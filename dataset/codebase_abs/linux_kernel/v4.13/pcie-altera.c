static inline void F_1 ( struct V_1 * V_2 , const T_1 V_3 ,
const T_1 V_4 )
{
F_2 ( V_3 , V_2 -> V_5 + V_4 ) ;
}
static inline T_1 F_3 ( struct V_1 * V_2 , const T_1 V_4 )
{
return F_4 ( V_2 -> V_5 + V_4 ) ;
}
static bool F_5 ( struct V_1 * V_2 )
{
return ! ! ( ( F_3 ( V_2 , V_6 ) & V_7 ) == V_8 ) ;
}
static bool F_6 ( struct V_9 * V_10 , unsigned int V_11 ,
int V_12 )
{
if ( F_7 ( V_10 ) && ( V_11 == 0 ) &&
( V_12 == V_13 ) )
return true ;
return false ;
}
static void F_8 ( struct V_1 * V_2 ,
struct V_14 * V_15 )
{
F_1 ( V_2 , V_15 -> V_16 , V_17 ) ;
F_1 ( V_2 , V_15 -> V_18 , V_19 ) ;
F_1 ( V_2 , V_15 -> V_20 , V_21 ) ;
}
static bool F_9 ( struct V_1 * V_2 ,
struct V_9 * V_10 , int V_22 )
{
if ( V_10 -> V_23 != V_2 -> V_24 ) {
if ( ! F_5 ( V_2 ) )
return false ;
}
if ( V_10 -> V_23 == V_2 -> V_24 && V_22 > 0 )
return false ;
return true ;
}
static int F_10 ( struct V_1 * V_2 , T_1 * V_3 )
{
int V_25 ;
bool V_26 = 0 ;
T_1 V_20 ;
T_1 V_16 , V_18 ;
T_1 V_27 = 1 ;
for ( V_25 = 0 ; V_25 < V_28 ; V_25 ++ ) {
V_20 = F_3 ( V_2 , V_29 ) ;
if ( ( V_20 & V_30 ) || ( V_20 & V_31 ) || V_26 ) {
V_16 = F_3 ( V_2 , V_32 ) ;
V_18 = F_3 ( V_2 , V_33 ) ;
if ( V_20 & V_30 ) {
V_26 = true ;
V_27 = F_11 ( V_18 ) ;
}
if ( V_20 & V_31 ) {
if ( V_27 )
return V_34 ;
if ( V_3 )
* V_3 = V_16 ;
return V_35 ;
}
}
F_12 ( 5 ) ;
}
return V_34 ;
}
static void F_13 ( struct V_1 * V_2 , T_1 * V_36 ,
T_1 V_37 , bool V_38 )
{
struct V_14 V_15 ;
V_15 . V_16 = V_36 [ 0 ] ;
V_15 . V_18 = V_36 [ 1 ] ;
V_15 . V_20 = V_39 ;
F_8 ( V_2 , & V_15 ) ;
if ( V_38 ) {
V_15 . V_16 = V_36 [ 2 ] ;
V_15 . V_18 = 0 ;
V_15 . V_20 = 0 ;
F_8 ( V_2 , & V_15 ) ;
V_15 . V_16 = V_37 ;
V_15 . V_18 = 0 ;
} else {
V_15 . V_16 = V_36 [ 2 ] ;
V_15 . V_18 = V_37 ;
}
V_15 . V_20 = V_40 ;
F_8 ( V_2 , & V_15 ) ;
}
static int F_14 ( struct V_1 * V_2 , T_2 V_10 , T_1 V_11 ,
int V_41 , T_2 V_42 , T_1 * V_3 )
{
T_1 V_36 [ V_43 ] ;
V_36 [ 0 ] = F_15 ( V_2 , V_10 ) ;
V_36 [ 1 ] = F_16 ( V_2 , V_44 , V_42 ) ;
V_36 [ 2 ] = F_17 ( V_10 , V_11 , V_41 ) ;
F_13 ( V_2 , V_36 , 0 , false ) ;
return F_10 ( V_2 , V_3 ) ;
}
static int F_18 ( struct V_1 * V_2 , T_2 V_10 , T_1 V_11 ,
int V_41 , T_2 V_42 , T_1 V_3 )
{
T_1 V_36 [ V_43 ] ;
int V_45 ;
V_36 [ 0 ] = F_19 ( V_2 , V_10 ) ;
V_36 [ 1 ] = F_16 ( V_2 , V_46 , V_42 ) ;
V_36 [ 2 ] = F_17 ( V_10 , V_11 , V_41 ) ;
if ( ( V_41 & 0x7 ) == 0 )
F_13 ( V_2 , V_36 , V_3 , true ) ;
else
F_13 ( V_2 , V_36 , V_3 , false ) ;
V_45 = F_10 ( V_2 , NULL ) ;
if ( V_45 != V_35 )
return V_45 ;
if ( ( V_10 == V_2 -> V_24 ) && ( V_41 == V_47 ) )
V_2 -> V_24 = ( T_2 ) ( V_3 ) ;
return V_35 ;
}
static int F_20 ( struct V_1 * V_2 , T_2 V_48 ,
unsigned int V_11 , int V_41 , int V_49 ,
T_1 * V_3 )
{
int V_45 ;
T_1 V_37 ;
T_2 V_42 ;
switch ( V_49 ) {
case 1 :
V_42 = 1 << ( V_41 & 3 ) ;
break;
case 2 :
V_42 = 3 << ( V_41 & 3 ) ;
break;
default:
V_42 = 0xf ;
break;
}
V_45 = F_14 ( V_2 , V_48 , V_11 ,
( V_41 & ~ V_50 ) , V_42 , & V_37 ) ;
if ( V_45 != V_35 )
return V_45 ;
switch ( V_49 ) {
case 1 :
* V_3 = ( V_37 >> ( 8 * ( V_41 & 0x3 ) ) ) & 0xff ;
break;
case 2 :
* V_3 = ( V_37 >> ( 8 * ( V_41 & 0x2 ) ) ) & 0xffff ;
break;
default:
* V_3 = V_37 ;
break;
}
return V_35 ;
}
static int F_21 ( struct V_1 * V_2 , T_2 V_48 ,
unsigned int V_11 , int V_41 , int V_49 ,
T_1 V_3 )
{
T_1 V_51 ;
T_1 V_52 = 8 * ( V_41 & 3 ) ;
T_2 V_42 ;
switch ( V_49 ) {
case 1 :
V_51 = ( V_3 & 0xff ) << V_52 ;
V_42 = 1 << ( V_41 & 3 ) ;
break;
case 2 :
V_51 = ( V_3 & 0xffff ) << V_52 ;
V_42 = 3 << ( V_41 & 3 ) ;
break;
default:
V_51 = V_3 ;
V_42 = 0xf ;
break;
}
return F_18 ( V_2 , V_48 , V_11 , ( V_41 & ~ V_50 ) ,
V_42 , V_51 ) ;
}
static int F_22 ( struct V_9 * V_10 , unsigned int V_11 ,
int V_41 , int V_49 , T_1 * V_3 )
{
struct V_1 * V_2 = V_10 -> V_53 ;
if ( F_6 ( V_10 , V_11 , V_41 ) )
return V_54 ;
if ( ! F_9 ( V_2 , V_10 , F_23 ( V_11 ) ) ) {
* V_3 = 0xffffffff ;
return V_34 ;
}
return F_20 ( V_2 , V_10 -> V_23 , V_11 , V_41 , V_49 ,
V_3 ) ;
}
static int F_24 ( struct V_9 * V_10 , unsigned int V_11 ,
int V_41 , int V_49 , T_1 V_3 )
{
struct V_1 * V_2 = V_10 -> V_53 ;
if ( F_6 ( V_10 , V_11 , V_41 ) )
return V_54 ;
if ( ! F_9 ( V_2 , V_10 , F_23 ( V_11 ) ) )
return V_34 ;
return F_21 ( V_2 , V_10 -> V_23 , V_11 , V_41 , V_49 ,
V_3 ) ;
}
static int F_25 ( struct V_1 * V_2 , T_2 V_48 ,
unsigned int V_11 , int V_12 , T_3 * V_3 )
{
T_1 V_37 ;
int V_45 ;
V_45 = F_20 ( V_2 , V_48 , V_11 ,
V_55 + V_12 , sizeof( * V_3 ) ,
& V_37 ) ;
* V_3 = V_37 ;
return V_45 ;
}
static int F_26 ( struct V_1 * V_2 , T_2 V_48 ,
unsigned int V_11 , int V_12 , T_3 V_3 )
{
return F_21 ( V_2 , V_48 , V_11 ,
V_55 + V_12 , sizeof( V_3 ) ,
V_3 ) ;
}
static void F_27 ( struct V_1 * V_2 )
{
struct V_56 * V_22 = & V_2 -> V_57 -> V_22 ;
T_3 V_58 ;
unsigned long V_59 ;
V_59 = V_60 ;
for (; ; ) {
F_25 ( V_2 , V_2 -> V_24 , V_61 ,
V_62 , & V_58 ) ;
if ( ! ( V_58 & V_63 ) )
break;
if ( F_28 ( V_60 , V_59 + V_64 ) ) {
F_29 ( V_22 , L_1 ) ;
break;
}
F_12 ( 100 ) ;
}
V_59 = V_60 ;
for (; ; ) {
if ( F_5 ( V_2 ) )
break;
if ( F_28 ( V_60 , V_59 + V_65 ) ) {
F_29 ( V_22 , L_2 ) ;
break;
}
F_12 ( 100 ) ;
}
}
static void F_30 ( struct V_1 * V_2 )
{
T_3 V_66 , V_67 , V_68 ;
if ( ! F_5 ( V_2 ) )
return;
F_25 ( V_2 , V_2 -> V_24 , V_61 , V_69 ,
& V_66 ) ;
if ( ( V_66 & V_70 ) <= V_71 )
return;
F_25 ( V_2 , V_2 -> V_24 , V_61 , V_62 ,
& V_67 ) ;
if ( ( V_67 & V_72 ) == V_73 ) {
F_25 ( V_2 , V_2 -> V_24 , V_61 ,
V_74 , & V_68 ) ;
V_68 |= V_75 ;
F_26 ( V_2 , V_2 -> V_24 , V_61 ,
V_74 , V_68 ) ;
F_27 ( V_2 ) ;
}
}
static int F_31 ( struct V_76 * V_77 , unsigned int V_78 ,
T_4 V_79 )
{
F_32 ( V_78 , & V_80 , V_81 ) ;
F_33 ( V_78 , V_77 -> V_82 ) ;
return 0 ;
}
static void F_34 ( struct V_83 * V_84 )
{
struct V_85 * V_86 = F_35 ( V_84 ) ;
struct V_1 * V_2 ;
struct V_56 * V_22 ;
unsigned long V_87 ;
T_1 V_88 ;
T_1 V_89 ;
F_36 ( V_86 , V_84 ) ;
V_2 = F_37 ( V_84 ) ;
V_22 = & V_2 -> V_57 -> V_22 ;
while ( ( V_87 = F_3 ( V_2 , V_90 )
& V_91 ) != 0 ) {
F_38 (bit, &status, INTX_NUM) {
F_1 ( V_2 , 1 << V_88 , V_90 ) ;
V_89 = F_39 ( V_2 -> V_76 , V_88 + 1 ) ;
if ( V_89 )
F_40 ( V_89 ) ;
else
F_29 ( V_22 , L_3 , V_88 ) ;
}
}
F_41 ( V_86 , V_84 ) ;
}
static int F_42 ( struct V_1 * V_2 )
{
int V_92 , V_93 = 0 ;
struct V_56 * V_22 = & V_2 -> V_57 -> V_22 ;
struct V_94 * V_95 = V_22 -> V_96 ;
struct V_97 * V_98 ;
V_92 = F_43 ( V_95 , 0 , 0xff , & V_2 -> V_99 ,
NULL ) ;
if ( V_92 )
return V_92 ;
V_92 = F_44 ( V_22 , & V_2 -> V_99 ) ;
if ( V_92 )
goto V_100;
F_45 (win, &pcie->resources) {
struct V_101 * V_102 = V_98 -> V_102 ;
if ( F_46 ( V_102 ) == V_103 )
V_93 |= ! ( V_102 -> V_104 & V_105 ) ;
}
if ( V_93 )
return 0 ;
F_29 ( V_22 , L_4 ) ;
V_92 = - V_106 ;
V_100:
F_47 ( & V_2 -> V_99 ) ;
return V_92 ;
}
static int F_48 ( struct V_1 * V_2 )
{
struct V_56 * V_22 = & V_2 -> V_57 -> V_22 ;
struct V_94 * V_107 = V_22 -> V_96 ;
V_2 -> V_76 = F_49 ( V_107 , V_108 + 1 ,
& V_109 , V_2 ) ;
if ( ! V_2 -> V_76 ) {
F_29 ( V_22 , L_5 ) ;
return - V_110 ;
}
return 0 ;
}
static int F_50 ( struct V_1 * V_2 )
{
struct V_56 * V_22 = & V_2 -> V_57 -> V_22 ;
struct V_111 * V_57 = V_2 -> V_57 ;
struct V_101 * V_112 ;
V_112 = F_51 ( V_57 , V_103 , L_6 ) ;
V_2 -> V_5 = F_52 ( V_22 , V_112 ) ;
if ( F_53 ( V_2 -> V_5 ) )
return F_54 ( V_2 -> V_5 ) ;
V_2 -> V_78 = F_55 ( V_57 , 0 ) ;
if ( V_2 -> V_78 <= 0 ) {
F_29 ( V_22 , L_7 , V_2 -> V_78 ) ;
return - V_106 ;
}
F_56 ( V_2 -> V_78 , F_34 , V_2 ) ;
return 0 ;
}
static void F_57 ( struct V_1 * V_2 )
{
F_30 ( V_2 ) ;
}
static int F_58 ( struct V_111 * V_57 )
{
struct V_56 * V_22 = & V_57 -> V_22 ;
struct V_1 * V_2 ;
struct V_9 * V_10 ;
struct V_9 * V_113 ;
struct V_114 * V_115 ;
int V_45 ;
V_115 = F_59 ( V_22 , sizeof( * V_2 ) ) ;
if ( ! V_115 )
return - V_110 ;
V_2 = F_60 ( V_115 ) ;
V_2 -> V_57 = V_57 ;
V_45 = F_50 ( V_2 ) ;
if ( V_45 ) {
F_29 ( V_22 , L_8 ) ;
return V_45 ;
}
F_61 ( & V_2 -> V_99 ) ;
V_45 = F_42 ( V_2 ) ;
if ( V_45 ) {
F_29 ( V_22 , L_9 ) ;
return V_45 ;
}
V_45 = F_48 ( V_2 ) ;
if ( V_45 ) {
F_29 ( V_22 , L_10 ) ;
return V_45 ;
}
F_1 ( V_2 , V_91 , V_90 ) ;
F_1 ( V_2 , V_116 , V_117 ) ;
F_57 ( V_2 ) ;
F_62 ( & V_2 -> V_99 , & V_115 -> V_118 ) ;
V_115 -> V_22 . V_119 = V_22 ;
V_115 -> V_53 = V_2 ;
V_115 -> V_120 = V_2 -> V_24 ;
V_115 -> V_121 = & V_122 ;
V_115 -> V_123 = V_124 ;
V_115 -> V_125 = V_126 ;
V_45 = F_63 ( V_115 ) ;
if ( V_45 < 0 )
return V_45 ;
V_10 = V_115 -> V_10 ;
F_64 ( V_10 ) ;
F_65 (child, &bus->children, node)
F_66 ( V_113 ) ;
F_67 ( V_10 ) ;
return V_45 ;
}
