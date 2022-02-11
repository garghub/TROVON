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
struct V_3 * V_4 = V_1 -> V_4 ;
struct V_5 * V_6 = & V_4 -> V_6 ;
int V_20 , V_21 ;
int V_22 , V_23 ;
int V_24 , V_25 , V_26 , V_27 , V_28 ;
V_20 = F_5 ( & V_1 -> V_29 . V_20 ) ;
V_22 = V_1 -> V_29 . V_22 ;
V_23 = F_5 ( & V_1 -> V_29 . V_23 ) ;
V_24 = V_1 -> V_29 . V_24 ;
V_25 = V_1 -> V_29 . V_25 ;
V_26 = F_5 ( & V_1 -> V_29 . V_26 ) ;
V_27 = V_1 -> V_29 . V_27 ;
V_28 = V_1 -> V_29 . V_28 ;
V_21 = V_6 -> V_30 * V_6 -> V_11 ;
return snprintf ( V_2 , V_15 ,
L_2 ,
V_23 ,
V_22 ,
V_26 ,
V_24 ,
V_25 ,
V_28 ,
V_27 ,
V_1 -> V_29 . V_31 ,
V_1 -> V_29 . V_32 ,
V_20 ,
V_21 ,
F_6 ( V_1 -> V_29 . V_33 ) ) ;
}
static T_1 F_7 ( struct V_1 * V_1 , char * V_2 )
{
int V_34 , V_35 ;
F_8 ( V_1 , & V_34 , & V_35 ) ;
return snprintf ( V_2 , V_15 , L_3 ,
V_34 , V_35 ) ;
}
static T_1 F_9 ( struct V_1 * V_1 , char * V_2 )
{
T_1 V_9 ;
V_9 = snprintf ( V_2 , V_15 ,
L_4 ,
F_10 ( & V_1 -> V_36 ) ,
F_10 ( & V_1 -> V_37 ) ,
F_10 ( & V_1 -> V_38 ) ,
F_10 ( & V_1 -> V_39 ) ,
F_10 ( & V_1 -> V_40 ) ,
F_10 ( & V_1 -> V_41 ) ) ;
return V_9 ;
}
static T_1 F_11 ( struct V_1 * V_1 , char * V_2 )
{
return F_12 ( & V_1 -> V_42 , V_2 ) ;
}
static T_1 F_13 ( struct V_1 * V_1 , char * V_2 )
{
struct V_3 * V_4 = V_1 -> V_4 ;
struct V_5 * V_6 = & V_4 -> V_6 ;
T_1 V_9 = 0 ;
V_9 = snprintf ( V_2 , V_15 - V_9 ,
L_5 ,
V_1 -> V_43 ,
V_1 -> V_44 . V_45 , V_6 -> V_44 . V_46 ,
V_1 -> V_44 . V_47 , V_6 -> V_44 . V_48 ,
V_1 -> V_44 . V_49 , V_6 -> V_44 . V_50 ,
V_1 -> V_44 . V_51 , V_6 -> V_44 . V_52 ,
V_1 -> V_44 . V_53 , V_6 -> V_44 . V_54 ,
V_1 -> V_44 . V_55 , V_6 -> V_44 . V_56 ) ;
V_9 += snprintf ( V_2 + V_9 , V_15 - V_9 ,
L_6 ,
V_6 -> V_44 . V_45 , V_6 -> V_44 . V_46 ,
V_6 -> V_44 . V_47 , V_6 -> V_44 . V_48 ,
V_6 -> V_44 . V_49 , V_6 -> V_44 . V_50 ,
V_6 -> V_44 . V_51 , V_6 -> V_44 . V_52 ,
V_6 -> V_44 . V_53 , V_6 -> V_44 . V_54 ,
V_6 -> V_44 . V_57 , V_6 -> V_44 . V_56 ) ;
return V_9 ;
}
static T_1 F_14 ( struct V_1 * V_1 , char * V_2 )
{
struct V_3 * V_4 = V_1 -> V_4 ;
struct V_5 * V_6 = & V_4 -> V_6 ;
struct V_58 * V_59 = & V_1 -> V_59 ;
struct V_60 * V_61 = & V_1 -> V_61 ;
struct V_62 * line ;
T_1 V_9 = 0 ;
int V_63 ;
int V_64 , V_65 ;
int V_66 = 0 , V_67 = 0 ;
int V_68 = 0 , V_69 = 0 ;
int V_70 = 0 , V_71 = 0 , V_72 = 0 , V_73 = 0 , V_74 = 0 ;
int free = 0 , V_75 = 0 , V_76 = 0 ;
int V_77 = 0 , V_78 = 0 , V_79 = 0 , V_80 = 0 , V_81 = 0 ;
int V_82 = 0 , V_83 = 0 ;
F_15 ( & V_61 -> V_84 ) ;
V_64 = ( V_61 -> V_85 ) ? V_61 -> V_85 -> V_86 : - 1 ;
V_65 = ( V_61 -> V_87 ) ? V_61 -> V_87 -> V_86 : - 1 ;
V_63 = V_61 -> V_63 ;
F_16 (line, &l_mg->free_list, list)
V_66 ++ ;
F_17 ( & V_61 -> V_84 ) ;
F_15 ( & V_61 -> V_88 ) ;
F_16 (line, &l_mg->gc_full_list, list) {
if ( line -> type == V_89 )
V_68 ++ ;
else if ( line -> type == V_90 )
V_69 ++ ;
V_67 ++ ;
V_70 ++ ;
}
F_16 (line, &l_mg->gc_high_list, list) {
if ( line -> type == V_89 )
V_68 ++ ;
else if ( line -> type == V_90 )
V_69 ++ ;
V_67 ++ ;
V_71 ++ ;
}
F_16 (line, &l_mg->gc_mid_list, list) {
if ( line -> type == V_89 )
V_68 ++ ;
else if ( line -> type == V_90 )
V_69 ++ ;
V_67 ++ ;
V_72 ++ ;
}
F_16 (line, &l_mg->gc_low_list, list) {
if ( line -> type == V_89 )
V_68 ++ ;
else if ( line -> type == V_90 )
V_69 ++ ;
V_67 ++ ;
V_73 ++ ;
}
F_16 (line, &l_mg->gc_empty_list, list) {
if ( line -> type == V_89 )
V_68 ++ ;
else if ( line -> type == V_90 )
V_69 ++ ;
V_67 ++ ;
V_74 ++ ;
}
F_16 (line, &l_mg->free_list, list)
free ++ ;
F_16 (line, &l_mg->bad_list, list)
V_75 ++ ;
F_16 (line, &l_mg->corrupt_list, list)
V_76 ++ ;
F_17 ( & V_61 -> V_88 ) ;
F_15 ( & V_61 -> V_84 ) ;
if ( V_61 -> V_85 ) {
V_79 = V_61 -> V_85 -> V_79 ;
V_77 = V_61 -> V_85 -> V_91 ;
V_78 = V_61 -> V_85 -> V_92 ;
V_80 = V_61 -> V_85 -> V_80 ;
V_81 = V_61 -> V_85 -> V_81 ;
V_83 = F_18 ( & V_61 -> V_93 ,
V_94 ) ;
V_82 = F_18 ( V_61 -> V_85 -> V_95 ,
V_59 -> V_96 ) ;
}
F_17 ( & V_61 -> V_84 ) ;
if ( V_63 != V_66 )
F_19 ( L_7 ) ;
V_9 = snprintf ( V_2 , V_15 - V_9 ,
L_8 ,
V_6 -> V_11 , V_59 -> V_97 , V_59 -> V_96 ) ;
V_9 += snprintf ( V_2 + V_9 , V_15 - V_9 ,
L_9 ,
V_64 , V_65 ,
free , V_63 , V_75 , V_76 ,
V_67 ,
V_68 , V_69 ,
V_61 -> V_98 ) ;
V_9 += snprintf ( V_2 + V_9 , V_15 - V_9 ,
L_10 ,
V_70 , V_71 , V_72 , V_73 , V_74 ,
F_5 ( & V_1 -> V_99 . V_100 ) ) ;
V_9 += snprintf ( V_2 + V_9 , V_15 - V_9 ,
L_11 ,
V_64 , V_79 , V_77 , V_78 , V_80 , V_81 ,
V_82 , V_59 -> V_96 , V_83 ) ;
return V_9 ;
}
static T_1 F_20 ( struct V_1 * V_1 , char * V_2 )
{
struct V_3 * V_4 = V_1 -> V_4 ;
struct V_5 * V_6 = & V_4 -> V_6 ;
struct V_58 * V_59 = & V_1 -> V_59 ;
T_1 V_9 = 0 ;
V_9 = snprintf ( V_2 , V_15 - V_9 ,
L_12 ,
V_59 -> V_101 , V_59 -> V_102 ) ;
V_9 += snprintf ( V_2 + V_9 , V_15 - V_9 ,
L_13 ,
V_59 -> V_103 , V_59 -> V_104 ,
V_59 -> V_105 ) ;
V_9 += snprintf ( V_2 + V_9 , V_15 - V_9 ,
L_14 ,
V_59 -> V_106 ,
V_59 -> V_107 ,
V_59 -> V_108 ) ;
V_9 += snprintf ( V_2 + V_9 , V_15 - V_9 ,
L_15 ,
V_59 -> V_97 ,
V_59 -> V_96 ,
V_6 -> V_109 ) ;
return V_9 ;
}
static T_1 F_21 ( struct V_1 * V_1 , char * V_2 )
{
return snprintf ( V_2 , V_15 ,
L_16 ,
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
static T_1 F_22 ( struct V_1 * V_1 , const char * V_2 ,
T_2 V_123 )
{
struct V_124 * V_99 = & V_1 -> V_99 ;
T_2 V_125 ;
int V_126 ;
V_125 = strcspn ( V_2 , L_17 ) ;
if ( V_125 >= V_123 )
return - V_127 ;
if ( F_23 ( V_2 , 0 , & V_126 ) )
return - V_127 ;
F_15 ( & V_99 -> V_128 ) ;
F_24 ( & V_1 -> V_29 , V_126 ) ;
F_17 ( & V_99 -> V_128 ) ;
return V_123 ;
}
static T_1 F_25 ( struct V_1 * V_1 , const char * V_2 ,
T_2 V_123 )
{
T_2 V_125 ;
int V_129 ;
V_125 = strcspn ( V_2 , L_17 ) ;
if ( V_125 >= V_123 )
return - V_127 ;
if ( F_23 ( V_2 , 0 , & V_129 ) )
return - V_127 ;
if ( V_129 < 0 || V_129 > 1 )
return - V_127 ;
F_26 ( V_1 , V_129 ) ;
return V_123 ;
}
static T_1 F_27 ( struct V_130 * V_131 , struct V_132 * V_133 ,
char * V_134 )
{
struct V_1 * V_1 = F_28 ( V_131 , struct V_1 , V_131 ) ;
if ( strcmp ( V_133 -> V_135 , L_18 ) == 0 )
return F_4 ( V_1 , V_134 ) ;
else if ( strcmp ( V_133 -> V_135 , L_19 ) == 0 )
return F_1 ( V_1 , V_134 ) ;
else if ( strcmp ( V_133 -> V_135 , L_20 ) == 0 )
return F_7 ( V_1 , V_134 ) ;
else if ( strcmp ( V_133 -> V_135 , L_21 ) == 0 )
return F_9 ( V_1 , V_134 ) ;
else if ( strcmp ( V_133 -> V_135 , L_22 ) == 0 )
return F_11 ( V_1 , V_134 ) ;
else if ( strcmp ( V_133 -> V_135 , L_23 ) == 0 )
return F_13 ( V_1 , V_134 ) ;
else if ( strcmp ( V_133 -> V_135 , L_24 ) == 0 )
return F_14 ( V_1 , V_134 ) ;
else if ( strcmp ( V_133 -> V_135 , L_25 ) == 0 )
return F_20 ( V_1 , V_134 ) ;
#ifdef F_29
else if ( strcmp ( V_133 -> V_135 , L_26 ) == 0 )
return F_21 ( V_1 , V_134 ) ;
#endif
return 0 ;
}
static T_1 F_30 ( struct V_130 * V_131 , struct V_132 * V_133 ,
const char * V_134 , T_2 V_123 )
{
struct V_1 * V_1 = F_28 ( V_131 , struct V_1 , V_131 ) ;
if ( strcmp ( V_133 -> V_135 , L_27 ) == 0 )
return F_22 ( V_1 , V_134 , V_123 ) ;
else if ( strcmp ( V_133 -> V_135 , L_28 ) == 0 )
return F_25 ( V_1 , V_134 , V_123 ) ;
return 0 ;
}
int F_31 ( struct V_136 * V_137 )
{
struct V_1 * V_1 = V_137 -> V_138 ;
struct V_139 * V_140 = F_32 ( V_1 -> V_141 ) ;
int V_142 ;
V_142 = F_33 ( & V_1 -> V_131 , & V_143 ,
F_34 ( & V_140 -> V_131 ) ,
L_29 , L_30 ) ;
if ( V_142 ) {
F_19 ( L_31 ,
V_137 -> V_144 ) ;
return V_142 ;
}
F_35 ( & V_1 -> V_131 , V_145 ) ;
return 0 ;
}
void F_36 ( struct V_136 * V_137 )
{
struct V_1 * V_1 = V_137 -> V_138 ;
F_35 ( & V_1 -> V_131 , V_146 ) ;
F_37 ( & V_1 -> V_131 ) ;
F_38 ( & V_1 -> V_131 ) ;
}
