static T_1 * F_1 ( struct V_1 * V_2 )
{
T_1 * V_3 ;
char * V_4 ;
if ( F_2 ( & V_4 , L_1 V_5 L_2
L_3 V_5 L_4 V_5 L_2
L_5 ,
V_2 -> V_6 . V_7 . V_8 , V_2 -> V_6 . V_7 . V_9 ,
V_2 -> V_6 . V_7 . V_10 , V_2 -> V_6 . V_7 . V_11 ,
V_2 -> V_6 . V_7 . V_12 , V_2 -> V_6 . V_7 . V_13 ) < 0 ) {
V_3 = F_3 () ;
} else {
V_3 = F_4 ( V_4 ) ;
free ( V_4 ) ;
}
return V_3 ;
}
static T_1 * F_5 ( struct V_1 * V_2 )
{
return F_6 ( L_6
L_7 V_14 L_8 ,
V_2 -> V_6 . V_15 . type == V_16 ? L_9 : L_10 ,
V_2 -> V_6 . V_17 . V_8 ,
V_2 -> V_6 . V_17 . V_18 ,
V_2 -> V_6 . V_17 . V_9 ,
V_2 -> V_6 . V_17 . V_19 ,
V_2 -> V_6 . V_17 . time ) ;
}
static T_1 * F_7 ( struct V_1 * V_2 )
{
return F_6 ( L_11 ,
V_2 -> V_6 . V_20 . V_8 ,
V_2 -> V_6 . V_20 . V_9 ,
V_2 -> V_6 . V_20 . V_20 ) ;
}
static T_1 * F_8 ( struct V_1 * V_2 )
{
struct V_21 * V_22 = (struct V_21 * ) ( & V_2 -> V_6 . V_15 + 1 ) ;
return F_6 ( L_12 V_14 L_13 V_14
L_14 V_14 L_15 ,
V_2 -> V_6 . V_15 . type == V_23 ? L_16 : L_17 ,
V_22 -> time , V_22 -> V_24 , V_22 -> V_25 ) ;
}
static T_1 * F_9 ( struct V_1 * V_2 )
{
T_1 * V_3 ;
char * V_4 ;
if ( F_2 ( & V_4 , L_18 V_5 L_2
L_19 V_5 L_15 ,
V_2 -> V_6 . V_26 . V_24 , V_2 -> V_6 . V_26 . V_26 ) < 0 ) {
V_3 = F_3 () ;
} else {
V_3 = F_4 ( V_4 ) ;
free ( V_4 ) ;
}
return V_3 ;
}
static T_1 * F_10 ( struct V_1 * V_2 )
{
return F_6 ( L_20 ,
V_2 -> V_6 . V_27 . V_8 ,
V_2 -> V_6 . V_27 . V_9 ) ;
}
static T_1 * F_11 ( struct V_1 * V_2 )
{
T_1 * V_3 ;
char * V_4 ;
if ( F_2 ( & V_4 , L_21 ) < 0 ) {
V_3 = F_3 () ;
} else {
V_3 = F_4 ( V_4 ) ;
free ( V_4 ) ;
}
return V_3 ;
}
static int F_12 ( void )
{
int V_28 ;
V_29 . V_30 =
V_31 . V_30 =
V_32 . V_30 =
V_33 . V_30 =
V_34 . V_30 =
V_35 . V_30 =
V_36 . V_30 = V_37 ;
V_28 = F_13 ( & V_29 ) ;
if ( V_28 < 0 )
goto V_38;
V_28 = F_13 ( & V_33 ) ;
if ( V_28 < 0 )
goto V_38;
V_28 = F_13 ( & V_31 ) ;
if ( V_28 < 0 )
goto V_38;
V_28 = F_13 ( & V_32 ) ;
if ( V_28 < 0 )
goto V_38;
V_28 = F_13 ( & V_36 ) ;
if ( V_28 < 0 )
goto V_38;
V_28 = F_13 ( & V_34 ) ;
if ( V_28 < 0 )
goto V_38;
V_28 = F_13 ( & V_35 ) ;
if ( V_28 < 0 )
goto V_38;
V_38:
return V_28 ;
}
static T_1 * F_14 ( union V_39 * V_6 )
{
struct V_1 * V_2 ;
T_2 * V_40 ;
if ( V_6 -> V_15 . type < V_41 ||
V_6 -> V_15 . type > V_42 )
return NULL ;
V_40 = V_43 [ V_6 -> V_15 . type ] ;
V_2 = F_15 ( struct V_1 , V_40 ) ;
if ( V_2 != NULL )
memcpy ( & V_2 -> V_6 , V_6 , V_6 -> V_15 . V_44 ) ;
return ( T_1 * ) V_2 ;
}
static int F_16 ( struct V_45 * V_46 ,
T_1 * args , T_1 * V_47 )
{
static char * V_48 [] = { L_22 , NULL } ;
char * V_49 = NULL ;
if ( ! F_17 ( args , V_47 , L_23 ,
V_48 , & V_49 ) )
return - 1 ;
V_46 -> V_50 = F_18 ( V_49 ) ;
if ( V_46 -> V_50 == NULL )
return - 1 ;
return 0 ;
}
static void F_19 ( struct V_45 * V_46 )
{
F_20 ( V_46 -> V_50 ) ;
V_46 -> V_51 -> V_52 ( ( T_1 * ) V_46 ) ;
}
static T_3 F_21 ( T_1 * V_53 )
{
struct V_45 * V_46 = ( void * ) V_53 ;
return V_46 -> V_50 -> V_54 ;
}
static T_1 * F_22 ( T_1 * V_53 , T_3 V_55 )
{
struct V_45 * V_46 = ( void * ) V_53 ;
if ( V_55 >= V_46 -> V_50 -> V_54 )
return NULL ;
return F_23 ( L_24 , V_46 -> V_50 -> V_56 [ V_55 ] ) ;
}
static int F_24 ( void )
{
V_57 . V_30 = V_37 ;
return F_13 ( & V_57 ) ;
}
static int F_25 ( struct V_58 * V_59 ,
T_1 * args , T_1 * V_47 )
{
static char * V_48 [] = { L_25 , L_26 , NULL } ;
int V_8 = - 1 , V_9 = - 1 ;
if ( ! F_17 ( args , V_47 , L_27 ,
V_48 , & V_8 , & V_9 ) )
return - 1 ;
V_59 -> V_60 = F_26 ( V_8 , V_9 ) ;
if ( V_59 -> V_60 == NULL )
return - 1 ;
return 0 ;
}
static void F_27 ( struct V_58 * V_59 )
{
F_28 ( V_59 -> V_60 ) ;
V_59 -> V_51 -> V_52 ( ( T_1 * ) V_59 ) ;
}
static T_3 F_29 ( T_1 * V_53 )
{
struct V_58 * V_59 = ( void * ) V_53 ;
return V_59 -> V_60 -> V_54 ;
}
static T_1 * F_30 ( T_1 * V_53 , T_3 V_55 )
{
struct V_58 * V_59 = ( void * ) V_53 ;
if ( V_55 >= V_59 -> V_60 -> V_54 )
return NULL ;
return F_23 ( L_24 , V_59 -> V_60 -> V_56 [ V_55 ] ) ;
}
static int F_31 ( void )
{
V_61 . V_30 = V_37 ;
return F_13 ( & V_61 ) ;
}
static int F_32 ( struct V_62 * V_63 ,
T_1 * args , T_1 * V_47 )
{
struct V_64 V_65 = {
. type = V_66 ,
. V_67 = V_68 ,
. V_69 = V_70 | V_71 ,
} ;
static char * V_48 [] = {
L_28 ,
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
NULL
} ;
T_4 V_72 = 0 ;
T_5 V_73 = 0 ,
V_74 = 0 ,
V_75 = 0 ,
V_76 = 0 ,
V_77 = 0 ,
V_78 = 0 ,
V_79 = 0 ,
V_80 = 0 ,
V_7 = 0 ,
V_20 = 0 ,
V_81 = 1 ,
V_82 = 0 ,
V_83 = 0 ,
V_84 = 0 ,
V_85 = 0 ,
V_86 = 0 ,
V_87 = 0 ,
V_88 = 1 ;
int V_89 = 0 ;
if ( ! F_17 ( args , V_47 ,
L_56 , V_48 ,
& V_65 . type , & V_65 . V_67 , & V_65 . V_90 ,
& V_72 , & V_65 . V_69 ,
& V_65 . V_91 , & V_73 , & V_74 ,
& V_75 , & V_76 , & V_77 ,
& V_78 , & V_79 , & V_80 ,
& V_7 , & V_20 , & V_81 , & V_82 ,
& V_83 , & V_84 , & V_85 ,
& V_86 , & V_87 , & V_88 ,
& V_65 . V_92 , & V_65 . V_93 ,
& V_65 . V_94 , & V_65 . V_95 , & V_89 ) )
return - 1 ;
if ( V_72 != 0 ) {
if ( V_65 . V_90 != 0 )
return - 1 ;
V_65 . V_72 = V_72 ;
}
V_65 . V_73 = V_73 ;
V_65 . V_74 = V_74 ;
V_65 . V_75 = V_75 ;
V_65 . V_76 = V_76 ;
V_65 . V_77 = V_77 ;
V_65 . V_78 = V_78 ;
V_65 . V_79 = V_79 ;
V_65 . V_80 = V_80 ;
V_65 . V_7 = V_7 ;
V_65 . V_20 = V_20 ;
V_65 . V_81 = V_81 ;
V_65 . V_82 = V_82 ;
V_65 . V_83 = V_83 ;
V_65 . V_84 = V_84 ;
V_65 . V_85 = V_85 ;
V_65 . V_86 = V_86 ;
V_65 . V_87 = V_87 ;
V_65 . V_88 = V_88 ;
F_33 ( & V_63 -> V_96 , & V_65 , V_89 ) ;
return 0 ;
}
static void F_34 ( struct V_62 * V_63 )
{
F_35 ( & V_63 -> V_96 ) ;
V_63 -> V_51 -> V_52 ( ( T_1 * ) V_63 ) ;
}
static T_1 * F_36 ( struct V_62 * V_63 ,
T_1 * args , T_1 * V_47 )
{
struct V_97 * V_96 = & V_63 -> V_96 ;
struct V_98 * V_50 = NULL ;
struct V_99 * V_60 = NULL ;
T_1 * V_46 = NULL , * V_59 = NULL ;
int V_100 = 0 , V_74 = 0 ;
static char * V_48 [] = { L_57 , L_58 , L_59 , L_35 , NULL } ;
if ( ! F_17 ( args , V_47 , L_60 , V_48 ,
& V_46 , & V_59 , & V_100 , & V_74 ) )
return NULL ;
if ( V_59 != NULL )
V_60 = ( (struct V_58 * ) V_59 ) -> V_60 ;
if ( V_46 != NULL )
V_50 = ( (struct V_45 * ) V_46 ) -> V_50 ;
V_96 -> V_65 . V_74 = V_74 ;
if ( F_37 ( V_96 , V_50 , V_60 , V_100 ) < 0 ) {
F_38 ( V_101 ) ;
return NULL ;
}
F_39 ( V_102 ) ;
return V_102 ;
}
static int F_40 ( void )
{
V_103 . V_30 = V_37 ;
return F_13 ( & V_103 ) ;
}
static int F_41 ( struct V_104 * V_105 ,
T_1 * args , T_1 * V_47 V_106 )
{
T_1 * V_46 = NULL , * V_59 = NULL ;
struct V_98 * V_50 ;
struct V_99 * V_60 ;
if ( ! F_42 ( args , L_61 , & V_46 , & V_59 ) )
return - 1 ;
V_60 = ( (struct V_58 * ) V_59 ) -> V_60 ;
V_50 = ( (struct V_45 * ) V_46 ) -> V_50 ;
F_43 ( & V_105 -> V_107 , V_50 , V_60 ) ;
return 0 ;
}
static void F_44 ( struct V_104 * V_105 )
{
F_45 ( & V_105 -> V_107 ) ;
V_105 -> V_51 -> V_52 ( ( T_1 * ) V_105 ) ;
}
static T_1 * F_46 ( struct V_104 * V_105 ,
T_1 * args , T_1 * V_47 )
{
struct V_108 * V_107 = & V_105 -> V_107 ;
static char * V_48 [] = { L_62 , L_63 , NULL } ;
int V_109 = 128 , V_110 = false ;
if ( ! F_17 ( args , V_47 , L_27 , V_48 ,
& V_109 , & V_110 ) )
return NULL ;
if ( F_47 ( V_107 , V_109 , V_110 ) < 0 ) {
F_38 ( V_101 ) ;
return NULL ;
}
F_39 ( V_102 ) ;
return V_102 ;
}
static T_1 * F_48 ( struct V_104 * V_105 ,
T_1 * args , T_1 * V_47 )
{
struct V_108 * V_107 = & V_105 -> V_107 ;
static char * V_48 [] = { L_64 , NULL } ;
int V_111 = - 1 , V_112 ;
if ( ! F_17 ( args , V_47 , L_65 , V_48 , & V_111 ) )
return NULL ;
V_112 = F_49 ( V_107 -> V_113 , V_107 -> V_114 , V_111 ) ;
if ( V_112 < 0 ) {
F_38 ( V_101 ) ;
return NULL ;
}
return F_23 ( L_24 , V_112 ) ;
}
static T_1 * F_50 ( struct V_104 * V_105 ,
T_1 * args V_106 , T_1 * V_47 V_106 )
{
struct V_108 * V_107 = & V_105 -> V_107 ;
T_1 * V_115 = F_51 ( 0 ) ;
int V_55 ;
for ( V_55 = 0 ; V_55 < V_107 -> V_114 ; ++ V_55 ) {
T_1 * V_116 ;
T_6 * V_117 = fdopen ( V_107 -> V_113 [ V_55 ] . V_118 , L_66 ) ;
if ( V_117 == NULL )
goto V_119;
V_116 = F_52 ( V_117 , L_67 , L_66 , NULL ) ;
if ( V_116 == NULL )
goto V_119;
if ( F_53 ( V_115 , V_116 ) != 0 ) {
F_54 ( V_116 ) ;
goto V_119;
}
F_54 ( V_116 ) ;
}
return V_115 ;
V_119:
return F_3 () ;
}
static T_1 * F_55 ( struct V_104 * V_105 ,
T_1 * args , T_1 * V_47 V_106 )
{
struct V_108 * V_107 = & V_105 -> V_107 ;
T_1 * V_63 ;
struct V_97 * V_96 ;
if ( ! F_42 ( args , L_68 , & V_63 ) )
return NULL ;
F_39 ( V_63 ) ;
V_96 = & ( (struct V_62 * ) V_63 ) -> V_96 ;
V_96 -> V_89 = V_107 -> V_120 ;
F_56 ( V_107 , V_96 ) ;
return F_23 ( L_24 , V_107 -> V_120 ) ;
}
static T_1 * F_57 ( struct V_104 * V_105 ,
T_1 * args , T_1 * V_47 )
{
struct V_108 * V_107 = & V_105 -> V_107 ;
union V_39 * V_6 ;
int V_88 = 1 , V_121 ;
static char * V_48 [] = { L_69 , L_51 , NULL } ;
int V_28 ;
if ( ! F_17 ( args , V_47 , L_70 , V_48 ,
& V_121 , & V_88 ) )
return NULL ;
V_6 = F_58 ( V_107 , V_121 ) ;
if ( V_6 != NULL ) {
struct V_97 * V_122 ;
T_1 * V_123 = F_14 ( V_6 ) ;
struct V_1 * V_2 = (struct V_1 * ) V_123 ;
if ( V_123 == NULL )
return F_3 () ;
V_122 = F_59 ( V_107 -> V_124 . V_125 , struct V_97 , V_126 ) ;
V_28 = F_60 ( V_6 , V_122 -> V_65 . V_69 ,
F_61 ( V_122 ) ,
V_88 , & V_2 -> V_127 , false ) ;
if ( V_28 )
return F_62 ( V_101 ,
L_71 , V_28 ) ;
return V_123 ;
}
F_39 ( V_102 ) ;
return V_102 ;
}
static T_3 F_63 ( T_1 * V_53 )
{
struct V_104 * V_105 = ( void * ) V_53 ;
return V_105 -> V_107 . V_120 ;
}
static T_1 * F_64 ( T_1 * V_53 , T_3 V_55 )
{
struct V_104 * V_105 = ( void * ) V_53 ;
struct V_97 * V_128 ;
if ( V_55 >= V_105 -> V_107 . V_120 )
return NULL ;
F_65 (pos, &pevlist->evlist.entries, node)
if ( V_55 -- == 0 )
break;
return F_23 ( L_68 , F_66 ( V_128 , struct V_62 , V_96 ) ) ;
}
static int F_67 ( void )
{
V_129 . V_30 = V_37 ;
return F_13 ( & V_129 ) ;
}
T_7 F_68 ( void )
{
T_1 * V_53 ;
int V_55 ;
T_1 * V_130 , * V_131 = F_69 ( L_67 , V_132 ) ;
if ( V_131 == NULL ||
F_12 () < 0 ||
F_67 () < 0 ||
F_40 () < 0 ||
F_31 () < 0 ||
F_24 () < 0 )
return;
F_39 ( & V_129 ) ;
F_70 ( V_131 , L_72 , ( T_1 * ) & V_129 ) ;
F_39 ( & V_103 ) ;
F_70 ( V_131 , L_73 , ( T_1 * ) & V_103 ) ;
F_39 ( & V_61 ) ;
F_70 ( V_131 , L_74 , ( T_1 * ) & V_61 ) ;
F_39 ( & V_57 ) ;
F_70 ( V_131 , L_75 , ( T_1 * ) & V_57 ) ;
V_130 = F_71 ( V_131 ) ;
if ( V_130 == NULL )
goto error;
for ( V_55 = 0 ; V_133 [ V_55 ] . V_134 != NULL ; V_55 ++ ) {
V_53 = F_72 ( V_133 [ V_55 ] . V_135 ) ;
if ( V_53 == NULL )
goto error;
F_73 ( V_130 , V_133 [ V_55 ] . V_134 , V_53 ) ;
F_54 ( V_53 ) ;
}
error:
if ( F_74 () )
F_75 ( V_136 , L_76 ) ;
}
