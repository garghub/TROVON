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
struct V_121 * V_122 ;
struct V_123 * V_124 ;
V_109 = ( V_125 / V_126 ) ;
V_7 += snprintf ( V_3 + V_7 , V_4 - V_7 , L_19 ) ;
F_8 ( V_111 -> V_127 ) ;
F_10 (ndlp, &vport->fc_nodes, nlp_listp) {
if ( ! V_109 ) {
V_7 += snprintf ( V_3 + V_7 , V_4 - V_7 ,
L_20 ) ;
break;
}
V_109 -- ;
switch ( V_113 -> V_128 ) {
case V_129 :
V_114 = L_21 ;
break;
case V_130 :
V_114 = L_22 ;
break;
case V_131 :
V_114 = L_23 ;
break;
case V_132 :
V_114 = L_24 ;
break;
case V_133 :
V_114 = L_25 ;
break;
case V_134 :
V_114 = L_26 ;
break;
case V_135 :
V_114 = L_27 ;
break;
case V_136 :
V_114 = L_28 ;
break;
case V_137 :
V_114 = L_29 ;
break;
default:
V_114 = L_30 ;
}
V_7 += snprintf ( V_3 + V_7 , V_4 - V_7 , L_31 ,
V_114 , V_113 -> V_138 ) ;
V_7 += snprintf ( V_3 + V_7 , V_4 - V_7 ,
L_32 ,
F_20 ( V_113 -> V_139 . V_140 . V_141 ) ) ;
V_7 += snprintf ( V_3 + V_7 , V_4 - V_7 ,
L_33 ,
F_20 ( V_113 -> V_142 . V_140 . V_141 ) ) ;
if ( V_113 -> V_143 & V_144 )
V_7 += snprintf ( V_3 + V_7 , V_4 - V_7 , L_34 ,
V_113 -> V_145 ) ;
else
V_7 += snprintf ( V_3 + V_7 , V_4 - V_7 , L_35 ) ;
V_7 += snprintf ( V_3 + V_7 , V_4 - V_7 , L_36 ,
V_113 -> V_143 ) ;
if ( ! V_113 -> V_146 )
V_7 += snprintf ( V_3 + V_7 , V_4 - V_7 , L_37 ) ;
if ( V_113 -> V_146 & V_147 )
V_7 += snprintf ( V_3 + V_7 , V_4 - V_7 , L_38 ) ;
if ( V_113 -> V_146 & V_148 )
V_7 += snprintf ( V_3 + V_7 , V_4 - V_7 , L_39 ) ;
if ( V_113 -> V_146 & V_149 )
V_7 += snprintf ( V_3 + V_7 , V_4 - V_7 , L_40 ,
V_113 -> V_150 ) ;
if ( V_113 -> V_146 & V_151 )
V_7 += snprintf ( V_3 + V_7 , V_4 - V_7 , L_41 ) ;
V_7 += snprintf ( V_3 + V_7 , V_4 - V_7 , L_42 ,
V_113 -> V_152 ) ;
V_7 += snprintf ( V_3 + V_7 , V_4 - V_7 , L_43 ,
F_21 ( & V_113 -> V_153 ) ) ;
V_7 += snprintf ( V_3 + V_7 , V_4 - V_7 , L_44 ) ;
}
F_13 ( V_111 -> V_127 ) ;
if ( V_27 -> V_154 && V_27 -> V_155 && ( V_2 == V_27 -> V_156 ) ) {
V_122 = (struct V_121 * ) V_27 -> V_155 -> V_157 ;
V_7 += snprintf ( V_3 + V_7 , V_4 - V_7 ,
L_45 ) ;
if ( V_27 -> V_155 -> V_158 )
V_114 = L_46 ;
else
V_114 = L_47 ;
V_7 += snprintf ( V_3 + V_7 , V_4 - V_7 ,
L_48 ,
F_20 ( V_2 -> V_159 . V_140 . V_141 ) ,
F_20 ( V_2 -> V_160 . V_140 . V_141 ) ,
V_114 ) ;
V_7 += snprintf ( V_3 + V_7 , V_4 - V_7 ,
L_49 ,
V_27 -> V_155 -> V_158 ) ;
goto V_161;
}
V_7 += snprintf ( V_3 + V_7 , V_4 - V_7 ,
L_50 ) ;
V_116 = V_2 -> V_116 ;
if ( ! V_116 )
goto V_161;
F_8 ( V_111 -> V_127 ) ;
V_118 = (struct V_117 * ) V_116 -> V_157 ;
if ( V_116 -> V_158 )
V_114 = L_51 ;
else
V_114 = L_52 ;
V_7 += snprintf ( V_3 + V_7 , V_4 - V_7 ,
L_53 ,
V_116 -> V_158 , V_114 ) ;
V_7 += snprintf ( V_3 + V_7 , V_4 - V_7 , L_54 ) ;
F_10 (rport, &lport->rport_list, list) {
V_124 = V_120 -> V_162 ;
switch ( V_124 -> V_163 ) {
case V_164 :
V_114 = L_51 ;
break;
case V_165 :
V_114 = L_52 ;
break;
default:
V_114 = L_55 ;
break;
}
V_7 += snprintf ( V_3 + V_7 , V_4 - V_7 ,
L_56 ,
V_114 , V_124 -> V_158 ) ;
V_7 += snprintf ( V_3 + V_7 , V_4 - V_7 , L_32 ,
V_124 -> V_166 ) ;
V_7 += snprintf ( V_3 + V_7 , V_4 - V_7 , L_33 ,
V_124 -> V_167 ) ;
switch ( V_124 -> V_168 ) {
case V_169 :
V_7 += snprintf ( V_3 + V_7 , V_4 - V_7 ,
L_57 ) ;
break;
case V_170 :
V_7 += snprintf ( V_3 + V_7 , V_4 - V_7 ,
L_58 ) ;
break;
case V_171 :
V_7 += snprintf ( V_3 + V_7 , V_4 - V_7 ,
L_59 ) ;
break;
default:
V_7 += snprintf ( V_3 + V_7 , V_4 - V_7 ,
L_60 ,
V_124 -> V_168 ) ;
break;
}
V_7 += snprintf ( V_3 + V_7 , V_4 - V_7 , L_44 ) ;
}
F_13 ( V_111 -> V_127 ) ;
V_161:
return V_7 ;
}
static int
F_22 ( struct V_1 * V_2 , char * V_3 , int V_4 )
{
struct V_26 * V_27 = V_2 -> V_27 ;
struct V_121 * V_122 ;
struct V_172 * V_173 , * V_174 ;
int V_7 = 0 ;
int V_109 ;
if ( V_27 -> V_154 ) {
if ( ! V_27 -> V_155 )
return V_7 ;
V_122 = (struct V_121 * ) V_27 -> V_155 -> V_157 ;
V_7 += snprintf ( V_3 + V_7 , V_4 - V_7 ,
L_61 ) ;
V_7 += snprintf ( V_3 + V_7 , V_4 - V_7 ,
L_62 ,
F_3 ( & V_122 -> V_175 ) ,
F_3 ( & V_122 -> V_176 ) ,
F_3 ( & V_122 -> V_177 ) ) ;
if ( F_3 ( & V_122 -> V_175 ) !=
F_3 ( & V_122 -> V_178 ) ) {
V_7 += snprintf ( V_3 + V_7 , V_4 - V_7 ,
L_63 ,
F_3 ( & V_122 -> V_175 ) ,
F_3 ( & V_122 -> V_178 ) ) ;
}
V_7 += snprintf ( V_3 + V_7 , V_4 - V_7 ,
L_64 ,
F_3 ( & V_122 -> V_179 ) ,
F_3 ( & V_122 -> V_180 ) ,
F_3 ( & V_122 -> V_181 ) ,
F_3 ( & V_122 -> V_182 ) ) ;
V_7 += snprintf ( V_3 + V_7 , V_4 - V_7 ,
L_65 ,
F_3 ( & V_122 -> V_183 ) ,
F_3 ( & V_122 -> V_184 ) ) ;
if ( F_3 ( & V_122 -> V_183 ) !=
F_3 ( & V_122 -> V_185 ) ) {
V_7 += snprintf ( V_3 + V_7 , V_4 - V_7 ,
L_66 ,
F_3 ( & V_122 -> V_183 ) ,
F_3 ( & V_122 -> V_185 ) ) ;
}
V_7 += snprintf ( V_3 + V_7 , V_4 - V_7 ,
L_67
L_68 ,
F_3 ( & V_122 -> V_186 ) ,
F_3 ( & V_122 -> V_187 ) ,
F_3 ( & V_122 -> V_188 ) ,
F_3 ( & V_122 -> V_189 ) ) ;
V_7 += snprintf ( V_3 + V_7 , V_4 - V_7 ,
L_69 ,
F_3 ( & V_122 -> V_190 ) ,
F_3 ( & V_122 -> V_191 ) ,
F_3 ( & V_122 -> V_192 ) ) ;
V_7 += snprintf ( V_3 + V_7 , V_4 - V_7 ,
L_70 ,
F_3 ( & V_122 -> V_193 ) ,
F_3 ( & V_122 -> V_194 ) ) ;
V_7 += snprintf ( V_3 + V_7 , V_4 - V_7 ,
L_71 ,
F_3 ( & V_122 -> V_195 ) ,
F_3 ( & V_122 -> V_196 ) ,
F_3 ( & V_122 -> V_197 ) ,
F_3 ( & V_122 -> V_198 ) ) ;
V_7 += snprintf ( V_3 + V_7 , V_4 - V_7 , L_44 ) ;
V_109 = 0 ;
F_23 ( & V_27 -> V_199 . V_200 ) ;
F_24 (ctxp, next_ctxp,
&phba->sli4_hba.lpfc_abts_nvmet_ctx_list,
list) {
V_109 ++ ;
}
F_25 ( & V_27 -> V_199 . V_200 ) ;
if ( V_109 ) {
V_7 += snprintf ( V_3 + V_7 , V_4 - V_7 ,
L_72 , V_109 ) ;
F_23 ( & V_27 -> V_199 . V_200 ) ;
F_24 (ctxp, next_ctxp,
&phba->sli4_hba.lpfc_abts_nvmet_ctx_list,
list) {
if ( V_7 >= ( V_4 - V_201 ) )
break;
V_7 += snprintf ( V_3 + V_7 , V_4 - V_7 ,
L_73
L_74 ,
V_173 -> V_202 , V_173 -> V_203 ,
V_173 -> V_102 ) ;
}
F_25 ( & V_27 -> V_199 . V_200 ) ;
}
V_7 += snprintf ( V_3 + V_7 , V_4 - V_7 ,
L_75 ,
V_27 -> V_199 . V_204 ,
V_27 -> V_199 . V_205 ,
V_27 -> V_199 . V_206 ) ;
} else {
if ( ! ( V_27 -> V_207 & V_208 ) )
return V_7 ;
V_7 += snprintf ( V_3 + V_7 , V_4 - V_7 ,
L_76 ) ;
V_7 += snprintf ( V_3 + V_7 , V_4 - V_7 ,
L_77 ,
V_27 -> V_209 ,
V_27 -> V_210 ) ;
V_7 += snprintf ( V_3 + V_7 , V_4 - V_7 ,
L_78 ,
V_27 -> V_211 ,
V_27 -> V_212 ,
V_27 -> V_213 ) ;
V_7 += snprintf ( V_3 + V_7 , V_4 - V_7 ,
L_79 , V_27 -> V_214 ) ;
}
return V_7 ;
}
static int
F_26 ( struct V_1 * V_2 , char * V_3 , int V_4 )
{
struct V_26 * V_27 = V_2 -> V_27 ;
int V_7 = 0 ;
if ( V_27 -> V_154 == 0 ) {
V_7 += snprintf ( V_3 + V_7 , V_215 - V_7 ,
L_80 ,
( V_27 -> V_216 ? L_81 : L_82 ) ,
V_27 -> V_217 ) ;
if ( V_27 -> V_217 == 0 )
return V_7 ;
V_7 += snprintf (
V_3 + V_7 , V_215 - V_7 ,
L_83
L_84 ) ;
V_7 += snprintf (
V_3 + V_7 , V_215 - V_7 ,
L_85 ,
F_27 ( V_27 -> V_218 ,
V_27 -> V_217 ) ,
V_27 -> V_219 ,
V_27 -> V_220 ) ;
V_7 += snprintf (
V_3 + V_7 , V_215 - V_7 ,
L_86
L_87 ) ;
V_7 += snprintf (
V_3 + V_7 , V_215 - V_7 ,
L_85 ,
F_27 ( V_27 -> V_221 ,
V_27 -> V_217 ) ,
V_27 -> V_222 ,
V_27 -> V_223 ) ;
V_7 += snprintf (
V_3 + V_7 , V_215 - V_7 ,
L_88
L_89 ) ;
V_7 += snprintf (
V_3 + V_7 , V_215 - V_7 ,
L_85 ,
F_27 ( V_27 -> V_224 ,
V_27 -> V_217 ) ,
V_27 -> V_225 ,
V_27 -> V_226 ) ;
V_7 += snprintf (
V_3 + V_7 , V_215 - V_7 ,
L_90
L_91 ) ;
V_7 += snprintf (
V_3 + V_7 , V_215 - V_7 ,
L_85 ,
F_27 ( V_27 -> V_227 ,
V_27 -> V_217 ) ,
V_27 -> V_228 ,
V_27 -> V_229 ) ;
V_7 += snprintf (
V_3 + V_7 , V_215 - V_7 ,
L_92 ,
F_27 ( V_27 -> V_218 +
V_27 -> V_221 +
V_27 -> V_224 +
V_27 -> V_227 ,
V_27 -> V_217 ) ) ;
return V_7 ;
}
V_7 += snprintf ( V_3 + V_7 , V_215 - V_7 ,
L_93 ,
( V_27 -> V_216 ? L_81 : L_82 ) ,
V_27 -> V_217 ,
V_27 -> V_230 ) ;
if ( V_27 -> V_217 == 0 )
return V_7 ;
V_7 += snprintf ( V_3 + V_7 , V_215 - V_7 ,
L_94
L_95 ) ;
V_7 += snprintf ( V_3 + V_7 , V_215 - V_7 ,
L_85 ,
F_27 ( V_27 -> V_218 ,
V_27 -> V_217 ) ,
V_27 -> V_219 ,
V_27 -> V_220 ) ;
V_7 += snprintf ( V_3 + V_7 , V_215 - V_7 ,
L_96
L_97 ) ;
V_7 += snprintf ( V_3 + V_7 , V_215 - V_7 ,
L_85 ,
F_27 ( V_27 -> V_221 ,
V_27 -> V_217 ) ,
V_27 -> V_222 ,
V_27 -> V_223 ) ;
V_7 += snprintf ( V_3 + V_7 , V_215 - V_7 ,
L_98
L_99 ) ;
V_7 += snprintf ( V_3 + V_7 , V_215 - V_7 ,
L_85 ,
F_27 ( V_27 -> V_224 ,
V_27 -> V_217 ) ,
V_27 -> V_225 ,
V_27 -> V_226 ) ;
V_7 += snprintf ( V_3 + V_7 , V_215 - V_7 ,
L_100
L_101 ) ;
V_7 += snprintf ( V_3 + V_7 , V_215 - V_7 ,
L_85 ,
F_27 ( V_27 -> V_227 ,
V_27 -> V_217 ) ,
V_27 -> V_228 ,
V_27 -> V_229 ) ;
V_7 += snprintf ( V_3 + V_7 , V_215 - V_7 ,
L_102
L_103 ) ;
V_7 += snprintf ( V_3 + V_7 , V_215 - V_7 ,
L_85 ,
F_27 ( V_27 -> V_231 ,
V_27 -> V_217 ) ,
V_27 -> V_232 ,
V_27 -> V_233 ) ;
if ( V_27 -> V_230 == 0 ) {
V_7 += snprintf ( V_3 + V_7 , V_215 - V_7 ,
L_104
L_105 ) ;
V_7 += snprintf ( V_3 + V_7 , V_215 - V_7 ,
L_106
L_107 ,
F_27 ( V_27 -> V_234 ,
V_27 -> V_217 ) ,
V_27 -> V_235 ,
V_27 -> V_236 ) ;
return V_7 ;
}
V_7 += snprintf ( V_3 + V_7 , V_215 - V_7 ,
L_108
L_109 ) ;
V_7 += snprintf ( V_3 + V_7 , V_215 - V_7 ,
L_85 ,
F_27 ( V_27 -> V_237 ,
V_27 -> V_230 ) ,
V_27 -> V_238 ,
V_27 -> V_239 ) ;
V_7 += snprintf ( V_3 + V_7 , V_215 - V_7 ,
L_110
L_111 ) ;
V_7 += snprintf ( V_3 + V_7 , V_215 - V_7 ,
L_85 ,
F_27 ( V_27 -> V_240 ,
V_27 -> V_230 ) ,
V_27 -> V_241 ,
V_27 -> V_242 ) ;
V_7 += snprintf ( V_3 + V_7 , V_215 - V_7 ,
L_112
L_113 ) ;
V_7 += snprintf ( V_3 + V_7 , V_215 - V_7 ,
L_85 ,
F_27 ( V_27 -> V_243 ,
V_27 -> V_230 ) ,
V_27 -> V_244 ,
V_27 -> V_245 ) ;
V_7 += snprintf ( V_3 + V_7 , V_215 - V_7 ,
L_114
L_115 ) ;
V_7 += snprintf ( V_3 + V_7 , V_215 - V_7 ,
L_85 ,
F_27 ( V_27 -> V_246 ,
V_27 -> V_230 ) ,
V_27 -> V_247 ,
V_27 -> V_248 ) ;
V_7 += snprintf ( V_3 + V_7 , V_215 - V_7 ,
L_116
L_117 ) ;
V_7 += snprintf ( V_3 + V_7 , V_215 - V_7 ,
L_85 ,
F_27 ( V_27 -> V_234 ,
V_27 -> V_230 ) ,
V_27 -> V_235 ,
V_27 -> V_236 ) ;
return V_7 ;
}
static int
F_28 ( struct V_26 * V_27 , char * V_3 , int V_4 )
{
struct V_249 * V_11 ;
int V_5 , V_203 , V_6 , V_250 ;
int V_7 = 0 ;
V_203 = V_27 -> V_251 ;
V_6 = ( F_3 ( & V_27 -> V_252 ) + 1 ) &
( V_27 -> V_253 - 1 ) ;
V_250 = V_27 -> V_254 ;
V_7 += snprintf ( V_3 + V_7 , V_4 - V_7 ,
L_118 ,
( V_27 -> V_154 ? L_119 : L_120 ) ,
( V_203 ? L_81 : L_82 ) ,
V_6 , V_250 , V_27 -> V_253 ) ;
if ( ! V_27 -> V_255 || V_203 )
return V_7 ;
for ( V_5 = V_6 ; V_5 < V_27 -> V_253 ; V_5 ++ ) {
if ( V_250 ) {
V_250 -- ;
continue;
}
V_11 = V_27 -> V_255 + V_5 ;
V_27 -> V_254 ++ ;
if ( ! V_11 -> V_19 )
continue;
V_7 += snprintf ( V_3 + V_7 , V_4 - V_7 , V_11 -> V_19 ,
V_11 -> V_23 , V_11 -> V_24 , V_11 -> V_25 ) ;
if ( V_27 -> V_254 >= V_27 -> V_253 ) {
V_27 -> V_254 = 0 ;
V_7 += snprintf ( V_3 + V_7 , V_4 - V_7 ,
L_121 ) ;
goto V_256;
}
if ( V_7 >= ( V_4 - V_201 ) ) {
V_7 += snprintf ( V_3 + V_7 , V_4 - V_7 ,
L_122 ,
V_27 -> V_254 ,
V_27 -> V_253 ) ;
goto V_256;
}
}
for ( V_5 = 0 ; V_5 < V_6 ; V_5 ++ ) {
if ( V_250 ) {
V_250 -- ;
continue;
}
V_11 = V_27 -> V_255 + V_5 ;
V_27 -> V_254 ++ ;
if ( ! V_11 -> V_19 )
continue;
V_7 += snprintf ( V_3 + V_7 , V_4 - V_7 , V_11 -> V_19 ,
V_11 -> V_23 , V_11 -> V_24 , V_11 -> V_25 ) ;
if ( V_27 -> V_254 >= V_27 -> V_253 ) {
V_27 -> V_254 = 0 ;
V_7 += snprintf ( V_3 + V_7 , V_4 - V_7 ,
L_121 ) ;
goto V_256;
}
if ( V_7 >= ( V_4 - V_201 ) ) {
V_7 += snprintf ( V_3 + V_7 , V_4 - V_7 ,
L_122 ,
V_27 -> V_254 ,
V_27 -> V_253 ) ;
goto V_256;
}
}
V_7 += snprintf ( V_3 + V_7 , V_4 - V_7 ,
L_123 ) ;
V_256:
return V_7 ;
}
static int
F_29 ( struct V_1 * V_2 , char * V_3 , int V_4 )
{
struct V_26 * V_27 = V_2 -> V_27 ;
int V_5 ;
int V_7 = 0 ;
T_1 V_257 = 0 ;
T_1 V_258 = 0 ;
T_1 V_259 = 0 ;
T_1 V_260 = 0 ;
if ( V_27 -> V_154 == 0 ) {
V_7 += snprintf ( V_3 + V_7 , V_215 - V_7 ,
L_124 ,
( V_27 -> V_261 & V_262 ?
L_81 : L_82 ) ) ;
for ( V_5 = 0 ; V_5 < V_27 -> V_199 . V_263 ; V_5 ++ ) {
if ( V_5 >= V_264 )
break;
V_7 += snprintf ( V_3 + V_7 , V_215 - V_7 ,
L_125 ,
V_5 , V_27 -> V_265 [ V_5 ] ,
V_27 -> V_266 [ V_5 ] ) ;
V_257 += V_27 -> V_265 [ V_5 ] ;
V_259 += V_27 -> V_266 [ V_5 ] ;
}
V_7 += snprintf ( V_3 + V_7 , V_215 - V_7 ,
L_126 ,
V_257 , V_259 ) ;
return V_7 ;
}
V_7 += snprintf ( V_3 + V_7 , V_215 - V_7 ,
L_127 ,
( V_27 -> V_261 & V_267 ?
L_128 : L_129 ) ) ;
V_7 += snprintf ( V_3 + V_7 , V_215 - V_7 ,
L_130 ,
( V_27 -> V_261 & V_268 ?
L_131 : L_132 ) ) ;
for ( V_5 = 0 ; V_5 < V_27 -> V_199 . V_263 ; V_5 ++ ) {
if ( V_5 >= V_264 )
break;
V_7 += snprintf ( V_3 + V_7 , V_215 - V_7 ,
L_133
L_134 ,
V_5 , V_27 -> V_265 [ V_5 ] ,
V_27 -> V_269 [ V_5 ] ,
V_27 -> V_266 [ V_5 ] ,
V_27 -> V_270 [ V_5 ] ) ;
V_257 += V_27 -> V_265 [ V_5 ] ;
V_258 += V_27 -> V_270 [ V_5 ] ;
V_259 += V_27 -> V_266 [ V_5 ] ;
V_260 += V_27 -> V_269 [ V_5 ] ;
}
V_7 += snprintf ( V_3 + V_7 , V_215 - V_7 ,
L_135 ,
V_257 , V_260 , V_259 , V_258 ) ;
return V_7 ;
}
inline void
F_30 ( struct V_1 * V_2 , int V_271 , char * V_19 ,
T_1 V_23 , T_1 V_24 , T_1 V_25 )
{
#ifdef F_31
struct V_10 * V_11 ;
int V_6 ;
if ( ! ( V_272 & V_271 ) )
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
V_11 -> V_22 = F_32 ( & V_273 ) ;
V_11 -> V_20 = V_274 ;
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
V_11 -> V_22 = F_32 ( & V_273 ) ;
V_11 -> V_20 = V_274 ;
#endif
return;
}
inline void
F_34 ( struct V_26 * V_27 , char * V_19 ,
T_2 V_23 , T_2 V_24 , T_1 V_25 )
{
#ifdef F_31
struct V_249 * V_11 ;
int V_6 ;
if ( ! V_27 -> V_251 || ! V_27 -> V_255 )
return;
V_6 = F_32 ( & V_27 -> V_252 ) &
( V_27 -> V_253 - 1 ) ;
V_11 = V_27 -> V_255 + V_6 ;
V_11 -> V_19 = V_19 ;
V_11 -> V_23 = V_23 ;
V_11 -> V_24 = V_24 ;
V_11 -> V_25 = V_25 ;
#endif
}
static int
F_35 ( struct V_275 * V_275 , struct V_276 * V_276 )
{
struct V_1 * V_2 = V_275 -> V_277 ;
struct V_278 * V_279 ;
int V_4 ;
int V_280 = - V_281 ;
if ( ! V_17 ) {
V_280 = - V_282 ;
goto V_256;
}
V_279 = F_2 ( sizeof( * V_279 ) , V_14 ) ;
if ( ! V_279 )
goto V_256;
V_4 = ( V_17 * V_13 ) ;
V_4 = F_36 ( V_4 ) ;
V_279 -> V_12 = F_2 ( V_4 , V_14 ) ;
if ( ! V_279 -> V_12 ) {
F_5 ( V_279 ) ;
goto V_256;
}
V_279 -> V_7 = F_1 ( V_2 , V_279 -> V_12 , V_4 ) ;
V_276 -> V_283 = V_279 ;
V_280 = 0 ;
V_256:
return V_280 ;
}
static int
F_37 ( struct V_275 * V_275 , struct V_276 * V_276 )
{
struct V_26 * V_27 = V_275 -> V_277 ;
struct V_278 * V_279 ;
int V_4 ;
int V_280 = - V_281 ;
if ( ! V_29 ) {
V_280 = - V_282 ;
goto V_256;
}
V_279 = F_2 ( sizeof( * V_279 ) , V_14 ) ;
if ( ! V_279 )
goto V_256;
V_4 = ( V_29 * V_13 ) ;
V_4 = F_36 ( V_4 ) ;
V_279 -> V_12 = F_2 ( V_4 , V_14 ) ;
if ( ! V_279 -> V_12 ) {
F_5 ( V_279 ) ;
goto V_256;
}
V_279 -> V_7 = F_6 ( V_27 , V_279 -> V_12 , V_4 ) ;
V_276 -> V_283 = V_279 ;
V_280 = 0 ;
V_256:
return V_280 ;
}
static int
F_38 ( struct V_275 * V_275 , struct V_276 * V_276 )
{
struct V_26 * V_27 = V_275 -> V_277 ;
struct V_278 * V_279 ;
int V_280 = - V_281 ;
V_279 = F_2 ( sizeof( * V_279 ) , V_14 ) ;
if ( ! V_279 )
goto V_256;
V_279 -> V_12 = F_2 ( V_74 , V_14 ) ;
if ( ! V_279 -> V_12 ) {
F_5 ( V_279 ) ;
goto V_256;
}
V_279 -> V_7 = F_7 ( V_27 , V_279 -> V_12 ,
V_74 ) ;
V_276 -> V_283 = V_279 ;
V_280 = 0 ;
V_256:
return V_280 ;
}
static int
F_39 ( struct V_275 * V_275 , struct V_276 * V_276 )
{
struct V_26 * V_27 = V_275 -> V_277 ;
struct V_278 * V_279 ;
int V_280 = - V_281 ;
V_279 = F_2 ( sizeof( * V_279 ) , V_14 ) ;
if ( ! V_279 )
goto V_256;
V_279 -> V_12 = F_2 ( V_284 , V_14 ) ;
if ( ! V_279 -> V_12 ) {
F_5 ( V_279 ) ;
goto V_256;
}
V_279 -> V_7 = F_14 ( V_27 , V_279 -> V_12 ,
V_284 ) ;
V_276 -> V_283 = V_279 ;
V_280 = 0 ;
V_256:
return V_280 ;
}
static int
F_40 ( struct V_275 * V_275 , struct V_276 * V_276 )
{
struct V_26 * V_27 = V_275 -> V_277 ;
struct V_278 * V_279 ;
int V_280 = - V_281 ;
V_279 = F_2 ( sizeof( * V_279 ) , V_14 ) ;
if ( ! V_279 )
goto V_256;
V_279 -> V_12 = F_2 ( V_285 , V_14 ) ;
if ( ! V_279 -> V_12 ) {
F_5 ( V_279 ) ;
goto V_256;
}
V_279 -> V_7 = F_16 ( V_27 , V_279 -> V_12 ,
V_285 ) ;
V_276 -> V_283 = V_279 ;
V_280 = 0 ;
V_256:
return V_280 ;
}
static int
F_41 ( struct V_275 * V_275 , struct V_276 * V_276 )
{
struct V_278 * V_279 ;
int V_280 = - V_281 ;
if ( ! V_286 )
return - V_287 ;
V_279 = F_2 ( sizeof( * V_279 ) , V_14 ) ;
if ( ! V_279 )
goto V_256;
F_42 ( L_136 ,
V_288 , V_286 ) ;
V_279 -> V_12 = V_286 ;
if ( ! V_279 -> V_12 ) {
F_5 ( V_279 ) ;
goto V_256;
}
V_279 -> V_7 = ( 1 << V_289 ) << V_290 ;
V_276 -> V_283 = V_279 ;
V_280 = 0 ;
V_256:
return V_280 ;
}
static int
F_43 ( struct V_275 * V_275 , struct V_276 * V_276 )
{
struct V_278 * V_279 ;
int V_280 = - V_281 ;
if ( ! V_291 )
return - V_287 ;
V_279 = F_2 ( sizeof( * V_279 ) , V_14 ) ;
if ( ! V_279 )
goto V_256;
F_42 ( L_137 ,
V_288 , V_291 , V_276 ) ;
V_279 -> V_12 = V_291 ;
if ( ! V_279 -> V_12 ) {
F_5 ( V_279 ) ;
goto V_256;
}
V_279 -> V_7 = ( 1 << V_292 ) << V_290 ;
V_276 -> V_283 = V_279 ;
V_280 = 0 ;
V_256:
return V_280 ;
}
static T_3
F_44 ( struct V_276 * V_276 , const char T_4 * V_3 ,
T_5 V_293 , T_6 * V_294 )
{
F_23 ( & V_295 ) ;
memset ( ( void * ) V_286 , 0 ,
( ( 1 << V_290 ) << V_289 ) ) ;
memset ( ( void * ) V_291 , 0 ,
( ( 1 << V_290 ) << V_292 ) ) ;
V_296 = 0 ;
F_25 ( & V_295 ) ;
return V_293 ;
}
static T_3
F_45 ( struct V_276 * V_276 , char T_4 * V_3 ,
T_5 V_293 , T_6 * V_294 )
{
struct V_297 * V_298 = V_276 -> V_299 . V_297 ;
struct V_26 * V_27 = V_276 -> V_283 ;
char V_300 [ 32 ] ;
V_71 V_301 = 0 ;
int V_109 = 0 ;
if ( V_298 == V_27 -> V_302 )
V_109 = snprintf ( V_300 , 32 , L_138 , V_27 -> V_303 ) ;
else if ( V_298 == V_27 -> V_304 )
V_109 = snprintf ( V_300 , 32 , L_138 , V_27 -> V_305 ) ;
else if ( V_298 == V_27 -> V_306 )
V_109 = snprintf ( V_300 , 32 , L_138 , V_27 -> V_307 ) ;
else if ( V_298 == V_27 -> V_308 )
V_109 = snprintf ( V_300 , 32 , L_138 , V_27 -> V_309 ) ;
else if ( V_298 == V_27 -> V_310 )
V_109 = snprintf ( V_300 , 32 , L_138 , V_27 -> V_311 ) ;
else if ( V_298 == V_27 -> V_312 )
V_109 = snprintf ( V_300 , 32 , L_138 , V_27 -> V_313 ) ;
else if ( V_298 == V_27 -> V_314 )
V_109 = snprintf ( V_300 , 32 , L_139 , V_27 -> V_315 ) ;
else if ( V_298 == V_27 -> V_316 ) {
memcpy ( & V_301 , & V_27 -> V_317 , sizeof( struct V_318 ) ) ;
V_301 = F_46 ( V_301 ) ;
V_109 = snprintf ( V_300 , 32 , L_140 , V_301 ) ;
} else if ( V_298 == V_27 -> V_319 ) {
if ( V_27 -> V_320 == ( V_321 ) ( - 1 ) )
V_109 = snprintf ( V_300 , 32 , L_141 ) ;
else
V_109 = snprintf ( V_300 , 32 , L_142 ,
( V_71 ) V_27 -> V_320 ) ;
} else
F_47 ( V_27 , V_322 , V_323 ,
L_143 ) ;
return F_48 ( V_3 , V_293 , V_294 , & V_300 , V_109 ) ;
}
static T_3
F_49 ( struct V_276 * V_276 , const char T_4 * V_3 ,
T_5 V_293 , T_6 * V_294 )
{
struct V_297 * V_298 = V_276 -> V_299 . V_297 ;
struct V_26 * V_27 = V_276 -> V_283 ;
char V_324 [ 33 ] ;
V_71 V_301 = 0 ;
int V_4 ;
memset ( V_324 , 0 , 33 ) ;
V_4 = ( V_293 < 32 ) ? V_293 : 32 ;
if ( F_50 ( V_324 , V_3 , V_4 ) )
return 0 ;
if ( V_298 == V_27 -> V_319 ) {
if ( ( V_3 [ 0 ] == 'o' ) && ( V_3 [ 1 ] == 'f' ) && ( V_3 [ 2 ] == 'f' ) )
V_301 = ( V_71 ) ( - 1 ) ;
}
if ( ( V_301 == 0 ) && ( F_51 ( V_324 , 0 , & V_301 ) ) )
return 0 ;
if ( V_298 == V_27 -> V_302 )
V_27 -> V_303 = ( T_1 ) V_301 ;
else if ( V_298 == V_27 -> V_304 )
V_27 -> V_305 = ( T_1 ) V_301 ;
else if ( V_298 == V_27 -> V_306 )
V_27 -> V_307 = ( T_1 ) V_301 ;
else if ( V_298 == V_27 -> V_308 )
V_27 -> V_309 = ( T_1 ) V_301 ;
else if ( V_298 == V_27 -> V_310 )
V_27 -> V_311 = ( T_1 ) V_301 ;
else if ( V_298 == V_27 -> V_312 )
V_27 -> V_313 = ( T_1 ) V_301 ;
else if ( V_298 == V_27 -> V_319 )
V_27 -> V_320 = ( V_321 ) V_301 ;
else if ( V_298 == V_27 -> V_314 )
V_27 -> V_315 = ( T_1 ) ( V_301 & V_325 ) ;
else if ( V_298 == V_27 -> V_316 ) {
V_301 = F_46 ( V_301 ) ;
memcpy ( & V_27 -> V_317 , & V_301 , sizeof( struct V_318 ) ) ;
} else
F_47 ( V_27 , V_322 , V_323 ,
L_144 ) ;
return V_293 ;
}
static int
F_52 ( struct V_275 * V_275 , struct V_276 * V_276 )
{
return 0 ;
}
static int
F_53 ( struct V_275 * V_275 , struct V_276 * V_276 )
{
struct V_1 * V_2 = V_275 -> V_277 ;
struct V_278 * V_279 ;
int V_280 = - V_281 ;
V_279 = F_2 ( sizeof( * V_279 ) , V_14 ) ;
if ( ! V_279 )
goto V_256;
V_279 -> V_12 = F_2 ( V_125 , V_14 ) ;
if ( ! V_279 -> V_12 ) {
F_5 ( V_279 ) ;
goto V_256;
}
V_279 -> V_7 = F_18 ( V_2 , V_279 -> V_12 ,
V_125 ) ;
V_276 -> V_283 = V_279 ;
V_280 = 0 ;
V_256:
return V_280 ;
}
static T_6
F_54 ( struct V_276 * V_276 , T_6 V_75 , int V_326 )
{
struct V_278 * V_279 = V_276 -> V_283 ;
return F_55 ( V_276 , V_75 , V_326 , V_279 -> V_7 ) ;
}
static T_3
F_56 ( struct V_276 * V_276 , char T_4 * V_3 ,
T_5 V_293 , T_6 * V_294 )
{
struct V_278 * V_279 = V_276 -> V_283 ;
return F_48 ( V_3 , V_293 , V_294 , V_279 -> V_12 ,
V_279 -> V_7 ) ;
}
static int
F_57 ( struct V_275 * V_275 , struct V_276 * V_276 )
{
struct V_278 * V_279 = V_276 -> V_283 ;
F_5 ( V_279 -> V_12 ) ;
F_5 ( V_279 ) ;
return 0 ;
}
static int
F_58 ( struct V_275 * V_275 , struct V_276 * V_276 )
{
struct V_278 * V_279 = V_276 -> V_283 ;
V_279 -> V_12 = NULL ;
F_5 ( V_279 ) ;
return 0 ;
}
static int
F_59 ( struct V_275 * V_275 , struct V_276 * V_276 )
{
struct V_1 * V_2 = V_275 -> V_277 ;
struct V_278 * V_279 ;
int V_280 = - V_281 ;
V_279 = F_2 ( sizeof( * V_279 ) , V_14 ) ;
if ( ! V_279 )
goto V_256;
V_279 -> V_12 = F_2 ( V_327 , V_14 ) ;
if ( ! V_279 -> V_12 ) {
F_5 ( V_279 ) ;
goto V_256;
}
V_279 -> V_7 = F_22 ( V_2 , V_279 -> V_12 ,
V_327 ) ;
V_279 -> V_277 = V_275 -> V_277 ;
V_276 -> V_283 = V_279 ;
V_280 = 0 ;
V_256:
return V_280 ;
}
static T_3
F_60 ( struct V_276 * V_276 , const char T_4 * V_3 ,
T_5 V_293 , T_6 * V_294 )
{
struct V_278 * V_279 = V_276 -> V_283 ;
struct V_1 * V_2 = (struct V_1 * ) V_279 -> V_277 ;
struct V_26 * V_27 = V_2 -> V_27 ;
struct V_121 * V_122 ;
char V_328 [ 64 ] ;
char * V_329 ;
if ( ! V_27 -> V_155 )
return - V_330 ;
if ( V_293 > 64 )
V_293 = 64 ;
if ( ! F_61 ( V_331 , V_3 , V_293 ) )
return - V_332 ;
memset ( V_328 , 0 , sizeof( V_328 ) ) ;
if ( F_50 ( V_328 , V_3 , V_293 ) )
return - V_332 ;
V_329 = & V_328 [ 0 ] ;
V_122 = (struct V_121 * ) V_27 -> V_155 -> V_157 ;
if ( ( strncmp ( V_329 , L_145 , strlen ( L_145 ) ) == 0 ) ||
( strncmp ( V_329 , L_146 , strlen ( L_146 ) ) == 0 ) ) {
F_62 ( & V_122 -> V_175 , 0 ) ;
F_62 ( & V_122 -> V_178 , 0 ) ;
F_62 ( & V_122 -> V_176 , 0 ) ;
F_62 ( & V_122 -> V_177 , 0 ) ;
F_62 ( & V_122 -> V_333 , 0 ) ;
F_62 ( & V_122 -> V_179 , 0 ) ;
F_62 ( & V_122 -> V_180 , 0 ) ;
F_62 ( & V_122 -> V_182 , 0 ) ;
F_62 ( & V_122 -> V_181 , 0 ) ;
F_62 ( & V_122 -> V_183 , 0 ) ;
F_62 ( & V_122 -> V_185 , 0 ) ;
F_62 ( & V_122 -> V_184 , 0 ) ;
F_62 ( & V_122 -> V_334 , 0 ) ;
F_62 ( & V_122 -> V_187 , 0 ) ;
F_62 ( & V_122 -> V_186 , 0 ) ;
F_62 ( & V_122 -> V_188 , 0 ) ;
F_62 ( & V_122 -> V_189 , 0 ) ;
F_62 ( & V_122 -> V_335 , 0 ) ;
F_62 ( & V_122 -> V_190 , 0 ) ;
F_62 ( & V_122 -> V_191 , 0 ) ;
F_62 ( & V_122 -> V_192 , 0 ) ;
F_62 ( & V_122 -> V_193 , 0 ) ;
F_62 ( & V_122 -> V_194 , 0 ) ;
F_62 ( & V_122 -> V_195 , 0 ) ;
F_62 ( & V_122 -> V_196 , 0 ) ;
F_62 ( & V_122 -> V_197 , 0 ) ;
F_62 ( & V_122 -> V_198 , 0 ) ;
}
return V_293 ;
}
static int
F_63 ( struct V_275 * V_275 , struct V_276 * V_276 )
{
struct V_1 * V_2 = V_275 -> V_277 ;
struct V_278 * V_279 ;
int V_280 = - V_281 ;
V_279 = F_2 ( sizeof( * V_279 ) , V_14 ) ;
if ( ! V_279 )
goto V_256;
V_279 -> V_12 = F_2 ( V_336 , V_14 ) ;
if ( ! V_279 -> V_12 ) {
F_5 ( V_279 ) ;
goto V_256;
}
V_279 -> V_7 = F_26 ( V_2 , V_279 -> V_12 ,
V_336 ) ;
V_279 -> V_277 = V_275 -> V_277 ;
V_276 -> V_283 = V_279 ;
V_280 = 0 ;
V_256:
return V_280 ;
}
static T_3
F_64 ( struct V_276 * V_276 , const char T_4 * V_3 ,
T_5 V_293 , T_6 * V_294 )
{
struct V_278 * V_279 = V_276 -> V_283 ;
struct V_1 * V_2 = (struct V_1 * ) V_279 -> V_277 ;
struct V_26 * V_27 = V_2 -> V_27 ;
char V_328 [ 64 ] ;
char * V_329 ;
if ( V_293 > 64 )
V_293 = 64 ;
if ( ! F_61 ( V_331 , V_3 , V_293 ) )
return - V_332 ;
memset ( V_328 , 0 , sizeof( V_328 ) ) ;
if ( F_50 ( V_328 , V_3 , V_293 ) )
return - V_332 ;
V_329 = & V_328 [ 0 ] ;
if ( ( strncmp ( V_329 , L_147 , sizeof( L_147 ) - 1 ) == 0 ) ) {
V_27 -> V_217 = 0 ;
V_27 -> V_230 = 0 ;
V_27 -> V_218 = 0 ;
V_27 -> V_220 = 0 ;
V_27 -> V_219 = 0xffffffff ;
V_27 -> V_221 = 0 ;
V_27 -> V_223 = 0 ;
V_27 -> V_222 = 0xffffffff ;
V_27 -> V_224 = 0 ;
V_27 -> V_226 = 0 ;
V_27 -> V_225 = 0xffffffff ;
V_27 -> V_227 = 0 ;
V_27 -> V_229 = 0 ;
V_27 -> V_228 = 0xffffffff ;
V_27 -> V_231 = 0 ;
V_27 -> V_233 = 0 ;
V_27 -> V_232 = 0xffffffff ;
V_27 -> V_237 = 0 ;
V_27 -> V_239 = 0 ;
V_27 -> V_238 = 0xffffffff ;
V_27 -> V_240 = 0 ;
V_27 -> V_242 = 0 ;
V_27 -> V_241 = 0xffffffff ;
V_27 -> V_243 = 0 ;
V_27 -> V_245 = 0 ;
V_27 -> V_244 = 0xffffffff ;
V_27 -> V_246 = 0 ;
V_27 -> V_248 = 0 ;
V_27 -> V_247 = 0xffffffff ;
V_27 -> V_234 = 0 ;
V_27 -> V_236 = 0 ;
V_27 -> V_235 = 0xffffffff ;
V_27 -> V_216 = 1 ;
return strlen ( V_329 ) ;
} else if ( ( strncmp ( V_329 , L_148 ,
sizeof( L_148 ) - 1 ) == 0 ) ) {
V_27 -> V_216 = 0 ;
return strlen ( V_329 ) ;
} else if ( ( strncmp ( V_329 , L_146 ,
sizeof( L_146 ) - 1 ) == 0 ) ) {
V_27 -> V_217 = 0 ;
V_27 -> V_230 = 0 ;
V_27 -> V_218 = 0 ;
V_27 -> V_220 = 0 ;
V_27 -> V_219 = 0xffffffff ;
V_27 -> V_221 = 0 ;
V_27 -> V_223 = 0 ;
V_27 -> V_222 = 0xffffffff ;
V_27 -> V_224 = 0 ;
V_27 -> V_226 = 0 ;
V_27 -> V_225 = 0xffffffff ;
V_27 -> V_227 = 0 ;
V_27 -> V_229 = 0 ;
V_27 -> V_228 = 0xffffffff ;
V_27 -> V_231 = 0 ;
V_27 -> V_233 = 0 ;
V_27 -> V_232 = 0xffffffff ;
V_27 -> V_237 = 0 ;
V_27 -> V_239 = 0 ;
V_27 -> V_238 = 0xffffffff ;
V_27 -> V_240 = 0 ;
V_27 -> V_242 = 0 ;
V_27 -> V_241 = 0xffffffff ;
V_27 -> V_243 = 0 ;
V_27 -> V_245 = 0 ;
V_27 -> V_244 = 0xffffffff ;
V_27 -> V_246 = 0 ;
V_27 -> V_248 = 0 ;
V_27 -> V_247 = 0xffffffff ;
V_27 -> V_234 = 0 ;
V_27 -> V_236 = 0 ;
V_27 -> V_235 = 0xffffffff ;
return strlen ( V_329 ) ;
}
return - V_337 ;
}
static int
F_65 ( struct V_275 * V_275 , struct V_276 * V_276 )
{
struct V_26 * V_27 = V_275 -> V_277 ;
struct V_278 * V_279 ;
int V_280 = - V_281 ;
V_279 = F_2 ( sizeof( * V_279 ) , V_14 ) ;
if ( ! V_279 )
goto V_256;
V_279 -> V_12 = F_2 ( V_338 , V_14 ) ;
if ( ! V_279 -> V_12 ) {
F_5 ( V_279 ) ;
goto V_256;
}
V_279 -> V_7 = F_28 ( V_27 , V_279 -> V_12 ,
V_338 ) ;
V_279 -> V_277 = V_275 -> V_277 ;
V_276 -> V_283 = V_279 ;
V_280 = 0 ;
V_256:
return V_280 ;
}
static T_3
F_66 ( struct V_276 * V_276 , const char T_4 * V_3 ,
T_5 V_293 , T_6 * V_294 )
{
struct V_278 * V_279 = V_276 -> V_283 ;
struct V_26 * V_27 = (struct V_26 * ) V_279 -> V_277 ;
int V_5 ;
unsigned long V_339 ;
char V_328 [ 64 ] ;
char * V_329 ;
if ( V_293 > 64 )
V_293 = 64 ;
if ( ! F_61 ( V_331 , V_3 , V_293 ) )
return - V_332 ;
memset ( V_328 , 0 , sizeof( V_328 ) ) ;
if ( F_50 ( V_328 , V_3 , V_293 ) )
return - V_332 ;
V_329 = & V_328 [ 0 ] ;
if ( ( strncmp ( V_329 , L_148 , sizeof( L_148 ) - 1 ) == 0 ) ) {
F_47 ( V_27 , V_322 , V_323 ,
L_149 ) ;
V_27 -> V_254 = 0 ;
V_27 -> V_251 = 0 ;
return strlen ( V_329 ) ;
} else if ( ( strncmp ( V_329 , L_147 , sizeof( L_147 ) - 1 ) == 0 ) ) {
F_47 ( V_27 , V_322 , V_323 ,
L_150 ) ;
V_27 -> V_254 = 0 ;
V_27 -> V_251 = 1 ;
return strlen ( V_329 ) ;
}
if ( V_27 -> V_251 != 0 )
return - V_337 ;
V_5 = F_67 ( V_329 , 0 , & V_339 ) ;
if ( V_5 )
return - V_337 ;
V_27 -> V_253 = ( T_1 ) V_339 ;
V_5 = 0 ;
while ( V_339 > 1 ) {
V_339 = V_339 >> 1 ;
V_5 ++ ;
}
V_339 = ( 1 << V_5 ) ;
if ( V_27 -> V_253 != V_339 )
F_47 ( V_27 , V_322 , V_323 ,
L_151 ,
V_339 ) ;
V_27 -> V_253 = ( T_1 ) V_339 ;
F_5 ( V_27 -> V_255 ) ;
V_27 -> V_255 = F_2 ( ( sizeof( struct V_249 ) *
V_339 ) , V_14 ) ;
if ( ! V_27 -> V_255 ) {
F_47 ( V_27 , V_322 , V_323 ,
L_152
L_153 ) ;
return - V_281 ;
}
memset ( V_27 -> V_255 , 0 ,
( sizeof( struct V_249 ) * V_339 ) ) ;
F_62 ( & V_27 -> V_252 , 0 ) ;
V_27 -> V_251 = 0 ;
V_27 -> V_254 = 0 ;
return strlen ( V_329 ) ;
}
static int
F_68 ( struct V_275 * V_275 , struct V_276 * V_276 )
{
struct V_1 * V_2 = V_275 -> V_277 ;
struct V_278 * V_279 ;
int V_280 = - V_281 ;
V_279 = F_2 ( sizeof( * V_279 ) , V_14 ) ;
if ( ! V_279 )
goto V_256;
V_279 -> V_12 = F_2 ( V_340 , V_14 ) ;
if ( ! V_279 -> V_12 ) {
F_5 ( V_279 ) ;
goto V_256;
}
V_279 -> V_7 = F_29 ( V_2 , V_279 -> V_12 ,
V_336 ) ;
V_279 -> V_277 = V_275 -> V_277 ;
V_276 -> V_283 = V_279 ;
V_280 = 0 ;
V_256:
return V_280 ;
}
static T_3
F_69 ( struct V_276 * V_276 , const char T_4 * V_3 ,
T_5 V_293 , T_6 * V_294 )
{
struct V_278 * V_279 = V_276 -> V_283 ;
struct V_1 * V_2 = (struct V_1 * ) V_279 -> V_277 ;
struct V_26 * V_27 = V_2 -> V_27 ;
char V_328 [ 64 ] ;
char * V_329 ;
int V_5 ;
if ( V_293 > 64 )
V_293 = 64 ;
if ( ! F_61 ( V_331 , V_3 , V_293 ) )
return - V_332 ;
memset ( V_328 , 0 , sizeof( V_328 ) ) ;
if ( F_50 ( V_328 , V_3 , V_293 ) )
return - V_332 ;
V_329 = & V_328 [ 0 ] ;
if ( ( strncmp ( V_329 , L_147 , sizeof( L_147 ) - 1 ) == 0 ) ) {
if ( V_27 -> V_154 )
V_27 -> V_261 |= V_267 ;
else
V_27 -> V_261 |= V_262 ;
return strlen ( V_329 ) ;
} else if ( ( strncmp ( V_329 , L_154 ,
sizeof( L_154 ) - 1 ) == 0 ) ) {
if ( V_27 -> V_154 )
V_27 -> V_261 |= V_268 ;
else
return - V_337 ;
return strlen ( V_329 ) ;
} else if ( ( strncmp ( V_329 , L_148 ,
sizeof( L_148 ) - 1 ) == 0 ) ) {
V_27 -> V_261 = V_341 ;
return strlen ( V_329 ) ;
} else if ( ( strncmp ( V_329 , L_146 ,
sizeof( L_146 ) - 1 ) == 0 ) ) {
for ( V_5 = 0 ; V_5 < V_27 -> V_199 . V_263 ; V_5 ++ ) {
if ( V_5 >= V_264 )
break;
V_27 -> V_270 [ V_5 ] = 0 ;
V_27 -> V_265 [ V_5 ] = 0 ;
V_27 -> V_266 [ V_5 ] = 0 ;
V_27 -> V_269 [ V_5 ] = 0 ;
}
return strlen ( V_329 ) ;
}
return - V_337 ;
}
static int F_70 ( const char T_4 * V_3 , T_5 V_293 ,
struct V_342 * V_343 )
{
char V_328 [ 64 ] ;
char * V_329 , * V_344 ;
int V_5 ;
T_5 V_345 ;
if ( ! F_61 ( V_331 , V_3 , V_293 ) )
return - V_332 ;
memset ( V_328 , 0 , sizeof( V_328 ) ) ;
memset ( V_343 , 0 , sizeof( * V_343 ) ) ;
V_345 = F_71 ( V_293 , ( sizeof( V_328 ) - 1 ) ) ;
if ( F_50 ( V_328 , V_3 , V_345 ) )
return - V_332 ;
V_329 = & V_328 [ 0 ] ;
V_344 = F_72 ( & V_329 , L_155 ) ;
if ( ! V_344 )
return - V_337 ;
V_343 -> V_346 = F_73 ( V_344 , NULL , 0 ) ;
if ( V_343 -> V_346 == 0 )
return - V_337 ;
for ( V_5 = 0 ; V_5 < V_347 ; V_5 ++ ) {
V_344 = F_72 ( & V_329 , L_155 ) ;
if ( ! V_344 )
return V_5 ;
V_343 -> V_348 [ V_5 ] = F_73 ( V_344 , NULL , 0 ) ;
}
return V_5 ;
}
static int
F_74 ( struct V_275 * V_275 , struct V_276 * V_276 )
{
struct V_278 * V_279 ;
V_279 = F_2 ( sizeof( * V_279 ) , V_14 ) ;
if ( ! V_279 )
return - V_281 ;
V_279 -> V_277 = V_275 -> V_277 ;
V_279 -> V_12 = NULL ;
V_276 -> V_283 = V_279 ;
return 0 ;
}
static int
F_75 ( struct V_275 * V_275 , struct V_276 * V_276 )
{
struct V_278 * V_279 = V_276 -> V_283 ;
F_5 ( V_279 -> V_12 ) ;
F_5 ( V_279 ) ;
return 0 ;
}
static int
F_76 ( struct V_275 * V_275 , struct V_276 * V_276 )
{
struct V_278 * V_279 = V_276 -> V_283 ;
if ( V_279 -> V_349 == V_350 ) {
switch ( V_351 . V_352 . V_346 ) {
case V_353 :
case V_354 :
case V_355 :
case V_356 :
case V_357 :
case V_358 :
memset ( & V_351 , 0 , sizeof( V_351 ) ) ;
break;
default:
break;
}
}
F_5 ( V_279 -> V_12 ) ;
F_5 ( V_279 ) ;
return 0 ;
}
static T_3
F_77 ( struct V_276 * V_276 , char T_4 * V_3 , T_5 V_293 ,
T_6 * V_294 )
{
struct V_278 * V_279 = V_276 -> V_283 ;
struct V_26 * V_27 = (struct V_26 * ) V_279 -> V_277 ;
int V_359 , V_360 , V_7 = 0 , V_6 = V_361 ;
int V_362 , V_363 ;
char * V_364 ;
struct V_365 * V_366 ;
T_1 V_367 ;
T_2 V_368 ;
T_7 V_369 ;
V_366 = V_27 -> V_370 ;
if ( ! V_366 )
return 0 ;
V_279 -> V_349 = V_371 ;
if ( ! V_279 -> V_12 )
V_279 -> V_12 = F_2 ( V_372 , V_14 ) ;
if ( ! V_279 -> V_12 )
return 0 ;
V_364 = V_279 -> V_12 ;
if ( * V_294 )
return 0 ;
if ( V_351 . V_352 . V_346 == V_373 ) {
V_362 = V_351 . V_352 . V_348 [ V_374 ] ;
V_363 = V_351 . V_352 . V_348 [ V_375 ] ;
} else
return 0 ;
switch ( V_363 ) {
case V_376 :
F_78 ( V_366 , V_362 , & V_369 ) ;
V_7 += snprintf ( V_364 + V_7 , V_372 - V_7 ,
L_156 , V_362 , V_369 ) ;
break;
case V_377 :
F_79 ( V_366 , V_362 , & V_368 ) ;
V_7 += snprintf ( V_364 + V_7 , V_372 - V_7 ,
L_157 , V_362 , V_368 ) ;
break;
case V_378 :
F_80 ( V_366 , V_362 , & V_367 ) ;
V_7 += snprintf ( V_364 + V_7 , V_372 - V_7 ,
L_158 , V_362 , V_367 ) ;
break;
case V_379 :
goto V_380;
break;
default:
V_7 = 0 ;
break;
}
return F_48 ( V_3 , V_293 , V_294 , V_364 , V_7 ) ;
V_380:
V_359 = V_351 . V_360 . V_381 ;
V_360 = V_359 ;
V_7 += snprintf ( V_364 + V_7 , V_372 - V_7 ,
L_159 , V_359 ) ;
while ( V_6 > 0 ) {
F_80 ( V_366 , V_360 , & V_367 ) ;
V_7 += snprintf ( V_364 + V_7 , V_372 - V_7 ,
L_160 , V_367 ) ;
V_360 += sizeof( T_1 ) ;
if ( V_360 >= V_372 ) {
V_7 += snprintf ( V_364 + V_7 ,
V_372 - V_7 , L_44 ) ;
break;
}
V_6 -= sizeof( T_1 ) ;
if ( ! V_6 )
V_7 += snprintf ( V_364 + V_7 , V_372 - V_7 ,
L_44 ) ;
else if ( ! ( V_6 % ( 8 * sizeof( T_1 ) ) ) ) {
V_359 += ( 8 * sizeof( T_1 ) ) ;
V_7 += snprintf ( V_364 + V_7 , V_372 - V_7 ,
L_161 , V_359 ) ;
}
}
if ( V_6 == 0 ) {
V_351 . V_360 . V_381 += V_361 ;
if ( V_351 . V_360 . V_381 >= V_372 )
V_351 . V_360 . V_381 = 0 ;
} else
V_351 . V_360 . V_381 = 0 ;
return F_48 ( V_3 , V_293 , V_294 , V_364 , V_7 ) ;
}
static T_3
F_81 ( struct V_276 * V_276 , const char T_4 * V_3 ,
T_5 V_293 , T_6 * V_294 )
{
struct V_278 * V_279 = V_276 -> V_283 ;
struct V_26 * V_27 = (struct V_26 * ) V_279 -> V_277 ;
T_1 V_362 , V_382 , V_363 ;
T_1 V_367 ;
T_2 V_368 ;
T_7 V_369 ;
struct V_365 * V_366 ;
int V_280 ;
V_366 = V_27 -> V_370 ;
if ( ! V_366 )
return - V_332 ;
V_279 -> V_349 = V_350 ;
V_280 = F_70 ( V_3 , V_293 , & V_351 . V_352 ) ;
if ( V_280 < 0 )
return V_280 ;
if ( V_351 . V_352 . V_346 == V_373 ) {
if ( V_280 != V_383 )
goto V_384;
V_362 = V_351 . V_352 . V_348 [ V_374 ] ;
V_363 = V_351 . V_352 . V_348 [ V_375 ] ;
if ( V_363 == V_379 ) {
if ( V_362 % sizeof( T_1 ) )
goto V_384;
V_351 . V_360 . V_381 = V_362 ;
} else if ( ( V_363 != sizeof( T_7 ) ) &&
( V_363 != sizeof( T_2 ) ) &&
( V_363 != sizeof( T_1 ) ) )
goto V_384;
if ( V_363 == sizeof( T_7 ) ) {
if ( V_362 > V_372 - sizeof( T_7 ) )
goto V_384;
if ( V_362 % sizeof( T_7 ) )
goto V_384;
}
if ( V_363 == sizeof( T_2 ) ) {
if ( V_362 > V_372 - sizeof( T_2 ) )
goto V_384;
if ( V_362 % sizeof( T_2 ) )
goto V_384;
}
if ( V_363 == sizeof( T_1 ) ) {
if ( V_362 > V_372 - sizeof( T_1 ) )
goto V_384;
if ( V_362 % sizeof( T_1 ) )
goto V_384;
}
} else if ( V_351 . V_352 . V_346 == V_353 ||
V_351 . V_352 . V_346 == V_354 ||
V_351 . V_352 . V_346 == V_355 ) {
if ( V_280 != V_385 )
goto V_384;
V_362 = V_351 . V_352 . V_348 [ V_374 ] ;
V_363 = V_351 . V_352 . V_348 [ V_375 ] ;
V_382 = V_351 . V_352 . V_348 [ V_386 ] ;
if ( ( V_363 != sizeof( T_7 ) ) &&
( V_363 != sizeof( T_2 ) ) &&
( V_363 != sizeof( T_1 ) ) )
goto V_384;
if ( V_363 == sizeof( T_7 ) ) {
if ( V_362 > V_372 - sizeof( T_7 ) )
goto V_384;
if ( V_362 % sizeof( T_7 ) )
goto V_384;
if ( V_351 . V_352 . V_346 == V_353 )
F_82 ( V_366 , V_362 ,
( T_7 ) V_382 ) ;
if ( V_351 . V_352 . V_346 == V_354 ) {
V_280 = F_78 ( V_366 , V_362 , & V_369 ) ;
if ( ! V_280 ) {
V_369 |= ( T_7 ) V_382 ;
F_82 ( V_366 , V_362 ,
V_369 ) ;
}
}
if ( V_351 . V_352 . V_346 == V_355 ) {
V_280 = F_78 ( V_366 , V_362 , & V_369 ) ;
if ( ! V_280 ) {
V_369 &= ( T_7 ) ( ~ V_382 ) ;
F_82 ( V_366 , V_362 ,
V_369 ) ;
}
}
}
if ( V_363 == sizeof( T_2 ) ) {
if ( V_362 > V_372 - sizeof( T_2 ) )
goto V_384;
if ( V_362 % sizeof( T_2 ) )
goto V_384;
if ( V_351 . V_352 . V_346 == V_353 )
F_83 ( V_366 , V_362 ,
( T_2 ) V_382 ) ;
if ( V_351 . V_352 . V_346 == V_354 ) {
V_280 = F_79 ( V_366 , V_362 , & V_368 ) ;
if ( ! V_280 ) {
V_368 |= ( T_2 ) V_382 ;
F_83 ( V_366 , V_362 ,
V_368 ) ;
}
}
if ( V_351 . V_352 . V_346 == V_355 ) {
V_280 = F_79 ( V_366 , V_362 , & V_368 ) ;
if ( ! V_280 ) {
V_368 &= ( T_2 ) ( ~ V_382 ) ;
F_83 ( V_366 , V_362 ,
V_368 ) ;
}
}
}
if ( V_363 == sizeof( T_1 ) ) {
if ( V_362 > V_372 - sizeof( T_1 ) )
goto V_384;
if ( V_362 % sizeof( T_1 ) )
goto V_384;
if ( V_351 . V_352 . V_346 == V_353 )
F_84 ( V_366 , V_362 , V_382 ) ;
if ( V_351 . V_352 . V_346 == V_354 ) {
V_280 = F_80 ( V_366 , V_362 ,
& V_367 ) ;
if ( ! V_280 ) {
V_367 |= V_382 ;
F_84 ( V_366 , V_362 ,
V_367 ) ;
}
}
if ( V_351 . V_352 . V_346 == V_355 ) {
V_280 = F_80 ( V_366 , V_362 ,
& V_367 ) ;
if ( ! V_280 ) {
V_367 &= ~ V_382 ;
F_84 ( V_366 , V_362 ,
V_367 ) ;
}
}
}
} else
goto V_384;
return V_293 ;
V_384:
memset ( & V_351 , 0 , sizeof( V_351 ) ) ;
return - V_337 ;
}
static T_3
F_85 ( struct V_276 * V_276 , char T_4 * V_3 , T_5 V_293 ,
T_6 * V_294 )
{
struct V_278 * V_279 = V_276 -> V_283 ;
struct V_26 * V_27 = (struct V_26 * ) V_279 -> V_277 ;
int V_359 , V_360 , V_387 , V_7 = 0 , V_6 ;
int V_388 , V_389 , V_390 ;
char * V_364 ;
void T_8 * V_391 ;
T_1 V_392 ;
struct V_365 * V_366 ;
T_1 V_367 ;
V_366 = V_27 -> V_370 ;
if ( ! V_366 )
return 0 ;
V_279 -> V_349 = V_371 ;
if ( ! V_279 -> V_12 )
V_279 -> V_12 = F_2 ( V_393 , V_14 ) ;
if ( ! V_279 -> V_12 )
return 0 ;
V_364 = V_279 -> V_12 ;
if ( * V_294 )
return 0 ;
if ( V_351 . V_352 . V_346 == V_394 ) {
V_388 = V_351 . V_352 . V_348 [ V_395 ] ;
V_360 = V_351 . V_352 . V_348 [ V_396 ] ;
V_389 = V_351 . V_352 . V_348 [ V_397 ] ;
V_390 = V_351 . V_352 . V_348 [ V_398 ] ;
} else
return 0 ;
if ( V_389 == 0 )
return 0 ;
V_392 = F_86 ( V_399 , & V_27 -> V_199 . V_400 ) ;
if ( V_392 == V_401 ) {
if ( V_388 == V_402 )
V_391 = V_27 -> V_199 . V_403 ;
else if ( V_388 == V_404 )
V_391 = V_27 -> V_199 . V_405 ;
else if ( V_388 == V_406 )
V_391 = V_27 -> V_199 . V_407 ;
else
return 0 ;
} else if ( V_392 == V_408 ) {
if ( V_388 == V_402 )
V_391 = V_27 -> V_199 . V_403 ;
else
return 0 ;
} else
return 0 ;
if ( V_389 == V_409 ) {
V_387 = V_360 ;
V_367 = F_17 ( V_391 + V_387 ) ;
V_7 += snprintf ( V_364 + V_7 , V_393 - V_7 ,
L_162 , V_387 , V_367 ) ;
} else
goto V_410;
return F_48 ( V_3 , V_293 , V_294 , V_364 , V_7 ) ;
V_410:
V_359 = V_351 . V_360 . V_381 ;
V_387 = V_359 ;
V_7 += snprintf ( V_364 + V_7 , V_393 - V_7 ,
L_163 , V_359 ) ;
V_6 = V_411 ;
while ( V_6 > 0 ) {
V_367 = F_17 ( V_391 + V_387 ) ;
V_7 += snprintf ( V_364 + V_7 , V_393 - V_7 ,
L_160 , V_367 ) ;
V_387 += sizeof( T_1 ) ;
if ( V_389 == V_412 ) {
if ( V_387 >= V_390 ) {
V_7 += snprintf ( V_364 + V_7 ,
V_393 - V_7 , L_44 ) ;
break;
}
} else {
if ( V_387 >= V_360 +
( V_389 * sizeof( T_1 ) ) ) {
V_7 += snprintf ( V_364 + V_7 ,
V_393 - V_7 , L_44 ) ;
break;
}
}
V_6 -= sizeof( T_1 ) ;
if ( ! V_6 )
V_7 += snprintf ( V_364 + V_7 ,
V_393 - V_7 , L_44 ) ;
else if ( ! ( V_6 % ( 8 * sizeof( T_1 ) ) ) ) {
V_359 += ( 8 * sizeof( T_1 ) ) ;
V_7 += snprintf ( V_364 + V_7 ,
V_393 - V_7 ,
L_164 , V_359 ) ;
}
}
if ( V_6 == 0 ) {
V_351 . V_360 . V_381 += V_411 ;
if ( V_389 == V_412 ) {
if ( V_351 . V_360 . V_381 >= V_390 )
V_351 . V_360 . V_381 = 0 ;
} else {
if ( V_387 >= V_360 +
( V_389 * sizeof( T_1 ) ) )
V_351 . V_360 . V_381 = V_360 ;
}
} else {
if ( V_389 == V_412 )
V_351 . V_360 . V_381 = 0 ;
else
V_351 . V_360 . V_381 = V_360 ;
}
return F_48 ( V_3 , V_293 , V_294 , V_364 , V_7 ) ;
}
static T_3
F_87 ( struct V_276 * V_276 , const char T_4 * V_3 ,
T_5 V_293 , T_6 * V_294 )
{
struct V_278 * V_279 = V_276 -> V_283 ;
struct V_26 * V_27 = (struct V_26 * ) V_279 -> V_277 ;
T_1 V_388 , V_390 , V_360 , V_382 , V_389 ;
struct V_365 * V_366 ;
void T_8 * V_391 ;
T_1 V_392 ;
T_1 V_367 ;
int V_280 ;
V_366 = V_27 -> V_370 ;
if ( ! V_366 )
return - V_332 ;
V_279 -> V_349 = V_350 ;
V_280 = F_70 ( V_3 , V_293 , & V_351 . V_352 ) ;
if ( V_280 < 0 )
return V_280 ;
V_392 = F_86 ( V_399 , & V_27 -> V_199 . V_400 ) ;
V_388 = V_351 . V_352 . V_348 [ V_395 ] ;
if ( V_392 == V_401 ) {
if ( ( V_388 != V_402 ) &&
( V_388 != V_404 ) &&
( V_388 != V_406 ) )
goto V_384;
} else if ( V_392 == V_408 ) {
if ( V_388 != V_402 )
goto V_384;
} else
goto V_384;
if ( V_392 == V_401 ) {
if ( V_388 == V_402 ) {
V_351 . V_352 . V_348 [ V_398 ] =
V_413 ;
V_391 = V_27 -> V_199 . V_403 ;
} else if ( V_388 == V_404 ) {
V_351 . V_352 . V_348 [ V_398 ] =
V_414 ;
V_391 = V_27 -> V_199 . V_405 ;
} else if ( V_388 == V_406 ) {
V_351 . V_352 . V_348 [ V_398 ] =
V_415 ;
V_391 = V_27 -> V_199 . V_407 ;
} else
goto V_384;
} else if ( V_392 == V_408 ) {
if ( V_388 == V_402 ) {
V_351 . V_352 . V_348 [ V_398 ] =
V_416 ;
V_391 = V_27 -> V_199 . V_403 ;
} else
goto V_384;
} else
goto V_384;
V_360 = V_351 . V_352 . V_348 [ V_396 ] ;
if ( V_360 % sizeof( T_1 ) )
goto V_384;
V_390 = V_351 . V_352 . V_348 [ V_398 ] ;
if ( V_351 . V_352 . V_346 == V_394 ) {
if ( V_280 != V_417 )
goto V_384;
V_389 = V_351 . V_352 . V_348 [ V_397 ] ;
if ( V_389 == V_412 ) {
if ( V_360 > V_390 - sizeof( T_1 ) )
goto V_384;
V_351 . V_360 . V_381 = V_360 ;
} else if ( V_389 > V_409 ) {
if ( V_360 + V_389 * sizeof( T_1 ) > V_390 )
goto V_384;
V_351 . V_360 . V_381 = V_360 ;
} else if ( V_389 != V_409 )
goto V_384;
} else if ( V_351 . V_352 . V_346 == V_418 ||
V_351 . V_352 . V_346 == V_419 ||
V_351 . V_352 . V_346 == V_420 ) {
if ( V_280 != V_421 )
goto V_384;
V_389 = V_409 ;
V_382 = V_351 . V_352 . V_348 [ V_422 ] ;
if ( V_351 . V_352 . V_346 == V_418 ) {
F_88 ( V_382 , V_391 + V_360 ) ;
F_17 ( V_391 + V_360 ) ;
}
if ( V_351 . V_352 . V_346 == V_419 ) {
V_367 = F_17 ( V_391 + V_360 ) ;
V_367 |= V_382 ;
F_88 ( V_367 , V_391 + V_360 ) ;
F_17 ( V_391 + V_360 ) ;
}
if ( V_351 . V_352 . V_346 == V_420 ) {
V_367 = F_17 ( V_391 + V_360 ) ;
V_367 &= ~ V_382 ;
F_88 ( V_367 , V_391 + V_360 ) ;
F_17 ( V_391 + V_360 ) ;
}
} else
goto V_384;
return V_293 ;
V_384:
memset ( & V_351 , 0 , sizeof( V_351 ) ) ;
return - V_337 ;
}
static int
F_89 ( struct V_423 * V_424 , char * V_425 ,
char * V_364 , int V_7 )
{
if ( ! V_424 )
return V_7 ;
V_7 += snprintf ( V_364 + V_7 , V_426 - V_7 ,
L_165 , V_425 ) ;
V_7 += snprintf ( V_364 + V_7 , V_426 - V_7 ,
L_166 ,
V_424 -> V_427 , V_424 -> V_428 ,
( unsigned long long ) V_424 -> V_429 ) ;
V_7 += snprintf ( V_364 + V_7 , V_426 - V_7 ,
L_167
L_168 ,
V_424 -> V_430 , V_424 -> V_59 ,
V_424 -> V_431 , V_424 -> V_432 ,
V_424 -> V_433 , V_424 -> V_434 ) ;
V_7 += snprintf ( V_364 + V_7 ,
V_426 - V_7 , L_44 ) ;
return V_7 ;
}
static int
F_90 ( struct V_26 * V_27 , char * V_425 , char * V_364 ,
int * V_7 , int V_435 , int V_436 )
{
struct V_423 * V_424 ;
int V_437 ;
for ( V_437 = 0 ; V_437 < V_27 -> V_438 ; V_437 ++ ) {
V_424 = V_27 -> V_199 . V_439 [ V_437 ] ;
if ( V_424 -> V_427 != V_436 )
continue;
* V_7 = F_89 ( V_424 , V_425 , V_364 , * V_7 ) ;
if ( * V_7 >= V_435 )
return 1 ;
}
for ( V_437 = 0 ; V_437 < V_27 -> V_440 ; V_437 ++ ) {
V_424 = V_27 -> V_199 . V_441 [ V_437 ] ;
if ( V_424 -> V_427 != V_436 )
continue;
* V_7 = F_89 ( V_424 , V_425 , V_364 , * V_7 ) ;
if ( * V_7 >= V_435 )
return 1 ;
}
return 0 ;
}
static int
F_91 ( struct V_423 * V_424 , char * V_442 ,
char * V_364 , int V_7 )
{
if ( ! V_424 )
return V_7 ;
V_7 += snprintf ( V_364 + V_7 , V_426 - V_7 ,
L_169 , V_442 ) ;
V_7 += snprintf ( V_364 + V_7 , V_426 - V_7 ,
L_170
L_171 ,
V_424 -> V_427 , V_424 -> V_428 , V_424 -> V_443 ,
V_424 -> V_444 , ( unsigned long long ) V_424 -> V_429 ) ;
V_7 += snprintf ( V_364 + V_7 , V_426 - V_7 ,
L_172
L_168 ,
V_424 -> V_430 , V_424 -> V_59 ,
V_424 -> V_431 , V_424 -> V_432 ,
V_424 -> V_433 , V_424 -> V_434 ) ;
V_7 += snprintf ( V_364 + V_7 , V_426 - V_7 , L_44 ) ;
return V_7 ;
}
static int
F_92 ( struct V_423 * V_424 , struct V_423 * V_445 ,
char * V_446 , char * V_364 , int V_7 )
{
if ( ! V_424 || ! V_445 )
return V_7 ;
V_7 += snprintf ( V_364 + V_7 , V_426 - V_7 ,
L_173 , V_446 ) ;
V_7 += snprintf ( V_364 + V_7 , V_426 - V_7 ,
L_174
L_175 ,
V_424 -> V_427 , V_424 -> V_428 , V_424 -> V_443 ,
V_424 -> V_444 , ( unsigned long long ) V_424 -> V_429 ) ;
V_7 += snprintf ( V_364 + V_7 , V_426 - V_7 ,
L_176
L_177 ,
V_424 -> V_430 , V_424 -> V_59 , V_424 -> V_431 ,
V_424 -> V_432 , V_424 -> V_433 , V_424 -> V_434 ) ;
V_7 += snprintf ( V_364 + V_7 , V_426 - V_7 ,
L_178
L_177 ,
V_445 -> V_430 , V_445 -> V_59 ,
V_445 -> V_431 , V_445 -> V_432 ,
V_445 -> V_433 , V_445 -> V_434 ) ;
return V_7 ;
}
static int
F_93 ( struct V_26 * V_27 , char * V_364 ,
int * V_7 , int V_435 , int V_447 , int V_448 )
{
struct V_423 * V_424 ;
int V_437 , V_280 ;
for ( V_437 = 0 ; V_437 < V_27 -> V_438 ; V_437 ++ ) {
V_424 = V_27 -> V_199 . V_449 [ V_437 ] ;
if ( V_424 -> V_427 != V_448 )
continue;
* V_7 = F_91 ( V_424 , L_179 , V_364 , * V_7 ) ;
V_424 -> V_450 = 0 ;
if ( * V_7 >= V_435 )
return 1 ;
V_280 = F_90 ( V_27 , L_179 , V_364 , V_7 ,
V_435 , V_424 -> V_430 ) ;
if ( V_280 )
return 1 ;
}
for ( V_437 = 0 ; V_437 < V_27 -> V_440 ; V_437 ++ ) {
V_424 = V_27 -> V_199 . V_451 [ V_437 ] ;
if ( V_424 -> V_427 != V_448 )
continue;
* V_7 = F_91 ( V_424 , L_119 , V_364 , * V_7 ) ;
V_424 -> V_450 = 0 ;
if ( * V_7 >= V_435 )
return 1 ;
V_280 = F_90 ( V_27 , L_119 , V_364 , V_7 ,
V_435 , V_424 -> V_430 ) ;
if ( V_280 )
return 1 ;
}
if ( V_447 < V_27 -> V_452 ) {
V_424 = V_27 -> V_199 . V_453 [ V_447 ] ;
* V_7 = F_91 ( V_424 , L_180 , V_364 , * V_7 ) ;
V_424 -> V_450 = 0 ;
if ( * V_7 >= V_435 )
return 1 ;
V_424 = V_27 -> V_199 . V_454 [ V_447 ] ;
* V_7 = F_92 ( V_424 ,
V_27 -> V_199 . V_455 [ V_447 ] ,
L_181 , V_364 , * V_7 ) ;
if ( * V_7 >= V_435 )
return 1 ;
}
return 0 ;
}
static int
F_94 ( struct V_423 * V_424 , char * V_456 ,
char * V_364 , int V_7 )
{
if ( ! V_424 )
return V_7 ;
V_7 += snprintf ( V_364 + V_7 , V_426 - V_7 ,
L_182
L_183 ,
V_456 , V_424 -> V_428 , V_424 -> V_443 , V_424 -> V_444 ,
( unsigned long long ) V_424 -> V_429 ) ;
V_7 += snprintf ( V_364 + V_7 , V_426 - V_7 ,
L_184
L_168 ,
V_424 -> V_430 , V_424 -> V_59 , V_424 -> V_431 ,
V_424 -> V_432 , V_424 -> V_433 , V_424 -> V_434 ) ;
V_7 += snprintf ( V_364 + V_7 , V_426 - V_7 , L_44 ) ;
return V_7 ;
}
static T_3
F_95 ( struct V_276 * V_276 , char T_4 * V_3 , T_5 V_293 ,
T_6 * V_294 )
{
struct V_278 * V_279 = V_276 -> V_283 ;
struct V_26 * V_27 = (struct V_26 * ) V_279 -> V_277 ;
char * V_364 ;
int V_435 , V_280 , V_457 , V_7 = 0 ;
struct V_423 * V_424 = NULL ;
if ( ! V_279 -> V_12 )
V_279 -> V_12 = F_2 ( V_426 , V_14 ) ;
if ( ! V_279 -> V_12 )
return 0 ;
V_364 = V_279 -> V_12 ;
V_435 = V_426 - 256 ;
if ( * V_294 )
return 0 ;
F_8 ( & V_27 -> V_49 ) ;
if ( V_27 -> V_199 . V_458 && V_27 -> V_459 ) {
V_457 = V_27 -> V_460 ;
if ( V_27 -> V_461 && ( V_457 >= V_27 -> V_459 ) ) {
V_27 -> V_460 = 0 ;
goto V_462;
}
V_27 -> V_460 ++ ;
if ( V_27 -> V_460 >= V_27 -> V_459 )
if ( V_27 -> V_461 == 0 )
V_27 -> V_460 = 0 ;
V_7 += snprintf ( V_364 + V_7 , V_426 - V_7 ,
L_185 ,
V_457 , V_27 -> V_459 ) ;
V_424 = V_27 -> V_199 . V_458 [ V_457 ] ;
if ( ! V_424 )
goto V_256;
V_7 = F_94 ( V_424 , L_186 , V_364 , V_7 ) ;
V_424 -> V_463 = 0 ;
if ( V_7 >= V_435 )
goto V_464;
V_280 = F_93 ( V_27 , V_364 , & V_7 ,
V_435 , V_457 , V_424 -> V_430 ) ;
if ( V_280 )
goto V_464;
if ( V_457 )
goto V_256;
V_424 = V_27 -> V_199 . V_465 ;
V_7 = F_91 ( V_424 , L_187 , V_364 , V_7 ) ;
if ( V_7 >= V_435 )
goto V_464;
V_424 = V_27 -> V_199 . V_466 ;
V_7 = F_89 ( V_424 , L_187 , V_364 , V_7 ) ;
if ( V_7 >= V_435 )
goto V_464;
V_424 = V_27 -> V_199 . V_467 ;
V_7 = F_91 ( V_424 , L_188 , V_364 , V_7 ) ;
if ( V_424 )
V_424 -> V_450 = 0 ;
if ( V_7 >= V_435 )
goto V_464;
V_424 = V_27 -> V_199 . V_468 ;
V_7 = F_89 ( V_424 , L_188 , V_364 , V_7 ) ;
if ( V_7 >= V_435 )
goto V_464;
V_424 = V_27 -> V_199 . V_469 ;
V_7 = F_91 ( V_424 , L_189 ,
V_364 , V_7 ) ;
if ( V_424 )
V_424 -> V_450 = 0 ;
if ( V_7 >= V_435 )
goto V_464;
V_424 = V_27 -> V_199 . V_470 ;
V_7 = F_89 ( V_424 , L_189 ,
V_364 , V_7 ) ;
if ( V_7 >= V_435 )
goto V_464;
V_424 = V_27 -> V_199 . V_471 ;
V_7 = F_92 ( V_424 , V_27 -> V_199 . V_472 ,
L_190 , V_364 , V_7 ) ;
if ( V_7 >= V_435 )
goto V_464;
goto V_256;
}
V_462:
if ( V_27 -> V_461 ) {
V_424 = V_27 -> V_199 . V_473 ;
V_7 = F_94 ( V_424 , L_191 , V_364 , V_7 ) ;
if ( V_424 )
V_424 -> V_463 = 0 ;
if ( V_7 >= V_435 )
goto V_464;
V_424 = V_27 -> V_199 . V_474 ;
V_7 = F_91 ( V_424 , L_192 , V_364 , V_7 ) ;
if ( V_424 )
V_424 -> V_450 = 0 ;
if ( V_7 >= V_435 )
goto V_464;
V_424 = V_27 -> V_199 . V_475 ;
V_7 = F_89 ( V_424 , L_192 , V_364 , V_7 ) ;
if ( V_7 >= V_435 )
goto V_464;
}
F_13 ( & V_27 -> V_49 ) ;
return F_48 ( V_3 , V_293 , V_294 , V_364 , V_7 ) ;
V_464:
V_7 += snprintf ( V_364 + V_7 ,
V_426 - V_7 , L_193 ) ;
V_256:
F_13 ( & V_27 -> V_49 ) ;
return F_48 ( V_3 , V_293 , V_294 , V_364 , V_7 ) ;
}
static int
F_96 ( struct V_423 * V_476 , int V_6 , int V_363 )
{
if ( ( V_363 != 1 ) && ( V_363 != V_477 ) )
return - V_337 ;
if ( V_6 > V_476 -> V_59 - 1 )
return - V_337 ;
return 0 ;
}
static int
F_97 ( char * V_364 , int V_7 , struct V_423 * V_478 ,
T_1 V_6 )
{
int V_360 , V_479 ;
T_1 * V_480 ;
if ( ! V_364 || ! V_478 )
return 0 ;
V_479 = V_478 -> V_431 ;
V_7 += snprintf ( V_364 + V_7 , V_481 - V_7 ,
L_194 , V_6 ) ;
V_360 = 0 ;
V_480 = V_478 -> V_482 [ V_6 ] . V_483 ;
while ( V_479 > 0 ) {
V_7 += snprintf ( V_364 + V_7 , V_481 - V_7 ,
L_160 , * V_480 ) ;
V_480 ++ ;
V_360 += sizeof( T_1 ) ;
V_479 -= sizeof( T_1 ) ;
if ( V_479 > 0 && ! ( V_360 % ( 4 * sizeof( T_1 ) ) ) )
V_7 += snprintf ( V_364 + V_7 ,
V_481 - V_7 , L_44 ) ;
}
V_7 += snprintf ( V_364 + V_7 , V_481 - V_7 , L_44 ) ;
return V_7 ;
}
static T_3
F_98 ( struct V_276 * V_276 , char T_4 * V_3 , T_5 V_293 ,
T_6 * V_294 )
{
struct V_278 * V_279 = V_276 -> V_283 ;
T_1 V_484 , V_6 , V_363 ;
struct V_423 * V_478 = NULL ;
char * V_364 ;
int V_7 = 0 ;
V_279 -> V_349 = V_371 ;
if ( ! V_279 -> V_12 )
V_279 -> V_12 = F_2 ( V_481 , V_14 ) ;
if ( ! V_279 -> V_12 )
return 0 ;
V_364 = V_279 -> V_12 ;
if ( * V_294 )
return 0 ;
if ( V_351 . V_352 . V_346 == V_485 ) {
V_6 = V_351 . V_352 . V_348 [ V_486 ] ;
V_363 = V_351 . V_352 . V_348 [ V_487 ] ;
V_478 = (struct V_423 * ) V_351 . V_488 ;
} else
return 0 ;
if ( V_363 == V_477 )
goto V_489;
V_7 = F_97 ( V_364 , V_7 , V_478 , V_6 ) ;
return F_48 ( V_3 , V_293 , V_294 , V_364 , V_7 ) ;
V_489:
V_484 = V_351 . V_360 . V_381 ;
V_6 = V_484 ;
while ( V_7 < V_490 - V_478 -> V_431 ) {
V_7 = F_97 ( V_364 , V_7 , V_478 , V_6 ) ;
V_6 ++ ;
if ( V_6 > V_478 -> V_59 - 1 )
break;
}
if ( V_6 > V_478 -> V_59 - 1 )
V_6 = 0 ;
V_351 . V_360 . V_381 = V_6 ;
return F_48 ( V_3 , V_293 , V_294 , V_364 , V_7 ) ;
}
static T_3
F_99 ( struct V_276 * V_276 , const char T_4 * V_3 ,
T_5 V_293 , T_6 * V_294 )
{
struct V_278 * V_279 = V_276 -> V_283 ;
struct V_26 * V_27 = (struct V_26 * ) V_279 -> V_277 ;
T_1 V_437 , V_491 , V_492 , V_6 , V_363 , V_360 , V_382 ;
T_1 * V_480 ;
struct V_423 * V_478 , * V_424 ;
int V_280 ;
V_279 -> V_349 = V_350 ;
V_280 = F_70 ( V_3 , V_293 , & V_351 . V_352 ) ;
if ( V_280 < 0 )
return V_280 ;
V_491 = V_351 . V_352 . V_348 [ V_493 ] ;
V_492 = V_351 . V_352 . V_348 [ V_494 ] ;
V_6 = V_351 . V_352 . V_348 [ V_486 ] ;
V_363 = V_351 . V_352 . V_348 [ V_487 ] ;
V_360 = V_351 . V_352 . V_348 [ V_495 ] ;
V_382 = V_351 . V_352 . V_348 [ V_496 ] ;
if ( V_351 . V_352 . V_346 == V_356 ||
V_351 . V_352 . V_346 == V_357 ||
V_351 . V_352 . V_346 == V_358 ) {
if ( V_280 != V_497 )
goto V_384;
if ( V_363 != 1 )
goto V_384;
} else if ( V_351 . V_352 . V_346 == V_485 ) {
if ( V_280 != V_498 )
goto V_384;
} else
goto V_384;
switch ( V_491 ) {
case V_499 :
if ( V_27 -> V_199 . V_458 ) {
for ( V_437 = 0 ; V_437 < V_27 -> V_459 ; V_437 ++ ) {
V_424 = V_27 -> V_199 . V_458 [ V_437 ] ;
if ( V_424 && V_424 -> V_430 == V_492 ) {
V_280 = F_96 ( V_424 ,
V_6 , V_363 ) ;
if ( V_280 )
goto V_384;
V_351 . V_488 = V_424 ;
goto V_500;
}
}
}
goto V_384;
break;
case V_501 :
if ( V_27 -> V_199 . V_465 &&
V_27 -> V_199 . V_465 -> V_430 == V_492 ) {
V_280 = F_96 (
V_27 -> V_199 . V_465 , V_6 , V_363 ) ;
if ( V_280 )
goto V_384;
V_351 . V_488 = V_27 -> V_199 . V_465 ;
goto V_500;
}
if ( V_27 -> V_199 . V_467 &&
V_27 -> V_199 . V_467 -> V_430 == V_492 ) {
V_280 = F_96 (
V_27 -> V_199 . V_467 , V_6 , V_363 ) ;
if ( V_280 )
goto V_384;
V_351 . V_488 = V_27 -> V_199 . V_467 ;
goto V_500;
}
if ( V_27 -> V_199 . V_469 &&
V_27 -> V_199 . V_469 -> V_430 == V_492 ) {
V_280 = F_96 (
V_27 -> V_199 . V_469 , V_6 , V_363 ) ;
if ( V_280 )
goto V_384;
V_351 . V_488 = V_27 -> V_199 . V_469 ;
goto V_500;
}
if ( V_27 -> V_199 . V_449 ) {
for ( V_437 = 0 ; V_437 < V_27 -> V_438 ;
V_437 ++ ) {
V_424 = V_27 -> V_199 . V_449 [ V_437 ] ;
if ( V_424 && V_424 -> V_430 == V_492 ) {
V_280 = F_96 (
V_424 , V_6 , V_363 ) ;
if ( V_280 )
goto V_384;
V_351 . V_488 = V_424 ;
goto V_500;
}
}
}
if ( V_27 -> V_199 . V_451 ) {
V_437 = 0 ;
do {
if ( V_27 -> V_199 . V_451 [ V_437 ] &&
V_27 -> V_199 . V_451 [ V_437 ] -> V_430 ==
V_492 ) {
V_280 = F_96 (
V_27 -> V_199 . V_451 [ V_437 ] ,
V_6 , V_363 ) ;
if ( V_280 )
goto V_384;
V_351 . V_488 =
V_27 -> V_199 . V_451 [ V_437 ] ;
goto V_500;
}
} while ( ++ V_437 < V_27 -> V_440 );
}
goto V_384;
break;
case V_502 :
if ( V_27 -> V_199 . V_466 &&
V_27 -> V_199 . V_466 -> V_430 == V_492 ) {
V_280 = F_96 (
V_27 -> V_199 . V_466 , V_6 , V_363 ) ;
if ( V_280 )
goto V_384;
V_351 . V_488 = V_27 -> V_199 . V_466 ;
goto V_500;
}
goto V_384;
break;
case V_503 :
if ( V_27 -> V_199 . V_468 &&
V_27 -> V_199 . V_468 -> V_430 == V_492 ) {
V_280 = F_96 (
V_27 -> V_199 . V_468 , V_6 , V_363 ) ;
if ( V_280 )
goto V_384;
V_351 . V_488 = V_27 -> V_199 . V_468 ;
goto V_500;
}
if ( V_27 -> V_199 . V_470 &&
V_27 -> V_199 . V_470 -> V_430 == V_492 ) {
V_280 = F_96 (
V_27 -> V_199 . V_470 , V_6 , V_363 ) ;
if ( V_280 )
goto V_384;
V_351 . V_488 = V_27 -> V_199 . V_470 ;
goto V_500;
}
if ( V_27 -> V_199 . V_439 ) {
for ( V_437 = 0 ; V_437 < V_27 -> V_438 ;
V_437 ++ ) {
V_424 = V_27 -> V_199 . V_439 [ V_437 ] ;
if ( V_424 && V_424 -> V_430 == V_492 ) {
V_280 = F_96 (
V_424 , V_6 , V_363 ) ;
if ( V_280 )
goto V_384;
V_351 . V_488 = V_424 ;
goto V_500;
}
}
}
if ( V_27 -> V_199 . V_441 ) {
for ( V_437 = 0 ; V_437 < V_27 -> V_440 ;
V_437 ++ ) {
V_424 = V_27 -> V_199 . V_441 [ V_437 ] ;
if ( V_424 && V_424 -> V_430 == V_492 ) {
V_280 = F_96 (
V_424 , V_6 , V_363 ) ;
if ( V_280 )
goto V_384;
V_351 . V_488 = V_424 ;
goto V_500;
}
}
}
if ( V_27 -> V_199 . V_441 ) {
for ( V_437 = 0 ; V_437 < V_27 -> V_440 ;
V_437 ++ ) {
if ( ! V_27 -> V_199 . V_441 [ V_437 ] )
continue;
if ( V_27 -> V_199 . V_441 [ V_437 ] -> V_430 ==
V_492 ) {
V_280 = F_96 (
V_27 -> V_199 . V_441 [ V_437 ] ,
V_6 , V_363 ) ;
if ( V_280 )
goto V_384;
V_351 . V_488 =
V_27 -> V_199 . V_441 [ V_437 ] ;
goto V_500;
}
}
}
goto V_384;
break;
case V_504 :
if ( V_27 -> V_199 . V_471 &&
V_27 -> V_199 . V_471 -> V_430 == V_492 ) {
V_280 = F_96 (
V_27 -> V_199 . V_471 , V_6 , V_363 ) ;
if ( V_280 )
goto V_384;
V_351 . V_488 = V_27 -> V_199 . V_471 ;
goto V_500;
}
if ( V_27 -> V_199 . V_472 &&
V_27 -> V_199 . V_472 -> V_430 == V_492 ) {
V_280 = F_96 (
V_27 -> V_199 . V_472 , V_6 , V_363 ) ;
if ( V_280 )
goto V_384;
V_351 . V_488 = V_27 -> V_199 . V_472 ;
goto V_500;
}
goto V_384;
break;
default:
goto V_384;
break;
}
V_500:
if ( V_351 . V_352 . V_346 == V_485 ) {
if ( V_363 == V_477 )
V_351 . V_360 . V_381 = V_6 ;
}
if ( V_351 . V_352 . V_346 == V_356 ||
V_351 . V_352 . V_346 == V_357 ||
V_351 . V_352 . V_346 == V_358 ) {
V_478 = (struct V_423 * ) V_351 . V_488 ;
if ( V_360 > V_478 -> V_431 / sizeof( T_1 ) - 1 )
goto V_384;
V_480 = V_478 -> V_482 [ V_6 ] . V_483 ;
V_480 += V_360 ;
if ( V_351 . V_352 . V_346 == V_356 )
* V_480 = V_382 ;
if ( V_351 . V_352 . V_346 == V_357 )
* V_480 |= V_382 ;
if ( V_351 . V_352 . V_346 == V_358 )
* V_480 &= ~ V_382 ;
}
return V_293 ;
V_384:
memset ( & V_351 , 0 , sizeof( V_351 ) ) ;
return - V_337 ;
}
static int
F_100 ( struct V_26 * V_27 , char * V_364 ,
int V_7 , T_1 V_505 )
{
if ( ! V_364 )
return 0 ;
switch ( V_505 ) {
case V_506 :
V_7 += snprintf ( V_364 + V_7 , V_507 - V_7 ,
L_195 ,
F_17 ( V_27 -> V_199 . V_508 ) ) ;
break;
case V_509 :
V_7 += snprintf ( V_364 + V_7 , V_507 - V_7 ,
L_196 ,
F_17 ( V_27 -> V_199 . V_510 ) ) ;
break;
case V_511 :
V_7 += snprintf ( V_364 + V_7 , V_507 - V_7 ,
L_197 ,
F_17 ( V_27 -> V_199 . V_512 ) ) ;
break;
case V_513 :
V_7 += snprintf ( V_364 + V_7 , V_507 - V_7 ,
L_198 ,
F_17 ( V_27 -> V_199 . V_514 ) ) ;
break;
default:
break;
}
return V_7 ;
}
static T_3
F_101 ( struct V_276 * V_276 , char T_4 * V_3 , T_5 V_293 ,
T_6 * V_294 )
{
struct V_278 * V_279 = V_276 -> V_283 ;
struct V_26 * V_27 = (struct V_26 * ) V_279 -> V_277 ;
T_1 V_515 , V_5 ;
char * V_364 ;
int V_7 = 0 ;
V_279 -> V_349 = V_371 ;
if ( ! V_279 -> V_12 )
V_279 -> V_12 = F_2 ( V_507 , V_14 ) ;
if ( ! V_279 -> V_12 )
return 0 ;
V_364 = V_279 -> V_12 ;
if ( * V_294 )
return 0 ;
if ( V_351 . V_352 . V_346 == V_516 )
V_515 = V_351 . V_352 . V_348 [ V_517 ] ;
else
return 0 ;
if ( V_515 == V_518 )
for ( V_5 = 1 ; V_5 <= V_519 ; V_5 ++ )
V_7 = F_100 ( V_27 ,
V_364 , V_7 , V_5 ) ;
else
V_7 = F_100 ( V_27 ,
V_364 , V_7 , V_515 ) ;
return F_48 ( V_3 , V_293 , V_294 , V_364 , V_7 ) ;
}
static T_3
F_102 ( struct V_276 * V_276 , const char T_4 * V_3 ,
T_5 V_293 , T_6 * V_294 )
{
struct V_278 * V_279 = V_276 -> V_283 ;
struct V_26 * V_27 = (struct V_26 * ) V_279 -> V_277 ;
T_1 V_515 , V_382 , V_520 = 0 ;
void T_8 * V_521 ;
int V_280 ;
V_279 -> V_349 = V_350 ;
V_280 = F_70 ( V_3 , V_293 , & V_351 . V_352 ) ;
if ( V_280 < 0 )
return V_280 ;
V_515 = V_351 . V_352 . V_348 [ V_517 ] ;
V_382 = V_351 . V_352 . V_348 [ V_522 ] ;
if ( V_351 . V_352 . V_346 == V_523 ||
V_351 . V_352 . V_346 == V_524 ||
V_351 . V_352 . V_346 == V_525 ) {
if ( V_280 != V_526 )
goto V_384;
if ( V_515 > V_519 )
goto V_384;
} else if ( V_351 . V_352 . V_346 == V_516 ) {
if ( V_280 != V_527 )
goto V_384;
if ( ( V_515 > V_519 ) &&
( V_515 != V_518 ) )
goto V_384;
} else
goto V_384;
if ( V_351 . V_352 . V_346 == V_523 ||
V_351 . V_352 . V_346 == V_524 ||
V_351 . V_352 . V_346 == V_525 ) {
switch ( V_515 ) {
case V_506 :
V_521 = V_27 -> V_199 . V_508 ;
break;
case V_509 :
V_521 = V_27 -> V_199 . V_510 ;
break;
case V_511 :
V_521 = V_27 -> V_199 . V_512 ;
break;
case V_513 :
V_521 = V_27 -> V_199 . V_514 ;
break;
default:
goto V_384;
}
if ( V_351 . V_352 . V_346 == V_523 )
V_520 = V_382 ;
if ( V_351 . V_352 . V_346 == V_524 ) {
V_520 = F_17 ( V_521 ) ;
V_520 |= V_382 ;
}
if ( V_351 . V_352 . V_346 == V_525 ) {
V_520 = F_17 ( V_521 ) ;
V_520 &= ~ V_382 ;
}
F_88 ( V_520 , V_521 ) ;
F_17 ( V_521 ) ;
}
return V_293 ;
V_384:
memset ( & V_351 , 0 , sizeof( V_351 ) ) ;
return - V_337 ;
}
static int
F_103 ( struct V_26 * V_27 , char * V_364 ,
int V_7 , T_1 V_528 )
{
if ( ! V_364 )
return 0 ;
switch ( V_528 ) {
case V_529 :
V_7 += snprintf ( V_364 + V_7 , V_530 - V_7 ,
L_199 ,
F_17 ( V_27 -> V_199 . V_403 +
V_531 ) ) ;
break;
case V_532 :
V_7 += snprintf ( V_364 + V_7 , V_530 - V_7 ,
L_200 ,
F_17 ( V_27 -> V_199 . V_403 +
V_533 ) ) ;
break;
case V_534 :
V_7 += snprintf ( V_364 + V_7 , V_530 - V_7 ,
L_201 ,
F_17 ( V_27 -> V_199 . V_403 +
V_535 ) ) ;
break;
case V_536 :
V_7 += snprintf ( V_364 + V_7 , V_530 - V_7 ,
L_202 ,
F_17 ( V_27 -> V_199 . V_403 +
V_537 ) ) ;
break;
case V_538 :
V_7 += snprintf ( V_364 + V_7 , V_530 - V_7 ,
L_203 ,
F_17 ( V_27 -> V_199 . V_403 +
V_539 ) ) ;
break;
case V_540 :
V_7 += snprintf ( V_364 + V_7 , V_530 - V_7 ,
L_204 ,
F_17 ( V_27 -> V_199 . V_403 +
V_541 ) ) ;
break;
default:
break;
}
return V_7 ;
}
static T_3
F_104 ( struct V_276 * V_276 , char T_4 * V_3 , T_5 V_293 ,
T_6 * V_294 )
{
struct V_278 * V_279 = V_276 -> V_283 ;
struct V_26 * V_27 = (struct V_26 * ) V_279 -> V_277 ;
T_1 V_542 , V_5 ;
char * V_364 ;
int V_7 = 0 ;
V_279 -> V_349 = V_371 ;
if ( ! V_279 -> V_12 )
V_279 -> V_12 = F_2 ( V_530 , V_14 ) ;
if ( ! V_279 -> V_12 )
return 0 ;
V_364 = V_279 -> V_12 ;
if ( * V_294 )
return 0 ;
if ( V_351 . V_352 . V_346 == V_543 )
V_542 = V_351 . V_352 . V_348 [ V_544 ] ;
else
return 0 ;
if ( V_542 == V_545 )
for ( V_5 = 1 ; V_5 <= V_546 ; V_5 ++ )
V_7 = F_103 ( V_27 ,
V_364 , V_7 , V_5 ) ;
else
V_7 = F_103 ( V_27 ,
V_364 , V_7 , V_542 ) ;
return F_48 ( V_3 , V_293 , V_294 , V_364 , V_7 ) ;
}
static T_3
F_105 ( struct V_276 * V_276 , const char T_4 * V_3 ,
T_5 V_293 , T_6 * V_294 )
{
struct V_278 * V_279 = V_276 -> V_283 ;
struct V_26 * V_27 = (struct V_26 * ) V_279 -> V_277 ;
T_1 V_542 , V_382 , V_520 = 0 ;
void T_8 * V_547 ;
int V_280 ;
V_279 -> V_349 = V_350 ;
V_280 = F_70 ( V_3 , V_293 , & V_351 . V_352 ) ;
if ( V_280 < 0 )
return V_280 ;
V_542 = V_351 . V_352 . V_348 [ V_544 ] ;
V_382 = V_351 . V_352 . V_348 [ V_548 ] ;
if ( V_351 . V_352 . V_346 == V_549 ||
V_351 . V_352 . V_346 == V_550 ||
V_351 . V_352 . V_346 == V_551 ) {
if ( V_280 != V_552 )
goto V_384;
if ( V_542 > V_546 )
goto V_384;
} else if ( V_351 . V_352 . V_346 == V_543 ) {
if ( V_280 != V_553 )
goto V_384;
if ( ( V_542 > V_546 ) &&
( V_542 != V_545 ) )
goto V_384;
} else
goto V_384;
if ( V_351 . V_352 . V_346 == V_549 ||
V_351 . V_352 . V_346 == V_550 ||
V_351 . V_352 . V_346 == V_551 ) {
switch ( V_542 ) {
case V_529 :
V_547 = V_27 -> V_199 . V_403 +
V_531 ;
break;
case V_532 :
V_547 = V_27 -> V_199 . V_403 +
V_533 ;
break;
case V_534 :
V_547 = V_27 -> V_199 . V_403 +
V_535 ;
break;
case V_536 :
V_547 = V_27 -> V_199 . V_403 +
V_537 ;
break;
case V_538 :
V_547 = V_27 -> V_199 . V_403 +
V_539 ;
break;
case V_540 :
V_547 = V_27 -> V_199 . V_403 +
V_541 ;
break;
default:
goto V_384;
}
if ( V_351 . V_352 . V_346 == V_549 )
V_520 = V_382 ;
if ( V_351 . V_352 . V_346 == V_550 ) {
V_520 = F_17 ( V_547 ) ;
V_520 |= V_382 ;
}
if ( V_351 . V_352 . V_346 == V_551 ) {
V_520 = F_17 ( V_547 ) ;
V_520 &= ~ V_382 ;
}
F_88 ( V_520 , V_547 ) ;
F_17 ( V_547 ) ;
}
return V_293 ;
V_384:
memset ( & V_351 , 0 , sizeof( V_351 ) ) ;
return - V_337 ;
}
static int
F_106 ( struct V_26 * V_27 , char * V_364 )
{
T_1 V_554 , V_555 , V_556 , V_557 ;
int V_7 = 0 ;
V_557 = V_351 . V_352 . V_348 [ V_558 ] ;
V_554 = V_351 . V_352 . V_348 [ V_559 ] ;
V_555 = V_351 . V_352 . V_348 [ V_560 ] ;
V_556 = V_351 . V_352 . V_348 [ V_561 ] ;
V_7 += snprintf ( V_364 + V_7 , V_562 - V_7 ,
L_205 , V_554 ) ;
V_7 += snprintf ( V_364 + V_7 , V_562 - V_7 ,
L_206 , V_555 ) ;
V_7 += snprintf ( V_364 + V_7 , V_562 - V_7 ,
L_207 , V_556 ) ;
V_7 += snprintf ( V_364 + V_7 , V_562 - V_7 ,
L_208 , V_557 ) ;
return V_7 ;
}
static T_3
F_107 ( struct V_276 * V_276 , char T_4 * V_3 , T_5 V_293 ,
T_6 * V_294 )
{
struct V_278 * V_279 = V_276 -> V_283 ;
struct V_26 * V_27 = (struct V_26 * ) V_279 -> V_277 ;
char * V_364 ;
int V_7 = 0 ;
V_279 -> V_349 = V_371 ;
if ( ! V_279 -> V_12 )
V_279 -> V_12 = F_2 ( V_562 , V_14 ) ;
if ( ! V_279 -> V_12 )
return 0 ;
V_364 = V_279 -> V_12 ;
if ( * V_294 )
return 0 ;
if ( ( V_351 . V_352 . V_346 != V_563 ) &&
( V_351 . V_352 . V_346 != V_564 ) )
return 0 ;
V_7 = F_106 ( V_27 , V_364 ) ;
return F_48 ( V_3 , V_293 , V_294 , V_364 , V_7 ) ;
}
static T_3
F_108 ( struct V_276 * V_276 , const char T_4 * V_3 ,
T_5 V_293 , T_6 * V_294 )
{
struct V_278 * V_279 = V_276 -> V_283 ;
T_1 V_554 , V_555 , V_556 , V_557 ;
int V_280 ;
V_279 -> V_349 = V_350 ;
V_280 = F_70 ( V_3 , V_293 , & V_351 . V_352 ) ;
if ( V_280 < 0 )
return V_280 ;
V_557 = V_351 . V_352 . V_348 [ V_558 ] ;
V_554 = V_351 . V_352 . V_348 [ V_559 ] ;
V_555 = V_351 . V_352 . V_348 [ V_560 ] ;
V_556 = V_351 . V_352 . V_348 [ V_561 ] ;
if ( V_351 . V_352 . V_346 == V_563 ) {
if ( ! ( V_554 & V_565 ) )
goto V_384;
if ( ( V_554 & ~ V_565 ) &&
( V_554 != V_566 ) )
goto V_384;
if ( V_556 > sizeof( V_91 ) )
goto V_384;
} else if ( V_351 . V_352 . V_346 == V_564 ) {
if ( ! ( V_554 & V_567 ) )
goto V_384;
if ( ( V_554 & ~ V_567 ) &&
( V_554 != V_566 ) )
goto V_384;
if ( V_556 > ( V_568 ) / 4 )
goto V_384;
if ( V_557 != 0x9b )
goto V_384;
} else
goto V_384;
if ( V_556 == 0 )
goto V_384;
if ( V_280 != V_569 )
goto V_384;
if ( V_557 & ~ 0xff )
goto V_384;
if ( V_555 == 0 )
goto V_570;
return V_293 ;
V_570:
memset ( & V_351 , 0 , sizeof( V_351 ) ) ;
return V_293 ;
V_384:
memset ( & V_351 , 0 , sizeof( V_351 ) ) ;
return - V_337 ;
}
static int
F_109 ( struct V_26 * V_27 , char * V_364 , int V_7 )
{
T_2 V_571 , V_572 ;
V_7 += snprintf ( V_364 + V_7 , V_573 - V_7 ,
L_209 ) ;
V_7 += snprintf ( V_364 + V_7 , V_573 - V_7 ,
L_210 ) ;
F_110 ( V_27 , V_574 ,
& V_571 , & V_572 ) ;
V_7 += snprintf ( V_364 + V_7 , V_573 - V_7 ,
L_211 , V_571 , V_572 ) ;
V_7 += snprintf ( V_364 + V_7 , V_573 - V_7 ,
L_212 ) ;
F_110 ( V_27 , V_575 ,
& V_571 , & V_572 ) ;
V_7 += snprintf ( V_364 + V_7 , V_573 - V_7 ,
L_211 , V_571 , V_572 ) ;
V_7 += snprintf ( V_364 + V_7 , V_573 - V_7 ,
L_213 ) ;
F_110 ( V_27 , V_576 ,
& V_571 , & V_572 ) ;
V_7 += snprintf ( V_364 + V_7 , V_573 - V_7 ,
L_211 , V_571 , V_572 ) ;
V_7 += snprintf ( V_364 + V_7 , V_573 - V_7 ,
L_214 ) ;
F_110 ( V_27 , V_577 ,
& V_571 , & V_572 ) ;
V_7 += snprintf ( V_364 + V_7 , V_573 - V_7 ,
L_211 , V_571 , V_572 ) ;
return V_7 ;
}
static int
F_111 ( struct V_26 * V_27 , char * V_364 , int V_7 )
{
T_2 V_571 , V_572 ;
int V_280 ;
V_7 += snprintf ( V_364 + V_7 , V_573 - V_7 ,
L_215 ) ;
V_7 += snprintf ( V_364 + V_7 , V_573 - V_7 ,
L_216 ) ;
V_280 = F_112 ( V_27 , V_574 ,
& V_571 , & V_572 ) ;
if ( ! V_280 )
V_7 += snprintf ( V_364 + V_7 , V_573 - V_7 ,
L_217 ,
V_27 -> V_578 , V_571 , V_572 ) ;
else
V_7 += snprintf ( V_364 + V_7 , V_573 - V_7 ,
L_218 ) ;
V_7 += snprintf ( V_364 + V_7 , V_573 - V_7 ,
L_219 ) ;
V_280 = F_112 ( V_27 , V_575 ,
& V_571 , & V_572 ) ;
if ( ! V_280 )
V_7 += snprintf ( V_364 + V_7 , V_573 - V_7 ,
L_217 ,
V_27 -> V_578 , V_571 , V_572 ) ;
else
V_7 += snprintf ( V_364 + V_7 , V_573 - V_7 ,
L_218 ) ;
V_7 += snprintf ( V_364 + V_7 , V_573 - V_7 ,
L_220 ) ;
V_280 = F_112 ( V_27 , V_576 ,
& V_571 , & V_572 ) ;
if ( ! V_280 )
V_7 += snprintf ( V_364 + V_7 , V_573 - V_7 ,
L_217 ,
V_27 -> V_578 , V_571 , V_572 ) ;
else
V_7 += snprintf ( V_364 + V_7 , V_573 - V_7 ,
L_218 ) ;
V_7 += snprintf ( V_364 + V_7 , V_573 - V_7 ,
L_221 ) ;
V_280 = F_112 ( V_27 , V_577 ,
& V_571 , & V_572 ) ;
if ( ! V_280 )
V_7 += snprintf ( V_364 + V_7 , V_573 - V_7 ,
L_217 ,
V_27 -> V_578 , V_571 , V_572 ) ;
else
V_7 += snprintf ( V_364 + V_7 , V_573 - V_7 ,
L_218 ) ;
return V_7 ;
}
static int
F_113 ( struct V_26 * V_27 , char * V_364 , int V_7 )
{
struct V_579 * V_580 ;
int V_6 ;
V_7 += snprintf ( V_364 + V_7 , V_573 - V_7 ,
L_222 ) ;
V_7 += snprintf ( V_364 + V_7 , V_573 - V_7 ,
L_223 ) ;
V_6 = 0 ;
F_10 (rsrc_blks, &phba->lpfc_vpi_blk_list, list) {
V_7 += snprintf ( V_364 + V_7 , V_573 - V_7 ,
L_224 ,
V_6 , V_580 -> V_581 ,
V_580 -> V_582 ) ;
V_6 ++ ;
}
V_7 += snprintf ( V_364 + V_7 , V_573 - V_7 ,
L_225 ) ;
V_6 = 0 ;
F_10 (rsrc_blks, &phba->sli4_hba.lpfc_vfi_blk_list,
list) {
V_7 += snprintf ( V_364 + V_7 , V_573 - V_7 ,
L_224 ,
V_6 , V_580 -> V_581 ,
V_580 -> V_582 ) ;
V_6 ++ ;
}
V_7 += snprintf ( V_364 + V_7 , V_573 - V_7 ,
L_226 ) ;
V_6 = 0 ;
F_10 (rsrc_blks, &phba->sli4_hba.lpfc_rpi_blk_list,
list) {
V_7 += snprintf ( V_364 + V_7 , V_573 - V_7 ,
L_224 ,
V_6 , V_580 -> V_581 ,
V_580 -> V_582 ) ;
V_6 ++ ;
}
V_7 += snprintf ( V_364 + V_7 , V_573 - V_7 ,
L_227 ) ;
V_6 = 0 ;
F_10 (rsrc_blks, &phba->sli4_hba.lpfc_xri_blk_list,
list) {
V_7 += snprintf ( V_364 + V_7 , V_573 - V_7 ,
L_224 ,
V_6 , V_580 -> V_581 ,
V_580 -> V_582 ) ;
V_6 ++ ;
}
return V_7 ;
}
static T_3
F_114 ( struct V_276 * V_276 , const char T_4 * V_3 ,
T_5 V_293 , T_6 * V_294 )
{
struct V_278 * V_279 = V_276 -> V_283 ;
T_1 V_583 ;
int V_280 ;
V_279 -> V_349 = V_350 ;
V_280 = F_70 ( V_3 , V_293 , & V_351 . V_352 ) ;
if ( V_280 < 0 )
return V_280 ;
V_583 = V_351 . V_352 . V_348 [ V_584 ] ;
if ( V_351 . V_352 . V_346 != V_585 )
goto V_384;
if ( V_280 != V_586 )
goto V_384;
if ( ! ( V_583 & V_587 ) )
goto V_384;
return V_293 ;
V_384:
memset ( & V_351 , 0 , sizeof( V_351 ) ) ;
return - V_337 ;
}
static T_3
F_115 ( struct V_276 * V_276 , char T_4 * V_3 , T_5 V_293 ,
T_6 * V_294 )
{
struct V_278 * V_279 = V_276 -> V_283 ;
struct V_26 * V_27 = (struct V_26 * ) V_279 -> V_277 ;
char * V_364 ;
T_1 V_583 ;
int V_7 = 0 ;
V_279 -> V_349 = V_371 ;
if ( ! V_279 -> V_12 )
V_279 -> V_12 = F_2 ( V_573 , V_14 ) ;
if ( ! V_279 -> V_12 )
return 0 ;
V_364 = V_279 -> V_12 ;
if ( * V_294 )
return 0 ;
if ( V_351 . V_352 . V_346 != V_585 )
return 0 ;
V_583 = V_351 . V_352 . V_348 [ V_584 ] ;
if ( V_583 & V_588 )
V_7 = F_109 ( V_27 , V_364 , V_7 ) ;
if ( V_583 & V_589 )
V_7 = F_111 ( V_27 , V_364 , V_7 ) ;
if ( V_583 & V_590 )
V_7 = F_113 ( V_27 , V_364 , V_7 ) ;
return F_48 ( V_3 , V_293 , V_294 , V_364 , V_7 ) ;
}
void
F_116 ( struct V_26 * V_27 , enum V_591 V_592 ,
enum V_593 V_594 , enum V_595 V_596 ,
enum V_597 V_598 ,
struct V_44 * V_599 , T_1 V_600 )
{
#ifdef F_31
T_1 * V_557 , * V_554 , * V_555 , * V_556 ;
char V_601 [ V_602 ] ;
int V_7 = 0 ;
T_1 V_603 = 0 ;
T_1 * V_604 ;
T_1 V_5 ;
if ( V_351 . V_352 . V_346 != V_564 )
return;
V_557 = & V_351 . V_352 . V_348 [ V_558 ] ;
V_554 = & V_351 . V_352 . V_348 [ V_559 ] ;
V_555 = & V_351 . V_352 . V_348 [ V_560 ] ;
V_556 = & V_351 . V_352 . V_348 [ V_561 ] ;
if ( ! ( * V_554 & V_566 ) ||
( * V_555 == 0 ) ||
( * V_556 == 0 ) )
return;
if ( * V_557 != 0x9B )
return;
if ( ( V_594 == V_605 ) && ( V_596 == V_606 ) ) {
if ( * V_554 & V_607 ) {
V_603 |= V_607 ;
F_42 ( L_228
L_229 ,
V_598 , V_592 , V_600 ) ;
}
}
if ( ( V_594 == V_605 ) && ( V_596 == V_608 ) ) {
if ( * V_554 & V_609 ) {
V_603 |= V_609 ;
F_42 ( L_230
L_231 ,
V_598 , V_592 , V_600 ) ;
}
}
if ( ( V_594 == V_610 ) && ( V_596 == V_606 ) ) {
if ( * V_554 & V_611 ) {
V_603 |= V_611 ;
F_42 ( L_232
L_229 ,
V_598 , V_592 , V_600 ) ;
}
}
if ( ( V_594 == V_610 ) && ( V_596 == V_608 ) ) {
if ( * V_554 & V_612 ) {
V_603 |= V_612 ;
F_42 ( L_233
L_231 ,
V_598 , V_592 , V_600 ) ;
}
}
if ( V_603 ) {
V_604 = ( T_1 * ) V_599 -> V_72 ;
for ( V_5 = 0 ; V_5 < * V_556 ; V_5 ++ ) {
if ( ! ( V_5 % 8 ) ) {
if ( V_5 != 0 )
F_42 ( L_130 , V_601 ) ;
V_7 = 0 ;
V_7 += snprintf ( V_601 + V_7 ,
V_602 - V_7 ,
L_234 , V_5 ) ;
}
V_7 += snprintf ( V_601 + V_7 , V_602 - V_7 ,
L_160 , ( T_1 ) * V_604 ) ;
V_604 ++ ;
}
if ( ( V_5 - 1 ) % 8 )
F_42 ( L_130 , V_601 ) ;
( * V_555 ) -- ;
}
if ( * V_555 == 0 )
memset ( & V_351 , 0 , sizeof( V_351 ) ) ;
return;
#endif
}
void
F_117 ( struct V_26 * V_27 , V_91 * V_613 )
{
#ifdef F_31
T_1 * V_554 , * V_555 , * V_556 , * V_557 ;
char V_601 [ V_602 ] ;
int V_7 = 0 ;
T_1 * V_604 ;
T_7 * V_614 ;
T_1 V_5 , V_31 ;
if ( V_351 . V_352 . V_346 != V_563 )
return;
V_557 = & V_351 . V_352 . V_348 [ V_558 ] ;
V_554 = & V_351 . V_352 . V_348 [ V_559 ] ;
V_555 = & V_351 . V_352 . V_348 [ V_560 ] ;
V_556 = & V_351 . V_352 . V_348 [ V_561 ] ;
if ( ! ( * V_554 & V_565 ) ||
( * V_555 == 0 ) ||
( * V_556 == 0 ) )
return;
if ( ( * V_557 != V_615 ) &&
( * V_557 != V_613 -> V_616 ) )
return;
if ( * V_554 & V_617 ) {
F_42 ( L_235 ,
V_613 -> V_616 ) ;
V_604 = ( T_1 * ) V_613 ;
for ( V_5 = 0 ; V_5 < * V_556 ; V_5 ++ ) {
if ( ! ( V_5 % 8 ) ) {
if ( V_5 != 0 )
F_42 ( L_130 , V_601 ) ;
V_7 = 0 ;
memset ( V_601 , 0 , V_602 ) ;
V_7 += snprintf ( V_601 + V_7 ,
V_602 - V_7 ,
L_234 , V_5 ) ;
}
V_7 += snprintf ( V_601 + V_7 , V_602 - V_7 ,
L_160 ,
( ( T_1 ) * V_604 ) & 0xffffffff ) ;
V_604 ++ ;
}
if ( ( V_5 - 1 ) % 8 )
F_42 ( L_130 , V_601 ) ;
F_42 ( L_44 ) ;
}
if ( * V_554 & V_618 ) {
F_42 ( L_236 ,
V_613 -> V_616 ) ;
V_614 = ( T_7 * ) V_613 ;
for ( V_5 = 0 ; V_5 < * V_556 ; V_5 ++ ) {
if ( ! ( V_5 % 8 ) ) {
if ( V_5 != 0 )
F_42 ( L_130 , V_601 ) ;
V_7 = 0 ;
memset ( V_601 , 0 , V_602 ) ;
V_7 += snprintf ( V_601 + V_7 ,
V_602 - V_7 ,
L_234 , V_5 ) ;
}
for ( V_31 = 0 ; V_31 < 4 ; V_31 ++ ) {
V_7 += snprintf ( V_601 + V_7 ,
V_602 - V_7 ,
L_237 ,
( ( T_7 ) * V_614 ) & 0xff ) ;
V_614 ++ ;
}
V_7 += snprintf ( V_601 + V_7 ,
V_602 - V_7 , L_238 ) ;
}
if ( ( V_5 - 1 ) % 8 )
F_42 ( L_130 , V_601 ) ;
F_42 ( L_44 ) ;
}
( * V_555 ) -- ;
if ( * V_555 == 0 )
memset ( & V_351 , 0 , sizeof( V_351 ) ) ;
return;
#endif
}
inline void
F_118 ( struct V_1 * V_2 )
{
#ifdef F_31
struct V_26 * V_27 = V_2 -> V_27 ;
char V_619 [ 64 ] ;
T_1 V_620 , V_5 ;
bool V_621 = false ;
if ( ! V_15 )
return;
if ( ! V_622 ) {
V_622 = F_119 ( L_239 , NULL ) ;
F_62 ( & V_623 , 0 ) ;
if ( ! V_622 ) {
F_120 ( V_2 , V_322 , V_323 ,
L_240 ) ;
goto V_624;
}
}
if ( ! V_21 )
V_21 = V_274 ;
snprintf ( V_619 , sizeof( V_619 ) , L_241 , V_27 -> V_578 ) ;
if ( ! V_27 -> V_625 ) {
V_621 = true ;
V_27 -> V_625 =
F_119 ( V_619 , V_622 ) ;
if ( ! V_27 -> V_625 ) {
F_120 ( V_2 , V_322 , V_323 ,
L_242 ) ;
goto V_624;
}
F_121 ( & V_623 ) ;
F_62 ( & V_27 -> V_626 , 0 ) ;
snprintf ( V_619 , sizeof( V_619 ) , L_243 ) ;
V_27 -> V_627 =
F_122 ( V_619 , V_628 | V_629 | V_630 ,
V_27 -> V_625 ,
V_27 , & V_631 ) ;
if ( ! V_27 -> V_627 ) {
F_120 ( V_2 , V_322 , V_323 ,
L_244 ) ;
goto V_624;
}
if ( V_27 -> V_48 < V_632 ) {
snprintf ( V_619 , sizeof( V_619 ) , L_245 ) ;
V_27 -> V_633 =
F_122 ( V_619 ,
V_628 | V_629 | V_630 ,
V_27 -> V_625 ,
V_27 , & V_634 ) ;
if ( ! V_27 -> V_633 ) {
F_120 ( V_2 , V_322 , V_323 ,
L_246
L_247 ) ;
goto V_624;
}
} else
V_27 -> V_633 = NULL ;
if ( V_27 -> V_48 < V_632 ) {
snprintf ( V_619 , sizeof( V_619 ) , L_248 ) ;
V_27 -> V_635 =
F_122 ( V_619 ,
V_628 | V_629 | V_630 ,
V_27 -> V_625 ,
V_27 , & V_636 ) ;
if ( ! V_27 -> V_635 ) {
F_120 ( V_2 , V_322 , V_323 ,
L_249
L_250 ) ;
goto V_624;
}
} else
V_27 -> V_635 = NULL ;
snprintf ( V_619 , sizeof( V_619 ) , L_251 ) ;
V_27 -> V_637 =
F_122 ( V_619 , V_628 | V_629 | V_630 ,
V_27 -> V_625 ,
V_27 , & V_638 ) ;
if ( ! V_27 -> V_637 ) {
F_120 ( V_2 , V_322 , V_323 ,
L_252 ) ;
goto V_624;
}
snprintf ( V_619 , sizeof( V_619 ) , L_253 ) ;
V_27 -> V_639 =
F_122 ( V_619 , V_628 | V_629 | V_630 ,
V_27 -> V_625 ,
V_27 , & V_640 ) ;
if ( ! V_27 -> V_639 ) {
F_120 ( V_2 , V_322 , V_323 ,
L_254 ) ;
goto V_624;
}
snprintf ( V_619 , sizeof( V_619 ) , L_255 ) ;
V_27 -> V_319 =
F_122 ( V_619 , V_628 | V_629 | V_630 ,
V_27 -> V_625 ,
V_27 , & V_641 ) ;
if ( ! V_27 -> V_319 ) {
F_120 ( V_2 , V_322 , V_323 ,
L_256 ) ;
goto V_624;
}
V_27 -> V_320 = V_642 ;
snprintf ( V_619 , sizeof( V_619 ) , L_257 ) ;
V_27 -> V_314 =
F_122 ( V_619 , V_628 | V_629 | V_630 ,
V_27 -> V_625 ,
V_27 , & V_641 ) ;
if ( ! V_27 -> V_314 ) {
F_120 ( V_2 , V_322 , V_323 ,
L_258 ) ;
goto V_624;
}
snprintf ( V_619 , sizeof( V_619 ) , L_259 ) ;
V_27 -> V_316 =
F_122 ( V_619 , V_628 | V_629 | V_630 ,
V_27 -> V_625 ,
V_27 , & V_641 ) ;
if ( ! V_27 -> V_316 ) {
F_120 ( V_2 , V_322 , V_323 ,
L_260 ) ;
goto V_624;
}
snprintf ( V_619 , sizeof( V_619 ) , L_261 ) ;
V_27 -> V_302 =
F_122 ( V_619 , V_628 | V_629 | V_630 ,
V_27 -> V_625 ,
V_27 , & V_641 ) ;
if ( ! V_27 -> V_302 ) {
F_120 ( V_2 , V_322 , V_323 ,
L_262 ) ;
goto V_624;
}
snprintf ( V_619 , sizeof( V_619 ) , L_263 ) ;
V_27 -> V_304 =
F_122 ( V_619 , V_628 | V_629 | V_630 ,
V_27 -> V_625 ,
V_27 , & V_641 ) ;
if ( ! V_27 -> V_304 ) {
F_120 ( V_2 , V_322 , V_323 ,
L_264 ) ;
goto V_624;
}
snprintf ( V_619 , sizeof( V_619 ) , L_265 ) ;
V_27 -> V_306 =
F_122 ( V_619 , V_628 | V_629 | V_630 ,
V_27 -> V_625 ,
V_27 , & V_641 ) ;
if ( ! V_27 -> V_306 ) {
F_120 ( V_2 , V_322 , V_323 ,
L_266 ) ;
goto V_624;
}
snprintf ( V_619 , sizeof( V_619 ) , L_267 ) ;
V_27 -> V_308 =
F_122 ( V_619 , V_628 | V_629 | V_630 ,
V_27 -> V_625 ,
V_27 , & V_641 ) ;
if ( ! V_27 -> V_308 ) {
F_120 ( V_2 , V_322 , V_323 ,
L_268 ) ;
goto V_624;
}
snprintf ( V_619 , sizeof( V_619 ) , L_269 ) ;
V_27 -> V_310 =
F_122 ( V_619 , V_628 | V_629 | V_630 ,
V_27 -> V_625 ,
V_27 , & V_641 ) ;
if ( ! V_27 -> V_310 ) {
F_120 ( V_2 , V_322 , V_323 ,
L_270 ) ;
goto V_624;
}
snprintf ( V_619 , sizeof( V_619 ) , L_271 ) ;
V_27 -> V_312 =
F_122 ( V_619 , V_628 | V_629 | V_630 ,
V_27 -> V_625 ,
V_27 , & V_641 ) ;
if ( ! V_27 -> V_312 ) {
F_120 ( V_2 , V_322 , V_323 ,
L_272 ) ;
goto V_624;
}
if ( V_29 ) {
V_620 = V_29 - 1 ;
if ( V_620 & V_29 ) {
V_620 = V_29 ;
V_5 = 0 ;
while ( V_620 > 1 ) {
V_620 = V_620 >> 1 ;
V_5 ++ ;
}
V_29 = ( 1 << V_5 ) ;
F_42 ( L_273
L_274 , V_17 ) ;
}
}
snprintf ( V_619 , sizeof( V_619 ) , L_275 ) ;
V_27 -> V_643 =
F_122 ( V_619 , V_628 | V_629 | V_630 ,
V_27 -> V_625 ,
V_27 , & V_644 ) ;
if ( ! V_27 -> V_643 ) {
F_120 ( V_2 , V_322 , V_323 ,
L_276
L_277 ) ;
goto V_624;
}
if ( ! V_27 -> V_30 ) {
V_27 -> V_30 = F_2 (
( sizeof( struct V_10 ) *
V_29 ) ,
V_14 ) ;
if ( ! V_27 -> V_30 ) {
F_120 ( V_2 , V_322 , V_323 ,
L_278
L_279 ) ;
goto V_624;
}
F_62 ( & V_27 -> V_28 , 0 ) ;
memset ( V_27 -> V_30 , 0 ,
( sizeof( struct V_10 ) *
V_29 ) ) ;
}
snprintf ( V_619 , sizeof( V_619 ) , L_280 ) ;
V_27 -> V_645 =
F_122 ( V_619 , 0644 ,
V_27 -> V_625 ,
V_27 , & V_646 ) ;
if ( ! V_27 -> V_645 ) {
F_120 ( V_2 , V_322 , V_323 ,
L_281 ) ;
goto V_624;
}
F_62 ( & V_27 -> V_252 , 0 ) ;
if ( V_647 ) {
V_620 = V_647 - 1 ;
if ( V_620 & V_17 ) {
V_620 = V_647 ;
V_5 = 0 ;
while ( V_620 > 1 ) {
V_620 = V_620 >> 1 ;
V_5 ++ ;
}
V_647 = ( 1 << V_5 ) ;
F_47 ( V_27 , V_322 , V_323 ,
L_282
L_283 ,
V_647 ) ;
}
V_27 -> V_253 = V_647 ;
V_27 -> V_255 = F_2 (
( sizeof( struct V_249 ) *
V_27 -> V_253 ) , V_14 ) ;
if ( ! V_27 -> V_255 ) {
F_47 ( V_27 , V_322 , V_323 ,
L_284
L_153 ) ;
goto V_648;
}
memset ( V_27 -> V_255 , 0 ,
( sizeof( struct V_249 ) *
V_27 -> V_253 ) ) ;
V_27 -> V_251 = 1 ;
V_27 -> V_254 = 0 ;
V_27 -> V_255 = NULL ;
} else {
V_648:
V_27 -> V_253 = 0 ;
V_27 -> V_251 = 0 ;
V_27 -> V_254 = 0 ;
V_27 -> V_255 = NULL ;
}
}
snprintf ( V_619 , sizeof( V_619 ) , L_285 , V_2 -> V_649 ) ;
if ( ! V_2 -> V_650 ) {
V_2 -> V_650 =
F_119 ( V_619 , V_27 -> V_625 ) ;
if ( ! V_2 -> V_650 ) {
F_120 ( V_2 , V_322 , V_323 ,
L_286 ) ;
goto V_624;
}
F_121 ( & V_27 -> V_626 ) ;
}
if ( V_17 ) {
V_620 = V_17 - 1 ;
if ( V_620 & V_17 ) {
V_620 = V_17 ;
V_5 = 0 ;
while ( V_620 > 1 ) {
V_620 = V_620 >> 1 ;
V_5 ++ ;
}
V_17 = ( 1 << V_5 ) ;
F_42 ( L_287 ,
V_17 ) ;
}
}
V_2 -> V_18 = F_123 (
( sizeof( struct V_10 ) * V_17 ) ,
V_14 ) ;
if ( ! V_2 -> V_18 ) {
F_120 ( V_2 , V_322 , V_323 ,
L_288
L_289 ) ;
goto V_624;
}
F_62 ( & V_2 -> V_16 , 0 ) ;
snprintf ( V_619 , sizeof( V_619 ) , L_290 ) ;
V_2 -> V_651 =
F_122 ( V_619 , V_628 | V_629 | V_630 ,
V_2 -> V_650 ,
V_2 , & V_652 ) ;
if ( ! V_2 -> V_651 ) {
F_120 ( V_2 , V_322 , V_323 ,
L_291
L_292 ) ;
goto V_624;
}
snprintf ( V_619 , sizeof( V_619 ) , L_293 ) ;
V_2 -> V_653 =
F_122 ( V_619 , V_628 | V_629 | V_630 ,
V_2 -> V_650 ,
V_2 , & V_654 ) ;
if ( ! V_2 -> V_653 ) {
F_120 ( V_2 , V_322 , V_323 ,
L_294 ) ;
goto V_624;
}
snprintf ( V_619 , sizeof( V_619 ) , L_295 ) ;
V_2 -> V_655 =
F_122 ( V_619 , 0644 ,
V_2 -> V_650 ,
V_2 , & V_656 ) ;
if ( ! V_2 -> V_655 ) {
F_120 ( V_2 , V_322 , V_323 ,
L_296 ) ;
goto V_624;
}
snprintf ( V_619 , sizeof( V_619 ) , L_297 ) ;
V_2 -> V_657 =
F_122 ( V_619 , 0644 ,
V_2 -> V_650 ,
V_2 , & V_658 ) ;
if ( ! V_2 -> V_657 ) {
F_120 ( V_2 , V_322 , V_323 ,
L_298 ) ;
goto V_624;
}
snprintf ( V_619 , sizeof( V_619 ) , L_299 ) ;
V_2 -> V_659 =
F_122 ( V_619 , 0644 ,
V_2 -> V_650 ,
V_2 , & V_660 ) ;
if ( ! V_2 -> V_659 ) {
F_120 ( V_2 , V_322 , V_323 ,
L_300 ) ;
goto V_624;
}
if ( ! V_621 )
goto V_624;
if ( V_27 -> V_48 < V_632 )
goto V_624;
snprintf ( V_619 , sizeof( V_619 ) , L_301 ) ;
if ( ! V_27 -> V_661 ) {
V_27 -> V_661 =
F_119 ( V_619 , V_27 -> V_625 ) ;
if ( ! V_27 -> V_661 ) {
F_120 ( V_2 , V_322 , V_323 ,
L_302 ) ;
goto V_624;
}
memset ( & V_351 , 0 , sizeof( V_351 ) ) ;
}
snprintf ( V_619 , sizeof( V_619 ) , L_303 ) ;
if ( ! V_27 -> V_662 ) {
V_27 -> V_662 =
F_122 ( V_619 , V_628 | V_629 | V_630 ,
V_27 -> V_661 , V_27 , & V_663 ) ;
if ( ! V_27 -> V_662 ) {
F_120 ( V_2 , V_322 , V_323 ,
L_304 ) ;
goto V_624;
}
V_351 . V_360 . V_381 = 0 ;
}
snprintf ( V_619 , sizeof( V_619 ) , L_305 ) ;
if ( ! V_27 -> V_664 ) {
V_27 -> V_664 =
F_122 ( V_619 , V_628 | V_629 | V_630 ,
V_27 -> V_661 , V_27 , & V_665 ) ;
if ( ! V_27 -> V_664 ) {
F_120 ( V_2 , V_322 , V_323 ,
L_306 ) ;
goto V_624;
}
V_351 . V_360 . V_381 = 0 ;
}
snprintf ( V_619 , sizeof( V_619 ) , L_307 ) ;
if ( ! V_27 -> V_666 ) {
V_27 -> V_666 =
F_122 ( V_619 , V_628 | V_629 ,
V_27 -> V_661 , V_27 , & V_667 ) ;
if ( ! V_27 -> V_666 ) {
F_120 ( V_2 , V_322 , V_323 ,
L_308 ) ;
goto V_624;
}
}
snprintf ( V_619 , sizeof( V_619 ) , L_309 ) ;
if ( ! V_27 -> V_668 ) {
V_27 -> V_668 =
F_122 ( V_619 , V_628 | V_629 | V_630 ,
V_27 -> V_661 , V_27 , & V_669 ) ;
if ( ! V_27 -> V_668 ) {
F_120 ( V_2 , V_322 , V_323 ,
L_310 ) ;
goto V_624;
}
}
snprintf ( V_619 , sizeof( V_619 ) , L_311 ) ;
if ( ! V_27 -> V_670 ) {
V_27 -> V_670 =
F_122 ( V_619 , V_628 | V_629 | V_630 ,
V_27 -> V_661 , V_27 , & V_671 ) ;
if ( ! V_27 -> V_670 ) {
F_120 ( V_2 , V_322 , V_323 ,
L_312 ) ;
goto V_624;
}
}
snprintf ( V_619 , sizeof( V_619 ) , L_313 ) ;
if ( ! V_27 -> V_672 ) {
V_27 -> V_672 =
F_122 ( V_619 , V_628 | V_629 | V_630 ,
V_27 -> V_661 , V_27 , & V_673 ) ;
if ( ! V_27 -> V_672 ) {
F_120 ( V_2 , V_322 , V_323 ,
L_314 ) ;
goto V_624;
}
}
snprintf ( V_619 , sizeof( V_619 ) , L_315 ) ;
if ( ! V_27 -> V_674 ) {
V_27 -> V_674 =
F_122 ( V_619 , V_628 | V_629 | V_630 ,
V_27 -> V_661 , V_27 , & V_675 ) ;
if ( ! V_27 -> V_674 ) {
F_120 ( V_2 , V_322 , V_323 ,
L_316 ) ;
goto V_624;
}
}
if ( V_27 -> V_199 . V_676 ) {
snprintf ( V_619 , sizeof( V_619 ) , L_317 ) ;
if ( ! V_27 -> V_677 ) {
V_27 -> V_677 =
F_122 ( V_619 ,
V_628 | V_629 | V_630 ,
V_27 -> V_661 , V_27 ,
& V_678 ) ;
if ( ! V_27 -> V_677 ) {
F_120 ( V_2 , V_322 , V_323 ,
L_318
L_319 ) ;
goto V_624;
}
}
}
V_624:
return;
#endif
}
inline void
F_124 ( struct V_1 * V_2 )
{
#ifdef F_31
struct V_26 * V_27 = V_2 -> V_27 ;
F_5 ( V_2 -> V_18 ) ;
V_2 -> V_18 = NULL ;
F_125 ( V_2 -> V_651 ) ;
V_2 -> V_651 = NULL ;
F_125 ( V_2 -> V_653 ) ;
V_2 -> V_653 = NULL ;
F_125 ( V_2 -> V_655 ) ;
V_2 -> V_655 = NULL ;
F_125 ( V_2 -> V_657 ) ;
V_2 -> V_657 = NULL ;
F_125 ( V_2 -> V_659 ) ;
V_2 -> V_659 = NULL ;
if ( V_2 -> V_650 ) {
F_125 ( V_2 -> V_650 ) ;
V_2 -> V_650 = NULL ;
F_126 ( & V_27 -> V_626 ) ;
}
if ( F_3 ( & V_27 -> V_626 ) == 0 ) {
F_125 ( V_27 -> V_627 ) ;
V_27 -> V_627 = NULL ;
F_125 ( V_27 -> V_633 ) ;
V_27 -> V_633 = NULL ;
F_125 ( V_27 -> V_635 ) ;
V_27 -> V_635 = NULL ;
F_125 ( V_27 -> V_637 ) ;
V_27 -> V_637 = NULL ;
F_125 ( V_27 -> V_639 ) ;
V_27 -> V_639 = NULL ;
F_125 ( V_27 -> V_319 ) ;
V_27 -> V_319 = NULL ;
F_125 ( V_27 -> V_314 ) ;
V_27 -> V_314 = NULL ;
F_125 ( V_27 -> V_316 ) ;
V_27 -> V_316 = NULL ;
F_125 ( V_27 -> V_302 ) ;
V_27 -> V_302 = NULL ;
F_125 ( V_27 -> V_304 ) ;
V_27 -> V_304 = NULL ;
F_125 ( V_27 -> V_306 ) ;
V_27 -> V_306 = NULL ;
F_125 ( V_27 -> V_308 ) ;
V_27 -> V_308 = NULL ;
F_125 ( V_27 -> V_310 ) ;
V_27 -> V_310 = NULL ;
F_125 ( V_27 -> V_312 ) ;
V_27 -> V_312 = NULL ;
F_5 ( V_27 -> V_30 ) ;
V_27 -> V_30 = NULL ;
F_125 ( V_27 -> V_643 ) ;
V_27 -> V_643 = NULL ;
F_125 ( V_27 -> V_645 ) ;
V_27 -> V_645 = NULL ;
F_5 ( V_27 -> V_255 ) ;
V_27 -> V_255 = NULL ;
if ( V_27 -> V_48 == V_632 ) {
F_125 ( V_27 -> V_677 ) ;
V_27 -> V_677 = NULL ;
F_125 ( V_27 -> V_674 ) ;
V_27 -> V_674 = NULL ;
F_125 ( V_27 -> V_672 ) ;
V_27 -> V_672 = NULL ;
F_125 ( V_27 -> V_670 ) ;
V_27 -> V_670 = NULL ;
F_125 ( V_27 -> V_668 ) ;
V_27 -> V_668 = NULL ;
F_125 ( V_27 -> V_666 ) ;
V_27 -> V_666 = NULL ;
F_125 ( V_27 -> V_664 ) ;
V_27 -> V_664 = NULL ;
F_125 ( V_27 -> V_662 ) ;
V_27 -> V_662 = NULL ;
F_125 ( V_27 -> V_661 ) ;
V_27 -> V_661 = NULL ;
}
if ( V_27 -> V_625 ) {
F_125 ( V_27 -> V_625 ) ;
V_27 -> V_625 = NULL ;
F_126 ( & V_623 ) ;
}
if ( F_3 ( & V_623 ) == 0 ) {
F_125 ( V_622 ) ;
V_622 = NULL ;
}
}
#endif
return;
}
void
F_127 ( struct V_26 * V_27 )
{
int V_679 ;
F_128 ( V_27 , V_680 , 0 ) ;
F_128 ( V_27 , V_681 , 0 ) ;
F_128 ( V_27 , V_682 , 0 ) ;
for ( V_679 = 0 ; V_679 < V_27 -> V_438 ; V_679 ++ )
F_128 ( V_27 , V_683 , V_679 ) ;
for ( V_679 = 0 ; V_679 < V_27 -> V_440 ; V_679 ++ )
F_128 ( V_27 , V_684 , V_679 ) ;
F_129 ( V_27 ) ;
F_130 ( V_27 ) ;
F_131 ( V_27 , V_680 , 0 ) ;
F_131 ( V_27 , V_681 , 0 ) ;
F_131 ( V_27 , V_682 , 0 ) ;
for ( V_679 = 0 ; V_679 < V_27 -> V_438 ; V_679 ++ )
F_131 ( V_27 , V_683 , V_679 ) ;
for ( V_679 = 0 ; V_679 < V_27 -> V_440 ; V_679 ++ )
F_131 ( V_27 , V_684 , V_679 ) ;
for ( V_679 = 0 ; V_679 < V_27 -> V_459 ; V_679 ++ )
F_132 ( V_27 , V_679 ) ;
}
