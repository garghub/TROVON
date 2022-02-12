void sas_dprint_porte(int phyid, enum port_event pe)
{
SAS_DPRINTK("phy%d: port event: %s\n", phyid, sas_porte_str[pe]);
}
void sas_dprint_phye(int phyid, enum phy_event pe)
{
SAS_DPRINTK("phy%d: phy event: %s\n", phyid, sas_phye_str[pe]);
}
void sas_dprint_hae(struct sas_ha_struct *sas_ha, enum ha_event he)
{
SAS_DPRINTK("ha %s: %s event\n", dev_name(sas_ha->dev),
sas_hae_str[he]);
}
void sas_dump_port(struct asd_sas_port *port)
{
SAS_DPRINTK("port%d: class:0x%x\n", port->id, port->class);
SAS_DPRINTK("port%d: sas_addr:%llx\n", port->id,
SAS_ADDR(port->sas_addr));
SAS_DPRINTK("port%d: attached_sas_addr:%llx\n", port->id,
SAS_ADDR(port->attached_sas_addr));
SAS_DPRINTK("port%d: iproto:0x%x\n", port->id, port->iproto);
SAS_DPRINTK("port%d: tproto:0x%x\n", port->id, port->tproto);
SAS_DPRINTK("port%d: oob_mode:0x%x\n", port->id, port->oob_mode);
SAS_DPRINTK("port%d: num_phys:%d\n", port->id, port->num_phys);
}
