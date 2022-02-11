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
if ( V_4 . V_44 != NULL )
V_4 . V_44 -> V_45 -> V_46 = 1 ;
if ( F_1 ( V_2 , & V_4 , V_6 , V_8 ) ) {
F_11 ( L_2 ) ;
return - 1 ;
}
return 0 ;
}
static int F_12 ( union V_37 * V_38 ,
struct V_5 * V_6 V_47 ,
struct V_1 * V_2 )
{
struct V_7 * V_8 = F_13 ( V_2 -> V_29 ,
V_38 -> V_48 . V_49 ) ;
if ( V_50 ) {
const char * V_51 = V_8 ? F_14 ( V_8 ) : L_3 ;
F_15 ( & V_52 ,
V_38 -> V_48 . V_53 , V_38 -> V_48 . V_54 ,
V_38 -> V_48 . V_49 ,
V_51 ,
V_38 -> V_48 . V_55 ) ;
}
F_16 ( L_4 V_56 L_5 , V_38 -> V_48 . V_53 , V_38 -> V_48 . V_54 ,
V_8 ? F_14 ( V_8 ) : L_6 ,
V_38 -> V_48 . V_55 ) ;
return 0 ;
}
static int F_17 ( struct V_1 * V_57 )
{
if ( ! ( V_57 -> V_58 & V_59 ) ) {
if ( V_14 ) {
fprintf ( V_40 , L_7
L_8
L_9 ) ;
return - V_60 ;
}
if ( V_15 . V_16 ) {
fprintf ( V_40 , L_10
L_11
L_12 ) ;
return - 1 ;
}
} else if ( ! V_61 && V_62 . V_63 != V_64 &&
! V_15 . V_16 ) {
V_15 . V_16 = true ;
if ( F_18 ( & V_62 ) < 0 ) {
fprintf ( V_40 , L_13
L_14 ) ;
return - V_60 ;
}
}
return 0 ;
}
static void F_19 ( int T_1 V_47 )
{
V_65 = 1 ;
}
static T_2 F_20 ( struct V_19 * V_57 ,
const char * V_66 , T_3 * V_67 )
{
T_2 V_68 ;
char V_69 ;
unsigned long V_70 = V_57 -> V_34 . V_70 [ V_36 ] ;
V_70 = F_21 ( V_70 , & V_69 ) ;
V_68 = fprintf ( V_67 , L_15 , V_70 , V_69 ) ;
if ( V_66 != NULL )
V_68 += fprintf ( V_67 , L_16 , V_66 ) ;
return V_68 + fprintf ( V_67 , L_17 ) ;
}
static int F_22 ( struct V_71 * V_29 ,
const char * V_72 )
{
struct V_7 * V_73 ;
F_23 (pos, &evlist->entries, node) {
struct V_19 * V_19 = & V_73 -> V_19 ;
const char * V_66 = NULL ;
if ( F_24 ( & V_19 -> V_74 ) != F_25 ( & V_19 -> V_74 ) )
V_66 = F_14 ( V_73 ) ;
F_20 ( V_19 , V_66 , stdout ) ;
F_26 ( V_19 , NULL , false , stdout ) ;
fprintf ( stdout , L_18 ) ;
}
if ( V_75 == V_76 &&
V_77 == V_78 ) {
fprintf ( stdout , L_19 , V_72 ) ;
if ( V_50 ) {
bool V_79 = ! strcmp ( V_80 , L_20 ) ;
F_27 ( stdout , & V_52 ,
V_79 ) ;
F_28 ( & V_52 ) ;
}
}
return 0 ;
}
static int F_29 ( void )
{
int V_68 = - V_60 ;
T_4 V_81 ;
struct V_1 * V_2 ;
struct V_7 * V_73 ;
struct V_44 * V_82 ;
struct V_83 * V_84 ;
const char * V_72 = L_21 ;
signal ( V_85 , F_19 ) ;
V_2 = F_30 ( V_86 , V_87 , V_88 , false , & V_89 ) ;
if ( V_2 == NULL )
return - V_21 ;
if ( V_50 )
F_31 ( & V_52 ) ;
V_68 = F_17 ( V_2 ) ;
if ( V_68 )
goto V_90;
V_68 = F_32 ( V_2 , & V_89 ) ;
if ( V_68 )
goto V_90;
V_82 = V_2 -> V_91 . V_92 [ V_93 ] ;
V_84 = F_33 ( V_82 ) ;
if ( V_82 == NULL ||
( V_82 -> V_45 -> V_46 &&
( V_84 -> V_94 == NULL ||
V_84 -> V_94 -> V_33 == 0 ) ) ) {
const struct V_45 * V_95 = V_82 -> V_45 ;
F_34 (
L_22
L_23
L_24 ,
F_35 ( & V_95 -> V_96 [ V_93 ] ) ?
L_25
L_26 :
L_27 ) ;
}
if ( V_97 ) {
F_36 ( V_2 , stdout ) ;
goto V_90;
}
if ( V_98 > 3 )
F_37 ( V_2 , stdout ) ;
if ( V_98 > 2 )
F_38 ( V_2 , stdout ) ;
V_81 = 0 ;
F_23 (pos, &session->evlist->entries, node) {
struct V_19 * V_19 = & V_73 -> V_19 ;
F_39 ( V_19 ) ;
F_40 ( V_19 ) ;
V_81 += V_19 -> V_34 . V_70 [ V_36 ] ;
}
if ( V_81 == 0 ) {
F_34 ( L_28 , V_86 ) ;
goto V_90;
}
if ( V_24 > 0 )
F_41 ( V_2 -> V_29 , V_72 ) ;
else
F_22 ( V_2 -> V_29 , V_72 ) ;
V_90:
return V_68 ;
}
static int
F_42 ( const struct V_99 * T_5 V_47 , const char * V_100 ,
int V_101 )
{
char * V_102 , * V_103 ;
char * V_104 ;
if ( V_101 ) {
V_61 = true ;
return 0 ;
}
V_15 . V_16 = true ;
if ( ! V_100 )
return 0 ;
V_102 = strtok ( ( char * ) V_100 , L_29 ) ;
if ( ! V_102 )
return - 1 ;
if ( ! strncmp ( V_102 , L_30 , strlen ( V_100 ) ) )
V_62 . V_63 = V_105 ;
else if ( ! strncmp ( V_102 , L_31 , strlen ( V_100 ) ) )
V_62 . V_63 = V_106 ;
else if ( ! strncmp ( V_102 , L_32 , strlen ( V_100 ) ) )
V_62 . V_63 = V_107 ;
else if ( ! strncmp ( V_102 , L_33 , strlen ( V_100 ) ) ) {
V_62 . V_63 = V_64 ;
V_15 . V_16 = false ;
return 0 ;
}
else
return - 1 ;
V_102 = strtok ( NULL , L_29 ) ;
if ( ! V_102 )
goto V_108;
V_103 = strtok ( NULL , L_29 ) ;
V_62 . V_109 = strtod ( V_102 , & V_104 ) ;
if ( V_102 == V_104 )
return - 1 ;
if ( V_103 )
V_62 . V_110 = strtod ( V_103 , & V_104 ) ;
V_108:
if ( F_18 ( & V_62 ) < 0 ) {
fprintf ( V_40 , L_34 ) ;
return - 1 ;
}
return 0 ;
}
int F_43 ( int V_111 , const char * * V_112 , const char * T_6 V_47 )
{
V_111 = F_44 ( V_111 , V_112 , V_113 , V_114 , 0 ) ;
if ( V_115 )
V_24 = 0 ;
else if ( V_116 )
V_24 = 1 ;
if ( strcmp ( V_86 , L_35 ) != 0 )
F_45 ( true ) ;
else
V_24 = 0 ;
if ( V_24 > 0 ) {
V_15 . V_117 = sizeof( struct V_25 ) ;
V_39 = V_118 ;
if ( V_98 ) {
V_15 . V_117 += sizeof( V_119 ) ;
V_15 . V_120 = true ;
}
}
if ( F_46 () < 0 )
return - 1 ;
F_47 ( V_114 , V_113 ) ;
if ( V_77 != V_78 ) {
if ( F_48 ( L_36 ) < 0 )
return - 1 ;
V_121 . V_122 = 1 ;
} else
V_15 . V_123 = false ;
if ( V_111 )
F_49 ( V_114 , V_113 ) ;
F_50 ( & V_124 , V_15 . V_125 , L_37 , stdout ) ;
F_50 ( & V_126 , V_15 . V_127 , L_38 , stdout ) ;
F_50 ( & V_128 , V_15 . V_129 , L_39 , stdout ) ;
return F_29 () ;
}
