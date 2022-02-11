static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
struct V_7 * V_8 )
{
struct V_9 * V_10 = NULL ;
int V_11 = 0 ;
struct V_12 * V_13 ;
if ( ( V_14 || V_15 . V_16 ) && V_6 -> V_17 ) {
V_11 = F_2 ( V_2 , V_4 -> V_18 ,
V_6 -> V_17 , & V_10 ) ;
if ( V_11 )
return V_11 ;
}
V_13 = F_3 ( & V_8 -> V_19 , V_4 , V_10 , V_6 -> V_20 ) ;
if ( V_13 == NULL )
return - V_21 ;
if ( V_15 . V_16 ) {
V_11 = F_4 ( V_13 -> V_17 , & V_2 -> V_22 ,
V_6 -> V_20 ) ;
if ( V_11 )
return V_11 ;
}
if ( V_4 -> V_23 != NULL && V_24 > 0 ) {
struct V_25 * V_26 = F_5 ( V_13 -> V_27 . V_23 ) ;
assert ( V_8 != NULL ) ;
V_11 = - V_21 ;
if ( V_26 -> V_28 == NULL &&
F_6 ( V_13 -> V_27 . V_23 , V_2 -> V_29 -> V_30 ) < 0 )
goto V_31;
V_11 = F_7 ( V_13 , V_8 -> V_32 , V_4 -> V_33 ) ;
}
V_8 -> V_19 . V_34 . V_35 += V_6 -> V_20 ;
F_8 ( & V_8 -> V_19 , V_36 ) ;
V_31:
return V_11 ;
}
static int F_9 ( union V_37 * V_38 ,
struct V_5 * V_6 ,
struct V_7 * V_8 ,
struct V_1 * V_2 )
{
struct V_3 V_4 ;
if ( F_10 ( V_38 , V_2 , & V_4 , V_6 ,
V_39 ) < 0 ) {
fprintf ( V_40 , L_1 ,
V_38 -> V_41 . type ) ;
return - 1 ;
}
if ( V_4 . V_42 || ( V_43 && V_4 . V_23 == NULL ) )
return 0 ;
if ( V_44 && ! F_11 ( V_6 -> V_45 , V_46 ) )
return 0 ;
if ( V_4 . V_47 != NULL )
V_4 . V_47 -> V_48 -> V_49 = 1 ;
if ( F_1 ( V_2 , & V_4 , V_6 , V_8 ) ) {
F_12 ( L_2 ) ;
return - 1 ;
}
return 0 ;
}
static int F_13 ( union V_37 * V_38 ,
struct V_5 * V_6 V_50 ,
struct V_1 * V_2 )
{
struct V_7 * V_8 = F_14 ( V_2 -> V_29 ,
V_38 -> V_51 . V_52 ) ;
if ( V_53 ) {
const char * V_54 = V_8 ? F_15 ( V_8 ) : L_3 ;
F_16 ( & V_55 ,
V_38 -> V_51 . V_56 , V_38 -> V_51 . V_57 ,
V_38 -> V_51 . V_52 ,
V_54 ,
V_38 -> V_51 . V_58 ) ;
}
F_17 ( L_4 V_59 L_5 , V_38 -> V_51 . V_56 , V_38 -> V_51 . V_57 ,
V_8 ? F_15 ( V_8 ) : L_6 ,
V_38 -> V_51 . V_58 ) ;
return 0 ;
}
static int F_18 ( struct V_1 * V_60 )
{
if ( ! ( V_60 -> V_61 & V_62 ) ) {
if ( V_14 ) {
F_19 ( L_7
L_8
L_9 ) ;
return - V_63 ;
}
if ( V_15 . V_16 ) {
F_19 ( L_10
L_11 ) ;
return - 1 ;
}
} else if ( ! V_64 && V_65 . V_66 != V_67 &&
! V_15 . V_16 ) {
V_15 . V_16 = true ;
if ( F_20 ( & V_65 ) < 0 ) {
F_19 ( L_12
L_13 ) ;
return - V_63 ;
}
}
return 0 ;
}
static void F_21 ( int T_1 V_50 )
{
V_68 = 1 ;
}
static T_2 F_22 ( struct V_19 * V_60 ,
const char * V_69 , T_3 * V_70 )
{
T_2 V_71 ;
char V_72 ;
unsigned long V_73 = V_60 -> V_34 . V_73 [ V_36 ] ;
V_73 = F_23 ( V_73 , & V_72 ) ;
V_71 = fprintf ( V_70 , L_14 , V_73 , V_72 ) ;
if ( V_69 != NULL )
V_71 += fprintf ( V_70 , L_15 , V_69 ) ;
return V_71 + fprintf ( V_70 , L_16 ) ;
}
static int F_24 ( struct V_74 * V_29 ,
const char * V_75 )
{
struct V_7 * V_76 ;
F_25 (pos, &evlist->entries, node) {
struct V_19 * V_19 = & V_76 -> V_19 ;
const char * V_69 = NULL ;
if ( F_26 ( & V_19 -> V_77 ) != F_27 ( & V_19 -> V_77 ) )
V_69 = F_15 ( V_76 ) ;
F_22 ( V_19 , V_69 , stdout ) ;
F_28 ( V_19 , NULL , false , stdout ) ;
fprintf ( stdout , L_17 ) ;
}
if ( V_78 == V_79 &&
V_80 == V_81 ) {
fprintf ( stdout , L_18 , V_75 ) ;
if ( V_53 ) {
bool V_82 = ! strcmp ( V_83 , L_19 ) ;
F_29 ( stdout , & V_55 ,
V_82 ) ;
F_30 ( & V_55 ) ;
}
}
return 0 ;
}
static int F_31 ( void )
{
int V_71 = - V_63 ;
T_4 V_84 ;
struct V_1 * V_2 ;
struct V_7 * V_76 ;
struct V_47 * V_85 ;
struct V_86 * V_87 ;
const char * V_75 = L_20 ;
signal ( V_88 , F_21 ) ;
V_2 = F_32 ( V_89 , V_90 , V_91 , false , & V_92 ) ;
if ( V_2 == NULL )
return - V_21 ;
if ( V_44 ) {
V_71 = F_33 ( V_2 , V_44 , V_46 ) ;
if ( V_71 )
goto V_93;
}
if ( V_53 )
F_34 ( & V_55 ) ;
V_71 = F_18 ( V_2 ) ;
if ( V_71 )
goto V_93;
V_71 = F_35 ( V_2 , & V_92 ) ;
if ( V_71 )
goto V_93;
V_85 = V_2 -> V_94 . V_95 [ V_96 ] ;
V_87 = F_36 ( V_85 ) ;
if ( V_85 == NULL ||
( V_85 -> V_48 -> V_49 &&
( V_87 -> V_97 == NULL ||
V_87 -> V_97 -> V_33 == 0 ) ) ) {
const struct V_48 * V_98 = V_85 -> V_48 ;
F_19 (
L_21
L_22
L_23 ,
F_37 ( & V_98 -> V_99 [ V_96 ] ) ?
L_24
L_25 :
L_26 ) ;
}
if ( V_100 ) {
F_38 ( V_2 , stdout ) ;
goto V_93;
}
if ( V_101 > 3 )
F_39 ( V_2 , stdout ) ;
if ( V_101 > 2 )
F_40 ( V_2 , stdout ) ;
V_84 = 0 ;
F_25 (pos, &session->evlist->entries, node) {
struct V_19 * V_19 = & V_76 -> V_19 ;
F_41 ( V_19 ) ;
F_42 ( V_19 ) ;
V_84 += V_19 -> V_34 . V_73 [ V_36 ] ;
}
if ( V_84 == 0 ) {
F_19 ( L_27 , V_89 ) ;
goto V_93;
}
if ( V_24 > 0 )
F_43 ( V_2 -> V_29 , V_75 ) ;
else
F_24 ( V_2 -> V_29 , V_75 ) ;
V_93:
return V_71 ;
}
static int
F_44 ( const struct V_102 * T_5 V_50 , const char * V_103 ,
int V_104 )
{
char * V_105 , * V_106 ;
char * V_107 ;
if ( V_104 ) {
V_64 = true ;
return 0 ;
}
V_15 . V_16 = true ;
if ( ! V_103 )
return 0 ;
V_105 = strtok ( ( char * ) V_103 , L_28 ) ;
if ( ! V_105 )
return - 1 ;
if ( ! strncmp ( V_105 , L_29 , strlen ( V_103 ) ) )
V_65 . V_66 = V_108 ;
else if ( ! strncmp ( V_105 , L_30 , strlen ( V_103 ) ) )
V_65 . V_66 = V_109 ;
else if ( ! strncmp ( V_105 , L_31 , strlen ( V_103 ) ) )
V_65 . V_66 = V_110 ;
else if ( ! strncmp ( V_105 , L_32 , strlen ( V_103 ) ) ) {
V_65 . V_66 = V_67 ;
V_15 . V_16 = false ;
return 0 ;
}
else
return - 1 ;
V_105 = strtok ( NULL , L_28 ) ;
if ( ! V_105 )
goto V_111;
V_65 . V_112 = strtod ( V_105 , & V_107 ) ;
if ( V_105 == V_107 )
return - 1 ;
V_106 = strtok ( NULL , L_28 ) ;
if ( ! V_106 )
goto V_111;
if ( V_106 [ 0 ] != 'c' ) {
V_65 . V_113 = strtod ( V_106 , & V_107 ) ;
V_106 = strtok ( NULL , L_28 ) ;
if ( ! V_106 )
goto V_111;
}
if ( ! strcmp ( V_106 , L_33 ) )
V_65 . V_114 = V_115 ;
else if ( ! strcmp ( V_106 , L_34 ) )
V_65 . V_114 = V_116 ;
else
return - 1 ;
V_111:
if ( F_20 ( & V_65 ) < 0 ) {
fprintf ( V_40 , L_35 ) ;
return - 1 ;
}
return 0 ;
}
int F_45 ( int V_117 , const char * * V_118 , const char * T_6 V_50 )
{
V_117 = F_46 ( V_117 , V_118 , V_119 , V_120 , 0 ) ;
if ( V_121 )
V_24 = 0 ;
else if ( V_122 )
V_24 = 1 ;
if ( V_123 )
V_65 . V_114 = V_115 ;
if ( strcmp ( V_89 , L_36 ) != 0 )
F_47 ( true ) ;
else
V_24 = 0 ;
if ( V_24 > 0 ) {
V_15 . V_124 = sizeof( struct V_25 ) ;
V_39 = V_125 ;
if ( V_101 ) {
V_15 . V_124 += sizeof( V_126 ) ;
V_15 . V_127 = true ;
}
}
if ( F_48 () < 0 )
return - 1 ;
F_49 ( V_120 , V_119 ) ;
if ( V_80 != V_81 ) {
if ( F_50 ( L_37 ) < 0 )
return - 1 ;
if ( ! strstr ( V_78 , L_37 ) )
V_128 . V_129 = 1 ;
} else
V_15 . V_130 = false ;
if ( V_117 )
F_51 ( V_120 , V_119 ) ;
F_52 ( & V_131 , V_15 . V_132 , L_38 , stdout ) ;
F_52 ( & V_133 , V_15 . V_134 , L_39 , stdout ) ;
F_52 ( & V_135 , V_15 . V_136 , L_40 , stdout ) ;
return F_31 () ;
}
