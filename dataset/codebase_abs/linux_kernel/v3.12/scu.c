static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
struct V_7 * V_8 )
{
struct V_9 {
T_1 V_10 ;
int V_11 ;
} V_12 [] = {
{ 0xF , 0 , } ,
{ 0xF , 4 , } ,
{ 0xF , 8 , } ,
{ 0x7 , 12 , } ,
{ 0x7 , 16 , } ,
{ 0x7 , 20 , } ,
{ 0x7 , 24 , } ,
{ 0x3 , 28 , } ,
{ 0x3 , 30 , } ,
} ;
T_1 V_10 ;
T_1 V_13 ;
int V_11 ;
int V_14 ;
if ( ! F_2 ( V_2 ) )
return 0 ;
V_14 = F_3 ( V_4 ) ;
if ( V_14 < 0 || V_14 > F_4 ( V_12 ) )
return - V_15 ;
V_13 = F_5 ( V_6 , V_8 ) ? 0x1 : 0x2 ;
V_13 = V_13 << V_12 [ V_14 ] . V_11 ;
V_10 = V_12 [ V_14 ] . V_10 << V_12 [ V_14 ] . V_11 ;
F_6 ( V_4 , V_16 , V_10 , V_13 ) ;
V_11 = ( V_14 % 4 ) * 8 ;
V_10 = 0x1F << V_11 ;
if ( 8 == V_14 )
V_13 = V_14 << V_11 ;
else
V_13 = ( V_14 + 1 ) << V_11 ;
switch ( V_14 / 4 ) {
case 0 :
F_6 ( V_4 , V_17 , V_10 , V_13 ) ;
break;
case 1 :
F_6 ( V_4 , V_18 , V_10 , V_13 ) ;
break;
case 2 :
F_6 ( V_4 , V_19 , V_10 , V_13 ) ;
break;
}
return 0 ;
}
static int F_7 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
struct V_7 * V_8 )
{
int V_14 = F_3 ( V_4 ) ;
T_1 V_13 ;
if ( F_2 ( V_2 ) ) {
V_13 = ( 1 << V_14 ) ;
F_6 ( V_4 , V_20 , V_13 , V_13 ) ;
}
return 0 ;
}
static int F_8 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
struct V_7 * V_8 )
{
struct V_21 * V_22 = F_9 ( V_8 ) ;
T_1 V_23 = V_22 -> V_24 ;
switch ( V_22 -> V_25 ) {
case 16 :
V_23 |= V_26 ;
break;
case 32 :
V_23 |= V_27 ;
break;
default:
return - V_15 ;
}
F_10 ( V_4 , V_28 , 1 ) ;
F_10 ( V_4 , V_29 , V_23 ) ;
return 0 ;
}
static int F_11 ( struct V_3 * V_4 ,
struct V_5 * V_6 ,
struct V_7 * V_8 )
{
struct V_1 * V_2 = F_12 ( V_4 ) ;
struct V_30 * V_31 = F_13 ( V_4 ) ;
struct V_32 * V_33 = F_14 ( V_2 ) ;
T_1 V_34 = F_15 ( V_31 ) ;
int V_35 ;
if ( ! ( V_34 & V_36 ) ) {
F_16 ( V_33 , L_1 ,
F_17 ( V_4 ) , F_3 ( V_4 ) ) ;
return 0 ;
}
V_35 = F_1 ( V_2 , V_4 , V_6 , V_8 ) ;
if ( V_35 < 0 )
return V_35 ;
V_35 = F_7 ( V_2 , V_4 , V_6 , V_8 ) ;
if ( V_35 < 0 )
return V_35 ;
V_35 = F_8 ( V_2 , V_4 , V_6 , V_8 ) ;
if ( V_35 < 0 )
return V_35 ;
F_16 ( V_33 , L_2 , F_17 ( V_4 ) , F_3 ( V_4 ) ) ;
return 0 ;
}
struct V_3 * F_18 ( struct V_1 * V_2 , int V_14 )
{
F_19 ( V_14 < 0 || V_14 >= F_20 ( V_2 ) ) ;
return & ( (struct V_30 * ) ( V_2 -> V_31 ) + V_14 ) -> V_4 ;
}
int F_21 ( struct V_37 * V_38 ,
struct V_39 * V_40 ,
struct V_1 * V_2 )
{
struct V_32 * V_33 = F_14 ( V_2 ) ;
struct V_30 * V_31 ;
int V_41 , V_42 ;
V_42 = V_40 -> V_43 ;
V_31 = F_22 ( V_33 , sizeof( * V_31 ) * V_42 , V_44 ) ;
if ( ! V_31 ) {
F_23 ( V_33 , L_3 ) ;
return - V_45 ;
}
V_2 -> V_46 = V_42 ;
V_2 -> V_31 = V_31 ;
F_24 (scu, priv, i) {
F_25 ( V_2 , & V_31 -> V_4 ,
& V_47 , V_41 ) ;
V_31 -> V_40 = & V_40 -> V_48 [ V_41 ] ;
F_16 ( V_33 , L_4 , V_41 ) ;
}
F_16 ( V_33 , L_5 ) ;
return 0 ;
}
void F_26 ( struct V_37 * V_38 ,
struct V_1 * V_2 )
{
}
