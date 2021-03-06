int snd_gus_iwffff_put_sample(void *private_data, struct iwffff_wave *wave,
char __user *data, long len, int atomic)
{
struct snd_gus_card *gus = private_data;
struct snd_gf1_mem_block *block;
int err;
if (wave->format & IWFFFF_WAVE_ROM)
return 0;
if (wave->format & IWFFFF_WAVE_STEREO)
return -EINVAL;
block = snd_gf1_mem_alloc(&gus->gf1.mem_alloc,
SNDRV_GF1_MEM_OWNER_WAVE_IWFFFF,
NULL, wave->size,
wave->format & IWFFFF_WAVE_16BIT, 1,
wave->share_id);
if (block == NULL)
return -ENOMEM;
err = snd_gus_dram_write(gus, data,
block->ptr, wave->size);
if (err < 0) {
snd_gf1_mem_lock(&gus->gf1.mem_alloc, 0);
snd_gf1_mem_xfree(&gus->gf1.mem_alloc, block);
snd_gf1_mem_lock(&gus->gf1.mem_alloc, 1);
return err;
}
wave->address.memory = block->ptr;
return 0;
}
int snd_gus_iwffff_get_sample(void *private_data, struct iwffff_wave *wave,
char __user *data, long len, int atomic)
{
struct snd_gus_card *gus = private_data;
return snd_gus_dram_read(gus, data, wave->address.memory, wave->size,
wave->format & IWFFFF_WAVE_ROM ? 1 : 0);
}
int snd_gus_iwffff_remove_sample(void *private_data, struct iwffff_wave *wave,
int atomic)
{
struct snd_gus_card *gus = private_data;
if (wave->format & IWFFFF_WAVE_ROM)
return 0;
return snd_gf1_mem_free(&gus->gf1.mem_alloc, wave->address.memory);
}
int snd_gus_gf1_put_sample(void *private_data, struct gf1_wave *wave,
char __user *data, long len, int atomic)
{
struct snd_gus_card *gus = private_data;
struct snd_gf1_mem_block *block;
int err;
if (wave->format & GF1_WAVE_STEREO)
return -EINVAL;
block = snd_gf1_mem_alloc(&gus->gf1.mem_alloc,
SNDRV_GF1_MEM_OWNER_WAVE_GF1,
NULL, wave->size,
wave->format & GF1_WAVE_16BIT, 1,
wave->share_id);
if (block == NULL)
return -ENOMEM;
err = snd_gus_dram_write(gus, data,
block->ptr, wave->size);
if (err < 0) {
snd_gf1_mem_lock(&gus->gf1.mem_alloc, 0);
snd_gf1_mem_xfree(&gus->gf1.mem_alloc, block);
snd_gf1_mem_lock(&gus->gf1.mem_alloc, 1);
return err;
}
wave->address.memory = block->ptr;
return 0;
}
int snd_gus_gf1_get_sample(void *private_data, struct gf1_wave *wave,
char __user *data, long len, int atomic)
{
struct snd_gus_card *gus = private_data;
return snd_gus_dram_read(gus, data, wave->address.memory, wave->size, 0);
}
int snd_gus_gf1_remove_sample(void *private_data, struct gf1_wave *wave,
int atomic)
{
struct snd_gus_card *gus = private_data;
return snd_gf1_mem_free(&gus->gf1.mem_alloc, wave->address.memory);
}
int snd_gus_simple_put_sample(void *private_data, struct simple_instrument *instr,
char __user *data, long len, int atomic)
{
struct snd_gus_card *gus = private_data;
struct snd_gf1_mem_block *block;
int err;
if (instr->format & SIMPLE_WAVE_STEREO)
return -EINVAL;
block = snd_gf1_mem_alloc(&gus->gf1.mem_alloc,
SNDRV_GF1_MEM_OWNER_WAVE_SIMPLE,
NULL, instr->size,
instr->format & SIMPLE_WAVE_16BIT, 1,
instr->share_id);
if (block == NULL)
return -ENOMEM;
err = snd_gus_dram_write(gus, data, block->ptr, instr->size);
if (err < 0) {
snd_gf1_mem_lock(&gus->gf1.mem_alloc, 0);
snd_gf1_mem_xfree(&gus->gf1.mem_alloc, block);
snd_gf1_mem_lock(&gus->gf1.mem_alloc, 1);
return err;
}
instr->address.memory = block->ptr;
return 0;
}
int snd_gus_simple_get_sample(void *private_data, struct simple_instrument *instr,
char __user *data, long len, int atomic)
{
struct snd_gus_card *gus = private_data;
return snd_gus_dram_read(gus, data, instr->address.memory, instr->size, 0);
}
int snd_gus_simple_remove_sample(void *private_data, struct simple_instrument *instr,
int atomic)
{
struct snd_gus_card *gus = private_data;
return snd_gf1_mem_free(&gus->gf1.mem_alloc, instr->address.memory);
}
