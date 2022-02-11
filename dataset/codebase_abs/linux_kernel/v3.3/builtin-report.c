static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
struct V_7 * V_7 )
{
struct V_8 * V_9 = NULL ;
int V_10 = 0 ;
struct V_11 * V_12 ;
if ( ( V_13 || V_14 . V_15 ) && V_6 -> V_16 ) {
V_10 = F_2 ( V_7 , V_2 , V_4 -> V_17 ,
V_6 -> V_16 , & V_9 ) ;
if ( V_10 )
return V_10 ;
}
V_12 = F_3 ( & V_2 -> V_18 , V_4 , V_9 , V_6 -> V_19 ) ;
if ( V_12 == NULL )
return - V_20 ;
if ( V_14 . V_15 ) {
V_10 = F_4 ( V_12 -> V_16 ,
& V_2 -> V_18 . V_21 ,
V_6 -> V_19 ) ;
if ( V_10 )
return V_10 ;
}
if ( V_4 -> V_22 != NULL && V_23 > 0 ) {
struct V_24 * V_25 = F_5 ( V_12 -> V_26 . V_22 ) ;
assert ( V_2 != NULL ) ;
V_10 = - V_20 ;
if ( V_25 -> V_27 == NULL && F_6 ( V_12 -> V_26 . V_22 ) < 0 )
goto V_28;
V_10 = F_7 ( V_12 , V_2 -> V_29 , V_4 -> V_30 ) ;
}
V_2 -> V_18 . V_31 . V_32 += V_6 -> V_19 ;
F_8 ( & V_2 -> V_18 , V_33 ) ;
V_28:
return V_10 ;
}
static int F_9 ( struct V_34 * V_35 ,
union V_36 * V_37 ,
struct V_5 * V_6 ,
struct V_1 * V_2 ,
struct V_7 * V_7 )
{
struct V_38 * V_39 = F_10 ( V_35 , struct V_38 , V_35 ) ;
struct V_3 V_4 ;
if ( F_11 ( V_37 , V_7 , & V_4 , V_6 ,
V_39 -> V_40 ) < 0 ) {
fprintf ( V_41 , L_1 ,
V_37 -> V_42 . type ) ;
return - 1 ;
}
if ( V_4 . V_43 || ( V_39 -> V_44 && V_4 . V_22 == NULL ) )
return 0 ;
if ( V_39 -> V_45 && ! F_12 ( V_6 -> V_46 , V_39 -> V_47 ) )
return 0 ;
if ( V_4 . V_48 != NULL )
V_4 . V_48 -> V_49 -> V_50 = 1 ;
if ( F_1 ( V_2 , & V_4 , V_6 , V_7 ) ) {
F_13 ( L_2 ) ;
return - 1 ;
}
return 0 ;
}
static int F_14 ( struct V_34 * V_35 ,
union V_36 * V_37 ,
struct V_5 * V_6 V_51 ,
struct V_1 * V_2 ,
struct V_7 * V_7 V_51 )
{
struct V_38 * V_39 = F_10 ( V_35 , struct V_38 , V_35 ) ;
if ( V_39 -> V_52 ) {
const char * V_53 = V_2 ? F_15 ( V_2 ) : L_3 ;
F_16 ( & V_39 -> V_54 ,
V_37 -> V_55 . V_56 , V_37 -> V_55 . V_57 ,
V_37 -> V_55 . V_58 ,
V_53 ,
V_37 -> V_55 . V_59 ) ;
}
F_17 ( L_4 V_60 L_5 , V_37 -> V_55 . V_56 , V_37 -> V_55 . V_57 ,
V_2 ? F_15 ( V_2 ) : L_6 ,
V_37 -> V_55 . V_59 ) ;
return 0 ;
}
static int F_18 ( struct V_38 * V_39 )
{
struct V_61 * V_62 = V_39 -> V_63 ;
if ( ! ( V_62 -> V_64 & V_65 ) ) {
if ( V_13 ) {
F_19 ( L_7
L_8
L_9 ) ;
return - V_66 ;
}
if ( V_14 . V_15 ) {
F_19 ( L_10
L_11 ) ;
return - 1 ;
}
} else if ( ! V_39 -> V_67 &&
V_68 . V_69 != V_70 &&
! V_14 . V_15 ) {
V_14 . V_15 = true ;
if ( F_20 ( & V_68 ) < 0 ) {
F_19 ( L_12
L_13 ) ;
return - V_66 ;
}
}
return 0 ;
}
static void F_21 ( int T_1 V_51 )
{
V_71 = 1 ;
}
static T_2 F_22 ( struct V_18 * V_62 ,
const char * V_72 , T_3 * V_73 )
{
T_2 V_74 ;
char V_75 ;
unsigned long V_76 = V_62 -> V_31 . V_76 [ V_33 ] ;
V_76 = F_23 ( V_76 , & V_75 ) ;
V_74 = fprintf ( V_73 , L_14 , V_76 , V_75 ) ;
if ( V_72 != NULL )
V_74 += fprintf ( V_73 , L_15 , V_72 ) ;
return V_74 + fprintf ( V_73 , L_16 ) ;
}
static int F_24 ( struct V_77 * V_78 ,
struct V_38 * V_39 ,
const char * V_79 )
{
struct V_1 * V_80 ;
F_25 (pos, &evlist->entries, node) {
struct V_18 * V_18 = & V_80 -> V_18 ;
const char * V_72 = F_15 ( V_80 ) ;
F_22 ( V_18 , V_72 , stdout ) ;
F_26 ( V_18 , NULL , false , true , 0 , 0 , stdout ) ;
fprintf ( stdout , L_17 ) ;
}
if ( V_81 == V_82 &&
V_83 == V_84 ) {
fprintf ( stdout , L_18 , V_79 ) ;
if ( V_39 -> V_52 ) {
bool V_85 = ! strcmp ( V_39 -> V_86 , L_19 ) ;
F_27 ( stdout , & V_39 -> V_54 ,
V_85 ) ;
F_28 ( & V_39 -> V_54 ) ;
}
}
return 0 ;
}
static int F_29 ( struct V_38 * V_39 )
{
int V_74 = - V_66 ;
T_4 V_87 ;
struct V_61 * V_63 ;
struct V_1 * V_80 ;
struct V_48 * V_88 ;
struct V_89 * V_90 ;
const char * V_79 = L_20 ;
signal ( V_91 , F_21 ) ;
V_63 = F_30 ( V_39 -> V_92 , V_93 ,
V_39 -> V_94 , false , & V_39 -> V_35 ) ;
if ( V_63 == NULL )
return - V_20 ;
V_39 -> V_63 = V_63 ;
if ( V_39 -> V_45 ) {
V_74 = F_31 ( V_63 , V_39 -> V_45 ,
V_39 -> V_47 ) ;
if ( V_74 )
goto V_95;
}
if ( V_23 <= 0 )
F_32 ( V_63 , stdout , V_39 -> V_96 ) ;
if ( V_39 -> V_52 )
F_33 ( & V_39 -> V_54 ) ;
V_74 = F_18 ( V_39 ) ;
if ( V_74 )
goto V_95;
V_74 = F_34 ( V_63 , & V_39 -> V_35 ) ;
if ( V_74 )
goto V_95;
V_88 = V_63 -> V_97 . V_98 [ V_99 ] ;
V_90 = F_35 ( V_88 ) ;
if ( V_88 == NULL ||
( V_88 -> V_49 -> V_50 &&
( V_90 -> V_100 == NULL ||
V_90 -> V_100 -> V_30 == 0 ) ) ) {
const struct V_49 * V_101 = V_88 -> V_49 ;
F_19 (
L_21
L_22
L_23 ,
F_36 ( & V_101 -> V_102 [ V_99 ] ) ?
L_24
L_25 :
L_26 ) ;
}
if ( V_103 ) {
F_37 ( V_63 , stdout ) ;
goto V_95;
}
if ( V_104 > 3 )
F_38 ( V_63 , stdout ) ;
if ( V_104 > 2 )
F_39 ( V_63 , stdout ) ;
V_87 = 0 ;
F_25 (pos, &session->evlist->entries, node) {
struct V_18 * V_18 = & V_80 -> V_18 ;
F_40 ( V_18 ) ;
F_41 ( V_18 ) ;
V_87 += V_18 -> V_31 . V_76 [ V_33 ] ;
}
if ( V_87 == 0 ) {
F_19 ( L_27 , V_63 -> V_105 ) ;
goto V_95;
}
if ( V_23 > 0 ) {
F_42 ( V_63 -> V_78 , V_79 ,
NULL , NULL , 0 ) ;
} else
F_24 ( V_63 -> V_78 , V_39 , V_79 ) ;
V_95:
return V_74 ;
}
static int
F_43 ( const struct V_106 * V_107 , const char * V_108 , int V_109 )
{
struct V_38 * V_39 = (struct V_38 * ) V_107 -> V_59 ;
char * V_110 , * V_111 ;
char * V_112 ;
if ( V_109 ) {
V_39 -> V_67 = true ;
return 0 ;
}
V_14 . V_15 = true ;
if ( ! V_108 )
return 0 ;
V_110 = strtok ( ( char * ) V_108 , L_28 ) ;
if ( ! V_110 )
return - 1 ;
if ( ! strncmp ( V_110 , L_29 , strlen ( V_108 ) ) )
V_68 . V_69 = V_113 ;
else if ( ! strncmp ( V_110 , L_30 , strlen ( V_108 ) ) )
V_68 . V_69 = V_114 ;
else if ( ! strncmp ( V_110 , L_31 , strlen ( V_108 ) ) )
V_68 . V_69 = V_115 ;
else if ( ! strncmp ( V_110 , L_32 , strlen ( V_108 ) ) ) {
V_68 . V_69 = V_70 ;
V_14 . V_15 = false ;
return 0 ;
}
else
return - 1 ;
V_110 = strtok ( NULL , L_28 ) ;
if ( ! V_110 )
goto V_116;
V_68 . V_117 = strtod ( V_110 , & V_112 ) ;
if ( V_110 == V_112 )
return - 1 ;
V_111 = strtok ( NULL , L_28 ) ;
if ( ! V_111 )
goto V_116;
if ( V_111 [ 0 ] != 'c' ) {
V_68 . V_118 = strtoul ( V_111 , & V_112 , 0 ) ;
V_111 = strtok ( NULL , L_28 ) ;
if ( ! V_111 )
goto V_116;
}
if ( ! strcmp ( V_111 , L_33 ) )
V_68 . V_119 = V_120 ;
else if ( ! strcmp ( V_111 , L_34 ) )
V_68 . V_119 = V_121 ;
else
return - 1 ;
V_116:
if ( F_20 ( & V_68 ) < 0 ) {
fprintf ( V_41 , L_35 ) ;
return - 1 ;
}
return 0 ;
}
int F_44 ( int V_122 , const char * * V_123 , const char * T_5 V_51 )
{
struct V_124 V_125 ;
char V_126 [] = L_36 ;
const char * const V_127 [] = {
L_37 ,
NULL
} ;
struct V_38 V_128 = {
. V_35 = {
. V_6 = F_9 ,
. V_129 = V_130 ,
. V_131 = V_132 ,
. exit = V_133 ,
. V_134 = V_133 ,
. V_135 = V_136 ,
. V_55 = F_14 ,
. V_137 = V_138 ,
. V_139 = V_140 ,
. V_141 = V_142 ,
. V_143 = V_144 ,
. V_145 = true ,
. V_146 = true ,
} ,
. V_86 = L_38 ,
} ;
const struct V_106 V_147 [] = {
F_45 ( 'i' , L_39 , & V_128 . V_92 , L_40 ,
L_41 ) ,
F_46 ( 'v' , L_42 , & V_104 ,
L_43 ) ,
F_47 ( 'D' , L_44 , & V_103 ,
L_45 ) ,
F_45 ( 'k' , L_46 , & V_14 . V_148 ,
L_40 , L_47 ) ,
F_45 ( 0 , L_48 , & V_14 . V_149 ,
L_40 , L_49 ) ,
F_47 ( 'f' , L_50 , & V_128 . V_94 , L_51 ) ,
F_47 ( 'm' , L_52 , & V_14 . V_150 ,
L_53 ) ,
F_47 ( 'n' , L_54 , & V_14 . V_151 ,
L_55 ) ,
F_47 ( 'T' , L_56 , & V_128 . V_52 ,
L_57 ) ,
F_45 ( 0 , L_58 , & V_128 . V_86 , L_59 ,
L_60 ) ,
F_47 ( 0 , L_61 , & V_128 . V_152 , L_62 ) ,
F_47 ( 0 , L_63 , & V_128 . V_153 ,
L_64 ) ,
F_45 ( 's' , L_65 , & V_81 , L_66 ,
L_67 ) ,
F_47 ( 0 , L_68 , & V_14 . V_154 ,
L_69 ) ,
F_45 ( 'p' , L_70 , & V_83 , L_71 ,
L_72 ) ,
F_47 ( 'x' , L_73 , & V_14 . V_155 ,
L_74 ) ,
F_48 ( 'g' , L_75 , & V_128 , L_76 ,
L_77
L_78 , & F_43 , V_126 ) ,
F_47 ( 'G' , L_79 , & V_128 . V_156 ,
L_80 ) ,
F_45 ( 'd' , L_81 , & V_14 . V_157 , L_82 ,
L_83 ) ,
F_45 ( 'c' , L_84 , & V_14 . V_158 , L_85 ,
L_86 ) ,
F_45 ( 'S' , L_87 , & V_14 . V_159 , L_88 ,
L_89 ) ,
F_45 ( 'w' , L_90 , & V_14 . V_160 ,
L_91 ,
L_92 ) ,
F_45 ( 't' , L_93 , & V_14 . V_161 , L_94 ,
L_95
L_96 ) ,
F_47 ( 'U' , L_97 , & V_128 . V_44 ,
L_98 ) ,
F_45 ( 0 , L_99 , & V_14 . V_162 , L_100 ,
L_101 ) ,
F_45 ( 'C' , L_102 , & V_128 . V_45 , L_102 ,
L_103 ) ,
F_47 ( 'I' , L_104 , & V_128 . V_96 ,
L_105 ) ,
F_47 ( 0 , L_106 , & V_14 . V_163 ,
L_107 ) ,
F_47 ( 0 , L_108 , & V_14 . V_164 ,
L_109 ) ,
F_45 ( 'M' , L_110 , & V_165 , L_111 ,
L_112 ) ,
F_47 ( 0 , L_113 , & V_14 . V_166 ,
L_114 ) ,
F_49 ()
} ;
V_122 = F_50 ( V_122 , V_123 , V_147 , V_127 , 0 ) ;
if ( V_128 . V_153 )
V_23 = 0 ;
else if ( V_128 . V_152 )
V_23 = 1 ;
if ( V_128 . V_156 )
V_68 . V_119 = V_120 ;
if ( ! V_128 . V_92 || ! strlen ( V_128 . V_92 ) ) {
if ( ! F_51 ( V_167 , & V_125 ) && F_52 ( V_125 . V_168 ) )
V_128 . V_92 = L_115 ;
else
V_128 . V_92 = L_116 ;
}
if ( strcmp ( V_128 . V_92 , L_115 ) != 0 )
F_53 ( true ) ;
else
V_23 = 0 ;
if ( V_23 > 0 ) {
V_14 . V_169 = sizeof( struct V_24 ) ;
V_128 . V_40 = V_170 ;
if ( V_104 ) {
V_14 . V_169 += sizeof( V_171 ) ;
V_14 . V_172 = true ;
}
}
if ( F_54 () < 0 )
return - 1 ;
F_55 ( V_127 , V_147 ) ;
if ( V_83 != V_84 ) {
if ( F_56 ( L_70 ) < 0 )
return - 1 ;
if ( ! strstr ( V_81 , L_70 ) )
V_173 . V_174 = 1 ;
} else
V_14 . V_155 = false ;
if ( V_122 )
F_57 ( V_127 , V_147 ) ;
F_58 ( & V_175 , V_14 . V_176 , L_117 , stdout ) ;
F_58 ( & V_177 , V_14 . V_178 , L_118 , stdout ) ;
F_58 ( & V_179 , V_14 . V_180 , L_119 , stdout ) ;
return F_29 ( & V_128 ) ;
}
