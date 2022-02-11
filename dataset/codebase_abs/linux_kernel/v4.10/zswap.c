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
if ( ! V_33 ) {
F_36 ( L_1 ) ;
return - V_35 ;
}
F_37 ( V_36 , V_32 ) = V_33 ;
return 0 ;
}
static int F_38 ( unsigned int V_32 )
{
T_5 * V_33 ;
V_33 = F_37 ( V_36 , V_32 ) ;
F_39 ( V_33 ) ;
F_37 ( V_36 , V_32 ) = NULL ;
return 0 ;
}
static int F_40 ( unsigned int V_32 , struct V_37 * V_19 )
{
struct V_5 * V_6 = F_41 ( V_19 , struct V_5 , V_19 ) ;
struct V_38 * V_39 ;
if ( F_42 ( * F_43 ( V_6 -> V_39 , V_32 ) ) )
return 0 ;
V_39 = F_44 ( V_6 -> V_40 , 0 , 0 ) ;
if ( F_45 ( V_39 ) ) {
F_36 ( L_2 ,
V_6 -> V_40 , F_46 ( V_39 ) ) ;
return - V_35 ;
}
* F_43 ( V_6 -> V_39 , V_32 ) = V_39 ;
return 0 ;
}
static int F_47 ( unsigned int V_32 , struct V_37 * V_19 )
{
struct V_5 * V_6 = F_41 ( V_19 , struct V_5 , V_19 ) ;
struct V_38 * V_39 ;
V_39 = * F_43 ( V_6 -> V_39 , V_32 ) ;
if ( ! F_45 ( V_39 ) )
F_48 ( V_39 ) ;
* F_43 ( V_6 -> V_39 , V_32 ) = NULL ;
return 0 ;
}
static struct V_5 * F_49 ( void )
{
struct V_5 * V_6 ;
V_6 = F_50 ( & V_41 , F_51 ( * V_6 ) , V_42 ) ;
F_42 ( ! V_6 ) ;
return V_6 ;
}
static struct V_5 * F_52 ( void )
{
F_53 ( & V_43 ) ;
return F_49 () ;
}
static struct V_5 * F_54 ( void )
{
struct V_5 * V_6 ;
F_4 () ;
V_6 = F_49 () ;
if ( ! V_6 || ! F_55 ( V_6 ) )
V_6 = NULL ;
F_7 () ;
return V_6 ;
}
static struct V_5 * F_56 ( void )
{
struct V_5 * V_6 , * V_44 = NULL ;
F_4 () ;
F_5 (pool, &zswap_pools, list)
V_44 = V_6 ;
if ( ! F_42 ( ! V_44 ) && ! F_55 ( V_44 ) )
V_44 = NULL ;
F_7 () ;
return V_44 ;
}
static struct V_5 * F_57 ( char * type , char * V_45 )
{
struct V_5 * V_6 ;
F_53 ( & V_43 ) ;
F_5 (pool, &zswap_pools, list) {
if ( strcmp ( V_6 -> V_40 , V_45 ) )
continue;
if ( strcmp ( F_58 ( V_6 -> V_8 ) , type ) )
continue;
if ( ! F_55 ( V_6 ) )
continue;
return V_6 ;
}
return NULL ;
}
static struct V_5 * F_59 ( char * type , char * V_45 )
{
struct V_5 * V_6 ;
char V_46 [ 38 ] ;
T_3 V_11 = V_47 | V_48 | V_49 ;
int V_50 ;
V_6 = F_60 ( sizeof( * V_6 ) , V_34 ) ;
if ( ! V_6 ) {
F_36 ( L_3 ) ;
return NULL ;
}
snprintf ( V_46 , 38 , L_4 , F_61 ( & V_51 ) ) ;
V_6 -> V_8 = F_62 ( type , V_46 , V_11 , & V_52 ) ;
if ( ! V_6 -> V_8 ) {
F_36 ( L_5 , type ) ;
goto error;
}
F_63 ( L_6 , F_58 ( V_6 -> V_8 ) ) ;
F_64 ( V_6 -> V_40 , V_45 , sizeof( V_6 -> V_40 ) ) ;
V_6 -> V_39 = F_65 ( struct V_38 * ) ;
if ( ! V_6 -> V_39 ) {
F_36 ( L_7 ) ;
goto error;
}
V_50 = F_66 ( V_53 ,
& V_6 -> V_19 ) ;
if ( V_50 )
goto error;
F_63 ( L_8 , V_6 -> V_40 ) ;
F_67 ( & V_6 -> V_54 ) ;
F_68 ( & V_6 -> V_42 ) ;
F_69 ( L_9 , V_6 ) ;
return V_6 ;
error:
F_70 ( V_6 -> V_39 ) ;
if ( V_6 -> V_8 )
F_71 ( V_6 -> V_8 ) ;
F_39 ( V_6 ) ;
return NULL ;
}
void F_72 ( struct V_5 * V_6 )
{
F_69 ( L_10 , V_6 ) ;
F_73 ( V_53 , & V_6 -> V_19 ) ;
F_70 ( V_6 -> V_39 ) ;
F_71 ( V_6 -> V_8 ) ;
F_39 ( V_6 ) ;
}
static int T_6 F_55 ( struct V_5 * V_6 )
{
return F_74 ( & V_6 -> V_54 ) ;
}
static void F_75 ( struct V_55 * V_56 )
{
struct V_5 * V_6 = F_76 ( V_56 , F_51 ( * V_6 ) , V_56 ) ;
F_77 () ;
F_42 ( F_74 ( & V_6 -> V_54 ) ) ;
F_72 ( V_6 ) ;
}
static void F_78 ( struct V_54 * V_54 )
{
struct V_5 * V_6 ;
V_6 = F_76 ( V_54 , F_51 ( * V_6 ) , V_54 ) ;
F_79 ( & V_43 ) ;
F_42 ( V_6 == F_52 () ) ;
F_80 ( & V_6 -> V_42 ) ;
F_81 ( & V_6 -> V_56 , F_75 ) ;
F_82 ( & V_6 -> V_56 ) ;
F_83 ( & V_43 ) ;
}
static void F_27 ( struct V_5 * V_6 )
{
F_84 ( & V_6 -> V_54 , F_78 ) ;
}
static int F_85 ( const char * V_57 , const struct V_58 * V_59 ,
char * type , char * V_45 )
{
struct V_5 * V_6 , * V_60 = NULL ;
char * V_61 = F_86 ( ( char * ) V_57 ) ;
int V_50 ;
if ( V_62 ) {
F_36 ( L_11 ) ;
return - V_63 ;
}
if ( ! strcmp ( V_61 , * ( char * * ) V_59 -> V_64 ) )
return 0 ;
if ( ! V_65 )
return F_87 ( V_61 , V_59 ) ;
if ( ! type ) {
if ( ! F_88 ( V_61 ) ) {
F_36 ( L_12 , V_61 ) ;
return - V_66 ;
}
type = V_61 ;
} else if ( ! V_45 ) {
if ( ! F_89 ( V_61 , 0 , 0 ) ) {
F_36 ( L_13 , V_61 ) ;
return - V_66 ;
}
V_45 = V_61 ;
} else {
F_42 ( 1 ) ;
return - V_67 ;
}
F_79 ( & V_43 ) ;
V_6 = F_57 ( type , V_45 ) ;
if ( V_6 ) {
F_69 ( L_14 , V_6 ) ;
F_80 ( & V_6 -> V_42 ) ;
} else {
F_83 ( & V_43 ) ;
V_6 = F_59 ( type , V_45 ) ;
F_79 ( & V_43 ) ;
}
if ( V_6 )
V_50 = F_87 ( V_61 , V_59 ) ;
else
V_50 = - V_67 ;
if ( ! V_50 ) {
V_60 = F_52 () ;
F_90 ( & V_6 -> V_42 , & V_41 ) ;
} else if ( V_6 ) {
F_91 ( & V_6 -> V_42 , & V_41 ) ;
V_60 = V_6 ;
}
F_83 ( & V_43 ) ;
if ( V_60 )
F_27 ( V_60 ) ;
return V_50 ;
}
static int F_92 ( const char * V_57 ,
const struct V_58 * V_59 )
{
return F_85 ( V_57 , V_59 , V_68 , NULL ) ;
}
static int F_93 ( const char * V_57 ,
const struct V_58 * V_59 )
{
return F_85 ( V_57 , V_59 , NULL , V_69 ) ;
}
static int F_94 ( const char * V_57 ,
const struct V_58 * V_59 )
{
if ( V_62 ) {
F_36 ( L_15 ) ;
return - V_63 ;
}
return F_95 ( V_57 , V_59 ) ;
}
static int F_96 ( T_7 V_12 ,
struct V_70 * * V_71 )
{
bool V_72 ;
* V_71 = F_97 ( V_12 , V_34 ,
NULL , 0 , & V_72 ) ;
if ( V_72 )
return V_73 ;
if ( ! * V_71 )
return V_74 ;
return V_75 ;
}
static int F_98 ( struct V_8 * V_6 , unsigned long V_27 )
{
struct V_76 * V_77 ;
T_7 V_78 ;
struct V_29 * V_30 ;
T_4 V_17 ;
struct V_10 * V_12 ;
struct V_70 * V_70 ;
struct V_38 * V_39 ;
T_5 * V_79 , * V_33 ;
unsigned int V_80 ;
int V_50 ;
struct V_81 V_82 = {
. V_83 = V_84 ,
} ;
V_77 = F_99 ( V_6 , V_27 , V_85 ) ;
V_78 = V_77 -> V_78 ;
F_100 ( V_6 , V_27 ) ;
V_30 = V_86 [ F_101 ( V_78 ) ] ;
V_17 = F_102 ( V_78 ) ;
F_79 ( & V_30 -> V_87 ) ;
V_12 = F_32 ( & V_30 -> V_31 , V_17 ) ;
if ( ! V_12 ) {
F_83 ( & V_30 -> V_87 ) ;
return 0 ;
}
F_83 ( & V_30 -> V_87 ) ;
F_31 ( V_17 != V_12 -> V_17 ) ;
switch ( F_96 ( V_78 , & V_70 ) ) {
case V_74 :
V_50 = - V_35 ;
goto V_88;
case V_75 :
F_103 ( V_70 ) ;
V_50 = - V_26 ;
goto V_88;
case V_73 :
V_80 = V_4 ;
V_79 = ( T_5 * ) F_99 ( V_12 -> V_6 -> V_8 , V_12 -> V_27 ,
V_85 ) + sizeof( struct V_76 ) ;
V_33 = F_104 ( V_70 ) ;
V_39 = * F_105 ( V_12 -> V_6 -> V_39 ) ;
V_50 = F_106 ( V_39 , V_79 , V_12 -> V_89 ,
V_33 , & V_80 ) ;
F_107 ( V_12 -> V_6 -> V_39 ) ;
F_108 ( V_33 ) ;
F_100 ( V_12 -> V_6 -> V_8 , V_12 -> V_27 ) ;
F_31 ( V_50 ) ;
F_31 ( V_80 != V_4 ) ;
F_109 ( V_70 ) ;
}
F_110 ( V_70 ) ;
F_111 ( V_70 , & V_82 , V_90 ) ;
F_103 ( V_70 ) ;
V_91 ++ ;
F_79 ( & V_30 -> V_87 ) ;
F_30 ( V_30 , V_12 ) ;
if ( V_12 == F_17 ( & V_30 -> V_31 , V_17 ) )
F_30 ( V_30 , V_12 ) ;
F_83 ( & V_30 -> V_87 ) ;
goto V_92;
V_88:
F_79 ( & V_30 -> V_87 ) ;
F_30 ( V_30 , V_12 ) ;
F_83 ( & V_30 -> V_87 ) ;
V_92:
return V_50 ;
}
static int F_112 ( void )
{
struct V_5 * V_6 ;
int V_50 ;
V_6 = F_56 () ;
if ( ! V_6 )
return - V_66 ;
V_50 = F_113 ( V_6 -> V_8 , 1 , NULL ) ;
F_27 ( V_6 ) ;
return V_50 ;
}
static int F_114 ( unsigned type , T_4 V_17 ,
struct V_70 * V_70 )
{
struct V_29 * V_30 = V_86 [ type ] ;
struct V_10 * V_12 , * V_22 ;
struct V_38 * V_39 ;
int V_50 ;
unsigned int V_80 = V_4 , V_93 ;
unsigned long V_27 ;
char * V_94 ;
T_5 * V_79 , * V_33 ;
struct V_76 * V_77 ;
if ( ! V_95 || ! V_30 ) {
V_50 = - V_63 ;
goto V_96;
}
if ( F_1 () ) {
V_97 ++ ;
if ( F_112 () ) {
V_98 ++ ;
V_50 = - V_35 ;
goto V_96;
}
}
V_12 = F_12 ( V_34 ) ;
if ( ! V_12 ) {
V_99 ++ ;
V_50 = - V_35 ;
goto V_96;
}
V_12 -> V_6 = F_54 () ;
if ( ! V_12 -> V_6 ) {
V_50 = - V_67 ;
goto V_100;
}
V_33 = F_115 ( V_36 ) ;
V_39 = * F_105 ( V_12 -> V_6 -> V_39 ) ;
V_79 = F_104 ( V_70 ) ;
V_50 = F_116 ( V_39 , V_79 , V_4 , V_33 , & V_80 ) ;
F_108 ( V_79 ) ;
F_107 ( V_12 -> V_6 -> V_39 ) ;
if ( V_50 ) {
V_50 = - V_67 ;
goto V_101;
}
V_93 = V_80 + sizeof( struct V_76 ) ;
V_50 = F_117 ( V_12 -> V_6 -> V_8 , V_93 ,
V_47 | V_48 | V_49 ,
& V_27 ) ;
if ( V_50 == - V_102 ) {
V_103 ++ ;
goto V_101;
}
if ( V_50 ) {
V_104 ++ ;
goto V_101;
}
V_77 = F_99 ( V_12 -> V_6 -> V_8 , V_27 , V_105 ) ;
V_77 -> V_78 = F_118 ( type , V_17 ) ;
V_94 = ( T_5 * ) ( V_77 + 1 ) ;
memcpy ( V_94 , V_33 , V_80 ) ;
F_100 ( V_12 -> V_6 -> V_8 , V_27 ) ;
F_119 ( V_36 ) ;
V_12 -> V_17 = V_17 ;
V_12 -> V_27 = V_27 ;
V_12 -> V_89 = V_80 ;
F_79 ( & V_30 -> V_87 ) ;
do {
V_50 = F_19 ( & V_30 -> V_31 , V_12 , & V_22 ) ;
if ( V_50 == - V_26 ) {
V_106 ++ ;
F_22 ( & V_30 -> V_31 , V_22 ) ;
F_30 ( V_30 , V_22 ) ;
}
} while ( V_50 == - V_26 );
F_83 ( & V_30 -> V_87 ) ;
F_120 ( & V_28 ) ;
F_3 () ;
return 0 ;
V_101:
F_119 ( V_36 ) ;
F_27 ( V_12 -> V_6 ) ;
V_100:
F_15 ( V_12 ) ;
V_96:
return V_50 ;
}
static int F_121 ( unsigned type , T_4 V_17 ,
struct V_70 * V_70 )
{
struct V_29 * V_30 = V_86 [ type ] ;
struct V_10 * V_12 ;
struct V_38 * V_39 ;
T_5 * V_79 , * V_33 ;
unsigned int V_80 ;
int V_50 ;
F_79 ( & V_30 -> V_87 ) ;
V_12 = F_32 ( & V_30 -> V_31 , V_17 ) ;
if ( ! V_12 ) {
F_83 ( & V_30 -> V_87 ) ;
return - 1 ;
}
F_83 ( & V_30 -> V_87 ) ;
V_80 = V_4 ;
V_79 = ( T_5 * ) F_99 ( V_12 -> V_6 -> V_8 , V_12 -> V_27 ,
V_85 ) + sizeof( struct V_76 ) ;
V_33 = F_104 ( V_70 ) ;
V_39 = * F_105 ( V_12 -> V_6 -> V_39 ) ;
V_50 = F_106 ( V_39 , V_79 , V_12 -> V_89 , V_33 , & V_80 ) ;
F_107 ( V_12 -> V_6 -> V_39 ) ;
F_108 ( V_33 ) ;
F_100 ( V_12 -> V_6 -> V_8 , V_12 -> V_27 ) ;
F_31 ( V_50 ) ;
F_79 ( & V_30 -> V_87 ) ;
F_30 ( V_30 , V_12 ) ;
F_83 ( & V_30 -> V_87 ) ;
return 0 ;
}
static void F_122 ( unsigned type , T_4 V_17 )
{
struct V_29 * V_30 = V_86 [ type ] ;
struct V_10 * V_12 ;
F_79 ( & V_30 -> V_87 ) ;
V_12 = F_17 ( & V_30 -> V_31 , V_17 ) ;
if ( ! V_12 ) {
F_83 ( & V_30 -> V_87 ) ;
return;
}
F_22 ( & V_30 -> V_31 , V_12 ) ;
F_30 ( V_30 , V_12 ) ;
F_83 ( & V_30 -> V_87 ) ;
}
static void F_123 ( unsigned type )
{
struct V_29 * V_30 = V_86 [ type ] ;
struct V_10 * V_12 , * V_107 ;
if ( ! V_30 )
return;
F_79 ( & V_30 -> V_87 ) ;
F_124 (entry, n, &tree->rbroot, rbnode)
F_25 ( V_12 ) ;
V_30 -> V_31 = V_108 ;
F_83 ( & V_30 -> V_87 ) ;
F_39 ( V_30 ) ;
V_86 [ type ] = NULL ;
}
static void F_125 ( unsigned type )
{
struct V_29 * V_30 ;
V_30 = F_60 ( sizeof( struct V_29 ) , V_34 ) ;
if ( ! V_30 ) {
F_36 ( L_16 , type ) ;
return;
}
V_30 -> V_31 = V_108 ;
F_126 ( & V_30 -> V_87 ) ;
V_86 [ type ] = V_30 ;
}
static int T_2 F_127 ( void )
{
if ( ! F_128 () )
return - V_63 ;
V_109 = F_129 ( L_17 , NULL ) ;
if ( ! V_109 )
return - V_35 ;
F_130 ( L_18 , V_110 ,
V_109 , & V_97 ) ;
F_130 ( L_19 , V_110 ,
V_109 , & V_98 ) ;
F_130 ( L_20 , V_110 ,
V_109 , & V_104 ) ;
F_130 ( L_21 , V_110 ,
V_109 , & V_99 ) ;
F_130 ( L_22 , V_110 ,
V_109 , & V_103 ) ;
F_130 ( L_23 , V_110 ,
V_109 , & V_91 ) ;
F_130 ( L_24 , V_110 ,
V_109 , & V_106 ) ;
F_130 ( L_25 , V_110 ,
V_109 , & V_3 ) ;
F_131 ( L_26 , V_110 ,
V_109 , & V_28 ) ;
return 0 ;
}
static void T_8 F_132 ( void )
{
F_133 ( V_109 ) ;
}
static int T_2 F_127 ( void )
{
return 0 ;
}
static void T_8 F_132 ( void ) { }
static int T_2 F_134 ( void )
{
struct V_5 * V_6 ;
int V_50 ;
V_65 = true ;
if ( F_8 () ) {
F_36 ( L_27 ) ;
goto V_111;
}
V_50 = F_135 ( V_112 , L_28 ,
F_33 , F_38 ) ;
if ( V_50 ) {
F_36 ( L_29 ) ;
goto V_113;
}
V_50 = F_136 ( V_53 ,
L_30 ,
F_40 ,
F_47 ) ;
if ( V_50 )
goto V_114;
V_6 = F_137 () ;
if ( ! V_6 ) {
F_36 ( L_31 ) ;
goto V_115;
}
F_138 ( L_32 , V_6 -> V_40 ,
F_58 ( V_6 -> V_8 ) ) ;
F_139 ( & V_6 -> V_42 , & V_41 ) ;
F_140 ( & V_116 ) ;
if ( F_127 () )
F_141 ( L_33 ) ;
return 0 ;
V_115:
F_142 ( V_53 ) ;
V_114:
F_143 ( V_112 ) ;
V_113:
F_10 () ;
V_111:
V_62 = true ;
V_95 = false ;
return - V_35 ;
}
