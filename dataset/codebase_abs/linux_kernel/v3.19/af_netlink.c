static inline int F_1 ( struct V_1 * V_2 )
{
return F_2 ( V_2 ) -> V_3 & V_4 ;
}
static int F_3 ( void * V_5 )
{
if ( V_6 )
return F_4 ( & V_7 ) || F_4 ( & V_8 ) ;
return 1 ;
}
static inline T_1 F_5 ( T_1 V_9 )
{
return V_9 ? 1 << ( V_9 - 1 ) : 0 ;
}
int F_6 ( struct V_10 * V_11 )
{
if ( F_7 ( V_11 -> V_12 -> type != V_13 ) )
return - V_14 ;
F_8 ( & V_15 ) ;
F_9 ( & V_11 -> V_16 , & V_17 ) ;
F_10 ( & V_15 ) ;
F_11 ( V_11 -> V_18 ) ;
return 0 ;
}
static int F_12 ( struct V_10 * V_11 )
{
bool V_19 = false ;
struct V_10 * V_20 ;
F_8 ( & V_15 ) ;
F_13 (tmp, &netlink_tap_all, list) {
if ( V_11 == V_20 ) {
F_14 ( & V_11 -> V_16 ) ;
V_19 = true ;
goto V_21;
}
}
F_15 ( L_1 , V_11 ) ;
V_21:
F_10 ( & V_15 ) ;
if ( V_19 && V_11 -> V_18 )
F_16 ( V_11 -> V_18 ) ;
return V_19 ? 0 : - V_22 ;
}
int F_17 ( struct V_10 * V_11 )
{
int V_23 ;
V_23 = F_12 ( V_11 ) ;
F_18 () ;
return V_23 ;
}
static bool F_19 ( const struct V_24 * V_25 )
{
struct V_1 * V_2 = V_25 -> V_2 ;
switch ( V_2 -> V_26 ) {
case V_27 :
case V_28 :
case V_29 :
case V_30 :
case V_31 :
case V_32 :
case V_33 :
case V_34 :
return true ;
}
return false ;
}
static int F_20 ( struct V_24 * V_25 ,
struct V_35 * V_12 )
{
struct V_24 * V_36 ;
struct V_1 * V_2 = V_25 -> V_2 ;
int V_23 = - V_37 ;
F_21 ( V_12 ) ;
V_36 = F_22 ( V_25 , V_38 ) ;
if ( V_36 ) {
V_36 -> V_12 = V_12 ;
V_36 -> V_39 = F_23 ( ( V_40 ) V_2 -> V_26 ) ;
V_36 -> V_41 = F_1 ( V_2 ) ?
V_42 : V_43 ;
F_24 ( V_36 ) ;
V_23 = F_25 ( V_36 ) ;
if ( F_7 ( V_23 > 0 ) )
V_23 = F_26 ( V_23 ) ;
}
F_27 ( V_12 ) ;
return V_23 ;
}
static void F_28 ( struct V_24 * V_25 )
{
int V_23 ;
struct V_10 * V_20 ;
if ( ! F_19 ( V_25 ) )
return;
F_29 (tmp, &netlink_tap_all, list) {
V_23 = F_20 ( V_25 , V_20 -> V_12 ) ;
if ( F_7 ( V_23 ) )
break;
}
}
static void F_30 ( struct V_24 * V_25 )
{
F_31 () ;
if ( F_7 ( ! F_32 ( & V_17 ) ) )
F_28 ( V_25 ) ;
F_33 () ;
}
static void F_34 ( struct V_1 * V_44 , struct V_1 * V_45 ,
struct V_24 * V_25 )
{
if ( ! ( F_1 ( V_44 ) && F_1 ( V_45 ) ) )
F_30 ( V_25 ) ;
}
static void F_35 ( struct V_1 * V_2 )
{
struct V_46 * V_47 = F_2 ( V_2 ) ;
if ( ! ( V_47 -> V_3 & V_48 ) ) {
if ( ! F_36 ( V_49 , & F_2 ( V_2 ) -> V_50 ) ) {
V_2 -> V_51 = V_52 ;
V_2 -> V_53 ( V_2 ) ;
}
}
F_37 ( & V_2 -> V_54 ) ;
}
static void F_38 ( struct V_1 * V_2 )
{
struct V_46 * V_47 = F_2 ( V_2 ) ;
if ( F_39 ( & V_2 -> V_55 ) )
F_40 ( V_49 , & V_47 -> V_50 ) ;
if ( ! F_41 ( V_49 , & V_47 -> V_50 ) )
F_42 ( & V_47 -> V_56 ) ;
}
static bool F_43 ( const struct V_24 * V_25 )
{
return F_44 ( V_25 ) . V_3 & V_57 ;
}
static bool F_45 ( struct V_1 * V_2 )
{
return F_2 ( V_2 ) -> V_58 . V_59 != NULL ;
}
static bool F_46 ( struct V_1 * V_2 )
{
return F_2 ( V_2 ) -> V_60 . V_59 != NULL ;
}
static void F_47 ( void * * V_59 , unsigned int V_61 , unsigned int V_62 )
{
unsigned int V_63 ;
for ( V_63 = 0 ; V_63 < V_62 ; V_63 ++ ) {
if ( V_59 [ V_63 ] != NULL ) {
if ( F_48 ( V_59 [ V_63 ] ) )
F_49 ( V_59 [ V_63 ] ) ;
else
F_50 ( ( unsigned long ) V_59 [ V_63 ] , V_61 ) ;
}
}
F_51 ( V_59 ) ;
}
static void * F_52 ( unsigned long V_61 )
{
void * V_64 ;
T_2 V_65 = V_66 | V_67 | V_68 |
V_69 | V_70 ;
V_64 = ( void * ) F_53 ( V_65 , V_61 ) ;
if ( V_64 != NULL )
return V_64 ;
V_64 = F_54 ( ( 1 << V_61 ) * V_71 ) ;
if ( V_64 != NULL )
return V_64 ;
V_65 &= ~ V_70 ;
return ( void * ) F_53 ( V_65 , V_61 ) ;
}
static void * * F_55 ( struct V_46 * V_47 ,
struct V_72 * V_73 , unsigned int V_61 )
{
unsigned int V_74 = V_73 -> V_75 ;
unsigned int V_63 ;
void * * V_59 ;
V_59 = F_56 ( V_74 , sizeof( void * ) , V_66 ) ;
if ( V_59 == NULL )
return NULL ;
for ( V_63 = 0 ; V_63 < V_74 ; V_63 ++ ) {
V_59 [ V_63 ] = F_52 ( V_61 ) ;
if ( V_59 [ V_63 ] == NULL )
goto V_76;
}
return V_59 ;
V_76:
F_47 ( V_59 , V_61 , V_74 ) ;
return NULL ;
}
static int F_57 ( struct V_1 * V_2 , struct V_72 * V_73 ,
bool V_77 , bool V_60 )
{
struct V_46 * V_47 = F_2 ( V_2 ) ;
struct V_78 * V_79 ;
struct V_80 * V_81 ;
void * * V_59 = NULL ;
unsigned int V_61 = 0 ;
int V_82 ;
V_79 = V_60 ? & V_47 -> V_60 : & V_47 -> V_58 ;
V_81 = V_60 ? & V_2 -> V_83 : & V_2 -> V_55 ;
if ( ! V_77 ) {
if ( F_58 ( & V_47 -> V_84 ) )
return - V_85 ;
if ( F_58 ( & V_79 -> V_86 ) )
return - V_85 ;
}
if ( V_73 -> V_75 ) {
if ( V_79 -> V_59 != NULL )
return - V_85 ;
if ( ( int ) V_73 -> V_87 <= 0 )
return - V_14 ;
if ( ! F_59 ( V_73 -> V_87 ) )
return - V_14 ;
if ( V_73 -> V_88 < V_89 )
return - V_14 ;
if ( ! F_60 ( V_73 -> V_88 , V_90 ) )
return - V_14 ;
V_79 -> V_91 = V_73 -> V_87 /
V_73 -> V_88 ;
if ( V_79 -> V_91 == 0 )
return - V_14 ;
if ( V_79 -> V_91 * V_73 -> V_75 !=
V_73 -> V_92 )
return - V_14 ;
V_61 = F_61 ( V_73 -> V_87 ) ;
V_59 = F_55 ( V_47 , V_73 , V_61 ) ;
if ( V_59 == NULL )
return - V_37 ;
} else {
if ( V_73 -> V_92 )
return - V_14 ;
}
V_82 = - V_85 ;
F_62 ( & V_47 -> V_93 ) ;
if ( V_77 || F_58 ( & V_47 -> V_84 ) == 0 ) {
V_82 = 0 ;
F_63 ( & V_81 -> V_94 ) ;
V_79 -> V_95 = V_73 -> V_92 - 1 ;
V_79 -> V_96 = 0 ;
V_79 -> V_97 = V_73 -> V_88 ;
V_79 -> V_98 = V_73 -> V_87 / V_71 ;
F_64 ( V_79 -> V_99 , V_73 -> V_75 ) ;
F_64 ( V_79 -> V_100 , V_61 ) ;
F_64 ( V_79 -> V_59 , V_59 ) ;
F_65 ( V_81 ) ;
F_66 ( & V_81 -> V_94 ) ;
F_67 ( F_58 ( & V_47 -> V_84 ) ) ;
}
F_68 ( & V_47 -> V_93 ) ;
if ( V_59 )
F_47 ( V_59 , V_61 , V_73 -> V_75 ) ;
return V_82 ;
}
static void F_69 ( struct V_101 * V_102 )
{
struct V_103 * V_103 = V_102 -> V_104 ;
struct V_105 * V_1 = V_103 -> V_106 ;
struct V_1 * V_2 = V_1 -> V_2 ;
if ( V_2 )
F_37 ( & F_2 ( V_2 ) -> V_84 ) ;
}
static void F_70 ( struct V_101 * V_102 )
{
struct V_103 * V_103 = V_102 -> V_104 ;
struct V_105 * V_1 = V_103 -> V_106 ;
struct V_1 * V_2 = V_1 -> V_2 ;
if ( V_2 )
F_71 ( & F_2 ( V_2 ) -> V_84 ) ;
}
static int F_72 ( struct V_103 * V_103 , struct V_105 * V_1 ,
struct V_101 * V_102 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_46 * V_47 = F_2 ( V_2 ) ;
struct V_78 * V_79 ;
unsigned long V_107 , V_108 , V_109 ;
unsigned int V_63 ;
int V_82 = - V_14 ;
if ( V_102 -> V_110 )
return - V_14 ;
F_62 ( & V_47 -> V_93 ) ;
V_109 = 0 ;
for ( V_79 = & V_47 -> V_58 ; V_79 <= & V_47 -> V_60 ; V_79 ++ ) {
if ( V_79 -> V_59 == NULL )
continue;
V_109 += V_79 -> V_99 * V_79 -> V_98 * V_71 ;
}
if ( V_109 == 0 )
goto V_21;
V_108 = V_102 -> V_111 - V_102 -> V_112 ;
if ( V_108 != V_109 )
goto V_21;
V_107 = V_102 -> V_112 ;
for ( V_79 = & V_47 -> V_58 ; V_79 <= & V_47 -> V_60 ; V_79 ++ ) {
if ( V_79 -> V_59 == NULL )
continue;
for ( V_63 = 0 ; V_63 < V_79 -> V_99 ; V_63 ++ ) {
struct V_113 * V_113 ;
void * V_114 = V_79 -> V_59 [ V_63 ] ;
unsigned int V_115 ;
for ( V_115 = 0 ; V_115 < V_79 -> V_98 ; V_115 ++ ) {
V_113 = F_73 ( V_114 ) ;
V_82 = F_74 ( V_102 , V_107 , V_113 ) ;
if ( V_82 < 0 )
goto V_21;
V_107 += V_71 ;
V_114 += V_71 ;
}
}
}
F_37 ( & V_47 -> V_84 ) ;
V_102 -> V_116 = & V_117 ;
V_82 = 0 ;
V_21:
F_68 ( & V_47 -> V_93 ) ;
return V_82 ;
}
static void F_75 ( const struct V_118 * V_119 , unsigned int V_120 )
{
#if V_121 == 1
struct V_113 * V_122 , * V_123 ;
V_122 = F_73 ( V_119 + V_71 ) ;
V_123 = F_73 ( ( void * ) V_119 + V_89 + V_120 - 1 ) ;
while ( V_122 <= V_123 ) {
F_76 ( V_122 ) ;
V_122 ++ ;
}
#endif
}
static enum V_124 F_77 ( const struct V_118 * V_119 )
{
F_78 () ;
F_76 ( F_73 ( V_119 ) ) ;
return V_119 -> V_125 ;
}
static void F_79 ( struct V_118 * V_119 ,
enum V_124 V_126 )
{
F_80 () ;
V_119 -> V_125 = V_126 ;
F_76 ( F_73 ( V_119 ) ) ;
}
static struct V_118 *
F_81 ( const struct V_78 * V_79 , unsigned int V_127 )
{
unsigned int V_128 , V_129 ;
V_128 = V_127 / V_79 -> V_91 ;
V_129 = V_127 % V_79 -> V_91 ;
return V_79 -> V_59 [ V_128 ] + ( V_129 * V_79 -> V_97 ) ;
}
static struct V_118 *
F_82 ( const struct V_78 * V_79 , unsigned int V_127 ,
enum V_124 V_126 )
{
struct V_118 * V_119 ;
V_119 = F_81 ( V_79 , V_127 ) ;
if ( F_77 ( V_119 ) != V_126 )
return NULL ;
return V_119 ;
}
static struct V_118 *
F_83 ( const struct V_78 * V_79 ,
enum V_124 V_126 )
{
return F_82 ( V_79 , V_79 -> V_96 , V_126 ) ;
}
static struct V_118 *
F_84 ( const struct V_78 * V_79 ,
enum V_124 V_126 )
{
unsigned int V_130 ;
V_130 = V_79 -> V_96 ? V_79 -> V_96 - 1 : V_79 -> V_95 ;
return F_82 ( V_79 , V_130 , V_126 ) ;
}
static void F_85 ( struct V_78 * V_79 )
{
V_79 -> V_96 = V_79 -> V_96 != V_79 -> V_95 ? V_79 -> V_96 + 1 : 0 ;
}
static void F_86 ( struct V_78 * V_79 )
{
unsigned int V_96 = V_79 -> V_96 , V_127 = V_96 ;
const struct V_118 * V_119 ;
do {
V_119 = F_81 ( V_79 , V_127 ) ;
if ( V_119 -> V_125 == V_131 )
break;
if ( V_119 -> V_125 != V_132 )
break;
F_85 ( V_79 ) ;
} while ( V_79 -> V_96 != V_96 );
}
static bool F_87 ( struct V_46 * V_47 )
{
struct V_78 * V_79 = & V_47 -> V_58 ;
struct V_118 * V_119 ;
unsigned int V_133 ;
V_119 = F_83 ( V_79 , V_131 ) ;
if ( V_119 == NULL )
return false ;
V_133 = V_79 -> V_96 + V_79 -> V_95 / 2 ;
if ( V_133 > V_79 -> V_95 )
V_133 -= V_79 -> V_95 ;
V_119 = F_81 ( V_79 , V_133 ) ;
return V_119 -> V_125 == V_131 ;
}
static unsigned int F_88 ( struct V_103 * V_103 , struct V_105 * V_1 ,
T_3 * V_56 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_46 * V_47 = F_2 ( V_2 ) ;
unsigned int V_134 ;
int V_82 ;
if ( V_47 -> V_58 . V_59 != NULL ) {
while ( V_47 -> V_135 && F_87 ( V_47 ) ) {
V_82 = F_89 ( V_2 ) ;
if ( V_82 < 0 ) {
V_2 -> V_51 = - V_82 ;
V_2 -> V_53 ( V_2 ) ;
break;
}
}
F_38 ( V_2 ) ;
}
V_134 = F_90 ( V_103 , V_1 , V_56 ) ;
F_63 ( & V_2 -> V_55 . V_94 ) ;
if ( V_47 -> V_58 . V_59 ) {
F_86 ( & V_47 -> V_58 ) ;
if ( ! F_84 ( & V_47 -> V_58 , V_131 ) )
V_134 |= V_136 | V_137 ;
}
F_66 ( & V_2 -> V_55 . V_94 ) ;
F_63 ( & V_2 -> V_83 . V_94 ) ;
if ( V_47 -> V_60 . V_59 ) {
if ( F_83 ( & V_47 -> V_60 , V_131 ) )
V_134 |= V_138 | V_139 ;
}
F_66 ( & V_2 -> V_83 . V_94 ) ;
return V_134 ;
}
static struct V_118 * F_91 ( struct V_24 * V_25 )
{
return (struct V_118 * ) ( V_25 -> V_96 - V_89 ) ;
}
static void F_92 ( struct V_24 * V_25 , struct V_1 * V_2 ,
struct V_78 * V_79 ,
struct V_118 * V_119 )
{
unsigned int V_108 ;
void * V_140 ;
V_108 = V_79 -> V_97 - V_89 ;
V_140 = ( void * ) V_119 + V_89 ;
V_25 -> V_96 = V_140 ;
V_25 -> V_140 = V_140 ;
F_93 ( V_25 ) ;
V_25 -> V_141 = V_25 -> V_142 + V_108 ;
V_25 -> V_62 = 0 ;
V_25 -> V_143 = V_144 ;
F_44 ( V_25 ) . V_3 |= V_57 ;
F_44 ( V_25 ) . V_2 = V_2 ;
}
static int F_94 ( struct V_1 * V_2 , struct V_145 * V_146 ,
T_1 V_147 , T_1 V_148 ,
struct V_149 * V_150 )
{
struct V_46 * V_47 = F_2 ( V_2 ) ;
struct V_78 * V_79 ;
struct V_118 * V_119 ;
struct V_24 * V_25 ;
unsigned int V_151 ;
int V_82 = 0 , V_62 = 0 ;
F_62 ( & V_47 -> V_93 ) ;
V_79 = & V_47 -> V_60 ;
V_151 = V_79 -> V_97 - V_89 ;
do {
unsigned int V_120 ;
V_119 = F_83 ( V_79 , V_152 ) ;
if ( V_119 == NULL ) {
if ( ! ( V_146 -> V_153 & V_154 ) &&
F_58 ( & V_47 -> V_60 . V_86 ) )
F_95 () ;
continue;
}
V_120 = F_96 ( V_119 -> V_120 ) ;
if ( V_120 > V_151 ) {
V_82 = - V_14 ;
goto V_21;
}
F_75 ( V_119 , V_120 ) ;
V_25 = F_97 ( V_120 , V_66 ) ;
if ( V_25 == NULL ) {
V_82 = - V_52 ;
goto V_21;
}
F_98 ( V_25 , V_120 ) ;
memcpy ( V_25 -> V_140 , ( void * ) V_119 + V_89 , V_120 ) ;
F_79 ( V_119 , V_131 ) ;
F_85 ( V_79 ) ;
F_44 ( V_25 ) . V_155 = V_47 -> V_155 ;
F_44 ( V_25 ) . V_148 = V_148 ;
F_44 ( V_25 ) . V_156 = V_150 -> V_157 -> V_156 ;
V_82 = F_99 ( V_2 , V_25 ) ;
if ( V_82 ) {
F_100 ( V_25 ) ;
goto V_21;
}
if ( F_7 ( V_148 ) ) {
F_37 ( & V_25 -> V_158 ) ;
F_101 ( V_2 , V_25 , V_147 , V_148 ,
V_66 ) ;
}
V_82 = F_102 ( V_2 , V_25 , V_147 ,
V_146 -> V_153 & V_154 ) ;
if ( V_82 < 0 )
goto V_21;
V_62 += V_82 ;
} while ( V_119 != NULL ||
( ! ( V_146 -> V_153 & V_154 ) &&
F_58 ( & V_47 -> V_60 . V_86 ) ) );
if ( V_62 > 0 )
V_82 = V_62 ;
V_21:
F_68 ( & V_47 -> V_93 ) ;
return V_82 ;
}
static void F_103 ( struct V_1 * V_2 , struct V_24 * V_25 )
{
struct V_118 * V_119 ;
V_119 = F_91 ( V_25 ) ;
V_119 -> V_120 = V_25 -> V_62 ;
V_119 -> V_159 = F_44 ( V_25 ) . V_148 ;
V_119 -> V_160 = F_44 ( V_25 ) . V_156 . V_161 ;
V_119 -> V_162 = F_104 ( F_105 ( V_2 ) , F_44 ( V_25 ) . V_156 . V_163 ) ;
V_119 -> V_164 = F_106 ( F_105 ( V_2 ) , F_44 ( V_25 ) . V_156 . V_165 ) ;
F_75 ( V_119 , V_119 -> V_120 ) ;
F_79 ( V_119 , V_152 ) ;
F_44 ( V_25 ) . V_3 |= V_166 ;
F_100 ( V_25 ) ;
}
static void F_107 ( struct V_1 * V_2 , struct V_24 * V_25 )
{
struct V_46 * V_47 = F_2 ( V_2 ) ;
struct V_78 * V_79 = & V_47 -> V_58 ;
struct V_118 * V_119 ;
F_63 ( & V_2 -> V_55 . V_94 ) ;
V_119 = F_83 ( V_79 , V_131 ) ;
if ( V_119 == NULL ) {
F_66 ( & V_2 -> V_55 . V_94 ) ;
F_100 ( V_25 ) ;
F_35 ( V_2 ) ;
return;
}
F_85 ( V_79 ) ;
F_108 ( & V_2 -> V_55 , V_25 ) ;
F_66 ( & V_2 -> V_55 . V_94 ) ;
V_119 -> V_120 = V_25 -> V_62 ;
V_119 -> V_159 = F_44 ( V_25 ) . V_148 ;
V_119 -> V_160 = F_44 ( V_25 ) . V_156 . V_161 ;
V_119 -> V_162 = F_104 ( F_105 ( V_2 ) , F_44 ( V_25 ) . V_156 . V_163 ) ;
V_119 -> V_164 = F_106 ( F_105 ( V_2 ) , F_44 ( V_25 ) . V_156 . V_165 ) ;
F_79 ( V_119 , V_167 ) ;
}
static void V_144 ( struct V_24 * V_25 )
{
#ifdef F_109
struct V_118 * V_119 ;
struct V_78 * V_79 ;
struct V_1 * V_2 ;
if ( F_43 ( V_25 ) ) {
V_119 = F_91 ( V_25 ) ;
V_2 = F_44 ( V_25 ) . V_2 ;
if ( F_44 ( V_25 ) . V_3 & V_168 ) {
F_79 ( V_119 , V_131 ) ;
V_79 = & F_2 ( V_2 ) -> V_60 ;
} else {
if ( ! ( F_44 ( V_25 ) . V_3 & V_166 ) ) {
V_119 -> V_120 = 0 ;
F_79 ( V_119 , V_152 ) ;
}
V_79 = & F_2 ( V_2 ) -> V_58 ;
}
F_67 ( F_58 ( & V_79 -> V_86 ) == 0 ) ;
F_71 ( & V_79 -> V_86 ) ;
F_110 ( V_2 ) ;
V_25 -> V_96 = NULL ;
}
#endif
if ( F_48 ( V_25 -> V_96 ) ) {
if ( ! V_25 -> V_169 ||
! F_111 ( & ( F_112 ( V_25 ) -> V_170 ) ) )
F_49 ( V_25 -> V_96 ) ;
V_25 -> V_96 = NULL ;
}
if ( V_25 -> V_2 != NULL )
F_113 ( V_25 ) ;
}
static void F_114 ( struct V_24 * V_25 , struct V_1 * V_2 )
{
F_67 ( V_25 -> V_2 != NULL ) ;
V_25 -> V_2 = V_2 ;
V_25 -> V_143 = V_144 ;
F_115 ( V_25 -> V_171 , & V_2 -> V_172 ) ;
F_116 ( V_2 , V_25 -> V_171 ) ;
}
static void F_117 ( struct V_1 * V_2 )
{
struct V_46 * V_47 = F_2 ( V_2 ) ;
if ( V_47 -> V_135 ) {
if ( V_47 -> V_173 . V_174 )
V_47 -> V_173 . V_174 ( & V_47 -> V_173 ) ;
F_16 ( V_47 -> V_173 . V_18 ) ;
F_100 ( V_47 -> V_173 . V_25 ) ;
}
F_118 ( & V_2 -> V_55 ) ;
#ifdef F_109
if ( 1 ) {
struct V_72 V_73 ;
memset ( & V_73 , 0 , sizeof( V_73 ) ) ;
if ( V_47 -> V_58 . V_59 )
F_57 ( V_2 , & V_73 , true , false ) ;
memset ( & V_73 , 0 , sizeof( V_73 ) ) ;
if ( V_47 -> V_60 . V_59 )
F_57 ( V_2 , & V_73 , true , true ) ;
}
#endif
if ( ! F_119 ( V_2 , V_175 ) ) {
F_120 ( V_176 L_2 , V_2 ) ;
return;
}
F_67 ( F_58 ( & V_2 -> V_172 ) ) ;
F_67 ( F_58 ( & V_2 -> V_177 ) ) ;
F_67 ( F_2 ( V_2 ) -> V_178 ) ;
}
void F_121 ( void )
__acquires( V_8 )
{
F_122 () ;
F_123 ( & V_8 ) ;
if ( F_58 ( & V_179 ) ) {
F_124 ( V_56 , V_180 ) ;
F_125 ( & V_181 , & V_56 ) ;
for (; ; ) {
F_126 ( V_182 ) ;
if ( F_58 ( & V_179 ) == 0 )
break;
F_127 ( & V_8 ) ;
F_95 () ;
F_123 ( & V_8 ) ;
}
F_128 ( V_183 ) ;
F_129 ( & V_181 , & V_56 ) ;
}
}
void F_130 ( void )
__releases( V_8 )
{
F_127 ( & V_8 ) ;
F_131 ( & V_181 ) ;
}
static inline void
F_132 ( void )
{
F_133 ( & V_8 ) ;
F_37 ( & V_179 ) ;
F_134 ( & V_8 ) ;
}
static inline void
F_135 ( void )
{
if ( F_136 ( & V_179 ) )
F_131 ( & V_181 ) ;
}
static bool F_137 ( void * V_184 , void * V_185 )
{
struct V_186 * V_187 = V_185 ;
struct V_1 * V_2 = V_184 ;
return F_2 ( V_2 ) -> V_155 == V_187 -> V_155 &&
F_138 ( F_139 ( V_2 ) , V_187 -> V_188 ) ;
}
static struct V_1 * F_140 ( struct V_189 * V_190 , T_1 V_155 ,
struct V_188 * V_188 )
{
struct V_186 V_185 = {
. V_188 = V_188 ,
. V_155 = V_155 ,
} ;
T_1 V_191 ;
V_191 = F_141 ( & V_190 -> V_191 , & V_155 , sizeof( V_155 ) ) ;
return F_142 ( & V_190 -> V_191 , V_191 ,
& F_137 , & V_185 ) ;
}
static struct V_1 * F_143 ( struct V_188 * V_188 , int V_39 , T_1 V_155 )
{
struct V_189 * V_190 = & V_192 [ V_39 ] ;
struct V_1 * V_2 ;
F_133 ( & V_8 ) ;
F_31 () ;
V_2 = F_140 ( V_190 , V_155 , V_188 ) ;
if ( V_2 )
F_144 ( V_2 ) ;
F_33 () ;
F_134 ( & V_8 ) ;
return V_2 ;
}
static void
F_145 ( struct V_1 * V_2 )
{
struct V_189 * V_193 = & V_192 [ V_2 -> V_26 ] ;
unsigned long V_134 ;
unsigned int V_63 ;
struct V_194 * V_194 ;
V_194 = F_146 ( V_193 -> V_194 ) ;
if ( ! V_194 )
return;
for ( V_63 = 0 ; V_63 < F_147 ( V_193 -> V_178 ) ; V_63 ++ ) {
V_134 = 0 ;
F_148 (sk, &tbl->mc_list) {
if ( V_63 < F_147 ( F_2 ( V_2 ) -> V_195 ) )
V_134 |= F_2 ( V_2 ) -> V_178 [ V_63 ] ;
}
V_194 -> V_196 [ V_63 ] = V_134 ;
}
}
static int F_149 ( struct V_1 * V_2 , struct V_188 * V_188 , T_1 V_155 )
{
struct V_189 * V_190 = & V_192 [ V_2 -> V_26 ] ;
int V_82 = - V_197 ;
F_62 ( & V_7 ) ;
if ( F_140 ( V_190 , V_155 , V_188 ) )
goto V_82;
V_82 = - V_85 ;
if ( F_2 ( V_2 ) -> V_155 )
goto V_82;
V_82 = - V_37 ;
if ( V_198 > 32 && F_7 ( V_190 -> V_191 . V_199 >= V_200 ) )
goto V_82;
F_2 ( V_2 ) -> V_155 = V_155 ;
F_144 ( V_2 ) ;
F_150 ( & V_190 -> V_191 , & F_2 ( V_2 ) -> V_201 ) ;
V_82 = 0 ;
V_82:
F_68 ( & V_7 ) ;
return V_82 ;
}
static void F_151 ( struct V_1 * V_2 )
{
struct V_189 * V_190 ;
F_62 ( & V_7 ) ;
V_190 = & V_192 [ V_2 -> V_26 ] ;
if ( F_152 ( & V_190 -> V_191 , & F_2 ( V_2 ) -> V_201 ) ) {
F_67 ( F_58 ( & V_2 -> V_202 ) == 1 ) ;
F_153 ( V_2 ) ;
}
F_68 ( & V_7 ) ;
F_121 () ;
if ( F_2 ( V_2 ) -> V_203 ) {
F_154 ( V_2 ) ;
F_145 ( V_2 ) ;
}
if ( V_2 -> V_26 == V_34 )
F_37 ( & V_204 ) ;
F_130 () ;
}
static int F_155 ( struct V_188 * V_188 , struct V_105 * V_1 ,
struct V_205 * V_206 , int V_39 )
{
struct V_1 * V_2 ;
struct V_46 * V_47 ;
V_1 -> V_207 = & V_208 ;
V_2 = F_156 ( V_188 , V_209 , V_66 , & V_210 ) ;
if ( ! V_2 )
return - V_37 ;
F_157 ( V_1 , V_2 ) ;
V_47 = F_2 ( V_2 ) ;
if ( V_206 ) {
V_47 -> V_206 = V_206 ;
} else {
V_47 -> V_206 = & V_47 -> V_211 ;
F_158 ( V_47 -> V_206 ) ;
}
F_159 ( & V_47 -> V_56 ) ;
#ifdef F_109
F_158 ( & V_47 -> V_93 ) ;
#endif
V_2 -> V_212 = F_117 ;
V_2 -> V_26 = V_39 ;
return 0 ;
}
static int F_160 ( struct V_188 * V_188 , struct V_105 * V_1 , int V_39 ,
int V_213 )
{
struct V_18 * V_18 = NULL ;
struct V_205 * V_206 ;
struct V_46 * V_47 ;
int (* F_161)( struct V_188 * V_188 , int V_9 );
void (* F_162)( struct V_188 * V_188 , int V_9 );
int V_82 = 0 ;
V_1 -> V_50 = V_214 ;
if ( V_1 -> type != V_215 && V_1 -> type != V_216 )
return - V_217 ;
if ( V_39 < 0 || V_39 >= V_218 )
return - V_219 ;
F_132 () ;
#ifdef F_163
if ( ! V_192 [ V_39 ] . V_220 ) {
F_135 () ;
F_164 ( L_3 , V_209 , V_39 ) ;
F_132 () ;
}
#endif
if ( V_192 [ V_39 ] . V_220 &&
F_165 ( V_192 [ V_39 ] . V_18 ) )
V_18 = V_192 [ V_39 ] . V_18 ;
else
V_82 = - V_219 ;
V_206 = V_192 [ V_39 ] . V_206 ;
F_161 = V_192 [ V_39 ] . F_161 ;
F_162 = V_192 [ V_39 ] . F_162 ;
F_135 () ;
if ( V_82 < 0 )
goto V_21;
V_82 = F_155 ( V_188 , V_1 , V_206 , V_39 ) ;
if ( V_82 < 0 )
goto V_221;
F_166 () ;
F_167 ( V_188 , & V_210 , 1 ) ;
F_168 () ;
V_47 = F_2 ( V_1 -> V_2 ) ;
V_47 -> V_18 = V_18 ;
V_47 -> V_222 = F_161 ;
V_47 -> V_223 = F_162 ;
V_21:
return V_82 ;
V_221:
F_16 ( V_18 ) ;
goto V_21;
}
static int F_169 ( struct V_105 * V_1 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_46 * V_47 ;
if ( ! V_2 )
return 0 ;
F_151 ( V_2 ) ;
F_170 ( V_2 ) ;
V_47 = F_2 ( V_2 ) ;
if ( V_47 -> V_223 ) {
int V_63 ;
for ( V_63 = 0 ; V_63 < V_47 -> V_195 ; V_63 ++ )
if ( F_41 ( V_63 , V_47 -> V_178 ) )
V_47 -> V_223 ( F_139 ( V_2 ) , V_63 + 1 ) ;
}
if ( V_2 -> V_26 == V_34 &&
F_111 ( & V_204 ) == 0 )
F_131 ( & V_224 ) ;
V_1 -> V_2 = NULL ;
F_171 ( & V_47 -> V_56 ) ;
F_118 ( & V_2 -> V_83 ) ;
if ( V_47 -> V_155 ) {
struct V_225 V_133 = {
. V_188 = F_139 ( V_2 ) ,
. V_39 = V_2 -> V_26 ,
. V_155 = V_47 -> V_155 ,
} ;
F_172 ( & V_226 ,
V_227 , & V_133 ) ;
}
F_16 ( V_47 -> V_18 ) ;
if ( F_1 ( V_2 ) ) {
F_121 () ;
F_173 ( V_192 [ V_2 -> V_26 ] . V_220 == 0 ) ;
if ( -- V_192 [ V_2 -> V_26 ] . V_220 == 0 ) {
struct V_194 * V_228 ;
V_228 = F_146 ( V_192 [ V_2 -> V_26 ] . V_194 ) ;
F_174 ( V_192 [ V_2 -> V_26 ] . V_194 , NULL ) ;
F_175 ( V_228 , V_229 ) ;
V_192 [ V_2 -> V_26 ] . V_18 = NULL ;
V_192 [ V_2 -> V_26 ] . F_161 = NULL ;
V_192 [ V_2 -> V_26 ] . F_162 = NULL ;
V_192 [ V_2 -> V_26 ] . V_3 = 0 ;
V_192 [ V_2 -> V_26 ] . V_220 = 0 ;
}
F_130 () ;
}
F_51 ( V_47 -> V_178 ) ;
V_47 -> V_178 = NULL ;
F_166 () ;
F_167 ( F_139 ( V_2 ) , & V_210 , - 1 ) ;
F_168 () ;
F_110 ( V_2 ) ;
return 0 ;
}
static int F_176 ( struct V_105 * V_1 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_188 * V_188 = F_139 ( V_2 ) ;
struct V_189 * V_190 = & V_192 [ V_2 -> V_26 ] ;
T_4 V_155 = F_177 ( V_180 ) ;
int V_82 ;
static T_4 V_230 = - 4097 ;
V_231:
F_178 () ;
F_121 () ;
F_31 () ;
if ( F_140 ( V_190 , V_155 , V_188 ) ) {
V_155 = V_230 -- ;
if ( V_230 > - 4097 )
V_230 = - 4097 ;
F_33 () ;
F_130 () ;
goto V_231;
}
F_33 () ;
F_130 () ;
V_82 = F_149 ( V_2 , V_188 , V_155 ) ;
if ( V_82 == - V_197 )
goto V_231;
if ( V_82 == - V_85 )
V_82 = 0 ;
return V_82 ;
}
bool F_179 ( const struct V_232 * V_233 ,
struct V_234 * V_235 , int V_236 )
{
return ( ( V_233 -> V_3 & V_237 ) ||
F_180 ( V_233 -> V_2 -> V_238 -> V_103 , V_235 , V_236 ) ) &&
F_181 ( V_235 , V_236 ) ;
}
bool F_182 ( const struct V_24 * V_25 ,
struct V_234 * V_235 , int V_236 )
{
return F_179 ( & F_44 ( V_25 ) , V_235 , V_236 ) ;
}
bool F_183 ( const struct V_24 * V_25 , int V_236 )
{
return F_182 ( V_25 , & V_239 , V_236 ) ;
}
bool F_184 ( const struct V_24 * V_25 , int V_236 )
{
return F_182 ( V_25 , F_139 ( V_25 -> V_2 ) -> V_235 , V_236 ) ;
}
static inline int F_185 ( const struct V_105 * V_1 , unsigned int V_240 )
{
return ( V_192 [ V_1 -> V_2 -> V_26 ] . V_3 & V_240 ) ||
F_181 ( F_139 ( V_1 -> V_2 ) -> V_235 , V_241 ) ;
}
static void
F_186 ( struct V_1 * V_2 , unsigned int V_203 )
{
struct V_46 * V_47 = F_2 ( V_2 ) ;
if ( V_47 -> V_203 && ! V_203 )
F_154 ( V_2 ) ;
else if ( ! V_47 -> V_203 && V_203 )
F_187 ( V_2 , & V_192 [ V_2 -> V_26 ] . V_242 ) ;
V_47 -> V_203 = V_203 ;
}
static int F_188 ( struct V_1 * V_2 )
{
struct V_46 * V_47 = F_2 ( V_2 ) ;
unsigned int V_178 ;
unsigned long * V_243 ;
int V_82 = 0 ;
F_121 () ;
V_178 = V_192 [ V_2 -> V_26 ] . V_178 ;
if ( ! V_192 [ V_2 -> V_26 ] . V_220 ) {
V_82 = - V_244 ;
goto V_245;
}
if ( V_47 -> V_195 >= V_178 )
goto V_245;
V_243 = F_189 ( V_47 -> V_178 , F_190 ( V_178 ) , V_38 ) ;
if ( V_243 == NULL ) {
V_82 = - V_37 ;
goto V_245;
}
memset ( ( char * ) V_243 + F_190 ( V_47 -> V_195 ) , 0 ,
F_190 ( V_178 ) - F_190 ( V_47 -> V_195 ) ) ;
V_47 -> V_178 = V_243 ;
V_47 -> V_195 = V_178 ;
V_245:
F_130 () ;
return V_82 ;
}
static void F_191 ( int V_9 , long unsigned int V_178 ,
struct V_1 * V_2 )
{
struct V_46 * V_47 = F_2 ( V_2 ) ;
int V_246 ;
if ( ! V_47 -> V_223 )
return;
for ( V_246 = 0 ; V_246 < V_9 ; V_246 ++ )
if ( F_41 ( V_246 , & V_178 ) )
V_47 -> V_223 ( F_139 ( V_2 ) , V_246 + 1 ) ;
}
static int V_222 ( struct V_105 * V_1 , struct V_247 * V_248 ,
int V_249 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_188 * V_188 = F_139 ( V_2 ) ;
struct V_46 * V_47 = F_2 ( V_2 ) ;
struct V_250 * V_251 = (struct V_250 * ) V_248 ;
int V_82 ;
long unsigned int V_178 = V_251 -> V_252 ;
if ( V_249 < sizeof( struct V_250 ) )
return - V_14 ;
if ( V_251 -> V_253 != V_254 )
return - V_14 ;
if ( V_178 ) {
if ( ! F_185 ( V_1 , V_255 ) )
return - V_256 ;
V_82 = F_188 ( V_2 ) ;
if ( V_82 )
return V_82 ;
}
if ( V_47 -> V_155 )
if ( V_251 -> V_257 != V_47 -> V_155 )
return - V_14 ;
if ( V_47 -> V_222 && V_178 ) {
int V_9 ;
for ( V_9 = 0 ; V_9 < V_47 -> V_195 ; V_9 ++ ) {
if ( ! F_41 ( V_9 , & V_178 ) )
continue;
V_82 = V_47 -> V_222 ( V_188 , V_9 + 1 ) ;
if ( ! V_82 )
continue;
F_191 ( V_9 , V_178 , V_2 ) ;
return V_82 ;
}
}
if ( ! V_47 -> V_155 ) {
V_82 = V_251 -> V_257 ?
F_149 ( V_2 , V_188 , V_251 -> V_257 ) :
F_176 ( V_1 ) ;
if ( V_82 ) {
F_191 ( V_47 -> V_195 , V_178 , V_2 ) ;
return V_82 ;
}
}
if ( ! V_178 && ( V_47 -> V_178 == NULL || ! ( T_1 ) V_47 -> V_178 [ 0 ] ) )
return 0 ;
F_121 () ;
F_186 ( V_2 , V_47 -> V_203 +
F_192 ( V_178 ) -
F_192 ( V_47 -> V_178 [ 0 ] ) ) ;
V_47 -> V_178 [ 0 ] = ( V_47 -> V_178 [ 0 ] & ~ 0xffffffffUL ) | V_178 ;
F_145 ( V_2 ) ;
F_130 () ;
return 0 ;
}
static int F_193 ( struct V_105 * V_1 , struct V_247 * V_248 ,
int V_258 , int V_3 )
{
int V_82 = 0 ;
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_46 * V_47 = F_2 ( V_2 ) ;
struct V_250 * V_251 = (struct V_250 * ) V_248 ;
if ( V_258 < sizeof( V_248 -> V_259 ) )
return - V_14 ;
if ( V_248 -> V_259 == V_260 ) {
V_2 -> V_261 = V_262 ;
V_47 -> V_147 = 0 ;
V_47 -> V_148 = 0 ;
return 0 ;
}
if ( V_248 -> V_259 != V_254 )
return - V_14 ;
if ( ( V_251 -> V_252 || V_251 -> V_257 ) &&
! F_185 ( V_1 , V_263 ) )
return - V_256 ;
if ( ! V_47 -> V_155 )
V_82 = F_176 ( V_1 ) ;
if ( V_82 == 0 ) {
V_2 -> V_261 = V_264 ;
V_47 -> V_147 = V_251 -> V_257 ;
V_47 -> V_148 = F_194 ( V_251 -> V_252 ) ;
}
return V_82 ;
}
static int F_195 ( struct V_105 * V_1 , struct V_247 * V_248 ,
int * V_249 , int V_265 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_46 * V_47 = F_2 ( V_2 ) ;
F_196 ( struct V_250 * , V_251 , V_248 ) ;
V_251 -> V_253 = V_254 ;
V_251 -> V_266 = 0 ;
* V_249 = sizeof( * V_251 ) ;
if ( V_265 ) {
V_251 -> V_257 = V_47 -> V_147 ;
V_251 -> V_252 = F_5 ( V_47 -> V_148 ) ;
} else {
V_251 -> V_257 = V_47 -> V_155 ;
V_251 -> V_252 = V_47 -> V_178 ? V_47 -> V_178 [ 0 ] : 0 ;
}
return 0 ;
}
static struct V_1 * F_197 ( struct V_1 * V_267 , T_1 V_155 )
{
struct V_1 * V_1 ;
struct V_46 * V_47 ;
V_1 = F_143 ( F_139 ( V_267 ) , V_267 -> V_26 , V_155 ) ;
if ( ! V_1 )
return F_198 ( - V_268 ) ;
V_47 = F_2 ( V_1 ) ;
if ( V_1 -> V_261 == V_264 &&
V_47 -> V_147 != F_2 ( V_267 ) -> V_155 ) {
F_110 ( V_1 ) ;
return F_198 ( - V_268 ) ;
}
return V_1 ;
}
struct V_1 * F_199 ( struct V_103 * V_269 )
{
struct V_270 * V_270 = F_200 ( V_269 ) ;
struct V_1 * V_1 ;
if ( ! F_201 ( V_270 -> V_271 ) )
return F_198 ( - V_272 ) ;
V_1 = F_202 ( V_270 ) -> V_2 ;
if ( V_1 -> V_273 != V_254 )
return F_198 ( - V_14 ) ;
F_144 ( V_1 ) ;
return V_1 ;
}
static struct V_24 * F_203 ( unsigned int V_108 ,
int V_274 )
{
struct V_24 * V_25 ;
void * V_140 ;
if ( V_108 <= V_275 || V_274 )
return F_97 ( V_108 , V_66 ) ;
V_108 = F_204 ( V_108 ) +
F_204 ( sizeof( struct V_276 ) ) ;
V_140 = F_205 ( V_108 ) ;
if ( V_140 == NULL )
return NULL ;
V_25 = F_206 ( V_140 , V_108 ) ;
if ( V_25 == NULL )
F_49 ( V_140 ) ;
else {
V_25 -> V_277 = 0 ;
V_25 -> V_143 = V_144 ;
}
return V_25 ;
}
int F_207 ( struct V_1 * V_2 , struct V_24 * V_25 ,
long * V_278 , struct V_1 * V_267 )
{
struct V_46 * V_47 ;
V_47 = F_2 ( V_2 ) ;
if ( ( F_58 ( & V_2 -> V_172 ) > V_2 -> V_279 ||
F_41 ( V_49 , & V_47 -> V_50 ) ) &&
! F_43 ( V_25 ) ) {
F_124 ( V_56 , V_180 ) ;
if ( ! * V_278 ) {
if ( ! V_267 || F_1 ( V_267 ) )
F_35 ( V_2 ) ;
F_110 ( V_2 ) ;
F_100 ( V_25 ) ;
return - V_280 ;
}
F_128 ( V_281 ) ;
F_208 ( & V_47 -> V_56 , & V_56 ) ;
if ( ( F_58 ( & V_2 -> V_172 ) > V_2 -> V_279 ||
F_41 ( V_49 , & V_47 -> V_50 ) ) &&
! F_119 ( V_2 , V_175 ) )
* V_278 = F_209 ( * V_278 ) ;
F_128 ( V_183 ) ;
F_129 ( & V_47 -> V_56 , & V_56 ) ;
F_110 ( V_2 ) ;
if ( F_210 ( V_180 ) ) {
F_100 ( V_25 ) ;
return F_211 ( * V_278 ) ;
}
return 1 ;
}
F_114 ( V_25 , V_2 ) ;
return 0 ;
}
static int F_212 ( struct V_1 * V_2 , struct V_24 * V_25 )
{
int V_62 = V_25 -> V_62 ;
F_30 ( V_25 ) ;
#ifdef F_109
if ( F_43 ( V_25 ) )
F_103 ( V_2 , V_25 ) ;
else if ( F_45 ( V_2 ) )
F_107 ( V_2 , V_25 ) ;
else
#endif
F_213 ( & V_2 -> V_55 , V_25 ) ;
V_2 -> V_282 ( V_2 ) ;
return V_62 ;
}
int F_214 ( struct V_1 * V_2 , struct V_24 * V_25 )
{
int V_62 = F_212 ( V_2 , V_25 ) ;
F_110 ( V_2 ) ;
return V_62 ;
}
void F_215 ( struct V_1 * V_2 , struct V_24 * V_25 )
{
F_100 ( V_25 ) ;
F_110 ( V_2 ) ;
}
static struct V_24 * F_216 ( struct V_24 * V_25 , T_2 V_283 )
{
int V_284 ;
F_67 ( V_25 -> V_2 != NULL ) ;
if ( F_43 ( V_25 ) )
return V_25 ;
V_284 = V_25 -> V_141 - V_25 -> V_142 ;
if ( F_48 ( V_25 -> V_96 ) || V_284 * 2 < V_25 -> V_171 )
return V_25 ;
if ( F_217 ( V_25 ) ) {
struct V_24 * V_36 = F_22 ( V_25 , V_283 ) ;
if ( ! V_36 )
return V_25 ;
F_218 ( V_25 ) ;
V_25 = V_36 ;
}
if ( ! F_219 ( V_25 , 0 , - V_284 , V_283 ) )
V_25 -> V_171 -= V_284 ;
return V_25 ;
}
static int F_220 ( struct V_1 * V_2 , struct V_24 * V_25 ,
struct V_1 * V_267 )
{
int V_23 ;
struct V_46 * V_47 = F_2 ( V_2 ) ;
V_23 = - V_268 ;
if ( V_47 -> V_285 != NULL ) {
V_23 = V_25 -> V_62 ;
F_114 ( V_25 , V_2 ) ;
F_44 ( V_25 ) . V_2 = V_267 ;
F_34 ( V_2 , V_267 , V_25 ) ;
V_47 -> V_285 ( V_25 ) ;
F_218 ( V_25 ) ;
} else {
F_100 ( V_25 ) ;
}
F_110 ( V_2 ) ;
return V_23 ;
}
int F_102 ( struct V_1 * V_267 , struct V_24 * V_25 ,
T_1 V_155 , int V_286 )
{
struct V_1 * V_2 ;
int V_82 ;
long V_278 ;
V_25 = F_216 ( V_25 , F_221 () ) ;
V_278 = F_222 ( V_267 , V_286 ) ;
V_231:
V_2 = F_197 ( V_267 , V_155 ) ;
if ( F_223 ( V_2 ) ) {
F_100 ( V_25 ) ;
return F_224 ( V_2 ) ;
}
if ( F_1 ( V_2 ) )
return F_220 ( V_2 , V_25 , V_267 ) ;
if ( F_225 ( V_2 , V_25 ) ) {
V_82 = V_25 -> V_62 ;
F_100 ( V_25 ) ;
F_110 ( V_2 ) ;
return V_82 ;
}
V_82 = F_207 ( V_2 , V_25 , & V_278 , V_267 ) ;
if ( V_82 == 1 )
goto V_231;
if ( V_82 )
return V_82 ;
return F_214 ( V_2 , V_25 ) ;
}
struct V_24 * F_226 ( struct V_1 * V_267 , unsigned int V_108 ,
T_1 V_147 , T_2 V_287 )
{
#ifdef F_109
struct V_1 * V_2 = NULL ;
struct V_24 * V_25 ;
struct V_78 * V_79 ;
struct V_118 * V_119 ;
unsigned int V_151 ;
V_2 = F_197 ( V_267 , V_147 ) ;
if ( F_223 ( V_2 ) )
goto V_21;
V_79 = & F_2 ( V_2 ) -> V_58 ;
if ( V_79 -> V_59 == NULL )
goto V_288;
if ( V_79 -> V_97 - V_89 < V_108 )
goto V_288;
V_25 = F_227 ( V_287 ) ;
if ( V_25 == NULL )
goto V_76;
F_63 ( & V_2 -> V_55 . V_94 ) ;
if ( V_79 -> V_59 == NULL )
goto V_289;
V_151 = V_79 -> V_97 - V_89 ;
if ( V_151 < V_108 )
goto V_289;
F_86 ( V_79 ) ;
V_119 = F_83 ( V_79 , V_131 ) ;
if ( V_119 == NULL )
goto V_290;
F_92 ( V_25 , V_2 , V_79 , V_119 ) ;
F_79 ( V_119 , V_291 ) ;
F_37 ( & V_79 -> V_86 ) ;
F_85 ( V_79 ) ;
F_66 ( & V_2 -> V_55 . V_94 ) ;
return V_25 ;
V_290:
F_100 ( V_25 ) ;
F_66 ( & V_2 -> V_55 . V_94 ) ;
F_35 ( V_2 ) ;
V_76:
F_110 ( V_2 ) ;
return NULL ;
V_289:
F_100 ( V_25 ) ;
F_66 ( & V_2 -> V_55 . V_94 ) ;
V_288:
F_110 ( V_2 ) ;
V_21:
#endif
return F_97 ( V_108 , V_287 ) ;
}
int F_228 ( struct V_1 * V_2 , unsigned int V_9 )
{
int V_292 = 0 ;
struct V_194 * V_194 ;
F_173 ( ! F_1 ( V_2 ) ) ;
F_31 () ;
V_194 = F_229 ( V_192 [ V_2 -> V_26 ] . V_194 ) ;
if ( V_194 && V_9 - 1 < V_192 [ V_2 -> V_26 ] . V_178 )
V_292 = F_41 ( V_9 - 1 , V_194 -> V_196 ) ;
F_33 () ;
return V_292 ;
}
static int F_230 ( struct V_1 * V_2 , struct V_24 * V_25 )
{
struct V_46 * V_47 = F_2 ( V_2 ) ;
if ( F_58 ( & V_2 -> V_172 ) <= V_2 -> V_279 &&
! F_41 ( V_49 , & V_47 -> V_50 ) ) {
F_114 ( V_25 , V_2 ) ;
F_212 ( V_2 , V_25 ) ;
return F_58 ( & V_2 -> V_172 ) > ( V_2 -> V_279 >> 1 ) ;
}
return - 1 ;
}
static void F_231 ( struct V_1 * V_2 ,
struct V_293 * V_294 )
{
struct V_46 * V_47 = F_2 ( V_2 ) ;
int V_295 ;
if ( V_294 -> V_296 == V_2 )
return;
if ( V_47 -> V_155 == V_294 -> V_155 || V_294 -> V_9 - 1 >= V_47 -> V_195 ||
! F_41 ( V_294 -> V_9 - 1 , V_47 -> V_178 ) )
return;
if ( ! F_138 ( F_139 ( V_2 ) , V_294 -> V_188 ) )
return;
if ( V_294 -> V_297 ) {
F_35 ( V_2 ) ;
return;
}
F_144 ( V_2 ) ;
if ( V_294 -> V_298 == NULL ) {
if ( F_217 ( V_294 -> V_25 ) ) {
V_294 -> V_298 = F_22 ( V_294 -> V_25 , V_294 -> V_283 ) ;
} else {
V_294 -> V_298 = F_232 ( V_294 -> V_25 ) ;
F_233 ( V_294 -> V_298 ) ;
}
}
if ( V_294 -> V_298 == NULL ) {
F_35 ( V_2 ) ;
V_294 -> V_297 = 1 ;
if ( V_47 -> V_3 & V_299 )
V_294 -> V_300 = 1 ;
} else if ( V_294 -> V_301 && V_294 -> V_301 ( V_2 , V_294 -> V_298 , V_294 -> V_302 ) ) {
F_100 ( V_294 -> V_298 ) ;
V_294 -> V_298 = NULL ;
} else if ( F_225 ( V_2 , V_294 -> V_298 ) ) {
F_100 ( V_294 -> V_298 ) ;
V_294 -> V_298 = NULL ;
} else if ( ( V_295 = F_230 ( V_2 , V_294 -> V_298 ) ) < 0 ) {
F_35 ( V_2 ) ;
if ( V_47 -> V_3 & V_299 )
V_294 -> V_300 = 1 ;
} else {
V_294 -> V_303 |= V_295 ;
V_294 -> V_304 = 1 ;
V_294 -> V_298 = NULL ;
}
F_110 ( V_2 ) ;
}
int F_234 ( struct V_1 * V_267 , struct V_24 * V_25 , T_1 V_155 ,
T_1 V_9 , T_2 V_283 ,
int (* F_235)( struct V_1 * V_305 , struct V_24 * V_25 , void * V_140 ) ,
void * V_306 )
{
struct V_188 * V_188 = F_139 ( V_267 ) ;
struct V_293 V_307 ;
struct V_1 * V_2 ;
V_25 = F_216 ( V_25 , V_283 ) ;
V_307 . V_296 = V_267 ;
V_307 . V_188 = V_188 ;
V_307 . V_155 = V_155 ;
V_307 . V_9 = V_9 ;
V_307 . V_297 = 0 ;
V_307 . V_300 = 0 ;
V_307 . V_303 = 0 ;
V_307 . V_304 = 0 ;
V_307 . V_283 = V_283 ;
V_307 . V_25 = V_25 ;
V_307 . V_298 = NULL ;
V_307 . V_301 = F_235 ;
V_307 . V_302 = V_306 ;
F_132 () ;
F_148 (sk, &nl_table[ssk->sk_protocol].mc_list)
F_231 ( V_2 , & V_307 ) ;
F_218 ( V_25 ) ;
F_135 () ;
if ( V_307 . V_300 ) {
F_100 ( V_307 . V_298 ) ;
return - V_52 ;
}
F_218 ( V_307 . V_298 ) ;
if ( V_307 . V_304 ) {
if ( V_307 . V_303 && ( V_283 & V_308 ) )
F_236 () ;
return 0 ;
}
return - V_309 ;
}
int F_101 ( struct V_1 * V_267 , struct V_24 * V_25 , T_1 V_155 ,
T_1 V_9 , T_2 V_283 )
{
return F_234 ( V_267 , V_25 , V_155 , V_9 , V_283 ,
NULL , NULL ) ;
}
static int F_237 ( struct V_1 * V_2 , struct V_310 * V_294 )
{
struct V_46 * V_47 = F_2 ( V_2 ) ;
int V_23 = 0 ;
if ( V_2 == V_294 -> V_296 )
goto V_21;
if ( ! F_138 ( F_139 ( V_2 ) , F_139 ( V_294 -> V_296 ) ) )
goto V_21;
if ( V_47 -> V_155 == V_294 -> V_155 || V_294 -> V_9 - 1 >= V_47 -> V_195 ||
! F_41 ( V_294 -> V_9 - 1 , V_47 -> V_178 ) )
goto V_21;
if ( V_294 -> V_311 == V_52 && V_47 -> V_3 & V_48 ) {
V_23 = 1 ;
goto V_21;
}
V_2 -> V_51 = V_294 -> V_311 ;
V_2 -> V_53 ( V_2 ) ;
V_21:
return V_23 ;
}
int F_238 ( struct V_1 * V_267 , T_1 V_155 , T_1 V_9 , int V_311 )
{
struct V_310 V_307 ;
struct V_1 * V_2 ;
int V_23 = 0 ;
V_307 . V_296 = V_267 ;
V_307 . V_155 = V_155 ;
V_307 . V_9 = V_9 ;
V_307 . V_311 = - V_311 ;
F_133 ( & V_8 ) ;
F_148 (sk, &nl_table[ssk->sk_protocol].mc_list)
V_23 += F_237 ( V_2 , & V_307 ) ;
F_134 ( & V_8 ) ;
return V_23 ;
}
static void F_239 ( struct V_46 * V_47 ,
unsigned int V_9 ,
int V_312 )
{
int V_228 , V_313 = ! ! V_312 , V_203 ;
V_228 = F_41 ( V_9 - 1 , V_47 -> V_178 ) ;
V_203 = V_47 -> V_203 - V_228 + V_313 ;
if ( V_313 )
F_240 ( V_9 - 1 , V_47 -> V_178 ) ;
else
F_241 ( V_9 - 1 , V_47 -> V_178 ) ;
F_186 ( & V_47 -> V_2 , V_203 ) ;
F_145 ( & V_47 -> V_2 ) ;
}
static int F_242 ( struct V_105 * V_1 , int V_314 , int V_315 ,
char T_5 * V_316 , unsigned int V_317 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_46 * V_47 = F_2 ( V_2 ) ;
unsigned int V_295 = 0 ;
int V_82 ;
if ( V_314 != V_318 )
return - V_319 ;
if ( V_315 != V_320 && V_315 != V_321 &&
V_317 >= sizeof( int ) &&
F_243 ( V_295 , ( unsigned int T_5 * ) V_316 ) )
return - V_322 ;
switch ( V_315 ) {
case V_323 :
if ( V_295 )
V_47 -> V_3 |= V_324 ;
else
V_47 -> V_3 &= ~ V_324 ;
V_82 = 0 ;
break;
case V_325 :
case V_326 : {
if ( ! F_185 ( V_1 , V_255 ) )
return - V_256 ;
V_82 = F_188 ( V_2 ) ;
if ( V_82 )
return V_82 ;
if ( ! V_295 || V_295 - 1 >= V_47 -> V_195 )
return - V_14 ;
if ( V_315 == V_325 && V_47 -> V_222 ) {
V_82 = V_47 -> V_222 ( F_139 ( V_2 ) , V_295 ) ;
if ( V_82 )
return V_82 ;
}
F_121 () ;
F_239 ( V_47 , V_295 ,
V_315 == V_325 ) ;
F_130 () ;
if ( V_315 == V_326 && V_47 -> V_223 )
V_47 -> V_223 ( F_139 ( V_2 ) , V_295 ) ;
V_82 = 0 ;
break;
}
case V_327 :
if ( V_295 )
V_47 -> V_3 |= V_299 ;
else
V_47 -> V_3 &= ~ V_299 ;
V_82 = 0 ;
break;
case V_328 :
if ( V_295 ) {
V_47 -> V_3 |= V_48 ;
F_40 ( V_49 , & V_47 -> V_50 ) ;
F_42 ( & V_47 -> V_56 ) ;
} else {
V_47 -> V_3 &= ~ V_48 ;
}
V_82 = 0 ;
break;
#ifdef F_109
case V_320 :
case V_321 : {
struct V_72 V_73 ;
if ( ! F_244 ( V_241 ) )
return - V_256 ;
if ( V_317 < sizeof( V_73 ) )
return - V_14 ;
if ( F_245 ( & V_73 , V_316 , sizeof( V_73 ) ) )
return - V_322 ;
V_82 = F_57 ( V_2 , & V_73 , false ,
V_315 == V_321 ) ;
break;
}
#endif
default:
V_82 = - V_319 ;
}
return V_82 ;
}
static int F_246 ( struct V_105 * V_1 , int V_314 , int V_315 ,
char T_5 * V_316 , int T_5 * V_317 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_46 * V_47 = F_2 ( V_2 ) ;
int V_62 , V_295 , V_82 ;
if ( V_314 != V_318 )
return - V_319 ;
if ( F_243 ( V_62 , V_317 ) )
return - V_322 ;
if ( V_62 < 0 )
return - V_14 ;
switch ( V_315 ) {
case V_323 :
if ( V_62 < sizeof( int ) )
return - V_14 ;
V_62 = sizeof( int ) ;
V_295 = V_47 -> V_3 & V_324 ? 1 : 0 ;
if ( F_247 ( V_62 , V_317 ) ||
F_247 ( V_295 , V_316 ) )
return - V_322 ;
V_82 = 0 ;
break;
case V_327 :
if ( V_62 < sizeof( int ) )
return - V_14 ;
V_62 = sizeof( int ) ;
V_295 = V_47 -> V_3 & V_299 ? 1 : 0 ;
if ( F_247 ( V_62 , V_317 ) ||
F_247 ( V_295 , V_316 ) )
return - V_322 ;
V_82 = 0 ;
break;
case V_328 :
if ( V_62 < sizeof( int ) )
return - V_14 ;
V_62 = sizeof( int ) ;
V_295 = V_47 -> V_3 & V_48 ? 1 : 0 ;
if ( F_247 ( V_62 , V_317 ) ||
F_247 ( V_295 , V_316 ) )
return - V_322 ;
V_82 = 0 ;
break;
default:
V_82 = - V_319 ;
}
return V_82 ;
}
static void F_248 ( struct V_145 * V_146 , struct V_24 * V_25 )
{
struct V_329 V_307 ;
V_307 . V_9 = F_44 ( V_25 ) . V_148 ;
F_249 ( V_146 , V_318 , V_323 , sizeof( V_307 ) , & V_307 ) ;
}
static int F_250 ( struct V_330 * V_330 , struct V_105 * V_1 ,
struct V_145 * V_146 , T_6 V_62 )
{
struct V_149 * V_150 = F_251 ( V_330 ) ;
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_46 * V_47 = F_2 ( V_2 ) ;
F_196 ( struct V_250 * , V_248 , V_146 -> V_331 ) ;
T_1 V_147 ;
T_1 V_148 ;
struct V_24 * V_25 ;
int V_82 ;
struct V_332 V_157 ;
T_1 V_333 = 0 ;
if ( V_146 -> V_153 & V_334 )
return - V_335 ;
if ( NULL == V_150 -> V_157 )
V_150 -> V_157 = & V_157 ;
V_82 = F_252 ( V_1 , V_146 , V_150 -> V_157 , true ) ;
if ( V_82 < 0 )
return V_82 ;
if ( V_146 -> V_336 ) {
V_82 = - V_14 ;
if ( V_248 -> V_253 != V_254 )
goto V_21;
V_147 = V_248 -> V_257 ;
V_148 = F_194 ( V_248 -> V_252 ) ;
V_82 = - V_256 ;
if ( ( V_148 || V_147 ) &&
! F_185 ( V_1 , V_263 ) )
goto V_21;
V_333 |= V_237 ;
} else {
V_147 = V_47 -> V_147 ;
V_148 = V_47 -> V_148 ;
}
if ( ! V_47 -> V_155 ) {
V_82 = F_176 ( V_1 ) ;
if ( V_82 )
goto V_21;
}
if ( F_46 ( V_2 ) &&
V_146 -> V_337 . V_338 -> V_339 == NULL ) {
V_82 = F_94 ( V_2 , V_146 , V_147 , V_148 ,
V_150 ) ;
goto V_21;
}
V_82 = - V_340 ;
if ( V_62 > V_2 -> V_341 - 32 )
goto V_21;
V_82 = - V_52 ;
V_25 = F_203 ( V_62 , V_148 ) ;
if ( V_25 == NULL )
goto V_21;
F_44 ( V_25 ) . V_155 = V_47 -> V_155 ;
F_44 ( V_25 ) . V_148 = V_148 ;
F_44 ( V_25 ) . V_156 = V_150 -> V_157 -> V_156 ;
F_44 ( V_25 ) . V_3 = V_333 ;
V_82 = - V_322 ;
if ( F_253 ( F_254 ( V_25 , V_62 ) , V_146 , V_62 ) ) {
F_100 ( V_25 ) ;
goto V_21;
}
V_82 = F_99 ( V_2 , V_25 ) ;
if ( V_82 ) {
F_100 ( V_25 ) ;
goto V_21;
}
if ( V_148 ) {
F_37 ( & V_25 -> V_158 ) ;
F_101 ( V_2 , V_25 , V_147 , V_148 , V_66 ) ;
}
V_82 = F_102 ( V_2 , V_25 , V_147 , V_146 -> V_153 & V_154 ) ;
V_21:
F_255 ( V_150 -> V_157 ) ;
return V_82 ;
}
static int F_256 ( struct V_330 * V_330 , struct V_105 * V_1 ,
struct V_145 * V_146 , T_6 V_62 ,
int V_3 )
{
struct V_149 * V_150 = F_251 ( V_330 ) ;
struct V_332 V_157 ;
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_46 * V_47 = F_2 ( V_2 ) ;
int V_342 = V_3 & V_154 ;
T_6 V_343 ;
struct V_24 * V_25 , * V_344 ;
int V_82 , V_23 ;
if ( V_3 & V_334 )
return - V_335 ;
V_343 = 0 ;
V_25 = F_257 ( V_2 , V_3 , V_342 , & V_82 ) ;
if ( V_25 == NULL )
goto V_21;
V_344 = V_25 ;
#ifdef F_258
if ( F_7 ( F_112 ( V_25 ) -> V_345 ) ) {
if ( V_3 & V_346 )
V_344 = F_112 ( V_25 ) -> V_345 ;
}
#endif
V_47 -> V_347 = F_259 ( V_47 -> V_347 , V_62 ) ;
V_47 -> V_347 = F_260 ( T_6 , V_47 -> V_347 ,
16384 ) ;
V_343 = V_344 -> V_62 ;
if ( V_62 < V_343 ) {
V_146 -> V_153 |= V_348 ;
V_343 = V_62 ;
}
F_261 ( V_344 ) ;
V_82 = F_262 ( V_344 , 0 , V_146 , V_343 ) ;
if ( V_146 -> V_331 ) {
F_196 ( struct V_250 * , V_248 , V_146 -> V_331 ) ;
V_248 -> V_253 = V_254 ;
V_248 -> V_266 = 0 ;
V_248 -> V_257 = F_44 ( V_25 ) . V_155 ;
V_248 -> V_252 = F_5 ( F_44 ( V_25 ) . V_148 ) ;
V_146 -> V_336 = sizeof( * V_248 ) ;
}
if ( V_47 -> V_3 & V_324 )
F_248 ( V_146 , V_25 ) ;
if ( NULL == V_150 -> V_157 ) {
memset ( & V_157 , 0 , sizeof( V_157 ) ) ;
V_150 -> V_157 = & V_157 ;
}
V_150 -> V_157 -> V_156 = * F_263 ( V_25 ) ;
if ( V_3 & V_348 )
V_343 = V_344 -> V_62 ;
F_264 ( V_2 , V_25 ) ;
if ( V_47 -> V_135 &&
F_58 ( & V_2 -> V_172 ) <= V_2 -> V_279 / 2 ) {
V_23 = F_89 ( V_2 ) ;
if ( V_23 ) {
V_2 -> V_51 = - V_23 ;
V_2 -> V_53 ( V_2 ) ;
}
}
F_265 ( V_1 , V_146 , V_150 -> V_157 , V_3 ) ;
V_21:
F_38 ( V_2 ) ;
return V_82 ? : V_343 ;
}
static void F_266 ( struct V_1 * V_2 )
{
F_267 () ;
}
struct V_1 *
F_268 ( struct V_188 * V_188 , int V_349 , struct V_18 * V_18 ,
struct V_350 * V_351 )
{
struct V_105 * V_1 ;
struct V_1 * V_2 ;
struct V_46 * V_47 ;
struct V_194 * V_194 = NULL ;
struct V_205 * V_206 = V_351 ? V_351 -> V_206 : NULL ;
unsigned int V_178 ;
F_173 ( ! V_192 ) ;
if ( V_349 < 0 || V_349 >= V_218 )
return NULL ;
if ( F_269 ( V_209 , V_216 , V_349 , & V_1 ) )
return NULL ;
if ( F_155 ( & V_352 , V_1 , V_206 , V_349 ) < 0 )
goto V_353;
V_2 = V_1 -> V_2 ;
F_270 ( V_2 , V_188 ) ;
if ( ! V_351 || V_351 -> V_178 < 32 )
V_178 = 32 ;
else
V_178 = V_351 -> V_178 ;
V_194 = F_271 ( sizeof( * V_194 ) + F_190 ( V_178 ) , V_66 ) ;
if ( ! V_194 )
goto V_354;
V_2 -> V_282 = F_266 ;
if ( V_351 && V_351 -> V_355 )
F_2 ( V_2 ) -> V_285 = V_351 -> V_355 ;
if ( F_149 ( V_2 , V_188 , 0 ) )
goto V_354;
V_47 = F_2 ( V_2 ) ;
V_47 -> V_3 |= V_4 ;
F_121 () ;
if ( ! V_192 [ V_349 ] . V_220 ) {
V_192 [ V_349 ] . V_178 = V_178 ;
F_272 ( V_192 [ V_349 ] . V_194 , V_194 ) ;
V_192 [ V_349 ] . V_206 = V_206 ;
V_192 [ V_349 ] . V_18 = V_18 ;
if ( V_351 ) {
V_192 [ V_349 ] . F_161 = V_351 -> F_161 ;
V_192 [ V_349 ] . F_162 = V_351 -> F_162 ;
V_192 [ V_349 ] . V_3 = V_351 -> V_3 ;
if ( V_351 -> V_356 )
V_192 [ V_349 ] . V_356 = V_351 -> V_356 ;
}
V_192 [ V_349 ] . V_220 = 1 ;
} else {
F_51 ( V_194 ) ;
V_192 [ V_349 ] . V_220 ++ ;
}
F_130 () ;
return V_2 ;
V_354:
F_51 ( V_194 ) ;
F_273 ( V_2 ) ;
return NULL ;
V_353:
F_274 ( V_1 ) ;
return NULL ;
}
void
F_273 ( struct V_1 * V_2 )
{
F_275 ( V_2 ) ;
}
int F_276 ( struct V_1 * V_2 , unsigned int V_178 )
{
struct V_194 * V_313 , * V_228 ;
struct V_189 * V_193 = & V_192 [ V_2 -> V_26 ] ;
if ( V_178 < 32 )
V_178 = 32 ;
if ( F_190 ( V_193 -> V_178 ) < F_190 ( V_178 ) ) {
V_313 = F_271 ( sizeof( * V_313 ) + F_190 ( V_178 ) , V_38 ) ;
if ( ! V_313 )
return - V_37 ;
V_228 = F_146 ( V_193 -> V_194 ) ;
memcpy ( V_313 -> V_196 , V_228 -> V_196 , F_190 ( V_193 -> V_178 ) ) ;
F_272 ( V_193 -> V_194 , V_313 ) ;
F_175 ( V_228 , V_229 ) ;
}
V_193 -> V_178 = V_178 ;
return 0 ;
}
int F_277 ( struct V_1 * V_2 , unsigned int V_178 )
{
int V_82 ;
F_121 () ;
V_82 = F_276 ( V_2 , V_178 ) ;
F_130 () ;
return V_82 ;
}
void F_278 ( struct V_1 * V_357 , unsigned int V_9 )
{
struct V_1 * V_2 ;
struct V_189 * V_193 = & V_192 [ V_357 -> V_26 ] ;
F_148 (sk, &tbl->mc_list)
F_239 ( F_2 ( V_2 ) , V_9 , 0 ) ;
}
struct V_358 *
F_279 ( struct V_24 * V_25 , T_1 V_155 , T_1 V_359 , int type , int V_62 , int V_3 )
{
struct V_358 * V_360 ;
int V_108 = F_280 ( V_62 ) ;
V_360 = (struct V_358 * ) F_254 ( V_25 , F_281 ( V_108 ) ) ;
V_360 -> V_361 = type ;
V_360 -> V_362 = V_108 ;
V_360 -> V_363 = V_3 ;
V_360 -> V_364 = V_155 ;
V_360 -> V_365 = V_359 ;
if ( ! F_282 ( V_108 ) || F_281 ( V_108 ) - V_108 != 0 )
memset ( F_283 ( V_360 ) + V_62 , 0 , F_281 ( V_108 ) - V_108 ) ;
return V_360 ;
}
static int F_89 ( struct V_1 * V_2 )
{
struct V_46 * V_47 = F_2 ( V_2 ) ;
struct V_366 * V_173 ;
struct V_24 * V_25 = NULL ;
struct V_358 * V_360 ;
int V_62 , V_82 = - V_52 ;
int V_367 ;
F_62 ( V_47 -> V_206 ) ;
if ( ! V_47 -> V_135 ) {
V_82 = - V_14 ;
goto V_368;
}
V_173 = & V_47 -> V_173 ;
V_367 = F_284 ( int , V_173 -> V_369 , V_275 ) ;
if ( ! F_45 ( V_2 ) &&
F_58 ( & V_2 -> V_172 ) >= V_2 -> V_279 )
goto V_368;
if ( V_367 < V_47 -> V_347 ) {
V_25 = F_226 ( V_2 ,
V_47 -> V_347 ,
V_47 -> V_155 ,
V_66 |
V_69 |
V_70 ) ;
if ( V_25 )
F_285 ( V_25 , F_286 ( V_25 ) -
V_47 -> V_347 ) ;
}
if ( ! V_25 )
V_25 = F_226 ( V_2 , V_367 , V_47 -> V_155 ,
V_66 ) ;
if ( ! V_25 )
goto V_368;
F_114 ( V_25 , V_2 ) ;
V_62 = V_173 -> V_370 ( V_25 , V_173 ) ;
if ( V_62 > 0 ) {
F_68 ( V_47 -> V_206 ) ;
if ( F_225 ( V_2 , V_25 ) )
F_100 ( V_25 ) ;
else
F_212 ( V_2 , V_25 ) ;
return 0 ;
}
V_360 = F_287 ( V_25 , V_173 , V_371 , sizeof( V_62 ) , V_372 ) ;
if ( ! V_360 )
goto V_368;
F_288 ( V_173 , V_360 ) ;
memcpy ( F_283 ( V_360 ) , & V_62 , sizeof( V_62 ) ) ;
if ( F_225 ( V_2 , V_25 ) )
F_100 ( V_25 ) ;
else
F_212 ( V_2 , V_25 ) ;
if ( V_173 -> V_174 )
V_173 -> V_174 ( V_173 ) ;
V_47 -> V_135 = false ;
F_68 ( V_47 -> V_206 ) ;
F_16 ( V_173 -> V_18 ) ;
F_218 ( V_173 -> V_25 ) ;
return 0 ;
V_368:
F_68 ( V_47 -> V_206 ) ;
F_100 ( V_25 ) ;
return V_82 ;
}
int F_289 ( struct V_1 * V_267 , struct V_24 * V_25 ,
const struct V_358 * V_360 ,
struct V_373 * V_374 )
{
struct V_366 * V_173 ;
struct V_1 * V_2 ;
struct V_46 * V_47 ;
int V_23 ;
if ( F_43 ( V_25 ) ) {
V_25 = F_290 ( V_25 , V_66 ) ;
if ( V_25 == NULL )
return - V_52 ;
} else
F_37 ( & V_25 -> V_158 ) ;
V_2 = F_143 ( F_139 ( V_267 ) , V_267 -> V_26 , F_44 ( V_25 ) . V_155 ) ;
if ( V_2 == NULL ) {
V_23 = - V_268 ;
goto V_375;
}
V_47 = F_2 ( V_2 ) ;
F_62 ( V_47 -> V_206 ) ;
if ( V_47 -> V_135 ) {
V_23 = - V_85 ;
goto V_376;
}
if ( ! F_165 ( V_374 -> V_18 ) ) {
V_23 = - V_219 ;
goto V_376;
}
V_173 = & V_47 -> V_173 ;
memset ( V_173 , 0 , sizeof( * V_173 ) ) ;
V_173 -> V_370 = V_374 -> V_370 ;
V_173 -> V_174 = V_374 -> V_174 ;
V_173 -> V_360 = V_360 ;
V_173 -> V_140 = V_374 -> V_140 ;
V_173 -> V_18 = V_374 -> V_18 ;
V_173 -> V_369 = V_374 -> V_369 ;
V_173 -> V_25 = V_25 ;
V_47 -> V_135 = true ;
F_68 ( V_47 -> V_206 ) ;
V_23 = F_89 ( V_2 ) ;
F_110 ( V_2 ) ;
if ( V_23 )
return V_23 ;
return - V_377 ;
V_376:
F_110 ( V_2 ) ;
F_68 ( V_47 -> V_206 ) ;
V_375:
F_100 ( V_25 ) ;
return V_23 ;
}
void F_291 ( struct V_24 * V_378 , struct V_358 * V_360 , int V_82 )
{
struct V_24 * V_25 ;
struct V_358 * V_379 ;
struct V_380 * V_381 ;
T_6 V_382 = sizeof( * V_381 ) ;
if ( V_82 )
V_382 += V_362 ( V_360 ) ;
V_25 = F_226 ( V_378 -> V_2 , F_292 ( V_382 ) ,
F_44 ( V_378 ) . V_155 , V_66 ) ;
if ( ! V_25 ) {
struct V_1 * V_2 ;
V_2 = F_143 ( F_139 ( V_378 -> V_2 ) ,
V_378 -> V_2 -> V_26 ,
F_44 ( V_378 ) . V_155 ) ;
if ( V_2 ) {
V_2 -> V_51 = V_52 ;
V_2 -> V_53 ( V_2 ) ;
F_110 ( V_2 ) ;
}
return;
}
V_379 = F_279 ( V_25 , F_44 ( V_378 ) . V_155 , V_360 -> V_365 ,
V_383 , V_382 , 0 ) ;
V_381 = F_283 ( V_379 ) ;
V_381 -> error = V_82 ;
memcpy ( & V_381 -> V_146 , V_360 , V_82 ? V_360 -> V_362 : sizeof( * V_360 ) ) ;
F_102 ( V_378 -> V_2 , V_25 , F_44 ( V_378 ) . V_155 , V_154 ) ;
}
int F_293 ( struct V_24 * V_25 , int (* V_173)( struct V_24 * ,
struct V_358 * ) )
{
struct V_358 * V_360 ;
int V_82 ;
while ( V_25 -> V_62 >= F_292 ( 0 ) ) {
int V_384 ;
V_360 = F_294 ( V_25 ) ;
V_82 = 0 ;
if ( V_360 -> V_362 < V_385 || V_25 -> V_62 < V_360 -> V_362 )
return 0 ;
if ( ! ( V_360 -> V_363 & V_386 ) )
goto V_387;
if ( V_360 -> V_361 < V_388 )
goto V_387;
V_82 = V_173 ( V_25 , V_360 ) ;
if ( V_82 == - V_377 )
goto V_389;
V_387:
if ( V_360 -> V_363 & V_390 || V_82 )
F_291 ( V_25 , V_360 , V_82 ) ;
V_389:
V_384 = F_281 ( V_360 -> V_362 ) ;
if ( V_384 > V_25 -> V_62 )
V_384 = V_25 -> V_62 ;
F_295 ( V_25 , V_384 ) ;
}
return 0 ;
}
int F_296 ( struct V_1 * V_2 , struct V_24 * V_25 , T_1 V_155 ,
unsigned int V_9 , int V_391 , T_2 V_3 )
{
int V_82 = 0 ;
if ( V_9 ) {
int V_392 = 0 ;
if ( V_391 ) {
F_37 ( & V_25 -> V_158 ) ;
V_392 = V_155 ;
}
V_82 = F_297 ( V_2 , V_25 , V_392 , V_9 , V_3 ) ;
}
if ( V_391 ) {
int V_290 ;
V_290 = F_298 ( V_2 , V_25 , V_155 ) ;
if ( ! V_82 || V_82 == - V_309 )
V_82 = V_290 ;
}
return V_82 ;
}
static struct V_1 * F_299 ( struct V_393 * V_359 , T_7 V_127 )
{
struct V_394 * V_395 = V_359 -> V_396 ;
int V_63 , V_397 ;
struct V_46 * V_47 ;
struct V_1 * V_398 ;
T_7 V_399 = 0 ;
for ( V_63 = 0 ; V_63 < V_218 ; V_63 ++ ) {
struct V_400 * V_401 = & V_192 [ V_63 ] . V_191 ;
const struct V_402 * V_193 = F_300 ( V_401 -> V_193 , V_401 ) ;
for ( V_397 = 0 ; V_397 < V_193 -> V_108 ; V_397 ++ ) {
F_301 (nlk, tbl->buckets[j], node) {
V_398 = (struct V_1 * ) V_47 ;
if ( F_139 ( V_398 ) != F_302 ( V_359 ) )
continue;
if ( V_399 == V_127 ) {
V_395 -> V_403 = V_63 ;
V_395 -> V_404 = V_397 ;
return V_398 ;
}
++ V_399 ;
}
}
}
return NULL ;
}
static void * F_303 ( struct V_393 * V_359 , T_7 * V_127 )
__acquires( V_8 ) __acquires( T_8 )
{
F_133 ( & V_8 ) ;
F_31 () ;
return * V_127 ? F_299 ( V_359 , * V_127 - 1 ) : V_405 ;
}
static void * F_304 ( struct V_393 * V_359 , void * V_406 , T_7 * V_127 )
{
struct V_400 * V_401 ;
struct V_46 * V_47 ;
struct V_394 * V_395 ;
struct V_188 * V_188 ;
int V_63 , V_397 ;
++ * V_127 ;
if ( V_406 == V_405 )
return F_299 ( V_359 , 0 ) ;
V_188 = F_302 ( V_359 ) ;
V_395 = V_359 -> V_396 ;
V_47 = V_406 ;
V_63 = V_395 -> V_403 ;
V_401 = & V_192 [ V_63 ] . V_191 ;
F_305 (nlk, nlk->node.next, ht, node)
if ( F_138 ( F_139 ( (struct V_1 * ) V_47 ) , V_188 ) )
return V_47 ;
V_397 = V_395 -> V_404 + 1 ;
do {
const struct V_402 * V_193 = F_300 ( V_401 -> V_193 , V_401 ) ;
for (; V_397 < V_193 -> V_108 ; V_397 ++ ) {
F_305 (nlk, tbl->buckets[j], ht, node) {
if ( F_138 ( F_139 ( (struct V_1 * ) V_47 ) , V_188 ) ) {
V_395 -> V_403 = V_63 ;
V_395 -> V_404 = V_397 ;
return V_47 ;
}
}
}
V_397 = 0 ;
} while ( ++ V_63 < V_218 );
return NULL ;
}
static void F_306 ( struct V_393 * V_359 , void * V_406 )
__releases( T_8 ) __releases( V_8 )
{
F_33 () ;
F_134 ( & V_8 ) ;
}
static int F_307 ( struct V_393 * V_359 , void * V_406 )
{
if ( V_406 == V_405 ) {
F_308 ( V_359 ,
L_4
L_5 ) ;
} else {
struct V_1 * V_398 = V_406 ;
struct V_46 * V_47 = F_2 ( V_398 ) ;
F_309 ( V_359 , L_6 ,
V_398 ,
V_398 -> V_26 ,
V_47 -> V_155 ,
V_47 -> V_178 ? ( T_1 ) V_47 -> V_178 [ 0 ] : 0 ,
F_310 ( V_398 ) ,
F_311 ( V_398 ) ,
V_47 -> V_135 ,
F_58 ( & V_398 -> V_202 ) ,
F_58 ( & V_398 -> V_54 ) ,
F_312 ( V_398 )
) ;
}
return 0 ;
}
static int F_313 ( struct V_270 * V_270 , struct V_103 * V_103 )
{
return F_314 ( V_270 , V_103 , & V_407 ,
sizeof( struct V_394 ) ) ;
}
int F_315 ( struct V_408 * V_409 )
{
return F_316 ( & V_226 , V_409 ) ;
}
int F_317 ( struct V_408 * V_409 )
{
return F_318 ( & V_226 , V_409 ) ;
}
static int T_9 F_319 ( struct V_188 * V_188 )
{
#ifdef F_320
if ( ! F_321 ( L_7 , 0 , V_188 -> V_410 , & V_411 ) )
return - V_37 ;
#endif
return 0 ;
}
static void T_10 F_322 ( struct V_188 * V_188 )
{
#ifdef F_320
F_323 ( L_7 , V_188 -> V_410 ) ;
#endif
}
static void T_11 F_324 ( void )
{
struct V_194 * V_194 ;
int V_178 = 32 ;
V_194 = F_271 ( sizeof( * V_194 ) + F_190 ( V_178 ) , V_66 ) ;
if ( ! V_194 )
F_325 ( L_8 ) ;
F_121 () ;
V_192 [ V_28 ] . V_178 = V_178 ;
F_272 ( V_192 [ V_28 ] . V_194 , V_194 ) ;
V_192 [ V_28 ] . V_18 = V_412 ;
V_192 [ V_28 ] . V_220 = 1 ;
V_192 [ V_28 ] . V_3 = V_263 ;
F_130 () ;
}
static int T_11 F_326 ( void )
{
int V_63 ;
int V_82 = F_327 ( & V_210 , 0 ) ;
struct V_413 V_414 = {
. V_415 = F_328 ( struct V_46 , V_201 ) ,
. V_416 = F_328 ( struct V_46 , V_155 ) ,
. V_417 = sizeof( T_1 ) ,
. V_418 = V_419 ,
. V_420 = 16 ,
. V_421 = V_422 ,
. V_423 = V_424 ,
#ifdef F_329
. V_425 = F_3 ,
#endif
} ;
if ( V_82 != 0 )
goto V_21;
F_330 ( sizeof( struct V_232 ) > F_331 ( struct V_24 , V_173 ) ) ;
V_192 = F_56 ( V_218 , sizeof( * V_192 ) , V_66 ) ;
if ( ! V_192 )
goto F_325;
for ( V_63 = 0 ; V_63 < V_218 ; V_63 ++ ) {
if ( F_332 ( & V_192 [ V_63 ] . V_191 , & V_414 ) < 0 ) {
while ( -- V_63 > 0 )
F_333 ( & V_192 [ V_63 ] . V_191 ) ;
F_51 ( V_192 ) ;
goto F_325;
}
}
F_334 ( & V_17 ) ;
F_324 () ;
F_335 ( & V_426 ) ;
F_336 ( & V_427 ) ;
F_337 () ;
V_21:
return V_82 ;
F_325:
F_325 ( L_9 ) ;
}
