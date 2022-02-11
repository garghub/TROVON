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
F_6 ( L_1 , V_30 , V_24 , V_25 , V_26 ) ;
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
struct V_38 * V_39 )
{
struct V_8 * V_9 = V_4 -> V_9 ;
bool V_40 ;
if ( ! V_39 )
return;
V_40 = ! ( V_39 -> V_41 . integer . V_41 [ 0 ] ||
V_39 -> V_41 . integer . V_41 [ 1 ] ) ;
if ( V_9 -> V_42 != V_40 ) {
V_9 -> V_42 = V_40 ;
if ( V_40 )
V_9 -> V_43 |= V_9 -> V_44 ;
else
V_9 -> V_43 &= ~ V_9 -> V_44 ;
F_5 ( V_4 , V_9 -> V_45 ,
V_9 -> V_46 , V_9 -> V_43 ) ;
}
}
static int F_9 ( struct V_3 * V_4 ,
T_1 V_18 , unsigned int V_47 )
{
int error , V_48 ;
F_6 ( L_2 , V_30 , V_18 , V_47 ) ;
V_48 = F_7 ( V_4 , V_18 , 0 ,
V_49 , 0 ) ;
if ( V_48 < 0 )
return V_48 ;
V_48 &= 0xff ;
V_48 &= ~ V_50 ;
V_48 |= ( V_47 & V_50 ) ;
error = F_10 ( V_4 , V_18 , V_48 ) ;
if ( error < 0 )
return error ;
return 1 ;
}
static void F_11 ( struct V_3 * V_4 , int V_51 )
{
struct V_8 * V_9 = V_4 -> V_9 ;
int V_52 = ! V_51 ;
if ( ! V_9 -> V_53 )
return;
if ( V_9 -> V_54 )
V_52 = ! V_52 ;
if ( ! V_9 -> V_55 ) {
if ( V_52 )
V_9 -> V_43 |= V_9 -> V_53 ;
else
V_9 -> V_43 &= ~ V_9 -> V_53 ;
F_5 ( V_4 , V_9 -> V_45 ,
V_9 -> V_46 , V_9 -> V_43 ) ;
} else {
V_9 -> V_56 = V_52 ? V_57 : V_58 ;
F_9 ( V_4 , V_9 -> V_55 ,
V_9 -> V_56 ) ;
}
}
static void F_12 ( void * V_59 , int V_60 )
{
F_11 ( V_59 , V_60 ) ;
}
static void F_13 ( struct V_3 * V_4 )
{
struct V_8 * V_9 = V_4 -> V_9 ;
if ( V_9 -> V_61 )
V_9 -> V_15 . V_62 =
! ( F_7 ( V_4 , V_4 -> V_31 , 0 ,
V_32 , 0 ) & V_9 -> V_61 ) ;
F_14 ( V_4 ) ;
if ( V_9 -> V_63 && V_9 -> V_64 ) {
unsigned int V_60 = V_9 -> V_43 ;
if ( V_9 -> V_15 . V_65 )
V_60 &= ~ V_9 -> V_63 ;
else
V_60 |= V_9 -> V_63 ;
if ( V_9 -> V_43 != V_60 )
F_5 ( V_4 , V_9 -> V_45 , V_9 -> V_46 ,
V_60 ) ;
}
}
static void F_15 ( struct V_3 * V_4 , T_1 V_18 ,
bool V_66 , bool V_67 )
{
struct V_8 * V_9 = V_4 -> V_9 ;
unsigned int V_13 , V_60 ;
for ( V_13 = 0 ; V_13 < V_9 -> V_68 ; V_13 ++ ) {
if ( V_9 -> V_69 [ V_13 ] == V_18 )
break;
}
if ( V_13 >= V_9 -> V_68 )
return;
V_13 = 1 << V_13 ;
V_60 = V_9 -> V_70 ;
if ( V_66 )
V_60 &= ~ V_13 ;
else
V_60 |= V_13 ;
if ( V_60 != V_9 -> V_70 ) {
V_9 -> V_70 = V_60 ;
if ( V_67 )
F_4 ( V_4 , V_4 -> V_31 , 0 ,
V_71 , V_60 ) ;
}
}
static void F_16 ( struct V_3 * V_4 ,
struct V_72 * V_73 )
{
struct V_8 * V_9 = V_4 -> V_9 ;
int V_12 ;
if ( ! V_9 -> V_68 )
return;
if ( V_73 && V_73 -> V_18 ) {
F_15 ( V_4 , V_73 -> V_18 ,
F_17 ( V_4 , V_73 -> V_18 ) ,
true ) ;
return;
}
for ( V_12 = 0 ; V_12 < V_9 -> V_68 ; V_12 ++ ) {
T_1 V_18 = V_9 -> V_69 [ V_12 ] ;
V_73 = F_18 ( V_4 , V_18 ) ;
if ( ! V_73 || ! V_73 -> V_7 )
continue;
if ( V_73 -> V_7 == V_74 ||
V_73 -> V_7 <= V_75 )
F_15 ( V_4 , V_18 ,
F_17 ( V_4 , V_18 ) ,
false ) ;
}
F_4 ( V_4 , V_4 -> V_31 , 0 , V_71 ,
V_9 -> V_70 ) ;
}
static void F_19 ( struct V_3 * V_4 ,
struct V_72 * V_73 )
{
F_20 ( V_4 , V_73 ) ;
F_16 ( V_4 , V_73 ) ;
}
static void F_21 ( struct V_3 * V_4 ,
struct V_72 * V_73 )
{
F_22 ( V_4 , V_73 ) ;
F_16 ( V_4 , V_73 ) ;
}
static void F_23 ( struct V_3 * V_4 ,
struct V_72 * V_73 )
{
F_24 ( V_4 , V_73 ) ;
F_16 ( V_4 , V_73 ) ;
}
static void F_25 ( struct V_3 * V_4 , struct V_72 * V_76 )
{
unsigned int V_26 ;
V_26 = F_7 ( V_4 , V_4 -> V_31 , 0 ,
V_32 , 0 ) ;
F_4 ( V_4 , V_4 -> V_31 , 0 , 0x7e0 ,
! ! ( V_26 & ( 1 << V_76 -> V_59 ) ) ) ;
}
static void F_26 ( struct V_3 * V_4 )
{
struct V_8 * V_9 = V_4 -> V_9 ;
int V_12 ;
for ( V_12 = 0 ; V_12 < V_9 -> V_68 ; V_12 ++ ) {
T_1 V_18 = V_9 -> V_69 [ V_12 ] ;
unsigned int V_77 = F_27 ( V_4 , V_18 ) ;
V_77 = F_28 ( V_77 ) ;
if ( F_18 ( V_4 , V_18 ) )
continue;
if ( V_77 == V_78 &&
! ( V_9 -> V_55 == V_18 ||
F_29 ( V_4 , V_18 ) ) ) {
F_30 ( V_4 , V_18 ,
V_74 ,
F_16 ) ;
} else {
if ( V_77 == V_79 )
F_15 ( V_4 , V_18 , false , false ) ;
else
F_15 ( V_4 , V_18 , true , false ) ;
}
}
}
static inline bool F_31 ( struct V_3 * V_4 , const char * V_80 ,
int * V_81 )
{
return ! F_32 ( V_4 , V_80 , V_81 ) ;
}
static void F_33 ( struct V_3 * V_4 )
{
struct V_8 * V_9 = V_4 -> V_9 ;
int V_60 ;
if ( F_31 ( V_4 , L_3 , & V_9 -> V_45 ) ) {
V_9 -> V_63 = V_9 -> V_46 = V_9 -> V_43 =
V_9 -> V_45 ;
}
if ( F_31 ( V_4 , L_4 , & V_9 -> V_46 ) )
V_9 -> V_45 &= V_9 -> V_45 ;
if ( F_31 ( V_4 , L_5 , & V_9 -> V_43 ) )
V_9 -> V_46 &= V_9 -> V_45 ;
if ( F_31 ( V_4 , L_6 , & V_9 -> V_63 ) )
V_9 -> V_63 &= V_9 -> V_45 ;
if ( F_31 ( V_4 , L_7 , & V_9 -> V_61 ) )
V_9 -> V_61 &= V_9 -> V_45 ;
V_60 = F_34 ( V_4 , L_8 ) ;
if ( V_60 >= 0 )
V_9 -> V_64 = V_60 ;
}
static int F_35 ( struct V_82 * V_83 ,
struct V_38 * V_39 )
{
struct V_3 * V_4 = F_36 ( V_83 ) ;
unsigned int V_13 = F_37 ( V_83 , & V_39 -> V_84 ) ;
struct V_8 * V_9 = V_4 -> V_9 ;
V_39 -> V_41 . integer . V_41 [ 0 ] = ! ! ( V_9 -> V_85 &
( V_9 -> V_86 << V_13 ) ) ;
return 0 ;
}
static int F_38 ( struct V_82 * V_83 ,
struct V_38 * V_39 )
{
struct V_3 * V_4 = F_36 ( V_83 ) ;
struct V_8 * V_9 = V_4 -> V_9 ;
unsigned int V_13 = F_37 ( V_83 , & V_39 -> V_84 ) ;
unsigned int V_87 ;
unsigned int V_60 , V_88 ;
V_88 = V_9 -> V_86 << V_13 ;
if ( V_39 -> V_41 . integer . V_41 [ 0 ] )
V_60 = V_9 -> V_85 | V_88 ;
else
V_60 = V_9 -> V_85 & ~ V_88 ;
if ( V_9 -> V_85 == V_60 )
return 0 ;
V_9 -> V_85 = V_60 ;
V_87 = F_7 ( V_4 , V_4 -> V_31 , 0 ,
V_83 -> V_89 & 0xFFFF , 0x0 ) ;
V_87 >>= V_9 -> V_90 ;
if ( V_9 -> V_85 & V_88 ) {
F_39 ( V_4 ) ;
V_87 |= V_88 ;
} else {
F_40 ( V_4 ) ;
V_87 &= ~ V_88 ;
}
F_41 ( V_4 , V_4 -> V_31 , 0 ,
V_83 -> V_89 >> 16 , V_87 ) ;
return 1 ;
}
static bool F_42 ( struct V_3 * V_4 )
{
if ( V_4 -> V_91 != 0x111d7605 &&
V_4 -> V_91 != 0x111d76d1 )
return false ;
switch ( V_4 -> V_92 ) {
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
static bool F_43 ( T_2 V_92 )
{
switch ( V_92 ) {
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
static void F_44 ( struct V_3 * V_4 )
{
struct V_8 * V_9 = V_4 -> V_9 ;
unsigned int V_93 ;
if ( V_9 -> V_53 )
return;
V_93 = F_45 ( V_4 , V_4 -> V_31 , V_94 ) ;
V_93 &= V_95 ;
if ( V_93 > 3 )
V_9 -> V_53 = 0x08 ;
else
V_9 -> V_53 = 0x01 ;
}
static int F_46 ( struct V_3 * V_4 , int V_96 )
{
struct V_8 * V_9 = V_4 -> V_9 ;
const struct V_97 * V_98 = NULL ;
if ( F_31 ( V_4 , L_9 , & V_9 -> V_53 ) ) {
F_31 ( V_4 , L_10 ,
& V_9 -> V_54 ) ;
return 1 ;
}
while ( ( V_98 = F_47 ( V_99 , NULL , V_98 ) ) ) {
if ( sscanf ( V_98 -> V_100 , L_11 ,
& V_9 -> V_54 ,
& V_9 -> V_53 ) == 2 ) {
unsigned int V_101 ;
V_101 = F_45 ( V_4 , V_4 -> V_31 ,
V_94 ) ;
V_101 &= V_95 ;
if ( V_9 -> V_53 < V_101 )
V_9 -> V_53 = 1 << V_9 -> V_53 ;
else
V_9 -> V_55 = V_9 -> V_53 ;
return 1 ;
}
if ( sscanf ( V_98 -> V_100 , L_12 ,
& V_9 -> V_54 ) == 1 ) {
F_44 ( V_4 ) ;
return 1 ;
}
if ( strstr ( V_98 -> V_100 , L_13 ) ) {
F_44 ( V_4 ) ;
if ( V_96 >= 0 )
V_9 -> V_54 = V_96 ;
else
V_9 -> V_54 = 1 ;
return 1 ;
}
}
if ( ! F_43 ( V_4 -> V_92 ) &&
( V_96 == 0 || V_96 == 1 ) ) {
F_44 ( V_4 ) ;
V_9 -> V_54 = V_96 ;
return 1 ;
}
return 0 ;
}
static bool F_48 ( struct V_3 * V_4 )
{
struct V_8 * V_9 = V_4 -> V_9 ;
T_1 * V_102 ;
int V_103 , V_12 ;
if ( V_9 -> V_15 . V_104 . V_105 == V_106 ) {
V_102 = V_9 -> V_15 . V_104 . V_107 ;
V_103 = V_9 -> V_15 . V_104 . V_108 ;
} else {
V_102 = V_9 -> V_15 . V_104 . V_109 ;
V_103 = V_9 -> V_15 . V_104 . V_110 ;
}
for ( V_12 = 0 ; V_12 < V_103 ; V_12 ++ ) {
unsigned int V_77 = F_27 ( V_4 , V_102 [ V_12 ] ) ;
if ( F_49 ( V_77 ) == V_111 )
return true ;
}
return false ;
}
static int F_50 ( struct V_3 * V_4 ,
T_1 V_18 )
{
struct V_8 * V_9 = V_4 -> V_9 ;
T_2 V_112 = F_51 ( V_4 , V_18 , V_113 ) ;
struct V_114 * V_115 ;
static struct V_114 V_116 =
F_52 ( NULL , 0 , 0 , 0 ) ;
static struct V_114 V_117 =
F_53 ( NULL , 0 , 0 , 0 ) ;
static struct V_114 V_118 =
F_54 ( NULL , 0 , 0 , 0 ) ;
if ( ( V_112 & V_119 ) >> V_120 ) {
const struct V_114 * V_121 ;
if ( V_9 -> V_122 == V_18 )
V_121 = & V_116 ;
else
V_121 = & V_117 ;
V_115 = F_55 ( & V_9 -> V_15 ,
L_14 , V_121 ) ;
if ( ! V_115 )
return - V_123 ;
V_115 -> V_89 =
F_56 ( V_18 , 1 , 0 , V_113 ) ;
}
if ( ( V_112 & V_124 ) >> V_125 ) {
V_115 = F_55 ( & V_9 -> V_15 ,
L_15 ,
& V_118 ) ;
if ( ! V_115 )
return - V_123 ;
V_115 -> V_89 =
F_56 ( V_18 , 1 , 0 , V_113 ) ;
}
return 0 ;
}
static int F_57 ( struct V_82 * V_83 ,
struct V_38 * V_39 )
{
struct V_3 * V_4 = F_36 ( V_83 ) ;
V_39 -> V_41 . integer . V_41 [ 0 ] = V_4 -> V_126 -> V_51 ;
return 0 ;
}
static int F_58 ( struct V_82 * V_83 ,
struct V_38 * V_39 )
{
struct V_3 * V_4 = F_36 ( V_83 ) ;
return F_59 ( V_4 , V_39 -> V_41 . integer . V_41 [ 0 ] ) ;
}
static int F_60 ( struct V_3 * V_4 )
{
struct V_8 * V_9 = V_4 -> V_9 ;
if ( ! F_55 ( & V_9 -> V_15 , NULL , & V_127 ) )
return - V_123 ;
return 0 ;
}
static int F_61 ( struct V_82 * V_83 ,
struct V_128 * V_129 )
{
struct V_3 * V_4 = F_36 ( V_83 ) ;
struct V_8 * V_9 = V_4 -> V_9 ;
return F_62 ( & V_9 -> V_130 , V_129 ) ;
}
static int F_63 ( struct V_82 * V_83 ,
struct V_38 * V_39 )
{
struct V_3 * V_4 = F_36 ( V_83 ) ;
struct V_8 * V_9 = V_4 -> V_9 ;
unsigned int V_131 = F_37 ( V_83 , & V_39 -> V_84 ) ;
V_39 -> V_41 . V_132 . V_133 [ 0 ] = V_9 -> V_134 [ V_131 ] ;
return 0 ;
}
static int F_64 ( struct V_82 * V_83 ,
struct V_38 * V_39 )
{
struct V_3 * V_4 = F_36 ( V_83 ) ;
struct V_8 * V_9 = V_4 -> V_9 ;
unsigned int V_131 = F_37 ( V_83 , & V_39 -> V_84 ) ;
return F_65 ( V_4 , & V_9 -> V_130 , V_39 ,
V_9 -> V_15 . V_104 . V_135 [ V_131 ] ,
& V_9 -> V_134 [ V_131 ] ) ;
}
static int F_66 ( struct V_3 * V_4 )
{
struct V_8 * V_9 = V_4 -> V_9 ;
struct V_136 * V_137 = & V_9 -> V_15 . V_104 ;
const char * const * V_138 = V_9 -> V_139 ;
struct V_114 * V_140 ;
int V_12 , V_141 ;
if ( V_137 -> V_142 < 1 )
return 0 ;
V_141 = F_67 ( V_4 , V_137 -> V_135 [ 0 ] ) ;
if ( V_141 <= 1 )
return 0 ;
if ( ! V_138 )
V_138 = V_143 ;
for ( V_12 = 0 ; V_12 < V_141 ; V_12 ++ ) {
if ( F_68 ( ! V_138 [ V_12 ] ) )
return - V_144 ;
F_69 ( & V_9 -> V_130 , V_138 [ V_12 ] , V_12 , NULL ) ;
}
V_140 = F_55 ( & V_9 -> V_15 , NULL , & V_145 ) ;
if ( ! V_140 )
return - V_123 ;
V_140 -> V_146 = V_137 -> V_142 ;
return 0 ;
}
static void F_70 ( struct V_3 * V_4 ,
const struct V_147 * V_148 , int V_7 )
{
struct V_8 * V_9 = V_4 -> V_9 ;
if ( V_7 == V_149 ) {
V_9 -> V_45 = V_9 -> V_46 = 0x09 ;
V_9 -> V_43 = 0x00 ;
V_9 -> V_15 . V_150 = 1 ;
}
}
static void F_71 ( struct V_3 * V_4 ,
const struct V_147 * V_148 , int V_7 )
{
struct V_8 * V_9 = V_4 -> V_9 ;
if ( V_7 != V_149 )
return;
F_72 ( V_4 , V_151 ) ;
V_9 -> V_45 = V_9 -> V_46 = V_9 -> V_43 = 0 ;
}
static void F_73 ( struct V_3 * V_4 )
{
struct V_8 * V_9 = V_4 -> V_9 ;
F_72 ( V_4 , V_152 ) ;
V_9 -> V_64 = 0 ;
}
static void F_74 ( struct V_3 * V_4 ,
const struct V_147 * V_148 , int V_7 )
{
struct V_8 * V_9 = V_4 -> V_9 ;
if ( V_7 != V_149 )
return;
F_73 ( V_4 ) ;
F_75 ( V_4 , V_153 ) ;
V_9 -> V_154 = 1 ;
}
static void F_76 ( struct V_3 * V_4 ,
const struct V_147 * V_148 , int V_7 )
{
if ( V_7 != V_149 )
return;
F_73 ( V_4 ) ;
F_77 ( V_4 , 0x0b , 0x90A70170 ) ;
}
static void F_78 ( struct V_3 * V_4 ,
const struct V_147 * V_148 , int V_7 )
{
if ( V_7 != V_149 )
return;
F_73 ( V_4 ) ;
F_77 ( V_4 , 0x13 , 0x90A60160 ) ;
}
static void F_79 ( struct V_3 * V_4 ,
const struct V_147 * V_148 , int V_7 )
{
if ( V_7 != V_149 )
return;
F_73 ( V_4 ) ;
F_77 ( V_4 , 0x0b , 0x90A70170 ) ;
F_77 ( V_4 , 0x13 , 0x90A60160 ) ;
}
static void F_80 ( struct V_3 * V_4 ,
const struct V_147 * V_148 , int V_7 )
{
struct V_8 * V_9 = V_4 -> V_9 ;
if ( V_7 != V_149 )
return;
F_72 ( V_4 , V_155 ) ;
V_9 -> V_64 = 0 ;
}
static void F_81 ( struct V_3 * V_4 ,
const struct V_147 * V_148 , int V_7 )
{
if ( V_7 == V_149 )
V_4 -> V_156 = 1 ;
}
static void F_82 ( struct V_3 * V_4 ,
const struct V_147 * V_148 , int V_7 )
{
struct V_8 * V_9 = V_4 -> V_9 ;
if ( V_7 != V_149 )
return;
if ( F_42 ( V_4 ) ) {
F_77 ( V_4 , 0xa , 0x2101201f ) ;
F_77 ( V_4 , 0xf , 0x2181205e ) ;
}
if ( F_46 ( V_4 , V_9 -> V_96 ) )
F_83 ( L_16 ,
V_9 -> V_53 ,
V_9 -> V_54 ) ;
}
static void F_84 ( struct V_3 * V_4 ,
const struct V_147 * V_148 , int V_7 )
{
if ( V_7 != V_149 )
return;
F_72 ( V_4 , V_157 ) ;
F_75 ( V_4 , V_158 ) ;
}
static void F_85 ( struct V_3 * V_4 ,
const struct V_147 * V_148 , int V_7 )
{
struct V_8 * V_9 = V_4 -> V_9 ;
if ( V_7 == V_149 )
V_9 -> V_96 = 0 ;
}
static void F_86 ( struct V_3 * V_4 ,
const struct V_147 * V_148 , int V_7 )
{
struct V_8 * V_9 = V_4 -> V_9 ;
if ( V_7 == V_149 )
V_9 -> V_96 = 1 ;
}
static void F_87 ( struct V_3 * V_4 ,
const struct V_147 * V_148 , int V_7 )
{
struct V_8 * V_9 = V_4 -> V_9 ;
if ( V_7 == V_149 )
V_9 -> V_44 = 0x08 ;
}
static void F_88 ( struct V_3 * V_4 ,
const struct V_147 * V_148 , int V_7 )
{
struct V_8 * V_9 = V_4 -> V_9 ;
if ( V_7 == V_149 )
V_9 -> V_159 = 1 ;
}
static int F_89 ( struct V_82 * V_83 ,
struct V_38 * V_39 )
{
struct V_3 * V_4 = F_36 ( V_83 ) ;
struct V_8 * V_9 = V_4 -> V_9 ;
V_39 -> V_41 . integer . V_41 [ 0 ] = ! ! ( V_9 -> V_43 & 0x20 ) ;
return 0 ;
}
static int F_90 ( struct V_82 * V_83 ,
struct V_38 * V_39 )
{
struct V_3 * V_4 = F_36 ( V_83 ) ;
struct V_8 * V_9 = V_4 -> V_9 ;
unsigned int V_43 ;
V_43 = ( V_9 -> V_43 & ~ 0x20 ) |
( V_39 -> V_41 . integer . V_41 [ 0 ] ? 0x20 : 0 ) ;
if ( V_43 == V_9 -> V_43 )
return 0 ;
V_9 -> V_43 = V_43 ;
F_5 ( V_4 , V_9 -> V_45 , V_9 -> V_46 , V_9 -> V_43 ) ;
return 1 ;
}
static int F_91 ( struct V_3 * V_4 )
{
struct V_8 * V_9 = V_4 -> V_9 ;
if ( ! F_55 ( & V_9 -> V_15 , L_17 ,
& V_160 ) )
return - V_123 ;
V_9 -> V_45 |= 0x20 ;
V_9 -> V_46 |= 0x20 ;
V_9 -> V_43 |= 0x20 ;
return 0 ;
}
static void F_92 ( struct V_3 * V_4 ,
const struct V_147 * V_148 , int V_7 )
{
struct V_8 * V_9 = V_4 -> V_9 ;
if ( V_7 != V_149 )
return;
F_72 ( V_4 , V_161 ) ;
V_9 -> V_45 = V_9 -> V_46 = V_9 -> V_43 = 0 ;
}
static void F_93 ( struct V_3 * V_4 ,
const struct V_147 * V_148 , int V_7 )
{
struct V_8 * V_9 = V_4 -> V_9 ;
struct V_72 * V_73 ;
if ( V_7 != V_149 )
return;
F_41 ( V_4 , V_4 -> V_31 , 0 ,
V_162 , 0x02 ) ;
F_30 ( V_4 , V_4 -> V_31 ,
V_163 ,
F_25 ) ;
V_73 = F_18 ( V_4 , V_4 -> V_31 ) ;
if ( V_73 )
V_73 -> V_59 = 0x02 ;
V_9 -> V_45 |= 0x02 ;
F_77 ( V_4 , 0x0e , 0x01813040 ) ;
}
static void F_94 ( struct V_3 * V_4 ,
const struct V_147 * V_148 , int V_7 )
{
struct V_8 * V_9 = V_4 -> V_9 ;
if ( V_7 != V_149 )
return;
V_9 -> V_53 = 0x01 ;
}
static void F_95 ( struct V_3 * V_4 ,
const struct V_147 * V_148 , int V_7 )
{
unsigned int V_164 ;
switch ( V_7 ) {
case V_149 :
F_77 ( V_4 , 0x0d , 0x90170010 ) ;
break;
case V_165 :
V_164 = F_45 ( V_4 , 0x1 , V_94 ) ;
V_164 &= V_95 ;
if ( V_164 >= 6 )
F_91 ( V_4 ) ;
break;
}
}
static void F_96 ( struct V_3 * V_4 ,
const struct V_147 * V_148 , int V_7 )
{
struct V_8 * V_9 = V_4 -> V_9 ;
if ( V_7 != V_149 )
return;
V_9 -> V_53 = 0x08 ;
}
static void F_97 ( struct V_3 * V_4 ,
const struct V_147 * V_148 , int V_7 )
{
struct V_8 * V_9 = V_4 -> V_9 ;
if ( V_7 != V_149 )
return;
if ( F_43 ( V_4 -> V_92 ) ) {
unsigned int V_166 = F_27 ( V_4 , 0x0f ) ;
if ( F_98 ( V_166 ) == V_167 ||
F_98 ( V_166 ) == V_168 ||
F_98 ( V_166 ) == V_169 ) {
V_166 = ( V_166 & ( ~ V_170 ) )
| ( V_169 <<
V_171 ) ;
V_166 = ( V_166 & ( ~ ( V_172
| V_173 ) ) )
| 0x1f ;
F_77 ( V_4 , 0x0f , V_166 ) ;
}
}
if ( F_46 ( V_4 , 1 ) )
F_83 ( L_16 ,
V_9 -> V_53 ,
V_9 -> V_54 ) ;
}
static void F_99 ( struct V_3 * V_4 ,
const struct V_147 * V_148 ,
int V_7 )
{
if ( V_7 != V_149 )
return;
F_100 ( V_4 , NULL , V_174 ,
V_175 ) ;
if ( V_4 -> V_176 != V_177 )
F_101 ( V_4 , V_7 ) ;
}
static void F_102 ( struct V_3 * V_4 ,
const struct V_147 * V_148 ,
int V_7 )
{
struct V_8 * V_9 = V_4 -> V_9 ;
if ( V_7 == V_149 ) {
V_9 -> V_45 = V_9 -> V_46 = 0x03 ;
V_9 -> V_43 = 0x03 ;
}
}
static void F_103 ( struct V_3 * V_4 ,
const struct V_147 * V_148 , int V_7 )
{
if ( V_7 == V_149 )
V_4 -> V_156 = 1 ;
}
static void F_104 ( struct V_3 * V_4 ,
const struct V_147 * V_148 , int V_7 )
{
struct V_8 * V_9 = V_4 -> V_9 ;
if ( V_7 == V_149 ) {
F_72 ( V_4 , V_178 ) ;
V_9 -> V_63 = V_9 -> V_45 = 0 ;
V_9 -> V_46 = V_9 -> V_43 = 0 ;
}
}
static void F_105 ( struct V_3 * V_4 ,
const struct V_147 * V_148 , int V_7 )
{
struct V_8 * V_9 = V_4 -> V_9 ;
if ( V_7 != V_149 )
return;
if ( V_4 -> V_92 != 0x1028022f ) {
V_9 -> V_63 = V_9 -> V_45 = 0x04 ;
V_9 -> V_46 = V_9 -> V_43 = 0x04 ;
}
F_75 ( V_4 , V_179 ) ;
V_9 -> V_154 = 1 ;
}
static void F_106 ( struct V_3 * V_4 ,
const struct V_147 * V_148 , int V_7 )
{
struct V_8 * V_9 = V_4 -> V_9 ;
if ( V_7 == V_149 ) {
F_75 ( V_4 , V_180 ) ;
V_9 -> V_154 = 1 ;
}
}
static void F_107 ( struct V_3 * V_4 ,
const struct V_147 * V_148 , int V_7 )
{
struct V_8 * V_9 = V_4 -> V_9 ;
if ( V_7 == V_149 ) {
F_72 ( V_4 , V_181 ) ;
V_9 -> V_63 = V_9 -> V_45 = V_9 -> V_46 = 0 ;
}
}
static void F_108 ( struct V_3 * V_4 ,
const struct V_147 * V_148 , int V_7 )
{
struct V_8 * V_9 = V_4 -> V_9 ;
struct V_72 * V_73 ;
if ( V_7 == V_149 ) {
F_72 ( V_4 , V_182 ) ;
F_41 ( V_4 , V_4 -> V_31 , 0 ,
V_162 , 0x10 ) ;
F_30 ( V_4 , V_4 -> V_31 ,
V_163 ,
F_25 ) ;
V_73 = F_18 ( V_4 , V_4 -> V_31 ) ;
if ( V_73 )
V_73 -> V_59 = 0x01 ;
V_9 -> V_46 = 0x0b ;
V_9 -> V_63 = 0x01 ;
V_9 -> V_45 = 0x1b ;
V_9 -> V_61 = 0x10 ;
V_9 -> V_43 = 0x01 ;
}
}
static void F_109 ( struct V_3 * V_4 ,
const struct V_147 * V_148 , int V_7 )
{
struct V_8 * V_9 = V_4 -> V_9 ;
if ( V_7 == V_149 )
V_9 -> V_64 = 0 ;
}
static int F_110 ( struct V_3 * V_4 )
{
struct V_8 * V_9 = V_4 -> V_9 ;
int V_183 ;
int V_184 = 0 ;
if ( V_9 -> V_159 )
V_184 |= V_185 ;
V_183 = F_111 ( V_4 , & V_9 -> V_15 . V_104 , NULL , V_184 ) ;
if ( V_183 < 0 )
return V_183 ;
V_9 -> V_15 . V_186 = F_1 ;
V_9 -> V_15 . V_187 = F_3 ;
V_9 -> V_15 . V_188 = F_13 ;
V_9 -> V_15 . V_189 = F_19 ;
V_9 -> V_15 . V_190 = F_21 ;
V_9 -> V_15 . V_191 = F_23 ;
V_183 = F_112 ( V_4 , & V_9 -> V_15 . V_104 ) ;
if ( V_183 < 0 )
return V_183 ;
V_9 -> V_15 . V_192 [ 3 ] |= V_193 ;
if ( V_9 -> V_122 > 0 ) {
V_183 = F_50 ( V_4 ,
V_9 -> V_122 ) ;
if ( V_183 < 0 )
return V_183 ;
}
#ifdef F_113
if ( V_9 -> V_15 . V_194 ) {
T_1 V_18 = V_9 -> V_15 . V_194 ;
unsigned int V_112 ;
V_183 = F_50 ( V_4 , V_18 ) ;
if ( V_183 < 0 )
return V_183 ;
if ( V_4 -> V_126 ) {
V_4 -> V_126 -> V_195 = V_9 -> V_196 ;
V_112 = F_51 ( V_4 , V_18 , V_113 ) ;
if ( ! ( V_112 & V_119 ) ) {
V_183 = F_60 ( V_4 ) ;
if ( V_183 < 0 )
return V_183 ;
}
}
}
#endif
if ( V_9 -> V_53 )
V_9 -> V_15 . V_197 . V_198 = F_12 ;
if ( V_9 -> V_199 &&
F_34 ( V_4 , L_18 ) == 1 ) {
if ( ! F_55 ( & V_9 -> V_15 , NULL , V_9 -> V_199 ) )
return - V_123 ;
}
if ( V_9 -> V_200 ) {
V_183 = F_66 ( V_4 ) ;
if ( V_183 < 0 )
return V_183 ;
}
F_26 ( V_4 ) ;
return 0 ;
}
static int F_114 ( struct V_3 * V_4 )
{
struct V_8 * V_9 = V_4 -> V_9 ;
unsigned int V_93 ;
int V_12 ;
F_33 ( V_4 ) ;
V_93 = V_9 -> V_43 ;
if ( ! V_9 -> V_64 )
V_93 |= V_9 -> V_63 ;
F_5 ( V_4 , V_9 -> V_45 , V_9 -> V_46 , V_93 ) ;
F_115 ( V_4 ) ;
if ( V_9 -> V_68 )
F_4 ( V_4 , V_4 -> V_31 , 0 ,
V_71 ,
V_9 -> V_70 ) ;
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
static void F_116 ( struct V_3 * V_4 )
{
struct V_8 * V_9 = V_4 -> V_9 ;
F_117 ( V_4 ) ;
if ( V_9 -> V_63 )
F_5 ( V_4 , V_9 -> V_45 ,
V_9 -> V_46 , V_9 -> V_43 &
~ V_9 -> V_63 ) ;
}
static void F_118 ( struct V_201 * V_202 ,
struct V_3 * V_4 , T_1 V_18 )
{
if ( V_18 == V_4 -> V_31 )
F_119 ( V_202 , L_19 ,
F_7 ( V_4 , V_18 , 0 ,
V_203 , 0 ) ) ;
}
static void F_120 ( struct V_201 * V_202 ,
struct V_3 * V_4 ,
unsigned int V_204 )
{
F_119 ( V_202 , L_20 ,
F_7 ( V_4 , V_4 -> V_31 , 0 , V_204 , 0 ) ) ;
}
static void F_121 ( struct V_201 * V_202 ,
struct V_3 * V_4 , T_1 V_18 )
{
F_118 ( V_202 , V_4 , V_18 ) ;
if ( V_18 == V_4 -> V_31 )
F_120 ( V_202 , V_4 , 0xfa0 ) ;
}
static void F_122 ( struct V_201 * V_202 ,
struct V_3 * V_4 , T_1 V_18 )
{
if ( V_18 == V_4 -> V_31 )
F_120 ( V_202 , V_4 , 0xfe0 ) ;
}
static void F_123 ( struct V_201 * V_202 ,
struct V_3 * V_4 , T_1 V_18 )
{
if ( V_18 == V_4 -> V_31 )
F_120 ( V_202 , V_4 , 0xfeb ) ;
}
static int F_124 ( struct V_3 * V_4 )
{
V_4 -> V_205 . V_206 ( V_4 ) ;
F_125 ( V_4 ) ;
F_126 ( V_4 ) ;
return 0 ;
}
static int F_127 ( struct V_3 * V_4 )
{
F_116 ( V_4 ) ;
return 0 ;
}
static void F_128 ( struct V_3 * V_4 , T_1 V_207 ,
unsigned int V_208 )
{
unsigned int V_209 = V_208 ;
struct V_8 * V_9 = V_4 -> V_9 ;
if ( V_208 == V_23 ) {
if ( V_9 -> V_55 ) {
V_209 = V_210 ;
}
F_2 ( 100 ) ;
}
F_7 ( V_4 , V_207 , 0 , V_19 ,
V_209 ) ;
F_129 ( V_4 , V_207 , V_208 ) ;
}
static int F_130 ( struct V_3 * V_4 )
{
struct V_8 * V_9 ;
V_9 = F_131 ( sizeof( * V_9 ) , V_211 ) ;
if ( ! V_9 )
return - V_123 ;
F_132 ( & V_9 -> V_15 ) ;
V_4 -> V_9 = V_9 ;
V_4 -> V_212 = 1 ;
return 0 ;
}
static int F_133 ( struct V_3 * V_4 )
{
struct V_8 * V_9 ;
int V_183 ;
V_183 = F_130 ( V_4 ) ;
if ( V_183 < 0 )
return V_183 ;
V_9 = V_4 -> V_9 ;
V_9 -> V_196 = 1 ;
V_9 -> V_15 . V_213 = 1 ;
V_4 -> V_205 = V_214 ;
V_4 -> V_215 = V_216 ;
F_75 ( V_4 , V_217 ) ;
F_100 ( V_4 , V_218 , V_219 ,
V_220 ) ;
F_101 ( V_4 , V_149 ) ;
V_183 = F_110 ( V_4 ) ;
if ( V_183 < 0 ) {
F_134 ( V_4 ) ;
return V_183 ;
}
F_101 ( V_4 , V_165 ) ;
return 0 ;
}
static int F_135 ( struct V_3 * V_4 )
{
struct V_8 * V_9 ;
int V_183 ;
V_183 = F_130 ( V_4 ) ;
if ( V_183 < 0 )
return V_183 ;
V_9 = V_4 -> V_9 ;
V_9 -> V_196 = 1 ;
V_9 -> V_15 . V_213 = 1 ;
V_4 -> V_205 = V_214 ;
F_75 ( V_4 , V_221 ) ;
F_100 ( V_4 , V_222 , V_223 ,
V_224 ) ;
F_101 ( V_4 , V_149 ) ;
V_183 = F_110 ( V_4 ) ;
if ( V_183 < 0 ) {
F_134 ( V_4 ) ;
return V_183 ;
}
F_101 ( V_4 , V_165 ) ;
return 0 ;
}
static int F_136 ( struct V_3 * V_4 )
{
struct V_8 * V_9 ;
int V_183 ;
int V_225 ;
V_183 = F_130 ( V_4 ) ;
if ( V_183 < 0 )
return V_183 ;
V_9 = V_4 -> V_9 ;
V_9 -> V_196 = 0 ;
V_9 -> V_15 . V_226 = 0x1d ;
V_9 -> V_200 = 1 ;
V_225 = F_67 ( V_4 , 0x0a ) - 1 ;
if ( V_225 < 3 || V_225 > 5 ) {
F_137 ( V_227 L_21
L_22 ) ;
V_225 = 5 ;
}
switch ( V_225 ) {
case 0x3 :
V_9 -> V_199 = & V_228 ;
break;
case 0x4 :
V_9 -> V_199 = & V_229 ;
break;
case 0x5 :
V_9 -> V_199 = & V_230 ;
break;
}
V_9 -> V_86 = 0x01 ;
V_9 -> V_90 = 8 ;
V_9 -> V_15 . V_194 = 0x1c ;
V_9 -> V_63 = V_9 -> V_45 = V_9 -> V_46 = 0x1 ;
V_9 -> V_43 = 0x01 ;
V_9 -> V_64 = 1 ;
V_9 -> V_68 = F_138 ( V_231 ) ;
V_9 -> V_69 = V_231 ;
V_9 -> V_15 . V_213 = 1 ;
V_9 -> V_15 . V_232 = 1 ;
V_4 -> V_205 = V_214 ;
F_100 ( V_4 , V_233 , V_234 ,
V_235 ) ;
F_101 ( V_4 , V_149 ) ;
if ( ! V_9 -> V_154 )
F_75 ( V_4 , V_236 ) ;
V_183 = F_110 ( V_4 ) ;
if ( V_183 < 0 ) {
F_134 ( V_4 ) ;
return V_183 ;
}
if ( V_9 -> V_64 && ! F_48 ( V_4 ) )
V_9 -> V_64 = 0 ;
V_4 -> V_237 = F_121 ;
F_101 ( V_4 , V_165 ) ;
return 0 ;
}
static void F_139 ( struct V_3 * V_4 )
{
struct V_8 * V_9 = V_4 -> V_9 ;
if ( V_9 -> V_53 ) {
if ( ! V_9 -> V_55 ) {
V_9 -> V_45 |= V_9 -> V_53 ;
V_9 -> V_46 |= V_9 -> V_53 ;
V_9 -> V_43 |= V_9 -> V_53 ;
} else {
V_4 -> V_205 . V_238 =
F_128 ;
}
}
if ( V_9 -> V_44 ) {
V_9 -> V_45 |= V_9 -> V_44 ;
V_9 -> V_46 |= V_9 -> V_44 ;
V_9 -> V_42 = true ;
V_9 -> V_43 |= V_9 -> V_44 ;
V_9 -> V_15 . V_239 = F_8 ;
}
}
static int F_140 ( struct V_3 * V_4 )
{
struct V_8 * V_9 ;
int V_183 ;
V_183 = F_130 ( V_4 ) ;
if ( V_183 < 0 )
return V_183 ;
V_4 -> V_240 = 0 ;
V_9 = V_4 -> V_9 ;
V_9 -> V_196 = 0 ;
V_9 -> V_15 . V_213 = 1 ;
V_9 -> V_15 . V_232 = 1 ;
V_9 -> V_15 . V_226 = 0x1b ;
V_9 -> V_15 . V_194 = 0x21 ;
V_9 -> V_69 = V_241 ;
V_9 -> V_68 = F_138 ( V_241 ) ;
V_9 -> V_96 = - 1 ;
V_4 -> V_205 = V_214 ;
F_75 ( V_4 , V_242 ) ;
F_100 ( V_4 , V_243 , V_244 ,
V_245 ) ;
F_101 ( V_4 , V_149 ) ;
F_139 ( V_4 ) ;
V_183 = F_110 ( V_4 ) ;
if ( V_183 < 0 ) {
F_134 ( V_4 ) ;
return V_183 ;
}
V_4 -> V_237 = F_118 ;
F_101 ( V_4 , V_165 ) ;
return 0 ;
}
static int F_141 ( struct V_3 * V_4 )
{
struct V_8 * V_9 ;
int V_183 ;
V_183 = F_130 ( V_4 ) ;
if ( V_183 < 0 )
return V_183 ;
V_4 -> V_240 = 0 ;
V_9 = V_4 -> V_9 ;
V_9 -> V_196 = 0 ;
V_9 -> V_15 . V_213 = 1 ;
V_9 -> V_15 . V_232 = 1 ;
V_9 -> V_15 . V_194 = 0x19 ;
V_9 -> V_69 = V_246 ;
V_9 -> V_68 = F_138 ( V_246 ) ;
V_9 -> V_96 = - 1 ;
V_4 -> V_205 = V_214 ;
V_183 = F_110 ( V_4 ) ;
if ( V_183 < 0 ) {
F_134 ( V_4 ) ;
return V_183 ;
}
V_4 -> V_237 = F_118 ;
return 0 ;
}
static int F_142 ( struct V_3 * V_4 )
{
struct V_8 * V_9 ;
const struct V_247 * V_248 = V_249 ;
int V_183 ;
V_183 = F_130 ( V_4 ) ;
if ( V_183 < 0 )
return V_183 ;
V_9 = V_4 -> V_9 ;
V_9 -> V_196 = 0 ;
V_9 -> V_15 . V_213 = 1 ;
V_9 -> V_15 . V_232 = 1 ;
V_9 -> V_15 . V_226 = 0x17 ;
V_9 -> V_200 = 1 ;
V_4 -> V_205 = V_214 ;
V_9 -> V_45 = 0x01 ;
V_9 -> V_46 = 0x01 ;
V_9 -> V_43 = 0x01 ;
switch ( V_4 -> V_91 ) {
case 0x111d76b6 :
case 0x111d76b7 :
V_248 ++ ;
break;
case 0x111d7608 :
if ( ( V_4 -> V_250 & 0xf ) == 0 ||
( V_4 -> V_250 & 0xf ) == 1 )
V_9 -> V_11 = 40 ;
V_248 ++ ;
F_77 ( V_4 , 0x0f , 0x40f000f0 ) ;
F_77 ( V_4 , 0x19 , 0x40f000f3 ) ;
break;
case 0x111d7603 :
if ( ( V_4 -> V_250 & 0xf ) == 1 )
V_9 -> V_11 = 40 ;
break;
}
if ( F_143 ( F_144 ( V_4 , 0x28 ) ) == V_251 )
F_75 ( V_4 , V_252 ) ;
if ( F_144 ( V_4 , 0xa ) & V_253 )
F_145 ( V_4 , V_248 ) ;
V_9 -> V_199 = & V_254 ;
V_9 -> V_86 = 0x50 ;
V_9 -> V_90 = 0 ;
V_9 -> V_14 = 1 ;
V_9 -> V_15 . V_194 = 0x26 ;
V_9 -> V_68 = F_138 ( V_255 ) ;
V_9 -> V_69 = V_255 ;
F_100 ( V_4 , V_256 , V_257 ,
V_258 ) ;
F_101 ( V_4 , V_149 ) ;
F_139 ( V_4 ) ;
V_183 = F_110 ( V_4 ) ;
if ( V_183 < 0 ) {
F_134 ( V_4 ) ;
return V_183 ;
}
V_4 -> V_237 = F_121 ;
F_101 ( V_4 , V_165 ) ;
return 0 ;
}
static int F_146 ( struct V_3 * V_4 )
{
struct V_8 * V_9 ;
int V_183 ;
V_183 = F_130 ( V_4 ) ;
if ( V_183 < 0 )
return V_183 ;
V_9 = V_4 -> V_9 ;
V_9 -> V_196 = 1 ;
V_9 -> V_15 . V_213 = 1 ;
V_4 -> V_205 = V_214 ;
F_75 ( V_4 , V_259 ) ;
F_147 ( V_4 , 0x12 , V_113 ,
( 0 << V_260 ) |
( 2 << V_125 ) |
( 0x27 << V_261 ) |
( 0 << V_120 ) ) ;
F_100 ( V_4 , V_262 , V_263 ,
V_175 ) ;
F_101 ( V_4 , V_149 ) ;
V_183 = F_110 ( V_4 ) ;
if ( V_183 < 0 ) {
F_134 ( V_4 ) ;
return V_183 ;
}
F_101 ( V_4 , V_165 ) ;
return 0 ;
}
static int F_148 ( struct V_3 * V_4 )
{
struct V_8 * V_9 ;
int V_183 ;
V_183 = F_130 ( V_4 ) ;
if ( V_183 < 0 )
return V_183 ;
V_9 = V_4 -> V_9 ;
V_9 -> V_196 = 1 ;
V_9 -> V_15 . V_213 = 1 ;
V_9 -> V_200 = 1 ;
V_9 -> V_139 = V_264 ;
V_9 -> V_15 . V_194 = 0x23 ;
V_9 -> V_63 = V_9 -> V_45 = 0x01 ;
V_9 -> V_46 = V_9 -> V_43 = 0x01 ;
V_9 -> V_199 = & V_265 ;
V_9 -> V_86 = 0x40 ;
V_9 -> V_90 = 0 ;
V_9 -> V_64 = 1 ;
V_4 -> V_205 = V_214 ;
F_100 ( V_4 , V_266 , V_267 ,
V_268 ) ;
F_101 ( V_4 , V_149 ) ;
if ( ! V_9 -> V_154 )
F_75 ( V_4 , V_269 ) ;
V_183 = F_110 ( V_4 ) ;
if ( V_183 < 0 ) {
F_134 ( V_4 ) ;
return V_183 ;
}
V_4 -> V_237 = F_123 ;
V_4 -> V_270 -> V_271 = 1 ;
F_101 ( V_4 , V_165 ) ;
return 0 ;
}
static int F_149 ( struct V_3 * V_4 )
{
struct V_8 * V_9 ;
int V_183 ;
V_183 = F_130 ( V_4 ) ;
if ( V_183 < 0 )
return V_183 ;
V_9 = V_4 -> V_9 ;
V_9 -> V_196 = 1 ;
V_9 -> V_15 . V_213 = 1 ;
V_9 -> V_200 = 1 ;
V_9 -> V_15 . V_194 = 0x23 ;
F_75 ( V_4 , V_272 ) ;
V_9 -> V_199 = & V_273 ;
V_9 -> V_86 = 0x40 ;
V_9 -> V_90 = 0 ;
V_9 -> V_63 = V_9 -> V_45 = V_9 -> V_46 = 0x1 ;
V_9 -> V_43 = 0x01 ;
V_9 -> V_64 = 1 ;
V_4 -> V_205 = V_214 ;
F_100 ( V_4 , V_274 , V_275 ,
V_276 ) ;
F_101 ( V_4 , V_149 ) ;
V_183 = F_110 ( V_4 ) ;
if ( V_183 < 0 ) {
F_134 ( V_4 ) ;
return V_183 ;
}
V_4 -> V_237 = F_122 ;
F_101 ( V_4 , V_165 ) ;
return 0 ;
}
static int F_150 ( struct V_3 * V_4 )
{
struct V_8 * V_9 ;
int V_183 ;
V_183 = F_130 ( V_4 ) ;
if ( V_183 < 0 )
return V_183 ;
V_9 = V_4 -> V_9 ;
V_9 -> V_196 = 1 ;
V_9 -> V_15 . V_213 = 1 ;
V_4 -> V_205 = V_214 ;
F_75 ( V_4 , V_277 ) ;
F_100 ( V_4 , V_278 , V_279 ,
V_280 ) ;
F_101 ( V_4 , V_149 ) ;
V_183 = F_110 ( V_4 ) ;
if ( V_183 < 0 ) {
F_134 ( V_4 ) ;
return - V_144 ;
}
F_101 ( V_4 , V_165 ) ;
return 0 ;
}
static int T_3 F_151 ( void )
{
return F_152 ( & V_281 ) ;
}
static void T_4 F_153 ( void )
{
F_154 ( & V_281 ) ;
}
