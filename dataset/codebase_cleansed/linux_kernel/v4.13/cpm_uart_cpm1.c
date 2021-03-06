void cpm_line_cr_cmd(struct uart_cpm_port *port, int cmd)
{
cpm_command(port->command, cmd);
}
void __iomem *cpm_uart_map_pram(struct uart_cpm_port *port,
struct device_node *np)
{
return of_iomap(np, 1);
}
void cpm_uart_unmap_pram(struct uart_cpm_port *port, void __iomem *pram)
{
iounmap(pram);
}
int cpm_uart_allocbuf(struct uart_cpm_port *pinfo, unsigned int is_con)
{
int dpmemsz, memsz;
u8 *dp_mem;
unsigned long dp_offset;
u8 *mem_addr;
dma_addr_t dma_addr = 0;
pr_debug("CPM uart[%d]:allocbuf\n", pinfo->port.line);
dpmemsz = sizeof(cbd_t) * (pinfo->rx_nrfifos + pinfo->tx_nrfifos);
dp_offset = cpm_dpalloc(dpmemsz, 8);
if (IS_ERR_VALUE(dp_offset)) {
printk(KERN_ERR
"cpm_uart_cpm1.c: could not allocate buffer descriptors\n");
return -ENOMEM;
}
dp_mem = cpm_dpram_addr(dp_offset);
memsz = L1_CACHE_ALIGN(pinfo->rx_nrfifos * pinfo->rx_fifosize) +
L1_CACHE_ALIGN(pinfo->tx_nrfifos * pinfo->tx_fifosize);
if (is_con) {
mem_addr = (u8 *) cpm_dpram_addr(cpm_dpalloc(memsz, 8));
dma_addr = (u32)cpm_dpram_phys(mem_addr);
} else
mem_addr = dma_alloc_coherent(pinfo->port.dev, memsz, &dma_addr,
GFP_KERNEL);
if (mem_addr == NULL) {
cpm_dpfree(dp_offset);
printk(KERN_ERR
"cpm_uart_cpm1.c: could not allocate coherent memory\n");
return -ENOMEM;
}
pinfo->dp_addr = dp_offset;
pinfo->mem_addr = mem_addr;
pinfo->dma_addr = dma_addr;
pinfo->mem_size = memsz;
pinfo->rx_buf = mem_addr;
pinfo->tx_buf = pinfo->rx_buf + L1_CACHE_ALIGN(pinfo->rx_nrfifos
* pinfo->rx_fifosize);
pinfo->rx_bd_base = (cbd_t __iomem __force *)dp_mem;
pinfo->tx_bd_base = pinfo->rx_bd_base + pinfo->rx_nrfifos;
return 0;
}
void cpm_uart_freebuf(struct uart_cpm_port *pinfo)
{
dma_free_coherent(pinfo->port.dev, L1_CACHE_ALIGN(pinfo->rx_nrfifos *
pinfo->rx_fifosize) +
L1_CACHE_ALIGN(pinfo->tx_nrfifos *
pinfo->tx_fifosize), pinfo->mem_addr,
pinfo->dma_addr);
cpm_dpfree(pinfo->dp_addr);
}
