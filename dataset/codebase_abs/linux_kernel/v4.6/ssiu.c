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
F_6 ( V_2 , V_16 , ( 1 << V_11 ) , ! V_10 << V_11 ) ;
V_12 = ( 1 << 4 ) | ( 1 << 20 ) ;
V_14 = ( 1 << 4 ) ;
V_13 = V_15 = 0 ;
if ( F_7 ( V_4 ) ) {
int V_17 = - 1 ;
switch ( V_11 ) {
case 1 :
V_17 = 0 ;
break;
case 2 :
V_17 = 2 ;
break;
case 4 :
V_17 = 16 ;
break;
default:
return - V_18 ;
}
V_12 |= 0x3 << V_17 ;
V_13 = F_8 ( V_8 ) ?
0x2 << V_17 : 0x1 << V_17 ;
} else if ( V_9 ) {
V_14 |= 0x00000007 ;
V_12 |= 0x0000000f ;
switch ( V_9 ) {
case 0x0206 :
V_15 = ( 1 << 4 ) |
( F_8 ( V_8 ) ? 0x2 : 0x1 ) ;
case 0x0006 :
V_13 = F_8 ( V_8 ) ?
0xa : 0x5 ;
if ( ! V_15 )
V_13 |= ( 1 << 4 ) ;
}
}
F_6 ( V_2 , V_19 , V_12 , V_13 ) ;
F_6 ( V_2 , V_20 , V_14 , V_15 ) ;
return 0 ;
}
static int F_9 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 )
{
int V_21 ;
V_21 = F_1 ( V_2 , V_4 , V_6 ) ;
if ( V_21 < 0 )
return V_21 ;
if ( F_10 ( V_4 ) ) {
F_11 ( V_2 , V_22 , 0x1 ) ;
}
if ( F_4 ( V_4 ) ) {
F_11 ( V_2 , V_23 ,
F_12 ( V_2 , V_4 ) |
( F_13 ( V_4 ) ?
F_14 ( V_4 ) :
F_15 ( V_4 ) ) ) ;
F_11 ( V_2 , V_24 , 1 ) ;
F_11 ( V_2 , V_25 ,
F_16 ( V_2 , V_4 ) ) ;
}
return 0 ;
}
static int F_17 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 )
{
if ( ! F_4 ( V_4 ) )
return 0 ;
F_11 ( V_2 , V_26 , 0x1 ) ;
if ( F_3 ( V_4 ) )
F_11 ( V_2 , V_27 , 0x1 ) ;
return 0 ;
}
static int F_18 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 )
{
if ( ! F_4 ( V_4 ) )
return 0 ;
F_11 ( V_2 , V_26 , 0 ) ;
if ( F_3 ( V_4 ) )
F_11 ( V_2 , V_27 , 0 ) ;
return 0 ;
}
static struct V_1 * F_19 ( struct V_5 * V_6 , int V_11 )
{
if ( F_20 ( V_11 < 0 || V_11 >= F_21 ( V_6 ) ) )
V_11 = 0 ;
return F_22 ( (struct V_28 * ) ( V_6 -> V_29 ) + V_11 ) ;
}
int F_23 ( struct V_3 * V_4 ,
struct V_1 * V_30 )
{
struct V_5 * V_6 = F_24 ( V_4 ) ;
struct V_1 * V_2 = F_19 ( V_6 , F_5 ( V_30 ) ) ;
F_25 ( V_30 ) ;
return F_26 ( V_2 , V_4 , V_2 -> type ) ;
}
int F_27 ( struct V_5 * V_6 )
{
struct V_31 * V_32 = F_28 ( V_6 ) ;
struct V_28 * V_29 ;
static struct V_33 * V_34 ;
int V_35 , V_36 , V_21 ;
V_36 = V_6 -> V_37 ;
V_29 = F_29 ( V_32 , sizeof( * V_29 ) * V_36 , V_38 ) ;
if ( ! V_29 )
return - V_39 ;
V_6 -> V_29 = V_29 ;
V_6 -> V_40 = V_36 ;
if ( F_30 ( V_6 ) )
V_34 = & V_41 ;
else
V_34 = & V_42 ;
F_31 (ssiu, priv, i) {
V_21 = F_32 ( V_6 , F_22 ( V_29 ) ,
V_34 , NULL , V_43 ,
V_44 , V_35 ) ;
if ( V_21 )
return V_21 ;
}
return 0 ;
}
void F_33 ( struct V_5 * V_6 )
{
struct V_28 * V_29 ;
int V_35 ;
F_31 (ssiu, priv, i) {
F_34 ( F_22 ( V_29 ) ) ;
}
}
