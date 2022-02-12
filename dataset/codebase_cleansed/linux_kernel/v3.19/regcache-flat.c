static int regcache_flat_init(struct regmap *map)
{
int i;
unsigned int *cache;
map->cache = kzalloc(sizeof(unsigned int) * (map->max_register + 1),
GFP_KERNEL);
if (!map->cache)
return -ENOMEM;
cache = map->cache;
for (i = 0; i < map->num_reg_defaults; i++)
cache[map->reg_defaults[i].reg] = map->reg_defaults[i].def;
return 0;
}
static int regcache_flat_exit(struct regmap *map)
{
kfree(map->cache);
map->cache = NULL;
return 0;
}
static int regcache_flat_read(struct regmap *map,
unsigned int reg, unsigned int *value)
{
unsigned int *cache = map->cache;
*value = cache[reg];
return 0;
}
static int regcache_flat_write(struct regmap *map, unsigned int reg,
unsigned int value)
{
unsigned int *cache = map->cache;
cache[reg] = value;
return 0;
}
