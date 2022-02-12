static void spi_slave_time_complete(void *arg)
{
struct spi_slave_time_priv *priv = arg;
int ret;
ret = priv->msg.status;
if (ret)
goto terminate;
ret = spi_slave_time_submit(priv);
if (ret)
goto terminate;
return;
terminate:
dev_info(&priv->spi->dev, "Terminating\n");
complete(&priv->finished);
}
static int spi_slave_time_submit(struct spi_slave_time_priv *priv)
{
u32 rem_us;
int ret;
u64 ts;
ts = local_clock();
rem_us = do_div(ts, 1000000000) / 1000;
priv->buf[0] = cpu_to_be32(ts);
priv->buf[1] = cpu_to_be32(rem_us);
spi_message_init_with_transfers(&priv->msg, &priv->xfer, 1);
priv->msg.complete = spi_slave_time_complete;
priv->msg.context = priv;
ret = spi_async(priv->spi, &priv->msg);
if (ret)
dev_err(&priv->spi->dev, "spi_async() failed %d\n", ret);
return ret;
}
static int spi_slave_time_probe(struct spi_device *spi)
{
struct spi_slave_time_priv *priv;
int ret;
priv = devm_kzalloc(&spi->dev, sizeof(*priv), GFP_KERNEL);
if (!priv)
return -ENOMEM;
priv->spi = spi;
init_completion(&priv->finished);
priv->xfer.tx_buf = priv->buf;
priv->xfer.len = sizeof(priv->buf);
ret = spi_slave_time_submit(priv);
if (ret)
return ret;
spi_set_drvdata(spi, priv);
return 0;
}
static int spi_slave_time_remove(struct spi_device *spi)
{
struct spi_slave_time_priv *priv = spi_get_drvdata(spi);
spi_slave_abort(spi);
wait_for_completion(&priv->finished);
return 0;
}
