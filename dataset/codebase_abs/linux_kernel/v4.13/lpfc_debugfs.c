static int
F_1 ( struct V_1 * V_2 , char * V_3 , int V_4 )
{
int V_5 , V_6 , V_7 , V_8 ;
T_1 V_9 ;
struct V_10 * V_11 ;
char * V_12 ;
V_12 = F_2 ( V_13 , V_14 ) ;
if ( ! V_12 )
return 0 ;
V_8 = V_15 ;
V_15 = 0 ;
V_7 = 0 ;
V_6 = ( F_3 ( & V_2 -> V_16 ) + 1 ) &
( V_17 - 1 ) ;
for ( V_5 = V_6 ; V_5 < V_17 ; V_5 ++ ) {
V_11 = V_2 -> V_18 + V_5 ;
if ( ! V_11 -> V_19 )
continue;
V_9 = F_4 ( V_11 -> V_20 - V_21 ) ;
snprintf ( V_12 ,
V_13 , L_1 ,
V_11 -> V_22 , V_9 , V_11 -> V_19 ) ;
V_7 += snprintf ( V_3 + V_7 , V_4 - V_7 , V_12 ,
V_11 -> V_23 , V_11 -> V_24 , V_11 -> V_25 ) ;
}
for ( V_5 = 0 ; V_5 < V_6 ; V_5 ++ ) {
V_11 = V_2 -> V_18 + V_5 ;
if ( ! V_11 -> V_19 )
continue;
V_9 = F_4 ( V_11 -> V_20 - V_21 ) ;
snprintf ( V_12 ,
V_13 , L_1 ,
V_11 -> V_22 , V_9 , V_11 -> V_19 ) ;
V_7 += snprintf ( V_3 + V_7 , V_4 - V_7 , V_12 ,
V_11 -> V_23 , V_11 -> V_24 , V_11 -> V_25 ) ;
}
V_15 = V_8 ;
F_5 ( V_12 ) ;
return V_7 ;
}
static int
F_6 ( struct V_26 * V_27 , char * V_3 , int V_4 )
{
int V_5 , V_6 , V_7 , V_8 ;
T_1 V_9 ;
struct V_10 * V_11 ;
char * V_12 ;
V_12 = F_2 ( V_13 , V_14 ) ;
if ( ! V_12 )
return 0 ;
V_8 = V_15 ;
V_15 = 0 ;
V_7 = 0 ;
V_6 = ( F_3 ( & V_27 -> V_28 ) + 1 ) &
( V_29 - 1 ) ;
for ( V_5 = V_6 ; V_5 < V_29 ; V_5 ++ ) {
V_11 = V_27 -> V_30 + V_5 ;
if ( ! V_11 -> V_19 )
continue;
V_9 = F_4 ( V_11 -> V_20 - V_21 ) ;
snprintf ( V_12 ,
V_13 , L_1 ,
V_11 -> V_22 , V_9 , V_11 -> V_19 ) ;
V_7 += snprintf ( V_3 + V_7 , V_4 - V_7 , V_12 ,
V_11 -> V_23 , V_11 -> V_24 , V_11 -> V_25 ) ;
}
for ( V_5 = 0 ; V_5 < V_6 ; V_5 ++ ) {
V_11 = V_27 -> V_30 + V_5 ;
if ( ! V_11 -> V_19 )
continue;
V_9 = F_4 ( V_11 -> V_20 - V_21 ) ;
snprintf ( V_12 ,
V_13 , L_1 ,
V_11 -> V_22 , V_9 , V_11 -> V_19 ) ;
V_7 += snprintf ( V_3 + V_7 , V_4 - V_7 , V_12 ,
V_11 -> V_23 , V_11 -> V_24 , V_11 -> V_25 ) ;
}
V_15 = V_8 ;
F_5 ( V_12 ) ;
return V_7 ;
}
static int
F_7 ( struct V_26 * V_27 , char * V_3 , int V_4 )
{
int V_7 = 0 ;
int V_5 , V_31 , V_32 , V_33 , V_34 ;
T_1 V_35 , V_36 , V_37 ;
struct V_38 * V_39 ;
struct V_40 * V_41 ;
struct V_42 * V_43 ;
struct V_44 * V_45 ;
struct V_46 * V_47 ;
if ( V_27 -> V_48 != 3 )
return 0 ;
F_8 ( & V_27 -> V_49 ) ;
V_5 = F_9 () ;
if ( V_5 > 1 ) {
V_50 ++ ;
if ( V_50 >= V_5 )
V_50 = 0 ;
}
else
V_50 = 0 ;
V_5 = V_50 ;
V_7 += snprintf ( V_3 + V_7 , V_4 - V_7 , L_2 , V_5 ) ;
V_41 = & V_27 -> V_41 [ V_5 ] ;
V_33 = 0 ;
F_10 (d_buf, &hbqs->hbq_buffer_list, list)
V_33 ++ ;
V_39 = V_51 [ V_5 ] ;
V_7 += snprintf ( V_3 + V_7 , V_4 - V_7 ,
L_3 ,
V_39 -> V_52 , V_39 -> V_53 , V_39 -> V_54 ,
V_39 -> V_55 , V_39 -> V_56 , V_39 -> V_57 , V_33 ) ;
V_36 = V_27 -> V_58 [ V_5 ] ;
V_37 = F_11 ( V_36 ) ;
V_7 += snprintf ( V_3 + V_7 , V_4 - V_7 ,
L_4 ,
V_41 -> V_59 , V_41 -> V_55 , V_41 -> V_60 ,
V_41 -> V_61 , V_41 -> V_62 , V_37 ) ;
V_43 = (struct V_42 * ) V_27 -> V_41 [ V_5 ] . V_63 ;
for ( V_31 = 0 ; V_31 < V_41 -> V_59 ; V_31 ++ ) {
V_7 += snprintf ( V_3 + V_7 , V_4 - V_7 ,
L_5 , V_31 ,
F_11 ( V_43 -> V_64 . V_65 ) ,
F_11 ( V_43 -> V_64 . V_66 . V_67 ) ,
F_11 ( V_43 -> V_68 ) ) ;
V_5 = 0 ;
V_32 = 0 ;
V_34 = V_41 -> V_60 - V_33 ;
if ( V_34 >= 0 ) {
if ( ( V_31 >= V_41 -> V_60 ) || ( V_31 < V_34 ) ) {
V_7 += snprintf ( V_3 + V_7 , V_4 - V_7 , L_6 ) ;
goto V_69;
}
}
else {
if ( ( V_31 >= V_41 -> V_60 ) &&
( V_31 < ( V_41 -> V_59 + V_34 ) ) ) {
V_7 += snprintf ( V_3 + V_7 , V_4 - V_7 , L_6 ) ;
goto V_69;
}
}
F_10 (d_buf, &hbqs->hbq_buffer_list, list) {
V_47 = F_12 ( V_45 , struct V_46 , V_70 ) ;
V_35 = ( ( V_71 ) V_47 -> V_70 . V_35 & 0xffffffff ) ;
if ( V_35 == F_11 ( V_43 -> V_64 . V_65 ) ) {
V_7 += snprintf ( V_3 + V_7 , V_4 - V_7 ,
L_7 , V_5 ,
V_47 -> V_70 . V_72 , V_47 -> V_73 ) ;
V_32 = 1 ;
break;
}
V_5 ++ ;
}
if ( ! V_32 ) {
V_7 += snprintf ( V_3 + V_7 , V_4 - V_7 , L_8 ) ;
}
V_69:
V_43 ++ ;
if ( V_7 > V_74 - 54 )
break;
}
F_13 ( & V_27 -> V_49 ) ;
return V_7 ;
}
static int
F_14 ( struct V_26 * V_27 , char * V_3 , int V_4 )
{
int V_7 = 0 ;
int V_5 , V_75 ;
T_1 * V_76 ;
char * V_12 ;
V_12 = F_2 ( 1024 , V_14 ) ;
if ( ! V_12 )
return 0 ;
V_75 = 0 ;
F_8 ( & V_27 -> V_49 ) ;
V_7 += snprintf ( V_3 + V_7 , V_4 - V_7 , L_9 ) ;
F_15 ( V_12 ,
V_27 -> V_77 + V_78 , 1024 ) ;
V_76 = ( T_1 * ) & V_12 [ 0 ] ;
V_75 = V_78 ;
V_78 += 1024 ;
if ( V_78 >= 4096 )
V_78 = 0 ;
V_5 = 1024 ;
while ( V_5 > 0 ) {
V_7 += snprintf ( V_3 + V_7 , V_4 - V_7 ,
L_10 ,
V_75 , * V_76 , * ( V_76 + 1 ) , * ( V_76 + 2 ) , * ( V_76 + 3 ) , * ( V_76 + 4 ) ,
* ( V_76 + 5 ) , * ( V_76 + 6 ) , * ( V_76 + 7 ) ) ;
V_76 += 8 ;
V_5 -= ( 8 * sizeof( T_1 ) ) ;
V_75 += ( 8 * sizeof( T_1 ) ) ;
}
F_13 ( & V_27 -> V_49 ) ;
F_5 ( V_12 ) ;
return V_7 ;
}
static int
F_16 ( struct V_26 * V_27 , char * V_3 , int V_4 )
{
int V_7 = 0 ;
int V_5 , V_75 ;
T_1 V_79 , V_80 , V_81 , V_82 ;
T_1 * V_76 ;
struct V_83 * V_84 ;
struct V_85 * V_86 = & V_27 -> V_87 ;
struct V_88 * V_89 ;
V_75 = 0 ;
F_8 ( & V_27 -> V_49 ) ;
V_7 += snprintf ( V_3 + V_7 , V_4 - V_7 , L_11 ) ;
V_76 = ( T_1 * ) V_27 -> V_90 . V_72 ;
V_5 = sizeof( V_91 ) ;
while ( V_5 > 0 ) {
V_7 += snprintf ( V_3 + V_7 , V_4 - V_7 ,
L_10 ,
V_75 , * V_76 , * ( V_76 + 1 ) , * ( V_76 + 2 ) , * ( V_76 + 3 ) , * ( V_76 + 4 ) ,
* ( V_76 + 5 ) , * ( V_76 + 6 ) , * ( V_76 + 7 ) ) ;
V_76 += 8 ;
V_5 -= ( 8 * sizeof( T_1 ) ) ;
V_75 += ( 8 * sizeof( T_1 ) ) ;
}
V_7 += snprintf ( V_3 + V_7 , V_4 - V_7 , L_12 ) ;
V_76 = ( T_1 * ) V_27 -> V_92 ;
V_5 = sizeof( V_93 ) ;
while ( V_5 > 0 ) {
V_7 += snprintf ( V_3 + V_7 , V_4 - V_7 ,
L_10 ,
V_75 , * V_76 , * ( V_76 + 1 ) , * ( V_76 + 2 ) , * ( V_76 + 3 ) , * ( V_76 + 4 ) ,
* ( V_76 + 5 ) , * ( V_76 + 6 ) , * ( V_76 + 7 ) ) ;
V_76 += 8 ;
V_5 -= ( 8 * sizeof( T_1 ) ) ;
V_75 += ( 8 * sizeof( T_1 ) ) ;
}
if ( V_27 -> V_48 <= V_94 ) {
for ( V_5 = 0 ; V_5 < 4 ; V_5 ++ ) {
V_84 = & V_27 -> V_95 [ V_5 ] ;
V_89 = & V_86 -> V_96 [ V_5 ] ;
V_7 += snprintf ( V_3 + V_7 , V_4 - V_7 ,
L_13
L_14
L_15
L_16 ,
V_5 , V_84 -> V_97 ,
V_89 -> V_87 . V_98 . V_99 ,
V_89 -> V_87 . V_98 . V_100 ,
V_89 -> V_87 . V_98 . V_101 ,
V_89 -> V_102 , V_84 -> V_103 ,
V_89 -> V_87 . V_98 . V_104 ) ;
}
V_79 = F_17 ( V_27 -> V_105 ) ;
V_80 = F_17 ( V_27 -> V_106 ) ;
V_81 = F_17 ( V_27 -> V_107 ) ;
V_82 = F_17 ( V_27 -> V_108 ) ;
V_7 += snprintf ( V_3 + V_7 , V_4 - V_7 , L_17
L_18 , V_79 , V_80 , V_81 , V_82 ) ;
}
F_13 ( & V_27 -> V_49 ) ;
return V_7 ;
}
static int
F_18 ( struct V_1 * V_2 , char * V_3 , int V_4 )
{
int V_7 = 0 ;
int V_109 ;
struct V_110 * V_111 = F_19 ( V_2 ) ;
struct V_26 * V_27 = V_2 -> V_27 ;
struct V_112 * V_113 ;
unsigned char * V_114 ;
struct V_115 * V_116 ;
struct V_117 * V_118 ;
struct V_119 * V_120 ;
V_109 = ( V_121 / V_122 ) ;
V_7 += snprintf ( V_3 + V_7 , V_4 - V_7 , L_19 ) ;
F_8 ( V_111 -> V_123 ) ;
F_10 (ndlp, &vport->fc_nodes, nlp_listp) {
if ( ! V_109 ) {
V_7 += snprintf ( V_3 + V_7 , V_4 - V_7 ,
L_20 ) ;
break;
}
V_109 -- ;
switch ( V_113 -> V_124 ) {
case V_125 :
V_114 = L_21 ;
break;
case V_126 :
V_114 = L_22 ;
break;
case V_127 :
V_114 = L_23 ;
break;
case V_128 :
V_114 = L_24 ;
break;
case V_129 :
V_114 = L_25 ;
break;
case V_130 :
V_114 = L_26 ;
break;
case V_131 :
V_114 = L_27 ;
break;
case V_132 :
V_114 = L_28 ;
break;
case V_133 :
V_114 = L_29 ;
break;
default:
V_114 = L_30 ;
}
V_7 += snprintf ( V_3 + V_7 , V_4 - V_7 , L_31 ,
V_114 , V_113 -> V_134 ) ;
V_7 += snprintf ( V_3 + V_7 , V_4 - V_7 ,
L_32 ,
F_20 ( V_113 -> V_135 . V_136 . V_137 ) ) ;
V_7 += snprintf ( V_3 + V_7 , V_4 - V_7 ,
L_33 ,
F_20 ( V_113 -> V_138 . V_136 . V_137 ) ) ;
if ( V_113 -> V_139 & V_140 )
V_7 += snprintf ( V_3 + V_7 , V_4 - V_7 , L_34 ,
V_113 -> V_141 ) ;
else
V_7 += snprintf ( V_3 + V_7 , V_4 - V_7 , L_35 ) ;
V_7 += snprintf ( V_3 + V_7 , V_4 - V_7 , L_36 ,
V_113 -> V_139 ) ;
if ( ! V_113 -> V_142 )
V_7 += snprintf ( V_3 + V_7 , V_4 - V_7 , L_37 ) ;
if ( V_113 -> V_142 & V_143 )
V_7 += snprintf ( V_3 + V_7 , V_4 - V_7 , L_38 ) ;
if ( V_113 -> V_142 & V_144 )
V_7 += snprintf ( V_3 + V_7 , V_4 - V_7 , L_39 ) ;
if ( V_113 -> V_142 & V_145 )
V_7 += snprintf ( V_3 + V_7 , V_4 - V_7 , L_40 ,
V_113 -> V_146 ) ;
if ( V_113 -> V_142 & V_147 )
V_7 += snprintf ( V_3 + V_7 , V_4 - V_7 , L_41 ) ;
if ( V_113 -> V_142 & V_148 )
V_7 += snprintf ( V_3 + V_7 ,
V_4 - V_7 , L_42 ,
V_149 ) ;
if ( V_113 -> V_142 & V_150 )
V_7 += snprintf ( V_3 + V_7 ,
V_4 - V_7 , L_43 ) ;
V_7 += snprintf ( V_3 + V_7 , V_4 - V_7 , L_44 ,
V_113 -> V_151 ) ;
V_7 += snprintf ( V_3 + V_7 , V_4 - V_7 , L_45 ,
F_21 ( & V_113 -> V_152 ) ) ;
V_7 += snprintf ( V_3 + V_7 , V_4 - V_7 , L_46 ) ;
}
F_13 ( V_111 -> V_123 ) ;
if ( V_27 -> V_153 && V_27 -> V_154 && ( V_2 == V_27 -> V_155 ) ) {
V_118 = (struct V_117 * ) V_27 -> V_154 -> V_156 ;
V_7 += snprintf ( V_3 + V_7 , V_4 - V_7 ,
L_47 ) ;
if ( V_27 -> V_154 -> V_157 )
V_114 = L_48 ;
else
V_114 = L_49 ;
V_7 += snprintf ( V_3 + V_7 , V_4 - V_7 ,
L_50 ,
F_20 ( V_2 -> V_158 . V_136 . V_137 ) ,
F_20 ( V_2 -> V_159 . V_136 . V_137 ) ,
V_114 ) ;
V_7 += snprintf ( V_3 + V_7 , V_4 - V_7 ,
L_51 ,
V_27 -> V_154 -> V_157 ) ;
goto V_160;
}
V_7 += snprintf ( V_3 + V_7 , V_4 - V_7 ,
L_52 ) ;
V_116 = V_2 -> V_116 ;
if ( ! V_116 )
goto V_160;
F_8 ( V_111 -> V_123 ) ;
if ( V_116 -> V_157 )
V_114 = L_53 ;
else
V_114 = L_54 ;
V_7 += snprintf ( V_3 + V_7 , V_4 - V_7 ,
L_55 ,
V_116 -> V_157 , V_114 ) ;
V_7 += snprintf ( V_3 + V_7 , V_4 - V_7 , L_56 ) ;
F_10 (ndlp, &vport->fc_nodes, nlp_listp) {
if ( ! V_113 -> V_120 )
continue;
V_120 = V_113 -> V_120 -> V_161 ;
switch ( V_120 -> V_162 ) {
case V_163 :
V_114 = L_53 ;
break;
case V_164 :
V_114 = L_54 ;
break;
default:
V_114 = L_57 ;
break;
}
V_7 += snprintf ( V_3 + V_7 , V_4 - V_7 ,
L_58 ,
V_114 , V_120 -> V_157 ) ;
V_7 += snprintf ( V_3 + V_7 , V_4 - V_7 , L_32 ,
V_120 -> V_165 ) ;
V_7 += snprintf ( V_3 + V_7 , V_4 - V_7 , L_33 ,
V_120 -> V_166 ) ;
if ( V_120 -> V_167 & V_168 )
V_7 += snprintf ( V_3 + V_7 , V_4 - V_7 ,
L_59 ) ;
if ( V_120 -> V_167 & V_169 )
V_7 += snprintf ( V_3 + V_7 , V_4 - V_7 ,
L_60 ) ;
if ( V_120 -> V_167 & V_170 )
V_7 += snprintf ( V_3 + V_7 , V_4 - V_7 ,
L_61 ) ;
if ( V_120 -> V_167 & ~ ( V_168 |
V_169 |
V_170 ) )
V_7 += snprintf ( V_3 + V_7 , V_4 - V_7 ,
L_62 ,
V_120 -> V_167 ) ;
V_7 += snprintf ( V_3 + V_7 , V_4 - V_7 , L_46 ) ;
}
F_13 ( V_111 -> V_123 ) ;
V_160:
return V_7 ;
}
static int
F_22 ( struct V_1 * V_2 , char * V_3 , int V_4 )
{
struct V_26 * V_27 = V_2 -> V_27 ;
struct V_117 * V_118 ;
struct V_171 * V_172 , * V_173 ;
V_71 V_174 , V_23 , V_24 , V_25 ;
int V_7 = 0 ;
int V_109 ;
if ( V_27 -> V_153 ) {
if ( ! V_27 -> V_154 )
return V_7 ;
V_118 = (struct V_117 * ) V_27 -> V_154 -> V_156 ;
V_7 += snprintf ( V_3 + V_7 , V_4 - V_7 ,
L_63 ) ;
V_7 += snprintf ( V_3 + V_7 , V_4 - V_7 ,
L_64 ,
F_3 ( & V_118 -> V_175 ) ,
F_3 ( & V_118 -> V_176 ) ,
F_3 ( & V_118 -> V_177 ) ) ;
if ( F_3 ( & V_118 -> V_175 ) !=
F_3 ( & V_118 -> V_178 ) ) {
V_7 += snprintf ( V_3 + V_7 , V_4 - V_7 ,
L_65 ,
F_3 ( & V_118 -> V_175 ) ,
F_3 ( & V_118 -> V_178 ) ) ;
}
V_7 += snprintf ( V_3 + V_7 , V_4 - V_7 ,
L_66 ,
F_3 ( & V_118 -> V_179 ) ,
F_3 ( & V_118 -> V_180 ) ,
F_3 ( & V_118 -> V_181 ) ,
F_3 ( & V_118 -> V_182 ) ) ;
V_7 += snprintf ( V_3 + V_7 , V_4 - V_7 ,
L_67
L_68 ,
F_3 ( & V_118 -> V_183 ) ,
F_3 ( & V_118 -> V_184 ) ,
F_3 ( & V_118 -> V_185 ) ,
F_3 ( & V_118 -> V_186 ) ) ;
if ( F_3 ( & V_118 -> V_183 ) !=
F_3 ( & V_118 -> V_187 ) ) {
V_7 += snprintf ( V_3 + V_7 , V_4 - V_7 ,
L_69 ,
F_3 ( & V_118 -> V_183 ) ,
F_3 ( & V_118 -> V_187 ) ) ;
}
V_7 += snprintf ( V_3 + V_7 , V_4 - V_7 ,
L_70
L_71 ,
F_3 ( & V_118 -> V_188 ) ,
F_3 ( & V_118 -> V_189 ) ,
F_3 ( & V_118 -> V_190 ) ,
F_3 ( & V_118 -> V_191 ) ) ;
V_7 += snprintf ( V_3 + V_7 , V_4 - V_7 ,
L_72 ,
F_3 ( & V_118 -> V_192 ) ,
F_3 ( & V_118 -> V_193 ) ,
F_3 ( & V_118 -> V_194 ) ) ;
V_7 += snprintf ( V_3 + V_7 , V_4 - V_7 ,
L_73 ,
F_3 ( & V_118 -> V_195 ) ,
F_3 ( & V_118 -> V_196 ) ) ;
V_7 += snprintf ( V_3 + V_7 , V_4 - V_7 ,
L_74 ,
F_3 ( & V_118 -> V_197 ) ,
F_3 ( & V_118 -> V_198 ) ,
F_3 ( & V_118 -> V_199 ) ,
F_3 ( & V_118 -> V_200 ) ) ;
V_7 += snprintf ( V_3 + V_7 , V_4 - V_7 , L_46 ) ;
V_109 = 0 ;
F_23 ( & V_27 -> V_201 . V_202 ) ;
F_24 (ctxp, next_ctxp,
&phba->sli4_hba.lpfc_abts_nvmet_ctx_list,
list) {
V_109 ++ ;
}
F_25 ( & V_27 -> V_201 . V_202 ) ;
if ( V_109 ) {
V_7 += snprintf ( V_3 + V_7 , V_4 - V_7 ,
L_75 , V_109 ) ;
F_23 ( & V_27 -> V_201 . V_202 ) ;
F_24 (ctxp, next_ctxp,
&phba->sli4_hba.lpfc_abts_nvmet_ctx_list,
list) {
if ( V_7 >= ( V_4 - V_203 ) )
break;
V_7 += snprintf ( V_3 + V_7 , V_4 - V_7 ,
L_76
L_77 ,
V_172 -> V_204 , V_172 -> V_205 ,
V_172 -> V_102 ) ;
}
F_25 ( & V_27 -> V_201 . V_202 ) ;
}
F_23 ( & V_27 -> V_201 . V_206 ) ;
F_23 ( & V_27 -> V_201 . V_207 ) ;
V_174 = V_27 -> V_201 . V_208 -
( V_27 -> V_201 . V_209 +
V_27 -> V_201 . V_210 ) ;
F_25 ( & V_27 -> V_201 . V_207 ) ;
F_25 ( & V_27 -> V_201 . V_206 ) ;
V_7 += snprintf ( V_3 + V_7 , V_4 - V_7 ,
L_78
L_79 ,
V_27 -> V_201 . V_208 ,
V_27 -> V_201 . V_211 ,
V_27 -> V_201 . V_212 ,
V_174 ) ;
} else {
if ( ! ( V_27 -> V_213 & V_214 ) )
return V_7 ;
V_7 += snprintf ( V_3 + V_7 , V_4 - V_7 ,
L_80 ) ;
V_7 += snprintf ( V_3 + V_7 , V_4 - V_7 ,
L_81 ,
F_3 ( & V_27 -> V_215 ) ,
F_3 ( & V_27 -> V_216 ) ) ;
V_174 = F_3 ( & V_27 -> V_217 ) ;
V_23 = F_3 ( & V_27 -> V_218 ) ;
V_24 = F_3 ( & V_27 -> V_219 ) ;
V_25 = F_3 ( & V_27 -> V_220 ) ;
V_7 += snprintf ( V_3 + V_7 , V_4 - V_7 ,
L_82 ,
V_23 , V_24 , V_25 ) ;
V_7 += snprintf ( V_3 + V_7 , V_4 - V_7 ,
L_83 ,
V_174 , ( V_23 + V_24 + V_25 ) - V_174 ) ;
}
return V_7 ;
}
static int
F_26 ( struct V_1 * V_2 , char * V_3 , int V_4 )
{
struct V_26 * V_27 = V_2 -> V_27 ;
int V_7 = 0 ;
if ( V_27 -> V_153 == 0 ) {
V_7 += snprintf ( V_3 + V_7 , V_221 - V_7 ,
L_84 ,
( V_27 -> V_222 ? L_85 : L_86 ) ,
V_27 -> V_223 ) ;
if ( V_27 -> V_223 == 0 )
return V_7 ;
V_7 += snprintf (
V_3 + V_7 , V_221 - V_7 ,
L_87
L_88 ) ;
V_7 += snprintf (
V_3 + V_7 , V_221 - V_7 ,
L_89 ,
F_27 ( V_27 -> V_224 ,
V_27 -> V_223 ) ,
V_27 -> V_225 ,
V_27 -> V_226 ) ;
V_7 += snprintf (
V_3 + V_7 , V_221 - V_7 ,
L_90
L_91 ) ;
V_7 += snprintf (
V_3 + V_7 , V_221 - V_7 ,
L_89 ,
F_27 ( V_27 -> V_227 ,
V_27 -> V_223 ) ,
V_27 -> V_228 ,
V_27 -> V_229 ) ;
V_7 += snprintf (
V_3 + V_7 , V_221 - V_7 ,
L_92
L_93 ) ;
V_7 += snprintf (
V_3 + V_7 , V_221 - V_7 ,
L_89 ,
F_27 ( V_27 -> V_230 ,
V_27 -> V_223 ) ,
V_27 -> V_231 ,
V_27 -> V_232 ) ;
V_7 += snprintf (
V_3 + V_7 , V_221 - V_7 ,
L_94
L_95 ) ;
V_7 += snprintf (
V_3 + V_7 , V_221 - V_7 ,
L_89 ,
F_27 ( V_27 -> V_233 ,
V_27 -> V_223 ) ,
V_27 -> V_234 ,
V_27 -> V_235 ) ;
V_7 += snprintf (
V_3 + V_7 , V_221 - V_7 ,
L_96 ,
F_27 ( V_27 -> V_224 +
V_27 -> V_227 +
V_27 -> V_230 +
V_27 -> V_233 ,
V_27 -> V_223 ) ) ;
return V_7 ;
}
V_7 += snprintf ( V_3 + V_7 , V_221 - V_7 ,
L_97 ,
( V_27 -> V_222 ? L_85 : L_86 ) ,
V_27 -> V_223 ,
V_27 -> V_236 ) ;
if ( V_27 -> V_223 == 0 )
return V_7 ;
V_7 += snprintf ( V_3 + V_7 , V_221 - V_7 ,
L_98
L_99 ) ;
V_7 += snprintf ( V_3 + V_7 , V_221 - V_7 ,
L_89 ,
F_27 ( V_27 -> V_224 ,
V_27 -> V_223 ) ,
V_27 -> V_225 ,
V_27 -> V_226 ) ;
V_7 += snprintf ( V_3 + V_7 , V_221 - V_7 ,
L_100
L_101 ) ;
V_7 += snprintf ( V_3 + V_7 , V_221 - V_7 ,
L_89 ,
F_27 ( V_27 -> V_227 ,
V_27 -> V_223 ) ,
V_27 -> V_228 ,
V_27 -> V_229 ) ;
V_7 += snprintf ( V_3 + V_7 , V_221 - V_7 ,
L_102
L_103 ) ;
V_7 += snprintf ( V_3 + V_7 , V_221 - V_7 ,
L_89 ,
F_27 ( V_27 -> V_230 ,
V_27 -> V_223 ) ,
V_27 -> V_231 ,
V_27 -> V_232 ) ;
V_7 += snprintf ( V_3 + V_7 , V_221 - V_7 ,
L_104
L_105 ) ;
V_7 += snprintf ( V_3 + V_7 , V_221 - V_7 ,
L_89 ,
F_27 ( V_27 -> V_233 ,
V_27 -> V_223 ) ,
V_27 -> V_234 ,
V_27 -> V_235 ) ;
V_7 += snprintf ( V_3 + V_7 , V_221 - V_7 ,
L_106
L_107 ) ;
V_7 += snprintf ( V_3 + V_7 , V_221 - V_7 ,
L_89 ,
F_27 ( V_27 -> V_237 ,
V_27 -> V_223 ) ,
V_27 -> V_238 ,
V_27 -> V_239 ) ;
if ( V_27 -> V_236 == 0 ) {
V_7 += snprintf ( V_3 + V_7 , V_221 - V_7 ,
L_108
L_109 ) ;
V_7 += snprintf ( V_3 + V_7 , V_221 - V_7 ,
L_110
L_111 ,
F_27 ( V_27 -> V_240 ,
V_27 -> V_223 ) ,
V_27 -> V_241 ,
V_27 -> V_242 ) ;
return V_7 ;
}
V_7 += snprintf ( V_3 + V_7 , V_221 - V_7 ,
L_112
L_113 ) ;
V_7 += snprintf ( V_3 + V_7 , V_221 - V_7 ,
L_89 ,
F_27 ( V_27 -> V_243 ,
V_27 -> V_236 ) ,
V_27 -> V_244 ,
V_27 -> V_245 ) ;
V_7 += snprintf ( V_3 + V_7 , V_221 - V_7 ,
L_114
L_115 ) ;
V_7 += snprintf ( V_3 + V_7 , V_221 - V_7 ,
L_89 ,
F_27 ( V_27 -> V_246 ,
V_27 -> V_236 ) ,
V_27 -> V_247 ,
V_27 -> V_248 ) ;
V_7 += snprintf ( V_3 + V_7 , V_221 - V_7 ,
L_116
L_117 ) ;
V_7 += snprintf ( V_3 + V_7 , V_221 - V_7 ,
L_89 ,
F_27 ( V_27 -> V_249 ,
V_27 -> V_236 ) ,
V_27 -> V_250 ,
V_27 -> V_251 ) ;
V_7 += snprintf ( V_3 + V_7 , V_221 - V_7 ,
L_118
L_119 ) ;
V_7 += snprintf ( V_3 + V_7 , V_221 - V_7 ,
L_89 ,
F_27 ( V_27 -> V_252 ,
V_27 -> V_236 ) ,
V_27 -> V_253 ,
V_27 -> V_254 ) ;
V_7 += snprintf ( V_3 + V_7 , V_221 - V_7 ,
L_120
L_121 ) ;
V_7 += snprintf ( V_3 + V_7 , V_221 - V_7 ,
L_89 ,
F_27 ( V_27 -> V_240 ,
V_27 -> V_236 ) ,
V_27 -> V_241 ,
V_27 -> V_242 ) ;
return V_7 ;
}
static int
F_28 ( struct V_26 * V_27 , char * V_3 , int V_4 )
{
struct V_255 * V_11 ;
int V_5 , V_205 , V_6 , V_256 ;
int V_7 = 0 ;
V_205 = V_27 -> V_257 ;
V_6 = ( F_3 ( & V_27 -> V_258 ) + 1 ) &
( V_27 -> V_259 - 1 ) ;
V_256 = V_27 -> V_260 ;
V_7 += snprintf ( V_3 + V_7 , V_4 - V_7 ,
L_122 ,
( V_27 -> V_153 ? L_123 : L_124 ) ,
( V_205 ? L_85 : L_86 ) ,
V_6 , V_256 , V_27 -> V_259 ) ;
if ( ! V_27 -> V_261 || V_205 )
return V_7 ;
for ( V_5 = V_6 ; V_5 < V_27 -> V_259 ; V_5 ++ ) {
if ( V_256 ) {
V_256 -- ;
continue;
}
V_11 = V_27 -> V_261 + V_5 ;
V_27 -> V_260 ++ ;
if ( ! V_11 -> V_19 )
continue;
V_7 += snprintf ( V_3 + V_7 , V_4 - V_7 , V_11 -> V_19 ,
V_11 -> V_23 , V_11 -> V_24 , V_11 -> V_25 ) ;
if ( V_27 -> V_260 >= V_27 -> V_259 ) {
V_27 -> V_260 = 0 ;
V_7 += snprintf ( V_3 + V_7 , V_4 - V_7 ,
L_125 ) ;
goto V_262;
}
if ( V_7 >= ( V_4 - V_203 ) ) {
V_7 += snprintf ( V_3 + V_7 , V_4 - V_7 ,
L_126 ,
V_27 -> V_260 ,
V_27 -> V_259 ) ;
goto V_262;
}
}
for ( V_5 = 0 ; V_5 < V_6 ; V_5 ++ ) {
if ( V_256 ) {
V_256 -- ;
continue;
}
V_11 = V_27 -> V_261 + V_5 ;
V_27 -> V_260 ++ ;
if ( ! V_11 -> V_19 )
continue;
V_7 += snprintf ( V_3 + V_7 , V_4 - V_7 , V_11 -> V_19 ,
V_11 -> V_23 , V_11 -> V_24 , V_11 -> V_25 ) ;
if ( V_27 -> V_260 >= V_27 -> V_259 ) {
V_27 -> V_260 = 0 ;
V_7 += snprintf ( V_3 + V_7 , V_4 - V_7 ,
L_125 ) ;
goto V_262;
}
if ( V_7 >= ( V_4 - V_203 ) ) {
V_7 += snprintf ( V_3 + V_7 , V_4 - V_7 ,
L_126 ,
V_27 -> V_260 ,
V_27 -> V_259 ) ;
goto V_262;
}
}
V_7 += snprintf ( V_3 + V_7 , V_4 - V_7 ,
L_127 ) ;
V_262:
return V_7 ;
}
static int
F_29 ( struct V_1 * V_2 , char * V_3 , int V_4 )
{
struct V_26 * V_27 = V_2 -> V_27 ;
int V_5 ;
int V_7 = 0 ;
T_1 V_263 = 0 ;
T_1 V_264 = 0 ;
T_1 V_265 = 0 ;
T_1 V_266 = 0 ;
if ( V_27 -> V_153 == 0 ) {
V_7 += snprintf ( V_3 + V_7 , V_221 - V_7 ,
L_128 ,
( V_27 -> V_267 & V_268 ?
L_85 : L_86 ) ) ;
for ( V_5 = 0 ; V_5 < V_27 -> V_201 . V_269 ; V_5 ++ ) {
if ( V_5 >= V_270 )
break;
V_7 += snprintf ( V_3 + V_7 , V_221 - V_7 ,
L_129 ,
V_5 , V_27 -> V_271 [ V_5 ] ,
V_27 -> V_272 [ V_5 ] ) ;
V_263 += V_27 -> V_271 [ V_5 ] ;
V_265 += V_27 -> V_272 [ V_5 ] ;
}
V_7 += snprintf ( V_3 + V_7 , V_221 - V_7 ,
L_130 ,
V_263 , V_265 ) ;
return V_7 ;
}
V_7 += snprintf ( V_3 + V_7 , V_221 - V_7 ,
L_131 ,
( V_27 -> V_267 & V_273 ?
L_132 : L_133 ) ) ;
V_7 += snprintf ( V_3 + V_7 , V_221 - V_7 ,
L_134 ,
( V_27 -> V_267 & V_274 ?
L_135 : L_136 ) ) ;
for ( V_5 = 0 ; V_5 < V_27 -> V_201 . V_269 ; V_5 ++ ) {
if ( V_5 >= V_270 )
break;
V_7 += snprintf ( V_3 + V_7 , V_221 - V_7 ,
L_137
L_138 ,
V_5 , V_27 -> V_271 [ V_5 ] ,
V_27 -> V_275 [ V_5 ] ,
V_27 -> V_272 [ V_5 ] ,
V_27 -> V_276 [ V_5 ] ) ;
V_263 += V_27 -> V_271 [ V_5 ] ;
V_264 += V_27 -> V_276 [ V_5 ] ;
V_265 += V_27 -> V_272 [ V_5 ] ;
V_266 += V_27 -> V_275 [ V_5 ] ;
}
V_7 += snprintf ( V_3 + V_7 , V_221 - V_7 ,
L_139 ,
V_263 , V_266 , V_265 , V_264 ) ;
return V_7 ;
}
inline void
F_30 ( struct V_1 * V_2 , int V_277 , char * V_19 ,
T_1 V_23 , T_1 V_24 , T_1 V_25 )
{
#ifdef F_31
struct V_10 * V_11 ;
int V_6 ;
if ( ! ( V_278 & V_277 ) )
return;
if ( ! V_15 || ! V_17 ||
! V_2 || ! V_2 -> V_18 )
return;
V_6 = F_32 ( & V_2 -> V_16 ) &
( V_17 - 1 ) ;
V_11 = V_2 -> V_18 + V_6 ;
V_11 -> V_19 = V_19 ;
V_11 -> V_23 = V_23 ;
V_11 -> V_24 = V_24 ;
V_11 -> V_25 = V_25 ;
V_11 -> V_22 = F_32 ( & V_279 ) ;
V_11 -> V_20 = V_280 ;
#endif
return;
}
inline void
F_33 ( struct V_26 * V_27 , char * V_19 ,
T_1 V_23 , T_1 V_24 , T_1 V_25 )
{
#ifdef F_31
struct V_10 * V_11 ;
int V_6 ;
if ( ! V_15 || ! V_29 ||
! V_27 || ! V_27 -> V_30 )
return;
V_6 = F_32 ( & V_27 -> V_28 ) &
( V_29 - 1 ) ;
V_11 = V_27 -> V_30 + V_6 ;
V_11 -> V_19 = V_19 ;
V_11 -> V_23 = V_23 ;
V_11 -> V_24 = V_24 ;
V_11 -> V_25 = V_25 ;
V_11 -> V_22 = F_32 ( & V_279 ) ;
V_11 -> V_20 = V_280 ;
#endif
return;
}
inline void
F_34 ( struct V_26 * V_27 , char * V_19 ,
T_2 V_23 , T_2 V_24 , T_1 V_25 )
{
#ifdef F_31
struct V_255 * V_11 ;
int V_6 ;
if ( ! V_27 -> V_257 || ! V_27 -> V_261 )
return;
V_6 = F_32 ( & V_27 -> V_258 ) &
( V_27 -> V_259 - 1 ) ;
V_11 = V_27 -> V_261 + V_6 ;
V_11 -> V_19 = V_19 ;
V_11 -> V_23 = V_23 ;
V_11 -> V_24 = V_24 ;
V_11 -> V_25 = V_25 ;
#endif
}
static int
F_35 ( struct V_281 * V_281 , struct V_282 * V_282 )
{
struct V_1 * V_2 = V_281 -> V_283 ;
struct V_284 * V_285 ;
int V_4 ;
int V_286 = - V_287 ;
if ( ! V_17 ) {
V_286 = - V_288 ;
goto V_262;
}
V_285 = F_2 ( sizeof( * V_285 ) , V_14 ) ;
if ( ! V_285 )
goto V_262;
V_4 = ( V_17 * V_13 ) ;
V_4 = F_36 ( V_4 ) ;
V_285 -> V_12 = F_2 ( V_4 , V_14 ) ;
if ( ! V_285 -> V_12 ) {
F_5 ( V_285 ) ;
goto V_262;
}
V_285 -> V_7 = F_1 ( V_2 , V_285 -> V_12 , V_4 ) ;
V_282 -> V_289 = V_285 ;
V_286 = 0 ;
V_262:
return V_286 ;
}
static int
F_37 ( struct V_281 * V_281 , struct V_282 * V_282 )
{
struct V_26 * V_27 = V_281 -> V_283 ;
struct V_284 * V_285 ;
int V_4 ;
int V_286 = - V_287 ;
if ( ! V_29 ) {
V_286 = - V_288 ;
goto V_262;
}
V_285 = F_2 ( sizeof( * V_285 ) , V_14 ) ;
if ( ! V_285 )
goto V_262;
V_4 = ( V_29 * V_13 ) ;
V_4 = F_36 ( V_4 ) ;
V_285 -> V_12 = F_2 ( V_4 , V_14 ) ;
if ( ! V_285 -> V_12 ) {
F_5 ( V_285 ) ;
goto V_262;
}
V_285 -> V_7 = F_6 ( V_27 , V_285 -> V_12 , V_4 ) ;
V_282 -> V_289 = V_285 ;
V_286 = 0 ;
V_262:
return V_286 ;
}
static int
F_38 ( struct V_281 * V_281 , struct V_282 * V_282 )
{
struct V_26 * V_27 = V_281 -> V_283 ;
struct V_284 * V_285 ;
int V_286 = - V_287 ;
V_285 = F_2 ( sizeof( * V_285 ) , V_14 ) ;
if ( ! V_285 )
goto V_262;
V_285 -> V_12 = F_2 ( V_74 , V_14 ) ;
if ( ! V_285 -> V_12 ) {
F_5 ( V_285 ) ;
goto V_262;
}
V_285 -> V_7 = F_7 ( V_27 , V_285 -> V_12 ,
V_74 ) ;
V_282 -> V_289 = V_285 ;
V_286 = 0 ;
V_262:
return V_286 ;
}
static int
F_39 ( struct V_281 * V_281 , struct V_282 * V_282 )
{
struct V_26 * V_27 = V_281 -> V_283 ;
struct V_284 * V_285 ;
int V_286 = - V_287 ;
V_285 = F_2 ( sizeof( * V_285 ) , V_14 ) ;
if ( ! V_285 )
goto V_262;
V_285 -> V_12 = F_2 ( V_290 , V_14 ) ;
if ( ! V_285 -> V_12 ) {
F_5 ( V_285 ) ;
goto V_262;
}
V_285 -> V_7 = F_14 ( V_27 , V_285 -> V_12 ,
V_290 ) ;
V_282 -> V_289 = V_285 ;
V_286 = 0 ;
V_262:
return V_286 ;
}
static int
F_40 ( struct V_281 * V_281 , struct V_282 * V_282 )
{
struct V_26 * V_27 = V_281 -> V_283 ;
struct V_284 * V_285 ;
int V_286 = - V_287 ;
V_285 = F_2 ( sizeof( * V_285 ) , V_14 ) ;
if ( ! V_285 )
goto V_262;
V_285 -> V_12 = F_2 ( V_291 , V_14 ) ;
if ( ! V_285 -> V_12 ) {
F_5 ( V_285 ) ;
goto V_262;
}
V_285 -> V_7 = F_16 ( V_27 , V_285 -> V_12 ,
V_291 ) ;
V_282 -> V_289 = V_285 ;
V_286 = 0 ;
V_262:
return V_286 ;
}
static int
F_41 ( struct V_281 * V_281 , struct V_282 * V_282 )
{
struct V_284 * V_285 ;
int V_286 = - V_287 ;
if ( ! V_292 )
return - V_293 ;
V_285 = F_2 ( sizeof( * V_285 ) , V_14 ) ;
if ( ! V_285 )
goto V_262;
F_42 ( L_140 ,
V_294 , V_292 ) ;
V_285 -> V_12 = V_292 ;
if ( ! V_285 -> V_12 ) {
F_5 ( V_285 ) ;
goto V_262;
}
V_285 -> V_7 = ( 1 << V_295 ) << V_296 ;
V_282 -> V_289 = V_285 ;
V_286 = 0 ;
V_262:
return V_286 ;
}
static int
F_43 ( struct V_281 * V_281 , struct V_282 * V_282 )
{
struct V_284 * V_285 ;
int V_286 = - V_287 ;
if ( ! V_297 )
return - V_293 ;
V_285 = F_2 ( sizeof( * V_285 ) , V_14 ) ;
if ( ! V_285 )
goto V_262;
F_42 ( L_141 ,
V_294 , V_297 , V_282 ) ;
V_285 -> V_12 = V_297 ;
if ( ! V_285 -> V_12 ) {
F_5 ( V_285 ) ;
goto V_262;
}
V_285 -> V_7 = ( 1 << V_298 ) << V_296 ;
V_282 -> V_289 = V_285 ;
V_286 = 0 ;
V_262:
return V_286 ;
}
static T_3
F_44 ( struct V_282 * V_282 , const char T_4 * V_3 ,
T_5 V_299 , T_6 * V_300 )
{
F_23 ( & V_301 ) ;
memset ( ( void * ) V_292 , 0 ,
( ( 1 << V_296 ) << V_295 ) ) ;
memset ( ( void * ) V_297 , 0 ,
( ( 1 << V_296 ) << V_298 ) ) ;
V_302 = 0 ;
F_25 ( & V_301 ) ;
return V_299 ;
}
static T_3
F_45 ( struct V_282 * V_282 , char T_4 * V_3 ,
T_5 V_299 , T_6 * V_300 )
{
struct V_303 * V_304 = V_282 -> V_305 . V_303 ;
struct V_26 * V_27 = V_282 -> V_289 ;
char V_306 [ 32 ] ;
V_71 V_307 = 0 ;
int V_109 = 0 ;
if ( V_304 == V_27 -> V_308 )
V_109 = snprintf ( V_306 , 32 , L_142 , V_27 -> V_309 ) ;
else if ( V_304 == V_27 -> V_310 )
V_109 = snprintf ( V_306 , 32 , L_142 , V_27 -> V_311 ) ;
else if ( V_304 == V_27 -> V_312 )
V_109 = snprintf ( V_306 , 32 , L_142 , V_27 -> V_313 ) ;
else if ( V_304 == V_27 -> V_314 )
V_109 = snprintf ( V_306 , 32 , L_142 , V_27 -> V_315 ) ;
else if ( V_304 == V_27 -> V_316 )
V_109 = snprintf ( V_306 , 32 , L_142 , V_27 -> V_317 ) ;
else if ( V_304 == V_27 -> V_318 )
V_109 = snprintf ( V_306 , 32 , L_142 , V_27 -> V_319 ) ;
else if ( V_304 == V_27 -> V_320 )
V_109 = snprintf ( V_306 , 32 , L_143 , V_27 -> V_321 ) ;
else if ( V_304 == V_27 -> V_322 ) {
memcpy ( & V_307 , & V_27 -> V_323 , sizeof( struct V_324 ) ) ;
V_307 = F_46 ( V_307 ) ;
V_109 = snprintf ( V_306 , 32 , L_144 , V_307 ) ;
} else if ( V_304 == V_27 -> V_325 ) {
if ( V_27 -> V_326 == ( V_327 ) ( - 1 ) )
V_109 = snprintf ( V_306 , 32 , L_145 ) ;
else
V_109 = snprintf ( V_306 , 32 , L_146 ,
( V_71 ) V_27 -> V_326 ) ;
} else
F_47 ( V_27 , V_328 , V_329 ,
L_147 ) ;
return F_48 ( V_3 , V_299 , V_300 , & V_306 , V_109 ) ;
}
static T_3
F_49 ( struct V_282 * V_282 , const char T_4 * V_3 ,
T_5 V_299 , T_6 * V_300 )
{
struct V_303 * V_304 = V_282 -> V_305 . V_303 ;
struct V_26 * V_27 = V_282 -> V_289 ;
char V_330 [ 33 ] ;
V_71 V_307 = 0 ;
int V_4 ;
memset ( V_330 , 0 , 33 ) ;
V_4 = ( V_299 < 32 ) ? V_299 : 32 ;
if ( F_50 ( V_330 , V_3 , V_4 ) )
return 0 ;
if ( V_304 == V_27 -> V_325 ) {
if ( ( V_3 [ 0 ] == 'o' ) && ( V_3 [ 1 ] == 'f' ) && ( V_3 [ 2 ] == 'f' ) )
V_307 = ( V_71 ) ( - 1 ) ;
}
if ( ( V_307 == 0 ) && ( F_51 ( V_330 , 0 , & V_307 ) ) )
return 0 ;
if ( V_304 == V_27 -> V_308 )
V_27 -> V_309 = ( T_1 ) V_307 ;
else if ( V_304 == V_27 -> V_310 )
V_27 -> V_311 = ( T_1 ) V_307 ;
else if ( V_304 == V_27 -> V_312 )
V_27 -> V_313 = ( T_1 ) V_307 ;
else if ( V_304 == V_27 -> V_314 )
V_27 -> V_315 = ( T_1 ) V_307 ;
else if ( V_304 == V_27 -> V_316 )
V_27 -> V_317 = ( T_1 ) V_307 ;
else if ( V_304 == V_27 -> V_318 )
V_27 -> V_319 = ( T_1 ) V_307 ;
else if ( V_304 == V_27 -> V_325 )
V_27 -> V_326 = ( V_327 ) V_307 ;
else if ( V_304 == V_27 -> V_320 )
V_27 -> V_321 = ( T_1 ) ( V_307 & V_331 ) ;
else if ( V_304 == V_27 -> V_322 ) {
V_307 = F_46 ( V_307 ) ;
memcpy ( & V_27 -> V_323 , & V_307 , sizeof( struct V_324 ) ) ;
} else
F_47 ( V_27 , V_328 , V_329 ,
L_148 ) ;
return V_299 ;
}
static int
F_52 ( struct V_281 * V_281 , struct V_282 * V_282 )
{
return 0 ;
}
static int
F_53 ( struct V_281 * V_281 , struct V_282 * V_282 )
{
struct V_1 * V_2 = V_281 -> V_283 ;
struct V_284 * V_285 ;
int V_286 = - V_287 ;
V_285 = F_2 ( sizeof( * V_285 ) , V_14 ) ;
if ( ! V_285 )
goto V_262;
V_285 -> V_12 = F_2 ( V_121 , V_14 ) ;
if ( ! V_285 -> V_12 ) {
F_5 ( V_285 ) ;
goto V_262;
}
V_285 -> V_7 = F_18 ( V_2 , V_285 -> V_12 ,
V_121 ) ;
V_282 -> V_289 = V_285 ;
V_286 = 0 ;
V_262:
return V_286 ;
}
static T_6
F_54 ( struct V_282 * V_282 , T_6 V_75 , int V_332 )
{
struct V_284 * V_285 = V_282 -> V_289 ;
return F_55 ( V_282 , V_75 , V_332 , V_285 -> V_7 ) ;
}
static T_3
F_56 ( struct V_282 * V_282 , char T_4 * V_3 ,
T_5 V_299 , T_6 * V_300 )
{
struct V_284 * V_285 = V_282 -> V_289 ;
return F_48 ( V_3 , V_299 , V_300 , V_285 -> V_12 ,
V_285 -> V_7 ) ;
}
static int
F_57 ( struct V_281 * V_281 , struct V_282 * V_282 )
{
struct V_284 * V_285 = V_282 -> V_289 ;
F_5 ( V_285 -> V_12 ) ;
F_5 ( V_285 ) ;
return 0 ;
}
static int
F_58 ( struct V_281 * V_281 , struct V_282 * V_282 )
{
struct V_284 * V_285 = V_282 -> V_289 ;
V_285 -> V_12 = NULL ;
F_5 ( V_285 ) ;
return 0 ;
}
static int
F_59 ( struct V_281 * V_281 , struct V_282 * V_282 )
{
struct V_1 * V_2 = V_281 -> V_283 ;
struct V_284 * V_285 ;
int V_286 = - V_287 ;
V_285 = F_2 ( sizeof( * V_285 ) , V_14 ) ;
if ( ! V_285 )
goto V_262;
V_285 -> V_12 = F_2 ( V_333 , V_14 ) ;
if ( ! V_285 -> V_12 ) {
F_5 ( V_285 ) ;
goto V_262;
}
V_285 -> V_7 = F_22 ( V_2 , V_285 -> V_12 ,
V_333 ) ;
V_285 -> V_283 = V_281 -> V_283 ;
V_282 -> V_289 = V_285 ;
V_286 = 0 ;
V_262:
return V_286 ;
}
static T_3
F_60 ( struct V_282 * V_282 , const char T_4 * V_3 ,
T_5 V_299 , T_6 * V_300 )
{
struct V_284 * V_285 = V_282 -> V_289 ;
struct V_1 * V_2 = (struct V_1 * ) V_285 -> V_283 ;
struct V_26 * V_27 = V_2 -> V_27 ;
struct V_117 * V_118 ;
char V_334 [ 64 ] ;
char * V_335 ;
if ( ! V_27 -> V_154 )
return - V_336 ;
if ( V_299 > 64 )
V_299 = 64 ;
memset ( V_334 , 0 , sizeof( V_334 ) ) ;
if ( F_50 ( V_334 , V_3 , V_299 ) )
return - V_337 ;
V_335 = & V_334 [ 0 ] ;
V_118 = (struct V_117 * ) V_27 -> V_154 -> V_156 ;
if ( ( strncmp ( V_335 , L_149 , strlen ( L_149 ) ) == 0 ) ||
( strncmp ( V_335 , L_150 , strlen ( L_150 ) ) == 0 ) ) {
F_61 ( & V_118 -> V_175 , 0 ) ;
F_61 ( & V_118 -> V_178 , 0 ) ;
F_61 ( & V_118 -> V_176 , 0 ) ;
F_61 ( & V_118 -> V_177 , 0 ) ;
F_61 ( & V_118 -> V_338 , 0 ) ;
F_61 ( & V_118 -> V_179 , 0 ) ;
F_61 ( & V_118 -> V_180 , 0 ) ;
F_61 ( & V_118 -> V_182 , 0 ) ;
F_61 ( & V_118 -> V_181 , 0 ) ;
F_61 ( & V_118 -> V_183 , 0 ) ;
F_61 ( & V_118 -> V_187 , 0 ) ;
F_61 ( & V_118 -> V_186 , 0 ) ;
F_61 ( & V_118 -> V_339 , 0 ) ;
F_61 ( & V_118 -> V_189 , 0 ) ;
F_61 ( & V_118 -> V_188 , 0 ) ;
F_61 ( & V_118 -> V_190 , 0 ) ;
F_61 ( & V_118 -> V_191 , 0 ) ;
F_61 ( & V_118 -> V_185 , 0 ) ;
F_61 ( & V_118 -> V_192 , 0 ) ;
F_61 ( & V_118 -> V_193 , 0 ) ;
F_61 ( & V_118 -> V_194 , 0 ) ;
F_61 ( & V_118 -> V_195 , 0 ) ;
F_61 ( & V_118 -> V_196 , 0 ) ;
F_61 ( & V_118 -> V_197 , 0 ) ;
F_61 ( & V_118 -> V_198 , 0 ) ;
F_61 ( & V_118 -> V_199 , 0 ) ;
F_61 ( & V_118 -> V_200 , 0 ) ;
}
return V_299 ;
}
static int
F_62 ( struct V_281 * V_281 , struct V_282 * V_282 )
{
struct V_1 * V_2 = V_281 -> V_283 ;
struct V_284 * V_285 ;
int V_286 = - V_287 ;
V_285 = F_2 ( sizeof( * V_285 ) , V_14 ) ;
if ( ! V_285 )
goto V_262;
V_285 -> V_12 = F_2 ( V_340 , V_14 ) ;
if ( ! V_285 -> V_12 ) {
F_5 ( V_285 ) ;
goto V_262;
}
V_285 -> V_7 = F_26 ( V_2 , V_285 -> V_12 ,
V_340 ) ;
V_285 -> V_283 = V_281 -> V_283 ;
V_282 -> V_289 = V_285 ;
V_286 = 0 ;
V_262:
return V_286 ;
}
static T_3
F_63 ( struct V_282 * V_282 , const char T_4 * V_3 ,
T_5 V_299 , T_6 * V_300 )
{
struct V_284 * V_285 = V_282 -> V_289 ;
struct V_1 * V_2 = (struct V_1 * ) V_285 -> V_283 ;
struct V_26 * V_27 = V_2 -> V_27 ;
char V_334 [ 64 ] ;
char * V_335 ;
if ( V_299 > 64 )
V_299 = 64 ;
memset ( V_334 , 0 , sizeof( V_334 ) ) ;
if ( F_50 ( V_334 , V_3 , V_299 ) )
return - V_337 ;
V_335 = & V_334 [ 0 ] ;
if ( ( strncmp ( V_335 , L_151 , sizeof( L_151 ) - 1 ) == 0 ) ) {
V_27 -> V_223 = 0 ;
V_27 -> V_236 = 0 ;
V_27 -> V_224 = 0 ;
V_27 -> V_226 = 0 ;
V_27 -> V_225 = 0xffffffff ;
V_27 -> V_227 = 0 ;
V_27 -> V_229 = 0 ;
V_27 -> V_228 = 0xffffffff ;
V_27 -> V_230 = 0 ;
V_27 -> V_232 = 0 ;
V_27 -> V_231 = 0xffffffff ;
V_27 -> V_233 = 0 ;
V_27 -> V_235 = 0 ;
V_27 -> V_234 = 0xffffffff ;
V_27 -> V_237 = 0 ;
V_27 -> V_239 = 0 ;
V_27 -> V_238 = 0xffffffff ;
V_27 -> V_243 = 0 ;
V_27 -> V_245 = 0 ;
V_27 -> V_244 = 0xffffffff ;
V_27 -> V_246 = 0 ;
V_27 -> V_248 = 0 ;
V_27 -> V_247 = 0xffffffff ;
V_27 -> V_249 = 0 ;
V_27 -> V_251 = 0 ;
V_27 -> V_250 = 0xffffffff ;
V_27 -> V_252 = 0 ;
V_27 -> V_254 = 0 ;
V_27 -> V_253 = 0xffffffff ;
V_27 -> V_240 = 0 ;
V_27 -> V_242 = 0 ;
V_27 -> V_241 = 0xffffffff ;
V_27 -> V_222 = 1 ;
return strlen ( V_335 ) ;
} else if ( ( strncmp ( V_335 , L_152 ,
sizeof( L_152 ) - 1 ) == 0 ) ) {
V_27 -> V_222 = 0 ;
return strlen ( V_335 ) ;
} else if ( ( strncmp ( V_335 , L_150 ,
sizeof( L_150 ) - 1 ) == 0 ) ) {
V_27 -> V_223 = 0 ;
V_27 -> V_236 = 0 ;
V_27 -> V_224 = 0 ;
V_27 -> V_226 = 0 ;
V_27 -> V_225 = 0xffffffff ;
V_27 -> V_227 = 0 ;
V_27 -> V_229 = 0 ;
V_27 -> V_228 = 0xffffffff ;
V_27 -> V_230 = 0 ;
V_27 -> V_232 = 0 ;
V_27 -> V_231 = 0xffffffff ;
V_27 -> V_233 = 0 ;
V_27 -> V_235 = 0 ;
V_27 -> V_234 = 0xffffffff ;
V_27 -> V_237 = 0 ;
V_27 -> V_239 = 0 ;
V_27 -> V_238 = 0xffffffff ;
V_27 -> V_243 = 0 ;
V_27 -> V_245 = 0 ;
V_27 -> V_244 = 0xffffffff ;
V_27 -> V_246 = 0 ;
V_27 -> V_248 = 0 ;
V_27 -> V_247 = 0xffffffff ;
V_27 -> V_249 = 0 ;
V_27 -> V_251 = 0 ;
V_27 -> V_250 = 0xffffffff ;
V_27 -> V_252 = 0 ;
V_27 -> V_254 = 0 ;
V_27 -> V_253 = 0xffffffff ;
V_27 -> V_240 = 0 ;
V_27 -> V_242 = 0 ;
V_27 -> V_241 = 0xffffffff ;
return strlen ( V_335 ) ;
}
return - V_341 ;
}
static int
F_64 ( struct V_281 * V_281 , struct V_282 * V_282 )
{
struct V_26 * V_27 = V_281 -> V_283 ;
struct V_284 * V_285 ;
int V_286 = - V_287 ;
V_285 = F_2 ( sizeof( * V_285 ) , V_14 ) ;
if ( ! V_285 )
goto V_262;
V_285 -> V_12 = F_2 ( V_342 , V_14 ) ;
if ( ! V_285 -> V_12 ) {
F_5 ( V_285 ) ;
goto V_262;
}
V_285 -> V_7 = F_28 ( V_27 , V_285 -> V_12 ,
V_342 ) ;
V_285 -> V_283 = V_281 -> V_283 ;
V_282 -> V_289 = V_285 ;
V_286 = 0 ;
V_262:
return V_286 ;
}
static T_3
F_65 ( struct V_282 * V_282 , const char T_4 * V_3 ,
T_5 V_299 , T_6 * V_300 )
{
struct V_284 * V_285 = V_282 -> V_289 ;
struct V_26 * V_27 = (struct V_26 * ) V_285 -> V_283 ;
int V_5 ;
unsigned long V_343 ;
char V_334 [ 64 ] ;
char * V_335 ;
if ( V_299 > 64 )
V_299 = 64 ;
memset ( V_334 , 0 , sizeof( V_334 ) ) ;
if ( F_50 ( V_334 , V_3 , V_299 ) )
return - V_337 ;
V_335 = & V_334 [ 0 ] ;
if ( ( strncmp ( V_335 , L_152 , sizeof( L_152 ) - 1 ) == 0 ) ) {
F_47 ( V_27 , V_328 , V_329 ,
L_153 ) ;
V_27 -> V_260 = 0 ;
V_27 -> V_257 = 0 ;
return strlen ( V_335 ) ;
} else if ( ( strncmp ( V_335 , L_151 , sizeof( L_151 ) - 1 ) == 0 ) ) {
F_47 ( V_27 , V_328 , V_329 ,
L_154 ) ;
V_27 -> V_260 = 0 ;
V_27 -> V_257 = 1 ;
return strlen ( V_335 ) ;
}
if ( V_27 -> V_257 != 0 )
return - V_341 ;
V_5 = F_66 ( V_335 , 0 , & V_343 ) ;
if ( V_5 )
return - V_341 ;
V_27 -> V_259 = ( T_1 ) V_343 ;
V_5 = 0 ;
while ( V_343 > 1 ) {
V_343 = V_343 >> 1 ;
V_5 ++ ;
}
V_343 = ( 1 << V_5 ) ;
if ( V_27 -> V_259 != V_343 )
F_47 ( V_27 , V_328 , V_329 ,
L_155 ,
V_343 ) ;
V_27 -> V_259 = ( T_1 ) V_343 ;
F_5 ( V_27 -> V_261 ) ;
V_27 -> V_261 = F_2 ( ( sizeof( struct V_255 ) *
V_343 ) , V_14 ) ;
if ( ! V_27 -> V_261 ) {
F_47 ( V_27 , V_328 , V_329 ,
L_156
L_157 ) ;
return - V_287 ;
}
memset ( V_27 -> V_261 , 0 ,
( sizeof( struct V_255 ) * V_343 ) ) ;
F_61 ( & V_27 -> V_258 , 0 ) ;
V_27 -> V_257 = 0 ;
V_27 -> V_260 = 0 ;
return strlen ( V_335 ) ;
}
static int
F_67 ( struct V_281 * V_281 , struct V_282 * V_282 )
{
struct V_1 * V_2 = V_281 -> V_283 ;
struct V_284 * V_285 ;
int V_286 = - V_287 ;
V_285 = F_2 ( sizeof( * V_285 ) , V_14 ) ;
if ( ! V_285 )
goto V_262;
V_285 -> V_12 = F_2 ( V_344 , V_14 ) ;
if ( ! V_285 -> V_12 ) {
F_5 ( V_285 ) ;
goto V_262;
}
V_285 -> V_7 = F_29 ( V_2 , V_285 -> V_12 ,
V_340 ) ;
V_285 -> V_283 = V_281 -> V_283 ;
V_282 -> V_289 = V_285 ;
V_286 = 0 ;
V_262:
return V_286 ;
}
static T_3
F_68 ( struct V_282 * V_282 , const char T_4 * V_3 ,
T_5 V_299 , T_6 * V_300 )
{
struct V_284 * V_285 = V_282 -> V_289 ;
struct V_1 * V_2 = (struct V_1 * ) V_285 -> V_283 ;
struct V_26 * V_27 = V_2 -> V_27 ;
char V_334 [ 64 ] ;
char * V_335 ;
int V_5 ;
if ( V_299 > 64 )
V_299 = 64 ;
memset ( V_334 , 0 , sizeof( V_334 ) ) ;
if ( F_50 ( V_334 , V_3 , V_299 ) )
return - V_337 ;
V_335 = & V_334 [ 0 ] ;
if ( ( strncmp ( V_335 , L_151 , sizeof( L_151 ) - 1 ) == 0 ) ) {
if ( V_27 -> V_153 )
V_27 -> V_267 |= V_273 ;
else
V_27 -> V_267 |= V_268 ;
return strlen ( V_335 ) ;
} else if ( ( strncmp ( V_335 , L_158 ,
sizeof( L_158 ) - 1 ) == 0 ) ) {
if ( V_27 -> V_153 )
V_27 -> V_267 |= V_274 ;
else
return - V_341 ;
return strlen ( V_335 ) ;
} else if ( ( strncmp ( V_335 , L_152 ,
sizeof( L_152 ) - 1 ) == 0 ) ) {
V_27 -> V_267 = V_345 ;
return strlen ( V_335 ) ;
} else if ( ( strncmp ( V_335 , L_150 ,
sizeof( L_150 ) - 1 ) == 0 ) ) {
for ( V_5 = 0 ; V_5 < V_27 -> V_201 . V_269 ; V_5 ++ ) {
if ( V_5 >= V_270 )
break;
V_27 -> V_276 [ V_5 ] = 0 ;
V_27 -> V_271 [ V_5 ] = 0 ;
V_27 -> V_272 [ V_5 ] = 0 ;
V_27 -> V_275 [ V_5 ] = 0 ;
}
return strlen ( V_335 ) ;
}
return - V_341 ;
}
static int F_69 ( const char T_4 * V_3 , T_5 V_299 ,
struct V_346 * V_347 )
{
char V_334 [ 64 ] ;
char * V_335 , * V_348 ;
int V_5 ;
T_5 V_349 ;
memset ( V_334 , 0 , sizeof( V_334 ) ) ;
memset ( V_347 , 0 , sizeof( * V_347 ) ) ;
V_349 = F_70 ( V_299 , ( sizeof( V_334 ) - 1 ) ) ;
if ( F_50 ( V_334 , V_3 , V_349 ) )
return - V_337 ;
V_335 = & V_334 [ 0 ] ;
V_348 = F_71 ( & V_335 , L_159 ) ;
if ( ! V_348 )
return - V_341 ;
V_347 -> V_350 = F_72 ( V_348 , NULL , 0 ) ;
if ( V_347 -> V_350 == 0 )
return - V_341 ;
for ( V_5 = 0 ; V_5 < V_351 ; V_5 ++ ) {
V_348 = F_71 ( & V_335 , L_159 ) ;
if ( ! V_348 )
return V_5 ;
V_347 -> V_352 [ V_5 ] = F_72 ( V_348 , NULL , 0 ) ;
}
return V_5 ;
}
static int
F_73 ( struct V_281 * V_281 , struct V_282 * V_282 )
{
struct V_284 * V_285 ;
V_285 = F_2 ( sizeof( * V_285 ) , V_14 ) ;
if ( ! V_285 )
return - V_287 ;
V_285 -> V_283 = V_281 -> V_283 ;
V_285 -> V_12 = NULL ;
V_282 -> V_289 = V_285 ;
return 0 ;
}
static int
F_74 ( struct V_281 * V_281 , struct V_282 * V_282 )
{
struct V_284 * V_285 = V_282 -> V_289 ;
F_5 ( V_285 -> V_12 ) ;
F_5 ( V_285 ) ;
return 0 ;
}
static int
F_75 ( struct V_281 * V_281 , struct V_282 * V_282 )
{
struct V_284 * V_285 = V_282 -> V_289 ;
if ( V_285 -> V_353 == V_354 ) {
switch ( V_355 . V_356 . V_350 ) {
case V_357 :
case V_358 :
case V_359 :
case V_360 :
case V_361 :
case V_362 :
memset ( & V_355 , 0 , sizeof( V_355 ) ) ;
break;
default:
break;
}
}
F_5 ( V_285 -> V_12 ) ;
F_5 ( V_285 ) ;
return 0 ;
}
static T_3
F_76 ( struct V_282 * V_282 , char T_4 * V_3 , T_5 V_299 ,
T_6 * V_300 )
{
struct V_284 * V_285 = V_282 -> V_289 ;
struct V_26 * V_27 = (struct V_26 * ) V_285 -> V_283 ;
int V_363 , V_364 , V_7 = 0 , V_6 = V_365 ;
int V_366 , V_367 ;
char * V_368 ;
struct V_369 * V_370 ;
T_1 V_371 ;
T_2 V_372 ;
T_7 V_373 ;
V_370 = V_27 -> V_374 ;
if ( ! V_370 )
return 0 ;
V_285 -> V_353 = V_375 ;
if ( ! V_285 -> V_12 )
V_285 -> V_12 = F_2 ( V_376 , V_14 ) ;
if ( ! V_285 -> V_12 )
return 0 ;
V_368 = V_285 -> V_12 ;
if ( * V_300 )
return 0 ;
if ( V_355 . V_356 . V_350 == V_377 ) {
V_366 = V_355 . V_356 . V_352 [ V_378 ] ;
V_367 = V_355 . V_356 . V_352 [ V_379 ] ;
} else
return 0 ;
switch ( V_367 ) {
case V_380 :
F_77 ( V_370 , V_366 , & V_373 ) ;
V_7 += snprintf ( V_368 + V_7 , V_376 - V_7 ,
L_160 , V_366 , V_373 ) ;
break;
case V_381 :
F_78 ( V_370 , V_366 , & V_372 ) ;
V_7 += snprintf ( V_368 + V_7 , V_376 - V_7 ,
L_161 , V_366 , V_372 ) ;
break;
case V_382 :
F_79 ( V_370 , V_366 , & V_371 ) ;
V_7 += snprintf ( V_368 + V_7 , V_376 - V_7 ,
L_162 , V_366 , V_371 ) ;
break;
case V_383 :
goto V_384;
break;
default:
V_7 = 0 ;
break;
}
return F_48 ( V_3 , V_299 , V_300 , V_368 , V_7 ) ;
V_384:
V_363 = V_355 . V_364 . V_385 ;
V_364 = V_363 ;
V_7 += snprintf ( V_368 + V_7 , V_376 - V_7 ,
L_163 , V_363 ) ;
while ( V_6 > 0 ) {
F_79 ( V_370 , V_364 , & V_371 ) ;
V_7 += snprintf ( V_368 + V_7 , V_376 - V_7 ,
L_164 , V_371 ) ;
V_364 += sizeof( T_1 ) ;
if ( V_364 >= V_376 ) {
V_7 += snprintf ( V_368 + V_7 ,
V_376 - V_7 , L_46 ) ;
break;
}
V_6 -= sizeof( T_1 ) ;
if ( ! V_6 )
V_7 += snprintf ( V_368 + V_7 , V_376 - V_7 ,
L_46 ) ;
else if ( ! ( V_6 % ( 8 * sizeof( T_1 ) ) ) ) {
V_363 += ( 8 * sizeof( T_1 ) ) ;
V_7 += snprintf ( V_368 + V_7 , V_376 - V_7 ,
L_165 , V_363 ) ;
}
}
if ( V_6 == 0 ) {
V_355 . V_364 . V_385 += V_365 ;
if ( V_355 . V_364 . V_385 >= V_376 )
V_355 . V_364 . V_385 = 0 ;
} else
V_355 . V_364 . V_385 = 0 ;
return F_48 ( V_3 , V_299 , V_300 , V_368 , V_7 ) ;
}
static T_3
F_80 ( struct V_282 * V_282 , const char T_4 * V_3 ,
T_5 V_299 , T_6 * V_300 )
{
struct V_284 * V_285 = V_282 -> V_289 ;
struct V_26 * V_27 = (struct V_26 * ) V_285 -> V_283 ;
T_1 V_366 , V_386 , V_367 ;
T_1 V_371 ;
T_2 V_372 ;
T_7 V_373 ;
struct V_369 * V_370 ;
int V_286 ;
V_370 = V_27 -> V_374 ;
if ( ! V_370 )
return - V_337 ;
V_285 -> V_353 = V_354 ;
V_286 = F_69 ( V_3 , V_299 , & V_355 . V_356 ) ;
if ( V_286 < 0 )
return V_286 ;
if ( V_355 . V_356 . V_350 == V_377 ) {
if ( V_286 != V_387 )
goto V_388;
V_366 = V_355 . V_356 . V_352 [ V_378 ] ;
V_367 = V_355 . V_356 . V_352 [ V_379 ] ;
if ( V_367 == V_383 ) {
if ( V_366 % sizeof( T_1 ) )
goto V_388;
V_355 . V_364 . V_385 = V_366 ;
} else if ( ( V_367 != sizeof( T_7 ) ) &&
( V_367 != sizeof( T_2 ) ) &&
( V_367 != sizeof( T_1 ) ) )
goto V_388;
if ( V_367 == sizeof( T_7 ) ) {
if ( V_366 > V_376 - sizeof( T_7 ) )
goto V_388;
if ( V_366 % sizeof( T_7 ) )
goto V_388;
}
if ( V_367 == sizeof( T_2 ) ) {
if ( V_366 > V_376 - sizeof( T_2 ) )
goto V_388;
if ( V_366 % sizeof( T_2 ) )
goto V_388;
}
if ( V_367 == sizeof( T_1 ) ) {
if ( V_366 > V_376 - sizeof( T_1 ) )
goto V_388;
if ( V_366 % sizeof( T_1 ) )
goto V_388;
}
} else if ( V_355 . V_356 . V_350 == V_357 ||
V_355 . V_356 . V_350 == V_358 ||
V_355 . V_356 . V_350 == V_359 ) {
if ( V_286 != V_389 )
goto V_388;
V_366 = V_355 . V_356 . V_352 [ V_378 ] ;
V_367 = V_355 . V_356 . V_352 [ V_379 ] ;
V_386 = V_355 . V_356 . V_352 [ V_390 ] ;
if ( ( V_367 != sizeof( T_7 ) ) &&
( V_367 != sizeof( T_2 ) ) &&
( V_367 != sizeof( T_1 ) ) )
goto V_388;
if ( V_367 == sizeof( T_7 ) ) {
if ( V_366 > V_376 - sizeof( T_7 ) )
goto V_388;
if ( V_366 % sizeof( T_7 ) )
goto V_388;
if ( V_355 . V_356 . V_350 == V_357 )
F_81 ( V_370 , V_366 ,
( T_7 ) V_386 ) ;
if ( V_355 . V_356 . V_350 == V_358 ) {
V_286 = F_77 ( V_370 , V_366 , & V_373 ) ;
if ( ! V_286 ) {
V_373 |= ( T_7 ) V_386 ;
F_81 ( V_370 , V_366 ,
V_373 ) ;
}
}
if ( V_355 . V_356 . V_350 == V_359 ) {
V_286 = F_77 ( V_370 , V_366 , & V_373 ) ;
if ( ! V_286 ) {
V_373 &= ( T_7 ) ( ~ V_386 ) ;
F_81 ( V_370 , V_366 ,
V_373 ) ;
}
}
}
if ( V_367 == sizeof( T_2 ) ) {
if ( V_366 > V_376 - sizeof( T_2 ) )
goto V_388;
if ( V_366 % sizeof( T_2 ) )
goto V_388;
if ( V_355 . V_356 . V_350 == V_357 )
F_82 ( V_370 , V_366 ,
( T_2 ) V_386 ) ;
if ( V_355 . V_356 . V_350 == V_358 ) {
V_286 = F_78 ( V_370 , V_366 , & V_372 ) ;
if ( ! V_286 ) {
V_372 |= ( T_2 ) V_386 ;
F_82 ( V_370 , V_366 ,
V_372 ) ;
}
}
if ( V_355 . V_356 . V_350 == V_359 ) {
V_286 = F_78 ( V_370 , V_366 , & V_372 ) ;
if ( ! V_286 ) {
V_372 &= ( T_2 ) ( ~ V_386 ) ;
F_82 ( V_370 , V_366 ,
V_372 ) ;
}
}
}
if ( V_367 == sizeof( T_1 ) ) {
if ( V_366 > V_376 - sizeof( T_1 ) )
goto V_388;
if ( V_366 % sizeof( T_1 ) )
goto V_388;
if ( V_355 . V_356 . V_350 == V_357 )
F_83 ( V_370 , V_366 , V_386 ) ;
if ( V_355 . V_356 . V_350 == V_358 ) {
V_286 = F_79 ( V_370 , V_366 ,
& V_371 ) ;
if ( ! V_286 ) {
V_371 |= V_386 ;
F_83 ( V_370 , V_366 ,
V_371 ) ;
}
}
if ( V_355 . V_356 . V_350 == V_359 ) {
V_286 = F_79 ( V_370 , V_366 ,
& V_371 ) ;
if ( ! V_286 ) {
V_371 &= ~ V_386 ;
F_83 ( V_370 , V_366 ,
V_371 ) ;
}
}
}
} else
goto V_388;
return V_299 ;
V_388:
memset ( & V_355 , 0 , sizeof( V_355 ) ) ;
return - V_341 ;
}
static T_3
F_84 ( struct V_282 * V_282 , char T_4 * V_3 , T_5 V_299 ,
T_6 * V_300 )
{
struct V_284 * V_285 = V_282 -> V_289 ;
struct V_26 * V_27 = (struct V_26 * ) V_285 -> V_283 ;
int V_363 , V_364 , V_391 , V_7 = 0 , V_6 ;
int V_392 , V_393 , V_394 ;
char * V_368 ;
void T_8 * V_395 ;
T_1 V_396 ;
struct V_369 * V_370 ;
T_1 V_371 ;
V_370 = V_27 -> V_374 ;
if ( ! V_370 )
return 0 ;
V_285 -> V_353 = V_375 ;
if ( ! V_285 -> V_12 )
V_285 -> V_12 = F_2 ( V_397 , V_14 ) ;
if ( ! V_285 -> V_12 )
return 0 ;
V_368 = V_285 -> V_12 ;
if ( * V_300 )
return 0 ;
if ( V_355 . V_356 . V_350 == V_398 ) {
V_392 = V_355 . V_356 . V_352 [ V_399 ] ;
V_364 = V_355 . V_356 . V_352 [ V_400 ] ;
V_393 = V_355 . V_356 . V_352 [ V_401 ] ;
V_394 = V_355 . V_356 . V_352 [ V_402 ] ;
} else
return 0 ;
if ( V_393 == 0 )
return 0 ;
V_396 = F_85 ( V_403 , & V_27 -> V_201 . V_404 ) ;
if ( V_396 == V_405 ) {
if ( V_392 == V_406 )
V_395 = V_27 -> V_201 . V_407 ;
else if ( V_392 == V_408 )
V_395 = V_27 -> V_201 . V_409 ;
else if ( V_392 == V_410 )
V_395 = V_27 -> V_201 . V_411 ;
else
return 0 ;
} else if ( V_396 == V_412 ) {
if ( V_392 == V_406 )
V_395 = V_27 -> V_201 . V_407 ;
else
return 0 ;
} else
return 0 ;
if ( V_393 == V_413 ) {
V_391 = V_364 ;
V_371 = F_17 ( V_395 + V_391 ) ;
V_7 += snprintf ( V_368 + V_7 , V_397 - V_7 ,
L_166 , V_391 , V_371 ) ;
} else
goto V_414;
return F_48 ( V_3 , V_299 , V_300 , V_368 , V_7 ) ;
V_414:
V_363 = V_355 . V_364 . V_385 ;
V_391 = V_363 ;
V_7 += snprintf ( V_368 + V_7 , V_397 - V_7 ,
L_167 , V_363 ) ;
V_6 = V_415 ;
while ( V_6 > 0 ) {
V_371 = F_17 ( V_395 + V_391 ) ;
V_7 += snprintf ( V_368 + V_7 , V_397 - V_7 ,
L_164 , V_371 ) ;
V_391 += sizeof( T_1 ) ;
if ( V_393 == V_416 ) {
if ( V_391 >= V_394 ) {
V_7 += snprintf ( V_368 + V_7 ,
V_397 - V_7 , L_46 ) ;
break;
}
} else {
if ( V_391 >= V_364 +
( V_393 * sizeof( T_1 ) ) ) {
V_7 += snprintf ( V_368 + V_7 ,
V_397 - V_7 , L_46 ) ;
break;
}
}
V_6 -= sizeof( T_1 ) ;
if ( ! V_6 )
V_7 += snprintf ( V_368 + V_7 ,
V_397 - V_7 , L_46 ) ;
else if ( ! ( V_6 % ( 8 * sizeof( T_1 ) ) ) ) {
V_363 += ( 8 * sizeof( T_1 ) ) ;
V_7 += snprintf ( V_368 + V_7 ,
V_397 - V_7 ,
L_168 , V_363 ) ;
}
}
if ( V_6 == 0 ) {
V_355 . V_364 . V_385 += V_415 ;
if ( V_393 == V_416 ) {
if ( V_355 . V_364 . V_385 >= V_394 )
V_355 . V_364 . V_385 = 0 ;
} else {
if ( V_391 >= V_364 +
( V_393 * sizeof( T_1 ) ) )
V_355 . V_364 . V_385 = V_364 ;
}
} else {
if ( V_393 == V_416 )
V_355 . V_364 . V_385 = 0 ;
else
V_355 . V_364 . V_385 = V_364 ;
}
return F_48 ( V_3 , V_299 , V_300 , V_368 , V_7 ) ;
}
static T_3
F_86 ( struct V_282 * V_282 , const char T_4 * V_3 ,
T_5 V_299 , T_6 * V_300 )
{
struct V_284 * V_285 = V_282 -> V_289 ;
struct V_26 * V_27 = (struct V_26 * ) V_285 -> V_283 ;
T_1 V_392 , V_394 , V_364 , V_386 , V_393 ;
struct V_369 * V_370 ;
void T_8 * V_395 ;
T_1 V_396 ;
T_1 V_371 ;
int V_286 ;
V_370 = V_27 -> V_374 ;
if ( ! V_370 )
return - V_337 ;
V_285 -> V_353 = V_354 ;
V_286 = F_69 ( V_3 , V_299 , & V_355 . V_356 ) ;
if ( V_286 < 0 )
return V_286 ;
V_396 = F_85 ( V_403 , & V_27 -> V_201 . V_404 ) ;
V_392 = V_355 . V_356 . V_352 [ V_399 ] ;
if ( V_396 == V_405 ) {
if ( ( V_392 != V_406 ) &&
( V_392 != V_408 ) &&
( V_392 != V_410 ) )
goto V_388;
} else if ( V_396 == V_412 ) {
if ( V_392 != V_406 )
goto V_388;
} else
goto V_388;
if ( V_396 == V_405 ) {
if ( V_392 == V_406 ) {
V_355 . V_356 . V_352 [ V_402 ] =
V_417 ;
V_395 = V_27 -> V_201 . V_407 ;
} else if ( V_392 == V_408 ) {
V_355 . V_356 . V_352 [ V_402 ] =
V_418 ;
V_395 = V_27 -> V_201 . V_409 ;
} else if ( V_392 == V_410 ) {
V_355 . V_356 . V_352 [ V_402 ] =
V_419 ;
V_395 = V_27 -> V_201 . V_411 ;
} else
goto V_388;
} else if ( V_396 == V_412 ) {
if ( V_392 == V_406 ) {
V_355 . V_356 . V_352 [ V_402 ] =
V_420 ;
V_395 = V_27 -> V_201 . V_407 ;
} else
goto V_388;
} else
goto V_388;
V_364 = V_355 . V_356 . V_352 [ V_400 ] ;
if ( V_364 % sizeof( T_1 ) )
goto V_388;
V_394 = V_355 . V_356 . V_352 [ V_402 ] ;
if ( V_355 . V_356 . V_350 == V_398 ) {
if ( V_286 != V_421 )
goto V_388;
V_393 = V_355 . V_356 . V_352 [ V_401 ] ;
if ( V_393 == V_416 ) {
if ( V_364 > V_394 - sizeof( T_1 ) )
goto V_388;
V_355 . V_364 . V_385 = V_364 ;
} else if ( V_393 > V_413 ) {
if ( V_364 + V_393 * sizeof( T_1 ) > V_394 )
goto V_388;
V_355 . V_364 . V_385 = V_364 ;
} else if ( V_393 != V_413 )
goto V_388;
} else if ( V_355 . V_356 . V_350 == V_422 ||
V_355 . V_356 . V_350 == V_423 ||
V_355 . V_356 . V_350 == V_424 ) {
if ( V_286 != V_425 )
goto V_388;
V_393 = V_413 ;
V_386 = V_355 . V_356 . V_352 [ V_426 ] ;
if ( V_355 . V_356 . V_350 == V_422 ) {
F_87 ( V_386 , V_395 + V_364 ) ;
F_17 ( V_395 + V_364 ) ;
}
if ( V_355 . V_356 . V_350 == V_423 ) {
V_371 = F_17 ( V_395 + V_364 ) ;
V_371 |= V_386 ;
F_87 ( V_371 , V_395 + V_364 ) ;
F_17 ( V_395 + V_364 ) ;
}
if ( V_355 . V_356 . V_350 == V_424 ) {
V_371 = F_17 ( V_395 + V_364 ) ;
V_371 &= ~ V_386 ;
F_87 ( V_371 , V_395 + V_364 ) ;
F_17 ( V_395 + V_364 ) ;
}
} else
goto V_388;
return V_299 ;
V_388:
memset ( & V_355 , 0 , sizeof( V_355 ) ) ;
return - V_341 ;
}
static int
F_88 ( struct V_427 * V_428 , char * V_429 ,
char * V_368 , int V_7 )
{
if ( ! V_428 )
return V_7 ;
V_7 += snprintf ( V_368 + V_7 , V_430 - V_7 ,
L_169 , V_429 ) ;
V_7 += snprintf ( V_368 + V_7 , V_430 - V_7 ,
L_170 ,
V_428 -> V_431 , V_428 -> V_432 ,
( unsigned long long ) V_428 -> V_433 ) ;
V_7 += snprintf ( V_368 + V_7 , V_430 - V_7 ,
L_171
L_172 ,
V_428 -> V_434 , V_428 -> V_59 ,
V_428 -> V_435 , V_428 -> V_436 ,
V_428 -> V_437 , V_428 -> V_438 ) ;
V_7 += snprintf ( V_368 + V_7 ,
V_430 - V_7 , L_46 ) ;
return V_7 ;
}
static int
F_89 ( struct V_26 * V_27 , char * V_429 , char * V_368 ,
int * V_7 , int V_439 , int V_440 )
{
struct V_427 * V_428 ;
int V_441 ;
for ( V_441 = 0 ; V_441 < V_27 -> V_442 ; V_441 ++ ) {
V_428 = V_27 -> V_201 . V_443 [ V_441 ] ;
if ( V_428 -> V_431 != V_440 )
continue;
* V_7 = F_88 ( V_428 , V_429 , V_368 , * V_7 ) ;
if ( * V_7 >= V_439 )
return 1 ;
}
for ( V_441 = 0 ; V_441 < V_27 -> V_444 ; V_441 ++ ) {
V_428 = V_27 -> V_201 . V_445 [ V_441 ] ;
if ( V_428 -> V_431 != V_440 )
continue;
* V_7 = F_88 ( V_428 , V_429 , V_368 , * V_7 ) ;
if ( * V_7 >= V_439 )
return 1 ;
}
return 0 ;
}
static int
F_90 ( struct V_427 * V_428 , char * V_446 ,
char * V_368 , int V_7 )
{
if ( ! V_428 )
return V_7 ;
V_7 += snprintf ( V_368 + V_7 , V_430 - V_7 ,
L_173 , V_446 ) ;
V_7 += snprintf ( V_368 + V_7 , V_430 - V_7 ,
L_174
L_175 ,
V_428 -> V_431 , V_428 -> V_432 , V_428 -> V_447 ,
V_428 -> V_448 , ( unsigned long long ) V_428 -> V_433 ) ;
V_7 += snprintf ( V_368 + V_7 , V_430 - V_7 ,
L_176
L_172 ,
V_428 -> V_434 , V_428 -> V_59 ,
V_428 -> V_435 , V_428 -> V_436 ,
V_428 -> V_437 , V_428 -> V_438 ) ;
V_7 += snprintf ( V_368 + V_7 , V_430 - V_7 , L_46 ) ;
return V_7 ;
}
static int
F_91 ( struct V_427 * V_428 , struct V_427 * V_449 ,
char * V_450 , char * V_368 , int V_7 )
{
if ( ! V_428 || ! V_449 )
return V_7 ;
V_7 += snprintf ( V_368 + V_7 , V_430 - V_7 ,
L_177 , V_450 ) ;
V_7 += snprintf ( V_368 + V_7 , V_430 - V_7 ,
L_178
L_179 ,
V_428 -> V_431 , V_428 -> V_432 , V_428 -> V_447 ,
V_428 -> V_448 , ( unsigned long long ) V_428 -> V_433 ) ;
V_7 += snprintf ( V_368 + V_7 , V_430 - V_7 ,
L_180
L_181 ,
V_428 -> V_434 , V_428 -> V_59 , V_428 -> V_435 ,
V_428 -> V_436 , V_428 -> V_437 , V_428 -> V_438 ) ;
V_7 += snprintf ( V_368 + V_7 , V_430 - V_7 ,
L_182
L_181 ,
V_449 -> V_434 , V_449 -> V_59 ,
V_449 -> V_435 , V_449 -> V_436 ,
V_449 -> V_437 , V_449 -> V_438 ) ;
return V_7 ;
}
static int
F_92 ( struct V_26 * V_27 , char * V_368 ,
int * V_7 , int V_439 , int V_451 , int V_452 )
{
struct V_427 * V_428 ;
int V_441 , V_286 ;
for ( V_441 = 0 ; V_441 < V_27 -> V_442 ; V_441 ++ ) {
V_428 = V_27 -> V_201 . V_453 [ V_441 ] ;
if ( V_428 -> V_431 != V_452 )
continue;
* V_7 = F_90 ( V_428 , L_183 , V_368 , * V_7 ) ;
V_428 -> V_454 = 0 ;
if ( * V_7 >= V_439 )
return 1 ;
V_286 = F_89 ( V_27 , L_183 , V_368 , V_7 ,
V_439 , V_428 -> V_434 ) ;
if ( V_286 )
return 1 ;
}
for ( V_441 = 0 ; V_441 < V_27 -> V_444 ; V_441 ++ ) {
V_428 = V_27 -> V_201 . V_455 [ V_441 ] ;
if ( V_428 -> V_431 != V_452 )
continue;
* V_7 = F_90 ( V_428 , L_123 , V_368 , * V_7 ) ;
V_428 -> V_454 = 0 ;
if ( * V_7 >= V_439 )
return 1 ;
V_286 = F_89 ( V_27 , L_123 , V_368 , V_7 ,
V_439 , V_428 -> V_434 ) ;
if ( V_286 )
return 1 ;
}
if ( V_451 < V_27 -> V_456 ) {
V_428 = V_27 -> V_201 . V_457 [ V_451 ] ;
* V_7 = F_90 ( V_428 , L_184 , V_368 , * V_7 ) ;
V_428 -> V_454 = 0 ;
if ( * V_7 >= V_439 )
return 1 ;
V_428 = V_27 -> V_201 . V_458 [ V_451 ] ;
* V_7 = F_91 ( V_428 ,
V_27 -> V_201 . V_459 [ V_451 ] ,
L_185 , V_368 , * V_7 ) ;
if ( * V_7 >= V_439 )
return 1 ;
}
return 0 ;
}
static int
F_93 ( struct V_427 * V_428 , char * V_460 ,
char * V_368 , int V_7 )
{
if ( ! V_428 )
return V_7 ;
V_7 += snprintf ( V_368 + V_7 , V_430 - V_7 ,
L_186
L_187 ,
V_460 , V_428 -> V_432 , V_428 -> V_447 , V_428 -> V_448 ,
( unsigned long long ) V_428 -> V_433 , V_428 -> V_461 ) ;
V_7 += snprintf ( V_368 + V_7 , V_430 - V_7 ,
L_188
L_172 ,
V_428 -> V_434 , V_428 -> V_59 , V_428 -> V_435 ,
V_428 -> V_436 , V_428 -> V_437 , V_428 -> V_438 ) ;
V_7 += snprintf ( V_368 + V_7 , V_430 - V_7 , L_46 ) ;
return V_7 ;
}
static T_3
F_94 ( struct V_282 * V_282 , char T_4 * V_3 , T_5 V_299 ,
T_6 * V_300 )
{
struct V_284 * V_285 = V_282 -> V_289 ;
struct V_26 * V_27 = (struct V_26 * ) V_285 -> V_283 ;
char * V_368 ;
int V_439 , V_286 , V_462 , V_7 = 0 ;
struct V_427 * V_428 = NULL ;
if ( ! V_285 -> V_12 )
V_285 -> V_12 = F_2 ( V_430 , V_14 ) ;
if ( ! V_285 -> V_12 )
return 0 ;
V_368 = V_285 -> V_12 ;
V_439 = V_430 - 256 ;
if ( * V_300 )
return 0 ;
F_8 ( & V_27 -> V_49 ) ;
if ( V_27 -> V_201 . V_463 && V_27 -> V_464 ) {
V_462 = V_27 -> V_465 ;
if ( V_27 -> V_466 && ( V_462 >= V_27 -> V_464 ) ) {
V_27 -> V_465 = 0 ;
goto V_467;
}
V_27 -> V_465 ++ ;
if ( V_27 -> V_465 >= V_27 -> V_464 )
if ( V_27 -> V_466 == 0 )
V_27 -> V_465 = 0 ;
V_7 += snprintf ( V_368 + V_7 , V_430 - V_7 ,
L_189 ,
V_462 , V_27 -> V_464 ) ;
V_428 = V_27 -> V_201 . V_463 [ V_462 ] ;
if ( ! V_428 )
goto V_262;
V_7 = F_93 ( V_428 , L_190 , V_368 , V_7 ) ;
V_428 -> V_468 = 0 ;
if ( V_7 >= V_439 )
goto V_469;
V_286 = F_92 ( V_27 , V_368 , & V_7 ,
V_439 , V_462 , V_428 -> V_434 ) ;
if ( V_286 )
goto V_469;
if ( V_462 )
goto V_262;
V_428 = V_27 -> V_201 . V_470 ;
V_7 = F_90 ( V_428 , L_191 , V_368 , V_7 ) ;
if ( V_7 >= V_439 )
goto V_469;
V_428 = V_27 -> V_201 . V_471 ;
V_7 = F_88 ( V_428 , L_191 , V_368 , V_7 ) ;
if ( V_7 >= V_439 )
goto V_469;
V_428 = V_27 -> V_201 . V_472 ;
V_7 = F_90 ( V_428 , L_192 , V_368 , V_7 ) ;
if ( V_428 )
V_428 -> V_454 = 0 ;
if ( V_7 >= V_439 )
goto V_469;
V_428 = V_27 -> V_201 . V_473 ;
V_7 = F_88 ( V_428 , L_192 , V_368 , V_7 ) ;
if ( V_7 >= V_439 )
goto V_469;
V_428 = V_27 -> V_201 . V_474 ;
V_7 = F_90 ( V_428 , L_193 ,
V_368 , V_7 ) ;
if ( V_428 )
V_428 -> V_454 = 0 ;
if ( V_7 >= V_439 )
goto V_469;
V_428 = V_27 -> V_201 . V_475 ;
V_7 = F_88 ( V_428 , L_193 ,
V_368 , V_7 ) ;
if ( V_7 >= V_439 )
goto V_469;
V_428 = V_27 -> V_201 . V_476 ;
V_7 = F_91 ( V_428 , V_27 -> V_201 . V_477 ,
L_194 , V_368 , V_7 ) ;
if ( V_7 >= V_439 )
goto V_469;
goto V_262;
}
V_467:
if ( V_27 -> V_466 ) {
V_428 = V_27 -> V_201 . V_478 ;
V_7 = F_93 ( V_428 , L_195 , V_368 , V_7 ) ;
if ( V_428 )
V_428 -> V_468 = 0 ;
if ( V_7 >= V_439 )
goto V_469;
V_428 = V_27 -> V_201 . V_479 ;
V_7 = F_90 ( V_428 , L_196 , V_368 , V_7 ) ;
if ( V_428 )
V_428 -> V_454 = 0 ;
if ( V_7 >= V_439 )
goto V_469;
V_428 = V_27 -> V_201 . V_480 ;
V_7 = F_88 ( V_428 , L_196 , V_368 , V_7 ) ;
if ( V_7 >= V_439 )
goto V_469;
}
F_13 ( & V_27 -> V_49 ) ;
return F_48 ( V_3 , V_299 , V_300 , V_368 , V_7 ) ;
V_469:
V_7 += snprintf ( V_368 + V_7 ,
V_430 - V_7 , L_197 ) ;
V_262:
F_13 ( & V_27 -> V_49 ) ;
return F_48 ( V_3 , V_299 , V_300 , V_368 , V_7 ) ;
}
static int
F_95 ( struct V_427 * V_481 , int V_6 , int V_367 )
{
if ( ( V_367 != 1 ) && ( V_367 != V_482 ) )
return - V_341 ;
if ( V_6 > V_481 -> V_59 - 1 )
return - V_341 ;
return 0 ;
}
static int
F_96 ( char * V_368 , int V_7 , struct V_427 * V_483 ,
T_1 V_6 )
{
int V_364 , V_484 ;
T_1 * V_485 ;
if ( ! V_368 || ! V_483 )
return 0 ;
V_484 = V_483 -> V_435 ;
V_7 += snprintf ( V_368 + V_7 , V_486 - V_7 ,
L_198 , V_6 ) ;
V_364 = 0 ;
V_485 = V_483 -> V_487 [ V_6 ] . V_488 ;
while ( V_484 > 0 ) {
V_7 += snprintf ( V_368 + V_7 , V_486 - V_7 ,
L_164 , * V_485 ) ;
V_485 ++ ;
V_364 += sizeof( T_1 ) ;
V_484 -= sizeof( T_1 ) ;
if ( V_484 > 0 && ! ( V_364 % ( 4 * sizeof( T_1 ) ) ) )
V_7 += snprintf ( V_368 + V_7 ,
V_486 - V_7 , L_46 ) ;
}
V_7 += snprintf ( V_368 + V_7 , V_486 - V_7 , L_46 ) ;
return V_7 ;
}
static T_3
F_97 ( struct V_282 * V_282 , char T_4 * V_3 , T_5 V_299 ,
T_6 * V_300 )
{
struct V_284 * V_285 = V_282 -> V_289 ;
T_1 V_489 , V_6 , V_367 ;
struct V_427 * V_483 = NULL ;
char * V_368 ;
int V_7 = 0 ;
V_285 -> V_353 = V_375 ;
if ( ! V_285 -> V_12 )
V_285 -> V_12 = F_2 ( V_486 , V_14 ) ;
if ( ! V_285 -> V_12 )
return 0 ;
V_368 = V_285 -> V_12 ;
if ( * V_300 )
return 0 ;
if ( V_355 . V_356 . V_350 == V_490 ) {
V_6 = V_355 . V_356 . V_352 [ V_491 ] ;
V_367 = V_355 . V_356 . V_352 [ V_492 ] ;
V_483 = (struct V_427 * ) V_355 . V_493 ;
} else
return 0 ;
if ( V_367 == V_482 )
goto V_494;
V_7 = F_96 ( V_368 , V_7 , V_483 , V_6 ) ;
return F_48 ( V_3 , V_299 , V_300 , V_368 , V_7 ) ;
V_494:
V_489 = V_355 . V_364 . V_385 ;
V_6 = V_489 ;
while ( V_7 < V_495 - V_483 -> V_435 ) {
V_7 = F_96 ( V_368 , V_7 , V_483 , V_6 ) ;
V_6 ++ ;
if ( V_6 > V_483 -> V_59 - 1 )
break;
}
if ( V_6 > V_483 -> V_59 - 1 )
V_6 = 0 ;
V_355 . V_364 . V_385 = V_6 ;
return F_48 ( V_3 , V_299 , V_300 , V_368 , V_7 ) ;
}
static T_3
F_98 ( struct V_282 * V_282 , const char T_4 * V_3 ,
T_5 V_299 , T_6 * V_300 )
{
struct V_284 * V_285 = V_282 -> V_289 ;
struct V_26 * V_27 = (struct V_26 * ) V_285 -> V_283 ;
T_1 V_441 , V_496 , V_497 , V_6 , V_367 , V_364 , V_386 ;
T_1 * V_485 ;
struct V_427 * V_483 , * V_428 ;
int V_286 ;
V_285 -> V_353 = V_354 ;
V_286 = F_69 ( V_3 , V_299 , & V_355 . V_356 ) ;
if ( V_286 < 0 )
return V_286 ;
V_496 = V_355 . V_356 . V_352 [ V_498 ] ;
V_497 = V_355 . V_356 . V_352 [ V_499 ] ;
V_6 = V_355 . V_356 . V_352 [ V_491 ] ;
V_367 = V_355 . V_356 . V_352 [ V_492 ] ;
V_364 = V_355 . V_356 . V_352 [ V_500 ] ;
V_386 = V_355 . V_356 . V_352 [ V_501 ] ;
if ( V_355 . V_356 . V_350 == V_360 ||
V_355 . V_356 . V_350 == V_361 ||
V_355 . V_356 . V_350 == V_362 ) {
if ( V_286 != V_502 )
goto V_388;
if ( V_367 != 1 )
goto V_388;
} else if ( V_355 . V_356 . V_350 == V_490 ) {
if ( V_286 != V_503 )
goto V_388;
} else
goto V_388;
switch ( V_496 ) {
case V_504 :
if ( V_27 -> V_201 . V_463 ) {
for ( V_441 = 0 ; V_441 < V_27 -> V_464 ; V_441 ++ ) {
V_428 = V_27 -> V_201 . V_463 [ V_441 ] ;
if ( V_428 && V_428 -> V_434 == V_497 ) {
V_286 = F_95 ( V_428 ,
V_6 , V_367 ) ;
if ( V_286 )
goto V_388;
V_355 . V_493 = V_428 ;
goto V_505;
}
}
}
goto V_388;
break;
case V_506 :
if ( V_27 -> V_201 . V_470 &&
V_27 -> V_201 . V_470 -> V_434 == V_497 ) {
V_286 = F_95 (
V_27 -> V_201 . V_470 , V_6 , V_367 ) ;
if ( V_286 )
goto V_388;
V_355 . V_493 = V_27 -> V_201 . V_470 ;
goto V_505;
}
if ( V_27 -> V_201 . V_472 &&
V_27 -> V_201 . V_472 -> V_434 == V_497 ) {
V_286 = F_95 (
V_27 -> V_201 . V_472 , V_6 , V_367 ) ;
if ( V_286 )
goto V_388;
V_355 . V_493 = V_27 -> V_201 . V_472 ;
goto V_505;
}
if ( V_27 -> V_201 . V_474 &&
V_27 -> V_201 . V_474 -> V_434 == V_497 ) {
V_286 = F_95 (
V_27 -> V_201 . V_474 , V_6 , V_367 ) ;
if ( V_286 )
goto V_388;
V_355 . V_493 = V_27 -> V_201 . V_474 ;
goto V_505;
}
if ( V_27 -> V_201 . V_453 ) {
for ( V_441 = 0 ; V_441 < V_27 -> V_442 ;
V_441 ++ ) {
V_428 = V_27 -> V_201 . V_453 [ V_441 ] ;
if ( V_428 && V_428 -> V_434 == V_497 ) {
V_286 = F_95 (
V_428 , V_6 , V_367 ) ;
if ( V_286 )
goto V_388;
V_355 . V_493 = V_428 ;
goto V_505;
}
}
}
if ( V_27 -> V_201 . V_455 ) {
V_441 = 0 ;
do {
if ( V_27 -> V_201 . V_455 [ V_441 ] &&
V_27 -> V_201 . V_455 [ V_441 ] -> V_434 ==
V_497 ) {
V_286 = F_95 (
V_27 -> V_201 . V_455 [ V_441 ] ,
V_6 , V_367 ) ;
if ( V_286 )
goto V_388;
V_355 . V_493 =
V_27 -> V_201 . V_455 [ V_441 ] ;
goto V_505;
}
} while ( ++ V_441 < V_27 -> V_444 );
}
goto V_388;
break;
case V_507 :
if ( V_27 -> V_201 . V_471 &&
V_27 -> V_201 . V_471 -> V_434 == V_497 ) {
V_286 = F_95 (
V_27 -> V_201 . V_471 , V_6 , V_367 ) ;
if ( V_286 )
goto V_388;
V_355 . V_493 = V_27 -> V_201 . V_471 ;
goto V_505;
}
goto V_388;
break;
case V_508 :
if ( V_27 -> V_201 . V_473 &&
V_27 -> V_201 . V_473 -> V_434 == V_497 ) {
V_286 = F_95 (
V_27 -> V_201 . V_473 , V_6 , V_367 ) ;
if ( V_286 )
goto V_388;
V_355 . V_493 = V_27 -> V_201 . V_473 ;
goto V_505;
}
if ( V_27 -> V_201 . V_475 &&
V_27 -> V_201 . V_475 -> V_434 == V_497 ) {
V_286 = F_95 (
V_27 -> V_201 . V_475 , V_6 , V_367 ) ;
if ( V_286 )
goto V_388;
V_355 . V_493 = V_27 -> V_201 . V_475 ;
goto V_505;
}
if ( V_27 -> V_201 . V_443 ) {
for ( V_441 = 0 ; V_441 < V_27 -> V_442 ;
V_441 ++ ) {
V_428 = V_27 -> V_201 . V_443 [ V_441 ] ;
if ( V_428 && V_428 -> V_434 == V_497 ) {
V_286 = F_95 (
V_428 , V_6 , V_367 ) ;
if ( V_286 )
goto V_388;
V_355 . V_493 = V_428 ;
goto V_505;
}
}
}
if ( V_27 -> V_201 . V_445 ) {
for ( V_441 = 0 ; V_441 < V_27 -> V_444 ;
V_441 ++ ) {
V_428 = V_27 -> V_201 . V_445 [ V_441 ] ;
if ( V_428 && V_428 -> V_434 == V_497 ) {
V_286 = F_95 (
V_428 , V_6 , V_367 ) ;
if ( V_286 )
goto V_388;
V_355 . V_493 = V_428 ;
goto V_505;
}
}
}
if ( V_27 -> V_201 . V_445 ) {
for ( V_441 = 0 ; V_441 < V_27 -> V_444 ;
V_441 ++ ) {
if ( ! V_27 -> V_201 . V_445 [ V_441 ] )
continue;
if ( V_27 -> V_201 . V_445 [ V_441 ] -> V_434 ==
V_497 ) {
V_286 = F_95 (
V_27 -> V_201 . V_445 [ V_441 ] ,
V_6 , V_367 ) ;
if ( V_286 )
goto V_388;
V_355 . V_493 =
V_27 -> V_201 . V_445 [ V_441 ] ;
goto V_505;
}
}
}
goto V_388;
break;
case V_509 :
if ( V_27 -> V_201 . V_476 &&
V_27 -> V_201 . V_476 -> V_434 == V_497 ) {
V_286 = F_95 (
V_27 -> V_201 . V_476 , V_6 , V_367 ) ;
if ( V_286 )
goto V_388;
V_355 . V_493 = V_27 -> V_201 . V_476 ;
goto V_505;
}
if ( V_27 -> V_201 . V_477 &&
V_27 -> V_201 . V_477 -> V_434 == V_497 ) {
V_286 = F_95 (
V_27 -> V_201 . V_477 , V_6 , V_367 ) ;
if ( V_286 )
goto V_388;
V_355 . V_493 = V_27 -> V_201 . V_477 ;
goto V_505;
}
goto V_388;
break;
default:
goto V_388;
break;
}
V_505:
if ( V_355 . V_356 . V_350 == V_490 ) {
if ( V_367 == V_482 )
V_355 . V_364 . V_385 = V_6 ;
}
if ( V_355 . V_356 . V_350 == V_360 ||
V_355 . V_356 . V_350 == V_361 ||
V_355 . V_356 . V_350 == V_362 ) {
V_483 = (struct V_427 * ) V_355 . V_493 ;
if ( V_364 > V_483 -> V_435 / sizeof( T_1 ) - 1 )
goto V_388;
V_485 = V_483 -> V_487 [ V_6 ] . V_488 ;
V_485 += V_364 ;
if ( V_355 . V_356 . V_350 == V_360 )
* V_485 = V_386 ;
if ( V_355 . V_356 . V_350 == V_361 )
* V_485 |= V_386 ;
if ( V_355 . V_356 . V_350 == V_362 )
* V_485 &= ~ V_386 ;
}
return V_299 ;
V_388:
memset ( & V_355 , 0 , sizeof( V_355 ) ) ;
return - V_341 ;
}
static int
F_99 ( struct V_26 * V_27 , char * V_368 ,
int V_7 , T_1 V_510 )
{
if ( ! V_368 )
return 0 ;
switch ( V_510 ) {
case V_511 :
V_7 += snprintf ( V_368 + V_7 , V_512 - V_7 ,
L_199 ,
F_17 ( V_27 -> V_201 . V_513 ) ) ;
break;
case V_514 :
V_7 += snprintf ( V_368 + V_7 , V_512 - V_7 ,
L_200 ,
F_17 ( V_27 -> V_201 . V_515 ) ) ;
break;
case V_516 :
V_7 += snprintf ( V_368 + V_7 , V_512 - V_7 ,
L_201 ,
F_17 ( V_27 -> V_201 . V_517 ) ) ;
break;
case V_518 :
V_7 += snprintf ( V_368 + V_7 , V_512 - V_7 ,
L_202 ,
F_17 ( V_27 -> V_201 . V_519 ) ) ;
break;
default:
break;
}
return V_7 ;
}
static T_3
F_100 ( struct V_282 * V_282 , char T_4 * V_3 , T_5 V_299 ,
T_6 * V_300 )
{
struct V_284 * V_285 = V_282 -> V_289 ;
struct V_26 * V_27 = (struct V_26 * ) V_285 -> V_283 ;
T_1 V_520 , V_5 ;
char * V_368 ;
int V_7 = 0 ;
V_285 -> V_353 = V_375 ;
if ( ! V_285 -> V_12 )
V_285 -> V_12 = F_2 ( V_512 , V_14 ) ;
if ( ! V_285 -> V_12 )
return 0 ;
V_368 = V_285 -> V_12 ;
if ( * V_300 )
return 0 ;
if ( V_355 . V_356 . V_350 == V_521 )
V_520 = V_355 . V_356 . V_352 [ V_522 ] ;
else
return 0 ;
if ( V_520 == V_523 )
for ( V_5 = 1 ; V_5 <= V_524 ; V_5 ++ )
V_7 = F_99 ( V_27 ,
V_368 , V_7 , V_5 ) ;
else
V_7 = F_99 ( V_27 ,
V_368 , V_7 , V_520 ) ;
return F_48 ( V_3 , V_299 , V_300 , V_368 , V_7 ) ;
}
static T_3
F_101 ( struct V_282 * V_282 , const char T_4 * V_3 ,
T_5 V_299 , T_6 * V_300 )
{
struct V_284 * V_285 = V_282 -> V_289 ;
struct V_26 * V_27 = (struct V_26 * ) V_285 -> V_283 ;
T_1 V_520 , V_386 , V_525 = 0 ;
void T_8 * V_526 ;
int V_286 ;
V_285 -> V_353 = V_354 ;
V_286 = F_69 ( V_3 , V_299 , & V_355 . V_356 ) ;
if ( V_286 < 0 )
return V_286 ;
V_520 = V_355 . V_356 . V_352 [ V_522 ] ;
V_386 = V_355 . V_356 . V_352 [ V_527 ] ;
if ( V_355 . V_356 . V_350 == V_528 ||
V_355 . V_356 . V_350 == V_529 ||
V_355 . V_356 . V_350 == V_530 ) {
if ( V_286 != V_531 )
goto V_388;
if ( V_520 > V_524 )
goto V_388;
} else if ( V_355 . V_356 . V_350 == V_521 ) {
if ( V_286 != V_532 )
goto V_388;
if ( ( V_520 > V_524 ) &&
( V_520 != V_523 ) )
goto V_388;
} else
goto V_388;
if ( V_355 . V_356 . V_350 == V_528 ||
V_355 . V_356 . V_350 == V_529 ||
V_355 . V_356 . V_350 == V_530 ) {
switch ( V_520 ) {
case V_511 :
V_526 = V_27 -> V_201 . V_513 ;
break;
case V_514 :
V_526 = V_27 -> V_201 . V_515 ;
break;
case V_516 :
V_526 = V_27 -> V_201 . V_517 ;
break;
case V_518 :
V_526 = V_27 -> V_201 . V_519 ;
break;
default:
goto V_388;
}
if ( V_355 . V_356 . V_350 == V_528 )
V_525 = V_386 ;
if ( V_355 . V_356 . V_350 == V_529 ) {
V_525 = F_17 ( V_526 ) ;
V_525 |= V_386 ;
}
if ( V_355 . V_356 . V_350 == V_530 ) {
V_525 = F_17 ( V_526 ) ;
V_525 &= ~ V_386 ;
}
F_87 ( V_525 , V_526 ) ;
F_17 ( V_526 ) ;
}
return V_299 ;
V_388:
memset ( & V_355 , 0 , sizeof( V_355 ) ) ;
return - V_341 ;
}
static int
F_102 ( struct V_26 * V_27 , char * V_368 ,
int V_7 , T_1 V_533 )
{
if ( ! V_368 )
return 0 ;
switch ( V_533 ) {
case V_534 :
V_7 += snprintf ( V_368 + V_7 , V_535 - V_7 ,
L_203 ,
F_17 ( V_27 -> V_201 . V_407 +
V_536 ) ) ;
break;
case V_537 :
V_7 += snprintf ( V_368 + V_7 , V_535 - V_7 ,
L_204 ,
F_17 ( V_27 -> V_201 . V_407 +
V_538 ) ) ;
break;
case V_539 :
V_7 += snprintf ( V_368 + V_7 , V_535 - V_7 ,
L_205 ,
F_17 ( V_27 -> V_201 . V_407 +
V_540 ) ) ;
break;
case V_541 :
V_7 += snprintf ( V_368 + V_7 , V_535 - V_7 ,
L_206 ,
F_17 ( V_27 -> V_201 . V_407 +
V_542 ) ) ;
break;
case V_543 :
V_7 += snprintf ( V_368 + V_7 , V_535 - V_7 ,
L_207 ,
F_17 ( V_27 -> V_201 . V_407 +
V_544 ) ) ;
break;
case V_545 :
V_7 += snprintf ( V_368 + V_7 , V_535 - V_7 ,
L_208 ,
F_17 ( V_27 -> V_201 . V_407 +
V_546 ) ) ;
break;
default:
break;
}
return V_7 ;
}
static T_3
F_103 ( struct V_282 * V_282 , char T_4 * V_3 , T_5 V_299 ,
T_6 * V_300 )
{
struct V_284 * V_285 = V_282 -> V_289 ;
struct V_26 * V_27 = (struct V_26 * ) V_285 -> V_283 ;
T_1 V_547 , V_5 ;
char * V_368 ;
int V_7 = 0 ;
V_285 -> V_353 = V_375 ;
if ( ! V_285 -> V_12 )
V_285 -> V_12 = F_2 ( V_535 , V_14 ) ;
if ( ! V_285 -> V_12 )
return 0 ;
V_368 = V_285 -> V_12 ;
if ( * V_300 )
return 0 ;
if ( V_355 . V_356 . V_350 == V_548 )
V_547 = V_355 . V_356 . V_352 [ V_549 ] ;
else
return 0 ;
if ( V_547 == V_550 )
for ( V_5 = 1 ; V_5 <= V_551 ; V_5 ++ )
V_7 = F_102 ( V_27 ,
V_368 , V_7 , V_5 ) ;
else
V_7 = F_102 ( V_27 ,
V_368 , V_7 , V_547 ) ;
return F_48 ( V_3 , V_299 , V_300 , V_368 , V_7 ) ;
}
static T_3
F_104 ( struct V_282 * V_282 , const char T_4 * V_3 ,
T_5 V_299 , T_6 * V_300 )
{
struct V_284 * V_285 = V_282 -> V_289 ;
struct V_26 * V_27 = (struct V_26 * ) V_285 -> V_283 ;
T_1 V_547 , V_386 , V_525 = 0 ;
void T_8 * V_552 ;
int V_286 ;
V_285 -> V_353 = V_354 ;
V_286 = F_69 ( V_3 , V_299 , & V_355 . V_356 ) ;
if ( V_286 < 0 )
return V_286 ;
V_547 = V_355 . V_356 . V_352 [ V_549 ] ;
V_386 = V_355 . V_356 . V_352 [ V_553 ] ;
if ( V_355 . V_356 . V_350 == V_554 ||
V_355 . V_356 . V_350 == V_555 ||
V_355 . V_356 . V_350 == V_556 ) {
if ( V_286 != V_557 )
goto V_388;
if ( V_547 > V_551 )
goto V_388;
} else if ( V_355 . V_356 . V_350 == V_548 ) {
if ( V_286 != V_558 )
goto V_388;
if ( ( V_547 > V_551 ) &&
( V_547 != V_550 ) )
goto V_388;
} else
goto V_388;
if ( V_355 . V_356 . V_350 == V_554 ||
V_355 . V_356 . V_350 == V_555 ||
V_355 . V_356 . V_350 == V_556 ) {
switch ( V_547 ) {
case V_534 :
V_552 = V_27 -> V_201 . V_407 +
V_536 ;
break;
case V_537 :
V_552 = V_27 -> V_201 . V_407 +
V_538 ;
break;
case V_539 :
V_552 = V_27 -> V_201 . V_407 +
V_540 ;
break;
case V_541 :
V_552 = V_27 -> V_201 . V_407 +
V_542 ;
break;
case V_543 :
V_552 = V_27 -> V_201 . V_407 +
V_544 ;
break;
case V_545 :
V_552 = V_27 -> V_201 . V_407 +
V_546 ;
break;
default:
goto V_388;
}
if ( V_355 . V_356 . V_350 == V_554 )
V_525 = V_386 ;
if ( V_355 . V_356 . V_350 == V_555 ) {
V_525 = F_17 ( V_552 ) ;
V_525 |= V_386 ;
}
if ( V_355 . V_356 . V_350 == V_556 ) {
V_525 = F_17 ( V_552 ) ;
V_525 &= ~ V_386 ;
}
F_87 ( V_525 , V_552 ) ;
F_17 ( V_552 ) ;
}
return V_299 ;
V_388:
memset ( & V_355 , 0 , sizeof( V_355 ) ) ;
return - V_341 ;
}
static int
F_105 ( struct V_26 * V_27 , char * V_368 )
{
T_1 V_559 , V_560 , V_561 , V_562 ;
int V_7 = 0 ;
V_562 = V_355 . V_356 . V_352 [ V_563 ] ;
V_559 = V_355 . V_356 . V_352 [ V_564 ] ;
V_560 = V_355 . V_356 . V_352 [ V_565 ] ;
V_561 = V_355 . V_356 . V_352 [ V_566 ] ;
V_7 += snprintf ( V_368 + V_7 , V_567 - V_7 ,
L_209 , V_559 ) ;
V_7 += snprintf ( V_368 + V_7 , V_567 - V_7 ,
L_210 , V_560 ) ;
V_7 += snprintf ( V_368 + V_7 , V_567 - V_7 ,
L_211 , V_561 ) ;
V_7 += snprintf ( V_368 + V_7 , V_567 - V_7 ,
L_212 , V_562 ) ;
return V_7 ;
}
static T_3
F_106 ( struct V_282 * V_282 , char T_4 * V_3 , T_5 V_299 ,
T_6 * V_300 )
{
struct V_284 * V_285 = V_282 -> V_289 ;
struct V_26 * V_27 = (struct V_26 * ) V_285 -> V_283 ;
char * V_368 ;
int V_7 = 0 ;
V_285 -> V_353 = V_375 ;
if ( ! V_285 -> V_12 )
V_285 -> V_12 = F_2 ( V_567 , V_14 ) ;
if ( ! V_285 -> V_12 )
return 0 ;
V_368 = V_285 -> V_12 ;
if ( * V_300 )
return 0 ;
if ( ( V_355 . V_356 . V_350 != V_568 ) &&
( V_355 . V_356 . V_350 != V_569 ) )
return 0 ;
V_7 = F_105 ( V_27 , V_368 ) ;
return F_48 ( V_3 , V_299 , V_300 , V_368 , V_7 ) ;
}
static T_3
F_107 ( struct V_282 * V_282 , const char T_4 * V_3 ,
T_5 V_299 , T_6 * V_300 )
{
struct V_284 * V_285 = V_282 -> V_289 ;
T_1 V_559 , V_560 , V_561 , V_562 ;
int V_286 ;
V_285 -> V_353 = V_354 ;
V_286 = F_69 ( V_3 , V_299 , & V_355 . V_356 ) ;
if ( V_286 < 0 )
return V_286 ;
V_562 = V_355 . V_356 . V_352 [ V_563 ] ;
V_559 = V_355 . V_356 . V_352 [ V_564 ] ;
V_560 = V_355 . V_356 . V_352 [ V_565 ] ;
V_561 = V_355 . V_356 . V_352 [ V_566 ] ;
if ( V_355 . V_356 . V_350 == V_568 ) {
if ( ! ( V_559 & V_570 ) )
goto V_388;
if ( ( V_559 & ~ V_570 ) &&
( V_559 != V_571 ) )
goto V_388;
if ( V_561 > sizeof( V_91 ) )
goto V_388;
} else if ( V_355 . V_356 . V_350 == V_569 ) {
if ( ! ( V_559 & V_572 ) )
goto V_388;
if ( ( V_559 & ~ V_572 ) &&
( V_559 != V_571 ) )
goto V_388;
if ( V_561 > ( V_573 ) / 4 )
goto V_388;
if ( V_562 != 0x9b )
goto V_388;
} else
goto V_388;
if ( V_561 == 0 )
goto V_388;
if ( V_286 != V_574 )
goto V_388;
if ( V_562 & ~ 0xff )
goto V_388;
if ( V_560 == 0 )
goto V_575;
return V_299 ;
V_575:
memset ( & V_355 , 0 , sizeof( V_355 ) ) ;
return V_299 ;
V_388:
memset ( & V_355 , 0 , sizeof( V_355 ) ) ;
return - V_341 ;
}
static int
F_108 ( struct V_26 * V_27 , char * V_368 , int V_7 )
{
T_2 V_576 , V_577 ;
V_7 += snprintf ( V_368 + V_7 , V_578 - V_7 ,
L_213 ) ;
V_7 += snprintf ( V_368 + V_7 , V_578 - V_7 ,
L_214 ) ;
F_109 ( V_27 , V_579 ,
& V_576 , & V_577 ) ;
V_7 += snprintf ( V_368 + V_7 , V_578 - V_7 ,
L_215 , V_576 , V_577 ) ;
V_7 += snprintf ( V_368 + V_7 , V_578 - V_7 ,
L_216 ) ;
F_109 ( V_27 , V_580 ,
& V_576 , & V_577 ) ;
V_7 += snprintf ( V_368 + V_7 , V_578 - V_7 ,
L_215 , V_576 , V_577 ) ;
V_7 += snprintf ( V_368 + V_7 , V_578 - V_7 ,
L_217 ) ;
F_109 ( V_27 , V_581 ,
& V_576 , & V_577 ) ;
V_7 += snprintf ( V_368 + V_7 , V_578 - V_7 ,
L_215 , V_576 , V_577 ) ;
V_7 += snprintf ( V_368 + V_7 , V_578 - V_7 ,
L_218 ) ;
F_109 ( V_27 , V_582 ,
& V_576 , & V_577 ) ;
V_7 += snprintf ( V_368 + V_7 , V_578 - V_7 ,
L_215 , V_576 , V_577 ) ;
return V_7 ;
}
static int
F_110 ( struct V_26 * V_27 , char * V_368 , int V_7 )
{
T_2 V_576 , V_577 ;
int V_286 ;
V_7 += snprintf ( V_368 + V_7 , V_578 - V_7 ,
L_219 ) ;
V_7 += snprintf ( V_368 + V_7 , V_578 - V_7 ,
L_220 ) ;
V_286 = F_111 ( V_27 , V_579 ,
& V_576 , & V_577 ) ;
if ( ! V_286 )
V_7 += snprintf ( V_368 + V_7 , V_578 - V_7 ,
L_221 ,
V_27 -> V_583 , V_576 , V_577 ) ;
else
V_7 += snprintf ( V_368 + V_7 , V_578 - V_7 ,
L_222 ) ;
V_7 += snprintf ( V_368 + V_7 , V_578 - V_7 ,
L_223 ) ;
V_286 = F_111 ( V_27 , V_580 ,
& V_576 , & V_577 ) ;
if ( ! V_286 )
V_7 += snprintf ( V_368 + V_7 , V_578 - V_7 ,
L_221 ,
V_27 -> V_583 , V_576 , V_577 ) ;
else
V_7 += snprintf ( V_368 + V_7 , V_578 - V_7 ,
L_222 ) ;
V_7 += snprintf ( V_368 + V_7 , V_578 - V_7 ,
L_224 ) ;
V_286 = F_111 ( V_27 , V_581 ,
& V_576 , & V_577 ) ;
if ( ! V_286 )
V_7 += snprintf ( V_368 + V_7 , V_578 - V_7 ,
L_221 ,
V_27 -> V_583 , V_576 , V_577 ) ;
else
V_7 += snprintf ( V_368 + V_7 , V_578 - V_7 ,
L_222 ) ;
V_7 += snprintf ( V_368 + V_7 , V_578 - V_7 ,
L_225 ) ;
V_286 = F_111 ( V_27 , V_582 ,
& V_576 , & V_577 ) ;
if ( ! V_286 )
V_7 += snprintf ( V_368 + V_7 , V_578 - V_7 ,
L_221 ,
V_27 -> V_583 , V_576 , V_577 ) ;
else
V_7 += snprintf ( V_368 + V_7 , V_578 - V_7 ,
L_222 ) ;
return V_7 ;
}
static int
F_112 ( struct V_26 * V_27 , char * V_368 , int V_7 )
{
struct V_584 * V_585 ;
int V_6 ;
V_7 += snprintf ( V_368 + V_7 , V_578 - V_7 ,
L_226 ) ;
V_7 += snprintf ( V_368 + V_7 , V_578 - V_7 ,
L_227 ) ;
V_6 = 0 ;
F_10 (rsrc_blks, &phba->lpfc_vpi_blk_list, list) {
V_7 += snprintf ( V_368 + V_7 , V_578 - V_7 ,
L_228 ,
V_6 , V_585 -> V_586 ,
V_585 -> V_587 ) ;
V_6 ++ ;
}
V_7 += snprintf ( V_368 + V_7 , V_578 - V_7 ,
L_229 ) ;
V_6 = 0 ;
F_10 (rsrc_blks, &phba->sli4_hba.lpfc_vfi_blk_list,
list) {
V_7 += snprintf ( V_368 + V_7 , V_578 - V_7 ,
L_228 ,
V_6 , V_585 -> V_586 ,
V_585 -> V_587 ) ;
V_6 ++ ;
}
V_7 += snprintf ( V_368 + V_7 , V_578 - V_7 ,
L_230 ) ;
V_6 = 0 ;
F_10 (rsrc_blks, &phba->sli4_hba.lpfc_rpi_blk_list,
list) {
V_7 += snprintf ( V_368 + V_7 , V_578 - V_7 ,
L_228 ,
V_6 , V_585 -> V_586 ,
V_585 -> V_587 ) ;
V_6 ++ ;
}
V_7 += snprintf ( V_368 + V_7 , V_578 - V_7 ,
L_231 ) ;
V_6 = 0 ;
F_10 (rsrc_blks, &phba->sli4_hba.lpfc_xri_blk_list,
list) {
V_7 += snprintf ( V_368 + V_7 , V_578 - V_7 ,
L_228 ,
V_6 , V_585 -> V_586 ,
V_585 -> V_587 ) ;
V_6 ++ ;
}
return V_7 ;
}
static T_3
F_113 ( struct V_282 * V_282 , const char T_4 * V_3 ,
T_5 V_299 , T_6 * V_300 )
{
struct V_284 * V_285 = V_282 -> V_289 ;
T_1 V_588 ;
int V_286 ;
V_285 -> V_353 = V_354 ;
V_286 = F_69 ( V_3 , V_299 , & V_355 . V_356 ) ;
if ( V_286 < 0 )
return V_286 ;
V_588 = V_355 . V_356 . V_352 [ V_589 ] ;
if ( V_355 . V_356 . V_350 != V_590 )
goto V_388;
if ( V_286 != V_591 )
goto V_388;
if ( ! ( V_588 & V_592 ) )
goto V_388;
return V_299 ;
V_388:
memset ( & V_355 , 0 , sizeof( V_355 ) ) ;
return - V_341 ;
}
static T_3
F_114 ( struct V_282 * V_282 , char T_4 * V_3 , T_5 V_299 ,
T_6 * V_300 )
{
struct V_284 * V_285 = V_282 -> V_289 ;
struct V_26 * V_27 = (struct V_26 * ) V_285 -> V_283 ;
char * V_368 ;
T_1 V_588 ;
int V_7 = 0 ;
V_285 -> V_353 = V_375 ;
if ( ! V_285 -> V_12 )
V_285 -> V_12 = F_2 ( V_578 , V_14 ) ;
if ( ! V_285 -> V_12 )
return 0 ;
V_368 = V_285 -> V_12 ;
if ( * V_300 )
return 0 ;
if ( V_355 . V_356 . V_350 != V_590 )
return 0 ;
V_588 = V_355 . V_356 . V_352 [ V_589 ] ;
if ( V_588 & V_593 )
V_7 = F_108 ( V_27 , V_368 , V_7 ) ;
if ( V_588 & V_594 )
V_7 = F_110 ( V_27 , V_368 , V_7 ) ;
if ( V_588 & V_595 )
V_7 = F_112 ( V_27 , V_368 , V_7 ) ;
return F_48 ( V_3 , V_299 , V_300 , V_368 , V_7 ) ;
}
void
F_115 ( struct V_26 * V_27 , enum V_596 V_597 ,
enum V_598 V_599 , enum V_600 V_601 ,
enum V_602 V_603 ,
struct V_44 * V_604 , T_1 V_605 )
{
#ifdef F_31
T_1 * V_562 , * V_559 , * V_560 , * V_561 ;
char V_606 [ V_607 ] ;
int V_7 = 0 ;
T_1 V_608 = 0 ;
T_1 * V_609 ;
T_1 V_5 ;
if ( V_355 . V_356 . V_350 != V_569 )
return;
V_562 = & V_355 . V_356 . V_352 [ V_563 ] ;
V_559 = & V_355 . V_356 . V_352 [ V_564 ] ;
V_560 = & V_355 . V_356 . V_352 [ V_565 ] ;
V_561 = & V_355 . V_356 . V_352 [ V_566 ] ;
if ( ! ( * V_559 & V_571 ) ||
( * V_560 == 0 ) ||
( * V_561 == 0 ) )
return;
if ( * V_562 != 0x9B )
return;
if ( ( V_599 == V_610 ) && ( V_601 == V_611 ) ) {
if ( * V_559 & V_612 ) {
V_608 |= V_612 ;
F_42 ( L_232
L_233 ,
V_603 , V_597 , V_605 ) ;
}
}
if ( ( V_599 == V_610 ) && ( V_601 == V_613 ) ) {
if ( * V_559 & V_614 ) {
V_608 |= V_614 ;
F_42 ( L_234
L_235 ,
V_603 , V_597 , V_605 ) ;
}
}
if ( ( V_599 == V_615 ) && ( V_601 == V_611 ) ) {
if ( * V_559 & V_616 ) {
V_608 |= V_616 ;
F_42 ( L_236
L_233 ,
V_603 , V_597 , V_605 ) ;
}
}
if ( ( V_599 == V_615 ) && ( V_601 == V_613 ) ) {
if ( * V_559 & V_617 ) {
V_608 |= V_617 ;
F_42 ( L_237
L_235 ,
V_603 , V_597 , V_605 ) ;
}
}
if ( V_608 ) {
V_609 = ( T_1 * ) V_604 -> V_72 ;
for ( V_5 = 0 ; V_5 < * V_561 ; V_5 ++ ) {
if ( ! ( V_5 % 8 ) ) {
if ( V_5 != 0 )
F_42 ( L_134 , V_606 ) ;
V_7 = 0 ;
V_7 += snprintf ( V_606 + V_7 ,
V_607 - V_7 ,
L_238 , V_5 ) ;
}
V_7 += snprintf ( V_606 + V_7 , V_607 - V_7 ,
L_164 , ( T_1 ) * V_609 ) ;
V_609 ++ ;
}
if ( ( V_5 - 1 ) % 8 )
F_42 ( L_134 , V_606 ) ;
( * V_560 ) -- ;
}
if ( * V_560 == 0 )
memset ( & V_355 , 0 , sizeof( V_355 ) ) ;
return;
#endif
}
void
F_116 ( struct V_26 * V_27 , V_91 * V_618 )
{
#ifdef F_31
T_1 * V_559 , * V_560 , * V_561 , * V_562 ;
char V_606 [ V_607 ] ;
int V_7 = 0 ;
T_1 * V_609 ;
T_7 * V_619 ;
T_1 V_5 , V_31 ;
if ( V_355 . V_356 . V_350 != V_568 )
return;
V_562 = & V_355 . V_356 . V_352 [ V_563 ] ;
V_559 = & V_355 . V_356 . V_352 [ V_564 ] ;
V_560 = & V_355 . V_356 . V_352 [ V_565 ] ;
V_561 = & V_355 . V_356 . V_352 [ V_566 ] ;
if ( ! ( * V_559 & V_570 ) ||
( * V_560 == 0 ) ||
( * V_561 == 0 ) )
return;
if ( ( * V_562 != V_620 ) &&
( * V_562 != V_618 -> V_621 ) )
return;
if ( * V_559 & V_622 ) {
F_42 ( L_239 ,
V_618 -> V_621 ) ;
V_609 = ( T_1 * ) V_618 ;
for ( V_5 = 0 ; V_5 < * V_561 ; V_5 ++ ) {
if ( ! ( V_5 % 8 ) ) {
if ( V_5 != 0 )
F_42 ( L_134 , V_606 ) ;
V_7 = 0 ;
memset ( V_606 , 0 , V_607 ) ;
V_7 += snprintf ( V_606 + V_7 ,
V_607 - V_7 ,
L_238 , V_5 ) ;
}
V_7 += snprintf ( V_606 + V_7 , V_607 - V_7 ,
L_164 ,
( ( T_1 ) * V_609 ) & 0xffffffff ) ;
V_609 ++ ;
}
if ( ( V_5 - 1 ) % 8 )
F_42 ( L_134 , V_606 ) ;
F_42 ( L_46 ) ;
}
if ( * V_559 & V_623 ) {
F_42 ( L_240 ,
V_618 -> V_621 ) ;
V_619 = ( T_7 * ) V_618 ;
for ( V_5 = 0 ; V_5 < * V_561 ; V_5 ++ ) {
if ( ! ( V_5 % 8 ) ) {
if ( V_5 != 0 )
F_42 ( L_134 , V_606 ) ;
V_7 = 0 ;
memset ( V_606 , 0 , V_607 ) ;
V_7 += snprintf ( V_606 + V_7 ,
V_607 - V_7 ,
L_238 , V_5 ) ;
}
for ( V_31 = 0 ; V_31 < 4 ; V_31 ++ ) {
V_7 += snprintf ( V_606 + V_7 ,
V_607 - V_7 ,
L_241 ,
( ( T_7 ) * V_619 ) & 0xff ) ;
V_619 ++ ;
}
V_7 += snprintf ( V_606 + V_7 ,
V_607 - V_7 , L_242 ) ;
}
if ( ( V_5 - 1 ) % 8 )
F_42 ( L_134 , V_606 ) ;
F_42 ( L_46 ) ;
}
( * V_560 ) -- ;
if ( * V_560 == 0 )
memset ( & V_355 , 0 , sizeof( V_355 ) ) ;
return;
#endif
}
inline void
F_117 ( struct V_1 * V_2 )
{
#ifdef F_31
struct V_26 * V_27 = V_2 -> V_27 ;
char V_624 [ 64 ] ;
T_1 V_625 , V_5 ;
bool V_626 = false ;
if ( ! V_15 )
return;
if ( ! V_627 ) {
V_627 = F_118 ( L_243 , NULL ) ;
F_61 ( & V_628 , 0 ) ;
if ( ! V_627 ) {
F_119 ( V_2 , V_328 , V_329 ,
L_244 ) ;
goto V_629;
}
}
if ( ! V_21 )
V_21 = V_280 ;
snprintf ( V_624 , sizeof( V_624 ) , L_245 , V_27 -> V_583 ) ;
if ( ! V_27 -> V_630 ) {
V_626 = true ;
V_27 -> V_630 =
F_118 ( V_624 , V_627 ) ;
if ( ! V_27 -> V_630 ) {
F_119 ( V_2 , V_328 , V_329 ,
L_246 ) ;
goto V_629;
}
F_120 ( & V_628 ) ;
F_61 ( & V_27 -> V_631 , 0 ) ;
snprintf ( V_624 , sizeof( V_624 ) , L_247 ) ;
V_27 -> V_632 =
F_121 ( V_624 , V_633 | V_634 | V_635 ,
V_27 -> V_630 ,
V_27 , & V_636 ) ;
if ( ! V_27 -> V_632 ) {
F_119 ( V_2 , V_328 , V_329 ,
L_248 ) ;
goto V_629;
}
if ( V_27 -> V_48 < V_637 ) {
snprintf ( V_624 , sizeof( V_624 ) , L_249 ) ;
V_27 -> V_638 =
F_121 ( V_624 ,
V_633 | V_634 | V_635 ,
V_27 -> V_630 ,
V_27 , & V_639 ) ;
if ( ! V_27 -> V_638 ) {
F_119 ( V_2 , V_328 , V_329 ,
L_250
L_251 ) ;
goto V_629;
}
} else
V_27 -> V_638 = NULL ;
if ( V_27 -> V_48 < V_637 ) {
snprintf ( V_624 , sizeof( V_624 ) , L_252 ) ;
V_27 -> V_640 =
F_121 ( V_624 ,
V_633 | V_634 | V_635 ,
V_27 -> V_630 ,
V_27 , & V_641 ) ;
if ( ! V_27 -> V_640 ) {
F_119 ( V_2 , V_328 , V_329 ,
L_253
L_254 ) ;
goto V_629;
}
} else
V_27 -> V_640 = NULL ;
snprintf ( V_624 , sizeof( V_624 ) , L_255 ) ;
V_27 -> V_642 =
F_121 ( V_624 , V_633 | V_634 | V_635 ,
V_27 -> V_630 ,
V_27 , & V_643 ) ;
if ( ! V_27 -> V_642 ) {
F_119 ( V_2 , V_328 , V_329 ,
L_256 ) ;
goto V_629;
}
snprintf ( V_624 , sizeof( V_624 ) , L_257 ) ;
V_27 -> V_644 =
F_121 ( V_624 , V_633 | V_634 | V_635 ,
V_27 -> V_630 ,
V_27 , & V_645 ) ;
if ( ! V_27 -> V_644 ) {
F_119 ( V_2 , V_328 , V_329 ,
L_258 ) ;
goto V_629;
}
snprintf ( V_624 , sizeof( V_624 ) , L_259 ) ;
V_27 -> V_325 =
F_121 ( V_624 , V_633 | V_634 | V_635 ,
V_27 -> V_630 ,
V_27 , & V_646 ) ;
if ( ! V_27 -> V_325 ) {
F_119 ( V_2 , V_328 , V_329 ,
L_260 ) ;
goto V_629;
}
V_27 -> V_326 = V_647 ;
snprintf ( V_624 , sizeof( V_624 ) , L_261 ) ;
V_27 -> V_320 =
F_121 ( V_624 , V_633 | V_634 | V_635 ,
V_27 -> V_630 ,
V_27 , & V_646 ) ;
if ( ! V_27 -> V_320 ) {
F_119 ( V_2 , V_328 , V_329 ,
L_262 ) ;
goto V_629;
}
snprintf ( V_624 , sizeof( V_624 ) , L_263 ) ;
V_27 -> V_322 =
F_121 ( V_624 , V_633 | V_634 | V_635 ,
V_27 -> V_630 ,
V_27 , & V_646 ) ;
if ( ! V_27 -> V_322 ) {
F_119 ( V_2 , V_328 , V_329 ,
L_264 ) ;
goto V_629;
}
snprintf ( V_624 , sizeof( V_624 ) , L_265 ) ;
V_27 -> V_308 =
F_121 ( V_624 , V_633 | V_634 | V_635 ,
V_27 -> V_630 ,
V_27 , & V_646 ) ;
if ( ! V_27 -> V_308 ) {
F_119 ( V_2 , V_328 , V_329 ,
L_266 ) ;
goto V_629;
}
snprintf ( V_624 , sizeof( V_624 ) , L_267 ) ;
V_27 -> V_310 =
F_121 ( V_624 , V_633 | V_634 | V_635 ,
V_27 -> V_630 ,
V_27 , & V_646 ) ;
if ( ! V_27 -> V_310 ) {
F_119 ( V_2 , V_328 , V_329 ,
L_268 ) ;
goto V_629;
}
snprintf ( V_624 , sizeof( V_624 ) , L_269 ) ;
V_27 -> V_312 =
F_121 ( V_624 , V_633 | V_634 | V_635 ,
V_27 -> V_630 ,
V_27 , & V_646 ) ;
if ( ! V_27 -> V_312 ) {
F_119 ( V_2 , V_328 , V_329 ,
L_270 ) ;
goto V_629;
}
snprintf ( V_624 , sizeof( V_624 ) , L_271 ) ;
V_27 -> V_314 =
F_121 ( V_624 , V_633 | V_634 | V_635 ,
V_27 -> V_630 ,
V_27 , & V_646 ) ;
if ( ! V_27 -> V_314 ) {
F_119 ( V_2 , V_328 , V_329 ,
L_272 ) ;
goto V_629;
}
snprintf ( V_624 , sizeof( V_624 ) , L_273 ) ;
V_27 -> V_316 =
F_121 ( V_624 , V_633 | V_634 | V_635 ,
V_27 -> V_630 ,
V_27 , & V_646 ) ;
if ( ! V_27 -> V_316 ) {
F_119 ( V_2 , V_328 , V_329 ,
L_274 ) ;
goto V_629;
}
snprintf ( V_624 , sizeof( V_624 ) , L_275 ) ;
V_27 -> V_318 =
F_121 ( V_624 , V_633 | V_634 | V_635 ,
V_27 -> V_630 ,
V_27 , & V_646 ) ;
if ( ! V_27 -> V_318 ) {
F_119 ( V_2 , V_328 , V_329 ,
L_276 ) ;
goto V_629;
}
if ( V_29 ) {
V_625 = V_29 - 1 ;
if ( V_625 & V_29 ) {
V_625 = V_29 ;
V_5 = 0 ;
while ( V_625 > 1 ) {
V_625 = V_625 >> 1 ;
V_5 ++ ;
}
V_29 = ( 1 << V_5 ) ;
F_42 ( L_277
L_278 , V_17 ) ;
}
}
snprintf ( V_624 , sizeof( V_624 ) , L_279 ) ;
V_27 -> V_648 =
F_121 ( V_624 , V_633 | V_634 | V_635 ,
V_27 -> V_630 ,
V_27 , & V_649 ) ;
if ( ! V_27 -> V_648 ) {
F_119 ( V_2 , V_328 , V_329 ,
L_280
L_281 ) ;
goto V_629;
}
if ( ! V_27 -> V_30 ) {
V_27 -> V_30 = F_2 (
( sizeof( struct V_10 ) *
V_29 ) ,
V_14 ) ;
if ( ! V_27 -> V_30 ) {
F_119 ( V_2 , V_328 , V_329 ,
L_282
L_283 ) ;
goto V_629;
}
F_61 ( & V_27 -> V_28 , 0 ) ;
memset ( V_27 -> V_30 , 0 ,
( sizeof( struct V_10 ) *
V_29 ) ) ;
}
snprintf ( V_624 , sizeof( V_624 ) , L_284 ) ;
V_27 -> V_650 =
F_121 ( V_624 , 0644 ,
V_27 -> V_630 ,
V_27 , & V_651 ) ;
if ( ! V_27 -> V_650 ) {
F_119 ( V_2 , V_328 , V_329 ,
L_285 ) ;
goto V_629;
}
F_61 ( & V_27 -> V_258 , 0 ) ;
if ( V_652 ) {
V_625 = V_652 - 1 ;
if ( V_625 & V_17 ) {
V_625 = V_652 ;
V_5 = 0 ;
while ( V_625 > 1 ) {
V_625 = V_625 >> 1 ;
V_5 ++ ;
}
V_652 = ( 1 << V_5 ) ;
F_47 ( V_27 , V_328 , V_329 ,
L_286
L_287 ,
V_652 ) ;
}
V_27 -> V_259 = V_652 ;
V_27 -> V_261 = F_2 (
( sizeof( struct V_255 ) *
V_27 -> V_259 ) , V_14 ) ;
if ( ! V_27 -> V_261 ) {
F_47 ( V_27 , V_328 , V_329 ,
L_288
L_157 ) ;
goto V_653;
}
memset ( V_27 -> V_261 , 0 ,
( sizeof( struct V_255 ) *
V_27 -> V_259 ) ) ;
V_27 -> V_257 = 1 ;
V_27 -> V_260 = 0 ;
V_27 -> V_261 = NULL ;
} else {
V_653:
V_27 -> V_259 = 0 ;
V_27 -> V_257 = 0 ;
V_27 -> V_260 = 0 ;
V_27 -> V_261 = NULL ;
}
}
snprintf ( V_624 , sizeof( V_624 ) , L_289 , V_2 -> V_654 ) ;
if ( ! V_2 -> V_655 ) {
V_2 -> V_655 =
F_118 ( V_624 , V_27 -> V_630 ) ;
if ( ! V_2 -> V_655 ) {
F_119 ( V_2 , V_328 , V_329 ,
L_290 ) ;
goto V_629;
}
F_120 ( & V_27 -> V_631 ) ;
}
if ( V_17 ) {
V_625 = V_17 - 1 ;
if ( V_625 & V_17 ) {
V_625 = V_17 ;
V_5 = 0 ;
while ( V_625 > 1 ) {
V_625 = V_625 >> 1 ;
V_5 ++ ;
}
V_17 = ( 1 << V_5 ) ;
F_42 ( L_291 ,
V_17 ) ;
}
}
V_2 -> V_18 = F_122 (
( sizeof( struct V_10 ) * V_17 ) ,
V_14 ) ;
if ( ! V_2 -> V_18 ) {
F_119 ( V_2 , V_328 , V_329 ,
L_292
L_293 ) ;
goto V_629;
}
F_61 ( & V_2 -> V_16 , 0 ) ;
snprintf ( V_624 , sizeof( V_624 ) , L_294 ) ;
V_2 -> V_656 =
F_121 ( V_624 , V_633 | V_634 | V_635 ,
V_2 -> V_655 ,
V_2 , & V_657 ) ;
if ( ! V_2 -> V_656 ) {
F_119 ( V_2 , V_328 , V_329 ,
L_295
L_296 ) ;
goto V_629;
}
snprintf ( V_624 , sizeof( V_624 ) , L_297 ) ;
V_2 -> V_658 =
F_121 ( V_624 , V_633 | V_634 | V_635 ,
V_2 -> V_655 ,
V_2 , & V_659 ) ;
if ( ! V_2 -> V_658 ) {
F_119 ( V_2 , V_328 , V_329 ,
L_298 ) ;
goto V_629;
}
snprintf ( V_624 , sizeof( V_624 ) , L_299 ) ;
V_2 -> V_660 =
F_121 ( V_624 , 0644 ,
V_2 -> V_655 ,
V_2 , & V_661 ) ;
if ( ! V_2 -> V_660 ) {
F_119 ( V_2 , V_328 , V_329 ,
L_300 ) ;
goto V_629;
}
snprintf ( V_624 , sizeof( V_624 ) , L_301 ) ;
V_2 -> V_662 =
F_121 ( V_624 , 0644 ,
V_2 -> V_655 ,
V_2 , & V_663 ) ;
if ( ! V_2 -> V_662 ) {
F_119 ( V_2 , V_328 , V_329 ,
L_302 ) ;
goto V_629;
}
snprintf ( V_624 , sizeof( V_624 ) , L_303 ) ;
V_2 -> V_664 =
F_121 ( V_624 , 0644 ,
V_2 -> V_655 ,
V_2 , & V_665 ) ;
if ( ! V_2 -> V_664 ) {
F_119 ( V_2 , V_328 , V_329 ,
L_304 ) ;
goto V_629;
}
if ( ! V_626 )
goto V_629;
if ( V_27 -> V_48 < V_637 )
goto V_629;
snprintf ( V_624 , sizeof( V_624 ) , L_305 ) ;
if ( ! V_27 -> V_666 ) {
V_27 -> V_666 =
F_118 ( V_624 , V_27 -> V_630 ) ;
if ( ! V_27 -> V_666 ) {
F_119 ( V_2 , V_328 , V_329 ,
L_306 ) ;
goto V_629;
}
memset ( & V_355 , 0 , sizeof( V_355 ) ) ;
}
snprintf ( V_624 , sizeof( V_624 ) , L_307 ) ;
if ( ! V_27 -> V_667 ) {
V_27 -> V_667 =
F_121 ( V_624 , V_633 | V_634 | V_635 ,
V_27 -> V_666 , V_27 , & V_668 ) ;
if ( ! V_27 -> V_667 ) {
F_119 ( V_2 , V_328 , V_329 ,
L_308 ) ;
goto V_629;
}
V_355 . V_364 . V_385 = 0 ;
}
snprintf ( V_624 , sizeof( V_624 ) , L_309 ) ;
if ( ! V_27 -> V_669 ) {
V_27 -> V_669 =
F_121 ( V_624 , V_633 | V_634 | V_635 ,
V_27 -> V_666 , V_27 , & V_670 ) ;
if ( ! V_27 -> V_669 ) {
F_119 ( V_2 , V_328 , V_329 ,
L_310 ) ;
goto V_629;
}
V_355 . V_364 . V_385 = 0 ;
}
snprintf ( V_624 , sizeof( V_624 ) , L_311 ) ;
if ( ! V_27 -> V_671 ) {
V_27 -> V_671 =
F_121 ( V_624 , V_633 | V_634 ,
V_27 -> V_666 , V_27 , & V_672 ) ;
if ( ! V_27 -> V_671 ) {
F_119 ( V_2 , V_328 , V_329 ,
L_312 ) ;
goto V_629;
}
}
snprintf ( V_624 , sizeof( V_624 ) , L_313 ) ;
if ( ! V_27 -> V_673 ) {
V_27 -> V_673 =
F_121 ( V_624 , V_633 | V_634 | V_635 ,
V_27 -> V_666 , V_27 , & V_674 ) ;
if ( ! V_27 -> V_673 ) {
F_119 ( V_2 , V_328 , V_329 ,
L_314 ) ;
goto V_629;
}
}
snprintf ( V_624 , sizeof( V_624 ) , L_315 ) ;
if ( ! V_27 -> V_675 ) {
V_27 -> V_675 =
F_121 ( V_624 , V_633 | V_634 | V_635 ,
V_27 -> V_666 , V_27 , & V_676 ) ;
if ( ! V_27 -> V_675 ) {
F_119 ( V_2 , V_328 , V_329 ,
L_316 ) ;
goto V_629;
}
}
snprintf ( V_624 , sizeof( V_624 ) , L_317 ) ;
if ( ! V_27 -> V_677 ) {
V_27 -> V_677 =
F_121 ( V_624 , V_633 | V_634 | V_635 ,
V_27 -> V_666 , V_27 , & V_678 ) ;
if ( ! V_27 -> V_677 ) {
F_119 ( V_2 , V_328 , V_329 ,
L_318 ) ;
goto V_629;
}
}
snprintf ( V_624 , sizeof( V_624 ) , L_319 ) ;
if ( ! V_27 -> V_679 ) {
V_27 -> V_679 =
F_121 ( V_624 , V_633 | V_634 | V_635 ,
V_27 -> V_666 , V_27 , & V_680 ) ;
if ( ! V_27 -> V_679 ) {
F_119 ( V_2 , V_328 , V_329 ,
L_320 ) ;
goto V_629;
}
}
if ( V_27 -> V_201 . V_681 ) {
snprintf ( V_624 , sizeof( V_624 ) , L_321 ) ;
if ( ! V_27 -> V_682 ) {
V_27 -> V_682 =
F_121 ( V_624 ,
V_633 | V_634 | V_635 ,
V_27 -> V_666 , V_27 ,
& V_683 ) ;
if ( ! V_27 -> V_682 ) {
F_119 ( V_2 , V_328 , V_329 ,
L_322
L_323 ) ;
goto V_629;
}
}
}
V_629:
return;
#endif
}
inline void
F_123 ( struct V_1 * V_2 )
{
#ifdef F_31
struct V_26 * V_27 = V_2 -> V_27 ;
F_5 ( V_2 -> V_18 ) ;
V_2 -> V_18 = NULL ;
F_124 ( V_2 -> V_656 ) ;
V_2 -> V_656 = NULL ;
F_124 ( V_2 -> V_658 ) ;
V_2 -> V_658 = NULL ;
F_124 ( V_2 -> V_660 ) ;
V_2 -> V_660 = NULL ;
F_124 ( V_2 -> V_662 ) ;
V_2 -> V_662 = NULL ;
F_124 ( V_2 -> V_664 ) ;
V_2 -> V_664 = NULL ;
if ( V_2 -> V_655 ) {
F_124 ( V_2 -> V_655 ) ;
V_2 -> V_655 = NULL ;
F_125 ( & V_27 -> V_631 ) ;
}
if ( F_3 ( & V_27 -> V_631 ) == 0 ) {
F_124 ( V_27 -> V_632 ) ;
V_27 -> V_632 = NULL ;
F_124 ( V_27 -> V_638 ) ;
V_27 -> V_638 = NULL ;
F_124 ( V_27 -> V_640 ) ;
V_27 -> V_640 = NULL ;
F_124 ( V_27 -> V_642 ) ;
V_27 -> V_642 = NULL ;
F_124 ( V_27 -> V_644 ) ;
V_27 -> V_644 = NULL ;
F_124 ( V_27 -> V_325 ) ;
V_27 -> V_325 = NULL ;
F_124 ( V_27 -> V_320 ) ;
V_27 -> V_320 = NULL ;
F_124 ( V_27 -> V_322 ) ;
V_27 -> V_322 = NULL ;
F_124 ( V_27 -> V_308 ) ;
V_27 -> V_308 = NULL ;
F_124 ( V_27 -> V_310 ) ;
V_27 -> V_310 = NULL ;
F_124 ( V_27 -> V_312 ) ;
V_27 -> V_312 = NULL ;
F_124 ( V_27 -> V_314 ) ;
V_27 -> V_314 = NULL ;
F_124 ( V_27 -> V_316 ) ;
V_27 -> V_316 = NULL ;
F_124 ( V_27 -> V_318 ) ;
V_27 -> V_318 = NULL ;
F_5 ( V_27 -> V_30 ) ;
V_27 -> V_30 = NULL ;
F_124 ( V_27 -> V_648 ) ;
V_27 -> V_648 = NULL ;
F_124 ( V_27 -> V_650 ) ;
V_27 -> V_650 = NULL ;
F_5 ( V_27 -> V_261 ) ;
V_27 -> V_261 = NULL ;
if ( V_27 -> V_48 == V_637 ) {
F_124 ( V_27 -> V_682 ) ;
V_27 -> V_682 = NULL ;
F_124 ( V_27 -> V_679 ) ;
V_27 -> V_679 = NULL ;
F_124 ( V_27 -> V_677 ) ;
V_27 -> V_677 = NULL ;
F_124 ( V_27 -> V_675 ) ;
V_27 -> V_675 = NULL ;
F_124 ( V_27 -> V_673 ) ;
V_27 -> V_673 = NULL ;
F_124 ( V_27 -> V_671 ) ;
V_27 -> V_671 = NULL ;
F_124 ( V_27 -> V_669 ) ;
V_27 -> V_669 = NULL ;
F_124 ( V_27 -> V_667 ) ;
V_27 -> V_667 = NULL ;
F_124 ( V_27 -> V_666 ) ;
V_27 -> V_666 = NULL ;
}
if ( V_27 -> V_630 ) {
F_124 ( V_27 -> V_630 ) ;
V_27 -> V_630 = NULL ;
F_125 ( & V_628 ) ;
}
if ( F_3 ( & V_628 ) == 0 ) {
F_124 ( V_627 ) ;
V_627 = NULL ;
}
}
#endif
return;
}
void
F_126 ( struct V_26 * V_27 )
{
int V_684 ;
F_127 ( V_27 , V_685 , 0 ) ;
F_127 ( V_27 , V_686 , 0 ) ;
F_127 ( V_27 , V_687 , 0 ) ;
for ( V_684 = 0 ; V_684 < V_27 -> V_442 ; V_684 ++ )
F_127 ( V_27 , V_688 , V_684 ) ;
for ( V_684 = 0 ; V_684 < V_27 -> V_444 ; V_684 ++ )
F_127 ( V_27 , V_689 , V_684 ) ;
F_128 ( V_27 ) ;
F_129 ( V_27 ) ;
F_130 ( V_27 , V_685 , 0 ) ;
F_130 ( V_27 , V_686 , 0 ) ;
F_130 ( V_27 , V_687 , 0 ) ;
for ( V_684 = 0 ; V_684 < V_27 -> V_442 ; V_684 ++ )
F_130 ( V_27 , V_688 , V_684 ) ;
for ( V_684 = 0 ; V_684 < V_27 -> V_444 ; V_684 ++ )
F_130 ( V_27 , V_689 , V_684 ) ;
for ( V_684 = 0 ; V_684 < V_27 -> V_464 ; V_684 ++ )
F_131 ( V_27 , V_684 ) ;
}
