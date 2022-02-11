static int
F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
int V_5 , struct V_3 * * V_6 )
{
int V_7 = F_2 ( V_2 -> V_8 -> V_9 . V_10 , 16 , V_5 ,
false , V_4 , V_6 ) ;
if ( V_7 == 0 ) {
F_3 ( * V_6 ) ;
F_4 ( * V_6 , 0x00 , V_2 -> V_11 ) ;
F_4 ( * V_6 , 0x04 , 0x00000000 ) ;
F_4 ( * V_6 , 0x08 , 0x00000000 ) ;
F_4 ( * V_6 , 0x0c , 0x00000000 ) ;
F_5 ( * V_6 ) ;
}
return V_7 ;
}
static void *
F_6 ( struct V_1 * V_2 )
{
struct V_12 * V_13 = V_12 ( V_2 ) ;
struct V_14 * V_15 = V_13 -> V_15 ;
unsigned long V_16 ;
F_7 ( & V_15 -> V_8 . V_17 , V_16 ) ;
if ( V_15 -> V_13 == V_13 )
V_15 -> V_13 = NULL ;
F_8 ( & V_15 -> V_8 . V_17 , V_16 ) ;
return V_13 ;
}
int
F_9 ( struct V_18 * V_19 ,
const struct V_20 * V_11 ,
struct V_1 * * V_21 )
{
struct V_14 * V_15 = V_14 ( V_11 -> V_8 ) ;
struct V_12 * V_13 ;
unsigned long V_16 ;
int V_7 = - V_22 ;
if ( ! ( V_13 = F_10 ( sizeof( * V_13 ) , V_23 ) ) )
return - V_24 ;
F_11 ( & V_12 , V_11 , & V_13 -> V_2 ) ;
V_13 -> V_15 = V_15 ;
V_13 -> V_25 = V_19 ;
* V_21 = & V_13 -> V_2 ;
F_7 ( & V_15 -> V_8 . V_17 , V_16 ) ;
if ( ! V_15 -> V_13 ) {
V_15 -> V_13 = V_13 ;
V_7 = 0 ;
}
F_8 ( & V_15 -> V_8 . V_17 , V_16 ) ;
return V_7 ;
}
void
F_12 ( struct V_26 * V_8 , int V_27 , struct V_28 * V_29 )
{
struct V_14 * V_15 = V_14 ( V_8 ) ;
struct V_30 * V_10 = V_15 -> V_8 . V_9 . V_10 ;
F_13 ( V_10 , 0x00b008 + ( V_27 * 0x10 ) , V_29 -> V_31 ) ;
F_13 ( V_10 , 0x00b004 + ( V_27 * 0x10 ) , V_29 -> V_32 ) ;
F_13 ( V_10 , 0x00b000 + ( V_27 * 0x10 ) , V_29 -> V_33 ) ;
}
static bool
F_14 ( struct V_30 * V_10 , T_1 V_34 , T_1 V_35 )
{
struct V_14 * V_15 = V_14 ( V_10 -> V_15 ) ;
struct V_36 * V_9 = & V_15 -> V_8 . V_9 ;
T_1 V_37 = V_35 << 4 ;
T_1 V_38 = F_15 ( V_10 , 0x700000 + V_37 ) ;
T_1 V_39 = F_15 ( V_10 , 0x700004 + V_37 ) ;
T_1 V_40 = F_15 ( V_10 , 0x700008 + V_37 ) ;
T_1 V_41 = ( V_40 & 0xfffff000 ) | ( V_38 >> 20 ) ;
T_1 V_42 = V_39 + 1 ;
if ( ! ( V_38 & 0x00002000 ) ) {
F_16 ( V_9 , L_1 ,
V_37 , V_38 , V_39 , V_40 ) ;
return false ;
}
if ( V_34 == 0x0190 ) {
F_17 ( V_10 , 0x00b300 , 0x00010000 ,
( V_38 & 0x00030000 ) ? 0x00010000 : 0 ) ;
F_13 ( V_10 , 0x00b334 , V_41 ) ;
F_13 ( V_10 , 0x00b324 , V_42 ) ;
} else
if ( V_34 == 0x01a0 ) {
F_17 ( V_10 , 0x00b300 , 0x00020000 ,
( V_38 & 0x00030000 ) ? 0x00020000 : 0 ) ;
F_13 ( V_10 , 0x00b360 , V_41 ) ;
F_13 ( V_10 , 0x00b364 , V_42 ) ;
} else {
if ( V_38 & 0x00030000 )
return false ;
F_13 ( V_10 , 0x00b370 , V_41 ) ;
F_13 ( V_10 , 0x00b374 , V_42 ) ;
}
return true ;
}
static bool
F_18 ( struct V_14 * V_15 , T_1 V_34 , T_1 V_35 )
{
struct V_30 * V_10 = V_15 -> V_8 . V_9 . V_10 ;
switch ( V_34 ) {
case 0x190 :
case 0x1a0 :
case 0x1b0 :
return V_15 -> V_43 -> V_44 ( V_10 , V_34 , V_35 ) ;
default:
break;
}
return false ;
}
static void
F_19 ( struct V_26 * V_8 )
{
struct V_14 * V_15 = V_14 ( V_8 ) ;
struct V_36 * V_9 = & V_15 -> V_8 . V_9 ;
struct V_30 * V_10 = V_9 -> V_10 ;
T_1 V_45 = F_15 ( V_10 , 0x00b100 ) ;
T_1 type = F_15 ( V_10 , 0x00b230 ) ;
T_1 V_34 = F_15 ( V_10 , 0x00b234 ) ;
T_1 V_35 = F_15 ( V_10 , 0x00b238 ) ;
T_1 V_46 = V_45 ;
unsigned long V_16 ;
F_7 ( & V_15 -> V_8 . V_17 , V_16 ) ;
if ( V_45 & 0x01000000 ) {
if ( type == 0x00000020 && V_34 == 0x0000 ) {
F_17 ( V_10 , 0x00b308 , 0x00000000 , 0x00000000 ) ;
V_46 &= ~ 0x01000000 ;
}
if ( type == 0x00000010 ) {
if ( F_18 ( V_15 , V_34 , V_35 ) )
V_46 &= ~ 0x01000000 ;
}
}
F_13 ( V_10 , 0x00b100 , V_45 ) ;
F_13 ( V_10 , 0x00b230 , 0x00000001 ) ;
if ( V_46 ) {
F_16 ( V_9 , L_2 ,
V_15 -> V_13 ? V_15 -> V_13 -> V_25 -> V_47 : - 1 ,
V_15 -> V_13 ? V_15 -> V_13 -> V_2 . V_48 -> V_49 :
L_3 , V_45 , type , V_34 , V_35 ) ;
}
F_8 ( & V_15 -> V_8 . V_17 , V_16 ) ;
}
int
F_20 ( struct V_26 * V_15 )
{
struct V_36 * V_9 = & V_15 -> V_9 ;
struct V_30 * V_10 = V_9 -> V_10 ;
F_13 ( V_10 , 0x00b0e0 , 0x00000020 ) ;
F_13 ( V_10 , 0x00b0e8 , 0x00000020 ) ;
F_13 ( V_10 , 0x00b32c , 0x00000000 ) ;
F_13 ( V_10 , 0x00b314 , 0x00000100 ) ;
F_13 ( V_10 , 0x00b220 , 0x00000031 ) ;
F_13 ( V_10 , 0x00b300 , 0x02001ec1 ) ;
F_17 ( V_10 , 0x00b32c , 0x00000001 , 0x00000001 ) ;
F_13 ( V_10 , 0x00b100 , 0xffffffff ) ;
F_13 ( V_10 , 0x00b140 , 0xffffffff ) ;
if ( F_21 (device, 2000 ,
if (!(nvkm_rd32(device, 0x00b200) & 0x00000001))
break;
) < 0 ) {
F_16 ( V_9 , L_4 ,
F_15 ( V_10 , 0x00b200 ) ) ;
return - V_22 ;
}
return 0 ;
}
static void *
F_22 ( struct V_26 * V_8 )
{
return V_14 ( V_8 ) ;
}
int
F_23 ( const struct V_50 * V_43 , struct V_30 * V_10 ,
int V_51 , struct V_26 * * V_52 )
{
struct V_14 * V_15 ;
if ( ! ( V_15 = F_10 ( sizeof( * V_15 ) , V_23 ) ) )
return - V_24 ;
V_15 -> V_43 = V_43 ;
* V_52 = & V_15 -> V_8 ;
return F_24 ( & V_53 , V_10 , V_51 ,
true , & V_15 -> V_8 ) ;
}
int
F_25 ( struct V_30 * V_10 , int V_51 , struct V_26 * * V_52 )
{
return F_23 ( & V_14 , V_10 , V_51 , V_52 ) ;
}
