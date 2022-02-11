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
if ( V_79 && V_79 -> V_18 ) {
F_18 ( V_4 , V_79 -> V_18 ,
F_20 ( V_4 , V_79 -> V_18 ) ,
true ) ;
return;
}
for ( V_12 = 0 ; V_12 < V_9 -> V_74 ; V_12 ++ ) {
T_1 V_18 = V_9 -> V_75 [ V_12 ] ;
V_79 = F_21 ( V_4 , V_18 ) ;
if ( ! V_79 || ! V_79 -> V_7 )
continue;
if ( V_79 -> V_7 == V_80 ||
V_79 -> V_7 <= V_81 )
F_18 ( V_4 , V_18 ,
F_20 ( V_4 , V_18 ) ,
false ) ;
}
F_4 ( V_4 , V_4 -> V_31 , 0 , V_77 ,
V_9 -> V_76 ) ;
}
static void F_22 ( struct V_3 * V_4 ,
struct V_78 * V_79 )
{
F_23 ( V_4 , V_79 ) ;
F_19 ( V_4 , V_79 ) ;
}
static void F_24 ( struct V_3 * V_4 ,
struct V_78 * V_79 )
{
F_25 ( V_4 , V_79 ) ;
F_19 ( V_4 , V_79 ) ;
}
static void F_26 ( struct V_3 * V_4 ,
struct V_78 * V_79 )
{
F_27 ( V_4 , V_79 ) ;
F_19 ( V_4 , V_79 ) ;
}
static void F_28 ( struct V_3 * V_4 , struct V_78 * V_82 )
{
unsigned int V_26 ;
V_26 = F_7 ( V_4 , V_4 -> V_31 , 0 ,
V_32 , 0 ) ;
F_4 ( V_4 , V_4 -> V_31 , 0 , 0x7e0 ,
! ! ( V_26 & ( 1 << V_82 -> V_65 ) ) ) ;
}
static void F_29 ( struct V_3 * V_4 )
{
struct V_8 * V_9 = V_4 -> V_9 ;
int V_12 ;
for ( V_12 = 0 ; V_12 < V_9 -> V_74 ; V_12 ++ ) {
T_1 V_18 = V_9 -> V_75 [ V_12 ] ;
unsigned int V_83 = F_30 ( V_4 , V_18 ) ;
V_83 = F_31 ( V_83 ) ;
if ( F_21 ( V_4 , V_18 ) )
continue;
if ( V_83 == V_84 &&
V_9 -> V_61 != V_18 &&
F_32 ( V_4 , V_18 ) ) {
F_33 ( V_4 , V_18 ,
V_80 ,
F_19 ) ;
} else {
if ( V_83 == V_85 )
F_18 ( V_4 , V_18 , false , false ) ;
else
F_18 ( V_4 , V_18 , true , false ) ;
}
}
}
static inline bool F_34 ( struct V_3 * V_4 , const char * V_86 ,
int * V_87 )
{
return ! F_35 ( V_4 , V_86 , V_87 ) ;
}
static void F_36 ( struct V_3 * V_4 )
{
struct V_8 * V_9 = V_4 -> V_9 ;
int V_66 ;
if ( F_34 ( V_4 , L_3 , & V_9 -> V_49 ) ) {
V_9 -> V_69 = V_9 -> V_50 = V_9 -> V_47 =
V_9 -> V_49 ;
}
if ( F_34 ( V_4 , L_4 , & V_9 -> V_50 ) )
V_9 -> V_49 &= V_9 -> V_49 ;
if ( F_34 ( V_4 , L_5 , & V_9 -> V_47 ) )
V_9 -> V_50 &= V_9 -> V_49 ;
if ( F_34 ( V_4 , L_6 , & V_9 -> V_69 ) )
V_9 -> V_69 &= V_9 -> V_49 ;
if ( F_34 ( V_4 , L_7 , & V_9 -> V_67 ) )
V_9 -> V_67 &= V_9 -> V_49 ;
V_66 = F_37 ( V_4 , L_8 ) ;
if ( V_66 >= 0 )
V_9 -> V_70 = V_66 ;
}
static int F_38 ( struct V_38 * V_39 ,
struct V_40 * V_41 )
{
struct V_3 * V_4 = F_39 ( V_39 ) ;
unsigned int V_13 = F_9 ( V_39 , & V_41 -> V_44 ) ;
struct V_8 * V_9 = V_4 -> V_9 ;
V_41 -> V_46 . integer . V_46 [ 0 ] = ! ! ( V_9 -> V_88 &
( V_9 -> V_89 << V_13 ) ) ;
return 0 ;
}
static int F_40 ( struct V_38 * V_39 ,
struct V_40 * V_41 )
{
struct V_3 * V_4 = F_39 ( V_39 ) ;
struct V_8 * V_9 = V_4 -> V_9 ;
unsigned int V_13 = F_9 ( V_39 , & V_41 -> V_44 ) ;
unsigned int V_90 ;
unsigned int V_66 , V_91 ;
V_91 = V_9 -> V_89 << V_13 ;
if ( V_41 -> V_46 . integer . V_46 [ 0 ] )
V_66 = V_9 -> V_88 | V_91 ;
else
V_66 = V_9 -> V_88 & ~ V_91 ;
if ( V_9 -> V_88 == V_66 )
return 0 ;
V_9 -> V_88 = V_66 ;
V_90 = F_7 ( V_4 , V_4 -> V_31 , 0 ,
V_39 -> V_92 & 0xFFFF , 0x0 ) ;
V_90 >>= V_9 -> V_93 ;
if ( V_9 -> V_88 & V_91 ) {
F_41 ( V_4 ) ;
V_90 |= V_91 ;
} else {
F_42 ( V_4 ) ;
V_90 &= ~ V_91 ;
}
F_43 ( V_4 , V_4 -> V_31 , 0 ,
V_39 -> V_92 >> 16 , V_90 ) ;
return 1 ;
}
static bool F_44 ( struct V_3 * V_4 )
{
if ( V_4 -> V_94 != 0x111d7605 &&
V_4 -> V_94 != 0x111d76d1 )
return false ;
switch ( V_4 -> V_95 ) {
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
static bool F_45 ( T_2 V_95 )
{
switch ( V_95 ) {
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
static void F_46 ( struct V_3 * V_4 )
{
struct V_8 * V_9 = V_4 -> V_9 ;
unsigned int V_96 ;
if ( V_9 -> V_59 )
return;
V_96 = F_47 ( V_4 , V_4 -> V_31 , V_97 ) ;
V_96 &= V_98 ;
if ( V_96 > 3 )
V_9 -> V_59 = 0x08 ;
else
V_9 -> V_59 = 0x01 ;
}
static int F_48 ( struct V_3 * V_4 , int V_99 )
{
struct V_8 * V_9 = V_4 -> V_9 ;
const struct V_100 * V_101 = NULL ;
if ( F_34 ( V_4 , L_9 , & V_9 -> V_59 ) ) {
F_34 ( V_4 , L_10 ,
& V_9 -> V_60 ) ;
return 1 ;
}
while ( ( V_101 = F_49 ( V_102 , NULL , V_101 ) ) ) {
if ( sscanf ( V_101 -> V_103 , L_11 ,
& V_9 -> V_60 ,
& V_9 -> V_59 ) == 2 ) {
unsigned int V_104 ;
V_104 = F_47 ( V_4 , V_4 -> V_31 ,
V_97 ) ;
V_104 &= V_98 ;
if ( V_9 -> V_59 < V_104 )
V_9 -> V_59 = 1 << V_9 -> V_59 ;
else
V_9 -> V_61 = V_9 -> V_59 ;
return 1 ;
}
if ( sscanf ( V_101 -> V_103 , L_12 ,
& V_9 -> V_60 ) == 1 ) {
F_46 ( V_4 ) ;
return 1 ;
}
if ( strstr ( V_101 -> V_103 , L_13 ) ) {
F_46 ( V_4 ) ;
if ( V_99 >= 0 )
V_9 -> V_60 = V_99 ;
else
V_9 -> V_60 = 1 ;
return 1 ;
}
}
if ( ! F_45 ( V_4 -> V_95 ) &&
( V_99 == 0 || V_99 == 1 ) ) {
F_46 ( V_4 ) ;
V_9 -> V_60 = V_99 ;
return 1 ;
}
return 0 ;
}
static bool F_50 ( struct V_3 * V_4 )
{
struct V_8 * V_9 = V_4 -> V_9 ;
T_1 * V_105 ;
int V_106 , V_12 ;
if ( V_9 -> V_15 . V_107 . V_108 == V_109 ) {
V_105 = V_9 -> V_15 . V_107 . V_110 ;
V_106 = V_9 -> V_15 . V_107 . V_111 ;
} else {
V_105 = V_9 -> V_15 . V_107 . V_112 ;
V_106 = V_9 -> V_15 . V_107 . V_113 ;
}
for ( V_12 = 0 ; V_12 < V_106 ; V_12 ++ ) {
unsigned int V_83 = F_30 ( V_4 , V_105 [ V_12 ] ) ;
if ( F_51 ( V_83 ) == V_114 )
return true ;
}
return false ;
}
static int F_52 ( struct V_3 * V_4 ,
T_1 V_18 )
{
struct V_8 * V_9 = V_4 -> V_9 ;
T_2 V_115 = F_53 ( V_4 , V_18 , V_116 ) ;
struct V_117 * V_118 ;
static struct V_117 V_119 =
F_54 ( NULL , 0 , 0 , 0 ) ;
static struct V_117 V_120 =
F_55 ( NULL , 0 , 0 , 0 ) ;
static struct V_117 V_121 =
F_56 ( NULL , 0 , 0 , 0 ) ;
if ( ( V_115 & V_122 ) >> V_123 ) {
const struct V_117 * V_124 ;
if ( V_9 -> V_125 == V_18 )
V_124 = & V_119 ;
else
V_124 = & V_120 ;
V_118 = F_57 ( & V_9 -> V_15 ,
L_14 , V_124 ) ;
if ( ! V_118 )
return - V_126 ;
V_118 -> V_92 =
F_58 ( V_18 , 1 , 0 , V_116 ) ;
}
if ( ( V_115 & V_127 ) >> V_128 ) {
V_118 = F_57 ( & V_9 -> V_15 ,
L_15 ,
& V_121 ) ;
if ( ! V_118 )
return - V_126 ;
V_118 -> V_92 =
F_58 ( V_18 , 1 , 0 , V_116 ) ;
}
return 0 ;
}
static int F_59 ( struct V_38 * V_39 ,
struct V_40 * V_41 )
{
struct V_3 * V_4 = F_39 ( V_39 ) ;
V_41 -> V_46 . integer . V_46 [ 0 ] = V_4 -> V_129 -> V_57 ;
return 0 ;
}
static int F_60 ( struct V_38 * V_39 ,
struct V_40 * V_41 )
{
struct V_3 * V_4 = F_39 ( V_39 ) ;
return F_61 ( V_4 , V_41 -> V_46 . integer . V_46 [ 0 ] ) ;
}
static int F_62 ( struct V_3 * V_4 )
{
struct V_8 * V_9 = V_4 -> V_9 ;
if ( ! F_57 ( & V_9 -> V_15 , NULL , & V_130 ) )
return - V_126 ;
return 0 ;
}
static int F_63 ( struct V_38 * V_39 ,
struct V_131 * V_132 )
{
struct V_3 * V_4 = F_39 ( V_39 ) ;
struct V_8 * V_9 = V_4 -> V_9 ;
return F_64 ( & V_9 -> V_133 , V_132 ) ;
}
static int F_65 ( struct V_38 * V_39 ,
struct V_40 * V_41 )
{
struct V_3 * V_4 = F_39 ( V_39 ) ;
struct V_8 * V_9 = V_4 -> V_9 ;
unsigned int V_134 = F_9 ( V_39 , & V_41 -> V_44 ) ;
V_41 -> V_46 . V_135 . V_136 [ 0 ] = V_9 -> V_137 [ V_134 ] ;
return 0 ;
}
static int F_66 ( struct V_38 * V_39 ,
struct V_40 * V_41 )
{
struct V_3 * V_4 = F_39 ( V_39 ) ;
struct V_8 * V_9 = V_4 -> V_9 ;
unsigned int V_134 = F_9 ( V_39 , & V_41 -> V_44 ) ;
return F_67 ( V_4 , & V_9 -> V_133 , V_41 ,
V_9 -> V_15 . V_107 . V_138 [ V_134 ] ,
& V_9 -> V_137 [ V_134 ] ) ;
}
static int F_68 ( struct V_3 * V_4 )
{
struct V_8 * V_9 = V_4 -> V_9 ;
struct V_139 * V_140 = & V_9 -> V_15 . V_107 ;
const char * const * V_141 = V_9 -> V_142 ;
struct V_117 * V_143 ;
int V_12 , V_144 ;
if ( V_140 -> V_145 < 1 )
return 0 ;
V_144 = F_69 ( V_4 , V_140 -> V_138 [ 0 ] ) ;
if ( V_144 <= 1 )
return 0 ;
if ( ! V_141 )
V_141 = V_146 ;
for ( V_12 = 0 ; V_12 < V_144 ; V_12 ++ ) {
if ( F_70 ( ! V_141 [ V_12 ] ) )
return - V_147 ;
F_71 ( V_4 , & V_9 -> V_133 , V_141 [ V_12 ] , V_12 , NULL ) ;
}
V_143 = F_57 ( & V_9 -> V_15 , NULL , & V_148 ) ;
if ( ! V_143 )
return - V_126 ;
V_143 -> V_149 = V_140 -> V_145 ;
return 0 ;
}
static void F_72 ( struct V_3 * V_4 ,
const struct V_150 * V_151 , int V_7 )
{
struct V_8 * V_9 = V_4 -> V_9 ;
if ( V_7 == V_152 ) {
V_9 -> V_49 = V_9 -> V_50 = 0x09 ;
V_9 -> V_47 = 0x00 ;
V_9 -> V_15 . V_153 = 1 ;
}
}
static void F_73 ( struct V_3 * V_4 ,
const struct V_150 * V_151 , int V_7 )
{
struct V_8 * V_9 = V_4 -> V_9 ;
if ( V_7 != V_152 )
return;
F_74 ( V_4 , V_154 ) ;
V_9 -> V_49 = V_9 -> V_50 = V_9 -> V_47 = 0 ;
}
static void F_75 ( struct V_3 * V_4 )
{
struct V_8 * V_9 = V_4 -> V_9 ;
F_74 ( V_4 , V_155 ) ;
V_9 -> V_70 = 0 ;
}
static void F_76 ( struct V_3 * V_4 ,
const struct V_150 * V_151 , int V_7 )
{
struct V_8 * V_9 = V_4 -> V_9 ;
if ( V_7 != V_152 )
return;
F_75 ( V_4 ) ;
F_77 ( V_4 , V_156 ) ;
V_9 -> V_157 = 1 ;
}
static void F_78 ( struct V_3 * V_4 ,
const struct V_150 * V_151 , int V_7 )
{
if ( V_7 != V_152 )
return;
F_75 ( V_4 ) ;
F_79 ( V_4 , 0x0b , 0x90A70170 ) ;
}
static void F_80 ( struct V_3 * V_4 ,
const struct V_150 * V_151 , int V_7 )
{
if ( V_7 != V_152 )
return;
F_75 ( V_4 ) ;
F_79 ( V_4 , 0x13 , 0x90A60160 ) ;
}
static void F_81 ( struct V_3 * V_4 ,
const struct V_150 * V_151 , int V_7 )
{
if ( V_7 != V_152 )
return;
F_75 ( V_4 ) ;
F_79 ( V_4 , 0x0b , 0x90A70170 ) ;
F_79 ( V_4 , 0x13 , 0x90A60160 ) ;
}
static void F_82 ( struct V_3 * V_4 ,
const struct V_150 * V_151 , int V_7 )
{
struct V_8 * V_9 = V_4 -> V_9 ;
if ( V_7 != V_152 )
return;
F_74 ( V_4 , V_158 ) ;
V_9 -> V_70 = 0 ;
}
static void F_83 ( struct V_3 * V_4 ,
const struct V_150 * V_151 , int V_7 )
{
if ( V_7 == V_152 )
V_4 -> V_159 = 1 ;
}
static void F_84 ( struct V_3 * V_4 ,
const struct V_150 * V_151 , int V_7 )
{
struct V_8 * V_9 = V_4 -> V_9 ;
if ( V_7 != V_152 )
return;
if ( F_44 ( V_4 ) ) {
F_79 ( V_4 , 0xa , 0x2101201f ) ;
F_79 ( V_4 , 0xf , 0x2181205e ) ;
}
if ( F_48 ( V_4 , V_9 -> V_99 ) )
F_6 ( V_4 , L_16 ,
V_9 -> V_59 ,
V_9 -> V_60 ) ;
V_9 -> V_15 . V_160 = true ;
}
static void F_85 ( struct V_3 * V_4 ,
const struct V_150 * V_151 , int V_7 )
{
if ( V_7 != V_152 )
return;
F_74 ( V_4 , V_161 ) ;
F_77 ( V_4 , V_162 ) ;
}
static void F_86 ( struct V_3 * V_4 ,
const struct V_150 * V_151 , int V_7 )
{
struct V_8 * V_9 = V_4 -> V_9 ;
if ( V_7 == V_152 )
V_9 -> V_99 = 0 ;
}
static void F_87 ( struct V_3 * V_4 ,
const struct V_150 * V_151 , int V_7 )
{
struct V_8 * V_9 = V_4 -> V_9 ;
if ( V_7 == V_152 )
V_9 -> V_99 = 1 ;
}
static void F_88 ( struct V_3 * V_4 ,
const struct V_150 * V_151 , int V_7 )
{
struct V_8 * V_9 = V_4 -> V_9 ;
if ( V_7 == V_152 ) {
V_9 -> V_48 = 0x08 ;
V_4 -> V_163 -> V_164 = 1 ;
}
}
static void F_89 ( struct V_3 * V_4 ,
const struct V_150 * V_151 , int V_7 )
{
struct V_8 * V_9 = V_4 -> V_9 ;
if ( V_7 == V_152 ) {
V_9 -> V_59 = 0x10 ;
V_9 -> V_99 = 0 ;
}
}
static void F_90 ( struct V_3 * V_4 ,
const struct V_150 * V_151 , int V_7 )
{
struct V_8 * V_9 = V_4 -> V_9 ;
if ( V_7 == V_152 )
V_9 -> V_165 = 1 ;
}
static int F_91 ( struct V_38 * V_39 ,
struct V_40 * V_41 )
{
struct V_3 * V_4 = F_39 ( V_39 ) ;
struct V_8 * V_9 = V_4 -> V_9 ;
V_41 -> V_46 . integer . V_46 [ 0 ] = ! ! ( V_9 -> V_47 & 0x20 ) ;
return 0 ;
}
static int F_92 ( struct V_38 * V_39 ,
struct V_40 * V_41 )
{
struct V_3 * V_4 = F_39 ( V_39 ) ;
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
static int F_93 ( struct V_3 * V_4 )
{
struct V_8 * V_9 = V_4 -> V_9 ;
if ( ! F_57 ( & V_9 -> V_15 , L_17 ,
& V_166 ) )
return - V_126 ;
V_9 -> V_49 |= 0x20 ;
V_9 -> V_50 |= 0x20 ;
V_9 -> V_47 |= 0x20 ;
return 0 ;
}
static void F_94 ( struct V_3 * V_4 ,
const struct V_150 * V_151 , int V_7 )
{
struct V_8 * V_9 = V_4 -> V_9 ;
if ( V_7 != V_152 )
return;
F_74 ( V_4 , V_167 ) ;
V_9 -> V_49 = V_9 -> V_50 = V_9 -> V_47 = 0 ;
}
static void F_95 ( struct V_3 * V_4 ,
const struct V_150 * V_151 , int V_7 )
{
struct V_8 * V_9 = V_4 -> V_9 ;
struct V_78 * V_79 ;
if ( V_7 != V_152 )
return;
F_43 ( V_4 , V_4 -> V_31 , 0 ,
V_168 , 0x02 ) ;
F_33 ( V_4 , V_4 -> V_31 ,
V_169 ,
F_28 ) ;
V_79 = F_21 ( V_4 , V_4 -> V_31 ) ;
if ( V_79 )
V_79 -> V_65 = 0x02 ;
V_9 -> V_49 |= 0x02 ;
F_79 ( V_4 , 0x0e , 0x01813040 ) ;
}
static void F_96 ( struct V_3 * V_4 ,
const struct V_150 * V_151 , int V_7 )
{
struct V_8 * V_9 = V_4 -> V_9 ;
if ( V_7 != V_152 )
return;
V_9 -> V_59 = 0x01 ;
}
static void F_97 ( struct V_3 * V_4 ,
const struct V_150 * V_151 , int V_7 )
{
unsigned int V_170 ;
switch ( V_7 ) {
case V_152 :
F_79 ( V_4 , 0x0d , 0x90170010 ) ;
break;
case V_171 :
V_170 = F_47 ( V_4 , 0x1 , V_97 ) ;
V_170 &= V_98 ;
if ( V_170 >= 6 )
F_93 ( V_4 ) ;
break;
}
}
static void F_98 ( struct V_3 * V_4 ,
const struct V_150 * V_151 , int V_7 )
{
struct V_8 * V_9 = V_4 -> V_9 ;
if ( V_7 != V_152 )
return;
V_9 -> V_59 = 0x08 ;
}
static void F_99 ( struct V_3 * V_4 ,
const struct V_150 * V_151 , int V_7 )
{
struct V_8 * V_9 = V_4 -> V_9 ;
if ( V_7 != V_152 )
return;
if ( F_45 ( V_4 -> V_95 ) ) {
unsigned int V_172 = F_30 ( V_4 , 0x0f ) ;
if ( F_100 ( V_172 ) == V_173 ||
F_100 ( V_172 ) == V_174 ||
F_100 ( V_172 ) == V_175 ) {
V_172 = ( V_172 & ( ~ V_176 ) )
| ( V_175 <<
V_177 ) ;
V_172 = ( V_172 & ( ~ ( V_178
| V_179 ) ) )
| 0x1f ;
F_79 ( V_4 , 0x0f , V_172 ) ;
}
}
if ( F_48 ( V_4 , 1 ) )
F_6 ( V_4 , L_16 ,
V_9 -> V_59 ,
V_9 -> V_60 ) ;
}
static void F_101 ( struct V_3 * V_4 ,
const struct V_150 * V_151 ,
int V_7 )
{
if ( V_7 != V_152 )
return;
V_4 -> V_180 = V_181 ;
F_102 ( V_4 , NULL , V_182 ,
V_183 ) ;
if ( V_4 -> V_180 != V_181 )
F_103 ( V_4 , V_7 ) ;
}
static void F_104 ( struct V_3 * V_4 ,
const struct V_150 * V_151 ,
int V_7 )
{
struct V_8 * V_9 = V_4 -> V_9 ;
if ( V_7 == V_152 ) {
V_9 -> V_49 = V_9 -> V_50 = 0x03 ;
V_9 -> V_47 = 0x03 ;
}
}
static void F_105 ( struct V_3 * V_4 ,
const struct V_150 * V_151 , int V_7 )
{
if ( V_7 == V_152 )
V_4 -> V_159 = 1 ;
}
static void F_106 ( struct V_3 * V_4 ,
const struct V_150 * V_151 , int V_7 )
{
struct V_8 * V_9 = V_4 -> V_9 ;
if ( V_7 == V_152 ) {
F_74 ( V_4 , V_184 ) ;
V_9 -> V_69 = V_9 -> V_49 = 0 ;
V_9 -> V_50 = V_9 -> V_47 = 0 ;
}
}
static void F_107 ( struct V_3 * V_4 ,
const struct V_150 * V_151 , int V_7 )
{
struct V_8 * V_9 = V_4 -> V_9 ;
if ( V_7 != V_152 )
return;
if ( V_4 -> V_95 != 0x1028022f ) {
V_9 -> V_69 = V_9 -> V_49 = 0x04 ;
V_9 -> V_50 = V_9 -> V_47 = 0x04 ;
}
F_77 ( V_4 , V_185 ) ;
V_9 -> V_157 = 1 ;
}
static void F_108 ( struct V_3 * V_4 ,
const struct V_150 * V_151 , int V_7 )
{
struct V_8 * V_9 = V_4 -> V_9 ;
if ( V_7 == V_152 ) {
F_77 ( V_4 , V_186 ) ;
V_9 -> V_157 = 1 ;
}
}
static void F_109 ( struct V_3 * V_4 ,
const struct V_150 * V_151 , int V_7 )
{
struct V_8 * V_9 = V_4 -> V_9 ;
if ( V_7 == V_152 ) {
F_74 ( V_4 , V_187 ) ;
V_9 -> V_69 = V_9 -> V_49 = V_9 -> V_50 = 0 ;
}
}
static void F_110 ( struct V_3 * V_4 ,
const struct V_150 * V_151 , int V_7 )
{
struct V_8 * V_9 = V_4 -> V_9 ;
struct V_78 * V_79 ;
if ( V_7 == V_152 ) {
F_74 ( V_4 , V_188 ) ;
F_43 ( V_4 , V_4 -> V_31 , 0 ,
V_168 , 0x10 ) ;
F_33 ( V_4 , V_4 -> V_31 ,
V_169 ,
F_28 ) ;
V_79 = F_21 ( V_4 , V_4 -> V_31 ) ;
if ( V_79 )
V_79 -> V_65 = 0x01 ;
V_9 -> V_50 = 0x0b ;
V_9 -> V_69 = 0x01 ;
V_9 -> V_49 = 0x1b ;
V_9 -> V_67 = 0x10 ;
V_9 -> V_47 = 0x01 ;
}
}
static void F_111 ( struct V_3 * V_4 ,
const struct V_150 * V_151 , int V_7 )
{
struct V_8 * V_9 = V_4 -> V_9 ;
if ( V_7 == V_152 )
V_9 -> V_70 = 0 ;
}
static void F_112 ( struct V_3 * V_4 ,
const struct V_150 * V_151 , int V_7 )
{
struct V_8 * V_9 = V_4 -> V_9 ;
if ( V_7 != V_152 )
return;
if ( F_48 ( V_4 , V_9 -> V_99 ) )
F_6 ( V_4 , L_16 ,
V_9 -> V_59 ,
V_9 -> V_60 ) ;
}
static int F_113 ( struct V_3 * V_4 )
{
struct V_8 * V_9 = V_4 -> V_9 ;
int V_189 ;
int V_190 = 0 ;
if ( V_9 -> V_165 )
V_190 |= V_191 ;
V_189 = F_114 ( V_4 , & V_9 -> V_15 . V_107 , NULL , V_190 ) ;
if ( V_189 < 0 )
return V_189 ;
V_9 -> V_15 . V_192 = F_1 ;
V_9 -> V_15 . V_193 = F_3 ;
V_9 -> V_15 . V_194 = F_16 ;
V_9 -> V_15 . V_195 = F_22 ;
V_9 -> V_15 . V_196 = F_24 ;
V_9 -> V_15 . V_197 = F_26 ;
V_189 = F_115 ( V_4 , & V_9 -> V_15 . V_107 ) ;
if ( V_189 < 0 )
return V_189 ;
V_9 -> V_15 . V_198 [ 3 ] |= V_199 ;
if ( V_9 -> V_125 > 0 ) {
V_189 = F_52 ( V_4 ,
V_9 -> V_125 ) ;
if ( V_189 < 0 )
return V_189 ;
}
#ifdef F_116
if ( V_9 -> V_15 . V_200 ) {
T_1 V_18 = V_9 -> V_15 . V_200 ;
unsigned int V_115 ;
V_189 = F_52 ( V_4 , V_18 ) ;
if ( V_189 < 0 )
return V_189 ;
if ( V_4 -> V_129 ) {
V_4 -> V_129 -> V_201 = V_9 -> V_202 ;
V_115 = F_53 ( V_4 , V_18 , V_116 ) ;
if ( ! ( V_115 & V_122 ) ) {
V_189 = F_62 ( V_4 ) ;
if ( V_189 < 0 )
return V_189 ;
}
}
}
#endif
if ( V_9 -> V_59 )
V_9 -> V_15 . V_203 . V_204 = F_15 ;
if ( V_9 -> V_205 &&
F_37 ( V_4 , L_18 ) == 1 ) {
if ( ! F_57 ( & V_9 -> V_15 , NULL , V_9 -> V_205 ) )
return - V_126 ;
}
if ( V_9 -> V_206 ) {
V_189 = F_68 ( V_4 ) ;
if ( V_189 < 0 )
return V_189 ;
}
return 0 ;
}
static int F_117 ( struct V_3 * V_4 )
{
int V_189 = F_118 ( V_4 ) ;
if ( V_189 < 0 )
return V_189 ;
F_29 ( V_4 ) ;
return 0 ;
}
static int F_119 ( struct V_3 * V_4 )
{
struct V_8 * V_9 = V_4 -> V_9 ;
int V_12 ;
F_36 ( V_4 ) ;
if ( ! V_9 -> V_70 )
V_9 -> V_47 |= V_9 -> V_69 ;
F_5 ( V_4 , V_9 -> V_49 , V_9 -> V_50 , V_9 -> V_47 ) ;
F_120 ( V_4 ) ;
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
static void F_121 ( struct V_3 * V_4 )
{
struct V_8 * V_9 = V_4 -> V_9 ;
F_122 ( V_4 ) ;
if ( V_9 -> V_69 )
F_5 ( V_4 , V_9 -> V_49 ,
V_9 -> V_50 , V_9 -> V_47 &
~ V_9 -> V_69 ) ;
}
static void F_123 ( struct V_207 * V_208 ,
struct V_3 * V_4 , T_1 V_18 )
{
if ( V_18 == V_4 -> V_31 )
F_124 ( V_208 , L_19 ,
F_7 ( V_4 , V_18 , 0 ,
V_209 , 0 ) ) ;
}
static void F_125 ( struct V_207 * V_208 ,
struct V_3 * V_4 ,
unsigned int V_210 )
{
F_124 ( V_208 , L_20 ,
F_7 ( V_4 , V_4 -> V_31 , 0 , V_210 , 0 ) ) ;
}
static void F_126 ( struct V_207 * V_208 ,
struct V_3 * V_4 , T_1 V_18 )
{
F_123 ( V_208 , V_4 , V_18 ) ;
if ( V_18 == V_4 -> V_31 )
F_125 ( V_208 , V_4 , 0xfa0 ) ;
}
static void F_127 ( struct V_207 * V_208 ,
struct V_3 * V_4 , T_1 V_18 )
{
if ( V_18 == V_4 -> V_31 )
F_125 ( V_208 , V_4 , 0xfe0 ) ;
}
static void F_128 ( struct V_207 * V_208 ,
struct V_3 * V_4 , T_1 V_18 )
{
if ( V_18 == V_4 -> V_31 )
F_125 ( V_208 , V_4 , 0xfeb ) ;
}
static int F_129 ( struct V_3 * V_4 )
{
F_121 ( V_4 ) ;
return 0 ;
}
static int F_130 ( struct V_3 * V_4 )
{
struct V_8 * V_9 ;
V_9 = F_131 ( sizeof( * V_9 ) , V_211 ) ;
if ( ! V_9 )
return - V_126 ;
F_132 ( & V_9 -> V_15 ) ;
V_4 -> V_9 = V_9 ;
V_4 -> V_212 = 1 ;
return 0 ;
}
static int F_133 ( struct V_3 * V_4 )
{
struct V_8 * V_9 ;
int V_189 ;
V_189 = F_130 ( V_4 ) ;
if ( V_189 < 0 )
return V_189 ;
V_9 = V_4 -> V_9 ;
V_9 -> V_202 = 1 ;
V_9 -> V_15 . V_213 = 1 ;
V_4 -> V_214 = V_215 ;
V_4 -> V_216 = V_217 ;
F_77 ( V_4 , V_218 ) ;
F_102 ( V_4 , V_219 , V_220 ,
V_221 ) ;
F_103 ( V_4 , V_152 ) ;
V_189 = F_113 ( V_4 ) ;
if ( V_189 < 0 ) {
F_134 ( V_4 ) ;
return V_189 ;
}
F_103 ( V_4 , V_171 ) ;
return 0 ;
}
static int F_135 ( struct V_3 * V_4 )
{
struct V_8 * V_9 ;
int V_189 ;
V_189 = F_130 ( V_4 ) ;
if ( V_189 < 0 )
return V_189 ;
V_9 = V_4 -> V_9 ;
V_9 -> V_202 = 1 ;
V_9 -> V_15 . V_213 = 1 ;
V_4 -> V_214 = V_215 ;
F_77 ( V_4 , V_222 ) ;
F_102 ( V_4 , V_223 , V_224 ,
V_225 ) ;
F_103 ( V_4 , V_152 ) ;
V_189 = F_113 ( V_4 ) ;
if ( V_189 < 0 ) {
F_134 ( V_4 ) ;
return V_189 ;
}
F_103 ( V_4 , V_171 ) ;
return 0 ;
}
static int F_136 ( struct V_3 * V_4 )
{
struct V_8 * V_9 ;
int V_189 ;
int V_226 ;
V_189 = F_130 ( V_4 ) ;
if ( V_189 < 0 )
return V_189 ;
V_9 = V_4 -> V_9 ;
V_9 -> V_202 = 0 ;
V_9 -> V_15 . V_227 = 0x1d ;
V_9 -> V_206 = 1 ;
V_226 = F_69 ( V_4 , 0x0a ) - 1 ;
if ( V_226 < 3 || V_226 > 5 ) {
F_137 ( V_4 ,
L_21 ) ;
V_226 = 5 ;
}
switch ( V_226 ) {
case 0x3 :
V_9 -> V_205 = & V_228 ;
break;
case 0x4 :
V_9 -> V_205 = & V_229 ;
break;
case 0x5 :
V_9 -> V_205 = & V_230 ;
break;
}
V_9 -> V_89 = 0x01 ;
V_9 -> V_93 = 8 ;
V_9 -> V_15 . V_200 = 0x1c ;
V_9 -> V_69 = V_9 -> V_49 = V_9 -> V_50 = 0x1 ;
V_9 -> V_47 = 0x01 ;
V_9 -> V_70 = 1 ;
V_9 -> V_74 = F_138 ( V_231 ) ;
V_9 -> V_75 = V_231 ;
V_9 -> V_15 . V_213 = 1 ;
V_9 -> V_15 . V_232 = 1 ;
V_4 -> V_214 = V_215 ;
F_102 ( V_4 , V_233 , V_234 ,
V_235 ) ;
F_103 ( V_4 , V_152 ) ;
if ( ! V_9 -> V_157 )
F_77 ( V_4 , V_236 ) ;
V_189 = F_113 ( V_4 ) ;
if ( V_189 < 0 ) {
F_134 ( V_4 ) ;
return V_189 ;
}
if ( V_9 -> V_70 && ! F_50 ( V_4 ) )
V_9 -> V_70 = 0 ;
V_4 -> V_237 = F_126 ;
F_103 ( V_4 , V_171 ) ;
return 0 ;
}
static void F_139 ( struct V_3 * V_4 )
{
struct V_8 * V_9 = V_4 -> V_9 ;
V_9 -> V_49 |= V_9 -> V_69 ;
if ( V_9 -> V_59 ) {
if ( ! V_9 -> V_61 ) {
V_9 -> V_49 |= V_9 -> V_59 ;
V_9 -> V_50 |= V_9 -> V_59 ;
V_9 -> V_47 |= V_9 -> V_59 ;
} else {
V_4 -> V_216 = F_12 ;
}
}
if ( V_9 -> V_48 ) {
V_9 -> V_49 |= V_9 -> V_48 ;
V_9 -> V_50 |= V_9 -> V_48 ;
V_9 -> V_45 = 0 ;
V_9 -> V_47 |= V_9 -> V_48 ;
V_9 -> V_15 . V_238 = F_8 ;
}
}
static int F_140 ( struct V_3 * V_4 )
{
struct V_8 * V_9 ;
int V_189 ;
V_189 = F_130 ( V_4 ) ;
if ( V_189 < 0 )
return V_189 ;
V_4 -> V_239 = 0 ;
V_9 = V_4 -> V_9 ;
V_9 -> V_202 = 0 ;
V_9 -> V_15 . V_213 = 1 ;
V_9 -> V_15 . V_232 = 1 ;
V_9 -> V_15 . V_227 = 0x1b ;
V_9 -> V_15 . V_200 = 0x21 ;
V_9 -> V_75 = V_240 ;
V_9 -> V_74 = F_138 ( V_240 ) ;
V_9 -> V_99 = - 1 ;
V_4 -> V_214 = V_215 ;
F_77 ( V_4 , V_241 ) ;
F_102 ( V_4 , V_242 , V_243 ,
V_244 ) ;
F_103 ( V_4 , V_152 ) ;
F_139 ( V_4 ) ;
V_189 = F_113 ( V_4 ) ;
if ( V_189 < 0 ) {
F_134 ( V_4 ) ;
return V_189 ;
}
V_4 -> V_237 = F_123 ;
F_103 ( V_4 , V_171 ) ;
return 0 ;
}
static int F_141 ( struct V_3 * V_4 )
{
struct V_8 * V_9 ;
int V_189 ;
V_189 = F_130 ( V_4 ) ;
if ( V_189 < 0 )
return V_189 ;
V_4 -> V_239 = 0 ;
V_9 = V_4 -> V_9 ;
V_9 -> V_202 = 0 ;
V_9 -> V_15 . V_213 = 1 ;
V_9 -> V_15 . V_232 = 1 ;
V_9 -> V_15 . V_200 = 0x19 ;
V_9 -> V_75 = V_245 ;
V_9 -> V_74 = F_138 ( V_245 ) ;
V_9 -> V_99 = 0 ;
V_4 -> V_214 = V_215 ;
F_102 ( V_4 , V_246 , V_247 ,
V_248 ) ;
F_103 ( V_4 , V_152 ) ;
F_139 ( V_4 ) ;
V_189 = F_113 ( V_4 ) ;
if ( V_189 < 0 ) {
F_134 ( V_4 ) ;
return V_189 ;
}
V_4 -> V_237 = F_123 ;
F_103 ( V_4 , V_171 ) ;
return 0 ;
}
static int F_142 ( struct V_3 * V_4 )
{
struct V_8 * V_9 ;
const struct V_249 * V_250 = V_251 ;
int V_189 ;
V_189 = F_130 ( V_4 ) ;
if ( V_189 < 0 )
return V_189 ;
V_9 = V_4 -> V_9 ;
V_9 -> V_202 = 0 ;
V_9 -> V_15 . V_213 = 1 ;
V_9 -> V_15 . V_232 = 1 ;
V_9 -> V_15 . V_227 = 0x17 ;
V_9 -> V_206 = 1 ;
V_4 -> V_214 = V_215 ;
V_9 -> V_49 = 0x01 ;
V_9 -> V_50 = 0x01 ;
V_9 -> V_47 = 0x01 ;
switch ( V_4 -> V_94 ) {
case 0x111d76b6 :
case 0x111d76b7 :
V_250 ++ ;
break;
case 0x111d7608 :
if ( ( V_4 -> V_252 & 0xf ) == 0 ||
( V_4 -> V_252 & 0xf ) == 1 )
V_9 -> V_11 = 40 ;
V_250 ++ ;
F_79 ( V_4 , 0x0f , 0x40f000f0 ) ;
F_79 ( V_4 , 0x19 , 0x40f000f3 ) ;
break;
case 0x111d7603 :
if ( ( V_4 -> V_252 & 0xf ) == 1 )
V_9 -> V_11 = 40 ;
break;
}
if ( F_143 ( F_144 ( V_4 , 0x28 ) ) == V_253 )
F_77 ( V_4 , V_254 ) ;
if ( F_144 ( V_4 , 0xa ) & V_255 )
F_145 ( V_4 , V_250 ) ;
V_9 -> V_205 = & V_256 ;
V_9 -> V_89 = 0x50 ;
V_9 -> V_93 = 0 ;
V_9 -> V_14 = 1 ;
V_9 -> V_15 . V_200 = 0x26 ;
V_9 -> V_74 = F_138 ( V_257 ) ;
V_9 -> V_75 = V_257 ;
F_102 ( V_4 , V_258 , V_259 ,
V_260 ) ;
F_103 ( V_4 , V_152 ) ;
F_139 ( V_4 ) ;
V_189 = F_113 ( V_4 ) ;
if ( V_189 < 0 ) {
F_134 ( V_4 ) ;
return V_189 ;
}
V_4 -> V_237 = F_126 ;
F_103 ( V_4 , V_171 ) ;
return 0 ;
}
static int F_146 ( struct V_3 * V_4 )
{
struct V_8 * V_9 ;
int V_189 ;
V_189 = F_130 ( V_4 ) ;
if ( V_189 < 0 )
return V_189 ;
V_9 = V_4 -> V_9 ;
V_9 -> V_202 = 1 ;
V_9 -> V_15 . V_213 = 1 ;
V_4 -> V_214 = V_215 ;
F_77 ( V_4 , V_261 ) ;
F_147 ( V_4 , 0x12 , V_116 ,
( 0 << V_262 ) |
( 2 << V_128 ) |
( 0x27 << V_263 ) |
( 0 << V_123 ) ) ;
F_102 ( V_4 , V_264 , V_265 ,
V_183 ) ;
F_103 ( V_4 , V_152 ) ;
V_189 = F_113 ( V_4 ) ;
if ( V_189 < 0 ) {
F_134 ( V_4 ) ;
return V_189 ;
}
F_103 ( V_4 , V_171 ) ;
return 0 ;
}
static int F_148 ( struct V_3 * V_4 )
{
struct V_8 * V_9 ;
int V_189 ;
V_189 = F_130 ( V_4 ) ;
if ( V_189 < 0 )
return V_189 ;
V_9 = V_4 -> V_9 ;
V_9 -> V_202 = 1 ;
V_9 -> V_15 . V_213 = 1 ;
V_9 -> V_206 = 1 ;
V_9 -> V_142 = V_266 ;
V_9 -> V_15 . V_200 = 0x23 ;
V_9 -> V_69 = V_9 -> V_49 = 0x01 ;
V_9 -> V_50 = V_9 -> V_47 = 0x01 ;
V_9 -> V_205 = & V_267 ;
V_9 -> V_89 = 0x40 ;
V_9 -> V_93 = 0 ;
V_9 -> V_70 = 1 ;
V_4 -> V_214 = V_215 ;
F_102 ( V_4 , V_268 , V_269 ,
V_270 ) ;
F_103 ( V_4 , V_152 ) ;
if ( ! V_9 -> V_157 )
F_77 ( V_4 , V_271 ) ;
V_189 = F_113 ( V_4 ) ;
if ( V_189 < 0 ) {
F_134 ( V_4 ) ;
return V_189 ;
}
V_4 -> V_237 = F_128 ;
V_4 -> V_163 -> V_272 = 1 ;
F_103 ( V_4 , V_171 ) ;
return 0 ;
}
static int F_149 ( struct V_3 * V_4 )
{
struct V_8 * V_9 ;
int V_189 ;
V_189 = F_130 ( V_4 ) ;
if ( V_189 < 0 )
return V_189 ;
V_9 = V_4 -> V_9 ;
V_9 -> V_202 = 1 ;
V_9 -> V_15 . V_213 = 1 ;
V_9 -> V_206 = 1 ;
V_9 -> V_15 . V_200 = 0x23 ;
F_77 ( V_4 , V_273 ) ;
V_9 -> V_205 = & V_274 ;
V_9 -> V_89 = 0x40 ;
V_9 -> V_93 = 0 ;
V_9 -> V_69 = V_9 -> V_49 = V_9 -> V_50 = 0x1 ;
V_9 -> V_47 = 0x01 ;
V_9 -> V_70 = 1 ;
V_4 -> V_214 = V_215 ;
F_102 ( V_4 , V_275 , V_276 ,
V_277 ) ;
F_103 ( V_4 , V_152 ) ;
V_189 = F_113 ( V_4 ) ;
if ( V_189 < 0 ) {
F_134 ( V_4 ) ;
return V_189 ;
}
V_4 -> V_237 = F_127 ;
F_103 ( V_4 , V_171 ) ;
return 0 ;
}
static int F_150 ( struct V_3 * V_4 )
{
struct V_8 * V_9 ;
int V_189 ;
V_189 = F_130 ( V_4 ) ;
if ( V_189 < 0 )
return V_189 ;
V_9 = V_4 -> V_9 ;
V_9 -> V_202 = 1 ;
V_9 -> V_15 . V_213 = 1 ;
V_4 -> V_214 = V_215 ;
F_77 ( V_4 , V_278 ) ;
F_102 ( V_4 , V_279 , V_280 ,
V_281 ) ;
F_103 ( V_4 , V_152 ) ;
V_189 = F_113 ( V_4 ) ;
if ( V_189 < 0 ) {
F_134 ( V_4 ) ;
return - V_147 ;
}
F_103 ( V_4 , V_171 ) ;
return 0 ;
}
static int T_3 F_151 ( void )
{
return F_152 ( & V_282 ) ;
}
static void T_4 F_153 ( void )
{
F_154 ( & V_282 ) ;
}
