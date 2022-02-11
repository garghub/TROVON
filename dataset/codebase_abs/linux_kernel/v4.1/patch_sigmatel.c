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
T_1 V_30 = V_4 -> V_31 . V_32 ;
F_6 ( V_4 , L_1 , V_33 , V_24 , V_25 , V_26 ) ;
V_27 = F_7 ( V_4 , V_30 , 0 ,
V_34 , 0 ) ;
V_27 = ( V_27 & ~ V_25 ) | ( V_26 & V_25 ) ;
V_28 = F_7 ( V_4 , V_30 , 0 ,
V_35 , 0 ) ;
V_28 |= V_24 ;
V_29 = F_7 ( V_4 , V_30 , 0 ,
V_36 , 0 ) ;
V_29 |= V_25 ;
F_4 ( V_4 , V_30 , 0 , 0x7e7 , 0 ) ;
F_4 ( V_4 , V_30 , 0 ,
V_37 , V_28 ) ;
F_7 ( V_4 , V_30 , 0 ,
V_38 , V_29 ) ;
F_2 ( 1 ) ;
F_7 ( V_4 , V_30 , 0 ,
V_39 , V_27 ) ;
}
static void F_8 ( struct V_3 * V_4 ,
struct V_40 * V_41 ,
struct V_42 * V_43 )
{
struct V_8 * V_9 = V_4 -> V_9 ;
unsigned int V_24 ;
bool V_44 , V_45 ;
if ( ! V_41 || ! V_43 )
return;
V_24 = 1U << F_9 ( V_41 , & V_43 -> V_46 ) ;
V_45 = ! V_9 -> V_47 ;
if ( V_43 -> V_48 . integer . V_48 [ 0 ] ||
V_43 -> V_48 . integer . V_48 [ 1 ] )
V_9 -> V_47 |= V_24 ;
else
V_9 -> V_47 &= ~ V_24 ;
V_44 = ! V_9 -> V_47 ;
if ( V_44 != V_45 ) {
if ( V_44 )
V_9 -> V_49 |= V_9 -> V_50 ;
else
V_9 -> V_49 &= ~ V_9 -> V_50 ;
F_5 ( V_4 , V_9 -> V_51 ,
V_9 -> V_52 , V_9 -> V_49 ) ;
}
}
static int F_10 ( struct V_3 * V_4 ,
T_1 V_18 , unsigned int V_53 )
{
int error , V_54 ;
F_6 ( V_4 , L_2 , V_33 , V_18 , V_53 ) ;
V_54 = F_7 ( V_4 , V_18 , 0 ,
V_55 , 0 ) ;
if ( V_54 < 0 )
return V_54 ;
V_54 &= 0xff ;
V_54 &= ~ V_56 ;
V_54 |= ( V_53 & V_56 ) ;
error = F_11 ( V_4 , V_18 , V_54 ) ;
if ( error < 0 )
return error ;
return 1 ;
}
static unsigned int F_12 ( struct V_3 * V_4 ,
T_1 V_18 ,
unsigned int V_57 )
{
if ( V_18 == V_4 -> V_31 . V_32 && V_57 == V_23 )
return V_58 ;
return F_13 ( V_4 , V_18 , V_57 ) ;
}
static void F_14 ( struct V_3 * V_4 , int V_59 )
{
struct V_8 * V_9 = V_4 -> V_9 ;
int V_60 = ! V_59 ;
if ( ! V_9 -> V_61 )
return;
if ( V_9 -> V_62 )
V_60 = ! V_60 ;
if ( ! V_9 -> V_63 ) {
if ( V_60 )
V_9 -> V_49 |= V_9 -> V_61 ;
else
V_9 -> V_49 &= ~ V_9 -> V_61 ;
F_5 ( V_4 , V_9 -> V_51 ,
V_9 -> V_52 , V_9 -> V_49 ) ;
} else {
V_9 -> V_64 = V_60 ? V_65 : V_66 ;
F_10 ( V_4 , V_9 -> V_63 ,
V_9 -> V_64 ) ;
}
}
static void F_15 ( void * V_67 , int V_68 )
{
F_14 ( V_67 , V_68 ) ;
}
static void F_16 ( struct V_3 * V_4 )
{
struct V_8 * V_9 = V_4 -> V_9 ;
if ( V_9 -> V_69 )
V_9 -> V_15 . V_70 =
! ( F_7 ( V_4 , V_4 -> V_31 . V_32 , 0 ,
V_34 , 0 ) & V_9 -> V_69 ) ;
F_17 ( V_4 ) ;
if ( V_9 -> V_71 && V_9 -> V_72 ) {
unsigned int V_68 = V_9 -> V_49 ;
if ( V_9 -> V_15 . V_73 )
V_68 &= ~ V_9 -> V_71 ;
else
V_68 |= V_9 -> V_71 ;
if ( V_9 -> V_49 != V_68 ) {
V_9 -> V_49 = V_68 ;
F_5 ( V_4 , V_9 -> V_51 , V_9 -> V_52 ,
V_68 ) ;
}
}
}
static void F_18 ( struct V_3 * V_4 , T_1 V_18 ,
bool V_74 , bool V_75 )
{
struct V_8 * V_9 = V_4 -> V_9 ;
unsigned int V_13 , V_68 ;
for ( V_13 = 0 ; V_13 < V_9 -> V_76 ; V_13 ++ ) {
if ( V_9 -> V_77 [ V_13 ] == V_18 )
break;
}
if ( V_13 >= V_9 -> V_76 )
return;
V_13 = 1 << V_13 ;
V_68 = V_9 -> V_78 ;
if ( V_74 )
V_68 &= ~ V_13 ;
else
V_68 |= V_13 ;
if ( V_68 != V_9 -> V_78 ) {
V_9 -> V_78 = V_68 ;
if ( V_75 )
F_4 ( V_4 , V_4 -> V_31 . V_32 , 0 ,
V_79 , V_68 ) ;
}
}
static void F_19 ( struct V_3 * V_4 ,
struct V_80 * V_81 )
{
struct V_8 * V_9 = V_4 -> V_9 ;
int V_12 ;
if ( ! V_9 -> V_76 )
return;
if ( V_81 && V_81 -> V_82 -> V_18 ) {
F_18 ( V_4 , V_81 -> V_82 -> V_18 ,
F_20 ( V_4 , V_81 -> V_82 -> V_18 ) ,
true ) ;
return;
}
for ( V_12 = 0 ; V_12 < V_9 -> V_76 ; V_12 ++ ) {
T_1 V_18 = V_9 -> V_77 [ V_12 ] ;
if ( ! F_21 ( V_4 , V_18 ) )
continue;
F_18 ( V_4 , V_18 ,
F_20 ( V_4 , V_18 ) ,
false ) ;
}
F_4 ( V_4 , V_4 -> V_31 . V_32 , 0 ,
V_79 ,
V_9 -> V_78 ) ;
}
static void F_22 ( struct V_3 * V_4 ,
struct V_80 * V_83 )
{
unsigned int V_26 ;
V_26 = F_7 ( V_4 , V_4 -> V_31 . V_32 , 0 ,
V_34 , 0 ) ;
F_4 ( V_4 , V_4 -> V_31 . V_32 , 0 , 0x7e0 ,
! ! ( V_26 & ( 1 << V_83 -> V_67 ) ) ) ;
}
static void F_23 ( struct V_3 * V_4 )
{
struct V_8 * V_9 = V_4 -> V_9 ;
int V_12 ;
for ( V_12 = 0 ; V_12 < V_9 -> V_76 ; V_12 ++ ) {
T_1 V_18 = V_9 -> V_77 [ V_12 ] ;
unsigned int V_84 = F_24 ( V_4 , V_18 ) ;
V_84 = F_25 ( V_84 ) ;
if ( V_84 == V_85 &&
V_9 -> V_63 != V_18 &&
F_26 ( V_4 , V_18 ) ) {
F_27 ( V_4 , V_18 ,
F_19 ) ;
} else {
if ( V_84 == V_86 )
F_18 ( V_4 , V_18 , false , false ) ;
else
F_18 ( V_4 , V_18 , true , false ) ;
}
}
}
static inline bool F_28 ( struct V_3 * V_4 , const char * V_87 ,
int * V_88 )
{
return ! F_29 ( V_4 , V_87 , V_88 ) ;
}
static void F_30 ( struct V_3 * V_4 )
{
struct V_8 * V_9 = V_4 -> V_9 ;
int V_68 ;
if ( F_28 ( V_4 , L_3 , & V_9 -> V_51 ) ) {
V_9 -> V_71 = V_9 -> V_52 = V_9 -> V_49 =
V_9 -> V_51 ;
}
if ( F_28 ( V_4 , L_4 , & V_9 -> V_52 ) )
V_9 -> V_52 &= V_9 -> V_51 ;
if ( F_28 ( V_4 , L_5 , & V_9 -> V_49 ) )
V_9 -> V_49 &= V_9 -> V_51 ;
if ( F_28 ( V_4 , L_6 , & V_9 -> V_71 ) )
V_9 -> V_71 &= V_9 -> V_51 ;
if ( F_28 ( V_4 , L_7 , & V_9 -> V_69 ) )
V_9 -> V_69 &= V_9 -> V_51 ;
V_68 = F_31 ( V_4 , L_8 ) ;
if ( V_68 >= 0 )
V_9 -> V_72 = V_68 ;
}
static int F_32 ( struct V_40 * V_41 ,
struct V_42 * V_43 )
{
struct V_3 * V_4 = F_33 ( V_41 ) ;
unsigned int V_13 = F_9 ( V_41 , & V_43 -> V_46 ) ;
struct V_8 * V_9 = V_4 -> V_9 ;
V_43 -> V_48 . integer . V_48 [ 0 ] = ! ! ( V_9 -> V_89 &
( V_9 -> V_90 << V_13 ) ) ;
return 0 ;
}
static int F_34 ( struct V_40 * V_41 ,
struct V_42 * V_43 )
{
struct V_3 * V_4 = F_33 ( V_41 ) ;
struct V_8 * V_9 = V_4 -> V_9 ;
unsigned int V_13 = F_9 ( V_41 , & V_43 -> V_46 ) ;
unsigned int V_91 ;
unsigned int V_68 , V_92 ;
V_92 = V_9 -> V_90 << V_13 ;
if ( V_43 -> V_48 . integer . V_48 [ 0 ] )
V_68 = V_9 -> V_89 | V_92 ;
else
V_68 = V_9 -> V_89 & ~ V_92 ;
if ( V_9 -> V_89 == V_68 )
return 0 ;
V_9 -> V_89 = V_68 ;
V_91 = F_7 ( V_4 , V_4 -> V_31 . V_32 , 0 ,
V_41 -> V_93 & 0xFFFF , 0x0 ) ;
V_91 >>= V_9 -> V_94 ;
if ( V_9 -> V_89 & V_92 ) {
F_35 ( V_4 ) ;
V_91 |= V_92 ;
} else {
F_36 ( V_4 ) ;
V_91 &= ~ V_92 ;
}
F_37 ( V_4 , V_4 -> V_31 . V_32 , 0 ,
V_41 -> V_93 >> 16 , V_91 ) ;
return 1 ;
}
static bool F_38 ( struct V_3 * V_4 )
{
if ( V_4 -> V_31 . V_95 != 0x111d7605 &&
V_4 -> V_31 . V_95 != 0x111d76d1 )
return false ;
switch ( V_4 -> V_31 . V_96 ) {
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
static bool F_39 ( T_2 V_96 )
{
switch ( V_96 ) {
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
unsigned int V_97 ;
if ( V_9 -> V_61 )
return;
V_97 = F_41 ( V_4 , V_4 -> V_31 . V_32 , V_98 ) ;
V_97 &= V_99 ;
if ( V_97 > 3 )
V_9 -> V_61 = 0x08 ;
else
V_9 -> V_61 = 0x01 ;
}
static int F_42 ( struct V_3 * V_4 , int V_100 )
{
struct V_8 * V_9 = V_4 -> V_9 ;
const struct V_101 * V_102 = NULL ;
if ( F_28 ( V_4 , L_9 , & V_9 -> V_61 ) ) {
F_28 ( V_4 , L_10 ,
& V_9 -> V_62 ) ;
return 1 ;
}
while ( ( V_102 = F_43 ( V_103 , NULL , V_102 ) ) ) {
if ( sscanf ( V_102 -> V_104 , L_11 ,
& V_9 -> V_62 ,
& V_9 -> V_61 ) == 2 ) {
unsigned int V_105 ;
V_105 = F_41 ( V_4 , V_4 -> V_31 . V_32 ,
V_98 ) ;
V_105 &= V_99 ;
if ( V_9 -> V_61 < V_105 )
V_9 -> V_61 = 1 << V_9 -> V_61 ;
else
V_9 -> V_63 = V_9 -> V_61 ;
return 1 ;
}
if ( sscanf ( V_102 -> V_104 , L_12 ,
& V_9 -> V_62 ) == 1 ) {
F_40 ( V_4 ) ;
return 1 ;
}
if ( strstr ( V_102 -> V_104 , L_13 ) ) {
F_40 ( V_4 ) ;
if ( V_100 >= 0 )
V_9 -> V_62 = V_100 ;
else
V_9 -> V_62 = 1 ;
return 1 ;
}
}
if ( ! F_39 ( V_4 -> V_31 . V_96 ) &&
( V_100 == 0 || V_100 == 1 ) ) {
F_40 ( V_4 ) ;
V_9 -> V_62 = V_100 ;
return 1 ;
}
return 0 ;
}
static bool F_44 ( struct V_3 * V_4 )
{
struct V_8 * V_9 = V_4 -> V_9 ;
T_1 * V_106 ;
int V_107 , V_12 ;
if ( V_9 -> V_15 . V_108 . V_109 == V_110 ) {
V_106 = V_9 -> V_15 . V_108 . V_111 ;
V_107 = V_9 -> V_15 . V_108 . V_112 ;
} else {
V_106 = V_9 -> V_15 . V_108 . V_113 ;
V_107 = V_9 -> V_15 . V_108 . V_114 ;
}
for ( V_12 = 0 ; V_12 < V_107 ; V_12 ++ ) {
unsigned int V_84 = F_24 ( V_4 , V_106 [ V_12 ] ) ;
if ( F_45 ( V_84 ) == V_115 )
return true ;
}
return false ;
}
static int F_46 ( struct V_3 * V_4 ,
T_1 V_18 )
{
struct V_8 * V_9 = V_4 -> V_9 ;
T_2 V_116 = F_47 ( V_4 , V_18 , V_117 ) ;
struct V_118 * V_119 ;
static struct V_118 V_120 =
F_48 ( NULL , 0 , 0 , 0 ) ;
static struct V_118 V_121 =
F_49 ( NULL , 0 , 0 , 0 ) ;
static struct V_118 V_122 =
F_50 ( NULL , 0 , 0 , 0 ) ;
if ( ( V_116 & V_123 ) >> V_124 ) {
const struct V_118 * V_125 ;
if ( V_9 -> V_126 == V_18 )
V_125 = & V_120 ;
else
V_125 = & V_121 ;
V_119 = F_51 ( & V_9 -> V_15 ,
L_14 , V_125 ) ;
if ( ! V_119 )
return - V_127 ;
V_119 -> V_93 =
F_52 ( V_18 , 1 , 0 , V_117 ) ;
}
if ( ( V_116 & V_128 ) >> V_129 ) {
V_119 = F_51 ( & V_9 -> V_15 ,
L_15 ,
& V_122 ) ;
if ( ! V_119 )
return - V_127 ;
V_119 -> V_93 =
F_52 ( V_18 , 1 , 0 , V_117 ) ;
}
return 0 ;
}
static int F_53 ( struct V_40 * V_41 ,
struct V_42 * V_43 )
{
struct V_3 * V_4 = F_33 ( V_41 ) ;
V_43 -> V_48 . integer . V_48 [ 0 ] = V_4 -> V_130 -> V_59 ;
return 0 ;
}
static int F_54 ( struct V_40 * V_41 ,
struct V_42 * V_43 )
{
struct V_3 * V_4 = F_33 ( V_41 ) ;
return F_55 ( V_4 , V_43 -> V_48 . integer . V_48 [ 0 ] ) ;
}
static int F_56 ( struct V_3 * V_4 )
{
struct V_8 * V_9 = V_4 -> V_9 ;
if ( ! F_51 ( & V_9 -> V_15 , NULL , & V_131 ) )
return - V_127 ;
return 0 ;
}
static int F_57 ( struct V_40 * V_41 ,
struct V_132 * V_133 )
{
struct V_3 * V_4 = F_33 ( V_41 ) ;
struct V_8 * V_9 = V_4 -> V_9 ;
return F_58 ( & V_9 -> V_134 , V_133 ) ;
}
static int F_59 ( struct V_40 * V_41 ,
struct V_42 * V_43 )
{
struct V_3 * V_4 = F_33 ( V_41 ) ;
struct V_8 * V_9 = V_4 -> V_9 ;
unsigned int V_135 = F_9 ( V_41 , & V_43 -> V_46 ) ;
V_43 -> V_48 . V_136 . V_137 [ 0 ] = V_9 -> V_138 [ V_135 ] ;
return 0 ;
}
static int F_60 ( struct V_40 * V_41 ,
struct V_42 * V_43 )
{
struct V_3 * V_4 = F_33 ( V_41 ) ;
struct V_8 * V_9 = V_4 -> V_9 ;
unsigned int V_135 = F_9 ( V_41 , & V_43 -> V_46 ) ;
return F_61 ( V_4 , & V_9 -> V_134 , V_43 ,
V_9 -> V_15 . V_108 . V_139 [ V_135 ] ,
& V_9 -> V_138 [ V_135 ] ) ;
}
static int F_62 ( struct V_3 * V_4 )
{
struct V_8 * V_9 = V_4 -> V_9 ;
struct V_140 * V_141 = & V_9 -> V_15 . V_108 ;
const char * const * V_142 = V_9 -> V_143 ;
struct V_118 * V_144 ;
int V_12 , V_145 ;
if ( V_141 -> V_146 < 1 )
return 0 ;
V_145 = F_63 ( V_4 , V_141 -> V_139 [ 0 ] ) ;
if ( V_145 <= 1 )
return 0 ;
if ( ! V_142 )
V_142 = V_147 ;
for ( V_12 = 0 ; V_12 < V_145 ; V_12 ++ ) {
if ( F_64 ( ! V_142 [ V_12 ] ) )
return - V_148 ;
F_65 ( V_4 , & V_9 -> V_134 , V_142 [ V_12 ] , V_12 , NULL ) ;
}
V_144 = F_51 ( & V_9 -> V_15 , NULL , & V_149 ) ;
if ( ! V_144 )
return - V_127 ;
V_144 -> V_150 = V_141 -> V_146 ;
return 0 ;
}
static void F_66 ( struct V_3 * V_4 ,
const struct V_151 * V_152 , int V_7 )
{
struct V_8 * V_9 = V_4 -> V_9 ;
if ( V_7 == V_153 ) {
V_9 -> V_51 = V_9 -> V_52 = 0x09 ;
V_9 -> V_49 = 0x00 ;
V_9 -> V_15 . V_154 = 1 ;
}
}
static void F_67 ( struct V_3 * V_4 ,
const struct V_151 * V_152 , int V_7 )
{
struct V_8 * V_9 = V_4 -> V_9 ;
if ( V_7 != V_153 )
return;
F_68 ( V_4 , V_155 ) ;
V_9 -> V_51 = V_9 -> V_52 = V_9 -> V_49 = 0 ;
}
static void F_69 ( struct V_3 * V_4 )
{
struct V_8 * V_9 = V_4 -> V_9 ;
F_68 ( V_4 , V_156 ) ;
V_9 -> V_72 = 0 ;
}
static void F_70 ( struct V_3 * V_4 ,
const struct V_151 * V_152 , int V_7 )
{
struct V_8 * V_9 = V_4 -> V_9 ;
if ( V_7 != V_153 )
return;
F_69 ( V_4 ) ;
F_71 ( V_4 , V_157 ) ;
V_9 -> V_158 = 1 ;
}
static void F_72 ( struct V_3 * V_4 ,
const struct V_151 * V_152 , int V_7 )
{
if ( V_7 != V_153 )
return;
F_69 ( V_4 ) ;
F_73 ( V_4 , 0x0b , 0x90A70170 ) ;
}
static void F_74 ( struct V_3 * V_4 ,
const struct V_151 * V_152 , int V_7 )
{
if ( V_7 != V_153 )
return;
F_69 ( V_4 ) ;
F_73 ( V_4 , 0x13 , 0x90A60160 ) ;
}
static void F_75 ( struct V_3 * V_4 ,
const struct V_151 * V_152 , int V_7 )
{
if ( V_7 != V_153 )
return;
F_69 ( V_4 ) ;
F_73 ( V_4 , 0x0b , 0x90A70170 ) ;
F_73 ( V_4 , 0x13 , 0x90A60160 ) ;
}
static void F_76 ( struct V_3 * V_4 ,
const struct V_151 * V_152 , int V_7 )
{
struct V_8 * V_9 = V_4 -> V_9 ;
if ( V_7 != V_153 )
return;
F_68 ( V_4 , V_159 ) ;
V_9 -> V_72 = 0 ;
}
static void F_77 ( struct V_3 * V_4 ,
const struct V_151 * V_152 , int V_7 )
{
if ( V_7 == V_153 )
V_4 -> V_160 = 1 ;
}
static void F_78 ( struct V_3 * V_4 ,
const struct V_151 * V_152 , int V_7 )
{
struct V_8 * V_9 = V_4 -> V_9 ;
if ( V_7 != V_153 )
return;
if ( F_38 ( V_4 ) ) {
F_73 ( V_4 , 0xa , 0x2101201f ) ;
F_73 ( V_4 , 0xf , 0x2181205e ) ;
}
if ( F_42 ( V_4 , V_9 -> V_100 ) )
F_6 ( V_4 , L_16 ,
V_9 -> V_61 ,
V_9 -> V_62 ) ;
V_9 -> V_15 . V_161 = true ;
}
static void F_79 ( struct V_3 * V_4 ,
const struct V_151 * V_152 , int V_7 )
{
if ( V_7 != V_153 )
return;
F_68 ( V_4 , V_162 ) ;
F_71 ( V_4 , V_163 ) ;
}
static void F_80 ( struct V_3 * V_4 ,
const struct V_151 * V_152 , int V_7 )
{
struct V_8 * V_9 = V_4 -> V_9 ;
if ( V_7 == V_153 )
V_9 -> V_100 = 0 ;
}
static void F_81 ( struct V_3 * V_4 ,
const struct V_151 * V_152 , int V_7 )
{
struct V_8 * V_9 = V_4 -> V_9 ;
if ( V_7 == V_153 )
V_9 -> V_100 = 1 ;
}
static void F_82 ( struct V_3 * V_4 ,
const struct V_151 * V_152 , int V_7 )
{
struct V_8 * V_9 = V_4 -> V_9 ;
if ( V_7 == V_153 ) {
V_9 -> V_50 = 0x08 ;
#ifdef F_83
V_4 -> V_31 . V_164 &= ~ V_165 ;
#endif
}
}
static void F_84 ( struct V_3 * V_4 ,
const struct V_151 * V_152 , int V_7 )
{
struct V_8 * V_9 = V_4 -> V_9 ;
if ( V_7 == V_153 ) {
V_9 -> V_61 = 0x10 ;
V_9 -> V_100 = 0 ;
}
}
static void F_85 ( struct V_3 * V_4 ,
const struct V_151 * V_152 , int V_7 )
{
struct V_8 * V_9 = V_4 -> V_9 ;
if ( V_7 == V_153 )
V_9 -> V_166 = 1 ;
}
static void F_86 ( struct V_3 * V_4 ,
const struct V_151 * V_152 ,
int V_7 )
{
struct V_8 * V_9 = V_4 -> V_9 ;
if ( V_7 != V_153 )
return;
V_9 -> V_71 = V_9 -> V_51 = V_9 -> V_52 =
V_9 -> V_49 = 0x10 ;
V_9 -> V_72 = 0 ;
}
static void F_87 ( struct V_3 * V_4 ,
const struct V_151 * V_152 ,
int V_7 )
{
struct V_8 * V_9 = V_4 -> V_9 ;
static T_1 V_167 [] = {
0xd , 0x13 ,
0
} ;
if ( V_7 != V_153 )
return;
V_9 -> V_15 . V_168 = V_167 ;
}
static int F_88 ( struct V_40 * V_41 ,
struct V_42 * V_43 )
{
struct V_3 * V_4 = F_33 ( V_41 ) ;
struct V_8 * V_9 = V_4 -> V_9 ;
V_43 -> V_48 . integer . V_48 [ 0 ] = ! ! ( V_9 -> V_49 & 0x20 ) ;
return 0 ;
}
static int F_89 ( struct V_40 * V_41 ,
struct V_42 * V_43 )
{
struct V_3 * V_4 = F_33 ( V_41 ) ;
struct V_8 * V_9 = V_4 -> V_9 ;
unsigned int V_49 ;
V_49 = ( V_9 -> V_49 & ~ 0x20 ) |
( V_43 -> V_48 . integer . V_48 [ 0 ] ? 0x20 : 0 ) ;
if ( V_49 == V_9 -> V_49 )
return 0 ;
V_9 -> V_49 = V_49 ;
F_5 ( V_4 , V_9 -> V_51 , V_9 -> V_52 , V_9 -> V_49 ) ;
return 1 ;
}
static int F_90 ( struct V_3 * V_4 )
{
struct V_8 * V_9 = V_4 -> V_9 ;
if ( ! F_51 ( & V_9 -> V_15 , L_17 ,
& V_169 ) )
return - V_127 ;
V_9 -> V_51 |= 0x20 ;
V_9 -> V_52 |= 0x20 ;
V_9 -> V_49 |= 0x20 ;
return 0 ;
}
static void F_91 ( struct V_3 * V_4 ,
const struct V_151 * V_152 , int V_7 )
{
struct V_8 * V_9 = V_4 -> V_9 ;
if ( V_7 != V_153 )
return;
F_68 ( V_4 , V_170 ) ;
V_9 -> V_51 = V_9 -> V_52 = V_9 -> V_49 = 0 ;
}
static void F_92 ( struct V_3 * V_4 ,
const struct V_151 * V_152 , int V_7 )
{
struct V_8 * V_9 = V_4 -> V_9 ;
struct V_80 * V_81 ;
if ( V_7 != V_153 )
return;
F_37 ( V_4 , V_4 -> V_31 . V_32 , 0 ,
V_171 , 0x02 ) ;
V_81 = F_27 ( V_4 , V_4 -> V_31 . V_32 ,
F_22 ) ;
if ( ! F_93 ( V_81 ) )
V_81 -> V_67 = 0x02 ;
V_9 -> V_51 |= 0x02 ;
F_73 ( V_4 , 0x0e , 0x01813040 ) ;
}
static void F_94 ( struct V_3 * V_4 ,
const struct V_151 * V_152 , int V_7 )
{
struct V_8 * V_9 = V_4 -> V_9 ;
if ( V_7 != V_153 )
return;
V_9 -> V_61 = 0x01 ;
}
static void F_95 ( struct V_3 * V_4 ,
const struct V_151 * V_152 , int V_7 )
{
unsigned int V_172 ;
switch ( V_7 ) {
case V_153 :
F_73 ( V_4 , 0x0d , 0x90170010 ) ;
break;
case V_173 :
V_172 = F_41 ( V_4 , 0x1 , V_98 ) ;
V_172 &= V_99 ;
if ( V_172 >= 6 )
F_90 ( V_4 ) ;
break;
}
}
static void F_96 ( struct V_3 * V_4 ,
const struct V_151 * V_152 , int V_7 )
{
struct V_8 * V_9 = V_4 -> V_9 ;
if ( V_7 != V_153 )
return;
V_9 -> V_61 = 0x08 ;
}
static void F_97 ( struct V_3 * V_4 ,
const struct V_151 * V_152 , int V_7 )
{
struct V_8 * V_9 = V_4 -> V_9 ;
if ( V_7 != V_153 )
return;
if ( F_39 ( V_4 -> V_31 . V_96 ) ) {
unsigned int V_174 = F_24 ( V_4 , 0x0f ) ;
if ( F_98 ( V_174 ) == V_175 ||
F_98 ( V_174 ) == V_176 ||
F_98 ( V_174 ) == V_177 ) {
V_174 = ( V_174 & ( ~ V_178 ) )
| ( V_177 <<
V_179 ) ;
V_174 = ( V_174 & ( ~ ( V_180
| V_181 ) ) )
| 0x1f ;
F_73 ( V_4 , 0x0f , V_174 ) ;
}
}
if ( F_42 ( V_4 , 1 ) )
F_6 ( V_4 , L_16 ,
V_9 -> V_61 ,
V_9 -> V_62 ) ;
}
static void F_99 ( struct V_3 * V_4 ,
const struct V_151 * V_152 ,
int V_7 )
{
if ( V_7 != V_153 )
return;
V_4 -> V_182 = V_183 ;
F_100 ( V_4 , NULL , V_184 ,
V_185 ) ;
if ( V_4 -> V_182 != V_183 )
F_101 ( V_4 , V_7 ) ;
}
static void F_102 ( struct V_3 * V_4 ,
const struct V_151 * V_152 ,
int V_7 )
{
struct V_8 * V_9 = V_4 -> V_9 ;
if ( V_7 == V_153 ) {
V_9 -> V_51 = V_9 -> V_52 = 0x03 ;
V_9 -> V_49 = 0x03 ;
}
}
static void F_103 ( struct V_3 * V_4 ,
const struct V_151 * V_152 , int V_7 )
{
if ( V_7 == V_153 )
V_4 -> V_160 = 1 ;
}
static void F_104 ( struct V_3 * V_4 ,
const struct V_151 * V_152 , int V_7 )
{
struct V_8 * V_9 = V_4 -> V_9 ;
if ( V_7 == V_153 ) {
F_68 ( V_4 , V_186 ) ;
V_9 -> V_71 = V_9 -> V_51 = 0 ;
V_9 -> V_52 = V_9 -> V_49 = 0 ;
}
}
static void F_105 ( struct V_3 * V_4 ,
const struct V_151 * V_152 , int V_7 )
{
struct V_8 * V_9 = V_4 -> V_9 ;
if ( V_7 != V_153 )
return;
if ( V_4 -> V_31 . V_96 != 0x1028022f ) {
V_9 -> V_71 = V_9 -> V_51 = 0x04 ;
V_9 -> V_52 = V_9 -> V_49 = 0x04 ;
}
F_71 ( V_4 , V_187 ) ;
V_9 -> V_158 = 1 ;
}
static void F_106 ( struct V_3 * V_4 ,
const struct V_151 * V_152 , int V_7 )
{
struct V_8 * V_9 = V_4 -> V_9 ;
if ( V_7 == V_153 ) {
F_71 ( V_4 , V_188 ) ;
V_9 -> V_158 = 1 ;
}
}
static void F_107 ( struct V_3 * V_4 ,
const struct V_151 * V_152 , int V_7 )
{
struct V_8 * V_9 = V_4 -> V_9 ;
if ( V_7 == V_153 ) {
F_68 ( V_4 , V_189 ) ;
V_9 -> V_71 = V_9 -> V_51 = V_9 -> V_52 = 0 ;
}
}
static void F_108 ( struct V_3 * V_4 ,
const struct V_151 * V_152 , int V_7 )
{
struct V_8 * V_9 = V_4 -> V_9 ;
struct V_80 * V_81 ;
if ( V_7 == V_153 ) {
F_68 ( V_4 , V_190 ) ;
F_37 ( V_4 , V_4 -> V_31 . V_32 , 0 ,
V_171 , 0x10 ) ;
V_81 = F_27 ( V_4 , V_4 -> V_31 . V_32 ,
F_22 ) ;
if ( ! F_93 ( V_81 ) )
V_81 -> V_67 = 0x01 ;
V_9 -> V_52 = 0x0b ;
V_9 -> V_71 = 0x01 ;
V_9 -> V_51 = 0x1b ;
V_9 -> V_69 = 0x10 ;
V_9 -> V_49 = 0x01 ;
}
}
static void F_109 ( struct V_3 * V_4 ,
const struct V_151 * V_152 , int V_7 )
{
struct V_8 * V_9 = V_4 -> V_9 ;
if ( V_7 == V_153 )
V_9 -> V_72 = 0 ;
}
static void F_110 ( struct V_3 * V_4 ,
const struct V_151 * V_152 , int V_7 )
{
struct V_8 * V_9 = V_4 -> V_9 ;
if ( V_7 != V_153 )
return;
if ( F_42 ( V_4 , V_9 -> V_100 ) )
F_6 ( V_4 , L_16 ,
V_9 -> V_61 ,
V_9 -> V_62 ) ;
}
static int F_111 ( struct V_3 * V_4 )
{
struct V_8 * V_9 = V_4 -> V_9 ;
int V_191 ;
int V_192 = 0 ;
if ( V_9 -> V_166 )
V_192 |= V_193 ;
V_191 = F_112 ( V_4 , & V_9 -> V_15 . V_108 , NULL , V_192 ) ;
if ( V_191 < 0 )
return V_191 ;
V_9 -> V_15 . V_194 = F_1 ;
V_9 -> V_15 . V_195 = F_3 ;
V_9 -> V_15 . V_196 = F_16 ;
V_191 = F_113 ( V_4 , & V_9 -> V_15 . V_108 ) ;
if ( V_191 < 0 )
return V_191 ;
if ( V_9 -> V_63 ) {
V_191 = F_114 ( V_4 , V_9 -> V_63 ) ;
if ( V_191 < 0 )
return V_191 ;
}
if ( V_9 -> V_126 > 0 ) {
V_191 = F_46 ( V_4 ,
V_9 -> V_126 ) ;
if ( V_191 < 0 )
return V_191 ;
}
#ifdef F_115
if ( V_9 -> V_15 . V_197 ) {
T_1 V_18 = V_9 -> V_15 . V_197 ;
unsigned int V_116 ;
V_191 = F_46 ( V_4 , V_18 ) ;
if ( V_191 < 0 )
return V_191 ;
if ( V_4 -> V_130 ) {
V_4 -> V_130 -> V_198 = V_9 -> V_199 ;
V_116 = F_47 ( V_4 , V_18 , V_117 ) ;
if ( ! ( V_116 & V_123 ) ) {
V_191 = F_56 ( V_4 ) ;
if ( V_191 < 0 )
return V_191 ;
}
}
}
#endif
if ( V_9 -> V_61 )
V_9 -> V_15 . V_200 . V_201 = F_15 ;
if ( V_9 -> V_202 &&
F_31 ( V_4 , L_18 ) == 1 ) {
unsigned int V_203 =
V_9 -> V_202 -> V_93 >> 16 ;
if ( F_116 ( & V_4 -> V_31 , V_203 ) )
return - V_127 ;
if ( ! F_51 ( & V_9 -> V_15 , NULL , V_9 -> V_202 ) )
return - V_127 ;
}
if ( V_9 -> V_204 ) {
V_191 = F_62 ( V_4 ) ;
if ( V_191 < 0 )
return V_191 ;
}
F_23 ( V_4 ) ;
return 0 ;
}
static int F_117 ( struct V_3 * V_4 )
{
struct V_8 * V_9 = V_4 -> V_9 ;
int V_12 ;
F_30 ( V_4 ) ;
if ( ! V_9 -> V_72 )
V_9 -> V_49 |= V_9 -> V_71 ;
F_5 ( V_4 , V_9 -> V_51 , V_9 -> V_52 , V_9 -> V_49 ) ;
F_118 ( V_4 ) ;
if ( V_9 -> V_76 )
F_4 ( V_4 , V_4 -> V_31 . V_32 , 0 ,
V_79 ,
V_9 -> V_78 ) ;
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
static void F_119 ( struct V_3 * V_4 )
{
struct V_8 * V_9 = V_4 -> V_9 ;
F_120 ( V_4 ) ;
if ( V_9 -> V_71 )
F_5 ( V_4 , V_9 -> V_51 ,
V_9 -> V_52 , V_9 -> V_49 &
~ V_9 -> V_71 ) ;
}
static void F_121 ( struct V_205 * V_206 ,
struct V_3 * V_4 , T_1 V_18 )
{
if ( V_18 == V_4 -> V_31 . V_32 )
F_122 ( V_206 , L_19 ,
F_7 ( V_4 , V_18 , 0 ,
V_207 , 0 ) ) ;
}
static void F_123 ( struct V_205 * V_206 ,
struct V_3 * V_4 ,
unsigned int V_208 )
{
F_122 ( V_206 , L_20 ,
F_7 ( V_4 , V_4 -> V_31 . V_32 , 0 , V_208 , 0 ) ) ;
}
static void F_124 ( struct V_205 * V_206 ,
struct V_3 * V_4 , T_1 V_18 )
{
F_121 ( V_206 , V_4 , V_18 ) ;
if ( V_18 == V_4 -> V_31 . V_32 )
F_123 ( V_206 , V_4 , 0xfa0 ) ;
}
static void F_125 ( struct V_205 * V_206 ,
struct V_3 * V_4 , T_1 V_18 )
{
if ( V_18 == V_4 -> V_31 . V_32 )
F_123 ( V_206 , V_4 , 0xfe0 ) ;
}
static void F_126 ( struct V_205 * V_206 ,
struct V_3 * V_4 , T_1 V_18 )
{
if ( V_18 == V_4 -> V_31 . V_32 )
F_123 ( V_206 , V_4 , 0xfeb ) ;
}
static int F_127 ( struct V_3 * V_4 )
{
F_119 ( V_4 ) ;
return 0 ;
}
static int F_128 ( struct V_3 * V_4 )
{
struct V_8 * V_9 ;
V_9 = F_129 ( sizeof( * V_9 ) , V_209 ) ;
if ( ! V_9 )
return - V_127 ;
F_130 ( & V_9 -> V_15 ) ;
V_4 -> V_9 = V_9 ;
V_4 -> V_210 = 1 ;
V_9 -> V_15 . V_211 = true ;
return 0 ;
}
static int F_131 ( struct V_3 * V_4 )
{
struct V_8 * V_9 ;
int V_191 ;
V_191 = F_128 ( V_4 ) ;
if ( V_191 < 0 )
return V_191 ;
V_9 = V_4 -> V_9 ;
V_9 -> V_199 = 1 ;
V_9 -> V_15 . V_212 = 1 ;
V_4 -> V_213 = V_214 ;
V_4 -> V_215 = V_216 ;
F_71 ( V_4 , V_217 ) ;
F_100 ( V_4 , V_218 , V_219 ,
V_220 ) ;
F_101 ( V_4 , V_153 ) ;
V_191 = F_111 ( V_4 ) ;
if ( V_191 < 0 ) {
F_132 ( V_4 ) ;
return V_191 ;
}
F_101 ( V_4 , V_173 ) ;
return 0 ;
}
static int F_133 ( struct V_3 * V_4 )
{
struct V_8 * V_9 ;
int V_191 ;
V_191 = F_128 ( V_4 ) ;
if ( V_191 < 0 )
return V_191 ;
V_9 = V_4 -> V_9 ;
V_9 -> V_199 = 1 ;
V_9 -> V_15 . V_212 = 1 ;
V_4 -> V_213 = V_214 ;
F_71 ( V_4 , V_221 ) ;
F_100 ( V_4 , V_222 , V_223 ,
V_224 ) ;
F_101 ( V_4 , V_153 ) ;
V_191 = F_111 ( V_4 ) ;
if ( V_191 < 0 ) {
F_132 ( V_4 ) ;
return V_191 ;
}
F_101 ( V_4 , V_173 ) ;
return 0 ;
}
static int F_134 ( struct V_3 * V_4 )
{
struct V_8 * V_9 ;
int V_191 ;
int V_225 ;
V_191 = F_128 ( V_4 ) ;
if ( V_191 < 0 )
return V_191 ;
V_9 = V_4 -> V_9 ;
V_4 -> V_226 = 1 ;
V_9 -> V_199 = 0 ;
V_9 -> V_15 . V_227 = 0x1d ;
V_9 -> V_204 = 1 ;
V_225 = F_63 ( V_4 , 0x0a ) - 1 ;
if ( V_225 < 3 || V_225 > 5 ) {
F_135 ( V_4 ,
L_21 ) ;
V_225 = 5 ;
}
switch ( V_225 ) {
case 0x3 :
V_9 -> V_202 = & V_228 ;
break;
case 0x4 :
V_9 -> V_202 = & V_229 ;
break;
case 0x5 :
V_9 -> V_202 = & V_230 ;
break;
}
V_9 -> V_90 = 0x01 ;
V_9 -> V_94 = 8 ;
V_9 -> V_15 . V_197 = 0x1c ;
V_9 -> V_71 = V_9 -> V_51 = V_9 -> V_52 = 0x1 ;
V_9 -> V_49 = 0x01 ;
V_9 -> V_72 = 1 ;
V_9 -> V_76 = F_136 ( V_231 ) ;
V_9 -> V_77 = V_231 ;
V_9 -> V_15 . V_212 = 1 ;
V_9 -> V_15 . V_232 = 1 ;
V_4 -> V_213 = V_214 ;
F_100 ( V_4 , V_233 , V_234 ,
V_235 ) ;
F_101 ( V_4 , V_153 ) ;
if ( ! V_9 -> V_158 )
F_71 ( V_4 , V_236 ) ;
V_191 = F_111 ( V_4 ) ;
if ( V_191 < 0 ) {
F_132 ( V_4 ) ;
return V_191 ;
}
if ( V_9 -> V_72 && ! F_44 ( V_4 ) )
V_9 -> V_72 = 0 ;
V_4 -> V_237 = F_124 ;
F_101 ( V_4 , V_173 ) ;
return 0 ;
}
static void F_137 ( struct V_3 * V_4 )
{
struct V_8 * V_9 = V_4 -> V_9 ;
V_9 -> V_51 |= V_9 -> V_71 ;
if ( V_9 -> V_61 ) {
if ( ! V_9 -> V_63 ) {
V_9 -> V_51 |= V_9 -> V_61 ;
V_9 -> V_52 |= V_9 -> V_61 ;
V_9 -> V_49 |= V_9 -> V_61 ;
} else {
V_4 -> V_215 = F_12 ;
}
}
if ( V_9 -> V_50 ) {
V_9 -> V_51 |= V_9 -> V_50 ;
V_9 -> V_52 |= V_9 -> V_50 ;
V_9 -> V_47 = 0 ;
V_9 -> V_49 |= V_9 -> V_50 ;
V_9 -> V_15 . V_238 = F_8 ;
}
}
static int F_138 ( struct V_3 * V_4 )
{
struct V_8 * V_9 ;
int V_191 ;
V_191 = F_128 ( V_4 ) ;
if ( V_191 < 0 )
return V_191 ;
V_4 -> V_31 . V_164 &= ~ V_239 ;
V_9 = V_4 -> V_9 ;
V_4 -> V_226 = 1 ;
V_9 -> V_199 = 0 ;
V_9 -> V_15 . V_212 = 1 ;
V_9 -> V_15 . V_232 = 1 ;
V_9 -> V_15 . V_227 = 0x1b ;
V_9 -> V_15 . V_197 = 0x21 ;
V_9 -> V_77 = V_240 ;
V_9 -> V_76 = F_136 ( V_240 ) ;
V_9 -> V_100 = - 1 ;
V_4 -> V_213 = V_214 ;
F_71 ( V_4 , V_241 ) ;
F_100 ( V_4 , V_242 , V_243 ,
V_244 ) ;
F_101 ( V_4 , V_153 ) ;
F_137 ( V_4 ) ;
V_191 = F_111 ( V_4 ) ;
if ( V_191 < 0 ) {
F_132 ( V_4 ) ;
return V_191 ;
}
V_4 -> V_237 = F_121 ;
F_101 ( V_4 , V_173 ) ;
return 0 ;
}
static int F_139 ( struct V_3 * V_4 )
{
struct V_8 * V_9 ;
int V_191 ;
V_191 = F_128 ( V_4 ) ;
if ( V_191 < 0 )
return V_191 ;
V_4 -> V_31 . V_164 &= ~ V_239 ;
V_9 = V_4 -> V_9 ;
V_4 -> V_226 = 1 ;
V_9 -> V_199 = 0 ;
V_9 -> V_15 . V_212 = 1 ;
V_9 -> V_15 . V_232 = 1 ;
V_9 -> V_15 . V_197 = 0x19 ;
V_9 -> V_77 = V_245 ;
V_9 -> V_76 = F_136 ( V_245 ) ;
V_9 -> V_100 = 0 ;
V_4 -> V_213 = V_214 ;
F_100 ( V_4 , V_246 , V_247 ,
V_248 ) ;
F_101 ( V_4 , V_153 ) ;
F_137 ( V_4 ) ;
V_191 = F_111 ( V_4 ) ;
if ( V_191 < 0 ) {
F_132 ( V_4 ) ;
return V_191 ;
}
V_4 -> V_237 = F_121 ;
F_101 ( V_4 , V_173 ) ;
return 0 ;
}
static int F_140 ( struct V_3 * V_4 )
{
struct V_8 * V_9 ;
const T_1 * V_249 = V_250 ;
int V_191 ;
V_191 = F_128 ( V_4 ) ;
if ( V_191 < 0 )
return V_191 ;
V_9 = V_4 -> V_9 ;
V_9 -> V_199 = 0 ;
V_9 -> V_15 . V_212 = 1 ;
V_9 -> V_15 . V_232 = 1 ;
V_9 -> V_15 . V_227 = 0x17 ;
V_9 -> V_204 = 1 ;
V_4 -> V_213 = V_214 ;
V_9 -> V_51 = 0x01 ;
V_9 -> V_52 = 0x01 ;
V_9 -> V_49 = 0x01 ;
switch ( V_4 -> V_31 . V_95 ) {
case 0x111d76b6 :
case 0x111d76b7 :
V_249 ++ ;
break;
case 0x111d7608 :
if ( ( V_4 -> V_31 . V_251 & 0xf ) == 0 ||
( V_4 -> V_31 . V_251 & 0xf ) == 1 )
V_9 -> V_11 = 40 ;
V_249 ++ ;
F_73 ( V_4 , 0x0f , 0x40f000f0 ) ;
F_73 ( V_4 , 0x19 , 0x40f000f3 ) ;
break;
case 0x111d7603 :
if ( ( V_4 -> V_31 . V_251 & 0xf ) == 1 )
V_9 -> V_11 = 40 ;
break;
}
if ( F_141 ( F_142 ( V_4 , 0x28 ) ) == V_252 )
F_71 ( V_4 , V_253 ) ;
if ( F_142 ( V_4 , 0xa ) & V_254 ) {
const T_1 * V_255 ;
for ( V_255 = V_249 ; * V_255 ; V_255 ++ )
F_143 ( V_4 , * V_255 , V_256 , 0 ,
0xff , 0x00 ) ;
}
V_9 -> V_202 = & V_257 ;
V_9 -> V_90 = 0x50 ;
V_9 -> V_94 = 0 ;
V_9 -> V_14 = 1 ;
V_9 -> V_15 . V_197 = 0x26 ;
V_9 -> V_76 = F_136 ( V_258 ) ;
V_9 -> V_77 = V_258 ;
F_100 ( V_4 , V_259 , V_260 ,
V_261 ) ;
F_101 ( V_4 , V_153 ) ;
F_137 ( V_4 ) ;
V_191 = F_111 ( V_4 ) ;
if ( V_191 < 0 ) {
F_132 ( V_4 ) ;
return V_191 ;
}
V_4 -> V_237 = F_124 ;
F_101 ( V_4 , V_173 ) ;
return 0 ;
}
static int F_144 ( struct V_3 * V_4 )
{
struct V_8 * V_9 ;
int V_191 ;
V_191 = F_128 ( V_4 ) ;
if ( V_191 < 0 )
return V_191 ;
V_9 = V_4 -> V_9 ;
V_9 -> V_199 = 1 ;
V_9 -> V_15 . V_212 = 1 ;
V_4 -> V_213 = V_214 ;
F_71 ( V_4 , V_262 ) ;
F_145 ( V_4 , 0x12 , V_117 ,
( 0 << V_263 ) |
( 2 << V_129 ) |
( 0x27 << V_264 ) |
( 0 << V_124 ) ) ;
F_100 ( V_4 , V_265 , V_266 ,
V_185 ) ;
F_101 ( V_4 , V_153 ) ;
V_191 = F_111 ( V_4 ) ;
if ( V_191 < 0 ) {
F_132 ( V_4 ) ;
return V_191 ;
}
F_101 ( V_4 , V_173 ) ;
return 0 ;
}
static int F_146 ( struct V_3 * V_4 )
{
struct V_8 * V_9 ;
int V_191 ;
V_191 = F_128 ( V_4 ) ;
if ( V_191 < 0 )
return V_191 ;
V_9 = V_4 -> V_9 ;
V_9 -> V_199 = 1 ;
V_9 -> V_15 . V_212 = 1 ;
V_9 -> V_204 = 1 ;
V_9 -> V_143 = V_267 ;
V_9 -> V_15 . V_197 = 0x23 ;
V_9 -> V_71 = V_9 -> V_51 = 0x01 ;
V_9 -> V_52 = V_9 -> V_49 = 0x01 ;
V_9 -> V_202 = & V_268 ;
V_9 -> V_90 = 0x40 ;
V_9 -> V_94 = 0 ;
V_9 -> V_72 = 1 ;
V_4 -> V_213 = V_214 ;
F_100 ( V_4 , V_269 , V_270 ,
V_271 ) ;
F_101 ( V_4 , V_153 ) ;
if ( ! V_9 -> V_158 )
F_71 ( V_4 , V_272 ) ;
V_191 = F_111 ( V_4 ) ;
if ( V_191 < 0 ) {
F_132 ( V_4 ) ;
return V_191 ;
}
V_4 -> V_237 = F_126 ;
V_4 -> V_273 -> V_274 = 1 ;
F_101 ( V_4 , V_173 ) ;
return 0 ;
}
static int F_147 ( struct V_3 * V_4 )
{
struct V_8 * V_9 ;
int V_191 ;
V_191 = F_128 ( V_4 ) ;
if ( V_191 < 0 )
return V_191 ;
V_9 = V_4 -> V_9 ;
V_9 -> V_199 = 1 ;
V_9 -> V_15 . V_212 = 1 ;
V_9 -> V_204 = 1 ;
V_9 -> V_15 . V_197 = 0x23 ;
F_71 ( V_4 , V_275 ) ;
V_9 -> V_202 = & V_276 ;
V_9 -> V_90 = 0x40 ;
V_9 -> V_94 = 0 ;
V_9 -> V_71 = V_9 -> V_51 = V_9 -> V_52 = 0x1 ;
V_9 -> V_49 = 0x01 ;
V_9 -> V_72 = 1 ;
V_4 -> V_213 = V_214 ;
F_100 ( V_4 , V_277 , V_278 ,
V_279 ) ;
F_101 ( V_4 , V_153 ) ;
V_191 = F_111 ( V_4 ) ;
if ( V_191 < 0 ) {
F_132 ( V_4 ) ;
return V_191 ;
}
V_4 -> V_237 = F_125 ;
F_101 ( V_4 , V_173 ) ;
return 0 ;
}
static int F_148 ( struct V_3 * V_4 )
{
struct V_8 * V_9 ;
int V_191 ;
V_191 = F_128 ( V_4 ) ;
if ( V_191 < 0 )
return V_191 ;
V_9 = V_4 -> V_9 ;
V_9 -> V_199 = 1 ;
V_9 -> V_15 . V_212 = 1 ;
V_4 -> V_213 = V_214 ;
F_71 ( V_4 , V_280 ) ;
F_100 ( V_4 , V_281 , V_282 ,
V_283 ) ;
F_101 ( V_4 , V_153 ) ;
V_191 = F_111 ( V_4 ) ;
if ( V_191 < 0 ) {
F_132 ( V_4 ) ;
return - V_148 ;
}
F_101 ( V_4 , V_173 ) ;
return 0 ;
}
