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
F_18 ( T_2 V_23 , struct V_38 * V_39 )
{
struct V_37 * V_40 ;
const struct V_15 * V_16 ;
T_1 V_12 = F_5 ( V_23 ) ;
V_40 = F_19 ( - V_8 ) ;
if ( V_12 >= V_13 )
goto V_41;
if ( ( V_16 = V_20 [ V_12 ] ) == NULL )
F_11 ( L_2 , V_12 ) ;
F_7 ( & V_19 ) ;
V_16 = V_20 [ V_12 ] ;
if ( V_16 == NULL || ! F_12 ( V_16 -> V_24 ) ) {
F_8 ( & V_19 ) ;
goto V_41;
}
F_8 ( & V_19 ) ;
V_40 = V_16 -> V_42 ( V_39 , V_23 ) ;
F_13 ( V_16 -> V_24 ) ;
if ( F_20 ( V_40 ) )
return V_40 ;
if ( V_39 -> V_43 )
F_21 ( V_39 -> V_43 ) ;
V_39 -> V_43 = V_40 ;
V_41:
return V_40 ;
}
void
F_21 ( struct V_37 * V_40 )
{
if ( ! F_22 ( & V_40 -> V_44 ) )
return;
V_40 -> V_45 -> V_46 ( V_40 ) ;
}
static void
F_23 ( struct V_47 * V_48 )
{
F_24 ( & V_48 -> V_49 ) ;
F_25 () ;
F_26 ( V_50 , & V_48 -> V_51 ) ;
}
static int
F_27 ( struct V_47 * V_48 )
{
T_3 * V_52 ;
int V_6 ;
V_52 = & V_48 -> V_53 -> V_54 -> V_55 ;
F_7 ( V_52 ) ;
V_6 = F_28 ( & V_48 -> V_56 ) == 0 ;
if ( V_6 )
F_23 ( V_48 ) ;
F_8 ( V_52 ) ;
return V_6 ;
}
int
F_29 ( struct V_37 * V_40 )
{
struct V_57 * V_58 ;
unsigned int V_59 ;
V_58 = F_30 ( sizeof( * V_58 ) , V_60 ) ;
if ( ! V_58 )
goto V_61;
V_58 -> V_62 = V_63 ;
V_59 = 1U << V_58 -> V_62 ;
V_58 -> V_64 = F_31 ( V_59 , sizeof( V_58 -> V_64 [ 0 ] ) , V_60 ) ;
if ( ! V_58 -> V_64 )
goto V_65;
F_32 ( & V_58 -> V_55 ) ;
V_40 -> V_54 = V_58 ;
return 0 ;
V_65:
F_33 ( V_58 ) ;
V_61:
return - V_34 ;
}
static inline
void F_34 ( struct V_66 * V_67 )
{
struct V_47 * V_48 ;
while ( ! F_35 ( V_67 ) ) {
V_48 = F_36 ( V_67 -> V_68 , struct V_47 , V_69 ) ;
F_37 ( & V_48 -> V_69 ) ;
F_38 ( V_48 ) ;
}
}
void
F_39 ( struct V_57 * V_70 )
{
F_40 ( free ) ;
struct V_71 * V_67 ;
struct V_47 * V_48 ;
unsigned int V_59 = 1U << V_70 -> V_62 ;
int V_32 ;
F_7 ( & V_72 ) ;
F_7 ( & V_70 -> V_55 ) ;
for ( V_32 = 0 ; V_32 < V_59 ; V_32 ++ ) {
V_67 = & V_70 -> V_64 [ V_32 ] ;
while ( ! F_41 ( V_67 ) ) {
V_48 = F_42 ( V_67 -> V_73 , struct V_47 , V_49 ) ;
F_43 ( V_48 ) ;
if ( ! F_35 ( & V_48 -> V_69 ) ) {
F_44 ( & V_48 -> V_69 ) ;
V_74 -- ;
}
F_45 ( & V_48 -> V_69 , & free ) ;
F_23 ( V_48 ) ;
}
}
F_8 ( & V_70 -> V_55 ) ;
F_8 ( & V_72 ) ;
F_34 ( & free ) ;
}
void
F_46 ( struct V_37 * V_40 )
{
struct V_57 * V_70 = V_40 -> V_54 ;
if ( V_70 ) {
V_40 -> V_54 = NULL ;
F_39 ( V_70 ) ;
F_33 ( V_70 -> V_64 ) ;
F_33 ( V_70 ) ;
}
}
static int
F_47 ( struct V_66 * free , int V_75 )
{
T_3 * V_52 ;
struct V_47 * V_48 , * V_68 ;
unsigned long V_76 = V_77 - V_78 ;
F_48 (cred, next, &cred_unused, cr_lru) {
if ( V_75 -- == 0 )
break;
if ( F_49 ( V_48 -> V_79 , V_76 , V_77 ) &&
F_50 ( V_50 , & V_48 -> V_51 ) != 0 )
return 0 ;
F_37 ( & V_48 -> V_69 ) ;
V_74 -- ;
if ( F_28 ( & V_48 -> V_56 ) != 0 )
continue;
V_52 = & V_48 -> V_53 -> V_54 -> V_55 ;
F_7 ( V_52 ) ;
if ( F_28 ( & V_48 -> V_56 ) == 0 ) {
F_43 ( V_48 ) ;
F_45 ( & V_48 -> V_69 , free ) ;
F_23 ( V_48 ) ;
}
F_8 ( V_52 ) ;
}
return ( V_74 / 100 ) * V_80 ;
}
static int
F_51 ( struct V_81 * V_82 , struct V_83 * V_84 )
{
F_40 ( free ) ;
int V_85 ;
int V_75 = V_84 -> V_75 ;
T_4 V_86 = V_84 -> V_86 ;
if ( ( V_86 & V_60 ) != V_60 )
return ( V_75 == 0 ) ? 0 : - 1 ;
if ( F_35 ( & V_87 ) )
return 0 ;
F_7 ( & V_72 ) ;
V_85 = F_47 ( & free , V_75 ) ;
F_8 ( & V_72 ) ;
F_34 ( & free ) ;
return V_85 ;
}
struct V_47 *
F_52 ( struct V_37 * V_40 , struct V_88 * V_89 ,
int V_90 )
{
F_40 ( free ) ;
struct V_57 * V_70 = V_40 -> V_54 ;
struct V_47 * V_48 = NULL ,
* V_91 , * V_58 ;
unsigned int V_92 ;
V_92 = F_53 ( F_54 ( & V_93 , V_89 -> V_94 ) , V_70 -> V_62 ) ;
F_55 () ;
F_56 (entry, &cache->hashtable[nr], cr_hash) {
if ( ! V_91 -> V_95 -> V_96 ( V_89 , V_91 , V_90 ) )
continue;
F_7 ( & V_70 -> V_55 ) ;
if ( F_50 ( V_50 , & V_91 -> V_51 ) == 0 ) {
F_8 ( & V_70 -> V_55 ) ;
continue;
}
V_48 = F_43 ( V_91 ) ;
F_8 ( & V_70 -> V_55 ) ;
break;
}
F_57 () ;
if ( V_48 != NULL )
goto V_97;
V_58 = V_40 -> V_45 -> V_98 ( V_40 , V_89 , V_90 ) ;
if ( F_20 ( V_58 ) ) {
V_48 = V_58 ;
goto V_41;
}
F_7 ( & V_70 -> V_55 ) ;
F_58 (entry, &cache->hashtable[nr], cr_hash) {
if ( ! V_91 -> V_95 -> V_96 ( V_89 , V_91 , V_90 ) )
continue;
V_48 = F_43 ( V_91 ) ;
break;
}
if ( V_48 == NULL ) {
V_48 = V_58 ;
F_59 ( V_50 , & V_48 -> V_51 ) ;
F_60 ( & V_48 -> V_49 , & V_70 -> V_64 [ V_92 ] ) ;
} else
F_45 ( & V_58 -> V_69 , & free ) ;
F_8 ( & V_70 -> V_55 ) ;
V_97:
if ( F_50 ( V_99 , & V_48 -> V_51 ) &&
V_48 -> V_95 -> V_100 != NULL &&
! ( V_90 & V_101 ) ) {
int V_85 = V_48 -> V_95 -> V_100 ( V_40 , V_48 ) ;
if ( V_85 < 0 ) {
F_38 ( V_48 ) ;
V_48 = F_19 ( V_85 ) ;
}
}
F_34 ( & free ) ;
V_41:
return V_48 ;
}
struct V_47 *
F_61 ( struct V_37 * V_40 , int V_90 )
{
struct V_88 V_89 ;
struct V_47 * V_6 ;
const struct V_48 * V_48 = F_62 () ;
F_17 ( L_4 ,
V_40 -> V_45 -> V_102 ) ;
memset ( & V_89 , 0 , sizeof( V_89 ) ) ;
V_89 . V_94 = V_48 -> V_103 ;
V_89 . V_104 = V_48 -> V_105 ;
V_89 . V_106 = F_63 ( ( (struct V_48 * ) V_48 ) -> V_106 ) ;
V_6 = V_40 -> V_45 -> V_107 ( V_40 , & V_89 , V_90 ) ;
F_64 ( V_89 . V_106 ) ;
return V_6 ;
}
void
F_65 ( struct V_47 * V_48 , const struct V_88 * V_89 ,
struct V_37 * V_40 , const struct V_108 * V_16 )
{
F_66 ( & V_48 -> V_49 ) ;
F_67 ( & V_48 -> V_69 ) ;
F_68 ( & V_48 -> V_56 , 1 ) ;
V_48 -> V_53 = V_40 ;
V_48 -> V_95 = V_16 ;
V_48 -> V_79 = V_77 ;
#ifdef F_69
V_48 -> V_109 = V_110 ;
#endif
V_48 -> V_111 = V_89 -> V_94 ;
}
struct V_47 *
F_70 ( struct V_112 * V_113 , struct V_47 * V_48 , int V_114 )
{
F_17 ( L_5 , V_113 -> V_115 ,
V_48 -> V_53 -> V_45 -> V_102 , V_48 ) ;
return F_43 ( V_48 ) ;
}
static struct V_47 *
F_71 ( struct V_112 * V_113 , int V_114 )
{
struct V_37 * V_40 = V_113 -> V_116 -> V_43 ;
struct V_88 V_89 = {
. V_94 = V_117 ,
. V_104 = V_118 ,
} ;
F_17 ( L_6 ,
V_113 -> V_115 , V_113 -> V_116 -> V_43 -> V_45 -> V_102 ) ;
return V_40 -> V_45 -> V_107 ( V_40 , & V_89 , V_114 ) ;
}
static struct V_47 *
F_72 ( struct V_112 * V_113 , int V_114 )
{
struct V_37 * V_40 = V_113 -> V_116 -> V_43 ;
F_17 ( L_6 ,
V_113 -> V_115 , V_40 -> V_45 -> V_102 ) ;
return F_61 ( V_40 , V_114 ) ;
}
static int
F_73 ( struct V_112 * V_113 , struct V_47 * V_48 , int V_90 )
{
struct V_119 * V_120 = V_113 -> V_121 ;
struct V_47 * V_58 ;
int V_114 = 0 ;
if ( V_90 & V_122 )
V_114 |= V_101 ;
if ( V_48 != NULL )
V_58 = V_48 -> V_95 -> V_123 ( V_113 , V_48 , V_114 ) ;
else if ( V_90 & V_124 )
V_58 = F_71 ( V_113 , V_114 ) ;
else
V_58 = F_72 ( V_113 , V_114 ) ;
if ( F_20 ( V_58 ) )
return F_74 ( V_58 ) ;
if ( V_120 -> V_125 != NULL )
F_38 ( V_120 -> V_125 ) ;
V_120 -> V_125 = V_58 ;
return 0 ;
}
void
F_38 ( struct V_47 * V_48 )
{
if ( F_50 ( V_50 , & V_48 -> V_51 ) == 0 ) {
if ( F_22 ( & V_48 -> V_56 ) )
V_48 -> V_95 -> V_126 ( V_48 ) ;
return;
}
if ( ! F_75 ( & V_48 -> V_56 , & V_72 ) )
return;
if ( ! F_35 ( & V_48 -> V_69 ) ) {
V_74 -- ;
F_37 ( & V_48 -> V_69 ) ;
}
if ( F_50 ( V_50 , & V_48 -> V_51 ) != 0 ) {
if ( F_50 ( V_127 , & V_48 -> V_51 ) != 0 ) {
V_48 -> V_79 = V_77 ;
F_45 ( & V_48 -> V_69 , & V_87 ) ;
V_74 ++ ;
goto V_128;
}
if ( ! F_27 ( V_48 ) ) {
goto V_128;
}
}
F_8 ( & V_72 ) ;
V_48 -> V_95 -> V_126 ( V_48 ) ;
return;
V_128:
F_8 ( & V_72 ) ;
}
T_5 *
F_76 ( struct V_112 * V_113 , T_5 * V_129 )
{
struct V_47 * V_48 = V_113 -> V_121 -> V_125 ;
F_17 ( L_7 ,
V_113 -> V_115 , V_48 -> V_53 -> V_45 -> V_102 , V_48 ) ;
return V_48 -> V_95 -> V_130 ( V_113 , V_129 ) ;
}
T_5 *
F_77 ( struct V_112 * V_113 , T_5 * V_129 )
{
struct V_47 * V_48 = V_113 -> V_121 -> V_125 ;
F_17 ( L_8 ,
V_113 -> V_115 , V_48 -> V_53 -> V_45 -> V_102 , V_48 ) ;
return V_48 -> V_95 -> V_131 ( V_113 , V_129 ) ;
}
static void F_78 ( T_6 V_132 , struct V_119 * V_133 ,
T_5 * V_134 , void * V_135 )
{
struct V_136 V_137 ;
F_79 ( & V_137 , & V_133 -> V_138 , V_134 ) ;
V_132 ( V_133 , & V_137 , V_135 ) ;
}
int
F_80 ( struct V_112 * V_113 , T_6 V_132 , void * V_133 ,
T_5 * V_134 , void * V_135 )
{
struct V_47 * V_48 = V_113 -> V_121 -> V_125 ;
F_17 ( L_9 ,
V_113 -> V_115 , V_48 -> V_95 -> V_139 , V_48 ) ;
if ( V_48 -> V_95 -> V_140 )
return V_48 -> V_95 -> V_140 ( V_113 , V_132 , V_133 , V_134 , V_135 ) ;
F_78 ( V_132 , V_133 , V_134 , V_135 ) ;
return 0 ;
}
static int
F_81 ( T_7 V_141 , struct V_119 * V_133 ,
T_5 * V_134 , void * V_135 )
{
struct V_136 V_137 ;
F_82 ( & V_137 , & V_133 -> V_142 , V_134 ) ;
return V_141 ( V_133 , & V_137 , V_135 ) ;
}
int
F_83 ( struct V_112 * V_113 , T_7 V_141 , void * V_133 ,
T_5 * V_134 , void * V_135 )
{
struct V_47 * V_48 = V_113 -> V_121 -> V_125 ;
F_17 ( L_10 ,
V_113 -> V_115 , V_48 -> V_95 -> V_139 , V_48 ) ;
if ( V_48 -> V_95 -> V_143 )
return V_48 -> V_95 -> V_143 ( V_113 , V_141 , V_133 ,
V_134 , V_135 ) ;
return F_81 ( V_141 , V_133 , V_134 , V_135 ) ;
}
int
F_84 ( struct V_112 * V_113 )
{
struct V_47 * V_48 ;
int V_144 ;
V_48 = V_113 -> V_121 -> V_125 ;
if ( V_48 == NULL ) {
V_144 = F_73 ( V_113 , V_113 -> V_145 . V_47 , V_113 -> V_146 ) ;
if ( V_144 < 0 )
goto V_41;
V_48 = V_113 -> V_121 -> V_125 ;
}
F_17 ( L_11 ,
V_113 -> V_115 , V_48 -> V_53 -> V_45 -> V_102 , V_48 ) ;
V_144 = V_48 -> V_95 -> V_147 ( V_113 ) ;
V_41:
if ( V_144 < 0 )
V_113 -> V_148 = V_144 ;
return V_144 ;
}
void
F_85 ( struct V_112 * V_113 )
{
struct V_47 * V_48 = V_113 -> V_121 -> V_125 ;
F_17 ( L_12 ,
V_113 -> V_115 , V_48 -> V_53 -> V_45 -> V_102 , V_48 ) ;
if ( V_48 )
F_26 ( V_127 , & V_48 -> V_51 ) ;
}
int
F_86 ( struct V_112 * V_113 )
{
struct V_47 * V_48 = V_113 -> V_121 -> V_125 ;
return V_48 == NULL ||
F_50 ( V_127 , & V_48 -> V_51 ) != 0 ;
}
int T_8 F_87 ( void )
{
int V_144 ;
V_144 = F_88 () ;
if ( V_144 < 0 )
goto V_149;
V_144 = F_89 () ;
if ( V_144 < 0 )
goto V_150;
F_90 ( & V_151 ) ;
return 0 ;
V_150:
F_91 () ;
V_149:
return V_144 ;
}
void F_92 ( void )
{
F_91 () ;
F_93 () ;
F_94 ( & V_151 ) ;
}
