static void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
int V_7 )
{
struct V_8 * V_9 = V_4 -> V_9 ;
if ( V_7 == V_10 && V_9 -> V_11 )
F_2 ( V_9 -> V_11 ) ;
}
static void F_3 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
int V_7 )
{
struct V_8 * V_9 = V_4 -> V_9 ;
int V_12 , V_13 = 0 ;
if ( ! V_9 -> V_14 )
return;
for ( V_12 = 0 ; V_12 < V_9 -> V_15 . V_16 ; V_12 ++ ) {
if ( V_9 -> V_15 . V_17 [ V_12 ] == V_2 -> V_18 ) {
V_13 = V_12 ;
break;
}
}
switch ( V_7 ) {
case V_10 :
F_2 ( 40 ) ;
F_4 ( V_4 , V_2 -> V_18 , 0 ,
V_19 , V_20 ) ;
V_9 -> V_21 |= ( 1 << V_13 ) ;
break;
case V_22 :
F_4 ( V_4 , V_2 -> V_18 , 0 ,
V_19 , V_23 ) ;
V_9 -> V_21 &= ~ ( 1 << V_13 ) ;
break;
}
}
static void F_5 ( struct V_3 * V_4 , unsigned int V_24 ,
unsigned int V_25 , unsigned int V_26 )
{
unsigned int V_27 , V_28 , V_29 ;
F_6 ( V_4 , L_1 , V_30 , V_24 , V_25 , V_26 ) ;
V_27 = F_7 ( V_4 , V_4 -> V_31 , 0 ,
V_32 , 0 ) ;
V_27 = ( V_27 & ~ V_25 ) | ( V_26 & V_25 ) ;
V_28 = F_7 ( V_4 , V_4 -> V_31 , 0 ,
V_33 , 0 ) ;
V_28 |= V_24 ;
V_29 = F_7 ( V_4 , V_4 -> V_31 , 0 ,
V_34 , 0 ) ;
V_29 |= V_25 ;
F_4 ( V_4 , V_4 -> V_31 , 0 , 0x7e7 , 0 ) ;
F_4 ( V_4 , V_4 -> V_31 , 0 ,
V_35 , V_28 ) ;
F_7 ( V_4 , V_4 -> V_31 , 0 ,
V_36 , V_29 ) ;
F_2 ( 1 ) ;
F_7 ( V_4 , V_4 -> V_31 , 0 ,
V_37 , V_27 ) ;
}
static void F_8 ( struct V_3 * V_4 ,
struct V_38 * V_39 ,
struct V_40 * V_41 )
{
struct V_8 * V_9 = V_4 -> V_9 ;
unsigned int V_24 ;
bool V_42 , V_43 ;
if ( ! V_39 || ! V_41 )
return;
V_24 = 1U << F_9 ( V_39 , & V_41 -> V_44 ) ;
V_43 = ! V_9 -> V_45 ;
if ( V_41 -> V_46 . integer . V_46 [ 0 ] ||
V_41 -> V_46 . integer . V_46 [ 1 ] )
V_9 -> V_45 |= V_24 ;
else
V_9 -> V_45 &= ~ V_24 ;
V_42 = ! V_9 -> V_45 ;
if ( V_42 != V_43 ) {
if ( V_42 )
V_9 -> V_47 |= V_9 -> V_48 ;
else
V_9 -> V_47 &= ~ V_9 -> V_48 ;
F_5 ( V_4 , V_9 -> V_49 ,
V_9 -> V_50 , V_9 -> V_47 ) ;
}
}
static int F_10 ( struct V_3 * V_4 ,
T_1 V_18 , unsigned int V_51 )
{
int error , V_52 ;
F_6 ( V_4 , L_2 , V_30 , V_18 , V_51 ) ;
V_52 = F_7 ( V_4 , V_18 , 0 ,
V_53 , 0 ) ;
if ( V_52 < 0 )
return V_52 ;
V_52 &= 0xff ;
V_52 &= ~ V_54 ;
V_52 |= ( V_51 & V_54 ) ;
error = F_11 ( V_4 , V_18 , V_52 ) ;
if ( error < 0 )
return error ;
return 1 ;
}
static unsigned int F_12 ( struct V_3 * V_4 ,
T_1 V_18 ,
unsigned int V_55 )
{
if ( V_18 == V_4 -> V_31 && V_55 == V_23 )
return V_56 ;
return F_13 ( V_4 , V_18 , V_55 ) ;
}
static void F_14 ( struct V_3 * V_4 , int V_57 )
{
struct V_8 * V_9 = V_4 -> V_9 ;
int V_58 = ! V_57 ;
if ( ! V_9 -> V_59 )
return;
if ( V_9 -> V_60 )
V_58 = ! V_58 ;
if ( ! V_9 -> V_61 ) {
if ( V_58 )
V_9 -> V_47 |= V_9 -> V_59 ;
else
V_9 -> V_47 &= ~ V_9 -> V_59 ;
F_5 ( V_4 , V_9 -> V_49 ,
V_9 -> V_50 , V_9 -> V_47 ) ;
} else {
V_9 -> V_62 = V_58 ? V_63 : V_64 ;
F_10 ( V_4 , V_9 -> V_61 ,
V_9 -> V_62 ) ;
}
}
static void F_15 ( void * V_65 , int V_66 )
{
F_14 ( V_65 , V_66 ) ;
}
static void F_16 ( struct V_3 * V_4 )
{
struct V_8 * V_9 = V_4 -> V_9 ;
if ( V_9 -> V_67 )
V_9 -> V_15 . V_68 =
! ( F_7 ( V_4 , V_4 -> V_31 , 0 ,
V_32 , 0 ) & V_9 -> V_67 ) ;
F_17 ( V_4 ) ;
if ( V_9 -> V_69 && V_9 -> V_70 ) {
unsigned int V_66 = V_9 -> V_47 ;
if ( V_9 -> V_15 . V_71 )
V_66 &= ~ V_9 -> V_69 ;
else
V_66 |= V_9 -> V_69 ;
if ( V_9 -> V_47 != V_66 ) {
V_9 -> V_47 = V_66 ;
F_5 ( V_4 , V_9 -> V_49 , V_9 -> V_50 ,
V_66 ) ;
}
}
}
static void F_18 ( struct V_3 * V_4 , T_1 V_18 ,
bool V_72 , bool V_73 )
{
struct V_8 * V_9 = V_4 -> V_9 ;
unsigned int V_13 , V_66 ;
for ( V_13 = 0 ; V_13 < V_9 -> V_74 ; V_13 ++ ) {
if ( V_9 -> V_75 [ V_13 ] == V_18 )
break;
}
if ( V_13 >= V_9 -> V_74 )
return;
V_13 = 1 << V_13 ;
V_66 = V_9 -> V_76 ;
if ( V_72 )
V_66 &= ~ V_13 ;
else
V_66 |= V_13 ;
if ( V_66 != V_9 -> V_76 ) {
V_9 -> V_76 = V_66 ;
if ( V_73 )
F_4 ( V_4 , V_4 -> V_31 , 0 ,
V_77 , V_66 ) ;
}
}
static void F_19 ( struct V_3 * V_4 ,
struct V_78 * V_79 )
{
struct V_8 * V_9 = V_4 -> V_9 ;
int V_12 ;
if ( ! V_9 -> V_74 )
return;
if ( V_79 && V_79 -> V_80 -> V_18 ) {
F_18 ( V_4 , V_79 -> V_80 -> V_18 ,
F_20 ( V_4 , V_79 -> V_80 -> V_18 ) ,
true ) ;
return;
}
for ( V_12 = 0 ; V_12 < V_9 -> V_74 ; V_12 ++ ) {
T_1 V_18 = V_9 -> V_75 [ V_12 ] ;
if ( ! F_21 ( V_4 , V_18 ) )
continue;
F_18 ( V_4 , V_18 ,
F_20 ( V_4 , V_18 ) ,
false ) ;
}
F_4 ( V_4 , V_4 -> V_31 , 0 , V_77 ,
V_9 -> V_76 ) ;
}
static void F_22 ( struct V_3 * V_4 ,
struct V_78 * V_81 )
{
unsigned int V_26 ;
V_26 = F_7 ( V_4 , V_4 -> V_31 , 0 ,
V_32 , 0 ) ;
F_4 ( V_4 , V_4 -> V_31 , 0 , 0x7e0 ,
! ! ( V_26 & ( 1 << V_81 -> V_65 ) ) ) ;
}
static void F_23 ( struct V_3 * V_4 )
{
struct V_8 * V_9 = V_4 -> V_9 ;
int V_12 ;
for ( V_12 = 0 ; V_12 < V_9 -> V_74 ; V_12 ++ ) {
T_1 V_18 = V_9 -> V_75 [ V_12 ] ;
unsigned int V_82 = F_24 ( V_4 , V_18 ) ;
V_82 = F_25 ( V_82 ) ;
if ( V_82 == V_83 &&
V_9 -> V_61 != V_18 &&
F_26 ( V_4 , V_18 ) ) {
F_27 ( V_4 , V_18 ,
F_19 ) ;
} else {
if ( V_82 == V_84 )
F_18 ( V_4 , V_18 , false , false ) ;
else
F_18 ( V_4 , V_18 , true , false ) ;
}
}
}
static inline bool F_28 ( struct V_3 * V_4 , const char * V_85 ,
int * V_86 )
{
return ! F_29 ( V_4 , V_85 , V_86 ) ;
}
static void F_30 ( struct V_3 * V_4 )
{
struct V_8 * V_9 = V_4 -> V_9 ;
int V_66 ;
if ( F_28 ( V_4 , L_3 , & V_9 -> V_49 ) ) {
V_9 -> V_69 = V_9 -> V_50 = V_9 -> V_47 =
V_9 -> V_49 ;
}
if ( F_28 ( V_4 , L_4 , & V_9 -> V_50 ) )
V_9 -> V_50 &= V_9 -> V_49 ;
if ( F_28 ( V_4 , L_5 , & V_9 -> V_47 ) )
V_9 -> V_47 &= V_9 -> V_49 ;
if ( F_28 ( V_4 , L_6 , & V_9 -> V_69 ) )
V_9 -> V_69 &= V_9 -> V_49 ;
if ( F_28 ( V_4 , L_7 , & V_9 -> V_67 ) )
V_9 -> V_67 &= V_9 -> V_49 ;
V_66 = F_31 ( V_4 , L_8 ) ;
if ( V_66 >= 0 )
V_9 -> V_70 = V_66 ;
}
static int F_32 ( struct V_38 * V_39 ,
struct V_40 * V_41 )
{
struct V_3 * V_4 = F_33 ( V_39 ) ;
unsigned int V_13 = F_9 ( V_39 , & V_41 -> V_44 ) ;
struct V_8 * V_9 = V_4 -> V_9 ;
V_41 -> V_46 . integer . V_46 [ 0 ] = ! ! ( V_9 -> V_87 &
( V_9 -> V_88 << V_13 ) ) ;
return 0 ;
}
static int F_34 ( struct V_38 * V_39 ,
struct V_40 * V_41 )
{
struct V_3 * V_4 = F_33 ( V_39 ) ;
struct V_8 * V_9 = V_4 -> V_9 ;
unsigned int V_13 = F_9 ( V_39 , & V_41 -> V_44 ) ;
unsigned int V_89 ;
unsigned int V_66 , V_90 ;
V_90 = V_9 -> V_88 << V_13 ;
if ( V_41 -> V_46 . integer . V_46 [ 0 ] )
V_66 = V_9 -> V_87 | V_90 ;
else
V_66 = V_9 -> V_87 & ~ V_90 ;
if ( V_9 -> V_87 == V_66 )
return 0 ;
V_9 -> V_87 = V_66 ;
V_89 = F_7 ( V_4 , V_4 -> V_31 , 0 ,
V_39 -> V_91 & 0xFFFF , 0x0 ) ;
V_89 >>= V_9 -> V_92 ;
if ( V_9 -> V_87 & V_90 ) {
F_35 ( V_4 ) ;
V_89 |= V_90 ;
} else {
F_36 ( V_4 ) ;
V_89 &= ~ V_90 ;
}
F_37 ( V_4 , V_4 -> V_31 , 0 ,
V_39 -> V_91 >> 16 , V_89 ) ;
return 1 ;
}
static bool F_38 ( struct V_3 * V_4 )
{
if ( V_4 -> V_93 != 0x111d7605 &&
V_4 -> V_93 != 0x111d76d1 )
return false ;
switch ( V_4 -> V_94 ) {
case 0x103c1618 :
case 0x103c1619 :
case 0x103c161a :
case 0x103c161b :
case 0x103c161c :
case 0x103c161d :
case 0x103c161e :
case 0x103c161f :
case 0x103c162a :
case 0x103c162b :
case 0x103c1630 :
case 0x103c1631 :
case 0x103c1633 :
case 0x103c1634 :
case 0x103c1635 :
case 0x103c3587 :
case 0x103c3588 :
case 0x103c3589 :
case 0x103c358a :
case 0x103c3667 :
case 0x103c3668 :
case 0x103c3669 :
return true ;
}
return false ;
}
static bool F_39 ( T_2 V_94 )
{
switch ( V_94 ) {
case 0x103c1520 :
case 0x103c1521 :
case 0x103c1523 :
case 0x103c1524 :
case 0x103c1525 :
case 0x103c1722 :
case 0x103c1723 :
case 0x103c1724 :
case 0x103c1725 :
case 0x103c1726 :
case 0x103c1727 :
case 0x103c1728 :
case 0x103c1729 :
case 0x103c172a :
case 0x103c172b :
case 0x103c307e :
case 0x103c307f :
case 0x103c3080 :
case 0x103c3081 :
case 0x103c7007 :
case 0x103c7008 :
return true ;
}
return false ;
}
static void F_40 ( struct V_3 * V_4 )
{
struct V_8 * V_9 = V_4 -> V_9 ;
unsigned int V_95 ;
if ( V_9 -> V_59 )
return;
V_95 = F_41 ( V_4 , V_4 -> V_31 , V_96 ) ;
V_95 &= V_97 ;
if ( V_95 > 3 )
V_9 -> V_59 = 0x08 ;
else
V_9 -> V_59 = 0x01 ;
}
static int F_42 ( struct V_3 * V_4 , int V_98 )
{
struct V_8 * V_9 = V_4 -> V_9 ;
const struct V_99 * V_100 = NULL ;
if ( F_28 ( V_4 , L_9 , & V_9 -> V_59 ) ) {
F_28 ( V_4 , L_10 ,
& V_9 -> V_60 ) ;
return 1 ;
}
while ( ( V_100 = F_43 ( V_101 , NULL , V_100 ) ) ) {
if ( sscanf ( V_100 -> V_102 , L_11 ,
& V_9 -> V_60 ,
& V_9 -> V_59 ) == 2 ) {
unsigned int V_103 ;
V_103 = F_41 ( V_4 , V_4 -> V_31 ,
V_96 ) ;
V_103 &= V_97 ;
if ( V_9 -> V_59 < V_103 )
V_9 -> V_59 = 1 << V_9 -> V_59 ;
else
V_9 -> V_61 = V_9 -> V_59 ;
return 1 ;
}
if ( sscanf ( V_100 -> V_102 , L_12 ,
& V_9 -> V_60 ) == 1 ) {
F_40 ( V_4 ) ;
return 1 ;
}
if ( strstr ( V_100 -> V_102 , L_13 ) ) {
F_40 ( V_4 ) ;
if ( V_98 >= 0 )
V_9 -> V_60 = V_98 ;
else
V_9 -> V_60 = 1 ;
return 1 ;
}
}
if ( ! F_39 ( V_4 -> V_94 ) &&
( V_98 == 0 || V_98 == 1 ) ) {
F_40 ( V_4 ) ;
V_9 -> V_60 = V_98 ;
return 1 ;
}
return 0 ;
}
static bool F_44 ( struct V_3 * V_4 )
{
struct V_8 * V_9 = V_4 -> V_9 ;
T_1 * V_104 ;
int V_105 , V_12 ;
if ( V_9 -> V_15 . V_106 . V_107 == V_108 ) {
V_104 = V_9 -> V_15 . V_106 . V_109 ;
V_105 = V_9 -> V_15 . V_106 . V_110 ;
} else {
V_104 = V_9 -> V_15 . V_106 . V_111 ;
V_105 = V_9 -> V_15 . V_106 . V_112 ;
}
for ( V_12 = 0 ; V_12 < V_105 ; V_12 ++ ) {
unsigned int V_82 = F_24 ( V_4 , V_104 [ V_12 ] ) ;
if ( F_45 ( V_82 ) == V_113 )
return true ;
}
return false ;
}
static int F_46 ( struct V_3 * V_4 ,
T_1 V_18 )
{
struct V_8 * V_9 = V_4 -> V_9 ;
T_2 V_114 = F_47 ( V_4 , V_18 , V_115 ) ;
struct V_116 * V_117 ;
static struct V_116 V_118 =
F_48 ( NULL , 0 , 0 , 0 ) ;
static struct V_116 V_119 =
F_49 ( NULL , 0 , 0 , 0 ) ;
static struct V_116 V_120 =
F_50 ( NULL , 0 , 0 , 0 ) ;
if ( ( V_114 & V_121 ) >> V_122 ) {
const struct V_116 * V_123 ;
if ( V_9 -> V_124 == V_18 )
V_123 = & V_118 ;
else
V_123 = & V_119 ;
V_117 = F_51 ( & V_9 -> V_15 ,
L_14 , V_123 ) ;
if ( ! V_117 )
return - V_125 ;
V_117 -> V_91 =
F_52 ( V_18 , 1 , 0 , V_115 ) ;
}
if ( ( V_114 & V_126 ) >> V_127 ) {
V_117 = F_51 ( & V_9 -> V_15 ,
L_15 ,
& V_120 ) ;
if ( ! V_117 )
return - V_125 ;
V_117 -> V_91 =
F_52 ( V_18 , 1 , 0 , V_115 ) ;
}
return 0 ;
}
static int F_53 ( struct V_38 * V_39 ,
struct V_40 * V_41 )
{
struct V_3 * V_4 = F_33 ( V_39 ) ;
V_41 -> V_46 . integer . V_46 [ 0 ] = V_4 -> V_128 -> V_57 ;
return 0 ;
}
static int F_54 ( struct V_38 * V_39 ,
struct V_40 * V_41 )
{
struct V_3 * V_4 = F_33 ( V_39 ) ;
return F_55 ( V_4 , V_41 -> V_46 . integer . V_46 [ 0 ] ) ;
}
static int F_56 ( struct V_3 * V_4 )
{
struct V_8 * V_9 = V_4 -> V_9 ;
if ( ! F_51 ( & V_9 -> V_15 , NULL , & V_129 ) )
return - V_125 ;
return 0 ;
}
static int F_57 ( struct V_38 * V_39 ,
struct V_130 * V_131 )
{
struct V_3 * V_4 = F_33 ( V_39 ) ;
struct V_8 * V_9 = V_4 -> V_9 ;
return F_58 ( & V_9 -> V_132 , V_131 ) ;
}
static int F_59 ( struct V_38 * V_39 ,
struct V_40 * V_41 )
{
struct V_3 * V_4 = F_33 ( V_39 ) ;
struct V_8 * V_9 = V_4 -> V_9 ;
unsigned int V_133 = F_9 ( V_39 , & V_41 -> V_44 ) ;
V_41 -> V_46 . V_134 . V_135 [ 0 ] = V_9 -> V_136 [ V_133 ] ;
return 0 ;
}
static int F_60 ( struct V_38 * V_39 ,
struct V_40 * V_41 )
{
struct V_3 * V_4 = F_33 ( V_39 ) ;
struct V_8 * V_9 = V_4 -> V_9 ;
unsigned int V_133 = F_9 ( V_39 , & V_41 -> V_44 ) ;
return F_61 ( V_4 , & V_9 -> V_132 , V_41 ,
V_9 -> V_15 . V_106 . V_137 [ V_133 ] ,
& V_9 -> V_136 [ V_133 ] ) ;
}
static int F_62 ( struct V_3 * V_4 )
{
struct V_8 * V_9 = V_4 -> V_9 ;
struct V_138 * V_139 = & V_9 -> V_15 . V_106 ;
const char * const * V_140 = V_9 -> V_141 ;
struct V_116 * V_142 ;
int V_12 , V_143 ;
if ( V_139 -> V_144 < 1 )
return 0 ;
V_143 = F_63 ( V_4 , V_139 -> V_137 [ 0 ] ) ;
if ( V_143 <= 1 )
return 0 ;
if ( ! V_140 )
V_140 = V_145 ;
for ( V_12 = 0 ; V_12 < V_143 ; V_12 ++ ) {
if ( F_64 ( ! V_140 [ V_12 ] ) )
return - V_146 ;
F_65 ( V_4 , & V_9 -> V_132 , V_140 [ V_12 ] , V_12 , NULL ) ;
}
V_142 = F_51 ( & V_9 -> V_15 , NULL , & V_147 ) ;
if ( ! V_142 )
return - V_125 ;
V_142 -> V_148 = V_139 -> V_144 ;
return 0 ;
}
static void F_66 ( struct V_3 * V_4 ,
const struct V_149 * V_150 , int V_7 )
{
struct V_8 * V_9 = V_4 -> V_9 ;
if ( V_7 == V_151 ) {
V_9 -> V_49 = V_9 -> V_50 = 0x09 ;
V_9 -> V_47 = 0x00 ;
V_9 -> V_15 . V_152 = 1 ;
}
}
static void F_67 ( struct V_3 * V_4 ,
const struct V_149 * V_150 , int V_7 )
{
struct V_8 * V_9 = V_4 -> V_9 ;
if ( V_7 != V_151 )
return;
F_68 ( V_4 , V_153 ) ;
V_9 -> V_49 = V_9 -> V_50 = V_9 -> V_47 = 0 ;
}
static void F_69 ( struct V_3 * V_4 )
{
struct V_8 * V_9 = V_4 -> V_9 ;
F_68 ( V_4 , V_154 ) ;
V_9 -> V_70 = 0 ;
}
static void F_70 ( struct V_3 * V_4 ,
const struct V_149 * V_150 , int V_7 )
{
struct V_8 * V_9 = V_4 -> V_9 ;
if ( V_7 != V_151 )
return;
F_69 ( V_4 ) ;
F_71 ( V_4 , V_155 ) ;
V_9 -> V_156 = 1 ;
}
static void F_72 ( struct V_3 * V_4 ,
const struct V_149 * V_150 , int V_7 )
{
if ( V_7 != V_151 )
return;
F_69 ( V_4 ) ;
F_73 ( V_4 , 0x0b , 0x90A70170 ) ;
}
static void F_74 ( struct V_3 * V_4 ,
const struct V_149 * V_150 , int V_7 )
{
if ( V_7 != V_151 )
return;
F_69 ( V_4 ) ;
F_73 ( V_4 , 0x13 , 0x90A60160 ) ;
}
static void F_75 ( struct V_3 * V_4 ,
const struct V_149 * V_150 , int V_7 )
{
if ( V_7 != V_151 )
return;
F_69 ( V_4 ) ;
F_73 ( V_4 , 0x0b , 0x90A70170 ) ;
F_73 ( V_4 , 0x13 , 0x90A60160 ) ;
}
static void F_76 ( struct V_3 * V_4 ,
const struct V_149 * V_150 , int V_7 )
{
struct V_8 * V_9 = V_4 -> V_9 ;
if ( V_7 != V_151 )
return;
F_68 ( V_4 , V_157 ) ;
V_9 -> V_70 = 0 ;
}
static void F_77 ( struct V_3 * V_4 ,
const struct V_149 * V_150 , int V_7 )
{
if ( V_7 == V_151 )
V_4 -> V_158 = 1 ;
}
static void F_78 ( struct V_3 * V_4 ,
const struct V_149 * V_150 , int V_7 )
{
struct V_8 * V_9 = V_4 -> V_9 ;
if ( V_7 != V_151 )
return;
if ( F_38 ( V_4 ) ) {
F_73 ( V_4 , 0xa , 0x2101201f ) ;
F_73 ( V_4 , 0xf , 0x2181205e ) ;
}
if ( F_42 ( V_4 , V_9 -> V_98 ) )
F_6 ( V_4 , L_16 ,
V_9 -> V_59 ,
V_9 -> V_60 ) ;
V_9 -> V_15 . V_159 = true ;
}
static void F_79 ( struct V_3 * V_4 ,
const struct V_149 * V_150 , int V_7 )
{
if ( V_7 != V_151 )
return;
F_68 ( V_4 , V_160 ) ;
F_71 ( V_4 , V_161 ) ;
}
static void F_80 ( struct V_3 * V_4 ,
const struct V_149 * V_150 , int V_7 )
{
struct V_8 * V_9 = V_4 -> V_9 ;
if ( V_7 == V_151 )
V_9 -> V_98 = 0 ;
}
static void F_81 ( struct V_3 * V_4 ,
const struct V_149 * V_150 , int V_7 )
{
struct V_8 * V_9 = V_4 -> V_9 ;
if ( V_7 == V_151 )
V_9 -> V_98 = 1 ;
}
static void F_82 ( struct V_3 * V_4 ,
const struct V_149 * V_150 , int V_7 )
{
struct V_8 * V_9 = V_4 -> V_9 ;
if ( V_7 == V_151 ) {
V_9 -> V_48 = 0x08 ;
V_4 -> V_162 -> V_163 = 1 ;
}
}
static void F_83 ( struct V_3 * V_4 ,
const struct V_149 * V_150 , int V_7 )
{
struct V_8 * V_9 = V_4 -> V_9 ;
if ( V_7 == V_151 ) {
V_9 -> V_59 = 0x10 ;
V_9 -> V_98 = 0 ;
}
}
static void F_84 ( struct V_3 * V_4 ,
const struct V_149 * V_150 , int V_7 )
{
struct V_8 * V_9 = V_4 -> V_9 ;
if ( V_7 == V_151 )
V_9 -> V_164 = 1 ;
}
static int F_85 ( struct V_38 * V_39 ,
struct V_40 * V_41 )
{
struct V_3 * V_4 = F_33 ( V_39 ) ;
struct V_8 * V_9 = V_4 -> V_9 ;
V_41 -> V_46 . integer . V_46 [ 0 ] = ! ! ( V_9 -> V_47 & 0x20 ) ;
return 0 ;
}
static int F_86 ( struct V_38 * V_39 ,
struct V_40 * V_41 )
{
struct V_3 * V_4 = F_33 ( V_39 ) ;
struct V_8 * V_9 = V_4 -> V_9 ;
unsigned int V_47 ;
V_47 = ( V_9 -> V_47 & ~ 0x20 ) |
( V_41 -> V_46 . integer . V_46 [ 0 ] ? 0x20 : 0 ) ;
if ( V_47 == V_9 -> V_47 )
return 0 ;
V_9 -> V_47 = V_47 ;
F_5 ( V_4 , V_9 -> V_49 , V_9 -> V_50 , V_9 -> V_47 ) ;
return 1 ;
}
static int F_87 ( struct V_3 * V_4 )
{
struct V_8 * V_9 = V_4 -> V_9 ;
if ( ! F_51 ( & V_9 -> V_15 , L_17 ,
& V_165 ) )
return - V_125 ;
V_9 -> V_49 |= 0x20 ;
V_9 -> V_50 |= 0x20 ;
V_9 -> V_47 |= 0x20 ;
return 0 ;
}
static void F_88 ( struct V_3 * V_4 ,
const struct V_149 * V_150 , int V_7 )
{
struct V_8 * V_9 = V_4 -> V_9 ;
if ( V_7 != V_151 )
return;
F_68 ( V_4 , V_166 ) ;
V_9 -> V_49 = V_9 -> V_50 = V_9 -> V_47 = 0 ;
}
static void F_89 ( struct V_3 * V_4 ,
const struct V_149 * V_150 , int V_7 )
{
struct V_8 * V_9 = V_4 -> V_9 ;
struct V_78 * V_79 ;
if ( V_7 != V_151 )
return;
F_37 ( V_4 , V_4 -> V_31 , 0 ,
V_167 , 0x02 ) ;
V_79 = F_27 ( V_4 , V_4 -> V_31 ,
F_22 ) ;
if ( ! F_90 ( V_79 ) )
V_79 -> V_65 = 0x02 ;
V_9 -> V_49 |= 0x02 ;
F_73 ( V_4 , 0x0e , 0x01813040 ) ;
}
static void F_91 ( struct V_3 * V_4 ,
const struct V_149 * V_150 , int V_7 )
{
struct V_8 * V_9 = V_4 -> V_9 ;
if ( V_7 != V_151 )
return;
V_9 -> V_59 = 0x01 ;
}
static void F_92 ( struct V_3 * V_4 ,
const struct V_149 * V_150 , int V_7 )
{
unsigned int V_168 ;
switch ( V_7 ) {
case V_151 :
F_73 ( V_4 , 0x0d , 0x90170010 ) ;
break;
case V_169 :
V_168 = F_41 ( V_4 , 0x1 , V_96 ) ;
V_168 &= V_97 ;
if ( V_168 >= 6 )
F_87 ( V_4 ) ;
break;
}
}
static void F_93 ( struct V_3 * V_4 ,
const struct V_149 * V_150 , int V_7 )
{
struct V_8 * V_9 = V_4 -> V_9 ;
if ( V_7 != V_151 )
return;
V_9 -> V_59 = 0x08 ;
}
static void F_94 ( struct V_3 * V_4 ,
const struct V_149 * V_150 , int V_7 )
{
struct V_8 * V_9 = V_4 -> V_9 ;
if ( V_7 != V_151 )
return;
if ( F_39 ( V_4 -> V_94 ) ) {
unsigned int V_170 = F_24 ( V_4 , 0x0f ) ;
if ( F_95 ( V_170 ) == V_171 ||
F_95 ( V_170 ) == V_172 ||
F_95 ( V_170 ) == V_173 ) {
V_170 = ( V_170 & ( ~ V_174 ) )
| ( V_173 <<
V_175 ) ;
V_170 = ( V_170 & ( ~ ( V_176
| V_177 ) ) )
| 0x1f ;
F_73 ( V_4 , 0x0f , V_170 ) ;
}
}
if ( F_42 ( V_4 , 1 ) )
F_6 ( V_4 , L_16 ,
V_9 -> V_59 ,
V_9 -> V_60 ) ;
}
static void F_96 ( struct V_3 * V_4 ,
const struct V_149 * V_150 ,
int V_7 )
{
if ( V_7 != V_151 )
return;
V_4 -> V_178 = V_179 ;
F_97 ( V_4 , NULL , V_180 ,
V_181 ) ;
if ( V_4 -> V_178 != V_179 )
F_98 ( V_4 , V_7 ) ;
}
static void F_99 ( struct V_3 * V_4 ,
const struct V_149 * V_150 ,
int V_7 )
{
struct V_8 * V_9 = V_4 -> V_9 ;
if ( V_7 == V_151 ) {
V_9 -> V_49 = V_9 -> V_50 = 0x03 ;
V_9 -> V_47 = 0x03 ;
}
}
static void F_100 ( struct V_3 * V_4 ,
const struct V_149 * V_150 , int V_7 )
{
if ( V_7 == V_151 )
V_4 -> V_158 = 1 ;
}
static void F_101 ( struct V_3 * V_4 ,
const struct V_149 * V_150 , int V_7 )
{
struct V_8 * V_9 = V_4 -> V_9 ;
if ( V_7 == V_151 ) {
F_68 ( V_4 , V_182 ) ;
V_9 -> V_69 = V_9 -> V_49 = 0 ;
V_9 -> V_50 = V_9 -> V_47 = 0 ;
}
}
static void F_102 ( struct V_3 * V_4 ,
const struct V_149 * V_150 , int V_7 )
{
struct V_8 * V_9 = V_4 -> V_9 ;
if ( V_7 != V_151 )
return;
if ( V_4 -> V_94 != 0x1028022f ) {
V_9 -> V_69 = V_9 -> V_49 = 0x04 ;
V_9 -> V_50 = V_9 -> V_47 = 0x04 ;
}
F_71 ( V_4 , V_183 ) ;
V_9 -> V_156 = 1 ;
}
static void F_103 ( struct V_3 * V_4 ,
const struct V_149 * V_150 , int V_7 )
{
struct V_8 * V_9 = V_4 -> V_9 ;
if ( V_7 == V_151 ) {
F_71 ( V_4 , V_184 ) ;
V_9 -> V_156 = 1 ;
}
}
static void F_104 ( struct V_3 * V_4 ,
const struct V_149 * V_150 , int V_7 )
{
struct V_8 * V_9 = V_4 -> V_9 ;
if ( V_7 == V_151 ) {
F_68 ( V_4 , V_185 ) ;
V_9 -> V_69 = V_9 -> V_49 = V_9 -> V_50 = 0 ;
}
}
static void F_105 ( struct V_3 * V_4 ,
const struct V_149 * V_150 , int V_7 )
{
struct V_8 * V_9 = V_4 -> V_9 ;
struct V_78 * V_79 ;
if ( V_7 == V_151 ) {
F_68 ( V_4 , V_186 ) ;
F_37 ( V_4 , V_4 -> V_31 , 0 ,
V_167 , 0x10 ) ;
V_79 = F_27 ( V_4 , V_4 -> V_31 ,
F_22 ) ;
if ( ! F_90 ( V_79 ) )
V_79 -> V_65 = 0x01 ;
V_9 -> V_50 = 0x0b ;
V_9 -> V_69 = 0x01 ;
V_9 -> V_49 = 0x1b ;
V_9 -> V_67 = 0x10 ;
V_9 -> V_47 = 0x01 ;
}
}
static void F_106 ( struct V_3 * V_4 ,
const struct V_149 * V_150 , int V_7 )
{
struct V_8 * V_9 = V_4 -> V_9 ;
if ( V_7 == V_151 )
V_9 -> V_70 = 0 ;
}
static void F_107 ( struct V_3 * V_4 ,
const struct V_149 * V_150 , int V_7 )
{
struct V_8 * V_9 = V_4 -> V_9 ;
if ( V_7 != V_151 )
return;
if ( F_42 ( V_4 , V_9 -> V_98 ) )
F_6 ( V_4 , L_16 ,
V_9 -> V_59 ,
V_9 -> V_60 ) ;
}
static int F_108 ( struct V_3 * V_4 )
{
struct V_8 * V_9 = V_4 -> V_9 ;
int V_187 ;
int V_188 = 0 ;
if ( V_9 -> V_164 )
V_188 |= V_189 ;
V_187 = F_109 ( V_4 , & V_9 -> V_15 . V_106 , NULL , V_188 ) ;
if ( V_187 < 0 )
return V_187 ;
V_9 -> V_15 . V_190 = F_1 ;
V_9 -> V_15 . V_191 = F_3 ;
V_9 -> V_15 . V_192 = F_16 ;
V_187 = F_110 ( V_4 , & V_9 -> V_15 . V_106 ) ;
if ( V_187 < 0 )
return V_187 ;
if ( V_9 -> V_124 > 0 ) {
V_187 = F_46 ( V_4 ,
V_9 -> V_124 ) ;
if ( V_187 < 0 )
return V_187 ;
}
#ifdef F_111
if ( V_9 -> V_15 . V_193 ) {
T_1 V_18 = V_9 -> V_15 . V_193 ;
unsigned int V_114 ;
V_187 = F_46 ( V_4 , V_18 ) ;
if ( V_187 < 0 )
return V_187 ;
if ( V_4 -> V_128 ) {
V_4 -> V_128 -> V_194 = V_9 -> V_195 ;
V_114 = F_47 ( V_4 , V_18 , V_115 ) ;
if ( ! ( V_114 & V_121 ) ) {
V_187 = F_56 ( V_4 ) ;
if ( V_187 < 0 )
return V_187 ;
}
}
}
#endif
if ( V_9 -> V_59 )
V_9 -> V_15 . V_196 . V_197 = F_15 ;
if ( V_9 -> V_198 &&
F_31 ( V_4 , L_18 ) == 1 ) {
if ( ! F_51 ( & V_9 -> V_15 , NULL , V_9 -> V_198 ) )
return - V_125 ;
}
if ( V_9 -> V_199 ) {
V_187 = F_62 ( V_4 ) ;
if ( V_187 < 0 )
return V_187 ;
}
F_23 ( V_4 ) ;
return 0 ;
}
static int F_112 ( struct V_3 * V_4 )
{
struct V_8 * V_9 = V_4 -> V_9 ;
int V_12 ;
F_30 ( V_4 ) ;
if ( ! V_9 -> V_70 )
V_9 -> V_47 |= V_9 -> V_69 ;
F_5 ( V_4 , V_9 -> V_49 , V_9 -> V_50 , V_9 -> V_47 ) ;
F_113 ( V_4 ) ;
if ( V_9 -> V_74 )
F_4 ( V_4 , V_4 -> V_31 , 0 ,
V_77 ,
V_9 -> V_76 ) ;
if ( V_9 -> V_14 ) {
for ( V_12 = 0 ; V_12 < V_9 -> V_15 . V_16 ; V_12 ++ ) {
if ( V_9 -> V_21 & ( 1 << V_12 ) )
continue;
F_4 ( V_4 , V_9 -> V_15 . V_17 [ V_12 ] , 0 ,
V_19 ,
V_23 ) ;
}
}
return 0 ;
}
static void F_114 ( struct V_3 * V_4 )
{
struct V_8 * V_9 = V_4 -> V_9 ;
F_115 ( V_4 ) ;
if ( V_9 -> V_69 )
F_5 ( V_4 , V_9 -> V_49 ,
V_9 -> V_50 , V_9 -> V_47 &
~ V_9 -> V_69 ) ;
}
static void F_116 ( struct V_200 * V_201 ,
struct V_3 * V_4 , T_1 V_18 )
{
if ( V_18 == V_4 -> V_31 )
F_117 ( V_201 , L_19 ,
F_7 ( V_4 , V_18 , 0 ,
V_202 , 0 ) ) ;
}
static void F_118 ( struct V_200 * V_201 ,
struct V_3 * V_4 ,
unsigned int V_203 )
{
F_117 ( V_201 , L_20 ,
F_7 ( V_4 , V_4 -> V_31 , 0 , V_203 , 0 ) ) ;
}
static void F_119 ( struct V_200 * V_201 ,
struct V_3 * V_4 , T_1 V_18 )
{
F_116 ( V_201 , V_4 , V_18 ) ;
if ( V_18 == V_4 -> V_31 )
F_118 ( V_201 , V_4 , 0xfa0 ) ;
}
static void F_120 ( struct V_200 * V_201 ,
struct V_3 * V_4 , T_1 V_18 )
{
if ( V_18 == V_4 -> V_31 )
F_118 ( V_201 , V_4 , 0xfe0 ) ;
}
static void F_121 ( struct V_200 * V_201 ,
struct V_3 * V_4 , T_1 V_18 )
{
if ( V_18 == V_4 -> V_31 )
F_118 ( V_201 , V_4 , 0xfeb ) ;
}
static int F_122 ( struct V_3 * V_4 )
{
F_114 ( V_4 ) ;
return 0 ;
}
static int F_123 ( struct V_3 * V_4 )
{
struct V_8 * V_9 ;
V_9 = F_124 ( sizeof( * V_9 ) , V_204 ) ;
if ( ! V_9 )
return - V_125 ;
F_125 ( & V_9 -> V_15 ) ;
V_4 -> V_9 = V_9 ;
V_4 -> V_205 = 1 ;
V_9 -> V_15 . V_206 = true ;
return 0 ;
}
static int F_126 ( struct V_3 * V_4 )
{
struct V_8 * V_9 ;
int V_187 ;
V_187 = F_123 ( V_4 ) ;
if ( V_187 < 0 )
return V_187 ;
V_9 = V_4 -> V_9 ;
V_9 -> V_195 = 1 ;
V_9 -> V_15 . V_207 = 1 ;
V_4 -> V_208 = V_209 ;
V_4 -> V_210 = V_211 ;
F_71 ( V_4 , V_212 ) ;
F_97 ( V_4 , V_213 , V_214 ,
V_215 ) ;
F_98 ( V_4 , V_151 ) ;
V_187 = F_108 ( V_4 ) ;
if ( V_187 < 0 ) {
F_127 ( V_4 ) ;
return V_187 ;
}
F_98 ( V_4 , V_169 ) ;
return 0 ;
}
static int F_128 ( struct V_3 * V_4 )
{
struct V_8 * V_9 ;
int V_187 ;
V_187 = F_123 ( V_4 ) ;
if ( V_187 < 0 )
return V_187 ;
V_9 = V_4 -> V_9 ;
V_9 -> V_195 = 1 ;
V_9 -> V_15 . V_207 = 1 ;
V_4 -> V_208 = V_209 ;
F_71 ( V_4 , V_216 ) ;
F_97 ( V_4 , V_217 , V_218 ,
V_219 ) ;
F_98 ( V_4 , V_151 ) ;
V_187 = F_108 ( V_4 ) ;
if ( V_187 < 0 ) {
F_127 ( V_4 ) ;
return V_187 ;
}
F_98 ( V_4 , V_169 ) ;
return 0 ;
}
static int F_129 ( struct V_3 * V_4 )
{
struct V_8 * V_9 ;
int V_187 ;
int V_220 ;
V_187 = F_123 ( V_4 ) ;
if ( V_187 < 0 )
return V_187 ;
V_9 = V_4 -> V_9 ;
V_9 -> V_195 = 0 ;
V_9 -> V_15 . V_221 = 0x1d ;
V_9 -> V_199 = 1 ;
V_220 = F_63 ( V_4 , 0x0a ) - 1 ;
if ( V_220 < 3 || V_220 > 5 ) {
F_130 ( V_4 ,
L_21 ) ;
V_220 = 5 ;
}
switch ( V_220 ) {
case 0x3 :
V_9 -> V_198 = & V_222 ;
break;
case 0x4 :
V_9 -> V_198 = & V_223 ;
break;
case 0x5 :
V_9 -> V_198 = & V_224 ;
break;
}
V_9 -> V_88 = 0x01 ;
V_9 -> V_92 = 8 ;
V_9 -> V_15 . V_193 = 0x1c ;
V_9 -> V_69 = V_9 -> V_49 = V_9 -> V_50 = 0x1 ;
V_9 -> V_47 = 0x01 ;
V_9 -> V_70 = 1 ;
V_9 -> V_74 = F_131 ( V_225 ) ;
V_9 -> V_75 = V_225 ;
V_9 -> V_15 . V_207 = 1 ;
V_9 -> V_15 . V_226 = 1 ;
V_4 -> V_208 = V_209 ;
F_97 ( V_4 , V_227 , V_228 ,
V_229 ) ;
F_98 ( V_4 , V_151 ) ;
if ( ! V_9 -> V_156 )
F_71 ( V_4 , V_230 ) ;
V_187 = F_108 ( V_4 ) ;
if ( V_187 < 0 ) {
F_127 ( V_4 ) ;
return V_187 ;
}
if ( V_9 -> V_70 && ! F_44 ( V_4 ) )
V_9 -> V_70 = 0 ;
V_4 -> V_231 = F_119 ;
F_98 ( V_4 , V_169 ) ;
return 0 ;
}
static void F_132 ( struct V_3 * V_4 )
{
struct V_8 * V_9 = V_4 -> V_9 ;
V_9 -> V_49 |= V_9 -> V_69 ;
if ( V_9 -> V_59 ) {
if ( ! V_9 -> V_61 ) {
V_9 -> V_49 |= V_9 -> V_59 ;
V_9 -> V_50 |= V_9 -> V_59 ;
V_9 -> V_47 |= V_9 -> V_59 ;
} else {
V_4 -> V_210 = F_12 ;
}
}
if ( V_9 -> V_48 ) {
V_9 -> V_49 |= V_9 -> V_48 ;
V_9 -> V_50 |= V_9 -> V_48 ;
V_9 -> V_45 = 0 ;
V_9 -> V_47 |= V_9 -> V_48 ;
V_9 -> V_15 . V_232 = F_8 ;
}
}
static int F_133 ( struct V_3 * V_4 )
{
struct V_8 * V_9 ;
int V_187 ;
V_187 = F_123 ( V_4 ) ;
if ( V_187 < 0 )
return V_187 ;
V_4 -> V_233 = 0 ;
V_9 = V_4 -> V_9 ;
V_9 -> V_195 = 0 ;
V_9 -> V_15 . V_207 = 1 ;
V_9 -> V_15 . V_226 = 1 ;
V_9 -> V_15 . V_221 = 0x1b ;
V_9 -> V_15 . V_193 = 0x21 ;
V_9 -> V_75 = V_234 ;
V_9 -> V_74 = F_131 ( V_234 ) ;
V_9 -> V_98 = - 1 ;
V_4 -> V_208 = V_209 ;
F_71 ( V_4 , V_235 ) ;
F_97 ( V_4 , V_236 , V_237 ,
V_238 ) ;
F_98 ( V_4 , V_151 ) ;
F_132 ( V_4 ) ;
V_187 = F_108 ( V_4 ) ;
if ( V_187 < 0 ) {
F_127 ( V_4 ) ;
return V_187 ;
}
V_4 -> V_231 = F_116 ;
F_98 ( V_4 , V_169 ) ;
return 0 ;
}
static int F_134 ( struct V_3 * V_4 )
{
struct V_8 * V_9 ;
int V_187 ;
V_187 = F_123 ( V_4 ) ;
if ( V_187 < 0 )
return V_187 ;
V_4 -> V_233 = 0 ;
V_9 = V_4 -> V_9 ;
V_9 -> V_195 = 0 ;
V_9 -> V_15 . V_207 = 1 ;
V_9 -> V_15 . V_226 = 1 ;
V_9 -> V_15 . V_193 = 0x19 ;
V_9 -> V_75 = V_239 ;
V_9 -> V_74 = F_131 ( V_239 ) ;
V_9 -> V_98 = 0 ;
V_4 -> V_208 = V_209 ;
F_97 ( V_4 , V_240 , V_241 ,
V_242 ) ;
F_98 ( V_4 , V_151 ) ;
F_132 ( V_4 ) ;
V_187 = F_108 ( V_4 ) ;
if ( V_187 < 0 ) {
F_127 ( V_4 ) ;
return V_187 ;
}
V_4 -> V_231 = F_116 ;
F_98 ( V_4 , V_169 ) ;
return 0 ;
}
static int F_135 ( struct V_3 * V_4 )
{
struct V_8 * V_9 ;
const struct V_243 * V_244 = V_245 ;
int V_187 ;
V_187 = F_123 ( V_4 ) ;
if ( V_187 < 0 )
return V_187 ;
V_9 = V_4 -> V_9 ;
V_9 -> V_195 = 0 ;
V_9 -> V_15 . V_207 = 1 ;
V_9 -> V_15 . V_226 = 1 ;
V_9 -> V_15 . V_221 = 0x17 ;
V_9 -> V_199 = 1 ;
V_4 -> V_208 = V_209 ;
V_9 -> V_49 = 0x01 ;
V_9 -> V_50 = 0x01 ;
V_9 -> V_47 = 0x01 ;
switch ( V_4 -> V_93 ) {
case 0x111d76b6 :
case 0x111d76b7 :
V_244 ++ ;
break;
case 0x111d7608 :
if ( ( V_4 -> V_246 & 0xf ) == 0 ||
( V_4 -> V_246 & 0xf ) == 1 )
V_9 -> V_11 = 40 ;
V_244 ++ ;
F_73 ( V_4 , 0x0f , 0x40f000f0 ) ;
F_73 ( V_4 , 0x19 , 0x40f000f3 ) ;
break;
case 0x111d7603 :
if ( ( V_4 -> V_246 & 0xf ) == 1 )
V_9 -> V_11 = 40 ;
break;
}
if ( F_136 ( F_137 ( V_4 , 0x28 ) ) == V_247 )
F_71 ( V_4 , V_248 ) ;
if ( F_137 ( V_4 , 0xa ) & V_249 )
F_138 ( V_4 , V_244 ) ;
V_9 -> V_198 = & V_250 ;
V_9 -> V_88 = 0x50 ;
V_9 -> V_92 = 0 ;
V_9 -> V_14 = 1 ;
V_9 -> V_15 . V_193 = 0x26 ;
V_9 -> V_74 = F_131 ( V_251 ) ;
V_9 -> V_75 = V_251 ;
F_97 ( V_4 , V_252 , V_253 ,
V_254 ) ;
F_98 ( V_4 , V_151 ) ;
F_132 ( V_4 ) ;
V_187 = F_108 ( V_4 ) ;
if ( V_187 < 0 ) {
F_127 ( V_4 ) ;
return V_187 ;
}
V_4 -> V_231 = F_119 ;
F_98 ( V_4 , V_169 ) ;
return 0 ;
}
static int F_139 ( struct V_3 * V_4 )
{
struct V_8 * V_9 ;
int V_187 ;
V_187 = F_123 ( V_4 ) ;
if ( V_187 < 0 )
return V_187 ;
V_9 = V_4 -> V_9 ;
V_9 -> V_195 = 1 ;
V_9 -> V_15 . V_207 = 1 ;
V_4 -> V_208 = V_209 ;
F_71 ( V_4 , V_255 ) ;
F_140 ( V_4 , 0x12 , V_115 ,
( 0 << V_256 ) |
( 2 << V_127 ) |
( 0x27 << V_257 ) |
( 0 << V_122 ) ) ;
F_97 ( V_4 , V_258 , V_259 ,
V_181 ) ;
F_98 ( V_4 , V_151 ) ;
V_187 = F_108 ( V_4 ) ;
if ( V_187 < 0 ) {
F_127 ( V_4 ) ;
return V_187 ;
}
F_98 ( V_4 , V_169 ) ;
return 0 ;
}
static int F_141 ( struct V_3 * V_4 )
{
struct V_8 * V_9 ;
int V_187 ;
V_187 = F_123 ( V_4 ) ;
if ( V_187 < 0 )
return V_187 ;
V_9 = V_4 -> V_9 ;
V_9 -> V_195 = 1 ;
V_9 -> V_15 . V_207 = 1 ;
V_9 -> V_199 = 1 ;
V_9 -> V_141 = V_260 ;
V_9 -> V_15 . V_193 = 0x23 ;
V_9 -> V_69 = V_9 -> V_49 = 0x01 ;
V_9 -> V_50 = V_9 -> V_47 = 0x01 ;
V_9 -> V_198 = & V_261 ;
V_9 -> V_88 = 0x40 ;
V_9 -> V_92 = 0 ;
V_9 -> V_70 = 1 ;
V_4 -> V_208 = V_209 ;
F_97 ( V_4 , V_262 , V_263 ,
V_264 ) ;
F_98 ( V_4 , V_151 ) ;
if ( ! V_9 -> V_156 )
F_71 ( V_4 , V_265 ) ;
V_187 = F_108 ( V_4 ) ;
if ( V_187 < 0 ) {
F_127 ( V_4 ) ;
return V_187 ;
}
V_4 -> V_231 = F_121 ;
V_4 -> V_162 -> V_266 = 1 ;
F_98 ( V_4 , V_169 ) ;
return 0 ;
}
static int F_142 ( struct V_3 * V_4 )
{
struct V_8 * V_9 ;
int V_187 ;
V_187 = F_123 ( V_4 ) ;
if ( V_187 < 0 )
return V_187 ;
V_9 = V_4 -> V_9 ;
V_9 -> V_195 = 1 ;
V_9 -> V_15 . V_207 = 1 ;
V_9 -> V_199 = 1 ;
V_9 -> V_15 . V_193 = 0x23 ;
F_71 ( V_4 , V_267 ) ;
V_9 -> V_198 = & V_268 ;
V_9 -> V_88 = 0x40 ;
V_9 -> V_92 = 0 ;
V_9 -> V_69 = V_9 -> V_49 = V_9 -> V_50 = 0x1 ;
V_9 -> V_47 = 0x01 ;
V_9 -> V_70 = 1 ;
V_4 -> V_208 = V_209 ;
F_97 ( V_4 , V_269 , V_270 ,
V_271 ) ;
F_98 ( V_4 , V_151 ) ;
V_187 = F_108 ( V_4 ) ;
if ( V_187 < 0 ) {
F_127 ( V_4 ) ;
return V_187 ;
}
V_4 -> V_231 = F_120 ;
F_98 ( V_4 , V_169 ) ;
return 0 ;
}
static int F_143 ( struct V_3 * V_4 )
{
struct V_8 * V_9 ;
int V_187 ;
V_187 = F_123 ( V_4 ) ;
if ( V_187 < 0 )
return V_187 ;
V_9 = V_4 -> V_9 ;
V_9 -> V_195 = 1 ;
V_9 -> V_15 . V_207 = 1 ;
V_4 -> V_208 = V_209 ;
F_71 ( V_4 , V_272 ) ;
F_97 ( V_4 , V_273 , V_274 ,
V_275 ) ;
F_98 ( V_4 , V_151 ) ;
V_187 = F_108 ( V_4 ) ;
if ( V_187 < 0 ) {
F_127 ( V_4 ) ;
return - V_146 ;
}
F_98 ( V_4 , V_169 ) ;
return 0 ;
}
static int T_3 F_144 ( void )
{
return F_145 ( & V_276 ) ;
}
static void T_4 F_146 ( void )
{
F_147 ( & V_276 ) ;
}
