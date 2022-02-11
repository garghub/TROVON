static T_1 F_1 ( struct V_1 * V_1 , char * V_2 )
{
struct V_3 * V_4 = V_1 -> V_4 ;
struct V_5 * V_6 = & V_4 -> V_6 ;
struct V_7 * V_8 ;
T_1 V_9 = 0 ;
int V_10 ;
for ( V_10 = 0 ; V_10 < V_6 -> V_11 ; V_10 ++ ) {
int V_12 = 1 ;
V_8 = & V_1 -> V_13 [ V_10 ] ;
if ( ! F_2 ( & V_8 -> V_14 ) ) {
V_12 = 0 ;
F_3 ( & V_8 -> V_14 ) ;
}
V_9 += snprintf ( V_2 + V_9 , V_15 - V_9 ,
L_1 ,
V_10 ,
V_8 -> V_16 . V_17 . V_18 ,
V_8 -> V_16 . V_17 . V_19 ,
V_12 ) ;
}
return V_9 ;
}
static T_1 F_4 ( struct V_1 * V_1 , char * V_2 )
{
int V_20 , V_21 ;
int V_22 , V_23 ;
int V_24 , V_25 , V_26 , V_27 ;
V_20 = F_5 ( & V_1 -> V_28 . V_20 ) ;
V_22 = V_1 -> V_28 . V_22 ;
V_23 = F_5 ( & V_1 -> V_28 . V_23 ) ;
V_24 = V_1 -> V_28 . V_24 ;
V_25 = F_5 ( & V_1 -> V_28 . V_25 ) ;
V_26 = V_1 -> V_28 . V_26 ;
V_27 = V_1 -> V_28 . V_27 ;
V_21 = V_1 -> V_28 . V_21 ;
return snprintf ( V_2 , V_15 ,
L_2 ,
V_23 ,
V_22 ,
V_25 ,
V_24 ,
V_27 ,
V_26 ,
V_1 -> V_28 . V_29 ,
V_1 -> V_28 . V_30 ,
V_20 ,
V_21 ,
F_6 ( V_1 -> V_28 . V_31 ) ) ;
}
static T_1 F_7 ( struct V_1 * V_1 , char * V_2 )
{
int V_32 , V_33 ;
F_8 ( V_1 , & V_32 , & V_33 ) ;
return snprintf ( V_2 , V_15 , L_3 ,
V_32 , V_33 ) ;
}
static T_1 F_9 ( struct V_1 * V_1 , char * V_2 )
{
T_1 V_9 ;
V_9 = snprintf ( V_2 , V_15 ,
L_4 ,
F_10 ( & V_1 -> V_34 ) ,
F_10 ( & V_1 -> V_35 ) ,
F_10 ( & V_1 -> V_36 ) ,
F_10 ( & V_1 -> V_37 ) ,
F_10 ( & V_1 -> V_38 ) ,
F_10 ( & V_1 -> V_39 ) ) ;
return V_9 ;
}
static T_1 F_11 ( struct V_1 * V_1 , char * V_2 )
{
return F_12 ( & V_1 -> V_40 , V_2 ) ;
}
static T_1 F_13 ( struct V_1 * V_1 , char * V_2 )
{
struct V_3 * V_4 = V_1 -> V_4 ;
struct V_5 * V_6 = & V_4 -> V_6 ;
T_1 V_9 = 0 ;
V_9 = snprintf ( V_2 , V_15 - V_9 ,
L_5 ,
V_1 -> V_41 ,
V_1 -> V_42 . V_43 , V_6 -> V_42 . V_44 ,
V_1 -> V_42 . V_45 , V_6 -> V_42 . V_46 ,
V_1 -> V_42 . V_47 , V_6 -> V_42 . V_48 ,
V_1 -> V_42 . V_49 , V_6 -> V_42 . V_50 ,
V_1 -> V_42 . V_51 , V_6 -> V_42 . V_52 ,
V_1 -> V_42 . V_53 , V_6 -> V_42 . V_54 ) ;
V_9 += snprintf ( V_2 + V_9 , V_15 - V_9 ,
L_6 ,
V_6 -> V_42 . V_43 , V_6 -> V_42 . V_44 ,
V_6 -> V_42 . V_45 , V_6 -> V_42 . V_46 ,
V_6 -> V_42 . V_47 , V_6 -> V_42 . V_48 ,
V_6 -> V_42 . V_49 , V_6 -> V_42 . V_50 ,
V_6 -> V_42 . V_51 , V_6 -> V_42 . V_52 ,
V_6 -> V_42 . V_55 , V_6 -> V_42 . V_54 ) ;
return V_9 ;
}
static T_1 F_14 ( struct V_1 * V_1 , char * V_2 )
{
struct V_3 * V_4 = V_1 -> V_4 ;
struct V_5 * V_6 = & V_4 -> V_6 ;
struct V_56 * V_57 = & V_1 -> V_57 ;
struct V_58 * V_59 = & V_1 -> V_59 ;
struct V_60 * line ;
T_1 V_9 = 0 ;
int V_61 ;
int V_62 , V_63 ;
int V_64 = 0 , V_65 = 0 , V_66 = 0 ;
int V_67 = 0 , V_68 = 0 ;
int V_69 = 0 , V_70 = 0 , V_71 = 0 , V_72 = 0 , V_73 = 0 ;
int V_74 = 0 , V_75 = 0 ;
int V_76 = 0 , V_77 = 0 , V_78 = 0 , V_79 = 0 ;
int V_80 = 0 , V_81 = 0 ;
F_15 ( & V_59 -> V_82 ) ;
V_62 = ( V_59 -> V_83 ) ? V_59 -> V_83 -> V_84 : - 1 ;
V_63 = ( V_59 -> V_85 ) ? V_59 -> V_85 -> V_84 : - 1 ;
V_61 = V_59 -> V_61 ;
F_16 (line, &l_mg->free_list, list)
V_64 ++ ;
F_17 ( & V_59 -> V_82 ) ;
F_15 ( & V_59 -> V_86 ) ;
F_16 (line, &l_mg->emeta_list, list)
V_66 ++ ;
F_17 ( & V_59 -> V_86 ) ;
F_15 ( & V_59 -> V_87 ) ;
F_16 (line, &l_mg->gc_full_list, list) {
if ( line -> type == V_88 )
V_67 ++ ;
else if ( line -> type == V_89 )
V_68 ++ ;
V_65 ++ ;
V_69 ++ ;
}
F_16 (line, &l_mg->gc_high_list, list) {
if ( line -> type == V_88 )
V_67 ++ ;
else if ( line -> type == V_89 )
V_68 ++ ;
V_65 ++ ;
V_70 ++ ;
}
F_16 (line, &l_mg->gc_mid_list, list) {
if ( line -> type == V_88 )
V_67 ++ ;
else if ( line -> type == V_89 )
V_68 ++ ;
V_65 ++ ;
V_71 ++ ;
}
F_16 (line, &l_mg->gc_low_list, list) {
if ( line -> type == V_88 )
V_67 ++ ;
else if ( line -> type == V_89 )
V_68 ++ ;
V_65 ++ ;
V_72 ++ ;
}
F_16 (line, &l_mg->gc_empty_list, list) {
if ( line -> type == V_88 )
V_67 ++ ;
else if ( line -> type == V_89 )
V_68 ++ ;
V_65 ++ ;
V_73 ++ ;
}
F_16 (line, &l_mg->bad_list, list)
V_74 ++ ;
F_16 (line, &l_mg->corrupt_list, list)
V_75 ++ ;
F_17 ( & V_59 -> V_87 ) ;
F_15 ( & V_59 -> V_82 ) ;
if ( V_59 -> V_83 ) {
V_77 = V_59 -> V_83 -> V_77 ;
V_76 = V_59 -> V_83 -> V_90 ;
V_78 = F_18 ( * V_59 -> V_83 -> V_78 ) ;
V_79 = V_59 -> V_83 -> V_79 ;
V_81 = F_19 ( & V_59 -> V_91 ,
V_92 ) ;
V_80 = F_19 ( V_59 -> V_83 -> V_93 ,
V_57 -> V_94 ) ;
}
F_17 ( & V_59 -> V_82 ) ;
if ( V_61 != V_64 )
F_20 ( L_7 ,
V_61 , V_64 ) ;
V_9 = snprintf ( V_2 , V_15 - V_9 ,
L_8 ,
V_6 -> V_11 , V_57 -> V_95 , V_57 -> V_94 ) ;
V_9 += snprintf ( V_2 + V_9 , V_15 - V_9 ,
L_9 ,
V_62 , V_63 ,
V_61 ,
V_66 , V_81 ,
V_65 ,
V_74 , V_75 ,
V_67 , V_68 ,
V_59 -> V_96 ) ;
V_9 += snprintf ( V_2 + V_9 , V_15 - V_9 ,
L_10 ,
V_69 , V_70 , V_71 , V_72 , V_73 ,
F_5 ( & V_1 -> V_97 . V_98 ) ) ;
V_9 += snprintf ( V_2 + V_9 , V_15 - V_9 ,
L_11 ,
V_62 , V_77 , V_76 , V_78 , V_79 ,
V_80 , V_57 -> V_94 ,
F_5 ( & V_1 -> V_99 ) ) ;
return V_9 ;
}
static T_1 F_21 ( struct V_1 * V_1 , char * V_2 )
{
struct V_3 * V_4 = V_1 -> V_4 ;
struct V_5 * V_6 = & V_4 -> V_6 ;
struct V_56 * V_57 = & V_1 -> V_57 ;
T_1 V_9 = 0 ;
V_9 = snprintf ( V_2 , V_15 - V_9 ,
L_12 ,
V_57 -> V_100 , V_57 -> V_101 ) ;
V_9 += snprintf ( V_2 + V_9 , V_15 - V_9 ,
L_13 ,
V_57 -> V_102 [ 0 ] , V_57 -> V_103 [ 0 ] ,
V_57 -> V_104 ) ;
V_9 += snprintf ( V_2 + V_9 , V_15 - V_9 ,
L_14 ,
V_57 -> V_105 ,
V_57 -> V_106 ,
V_57 -> V_107 ) ;
V_9 += snprintf ( V_2 + V_9 , V_15 - V_9 ,
L_15 ,
V_57 -> V_95 ,
V_57 -> V_94 ,
V_6 -> V_108 ) ;
return V_9 ;
}
static T_1 F_22 ( struct V_1 * V_1 , char * V_2 )
{
return snprintf ( V_2 , V_15 , L_16 , V_1 -> V_109 ) ;
}
static T_1 F_23 ( struct V_1 * V_1 , char * V_2 )
{
return snprintf ( V_2 , V_15 ,
L_17 ,
F_10 ( & V_1 -> V_110 ) ,
F_10 ( & V_1 -> V_111 ) ,
F_10 ( & V_1 -> V_112 ) ,
F_10 ( & V_1 -> V_113 ) ,
F_10 ( & V_1 -> V_114 ) ,
F_10 ( & V_1 -> V_115 ) ,
F_10 ( & V_1 -> V_116 ) ,
F_10 ( & V_1 -> V_117 ) ,
F_10 ( & V_1 -> V_118 ) ,
F_10 ( & V_1 -> V_119 ) ,
F_10 ( & V_1 -> V_120 ) ,
F_10 ( & V_1 -> V_121 ) ,
F_10 ( & V_1 -> V_122 ) ) ;
}
static T_1 F_24 ( struct V_1 * V_1 , const char * V_2 ,
T_2 V_123 )
{
T_2 V_124 ;
int V_125 ;
V_124 = strcspn ( V_2 , L_18 ) ;
if ( V_124 >= V_123 )
return - V_126 ;
if ( F_25 ( V_2 , 0 , & V_125 ) )
return - V_126 ;
F_26 ( V_1 , V_125 ) ;
return V_123 ;
}
static T_1 F_27 ( struct V_1 * V_1 ,
const char * V_2 , T_2 V_123 )
{
T_2 V_124 ;
int V_109 ;
V_124 = strcspn ( V_2 , L_18 ) ;
if ( V_124 >= V_123 )
return - V_126 ;
if ( F_25 ( V_2 , 0 , & V_109 ) )
return - V_126 ;
if ( V_109 < V_1 -> V_127
|| V_109 > V_1 -> V_128
|| V_109 % V_1 -> V_127 != 0 )
return - V_126 ;
F_28 ( V_1 , V_109 ) ;
return V_123 ;
}
static T_1 F_29 ( struct V_129 * V_130 , struct V_131 * V_132 ,
char * V_133 )
{
struct V_1 * V_1 = F_30 ( V_130 , struct V_1 , V_130 ) ;
if ( strcmp ( V_132 -> V_134 , L_19 ) == 0 )
return F_4 ( V_1 , V_133 ) ;
else if ( strcmp ( V_132 -> V_134 , L_20 ) == 0 )
return F_1 ( V_1 , V_133 ) ;
else if ( strcmp ( V_132 -> V_134 , L_21 ) == 0 )
return F_7 ( V_1 , V_133 ) ;
else if ( strcmp ( V_132 -> V_134 , L_22 ) == 0 )
return F_9 ( V_1 , V_133 ) ;
else if ( strcmp ( V_132 -> V_134 , L_23 ) == 0 )
return F_11 ( V_1 , V_133 ) ;
else if ( strcmp ( V_132 -> V_134 , L_24 ) == 0 )
return F_13 ( V_1 , V_133 ) ;
else if ( strcmp ( V_132 -> V_134 , L_25 ) == 0 )
return F_14 ( V_1 , V_133 ) ;
else if ( strcmp ( V_132 -> V_134 , L_26 ) == 0 )
return F_21 ( V_1 , V_133 ) ;
else if ( strcmp ( V_132 -> V_134 , L_27 ) == 0 )
return F_22 ( V_1 , V_133 ) ;
#ifdef F_31
else if ( strcmp ( V_132 -> V_134 , L_28 ) == 0 )
return F_23 ( V_1 , V_133 ) ;
#endif
return 0 ;
}
static T_1 F_32 ( struct V_129 * V_130 , struct V_131 * V_132 ,
const char * V_133 , T_2 V_123 )
{
struct V_1 * V_1 = F_30 ( V_130 , struct V_1 , V_130 ) ;
if ( strcmp ( V_132 -> V_134 , L_29 ) == 0 )
return F_24 ( V_1 , V_133 , V_123 ) ;
else if ( strcmp ( V_132 -> V_134 , L_27 ) == 0 )
return F_27 ( V_1 , V_133 , V_123 ) ;
return 0 ;
}
int F_33 ( struct V_135 * V_136 )
{
struct V_1 * V_1 = V_136 -> V_137 ;
struct V_138 * V_139 = F_34 ( V_1 -> V_140 ) ;
int V_141 ;
V_141 = F_35 ( & V_1 -> V_130 , & V_142 ,
F_36 ( & V_139 -> V_130 ) ,
L_30 , L_31 ) ;
if ( V_141 ) {
F_20 ( L_32 ,
V_136 -> V_143 ) ;
return V_141 ;
}
F_37 ( & V_1 -> V_130 , V_144 ) ;
return 0 ;
}
void F_38 ( struct V_135 * V_136 )
{
struct V_1 * V_1 = V_136 -> V_137 ;
F_37 ( & V_1 -> V_130 , V_145 ) ;
F_39 ( & V_1 -> V_130 ) ;
F_40 ( & V_1 -> V_130 ) ;
}
