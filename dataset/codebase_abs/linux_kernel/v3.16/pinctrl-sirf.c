static int F_1 ( struct V_1 * V_2 )
{
return V_3 ;
}
static const char * F_2 ( struct V_1 * V_2 ,
unsigned V_4 )
{
return V_5 [ V_4 ] . V_6 ;
}
static int F_3 ( struct V_1 * V_2 , unsigned V_4 ,
const unsigned * * V_7 ,
unsigned * V_8 )
{
* V_7 = V_5 [ V_4 ] . V_7 ;
* V_8 = V_5 [ V_4 ] . V_8 ;
return 0 ;
}
static void F_4 ( struct V_1 * V_2 , struct V_9 * V_10 ,
unsigned V_11 )
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
if ( V_25 < 0 )
return V_25 ;
V_25 = F_10 ( V_20 , L_3 ) ;
if ( V_25 < 0 )
return V_25 ;
V_27 += V_25 ;
}
if ( ! V_27 ) {
F_11 ( V_19 -> V_28 , L_4 ) ;
return - V_29 ;
}
* V_16 = F_12 ( sizeof( * * V_16 ) * V_27 , V_30 ) ;
if ( ! * V_16 )
return - V_31 ;
F_8 (np_config, np) {
F_9 ( V_20 , L_2 , & V_23 ) ;
F_13 (np, L_3 , prop, group) {
( * V_16 ) [ V_26 ] . type = V_32 ;
( * V_16 ) [ V_26 ] . V_33 . V_34 . V_24 = V_24 ;
( * V_16 ) [ V_26 ] . V_33 . V_34 . V_23 = V_23 ;
V_26 ++ ;
}
}
* V_17 = V_27 ;
return 0 ;
}
static void F_14 ( struct V_1 * V_2 ,
struct V_15 * V_16 , unsigned V_17 )
{
F_15 ( V_16 ) ;
}
static void F_16 ( struct V_18 * V_19 , unsigned V_4 ,
bool V_35 )
{
int V_36 ;
const struct V_37 * V_34 = V_38 [ V_4 ] . V_39 ;
const struct V_40 * V_41 = V_34 -> V_42 ;
for ( V_36 = 0 ; V_36 < V_34 -> V_43 ; V_36 ++ ) {
T_1 V_44 ;
if ( ! V_19 -> V_45 ) {
V_44 = F_17 ( V_19 -> V_46 + F_18 ( V_41 [ V_36 ] . V_24 ) ) ;
if ( V_35 )
V_44 = V_44 & ~ V_41 [ V_36 ] . V_41 ;
else
V_44 = V_44 | V_41 [ V_36 ] . V_41 ;
F_19 ( V_44 , V_19 -> V_46 + F_18 ( V_41 [ V_36 ] . V_24 ) ) ;
} else {
if ( V_35 )
F_19 ( V_41 [ V_36 ] . V_41 , V_19 -> V_46 +
F_20 ( V_41 [ V_36 ] . V_24 ) ) ;
else
F_19 ( V_41 [ V_36 ] . V_41 , V_19 -> V_46 +
F_18 ( V_41 [ V_36 ] . V_24 ) ) ;
}
}
if ( V_34 -> V_47 && V_35 ) {
T_1 V_48 ;
V_48 =
F_17 ( V_19 -> V_49 + V_34 -> V_50 ) ;
V_48 =
( V_48 & ~ V_34 -> V_47 ) | ( V_34 -> V_51 ) ;
F_19 ( V_48 , V_19 -> V_49 + V_34 -> V_50 ) ;
}
}
static int F_21 ( struct V_1 * V_52 , unsigned V_4 ,
unsigned V_24 )
{
struct V_18 * V_19 ;
V_19 = F_7 ( V_52 ) ;
F_16 ( V_19 , V_4 , true ) ;
return 0 ;
}
static void F_22 ( struct V_1 * V_52 , unsigned V_4 ,
unsigned V_24 )
{
struct V_18 * V_19 ;
V_19 = F_7 ( V_52 ) ;
F_16 ( V_19 , V_4 , false ) ;
}
static int F_23 ( struct V_1 * V_52 )
{
return V_53 ;
}
static const char * F_24 ( struct V_1 * V_2 ,
unsigned V_4 )
{
return V_38 [ V_4 ] . V_6 ;
}
static int F_25 ( struct V_1 * V_2 , unsigned V_4 ,
const char * const * * V_54 ,
unsigned * const V_55 )
{
* V_54 = V_38 [ V_4 ] . V_54 ;
* V_55 = V_38 [ V_4 ] . V_55 ;
return 0 ;
}
static int F_26 ( struct V_1 * V_52 ,
struct V_56 * V_57 , unsigned V_11 )
{
struct V_18 * V_19 ;
int V_24 = V_57 -> V_58 ;
T_1 V_44 ;
V_19 = F_7 ( V_52 ) ;
if ( ! V_19 -> V_45 ) {
V_44 = F_17 ( V_19 -> V_46 + F_18 ( V_24 ) ) ;
V_44 = V_44 | ( 1 << ( V_11 - V_57 -> V_59 ) ) ;
F_19 ( V_44 , V_19 -> V_46 + F_18 ( V_24 ) ) ;
} else {
F_19 ( 1 << ( V_11 - V_57 -> V_59 ) , V_19 -> V_46 +
F_18 ( V_24 ) ) ;
}
return 0 ;
}
static void T_2 * F_27 ( void )
{
const struct V_60 V_61 [] = {
{ . V_62 = L_5 } ,
{ . V_62 = L_6 } ,
{}
} ;
struct V_13 * V_20 ;
V_20 = F_28 ( NULL , V_61 ) ;
if ( ! V_20 )
F_29 ( L_7 ) ;
return F_30 ( V_20 , 0 ) ;
}
static int F_31 ( struct V_63 * V_64 ,
const struct V_65 * V_66 ,
T_1 * V_67 )
{
if ( V_66 -> args [ 0 ] > V_68 * V_69 )
return - V_70 ;
if ( V_67 )
* V_67 = V_66 -> args [ 1 ] ;
return V_66 -> args [ 0 ] ;
}
static int F_32 ( struct V_71 * V_72 )
{
int V_25 ;
struct V_18 * V_19 ;
struct V_13 * V_20 = V_72 -> V_28 . V_73 ;
const struct V_74 * V_75 ;
V_19 = F_33 ( & V_72 -> V_28 , sizeof( * V_19 ) , V_30 ) ;
if ( ! V_19 )
return - V_31 ;
V_19 -> V_28 = & V_72 -> V_28 ;
F_34 ( V_72 , V_19 ) ;
V_19 -> V_46 = F_30 ( V_20 , 0 ) ;
if ( ! V_19 -> V_46 ) {
F_11 ( & V_72 -> V_28 , L_8 ) ;
return - V_31 ;
}
V_19 -> V_49 = F_27 () ;
if ( ! V_19 -> V_49 ) {
V_25 = - V_31 ;
F_11 ( & V_72 -> V_28 , L_9 ) ;
goto V_76;
}
if ( F_35 ( V_20 , L_10 ) )
V_19 -> V_45 = 1 ;
V_75 = F_36 ( V_77 , V_20 ) -> V_33 ;
V_5 = V_75 -> V_78 ;
V_3 = V_75 -> V_79 ;
V_38 = V_75 -> V_80 ;
V_53 = V_75 -> V_81 ;
V_82 . V_7 = V_75 -> V_83 ;
V_82 . V_84 = V_75 -> V_85 ;
V_19 -> V_86 = F_37 ( & V_82 , & V_72 -> V_28 , V_19 ) ;
if ( ! V_19 -> V_86 ) {
F_11 ( & V_72 -> V_28 , L_11 ) ;
V_25 = - V_70 ;
goto V_87;
}
F_38 ( & V_72 -> V_28 , L_12 ) ;
return 0 ;
V_87:
F_39 ( V_19 -> V_49 ) ;
V_76:
F_39 ( V_19 -> V_46 ) ;
return V_25 ;
}
static int F_40 ( struct V_88 * V_28 )
{
int V_36 , V_89 ;
struct V_18 * V_19 = F_41 ( V_28 ) ;
for ( V_36 = 0 ; V_36 < V_68 ; V_36 ++ ) {
for ( V_89 = 0 ; V_89 < V_69 ; V_89 ++ ) {
V_19 -> V_90 [ V_36 ] [ V_89 ] = F_17 ( V_19 -> V_46 +
F_42 ( V_36 , V_89 ) ) ;
}
V_19 -> V_91 [ V_36 ] = F_17 ( V_19 -> V_46 +
F_43 ( V_36 ) ) ;
V_19 -> V_92 [ V_36 ] = F_17 ( V_19 -> V_46 +
F_18 ( V_36 ) ) ;
}
V_19 -> V_93 = F_17 ( V_19 -> V_46 + V_94 ) ;
for ( V_36 = 0 ; V_36 < 3 ; V_36 ++ )
V_19 -> V_95 [ V_36 ] = F_17 ( V_19 -> V_49 + 4 * V_36 ) ;
return 0 ;
}
static int F_44 ( struct V_88 * V_28 )
{
int V_36 , V_89 ;
struct V_18 * V_19 = F_41 ( V_28 ) ;
for ( V_36 = 0 ; V_36 < V_68 ; V_36 ++ ) {
for ( V_89 = 0 ; V_89 < V_69 ; V_89 ++ ) {
F_19 ( V_19 -> V_90 [ V_36 ] [ V_89 ] , V_19 -> V_46 +
F_42 ( V_36 , V_89 ) ) ;
}
F_19 ( V_19 -> V_91 [ V_36 ] , V_19 -> V_46 +
F_43 ( V_36 ) ) ;
F_19 ( V_19 -> V_92 [ V_36 ] , V_19 -> V_46 +
F_18 ( V_36 ) ) ;
}
F_19 ( V_19 -> V_93 , V_19 -> V_46 + V_94 ) ;
for ( V_36 = 0 ; V_36 < 3 ; V_36 ++ )
F_19 ( V_19 -> V_95 [ V_36 ] , V_19 -> V_49 + 4 * V_36 ) ;
return 0 ;
}
static int T_3 F_45 ( void )
{
return F_46 ( & V_96 ) ;
}
static inline struct V_97 * F_47 ( struct V_63 * V_64 )
{
return F_48 ( V_64 , struct V_97 , V_98 . V_64 ) ;
}
static inline struct V_99 *
F_49 ( struct V_97 * V_100 , unsigned int V_11 )
{
return & V_100 -> V_101 [ V_11 / V_69 ] ;
}
static inline int F_50 ( unsigned int V_11 )
{
return V_11 % V_69 ;
}
static void F_51 ( struct V_102 * V_103 )
{
struct V_63 * V_64 = F_52 ( V_103 ) ;
struct V_97 * V_100 = F_47 ( V_64 ) ;
struct V_99 * V_104 = F_49 ( V_100 , V_103 -> V_105 ) ;
int V_106 = F_50 ( V_103 -> V_105 ) ;
T_1 V_107 , V_11 ;
unsigned long V_67 ;
V_11 = F_42 ( V_104 -> V_58 , V_106 ) ;
F_53 ( & V_108 , V_67 ) ;
V_107 = F_17 ( V_100 -> V_98 . V_109 + V_11 ) ;
F_19 ( V_107 , V_100 -> V_98 . V_109 + V_11 ) ;
F_54 ( & V_108 , V_67 ) ;
}
static void F_55 ( struct V_97 * V_100 ,
struct V_99 * V_104 ,
int V_106 )
{
T_1 V_107 , V_11 ;
unsigned long V_67 ;
V_11 = F_42 ( V_104 -> V_58 , V_106 ) ;
F_53 ( & V_108 , V_67 ) ;
V_107 = F_17 ( V_100 -> V_98 . V_109 + V_11 ) ;
V_107 &= ~ V_110 ;
V_107 &= ~ V_111 ;
F_19 ( V_107 , V_100 -> V_98 . V_109 + V_11 ) ;
F_54 ( & V_108 , V_67 ) ;
}
static void F_56 ( struct V_102 * V_103 )
{
struct V_63 * V_64 = F_52 ( V_103 ) ;
struct V_97 * V_100 = F_47 ( V_64 ) ;
struct V_99 * V_104 = F_49 ( V_100 , V_103 -> V_105 ) ;
F_55 ( V_100 , V_104 , V_103 -> V_105 % V_69 ) ;
}
static void F_57 ( struct V_102 * V_103 )
{
struct V_63 * V_64 = F_52 ( V_103 ) ;
struct V_97 * V_100 = F_47 ( V_64 ) ;
struct V_99 * V_104 = F_49 ( V_100 , V_103 -> V_105 ) ;
int V_106 = F_50 ( V_103 -> V_105 ) ;
T_1 V_107 , V_11 ;
unsigned long V_67 ;
V_11 = F_42 ( V_104 -> V_58 , V_106 ) ;
F_53 ( & V_108 , V_67 ) ;
V_107 = F_17 ( V_100 -> V_98 . V_109 + V_11 ) ;
V_107 &= ~ V_111 ;
V_107 |= V_110 ;
F_19 ( V_107 , V_100 -> V_98 . V_109 + V_11 ) ;
F_54 ( & V_108 , V_67 ) ;
}
static int F_58 ( struct V_102 * V_103 , unsigned type )
{
struct V_63 * V_64 = F_52 ( V_103 ) ;
struct V_97 * V_100 = F_47 ( V_64 ) ;
struct V_99 * V_104 = F_49 ( V_100 , V_103 -> V_105 ) ;
int V_106 = F_50 ( V_103 -> V_105 ) ;
T_1 V_107 , V_11 ;
unsigned long V_67 ;
V_11 = F_42 ( V_104 -> V_58 , V_106 ) ;
F_53 ( & V_108 , V_67 ) ;
V_107 = F_17 ( V_100 -> V_98 . V_109 + V_11 ) ;
V_107 &= ~ ( V_111 | V_112 ) ;
switch ( type ) {
case V_113 :
break;
case V_114 :
V_107 |= V_115 | V_116 ;
V_107 &= ~ V_117 ;
break;
case V_118 :
V_107 &= ~ V_115 ;
V_107 |= V_117 | V_116 ;
break;
case V_119 :
V_107 |= V_115 | V_117 |
V_116 ;
break;
case V_120 :
V_107 &= ~ ( V_115 | V_116 ) ;
V_107 |= V_117 ;
break;
case V_121 :
V_107 |= V_115 ;
V_107 &= ~ ( V_117 | V_116 ) ;
break;
}
F_19 ( V_107 , V_100 -> V_98 . V_109 + V_11 ) ;
F_54 ( & V_108 , V_67 ) ;
return 0 ;
}
static void F_59 ( unsigned int V_122 , struct V_123 * V_124 )
{
struct V_63 * V_64 = F_60 ( V_124 ) ;
struct V_97 * V_100 = F_47 ( V_64 ) ;
struct V_99 * V_104 ;
T_1 V_125 , V_126 ;
int V_106 = 0 ;
struct V_127 * V_98 = F_61 ( V_122 ) ;
int V_36 ;
for ( V_36 = 0 ; V_36 < V_68 ; V_36 ++ ) {
V_104 = & V_100 -> V_101 [ V_36 ] ;
if ( V_104 -> V_128 == V_122 )
break;
}
F_62 ( V_36 == V_68 ) ;
F_63 ( V_98 , V_124 ) ;
V_125 = F_17 ( V_100 -> V_98 . V_109 + F_43 ( V_104 -> V_58 ) ) ;
if ( ! V_125 ) {
F_64 ( V_129
L_13 ,
V_130 , V_104 -> V_58 , V_125 ) ;
F_65 ( V_122 , V_124 ) ;
return;
}
while ( V_125 ) {
V_126 = F_17 ( V_100 -> V_98 . V_109 + F_42 ( V_104 -> V_58 , V_106 ) ) ;
if ( ( V_125 & 0x1 ) && ( V_126 & V_110 ) ) {
F_66 ( L_14 ,
V_130 , V_104 -> V_58 , V_106 ) ;
F_67 ( F_68 ( V_64 -> V_131 , V_106 +
V_104 -> V_58 * V_69 ) ) ;
}
V_106 ++ ;
V_125 = V_125 >> 1 ;
}
F_69 ( V_98 , V_124 ) ;
}
static inline void F_70 ( struct V_97 * V_100 ,
unsigned V_132 )
{
T_1 V_107 ;
V_107 = F_17 ( V_100 -> V_98 . V_109 + V_132 ) ;
V_107 &= ~ V_112 ;
F_19 ( V_107 , V_100 -> V_98 . V_109 + V_132 ) ;
}
static int F_71 ( struct V_63 * V_98 , unsigned V_11 )
{
struct V_97 * V_100 = F_47 ( V_98 ) ;
struct V_99 * V_104 = F_49 ( V_100 , V_11 ) ;
unsigned long V_67 ;
if ( F_72 ( V_98 -> V_133 + V_11 ) )
return - V_29 ;
F_53 ( & V_104 -> V_134 , V_67 ) ;
F_70 ( V_100 , F_42 ( V_104 -> V_58 , V_11 ) ) ;
F_55 ( V_100 , V_104 , V_11 ) ;
F_54 ( & V_104 -> V_134 , V_67 ) ;
return 0 ;
}
static void F_73 ( struct V_63 * V_98 , unsigned V_11 )
{
struct V_97 * V_100 = F_47 ( V_98 ) ;
struct V_99 * V_104 = F_49 ( V_100 , V_11 ) ;
unsigned long V_67 ;
F_53 ( & V_104 -> V_134 , V_67 ) ;
F_55 ( V_100 , V_104 , V_11 ) ;
F_70 ( V_100 , F_42 ( V_104 -> V_58 , V_11 ) ) ;
F_54 ( & V_104 -> V_134 , V_67 ) ;
F_74 ( V_98 -> V_133 + V_11 ) ;
}
static int F_75 ( struct V_63 * V_98 , unsigned V_135 )
{
struct V_97 * V_100 = F_47 ( V_98 ) ;
struct V_99 * V_104 = F_49 ( V_100 , V_135 ) ;
int V_106 = F_50 ( V_135 ) ;
unsigned long V_67 ;
unsigned V_11 ;
V_11 = F_42 ( V_104 -> V_58 , V_106 ) ;
F_53 ( & V_104 -> V_134 , V_67 ) ;
F_70 ( V_100 , V_11 ) ;
F_54 ( & V_104 -> V_134 , V_67 ) ;
return 0 ;
}
static inline void F_76 ( struct V_97 * V_100 ,
struct V_99 * V_104 ,
unsigned V_11 ,
int V_136 )
{
T_1 V_137 ;
unsigned long V_67 ;
F_53 ( & V_104 -> V_134 , V_67 ) ;
V_137 = F_17 ( V_100 -> V_98 . V_109 + V_11 ) ;
if ( V_136 )
V_137 |= V_138 ;
else
V_137 &= ~ V_138 ;
V_137 &= ~ V_110 ;
V_137 |= V_112 ;
F_19 ( V_137 , V_100 -> V_98 . V_109 + V_11 ) ;
F_54 ( & V_104 -> V_134 , V_67 ) ;
}
static int F_77 ( struct V_63 * V_98 , unsigned V_135 , int V_136 )
{
struct V_97 * V_100 = F_47 ( V_98 ) ;
struct V_99 * V_104 = F_49 ( V_100 , V_135 ) ;
int V_106 = F_50 ( V_135 ) ;
T_1 V_11 ;
unsigned long V_67 ;
V_11 = F_42 ( V_104 -> V_58 , V_106 ) ;
F_53 ( & V_108 , V_67 ) ;
F_76 ( V_100 , V_104 , V_11 , V_136 ) ;
F_54 ( & V_108 , V_67 ) ;
return 0 ;
}
static int F_78 ( struct V_63 * V_98 , unsigned V_11 )
{
struct V_97 * V_100 = F_47 ( V_98 ) ;
struct V_99 * V_104 = F_49 ( V_100 , V_11 ) ;
T_1 V_107 ;
unsigned long V_67 ;
F_53 ( & V_104 -> V_134 , V_67 ) ;
V_107 = F_17 ( V_100 -> V_98 . V_109 + F_42 ( V_104 -> V_58 , V_11 ) ) ;
F_54 ( & V_104 -> V_134 , V_67 ) ;
return ! ! ( V_107 & V_139 ) ;
}
static void F_79 ( struct V_63 * V_98 , unsigned V_11 ,
int V_136 )
{
struct V_97 * V_100 = F_47 ( V_98 ) ;
struct V_99 * V_104 = F_49 ( V_100 , V_11 ) ;
T_1 V_126 ;
unsigned long V_67 ;
F_53 ( & V_104 -> V_134 , V_67 ) ;
V_126 = F_17 ( V_100 -> V_98 . V_109 + F_42 ( V_104 -> V_58 , V_11 ) ) ;
if ( V_136 )
V_126 |= V_138 ;
else
V_126 &= ~ V_138 ;
F_19 ( V_126 , V_100 -> V_98 . V_109 + F_42 ( V_104 -> V_58 , V_11 ) ) ;
F_54 ( & V_104 -> V_134 , V_67 ) ;
}
static void F_80 ( struct V_97 * V_100 ,
const T_1 * V_140 )
{
int V_36 , V_141 ;
const unsigned long * V_142 = ( const unsigned long * ) V_140 ;
for ( V_36 = 0 ; V_36 < V_68 ; V_36 ++ ) {
F_81 (n, p + i, BITS_PER_LONG) {
T_1 V_11 = F_42 ( V_36 , V_141 ) ;
T_1 V_107 = F_17 ( V_100 -> V_98 . V_109 + V_11 ) ;
V_107 |= V_143 ;
V_107 |= V_144 ;
F_19 ( V_107 , V_100 -> V_98 . V_109 + V_11 ) ;
}
}
}
static void F_82 ( struct V_97 * V_100 ,
const T_1 * V_145 )
{
int V_36 , V_141 ;
const unsigned long * V_142 = ( const unsigned long * ) V_145 ;
for ( V_36 = 0 ; V_36 < V_68 ; V_36 ++ ) {
F_81 (n, p + i, BITS_PER_LONG) {
T_1 V_11 = F_42 ( V_36 , V_141 ) ;
T_1 V_107 = F_17 ( V_100 -> V_98 . V_109 + V_11 ) ;
V_107 |= V_143 ;
V_107 &= ~ V_144 ;
F_19 ( V_107 , V_100 -> V_98 . V_109 + V_11 ) ;
}
}
}
static int F_83 ( struct V_13 * V_20 )
{
int V_36 , V_146 = 0 ;
static struct V_97 * V_100 ;
struct V_99 * V_104 ;
void T_2 * V_109 ;
struct V_71 * V_72 ;
bool V_45 = false ;
T_1 V_140 [ V_68 ] , V_145 [ V_68 ] ;
V_72 = F_84 ( V_20 ) ;
if ( ! V_72 )
return - V_29 ;
V_100 = F_33 ( & V_72 -> V_28 , sizeof( * V_100 ) , V_30 ) ;
if ( ! V_100 )
return - V_31 ;
V_109 = F_30 ( V_20 , 0 ) ;
if ( ! V_109 )
return - V_31 ;
if ( F_35 ( V_20 , L_10 ) )
V_45 = 1 ;
V_100 -> V_98 . V_64 . V_147 = F_71 ;
V_100 -> V_98 . V_64 . free = F_73 ;
V_100 -> V_98 . V_64 . V_148 = F_75 ;
V_100 -> V_98 . V_64 . V_149 = F_78 ;
V_100 -> V_98 . V_64 . V_150 = F_77 ;
V_100 -> V_98 . V_64 . V_151 = F_79 ;
V_100 -> V_98 . V_64 . V_133 = 0 ;
V_100 -> V_98 . V_64 . V_152 = V_69 * V_68 ;
V_100 -> V_98 . V_64 . V_153 = F_85 ( V_20 -> V_154 , V_30 ) ;
V_100 -> V_98 . V_64 . V_73 = V_20 ;
V_100 -> V_98 . V_64 . V_155 = F_31 ;
V_100 -> V_98 . V_64 . V_156 = 2 ;
V_100 -> V_98 . V_64 . V_28 = & V_72 -> V_28 ;
V_100 -> V_98 . V_109 = V_109 ;
V_100 -> V_45 = V_45 ;
V_146 = F_86 ( & V_100 -> V_98 . V_64 ) ;
if ( V_146 ) {
F_11 ( & V_72 -> V_28 , L_15 ,
V_20 -> V_154 , V_146 ) ;
goto V_157;
}
V_146 = F_87 ( & V_100 -> V_98 . V_64 ,
& V_158 ,
0 , V_159 ,
V_113 ) ;
if ( V_146 ) {
F_11 ( & V_72 -> V_28 ,
L_16 ) ;
goto V_157;
}
for ( V_36 = 0 ; V_36 < V_68 ; V_36 ++ ) {
V_104 = & V_100 -> V_101 [ V_36 ] ;
F_88 ( & V_104 -> V_134 ) ;
V_104 -> V_128 = F_89 ( V_72 , V_36 ) ;
if ( V_104 -> V_128 < 0 ) {
V_146 = V_104 -> V_128 ;
goto V_160;
}
F_90 ( & V_100 -> V_98 . V_64 ,
& V_158 ,
V_104 -> V_128 ,
F_59 ) ;
}
V_146 = F_91 ( & V_100 -> V_98 . V_64 , F_92 ( & V_72 -> V_28 ) ,
0 , 0 , V_69 * V_68 ) ;
if ( V_146 ) {
F_11 ( & V_72 -> V_28 ,
L_17 ) ;
goto V_161;
}
if ( ! F_93 ( V_20 , L_18 , V_140 ,
V_68 ) )
F_80 ( V_100 , V_140 ) ;
if ( ! F_93 ( V_20 , L_19 , V_145 ,
V_68 ) )
F_82 ( V_100 , V_145 ) ;
return 0 ;
V_161:
V_160:
if ( F_94 ( & V_100 -> V_98 . V_64 ) )
F_11 ( & V_72 -> V_28 , L_20 ) ;
V_157:
F_39 ( V_109 ) ;
return V_146 ;
}
static int T_3 F_95 ( void )
{
struct V_13 * V_20 ;
V_20 = F_28 ( NULL , V_77 ) ;
if ( ! V_20 )
return - V_29 ;
return F_83 ( V_20 ) ;
}
