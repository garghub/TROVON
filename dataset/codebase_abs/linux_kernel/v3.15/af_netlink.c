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
static int F_12 ( struct V_13 * V_14 )
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
V_40 -> V_45 = F_1 ( V_2 ) ?
V_46 : V_47 ;
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
static void F_33 ( struct V_1 * V_48 , struct V_1 * V_49 ,
struct V_27 * V_28 )
{
if ( ! ( F_1 ( V_48 ) && F_1 ( V_49 ) ) )
F_29 ( V_28 ) ;
}
static void F_34 ( struct V_1 * V_2 )
{
struct V_50 * V_51 = F_2 ( V_2 ) ;
if ( ! ( V_51 -> V_3 & V_52 ) ) {
if ( ! F_35 ( V_53 , & F_2 ( V_2 ) -> V_54 ) ) {
V_2 -> V_55 = V_56 ;
V_2 -> V_57 ( V_2 ) ;
}
}
F_36 ( & V_2 -> V_58 ) ;
}
static void F_37 ( struct V_1 * V_2 )
{
struct V_50 * V_51 = F_2 ( V_2 ) ;
if ( F_38 ( & V_2 -> V_59 ) )
F_39 ( V_53 , & V_51 -> V_54 ) ;
if ( ! F_40 ( V_53 , & V_51 -> V_54 ) )
F_41 ( & V_51 -> V_60 ) ;
}
static bool F_42 ( const struct V_27 * V_28 )
{
return F_43 ( V_28 ) . V_3 & V_61 ;
}
static bool F_44 ( struct V_1 * V_2 )
{
return F_2 ( V_2 ) -> V_62 . V_63 != NULL ;
}
static bool F_45 ( struct V_1 * V_2 )
{
return F_2 ( V_2 ) -> V_64 . V_63 != NULL ;
}
static void F_46 ( void * * V_63 , unsigned int V_65 , unsigned int V_66 )
{
unsigned int V_67 ;
for ( V_67 = 0 ; V_67 < V_66 ; V_67 ++ ) {
if ( V_63 [ V_67 ] != NULL ) {
if ( F_47 ( V_63 [ V_67 ] ) )
F_48 ( V_63 [ V_67 ] ) ;
else
F_49 ( ( unsigned long ) V_63 [ V_67 ] , V_65 ) ;
}
}
F_50 ( V_63 ) ;
}
static void * F_51 ( unsigned long V_65 )
{
void * V_68 ;
T_2 V_69 = V_70 | V_71 | V_72 |
V_73 | V_74 ;
V_68 = ( void * ) F_52 ( V_69 , V_65 ) ;
if ( V_68 != NULL )
return V_68 ;
V_68 = F_53 ( ( 1 << V_65 ) * V_75 ) ;
if ( V_68 != NULL )
return V_68 ;
V_69 &= ~ V_74 ;
return ( void * ) F_52 ( V_69 , V_65 ) ;
}
static void * * F_54 ( struct V_50 * V_51 ,
struct V_76 * V_77 , unsigned int V_65 )
{
unsigned int V_78 = V_77 -> V_79 ;
unsigned int V_67 ;
void * * V_63 ;
V_63 = F_55 ( V_78 , sizeof( void * ) , V_70 ) ;
if ( V_63 == NULL )
return NULL ;
for ( V_67 = 0 ; V_67 < V_78 ; V_67 ++ ) {
V_63 [ V_67 ] = F_51 ( V_65 ) ;
if ( V_63 [ V_67 ] == NULL )
goto V_80;
}
return V_63 ;
V_80:
F_46 ( V_63 , V_65 , V_78 ) ;
return NULL ;
}
static int F_56 ( struct V_1 * V_2 , struct V_76 * V_77 ,
bool V_81 , bool V_64 )
{
struct V_50 * V_51 = F_2 ( V_2 ) ;
struct V_82 * V_83 ;
struct V_84 * V_85 ;
void * * V_63 = NULL ;
unsigned int V_65 = 0 ;
int V_86 ;
V_83 = V_64 ? & V_51 -> V_64 : & V_51 -> V_62 ;
V_85 = V_64 ? & V_2 -> V_87 : & V_2 -> V_59 ;
if ( ! V_81 ) {
if ( F_57 ( & V_51 -> V_88 ) )
return - V_89 ;
if ( F_57 ( & V_83 -> V_90 ) )
return - V_89 ;
}
if ( V_77 -> V_79 ) {
if ( V_83 -> V_63 != NULL )
return - V_89 ;
if ( ( int ) V_77 -> V_91 <= 0 )
return - V_17 ;
if ( ! F_58 ( V_77 -> V_91 , V_75 ) )
return - V_17 ;
if ( V_77 -> V_92 < V_93 )
return - V_17 ;
if ( ! F_58 ( V_77 -> V_92 , V_94 ) )
return - V_17 ;
V_83 -> V_95 = V_77 -> V_91 /
V_77 -> V_92 ;
if ( V_83 -> V_95 == 0 )
return - V_17 ;
if ( V_83 -> V_95 * V_77 -> V_79 !=
V_77 -> V_96 )
return - V_17 ;
V_65 = F_59 ( V_77 -> V_91 ) ;
V_63 = F_54 ( V_51 , V_77 , V_65 ) ;
if ( V_63 == NULL )
return - V_41 ;
} else {
if ( V_77 -> V_96 )
return - V_17 ;
}
V_86 = - V_89 ;
F_60 ( & V_51 -> V_97 ) ;
if ( V_81 || F_57 ( & V_51 -> V_88 ) == 0 ) {
V_86 = 0 ;
F_61 ( & V_85 -> V_98 ) ;
V_83 -> V_99 = V_77 -> V_96 - 1 ;
V_83 -> V_100 = 0 ;
V_83 -> V_101 = V_77 -> V_92 ;
V_83 -> V_102 = V_77 -> V_91 / V_75 ;
F_62 ( V_83 -> V_103 , V_77 -> V_79 ) ;
F_62 ( V_83 -> V_104 , V_65 ) ;
F_62 ( V_83 -> V_63 , V_63 ) ;
F_63 ( V_85 ) ;
F_64 ( & V_85 -> V_98 ) ;
F_65 ( F_57 ( & V_51 -> V_88 ) ) ;
}
F_66 ( & V_51 -> V_97 ) ;
if ( V_63 )
F_46 ( V_63 , V_65 , V_77 -> V_79 ) ;
return V_86 ;
}
static void F_67 ( struct V_105 * V_106 )
{
struct V_107 * V_107 = V_106 -> V_108 ;
struct V_109 * V_1 = V_107 -> V_110 ;
struct V_1 * V_2 = V_1 -> V_2 ;
if ( V_2 )
F_36 ( & F_2 ( V_2 ) -> V_88 ) ;
}
static void F_68 ( struct V_105 * V_106 )
{
struct V_107 * V_107 = V_106 -> V_108 ;
struct V_109 * V_1 = V_107 -> V_110 ;
struct V_1 * V_2 = V_1 -> V_2 ;
if ( V_2 )
F_69 ( & F_2 ( V_2 ) -> V_88 ) ;
}
static int F_70 ( struct V_107 * V_107 , struct V_109 * V_1 ,
struct V_105 * V_106 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_50 * V_51 = F_2 ( V_2 ) ;
struct V_82 * V_83 ;
unsigned long V_111 , V_112 , V_113 ;
unsigned int V_67 ;
int V_86 = - V_17 ;
if ( V_106 -> V_114 )
return - V_17 ;
F_60 ( & V_51 -> V_97 ) ;
V_113 = 0 ;
for ( V_83 = & V_51 -> V_62 ; V_83 <= & V_51 -> V_64 ; V_83 ++ ) {
if ( V_83 -> V_63 == NULL )
continue;
V_113 += V_83 -> V_103 * V_83 -> V_102 * V_75 ;
}
if ( V_113 == 0 )
goto V_24;
V_112 = V_106 -> V_115 - V_106 -> V_116 ;
if ( V_112 != V_113 )
goto V_24;
V_111 = V_106 -> V_116 ;
for ( V_83 = & V_51 -> V_62 ; V_83 <= & V_51 -> V_64 ; V_83 ++ ) {
if ( V_83 -> V_63 == NULL )
continue;
for ( V_67 = 0 ; V_67 < V_83 -> V_103 ; V_67 ++ ) {
struct V_117 * V_117 ;
void * V_118 = V_83 -> V_63 [ V_67 ] ;
unsigned int V_119 ;
for ( V_119 = 0 ; V_119 < V_83 -> V_102 ; V_119 ++ ) {
V_117 = F_71 ( V_118 ) ;
V_86 = F_72 ( V_106 , V_111 , V_117 ) ;
if ( V_86 < 0 )
goto V_24;
V_111 += V_75 ;
V_118 += V_75 ;
}
}
}
F_36 ( & V_51 -> V_88 ) ;
V_106 -> V_120 = & V_121 ;
V_86 = 0 ;
V_24:
F_66 ( & V_51 -> V_97 ) ;
return V_86 ;
}
static void F_73 ( const struct V_122 * V_123 )
{
#if V_124 == 1
struct V_117 * V_125 , * V_126 ;
V_125 = F_71 ( V_123 + V_75 ) ;
V_126 = F_71 ( ( void * ) V_123 + V_93 + V_123 -> V_127 - 1 ) ;
while ( V_125 <= V_126 ) {
F_74 ( V_125 ) ;
V_125 ++ ;
}
#endif
}
static enum V_128 F_75 ( const struct V_122 * V_123 )
{
F_76 () ;
F_74 ( F_71 ( V_123 ) ) ;
return V_123 -> V_129 ;
}
static void F_77 ( struct V_122 * V_123 ,
enum V_128 V_130 )
{
V_123 -> V_129 = V_130 ;
F_74 ( F_71 ( V_123 ) ) ;
F_78 () ;
}
static struct V_122 *
F_79 ( const struct V_82 * V_83 , unsigned int V_131 )
{
unsigned int V_132 , V_133 ;
V_132 = V_131 / V_83 -> V_95 ;
V_133 = V_131 % V_83 -> V_95 ;
return V_83 -> V_63 [ V_132 ] + ( V_133 * V_83 -> V_101 ) ;
}
static struct V_122 *
F_80 ( const struct V_82 * V_83 , unsigned int V_131 ,
enum V_128 V_130 )
{
struct V_122 * V_123 ;
V_123 = F_79 ( V_83 , V_131 ) ;
if ( F_75 ( V_123 ) != V_130 )
return NULL ;
return V_123 ;
}
static struct V_122 *
F_81 ( const struct V_82 * V_83 ,
enum V_128 V_130 )
{
return F_80 ( V_83 , V_83 -> V_100 , V_130 ) ;
}
static struct V_122 *
F_82 ( const struct V_82 * V_83 ,
enum V_128 V_130 )
{
unsigned int V_134 ;
V_134 = V_83 -> V_100 ? V_83 -> V_100 - 1 : V_83 -> V_99 ;
return F_80 ( V_83 , V_134 , V_130 ) ;
}
static void F_83 ( struct V_82 * V_83 )
{
V_83 -> V_100 = V_83 -> V_100 != V_83 -> V_99 ? V_83 -> V_100 + 1 : 0 ;
}
static void F_84 ( struct V_82 * V_83 )
{
unsigned int V_100 = V_83 -> V_100 , V_131 = V_100 ;
const struct V_122 * V_123 ;
do {
V_123 = F_79 ( V_83 , V_131 ) ;
if ( V_123 -> V_129 == V_135 )
break;
if ( V_123 -> V_129 != V_136 )
break;
F_83 ( V_83 ) ;
} while ( V_83 -> V_100 != V_100 );
}
static bool F_85 ( struct V_50 * V_51 )
{
struct V_82 * V_83 = & V_51 -> V_62 ;
struct V_122 * V_123 ;
unsigned int V_137 ;
V_123 = F_81 ( V_83 , V_135 ) ;
if ( V_123 == NULL )
return false ;
V_137 = V_83 -> V_100 + V_83 -> V_99 / 2 ;
if ( V_137 > V_83 -> V_99 )
V_137 -= V_83 -> V_99 ;
V_123 = F_79 ( V_83 , V_137 ) ;
return V_123 -> V_129 == V_135 ;
}
static unsigned int F_86 ( struct V_107 * V_107 , struct V_109 * V_1 ,
T_3 * V_60 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_50 * V_51 = F_2 ( V_2 ) ;
unsigned int V_12 ;
int V_86 ;
if ( V_51 -> V_62 . V_63 != NULL ) {
while ( V_51 -> V_138 && F_85 ( V_51 ) ) {
V_86 = F_87 ( V_2 ) ;
if ( V_86 < 0 ) {
V_2 -> V_55 = V_86 ;
V_2 -> V_57 ( V_2 ) ;
break;
}
}
F_37 ( V_2 ) ;
}
V_12 = F_88 ( V_107 , V_1 , V_60 ) ;
F_61 ( & V_2 -> V_59 . V_98 ) ;
if ( V_51 -> V_62 . V_63 ) {
F_84 ( & V_51 -> V_62 ) ;
if ( ! F_82 ( & V_51 -> V_62 , V_135 ) )
V_12 |= V_139 | V_140 ;
}
F_64 ( & V_2 -> V_59 . V_98 ) ;
F_61 ( & V_2 -> V_87 . V_98 ) ;
if ( V_51 -> V_64 . V_63 ) {
if ( F_81 ( & V_51 -> V_64 , V_135 ) )
V_12 |= V_141 | V_142 ;
}
F_64 ( & V_2 -> V_87 . V_98 ) ;
return V_12 ;
}
static struct V_122 * F_89 ( struct V_27 * V_28 )
{
return (struct V_122 * ) ( V_28 -> V_100 - V_93 ) ;
}
static void F_90 ( struct V_27 * V_28 , struct V_1 * V_2 ,
struct V_82 * V_83 ,
struct V_122 * V_123 )
{
unsigned int V_112 ;
void * V_143 ;
V_112 = V_83 -> V_101 - V_93 ;
V_143 = ( void * ) V_123 + V_93 ;
V_28 -> V_100 = V_143 ;
V_28 -> V_143 = V_143 ;
F_91 ( V_28 ) ;
V_28 -> V_144 = V_28 -> V_145 + V_112 ;
V_28 -> V_66 = 0 ;
V_28 -> V_146 = V_147 ;
F_43 ( V_28 ) . V_3 |= V_61 ;
F_43 ( V_28 ) . V_2 = V_2 ;
}
static int F_92 ( struct V_1 * V_2 , struct V_148 * V_149 ,
T_1 V_150 , T_1 V_151 ,
struct V_152 * V_153 )
{
struct V_50 * V_51 = F_2 ( V_2 ) ;
struct V_82 * V_83 ;
struct V_122 * V_123 ;
struct V_27 * V_28 ;
unsigned int V_154 ;
bool V_155 = true ;
int V_86 = 0 , V_66 = 0 ;
if ( F_93 ( & V_2 -> V_156 -> V_107 -> V_157 ) > 2 ||
F_57 ( & V_51 -> V_88 ) > 1 )
V_155 = false ;
F_60 ( & V_51 -> V_97 ) ;
V_83 = & V_51 -> V_64 ;
V_154 = V_83 -> V_101 - V_93 ;
do {
V_123 = F_81 ( V_83 , V_158 ) ;
if ( V_123 == NULL ) {
if ( ! ( V_149 -> V_159 & V_160 ) &&
F_57 ( & V_51 -> V_64 . V_90 ) )
F_94 () ;
continue;
}
if ( V_123 -> V_127 > V_154 ) {
V_86 = - V_17 ;
goto V_24;
}
F_73 ( V_123 ) ;
if ( F_95 ( V_150 == 0 && V_151 == 0 && V_155 ) ) {
V_28 = F_96 ( V_70 ) ;
if ( V_28 == NULL ) {
V_86 = - V_56 ;
goto V_24;
}
F_97 ( V_2 ) ;
F_90 ( V_28 , V_2 , V_83 , V_123 ) ;
F_43 ( V_28 ) . V_3 |= V_161 ;
F_98 ( V_28 , V_123 -> V_127 ) ;
F_77 ( V_123 , V_162 ) ;
F_36 ( & V_83 -> V_90 ) ;
} else {
V_28 = F_99 ( V_123 -> V_127 , V_70 ) ;
if ( V_28 == NULL ) {
V_86 = - V_56 ;
goto V_24;
}
F_98 ( V_28 , V_123 -> V_127 ) ;
memcpy ( V_28 -> V_143 , ( void * ) V_123 + V_93 , V_123 -> V_127 ) ;
F_77 ( V_123 , V_135 ) ;
}
F_83 ( V_83 ) ;
F_43 ( V_28 ) . V_9 = V_51 -> V_9 ;
F_43 ( V_28 ) . V_151 = V_151 ;
F_43 ( V_28 ) . V_163 = V_153 -> V_164 -> V_163 ;
V_86 = F_100 ( V_2 , V_28 ) ;
if ( V_86 ) {
F_101 ( V_28 ) ;
goto V_24;
}
if ( F_7 ( V_151 ) ) {
F_36 ( & V_28 -> V_165 ) ;
F_102 ( V_2 , V_28 , V_150 , V_151 ,
V_70 ) ;
}
V_86 = F_103 ( V_2 , V_28 , V_150 ,
V_149 -> V_159 & V_160 ) ;
if ( V_86 < 0 )
goto V_24;
V_66 += V_86 ;
} while ( V_123 != NULL ||
( ! ( V_149 -> V_159 & V_160 ) &&
F_57 ( & V_51 -> V_64 . V_90 ) ) );
if ( V_66 > 0 )
V_86 = V_66 ;
V_24:
F_66 ( & V_51 -> V_97 ) ;
return V_86 ;
}
static void F_104 ( struct V_1 * V_2 , struct V_27 * V_28 )
{
struct V_122 * V_123 ;
V_123 = F_89 ( V_28 ) ;
V_123 -> V_127 = V_28 -> V_66 ;
V_123 -> V_166 = F_43 ( V_28 ) . V_151 ;
V_123 -> V_167 = F_43 ( V_28 ) . V_163 . V_168 ;
V_123 -> V_169 = F_105 ( F_106 ( V_2 ) , F_43 ( V_28 ) . V_163 . V_170 ) ;
V_123 -> V_171 = F_107 ( F_106 ( V_2 ) , F_43 ( V_28 ) . V_163 . V_172 ) ;
F_73 ( V_123 ) ;
F_77 ( V_123 , V_158 ) ;
F_43 ( V_28 ) . V_3 |= V_173 ;
F_101 ( V_28 ) ;
}
static void F_108 ( struct V_1 * V_2 , struct V_27 * V_28 )
{
struct V_50 * V_51 = F_2 ( V_2 ) ;
struct V_82 * V_83 = & V_51 -> V_62 ;
struct V_122 * V_123 ;
F_61 ( & V_2 -> V_59 . V_98 ) ;
V_123 = F_81 ( V_83 , V_135 ) ;
if ( V_123 == NULL ) {
F_64 ( & V_2 -> V_59 . V_98 ) ;
F_101 ( V_28 ) ;
F_34 ( V_2 ) ;
return;
}
F_83 ( V_83 ) ;
F_109 ( & V_2 -> V_59 , V_28 ) ;
F_64 ( & V_2 -> V_59 . V_98 ) ;
V_123 -> V_127 = V_28 -> V_66 ;
V_123 -> V_166 = F_43 ( V_28 ) . V_151 ;
V_123 -> V_167 = F_43 ( V_28 ) . V_163 . V_168 ;
V_123 -> V_169 = F_105 ( F_106 ( V_2 ) , F_43 ( V_28 ) . V_163 . V_170 ) ;
V_123 -> V_171 = F_107 ( F_106 ( V_2 ) , F_43 ( V_28 ) . V_163 . V_172 ) ;
F_77 ( V_123 , V_174 ) ;
}
static void V_147 ( struct V_27 * V_28 )
{
#ifdef F_110
struct V_122 * V_123 ;
struct V_82 * V_83 ;
struct V_1 * V_2 ;
if ( F_42 ( V_28 ) ) {
V_123 = F_89 ( V_28 ) ;
V_2 = F_43 ( V_28 ) . V_2 ;
if ( F_43 ( V_28 ) . V_3 & V_161 ) {
F_77 ( V_123 , V_135 ) ;
V_83 = & F_2 ( V_2 ) -> V_64 ;
} else {
if ( ! ( F_43 ( V_28 ) . V_3 & V_173 ) ) {
V_123 -> V_127 = 0 ;
F_77 ( V_123 , V_158 ) ;
}
V_83 = & F_2 ( V_2 ) -> V_62 ;
}
F_65 ( F_57 ( & V_83 -> V_90 ) == 0 ) ;
F_69 ( & V_83 -> V_90 ) ;
F_111 ( V_2 ) ;
V_28 -> V_100 = NULL ;
}
#endif
if ( F_47 ( V_28 -> V_100 ) ) {
if ( ! V_28 -> V_175 ||
! F_112 ( & ( F_113 ( V_28 ) -> V_176 ) ) )
F_48 ( V_28 -> V_100 ) ;
V_28 -> V_100 = NULL ;
}
if ( V_28 -> V_2 != NULL )
F_114 ( V_28 ) ;
}
static void F_115 ( struct V_27 * V_28 , struct V_1 * V_2 )
{
F_65 ( V_28 -> V_2 != NULL ) ;
V_28 -> V_2 = V_2 ;
V_28 -> V_146 = V_147 ;
F_116 ( V_28 -> V_177 , & V_2 -> V_178 ) ;
F_117 ( V_2 , V_28 -> V_177 ) ;
}
static void F_118 ( struct V_1 * V_2 )
{
struct V_50 * V_51 = F_2 ( V_2 ) ;
if ( V_51 -> V_138 ) {
if ( V_51 -> V_179 . V_180 )
V_51 -> V_179 . V_180 ( & V_51 -> V_179 ) ;
F_16 ( V_51 -> V_179 . V_21 ) ;
F_101 ( V_51 -> V_179 . V_28 ) ;
}
F_119 ( & V_2 -> V_59 ) ;
#ifdef F_110
if ( 1 ) {
struct V_76 V_77 ;
memset ( & V_77 , 0 , sizeof( V_77 ) ) ;
if ( V_51 -> V_62 . V_63 )
F_56 ( V_2 , & V_77 , true , false ) ;
memset ( & V_77 , 0 , sizeof( V_77 ) ) ;
if ( V_51 -> V_64 . V_63 )
F_56 ( V_2 , & V_77 , true , true ) ;
}
#endif
if ( ! F_120 ( V_2 , V_181 ) ) {
F_121 ( V_182 L_2 , V_2 ) ;
return;
}
F_65 ( F_57 ( & V_2 -> V_178 ) ) ;
F_65 ( F_57 ( & V_2 -> V_183 ) ) ;
F_65 ( F_2 ( V_2 ) -> V_184 ) ;
}
void F_122 ( void )
__acquires( T_4 )
{
F_123 () ;
F_124 ( & T_4 ) ;
if ( F_57 ( & V_185 ) ) {
F_125 ( V_60 , V_186 ) ;
F_126 ( & V_187 , & V_60 ) ;
for (; ; ) {
F_127 ( V_188 ) ;
if ( F_57 ( & V_185 ) == 0 )
break;
F_128 ( & T_4 ) ;
F_94 () ;
F_124 ( & T_4 ) ;
}
F_129 ( V_189 ) ;
F_130 ( & V_187 , & V_60 ) ;
}
}
void F_131 ( void )
__releases( T_4 )
{
F_128 ( & T_4 ) ;
F_132 ( & V_187 ) ;
}
static inline void
F_133 ( void )
{
F_134 ( & T_4 ) ;
F_36 ( & V_185 ) ;
F_135 ( & T_4 ) ;
}
static inline void
F_136 ( void )
{
if ( F_137 ( & V_185 ) )
F_132 ( & V_187 ) ;
}
static bool F_138 ( struct V_190 * V_190 , struct V_1 * V_2 )
{
return F_139 ( F_140 ( V_2 ) , V_190 ) ;
}
static struct V_1 * F_141 ( struct V_190 * V_190 , int V_43 , T_1 V_9 )
{
struct V_191 * V_10 = & V_192 [ V_43 ] ;
struct V_7 * V_8 = & V_10 -> V_8 ;
struct V_6 * V_100 ;
struct V_1 * V_2 ;
F_134 ( & T_4 ) ;
V_100 = F_4 ( V_8 , V_9 ) ;
F_142 (sk, head) {
if ( V_10 -> V_193 ( V_190 , V_2 ) &&
( F_2 ( V_2 ) -> V_9 == V_9 ) ) {
F_97 ( V_2 ) ;
goto V_22;
}
}
V_2 = NULL ;
V_22:
F_135 ( & T_4 ) ;
return V_2 ;
}
static struct V_6 * F_143 ( T_5 V_112 )
{
if ( V_112 <= V_75 )
return F_144 ( V_112 , V_42 ) ;
else
return (struct V_6 * )
F_52 ( V_42 | V_72 ,
F_59 ( V_112 ) ) ;
}
static void F_145 ( struct V_6 * V_10 , T_5 V_112 )
{
if ( V_112 <= V_75 )
F_50 ( V_10 ) ;
else
F_49 ( ( unsigned long ) V_10 , F_59 ( V_112 ) ) ;
}
static int F_146 ( struct V_7 * V_8 , int V_194 )
{
unsigned int V_195 , V_12 , V_196 ;
T_5 V_197 , V_112 ;
struct V_6 * V_198 , * V_10 ;
int V_67 ;
V_195 = V_12 = V_8 -> V_12 ;
V_197 = V_112 = ( V_12 + 1 ) * sizeof( * V_10 ) ;
V_196 = V_8 -> V_196 ;
if ( V_194 ) {
if ( ++ V_196 > V_8 -> V_199 )
return 0 ;
V_12 = V_12 * 2 + 1 ;
V_112 *= 2 ;
}
V_10 = F_143 ( V_112 ) ;
if ( ! V_10 )
return 0 ;
V_198 = V_8 -> V_10 ;
V_8 -> V_10 = V_10 ;
V_8 -> V_12 = V_12 ;
V_8 -> V_196 = V_196 ;
F_147 ( & V_8 -> V_11 , sizeof( V_8 -> V_11 ) ) ;
for ( V_67 = 0 ; V_67 <= V_195 ; V_67 ++ ) {
struct V_1 * V_2 ;
struct V_200 * V_23 ;
F_148 (sk, tmp, &otable[i])
F_149 ( V_2 , F_4 ( V_8 , F_2 ( V_2 ) -> V_9 ) ) ;
}
F_145 ( V_198 , V_197 ) ;
V_8 -> V_201 = V_202 + 10 * 60 * V_203 ;
return 1 ;
}
static inline int F_150 ( struct V_7 * V_8 , int V_66 )
{
int V_204 = V_8 -> V_205 >> V_8 -> V_196 ;
if ( F_7 ( V_204 > 1 ) && F_146 ( V_8 , 1 ) )
return 1 ;
if ( F_7 ( V_66 > V_204 ) && F_151 ( V_202 , V_8 -> V_201 ) ) {
F_146 ( V_8 , 0 ) ;
return 1 ;
}
return 0 ;
}
static void
F_152 ( struct V_1 * V_2 )
{
struct V_191 * V_206 = & V_192 [ V_2 -> V_30 ] ;
unsigned long V_12 ;
unsigned int V_67 ;
struct V_207 * V_207 ;
V_207 = F_153 ( V_206 -> V_207 ) ;
if ( ! V_207 )
return;
for ( V_67 = 0 ; V_67 < F_154 ( V_206 -> V_184 ) ; V_67 ++ ) {
V_12 = 0 ;
F_155 (sk, &tbl->mc_list) {
if ( V_67 < F_154 ( F_2 ( V_2 ) -> V_208 ) )
V_12 |= F_2 ( V_2 ) -> V_184 [ V_67 ] ;
}
V_207 -> V_209 [ V_67 ] = V_12 ;
}
}
static int F_156 ( struct V_1 * V_2 , struct V_190 * V_190 , T_1 V_9 )
{
struct V_191 * V_10 = & V_192 [ V_2 -> V_30 ] ;
struct V_7 * V_8 = & V_10 -> V_8 ;
struct V_6 * V_100 ;
int V_86 = - V_210 ;
struct V_1 * V_211 ;
int V_66 ;
F_122 () ;
V_100 = F_4 ( V_8 , V_9 ) ;
V_66 = 0 ;
F_142 (osk, head) {
if ( V_10 -> V_193 ( V_190 , V_211 ) &&
( F_2 ( V_211 ) -> V_9 == V_9 ) )
break;
V_66 ++ ;
}
if ( V_211 )
goto V_86;
V_86 = - V_89 ;
if ( F_2 ( V_2 ) -> V_9 )
goto V_86;
V_86 = - V_41 ;
if ( V_212 > 32 && F_7 ( V_8 -> V_205 >= V_213 ) )
goto V_86;
if ( V_66 && F_150 ( V_8 , V_66 ) )
V_100 = F_4 ( V_8 , V_9 ) ;
V_8 -> V_205 ++ ;
F_2 ( V_2 ) -> V_9 = V_9 ;
F_157 ( V_2 , V_100 ) ;
V_86 = 0 ;
V_86:
F_131 () ;
return V_86 ;
}
static void F_158 ( struct V_1 * V_2 )
{
F_122 () ;
if ( F_159 ( V_2 ) )
V_192 [ V_2 -> V_30 ] . V_8 . V_205 -- ;
if ( F_2 ( V_2 ) -> V_214 )
F_160 ( V_2 ) ;
F_131 () ;
}
static int F_161 ( struct V_190 * V_190 , struct V_109 * V_1 ,
struct V_215 * V_216 , int V_43 )
{
struct V_1 * V_2 ;
struct V_50 * V_51 ;
V_1 -> V_217 = & V_218 ;
V_2 = F_162 ( V_190 , V_219 , V_70 , & V_220 ) ;
if ( ! V_2 )
return - V_41 ;
F_163 ( V_1 , V_2 ) ;
V_51 = F_2 ( V_2 ) ;
if ( V_216 ) {
V_51 -> V_216 = V_216 ;
} else {
V_51 -> V_216 = & V_51 -> V_221 ;
F_164 ( V_51 -> V_216 ) ;
}
F_165 ( & V_51 -> V_60 ) ;
#ifdef F_110
F_164 ( & V_51 -> V_97 ) ;
#endif
V_2 -> V_222 = F_118 ;
V_2 -> V_30 = V_43 ;
return 0 ;
}
static int F_166 ( struct V_190 * V_190 , struct V_109 * V_1 , int V_43 ,
int V_223 )
{
struct V_21 * V_21 = NULL ;
struct V_215 * V_216 ;
struct V_50 * V_51 ;
void (* F_167)( int V_5 );
int V_86 = 0 ;
V_1 -> V_54 = V_224 ;
if ( V_1 -> type != V_225 && V_1 -> type != V_226 )
return - V_227 ;
if ( V_43 < 0 || V_43 >= V_228 )
return - V_229 ;
F_133 () ;
#ifdef F_168
if ( ! V_192 [ V_43 ] . V_230 ) {
F_136 () ;
F_169 ( L_3 , V_219 , V_43 ) ;
F_133 () ;
}
#endif
if ( V_192 [ V_43 ] . V_230 &&
F_170 ( V_192 [ V_43 ] . V_21 ) )
V_21 = V_192 [ V_43 ] . V_21 ;
else
V_86 = - V_229 ;
V_216 = V_192 [ V_43 ] . V_216 ;
F_167 = V_192 [ V_43 ] . F_167 ;
F_136 () ;
if ( V_86 < 0 )
goto V_24;
V_86 = F_161 ( V_190 , V_1 , V_216 , V_43 ) ;
if ( V_86 < 0 )
goto V_231;
F_171 () ;
F_172 ( V_190 , & V_220 , 1 ) ;
F_173 () ;
V_51 = F_2 ( V_1 -> V_2 ) ;
V_51 -> V_21 = V_21 ;
V_51 -> V_232 = F_167 ;
V_24:
return V_86 ;
V_231:
F_16 ( V_21 ) ;
goto V_24;
}
static int F_174 ( struct V_109 * V_1 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_50 * V_51 ;
if ( ! V_2 )
return 0 ;
F_158 ( V_2 ) ;
F_175 ( V_2 ) ;
V_51 = F_2 ( V_2 ) ;
V_1 -> V_2 = NULL ;
F_176 ( & V_51 -> V_60 ) ;
F_119 ( & V_2 -> V_87 ) ;
if ( V_51 -> V_9 ) {
struct V_233 V_137 = {
. V_190 = F_140 ( V_2 ) ,
. V_43 = V_2 -> V_30 ,
. V_9 = V_51 -> V_9 ,
} ;
F_177 ( & V_234 ,
V_235 , & V_137 ) ;
}
F_16 ( V_51 -> V_21 ) ;
F_122 () ;
if ( F_1 ( V_2 ) ) {
F_178 ( V_192 [ V_2 -> V_30 ] . V_230 == 0 ) ;
if ( -- V_192 [ V_2 -> V_30 ] . V_230 == 0 ) {
struct V_207 * V_236 ;
V_236 = F_153 ( V_192 [ V_2 -> V_30 ] . V_207 ) ;
F_179 ( V_192 [ V_2 -> V_30 ] . V_207 , NULL ) ;
F_180 ( V_236 , V_237 ) ;
V_192 [ V_2 -> V_30 ] . V_21 = NULL ;
V_192 [ V_2 -> V_30 ] . F_167 = NULL ;
V_192 [ V_2 -> V_30 ] . V_3 = 0 ;
V_192 [ V_2 -> V_30 ] . V_230 = 0 ;
}
} else if ( V_51 -> V_214 ) {
F_152 ( V_2 ) ;
}
F_131 () ;
F_50 ( V_51 -> V_184 ) ;
V_51 -> V_184 = NULL ;
F_171 () ;
F_172 ( F_140 ( V_2 ) , & V_220 , - 1 ) ;
F_173 () ;
F_111 ( V_2 ) ;
return 0 ;
}
static int F_181 ( struct V_109 * V_1 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_190 * V_190 = F_140 ( V_2 ) ;
struct V_191 * V_10 = & V_192 [ V_2 -> V_30 ] ;
struct V_7 * V_8 = & V_10 -> V_8 ;
struct V_6 * V_100 ;
struct V_1 * V_211 ;
T_6 V_9 = F_182 ( V_186 ) ;
int V_86 ;
static T_6 V_238 = - 4097 ;
V_239:
F_183 () ;
F_122 () ;
V_100 = F_4 ( V_8 , V_9 ) ;
F_142 (osk, head) {
if ( ! V_10 -> V_193 ( V_190 , V_211 ) )
continue;
if ( F_2 ( V_211 ) -> V_9 == V_9 ) {
V_9 = V_238 -- ;
if ( V_238 > - 4097 )
V_238 = - 4097 ;
F_131 () ;
goto V_239;
}
}
F_131 () ;
V_86 = F_156 ( V_2 , V_190 , V_9 ) ;
if ( V_86 == - V_210 )
goto V_239;
if ( V_86 == - V_89 )
V_86 = 0 ;
return V_86 ;
}
bool F_184 ( const struct V_240 * V_241 ,
struct V_242 * V_243 , int V_244 )
{
return ( ( V_241 -> V_3 & V_245 ) ||
F_185 ( V_241 -> V_2 -> V_156 -> V_107 , V_243 , V_244 ) ) &&
F_186 ( V_243 , V_244 ) ;
}
bool F_187 ( const struct V_27 * V_28 ,
struct V_242 * V_243 , int V_244 )
{
return F_184 ( & F_43 ( V_28 ) , V_243 , V_244 ) ;
}
bool F_188 ( const struct V_27 * V_28 , int V_244 )
{
return F_187 ( V_28 , & V_246 , V_244 ) ;
}
bool F_189 ( const struct V_27 * V_28 , int V_244 )
{
return F_187 ( V_28 , F_140 ( V_28 -> V_2 ) -> V_243 , V_244 ) ;
}
static inline int F_190 ( const struct V_109 * V_1 , unsigned int V_247 )
{
return ( V_192 [ V_1 -> V_2 -> V_30 ] . V_3 & V_247 ) ||
F_186 ( F_140 ( V_1 -> V_2 ) -> V_243 , V_248 ) ;
}
static void
F_191 ( struct V_1 * V_2 , unsigned int V_214 )
{
struct V_50 * V_51 = F_2 ( V_2 ) ;
if ( V_51 -> V_214 && ! V_214 )
F_160 ( V_2 ) ;
else if ( ! V_51 -> V_214 && V_214 )
F_192 ( V_2 , & V_192 [ V_2 -> V_30 ] . V_249 ) ;
V_51 -> V_214 = V_214 ;
}
static int F_193 ( struct V_1 * V_2 )
{
struct V_50 * V_51 = F_2 ( V_2 ) ;
unsigned int V_184 ;
unsigned long * V_250 ;
int V_86 = 0 ;
F_122 () ;
V_184 = V_192 [ V_2 -> V_30 ] . V_184 ;
if ( ! V_192 [ V_2 -> V_30 ] . V_230 ) {
V_86 = - V_251 ;
goto V_252;
}
if ( V_51 -> V_208 >= V_184 )
goto V_252;
V_250 = F_194 ( V_51 -> V_184 , F_195 ( V_184 ) , V_42 ) ;
if ( V_250 == NULL ) {
V_86 = - V_41 ;
goto V_252;
}
memset ( ( char * ) V_250 + F_195 ( V_51 -> V_208 ) , 0 ,
F_195 ( V_184 ) - F_195 ( V_51 -> V_208 ) ) ;
V_51 -> V_184 = V_250 ;
V_51 -> V_208 = V_184 ;
V_252:
F_131 () ;
return V_86 ;
}
static int V_232 ( struct V_109 * V_1 , struct V_253 * V_254 ,
int V_255 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_190 * V_190 = F_140 ( V_2 ) ;
struct V_50 * V_51 = F_2 ( V_2 ) ;
struct V_256 * V_257 = (struct V_256 * ) V_254 ;
int V_86 ;
if ( V_255 < sizeof( struct V_256 ) )
return - V_17 ;
if ( V_257 -> V_258 != V_259 )
return - V_17 ;
if ( V_257 -> V_260 ) {
if ( ! F_190 ( V_1 , V_261 ) )
return - V_262 ;
V_86 = F_193 ( V_2 ) ;
if ( V_86 )
return V_86 ;
}
if ( V_51 -> V_9 ) {
if ( V_257 -> V_263 != V_51 -> V_9 )
return - V_17 ;
} else {
V_86 = V_257 -> V_263 ?
F_156 ( V_2 , V_190 , V_257 -> V_263 ) :
F_181 ( V_1 ) ;
if ( V_86 )
return V_86 ;
}
if ( ! V_257 -> V_260 && ( V_51 -> V_184 == NULL || ! ( T_1 ) V_51 -> V_184 [ 0 ] ) )
return 0 ;
F_122 () ;
F_191 ( V_2 , V_51 -> V_214 +
F_196 ( V_257 -> V_260 ) -
F_196 ( V_51 -> V_184 [ 0 ] ) ) ;
V_51 -> V_184 [ 0 ] = ( V_51 -> V_184 [ 0 ] & ~ 0xffffffffUL ) | V_257 -> V_260 ;
F_152 ( V_2 ) ;
F_131 () ;
if ( V_51 -> V_232 && V_51 -> V_184 [ 0 ] ) {
int V_67 ;
for ( V_67 = 0 ; V_67 < V_51 -> V_208 ; V_67 ++ ) {
if ( F_40 ( V_67 , V_51 -> V_184 ) )
V_51 -> V_232 ( V_67 ) ;
}
}
return 0 ;
}
static int F_197 ( struct V_109 * V_1 , struct V_253 * V_254 ,
int V_264 , int V_3 )
{
int V_86 = 0 ;
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_50 * V_51 = F_2 ( V_2 ) ;
struct V_256 * V_257 = (struct V_256 * ) V_254 ;
if ( V_264 < sizeof( V_254 -> V_265 ) )
return - V_17 ;
if ( V_254 -> V_265 == V_266 ) {
V_2 -> V_267 = V_268 ;
V_51 -> V_150 = 0 ;
V_51 -> V_151 = 0 ;
return 0 ;
}
if ( V_254 -> V_265 != V_259 )
return - V_17 ;
if ( ( V_257 -> V_260 || V_257 -> V_263 ) &&
! F_190 ( V_1 , V_269 ) )
return - V_262 ;
if ( ! V_51 -> V_9 )
V_86 = F_181 ( V_1 ) ;
if ( V_86 == 0 ) {
V_2 -> V_267 = V_270 ;
V_51 -> V_150 = V_257 -> V_263 ;
V_51 -> V_151 = F_198 ( V_257 -> V_260 ) ;
}
return V_86 ;
}
static int F_199 ( struct V_109 * V_1 , struct V_253 * V_254 ,
int * V_255 , int V_271 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_50 * V_51 = F_2 ( V_2 ) ;
F_200 ( struct V_256 * , V_257 , V_254 ) ;
V_257 -> V_258 = V_259 ;
V_257 -> V_272 = 0 ;
* V_255 = sizeof( * V_257 ) ;
if ( V_271 ) {
V_257 -> V_263 = V_51 -> V_150 ;
V_257 -> V_260 = F_3 ( V_51 -> V_151 ) ;
} else {
V_257 -> V_263 = V_51 -> V_9 ;
V_257 -> V_260 = V_51 -> V_184 ? V_51 -> V_184 [ 0 ] : 0 ;
}
return 0 ;
}
static struct V_1 * F_201 ( struct V_1 * V_273 , T_1 V_9 )
{
struct V_1 * V_1 ;
struct V_50 * V_51 ;
V_1 = F_141 ( F_140 ( V_273 ) , V_273 -> V_30 , V_9 ) ;
if ( ! V_1 )
return F_202 ( - V_274 ) ;
V_51 = F_2 ( V_1 ) ;
if ( V_1 -> V_267 == V_270 &&
V_51 -> V_150 != F_2 ( V_273 ) -> V_9 ) {
F_111 ( V_1 ) ;
return F_202 ( - V_274 ) ;
}
return V_1 ;
}
struct V_1 * F_203 ( struct V_107 * V_275 )
{
struct V_276 * V_276 = F_204 ( V_275 ) ;
struct V_1 * V_1 ;
if ( ! F_205 ( V_276 -> V_277 ) )
return F_202 ( - V_278 ) ;
V_1 = F_206 ( V_276 ) -> V_2 ;
if ( V_1 -> V_279 != V_259 )
return F_202 ( - V_17 ) ;
F_97 ( V_1 ) ;
return V_1 ;
}
static struct V_27 * F_207 ( unsigned int V_112 ,
int V_280 )
{
struct V_27 * V_28 ;
void * V_143 ;
if ( V_112 <= V_281 || V_280 )
return F_99 ( V_112 , V_70 ) ;
V_112 = F_208 ( V_112 ) +
F_208 ( sizeof( struct V_282 ) ) ;
V_143 = F_209 ( V_112 ) ;
if ( V_143 == NULL )
return NULL ;
V_28 = F_210 ( V_143 , V_112 ) ;
if ( V_28 == NULL )
F_48 ( V_143 ) ;
else {
V_28 -> V_283 = 0 ;
V_28 -> V_146 = V_147 ;
}
return V_28 ;
}
int F_211 ( struct V_1 * V_2 , struct V_27 * V_28 ,
long * V_284 , struct V_1 * V_273 )
{
struct V_50 * V_51 ;
V_51 = F_2 ( V_2 ) ;
if ( ( F_57 ( & V_2 -> V_178 ) > V_2 -> V_285 ||
F_40 ( V_53 , & V_51 -> V_54 ) ) &&
! F_42 ( V_28 ) ) {
F_125 ( V_60 , V_186 ) ;
if ( ! * V_284 ) {
if ( ! V_273 || F_1 ( V_273 ) )
F_34 ( V_2 ) ;
F_111 ( V_2 ) ;
F_101 ( V_28 ) ;
return - V_286 ;
}
F_129 ( V_287 ) ;
F_212 ( & V_51 -> V_60 , & V_60 ) ;
if ( ( F_57 ( & V_2 -> V_178 ) > V_2 -> V_285 ||
F_40 ( V_53 , & V_51 -> V_54 ) ) &&
! F_120 ( V_2 , V_181 ) )
* V_284 = F_213 ( * V_284 ) ;
F_129 ( V_189 ) ;
F_130 ( & V_51 -> V_60 , & V_60 ) ;
F_111 ( V_2 ) ;
if ( F_214 ( V_186 ) ) {
F_101 ( V_28 ) ;
return F_215 ( * V_284 ) ;
}
return 1 ;
}
F_115 ( V_28 , V_2 ) ;
return 0 ;
}
static int F_216 ( struct V_1 * V_2 , struct V_27 * V_28 )
{
int V_66 = V_28 -> V_66 ;
F_29 ( V_28 ) ;
#ifdef F_110
if ( F_42 ( V_28 ) )
F_104 ( V_2 , V_28 ) ;
else if ( F_44 ( V_2 ) )
F_108 ( V_2 , V_28 ) ;
else
#endif
F_217 ( & V_2 -> V_59 , V_28 ) ;
V_2 -> V_288 ( V_2 ) ;
return V_66 ;
}
int F_218 ( struct V_1 * V_2 , struct V_27 * V_28 )
{
int V_66 = F_216 ( V_2 , V_28 ) ;
F_111 ( V_2 ) ;
return V_66 ;
}
void F_219 ( struct V_1 * V_2 , struct V_27 * V_28 )
{
F_101 ( V_28 ) ;
F_111 ( V_2 ) ;
}
static struct V_27 * F_220 ( struct V_27 * V_28 , T_2 V_289 )
{
int V_290 ;
F_65 ( V_28 -> V_2 != NULL ) ;
if ( F_42 ( V_28 ) )
return V_28 ;
V_290 = V_28 -> V_144 - V_28 -> V_145 ;
if ( F_47 ( V_28 -> V_100 ) || V_290 * 2 < V_28 -> V_177 )
return V_28 ;
if ( F_221 ( V_28 ) ) {
struct V_27 * V_40 = F_22 ( V_28 , V_289 ) ;
if ( ! V_40 )
return V_28 ;
F_222 ( V_28 ) ;
V_28 = V_40 ;
}
if ( ! F_223 ( V_28 , 0 , - V_290 , V_289 ) )
V_28 -> V_177 -= V_290 ;
return V_28 ;
}
static int F_224 ( struct V_1 * V_2 , struct V_27 * V_28 ,
struct V_1 * V_273 )
{
int V_26 ;
struct V_50 * V_51 = F_2 ( V_2 ) ;
V_26 = - V_274 ;
if ( V_51 -> V_291 != NULL ) {
V_26 = V_28 -> V_66 ;
F_115 ( V_28 , V_2 ) ;
F_43 ( V_28 ) . V_2 = V_273 ;
F_33 ( V_2 , V_273 , V_28 ) ;
V_51 -> V_291 ( V_28 ) ;
F_222 ( V_28 ) ;
} else {
F_101 ( V_28 ) ;
}
F_111 ( V_2 ) ;
return V_26 ;
}
int F_103 ( struct V_1 * V_273 , struct V_27 * V_28 ,
T_1 V_9 , int V_292 )
{
struct V_1 * V_2 ;
int V_86 ;
long V_284 ;
V_28 = F_220 ( V_28 , F_225 () ) ;
V_284 = F_226 ( V_273 , V_292 ) ;
V_239:
V_2 = F_201 ( V_273 , V_9 ) ;
if ( F_227 ( V_2 ) ) {
F_101 ( V_28 ) ;
return F_228 ( V_2 ) ;
}
if ( F_1 ( V_2 ) )
return F_224 ( V_2 , V_28 , V_273 ) ;
if ( F_229 ( V_2 , V_28 ) ) {
V_86 = V_28 -> V_66 ;
F_101 ( V_28 ) ;
F_111 ( V_2 ) ;
return V_86 ;
}
V_86 = F_211 ( V_2 , V_28 , & V_284 , V_273 ) ;
if ( V_86 == 1 )
goto V_239;
if ( V_86 )
return V_86 ;
return F_218 ( V_2 , V_28 ) ;
}
struct V_27 * F_230 ( struct V_1 * V_273 , unsigned int V_112 ,
T_1 V_150 , T_2 V_293 )
{
#ifdef F_110
struct V_1 * V_2 = NULL ;
struct V_27 * V_28 ;
struct V_82 * V_83 ;
struct V_122 * V_123 ;
unsigned int V_154 ;
V_2 = F_201 ( V_273 , V_150 ) ;
if ( F_227 ( V_2 ) )
goto V_24;
V_83 = & F_2 ( V_2 ) -> V_62 ;
if ( V_83 -> V_63 == NULL )
goto V_294;
if ( V_83 -> V_101 - V_93 < V_112 )
goto V_294;
V_28 = F_96 ( V_293 ) ;
if ( V_28 == NULL )
goto V_80;
F_61 ( & V_2 -> V_59 . V_98 ) ;
if ( V_83 -> V_63 == NULL )
goto V_295;
V_154 = V_83 -> V_101 - V_93 ;
if ( V_154 < V_112 )
goto V_295;
F_84 ( V_83 ) ;
V_123 = F_81 ( V_83 , V_135 ) ;
if ( V_123 == NULL )
goto V_296;
F_90 ( V_28 , V_2 , V_83 , V_123 ) ;
F_77 ( V_123 , V_162 ) ;
F_36 ( & V_83 -> V_90 ) ;
F_83 ( V_83 ) ;
F_64 ( & V_2 -> V_59 . V_98 ) ;
return V_28 ;
V_296:
F_101 ( V_28 ) ;
F_64 ( & V_2 -> V_59 . V_98 ) ;
F_34 ( V_2 ) ;
V_80:
F_111 ( V_2 ) ;
return NULL ;
V_295:
F_101 ( V_28 ) ;
F_64 ( & V_2 -> V_59 . V_98 ) ;
V_294:
F_111 ( V_2 ) ;
V_24:
#endif
return F_99 ( V_112 , V_293 ) ;
}
int F_231 ( struct V_1 * V_2 , unsigned int V_5 )
{
int V_297 = 0 ;
struct V_207 * V_207 ;
F_178 ( ! F_1 ( V_2 ) ) ;
F_30 () ;
V_207 = F_232 ( V_192 [ V_2 -> V_30 ] . V_207 ) ;
if ( V_207 && V_5 - 1 < V_192 [ V_2 -> V_30 ] . V_184 )
V_297 = F_40 ( V_5 - 1 , V_207 -> V_209 ) ;
F_32 () ;
return V_297 ;
}
static int F_233 ( struct V_1 * V_2 , struct V_27 * V_28 )
{
struct V_50 * V_51 = F_2 ( V_2 ) ;
if ( F_57 ( & V_2 -> V_178 ) <= V_2 -> V_285 &&
! F_40 ( V_53 , & V_51 -> V_54 ) ) {
F_115 ( V_28 , V_2 ) ;
F_216 ( V_2 , V_28 ) ;
return F_57 ( & V_2 -> V_178 ) > ( V_2 -> V_285 >> 1 ) ;
}
return - 1 ;
}
static int F_234 ( struct V_1 * V_2 ,
struct V_298 * V_299 )
{
struct V_50 * V_51 = F_2 ( V_2 ) ;
int V_300 ;
if ( V_299 -> V_301 == V_2 )
goto V_24;
if ( V_51 -> V_9 == V_299 -> V_9 || V_299 -> V_5 - 1 >= V_51 -> V_208 ||
! F_40 ( V_299 -> V_5 - 1 , V_51 -> V_184 ) )
goto V_24;
if ( ! F_139 ( F_140 ( V_2 ) , V_299 -> V_190 ) )
goto V_24;
if ( V_299 -> V_302 ) {
F_34 ( V_2 ) ;
goto V_24;
}
F_97 ( V_2 ) ;
if ( V_299 -> V_303 == NULL ) {
if ( F_221 ( V_299 -> V_28 ) ) {
V_299 -> V_303 = F_22 ( V_299 -> V_28 , V_299 -> V_289 ) ;
} else {
V_299 -> V_303 = F_235 ( V_299 -> V_28 ) ;
F_236 ( V_299 -> V_303 ) ;
}
}
if ( V_299 -> V_303 == NULL ) {
F_34 ( V_2 ) ;
V_299 -> V_302 = 1 ;
if ( V_51 -> V_3 & V_304 )
V_299 -> V_305 = 1 ;
} else if ( V_299 -> V_306 && V_299 -> V_306 ( V_2 , V_299 -> V_303 , V_299 -> V_307 ) ) {
F_101 ( V_299 -> V_303 ) ;
V_299 -> V_303 = NULL ;
} else if ( F_229 ( V_2 , V_299 -> V_303 ) ) {
F_101 ( V_299 -> V_303 ) ;
V_299 -> V_303 = NULL ;
} else if ( ( V_300 = F_233 ( V_2 , V_299 -> V_303 ) ) < 0 ) {
F_34 ( V_2 ) ;
if ( V_51 -> V_3 & V_304 )
V_299 -> V_305 = 1 ;
} else {
V_299 -> V_308 |= V_300 ;
V_299 -> V_309 = 1 ;
V_299 -> V_303 = NULL ;
}
F_111 ( V_2 ) ;
V_24:
return 0 ;
}
int F_237 ( struct V_1 * V_273 , struct V_27 * V_28 , T_1 V_9 ,
T_1 V_5 , T_2 V_289 ,
int (* F_238)( struct V_1 * V_310 , struct V_27 * V_28 , void * V_143 ) ,
void * V_311 )
{
struct V_190 * V_190 = F_140 ( V_273 ) ;
struct V_298 V_312 ;
struct V_1 * V_2 ;
V_28 = F_220 ( V_28 , V_289 ) ;
V_312 . V_301 = V_273 ;
V_312 . V_190 = V_190 ;
V_312 . V_9 = V_9 ;
V_312 . V_5 = V_5 ;
V_312 . V_302 = 0 ;
V_312 . V_305 = 0 ;
V_312 . V_308 = 0 ;
V_312 . V_309 = 0 ;
V_312 . V_289 = V_289 ;
V_312 . V_28 = V_28 ;
V_312 . V_303 = NULL ;
V_312 . V_306 = F_238 ;
V_312 . V_307 = V_311 ;
F_133 () ;
F_155 (sk, &nl_table[ssk->sk_protocol].mc_list)
F_234 ( V_2 , & V_312 ) ;
F_222 ( V_28 ) ;
F_136 () ;
if ( V_312 . V_305 ) {
F_101 ( V_312 . V_303 ) ;
return - V_56 ;
}
F_222 ( V_312 . V_303 ) ;
if ( V_312 . V_309 ) {
if ( V_312 . V_308 && ( V_289 & V_313 ) )
F_239 () ;
return 0 ;
}
return - V_314 ;
}
int F_102 ( struct V_1 * V_273 , struct V_27 * V_28 , T_1 V_9 ,
T_1 V_5 , T_2 V_289 )
{
return F_237 ( V_273 , V_28 , V_9 , V_5 , V_289 ,
NULL , NULL ) ;
}
static int F_240 ( struct V_1 * V_2 , struct V_315 * V_299 )
{
struct V_50 * V_51 = F_2 ( V_2 ) ;
int V_26 = 0 ;
if ( V_2 == V_299 -> V_301 )
goto V_24;
if ( ! F_139 ( F_140 ( V_2 ) , F_140 ( V_299 -> V_301 ) ) )
goto V_24;
if ( V_51 -> V_9 == V_299 -> V_9 || V_299 -> V_5 - 1 >= V_51 -> V_208 ||
! F_40 ( V_299 -> V_5 - 1 , V_51 -> V_184 ) )
goto V_24;
if ( V_299 -> V_316 == V_56 && V_51 -> V_3 & V_52 ) {
V_26 = 1 ;
goto V_24;
}
V_2 -> V_55 = V_299 -> V_316 ;
V_2 -> V_57 ( V_2 ) ;
V_24:
return V_26 ;
}
int F_241 ( struct V_1 * V_273 , T_1 V_9 , T_1 V_5 , int V_316 )
{
struct V_315 V_312 ;
struct V_1 * V_2 ;
int V_26 = 0 ;
V_312 . V_301 = V_273 ;
V_312 . V_9 = V_9 ;
V_312 . V_5 = V_5 ;
V_312 . V_316 = - V_316 ;
F_134 ( & T_4 ) ;
F_155 (sk, &nl_table[ssk->sk_protocol].mc_list)
V_26 += F_240 ( V_2 , & V_312 ) ;
F_135 ( & T_4 ) ;
return V_26 ;
}
static void F_242 ( struct V_50 * V_51 ,
unsigned int V_5 ,
int V_317 )
{
int V_236 , V_318 = ! ! V_317 , V_214 ;
V_236 = F_40 ( V_5 - 1 , V_51 -> V_184 ) ;
V_214 = V_51 -> V_214 - V_236 + V_318 ;
if ( V_318 )
F_243 ( V_5 - 1 , V_51 -> V_184 ) ;
else
F_244 ( V_5 - 1 , V_51 -> V_184 ) ;
F_191 ( & V_51 -> V_2 , V_214 ) ;
F_152 ( & V_51 -> V_2 ) ;
}
static int F_245 ( struct V_109 * V_1 , int V_319 , int V_320 ,
char T_7 * V_321 , unsigned int V_322 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_50 * V_51 = F_2 ( V_2 ) ;
unsigned int V_300 = 0 ;
int V_86 ;
if ( V_319 != V_323 )
return - V_324 ;
if ( V_320 != V_325 && V_320 != V_326 &&
V_322 >= sizeof( int ) &&
F_246 ( V_300 , ( unsigned int T_7 * ) V_321 ) )
return - V_327 ;
switch ( V_320 ) {
case V_328 :
if ( V_300 )
V_51 -> V_3 |= V_329 ;
else
V_51 -> V_3 &= ~ V_329 ;
V_86 = 0 ;
break;
case V_330 :
case V_331 : {
if ( ! F_190 ( V_1 , V_261 ) )
return - V_262 ;
V_86 = F_193 ( V_2 ) ;
if ( V_86 )
return V_86 ;
if ( ! V_300 || V_300 - 1 >= V_51 -> V_208 )
return - V_17 ;
F_122 () ;
F_242 ( V_51 , V_300 ,
V_320 == V_330 ) ;
F_131 () ;
if ( V_51 -> V_232 )
V_51 -> V_232 ( V_300 ) ;
V_86 = 0 ;
break;
}
case V_332 :
if ( V_300 )
V_51 -> V_3 |= V_304 ;
else
V_51 -> V_3 &= ~ V_304 ;
V_86 = 0 ;
break;
case V_333 :
if ( V_300 ) {
V_51 -> V_3 |= V_52 ;
F_39 ( V_53 , & V_51 -> V_54 ) ;
F_41 ( & V_51 -> V_60 ) ;
} else {
V_51 -> V_3 &= ~ V_52 ;
}
V_86 = 0 ;
break;
#ifdef F_110
case V_325 :
case V_326 : {
struct V_76 V_77 ;
if ( ! F_247 ( V_248 ) )
return - V_262 ;
if ( V_322 < sizeof( V_77 ) )
return - V_17 ;
if ( F_248 ( & V_77 , V_321 , sizeof( V_77 ) ) )
return - V_327 ;
V_86 = F_56 ( V_2 , & V_77 , false ,
V_320 == V_326 ) ;
break;
}
#endif
default:
V_86 = - V_324 ;
}
return V_86 ;
}
static int F_249 ( struct V_109 * V_1 , int V_319 , int V_320 ,
char T_7 * V_321 , int T_7 * V_322 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_50 * V_51 = F_2 ( V_2 ) ;
int V_66 , V_300 , V_86 ;
if ( V_319 != V_323 )
return - V_324 ;
if ( F_246 ( V_66 , V_322 ) )
return - V_327 ;
if ( V_66 < 0 )
return - V_17 ;
switch ( V_320 ) {
case V_328 :
if ( V_66 < sizeof( int ) )
return - V_17 ;
V_66 = sizeof( int ) ;
V_300 = V_51 -> V_3 & V_329 ? 1 : 0 ;
if ( F_250 ( V_66 , V_322 ) ||
F_250 ( V_300 , V_321 ) )
return - V_327 ;
V_86 = 0 ;
break;
case V_332 :
if ( V_66 < sizeof( int ) )
return - V_17 ;
V_66 = sizeof( int ) ;
V_300 = V_51 -> V_3 & V_304 ? 1 : 0 ;
if ( F_250 ( V_66 , V_322 ) ||
F_250 ( V_300 , V_321 ) )
return - V_327 ;
V_86 = 0 ;
break;
case V_333 :
if ( V_66 < sizeof( int ) )
return - V_17 ;
V_66 = sizeof( int ) ;
V_300 = V_51 -> V_3 & V_52 ? 1 : 0 ;
if ( F_250 ( V_66 , V_322 ) ||
F_250 ( V_300 , V_321 ) )
return - V_327 ;
V_86 = 0 ;
break;
default:
V_86 = - V_324 ;
}
return V_86 ;
}
static void F_251 ( struct V_148 * V_149 , struct V_27 * V_28 )
{
struct V_334 V_312 ;
V_312 . V_5 = F_43 ( V_28 ) . V_151 ;
F_252 ( V_149 , V_323 , V_328 , sizeof( V_312 ) , & V_312 ) ;
}
static int F_253 ( struct V_335 * V_335 , struct V_109 * V_1 ,
struct V_148 * V_149 , T_5 V_66 )
{
struct V_152 * V_153 = F_254 ( V_335 ) ;
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_50 * V_51 = F_2 ( V_2 ) ;
F_200 ( struct V_256 * , V_254 , V_149 -> V_336 ) ;
T_1 V_150 ;
T_1 V_151 ;
struct V_27 * V_28 ;
int V_86 ;
struct V_337 V_164 ;
T_1 V_338 = 0 ;
if ( V_149 -> V_159 & V_339 )
return - V_340 ;
if ( NULL == V_153 -> V_164 )
V_153 -> V_164 = & V_164 ;
V_86 = F_255 ( V_1 , V_149 , V_153 -> V_164 , true ) ;
if ( V_86 < 0 )
return V_86 ;
if ( V_149 -> V_341 ) {
V_86 = - V_17 ;
if ( V_254 -> V_258 != V_259 )
goto V_24;
V_150 = V_254 -> V_263 ;
V_151 = F_198 ( V_254 -> V_260 ) ;
V_86 = - V_262 ;
if ( ( V_151 || V_150 ) &&
! F_190 ( V_1 , V_269 ) )
goto V_24;
V_338 |= V_245 ;
} else {
V_150 = V_51 -> V_150 ;
V_151 = V_51 -> V_151 ;
}
if ( ! V_51 -> V_9 ) {
V_86 = F_181 ( V_1 ) ;
if ( V_86 )
goto V_24;
}
if ( F_45 ( V_2 ) &&
V_149 -> V_342 -> V_343 == NULL ) {
V_86 = F_92 ( V_2 , V_149 , V_150 , V_151 ,
V_153 ) ;
goto V_24;
}
V_86 = - V_344 ;
if ( V_66 > V_2 -> V_345 - 32 )
goto V_24;
V_86 = - V_56 ;
V_28 = F_207 ( V_66 , V_151 ) ;
if ( V_28 == NULL )
goto V_24;
F_43 ( V_28 ) . V_9 = V_51 -> V_9 ;
F_43 ( V_28 ) . V_151 = V_151 ;
F_43 ( V_28 ) . V_163 = V_153 -> V_164 -> V_163 ;
F_43 ( V_28 ) . V_3 = V_338 ;
V_86 = - V_327 ;
if ( F_256 ( F_257 ( V_28 , V_66 ) , V_149 -> V_342 , V_66 ) ) {
F_101 ( V_28 ) ;
goto V_24;
}
V_86 = F_100 ( V_2 , V_28 ) ;
if ( V_86 ) {
F_101 ( V_28 ) ;
goto V_24;
}
if ( V_151 ) {
F_36 ( & V_28 -> V_165 ) ;
F_102 ( V_2 , V_28 , V_150 , V_151 , V_70 ) ;
}
V_86 = F_103 ( V_2 , V_28 , V_150 , V_149 -> V_159 & V_160 ) ;
V_24:
F_258 ( V_153 -> V_164 ) ;
return V_86 ;
}
static int F_259 ( struct V_335 * V_335 , struct V_109 * V_1 ,
struct V_148 * V_149 , T_5 V_66 ,
int V_3 )
{
struct V_152 * V_153 = F_254 ( V_335 ) ;
struct V_337 V_164 ;
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_50 * V_51 = F_2 ( V_2 ) ;
int V_346 = V_3 & V_160 ;
T_5 V_347 ;
struct V_27 * V_28 , * V_348 ;
int V_86 , V_26 ;
if ( V_3 & V_339 )
return - V_340 ;
V_347 = 0 ;
V_28 = F_260 ( V_2 , V_3 , V_346 , & V_86 ) ;
if ( V_28 == NULL )
goto V_24;
V_348 = V_28 ;
#ifdef F_261
if ( F_7 ( F_113 ( V_28 ) -> V_349 ) ) {
if ( V_3 & V_350 )
V_348 = F_113 ( V_28 ) -> V_349 ;
}
#endif
V_51 -> V_351 = F_262 ( V_51 -> V_351 , V_66 ) ;
V_51 -> V_351 = F_263 ( T_5 , V_51 -> V_351 ,
16384 ) ;
V_347 = V_348 -> V_66 ;
if ( V_66 < V_347 ) {
V_149 -> V_159 |= V_352 ;
V_347 = V_66 ;
}
F_264 ( V_348 ) ;
V_86 = F_265 ( V_348 , 0 , V_149 -> V_342 , V_347 ) ;
if ( V_149 -> V_336 ) {
F_200 ( struct V_256 * , V_254 , V_149 -> V_336 ) ;
V_254 -> V_258 = V_259 ;
V_254 -> V_272 = 0 ;
V_254 -> V_263 = F_43 ( V_28 ) . V_9 ;
V_254 -> V_260 = F_3 ( F_43 ( V_28 ) . V_151 ) ;
V_149 -> V_341 = sizeof( * V_254 ) ;
}
if ( V_51 -> V_3 & V_329 )
F_251 ( V_149 , V_28 ) ;
if ( NULL == V_153 -> V_164 ) {
memset ( & V_164 , 0 , sizeof( V_164 ) ) ;
V_153 -> V_164 = & V_164 ;
}
V_153 -> V_164 -> V_163 = * F_266 ( V_28 ) ;
if ( V_3 & V_352 )
V_347 = V_348 -> V_66 ;
F_267 ( V_2 , V_28 ) ;
if ( V_51 -> V_138 &&
F_57 ( & V_2 -> V_178 ) <= V_2 -> V_285 / 2 ) {
V_26 = F_87 ( V_2 ) ;
if ( V_26 ) {
V_2 -> V_55 = V_26 ;
V_2 -> V_57 ( V_2 ) ;
}
}
F_268 ( V_1 , V_149 , V_153 -> V_164 , V_3 ) ;
V_24:
F_37 ( V_2 ) ;
return V_86 ? : V_347 ;
}
static void F_269 ( struct V_1 * V_2 )
{
F_270 () ;
}
struct V_1 *
F_271 ( struct V_190 * V_190 , int V_353 , struct V_21 * V_21 ,
struct V_354 * V_355 )
{
struct V_109 * V_1 ;
struct V_1 * V_2 ;
struct V_50 * V_51 ;
struct V_207 * V_207 = NULL ;
struct V_215 * V_216 = V_355 ? V_355 -> V_216 : NULL ;
unsigned int V_184 ;
F_178 ( ! V_192 ) ;
if ( V_353 < 0 || V_353 >= V_228 )
return NULL ;
if ( F_272 ( V_219 , V_226 , V_353 , & V_1 ) )
return NULL ;
if ( F_161 ( & V_356 , V_1 , V_216 , V_353 ) < 0 )
goto V_357;
V_2 = V_1 -> V_2 ;
F_273 ( V_2 , V_190 ) ;
if ( ! V_355 || V_355 -> V_184 < 32 )
V_184 = 32 ;
else
V_184 = V_355 -> V_184 ;
V_207 = F_144 ( sizeof( * V_207 ) + F_195 ( V_184 ) , V_70 ) ;
if ( ! V_207 )
goto V_358;
V_2 -> V_288 = F_269 ;
if ( V_355 && V_355 -> V_359 )
F_2 ( V_2 ) -> V_291 = V_355 -> V_359 ;
if ( F_156 ( V_2 , V_190 , 0 ) )
goto V_358;
V_51 = F_2 ( V_2 ) ;
V_51 -> V_3 |= V_4 ;
F_122 () ;
if ( ! V_192 [ V_353 ] . V_230 ) {
V_192 [ V_353 ] . V_184 = V_184 ;
F_274 ( V_192 [ V_353 ] . V_207 , V_207 ) ;
V_192 [ V_353 ] . V_216 = V_216 ;
V_192 [ V_353 ] . V_21 = V_21 ;
if ( V_355 ) {
V_192 [ V_353 ] . F_167 = V_355 -> F_167 ;
V_192 [ V_353 ] . V_3 = V_355 -> V_3 ;
if ( V_355 -> V_193 )
V_192 [ V_353 ] . V_193 = V_355 -> V_193 ;
}
V_192 [ V_353 ] . V_230 = 1 ;
} else {
F_50 ( V_207 ) ;
V_192 [ V_353 ] . V_230 ++ ;
}
F_131 () ;
return V_2 ;
V_358:
F_50 ( V_207 ) ;
F_275 ( V_2 ) ;
return NULL ;
V_357:
F_276 ( V_1 ) ;
return NULL ;
}
void
F_275 ( struct V_1 * V_2 )
{
F_277 ( V_2 ) ;
}
int F_278 ( struct V_1 * V_2 , unsigned int V_184 )
{
struct V_207 * V_318 , * V_236 ;
struct V_191 * V_206 = & V_192 [ V_2 -> V_30 ] ;
if ( V_184 < 32 )
V_184 = 32 ;
if ( F_195 ( V_206 -> V_184 ) < F_195 ( V_184 ) ) {
V_318 = F_144 ( sizeof( * V_318 ) + F_195 ( V_184 ) , V_42 ) ;
if ( ! V_318 )
return - V_41 ;
V_236 = F_153 ( V_206 -> V_207 ) ;
memcpy ( V_318 -> V_209 , V_236 -> V_209 , F_195 ( V_206 -> V_184 ) ) ;
F_274 ( V_206 -> V_207 , V_318 ) ;
F_180 ( V_236 , V_237 ) ;
}
V_206 -> V_184 = V_184 ;
return 0 ;
}
int F_279 ( struct V_1 * V_2 , unsigned int V_184 )
{
int V_86 ;
F_122 () ;
V_86 = F_278 ( V_2 , V_184 ) ;
F_131 () ;
return V_86 ;
}
void F_280 ( struct V_1 * V_360 , unsigned int V_5 )
{
struct V_1 * V_2 ;
struct V_191 * V_206 = & V_192 [ V_360 -> V_30 ] ;
F_155 (sk, &tbl->mc_list)
F_242 ( F_2 ( V_2 ) , V_5 , 0 ) ;
}
struct V_361 *
F_281 ( struct V_27 * V_28 , T_1 V_9 , T_1 V_362 , int type , int V_66 , int V_3 )
{
struct V_361 * V_363 ;
int V_112 = F_282 ( V_66 ) ;
V_363 = (struct V_361 * ) F_257 ( V_28 , F_283 ( V_112 ) ) ;
V_363 -> V_364 = type ;
V_363 -> V_365 = V_112 ;
V_363 -> V_366 = V_3 ;
V_363 -> V_367 = V_9 ;
V_363 -> V_368 = V_362 ;
if ( ! F_284 ( V_112 ) || F_283 ( V_112 ) - V_112 != 0 )
memset ( F_285 ( V_363 ) + V_66 , 0 , F_283 ( V_112 ) - V_112 ) ;
return V_363 ;
}
static int F_87 ( struct V_1 * V_2 )
{
struct V_50 * V_51 = F_2 ( V_2 ) ;
struct V_369 * V_179 ;
struct V_27 * V_28 = NULL ;
struct V_361 * V_363 ;
int V_66 , V_86 = - V_56 ;
int V_370 ;
F_60 ( V_51 -> V_216 ) ;
if ( ! V_51 -> V_138 ) {
V_86 = - V_17 ;
goto V_371;
}
V_179 = & V_51 -> V_179 ;
V_370 = F_286 ( int , V_179 -> V_372 , V_281 ) ;
if ( ! F_44 ( V_2 ) &&
F_57 ( & V_2 -> V_178 ) >= V_2 -> V_285 )
goto V_371;
if ( V_370 < V_51 -> V_351 ) {
V_28 = F_230 ( V_2 ,
V_51 -> V_351 ,
V_51 -> V_9 ,
V_70 |
V_73 |
V_74 ) ;
if ( V_28 )
F_287 ( V_28 , F_288 ( V_28 ) -
V_51 -> V_351 ) ;
}
if ( ! V_28 )
V_28 = F_230 ( V_2 , V_370 , V_51 -> V_9 ,
V_70 ) ;
if ( ! V_28 )
goto V_371;
F_115 ( V_28 , V_2 ) ;
V_66 = V_179 -> V_373 ( V_28 , V_179 ) ;
if ( V_66 > 0 ) {
F_66 ( V_51 -> V_216 ) ;
if ( F_229 ( V_2 , V_28 ) )
F_101 ( V_28 ) ;
else
F_216 ( V_2 , V_28 ) ;
return 0 ;
}
V_363 = F_289 ( V_28 , V_179 , V_374 , sizeof( V_66 ) , V_375 ) ;
if ( ! V_363 )
goto V_371;
F_290 ( V_179 , V_363 ) ;
memcpy ( F_285 ( V_363 ) , & V_66 , sizeof( V_66 ) ) ;
if ( F_229 ( V_2 , V_28 ) )
F_101 ( V_28 ) ;
else
F_216 ( V_2 , V_28 ) ;
if ( V_179 -> V_180 )
V_179 -> V_180 ( V_179 ) ;
V_51 -> V_138 = false ;
F_66 ( V_51 -> V_216 ) ;
F_16 ( V_179 -> V_21 ) ;
F_222 ( V_179 -> V_28 ) ;
return 0 ;
V_371:
F_66 ( V_51 -> V_216 ) ;
F_101 ( V_28 ) ;
return V_86 ;
}
int F_291 ( struct V_1 * V_273 , struct V_27 * V_28 ,
const struct V_361 * V_363 ,
struct V_376 * V_377 )
{
struct V_369 * V_179 ;
struct V_1 * V_2 ;
struct V_50 * V_51 ;
int V_26 ;
if ( F_42 ( V_28 ) ) {
V_28 = F_292 ( V_28 , V_70 ) ;
if ( V_28 == NULL )
return - V_56 ;
} else
F_36 ( & V_28 -> V_165 ) ;
V_2 = F_141 ( F_140 ( V_273 ) , V_273 -> V_30 , F_43 ( V_28 ) . V_9 ) ;
if ( V_2 == NULL ) {
V_26 = - V_274 ;
goto V_378;
}
V_51 = F_2 ( V_2 ) ;
F_60 ( V_51 -> V_216 ) ;
if ( V_51 -> V_138 ) {
V_26 = - V_89 ;
goto V_379;
}
if ( ! F_170 ( V_377 -> V_21 ) ) {
V_26 = - V_229 ;
goto V_379;
}
V_179 = & V_51 -> V_179 ;
memset ( V_179 , 0 , sizeof( * V_179 ) ) ;
V_179 -> V_373 = V_377 -> V_373 ;
V_179 -> V_180 = V_377 -> V_180 ;
V_179 -> V_363 = V_363 ;
V_179 -> V_143 = V_377 -> V_143 ;
V_179 -> V_21 = V_377 -> V_21 ;
V_179 -> V_372 = V_377 -> V_372 ;
V_179 -> V_28 = V_28 ;
V_51 -> V_138 = true ;
F_66 ( V_51 -> V_216 ) ;
V_26 = F_87 ( V_2 ) ;
F_111 ( V_2 ) ;
if ( V_26 )
return V_26 ;
return - V_380 ;
V_379:
F_111 ( V_2 ) ;
F_66 ( V_51 -> V_216 ) ;
V_378:
F_101 ( V_28 ) ;
return V_26 ;
}
void F_293 ( struct V_27 * V_381 , struct V_361 * V_363 , int V_86 )
{
struct V_27 * V_28 ;
struct V_361 * V_382 ;
struct V_383 * V_384 ;
T_5 V_385 = sizeof( * V_384 ) ;
if ( V_86 )
V_385 += V_365 ( V_363 ) ;
V_28 = F_230 ( V_381 -> V_2 , F_294 ( V_385 ) ,
F_43 ( V_381 ) . V_9 , V_70 ) ;
if ( ! V_28 ) {
struct V_1 * V_2 ;
V_2 = F_141 ( F_140 ( V_381 -> V_2 ) ,
V_381 -> V_2 -> V_30 ,
F_43 ( V_381 ) . V_9 ) ;
if ( V_2 ) {
V_2 -> V_55 = V_56 ;
V_2 -> V_57 ( V_2 ) ;
F_111 ( V_2 ) ;
}
return;
}
V_382 = F_281 ( V_28 , F_43 ( V_381 ) . V_9 , V_363 -> V_368 ,
V_386 , V_385 , 0 ) ;
V_384 = F_285 ( V_382 ) ;
V_384 -> error = V_86 ;
memcpy ( & V_384 -> V_149 , V_363 , V_86 ? V_363 -> V_365 : sizeof( * V_363 ) ) ;
F_103 ( V_381 -> V_2 , V_28 , F_43 ( V_381 ) . V_9 , V_160 ) ;
}
int F_295 ( struct V_27 * V_28 , int (* V_179)( struct V_27 * ,
struct V_361 * ) )
{
struct V_361 * V_363 ;
int V_86 ;
while ( V_28 -> V_66 >= F_294 ( 0 ) ) {
int V_387 ;
V_363 = F_296 ( V_28 ) ;
V_86 = 0 ;
if ( V_363 -> V_365 < V_388 || V_28 -> V_66 < V_363 -> V_365 )
return 0 ;
if ( ! ( V_363 -> V_366 & V_389 ) )
goto V_390;
if ( V_363 -> V_364 < V_391 )
goto V_390;
V_86 = V_179 ( V_28 , V_363 ) ;
if ( V_86 == - V_380 )
goto V_392;
V_390:
if ( V_363 -> V_366 & V_393 || V_86 )
F_293 ( V_28 , V_363 , V_86 ) ;
V_392:
V_387 = F_283 ( V_363 -> V_365 ) ;
if ( V_387 > V_28 -> V_66 )
V_387 = V_28 -> V_66 ;
F_297 ( V_28 , V_387 ) ;
}
return 0 ;
}
int F_298 ( struct V_1 * V_2 , struct V_27 * V_28 , T_1 V_9 ,
unsigned int V_5 , int V_394 , T_2 V_3 )
{
int V_86 = 0 ;
if ( V_5 ) {
int V_395 = 0 ;
if ( V_394 ) {
F_36 ( & V_28 -> V_165 ) ;
V_395 = V_9 ;
}
V_86 = F_299 ( V_2 , V_28 , V_395 , V_5 , V_3 ) ;
}
if ( V_394 ) {
int V_296 ;
V_296 = F_300 ( V_2 , V_28 , V_9 ) ;
if ( ! V_86 || V_86 == - V_314 )
V_86 = V_296 ;
}
return V_86 ;
}
static struct V_1 * F_301 ( struct V_396 * V_362 , T_8 V_131 )
{
struct V_397 * V_398 = V_362 -> V_399 ;
int V_67 , V_400 ;
struct V_1 * V_401 ;
T_8 V_402 = 0 ;
for ( V_67 = 0 ; V_67 < V_228 ; V_67 ++ ) {
struct V_7 * V_8 = & V_192 [ V_67 ] . V_8 ;
for ( V_400 = 0 ; V_400 <= V_8 -> V_12 ; V_400 ++ ) {
F_142 (s, &hash->table[j]) {
if ( F_140 ( V_401 ) != F_302 ( V_362 ) )
continue;
if ( V_402 == V_131 ) {
V_398 -> V_403 = V_67 ;
V_398 -> V_404 = V_400 ;
return V_401 ;
}
++ V_402 ;
}
}
}
return NULL ;
}
static void * F_303 ( struct V_396 * V_362 , T_8 * V_131 )
__acquires( T_4 )
{
F_134 ( & T_4 ) ;
return * V_131 ? F_301 ( V_362 , * V_131 - 1 ) : V_405 ;
}
static void * F_304 ( struct V_396 * V_362 , void * V_406 , T_8 * V_131 )
{
struct V_1 * V_401 ;
struct V_397 * V_398 ;
struct V_190 * V_190 ;
int V_67 , V_400 ;
++ * V_131 ;
if ( V_406 == V_405 )
return F_301 ( V_362 , 0 ) ;
V_190 = F_302 ( V_362 ) ;
V_398 = V_362 -> V_399 ;
V_401 = V_406 ;
do {
V_401 = F_305 ( V_401 ) ;
} while ( V_401 && ! V_192 [ V_401 -> V_30 ] . V_193 ( V_190 , V_401 ) );
if ( V_401 )
return V_401 ;
V_67 = V_398 -> V_403 ;
V_400 = V_398 -> V_404 + 1 ;
do {
struct V_7 * V_8 = & V_192 [ V_67 ] . V_8 ;
for (; V_400 <= V_8 -> V_12 ; V_400 ++ ) {
V_401 = F_306 ( & V_8 -> V_10 [ V_400 ] ) ;
while ( V_401 && ! V_192 [ V_401 -> V_30 ] . V_193 ( V_190 , V_401 ) )
V_401 = F_305 ( V_401 ) ;
if ( V_401 ) {
V_398 -> V_403 = V_67 ;
V_398 -> V_404 = V_400 ;
return V_401 ;
}
}
V_400 = 0 ;
} while ( ++ V_67 < V_228 );
return NULL ;
}
static void F_307 ( struct V_396 * V_362 , void * V_406 )
__releases( T_4 )
{
F_135 ( & T_4 ) ;
}
static int F_308 ( struct V_396 * V_362 , void * V_406 )
{
if ( V_406 == V_405 ) {
F_309 ( V_362 ,
L_4
L_5 ) ;
} else {
struct V_1 * V_401 = V_406 ;
struct V_50 * V_51 = F_2 ( V_401 ) ;
F_310 ( V_362 , L_6 ,
V_401 ,
V_401 -> V_30 ,
V_51 -> V_9 ,
V_51 -> V_184 ? ( T_1 ) V_51 -> V_184 [ 0 ] : 0 ,
F_311 ( V_401 ) ,
F_312 ( V_401 ) ,
V_51 -> V_138 ,
F_57 ( & V_401 -> V_407 ) ,
F_57 ( & V_401 -> V_58 ) ,
F_313 ( V_401 )
) ;
}
return 0 ;
}
static int F_314 ( struct V_276 * V_276 , struct V_107 * V_107 )
{
return F_315 ( V_276 , V_107 , & V_408 ,
sizeof( struct V_397 ) ) ;
}
int F_316 ( struct V_409 * V_410 )
{
return F_317 ( & V_234 , V_410 ) ;
}
int F_318 ( struct V_409 * V_410 )
{
return F_319 ( & V_234 , V_410 ) ;
}
static int T_9 F_320 ( struct V_190 * V_190 )
{
#ifdef F_321
if ( ! F_322 ( L_7 , 0 , V_190 -> V_411 , & V_412 ) )
return - V_41 ;
#endif
return 0 ;
}
static void T_10 F_323 ( struct V_190 * V_190 )
{
#ifdef F_321
F_324 ( L_7 , V_190 -> V_411 ) ;
#endif
}
static void T_11 F_325 ( void )
{
struct V_207 * V_207 ;
int V_184 = 32 ;
V_207 = F_144 ( sizeof( * V_207 ) + F_195 ( V_184 ) , V_70 ) ;
if ( ! V_207 )
F_326 ( L_8 ) ;
F_122 () ;
V_192 [ V_32 ] . V_184 = V_184 ;
F_274 ( V_192 [ V_32 ] . V_207 , V_207 ) ;
V_192 [ V_32 ] . V_21 = V_413 ;
V_192 [ V_32 ] . V_230 = 1 ;
V_192 [ V_32 ] . V_3 = V_269 ;
F_131 () ;
}
static int T_11 F_327 ( void )
{
int V_67 ;
unsigned long V_414 ;
unsigned int V_65 ;
int V_86 = F_328 ( & V_220 , 0 ) ;
if ( V_86 != 0 )
goto V_24;
F_329 ( sizeof( struct V_240 ) > F_330 ( struct V_27 , V_179 ) ) ;
V_192 = F_55 ( V_228 , sizeof( * V_192 ) , V_70 ) ;
if ( ! V_192 )
goto F_326;
if ( V_415 >= ( 128 * 1024 ) )
V_414 = V_415 >> ( 21 - V_416 ) ;
else
V_414 = V_415 >> ( 23 - V_416 ) ;
V_65 = F_331 ( V_414 ) - 1 + V_416 ;
V_414 = ( 1UL << V_65 ) / sizeof( struct V_6 ) ;
V_65 = F_331 ( F_332 ( V_414 , ( unsigned long ) V_213 ) ) - 1 ;
for ( V_67 = 0 ; V_67 < V_228 ; V_67 ++ ) {
struct V_7 * V_8 = & V_192 [ V_67 ] . V_8 ;
V_8 -> V_10 = F_143 ( 1 * sizeof( * V_8 -> V_10 ) ) ;
if ( ! V_8 -> V_10 ) {
while ( V_67 -- > 0 )
F_145 ( V_192 [ V_67 ] . V_8 . V_10 ,
1 * sizeof( * V_8 -> V_10 ) ) ;
F_50 ( V_192 ) ;
goto F_326;
}
V_8 -> V_199 = V_65 ;
V_8 -> V_196 = 0 ;
V_8 -> V_12 = 0 ;
V_8 -> V_201 = V_202 ;
V_192 [ V_67 ] . V_193 = F_138 ;
}
F_333 ( & V_20 ) ;
F_325 () ;
F_334 ( & V_417 ) ;
F_335 ( & V_418 ) ;
F_336 () ;
V_24:
return V_86 ;
F_326:
F_326 ( L_9 ) ;
}
