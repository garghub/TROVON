static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
void T_1 * V_5 = V_4 -> V_6 -> V_7 [ V_8 ] ;
void T_1 * V_9 = V_5 + V_10 [ V_4 -> V_11 ] . V_9 ;
F_2 ( 0 , V_9 ) ;
F_3 ( V_4 ) ;
}
static void F_4 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
void T_1 * V_12 = V_4 -> V_13 . V_14 ;
F_5 ( V_4 -> V_15 , V_12 + V_16 ) ;
V_4 -> V_17 -> V_18 ( V_4 , & V_2 -> V_19 ) ;
}
static void F_6 ( struct V_1 * V_2 )
{
unsigned int V_20 = ( V_2 -> V_19 . V_21 & V_22 ) ;
struct V_3 * V_4 = V_2 -> V_4 ;
void T_1 * V_5 = V_4 -> V_6 -> V_7 [ V_8 ] ;
void T_1 * V_9 = V_5 + V_10 [ V_4 -> V_11 ] . V_9 ;
T_2 V_23 = V_24 ;
if ( ! V_20 )
V_23 |= V_25 ;
F_2 ( V_23 , V_9 ) ;
}
static void F_7 ( struct V_1 * V_2 )
{
struct V_26 * V_27 ;
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_28 * V_29 , * V_30 = NULL ;
unsigned int V_31 ;
V_29 = & V_4 -> V_32 [ 0 ] ;
F_8 (qc->sg, sg, qc->n_elem, si) {
T_3 V_33 = ( T_3 ) F_9 ( V_27 ) ;
T_3 V_34 = F_10 ( V_27 ) ;
V_29 -> V_33 = F_11 ( V_33 ) ;
V_29 -> V_35 = F_11 ( V_34 ) ;
F_12 ( L_1 , V_31 , V_33 , V_34 ) ;
V_30 = V_29 ;
V_29 ++ ;
}
if ( F_13 ( V_30 ) )
V_30 -> V_35 |= F_11 ( V_36 ) ;
}
static void F_14 ( struct V_1 * V_2 )
{
if ( ! ( V_2 -> V_21 & V_37 ) )
return;
F_7 ( V_2 ) ;
}
static unsigned char F_15 ( struct V_38 * V_39 )
{
T_2 V_40 = 0 ;
F_16 ( V_39 , V_41 , & V_40 ) ;
return V_40 ;
}
static int F_17 ( struct V_42 * V_43 , struct V_44 * * V_45 )
{
struct V_3 * V_4 = V_43 -> V_4 ;
void T_1 * V_5 = V_4 -> V_6 -> V_7 [ V_8 ] ;
void T_1 * V_33 = V_5 + V_10 [ V_4 -> V_11 ] . V_46 ;
struct V_44 * V_47 ;
T_3 V_48 , V_49 [ 2 ] = { } ;
int V_50 ;
V_50 = F_18 ( V_43 , V_45 ) ;
if ( V_50 )
return V_50 ;
F_19 (dev, link, ALL) {
if ( ! F_20 ( V_47 ) )
V_49 [ V_47 -> V_51 ] = 0 ;
else if ( V_47 -> V_21 & V_52 )
V_49 [ V_47 -> V_51 ] = 1 ;
else
V_49 [ V_47 -> V_51 ] = 3 ;
}
V_48 = F_21 ( V_33 ) ;
V_48 &= ~ ( ( 1 << 5 ) | ( 1 << 4 ) | ( 1 << 1 ) | ( 1 << 0 ) ) ;
V_48 |= V_49 [ 0 ] ;
V_48 |= ( V_49 [ 1 ] << 4 ) ;
F_22 ( V_48 , V_33 ) ;
F_21 ( V_33 ) ;
return 0 ;
}
static inline void T_1 * F_23 ( struct V_3 * V_4 ,
unsigned int V_53 )
{
void T_1 * V_54 = V_4 -> V_13 . V_55 ;
switch ( V_53 ) {
case V_56 :
return V_54 + 4 ;
case V_57 :
return V_54 + 8 ;
case V_58 :
return V_54 ;
default:
break;
}
return NULL ;
}
static int F_24 ( struct V_42 * V_43 , unsigned int V_53 , T_3 * V_59 )
{
void T_1 * V_60 = F_23 ( V_43 -> V_4 , V_53 ) ;
if ( V_60 ) {
* V_59 = F_21 ( V_60 ) ;
return 0 ;
}
return - V_61 ;
}
static int F_25 ( struct V_42 * V_43 , unsigned int V_53 , T_3 V_59 )
{
void T_1 * V_60 = F_23 ( V_43 -> V_4 , V_53 ) ;
if ( V_60 ) {
F_22 ( V_59 , V_60 ) ;
return 0 ;
}
return - V_61 ;
}
static void F_26 ( struct V_3 * V_4 , T_3 V_9 )
{
struct V_62 * V_63 = & V_4 -> V_43 . V_64 ;
struct V_1 * V_2 = F_27 ( V_4 , V_4 -> V_43 . V_65 ) ;
T_2 V_66 ;
if ( F_28 ( V_9 & V_67 ) ) {
T_3 V_68 = 0xffffffff ;
F_24 ( & V_4 -> V_43 , V_57 , & V_68 ) ;
F_25 ( & V_4 -> V_43 , V_57 , V_68 ) ;
if ( V_68 & V_69 ) {
V_4 -> V_43 . V_64 . V_68 |= V_68 ;
goto V_70;
}
if ( ! ( V_9 & V_71 ) )
return;
}
if ( F_28 ( ! V_2 || ( V_2 -> V_19 . V_21 & V_72 ) ) ) {
V_4 -> V_17 -> V_73 ( V_4 ) ;
return;
}
switch ( V_4 -> V_74 ) {
case V_75 :
if ( ! ( V_2 -> V_47 -> V_21 & V_76 ) )
goto V_77;
break;
case V_78 :
if ( F_29 ( V_2 -> V_19 . V_79 ) ) {
V_4 -> V_17 -> V_80 ( V_2 ) ;
if ( V_9 & V_81 ) {
V_2 -> V_82 |= V_83 ;
V_4 -> V_74 = V_84 ;
}
}
break;
case V_85 :
break;
default:
goto V_77;
}
V_66 = V_4 -> V_17 -> V_73 ( V_4 ) ;
if ( F_28 ( V_66 & V_86 ) )
goto V_77;
F_30 ( V_4 ) ;
F_31 ( V_4 , V_2 , V_66 , 0 ) ;
if ( F_28 ( V_2 -> V_82 ) && F_29 ( V_2 -> V_19 . V_79 ) )
F_32 ( V_63 , L_2 , V_9 ) ;
return;
V_77:
V_2 -> V_82 |= V_87 ;
V_70:
F_33 ( V_4 ) ;
}
static T_4 F_34 ( int V_88 , void * V_89 )
{
struct V_90 * V_6 = V_89 ;
void T_1 * V_5 = V_6 -> V_7 [ V_8 ] ;
int V_91 = 0 ;
int V_92 ;
F_35 ( & V_6 -> V_93 ) ;
for ( V_92 = 0 ; V_92 < V_6 -> V_94 ; V_92 ++ ) {
struct V_3 * V_4 = V_6 -> V_95 [ V_92 ] ;
T_3 V_9 = F_21 ( V_5 + V_10 [ V_4 -> V_11 ] . V_9 ) ;
if ( V_4 -> V_21 & V_96 )
V_9 &= ~ V_67 ;
if ( V_9 == 0xffffffff ||
! ( V_9 & ( V_71 | V_67 ) ) )
continue;
F_26 ( V_4 , V_9 ) ;
V_91 = 1 ;
}
F_36 ( & V_6 -> V_93 ) ;
return F_37 ( V_91 ) ;
}
static void F_38 ( struct V_3 * V_4 )
{
void T_1 * V_5 = V_4 -> V_6 -> V_7 [ V_8 ] ;
T_3 V_48 ;
F_22 ( 0 , V_5 + V_10 [ V_4 -> V_11 ] . V_97 ) ;
V_48 = F_21 ( V_5 + V_98 ) ;
V_48 |= V_99 << V_4 -> V_11 ;
F_22 ( V_48 , V_5 + V_98 ) ;
F_21 ( V_5 + V_98 ) ;
F_2 ( F_39 ( V_4 -> V_13 . V_14 ) & ~ V_100 ,
V_4 -> V_13 . V_14 ) ;
F_39 ( V_4 -> V_13 . V_14 ) ;
}
static void F_40 ( struct V_3 * V_4 )
{
void T_1 * V_5 = V_4 -> V_6 -> V_7 [ V_8 ] ;
T_3 V_48 ;
V_4 -> V_17 -> V_73 ( V_4 ) ;
F_30 ( V_4 ) ;
if ( ! ( V_4 -> V_21 & V_96 ) )
F_22 ( V_101 , V_5 + V_10 [ V_4 -> V_11 ] . V_97 ) ;
V_48 = F_21 ( V_5 + V_98 ) ;
V_48 &= ~ ( V_99 << V_4 -> V_11 ) ;
F_22 ( V_48 , V_5 + V_98 ) ;
}
static void F_41 ( struct V_44 * V_47 )
{
struct V_3 * V_4 = V_47 -> V_43 -> V_4 ;
int V_102 = V_4 -> V_43 . V_103 . V_92 . V_21 & V_104 ;
unsigned int V_105 , V_106 = 0 ;
unsigned char V_107 [ V_108 + 1 ] ;
F_42 ( V_47 -> V_109 , V_107 , V_110 , sizeof( V_107 ) ) ;
for ( V_105 = 0 ; V_111 [ V_105 ] . V_112 ; V_105 ++ )
if ( ! strcmp ( V_111 [ V_105 ] . V_112 , V_107 ) ) {
V_106 = V_111 [ V_105 ] . V_113 ;
break;
}
if ( V_114 ||
( ( V_4 -> V_21 & V_115 ) &&
( V_106 & V_116 ) ) ) {
if ( V_102 )
F_43 ( V_47 ,
L_3 ) ;
V_47 -> V_117 = 15 ;
return;
}
if ( V_106 & V_118 ) {
if ( V_102 )
F_43 ( V_47 , L_4 ,
V_107 ) ;
V_47 -> V_119 &= V_120 ;
return;
}
}
static void F_44 ( struct V_90 * V_6 )
{
struct V_38 * V_39 = F_45 ( V_6 -> V_47 ) ;
void T_1 * V_5 = V_6 -> V_7 [ V_8 ] ;
T_2 V_121 ;
T_3 V_48 ;
int V_92 ;
V_121 = F_15 ( V_39 ) ;
if ( V_121 ) {
V_121 >>= 3 ;
V_121 ++ ;
for ( V_92 = 0 ; V_92 < V_6 -> V_94 ; V_92 ++ )
F_46 ( V_121 << 8 | V_121 ,
V_5 + V_10 [ V_92 ] . V_122 ) ;
} else
F_47 ( & V_39 -> V_47 ,
L_5 ) ;
if ( V_6 -> V_95 [ 0 ] -> V_21 & V_123 ) {
int V_124 ;
for ( V_92 = 0 , V_124 = 0 ; V_92 < V_6 -> V_94 ; V_92 ++ ) {
V_48 = F_21 ( V_5 + V_10 [ V_92 ] . V_125 ) ;
if ( ( V_48 & 0x3 ) != 0x01 )
continue;
if ( ! V_124 )
F_48 ( & V_39 -> V_47 ,
L_6 ) ;
F_22 ( V_48 & ~ 0x3 , V_5 + V_10 [ V_92 ] . V_125 ) ;
V_124 ++ ;
}
}
if ( V_6 -> V_94 == 4 ) {
V_48 = F_21 ( V_5 + V_10 [ 2 ] . V_12 ) ;
if ( ( V_48 & V_126 ) == 0 )
F_22 ( V_48 | V_126 ,
V_5 + V_10 [ 2 ] . V_12 ) ;
}
}
static bool F_49 ( struct V_38 * V_39 )
{
static const struct V_127 V_128 [] = {
{
. V_129 = L_7 ,
. V_130 = {
F_50 ( V_131 , L_8 ) ,
F_50 ( V_132 , L_7 ) ,
} ,
. V_133 = ( void * ) 0x12UL ,
} ,
{ }
} ;
const struct V_127 * V_134 = F_51 ( V_128 ) ;
if ( V_134 ) {
unsigned long V_135 = ( unsigned long ) V_134 -> V_133 ;
return V_135 == F_52 ( V_39 -> V_136 ) ;
}
return false ;
}
static int F_53 ( struct V_38 * V_39 , const struct V_137 * V_138 )
{
int V_139 = V_138 -> V_133 ;
struct V_140 V_141 = V_142 [ V_139 ] ;
const struct V_140 * V_143 [] = { & V_141 , NULL } ;
struct V_90 * V_6 ;
void T_1 * V_5 ;
int V_94 , V_50 ;
unsigned int V_92 ;
F_54 ( & V_39 -> V_47 , V_144 ) ;
V_94 = 2 ;
if ( V_139 == V_145 )
V_94 = 4 ;
if ( F_49 ( V_39 ) ) {
V_141 . V_21 |= V_146 |
V_147 ;
F_48 ( & V_39 -> V_47 , L_9
L_10 ) ;
}
V_6 = F_55 ( & V_39 -> V_47 , V_143 , V_94 ) ;
if ( ! V_6 )
return - V_148 ;
V_50 = F_56 ( V_39 ) ;
if ( V_50 )
return V_50 ;
V_50 = F_57 ( V_39 , 1 << V_8 , V_149 ) ;
if ( V_50 == - V_150 )
F_58 ( V_39 ) ;
if ( V_50 )
return V_50 ;
V_6 -> V_7 = F_59 ( V_39 ) ;
V_50 = F_60 ( V_39 , V_151 ) ;
if ( V_50 )
return V_50 ;
V_50 = F_61 ( V_39 , V_151 ) ;
if ( V_50 )
return V_50 ;
V_5 = V_6 -> V_7 [ V_8 ] ;
for ( V_92 = 0 ; V_92 < V_6 -> V_94 ; V_92 ++ ) {
struct V_3 * V_4 = V_6 -> V_95 [ V_92 ] ;
struct V_152 * V_13 = & V_4 -> V_13 ;
V_13 -> V_153 = V_5 + V_10 [ V_92 ] . V_19 ;
V_13 -> V_154 =
V_13 -> V_155 = V_5 + V_10 [ V_92 ] . V_156 ;
V_13 -> V_14 = V_5 + V_10 [ V_92 ] . V_12 ;
V_13 -> V_55 = V_5 + V_10 [ V_92 ] . V_157 ;
F_62 ( V_13 ) ;
F_63 ( V_4 , V_8 , - 1 , L_11 ) ;
F_63 ( V_4 , V_8 , V_10 [ V_92 ] . V_19 , L_12 ) ;
}
F_44 ( V_6 ) ;
F_64 ( V_39 ) ;
return F_65 ( V_6 , V_39 -> V_88 , F_34 , V_158 ,
& V_159 ) ;
}
static int F_66 ( struct V_38 * V_39 )
{
struct V_90 * V_6 = F_67 ( & V_39 -> V_47 ) ;
int V_50 ;
V_50 = F_68 ( V_39 ) ;
if ( V_50 )
return V_50 ;
F_44 ( V_6 ) ;
F_69 ( V_6 ) ;
return 0 ;
}
