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
static void F_6 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = F_2 ( V_2 ) ;
if ( ! ( V_14 -> V_3 & V_15 ) ) {
if ( ! F_7 ( V_16 , & F_2 ( V_2 ) -> V_17 ) ) {
V_2 -> V_18 = V_19 ;
V_2 -> V_20 ( V_2 ) ;
}
}
F_8 ( & V_2 -> V_21 ) ;
}
static void F_9 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = F_2 ( V_2 ) ;
if ( F_10 ( & V_2 -> V_22 ) )
F_11 ( V_16 , & V_14 -> V_17 ) ;
if ( ! F_12 ( V_16 , & V_14 -> V_17 ) )
F_13 ( & V_14 -> V_23 ) ;
}
static bool F_14 ( const struct V_24 * V_25 )
{
return F_15 ( V_25 ) . V_3 & V_26 ;
}
static bool F_16 ( struct V_1 * V_2 )
{
return F_2 ( V_2 ) -> V_27 . V_28 != NULL ;
}
static bool F_17 ( struct V_1 * V_2 )
{
return F_2 ( V_2 ) -> V_29 . V_28 != NULL ;
}
static void F_18 ( void * * V_28 , unsigned int V_30 , unsigned int V_31 )
{
unsigned int V_32 ;
for ( V_32 = 0 ; V_32 < V_31 ; V_32 ++ ) {
if ( V_28 [ V_32 ] != NULL ) {
if ( F_19 ( V_28 [ V_32 ] ) )
F_20 ( V_28 [ V_32 ] ) ;
else
F_21 ( ( unsigned long ) V_28 [ V_32 ] , V_30 ) ;
}
}
F_22 ( V_28 ) ;
}
static void * F_23 ( unsigned long V_30 )
{
void * V_33 ;
T_2 V_34 = V_35 | V_36 | V_37 |
V_38 | V_39 ;
V_33 = ( void * ) F_24 ( V_34 , V_30 ) ;
if ( V_33 != NULL )
return V_33 ;
V_33 = F_25 ( ( 1 << V_30 ) * V_40 ) ;
if ( V_33 != NULL )
return V_33 ;
V_34 &= ~ V_39 ;
return ( void * ) F_24 ( V_34 , V_30 ) ;
}
static void * * F_26 ( struct V_13 * V_14 ,
struct V_41 * V_42 , unsigned int V_30 )
{
unsigned int V_43 = V_42 -> V_44 ;
unsigned int V_32 ;
void * * V_28 , * V_45 ;
V_28 = F_27 ( V_43 , sizeof( void * ) , V_35 ) ;
if ( V_28 == NULL )
return NULL ;
for ( V_32 = 0 ; V_32 < V_43 ; V_32 ++ ) {
V_28 [ V_32 ] = V_45 = F_23 ( V_30 ) ;
if ( V_28 [ V_32 ] == NULL )
goto V_46;
}
return V_28 ;
V_46:
F_18 ( V_28 , V_30 , V_43 ) ;
return NULL ;
}
static int F_28 ( struct V_1 * V_2 , struct V_41 * V_42 ,
bool V_47 , bool V_29 )
{
struct V_13 * V_14 = F_2 ( V_2 ) ;
struct V_48 * V_49 ;
struct V_50 * V_51 ;
void * * V_28 = NULL ;
unsigned int V_30 = 0 ;
int V_52 ;
V_49 = V_29 ? & V_14 -> V_29 : & V_14 -> V_27 ;
V_51 = V_29 ? & V_2 -> V_53 : & V_2 -> V_22 ;
if ( ! V_47 ) {
if ( F_29 ( & V_14 -> V_54 ) )
return - V_55 ;
if ( F_29 ( & V_49 -> V_56 ) )
return - V_55 ;
}
if ( V_42 -> V_44 ) {
if ( V_49 -> V_28 != NULL )
return - V_55 ;
if ( ( int ) V_42 -> V_57 <= 0 )
return - V_58 ;
if ( ! F_30 ( V_42 -> V_57 , V_40 ) )
return - V_58 ;
if ( V_42 -> V_59 < V_60 )
return - V_58 ;
if ( ! F_30 ( V_42 -> V_59 , V_61 ) )
return - V_58 ;
V_49 -> V_62 = V_42 -> V_57 /
V_42 -> V_59 ;
if ( V_49 -> V_62 == 0 )
return - V_58 ;
if ( V_49 -> V_62 * V_42 -> V_44 !=
V_42 -> V_63 )
return - V_58 ;
V_30 = F_31 ( V_42 -> V_57 ) ;
V_28 = F_26 ( V_14 , V_42 , V_30 ) ;
if ( V_28 == NULL )
return - V_64 ;
} else {
if ( V_42 -> V_63 )
return - V_58 ;
}
V_52 = - V_55 ;
F_32 ( & V_14 -> V_65 ) ;
if ( V_47 || F_29 ( & V_14 -> V_54 ) == 0 ) {
V_52 = 0 ;
F_33 ( & V_51 -> V_66 ) ;
V_49 -> V_67 = V_42 -> V_63 - 1 ;
V_49 -> V_68 = 0 ;
V_49 -> V_69 = V_42 -> V_59 ;
V_49 -> V_70 = V_42 -> V_57 / V_40 ;
F_34 ( V_49 -> V_71 , V_42 -> V_44 ) ;
F_34 ( V_49 -> V_72 , V_30 ) ;
F_34 ( V_49 -> V_28 , V_28 ) ;
F_35 ( V_51 ) ;
F_36 ( & V_51 -> V_66 ) ;
F_37 ( F_29 ( & V_14 -> V_54 ) ) ;
}
F_38 ( & V_14 -> V_65 ) ;
if ( V_28 )
F_18 ( V_28 , V_30 , V_42 -> V_44 ) ;
return V_52 ;
}
static void F_39 ( struct V_73 * V_74 )
{
struct V_75 * V_75 = V_74 -> V_76 ;
struct V_77 * V_1 = V_75 -> V_78 ;
struct V_1 * V_2 = V_1 -> V_2 ;
if ( V_2 )
F_8 ( & F_2 ( V_2 ) -> V_54 ) ;
}
static void F_40 ( struct V_73 * V_74 )
{
struct V_75 * V_75 = V_74 -> V_76 ;
struct V_77 * V_1 = V_75 -> V_78 ;
struct V_1 * V_2 = V_1 -> V_2 ;
if ( V_2 )
F_41 ( & F_2 ( V_2 ) -> V_54 ) ;
}
static int F_42 ( struct V_75 * V_75 , struct V_77 * V_1 ,
struct V_73 * V_74 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_13 * V_14 = F_2 ( V_2 ) ;
struct V_48 * V_49 ;
unsigned long V_79 , V_80 , V_81 ;
unsigned int V_32 ;
int V_52 = - V_58 ;
if ( V_74 -> V_82 )
return - V_58 ;
F_32 ( & V_14 -> V_65 ) ;
V_81 = 0 ;
for ( V_49 = & V_14 -> V_27 ; V_49 <= & V_14 -> V_29 ; V_49 ++ ) {
if ( V_49 -> V_28 == NULL )
continue;
V_81 += V_49 -> V_71 * V_49 -> V_70 * V_40 ;
}
if ( V_81 == 0 )
goto V_83;
V_80 = V_74 -> V_84 - V_74 -> V_85 ;
if ( V_80 != V_81 )
goto V_83;
V_79 = V_74 -> V_85 ;
for ( V_49 = & V_14 -> V_27 ; V_49 <= & V_14 -> V_29 ; V_49 ++ ) {
if ( V_49 -> V_28 == NULL )
continue;
for ( V_32 = 0 ; V_32 < V_49 -> V_71 ; V_32 ++ ) {
struct V_86 * V_86 ;
void * V_87 = V_49 -> V_28 [ V_32 ] ;
unsigned int V_88 ;
for ( V_88 = 0 ; V_88 < V_49 -> V_70 ; V_88 ++ ) {
V_86 = F_43 ( V_87 ) ;
V_52 = F_44 ( V_74 , V_79 , V_86 ) ;
if ( V_52 < 0 )
goto V_83;
V_79 += V_40 ;
V_87 += V_40 ;
}
}
}
F_8 ( & V_14 -> V_54 ) ;
V_74 -> V_89 = & V_90 ;
V_52 = 0 ;
V_83:
F_38 ( & V_14 -> V_65 ) ;
return V_52 ;
}
static void F_45 ( const struct V_91 * V_92 )
{
#if V_93 == 1
struct V_86 * V_94 , * V_95 ;
V_94 = F_43 ( V_92 + V_40 ) ;
V_95 = F_43 ( ( void * ) V_92 + V_60 + V_92 -> V_96 - 1 ) ;
while ( V_94 <= V_95 ) {
F_46 ( V_94 ) ;
V_94 ++ ;
}
#endif
}
static enum V_97 F_47 ( const struct V_91 * V_92 )
{
F_48 () ;
F_46 ( F_43 ( V_92 ) ) ;
return V_92 -> V_98 ;
}
static void F_49 ( struct V_91 * V_92 ,
enum V_97 V_99 )
{
V_92 -> V_98 = V_99 ;
F_46 ( F_43 ( V_92 ) ) ;
F_50 () ;
}
static struct V_91 *
F_51 ( const struct V_48 * V_49 , unsigned int V_100 )
{
unsigned int V_101 , V_102 ;
V_101 = V_100 / V_49 -> V_62 ;
V_102 = V_100 % V_49 -> V_62 ;
return V_49 -> V_28 [ V_101 ] + ( V_102 * V_49 -> V_69 ) ;
}
static struct V_91 *
F_52 ( const struct V_48 * V_49 , unsigned int V_100 ,
enum V_97 V_99 )
{
struct V_91 * V_92 ;
V_92 = F_51 ( V_49 , V_100 ) ;
if ( F_47 ( V_92 ) != V_99 )
return NULL ;
return V_92 ;
}
static struct V_91 *
F_53 ( const struct V_48 * V_49 ,
enum V_97 V_99 )
{
return F_52 ( V_49 , V_49 -> V_68 , V_99 ) ;
}
static struct V_91 *
F_54 ( const struct V_48 * V_49 ,
enum V_97 V_99 )
{
unsigned int V_103 ;
V_103 = V_49 -> V_68 ? V_49 -> V_68 - 1 : V_49 -> V_67 ;
return F_52 ( V_49 , V_103 , V_99 ) ;
}
static void F_55 ( struct V_48 * V_49 )
{
V_49 -> V_68 = V_49 -> V_68 != V_49 -> V_67 ? V_49 -> V_68 + 1 : 0 ;
}
static void F_56 ( struct V_48 * V_49 )
{
unsigned int V_68 = V_49 -> V_68 , V_100 = V_68 ;
const struct V_91 * V_92 ;
do {
V_92 = F_51 ( V_49 , V_100 ) ;
if ( V_92 -> V_98 == V_104 )
break;
if ( V_92 -> V_98 != V_105 )
break;
F_55 ( V_49 ) ;
} while ( V_49 -> V_68 != V_68 );
}
static bool F_57 ( struct V_13 * V_14 )
{
struct V_48 * V_49 = & V_14 -> V_27 ;
struct V_91 * V_92 ;
unsigned int V_106 ;
V_92 = F_53 ( V_49 , V_104 ) ;
if ( V_92 == NULL )
return false ;
V_106 = V_49 -> V_68 + V_49 -> V_67 / 2 ;
if ( V_106 > V_49 -> V_67 )
V_106 -= V_49 -> V_67 ;
V_92 = F_51 ( V_49 , V_106 ) ;
return V_92 -> V_98 == V_104 ;
}
static unsigned int F_58 ( struct V_75 * V_75 , struct V_77 * V_1 ,
T_3 * V_23 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_13 * V_14 = F_2 ( V_2 ) ;
unsigned int V_12 ;
int V_52 ;
if ( V_14 -> V_27 . V_28 != NULL ) {
while ( V_14 -> V_107 != NULL && F_57 ( V_14 ) ) {
V_52 = F_59 ( V_2 ) ;
if ( V_52 < 0 ) {
V_2 -> V_18 = V_52 ;
V_2 -> V_20 ( V_2 ) ;
break;
}
}
F_9 ( V_2 ) ;
}
V_12 = F_60 ( V_75 , V_1 , V_23 ) ;
F_33 ( & V_2 -> V_22 . V_66 ) ;
if ( V_14 -> V_27 . V_28 ) {
F_56 ( & V_14 -> V_27 ) ;
if ( ! F_54 ( & V_14 -> V_27 , V_104 ) )
V_12 |= V_108 | V_109 ;
}
F_36 ( & V_2 -> V_22 . V_66 ) ;
F_33 ( & V_2 -> V_53 . V_66 ) ;
if ( V_14 -> V_29 . V_28 ) {
if ( F_53 ( & V_14 -> V_29 , V_104 ) )
V_12 |= V_110 | V_111 ;
}
F_36 ( & V_2 -> V_53 . V_66 ) ;
return V_12 ;
}
static struct V_91 * F_61 ( struct V_24 * V_25 )
{
return (struct V_91 * ) ( V_25 -> V_68 - V_60 ) ;
}
static void F_62 ( struct V_24 * V_25 , struct V_1 * V_2 ,
struct V_48 * V_49 ,
struct V_91 * V_92 )
{
unsigned int V_80 ;
void * V_112 ;
V_80 = V_49 -> V_69 - V_60 ;
V_112 = ( void * ) V_92 + V_60 ;
V_25 -> V_68 = V_112 ;
V_25 -> V_112 = V_112 ;
F_63 ( V_25 ) ;
V_25 -> V_113 = V_25 -> V_114 + V_80 ;
V_25 -> V_31 = 0 ;
V_25 -> V_115 = V_116 ;
F_15 ( V_25 ) . V_3 |= V_26 ;
F_15 ( V_25 ) . V_2 = V_2 ;
}
static int F_64 ( struct V_1 * V_2 , struct V_117 * V_118 ,
T_1 V_119 , T_1 V_120 ,
struct V_121 * V_122 )
{
struct V_13 * V_14 = F_2 ( V_2 ) ;
struct V_48 * V_49 ;
struct V_91 * V_92 ;
struct V_24 * V_25 ;
unsigned int V_123 ;
bool V_124 = true ;
int V_52 = 0 , V_31 = 0 ;
if ( F_65 ( & V_2 -> V_125 -> V_75 -> V_126 ) > 2 ||
F_29 ( & V_14 -> V_54 ) > 1 )
V_124 = false ;
F_32 ( & V_14 -> V_65 ) ;
V_49 = & V_14 -> V_29 ;
V_123 = V_49 -> V_69 - V_60 ;
do {
V_92 = F_53 ( V_49 , V_127 ) ;
if ( V_92 == NULL ) {
if ( ! ( V_118 -> V_128 & V_129 ) &&
F_29 ( & V_14 -> V_29 . V_56 ) )
F_66 () ;
continue;
}
if ( V_92 -> V_96 > V_123 ) {
V_52 = - V_58 ;
goto V_83;
}
F_45 ( V_92 ) ;
if ( F_67 ( V_119 == 0 && V_120 == 0 && V_124 ) ) {
V_25 = F_68 ( V_35 ) ;
if ( V_25 == NULL ) {
V_52 = - V_19 ;
goto V_83;
}
F_69 ( V_2 ) ;
F_62 ( V_25 , V_2 , V_49 , V_92 ) ;
F_15 ( V_25 ) . V_3 |= V_130 ;
F_70 ( V_25 , V_92 -> V_96 ) ;
F_49 ( V_92 , V_131 ) ;
F_8 ( & V_49 -> V_56 ) ;
} else {
V_25 = F_71 ( V_92 -> V_96 , V_35 ) ;
if ( V_25 == NULL ) {
V_52 = - V_19 ;
goto V_83;
}
F_70 ( V_25 , V_92 -> V_96 ) ;
memcpy ( V_25 -> V_112 , ( void * ) V_92 + V_60 , V_92 -> V_96 ) ;
F_49 ( V_92 , V_104 ) ;
}
F_55 ( V_49 ) ;
F_15 ( V_25 ) . V_9 = V_14 -> V_9 ;
F_15 ( V_25 ) . V_120 = V_120 ;
F_15 ( V_25 ) . V_132 = V_122 -> V_133 -> V_132 ;
V_52 = F_72 ( V_2 , V_25 ) ;
if ( V_52 ) {
F_73 ( V_25 ) ;
goto V_83;
}
if ( F_74 ( V_120 ) ) {
F_8 ( & V_25 -> V_134 ) ;
F_75 ( V_2 , V_25 , V_119 , V_120 ,
V_35 ) ;
}
V_52 = F_76 ( V_2 , V_25 , V_119 ,
V_118 -> V_128 & V_129 ) ;
if ( V_52 < 0 )
goto V_83;
V_31 += V_52 ;
} while ( V_92 != NULL ||
( ! ( V_118 -> V_128 & V_129 ) &&
F_29 ( & V_14 -> V_29 . V_56 ) ) );
if ( V_31 > 0 )
V_52 = V_31 ;
V_83:
F_38 ( & V_14 -> V_65 ) ;
return V_52 ;
}
static void F_77 ( struct V_1 * V_2 , struct V_24 * V_25 )
{
struct V_91 * V_92 ;
V_92 = F_61 ( V_25 ) ;
V_92 -> V_96 = V_25 -> V_31 ;
V_92 -> V_135 = F_15 ( V_25 ) . V_120 ;
V_92 -> V_136 = F_15 ( V_25 ) . V_132 . V_137 ;
V_92 -> V_138 = F_78 ( F_79 ( V_2 ) , F_15 ( V_25 ) . V_132 . V_139 ) ;
V_92 -> V_140 = F_80 ( F_79 ( V_2 ) , F_15 ( V_25 ) . V_132 . V_141 ) ;
F_45 ( V_92 ) ;
F_49 ( V_92 , V_127 ) ;
F_15 ( V_25 ) . V_3 |= V_142 ;
F_73 ( V_25 ) ;
}
static void F_81 ( struct V_1 * V_2 , struct V_24 * V_25 )
{
struct V_13 * V_14 = F_2 ( V_2 ) ;
struct V_48 * V_49 = & V_14 -> V_27 ;
struct V_91 * V_92 ;
F_33 ( & V_2 -> V_22 . V_66 ) ;
V_92 = F_53 ( V_49 , V_104 ) ;
if ( V_92 == NULL ) {
F_36 ( & V_2 -> V_22 . V_66 ) ;
F_73 ( V_25 ) ;
F_6 ( V_2 ) ;
return;
}
F_55 ( V_49 ) ;
F_82 ( & V_2 -> V_22 , V_25 ) ;
F_36 ( & V_2 -> V_22 . V_66 ) ;
V_92 -> V_96 = V_25 -> V_31 ;
V_92 -> V_135 = F_15 ( V_25 ) . V_120 ;
V_92 -> V_136 = F_15 ( V_25 ) . V_132 . V_137 ;
V_92 -> V_138 = F_78 ( F_79 ( V_2 ) , F_15 ( V_25 ) . V_132 . V_139 ) ;
V_92 -> V_140 = F_80 ( F_79 ( V_2 ) , F_15 ( V_25 ) . V_132 . V_141 ) ;
F_49 ( V_92 , V_143 ) ;
}
static void F_83 ( struct V_144 * V_107 )
{
F_73 ( V_107 -> V_25 ) ;
F_22 ( V_107 ) ;
}
static void F_84 ( struct V_144 * V_107 )
{
F_85 ( V_107 -> V_25 ) ;
F_22 ( V_107 ) ;
}
static void V_116 ( struct V_24 * V_25 )
{
#ifdef F_86
struct V_91 * V_92 ;
struct V_48 * V_49 ;
struct V_1 * V_2 ;
if ( F_14 ( V_25 ) ) {
V_92 = F_61 ( V_25 ) ;
V_2 = F_15 ( V_25 ) . V_2 ;
if ( F_15 ( V_25 ) . V_3 & V_130 ) {
F_49 ( V_92 , V_104 ) ;
V_49 = & F_2 ( V_2 ) -> V_29 ;
} else {
if ( ! ( F_15 ( V_25 ) . V_3 & V_142 ) ) {
V_92 -> V_96 = 0 ;
F_49 ( V_92 , V_127 ) ;
}
V_49 = & F_2 ( V_2 ) -> V_27 ;
}
F_37 ( F_29 ( & V_49 -> V_56 ) == 0 ) ;
F_41 ( & V_49 -> V_56 ) ;
F_87 ( V_2 ) ;
V_25 -> V_68 = NULL ;
}
#endif
if ( V_25 -> V_2 != NULL )
F_88 ( V_25 ) ;
}
static void F_89 ( struct V_24 * V_25 , struct V_1 * V_2 )
{
F_37 ( V_25 -> V_2 != NULL ) ;
V_25 -> V_2 = V_2 ;
V_25 -> V_115 = V_116 ;
F_90 ( V_25 -> V_145 , & V_2 -> V_146 ) ;
F_91 ( V_2 , V_25 -> V_145 ) ;
}
static void F_92 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = F_2 ( V_2 ) ;
if ( V_14 -> V_107 ) {
if ( V_14 -> V_107 -> V_147 )
V_14 -> V_107 -> V_147 ( V_14 -> V_107 ) ;
F_93 ( V_14 -> V_107 -> V_148 ) ;
F_83 ( V_14 -> V_107 ) ;
}
F_94 ( & V_2 -> V_22 ) ;
#ifdef F_86
if ( 1 ) {
struct V_41 V_42 ;
memset ( & V_42 , 0 , sizeof( V_42 ) ) ;
if ( V_14 -> V_27 . V_28 )
F_28 ( V_2 , & V_42 , true , false ) ;
memset ( & V_42 , 0 , sizeof( V_42 ) ) ;
if ( V_14 -> V_29 . V_28 )
F_28 ( V_2 , & V_42 , true , true ) ;
}
#endif
if ( ! F_95 ( V_2 , V_149 ) ) {
F_96 ( V_150 L_1 , V_2 ) ;
return;
}
F_37 ( F_29 ( & V_2 -> V_146 ) ) ;
F_37 ( F_29 ( & V_2 -> V_151 ) ) ;
F_37 ( F_2 ( V_2 ) -> V_152 ) ;
}
void F_97 ( void )
__acquires( T_4 )
{
F_98 () ;
F_99 ( & T_4 ) ;
if ( F_29 ( & V_153 ) ) {
F_100 ( V_23 , V_154 ) ;
F_101 ( & V_155 , & V_23 ) ;
for (; ; ) {
F_102 ( V_156 ) ;
if ( F_29 ( & V_153 ) == 0 )
break;
F_103 ( & T_4 ) ;
F_66 () ;
F_99 ( & T_4 ) ;
}
F_104 ( V_157 ) ;
F_105 ( & V_155 , & V_23 ) ;
}
}
void F_106 ( void )
__releases( T_4 )
{
F_103 ( & T_4 ) ;
F_107 ( & V_155 ) ;
}
static inline void
F_108 ( void )
{
F_109 ( & T_4 ) ;
F_8 ( & V_153 ) ;
F_110 ( & T_4 ) ;
}
static inline void
F_111 ( void )
{
if ( F_112 ( & V_153 ) )
F_107 ( & V_155 ) ;
}
static struct V_1 * F_113 ( struct V_158 * V_158 , int V_159 , T_1 V_9 )
{
struct V_7 * V_8 = & V_160 [ V_159 ] . V_8 ;
struct V_6 * V_68 ;
struct V_1 * V_2 ;
F_109 ( & T_4 ) ;
V_68 = F_4 ( V_8 , V_9 ) ;
F_114 (sk, head) {
if ( F_115 ( F_116 ( V_2 ) , V_158 ) && ( F_2 ( V_2 ) -> V_9 == V_9 ) ) {
F_69 ( V_2 ) ;
goto V_161;
}
}
V_2 = NULL ;
V_161:
F_110 ( & T_4 ) ;
return V_2 ;
}
static struct V_6 * F_117 ( T_5 V_80 )
{
if ( V_80 <= V_40 )
return F_118 ( V_80 , V_162 ) ;
else
return (struct V_6 * )
F_24 ( V_162 | V_37 ,
F_31 ( V_80 ) ) ;
}
static void F_119 ( struct V_6 * V_10 , T_5 V_80 )
{
if ( V_80 <= V_40 )
F_22 ( V_10 ) ;
else
F_21 ( ( unsigned long ) V_10 , F_31 ( V_80 ) ) ;
}
static int F_120 ( struct V_7 * V_8 , int V_163 )
{
unsigned int V_164 , V_12 , V_165 ;
T_5 V_166 , V_80 ;
struct V_6 * V_167 , * V_10 ;
int V_32 ;
V_164 = V_12 = V_8 -> V_12 ;
V_166 = V_80 = ( V_12 + 1 ) * sizeof( * V_10 ) ;
V_165 = V_8 -> V_165 ;
if ( V_163 ) {
if ( ++ V_165 > V_8 -> V_168 )
return 0 ;
V_12 = V_12 * 2 + 1 ;
V_80 *= 2 ;
}
V_10 = F_117 ( V_80 ) ;
if ( ! V_10 )
return 0 ;
V_167 = V_8 -> V_10 ;
V_8 -> V_10 = V_10 ;
V_8 -> V_12 = V_12 ;
V_8 -> V_165 = V_165 ;
F_121 ( & V_8 -> V_11 , sizeof( V_8 -> V_11 ) ) ;
for ( V_32 = 0 ; V_32 <= V_164 ; V_32 ++ ) {
struct V_1 * V_2 ;
struct V_169 * V_170 ;
F_122 (sk, tmp, &otable[i])
F_123 ( V_2 , F_4 ( V_8 , F_2 ( V_2 ) -> V_9 ) ) ;
}
F_119 ( V_167 , V_166 ) ;
V_8 -> V_171 = V_172 + 10 * 60 * V_173 ;
return 1 ;
}
static inline int F_124 ( struct V_7 * V_8 , int V_31 )
{
int V_174 = V_8 -> V_175 >> V_8 -> V_165 ;
if ( F_74 ( V_174 > 1 ) && F_120 ( V_8 , 1 ) )
return 1 ;
if ( F_74 ( V_31 > V_174 ) && F_125 ( V_172 , V_8 -> V_171 ) ) {
F_120 ( V_8 , 0 ) ;
return 1 ;
}
return 0 ;
}
static void
F_126 ( struct V_1 * V_2 )
{
struct V_176 * V_177 = & V_160 [ V_2 -> V_178 ] ;
unsigned long V_12 ;
unsigned int V_32 ;
struct V_179 * V_179 ;
V_179 = F_127 ( V_177 -> V_179 ) ;
if ( ! V_179 )
return;
for ( V_32 = 0 ; V_32 < F_128 ( V_177 -> V_152 ) ; V_32 ++ ) {
V_12 = 0 ;
F_129 (sk, &tbl->mc_list) {
if ( V_32 < F_128 ( F_2 ( V_2 ) -> V_180 ) )
V_12 |= F_2 ( V_2 ) -> V_152 [ V_32 ] ;
}
V_179 -> V_181 [ V_32 ] = V_12 ;
}
}
static int F_130 ( struct V_1 * V_2 , struct V_158 * V_158 , T_1 V_9 )
{
struct V_7 * V_8 = & V_160 [ V_2 -> V_178 ] . V_8 ;
struct V_6 * V_68 ;
int V_52 = - V_182 ;
struct V_1 * V_183 ;
int V_31 ;
F_97 () ;
V_68 = F_4 ( V_8 , V_9 ) ;
V_31 = 0 ;
F_114 (osk, head) {
if ( F_115 ( F_116 ( V_183 ) , V_158 ) && ( F_2 ( V_183 ) -> V_9 == V_9 ) )
break;
V_31 ++ ;
}
if ( V_183 )
goto V_52;
V_52 = - V_55 ;
if ( F_2 ( V_2 ) -> V_9 )
goto V_52;
V_52 = - V_64 ;
if ( V_184 > 32 && F_74 ( V_8 -> V_175 >= V_185 ) )
goto V_52;
if ( V_31 && F_124 ( V_8 , V_31 ) )
V_68 = F_4 ( V_8 , V_9 ) ;
V_8 -> V_175 ++ ;
F_2 ( V_2 ) -> V_9 = V_9 ;
F_131 ( V_2 , V_68 ) ;
V_52 = 0 ;
V_52:
F_106 () ;
return V_52 ;
}
static void F_132 ( struct V_1 * V_2 )
{
F_97 () ;
if ( F_133 ( V_2 ) )
V_160 [ V_2 -> V_178 ] . V_8 . V_175 -- ;
if ( F_2 ( V_2 ) -> V_186 )
F_134 ( V_2 ) ;
F_106 () ;
}
static int F_135 ( struct V_158 * V_158 , struct V_77 * V_1 ,
struct V_187 * V_188 , int V_159 )
{
struct V_1 * V_2 ;
struct V_13 * V_14 ;
V_1 -> V_189 = & V_190 ;
V_2 = F_136 ( V_158 , V_191 , V_35 , & V_192 ) ;
if ( ! V_2 )
return - V_64 ;
F_137 ( V_1 , V_2 ) ;
V_14 = F_2 ( V_2 ) ;
if ( V_188 ) {
V_14 -> V_188 = V_188 ;
} else {
V_14 -> V_188 = & V_14 -> V_193 ;
F_138 ( V_14 -> V_188 ) ;
}
F_139 ( & V_14 -> V_23 ) ;
#ifdef F_86
F_138 ( & V_14 -> V_65 ) ;
#endif
V_2 -> V_194 = F_92 ;
V_2 -> V_178 = V_159 ;
return 0 ;
}
static int F_140 ( struct V_158 * V_158 , struct V_77 * V_1 , int V_159 ,
int V_195 )
{
struct V_148 * V_148 = NULL ;
struct V_187 * V_188 ;
struct V_13 * V_14 ;
void (* F_141)( int V_5 );
int V_52 = 0 ;
V_1 -> V_17 = V_196 ;
if ( V_1 -> type != V_197 && V_1 -> type != V_198 )
return - V_199 ;
if ( V_159 < 0 || V_159 >= V_200 )
return - V_201 ;
F_108 () ;
#ifdef F_142
if ( ! V_160 [ V_159 ] . V_202 ) {
F_111 () ;
F_143 ( L_2 , V_191 , V_159 ) ;
F_108 () ;
}
#endif
if ( V_160 [ V_159 ] . V_202 &&
F_144 ( V_160 [ V_159 ] . V_148 ) )
V_148 = V_160 [ V_159 ] . V_148 ;
else
V_52 = - V_201 ;
V_188 = V_160 [ V_159 ] . V_188 ;
F_141 = V_160 [ V_159 ] . F_141 ;
F_111 () ;
if ( V_52 < 0 )
goto V_83;
V_52 = F_135 ( V_158 , V_1 , V_188 , V_159 ) ;
if ( V_52 < 0 )
goto V_203;
F_145 () ;
F_146 ( V_158 , & V_192 , 1 ) ;
F_147 () ;
V_14 = F_2 ( V_1 -> V_2 ) ;
V_14 -> V_148 = V_148 ;
V_14 -> V_204 = F_141 ;
V_83:
return V_52 ;
V_203:
F_93 ( V_148 ) ;
goto V_83;
}
static int F_148 ( struct V_77 * V_1 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_13 * V_14 ;
if ( ! V_2 )
return 0 ;
F_132 ( V_2 ) ;
F_149 ( V_2 ) ;
V_14 = F_2 ( V_2 ) ;
V_1 -> V_2 = NULL ;
F_150 ( & V_14 -> V_23 ) ;
F_94 ( & V_2 -> V_53 ) ;
if ( V_14 -> V_9 ) {
struct V_205 V_106 = {
. V_158 = F_116 ( V_2 ) ,
. V_159 = V_2 -> V_178 ,
. V_9 = V_14 -> V_9 ,
} ;
F_151 ( & V_206 ,
V_207 , & V_106 ) ;
}
F_93 ( V_14 -> V_148 ) ;
F_97 () ;
if ( F_1 ( V_2 ) ) {
F_152 ( V_160 [ V_2 -> V_178 ] . V_202 == 0 ) ;
if ( -- V_160 [ V_2 -> V_178 ] . V_202 == 0 ) {
struct V_179 * V_208 ;
V_208 = F_127 ( V_160 [ V_2 -> V_178 ] . V_179 ) ;
F_153 ( V_160 [ V_2 -> V_178 ] . V_179 , NULL ) ;
F_154 ( V_208 , V_209 ) ;
V_160 [ V_2 -> V_178 ] . V_148 = NULL ;
V_160 [ V_2 -> V_178 ] . F_141 = NULL ;
V_160 [ V_2 -> V_178 ] . V_3 = 0 ;
V_160 [ V_2 -> V_178 ] . V_202 = 0 ;
}
} else if ( V_14 -> V_186 ) {
F_126 ( V_2 ) ;
}
F_106 () ;
F_22 ( V_14 -> V_152 ) ;
V_14 -> V_152 = NULL ;
F_145 () ;
F_146 ( F_116 ( V_2 ) , & V_192 , - 1 ) ;
F_147 () ;
F_87 ( V_2 ) ;
return 0 ;
}
static int F_155 ( struct V_77 * V_1 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_158 * V_158 = F_116 ( V_2 ) ;
struct V_7 * V_8 = & V_160 [ V_2 -> V_178 ] . V_8 ;
struct V_6 * V_68 ;
struct V_1 * V_183 ;
T_6 V_9 = F_156 ( V_154 ) ;
int V_52 ;
static T_6 V_210 = - 4097 ;
V_211:
F_157 () ;
F_97 () ;
V_68 = F_4 ( V_8 , V_9 ) ;
F_114 (osk, head) {
if ( ! F_115 ( F_116 ( V_183 ) , V_158 ) )
continue;
if ( F_2 ( V_183 ) -> V_9 == V_9 ) {
V_9 = V_210 -- ;
if ( V_210 > - 4097 )
V_210 = - 4097 ;
F_106 () ;
goto V_211;
}
}
F_106 () ;
V_52 = F_130 ( V_2 , V_158 , V_9 ) ;
if ( V_52 == - V_182 )
goto V_211;
if ( V_52 == - V_55 )
V_52 = 0 ;
return V_52 ;
}
static inline int F_158 ( const struct V_77 * V_1 , unsigned int V_212 )
{
return ( V_160 [ V_1 -> V_2 -> V_178 ] . V_3 & V_212 ) ||
F_159 ( F_116 ( V_1 -> V_2 ) -> V_213 , V_214 ) ;
}
static void
F_160 ( struct V_1 * V_2 , unsigned int V_186 )
{
struct V_13 * V_14 = F_2 ( V_2 ) ;
if ( V_14 -> V_186 && ! V_186 )
F_134 ( V_2 ) ;
else if ( ! V_14 -> V_186 && V_186 )
F_161 ( V_2 , & V_160 [ V_2 -> V_178 ] . V_215 ) ;
V_14 -> V_186 = V_186 ;
}
static int F_162 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = F_2 ( V_2 ) ;
unsigned int V_152 ;
unsigned long * V_216 ;
int V_52 = 0 ;
F_97 () ;
V_152 = V_160 [ V_2 -> V_178 ] . V_152 ;
if ( ! V_160 [ V_2 -> V_178 ] . V_202 ) {
V_52 = - V_217 ;
goto V_218;
}
if ( V_14 -> V_180 >= V_152 )
goto V_218;
V_216 = F_163 ( V_14 -> V_152 , F_164 ( V_152 ) , V_162 ) ;
if ( V_216 == NULL ) {
V_52 = - V_64 ;
goto V_218;
}
memset ( ( char * ) V_216 + F_164 ( V_14 -> V_180 ) , 0 ,
F_164 ( V_152 ) - F_164 ( V_14 -> V_180 ) ) ;
V_14 -> V_152 = V_216 ;
V_14 -> V_180 = V_152 ;
V_218:
F_106 () ;
return V_52 ;
}
static int V_204 ( struct V_77 * V_1 , struct V_219 * V_220 ,
int V_221 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_158 * V_158 = F_116 ( V_2 ) ;
struct V_13 * V_14 = F_2 ( V_2 ) ;
struct V_222 * V_223 = (struct V_222 * ) V_220 ;
int V_52 ;
if ( V_221 < sizeof( struct V_222 ) )
return - V_58 ;
if ( V_223 -> V_224 != V_225 )
return - V_58 ;
if ( V_223 -> V_226 ) {
if ( ! F_158 ( V_1 , V_227 ) )
return - V_228 ;
V_52 = F_162 ( V_2 ) ;
if ( V_52 )
return V_52 ;
}
if ( V_14 -> V_9 ) {
if ( V_223 -> V_229 != V_14 -> V_9 )
return - V_58 ;
} else {
V_52 = V_223 -> V_229 ?
F_130 ( V_2 , V_158 , V_223 -> V_229 ) :
F_155 ( V_1 ) ;
if ( V_52 )
return V_52 ;
}
if ( ! V_223 -> V_226 && ( V_14 -> V_152 == NULL || ! ( T_1 ) V_14 -> V_152 [ 0 ] ) )
return 0 ;
F_97 () ;
F_160 ( V_2 , V_14 -> V_186 +
F_165 ( V_223 -> V_226 ) -
F_165 ( V_14 -> V_152 [ 0 ] ) ) ;
V_14 -> V_152 [ 0 ] = ( V_14 -> V_152 [ 0 ] & ~ 0xffffffffUL ) | V_223 -> V_226 ;
F_126 ( V_2 ) ;
F_106 () ;
if ( V_14 -> V_204 && V_14 -> V_152 [ 0 ] ) {
int V_32 ;
for ( V_32 = 0 ; V_32 < V_14 -> V_180 ; V_32 ++ ) {
if ( F_12 ( V_32 , V_14 -> V_152 ) )
V_14 -> V_204 ( V_32 ) ;
}
}
return 0 ;
}
static int F_166 ( struct V_77 * V_1 , struct V_219 * V_220 ,
int V_230 , int V_3 )
{
int V_52 = 0 ;
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_13 * V_14 = F_2 ( V_2 ) ;
struct V_222 * V_223 = (struct V_222 * ) V_220 ;
if ( V_230 < sizeof( V_220 -> V_231 ) )
return - V_58 ;
if ( V_220 -> V_231 == V_232 ) {
V_2 -> V_233 = V_234 ;
V_14 -> V_119 = 0 ;
V_14 -> V_120 = 0 ;
return 0 ;
}
if ( V_220 -> V_231 != V_225 )
return - V_58 ;
if ( V_223 -> V_226 && ! F_158 ( V_1 , V_235 ) )
return - V_228 ;
if ( ! V_14 -> V_9 )
V_52 = F_155 ( V_1 ) ;
if ( V_52 == 0 ) {
V_2 -> V_233 = V_236 ;
V_14 -> V_119 = V_223 -> V_229 ;
V_14 -> V_120 = F_167 ( V_223 -> V_226 ) ;
}
return V_52 ;
}
static int F_168 ( struct V_77 * V_1 , struct V_219 * V_220 ,
int * V_221 , int V_237 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_13 * V_14 = F_2 ( V_2 ) ;
F_169 ( struct V_222 * , V_223 , V_220 ) ;
V_223 -> V_224 = V_225 ;
V_223 -> V_238 = 0 ;
* V_221 = sizeof( * V_223 ) ;
if ( V_237 ) {
V_223 -> V_229 = V_14 -> V_119 ;
V_223 -> V_226 = F_3 ( V_14 -> V_120 ) ;
} else {
V_223 -> V_229 = V_14 -> V_9 ;
V_223 -> V_226 = V_14 -> V_152 ? V_14 -> V_152 [ 0 ] : 0 ;
}
return 0 ;
}
static struct V_1 * F_170 ( struct V_1 * V_239 , T_1 V_9 )
{
struct V_1 * V_1 ;
struct V_13 * V_14 ;
V_1 = F_113 ( F_116 ( V_239 ) , V_239 -> V_178 , V_9 ) ;
if ( ! V_1 )
return F_171 ( - V_240 ) ;
V_14 = F_2 ( V_1 ) ;
if ( V_1 -> V_233 == V_236 &&
V_14 -> V_119 != F_2 ( V_239 ) -> V_9 ) {
F_87 ( V_1 ) ;
return F_171 ( - V_240 ) ;
}
return V_1 ;
}
struct V_1 * F_172 ( struct V_75 * V_241 )
{
struct V_242 * V_242 = F_173 ( V_241 ) ;
struct V_1 * V_1 ;
if ( ! F_174 ( V_242 -> V_243 ) )
return F_171 ( - V_244 ) ;
V_1 = F_175 ( V_242 ) -> V_2 ;
if ( V_1 -> V_245 != V_225 )
return F_171 ( - V_58 ) ;
F_69 ( V_1 ) ;
return V_1 ;
}
int F_176 ( struct V_1 * V_2 , struct V_24 * V_25 ,
long * V_246 , struct V_1 * V_239 )
{
struct V_13 * V_14 ;
V_14 = F_2 ( V_2 ) ;
if ( ( F_29 ( & V_2 -> V_146 ) > V_2 -> V_247 ||
F_12 ( V_16 , & V_14 -> V_17 ) ) &&
! F_14 ( V_25 ) ) {
F_100 ( V_23 , V_154 ) ;
if ( ! * V_246 ) {
if ( ! V_239 || F_1 ( V_239 ) )
F_6 ( V_2 ) ;
F_87 ( V_2 ) ;
F_73 ( V_25 ) ;
return - V_248 ;
}
F_104 ( V_249 ) ;
F_177 ( & V_14 -> V_23 , & V_23 ) ;
if ( ( F_29 ( & V_2 -> V_146 ) > V_2 -> V_247 ||
F_12 ( V_16 , & V_14 -> V_17 ) ) &&
! F_95 ( V_2 , V_149 ) )
* V_246 = F_178 ( * V_246 ) ;
F_104 ( V_157 ) ;
F_105 ( & V_14 -> V_23 , & V_23 ) ;
F_87 ( V_2 ) ;
if ( F_179 ( V_154 ) ) {
F_73 ( V_25 ) ;
return F_180 ( * V_246 ) ;
}
return 1 ;
}
F_89 ( V_25 , V_2 ) ;
return 0 ;
}
static int F_181 ( struct V_1 * V_2 , struct V_24 * V_25 )
{
int V_31 = V_25 -> V_31 ;
#ifdef F_86
if ( F_14 ( V_25 ) )
F_77 ( V_2 , V_25 ) ;
else if ( F_16 ( V_2 ) )
F_81 ( V_2 , V_25 ) ;
else
#endif
F_182 ( & V_2 -> V_22 , V_25 ) ;
V_2 -> V_250 ( V_2 , V_31 ) ;
return V_31 ;
}
int F_183 ( struct V_1 * V_2 , struct V_24 * V_25 )
{
int V_31 = F_181 ( V_2 , V_25 ) ;
F_87 ( V_2 ) ;
return V_31 ;
}
void F_184 ( struct V_1 * V_2 , struct V_24 * V_25 )
{
F_73 ( V_25 ) ;
F_87 ( V_2 ) ;
}
static struct V_24 * F_185 ( struct V_24 * V_25 , T_2 V_251 )
{
int V_252 ;
F_37 ( V_25 -> V_2 != NULL ) ;
if ( F_14 ( V_25 ) )
return V_25 ;
V_252 = V_25 -> V_113 - V_25 -> V_114 ;
if ( V_252 * 2 < V_25 -> V_145 )
return V_25 ;
if ( F_186 ( V_25 ) ) {
struct V_24 * V_253 = F_187 ( V_25 , V_251 ) ;
if ( ! V_253 )
return V_25 ;
F_85 ( V_25 ) ;
V_25 = V_253 ;
}
if ( ! F_188 ( V_25 , 0 , - V_252 , V_251 ) )
V_25 -> V_145 -= V_252 ;
return V_25 ;
}
static int F_189 ( struct V_1 * V_2 , struct V_24 * V_25 ,
struct V_1 * V_239 )
{
int V_254 ;
struct V_13 * V_14 = F_2 ( V_2 ) ;
V_254 = - V_240 ;
if ( V_14 -> V_255 != NULL ) {
V_254 = V_25 -> V_31 ;
F_89 ( V_25 , V_2 ) ;
F_15 ( V_25 ) . V_2 = V_239 ;
V_14 -> V_255 ( V_25 ) ;
F_85 ( V_25 ) ;
} else {
F_73 ( V_25 ) ;
}
F_87 ( V_2 ) ;
return V_254 ;
}
int F_76 ( struct V_1 * V_239 , struct V_24 * V_25 ,
T_1 V_9 , int V_256 )
{
struct V_1 * V_2 ;
int V_52 ;
long V_246 ;
V_25 = F_185 ( V_25 , F_190 () ) ;
V_246 = F_191 ( V_239 , V_256 ) ;
V_211:
V_2 = F_170 ( V_239 , V_9 ) ;
if ( F_192 ( V_2 ) ) {
F_73 ( V_25 ) ;
return F_193 ( V_2 ) ;
}
if ( F_1 ( V_2 ) )
return F_189 ( V_2 , V_25 , V_239 ) ;
if ( F_194 ( V_2 , V_25 ) ) {
V_52 = V_25 -> V_31 ;
F_73 ( V_25 ) ;
F_87 ( V_2 ) ;
return V_52 ;
}
V_52 = F_176 ( V_2 , V_25 , & V_246 , V_239 ) ;
if ( V_52 == 1 )
goto V_211;
if ( V_52 )
return V_52 ;
return F_183 ( V_2 , V_25 ) ;
}
struct V_24 * F_195 ( struct V_1 * V_239 , unsigned int V_80 ,
T_1 V_119 , T_2 V_257 )
{
#ifdef F_86
struct V_1 * V_2 = NULL ;
struct V_24 * V_25 ;
struct V_48 * V_49 ;
struct V_91 * V_92 ;
unsigned int V_123 ;
V_2 = F_170 ( V_239 , V_119 ) ;
if ( F_192 ( V_2 ) )
goto V_83;
V_49 = & F_2 ( V_2 ) -> V_27 ;
if ( V_49 -> V_28 == NULL )
goto V_258;
V_25 = F_68 ( V_257 ) ;
if ( V_25 == NULL )
goto V_46;
F_33 ( & V_2 -> V_22 . V_66 ) ;
if ( V_49 -> V_28 == NULL )
goto V_259;
V_123 = V_49 -> V_69 - V_60 ;
if ( V_123 < V_80 )
goto V_259;
F_56 ( V_49 ) ;
V_92 = F_53 ( V_49 , V_104 ) ;
if ( V_92 == NULL )
goto V_260;
F_62 ( V_25 , V_2 , V_49 , V_92 ) ;
F_49 ( V_92 , V_131 ) ;
F_8 ( & V_49 -> V_56 ) ;
F_55 ( V_49 ) ;
F_36 ( & V_2 -> V_22 . V_66 ) ;
return V_25 ;
V_260:
F_73 ( V_25 ) ;
F_36 ( & V_2 -> V_22 . V_66 ) ;
F_6 ( V_2 ) ;
V_46:
F_87 ( V_2 ) ;
return NULL ;
V_259:
F_73 ( V_25 ) ;
F_36 ( & V_2 -> V_22 . V_66 ) ;
V_258:
F_87 ( V_2 ) ;
V_83:
#endif
return F_71 ( V_80 , V_257 ) ;
}
int F_196 ( struct V_1 * V_2 , unsigned int V_5 )
{
int V_261 = 0 ;
struct V_179 * V_179 ;
F_152 ( ! F_1 ( V_2 ) ) ;
F_197 () ;
V_179 = F_198 ( V_160 [ V_2 -> V_178 ] . V_179 ) ;
if ( V_179 && V_5 - 1 < V_160 [ V_2 -> V_178 ] . V_152 )
V_261 = F_12 ( V_5 - 1 , V_179 -> V_181 ) ;
F_199 () ;
return V_261 ;
}
static int F_200 ( struct V_1 * V_2 , struct V_24 * V_25 )
{
struct V_13 * V_14 = F_2 ( V_2 ) ;
if ( F_29 ( & V_2 -> V_146 ) <= V_2 -> V_247 &&
! F_12 ( V_16 , & V_14 -> V_17 ) ) {
F_89 ( V_25 , V_2 ) ;
F_181 ( V_2 , V_25 ) ;
return F_29 ( & V_2 -> V_146 ) > ( V_2 -> V_247 >> 1 ) ;
}
return - 1 ;
}
static int F_201 ( struct V_1 * V_2 ,
struct V_262 * V_263 )
{
struct V_13 * V_14 = F_2 ( V_2 ) ;
int V_264 ;
if ( V_263 -> V_265 == V_2 )
goto V_83;
if ( V_14 -> V_9 == V_263 -> V_9 || V_263 -> V_5 - 1 >= V_14 -> V_180 ||
! F_12 ( V_263 -> V_5 - 1 , V_14 -> V_152 ) )
goto V_83;
if ( ! F_115 ( F_116 ( V_2 ) , V_263 -> V_158 ) )
goto V_83;
if ( V_263 -> V_266 ) {
F_6 ( V_2 ) ;
goto V_83;
}
F_69 ( V_2 ) ;
if ( V_263 -> V_267 == NULL ) {
if ( F_186 ( V_263 -> V_25 ) ) {
V_263 -> V_267 = F_187 ( V_263 -> V_25 , V_263 -> V_251 ) ;
} else {
V_263 -> V_267 = F_202 ( V_263 -> V_25 ) ;
F_203 ( V_263 -> V_267 ) ;
}
}
if ( V_263 -> V_267 == NULL ) {
F_6 ( V_2 ) ;
V_263 -> V_266 = 1 ;
if ( V_14 -> V_3 & V_268 )
V_263 -> V_269 = 1 ;
} else if ( V_263 -> V_270 && V_263 -> V_270 ( V_2 , V_263 -> V_267 , V_263 -> V_271 ) ) {
F_73 ( V_263 -> V_267 ) ;
V_263 -> V_267 = NULL ;
} else if ( F_194 ( V_2 , V_263 -> V_267 ) ) {
F_73 ( V_263 -> V_267 ) ;
V_263 -> V_267 = NULL ;
} else if ( ( V_264 = F_200 ( V_2 , V_263 -> V_267 ) ) < 0 ) {
F_6 ( V_2 ) ;
if ( V_14 -> V_3 & V_268 )
V_263 -> V_269 = 1 ;
} else {
V_263 -> V_272 |= V_264 ;
V_263 -> V_273 = 1 ;
V_263 -> V_267 = NULL ;
}
F_87 ( V_2 ) ;
V_83:
return 0 ;
}
int F_204 ( struct V_1 * V_239 , struct V_24 * V_25 , T_1 V_9 ,
T_1 V_5 , T_2 V_251 ,
int (* F_205)( struct V_1 * V_274 , struct V_24 * V_25 , void * V_112 ) ,
void * V_275 )
{
struct V_158 * V_158 = F_116 ( V_239 ) ;
struct V_262 V_276 ;
struct V_1 * V_2 ;
V_25 = F_185 ( V_25 , V_251 ) ;
V_276 . V_265 = V_239 ;
V_276 . V_158 = V_158 ;
V_276 . V_9 = V_9 ;
V_276 . V_5 = V_5 ;
V_276 . V_266 = 0 ;
V_276 . V_269 = 0 ;
V_276 . V_272 = 0 ;
V_276 . V_273 = 0 ;
V_276 . V_251 = V_251 ;
V_276 . V_25 = V_25 ;
V_276 . V_267 = NULL ;
V_276 . V_270 = F_205 ;
V_276 . V_271 = V_275 ;
F_108 () ;
F_129 (sk, &nl_table[ssk->sk_protocol].mc_list)
F_201 ( V_2 , & V_276 ) ;
F_85 ( V_25 ) ;
F_111 () ;
if ( V_276 . V_269 ) {
F_73 ( V_276 . V_267 ) ;
return - V_19 ;
}
F_85 ( V_276 . V_267 ) ;
if ( V_276 . V_273 ) {
if ( V_276 . V_272 && ( V_251 & V_277 ) )
F_206 () ;
return 0 ;
}
return - V_278 ;
}
int F_75 ( struct V_1 * V_239 , struct V_24 * V_25 , T_1 V_9 ,
T_1 V_5 , T_2 V_251 )
{
return F_204 ( V_239 , V_25 , V_9 , V_5 , V_251 ,
NULL , NULL ) ;
}
static int F_207 ( struct V_1 * V_2 , struct V_279 * V_263 )
{
struct V_13 * V_14 = F_2 ( V_2 ) ;
int V_254 = 0 ;
if ( V_2 == V_263 -> V_265 )
goto V_83;
if ( ! F_115 ( F_116 ( V_2 ) , F_116 ( V_263 -> V_265 ) ) )
goto V_83;
if ( V_14 -> V_9 == V_263 -> V_9 || V_263 -> V_5 - 1 >= V_14 -> V_180 ||
! F_12 ( V_263 -> V_5 - 1 , V_14 -> V_152 ) )
goto V_83;
if ( V_263 -> V_280 == V_19 && V_14 -> V_3 & V_15 ) {
V_254 = 1 ;
goto V_83;
}
V_2 -> V_18 = V_263 -> V_280 ;
V_2 -> V_20 ( V_2 ) ;
V_83:
return V_254 ;
}
int F_208 ( struct V_1 * V_239 , T_1 V_9 , T_1 V_5 , int V_280 )
{
struct V_279 V_276 ;
struct V_1 * V_2 ;
int V_254 = 0 ;
V_276 . V_265 = V_239 ;
V_276 . V_9 = V_9 ;
V_276 . V_5 = V_5 ;
V_276 . V_280 = - V_280 ;
F_109 ( & T_4 ) ;
F_129 (sk, &nl_table[ssk->sk_protocol].mc_list)
V_254 += F_207 ( V_2 , & V_276 ) ;
F_110 ( & T_4 ) ;
return V_254 ;
}
static void F_209 ( struct V_13 * V_14 ,
unsigned int V_5 ,
int V_281 )
{
int V_208 , V_282 = ! ! V_281 , V_186 ;
V_208 = F_12 ( V_5 - 1 , V_14 -> V_152 ) ;
V_186 = V_14 -> V_186 - V_208 + V_282 ;
if ( V_282 )
F_210 ( V_5 - 1 , V_14 -> V_152 ) ;
else
F_211 ( V_5 - 1 , V_14 -> V_152 ) ;
F_160 ( & V_14 -> V_2 , V_186 ) ;
F_126 ( & V_14 -> V_2 ) ;
}
static int F_212 ( struct V_77 * V_1 , int V_283 , int V_284 ,
char T_7 * V_285 , unsigned int V_286 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_13 * V_14 = F_2 ( V_2 ) ;
unsigned int V_264 = 0 ;
int V_52 ;
if ( V_283 != V_287 )
return - V_288 ;
if ( V_284 != V_289 && V_284 != V_290 &&
V_286 >= sizeof( int ) &&
F_213 ( V_264 , ( unsigned int T_7 * ) V_285 ) )
return - V_291 ;
switch ( V_284 ) {
case V_292 :
if ( V_264 )
V_14 -> V_3 |= V_293 ;
else
V_14 -> V_3 &= ~ V_293 ;
V_52 = 0 ;
break;
case V_294 :
case V_295 : {
if ( ! F_158 ( V_1 , V_227 ) )
return - V_228 ;
V_52 = F_162 ( V_2 ) ;
if ( V_52 )
return V_52 ;
if ( ! V_264 || V_264 - 1 >= V_14 -> V_180 )
return - V_58 ;
F_97 () ;
F_209 ( V_14 , V_264 ,
V_284 == V_294 ) ;
F_106 () ;
if ( V_14 -> V_204 )
V_14 -> V_204 ( V_264 ) ;
V_52 = 0 ;
break;
}
case V_296 :
if ( V_264 )
V_14 -> V_3 |= V_268 ;
else
V_14 -> V_3 &= ~ V_268 ;
V_52 = 0 ;
break;
case V_297 :
if ( V_264 ) {
V_14 -> V_3 |= V_15 ;
F_11 ( V_16 , & V_14 -> V_17 ) ;
F_13 ( & V_14 -> V_23 ) ;
} else {
V_14 -> V_3 &= ~ V_15 ;
}
V_52 = 0 ;
break;
#ifdef F_86
case V_289 :
case V_290 : {
struct V_41 V_42 ;
if ( ! F_214 ( V_214 ) )
return - V_228 ;
if ( V_286 < sizeof( V_42 ) )
return - V_58 ;
if ( F_215 ( & V_42 , V_285 , sizeof( V_42 ) ) )
return - V_291 ;
V_52 = F_28 ( V_2 , & V_42 , false ,
V_284 == V_290 ) ;
break;
}
#endif
default:
V_52 = - V_288 ;
}
return V_52 ;
}
static int F_216 ( struct V_77 * V_1 , int V_283 , int V_284 ,
char T_7 * V_285 , int T_7 * V_286 )
{
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_13 * V_14 = F_2 ( V_2 ) ;
int V_31 , V_264 , V_52 ;
if ( V_283 != V_287 )
return - V_288 ;
if ( F_213 ( V_31 , V_286 ) )
return - V_291 ;
if ( V_31 < 0 )
return - V_58 ;
switch ( V_284 ) {
case V_292 :
if ( V_31 < sizeof( int ) )
return - V_58 ;
V_31 = sizeof( int ) ;
V_264 = V_14 -> V_3 & V_293 ? 1 : 0 ;
if ( F_217 ( V_31 , V_286 ) ||
F_217 ( V_264 , V_285 ) )
return - V_291 ;
V_52 = 0 ;
break;
case V_296 :
if ( V_31 < sizeof( int ) )
return - V_58 ;
V_31 = sizeof( int ) ;
V_264 = V_14 -> V_3 & V_268 ? 1 : 0 ;
if ( F_217 ( V_31 , V_286 ) ||
F_217 ( V_264 , V_285 ) )
return - V_291 ;
V_52 = 0 ;
break;
case V_297 :
if ( V_31 < sizeof( int ) )
return - V_58 ;
V_31 = sizeof( int ) ;
V_264 = V_14 -> V_3 & V_15 ? 1 : 0 ;
if ( F_217 ( V_31 , V_286 ) ||
F_217 ( V_264 , V_285 ) )
return - V_291 ;
V_52 = 0 ;
break;
default:
V_52 = - V_288 ;
}
return V_52 ;
}
static void F_218 ( struct V_117 * V_118 , struct V_24 * V_25 )
{
struct V_298 V_276 ;
V_276 . V_5 = F_15 ( V_25 ) . V_120 ;
F_219 ( V_118 , V_287 , V_292 , sizeof( V_276 ) , & V_276 ) ;
}
static int F_220 ( struct V_299 * V_299 , struct V_77 * V_1 ,
struct V_117 * V_118 , T_5 V_31 )
{
struct V_121 * V_122 = F_221 ( V_299 ) ;
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_13 * V_14 = F_2 ( V_2 ) ;
struct V_222 * V_220 = V_118 -> V_300 ;
T_1 V_119 ;
T_1 V_120 ;
struct V_24 * V_25 ;
int V_52 ;
struct V_301 V_133 ;
if ( V_118 -> V_128 & V_302 )
return - V_303 ;
if ( NULL == V_122 -> V_133 )
V_122 -> V_133 = & V_133 ;
V_52 = F_222 ( V_1 , V_118 , V_122 -> V_133 , true ) ;
if ( V_52 < 0 )
return V_52 ;
if ( V_118 -> V_304 ) {
V_52 = - V_58 ;
if ( V_220 -> V_224 != V_225 )
goto V_83;
V_119 = V_220 -> V_229 ;
V_120 = F_167 ( V_220 -> V_226 ) ;
V_52 = - V_228 ;
if ( ( V_120 || V_119 ) &&
! F_158 ( V_1 , V_235 ) )
goto V_83;
} else {
V_119 = V_14 -> V_119 ;
V_120 = V_14 -> V_120 ;
}
if ( ! V_14 -> V_9 ) {
V_52 = F_155 ( V_1 ) ;
if ( V_52 )
goto V_83;
}
if ( F_17 ( V_2 ) &&
V_118 -> V_305 -> V_306 == NULL ) {
V_52 = F_64 ( V_2 , V_118 , V_119 , V_120 ,
V_122 ) ;
goto V_83;
}
V_52 = - V_307 ;
if ( V_31 > V_2 -> V_308 - 32 )
goto V_83;
V_52 = - V_19 ;
V_25 = F_71 ( V_31 , V_35 ) ;
if ( V_25 == NULL )
goto V_83;
F_15 ( V_25 ) . V_9 = V_14 -> V_9 ;
F_15 ( V_25 ) . V_120 = V_120 ;
F_15 ( V_25 ) . V_132 = V_122 -> V_133 -> V_132 ;
V_52 = - V_291 ;
if ( F_223 ( F_224 ( V_25 , V_31 ) , V_118 -> V_305 , V_31 ) ) {
F_73 ( V_25 ) ;
goto V_83;
}
V_52 = F_72 ( V_2 , V_25 ) ;
if ( V_52 ) {
F_73 ( V_25 ) ;
goto V_83;
}
if ( V_120 ) {
F_8 ( & V_25 -> V_134 ) ;
F_75 ( V_2 , V_25 , V_119 , V_120 , V_35 ) ;
}
V_52 = F_76 ( V_2 , V_25 , V_119 , V_118 -> V_128 & V_129 ) ;
V_83:
F_225 ( V_122 -> V_133 ) ;
return V_52 ;
}
static int F_226 ( struct V_299 * V_299 , struct V_77 * V_1 ,
struct V_117 * V_118 , T_5 V_31 ,
int V_3 )
{
struct V_121 * V_122 = F_221 ( V_299 ) ;
struct V_301 V_133 ;
struct V_1 * V_2 = V_1 -> V_2 ;
struct V_13 * V_14 = F_2 ( V_2 ) ;
int V_309 = V_3 & V_129 ;
T_5 V_310 ;
struct V_24 * V_25 , * V_311 ;
int V_52 , V_254 ;
if ( V_3 & V_302 )
return - V_303 ;
V_310 = 0 ;
V_25 = F_227 ( V_2 , V_3 , V_309 , & V_52 ) ;
if ( V_25 == NULL )
goto V_83;
V_311 = V_25 ;
#ifdef F_228
if ( F_74 ( F_229 ( V_25 ) -> V_312 ) ) {
if ( V_3 & V_313 )
V_311 = F_229 ( V_25 ) -> V_312 ;
}
#endif
V_118 -> V_304 = 0 ;
V_310 = V_311 -> V_31 ;
if ( V_31 < V_310 ) {
V_118 -> V_128 |= V_314 ;
V_310 = V_31 ;
}
F_230 ( V_311 ) ;
V_52 = F_231 ( V_311 , 0 , V_118 -> V_305 , V_310 ) ;
if ( V_118 -> V_300 ) {
struct V_222 * V_220 = (struct V_222 * ) V_118 -> V_300 ;
V_220 -> V_224 = V_225 ;
V_220 -> V_238 = 0 ;
V_220 -> V_229 = F_15 ( V_25 ) . V_9 ;
V_220 -> V_226 = F_3 ( F_15 ( V_25 ) . V_120 ) ;
V_118 -> V_304 = sizeof( * V_220 ) ;
}
if ( V_14 -> V_3 & V_293 )
F_218 ( V_118 , V_25 ) ;
if ( NULL == V_122 -> V_133 ) {
memset ( & V_133 , 0 , sizeof( V_133 ) ) ;
V_122 -> V_133 = & V_133 ;
}
V_122 -> V_133 -> V_132 = * F_232 ( V_25 ) ;
if ( V_3 & V_314 )
V_310 = V_311 -> V_31 ;
F_233 ( V_2 , V_25 ) ;
if ( V_14 -> V_107 && F_29 ( & V_2 -> V_146 ) <= V_2 -> V_247 / 2 ) {
V_254 = F_59 ( V_2 ) ;
if ( V_254 ) {
V_2 -> V_18 = V_254 ;
V_2 -> V_20 ( V_2 ) ;
}
}
F_234 ( V_1 , V_118 , V_122 -> V_133 , V_3 ) ;
V_83:
F_9 ( V_2 ) ;
return V_52 ? : V_310 ;
}
static void F_235 ( struct V_1 * V_2 , int V_31 )
{
F_236 () ;
}
struct V_1 *
F_237 ( struct V_158 * V_158 , int V_315 , struct V_148 * V_148 ,
struct V_316 * V_317 )
{
struct V_77 * V_1 ;
struct V_1 * V_2 ;
struct V_13 * V_14 ;
struct V_179 * V_179 = NULL ;
struct V_187 * V_188 = V_317 ? V_317 -> V_188 : NULL ;
unsigned int V_152 ;
F_152 ( ! V_160 ) ;
if ( V_315 < 0 || V_315 >= V_200 )
return NULL ;
if ( F_238 ( V_191 , V_198 , V_315 , & V_1 ) )
return NULL ;
if ( F_135 ( & V_318 , V_1 , V_188 , V_315 ) < 0 )
goto V_319;
V_2 = V_1 -> V_2 ;
F_239 ( V_2 , V_158 ) ;
if ( ! V_317 || V_317 -> V_152 < 32 )
V_152 = 32 ;
else
V_152 = V_317 -> V_152 ;
V_179 = F_118 ( sizeof( * V_179 ) + F_164 ( V_152 ) , V_35 ) ;
if ( ! V_179 )
goto V_320;
V_2 -> V_250 = F_235 ;
if ( V_317 && V_317 -> V_321 )
F_2 ( V_2 ) -> V_255 = V_317 -> V_321 ;
if ( F_130 ( V_2 , V_158 , 0 ) )
goto V_320;
V_14 = F_2 ( V_2 ) ;
V_14 -> V_3 |= V_4 ;
F_97 () ;
if ( ! V_160 [ V_315 ] . V_202 ) {
V_160 [ V_315 ] . V_152 = V_152 ;
F_240 ( V_160 [ V_315 ] . V_179 , V_179 ) ;
V_160 [ V_315 ] . V_188 = V_188 ;
V_160 [ V_315 ] . V_148 = V_148 ;
if ( V_317 ) {
V_160 [ V_315 ] . F_141 = V_317 -> F_141 ;
V_160 [ V_315 ] . V_3 = V_317 -> V_3 ;
}
V_160 [ V_315 ] . V_202 = 1 ;
} else {
F_22 ( V_179 ) ;
V_160 [ V_315 ] . V_202 ++ ;
}
F_106 () ;
return V_2 ;
V_320:
F_22 ( V_179 ) ;
F_241 ( V_2 ) ;
return NULL ;
V_319:
F_242 ( V_1 ) ;
return NULL ;
}
void
F_241 ( struct V_1 * V_2 )
{
F_243 ( V_2 ) ;
}
int F_244 ( struct V_1 * V_2 , unsigned int V_152 )
{
struct V_179 * V_282 , * V_208 ;
struct V_176 * V_177 = & V_160 [ V_2 -> V_178 ] ;
if ( V_152 < 32 )
V_152 = 32 ;
if ( F_164 ( V_177 -> V_152 ) < F_164 ( V_152 ) ) {
V_282 = F_118 ( sizeof( * V_282 ) + F_164 ( V_152 ) , V_162 ) ;
if ( ! V_282 )
return - V_64 ;
V_208 = F_127 ( V_177 -> V_179 ) ;
memcpy ( V_282 -> V_181 , V_208 -> V_181 , F_164 ( V_177 -> V_152 ) ) ;
F_240 ( V_177 -> V_179 , V_282 ) ;
F_154 ( V_208 , V_209 ) ;
}
V_177 -> V_152 = V_152 ;
return 0 ;
}
int F_245 ( struct V_1 * V_2 , unsigned int V_152 )
{
int V_52 ;
F_97 () ;
V_52 = F_244 ( V_2 , V_152 ) ;
F_106 () ;
return V_52 ;
}
void F_246 ( struct V_1 * V_322 , unsigned int V_5 )
{
struct V_1 * V_2 ;
struct V_176 * V_177 = & V_160 [ V_322 -> V_178 ] ;
F_129 (sk, &tbl->mc_list)
F_209 ( F_2 ( V_2 ) , V_5 , 0 ) ;
}
void F_247 ( struct V_1 * V_322 , unsigned int V_5 )
{
F_97 () ;
F_246 ( V_322 , V_5 ) ;
F_106 () ;
}
struct V_323 *
F_248 ( struct V_24 * V_25 , T_1 V_9 , T_1 V_324 , int type , int V_31 , int V_3 )
{
struct V_323 * V_325 ;
int V_80 = F_249 ( V_31 ) ;
V_325 = (struct V_323 * ) F_224 ( V_25 , F_250 ( V_80 ) ) ;
V_325 -> V_326 = type ;
V_325 -> V_327 = V_80 ;
V_325 -> V_328 = V_3 ;
V_325 -> V_329 = V_9 ;
V_325 -> V_330 = V_324 ;
if ( ! F_251 ( V_80 ) || F_250 ( V_80 ) - V_80 != 0 )
memset ( F_252 ( V_325 ) + V_31 , 0 , F_250 ( V_80 ) - V_80 ) ;
return V_325 ;
}
static int F_59 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = F_2 ( V_2 ) ;
struct V_144 * V_107 ;
struct V_24 * V_25 = NULL ;
struct V_323 * V_325 ;
int V_31 , V_52 = - V_19 ;
int V_331 ;
F_32 ( V_14 -> V_188 ) ;
V_107 = V_14 -> V_107 ;
if ( V_107 == NULL ) {
V_52 = - V_58 ;
goto V_332;
}
V_331 = F_253 ( int , V_107 -> V_333 , V_334 ) ;
if ( ! F_16 ( V_2 ) &&
F_29 ( & V_2 -> V_146 ) >= V_2 -> V_247 )
goto V_332;
V_25 = F_195 ( V_2 , V_331 , V_14 -> V_9 , V_35 ) ;
if ( ! V_25 )
goto V_332;
F_89 ( V_25 , V_2 ) ;
V_31 = V_107 -> V_335 ( V_25 , V_107 ) ;
if ( V_31 > 0 ) {
F_38 ( V_14 -> V_188 ) ;
if ( F_194 ( V_2 , V_25 ) )
F_73 ( V_25 ) ;
else
F_181 ( V_2 , V_25 ) ;
return 0 ;
}
V_325 = F_254 ( V_25 , V_107 , V_336 , sizeof( V_31 ) , V_337 ) ;
if ( ! V_325 )
goto V_332;
F_255 ( V_107 , V_325 ) ;
memcpy ( F_252 ( V_325 ) , & V_31 , sizeof( V_31 ) ) ;
if ( F_194 ( V_2 , V_25 ) )
F_73 ( V_25 ) ;
else
F_181 ( V_2 , V_25 ) ;
if ( V_107 -> V_147 )
V_107 -> V_147 ( V_107 ) ;
V_14 -> V_107 = NULL ;
F_38 ( V_14 -> V_188 ) ;
F_93 ( V_107 -> V_148 ) ;
F_84 ( V_107 ) ;
return 0 ;
V_332:
F_38 ( V_14 -> V_188 ) ;
F_73 ( V_25 ) ;
return V_52 ;
}
int F_256 ( struct V_1 * V_239 , struct V_24 * V_25 ,
const struct V_323 * V_325 ,
struct V_338 * V_339 )
{
struct V_144 * V_107 ;
struct V_1 * V_2 ;
struct V_13 * V_14 ;
int V_254 ;
V_107 = F_118 ( sizeof( * V_107 ) , V_35 ) ;
if ( V_107 == NULL )
return - V_19 ;
if ( F_14 ( V_25 ) ) {
V_25 = F_257 ( V_25 , V_35 ) ;
if ( V_25 == NULL ) {
F_22 ( V_107 ) ;
return - V_19 ;
}
} else
F_8 ( & V_25 -> V_134 ) ;
V_107 -> V_335 = V_339 -> V_335 ;
V_107 -> V_147 = V_339 -> V_147 ;
V_107 -> V_325 = V_325 ;
V_107 -> V_112 = V_339 -> V_112 ;
V_107 -> V_148 = V_339 -> V_148 ;
V_107 -> V_333 = V_339 -> V_333 ;
V_107 -> V_25 = V_25 ;
V_2 = F_113 ( F_116 ( V_239 ) , V_239 -> V_178 , F_15 ( V_25 ) . V_9 ) ;
if ( V_2 == NULL ) {
F_83 ( V_107 ) ;
return - V_240 ;
}
V_14 = F_2 ( V_2 ) ;
F_32 ( V_14 -> V_188 ) ;
if ( V_14 -> V_107 ) {
F_38 ( V_14 -> V_188 ) ;
F_83 ( V_107 ) ;
V_254 = - V_55 ;
goto V_83;
}
if ( ! F_144 ( V_107 -> V_148 ) ) {
F_38 ( V_14 -> V_188 ) ;
F_83 ( V_107 ) ;
V_254 = - V_201 ;
goto V_83;
}
V_14 -> V_107 = V_107 ;
F_38 ( V_14 -> V_188 ) ;
V_254 = F_59 ( V_2 ) ;
V_83:
F_87 ( V_2 ) ;
if ( V_254 )
return V_254 ;
return - V_340 ;
}
void F_258 ( struct V_24 * V_341 , struct V_323 * V_325 , int V_52 )
{
struct V_24 * V_25 ;
struct V_323 * V_342 ;
struct V_343 * V_344 ;
T_5 V_345 = sizeof( * V_344 ) ;
if ( V_52 )
V_345 += V_327 ( V_325 ) ;
V_25 = F_195 ( V_341 -> V_2 , F_259 ( V_345 ) ,
F_15 ( V_341 ) . V_9 , V_35 ) ;
if ( ! V_25 ) {
struct V_1 * V_2 ;
V_2 = F_113 ( F_116 ( V_341 -> V_2 ) ,
V_341 -> V_2 -> V_178 ,
F_15 ( V_341 ) . V_9 ) ;
if ( V_2 ) {
V_2 -> V_18 = V_19 ;
V_2 -> V_20 ( V_2 ) ;
F_87 ( V_2 ) ;
}
return;
}
V_342 = F_248 ( V_25 , F_15 ( V_341 ) . V_9 , V_325 -> V_330 ,
V_346 , V_345 , 0 ) ;
V_344 = F_252 ( V_342 ) ;
V_344 -> error = V_52 ;
memcpy ( & V_344 -> V_118 , V_325 , V_52 ? V_325 -> V_327 : sizeof( * V_325 ) ) ;
F_76 ( V_341 -> V_2 , V_25 , F_15 ( V_341 ) . V_9 , V_129 ) ;
}
int F_260 ( struct V_24 * V_25 , int (* V_107)( struct V_24 * ,
struct V_323 * ) )
{
struct V_323 * V_325 ;
int V_52 ;
while ( V_25 -> V_31 >= F_259 ( 0 ) ) {
int V_347 ;
V_325 = F_261 ( V_25 ) ;
V_52 = 0 ;
if ( V_325 -> V_327 < V_348 || V_25 -> V_31 < V_325 -> V_327 )
return 0 ;
if ( ! ( V_325 -> V_328 & V_349 ) )
goto V_350;
if ( V_325 -> V_326 < V_351 )
goto V_350;
V_52 = V_107 ( V_25 , V_325 ) ;
if ( V_52 == - V_340 )
goto V_352;
V_350:
if ( V_325 -> V_328 & V_353 || V_52 )
F_258 ( V_25 , V_325 , V_52 ) ;
V_352:
V_347 = F_250 ( V_325 -> V_327 ) ;
if ( V_347 > V_25 -> V_31 )
V_347 = V_25 -> V_31 ;
F_262 ( V_25 , V_347 ) ;
}
return 0 ;
}
int F_263 ( struct V_1 * V_2 , struct V_24 * V_25 , T_1 V_9 ,
unsigned int V_5 , int V_354 , T_2 V_3 )
{
int V_52 = 0 ;
if ( V_5 ) {
int V_355 = 0 ;
if ( V_354 ) {
F_8 ( & V_25 -> V_134 ) ;
V_355 = V_9 ;
}
V_52 = F_264 ( V_2 , V_25 , V_355 , V_5 , V_3 ) ;
}
if ( V_354 ) {
int V_260 ;
V_260 = F_265 ( V_2 , V_25 , V_9 ) ;
if ( ! V_52 || V_52 == - V_278 )
V_52 = V_260 ;
}
return V_52 ;
}
static struct V_1 * F_266 ( struct V_356 * V_324 , T_8 V_100 )
{
struct V_357 * V_358 = V_324 -> V_359 ;
int V_32 , V_360 ;
struct V_1 * V_361 ;
T_8 V_362 = 0 ;
for ( V_32 = 0 ; V_32 < V_200 ; V_32 ++ ) {
struct V_7 * V_8 = & V_160 [ V_32 ] . V_8 ;
for ( V_360 = 0 ; V_360 <= V_8 -> V_12 ; V_360 ++ ) {
F_114 (s, &hash->table[j]) {
if ( F_116 ( V_361 ) != F_267 ( V_324 ) )
continue;
if ( V_362 == V_100 ) {
V_358 -> V_363 = V_32 ;
V_358 -> V_364 = V_360 ;
return V_361 ;
}
++ V_362 ;
}
}
}
return NULL ;
}
static void * F_268 ( struct V_356 * V_324 , T_8 * V_100 )
__acquires( T_4 )
{
F_109 ( & T_4 ) ;
return * V_100 ? F_266 ( V_324 , * V_100 - 1 ) : V_365 ;
}
static void * F_269 ( struct V_356 * V_324 , void * V_366 , T_8 * V_100 )
{
struct V_1 * V_361 ;
struct V_357 * V_358 ;
int V_32 , V_360 ;
++ * V_100 ;
if ( V_366 == V_365 )
return F_266 ( V_324 , 0 ) ;
V_358 = V_324 -> V_359 ;
V_361 = V_366 ;
do {
V_361 = F_270 ( V_361 ) ;
} while ( V_361 && F_116 ( V_361 ) != F_267 ( V_324 ) );
if ( V_361 )
return V_361 ;
V_32 = V_358 -> V_363 ;
V_360 = V_358 -> V_364 + 1 ;
do {
struct V_7 * V_8 = & V_160 [ V_32 ] . V_8 ;
for (; V_360 <= V_8 -> V_12 ; V_360 ++ ) {
V_361 = F_271 ( & V_8 -> V_10 [ V_360 ] ) ;
while ( V_361 && F_116 ( V_361 ) != F_267 ( V_324 ) )
V_361 = F_270 ( V_361 ) ;
if ( V_361 ) {
V_358 -> V_363 = V_32 ;
V_358 -> V_364 = V_360 ;
return V_361 ;
}
}
V_360 = 0 ;
} while ( ++ V_32 < V_200 );
return NULL ;
}
static void F_272 ( struct V_356 * V_324 , void * V_366 )
__releases( T_4 )
{
F_110 ( & T_4 ) ;
}
static int F_273 ( struct V_356 * V_324 , void * V_366 )
{
if ( V_366 == V_365 ) {
F_274 ( V_324 ,
L_3
L_4 ) ;
} else {
struct V_1 * V_361 = V_366 ;
struct V_13 * V_14 = F_2 ( V_361 ) ;
F_275 ( V_324 , L_5 ,
V_361 ,
V_361 -> V_178 ,
V_14 -> V_9 ,
V_14 -> V_152 ? ( T_1 ) V_14 -> V_152 [ 0 ] : 0 ,
F_276 ( V_361 ) ,
F_277 ( V_361 ) ,
V_14 -> V_107 ,
F_29 ( & V_361 -> V_367 ) ,
F_29 ( & V_361 -> V_21 ) ,
F_278 ( V_361 )
) ;
}
return 0 ;
}
static int F_279 ( struct V_242 * V_242 , struct V_75 * V_75 )
{
return F_280 ( V_242 , V_75 , & V_368 ,
sizeof( struct V_357 ) ) ;
}
int F_281 ( struct V_369 * V_370 )
{
return F_282 ( & V_206 , V_370 ) ;
}
int F_283 ( struct V_369 * V_370 )
{
return F_284 ( & V_206 , V_370 ) ;
}
static int T_9 F_285 ( struct V_158 * V_158 )
{
#ifdef F_286
if ( ! F_287 ( L_6 , 0 , V_158 -> V_371 , & V_372 ) )
return - V_64 ;
#endif
return 0 ;
}
static void T_10 F_288 ( struct V_158 * V_158 )
{
#ifdef F_286
F_289 ( L_6 , V_158 -> V_371 ) ;
#endif
}
static void T_11 F_290 ( void )
{
struct V_179 * V_179 ;
int V_152 = 32 ;
V_179 = F_118 ( sizeof( * V_179 ) + F_164 ( V_152 ) , V_35 ) ;
if ( ! V_179 )
F_291 ( L_7 ) ;
F_97 () ;
V_160 [ V_373 ] . V_152 = V_152 ;
F_240 ( V_160 [ V_373 ] . V_179 , V_179 ) ;
V_160 [ V_373 ] . V_148 = V_374 ;
V_160 [ V_373 ] . V_202 = 1 ;
V_160 [ V_373 ] . V_3 = V_235 ;
F_106 () ;
}
static int T_11 F_292 ( void )
{
int V_32 ;
unsigned long V_375 ;
unsigned int V_30 ;
int V_52 = F_293 ( & V_192 , 0 ) ;
if ( V_52 != 0 )
goto V_83;
F_294 ( sizeof( struct V_376 ) > F_295 ( struct V_24 , V_107 ) ) ;
V_160 = F_27 ( V_200 , sizeof( * V_160 ) , V_35 ) ;
if ( ! V_160 )
goto F_291;
if ( V_377 >= ( 128 * 1024 ) )
V_375 = V_377 >> ( 21 - V_378 ) ;
else
V_375 = V_377 >> ( 23 - V_378 ) ;
V_30 = F_296 ( V_375 ) - 1 + V_378 ;
V_375 = ( 1UL << V_30 ) / sizeof( struct V_6 ) ;
V_30 = F_296 ( F_297 ( V_375 , ( unsigned long ) V_185 ) ) - 1 ;
for ( V_32 = 0 ; V_32 < V_200 ; V_32 ++ ) {
struct V_7 * V_8 = & V_160 [ V_32 ] . V_8 ;
V_8 -> V_10 = F_117 ( 1 * sizeof( * V_8 -> V_10 ) ) ;
if ( ! V_8 -> V_10 ) {
while ( V_32 -- > 0 )
F_119 ( V_160 [ V_32 ] . V_8 . V_10 ,
1 * sizeof( * V_8 -> V_10 ) ) ;
F_22 ( V_160 ) ;
goto F_291;
}
V_8 -> V_168 = V_30 ;
V_8 -> V_165 = 0 ;
V_8 -> V_12 = 0 ;
V_8 -> V_171 = V_172 ;
}
F_290 () ;
F_298 ( & V_379 ) ;
F_299 ( & V_380 ) ;
F_300 () ;
V_83:
return V_52 ;
F_291:
F_291 ( L_8 ) ;
}
