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
int
F_9 ( struct V_20 * V_5 , struct V_1 * * V_21 )
{
struct V_1 * V_2 ;
struct V_3 * V_4 = & V_5 -> V_4 ;
struct V_6 * V_7 = V_4 -> V_7 ;
enum V_22 type = F_10 ( V_7 -> V_9 ) ;
const T_2 V_23 = ( 256 * 1024 ) ;
const T_2 V_24 = ( 1024 * 1024 ) ;
T_2 V_25 = F_5 ( V_7 , 0x02243c ) , V_26 ;
T_2 V_27 = F_5 ( V_7 , 0x021c14 ) ;
T_3 V_28 , V_29 = 0 , V_30 = ~ 0ULL ;
bool V_31 = false ;
int V_32 ;
F_11 ( V_4 , L_1 , V_25 ) ;
F_11 ( V_4 , L_2 , V_27 ) ;
for ( V_26 = 0 ; V_26 < V_25 ; V_26 ++ ) {
if ( ! ( V_27 & ( 1 << V_26 ) ) ) {
V_28 = F_5 ( V_7 , 0x90020c + ( V_26 * 0x4000 ) ) ;
F_11 ( V_4 , L_3 , V_26 , V_28 ) ;
V_28 = V_28 << 20 ;
if ( V_28 != V_30 ) {
if ( V_30 != ~ 0ULL )
V_31 = true ;
V_30 = F_12 ( V_30 , V_28 ) ;
}
V_29 = V_29 + V_28 ;
}
}
V_32 = F_13 ( & V_33 , V_5 , type , V_29 , 0 , & V_2 ) ;
* V_21 = V_2 ;
if ( V_32 )
return V_32 ;
F_14 ( & V_2 -> V_34 ) ;
if ( V_31 ) {
V_32 = F_15 ( & V_2 -> V_34 , V_23 >> V_35 ,
( ( V_30 * V_25 ) - V_23 ) >>
V_35 , 1 ) ;
if ( V_32 )
return V_32 ;
V_32 = F_15 ( & V_2 -> V_34 , ( 0x1000000000ULL + V_30 ) >>
V_35 ,
( V_29 - ( V_30 * V_25 ) - V_24 ) >>
V_35 , 1 ) ;
if ( V_32 )
return V_32 ;
} else {
V_32 = F_15 ( & V_2 -> V_34 , V_23 >> V_35 ,
( V_29 - V_23 - V_24 ) >>
V_35 , 1 ) ;
if ( V_32 )
return V_32 ;
}
return 0 ;
}
