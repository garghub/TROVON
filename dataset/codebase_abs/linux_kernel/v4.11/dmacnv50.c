static void
F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 =
F_2 ( V_2 , F_3 ( * V_4 ) , V_5 ) ;
F_4 ( V_4 -> V_6 -> V_7 , V_4 -> V_8 ) ;
}
static int
F_5 ( struct V_9 * V_2 ,
const struct V_10 * V_11 ,
void * V_12 , T_1 V_13 , struct V_14 * * V_15 )
{
struct V_16 * V_17 = V_16 ( V_2 ) ;
struct V_18 * V_6 = V_17 -> V_2 . V_6 ;
struct V_19 * V_20 = V_6 -> V_21 -> V_2 . V_22 . V_23 . V_20 ;
const struct V_24 * V_25 = V_11 -> V_26 ;
struct V_3 * V_4 ;
int V_27 ;
if ( ! ( V_4 = F_6 ( sizeof( * V_4 ) , V_28 ) ) )
return - V_29 ;
F_7 ( & V_30 , V_11 , & V_4 -> V_5 ) ;
V_4 -> V_6 = V_6 ;
* V_15 = & V_4 -> V_5 . V_2 ;
V_27 = V_25 -> V_31 ( V_20 , V_11 , V_12 , V_13 , & V_4 -> V_5 . V_4 ) ;
if ( V_27 )
return V_27 ;
V_4 -> V_8 = V_17 -> V_32 -> V_33 ( V_17 , V_4 -> V_5 . V_4 ,
V_11 -> V_34 ) ;
if ( V_4 -> V_8 < 0 )
return V_4 -> V_8 ;
return 0 ;
}
static int
F_8 ( struct V_9 * V_2 , int V_35 ,
struct V_10 * V_25 )
{
struct V_16 * V_17 = V_16 ( V_2 ) ;
struct V_36 * V_21 = V_17 -> V_2 . V_6 -> V_21 ;
struct V_19 * V_20 = V_21 -> V_2 . V_22 . V_23 . V_20 ;
const struct V_24 * V_11 = NULL ;
V_25 -> V_22 = F_9 ( V_20 , V_37 ) ;
if ( V_25 -> V_22 && V_25 -> V_22 -> V_32 -> V_2 . V_25 ) {
V_25 -> V_22 -> V_32 -> V_2 . V_25 ( V_25 , V_35 , & V_11 ) ;
if ( V_11 ) {
V_25 -> V_26 = V_11 ;
return 0 ;
}
}
return - V_38 ;
}
static void
F_10 ( struct V_9 * V_2 )
{
struct V_16 * V_17 = V_16 ( V_2 ) ;
V_17 -> V_32 -> V_39 ( V_17 ) ;
}
static int
F_11 ( struct V_9 * V_2 )
{
struct V_16 * V_17 = V_16 ( V_2 ) ;
return V_17 -> V_32 -> V_40 ( V_17 ) ;
}
static void *
F_12 ( struct V_9 * V_2 )
{
return V_16 ( V_2 ) ;
}
int
F_13 ( const struct V_41 * V_32 ,
const struct V_42 * V_43 ,
struct V_18 * V_6 , int V_44 , int V_45 , T_2 V_46 ,
const struct V_10 * V_11 ,
struct V_14 * * V_15 )
{
struct V_47 * V_48 = V_11 -> V_48 ;
struct V_49 * V_50 ;
struct V_16 * V_17 ;
int V_27 ;
if ( ! ( V_17 = F_6 ( sizeof( * V_17 ) , V_28 ) ) )
return - V_29 ;
* V_15 = & V_17 -> V_2 . V_4 ;
V_17 -> V_32 = V_32 ;
V_27 = F_14 ( & V_51 , V_43 , V_6 ,
V_44 , V_44 , V_45 , V_11 , & V_17 -> V_2 ) ;
if ( V_27 )
return V_27 ;
V_50 = F_15 ( V_48 , V_46 ) ;
if ( F_16 ( V_50 ) )
return F_17 ( V_50 ) ;
if ( V_50 -> V_52 - V_50 -> V_53 != 0xfff )
return - V_38 ;
switch ( V_50 -> V_54 ) {
case V_55 :
V_17 -> V_46 = 0x00000001 | V_50 -> V_53 >> 8 ;
break;
case V_56 :
V_17 -> V_46 = 0x00000003 | V_50 -> V_53 >> 8 ;
break;
default:
return - V_38 ;
}
return 0 ;
}
int
F_18 ( struct V_16 * V_17 ,
struct V_14 * V_4 , T_1 V_34 )
{
return F_19 ( V_17 -> V_2 . V_6 -> V_7 , V_4 ,
V_17 -> V_2 . V_44 . V_57 , - 10 , V_34 ,
V_17 -> V_2 . V_44 . V_57 << 28 |
V_17 -> V_2 . V_44 . V_57 ) ;
}
static void
F_20 ( struct V_16 * V_17 )
{
struct V_36 * V_21 = V_17 -> V_2 . V_6 -> V_21 ;
struct V_58 * V_23 = & V_21 -> V_2 . V_22 . V_23 ;
struct V_19 * V_20 = V_23 -> V_20 ;
int V_59 = V_17 -> V_2 . V_44 . V_59 ;
int V_57 = V_17 -> V_2 . V_44 . V_57 ;
F_21 ( V_20 , 0x610200 + ( V_59 * 0x0010 ) , 0x00001010 , 0x00001000 ) ;
F_21 ( V_20 , 0x610200 + ( V_59 * 0x0010 ) , 0x00000003 , 0x00000000 ) ;
if ( F_22 (device, 2000 ,
if (!(nvkm_rd32(device, 0x610200 + (ctrl * 0x10)) & 0x001e0000))
break;
) < 0 ) {
F_23 ( V_23 , L_1 , V_57 ,
F_24 ( V_20 , 0x610200 + ( V_59 * 0x10 ) ) ) ;
}
F_21 ( V_20 , 0x610028 , 0x00010001 << V_57 , 0x00000000 << V_57 ) ;
}
static int
F_25 ( struct V_16 * V_17 )
{
struct V_36 * V_21 = V_17 -> V_2 . V_6 -> V_21 ;
struct V_58 * V_23 = & V_21 -> V_2 . V_22 . V_23 ;
struct V_19 * V_20 = V_23 -> V_20 ;
int V_59 = V_17 -> V_2 . V_44 . V_59 ;
int V_57 = V_17 -> V_2 . V_44 . V_57 ;
F_21 ( V_20 , 0x610028 , 0x00010000 << V_57 , 0x00010000 << V_57 ) ;
F_26 ( V_20 , 0x610204 + ( V_59 * 0x0010 ) , V_17 -> V_46 ) ;
F_26 ( V_20 , 0x610208 + ( V_59 * 0x0010 ) , 0x00010000 ) ;
F_26 ( V_20 , 0x61020c + ( V_59 * 0x0010 ) , V_59 ) ;
F_21 ( V_20 , 0x610200 + ( V_59 * 0x0010 ) , 0x00000010 , 0x00000010 ) ;
F_26 ( V_20 , 0x640000 + ( V_59 * 0x1000 ) , 0x00000000 ) ;
F_26 ( V_20 , 0x610200 + ( V_59 * 0x0010 ) , 0x00000013 ) ;
if ( F_22 (device, 2000 ,
if (!(nvkm_rd32(device, 0x610200 + (ctrl * 0x10)) & 0x80000000))
break;
) < 0 ) {
F_23 ( V_23 , L_2 , V_57 ,
F_24 ( V_20 , 0x610200 + ( V_59 * 0x10 ) ) ) ;
return - V_60 ;
}
return 0 ;
}
