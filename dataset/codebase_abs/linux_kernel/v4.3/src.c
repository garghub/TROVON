static void F_1 ( struct V_1 * V_2 )
{
F_2 ( V_2 , V_3 , 0 ) ;
F_2 ( V_2 , V_3 , 1 ) ;
}
static void F_3 ( struct V_1 * V_2 , T_1 V_4 )
{
F_2 ( V_2 , V_5 , V_4 ) ;
}
static struct V_6 * F_4 ( struct V_7 * V_8 ,
struct V_1 * V_2 )
{
struct V_9 * V_10 = F_5 ( V_2 ) ;
int V_11 = F_6 ( V_8 ) ;
return F_7 ( F_8 ( V_10 ) ,
V_2 ,
V_11 ? L_1 : L_2 ) ;
}
int F_9 ( struct V_1 * V_12 ,
struct V_7 * V_8 ,
int V_13 )
{
struct V_14 * V_15 = F_10 ( V_8 ) ;
int V_16 = F_11 ( V_12 ) ;
F_12 ( V_12 , V_17 , ( 1 << V_16 ) ,
! V_13 << V_16 ) ;
if ( F_13 ( V_12 ) ) {
int V_18 = - 1 ;
switch ( V_16 ) {
case 1 :
V_18 = 0 ;
break;
case 2 :
V_18 = 2 ;
break;
case 4 :
V_18 = 16 ;
break;
}
if ( V_18 >= 0 )
F_12 ( V_12 , V_19 ,
0x3 << V_18 ,
F_14 ( V_15 ) ?
0x2 << V_18 : 0x1 << V_18 ) ;
}
if ( V_13 ) {
T_1 V_20 = F_15 ( V_12 , V_8 ) ;
F_2 ( V_12 , V_21 ,
F_16 ( V_12 , V_8 ) ) ;
F_2 ( V_12 , V_22 , 1 ) ;
F_2 ( V_12 , V_23 , 0x1 ) ;
F_2 ( V_12 , V_24 , V_20 ) ;
}
return 0 ;
}
int F_17 ( struct V_1 * V_12 ,
struct V_7 * V_8 )
{
F_2 ( V_12 , V_23 , 0 ) ;
return 0 ;
}
int F_18 ( struct V_1 * V_12 )
{
struct V_9 * V_10 = F_5 ( V_12 ) ;
if ( F_19 ( V_10 ) )
return 0 ;
F_2 ( V_12 , V_25 ,
F_20 ( V_12 ) ?
0x0e000000 : 0x0f000000 ) ;
return 0 ;
}
int F_21 ( struct V_1 * V_12 )
{
struct V_9 * V_10 = F_5 ( V_12 ) ;
if ( F_19 ( V_10 ) )
return 0 ;
F_2 ( V_12 , V_25 , 0x00000000 ) ;
return 0 ;
}
static T_1 F_22 ( struct V_7 * V_8 ,
struct V_26 * V_27 )
{
struct V_28 * V_29 = F_23 ( V_8 ) ;
T_1 V_30 ;
if ( ! V_29 )
return 0 ;
if ( ! F_24 ( V_27 ) )
return V_27 -> V_30 ;
V_30 = V_27 -> V_31 . V_20 ;
if ( ! V_30 )
V_30 = V_27 -> V_30 ;
if ( ! V_30 )
V_30 = V_29 -> V_32 ;
return V_30 ;
}
unsigned int F_25 ( struct V_9 * V_10 ,
struct V_7 * V_8 ,
struct V_28 * V_29 )
{
struct V_1 * V_33 = F_26 ( V_8 ) ;
struct V_26 * V_27 ;
unsigned int V_32 = 0 ;
if ( V_33 ) {
V_27 = F_27 ( V_33 ) ;
V_32 = F_22 ( V_8 , V_27 ) ;
}
if ( ! V_32 )
V_32 = V_29 -> V_32 ;
return V_32 ;
}
static int F_28 ( struct V_1 * V_2 ,
struct V_7 * V_8 )
{
struct V_28 * V_29 = F_23 ( V_8 ) ;
struct V_26 * V_27 = F_27 ( V_2 ) ;
T_1 V_30 = F_22 ( V_8 , V_27 ) ;
T_1 V_34 = 0 ;
if ( V_30 )
V_34 = 0x0400000 / V_30 * V_29 -> V_32 ;
F_2 ( V_2 , V_35 , F_16 ( V_2 , V_8 ) ) ;
if ( V_34 ) {
F_2 ( V_2 , V_36 , 1 ) ;
F_2 ( V_2 , V_37 , V_34 ) ;
}
F_2 ( V_2 , V_38 , 1 ) ;
return 0 ;
}
static int F_29 ( struct V_1 * V_2 ,
struct V_7 * V_8 ,
struct V_39 * V_40 ,
struct V_41 * V_42 )
{
struct V_26 * V_27 = F_27 ( V_2 ) ;
struct V_43 * V_44 = V_40 -> V_45 ;
V_27 -> V_30 = V_27 -> V_46 -> V_30 ;
if ( V_44 -> V_47 -> V_48 ) {
int V_49 = V_40 -> V_49 ;
struct V_50 * V_51 ;
struct V_41 * V_52 ;
F_30 (dpcm, &fe->dpcm[stream].be_clients, list_be) {
V_52 = & V_51 -> V_53 ;
if ( F_31 ( V_42 ) != F_31 ( V_52 ) )
V_27 -> V_30 = F_31 ( V_52 ) ;
}
}
return 0 ;
}
static int F_32 ( struct V_1 * V_2 ,
struct V_9 * V_10 )
{
struct V_26 * V_27 = F_27 ( V_2 ) ;
F_33 ( V_2 ) ;
F_1 ( V_2 ) ;
F_34 ( V_2 ) ;
V_27 -> V_54 = 0 ;
V_27 -> V_31 . V_20 = 0 ;
return 0 ;
}
static int F_35 ( struct V_1 * V_2 ,
struct V_7 * V_8 ,
struct V_9 * V_10 )
{
struct V_26 * V_27 = F_27 ( V_2 ) ;
struct V_55 * V_56 = F_36 ( V_10 ) ;
F_37 ( V_2 ) ;
if ( V_27 -> V_54 )
F_38 ( V_56 , L_3 ,
F_39 ( V_2 ) , F_11 ( V_2 ) , V_27 -> V_54 ) ;
V_27 -> V_30 = 0 ;
V_27 -> V_31 . V_20 = 0 ;
return 0 ;
}
static int F_40 ( struct V_1 * V_2 )
{
F_41 ( V_2 ) ;
return 0 ;
}
static int F_42 ( struct V_1 * V_2 )
{
return 0 ;
}
static int F_43 ( struct V_7 * V_8 ,
struct V_1 * V_2 )
{
struct V_57 {
T_1 V_58 ;
int V_18 ;
} V_59 [] = {
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
T_1 V_58 ;
T_1 V_20 ;
int V_60 ;
V_60 = F_11 ( V_2 ) ;
if ( V_60 < 0 || V_60 >= F_44 ( V_59 ) )
return - V_61 ;
V_20 = F_6 ( V_8 ) ? 0x1 : 0x2 ;
V_20 = V_20 << V_59 [ V_60 ] . V_18 ;
V_58 = V_59 [ V_60 ] . V_58 << V_59 [ V_60 ] . V_18 ;
F_12 ( V_2 , V_62 , V_58 , V_20 ) ;
return 0 ;
}
static int F_45 ( struct V_7 * V_8 ,
struct V_1 * V_2 )
{
struct V_9 * V_10 = F_5 ( V_2 ) ;
struct V_26 * V_27 = F_27 ( V_2 ) ;
struct V_28 * V_29 = F_23 ( V_8 ) ;
T_1 V_30 = F_22 ( V_8 , V_27 ) ;
T_1 V_58 ;
T_1 V_20 ;
int V_18 ;
int V_60 = F_11 ( V_2 ) ;
int V_63 ;
V_18 = ( V_60 % 4 ) * 8 ;
V_58 = 0x1F << V_18 ;
V_63 = 0 ;
if ( V_30 ) {
V_20 = 0 ;
V_63 = F_46 ( V_10 , V_2 ,
V_29 -> V_32 ,
V_30 ) ;
} else if ( 8 == V_60 ) {
V_20 = V_60 << V_18 ;
} else {
V_20 = ( V_60 + 1 ) << V_18 ;
}
if ( V_63 < 0 )
return V_63 ;
switch ( V_60 / 4 ) {
case 0 :
F_12 ( V_2 , V_64 , V_58 , V_20 ) ;
break;
case 1 :
F_12 ( V_2 , V_65 , V_58 , V_20 ) ;
break;
case 2 :
F_12 ( V_2 , V_66 , V_58 , V_20 ) ;
break;
}
return 0 ;
}
static int F_47 ( struct V_1 * V_2 ,
struct V_7 * V_8 )
{
struct V_26 * V_27 = F_27 ( V_2 ) ;
int V_63 ;
V_63 = F_28 ( V_2 , V_8 ) ;
if ( V_63 < 0 )
return V_63 ;
F_2 ( V_2 , V_67 , 0x00010110 ) ;
F_2 ( V_2 , V_68 ,
F_48 ( V_2 , V_37 ) / 100 * 98 ) ;
if ( F_22 ( V_8 , V_27 ) )
F_2 ( V_2 , V_69 , 1 ) ;
return 0 ;
}
static int F_49 ( struct V_1 * V_2 ,
struct V_7 * V_8 ,
struct V_9 * V_10 )
{
int V_63 ;
V_63 = F_32 ( V_2 , V_10 ) ;
if ( V_63 < 0 )
return V_63 ;
V_63 = F_43 ( V_8 , V_2 ) ;
if ( V_63 < 0 )
return V_63 ;
V_63 = F_47 ( V_2 , V_8 ) ;
if ( V_63 < 0 )
return V_63 ;
V_63 = F_45 ( V_8 , V_2 ) ;
if ( V_63 < 0 )
return V_63 ;
return 0 ;
}
static int F_50 ( struct V_1 * V_2 ,
struct V_7 * V_8 ,
struct V_9 * V_10 )
{
int V_60 = F_11 ( V_2 ) ;
F_12 ( V_2 , V_70 , ( 1 << V_60 ) , ( 1 << V_60 ) ) ;
return F_40 ( V_2 ) ;
}
static int F_51 ( struct V_1 * V_2 ,
struct V_7 * V_8 ,
struct V_9 * V_10 )
{
int V_60 = F_11 ( V_2 ) ;
F_12 ( V_2 , V_70 , ( 1 << V_60 ) , 0 ) ;
return F_42 ( V_2 ) ;
}
static void F_52 ( struct V_1 * V_2 , int V_4 )
{
struct V_26 * V_27 = F_27 ( V_2 ) ;
T_1 V_71 , V_72 , V_73 ;
int V_74 = V_27 -> V_46 -> V_74 ;
int V_60 = F_11 ( V_2 ) ;
V_71 =
V_73 = F_53 ( V_60 ) ;
V_72 = 0x3300 ;
if ( ( V_74 <= 0 ) || ! V_4 ) {
V_71 = 0 ;
V_72 = 0 ;
}
if ( F_24 ( V_27 ) )
V_71 = V_71 & 0xffff ;
F_2 ( V_2 , V_75 , V_72 ) ;
F_12 ( V_2 , V_76 , V_73 , V_71 ) ;
F_12 ( V_2 , V_77 , V_73 , V_71 ) ;
}
static void F_54 ( struct V_1 * V_2 )
{
T_1 V_20 = F_53 ( F_11 ( V_2 ) ) ;
F_12 ( V_2 , V_78 , V_20 , V_20 ) ;
F_12 ( V_2 , V_79 , V_20 , V_20 ) ;
}
static bool F_55 ( struct V_1 * V_2 )
{
struct V_26 * V_27 = F_27 ( V_2 ) ;
T_1 V_80 , V_81 ;
bool V_63 = false ;
V_80 = V_81 = F_53 ( F_11 ( V_2 ) ) ;
if ( F_24 ( V_27 ) )
V_80 = V_80 & 0xffff ;
if ( ( F_48 ( V_2 , V_78 ) & V_80 ) ||
( F_48 ( V_2 , V_79 ) & V_81 ) ) {
struct V_26 * V_27 = F_27 ( V_2 ) ;
V_27 -> V_54 ++ ;
V_63 = true ;
}
F_54 ( V_2 ) ;
return V_63 ;
}
static int F_56 ( struct V_1 * V_2 ,
struct V_7 * V_8 )
{
struct V_26 * V_27 = F_27 ( V_2 ) ;
T_1 V_20 ;
V_20 = F_15 ( V_2 , V_8 ) ;
F_2 ( V_2 , V_82 , V_20 ) ;
V_20 = ( F_57 ( V_8 ) && ! F_24 ( V_27 ) ) ?
0x01 : 0x11 ;
F_2 ( V_2 , V_83 , V_20 ) ;
F_54 ( V_2 ) ;
F_40 ( V_2 ) ;
F_58 ( V_2 ) ;
return 0 ;
}
static int F_59 ( struct V_1 * V_2 )
{
F_60 ( V_2 ) ;
F_2 ( V_2 , V_83 , 0 ) ;
F_55 ( V_2 ) ;
return F_42 ( V_2 ) ;
}
static void F_61 ( struct V_1 * V_2 ,
struct V_7 * V_8 )
{
struct V_9 * V_10 = F_5 ( V_2 ) ;
F_62 ( & V_10 -> V_84 ) ;
if ( ! F_63 ( V_8 ) )
goto V_85;
if ( F_55 ( V_2 ) ) {
struct V_9 * V_10 = F_5 ( V_2 ) ;
struct V_26 * V_27 = F_27 ( V_2 ) ;
struct V_55 * V_56 = F_36 ( V_10 ) ;
F_64 ( V_56 , L_4 ,
F_39 ( V_2 ) , F_11 ( V_2 ) ) ;
F_59 ( V_2 ) ;
if ( V_27 -> V_54 < 1024 )
F_56 ( V_2 , V_8 ) ;
else
F_38 ( V_56 , L_5 ) ;
}
V_85:
F_65 ( & V_10 -> V_84 ) ;
}
static T_2 F_66 ( int V_74 , void * V_86 )
{
struct V_1 * V_2 = V_86 ;
F_67 ( V_2 , F_61 ) ;
return V_87 ;
}
static int F_68 ( struct V_1 * V_2 ,
struct V_7 * V_8 )
{
struct V_9 * V_10 = F_5 ( V_2 ) ;
struct V_55 * V_56 = F_36 ( V_10 ) ;
struct V_28 * V_29 = F_23 ( V_8 ) ;
struct V_26 * V_27 = F_27 ( V_2 ) ;
T_1 V_30 = F_22 ( V_8 , V_27 ) ;
T_1 V_88 , V_89 ;
T_3 V_90 ;
int V_63 ;
if ( ! V_30 )
V_90 = 0 ;
else if ( V_30 > V_29 -> V_32 )
V_90 = 100 * V_30 / V_29 -> V_32 ;
else
V_90 = 100 * V_29 -> V_32 / V_30 ;
if ( V_90 > 600 ) {
F_69 ( V_56 , L_6 ) ;
return - V_91 ;
}
V_63 = F_28 ( V_2 , V_8 ) ;
if ( V_63 < 0 )
return V_63 ;
V_88 = 0x00011110 ;
V_89 = 0x0 ;
if ( V_30 ) {
V_89 = 0x1 ;
if ( F_24 ( V_27 ) ) {
V_88 |= 0x1 ;
V_89 |= F_6 ( V_8 ) ?
( 0x1 << 24 ) : ( 0x1 << 25 ) ;
}
}
F_2 ( V_2 , V_67 , V_88 ) ;
F_2 ( V_2 , V_69 , V_89 ) ;
switch ( F_11 ( V_2 ) ) {
case 5 :
case 6 :
case 7 :
case 8 :
F_2 ( V_2 , V_92 , 0x02400000 ) ;
break;
default:
F_2 ( V_2 , V_92 , 0x01800000 ) ;
break;
}
F_2 ( V_2 , V_93 , 0x00100060 ) ;
return 0 ;
}
static int F_70 ( struct V_7 * V_8 ,
struct V_1 * V_2 )
{
struct V_28 * V_29 = F_23 ( V_8 ) ;
struct V_26 * V_27 = F_27 ( V_2 ) ;
T_1 V_30 = F_22 ( V_8 , V_27 ) ;
int V_63 ;
if ( V_30 )
V_63 = F_71 ( V_2 , V_8 ,
V_29 -> V_32 ,
V_30 ) ;
else
V_63 = F_72 ( V_2 , V_8 ) ;
return V_63 ;
}
static int F_73 ( struct V_1 * V_2 ,
struct V_7 * V_8 ,
struct V_9 * V_10 )
{
struct V_26 * V_27 = F_27 ( V_2 ) ;
struct V_55 * V_56 = F_36 ( V_10 ) ;
int V_74 = V_27 -> V_46 -> V_74 ;
int V_63 ;
if ( V_74 > 0 ) {
V_63 = F_74 ( V_56 , V_74 ,
F_66 ,
V_94 ,
F_75 ( V_56 ) , V_2 ) ;
if ( V_63 )
return V_63 ;
}
V_63 = F_76 ( V_8 ,
F_77 ( V_2 ) ,
V_27 -> V_46 -> V_95 ) ;
return V_63 ;
}
static int F_78 ( struct V_1 * V_2 ,
struct V_7 * V_8 ,
struct V_9 * V_10 )
{
F_79 ( V_8 , F_77 ( V_2 ) ) ;
return 0 ;
}
static int F_80 ( struct V_1 * V_2 ,
struct V_7 * V_8 ,
struct V_9 * V_10 )
{
int V_63 ;
V_63 = F_32 ( V_2 , V_10 ) ;
if ( V_63 < 0 )
return V_63 ;
V_63 = F_68 ( V_2 , V_8 ) ;
if ( V_63 < 0 )
return V_63 ;
V_63 = F_70 ( V_8 , V_2 ) ;
if ( V_63 < 0 )
return V_63 ;
return 0 ;
}
static int F_81 ( struct V_1 * V_2 ,
struct V_7 * V_8 ,
struct V_9 * V_10 )
{
F_82 ( V_8 , F_77 ( V_2 ) ) ;
return F_56 ( V_2 , V_8 ) ;
}
static int F_83 ( struct V_1 * V_2 ,
struct V_7 * V_8 ,
struct V_9 * V_10 )
{
int V_63 ;
V_63 = F_59 ( V_2 ) ;
F_84 ( V_8 , F_77 ( V_2 ) ) ;
return V_63 ;
}
static void F_85 ( struct V_7 * V_8 ,
struct V_1 * V_2 )
{
struct V_28 * V_29 = F_23 ( V_8 ) ;
struct V_26 * V_27 = F_27 ( V_2 ) ;
T_1 V_30 = F_22 ( V_8 , V_27 ) ;
T_1 V_34 ;
if ( ! V_29 )
return;
if ( ! V_30 )
V_30 = V_29 -> V_32 ;
V_34 = 0x0400000 / V_30 * V_29 -> V_32 ;
F_2 ( V_2 , V_37 , V_34 ) ;
}
static int F_86 ( struct V_1 * V_2 ,
struct V_7 * V_8 ,
struct V_43 * V_96 )
{
struct V_9 * V_10 = F_5 ( V_2 ) ;
struct V_14 * V_15 = F_10 ( V_8 ) ;
struct V_26 * V_27 = F_27 ( V_2 ) ;
int V_63 ;
if ( F_19 ( V_10 ) )
return 0 ;
if ( ! F_14 ( V_15 ) )
return 0 ;
V_63 = F_87 ( V_2 , V_8 , V_96 ,
F_6 ( V_8 ) ?
L_7 :
L_8 ,
F_85 ,
& V_27 -> V_97 , 1 ) ;
if ( V_63 < 0 )
return V_63 ;
V_63 = F_87 ( V_2 , V_8 , V_96 ,
F_6 ( V_8 ) ?
L_9 :
L_10 ,
F_85 ,
& V_27 -> V_31 , 192000 ) ;
return V_63 ;
}
struct V_1 * F_88 ( struct V_9 * V_10 , int V_60 )
{
if ( F_89 ( V_60 < 0 || V_60 >= F_90 ( V_10 ) ) )
V_60 = 0 ;
return & ( (struct V_26 * ) ( V_10 -> V_27 ) + V_60 ) -> V_2 ;
}
static void F_91 ( struct V_98 * V_99 ,
const struct V_100 * V_101 ,
struct V_9 * V_10 )
{
struct V_102 * V_103 ;
struct V_102 * V_104 ;
struct V_105 * V_46 = F_92 ( V_10 ) ;
struct V_106 * V_107 ;
struct V_55 * V_56 = & V_99 -> V_56 ;
int V_108 , V_109 ;
if ( ! V_101 )
return;
V_103 = F_8 ( V_10 ) ;
if ( ! V_103 )
return;
V_108 = F_93 ( V_103 ) ;
if ( ! V_108 )
goto V_110;
V_107 = F_94 ( V_56 ,
sizeof( struct V_106 ) * V_108 ,
V_111 ) ;
if ( ! V_107 ) {
F_69 ( V_56 , L_11 ) ;
goto V_110;
}
V_46 -> V_107 = V_107 ;
V_46 -> V_112 = V_108 ;
V_109 = 0 ;
F_95 (src_node, np) {
V_107 [ V_109 ] . V_74 = F_96 ( V_104 , 0 ) ;
V_109 ++ ;
}
V_110:
F_97 ( V_103 ) ;
}
int F_98 ( struct V_98 * V_99 ,
const struct V_100 * V_101 ,
struct V_9 * V_10 )
{
struct V_105 * V_46 = F_92 ( V_10 ) ;
struct V_55 * V_56 = F_36 ( V_10 ) ;
struct V_26 * V_27 ;
struct V_113 * V_114 ;
struct V_115 * V_115 ;
char V_116 [ V_117 ] ;
int V_109 , V_108 , V_63 ;
V_114 = NULL ;
if ( F_19 ( V_10 ) )
V_114 = & V_118 ;
if ( F_99 ( V_10 ) )
V_114 = & V_119 ;
if ( ! V_114 ) {
F_69 ( V_56 , L_12 ) ;
return - V_61 ;
}
F_91 ( V_99 , V_101 , V_10 ) ;
V_108 = V_46 -> V_112 ;
if ( ! V_108 )
return 0 ;
V_27 = F_94 ( V_56 , sizeof( * V_27 ) * V_108 , V_111 ) ;
if ( ! V_27 )
return - V_120 ;
V_10 -> V_121 = V_108 ;
V_10 -> V_27 = V_27 ;
F_100 (src, priv, i) {
snprintf ( V_116 , V_117 , L_13 ,
V_122 , V_109 ) ;
V_115 = F_101 ( V_56 , V_116 ) ;
if ( F_102 ( V_115 ) )
return F_103 ( V_115 ) ;
V_27 -> V_46 = & V_46 -> V_107 [ V_109 ] ;
V_63 = F_104 ( V_10 , & V_27 -> V_2 , V_114 , V_115 , V_123 , V_109 ) ;
if ( V_63 )
return V_63 ;
}
return 0 ;
}
void F_105 ( struct V_98 * V_99 ,
struct V_9 * V_10 )
{
struct V_26 * V_27 ;
int V_109 ;
F_100 (src, priv, i) {
F_106 ( & V_27 -> V_2 ) ;
}
}
