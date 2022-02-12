static int __scif_get_port(int start, int end)
{
int id;
struct scif_port *port = kzalloc(sizeof(*port), GFP_ATOMIC);
if (!port)
return -ENOMEM;
spin_lock(&scif_info.port_lock);
id = idr_alloc(&scif_ports, port, start, end, GFP_ATOMIC);
if (id >= 0)
port->ref_cnt++;
spin_unlock(&scif_info.port_lock);
return id;
}
int scif_rsrv_port(u16 port)
{
return __scif_get_port(port, port + 1);
}
int scif_get_new_port(void)
{
return __scif_get_port(SCIF_PORT_RSVD + 1, SCIF_PORT_COUNT);
}
void scif_get_port(u16 id)
{
struct scif_port *port;
if (!id)
return;
spin_lock(&scif_info.port_lock);
port = idr_find(&scif_ports, id);
if (port)
port->ref_cnt++;
spin_unlock(&scif_info.port_lock);
}
void scif_put_port(u16 id)
{
struct scif_port *port;
if (!id)
return;
spin_lock(&scif_info.port_lock);
port = idr_find(&scif_ports, id);
if (port) {
port->ref_cnt--;
if (!port->ref_cnt) {
idr_remove(&scif_ports, id);
kfree(port);
}
}
spin_unlock(&scif_info.port_lock);
}
