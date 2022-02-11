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
struct V_13 * V_14 = F_2 ( V_4 ) ;
T_1 V_10 ;
T_1 V_15 ;
int V_11 ;
int V_16 ;
if ( ! F_3 ( V_2 ) )
return 0 ;
V_16 = F_4 ( V_4 ) ;
if ( V_16 < 0 || V_16 >= F_5 ( V_12 ) )
return - V_17 ;
V_15 = F_6 ( V_6 , V_8 ) ? 0x1 : 0x2 ;
V_15 = V_15 << V_12 [ V_16 ] . V_11 ;
V_10 = V_12 [ V_16 ] . V_10 << V_12 [ V_16 ] . V_11 ;
F_7 ( V_4 , V_18 , V_10 , V_15 ) ;
V_11 = ( V_16 % 4 ) * 8 ;
V_10 = 0x1F << V_11 ;
if ( F_8 ( V_14 ) )
V_15 = 0 ;
else if ( 8 == V_16 )
V_15 = V_16 << V_11 ;
else
V_15 = ( V_16 + 1 ) << V_11 ;
switch ( V_16 / 4 ) {
case 0 :
F_7 ( V_4 , V_19 , V_10 , V_15 ) ;
break;
case 1 :
F_7 ( V_4 , V_20 , V_10 , V_15 ) ;
break;
case 2 :
F_7 ( V_4 , V_21 , V_10 , V_15 ) ;
break;
}
return 0 ;
}
unsigned int F_9 ( struct V_1 * V_2 ,
struct V_3 * V_22 ,
struct V_23 * V_24 )
{
struct V_13 * V_14 ;
unsigned int V_25 ;
V_14 = F_2 ( F_10 ( V_2 , F_4 ( V_22 ) ) ) ;
V_25 = F_8 ( V_14 ) ;
if ( ! V_25 )
V_25 = V_24 -> V_25 ;
return V_25 ;
}
static int F_11 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
struct V_7 * V_8 )
{
struct V_23 * V_24 = F_12 ( V_8 ) ;
struct V_13 * V_14 = F_2 ( V_4 ) ;
T_1 V_26 = F_8 ( V_14 ) ;
T_1 V_27 = V_24 -> V_28 ;
F_13 ( V_4 , V_29 , 0 ) ;
F_13 ( V_4 , V_29 , 1 ) ;
F_13 ( V_4 , V_30 , 1 ) ;
switch ( V_24 -> V_31 ) {
case 16 :
V_27 |= V_32 ;
break;
case 32 :
V_27 |= V_33 ;
break;
default:
return - V_17 ;
}
F_13 ( V_4 , V_34 , V_27 ) ;
if ( V_26 ) {
T_1 V_35 = 0x0400000 / V_26 * V_24 -> V_25 ;
int V_36 ;
F_13 ( V_4 , V_37 , 1 ) ;
F_13 ( V_4 , V_38 , V_35 ) ;
F_13 ( V_4 , V_39 , 0x00010110 ) ;
F_13 ( V_4 , V_40 , V_35 / 100 * 98 ) ;
if ( F_3 ( V_2 ) ) {
}
V_36 = F_14 ( V_2 , V_4 ,
V_24 -> V_25 ,
V_26 ) ;
if ( V_36 < 0 )
return V_36 ;
}
F_13 ( V_4 , V_30 , 0 ) ;
F_13 ( V_4 , V_41 , 1 ) ;
return 0 ;
}
static int F_15 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
struct V_7 * V_8 )
{
struct V_13 * V_14 = F_2 ( V_4 ) ;
int V_16 = F_4 ( V_4 ) ;
T_1 V_15 ;
if ( F_3 ( V_2 ) ) {
V_15 = ( 1 << V_16 ) ;
F_7 ( V_4 , V_42 , V_15 , V_15 ) ;
}
if ( F_8 ( V_14 ) )
F_13 ( V_4 , V_43 , 1 ) ;
return 0 ;
}
static int F_16 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
struct V_7 * V_8 )
{
struct V_13 * V_14 = F_2 ( V_4 ) ;
int V_16 = F_4 ( V_4 ) ;
T_1 V_10 ;
if ( F_3 ( V_2 ) ) {
V_10 = ( 1 << V_16 ) ;
F_7 ( V_4 , V_42 , V_10 , 0 ) ;
}
if ( F_8 ( V_14 ) )
F_13 ( V_4 , V_43 , 0 ) ;
return 0 ;
}
bool F_17 ( struct V_3 * V_4 )
{
struct V_13 * V_14 = F_2 ( V_4 ) ;
T_1 V_44 = F_18 ( V_14 ) ;
return ! ! ( V_44 & V_45 ) ;
}
static int F_19 ( struct V_3 * V_4 ,
struct V_5 * V_6 ,
struct V_7 * V_8 )
{
struct V_1 * V_2 = F_20 ( V_4 ) ;
struct V_13 * V_14 = F_2 ( V_4 ) ;
struct V_46 * V_47 = F_21 ( V_2 ) ;
int V_36 ;
if ( ! F_17 ( V_4 ) ) {
F_22 ( V_47 , L_1 ,
F_23 ( V_4 ) , F_4 ( V_4 ) ) ;
return 0 ;
}
F_24 ( V_14 -> V_48 ) ;
V_36 = F_1 ( V_2 , V_4 , V_6 , V_8 ) ;
if ( V_36 < 0 )
return V_36 ;
V_36 = F_11 ( V_2 , V_4 , V_6 , V_8 ) ;
if ( V_36 < 0 )
return V_36 ;
V_36 = F_15 ( V_2 , V_4 , V_6 , V_8 ) ;
if ( V_36 < 0 )
return V_36 ;
F_22 ( V_47 , L_2 , F_23 ( V_4 ) , F_4 ( V_4 ) ) ;
return 0 ;
}
static int F_25 ( struct V_3 * V_4 ,
struct V_5 * V_6 ,
struct V_7 * V_8 )
{
struct V_1 * V_2 = F_20 ( V_4 ) ;
struct V_13 * V_14 = F_2 ( V_4 ) ;
if ( ! F_17 ( V_4 ) )
return 0 ;
F_16 ( V_2 , V_4 , V_6 , V_8 ) ;
F_26 ( V_14 -> V_48 ) ;
return 0 ;
}
struct V_3 * F_10 ( struct V_1 * V_2 , int V_16 )
{
if ( F_27 ( V_16 < 0 || V_16 >= F_28 ( V_2 ) ) )
V_16 = 0 ;
return & ( (struct V_13 * ) ( V_2 -> V_14 ) + V_16 ) -> V_4 ;
}
int F_29 ( struct V_49 * V_50 ,
struct V_51 * V_52 ,
struct V_1 * V_2 )
{
struct V_46 * V_47 = F_21 ( V_2 ) ;
struct V_13 * V_14 ;
struct V_48 * V_48 ;
char V_53 [ V_54 ] ;
int V_55 , V_56 ;
V_56 = V_52 -> V_57 ;
V_14 = F_30 ( V_47 , sizeof( * V_14 ) * V_56 , V_58 ) ;
if ( ! V_14 ) {
F_31 ( V_47 , L_3 ) ;
return - V_59 ;
}
V_2 -> V_60 = V_56 ;
V_2 -> V_14 = V_14 ;
F_32 (scu, priv, i) {
snprintf ( V_53 , V_54 , L_4 , V_55 ) ;
V_48 = F_33 ( V_47 , V_53 ) ;
if ( F_34 ( V_48 ) )
return F_35 ( V_48 ) ;
F_36 ( V_2 , & V_14 -> V_4 ,
& V_61 , V_55 ) ;
V_14 -> V_52 = & V_52 -> V_62 [ V_55 ] ;
V_14 -> V_48 = V_48 ;
F_22 ( V_47 , L_5 , V_55 ) ;
}
F_22 ( V_47 , L_6 ) ;
return 0 ;
}
void F_37 ( struct V_49 * V_50 ,
struct V_1 * V_2 )
{
}
