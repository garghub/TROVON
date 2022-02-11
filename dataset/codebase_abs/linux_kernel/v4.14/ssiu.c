static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 )
{
struct V_7 * V_8 = F_2 ( V_4 ) ;
T_1 V_9 = F_3 ( V_4 ) ;
int V_10 = F_4 ( V_4 ) ;
int V_11 = F_5 ( V_2 ) ;
T_1 V_12 , V_13 ;
T_1 V_14 , V_15 ;
switch ( V_11 ) {
case 0 :
case 1 :
case 2 :
case 3 :
case 4 :
F_6 ( V_2 , V_16 , 0xf << ( V_11 * 4 ) ) ;
F_6 ( V_2 , V_17 , 0xf << ( V_11 * 4 ) ) ;
F_6 ( V_2 , V_18 , 0xf << ( V_11 * 4 ) ) ;
F_6 ( V_2 , V_19 , 0xf << ( V_11 * 4 ) ) ;
break;
case 9 :
F_6 ( V_2 , V_20 , 0xf << 4 ) ;
F_6 ( V_2 , V_21 , 0xf << 4 ) ;
F_6 ( V_2 , V_22 , 0xf << 4 ) ;
F_6 ( V_2 , V_23 , 0xf << 4 ) ;
break;
}
F_7 ( V_2 , V_24 , ( 1 << V_11 ) , ! V_10 << V_11 ) ;
V_12 = ( 1 << 4 ) | ( 1 << 20 ) ;
V_14 = ( 1 << 4 ) ;
V_13 = V_15 = 0 ;
if ( V_11 == 8 ) {
} else if ( F_8 ( V_4 ) ) {
int V_25 = - 1 ;
switch ( V_11 ) {
case 1 :
V_25 = 0 ;
break;
case 2 :
V_25 = 2 ;
break;
case 4 :
V_25 = 16 ;
break;
default:
return - V_26 ;
}
V_12 |= 0x3 << V_25 ;
V_13 = F_9 ( V_8 ) ?
0x2 << V_25 : 0x1 << V_25 ;
} else if ( V_9 ) {
V_14 |= 0x00000007 ;
V_12 |= 0x0000000f ;
switch ( V_9 ) {
case 0x0206 :
V_15 = ( 1 << 4 ) |
( F_9 ( V_8 ) ? 0x2 : 0x1 ) ;
case 0x0006 :
V_13 = F_9 ( V_8 ) ?
0xa : 0x5 ;
if ( ! V_15 )
V_13 |= ( 1 << 4 ) ;
}
}
F_7 ( V_2 , V_27 , V_12 , V_13 ) ;
F_7 ( V_2 , V_28 , V_14 , V_15 ) ;
return 0 ;
}
static int F_10 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 )
{
int V_29 = F_11 ( V_4 ) ;
int V_30 ;
V_30 = F_1 ( V_2 , V_4 , V_6 ) ;
if ( V_30 < 0 )
return V_30 ;
if ( F_12 ( V_4 ) ) {
F_6 ( V_2 , V_31 , 0x1 ) ;
}
if ( F_4 ( V_4 ) ) {
F_6 ( V_2 , V_32 ,
F_13 ( V_2 , V_4 ) |
( F_14 ( V_4 ) ?
F_15 ( V_4 ) :
F_16 ( V_4 ) ) ) ;
F_6 ( V_2 , V_33 ,
F_17 ( V_4 , V_2 ) | 1 ) ;
F_6 ( V_2 , V_34 ,
F_18 ( V_2 , V_4 ) ) ;
}
if ( V_29 ) {
enum V_35 V_36 [] = {
V_37 ,
V_38 ,
V_39 ,
} ;
struct V_1 * V_40 = F_19 ( V_4 ) ;
struct V_1 * V_41 ;
T_1 V_42 ;
int V_43 , V_25 ;
V_43 = F_5 ( V_40 ) ;
V_42 = V_43 << 16 |
V_43 << 20 |
V_43 << 24 |
V_43 << 28 |
V_43 ;
F_20 (i, pos, io, rsnd_ssi_array) {
V_25 = ( V_43 * 4 ) + 16 ;
V_42 = ( V_42 & ~ ( 0xF << V_25 ) ) |
F_5 ( V_41 ) << V_25 ;
}
switch ( V_29 ) {
case V_44 :
F_6 ( V_2 , V_45 , V_42 ) ;
break;
case V_46 :
F_6 ( V_2 , V_47 , V_42 ) ;
break;
}
}
return 0 ;
}
static int F_21 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 )
{
if ( ! F_4 ( V_4 ) )
return 0 ;
F_6 ( V_2 , V_48 , 0x1 ) ;
if ( F_3 ( V_4 ) )
F_6 ( V_2 , V_49 , 0x1 ) ;
return 0 ;
}
static int F_22 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 )
{
if ( ! F_4 ( V_4 ) )
return 0 ;
F_6 ( V_2 , V_48 , 0 ) ;
if ( F_3 ( V_4 ) )
F_6 ( V_2 , V_49 , 0 ) ;
return 0 ;
}
static struct V_1 * F_23 ( struct V_5 * V_6 , int V_11 )
{
if ( F_24 ( V_11 < 0 || V_11 >= F_25 ( V_6 ) ) )
V_11 = 0 ;
return F_26 ( (struct V_50 * ) ( V_6 -> V_51 ) + V_11 ) ;
}
int F_27 ( struct V_3 * V_4 ,
struct V_1 * V_40 )
{
struct V_5 * V_6 = F_28 ( V_4 ) ;
struct V_1 * V_2 = F_23 ( V_6 , F_5 ( V_40 ) ) ;
F_29 ( V_40 ) ;
return F_30 ( V_2 , V_4 , V_2 -> type ) ;
}
int F_31 ( struct V_5 * V_6 )
{
struct V_52 * V_53 = F_32 ( V_6 ) ;
struct V_50 * V_51 ;
struct V_54 * V_55 ;
int V_43 , V_56 , V_30 ;
V_56 = V_6 -> V_57 ;
V_51 = F_33 ( V_53 , sizeof( * V_51 ) * V_56 , V_58 ) ;
if ( ! V_51 )
return - V_59 ;
V_6 -> V_51 = V_51 ;
V_6 -> V_60 = V_56 ;
if ( F_34 ( V_6 ) )
V_55 = & V_61 ;
else
V_55 = & V_62 ;
F_35 (ssiu, priv, i) {
V_30 = F_36 ( V_6 , F_26 ( V_51 ) ,
V_55 , NULL , V_63 ,
V_64 , V_43 ) ;
if ( V_30 )
return V_30 ;
}
return 0 ;
}
void F_37 ( struct V_5 * V_6 )
{
struct V_50 * V_51 ;
int V_43 ;
F_35 (ssiu, priv, i) {
F_38 ( F_26 ( V_51 ) ) ;
}
}
