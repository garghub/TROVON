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
struct V_21 *
F_10 ( T_2 V_22 , struct V_23 * V_24 )
{
struct V_21 * V_25 ;
const struct V_15 * V_16 ;
T_1 V_12 = F_5 ( V_22 ) ;
V_25 = F_11 ( - V_8 ) ;
if ( V_12 >= V_13 )
goto V_26;
if ( ( V_16 = V_20 [ V_12 ] ) == NULL )
F_12 ( L_2 , V_12 ) ;
F_7 ( & V_19 ) ;
V_16 = V_20 [ V_12 ] ;
if ( V_16 == NULL || ! F_13 ( V_16 -> V_27 ) ) {
F_8 ( & V_19 ) ;
goto V_26;
}
F_8 ( & V_19 ) ;
V_25 = V_16 -> V_28 ( V_24 , V_22 ) ;
F_14 ( V_16 -> V_27 ) ;
if ( F_15 ( V_25 ) )
return V_25 ;
if ( V_24 -> V_29 )
F_16 ( V_24 -> V_29 ) ;
V_24 -> V_29 = V_25 ;
V_26:
return V_25 ;
}
void
F_16 ( struct V_21 * V_25 )
{
if ( ! F_17 ( & V_25 -> V_30 ) )
return;
V_25 -> V_31 -> V_32 ( V_25 ) ;
}
static void
F_18 ( struct V_33 * V_34 )
{
F_19 ( & V_34 -> V_35 ) ;
F_20 () ;
F_21 ( V_36 , & V_34 -> V_37 ) ;
}
static int
F_22 ( struct V_33 * V_34 )
{
T_3 * V_38 ;
int V_6 ;
V_38 = & V_34 -> V_39 -> V_40 -> V_41 ;
F_7 ( V_38 ) ;
V_6 = F_23 ( & V_34 -> V_42 ) == 0 ;
if ( V_6 )
F_18 ( V_34 ) ;
F_8 ( V_38 ) ;
return V_6 ;
}
int
F_24 ( struct V_21 * V_25 )
{
struct V_43 * V_44 ;
unsigned int V_45 ;
V_44 = F_25 ( sizeof( * V_44 ) , V_46 ) ;
if ( ! V_44 )
goto V_47;
V_44 -> V_48 = V_49 ;
V_45 = 1U << V_44 -> V_48 ;
V_44 -> V_50 = F_26 ( V_45 , sizeof( V_44 -> V_50 [ 0 ] ) , V_46 ) ;
if ( ! V_44 -> V_50 )
goto V_51;
F_27 ( & V_44 -> V_41 ) ;
V_25 -> V_40 = V_44 ;
return 0 ;
V_51:
F_28 ( V_44 ) ;
V_47:
return - V_52 ;
}
static inline
void F_29 ( struct V_53 * V_54 )
{
struct V_33 * V_34 ;
while ( ! F_30 ( V_54 ) ) {
V_34 = F_31 ( V_54 -> V_55 , struct V_33 , V_56 ) ;
F_32 ( & V_34 -> V_56 ) ;
F_33 ( V_34 ) ;
}
}
void
F_34 ( struct V_43 * V_57 )
{
F_35 ( free ) ;
struct V_58 * V_54 ;
struct V_33 * V_34 ;
unsigned int V_45 = 1U << V_57 -> V_48 ;
int V_59 ;
F_7 ( & V_60 ) ;
F_7 ( & V_57 -> V_41 ) ;
for ( V_59 = 0 ; V_59 < V_45 ; V_59 ++ ) {
V_54 = & V_57 -> V_50 [ V_59 ] ;
while ( ! F_36 ( V_54 ) ) {
V_34 = F_37 ( V_54 -> V_61 , struct V_33 , V_35 ) ;
F_38 ( V_34 ) ;
if ( ! F_30 ( & V_34 -> V_56 ) ) {
F_39 ( & V_34 -> V_56 ) ;
V_62 -- ;
}
F_40 ( & V_34 -> V_56 , & free ) ;
F_18 ( V_34 ) ;
}
}
F_8 ( & V_57 -> V_41 ) ;
F_8 ( & V_60 ) ;
F_29 ( & free ) ;
}
void
F_41 ( struct V_21 * V_25 )
{
struct V_43 * V_57 = V_25 -> V_40 ;
if ( V_57 ) {
V_25 -> V_40 = NULL ;
F_34 ( V_57 ) ;
F_28 ( V_57 -> V_50 ) ;
F_28 ( V_57 ) ;
}
}
static int
F_42 ( struct V_53 * free , int V_63 )
{
T_3 * V_38 ;
struct V_33 * V_34 , * V_55 ;
unsigned long V_64 = V_65 - V_66 ;
F_43 (cred, next, &cred_unused, cr_lru) {
if ( V_63 -- == 0 )
break;
if ( F_44 ( V_34 -> V_67 , V_64 , V_65 ) &&
F_45 ( V_36 , & V_34 -> V_37 ) != 0 )
return 0 ;
F_32 ( & V_34 -> V_56 ) ;
V_62 -- ;
if ( F_23 ( & V_34 -> V_42 ) != 0 )
continue;
V_38 = & V_34 -> V_39 -> V_40 -> V_41 ;
F_7 ( V_38 ) ;
if ( F_23 ( & V_34 -> V_42 ) == 0 ) {
F_38 ( V_34 ) ;
F_40 ( & V_34 -> V_56 , free ) ;
F_18 ( V_34 ) ;
}
F_8 ( V_38 ) ;
}
return ( V_62 / 100 ) * V_68 ;
}
static int
F_46 ( struct V_69 * V_70 , struct V_71 * V_72 )
{
F_35 ( free ) ;
int V_73 ;
int V_63 = V_72 -> V_63 ;
T_4 V_74 = V_72 -> V_74 ;
if ( ( V_74 & V_46 ) != V_46 )
return ( V_63 == 0 ) ? 0 : - 1 ;
if ( F_30 ( & V_75 ) )
return 0 ;
F_7 ( & V_60 ) ;
V_73 = F_42 ( & free , V_63 ) ;
F_8 ( & V_60 ) ;
F_29 ( & free ) ;
return V_73 ;
}
struct V_33 *
F_47 ( struct V_21 * V_25 , struct V_76 * V_77 ,
int V_78 )
{
F_35 ( free ) ;
struct V_43 * V_57 = V_25 -> V_40 ;
struct V_79 * V_80 ;
struct V_33 * V_34 = NULL ,
* V_81 , * V_44 ;
unsigned int V_82 ;
V_82 = F_48 ( V_77 -> V_83 , V_57 -> V_48 ) ;
F_49 () ;
F_50 (entry, pos, &cache->hashtable[nr], cr_hash) {
if ( ! V_81 -> V_84 -> V_85 ( V_77 , V_81 , V_78 ) )
continue;
F_7 ( & V_57 -> V_41 ) ;
if ( F_45 ( V_36 , & V_81 -> V_37 ) == 0 ) {
F_8 ( & V_57 -> V_41 ) ;
continue;
}
V_34 = F_38 ( V_81 ) ;
F_8 ( & V_57 -> V_41 ) ;
break;
}
F_51 () ;
if ( V_34 != NULL )
goto V_86;
V_44 = V_25 -> V_31 -> V_87 ( V_25 , V_77 , V_78 ) ;
if ( F_15 ( V_44 ) ) {
V_34 = V_44 ;
goto V_26;
}
F_7 ( & V_57 -> V_41 ) ;
F_52 (entry, pos, &cache->hashtable[nr], cr_hash) {
if ( ! V_81 -> V_84 -> V_85 ( V_77 , V_81 , V_78 ) )
continue;
V_34 = F_38 ( V_81 ) ;
break;
}
if ( V_34 == NULL ) {
V_34 = V_44 ;
F_53 ( V_36 , & V_34 -> V_37 ) ;
F_54 ( & V_34 -> V_35 , & V_57 -> V_50 [ V_82 ] ) ;
} else
F_40 ( & V_44 -> V_56 , & free ) ;
F_8 ( & V_57 -> V_41 ) ;
V_86:
if ( F_45 ( V_88 , & V_34 -> V_37 ) &&
V_34 -> V_84 -> V_89 != NULL &&
! ( V_78 & V_90 ) ) {
int V_73 = V_34 -> V_84 -> V_89 ( V_25 , V_34 ) ;
if ( V_73 < 0 ) {
F_33 ( V_34 ) ;
V_34 = F_11 ( V_73 ) ;
}
}
F_29 ( & free ) ;
V_26:
return V_34 ;
}
struct V_33 *
F_55 ( struct V_21 * V_25 , int V_78 )
{
struct V_76 V_77 ;
struct V_33 * V_6 ;
const struct V_34 * V_34 = F_56 () ;
F_57 ( L_3 ,
V_25 -> V_31 -> V_91 ) ;
memset ( & V_77 , 0 , sizeof( V_77 ) ) ;
V_77 . V_83 = V_34 -> V_92 ;
V_77 . V_93 = V_34 -> V_94 ;
V_77 . V_95 = F_58 ( ( (struct V_34 * ) V_34 ) -> V_95 ) ;
V_6 = V_25 -> V_31 -> V_96 ( V_25 , & V_77 , V_78 ) ;
F_59 ( V_77 . V_95 ) ;
return V_6 ;
}
void
F_60 ( struct V_33 * V_34 , const struct V_76 * V_77 ,
struct V_21 * V_25 , const struct V_97 * V_16 )
{
F_61 ( & V_34 -> V_35 ) ;
F_62 ( & V_34 -> V_56 ) ;
F_63 ( & V_34 -> V_42 , 1 ) ;
V_34 -> V_39 = V_25 ;
V_34 -> V_84 = V_16 ;
V_34 -> V_67 = V_65 ;
#ifdef F_64
V_34 -> V_98 = V_99 ;
#endif
V_34 -> V_100 = V_77 -> V_83 ;
}
struct V_33 *
F_65 ( struct V_101 * V_102 , struct V_33 * V_34 , int V_103 )
{
F_57 ( L_4 , V_102 -> V_104 ,
V_34 -> V_39 -> V_31 -> V_91 , V_34 ) ;
return F_38 ( V_34 ) ;
}
static struct V_33 *
F_66 ( struct V_101 * V_102 , int V_103 )
{
struct V_21 * V_25 = V_102 -> V_105 -> V_29 ;
struct V_76 V_77 = {
. V_83 = 0 ,
. V_93 = 0 ,
} ;
F_57 ( L_5 ,
V_102 -> V_104 , V_102 -> V_105 -> V_29 -> V_31 -> V_91 ) ;
return V_25 -> V_31 -> V_96 ( V_25 , & V_77 , V_103 ) ;
}
static struct V_33 *
F_67 ( struct V_101 * V_102 , int V_103 )
{
struct V_21 * V_25 = V_102 -> V_105 -> V_29 ;
F_57 ( L_5 ,
V_102 -> V_104 , V_25 -> V_31 -> V_91 ) ;
return F_55 ( V_25 , V_103 ) ;
}
static int
F_68 ( struct V_101 * V_102 , struct V_33 * V_34 , int V_78 )
{
struct V_106 * V_107 = V_102 -> V_108 ;
struct V_33 * V_44 ;
int V_103 = 0 ;
if ( V_78 & V_109 )
V_103 |= V_90 ;
if ( V_34 != NULL )
V_44 = V_34 -> V_84 -> V_110 ( V_102 , V_34 , V_103 ) ;
else if ( V_78 & V_111 )
V_44 = F_66 ( V_102 , V_103 ) ;
else
V_44 = F_67 ( V_102 , V_103 ) ;
if ( F_15 ( V_44 ) )
return F_69 ( V_44 ) ;
if ( V_107 -> V_112 != NULL )
F_33 ( V_107 -> V_112 ) ;
V_107 -> V_112 = V_44 ;
return 0 ;
}
void
F_33 ( struct V_33 * V_34 )
{
if ( F_45 ( V_36 , & V_34 -> V_37 ) == 0 ) {
if ( F_17 ( & V_34 -> V_42 ) )
V_34 -> V_84 -> V_113 ( V_34 ) ;
return;
}
if ( ! F_70 ( & V_34 -> V_42 , & V_60 ) )
return;
if ( ! F_30 ( & V_34 -> V_56 ) ) {
V_62 -- ;
F_32 ( & V_34 -> V_56 ) ;
}
if ( F_45 ( V_36 , & V_34 -> V_37 ) != 0 ) {
if ( F_45 ( V_114 , & V_34 -> V_37 ) != 0 ) {
V_34 -> V_67 = V_65 ;
F_40 ( & V_34 -> V_56 , & V_75 ) ;
V_62 ++ ;
goto V_115;
}
if ( ! F_22 ( V_34 ) ) {
goto V_115;
}
}
F_8 ( & V_60 ) ;
V_34 -> V_84 -> V_113 ( V_34 ) ;
return;
V_115:
F_8 ( & V_60 ) ;
}
T_5 *
F_71 ( struct V_101 * V_102 , T_5 * V_116 )
{
struct V_33 * V_34 = V_102 -> V_108 -> V_112 ;
F_57 ( L_6 ,
V_102 -> V_104 , V_34 -> V_39 -> V_31 -> V_91 , V_34 ) ;
return V_34 -> V_84 -> V_117 ( V_102 , V_116 ) ;
}
T_5 *
F_72 ( struct V_101 * V_102 , T_5 * V_116 )
{
struct V_33 * V_34 = V_102 -> V_108 -> V_112 ;
F_57 ( L_7 ,
V_102 -> V_104 , V_34 -> V_39 -> V_31 -> V_91 , V_34 ) ;
return V_34 -> V_84 -> V_118 ( V_102 , V_116 ) ;
}
static void F_73 ( T_6 V_119 , struct V_106 * V_120 ,
T_5 * V_121 , void * V_122 )
{
struct V_123 V_124 ;
F_74 ( & V_124 , & V_120 -> V_125 , V_121 ) ;
V_119 ( V_120 , & V_124 , V_122 ) ;
}
int
F_75 ( struct V_101 * V_102 , T_6 V_119 , void * V_120 ,
T_5 * V_121 , void * V_122 )
{
struct V_33 * V_34 = V_102 -> V_108 -> V_112 ;
F_57 ( L_8 ,
V_102 -> V_104 , V_34 -> V_84 -> V_126 , V_34 ) ;
if ( V_34 -> V_84 -> V_127 )
return V_34 -> V_84 -> V_127 ( V_102 , V_119 , V_120 , V_121 , V_122 ) ;
F_73 ( V_119 , V_120 , V_121 , V_122 ) ;
return 0 ;
}
static int
F_76 ( T_7 V_128 , struct V_106 * V_120 ,
T_5 * V_121 , void * V_122 )
{
struct V_123 V_124 ;
F_77 ( & V_124 , & V_120 -> V_129 , V_121 ) ;
return V_128 ( V_120 , & V_124 , V_122 ) ;
}
int
F_78 ( struct V_101 * V_102 , T_7 V_128 , void * V_120 ,
T_5 * V_121 , void * V_122 )
{
struct V_33 * V_34 = V_102 -> V_108 -> V_112 ;
F_57 ( L_9 ,
V_102 -> V_104 , V_34 -> V_84 -> V_126 , V_34 ) ;
if ( V_34 -> V_84 -> V_130 )
return V_34 -> V_84 -> V_130 ( V_102 , V_128 , V_120 ,
V_121 , V_122 ) ;
return F_76 ( V_128 , V_120 , V_121 , V_122 ) ;
}
int
F_79 ( struct V_101 * V_102 )
{
struct V_33 * V_34 ;
int V_131 ;
V_34 = V_102 -> V_108 -> V_112 ;
if ( V_34 == NULL ) {
V_131 = F_68 ( V_102 , V_102 -> V_132 . V_33 , V_102 -> V_133 ) ;
if ( V_131 < 0 )
goto V_26;
V_34 = V_102 -> V_108 -> V_112 ;
}
F_57 ( L_10 ,
V_102 -> V_104 , V_34 -> V_39 -> V_31 -> V_91 , V_34 ) ;
V_131 = V_34 -> V_84 -> V_134 ( V_102 ) ;
V_26:
if ( V_131 < 0 )
V_102 -> V_135 = V_131 ;
return V_131 ;
}
void
F_80 ( struct V_101 * V_102 )
{
struct V_33 * V_34 = V_102 -> V_108 -> V_112 ;
F_57 ( L_11 ,
V_102 -> V_104 , V_34 -> V_39 -> V_31 -> V_91 , V_34 ) ;
if ( V_34 )
F_21 ( V_114 , & V_34 -> V_37 ) ;
}
int
F_81 ( struct V_101 * V_102 )
{
struct V_33 * V_34 = V_102 -> V_108 -> V_112 ;
return V_34 == NULL ||
F_45 ( V_114 , & V_34 -> V_37 ) != 0 ;
}
int T_8 F_82 ( void )
{
int V_131 ;
V_131 = F_83 () ;
if ( V_131 < 0 )
goto V_136;
V_131 = F_84 () ;
if ( V_131 < 0 )
goto V_137;
F_85 ( & V_138 ) ;
return 0 ;
V_137:
F_86 () ;
V_136:
return V_131 ;
}
void F_87 ( void )
{
F_86 () ;
F_88 () ;
F_89 ( & V_138 ) ;
}
