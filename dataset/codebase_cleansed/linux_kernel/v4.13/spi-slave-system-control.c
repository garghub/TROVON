static void spi_slave_system_control_complete(void *arg)
{
struct spi_slave_system_control_priv *priv = arg;
u16 cmd;
int ret;
if (priv->msg.status)
goto terminate;
cmd = be16_to_cpu(priv->cmd);
switch (cmd) {
case CMD_REBOOT:
dev_info(&priv->spi->dev, "Rebooting system...\n");
kernel_restart(NULL);
case CMD_POWEROFF:
dev_info(&priv->spi->dev, "Powering off system...\n");
kernel_power_off();
break;
case CMD_HALT:
dev_info(&priv->spi->dev, "Halting system...\n");
kernel_halt();
break;
case CMD_SUSPEND:
dev_info(&priv->spi->dev, "Suspending system...\n");
pm_suspend(PM_SUSPEND_MEM);
break;
default:
dev_warn(&priv->spi->dev, "Unknown command 0x%x\n", cmd);
break;
}
ret = spi_slave_system_control_submit(priv);
if (ret)
goto terminate;
return;
terminate:
dev_info(&priv->spi->dev, "Terminating\n");
complete(&priv->finished);
}
static
int spi_slave_system_control_submit(struct spi_slave_system_control_priv *priv)
{
int ret;
spi_message_init_with_transfers(&priv->msg, &priv->xfer, 1);
priv->msg.complete = spi_slave_system_control_complete;
priv->msg.context = priv;
ret = spi_async(priv->spi, &priv->msg);
if (ret)
dev_err(&priv->spi->dev, "spi_async() failed %d\n", ret);
return ret;
}
static int spi_slave_system_control_probe(struct spi_device *spi)
{
struct spi_slave_system_control_priv *priv;
int ret;
priv = devm_kzalloc(&spi->dev, sizeof(*priv), GFP_KERNEL);
if (!priv)
return -ENOMEM;
priv->spi = spi;
init_completion(&priv->finished);
priv->xfer.rx_buf = &priv->cmd;
priv->xfer.len = sizeof(priv->cmd);
ret = spi_slave_system_control_submit(priv);
if (ret)
return ret;
spi_set_drvdata(spi, priv);
return 0;
}
static int spi_slave_system_control_remove(struct spi_device *spi)
{
struct spi_slave_system_control_priv *priv = spi_get_drvdata(spi);
spi_slave_abort(spi);
wait_for_completion(&priv->finished);
return 0;
}
