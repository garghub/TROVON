static int
F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_5 -> V_4 ;
struct V_6 * V_7 = V_4 -> V_7 ;
struct V_8 * V_9 = V_7 -> V_9 ;
T_1 V_10 , V_11 , V_12 , V_13 , V_14 , V_15 ;
T_2 V_16 ;
int V_17 ;
V_16 = F_2 ( V_9 , & V_10 , & V_11 , & V_12 , & V_13 , & V_14 , & V_15 ) ;
if ( ! V_16 || V_11 < 0x15 )
return - V_18 ;
V_12 = F_3 ( V_9 , V_16 + 0x14 ) ;
V_16 = F_4 ( V_9 , V_16 + 0x10 ) ;
if ( V_12 ) {
T_2 V_19 = F_5 ( V_7 , 0x9a065c ) & 0x000000f0 ;
for ( V_17 = 0 ; V_17 < V_12 ; V_17 ++ , V_16 += 4 ) {
if ( V_17 != V_19 >> 4 ) {
F_6 ( V_7 , 0x9a065c , 0x000000f0 , V_17 << 4 ) ;
F_7 (&(struct nvbios_init) {
.subdev = subdev,
.bios = bios,
.offset = nvbios_rd32(bios, data),
.execute = 1 ,
}) ;
}
}
F_6 ( V_7 , 0x9a065c , 0x000000f0 , V_19 ) ;
}
F_6 ( V_7 , 0x9a0584 , 0x11000000 , 0x00000000 ) ;
F_8 ( V_7 , 0x10ecc0 , 0xffffffff ) ;
F_6 ( V_7 , 0x9a0160 , 0x00000010 , 0x00000010 ) ;
return 0 ;
}
static T_2
F_9 ( struct V_6 * V_7 , int V_20 )
{
return F_5 ( V_7 , 0x90020c + ( V_20 * 0x4000 ) ) ;
}
int
F_10 ( struct V_21 * V_5 , struct V_1 * * V_22 )
{
struct V_1 * V_2 ;
if ( ! ( V_2 = * V_22 = F_11 ( sizeof( * V_2 ) , V_23 ) ) )
return - V_24 ;
return F_12 ( & V_25 , V_5 , V_2 ) ;
}
