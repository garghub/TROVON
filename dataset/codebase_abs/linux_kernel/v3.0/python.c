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
static int F_9 ( void )
{
int V_26 ;
V_27 . V_28 =
V_29 . V_28 =
V_30 . V_28 =
V_31 . V_28 = V_32 ;
V_26 = F_10 ( & V_27 ) ;
if ( V_26 < 0 )
goto V_33;
V_26 = F_10 ( & V_29 ) ;
if ( V_26 < 0 )
goto V_33;
V_26 = F_10 ( & V_30 ) ;
if ( V_26 < 0 )
goto V_33;
V_26 = F_10 ( & V_31 ) ;
if ( V_26 < 0 )
goto V_33;
V_33:
return V_26 ;
}
static T_1 * F_11 ( union V_34 * V_6 )
{
struct V_1 * V_2 ;
T_2 * V_35 ;
if ( V_6 -> V_15 . type < V_36 ||
V_6 -> V_15 . type > V_37 )
return NULL ;
V_35 = V_38 [ V_6 -> V_15 . type ] ;
V_2 = F_12 ( struct V_1 , V_35 ) ;
if ( V_2 != NULL )
memcpy ( & V_2 -> V_6 , V_6 , V_6 -> V_15 . V_39 ) ;
return ( T_1 * ) V_2 ;
}
static int F_13 ( struct V_40 * V_41 ,
T_1 * args , T_1 * V_42 )
{
static char * V_43 [] = { L_18 , NULL , NULL , } ;
char * V_44 = NULL ;
if ( ! F_14 ( args , V_42 , L_19 ,
V_43 , & V_44 ) )
return - 1 ;
V_41 -> V_45 = F_15 ( V_44 ) ;
if ( V_41 -> V_45 == NULL )
return - 1 ;
return 0 ;
}
static void F_16 ( struct V_40 * V_41 )
{
F_17 ( V_41 -> V_45 ) ;
V_41 -> V_46 -> V_47 ( ( T_1 * ) V_41 ) ;
}
static T_3 F_18 ( T_1 * V_48 )
{
struct V_40 * V_41 = ( void * ) V_48 ;
return V_41 -> V_45 -> V_49 ;
}
static T_1 * F_19 ( T_1 * V_48 , T_3 V_50 )
{
struct V_40 * V_41 = ( void * ) V_48 ;
if ( V_50 >= V_41 -> V_45 -> V_49 )
return NULL ;
return F_20 ( L_20 , V_41 -> V_45 -> V_51 [ V_50 ] ) ;
}
static int F_21 ( void )
{
V_52 . V_28 = V_32 ;
return F_10 ( & V_52 ) ;
}
static int F_22 ( struct V_53 * V_54 ,
T_1 * args , T_1 * V_42 )
{
static char * V_43 [] = { L_21 , L_22 , NULL , NULL , } ;
int V_8 = - 1 , V_9 = - 1 ;
if ( ! F_14 ( args , V_42 , L_23 ,
V_43 , & V_8 , & V_9 ) )
return - 1 ;
V_54 -> V_55 = F_23 ( V_8 , V_9 ) ;
if ( V_54 -> V_55 == NULL )
return - 1 ;
return 0 ;
}
static void F_24 ( struct V_53 * V_54 )
{
F_25 ( V_54 -> V_55 ) ;
V_54 -> V_46 -> V_47 ( ( T_1 * ) V_54 ) ;
}
static T_3 F_26 ( T_1 * V_48 )
{
struct V_53 * V_54 = ( void * ) V_48 ;
return V_54 -> V_55 -> V_49 ;
}
static T_1 * F_27 ( T_1 * V_48 , T_3 V_50 )
{
struct V_53 * V_54 = ( void * ) V_48 ;
if ( V_50 >= V_54 -> V_55 -> V_49 )
return NULL ;
return F_20 ( L_20 , V_54 -> V_55 -> V_51 [ V_50 ] ) ;
}
static int F_28 ( void )
{
V_56 . V_28 = V_32 ;
return F_10 ( & V_56 ) ;
}
static int F_29 ( struct V_57 * V_58 ,
T_1 * args , T_1 * V_42 )
{
struct V_59 V_60 = {
. type = V_61 ,
. V_62 = V_63 ,
. V_64 = V_65 | V_66 ,
} ;
static char * V_43 [] = {
L_24 ,
L_25 ,
L_26 ,
L_27 ,
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
L_51 , NULL , NULL , } ;
T_4 V_67 = 0 ;
T_5 V_68 = 0 ,
V_69 = 0 ,
V_70 = 0 ,
V_71 = 0 ,
V_72 = 0 ,
V_73 = 0 ,
V_74 = 0 ,
V_75 = 0 ,
V_7 = 0 ,
V_20 = 0 ,
V_76 = 1 ,
V_77 = 0 ,
V_78 = 0 ,
V_79 = 0 ,
V_80 = 0 ,
V_81 = 0 ,
V_82 = 0 ,
V_83 = 1 ;
int V_84 = 0 ;
if ( ! F_14 ( args , V_42 ,
L_52 , V_43 ,
& V_60 . type , & V_60 . V_62 , & V_60 . V_85 ,
& V_67 , & V_60 . V_64 ,
& V_60 . V_86 , & V_68 , & V_69 ,
& V_70 , & V_71 , & V_72 ,
& V_73 , & V_74 , & V_75 ,
& V_7 , & V_20 , & V_76 , & V_77 ,
& V_78 , & V_79 , & V_80 ,
& V_81 , & V_82 , & V_83 ,
& V_60 . V_87 , & V_60 . V_88 ,
& V_60 . V_89 , & V_60 . V_90 , & V_84 ) )
return - 1 ;
if ( V_67 != 0 ) {
if ( V_60 . V_85 != 0 )
return - 1 ;
V_60 . V_67 = V_67 ;
}
V_60 . V_68 = V_68 ;
V_60 . V_69 = V_69 ;
V_60 . V_70 = V_70 ;
V_60 . V_71 = V_71 ;
V_60 . V_72 = V_72 ;
V_60 . V_73 = V_73 ;
V_60 . V_74 = V_74 ;
V_60 . V_75 = V_75 ;
V_60 . V_7 = V_7 ;
V_60 . V_20 = V_20 ;
V_60 . V_76 = V_76 ;
V_60 . V_77 = V_77 ;
V_60 . V_78 = V_78 ;
V_60 . V_79 = V_79 ;
V_60 . V_80 = V_80 ;
V_60 . V_81 = V_81 ;
V_60 . V_82 = V_82 ;
V_60 . V_83 = V_83 ;
F_30 ( & V_58 -> V_91 , & V_60 , V_84 ) ;
return 0 ;
}
static void F_31 ( struct V_57 * V_58 )
{
F_32 ( & V_58 -> V_91 ) ;
V_58 -> V_46 -> V_47 ( ( T_1 * ) V_58 ) ;
}
static T_1 * F_33 ( struct V_57 * V_58 ,
T_1 * args , T_1 * V_42 )
{
struct V_92 * V_91 = & V_58 -> V_91 ;
struct V_93 * V_45 = NULL ;
struct V_94 * V_55 = NULL ;
T_1 * V_41 = NULL , * V_54 = NULL ;
int V_95 = 0 , V_69 = 0 ;
static char * V_43 [] = { L_53 , L_54 , L_55 , L_31 , NULL , NULL } ;
if ( ! F_14 ( args , V_42 , L_56 , V_43 ,
& V_41 , & V_54 , & V_95 , & V_69 ) )
return NULL ;
if ( V_54 != NULL )
V_55 = ( (struct V_53 * ) V_54 ) -> V_55 ;
if ( V_41 != NULL )
V_45 = ( (struct V_40 * ) V_41 ) -> V_45 ;
V_91 -> V_60 . V_69 = V_69 ;
if ( F_34 ( V_91 , V_45 , V_55 , V_95 ) < 0 ) {
F_35 ( V_96 ) ;
return NULL ;
}
F_36 ( V_97 ) ;
return V_97 ;
}
static int F_37 ( void )
{
V_98 . V_28 = V_32 ;
return F_10 ( & V_98 ) ;
}
static int F_38 ( struct V_99 * V_100 ,
T_1 * args , T_1 * V_42 V_101 )
{
T_1 * V_41 = NULL , * V_54 = NULL ;
struct V_93 * V_45 ;
struct V_94 * V_55 ;
if ( ! F_39 ( args , L_57 , & V_41 , & V_54 ) )
return - 1 ;
V_55 = ( (struct V_53 * ) V_54 ) -> V_55 ;
V_45 = ( (struct V_40 * ) V_41 ) -> V_45 ;
F_40 ( & V_100 -> V_102 , V_45 , V_55 ) ;
return 0 ;
}
static void F_41 ( struct V_99 * V_100 )
{
F_42 ( & V_100 -> V_102 ) ;
V_100 -> V_46 -> V_47 ( ( T_1 * ) V_100 ) ;
}
static T_1 * F_43 ( struct V_99 * V_100 ,
T_1 * args , T_1 * V_42 )
{
struct V_103 * V_102 = & V_100 -> V_102 ;
static char * V_43 [] = { L_58 , L_59 ,
NULL , NULL } ;
int V_104 = 128 , V_105 = false ;
if ( ! F_14 ( args , V_42 , L_23 , V_43 ,
& V_104 , & V_105 ) )
return NULL ;
if ( F_44 ( V_102 , V_104 , V_105 ) < 0 ) {
F_35 ( V_96 ) ;
return NULL ;
}
F_36 ( V_97 ) ;
return V_97 ;
}
static T_1 * F_45 ( struct V_99 * V_100 ,
T_1 * args , T_1 * V_42 )
{
struct V_103 * V_102 = & V_100 -> V_102 ;
static char * V_43 [] = { L_60 , NULL , NULL } ;
int V_106 = - 1 , V_107 ;
if ( ! F_14 ( args , V_42 , L_61 , V_43 , & V_106 ) )
return NULL ;
V_107 = F_46 ( V_102 -> V_108 , V_102 -> V_109 , V_106 ) ;
if ( V_107 < 0 ) {
F_35 ( V_96 ) ;
return NULL ;
}
return F_20 ( L_20 , V_107 ) ;
}
static T_1 * F_47 ( struct V_99 * V_100 ,
T_1 * args V_101 , T_1 * V_42 V_101 )
{
struct V_103 * V_102 = & V_100 -> V_102 ;
T_1 * V_110 = F_48 ( 0 ) ;
int V_50 ;
for ( V_50 = 0 ; V_50 < V_102 -> V_109 ; ++ V_50 ) {
T_1 * V_111 ;
T_6 * V_112 = fdopen ( V_102 -> V_108 [ V_50 ] . V_113 , L_62 ) ;
if ( V_112 == NULL )
goto V_114;
V_111 = F_49 ( V_112 , L_63 , L_62 , NULL ) ;
if ( V_111 == NULL )
goto V_114;
if ( F_50 ( V_110 , V_111 ) != 0 ) {
F_51 ( V_111 ) ;
goto V_114;
}
F_51 ( V_111 ) ;
}
return V_110 ;
V_114:
return F_3 () ;
}
static T_1 * F_52 ( struct V_99 * V_100 ,
T_1 * args , T_1 * V_42 V_101 )
{
struct V_103 * V_102 = & V_100 -> V_102 ;
T_1 * V_58 ;
struct V_92 * V_91 ;
if ( ! F_39 ( args , L_64 , & V_58 ) )
return NULL ;
F_36 ( V_58 ) ;
V_91 = & ( (struct V_57 * ) V_58 ) -> V_91 ;
V_91 -> V_84 = V_102 -> V_115 ;
F_53 ( V_102 , V_91 ) ;
return F_20 ( L_20 , V_102 -> V_115 ) ;
}
static T_1 * F_54 ( struct V_99 * V_100 ,
T_1 * args , T_1 * V_42 )
{
struct V_103 * V_102 = & V_100 -> V_102 ;
union V_34 * V_6 ;
int V_83 = 1 , V_116 ;
static char * V_43 [] = { L_65 , L_47 , NULL , NULL } ;
int V_26 ;
if ( ! F_14 ( args , V_42 , L_66 , V_43 ,
& V_116 , & V_83 ) )
return NULL ;
V_6 = F_55 ( V_102 , V_116 ) ;
if ( V_6 != NULL ) {
struct V_92 * V_117 ;
T_1 * V_118 = F_11 ( V_6 ) ;
struct V_1 * V_2 = (struct V_1 * ) V_118 ;
if ( V_118 == NULL )
return F_3 () ;
V_117 = F_56 ( V_102 -> V_119 . V_120 , struct V_92 , V_121 ) ;
V_26 = F_57 ( V_6 , V_117 -> V_60 . V_64 ,
F_58 ( V_117 ) ,
V_83 , & V_2 -> V_122 ) ;
if ( V_26 )
return F_59 ( V_96 ,
L_67 , V_26 ) ;
return V_118 ;
}
F_36 ( V_97 ) ;
return V_97 ;
}
static T_3 F_60 ( T_1 * V_48 )
{
struct V_99 * V_100 = ( void * ) V_48 ;
return V_100 -> V_102 . V_115 ;
}
static T_1 * F_61 ( T_1 * V_48 , T_3 V_50 )
{
struct V_99 * V_100 = ( void * ) V_48 ;
struct V_92 * V_123 ;
if ( V_50 >= V_100 -> V_102 . V_115 )
return NULL ;
F_62 (pos, &pevlist->evlist.entries, node)
if ( V_50 -- == 0 )
break;
return F_20 ( L_64 , F_63 ( V_123 , struct V_57 , V_91 ) ) ;
}
static int F_64 ( void )
{
V_124 . V_28 = V_32 ;
return F_10 ( & V_124 ) ;
}
T_7 F_65 ( void )
{
T_1 * V_48 ;
int V_50 ;
T_1 * V_125 , * V_126 = F_66 ( L_63 , V_127 ) ;
if ( V_126 == NULL ||
F_9 () < 0 ||
F_64 () < 0 ||
F_37 () < 0 ||
F_28 () < 0 ||
F_21 () < 0 )
return;
F_36 ( & V_124 ) ;
F_67 ( V_126 , L_68 , ( T_1 * ) & V_124 ) ;
F_36 ( & V_98 ) ;
F_67 ( V_126 , L_69 , ( T_1 * ) & V_98 ) ;
F_36 ( & V_56 ) ;
F_67 ( V_126 , L_70 , ( T_1 * ) & V_56 ) ;
F_36 ( & V_52 ) ;
F_67 ( V_126 , L_71 , ( T_1 * ) & V_52 ) ;
V_125 = F_68 ( V_126 ) ;
if ( V_125 == NULL )
goto error;
for ( V_50 = 0 ; V_128 [ V_50 ] . V_129 != NULL ; V_50 ++ ) {
V_48 = F_69 ( V_128 [ V_50 ] . V_130 ) ;
if ( V_48 == NULL )
goto error;
F_70 ( V_125 , V_128 [ V_50 ] . V_129 , V_48 ) ;
F_51 ( V_48 ) ;
}
error:
if ( F_71 () )
F_72 ( V_131 , L_72 ) ;
}
