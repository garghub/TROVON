static bool F_1 ( void )
{
return V_1 * V_2 / 100 <
F_2 ( V_3 , V_4 ) ;
}
static void F_3 ( void )
{
struct V_5 * V_6 ;
T_1 V_7 = 0 ;
F_4 () ;
F_5 (pool, &zswap_pools, list)
V_7 += F_6 ( V_6 -> V_8 ) ;
F_7 () ;
V_3 = V_7 ;
}
static int T_2 F_8 ( void )
{
V_9 = F_9 ( V_10 , 0 ) ;
return V_9 == NULL ;
}
static void T_2 F_10 ( void )
{
F_11 ( V_9 ) ;
}
static struct V_10 * F_12 ( T_3 V_11 )
{
struct V_10 * V_12 ;
V_12 = F_13 ( V_9 , V_11 ) ;
if ( ! V_12 )
return NULL ;
V_12 -> V_13 = 1 ;
F_14 ( & V_12 -> V_14 ) ;
return V_12 ;
}
static void F_15 ( struct V_10 * V_12 )
{
F_16 ( V_9 , V_12 ) ;
}
static struct V_10 * F_17 ( struct V_15 * V_16 , T_4 V_17 )
{
struct V_18 * V_19 = V_16 -> V_18 ;
struct V_10 * V_12 ;
while ( V_19 ) {
V_12 = F_18 ( V_19 , struct V_10 , V_14 ) ;
if ( V_12 -> V_17 > V_17 )
V_19 = V_19 -> V_20 ;
else if ( V_12 -> V_17 < V_17 )
V_19 = V_19 -> V_21 ;
else
return V_12 ;
}
return NULL ;
}
static int F_19 ( struct V_15 * V_16 , struct V_10 * V_12 ,
struct V_10 * * V_22 )
{
struct V_18 * * V_23 = & V_16 -> V_18 , * V_24 = NULL ;
struct V_10 * V_25 ;
while ( * V_23 ) {
V_24 = * V_23 ;
V_25 = F_18 ( V_24 , struct V_10 , V_14 ) ;
if ( V_25 -> V_17 > V_12 -> V_17 )
V_23 = & ( * V_23 ) -> V_20 ;
else if ( V_25 -> V_17 < V_12 -> V_17 )
V_23 = & ( * V_23 ) -> V_21 ;
else {
* V_22 = V_25 ;
return - V_26 ;
}
}
F_20 ( & V_12 -> V_14 , V_24 , V_23 ) ;
F_21 ( & V_12 -> V_14 , V_16 ) ;
return 0 ;
}
static void F_22 ( struct V_15 * V_16 , struct V_10 * V_12 )
{
if ( ! F_23 ( & V_12 -> V_14 ) ) {
F_24 ( & V_12 -> V_14 , V_16 ) ;
F_14 ( & V_12 -> V_14 ) ;
}
}
static void F_25 ( struct V_10 * V_12 )
{
F_26 ( V_12 -> V_6 -> V_8 , V_12 -> V_27 ) ;
F_27 ( V_12 -> V_6 ) ;
F_15 ( V_12 ) ;
F_28 ( & V_28 ) ;
F_3 () ;
}
static void F_29 ( struct V_10 * V_12 )
{
V_12 -> V_13 ++ ;
}
static void F_30 ( struct V_29 * V_30 ,
struct V_10 * V_12 )
{
int V_13 = -- V_12 -> V_13 ;
F_31 ( V_13 < 0 ) ;
if ( V_13 == 0 ) {
F_22 ( & V_30 -> V_31 , V_12 ) ;
F_25 ( V_12 ) ;
}
}
static struct V_10 * F_32 ( struct V_15 * V_16 ,
T_4 V_17 )
{
struct V_10 * V_12 ;
V_12 = F_17 ( V_16 , V_17 ) ;
if ( V_12 )
F_29 ( V_12 ) ;
return V_12 ;
}
static int F_33 ( unsigned int V_32 )
{
T_5 * V_33 ;
V_33 = F_34 ( V_4 * 2 , V_34 , F_35 ( V_32 ) ) ;
if ( ! V_33 )
return - V_35 ;
F_36 ( V_36 , V_32 ) = V_33 ;
return 0 ;
}
static int F_37 ( unsigned int V_32 )
{
T_5 * V_33 ;
V_33 = F_36 ( V_36 , V_32 ) ;
F_38 ( V_33 ) ;
F_36 ( V_36 , V_32 ) = NULL ;
return 0 ;
}
static int F_39 ( unsigned int V_32 , struct V_37 * V_19 )
{
struct V_5 * V_6 = F_40 ( V_19 , struct V_5 , V_19 ) ;
struct V_38 * V_39 ;
if ( F_41 ( * F_42 ( V_6 -> V_39 , V_32 ) ) )
return 0 ;
V_39 = F_43 ( V_6 -> V_40 , 0 , 0 ) ;
if ( F_44 ( V_39 ) ) {
F_45 ( L_1 ,
V_6 -> V_40 , F_46 ( V_39 ) ) ;
return - V_35 ;
}
* F_42 ( V_6 -> V_39 , V_32 ) = V_39 ;
return 0 ;
}
static int F_47 ( unsigned int V_32 , struct V_37 * V_19 )
{
struct V_5 * V_6 = F_40 ( V_19 , struct V_5 , V_19 ) ;
struct V_38 * V_39 ;
V_39 = * F_42 ( V_6 -> V_39 , V_32 ) ;
if ( ! F_44 ( V_39 ) )
F_48 ( V_39 ) ;
* F_42 ( V_6 -> V_39 , V_32 ) = NULL ;
return 0 ;
}
static struct V_5 * F_49 ( void )
{
struct V_5 * V_6 ;
V_6 = F_50 ( & V_41 , F_51 ( * V_6 ) , V_42 ) ;
F_52 ( ! V_6 && V_43 ,
L_2 , V_44 ) ;
return V_6 ;
}
static struct V_5 * F_53 ( void )
{
F_54 ( & V_45 ) ;
return F_49 () ;
}
static struct V_5 * F_55 ( void )
{
struct V_5 * V_6 ;
F_4 () ;
V_6 = F_49 () ;
if ( ! F_56 ( V_6 ) )
V_6 = NULL ;
F_7 () ;
return V_6 ;
}
static struct V_5 * F_57 ( void )
{
struct V_5 * V_6 , * V_46 = NULL ;
F_4 () ;
F_5 (pool, &zswap_pools, list)
V_46 = V_6 ;
F_52 ( ! V_46 && V_43 ,
L_2 , V_44 ) ;
if ( ! F_56 ( V_46 ) )
V_46 = NULL ;
F_7 () ;
return V_46 ;
}
static struct V_5 * F_58 ( char * type , char * V_47 )
{
struct V_5 * V_6 ;
F_54 ( & V_45 ) ;
F_5 (pool, &zswap_pools, list) {
if ( strcmp ( V_6 -> V_40 , V_47 ) )
continue;
if ( strcmp ( F_59 ( V_6 -> V_8 ) , type ) )
continue;
if ( ! F_56 ( V_6 ) )
continue;
return V_6 ;
}
return NULL ;
}
static struct V_5 * F_60 ( char * type , char * V_47 )
{
struct V_5 * V_6 ;
char V_48 [ 38 ] ;
T_3 V_11 = V_49 | V_50 | V_51 ;
int V_52 ;
if ( ! V_43 ) {
if ( ! strcmp ( type , V_53 ) )
return NULL ;
if ( ! strcmp ( V_47 , V_53 ) )
return NULL ;
}
V_6 = F_61 ( sizeof( * V_6 ) , V_34 ) ;
if ( ! V_6 )
return NULL ;
snprintf ( V_48 , 38 , L_3 , F_62 ( & V_54 ) ) ;
V_6 -> V_8 = F_63 ( type , V_48 , V_11 , & V_55 ) ;
if ( ! V_6 -> V_8 ) {
F_45 ( L_4 , type ) ;
goto error;
}
F_64 ( L_5 , F_59 ( V_6 -> V_8 ) ) ;
F_65 ( V_6 -> V_40 , V_47 , sizeof( V_6 -> V_40 ) ) ;
V_6 -> V_39 = F_66 ( struct V_38 * ) ;
if ( ! V_6 -> V_39 ) {
F_45 ( L_6 ) ;
goto error;
}
V_52 = F_67 ( V_56 ,
& V_6 -> V_19 ) ;
if ( V_52 )
goto error;
F_64 ( L_7 , V_6 -> V_40 ) ;
F_68 ( & V_6 -> V_57 ) ;
F_69 ( & V_6 -> V_42 ) ;
F_70 ( L_8 , V_6 ) ;
return V_6 ;
error:
F_71 ( V_6 -> V_39 ) ;
if ( V_6 -> V_8 )
F_72 ( V_6 -> V_8 ) ;
F_38 ( V_6 ) ;
return NULL ;
}
void F_73 ( struct V_5 * V_6 )
{
F_70 ( L_9 , V_6 ) ;
F_74 ( V_56 , & V_6 -> V_19 ) ;
F_71 ( V_6 -> V_39 ) ;
F_72 ( V_6 -> V_8 ) ;
F_38 ( V_6 ) ;
}
static int T_6 F_56 ( struct V_5 * V_6 )
{
if ( ! V_6 )
return 0 ;
return F_75 ( & V_6 -> V_57 ) ;
}
static void F_76 ( struct V_58 * V_59 )
{
struct V_5 * V_6 = F_77 ( V_59 , F_51 ( * V_6 ) , V_59 ) ;
F_78 () ;
F_41 ( F_75 ( & V_6 -> V_57 ) ) ;
F_73 ( V_6 ) ;
}
static void F_79 ( struct V_57 * V_57 )
{
struct V_5 * V_6 ;
V_6 = F_77 ( V_57 , F_51 ( * V_6 ) , V_57 ) ;
F_80 ( & V_45 ) ;
F_41 ( V_6 == F_53 () ) ;
F_81 ( & V_6 -> V_42 ) ;
F_82 ( & V_6 -> V_59 , F_76 ) ;
F_83 ( & V_6 -> V_59 ) ;
F_84 ( & V_45 ) ;
}
static void F_27 ( struct V_5 * V_6 )
{
F_85 ( & V_6 -> V_57 , F_79 ) ;
}
static int F_86 ( const char * V_60 , const struct V_61 * V_62 ,
char * type , char * V_47 )
{
struct V_5 * V_6 , * V_63 = NULL ;
char * V_64 = F_87 ( ( char * ) V_60 ) ;
int V_52 ;
if ( V_65 ) {
F_45 ( L_10 ) ;
return - V_66 ;
}
if ( ! strcmp ( V_64 , * ( char * * ) V_62 -> V_67 ) && V_43 )
return 0 ;
if ( ! V_68 )
return F_88 ( V_64 , V_62 ) ;
if ( ! type ) {
if ( ! F_89 ( V_64 ) ) {
F_45 ( L_11 , V_64 ) ;
return - V_69 ;
}
type = V_64 ;
} else if ( ! V_47 ) {
if ( ! F_90 ( V_64 , 0 , 0 ) ) {
F_45 ( L_12 , V_64 ) ;
return - V_69 ;
}
V_47 = V_64 ;
} else {
F_41 ( 1 ) ;
return - V_70 ;
}
F_80 ( & V_45 ) ;
V_6 = F_58 ( type , V_47 ) ;
if ( V_6 ) {
F_70 ( L_13 , V_6 ) ;
F_41 ( V_6 == F_53 () ) ;
F_81 ( & V_6 -> V_42 ) ;
}
F_84 ( & V_45 ) ;
if ( ! V_6 )
V_6 = F_60 ( type , V_47 ) ;
if ( V_6 )
V_52 = F_88 ( V_64 , V_62 ) ;
else
V_52 = - V_70 ;
F_80 ( & V_45 ) ;
if ( ! V_52 ) {
V_63 = F_53 () ;
F_91 ( & V_6 -> V_42 , & V_41 ) ;
V_43 = true ;
} else if ( V_6 ) {
F_92 ( & V_6 -> V_42 , & V_41 ) ;
V_63 = V_6 ;
}
F_84 ( & V_45 ) ;
if ( ! V_43 && ! V_6 ) {
V_52 = F_88 ( V_64 , V_62 ) ;
}
if ( V_63 )
F_27 ( V_63 ) ;
return V_52 ;
}
static int F_93 ( const char * V_60 ,
const struct V_61 * V_62 )
{
return F_86 ( V_60 , V_62 , V_71 , NULL ) ;
}
static int F_94 ( const char * V_60 ,
const struct V_61 * V_62 )
{
return F_86 ( V_60 , V_62 , NULL , V_72 ) ;
}
static int F_95 ( const char * V_60 ,
const struct V_61 * V_62 )
{
if ( V_65 ) {
F_45 ( L_14 ) ;
return - V_66 ;
}
if ( ! V_43 && V_68 ) {
F_45 ( L_15 ) ;
return - V_66 ;
}
return F_96 ( V_60 , V_62 ) ;
}
static int F_97 ( T_7 V_12 ,
struct V_73 * * V_74 )
{
bool V_75 ;
* V_74 = F_98 ( V_12 , V_34 ,
NULL , 0 , & V_75 ) ;
if ( V_75 )
return V_76 ;
if ( ! * V_74 )
return V_77 ;
return V_78 ;
}
static int F_99 ( struct V_8 * V_6 , unsigned long V_27 )
{
struct V_79 * V_80 ;
T_7 V_81 ;
struct V_29 * V_30 ;
T_4 V_17 ;
struct V_10 * V_12 ;
struct V_73 * V_73 ;
struct V_38 * V_39 ;
T_5 * V_82 , * V_33 ;
unsigned int V_83 ;
int V_52 ;
struct V_84 V_85 = {
. V_86 = V_87 ,
} ;
V_80 = F_100 ( V_6 , V_27 , V_88 ) ;
V_81 = V_80 -> V_81 ;
F_101 ( V_6 , V_27 ) ;
V_30 = V_89 [ F_102 ( V_81 ) ] ;
V_17 = F_103 ( V_81 ) ;
F_80 ( & V_30 -> V_90 ) ;
V_12 = F_32 ( & V_30 -> V_31 , V_17 ) ;
if ( ! V_12 ) {
F_84 ( & V_30 -> V_90 ) ;
return 0 ;
}
F_84 ( & V_30 -> V_90 ) ;
F_31 ( V_17 != V_12 -> V_17 ) ;
switch ( F_97 ( V_81 , & V_73 ) ) {
case V_77 :
V_52 = - V_35 ;
goto V_91;
case V_78 :
F_104 ( V_73 ) ;
V_52 = - V_26 ;
goto V_91;
case V_76 :
V_83 = V_4 ;
V_82 = ( T_5 * ) F_100 ( V_12 -> V_6 -> V_8 , V_12 -> V_27 ,
V_88 ) + sizeof( struct V_79 ) ;
V_33 = F_105 ( V_73 ) ;
V_39 = * F_106 ( V_12 -> V_6 -> V_39 ) ;
V_52 = F_107 ( V_39 , V_82 , V_12 -> V_92 ,
V_33 , & V_83 ) ;
F_108 ( V_12 -> V_6 -> V_39 ) ;
F_109 ( V_33 ) ;
F_101 ( V_12 -> V_6 -> V_8 , V_12 -> V_27 ) ;
F_31 ( V_52 ) ;
F_31 ( V_83 != V_4 ) ;
F_110 ( V_73 ) ;
}
F_111 ( V_73 ) ;
F_112 ( V_73 , & V_85 , V_93 ) ;
F_104 ( V_73 ) ;
V_94 ++ ;
F_80 ( & V_30 -> V_90 ) ;
F_30 ( V_30 , V_12 ) ;
if ( V_12 == F_17 ( & V_30 -> V_31 , V_17 ) )
F_30 ( V_30 , V_12 ) ;
F_84 ( & V_30 -> V_90 ) ;
goto V_95;
V_91:
F_80 ( & V_30 -> V_90 ) ;
F_30 ( V_30 , V_12 ) ;
F_84 ( & V_30 -> V_90 ) ;
V_95:
return V_52 ;
}
static int F_113 ( void )
{
struct V_5 * V_6 ;
int V_52 ;
V_6 = F_57 () ;
if ( ! V_6 )
return - V_69 ;
V_52 = F_114 ( V_6 -> V_8 , 1 , NULL ) ;
F_27 ( V_6 ) ;
return V_52 ;
}
static int F_115 ( unsigned type , T_4 V_17 ,
struct V_73 * V_73 )
{
struct V_29 * V_30 = V_89 [ type ] ;
struct V_10 * V_12 , * V_22 ;
struct V_38 * V_39 ;
int V_52 ;
unsigned int V_83 = V_4 , V_96 ;
unsigned long V_27 ;
char * V_97 ;
T_5 * V_82 , * V_33 ;
struct V_79 * V_80 ;
if ( ! V_98 || ! V_30 ) {
V_52 = - V_66 ;
goto V_99;
}
if ( F_1 () ) {
V_100 ++ ;
if ( F_113 () ) {
V_101 ++ ;
V_52 = - V_35 ;
goto V_99;
}
}
V_12 = F_12 ( V_34 ) ;
if ( ! V_12 ) {
V_102 ++ ;
V_52 = - V_35 ;
goto V_99;
}
V_12 -> V_6 = F_55 () ;
if ( ! V_12 -> V_6 ) {
V_52 = - V_70 ;
goto V_103;
}
V_33 = F_116 ( V_36 ) ;
V_39 = * F_106 ( V_12 -> V_6 -> V_39 ) ;
V_82 = F_105 ( V_73 ) ;
V_52 = F_117 ( V_39 , V_82 , V_4 , V_33 , & V_83 ) ;
F_109 ( V_82 ) ;
F_108 ( V_12 -> V_6 -> V_39 ) ;
if ( V_52 ) {
V_52 = - V_70 ;
goto V_104;
}
V_96 = V_83 + sizeof( struct V_79 ) ;
V_52 = F_118 ( V_12 -> V_6 -> V_8 , V_96 ,
V_49 | V_50 | V_51 ,
& V_27 ) ;
if ( V_52 == - V_105 ) {
V_106 ++ ;
goto V_104;
}
if ( V_52 ) {
V_107 ++ ;
goto V_104;
}
V_80 = F_100 ( V_12 -> V_6 -> V_8 , V_27 , V_108 ) ;
V_80 -> V_81 = F_119 ( type , V_17 ) ;
V_97 = ( T_5 * ) ( V_80 + 1 ) ;
memcpy ( V_97 , V_33 , V_83 ) ;
F_101 ( V_12 -> V_6 -> V_8 , V_27 ) ;
F_120 ( V_36 ) ;
V_12 -> V_17 = V_17 ;
V_12 -> V_27 = V_27 ;
V_12 -> V_92 = V_83 ;
F_80 ( & V_30 -> V_90 ) ;
do {
V_52 = F_19 ( & V_30 -> V_31 , V_12 , & V_22 ) ;
if ( V_52 == - V_26 ) {
V_109 ++ ;
F_22 ( & V_30 -> V_31 , V_22 ) ;
F_30 ( V_30 , V_22 ) ;
}
} while ( V_52 == - V_26 );
F_84 ( & V_30 -> V_90 ) ;
F_121 ( & V_28 ) ;
F_3 () ;
return 0 ;
V_104:
F_120 ( V_36 ) ;
F_27 ( V_12 -> V_6 ) ;
V_103:
F_15 ( V_12 ) ;
V_99:
return V_52 ;
}
static int F_122 ( unsigned type , T_4 V_17 ,
struct V_73 * V_73 )
{
struct V_29 * V_30 = V_89 [ type ] ;
struct V_10 * V_12 ;
struct V_38 * V_39 ;
T_5 * V_82 , * V_33 ;
unsigned int V_83 ;
int V_52 ;
F_80 ( & V_30 -> V_90 ) ;
V_12 = F_32 ( & V_30 -> V_31 , V_17 ) ;
if ( ! V_12 ) {
F_84 ( & V_30 -> V_90 ) ;
return - 1 ;
}
F_84 ( & V_30 -> V_90 ) ;
V_83 = V_4 ;
V_82 = ( T_5 * ) F_100 ( V_12 -> V_6 -> V_8 , V_12 -> V_27 ,
V_88 ) + sizeof( struct V_79 ) ;
V_33 = F_105 ( V_73 ) ;
V_39 = * F_106 ( V_12 -> V_6 -> V_39 ) ;
V_52 = F_107 ( V_39 , V_82 , V_12 -> V_92 , V_33 , & V_83 ) ;
F_108 ( V_12 -> V_6 -> V_39 ) ;
F_109 ( V_33 ) ;
F_101 ( V_12 -> V_6 -> V_8 , V_12 -> V_27 ) ;
F_31 ( V_52 ) ;
F_80 ( & V_30 -> V_90 ) ;
F_30 ( V_30 , V_12 ) ;
F_84 ( & V_30 -> V_90 ) ;
return 0 ;
}
static void F_123 ( unsigned type , T_4 V_17 )
{
struct V_29 * V_30 = V_89 [ type ] ;
struct V_10 * V_12 ;
F_80 ( & V_30 -> V_90 ) ;
V_12 = F_17 ( & V_30 -> V_31 , V_17 ) ;
if ( ! V_12 ) {
F_84 ( & V_30 -> V_90 ) ;
return;
}
F_22 ( & V_30 -> V_31 , V_12 ) ;
F_30 ( V_30 , V_12 ) ;
F_84 ( & V_30 -> V_90 ) ;
}
static void F_124 ( unsigned type )
{
struct V_29 * V_30 = V_89 [ type ] ;
struct V_10 * V_12 , * V_110 ;
if ( ! V_30 )
return;
F_80 ( & V_30 -> V_90 ) ;
F_125 (entry, n, &tree->rbroot, rbnode)
F_25 ( V_12 ) ;
V_30 -> V_31 = V_111 ;
F_84 ( & V_30 -> V_90 ) ;
F_38 ( V_30 ) ;
V_89 [ type ] = NULL ;
}
static void F_126 ( unsigned type )
{
struct V_29 * V_30 ;
V_30 = F_61 ( sizeof( * V_30 ) , V_34 ) ;
if ( ! V_30 ) {
F_45 ( L_16 , type ) ;
return;
}
V_30 -> V_31 = V_111 ;
F_127 ( & V_30 -> V_90 ) ;
V_89 [ type ] = V_30 ;
}
static int T_2 F_128 ( void )
{
if ( ! F_129 () )
return - V_66 ;
V_112 = F_130 ( L_17 , NULL ) ;
if ( ! V_112 )
return - V_35 ;
F_131 ( L_18 , V_113 ,
V_112 , & V_100 ) ;
F_131 ( L_19 , V_113 ,
V_112 , & V_101 ) ;
F_131 ( L_20 , V_113 ,
V_112 , & V_107 ) ;
F_131 ( L_21 , V_113 ,
V_112 , & V_102 ) ;
F_131 ( L_22 , V_113 ,
V_112 , & V_106 ) ;
F_131 ( L_23 , V_113 ,
V_112 , & V_94 ) ;
F_131 ( L_24 , V_113 ,
V_112 , & V_109 ) ;
F_131 ( L_25 , V_113 ,
V_112 , & V_3 ) ;
F_132 ( L_26 , V_113 ,
V_112 , & V_28 ) ;
return 0 ;
}
static void T_8 F_133 ( void )
{
F_134 ( V_112 ) ;
}
static int T_2 F_128 ( void )
{
return 0 ;
}
static void T_8 F_133 ( void ) { }
static int T_2 F_135 ( void )
{
struct V_5 * V_6 ;
int V_52 ;
V_68 = true ;
if ( F_8 () ) {
F_45 ( L_27 ) ;
goto V_114;
}
V_52 = F_136 ( V_115 , L_28 ,
F_33 , F_37 ) ;
if ( V_52 ) {
F_45 ( L_29 ) ;
goto V_116;
}
V_52 = F_137 ( V_56 ,
L_30 ,
F_39 ,
F_47 ) ;
if ( V_52 )
goto V_117;
V_6 = F_138 () ;
if ( V_6 ) {
F_139 ( L_31 , V_6 -> V_40 ,
F_59 ( V_6 -> V_8 ) ) ;
F_140 ( & V_6 -> V_42 , & V_41 ) ;
V_43 = true ;
} else {
F_45 ( L_32 ) ;
V_98 = false ;
}
F_141 ( & V_118 ) ;
if ( F_128 () )
F_142 ( L_33 ) ;
return 0 ;
V_117:
F_143 ( V_115 ) ;
V_116:
F_10 () ;
V_114:
V_65 = true ;
V_98 = false ;
return - V_35 ;
}
