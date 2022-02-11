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
V_5 = F_3 ( V_2 -> V_14 , V_8 , 2 ) ;
if ( V_5 != 2 ) {
F_4 ( L_3 ,
V_2 -> V_10 -> V_11 , V_3 , V_5 ) ;
if ( V_5 < 0 )
return V_5 ;
else
return - V_15 ;
}
F_2 ( L_1 , V_3 , * V_4 ) ;
return 0 ;
}
static int F_6 ( struct V_1 * V_2 ,
T_1 V_3 , int V_18 , int V_19 )
{
T_2 V_4 ;
int V_5 ;
F_2 ( L_4 , V_3 , V_18 , V_19 ) ;
V_5 = F_5 ( V_2 , V_3 , & V_4 ) ;
if ( F_7 ( V_5 ) )
goto V_20;
V_4 &= ~ ( 1 << V_18 ) ;
V_4 |= ( V_19 & 1 ) << V_18 ;
V_5 = F_1 ( V_2 , V_3 , V_4 ) ;
F_7 ( V_5 ) ;
V_20:
return V_5 ;
}
static int F_8 ( struct V_1 * V_2 )
{
int V_5 ;
F_9 ( L_5 ) ;
V_5 = F_6 ( V_2 , 0x0000 , 7 , 0 ) ;
if ( F_7 ( V_5 ) )
goto V_20;
F_10 ( 20 ) ;
V_5 = F_6 ( V_2 , 0x0000 , 7 , 1 ) ;
F_7 ( V_5 ) ;
V_20:
return V_5 ;
}
static int F_11 ( struct V_1 * V_2 ,
enum F_11 V_21 )
{
T_2 V_4 ;
int V_5 ;
F_9 ( L_6 , V_21 ) ;
V_5 = F_6 ( V_2 , 0x0071 , 7 ,
V_21 == V_22 ? 1 : 0 ) ;
if ( F_7 ( V_5 ) )
goto V_20;
V_5 = F_6 ( V_2 , 0x0071 , 6 , 0 ) ;
if ( F_7 ( V_5 ) )
goto V_20;
V_5 = F_5 ( V_2 , 0x0070 , & V_4 ) ;
if ( F_7 ( V_5 ) )
goto V_20;
V_4 |= 0x10 ;
if ( V_21 == V_22 )
V_4 &= ~ 0x10 ;
V_5 = F_1 ( V_2 , 0x0070 , V_4 ) ;
F_7 ( V_5 ) ;
V_20:
return V_5 ;
}
static int F_12 ( struct V_1 * V_2 ,
enum V_23 V_24 ,
enum V_25 V_26 )
{
T_2 V_4 ;
int V_5 ;
F_9 ( L_7 , V_24 , V_26 ) ;
V_5 = F_5 ( V_2 , 0x0070 , & V_4 ) ;
if ( F_7 ( V_5 ) )
goto V_20;
V_4 &= ~ 0x06 ;
if ( V_24 == V_27 )
V_4 |= 0x04 ;
if ( V_26 == V_28 )
V_4 |= 0x02 ;
V_5 = F_1 ( V_2 , 0x0070 , V_4 ) ;
F_7 ( V_5 ) ;
V_20:
return V_5 ;
}
static int F_13 ( struct V_1 * V_2 ,
int V_21 )
{
T_2 V_4 ;
int V_5 ;
F_9 ( L_6 , V_21 ) ;
if ( V_21 ) {
V_5 = F_5 ( V_2 , 0x0070 , & V_4 ) ;
if ( F_7 ( V_5 ) )
goto V_20;
V_4 &= ~ 0xa8 ;
V_5 = F_1 ( V_2 , 0x0070 , V_4 ) ;
if ( F_7 ( V_5 ) )
goto V_20;
V_5 = F_6 ( V_2 , 0x0003 , 6 , 1 ) ;
if ( F_7 ( V_5 ) )
goto V_20;
} else {
V_5 = F_6 ( V_2 , 0x0003 , 6 , 0 ) ;
if ( F_7 ( V_5 ) )
goto V_20;
V_5 = F_5 ( V_2 , 0x0070 , & V_4 ) ;
if ( F_7 ( V_5 ) )
goto V_20;
V_4 |= 0xa8 ;
V_5 = F_1 ( V_2 , 0x0070 , V_4 ) ;
if ( F_7 ( V_5 ) )
goto V_20;
}
V_20:
return V_5 ;
}
static int F_14 ( struct V_29 * V_30 , int V_31 )
{
struct V_1 * V_2 = V_30 -> V_32 ;
F_9 ( L_8 , V_31 ) ;
return F_13 ( V_2 , V_31 ? 0 : 1 ) ;
}
static int F_15 ( struct V_1 * V_2 ,
int V_21 )
{
int V_5 ;
F_9 ( L_6 , V_21 ) ;
if ( V_21 == 0 ) {
V_5 = F_6 ( V_2 , 0x0000 , 7 , 0 ) ;
if ( F_7 ( V_5 ) )
goto V_20;
V_5 = F_6 ( V_2 , 0x0000 , 0 , 0 ) ;
if ( F_7 ( V_5 ) )
goto V_20;
} else {
V_5 = F_6 ( V_2 , 0x0000 , 7 , 1 ) ;
if ( F_7 ( V_5 ) )
goto V_20;
V_5 = F_6 ( V_2 , 0x0000 , 0 , 1 ) ;
if ( F_7 ( V_5 ) )
goto V_20;
}
#ifdef F_16
F_17 ( V_2 ) ;
#endif
V_20:
return V_5 ;
}
static int F_18 ( struct V_1 * V_2 )
{
T_2 V_4 ;
int V_5 ;
F_9 ( L_5 ) ;
V_5 = F_5 ( V_2 , 0x0002 , & V_4 ) ;
V_4 &= 0xf7 ;
V_4 |= 0x04 ;
V_5 = F_1 ( V_2 , 0x0002 , V_4 ) ;
if ( F_7 ( V_5 ) )
goto V_20;
V_5 = F_1 ( V_2 , 0x0008 , 0x80 ) ;
if ( F_7 ( V_5 ) )
goto V_20;
V_5 = F_5 ( V_2 , 0x0009 , & V_4 ) ;
V_4 &= 0xe3 ;
V_4 |= 0x0c ;
V_5 = F_1 ( V_2 , 0x0009 , V_4 ) ;
if ( F_7 ( V_5 ) )
goto V_20;
V_5 = F_5 ( V_2 , 0x0009 , & V_4 ) ;
V_4 &= 0xfc ;
V_5 = F_1 ( V_2 , 0x0009 , V_4 ) ;
if ( F_7 ( V_5 ) )
goto V_20;
V_5 = F_5 ( V_2 , 0x000d , & V_4 ) ;
V_4 &= 0xbf ;
V_5 = F_1 ( V_2 , 0x000d , V_4 ) ;
if ( F_7 ( V_5 ) )
goto V_20;
#if 0
ret = lgdt3306a_write_reg(state, 0x0024, 0x00);
if (lg_chkerr(ret))
goto fail;
ret = lgdt3306a_write_reg(state, 0x002e, 0x00);
ret = lgdt3306a_write_reg(state, 0x002f, 0x00);
ret = lgdt3306a_write_reg(state, 0x0030, 0x00);
ret = lgdt3306a_write_reg(state, 0x002b, 0x00);
ret = lgdt3306a_write_reg(state, 0x002c, 0x00);
ret = lgdt3306a_write_reg(state, 0x002d, 0x00);
ret = lgdt3306a_write_reg(state, 0x0028, 0x00);
ret = lgdt3306a_write_reg(state, 0x0029, 0x00);
ret = lgdt3306a_write_reg(state, 0x002a, 0x00);
ret = lgdt3306a_write_reg(state, 0x0025, 0x00);
ret = lgdt3306a_write_reg(state, 0x0026, 0x00);
ret = lgdt3306a_write_reg(state, 0x0027, 0x00);
#else
V_5 = F_1 ( V_2 , 0x0024 , 0x5A ) ;
if ( F_7 ( V_5 ) )
goto V_20;
V_5 = F_1 ( V_2 , 0x002e , 0x5A ) ;
V_5 = F_1 ( V_2 , 0x002f , 0x00 ) ;
V_5 = F_1 ( V_2 , 0x0030 , 0x00 ) ;
V_5 = F_1 ( V_2 , 0x002b , 0x36 ) ;
V_5 = F_1 ( V_2 , 0x002c , 0x00 ) ;
V_5 = F_1 ( V_2 , 0x002d , 0x00 ) ;
V_5 = F_1 ( V_2 , 0x0028 , 0x2A ) ;
V_5 = F_1 ( V_2 , 0x0029 , 0x00 ) ;
V_5 = F_1 ( V_2 , 0x002a , 0x00 ) ;
V_5 = F_1 ( V_2 , 0x0025 , 0x06 ) ;
V_5 = F_1 ( V_2 , 0x0026 , 0x00 ) ;
V_5 = F_1 ( V_2 , 0x0027 , 0x00 ) ;
#endif
V_5 = F_5 ( V_2 , 0x001e , & V_4 ) ;
V_4 &= 0x0f ;
V_4 |= 0xa0 ;
V_5 = F_1 ( V_2 , 0x001e , V_4 ) ;
V_5 = F_1 ( V_2 , 0x0022 , 0x08 ) ;
V_5 = F_1 ( V_2 , 0x0023 , 0xFF ) ;
V_5 = F_5 ( V_2 , 0x211f , & V_4 ) ;
V_4 &= 0xef ;
V_5 = F_1 ( V_2 , 0x211f , V_4 ) ;
V_5 = F_1 ( V_2 , 0x2173 , 0x01 ) ;
V_5 = F_5 ( V_2 , 0x1061 , & V_4 ) ;
V_4 &= 0xf8 ;
V_4 |= 0x04 ;
V_5 = F_1 ( V_2 , 0x1061 , V_4 ) ;
V_5 = F_5 ( V_2 , 0x103d , & V_4 ) ;
V_4 &= 0xcf ;
V_5 = F_1 ( V_2 , 0x103d , V_4 ) ;
V_5 = F_1 ( V_2 , 0x2122 , 0x40 ) ;
V_5 = F_5 ( V_2 , 0x2141 , & V_4 ) ;
V_4 &= 0x3f ;
V_5 = F_1 ( V_2 , 0x2141 , V_4 ) ;
V_5 = F_5 ( V_2 , 0x2135 , & V_4 ) ;
V_4 &= 0x0f ;
V_4 |= 0x70 ;
V_5 = F_1 ( V_2 , 0x2135 , V_4 ) ;
V_5 = F_5 ( V_2 , 0x0003 , & V_4 ) ;
V_4 &= 0xf7 ;
V_5 = F_1 ( V_2 , 0x0003 , V_4 ) ;
V_5 = F_5 ( V_2 , 0x001c , & V_4 ) ;
V_4 &= 0x7f ;
V_5 = F_1 ( V_2 , 0x001c , V_4 ) ;
V_5 = F_5 ( V_2 , 0x2179 , & V_4 ) ;
V_4 &= 0xf8 ;
V_5 = F_1 ( V_2 , 0x2179 , V_4 ) ;
V_5 = F_5 ( V_2 , 0x217a , & V_4 ) ;
V_4 &= 0xf8 ;
V_5 = F_1 ( V_2 , 0x217a , V_4 ) ;
V_5 = F_8 ( V_2 ) ;
if ( F_7 ( V_5 ) )
goto V_20;
F_9 ( L_9 ) ;
V_20:
return V_5 ;
}
static int F_19 ( struct V_1 * V_2 , int V_33 )
{
T_2 V_4 ;
int V_5 ;
F_9 ( L_10 , V_33 ) ;
V_5 = F_1 ( V_2 , 0x0008 , 0x08 ) ;
if ( F_7 ( V_5 ) )
goto V_20;
V_5 = F_5 ( V_2 , 0x0002 , & V_4 ) ;
V_4 &= 0xfb ;
V_4 |= 0x08 ;
V_5 = F_1 ( V_2 , 0x0002 , V_4 ) ;
if ( F_7 ( V_5 ) )
goto V_20;
V_5 = F_5 ( V_2 , 0x0009 , & V_4 ) ;
V_4 &= 0xe3 ;
V_5 = F_1 ( V_2 , 0x0009 , V_4 ) ;
if ( F_7 ( V_5 ) )
goto V_20;
V_5 = F_5 ( V_2 , 0x0009 , & V_4 ) ;
V_4 &= 0xfc ;
V_4 |= 0x02 ;
V_5 = F_1 ( V_2 , 0x0009 , V_4 ) ;
if ( F_7 ( V_5 ) )
goto V_20;
V_5 = F_5 ( V_2 , 0x101a , & V_4 ) ;
V_4 &= 0xf8 ;
if ( V_33 == V_34 )
V_4 |= 0x02 ;
else
V_4 |= 0x04 ;
V_5 = F_1 ( V_2 , 0x101a , V_4 ) ;
if ( F_7 ( V_5 ) )
goto V_20;
V_5 = F_5 ( V_2 , 0x000d , & V_4 ) ;
V_4 &= 0xbf ;
V_4 |= 0x40 ;
V_5 = F_1 ( V_2 , 0x000d , V_4 ) ;
if ( F_7 ( V_5 ) )
goto V_20;
V_5 = F_5 ( V_2 , 0x0024 , & V_4 ) ;
V_4 &= 0x00 ;
V_5 = F_1 ( V_2 , 0x0024 , V_4 ) ;
if ( F_7 ( V_5 ) )
goto V_20;
V_5 = F_8 ( V_2 ) ;
if ( F_7 ( V_5 ) )
goto V_20;
F_9 ( L_9 ) ;
V_20:
return V_5 ;
}
static int F_20 ( struct V_1 * V_2 ,
struct V_35 * V_36 )
{
int V_5 ;
F_9 ( L_5 ) ;
switch ( V_36 -> V_33 ) {
case V_37 :
V_5 = F_18 ( V_2 ) ;
break;
case V_34 :
V_5 = F_19 ( V_2 , V_34 ) ;
break;
case V_38 :
V_5 = F_19 ( V_2 , V_38 ) ;
break;
default:
return - V_39 ;
}
if ( F_7 ( V_5 ) )
goto V_20;
V_2 -> V_40 = V_36 -> V_33 ;
V_20:
return V_5 ;
}
static int F_21 ( struct V_1 * V_2 ,
struct V_35 * V_36 )
{
F_9 ( L_5 ) ;
switch ( V_36 -> V_33 ) {
case V_37 :
break;
case V_34 :
case V_38 :
break;
default:
return - V_39 ;
}
return 0 ;
}
static int F_22 ( struct V_1 * V_2 ,
int V_41 )
{
int V_5 ;
F_9 ( L_6 , V_41 ) ;
V_5 = F_6 ( V_2 , 0x0002 , 2 , V_41 ? 1 : 0 ) ;
return V_5 ;
}
static int F_23 ( struct V_1 * V_2 ,
int V_42 )
{
int V_5 ;
F_9 ( L_6 , V_42 ) ;
V_5 = F_6 ( V_2 , 0x0002 , 3 , V_42 ) ;
return V_5 ;
}
static int F_24 ( struct V_1 * V_2 ,
struct V_35 * V_36 ,
int V_41 )
{
int V_5 = 0 ;
F_9 ( L_6 , V_41 ) ;
#if 0
ret = lgdt3306a_set_inversion(state, inversion);
switch (p->modulation) {
case VSB_8:
ret = lgdt3306a_set_inversion_auto(state, 0);
break;
case QAM_64:
case QAM_256:
ret = lgdt3306a_set_inversion_auto(state, 1);
break;
default:
ret = -EINVAL;
}
#endif
return V_5 ;
}
static int F_25 ( struct V_1 * V_2 ,
struct V_35 * V_36 )
{
int V_5 ;
T_1 V_43 ;
T_2 V_44 , V_45 ;
switch ( V_36 -> V_33 ) {
case V_37 :
V_43 = V_2 -> V_10 -> V_46 ;
break;
case V_34 :
case V_38 :
V_43 = V_2 -> V_10 -> V_47 ;
break;
default:
return - V_39 ;
}
switch ( V_43 ) {
default:
F_26 ( L_11 ,
V_43 ) ;
case 3250 :
V_44 = 0x34 ;
V_45 = 0x00 ;
break;
case 3500 :
V_44 = 0x38 ;
V_45 = 0x00 ;
break;
case 4000 :
V_44 = 0x40 ;
V_45 = 0x00 ;
break;
case 5000 :
V_44 = 0x50 ;
V_45 = 0x00 ;
break;
case 5380 :
V_44 = 0x56 ;
V_45 = 0x14 ;
break;
}
V_5 = F_1 ( V_2 , 0x0010 , V_44 ) ;
if ( V_5 )
return V_5 ;
V_5 = F_1 ( V_2 , 0x0011 , V_45 ) ;
if ( V_5 )
return V_5 ;
F_9 ( L_12 , V_43 , V_44 << 8 | V_45 ) ;
return 0 ;
}
static int F_27 ( struct V_29 * V_30 , int V_48 )
{
struct V_1 * V_2 = V_30 -> V_32 ;
if ( V_2 -> V_10 -> V_49 ) {
F_9 ( L_13 , V_2 -> V_10 -> V_49 ) ;
return 0 ;
}
F_9 ( L_6 , V_48 ) ;
return F_6 ( V_2 , 0x0002 , 7 , V_48 ? 0 : 1 ) ;
}
static int F_28 ( struct V_1 * V_2 )
{
int V_5 ;
F_9 ( L_5 ) ;
V_2 -> V_50 = - 1 ;
V_5 = F_13 ( V_2 , 1 ) ;
if ( F_7 ( V_5 ) )
goto V_20;
V_5 = F_15 ( V_2 , 0 ) ;
F_7 ( V_5 ) ;
V_20:
return 0 ;
}
static int F_29 ( struct V_29 * V_30 )
{
struct V_1 * V_2 = V_30 -> V_32 ;
return F_28 ( V_2 ) ;
}
static int F_30 ( struct V_29 * V_30 )
{
struct V_1 * V_2 = V_30 -> V_32 ;
T_2 V_4 ;
int V_5 ;
F_9 ( L_5 ) ;
V_5 = F_6 ( V_2 , 0x0001 , 0 , 1 ) ;
if ( F_7 ( V_5 ) )
goto V_20;
V_5 = F_23 ( V_2 , 0 ) ;
if ( F_7 ( V_5 ) )
goto V_20;
V_5 = F_22 ( V_2 , 1 ) ;
if ( F_7 ( V_5 ) )
goto V_20;
V_5 = F_6 ( V_2 , 0x0004 , 7 , 1 ) ;
if ( F_7 ( V_5 ) )
goto V_20;
V_5 = F_6 ( V_2 , 0x0004 , 2 , 0 ) ;
if ( F_7 ( V_5 ) )
goto V_20;
V_5 = F_6 ( V_2 , 0x0004 , 3 , 0 ) ;
if ( F_7 ( V_5 ) )
goto V_20;
V_5 = F_6 ( V_2 , 0x0005 , 6 , 0 ) ;
if ( F_7 ( V_5 ) )
goto V_20;
if ( V_2 -> V_10 -> V_51 == 24 ) {
V_5 = F_5 ( V_2 , 0x0005 , & V_4 ) ;
if ( F_7 ( V_5 ) )
goto V_20;
V_4 &= 0xc0 ;
V_4 |= 0x25 ;
V_5 = F_1 ( V_2 , 0x0005 , V_4 ) ;
if ( F_7 ( V_5 ) )
goto V_20;
V_5 = F_1 ( V_2 , 0x0006 , 0x64 ) ;
if ( F_7 ( V_5 ) )
goto V_20;
V_5 = F_5 ( V_2 , 0x000d , & V_4 ) ;
if ( F_7 ( V_5 ) )
goto V_20;
V_4 &= 0xc0 ;
V_4 |= 0x18 ;
V_5 = F_1 ( V_2 , 0x000d , V_4 ) ;
if ( F_7 ( V_5 ) )
goto V_20;
} else if ( V_2 -> V_10 -> V_51 == 25 ) {
V_5 = F_5 ( V_2 , 0x0005 , & V_4 ) ;
if ( F_7 ( V_5 ) )
goto V_20;
V_4 &= 0xc0 ;
V_4 |= 0x25 ;
V_5 = F_1 ( V_2 , 0x0005 , V_4 ) ;
if ( F_7 ( V_5 ) )
goto V_20;
V_5 = F_1 ( V_2 , 0x0006 , 0x64 ) ;
if ( F_7 ( V_5 ) )
goto V_20;
V_5 = F_5 ( V_2 , 0x000d , & V_4 ) ;
if ( F_7 ( V_5 ) )
goto V_20;
V_4 &= 0xc0 ;
V_4 |= 0x19 ;
V_5 = F_1 ( V_2 , 0x000d , V_4 ) ;
if ( F_7 ( V_5 ) )
goto V_20;
} else {
F_4 ( L_14 , V_2 -> V_10 -> V_51 ) ;
}
#if 0
ret = lgdt3306a_write_reg(state, 0x000e, 0x00);
ret = lgdt3306a_write_reg(state, 0x000f, 0x00);
#endif
V_5 = F_1 ( V_2 , 0x0010 , 0x34 ) ;
V_5 = F_1 ( V_2 , 0x0011 , 0x00 ) ;
V_5 = F_1 ( V_2 , 0x0014 , 0 ) ;
V_5 = F_5 ( V_2 , 0x103c , & V_4 ) ;
V_4 &= 0x0f ;
V_4 |= 0x20 ;
V_5 = F_1 ( V_2 , 0x103c , V_4 ) ;
V_5 = F_5 ( V_2 , 0x103d , & V_4 ) ;
V_4 &= 0xfc ;
V_4 |= 0x03 ;
V_5 = F_1 ( V_2 , 0x103d , V_4 ) ;
V_5 = F_5 ( V_2 , 0x1036 , & V_4 ) ;
V_4 &= 0xf0 ;
V_4 |= 0x0c ;
V_5 = F_1 ( V_2 , 0x1036 , V_4 ) ;
V_5 = F_5 ( V_2 , 0x211f , & V_4 ) ;
V_4 &= 0xef ;
V_5 = F_1 ( V_2 , 0x211f , V_4 ) ;
V_5 = F_5 ( V_2 , 0x2849 , & V_4 ) ;
V_4 &= 0xef ;
V_5 = F_1 ( V_2 , 0x2849 , V_4 ) ;
V_5 = F_18 ( V_2 ) ;
V_5 = F_11 ( V_2 , V_2 -> V_10 -> V_52 ) ;
V_5 = F_13 ( V_2 , 1 ) ;
V_5 = F_28 ( V_2 ) ;
F_7 ( V_5 ) ;
V_20:
return V_5 ;
}
static int F_31 ( struct V_29 * V_30 )
{
struct V_35 * V_36 = & V_30 -> V_53 ;
struct V_1 * V_2 = V_30 -> V_32 ;
int V_5 ;
F_9 ( L_15 , V_36 -> V_54 , V_36 -> V_33 ) ;
if ( V_2 -> V_50 == V_36 -> V_54 &&
V_2 -> V_40 == V_36 -> V_33 ) {
F_9 ( L_16 ) ;
return 0 ;
}
V_2 -> V_50 = - 1 ;
V_2 -> V_40 = - 1 ;
V_5 = F_15 ( V_2 , 1 ) ;
if ( F_7 ( V_5 ) )
goto V_20;
if ( V_30 -> V_55 . V_56 . V_57 ) {
V_5 = V_30 -> V_55 . V_56 . V_57 ( V_30 ) ;
if ( V_30 -> V_55 . V_58 )
V_30 -> V_55 . V_58 ( V_30 , 0 ) ;
#if 0
if (lg_chkerr(ret))
goto fail;
state->current_frequency = p->frequency;
#endif
}
V_5 = F_20 ( V_2 , V_36 ) ;
if ( F_7 ( V_5 ) )
goto V_20;
V_5 = F_21 ( V_2 , V_36 ) ;
if ( F_7 ( V_5 ) )
goto V_20;
V_5 = F_25 ( V_2 , V_36 ) ;
if ( F_7 ( V_5 ) )
goto V_20;
V_5 = F_24 ( V_2 , V_36 ,
V_2 -> V_10 -> V_59 ? 1 : 0 ) ;
if ( F_7 ( V_5 ) )
goto V_20;
V_5 = F_11 ( V_2 , V_2 -> V_10 -> V_52 ) ;
if ( F_7 ( V_5 ) )
goto V_20;
V_5 = F_12 ( V_2 ,
V_2 -> V_10 -> V_60 ,
V_2 -> V_10 -> V_61 ) ;
if ( F_7 ( V_5 ) )
goto V_20;
V_5 = F_13 ( V_2 , 0 ) ;
if ( F_7 ( V_5 ) )
goto V_20;
V_5 = F_8 ( V_2 ) ;
if ( F_7 ( V_5 ) )
goto V_20;
#ifdef F_16
F_17 ( V_2 ) ;
#endif
V_2 -> V_50 = V_36 -> V_54 ;
V_20:
return V_5 ;
}
static int F_32 ( struct V_29 * V_30 ,
struct V_35 * V_36 )
{
struct V_1 * V_2 = V_30 -> V_32 ;
F_9 ( L_17 ,
V_2 -> V_50 , V_2 -> V_40 ) ;
V_36 -> V_33 = V_2 -> V_40 ;
V_36 -> V_54 = V_2 -> V_50 ;
return 0 ;
}
static enum V_62 F_33 ( struct V_29 * V_30 )
{
#if 1
return V_63 ;
#else
return V_64 ;
#endif
}
static int F_34 ( struct V_1 * V_2 )
{
T_2 V_4 ;
int V_5 ;
T_2 V_65 , V_66 , V_67 ;
T_1 V_68 ;
V_5 = F_5 ( V_2 , 0x21a1 , & V_4 ) ;
if ( V_5 )
return V_5 ;
V_65 = V_4 & 0x3f ;
V_5 = F_5 ( V_2 , 0x2185 , & V_66 ) ;
if ( V_5 )
return V_5 ;
V_5 = F_5 ( V_2 , 0x2191 , & V_4 ) ;
if ( V_5 )
return V_5 ;
V_67 = ( V_4 & 0x80 ) >> 7 ;
V_5 = F_5 ( V_2 , 0x2180 , & V_4 ) ;
if ( V_5 )
return V_5 ;
V_68 = ( V_4 & 0x03 ) << 8 ;
V_5 = F_5 ( V_2 , 0x2181 , & V_4 ) ;
if ( V_5 )
return V_5 ;
V_68 |= V_4 ;
F_9 ( L_18 ,
V_65 , V_66 , V_67 , V_68 ) ;
V_5 = F_5 ( V_2 , 0x1061 , & V_4 ) ;
if ( V_5 )
return V_5 ;
V_4 &= 0xf8 ;
if ( ( V_65 > 18 ) && ( V_66 > 0x68 )
&& ( V_67 == 0x01 )
&& ( ( V_68 == 0x03FF ) || ( V_68 < 0x6C ) ) ) {
V_4 |= 0x00 ;
} else {
V_4 |= 0x04 ;
}
V_5 = F_1 ( V_2 , 0x1061 , V_4 ) ;
if ( V_5 )
return V_5 ;
V_5 = F_5 ( V_2 , 0x0024 , & V_4 ) ;
if ( V_5 )
return V_5 ;
V_4 &= 0x0f ;
if ( V_67 == 0 ) {
V_4 |= 0x50 ;
}
V_5 = F_1 ( V_2 , 0x0024 , V_4 ) ;
if ( V_5 )
return V_5 ;
V_5 = F_5 ( V_2 , 0x103d , & V_4 ) ;
if ( V_5 )
return V_5 ;
V_4 &= 0xcf ;
V_4 |= 0x20 ;
V_5 = F_1 ( V_2 , 0x103d , V_4 ) ;
return V_5 ;
}
static enum V_69
F_35 ( struct V_1 * V_2 )
{
T_2 V_4 = 0 ;
int V_5 ;
V_5 = F_5 ( V_2 , 0x0081 , & V_4 ) ;
if ( V_5 )
goto V_70;
if ( V_4 & 0x80 ) {
F_9 ( L_19 ) ;
return V_71 ;
}
if ( V_4 & 0x08 ) {
V_5 = F_5 ( V_2 , 0x00a6 , & V_4 ) ;
if ( V_5 )
goto V_70;
V_4 = V_4 >> 2 ;
if ( V_4 & 0x01 ) {
F_9 ( L_20 ) ;
return V_72 ;
}
F_9 ( L_21 ) ;
return V_73 ;
}
V_70:
F_26 ( L_22 ) ;
return V_74 ;
}
static enum V_75
F_36 ( struct V_1 * V_2 ,
enum V_76 V_77 )
{
T_2 V_4 = 0 ;
int V_5 ;
enum V_69 V_78 ;
enum V_75 V_79 ;
V_78 = V_74 ;
switch ( V_77 ) {
case V_80 :
{
V_5 = F_5 ( V_2 , 0x00a6 , & V_4 ) ;
if ( V_5 )
return V_5 ;
if ( ( V_4 & 0x80 ) == 0x80 )
V_79 = V_81 ;
else
V_79 = V_82 ;
F_9 ( L_23 , V_79 ) ;
break;
}
case V_83 :
{
V_5 = F_5 ( V_2 , 0x0080 , & V_4 ) ;
if ( V_5 )
return V_5 ;
if ( ( V_4 & 0x40 ) == 0x40 )
V_79 = V_81 ;
else
V_79 = V_82 ;
F_9 ( L_24 , V_79 ) ;
break;
}
case V_84 :
{
V_78 = F_35 ( V_2 ) ;
if ( ( V_78 == V_73 ) || ( V_78 == V_72 ) ) {
V_5 = F_5 ( V_2 , 0x1094 , & V_4 ) ;
if ( V_5 )
return V_5 ;
if ( ( V_4 & 0x80 ) == 0x80 )
V_79 = V_81 ;
else
V_79 = V_82 ;
} else
V_79 = V_85 ;
F_9 ( L_25 , V_79 ) ;
break;
}
case V_86 :
{
V_78 = F_35 ( V_2 ) ;
if ( ( V_78 == V_73 ) || ( V_78 == V_72 ) ) {
V_5 = F_5 ( V_2 , 0x0080 , & V_4 ) ;
if ( V_5 )
return V_5 ;
if ( ( V_4 & 0x10 ) == 0x10 )
V_79 = V_81 ;
else
V_79 = V_82 ;
} else
V_79 = V_85 ;
F_9 ( L_26 , V_79 ) ;
break;
}
default:
V_79 = V_85 ;
F_26 ( L_27 , V_77 ) ;
break;
}
return V_79 ;
}
static enum V_87
F_37 ( struct V_1 * V_2 )
{
T_2 V_4 = 0 ;
int V_5 ;
enum V_87 V_79 ;
V_5 = F_5 ( V_2 , 0x0080 , & V_4 ) ;
if ( V_5 )
return V_5 ;
V_79 = (enum V_87 ) ( V_4 & 0x03 ) ;
F_9 ( L_28 , V_79 ) ;
return V_79 ;
}
static int F_38 ( struct V_1 * V_2 )
{
T_2 V_4 = 0 ;
int V_5 ;
T_2 V_88 , V_65 , V_89 , V_90 ;
V_5 = F_5 ( V_2 , 0x21bc , & V_88 ) ;
if ( V_5 )
return V_5 ;
V_5 = F_5 ( V_2 , 0x21a1 , & V_4 ) ;
if ( V_5 )
return V_5 ;
V_65 = V_4 & 0x3f ;
V_5 = F_5 ( V_2 , 0x2199 , & V_4 ) ;
if ( V_5 )
return V_5 ;
V_89 = ( V_4 & 0x40 ) >> 6 ;
V_5 = F_5 ( V_2 , 0x0090 , & V_4 ) ;
if ( V_5 )
return V_5 ;
V_90 = ( V_4 & 0xf0 ) >> 4 ;
F_9 ( L_29 ,
V_65 , V_89 , V_90 , V_88 ) ;
#if 0
if ((mainStrong == 0) && (currChDiffACQ > 0x70))
#endif
if ( V_89 == 0 ) {
V_5 = F_5 ( V_2 , 0x2135 , & V_4 ) ;
if ( V_5 )
return V_5 ;
V_4 &= 0x0f ;
V_4 |= 0xa0 ;
V_5 = F_1 ( V_2 , 0x2135 , V_4 ) ;
if ( V_5 )
return V_5 ;
V_5 = F_5 ( V_2 , 0x2141 , & V_4 ) ;
if ( V_5 )
return V_5 ;
V_4 &= 0x3f ;
V_4 |= 0x80 ;
V_5 = F_1 ( V_2 , 0x2141 , V_4 ) ;
if ( V_5 )
return V_5 ;
V_5 = F_1 ( V_2 , 0x2122 , 0x70 ) ;
if ( V_5 )
return V_5 ;
} else {
V_5 = F_5 ( V_2 , 0x2135 , & V_4 ) ;
if ( V_5 )
return V_5 ;
V_4 &= 0x0f ;
V_4 |= 0x70 ;
V_5 = F_1 ( V_2 , 0x2135 , V_4 ) ;
if ( V_5 )
return V_5 ;
V_5 = F_5 ( V_2 , 0x2141 , & V_4 ) ;
if ( V_5 )
return V_5 ;
V_4 &= 0x3f ;
V_4 |= 0x40 ;
V_5 = F_1 ( V_2 , 0x2141 , V_4 ) ;
if ( V_5 )
return V_5 ;
V_5 = F_1 ( V_2 , 0x2122 , 0x40 ) ;
if ( V_5 )
return V_5 ;
}
return 0 ;
}
static enum V_75
F_39 ( struct V_1 * V_2 )
{
enum V_75 V_91 = V_82 ;
int V_92 ;
for ( V_92 = 0 ; V_92 < 2 ; V_92 ++ ) {
F_10 ( 30 ) ;
V_91 = F_36 ( V_2 ,
V_80 ) ;
if ( V_91 == V_81 ) {
F_9 ( L_30 , V_92 ) ;
return V_81 ;
}
}
F_9 ( L_31 ) ;
return V_82 ;
}
static enum V_75
F_40 ( struct V_1 * V_2 )
{
enum V_75 V_93 = V_82 ;
int V_92 ;
for ( V_92 = 0 ; V_92 < 2 ; V_92 ++ ) {
F_10 ( 30 ) ;
V_93 = F_36 ( V_2 ,
V_86 ) ;
if ( V_93 == V_81 ) {
F_9 ( L_30 , V_92 ) ;
return V_93 ;
}
}
F_9 ( L_31 ) ;
return V_93 ;
}
static enum V_87
F_41 ( struct V_1 * V_2 )
{
enum V_87 V_94 = V_95 ;
int V_92 ;
for ( V_92 = 0 ; V_92 < 5 ; V_92 ++ ) {
F_10 ( 30 ) ;
V_94 = F_37 ( V_2 ) ;
if ( V_94 == V_96 ) {
F_9 ( L_32 , V_92 ) ;
return V_94 ;
}
}
F_9 ( L_33 , V_94 ) ;
return V_94 ;
}
static T_2 F_42 ( struct V_1 * V_2 )
{
T_2 V_4 ;
int V_5 ;
V_5 = F_5 ( V_2 , 0x00fa , & V_4 ) ;
if ( V_5 )
return V_5 ;
return V_4 ;
}
static T_3 F_43 ( T_3 V_97 )
{
T_3 V_98 , V_99 , V_100 ;
T_3 V_101 = 0 ;
T_3 V_92 ;
if ( V_97 <= 0 )
return - 1000000 ;
if ( V_97 == 10 )
return 0 ;
if ( V_97 < 10 ) {
while ( V_97 < 10 ) {
V_97 = V_97 * 10 ;
V_101 -- ;
}
} else {
while ( V_97 >= 100 ) {
V_97 = V_97 / 10 ;
V_101 ++ ;
}
}
V_101 *= 1000 ;
if ( V_97 == 10 )
return V_101 ;
for ( V_92 = 1 ; V_92 < F_44 ( V_102 ) ; V_92 ++ ) {
if ( V_102 [ V_92 ] >= V_97 )
break;
}
if ( V_92 == F_44 ( V_102 ) )
return V_101 + V_103 [ V_92 - 1 ] ;
V_98 = V_97 - V_102 [ V_92 - 1 ] ;
V_99 = V_102 [ V_92 ] - V_102 [ V_92 - 1 ] ;
V_100 = V_103 [ V_92 ] - V_103 [ V_92 - 1 ] ;
return V_101 + V_103 [ V_92 - 1 ] +
( ( V_98 * V_100 ) / V_99 ) ;
}
static T_3 F_45 ( struct V_1 * V_2 )
{
T_3 V_104 ;
T_3 V_105 ;
T_3 V_106 ;
V_104 = ( F_46 ( V_2 , 0x00ec ) << 8 ) |
( F_46 ( V_2 , 0x00ed ) ) ;
V_105 = ( F_46 ( V_2 , 0x00e8 ) << 8 ) |
( F_46 ( V_2 , 0x00e9 ) ) ;
if ( V_104 == 0 )
return 0 ;
V_106 = F_43 ( ( V_105 * 10000 ) / V_104 ) - 3000 ;
F_9 ( L_34 , V_104 , V_105 , V_106 ) ;
return V_106 ;
}
static enum V_75
F_47 ( struct V_1 * V_2 )
{
int V_5 ;
T_2 V_107 = 0 ;
T_2 V_108 ;
T_3 V_109 ;
for ( V_107 = 0 ; V_107 < 10 ; V_107 ++ ) {
if ( F_39 ( V_2 ) == V_82 ) {
F_9 ( L_35 ) ;
return V_82 ;
}
F_10 ( 20 ) ;
V_5 = F_38 ( V_2 ) ;
if ( V_5 )
break;
V_108 = F_42 ( V_2 ) ;
V_109 = F_45 ( V_2 ) ;
F_9 ( L_36 , V_107 , V_108 , V_109 ) ;
if ( ( V_109 >= 1500 ) && ( V_108 < 0xff ) )
return V_81 ;
}
F_9 ( L_37 ) ;
return V_82 ;
}
static enum V_75
F_48 ( struct V_1 * V_2 )
{
T_2 V_107 ;
T_2 V_108 ;
T_3 V_109 ;
for ( V_107 = 0 ; V_107 < 10 ; V_107 ++ ) {
if ( F_40 ( V_2 ) == V_82 ) {
F_9 ( L_38 ) ;
return V_82 ;
}
F_10 ( 20 ) ;
V_108 = F_42 ( V_2 ) ;
V_109 = F_45 ( V_2 ) ;
F_9 ( L_36 , V_107 , V_108 , V_109 ) ;
if ( ( V_109 >= 1500 ) && ( V_108 < 0xff ) )
return V_81 ;
}
F_9 ( L_37 ) ;
return V_82 ;
}
static int F_49 ( struct V_29 * V_30 ,
enum V_110 * V_111 )
{
struct V_1 * V_2 = V_30 -> V_32 ;
T_1 V_112 = 0 ;
int V_5 = 0 ;
if ( V_30 -> V_55 . V_56 . V_113 ) {
V_5 = V_30 -> V_55 . V_56 . V_113 ( V_30 , & V_112 ) ;
if ( V_5 == 0 )
F_9 ( L_39 , V_112 ) ;
else
F_9 ( L_40 ) ;
}
* V_111 = 0 ;
if ( F_41 ( V_2 ) == V_96 ) {
* V_111 |= V_114 ;
* V_111 |= V_115 ;
switch ( V_2 -> V_40 ) {
case V_38 :
case V_34 :
if ( F_48 ( V_2 ) == V_81 ) {
* V_111 |= V_116 ;
* V_111 |= V_117 ;
* V_111 |= V_118 ;
}
break;
case V_37 :
if ( F_47 ( V_2 ) == V_81 ) {
* V_111 |= V_116 ;
* V_111 |= V_117 ;
* V_111 |= V_118 ;
V_5 = F_34 ( V_2 ) ;
}
break;
default:
V_5 = - V_39 ;
}
}
return V_5 ;
}
static int F_50 ( struct V_29 * V_30 , T_1 * V_109 )
{
struct V_1 * V_2 = V_30 -> V_32 ;
V_2 -> V_109 = F_45 ( V_2 ) ;
* V_109 = V_2 -> V_109 / 10 ;
return 0 ;
}
static int F_51 ( struct V_29 * V_30 ,
T_1 * V_112 )
{
struct V_1 * V_2 = V_30 -> V_32 ;
T_1 V_109 ;
int V_5 ;
T_3 V_119 ;
T_3 V_120 ;
* V_112 = 0 ;
switch ( V_2 -> V_40 ) {
case V_37 :
V_119 = 1600 ;
break;
case V_34 :
V_119 = 2200 ;
break;
case V_38 :
V_119 = 2800 ;
break;
default:
return - V_39 ;
}
V_5 = V_30 -> V_55 . V_121 ( V_30 , & V_109 ) ;
if ( F_7 ( V_5 ) )
goto V_20;
if ( V_2 -> V_109 <= ( V_119 - 100 ) )
V_120 = 0 ;
else if ( V_2 -> V_109 <= V_119 )
V_120 = ( 0xffff * 65 ) / 100 ;
else {
V_120 = V_2 -> V_109 - V_119 ;
V_120 /= 50 ;
V_120 += 78 ;
if ( V_120 > 100 )
V_120 = 100 ;
V_120 = ( 0xffff * V_120 ) / 100 ;
}
* V_112 = ( T_1 ) V_120 ;
F_9 ( L_41 , * V_112 ) ;
V_20:
return V_5 ;
}
static int F_52 ( struct V_29 * V_30 , T_3 * V_122 )
{
struct V_1 * V_2 = V_30 -> V_32 ;
T_3 V_123 ;
* V_122 = 0 ;
#if 1
V_123 = F_46 ( V_2 , 0x00fc ) ;
V_123 = ( V_123 << 8 ) | F_46 ( V_2 , 0x00fd ) ;
V_123 = ( V_123 << 8 ) | F_46 ( V_2 , 0x00fe ) ;
V_123 = ( V_123 << 8 ) | F_46 ( V_2 , 0x00ff ) ;
* V_122 = V_123 ;
F_9 ( L_42 , V_123 ) ;
#endif
return 0 ;
}
static int F_53 ( struct V_29 * V_30 , T_3 * V_124 )
{
struct V_1 * V_2 = V_30 -> V_32 ;
* V_124 = 0 ;
#if 1
* V_124 = F_46 ( V_2 , 0x00f4 ) ;
F_9 ( L_43 , * V_124 ) ;
#endif
return 0 ;
}
static int F_54 ( struct V_29 * V_30 , bool V_125 ,
unsigned int V_126 , unsigned int * V_127 ,
enum V_110 * V_111 )
{
int V_5 = 0 ;
struct V_1 * V_2 = V_30 -> V_32 ;
F_9 ( L_44 , V_125 ) ;
if ( V_125 ) {
V_2 -> V_50 = - 1 ;
V_5 = F_31 ( V_30 ) ;
if ( V_5 != 0 )
return V_5 ;
}
* V_127 = 125 ;
V_5 = F_49 ( V_30 , V_111 ) ;
return V_5 ;
}
static int F_55 ( struct V_29 * V_30 ,
struct V_128
* V_129 )
{
V_129 -> V_130 = 100 ;
F_9 ( L_5 ) ;
return 0 ;
}
static int F_56 ( struct V_29 * V_30 )
{
enum V_110 V_111 = 0 ;
int V_5 ;
V_5 = F_31 ( V_30 ) ;
if ( V_5 )
goto error;
V_5 = F_49 ( V_30 , & V_111 ) ;
if ( V_5 )
goto error;
if ( V_111 & V_118 )
return V_131 ;
else
return V_132 ;
error:
F_9 ( L_45 , V_5 ) ;
return V_133 ;
}
static void F_57 ( struct V_29 * V_30 )
{
struct V_1 * V_2 = V_30 -> V_32 ;
F_9 ( L_5 ) ;
F_58 ( V_2 ) ;
}
struct V_29 * F_59 ( const struct V_134 * V_135 ,
struct V_136 * V_14 )
{
struct V_1 * V_2 = NULL ;
int V_5 ;
T_2 V_4 ;
F_9 ( L_46 ,
V_14 ? F_60 ( V_14 ) : 0 ,
V_135 ? V_135 -> V_11 : 0 ) ;
V_2 = F_61 ( sizeof( struct V_1 ) , V_137 ) ;
if ( V_2 == NULL )
goto V_20;
V_2 -> V_10 = V_135 ;
V_2 -> V_14 = V_14 ;
memcpy ( & V_2 -> V_138 . V_55 , & V_139 ,
sizeof( struct V_140 ) ) ;
V_2 -> V_138 . V_32 = V_2 ;
V_5 = F_5 ( V_2 , 0x0000 , & V_4 ) ;
if ( F_7 ( V_5 ) )
goto V_20;
if ( ( V_4 & 0x74 ) != 0x74 ) {
F_26 ( L_47 , ( V_4 & 0x74 ) ) ;
#if 0
goto fail;
#endif
}
V_5 = F_5 ( V_2 , 0x0001 , & V_4 ) ;
if ( F_7 ( V_5 ) )
goto V_20;
if ( ( V_4 & 0xf6 ) != 0xc6 ) {
F_26 ( L_48 , ( V_4 & 0xf6 ) ) ;
#if 0
goto fail;
#endif
}
V_5 = F_5 ( V_2 , 0x0002 , & V_4 ) ;
if ( F_7 ( V_5 ) )
goto V_20;
if ( ( V_4 & 0x73 ) != 0x03 ) {
F_26 ( L_49 , ( V_4 & 0x73 ) ) ;
#if 0
goto fail;
#endif
}
V_2 -> V_50 = - 1 ;
V_2 -> V_40 = - 1 ;
F_28 ( V_2 ) ;
return & V_2 -> V_138 ;
V_20:
F_26 ( L_50 ) ;
F_58 ( V_2 ) ;
return NULL ;
}
static void F_17 ( struct V_1 * V_2 )
{
memset ( V_141 , 0xff , sizeof( V_141 ) ) ;
F_62 ( V_2 ) ;
}
static void F_62 ( struct V_1 * V_2 )
{
int V_92 ;
int V_142 = V_143 ;
if ( ( V_143 & F_16 ) == 0 )
return;
V_143 &= ~ V_144 ;
F_63 ( L_5 ) ;
for ( V_92 = 0 ; V_92 < V_145 ; V_92 ++ ) {
F_5 ( V_2 , V_146 [ V_92 ] , & V_147 [ V_92 ] ) ;
if ( V_147 [ V_92 ] != V_141 [ V_92 ] ) {
F_63 ( L_51 , V_146 [ V_92 ] , V_147 [ V_92 ] ) ;
V_141 [ V_92 ] = V_147 [ V_92 ] ;
}
}
V_143 = V_142 ;
}
static int F_64 ( struct V_148 * V_149 , T_3 V_150 )
{
struct V_151 * V_152 = F_65 ( V_149 ) ;
struct V_1 * V_2 = F_66 ( V_152 ) ;
return F_27 ( & V_2 -> V_138 , 1 ) ;
}
static int F_67 ( struct V_148 * V_149 , T_3 V_150 )
{
struct V_151 * V_152 = F_65 ( V_149 ) ;
struct V_1 * V_2 = F_66 ( V_152 ) ;
return F_27 ( & V_2 -> V_138 , 0 ) ;
}
static int F_68 ( struct V_151 * V_152 ,
const struct V_153 * V_154 )
{
struct V_134 * V_135 ;
struct V_1 * V_2 ;
struct V_29 * V_30 ;
int V_5 ;
V_135 = F_61 ( sizeof( struct V_134 ) , V_137 ) ;
if ( V_135 == NULL ) {
V_5 = - V_155 ;
goto V_20;
}
memcpy ( V_135 , V_152 -> V_156 . V_157 ,
sizeof( struct V_134 ) ) ;
V_135 -> V_11 = V_152 -> V_9 ;
V_30 = F_59 ( V_135 , V_152 -> V_158 ) ;
if ( V_30 == NULL ) {
V_5 = - V_159 ;
goto V_160;
}
F_69 ( V_152 , V_30 -> V_32 ) ;
V_2 = V_30 -> V_32 ;
V_2 -> V_149 = F_70 ( V_152 -> V_158 , & V_152 -> V_156 ,
1 , 0 , V_161 ,
F_64 , F_67 ) ;
if ( ! V_2 -> V_149 ) {
V_5 = - V_155 ;
goto V_162;
}
V_2 -> V_149 -> V_163 = V_152 ;
V_5 = F_71 ( V_2 -> V_149 , 0 , 0 , 0 ) ;
if ( V_5 )
goto V_162;
V_30 -> V_55 . V_58 = NULL ;
* V_135 -> V_136 = V_2 -> V_149 -> V_158 [ 0 ] ;
* V_135 -> V_30 = V_30 ;
return 0 ;
V_162:
F_58 ( V_2 ) ;
V_160:
F_58 ( V_135 ) ;
V_20:
F_72 ( & V_152 -> V_156 , L_52 , V_5 ) ;
return V_5 ;
}
static int F_73 ( struct V_151 * V_152 )
{
struct V_1 * V_2 = F_66 ( V_152 ) ;
F_74 ( V_2 -> V_149 ) ;
V_2 -> V_138 . V_55 . V_164 = NULL ;
V_2 -> V_138 . V_32 = NULL ;
F_58 ( V_2 -> V_10 ) ;
F_58 ( V_2 ) ;
return 0 ;
}
