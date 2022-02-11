static struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
#if 0
map_write8(map, 0x55, 0);
if (map_read8(map, 0) != 0x55)
return NULL;
map_write8(map, 0xAA, 0);
if (map_read8(map, 0) != 0xAA)
return NULL;
map_write8(map, 0x55, map->size-1);
if (map_read8(map, map->size-1) != 0x55)
return NULL;
map_write8(map, 0xAA, map->size-1);
if (map_read8(map, map->size-1) != 0xAA)
return NULL;
#endif
V_4 = F_2 ( sizeof( * V_4 ) , V_5 ) ;
if ( ! V_4 )
return NULL ;
V_3 -> V_6 = & V_7 ;
V_4 -> V_8 = V_3 ;
V_4 -> V_9 = V_3 -> V_9 ;
V_4 -> type = V_10 ;
V_4 -> V_11 = V_3 -> V_11 ;
V_4 -> V_12 = V_13 ;
V_4 -> V_14 = V_15 ;
V_4 -> V_16 = V_17 ;
V_4 -> V_18 = V_19 ;
V_4 -> V_20 = V_19 ;
V_4 -> V_21 = V_22 ;
V_4 -> V_23 = V_24 ;
V_4 -> V_25 = 1 ;
V_4 -> V_26 = V_27 ;
while( V_4 -> V_11 & ( V_4 -> V_26 - 1 ) )
V_4 -> V_26 >>= 1 ;
F_3 ( V_28 ) ;
return V_4 ;
}
static unsigned long V_15 ( struct V_1 * V_4 ,
unsigned long V_29 ,
unsigned long V_30 ,
unsigned long V_23 )
{
struct V_2 * V_3 = V_4 -> V_8 ;
return ( unsigned long ) V_3 -> V_31 + V_30 ;
}
static int V_17 ( struct V_1 * V_4 , T_1 V_32 , T_2 V_29 , T_2 * V_33 , T_3 * V_34 )
{
struct V_2 * V_3 = V_4 -> V_8 ;
F_4 ( V_3 , V_34 , V_32 , V_29 ) ;
* V_33 = V_29 ;
return 0 ;
}
static int V_19 ( struct V_1 * V_4 , T_1 V_35 , T_2 V_29 , T_2 * V_33 , const T_3 * V_34 )
{
struct V_2 * V_3 = V_4 -> V_8 ;
F_5 ( V_3 , V_35 , V_34 , V_29 ) ;
* V_33 = V_29 ;
return 0 ;
}
static int V_13 ( struct V_1 * V_4 , struct V_36 * V_37 )
{
struct V_2 * V_3 = V_4 -> V_8 ;
T_4 V_38 ;
unsigned long V_39 ;
V_38 = F_6 ( V_3 ) ;
for ( V_39 = 0 ; V_39 < V_37 -> V_29 ; V_39 += F_7 ( V_3 ) )
F_8 ( V_3 , V_38 , V_37 -> V_40 + V_39 ) ;
V_37 -> V_41 = V_42 ;
F_9 ( V_37 ) ;
return 0 ;
}
static void V_22 ( struct V_1 * V_4 )
{
}
static int T_5 F_10 ( void )
{
F_11 ( & V_7 ) ;
return 0 ;
}
static void T_6 F_12 ( void )
{
F_13 ( & V_7 ) ;
}
