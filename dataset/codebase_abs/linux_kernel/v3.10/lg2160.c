static int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_2 V_4 )
{
int V_5 ;
T_2 V_6 [] = { V_3 >> 8 , V_3 & 0xff , V_4 } ;
struct V_7 V_8 = {
. V_9 = V_2 -> V_10 -> V_11 , . V_12 = 0 ,
. V_6 = V_6 , . V_13 = 3 ,
} ;
F_2 ( L_1 , V_3 , V_4 ) ;
V_5 = F_3 ( V_2 -> V_14 , & V_8 , 1 ) ;
if ( V_5 != 1 ) {
F_4 ( L_2 ,
V_8 . V_6 [ 0 ] , V_8 . V_6 [ 1 ] , V_8 . V_6 [ 2 ] , V_5 ) ;
if ( V_5 < 0 )
return V_5 ;
else
return - V_15 ;
}
return 0 ;
}
static int F_5 ( struct V_1 * V_2 , T_1 V_3 , T_2 * V_4 )
{
int V_5 ;
T_2 V_16 [] = { V_3 >> 8 , V_3 & 0xff } ;
struct V_7 V_8 [] = {
{ . V_9 = V_2 -> V_10 -> V_11 ,
. V_12 = 0 , . V_6 = V_16 , . V_13 = 2 } ,
{ . V_9 = V_2 -> V_10 -> V_11 ,
. V_12 = V_17 , . V_6 = V_4 , . V_13 = 1 } ,
} ;
F_2 ( L_3 , V_3 ) ;
V_5 = F_3 ( V_2 -> V_14 , V_8 , 2 ) ;
if ( V_5 != 2 ) {
F_4 ( L_4 ,
V_2 -> V_10 -> V_11 , V_3 , V_5 ) ;
if ( V_5 < 0 )
return V_5 ;
else
return - V_15 ;
}
return 0 ;
}
static int F_6 ( struct V_1 * V_2 ,
struct V_18 * V_19 , int V_13 )
{
int V_20 , V_5 ;
F_2 ( L_5 , V_13 ) ;
for ( V_20 = 0 ; V_20 < V_13 ; V_20 ++ ) {
V_5 = F_1 ( V_2 , V_19 [ V_20 ] . V_3 , V_19 [ V_20 ] . V_4 ) ;
if ( F_7 ( V_5 ) )
return V_5 ;
}
return 0 ;
}
static int F_8 ( struct V_1 * V_2 ,
T_1 V_3 , int V_21 , int V_22 )
{
T_2 V_4 ;
int V_5 ;
F_2 ( L_6 , V_3 , V_21 , V_22 ) ;
V_5 = F_5 ( V_2 , V_3 , & V_4 ) ;
if ( F_7 ( V_5 ) )
goto V_23;
V_4 &= ~ ( 1 << V_21 ) ;
V_4 |= ( V_22 & 1 ) << V_21 ;
V_5 = F_1 ( V_2 , V_3 , V_4 ) ;
F_7 ( V_5 ) ;
V_23:
return V_5 ;
}
static int F_9 ( struct V_24 * V_25 , int V_26 )
{
struct V_1 * V_2 = V_25 -> V_27 ;
int V_5 ;
if ( V_2 -> V_10 -> V_28 )
return 0 ;
F_10 ( L_7 , V_26 ) ;
V_5 = F_8 ( V_2 , 0x0000 , 0 , V_26 ? 0 : 1 ) ;
F_11 ( 1 ) ;
return V_5 ;
}
static int F_12 ( struct V_1 * V_2 )
{
int V_5 ;
F_10 ( L_8 ) ;
V_5 = F_1 ( V_2 , 0x0002 , 0x00 ) ;
if ( F_7 ( V_5 ) )
goto V_23;
F_11 ( 20 ) ;
V_5 = F_1 ( V_2 , 0x0002 , 0x01 ) ;
if ( F_7 ( V_5 ) )
goto V_23;
V_2 -> V_29 = F_13 ( V_30 ) ;
V_23:
return V_5 ;
}
static int F_14 ( struct V_1 * V_2 )
{
int V_5 ;
static struct V_18 V_31 [] = {
#if 0
{ .reg = 0x0015, .val = 0xe6 },
#else
{ . V_3 = 0x0015 , . V_4 = 0xf7 } ,
{ . V_3 = 0x001b , . V_4 = 0x52 } ,
{ . V_3 = 0x0208 , . V_4 = 0x00 } ,
{ . V_3 = 0x0209 , . V_4 = 0x82 } ,
{ . V_3 = 0x0210 , . V_4 = 0xf9 } ,
{ . V_3 = 0x020a , . V_4 = 0x00 } ,
{ . V_3 = 0x020b , . V_4 = 0x82 } ,
{ . V_3 = 0x020d , . V_4 = 0x28 } ,
{ . V_3 = 0x020f , . V_4 = 0x14 } ,
#endif
} ;
static struct V_18 V_32 [] = {
{ . V_3 = 0x0000 , . V_4 = 0x41 } ,
{ . V_3 = 0x0001 , . V_4 = 0xfb } ,
{ . V_3 = 0x0216 , . V_4 = 0x00 } ,
{ . V_3 = 0x0219 , . V_4 = 0x00 } ,
{ . V_3 = 0x021b , . V_4 = 0x55 } ,
{ . V_3 = 0x0606 , . V_4 = 0x0a } ,
} ;
switch ( V_2 -> V_10 -> V_33 ) {
case V_34 :
V_5 = F_6 ( V_2 ,
V_31 , F_15 ( V_31 ) ) ;
break;
case V_35 :
V_5 = F_6 ( V_2 ,
V_32 , F_15 ( V_32 ) ) ;
break;
default:
V_5 = - V_36 ;
break;
}
if ( F_7 ( V_5 ) )
goto V_23;
V_5 = F_12 ( V_2 ) ;
F_7 ( V_5 ) ;
V_23:
return V_5 ;
}
static int F_16 ( struct V_1 * V_2 )
{
T_2 V_4 ;
int V_5 ;
F_10 ( L_9 , V_2 -> V_10 -> V_37 ) ;
V_5 = F_5 ( V_2 , 0x0132 , & V_4 ) ;
if ( F_7 ( V_5 ) )
goto V_23;
V_4 &= 0xfb ;
V_4 |= ( 0 == V_2 -> V_10 -> V_37 ) ? 0x04 : 0x00 ;
V_5 = F_1 ( V_2 , 0x0132 , V_4 ) ;
F_7 ( V_5 ) ;
V_23:
return V_5 ;
}
static int F_17 ( struct V_1 * V_2 ,
int V_38 , int V_39 )
{
T_2 V_4 ;
int V_5 ;
V_5 = F_5 ( V_2 , 0x0100 , & V_4 ) ;
if ( F_7 ( V_5 ) )
goto V_23;
V_4 &= 0xf3 ;
V_4 |= ( V_38 ) ? 0x08 : 0x00 ;
V_4 |= ( V_39 ) ? 0x04 : 0x00 ;
V_5 = F_1 ( V_2 , 0x0100 , V_4 ) ;
F_7 ( V_5 ) ;
V_23:
return V_5 ;
}
static int F_18 ( struct V_1 * V_2 ,
int V_40 , int V_41 )
{
T_2 V_4 ;
int V_5 ;
V_5 = F_5 ( V_2 , 0x0100 , & V_4 ) ;
if ( F_7 ( V_5 ) )
goto V_23;
V_4 &= 0xfc ;
V_4 |= ( V_40 ) ? 0x02 : 0x00 ;
V_4 |= ( V_41 ) ? 0x01 : 0x00 ;
V_5 = F_1 ( V_2 , 0x0100 , V_4 ) ;
F_7 ( V_5 ) ;
V_23:
return V_5 ;
}
static int F_19 ( struct V_1 * V_2 ,
int V_42 )
{
T_2 V_4 ;
int V_5 ;
V_5 = F_5 ( V_2 , 0x0008 , & V_4 ) ;
if ( F_7 ( V_5 ) )
goto V_23;
V_4 &= 0xfe ;
V_4 |= ( V_42 ) ? 0x01 : 0x00 ;
V_5 = F_1 ( V_2 , 0x0008 , V_4 ) ;
F_7 ( V_5 ) ;
V_23:
return V_5 ;
}
static int F_20 ( struct V_1 * V_2 ,
int V_43 )
{
T_2 V_4 ;
int V_5 ;
V_5 = F_5 ( V_2 , 0x0132 , & V_4 ) ;
if ( F_7 ( V_5 ) )
goto V_23;
V_4 &= 0xfd ;
V_4 |= ( V_43 ) ? 0x02 : 0x00 ;
V_5 = F_1 ( V_2 , 0x0132 , V_4 ) ;
F_7 ( V_5 ) ;
V_23:
return F_12 ( V_2 ) ;
}
static int F_21 ( struct V_1 * V_2 , int V_22 )
{
T_2 V_4 ;
int V_5 ;
V_5 = F_5 ( V_2 , 0x0007 , & V_4 ) ;
if ( F_7 ( V_5 ) )
goto V_23;
V_4 &= 0xbf ;
V_4 |= ( V_22 ) ? 0x40 : 0x00 ;
V_5 = F_1 ( V_2 , 0x0007 , V_4 ) ;
F_7 ( V_5 ) ;
V_23:
return V_5 ;
}
static int F_22 ( struct V_1 * V_2 , int V_44 )
{
int V_5 ;
V_5 = F_1 ( V_2 , 0x013e , V_44 & 0x7f ) ;
if ( F_7 ( V_5 ) )
goto V_23;
V_2 -> V_45 = V_44 & 0x7f ;
V_23:
return V_5 ;
}
static int F_23 ( struct V_1 * V_2 , int V_44 )
{
int V_5 ;
T_1 V_3 ;
T_2 V_4 ;
switch ( V_2 -> V_10 -> V_33 ) {
case V_34 :
V_3 = 0x0400 ;
break;
case V_35 :
default:
V_3 = 0x0500 ;
break;
}
V_5 = F_5 ( V_2 , V_3 , & V_4 ) ;
if ( F_7 ( V_5 ) )
goto V_23;
V_4 &= 0xfe ;
V_4 |= ( V_44 ) ? 0x01 : 0x00 ;
V_5 = F_1 ( V_2 , V_3 , V_4 ) ;
F_7 ( V_5 ) ;
V_23:
return V_5 ;
}
static int F_24 ( struct V_1 * V_2 )
{
T_2 V_4 ;
int V_5 ;
V_5 = F_5 ( V_2 , 0x0014 , & V_4 ) ;
if ( F_7 ( V_5 ) )
goto V_23;
V_4 &= 0xf3 ;
V_4 |= ( V_2 -> V_10 -> V_46 << 2 ) ;
V_5 = F_1 ( V_2 , 0x0014 , V_4 ) ;
F_7 ( V_5 ) ;
V_23:
return V_5 ;
}
static int F_25 ( struct V_1 * V_2 )
{
T_2 V_4 ;
int V_5 ;
V_5 = F_5 ( V_2 , 0x0014 , & V_4 ) ;
if ( F_7 ( V_5 ) )
goto V_23;
V_4 &= ~ 0x07 ;
V_4 |= V_2 -> V_10 -> V_47 ;
V_5 = F_1 ( V_2 , 0x0014 , V_4 ) ;
F_7 ( V_5 ) ;
V_23:
return V_5 ;
}
static int F_26 ( struct V_1 * V_2 , int V_22 )
{
int V_5 ;
V_5 = F_1 ( V_2 , 0x0017 , 0x23 ) ;
if ( F_7 ( V_5 ) )
goto V_23;
V_5 = F_1 ( V_2 , 0x0016 , 0xfc ) ;
if ( F_7 ( V_5 ) )
goto V_23;
switch ( V_2 -> V_10 -> V_33 ) {
case V_34 :
V_5 = F_1 ( V_2 , 0x0016 ,
0xfc | ( ( V_22 ) ? 0x02 : 0x00 ) ) ;
break;
case V_35 :
V_5 = F_1 ( V_2 , 0x0016 , ( V_22 ) ? 0x10 : 0x00 ) ;
break;
}
if ( F_7 ( V_5 ) )
goto V_23;
V_5 = F_14 ( V_2 ) ;
if ( F_7 ( V_5 ) )
goto V_23;
if ( V_22 ) {
V_5 = F_1 ( V_2 , 0x0017 , 0x03 ) ;
F_7 ( V_5 ) ;
}
V_23:
return V_5 ;
}
static int F_27 ( struct V_1 * V_2 , T_2 * V_48 )
{
T_2 V_4 ;
int V_5 ;
* V_48 = 0xff ;
V_5 = F_5 ( V_2 , 0x0128 , & V_4 ) ;
if ( F_7 ( V_5 ) )
goto V_23;
* V_48 = ( V_4 >> 3 ) & 0x1f ;
V_23:
return V_5 ;
}
static int F_28 ( struct V_1 * V_2 , T_2 * V_49 )
{
T_2 V_4 ;
int V_5 ;
* V_49 = 0xff ;
V_5 = F_5 ( V_2 , 0x0124 , & V_4 ) ;
if ( F_7 ( V_5 ) )
goto V_23;
* V_49 = ( ( V_4 >> 4 ) & 0x07 ) + 1 ;
V_23:
return V_5 ;
}
static int F_29 ( struct V_1 * V_2 , T_2 * V_50 )
{
T_2 V_4 ;
int V_5 ;
* V_50 = 0xff ;
V_5 = F_5 ( V_2 , 0x0125 , & V_4 ) ;
if ( F_7 ( V_5 ) )
goto V_23;
* V_50 = V_4 & 0x1f ;
V_23:
return V_5 ;
}
static int F_30 ( struct V_1 * V_2 , T_2 * V_51 )
{
T_2 V_4 ;
int V_5 ;
* V_51 = 0xff ;
V_5 = F_5 ( V_2 , 0x0124 , & V_4 ) ;
if ( F_7 ( V_5 ) )
goto V_23;
* V_51 = V_4 & 0x0f ;
V_23:
return V_5 ;
}
static int F_31 ( struct V_1 * V_2 , T_2 * V_52 )
{
T_2 V_4 ;
int V_5 ;
* V_52 = 0xff ;
V_5 = F_5 ( V_2 , 0x0125 , & V_4 ) ;
if ( F_7 ( V_5 ) )
goto V_23;
* V_52 = ( ( V_4 >> 5 ) & 0x07 ) + 1 ;
V_23:
return V_5 ;
}
static int F_32 ( struct V_1 * V_2 ,
enum V_53 * V_54 )
{
T_2 V_4 ;
int V_5 ;
switch ( V_2 -> V_10 -> V_33 ) {
case V_34 :
V_5 = F_5 ( V_2 , 0x0410 , & V_4 ) ;
break;
case V_35 :
V_5 = F_5 ( V_2 , 0x0513 , & V_4 ) ;
break;
default:
V_5 = - V_36 ;
}
if ( F_7 ( V_5 ) )
goto V_23;
switch ( ( V_4 >> 4 ) & 0x03 ) {
#if 1
default:
#endif
case 0x00 :
* V_54 = V_55 ;
break;
case 0x01 :
* V_54 = V_56 ;
break;
#if 0
default:
*rs_framemode = ATSCMH_RSFRAME_RES;
break;
#endif
}
V_23:
return V_5 ;
}
static
int F_33 ( struct V_1 * V_2 ,
enum V_57 * V_58 )
{
T_2 V_4 ;
int V_5 ;
switch ( V_2 -> V_10 -> V_33 ) {
case V_34 :
V_5 = F_5 ( V_2 , 0x0400 , & V_4 ) ;
break;
case V_35 :
V_5 = F_5 ( V_2 , 0x0500 , & V_4 ) ;
break;
default:
V_5 = - V_36 ;
}
if ( F_7 ( V_5 ) )
goto V_23;
V_4 &= 0x01 ;
* V_58 = (enum V_57 ) V_4 ;
V_23:
return V_5 ;
}
static int F_34 ( struct V_1 * V_2 ,
enum V_59 * V_60 ,
enum V_59 * V_61 )
{
T_2 V_4 ;
int V_5 ;
switch ( V_2 -> V_10 -> V_33 ) {
case V_34 :
V_5 = F_5 ( V_2 , 0x0410 , & V_4 ) ;
break;
case V_35 :
V_5 = F_5 ( V_2 , 0x0513 , & V_4 ) ;
break;
default:
V_5 = - V_36 ;
}
if ( F_7 ( V_5 ) )
goto V_23;
* V_60 = (enum V_59 ) ( ( V_4 >> 2 ) & 0x03 ) ;
* V_61 = (enum V_59 ) ( V_4 & 0x03 ) ;
V_23:
return V_5 ;
}
static int F_35 ( struct V_1 * V_2 ,
enum V_62 * V_63 )
{
T_2 V_4 ;
int V_5 ;
switch ( V_2 -> V_10 -> V_33 ) {
case V_34 :
V_5 = F_5 ( V_2 , 0x0315 , & V_4 ) ;
break;
case V_35 :
V_5 = F_5 ( V_2 , 0x0511 , & V_4 ) ;
break;
default:
V_5 = - V_36 ;
}
if ( F_7 ( V_5 ) )
goto V_23;
switch ( V_4 & 0x03 ) {
case 0x00 :
* V_63 = V_64 ;
break;
case 0x01 :
* V_63 = V_65 ;
break;
default:
* V_63 = V_66 ;
break;
}
V_23:
return V_5 ;
}
static int F_36 ( struct V_1 * V_2 ,
enum V_67 * V_68 ,
enum V_67 * V_69 ,
enum V_67 * V_70 ,
enum V_67 * V_71 )
{
T_2 V_4 ;
int V_5 ;
switch ( V_2 -> V_10 -> V_33 ) {
case V_34 :
V_5 = F_5 ( V_2 , 0x0316 , & V_4 ) ;
break;
case V_35 :
V_5 = F_5 ( V_2 , 0x0512 , & V_4 ) ;
break;
default:
V_5 = - V_36 ;
}
if ( F_7 ( V_5 ) )
goto V_23;
switch ( ( V_4 >> 6 ) & 0x03 ) {
case 0x00 :
* V_68 = V_72 ;
break;
case 0x01 :
* V_68 = V_73 ;
break;
default:
* V_68 = V_74 ;
break;
}
switch ( ( V_4 >> 4 ) & 0x03 ) {
case 0x00 :
* V_69 = V_72 ;
break;
case 0x01 :
* V_69 = V_73 ;
break;
default:
* V_69 = V_74 ;
break;
}
switch ( ( V_4 >> 2 ) & 0x03 ) {
case 0x00 :
* V_70 = V_72 ;
break;
case 0x01 :
* V_70 = V_73 ;
break;
default:
* V_70 = V_74 ;
break;
}
switch ( V_4 & 0x03 ) {
case 0x00 :
* V_71 = V_72 ;
break;
case 0x01 :
* V_71 = V_73 ;
break;
default:
* V_71 = V_74 ;
break;
}
V_23:
return V_5 ;
}
static int F_37 ( struct V_24 * V_25 )
{
struct V_1 * V_2 = V_25 -> V_27 ;
int V_5 ;
F_10 ( L_8 ) ;
V_25 -> V_75 . V_76 = V_77 ;
V_25 -> V_75 . V_78 = V_2 -> V_79 ;
V_25 -> V_75 . V_80 = V_81 ;
V_5 = F_27 ( V_2 ,
& V_25 -> V_75 . V_82 ) ;
if ( F_7 ( V_5 ) )
goto V_23;
if ( V_2 -> V_83 != V_25 -> V_75 . V_82 ) {
V_2 -> V_83 = V_25 -> V_75 . V_82 ;
#if 0
ret = lg2160_get_parade_id(state,
&fe->dtv_property_cache.atscmh_parade_id);
if (lg_fail(ret))
goto fail;
fe->dtv_property_cache.atscmh_parade_id = state->parade_id;
#endif
V_5 = F_28 ( V_2 ,
& V_25 -> V_75 . V_84 ) ;
if ( F_7 ( V_5 ) )
goto V_23;
V_5 = F_29 ( V_2 ,
& V_25 -> V_75 . V_85 ) ;
if ( F_7 ( V_5 ) )
goto V_23;
V_5 = F_30 ( V_2 ,
& V_25 -> V_75 . V_86 ) ;
if ( F_7 ( V_5 ) )
goto V_23;
V_5 = F_31 ( V_2 ,
& V_25 -> V_75 . V_87 ) ;
if ( F_7 ( V_5 ) )
goto V_23;
V_5 = F_32 ( V_2 ,
(enum V_53 * )
& V_25 -> V_75 . V_53 ) ;
if ( F_7 ( V_5 ) )
goto V_23;
V_5 = F_33 ( V_2 ,
(enum V_57 * )
& V_25 -> V_75 . V_57 ) ;
if ( F_7 ( V_5 ) )
goto V_23;
V_5 = F_34 ( V_2 ,
(enum V_59 * )
& V_25 -> V_75 . V_88 ,
(enum V_59 * )
& V_25 -> V_75 . V_89 ) ;
if ( F_7 ( V_5 ) )
goto V_23;
V_5 = F_35 ( V_2 ,
(enum V_62 * )
& V_25 -> V_75 . V_62 ) ;
if ( F_7 ( V_5 ) )
goto V_23;
V_5 = F_36 ( V_2 ,
(enum V_67 * )
& V_25 -> V_75 . V_90 ,
(enum V_67 * )
& V_25 -> V_75 . V_91 ,
(enum V_67 * )
& V_25 -> V_75 . V_92 ,
(enum V_67 * )
& V_25 -> V_75 . V_93 ) ;
if ( F_7 ( V_5 ) )
goto V_23;
}
#if 0
ret = lg216x_read_fic_err_count(state,
(u8 *)&fe->dtv_property_cache.atscmh_fic_err);
if (lg_fail(ret))
goto fail;
ret = lg216x_read_crc_err_count(state,
&fe->dtv_property_cache.atscmh_crc_err);
if (lg_fail(ret))
goto fail;
ret = lg216x_read_rs_err_count(state,
&fe->dtv_property_cache.atscmh_rs_err);
if (lg_fail(ret))
goto fail;
switch (state->cfg->lg_chip) {
case LG2160:
if (((fe->dtv_property_cache.atscmh_rs_err >= 240) &&
(fe->dtv_property_cache.atscmh_crc_err >= 240)) &&
((jiffies_to_msecs(jiffies) - state->last_reset) > 6000))
ret = lg216x_soft_reset(state);
break;
case LG2161:
ret = 0;
break;
}
lg_fail(ret);
#endif
V_23:
return V_5 ;
}
static int F_38 ( struct V_24 * V_25 ,
struct V_94 * V_95 )
{
return ( V_96 == V_95 -> V_97 ) ?
F_37 ( V_25 ) : 0 ;
}
static int F_39 ( struct V_24 * V_25 )
{
struct V_1 * V_2 = V_25 -> V_27 ;
int V_5 ;
F_10 ( L_7 , V_25 -> V_75 . V_78 ) ;
if ( V_25 -> V_98 . V_99 . V_100 ) {
V_5 = V_25 -> V_98 . V_99 . V_100 ( V_25 ) ;
if ( V_25 -> V_98 . V_101 )
V_25 -> V_98 . V_101 ( V_25 , 0 ) ;
if ( F_7 ( V_5 ) )
goto V_23;
V_2 -> V_79 = V_25 -> V_75 . V_78 ;
}
V_5 = F_17 ( V_2 , 0 , 0 ) ;
if ( F_7 ( V_5 ) )
goto V_23;
V_5 = F_18 ( V_2 , 0 , 0 ) ;
if ( F_7 ( V_5 ) )
goto V_23;
V_5 = F_19 ( V_2 , 1 ) ;
if ( F_7 ( V_5 ) )
goto V_23;
V_5 = F_16 ( V_2 ) ;
if ( F_7 ( V_5 ) )
goto V_23;
V_5 = F_20 ( V_2 , V_2 -> V_10 -> V_102 ) ;
if ( F_7 ( V_5 ) )
goto V_23;
V_5 = F_12 ( V_2 ) ;
if ( F_7 ( V_5 ) )
goto V_23;
V_5 = F_21 ( V_2 , 0 ) ;
if ( F_7 ( V_5 ) )
goto V_23;
switch ( V_2 -> V_10 -> V_33 ) {
case V_34 :
V_5 = F_24 ( V_2 ) ;
if ( F_7 ( V_5 ) )
goto V_23;
break;
case V_35 :
V_5 = F_25 ( V_2 ) ;
if ( F_7 ( V_5 ) )
goto V_23;
break;
}
V_5 = F_22 ( V_2 , V_25 -> V_75 . V_103 ) ;
if ( F_7 ( V_5 ) )
goto V_23;
V_5 = F_23 ( V_2 ,
V_25 -> V_75 . V_57 ) ;
if ( F_7 ( V_5 ) )
goto V_23;
V_5 = F_14 ( V_2 ) ;
if ( F_7 ( V_5 ) )
goto V_23;
V_5 = F_26 ( V_2 , 1 ) ;
F_7 ( V_5 ) ;
F_37 ( V_25 ) ;
V_23:
return V_5 ;
}
static int F_40 ( struct V_1 * V_2 ,
int * V_104 , int * V_105 )
{
T_2 V_4 ;
int V_5 ;
* V_104 = 0 ;
* V_105 = 0 ;
V_5 = F_5 ( V_2 , 0x011b , & V_4 ) ;
if ( F_7 ( V_5 ) )
goto V_23;
* V_105 = ( V_4 & 0x20 ) ? 0 : 1 ;
* V_104 = ( V_4 & 0x40 ) ? 0 : 1 ;
V_23:
return V_5 ;
}
static int F_41 ( struct V_1 * V_2 ,
int * V_104 , int * V_105 )
{
T_2 V_4 ;
int V_5 ;
* V_104 = 0 ;
* V_105 = 0 ;
V_5 = F_5 ( V_2 , 0x0304 , & V_4 ) ;
if ( F_7 ( V_5 ) )
goto V_23;
* V_105 = ( V_4 & 0x80 ) ? 0 : 1 ;
V_5 = F_5 ( V_2 , 0x011b , & V_4 ) ;
if ( F_7 ( V_5 ) )
goto V_23;
* V_104 = ( V_4 & 0x40 ) ? 0 : 1 ;
V_23:
return V_5 ;
}
static int F_42 ( struct V_1 * V_2 ,
int * V_104 , int * V_105 )
{
#ifdef F_43
int V_5 ;
switch ( V_2 -> V_10 -> V_33 ) {
case V_34 :
V_5 = F_40 ( V_2 , V_104 , V_105 ) ;
break;
case V_35 :
V_5 = F_41 ( V_2 , V_104 , V_105 ) ;
break;
default:
V_5 = - V_36 ;
break;
}
return V_5 ;
#else
return F_40 ( V_2 , V_104 , V_105 ) ;
#endif
}
static int F_44 ( struct V_24 * V_25 , T_3 * V_106 )
{
struct V_1 * V_2 = V_25 -> V_27 ;
int V_5 , V_104 , V_105 ;
* V_106 = 0 ;
V_5 = F_42 ( V_2 , & V_104 , & V_105 ) ;
if ( F_7 ( V_5 ) )
goto V_23;
F_10 ( L_10 ,
V_104 ? L_11 : L_12 ,
V_105 ? L_13 : L_12 ) ;
if ( V_104 )
* V_106 |= V_107 ;
if ( V_105 )
* V_106 |= V_108 ;
if ( * V_106 )
* V_106 |= V_109 | V_110 | V_111 ;
V_23:
return V_5 ;
}
static int F_45 ( struct V_24 * V_25 , T_1 * V_112 )
{
struct V_1 * V_2 = V_25 -> V_27 ;
T_2 V_113 , V_114 ;
int V_5 ;
* V_112 = 0 ;
V_5 = F_5 ( V_2 , 0x0202 , & V_113 ) ;
if ( F_7 ( V_5 ) )
goto V_23;
V_5 = F_5 ( V_2 , 0x0203 , & V_114 ) ;
if ( F_7 ( V_5 ) )
goto V_23;
if ( ( V_113 == 0xba ) || ( V_114 == 0xdf ) )
* V_112 = 0 ;
else
#if 1
* V_112 = ( ( V_113 >> 4 ) * 100 ) + ( ( V_113 & 0x0f ) * 10 ) + ( V_114 >> 4 ) ;
#else
* V_112 = ( V_114 | ( V_113 << 8 ) ) ;
#endif
V_23:
return V_5 ;
}
static int F_46 ( struct V_24 * V_25 , T_1 * V_112 )
{
struct V_1 * V_2 = V_25 -> V_27 ;
T_2 V_113 , V_114 ;
int V_5 ;
* V_112 = 0 ;
V_5 = F_5 ( V_2 , 0x0302 , & V_113 ) ;
if ( F_7 ( V_5 ) )
goto V_23;
V_5 = F_5 ( V_2 , 0x0303 , & V_114 ) ;
if ( F_7 ( V_5 ) )
goto V_23;
if ( ( V_113 == 0xba ) || ( V_114 == 0xfd ) )
* V_112 = 0 ;
else
* V_112 = ( ( V_113 >> 4 ) * 100 ) + ( ( V_113 & 0x0f ) * 10 ) + ( V_114 & 0x0f ) ;
V_23:
return V_5 ;
}
static int F_47 ( struct V_24 * V_25 ,
T_1 * V_115 )
{
#if 0
struct lg216x_state *state = fe->demodulator_priv;
u16 snr;
int ret;
#endif
* V_115 = 0 ;
#if 0
ret = fe->ops.read_snr(fe, &snr);
if (lg_fail(ret))
goto fail;
if (state->snr >= 8960 * 0x10000)
*strength = 0xffff;
else
*strength = state->snr / 8960;
fail:
return ret;
#else
return 0 ;
#endif
}
static int F_48 ( struct V_24 * V_25 , T_4 * V_116 )
{
#if 0
struct lg216x_state *state = fe->demodulator_priv;
int ret;
ret = lg216x_read_rs_err_count(state,
&fe->dtv_property_cache.atscmh_rs_err);
if (lg_fail(ret))
goto fail;
*ucblocks = fe->dtv_property_cache.atscmh_rs_err;
fail:
#else
* V_116 = 0 ;
#endif
return 0 ;
}
static int F_49 ( struct V_24 * V_25 ,
struct V_117
* V_118 )
{
V_118 -> V_119 = 500 ;
F_10 ( L_8 ) ;
return 0 ;
}
static void F_50 ( struct V_24 * V_25 )
{
struct V_1 * V_2 = V_25 -> V_27 ;
F_10 ( L_8 ) ;
F_51 ( V_2 ) ;
}
struct V_24 * F_52 ( const struct V_120 * V_121 ,
struct V_122 * V_14 )
{
struct V_1 * V_2 = NULL ;
F_10 ( L_14 ,
V_14 ? F_53 ( V_14 ) : 0 ,
V_121 ? V_121 -> V_11 : 0 ) ;
V_2 = F_54 ( sizeof( struct V_1 ) , V_123 ) ;
if ( ! V_2 )
return NULL ;
V_2 -> V_10 = V_121 ;
V_2 -> V_14 = V_14 ;
V_2 -> V_83 = 0xff ;
V_2 -> V_45 = 0xff ;
switch ( V_121 -> V_33 ) {
default:
F_55 ( L_15 ) ;
case V_34 :
memcpy ( & V_2 -> V_124 . V_98 , & V_125 ,
sizeof( struct V_126 ) ) ;
break;
case V_35 :
memcpy ( & V_2 -> V_124 . V_98 , & V_127 ,
sizeof( struct V_126 ) ) ;
break;
}
V_2 -> V_124 . V_27 = V_2 ;
V_2 -> V_79 = - 1 ;
V_2 -> V_124 . V_75 . V_103 = 1 ;
return & V_2 -> V_124 ;
}
