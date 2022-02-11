int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
int V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = F_3 ( V_7 ) ;
int V_10 = F_4 ( V_2 ) ;
F_5 ( V_2 , V_11 , ( 1 << V_10 ) ,
! V_5 << V_10 ) ;
if ( F_6 ( V_2 ) ) {
int V_12 = - 1 ;
switch ( V_10 ) {
case 1 :
V_12 = 0 ;
break;
case 2 :
V_12 = 2 ;
break;
case 4 :
V_12 = 16 ;
break;
}
if ( V_12 >= 0 )
F_5 ( V_2 , V_13 ,
0x3 << V_12 ,
F_7 ( V_4 ) ?
0x2 << V_12 : 0x1 << V_12 ) ;
}
if ( V_5 ) {
T_1 V_14 = 0x76543210 ;
T_1 V_15 = ~ 0 ;
F_8 ( V_2 , V_16 ,
F_9 ( V_2 ) ) ;
F_8 ( V_2 , V_17 , 1 ) ;
F_8 ( V_2 , V_18 , 0x1 ) ;
V_15 <<= V_9 -> V_19 * 4 ;
V_14 = V_14 & V_15 ;
switch ( V_9 -> V_20 ) {
case 16 :
V_14 |= 0x67452301 & ~ V_15 ;
break;
case 32 :
V_14 |= 0x76543210 & ~ V_15 ;
break;
}
F_8 ( V_2 , V_21 , V_14 ) ;
}
return 0 ;
}
int F_10 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
F_8 ( V_2 , V_18 , 0 ) ;
return 0 ;
}
int F_11 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_22 * V_23 = F_12 ( V_2 ) ;
if ( F_13 ( V_23 ) )
return 0 ;
if ( F_14 ( V_2 ) )
F_8 ( V_2 , V_24 , 0x0e000000 ) ;
else
F_8 ( V_2 , V_24 , 0x0f000000 ) ;
return 0 ;
}
int F_15 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_22 * V_23 = F_12 ( V_2 ) ;
if ( F_13 ( V_23 ) )
return 0 ;
F_8 ( V_2 , V_24 , 0x00000000 ) ;
return 0 ;
}
unsigned int F_16 ( struct V_22 * V_23 ,
struct V_6 * V_7 ,
struct V_8 * V_9 )
{
struct V_1 * V_25 = F_17 ( V_7 ) ;
struct V_26 * V_27 ;
unsigned int V_28 = 0 ;
if ( V_25 ) {
V_27 = F_18 ( V_25 ) ;
V_28 = F_19 ( V_27 ) ;
}
if ( ! V_28 )
V_28 = V_9 -> V_28 ;
return V_28 ;
}
static int F_20 ( struct V_1 * V_29 ,
struct V_3 * V_4 )
{
struct V_6 * V_7 = F_2 ( V_29 ) ;
struct V_8 * V_9 = F_3 ( V_7 ) ;
struct V_26 * V_27 = F_18 ( V_29 ) ;
T_1 V_30 = F_19 ( V_27 ) ;
T_1 V_31 = 0 ;
if ( V_30 )
V_31 = 0x0400000 / V_30 * V_9 -> V_28 ;
F_8 ( V_29 , V_32 , 0 ) ;
F_8 ( V_29 , V_32 , 1 ) ;
F_8 ( V_29 , V_33 , F_9 ( V_29 ) ) ;
if ( V_31 ) {
F_8 ( V_29 , V_34 , 1 ) ;
F_8 ( V_29 , V_35 , V_31 ) ;
}
F_8 ( V_29 , V_36 , 1 ) ;
return 0 ;
}
static int F_21 ( struct V_1 * V_29 ,
struct V_3 * V_4 )
{
struct V_26 * V_27 = F_18 ( V_29 ) ;
F_22 ( V_27 -> V_37 ) ;
F_8 ( V_29 , V_38 , 1 ) ;
return 0 ;
}
static int F_23 ( struct V_1 * V_29 ,
struct V_3 * V_4 )
{
struct V_26 * V_27 = F_18 ( V_29 ) ;
F_24 ( V_27 -> V_37 ) ;
return 0 ;
}
static int F_25 ( struct V_1 * V_29 )
{
F_8 ( V_29 , V_38 , 0 ) ;
return 0 ;
}
static int F_26 ( struct V_1 * V_29 )
{
return 0 ;
}
static int F_27 ( struct V_1 * V_29 ,
struct V_3 * V_4 )
{
struct V_6 * V_7 = F_2 ( V_29 ) ;
struct V_39 {
T_1 V_15 ;
int V_12 ;
} V_40 [] = {
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
T_1 V_15 ;
T_1 V_14 ;
int V_41 ;
V_41 = F_4 ( V_29 ) ;
if ( V_41 < 0 || V_41 >= F_28 ( V_40 ) )
return - V_42 ;
V_14 = F_29 ( V_4 , V_7 ) ? 0x1 : 0x2 ;
V_14 = V_14 << V_40 [ V_41 ] . V_12 ;
V_15 = V_40 [ V_41 ] . V_15 << V_40 [ V_41 ] . V_12 ;
F_5 ( V_29 , V_43 , V_15 , V_14 ) ;
return 0 ;
}
static int F_30 ( struct V_1 * V_29 ,
struct V_3 * V_4 )
{
struct V_6 * V_7 = F_2 ( V_29 ) ;
struct V_22 * V_23 = F_12 ( V_29 ) ;
struct V_26 * V_27 = F_18 ( V_29 ) ;
struct V_8 * V_9 = F_3 ( V_7 ) ;
T_1 V_30 = F_19 ( V_27 ) ;
T_1 V_15 ;
T_1 V_14 ;
int V_12 ;
int V_41 = F_4 ( V_29 ) ;
int V_44 ;
V_12 = ( V_41 % 4 ) * 8 ;
V_15 = 0x1F << V_12 ;
V_44 = 0 ;
if ( V_30 ) {
V_14 = 0 ;
V_44 = F_31 ( V_23 , V_29 ,
V_9 -> V_28 ,
V_30 ) ;
} else if ( 8 == V_41 ) {
V_14 = V_41 << V_12 ;
} else {
V_14 = ( V_41 + 1 ) << V_12 ;
}
if ( V_44 < 0 )
return V_44 ;
switch ( V_41 / 4 ) {
case 0 :
F_5 ( V_29 , V_45 , V_15 , V_14 ) ;
break;
case 1 :
F_5 ( V_29 , V_46 , V_15 , V_14 ) ;
break;
case 2 :
F_5 ( V_29 , V_47 , V_15 , V_14 ) ;
break;
}
return 0 ;
}
static int F_32 ( struct V_1 * V_29 ,
struct V_3 * V_4 )
{
struct V_26 * V_27 = F_18 ( V_29 ) ;
int V_44 ;
V_44 = F_20 ( V_29 , V_4 ) ;
if ( V_44 < 0 )
return V_44 ;
F_8 ( V_29 , V_48 , 0x00010110 ) ;
F_8 ( V_29 , V_49 ,
F_33 ( V_29 , V_35 ) / 100 * 98 ) ;
if ( F_19 ( V_27 ) )
F_8 ( V_29 , V_50 , 1 ) ;
return 0 ;
}
static int F_34 ( struct V_1 * V_29 ,
struct V_3 * V_4 )
{
struct V_22 * V_23 = F_12 ( V_29 ) ;
struct V_51 * V_52 = F_35 ( V_23 ) ;
F_36 ( V_52 , L_1 ,
F_37 ( V_29 ) , F_4 ( V_29 ) ) ;
return 0 ;
}
static int F_38 ( struct V_1 * V_29 ,
struct V_3 * V_4 )
{
int V_44 ;
V_44 = F_21 ( V_29 , V_4 ) ;
if ( V_44 < 0 )
return V_44 ;
V_44 = F_27 ( V_29 , V_4 ) ;
if ( V_44 < 0 )
return V_44 ;
V_44 = F_32 ( V_29 , V_4 ) ;
if ( V_44 < 0 )
return V_44 ;
V_44 = F_30 ( V_29 , V_4 ) ;
if ( V_44 < 0 )
return V_44 ;
return 0 ;
}
static int F_39 ( struct V_1 * V_29 ,
struct V_3 * V_4 )
{
int V_41 = F_4 ( V_29 ) ;
F_5 ( V_29 , V_53 , ( 1 << V_41 ) , ( 1 << V_41 ) ) ;
return F_25 ( V_29 ) ;
}
static int F_40 ( struct V_1 * V_29 ,
struct V_3 * V_4 )
{
int V_41 = F_4 ( V_29 ) ;
F_5 ( V_29 , V_53 , ( 1 << V_41 ) , 0 ) ;
return F_26 ( V_29 ) ;
}
static int F_41 ( struct V_1 * V_29 ,
struct V_3 * V_4 )
{
struct V_22 * V_23 = F_12 ( V_29 ) ;
struct V_51 * V_52 = F_35 ( V_23 ) ;
struct V_6 * V_7 = F_2 ( V_29 ) ;
struct V_8 * V_9 = F_3 ( V_7 ) ;
struct V_26 * V_27 = F_18 ( V_29 ) ;
T_1 V_30 = F_19 ( V_27 ) ;
T_2 V_54 ;
int V_44 ;
if ( ! V_30 )
V_54 = 0 ;
else if ( V_30 > V_9 -> V_28 )
V_54 = 100 * V_30 / V_9 -> V_28 ;
else
V_54 = 100 * V_9 -> V_28 / V_30 ;
if ( V_54 > 600 ) {
F_42 ( V_52 , L_2 ) ;
return - V_55 ;
}
V_44 = F_20 ( V_29 , V_4 ) ;
if ( V_44 < 0 )
return V_44 ;
F_8 ( V_29 , V_48 , 0x00011110 ) ;
if ( V_30 ) {
F_8 ( V_29 , V_50 , 1 ) ;
}
switch ( F_4 ( V_29 ) ) {
case 5 :
case 6 :
case 7 :
case 8 :
F_8 ( V_29 , V_56 , 0x02400000 ) ;
break;
default:
F_8 ( V_29 , V_56 , 0x01800000 ) ;
break;
}
F_8 ( V_29 , V_57 , 0x00100060 ) ;
return 0 ;
}
static int F_43 ( struct V_1 * V_29 ,
struct V_3 * V_4 )
{
struct V_6 * V_7 = F_2 ( V_29 ) ;
struct V_8 * V_9 = F_3 ( V_7 ) ;
struct V_26 * V_27 = F_18 ( V_29 ) ;
T_1 V_30 = F_19 ( V_27 ) ;
int V_44 ;
if ( V_30 )
V_44 = F_44 ( V_29 , V_4 , V_7 ,
V_9 -> V_28 ,
V_30 ) ;
else
V_44 = F_45 ( V_29 , V_4 , V_7 ) ;
return V_44 ;
}
static int F_46 ( struct V_1 * V_29 ,
struct V_3 * V_4 )
{
struct V_22 * V_23 = F_12 ( V_29 ) ;
struct V_26 * V_27 = F_18 ( V_29 ) ;
struct V_51 * V_52 = F_35 ( V_23 ) ;
int V_44 ;
V_44 = F_47 ( V_23 ,
F_48 ( V_29 ) ,
F_49 ( V_23 , V_27 ) ,
V_27 -> V_58 -> V_59 ) ;
if ( V_44 < 0 )
F_42 ( V_52 , L_3 ,
F_37 ( V_29 ) , F_4 ( V_29 ) ) ;
else
F_36 ( V_52 , L_4 ,
F_37 ( V_29 ) , F_4 ( V_29 ) ) ;
return V_44 ;
}
static int F_50 ( struct V_1 * V_29 ,
struct V_3 * V_4 )
{
F_51 ( F_12 ( V_29 ) , F_48 ( V_29 ) ) ;
return 0 ;
}
static int F_52 ( struct V_1 * V_29 ,
struct V_3 * V_4 )
{
int V_44 ;
V_44 = F_21 ( V_29 , V_4 ) ;
if ( V_44 < 0 )
return V_44 ;
V_44 = F_41 ( V_29 , V_4 ) ;
if ( V_44 < 0 )
return V_44 ;
V_44 = F_43 ( V_29 , V_4 ) ;
if ( V_44 < 0 )
return V_44 ;
return 0 ;
}
static int F_53 ( struct V_1 * V_29 ,
struct V_3 * V_4 )
{
struct V_6 * V_7 = F_2 ( V_29 ) ;
struct V_26 * V_27 = F_18 ( V_29 ) ;
T_1 V_14 = F_54 ( V_7 ) ? 0x01 : 0x11 ;
F_55 ( F_48 ( & V_27 -> V_29 ) ) ;
F_8 ( V_29 , V_60 , V_14 ) ;
return F_25 ( V_29 ) ;
}
static int F_56 ( struct V_1 * V_29 ,
struct V_3 * V_4 )
{
struct V_26 * V_27 = F_18 ( V_29 ) ;
F_8 ( V_29 , V_60 , 0 ) ;
F_57 ( F_48 ( & V_27 -> V_29 ) ) ;
return F_26 ( V_29 ) ;
}
struct V_1 * F_58 ( struct V_22 * V_23 , int V_41 )
{
if ( F_59 ( V_41 < 0 || V_41 >= F_60 ( V_23 ) ) )
V_41 = 0 ;
return & ( (struct V_26 * ) ( V_23 -> V_27 ) + V_41 ) -> V_29 ;
}
static void F_61 ( struct V_61 * V_62 ,
const struct V_63 * V_64 ,
struct V_22 * V_23 )
{
struct V_65 * V_66 ;
struct V_67 * V_58 = F_62 ( V_23 ) ;
struct V_68 * V_69 ;
struct V_51 * V_52 = & V_62 -> V_52 ;
int V_70 ;
if ( ! V_64 )
return;
V_66 = F_63 ( V_52 -> V_71 , L_5 ) ;
if ( ! V_66 )
return;
V_70 = F_64 ( V_66 ) ;
if ( ! V_70 )
goto V_72;
V_69 = F_65 ( V_52 ,
sizeof( struct V_68 ) * V_70 ,
V_73 ) ;
if ( ! V_69 ) {
F_42 ( V_52 , L_6 ) ;
goto V_72;
}
V_58 -> V_69 = V_69 ;
V_58 -> V_74 = V_70 ;
V_72:
F_66 ( V_66 ) ;
}
int F_67 ( struct V_61 * V_62 ,
const struct V_63 * V_64 ,
struct V_22 * V_23 )
{
struct V_67 * V_58 = F_62 ( V_23 ) ;
struct V_51 * V_52 = F_35 ( V_23 ) ;
struct V_26 * V_27 ;
struct V_75 * V_76 ;
struct V_37 * V_37 ;
char V_77 [ V_78 ] ;
int V_79 , V_70 ;
V_76 = NULL ;
if ( F_13 ( V_23 ) )
V_76 = & V_80 ;
if ( F_68 ( V_23 ) )
V_76 = & V_81 ;
if ( ! V_76 ) {
F_42 ( V_52 , L_7 ) ;
return - V_42 ;
}
F_61 ( V_62 , V_64 , V_23 ) ;
V_70 = V_58 -> V_74 ;
if ( ! V_70 )
return 0 ;
V_27 = F_65 ( V_52 , sizeof( * V_27 ) * V_70 , V_73 ) ;
if ( ! V_27 ) {
F_42 ( V_52 , L_8 ) ;
return - V_82 ;
}
V_23 -> V_83 = V_70 ;
V_23 -> V_27 = V_27 ;
F_69 (src, priv, i) {
snprintf ( V_77 , V_78 , L_9 ,
V_84 , V_79 ) ;
V_37 = F_70 ( V_52 , V_77 ) ;
if ( F_71 ( V_37 ) )
return F_72 ( V_37 ) ;
V_27 -> V_58 = & V_58 -> V_69 [ V_79 ] ;
V_27 -> V_37 = V_37 ;
F_73 ( V_23 , & V_27 -> V_29 , V_76 , V_85 , V_79 ) ;
F_36 ( V_52 , L_10 , V_79 ) ;
}
return 0 ;
}
