static int pxa2xx_pcm_hw_params(struct snd_pcm_substream *substream,\r\nstruct snd_pcm_hw_params *params)\r\n{\r\nstruct snd_soc_pcm_runtime *rtd = substream->private_data;\r\nstruct snd_dmaengine_dai_dma_data *dma;\r\ndma = snd_soc_dai_get_dma_data(rtd->cpu_dai, substream);\r\nif (!dma)\r\nreturn 0;\r\nreturn __pxa2xx_pcm_hw_params(substream, params);\r\n}\r\nstatic int pxa2xx_pcm_hw_free(struct snd_pcm_substream *substream)\r\n{\r\n__pxa2xx_pcm_hw_free(substream);\r\nreturn 0;\r\n}\r\nstatic int pxa2xx_soc_pcm_new(struct snd_soc_pcm_runtime *rtd)\r\n{\r\nstruct snd_card *card = rtd->card->snd_card;\r\nstruct snd_pcm *pcm = rtd->pcm;\r\nint ret;\r\nret = dma_coerce_mask_and_coherent(card->dev, DMA_BIT_MASK(32));\r\nif (ret)\r\nreturn ret;\r\nif (pcm->streams[SNDRV_PCM_STREAM_PLAYBACK].substream) {\r\nret = pxa2xx_pcm_preallocate_dma_buffer(pcm,\r\nSNDRV_PCM_STREAM_PLAYBACK);\r\nif (ret)\r\ngoto out;\r\n}\r\nif (pcm->streams[SNDRV_PCM_STREAM_CAPTURE].substream) {\r\nret = pxa2xx_pcm_preallocate_dma_buffer(pcm,\r\nSNDRV_PCM_STREAM_CAPTURE);\r\nif (ret)\r\ngoto out;\r\n}\r\nout:\r\nreturn ret;\r\n}\r\nstatic int pxa2xx_soc_platform_probe(struct platform_device *pdev)\r\n{\r\nreturn devm_snd_soc_register_platform(&pdev->dev, &pxa2xx_soc_platform);\r\n}
