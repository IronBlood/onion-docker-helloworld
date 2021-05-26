#include <signal.h>
#include <onion/onion.h>

#define PORT "8084"

static onion *o = NULL;

static int api_helloworld(void *p, onion_request *req, onion_response *res) {
	(void) p;
	(void) req;

	onion_response_set_header(res, "Content-Type", "application/json; charset=utf-8");
	onion_response_set_header(res, "access-control-allow-origin", "*");
	onion_response_write0(res, "{ \"msg\": \"helloworld\" }");
	return OCS_PROCESSED;
}

static void shutdown_server(int _) {
	(void) _;
	if (o)
	onion_listen_stop(o);
}

int main(int argc, char *argv[]) {
	(void) argc;
	(void) argv;

	signal(SIGINT, shutdown_server);
	signal(SIGTERM, shutdown_server);

	o = onion_new(O_POOL);

	onion_set_max_threads(o, 32);
	onion_set_timeout(o, 5000);
	onion_set_hostname(o, "::");
	onion_set_port(o, PORT);

	onion_url *urls = onion_root_url(o);
	onion_url_add(urls, "^(.*)$", api_helloworld);

	onion_listen(o);

	onion_free(o);
	return 0;
}