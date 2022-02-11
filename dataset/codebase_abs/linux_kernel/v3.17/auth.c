static int F_1 ( const char * V_1 , const struct V_2 * V_3 )
{
unsigned long V_4 ;
unsigned int V_5 ;
int V_6 ;
if ( ! V_1 )
goto V_7;
V_6 = F_2 ( V_1 , 0 , & V_4 ) ;
if ( V_6 == - V_8 )
goto V_7;
V_5 = F_3 ( V_4 ) ;
if ( V_4 > ( 1U << V_5 ) )
V_5 ++ ;
if ( V_5 > V_9 || V_5 < 2 )
goto V_7;
* ( unsigned int * ) V_3 -> V_10 = V_5 ;
return 0 ;
V_7:
return - V_8 ;
}
static int F_4 ( char * V_11 , const struct V_2 * V_3 )
{
unsigned int V_5 ;
V_5 = * ( unsigned int * ) V_3 -> V_10 ;
return sprintf ( V_11 , L_1 , 1U << V_5 ) ;
}
static T_1
F_5 ( T_1 V_12 ) {
if ( V_12 > V_13 )
return V_14 ;
return V_12 ;
}
int
F_6 ( const struct V_15 * V_16 )
{
T_2 V_12 ;
int V_6 = - V_17 ;
if ( ( V_12 = V_16 -> V_18 ) >= V_13 )
return - V_8 ;
F_7 ( & V_19 ) ;
if ( V_20 [ V_12 ] == NULL ) {
V_20 [ V_12 ] = V_16 ;
V_6 = 0 ;
}
F_8 ( & V_19 ) ;
return V_6 ;
}
int
F_9 ( const struct V_15 * V_16 )
{
T_2 V_12 ;
int V_6 = - V_17 ;
if ( ( V_12 = V_16 -> V_18 ) >= V_13 )
return - V_8 ;
F_7 ( & V_19 ) ;
if ( V_20 [ V_12 ] == V_16 ) {
V_20 [ V_12 ] = NULL ;
V_6 = 0 ;
}
F_8 ( & V_19 ) ;
return V_6 ;
}
T_2
F_10 ( T_2 V_12 , struct V_21 * V_22 )
{
const struct V_15 * V_16 ;
T_2 V_23 ;
V_16 = V_20 [ V_12 ] ;
if ( V_16 == NULL )
F_11 ( L_2 , V_12 ) ;
F_7 ( & V_19 ) ;
V_16 = V_20 [ V_12 ] ;
if ( V_16 == NULL || ! F_12 ( V_16 -> V_24 ) ) {
F_8 ( & V_19 ) ;
return V_13 ;
}
F_8 ( & V_19 ) ;
V_23 = V_12 ;
if ( V_16 -> V_25 != NULL )
V_23 = V_16 -> V_25 ( V_22 ) ;
F_13 ( V_16 -> V_24 ) ;
return V_23 ;
}
int
F_14 ( T_2 V_23 , struct V_21 * V_22 )
{
T_2 V_12 = F_5 ( V_23 ) ;
const struct V_15 * V_16 ;
int V_26 ;
if ( V_12 >= V_13 )
return - V_8 ;
V_16 = V_20 [ V_12 ] ;
if ( V_16 == NULL )
F_11 ( L_2 , V_12 ) ;
F_7 ( & V_19 ) ;
V_16 = V_20 [ V_12 ] ;
if ( V_16 == NULL || ! F_12 ( V_16 -> V_24 ) ) {
F_8 ( & V_19 ) ;
return - V_27 ;
}
F_8 ( & V_19 ) ;
V_26 = - V_27 ;
if ( V_16 -> V_28 != NULL )
V_26 = V_16 -> V_28 ( V_23 , V_22 ) ;
F_13 ( V_16 -> V_24 ) ;
return V_26 ;
}
int
F_15 ( T_2 * V_29 , int V_30 )
{
T_2 V_12 ;
int V_26 = 0 ;
F_7 ( & V_19 ) ;
for ( V_12 = 0 ; V_12 < V_13 ; V_12 ++ ) {
const struct V_15 * V_16 = V_20 [ V_12 ] ;
T_2 V_31 [ 4 ] ;
int V_32 , V_33 ;
if ( V_26 >= V_30 ) {
V_26 = - V_34 ;
break;
}
if ( V_16 == NULL )
continue;
if ( V_16 -> V_35 == NULL ) {
V_29 [ V_26 ++ ] = V_16 -> V_18 ;
continue;
}
V_33 = V_16 -> V_35 ( V_31 , F_16 ( V_31 ) ) ;
if ( V_33 < 0 ) {
V_26 = V_33 ;
break;
}
for ( V_32 = 0 ; V_32 < V_33 ; V_32 ++ ) {
if ( V_26 >= V_30 ) {
V_26 = - V_34 ;
break;
}
V_29 [ V_26 ++ ] = V_31 [ V_32 ] ;
}
}
F_8 ( & V_19 ) ;
F_17 ( L_3 , V_36 , V_26 ) ;
return V_26 ;
}
struct V_37 *
F_18 ( struct V_38 * args , struct V_39 * V_40 )
{
struct V_37 * V_41 ;
const struct V_15 * V_16 ;
T_1 V_12 = F_5 ( args -> V_23 ) ;
V_41 = F_19 ( - V_8 ) ;
if ( V_12 >= V_13 )
goto V_42;
if ( ( V_16 = V_20 [ V_12 ] ) == NULL )
F_11 ( L_2 , V_12 ) ;
F_7 ( & V_19 ) ;
V_16 = V_20 [ V_12 ] ;
if ( V_16 == NULL || ! F_12 ( V_16 -> V_24 ) ) {
F_8 ( & V_19 ) ;
goto V_42;
}
F_8 ( & V_19 ) ;
V_41 = V_16 -> V_43 ( args , V_40 ) ;
F_13 ( V_16 -> V_24 ) ;
if ( F_20 ( V_41 ) )
return V_41 ;
if ( V_40 -> V_44 )
F_21 ( V_40 -> V_44 ) ;
V_40 -> V_44 = V_41 ;
V_42:
return V_41 ;
}
void
F_21 ( struct V_37 * V_41 )
{
if ( ! F_22 ( & V_41 -> V_45 ) )
return;
V_41 -> V_46 -> V_47 ( V_41 ) ;
}
static void
F_23 ( struct V_48 * V_49 )
{
F_24 ( & V_49 -> V_50 ) ;
F_25 () ;
F_26 ( V_51 , & V_49 -> V_52 ) ;
}
static int
F_27 ( struct V_48 * V_49 )
{
T_3 * V_53 ;
int V_6 ;
V_53 = & V_49 -> V_54 -> V_55 -> V_56 ;
F_7 ( V_53 ) ;
V_6 = F_28 ( & V_49 -> V_57 ) == 0 ;
if ( V_6 )
F_23 ( V_49 ) ;
F_8 ( V_53 ) ;
return V_6 ;
}
int
F_29 ( struct V_37 * V_41 )
{
struct V_58 * V_59 ;
unsigned int V_60 ;
V_59 = F_30 ( sizeof( * V_59 ) , V_61 ) ;
if ( ! V_59 )
goto V_62;
V_59 -> V_63 = V_64 ;
V_60 = 1U << V_59 -> V_63 ;
V_59 -> V_65 = F_31 ( V_60 , sizeof( V_59 -> V_65 [ 0 ] ) , V_61 ) ;
if ( ! V_59 -> V_65 )
goto V_66;
F_32 ( & V_59 -> V_56 ) ;
V_41 -> V_55 = V_59 ;
return 0 ;
V_66:
F_33 ( V_59 ) ;
V_62:
return - V_34 ;
}
int
F_34 ( struct V_37 * V_41 , struct V_48 * V_49 )
{
if ( ! V_49 -> V_54 -> V_46 -> V_67 )
return 0 ;
return V_49 -> V_54 -> V_46 -> V_67 ( V_41 , V_49 ) ;
}
bool
F_35 ( struct V_48 * V_49 )
{
if ( ! V_49 -> V_68 -> V_69 )
return false ;
return V_49 -> V_68 -> V_69 ( V_49 ) ;
}
char *
F_36 ( struct V_48 * V_49 )
{
if ( ! V_49 -> V_68 -> V_70 )
return NULL ;
return V_49 -> V_68 -> V_70 ( V_49 ) ;
}
static inline
void F_37 ( struct V_71 * V_72 )
{
struct V_48 * V_49 ;
while ( ! F_38 ( V_72 ) ) {
V_49 = F_39 ( V_72 -> V_73 , struct V_48 , V_74 ) ;
F_40 ( & V_49 -> V_74 ) ;
F_41 ( V_49 ) ;
}
}
void
F_42 ( struct V_58 * V_75 )
{
F_43 ( free ) ;
struct V_76 * V_72 ;
struct V_48 * V_49 ;
unsigned int V_60 = 1U << V_75 -> V_63 ;
int V_32 ;
F_7 ( & V_77 ) ;
F_7 ( & V_75 -> V_56 ) ;
for ( V_32 = 0 ; V_32 < V_60 ; V_32 ++ ) {
V_72 = & V_75 -> V_65 [ V_32 ] ;
while ( ! F_44 ( V_72 ) ) {
V_49 = F_45 ( V_72 -> V_78 , struct V_48 , V_50 ) ;
F_46 ( V_49 ) ;
if ( ! F_38 ( & V_49 -> V_74 ) ) {
F_47 ( & V_49 -> V_74 ) ;
V_79 -- ;
}
F_48 ( & V_49 -> V_74 , & free ) ;
F_23 ( V_49 ) ;
}
}
F_8 ( & V_75 -> V_56 ) ;
F_8 ( & V_77 ) ;
F_37 ( & free ) ;
}
void
F_49 ( struct V_37 * V_41 )
{
struct V_58 * V_75 = V_41 -> V_55 ;
if ( V_75 ) {
V_41 -> V_55 = NULL ;
F_42 ( V_75 ) ;
F_33 ( V_75 -> V_65 ) ;
F_33 ( V_75 ) ;
}
}
static long
F_50 ( struct V_71 * free , int V_80 )
{
T_3 * V_53 ;
struct V_48 * V_49 , * V_73 ;
unsigned long V_81 = V_82 - V_83 ;
long V_84 = 0 ;
F_51 (cred, next, &cred_unused, cr_lru) {
if ( V_80 -- == 0 )
break;
if ( F_52 ( V_49 -> V_85 , V_81 , V_82 ) &&
F_53 ( V_51 , & V_49 -> V_52 ) != 0 )
break;
F_40 ( & V_49 -> V_74 ) ;
V_79 -- ;
V_84 ++ ;
if ( F_28 ( & V_49 -> V_57 ) != 0 )
continue;
V_53 = & V_49 -> V_54 -> V_55 -> V_56 ;
F_7 ( V_53 ) ;
if ( F_28 ( & V_49 -> V_57 ) == 0 ) {
F_46 ( V_49 ) ;
F_48 ( & V_49 -> V_74 , free ) ;
F_23 ( V_49 ) ;
}
F_8 ( V_53 ) ;
}
return V_84 ;
}
static unsigned long
F_54 ( int V_80 )
{
F_43 ( free ) ;
unsigned long V_84 ;
F_7 ( & V_77 ) ;
V_84 = F_50 ( & free , V_80 ) ;
F_8 ( & V_77 ) ;
F_37 ( & free ) ;
return V_84 ;
}
static unsigned long
F_55 ( struct V_86 * V_87 , struct V_88 * V_89 )
{
if ( ( V_89 -> V_90 & V_61 ) != V_61 )
return V_91 ;
if ( F_38 ( & V_92 ) )
return V_91 ;
return F_54 ( V_89 -> V_80 ) ;
}
static unsigned long
F_56 ( struct V_86 * V_87 , struct V_88 * V_89 )
{
return ( V_79 / 100 ) * V_93 ;
}
static void
F_57 ( void )
{
unsigned long V_94 ;
unsigned int V_80 ;
if ( V_79 <= V_95 )
return;
V_94 = V_79 - V_95 ;
V_80 = 100 ;
if ( V_94 < V_80 )
V_80 = V_94 ;
F_54 ( V_80 ) ;
}
struct V_48 *
F_58 ( struct V_37 * V_41 , struct V_96 * V_97 ,
int V_98 )
{
F_43 ( free ) ;
struct V_58 * V_75 = V_41 -> V_55 ;
struct V_48 * V_49 = NULL ,
* V_99 , * V_59 ;
unsigned int V_100 ;
V_100 = F_59 ( F_60 ( & V_101 , V_97 -> V_102 ) , V_75 -> V_63 ) ;
F_61 () ;
F_62 (entry, &cache->hashtable[nr], cr_hash) {
if ( ! V_99 -> V_68 -> V_103 ( V_97 , V_99 , V_98 ) )
continue;
if ( V_98 & V_104 ) {
if ( F_53 ( V_51 , & V_99 -> V_52 ) &&
! F_53 ( V_105 , & V_99 -> V_52 ) )
V_49 = V_99 ;
break;
}
F_7 ( & V_75 -> V_56 ) ;
if ( F_53 ( V_51 , & V_99 -> V_52 ) == 0 ) {
F_8 ( & V_75 -> V_56 ) ;
continue;
}
V_49 = F_46 ( V_99 ) ;
F_8 ( & V_75 -> V_56 ) ;
break;
}
F_63 () ;
if ( V_49 != NULL )
goto V_106;
if ( V_98 & V_104 )
return F_19 ( - V_107 ) ;
V_59 = V_41 -> V_46 -> V_108 ( V_41 , V_97 , V_98 ) ;
if ( F_20 ( V_59 ) ) {
V_49 = V_59 ;
goto V_42;
}
F_7 ( & V_75 -> V_56 ) ;
F_64 (entry, &cache->hashtable[nr], cr_hash) {
if ( ! V_99 -> V_68 -> V_103 ( V_97 , V_99 , V_98 ) )
continue;
V_49 = F_46 ( V_99 ) ;
break;
}
if ( V_49 == NULL ) {
V_49 = V_59 ;
F_65 ( V_51 , & V_49 -> V_52 ) ;
F_66 ( & V_49 -> V_50 , & V_75 -> V_65 [ V_100 ] ) ;
} else
F_48 ( & V_59 -> V_74 , & free ) ;
F_8 ( & V_75 -> V_56 ) ;
F_57 () ;
V_106:
if ( F_53 ( V_105 , & V_49 -> V_52 ) &&
V_49 -> V_68 -> V_109 != NULL &&
! ( V_98 & V_110 ) ) {
int V_111 = V_49 -> V_68 -> V_109 ( V_41 , V_49 ) ;
if ( V_111 < 0 ) {
F_41 ( V_49 ) ;
V_49 = F_19 ( V_111 ) ;
}
}
F_37 ( & free ) ;
V_42:
return V_49 ;
}
struct V_48 *
F_67 ( struct V_37 * V_41 , int V_98 )
{
struct V_96 V_97 ;
struct V_48 * V_6 ;
const struct V_49 * V_49 = F_68 () ;
F_17 ( L_4 ,
V_41 -> V_46 -> V_112 ) ;
memset ( & V_97 , 0 , sizeof( V_97 ) ) ;
V_97 . V_102 = V_49 -> V_113 ;
V_97 . V_114 = V_49 -> V_115 ;
V_97 . V_116 = V_49 -> V_116 ;
V_6 = V_41 -> V_46 -> V_117 ( V_41 , & V_97 , V_98 ) ;
return V_6 ;
}
void
F_69 ( struct V_48 * V_49 , const struct V_96 * V_97 ,
struct V_37 * V_41 , const struct V_118 * V_16 )
{
F_70 ( & V_49 -> V_50 ) ;
F_71 ( & V_49 -> V_74 ) ;
F_72 ( & V_49 -> V_57 , 1 ) ;
V_49 -> V_54 = V_41 ;
V_49 -> V_68 = V_16 ;
V_49 -> V_85 = V_82 ;
#ifdef F_73
V_49 -> V_119 = V_120 ;
#endif
V_49 -> V_121 = V_97 -> V_102 ;
}
struct V_48 *
F_74 ( struct V_122 * V_123 , struct V_48 * V_49 , int V_124 )
{
F_17 ( L_5 , V_123 -> V_125 ,
V_49 -> V_54 -> V_46 -> V_112 , V_49 ) ;
return F_46 ( V_49 ) ;
}
static struct V_48 *
F_75 ( struct V_122 * V_123 , int V_124 )
{
struct V_37 * V_41 = V_123 -> V_126 -> V_44 ;
struct V_96 V_97 = {
. V_102 = V_127 ,
. V_114 = V_128 ,
} ;
F_17 ( L_6 ,
V_123 -> V_125 , V_123 -> V_126 -> V_44 -> V_46 -> V_112 ) ;
return V_41 -> V_46 -> V_117 ( V_41 , & V_97 , V_124 ) ;
}
static struct V_48 *
F_76 ( struct V_122 * V_123 , int V_124 )
{
struct V_37 * V_41 = V_123 -> V_126 -> V_44 ;
F_17 ( L_6 ,
V_123 -> V_125 , V_41 -> V_46 -> V_112 ) ;
return F_67 ( V_41 , V_124 ) ;
}
static int
F_77 ( struct V_122 * V_123 , struct V_48 * V_49 , int V_98 )
{
struct V_129 * V_130 = V_123 -> V_131 ;
struct V_48 * V_59 ;
int V_124 = 0 ;
if ( V_98 & V_132 )
V_124 |= V_110 ;
if ( V_49 != NULL )
V_59 = V_49 -> V_68 -> V_133 ( V_123 , V_49 , V_124 ) ;
else if ( V_98 & V_134 )
V_59 = F_75 ( V_123 , V_124 ) ;
else
V_59 = F_76 ( V_123 , V_124 ) ;
if ( F_20 ( V_59 ) )
return F_78 ( V_59 ) ;
if ( V_130 -> V_135 != NULL )
F_41 ( V_130 -> V_135 ) ;
V_130 -> V_135 = V_59 ;
return 0 ;
}
void
F_41 ( struct V_48 * V_49 )
{
if ( F_53 ( V_51 , & V_49 -> V_52 ) == 0 ) {
if ( F_22 ( & V_49 -> V_57 ) )
V_49 -> V_68 -> V_136 ( V_49 ) ;
return;
}
if ( ! F_79 ( & V_49 -> V_57 , & V_77 ) )
return;
if ( ! F_38 ( & V_49 -> V_74 ) ) {
V_79 -- ;
F_40 ( & V_49 -> V_74 ) ;
}
if ( F_53 ( V_51 , & V_49 -> V_52 ) != 0 ) {
if ( F_53 ( V_137 , & V_49 -> V_52 ) != 0 ) {
V_49 -> V_85 = V_82 ;
F_48 ( & V_49 -> V_74 , & V_92 ) ;
V_79 ++ ;
goto V_138;
}
if ( ! F_27 ( V_49 ) ) {
goto V_138;
}
}
F_8 ( & V_77 ) ;
V_49 -> V_68 -> V_136 ( V_49 ) ;
return;
V_138:
F_8 ( & V_77 ) ;
}
T_4 *
F_80 ( struct V_122 * V_123 , T_4 * V_139 )
{
struct V_48 * V_49 = V_123 -> V_131 -> V_135 ;
F_17 ( L_7 ,
V_123 -> V_125 , V_49 -> V_54 -> V_46 -> V_112 , V_49 ) ;
return V_49 -> V_68 -> V_140 ( V_123 , V_139 ) ;
}
T_4 *
F_81 ( struct V_122 * V_123 , T_4 * V_139 )
{
struct V_48 * V_49 = V_123 -> V_131 -> V_135 ;
F_17 ( L_8 ,
V_123 -> V_125 , V_49 -> V_54 -> V_46 -> V_112 , V_49 ) ;
return V_49 -> V_68 -> V_141 ( V_123 , V_139 ) ;
}
static void F_82 ( T_5 V_142 , struct V_129 * V_143 ,
T_4 * V_144 , void * V_145 )
{
struct V_146 V_147 ;
F_83 ( & V_147 , & V_143 -> V_148 , V_144 ) ;
V_142 ( V_143 , & V_147 , V_145 ) ;
}
int
F_84 ( struct V_122 * V_123 , T_5 V_142 , void * V_143 ,
T_4 * V_144 , void * V_145 )
{
struct V_48 * V_49 = V_123 -> V_131 -> V_135 ;
F_17 ( L_9 ,
V_123 -> V_125 , V_49 -> V_68 -> V_149 , V_49 ) ;
if ( V_49 -> V_68 -> V_150 )
return V_49 -> V_68 -> V_150 ( V_123 , V_142 , V_143 , V_144 , V_145 ) ;
F_82 ( V_142 , V_143 , V_144 , V_145 ) ;
return 0 ;
}
static int
F_85 ( T_6 V_151 , struct V_129 * V_143 ,
T_4 * V_144 , void * V_145 )
{
struct V_146 V_147 ;
F_86 ( & V_147 , & V_143 -> V_152 , V_144 ) ;
return V_151 ( V_143 , & V_147 , V_145 ) ;
}
int
F_87 ( struct V_122 * V_123 , T_6 V_151 , void * V_143 ,
T_4 * V_144 , void * V_145 )
{
struct V_48 * V_49 = V_123 -> V_131 -> V_135 ;
F_17 ( L_10 ,
V_123 -> V_125 , V_49 -> V_68 -> V_149 , V_49 ) ;
if ( V_49 -> V_68 -> V_153 )
return V_49 -> V_68 -> V_153 ( V_123 , V_151 , V_143 ,
V_144 , V_145 ) ;
return F_85 ( V_151 , V_143 , V_144 , V_145 ) ;
}
int
F_88 ( struct V_122 * V_123 )
{
struct V_48 * V_49 ;
int V_154 ;
V_49 = V_123 -> V_131 -> V_135 ;
if ( V_49 == NULL ) {
V_154 = F_77 ( V_123 , V_123 -> V_155 . V_48 , V_123 -> V_156 ) ;
if ( V_154 < 0 )
goto V_42;
V_49 = V_123 -> V_131 -> V_135 ;
}
F_17 ( L_11 ,
V_123 -> V_125 , V_49 -> V_54 -> V_46 -> V_112 , V_49 ) ;
V_154 = V_49 -> V_68 -> V_157 ( V_123 ) ;
V_42:
if ( V_154 < 0 )
V_123 -> V_158 = V_154 ;
return V_154 ;
}
void
F_89 ( struct V_122 * V_123 )
{
struct V_48 * V_49 = V_123 -> V_131 -> V_135 ;
F_17 ( L_12 ,
V_123 -> V_125 , V_49 -> V_54 -> V_46 -> V_112 , V_49 ) ;
if ( V_49 )
F_26 ( V_137 , & V_49 -> V_52 ) ;
}
int
F_90 ( struct V_122 * V_123 )
{
struct V_48 * V_49 = V_123 -> V_131 -> V_135 ;
return V_49 == NULL ||
F_53 ( V_137 , & V_49 -> V_52 ) != 0 ;
}
int T_7 F_91 ( void )
{
int V_154 ;
V_154 = F_92 () ;
if ( V_154 < 0 )
goto V_159;
V_154 = F_93 () ;
if ( V_154 < 0 )
goto V_160;
F_94 ( & V_161 ) ;
return 0 ;
V_160:
F_95 () ;
V_159:
return V_154 ;
}
void F_96 ( void )
{
F_95 () ;
F_97 () ;
F_98 ( & V_161 ) ;
}
