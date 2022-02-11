int F_1 ( int V_1 , const char * V_2 , ... )
{
T_1 args ;
int V_3 = 0 ;
if ( V_4 >= V_1 ) {
va_start ( args , V_2 ) ;
V_3 = vfprintf ( V_5 , V_2 , args ) ;
va_end ( args ) ;
}
return V_3 ;
}
static T_2 * F_2 ( struct V_6 * V_7 )
{
T_2 * V_3 ;
char * V_8 ;
if ( F_3 ( & V_8 , L_1 V_9 L_2
L_3 V_9 L_4 V_9 L_2
L_5 ,
V_7 -> V_10 . V_11 . V_12 , V_7 -> V_10 . V_11 . V_13 ,
V_7 -> V_10 . V_11 . V_14 , V_7 -> V_10 . V_11 . V_15 ,
V_7 -> V_10 . V_11 . V_16 , V_7 -> V_10 . V_11 . V_17 ) < 0 ) {
V_3 = F_4 () ;
} else {
V_3 = F_5 ( V_8 ) ;
free ( V_8 ) ;
}
return V_3 ;
}
static T_2 * F_6 ( struct V_6 * V_7 )
{
return F_7 ( L_6
L_7 V_18 L_8 ,
V_7 -> V_10 . V_19 . type == V_20 ? L_9 : L_10 ,
V_7 -> V_10 . V_21 . V_12 ,
V_7 -> V_10 . V_21 . V_22 ,
V_7 -> V_10 . V_21 . V_13 ,
V_7 -> V_10 . V_21 . V_23 ,
V_7 -> V_10 . V_21 . time ) ;
}
static T_2 * F_8 ( struct V_6 * V_7 )
{
return F_7 ( L_11 ,
V_7 -> V_10 . V_24 . V_12 ,
V_7 -> V_10 . V_24 . V_13 ,
V_7 -> V_10 . V_24 . V_24 ) ;
}
static T_2 * F_9 ( struct V_6 * V_7 )
{
struct V_25 * V_26 = (struct V_25 * ) ( & V_7 -> V_10 . V_19 + 1 ) ;
return F_7 ( L_12 V_18 L_13 V_18
L_14 V_18 L_15 ,
V_7 -> V_10 . V_19 . type == V_27 ? L_16 : L_17 ,
V_26 -> time , V_26 -> V_28 , V_26 -> V_29 ) ;
}
static T_2 * F_10 ( struct V_6 * V_7 )
{
T_2 * V_3 ;
char * V_8 ;
if ( F_3 ( & V_8 , L_18 V_9 L_2
L_19 V_9 L_15 ,
V_7 -> V_10 . V_30 . V_28 , V_7 -> V_10 . V_30 . V_30 ) < 0 ) {
V_3 = F_4 () ;
} else {
V_3 = F_5 ( V_8 ) ;
free ( V_8 ) ;
}
return V_3 ;
}
static T_2 * F_11 ( struct V_6 * V_7 )
{
return F_7 ( L_20 ,
V_7 -> V_10 . V_31 . V_12 ,
V_7 -> V_10 . V_31 . V_13 ) ;
}
static T_2 * F_12 ( struct V_6 * V_7 )
{
T_2 * V_3 ;
char * V_8 ;
if ( F_3 ( & V_8 , L_21 ) < 0 ) {
V_3 = F_4 () ;
} else {
V_3 = F_5 ( V_8 ) ;
free ( V_8 ) ;
}
return V_3 ;
}
static int F_13 ( void )
{
int V_32 ;
V_33 . V_34 =
V_35 . V_34 =
V_36 . V_34 =
V_37 . V_34 =
V_38 . V_34 =
V_39 . V_34 =
V_40 . V_34 = V_41 ;
V_32 = F_14 ( & V_33 ) ;
if ( V_32 < 0 )
goto V_42;
V_32 = F_14 ( & V_37 ) ;
if ( V_32 < 0 )
goto V_42;
V_32 = F_14 ( & V_35 ) ;
if ( V_32 < 0 )
goto V_42;
V_32 = F_14 ( & V_36 ) ;
if ( V_32 < 0 )
goto V_42;
V_32 = F_14 ( & V_40 ) ;
if ( V_32 < 0 )
goto V_42;
V_32 = F_14 ( & V_38 ) ;
if ( V_32 < 0 )
goto V_42;
V_32 = F_14 ( & V_39 ) ;
if ( V_32 < 0 )
goto V_42;
V_42:
return V_32 ;
}
static T_2 * F_15 ( union V_43 * V_10 )
{
struct V_6 * V_7 ;
T_3 * V_44 ;
if ( V_10 -> V_19 . type < V_45 ||
V_10 -> V_19 . type > V_46 )
return NULL ;
V_44 = V_47 [ V_10 -> V_19 . type ] ;
V_7 = F_16 ( struct V_6 , V_44 ) ;
if ( V_7 != NULL )
memcpy ( & V_7 -> V_10 , V_10 , V_10 -> V_19 . V_48 ) ;
return ( T_2 * ) V_7 ;
}
static int F_17 ( struct V_49 * V_50 ,
T_2 * args , T_2 * V_51 )
{
static char * V_52 [] = { L_22 , NULL } ;
char * V_53 = NULL ;
if ( ! F_18 ( args , V_51 , L_23 ,
V_52 , & V_53 ) )
return - 1 ;
V_50 -> V_54 = F_19 ( V_53 ) ;
if ( V_50 -> V_54 == NULL )
return - 1 ;
return 0 ;
}
static void F_20 ( struct V_49 * V_50 )
{
F_21 ( V_50 -> V_54 ) ;
V_50 -> V_55 -> V_56 ( ( T_2 * ) V_50 ) ;
}
static T_4 F_22 ( T_2 * V_57 )
{
struct V_49 * V_50 = ( void * ) V_57 ;
return V_50 -> V_54 -> V_58 ;
}
static T_2 * F_23 ( T_2 * V_57 , T_4 V_59 )
{
struct V_49 * V_50 = ( void * ) V_57 ;
if ( V_59 >= V_50 -> V_54 -> V_58 )
return NULL ;
return F_24 ( L_24 , V_50 -> V_54 -> V_60 [ V_59 ] ) ;
}
static int F_25 ( void )
{
V_61 . V_34 = V_41 ;
return F_14 ( & V_61 ) ;
}
static int F_26 ( struct V_62 * V_63 ,
T_2 * args , T_2 * V_51 )
{
static char * V_52 [] = { L_25 , L_26 , L_27 , NULL } ;
int V_12 = - 1 , V_13 = - 1 , V_64 = V_65 ;
if ( ! F_18 ( args , V_51 , L_28 ,
V_52 , & V_12 , & V_13 , & V_64 ) )
return - 1 ;
V_63 -> V_66 = F_27 ( V_12 , V_13 , V_64 ) ;
if ( V_63 -> V_66 == NULL )
return - 1 ;
return 0 ;
}
static void F_28 ( struct V_62 * V_63 )
{
F_29 ( V_63 -> V_66 ) ;
V_63 -> V_55 -> V_56 ( ( T_2 * ) V_63 ) ;
}
static T_4 F_30 ( T_2 * V_57 )
{
struct V_62 * V_63 = ( void * ) V_57 ;
return V_63 -> V_66 -> V_58 ;
}
static T_2 * F_31 ( T_2 * V_57 , T_4 V_59 )
{
struct V_62 * V_63 = ( void * ) V_57 ;
if ( V_59 >= V_63 -> V_66 -> V_58 )
return NULL ;
return F_24 ( L_24 , V_63 -> V_66 -> V_60 [ V_59 ] ) ;
}
static int F_32 ( void )
{
V_67 . V_34 = V_41 ;
return F_14 ( & V_67 ) ;
}
static int F_33 ( struct V_68 * V_69 ,
T_2 * args , T_2 * V_51 )
{
struct V_70 V_71 = {
. type = V_72 ,
. V_73 = V_74 ,
. V_75 = V_76 | V_77 ,
} ;
static char * V_52 [] = {
L_29 ,
L_30 ,
L_31 ,
L_32 ,
L_33 ,
L_34 ,
L_35 ,
L_36 ,
L_37 ,
L_38 ,
L_39 ,
L_40 ,
L_41 ,
L_42 ,
L_43 ,
L_44 ,
L_45 ,
L_46 ,
L_47 ,
L_48 ,
L_49 ,
L_50 ,
L_51 ,
L_52 ,
L_53 ,
L_54 ,
L_55 ,
L_56 ,
NULL
} ;
T_5 V_78 = 0 ;
T_6 V_79 = 0 ,
V_80 = 0 ,
V_81 = 0 ,
V_82 = 0 ,
V_83 = 0 ,
V_84 = 0 ,
V_85 = 0 ,
V_86 = 0 ,
V_11 = 0 ,
V_24 = 0 ,
V_87 = 1 ,
V_88 = 0 ,
V_89 = 0 ,
V_90 = 0 ,
V_91 = 0 ,
V_92 = 0 ,
V_93 = 0 ,
V_94 = 1 ;
int V_95 = 0 ;
if ( ! F_18 ( args , V_51 ,
L_57 , V_52 ,
& V_71 . type , & V_71 . V_73 , & V_71 . V_96 ,
& V_78 , & V_71 . V_75 ,
& V_71 . V_97 , & V_79 , & V_80 ,
& V_81 , & V_82 , & V_83 ,
& V_84 , & V_85 , & V_86 ,
& V_11 , & V_24 , & V_87 , & V_88 ,
& V_89 , & V_90 , & V_91 ,
& V_92 , & V_93 , & V_94 ,
& V_71 . V_98 , & V_71 . V_99 ,
& V_71 . V_100 , & V_71 . V_101 , & V_95 ) )
return - 1 ;
if ( V_78 != 0 ) {
if ( V_71 . V_96 != 0 )
return - 1 ;
V_71 . V_78 = V_78 ;
}
V_71 . V_79 = V_79 ;
V_71 . V_80 = V_80 ;
V_71 . V_81 = V_81 ;
V_71 . V_82 = V_82 ;
V_71 . V_83 = V_83 ;
V_71 . V_84 = V_84 ;
V_71 . V_85 = V_85 ;
V_71 . V_86 = V_86 ;
V_71 . V_11 = V_11 ;
V_71 . V_24 = V_24 ;
V_71 . V_87 = V_87 ;
V_71 . V_88 = V_88 ;
V_71 . V_89 = V_89 ;
V_71 . V_90 = V_90 ;
V_71 . V_91 = V_91 ;
V_71 . V_92 = V_92 ;
V_71 . V_93 = V_93 ;
V_71 . V_94 = V_94 ;
F_34 ( & V_69 -> V_102 , & V_71 , V_95 ) ;
return 0 ;
}
static void F_35 ( struct V_68 * V_69 )
{
F_36 ( & V_69 -> V_102 ) ;
V_69 -> V_55 -> V_56 ( ( T_2 * ) V_69 ) ;
}
static T_2 * F_37 ( struct V_68 * V_69 ,
T_2 * args , T_2 * V_51 )
{
struct V_103 * V_102 = & V_69 -> V_102 ;
struct V_104 * V_54 = NULL ;
struct V_105 * V_66 = NULL ;
T_2 * V_50 = NULL , * V_63 = NULL ;
int V_106 = 0 , V_80 = 0 ;
static char * V_52 [] = { L_58 , L_59 , L_60 , L_36 , NULL } ;
if ( ! F_18 ( args , V_51 , L_61 , V_52 ,
& V_50 , & V_63 , & V_106 , & V_80 ) )
return NULL ;
if ( V_63 != NULL )
V_66 = ( (struct V_62 * ) V_63 ) -> V_66 ;
if ( V_50 != NULL )
V_54 = ( (struct V_49 * ) V_50 ) -> V_54 ;
V_102 -> V_71 . V_80 = V_80 ;
if ( F_38 ( V_102 , V_54 , V_66 ) < 0 ) {
F_39 ( V_107 ) ;
return NULL ;
}
F_40 ( V_108 ) ;
return V_108 ;
}
static int F_41 ( void )
{
V_109 . V_34 = V_41 ;
return F_14 ( & V_109 ) ;
}
static int F_42 ( struct V_110 * V_111 ,
T_2 * args , T_2 * V_51 V_112 )
{
T_2 * V_50 = NULL , * V_63 = NULL ;
struct V_104 * V_54 ;
struct V_105 * V_66 ;
if ( ! F_43 ( args , L_62 , & V_50 , & V_63 ) )
return - 1 ;
V_66 = ( (struct V_62 * ) V_63 ) -> V_66 ;
V_54 = ( (struct V_49 * ) V_50 ) -> V_54 ;
F_44 ( & V_111 -> V_113 , V_54 , V_66 ) ;
return 0 ;
}
static void F_45 ( struct V_110 * V_111 )
{
F_46 ( & V_111 -> V_113 ) ;
V_111 -> V_55 -> V_56 ( ( T_2 * ) V_111 ) ;
}
static T_2 * F_47 ( struct V_110 * V_111 ,
T_2 * args , T_2 * V_51 )
{
struct V_114 * V_113 = & V_111 -> V_113 ;
static char * V_52 [] = { L_63 , L_64 , NULL } ;
int V_115 = 128 , V_116 = false ;
if ( ! F_18 ( args , V_51 , L_65 , V_52 ,
& V_115 , & V_116 ) )
return NULL ;
if ( F_48 ( V_113 , V_115 , V_116 ) < 0 ) {
F_39 ( V_107 ) ;
return NULL ;
}
F_40 ( V_108 ) ;
return V_108 ;
}
static T_2 * F_49 ( struct V_110 * V_111 ,
T_2 * args , T_2 * V_51 )
{
struct V_114 * V_113 = & V_111 -> V_113 ;
static char * V_52 [] = { L_66 , NULL } ;
int V_117 = - 1 , V_118 ;
if ( ! F_18 ( args , V_51 , L_67 , V_52 , & V_117 ) )
return NULL ;
V_118 = F_50 ( V_113 -> V_119 , V_113 -> V_120 , V_117 ) ;
if ( V_118 < 0 ) {
F_39 ( V_107 ) ;
return NULL ;
}
return F_24 ( L_24 , V_118 ) ;
}
static T_2 * F_51 ( struct V_110 * V_111 ,
T_2 * args V_112 ,
T_2 * V_51 V_112 )
{
struct V_114 * V_113 = & V_111 -> V_113 ;
T_2 * V_121 = F_52 ( 0 ) ;
int V_59 ;
for ( V_59 = 0 ; V_59 < V_113 -> V_120 ; ++ V_59 ) {
T_2 * V_122 ;
T_7 * V_123 = fdopen ( V_113 -> V_119 [ V_59 ] . V_124 , L_68 ) ;
if ( V_123 == NULL )
goto V_125;
V_122 = F_53 ( V_123 , L_69 , L_68 , NULL ) ;
if ( V_122 == NULL )
goto V_125;
if ( F_54 ( V_121 , V_122 ) != 0 ) {
F_55 ( V_122 ) ;
goto V_125;
}
F_55 ( V_122 ) ;
}
return V_121 ;
V_125:
return F_4 () ;
}
static T_2 * F_56 ( struct V_110 * V_111 ,
T_2 * args ,
T_2 * V_51 V_112 )
{
struct V_114 * V_113 = & V_111 -> V_113 ;
T_2 * V_69 ;
struct V_103 * V_102 ;
if ( ! F_43 ( args , L_70 , & V_69 ) )
return NULL ;
F_40 ( V_69 ) ;
V_102 = & ( (struct V_68 * ) V_69 ) -> V_102 ;
V_102 -> V_95 = V_113 -> V_126 ;
F_57 ( V_113 , V_102 ) ;
return F_24 ( L_24 , V_113 -> V_126 ) ;
}
static T_2 * F_58 ( struct V_110 * V_111 ,
T_2 * args , T_2 * V_51 )
{
struct V_114 * V_113 = & V_111 -> V_113 ;
union V_43 * V_10 ;
int V_94 = 1 , V_127 ;
static char * V_52 [] = { L_71 , L_52 , NULL } ;
int V_32 ;
if ( ! F_18 ( args , V_51 , L_72 , V_52 ,
& V_127 , & V_94 ) )
return NULL ;
V_10 = F_59 ( V_113 , V_127 ) ;
if ( V_10 != NULL ) {
T_2 * V_128 = F_15 ( V_10 ) ;
struct V_6 * V_7 = (struct V_6 * ) V_128 ;
F_60 ( V_113 , V_127 ) ;
if ( V_128 == NULL )
return F_4 () ;
V_32 = F_61 ( V_113 , V_10 , & V_7 -> V_129 ) ;
if ( V_32 )
return F_62 ( V_107 ,
L_73 , V_32 ) ;
return V_128 ;
}
F_40 ( V_108 ) ;
return V_108 ;
}
static T_2 * F_63 ( struct V_110 * V_111 ,
T_2 * args , T_2 * V_51 )
{
struct V_114 * V_113 = & V_111 -> V_113 ;
int V_106 = 0 ;
static char * V_52 [] = { L_60 , NULL } ;
if ( ! F_18 ( args , V_51 , L_61 , V_52 , & V_106 ) )
return NULL ;
if ( V_106 )
F_64 ( V_113 ) ;
if ( F_65 ( V_113 ) < 0 ) {
F_39 ( V_107 ) ;
return NULL ;
}
F_40 ( V_108 ) ;
return V_108 ;
}
static T_4 F_66 ( T_2 * V_57 )
{
struct V_110 * V_111 = ( void * ) V_57 ;
return V_111 -> V_113 . V_126 ;
}
static T_2 * F_67 ( T_2 * V_57 , T_4 V_59 )
{
struct V_110 * V_111 = ( void * ) V_57 ;
struct V_103 * V_130 ;
if ( V_59 >= V_111 -> V_113 . V_126 )
return NULL ;
F_68 (pos, &pevlist->evlist.entries, node)
if ( V_59 -- == 0 )
break;
return F_24 ( L_70 , F_69 ( V_130 , struct V_68 , V_102 ) ) ;
}
static int F_70 ( void )
{
V_131 . V_34 = V_41 ;
return F_14 ( & V_131 ) ;
}
T_8 F_71 ( void )
{
T_2 * V_57 ;
int V_59 ;
T_2 * V_132 , * V_133 = F_72 ( L_69 , V_134 ) ;
if ( V_133 == NULL ||
F_13 () < 0 ||
F_70 () < 0 ||
F_41 () < 0 ||
F_32 () < 0 ||
F_25 () < 0 )
return;
V_135 = F_73 ( V_136 ) ;
F_40 ( & V_131 ) ;
F_74 ( V_133 , L_74 , ( T_2 * ) & V_131 ) ;
F_40 ( & V_109 ) ;
F_74 ( V_133 , L_75 , ( T_2 * ) & V_109 ) ;
F_40 ( & V_67 ) ;
F_74 ( V_133 , L_76 , ( T_2 * ) & V_67 ) ;
F_40 ( & V_61 ) ;
F_74 ( V_133 , L_77 , ( T_2 * ) & V_61 ) ;
V_132 = F_75 ( V_133 ) ;
if ( V_132 == NULL )
goto error;
for ( V_59 = 0 ; V_137 [ V_59 ] . V_138 != NULL ; V_59 ++ ) {
V_57 = F_76 ( V_137 [ V_59 ] . V_139 ) ;
if ( V_57 == NULL )
goto error;
F_77 ( V_132 , V_137 [ V_59 ] . V_138 , V_57 ) ;
F_55 ( V_57 ) ;
}
error:
if ( F_78 () )
F_79 ( V_140 , L_78 ) ;
}
void F_80 ( struct V_70 * V_71 , T_9 V_12 , int V_127 ,
int V_124 , int V_141 , unsigned long V_142 )
{
}
