int F_1 ( int V_1 , int V_2 , const char * V_3 , ... )
{
T_1 args ;
int V_4 = 0 ;
if ( V_2 >= V_1 ) {
va_start ( args , V_3 ) ;
V_4 = vfprintf ( V_5 , V_3 , args ) ;
va_end ( args ) ;
}
return V_4 ;
}
static T_2 * F_2 ( struct V_6 * V_7 )
{
T_2 * V_4 ;
char * V_8 ;
if ( F_3 ( & V_8 , L_1 V_9 L_2
L_3 V_9 L_4 V_9 L_2
L_5 ,
V_7 -> V_10 . V_11 . V_12 , V_7 -> V_10 . V_11 . V_13 ,
V_7 -> V_10 . V_11 . V_14 , V_7 -> V_10 . V_11 . V_15 ,
V_7 -> V_10 . V_11 . V_16 , V_7 -> V_10 . V_11 . V_17 ) < 0 ) {
V_4 = F_4 () ;
} else {
V_4 = F_5 ( V_8 ) ;
free ( V_8 ) ;
}
return V_4 ;
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
T_2 * V_4 ;
char * V_8 ;
if ( F_3 ( & V_8 , L_18 V_9 L_2
L_19 V_9 L_15 ,
V_7 -> V_10 . V_30 . V_28 , V_7 -> V_10 . V_30 . V_30 ) < 0 ) {
V_4 = F_4 () ;
} else {
V_4 = F_5 ( V_8 ) ;
free ( V_8 ) ;
}
return V_4 ;
}
static T_2 * F_11 ( struct V_6 * V_7 )
{
return F_7 ( L_20 ,
V_7 -> V_10 . V_31 . V_12 ,
V_7 -> V_10 . V_31 . V_13 ) ;
}
static T_2 * F_12 ( struct V_6 * V_7 )
{
T_2 * V_4 ;
char * V_8 ;
if ( F_3 ( & V_8 , L_21 ) < 0 ) {
V_4 = F_4 () ;
} else {
V_4 = F_5 ( V_8 ) ;
free ( V_8 ) ;
}
return V_4 ;
}
static T_2 * F_13 ( struct V_6 * V_7 )
{
T_2 * V_4 ;
char * V_8 ;
if ( F_3 ( & V_8 , L_22 ,
V_7 -> V_10 . V_32 . V_33 ,
V_7 -> V_10 . V_32 . V_34 ,
! ! ( V_7 -> V_10 . V_19 . V_35 & V_36 ) ) < 0 ) {
V_4 = F_4 () ;
} else {
V_4 = F_5 ( V_8 ) ;
free ( V_8 ) ;
}
return V_4 ;
}
static int F_14 ( void )
{
int V_37 ;
V_38 . V_39 =
V_40 . V_39 =
V_41 . V_39 =
V_42 . V_39 =
V_43 . V_39 =
V_44 . V_39 =
V_45 . V_39 =
V_46 . V_39 = V_47 ;
V_37 = F_15 ( & V_38 ) ;
if ( V_37 < 0 )
goto V_48;
V_37 = F_15 ( & V_42 ) ;
if ( V_37 < 0 )
goto V_48;
V_37 = F_15 ( & V_40 ) ;
if ( V_37 < 0 )
goto V_48;
V_37 = F_15 ( & V_41 ) ;
if ( V_37 < 0 )
goto V_48;
V_37 = F_15 ( & V_46 ) ;
if ( V_37 < 0 )
goto V_48;
V_37 = F_15 ( & V_43 ) ;
if ( V_37 < 0 )
goto V_48;
V_37 = F_15 ( & V_44 ) ;
if ( V_37 < 0 )
goto V_48;
V_37 = F_15 ( & V_45 ) ;
if ( V_37 < 0 )
goto V_48;
V_48:
return V_37 ;
}
static T_2 * F_16 ( union V_49 * V_10 )
{
struct V_6 * V_7 ;
T_3 * V_50 ;
if ( ( V_10 -> V_19 . type < V_51 ||
V_10 -> V_19 . type > V_52 ) &&
! ( V_10 -> V_19 . type == V_53 ||
V_10 -> V_19 . type == V_54 ) )
return NULL ;
V_50 = V_55 [ V_10 -> V_19 . type ] ;
V_7 = F_17 ( struct V_6 , V_50 ) ;
if ( V_7 != NULL )
memcpy ( & V_7 -> V_10 , V_10 , V_10 -> V_19 . V_56 ) ;
return ( T_2 * ) V_7 ;
}
static int F_18 ( struct V_57 * V_58 ,
T_2 * args , T_2 * V_59 )
{
static char * V_60 [] = { L_23 , NULL } ;
char * V_61 = NULL ;
if ( ! F_19 ( args , V_59 , L_24 ,
V_60 , & V_61 ) )
return - 1 ;
V_58 -> V_62 = F_20 ( V_61 ) ;
if ( V_58 -> V_62 == NULL )
return - 1 ;
return 0 ;
}
static void F_21 ( struct V_57 * V_58 )
{
F_22 ( V_58 -> V_62 ) ;
V_58 -> V_63 -> V_64 ( ( T_2 * ) V_58 ) ;
}
static T_4 F_23 ( T_2 * V_65 )
{
struct V_57 * V_58 = ( void * ) V_65 ;
return V_58 -> V_62 -> V_66 ;
}
static T_2 * F_24 ( T_2 * V_65 , T_4 V_67 )
{
struct V_57 * V_58 = ( void * ) V_65 ;
if ( V_67 >= V_58 -> V_62 -> V_66 )
return NULL ;
return F_25 ( L_25 , V_58 -> V_62 -> V_68 [ V_67 ] ) ;
}
static int F_26 ( void )
{
V_69 . V_39 = V_47 ;
return F_15 ( & V_69 ) ;
}
static int F_27 ( struct V_70 * V_71 ,
T_2 * args , T_2 * V_59 )
{
static char * V_60 [] = { L_26 , L_27 , L_28 , NULL } ;
int V_12 = - 1 , V_13 = - 1 , V_72 = V_73 ;
if ( ! F_19 ( args , V_59 , L_29 ,
V_60 , & V_12 , & V_13 , & V_72 ) )
return - 1 ;
V_71 -> V_74 = F_28 ( V_12 , V_13 , V_72 ) ;
if ( V_71 -> V_74 == NULL )
return - 1 ;
return 0 ;
}
static void F_29 ( struct V_70 * V_71 )
{
F_30 ( V_71 -> V_74 ) ;
V_71 -> V_63 -> V_64 ( ( T_2 * ) V_71 ) ;
}
static T_4 F_31 ( T_2 * V_65 )
{
struct V_70 * V_71 = ( void * ) V_65 ;
return V_71 -> V_74 -> V_66 ;
}
static T_2 * F_32 ( T_2 * V_65 , T_4 V_67 )
{
struct V_70 * V_71 = ( void * ) V_65 ;
if ( V_67 >= V_71 -> V_74 -> V_66 )
return NULL ;
return F_25 ( L_25 , V_71 -> V_74 -> V_68 [ V_67 ] ) ;
}
static int F_33 ( void )
{
V_75 . V_39 = V_47 ;
return F_15 ( & V_75 ) ;
}
static int F_34 ( struct V_76 * V_77 ,
T_2 * args , T_2 * V_59 )
{
struct V_78 V_79 = {
. type = V_80 ,
. V_81 = V_82 ,
. V_83 = V_84 | V_85 ,
} ;
static char * V_60 [] = {
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
L_57 ,
L_58 ,
NULL
} ;
T_5 V_86 = 0 ;
T_6 V_87 = 0 ,
V_88 = 0 ,
V_89 = 0 ,
V_90 = 0 ,
V_91 = 0 ,
V_92 = 0 ,
V_93 = 0 ,
V_94 = 0 ,
V_11 = 0 ,
V_32 = 0 ,
V_24 = 0 ,
V_95 = 1 ,
V_96 = 0 ,
V_97 = 0 ,
V_98 = 0 ,
V_99 = 0 ,
V_100 = 0 ,
V_101 = 0 ,
V_102 = 1 ;
int V_103 = 0 ;
if ( ! F_19 ( args , V_59 ,
L_59 , V_60 ,
& V_79 . type , & V_79 . V_81 , & V_79 . V_104 ,
& V_86 , & V_79 . V_83 ,
& V_79 . V_105 , & V_87 , & V_88 ,
& V_89 , & V_90 , & V_91 ,
& V_92 , & V_93 , & V_94 ,
& V_11 , & V_32 , & V_24 , & V_95 , & V_96 ,
& V_97 , & V_98 , & V_99 ,
& V_100 , & V_101 , & V_102 ,
& V_79 . V_106 , & V_79 . V_107 ,
& V_79 . V_108 , & V_79 . V_109 , & V_103 ) )
return - 1 ;
if ( V_86 != 0 ) {
if ( V_79 . V_104 != 0 )
return - 1 ;
V_79 . V_86 = V_86 ;
}
V_79 . V_87 = V_87 ;
V_79 . V_88 = V_88 ;
V_79 . V_89 = V_89 ;
V_79 . V_90 = V_90 ;
V_79 . V_91 = V_91 ;
V_79 . V_92 = V_92 ;
V_79 . V_93 = V_93 ;
V_79 . V_94 = V_94 ;
V_79 . V_11 = V_11 ;
V_79 . V_32 = V_32 ;
V_79 . V_24 = V_24 ;
V_79 . V_95 = V_95 ;
V_79 . V_96 = V_96 ;
V_79 . V_97 = V_97 ;
V_79 . V_98 = V_98 ;
V_79 . V_99 = V_99 ;
V_79 . V_100 = V_100 ;
V_79 . V_101 = V_101 ;
V_79 . V_102 = V_102 ;
F_35 ( & V_77 -> V_110 , & V_79 , V_103 ) ;
return 0 ;
}
static void F_36 ( struct V_76 * V_77 )
{
F_37 ( & V_77 -> V_110 ) ;
V_77 -> V_63 -> V_64 ( ( T_2 * ) V_77 ) ;
}
static T_2 * F_38 ( struct V_76 * V_77 ,
T_2 * args , T_2 * V_59 )
{
struct V_111 * V_110 = & V_77 -> V_110 ;
struct V_112 * V_62 = NULL ;
struct V_113 * V_74 = NULL ;
T_2 * V_58 = NULL , * V_71 = NULL ;
int V_114 = 0 , V_88 = 0 ;
static char * V_60 [] = { L_60 , L_61 , L_62 , L_37 , NULL } ;
if ( ! F_19 ( args , V_59 , L_63 , V_60 ,
& V_58 , & V_71 , & V_114 , & V_88 ) )
return NULL ;
if ( V_71 != NULL )
V_74 = ( (struct V_70 * ) V_71 ) -> V_74 ;
if ( V_58 != NULL )
V_62 = ( (struct V_57 * ) V_58 ) -> V_62 ;
V_110 -> V_79 . V_88 = V_88 ;
if ( F_39 ( V_110 , V_62 , V_74 ) < 0 ) {
F_40 ( V_115 ) ;
return NULL ;
}
F_41 ( V_116 ) ;
return V_116 ;
}
static int F_42 ( void )
{
V_117 . V_39 = V_47 ;
return F_15 ( & V_117 ) ;
}
static int F_43 ( struct V_118 * V_119 ,
T_2 * args , T_2 * V_59 V_120 )
{
T_2 * V_58 = NULL , * V_71 = NULL ;
struct V_112 * V_62 ;
struct V_113 * V_74 ;
if ( ! F_44 ( args , L_64 , & V_58 , & V_71 ) )
return - 1 ;
V_74 = ( (struct V_70 * ) V_71 ) -> V_74 ;
V_62 = ( (struct V_57 * ) V_58 ) -> V_62 ;
F_45 ( & V_119 -> V_121 , V_62 , V_74 ) ;
return 0 ;
}
static void F_46 ( struct V_118 * V_119 )
{
F_47 ( & V_119 -> V_121 ) ;
V_119 -> V_63 -> V_64 ( ( T_2 * ) V_119 ) ;
}
static T_2 * F_48 ( struct V_118 * V_119 ,
T_2 * args , T_2 * V_59 )
{
struct V_122 * V_121 = & V_119 -> V_121 ;
static char * V_60 [] = { L_65 , L_66 , NULL } ;
int V_123 = 128 , V_124 = false ;
if ( ! F_19 ( args , V_59 , L_67 , V_60 ,
& V_123 , & V_124 ) )
return NULL ;
if ( F_49 ( V_121 , V_123 , V_124 ) < 0 ) {
F_40 ( V_115 ) ;
return NULL ;
}
F_41 ( V_116 ) ;
return V_116 ;
}
static T_2 * F_50 ( struct V_118 * V_119 ,
T_2 * args , T_2 * V_59 )
{
struct V_122 * V_121 = & V_119 -> V_121 ;
static char * V_60 [] = { L_68 , NULL } ;
int V_125 = - 1 , V_126 ;
if ( ! F_19 ( args , V_59 , L_69 , V_60 , & V_125 ) )
return NULL ;
V_126 = F_51 ( V_121 , V_125 ) ;
if ( V_126 < 0 ) {
F_40 ( V_115 ) ;
return NULL ;
}
return F_25 ( L_25 , V_126 ) ;
}
static T_2 * F_52 ( struct V_118 * V_119 ,
T_2 * args V_120 ,
T_2 * V_59 V_120 )
{
struct V_122 * V_121 = & V_119 -> V_121 ;
T_2 * V_127 = F_53 ( 0 ) ;
int V_67 ;
for ( V_67 = 0 ; V_67 < V_121 -> V_128 . V_66 ; ++ V_67 ) {
T_2 * V_129 ;
T_7 * V_130 = fdopen ( V_121 -> V_128 . V_131 [ V_67 ] . V_132 , L_70 ) ;
if ( V_130 == NULL )
goto V_133;
V_129 = F_54 ( V_130 , L_71 , L_70 , NULL ) ;
if ( V_129 == NULL )
goto V_133;
if ( F_55 ( V_127 , V_129 ) != 0 ) {
F_56 ( V_129 ) ;
goto V_133;
}
F_56 ( V_129 ) ;
}
return V_127 ;
V_133:
return F_4 () ;
}
static T_2 * F_57 ( struct V_118 * V_119 ,
T_2 * args ,
T_2 * V_59 V_120 )
{
struct V_122 * V_121 = & V_119 -> V_121 ;
T_2 * V_77 ;
struct V_111 * V_110 ;
if ( ! F_44 ( args , L_72 , & V_77 ) )
return NULL ;
F_41 ( V_77 ) ;
V_110 = & ( (struct V_76 * ) V_77 ) -> V_110 ;
V_110 -> V_103 = V_121 -> V_134 ;
F_58 ( V_121 , V_110 ) ;
return F_25 ( L_25 , V_121 -> V_134 ) ;
}
static T_2 * F_59 ( struct V_118 * V_119 ,
T_2 * args , T_2 * V_59 )
{
struct V_122 * V_121 = & V_119 -> V_121 ;
union V_49 * V_10 ;
int V_102 = 1 , V_135 ;
static char * V_60 [] = { L_73 , L_54 , NULL } ;
int V_37 ;
if ( ! F_19 ( args , V_59 , L_74 , V_60 ,
& V_135 , & V_102 ) )
return NULL ;
V_10 = F_60 ( V_121 , V_135 ) ;
if ( V_10 != NULL ) {
T_2 * V_136 = F_16 ( V_10 ) ;
struct V_6 * V_7 = (struct V_6 * ) V_136 ;
F_61 ( V_121 , V_135 ) ;
if ( V_136 == NULL )
return F_4 () ;
V_37 = F_62 ( V_121 , V_10 , & V_7 -> V_137 ) ;
if ( V_37 )
return F_63 ( V_115 ,
L_75 , V_37 ) ;
return V_136 ;
}
F_41 ( V_116 ) ;
return V_116 ;
}
static T_2 * F_64 ( struct V_118 * V_119 ,
T_2 * args , T_2 * V_59 )
{
struct V_122 * V_121 = & V_119 -> V_121 ;
int V_114 = 0 ;
static char * V_60 [] = { L_62 , NULL } ;
if ( ! F_19 ( args , V_59 , L_63 , V_60 , & V_114 ) )
return NULL ;
if ( V_114 )
F_65 ( V_121 ) ;
if ( F_66 ( V_121 ) < 0 ) {
F_40 ( V_115 ) ;
return NULL ;
}
F_41 ( V_116 ) ;
return V_116 ;
}
static T_4 F_67 ( T_2 * V_65 )
{
struct V_118 * V_119 = ( void * ) V_65 ;
return V_119 -> V_121 . V_134 ;
}
static T_2 * F_68 ( T_2 * V_65 , T_4 V_67 )
{
struct V_118 * V_119 = ( void * ) V_65 ;
struct V_111 * V_138 ;
if ( V_67 >= V_119 -> V_121 . V_134 )
return NULL ;
F_69 (&pevlist->evlist, pos) {
if ( V_67 -- == 0 )
break;
}
return F_25 ( L_72 , F_70 ( V_138 , struct V_76 , V_110 ) ) ;
}
static int F_71 ( void )
{
V_139 . V_39 = V_47 ;
return F_15 ( & V_139 ) ;
}
T_8 F_72 ( void )
{
T_2 * V_65 ;
int V_67 ;
T_2 * V_140 , * V_141 = F_73 ( L_71 , V_142 ) ;
if ( V_141 == NULL ||
F_14 () < 0 ||
F_71 () < 0 ||
F_42 () < 0 ||
F_33 () < 0 ||
F_26 () < 0 )
return;
V_143 = F_74 ( V_144 ) ;
F_41 ( & V_139 ) ;
F_75 ( V_141 , L_76 , ( T_2 * ) & V_139 ) ;
F_41 ( & V_117 ) ;
F_75 ( V_141 , L_77 , ( T_2 * ) & V_117 ) ;
F_41 ( & V_75 ) ;
F_75 ( V_141 , L_78 , ( T_2 * ) & V_75 ) ;
F_41 ( & V_69 ) ;
F_75 ( V_141 , L_79 , ( T_2 * ) & V_69 ) ;
V_140 = F_76 ( V_141 ) ;
if ( V_140 == NULL )
goto error;
for ( V_67 = 0 ; V_145 [ V_67 ] . V_146 != NULL ; V_67 ++ ) {
V_65 = F_77 ( V_145 [ V_67 ] . V_147 ) ;
if ( V_65 == NULL )
goto error;
F_78 ( V_140 , V_145 [ V_67 ] . V_146 , V_65 ) ;
F_56 ( V_65 ) ;
}
error:
if ( F_79 () )
F_80 ( V_148 , L_80 ) ;
}
void F_81 ( struct V_78 * V_79 , T_9 V_12 , int V_135 ,
int V_132 , int V_149 , unsigned long V_150 )
{
}
