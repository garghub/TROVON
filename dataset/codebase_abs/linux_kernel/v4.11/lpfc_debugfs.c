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
int V_7 = 0 ;
if ( V_27 -> V_154 ) {
if ( ! V_27 -> V_155 )
return V_7 ;
V_122 = (struct V_121 * ) V_27 -> V_155 -> V_157 ;
V_7 += snprintf ( V_3 + V_7 , V_4 - V_7 ,
L_61 ) ;
V_7 += snprintf ( V_3 + V_7 , V_4 - V_7 ,
L_62 ,
F_3 ( & V_122 -> V_172 ) ,
F_3 ( & V_122 -> V_173 ) ,
F_3 ( & V_122 -> V_174 ) ) ;
if ( F_3 ( & V_122 -> V_172 ) !=
F_3 ( & V_122 -> V_175 ) ) {
V_7 += snprintf ( V_3 + V_7 , V_4 - V_7 ,
L_63 ,
F_3 ( & V_122 -> V_172 ) ,
F_3 ( & V_122 -> V_175 ) ) ;
}
V_7 += snprintf ( V_3 + V_7 , V_4 - V_7 ,
L_64 ,
F_3 ( & V_122 -> V_176 ) ,
F_3 ( & V_122 -> V_177 ) ,
F_3 ( & V_122 -> V_178 ) ,
F_3 ( & V_122 -> V_179 ) ) ;
V_7 += snprintf ( V_3 + V_7 , V_4 - V_7 ,
L_65 ,
F_3 ( & V_122 -> V_180 ) ,
F_3 ( & V_122 -> V_181 ) ) ;
if ( F_3 ( & V_122 -> V_180 ) !=
F_3 ( & V_122 -> V_182 ) ) {
V_7 += snprintf ( V_3 + V_7 , V_4 - V_7 ,
L_66 ,
F_3 ( & V_122 -> V_180 ) ,
F_3 ( & V_122 -> V_182 ) ) ;
}
V_7 += snprintf ( V_3 + V_7 , V_4 - V_7 ,
L_67 ,
F_3 ( & V_122 -> V_183 ) ,
F_3 ( & V_122 -> V_184 ) ,
F_3 ( & V_122 -> V_185 ) ,
F_3 ( & V_122 -> V_186 ) ) ;
V_7 += snprintf ( V_3 + V_7 , V_4 - V_7 ,
L_68 ,
F_3 ( & V_122 -> V_187 ) ,
F_3 ( & V_122 -> V_188 ) ) ;
V_7 += snprintf ( V_3 + V_7 , V_4 - V_7 ,
L_69 ,
F_3 ( & V_122 -> V_189 ) ,
F_3 ( & V_122 -> V_190 ) ,
F_3 ( & V_122 -> V_191 ) ) ;
V_7 += snprintf ( V_3 + V_7 , V_4 - V_7 ,
L_70 ,
F_3 ( & V_122 -> V_192 ) ,
F_3 ( & V_122 -> V_193 ) ,
F_3 ( & V_122 -> V_194 ) ) ;
V_7 += snprintf ( V_3 + V_7 , V_4 - V_7 , L_44 ) ;
} else {
if ( ! ( V_27 -> V_195 & V_196 ) )
return V_7 ;
V_7 += snprintf ( V_3 + V_7 , V_4 - V_7 ,
L_71 ) ;
V_7 += snprintf ( V_3 + V_7 , V_4 - V_7 ,
L_72 ,
V_27 -> V_197 ,
V_27 -> V_198 ) ;
V_7 += snprintf ( V_3 + V_7 , V_4 - V_7 ,
L_73 ,
V_27 -> V_199 ,
V_27 -> V_200 ,
V_27 -> V_201 ) ;
V_7 += snprintf ( V_3 + V_7 , V_4 - V_7 ,
L_74 , V_27 -> V_202 ) ;
}
return V_7 ;
}
static int
F_23 ( struct V_1 * V_2 , char * V_3 , int V_4 )
{
struct V_26 * V_27 = V_2 -> V_27 ;
int V_7 = 0 ;
if ( V_27 -> V_154 == 0 ) {
V_7 += snprintf ( V_3 + V_7 , V_203 - V_7 ,
L_75 ,
( V_27 -> V_204 ? L_76 : L_77 ) ,
V_27 -> V_205 ) ;
if ( V_27 -> V_205 == 0 )
return V_7 ;
V_7 += snprintf (
V_3 + V_7 , V_203 - V_7 ,
L_78
L_79 ) ;
V_7 += snprintf (
V_3 + V_7 , V_203 - V_7 ,
L_80 ,
F_24 ( V_27 -> V_206 ,
V_27 -> V_205 ) ,
V_27 -> V_207 ,
V_27 -> V_208 ) ;
V_7 += snprintf (
V_3 + V_7 , V_203 - V_7 ,
L_81
L_82 ) ;
V_7 += snprintf (
V_3 + V_7 , V_203 - V_7 ,
L_80 ,
F_24 ( V_27 -> V_209 ,
V_27 -> V_205 ) ,
V_27 -> V_210 ,
V_27 -> V_211 ) ;
V_7 += snprintf (
V_3 + V_7 , V_203 - V_7 ,
L_83
L_84 ) ;
V_7 += snprintf (
V_3 + V_7 , V_203 - V_7 ,
L_80 ,
F_24 ( V_27 -> V_212 ,
V_27 -> V_205 ) ,
V_27 -> V_213 ,
V_27 -> V_214 ) ;
V_7 += snprintf (
V_3 + V_7 , V_203 - V_7 ,
L_85
L_86 ) ;
V_7 += snprintf (
V_3 + V_7 , V_203 - V_7 ,
L_80 ,
F_24 ( V_27 -> V_215 ,
V_27 -> V_205 ) ,
V_27 -> V_216 ,
V_27 -> V_217 ) ;
V_7 += snprintf (
V_3 + V_7 , V_203 - V_7 ,
L_87 ,
F_24 ( V_27 -> V_206 +
V_27 -> V_209 +
V_27 -> V_212 +
V_27 -> V_215 ,
V_27 -> V_205 ) ) ;
return V_7 ;
}
V_7 += snprintf ( V_3 + V_7 , V_203 - V_7 ,
L_88 ,
( V_27 -> V_204 ? L_76 : L_77 ) ,
V_27 -> V_205 ,
V_27 -> V_218 ) ;
if ( V_27 -> V_205 == 0 )
return V_7 ;
V_7 += snprintf ( V_3 + V_7 , V_203 - V_7 ,
L_89
L_90 ) ;
V_7 += snprintf ( V_3 + V_7 , V_203 - V_7 ,
L_80 ,
F_24 ( V_27 -> V_206 ,
V_27 -> V_205 ) ,
V_27 -> V_207 ,
V_27 -> V_208 ) ;
V_7 += snprintf ( V_3 + V_7 , V_203 - V_7 ,
L_91
L_92 ) ;
V_7 += snprintf ( V_3 + V_7 , V_203 - V_7 ,
L_80 ,
F_24 ( V_27 -> V_209 ,
V_27 -> V_205 ) ,
V_27 -> V_210 ,
V_27 -> V_211 ) ;
V_7 += snprintf ( V_3 + V_7 , V_203 - V_7 ,
L_93
L_94 ) ;
V_7 += snprintf ( V_3 + V_7 , V_203 - V_7 ,
L_80 ,
F_24 ( V_27 -> V_212 ,
V_27 -> V_205 ) ,
V_27 -> V_213 ,
V_27 -> V_214 ) ;
V_7 += snprintf ( V_3 + V_7 , V_203 - V_7 ,
L_95
L_96 ) ;
V_7 += snprintf ( V_3 + V_7 , V_203 - V_7 ,
L_80 ,
F_24 ( V_27 -> V_215 ,
V_27 -> V_205 ) ,
V_27 -> V_216 ,
V_27 -> V_217 ) ;
V_7 += snprintf ( V_3 + V_7 , V_203 - V_7 ,
L_97
L_98 ) ;
V_7 += snprintf ( V_3 + V_7 , V_203 - V_7 ,
L_80 ,
F_24 ( V_27 -> V_219 ,
V_27 -> V_205 ) ,
V_27 -> V_220 ,
V_27 -> V_221 ) ;
if ( V_27 -> V_218 == 0 ) {
V_7 += snprintf ( V_3 + V_7 , V_203 - V_7 ,
L_99
L_100 ) ;
V_7 += snprintf ( V_3 + V_7 , V_203 - V_7 ,
L_101
L_102 ,
F_24 ( V_27 -> V_222 ,
V_27 -> V_205 ) ,
V_27 -> V_223 ,
V_27 -> V_224 ) ;
return V_7 ;
}
V_7 += snprintf ( V_3 + V_7 , V_203 - V_7 ,
L_103
L_104 ) ;
V_7 += snprintf ( V_3 + V_7 , V_203 - V_7 ,
L_80 ,
F_24 ( V_27 -> V_225 ,
V_27 -> V_218 ) ,
V_27 -> V_226 ,
V_27 -> V_227 ) ;
V_7 += snprintf ( V_3 + V_7 , V_203 - V_7 ,
L_105
L_106 ) ;
V_7 += snprintf ( V_3 + V_7 , V_203 - V_7 ,
L_80 ,
F_24 ( V_27 -> V_228 ,
V_27 -> V_218 ) ,
V_27 -> V_229 ,
V_27 -> V_230 ) ;
V_7 += snprintf ( V_3 + V_7 , V_203 - V_7 ,
L_107
L_108 ) ;
V_7 += snprintf ( V_3 + V_7 , V_203 - V_7 ,
L_80 ,
F_24 ( V_27 -> V_231 ,
V_27 -> V_218 ) ,
V_27 -> V_232 ,
V_27 -> V_233 ) ;
V_7 += snprintf ( V_3 + V_7 , V_203 - V_7 ,
L_109
L_110 ) ;
V_7 += snprintf ( V_3 + V_7 , V_203 - V_7 ,
L_80 ,
F_24 ( V_27 -> V_234 ,
V_27 -> V_218 ) ,
V_27 -> V_235 ,
V_27 -> V_236 ) ;
V_7 += snprintf ( V_3 + V_7 , V_203 - V_7 ,
L_111
L_112 ) ;
V_7 += snprintf ( V_3 + V_7 , V_203 - V_7 ,
L_80 ,
F_24 ( V_27 -> V_222 ,
V_27 -> V_218 ) ,
V_27 -> V_223 ,
V_27 -> V_224 ) ;
return V_7 ;
}
static int
F_25 ( struct V_26 * V_27 , char * V_3 , int V_4 )
{
struct V_237 * V_11 ;
int V_5 , V_238 , V_6 , V_239 ;
int V_7 = 0 ;
V_238 = V_27 -> V_240 ;
V_6 = ( F_3 ( & V_27 -> V_241 ) + 1 ) &
( V_27 -> V_242 - 1 ) ;
V_239 = V_27 -> V_243 ;
V_7 += snprintf ( V_3 + V_7 , V_4 - V_7 ,
L_113 ,
( V_27 -> V_154 ? L_114 : L_115 ) ,
( V_238 ? L_76 : L_77 ) ,
V_6 , V_239 , V_27 -> V_242 ) ;
if ( ! V_27 -> V_244 || V_238 )
return V_7 ;
for ( V_5 = V_6 ; V_5 < V_27 -> V_242 ; V_5 ++ ) {
if ( V_239 ) {
V_239 -- ;
continue;
}
V_11 = V_27 -> V_244 + V_5 ;
V_27 -> V_243 ++ ;
if ( ! V_11 -> V_19 )
continue;
V_7 += snprintf ( V_3 + V_7 , V_4 - V_7 , V_11 -> V_19 ,
V_11 -> V_23 , V_11 -> V_24 , V_11 -> V_25 ) ;
if ( V_27 -> V_243 >= V_27 -> V_242 ) {
V_27 -> V_243 = 0 ;
V_7 += snprintf ( V_3 + V_7 , V_4 - V_7 ,
L_116 ) ;
goto V_245;
}
if ( V_7 >= ( V_4 - V_246 ) ) {
V_7 += snprintf ( V_3 + V_7 , V_4 - V_7 ,
L_117 ,
V_27 -> V_243 ,
V_27 -> V_242 ) ;
goto V_245;
}
}
for ( V_5 = 0 ; V_5 < V_6 ; V_5 ++ ) {
if ( V_239 ) {
V_239 -- ;
continue;
}
V_11 = V_27 -> V_244 + V_5 ;
V_27 -> V_243 ++ ;
if ( ! V_11 -> V_19 )
continue;
V_7 += snprintf ( V_3 + V_7 , V_4 - V_7 , V_11 -> V_19 ,
V_11 -> V_23 , V_11 -> V_24 , V_11 -> V_25 ) ;
if ( V_27 -> V_243 >= V_27 -> V_242 ) {
V_27 -> V_243 = 0 ;
V_7 += snprintf ( V_3 + V_7 , V_4 - V_7 ,
L_116 ) ;
goto V_245;
}
if ( V_7 >= ( V_4 - V_246 ) ) {
V_7 += snprintf ( V_3 + V_7 , V_4 - V_7 ,
L_117 ,
V_27 -> V_243 ,
V_27 -> V_242 ) ;
goto V_245;
}
}
V_7 += snprintf ( V_3 + V_7 , V_4 - V_7 ,
L_118 ) ;
V_245:
return V_7 ;
}
static int
F_26 ( struct V_1 * V_2 , char * V_3 , int V_4 )
{
struct V_26 * V_27 = V_2 -> V_27 ;
int V_5 ;
int V_7 = 0 ;
T_1 V_247 = 0 ;
T_1 V_248 = 0 ;
T_1 V_249 = 0 ;
T_1 V_250 = 0 ;
if ( V_27 -> V_154 == 0 ) {
V_7 += snprintf ( V_3 + V_7 , V_203 - V_7 ,
L_119 ,
( V_27 -> V_251 & V_252 ?
L_76 : L_77 ) ) ;
for ( V_5 = 0 ; V_5 < V_27 -> V_253 . V_254 ; V_5 ++ ) {
if ( V_5 >= V_255 )
break;
V_7 += snprintf ( V_3 + V_7 , V_203 - V_7 ,
L_120 ,
V_5 , V_27 -> V_256 [ V_5 ] ,
V_27 -> V_257 [ V_5 ] ) ;
V_247 += V_27 -> V_256 [ V_5 ] ;
V_249 += V_27 -> V_257 [ V_5 ] ;
}
V_7 += snprintf ( V_3 + V_7 , V_203 - V_7 ,
L_121 ,
V_247 , V_249 ) ;
return V_7 ;
}
V_7 += snprintf ( V_3 + V_7 , V_203 - V_7 ,
L_122 ,
( V_27 -> V_251 & V_258 ?
L_123 : L_124 ) ) ;
V_7 += snprintf ( V_3 + V_7 , V_203 - V_7 ,
L_125 ,
( V_27 -> V_251 & V_259 ?
L_126 : L_127 ) ) ;
for ( V_5 = 0 ; V_5 < V_27 -> V_253 . V_254 ; V_5 ++ ) {
if ( V_5 >= V_255 )
break;
V_7 += snprintf ( V_3 + V_7 , V_203 - V_7 ,
L_128
L_129 ,
V_5 , V_27 -> V_256 [ V_5 ] ,
V_27 -> V_260 [ V_5 ] ,
V_27 -> V_257 [ V_5 ] ,
V_27 -> V_261 [ V_5 ] ) ;
V_247 += V_27 -> V_256 [ V_5 ] ;
V_248 += V_27 -> V_261 [ V_5 ] ;
V_249 += V_27 -> V_257 [ V_5 ] ;
V_250 += V_27 -> V_260 [ V_5 ] ;
}
V_7 += snprintf ( V_3 + V_7 , V_203 - V_7 ,
L_130 ,
V_247 , V_250 , V_249 , V_248 ) ;
return V_7 ;
}
inline void
F_27 ( struct V_1 * V_2 , int V_262 , char * V_19 ,
T_1 V_23 , T_1 V_24 , T_1 V_25 )
{
#ifdef F_28
struct V_10 * V_11 ;
int V_6 ;
if ( ! ( V_263 & V_262 ) )
return;
if ( ! V_15 || ! V_17 ||
! V_2 || ! V_2 -> V_18 )
return;
V_6 = F_29 ( & V_2 -> V_16 ) &
( V_17 - 1 ) ;
V_11 = V_2 -> V_18 + V_6 ;
V_11 -> V_19 = V_19 ;
V_11 -> V_23 = V_23 ;
V_11 -> V_24 = V_24 ;
V_11 -> V_25 = V_25 ;
V_11 -> V_22 = F_29 ( & V_264 ) ;
V_11 -> V_20 = V_265 ;
#endif
return;
}
inline void
F_30 ( struct V_26 * V_27 , char * V_19 ,
T_1 V_23 , T_1 V_24 , T_1 V_25 )
{
#ifdef F_28
struct V_10 * V_11 ;
int V_6 ;
if ( ! V_15 || ! V_29 ||
! V_27 || ! V_27 -> V_30 )
return;
V_6 = F_29 ( & V_27 -> V_28 ) &
( V_29 - 1 ) ;
V_11 = V_27 -> V_30 + V_6 ;
V_11 -> V_19 = V_19 ;
V_11 -> V_23 = V_23 ;
V_11 -> V_24 = V_24 ;
V_11 -> V_25 = V_25 ;
V_11 -> V_22 = F_29 ( & V_264 ) ;
V_11 -> V_20 = V_265 ;
#endif
return;
}
inline void
F_31 ( struct V_26 * V_27 , char * V_19 ,
T_2 V_23 , T_2 V_24 , T_1 V_25 )
{
#ifdef F_28
struct V_237 * V_11 ;
int V_6 ;
if ( ! V_27 -> V_240 || ! V_27 -> V_244 )
return;
V_6 = F_29 ( & V_27 -> V_241 ) &
( V_27 -> V_242 - 1 ) ;
V_11 = V_27 -> V_244 + V_6 ;
V_11 -> V_19 = V_19 ;
V_11 -> V_23 = V_23 ;
V_11 -> V_24 = V_24 ;
V_11 -> V_25 = V_25 ;
#endif
}
static int
F_32 ( struct V_266 * V_266 , struct V_267 * V_267 )
{
struct V_1 * V_2 = V_266 -> V_268 ;
struct V_269 * V_270 ;
int V_4 ;
int V_271 = - V_272 ;
if ( ! V_17 ) {
V_271 = - V_273 ;
goto V_245;
}
V_270 = F_2 ( sizeof( * V_270 ) , V_14 ) ;
if ( ! V_270 )
goto V_245;
V_4 = ( V_17 * V_13 ) ;
V_4 = F_33 ( V_4 ) ;
V_270 -> V_12 = F_2 ( V_4 , V_14 ) ;
if ( ! V_270 -> V_12 ) {
F_5 ( V_270 ) ;
goto V_245;
}
V_270 -> V_7 = F_1 ( V_2 , V_270 -> V_12 , V_4 ) ;
V_267 -> V_274 = V_270 ;
V_271 = 0 ;
V_245:
return V_271 ;
}
static int
F_34 ( struct V_266 * V_266 , struct V_267 * V_267 )
{
struct V_26 * V_27 = V_266 -> V_268 ;
struct V_269 * V_270 ;
int V_4 ;
int V_271 = - V_272 ;
if ( ! V_29 ) {
V_271 = - V_273 ;
goto V_245;
}
V_270 = F_2 ( sizeof( * V_270 ) , V_14 ) ;
if ( ! V_270 )
goto V_245;
V_4 = ( V_29 * V_13 ) ;
V_4 = F_33 ( V_4 ) ;
V_270 -> V_12 = F_2 ( V_4 , V_14 ) ;
if ( ! V_270 -> V_12 ) {
F_5 ( V_270 ) ;
goto V_245;
}
V_270 -> V_7 = F_6 ( V_27 , V_270 -> V_12 , V_4 ) ;
V_267 -> V_274 = V_270 ;
V_271 = 0 ;
V_245:
return V_271 ;
}
static int
F_35 ( struct V_266 * V_266 , struct V_267 * V_267 )
{
struct V_26 * V_27 = V_266 -> V_268 ;
struct V_269 * V_270 ;
int V_271 = - V_272 ;
V_270 = F_2 ( sizeof( * V_270 ) , V_14 ) ;
if ( ! V_270 )
goto V_245;
V_270 -> V_12 = F_2 ( V_74 , V_14 ) ;
if ( ! V_270 -> V_12 ) {
F_5 ( V_270 ) ;
goto V_245;
}
V_270 -> V_7 = F_7 ( V_27 , V_270 -> V_12 ,
V_74 ) ;
V_267 -> V_274 = V_270 ;
V_271 = 0 ;
V_245:
return V_271 ;
}
static int
F_36 ( struct V_266 * V_266 , struct V_267 * V_267 )
{
struct V_26 * V_27 = V_266 -> V_268 ;
struct V_269 * V_270 ;
int V_271 = - V_272 ;
V_270 = F_2 ( sizeof( * V_270 ) , V_14 ) ;
if ( ! V_270 )
goto V_245;
V_270 -> V_12 = F_2 ( V_275 , V_14 ) ;
if ( ! V_270 -> V_12 ) {
F_5 ( V_270 ) ;
goto V_245;
}
V_270 -> V_7 = F_14 ( V_27 , V_270 -> V_12 ,
V_275 ) ;
V_267 -> V_274 = V_270 ;
V_271 = 0 ;
V_245:
return V_271 ;
}
static int
F_37 ( struct V_266 * V_266 , struct V_267 * V_267 )
{
struct V_26 * V_27 = V_266 -> V_268 ;
struct V_269 * V_270 ;
int V_271 = - V_272 ;
V_270 = F_2 ( sizeof( * V_270 ) , V_14 ) ;
if ( ! V_270 )
goto V_245;
V_270 -> V_12 = F_2 ( V_276 , V_14 ) ;
if ( ! V_270 -> V_12 ) {
F_5 ( V_270 ) ;
goto V_245;
}
V_270 -> V_7 = F_16 ( V_27 , V_270 -> V_12 ,
V_276 ) ;
V_267 -> V_274 = V_270 ;
V_271 = 0 ;
V_245:
return V_271 ;
}
static int
F_38 ( struct V_266 * V_266 , struct V_267 * V_267 )
{
struct V_269 * V_270 ;
int V_271 = - V_272 ;
if ( ! V_277 )
return - V_278 ;
V_270 = F_2 ( sizeof( * V_270 ) , V_14 ) ;
if ( ! V_270 )
goto V_245;
F_39 ( L_131 ,
V_279 , V_277 ) ;
V_270 -> V_12 = V_277 ;
if ( ! V_270 -> V_12 ) {
F_5 ( V_270 ) ;
goto V_245;
}
V_270 -> V_7 = ( 1 << V_280 ) << V_281 ;
V_267 -> V_274 = V_270 ;
V_271 = 0 ;
V_245:
return V_271 ;
}
static int
F_40 ( struct V_266 * V_266 , struct V_267 * V_267 )
{
struct V_269 * V_270 ;
int V_271 = - V_272 ;
if ( ! V_282 )
return - V_278 ;
V_270 = F_2 ( sizeof( * V_270 ) , V_14 ) ;
if ( ! V_270 )
goto V_245;
F_39 ( L_132 ,
V_279 , V_282 , V_267 ) ;
V_270 -> V_12 = V_282 ;
if ( ! V_270 -> V_12 ) {
F_5 ( V_270 ) ;
goto V_245;
}
V_270 -> V_7 = ( 1 << V_283 ) << V_281 ;
V_267 -> V_274 = V_270 ;
V_271 = 0 ;
V_245:
return V_271 ;
}
static T_3
F_41 ( struct V_267 * V_267 , const char T_4 * V_3 ,
T_5 V_284 , T_6 * V_285 )
{
F_42 ( & V_286 ) ;
memset ( ( void * ) V_277 , 0 ,
( ( 1 << V_281 ) << V_280 ) ) ;
memset ( ( void * ) V_282 , 0 ,
( ( 1 << V_281 ) << V_283 ) ) ;
V_287 = 0 ;
F_43 ( & V_286 ) ;
return V_284 ;
}
static T_3
F_44 ( struct V_267 * V_267 , char T_4 * V_3 ,
T_5 V_284 , T_6 * V_285 )
{
struct V_288 * V_289 = V_267 -> V_290 . V_288 ;
struct V_26 * V_27 = V_267 -> V_274 ;
char V_291 [ 32 ] ;
V_71 V_292 = 0 ;
int V_109 = 0 ;
if ( V_289 == V_27 -> V_293 )
V_109 = snprintf ( V_291 , 32 , L_133 , V_27 -> V_294 ) ;
else if ( V_289 == V_27 -> V_295 )
V_109 = snprintf ( V_291 , 32 , L_133 , V_27 -> V_296 ) ;
else if ( V_289 == V_27 -> V_297 )
V_109 = snprintf ( V_291 , 32 , L_133 , V_27 -> V_298 ) ;
else if ( V_289 == V_27 -> V_299 )
V_109 = snprintf ( V_291 , 32 , L_133 , V_27 -> V_300 ) ;
else if ( V_289 == V_27 -> V_301 )
V_109 = snprintf ( V_291 , 32 , L_133 , V_27 -> V_302 ) ;
else if ( V_289 == V_27 -> V_303 )
V_109 = snprintf ( V_291 , 32 , L_133 , V_27 -> V_304 ) ;
else if ( V_289 == V_27 -> V_305 )
V_109 = snprintf ( V_291 , 32 , L_134 , V_27 -> V_306 ) ;
else if ( V_289 == V_27 -> V_307 ) {
memcpy ( & V_292 , & V_27 -> V_308 , sizeof( struct V_309 ) ) ;
V_292 = F_45 ( V_292 ) ;
V_109 = snprintf ( V_291 , 32 , L_135 , V_292 ) ;
} else if ( V_289 == V_27 -> V_310 ) {
if ( V_27 -> V_311 == ( V_312 ) ( - 1 ) )
V_109 = snprintf ( V_291 , 32 , L_136 ) ;
else
V_109 = snprintf ( V_291 , 32 , L_137 ,
( V_71 ) V_27 -> V_311 ) ;
} else
F_46 ( V_27 , V_313 , V_314 ,
L_138 ) ;
return F_47 ( V_3 , V_284 , V_285 , & V_291 , V_109 ) ;
}
static T_3
F_48 ( struct V_267 * V_267 , const char T_4 * V_3 ,
T_5 V_284 , T_6 * V_285 )
{
struct V_288 * V_289 = V_267 -> V_290 . V_288 ;
struct V_26 * V_27 = V_267 -> V_274 ;
char V_315 [ 33 ] ;
V_71 V_292 = 0 ;
int V_4 ;
memset ( V_315 , 0 , 33 ) ;
V_4 = ( V_284 < 32 ) ? V_284 : 32 ;
if ( F_49 ( V_315 , V_3 , V_4 ) )
return 0 ;
if ( V_289 == V_27 -> V_310 ) {
if ( ( V_3 [ 0 ] == 'o' ) && ( V_3 [ 1 ] == 'f' ) && ( V_3 [ 2 ] == 'f' ) )
V_292 = ( V_71 ) ( - 1 ) ;
}
if ( ( V_292 == 0 ) && ( F_50 ( V_315 , 0 , & V_292 ) ) )
return 0 ;
if ( V_289 == V_27 -> V_293 )
V_27 -> V_294 = ( T_1 ) V_292 ;
else if ( V_289 == V_27 -> V_295 )
V_27 -> V_296 = ( T_1 ) V_292 ;
else if ( V_289 == V_27 -> V_297 )
V_27 -> V_298 = ( T_1 ) V_292 ;
else if ( V_289 == V_27 -> V_299 )
V_27 -> V_300 = ( T_1 ) V_292 ;
else if ( V_289 == V_27 -> V_301 )
V_27 -> V_302 = ( T_1 ) V_292 ;
else if ( V_289 == V_27 -> V_303 )
V_27 -> V_304 = ( T_1 ) V_292 ;
else if ( V_289 == V_27 -> V_310 )
V_27 -> V_311 = ( V_312 ) V_292 ;
else if ( V_289 == V_27 -> V_305 )
V_27 -> V_306 = ( T_1 ) ( V_292 & V_316 ) ;
else if ( V_289 == V_27 -> V_307 ) {
V_292 = F_45 ( V_292 ) ;
memcpy ( & V_27 -> V_308 , & V_292 , sizeof( struct V_309 ) ) ;
} else
F_46 ( V_27 , V_313 , V_314 ,
L_139 ) ;
return V_284 ;
}
static int
F_51 ( struct V_266 * V_266 , struct V_267 * V_267 )
{
return 0 ;
}
static int
F_52 ( struct V_266 * V_266 , struct V_267 * V_267 )
{
struct V_1 * V_2 = V_266 -> V_268 ;
struct V_269 * V_270 ;
int V_271 = - V_272 ;
V_270 = F_2 ( sizeof( * V_270 ) , V_14 ) ;
if ( ! V_270 )
goto V_245;
V_270 -> V_12 = F_2 ( V_125 , V_14 ) ;
if ( ! V_270 -> V_12 ) {
F_5 ( V_270 ) ;
goto V_245;
}
V_270 -> V_7 = F_18 ( V_2 , V_270 -> V_12 ,
V_125 ) ;
V_267 -> V_274 = V_270 ;
V_271 = 0 ;
V_245:
return V_271 ;
}
static T_6
F_53 ( struct V_267 * V_267 , T_6 V_75 , int V_317 )
{
struct V_269 * V_270 = V_267 -> V_274 ;
return F_54 ( V_267 , V_75 , V_317 , V_270 -> V_7 ) ;
}
static T_3
F_55 ( struct V_267 * V_267 , char T_4 * V_3 ,
T_5 V_284 , T_6 * V_285 )
{
struct V_269 * V_270 = V_267 -> V_274 ;
return F_47 ( V_3 , V_284 , V_285 , V_270 -> V_12 ,
V_270 -> V_7 ) ;
}
static int
F_56 ( struct V_266 * V_266 , struct V_267 * V_267 )
{
struct V_269 * V_270 = V_267 -> V_274 ;
F_5 ( V_270 -> V_12 ) ;
F_5 ( V_270 ) ;
return 0 ;
}
static int
F_57 ( struct V_266 * V_266 , struct V_267 * V_267 )
{
struct V_269 * V_270 = V_267 -> V_274 ;
V_270 -> V_12 = NULL ;
F_5 ( V_270 ) ;
return 0 ;
}
static int
F_58 ( struct V_266 * V_266 , struct V_267 * V_267 )
{
struct V_1 * V_2 = V_266 -> V_268 ;
struct V_269 * V_270 ;
int V_271 = - V_272 ;
V_270 = F_2 ( sizeof( * V_270 ) , V_14 ) ;
if ( ! V_270 )
goto V_245;
V_270 -> V_12 = F_2 ( V_318 , V_14 ) ;
if ( ! V_270 -> V_12 ) {
F_5 ( V_270 ) ;
goto V_245;
}
V_270 -> V_7 = F_22 ( V_2 , V_270 -> V_12 ,
V_318 ) ;
V_270 -> V_268 = V_266 -> V_268 ;
V_267 -> V_274 = V_270 ;
V_271 = 0 ;
V_245:
return V_271 ;
}
static T_3
F_59 ( struct V_267 * V_267 , const char T_4 * V_3 ,
T_5 V_284 , T_6 * V_285 )
{
struct V_269 * V_270 = V_267 -> V_274 ;
struct V_1 * V_2 = (struct V_1 * ) V_270 -> V_268 ;
struct V_26 * V_27 = V_2 -> V_27 ;
struct V_121 * V_122 ;
char V_319 [ 64 ] ;
char * V_320 ;
if ( ! V_27 -> V_155 )
return - V_321 ;
if ( V_284 > 64 )
V_284 = 64 ;
if ( ! F_60 ( V_322 , V_3 , V_284 ) )
return - V_323 ;
memset ( V_319 , 0 , sizeof( V_319 ) ) ;
if ( F_49 ( V_319 , V_3 , V_284 ) )
return - V_323 ;
V_320 = & V_319 [ 0 ] ;
V_122 = (struct V_121 * ) V_27 -> V_155 -> V_157 ;
if ( ( strncmp ( V_320 , L_140 , strlen ( L_140 ) ) == 0 ) ||
( strncmp ( V_320 , L_141 , strlen ( L_141 ) ) == 0 ) ) {
F_61 ( & V_122 -> V_172 , 0 ) ;
F_61 ( & V_122 -> V_175 , 0 ) ;
F_61 ( & V_122 -> V_173 , 0 ) ;
F_61 ( & V_122 -> V_174 , 0 ) ;
F_61 ( & V_122 -> V_176 , 0 ) ;
F_61 ( & V_122 -> V_177 , 0 ) ;
F_61 ( & V_122 -> V_179 , 0 ) ;
F_61 ( & V_122 -> V_178 , 0 ) ;
F_61 ( & V_122 -> V_180 , 0 ) ;
F_61 ( & V_122 -> V_182 , 0 ) ;
F_61 ( & V_122 -> V_181 , 0 ) ;
F_61 ( & V_122 -> V_187 , 0 ) ;
F_61 ( & V_122 -> V_188 , 0 ) ;
F_61 ( & V_122 -> V_184 , 0 ) ;
F_61 ( & V_122 -> V_183 , 0 ) ;
F_61 ( & V_122 -> V_185 , 0 ) ;
F_61 ( & V_122 -> V_186 , 0 ) ;
F_61 ( & V_122 -> V_189 , 0 ) ;
F_61 ( & V_122 -> V_190 , 0 ) ;
F_61 ( & V_122 -> V_191 , 0 ) ;
F_61 ( & V_122 -> V_192 , 0 ) ;
F_61 ( & V_122 -> V_193 , 0 ) ;
F_61 ( & V_122 -> V_194 , 0 ) ;
}
return V_284 ;
}
static int
F_62 ( struct V_266 * V_266 , struct V_267 * V_267 )
{
struct V_1 * V_2 = V_266 -> V_268 ;
struct V_269 * V_270 ;
int V_271 = - V_272 ;
V_270 = F_2 ( sizeof( * V_270 ) , V_14 ) ;
if ( ! V_270 )
goto V_245;
V_270 -> V_12 = F_2 ( V_324 , V_14 ) ;
if ( ! V_270 -> V_12 ) {
F_5 ( V_270 ) ;
goto V_245;
}
V_270 -> V_7 = F_23 ( V_2 , V_270 -> V_12 ,
V_324 ) ;
V_270 -> V_268 = V_266 -> V_268 ;
V_267 -> V_274 = V_270 ;
V_271 = 0 ;
V_245:
return V_271 ;
}
static T_3
F_63 ( struct V_267 * V_267 , const char T_4 * V_3 ,
T_5 V_284 , T_6 * V_285 )
{
struct V_269 * V_270 = V_267 -> V_274 ;
struct V_1 * V_2 = (struct V_1 * ) V_270 -> V_268 ;
struct V_26 * V_27 = V_2 -> V_27 ;
char V_319 [ 64 ] ;
char * V_320 ;
if ( V_284 > 64 )
V_284 = 64 ;
if ( ! F_60 ( V_322 , V_3 , V_284 ) )
return - V_323 ;
memset ( V_319 , 0 , sizeof( V_319 ) ) ;
if ( F_49 ( V_319 , V_3 , V_284 ) )
return - V_323 ;
V_320 = & V_319 [ 0 ] ;
if ( ( strncmp ( V_320 , L_142 , sizeof( L_142 ) - 1 ) == 0 ) ) {
V_27 -> V_205 = 0 ;
V_27 -> V_218 = 0 ;
V_27 -> V_206 = 0 ;
V_27 -> V_208 = 0 ;
V_27 -> V_207 = 0xffffffff ;
V_27 -> V_209 = 0 ;
V_27 -> V_211 = 0 ;
V_27 -> V_210 = 0xffffffff ;
V_27 -> V_212 = 0 ;
V_27 -> V_214 = 0 ;
V_27 -> V_213 = 0xffffffff ;
V_27 -> V_215 = 0 ;
V_27 -> V_217 = 0 ;
V_27 -> V_216 = 0xffffffff ;
V_27 -> V_219 = 0 ;
V_27 -> V_221 = 0 ;
V_27 -> V_220 = 0xffffffff ;
V_27 -> V_225 = 0 ;
V_27 -> V_227 = 0 ;
V_27 -> V_226 = 0xffffffff ;
V_27 -> V_228 = 0 ;
V_27 -> V_230 = 0 ;
V_27 -> V_229 = 0xffffffff ;
V_27 -> V_231 = 0 ;
V_27 -> V_233 = 0 ;
V_27 -> V_232 = 0xffffffff ;
V_27 -> V_234 = 0 ;
V_27 -> V_236 = 0 ;
V_27 -> V_235 = 0xffffffff ;
V_27 -> V_222 = 0 ;
V_27 -> V_224 = 0 ;
V_27 -> V_223 = 0xffffffff ;
V_27 -> V_204 = 1 ;
return strlen ( V_320 ) ;
} else if ( ( strncmp ( V_320 , L_143 ,
sizeof( L_143 ) - 1 ) == 0 ) ) {
V_27 -> V_204 = 0 ;
return strlen ( V_320 ) ;
} else if ( ( strncmp ( V_320 , L_141 ,
sizeof( L_141 ) - 1 ) == 0 ) ) {
V_27 -> V_205 = 0 ;
V_27 -> V_218 = 0 ;
V_27 -> V_206 = 0 ;
V_27 -> V_208 = 0 ;
V_27 -> V_207 = 0xffffffff ;
V_27 -> V_209 = 0 ;
V_27 -> V_211 = 0 ;
V_27 -> V_210 = 0xffffffff ;
V_27 -> V_212 = 0 ;
V_27 -> V_214 = 0 ;
V_27 -> V_213 = 0xffffffff ;
V_27 -> V_215 = 0 ;
V_27 -> V_217 = 0 ;
V_27 -> V_216 = 0xffffffff ;
V_27 -> V_219 = 0 ;
V_27 -> V_221 = 0 ;
V_27 -> V_220 = 0xffffffff ;
V_27 -> V_225 = 0 ;
V_27 -> V_227 = 0 ;
V_27 -> V_226 = 0xffffffff ;
V_27 -> V_228 = 0 ;
V_27 -> V_230 = 0 ;
V_27 -> V_229 = 0xffffffff ;
V_27 -> V_231 = 0 ;
V_27 -> V_233 = 0 ;
V_27 -> V_232 = 0xffffffff ;
V_27 -> V_234 = 0 ;
V_27 -> V_236 = 0 ;
V_27 -> V_235 = 0xffffffff ;
V_27 -> V_222 = 0 ;
V_27 -> V_224 = 0 ;
V_27 -> V_223 = 0xffffffff ;
return strlen ( V_320 ) ;
}
return - V_325 ;
}
static int
F_64 ( struct V_266 * V_266 , struct V_267 * V_267 )
{
struct V_26 * V_27 = V_266 -> V_268 ;
struct V_269 * V_270 ;
int V_271 = - V_272 ;
V_270 = F_2 ( sizeof( * V_270 ) , V_14 ) ;
if ( ! V_270 )
goto V_245;
V_270 -> V_12 = F_2 ( V_326 , V_14 ) ;
if ( ! V_270 -> V_12 ) {
F_5 ( V_270 ) ;
goto V_245;
}
V_270 -> V_7 = F_25 ( V_27 , V_270 -> V_12 ,
V_326 ) ;
V_270 -> V_268 = V_266 -> V_268 ;
V_267 -> V_274 = V_270 ;
V_271 = 0 ;
V_245:
return V_271 ;
}
static T_3
F_65 ( struct V_267 * V_267 , const char T_4 * V_3 ,
T_5 V_284 , T_6 * V_285 )
{
struct V_269 * V_270 = V_267 -> V_274 ;
struct V_26 * V_27 = (struct V_26 * ) V_270 -> V_268 ;
int V_5 ;
unsigned long V_327 ;
char V_319 [ 64 ] ;
char * V_320 ;
if ( V_284 > 64 )
V_284 = 64 ;
if ( ! F_60 ( V_322 , V_3 , V_284 ) )
return - V_323 ;
memset ( V_319 , 0 , sizeof( V_319 ) ) ;
if ( F_49 ( V_319 , V_3 , V_284 ) )
return - V_323 ;
V_320 = & V_319 [ 0 ] ;
if ( ( strncmp ( V_320 , L_143 , sizeof( L_143 ) - 1 ) == 0 ) ) {
F_46 ( V_27 , V_313 , V_314 ,
L_144 ) ;
V_27 -> V_243 = 0 ;
V_27 -> V_240 = 0 ;
return strlen ( V_320 ) ;
} else if ( ( strncmp ( V_320 , L_142 , sizeof( L_142 ) - 1 ) == 0 ) ) {
F_46 ( V_27 , V_313 , V_314 ,
L_145 ) ;
V_27 -> V_243 = 0 ;
V_27 -> V_240 = 1 ;
return strlen ( V_320 ) ;
}
if ( V_27 -> V_240 != 0 )
return - V_325 ;
V_5 = F_66 ( V_320 , 0 , & V_327 ) ;
if ( V_5 )
return - V_325 ;
V_27 -> V_242 = ( T_1 ) V_327 ;
V_5 = 0 ;
while ( V_327 > 1 ) {
V_327 = V_327 >> 1 ;
V_5 ++ ;
}
V_327 = ( 1 << V_5 ) ;
if ( V_27 -> V_242 != V_327 )
F_46 ( V_27 , V_313 , V_314 ,
L_146 ,
V_327 ) ;
V_27 -> V_242 = ( T_1 ) V_327 ;
F_5 ( V_27 -> V_244 ) ;
V_27 -> V_244 = F_2 ( ( sizeof( struct V_237 ) *
V_327 ) , V_14 ) ;
if ( ! V_27 -> V_244 ) {
F_46 ( V_27 , V_313 , V_314 ,
L_147
L_148 ) ;
return - V_272 ;
}
memset ( V_27 -> V_244 , 0 ,
( sizeof( struct V_237 ) * V_327 ) ) ;
F_61 ( & V_27 -> V_241 , 0 ) ;
V_27 -> V_240 = 0 ;
V_27 -> V_243 = 0 ;
return strlen ( V_320 ) ;
}
static int
F_67 ( struct V_266 * V_266 , struct V_267 * V_267 )
{
struct V_1 * V_2 = V_266 -> V_268 ;
struct V_269 * V_270 ;
int V_271 = - V_272 ;
V_270 = F_2 ( sizeof( * V_270 ) , V_14 ) ;
if ( ! V_270 )
goto V_245;
V_270 -> V_12 = F_2 ( V_328 , V_14 ) ;
if ( ! V_270 -> V_12 ) {
F_5 ( V_270 ) ;
goto V_245;
}
V_270 -> V_7 = F_26 ( V_2 , V_270 -> V_12 ,
V_324 ) ;
V_270 -> V_268 = V_266 -> V_268 ;
V_267 -> V_274 = V_270 ;
V_271 = 0 ;
V_245:
return V_271 ;
}
static T_3
F_68 ( struct V_267 * V_267 , const char T_4 * V_3 ,
T_5 V_284 , T_6 * V_285 )
{
struct V_269 * V_270 = V_267 -> V_274 ;
struct V_1 * V_2 = (struct V_1 * ) V_270 -> V_268 ;
struct V_26 * V_27 = V_2 -> V_27 ;
char V_319 [ 64 ] ;
char * V_320 ;
int V_5 ;
if ( V_284 > 64 )
V_284 = 64 ;
if ( ! F_60 ( V_322 , V_3 , V_284 ) )
return - V_323 ;
memset ( V_319 , 0 , sizeof( V_319 ) ) ;
if ( F_49 ( V_319 , V_3 , V_284 ) )
return - V_323 ;
V_320 = & V_319 [ 0 ] ;
if ( ( strncmp ( V_320 , L_142 , sizeof( L_142 ) - 1 ) == 0 ) ) {
if ( V_27 -> V_154 )
V_27 -> V_251 |= V_258 ;
else
V_27 -> V_251 |= V_252 ;
return strlen ( V_320 ) ;
} else if ( ( strncmp ( V_320 , L_149 ,
sizeof( L_149 ) - 1 ) == 0 ) ) {
if ( V_27 -> V_154 )
V_27 -> V_251 |= V_259 ;
else
return - V_325 ;
return strlen ( V_320 ) ;
} else if ( ( strncmp ( V_320 , L_143 ,
sizeof( L_143 ) - 1 ) == 0 ) ) {
V_27 -> V_251 = V_329 ;
return strlen ( V_320 ) ;
} else if ( ( strncmp ( V_320 , L_141 ,
sizeof( L_141 ) - 1 ) == 0 ) ) {
for ( V_5 = 0 ; V_5 < V_27 -> V_253 . V_254 ; V_5 ++ ) {
if ( V_5 >= V_255 )
break;
V_27 -> V_261 [ V_5 ] = 0 ;
V_27 -> V_256 [ V_5 ] = 0 ;
V_27 -> V_257 [ V_5 ] = 0 ;
V_27 -> V_260 [ V_5 ] = 0 ;
}
return strlen ( V_320 ) ;
}
return - V_325 ;
}
static int F_69 ( const char T_4 * V_3 , T_5 V_284 ,
struct V_330 * V_331 )
{
char V_319 [ 64 ] ;
char * V_320 , * V_332 ;
int V_5 ;
T_5 V_333 ;
if ( ! F_60 ( V_322 , V_3 , V_284 ) )
return - V_323 ;
memset ( V_319 , 0 , sizeof( V_319 ) ) ;
memset ( V_331 , 0 , sizeof( * V_331 ) ) ;
V_333 = F_70 ( V_284 , ( sizeof( V_319 ) - 1 ) ) ;
if ( F_49 ( V_319 , V_3 , V_333 ) )
return - V_323 ;
V_320 = & V_319 [ 0 ] ;
V_332 = F_71 ( & V_320 , L_150 ) ;
if ( ! V_332 )
return - V_325 ;
V_331 -> V_334 = F_72 ( V_332 , NULL , 0 ) ;
if ( V_331 -> V_334 == 0 )
return - V_325 ;
for ( V_5 = 0 ; V_5 < V_335 ; V_5 ++ ) {
V_332 = F_71 ( & V_320 , L_150 ) ;
if ( ! V_332 )
return V_5 ;
V_331 -> V_336 [ V_5 ] = F_72 ( V_332 , NULL , 0 ) ;
}
return V_5 ;
}
static int
F_73 ( struct V_266 * V_266 , struct V_267 * V_267 )
{
struct V_269 * V_270 ;
V_270 = F_2 ( sizeof( * V_270 ) , V_14 ) ;
if ( ! V_270 )
return - V_272 ;
V_270 -> V_268 = V_266 -> V_268 ;
V_270 -> V_12 = NULL ;
V_267 -> V_274 = V_270 ;
return 0 ;
}
static int
F_74 ( struct V_266 * V_266 , struct V_267 * V_267 )
{
struct V_269 * V_270 = V_267 -> V_274 ;
F_5 ( V_270 -> V_12 ) ;
F_5 ( V_270 ) ;
return 0 ;
}
static int
F_75 ( struct V_266 * V_266 , struct V_267 * V_267 )
{
struct V_269 * V_270 = V_267 -> V_274 ;
if ( V_270 -> V_337 == V_338 ) {
switch ( V_339 . V_340 . V_334 ) {
case V_341 :
case V_342 :
case V_343 :
case V_344 :
case V_345 :
case V_346 :
memset ( & V_339 , 0 , sizeof( V_339 ) ) ;
break;
default:
break;
}
}
F_5 ( V_270 -> V_12 ) ;
F_5 ( V_270 ) ;
return 0 ;
}
static T_3
F_76 ( struct V_267 * V_267 , char T_4 * V_3 , T_5 V_284 ,
T_6 * V_285 )
{
struct V_269 * V_270 = V_267 -> V_274 ;
struct V_26 * V_27 = (struct V_26 * ) V_270 -> V_268 ;
int V_347 , V_348 , V_7 = 0 , V_6 = V_349 ;
int V_350 , V_351 ;
char * V_352 ;
struct V_353 * V_354 ;
T_1 V_355 ;
T_2 V_356 ;
T_7 V_357 ;
V_354 = V_27 -> V_358 ;
if ( ! V_354 )
return 0 ;
V_270 -> V_337 = V_359 ;
if ( ! V_270 -> V_12 )
V_270 -> V_12 = F_2 ( V_360 , V_14 ) ;
if ( ! V_270 -> V_12 )
return 0 ;
V_352 = V_270 -> V_12 ;
if ( * V_285 )
return 0 ;
if ( V_339 . V_340 . V_334 == V_361 ) {
V_350 = V_339 . V_340 . V_336 [ V_362 ] ;
V_351 = V_339 . V_340 . V_336 [ V_363 ] ;
} else
return 0 ;
switch ( V_351 ) {
case V_364 :
F_77 ( V_354 , V_350 , & V_357 ) ;
V_7 += snprintf ( V_352 + V_7 , V_360 - V_7 ,
L_151 , V_350 , V_357 ) ;
break;
case V_365 :
F_78 ( V_354 , V_350 , & V_356 ) ;
V_7 += snprintf ( V_352 + V_7 , V_360 - V_7 ,
L_152 , V_350 , V_356 ) ;
break;
case V_366 :
F_79 ( V_354 , V_350 , & V_355 ) ;
V_7 += snprintf ( V_352 + V_7 , V_360 - V_7 ,
L_153 , V_350 , V_355 ) ;
break;
case V_367 :
goto V_368;
break;
default:
V_7 = 0 ;
break;
}
return F_47 ( V_3 , V_284 , V_285 , V_352 , V_7 ) ;
V_368:
V_347 = V_339 . V_348 . V_369 ;
V_348 = V_347 ;
V_7 += snprintf ( V_352 + V_7 , V_360 - V_7 ,
L_154 , V_347 ) ;
while ( V_6 > 0 ) {
F_79 ( V_354 , V_348 , & V_355 ) ;
V_7 += snprintf ( V_352 + V_7 , V_360 - V_7 ,
L_155 , V_355 ) ;
V_348 += sizeof( T_1 ) ;
if ( V_348 >= V_360 ) {
V_7 += snprintf ( V_352 + V_7 ,
V_360 - V_7 , L_44 ) ;
break;
}
V_6 -= sizeof( T_1 ) ;
if ( ! V_6 )
V_7 += snprintf ( V_352 + V_7 , V_360 - V_7 ,
L_44 ) ;
else if ( ! ( V_6 % ( 8 * sizeof( T_1 ) ) ) ) {
V_347 += ( 8 * sizeof( T_1 ) ) ;
V_7 += snprintf ( V_352 + V_7 , V_360 - V_7 ,
L_156 , V_347 ) ;
}
}
if ( V_6 == 0 ) {
V_339 . V_348 . V_369 += V_349 ;
if ( V_339 . V_348 . V_369 >= V_360 )
V_339 . V_348 . V_369 = 0 ;
} else
V_339 . V_348 . V_369 = 0 ;
return F_47 ( V_3 , V_284 , V_285 , V_352 , V_7 ) ;
}
static T_3
F_80 ( struct V_267 * V_267 , const char T_4 * V_3 ,
T_5 V_284 , T_6 * V_285 )
{
struct V_269 * V_270 = V_267 -> V_274 ;
struct V_26 * V_27 = (struct V_26 * ) V_270 -> V_268 ;
T_1 V_350 , V_370 , V_351 ;
T_1 V_355 ;
T_2 V_356 ;
T_7 V_357 ;
struct V_353 * V_354 ;
int V_271 ;
V_354 = V_27 -> V_358 ;
if ( ! V_354 )
return - V_323 ;
V_270 -> V_337 = V_338 ;
V_271 = F_69 ( V_3 , V_284 , & V_339 . V_340 ) ;
if ( V_271 < 0 )
return V_271 ;
if ( V_339 . V_340 . V_334 == V_361 ) {
if ( V_271 != V_371 )
goto V_372;
V_350 = V_339 . V_340 . V_336 [ V_362 ] ;
V_351 = V_339 . V_340 . V_336 [ V_363 ] ;
if ( V_351 == V_367 ) {
if ( V_350 % sizeof( T_1 ) )
goto V_372;
V_339 . V_348 . V_369 = V_350 ;
} else if ( ( V_351 != sizeof( T_7 ) ) &&
( V_351 != sizeof( T_2 ) ) &&
( V_351 != sizeof( T_1 ) ) )
goto V_372;
if ( V_351 == sizeof( T_7 ) ) {
if ( V_350 > V_360 - sizeof( T_7 ) )
goto V_372;
if ( V_350 % sizeof( T_7 ) )
goto V_372;
}
if ( V_351 == sizeof( T_2 ) ) {
if ( V_350 > V_360 - sizeof( T_2 ) )
goto V_372;
if ( V_350 % sizeof( T_2 ) )
goto V_372;
}
if ( V_351 == sizeof( T_1 ) ) {
if ( V_350 > V_360 - sizeof( T_1 ) )
goto V_372;
if ( V_350 % sizeof( T_1 ) )
goto V_372;
}
} else if ( V_339 . V_340 . V_334 == V_341 ||
V_339 . V_340 . V_334 == V_342 ||
V_339 . V_340 . V_334 == V_343 ) {
if ( V_271 != V_373 )
goto V_372;
V_350 = V_339 . V_340 . V_336 [ V_362 ] ;
V_351 = V_339 . V_340 . V_336 [ V_363 ] ;
V_370 = V_339 . V_340 . V_336 [ V_374 ] ;
if ( ( V_351 != sizeof( T_7 ) ) &&
( V_351 != sizeof( T_2 ) ) &&
( V_351 != sizeof( T_1 ) ) )
goto V_372;
if ( V_351 == sizeof( T_7 ) ) {
if ( V_350 > V_360 - sizeof( T_7 ) )
goto V_372;
if ( V_350 % sizeof( T_7 ) )
goto V_372;
if ( V_339 . V_340 . V_334 == V_341 )
F_81 ( V_354 , V_350 ,
( T_7 ) V_370 ) ;
if ( V_339 . V_340 . V_334 == V_342 ) {
V_271 = F_77 ( V_354 , V_350 , & V_357 ) ;
if ( ! V_271 ) {
V_357 |= ( T_7 ) V_370 ;
F_81 ( V_354 , V_350 ,
V_357 ) ;
}
}
if ( V_339 . V_340 . V_334 == V_343 ) {
V_271 = F_77 ( V_354 , V_350 , & V_357 ) ;
if ( ! V_271 ) {
V_357 &= ( T_7 ) ( ~ V_370 ) ;
F_81 ( V_354 , V_350 ,
V_357 ) ;
}
}
}
if ( V_351 == sizeof( T_2 ) ) {
if ( V_350 > V_360 - sizeof( T_2 ) )
goto V_372;
if ( V_350 % sizeof( T_2 ) )
goto V_372;
if ( V_339 . V_340 . V_334 == V_341 )
F_82 ( V_354 , V_350 ,
( T_2 ) V_370 ) ;
if ( V_339 . V_340 . V_334 == V_342 ) {
V_271 = F_78 ( V_354 , V_350 , & V_356 ) ;
if ( ! V_271 ) {
V_356 |= ( T_2 ) V_370 ;
F_82 ( V_354 , V_350 ,
V_356 ) ;
}
}
if ( V_339 . V_340 . V_334 == V_343 ) {
V_271 = F_78 ( V_354 , V_350 , & V_356 ) ;
if ( ! V_271 ) {
V_356 &= ( T_2 ) ( ~ V_370 ) ;
F_82 ( V_354 , V_350 ,
V_356 ) ;
}
}
}
if ( V_351 == sizeof( T_1 ) ) {
if ( V_350 > V_360 - sizeof( T_1 ) )
goto V_372;
if ( V_350 % sizeof( T_1 ) )
goto V_372;
if ( V_339 . V_340 . V_334 == V_341 )
F_83 ( V_354 , V_350 , V_370 ) ;
if ( V_339 . V_340 . V_334 == V_342 ) {
V_271 = F_79 ( V_354 , V_350 ,
& V_355 ) ;
if ( ! V_271 ) {
V_355 |= V_370 ;
F_83 ( V_354 , V_350 ,
V_355 ) ;
}
}
if ( V_339 . V_340 . V_334 == V_343 ) {
V_271 = F_79 ( V_354 , V_350 ,
& V_355 ) ;
if ( ! V_271 ) {
V_355 &= ~ V_370 ;
F_83 ( V_354 , V_350 ,
V_355 ) ;
}
}
}
} else
goto V_372;
return V_284 ;
V_372:
memset ( & V_339 , 0 , sizeof( V_339 ) ) ;
return - V_325 ;
}
static T_3
F_84 ( struct V_267 * V_267 , char T_4 * V_3 , T_5 V_284 ,
T_6 * V_285 )
{
struct V_269 * V_270 = V_267 -> V_274 ;
struct V_26 * V_27 = (struct V_26 * ) V_270 -> V_268 ;
int V_347 , V_348 , V_375 , V_7 = 0 , V_6 ;
int V_376 , V_377 , V_378 ;
char * V_352 ;
void T_8 * V_379 ;
T_1 V_380 ;
struct V_353 * V_354 ;
T_1 V_355 ;
V_354 = V_27 -> V_358 ;
if ( ! V_354 )
return 0 ;
V_270 -> V_337 = V_359 ;
if ( ! V_270 -> V_12 )
V_270 -> V_12 = F_2 ( V_381 , V_14 ) ;
if ( ! V_270 -> V_12 )
return 0 ;
V_352 = V_270 -> V_12 ;
if ( * V_285 )
return 0 ;
if ( V_339 . V_340 . V_334 == V_382 ) {
V_376 = V_339 . V_340 . V_336 [ V_383 ] ;
V_348 = V_339 . V_340 . V_336 [ V_384 ] ;
V_377 = V_339 . V_340 . V_336 [ V_385 ] ;
V_378 = V_339 . V_340 . V_336 [ V_386 ] ;
} else
return 0 ;
if ( V_377 == 0 )
return 0 ;
V_380 = F_85 ( V_387 , & V_27 -> V_253 . V_388 ) ;
if ( V_380 == V_389 ) {
if ( V_376 == V_390 )
V_379 = V_27 -> V_253 . V_391 ;
else if ( V_376 == V_392 )
V_379 = V_27 -> V_253 . V_393 ;
else if ( V_376 == V_394 )
V_379 = V_27 -> V_253 . V_395 ;
else
return 0 ;
} else if ( V_380 == V_396 ) {
if ( V_376 == V_390 )
V_379 = V_27 -> V_253 . V_391 ;
else
return 0 ;
} else
return 0 ;
if ( V_377 == V_397 ) {
V_375 = V_348 ;
V_355 = F_17 ( V_379 + V_375 ) ;
V_7 += snprintf ( V_352 + V_7 , V_381 - V_7 ,
L_157 , V_375 , V_355 ) ;
} else
goto V_398;
return F_47 ( V_3 , V_284 , V_285 , V_352 , V_7 ) ;
V_398:
V_347 = V_339 . V_348 . V_369 ;
V_375 = V_347 ;
V_7 += snprintf ( V_352 + V_7 , V_381 - V_7 ,
L_158 , V_347 ) ;
V_6 = V_399 ;
while ( V_6 > 0 ) {
V_355 = F_17 ( V_379 + V_375 ) ;
V_7 += snprintf ( V_352 + V_7 , V_381 - V_7 ,
L_155 , V_355 ) ;
V_375 += sizeof( T_1 ) ;
if ( V_377 == V_400 ) {
if ( V_375 >= V_378 ) {
V_7 += snprintf ( V_352 + V_7 ,
V_381 - V_7 , L_44 ) ;
break;
}
} else {
if ( V_375 >= V_348 +
( V_377 * sizeof( T_1 ) ) ) {
V_7 += snprintf ( V_352 + V_7 ,
V_381 - V_7 , L_44 ) ;
break;
}
}
V_6 -= sizeof( T_1 ) ;
if ( ! V_6 )
V_7 += snprintf ( V_352 + V_7 ,
V_381 - V_7 , L_44 ) ;
else if ( ! ( V_6 % ( 8 * sizeof( T_1 ) ) ) ) {
V_347 += ( 8 * sizeof( T_1 ) ) ;
V_7 += snprintf ( V_352 + V_7 ,
V_381 - V_7 ,
L_159 , V_347 ) ;
}
}
if ( V_6 == 0 ) {
V_339 . V_348 . V_369 += V_399 ;
if ( V_377 == V_400 ) {
if ( V_339 . V_348 . V_369 >= V_378 )
V_339 . V_348 . V_369 = 0 ;
} else {
if ( V_375 >= V_348 +
( V_377 * sizeof( T_1 ) ) )
V_339 . V_348 . V_369 = V_348 ;
}
} else {
if ( V_377 == V_400 )
V_339 . V_348 . V_369 = 0 ;
else
V_339 . V_348 . V_369 = V_348 ;
}
return F_47 ( V_3 , V_284 , V_285 , V_352 , V_7 ) ;
}
static T_3
F_86 ( struct V_267 * V_267 , const char T_4 * V_3 ,
T_5 V_284 , T_6 * V_285 )
{
struct V_269 * V_270 = V_267 -> V_274 ;
struct V_26 * V_27 = (struct V_26 * ) V_270 -> V_268 ;
T_1 V_376 , V_378 , V_348 , V_370 , V_377 ;
struct V_353 * V_354 ;
void T_8 * V_379 ;
T_1 V_380 ;
T_1 V_355 ;
int V_271 ;
V_354 = V_27 -> V_358 ;
if ( ! V_354 )
return - V_323 ;
V_270 -> V_337 = V_338 ;
V_271 = F_69 ( V_3 , V_284 , & V_339 . V_340 ) ;
if ( V_271 < 0 )
return V_271 ;
V_380 = F_85 ( V_387 , & V_27 -> V_253 . V_388 ) ;
V_376 = V_339 . V_340 . V_336 [ V_383 ] ;
if ( V_380 == V_389 ) {
if ( ( V_376 != V_390 ) &&
( V_376 != V_392 ) &&
( V_376 != V_394 ) )
goto V_372;
} else if ( V_380 == V_396 ) {
if ( V_376 != V_390 )
goto V_372;
} else
goto V_372;
if ( V_380 == V_389 ) {
if ( V_376 == V_390 ) {
V_339 . V_340 . V_336 [ V_386 ] =
V_401 ;
V_379 = V_27 -> V_253 . V_391 ;
} else if ( V_376 == V_392 ) {
V_339 . V_340 . V_336 [ V_386 ] =
V_402 ;
V_379 = V_27 -> V_253 . V_393 ;
} else if ( V_376 == V_394 ) {
V_339 . V_340 . V_336 [ V_386 ] =
V_403 ;
V_379 = V_27 -> V_253 . V_395 ;
} else
goto V_372;
} else if ( V_380 == V_396 ) {
if ( V_376 == V_390 ) {
V_339 . V_340 . V_336 [ V_386 ] =
V_404 ;
V_379 = V_27 -> V_253 . V_391 ;
} else
goto V_372;
} else
goto V_372;
V_348 = V_339 . V_340 . V_336 [ V_384 ] ;
if ( V_348 % sizeof( T_1 ) )
goto V_372;
V_378 = V_339 . V_340 . V_336 [ V_386 ] ;
if ( V_339 . V_340 . V_334 == V_382 ) {
if ( V_271 != V_405 )
goto V_372;
V_377 = V_339 . V_340 . V_336 [ V_385 ] ;
if ( V_377 == V_400 ) {
if ( V_348 > V_378 - sizeof( T_1 ) )
goto V_372;
V_339 . V_348 . V_369 = V_348 ;
} else if ( V_377 > V_397 ) {
if ( V_348 + V_377 * sizeof( T_1 ) > V_378 )
goto V_372;
V_339 . V_348 . V_369 = V_348 ;
} else if ( V_377 != V_397 )
goto V_372;
} else if ( V_339 . V_340 . V_334 == V_406 ||
V_339 . V_340 . V_334 == V_407 ||
V_339 . V_340 . V_334 == V_408 ) {
if ( V_271 != V_409 )
goto V_372;
V_377 = V_397 ;
V_370 = V_339 . V_340 . V_336 [ V_410 ] ;
if ( V_339 . V_340 . V_334 == V_406 ) {
F_87 ( V_370 , V_379 + V_348 ) ;
F_17 ( V_379 + V_348 ) ;
}
if ( V_339 . V_340 . V_334 == V_407 ) {
V_355 = F_17 ( V_379 + V_348 ) ;
V_355 |= V_370 ;
F_87 ( V_355 , V_379 + V_348 ) ;
F_17 ( V_379 + V_348 ) ;
}
if ( V_339 . V_340 . V_334 == V_408 ) {
V_355 = F_17 ( V_379 + V_348 ) ;
V_355 &= ~ V_370 ;
F_87 ( V_355 , V_379 + V_348 ) ;
F_17 ( V_379 + V_348 ) ;
}
} else
goto V_372;
return V_284 ;
V_372:
memset ( & V_339 , 0 , sizeof( V_339 ) ) ;
return - V_325 ;
}
static int
F_88 ( struct V_411 * V_412 , char * V_413 ,
char * V_352 , int V_7 )
{
if ( ! V_412 )
return V_7 ;
V_7 += snprintf ( V_352 + V_7 , V_414 - V_7 ,
L_160 , V_413 ) ;
V_7 += snprintf ( V_352 + V_7 , V_414 - V_7 ,
L_161 ,
V_412 -> V_415 , V_412 -> V_416 ,
( unsigned long long ) V_412 -> V_417 ) ;
V_7 += snprintf ( V_352 + V_7 , V_414 - V_7 ,
L_162
L_163 ,
V_412 -> V_418 , V_412 -> V_59 ,
V_412 -> V_419 , V_412 -> V_420 ,
V_412 -> V_421 ) ;
V_7 += snprintf ( V_352 + V_7 ,
V_414 - V_7 , L_44 ) ;
return V_7 ;
}
static int
F_89 ( struct V_26 * V_27 , char * V_413 , char * V_352 ,
int * V_7 , int V_422 , int V_423 )
{
struct V_411 * V_412 ;
int V_424 ;
for ( V_424 = 0 ; V_424 < V_27 -> V_425 ; V_424 ++ ) {
V_412 = V_27 -> V_253 . V_426 [ V_424 ] ;
if ( V_412 -> V_415 != V_423 )
continue;
* V_7 = F_88 ( V_412 , V_413 , V_352 , * V_7 ) ;
if ( * V_7 >= V_422 )
return 1 ;
}
for ( V_424 = 0 ; V_424 < V_27 -> V_427 ; V_424 ++ ) {
V_412 = V_27 -> V_253 . V_428 [ V_424 ] ;
if ( V_412 -> V_415 != V_423 )
continue;
* V_7 = F_88 ( V_412 , V_413 , V_352 , * V_7 ) ;
if ( * V_7 >= V_422 )
return 1 ;
}
return 0 ;
}
static int
F_90 ( struct V_411 * V_412 , char * V_429 ,
char * V_352 , int V_7 )
{
if ( ! V_412 )
return V_7 ;
V_7 += snprintf ( V_352 + V_7 , V_414 - V_7 ,
L_164 , V_429 ) ;
V_7 += snprintf ( V_352 + V_7 , V_414 - V_7 ,
L_165
L_166 ,
V_412 -> V_415 , V_412 -> V_416 , V_412 -> V_430 ,
V_412 -> V_431 , ( unsigned long long ) V_412 -> V_417 ) ;
V_7 += snprintf ( V_352 + V_7 , V_414 - V_7 ,
L_167
L_163 ,
V_412 -> V_418 , V_412 -> V_59 ,
V_412 -> V_419 , V_412 -> V_420 ,
V_412 -> V_421 ) ;
V_7 += snprintf ( V_352 + V_7 , V_414 - V_7 , L_44 ) ;
return V_7 ;
}
static int
F_91 ( struct V_411 * V_412 , struct V_411 * V_432 ,
char * V_433 , char * V_352 , int V_7 )
{
if ( ! V_412 || ! V_432 )
return V_7 ;
V_7 += snprintf ( V_352 + V_7 , V_414 - V_7 ,
L_168 , V_433 ) ;
V_7 += snprintf ( V_352 + V_7 , V_414 - V_7 ,
L_169
L_170 ,
V_412 -> V_415 , V_412 -> V_416 , V_412 -> V_430 ,
V_412 -> V_431 , ( unsigned long long ) V_412 -> V_417 ) ;
V_7 += snprintf ( V_352 + V_7 , V_414 - V_7 ,
L_171
L_172 ,
V_412 -> V_418 , V_412 -> V_59 , V_412 -> V_419 ,
V_412 -> V_420 , V_412 -> V_421 ) ;
V_7 += snprintf ( V_352 + V_7 , V_414 - V_7 ,
L_173
L_172 ,
V_432 -> V_418 , V_432 -> V_59 ,
V_432 -> V_419 , V_432 -> V_420 ,
V_432 -> V_421 ) ;
V_7 += snprintf ( V_352 + V_7 , V_414 - V_7 , L_44 ) ;
return V_7 ;
}
static int
F_92 ( struct V_26 * V_27 , char * V_352 ,
int * V_7 , int V_422 , int V_434 , int V_435 )
{
struct V_411 * V_412 ;
int V_424 , V_271 ;
for ( V_424 = 0 ; V_424 < V_27 -> V_425 ; V_424 ++ ) {
V_412 = V_27 -> V_253 . V_436 [ V_424 ] ;
if ( V_412 -> V_415 != V_435 )
continue;
* V_7 = F_90 ( V_412 , L_174 , V_352 , * V_7 ) ;
V_412 -> V_437 = 0 ;
if ( * V_7 >= V_422 )
return 1 ;
V_271 = F_89 ( V_27 , L_174 , V_352 , V_7 ,
V_422 , V_412 -> V_418 ) ;
if ( V_271 )
return 1 ;
}
for ( V_424 = 0 ; V_424 < V_27 -> V_427 ; V_424 ++ ) {
V_412 = V_27 -> V_253 . V_438 [ V_424 ] ;
if ( V_412 -> V_415 != V_435 )
continue;
* V_7 = F_90 ( V_412 , L_114 , V_352 , * V_7 ) ;
V_412 -> V_437 = 0 ;
if ( * V_7 >= V_422 )
return 1 ;
V_271 = F_89 ( V_27 , L_114 , V_352 , V_7 ,
V_422 , V_412 -> V_418 ) ;
if ( V_271 )
return 1 ;
}
if ( V_434 < V_27 -> V_439 ) {
V_412 = V_27 -> V_253 . V_440 [ V_434 ] ;
* V_7 = F_90 ( V_412 , L_175 , V_352 , * V_7 ) ;
V_412 -> V_437 = 0 ;
if ( * V_7 >= V_422 )
return 1 ;
V_412 = V_27 -> V_253 . V_441 [ V_434 ] ;
* V_7 = F_91 ( V_412 ,
V_27 -> V_253 . V_442 [ V_434 ] ,
L_176 , V_352 , * V_7 ) ;
if ( * V_7 >= V_422 )
return 1 ;
}
return 0 ;
}
static int
F_93 ( struct V_411 * V_412 , char * V_443 ,
char * V_352 , int V_7 )
{
if ( ! V_412 )
return V_7 ;
V_7 += snprintf ( V_352 + V_7 , V_414 - V_7 ,
L_177
L_178 ,
V_443 , V_412 -> V_416 , V_412 -> V_430 , V_412 -> V_431 ,
( unsigned long long ) V_412 -> V_417 ) ;
V_7 += snprintf ( V_352 + V_7 , V_414 - V_7 ,
L_179
L_163 ,
V_412 -> V_418 , V_412 -> V_59 , V_412 -> V_419 ,
V_412 -> V_420 , V_412 -> V_421 ) ;
V_7 += snprintf ( V_352 + V_7 , V_414 - V_7 , L_44 ) ;
return V_7 ;
}
static T_3
F_94 ( struct V_267 * V_267 , char T_4 * V_3 , T_5 V_284 ,
T_6 * V_285 )
{
struct V_269 * V_270 = V_267 -> V_274 ;
struct V_26 * V_27 = (struct V_26 * ) V_270 -> V_268 ;
char * V_352 ;
int V_422 , V_271 , V_444 , V_7 = 0 ;
struct V_411 * V_412 = NULL ;
if ( ! V_270 -> V_12 )
V_270 -> V_12 = F_2 ( V_414 , V_14 ) ;
if ( ! V_270 -> V_12 )
return 0 ;
V_352 = V_270 -> V_12 ;
V_422 = V_414 - 256 ;
if ( * V_285 )
return 0 ;
F_8 ( & V_27 -> V_49 ) ;
if ( V_27 -> V_253 . V_445 && V_27 -> V_446 ) {
V_444 = V_27 -> V_447 ;
if ( V_27 -> V_448 && ( V_444 >= V_27 -> V_446 ) ) {
V_27 -> V_447 = 0 ;
goto V_449;
}
V_27 -> V_447 ++ ;
if ( V_27 -> V_447 >= V_27 -> V_446 )
if ( V_27 -> V_448 == 0 )
V_27 -> V_447 = 0 ;
V_7 += snprintf ( V_352 + V_7 , V_414 - V_7 ,
L_180 ,
V_444 , V_27 -> V_446 ) ;
V_412 = V_27 -> V_253 . V_445 [ V_444 ] ;
if ( ! V_412 )
goto V_245;
V_7 = F_93 ( V_412 , L_181 , V_352 , V_7 ) ;
V_412 -> V_450 = 0 ;
if ( V_7 >= V_422 )
goto V_451;
V_271 = F_92 ( V_27 , V_352 , & V_7 ,
V_422 , V_444 , V_412 -> V_418 ) ;
if ( V_271 )
goto V_451;
if ( V_444 )
goto V_245;
V_412 = V_27 -> V_253 . V_452 ;
V_7 = F_90 ( V_412 , L_182 , V_352 , V_7 ) ;
if ( V_7 >= V_422 )
goto V_451;
V_412 = V_27 -> V_253 . V_453 ;
V_7 = F_88 ( V_412 , L_182 , V_352 , V_7 ) ;
if ( V_7 >= V_422 )
goto V_451;
V_412 = V_27 -> V_253 . V_454 ;
V_7 = F_90 ( V_412 , L_183 , V_352 , V_7 ) ;
if ( V_412 )
V_412 -> V_437 = 0 ;
if ( V_7 >= V_422 )
goto V_451;
V_412 = V_27 -> V_253 . V_455 ;
V_7 = F_88 ( V_412 , L_183 , V_352 , V_7 ) ;
if ( V_7 >= V_422 )
goto V_451;
V_412 = V_27 -> V_253 . V_456 ;
V_7 = F_90 ( V_412 , L_184 ,
V_352 , V_7 ) ;
if ( V_412 )
V_412 -> V_437 = 0 ;
if ( V_7 >= V_422 )
goto V_451;
V_412 = V_27 -> V_253 . V_457 ;
V_7 = F_88 ( V_412 , L_184 ,
V_352 , V_7 ) ;
if ( V_7 >= V_422 )
goto V_451;
V_412 = V_27 -> V_253 . V_458 ;
V_7 = F_91 ( V_412 , V_27 -> V_253 . V_459 ,
L_185 , V_352 , V_7 ) ;
if ( V_7 >= V_422 )
goto V_451;
goto V_245;
}
V_449:
if ( V_27 -> V_448 ) {
V_412 = V_27 -> V_253 . V_460 ;
V_7 = F_93 ( V_412 , L_186 , V_352 , V_7 ) ;
if ( V_412 )
V_412 -> V_450 = 0 ;
if ( V_7 >= V_422 )
goto V_451;
V_412 = V_27 -> V_253 . V_461 ;
V_7 = F_90 ( V_412 , L_187 , V_352 , V_7 ) ;
if ( V_412 )
V_412 -> V_437 = 0 ;
if ( V_7 >= V_422 )
goto V_451;
V_412 = V_27 -> V_253 . V_462 ;
V_7 = F_88 ( V_412 , L_187 , V_352 , V_7 ) ;
if ( V_7 >= V_422 )
goto V_451;
}
F_13 ( & V_27 -> V_49 ) ;
return F_47 ( V_3 , V_284 , V_285 , V_352 , V_7 ) ;
V_451:
V_7 += snprintf ( V_352 + V_7 ,
V_414 - V_7 , L_188 ) ;
V_245:
F_13 ( & V_27 -> V_49 ) ;
return F_47 ( V_3 , V_284 , V_285 , V_352 , V_7 ) ;
}
static int
F_95 ( struct V_411 * V_463 , int V_6 , int V_351 )
{
if ( ( V_351 != 1 ) && ( V_351 != V_464 ) )
return - V_325 ;
if ( V_6 > V_463 -> V_59 - 1 )
return - V_325 ;
return 0 ;
}
static int
F_96 ( char * V_352 , int V_7 , struct V_411 * V_465 ,
T_1 V_6 )
{
int V_348 , V_466 ;
T_1 * V_467 ;
if ( ! V_352 || ! V_465 )
return 0 ;
V_466 = V_465 -> V_419 ;
V_7 += snprintf ( V_352 + V_7 , V_468 - V_7 ,
L_189 , V_6 ) ;
V_348 = 0 ;
V_467 = V_465 -> V_469 [ V_6 ] . V_470 ;
while ( V_466 > 0 ) {
V_7 += snprintf ( V_352 + V_7 , V_468 - V_7 ,
L_155 , * V_467 ) ;
V_467 ++ ;
V_348 += sizeof( T_1 ) ;
V_466 -= sizeof( T_1 ) ;
if ( V_466 > 0 && ! ( V_348 % ( 4 * sizeof( T_1 ) ) ) )
V_7 += snprintf ( V_352 + V_7 ,
V_468 - V_7 , L_44 ) ;
}
V_7 += snprintf ( V_352 + V_7 , V_468 - V_7 , L_44 ) ;
return V_7 ;
}
static T_3
F_97 ( struct V_267 * V_267 , char T_4 * V_3 , T_5 V_284 ,
T_6 * V_285 )
{
struct V_269 * V_270 = V_267 -> V_274 ;
T_1 V_471 , V_6 , V_351 ;
struct V_411 * V_465 = NULL ;
char * V_352 ;
int V_7 = 0 ;
V_270 -> V_337 = V_359 ;
if ( ! V_270 -> V_12 )
V_270 -> V_12 = F_2 ( V_468 , V_14 ) ;
if ( ! V_270 -> V_12 )
return 0 ;
V_352 = V_270 -> V_12 ;
if ( * V_285 )
return 0 ;
if ( V_339 . V_340 . V_334 == V_472 ) {
V_6 = V_339 . V_340 . V_336 [ V_473 ] ;
V_351 = V_339 . V_340 . V_336 [ V_474 ] ;
V_465 = (struct V_411 * ) V_339 . V_475 ;
} else
return 0 ;
if ( V_351 == V_464 )
goto V_476;
V_7 = F_96 ( V_352 , V_7 , V_465 , V_6 ) ;
return F_47 ( V_3 , V_284 , V_285 , V_352 , V_7 ) ;
V_476:
V_471 = V_339 . V_348 . V_369 ;
V_6 = V_471 ;
while ( V_7 < V_477 - V_465 -> V_419 ) {
V_7 = F_96 ( V_352 , V_7 , V_465 , V_6 ) ;
V_6 ++ ;
if ( V_6 > V_465 -> V_59 - 1 )
break;
}
if ( V_6 > V_465 -> V_59 - 1 )
V_6 = 0 ;
V_339 . V_348 . V_369 = V_6 ;
return F_47 ( V_3 , V_284 , V_285 , V_352 , V_7 ) ;
}
static T_3
F_98 ( struct V_267 * V_267 , const char T_4 * V_3 ,
T_5 V_284 , T_6 * V_285 )
{
struct V_269 * V_270 = V_267 -> V_274 ;
struct V_26 * V_27 = (struct V_26 * ) V_270 -> V_268 ;
T_1 V_424 , V_478 , V_479 , V_6 , V_351 , V_348 , V_370 ;
T_1 * V_467 ;
struct V_411 * V_465 , * V_412 ;
int V_271 ;
V_270 -> V_337 = V_338 ;
V_271 = F_69 ( V_3 , V_284 , & V_339 . V_340 ) ;
if ( V_271 < 0 )
return V_271 ;
V_478 = V_339 . V_340 . V_336 [ V_480 ] ;
V_479 = V_339 . V_340 . V_336 [ V_481 ] ;
V_6 = V_339 . V_340 . V_336 [ V_473 ] ;
V_351 = V_339 . V_340 . V_336 [ V_474 ] ;
V_348 = V_339 . V_340 . V_336 [ V_482 ] ;
V_370 = V_339 . V_340 . V_336 [ V_483 ] ;
if ( V_339 . V_340 . V_334 == V_344 ||
V_339 . V_340 . V_334 == V_345 ||
V_339 . V_340 . V_334 == V_346 ) {
if ( V_271 != V_484 )
goto V_372;
if ( V_351 != 1 )
goto V_372;
} else if ( V_339 . V_340 . V_334 == V_472 ) {
if ( V_271 != V_485 )
goto V_372;
} else
goto V_372;
switch ( V_478 ) {
case V_486 :
if ( V_27 -> V_253 . V_445 ) {
for ( V_424 = 0 ; V_424 < V_27 -> V_446 ; V_424 ++ ) {
V_412 = V_27 -> V_253 . V_445 [ V_424 ] ;
if ( V_412 && V_412 -> V_418 == V_479 ) {
V_271 = F_95 ( V_412 ,
V_6 , V_351 ) ;
if ( V_271 )
goto V_372;
V_339 . V_475 = V_412 ;
goto V_487;
}
}
}
goto V_372;
break;
case V_488 :
if ( V_27 -> V_253 . V_452 &&
V_27 -> V_253 . V_452 -> V_418 == V_479 ) {
V_271 = F_95 (
V_27 -> V_253 . V_452 , V_6 , V_351 ) ;
if ( V_271 )
goto V_372;
V_339 . V_475 = V_27 -> V_253 . V_452 ;
goto V_487;
}
if ( V_27 -> V_253 . V_454 &&
V_27 -> V_253 . V_454 -> V_418 == V_479 ) {
V_271 = F_95 (
V_27 -> V_253 . V_454 , V_6 , V_351 ) ;
if ( V_271 )
goto V_372;
V_339 . V_475 = V_27 -> V_253 . V_454 ;
goto V_487;
}
if ( V_27 -> V_253 . V_456 &&
V_27 -> V_253 . V_456 -> V_418 == V_479 ) {
V_271 = F_95 (
V_27 -> V_253 . V_456 , V_6 , V_351 ) ;
if ( V_271 )
goto V_372;
V_339 . V_475 = V_27 -> V_253 . V_456 ;
goto V_487;
}
if ( V_27 -> V_253 . V_436 ) {
for ( V_424 = 0 ; V_424 < V_27 -> V_425 ;
V_424 ++ ) {
V_412 = V_27 -> V_253 . V_436 [ V_424 ] ;
if ( V_412 && V_412 -> V_418 == V_479 ) {
V_271 = F_95 (
V_412 , V_6 , V_351 ) ;
if ( V_271 )
goto V_372;
V_339 . V_475 = V_412 ;
goto V_487;
}
}
}
if ( V_27 -> V_253 . V_438 ) {
V_424 = 0 ;
do {
if ( V_27 -> V_253 . V_438 [ V_424 ] &&
V_27 -> V_253 . V_438 [ V_424 ] -> V_418 ==
V_479 ) {
V_271 = F_95 (
V_27 -> V_253 . V_438 [ V_424 ] ,
V_6 , V_351 ) ;
if ( V_271 )
goto V_372;
V_339 . V_475 =
V_27 -> V_253 . V_438 [ V_424 ] ;
goto V_487;
}
} while ( ++ V_424 < V_27 -> V_427 );
}
goto V_372;
break;
case V_489 :
if ( V_27 -> V_253 . V_453 &&
V_27 -> V_253 . V_453 -> V_418 == V_479 ) {
V_271 = F_95 (
V_27 -> V_253 . V_453 , V_6 , V_351 ) ;
if ( V_271 )
goto V_372;
V_339 . V_475 = V_27 -> V_253 . V_453 ;
goto V_487;
}
goto V_372;
break;
case V_490 :
if ( V_27 -> V_253 . V_455 &&
V_27 -> V_253 . V_455 -> V_418 == V_479 ) {
V_271 = F_95 (
V_27 -> V_253 . V_455 , V_6 , V_351 ) ;
if ( V_271 )
goto V_372;
V_339 . V_475 = V_27 -> V_253 . V_455 ;
goto V_487;
}
if ( V_27 -> V_253 . V_457 &&
V_27 -> V_253 . V_457 -> V_418 == V_479 ) {
V_271 = F_95 (
V_27 -> V_253 . V_457 , V_6 , V_351 ) ;
if ( V_271 )
goto V_372;
V_339 . V_475 = V_27 -> V_253 . V_457 ;
goto V_487;
}
if ( V_27 -> V_253 . V_426 ) {
for ( V_424 = 0 ; V_424 < V_27 -> V_425 ;
V_424 ++ ) {
V_412 = V_27 -> V_253 . V_426 [ V_424 ] ;
if ( V_412 && V_412 -> V_418 == V_479 ) {
V_271 = F_95 (
V_412 , V_6 , V_351 ) ;
if ( V_271 )
goto V_372;
V_339 . V_475 = V_412 ;
goto V_487;
}
}
}
if ( V_27 -> V_253 . V_428 ) {
for ( V_424 = 0 ; V_424 < V_27 -> V_427 ;
V_424 ++ ) {
V_412 = V_27 -> V_253 . V_428 [ V_424 ] ;
if ( V_412 && V_412 -> V_418 == V_479 ) {
V_271 = F_95 (
V_412 , V_6 , V_351 ) ;
if ( V_271 )
goto V_372;
V_339 . V_475 = V_412 ;
goto V_487;
}
}
}
if ( V_27 -> V_253 . V_428 ) {
for ( V_424 = 0 ; V_424 < V_27 -> V_427 ;
V_424 ++ ) {
if ( ! V_27 -> V_253 . V_428 [ V_424 ] )
continue;
if ( V_27 -> V_253 . V_428 [ V_424 ] -> V_418 ==
V_479 ) {
V_271 = F_95 (
V_27 -> V_253 . V_428 [ V_424 ] ,
V_6 , V_351 ) ;
if ( V_271 )
goto V_372;
V_339 . V_475 =
V_27 -> V_253 . V_428 [ V_424 ] ;
goto V_487;
}
}
}
goto V_372;
break;
case V_491 :
if ( V_27 -> V_253 . V_458 &&
V_27 -> V_253 . V_458 -> V_418 == V_479 ) {
V_271 = F_95 (
V_27 -> V_253 . V_458 , V_6 , V_351 ) ;
if ( V_271 )
goto V_372;
V_339 . V_475 = V_27 -> V_253 . V_458 ;
goto V_487;
}
if ( V_27 -> V_253 . V_459 &&
V_27 -> V_253 . V_459 -> V_418 == V_479 ) {
V_271 = F_95 (
V_27 -> V_253 . V_459 , V_6 , V_351 ) ;
if ( V_271 )
goto V_372;
V_339 . V_475 = V_27 -> V_253 . V_459 ;
goto V_487;
}
goto V_372;
break;
default:
goto V_372;
break;
}
V_487:
if ( V_339 . V_340 . V_334 == V_472 ) {
if ( V_351 == V_464 )
V_339 . V_348 . V_369 = V_6 ;
}
if ( V_339 . V_340 . V_334 == V_344 ||
V_339 . V_340 . V_334 == V_345 ||
V_339 . V_340 . V_334 == V_346 ) {
V_465 = (struct V_411 * ) V_339 . V_475 ;
if ( V_348 > V_465 -> V_419 / sizeof( T_1 ) - 1 )
goto V_372;
V_467 = V_465 -> V_469 [ V_6 ] . V_470 ;
V_467 += V_348 ;
if ( V_339 . V_340 . V_334 == V_344 )
* V_467 = V_370 ;
if ( V_339 . V_340 . V_334 == V_345 )
* V_467 |= V_370 ;
if ( V_339 . V_340 . V_334 == V_346 )
* V_467 &= ~ V_370 ;
}
return V_284 ;
V_372:
memset ( & V_339 , 0 , sizeof( V_339 ) ) ;
return - V_325 ;
}
static int
F_99 ( struct V_26 * V_27 , char * V_352 ,
int V_7 , T_1 V_492 )
{
if ( ! V_352 )
return 0 ;
switch ( V_492 ) {
case V_493 :
V_7 += snprintf ( V_352 + V_7 , V_494 - V_7 ,
L_190 ,
F_17 ( V_27 -> V_253 . V_495 ) ) ;
break;
case V_496 :
V_7 += snprintf ( V_352 + V_7 , V_494 - V_7 ,
L_191 ,
F_17 ( V_27 -> V_253 . V_497 ) ) ;
break;
case V_498 :
V_7 += snprintf ( V_352 + V_7 , V_494 - V_7 ,
L_192 ,
F_17 ( V_27 -> V_253 . V_499 ) ) ;
break;
case V_500 :
V_7 += snprintf ( V_352 + V_7 , V_494 - V_7 ,
L_193 ,
F_17 ( V_27 -> V_253 . V_501 ) ) ;
break;
default:
break;
}
return V_7 ;
}
static T_3
F_100 ( struct V_267 * V_267 , char T_4 * V_3 , T_5 V_284 ,
T_6 * V_285 )
{
struct V_269 * V_270 = V_267 -> V_274 ;
struct V_26 * V_27 = (struct V_26 * ) V_270 -> V_268 ;
T_1 V_502 , V_5 ;
char * V_352 ;
int V_7 = 0 ;
V_270 -> V_337 = V_359 ;
if ( ! V_270 -> V_12 )
V_270 -> V_12 = F_2 ( V_494 , V_14 ) ;
if ( ! V_270 -> V_12 )
return 0 ;
V_352 = V_270 -> V_12 ;
if ( * V_285 )
return 0 ;
if ( V_339 . V_340 . V_334 == V_503 )
V_502 = V_339 . V_340 . V_336 [ V_504 ] ;
else
return 0 ;
if ( V_502 == V_505 )
for ( V_5 = 1 ; V_5 <= V_506 ; V_5 ++ )
V_7 = F_99 ( V_27 ,
V_352 , V_7 , V_5 ) ;
else
V_7 = F_99 ( V_27 ,
V_352 , V_7 , V_502 ) ;
return F_47 ( V_3 , V_284 , V_285 , V_352 , V_7 ) ;
}
static T_3
F_101 ( struct V_267 * V_267 , const char T_4 * V_3 ,
T_5 V_284 , T_6 * V_285 )
{
struct V_269 * V_270 = V_267 -> V_274 ;
struct V_26 * V_27 = (struct V_26 * ) V_270 -> V_268 ;
T_1 V_502 , V_370 , V_507 = 0 ;
void T_8 * V_508 ;
int V_271 ;
V_270 -> V_337 = V_338 ;
V_271 = F_69 ( V_3 , V_284 , & V_339 . V_340 ) ;
if ( V_271 < 0 )
return V_271 ;
V_502 = V_339 . V_340 . V_336 [ V_504 ] ;
V_370 = V_339 . V_340 . V_336 [ V_509 ] ;
if ( V_339 . V_340 . V_334 == V_510 ||
V_339 . V_340 . V_334 == V_511 ||
V_339 . V_340 . V_334 == V_512 ) {
if ( V_271 != V_513 )
goto V_372;
if ( V_502 > V_506 )
goto V_372;
} else if ( V_339 . V_340 . V_334 == V_503 ) {
if ( V_271 != V_514 )
goto V_372;
if ( ( V_502 > V_506 ) &&
( V_502 != V_505 ) )
goto V_372;
} else
goto V_372;
if ( V_339 . V_340 . V_334 == V_510 ||
V_339 . V_340 . V_334 == V_511 ||
V_339 . V_340 . V_334 == V_512 ) {
switch ( V_502 ) {
case V_493 :
V_508 = V_27 -> V_253 . V_495 ;
break;
case V_496 :
V_508 = V_27 -> V_253 . V_497 ;
break;
case V_498 :
V_508 = V_27 -> V_253 . V_499 ;
break;
case V_500 :
V_508 = V_27 -> V_253 . V_501 ;
break;
default:
goto V_372;
}
if ( V_339 . V_340 . V_334 == V_510 )
V_507 = V_370 ;
if ( V_339 . V_340 . V_334 == V_511 ) {
V_507 = F_17 ( V_508 ) ;
V_507 |= V_370 ;
}
if ( V_339 . V_340 . V_334 == V_512 ) {
V_507 = F_17 ( V_508 ) ;
V_507 &= ~ V_370 ;
}
F_87 ( V_507 , V_508 ) ;
F_17 ( V_508 ) ;
}
return V_284 ;
V_372:
memset ( & V_339 , 0 , sizeof( V_339 ) ) ;
return - V_325 ;
}
static int
F_102 ( struct V_26 * V_27 , char * V_352 ,
int V_7 , T_1 V_515 )
{
if ( ! V_352 )
return 0 ;
switch ( V_515 ) {
case V_516 :
V_7 += snprintf ( V_352 + V_7 , V_517 - V_7 ,
L_194 ,
F_17 ( V_27 -> V_253 . V_391 +
V_518 ) ) ;
break;
case V_519 :
V_7 += snprintf ( V_352 + V_7 , V_517 - V_7 ,
L_195 ,
F_17 ( V_27 -> V_253 . V_391 +
V_520 ) ) ;
break;
case V_521 :
V_7 += snprintf ( V_352 + V_7 , V_517 - V_7 ,
L_196 ,
F_17 ( V_27 -> V_253 . V_391 +
V_522 ) ) ;
break;
case V_523 :
V_7 += snprintf ( V_352 + V_7 , V_517 - V_7 ,
L_197 ,
F_17 ( V_27 -> V_253 . V_391 +
V_524 ) ) ;
break;
case V_525 :
V_7 += snprintf ( V_352 + V_7 , V_517 - V_7 ,
L_198 ,
F_17 ( V_27 -> V_253 . V_391 +
V_526 ) ) ;
break;
case V_527 :
V_7 += snprintf ( V_352 + V_7 , V_517 - V_7 ,
L_199 ,
F_17 ( V_27 -> V_253 . V_391 +
V_528 ) ) ;
break;
default:
break;
}
return V_7 ;
}
static T_3
F_103 ( struct V_267 * V_267 , char T_4 * V_3 , T_5 V_284 ,
T_6 * V_285 )
{
struct V_269 * V_270 = V_267 -> V_274 ;
struct V_26 * V_27 = (struct V_26 * ) V_270 -> V_268 ;
T_1 V_529 , V_5 ;
char * V_352 ;
int V_7 = 0 ;
V_270 -> V_337 = V_359 ;
if ( ! V_270 -> V_12 )
V_270 -> V_12 = F_2 ( V_517 , V_14 ) ;
if ( ! V_270 -> V_12 )
return 0 ;
V_352 = V_270 -> V_12 ;
if ( * V_285 )
return 0 ;
if ( V_339 . V_340 . V_334 == V_530 )
V_529 = V_339 . V_340 . V_336 [ V_531 ] ;
else
return 0 ;
if ( V_529 == V_532 )
for ( V_5 = 1 ; V_5 <= V_533 ; V_5 ++ )
V_7 = F_102 ( V_27 ,
V_352 , V_7 , V_5 ) ;
else
V_7 = F_102 ( V_27 ,
V_352 , V_7 , V_529 ) ;
return F_47 ( V_3 , V_284 , V_285 , V_352 , V_7 ) ;
}
static T_3
F_104 ( struct V_267 * V_267 , const char T_4 * V_3 ,
T_5 V_284 , T_6 * V_285 )
{
struct V_269 * V_270 = V_267 -> V_274 ;
struct V_26 * V_27 = (struct V_26 * ) V_270 -> V_268 ;
T_1 V_529 , V_370 , V_507 = 0 ;
void T_8 * V_534 ;
int V_271 ;
V_270 -> V_337 = V_338 ;
V_271 = F_69 ( V_3 , V_284 , & V_339 . V_340 ) ;
if ( V_271 < 0 )
return V_271 ;
V_529 = V_339 . V_340 . V_336 [ V_531 ] ;
V_370 = V_339 . V_340 . V_336 [ V_535 ] ;
if ( V_339 . V_340 . V_334 == V_536 ||
V_339 . V_340 . V_334 == V_537 ||
V_339 . V_340 . V_334 == V_538 ) {
if ( V_271 != V_539 )
goto V_372;
if ( V_529 > V_533 )
goto V_372;
} else if ( V_339 . V_340 . V_334 == V_530 ) {
if ( V_271 != V_540 )
goto V_372;
if ( ( V_529 > V_533 ) &&
( V_529 != V_532 ) )
goto V_372;
} else
goto V_372;
if ( V_339 . V_340 . V_334 == V_536 ||
V_339 . V_340 . V_334 == V_537 ||
V_339 . V_340 . V_334 == V_538 ) {
switch ( V_529 ) {
case V_516 :
V_534 = V_27 -> V_253 . V_391 +
V_518 ;
break;
case V_519 :
V_534 = V_27 -> V_253 . V_391 +
V_520 ;
break;
case V_521 :
V_534 = V_27 -> V_253 . V_391 +
V_522 ;
break;
case V_523 :
V_534 = V_27 -> V_253 . V_391 +
V_524 ;
break;
case V_525 :
V_534 = V_27 -> V_253 . V_391 +
V_526 ;
break;
case V_527 :
V_534 = V_27 -> V_253 . V_391 +
V_528 ;
break;
default:
goto V_372;
}
if ( V_339 . V_340 . V_334 == V_536 )
V_507 = V_370 ;
if ( V_339 . V_340 . V_334 == V_537 ) {
V_507 = F_17 ( V_534 ) ;
V_507 |= V_370 ;
}
if ( V_339 . V_340 . V_334 == V_538 ) {
V_507 = F_17 ( V_534 ) ;
V_507 &= ~ V_370 ;
}
F_87 ( V_507 , V_534 ) ;
F_17 ( V_534 ) ;
}
return V_284 ;
V_372:
memset ( & V_339 , 0 , sizeof( V_339 ) ) ;
return - V_325 ;
}
static int
F_105 ( struct V_26 * V_27 , char * V_352 )
{
T_1 V_541 , V_542 , V_543 , V_544 ;
int V_7 = 0 ;
V_544 = V_339 . V_340 . V_336 [ V_545 ] ;
V_541 = V_339 . V_340 . V_336 [ V_546 ] ;
V_542 = V_339 . V_340 . V_336 [ V_547 ] ;
V_543 = V_339 . V_340 . V_336 [ V_548 ] ;
V_7 += snprintf ( V_352 + V_7 , V_549 - V_7 ,
L_200 , V_541 ) ;
V_7 += snprintf ( V_352 + V_7 , V_549 - V_7 ,
L_201 , V_542 ) ;
V_7 += snprintf ( V_352 + V_7 , V_549 - V_7 ,
L_202 , V_543 ) ;
V_7 += snprintf ( V_352 + V_7 , V_549 - V_7 ,
L_203 , V_544 ) ;
return V_7 ;
}
static T_3
F_106 ( struct V_267 * V_267 , char T_4 * V_3 , T_5 V_284 ,
T_6 * V_285 )
{
struct V_269 * V_270 = V_267 -> V_274 ;
struct V_26 * V_27 = (struct V_26 * ) V_270 -> V_268 ;
char * V_352 ;
int V_7 = 0 ;
V_270 -> V_337 = V_359 ;
if ( ! V_270 -> V_12 )
V_270 -> V_12 = F_2 ( V_549 , V_14 ) ;
if ( ! V_270 -> V_12 )
return 0 ;
V_352 = V_270 -> V_12 ;
if ( * V_285 )
return 0 ;
if ( ( V_339 . V_340 . V_334 != V_550 ) &&
( V_339 . V_340 . V_334 != V_551 ) )
return 0 ;
V_7 = F_105 ( V_27 , V_352 ) ;
return F_47 ( V_3 , V_284 , V_285 , V_352 , V_7 ) ;
}
static T_3
F_107 ( struct V_267 * V_267 , const char T_4 * V_3 ,
T_5 V_284 , T_6 * V_285 )
{
struct V_269 * V_270 = V_267 -> V_274 ;
T_1 V_541 , V_542 , V_543 , V_544 ;
int V_271 ;
V_270 -> V_337 = V_338 ;
V_271 = F_69 ( V_3 , V_284 , & V_339 . V_340 ) ;
if ( V_271 < 0 )
return V_271 ;
V_544 = V_339 . V_340 . V_336 [ V_545 ] ;
V_541 = V_339 . V_340 . V_336 [ V_546 ] ;
V_542 = V_339 . V_340 . V_336 [ V_547 ] ;
V_543 = V_339 . V_340 . V_336 [ V_548 ] ;
if ( V_339 . V_340 . V_334 == V_550 ) {
if ( ! ( V_541 & V_552 ) )
goto V_372;
if ( ( V_541 & ~ V_552 ) &&
( V_541 != V_553 ) )
goto V_372;
if ( V_543 > sizeof( V_91 ) )
goto V_372;
} else if ( V_339 . V_340 . V_334 == V_551 ) {
if ( ! ( V_541 & V_554 ) )
goto V_372;
if ( ( V_541 & ~ V_554 ) &&
( V_541 != V_553 ) )
goto V_372;
if ( V_543 > ( V_555 ) / 4 )
goto V_372;
if ( V_544 != 0x9b )
goto V_372;
} else
goto V_372;
if ( V_543 == 0 )
goto V_372;
if ( V_271 != V_556 )
goto V_372;
if ( V_544 & ~ 0xff )
goto V_372;
if ( V_542 == 0 )
goto V_557;
return V_284 ;
V_557:
memset ( & V_339 , 0 , sizeof( V_339 ) ) ;
return V_284 ;
V_372:
memset ( & V_339 , 0 , sizeof( V_339 ) ) ;
return - V_325 ;
}
static int
F_108 ( struct V_26 * V_27 , char * V_352 , int V_7 )
{
T_2 V_558 , V_559 ;
V_7 += snprintf ( V_352 + V_7 , V_560 - V_7 ,
L_204 ) ;
V_7 += snprintf ( V_352 + V_7 , V_560 - V_7 ,
L_205 ) ;
F_109 ( V_27 , V_561 ,
& V_558 , & V_559 ) ;
V_7 += snprintf ( V_352 + V_7 , V_560 - V_7 ,
L_206 , V_558 , V_559 ) ;
V_7 += snprintf ( V_352 + V_7 , V_560 - V_7 ,
L_207 ) ;
F_109 ( V_27 , V_562 ,
& V_558 , & V_559 ) ;
V_7 += snprintf ( V_352 + V_7 , V_560 - V_7 ,
L_206 , V_558 , V_559 ) ;
V_7 += snprintf ( V_352 + V_7 , V_560 - V_7 ,
L_208 ) ;
F_109 ( V_27 , V_563 ,
& V_558 , & V_559 ) ;
V_7 += snprintf ( V_352 + V_7 , V_560 - V_7 ,
L_206 , V_558 , V_559 ) ;
V_7 += snprintf ( V_352 + V_7 , V_560 - V_7 ,
L_209 ) ;
F_109 ( V_27 , V_564 ,
& V_558 , & V_559 ) ;
V_7 += snprintf ( V_352 + V_7 , V_560 - V_7 ,
L_206 , V_558 , V_559 ) ;
return V_7 ;
}
static int
F_110 ( struct V_26 * V_27 , char * V_352 , int V_7 )
{
T_2 V_558 , V_559 ;
int V_271 ;
V_7 += snprintf ( V_352 + V_7 , V_560 - V_7 ,
L_210 ) ;
V_7 += snprintf ( V_352 + V_7 , V_560 - V_7 ,
L_211 ) ;
V_271 = F_111 ( V_27 , V_561 ,
& V_558 , & V_559 ) ;
if ( ! V_271 )
V_7 += snprintf ( V_352 + V_7 , V_560 - V_7 ,
L_212 ,
V_27 -> V_565 , V_558 , V_559 ) ;
else
V_7 += snprintf ( V_352 + V_7 , V_560 - V_7 ,
L_213 ) ;
V_7 += snprintf ( V_352 + V_7 , V_560 - V_7 ,
L_214 ) ;
V_271 = F_111 ( V_27 , V_562 ,
& V_558 , & V_559 ) ;
if ( ! V_271 )
V_7 += snprintf ( V_352 + V_7 , V_560 - V_7 ,
L_212 ,
V_27 -> V_565 , V_558 , V_559 ) ;
else
V_7 += snprintf ( V_352 + V_7 , V_560 - V_7 ,
L_213 ) ;
V_7 += snprintf ( V_352 + V_7 , V_560 - V_7 ,
L_215 ) ;
V_271 = F_111 ( V_27 , V_563 ,
& V_558 , & V_559 ) ;
if ( ! V_271 )
V_7 += snprintf ( V_352 + V_7 , V_560 - V_7 ,
L_212 ,
V_27 -> V_565 , V_558 , V_559 ) ;
else
V_7 += snprintf ( V_352 + V_7 , V_560 - V_7 ,
L_213 ) ;
V_7 += snprintf ( V_352 + V_7 , V_560 - V_7 ,
L_216 ) ;
V_271 = F_111 ( V_27 , V_564 ,
& V_558 , & V_559 ) ;
if ( ! V_271 )
V_7 += snprintf ( V_352 + V_7 , V_560 - V_7 ,
L_212 ,
V_27 -> V_565 , V_558 , V_559 ) ;
else
V_7 += snprintf ( V_352 + V_7 , V_560 - V_7 ,
L_213 ) ;
return V_7 ;
}
static int
F_112 ( struct V_26 * V_27 , char * V_352 , int V_7 )
{
struct V_566 * V_567 ;
int V_6 ;
V_7 += snprintf ( V_352 + V_7 , V_560 - V_7 ,
L_217 ) ;
V_7 += snprintf ( V_352 + V_7 , V_560 - V_7 ,
L_218 ) ;
V_6 = 0 ;
F_10 (rsrc_blks, &phba->lpfc_vpi_blk_list, list) {
V_7 += snprintf ( V_352 + V_7 , V_560 - V_7 ,
L_219 ,
V_6 , V_567 -> V_568 ,
V_567 -> V_569 ) ;
V_6 ++ ;
}
V_7 += snprintf ( V_352 + V_7 , V_560 - V_7 ,
L_220 ) ;
V_6 = 0 ;
F_10 (rsrc_blks, &phba->sli4_hba.lpfc_vfi_blk_list,
list) {
V_7 += snprintf ( V_352 + V_7 , V_560 - V_7 ,
L_219 ,
V_6 , V_567 -> V_568 ,
V_567 -> V_569 ) ;
V_6 ++ ;
}
V_7 += snprintf ( V_352 + V_7 , V_560 - V_7 ,
L_221 ) ;
V_6 = 0 ;
F_10 (rsrc_blks, &phba->sli4_hba.lpfc_rpi_blk_list,
list) {
V_7 += snprintf ( V_352 + V_7 , V_560 - V_7 ,
L_219 ,
V_6 , V_567 -> V_568 ,
V_567 -> V_569 ) ;
V_6 ++ ;
}
V_7 += snprintf ( V_352 + V_7 , V_560 - V_7 ,
L_222 ) ;
V_6 = 0 ;
F_10 (rsrc_blks, &phba->sli4_hba.lpfc_xri_blk_list,
list) {
V_7 += snprintf ( V_352 + V_7 , V_560 - V_7 ,
L_219 ,
V_6 , V_567 -> V_568 ,
V_567 -> V_569 ) ;
V_6 ++ ;
}
return V_7 ;
}
static T_3
F_113 ( struct V_267 * V_267 , const char T_4 * V_3 ,
T_5 V_284 , T_6 * V_285 )
{
struct V_269 * V_270 = V_267 -> V_274 ;
T_1 V_570 ;
int V_271 ;
V_270 -> V_337 = V_338 ;
V_271 = F_69 ( V_3 , V_284 , & V_339 . V_340 ) ;
if ( V_271 < 0 )
return V_271 ;
V_570 = V_339 . V_340 . V_336 [ V_571 ] ;
if ( V_339 . V_340 . V_334 != V_572 )
goto V_372;
if ( V_271 != V_573 )
goto V_372;
if ( ! ( V_570 & V_574 ) )
goto V_372;
return V_284 ;
V_372:
memset ( & V_339 , 0 , sizeof( V_339 ) ) ;
return - V_325 ;
}
static T_3
F_114 ( struct V_267 * V_267 , char T_4 * V_3 , T_5 V_284 ,
T_6 * V_285 )
{
struct V_269 * V_270 = V_267 -> V_274 ;
struct V_26 * V_27 = (struct V_26 * ) V_270 -> V_268 ;
char * V_352 ;
T_1 V_570 ;
int V_7 = 0 ;
V_270 -> V_337 = V_359 ;
if ( ! V_270 -> V_12 )
V_270 -> V_12 = F_2 ( V_560 , V_14 ) ;
if ( ! V_270 -> V_12 )
return 0 ;
V_352 = V_270 -> V_12 ;
if ( * V_285 )
return 0 ;
if ( V_339 . V_340 . V_334 != V_572 )
return 0 ;
V_570 = V_339 . V_340 . V_336 [ V_571 ] ;
if ( V_570 & V_575 )
V_7 = F_108 ( V_27 , V_352 , V_7 ) ;
if ( V_570 & V_576 )
V_7 = F_110 ( V_27 , V_352 , V_7 ) ;
if ( V_570 & V_577 )
V_7 = F_112 ( V_27 , V_352 , V_7 ) ;
return F_47 ( V_3 , V_284 , V_285 , V_352 , V_7 ) ;
}
void
F_115 ( struct V_26 * V_27 , enum V_578 V_579 ,
enum V_580 V_581 , enum V_582 V_583 ,
enum V_584 V_585 ,
struct V_44 * V_586 , T_1 V_587 )
{
#ifdef F_28
T_1 * V_544 , * V_541 , * V_542 , * V_543 ;
char V_588 [ V_589 ] ;
int V_7 = 0 ;
T_1 V_590 = 0 ;
T_1 * V_591 ;
T_1 V_5 ;
if ( V_339 . V_340 . V_334 != V_551 )
return;
V_544 = & V_339 . V_340 . V_336 [ V_545 ] ;
V_541 = & V_339 . V_340 . V_336 [ V_546 ] ;
V_542 = & V_339 . V_340 . V_336 [ V_547 ] ;
V_543 = & V_339 . V_340 . V_336 [ V_548 ] ;
if ( ! ( * V_541 & V_553 ) ||
( * V_542 == 0 ) ||
( * V_543 == 0 ) )
return;
if ( * V_544 != 0x9B )
return;
if ( ( V_581 == V_592 ) && ( V_583 == V_593 ) ) {
if ( * V_541 & V_594 ) {
V_590 |= V_594 ;
F_39 ( L_223
L_224 ,
V_585 , V_579 , V_587 ) ;
}
}
if ( ( V_581 == V_592 ) && ( V_583 == V_595 ) ) {
if ( * V_541 & V_596 ) {
V_590 |= V_596 ;
F_39 ( L_225
L_226 ,
V_585 , V_579 , V_587 ) ;
}
}
if ( ( V_581 == V_597 ) && ( V_583 == V_593 ) ) {
if ( * V_541 & V_598 ) {
V_590 |= V_598 ;
F_39 ( L_227
L_224 ,
V_585 , V_579 , V_587 ) ;
}
}
if ( ( V_581 == V_597 ) && ( V_583 == V_595 ) ) {
if ( * V_541 & V_599 ) {
V_590 |= V_599 ;
F_39 ( L_228
L_226 ,
V_585 , V_579 , V_587 ) ;
}
}
if ( V_590 ) {
V_591 = ( T_1 * ) V_586 -> V_72 ;
for ( V_5 = 0 ; V_5 < * V_543 ; V_5 ++ ) {
if ( ! ( V_5 % 8 ) ) {
if ( V_5 != 0 )
F_39 ( L_125 , V_588 ) ;
V_7 = 0 ;
V_7 += snprintf ( V_588 + V_7 ,
V_589 - V_7 ,
L_229 , V_5 ) ;
}
V_7 += snprintf ( V_588 + V_7 , V_589 - V_7 ,
L_155 , ( T_1 ) * V_591 ) ;
V_591 ++ ;
}
if ( ( V_5 - 1 ) % 8 )
F_39 ( L_125 , V_588 ) ;
( * V_542 ) -- ;
}
if ( * V_542 == 0 )
memset ( & V_339 , 0 , sizeof( V_339 ) ) ;
return;
#endif
}
void
F_116 ( struct V_26 * V_27 , V_91 * V_600 )
{
#ifdef F_28
T_1 * V_541 , * V_542 , * V_543 , * V_544 ;
char V_588 [ V_589 ] ;
int V_7 = 0 ;
T_1 * V_591 ;
T_7 * V_601 ;
T_1 V_5 , V_31 ;
if ( V_339 . V_340 . V_334 != V_550 )
return;
V_544 = & V_339 . V_340 . V_336 [ V_545 ] ;
V_541 = & V_339 . V_340 . V_336 [ V_546 ] ;
V_542 = & V_339 . V_340 . V_336 [ V_547 ] ;
V_543 = & V_339 . V_340 . V_336 [ V_548 ] ;
if ( ! ( * V_541 & V_552 ) ||
( * V_542 == 0 ) ||
( * V_543 == 0 ) )
return;
if ( ( * V_544 != V_602 ) &&
( * V_544 != V_600 -> V_603 ) )
return;
if ( * V_541 & V_604 ) {
F_39 ( L_230 ,
V_600 -> V_603 ) ;
V_591 = ( T_1 * ) V_600 ;
for ( V_5 = 0 ; V_5 < * V_543 ; V_5 ++ ) {
if ( ! ( V_5 % 8 ) ) {
if ( V_5 != 0 )
F_39 ( L_125 , V_588 ) ;
V_7 = 0 ;
memset ( V_588 , 0 , V_589 ) ;
V_7 += snprintf ( V_588 + V_7 ,
V_589 - V_7 ,
L_229 , V_5 ) ;
}
V_7 += snprintf ( V_588 + V_7 , V_589 - V_7 ,
L_155 ,
( ( T_1 ) * V_591 ) & 0xffffffff ) ;
V_591 ++ ;
}
if ( ( V_5 - 1 ) % 8 )
F_39 ( L_125 , V_588 ) ;
F_39 ( L_44 ) ;
}
if ( * V_541 & V_605 ) {
F_39 ( L_231 ,
V_600 -> V_603 ) ;
V_601 = ( T_7 * ) V_600 ;
for ( V_5 = 0 ; V_5 < * V_543 ; V_5 ++ ) {
if ( ! ( V_5 % 8 ) ) {
if ( V_5 != 0 )
F_39 ( L_125 , V_588 ) ;
V_7 = 0 ;
memset ( V_588 , 0 , V_589 ) ;
V_7 += snprintf ( V_588 + V_7 ,
V_589 - V_7 ,
L_229 , V_5 ) ;
}
for ( V_31 = 0 ; V_31 < 4 ; V_31 ++ ) {
V_7 += snprintf ( V_588 + V_7 ,
V_589 - V_7 ,
L_232 ,
( ( T_7 ) * V_601 ) & 0xff ) ;
V_601 ++ ;
}
V_7 += snprintf ( V_588 + V_7 ,
V_589 - V_7 , L_233 ) ;
}
if ( ( V_5 - 1 ) % 8 )
F_39 ( L_125 , V_588 ) ;
F_39 ( L_44 ) ;
}
( * V_542 ) -- ;
if ( * V_542 == 0 )
memset ( & V_339 , 0 , sizeof( V_339 ) ) ;
return;
#endif
}
inline void
F_117 ( struct V_1 * V_2 )
{
#ifdef F_28
struct V_26 * V_27 = V_2 -> V_27 ;
char V_606 [ 64 ] ;
T_1 V_607 , V_5 ;
bool V_608 = false ;
if ( ! V_15 )
return;
if ( ! V_609 ) {
V_609 = F_118 ( L_234 , NULL ) ;
F_61 ( & V_610 , 0 ) ;
if ( ! V_609 ) {
F_119 ( V_2 , V_313 , V_314 ,
L_235 ) ;
goto V_611;
}
}
if ( ! V_21 )
V_21 = V_265 ;
snprintf ( V_606 , sizeof( V_606 ) , L_236 , V_27 -> V_565 ) ;
if ( ! V_27 -> V_612 ) {
V_608 = true ;
V_27 -> V_612 =
F_118 ( V_606 , V_609 ) ;
if ( ! V_27 -> V_612 ) {
F_119 ( V_2 , V_313 , V_314 ,
L_237 ) ;
goto V_611;
}
F_120 ( & V_610 ) ;
F_61 ( & V_27 -> V_613 , 0 ) ;
snprintf ( V_606 , sizeof( V_606 ) , L_238 ) ;
V_27 -> V_614 =
F_121 ( V_606 , V_615 | V_616 | V_617 ,
V_27 -> V_612 ,
V_27 , & V_618 ) ;
if ( ! V_27 -> V_614 ) {
F_119 ( V_2 , V_313 , V_314 ,
L_239 ) ;
goto V_611;
}
if ( V_27 -> V_48 < V_619 ) {
snprintf ( V_606 , sizeof( V_606 ) , L_240 ) ;
V_27 -> V_620 =
F_121 ( V_606 ,
V_615 | V_616 | V_617 ,
V_27 -> V_612 ,
V_27 , & V_621 ) ;
if ( ! V_27 -> V_620 ) {
F_119 ( V_2 , V_313 , V_314 ,
L_241
L_242 ) ;
goto V_611;
}
} else
V_27 -> V_620 = NULL ;
if ( V_27 -> V_48 < V_619 ) {
snprintf ( V_606 , sizeof( V_606 ) , L_243 ) ;
V_27 -> V_622 =
F_121 ( V_606 ,
V_615 | V_616 | V_617 ,
V_27 -> V_612 ,
V_27 , & V_623 ) ;
if ( ! V_27 -> V_622 ) {
F_119 ( V_2 , V_313 , V_314 ,
L_244
L_245 ) ;
goto V_611;
}
} else
V_27 -> V_622 = NULL ;
snprintf ( V_606 , sizeof( V_606 ) , L_246 ) ;
V_27 -> V_624 =
F_121 ( V_606 , V_615 | V_616 | V_617 ,
V_27 -> V_612 ,
V_27 , & V_625 ) ;
if ( ! V_27 -> V_624 ) {
F_119 ( V_2 , V_313 , V_314 ,
L_247 ) ;
goto V_611;
}
snprintf ( V_606 , sizeof( V_606 ) , L_248 ) ;
V_27 -> V_626 =
F_121 ( V_606 , V_615 | V_616 | V_617 ,
V_27 -> V_612 ,
V_27 , & V_627 ) ;
if ( ! V_27 -> V_626 ) {
F_119 ( V_2 , V_313 , V_314 ,
L_249 ) ;
goto V_611;
}
snprintf ( V_606 , sizeof( V_606 ) , L_250 ) ;
V_27 -> V_310 =
F_121 ( V_606 , V_615 | V_616 | V_617 ,
V_27 -> V_612 ,
V_27 , & V_628 ) ;
if ( ! V_27 -> V_310 ) {
F_119 ( V_2 , V_313 , V_314 ,
L_251 ) ;
goto V_611;
}
V_27 -> V_311 = V_629 ;
snprintf ( V_606 , sizeof( V_606 ) , L_252 ) ;
V_27 -> V_305 =
F_121 ( V_606 , V_615 | V_616 | V_617 ,
V_27 -> V_612 ,
V_27 , & V_628 ) ;
if ( ! V_27 -> V_305 ) {
F_119 ( V_2 , V_313 , V_314 ,
L_253 ) ;
goto V_611;
}
snprintf ( V_606 , sizeof( V_606 ) , L_254 ) ;
V_27 -> V_307 =
F_121 ( V_606 , V_615 | V_616 | V_617 ,
V_27 -> V_612 ,
V_27 , & V_628 ) ;
if ( ! V_27 -> V_307 ) {
F_119 ( V_2 , V_313 , V_314 ,
L_255 ) ;
goto V_611;
}
snprintf ( V_606 , sizeof( V_606 ) , L_256 ) ;
V_27 -> V_293 =
F_121 ( V_606 , V_615 | V_616 | V_617 ,
V_27 -> V_612 ,
V_27 , & V_628 ) ;
if ( ! V_27 -> V_293 ) {
F_119 ( V_2 , V_313 , V_314 ,
L_257 ) ;
goto V_611;
}
snprintf ( V_606 , sizeof( V_606 ) , L_258 ) ;
V_27 -> V_295 =
F_121 ( V_606 , V_615 | V_616 | V_617 ,
V_27 -> V_612 ,
V_27 , & V_628 ) ;
if ( ! V_27 -> V_295 ) {
F_119 ( V_2 , V_313 , V_314 ,
L_259 ) ;
goto V_611;
}
snprintf ( V_606 , sizeof( V_606 ) , L_260 ) ;
V_27 -> V_297 =
F_121 ( V_606 , V_615 | V_616 | V_617 ,
V_27 -> V_612 ,
V_27 , & V_628 ) ;
if ( ! V_27 -> V_297 ) {
F_119 ( V_2 , V_313 , V_314 ,
L_261 ) ;
goto V_611;
}
snprintf ( V_606 , sizeof( V_606 ) , L_262 ) ;
V_27 -> V_299 =
F_121 ( V_606 , V_615 | V_616 | V_617 ,
V_27 -> V_612 ,
V_27 , & V_628 ) ;
if ( ! V_27 -> V_299 ) {
F_119 ( V_2 , V_313 , V_314 ,
L_263 ) ;
goto V_611;
}
snprintf ( V_606 , sizeof( V_606 ) , L_264 ) ;
V_27 -> V_301 =
F_121 ( V_606 , V_615 | V_616 | V_617 ,
V_27 -> V_612 ,
V_27 , & V_628 ) ;
if ( ! V_27 -> V_301 ) {
F_119 ( V_2 , V_313 , V_314 ,
L_265 ) ;
goto V_611;
}
snprintf ( V_606 , sizeof( V_606 ) , L_266 ) ;
V_27 -> V_303 =
F_121 ( V_606 , V_615 | V_616 | V_617 ,
V_27 -> V_612 ,
V_27 , & V_628 ) ;
if ( ! V_27 -> V_303 ) {
F_119 ( V_2 , V_313 , V_314 ,
L_267 ) ;
goto V_611;
}
if ( V_29 ) {
V_607 = V_29 - 1 ;
if ( V_607 & V_29 ) {
V_607 = V_29 ;
V_5 = 0 ;
while ( V_607 > 1 ) {
V_607 = V_607 >> 1 ;
V_5 ++ ;
}
V_29 = ( 1 << V_5 ) ;
F_39 ( L_268
L_269 , V_17 ) ;
}
}
snprintf ( V_606 , sizeof( V_606 ) , L_270 ) ;
V_27 -> V_630 =
F_121 ( V_606 , V_615 | V_616 | V_617 ,
V_27 -> V_612 ,
V_27 , & V_631 ) ;
if ( ! V_27 -> V_630 ) {
F_119 ( V_2 , V_313 , V_314 ,
L_271
L_272 ) ;
goto V_611;
}
if ( ! V_27 -> V_30 ) {
V_27 -> V_30 = F_2 (
( sizeof( struct V_10 ) *
V_29 ) ,
V_14 ) ;
if ( ! V_27 -> V_30 ) {
F_119 ( V_2 , V_313 , V_314 ,
L_273
L_274 ) ;
goto V_611;
}
F_61 ( & V_27 -> V_28 , 0 ) ;
memset ( V_27 -> V_30 , 0 ,
( sizeof( struct V_10 ) *
V_29 ) ) ;
}
snprintf ( V_606 , sizeof( V_606 ) , L_275 ) ;
V_27 -> V_632 =
F_121 ( V_606 , 0644 ,
V_27 -> V_612 ,
V_27 , & V_633 ) ;
if ( ! V_27 -> V_632 ) {
F_119 ( V_2 , V_313 , V_314 ,
L_276 ) ;
goto V_611;
}
F_61 ( & V_27 -> V_241 , 0 ) ;
if ( V_634 ) {
V_607 = V_634 - 1 ;
if ( V_607 & V_17 ) {
V_607 = V_634 ;
V_5 = 0 ;
while ( V_607 > 1 ) {
V_607 = V_607 >> 1 ;
V_5 ++ ;
}
V_634 = ( 1 << V_5 ) ;
F_46 ( V_27 , V_313 , V_314 ,
L_277
L_278 ,
V_634 ) ;
}
V_27 -> V_242 = V_634 ;
V_27 -> V_244 = F_2 (
( sizeof( struct V_237 ) *
V_27 -> V_242 ) , V_14 ) ;
if ( ! V_27 -> V_244 ) {
F_46 ( V_27 , V_313 , V_314 ,
L_279
L_148 ) ;
goto V_635;
}
memset ( V_27 -> V_244 , 0 ,
( sizeof( struct V_237 ) *
V_27 -> V_242 ) ) ;
V_27 -> V_240 = 1 ;
V_27 -> V_243 = 0 ;
V_27 -> V_244 = NULL ;
} else {
V_635:
V_27 -> V_242 = 0 ;
V_27 -> V_240 = 0 ;
V_27 -> V_243 = 0 ;
V_27 -> V_244 = NULL ;
}
}
snprintf ( V_606 , sizeof( V_606 ) , L_280 , V_2 -> V_636 ) ;
if ( ! V_2 -> V_637 ) {
V_2 -> V_637 =
F_118 ( V_606 , V_27 -> V_612 ) ;
if ( ! V_2 -> V_637 ) {
F_119 ( V_2 , V_313 , V_314 ,
L_281 ) ;
goto V_611;
}
F_120 ( & V_27 -> V_613 ) ;
}
if ( V_17 ) {
V_607 = V_17 - 1 ;
if ( V_607 & V_17 ) {
V_607 = V_17 ;
V_5 = 0 ;
while ( V_607 > 1 ) {
V_607 = V_607 >> 1 ;
V_5 ++ ;
}
V_17 = ( 1 << V_5 ) ;
F_39 ( L_282 ,
V_17 ) ;
}
}
V_2 -> V_18 = F_122 (
( sizeof( struct V_10 ) * V_17 ) ,
V_14 ) ;
if ( ! V_2 -> V_18 ) {
F_119 ( V_2 , V_313 , V_314 ,
L_283
L_284 ) ;
goto V_611;
}
F_61 ( & V_2 -> V_16 , 0 ) ;
snprintf ( V_606 , sizeof( V_606 ) , L_285 ) ;
V_2 -> V_638 =
F_121 ( V_606 , V_615 | V_616 | V_617 ,
V_2 -> V_637 ,
V_2 , & V_639 ) ;
if ( ! V_2 -> V_638 ) {
F_119 ( V_2 , V_313 , V_314 ,
L_286
L_287 ) ;
goto V_611;
}
snprintf ( V_606 , sizeof( V_606 ) , L_288 ) ;
V_2 -> V_640 =
F_121 ( V_606 , V_615 | V_616 | V_617 ,
V_2 -> V_637 ,
V_2 , & V_641 ) ;
if ( ! V_2 -> V_640 ) {
F_119 ( V_2 , V_313 , V_314 ,
L_289 ) ;
goto V_611;
}
snprintf ( V_606 , sizeof( V_606 ) , L_290 ) ;
V_2 -> V_642 =
F_121 ( V_606 , 0644 ,
V_2 -> V_637 ,
V_2 , & V_643 ) ;
if ( ! V_2 -> V_642 ) {
F_119 ( V_2 , V_313 , V_314 ,
L_291 ) ;
goto V_611;
}
snprintf ( V_606 , sizeof( V_606 ) , L_292 ) ;
V_2 -> V_644 =
F_121 ( V_606 , 0644 ,
V_2 -> V_637 ,
V_2 , & V_645 ) ;
if ( ! V_2 -> V_644 ) {
F_119 ( V_2 , V_313 , V_314 ,
L_293 ) ;
goto V_611;
}
snprintf ( V_606 , sizeof( V_606 ) , L_294 ) ;
V_2 -> V_646 =
F_121 ( V_606 , 0644 ,
V_2 -> V_637 ,
V_2 , & V_647 ) ;
if ( ! V_2 -> V_646 ) {
F_119 ( V_2 , V_313 , V_314 ,
L_295 ) ;
goto V_611;
}
if ( ! V_608 )
goto V_611;
if ( V_27 -> V_48 < V_619 )
goto V_611;
snprintf ( V_606 , sizeof( V_606 ) , L_296 ) ;
if ( ! V_27 -> V_648 ) {
V_27 -> V_648 =
F_118 ( V_606 , V_27 -> V_612 ) ;
if ( ! V_27 -> V_648 ) {
F_119 ( V_2 , V_313 , V_314 ,
L_297 ) ;
goto V_611;
}
memset ( & V_339 , 0 , sizeof( V_339 ) ) ;
}
snprintf ( V_606 , sizeof( V_606 ) , L_298 ) ;
if ( ! V_27 -> V_649 ) {
V_27 -> V_649 =
F_121 ( V_606 , V_615 | V_616 | V_617 ,
V_27 -> V_648 , V_27 , & V_650 ) ;
if ( ! V_27 -> V_649 ) {
F_119 ( V_2 , V_313 , V_314 ,
L_299 ) ;
goto V_611;
}
V_339 . V_348 . V_369 = 0 ;
}
snprintf ( V_606 , sizeof( V_606 ) , L_300 ) ;
if ( ! V_27 -> V_651 ) {
V_27 -> V_651 =
F_121 ( V_606 , V_615 | V_616 | V_617 ,
V_27 -> V_648 , V_27 , & V_652 ) ;
if ( ! V_27 -> V_651 ) {
F_119 ( V_2 , V_313 , V_314 ,
L_301 ) ;
goto V_611;
}
V_339 . V_348 . V_369 = 0 ;
}
snprintf ( V_606 , sizeof( V_606 ) , L_302 ) ;
if ( ! V_27 -> V_653 ) {
V_27 -> V_653 =
F_121 ( V_606 , V_615 | V_616 ,
V_27 -> V_648 , V_27 , & V_654 ) ;
if ( ! V_27 -> V_653 ) {
F_119 ( V_2 , V_313 , V_314 ,
L_303 ) ;
goto V_611;
}
}
snprintf ( V_606 , sizeof( V_606 ) , L_304 ) ;
if ( ! V_27 -> V_655 ) {
V_27 -> V_655 =
F_121 ( V_606 , V_615 | V_616 | V_617 ,
V_27 -> V_648 , V_27 , & V_656 ) ;
if ( ! V_27 -> V_655 ) {
F_119 ( V_2 , V_313 , V_314 ,
L_305 ) ;
goto V_611;
}
}
snprintf ( V_606 , sizeof( V_606 ) , L_306 ) ;
if ( ! V_27 -> V_657 ) {
V_27 -> V_657 =
F_121 ( V_606 , V_615 | V_616 | V_617 ,
V_27 -> V_648 , V_27 , & V_658 ) ;
if ( ! V_27 -> V_657 ) {
F_119 ( V_2 , V_313 , V_314 ,
L_307 ) ;
goto V_611;
}
}
snprintf ( V_606 , sizeof( V_606 ) , L_308 ) ;
if ( ! V_27 -> V_659 ) {
V_27 -> V_659 =
F_121 ( V_606 , V_615 | V_616 | V_617 ,
V_27 -> V_648 , V_27 , & V_660 ) ;
if ( ! V_27 -> V_659 ) {
F_119 ( V_2 , V_313 , V_314 ,
L_309 ) ;
goto V_611;
}
}
snprintf ( V_606 , sizeof( V_606 ) , L_310 ) ;
if ( ! V_27 -> V_661 ) {
V_27 -> V_661 =
F_121 ( V_606 , V_615 | V_616 | V_617 ,
V_27 -> V_648 , V_27 , & V_662 ) ;
if ( ! V_27 -> V_661 ) {
F_119 ( V_2 , V_313 , V_314 ,
L_311 ) ;
goto V_611;
}
}
if ( V_27 -> V_253 . V_663 ) {
snprintf ( V_606 , sizeof( V_606 ) , L_312 ) ;
if ( ! V_27 -> V_664 ) {
V_27 -> V_664 =
F_121 ( V_606 ,
V_615 | V_616 | V_617 ,
V_27 -> V_648 , V_27 ,
& V_665 ) ;
if ( ! V_27 -> V_664 ) {
F_119 ( V_2 , V_313 , V_314 ,
L_313
L_314 ) ;
goto V_611;
}
}
}
V_611:
return;
#endif
}
inline void
F_123 ( struct V_1 * V_2 )
{
#ifdef F_28
struct V_26 * V_27 = V_2 -> V_27 ;
if ( V_2 -> V_18 ) {
F_5 ( V_2 -> V_18 ) ;
V_2 -> V_18 = NULL ;
}
F_124 ( V_2 -> V_638 ) ;
V_2 -> V_638 = NULL ;
F_124 ( V_2 -> V_640 ) ;
V_2 -> V_640 = NULL ;
F_124 ( V_2 -> V_642 ) ;
V_2 -> V_642 = NULL ;
F_124 ( V_2 -> V_644 ) ;
V_2 -> V_644 = NULL ;
F_124 ( V_2 -> V_646 ) ;
V_2 -> V_646 = NULL ;
if ( V_2 -> V_637 ) {
F_124 ( V_2 -> V_637 ) ;
V_2 -> V_637 = NULL ;
F_125 ( & V_27 -> V_613 ) ;
}
if ( F_3 ( & V_27 -> V_613 ) == 0 ) {
F_124 ( V_27 -> V_614 ) ;
V_27 -> V_614 = NULL ;
F_124 ( V_27 -> V_620 ) ;
V_27 -> V_620 = NULL ;
F_124 ( V_27 -> V_622 ) ;
V_27 -> V_622 = NULL ;
F_124 ( V_27 -> V_624 ) ;
V_27 -> V_624 = NULL ;
F_124 ( V_27 -> V_626 ) ;
V_27 -> V_626 = NULL ;
F_124 ( V_27 -> V_310 ) ;
V_27 -> V_310 = NULL ;
F_124 ( V_27 -> V_305 ) ;
V_27 -> V_305 = NULL ;
F_124 ( V_27 -> V_307 ) ;
V_27 -> V_307 = NULL ;
F_124 ( V_27 -> V_293 ) ;
V_27 -> V_293 = NULL ;
F_124 ( V_27 -> V_295 ) ;
V_27 -> V_295 = NULL ;
F_124 ( V_27 -> V_297 ) ;
V_27 -> V_297 = NULL ;
F_124 ( V_27 -> V_299 ) ;
V_27 -> V_299 = NULL ;
F_124 ( V_27 -> V_301 ) ;
V_27 -> V_301 = NULL ;
F_124 ( V_27 -> V_303 ) ;
V_27 -> V_303 = NULL ;
if ( V_27 -> V_30 ) {
F_5 ( V_27 -> V_30 ) ;
V_27 -> V_30 = NULL ;
}
F_124 ( V_27 -> V_630 ) ;
V_27 -> V_630 = NULL ;
F_124 ( V_27 -> V_632 ) ;
V_27 -> V_632 = NULL ;
F_5 ( V_27 -> V_244 ) ;
V_27 -> V_244 = NULL ;
if ( V_27 -> V_48 == V_619 ) {
F_124 ( V_27 -> V_664 ) ;
V_27 -> V_664 = NULL ;
F_124 ( V_27 -> V_661 ) ;
V_27 -> V_661 = NULL ;
F_124 ( V_27 -> V_659 ) ;
V_27 -> V_659 = NULL ;
F_124 ( V_27 -> V_657 ) ;
V_27 -> V_657 = NULL ;
F_124 ( V_27 -> V_655 ) ;
V_27 -> V_655 = NULL ;
F_124 ( V_27 -> V_653 ) ;
V_27 -> V_653 = NULL ;
F_124 ( V_27 -> V_651 ) ;
V_27 -> V_651 = NULL ;
F_124 ( V_27 -> V_649 ) ;
V_27 -> V_649 = NULL ;
F_124 ( V_27 -> V_648 ) ;
V_27 -> V_648 = NULL ;
}
if ( V_27 -> V_612 ) {
F_124 ( V_27 -> V_612 ) ;
V_27 -> V_612 = NULL ;
F_125 ( & V_610 ) ;
}
F_124 ( V_609 ) ;
V_609 = NULL ;
}
#endif
return;
}
void
F_126 ( struct V_26 * V_27 )
{
int V_666 ;
F_127 ( V_27 , V_667 , 0 ) ;
F_127 ( V_27 , V_668 , 0 ) ;
F_127 ( V_27 , V_669 , 0 ) ;
for ( V_666 = 0 ; V_666 < V_27 -> V_425 ; V_666 ++ )
F_127 ( V_27 , V_670 , V_666 ) ;
for ( V_666 = 0 ; V_666 < V_27 -> V_427 ; V_666 ++ )
F_127 ( V_27 , V_671 , V_666 ) ;
F_128 ( V_27 ) ;
F_129 ( V_27 ) ;
F_130 ( V_27 , V_667 , 0 ) ;
F_130 ( V_27 , V_668 , 0 ) ;
F_130 ( V_27 , V_669 , 0 ) ;
for ( V_666 = 0 ; V_666 < V_27 -> V_425 ; V_666 ++ )
F_130 ( V_27 , V_670 , V_666 ) ;
for ( V_666 = 0 ; V_666 < V_27 -> V_427 ; V_666 ++ )
F_130 ( V_27 , V_671 , V_666 ) ;
for ( V_666 = 0 ; V_666 < V_27 -> V_446 ; V_666 ++ )
F_131 ( V_27 , V_666 ) ;
}
