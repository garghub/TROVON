static inline int F_1 ( struct V_1 * V_2 )
{
return F_2 ( V_2 ) -> V_3 & V_4 ;
}
static inline T_1 F_3 ( T_1 V_5 )
{
return V_5 ? 1 << ( V_5 - 1 ) : 0 ;
}
static inline struct V_6 * F_4 ( struct V_7 * V_8 , T_1 V_9 )
{
return & V_8 -> V_10 [ F_5 ( V_9 , V_8 -> V_11 ) & V_8 -> V_12 ] ;
}
int F_6 ( struct V_13 * V_14 )
{
if ( F_7 ( V_14 -> V_15 -> type != V_16 ) )
return - V_17 ;
F_8 ( & V_18 ) ;
F_9 ( & V_14 -> V_19 , & V_20 ) ;
F_10 ( & V_18 ) ;
if ( V_14 -> V_21 )
F_11 ( V_14 -> V_21 ) ;
return 0 ;
}
int F_12 ( struct V_13 * V_14 )
{
bool V_22 = false ;
struct V_13 * V_23 ;
F_8 ( & V_18 ) ;
F_13 (tmp, &netlink_tap_all, list) {
if ( V_14 == V_23 ) {
F_14 ( & V_14 -> V_19 ) ;
V_22 = true ;
goto V_24;
}
}
F_15 ( L_1 , V_14 ) ;
V_24:
F_10 ( & V_18 ) ;
if ( V_22 && V_14 -> V_21 )
F_16 ( V_14 -> V_21 ) ;
return V_22 ? 0 : - V_25 ;
}
int F_17 ( struct V_13 * V_14 )
{
int V_26 ;
V_26 = F_12 ( V_14 ) ;
F_18 () ;
return V_26 ;
}
static bool F_19 ( const struct V_27 * V_28 )
{
struct V_1 * V_2 = V_28 -> V_2 ;
bool V_29 = false ;
switch ( V_2 -> V_30 ) {
case V_31 :
case V_32 :
case V_33 :
case V_34 :
case V_35 :
case V_36 :
case V_37 :
case V_38 :
V_29 = true ;
break;
}
return V_29 ;
}
static int F_20 ( struct V_27 * V_28 ,
struct V_39 * V_15 )
{
struct V_27 * V_40 ;
struct V_1 * V_2 = V_28 -> V_2 ;
int V_26 = - V_41 ;
F_21 ( V_15 ) ;
V_40 = F_22 ( V_28 , V_42 ) ;
if ( V_40 ) {
V_40 -> V_15 = V_15 ;
V_40 -> V_43 = F_23 ( ( V_44 ) V_2 -> V_30 ) ;
V_26 = F_24 ( V_40 ) ;
if ( F_7 ( V_26 > 0 ) )
V_26 = F_25 ( V_26 ) ;
}
F_26 ( V_15 ) ;
return V_26 ;
}
static void F_27 ( struct V_27 * V_28 )
{
int V_26 ;
struct V_13 * V_23 ;
if ( ! F_19 ( V_28 ) )
return;
F_28 (tmp, &netlink_tap_all, list) {
V_26 = F_20 ( V_28 , V_23 -> V_15 ) ;
if ( F_7 ( V_26 ) )
break;
}
}
static void F_29 ( struct V_27 * V_28 )
{
F_30 () ;
if ( F_7 ( ! F_31 ( & V_20 ) ) )
F_27 ( V_28 ) ;
F_32 () ;
}
static void F_33 ( struct V_1 * V_2 )
{
struct V_45 * V_46 = F_2 ( V_2 ) ;
if ( ! ( V_46 -> V_3 & V_47 ) ) {
if ( ! F_34 ( V_48 , & F_2 ( V_2 ) -> V_49 ) ) {
V_2 -> V_50 = V_51 ;
V_2 -> V_52 ( V_2 ) ;
}
}
F_35 ( & V_2 -> V_53 ) ;
}
static void F_36 ( struct V_1 * V_2 )
{
struct V_45 * V_46 = F_2 ( V_2 ) ;
if ( F_37 ( & V_2 -> V_54 ) )
F_38 ( V_48 , & V_46 -> V_49 ) ;
if ( ! F_39 ( V_48 , & V_46 -> V_49 ) )
F_40 ( & V_46 -> V_55 ) ;
}
static bool F_41 ( const struct V_27 * V_28 )
{
return F_42 ( V_28 ) . V_3 & V_56 ;
}
static bool F_43 ( struct V_1 * V_2 )
{
return F_2 ( V_2 ) -> V_57 . V_58 != NULL ;
}
static bool F_44 ( struct V_1 * V_2 )
{
return F_2 ( V_2 ) -> V_59 . V_58 != NULL ;
}
static void F_45 ( void * * V_58 , unsigned int V_60 , unsigned int V_61 )
{
unsigned int V_62 ;
for ( V_62 = 0 ; V_62 < V_61 ; V_62 ++ ) {
if ( V_58 [ V_62 ] != NULL ) {
if ( F_46 ( V_58 [ V_62 ] ) )
F_47 ( V_58 [ V_62 ] ) ;
else
F_48 ( ( unsigned long ) V_58 [ V_62 ] , V_60 ) ;
}
}
F_49 ( V_58 ) ;
}
static void * F_50 ( unsigned long V_60 )
{
void * V_63 ;
T_2 V_64 = V_65 | V_66 | V_67 |
V_68 | V_69 ;
V_63 = ( void * ) F_51 ( V_64 , V_60 ) ;
if ( V_63 != NULL )
return V_63 ;
V_63 = F_52 ( ( 1 << V_60 ) * V_70 ) ;
if ( V_63 != NULL )
return V_63 ;
V_64 &= ~ V_69 ;
return ( void * ) F_51 ( V_64 , V_60 ) ;
}
static void * * F_53 ( struct V_45 * V_46 ,
struct V_71 * V_72 , unsigned int V_60 )
{
unsigned int V_73 = V_72 -> V_74 ;
unsigned int V_62 ;
void * * V_58 ;
V_58 = F_54 ( V_73 , sizeof( void * ) , V_65 ) ;
if ( V_58 == NULL )
return NULL ;
for ( V_62 = 0 ; V_62 < V_73 ; V_62 ++ ) {
V_58 [ V_62 ] = F_50 ( V_60 ) ;
if ( V_58 [ V_62 ] == NULL )
goto V_75;
}
return V_58 ;
V_75:
F_45 ( V_58 , V_60 , V_73 ) ;
return NULL ;
}
static int F_55 ( struct V_1 * V_2 , struct V_71 * V_72 ,
bool V_76 , bool V_59 )
{
struct V_45 * V_46 = F_2 ( V_2 ) ;
struct V_77 * V_78 ;
struct V_79 * V_80 ;
void * * V_58 = NULL ;
unsigned int V_60 = 0 ;
int V_81 ;
V_78 = V_59 ? & V_46 -> V_59 : & V_46 -> V_57 ;
V_80 = V_59 ? & V_2 -> V_82 : & V_2 -> V_54 ;
if ( ! V_76 ) {
if ( F_56 ( & V_46 -> V_83 ) )
return - V_84 ;
if ( F_56 ( & V_78 -> V_85 ) )
return - V_84 ;
}
if ( V_72 -> V_74 ) {
if ( V_78 -> V_58 != NULL )
return - V_84 ;
if ( ( int ) V_72 -> V_86 <= 0 )
return - V_17 ;
if ( ! F_57 ( V_72 -> V_86 , V_70 ) )
return - V_17 ;
if ( V_72 -> V_87 < V_88 )
return - V_17 ;
if ( ! F_57 ( V_72 -> V_87 , V_89 ) )
return - V_17 ;
V_78 -> V_90 = V_72 -> V_86 /
V_72 -> V_87 ;
if ( V_78 -> V_90 == 0 )
return - V_17 ;
if ( V_78 -> V_90 * V_72 -> V_74 !=
V_72 -> V_91 )
return - V_17 ;
V_60 = F_58 ( V_72 -> V_86 ) ;
V_58 = F_53 ( V_46 , V_72 , V_60 ) ;
if ( V_58 == NULL )
return - V_41 ;
} else {
if ( V_72 -> V_91 )
return - V_17 ;
}
V_81 = - V_84 ;
F_59 ( & V_46 -> V_92 ) ;
if ( V_76 || F_56 ( & V_46 -> V_83 ) == 0 ) {
V_81 = 0 ;
F_60 ( & V_80 -> V_93 ) ;
V_78 -> V_94 = V_72 -> V_91 - 1 ;
V_78 -> V_95 = 0 ;
V_78 -> V_96 = V_72 -> V_87 ;
V_78 -> V_97 = V_72 -> V_86 / V_70 ;
F_61 ( V_78 -> V_98 , V_72 -> V_74 ) ;
F_61 ( V_78 -> V_99 , V_60 ) ;
F_61 ( V_78 -> V_58 , V_58 ) ;
F_62 ( V_80 ) ;
F_63 ( & V_80 -> V_93 ) ;
F_64 ( F_56 ( & V_46 -> V_83 ) ) ;
}
F_65 ( & V_46 -> V_92 ) ;
if ( V_58 )
F_45 ( V_58 , V_60 , V_72 -> V_74 ) ;
return V_81 ;
}
static void F_66 ( struct V_100 * V_101 )
{
struct V_102 * V_102 = V_101 -> V_103 ;
struct V_104 * V_1 = V_102 -> V_105 ;
struct V_1 * V_2 = V_1 -> V_2 ;
if ( V_2 )
F_35 ( & F_2 ( V_2 ) -> V_83 ) ;
}
static void F_67 ( struct V_100 * V_101 )
{
struct V_102 * V_102 = V_101 -> V_103 ;
struct V_104 * V_1 = V_102 -> V_105 ;
struct V_1 * V_2 = V_1 -> V_2 ;
if ( V_2 )
F_68 ( & F_2 ( V_2 ) -> V_83 ) ;
}
static int F_69 ( struct V_102 * V_102 , struct V_104 * V_1 ,
struct V_100 * V_101 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_45 * V_46 = F_2 ( V_2 ) ;
struct V_77 * V_78 ;
unsigned long V_106 , V_107 , V_108 ;
unsigned int V_62 ;
int V_81 = - V_17 ;
if ( V_101 -> V_109 )
return - V_17 ;
F_59 ( & V_46 -> V_92 ) ;
V_108 = 0 ;
for ( V_78 = & V_46 -> V_57 ; V_78 <= & V_46 -> V_59 ; V_78 ++ ) {
if ( V_78 -> V_58 == NULL )
continue;
V_108 += V_78 -> V_98 * V_78 -> V_97 * V_70 ;
}
if ( V_108 == 0 )
goto V_24;
V_107 = V_101 -> V_110 - V_101 -> V_111 ;
if ( V_107 != V_108 )
goto V_24;
V_106 = V_101 -> V_111 ;
for ( V_78 = & V_46 -> V_57 ; V_78 <= & V_46 -> V_59 ; V_78 ++ ) {
if ( V_78 -> V_58 == NULL )
continue;
for ( V_62 = 0 ; V_62 < V_78 -> V_98 ; V_62 ++ ) {
struct V_112 * V_112 ;
void * V_113 = V_78 -> V_58 [ V_62 ] ;
unsigned int V_114 ;
for ( V_114 = 0 ; V_114 < V_78 -> V_97 ; V_114 ++ ) {
V_112 = F_70 ( V_113 ) ;
V_81 = F_71 ( V_101 , V_106 , V_112 ) ;
if ( V_81 < 0 )
goto V_24;
V_106 += V_70 ;
V_113 += V_70 ;
}
}
}
F_35 ( & V_46 -> V_83 ) ;
V_101 -> V_115 = & V_116 ;
V_81 = 0 ;
V_24:
F_65 ( & V_46 -> V_92 ) ;
return V_81 ;
}
static void F_72 ( const struct V_117 * V_118 )
{
#if V_119 == 1
struct V_112 * V_120 , * V_121 ;
V_120 = F_70 ( V_118 + V_70 ) ;
V_121 = F_70 ( ( void * ) V_118 + V_88 + V_118 -> V_122 - 1 ) ;
while ( V_120 <= V_121 ) {
F_73 ( V_120 ) ;
V_120 ++ ;
}
#endif
}
static enum V_123 F_74 ( const struct V_117 * V_118 )
{
F_75 () ;
F_73 ( F_70 ( V_118 ) ) ;
return V_118 -> V_124 ;
}
static void F_76 ( struct V_117 * V_118 ,
enum V_123 V_125 )
{
V_118 -> V_124 = V_125 ;
F_73 ( F_70 ( V_118 ) ) ;
F_77 () ;
}
static struct V_117 *
F_78 ( const struct V_77 * V_78 , unsigned int V_126 )
{
unsigned int V_127 , V_128 ;
V_127 = V_126 / V_78 -> V_90 ;
V_128 = V_126 % V_78 -> V_90 ;
return V_78 -> V_58 [ V_127 ] + ( V_128 * V_78 -> V_96 ) ;
}
static struct V_117 *
F_79 ( const struct V_77 * V_78 , unsigned int V_126 ,
enum V_123 V_125 )
{
struct V_117 * V_118 ;
V_118 = F_78 ( V_78 , V_126 ) ;
if ( F_74 ( V_118 ) != V_125 )
return NULL ;
return V_118 ;
}
static struct V_117 *
F_80 ( const struct V_77 * V_78 ,
enum V_123 V_125 )
{
return F_79 ( V_78 , V_78 -> V_95 , V_125 ) ;
}
static struct V_117 *
F_81 ( const struct V_77 * V_78 ,
enum V_123 V_125 )
{
unsigned int V_129 ;
V_129 = V_78 -> V_95 ? V_78 -> V_95 - 1 : V_78 -> V_94 ;
return F_79 ( V_78 , V_129 , V_125 ) ;
}
static void F_82 ( struct V_77 * V_78 )
{
V_78 -> V_95 = V_78 -> V_95 != V_78 -> V_94 ? V_78 -> V_95 + 1 : 0 ;
}
static void F_83 ( struct V_77 * V_78 )
{
unsigned int V_95 = V_78 -> V_95 , V_126 = V_95 ;
const struct V_117 * V_118 ;
do {
V_118 = F_78 ( V_78 , V_126 ) ;
if ( V_118 -> V_124 == V_130 )
break;
if ( V_118 -> V_124 != V_131 )
break;
F_82 ( V_78 ) ;
} while ( V_78 -> V_95 != V_95 );
}
static bool F_84 ( struct V_45 * V_46 )
{
struct V_77 * V_78 = & V_46 -> V_57 ;
struct V_117 * V_118 ;
unsigned int V_132 ;
V_118 = F_80 ( V_78 , V_130 ) ;
if ( V_118 == NULL )
return false ;
V_132 = V_78 -> V_95 + V_78 -> V_94 / 2 ;
if ( V_132 > V_78 -> V_94 )
V_132 -= V_78 -> V_94 ;
V_118 = F_78 ( V_78 , V_132 ) ;
return V_118 -> V_124 == V_130 ;
}
static unsigned int F_85 ( struct V_102 * V_102 , struct V_104 * V_1 ,
T_3 * V_55 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_45 * V_46 = F_2 ( V_2 ) ;
unsigned int V_12 ;
int V_81 ;
if ( V_46 -> V_57 . V_58 != NULL ) {
while ( V_46 -> V_133 && F_84 ( V_46 ) ) {
V_81 = F_86 ( V_2 ) ;
if ( V_81 < 0 ) {
V_2 -> V_50 = V_81 ;
V_2 -> V_52 ( V_2 ) ;
break;
}
}
F_36 ( V_2 ) ;
}
V_12 = F_87 ( V_102 , V_1 , V_55 ) ;
F_60 ( & V_2 -> V_54 . V_93 ) ;
if ( V_46 -> V_57 . V_58 ) {
F_83 ( & V_46 -> V_57 ) ;
if ( ! F_81 ( & V_46 -> V_57 , V_130 ) )
V_12 |= V_134 | V_135 ;
}
F_63 ( & V_2 -> V_54 . V_93 ) ;
F_60 ( & V_2 -> V_82 . V_93 ) ;
if ( V_46 -> V_59 . V_58 ) {
if ( F_80 ( & V_46 -> V_59 , V_130 ) )
V_12 |= V_136 | V_137 ;
}
F_63 ( & V_2 -> V_82 . V_93 ) ;
return V_12 ;
}
static struct V_117 * F_88 ( struct V_27 * V_28 )
{
return (struct V_117 * ) ( V_28 -> V_95 - V_88 ) ;
}
static void F_89 ( struct V_27 * V_28 , struct V_1 * V_2 ,
struct V_77 * V_78 ,
struct V_117 * V_118 )
{
unsigned int V_107 ;
void * V_138 ;
V_107 = V_78 -> V_96 - V_88 ;
V_138 = ( void * ) V_118 + V_88 ;
V_28 -> V_95 = V_138 ;
V_28 -> V_138 = V_138 ;
F_90 ( V_28 ) ;
V_28 -> V_139 = V_28 -> V_140 + V_107 ;
V_28 -> V_61 = 0 ;
V_28 -> V_141 = V_142 ;
F_42 ( V_28 ) . V_3 |= V_56 ;
F_42 ( V_28 ) . V_2 = V_2 ;
}
static int F_91 ( struct V_1 * V_2 , struct V_143 * V_144 ,
T_1 V_145 , T_1 V_146 ,
struct V_147 * V_148 )
{
struct V_45 * V_46 = F_2 ( V_2 ) ;
struct V_77 * V_78 ;
struct V_117 * V_118 ;
struct V_27 * V_28 ;
unsigned int V_149 ;
bool V_150 = true ;
int V_81 = 0 , V_61 = 0 ;
if ( F_92 ( & V_2 -> V_151 -> V_102 -> V_152 ) > 2 ||
F_56 ( & V_46 -> V_83 ) > 1 )
V_150 = false ;
F_59 ( & V_46 -> V_92 ) ;
V_78 = & V_46 -> V_59 ;
V_149 = V_78 -> V_96 - V_88 ;
do {
V_118 = F_80 ( V_78 , V_153 ) ;
if ( V_118 == NULL ) {
if ( ! ( V_144 -> V_154 & V_155 ) &&
F_56 ( & V_46 -> V_59 . V_85 ) )
F_93 () ;
continue;
}
if ( V_118 -> V_122 > V_149 ) {
V_81 = - V_17 ;
goto V_24;
}
F_72 ( V_118 ) ;
if ( F_94 ( V_145 == 0 && V_146 == 0 && V_150 ) ) {
V_28 = F_95 ( V_65 ) ;
if ( V_28 == NULL ) {
V_81 = - V_51 ;
goto V_24;
}
F_96 ( V_2 ) ;
F_89 ( V_28 , V_2 , V_78 , V_118 ) ;
F_42 ( V_28 ) . V_3 |= V_156 ;
F_97 ( V_28 , V_118 -> V_122 ) ;
F_76 ( V_118 , V_157 ) ;
F_35 ( & V_78 -> V_85 ) ;
} else {
V_28 = F_98 ( V_118 -> V_122 , V_65 ) ;
if ( V_28 == NULL ) {
V_81 = - V_51 ;
goto V_24;
}
F_97 ( V_28 , V_118 -> V_122 ) ;
memcpy ( V_28 -> V_138 , ( void * ) V_118 + V_88 , V_118 -> V_122 ) ;
F_76 ( V_118 , V_130 ) ;
}
F_82 ( V_78 ) ;
F_42 ( V_28 ) . V_9 = V_46 -> V_9 ;
F_42 ( V_28 ) . V_146 = V_146 ;
F_42 ( V_28 ) . V_158 = V_148 -> V_159 -> V_158 ;
V_81 = F_99 ( V_2 , V_28 ) ;
if ( V_81 ) {
F_100 ( V_28 ) ;
goto V_24;
}
if ( F_7 ( V_146 ) ) {
F_35 ( & V_28 -> V_160 ) ;
F_101 ( V_2 , V_28 , V_145 , V_146 ,
V_65 ) ;
}
V_81 = F_102 ( V_2 , V_28 , V_145 ,
V_144 -> V_154 & V_155 ) ;
if ( V_81 < 0 )
goto V_24;
V_61 += V_81 ;
} while ( V_118 != NULL ||
( ! ( V_144 -> V_154 & V_155 ) &&
F_56 ( & V_46 -> V_59 . V_85 ) ) );
if ( V_61 > 0 )
V_81 = V_61 ;
V_24:
F_65 ( & V_46 -> V_92 ) ;
return V_81 ;
}
static void F_103 ( struct V_1 * V_2 , struct V_27 * V_28 )
{
struct V_117 * V_118 ;
V_118 = F_88 ( V_28 ) ;
V_118 -> V_122 = V_28 -> V_61 ;
V_118 -> V_161 = F_42 ( V_28 ) . V_146 ;
V_118 -> V_162 = F_42 ( V_28 ) . V_158 . V_163 ;
V_118 -> V_164 = F_104 ( F_105 ( V_2 ) , F_42 ( V_28 ) . V_158 . V_165 ) ;
V_118 -> V_166 = F_106 ( F_105 ( V_2 ) , F_42 ( V_28 ) . V_158 . V_167 ) ;
F_72 ( V_118 ) ;
F_76 ( V_118 , V_153 ) ;
F_42 ( V_28 ) . V_3 |= V_168 ;
F_100 ( V_28 ) ;
}
static void F_107 ( struct V_1 * V_2 , struct V_27 * V_28 )
{
struct V_45 * V_46 = F_2 ( V_2 ) ;
struct V_77 * V_78 = & V_46 -> V_57 ;
struct V_117 * V_118 ;
F_60 ( & V_2 -> V_54 . V_93 ) ;
V_118 = F_80 ( V_78 , V_130 ) ;
if ( V_118 == NULL ) {
F_63 ( & V_2 -> V_54 . V_93 ) ;
F_100 ( V_28 ) ;
F_33 ( V_2 ) ;
return;
}
F_82 ( V_78 ) ;
F_108 ( & V_2 -> V_54 , V_28 ) ;
F_63 ( & V_2 -> V_54 . V_93 ) ;
V_118 -> V_122 = V_28 -> V_61 ;
V_118 -> V_161 = F_42 ( V_28 ) . V_146 ;
V_118 -> V_162 = F_42 ( V_28 ) . V_158 . V_163 ;
V_118 -> V_164 = F_104 ( F_105 ( V_2 ) , F_42 ( V_28 ) . V_158 . V_165 ) ;
V_118 -> V_166 = F_106 ( F_105 ( V_2 ) , F_42 ( V_28 ) . V_158 . V_167 ) ;
F_76 ( V_118 , V_169 ) ;
}
static void V_142 ( struct V_27 * V_28 )
{
#ifdef F_109
struct V_117 * V_118 ;
struct V_77 * V_78 ;
struct V_1 * V_2 ;
if ( F_41 ( V_28 ) ) {
V_118 = F_88 ( V_28 ) ;
V_2 = F_42 ( V_28 ) . V_2 ;
if ( F_42 ( V_28 ) . V_3 & V_156 ) {
F_76 ( V_118 , V_130 ) ;
V_78 = & F_2 ( V_2 ) -> V_59 ;
} else {
if ( ! ( F_42 ( V_28 ) . V_3 & V_168 ) ) {
V_118 -> V_122 = 0 ;
F_76 ( V_118 , V_153 ) ;
}
V_78 = & F_2 ( V_2 ) -> V_57 ;
}
F_64 ( F_56 ( & V_78 -> V_85 ) == 0 ) ;
F_68 ( & V_78 -> V_85 ) ;
F_110 ( V_2 ) ;
V_28 -> V_95 = NULL ;
}
#endif
if ( F_46 ( V_28 -> V_95 ) ) {
if ( ! V_28 -> V_170 ||
! F_111 ( & ( F_112 ( V_28 ) -> V_171 ) ) )
F_47 ( V_28 -> V_95 ) ;
V_28 -> V_95 = NULL ;
}
if ( V_28 -> V_2 != NULL )
F_113 ( V_28 ) ;
}
static void F_114 ( struct V_27 * V_28 , struct V_1 * V_2 )
{
F_64 ( V_28 -> V_2 != NULL ) ;
V_28 -> V_2 = V_2 ;
V_28 -> V_141 = V_142 ;
F_115 ( V_28 -> V_172 , & V_2 -> V_173 ) ;
F_116 ( V_2 , V_28 -> V_172 ) ;
}
static void F_117 ( struct V_1 * V_2 )
{
struct V_45 * V_46 = F_2 ( V_2 ) ;
if ( V_46 -> V_133 ) {
if ( V_46 -> V_174 . V_175 )
V_46 -> V_174 . V_175 ( & V_46 -> V_174 ) ;
F_16 ( V_46 -> V_174 . V_21 ) ;
F_100 ( V_46 -> V_174 . V_28 ) ;
}
F_118 ( & V_2 -> V_54 ) ;
#ifdef F_109
if ( 1 ) {
struct V_71 V_72 ;
memset ( & V_72 , 0 , sizeof( V_72 ) ) ;
if ( V_46 -> V_57 . V_58 )
F_55 ( V_2 , & V_72 , true , false ) ;
memset ( & V_72 , 0 , sizeof( V_72 ) ) ;
if ( V_46 -> V_59 . V_58 )
F_55 ( V_2 , & V_72 , true , true ) ;
}
#endif
if ( ! F_119 ( V_2 , V_176 ) ) {
F_120 ( V_177 L_2 , V_2 ) ;
return;
}
F_64 ( F_56 ( & V_2 -> V_173 ) ) ;
F_64 ( F_56 ( & V_2 -> V_178 ) ) ;
F_64 ( F_2 ( V_2 ) -> V_179 ) ;
}
void F_121 ( void )
__acquires( T_4 )
{
F_122 () ;
F_123 ( & T_4 ) ;
if ( F_56 ( & V_180 ) ) {
F_124 ( V_55 , V_181 ) ;
F_125 ( & V_182 , & V_55 ) ;
for (; ; ) {
F_126 ( V_183 ) ;
if ( F_56 ( & V_180 ) == 0 )
break;
F_127 ( & T_4 ) ;
F_93 () ;
F_123 ( & T_4 ) ;
}
F_128 ( V_184 ) ;
F_129 ( & V_182 , & V_55 ) ;
}
}
void F_130 ( void )
__releases( T_4 )
{
F_127 ( & T_4 ) ;
F_131 ( & V_182 ) ;
}
static inline void
F_132 ( void )
{
F_133 ( & T_4 ) ;
F_35 ( & V_180 ) ;
F_134 ( & T_4 ) ;
}
static inline void
F_135 ( void )
{
if ( F_136 ( & V_180 ) )
F_131 ( & V_182 ) ;
}
static bool F_137 ( struct V_185 * V_185 , struct V_1 * V_2 )
{
return F_138 ( F_139 ( V_2 ) , V_185 ) ;
}
static struct V_1 * F_140 ( struct V_185 * V_185 , int V_43 , T_1 V_9 )
{
struct V_186 * V_10 = & V_187 [ V_43 ] ;
struct V_7 * V_8 = & V_10 -> V_8 ;
struct V_6 * V_95 ;
struct V_1 * V_2 ;
F_133 ( & T_4 ) ;
V_95 = F_4 ( V_8 , V_9 ) ;
F_141 (sk, head) {
if ( V_10 -> V_188 ( V_185 , V_2 ) &&
( F_2 ( V_2 ) -> V_9 == V_9 ) ) {
F_96 ( V_2 ) ;
goto V_22;
}
}
V_2 = NULL ;
V_22:
F_134 ( & T_4 ) ;
return V_2 ;
}
static struct V_6 * F_142 ( T_5 V_107 )
{
if ( V_107 <= V_70 )
return F_143 ( V_107 , V_42 ) ;
else
return (struct V_6 * )
F_51 ( V_42 | V_67 ,
F_58 ( V_107 ) ) ;
}
static void F_144 ( struct V_6 * V_10 , T_5 V_107 )
{
if ( V_107 <= V_70 )
F_49 ( V_10 ) ;
else
F_48 ( ( unsigned long ) V_10 , F_58 ( V_107 ) ) ;
}
static int F_145 ( struct V_7 * V_8 , int V_189 )
{
unsigned int V_190 , V_12 , V_191 ;
T_5 V_192 , V_107 ;
struct V_6 * V_193 , * V_10 ;
int V_62 ;
V_190 = V_12 = V_8 -> V_12 ;
V_192 = V_107 = ( V_12 + 1 ) * sizeof( * V_10 ) ;
V_191 = V_8 -> V_191 ;
if ( V_189 ) {
if ( ++ V_191 > V_8 -> V_194 )
return 0 ;
V_12 = V_12 * 2 + 1 ;
V_107 *= 2 ;
}
V_10 = F_142 ( V_107 ) ;
if ( ! V_10 )
return 0 ;
V_193 = V_8 -> V_10 ;
V_8 -> V_10 = V_10 ;
V_8 -> V_12 = V_12 ;
V_8 -> V_191 = V_191 ;
F_146 ( & V_8 -> V_11 , sizeof( V_8 -> V_11 ) ) ;
for ( V_62 = 0 ; V_62 <= V_190 ; V_62 ++ ) {
struct V_1 * V_2 ;
struct V_195 * V_23 ;
F_147 (sk, tmp, &otable[i])
F_148 ( V_2 , F_4 ( V_8 , F_2 ( V_2 ) -> V_9 ) ) ;
}
F_144 ( V_193 , V_192 ) ;
V_8 -> V_196 = V_197 + 10 * 60 * V_198 ;
return 1 ;
}
static inline int F_149 ( struct V_7 * V_8 , int V_61 )
{
int V_199 = V_8 -> V_200 >> V_8 -> V_191 ;
if ( F_7 ( V_199 > 1 ) && F_145 ( V_8 , 1 ) )
return 1 ;
if ( F_7 ( V_61 > V_199 ) && F_150 ( V_197 , V_8 -> V_196 ) ) {
F_145 ( V_8 , 0 ) ;
return 1 ;
}
return 0 ;
}
static void
F_151 ( struct V_1 * V_2 )
{
struct V_186 * V_201 = & V_187 [ V_2 -> V_30 ] ;
unsigned long V_12 ;
unsigned int V_62 ;
struct V_202 * V_202 ;
V_202 = F_152 ( V_201 -> V_202 ) ;
if ( ! V_202 )
return;
for ( V_62 = 0 ; V_62 < F_153 ( V_201 -> V_179 ) ; V_62 ++ ) {
V_12 = 0 ;
F_154 (sk, &tbl->mc_list) {
if ( V_62 < F_153 ( F_2 ( V_2 ) -> V_203 ) )
V_12 |= F_2 ( V_2 ) -> V_179 [ V_62 ] ;
}
V_202 -> V_204 [ V_62 ] = V_12 ;
}
}
static int F_155 ( struct V_1 * V_2 , struct V_185 * V_185 , T_1 V_9 )
{
struct V_186 * V_10 = & V_187 [ V_2 -> V_30 ] ;
struct V_7 * V_8 = & V_10 -> V_8 ;
struct V_6 * V_95 ;
int V_81 = - V_205 ;
struct V_1 * V_206 ;
int V_61 ;
F_121 () ;
V_95 = F_4 ( V_8 , V_9 ) ;
V_61 = 0 ;
F_141 (osk, head) {
if ( V_10 -> V_188 ( V_185 , V_206 ) &&
( F_2 ( V_206 ) -> V_9 == V_9 ) )
break;
V_61 ++ ;
}
if ( V_206 )
goto V_81;
V_81 = - V_84 ;
if ( F_2 ( V_2 ) -> V_9 )
goto V_81;
V_81 = - V_41 ;
if ( V_207 > 32 && F_7 ( V_8 -> V_200 >= V_208 ) )
goto V_81;
if ( V_61 && F_149 ( V_8 , V_61 ) )
V_95 = F_4 ( V_8 , V_9 ) ;
V_8 -> V_200 ++ ;
F_2 ( V_2 ) -> V_9 = V_9 ;
F_156 ( V_2 , V_95 ) ;
V_81 = 0 ;
V_81:
F_130 () ;
return V_81 ;
}
static void F_157 ( struct V_1 * V_2 )
{
F_121 () ;
if ( F_158 ( V_2 ) )
V_187 [ V_2 -> V_30 ] . V_8 . V_200 -- ;
if ( F_2 ( V_2 ) -> V_209 )
F_159 ( V_2 ) ;
F_130 () ;
}
static int F_160 ( struct V_185 * V_185 , struct V_104 * V_1 ,
struct V_210 * V_211 , int V_43 )
{
struct V_1 * V_2 ;
struct V_45 * V_46 ;
V_1 -> V_212 = & V_213 ;
V_2 = F_161 ( V_185 , V_214 , V_65 , & V_215 ) ;
if ( ! V_2 )
return - V_41 ;
F_162 ( V_1 , V_2 ) ;
V_46 = F_2 ( V_2 ) ;
if ( V_211 ) {
V_46 -> V_211 = V_211 ;
} else {
V_46 -> V_211 = & V_46 -> V_216 ;
F_163 ( V_46 -> V_211 ) ;
}
F_164 ( & V_46 -> V_55 ) ;
#ifdef F_109
F_163 ( & V_46 -> V_92 ) ;
#endif
V_2 -> V_217 = F_117 ;
V_2 -> V_30 = V_43 ;
return 0 ;
}
static int F_165 ( struct V_185 * V_185 , struct V_104 * V_1 , int V_43 ,
int V_218 )
{
struct V_21 * V_21 = NULL ;
struct V_210 * V_211 ;
struct V_45 * V_46 ;
void (* F_166)( int V_5 );
int V_81 = 0 ;
V_1 -> V_49 = V_219 ;
if ( V_1 -> type != V_220 && V_1 -> type != V_221 )
return - V_222 ;
if ( V_43 < 0 || V_43 >= V_223 )
return - V_224 ;
F_132 () ;
#ifdef F_167
if ( ! V_187 [ V_43 ] . V_225 ) {
F_135 () ;
F_168 ( L_3 , V_214 , V_43 ) ;
F_132 () ;
}
#endif
if ( V_187 [ V_43 ] . V_225 &&
F_169 ( V_187 [ V_43 ] . V_21 ) )
V_21 = V_187 [ V_43 ] . V_21 ;
else
V_81 = - V_224 ;
V_211 = V_187 [ V_43 ] . V_211 ;
F_166 = V_187 [ V_43 ] . F_166 ;
F_135 () ;
if ( V_81 < 0 )
goto V_24;
V_81 = F_160 ( V_185 , V_1 , V_211 , V_43 ) ;
if ( V_81 < 0 )
goto V_226;
F_170 () ;
F_171 ( V_185 , & V_215 , 1 ) ;
F_172 () ;
V_46 = F_2 ( V_1 -> V_2 ) ;
V_46 -> V_21 = V_21 ;
V_46 -> V_227 = F_166 ;
V_24:
return V_81 ;
V_226:
F_16 ( V_21 ) ;
goto V_24;
}
static int F_173 ( struct V_104 * V_1 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_45 * V_46 ;
if ( ! V_2 )
return 0 ;
F_157 ( V_2 ) ;
F_174 ( V_2 ) ;
V_46 = F_2 ( V_2 ) ;
V_1 -> V_2 = NULL ;
F_175 ( & V_46 -> V_55 ) ;
F_118 ( & V_2 -> V_82 ) ;
if ( V_46 -> V_9 ) {
struct V_228 V_132 = {
. V_185 = F_139 ( V_2 ) ,
. V_43 = V_2 -> V_30 ,
. V_9 = V_46 -> V_9 ,
} ;
F_176 ( & V_229 ,
V_230 , & V_132 ) ;
}
F_16 ( V_46 -> V_21 ) ;
F_121 () ;
if ( F_1 ( V_2 ) ) {
F_177 ( V_187 [ V_2 -> V_30 ] . V_225 == 0 ) ;
if ( -- V_187 [ V_2 -> V_30 ] . V_225 == 0 ) {
struct V_202 * V_231 ;
V_231 = F_152 ( V_187 [ V_2 -> V_30 ] . V_202 ) ;
F_178 ( V_187 [ V_2 -> V_30 ] . V_202 , NULL ) ;
F_179 ( V_231 , V_232 ) ;
V_187 [ V_2 -> V_30 ] . V_21 = NULL ;
V_187 [ V_2 -> V_30 ] . F_166 = NULL ;
V_187 [ V_2 -> V_30 ] . V_3 = 0 ;
V_187 [ V_2 -> V_30 ] . V_225 = 0 ;
}
} else if ( V_46 -> V_209 ) {
F_151 ( V_2 ) ;
}
F_130 () ;
F_49 ( V_46 -> V_179 ) ;
V_46 -> V_179 = NULL ;
F_170 () ;
F_171 ( F_139 ( V_2 ) , & V_215 , - 1 ) ;
F_172 () ;
F_110 ( V_2 ) ;
return 0 ;
}
static int F_180 ( struct V_104 * V_1 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_185 * V_185 = F_139 ( V_2 ) ;
struct V_186 * V_10 = & V_187 [ V_2 -> V_30 ] ;
struct V_7 * V_8 = & V_10 -> V_8 ;
struct V_6 * V_95 ;
struct V_1 * V_206 ;
T_6 V_9 = F_181 ( V_181 ) ;
int V_81 ;
static T_6 V_233 = - 4097 ;
V_234:
F_182 () ;
F_121 () ;
V_95 = F_4 ( V_8 , V_9 ) ;
F_141 (osk, head) {
if ( ! V_10 -> V_188 ( V_185 , V_206 ) )
continue;
if ( F_2 ( V_206 ) -> V_9 == V_9 ) {
V_9 = V_233 -- ;
if ( V_233 > - 4097 )
V_233 = - 4097 ;
F_130 () ;
goto V_234;
}
}
F_130 () ;
V_81 = F_155 ( V_2 , V_185 , V_9 ) ;
if ( V_81 == - V_205 )
goto V_234;
if ( V_81 == - V_84 )
V_81 = 0 ;
return V_81 ;
}
static inline int F_183 ( const struct V_104 * V_1 , unsigned int V_235 )
{
return ( V_187 [ V_1 -> V_2 -> V_30 ] . V_3 & V_235 ) ||
F_184 ( F_139 ( V_1 -> V_2 ) -> V_236 , V_237 ) ;
}
static void
F_185 ( struct V_1 * V_2 , unsigned int V_209 )
{
struct V_45 * V_46 = F_2 ( V_2 ) ;
if ( V_46 -> V_209 && ! V_209 )
F_159 ( V_2 ) ;
else if ( ! V_46 -> V_209 && V_209 )
F_186 ( V_2 , & V_187 [ V_2 -> V_30 ] . V_238 ) ;
V_46 -> V_209 = V_209 ;
}
static int F_187 ( struct V_1 * V_2 )
{
struct V_45 * V_46 = F_2 ( V_2 ) ;
unsigned int V_179 ;
unsigned long * V_239 ;
int V_81 = 0 ;
F_121 () ;
V_179 = V_187 [ V_2 -> V_30 ] . V_179 ;
if ( ! V_187 [ V_2 -> V_30 ] . V_225 ) {
V_81 = - V_240 ;
goto V_241;
}
if ( V_46 -> V_203 >= V_179 )
goto V_241;
V_239 = F_188 ( V_46 -> V_179 , F_189 ( V_179 ) , V_42 ) ;
if ( V_239 == NULL ) {
V_81 = - V_41 ;
goto V_241;
}
memset ( ( char * ) V_239 + F_189 ( V_46 -> V_203 ) , 0 ,
F_189 ( V_179 ) - F_189 ( V_46 -> V_203 ) ) ;
V_46 -> V_179 = V_239 ;
V_46 -> V_203 = V_179 ;
V_241:
F_130 () ;
return V_81 ;
}
static int V_227 ( struct V_104 * V_1 , struct V_242 * V_243 ,
int V_244 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_185 * V_185 = F_139 ( V_2 ) ;
struct V_45 * V_46 = F_2 ( V_2 ) ;
struct V_245 * V_246 = (struct V_245 * ) V_243 ;
int V_81 ;
if ( V_244 < sizeof( struct V_245 ) )
return - V_17 ;
if ( V_246 -> V_247 != V_248 )
return - V_17 ;
if ( V_246 -> V_249 ) {
if ( ! F_183 ( V_1 , V_250 ) )
return - V_251 ;
V_81 = F_187 ( V_2 ) ;
if ( V_81 )
return V_81 ;
}
if ( V_46 -> V_9 ) {
if ( V_246 -> V_252 != V_46 -> V_9 )
return - V_17 ;
} else {
V_81 = V_246 -> V_252 ?
F_155 ( V_2 , V_185 , V_246 -> V_252 ) :
F_180 ( V_1 ) ;
if ( V_81 )
return V_81 ;
}
if ( ! V_246 -> V_249 && ( V_46 -> V_179 == NULL || ! ( T_1 ) V_46 -> V_179 [ 0 ] ) )
return 0 ;
F_121 () ;
F_185 ( V_2 , V_46 -> V_209 +
F_190 ( V_246 -> V_249 ) -
F_190 ( V_46 -> V_179 [ 0 ] ) ) ;
V_46 -> V_179 [ 0 ] = ( V_46 -> V_179 [ 0 ] & ~ 0xffffffffUL ) | V_246 -> V_249 ;
F_151 ( V_2 ) ;
F_130 () ;
if ( V_46 -> V_227 && V_46 -> V_179 [ 0 ] ) {
int V_62 ;
for ( V_62 = 0 ; V_62 < V_46 -> V_203 ; V_62 ++ ) {
if ( F_39 ( V_62 , V_46 -> V_179 ) )
V_46 -> V_227 ( V_62 ) ;
}
}
return 0 ;
}
static int F_191 ( struct V_104 * V_1 , struct V_242 * V_243 ,
int V_253 , int V_3 )
{
int V_81 = 0 ;
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_45 * V_46 = F_2 ( V_2 ) ;
struct V_245 * V_246 = (struct V_245 * ) V_243 ;
if ( V_253 < sizeof( V_243 -> V_254 ) )
return - V_17 ;
if ( V_243 -> V_254 == V_255 ) {
V_2 -> V_256 = V_257 ;
V_46 -> V_145 = 0 ;
V_46 -> V_146 = 0 ;
return 0 ;
}
if ( V_243 -> V_254 != V_248 )
return - V_17 ;
if ( V_246 -> V_249 && ! F_183 ( V_1 , V_258 ) )
return - V_251 ;
if ( ! V_46 -> V_9 )
V_81 = F_180 ( V_1 ) ;
if ( V_81 == 0 ) {
V_2 -> V_256 = V_259 ;
V_46 -> V_145 = V_246 -> V_252 ;
V_46 -> V_146 = F_192 ( V_246 -> V_249 ) ;
}
return V_81 ;
}
static int F_193 ( struct V_104 * V_1 , struct V_242 * V_243 ,
int * V_244 , int V_260 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_45 * V_46 = F_2 ( V_2 ) ;
F_194 ( struct V_245 * , V_246 , V_243 ) ;
V_246 -> V_247 = V_248 ;
V_246 -> V_261 = 0 ;
* V_244 = sizeof( * V_246 ) ;
if ( V_260 ) {
V_246 -> V_252 = V_46 -> V_145 ;
V_246 -> V_249 = F_3 ( V_46 -> V_146 ) ;
} else {
V_246 -> V_252 = V_46 -> V_9 ;
V_246 -> V_249 = V_46 -> V_179 ? V_46 -> V_179 [ 0 ] : 0 ;
}
return 0 ;
}
static struct V_1 * F_195 ( struct V_1 * V_262 , T_1 V_9 )
{
struct V_1 * V_1 ;
struct V_45 * V_46 ;
V_1 = F_140 ( F_139 ( V_262 ) , V_262 -> V_30 , V_9 ) ;
if ( ! V_1 )
return F_196 ( - V_263 ) ;
V_46 = F_2 ( V_1 ) ;
if ( V_1 -> V_256 == V_259 &&
V_46 -> V_145 != F_2 ( V_262 ) -> V_9 ) {
F_110 ( V_1 ) ;
return F_196 ( - V_263 ) ;
}
return V_1 ;
}
struct V_1 * F_197 ( struct V_102 * V_264 )
{
struct V_265 * V_265 = F_198 ( V_264 ) ;
struct V_1 * V_1 ;
if ( ! F_199 ( V_265 -> V_266 ) )
return F_196 ( - V_267 ) ;
V_1 = F_200 ( V_265 ) -> V_2 ;
if ( V_1 -> V_268 != V_248 )
return F_196 ( - V_17 ) ;
F_96 ( V_1 ) ;
return V_1 ;
}
static struct V_27 * F_201 ( unsigned int V_107 ,
int V_269 )
{
struct V_27 * V_28 ;
void * V_138 ;
if ( V_107 <= V_270 || V_269 )
return F_98 ( V_107 , V_65 ) ;
V_107 = F_202 ( V_107 ) +
F_202 ( sizeof( struct V_271 ) ) ;
V_138 = F_203 ( V_107 ) ;
if ( V_138 == NULL )
return NULL ;
V_28 = F_204 ( V_138 , V_107 ) ;
if ( V_28 == NULL )
F_47 ( V_138 ) ;
else {
V_28 -> V_272 = 0 ;
V_28 -> V_141 = V_142 ;
}
return V_28 ;
}
int F_205 ( struct V_1 * V_2 , struct V_27 * V_28 ,
long * V_273 , struct V_1 * V_262 )
{
struct V_45 * V_46 ;
V_46 = F_2 ( V_2 ) ;
if ( ( F_56 ( & V_2 -> V_173 ) > V_2 -> V_274 ||
F_39 ( V_48 , & V_46 -> V_49 ) ) &&
! F_41 ( V_28 ) ) {
F_124 ( V_55 , V_181 ) ;
if ( ! * V_273 ) {
if ( ! V_262 || F_1 ( V_262 ) )
F_33 ( V_2 ) ;
F_110 ( V_2 ) ;
F_100 ( V_28 ) ;
return - V_275 ;
}
F_128 ( V_276 ) ;
F_206 ( & V_46 -> V_55 , & V_55 ) ;
if ( ( F_56 ( & V_2 -> V_173 ) > V_2 -> V_274 ||
F_39 ( V_48 , & V_46 -> V_49 ) ) &&
! F_119 ( V_2 , V_176 ) )
* V_273 = F_207 ( * V_273 ) ;
F_128 ( V_184 ) ;
F_129 ( & V_46 -> V_55 , & V_55 ) ;
F_110 ( V_2 ) ;
if ( F_208 ( V_181 ) ) {
F_100 ( V_28 ) ;
return F_209 ( * V_273 ) ;
}
return 1 ;
}
F_114 ( V_28 , V_2 ) ;
return 0 ;
}
static int F_210 ( struct V_1 * V_2 , struct V_27 * V_28 )
{
int V_61 = V_28 -> V_61 ;
F_29 ( V_28 ) ;
#ifdef F_109
if ( F_41 ( V_28 ) )
F_103 ( V_2 , V_28 ) ;
else if ( F_43 ( V_2 ) )
F_107 ( V_2 , V_28 ) ;
else
#endif
F_211 ( & V_2 -> V_54 , V_28 ) ;
V_2 -> V_277 ( V_2 , V_61 ) ;
return V_61 ;
}
int F_212 ( struct V_1 * V_2 , struct V_27 * V_28 )
{
int V_61 = F_210 ( V_2 , V_28 ) ;
F_110 ( V_2 ) ;
return V_61 ;
}
void F_213 ( struct V_1 * V_2 , struct V_27 * V_28 )
{
F_100 ( V_28 ) ;
F_110 ( V_2 ) ;
}
static struct V_27 * F_214 ( struct V_27 * V_28 , T_2 V_278 )
{
int V_279 ;
F_64 ( V_28 -> V_2 != NULL ) ;
if ( F_41 ( V_28 ) )
return V_28 ;
V_279 = V_28 -> V_139 - V_28 -> V_140 ;
if ( F_46 ( V_28 -> V_95 ) || V_279 * 2 < V_28 -> V_172 )
return V_28 ;
if ( F_215 ( V_28 ) ) {
struct V_27 * V_40 = F_22 ( V_28 , V_278 ) ;
if ( ! V_40 )
return V_28 ;
F_216 ( V_28 ) ;
V_28 = V_40 ;
}
if ( ! F_217 ( V_28 , 0 , - V_279 , V_278 ) )
V_28 -> V_172 -= V_279 ;
return V_28 ;
}
static int F_218 ( struct V_1 * V_2 , struct V_27 * V_28 ,
struct V_1 * V_262 )
{
int V_26 ;
struct V_45 * V_46 = F_2 ( V_2 ) ;
V_26 = - V_263 ;
if ( V_46 -> V_280 != NULL ) {
V_26 = V_28 -> V_61 ;
F_114 ( V_28 , V_2 ) ;
F_42 ( V_28 ) . V_2 = V_262 ;
V_46 -> V_280 ( V_28 ) ;
F_216 ( V_28 ) ;
} else {
F_100 ( V_28 ) ;
}
F_110 ( V_2 ) ;
return V_26 ;
}
int F_102 ( struct V_1 * V_262 , struct V_27 * V_28 ,
T_1 V_9 , int V_281 )
{
struct V_1 * V_2 ;
int V_81 ;
long V_273 ;
V_28 = F_214 ( V_28 , F_219 () ) ;
V_273 = F_220 ( V_262 , V_281 ) ;
V_234:
V_2 = F_195 ( V_262 , V_9 ) ;
if ( F_221 ( V_2 ) ) {
F_100 ( V_28 ) ;
return F_222 ( V_2 ) ;
}
if ( F_1 ( V_2 ) )
return F_218 ( V_2 , V_28 , V_262 ) ;
if ( F_223 ( V_2 , V_28 ) ) {
V_81 = V_28 -> V_61 ;
F_100 ( V_28 ) ;
F_110 ( V_2 ) ;
return V_81 ;
}
V_81 = F_205 ( V_2 , V_28 , & V_273 , V_262 ) ;
if ( V_81 == 1 )
goto V_234;
if ( V_81 )
return V_81 ;
return F_212 ( V_2 , V_28 ) ;
}
struct V_27 * F_224 ( struct V_1 * V_262 , unsigned int V_107 ,
T_1 V_145 , T_2 V_282 )
{
#ifdef F_109
struct V_1 * V_2 = NULL ;
struct V_27 * V_28 ;
struct V_77 * V_78 ;
struct V_117 * V_118 ;
unsigned int V_149 ;
V_2 = F_195 ( V_262 , V_145 ) ;
if ( F_221 ( V_2 ) )
goto V_24;
V_78 = & F_2 ( V_2 ) -> V_57 ;
if ( V_78 -> V_58 == NULL )
goto V_283;
V_28 = F_95 ( V_282 ) ;
if ( V_28 == NULL )
goto V_75;
F_60 ( & V_2 -> V_54 . V_93 ) ;
if ( V_78 -> V_58 == NULL )
goto V_284;
V_149 = V_78 -> V_96 - V_88 ;
if ( V_149 < V_107 )
goto V_284;
F_83 ( V_78 ) ;
V_118 = F_80 ( V_78 , V_130 ) ;
if ( V_118 == NULL )
goto V_285;
F_89 ( V_28 , V_2 , V_78 , V_118 ) ;
F_76 ( V_118 , V_157 ) ;
F_35 ( & V_78 -> V_85 ) ;
F_82 ( V_78 ) ;
F_63 ( & V_2 -> V_54 . V_93 ) ;
return V_28 ;
V_285:
F_100 ( V_28 ) ;
F_63 ( & V_2 -> V_54 . V_93 ) ;
F_33 ( V_2 ) ;
V_75:
F_110 ( V_2 ) ;
return NULL ;
V_284:
F_100 ( V_28 ) ;
F_63 ( & V_2 -> V_54 . V_93 ) ;
V_283:
F_110 ( V_2 ) ;
V_24:
#endif
return F_98 ( V_107 , V_282 ) ;
}
int F_225 ( struct V_1 * V_2 , unsigned int V_5 )
{
int V_286 = 0 ;
struct V_202 * V_202 ;
F_177 ( ! F_1 ( V_2 ) ) ;
F_30 () ;
V_202 = F_226 ( V_187 [ V_2 -> V_30 ] . V_202 ) ;
if ( V_202 && V_5 - 1 < V_187 [ V_2 -> V_30 ] . V_179 )
V_286 = F_39 ( V_5 - 1 , V_202 -> V_204 ) ;
F_32 () ;
return V_286 ;
}
static int F_227 ( struct V_1 * V_2 , struct V_27 * V_28 )
{
struct V_45 * V_46 = F_2 ( V_2 ) ;
if ( F_56 ( & V_2 -> V_173 ) <= V_2 -> V_274 &&
! F_39 ( V_48 , & V_46 -> V_49 ) ) {
F_114 ( V_28 , V_2 ) ;
F_210 ( V_2 , V_28 ) ;
return F_56 ( & V_2 -> V_173 ) > ( V_2 -> V_274 >> 1 ) ;
}
return - 1 ;
}
static int F_228 ( struct V_1 * V_2 ,
struct V_287 * V_288 )
{
struct V_45 * V_46 = F_2 ( V_2 ) ;
int V_289 ;
if ( V_288 -> V_290 == V_2 )
goto V_24;
if ( V_46 -> V_9 == V_288 -> V_9 || V_288 -> V_5 - 1 >= V_46 -> V_203 ||
! F_39 ( V_288 -> V_5 - 1 , V_46 -> V_179 ) )
goto V_24;
if ( ! F_138 ( F_139 ( V_2 ) , V_288 -> V_185 ) )
goto V_24;
if ( V_288 -> V_291 ) {
F_33 ( V_2 ) ;
goto V_24;
}
F_96 ( V_2 ) ;
if ( V_288 -> V_292 == NULL ) {
if ( F_215 ( V_288 -> V_28 ) ) {
V_288 -> V_292 = F_22 ( V_288 -> V_28 , V_288 -> V_278 ) ;
} else {
V_288 -> V_292 = F_229 ( V_288 -> V_28 ) ;
F_230 ( V_288 -> V_292 ) ;
}
}
if ( V_288 -> V_292 == NULL ) {
F_33 ( V_2 ) ;
V_288 -> V_291 = 1 ;
if ( V_46 -> V_3 & V_293 )
V_288 -> V_294 = 1 ;
} else if ( V_288 -> V_295 && V_288 -> V_295 ( V_2 , V_288 -> V_292 , V_288 -> V_296 ) ) {
F_100 ( V_288 -> V_292 ) ;
V_288 -> V_292 = NULL ;
} else if ( F_223 ( V_2 , V_288 -> V_292 ) ) {
F_100 ( V_288 -> V_292 ) ;
V_288 -> V_292 = NULL ;
} else if ( ( V_289 = F_227 ( V_2 , V_288 -> V_292 ) ) < 0 ) {
F_33 ( V_2 ) ;
if ( V_46 -> V_3 & V_293 )
V_288 -> V_294 = 1 ;
} else {
V_288 -> V_297 |= V_289 ;
V_288 -> V_298 = 1 ;
V_288 -> V_292 = NULL ;
}
F_110 ( V_2 ) ;
V_24:
return 0 ;
}
int F_231 ( struct V_1 * V_262 , struct V_27 * V_28 , T_1 V_9 ,
T_1 V_5 , T_2 V_278 ,
int (* F_232)( struct V_1 * V_299 , struct V_27 * V_28 , void * V_138 ) ,
void * V_300 )
{
struct V_185 * V_185 = F_139 ( V_262 ) ;
struct V_287 V_301 ;
struct V_1 * V_2 ;
V_28 = F_214 ( V_28 , V_278 ) ;
V_301 . V_290 = V_262 ;
V_301 . V_185 = V_185 ;
V_301 . V_9 = V_9 ;
V_301 . V_5 = V_5 ;
V_301 . V_291 = 0 ;
V_301 . V_294 = 0 ;
V_301 . V_297 = 0 ;
V_301 . V_298 = 0 ;
V_301 . V_278 = V_278 ;
V_301 . V_28 = V_28 ;
V_301 . V_292 = NULL ;
V_301 . V_295 = F_232 ;
V_301 . V_296 = V_300 ;
F_132 () ;
F_154 (sk, &nl_table[ssk->sk_protocol].mc_list)
F_228 ( V_2 , & V_301 ) ;
F_216 ( V_28 ) ;
F_135 () ;
if ( V_301 . V_294 ) {
F_100 ( V_301 . V_292 ) ;
return - V_51 ;
}
F_216 ( V_301 . V_292 ) ;
if ( V_301 . V_298 ) {
if ( V_301 . V_297 && ( V_278 & V_302 ) )
F_233 () ;
return 0 ;
}
return - V_303 ;
}
int F_101 ( struct V_1 * V_262 , struct V_27 * V_28 , T_1 V_9 ,
T_1 V_5 , T_2 V_278 )
{
return F_231 ( V_262 , V_28 , V_9 , V_5 , V_278 ,
NULL , NULL ) ;
}
static int F_234 ( struct V_1 * V_2 , struct V_304 * V_288 )
{
struct V_45 * V_46 = F_2 ( V_2 ) ;
int V_26 = 0 ;
if ( V_2 == V_288 -> V_290 )
goto V_24;
if ( ! F_138 ( F_139 ( V_2 ) , F_139 ( V_288 -> V_290 ) ) )
goto V_24;
if ( V_46 -> V_9 == V_288 -> V_9 || V_288 -> V_5 - 1 >= V_46 -> V_203 ||
! F_39 ( V_288 -> V_5 - 1 , V_46 -> V_179 ) )
goto V_24;
if ( V_288 -> V_305 == V_51 && V_46 -> V_3 & V_47 ) {
V_26 = 1 ;
goto V_24;
}
V_2 -> V_50 = V_288 -> V_305 ;
V_2 -> V_52 ( V_2 ) ;
V_24:
return V_26 ;
}
int F_235 ( struct V_1 * V_262 , T_1 V_9 , T_1 V_5 , int V_305 )
{
struct V_304 V_301 ;
struct V_1 * V_2 ;
int V_26 = 0 ;
V_301 . V_290 = V_262 ;
V_301 . V_9 = V_9 ;
V_301 . V_5 = V_5 ;
V_301 . V_305 = - V_305 ;
F_133 ( & T_4 ) ;
F_154 (sk, &nl_table[ssk->sk_protocol].mc_list)
V_26 += F_234 ( V_2 , & V_301 ) ;
F_134 ( & T_4 ) ;
return V_26 ;
}
static void F_236 ( struct V_45 * V_46 ,
unsigned int V_5 ,
int V_306 )
{
int V_231 , V_307 = ! ! V_306 , V_209 ;
V_231 = F_39 ( V_5 - 1 , V_46 -> V_179 ) ;
V_209 = V_46 -> V_209 - V_231 + V_307 ;
if ( V_307 )
F_237 ( V_5 - 1 , V_46 -> V_179 ) ;
else
F_238 ( V_5 - 1 , V_46 -> V_179 ) ;
F_185 ( & V_46 -> V_2 , V_209 ) ;
F_151 ( & V_46 -> V_2 ) ;
}
static int F_239 ( struct V_104 * V_1 , int V_308 , int V_309 ,
char T_7 * V_310 , unsigned int V_311 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_45 * V_46 = F_2 ( V_2 ) ;
unsigned int V_289 = 0 ;
int V_81 ;
if ( V_308 != V_312 )
return - V_313 ;
if ( V_309 != V_314 && V_309 != V_315 &&
V_311 >= sizeof( int ) &&
F_240 ( V_289 , ( unsigned int T_7 * ) V_310 ) )
return - V_316 ;
switch ( V_309 ) {
case V_317 :
if ( V_289 )
V_46 -> V_3 |= V_318 ;
else
V_46 -> V_3 &= ~ V_318 ;
V_81 = 0 ;
break;
case V_319 :
case V_320 : {
if ( ! F_183 ( V_1 , V_250 ) )
return - V_251 ;
V_81 = F_187 ( V_2 ) ;
if ( V_81 )
return V_81 ;
if ( ! V_289 || V_289 - 1 >= V_46 -> V_203 )
return - V_17 ;
F_121 () ;
F_236 ( V_46 , V_289 ,
V_309 == V_319 ) ;
F_130 () ;
if ( V_46 -> V_227 )
V_46 -> V_227 ( V_289 ) ;
V_81 = 0 ;
break;
}
case V_321 :
if ( V_289 )
V_46 -> V_3 |= V_293 ;
else
V_46 -> V_3 &= ~ V_293 ;
V_81 = 0 ;
break;
case V_322 :
if ( V_289 ) {
V_46 -> V_3 |= V_47 ;
F_38 ( V_48 , & V_46 -> V_49 ) ;
F_40 ( & V_46 -> V_55 ) ;
} else {
V_46 -> V_3 &= ~ V_47 ;
}
V_81 = 0 ;
break;
#ifdef F_109
case V_314 :
case V_315 : {
struct V_71 V_72 ;
if ( ! F_241 ( V_237 ) )
return - V_251 ;
if ( V_311 < sizeof( V_72 ) )
return - V_17 ;
if ( F_242 ( & V_72 , V_310 , sizeof( V_72 ) ) )
return - V_316 ;
V_81 = F_55 ( V_2 , & V_72 , false ,
V_309 == V_315 ) ;
break;
}
#endif
default:
V_81 = - V_313 ;
}
return V_81 ;
}
static int F_243 ( struct V_104 * V_1 , int V_308 , int V_309 ,
char T_7 * V_310 , int T_7 * V_311 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_45 * V_46 = F_2 ( V_2 ) ;
int V_61 , V_289 , V_81 ;
if ( V_308 != V_312 )
return - V_313 ;
if ( F_240 ( V_61 , V_311 ) )
return - V_316 ;
if ( V_61 < 0 )
return - V_17 ;
switch ( V_309 ) {
case V_317 :
if ( V_61 < sizeof( int ) )
return - V_17 ;
V_61 = sizeof( int ) ;
V_289 = V_46 -> V_3 & V_318 ? 1 : 0 ;
if ( F_244 ( V_61 , V_311 ) ||
F_244 ( V_289 , V_310 ) )
return - V_316 ;
V_81 = 0 ;
break;
case V_321 :
if ( V_61 < sizeof( int ) )
return - V_17 ;
V_61 = sizeof( int ) ;
V_289 = V_46 -> V_3 & V_293 ? 1 : 0 ;
if ( F_244 ( V_61 , V_311 ) ||
F_244 ( V_289 , V_310 ) )
return - V_316 ;
V_81 = 0 ;
break;
case V_322 :
if ( V_61 < sizeof( int ) )
return - V_17 ;
V_61 = sizeof( int ) ;
V_289 = V_46 -> V_3 & V_47 ? 1 : 0 ;
if ( F_244 ( V_61 , V_311 ) ||
F_244 ( V_289 , V_310 ) )
return - V_316 ;
V_81 = 0 ;
break;
default:
V_81 = - V_313 ;
}
return V_81 ;
}
static void F_245 ( struct V_143 * V_144 , struct V_27 * V_28 )
{
struct V_323 V_301 ;
V_301 . V_5 = F_42 ( V_28 ) . V_146 ;
F_246 ( V_144 , V_312 , V_317 , sizeof( V_301 ) , & V_301 ) ;
}
static int F_247 ( struct V_324 * V_324 , struct V_104 * V_1 ,
struct V_143 * V_144 , T_5 V_61 )
{
struct V_147 * V_148 = F_248 ( V_324 ) ;
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_45 * V_46 = F_2 ( V_2 ) ;
struct V_245 * V_243 = V_144 -> V_325 ;
T_1 V_145 ;
T_1 V_146 ;
struct V_27 * V_28 ;
int V_81 ;
struct V_326 V_159 ;
if ( V_144 -> V_154 & V_327 )
return - V_328 ;
if ( NULL == V_148 -> V_159 )
V_148 -> V_159 = & V_159 ;
V_81 = F_249 ( V_1 , V_144 , V_148 -> V_159 , true ) ;
if ( V_81 < 0 )
return V_81 ;
if ( V_144 -> V_329 ) {
V_81 = - V_17 ;
if ( V_243 -> V_247 != V_248 )
goto V_24;
V_145 = V_243 -> V_252 ;
V_146 = F_192 ( V_243 -> V_249 ) ;
V_81 = - V_251 ;
if ( ( V_146 || V_145 ) &&
! F_183 ( V_1 , V_258 ) )
goto V_24;
} else {
V_145 = V_46 -> V_145 ;
V_146 = V_46 -> V_146 ;
}
if ( ! V_46 -> V_9 ) {
V_81 = F_180 ( V_1 ) ;
if ( V_81 )
goto V_24;
}
if ( F_44 ( V_2 ) &&
V_144 -> V_330 -> V_331 == NULL ) {
V_81 = F_91 ( V_2 , V_144 , V_145 , V_146 ,
V_148 ) ;
goto V_24;
}
V_81 = - V_332 ;
if ( V_61 > V_2 -> V_333 - 32 )
goto V_24;
V_81 = - V_51 ;
V_28 = F_201 ( V_61 , V_146 ) ;
if ( V_28 == NULL )
goto V_24;
F_42 ( V_28 ) . V_9 = V_46 -> V_9 ;
F_42 ( V_28 ) . V_146 = V_146 ;
F_42 ( V_28 ) . V_158 = V_148 -> V_159 -> V_158 ;
V_81 = - V_316 ;
if ( F_250 ( F_251 ( V_28 , V_61 ) , V_144 -> V_330 , V_61 ) ) {
F_100 ( V_28 ) ;
goto V_24;
}
V_81 = F_99 ( V_2 , V_28 ) ;
if ( V_81 ) {
F_100 ( V_28 ) ;
goto V_24;
}
if ( V_146 ) {
F_35 ( & V_28 -> V_160 ) ;
F_101 ( V_2 , V_28 , V_145 , V_146 , V_65 ) ;
}
V_81 = F_102 ( V_2 , V_28 , V_145 , V_144 -> V_154 & V_155 ) ;
V_24:
F_252 ( V_148 -> V_159 ) ;
return V_81 ;
}
static int F_253 ( struct V_324 * V_324 , struct V_104 * V_1 ,
struct V_143 * V_144 , T_5 V_61 ,
int V_3 )
{
struct V_147 * V_148 = F_248 ( V_324 ) ;
struct V_326 V_159 ;
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_45 * V_46 = F_2 ( V_2 ) ;
int V_334 = V_3 & V_155 ;
T_5 V_335 ;
struct V_27 * V_28 , * V_336 ;
int V_81 , V_26 ;
if ( V_3 & V_327 )
return - V_328 ;
V_335 = 0 ;
V_28 = F_254 ( V_2 , V_3 , V_334 , & V_81 ) ;
if ( V_28 == NULL )
goto V_24;
V_336 = V_28 ;
#ifdef F_255
if ( F_7 ( F_112 ( V_28 ) -> V_337 ) ) {
if ( V_3 & V_338 )
V_336 = F_112 ( V_28 ) -> V_337 ;
}
#endif
V_335 = V_336 -> V_61 ;
if ( V_61 < V_335 ) {
V_144 -> V_154 |= V_339 ;
V_335 = V_61 ;
}
F_256 ( V_336 ) ;
V_81 = F_257 ( V_336 , 0 , V_144 -> V_330 , V_335 ) ;
if ( V_144 -> V_325 ) {
struct V_245 * V_243 = (struct V_245 * ) V_144 -> V_325 ;
V_243 -> V_247 = V_248 ;
V_243 -> V_261 = 0 ;
V_243 -> V_252 = F_42 ( V_28 ) . V_9 ;
V_243 -> V_249 = F_3 ( F_42 ( V_28 ) . V_146 ) ;
V_144 -> V_329 = sizeof( * V_243 ) ;
}
if ( V_46 -> V_3 & V_318 )
F_245 ( V_144 , V_28 ) ;
if ( NULL == V_148 -> V_159 ) {
memset ( & V_159 , 0 , sizeof( V_159 ) ) ;
V_148 -> V_159 = & V_159 ;
}
V_148 -> V_159 -> V_158 = * F_258 ( V_28 ) ;
if ( V_3 & V_339 )
V_335 = V_336 -> V_61 ;
F_259 ( V_2 , V_28 ) ;
if ( V_46 -> V_133 &&
F_56 ( & V_2 -> V_173 ) <= V_2 -> V_274 / 2 ) {
V_26 = F_86 ( V_2 ) ;
if ( V_26 ) {
V_2 -> V_50 = V_26 ;
V_2 -> V_52 ( V_2 ) ;
}
}
F_260 ( V_1 , V_144 , V_148 -> V_159 , V_3 ) ;
V_24:
F_36 ( V_2 ) ;
return V_81 ? : V_335 ;
}
static void F_261 ( struct V_1 * V_2 , int V_61 )
{
F_262 () ;
}
struct V_1 *
F_263 ( struct V_185 * V_185 , int V_340 , struct V_21 * V_21 ,
struct V_341 * V_342 )
{
struct V_104 * V_1 ;
struct V_1 * V_2 ;
struct V_45 * V_46 ;
struct V_202 * V_202 = NULL ;
struct V_210 * V_211 = V_342 ? V_342 -> V_211 : NULL ;
unsigned int V_179 ;
F_177 ( ! V_187 ) ;
if ( V_340 < 0 || V_340 >= V_223 )
return NULL ;
if ( F_264 ( V_214 , V_221 , V_340 , & V_1 ) )
return NULL ;
if ( F_160 ( & V_343 , V_1 , V_211 , V_340 ) < 0 )
goto V_344;
V_2 = V_1 -> V_2 ;
F_265 ( V_2 , V_185 ) ;
if ( ! V_342 || V_342 -> V_179 < 32 )
V_179 = 32 ;
else
V_179 = V_342 -> V_179 ;
V_202 = F_143 ( sizeof( * V_202 ) + F_189 ( V_179 ) , V_65 ) ;
if ( ! V_202 )
goto V_345;
V_2 -> V_277 = F_261 ;
if ( V_342 && V_342 -> V_346 )
F_2 ( V_2 ) -> V_280 = V_342 -> V_346 ;
if ( F_155 ( V_2 , V_185 , 0 ) )
goto V_345;
V_46 = F_2 ( V_2 ) ;
V_46 -> V_3 |= V_4 ;
F_121 () ;
if ( ! V_187 [ V_340 ] . V_225 ) {
V_187 [ V_340 ] . V_179 = V_179 ;
F_266 ( V_187 [ V_340 ] . V_202 , V_202 ) ;
V_187 [ V_340 ] . V_211 = V_211 ;
V_187 [ V_340 ] . V_21 = V_21 ;
if ( V_342 ) {
V_187 [ V_340 ] . F_166 = V_342 -> F_166 ;
V_187 [ V_340 ] . V_3 = V_342 -> V_3 ;
if ( V_342 -> V_188 )
V_187 [ V_340 ] . V_188 = V_342 -> V_188 ;
}
V_187 [ V_340 ] . V_225 = 1 ;
} else {
F_49 ( V_202 ) ;
V_187 [ V_340 ] . V_225 ++ ;
}
F_130 () ;
return V_2 ;
V_345:
F_49 ( V_202 ) ;
F_267 ( V_2 ) ;
return NULL ;
V_344:
F_268 ( V_1 ) ;
return NULL ;
}
void
F_267 ( struct V_1 * V_2 )
{
F_269 ( V_2 ) ;
}
int F_270 ( struct V_1 * V_2 , unsigned int V_179 )
{
struct V_202 * V_307 , * V_231 ;
struct V_186 * V_201 = & V_187 [ V_2 -> V_30 ] ;
if ( V_179 < 32 )
V_179 = 32 ;
if ( F_189 ( V_201 -> V_179 ) < F_189 ( V_179 ) ) {
V_307 = F_143 ( sizeof( * V_307 ) + F_189 ( V_179 ) , V_42 ) ;
if ( ! V_307 )
return - V_41 ;
V_231 = F_152 ( V_201 -> V_202 ) ;
memcpy ( V_307 -> V_204 , V_231 -> V_204 , F_189 ( V_201 -> V_179 ) ) ;
F_266 ( V_201 -> V_202 , V_307 ) ;
F_179 ( V_231 , V_232 ) ;
}
V_201 -> V_179 = V_179 ;
return 0 ;
}
int F_271 ( struct V_1 * V_2 , unsigned int V_179 )
{
int V_81 ;
F_121 () ;
V_81 = F_270 ( V_2 , V_179 ) ;
F_130 () ;
return V_81 ;
}
void F_272 ( struct V_1 * V_347 , unsigned int V_5 )
{
struct V_1 * V_2 ;
struct V_186 * V_201 = & V_187 [ V_347 -> V_30 ] ;
F_154 (sk, &tbl->mc_list)
F_236 ( F_2 ( V_2 ) , V_5 , 0 ) ;
}
void F_273 ( struct V_1 * V_347 , unsigned int V_5 )
{
F_121 () ;
F_272 ( V_347 , V_5 ) ;
F_130 () ;
}
struct V_348 *
F_274 ( struct V_27 * V_28 , T_1 V_9 , T_1 V_349 , int type , int V_61 , int V_3 )
{
struct V_348 * V_350 ;
int V_107 = F_275 ( V_61 ) ;
V_350 = (struct V_348 * ) F_251 ( V_28 , F_276 ( V_107 ) ) ;
V_350 -> V_351 = type ;
V_350 -> V_352 = V_107 ;
V_350 -> V_353 = V_3 ;
V_350 -> V_354 = V_9 ;
V_350 -> V_355 = V_349 ;
if ( ! F_277 ( V_107 ) || F_276 ( V_107 ) - V_107 != 0 )
memset ( F_278 ( V_350 ) + V_61 , 0 , F_276 ( V_107 ) - V_107 ) ;
return V_350 ;
}
static int F_86 ( struct V_1 * V_2 )
{
struct V_45 * V_46 = F_2 ( V_2 ) ;
struct V_356 * V_174 ;
struct V_27 * V_28 = NULL ;
struct V_348 * V_350 ;
int V_61 , V_81 = - V_51 ;
int V_357 ;
F_59 ( V_46 -> V_211 ) ;
if ( ! V_46 -> V_133 ) {
V_81 = - V_17 ;
goto V_358;
}
V_174 = & V_46 -> V_174 ;
V_357 = F_279 ( int , V_174 -> V_359 , V_270 ) ;
if ( ! F_43 ( V_2 ) &&
F_56 ( & V_2 -> V_173 ) >= V_2 -> V_274 )
goto V_358;
V_28 = F_224 ( V_2 , V_357 , V_46 -> V_9 , V_65 ) ;
if ( ! V_28 )
goto V_358;
F_114 ( V_28 , V_2 ) ;
V_61 = V_174 -> V_360 ( V_28 , V_174 ) ;
if ( V_61 > 0 ) {
F_65 ( V_46 -> V_211 ) ;
if ( F_223 ( V_2 , V_28 ) )
F_100 ( V_28 ) ;
else
F_210 ( V_2 , V_28 ) ;
return 0 ;
}
V_350 = F_280 ( V_28 , V_174 , V_361 , sizeof( V_61 ) , V_362 ) ;
if ( ! V_350 )
goto V_358;
F_281 ( V_174 , V_350 ) ;
memcpy ( F_278 ( V_350 ) , & V_61 , sizeof( V_61 ) ) ;
if ( F_223 ( V_2 , V_28 ) )
F_100 ( V_28 ) ;
else
F_210 ( V_2 , V_28 ) ;
if ( V_174 -> V_175 )
V_174 -> V_175 ( V_174 ) ;
V_46 -> V_133 = false ;
F_65 ( V_46 -> V_211 ) ;
F_16 ( V_174 -> V_21 ) ;
F_216 ( V_174 -> V_28 ) ;
return 0 ;
V_358:
F_65 ( V_46 -> V_211 ) ;
F_100 ( V_28 ) ;
return V_81 ;
}
int F_282 ( struct V_1 * V_262 , struct V_27 * V_28 ,
const struct V_348 * V_350 ,
struct V_363 * V_364 )
{
struct V_356 * V_174 ;
struct V_1 * V_2 ;
struct V_45 * V_46 ;
int V_26 ;
if ( F_41 ( V_28 ) ) {
V_28 = F_283 ( V_28 , V_65 ) ;
if ( V_28 == NULL )
return - V_51 ;
} else
F_35 ( & V_28 -> V_160 ) ;
V_2 = F_140 ( F_139 ( V_262 ) , V_262 -> V_30 , F_42 ( V_28 ) . V_9 ) ;
if ( V_2 == NULL ) {
V_26 = - V_263 ;
goto V_365;
}
V_46 = F_2 ( V_2 ) ;
F_59 ( V_46 -> V_211 ) ;
if ( V_46 -> V_133 ) {
V_26 = - V_84 ;
goto V_366;
}
if ( ! F_169 ( V_364 -> V_21 ) ) {
V_26 = - V_224 ;
goto V_366;
}
V_174 = & V_46 -> V_174 ;
memset ( V_174 , 0 , sizeof( * V_174 ) ) ;
V_174 -> V_360 = V_364 -> V_360 ;
V_174 -> V_175 = V_364 -> V_175 ;
V_174 -> V_350 = V_350 ;
V_174 -> V_138 = V_364 -> V_138 ;
V_174 -> V_21 = V_364 -> V_21 ;
V_174 -> V_359 = V_364 -> V_359 ;
V_174 -> V_28 = V_28 ;
V_46 -> V_133 = true ;
F_65 ( V_46 -> V_211 ) ;
V_26 = F_86 ( V_2 ) ;
F_110 ( V_2 ) ;
if ( V_26 )
return V_26 ;
return - V_367 ;
V_366:
F_110 ( V_2 ) ;
F_65 ( V_46 -> V_211 ) ;
V_365:
F_100 ( V_28 ) ;
return V_26 ;
}
void F_284 ( struct V_27 * V_368 , struct V_348 * V_350 , int V_81 )
{
struct V_27 * V_28 ;
struct V_348 * V_369 ;
struct V_370 * V_371 ;
T_5 V_372 = sizeof( * V_371 ) ;
if ( V_81 )
V_372 += V_352 ( V_350 ) ;
V_28 = F_224 ( V_368 -> V_2 , F_285 ( V_372 ) ,
F_42 ( V_368 ) . V_9 , V_65 ) ;
if ( ! V_28 ) {
struct V_1 * V_2 ;
V_2 = F_140 ( F_139 ( V_368 -> V_2 ) ,
V_368 -> V_2 -> V_30 ,
F_42 ( V_368 ) . V_9 ) ;
if ( V_2 ) {
V_2 -> V_50 = V_51 ;
V_2 -> V_52 ( V_2 ) ;
F_110 ( V_2 ) ;
}
return;
}
V_369 = F_274 ( V_28 , F_42 ( V_368 ) . V_9 , V_350 -> V_355 ,
V_373 , V_372 , 0 ) ;
V_371 = F_278 ( V_369 ) ;
V_371 -> error = V_81 ;
memcpy ( & V_371 -> V_144 , V_350 , V_81 ? V_350 -> V_352 : sizeof( * V_350 ) ) ;
F_102 ( V_368 -> V_2 , V_28 , F_42 ( V_368 ) . V_9 , V_155 ) ;
}
int F_286 ( struct V_27 * V_28 , int (* V_174)( struct V_27 * ,
struct V_348 * ) )
{
struct V_348 * V_350 ;
int V_81 ;
while ( V_28 -> V_61 >= F_285 ( 0 ) ) {
int V_374 ;
V_350 = F_287 ( V_28 ) ;
V_81 = 0 ;
if ( V_350 -> V_352 < V_375 || V_28 -> V_61 < V_350 -> V_352 )
return 0 ;
if ( ! ( V_350 -> V_353 & V_376 ) )
goto V_377;
if ( V_350 -> V_351 < V_378 )
goto V_377;
V_81 = V_174 ( V_28 , V_350 ) ;
if ( V_81 == - V_367 )
goto V_379;
V_377:
if ( V_350 -> V_353 & V_380 || V_81 )
F_284 ( V_28 , V_350 , V_81 ) ;
V_379:
V_374 = F_276 ( V_350 -> V_352 ) ;
if ( V_374 > V_28 -> V_61 )
V_374 = V_28 -> V_61 ;
F_288 ( V_28 , V_374 ) ;
}
return 0 ;
}
int F_289 ( struct V_1 * V_2 , struct V_27 * V_28 , T_1 V_9 ,
unsigned int V_5 , int V_381 , T_2 V_3 )
{
int V_81 = 0 ;
if ( V_5 ) {
int V_382 = 0 ;
if ( V_381 ) {
F_35 ( & V_28 -> V_160 ) ;
V_382 = V_9 ;
}
V_81 = F_290 ( V_2 , V_28 , V_382 , V_5 , V_3 ) ;
}
if ( V_381 ) {
int V_285 ;
V_285 = F_291 ( V_2 , V_28 , V_9 ) ;
if ( ! V_81 || V_81 == - V_303 )
V_81 = V_285 ;
}
return V_81 ;
}
static struct V_1 * F_292 ( struct V_383 * V_349 , T_8 V_126 )
{
struct V_384 * V_385 = V_349 -> V_386 ;
int V_62 , V_387 ;
struct V_1 * V_388 ;
T_8 V_389 = 0 ;
for ( V_62 = 0 ; V_62 < V_223 ; V_62 ++ ) {
struct V_7 * V_8 = & V_187 [ V_62 ] . V_8 ;
for ( V_387 = 0 ; V_387 <= V_8 -> V_12 ; V_387 ++ ) {
F_141 (s, &hash->table[j]) {
if ( F_139 ( V_388 ) != F_293 ( V_349 ) )
continue;
if ( V_389 == V_126 ) {
V_385 -> V_390 = V_62 ;
V_385 -> V_391 = V_387 ;
return V_388 ;
}
++ V_389 ;
}
}
}
return NULL ;
}
static void * F_294 ( struct V_383 * V_349 , T_8 * V_126 )
__acquires( T_4 )
{
F_133 ( & T_4 ) ;
return * V_126 ? F_292 ( V_349 , * V_126 - 1 ) : V_392 ;
}
static void * F_295 ( struct V_383 * V_349 , void * V_393 , T_8 * V_126 )
{
struct V_1 * V_388 ;
struct V_384 * V_385 ;
struct V_185 * V_185 ;
int V_62 , V_387 ;
++ * V_126 ;
if ( V_393 == V_392 )
return F_292 ( V_349 , 0 ) ;
V_185 = F_293 ( V_349 ) ;
V_385 = V_349 -> V_386 ;
V_388 = V_393 ;
do {
V_388 = F_296 ( V_388 ) ;
} while ( V_388 && ! V_187 [ V_388 -> V_30 ] . V_188 ( V_185 , V_388 ) );
if ( V_388 )
return V_388 ;
V_62 = V_385 -> V_390 ;
V_387 = V_385 -> V_391 + 1 ;
do {
struct V_7 * V_8 = & V_187 [ V_62 ] . V_8 ;
for (; V_387 <= V_8 -> V_12 ; V_387 ++ ) {
V_388 = F_297 ( & V_8 -> V_10 [ V_387 ] ) ;
while ( V_388 && ! V_187 [ V_388 -> V_30 ] . V_188 ( V_185 , V_388 ) )
V_388 = F_296 ( V_388 ) ;
if ( V_388 ) {
V_385 -> V_390 = V_62 ;
V_385 -> V_391 = V_387 ;
return V_388 ;
}
}
V_387 = 0 ;
} while ( ++ V_62 < V_223 );
return NULL ;
}
static void F_298 ( struct V_383 * V_349 , void * V_393 )
__releases( T_4 )
{
F_134 ( & T_4 ) ;
}
static int F_299 ( struct V_383 * V_349 , void * V_393 )
{
if ( V_393 == V_392 ) {
F_300 ( V_349 ,
L_4
L_5 ) ;
} else {
struct V_1 * V_388 = V_393 ;
struct V_45 * V_46 = F_2 ( V_388 ) ;
F_301 ( V_349 , L_6 ,
V_388 ,
V_388 -> V_30 ,
V_46 -> V_9 ,
V_46 -> V_179 ? ( T_1 ) V_46 -> V_179 [ 0 ] : 0 ,
F_302 ( V_388 ) ,
F_303 ( V_388 ) ,
V_46 -> V_133 ,
F_56 ( & V_388 -> V_394 ) ,
F_56 ( & V_388 -> V_53 ) ,
F_304 ( V_388 )
) ;
}
return 0 ;
}
static int F_305 ( struct V_265 * V_265 , struct V_102 * V_102 )
{
return F_306 ( V_265 , V_102 , & V_395 ,
sizeof( struct V_384 ) ) ;
}
int F_307 ( struct V_396 * V_397 )
{
return F_308 ( & V_229 , V_397 ) ;
}
int F_309 ( struct V_396 * V_397 )
{
return F_310 ( & V_229 , V_397 ) ;
}
static int T_9 F_311 ( struct V_185 * V_185 )
{
#ifdef F_312
if ( ! F_313 ( L_7 , 0 , V_185 -> V_398 , & V_399 ) )
return - V_41 ;
#endif
return 0 ;
}
static void T_10 F_314 ( struct V_185 * V_185 )
{
#ifdef F_312
F_315 ( L_7 , V_185 -> V_398 ) ;
#endif
}
static void T_11 F_316 ( void )
{
struct V_202 * V_202 ;
int V_179 = 32 ;
V_202 = F_143 ( sizeof( * V_202 ) + F_189 ( V_179 ) , V_65 ) ;
if ( ! V_202 )
F_317 ( L_8 ) ;
F_121 () ;
V_187 [ V_32 ] . V_179 = V_179 ;
F_266 ( V_187 [ V_32 ] . V_202 , V_202 ) ;
V_187 [ V_32 ] . V_21 = V_400 ;
V_187 [ V_32 ] . V_225 = 1 ;
V_187 [ V_32 ] . V_3 = V_258 ;
F_130 () ;
}
static int T_11 F_318 ( void )
{
int V_62 ;
unsigned long V_401 ;
unsigned int V_60 ;
int V_81 = F_319 ( & V_215 , 0 ) ;
if ( V_81 != 0 )
goto V_24;
F_320 ( sizeof( struct V_402 ) > F_321 ( struct V_27 , V_174 ) ) ;
V_187 = F_54 ( V_223 , sizeof( * V_187 ) , V_65 ) ;
if ( ! V_187 )
goto F_317;
if ( V_403 >= ( 128 * 1024 ) )
V_401 = V_403 >> ( 21 - V_404 ) ;
else
V_401 = V_403 >> ( 23 - V_404 ) ;
V_60 = F_322 ( V_401 ) - 1 + V_404 ;
V_401 = ( 1UL << V_60 ) / sizeof( struct V_6 ) ;
V_60 = F_322 ( F_323 ( V_401 , ( unsigned long ) V_208 ) ) - 1 ;
for ( V_62 = 0 ; V_62 < V_223 ; V_62 ++ ) {
struct V_7 * V_8 = & V_187 [ V_62 ] . V_8 ;
V_8 -> V_10 = F_142 ( 1 * sizeof( * V_8 -> V_10 ) ) ;
if ( ! V_8 -> V_10 ) {
while ( V_62 -- > 0 )
F_144 ( V_187 [ V_62 ] . V_8 . V_10 ,
1 * sizeof( * V_8 -> V_10 ) ) ;
F_49 ( V_187 ) ;
goto F_317;
}
V_8 -> V_194 = V_60 ;
V_8 -> V_191 = 0 ;
V_8 -> V_12 = 0 ;
V_8 -> V_196 = V_197 ;
V_187 [ V_62 ] . V_188 = F_137 ;
}
F_324 ( & V_20 ) ;
F_316 () ;
F_325 ( & V_405 ) ;
F_326 ( & V_406 ) ;
F_327 () ;
V_24:
return V_81 ;
F_317:
F_317 ( L_9 ) ;
}
