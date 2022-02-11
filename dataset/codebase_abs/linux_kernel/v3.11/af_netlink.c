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
static int F_19 ( struct V_27 * V_28 ,
struct V_29 * V_15 )
{
struct V_27 * V_30 ;
int V_26 = - V_31 ;
F_20 ( V_15 ) ;
V_30 = F_21 ( V_28 , V_32 ) ;
if ( V_30 ) {
V_30 -> V_15 = V_15 ;
V_26 = F_22 ( V_30 ) ;
if ( F_7 ( V_26 > 0 ) )
V_26 = F_23 ( V_26 ) ;
}
F_24 ( V_15 ) ;
return V_26 ;
}
static void F_25 ( struct V_27 * V_28 )
{
int V_26 ;
struct V_13 * V_23 ;
F_26 (tmp, &netlink_tap_all, list) {
V_26 = F_19 ( V_28 , V_23 -> V_15 ) ;
if ( F_7 ( V_26 ) )
break;
}
}
static void F_27 ( struct V_27 * V_28 )
{
F_28 () ;
if ( F_7 ( ! F_29 ( & V_20 ) ) )
F_25 ( V_28 ) ;
F_30 () ;
}
static void F_31 ( struct V_1 * V_2 )
{
struct V_33 * V_34 = F_2 ( V_2 ) ;
if ( ! ( V_34 -> V_3 & V_35 ) ) {
if ( ! F_32 ( V_36 , & F_2 ( V_2 ) -> V_37 ) ) {
V_2 -> V_38 = V_39 ;
V_2 -> V_40 ( V_2 ) ;
}
}
F_33 ( & V_2 -> V_41 ) ;
}
static void F_34 ( struct V_1 * V_2 )
{
struct V_33 * V_34 = F_2 ( V_2 ) ;
if ( F_35 ( & V_2 -> V_42 ) )
F_36 ( V_36 , & V_34 -> V_37 ) ;
if ( ! F_37 ( V_36 , & V_34 -> V_37 ) )
F_38 ( & V_34 -> V_43 ) ;
}
static bool F_39 ( const struct V_27 * V_28 )
{
return F_40 ( V_28 ) . V_3 & V_44 ;
}
static bool F_41 ( struct V_1 * V_2 )
{
return F_2 ( V_2 ) -> V_45 . V_46 != NULL ;
}
static bool F_42 ( struct V_1 * V_2 )
{
return F_2 ( V_2 ) -> V_47 . V_46 != NULL ;
}
static void F_43 ( void * * V_46 , unsigned int V_48 , unsigned int V_49 )
{
unsigned int V_50 ;
for ( V_50 = 0 ; V_50 < V_49 ; V_50 ++ ) {
if ( V_46 [ V_50 ] != NULL ) {
if ( F_44 ( V_46 [ V_50 ] ) )
F_45 ( V_46 [ V_50 ] ) ;
else
F_46 ( ( unsigned long ) V_46 [ V_50 ] , V_48 ) ;
}
}
F_47 ( V_46 ) ;
}
static void * F_48 ( unsigned long V_48 )
{
void * V_51 ;
T_2 V_52 = V_53 | V_54 | V_55 |
V_56 | V_57 ;
V_51 = ( void * ) F_49 ( V_52 , V_48 ) ;
if ( V_51 != NULL )
return V_51 ;
V_51 = F_50 ( ( 1 << V_48 ) * V_58 ) ;
if ( V_51 != NULL )
return V_51 ;
V_52 &= ~ V_57 ;
return ( void * ) F_49 ( V_52 , V_48 ) ;
}
static void * * F_51 ( struct V_33 * V_34 ,
struct V_59 * V_60 , unsigned int V_48 )
{
unsigned int V_61 = V_60 -> V_62 ;
unsigned int V_50 ;
void * * V_46 , * V_63 ;
V_46 = F_52 ( V_61 , sizeof( void * ) , V_53 ) ;
if ( V_46 == NULL )
return NULL ;
for ( V_50 = 0 ; V_50 < V_61 ; V_50 ++ ) {
V_46 [ V_50 ] = V_63 = F_48 ( V_48 ) ;
if ( V_46 [ V_50 ] == NULL )
goto V_64;
}
return V_46 ;
V_64:
F_43 ( V_46 , V_48 , V_61 ) ;
return NULL ;
}
static int F_53 ( struct V_1 * V_2 , struct V_59 * V_60 ,
bool V_65 , bool V_47 )
{
struct V_33 * V_34 = F_2 ( V_2 ) ;
struct V_66 * V_67 ;
struct V_68 * V_69 ;
void * * V_46 = NULL ;
unsigned int V_48 = 0 ;
int V_70 ;
V_67 = V_47 ? & V_34 -> V_47 : & V_34 -> V_45 ;
V_69 = V_47 ? & V_2 -> V_71 : & V_2 -> V_42 ;
if ( ! V_65 ) {
if ( F_54 ( & V_34 -> V_72 ) )
return - V_73 ;
if ( F_54 ( & V_67 -> V_74 ) )
return - V_73 ;
}
if ( V_60 -> V_62 ) {
if ( V_67 -> V_46 != NULL )
return - V_73 ;
if ( ( int ) V_60 -> V_75 <= 0 )
return - V_17 ;
if ( ! F_55 ( V_60 -> V_75 , V_58 ) )
return - V_17 ;
if ( V_60 -> V_76 < V_77 )
return - V_17 ;
if ( ! F_55 ( V_60 -> V_76 , V_78 ) )
return - V_17 ;
V_67 -> V_79 = V_60 -> V_75 /
V_60 -> V_76 ;
if ( V_67 -> V_79 == 0 )
return - V_17 ;
if ( V_67 -> V_79 * V_60 -> V_62 !=
V_60 -> V_80 )
return - V_17 ;
V_48 = F_56 ( V_60 -> V_75 ) ;
V_46 = F_51 ( V_34 , V_60 , V_48 ) ;
if ( V_46 == NULL )
return - V_31 ;
} else {
if ( V_60 -> V_80 )
return - V_17 ;
}
V_70 = - V_73 ;
F_57 ( & V_34 -> V_81 ) ;
if ( V_65 || F_54 ( & V_34 -> V_72 ) == 0 ) {
V_70 = 0 ;
F_58 ( & V_69 -> V_82 ) ;
V_67 -> V_83 = V_60 -> V_80 - 1 ;
V_67 -> V_84 = 0 ;
V_67 -> V_85 = V_60 -> V_76 ;
V_67 -> V_86 = V_60 -> V_75 / V_58 ;
F_59 ( V_67 -> V_87 , V_60 -> V_62 ) ;
F_59 ( V_67 -> V_88 , V_48 ) ;
F_59 ( V_67 -> V_46 , V_46 ) ;
F_60 ( V_69 ) ;
F_61 ( & V_69 -> V_82 ) ;
F_62 ( F_54 ( & V_34 -> V_72 ) ) ;
}
F_63 ( & V_34 -> V_81 ) ;
if ( V_46 )
F_43 ( V_46 , V_48 , V_60 -> V_62 ) ;
return V_70 ;
}
static void F_64 ( struct V_89 * V_90 )
{
struct V_91 * V_91 = V_90 -> V_92 ;
struct V_93 * V_1 = V_91 -> V_94 ;
struct V_1 * V_2 = V_1 -> V_2 ;
if ( V_2 )
F_33 ( & F_2 ( V_2 ) -> V_72 ) ;
}
static void F_65 ( struct V_89 * V_90 )
{
struct V_91 * V_91 = V_90 -> V_92 ;
struct V_93 * V_1 = V_91 -> V_94 ;
struct V_1 * V_2 = V_1 -> V_2 ;
if ( V_2 )
F_66 ( & F_2 ( V_2 ) -> V_72 ) ;
}
static int F_67 ( struct V_91 * V_91 , struct V_93 * V_1 ,
struct V_89 * V_90 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_33 * V_34 = F_2 ( V_2 ) ;
struct V_66 * V_67 ;
unsigned long V_95 , V_96 , V_97 ;
unsigned int V_50 ;
int V_70 = - V_17 ;
if ( V_90 -> V_98 )
return - V_17 ;
F_57 ( & V_34 -> V_81 ) ;
V_97 = 0 ;
for ( V_67 = & V_34 -> V_45 ; V_67 <= & V_34 -> V_47 ; V_67 ++ ) {
if ( V_67 -> V_46 == NULL )
continue;
V_97 += V_67 -> V_87 * V_67 -> V_86 * V_58 ;
}
if ( V_97 == 0 )
goto V_24;
V_96 = V_90 -> V_99 - V_90 -> V_100 ;
if ( V_96 != V_97 )
goto V_24;
V_95 = V_90 -> V_100 ;
for ( V_67 = & V_34 -> V_45 ; V_67 <= & V_34 -> V_47 ; V_67 ++ ) {
if ( V_67 -> V_46 == NULL )
continue;
for ( V_50 = 0 ; V_50 < V_67 -> V_87 ; V_50 ++ ) {
struct V_101 * V_101 ;
void * V_102 = V_67 -> V_46 [ V_50 ] ;
unsigned int V_103 ;
for ( V_103 = 0 ; V_103 < V_67 -> V_86 ; V_103 ++ ) {
V_101 = F_68 ( V_102 ) ;
V_70 = F_69 ( V_90 , V_95 , V_101 ) ;
if ( V_70 < 0 )
goto V_24;
V_95 += V_58 ;
V_102 += V_58 ;
}
}
}
F_33 ( & V_34 -> V_72 ) ;
V_90 -> V_104 = & V_105 ;
V_70 = 0 ;
V_24:
F_63 ( & V_34 -> V_81 ) ;
return V_70 ;
}
static void F_70 ( const struct V_106 * V_107 )
{
#if V_108 == 1
struct V_101 * V_109 , * V_110 ;
V_109 = F_68 ( V_107 + V_58 ) ;
V_110 = F_68 ( ( void * ) V_107 + V_77 + V_107 -> V_111 - 1 ) ;
while ( V_109 <= V_110 ) {
F_71 ( V_109 ) ;
V_109 ++ ;
}
#endif
}
static enum V_112 F_72 ( const struct V_106 * V_107 )
{
F_73 () ;
F_71 ( F_68 ( V_107 ) ) ;
return V_107 -> V_113 ;
}
static void F_74 ( struct V_106 * V_107 ,
enum V_112 V_114 )
{
V_107 -> V_113 = V_114 ;
F_71 ( F_68 ( V_107 ) ) ;
F_75 () ;
}
static struct V_106 *
F_76 ( const struct V_66 * V_67 , unsigned int V_115 )
{
unsigned int V_116 , V_117 ;
V_116 = V_115 / V_67 -> V_79 ;
V_117 = V_115 % V_67 -> V_79 ;
return V_67 -> V_46 [ V_116 ] + ( V_117 * V_67 -> V_85 ) ;
}
static struct V_106 *
F_77 ( const struct V_66 * V_67 , unsigned int V_115 ,
enum V_112 V_114 )
{
struct V_106 * V_107 ;
V_107 = F_76 ( V_67 , V_115 ) ;
if ( F_72 ( V_107 ) != V_114 )
return NULL ;
return V_107 ;
}
static struct V_106 *
F_78 ( const struct V_66 * V_67 ,
enum V_112 V_114 )
{
return F_77 ( V_67 , V_67 -> V_84 , V_114 ) ;
}
static struct V_106 *
F_79 ( const struct V_66 * V_67 ,
enum V_112 V_114 )
{
unsigned int V_118 ;
V_118 = V_67 -> V_84 ? V_67 -> V_84 - 1 : V_67 -> V_83 ;
return F_77 ( V_67 , V_118 , V_114 ) ;
}
static void F_80 ( struct V_66 * V_67 )
{
V_67 -> V_84 = V_67 -> V_84 != V_67 -> V_83 ? V_67 -> V_84 + 1 : 0 ;
}
static void F_81 ( struct V_66 * V_67 )
{
unsigned int V_84 = V_67 -> V_84 , V_115 = V_84 ;
const struct V_106 * V_107 ;
do {
V_107 = F_76 ( V_67 , V_115 ) ;
if ( V_107 -> V_113 == V_119 )
break;
if ( V_107 -> V_113 != V_120 )
break;
F_80 ( V_67 ) ;
} while ( V_67 -> V_84 != V_84 );
}
static bool F_82 ( struct V_33 * V_34 )
{
struct V_66 * V_67 = & V_34 -> V_45 ;
struct V_106 * V_107 ;
unsigned int V_121 ;
V_107 = F_78 ( V_67 , V_119 ) ;
if ( V_107 == NULL )
return false ;
V_121 = V_67 -> V_84 + V_67 -> V_83 / 2 ;
if ( V_121 > V_67 -> V_83 )
V_121 -= V_67 -> V_83 ;
V_107 = F_76 ( V_67 , V_121 ) ;
return V_107 -> V_113 == V_119 ;
}
static unsigned int F_83 ( struct V_91 * V_91 , struct V_93 * V_1 ,
T_3 * V_43 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_33 * V_34 = F_2 ( V_2 ) ;
unsigned int V_12 ;
int V_70 ;
if ( V_34 -> V_45 . V_46 != NULL ) {
while ( V_34 -> V_122 != NULL && F_82 ( V_34 ) ) {
V_70 = F_84 ( V_2 ) ;
if ( V_70 < 0 ) {
V_2 -> V_38 = V_70 ;
V_2 -> V_40 ( V_2 ) ;
break;
}
}
F_34 ( V_2 ) ;
}
V_12 = F_85 ( V_91 , V_1 , V_43 ) ;
F_58 ( & V_2 -> V_42 . V_82 ) ;
if ( V_34 -> V_45 . V_46 ) {
F_81 ( & V_34 -> V_45 ) ;
if ( ! F_79 ( & V_34 -> V_45 , V_119 ) )
V_12 |= V_123 | V_124 ;
}
F_61 ( & V_2 -> V_42 . V_82 ) ;
F_58 ( & V_2 -> V_71 . V_82 ) ;
if ( V_34 -> V_47 . V_46 ) {
if ( F_78 ( & V_34 -> V_47 , V_119 ) )
V_12 |= V_125 | V_126 ;
}
F_61 ( & V_2 -> V_71 . V_82 ) ;
return V_12 ;
}
static struct V_106 * F_86 ( struct V_27 * V_28 )
{
return (struct V_106 * ) ( V_28 -> V_84 - V_77 ) ;
}
static void F_87 ( struct V_27 * V_28 , struct V_1 * V_2 ,
struct V_66 * V_67 ,
struct V_106 * V_107 )
{
unsigned int V_96 ;
void * V_127 ;
V_96 = V_67 -> V_85 - V_77 ;
V_127 = ( void * ) V_107 + V_77 ;
V_28 -> V_84 = V_127 ;
V_28 -> V_127 = V_127 ;
F_88 ( V_28 ) ;
V_28 -> V_128 = V_28 -> V_129 + V_96 ;
V_28 -> V_49 = 0 ;
V_28 -> V_130 = V_131 ;
F_40 ( V_28 ) . V_3 |= V_44 ;
F_40 ( V_28 ) . V_2 = V_2 ;
}
static int F_89 ( struct V_1 * V_2 , struct V_132 * V_133 ,
T_1 V_134 , T_1 V_135 ,
struct V_136 * V_137 )
{
struct V_33 * V_34 = F_2 ( V_2 ) ;
struct V_66 * V_67 ;
struct V_106 * V_107 ;
struct V_27 * V_28 ;
unsigned int V_138 ;
bool V_139 = true ;
int V_70 = 0 , V_49 = 0 ;
if ( F_90 ( & V_2 -> V_140 -> V_91 -> V_141 ) > 2 ||
F_54 ( & V_34 -> V_72 ) > 1 )
V_139 = false ;
F_57 ( & V_34 -> V_81 ) ;
V_67 = & V_34 -> V_47 ;
V_138 = V_67 -> V_85 - V_77 ;
do {
V_107 = F_78 ( V_67 , V_142 ) ;
if ( V_107 == NULL ) {
if ( ! ( V_133 -> V_143 & V_144 ) &&
F_54 ( & V_34 -> V_47 . V_74 ) )
F_91 () ;
continue;
}
if ( V_107 -> V_111 > V_138 ) {
V_70 = - V_17 ;
goto V_24;
}
F_70 ( V_107 ) ;
if ( F_92 ( V_134 == 0 && V_135 == 0 && V_139 ) ) {
V_28 = F_93 ( V_53 ) ;
if ( V_28 == NULL ) {
V_70 = - V_39 ;
goto V_24;
}
F_94 ( V_2 ) ;
F_87 ( V_28 , V_2 , V_67 , V_107 ) ;
F_40 ( V_28 ) . V_3 |= V_145 ;
F_95 ( V_28 , V_107 -> V_111 ) ;
F_74 ( V_107 , V_146 ) ;
F_33 ( & V_67 -> V_74 ) ;
} else {
V_28 = F_96 ( V_107 -> V_111 , V_53 ) ;
if ( V_28 == NULL ) {
V_70 = - V_39 ;
goto V_24;
}
F_95 ( V_28 , V_107 -> V_111 ) ;
memcpy ( V_28 -> V_127 , ( void * ) V_107 + V_77 , V_107 -> V_111 ) ;
F_74 ( V_107 , V_119 ) ;
}
F_80 ( V_67 ) ;
F_40 ( V_28 ) . V_9 = V_34 -> V_9 ;
F_40 ( V_28 ) . V_135 = V_135 ;
F_40 ( V_28 ) . V_147 = V_137 -> V_148 -> V_147 ;
V_70 = F_97 ( V_2 , V_28 ) ;
if ( V_70 ) {
F_98 ( V_28 ) ;
goto V_24;
}
if ( F_7 ( V_135 ) ) {
F_33 ( & V_28 -> V_149 ) ;
F_99 ( V_2 , V_28 , V_134 , V_135 ,
V_53 ) ;
}
V_70 = F_100 ( V_2 , V_28 , V_134 ,
V_133 -> V_143 & V_144 ) ;
if ( V_70 < 0 )
goto V_24;
V_49 += V_70 ;
} while ( V_107 != NULL ||
( ! ( V_133 -> V_143 & V_144 ) &&
F_54 ( & V_34 -> V_47 . V_74 ) ) );
if ( V_49 > 0 )
V_70 = V_49 ;
V_24:
F_63 ( & V_34 -> V_81 ) ;
return V_70 ;
}
static void F_101 ( struct V_1 * V_2 , struct V_27 * V_28 )
{
struct V_106 * V_107 ;
V_107 = F_86 ( V_28 ) ;
V_107 -> V_111 = V_28 -> V_49 ;
V_107 -> V_150 = F_40 ( V_28 ) . V_135 ;
V_107 -> V_151 = F_40 ( V_28 ) . V_147 . V_152 ;
V_107 -> V_153 = F_102 ( F_103 ( V_2 ) , F_40 ( V_28 ) . V_147 . V_154 ) ;
V_107 -> V_155 = F_104 ( F_103 ( V_2 ) , F_40 ( V_28 ) . V_147 . V_156 ) ;
F_70 ( V_107 ) ;
F_74 ( V_107 , V_142 ) ;
F_40 ( V_28 ) . V_3 |= V_157 ;
F_98 ( V_28 ) ;
}
static void F_105 ( struct V_1 * V_2 , struct V_27 * V_28 )
{
struct V_33 * V_34 = F_2 ( V_2 ) ;
struct V_66 * V_67 = & V_34 -> V_45 ;
struct V_106 * V_107 ;
F_58 ( & V_2 -> V_42 . V_82 ) ;
V_107 = F_78 ( V_67 , V_119 ) ;
if ( V_107 == NULL ) {
F_61 ( & V_2 -> V_42 . V_82 ) ;
F_98 ( V_28 ) ;
F_31 ( V_2 ) ;
return;
}
F_80 ( V_67 ) ;
F_106 ( & V_2 -> V_42 , V_28 ) ;
F_61 ( & V_2 -> V_42 . V_82 ) ;
V_107 -> V_111 = V_28 -> V_49 ;
V_107 -> V_150 = F_40 ( V_28 ) . V_135 ;
V_107 -> V_151 = F_40 ( V_28 ) . V_147 . V_152 ;
V_107 -> V_153 = F_102 ( F_103 ( V_2 ) , F_40 ( V_28 ) . V_147 . V_154 ) ;
V_107 -> V_155 = F_104 ( F_103 ( V_2 ) , F_40 ( V_28 ) . V_147 . V_156 ) ;
F_74 ( V_107 , V_158 ) ;
}
static void F_107 ( struct V_159 * V_122 )
{
F_98 ( V_122 -> V_28 ) ;
F_47 ( V_122 ) ;
}
static void F_108 ( struct V_159 * V_122 )
{
F_109 ( V_122 -> V_28 ) ;
F_47 ( V_122 ) ;
}
static void V_131 ( struct V_27 * V_28 )
{
#ifdef F_110
struct V_106 * V_107 ;
struct V_66 * V_67 ;
struct V_1 * V_2 ;
if ( F_39 ( V_28 ) ) {
V_107 = F_86 ( V_28 ) ;
V_2 = F_40 ( V_28 ) . V_2 ;
if ( F_40 ( V_28 ) . V_3 & V_145 ) {
F_74 ( V_107 , V_119 ) ;
V_67 = & F_2 ( V_2 ) -> V_47 ;
} else {
if ( ! ( F_40 ( V_28 ) . V_3 & V_157 ) ) {
V_107 -> V_111 = 0 ;
F_74 ( V_107 , V_142 ) ;
}
V_67 = & F_2 ( V_2 ) -> V_45 ;
}
F_62 ( F_54 ( & V_67 -> V_74 ) == 0 ) ;
F_66 ( & V_67 -> V_74 ) ;
F_111 ( V_2 ) ;
V_28 -> V_84 = NULL ;
}
#endif
if ( F_44 ( V_28 -> V_84 ) ) {
if ( ! V_28 -> V_160 ||
! F_112 ( & ( F_113 ( V_28 ) -> V_161 ) ) )
F_45 ( V_28 -> V_84 ) ;
V_28 -> V_84 = NULL ;
}
if ( V_28 -> V_2 != NULL )
F_114 ( V_28 ) ;
}
static void F_115 ( struct V_27 * V_28 , struct V_1 * V_2 )
{
F_62 ( V_28 -> V_2 != NULL ) ;
V_28 -> V_2 = V_2 ;
V_28 -> V_130 = V_131 ;
F_116 ( V_28 -> V_162 , & V_2 -> V_163 ) ;
F_117 ( V_2 , V_28 -> V_162 ) ;
}
static void F_118 ( struct V_1 * V_2 )
{
struct V_33 * V_34 = F_2 ( V_2 ) ;
if ( V_34 -> V_122 ) {
if ( V_34 -> V_122 -> V_164 )
V_34 -> V_122 -> V_164 ( V_34 -> V_122 ) ;
F_16 ( V_34 -> V_122 -> V_21 ) ;
F_107 ( V_34 -> V_122 ) ;
}
F_119 ( & V_2 -> V_42 ) ;
#ifdef F_110
if ( 1 ) {
struct V_59 V_60 ;
memset ( & V_60 , 0 , sizeof( V_60 ) ) ;
if ( V_34 -> V_45 . V_46 )
F_53 ( V_2 , & V_60 , true , false ) ;
memset ( & V_60 , 0 , sizeof( V_60 ) ) ;
if ( V_34 -> V_47 . V_46 )
F_53 ( V_2 , & V_60 , true , true ) ;
}
#endif
if ( ! F_120 ( V_2 , V_165 ) ) {
F_121 ( V_166 L_2 , V_2 ) ;
return;
}
F_62 ( F_54 ( & V_2 -> V_163 ) ) ;
F_62 ( F_54 ( & V_2 -> V_167 ) ) ;
F_62 ( F_2 ( V_2 ) -> V_168 ) ;
}
void F_122 ( void )
__acquires( T_4 )
{
F_123 () ;
F_124 ( & T_4 ) ;
if ( F_54 ( & V_169 ) ) {
F_125 ( V_43 , V_170 ) ;
F_126 ( & V_171 , & V_43 ) ;
for (; ; ) {
F_127 ( V_172 ) ;
if ( F_54 ( & V_169 ) == 0 )
break;
F_128 ( & T_4 ) ;
F_91 () ;
F_124 ( & T_4 ) ;
}
F_129 ( V_173 ) ;
F_130 ( & V_171 , & V_43 ) ;
}
}
void F_131 ( void )
__releases( T_4 )
{
F_128 ( & T_4 ) ;
F_132 ( & V_171 ) ;
}
static inline void
F_133 ( void )
{
F_134 ( & T_4 ) ;
F_33 ( & V_169 ) ;
F_135 ( & T_4 ) ;
}
static inline void
F_136 ( void )
{
if ( F_137 ( & V_169 ) )
F_132 ( & V_171 ) ;
}
static bool F_138 ( struct V_174 * V_174 , struct V_1 * V_2 )
{
return F_139 ( F_140 ( V_2 ) , V_174 ) ;
}
static struct V_1 * F_141 ( struct V_174 * V_174 , int V_175 , T_1 V_9 )
{
struct V_176 * V_10 = & V_177 [ V_175 ] ;
struct V_7 * V_8 = & V_10 -> V_8 ;
struct V_6 * V_84 ;
struct V_1 * V_2 ;
F_134 ( & T_4 ) ;
V_84 = F_4 ( V_8 , V_9 ) ;
F_142 (sk, head) {
if ( V_10 -> V_178 ( V_174 , V_2 ) &&
( F_2 ( V_2 ) -> V_9 == V_9 ) ) {
F_94 ( V_2 ) ;
goto V_22;
}
}
V_2 = NULL ;
V_22:
F_135 ( & T_4 ) ;
return V_2 ;
}
static struct V_6 * F_143 ( T_5 V_96 )
{
if ( V_96 <= V_58 )
return F_144 ( V_96 , V_32 ) ;
else
return (struct V_6 * )
F_49 ( V_32 | V_55 ,
F_56 ( V_96 ) ) ;
}
static void F_145 ( struct V_6 * V_10 , T_5 V_96 )
{
if ( V_96 <= V_58 )
F_47 ( V_10 ) ;
else
F_46 ( ( unsigned long ) V_10 , F_56 ( V_96 ) ) ;
}
static int F_146 ( struct V_7 * V_8 , int V_179 )
{
unsigned int V_180 , V_12 , V_181 ;
T_5 V_182 , V_96 ;
struct V_6 * V_183 , * V_10 ;
int V_50 ;
V_180 = V_12 = V_8 -> V_12 ;
V_182 = V_96 = ( V_12 + 1 ) * sizeof( * V_10 ) ;
V_181 = V_8 -> V_181 ;
if ( V_179 ) {
if ( ++ V_181 > V_8 -> V_184 )
return 0 ;
V_12 = V_12 * 2 + 1 ;
V_96 *= 2 ;
}
V_10 = F_143 ( V_96 ) ;
if ( ! V_10 )
return 0 ;
V_183 = V_8 -> V_10 ;
V_8 -> V_10 = V_10 ;
V_8 -> V_12 = V_12 ;
V_8 -> V_181 = V_181 ;
F_147 ( & V_8 -> V_11 , sizeof( V_8 -> V_11 ) ) ;
for ( V_50 = 0 ; V_50 <= V_180 ; V_50 ++ ) {
struct V_1 * V_2 ;
struct V_185 * V_23 ;
F_148 (sk, tmp, &otable[i])
F_149 ( V_2 , F_4 ( V_8 , F_2 ( V_2 ) -> V_9 ) ) ;
}
F_145 ( V_183 , V_182 ) ;
V_8 -> V_186 = V_187 + 10 * 60 * V_188 ;
return 1 ;
}
static inline int F_150 ( struct V_7 * V_8 , int V_49 )
{
int V_189 = V_8 -> V_190 >> V_8 -> V_181 ;
if ( F_7 ( V_189 > 1 ) && F_146 ( V_8 , 1 ) )
return 1 ;
if ( F_7 ( V_49 > V_189 ) && F_151 ( V_187 , V_8 -> V_186 ) ) {
F_146 ( V_8 , 0 ) ;
return 1 ;
}
return 0 ;
}
static void
F_152 ( struct V_1 * V_2 )
{
struct V_176 * V_191 = & V_177 [ V_2 -> V_192 ] ;
unsigned long V_12 ;
unsigned int V_50 ;
struct V_193 * V_193 ;
V_193 = F_153 ( V_191 -> V_193 ) ;
if ( ! V_193 )
return;
for ( V_50 = 0 ; V_50 < F_154 ( V_191 -> V_168 ) ; V_50 ++ ) {
V_12 = 0 ;
F_155 (sk, &tbl->mc_list) {
if ( V_50 < F_154 ( F_2 ( V_2 ) -> V_194 ) )
V_12 |= F_2 ( V_2 ) -> V_168 [ V_50 ] ;
}
V_193 -> V_195 [ V_50 ] = V_12 ;
}
}
static int F_156 ( struct V_1 * V_2 , struct V_174 * V_174 , T_1 V_9 )
{
struct V_176 * V_10 = & V_177 [ V_2 -> V_192 ] ;
struct V_7 * V_8 = & V_10 -> V_8 ;
struct V_6 * V_84 ;
int V_70 = - V_196 ;
struct V_1 * V_197 ;
int V_49 ;
F_122 () ;
V_84 = F_4 ( V_8 , V_9 ) ;
V_49 = 0 ;
F_142 (osk, head) {
if ( V_10 -> V_178 ( V_174 , V_197 ) &&
( F_2 ( V_197 ) -> V_9 == V_9 ) )
break;
V_49 ++ ;
}
if ( V_197 )
goto V_70;
V_70 = - V_73 ;
if ( F_2 ( V_2 ) -> V_9 )
goto V_70;
V_70 = - V_31 ;
if ( V_198 > 32 && F_7 ( V_8 -> V_190 >= V_199 ) )
goto V_70;
if ( V_49 && F_150 ( V_8 , V_49 ) )
V_84 = F_4 ( V_8 , V_9 ) ;
V_8 -> V_190 ++ ;
F_2 ( V_2 ) -> V_9 = V_9 ;
F_157 ( V_2 , V_84 ) ;
V_70 = 0 ;
V_70:
F_131 () ;
return V_70 ;
}
static void F_158 ( struct V_1 * V_2 )
{
F_122 () ;
if ( F_159 ( V_2 ) )
V_177 [ V_2 -> V_192 ] . V_8 . V_190 -- ;
if ( F_2 ( V_2 ) -> V_200 )
F_160 ( V_2 ) ;
F_131 () ;
}
static int F_161 ( struct V_174 * V_174 , struct V_93 * V_1 ,
struct V_201 * V_202 , int V_175 )
{
struct V_1 * V_2 ;
struct V_33 * V_34 ;
V_1 -> V_203 = & V_204 ;
V_2 = F_162 ( V_174 , V_205 , V_53 , & V_206 ) ;
if ( ! V_2 )
return - V_31 ;
F_163 ( V_1 , V_2 ) ;
V_34 = F_2 ( V_2 ) ;
if ( V_202 ) {
V_34 -> V_202 = V_202 ;
} else {
V_34 -> V_202 = & V_34 -> V_207 ;
F_164 ( V_34 -> V_202 ) ;
}
F_165 ( & V_34 -> V_43 ) ;
#ifdef F_110
F_164 ( & V_34 -> V_81 ) ;
#endif
V_2 -> V_208 = F_118 ;
V_2 -> V_192 = V_175 ;
return 0 ;
}
static int F_166 ( struct V_174 * V_174 , struct V_93 * V_1 , int V_175 ,
int V_209 )
{
struct V_21 * V_21 = NULL ;
struct V_201 * V_202 ;
struct V_33 * V_34 ;
void (* F_167)( int V_5 );
int V_70 = 0 ;
V_1 -> V_37 = V_210 ;
if ( V_1 -> type != V_211 && V_1 -> type != V_212 )
return - V_213 ;
if ( V_175 < 0 || V_175 >= V_214 )
return - V_215 ;
F_133 () ;
#ifdef F_168
if ( ! V_177 [ V_175 ] . V_216 ) {
F_136 () ;
F_169 ( L_3 , V_205 , V_175 ) ;
F_133 () ;
}
#endif
if ( V_177 [ V_175 ] . V_216 &&
F_170 ( V_177 [ V_175 ] . V_21 ) )
V_21 = V_177 [ V_175 ] . V_21 ;
else
V_70 = - V_215 ;
V_202 = V_177 [ V_175 ] . V_202 ;
F_167 = V_177 [ V_175 ] . F_167 ;
F_136 () ;
if ( V_70 < 0 )
goto V_24;
V_70 = F_161 ( V_174 , V_1 , V_202 , V_175 ) ;
if ( V_70 < 0 )
goto V_217;
F_171 () ;
F_172 ( V_174 , & V_206 , 1 ) ;
F_173 () ;
V_34 = F_2 ( V_1 -> V_2 ) ;
V_34 -> V_21 = V_21 ;
V_34 -> V_218 = F_167 ;
V_24:
return V_70 ;
V_217:
F_16 ( V_21 ) ;
goto V_24;
}
static int F_174 ( struct V_93 * V_1 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_33 * V_34 ;
if ( ! V_2 )
return 0 ;
F_158 ( V_2 ) ;
F_175 ( V_2 ) ;
V_34 = F_2 ( V_2 ) ;
V_1 -> V_2 = NULL ;
F_176 ( & V_34 -> V_43 ) ;
F_119 ( & V_2 -> V_71 ) ;
if ( V_34 -> V_9 ) {
struct V_219 V_121 = {
. V_174 = F_140 ( V_2 ) ,
. V_175 = V_2 -> V_192 ,
. V_9 = V_34 -> V_9 ,
} ;
F_177 ( & V_220 ,
V_221 , & V_121 ) ;
}
F_16 ( V_34 -> V_21 ) ;
F_122 () ;
if ( F_1 ( V_2 ) ) {
F_178 ( V_177 [ V_2 -> V_192 ] . V_216 == 0 ) ;
if ( -- V_177 [ V_2 -> V_192 ] . V_216 == 0 ) {
struct V_193 * V_222 ;
V_222 = F_153 ( V_177 [ V_2 -> V_192 ] . V_193 ) ;
F_179 ( V_177 [ V_2 -> V_192 ] . V_193 , NULL ) ;
F_180 ( V_222 , V_223 ) ;
V_177 [ V_2 -> V_192 ] . V_21 = NULL ;
V_177 [ V_2 -> V_192 ] . F_167 = NULL ;
V_177 [ V_2 -> V_192 ] . V_3 = 0 ;
V_177 [ V_2 -> V_192 ] . V_216 = 0 ;
}
} else if ( V_34 -> V_200 ) {
F_152 ( V_2 ) ;
}
F_131 () ;
F_47 ( V_34 -> V_168 ) ;
V_34 -> V_168 = NULL ;
F_171 () ;
F_172 ( F_140 ( V_2 ) , & V_206 , - 1 ) ;
F_173 () ;
F_111 ( V_2 ) ;
return 0 ;
}
static int F_181 ( struct V_93 * V_1 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_174 * V_174 = F_140 ( V_2 ) ;
struct V_176 * V_10 = & V_177 [ V_2 -> V_192 ] ;
struct V_7 * V_8 = & V_10 -> V_8 ;
struct V_6 * V_84 ;
struct V_1 * V_197 ;
T_6 V_9 = F_182 ( V_170 ) ;
int V_70 ;
static T_6 V_224 = - 4097 ;
V_225:
F_183 () ;
F_122 () ;
V_84 = F_4 ( V_8 , V_9 ) ;
F_142 (osk, head) {
if ( ! V_10 -> V_178 ( V_174 , V_197 ) )
continue;
if ( F_2 ( V_197 ) -> V_9 == V_9 ) {
V_9 = V_224 -- ;
if ( V_224 > - 4097 )
V_224 = - 4097 ;
F_131 () ;
goto V_225;
}
}
F_131 () ;
V_70 = F_156 ( V_2 , V_174 , V_9 ) ;
if ( V_70 == - V_196 )
goto V_225;
if ( V_70 == - V_73 )
V_70 = 0 ;
return V_70 ;
}
static inline int F_184 ( const struct V_93 * V_1 , unsigned int V_226 )
{
return ( V_177 [ V_1 -> V_2 -> V_192 ] . V_3 & V_226 ) ||
F_185 ( F_140 ( V_1 -> V_2 ) -> V_227 , V_228 ) ;
}
static void
F_186 ( struct V_1 * V_2 , unsigned int V_200 )
{
struct V_33 * V_34 = F_2 ( V_2 ) ;
if ( V_34 -> V_200 && ! V_200 )
F_160 ( V_2 ) ;
else if ( ! V_34 -> V_200 && V_200 )
F_187 ( V_2 , & V_177 [ V_2 -> V_192 ] . V_229 ) ;
V_34 -> V_200 = V_200 ;
}
static int F_188 ( struct V_1 * V_2 )
{
struct V_33 * V_34 = F_2 ( V_2 ) ;
unsigned int V_168 ;
unsigned long * V_230 ;
int V_70 = 0 ;
F_122 () ;
V_168 = V_177 [ V_2 -> V_192 ] . V_168 ;
if ( ! V_177 [ V_2 -> V_192 ] . V_216 ) {
V_70 = - V_231 ;
goto V_232;
}
if ( V_34 -> V_194 >= V_168 )
goto V_232;
V_230 = F_189 ( V_34 -> V_168 , F_190 ( V_168 ) , V_32 ) ;
if ( V_230 == NULL ) {
V_70 = - V_31 ;
goto V_232;
}
memset ( ( char * ) V_230 + F_190 ( V_34 -> V_194 ) , 0 ,
F_190 ( V_168 ) - F_190 ( V_34 -> V_194 ) ) ;
V_34 -> V_168 = V_230 ;
V_34 -> V_194 = V_168 ;
V_232:
F_131 () ;
return V_70 ;
}
static int V_218 ( struct V_93 * V_1 , struct V_233 * V_234 ,
int V_235 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_174 * V_174 = F_140 ( V_2 ) ;
struct V_33 * V_34 = F_2 ( V_2 ) ;
struct V_236 * V_237 = (struct V_236 * ) V_234 ;
int V_70 ;
if ( V_235 < sizeof( struct V_236 ) )
return - V_17 ;
if ( V_237 -> V_238 != V_239 )
return - V_17 ;
if ( V_237 -> V_240 ) {
if ( ! F_184 ( V_1 , V_241 ) )
return - V_242 ;
V_70 = F_188 ( V_2 ) ;
if ( V_70 )
return V_70 ;
}
if ( V_34 -> V_9 ) {
if ( V_237 -> V_243 != V_34 -> V_9 )
return - V_17 ;
} else {
V_70 = V_237 -> V_243 ?
F_156 ( V_2 , V_174 , V_237 -> V_243 ) :
F_181 ( V_1 ) ;
if ( V_70 )
return V_70 ;
}
if ( ! V_237 -> V_240 && ( V_34 -> V_168 == NULL || ! ( T_1 ) V_34 -> V_168 [ 0 ] ) )
return 0 ;
F_122 () ;
F_186 ( V_2 , V_34 -> V_200 +
F_191 ( V_237 -> V_240 ) -
F_191 ( V_34 -> V_168 [ 0 ] ) ) ;
V_34 -> V_168 [ 0 ] = ( V_34 -> V_168 [ 0 ] & ~ 0xffffffffUL ) | V_237 -> V_240 ;
F_152 ( V_2 ) ;
F_131 () ;
if ( V_34 -> V_218 && V_34 -> V_168 [ 0 ] ) {
int V_50 ;
for ( V_50 = 0 ; V_50 < V_34 -> V_194 ; V_50 ++ ) {
if ( F_37 ( V_50 , V_34 -> V_168 ) )
V_34 -> V_218 ( V_50 ) ;
}
}
return 0 ;
}
static int F_192 ( struct V_93 * V_1 , struct V_233 * V_234 ,
int V_244 , int V_3 )
{
int V_70 = 0 ;
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_33 * V_34 = F_2 ( V_2 ) ;
struct V_236 * V_237 = (struct V_236 * ) V_234 ;
if ( V_244 < sizeof( V_234 -> V_245 ) )
return - V_17 ;
if ( V_234 -> V_245 == V_246 ) {
V_2 -> V_247 = V_248 ;
V_34 -> V_134 = 0 ;
V_34 -> V_135 = 0 ;
return 0 ;
}
if ( V_234 -> V_245 != V_239 )
return - V_17 ;
if ( V_237 -> V_240 && ! F_184 ( V_1 , V_249 ) )
return - V_242 ;
if ( ! V_34 -> V_9 )
V_70 = F_181 ( V_1 ) ;
if ( V_70 == 0 ) {
V_2 -> V_247 = V_250 ;
V_34 -> V_134 = V_237 -> V_243 ;
V_34 -> V_135 = F_193 ( V_237 -> V_240 ) ;
}
return V_70 ;
}
static int F_194 ( struct V_93 * V_1 , struct V_233 * V_234 ,
int * V_235 , int V_251 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_33 * V_34 = F_2 ( V_2 ) ;
F_195 ( struct V_236 * , V_237 , V_234 ) ;
V_237 -> V_238 = V_239 ;
V_237 -> V_252 = 0 ;
* V_235 = sizeof( * V_237 ) ;
if ( V_251 ) {
V_237 -> V_243 = V_34 -> V_134 ;
V_237 -> V_240 = F_3 ( V_34 -> V_135 ) ;
} else {
V_237 -> V_243 = V_34 -> V_9 ;
V_237 -> V_240 = V_34 -> V_168 ? V_34 -> V_168 [ 0 ] : 0 ;
}
return 0 ;
}
static struct V_1 * F_196 ( struct V_1 * V_253 , T_1 V_9 )
{
struct V_1 * V_1 ;
struct V_33 * V_34 ;
V_1 = F_141 ( F_140 ( V_253 ) , V_253 -> V_192 , V_9 ) ;
if ( ! V_1 )
return F_197 ( - V_254 ) ;
V_34 = F_2 ( V_1 ) ;
if ( V_1 -> V_247 == V_250 &&
V_34 -> V_134 != F_2 ( V_253 ) -> V_9 ) {
F_111 ( V_1 ) ;
return F_197 ( - V_254 ) ;
}
return V_1 ;
}
struct V_1 * F_198 ( struct V_91 * V_255 )
{
struct V_256 * V_256 = F_199 ( V_255 ) ;
struct V_1 * V_1 ;
if ( ! F_200 ( V_256 -> V_257 ) )
return F_197 ( - V_258 ) ;
V_1 = F_201 ( V_256 ) -> V_2 ;
if ( V_1 -> V_259 != V_239 )
return F_197 ( - V_17 ) ;
F_94 ( V_1 ) ;
return V_1 ;
}
static struct V_27 * F_202 ( unsigned int V_96 ,
int V_260 )
{
struct V_27 * V_28 ;
void * V_127 ;
if ( V_96 <= V_261 || V_260 )
return F_96 ( V_96 , V_53 ) ;
V_96 = F_203 ( V_96 ) +
F_203 ( sizeof( struct V_262 ) ) ;
V_127 = F_204 ( V_96 ) ;
if ( V_127 == NULL )
return NULL ;
V_28 = F_205 ( V_127 , V_96 ) ;
if ( V_28 == NULL )
F_45 ( V_127 ) ;
else {
V_28 -> V_263 = 0 ;
V_28 -> V_130 = V_131 ;
}
return V_28 ;
}
int F_206 ( struct V_1 * V_2 , struct V_27 * V_28 ,
long * V_264 , struct V_1 * V_253 )
{
struct V_33 * V_34 ;
V_34 = F_2 ( V_2 ) ;
if ( ( F_54 ( & V_2 -> V_163 ) > V_2 -> V_265 ||
F_37 ( V_36 , & V_34 -> V_37 ) ) &&
! F_39 ( V_28 ) ) {
F_125 ( V_43 , V_170 ) ;
if ( ! * V_264 ) {
if ( ! V_253 || F_1 ( V_253 ) )
F_31 ( V_2 ) ;
F_111 ( V_2 ) ;
F_98 ( V_28 ) ;
return - V_266 ;
}
F_129 ( V_267 ) ;
F_207 ( & V_34 -> V_43 , & V_43 ) ;
if ( ( F_54 ( & V_2 -> V_163 ) > V_2 -> V_265 ||
F_37 ( V_36 , & V_34 -> V_37 ) ) &&
! F_120 ( V_2 , V_165 ) )
* V_264 = F_208 ( * V_264 ) ;
F_129 ( V_173 ) ;
F_130 ( & V_34 -> V_43 , & V_43 ) ;
F_111 ( V_2 ) ;
if ( F_209 ( V_170 ) ) {
F_98 ( V_28 ) ;
return F_210 ( * V_264 ) ;
}
return 1 ;
}
F_115 ( V_28 , V_2 ) ;
return 0 ;
}
static int F_211 ( struct V_1 * V_2 , struct V_27 * V_28 )
{
int V_49 = V_28 -> V_49 ;
F_27 ( V_28 ) ;
#ifdef F_110
if ( F_39 ( V_28 ) )
F_101 ( V_2 , V_28 ) ;
else if ( F_41 ( V_2 ) )
F_105 ( V_2 , V_28 ) ;
else
#endif
F_212 ( & V_2 -> V_42 , V_28 ) ;
V_2 -> V_268 ( V_2 , V_49 ) ;
return V_49 ;
}
int F_213 ( struct V_1 * V_2 , struct V_27 * V_28 )
{
int V_49 = F_211 ( V_2 , V_28 ) ;
F_111 ( V_2 ) ;
return V_49 ;
}
void F_214 ( struct V_1 * V_2 , struct V_27 * V_28 )
{
F_98 ( V_28 ) ;
F_111 ( V_2 ) ;
}
static struct V_27 * F_215 ( struct V_27 * V_28 , T_2 V_269 )
{
int V_270 ;
F_62 ( V_28 -> V_2 != NULL ) ;
if ( F_39 ( V_28 ) )
return V_28 ;
V_270 = V_28 -> V_128 - V_28 -> V_129 ;
if ( F_44 ( V_28 -> V_84 ) || V_270 * 2 < V_28 -> V_162 )
return V_28 ;
if ( F_216 ( V_28 ) ) {
struct V_27 * V_30 = F_21 ( V_28 , V_269 ) ;
if ( ! V_30 )
return V_28 ;
F_109 ( V_28 ) ;
V_28 = V_30 ;
}
if ( ! F_217 ( V_28 , 0 , - V_270 , V_269 ) )
V_28 -> V_162 -= V_270 ;
return V_28 ;
}
static int F_218 ( struct V_1 * V_2 , struct V_27 * V_28 ,
struct V_1 * V_253 )
{
int V_26 ;
struct V_33 * V_34 = F_2 ( V_2 ) ;
V_26 = - V_254 ;
if ( V_34 -> V_271 != NULL ) {
V_26 = V_28 -> V_49 ;
F_115 ( V_28 , V_2 ) ;
F_40 ( V_28 ) . V_2 = V_253 ;
V_34 -> V_271 ( V_28 ) ;
F_109 ( V_28 ) ;
} else {
F_98 ( V_28 ) ;
}
F_111 ( V_2 ) ;
return V_26 ;
}
int F_100 ( struct V_1 * V_253 , struct V_27 * V_28 ,
T_1 V_9 , int V_272 )
{
struct V_1 * V_2 ;
int V_70 ;
long V_264 ;
V_28 = F_215 ( V_28 , F_219 () ) ;
V_264 = F_220 ( V_253 , V_272 ) ;
V_225:
V_2 = F_196 ( V_253 , V_9 ) ;
if ( F_221 ( V_2 ) ) {
F_98 ( V_28 ) ;
return F_222 ( V_2 ) ;
}
if ( F_1 ( V_2 ) )
return F_218 ( V_2 , V_28 , V_253 ) ;
if ( F_223 ( V_2 , V_28 ) ) {
V_70 = V_28 -> V_49 ;
F_98 ( V_28 ) ;
F_111 ( V_2 ) ;
return V_70 ;
}
V_70 = F_206 ( V_2 , V_28 , & V_264 , V_253 ) ;
if ( V_70 == 1 )
goto V_225;
if ( V_70 )
return V_70 ;
return F_213 ( V_2 , V_28 ) ;
}
struct V_27 * F_224 ( struct V_1 * V_253 , unsigned int V_96 ,
T_1 V_134 , T_2 V_273 )
{
#ifdef F_110
struct V_1 * V_2 = NULL ;
struct V_27 * V_28 ;
struct V_66 * V_67 ;
struct V_106 * V_107 ;
unsigned int V_138 ;
V_2 = F_196 ( V_253 , V_134 ) ;
if ( F_221 ( V_2 ) )
goto V_24;
V_67 = & F_2 ( V_2 ) -> V_45 ;
if ( V_67 -> V_46 == NULL )
goto V_274;
V_28 = F_93 ( V_273 ) ;
if ( V_28 == NULL )
goto V_64;
F_58 ( & V_2 -> V_42 . V_82 ) ;
if ( V_67 -> V_46 == NULL )
goto V_275;
V_138 = V_67 -> V_85 - V_77 ;
if ( V_138 < V_96 )
goto V_275;
F_81 ( V_67 ) ;
V_107 = F_78 ( V_67 , V_119 ) ;
if ( V_107 == NULL )
goto V_276;
F_87 ( V_28 , V_2 , V_67 , V_107 ) ;
F_74 ( V_107 , V_146 ) ;
F_33 ( & V_67 -> V_74 ) ;
F_80 ( V_67 ) ;
F_61 ( & V_2 -> V_42 . V_82 ) ;
return V_28 ;
V_276:
F_98 ( V_28 ) ;
F_61 ( & V_2 -> V_42 . V_82 ) ;
F_31 ( V_2 ) ;
V_64:
F_111 ( V_2 ) ;
return NULL ;
V_275:
F_98 ( V_28 ) ;
F_61 ( & V_2 -> V_42 . V_82 ) ;
V_274:
F_111 ( V_2 ) ;
V_24:
#endif
return F_96 ( V_96 , V_273 ) ;
}
int F_225 ( struct V_1 * V_2 , unsigned int V_5 )
{
int V_277 = 0 ;
struct V_193 * V_193 ;
F_178 ( ! F_1 ( V_2 ) ) ;
F_28 () ;
V_193 = F_226 ( V_177 [ V_2 -> V_192 ] . V_193 ) ;
if ( V_193 && V_5 - 1 < V_177 [ V_2 -> V_192 ] . V_168 )
V_277 = F_37 ( V_5 - 1 , V_193 -> V_195 ) ;
F_30 () ;
return V_277 ;
}
static int F_227 ( struct V_1 * V_2 , struct V_27 * V_28 )
{
struct V_33 * V_34 = F_2 ( V_2 ) ;
if ( F_54 ( & V_2 -> V_163 ) <= V_2 -> V_265 &&
! F_37 ( V_36 , & V_34 -> V_37 ) ) {
F_115 ( V_28 , V_2 ) ;
F_211 ( V_2 , V_28 ) ;
return F_54 ( & V_2 -> V_163 ) > ( V_2 -> V_265 >> 1 ) ;
}
return - 1 ;
}
static int F_228 ( struct V_1 * V_2 ,
struct V_278 * V_279 )
{
struct V_33 * V_34 = F_2 ( V_2 ) ;
int V_280 ;
if ( V_279 -> V_281 == V_2 )
goto V_24;
if ( V_34 -> V_9 == V_279 -> V_9 || V_279 -> V_5 - 1 >= V_34 -> V_194 ||
! F_37 ( V_279 -> V_5 - 1 , V_34 -> V_168 ) )
goto V_24;
if ( ! F_139 ( F_140 ( V_2 ) , V_279 -> V_174 ) )
goto V_24;
if ( V_279 -> V_282 ) {
F_31 ( V_2 ) ;
goto V_24;
}
F_94 ( V_2 ) ;
if ( V_279 -> V_283 == NULL ) {
if ( F_216 ( V_279 -> V_28 ) ) {
V_279 -> V_283 = F_21 ( V_279 -> V_28 , V_279 -> V_269 ) ;
} else {
V_279 -> V_283 = F_229 ( V_279 -> V_28 ) ;
F_230 ( V_279 -> V_283 ) ;
}
}
if ( V_279 -> V_283 == NULL ) {
F_31 ( V_2 ) ;
V_279 -> V_282 = 1 ;
if ( V_34 -> V_3 & V_284 )
V_279 -> V_285 = 1 ;
} else if ( V_279 -> V_286 && V_279 -> V_286 ( V_2 , V_279 -> V_283 , V_279 -> V_287 ) ) {
F_98 ( V_279 -> V_283 ) ;
V_279 -> V_283 = NULL ;
} else if ( F_223 ( V_2 , V_279 -> V_283 ) ) {
F_98 ( V_279 -> V_283 ) ;
V_279 -> V_283 = NULL ;
} else if ( ( V_280 = F_227 ( V_2 , V_279 -> V_283 ) ) < 0 ) {
F_31 ( V_2 ) ;
if ( V_34 -> V_3 & V_284 )
V_279 -> V_285 = 1 ;
} else {
V_279 -> V_288 |= V_280 ;
V_279 -> V_289 = 1 ;
V_279 -> V_283 = NULL ;
}
F_111 ( V_2 ) ;
V_24:
return 0 ;
}
int F_231 ( struct V_1 * V_253 , struct V_27 * V_28 , T_1 V_9 ,
T_1 V_5 , T_2 V_269 ,
int (* F_232)( struct V_1 * V_290 , struct V_27 * V_28 , void * V_127 ) ,
void * V_291 )
{
struct V_174 * V_174 = F_140 ( V_253 ) ;
struct V_278 V_292 ;
struct V_1 * V_2 ;
V_28 = F_215 ( V_28 , V_269 ) ;
V_292 . V_281 = V_253 ;
V_292 . V_174 = V_174 ;
V_292 . V_9 = V_9 ;
V_292 . V_5 = V_5 ;
V_292 . V_282 = 0 ;
V_292 . V_285 = 0 ;
V_292 . V_288 = 0 ;
V_292 . V_289 = 0 ;
V_292 . V_269 = V_269 ;
V_292 . V_28 = V_28 ;
V_292 . V_283 = NULL ;
V_292 . V_286 = F_232 ;
V_292 . V_287 = V_291 ;
F_133 () ;
F_155 (sk, &nl_table[ssk->sk_protocol].mc_list)
F_228 ( V_2 , & V_292 ) ;
F_109 ( V_28 ) ;
F_136 () ;
if ( V_292 . V_285 ) {
F_98 ( V_292 . V_283 ) ;
return - V_39 ;
}
F_109 ( V_292 . V_283 ) ;
if ( V_292 . V_289 ) {
if ( V_292 . V_288 && ( V_269 & V_293 ) )
F_233 () ;
return 0 ;
}
return - V_294 ;
}
int F_99 ( struct V_1 * V_253 , struct V_27 * V_28 , T_1 V_9 ,
T_1 V_5 , T_2 V_269 )
{
return F_231 ( V_253 , V_28 , V_9 , V_5 , V_269 ,
NULL , NULL ) ;
}
static int F_234 ( struct V_1 * V_2 , struct V_295 * V_279 )
{
struct V_33 * V_34 = F_2 ( V_2 ) ;
int V_26 = 0 ;
if ( V_2 == V_279 -> V_281 )
goto V_24;
if ( ! F_139 ( F_140 ( V_2 ) , F_140 ( V_279 -> V_281 ) ) )
goto V_24;
if ( V_34 -> V_9 == V_279 -> V_9 || V_279 -> V_5 - 1 >= V_34 -> V_194 ||
! F_37 ( V_279 -> V_5 - 1 , V_34 -> V_168 ) )
goto V_24;
if ( V_279 -> V_296 == V_39 && V_34 -> V_3 & V_35 ) {
V_26 = 1 ;
goto V_24;
}
V_2 -> V_38 = V_279 -> V_296 ;
V_2 -> V_40 ( V_2 ) ;
V_24:
return V_26 ;
}
int F_235 ( struct V_1 * V_253 , T_1 V_9 , T_1 V_5 , int V_296 )
{
struct V_295 V_292 ;
struct V_1 * V_2 ;
int V_26 = 0 ;
V_292 . V_281 = V_253 ;
V_292 . V_9 = V_9 ;
V_292 . V_5 = V_5 ;
V_292 . V_296 = - V_296 ;
F_134 ( & T_4 ) ;
F_155 (sk, &nl_table[ssk->sk_protocol].mc_list)
V_26 += F_234 ( V_2 , & V_292 ) ;
F_135 ( & T_4 ) ;
return V_26 ;
}
static void F_236 ( struct V_33 * V_34 ,
unsigned int V_5 ,
int V_297 )
{
int V_222 , V_298 = ! ! V_297 , V_200 ;
V_222 = F_37 ( V_5 - 1 , V_34 -> V_168 ) ;
V_200 = V_34 -> V_200 - V_222 + V_298 ;
if ( V_298 )
F_237 ( V_5 - 1 , V_34 -> V_168 ) ;
else
F_238 ( V_5 - 1 , V_34 -> V_168 ) ;
F_186 ( & V_34 -> V_2 , V_200 ) ;
F_152 ( & V_34 -> V_2 ) ;
}
static int F_239 ( struct V_93 * V_1 , int V_299 , int V_300 ,
char T_7 * V_301 , unsigned int V_302 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_33 * V_34 = F_2 ( V_2 ) ;
unsigned int V_280 = 0 ;
int V_70 ;
if ( V_299 != V_303 )
return - V_304 ;
if ( V_300 != V_305 && V_300 != V_306 &&
V_302 >= sizeof( int ) &&
F_240 ( V_280 , ( unsigned int T_7 * ) V_301 ) )
return - V_307 ;
switch ( V_300 ) {
case V_308 :
if ( V_280 )
V_34 -> V_3 |= V_309 ;
else
V_34 -> V_3 &= ~ V_309 ;
V_70 = 0 ;
break;
case V_310 :
case V_311 : {
if ( ! F_184 ( V_1 , V_241 ) )
return - V_242 ;
V_70 = F_188 ( V_2 ) ;
if ( V_70 )
return V_70 ;
if ( ! V_280 || V_280 - 1 >= V_34 -> V_194 )
return - V_17 ;
F_122 () ;
F_236 ( V_34 , V_280 ,
V_300 == V_310 ) ;
F_131 () ;
if ( V_34 -> V_218 )
V_34 -> V_218 ( V_280 ) ;
V_70 = 0 ;
break;
}
case V_312 :
if ( V_280 )
V_34 -> V_3 |= V_284 ;
else
V_34 -> V_3 &= ~ V_284 ;
V_70 = 0 ;
break;
case V_313 :
if ( V_280 ) {
V_34 -> V_3 |= V_35 ;
F_36 ( V_36 , & V_34 -> V_37 ) ;
F_38 ( & V_34 -> V_43 ) ;
} else {
V_34 -> V_3 &= ~ V_35 ;
}
V_70 = 0 ;
break;
#ifdef F_110
case V_305 :
case V_306 : {
struct V_59 V_60 ;
if ( ! F_241 ( V_228 ) )
return - V_242 ;
if ( V_302 < sizeof( V_60 ) )
return - V_17 ;
if ( F_242 ( & V_60 , V_301 , sizeof( V_60 ) ) )
return - V_307 ;
V_70 = F_53 ( V_2 , & V_60 , false ,
V_300 == V_306 ) ;
break;
}
#endif
default:
V_70 = - V_304 ;
}
return V_70 ;
}
static int F_243 ( struct V_93 * V_1 , int V_299 , int V_300 ,
char T_7 * V_301 , int T_7 * V_302 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_33 * V_34 = F_2 ( V_2 ) ;
int V_49 , V_280 , V_70 ;
if ( V_299 != V_303 )
return - V_304 ;
if ( F_240 ( V_49 , V_302 ) )
return - V_307 ;
if ( V_49 < 0 )
return - V_17 ;
switch ( V_300 ) {
case V_308 :
if ( V_49 < sizeof( int ) )
return - V_17 ;
V_49 = sizeof( int ) ;
V_280 = V_34 -> V_3 & V_309 ? 1 : 0 ;
if ( F_244 ( V_49 , V_302 ) ||
F_244 ( V_280 , V_301 ) )
return - V_307 ;
V_70 = 0 ;
break;
case V_312 :
if ( V_49 < sizeof( int ) )
return - V_17 ;
V_49 = sizeof( int ) ;
V_280 = V_34 -> V_3 & V_284 ? 1 : 0 ;
if ( F_244 ( V_49 , V_302 ) ||
F_244 ( V_280 , V_301 ) )
return - V_307 ;
V_70 = 0 ;
break;
case V_313 :
if ( V_49 < sizeof( int ) )
return - V_17 ;
V_49 = sizeof( int ) ;
V_280 = V_34 -> V_3 & V_35 ? 1 : 0 ;
if ( F_244 ( V_49 , V_302 ) ||
F_244 ( V_280 , V_301 ) )
return - V_307 ;
V_70 = 0 ;
break;
default:
V_70 = - V_304 ;
}
return V_70 ;
}
static void F_245 ( struct V_132 * V_133 , struct V_27 * V_28 )
{
struct V_314 V_292 ;
V_292 . V_5 = F_40 ( V_28 ) . V_135 ;
F_246 ( V_133 , V_303 , V_308 , sizeof( V_292 ) , & V_292 ) ;
}
static int F_247 ( struct V_315 * V_315 , struct V_93 * V_1 ,
struct V_132 * V_133 , T_5 V_49 )
{
struct V_136 * V_137 = F_248 ( V_315 ) ;
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_33 * V_34 = F_2 ( V_2 ) ;
struct V_236 * V_234 = V_133 -> V_316 ;
T_1 V_134 ;
T_1 V_135 ;
struct V_27 * V_28 ;
int V_70 ;
struct V_317 V_148 ;
if ( V_133 -> V_143 & V_318 )
return - V_319 ;
if ( NULL == V_137 -> V_148 )
V_137 -> V_148 = & V_148 ;
V_70 = F_249 ( V_1 , V_133 , V_137 -> V_148 , true ) ;
if ( V_70 < 0 )
return V_70 ;
if ( V_133 -> V_320 ) {
V_70 = - V_17 ;
if ( V_234 -> V_238 != V_239 )
goto V_24;
V_134 = V_234 -> V_243 ;
V_135 = F_193 ( V_234 -> V_240 ) ;
V_70 = - V_242 ;
if ( ( V_135 || V_134 ) &&
! F_184 ( V_1 , V_249 ) )
goto V_24;
} else {
V_134 = V_34 -> V_134 ;
V_135 = V_34 -> V_135 ;
}
if ( ! V_34 -> V_9 ) {
V_70 = F_181 ( V_1 ) ;
if ( V_70 )
goto V_24;
}
if ( F_42 ( V_2 ) &&
V_133 -> V_321 -> V_322 == NULL ) {
V_70 = F_89 ( V_2 , V_133 , V_134 , V_135 ,
V_137 ) ;
goto V_24;
}
V_70 = - V_323 ;
if ( V_49 > V_2 -> V_324 - 32 )
goto V_24;
V_70 = - V_39 ;
V_28 = F_202 ( V_49 , V_135 ) ;
if ( V_28 == NULL )
goto V_24;
F_40 ( V_28 ) . V_9 = V_34 -> V_9 ;
F_40 ( V_28 ) . V_135 = V_135 ;
F_40 ( V_28 ) . V_147 = V_137 -> V_148 -> V_147 ;
V_70 = - V_307 ;
if ( F_250 ( F_251 ( V_28 , V_49 ) , V_133 -> V_321 , V_49 ) ) {
F_98 ( V_28 ) ;
goto V_24;
}
V_70 = F_97 ( V_2 , V_28 ) ;
if ( V_70 ) {
F_98 ( V_28 ) ;
goto V_24;
}
if ( V_135 ) {
F_33 ( & V_28 -> V_149 ) ;
F_99 ( V_2 , V_28 , V_134 , V_135 , V_53 ) ;
}
V_70 = F_100 ( V_2 , V_28 , V_134 , V_133 -> V_143 & V_144 ) ;
V_24:
F_252 ( V_137 -> V_148 ) ;
return V_70 ;
}
static int F_253 ( struct V_315 * V_315 , struct V_93 * V_1 ,
struct V_132 * V_133 , T_5 V_49 ,
int V_3 )
{
struct V_136 * V_137 = F_248 ( V_315 ) ;
struct V_317 V_148 ;
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_33 * V_34 = F_2 ( V_2 ) ;
int V_325 = V_3 & V_144 ;
T_5 V_326 ;
struct V_27 * V_28 , * V_327 ;
int V_70 , V_26 ;
if ( V_3 & V_318 )
return - V_319 ;
V_326 = 0 ;
V_28 = F_254 ( V_2 , V_3 , V_325 , & V_70 ) ;
if ( V_28 == NULL )
goto V_24;
V_327 = V_28 ;
#ifdef F_255
if ( F_7 ( F_113 ( V_28 ) -> V_328 ) ) {
if ( V_3 & V_329 )
V_327 = F_113 ( V_28 ) -> V_328 ;
}
#endif
V_133 -> V_320 = 0 ;
V_326 = V_327 -> V_49 ;
if ( V_49 < V_326 ) {
V_133 -> V_143 |= V_330 ;
V_326 = V_49 ;
}
F_256 ( V_327 ) ;
V_70 = F_257 ( V_327 , 0 , V_133 -> V_321 , V_326 ) ;
if ( V_133 -> V_316 ) {
struct V_236 * V_234 = (struct V_236 * ) V_133 -> V_316 ;
V_234 -> V_238 = V_239 ;
V_234 -> V_252 = 0 ;
V_234 -> V_243 = F_40 ( V_28 ) . V_9 ;
V_234 -> V_240 = F_3 ( F_40 ( V_28 ) . V_135 ) ;
V_133 -> V_320 = sizeof( * V_234 ) ;
}
if ( V_34 -> V_3 & V_309 )
F_245 ( V_133 , V_28 ) ;
if ( NULL == V_137 -> V_148 ) {
memset ( & V_148 , 0 , sizeof( V_148 ) ) ;
V_137 -> V_148 = & V_148 ;
}
V_137 -> V_148 -> V_147 = * F_258 ( V_28 ) ;
if ( V_3 & V_330 )
V_326 = V_327 -> V_49 ;
F_259 ( V_2 , V_28 ) ;
if ( V_34 -> V_122 && F_54 ( & V_2 -> V_163 ) <= V_2 -> V_265 / 2 ) {
V_26 = F_84 ( V_2 ) ;
if ( V_26 ) {
V_2 -> V_38 = V_26 ;
V_2 -> V_40 ( V_2 ) ;
}
}
F_260 ( V_1 , V_133 , V_137 -> V_148 , V_3 ) ;
V_24:
F_34 ( V_2 ) ;
return V_70 ? : V_326 ;
}
static void F_261 ( struct V_1 * V_2 , int V_49 )
{
F_262 () ;
}
struct V_1 *
F_263 ( struct V_174 * V_174 , int V_331 , struct V_21 * V_21 ,
struct V_332 * V_333 )
{
struct V_93 * V_1 ;
struct V_1 * V_2 ;
struct V_33 * V_34 ;
struct V_193 * V_193 = NULL ;
struct V_201 * V_202 = V_333 ? V_333 -> V_202 : NULL ;
unsigned int V_168 ;
F_178 ( ! V_177 ) ;
if ( V_331 < 0 || V_331 >= V_214 )
return NULL ;
if ( F_264 ( V_205 , V_212 , V_331 , & V_1 ) )
return NULL ;
if ( F_161 ( & V_334 , V_1 , V_202 , V_331 ) < 0 )
goto V_335;
V_2 = V_1 -> V_2 ;
F_265 ( V_2 , V_174 ) ;
if ( ! V_333 || V_333 -> V_168 < 32 )
V_168 = 32 ;
else
V_168 = V_333 -> V_168 ;
V_193 = F_144 ( sizeof( * V_193 ) + F_190 ( V_168 ) , V_53 ) ;
if ( ! V_193 )
goto V_336;
V_2 -> V_268 = F_261 ;
if ( V_333 && V_333 -> V_337 )
F_2 ( V_2 ) -> V_271 = V_333 -> V_337 ;
if ( F_156 ( V_2 , V_174 , 0 ) )
goto V_336;
V_34 = F_2 ( V_2 ) ;
V_34 -> V_3 |= V_4 ;
F_122 () ;
if ( ! V_177 [ V_331 ] . V_216 ) {
V_177 [ V_331 ] . V_168 = V_168 ;
F_266 ( V_177 [ V_331 ] . V_193 , V_193 ) ;
V_177 [ V_331 ] . V_202 = V_202 ;
V_177 [ V_331 ] . V_21 = V_21 ;
if ( V_333 ) {
V_177 [ V_331 ] . F_167 = V_333 -> F_167 ;
V_177 [ V_331 ] . V_3 = V_333 -> V_3 ;
if ( V_333 -> V_178 )
V_177 [ V_331 ] . V_178 = V_333 -> V_178 ;
}
V_177 [ V_331 ] . V_216 = 1 ;
} else {
F_47 ( V_193 ) ;
V_177 [ V_331 ] . V_216 ++ ;
}
F_131 () ;
return V_2 ;
V_336:
F_47 ( V_193 ) ;
F_267 ( V_2 ) ;
return NULL ;
V_335:
F_268 ( V_1 ) ;
return NULL ;
}
void
F_267 ( struct V_1 * V_2 )
{
F_269 ( V_2 ) ;
}
int F_270 ( struct V_1 * V_2 , unsigned int V_168 )
{
struct V_193 * V_298 , * V_222 ;
struct V_176 * V_191 = & V_177 [ V_2 -> V_192 ] ;
if ( V_168 < 32 )
V_168 = 32 ;
if ( F_190 ( V_191 -> V_168 ) < F_190 ( V_168 ) ) {
V_298 = F_144 ( sizeof( * V_298 ) + F_190 ( V_168 ) , V_32 ) ;
if ( ! V_298 )
return - V_31 ;
V_222 = F_153 ( V_191 -> V_193 ) ;
memcpy ( V_298 -> V_195 , V_222 -> V_195 , F_190 ( V_191 -> V_168 ) ) ;
F_266 ( V_191 -> V_193 , V_298 ) ;
F_180 ( V_222 , V_223 ) ;
}
V_191 -> V_168 = V_168 ;
return 0 ;
}
int F_271 ( struct V_1 * V_2 , unsigned int V_168 )
{
int V_70 ;
F_122 () ;
V_70 = F_270 ( V_2 , V_168 ) ;
F_131 () ;
return V_70 ;
}
void F_272 ( struct V_1 * V_338 , unsigned int V_5 )
{
struct V_1 * V_2 ;
struct V_176 * V_191 = & V_177 [ V_338 -> V_192 ] ;
F_155 (sk, &tbl->mc_list)
F_236 ( F_2 ( V_2 ) , V_5 , 0 ) ;
}
void F_273 ( struct V_1 * V_338 , unsigned int V_5 )
{
F_122 () ;
F_272 ( V_338 , V_5 ) ;
F_131 () ;
}
struct V_339 *
F_274 ( struct V_27 * V_28 , T_1 V_9 , T_1 V_340 , int type , int V_49 , int V_3 )
{
struct V_339 * V_341 ;
int V_96 = F_275 ( V_49 ) ;
V_341 = (struct V_339 * ) F_251 ( V_28 , F_276 ( V_96 ) ) ;
V_341 -> V_342 = type ;
V_341 -> V_343 = V_96 ;
V_341 -> V_344 = V_3 ;
V_341 -> V_345 = V_9 ;
V_341 -> V_346 = V_340 ;
if ( ! F_277 ( V_96 ) || F_276 ( V_96 ) - V_96 != 0 )
memset ( F_278 ( V_341 ) + V_49 , 0 , F_276 ( V_96 ) - V_96 ) ;
return V_341 ;
}
static int F_84 ( struct V_1 * V_2 )
{
struct V_33 * V_34 = F_2 ( V_2 ) ;
struct V_159 * V_122 ;
struct V_27 * V_28 = NULL ;
struct V_339 * V_341 ;
int V_49 , V_70 = - V_39 ;
int V_347 ;
F_57 ( V_34 -> V_202 ) ;
V_122 = V_34 -> V_122 ;
if ( V_122 == NULL ) {
V_70 = - V_17 ;
goto V_348;
}
V_347 = F_279 ( int , V_122 -> V_349 , V_261 ) ;
if ( ! F_41 ( V_2 ) &&
F_54 ( & V_2 -> V_163 ) >= V_2 -> V_265 )
goto V_348;
V_28 = F_224 ( V_2 , V_347 , V_34 -> V_9 , V_53 ) ;
if ( ! V_28 )
goto V_348;
F_115 ( V_28 , V_2 ) ;
V_49 = V_122 -> V_350 ( V_28 , V_122 ) ;
if ( V_49 > 0 ) {
F_63 ( V_34 -> V_202 ) ;
if ( F_223 ( V_2 , V_28 ) )
F_98 ( V_28 ) ;
else
F_211 ( V_2 , V_28 ) ;
return 0 ;
}
V_341 = F_280 ( V_28 , V_122 , V_351 , sizeof( V_49 ) , V_352 ) ;
if ( ! V_341 )
goto V_348;
F_281 ( V_122 , V_341 ) ;
memcpy ( F_278 ( V_341 ) , & V_49 , sizeof( V_49 ) ) ;
if ( F_223 ( V_2 , V_28 ) )
F_98 ( V_28 ) ;
else
F_211 ( V_2 , V_28 ) ;
if ( V_122 -> V_164 )
V_122 -> V_164 ( V_122 ) ;
V_34 -> V_122 = NULL ;
F_63 ( V_34 -> V_202 ) ;
F_16 ( V_122 -> V_21 ) ;
F_108 ( V_122 ) ;
return 0 ;
V_348:
F_63 ( V_34 -> V_202 ) ;
F_98 ( V_28 ) ;
return V_70 ;
}
int F_282 ( struct V_1 * V_253 , struct V_27 * V_28 ,
const struct V_339 * V_341 ,
struct V_353 * V_354 )
{
struct V_159 * V_122 ;
struct V_1 * V_2 ;
struct V_33 * V_34 ;
int V_26 ;
V_122 = F_144 ( sizeof( * V_122 ) , V_53 ) ;
if ( V_122 == NULL )
return - V_39 ;
if ( F_39 ( V_28 ) ) {
V_28 = F_283 ( V_28 , V_53 ) ;
if ( V_28 == NULL ) {
F_47 ( V_122 ) ;
return - V_39 ;
}
} else
F_33 ( & V_28 -> V_149 ) ;
V_122 -> V_350 = V_354 -> V_350 ;
V_122 -> V_164 = V_354 -> V_164 ;
V_122 -> V_341 = V_341 ;
V_122 -> V_127 = V_354 -> V_127 ;
V_122 -> V_21 = V_354 -> V_21 ;
V_122 -> V_349 = V_354 -> V_349 ;
V_122 -> V_28 = V_28 ;
V_2 = F_141 ( F_140 ( V_253 ) , V_253 -> V_192 , F_40 ( V_28 ) . V_9 ) ;
if ( V_2 == NULL ) {
F_107 ( V_122 ) ;
return - V_254 ;
}
V_34 = F_2 ( V_2 ) ;
F_57 ( V_34 -> V_202 ) ;
if ( V_34 -> V_122 ) {
F_63 ( V_34 -> V_202 ) ;
F_107 ( V_122 ) ;
V_26 = - V_73 ;
goto V_24;
}
if ( ! F_170 ( V_122 -> V_21 ) ) {
F_63 ( V_34 -> V_202 ) ;
F_107 ( V_122 ) ;
V_26 = - V_215 ;
goto V_24;
}
V_34 -> V_122 = V_122 ;
F_63 ( V_34 -> V_202 ) ;
V_26 = F_84 ( V_2 ) ;
V_24:
F_111 ( V_2 ) ;
if ( V_26 )
return V_26 ;
return - V_355 ;
}
void F_284 ( struct V_27 * V_356 , struct V_339 * V_341 , int V_70 )
{
struct V_27 * V_28 ;
struct V_339 * V_357 ;
struct V_358 * V_359 ;
T_5 V_360 = sizeof( * V_359 ) ;
if ( V_70 )
V_360 += V_343 ( V_341 ) ;
V_28 = F_224 ( V_356 -> V_2 , F_285 ( V_360 ) ,
F_40 ( V_356 ) . V_9 , V_53 ) ;
if ( ! V_28 ) {
struct V_1 * V_2 ;
V_2 = F_141 ( F_140 ( V_356 -> V_2 ) ,
V_356 -> V_2 -> V_192 ,
F_40 ( V_356 ) . V_9 ) ;
if ( V_2 ) {
V_2 -> V_38 = V_39 ;
V_2 -> V_40 ( V_2 ) ;
F_111 ( V_2 ) ;
}
return;
}
V_357 = F_274 ( V_28 , F_40 ( V_356 ) . V_9 , V_341 -> V_346 ,
V_361 , V_360 , 0 ) ;
V_359 = F_278 ( V_357 ) ;
V_359 -> error = V_70 ;
memcpy ( & V_359 -> V_133 , V_341 , V_70 ? V_341 -> V_343 : sizeof( * V_341 ) ) ;
F_100 ( V_356 -> V_2 , V_28 , F_40 ( V_356 ) . V_9 , V_144 ) ;
}
int F_286 ( struct V_27 * V_28 , int (* V_122)( struct V_27 * ,
struct V_339 * ) )
{
struct V_339 * V_341 ;
int V_70 ;
while ( V_28 -> V_49 >= F_285 ( 0 ) ) {
int V_362 ;
V_341 = F_287 ( V_28 ) ;
V_70 = 0 ;
if ( V_341 -> V_343 < V_363 || V_28 -> V_49 < V_341 -> V_343 )
return 0 ;
if ( ! ( V_341 -> V_344 & V_364 ) )
goto V_365;
if ( V_341 -> V_342 < V_366 )
goto V_365;
V_70 = V_122 ( V_28 , V_341 ) ;
if ( V_70 == - V_355 )
goto V_367;
V_365:
if ( V_341 -> V_344 & V_368 || V_70 )
F_284 ( V_28 , V_341 , V_70 ) ;
V_367:
V_362 = F_276 ( V_341 -> V_343 ) ;
if ( V_362 > V_28 -> V_49 )
V_362 = V_28 -> V_49 ;
F_288 ( V_28 , V_362 ) ;
}
return 0 ;
}
int F_289 ( struct V_1 * V_2 , struct V_27 * V_28 , T_1 V_9 ,
unsigned int V_5 , int V_369 , T_2 V_3 )
{
int V_70 = 0 ;
if ( V_5 ) {
int V_370 = 0 ;
if ( V_369 ) {
F_33 ( & V_28 -> V_149 ) ;
V_370 = V_9 ;
}
V_70 = F_290 ( V_2 , V_28 , V_370 , V_5 , V_3 ) ;
}
if ( V_369 ) {
int V_276 ;
V_276 = F_291 ( V_2 , V_28 , V_9 ) ;
if ( ! V_70 || V_70 == - V_294 )
V_70 = V_276 ;
}
return V_70 ;
}
static struct V_1 * F_292 ( struct V_371 * V_340 , T_8 V_115 )
{
struct V_372 * V_373 = V_340 -> V_374 ;
int V_50 , V_375 ;
struct V_1 * V_376 ;
T_8 V_377 = 0 ;
for ( V_50 = 0 ; V_50 < V_214 ; V_50 ++ ) {
struct V_7 * V_8 = & V_177 [ V_50 ] . V_8 ;
for ( V_375 = 0 ; V_375 <= V_8 -> V_12 ; V_375 ++ ) {
F_142 (s, &hash->table[j]) {
if ( F_140 ( V_376 ) != F_293 ( V_340 ) )
continue;
if ( V_377 == V_115 ) {
V_373 -> V_378 = V_50 ;
V_373 -> V_379 = V_375 ;
return V_376 ;
}
++ V_377 ;
}
}
}
return NULL ;
}
static void * F_294 ( struct V_371 * V_340 , T_8 * V_115 )
__acquires( T_4 )
{
F_134 ( & T_4 ) ;
return * V_115 ? F_292 ( V_340 , * V_115 - 1 ) : V_380 ;
}
static void * F_295 ( struct V_371 * V_340 , void * V_381 , T_8 * V_115 )
{
struct V_1 * V_376 ;
struct V_372 * V_373 ;
struct V_174 * V_174 ;
int V_50 , V_375 ;
++ * V_115 ;
if ( V_381 == V_380 )
return F_292 ( V_340 , 0 ) ;
V_174 = F_293 ( V_340 ) ;
V_373 = V_340 -> V_374 ;
V_376 = V_381 ;
do {
V_376 = F_296 ( V_376 ) ;
} while ( V_376 && ! V_177 [ V_376 -> V_192 ] . V_178 ( V_174 , V_376 ) );
if ( V_376 )
return V_376 ;
V_50 = V_373 -> V_378 ;
V_375 = V_373 -> V_379 + 1 ;
do {
struct V_7 * V_8 = & V_177 [ V_50 ] . V_8 ;
for (; V_375 <= V_8 -> V_12 ; V_375 ++ ) {
V_376 = F_297 ( & V_8 -> V_10 [ V_375 ] ) ;
while ( V_376 && ! V_177 [ V_376 -> V_192 ] . V_178 ( V_174 , V_376 ) )
V_376 = F_296 ( V_376 ) ;
if ( V_376 ) {
V_373 -> V_378 = V_50 ;
V_373 -> V_379 = V_375 ;
return V_376 ;
}
}
V_375 = 0 ;
} while ( ++ V_50 < V_214 );
return NULL ;
}
static void F_298 ( struct V_371 * V_340 , void * V_381 )
__releases( T_4 )
{
F_135 ( & T_4 ) ;
}
static int F_299 ( struct V_371 * V_340 , void * V_381 )
{
if ( V_381 == V_380 ) {
F_300 ( V_340 ,
L_4
L_5 ) ;
} else {
struct V_1 * V_376 = V_381 ;
struct V_33 * V_34 = F_2 ( V_376 ) ;
F_301 ( V_340 , L_6 ,
V_376 ,
V_376 -> V_192 ,
V_34 -> V_9 ,
V_34 -> V_168 ? ( T_1 ) V_34 -> V_168 [ 0 ] : 0 ,
F_302 ( V_376 ) ,
F_303 ( V_376 ) ,
V_34 -> V_122 ,
F_54 ( & V_376 -> V_382 ) ,
F_54 ( & V_376 -> V_41 ) ,
F_304 ( V_376 )
) ;
}
return 0 ;
}
static int F_305 ( struct V_256 * V_256 , struct V_91 * V_91 )
{
return F_306 ( V_256 , V_91 , & V_383 ,
sizeof( struct V_372 ) ) ;
}
int F_307 ( struct V_384 * V_385 )
{
return F_308 ( & V_220 , V_385 ) ;
}
int F_309 ( struct V_384 * V_385 )
{
return F_310 ( & V_220 , V_385 ) ;
}
static int T_9 F_311 ( struct V_174 * V_174 )
{
#ifdef F_312
if ( ! F_313 ( L_7 , 0 , V_174 -> V_386 , & V_387 ) )
return - V_31 ;
#endif
return 0 ;
}
static void T_10 F_314 ( struct V_174 * V_174 )
{
#ifdef F_312
F_315 ( L_7 , V_174 -> V_386 ) ;
#endif
}
static void T_11 F_316 ( void )
{
struct V_193 * V_193 ;
int V_168 = 32 ;
V_193 = F_144 ( sizeof( * V_193 ) + F_190 ( V_168 ) , V_53 ) ;
if ( ! V_193 )
F_317 ( L_8 ) ;
F_122 () ;
V_177 [ V_388 ] . V_168 = V_168 ;
F_266 ( V_177 [ V_388 ] . V_193 , V_193 ) ;
V_177 [ V_388 ] . V_21 = V_389 ;
V_177 [ V_388 ] . V_216 = 1 ;
V_177 [ V_388 ] . V_3 = V_249 ;
F_131 () ;
}
static int T_11 F_318 ( void )
{
int V_50 ;
unsigned long V_390 ;
unsigned int V_48 ;
int V_70 = F_319 ( & V_206 , 0 ) ;
if ( V_70 != 0 )
goto V_24;
F_320 ( sizeof( struct V_391 ) > F_321 ( struct V_27 , V_122 ) ) ;
V_177 = F_52 ( V_214 , sizeof( * V_177 ) , V_53 ) ;
if ( ! V_177 )
goto F_317;
if ( V_392 >= ( 128 * 1024 ) )
V_390 = V_392 >> ( 21 - V_393 ) ;
else
V_390 = V_392 >> ( 23 - V_393 ) ;
V_48 = F_322 ( V_390 ) - 1 + V_393 ;
V_390 = ( 1UL << V_48 ) / sizeof( struct V_6 ) ;
V_48 = F_322 ( F_323 ( V_390 , ( unsigned long ) V_199 ) ) - 1 ;
for ( V_50 = 0 ; V_50 < V_214 ; V_50 ++ ) {
struct V_7 * V_8 = & V_177 [ V_50 ] . V_8 ;
V_8 -> V_10 = F_143 ( 1 * sizeof( * V_8 -> V_10 ) ) ;
if ( ! V_8 -> V_10 ) {
while ( V_50 -- > 0 )
F_145 ( V_177 [ V_50 ] . V_8 . V_10 ,
1 * sizeof( * V_8 -> V_10 ) ) ;
F_47 ( V_177 ) ;
goto F_317;
}
V_8 -> V_184 = V_48 ;
V_8 -> V_181 = 0 ;
V_8 -> V_12 = 0 ;
V_8 -> V_186 = V_187 ;
V_177 [ V_50 ] . V_178 = F_138 ;
}
F_324 ( & V_20 ) ;
F_316 () ;
F_325 ( & V_394 ) ;
F_326 ( & V_395 ) ;
F_327 () ;
V_24:
return V_70 ;
F_317:
F_317 ( L_9 ) ;
}
