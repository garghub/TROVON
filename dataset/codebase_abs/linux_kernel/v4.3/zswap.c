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
struct V_10 * V_12 = NULL ;
V_12 = F_17 ( V_16 , V_17 ) ;
if ( V_12 )
F_29 ( V_12 ) ;
return V_12 ;
}
static int F_33 ( unsigned long V_32 , unsigned long V_33 )
{
T_5 * V_34 ;
switch ( V_32 ) {
case V_35 :
V_34 = F_34 ( V_4 * 2 , V_36 , F_35 ( V_33 ) ) ;
if ( ! V_34 ) {
F_36 ( L_1 ) ;
return V_37 ;
}
F_37 ( V_38 , V_33 ) = V_34 ;
break;
case V_39 :
case V_40 :
V_34 = F_37 ( V_38 , V_33 ) ;
F_38 ( V_34 ) ;
F_37 ( V_38 , V_33 ) = NULL ;
break;
default:
break;
}
return V_41 ;
}
static int F_39 ( struct V_42 * V_43 ,
unsigned long V_32 , void * V_44 )
{
return F_33 ( V_32 , ( unsigned long ) V_44 ) ;
}
static int T_2 F_40 ( void )
{
unsigned long V_33 ;
F_41 () ;
F_42 (cpu)
if ( F_33 ( V_35 , V_33 ) ==
V_37 )
goto V_45;
F_43 ( & V_46 ) ;
F_44 () ;
return 0 ;
V_45:
F_42 (cpu)
F_33 ( V_40 , V_33 ) ;
F_44 () ;
return - V_47 ;
}
static void F_45 ( void )
{
unsigned long V_33 ;
F_41 () ;
F_42 (cpu)
F_33 ( V_40 , V_33 ) ;
F_46 ( & V_46 ) ;
F_44 () ;
}
static int F_47 ( struct V_5 * V_6 ,
unsigned long V_32 , unsigned long V_33 )
{
struct V_48 * V_49 ;
switch ( V_32 ) {
case V_35 :
if ( F_48 ( * F_49 ( V_6 -> V_49 , V_33 ) ) )
break;
V_49 = F_50 ( V_6 -> V_50 , 0 , 0 ) ;
if ( F_51 ( V_49 ) ) {
F_36 ( L_2 ,
V_6 -> V_50 , F_52 ( V_49 ) ) ;
return V_37 ;
}
* F_49 ( V_6 -> V_49 , V_33 ) = V_49 ;
break;
case V_39 :
case V_40 :
V_49 = * F_49 ( V_6 -> V_49 , V_33 ) ;
if ( ! F_51 ( V_49 ) )
F_53 ( V_49 ) ;
* F_49 ( V_6 -> V_49 , V_33 ) = NULL ;
break;
default:
break;
}
return V_41 ;
}
static int F_54 ( struct V_42 * V_43 ,
unsigned long V_32 , void * V_44 )
{
unsigned long V_33 = ( unsigned long ) V_44 ;
struct V_5 * V_6 = F_55 ( V_43 , F_56 ( * V_6 ) , V_51 ) ;
return F_47 ( V_6 , V_32 , V_33 ) ;
}
static int F_57 ( struct V_5 * V_6 )
{
unsigned long V_33 ;
memset ( & V_6 -> V_51 , 0 , sizeof( V_6 -> V_51 ) ) ;
V_6 -> V_51 . V_52 = F_54 ;
F_41 () ;
F_42 (cpu)
if ( F_47 ( V_6 , V_35 , V_33 ) ==
V_37 )
goto V_45;
F_43 ( & V_6 -> V_51 ) ;
F_44 () ;
return 0 ;
V_45:
F_42 (cpu)
F_47 ( V_6 , V_40 , V_33 ) ;
F_44 () ;
return - V_47 ;
}
static void F_58 ( struct V_5 * V_6 )
{
unsigned long V_33 ;
F_41 () ;
F_42 (cpu)
F_47 ( V_6 , V_40 , V_33 ) ;
F_46 ( & V_6 -> V_51 ) ;
F_44 () ;
}
static struct V_5 * F_59 ( void )
{
struct V_5 * V_6 ;
V_6 = F_60 ( & V_53 , F_56 ( * V_6 ) , V_54 ) ;
F_48 ( ! V_6 ) ;
return V_6 ;
}
static struct V_5 * F_61 ( void )
{
F_62 ( & V_55 ) ;
return F_59 () ;
}
static struct V_5 * F_63 ( void )
{
struct V_5 * V_6 ;
F_4 () ;
V_6 = F_59 () ;
if ( ! V_6 || ! F_64 ( V_6 ) )
V_6 = NULL ;
F_7 () ;
return V_6 ;
}
static struct V_5 * F_65 ( void )
{
struct V_5 * V_6 , * V_56 = NULL ;
F_4 () ;
F_5 (pool, &zswap_pools, list)
V_56 = V_6 ;
if ( ! F_48 ( ! V_56 ) && ! F_64 ( V_56 ) )
V_56 = NULL ;
F_7 () ;
return V_56 ;
}
static struct V_5 * F_66 ( char * type , char * V_57 )
{
struct V_5 * V_6 ;
F_62 ( & V_55 ) ;
F_5 (pool, &zswap_pools, list) {
if ( strncmp ( V_6 -> V_50 , V_57 , sizeof( V_6 -> V_50 ) ) )
continue;
if ( strncmp ( F_67 ( V_6 -> V_8 ) , type ,
sizeof( V_58 ) ) )
continue;
if ( ! F_64 ( V_6 ) )
continue;
return V_6 ;
}
return NULL ;
}
static struct V_5 * F_68 ( char * type , char * V_57 )
{
struct V_5 * V_6 ;
T_3 V_11 = V_59 | V_60 ;
V_6 = F_69 ( sizeof( * V_6 ) , V_36 ) ;
if ( ! V_6 ) {
F_36 ( L_3 ) ;
return NULL ;
}
V_6 -> V_8 = F_70 ( type , L_4 , V_11 , & V_61 ) ;
if ( ! V_6 -> V_8 ) {
F_36 ( L_5 , type ) ;
goto error;
}
F_71 ( L_6 , F_67 ( V_6 -> V_8 ) ) ;
F_72 ( V_6 -> V_50 , V_57 , sizeof( V_6 -> V_50 ) ) ;
V_6 -> V_49 = F_73 ( struct V_48 * ) ;
if ( ! V_6 -> V_49 ) {
F_36 ( L_7 ) ;
goto error;
}
if ( F_57 ( V_6 ) )
goto error;
F_71 ( L_8 , V_6 -> V_50 ) ;
F_74 ( & V_6 -> V_62 ) ;
F_75 ( & V_6 -> V_54 ) ;
F_76 ( L_9 , V_6 ) ;
return V_6 ;
error:
F_77 ( V_6 -> V_49 ) ;
if ( V_6 -> V_8 )
F_78 ( V_6 -> V_8 ) ;
F_38 ( V_6 ) ;
return NULL ;
}
static struct V_5 * F_79 ( void )
{
if ( ! F_80 ( V_63 , 0 , 0 ) ) {
F_36 ( L_10 ,
V_63 , V_64 ) ;
strncpy ( V_63 , V_64 ,
sizeof( V_63 ) ) ;
}
if ( ! F_81 ( V_58 ) ) {
F_36 ( L_11 ,
V_58 , V_65 ) ;
strncpy ( V_58 , V_65 ,
sizeof( V_58 ) ) ;
}
return F_68 ( V_58 , V_63 ) ;
}
static void F_82 ( struct V_5 * V_6 )
{
F_76 ( L_12 , V_6 ) ;
F_58 ( V_6 ) ;
F_77 ( V_6 -> V_49 ) ;
F_78 ( V_6 -> V_8 ) ;
F_38 ( V_6 ) ;
}
static int T_6 F_64 ( struct V_5 * V_6 )
{
return F_83 ( & V_6 -> V_62 ) ;
}
static void F_84 ( struct V_66 * V_67 )
{
struct V_5 * V_6 = F_55 ( V_67 , F_56 ( * V_6 ) , V_66 ) ;
F_48 ( F_83 ( & V_6 -> V_62 ) ) ;
F_82 ( V_6 ) ;
}
static void F_85 ( struct V_62 * V_62 )
{
struct V_5 * V_6 ;
V_6 = F_55 ( V_62 , F_56 ( * V_6 ) , V_62 ) ;
F_86 ( & V_55 ) ;
F_48 ( V_6 == F_61 () ) ;
F_87 ( & V_6 -> V_54 ) ;
F_88 ( & V_6 -> V_66 , F_84 ) ;
F_89 ( & V_55 ) ;
}
static void F_27 ( struct V_5 * V_6 )
{
F_90 ( & V_6 -> V_62 , F_85 ) ;
}
static int F_91 ( const char * V_68 , const struct V_69 * V_70 ,
char * type , char * V_57 )
{
struct V_5 * V_6 , * V_71 = NULL ;
char V_72 [ V_70 -> V_72 -> V_73 ] , * V_74 ;
int V_75 ;
F_72 ( V_72 , V_68 , V_70 -> V_72 -> V_73 ) ;
V_74 = F_92 ( V_72 ) ;
if ( ! V_76 )
return F_93 ( V_74 , V_70 ) ;
if ( ! strncmp ( V_70 -> V_72 -> string , V_74 , V_70 -> V_72 -> V_73 ) )
return 0 ;
if ( ! type ) {
type = V_74 ;
if ( ! F_81 ( type ) ) {
F_36 ( L_13 , type ) ;
return - V_77 ;
}
} else if ( ! V_57 ) {
V_57 = V_74 ;
if ( ! F_80 ( V_57 , 0 , 0 ) ) {
F_36 ( L_14 , V_57 ) ;
return - V_77 ;
}
}
F_86 ( & V_55 ) ;
V_6 = F_66 ( type , V_57 ) ;
if ( V_6 ) {
F_76 ( L_15 , V_6 ) ;
F_87 ( & V_6 -> V_54 ) ;
} else {
F_89 ( & V_55 ) ;
V_6 = F_68 ( type , V_57 ) ;
F_86 ( & V_55 ) ;
}
if ( V_6 )
V_75 = F_93 ( V_74 , V_70 ) ;
else
V_75 = - V_78 ;
if ( ! V_75 ) {
V_71 = F_61 () ;
F_94 ( & V_6 -> V_54 , & V_53 ) ;
} else if ( V_6 ) {
F_95 ( & V_6 -> V_54 , & V_53 ) ;
V_71 = V_6 ;
}
F_89 ( & V_55 ) ;
if ( V_71 )
F_27 ( V_71 ) ;
return V_75 ;
}
static int F_96 ( const char * V_68 ,
const struct V_69 * V_70 )
{
return F_91 ( V_68 , V_70 , V_58 , NULL ) ;
}
static int F_97 ( const char * V_68 ,
const struct V_69 * V_70 )
{
return F_91 ( V_68 , V_70 , NULL , V_63 ) ;
}
static int F_98 ( T_7 V_12 ,
struct V_79 * * V_80 )
{
bool V_81 ;
* V_80 = F_99 ( V_12 , V_36 ,
NULL , 0 , & V_81 ) ;
if ( V_81 )
return V_82 ;
if ( ! * V_80 )
return V_83 ;
return V_84 ;
}
static int F_100 ( struct V_8 * V_6 , unsigned long V_27 )
{
struct V_85 * V_86 ;
T_7 V_87 ;
struct V_29 * V_30 ;
T_4 V_17 ;
struct V_10 * V_12 ;
struct V_79 * V_79 ;
struct V_48 * V_49 ;
T_5 * V_88 , * V_34 ;
unsigned int V_89 ;
int V_75 ;
struct V_90 V_91 = {
. V_92 = V_93 ,
} ;
V_86 = F_101 ( V_6 , V_27 , V_94 ) ;
V_87 = V_86 -> V_87 ;
F_102 ( V_6 , V_27 ) ;
V_30 = V_95 [ F_103 ( V_87 ) ] ;
V_17 = F_104 ( V_87 ) ;
F_86 ( & V_30 -> V_96 ) ;
V_12 = F_32 ( & V_30 -> V_31 , V_17 ) ;
if ( ! V_12 ) {
F_89 ( & V_30 -> V_96 ) ;
return 0 ;
}
F_89 ( & V_30 -> V_96 ) ;
F_31 ( V_17 != V_12 -> V_17 ) ;
switch ( F_98 ( V_87 , & V_79 ) ) {
case V_83 :
V_75 = - V_47 ;
goto V_97;
case V_84 :
F_105 ( V_79 ) ;
V_75 = - V_26 ;
goto V_97;
case V_82 :
V_89 = V_4 ;
V_88 = ( T_5 * ) F_101 ( V_12 -> V_6 -> V_8 , V_12 -> V_27 ,
V_94 ) + sizeof( struct V_85 ) ;
V_34 = F_106 ( V_79 ) ;
V_49 = * F_107 ( V_12 -> V_6 -> V_49 ) ;
V_75 = F_108 ( V_49 , V_88 , V_12 -> V_98 ,
V_34 , & V_89 ) ;
F_109 ( V_12 -> V_6 -> V_49 ) ;
F_110 ( V_34 ) ;
F_102 ( V_12 -> V_6 -> V_8 , V_12 -> V_27 ) ;
F_31 ( V_75 ) ;
F_31 ( V_89 != V_4 ) ;
F_111 ( V_79 ) ;
}
F_112 ( V_79 ) ;
F_113 ( V_79 , & V_91 , V_99 ) ;
F_105 ( V_79 ) ;
V_100 ++ ;
F_86 ( & V_30 -> V_96 ) ;
F_30 ( V_30 , V_12 ) ;
if ( V_12 == F_17 ( & V_30 -> V_31 , V_17 ) )
F_30 ( V_30 , V_12 ) ;
F_89 ( & V_30 -> V_96 ) ;
goto V_101;
V_97:
F_86 ( & V_30 -> V_96 ) ;
F_30 ( V_30 , V_12 ) ;
F_89 ( & V_30 -> V_96 ) ;
V_101:
return V_75 ;
}
static int F_114 ( void )
{
struct V_5 * V_6 ;
int V_75 ;
V_6 = F_65 () ;
if ( ! V_6 )
return - V_77 ;
V_75 = F_115 ( V_6 -> V_8 , 1 , NULL ) ;
F_27 ( V_6 ) ;
return V_75 ;
}
static int F_116 ( unsigned type , T_4 V_17 ,
struct V_79 * V_79 )
{
struct V_29 * V_30 = V_95 [ type ] ;
struct V_10 * V_12 , * V_22 ;
struct V_48 * V_49 ;
int V_75 ;
unsigned int V_89 = V_4 , V_102 ;
unsigned long V_27 ;
char * V_103 ;
T_5 * V_88 , * V_34 ;
struct V_85 * V_86 ;
if ( ! V_104 || ! V_30 ) {
V_75 = - V_105 ;
goto V_106;
}
if ( F_1 () ) {
V_107 ++ ;
if ( F_114 () ) {
V_108 ++ ;
V_75 = - V_47 ;
goto V_106;
}
}
V_12 = F_12 ( V_36 ) ;
if ( ! V_12 ) {
V_109 ++ ;
V_75 = - V_47 ;
goto V_106;
}
V_12 -> V_6 = F_63 () ;
if ( ! V_12 -> V_6 ) {
V_75 = - V_78 ;
goto V_110;
}
V_34 = F_117 ( V_38 ) ;
V_49 = * F_107 ( V_12 -> V_6 -> V_49 ) ;
V_88 = F_106 ( V_79 ) ;
V_75 = F_118 ( V_49 , V_88 , V_4 , V_34 , & V_89 ) ;
F_110 ( V_88 ) ;
F_109 ( V_12 -> V_6 -> V_49 ) ;
if ( V_75 ) {
V_75 = - V_78 ;
goto V_111;
}
V_102 = V_89 + sizeof( struct V_85 ) ;
V_75 = F_119 ( V_12 -> V_6 -> V_8 , V_102 ,
V_59 | V_60 , & V_27 ) ;
if ( V_75 == - V_112 ) {
V_113 ++ ;
goto V_111;
}
if ( V_75 ) {
V_114 ++ ;
goto V_111;
}
V_86 = F_101 ( V_12 -> V_6 -> V_8 , V_27 , V_115 ) ;
V_86 -> V_87 = F_120 ( type , V_17 ) ;
V_103 = ( T_5 * ) ( V_86 + 1 ) ;
memcpy ( V_103 , V_34 , V_89 ) ;
F_102 ( V_12 -> V_6 -> V_8 , V_27 ) ;
F_121 ( V_38 ) ;
V_12 -> V_17 = V_17 ;
V_12 -> V_27 = V_27 ;
V_12 -> V_98 = V_89 ;
F_86 ( & V_30 -> V_96 ) ;
do {
V_75 = F_19 ( & V_30 -> V_31 , V_12 , & V_22 ) ;
if ( V_75 == - V_26 ) {
V_116 ++ ;
F_22 ( & V_30 -> V_31 , V_22 ) ;
F_30 ( V_30 , V_22 ) ;
}
} while ( V_75 == - V_26 );
F_89 ( & V_30 -> V_96 ) ;
F_122 ( & V_28 ) ;
F_3 () ;
return 0 ;
V_111:
F_121 ( V_38 ) ;
F_27 ( V_12 -> V_6 ) ;
V_110:
F_15 ( V_12 ) ;
V_106:
return V_75 ;
}
static int F_123 ( unsigned type , T_4 V_17 ,
struct V_79 * V_79 )
{
struct V_29 * V_30 = V_95 [ type ] ;
struct V_10 * V_12 ;
struct V_48 * V_49 ;
T_5 * V_88 , * V_34 ;
unsigned int V_89 ;
int V_75 ;
F_86 ( & V_30 -> V_96 ) ;
V_12 = F_32 ( & V_30 -> V_31 , V_17 ) ;
if ( ! V_12 ) {
F_89 ( & V_30 -> V_96 ) ;
return - 1 ;
}
F_89 ( & V_30 -> V_96 ) ;
V_89 = V_4 ;
V_88 = ( T_5 * ) F_101 ( V_12 -> V_6 -> V_8 , V_12 -> V_27 ,
V_94 ) + sizeof( struct V_85 ) ;
V_34 = F_106 ( V_79 ) ;
V_49 = * F_107 ( V_12 -> V_6 -> V_49 ) ;
V_75 = F_108 ( V_49 , V_88 , V_12 -> V_98 , V_34 , & V_89 ) ;
F_109 ( V_12 -> V_6 -> V_49 ) ;
F_110 ( V_34 ) ;
F_102 ( V_12 -> V_6 -> V_8 , V_12 -> V_27 ) ;
F_31 ( V_75 ) ;
F_86 ( & V_30 -> V_96 ) ;
F_30 ( V_30 , V_12 ) ;
F_89 ( & V_30 -> V_96 ) ;
return 0 ;
}
static void F_124 ( unsigned type , T_4 V_17 )
{
struct V_29 * V_30 = V_95 [ type ] ;
struct V_10 * V_12 ;
F_86 ( & V_30 -> V_96 ) ;
V_12 = F_17 ( & V_30 -> V_31 , V_17 ) ;
if ( ! V_12 ) {
F_89 ( & V_30 -> V_96 ) ;
return;
}
F_22 ( & V_30 -> V_31 , V_12 ) ;
F_30 ( V_30 , V_12 ) ;
F_89 ( & V_30 -> V_96 ) ;
}
static void F_125 ( unsigned type )
{
struct V_29 * V_30 = V_95 [ type ] ;
struct V_10 * V_12 , * V_117 ;
if ( ! V_30 )
return;
F_86 ( & V_30 -> V_96 ) ;
F_126 (entry, n, &tree->rbroot, rbnode)
F_25 ( V_12 ) ;
V_30 -> V_31 = V_118 ;
F_89 ( & V_30 -> V_96 ) ;
F_38 ( V_30 ) ;
V_95 [ type ] = NULL ;
}
static void F_127 ( unsigned type )
{
struct V_29 * V_30 ;
V_30 = F_69 ( sizeof( struct V_29 ) , V_36 ) ;
if ( ! V_30 ) {
F_36 ( L_16 , type ) ;
return;
}
V_30 -> V_31 = V_118 ;
F_128 ( & V_30 -> V_96 ) ;
V_95 [ type ] = V_30 ;
}
static int T_2 F_129 ( void )
{
if ( ! F_130 () )
return - V_105 ;
V_119 = F_131 ( L_4 , NULL ) ;
if ( ! V_119 )
return - V_47 ;
F_132 ( L_17 , V_120 ,
V_119 , & V_107 ) ;
F_132 ( L_18 , V_120 ,
V_119 , & V_108 ) ;
F_132 ( L_19 , V_120 ,
V_119 , & V_114 ) ;
F_132 ( L_20 , V_120 ,
V_119 , & V_109 ) ;
F_132 ( L_21 , V_120 ,
V_119 , & V_113 ) ;
F_132 ( L_22 , V_120 ,
V_119 , & V_100 ) ;
F_132 ( L_23 , V_120 ,
V_119 , & V_116 ) ;
F_132 ( L_24 , V_120 ,
V_119 , & V_3 ) ;
F_133 ( L_25 , V_120 ,
V_119 , & V_28 ) ;
return 0 ;
}
static void T_8 F_134 ( void )
{
F_135 ( V_119 ) ;
}
static int T_2 F_129 ( void )
{
return 0 ;
}
static void T_8 F_134 ( void ) { }
static int T_2 F_136 ( void )
{
struct V_5 * V_6 ;
V_76 = true ;
if ( F_8 () ) {
F_36 ( L_26 ) ;
goto V_121;
}
if ( F_40 () ) {
F_36 ( L_27 ) ;
goto V_122;
}
V_6 = F_79 () ;
if ( ! V_6 ) {
F_36 ( L_28 ) ;
goto V_123;
}
F_137 ( L_29 , V_6 -> V_50 ,
F_67 ( V_6 -> V_8 ) ) ;
F_138 ( & V_6 -> V_54 , & V_53 ) ;
F_139 ( & V_124 ) ;
if ( F_129 () )
F_140 ( L_30 ) ;
return 0 ;
V_123:
F_45 () ;
V_122:
F_10 () ;
V_121:
return - V_47 ;
}
