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
if ( V_12 >= V_13 )
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
int
F_10 ( T_2 * V_21 , int V_22 )
{
T_2 V_12 ;
int V_23 = 0 ;
F_7 ( & V_19 ) ;
for ( V_12 = 0 ; V_12 < V_13 ; V_12 ++ ) {
const struct V_15 * V_16 = V_20 [ V_12 ] ;
T_2 V_24 [ 4 ] ;
int V_25 , V_26 ;
if ( V_23 >= V_22 ) {
V_23 = - V_27 ;
break;
}
if ( V_16 == NULL )
continue;
if ( V_16 -> V_28 == NULL ) {
V_21 [ V_23 ++ ] = V_16 -> V_18 ;
continue;
}
V_26 = V_16 -> V_28 ( V_24 , F_11 ( V_24 ) ) ;
if ( V_26 < 0 ) {
V_23 = V_26 ;
break;
}
for ( V_25 = 0 ; V_25 < V_26 ; V_25 ++ ) {
if ( V_23 >= V_22 ) {
V_23 = - V_27 ;
break;
}
V_21 [ V_23 ++ ] = V_24 [ V_25 ] ;
}
}
F_8 ( & V_19 ) ;
F_12 ( L_2 , V_29 , V_23 ) ;
return V_23 ;
}
struct V_30 *
F_13 ( T_2 V_31 , struct V_32 * V_33 )
{
struct V_30 * V_34 ;
const struct V_15 * V_16 ;
T_1 V_12 = F_5 ( V_31 ) ;
V_34 = F_14 ( - V_8 ) ;
if ( V_12 >= V_13 )
goto V_35;
if ( ( V_16 = V_20 [ V_12 ] ) == NULL )
F_15 ( L_3 , V_12 ) ;
F_7 ( & V_19 ) ;
V_16 = V_20 [ V_12 ] ;
if ( V_16 == NULL || ! F_16 ( V_16 -> V_36 ) ) {
F_8 ( & V_19 ) ;
goto V_35;
}
F_8 ( & V_19 ) ;
V_34 = V_16 -> V_37 ( V_33 , V_31 ) ;
F_17 ( V_16 -> V_36 ) ;
if ( F_18 ( V_34 ) )
return V_34 ;
if ( V_33 -> V_38 )
F_19 ( V_33 -> V_38 ) ;
V_33 -> V_38 = V_34 ;
V_35:
return V_34 ;
}
void
F_19 ( struct V_30 * V_34 )
{
if ( ! F_20 ( & V_34 -> V_39 ) )
return;
V_34 -> V_40 -> V_41 ( V_34 ) ;
}
static void
F_21 ( struct V_42 * V_43 )
{
F_22 ( & V_43 -> V_44 ) ;
F_23 () ;
F_24 ( V_45 , & V_43 -> V_46 ) ;
}
static int
F_25 ( struct V_42 * V_43 )
{
T_3 * V_47 ;
int V_6 ;
V_47 = & V_43 -> V_48 -> V_49 -> V_50 ;
F_7 ( V_47 ) ;
V_6 = F_26 ( & V_43 -> V_51 ) == 0 ;
if ( V_6 )
F_21 ( V_43 ) ;
F_8 ( V_47 ) ;
return V_6 ;
}
int
F_27 ( struct V_30 * V_34 )
{
struct V_52 * V_53 ;
unsigned int V_54 ;
V_53 = F_28 ( sizeof( * V_53 ) , V_55 ) ;
if ( ! V_53 )
goto V_56;
V_53 -> V_57 = V_58 ;
V_54 = 1U << V_53 -> V_57 ;
V_53 -> V_59 = F_29 ( V_54 , sizeof( V_53 -> V_59 [ 0 ] ) , V_55 ) ;
if ( ! V_53 -> V_59 )
goto V_60;
F_30 ( & V_53 -> V_50 ) ;
V_34 -> V_49 = V_53 ;
return 0 ;
V_60:
F_31 ( V_53 ) ;
V_56:
return - V_27 ;
}
static inline
void F_32 ( struct V_61 * V_62 )
{
struct V_42 * V_43 ;
while ( ! F_33 ( V_62 ) ) {
V_43 = F_34 ( V_62 -> V_63 , struct V_42 , V_64 ) ;
F_35 ( & V_43 -> V_64 ) ;
F_36 ( V_43 ) ;
}
}
void
F_37 ( struct V_52 * V_65 )
{
F_38 ( free ) ;
struct V_66 * V_62 ;
struct V_42 * V_43 ;
unsigned int V_54 = 1U << V_65 -> V_57 ;
int V_25 ;
F_7 ( & V_67 ) ;
F_7 ( & V_65 -> V_50 ) ;
for ( V_25 = 0 ; V_25 < V_54 ; V_25 ++ ) {
V_62 = & V_65 -> V_59 [ V_25 ] ;
while ( ! F_39 ( V_62 ) ) {
V_43 = F_40 ( V_62 -> V_68 , struct V_42 , V_44 ) ;
F_41 ( V_43 ) ;
if ( ! F_33 ( & V_43 -> V_64 ) ) {
F_42 ( & V_43 -> V_64 ) ;
V_69 -- ;
}
F_43 ( & V_43 -> V_64 , & free ) ;
F_21 ( V_43 ) ;
}
}
F_8 ( & V_65 -> V_50 ) ;
F_8 ( & V_67 ) ;
F_32 ( & free ) ;
}
void
F_44 ( struct V_30 * V_34 )
{
struct V_52 * V_65 = V_34 -> V_49 ;
if ( V_65 ) {
V_34 -> V_49 = NULL ;
F_37 ( V_65 ) ;
F_31 ( V_65 -> V_59 ) ;
F_31 ( V_65 ) ;
}
}
static int
F_45 ( struct V_61 * free , int V_70 )
{
T_3 * V_47 ;
struct V_42 * V_43 , * V_63 ;
unsigned long V_71 = V_72 - V_73 ;
F_46 (cred, next, &cred_unused, cr_lru) {
if ( V_70 -- == 0 )
break;
if ( F_47 ( V_43 -> V_74 , V_71 , V_72 ) &&
F_48 ( V_45 , & V_43 -> V_46 ) != 0 )
return 0 ;
F_35 ( & V_43 -> V_64 ) ;
V_69 -- ;
if ( F_26 ( & V_43 -> V_51 ) != 0 )
continue;
V_47 = & V_43 -> V_48 -> V_49 -> V_50 ;
F_7 ( V_47 ) ;
if ( F_26 ( & V_43 -> V_51 ) == 0 ) {
F_41 ( V_43 ) ;
F_43 ( & V_43 -> V_64 , free ) ;
F_21 ( V_43 ) ;
}
F_8 ( V_47 ) ;
}
return ( V_69 / 100 ) * V_75 ;
}
static int
F_49 ( struct V_76 * V_77 , struct V_78 * V_79 )
{
F_38 ( free ) ;
int V_80 ;
int V_70 = V_79 -> V_70 ;
T_4 V_81 = V_79 -> V_81 ;
if ( ( V_81 & V_55 ) != V_55 )
return ( V_70 == 0 ) ? 0 : - 1 ;
if ( F_33 ( & V_82 ) )
return 0 ;
F_7 ( & V_67 ) ;
V_80 = F_45 ( & free , V_70 ) ;
F_8 ( & V_67 ) ;
F_32 ( & free ) ;
return V_80 ;
}
struct V_42 *
F_50 ( struct V_30 * V_34 , struct V_83 * V_84 ,
int V_85 )
{
F_38 ( free ) ;
struct V_52 * V_65 = V_34 -> V_49 ;
struct V_86 * V_87 ;
struct V_42 * V_43 = NULL ,
* V_88 , * V_53 ;
unsigned int V_89 ;
V_89 = F_51 ( V_84 -> V_90 , V_65 -> V_57 ) ;
F_52 () ;
F_53 (entry, pos, &cache->hashtable[nr], cr_hash) {
if ( ! V_88 -> V_91 -> V_92 ( V_84 , V_88 , V_85 ) )
continue;
F_7 ( & V_65 -> V_50 ) ;
if ( F_48 ( V_45 , & V_88 -> V_46 ) == 0 ) {
F_8 ( & V_65 -> V_50 ) ;
continue;
}
V_43 = F_41 ( V_88 ) ;
F_8 ( & V_65 -> V_50 ) ;
break;
}
F_54 () ;
if ( V_43 != NULL )
goto V_93;
V_53 = V_34 -> V_40 -> V_94 ( V_34 , V_84 , V_85 ) ;
if ( F_18 ( V_53 ) ) {
V_43 = V_53 ;
goto V_35;
}
F_7 ( & V_65 -> V_50 ) ;
F_55 (entry, pos, &cache->hashtable[nr], cr_hash) {
if ( ! V_88 -> V_91 -> V_92 ( V_84 , V_88 , V_85 ) )
continue;
V_43 = F_41 ( V_88 ) ;
break;
}
if ( V_43 == NULL ) {
V_43 = V_53 ;
F_56 ( V_45 , & V_43 -> V_46 ) ;
F_57 ( & V_43 -> V_44 , & V_65 -> V_59 [ V_89 ] ) ;
} else
F_43 ( & V_53 -> V_64 , & free ) ;
F_8 ( & V_65 -> V_50 ) ;
V_93:
if ( F_48 ( V_95 , & V_43 -> V_46 ) &&
V_43 -> V_91 -> V_96 != NULL &&
! ( V_85 & V_97 ) ) {
int V_80 = V_43 -> V_91 -> V_96 ( V_34 , V_43 ) ;
if ( V_80 < 0 ) {
F_36 ( V_43 ) ;
V_43 = F_14 ( V_80 ) ;
}
}
F_32 ( & free ) ;
V_35:
return V_43 ;
}
struct V_42 *
F_58 ( struct V_30 * V_34 , int V_85 )
{
struct V_83 V_84 ;
struct V_42 * V_6 ;
const struct V_43 * V_43 = F_59 () ;
F_12 ( L_4 ,
V_34 -> V_40 -> V_98 ) ;
memset ( & V_84 , 0 , sizeof( V_84 ) ) ;
V_84 . V_90 = V_43 -> V_99 ;
V_84 . V_100 = V_43 -> V_101 ;
V_84 . V_102 = F_60 ( ( (struct V_43 * ) V_43 ) -> V_102 ) ;
V_6 = V_34 -> V_40 -> V_103 ( V_34 , & V_84 , V_85 ) ;
F_61 ( V_84 . V_102 ) ;
return V_6 ;
}
void
F_62 ( struct V_42 * V_43 , const struct V_83 * V_84 ,
struct V_30 * V_34 , const struct V_104 * V_16 )
{
F_63 ( & V_43 -> V_44 ) ;
F_64 ( & V_43 -> V_64 ) ;
F_65 ( & V_43 -> V_51 , 1 ) ;
V_43 -> V_48 = V_34 ;
V_43 -> V_91 = V_16 ;
V_43 -> V_74 = V_72 ;
#ifdef F_66
V_43 -> V_105 = V_106 ;
#endif
V_43 -> V_107 = V_84 -> V_90 ;
}
struct V_42 *
F_67 ( struct V_108 * V_109 , struct V_42 * V_43 , int V_110 )
{
F_12 ( L_5 , V_109 -> V_111 ,
V_43 -> V_48 -> V_40 -> V_98 , V_43 ) ;
return F_41 ( V_43 ) ;
}
static struct V_42 *
F_68 ( struct V_108 * V_109 , int V_110 )
{
struct V_30 * V_34 = V_109 -> V_112 -> V_38 ;
struct V_83 V_84 = {
. V_90 = 0 ,
. V_100 = 0 ,
} ;
F_12 ( L_6 ,
V_109 -> V_111 , V_109 -> V_112 -> V_38 -> V_40 -> V_98 ) ;
return V_34 -> V_40 -> V_103 ( V_34 , & V_84 , V_110 ) ;
}
static struct V_42 *
F_69 ( struct V_108 * V_109 , int V_110 )
{
struct V_30 * V_34 = V_109 -> V_112 -> V_38 ;
F_12 ( L_6 ,
V_109 -> V_111 , V_34 -> V_40 -> V_98 ) ;
return F_58 ( V_34 , V_110 ) ;
}
static int
F_70 ( struct V_108 * V_109 , struct V_42 * V_43 , int V_85 )
{
struct V_113 * V_114 = V_109 -> V_115 ;
struct V_42 * V_53 ;
int V_110 = 0 ;
if ( V_85 & V_116 )
V_110 |= V_97 ;
if ( V_43 != NULL )
V_53 = V_43 -> V_91 -> V_117 ( V_109 , V_43 , V_110 ) ;
else if ( V_85 & V_118 )
V_53 = F_68 ( V_109 , V_110 ) ;
else
V_53 = F_69 ( V_109 , V_110 ) ;
if ( F_18 ( V_53 ) )
return F_71 ( V_53 ) ;
if ( V_114 -> V_119 != NULL )
F_36 ( V_114 -> V_119 ) ;
V_114 -> V_119 = V_53 ;
return 0 ;
}
void
F_36 ( struct V_42 * V_43 )
{
if ( F_48 ( V_45 , & V_43 -> V_46 ) == 0 ) {
if ( F_20 ( & V_43 -> V_51 ) )
V_43 -> V_91 -> V_120 ( V_43 ) ;
return;
}
if ( ! F_72 ( & V_43 -> V_51 , & V_67 ) )
return;
if ( ! F_33 ( & V_43 -> V_64 ) ) {
V_69 -- ;
F_35 ( & V_43 -> V_64 ) ;
}
if ( F_48 ( V_45 , & V_43 -> V_46 ) != 0 ) {
if ( F_48 ( V_121 , & V_43 -> V_46 ) != 0 ) {
V_43 -> V_74 = V_72 ;
F_43 ( & V_43 -> V_64 , & V_82 ) ;
V_69 ++ ;
goto V_122;
}
if ( ! F_25 ( V_43 ) ) {
goto V_122;
}
}
F_8 ( & V_67 ) ;
V_43 -> V_91 -> V_120 ( V_43 ) ;
return;
V_122:
F_8 ( & V_67 ) ;
}
T_5 *
F_73 ( struct V_108 * V_109 , T_5 * V_123 )
{
struct V_42 * V_43 = V_109 -> V_115 -> V_119 ;
F_12 ( L_7 ,
V_109 -> V_111 , V_43 -> V_48 -> V_40 -> V_98 , V_43 ) ;
return V_43 -> V_91 -> V_124 ( V_109 , V_123 ) ;
}
T_5 *
F_74 ( struct V_108 * V_109 , T_5 * V_123 )
{
struct V_42 * V_43 = V_109 -> V_115 -> V_119 ;
F_12 ( L_8 ,
V_109 -> V_111 , V_43 -> V_48 -> V_40 -> V_98 , V_43 ) ;
return V_43 -> V_91 -> V_125 ( V_109 , V_123 ) ;
}
static void F_75 ( T_6 V_126 , struct V_113 * V_127 ,
T_5 * V_128 , void * V_129 )
{
struct V_130 V_131 ;
F_76 ( & V_131 , & V_127 -> V_132 , V_128 ) ;
V_126 ( V_127 , & V_131 , V_129 ) ;
}
int
F_77 ( struct V_108 * V_109 , T_6 V_126 , void * V_127 ,
T_5 * V_128 , void * V_129 )
{
struct V_42 * V_43 = V_109 -> V_115 -> V_119 ;
F_12 ( L_9 ,
V_109 -> V_111 , V_43 -> V_91 -> V_133 , V_43 ) ;
if ( V_43 -> V_91 -> V_134 )
return V_43 -> V_91 -> V_134 ( V_109 , V_126 , V_127 , V_128 , V_129 ) ;
F_75 ( V_126 , V_127 , V_128 , V_129 ) ;
return 0 ;
}
static int
F_78 ( T_7 V_135 , struct V_113 * V_127 ,
T_5 * V_128 , void * V_129 )
{
struct V_130 V_131 ;
F_79 ( & V_131 , & V_127 -> V_136 , V_128 ) ;
return V_135 ( V_127 , & V_131 , V_129 ) ;
}
int
F_80 ( struct V_108 * V_109 , T_7 V_135 , void * V_127 ,
T_5 * V_128 , void * V_129 )
{
struct V_42 * V_43 = V_109 -> V_115 -> V_119 ;
F_12 ( L_10 ,
V_109 -> V_111 , V_43 -> V_91 -> V_133 , V_43 ) ;
if ( V_43 -> V_91 -> V_137 )
return V_43 -> V_91 -> V_137 ( V_109 , V_135 , V_127 ,
V_128 , V_129 ) ;
return F_78 ( V_135 , V_127 , V_128 , V_129 ) ;
}
int
F_81 ( struct V_108 * V_109 )
{
struct V_42 * V_43 ;
int V_138 ;
V_43 = V_109 -> V_115 -> V_119 ;
if ( V_43 == NULL ) {
V_138 = F_70 ( V_109 , V_109 -> V_139 . V_42 , V_109 -> V_140 ) ;
if ( V_138 < 0 )
goto V_35;
V_43 = V_109 -> V_115 -> V_119 ;
}
F_12 ( L_11 ,
V_109 -> V_111 , V_43 -> V_48 -> V_40 -> V_98 , V_43 ) ;
V_138 = V_43 -> V_91 -> V_141 ( V_109 ) ;
V_35:
if ( V_138 < 0 )
V_109 -> V_142 = V_138 ;
return V_138 ;
}
void
F_82 ( struct V_108 * V_109 )
{
struct V_42 * V_43 = V_109 -> V_115 -> V_119 ;
F_12 ( L_12 ,
V_109 -> V_111 , V_43 -> V_48 -> V_40 -> V_98 , V_43 ) ;
if ( V_43 )
F_24 ( V_121 , & V_43 -> V_46 ) ;
}
int
F_83 ( struct V_108 * V_109 )
{
struct V_42 * V_43 = V_109 -> V_115 -> V_119 ;
return V_43 == NULL ||
F_48 ( V_121 , & V_43 -> V_46 ) != 0 ;
}
int T_8 F_84 ( void )
{
int V_138 ;
V_138 = F_85 () ;
if ( V_138 < 0 )
goto V_143;
V_138 = F_86 () ;
if ( V_138 < 0 )
goto V_144;
F_87 ( & V_145 ) ;
return 0 ;
V_144:
F_88 () ;
V_143:
return V_138 ;
}
void F_89 ( void )
{
F_88 () ;
F_90 () ;
F_91 ( & V_145 ) ;
}
