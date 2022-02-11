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
static inline
void F_36 ( struct V_70 * V_71 )
{
struct V_48 * V_49 ;
while ( ! F_37 ( V_71 ) ) {
V_49 = F_38 ( V_71 -> V_72 , struct V_48 , V_73 ) ;
F_39 ( & V_49 -> V_73 ) ;
F_40 ( V_49 ) ;
}
}
void
F_41 ( struct V_58 * V_74 )
{
F_42 ( free ) ;
struct V_75 * V_71 ;
struct V_48 * V_49 ;
unsigned int V_60 = 1U << V_74 -> V_63 ;
int V_32 ;
F_7 ( & V_76 ) ;
F_7 ( & V_74 -> V_56 ) ;
for ( V_32 = 0 ; V_32 < V_60 ; V_32 ++ ) {
V_71 = & V_74 -> V_65 [ V_32 ] ;
while ( ! F_43 ( V_71 ) ) {
V_49 = F_44 ( V_71 -> V_77 , struct V_48 , V_50 ) ;
F_45 ( V_49 ) ;
if ( ! F_37 ( & V_49 -> V_73 ) ) {
F_46 ( & V_49 -> V_73 ) ;
V_78 -- ;
}
F_47 ( & V_49 -> V_73 , & free ) ;
F_23 ( V_49 ) ;
}
}
F_8 ( & V_74 -> V_56 ) ;
F_8 ( & V_76 ) ;
F_36 ( & free ) ;
}
void
F_48 ( struct V_37 * V_41 )
{
struct V_58 * V_74 = V_41 -> V_55 ;
if ( V_74 ) {
V_41 -> V_55 = NULL ;
F_41 ( V_74 ) ;
F_33 ( V_74 -> V_65 ) ;
F_33 ( V_74 ) ;
}
}
static long
F_49 ( struct V_70 * free , int V_79 )
{
T_3 * V_53 ;
struct V_48 * V_49 , * V_72 ;
unsigned long V_80 = V_81 - V_82 ;
long V_83 = 0 ;
F_50 (cred, next, &cred_unused, cr_lru) {
if ( V_79 -- == 0 )
break;
if ( F_51 ( V_49 -> V_84 , V_80 , V_81 ) &&
F_52 ( V_51 , & V_49 -> V_52 ) != 0 )
break;
F_39 ( & V_49 -> V_73 ) ;
V_78 -- ;
V_83 ++ ;
if ( F_28 ( & V_49 -> V_57 ) != 0 )
continue;
V_53 = & V_49 -> V_54 -> V_55 -> V_56 ;
F_7 ( V_53 ) ;
if ( F_28 ( & V_49 -> V_57 ) == 0 ) {
F_45 ( V_49 ) ;
F_47 ( & V_49 -> V_73 , free ) ;
F_23 ( V_49 ) ;
}
F_8 ( V_53 ) ;
}
return V_83 ;
}
static unsigned long
F_53 ( struct V_85 * V_86 , struct V_87 * V_88 )
{
F_42 ( free ) ;
unsigned long V_83 ;
if ( ( V_88 -> V_89 & V_61 ) != V_61 )
return V_90 ;
if ( F_37 ( & V_91 ) )
return V_90 ;
F_7 ( & V_76 ) ;
V_83 = F_49 ( & free , V_88 -> V_79 ) ;
F_8 ( & V_76 ) ;
F_36 ( & free ) ;
return V_83 ;
}
static unsigned long
F_54 ( struct V_85 * V_86 , struct V_87 * V_88 )
{
return ( V_78 / 100 ) * V_92 ;
}
struct V_48 *
F_55 ( struct V_37 * V_41 , struct V_93 * V_94 ,
int V_95 )
{
F_42 ( free ) ;
struct V_58 * V_74 = V_41 -> V_55 ;
struct V_48 * V_49 = NULL ,
* V_96 , * V_59 ;
unsigned int V_97 ;
V_97 = F_56 ( F_57 ( & V_98 , V_94 -> V_99 ) , V_74 -> V_63 ) ;
F_58 () ;
F_59 (entry, &cache->hashtable[nr], cr_hash) {
if ( ! V_96 -> V_68 -> V_100 ( V_94 , V_96 , V_95 ) )
continue;
F_7 ( & V_74 -> V_56 ) ;
if ( F_52 ( V_51 , & V_96 -> V_52 ) == 0 ) {
F_8 ( & V_74 -> V_56 ) ;
continue;
}
V_49 = F_45 ( V_96 ) ;
F_8 ( & V_74 -> V_56 ) ;
break;
}
F_60 () ;
if ( V_49 != NULL )
goto V_101;
V_59 = V_41 -> V_46 -> V_102 ( V_41 , V_94 , V_95 ) ;
if ( F_20 ( V_59 ) ) {
V_49 = V_59 ;
goto V_42;
}
F_7 ( & V_74 -> V_56 ) ;
F_61 (entry, &cache->hashtable[nr], cr_hash) {
if ( ! V_96 -> V_68 -> V_100 ( V_94 , V_96 , V_95 ) )
continue;
V_49 = F_45 ( V_96 ) ;
break;
}
if ( V_49 == NULL ) {
V_49 = V_59 ;
F_62 ( V_51 , & V_49 -> V_52 ) ;
F_63 ( & V_49 -> V_50 , & V_74 -> V_65 [ V_97 ] ) ;
} else
F_47 ( & V_59 -> V_73 , & free ) ;
F_8 ( & V_74 -> V_56 ) ;
V_101:
if ( F_52 ( V_103 , & V_49 -> V_52 ) &&
V_49 -> V_68 -> V_104 != NULL &&
! ( V_95 & V_105 ) ) {
int V_106 = V_49 -> V_68 -> V_104 ( V_41 , V_49 ) ;
if ( V_106 < 0 ) {
F_40 ( V_49 ) ;
V_49 = F_19 ( V_106 ) ;
}
}
F_36 ( & free ) ;
V_42:
return V_49 ;
}
struct V_48 *
F_64 ( struct V_37 * V_41 , int V_95 )
{
struct V_93 V_94 ;
struct V_48 * V_6 ;
const struct V_49 * V_49 = F_65 () ;
F_17 ( L_4 ,
V_41 -> V_46 -> V_107 ) ;
memset ( & V_94 , 0 , sizeof( V_94 ) ) ;
V_94 . V_99 = V_49 -> V_108 ;
V_94 . V_109 = V_49 -> V_110 ;
V_94 . V_111 = F_66 ( ( (struct V_49 * ) V_49 ) -> V_111 ) ;
V_6 = V_41 -> V_46 -> V_112 ( V_41 , & V_94 , V_95 ) ;
F_67 ( V_94 . V_111 ) ;
return V_6 ;
}
void
F_68 ( struct V_48 * V_49 , const struct V_93 * V_94 ,
struct V_37 * V_41 , const struct V_113 * V_16 )
{
F_69 ( & V_49 -> V_50 ) ;
F_70 ( & V_49 -> V_73 ) ;
F_71 ( & V_49 -> V_57 , 1 ) ;
V_49 -> V_54 = V_41 ;
V_49 -> V_68 = V_16 ;
V_49 -> V_84 = V_81 ;
#ifdef F_72
V_49 -> V_114 = V_115 ;
#endif
V_49 -> V_116 = V_94 -> V_99 ;
}
struct V_48 *
F_73 ( struct V_117 * V_118 , struct V_48 * V_49 , int V_119 )
{
F_17 ( L_5 , V_118 -> V_120 ,
V_49 -> V_54 -> V_46 -> V_107 , V_49 ) ;
return F_45 ( V_49 ) ;
}
static struct V_48 *
F_74 ( struct V_117 * V_118 , int V_119 )
{
struct V_37 * V_41 = V_118 -> V_121 -> V_44 ;
struct V_93 V_94 = {
. V_99 = V_122 ,
. V_109 = V_123 ,
} ;
F_17 ( L_6 ,
V_118 -> V_120 , V_118 -> V_121 -> V_44 -> V_46 -> V_107 ) ;
return V_41 -> V_46 -> V_112 ( V_41 , & V_94 , V_119 ) ;
}
static struct V_48 *
F_75 ( struct V_117 * V_118 , int V_119 )
{
struct V_37 * V_41 = V_118 -> V_121 -> V_44 ;
F_17 ( L_6 ,
V_118 -> V_120 , V_41 -> V_46 -> V_107 ) ;
return F_64 ( V_41 , V_119 ) ;
}
static int
F_76 ( struct V_117 * V_118 , struct V_48 * V_49 , int V_95 )
{
struct V_124 * V_125 = V_118 -> V_126 ;
struct V_48 * V_59 ;
int V_119 = 0 ;
if ( V_95 & V_127 )
V_119 |= V_105 ;
if ( V_49 != NULL )
V_59 = V_49 -> V_68 -> V_128 ( V_118 , V_49 , V_119 ) ;
else if ( V_95 & V_129 )
V_59 = F_74 ( V_118 , V_119 ) ;
else
V_59 = F_75 ( V_118 , V_119 ) ;
if ( F_20 ( V_59 ) )
return F_77 ( V_59 ) ;
if ( V_125 -> V_130 != NULL )
F_40 ( V_125 -> V_130 ) ;
V_125 -> V_130 = V_59 ;
return 0 ;
}
void
F_40 ( struct V_48 * V_49 )
{
if ( F_52 ( V_51 , & V_49 -> V_52 ) == 0 ) {
if ( F_22 ( & V_49 -> V_57 ) )
V_49 -> V_68 -> V_131 ( V_49 ) ;
return;
}
if ( ! F_78 ( & V_49 -> V_57 , & V_76 ) )
return;
if ( ! F_37 ( & V_49 -> V_73 ) ) {
V_78 -- ;
F_39 ( & V_49 -> V_73 ) ;
}
if ( F_52 ( V_51 , & V_49 -> V_52 ) != 0 ) {
if ( F_52 ( V_132 , & V_49 -> V_52 ) != 0 ) {
V_49 -> V_84 = V_81 ;
F_47 ( & V_49 -> V_73 , & V_91 ) ;
V_78 ++ ;
goto V_133;
}
if ( ! F_27 ( V_49 ) ) {
goto V_133;
}
}
F_8 ( & V_76 ) ;
V_49 -> V_68 -> V_131 ( V_49 ) ;
return;
V_133:
F_8 ( & V_76 ) ;
}
T_4 *
F_79 ( struct V_117 * V_118 , T_4 * V_134 )
{
struct V_48 * V_49 = V_118 -> V_126 -> V_130 ;
F_17 ( L_7 ,
V_118 -> V_120 , V_49 -> V_54 -> V_46 -> V_107 , V_49 ) ;
return V_49 -> V_68 -> V_135 ( V_118 , V_134 ) ;
}
T_4 *
F_80 ( struct V_117 * V_118 , T_4 * V_134 )
{
struct V_48 * V_49 = V_118 -> V_126 -> V_130 ;
F_17 ( L_8 ,
V_118 -> V_120 , V_49 -> V_54 -> V_46 -> V_107 , V_49 ) ;
return V_49 -> V_68 -> V_136 ( V_118 , V_134 ) ;
}
static void F_81 ( T_5 V_137 , struct V_124 * V_138 ,
T_4 * V_139 , void * V_140 )
{
struct V_141 V_142 ;
F_82 ( & V_142 , & V_138 -> V_143 , V_139 ) ;
V_137 ( V_138 , & V_142 , V_140 ) ;
}
int
F_83 ( struct V_117 * V_118 , T_5 V_137 , void * V_138 ,
T_4 * V_139 , void * V_140 )
{
struct V_48 * V_49 = V_118 -> V_126 -> V_130 ;
F_17 ( L_9 ,
V_118 -> V_120 , V_49 -> V_68 -> V_144 , V_49 ) ;
if ( V_49 -> V_68 -> V_145 )
return V_49 -> V_68 -> V_145 ( V_118 , V_137 , V_138 , V_139 , V_140 ) ;
F_81 ( V_137 , V_138 , V_139 , V_140 ) ;
return 0 ;
}
static int
F_84 ( T_6 V_146 , struct V_124 * V_138 ,
T_4 * V_139 , void * V_140 )
{
struct V_141 V_142 ;
F_85 ( & V_142 , & V_138 -> V_147 , V_139 ) ;
return V_146 ( V_138 , & V_142 , V_140 ) ;
}
int
F_86 ( struct V_117 * V_118 , T_6 V_146 , void * V_138 ,
T_4 * V_139 , void * V_140 )
{
struct V_48 * V_49 = V_118 -> V_126 -> V_130 ;
F_17 ( L_10 ,
V_118 -> V_120 , V_49 -> V_68 -> V_144 , V_49 ) ;
if ( V_49 -> V_68 -> V_148 )
return V_49 -> V_68 -> V_148 ( V_118 , V_146 , V_138 ,
V_139 , V_140 ) ;
return F_84 ( V_146 , V_138 , V_139 , V_140 ) ;
}
int
F_87 ( struct V_117 * V_118 )
{
struct V_48 * V_49 ;
int V_149 ;
V_49 = V_118 -> V_126 -> V_130 ;
if ( V_49 == NULL ) {
V_149 = F_76 ( V_118 , V_118 -> V_150 . V_48 , V_118 -> V_151 ) ;
if ( V_149 < 0 )
goto V_42;
V_49 = V_118 -> V_126 -> V_130 ;
}
F_17 ( L_11 ,
V_118 -> V_120 , V_49 -> V_54 -> V_46 -> V_107 , V_49 ) ;
V_149 = V_49 -> V_68 -> V_152 ( V_118 ) ;
V_42:
if ( V_149 < 0 )
V_118 -> V_153 = V_149 ;
return V_149 ;
}
void
F_88 ( struct V_117 * V_118 )
{
struct V_48 * V_49 = V_118 -> V_126 -> V_130 ;
F_17 ( L_12 ,
V_118 -> V_120 , V_49 -> V_54 -> V_46 -> V_107 , V_49 ) ;
if ( V_49 )
F_26 ( V_132 , & V_49 -> V_52 ) ;
}
int
F_89 ( struct V_117 * V_118 )
{
struct V_48 * V_49 = V_118 -> V_126 -> V_130 ;
return V_49 == NULL ||
F_52 ( V_132 , & V_49 -> V_52 ) != 0 ;
}
int T_7 F_90 ( void )
{
int V_149 ;
V_149 = F_91 () ;
if ( V_149 < 0 )
goto V_154;
V_149 = F_92 () ;
if ( V_149 < 0 )
goto V_155;
F_93 ( & V_156 ) ;
return 0 ;
V_155:
F_94 () ;
V_154:
return V_149 ;
}
void F_95 ( void )
{
F_94 () ;
F_96 () ;
F_97 ( & V_156 ) ;
}
