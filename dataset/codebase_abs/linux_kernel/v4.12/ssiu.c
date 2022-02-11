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
int V_29 ;
V_29 = F_1 ( V_2 , V_4 , V_6 ) ;
if ( V_29 < 0 )
return V_29 ;
if ( F_11 ( V_4 ) ) {
F_6 ( V_2 , V_30 , 0x1 ) ;
}
if ( F_4 ( V_4 ) ) {
F_6 ( V_2 , V_31 ,
F_12 ( V_2 , V_4 ) |
( F_13 ( V_4 ) ?
F_14 ( V_4 ) :
F_15 ( V_4 ) ) ) ;
F_6 ( V_2 , V_32 ,
F_16 ( V_4 , V_2 ) | 1 ) ;
F_6 ( V_2 , V_33 ,
F_17 ( V_2 , V_4 ) ) ;
}
return 0 ;
}
static int F_18 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 )
{
if ( ! F_4 ( V_4 ) )
return 0 ;
F_6 ( V_2 , V_34 , 0x1 ) ;
if ( F_3 ( V_4 ) )
F_6 ( V_2 , V_35 , 0x1 ) ;
return 0 ;
}
static int F_19 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 )
{
if ( ! F_4 ( V_4 ) )
return 0 ;
F_6 ( V_2 , V_34 , 0 ) ;
if ( F_3 ( V_4 ) )
F_6 ( V_2 , V_35 , 0 ) ;
return 0 ;
}
static struct V_1 * F_20 ( struct V_5 * V_6 , int V_11 )
{
if ( F_21 ( V_11 < 0 || V_11 >= F_22 ( V_6 ) ) )
V_11 = 0 ;
return F_23 ( (struct V_36 * ) ( V_6 -> V_37 ) + V_11 ) ;
}
int F_24 ( struct V_3 * V_4 ,
struct V_1 * V_38 )
{
struct V_5 * V_6 = F_25 ( V_4 ) ;
struct V_1 * V_2 = F_20 ( V_6 , F_5 ( V_38 ) ) ;
F_26 ( V_38 ) ;
return F_27 ( V_2 , V_4 , V_2 -> type ) ;
}
int F_28 ( struct V_5 * V_6 )
{
struct V_39 * V_40 = F_29 ( V_6 ) ;
struct V_36 * V_37 ;
static struct V_41 * V_42 ;
int V_43 , V_44 , V_29 ;
V_44 = V_6 -> V_45 ;
V_37 = F_30 ( V_40 , sizeof( * V_37 ) * V_44 , V_46 ) ;
if ( ! V_37 )
return - V_47 ;
V_6 -> V_37 = V_37 ;
V_6 -> V_48 = V_44 ;
if ( F_31 ( V_6 ) )
V_42 = & V_49 ;
else
V_42 = & V_50 ;
F_32 (ssiu, priv, i) {
V_29 = F_33 ( V_6 , F_23 ( V_37 ) ,
V_42 , NULL , V_51 ,
V_52 , V_43 ) ;
if ( V_29 )
return V_29 ;
}
return 0 ;
}
void F_34 ( struct V_5 * V_6 )
{
struct V_36 * V_37 ;
int V_43 ;
F_32 (ssiu, priv, i) {
F_35 ( F_23 ( V_37 ) ) ;
}
}
