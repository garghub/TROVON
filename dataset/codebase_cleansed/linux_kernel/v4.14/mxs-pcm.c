int mxs_pcm_platform_register(struct device *dev)\r\n{\r\nreturn devm_snd_dmaengine_pcm_register(dev, &mxs_dmaengine_pcm_config,\r\nSND_DMAENGINE_PCM_FLAG_HALF_DUPLEX);\r\n}
