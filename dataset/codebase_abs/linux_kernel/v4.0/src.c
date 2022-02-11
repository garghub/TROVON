int F_1 ( struct V_1 * V_2 ,
int V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_7 = F_3 ( V_5 ) ;
struct V_8 * V_9 = F_4 ( V_5 ) ;
int V_10 = F_5 ( V_2 ) ;
F_6 ( V_2 , V_11 , ( 1 << V_10 ) ,
! V_3 << V_10 ) ;
if ( F_7 ( V_2 ) ) {
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
F_6 ( V_2 , V_13 ,
0x3 << V_12 ,
F_8 ( V_7 ) ?
0x2 << V_12 : 0x1 << V_12 ) ;
}
if ( V_3 ) {
T_1 V_14 = 0x76543210 ;
T_1 V_15 = ~ 0 ;
F_9 ( V_2 , V_16 ,
F_10 ( V_2 ) ) ;
F_9 ( V_2 , V_17 , 1 ) ;
F_9 ( V_2 , V_18 , 0x1 ) ;
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
F_9 ( V_2 , V_21 , V_14 ) ;
}
return 0 ;
}
int F_11 ( struct V_1 * V_2 )
{
F_9 ( V_2 , V_18 , 0 ) ;
return 0 ;
}
int F_12 ( struct V_1 * V_2 )
{
struct V_22 * V_23 = F_13 ( V_2 ) ;
if ( F_14 ( V_23 ) )
return 0 ;
if ( F_15 ( V_2 ) )
F_9 ( V_2 , V_24 , 0x0e000000 ) ;
else
F_9 ( V_2 , V_24 , 0x0f000000 ) ;
return 0 ;
}
int F_16 ( struct V_1 * V_2 )
{
struct V_22 * V_23 = F_13 ( V_2 ) ;
if ( F_14 ( V_23 ) )
return 0 ;
F_9 ( V_2 , V_24 , 0x00000000 ) ;
return 0 ;
}
unsigned int F_17 ( struct V_22 * V_23 ,
struct V_4 * V_5 ,
struct V_8 * V_9 )
{
struct V_1 * V_25 = F_18 ( V_5 ) ;
struct V_26 * V_27 ;
unsigned int V_28 = 0 ;
if ( V_25 ) {
V_27 = F_19 ( V_25 ) ;
V_28 = F_20 ( V_27 ) ;
}
if ( ! V_28 )
V_28 = V_9 -> V_28 ;
return V_28 ;
}
static int F_21 ( struct V_1 * V_29 )
{
struct V_4 * V_5 = F_2 ( V_29 ) ;
struct V_8 * V_9 = F_4 ( V_5 ) ;
struct V_26 * V_27 = F_19 ( V_29 ) ;
T_1 V_30 = F_20 ( V_27 ) ;
T_1 V_31 = 0 ;
if ( V_30 )
V_31 = 0x0400000 / V_30 * V_9 -> V_28 ;
F_9 ( V_29 , V_32 , 0 ) ;
F_9 ( V_29 , V_32 , 1 ) ;
F_9 ( V_29 , V_33 , F_10 ( V_29 ) ) ;
if ( V_31 ) {
F_9 ( V_29 , V_34 , 1 ) ;
F_9 ( V_29 , V_35 , V_31 ) ;
}
F_9 ( V_29 , V_36 , 1 ) ;
return 0 ;
}
static int F_22 ( struct V_1 * V_29 )
{
struct V_26 * V_27 = F_19 ( V_29 ) ;
F_23 ( V_29 ) ;
V_27 -> V_37 = 0 ;
F_9 ( V_29 , V_38 , 1 ) ;
return 0 ;
}
static int F_24 ( struct V_1 * V_29 ,
struct V_22 * V_23 )
{
struct V_26 * V_27 = F_19 ( V_29 ) ;
struct V_39 * V_40 = F_25 ( V_23 ) ;
F_26 ( V_29 ) ;
if ( V_27 -> V_37 )
F_27 ( V_40 , L_1 ,
F_28 ( V_29 ) , F_5 ( V_29 ) , V_27 -> V_37 ) ;
return 0 ;
}
static int F_29 ( struct V_1 * V_29 )
{
F_9 ( V_29 , V_38 , 0 ) ;
return 0 ;
}
static int F_30 ( struct V_1 * V_29 )
{
return 0 ;
}
static int F_31 ( struct V_1 * V_29 )
{
struct V_4 * V_5 = F_2 ( V_29 ) ;
struct V_41 {
T_1 V_15 ;
int V_12 ;
} V_42 [] = {
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
int V_43 ;
V_43 = F_5 ( V_29 ) ;
if ( V_43 < 0 || V_43 >= F_32 ( V_42 ) )
return - V_44 ;
V_14 = F_33 ( V_5 ) ? 0x1 : 0x2 ;
V_14 = V_14 << V_42 [ V_43 ] . V_12 ;
V_15 = V_42 [ V_43 ] . V_15 << V_42 [ V_43 ] . V_12 ;
F_6 ( V_29 , V_45 , V_15 , V_14 ) ;
return 0 ;
}
static int F_34 ( struct V_1 * V_29 )
{
struct V_4 * V_5 = F_2 ( V_29 ) ;
struct V_22 * V_23 = F_13 ( V_29 ) ;
struct V_26 * V_27 = F_19 ( V_29 ) ;
struct V_8 * V_9 = F_4 ( V_5 ) ;
T_1 V_30 = F_20 ( V_27 ) ;
T_1 V_15 ;
T_1 V_14 ;
int V_12 ;
int V_43 = F_5 ( V_29 ) ;
int V_46 ;
V_12 = ( V_43 % 4 ) * 8 ;
V_15 = 0x1F << V_12 ;
V_46 = 0 ;
if ( V_30 ) {
V_14 = 0 ;
V_46 = F_35 ( V_23 , V_29 ,
V_9 -> V_28 ,
V_30 ) ;
} else if ( 8 == V_43 ) {
V_14 = V_43 << V_12 ;
} else {
V_14 = ( V_43 + 1 ) << V_12 ;
}
if ( V_46 < 0 )
return V_46 ;
switch ( V_43 / 4 ) {
case 0 :
F_6 ( V_29 , V_47 , V_15 , V_14 ) ;
break;
case 1 :
F_6 ( V_29 , V_48 , V_15 , V_14 ) ;
break;
case 2 :
F_6 ( V_29 , V_49 , V_15 , V_14 ) ;
break;
}
return 0 ;
}
static int F_36 ( struct V_1 * V_29 )
{
struct V_26 * V_27 = F_19 ( V_29 ) ;
int V_46 ;
V_46 = F_21 ( V_29 ) ;
if ( V_46 < 0 )
return V_46 ;
F_9 ( V_29 , V_50 , 0x00010110 ) ;
F_9 ( V_29 , V_51 ,
F_37 ( V_29 , V_35 ) / 100 * 98 ) ;
if ( F_20 ( V_27 ) )
F_9 ( V_29 , V_52 , 1 ) ;
return 0 ;
}
static int F_38 ( struct V_1 * V_29 ,
struct V_22 * V_23 )
{
struct V_39 * V_40 = F_25 ( V_23 ) ;
F_39 ( V_40 , L_2 ,
F_28 ( V_29 ) , F_5 ( V_29 ) ) ;
return 0 ;
}
static int F_40 ( struct V_1 * V_29 ,
struct V_22 * V_23 )
{
int V_46 ;
V_46 = F_22 ( V_29 ) ;
if ( V_46 < 0 )
return V_46 ;
V_46 = F_31 ( V_29 ) ;
if ( V_46 < 0 )
return V_46 ;
V_46 = F_36 ( V_29 ) ;
if ( V_46 < 0 )
return V_46 ;
V_46 = F_34 ( V_29 ) ;
if ( V_46 < 0 )
return V_46 ;
return 0 ;
}
static int F_41 ( struct V_1 * V_29 ,
struct V_22 * V_23 )
{
int V_43 = F_5 ( V_29 ) ;
F_6 ( V_29 , V_53 , ( 1 << V_43 ) , ( 1 << V_43 ) ) ;
return F_29 ( V_29 ) ;
}
static int F_42 ( struct V_1 * V_29 ,
struct V_22 * V_23 )
{
int V_43 = F_5 ( V_29 ) ;
F_6 ( V_29 , V_53 , ( 1 << V_43 ) , 0 ) ;
return F_30 ( V_29 ) ;
}
static void F_43 ( struct V_1 * V_29 , int V_54 )
{
struct V_26 * V_27 = F_19 ( V_29 ) ;
T_1 V_55 , V_56 , V_57 ;
int V_58 = V_27 -> V_59 -> V_58 ;
int V_43 = F_5 ( V_29 ) ;
V_55 =
V_57 = F_44 ( V_43 ) ;
V_56 = 0x3300 ;
if ( ( V_58 <= 0 ) || ! V_54 ) {
V_55 = 0 ;
V_56 = 0 ;
}
F_9 ( V_29 , V_60 , V_56 ) ;
F_6 ( V_29 , V_61 , V_57 , V_55 ) ;
F_6 ( V_29 , V_62 , V_57 , V_55 ) ;
}
static void F_45 ( struct V_1 * V_29 )
{
T_1 V_14 = F_44 ( F_5 ( V_29 ) ) ;
F_6 ( V_29 , V_63 , V_14 , V_14 ) ;
F_6 ( V_29 , V_64 , V_14 , V_14 ) ;
}
static bool F_46 ( struct V_1 * V_29 )
{
T_1 V_14 = F_44 ( F_5 ( V_29 ) ) ;
bool V_46 = false ;
if ( ( F_37 ( V_29 , V_63 ) & V_14 ) ||
( F_37 ( V_29 , V_64 ) & V_14 ) ) {
struct V_26 * V_27 = F_19 ( V_29 ) ;
V_27 -> V_37 ++ ;
V_46 = true ;
}
F_45 ( V_29 ) ;
return V_46 ;
}
static int F_47 ( struct V_1 * V_29 )
{
struct V_4 * V_5 = F_2 ( V_29 ) ;
T_1 V_14 = F_48 ( V_5 ) ? 0x01 : 0x11 ;
F_9 ( V_29 , V_65 , V_14 ) ;
F_45 ( V_29 ) ;
F_29 ( V_29 ) ;
F_49 ( V_29 ) ;
return 0 ;
}
static int F_50 ( struct V_1 * V_29 )
{
F_51 ( V_29 ) ;
F_9 ( V_29 , V_65 , 0 ) ;
F_46 ( V_29 ) ;
return F_30 ( V_29 ) ;
}
static T_2 F_52 ( int V_58 , void * V_66 )
{
struct V_1 * V_29 = V_66 ;
struct V_4 * V_5 = F_2 ( V_29 ) ;
if ( ! V_5 )
return V_67 ;
if ( F_46 ( V_29 ) ) {
struct V_22 * V_23 = F_13 ( V_29 ) ;
struct V_39 * V_40 = F_25 ( V_23 ) ;
F_50 ( V_29 ) ;
F_47 ( V_29 ) ;
F_39 ( V_40 , L_3 ,
F_28 ( V_29 ) , F_5 ( V_29 ) ) ;
}
return V_68 ;
}
static int F_53 ( struct V_1 * V_29 )
{
struct V_22 * V_23 = F_13 ( V_29 ) ;
struct V_39 * V_40 = F_25 ( V_23 ) ;
struct V_4 * V_5 = F_2 ( V_29 ) ;
struct V_8 * V_9 = F_4 ( V_5 ) ;
struct V_26 * V_27 = F_19 ( V_29 ) ;
T_1 V_30 = F_20 ( V_27 ) ;
T_3 V_69 ;
int V_46 ;
if ( ! V_30 )
V_69 = 0 ;
else if ( V_30 > V_9 -> V_28 )
V_69 = 100 * V_30 / V_9 -> V_28 ;
else
V_69 = 100 * V_9 -> V_28 / V_30 ;
if ( V_69 > 600 ) {
F_54 ( V_40 , L_4 ) ;
return - V_70 ;
}
V_46 = F_21 ( V_29 ) ;
if ( V_46 < 0 )
return V_46 ;
F_9 ( V_29 , V_50 , 0x00011110 ) ;
if ( V_30 ) {
F_9 ( V_29 , V_52 , 1 ) ;
}
switch ( F_5 ( V_29 ) ) {
case 5 :
case 6 :
case 7 :
case 8 :
F_9 ( V_29 , V_71 , 0x02400000 ) ;
break;
default:
F_9 ( V_29 , V_71 , 0x01800000 ) ;
break;
}
F_9 ( V_29 , V_72 , 0x00100060 ) ;
return 0 ;
}
static int F_55 ( struct V_1 * V_29 )
{
struct V_4 * V_5 = F_2 ( V_29 ) ;
struct V_8 * V_9 = F_4 ( V_5 ) ;
struct V_26 * V_27 = F_19 ( V_29 ) ;
T_1 V_30 = F_20 ( V_27 ) ;
int V_46 ;
if ( V_30 )
V_46 = F_56 ( V_29 , V_5 ,
V_9 -> V_28 ,
V_30 ) ;
else
V_46 = F_57 ( V_29 , V_5 ) ;
return V_46 ;
}
static int F_58 ( struct V_1 * V_29 ,
struct V_22 * V_23 )
{
struct V_26 * V_27 = F_19 ( V_29 ) ;
struct V_39 * V_40 = F_25 ( V_23 ) ;
int V_58 = V_27 -> V_59 -> V_58 ;
int V_46 ;
if ( V_58 > 0 ) {
V_46 = F_59 ( V_40 , V_58 ,
F_52 ,
V_73 ,
F_60 ( V_40 ) , V_29 ) ;
if ( V_46 )
goto V_74;
}
V_46 = F_61 ( V_23 ,
F_62 ( V_29 ) ,
F_63 ( V_23 , V_27 ) ,
V_27 -> V_59 -> V_75 ) ;
if ( V_46 )
goto V_74;
F_39 ( V_40 , L_5 ,
F_28 ( V_29 ) , F_5 ( V_29 ) ) ;
return V_46 ;
V_74:
F_54 ( V_40 , L_6 ,
F_28 ( V_29 ) , F_5 ( V_29 ) ) ;
return V_46 ;
}
static int F_64 ( struct V_1 * V_29 ,
struct V_22 * V_23 )
{
F_65 ( V_23 , F_62 ( V_29 ) ) ;
return 0 ;
}
static int F_66 ( struct V_1 * V_29 ,
struct V_22 * V_23 )
{
int V_46 ;
V_46 = F_22 ( V_29 ) ;
if ( V_46 < 0 )
return V_46 ;
V_46 = F_53 ( V_29 ) ;
if ( V_46 < 0 )
return V_46 ;
V_46 = F_55 ( V_29 ) ;
if ( V_46 < 0 )
return V_46 ;
return 0 ;
}
static int F_67 ( struct V_1 * V_29 ,
struct V_22 * V_23 )
{
F_68 ( F_62 ( V_29 ) ) ;
return F_47 ( V_29 ) ;
}
static int F_69 ( struct V_1 * V_29 ,
struct V_22 * V_23 )
{
int V_46 ;
V_46 = F_50 ( V_29 ) ;
F_70 ( F_62 ( V_29 ) ) ;
return V_46 ;
}
struct V_1 * F_71 ( struct V_22 * V_23 , int V_43 )
{
if ( F_72 ( V_43 < 0 || V_43 >= F_73 ( V_23 ) ) )
V_43 = 0 ;
return & ( (struct V_26 * ) ( V_23 -> V_27 ) + V_43 ) -> V_29 ;
}
static void F_74 ( struct V_76 * V_77 ,
const struct V_78 * V_79 ,
struct V_22 * V_23 )
{
struct V_80 * V_81 ;
struct V_80 * V_82 ;
struct V_83 * V_59 = F_75 ( V_23 ) ;
struct V_84 * V_85 ;
struct V_39 * V_40 = & V_77 -> V_40 ;
int V_86 , V_87 ;
if ( ! V_79 )
return;
V_81 = F_76 ( V_40 -> V_88 , L_7 ) ;
if ( ! V_81 )
return;
V_86 = F_77 ( V_81 ) ;
if ( ! V_86 )
goto V_89;
V_85 = F_78 ( V_40 ,
sizeof( struct V_84 ) * V_86 ,
V_90 ) ;
if ( ! V_85 ) {
F_54 ( V_40 , L_8 ) ;
goto V_89;
}
V_59 -> V_85 = V_85 ;
V_59 -> V_91 = V_86 ;
V_87 = 0 ;
F_79 (src_node, np) {
V_85 [ V_87 ] . V_58 = F_80 ( V_82 , 0 ) ;
V_87 ++ ;
}
V_89:
F_81 ( V_81 ) ;
}
int F_82 ( struct V_76 * V_77 ,
const struct V_78 * V_79 ,
struct V_22 * V_23 )
{
struct V_83 * V_59 = F_75 ( V_23 ) ;
struct V_39 * V_40 = F_25 ( V_23 ) ;
struct V_26 * V_27 ;
struct V_92 * V_93 ;
struct V_94 * V_94 ;
char V_95 [ V_96 ] ;
int V_87 , V_86 ;
V_93 = NULL ;
if ( F_14 ( V_23 ) )
V_93 = & V_97 ;
if ( F_83 ( V_23 ) )
V_93 = & V_98 ;
if ( ! V_93 ) {
F_54 ( V_40 , L_9 ) ;
return - V_44 ;
}
F_74 ( V_77 , V_79 , V_23 ) ;
V_86 = V_59 -> V_91 ;
if ( ! V_86 )
return 0 ;
V_27 = F_78 ( V_40 , sizeof( * V_27 ) * V_86 , V_90 ) ;
if ( ! V_27 ) {
F_54 ( V_40 , L_10 ) ;
return - V_99 ;
}
V_23 -> V_100 = V_86 ;
V_23 -> V_27 = V_27 ;
F_84 (src, priv, i) {
snprintf ( V_95 , V_96 , L_11 ,
V_101 , V_87 ) ;
V_94 = F_85 ( V_40 , V_95 ) ;
if ( F_86 ( V_94 ) )
return F_87 ( V_94 ) ;
V_27 -> V_59 = & V_59 -> V_85 [ V_87 ] ;
F_88 ( & V_27 -> V_29 , V_93 , V_94 , V_102 , V_87 ) ;
F_39 ( V_40 , L_12 , V_87 ) ;
}
return 0 ;
}
