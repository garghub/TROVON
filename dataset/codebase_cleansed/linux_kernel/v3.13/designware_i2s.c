static inline void i2s_write_reg(void __iomem *io_base, int reg, u32 val)\r\n{\r\nwritel(val, io_base + reg);\r\n}\r\nstatic inline u32 i2s_read_reg(void __iomem *io_base, int reg)\r\n{\r\nreturn readl(io_base + reg);\r\n}\r\nstatic inline void i2s_disable_channels(struct dw_i2s_dev *dev, u32 stream)\r\n{\r\nu32 i = 0;\r\nif (stream == SNDRV_PCM_STREAM_PLAYBACK) {\r\nfor (i = 0; i < 4; i++)\r\ni2s_write_reg(dev->i2s_base, TER(i), 0);\r\n} else {\r\nfor (i = 0; i < 4; i++)\r\ni2s_write_reg(dev->i2s_base, RER(i), 0);\r\n}\r\n}\r\nstatic inline void i2s_clear_irqs(struct dw_i2s_dev *dev, u32 stream)\r\n{\r\nu32 i = 0;\r\nif (stream == SNDRV_PCM_STREAM_PLAYBACK) {\r\nfor (i = 0; i < 4; i++)\r\ni2s_write_reg(dev->i2s_base, TOR(i), 0);\r\n} else {\r\nfor (i = 0; i < 4; i++)\r\ni2s_write_reg(dev->i2s_base, ROR(i), 0);\r\n}\r\n}\r\nstatic void i2s_start(struct dw_i2s_dev *dev,\r\nstruct snd_pcm_substream *substream)\r\n{\r\ni2s_write_reg(dev->i2s_base, IER, 1);\r\nif (substream->stream == SNDRV_PCM_STREAM_PLAYBACK)\r\ni2s_write_reg(dev->i2s_base, ITER, 1);\r\nelse\r\ni2s_write_reg(dev->i2s_base, IRER, 1);\r\ni2s_write_reg(dev->i2s_base, CER, 1);\r\n}\r\nstatic void i2s_stop(struct dw_i2s_dev *dev,\r\nstruct snd_pcm_substream *substream)\r\n{\r\nu32 i = 0, irq;\r\ni2s_clear_irqs(dev, substream->stream);\r\nif (substream->stream == SNDRV_PCM_STREAM_PLAYBACK) {\r\ni2s_write_reg(dev->i2s_base, ITER, 0);\r\nfor (i = 0; i < 4; i++) {\r\nirq = i2s_read_reg(dev->i2s_base, IMR(i));\r\ni2s_write_reg(dev->i2s_base, IMR(i), irq | 0x30);\r\n}\r\n} else {\r\ni2s_write_reg(dev->i2s_base, IRER, 0);\r\nfor (i = 0; i < 4; i++) {\r\nirq = i2s_read_reg(dev->i2s_base, IMR(i));\r\ni2s_write_reg(dev->i2s_base, IMR(i), irq | 0x03);\r\n}\r\n}\r\nif (!dev->active) {\r\ni2s_write_reg(dev->i2s_base, CER, 0);\r\ni2s_write_reg(dev->i2s_base, IER, 0);\r\n}\r\n}\r\nstatic int dw_i2s_startup(struct snd_pcm_substream *substream,\r\nstruct snd_soc_dai *cpu_dai)\r\n{\r\nstruct dw_i2s_dev *dev = snd_soc_dai_get_drvdata(cpu_dai);\r\nstruct i2s_dma_data *dma_data = NULL;\r\nif (!(dev->capability & DWC_I2S_RECORD) &&\r\n(substream->stream == SNDRV_PCM_STREAM_CAPTURE))\r\nreturn -EINVAL;\r\nif (!(dev->capability & DWC_I2S_PLAY) &&\r\n(substream->stream == SNDRV_PCM_STREAM_PLAYBACK))\r\nreturn -EINVAL;\r\nif (substream->stream == SNDRV_PCM_STREAM_PLAYBACK)\r\ndma_data = &dev->play_dma_data;\r\nelse if (substream->stream == SNDRV_PCM_STREAM_CAPTURE)\r\ndma_data = &dev->capture_dma_data;\r\nsnd_soc_dai_set_dma_data(cpu_dai, substream, (void *)dma_data);\r\nreturn 0;\r\n}\r\nstatic int dw_i2s_hw_params(struct snd_pcm_substream *substream,\r\nstruct snd_pcm_hw_params *params, struct snd_soc_dai *dai)\r\n{\r\nstruct dw_i2s_dev *dev = snd_soc_dai_get_drvdata(dai);\r\nstruct i2s_clk_config_data *config = &dev->config;\r\nu32 ccr, xfer_resolution, ch_reg, irq;\r\nint ret;\r\nswitch (params_format(params)) {\r\ncase SNDRV_PCM_FORMAT_S16_LE:\r\nconfig->data_width = 16;\r\nccr = 0x00;\r\nxfer_resolution = 0x02;\r\nbreak;\r\ncase SNDRV_PCM_FORMAT_S24_LE:\r\nconfig->data_width = 24;\r\nccr = 0x08;\r\nxfer_resolution = 0x04;\r\nbreak;\r\ncase SNDRV_PCM_FORMAT_S32_LE:\r\nconfig->data_width = 32;\r\nccr = 0x10;\r\nxfer_resolution = 0x05;\r\nbreak;\r\ndefault:\r\ndev_err(dev->dev, "designware-i2s: unsuppted PCM fmt");\r\nreturn -EINVAL;\r\n}\r\nconfig->chan_nr = params_channels(params);\r\nswitch (config->chan_nr) {\r\ncase EIGHT_CHANNEL_SUPPORT:\r\nch_reg = 3;\r\nbreak;\r\ncase SIX_CHANNEL_SUPPORT:\r\nch_reg = 2;\r\nbreak;\r\ncase FOUR_CHANNEL_SUPPORT:\r\nch_reg = 1;\r\nbreak;\r\ncase TWO_CHANNEL_SUPPORT:\r\nch_reg = 0;\r\nbreak;\r\ndefault:\r\ndev_err(dev->dev, "channel not supported\n");\r\nreturn -EINVAL;\r\n}\r\ni2s_disable_channels(dev, substream->stream);\r\nif (substream->stream == SNDRV_PCM_STREAM_PLAYBACK) {\r\ni2s_write_reg(dev->i2s_base, TCR(ch_reg), xfer_resolution);\r\ni2s_write_reg(dev->i2s_base, TFCR(ch_reg), 0x02);\r\nirq = i2s_read_reg(dev->i2s_base, IMR(ch_reg));\r\ni2s_write_reg(dev->i2s_base, IMR(ch_reg), irq & ~0x30);\r\ni2s_write_reg(dev->i2s_base, TER(ch_reg), 1);\r\n} else {\r\ni2s_write_reg(dev->i2s_base, RCR(ch_reg), xfer_resolution);\r\ni2s_write_reg(dev->i2s_base, RFCR(ch_reg), 0x07);\r\nirq = i2s_read_reg(dev->i2s_base, IMR(ch_reg));\r\ni2s_write_reg(dev->i2s_base, IMR(ch_reg), irq & ~0x03);\r\ni2s_write_reg(dev->i2s_base, RER(ch_reg), 1);\r\n}\r\ni2s_write_reg(dev->i2s_base, CCR, ccr);\r\nconfig->sample_rate = params_rate(params);\r\nif (!dev->i2s_clk_cfg)\r\nreturn -EINVAL;\r\nret = dev->i2s_clk_cfg(config);\r\nif (ret < 0) {\r\ndev_err(dev->dev, "runtime audio clk config fail\n");\r\nreturn ret;\r\n}\r\nreturn 0;\r\n}\r\nstatic void dw_i2s_shutdown(struct snd_pcm_substream *substream,\r\nstruct snd_soc_dai *dai)\r\n{\r\nsnd_soc_dai_set_dma_data(dai, substream, NULL);\r\n}\r\nstatic int dw_i2s_trigger(struct snd_pcm_substream *substream,\r\nint cmd, struct snd_soc_dai *dai)\r\n{\r\nstruct dw_i2s_dev *dev = snd_soc_dai_get_drvdata(dai);\r\nint ret = 0;\r\nswitch (cmd) {\r\ncase SNDRV_PCM_TRIGGER_START:\r\ncase SNDRV_PCM_TRIGGER_RESUME:\r\ncase SNDRV_PCM_TRIGGER_PAUSE_RELEASE:\r\ndev->active++;\r\ni2s_start(dev, substream);\r\nbreak;\r\ncase SNDRV_PCM_TRIGGER_STOP:\r\ncase SNDRV_PCM_TRIGGER_SUSPEND:\r\ncase SNDRV_PCM_TRIGGER_PAUSE_PUSH:\r\ndev->active--;\r\ni2s_stop(dev, substream);\r\nbreak;\r\ndefault:\r\nret = -EINVAL;\r\nbreak;\r\n}\r\nreturn ret;\r\n}\r\nstatic int dw_i2s_suspend(struct snd_soc_dai *dai)\r\n{\r\nstruct dw_i2s_dev *dev = snd_soc_dai_get_drvdata(dai);\r\nclk_disable(dev->clk);\r\nreturn 0;\r\n}\r\nstatic int dw_i2s_resume(struct snd_soc_dai *dai)\r\n{\r\nstruct dw_i2s_dev *dev = snd_soc_dai_get_drvdata(dai);\r\nclk_enable(dev->clk);\r\nreturn 0;\r\n}\r\nstatic int dw_i2s_probe(struct platform_device *pdev)\r\n{\r\nconst struct i2s_platform_data *pdata = pdev->dev.platform_data;\r\nstruct dw_i2s_dev *dev;\r\nstruct resource *res;\r\nint ret;\r\nunsigned int cap;\r\nstruct snd_soc_dai_driver *dw_i2s_dai;\r\nif (!pdata) {\r\ndev_err(&pdev->dev, "Invalid platform data\n");\r\nreturn -EINVAL;\r\n}\r\nres = platform_get_resource(pdev, IORESOURCE_MEM, 0);\r\nif (!res) {\r\ndev_err(&pdev->dev, "no i2s resource defined\n");\r\nreturn -ENODEV;\r\n}\r\nif (!devm_request_mem_region(&pdev->dev, res->start,\r\nresource_size(res), pdev->name)) {\r\ndev_err(&pdev->dev, "i2s region already claimed\n");\r\nreturn -EBUSY;\r\n}\r\ndev = devm_kzalloc(&pdev->dev, sizeof(*dev), GFP_KERNEL);\r\nif (!dev) {\r\ndev_warn(&pdev->dev, "kzalloc fail\n");\r\nreturn -ENOMEM;\r\n}\r\ndev->i2s_base = devm_ioremap(&pdev->dev, res->start,\r\nresource_size(res));\r\nif (!dev->i2s_base) {\r\ndev_err(&pdev->dev, "ioremap fail for i2s_region\n");\r\nreturn -ENOMEM;\r\n}\r\ncap = pdata->cap;\r\ndev->capability = cap;\r\ndev->i2s_clk_cfg = pdata->i2s_clk_cfg;\r\ndev->play_dma_data.data = pdata->play_dma_data;\r\ndev->capture_dma_data.data = pdata->capture_dma_data;\r\ndev->play_dma_data.addr = res->start + I2S_TXDMA;\r\ndev->capture_dma_data.addr = res->start + I2S_RXDMA;\r\ndev->play_dma_data.max_burst = 16;\r\ndev->capture_dma_data.max_burst = 16;\r\ndev->play_dma_data.addr_width = DMA_SLAVE_BUSWIDTH_2_BYTES;\r\ndev->capture_dma_data.addr_width = DMA_SLAVE_BUSWIDTH_2_BYTES;\r\ndev->play_dma_data.filter = pdata->filter;\r\ndev->capture_dma_data.filter = pdata->filter;\r\ndev->clk = clk_get(&pdev->dev, NULL);\r\nif (IS_ERR(dev->clk))\r\nreturn PTR_ERR(dev->clk);\r\nret = clk_enable(dev->clk);\r\nif (ret < 0)\r\ngoto err_clk_put;\r\ndw_i2s_dai = devm_kzalloc(&pdev->dev, sizeof(*dw_i2s_dai), GFP_KERNEL);\r\nif (!dw_i2s_dai) {\r\ndev_err(&pdev->dev, "mem allocation failed for dai driver\n");\r\nret = -ENOMEM;\r\ngoto err_clk_disable;\r\n}\r\nif (cap & DWC_I2S_PLAY) {\r\ndev_dbg(&pdev->dev, " designware: play supported\n");\r\ndw_i2s_dai->playback.channels_min = MIN_CHANNEL_NUM;\r\ndw_i2s_dai->playback.channels_max = pdata->channel;\r\ndw_i2s_dai->playback.formats = pdata->snd_fmts;\r\ndw_i2s_dai->playback.rates = pdata->snd_rates;\r\n}\r\nif (cap & DWC_I2S_RECORD) {\r\ndev_dbg(&pdev->dev, "designware: record supported\n");\r\ndw_i2s_dai->capture.channels_min = MIN_CHANNEL_NUM;\r\ndw_i2s_dai->capture.channels_max = pdata->channel;\r\ndw_i2s_dai->capture.formats = pdata->snd_fmts;\r\ndw_i2s_dai->capture.rates = pdata->snd_rates;\r\n}\r\ndw_i2s_dai->ops = &dw_i2s_dai_ops;\r\ndw_i2s_dai->suspend = dw_i2s_suspend;\r\ndw_i2s_dai->resume = dw_i2s_resume;\r\ndev->dev = &pdev->dev;\r\ndev_set_drvdata(&pdev->dev, dev);\r\nret = snd_soc_register_component(&pdev->dev, &dw_i2s_component,\r\ndw_i2s_dai, 1);\r\nif (ret != 0) {\r\ndev_err(&pdev->dev, "not able to register dai\n");\r\ngoto err_clk_disable;\r\n}\r\nreturn 0;\r\nerr_clk_disable:\r\nclk_disable(dev->clk);\r\nerr_clk_put:\r\nclk_put(dev->clk);\r\nreturn ret;\r\n}\r\nstatic int dw_i2s_remove(struct platform_device *pdev)\r\n{\r\nstruct dw_i2s_dev *dev = dev_get_drvdata(&pdev->dev);\r\nsnd_soc_unregister_component(&pdev->dev);\r\nclk_put(dev->clk);\r\nreturn 0;\r\n}
