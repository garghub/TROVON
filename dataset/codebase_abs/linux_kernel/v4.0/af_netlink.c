static inline int F_1 ( struct V_1 * V_2 )
{
return F_2 ( V_2 ) -> V_3 & V_4 ;
}
static inline T_1 F_3 ( T_1 V_5 )
{
return V_5 ? 1 << ( V_5 - 1 ) : 0 ;
}
int F_4 ( struct V_6 * V_7 )
{
if ( F_5 ( V_7 -> V_8 -> type != V_9 ) )
return - V_10 ;
F_6 ( & V_11 ) ;
F_7 ( & V_7 -> V_12 , & V_13 ) ;
F_8 ( & V_11 ) ;
F_9 ( V_7 -> V_14 ) ;
return 0 ;
}
static int F_10 ( struct V_6 * V_7 )
{
bool V_15 = false ;
struct V_6 * V_16 ;
F_6 ( & V_11 ) ;
F_11 (tmp, &netlink_tap_all, list) {
if ( V_7 == V_16 ) {
F_12 ( & V_7 -> V_12 ) ;
V_15 = true ;
goto V_17;
}
}
F_13 ( L_1 , V_7 ) ;
V_17:
F_8 ( & V_11 ) ;
if ( V_15 && V_7 -> V_14 )
F_14 ( V_7 -> V_14 ) ;
return V_15 ? 0 : - V_18 ;
}
int F_15 ( struct V_6 * V_7 )
{
int V_19 ;
V_19 = F_10 ( V_7 ) ;
F_16 () ;
return V_19 ;
}
static bool F_17 ( const struct V_20 * V_21 )
{
struct V_1 * V_2 = V_21 -> V_2 ;
switch ( V_2 -> V_22 ) {
case V_23 :
case V_24 :
case V_25 :
case V_26 :
case V_27 :
case V_28 :
case V_29 :
case V_30 :
return true ;
}
return false ;
}
static int F_18 ( struct V_20 * V_21 ,
struct V_31 * V_8 )
{
struct V_20 * V_32 ;
struct V_1 * V_2 = V_21 -> V_2 ;
int V_19 = - V_33 ;
F_19 ( V_8 ) ;
V_32 = F_20 ( V_21 , V_34 ) ;
if ( V_32 ) {
V_32 -> V_8 = V_8 ;
V_32 -> V_35 = F_21 ( ( V_36 ) V_2 -> V_22 ) ;
V_32 -> V_37 = F_1 ( V_2 ) ?
V_38 : V_39 ;
F_22 ( V_32 ) ;
V_19 = F_23 ( V_32 ) ;
if ( F_5 ( V_19 > 0 ) )
V_19 = F_24 ( V_19 ) ;
}
F_25 ( V_8 ) ;
return V_19 ;
}
static void F_26 ( struct V_20 * V_21 )
{
int V_19 ;
struct V_6 * V_16 ;
if ( ! F_17 ( V_21 ) )
return;
F_27 (tmp, &netlink_tap_all, list) {
V_19 = F_18 ( V_21 , V_16 -> V_8 ) ;
if ( F_5 ( V_19 ) )
break;
}
}
static void F_28 ( struct V_20 * V_21 )
{
F_29 () ;
if ( F_5 ( ! F_30 ( & V_13 ) ) )
F_26 ( V_21 ) ;
F_31 () ;
}
static void F_32 ( struct V_1 * V_40 , struct V_1 * V_41 ,
struct V_20 * V_21 )
{
if ( ! ( F_1 ( V_40 ) && F_1 ( V_41 ) ) )
F_28 ( V_21 ) ;
}
static void F_33 ( struct V_1 * V_2 )
{
struct V_42 * V_43 = F_2 ( V_2 ) ;
if ( ! ( V_43 -> V_3 & V_44 ) ) {
if ( ! F_34 ( V_45 , & F_2 ( V_2 ) -> V_46 ) ) {
V_2 -> V_47 = V_48 ;
V_2 -> V_49 ( V_2 ) ;
}
}
F_35 ( & V_2 -> V_50 ) ;
}
static void F_36 ( struct V_1 * V_2 )
{
struct V_42 * V_43 = F_2 ( V_2 ) ;
if ( F_37 ( & V_2 -> V_51 ) )
F_38 ( V_45 , & V_43 -> V_46 ) ;
if ( ! F_39 ( V_45 , & V_43 -> V_46 ) )
F_40 ( & V_43 -> V_52 ) ;
}
static bool F_41 ( const struct V_20 * V_21 )
{
return F_42 ( V_21 ) . V_3 & V_53 ;
}
static bool F_43 ( struct V_1 * V_2 )
{
return F_2 ( V_2 ) -> V_54 . V_55 != NULL ;
}
static bool F_44 ( struct V_1 * V_2 )
{
return F_2 ( V_2 ) -> V_56 . V_55 != NULL ;
}
static void F_45 ( void * * V_55 , unsigned int V_57 , unsigned int V_58 )
{
unsigned int V_59 ;
for ( V_59 = 0 ; V_59 < V_58 ; V_59 ++ ) {
if ( V_55 [ V_59 ] != NULL ) {
if ( F_46 ( V_55 [ V_59 ] ) )
F_47 ( V_55 [ V_59 ] ) ;
else
F_48 ( ( unsigned long ) V_55 [ V_59 ] , V_57 ) ;
}
}
F_49 ( V_55 ) ;
}
static void * F_50 ( unsigned long V_57 )
{
void * V_60 ;
T_2 V_61 = V_62 | V_63 | V_64 |
V_65 | V_66 ;
V_60 = ( void * ) F_51 ( V_61 , V_57 ) ;
if ( V_60 != NULL )
return V_60 ;
V_60 = F_52 ( ( 1 << V_57 ) * V_67 ) ;
if ( V_60 != NULL )
return V_60 ;
V_61 &= ~ V_66 ;
return ( void * ) F_51 ( V_61 , V_57 ) ;
}
static void * * F_53 ( struct V_42 * V_43 ,
struct V_68 * V_69 , unsigned int V_57 )
{
unsigned int V_70 = V_69 -> V_71 ;
unsigned int V_59 ;
void * * V_55 ;
V_55 = F_54 ( V_70 , sizeof( void * ) , V_62 ) ;
if ( V_55 == NULL )
return NULL ;
for ( V_59 = 0 ; V_59 < V_70 ; V_59 ++ ) {
V_55 [ V_59 ] = F_50 ( V_57 ) ;
if ( V_55 [ V_59 ] == NULL )
goto V_72;
}
return V_55 ;
V_72:
F_45 ( V_55 , V_57 , V_70 ) ;
return NULL ;
}
static int F_55 ( struct V_1 * V_2 , struct V_68 * V_69 ,
bool V_73 , bool V_56 )
{
struct V_42 * V_43 = F_2 ( V_2 ) ;
struct V_74 * V_75 ;
struct V_76 * V_77 ;
void * * V_55 = NULL ;
unsigned int V_57 = 0 ;
int V_78 ;
V_75 = V_56 ? & V_43 -> V_56 : & V_43 -> V_54 ;
V_77 = V_56 ? & V_2 -> V_79 : & V_2 -> V_51 ;
if ( ! V_73 ) {
if ( F_56 ( & V_43 -> V_80 ) )
return - V_81 ;
if ( F_56 ( & V_75 -> V_82 ) )
return - V_81 ;
}
if ( V_69 -> V_71 ) {
if ( V_75 -> V_55 != NULL )
return - V_81 ;
if ( ( int ) V_69 -> V_83 <= 0 )
return - V_10 ;
if ( ! F_57 ( V_69 -> V_83 ) )
return - V_10 ;
if ( V_69 -> V_84 < V_85 )
return - V_10 ;
if ( ! F_58 ( V_69 -> V_84 , V_86 ) )
return - V_10 ;
V_75 -> V_87 = V_69 -> V_83 /
V_69 -> V_84 ;
if ( V_75 -> V_87 == 0 )
return - V_10 ;
if ( V_75 -> V_87 * V_69 -> V_71 !=
V_69 -> V_88 )
return - V_10 ;
V_57 = F_59 ( V_69 -> V_83 ) ;
V_55 = F_53 ( V_43 , V_69 , V_57 ) ;
if ( V_55 == NULL )
return - V_33 ;
} else {
if ( V_69 -> V_88 )
return - V_10 ;
}
V_78 = - V_81 ;
F_60 ( & V_43 -> V_89 ) ;
if ( V_73 || F_56 ( & V_43 -> V_80 ) == 0 ) {
V_78 = 0 ;
F_61 ( & V_77 -> V_90 ) ;
V_75 -> V_91 = V_69 -> V_88 - 1 ;
V_75 -> V_92 = 0 ;
V_75 -> V_93 = V_69 -> V_84 ;
V_75 -> V_94 = V_69 -> V_83 / V_67 ;
F_62 ( V_75 -> V_95 , V_69 -> V_71 ) ;
F_62 ( V_75 -> V_96 , V_57 ) ;
F_62 ( V_75 -> V_55 , V_55 ) ;
F_63 ( V_77 ) ;
F_64 ( & V_77 -> V_90 ) ;
F_65 ( F_56 ( & V_43 -> V_80 ) ) ;
}
F_66 ( & V_43 -> V_89 ) ;
if ( V_55 )
F_45 ( V_55 , V_57 , V_69 -> V_71 ) ;
return V_78 ;
}
static void F_67 ( struct V_97 * V_98 )
{
struct V_99 * V_99 = V_98 -> V_100 ;
struct V_101 * V_1 = V_99 -> V_102 ;
struct V_1 * V_2 = V_1 -> V_2 ;
if ( V_2 )
F_35 ( & F_2 ( V_2 ) -> V_80 ) ;
}
static void F_68 ( struct V_97 * V_98 )
{
struct V_99 * V_99 = V_98 -> V_100 ;
struct V_101 * V_1 = V_99 -> V_102 ;
struct V_1 * V_2 = V_1 -> V_2 ;
if ( V_2 )
F_69 ( & F_2 ( V_2 ) -> V_80 ) ;
}
static int F_70 ( struct V_99 * V_99 , struct V_101 * V_1 ,
struct V_97 * V_98 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_42 * V_43 = F_2 ( V_2 ) ;
struct V_74 * V_75 ;
unsigned long V_103 , V_104 , V_105 ;
unsigned int V_59 ;
int V_78 = - V_10 ;
if ( V_98 -> V_106 )
return - V_10 ;
F_60 ( & V_43 -> V_89 ) ;
V_105 = 0 ;
for ( V_75 = & V_43 -> V_54 ; V_75 <= & V_43 -> V_56 ; V_75 ++ ) {
if ( V_75 -> V_55 == NULL )
continue;
V_105 += V_75 -> V_95 * V_75 -> V_94 * V_67 ;
}
if ( V_105 == 0 )
goto V_17;
V_104 = V_98 -> V_107 - V_98 -> V_108 ;
if ( V_104 != V_105 )
goto V_17;
V_103 = V_98 -> V_108 ;
for ( V_75 = & V_43 -> V_54 ; V_75 <= & V_43 -> V_56 ; V_75 ++ ) {
if ( V_75 -> V_55 == NULL )
continue;
for ( V_59 = 0 ; V_59 < V_75 -> V_95 ; V_59 ++ ) {
struct V_109 * V_109 ;
void * V_110 = V_75 -> V_55 [ V_59 ] ;
unsigned int V_111 ;
for ( V_111 = 0 ; V_111 < V_75 -> V_94 ; V_111 ++ ) {
V_109 = F_71 ( V_110 ) ;
V_78 = F_72 ( V_98 , V_103 , V_109 ) ;
if ( V_78 < 0 )
goto V_17;
V_103 += V_67 ;
V_110 += V_67 ;
}
}
}
F_35 ( & V_43 -> V_80 ) ;
V_98 -> V_112 = & V_113 ;
V_78 = 0 ;
V_17:
F_66 ( & V_43 -> V_89 ) ;
return V_78 ;
}
static void F_73 ( const struct V_114 * V_115 , unsigned int V_116 )
{
#if V_117 == 1
struct V_109 * V_118 , * V_119 ;
V_118 = F_71 ( V_115 + V_67 ) ;
V_119 = F_71 ( ( void * ) V_115 + V_85 + V_116 - 1 ) ;
while ( V_118 <= V_119 ) {
F_74 ( V_118 ) ;
V_118 ++ ;
}
#endif
}
static enum V_120 F_75 ( const struct V_114 * V_115 )
{
F_76 () ;
F_74 ( F_71 ( V_115 ) ) ;
return V_115 -> V_121 ;
}
static void F_77 ( struct V_114 * V_115 ,
enum V_120 V_122 )
{
F_78 () ;
V_115 -> V_121 = V_122 ;
F_74 ( F_71 ( V_115 ) ) ;
}
static struct V_114 *
F_79 ( const struct V_74 * V_75 , unsigned int V_123 )
{
unsigned int V_124 , V_125 ;
V_124 = V_123 / V_75 -> V_87 ;
V_125 = V_123 % V_75 -> V_87 ;
return V_75 -> V_55 [ V_124 ] + ( V_125 * V_75 -> V_93 ) ;
}
static struct V_114 *
F_80 ( const struct V_74 * V_75 , unsigned int V_123 ,
enum V_120 V_122 )
{
struct V_114 * V_115 ;
V_115 = F_79 ( V_75 , V_123 ) ;
if ( F_75 ( V_115 ) != V_122 )
return NULL ;
return V_115 ;
}
static struct V_114 *
F_81 ( const struct V_74 * V_75 ,
enum V_120 V_122 )
{
return F_80 ( V_75 , V_75 -> V_92 , V_122 ) ;
}
static struct V_114 *
F_82 ( const struct V_74 * V_75 ,
enum V_120 V_122 )
{
unsigned int V_126 ;
V_126 = V_75 -> V_92 ? V_75 -> V_92 - 1 : V_75 -> V_91 ;
return F_80 ( V_75 , V_126 , V_122 ) ;
}
static void F_83 ( struct V_74 * V_75 )
{
V_75 -> V_92 = V_75 -> V_92 != V_75 -> V_91 ? V_75 -> V_92 + 1 : 0 ;
}
static void F_84 ( struct V_74 * V_75 )
{
unsigned int V_92 = V_75 -> V_92 , V_123 = V_92 ;
const struct V_114 * V_115 ;
do {
V_115 = F_79 ( V_75 , V_123 ) ;
if ( V_115 -> V_121 == V_127 )
break;
if ( V_115 -> V_121 != V_128 )
break;
F_83 ( V_75 ) ;
} while ( V_75 -> V_92 != V_92 );
}
static bool F_85 ( struct V_42 * V_43 )
{
struct V_74 * V_75 = & V_43 -> V_54 ;
struct V_114 * V_115 ;
unsigned int V_129 ;
V_115 = F_81 ( V_75 , V_127 ) ;
if ( V_115 == NULL )
return false ;
V_129 = V_75 -> V_92 + V_75 -> V_91 / 2 ;
if ( V_129 > V_75 -> V_91 )
V_129 -= V_75 -> V_91 ;
V_115 = F_79 ( V_75 , V_129 ) ;
return V_115 -> V_121 == V_127 ;
}
static unsigned int F_86 ( struct V_99 * V_99 , struct V_101 * V_1 ,
T_3 * V_52 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_42 * V_43 = F_2 ( V_2 ) ;
unsigned int V_130 ;
int V_78 ;
if ( V_43 -> V_54 . V_55 != NULL ) {
while ( V_43 -> V_131 && F_85 ( V_43 ) ) {
V_78 = F_87 ( V_2 ) ;
if ( V_78 < 0 ) {
V_2 -> V_47 = - V_78 ;
V_2 -> V_49 ( V_2 ) ;
break;
}
}
F_36 ( V_2 ) ;
}
V_130 = F_88 ( V_99 , V_1 , V_52 ) ;
F_61 ( & V_2 -> V_51 . V_90 ) ;
if ( V_43 -> V_54 . V_55 ) {
F_84 ( & V_43 -> V_54 ) ;
if ( ! F_82 ( & V_43 -> V_54 , V_127 ) )
V_130 |= V_132 | V_133 ;
}
F_64 ( & V_2 -> V_51 . V_90 ) ;
F_61 ( & V_2 -> V_79 . V_90 ) ;
if ( V_43 -> V_56 . V_55 ) {
if ( F_81 ( & V_43 -> V_56 , V_127 ) )
V_130 |= V_134 | V_135 ;
}
F_64 ( & V_2 -> V_79 . V_90 ) ;
return V_130 ;
}
static struct V_114 * F_89 ( struct V_20 * V_21 )
{
return (struct V_114 * ) ( V_21 -> V_92 - V_85 ) ;
}
static void F_90 ( struct V_20 * V_21 , struct V_1 * V_2 ,
struct V_74 * V_75 ,
struct V_114 * V_115 )
{
unsigned int V_104 ;
void * V_136 ;
V_104 = V_75 -> V_93 - V_85 ;
V_136 = ( void * ) V_115 + V_85 ;
V_21 -> V_92 = V_136 ;
V_21 -> V_136 = V_136 ;
F_91 ( V_21 ) ;
V_21 -> V_137 = V_21 -> V_138 + V_104 ;
V_21 -> V_58 = 0 ;
V_21 -> V_139 = V_140 ;
F_42 ( V_21 ) . V_3 |= V_53 ;
F_42 ( V_21 ) . V_2 = V_2 ;
}
static int F_92 ( struct V_1 * V_2 , struct V_141 * V_142 ,
T_1 V_143 , T_1 V_144 ,
struct V_145 * V_146 )
{
struct V_42 * V_43 = F_2 ( V_2 ) ;
struct V_74 * V_75 ;
struct V_114 * V_115 ;
struct V_20 * V_21 ;
unsigned int V_147 ;
int V_78 = 0 , V_58 = 0 ;
F_60 ( & V_43 -> V_89 ) ;
V_75 = & V_43 -> V_56 ;
V_147 = V_75 -> V_93 - V_85 ;
do {
unsigned int V_116 ;
V_115 = F_81 ( V_75 , V_148 ) ;
if ( V_115 == NULL ) {
if ( ! ( V_142 -> V_149 & V_150 ) &&
F_56 ( & V_43 -> V_56 . V_82 ) )
F_93 () ;
continue;
}
V_116 = F_94 ( V_115 -> V_116 ) ;
if ( V_116 > V_147 ) {
V_78 = - V_10 ;
goto V_17;
}
F_73 ( V_115 , V_116 ) ;
V_21 = F_95 ( V_116 , V_62 ) ;
if ( V_21 == NULL ) {
V_78 = - V_48 ;
goto V_17;
}
F_96 ( V_21 , V_116 ) ;
memcpy ( V_21 -> V_136 , ( void * ) V_115 + V_85 , V_116 ) ;
F_77 ( V_115 , V_127 ) ;
F_83 ( V_75 ) ;
F_42 ( V_21 ) . V_151 = V_43 -> V_151 ;
F_42 ( V_21 ) . V_144 = V_144 ;
F_42 ( V_21 ) . V_152 = V_146 -> V_152 ;
V_78 = F_97 ( V_2 , V_21 ) ;
if ( V_78 ) {
F_98 ( V_21 ) ;
goto V_17;
}
if ( F_5 ( V_144 ) ) {
F_35 ( & V_21 -> V_153 ) ;
F_99 ( V_2 , V_21 , V_143 , V_144 ,
V_62 ) ;
}
V_78 = F_100 ( V_2 , V_21 , V_143 ,
V_142 -> V_149 & V_150 ) ;
if ( V_78 < 0 )
goto V_17;
V_58 += V_78 ;
} while ( V_115 != NULL ||
( ! ( V_142 -> V_149 & V_150 ) &&
F_56 ( & V_43 -> V_56 . V_82 ) ) );
if ( V_58 > 0 )
V_78 = V_58 ;
V_17:
F_66 ( & V_43 -> V_89 ) ;
return V_78 ;
}
static void F_101 ( struct V_1 * V_2 , struct V_20 * V_21 )
{
struct V_114 * V_115 ;
V_115 = F_89 ( V_21 ) ;
V_115 -> V_116 = V_21 -> V_58 ;
V_115 -> V_154 = F_42 ( V_21 ) . V_144 ;
V_115 -> V_155 = F_42 ( V_21 ) . V_152 . V_156 ;
V_115 -> V_157 = F_102 ( F_103 ( V_2 ) , F_42 ( V_21 ) . V_152 . V_158 ) ;
V_115 -> V_159 = F_104 ( F_103 ( V_2 ) , F_42 ( V_21 ) . V_152 . V_160 ) ;
F_73 ( V_115 , V_115 -> V_116 ) ;
F_77 ( V_115 , V_148 ) ;
F_42 ( V_21 ) . V_3 |= V_161 ;
F_98 ( V_21 ) ;
}
static void F_105 ( struct V_1 * V_2 , struct V_20 * V_21 )
{
struct V_42 * V_43 = F_2 ( V_2 ) ;
struct V_74 * V_75 = & V_43 -> V_54 ;
struct V_114 * V_115 ;
F_61 ( & V_2 -> V_51 . V_90 ) ;
V_115 = F_81 ( V_75 , V_127 ) ;
if ( V_115 == NULL ) {
F_64 ( & V_2 -> V_51 . V_90 ) ;
F_98 ( V_21 ) ;
F_33 ( V_2 ) ;
return;
}
F_83 ( V_75 ) ;
F_106 ( & V_2 -> V_51 , V_21 ) ;
F_64 ( & V_2 -> V_51 . V_90 ) ;
V_115 -> V_116 = V_21 -> V_58 ;
V_115 -> V_154 = F_42 ( V_21 ) . V_144 ;
V_115 -> V_155 = F_42 ( V_21 ) . V_152 . V_156 ;
V_115 -> V_157 = F_102 ( F_103 ( V_2 ) , F_42 ( V_21 ) . V_152 . V_158 ) ;
V_115 -> V_159 = F_104 ( F_103 ( V_2 ) , F_42 ( V_21 ) . V_152 . V_160 ) ;
F_77 ( V_115 , V_162 ) ;
}
static void V_140 ( struct V_20 * V_21 )
{
#ifdef F_107
struct V_114 * V_115 ;
struct V_74 * V_75 ;
struct V_1 * V_2 ;
if ( F_41 ( V_21 ) ) {
V_115 = F_89 ( V_21 ) ;
V_2 = F_42 ( V_21 ) . V_2 ;
if ( F_42 ( V_21 ) . V_3 & V_163 ) {
F_77 ( V_115 , V_127 ) ;
V_75 = & F_2 ( V_2 ) -> V_56 ;
} else {
if ( ! ( F_42 ( V_21 ) . V_3 & V_161 ) ) {
V_115 -> V_116 = 0 ;
F_77 ( V_115 , V_148 ) ;
}
V_75 = & F_2 ( V_2 ) -> V_54 ;
}
F_65 ( F_56 ( & V_75 -> V_82 ) == 0 ) ;
F_69 ( & V_75 -> V_82 ) ;
F_108 ( V_2 ) ;
V_21 -> V_92 = NULL ;
}
#endif
if ( F_46 ( V_21 -> V_92 ) ) {
if ( ! V_21 -> V_164 ||
! F_109 ( & ( F_110 ( V_21 ) -> V_165 ) ) )
F_47 ( V_21 -> V_92 ) ;
V_21 -> V_92 = NULL ;
}
if ( V_21 -> V_2 != NULL )
F_111 ( V_21 ) ;
}
static void F_112 ( struct V_20 * V_21 , struct V_1 * V_2 )
{
F_65 ( V_21 -> V_2 != NULL ) ;
V_21 -> V_2 = V_2 ;
V_21 -> V_139 = V_140 ;
F_113 ( V_21 -> V_166 , & V_2 -> V_167 ) ;
F_114 ( V_2 , V_21 -> V_166 ) ;
}
static void F_115 ( struct V_1 * V_2 )
{
struct V_42 * V_43 = F_2 ( V_2 ) ;
if ( V_43 -> V_131 ) {
if ( V_43 -> V_168 . V_169 )
V_43 -> V_168 . V_169 ( & V_43 -> V_168 ) ;
F_14 ( V_43 -> V_168 . V_14 ) ;
F_98 ( V_43 -> V_168 . V_21 ) ;
}
F_116 ( & V_2 -> V_51 ) ;
#ifdef F_107
if ( 1 ) {
struct V_68 V_69 ;
memset ( & V_69 , 0 , sizeof( V_69 ) ) ;
if ( V_43 -> V_54 . V_55 )
F_55 ( V_2 , & V_69 , true , false ) ;
memset ( & V_69 , 0 , sizeof( V_69 ) ) ;
if ( V_43 -> V_56 . V_55 )
F_55 ( V_2 , & V_69 , true , true ) ;
}
#endif
if ( ! F_117 ( V_2 , V_170 ) ) {
F_118 ( V_171 L_2 , V_2 ) ;
return;
}
F_65 ( F_56 ( & V_2 -> V_167 ) ) ;
F_65 ( F_56 ( & V_2 -> V_172 ) ) ;
F_65 ( F_2 ( V_2 ) -> V_173 ) ;
}
void F_119 ( void )
__acquires( T_4 )
{
F_120 () ;
F_121 ( & T_4 ) ;
if ( F_56 ( & V_174 ) ) {
F_122 ( V_52 , V_175 ) ;
F_123 ( & V_176 , & V_52 ) ;
for (; ; ) {
F_124 ( V_177 ) ;
if ( F_56 ( & V_174 ) == 0 )
break;
F_125 ( & T_4 ) ;
F_93 () ;
F_121 ( & T_4 ) ;
}
F_126 ( V_178 ) ;
F_127 ( & V_176 , & V_52 ) ;
}
}
void F_128 ( void )
__releases( T_4 )
{
F_125 ( & T_4 ) ;
F_129 ( & V_176 ) ;
}
static inline void
F_130 ( void )
{
F_131 ( & T_4 ) ;
F_35 ( & V_174 ) ;
F_132 ( & T_4 ) ;
}
static inline void
F_133 ( void )
{
if ( F_134 ( & V_174 ) )
F_129 ( & V_176 ) ;
}
static bool F_135 ( void * V_179 , void * V_180 )
{
struct V_181 * V_182 = V_180 ;
struct V_1 * V_2 = V_179 ;
return F_2 ( V_2 ) -> V_151 == V_182 -> V_151 &&
F_136 ( F_137 ( V_2 ) , V_182 -> V_183 ) ;
}
static struct V_1 * F_138 ( struct V_184 * V_185 , T_1 V_151 ,
struct V_183 * V_183 )
{
struct V_181 V_180 = {
. V_183 = V_183 ,
. V_151 = V_151 ,
} ;
return F_139 ( & V_185 -> V_186 , & V_151 ,
& F_135 , & V_180 ) ;
}
static bool F_140 ( struct V_184 * V_185 , struct V_1 * V_2 )
{
struct V_181 V_180 = {
. V_183 = F_137 ( V_2 ) ,
. V_151 = F_2 ( V_2 ) -> V_151 ,
} ;
return F_141 ( & V_185 -> V_186 ,
& F_2 ( V_2 ) -> V_187 ,
& F_135 , & V_180 ) ;
}
static struct V_1 * F_142 ( struct V_183 * V_183 , int V_35 , T_1 V_151 )
{
struct V_184 * V_185 = & V_188 [ V_35 ] ;
struct V_1 * V_2 ;
F_29 () ;
V_2 = F_138 ( V_185 , V_151 , V_183 ) ;
if ( V_2 )
F_143 ( V_2 ) ;
F_31 () ;
return V_2 ;
}
static void
F_144 ( struct V_1 * V_2 )
{
struct V_184 * V_189 = & V_188 [ V_2 -> V_22 ] ;
unsigned long V_130 ;
unsigned int V_59 ;
struct V_190 * V_190 ;
V_190 = F_145 ( V_189 -> V_190 ) ;
if ( ! V_190 )
return;
for ( V_59 = 0 ; V_59 < F_146 ( V_189 -> V_173 ) ; V_59 ++ ) {
V_130 = 0 ;
F_147 (sk, &tbl->mc_list) {
if ( V_59 < F_146 ( F_2 ( V_2 ) -> V_191 ) )
V_130 |= F_2 ( V_2 ) -> V_173 [ V_59 ] ;
}
V_190 -> V_192 [ V_59 ] = V_130 ;
}
}
static int F_148 ( struct V_1 * V_2 , T_1 V_151 )
{
struct V_184 * V_185 = & V_188 [ V_2 -> V_22 ] ;
int V_78 ;
F_149 ( V_2 ) ;
V_78 = - V_81 ;
if ( F_2 ( V_2 ) -> V_151 )
goto V_78;
V_78 = - V_33 ;
if ( V_193 > 32 &&
F_5 ( F_56 ( & V_185 -> V_186 . V_194 ) >= V_195 ) )
goto V_78;
F_2 ( V_2 ) -> V_151 = V_151 ;
F_143 ( V_2 ) ;
V_78 = 0 ;
if ( ! F_140 ( V_185 , V_2 ) ) {
V_78 = - V_196 ;
F_108 ( V_2 ) ;
}
V_78:
F_150 ( V_2 ) ;
return V_78 ;
}
static void F_151 ( struct V_1 * V_2 )
{
struct V_184 * V_185 ;
V_185 = & V_188 [ V_2 -> V_22 ] ;
if ( F_152 ( & V_185 -> V_186 , & F_2 ( V_2 ) -> V_187 ) ) {
F_65 ( F_56 ( & V_2 -> V_197 ) == 1 ) ;
F_153 ( V_2 ) ;
}
F_119 () ;
if ( F_2 ( V_2 ) -> V_198 ) {
F_154 ( V_2 ) ;
F_144 ( V_2 ) ;
}
if ( V_2 -> V_22 == V_30 )
F_35 ( & V_199 ) ;
F_128 () ;
}
static int F_155 ( struct V_183 * V_183 , struct V_101 * V_1 ,
struct V_200 * V_201 , int V_35 )
{
struct V_1 * V_2 ;
struct V_42 * V_43 ;
V_1 -> V_202 = & V_203 ;
V_2 = F_156 ( V_183 , V_204 , V_62 , & V_205 ) ;
if ( ! V_2 )
return - V_33 ;
F_157 ( V_1 , V_2 ) ;
V_43 = F_2 ( V_2 ) ;
if ( V_201 ) {
V_43 -> V_201 = V_201 ;
} else {
V_43 -> V_201 = & V_43 -> V_206 ;
F_158 ( V_43 -> V_201 ) ;
}
F_159 ( & V_43 -> V_52 ) ;
#ifdef F_107
F_158 ( & V_43 -> V_89 ) ;
#endif
V_2 -> V_207 = F_115 ;
V_2 -> V_22 = V_35 ;
return 0 ;
}
static int F_160 ( struct V_183 * V_183 , struct V_101 * V_1 , int V_35 ,
int V_208 )
{
struct V_14 * V_14 = NULL ;
struct V_200 * V_201 ;
struct V_42 * V_43 ;
int (* F_161)( struct V_183 * V_183 , int V_5 );
void (* F_162)( struct V_183 * V_183 , int V_5 );
int V_78 = 0 ;
V_1 -> V_46 = V_209 ;
if ( V_1 -> type != V_210 && V_1 -> type != V_211 )
return - V_212 ;
if ( V_35 < 0 || V_35 >= V_213 )
return - V_214 ;
F_130 () ;
#ifdef F_163
if ( ! V_188 [ V_35 ] . V_215 ) {
F_133 () ;
F_164 ( L_3 , V_204 , V_35 ) ;
F_130 () ;
}
#endif
if ( V_188 [ V_35 ] . V_215 &&
F_165 ( V_188 [ V_35 ] . V_14 ) )
V_14 = V_188 [ V_35 ] . V_14 ;
else
V_78 = - V_214 ;
V_201 = V_188 [ V_35 ] . V_201 ;
F_161 = V_188 [ V_35 ] . F_161 ;
F_162 = V_188 [ V_35 ] . F_162 ;
F_133 () ;
if ( V_78 < 0 )
goto V_17;
V_78 = F_155 ( V_183 , V_1 , V_201 , V_35 ) ;
if ( V_78 < 0 )
goto V_216;
F_166 () ;
F_167 ( V_183 , & V_205 , 1 ) ;
F_168 () ;
V_43 = F_2 ( V_1 -> V_2 ) ;
V_43 -> V_14 = V_14 ;
V_43 -> V_217 = F_161 ;
V_43 -> V_218 = F_162 ;
V_17:
return V_78 ;
V_216:
F_14 ( V_14 ) ;
goto V_17;
}
static void F_169 ( struct V_219 * V_92 )
{
struct V_42 * V_43 = F_170 ( V_92 , struct V_42 , V_220 ) ;
F_108 ( & V_43 -> V_2 ) ;
}
static int F_171 ( struct V_101 * V_1 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_42 * V_43 ;
if ( ! V_2 )
return 0 ;
F_151 ( V_2 ) ;
F_172 ( V_2 ) ;
V_43 = F_2 ( V_2 ) ;
if ( V_43 -> V_218 ) {
int V_59 ;
for ( V_59 = 0 ; V_59 < V_43 -> V_191 ; V_59 ++ )
if ( F_39 ( V_59 , V_43 -> V_173 ) )
V_43 -> V_218 ( F_137 ( V_2 ) , V_59 + 1 ) ;
}
if ( V_2 -> V_22 == V_30 &&
F_109 ( & V_199 ) == 0 )
F_129 ( & V_221 ) ;
V_1 -> V_2 = NULL ;
F_173 ( & V_43 -> V_52 ) ;
F_116 ( & V_2 -> V_79 ) ;
if ( V_43 -> V_151 ) {
struct V_222 V_129 = {
. V_183 = F_137 ( V_2 ) ,
. V_35 = V_2 -> V_22 ,
. V_151 = V_43 -> V_151 ,
} ;
F_174 ( & V_223 ,
V_224 , & V_129 ) ;
}
F_14 ( V_43 -> V_14 ) ;
if ( F_1 ( V_2 ) ) {
F_119 () ;
F_175 ( V_188 [ V_2 -> V_22 ] . V_215 == 0 ) ;
if ( -- V_188 [ V_2 -> V_22 ] . V_215 == 0 ) {
struct V_190 * V_225 ;
V_225 = F_145 ( V_188 [ V_2 -> V_22 ] . V_190 ) ;
F_176 ( V_188 [ V_2 -> V_22 ] . V_190 , NULL ) ;
F_177 ( V_225 , V_220 ) ;
V_188 [ V_2 -> V_22 ] . V_14 = NULL ;
V_188 [ V_2 -> V_22 ] . F_161 = NULL ;
V_188 [ V_2 -> V_22 ] . F_162 = NULL ;
V_188 [ V_2 -> V_22 ] . V_3 = 0 ;
V_188 [ V_2 -> V_22 ] . V_215 = 0 ;
}
F_128 () ;
}
F_49 ( V_43 -> V_173 ) ;
V_43 -> V_173 = NULL ;
F_166 () ;
F_167 ( F_137 ( V_2 ) , & V_205 , - 1 ) ;
F_168 () ;
F_178 ( & V_43 -> V_220 , F_169 ) ;
return 0 ;
}
static int F_179 ( struct V_101 * V_1 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_183 * V_183 = F_137 ( V_2 ) ;
struct V_184 * V_185 = & V_188 [ V_2 -> V_22 ] ;
T_5 V_151 = F_180 ( V_175 ) ;
int V_78 ;
static T_5 V_226 = - 4097 ;
V_227:
F_181 () ;
F_29 () ;
if ( F_138 ( V_185 , V_151 , V_183 ) ) {
V_151 = V_226 -- ;
if ( V_226 > - 4097 )
V_226 = - 4097 ;
F_31 () ;
goto V_227;
}
F_31 () ;
V_78 = F_148 ( V_2 , V_151 ) ;
if ( V_78 == - V_196 )
goto V_227;
if ( V_78 == - V_81 )
V_78 = 0 ;
return V_78 ;
}
bool F_182 ( const struct V_228 * V_229 ,
struct V_230 * V_231 , int V_232 )
{
return ( ( V_229 -> V_3 & V_233 ) ||
F_183 ( V_229 -> V_2 -> V_234 -> V_99 , V_231 , V_232 ) ) &&
F_184 ( V_231 , V_232 ) ;
}
bool F_185 ( const struct V_20 * V_21 ,
struct V_230 * V_231 , int V_232 )
{
return F_182 ( & F_42 ( V_21 ) , V_231 , V_232 ) ;
}
bool F_186 ( const struct V_20 * V_21 , int V_232 )
{
return F_185 ( V_21 , & V_235 , V_232 ) ;
}
bool F_187 ( const struct V_20 * V_21 , int V_232 )
{
return F_185 ( V_21 , F_137 ( V_21 -> V_2 ) -> V_231 , V_232 ) ;
}
static inline int F_188 ( const struct V_101 * V_1 , unsigned int V_236 )
{
return ( V_188 [ V_1 -> V_2 -> V_22 ] . V_3 & V_236 ) ||
F_184 ( F_137 ( V_1 -> V_2 ) -> V_231 , V_237 ) ;
}
static void
F_189 ( struct V_1 * V_2 , unsigned int V_198 )
{
struct V_42 * V_43 = F_2 ( V_2 ) ;
if ( V_43 -> V_198 && ! V_198 )
F_154 ( V_2 ) ;
else if ( ! V_43 -> V_198 && V_198 )
F_190 ( V_2 , & V_188 [ V_2 -> V_22 ] . V_238 ) ;
V_43 -> V_198 = V_198 ;
}
static int F_191 ( struct V_1 * V_2 )
{
struct V_42 * V_43 = F_2 ( V_2 ) ;
unsigned int V_173 ;
unsigned long * V_239 ;
int V_78 = 0 ;
F_119 () ;
V_173 = V_188 [ V_2 -> V_22 ] . V_173 ;
if ( ! V_188 [ V_2 -> V_22 ] . V_215 ) {
V_78 = - V_240 ;
goto V_241;
}
if ( V_43 -> V_191 >= V_173 )
goto V_241;
V_239 = F_192 ( V_43 -> V_173 , F_193 ( V_173 ) , V_34 ) ;
if ( V_239 == NULL ) {
V_78 = - V_33 ;
goto V_241;
}
memset ( ( char * ) V_239 + F_193 ( V_43 -> V_191 ) , 0 ,
F_193 ( V_173 ) - F_193 ( V_43 -> V_191 ) ) ;
V_43 -> V_173 = V_239 ;
V_43 -> V_191 = V_173 ;
V_241:
F_128 () ;
return V_78 ;
}
static void F_194 ( int V_5 , long unsigned int V_173 ,
struct V_1 * V_2 )
{
struct V_42 * V_43 = F_2 ( V_2 ) ;
int V_242 ;
if ( ! V_43 -> V_218 )
return;
for ( V_242 = 0 ; V_242 < V_5 ; V_242 ++ )
if ( F_39 ( V_242 , & V_173 ) )
V_43 -> V_218 ( F_137 ( V_2 ) , V_242 + 1 ) ;
}
static int V_217 ( struct V_101 * V_1 , struct V_243 * V_244 ,
int V_245 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_183 * V_183 = F_137 ( V_2 ) ;
struct V_42 * V_43 = F_2 ( V_2 ) ;
struct V_246 * V_247 = (struct V_246 * ) V_244 ;
int V_78 ;
long unsigned int V_173 = V_247 -> V_248 ;
if ( V_245 < sizeof( struct V_246 ) )
return - V_10 ;
if ( V_247 -> V_249 != V_250 )
return - V_10 ;
if ( V_173 ) {
if ( ! F_188 ( V_1 , V_251 ) )
return - V_252 ;
V_78 = F_191 ( V_2 ) ;
if ( V_78 )
return V_78 ;
}
if ( V_43 -> V_151 )
if ( V_247 -> V_253 != V_43 -> V_151 )
return - V_10 ;
if ( V_43 -> V_217 && V_173 ) {
int V_5 ;
for ( V_5 = 0 ; V_5 < V_43 -> V_191 ; V_5 ++ ) {
if ( ! F_39 ( V_5 , & V_173 ) )
continue;
V_78 = V_43 -> V_217 ( V_183 , V_5 + 1 ) ;
if ( ! V_78 )
continue;
F_194 ( V_5 , V_173 , V_2 ) ;
return V_78 ;
}
}
if ( ! V_43 -> V_151 ) {
V_78 = V_247 -> V_253 ?
F_148 ( V_2 , V_247 -> V_253 ) :
F_179 ( V_1 ) ;
if ( V_78 ) {
F_194 ( V_43 -> V_191 , V_173 , V_2 ) ;
return V_78 ;
}
}
if ( ! V_173 && ( V_43 -> V_173 == NULL || ! ( T_1 ) V_43 -> V_173 [ 0 ] ) )
return 0 ;
F_119 () ;
F_189 ( V_2 , V_43 -> V_198 +
F_195 ( V_173 ) -
F_195 ( V_43 -> V_173 [ 0 ] ) ) ;
V_43 -> V_173 [ 0 ] = ( V_43 -> V_173 [ 0 ] & ~ 0xffffffffUL ) | V_173 ;
F_144 ( V_2 ) ;
F_128 () ;
return 0 ;
}
static int F_196 ( struct V_101 * V_1 , struct V_243 * V_244 ,
int V_254 , int V_3 )
{
int V_78 = 0 ;
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_42 * V_43 = F_2 ( V_2 ) ;
struct V_246 * V_247 = (struct V_246 * ) V_244 ;
if ( V_254 < sizeof( V_244 -> V_255 ) )
return - V_10 ;
if ( V_244 -> V_255 == V_256 ) {
V_2 -> V_257 = V_258 ;
V_43 -> V_143 = 0 ;
V_43 -> V_144 = 0 ;
return 0 ;
}
if ( V_244 -> V_255 != V_250 )
return - V_10 ;
if ( ( V_247 -> V_248 || V_247 -> V_253 ) &&
! F_188 ( V_1 , V_259 ) )
return - V_252 ;
if ( ! V_43 -> V_151 )
V_78 = F_179 ( V_1 ) ;
if ( V_78 == 0 ) {
V_2 -> V_257 = V_260 ;
V_43 -> V_143 = V_247 -> V_253 ;
V_43 -> V_144 = F_197 ( V_247 -> V_248 ) ;
}
return V_78 ;
}
static int F_198 ( struct V_101 * V_1 , struct V_243 * V_244 ,
int * V_245 , int V_261 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_42 * V_43 = F_2 ( V_2 ) ;
F_199 ( struct V_246 * , V_247 , V_244 ) ;
V_247 -> V_249 = V_250 ;
V_247 -> V_262 = 0 ;
* V_245 = sizeof( * V_247 ) ;
if ( V_261 ) {
V_247 -> V_253 = V_43 -> V_143 ;
V_247 -> V_248 = F_3 ( V_43 -> V_144 ) ;
} else {
V_247 -> V_253 = V_43 -> V_151 ;
V_247 -> V_248 = V_43 -> V_173 ? V_43 -> V_173 [ 0 ] : 0 ;
}
return 0 ;
}
static struct V_1 * F_200 ( struct V_1 * V_263 , T_1 V_151 )
{
struct V_1 * V_1 ;
struct V_42 * V_43 ;
V_1 = F_142 ( F_137 ( V_263 ) , V_263 -> V_22 , V_151 ) ;
if ( ! V_1 )
return F_201 ( - V_264 ) ;
V_43 = F_2 ( V_1 ) ;
if ( V_1 -> V_257 == V_260 &&
V_43 -> V_143 != F_2 ( V_263 ) -> V_151 ) {
F_108 ( V_1 ) ;
return F_201 ( - V_264 ) ;
}
return V_1 ;
}
struct V_1 * F_202 ( struct V_99 * V_265 )
{
struct V_266 * V_266 = F_203 ( V_265 ) ;
struct V_1 * V_1 ;
if ( ! F_204 ( V_266 -> V_267 ) )
return F_201 ( - V_268 ) ;
V_1 = F_205 ( V_266 ) -> V_2 ;
if ( V_1 -> V_269 != V_250 )
return F_201 ( - V_10 ) ;
F_143 ( V_1 ) ;
return V_1 ;
}
static struct V_20 * F_206 ( unsigned int V_104 ,
int V_270 )
{
struct V_20 * V_21 ;
void * V_136 ;
if ( V_104 <= V_271 || V_270 )
return F_95 ( V_104 , V_62 ) ;
V_104 = F_207 ( V_104 ) +
F_207 ( sizeof( struct V_272 ) ) ;
V_136 = F_208 ( V_104 ) ;
if ( V_136 == NULL )
return NULL ;
V_21 = F_209 ( V_136 , V_104 ) ;
if ( V_21 == NULL )
F_47 ( V_136 ) ;
else {
V_21 -> V_273 = 0 ;
V_21 -> V_139 = V_140 ;
}
return V_21 ;
}
int F_210 ( struct V_1 * V_2 , struct V_20 * V_21 ,
long * V_274 , struct V_1 * V_263 )
{
struct V_42 * V_43 ;
V_43 = F_2 ( V_2 ) ;
if ( ( F_56 ( & V_2 -> V_167 ) > V_2 -> V_275 ||
F_39 ( V_45 , & V_43 -> V_46 ) ) &&
! F_41 ( V_21 ) ) {
F_122 ( V_52 , V_175 ) ;
if ( ! * V_274 ) {
if ( ! V_263 || F_1 ( V_263 ) )
F_33 ( V_2 ) ;
F_108 ( V_2 ) ;
F_98 ( V_21 ) ;
return - V_276 ;
}
F_126 ( V_277 ) ;
F_211 ( & V_43 -> V_52 , & V_52 ) ;
if ( ( F_56 ( & V_2 -> V_167 ) > V_2 -> V_275 ||
F_39 ( V_45 , & V_43 -> V_46 ) ) &&
! F_117 ( V_2 , V_170 ) )
* V_274 = F_212 ( * V_274 ) ;
F_126 ( V_178 ) ;
F_127 ( & V_43 -> V_52 , & V_52 ) ;
F_108 ( V_2 ) ;
if ( F_213 ( V_175 ) ) {
F_98 ( V_21 ) ;
return F_214 ( * V_274 ) ;
}
return 1 ;
}
F_112 ( V_21 , V_2 ) ;
return 0 ;
}
static int F_215 ( struct V_1 * V_2 , struct V_20 * V_21 )
{
int V_58 = V_21 -> V_58 ;
F_28 ( V_21 ) ;
#ifdef F_107
if ( F_41 ( V_21 ) )
F_101 ( V_2 , V_21 ) ;
else if ( F_43 ( V_2 ) )
F_105 ( V_2 , V_21 ) ;
else
#endif
F_216 ( & V_2 -> V_51 , V_21 ) ;
V_2 -> V_278 ( V_2 ) ;
return V_58 ;
}
int F_217 ( struct V_1 * V_2 , struct V_20 * V_21 )
{
int V_58 = F_215 ( V_2 , V_21 ) ;
F_108 ( V_2 ) ;
return V_58 ;
}
void F_218 ( struct V_1 * V_2 , struct V_20 * V_21 )
{
F_98 ( V_21 ) ;
F_108 ( V_2 ) ;
}
static struct V_20 * F_219 ( struct V_20 * V_21 , T_2 V_279 )
{
int V_280 ;
F_65 ( V_21 -> V_2 != NULL ) ;
if ( F_41 ( V_21 ) )
return V_21 ;
V_280 = V_21 -> V_137 - V_21 -> V_138 ;
if ( F_46 ( V_21 -> V_92 ) || V_280 * 2 < V_21 -> V_166 )
return V_21 ;
if ( F_220 ( V_21 ) ) {
struct V_20 * V_32 = F_20 ( V_21 , V_279 ) ;
if ( ! V_32 )
return V_21 ;
F_221 ( V_21 ) ;
V_21 = V_32 ;
}
if ( ! F_222 ( V_21 , 0 , - V_280 , V_279 ) )
V_21 -> V_166 -= V_280 ;
return V_21 ;
}
static int F_223 ( struct V_1 * V_2 , struct V_20 * V_21 ,
struct V_1 * V_263 )
{
int V_19 ;
struct V_42 * V_43 = F_2 ( V_2 ) ;
V_19 = - V_264 ;
if ( V_43 -> V_281 != NULL ) {
V_19 = V_21 -> V_58 ;
F_112 ( V_21 , V_2 ) ;
F_42 ( V_21 ) . V_2 = V_263 ;
F_32 ( V_2 , V_263 , V_21 ) ;
V_43 -> V_281 ( V_21 ) ;
F_221 ( V_21 ) ;
} else {
F_98 ( V_21 ) ;
}
F_108 ( V_2 ) ;
return V_19 ;
}
int F_100 ( struct V_1 * V_263 , struct V_20 * V_21 ,
T_1 V_151 , int V_282 )
{
struct V_1 * V_2 ;
int V_78 ;
long V_274 ;
V_21 = F_219 ( V_21 , F_224 () ) ;
V_274 = F_225 ( V_263 , V_282 ) ;
V_227:
V_2 = F_200 ( V_263 , V_151 ) ;
if ( F_226 ( V_2 ) ) {
F_98 ( V_21 ) ;
return F_227 ( V_2 ) ;
}
if ( F_1 ( V_2 ) )
return F_223 ( V_2 , V_21 , V_263 ) ;
if ( F_228 ( V_2 , V_21 ) ) {
V_78 = V_21 -> V_58 ;
F_98 ( V_21 ) ;
F_108 ( V_2 ) ;
return V_78 ;
}
V_78 = F_210 ( V_2 , V_21 , & V_274 , V_263 ) ;
if ( V_78 == 1 )
goto V_227;
if ( V_78 )
return V_78 ;
return F_217 ( V_2 , V_21 ) ;
}
struct V_20 * F_229 ( struct V_1 * V_263 , unsigned int V_104 ,
T_1 V_143 , T_2 V_283 )
{
#ifdef F_107
struct V_1 * V_2 = NULL ;
struct V_20 * V_21 ;
struct V_74 * V_75 ;
struct V_114 * V_115 ;
unsigned int V_147 ;
V_2 = F_200 ( V_263 , V_143 ) ;
if ( F_226 ( V_2 ) )
goto V_17;
V_75 = & F_2 ( V_2 ) -> V_54 ;
if ( V_75 -> V_55 == NULL )
goto V_284;
if ( V_75 -> V_93 - V_85 < V_104 )
goto V_284;
V_21 = F_230 ( V_283 ) ;
if ( V_21 == NULL )
goto V_72;
F_61 ( & V_2 -> V_51 . V_90 ) ;
if ( V_75 -> V_55 == NULL )
goto V_285;
V_147 = V_75 -> V_93 - V_85 ;
if ( V_147 < V_104 )
goto V_285;
F_84 ( V_75 ) ;
V_115 = F_81 ( V_75 , V_127 ) ;
if ( V_115 == NULL )
goto V_286;
F_90 ( V_21 , V_2 , V_75 , V_115 ) ;
F_77 ( V_115 , V_287 ) ;
F_35 ( & V_75 -> V_82 ) ;
F_83 ( V_75 ) ;
F_64 ( & V_2 -> V_51 . V_90 ) ;
return V_21 ;
V_286:
F_98 ( V_21 ) ;
F_64 ( & V_2 -> V_51 . V_90 ) ;
F_33 ( V_2 ) ;
V_72:
F_108 ( V_2 ) ;
return NULL ;
V_285:
F_98 ( V_21 ) ;
F_64 ( & V_2 -> V_51 . V_90 ) ;
V_284:
F_108 ( V_2 ) ;
V_17:
#endif
return F_95 ( V_104 , V_283 ) ;
}
int F_231 ( struct V_1 * V_2 , unsigned int V_5 )
{
int V_288 = 0 ;
struct V_190 * V_190 ;
F_175 ( ! F_1 ( V_2 ) ) ;
F_29 () ;
V_190 = F_232 ( V_188 [ V_2 -> V_22 ] . V_190 ) ;
if ( V_190 && V_5 - 1 < V_188 [ V_2 -> V_22 ] . V_173 )
V_288 = F_39 ( V_5 - 1 , V_190 -> V_192 ) ;
F_31 () ;
return V_288 ;
}
static int F_233 ( struct V_1 * V_2 , struct V_20 * V_21 )
{
struct V_42 * V_43 = F_2 ( V_2 ) ;
if ( F_56 ( & V_2 -> V_167 ) <= V_2 -> V_275 &&
! F_39 ( V_45 , & V_43 -> V_46 ) ) {
F_112 ( V_21 , V_2 ) ;
F_215 ( V_2 , V_21 ) ;
return F_56 ( & V_2 -> V_167 ) > ( V_2 -> V_275 >> 1 ) ;
}
return - 1 ;
}
static void F_234 ( struct V_1 * V_2 ,
struct V_289 * V_290 )
{
struct V_42 * V_43 = F_2 ( V_2 ) ;
int V_291 ;
if ( V_290 -> V_292 == V_2 )
return;
if ( V_43 -> V_151 == V_290 -> V_151 || V_290 -> V_5 - 1 >= V_43 -> V_191 ||
! F_39 ( V_290 -> V_5 - 1 , V_43 -> V_173 ) )
return;
if ( ! F_136 ( F_137 ( V_2 ) , V_290 -> V_183 ) )
return;
if ( V_290 -> V_293 ) {
F_33 ( V_2 ) ;
return;
}
F_143 ( V_2 ) ;
if ( V_290 -> V_294 == NULL ) {
if ( F_220 ( V_290 -> V_21 ) ) {
V_290 -> V_294 = F_20 ( V_290 -> V_21 , V_290 -> V_279 ) ;
} else {
V_290 -> V_294 = F_235 ( V_290 -> V_21 ) ;
F_236 ( V_290 -> V_294 ) ;
}
}
if ( V_290 -> V_294 == NULL ) {
F_33 ( V_2 ) ;
V_290 -> V_293 = 1 ;
if ( V_43 -> V_3 & V_295 )
V_290 -> V_296 = 1 ;
} else if ( V_290 -> V_297 && V_290 -> V_297 ( V_2 , V_290 -> V_294 , V_290 -> V_298 ) ) {
F_98 ( V_290 -> V_294 ) ;
V_290 -> V_294 = NULL ;
} else if ( F_228 ( V_2 , V_290 -> V_294 ) ) {
F_98 ( V_290 -> V_294 ) ;
V_290 -> V_294 = NULL ;
} else if ( ( V_291 = F_233 ( V_2 , V_290 -> V_294 ) ) < 0 ) {
F_33 ( V_2 ) ;
if ( V_43 -> V_3 & V_295 )
V_290 -> V_296 = 1 ;
} else {
V_290 -> V_299 |= V_291 ;
V_290 -> V_300 = 1 ;
V_290 -> V_294 = NULL ;
}
F_108 ( V_2 ) ;
}
int F_237 ( struct V_1 * V_263 , struct V_20 * V_21 , T_1 V_151 ,
T_1 V_5 , T_2 V_279 ,
int (* F_238)( struct V_1 * V_301 , struct V_20 * V_21 , void * V_136 ) ,
void * V_302 )
{
struct V_183 * V_183 = F_137 ( V_263 ) ;
struct V_289 V_303 ;
struct V_1 * V_2 ;
V_21 = F_219 ( V_21 , V_279 ) ;
V_303 . V_292 = V_263 ;
V_303 . V_183 = V_183 ;
V_303 . V_151 = V_151 ;
V_303 . V_5 = V_5 ;
V_303 . V_293 = 0 ;
V_303 . V_296 = 0 ;
V_303 . V_299 = 0 ;
V_303 . V_300 = 0 ;
V_303 . V_279 = V_279 ;
V_303 . V_21 = V_21 ;
V_303 . V_294 = NULL ;
V_303 . V_297 = F_238 ;
V_303 . V_298 = V_302 ;
F_130 () ;
F_147 (sk, &nl_table[ssk->sk_protocol].mc_list)
F_234 ( V_2 , & V_303 ) ;
F_221 ( V_21 ) ;
F_133 () ;
if ( V_303 . V_296 ) {
F_98 ( V_303 . V_294 ) ;
return - V_48 ;
}
F_221 ( V_303 . V_294 ) ;
if ( V_303 . V_300 ) {
if ( V_303 . V_299 && ( V_279 & V_304 ) )
F_239 () ;
return 0 ;
}
return - V_305 ;
}
int F_99 ( struct V_1 * V_263 , struct V_20 * V_21 , T_1 V_151 ,
T_1 V_5 , T_2 V_279 )
{
return F_237 ( V_263 , V_21 , V_151 , V_5 , V_279 ,
NULL , NULL ) ;
}
static int F_240 ( struct V_1 * V_2 , struct V_306 * V_290 )
{
struct V_42 * V_43 = F_2 ( V_2 ) ;
int V_19 = 0 ;
if ( V_2 == V_290 -> V_292 )
goto V_17;
if ( ! F_136 ( F_137 ( V_2 ) , F_137 ( V_290 -> V_292 ) ) )
goto V_17;
if ( V_43 -> V_151 == V_290 -> V_151 || V_290 -> V_5 - 1 >= V_43 -> V_191 ||
! F_39 ( V_290 -> V_5 - 1 , V_43 -> V_173 ) )
goto V_17;
if ( V_290 -> V_307 == V_48 && V_43 -> V_3 & V_44 ) {
V_19 = 1 ;
goto V_17;
}
V_2 -> V_47 = V_290 -> V_307 ;
V_2 -> V_49 ( V_2 ) ;
V_17:
return V_19 ;
}
int F_241 ( struct V_1 * V_263 , T_1 V_151 , T_1 V_5 , int V_307 )
{
struct V_306 V_303 ;
struct V_1 * V_2 ;
int V_19 = 0 ;
V_303 . V_292 = V_263 ;
V_303 . V_151 = V_151 ;
V_303 . V_5 = V_5 ;
V_303 . V_307 = - V_307 ;
F_131 ( & T_4 ) ;
F_147 (sk, &nl_table[ssk->sk_protocol].mc_list)
V_19 += F_240 ( V_2 , & V_303 ) ;
F_132 ( & T_4 ) ;
return V_19 ;
}
static void F_242 ( struct V_42 * V_43 ,
unsigned int V_5 ,
int V_308 )
{
int V_225 , V_309 = ! ! V_308 , V_198 ;
V_225 = F_39 ( V_5 - 1 , V_43 -> V_173 ) ;
V_198 = V_43 -> V_198 - V_225 + V_309 ;
if ( V_309 )
F_243 ( V_5 - 1 , V_43 -> V_173 ) ;
else
F_244 ( V_5 - 1 , V_43 -> V_173 ) ;
F_189 ( & V_43 -> V_2 , V_198 ) ;
F_144 ( & V_43 -> V_2 ) ;
}
static int F_245 ( struct V_101 * V_1 , int V_310 , int V_311 ,
char T_6 * V_312 , unsigned int V_313 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_42 * V_43 = F_2 ( V_2 ) ;
unsigned int V_291 = 0 ;
int V_78 ;
if ( V_310 != V_314 )
return - V_315 ;
if ( V_311 != V_316 && V_311 != V_317 &&
V_313 >= sizeof( int ) &&
F_246 ( V_291 , ( unsigned int T_6 * ) V_312 ) )
return - V_318 ;
switch ( V_311 ) {
case V_319 :
if ( V_291 )
V_43 -> V_3 |= V_320 ;
else
V_43 -> V_3 &= ~ V_320 ;
V_78 = 0 ;
break;
case V_321 :
case V_322 : {
if ( ! F_188 ( V_1 , V_251 ) )
return - V_252 ;
V_78 = F_191 ( V_2 ) ;
if ( V_78 )
return V_78 ;
if ( ! V_291 || V_291 - 1 >= V_43 -> V_191 )
return - V_10 ;
if ( V_311 == V_321 && V_43 -> V_217 ) {
V_78 = V_43 -> V_217 ( F_137 ( V_2 ) , V_291 ) ;
if ( V_78 )
return V_78 ;
}
F_119 () ;
F_242 ( V_43 , V_291 ,
V_311 == V_321 ) ;
F_128 () ;
if ( V_311 == V_322 && V_43 -> V_218 )
V_43 -> V_218 ( F_137 ( V_2 ) , V_291 ) ;
V_78 = 0 ;
break;
}
case V_323 :
if ( V_291 )
V_43 -> V_3 |= V_295 ;
else
V_43 -> V_3 &= ~ V_295 ;
V_78 = 0 ;
break;
case V_324 :
if ( V_291 ) {
V_43 -> V_3 |= V_44 ;
F_38 ( V_45 , & V_43 -> V_46 ) ;
F_40 ( & V_43 -> V_52 ) ;
} else {
V_43 -> V_3 &= ~ V_44 ;
}
V_78 = 0 ;
break;
#ifdef F_107
case V_316 :
case V_317 : {
struct V_68 V_69 ;
if ( ! F_247 ( V_237 ) )
return - V_252 ;
if ( V_313 < sizeof( V_69 ) )
return - V_10 ;
if ( F_248 ( & V_69 , V_312 , sizeof( V_69 ) ) )
return - V_318 ;
V_78 = F_55 ( V_2 , & V_69 , false ,
V_311 == V_317 ) ;
break;
}
#endif
default:
V_78 = - V_315 ;
}
return V_78 ;
}
static int F_249 ( struct V_101 * V_1 , int V_310 , int V_311 ,
char T_6 * V_312 , int T_6 * V_313 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_42 * V_43 = F_2 ( V_2 ) ;
int V_58 , V_291 , V_78 ;
if ( V_310 != V_314 )
return - V_315 ;
if ( F_246 ( V_58 , V_313 ) )
return - V_318 ;
if ( V_58 < 0 )
return - V_10 ;
switch ( V_311 ) {
case V_319 :
if ( V_58 < sizeof( int ) )
return - V_10 ;
V_58 = sizeof( int ) ;
V_291 = V_43 -> V_3 & V_320 ? 1 : 0 ;
if ( F_250 ( V_58 , V_313 ) ||
F_250 ( V_291 , V_312 ) )
return - V_318 ;
V_78 = 0 ;
break;
case V_323 :
if ( V_58 < sizeof( int ) )
return - V_10 ;
V_58 = sizeof( int ) ;
V_291 = V_43 -> V_3 & V_295 ? 1 : 0 ;
if ( F_250 ( V_58 , V_313 ) ||
F_250 ( V_291 , V_312 ) )
return - V_318 ;
V_78 = 0 ;
break;
case V_324 :
if ( V_58 < sizeof( int ) )
return - V_10 ;
V_58 = sizeof( int ) ;
V_291 = V_43 -> V_3 & V_44 ? 1 : 0 ;
if ( F_250 ( V_58 , V_313 ) ||
F_250 ( V_291 , V_312 ) )
return - V_318 ;
V_78 = 0 ;
break;
default:
V_78 = - V_315 ;
}
return V_78 ;
}
static void F_251 ( struct V_141 * V_142 , struct V_20 * V_21 )
{
struct V_325 V_303 ;
V_303 . V_5 = F_42 ( V_21 ) . V_144 ;
F_252 ( V_142 , V_314 , V_319 , sizeof( V_303 ) , & V_303 ) ;
}
static int F_253 ( struct V_326 * V_326 , struct V_101 * V_1 ,
struct V_141 * V_142 , T_7 V_58 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_42 * V_43 = F_2 ( V_2 ) ;
F_199 ( struct V_246 * , V_244 , V_142 -> V_327 ) ;
T_1 V_143 ;
T_1 V_144 ;
struct V_20 * V_21 ;
int V_78 ;
struct V_145 V_146 ;
T_1 V_328 = 0 ;
if ( V_142 -> V_149 & V_329 )
return - V_330 ;
V_78 = F_254 ( V_1 , V_142 , & V_146 , true ) ;
if ( V_78 < 0 )
return V_78 ;
if ( V_142 -> V_331 ) {
V_78 = - V_10 ;
if ( V_244 -> V_249 != V_250 )
goto V_17;
V_143 = V_244 -> V_253 ;
V_144 = F_197 ( V_244 -> V_248 ) ;
V_78 = - V_252 ;
if ( ( V_144 || V_143 ) &&
! F_188 ( V_1 , V_259 ) )
goto V_17;
V_328 |= V_233 ;
} else {
V_143 = V_43 -> V_143 ;
V_144 = V_43 -> V_144 ;
}
if ( ! V_43 -> V_151 ) {
V_78 = F_179 ( V_1 ) ;
if ( V_78 )
goto V_17;
}
if ( F_44 ( V_2 ) &&
V_142 -> V_332 . type == V_333 &&
V_142 -> V_332 . V_334 == 1 &&
V_142 -> V_332 . V_335 -> V_336 == NULL ) {
V_78 = F_92 ( V_2 , V_142 , V_143 , V_144 ,
& V_146 ) ;
goto V_17;
}
V_78 = - V_337 ;
if ( V_58 > V_2 -> V_338 - 32 )
goto V_17;
V_78 = - V_48 ;
V_21 = F_206 ( V_58 , V_144 ) ;
if ( V_21 == NULL )
goto V_17;
F_42 ( V_21 ) . V_151 = V_43 -> V_151 ;
F_42 ( V_21 ) . V_144 = V_144 ;
F_42 ( V_21 ) . V_152 = V_146 . V_152 ;
F_42 ( V_21 ) . V_3 = V_328 ;
V_78 = - V_318 ;
if ( F_255 ( F_256 ( V_21 , V_58 ) , V_142 , V_58 ) ) {
F_98 ( V_21 ) ;
goto V_17;
}
V_78 = F_97 ( V_2 , V_21 ) ;
if ( V_78 ) {
F_98 ( V_21 ) ;
goto V_17;
}
if ( V_144 ) {
F_35 ( & V_21 -> V_153 ) ;
F_99 ( V_2 , V_21 , V_143 , V_144 , V_62 ) ;
}
V_78 = F_100 ( V_2 , V_21 , V_143 , V_142 -> V_149 & V_150 ) ;
V_17:
F_257 ( & V_146 ) ;
return V_78 ;
}
static int F_258 ( struct V_326 * V_326 , struct V_101 * V_1 ,
struct V_141 * V_142 , T_7 V_58 ,
int V_3 )
{
struct V_145 V_146 ;
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_42 * V_43 = F_2 ( V_2 ) ;
int V_339 = V_3 & V_150 ;
T_7 V_340 ;
struct V_20 * V_21 , * V_341 ;
int V_78 , V_19 ;
if ( V_3 & V_329 )
return - V_330 ;
V_340 = 0 ;
V_21 = F_259 ( V_2 , V_3 , V_339 , & V_78 ) ;
if ( V_21 == NULL )
goto V_17;
V_341 = V_21 ;
#ifdef F_260
if ( F_5 ( F_110 ( V_21 ) -> V_342 ) ) {
if ( V_3 & V_343 )
V_341 = F_110 ( V_21 ) -> V_342 ;
}
#endif
V_43 -> V_344 = F_261 ( V_43 -> V_344 , V_58 ) ;
V_43 -> V_344 = F_262 ( T_7 , V_43 -> V_344 ,
16384 ) ;
V_340 = V_341 -> V_58 ;
if ( V_58 < V_340 ) {
V_142 -> V_149 |= V_345 ;
V_340 = V_58 ;
}
F_263 ( V_341 ) ;
V_78 = F_264 ( V_341 , 0 , V_142 , V_340 ) ;
if ( V_142 -> V_327 ) {
F_199 ( struct V_246 * , V_244 , V_142 -> V_327 ) ;
V_244 -> V_249 = V_250 ;
V_244 -> V_262 = 0 ;
V_244 -> V_253 = F_42 ( V_21 ) . V_151 ;
V_244 -> V_248 = F_3 ( F_42 ( V_21 ) . V_144 ) ;
V_142 -> V_331 = sizeof( * V_244 ) ;
}
if ( V_43 -> V_3 & V_320 )
F_251 ( V_142 , V_21 ) ;
memset ( & V_146 , 0 , sizeof( V_146 ) ) ;
V_146 . V_152 = * F_265 ( V_21 ) ;
if ( V_3 & V_345 )
V_340 = V_341 -> V_58 ;
F_266 ( V_2 , V_21 ) ;
if ( V_43 -> V_131 &&
F_56 ( & V_2 -> V_167 ) <= V_2 -> V_275 / 2 ) {
V_19 = F_87 ( V_2 ) ;
if ( V_19 ) {
V_2 -> V_47 = - V_19 ;
V_2 -> V_49 ( V_2 ) ;
}
}
F_267 ( V_1 , V_142 , & V_146 , V_3 ) ;
V_17:
F_36 ( V_2 ) ;
return V_78 ? : V_340 ;
}
static void F_268 ( struct V_1 * V_2 )
{
F_269 () ;
}
struct V_1 *
F_270 ( struct V_183 * V_183 , int V_346 , struct V_14 * V_14 ,
struct V_347 * V_348 )
{
struct V_101 * V_1 ;
struct V_1 * V_2 ;
struct V_42 * V_43 ;
struct V_190 * V_190 = NULL ;
struct V_200 * V_201 = V_348 ? V_348 -> V_201 : NULL ;
unsigned int V_173 ;
F_175 ( ! V_188 ) ;
if ( V_346 < 0 || V_346 >= V_213 )
return NULL ;
if ( F_271 ( V_204 , V_211 , V_346 , & V_1 ) )
return NULL ;
if ( F_155 ( & V_349 , V_1 , V_201 , V_346 ) < 0 )
goto V_350;
V_2 = V_1 -> V_2 ;
F_272 ( V_2 , V_183 ) ;
if ( ! V_348 || V_348 -> V_173 < 32 )
V_173 = 32 ;
else
V_173 = V_348 -> V_173 ;
V_190 = F_273 ( sizeof( * V_190 ) + F_193 ( V_173 ) , V_62 ) ;
if ( ! V_190 )
goto V_351;
V_2 -> V_278 = F_268 ;
if ( V_348 && V_348 -> V_352 )
F_2 ( V_2 ) -> V_281 = V_348 -> V_352 ;
if ( F_148 ( V_2 , 0 ) )
goto V_351;
V_43 = F_2 ( V_2 ) ;
V_43 -> V_3 |= V_4 ;
F_119 () ;
if ( ! V_188 [ V_346 ] . V_215 ) {
V_188 [ V_346 ] . V_173 = V_173 ;
F_274 ( V_188 [ V_346 ] . V_190 , V_190 ) ;
V_188 [ V_346 ] . V_201 = V_201 ;
V_188 [ V_346 ] . V_14 = V_14 ;
if ( V_348 ) {
V_188 [ V_346 ] . F_161 = V_348 -> F_161 ;
V_188 [ V_346 ] . F_162 = V_348 -> F_162 ;
V_188 [ V_346 ] . V_3 = V_348 -> V_3 ;
if ( V_348 -> V_353 )
V_188 [ V_346 ] . V_353 = V_348 -> V_353 ;
}
V_188 [ V_346 ] . V_215 = 1 ;
} else {
F_49 ( V_190 ) ;
V_188 [ V_346 ] . V_215 ++ ;
}
F_128 () ;
return V_2 ;
V_351:
F_49 ( V_190 ) ;
F_275 ( V_2 ) ;
return NULL ;
V_350:
F_276 ( V_1 ) ;
return NULL ;
}
void
F_275 ( struct V_1 * V_2 )
{
F_277 ( V_2 ) ;
}
int F_278 ( struct V_1 * V_2 , unsigned int V_173 )
{
struct V_190 * V_309 , * V_225 ;
struct V_184 * V_189 = & V_188 [ V_2 -> V_22 ] ;
if ( V_173 < 32 )
V_173 = 32 ;
if ( F_193 ( V_189 -> V_173 ) < F_193 ( V_173 ) ) {
V_309 = F_273 ( sizeof( * V_309 ) + F_193 ( V_173 ) , V_34 ) ;
if ( ! V_309 )
return - V_33 ;
V_225 = F_145 ( V_189 -> V_190 ) ;
memcpy ( V_309 -> V_192 , V_225 -> V_192 , F_193 ( V_189 -> V_173 ) ) ;
F_274 ( V_189 -> V_190 , V_309 ) ;
F_177 ( V_225 , V_220 ) ;
}
V_189 -> V_173 = V_173 ;
return 0 ;
}
int F_279 ( struct V_1 * V_2 , unsigned int V_173 )
{
int V_78 ;
F_119 () ;
V_78 = F_278 ( V_2 , V_173 ) ;
F_128 () ;
return V_78 ;
}
void F_280 ( struct V_1 * V_354 , unsigned int V_5 )
{
struct V_1 * V_2 ;
struct V_184 * V_189 = & V_188 [ V_354 -> V_22 ] ;
F_147 (sk, &tbl->mc_list)
F_242 ( F_2 ( V_2 ) , V_5 , 0 ) ;
}
struct V_355 *
F_281 ( struct V_20 * V_21 , T_1 V_151 , T_1 V_356 , int type , int V_58 , int V_3 )
{
struct V_355 * V_357 ;
int V_104 = F_282 ( V_58 ) ;
V_357 = (struct V_355 * ) F_256 ( V_21 , F_283 ( V_104 ) ) ;
V_357 -> V_358 = type ;
V_357 -> V_359 = V_104 ;
V_357 -> V_360 = V_3 ;
V_357 -> V_361 = V_151 ;
V_357 -> V_362 = V_356 ;
if ( ! F_284 ( V_104 ) || F_283 ( V_104 ) - V_104 != 0 )
memset ( F_285 ( V_357 ) + V_58 , 0 , F_283 ( V_104 ) - V_104 ) ;
return V_357 ;
}
static int F_87 ( struct V_1 * V_2 )
{
struct V_42 * V_43 = F_2 ( V_2 ) ;
struct V_363 * V_168 ;
struct V_20 * V_21 = NULL ;
struct V_355 * V_357 ;
int V_58 , V_78 = - V_48 ;
int V_364 ;
F_60 ( V_43 -> V_201 ) ;
if ( ! V_43 -> V_131 ) {
V_78 = - V_10 ;
goto V_365;
}
V_168 = & V_43 -> V_168 ;
V_364 = F_286 ( int , V_168 -> V_366 , V_271 ) ;
if ( ! F_43 ( V_2 ) &&
F_56 ( & V_2 -> V_167 ) >= V_2 -> V_275 )
goto V_365;
if ( V_364 < V_43 -> V_344 ) {
V_21 = F_229 ( V_2 ,
V_43 -> V_344 ,
V_43 -> V_151 ,
V_62 |
V_65 |
V_66 ) ;
if ( V_21 )
F_287 ( V_21 , F_288 ( V_21 ) -
V_43 -> V_344 ) ;
}
if ( ! V_21 )
V_21 = F_229 ( V_2 , V_364 , V_43 -> V_151 ,
V_62 ) ;
if ( ! V_21 )
goto V_365;
F_112 ( V_21 , V_2 ) ;
V_58 = V_168 -> V_367 ( V_21 , V_168 ) ;
if ( V_58 > 0 ) {
F_66 ( V_43 -> V_201 ) ;
if ( F_228 ( V_2 , V_21 ) )
F_98 ( V_21 ) ;
else
F_215 ( V_2 , V_21 ) ;
return 0 ;
}
V_357 = F_289 ( V_21 , V_168 , V_368 , sizeof( V_58 ) , V_369 ) ;
if ( ! V_357 )
goto V_365;
F_290 ( V_168 , V_357 ) ;
memcpy ( F_285 ( V_357 ) , & V_58 , sizeof( V_58 ) ) ;
if ( F_228 ( V_2 , V_21 ) )
F_98 ( V_21 ) ;
else
F_215 ( V_2 , V_21 ) ;
if ( V_168 -> V_169 )
V_168 -> V_169 ( V_168 ) ;
V_43 -> V_131 = false ;
F_66 ( V_43 -> V_201 ) ;
F_14 ( V_168 -> V_14 ) ;
F_221 ( V_168 -> V_21 ) ;
return 0 ;
V_365:
F_66 ( V_43 -> V_201 ) ;
F_98 ( V_21 ) ;
return V_78 ;
}
int F_291 ( struct V_1 * V_263 , struct V_20 * V_21 ,
const struct V_355 * V_357 ,
struct V_370 * V_371 )
{
struct V_363 * V_168 ;
struct V_1 * V_2 ;
struct V_42 * V_43 ;
int V_19 ;
if ( F_41 ( V_21 ) ) {
V_21 = F_292 ( V_21 , V_62 ) ;
if ( V_21 == NULL )
return - V_48 ;
} else
F_35 ( & V_21 -> V_153 ) ;
V_2 = F_142 ( F_137 ( V_263 ) , V_263 -> V_22 , F_42 ( V_21 ) . V_151 ) ;
if ( V_2 == NULL ) {
V_19 = - V_264 ;
goto V_372;
}
V_43 = F_2 ( V_2 ) ;
F_60 ( V_43 -> V_201 ) ;
if ( V_43 -> V_131 ) {
V_19 = - V_81 ;
goto V_373;
}
if ( ! F_165 ( V_371 -> V_14 ) ) {
V_19 = - V_214 ;
goto V_373;
}
V_168 = & V_43 -> V_168 ;
memset ( V_168 , 0 , sizeof( * V_168 ) ) ;
V_168 -> V_367 = V_371 -> V_367 ;
V_168 -> V_169 = V_371 -> V_169 ;
V_168 -> V_357 = V_357 ;
V_168 -> V_136 = V_371 -> V_136 ;
V_168 -> V_14 = V_371 -> V_14 ;
V_168 -> V_366 = V_371 -> V_366 ;
V_168 -> V_21 = V_21 ;
V_43 -> V_131 = true ;
F_66 ( V_43 -> V_201 ) ;
V_19 = F_87 ( V_2 ) ;
F_108 ( V_2 ) ;
if ( V_19 )
return V_19 ;
return - V_374 ;
V_373:
F_108 ( V_2 ) ;
F_66 ( V_43 -> V_201 ) ;
V_372:
F_98 ( V_21 ) ;
return V_19 ;
}
void F_293 ( struct V_20 * V_375 , struct V_355 * V_357 , int V_78 )
{
struct V_20 * V_21 ;
struct V_355 * V_376 ;
struct V_377 * V_378 ;
T_7 V_379 = sizeof( * V_378 ) ;
if ( V_78 )
V_379 += V_359 ( V_357 ) ;
V_21 = F_229 ( V_375 -> V_2 , F_294 ( V_379 ) ,
F_42 ( V_375 ) . V_151 , V_62 ) ;
if ( ! V_21 ) {
struct V_1 * V_2 ;
V_2 = F_142 ( F_137 ( V_375 -> V_2 ) ,
V_375 -> V_2 -> V_22 ,
F_42 ( V_375 ) . V_151 ) ;
if ( V_2 ) {
V_2 -> V_47 = V_48 ;
V_2 -> V_49 ( V_2 ) ;
F_108 ( V_2 ) ;
}
return;
}
V_376 = F_281 ( V_21 , F_42 ( V_375 ) . V_151 , V_357 -> V_362 ,
V_380 , V_379 , 0 ) ;
V_378 = F_285 ( V_376 ) ;
V_378 -> error = V_78 ;
memcpy ( & V_378 -> V_142 , V_357 , V_78 ? V_357 -> V_359 : sizeof( * V_357 ) ) ;
F_100 ( V_375 -> V_2 , V_21 , F_42 ( V_375 ) . V_151 , V_150 ) ;
}
int F_295 ( struct V_20 * V_21 , int (* V_168)( struct V_20 * ,
struct V_355 * ) )
{
struct V_355 * V_357 ;
int V_78 ;
while ( V_21 -> V_58 >= F_294 ( 0 ) ) {
int V_381 ;
V_357 = F_296 ( V_21 ) ;
V_78 = 0 ;
if ( V_357 -> V_359 < V_382 || V_21 -> V_58 < V_357 -> V_359 )
return 0 ;
if ( ! ( V_357 -> V_360 & V_383 ) )
goto V_384;
if ( V_357 -> V_358 < V_385 )
goto V_384;
V_78 = V_168 ( V_21 , V_357 ) ;
if ( V_78 == - V_374 )
goto V_386;
V_384:
if ( V_357 -> V_360 & V_387 || V_78 )
F_293 ( V_21 , V_357 , V_78 ) ;
V_386:
V_381 = F_283 ( V_357 -> V_359 ) ;
if ( V_381 > V_21 -> V_58 )
V_381 = V_21 -> V_58 ;
F_297 ( V_21 , V_381 ) ;
}
return 0 ;
}
int F_298 ( struct V_1 * V_2 , struct V_20 * V_21 , T_1 V_151 ,
unsigned int V_5 , int V_388 , T_2 V_3 )
{
int V_78 = 0 ;
if ( V_5 ) {
int V_389 = 0 ;
if ( V_388 ) {
F_35 ( & V_21 -> V_153 ) ;
V_389 = V_151 ;
}
V_78 = F_299 ( V_2 , V_21 , V_389 , V_5 , V_3 ) ;
}
if ( V_388 ) {
int V_286 ;
V_286 = F_300 ( V_2 , V_21 , V_151 ) ;
if ( ! V_78 || V_78 == - V_305 )
V_78 = V_286 ;
}
return V_78 ;
}
static int F_301 ( struct V_390 * V_391 )
{
int V_78 ;
V_78 = F_302 ( & V_188 [ V_391 -> V_392 ] . V_186 , & V_391 -> V_393 ) ;
if ( V_78 ) {
V_391 -> V_392 = V_213 ;
return V_78 ;
}
V_78 = F_303 ( & V_391 -> V_393 ) ;
return V_78 == - V_276 ? 0 : V_78 ;
}
static void F_304 ( struct V_390 * V_391 )
{
F_305 ( & V_391 -> V_393 ) ;
F_306 ( & V_391 -> V_393 ) ;
}
static void * F_307 ( struct V_394 * V_356 )
{
struct V_390 * V_391 = V_356 -> V_395 ;
struct V_42 * V_43 ;
do {
for (; ; ) {
int V_78 ;
V_43 = F_308 ( & V_391 -> V_393 ) ;
if ( F_226 ( V_43 ) ) {
if ( F_227 ( V_43 ) == - V_276 )
continue;
return V_43 ;
}
if ( V_43 )
break;
F_304 ( V_391 ) ;
if ( ++ V_391 -> V_392 >= V_213 )
return NULL ;
V_78 = F_301 ( V_391 ) ;
if ( V_78 )
return F_201 ( V_78 ) ;
}
} while ( F_137 ( & V_43 -> V_2 ) != F_309 ( V_356 ) );
return V_43 ;
}
static void * F_310 ( struct V_394 * V_356 , T_8 * V_396 )
{
struct V_390 * V_391 = V_356 -> V_395 ;
void * V_397 = V_398 ;
T_8 V_123 ;
int V_78 ;
V_391 -> V_392 = 0 ;
V_78 = F_301 ( V_391 ) ;
if ( V_78 )
return F_201 ( V_78 ) ;
for ( V_123 = * V_396 ; V_123 && V_397 && ! F_226 ( V_397 ) ; V_123 -- )
V_397 = F_307 ( V_356 ) ;
return V_397 ;
}
static void * F_311 ( struct V_394 * V_356 , void * V_399 , T_8 * V_123 )
{
++ * V_123 ;
return F_307 ( V_356 ) ;
}
static void F_312 ( struct V_394 * V_356 , void * V_399 )
{
struct V_390 * V_391 = V_356 -> V_395 ;
if ( V_391 -> V_392 >= V_213 )
return;
F_304 ( V_391 ) ;
}
static int F_313 ( struct V_394 * V_356 , void * V_399 )
{
if ( V_399 == V_398 ) {
F_314 ( V_356 ,
L_4
L_5 ) ;
} else {
struct V_1 * V_400 = V_399 ;
struct V_42 * V_43 = F_2 ( V_400 ) ;
F_315 ( V_356 , L_6 ,
V_400 ,
V_400 -> V_22 ,
V_43 -> V_151 ,
V_43 -> V_173 ? ( T_1 ) V_43 -> V_173 [ 0 ] : 0 ,
F_316 ( V_400 ) ,
F_317 ( V_400 ) ,
V_43 -> V_131 ,
F_56 ( & V_400 -> V_197 ) ,
F_56 ( & V_400 -> V_50 ) ,
F_318 ( V_400 )
) ;
}
return 0 ;
}
static int F_319 ( struct V_266 * V_266 , struct V_99 * V_99 )
{
return F_320 ( V_266 , V_99 , & V_401 ,
sizeof( struct V_390 ) ) ;
}
int F_321 ( struct V_402 * V_403 )
{
return F_322 ( & V_223 , V_403 ) ;
}
int F_323 ( struct V_402 * V_403 )
{
return F_324 ( & V_223 , V_403 ) ;
}
static int T_9 F_325 ( struct V_183 * V_183 )
{
#ifdef F_326
if ( ! F_327 ( L_7 , 0 , V_183 -> V_404 , & V_405 ) )
return - V_33 ;
#endif
return 0 ;
}
static void T_10 F_328 ( struct V_183 * V_183 )
{
#ifdef F_326
F_329 ( L_7 , V_183 -> V_404 ) ;
#endif
}
static void T_11 F_330 ( void )
{
struct V_190 * V_190 ;
int V_173 = 32 ;
V_190 = F_273 ( sizeof( * V_190 ) + F_193 ( V_173 ) , V_62 ) ;
if ( ! V_190 )
F_331 ( L_8 ) ;
F_119 () ;
V_188 [ V_24 ] . V_173 = V_173 ;
F_274 ( V_188 [ V_24 ] . V_190 , V_190 ) ;
V_188 [ V_24 ] . V_14 = V_406 ;
V_188 [ V_24 ] . V_215 = 1 ;
V_188 [ V_24 ] . V_3 = V_259 ;
F_128 () ;
}
static int T_11 F_332 ( void )
{
int V_59 ;
int V_78 = F_333 ( & V_205 , 0 ) ;
struct V_407 V_408 = {
. V_409 = F_334 ( struct V_42 , V_187 ) ,
. V_410 = F_334 ( struct V_42 , V_151 ) ,
. V_411 = sizeof( T_1 ) ,
. V_412 = V_413 ,
. V_414 = 16 ,
} ;
if ( V_78 != 0 )
goto V_17;
F_335 ( sizeof( struct V_228 ) > F_336 ( struct V_20 , V_168 ) ) ;
V_188 = F_54 ( V_213 , sizeof( * V_188 ) , V_62 ) ;
if ( ! V_188 )
goto F_331;
for ( V_59 = 0 ; V_59 < V_213 ; V_59 ++ ) {
if ( F_337 ( & V_188 [ V_59 ] . V_186 , & V_408 ) < 0 ) {
while ( -- V_59 > 0 )
F_338 ( & V_188 [ V_59 ] . V_186 ) ;
F_49 ( V_188 ) ;
goto F_331;
}
}
F_339 ( & V_13 ) ;
F_330 () ;
F_340 ( & V_415 ) ;
F_341 ( & V_416 ) ;
F_342 () ;
V_17:
return V_78 ;
F_331:
F_331 ( L_9 ) ;
}
