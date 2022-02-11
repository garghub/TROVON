static struct V_1 * F_1 ( struct V_2 * V_3 ,
struct V_4 * V_5 )
{
struct V_6 * V_7 = F_2 ( V_5 ) ;
int V_8 = F_3 ( V_3 ) ;
return F_4 ( F_5 ( V_7 ) ,
V_5 ,
V_8 ? L_1 : L_2 ) ;
}
int F_6 ( struct V_4 * V_9 ,
struct V_2 * V_3 ,
int V_10 )
{
struct V_11 * V_12 = F_7 ( V_3 ) ;
struct V_13 * V_14 = F_8 ( V_3 ) ;
int V_15 = F_9 ( V_9 ) ;
F_10 ( V_9 , V_16 , ( 1 << V_15 ) ,
! V_10 << V_15 ) ;
if ( F_11 ( V_9 ) ) {
int V_17 = - 1 ;
switch ( V_15 ) {
case 1 :
V_17 = 0 ;
break;
case 2 :
V_17 = 2 ;
break;
case 4 :
V_17 = 16 ;
break;
}
if ( V_17 >= 0 )
F_10 ( V_9 , V_18 ,
0x3 << V_17 ,
F_12 ( V_12 ) ?
0x2 << V_17 : 0x1 << V_17 ) ;
}
if ( V_10 ) {
T_1 V_19 = 0x76543210 ;
T_1 V_20 = ~ 0 ;
F_13 ( V_9 , V_21 ,
F_14 ( V_9 , V_3 ) ) ;
F_13 ( V_9 , V_22 , 1 ) ;
F_13 ( V_9 , V_23 , 0x1 ) ;
V_20 <<= V_14 -> V_24 * 4 ;
V_19 = V_19 & V_20 ;
switch ( V_14 -> V_25 ) {
case 16 :
V_19 |= 0x67452301 & ~ V_20 ;
break;
case 32 :
V_19 |= 0x76543210 & ~ V_20 ;
break;
}
F_13 ( V_9 , V_26 , V_19 ) ;
}
return 0 ;
}
int F_15 ( struct V_4 * V_9 ,
struct V_2 * V_3 )
{
F_13 ( V_9 , V_23 , 0 ) ;
return 0 ;
}
int F_16 ( struct V_4 * V_9 )
{
struct V_6 * V_7 = F_2 ( V_9 ) ;
if ( F_17 ( V_7 ) )
return 0 ;
if ( F_18 ( V_9 ) )
F_13 ( V_9 , V_27 , 0x0e000000 ) ;
else
F_13 ( V_9 , V_27 , 0x0f000000 ) ;
return 0 ;
}
int F_19 ( struct V_4 * V_9 )
{
struct V_6 * V_7 = F_2 ( V_9 ) ;
if ( F_17 ( V_7 ) )
return 0 ;
F_13 ( V_9 , V_27 , 0x00000000 ) ;
return 0 ;
}
static T_1 F_20 ( struct V_2 * V_3 ,
struct V_28 * V_29 )
{
struct V_13 * V_14 = F_8 ( V_3 ) ;
T_1 V_30 ;
if ( ! V_14 )
return 0 ;
if ( ! F_21 ( V_29 ) )
return V_29 -> V_30 ;
V_30 = V_29 -> V_31 . V_19 ;
if ( ! V_30 )
V_30 = V_29 -> V_30 ;
if ( ! V_30 )
V_30 = V_14 -> V_32 ;
return V_30 ;
}
unsigned int F_22 ( struct V_6 * V_7 ,
struct V_2 * V_3 ,
struct V_13 * V_14 )
{
struct V_4 * V_33 = F_23 ( V_3 ) ;
struct V_28 * V_29 ;
unsigned int V_32 = 0 ;
if ( V_33 ) {
V_29 = F_24 ( V_33 ) ;
V_32 = F_20 ( V_3 , V_29 ) ;
}
if ( ! V_32 )
V_32 = V_14 -> V_32 ;
return V_32 ;
}
static int F_25 ( struct V_4 * V_5 ,
struct V_2 * V_3 )
{
struct V_13 * V_14 = F_8 ( V_3 ) ;
struct V_28 * V_29 = F_24 ( V_5 ) ;
T_1 V_30 = F_20 ( V_3 , V_29 ) ;
T_1 V_34 = 0 ;
if ( V_30 )
V_34 = 0x0400000 / V_30 * V_14 -> V_32 ;
F_13 ( V_5 , V_35 , 0 ) ;
F_13 ( V_5 , V_35 , 1 ) ;
F_13 ( V_5 , V_36 , F_14 ( V_5 , V_3 ) ) ;
if ( V_34 ) {
F_13 ( V_5 , V_37 , 1 ) ;
F_13 ( V_5 , V_38 , V_34 ) ;
}
F_13 ( V_5 , V_39 , 1 ) ;
return 0 ;
}
static int F_26 ( struct V_4 * V_5 ,
struct V_2 * V_3 ,
struct V_40 * V_41 ,
struct V_42 * V_43 )
{
struct V_28 * V_29 = F_24 ( V_5 ) ;
struct V_44 * V_45 = V_41 -> V_46 ;
V_29 -> V_30 = V_29 -> V_47 -> V_30 ;
if ( V_45 -> V_48 -> V_49 ) {
int V_50 = V_41 -> V_50 ;
struct V_51 * V_52 ;
struct V_42 * V_53 ;
F_27 (dpcm, &fe->dpcm[stream].be_clients, list_be) {
V_53 = & V_52 -> V_54 ;
if ( F_28 ( V_43 ) != F_28 ( V_53 ) )
V_29 -> V_30 = F_28 ( V_53 ) ;
}
}
return 0 ;
}
static int F_29 ( struct V_4 * V_5 ,
struct V_6 * V_7 )
{
struct V_28 * V_29 = F_24 ( V_5 ) ;
F_30 ( V_5 ) ;
V_29 -> V_55 = 0 ;
V_29 -> V_31 . V_19 = 0 ;
F_13 ( V_5 , V_56 , 1 ) ;
return 0 ;
}
static int F_31 ( struct V_4 * V_5 ,
struct V_2 * V_3 ,
struct V_6 * V_7 )
{
struct V_28 * V_29 = F_24 ( V_5 ) ;
struct V_57 * V_58 = F_32 ( V_7 ) ;
F_33 ( V_5 ) ;
if ( V_29 -> V_55 )
F_34 ( V_58 , L_3 ,
F_35 ( V_5 ) , F_9 ( V_5 ) , V_29 -> V_55 ) ;
V_29 -> V_30 = 0 ;
V_29 -> V_31 . V_19 = 0 ;
return 0 ;
}
static int F_36 ( struct V_4 * V_5 )
{
F_13 ( V_5 , V_56 , 0 ) ;
return 0 ;
}
static int F_37 ( struct V_4 * V_5 )
{
return 0 ;
}
static int F_38 ( struct V_2 * V_3 ,
struct V_4 * V_5 )
{
struct V_59 {
T_1 V_20 ;
int V_17 ;
} V_60 [] = {
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
T_1 V_20 ;
T_1 V_19 ;
int V_61 ;
V_61 = F_9 ( V_5 ) ;
if ( V_61 < 0 || V_61 >= F_39 ( V_60 ) )
return - V_62 ;
V_19 = F_3 ( V_3 ) ? 0x1 : 0x2 ;
V_19 = V_19 << V_60 [ V_61 ] . V_17 ;
V_20 = V_60 [ V_61 ] . V_20 << V_60 [ V_61 ] . V_17 ;
F_10 ( V_5 , V_63 , V_20 , V_19 ) ;
return 0 ;
}
static int F_40 ( struct V_2 * V_3 ,
struct V_4 * V_5 )
{
struct V_6 * V_7 = F_2 ( V_5 ) ;
struct V_28 * V_29 = F_24 ( V_5 ) ;
struct V_13 * V_14 = F_8 ( V_3 ) ;
T_1 V_30 = F_20 ( V_3 , V_29 ) ;
T_1 V_20 ;
T_1 V_19 ;
int V_17 ;
int V_61 = F_9 ( V_5 ) ;
int V_64 ;
V_17 = ( V_61 % 4 ) * 8 ;
V_20 = 0x1F << V_17 ;
V_64 = 0 ;
if ( V_30 ) {
V_19 = 0 ;
V_64 = F_41 ( V_7 , V_5 ,
V_14 -> V_32 ,
V_30 ) ;
} else if ( 8 == V_61 ) {
V_19 = V_61 << V_17 ;
} else {
V_19 = ( V_61 + 1 ) << V_17 ;
}
if ( V_64 < 0 )
return V_64 ;
switch ( V_61 / 4 ) {
case 0 :
F_10 ( V_5 , V_65 , V_20 , V_19 ) ;
break;
case 1 :
F_10 ( V_5 , V_66 , V_20 , V_19 ) ;
break;
case 2 :
F_10 ( V_5 , V_67 , V_20 , V_19 ) ;
break;
}
return 0 ;
}
static int F_42 ( struct V_4 * V_5 ,
struct V_2 * V_3 )
{
struct V_28 * V_29 = F_24 ( V_5 ) ;
int V_64 ;
V_64 = F_25 ( V_5 , V_3 ) ;
if ( V_64 < 0 )
return V_64 ;
F_13 ( V_5 , V_68 , 0x00010110 ) ;
F_13 ( V_5 , V_69 ,
F_43 ( V_5 , V_38 ) / 100 * 98 ) ;
if ( F_20 ( V_3 , V_29 ) )
F_13 ( V_5 , V_70 , 1 ) ;
return 0 ;
}
static int F_44 ( struct V_4 * V_5 ,
struct V_2 * V_3 ,
struct V_6 * V_7 )
{
int V_64 ;
V_64 = F_29 ( V_5 , V_7 ) ;
if ( V_64 < 0 )
return V_64 ;
V_64 = F_38 ( V_3 , V_5 ) ;
if ( V_64 < 0 )
return V_64 ;
V_64 = F_42 ( V_5 , V_3 ) ;
if ( V_64 < 0 )
return V_64 ;
V_64 = F_40 ( V_3 , V_5 ) ;
if ( V_64 < 0 )
return V_64 ;
return 0 ;
}
static int F_45 ( struct V_4 * V_5 ,
struct V_2 * V_3 ,
struct V_6 * V_7 )
{
int V_61 = F_9 ( V_5 ) ;
F_10 ( V_5 , V_71 , ( 1 << V_61 ) , ( 1 << V_61 ) ) ;
return F_36 ( V_5 ) ;
}
static int F_46 ( struct V_4 * V_5 ,
struct V_2 * V_3 ,
struct V_6 * V_7 )
{
int V_61 = F_9 ( V_5 ) ;
F_10 ( V_5 , V_71 , ( 1 << V_61 ) , 0 ) ;
return F_37 ( V_5 ) ;
}
static void F_47 ( struct V_4 * V_5 , int V_72 )
{
struct V_28 * V_29 = F_24 ( V_5 ) ;
T_1 V_73 , V_74 , V_75 ;
int V_76 = V_29 -> V_47 -> V_76 ;
int V_61 = F_9 ( V_5 ) ;
V_73 =
V_75 = F_48 ( V_61 ) ;
V_74 = 0x3300 ;
if ( ( V_76 <= 0 ) || ! V_72 ) {
V_73 = 0 ;
V_74 = 0 ;
}
F_13 ( V_5 , V_77 , V_74 ) ;
F_10 ( V_5 , V_78 , V_75 , V_73 ) ;
F_10 ( V_5 , V_79 , V_75 , V_73 ) ;
}
static void F_49 ( struct V_4 * V_5 )
{
T_1 V_19 = F_48 ( F_9 ( V_5 ) ) ;
F_10 ( V_5 , V_80 , V_19 , V_19 ) ;
F_10 ( V_5 , V_81 , V_19 , V_19 ) ;
}
static bool F_50 ( struct V_4 * V_5 )
{
T_1 V_19 = F_48 ( F_9 ( V_5 ) ) ;
bool V_64 = false ;
if ( ( F_43 ( V_5 , V_80 ) & V_19 ) ||
( F_43 ( V_5 , V_81 ) & V_19 ) ) {
struct V_28 * V_29 = F_24 ( V_5 ) ;
V_29 -> V_55 ++ ;
V_64 = true ;
}
F_49 ( V_5 ) ;
return V_64 ;
}
static int F_51 ( struct V_4 * V_5 ,
struct V_2 * V_3 )
{
T_1 V_19 = F_52 ( V_3 ) ? 0x01 : 0x11 ;
F_13 ( V_5 , V_82 , V_19 ) ;
F_49 ( V_5 ) ;
F_36 ( V_5 ) ;
F_53 ( V_5 ) ;
return 0 ;
}
static int F_54 ( struct V_4 * V_5 )
{
F_55 ( V_5 ) ;
F_13 ( V_5 , V_82 , 0 ) ;
F_50 ( V_5 ) ;
return F_37 ( V_5 ) ;
}
static void F_56 ( struct V_4 * V_5 ,
struct V_2 * V_3 )
{
struct V_6 * V_7 = F_2 ( V_5 ) ;
F_57 ( & V_7 -> V_83 ) ;
if ( ! F_58 ( V_3 ) )
goto V_84;
if ( F_50 ( V_5 ) ) {
struct V_6 * V_7 = F_2 ( V_5 ) ;
struct V_28 * V_29 = F_24 ( V_5 ) ;
struct V_57 * V_58 = F_32 ( V_7 ) ;
F_59 ( V_58 , L_4 ,
F_35 ( V_5 ) , F_9 ( V_5 ) ) ;
F_54 ( V_5 ) ;
if ( V_29 -> V_55 < 1024 )
F_51 ( V_5 , V_3 ) ;
else
F_34 ( V_58 , L_5 ) ;
}
V_84:
F_60 ( & V_7 -> V_83 ) ;
}
static T_2 F_61 ( int V_76 , void * V_85 )
{
struct V_4 * V_5 = V_85 ;
F_62 ( V_5 , F_56 ) ;
return V_86 ;
}
static int F_63 ( struct V_4 * V_5 ,
struct V_2 * V_3 )
{
struct V_6 * V_7 = F_2 ( V_5 ) ;
struct V_57 * V_58 = F_32 ( V_7 ) ;
struct V_13 * V_14 = F_8 ( V_3 ) ;
struct V_28 * V_29 = F_24 ( V_5 ) ;
T_1 V_30 = F_20 ( V_3 , V_29 ) ;
T_1 V_87 , V_88 ;
T_3 V_89 ;
int V_64 ;
if ( ! V_30 )
V_89 = 0 ;
else if ( V_30 > V_14 -> V_32 )
V_89 = 100 * V_30 / V_14 -> V_32 ;
else
V_89 = 100 * V_14 -> V_32 / V_30 ;
if ( V_89 > 600 ) {
F_64 ( V_58 , L_6 ) ;
return - V_90 ;
}
V_64 = F_25 ( V_5 , V_3 ) ;
if ( V_64 < 0 )
return V_64 ;
V_87 = 0x00011110 ;
V_88 = 0x0 ;
if ( V_30 ) {
V_88 = 0x1 ;
if ( F_21 ( V_29 ) ) {
V_87 |= 0x1 ;
V_88 |= F_3 ( V_3 ) ?
( 0x1 << 24 ) : ( 0x1 << 25 ) ;
}
}
F_13 ( V_5 , V_68 , V_87 ) ;
F_13 ( V_5 , V_70 , V_88 ) ;
switch ( F_9 ( V_5 ) ) {
case 5 :
case 6 :
case 7 :
case 8 :
F_13 ( V_5 , V_91 , 0x02400000 ) ;
break;
default:
F_13 ( V_5 , V_91 , 0x01800000 ) ;
break;
}
F_13 ( V_5 , V_92 , 0x00100060 ) ;
return 0 ;
}
static int F_65 ( struct V_2 * V_3 ,
struct V_4 * V_5 )
{
struct V_13 * V_14 = F_8 ( V_3 ) ;
struct V_28 * V_29 = F_24 ( V_5 ) ;
T_1 V_30 = F_20 ( V_3 , V_29 ) ;
int V_64 ;
if ( V_30 )
V_64 = F_66 ( V_5 , V_3 ,
V_14 -> V_32 ,
V_30 ) ;
else
V_64 = F_67 ( V_5 , V_3 ) ;
return V_64 ;
}
static int F_68 ( struct V_4 * V_5 ,
struct V_2 * V_3 ,
struct V_6 * V_7 )
{
struct V_28 * V_29 = F_24 ( V_5 ) ;
struct V_57 * V_58 = F_32 ( V_7 ) ;
int V_76 = V_29 -> V_47 -> V_76 ;
int V_64 ;
if ( V_76 > 0 ) {
V_64 = F_69 ( V_58 , V_76 ,
F_61 ,
V_93 ,
F_70 ( V_58 ) , V_5 ) ;
if ( V_64 )
return V_64 ;
}
V_64 = F_71 ( V_3 ,
F_72 ( V_5 ) ,
V_29 -> V_47 -> V_94 ) ;
return V_64 ;
}
static int F_73 ( struct V_4 * V_5 ,
struct V_2 * V_3 ,
struct V_6 * V_7 )
{
F_74 ( V_3 , F_72 ( V_5 ) ) ;
return 0 ;
}
static int F_75 ( struct V_4 * V_5 ,
struct V_2 * V_3 ,
struct V_6 * V_7 )
{
int V_64 ;
V_64 = F_29 ( V_5 , V_7 ) ;
if ( V_64 < 0 )
return V_64 ;
V_64 = F_63 ( V_5 , V_3 ) ;
if ( V_64 < 0 )
return V_64 ;
V_64 = F_65 ( V_3 , V_5 ) ;
if ( V_64 < 0 )
return V_64 ;
return 0 ;
}
static int F_76 ( struct V_4 * V_5 ,
struct V_2 * V_3 ,
struct V_6 * V_7 )
{
F_77 ( V_3 , F_72 ( V_5 ) ) ;
return F_51 ( V_5 , V_3 ) ;
}
static int F_78 ( struct V_4 * V_5 ,
struct V_2 * V_3 ,
struct V_6 * V_7 )
{
int V_64 ;
V_64 = F_54 ( V_5 ) ;
F_79 ( V_3 , F_72 ( V_5 ) ) ;
return V_64 ;
}
static void F_80 ( struct V_2 * V_3 ,
struct V_4 * V_5 )
{
struct V_13 * V_14 = F_8 ( V_3 ) ;
struct V_28 * V_29 = F_24 ( V_5 ) ;
T_1 V_30 = F_20 ( V_3 , V_29 ) ;
T_1 V_34 ;
if ( ! V_14 )
return;
if ( ! V_30 )
V_30 = V_14 -> V_32 ;
V_34 = 0x0400000 / V_30 * V_14 -> V_32 ;
F_13 ( V_5 , V_38 , V_34 ) ;
}
static int F_81 ( struct V_4 * V_5 ,
struct V_2 * V_3 ,
struct V_44 * V_95 )
{
struct V_6 * V_7 = F_2 ( V_5 ) ;
struct V_11 * V_12 = F_7 ( V_3 ) ;
struct V_28 * V_29 = F_24 ( V_5 ) ;
int V_64 ;
if ( F_17 ( V_7 ) )
return 0 ;
if ( ! F_12 ( V_12 ) )
return 0 ;
if ( F_52 ( V_3 ) )
return 0 ;
V_64 = F_82 ( V_5 , V_3 , V_95 ,
F_3 ( V_3 ) ?
L_7 :
L_8 ,
F_80 ,
& V_29 -> V_96 , 1 ) ;
if ( V_64 < 0 )
return V_64 ;
V_64 = F_82 ( V_5 , V_3 , V_95 ,
F_3 ( V_3 ) ?
L_9 :
L_10 ,
F_80 ,
& V_29 -> V_31 , 192000 ) ;
return V_64 ;
}
struct V_4 * F_83 ( struct V_6 * V_7 , int V_61 )
{
if ( F_84 ( V_61 < 0 || V_61 >= F_85 ( V_7 ) ) )
V_61 = 0 ;
return & ( (struct V_28 * ) ( V_7 -> V_29 ) + V_61 ) -> V_5 ;
}
static void F_86 ( struct V_97 * V_98 ,
const struct V_99 * V_100 ,
struct V_6 * V_7 )
{
struct V_101 * V_102 ;
struct V_101 * V_103 ;
struct V_104 * V_47 = F_87 ( V_7 ) ;
struct V_105 * V_106 ;
struct V_57 * V_58 = & V_98 -> V_58 ;
int V_107 , V_108 ;
if ( ! V_100 )
return;
V_102 = F_5 ( V_7 ) ;
if ( ! V_102 )
return;
V_107 = F_88 ( V_102 ) ;
if ( ! V_107 )
goto V_109;
V_106 = F_89 ( V_58 ,
sizeof( struct V_105 ) * V_107 ,
V_110 ) ;
if ( ! V_106 ) {
F_64 ( V_58 , L_11 ) ;
goto V_109;
}
V_47 -> V_106 = V_106 ;
V_47 -> V_111 = V_107 ;
V_108 = 0 ;
F_90 (src_node, np) {
V_106 [ V_108 ] . V_76 = F_91 ( V_103 , 0 ) ;
V_108 ++ ;
}
V_109:
F_92 ( V_102 ) ;
}
int F_93 ( struct V_97 * V_98 ,
const struct V_99 * V_100 ,
struct V_6 * V_7 )
{
struct V_104 * V_47 = F_87 ( V_7 ) ;
struct V_57 * V_58 = F_32 ( V_7 ) ;
struct V_28 * V_29 ;
struct V_112 * V_113 ;
struct V_114 * V_114 ;
char V_115 [ V_116 ] ;
int V_108 , V_107 , V_64 ;
V_113 = NULL ;
if ( F_17 ( V_7 ) )
V_113 = & V_117 ;
if ( F_94 ( V_7 ) )
V_113 = & V_118 ;
if ( ! V_113 ) {
F_64 ( V_58 , L_12 ) ;
return - V_62 ;
}
F_86 ( V_98 , V_100 , V_7 ) ;
V_107 = V_47 -> V_111 ;
if ( ! V_107 )
return 0 ;
V_29 = F_89 ( V_58 , sizeof( * V_29 ) * V_107 , V_110 ) ;
if ( ! V_29 ) {
F_64 ( V_58 , L_13 ) ;
return - V_119 ;
}
V_7 -> V_120 = V_107 ;
V_7 -> V_29 = V_29 ;
F_95 (src, priv, i) {
snprintf ( V_115 , V_116 , L_14 ,
V_121 , V_108 ) ;
V_114 = F_96 ( V_58 , V_115 ) ;
if ( F_97 ( V_114 ) )
return F_98 ( V_114 ) ;
V_29 -> V_47 = & V_47 -> V_106 [ V_108 ] ;
V_64 = F_99 ( V_7 , & V_29 -> V_5 , V_113 , V_114 , V_122 , V_108 ) ;
if ( V_64 )
return V_64 ;
}
return 0 ;
}
void F_100 ( struct V_97 * V_98 ,
struct V_6 * V_7 )
{
struct V_28 * V_29 ;
int V_108 ;
F_95 (src, priv, i) {
F_101 ( & V_29 -> V_5 ) ;
}
}
