static int F_1 ( struct V_1 * V_2 )
{
return V_3 ;
}
static const char * F_2 ( struct V_1 * V_2 ,
unsigned V_4 )
{
return V_5 [ V_4 ] . V_6 ;
}
static int F_3 ( struct V_1 * V_2 ,
unsigned V_4 ,
const unsigned * * V_7 ,
unsigned * V_8 )
{
* V_7 = V_5 [ V_4 ] . V_7 ;
* V_8 = V_5 [ V_4 ] . V_8 ;
return 0 ;
}
static void F_4 ( struct V_1 * V_2 ,
struct V_9 * V_10 , unsigned V_11 )
{
F_5 ( V_10 , L_1 V_12 ) ;
}
static int F_6 ( struct V_1 * V_2 ,
struct V_13 * V_14 ,
struct V_15 * * V_16 , unsigned * V_17 )
{
struct V_18 * V_19 = F_7 ( V_2 ) ;
struct V_13 * V_20 ;
struct V_21 * V_22 ;
const char * V_23 , * V_24 ;
int V_25 , V_26 = 0 , V_27 = 0 ;
F_8 (np_config, np) {
V_25 = F_9 ( V_20 , L_2 , & V_23 ) ;
if ( V_25 < 0 ) {
F_10 ( V_20 ) ;
return V_25 ;
}
V_25 = F_11 ( V_20 , L_3 ) ;
if ( V_25 < 0 ) {
F_10 ( V_20 ) ;
return V_25 ;
}
V_27 += V_25 ;
}
if ( ! V_27 ) {
F_12 ( V_19 -> V_28 , L_4 ) ;
return - V_29 ;
}
* V_16 = F_13 ( sizeof( * * V_16 ) * V_27 , V_30 ) ;
if ( ! * V_16 )
return - V_31 ;
F_8 (np_config, np) {
F_9 ( V_20 , L_2 , & V_23 ) ;
F_14 (np, L_3 , prop, group) {
( * V_16 ) [ V_26 ] . type = V_32 ;
( * V_16 ) [ V_26 ] . V_33 . V_34 . V_24 = V_24 ;
( * V_16 ) [ V_26 ] . V_33 . V_34 . V_23 = V_23 ;
V_26 ++ ;
}
}
* V_17 = V_27 ;
return 0 ;
}
static void F_15 ( struct V_1 * V_2 ,
struct V_15 * V_16 , unsigned V_17 )
{
F_16 ( V_16 ) ;
}
static void F_17 ( struct V_18 * V_19 ,
unsigned V_4 , bool V_35 )
{
int V_36 ;
const struct V_37 * V_34 =
V_38 [ V_4 ] . V_39 ;
const struct V_40 * V_41 = V_34 -> V_42 ;
for ( V_36 = 0 ; V_36 < V_34 -> V_43 ; V_36 ++ ) {
T_1 V_44 ;
V_44 = F_18 ( V_19 -> V_45 +
F_19 ( V_41 [ V_36 ] . V_24 ) ) ;
if ( V_35 )
V_44 = V_44 & ~ V_41 [ V_36 ] . V_41 ;
else
V_44 = V_44 | V_41 [ V_36 ] . V_41 ;
F_20 ( V_44 , V_19 -> V_45 +
F_19 ( V_41 [ V_36 ] . V_24 ) ) ;
}
if ( V_34 -> V_46 && V_35 ) {
T_1 V_47 ;
V_47 =
F_18 ( V_19 -> V_48 + V_34 -> V_49 ) ;
V_47 =
( V_47 & ~ V_34 -> V_46 ) | ( V_34 -> V_50 ) ;
F_20 ( V_47 , V_19 -> V_48 + V_34 -> V_49 ) ;
}
}
static int F_21 ( struct V_1 * V_51 ,
unsigned V_4 ,
unsigned V_24 )
{
struct V_18 * V_19 ;
V_19 = F_7 ( V_51 ) ;
F_17 ( V_19 , V_4 , true ) ;
return 0 ;
}
static int F_22 ( struct V_1 * V_51 )
{
return V_52 ;
}
static const char * F_23 ( struct V_1 * V_2 ,
unsigned V_4 )
{
return V_38 [ V_4 ] . V_6 ;
}
static int F_24 ( struct V_1 * V_2 ,
unsigned V_4 ,
const char * const * * V_53 ,
unsigned * const V_54 )
{
* V_53 = V_38 [ V_4 ] . V_53 ;
* V_54 = V_38 [ V_4 ] . V_54 ;
return 0 ;
}
static int F_25 ( struct V_1 * V_51 ,
struct V_55 * V_56 , unsigned V_11 )
{
struct V_18 * V_19 ;
int V_24 = V_56 -> V_57 ;
T_1 V_44 ;
V_19 = F_7 ( V_51 ) ;
V_44 = F_18 ( V_19 -> V_45 +
F_19 ( V_24 ) ) ;
V_44 = V_44 | ( 1 << ( V_11 - V_56 -> V_58 ) ) ;
F_20 ( V_44 , V_19 -> V_45 +
F_19 ( V_24 ) ) ;
return 0 ;
}
static void T_2 * F_26 ( void )
{
const struct V_59 V_60 [] = {
{ . V_61 = L_5 } ,
{}
} ;
struct V_13 * V_20 ;
V_20 = F_27 ( NULL , V_60 ) ;
if ( ! V_20 )
F_28 ( L_6 ) ;
return F_29 ( V_20 , 0 ) ;
}
static int F_30 ( struct V_62 * V_63 ,
const struct V_64 * V_65 ,
T_1 * V_66 )
{
if ( V_65 -> args [ 0 ] > V_67 * V_68 )
return - V_69 ;
if ( V_66 )
* V_66 = V_65 -> args [ 1 ] ;
return V_65 -> args [ 0 ] ;
}
static int F_31 ( struct V_70 * V_71 )
{
int V_25 ;
struct V_18 * V_19 ;
struct V_13 * V_20 = V_71 -> V_28 . V_72 ;
const struct V_73 * V_74 ;
V_19 = F_32 ( & V_71 -> V_28 , sizeof( * V_19 ) , V_30 ) ;
if ( ! V_19 )
return - V_31 ;
V_19 -> V_28 = & V_71 -> V_28 ;
F_33 ( V_71 , V_19 ) ;
V_19 -> V_45 = F_29 ( V_20 , 0 ) ;
if ( ! V_19 -> V_45 ) {
F_12 ( & V_71 -> V_28 , L_7 ) ;
return - V_31 ;
}
V_19 -> V_48 = F_26 () ;
if ( ! V_19 -> V_48 ) {
V_25 = - V_31 ;
F_12 ( & V_71 -> V_28 , L_8 ) ;
goto V_75;
}
V_74 = F_34 ( V_76 , V_20 ) -> V_33 ;
V_5 = V_74 -> V_77 ;
V_3 = V_74 -> V_78 ;
V_38 = V_74 -> V_79 ;
V_52 = V_74 -> V_80 ;
V_81 . V_7 = V_74 -> V_82 ;
V_81 . V_83 = V_74 -> V_84 ;
V_19 -> V_85 = F_35 ( & V_81 , & V_71 -> V_28 , V_19 ) ;
if ( F_36 ( V_19 -> V_85 ) ) {
F_12 ( & V_71 -> V_28 , L_9 ) ;
V_25 = F_37 ( V_19 -> V_85 ) ;
goto V_86;
}
F_38 ( & V_71 -> V_28 , L_10 ) ;
return 0 ;
V_86:
F_39 ( V_19 -> V_48 ) ;
V_75:
F_39 ( V_19 -> V_45 ) ;
return V_25 ;
}
static int F_40 ( struct V_87 * V_28 )
{
int V_36 , V_88 ;
struct V_18 * V_19 = F_41 ( V_28 ) ;
for ( V_36 = 0 ; V_36 < V_67 ; V_36 ++ ) {
for ( V_88 = 0 ; V_88 < V_68 ; V_88 ++ ) {
V_19 -> V_89 [ V_36 ] [ V_88 ] = F_18 ( V_19 -> V_45 +
F_42 ( V_36 , V_88 ) ) ;
}
V_19 -> V_90 [ V_36 ] = F_18 ( V_19 -> V_45 +
F_43 ( V_36 ) ) ;
V_19 -> V_91 [ V_36 ] = F_18 ( V_19 -> V_45 +
F_19 ( V_36 ) ) ;
}
V_19 -> V_92 = F_18 ( V_19 -> V_45 + V_93 ) ;
for ( V_36 = 0 ; V_36 < 3 ; V_36 ++ )
V_19 -> V_94 [ V_36 ] = F_18 ( V_19 -> V_48 + 4 * V_36 ) ;
return 0 ;
}
static int F_44 ( struct V_87 * V_28 )
{
int V_36 , V_88 ;
struct V_18 * V_19 = F_41 ( V_28 ) ;
for ( V_36 = 0 ; V_36 < V_67 ; V_36 ++ ) {
for ( V_88 = 0 ; V_88 < V_68 ; V_88 ++ ) {
F_20 ( V_19 -> V_89 [ V_36 ] [ V_88 ] , V_19 -> V_45 +
F_42 ( V_36 , V_88 ) ) ;
}
F_20 ( V_19 -> V_90 [ V_36 ] , V_19 -> V_45 +
F_43 ( V_36 ) ) ;
F_20 ( V_19 -> V_91 [ V_36 ] , V_19 -> V_45 +
F_19 ( V_36 ) ) ;
}
F_20 ( V_19 -> V_92 , V_19 -> V_45 + V_93 ) ;
for ( V_36 = 0 ; V_36 < 3 ; V_36 ++ )
F_20 ( V_19 -> V_94 [ V_36 ] , V_19 -> V_48 + 4 * V_36 ) ;
return 0 ;
}
static int T_3 F_45 ( void )
{
return F_46 ( & V_95 ) ;
}
static inline struct V_96 *
F_47 ( struct V_97 * V_98 , unsigned int V_11 )
{
return & V_98 -> V_99 [ V_11 / V_68 ] ;
}
static inline int F_48 ( unsigned int V_11 )
{
return V_11 % V_68 ;
}
static void F_49 ( struct V_100 * V_101 )
{
struct V_62 * V_63 = F_50 ( V_101 ) ;
struct V_97 * V_98 = F_51 ( V_63 ) ;
struct V_96 * V_102 = F_47 ( V_98 , V_101 -> V_103 ) ;
int V_104 = F_48 ( V_101 -> V_103 ) ;
T_1 V_105 , V_11 ;
unsigned long V_66 ;
V_11 = F_42 ( V_102 -> V_57 , V_104 ) ;
F_52 ( & V_98 -> V_106 , V_66 ) ;
V_105 = F_18 ( V_98 -> V_107 . V_108 + V_11 ) ;
F_20 ( V_105 , V_98 -> V_107 . V_108 + V_11 ) ;
F_53 ( & V_98 -> V_106 , V_66 ) ;
}
static void F_54 ( struct V_97 * V_98 ,
struct V_96 * V_102 ,
int V_104 )
{
T_1 V_105 , V_11 ;
unsigned long V_66 ;
V_11 = F_42 ( V_102 -> V_57 , V_104 ) ;
F_52 ( & V_98 -> V_106 , V_66 ) ;
V_105 = F_18 ( V_98 -> V_107 . V_108 + V_11 ) ;
V_105 &= ~ V_109 ;
V_105 &= ~ V_110 ;
F_20 ( V_105 , V_98 -> V_107 . V_108 + V_11 ) ;
F_53 ( & V_98 -> V_106 , V_66 ) ;
}
static void F_55 ( struct V_100 * V_101 )
{
struct V_62 * V_63 = F_50 ( V_101 ) ;
struct V_97 * V_98 = F_51 ( V_63 ) ;
struct V_96 * V_102 = F_47 ( V_98 , V_101 -> V_103 ) ;
F_54 ( V_98 , V_102 , V_101 -> V_103 % V_68 ) ;
}
static void F_56 ( struct V_100 * V_101 )
{
struct V_62 * V_63 = F_50 ( V_101 ) ;
struct V_97 * V_98 = F_51 ( V_63 ) ;
struct V_96 * V_102 = F_47 ( V_98 , V_101 -> V_103 ) ;
int V_104 = F_48 ( V_101 -> V_103 ) ;
T_1 V_105 , V_11 ;
unsigned long V_66 ;
V_11 = F_42 ( V_102 -> V_57 , V_104 ) ;
F_52 ( & V_98 -> V_106 , V_66 ) ;
V_105 = F_18 ( V_98 -> V_107 . V_108 + V_11 ) ;
V_105 &= ~ V_110 ;
V_105 |= V_109 ;
F_20 ( V_105 , V_98 -> V_107 . V_108 + V_11 ) ;
F_53 ( & V_98 -> V_106 , V_66 ) ;
}
static int F_57 ( struct V_100 * V_101 , unsigned type )
{
struct V_62 * V_63 = F_50 ( V_101 ) ;
struct V_97 * V_98 = F_51 ( V_63 ) ;
struct V_96 * V_102 = F_47 ( V_98 , V_101 -> V_103 ) ;
int V_104 = F_48 ( V_101 -> V_103 ) ;
T_1 V_105 , V_11 ;
unsigned long V_66 ;
V_11 = F_42 ( V_102 -> V_57 , V_104 ) ;
F_52 ( & V_98 -> V_106 , V_66 ) ;
V_105 = F_18 ( V_98 -> V_107 . V_108 + V_11 ) ;
V_105 &= ~ ( V_110 | V_111 ) ;
switch ( type ) {
case V_112 :
break;
case V_113 :
V_105 |= V_114 |
V_115 ;
V_105 &= ~ V_116 ;
break;
case V_117 :
V_105 &= ~ V_114 ;
V_105 |= V_116 |
V_115 ;
break;
case V_118 :
V_105 |= V_114 |
V_116 |
V_115 ;
break;
case V_119 :
V_105 &= ~ ( V_114 |
V_115 ) ;
V_105 |= V_116 ;
break;
case V_120 :
V_105 |= V_114 ;
V_105 &= ~ ( V_116 |
V_115 ) ;
break;
}
F_20 ( V_105 , V_98 -> V_107 . V_108 + V_11 ) ;
F_53 ( & V_98 -> V_106 , V_66 ) ;
return 0 ;
}
static void F_58 ( struct V_121 * V_122 )
{
unsigned int V_123 = F_59 ( V_122 ) ;
struct V_62 * V_63 = F_60 ( V_122 ) ;
struct V_97 * V_98 = F_51 ( V_63 ) ;
struct V_96 * V_102 ;
T_1 V_124 , V_125 ;
int V_104 = 0 ;
struct V_126 * V_107 = F_61 ( V_122 ) ;
int V_36 ;
for ( V_36 = 0 ; V_36 < V_67 ; V_36 ++ ) {
V_102 = & V_98 -> V_99 [ V_36 ] ;
if ( V_102 -> V_127 == V_123 )
break;
}
F_62 ( V_36 == V_67 ) ;
F_63 ( V_107 , V_122 ) ;
V_124 = F_18 ( V_98 -> V_107 . V_108 + F_43 ( V_102 -> V_57 ) ) ;
if ( ! V_124 ) {
F_64 ( V_128
L_11 ,
V_129 , V_102 -> V_57 , V_124 ) ;
F_65 ( V_122 ) ;
return;
}
while ( V_124 ) {
V_125 = F_18 ( V_98 -> V_107 . V_108 + F_42 ( V_102 -> V_57 , V_104 ) ) ;
if ( ( V_124 & 0x1 ) && ( V_125 & V_109 ) ) {
F_66 ( L_12 ,
V_129 , V_102 -> V_57 , V_104 ) ;
F_67 ( F_68 ( V_63 -> V_130 , V_104 +
V_102 -> V_57 * V_68 ) ) ;
}
V_104 ++ ;
V_124 = V_124 >> 1 ;
}
F_69 ( V_107 , V_122 ) ;
}
static inline void F_70 ( struct V_97 * V_98 ,
unsigned V_131 )
{
T_1 V_105 ;
V_105 = F_18 ( V_98 -> V_107 . V_108 + V_131 ) ;
V_105 &= ~ V_111 ;
F_20 ( V_105 , V_98 -> V_107 . V_108 + V_131 ) ;
}
static int F_71 ( struct V_62 * V_107 , unsigned V_11 )
{
struct V_97 * V_98 = F_51 ( V_107 ) ;
struct V_96 * V_102 = F_47 ( V_98 , V_11 ) ;
unsigned long V_66 ;
if ( F_72 ( V_107 -> V_132 + V_11 ) )
return - V_29 ;
F_52 ( & V_102 -> V_106 , V_66 ) ;
F_70 ( V_98 , F_42 ( V_102 -> V_57 , V_11 ) ) ;
F_54 ( V_98 , V_102 , V_11 ) ;
F_53 ( & V_102 -> V_106 , V_66 ) ;
return 0 ;
}
static void F_73 ( struct V_62 * V_107 , unsigned V_11 )
{
struct V_97 * V_98 = F_51 ( V_107 ) ;
struct V_96 * V_102 = F_47 ( V_98 , V_11 ) ;
unsigned long V_66 ;
F_52 ( & V_102 -> V_106 , V_66 ) ;
F_54 ( V_98 , V_102 , V_11 ) ;
F_70 ( V_98 , F_42 ( V_102 -> V_57 , V_11 ) ) ;
F_53 ( & V_102 -> V_106 , V_66 ) ;
F_74 ( V_107 -> V_132 + V_11 ) ;
}
static int F_75 ( struct V_62 * V_107 , unsigned V_133 )
{
struct V_97 * V_98 = F_51 ( V_107 ) ;
struct V_96 * V_102 = F_47 ( V_98 , V_133 ) ;
int V_104 = F_48 ( V_133 ) ;
unsigned long V_66 ;
unsigned V_11 ;
V_11 = F_42 ( V_102 -> V_57 , V_104 ) ;
F_52 ( & V_102 -> V_106 , V_66 ) ;
F_70 ( V_98 , V_11 ) ;
F_53 ( & V_102 -> V_106 , V_66 ) ;
return 0 ;
}
static inline void F_76 ( struct V_97 * V_98 ,
struct V_96 * V_102 ,
unsigned V_11 ,
int V_134 )
{
T_1 V_135 ;
unsigned long V_66 ;
F_52 ( & V_102 -> V_106 , V_66 ) ;
V_135 = F_18 ( V_98 -> V_107 . V_108 + V_11 ) ;
if ( V_134 )
V_135 |= V_136 ;
else
V_135 &= ~ V_136 ;
V_135 &= ~ V_109 ;
V_135 |= V_111 ;
F_20 ( V_135 , V_98 -> V_107 . V_108 + V_11 ) ;
F_53 ( & V_102 -> V_106 , V_66 ) ;
}
static int F_77 ( struct V_62 * V_107 ,
unsigned V_133 , int V_134 )
{
struct V_97 * V_98 = F_51 ( V_107 ) ;
struct V_96 * V_102 = F_47 ( V_98 , V_133 ) ;
int V_104 = F_48 ( V_133 ) ;
T_1 V_11 ;
unsigned long V_66 ;
V_11 = F_42 ( V_102 -> V_57 , V_104 ) ;
F_52 ( & V_98 -> V_106 , V_66 ) ;
F_76 ( V_98 , V_102 , V_11 , V_134 ) ;
F_53 ( & V_98 -> V_106 , V_66 ) ;
return 0 ;
}
static int F_78 ( struct V_62 * V_107 , unsigned V_11 )
{
struct V_97 * V_98 = F_51 ( V_107 ) ;
struct V_96 * V_102 = F_47 ( V_98 , V_11 ) ;
T_1 V_105 ;
unsigned long V_66 ;
F_52 ( & V_102 -> V_106 , V_66 ) ;
V_105 = F_18 ( V_98 -> V_107 . V_108 + F_42 ( V_102 -> V_57 , V_11 ) ) ;
F_53 ( & V_102 -> V_106 , V_66 ) ;
return ! ! ( V_105 & V_137 ) ;
}
static void F_79 ( struct V_62 * V_107 , unsigned V_11 ,
int V_134 )
{
struct V_97 * V_98 = F_51 ( V_107 ) ;
struct V_96 * V_102 = F_47 ( V_98 , V_11 ) ;
T_1 V_125 ;
unsigned long V_66 ;
F_52 ( & V_102 -> V_106 , V_66 ) ;
V_125 = F_18 ( V_98 -> V_107 . V_108 + F_42 ( V_102 -> V_57 , V_11 ) ) ;
if ( V_134 )
V_125 |= V_136 ;
else
V_125 &= ~ V_136 ;
F_20 ( V_125 , V_98 -> V_107 . V_108 + F_42 ( V_102 -> V_57 , V_11 ) ) ;
F_53 ( & V_102 -> V_106 , V_66 ) ;
}
static void F_80 ( struct V_97 * V_98 ,
const T_1 * V_138 )
{
int V_36 , V_139 ;
const unsigned long * V_140 = ( const unsigned long * ) V_138 ;
for ( V_36 = 0 ; V_36 < V_67 ; V_36 ++ ) {
F_81 (n, p + i, BITS_PER_LONG) {
T_1 V_11 = F_42 ( V_36 , V_139 ) ;
T_1 V_105 = F_18 ( V_98 -> V_107 . V_108 + V_11 ) ;
V_105 |= V_141 ;
V_105 |= V_142 ;
F_20 ( V_105 , V_98 -> V_107 . V_108 + V_11 ) ;
}
}
}
static void F_82 ( struct V_97 * V_98 ,
const T_1 * V_143 )
{
int V_36 , V_139 ;
const unsigned long * V_140 = ( const unsigned long * ) V_143 ;
for ( V_36 = 0 ; V_36 < V_67 ; V_36 ++ ) {
F_81 (n, p + i, BITS_PER_LONG) {
T_1 V_11 = F_42 ( V_36 , V_139 ) ;
T_1 V_105 = F_18 ( V_98 -> V_107 . V_108 + V_11 ) ;
V_105 |= V_141 ;
V_105 &= ~ V_142 ;
F_20 ( V_105 , V_98 -> V_107 . V_108 + V_11 ) ;
}
}
}
static int F_83 ( struct V_13 * V_20 )
{
int V_36 , V_144 = 0 ;
static struct V_97 * V_98 ;
struct V_96 * V_102 ;
void T_2 * V_108 ;
struct V_70 * V_71 ;
T_1 V_138 [ V_67 ] , V_143 [ V_67 ] ;
V_71 = F_84 ( V_20 ) ;
if ( ! V_71 )
return - V_29 ;
V_98 = F_32 ( & V_71 -> V_28 , sizeof( * V_98 ) , V_30 ) ;
if ( ! V_98 )
return - V_31 ;
F_85 ( & V_98 -> V_106 ) ;
V_108 = F_29 ( V_20 , 0 ) ;
if ( ! V_108 )
return - V_31 ;
V_98 -> V_107 . V_63 . V_145 = F_71 ;
V_98 -> V_107 . V_63 . free = F_73 ;
V_98 -> V_107 . V_63 . V_146 = F_75 ;
V_98 -> V_107 . V_63 . V_147 = F_78 ;
V_98 -> V_107 . V_63 . V_148 = F_77 ;
V_98 -> V_107 . V_63 . V_149 = F_79 ;
V_98 -> V_107 . V_63 . V_132 = 0 ;
V_98 -> V_107 . V_63 . V_150 = V_68 * V_67 ;
V_98 -> V_107 . V_63 . V_151 = F_86 ( V_20 -> V_152 , V_30 ) ;
V_98 -> V_107 . V_63 . V_72 = V_20 ;
V_98 -> V_107 . V_63 . V_153 = F_30 ;
V_98 -> V_107 . V_63 . V_154 = 2 ;
V_98 -> V_107 . V_63 . V_155 = & V_71 -> V_28 ;
V_98 -> V_107 . V_108 = V_108 ;
V_144 = F_87 ( & V_98 -> V_107 . V_63 , V_98 ) ;
if ( V_144 ) {
F_12 ( & V_71 -> V_28 , L_13 ,
V_20 -> V_152 , V_144 ) ;
goto V_156;
}
V_144 = F_88 ( & V_98 -> V_107 . V_63 ,
& V_157 ,
0 , V_158 ,
V_112 ) ;
if ( V_144 ) {
F_12 ( & V_71 -> V_28 ,
L_14 ) ;
goto V_159;
}
for ( V_36 = 0 ; V_36 < V_67 ; V_36 ++ ) {
V_102 = & V_98 -> V_99 [ V_36 ] ;
F_85 ( & V_102 -> V_106 ) ;
V_102 -> V_127 = F_89 ( V_71 , V_36 ) ;
if ( V_102 -> V_127 < 0 ) {
V_144 = V_102 -> V_127 ;
goto V_159;
}
F_90 ( & V_98 -> V_107 . V_63 ,
& V_157 ,
V_102 -> V_127 ,
F_58 ) ;
}
V_144 = F_91 ( & V_98 -> V_107 . V_63 , F_92 ( & V_71 -> V_28 ) ,
0 , 0 , V_68 * V_67 ) ;
if ( V_144 ) {
F_12 ( & V_71 -> V_28 ,
L_15 ) ;
goto V_160;
}
if ( ! F_93 ( V_20 , L_16 , V_138 ,
V_67 ) )
F_80 ( V_98 , V_138 ) ;
if ( ! F_93 ( V_20 , L_17 , V_143 ,
V_67 ) )
F_82 ( V_98 , V_143 ) ;
return 0 ;
V_160:
V_159:
F_94 ( & V_98 -> V_107 . V_63 ) ;
V_156:
F_39 ( V_108 ) ;
return V_144 ;
}
static int T_3 F_95 ( void )
{
struct V_13 * V_20 ;
V_20 = F_27 ( NULL , V_76 ) ;
if ( ! V_20 )
return - V_29 ;
return F_83 ( V_20 ) ;
}
