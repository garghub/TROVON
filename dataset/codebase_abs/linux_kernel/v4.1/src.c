static struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = F_2 ( V_3 ) ;
struct V_6 * V_7 = F_3 ( V_3 ) ;
int V_8 = F_4 ( V_7 ) ;
return F_5 ( F_6 ( V_5 ) ,
V_3 ,
V_8 ? L_1 : L_2 ) ;
}
int F_7 ( struct V_2 * V_9 ,
int V_10 )
{
struct V_6 * V_7 = F_3 ( V_9 ) ;
struct V_11 * V_12 = F_8 ( V_7 ) ;
struct V_13 * V_14 = F_9 ( V_7 ) ;
int V_15 = F_10 ( V_9 ) ;
F_11 ( V_9 , V_16 , ( 1 << V_15 ) ,
! V_10 << V_15 ) ;
if ( F_12 ( V_9 ) ) {
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
F_11 ( V_9 , V_18 ,
0x3 << V_17 ,
F_13 ( V_12 ) ?
0x2 << V_17 : 0x1 << V_17 ) ;
}
if ( V_10 ) {
T_1 V_19 = 0x76543210 ;
T_1 V_20 = ~ 0 ;
F_14 ( V_9 , V_21 ,
F_15 ( V_9 ) ) ;
F_14 ( V_9 , V_22 , 1 ) ;
F_14 ( V_9 , V_23 , 0x1 ) ;
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
F_14 ( V_9 , V_26 , V_19 ) ;
}
return 0 ;
}
int F_16 ( struct V_2 * V_9 )
{
F_14 ( V_9 , V_23 , 0 ) ;
return 0 ;
}
int F_17 ( struct V_2 * V_9 )
{
struct V_4 * V_5 = F_2 ( V_9 ) ;
if ( F_18 ( V_5 ) )
return 0 ;
if ( F_19 ( V_9 ) )
F_14 ( V_9 , V_27 , 0x0e000000 ) ;
else
F_14 ( V_9 , V_27 , 0x0f000000 ) ;
return 0 ;
}
int F_20 ( struct V_2 * V_9 )
{
struct V_4 * V_5 = F_2 ( V_9 ) ;
if ( F_18 ( V_5 ) )
return 0 ;
F_14 ( V_9 , V_27 , 0x00000000 ) ;
return 0 ;
}
static T_1 F_21 ( struct V_28 * V_29 )
{
struct V_2 * V_3 = & V_29 -> V_3 ;
struct V_6 * V_7 = F_3 ( V_3 ) ;
struct V_13 * V_14 = F_9 ( V_7 ) ;
T_1 V_30 ;
if ( ! V_14 )
return 0 ;
if ( ! F_22 ( V_29 ) )
return V_29 -> V_30 ;
V_30 = V_29 -> V_31 . V_19 ;
if ( ! V_30 )
V_30 = V_29 -> V_30 ;
if ( ! V_30 )
V_30 = V_14 -> V_32 ;
return V_30 ;
}
unsigned int F_23 ( struct V_4 * V_5 ,
struct V_6 * V_7 ,
struct V_13 * V_14 )
{
struct V_2 * V_33 = F_24 ( V_7 ) ;
struct V_28 * V_29 ;
unsigned int V_32 = 0 ;
if ( V_33 ) {
V_29 = F_25 ( V_33 ) ;
V_32 = F_21 ( V_29 ) ;
}
if ( ! V_32 )
V_32 = V_14 -> V_32 ;
return V_32 ;
}
static int F_26 ( struct V_2 * V_3 )
{
struct V_6 * V_7 = F_3 ( V_3 ) ;
struct V_13 * V_14 = F_9 ( V_7 ) ;
struct V_28 * V_29 = F_25 ( V_3 ) ;
T_1 V_30 = F_21 ( V_29 ) ;
T_1 V_34 = 0 ;
if ( V_30 )
V_34 = 0x0400000 / V_30 * V_14 -> V_32 ;
F_14 ( V_3 , V_35 , 0 ) ;
F_14 ( V_3 , V_35 , 1 ) ;
F_14 ( V_3 , V_36 , F_15 ( V_3 ) ) ;
if ( V_34 ) {
F_14 ( V_3 , V_37 , 1 ) ;
F_14 ( V_3 , V_38 , V_34 ) ;
}
F_14 ( V_3 , V_39 , 1 ) ;
return 0 ;
}
static int F_27 ( struct V_2 * V_3 ,
struct V_40 * V_41 ,
struct V_42 * V_43 )
{
struct V_28 * V_29 = F_25 ( V_3 ) ;
struct V_44 * V_45 = V_41 -> V_46 ;
V_29 -> V_30 = V_29 -> V_47 -> V_30 ;
if ( V_45 -> V_48 -> V_49 ) {
int V_50 = V_41 -> V_50 ;
struct V_51 * V_52 ;
struct V_42 * V_53 ;
F_28 (dpcm, &fe->dpcm[stream].be_clients, list_be) {
V_53 = & V_52 -> V_54 ;
if ( F_29 ( V_43 ) != F_29 ( V_53 ) )
V_29 -> V_30 = F_29 ( V_53 ) ;
}
}
return 0 ;
}
static int F_30 ( struct V_2 * V_3 ,
struct V_4 * V_5 )
{
struct V_28 * V_29 = F_25 ( V_3 ) ;
F_31 ( V_3 ) ;
V_29 -> V_55 = 0 ;
V_29 -> V_31 . V_19 = 0 ;
F_14 ( V_3 , V_56 , 1 ) ;
return 0 ;
}
static int F_32 ( struct V_2 * V_3 ,
struct V_4 * V_5 )
{
struct V_28 * V_29 = F_25 ( V_3 ) ;
struct V_57 * V_58 = F_33 ( V_5 ) ;
F_34 ( V_3 ) ;
if ( V_29 -> V_55 )
F_35 ( V_58 , L_3 ,
F_36 ( V_3 ) , F_10 ( V_3 ) , V_29 -> V_55 ) ;
V_29 -> V_30 = 0 ;
V_29 -> V_31 . V_19 = 0 ;
return 0 ;
}
static int F_37 ( struct V_2 * V_3 )
{
F_14 ( V_3 , V_56 , 0 ) ;
return 0 ;
}
static int F_38 ( struct V_2 * V_3 )
{
return 0 ;
}
static int F_39 ( struct V_2 * V_3 )
{
struct V_6 * V_7 = F_3 ( V_3 ) ;
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
V_61 = F_10 ( V_3 ) ;
if ( V_61 < 0 || V_61 >= F_40 ( V_60 ) )
return - V_62 ;
V_19 = F_4 ( V_7 ) ? 0x1 : 0x2 ;
V_19 = V_19 << V_60 [ V_61 ] . V_17 ;
V_20 = V_60 [ V_61 ] . V_20 << V_60 [ V_61 ] . V_17 ;
F_11 ( V_3 , V_63 , V_20 , V_19 ) ;
return 0 ;
}
static int F_41 ( struct V_2 * V_3 )
{
struct V_6 * V_7 = F_3 ( V_3 ) ;
struct V_4 * V_5 = F_2 ( V_3 ) ;
struct V_28 * V_29 = F_25 ( V_3 ) ;
struct V_13 * V_14 = F_9 ( V_7 ) ;
T_1 V_30 = F_21 ( V_29 ) ;
T_1 V_20 ;
T_1 V_19 ;
int V_17 ;
int V_61 = F_10 ( V_3 ) ;
int V_64 ;
V_17 = ( V_61 % 4 ) * 8 ;
V_20 = 0x1F << V_17 ;
V_64 = 0 ;
if ( V_30 ) {
V_19 = 0 ;
V_64 = F_42 ( V_5 , V_3 ,
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
F_11 ( V_3 , V_65 , V_20 , V_19 ) ;
break;
case 1 :
F_11 ( V_3 , V_66 , V_20 , V_19 ) ;
break;
case 2 :
F_11 ( V_3 , V_67 , V_20 , V_19 ) ;
break;
}
return 0 ;
}
static int F_43 ( struct V_2 * V_3 )
{
struct V_28 * V_29 = F_25 ( V_3 ) ;
int V_64 ;
V_64 = F_26 ( V_3 ) ;
if ( V_64 < 0 )
return V_64 ;
F_14 ( V_3 , V_68 , 0x00010110 ) ;
F_14 ( V_3 , V_69 ,
F_44 ( V_3 , V_38 ) / 100 * 98 ) ;
if ( F_21 ( V_29 ) )
F_14 ( V_3 , V_70 , 1 ) ;
return 0 ;
}
static int F_45 ( struct V_2 * V_3 ,
struct V_4 * V_5 )
{
int V_64 ;
V_64 = F_30 ( V_3 , V_5 ) ;
if ( V_64 < 0 )
return V_64 ;
V_64 = F_39 ( V_3 ) ;
if ( V_64 < 0 )
return V_64 ;
V_64 = F_43 ( V_3 ) ;
if ( V_64 < 0 )
return V_64 ;
V_64 = F_41 ( V_3 ) ;
if ( V_64 < 0 )
return V_64 ;
return 0 ;
}
static int F_46 ( struct V_2 * V_3 ,
struct V_4 * V_5 )
{
int V_61 = F_10 ( V_3 ) ;
F_11 ( V_3 , V_71 , ( 1 << V_61 ) , ( 1 << V_61 ) ) ;
return F_37 ( V_3 ) ;
}
static int F_47 ( struct V_2 * V_3 ,
struct V_4 * V_5 )
{
int V_61 = F_10 ( V_3 ) ;
F_11 ( V_3 , V_71 , ( 1 << V_61 ) , 0 ) ;
return F_38 ( V_3 ) ;
}
static void F_48 ( struct V_2 * V_3 , int V_72 )
{
struct V_28 * V_29 = F_25 ( V_3 ) ;
T_1 V_73 , V_74 , V_75 ;
int V_76 = V_29 -> V_47 -> V_76 ;
int V_61 = F_10 ( V_3 ) ;
V_73 =
V_75 = F_49 ( V_61 ) ;
V_74 = 0x3300 ;
if ( ( V_76 <= 0 ) || ! V_72 ) {
V_73 = 0 ;
V_74 = 0 ;
}
F_14 ( V_3 , V_77 , V_74 ) ;
F_11 ( V_3 , V_78 , V_75 , V_73 ) ;
F_11 ( V_3 , V_79 , V_75 , V_73 ) ;
}
static void F_50 ( struct V_2 * V_3 )
{
T_1 V_19 = F_49 ( F_10 ( V_3 ) ) ;
F_11 ( V_3 , V_80 , V_19 , V_19 ) ;
F_11 ( V_3 , V_81 , V_19 , V_19 ) ;
}
static bool F_51 ( struct V_2 * V_3 )
{
T_1 V_19 = F_49 ( F_10 ( V_3 ) ) ;
bool V_64 = false ;
if ( ( F_44 ( V_3 , V_80 ) & V_19 ) ||
( F_44 ( V_3 , V_81 ) & V_19 ) ) {
struct V_28 * V_29 = F_25 ( V_3 ) ;
V_29 -> V_55 ++ ;
V_64 = true ;
}
F_50 ( V_3 ) ;
return V_64 ;
}
static int F_52 ( struct V_2 * V_3 )
{
struct V_6 * V_7 = F_3 ( V_3 ) ;
T_1 V_19 = F_53 ( V_7 ) ? 0x01 : 0x11 ;
F_14 ( V_3 , V_82 , V_19 ) ;
F_50 ( V_3 ) ;
F_37 ( V_3 ) ;
F_54 ( V_3 ) ;
return 0 ;
}
static int F_55 ( struct V_2 * V_3 )
{
F_56 ( V_3 ) ;
F_14 ( V_3 , V_82 , 0 ) ;
F_51 ( V_3 ) ;
return F_38 ( V_3 ) ;
}
static T_2 F_57 ( int V_76 , void * V_83 )
{
struct V_2 * V_3 = V_83 ;
struct V_6 * V_7 = F_3 ( V_3 ) ;
if ( ! V_7 )
return V_84 ;
if ( F_51 ( V_3 ) ) {
struct V_4 * V_5 = F_2 ( V_3 ) ;
struct V_28 * V_29 = F_25 ( V_3 ) ;
struct V_57 * V_58 = F_33 ( V_5 ) ;
F_58 ( V_58 , L_4 ,
F_36 ( V_3 ) , F_10 ( V_3 ) ) ;
F_55 ( V_3 ) ;
if ( V_29 -> V_55 < 1024 )
F_52 ( V_3 ) ;
else
F_35 ( V_58 , L_5 ) ;
}
return V_85 ;
}
static int F_59 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = F_2 ( V_3 ) ;
struct V_57 * V_58 = F_33 ( V_5 ) ;
struct V_6 * V_7 = F_3 ( V_3 ) ;
struct V_13 * V_14 = F_9 ( V_7 ) ;
struct V_28 * V_29 = F_25 ( V_3 ) ;
T_1 V_30 = F_21 ( V_29 ) ;
T_1 V_86 , V_87 ;
T_3 V_88 ;
int V_64 ;
if ( ! V_30 )
V_88 = 0 ;
else if ( V_30 > V_14 -> V_32 )
V_88 = 100 * V_30 / V_14 -> V_32 ;
else
V_88 = 100 * V_14 -> V_32 / V_30 ;
if ( V_88 > 600 ) {
F_60 ( V_58 , L_6 ) ;
return - V_89 ;
}
V_64 = F_26 ( V_3 ) ;
if ( V_64 < 0 )
return V_64 ;
V_86 = 0x00011110 ;
V_87 = 0x0 ;
if ( V_30 ) {
V_87 = 0x1 ;
if ( F_22 ( V_29 ) ) {
V_86 |= 0x1 ;
V_87 |= F_4 ( V_7 ) ?
( 0x1 << 24 ) : ( 0x1 << 25 ) ;
}
}
F_14 ( V_3 , V_68 , V_86 ) ;
F_14 ( V_3 , V_70 , V_87 ) ;
switch ( F_10 ( V_3 ) ) {
case 5 :
case 6 :
case 7 :
case 8 :
F_14 ( V_3 , V_90 , 0x02400000 ) ;
break;
default:
F_14 ( V_3 , V_90 , 0x01800000 ) ;
break;
}
F_14 ( V_3 , V_91 , 0x00100060 ) ;
return 0 ;
}
static int F_61 ( struct V_2 * V_3 )
{
struct V_6 * V_7 = F_3 ( V_3 ) ;
struct V_13 * V_14 = F_9 ( V_7 ) ;
struct V_28 * V_29 = F_25 ( V_3 ) ;
T_1 V_30 = F_21 ( V_29 ) ;
int V_64 ;
if ( V_30 )
V_64 = F_62 ( V_3 , V_7 ,
V_14 -> V_32 ,
V_30 ) ;
else
V_64 = F_63 ( V_3 , V_7 ) ;
return V_64 ;
}
static int F_64 ( struct V_2 * V_3 ,
struct V_4 * V_5 )
{
struct V_28 * V_29 = F_25 ( V_3 ) ;
struct V_57 * V_58 = F_33 ( V_5 ) ;
int V_76 = V_29 -> V_47 -> V_76 ;
int V_64 ;
if ( V_76 > 0 ) {
V_64 = F_65 ( V_58 , V_76 ,
F_57 ,
V_92 ,
F_66 ( V_58 ) , V_3 ) ;
if ( V_64 )
return V_64 ;
}
V_64 = F_67 ( V_5 ,
F_68 ( V_3 ) ,
V_29 -> V_47 -> V_93 ) ;
return V_64 ;
}
static int F_69 ( struct V_2 * V_3 ,
struct V_4 * V_5 )
{
F_70 ( F_68 ( V_3 ) ) ;
return 0 ;
}
static int F_71 ( struct V_2 * V_3 ,
struct V_4 * V_5 )
{
int V_64 ;
V_64 = F_30 ( V_3 , V_5 ) ;
if ( V_64 < 0 )
return V_64 ;
V_64 = F_59 ( V_3 ) ;
if ( V_64 < 0 )
return V_64 ;
V_64 = F_61 ( V_3 ) ;
if ( V_64 < 0 )
return V_64 ;
return 0 ;
}
static int F_72 ( struct V_2 * V_3 ,
struct V_4 * V_5 )
{
F_73 ( F_68 ( V_3 ) ) ;
return F_52 ( V_3 ) ;
}
static int F_74 ( struct V_2 * V_3 ,
struct V_4 * V_5 )
{
int V_64 ;
V_64 = F_55 ( V_3 ) ;
F_75 ( F_68 ( V_3 ) ) ;
return V_64 ;
}
static void F_76 ( struct V_2 * V_3 )
{
struct V_6 * V_7 = F_3 ( V_3 ) ;
struct V_13 * V_14 = F_9 ( V_7 ) ;
struct V_28 * V_29 = F_25 ( V_3 ) ;
T_1 V_30 = F_21 ( V_29 ) ;
T_1 V_34 ;
if ( ! V_14 )
return;
if ( ! V_30 )
V_30 = V_14 -> V_32 ;
V_34 = 0x0400000 / V_30 * V_14 -> V_32 ;
F_14 ( V_3 , V_38 , V_34 ) ;
}
static int F_77 ( struct V_2 * V_3 ,
struct V_44 * V_94 )
{
struct V_4 * V_5 = F_2 ( V_3 ) ;
struct V_6 * V_7 = F_3 ( V_3 ) ;
struct V_11 * V_12 = F_8 ( V_7 ) ;
struct V_28 * V_29 = F_25 ( V_3 ) ;
int V_64 ;
if ( F_18 ( V_5 ) )
return 0 ;
if ( ! F_13 ( V_12 ) )
return 0 ;
if ( F_53 ( V_7 ) )
return 0 ;
V_64 = F_78 ( V_3 , V_94 ,
F_4 ( V_7 ) ?
L_7 :
L_8 ,
F_76 ,
& V_29 -> V_95 , 1 ) ;
if ( V_64 < 0 )
return V_64 ;
V_64 = F_78 ( V_3 , V_94 ,
F_4 ( V_7 ) ?
L_9 :
L_10 ,
F_76 ,
& V_29 -> V_31 , 192000 ) ;
return V_64 ;
}
struct V_2 * F_79 ( struct V_4 * V_5 , int V_61 )
{
if ( F_80 ( V_61 < 0 || V_61 >= F_81 ( V_5 ) ) )
V_61 = 0 ;
return & ( (struct V_28 * ) ( V_5 -> V_29 ) + V_61 ) -> V_3 ;
}
static void F_82 ( struct V_96 * V_97 ,
const struct V_98 * V_99 ,
struct V_4 * V_5 )
{
struct V_100 * V_101 ;
struct V_100 * V_102 ;
struct V_103 * V_47 = F_83 ( V_5 ) ;
struct V_104 * V_105 ;
struct V_57 * V_58 = & V_97 -> V_58 ;
int V_106 , V_107 ;
if ( ! V_99 )
return;
V_101 = F_6 ( V_5 ) ;
if ( ! V_101 )
return;
V_106 = F_84 ( V_101 ) ;
if ( ! V_106 )
goto V_108;
V_105 = F_85 ( V_58 ,
sizeof( struct V_104 ) * V_106 ,
V_109 ) ;
if ( ! V_105 ) {
F_60 ( V_58 , L_11 ) ;
goto V_108;
}
V_47 -> V_105 = V_105 ;
V_47 -> V_110 = V_106 ;
V_107 = 0 ;
F_86 (src_node, np) {
V_105 [ V_107 ] . V_76 = F_87 ( V_102 , 0 ) ;
V_107 ++ ;
}
V_108:
F_88 ( V_101 ) ;
}
int F_89 ( struct V_96 * V_97 ,
const struct V_98 * V_99 ,
struct V_4 * V_5 )
{
struct V_103 * V_47 = F_83 ( V_5 ) ;
struct V_57 * V_58 = F_33 ( V_5 ) ;
struct V_28 * V_29 ;
struct V_111 * V_112 ;
struct V_113 * V_113 ;
char V_114 [ V_115 ] ;
int V_107 , V_106 , V_64 ;
V_112 = NULL ;
if ( F_18 ( V_5 ) )
V_112 = & V_116 ;
if ( F_90 ( V_5 ) )
V_112 = & V_117 ;
if ( ! V_112 ) {
F_60 ( V_58 , L_12 ) ;
return - V_62 ;
}
F_82 ( V_97 , V_99 , V_5 ) ;
V_106 = V_47 -> V_110 ;
if ( ! V_106 )
return 0 ;
V_29 = F_85 ( V_58 , sizeof( * V_29 ) * V_106 , V_109 ) ;
if ( ! V_29 ) {
F_60 ( V_58 , L_13 ) ;
return - V_118 ;
}
V_5 -> V_119 = V_106 ;
V_5 -> V_29 = V_29 ;
F_91 (src, priv, i) {
snprintf ( V_114 , V_115 , L_14 ,
V_120 , V_107 ) ;
V_113 = F_92 ( V_58 , V_114 ) ;
if ( F_93 ( V_113 ) )
return F_94 ( V_113 ) ;
V_29 -> V_47 = & V_47 -> V_105 [ V_107 ] ;
V_64 = F_95 ( & V_29 -> V_3 , V_112 , V_113 , V_121 , V_107 ) ;
if ( V_64 )
return V_64 ;
}
return 0 ;
}
void F_96 ( struct V_96 * V_97 ,
struct V_4 * V_5 )
{
struct V_28 * V_29 ;
int V_107 ;
F_91 (src, priv, i) {
F_97 ( & V_29 -> V_3 ) ;
}
}
