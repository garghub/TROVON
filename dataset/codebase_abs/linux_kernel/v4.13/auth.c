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
V_5 = F_3 ( V_4 - 1 ) ;
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
F_35 ( struct V_37 * V_41 , struct V_48 * V_49 )
{
if ( V_41 -> V_68 & V_69 )
return false ;
if ( ! V_49 -> V_70 -> V_71 )
return false ;
return V_49 -> V_70 -> V_71 ( V_49 ) ;
}
char *
F_36 ( struct V_48 * V_49 )
{
if ( ! V_49 -> V_70 -> V_72 )
return NULL ;
return V_49 -> V_70 -> V_72 ( V_49 ) ;
}
static inline
void F_37 ( struct V_73 * V_74 )
{
struct V_48 * V_49 ;
while ( ! F_38 ( V_74 ) ) {
V_49 = F_39 ( V_74 -> V_75 , struct V_48 , V_76 ) ;
F_40 ( & V_49 -> V_76 ) ;
F_41 ( V_49 ) ;
}
}
void
F_42 ( struct V_58 * V_77 )
{
F_43 ( free ) ;
struct V_78 * V_74 ;
struct V_48 * V_49 ;
unsigned int V_60 = 1U << V_77 -> V_63 ;
int V_32 ;
F_7 ( & V_79 ) ;
F_7 ( & V_77 -> V_56 ) ;
for ( V_32 = 0 ; V_32 < V_60 ; V_32 ++ ) {
V_74 = & V_77 -> V_65 [ V_32 ] ;
while ( ! F_44 ( V_74 ) ) {
V_49 = F_45 ( V_74 -> V_80 , struct V_48 , V_50 ) ;
F_46 ( V_49 ) ;
if ( ! F_38 ( & V_49 -> V_76 ) ) {
F_47 ( & V_49 -> V_76 ) ;
V_81 -- ;
}
F_48 ( & V_49 -> V_76 , & free ) ;
F_23 ( V_49 ) ;
}
}
F_8 ( & V_77 -> V_56 ) ;
F_8 ( & V_79 ) ;
F_37 ( & free ) ;
}
void
F_49 ( struct V_37 * V_41 )
{
struct V_58 * V_77 = V_41 -> V_55 ;
if ( V_77 ) {
V_41 -> V_55 = NULL ;
F_42 ( V_77 ) ;
F_33 ( V_77 -> V_65 ) ;
F_33 ( V_77 ) ;
}
}
static long
F_50 ( struct V_73 * free , int V_82 )
{
T_3 * V_53 ;
struct V_48 * V_49 , * V_75 ;
unsigned long V_83 = V_84 - V_85 ;
long V_86 = 0 ;
F_51 (cred, next, &cred_unused, cr_lru) {
if ( V_82 -- == 0 )
break;
if ( F_52 ( V_49 -> V_87 , V_83 , V_84 ) &&
F_53 ( V_51 , & V_49 -> V_52 ) != 0 ) {
V_86 = V_88 ;
break;
}
F_40 ( & V_49 -> V_76 ) ;
V_81 -- ;
V_86 ++ ;
if ( F_28 ( & V_49 -> V_57 ) != 0 )
continue;
V_53 = & V_49 -> V_54 -> V_55 -> V_56 ;
F_7 ( V_53 ) ;
if ( F_28 ( & V_49 -> V_57 ) == 0 ) {
F_46 ( V_49 ) ;
F_48 ( & V_49 -> V_76 , free ) ;
F_23 ( V_49 ) ;
}
F_8 ( V_53 ) ;
}
return V_86 ;
}
static unsigned long
F_54 ( int V_82 )
{
F_43 ( free ) ;
unsigned long V_86 ;
F_7 ( & V_79 ) ;
V_86 = F_50 ( & free , V_82 ) ;
F_8 ( & V_79 ) ;
F_37 ( & free ) ;
return V_86 ;
}
static unsigned long
F_55 ( struct V_89 * V_90 , struct V_91 * V_92 )
{
if ( ( V_92 -> V_93 & V_61 ) != V_61 )
return V_88 ;
if ( F_38 ( & V_94 ) )
return V_88 ;
return F_54 ( V_92 -> V_82 ) ;
}
static unsigned long
F_56 ( struct V_89 * V_90 , struct V_91 * V_92 )
{
return V_81 * V_95 / 100 ;
}
static void
F_57 ( void )
{
unsigned long V_96 ;
unsigned int V_82 ;
if ( V_81 <= V_97 )
return;
V_96 = V_81 - V_97 ;
V_82 = 100 ;
if ( V_96 < V_82 )
V_82 = V_96 ;
F_54 ( V_82 ) ;
}
struct V_48 *
F_58 ( struct V_37 * V_41 , struct V_98 * V_99 ,
int V_100 , T_4 V_101 )
{
F_43 ( free ) ;
struct V_58 * V_77 = V_41 -> V_55 ;
struct V_48 * V_49 = NULL ,
* V_102 , * V_59 ;
unsigned int V_103 ;
V_103 = V_41 -> V_46 -> V_104 ( V_99 , V_77 -> V_63 ) ;
F_59 () ;
F_60 (entry, &cache->hashtable[nr], cr_hash) {
if ( ! V_102 -> V_70 -> V_105 ( V_99 , V_102 , V_100 ) )
continue;
if ( V_100 & V_106 ) {
if ( F_53 ( V_51 , & V_102 -> V_52 ) &&
! F_53 ( V_107 , & V_102 -> V_52 ) )
V_49 = V_102 ;
break;
}
F_7 ( & V_77 -> V_56 ) ;
if ( F_53 ( V_51 , & V_102 -> V_52 ) == 0 ) {
F_8 ( & V_77 -> V_56 ) ;
continue;
}
V_49 = F_46 ( V_102 ) ;
F_8 ( & V_77 -> V_56 ) ;
break;
}
F_61 () ;
if ( V_49 != NULL )
goto V_108;
if ( V_100 & V_106 )
return F_19 ( - V_109 ) ;
V_59 = V_41 -> V_46 -> V_110 ( V_41 , V_99 , V_100 , V_101 ) ;
if ( F_20 ( V_59 ) ) {
V_49 = V_59 ;
goto V_42;
}
F_7 ( & V_77 -> V_56 ) ;
F_62 (entry, &cache->hashtable[nr], cr_hash) {
if ( ! V_102 -> V_70 -> V_105 ( V_99 , V_102 , V_100 ) )
continue;
V_49 = F_46 ( V_102 ) ;
break;
}
if ( V_49 == NULL ) {
V_49 = V_59 ;
F_63 ( V_51 , & V_49 -> V_52 ) ;
F_64 ( & V_49 -> V_50 , & V_77 -> V_65 [ V_103 ] ) ;
} else
F_48 ( & V_59 -> V_76 , & free ) ;
F_8 ( & V_77 -> V_56 ) ;
F_57 () ;
V_108:
if ( F_53 ( V_107 , & V_49 -> V_52 ) &&
V_49 -> V_70 -> V_111 != NULL &&
! ( V_100 & V_112 ) ) {
int V_113 = V_49 -> V_70 -> V_111 ( V_41 , V_49 ) ;
if ( V_113 < 0 ) {
F_41 ( V_49 ) ;
V_49 = F_19 ( V_113 ) ;
}
}
F_37 ( & free ) ;
V_42:
return V_49 ;
}
struct V_48 *
F_65 ( struct V_37 * V_41 , int V_100 )
{
struct V_98 V_99 ;
struct V_48 * V_6 ;
const struct V_49 * V_49 = F_66 () ;
F_17 ( L_4 ,
V_41 -> V_46 -> V_114 ) ;
memset ( & V_99 , 0 , sizeof( V_99 ) ) ;
V_99 . V_115 = V_49 -> V_116 ;
V_99 . V_117 = V_49 -> V_118 ;
V_99 . V_119 = V_49 -> V_119 ;
V_6 = V_41 -> V_46 -> V_120 ( V_41 , & V_99 , V_100 ) ;
return V_6 ;
}
void
F_67 ( struct V_48 * V_49 , const struct V_98 * V_99 ,
struct V_37 * V_41 , const struct V_121 * V_16 )
{
F_68 ( & V_49 -> V_50 ) ;
F_69 ( & V_49 -> V_76 ) ;
F_70 ( & V_49 -> V_57 , 1 ) ;
V_49 -> V_54 = V_41 ;
V_49 -> V_70 = V_16 ;
V_49 -> V_87 = V_84 ;
V_49 -> V_122 = V_99 -> V_115 ;
}
struct V_48 *
F_71 ( struct V_123 * V_124 , struct V_48 * V_49 , int V_125 )
{
F_17 ( L_5 , V_124 -> V_126 ,
V_49 -> V_54 -> V_46 -> V_114 , V_49 ) ;
return F_46 ( V_49 ) ;
}
static struct V_48 *
F_72 ( struct V_123 * V_124 , int V_125 )
{
struct V_37 * V_41 = V_124 -> V_127 -> V_44 ;
struct V_98 V_99 = {
. V_115 = V_128 ,
. V_117 = V_129 ,
} ;
F_17 ( L_6 ,
V_124 -> V_126 , V_124 -> V_127 -> V_44 -> V_46 -> V_114 ) ;
return V_41 -> V_46 -> V_120 ( V_41 , & V_99 , V_125 ) ;
}
static struct V_48 *
F_73 ( struct V_123 * V_124 , int V_125 )
{
struct V_37 * V_41 = V_124 -> V_127 -> V_44 ;
F_17 ( L_6 ,
V_124 -> V_126 , V_41 -> V_46 -> V_114 ) ;
return F_65 ( V_41 , V_125 ) ;
}
static int
F_74 ( struct V_123 * V_124 , struct V_48 * V_49 , int V_100 )
{
struct V_130 * V_131 = V_124 -> V_132 ;
struct V_48 * V_59 ;
int V_125 = 0 ;
if ( V_100 & V_133 )
V_125 |= V_112 ;
if ( V_49 != NULL )
V_59 = V_49 -> V_70 -> V_134 ( V_124 , V_49 , V_125 ) ;
else if ( V_100 & V_135 )
V_59 = F_72 ( V_124 , V_125 ) ;
else
V_59 = F_73 ( V_124 , V_125 ) ;
if ( F_20 ( V_59 ) )
return F_75 ( V_59 ) ;
F_41 ( V_131 -> V_136 ) ;
V_131 -> V_136 = V_59 ;
return 0 ;
}
void
F_41 ( struct V_48 * V_49 )
{
if ( V_49 == NULL )
return;
if ( F_53 ( V_51 , & V_49 -> V_52 ) == 0 ) {
if ( F_22 ( & V_49 -> V_57 ) )
V_49 -> V_70 -> V_137 ( V_49 ) ;
return;
}
if ( ! F_76 ( & V_49 -> V_57 , & V_79 ) )
return;
if ( ! F_38 ( & V_49 -> V_76 ) ) {
V_81 -- ;
F_40 ( & V_49 -> V_76 ) ;
}
if ( F_53 ( V_51 , & V_49 -> V_52 ) != 0 ) {
if ( F_53 ( V_138 , & V_49 -> V_52 ) != 0 ) {
V_49 -> V_87 = V_84 ;
F_48 ( & V_49 -> V_76 , & V_94 ) ;
V_81 ++ ;
goto V_139;
}
if ( ! F_27 ( V_49 ) ) {
goto V_139;
}
}
F_8 ( & V_79 ) ;
V_49 -> V_70 -> V_137 ( V_49 ) ;
return;
V_139:
F_8 ( & V_79 ) ;
}
T_5 *
F_77 ( struct V_123 * V_124 , T_5 * V_140 )
{
struct V_48 * V_49 = V_124 -> V_132 -> V_136 ;
F_17 ( L_7 ,
V_124 -> V_126 , V_49 -> V_54 -> V_46 -> V_114 , V_49 ) ;
return V_49 -> V_70 -> V_141 ( V_124 , V_140 ) ;
}
T_5 *
F_78 ( struct V_123 * V_124 , T_5 * V_140 )
{
struct V_48 * V_49 = V_124 -> V_132 -> V_136 ;
F_17 ( L_8 ,
V_124 -> V_126 , V_49 -> V_54 -> V_46 -> V_114 , V_49 ) ;
return V_49 -> V_70 -> V_142 ( V_124 , V_140 ) ;
}
static void F_79 ( T_6 V_143 , struct V_130 * V_144 ,
T_5 * V_145 , void * V_146 )
{
struct V_147 V_148 ;
F_80 ( & V_148 , & V_144 -> V_149 , V_145 ) ;
V_143 ( V_144 , & V_148 , V_146 ) ;
}
int
F_81 ( struct V_123 * V_124 , T_6 V_143 , void * V_144 ,
T_5 * V_145 , void * V_146 )
{
struct V_48 * V_49 = V_124 -> V_132 -> V_136 ;
F_17 ( L_9 ,
V_124 -> V_126 , V_49 -> V_70 -> V_150 , V_49 ) ;
if ( V_49 -> V_70 -> V_151 )
return V_49 -> V_70 -> V_151 ( V_124 , V_143 , V_144 , V_145 , V_146 ) ;
F_79 ( V_143 , V_144 , V_145 , V_146 ) ;
return 0 ;
}
static int
F_82 ( T_7 V_152 , struct V_130 * V_144 ,
T_5 * V_145 , void * V_146 )
{
struct V_147 V_148 ;
F_83 ( & V_148 , & V_144 -> V_153 , V_145 ) ;
return V_152 ( V_144 , & V_148 , V_146 ) ;
}
int
F_84 ( struct V_123 * V_124 , T_7 V_152 , void * V_144 ,
T_5 * V_145 , void * V_146 )
{
struct V_48 * V_49 = V_124 -> V_132 -> V_136 ;
F_17 ( L_10 ,
V_124 -> V_126 , V_49 -> V_70 -> V_150 , V_49 ) ;
if ( V_49 -> V_70 -> V_154 )
return V_49 -> V_70 -> V_154 ( V_124 , V_152 , V_144 ,
V_145 , V_146 ) ;
return F_82 ( V_152 , V_144 , V_145 , V_146 ) ;
}
int
F_85 ( struct V_123 * V_124 )
{
struct V_48 * V_49 ;
int V_155 ;
V_49 = V_124 -> V_132 -> V_136 ;
if ( V_49 == NULL ) {
V_155 = F_74 ( V_124 , V_124 -> V_156 . V_48 , V_124 -> V_157 ) ;
if ( V_155 < 0 )
goto V_42;
V_49 = V_124 -> V_132 -> V_136 ;
}
F_17 ( L_11 ,
V_124 -> V_126 , V_49 -> V_54 -> V_46 -> V_114 , V_49 ) ;
V_155 = V_49 -> V_70 -> V_158 ( V_124 ) ;
V_42:
if ( V_155 < 0 )
V_124 -> V_159 = V_155 ;
return V_155 ;
}
void
F_86 ( struct V_123 * V_124 )
{
struct V_48 * V_49 = V_124 -> V_132 -> V_136 ;
F_17 ( L_12 ,
V_124 -> V_126 , V_49 -> V_54 -> V_46 -> V_114 , V_49 ) ;
if ( V_49 )
F_26 ( V_138 , & V_49 -> V_52 ) ;
}
int
F_87 ( struct V_123 * V_124 )
{
struct V_48 * V_49 = V_124 -> V_132 -> V_136 ;
return V_49 == NULL ||
F_53 ( V_138 , & V_49 -> V_52 ) != 0 ;
}
int T_8 F_88 ( void )
{
int V_155 ;
V_155 = F_89 () ;
if ( V_155 < 0 )
goto V_160;
V_155 = F_90 () ;
if ( V_155 < 0 )
goto V_161;
V_155 = F_91 ( & V_162 ) ;
if ( V_155 < 0 )
goto V_163;
return 0 ;
V_163:
F_92 () ;
V_161:
F_93 () ;
V_160:
return V_155 ;
}
void F_94 ( void )
{
F_93 () ;
F_92 () ;
F_95 ( & V_162 ) ;
}
