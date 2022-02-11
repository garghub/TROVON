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
for ( V_5 = 0 ; V_5 < 4 ; V_5 ++ ) {
V_84 = & V_27 -> V_94 [ V_5 ] ;
V_89 = & V_86 -> V_95 [ V_5 ] ;
V_7 += snprintf ( V_3 + V_7 , V_4 - V_7 ,
L_13
L_14 ,
V_5 , V_84 -> V_96 , V_89 -> V_87 . V_97 . V_98 ,
V_89 -> V_87 . V_97 . V_99 ,
V_89 -> V_87 . V_97 . V_100 ,
V_89 -> V_101 , V_84 -> V_102 ,
V_89 -> V_87 . V_97 . V_103 ) ;
}
if ( V_27 -> V_48 <= V_104 ) {
V_79 = F_17 ( V_27 -> V_105 ) ;
V_80 = F_17 ( V_27 -> V_106 ) ;
V_81 = F_17 ( V_27 -> V_107 ) ;
V_82 = F_17 ( V_27 -> V_108 ) ;
V_7 += snprintf ( V_3 + V_7 , V_4 - V_7 , L_15
L_16 , V_79 , V_80 , V_81 , V_82 ) ;
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
struct V_112 * V_113 ;
unsigned char * V_114 , * V_115 ;
V_109 = ( V_116 / V_117 ) ;
F_8 ( V_111 -> V_118 ) ;
F_10 (ndlp, &vport->fc_nodes, nlp_listp) {
if ( ! V_109 ) {
V_7 += snprintf ( V_3 + V_7 , V_4 - V_7 ,
L_17 ) ;
break;
}
V_109 -- ;
switch ( V_113 -> V_119 ) {
case V_120 :
V_114 = L_18 ;
break;
case V_121 :
V_114 = L_19 ;
break;
case V_122 :
V_114 = L_20 ;
break;
case V_123 :
V_114 = L_21 ;
break;
case V_124 :
V_114 = L_22 ;
break;
case V_125 :
V_114 = L_23 ;
break;
case V_126 :
V_114 = L_24 ;
break;
case V_127 :
V_114 = L_25 ;
break;
case V_128 :
V_114 = L_26 ;
break;
default:
V_114 = L_27 ;
}
V_7 += snprintf ( V_3 + V_7 , V_4 - V_7 , L_28 ,
V_114 , V_113 -> V_129 ) ;
V_115 = ( unsigned char * ) & V_113 -> V_130 ;
V_7 += snprintf ( V_3 + V_7 , V_4 - V_7 ,
L_29 ,
* V_115 , * ( V_115 + 1 ) , * ( V_115 + 2 ) , * ( V_115 + 3 ) ,
* ( V_115 + 4 ) , * ( V_115 + 5 ) , * ( V_115 + 6 ) , * ( V_115 + 7 ) ) ;
V_115 = ( unsigned char * ) & V_113 -> V_131 ;
V_7 += snprintf ( V_3 + V_7 , V_4 - V_7 ,
L_30 ,
* V_115 , * ( V_115 + 1 ) , * ( V_115 + 2 ) , * ( V_115 + 3 ) ,
* ( V_115 + 4 ) , * ( V_115 + 5 ) , * ( V_115 + 6 ) , * ( V_115 + 7 ) ) ;
if ( V_113 -> V_132 & V_133 )
V_7 += snprintf ( V_3 + V_7 , V_4 - V_7 , L_31 ,
V_113 -> V_134 ) ;
else
V_7 += snprintf ( V_3 + V_7 , V_4 - V_7 , L_32 ) ;
V_7 += snprintf ( V_3 + V_7 , V_4 - V_7 , L_33 ,
V_113 -> V_132 ) ;
if ( ! V_113 -> V_135 )
V_7 += snprintf ( V_3 + V_7 , V_4 - V_7 , L_34 ) ;
if ( V_113 -> V_135 & V_136 )
V_7 += snprintf ( V_3 + V_7 , V_4 - V_7 , L_35 ) ;
if ( V_113 -> V_135 & V_137 )
V_7 += snprintf ( V_3 + V_7 , V_4 - V_7 , L_36 ) ;
if ( V_113 -> V_135 & V_138 )
V_7 += snprintf ( V_3 + V_7 , V_4 - V_7 , L_37 ,
V_113 -> V_139 ) ;
if ( V_113 -> V_135 & V_140 )
V_7 += snprintf ( V_3 + V_7 , V_4 - V_7 , L_38 ) ;
V_7 += snprintf ( V_3 + V_7 , V_4 - V_7 , L_39 ,
V_113 -> V_141 ) ;
V_7 += snprintf ( V_3 + V_7 , V_4 - V_7 , L_40 ,
F_3 ( & V_113 -> V_142 . V_143 ) ) ;
V_7 += snprintf ( V_3 + V_7 , V_4 - V_7 , L_41 ) ;
}
F_13 ( V_111 -> V_118 ) ;
return V_7 ;
}
inline void
F_20 ( struct V_1 * V_2 , int V_144 , char * V_19 ,
T_1 V_23 , T_1 V_24 , T_1 V_25 )
{
#ifdef F_21
struct V_10 * V_11 ;
int V_6 ;
if ( ! ( V_145 & V_144 ) )
return;
if ( ! V_15 || ! V_17 ||
! V_2 || ! V_2 -> V_18 )
return;
V_6 = F_22 ( & V_2 -> V_16 ) &
( V_17 - 1 ) ;
V_11 = V_2 -> V_18 + V_6 ;
V_11 -> V_19 = V_19 ;
V_11 -> V_23 = V_23 ;
V_11 -> V_24 = V_24 ;
V_11 -> V_25 = V_25 ;
V_11 -> V_22 = F_22 ( & V_146 ) ;
V_11 -> V_20 = V_147 ;
#endif
return;
}
inline void
F_23 ( struct V_26 * V_27 , char * V_19 ,
T_1 V_23 , T_1 V_24 , T_1 V_25 )
{
#ifdef F_21
struct V_10 * V_11 ;
int V_6 ;
if ( ! V_15 || ! V_29 ||
! V_27 || ! V_27 -> V_30 )
return;
V_6 = F_22 ( & V_27 -> V_28 ) &
( V_29 - 1 ) ;
V_11 = V_27 -> V_30 + V_6 ;
V_11 -> V_19 = V_19 ;
V_11 -> V_23 = V_23 ;
V_11 -> V_24 = V_24 ;
V_11 -> V_25 = V_25 ;
V_11 -> V_22 = F_22 ( & V_146 ) ;
V_11 -> V_20 = V_147 ;
#endif
return;
}
static int
F_24 ( struct V_148 * V_148 , struct V_149 * V_149 )
{
struct V_1 * V_2 = V_148 -> V_150 ;
struct V_151 * V_152 ;
int V_4 ;
int V_153 = - V_154 ;
if ( ! V_17 ) {
V_153 = - V_155 ;
goto V_156;
}
V_152 = F_2 ( sizeof( * V_152 ) , V_14 ) ;
if ( ! V_152 )
goto V_156;
V_4 = ( V_17 * V_13 ) ;
V_4 = F_25 ( V_4 ) ;
V_152 -> V_12 = F_2 ( V_4 , V_14 ) ;
if ( ! V_152 -> V_12 ) {
F_5 ( V_152 ) ;
goto V_156;
}
V_152 -> V_7 = F_1 ( V_2 , V_152 -> V_12 , V_4 ) ;
V_149 -> V_157 = V_152 ;
V_153 = 0 ;
V_156:
return V_153 ;
}
static int
F_26 ( struct V_148 * V_148 , struct V_149 * V_149 )
{
struct V_26 * V_27 = V_148 -> V_150 ;
struct V_151 * V_152 ;
int V_4 ;
int V_153 = - V_154 ;
if ( ! V_29 ) {
V_153 = - V_155 ;
goto V_156;
}
V_152 = F_2 ( sizeof( * V_152 ) , V_14 ) ;
if ( ! V_152 )
goto V_156;
V_4 = ( V_29 * V_13 ) ;
V_4 = F_25 ( V_4 ) ;
V_152 -> V_12 = F_2 ( V_4 , V_14 ) ;
if ( ! V_152 -> V_12 ) {
F_5 ( V_152 ) ;
goto V_156;
}
V_152 -> V_7 = F_6 ( V_27 , V_152 -> V_12 , V_4 ) ;
V_149 -> V_157 = V_152 ;
V_153 = 0 ;
V_156:
return V_153 ;
}
static int
F_27 ( struct V_148 * V_148 , struct V_149 * V_149 )
{
struct V_26 * V_27 = V_148 -> V_150 ;
struct V_151 * V_152 ;
int V_153 = - V_154 ;
V_152 = F_2 ( sizeof( * V_152 ) , V_14 ) ;
if ( ! V_152 )
goto V_156;
V_152 -> V_12 = F_2 ( V_74 , V_14 ) ;
if ( ! V_152 -> V_12 ) {
F_5 ( V_152 ) ;
goto V_156;
}
V_152 -> V_7 = F_7 ( V_27 , V_152 -> V_12 ,
V_74 ) ;
V_149 -> V_157 = V_152 ;
V_153 = 0 ;
V_156:
return V_153 ;
}
static int
F_28 ( struct V_148 * V_148 , struct V_149 * V_149 )
{
struct V_26 * V_27 = V_148 -> V_150 ;
struct V_151 * V_152 ;
int V_153 = - V_154 ;
V_152 = F_2 ( sizeof( * V_152 ) , V_14 ) ;
if ( ! V_152 )
goto V_156;
V_152 -> V_12 = F_2 ( V_158 , V_14 ) ;
if ( ! V_152 -> V_12 ) {
F_5 ( V_152 ) ;
goto V_156;
}
V_152 -> V_7 = F_14 ( V_27 , V_152 -> V_12 ,
V_158 ) ;
V_149 -> V_157 = V_152 ;
V_153 = 0 ;
V_156:
return V_153 ;
}
static int
F_29 ( struct V_148 * V_148 , struct V_149 * V_149 )
{
struct V_26 * V_27 = V_148 -> V_150 ;
struct V_151 * V_152 ;
int V_153 = - V_154 ;
V_152 = F_2 ( sizeof( * V_152 ) , V_14 ) ;
if ( ! V_152 )
goto V_156;
V_152 -> V_12 = F_2 ( V_159 , V_14 ) ;
if ( ! V_152 -> V_12 ) {
F_5 ( V_152 ) ;
goto V_156;
}
V_152 -> V_7 = F_16 ( V_27 , V_152 -> V_12 ,
V_159 ) ;
V_149 -> V_157 = V_152 ;
V_153 = 0 ;
V_156:
return V_153 ;
}
static int
F_30 ( struct V_148 * V_148 , struct V_149 * V_149 )
{
struct V_151 * V_152 ;
int V_153 = - V_154 ;
if ( ! V_160 )
return - V_161 ;
V_152 = F_2 ( sizeof( * V_152 ) , V_14 ) ;
if ( ! V_152 )
goto V_156;
F_31 ( V_162 L_42 ,
V_163 , V_160 ) ;
V_152 -> V_12 = V_160 ;
if ( ! V_152 -> V_12 ) {
F_5 ( V_152 ) ;
goto V_156;
}
V_152 -> V_7 = ( 1 << V_164 ) << V_165 ;
V_149 -> V_157 = V_152 ;
V_153 = 0 ;
V_156:
return V_153 ;
}
static int
F_32 ( struct V_148 * V_148 , struct V_149 * V_149 )
{
struct V_151 * V_152 ;
int V_153 = - V_154 ;
if ( ! V_166 )
return - V_161 ;
V_152 = F_2 ( sizeof( * V_152 ) , V_14 ) ;
if ( ! V_152 )
goto V_156;
F_31 ( V_162 L_43 ,
V_163 , V_166 , V_149 -> V_167 -> V_168 . V_115 ) ;
V_152 -> V_12 = V_166 ;
if ( ! V_152 -> V_12 ) {
F_5 ( V_152 ) ;
goto V_156;
}
V_152 -> V_7 = ( 1 << V_169 ) << V_165 ;
V_149 -> V_157 = V_152 ;
V_153 = 0 ;
V_156:
return V_153 ;
}
static T_2
F_33 ( struct V_149 * V_149 , const char T_3 * V_3 ,
T_4 V_170 , T_5 * V_171 )
{
F_34 ( & V_172 ) ;
memset ( ( void * ) V_160 , 0 ,
( ( 1 << V_165 ) << V_164 ) ) ;
memset ( ( void * ) V_166 , 0 ,
( ( 1 << V_165 ) << V_169 ) ) ;
V_173 = 0 ;
F_35 ( & V_172 ) ;
return V_170 ;
}
static T_2
F_36 ( struct V_149 * V_149 , char T_3 * V_3 ,
T_4 V_170 , T_5 * V_171 )
{
struct V_174 * V_175 = V_149 -> V_167 ;
struct V_26 * V_27 = V_149 -> V_157 ;
char V_176 [ 32 ] ;
V_71 V_177 = 0 ;
int V_109 = 0 ;
if ( V_175 == V_27 -> V_178 )
V_109 = snprintf ( V_176 , 32 , L_44 , V_27 -> V_179 ) ;
else if ( V_175 == V_27 -> V_180 )
V_109 = snprintf ( V_176 , 32 , L_44 , V_27 -> V_181 ) ;
else if ( V_175 == V_27 -> V_182 )
V_109 = snprintf ( V_176 , 32 , L_44 , V_27 -> V_183 ) ;
else if ( V_175 == V_27 -> V_184 )
V_109 = snprintf ( V_176 , 32 , L_44 , V_27 -> V_185 ) ;
else if ( V_175 == V_27 -> V_186 )
V_109 = snprintf ( V_176 , 32 , L_44 , V_27 -> V_187 ) ;
else if ( V_175 == V_27 -> V_188 )
V_109 = snprintf ( V_176 , 32 , L_44 , V_27 -> V_189 ) ;
else if ( V_175 == V_27 -> V_190 )
V_109 = snprintf ( V_176 , 32 , L_45 , V_27 -> V_191 ) ;
else if ( V_175 == V_27 -> V_192 ) {
memcpy ( & V_177 , & V_27 -> V_193 , sizeof( struct V_194 ) ) ;
V_177 = F_37 ( V_177 ) ;
V_109 = snprintf ( V_176 , 32 , L_46 , V_177 ) ;
} else if ( V_175 == V_27 -> V_195 ) {
if ( V_27 -> V_196 == ( V_197 ) ( - 1 ) )
V_109 = snprintf ( V_176 , 32 , L_47 ) ;
else
V_109 = snprintf ( V_176 , 32 , L_48 ,
( V_71 ) V_27 -> V_196 ) ;
} else
F_38 ( V_27 , V_162 , V_198 ,
L_49 ) ;
return F_39 ( V_3 , V_170 , V_171 , & V_176 , V_109 ) ;
}
static T_2
F_40 ( struct V_149 * V_149 , const char T_3 * V_3 ,
T_4 V_170 , T_5 * V_171 )
{
struct V_174 * V_175 = V_149 -> V_167 ;
struct V_26 * V_27 = V_149 -> V_157 ;
char V_199 [ 32 ] ;
V_71 V_177 = 0 ;
int V_4 ;
memset ( V_199 , 0 , 32 ) ;
V_4 = ( V_170 < 32 ) ? V_170 : 32 ;
if ( F_41 ( V_199 , V_3 , V_4 ) )
return 0 ;
if ( V_175 == V_27 -> V_195 ) {
if ( ( V_3 [ 0 ] == 'o' ) && ( V_3 [ 1 ] == 'f' ) && ( V_3 [ 2 ] == 'f' ) )
V_177 = ( V_71 ) ( - 1 ) ;
}
if ( ( V_177 == 0 ) && ( F_42 ( V_199 , 0 , & V_177 ) ) )
return 0 ;
if ( V_175 == V_27 -> V_178 )
V_27 -> V_179 = ( T_1 ) V_177 ;
else if ( V_175 == V_27 -> V_180 )
V_27 -> V_181 = ( T_1 ) V_177 ;
else if ( V_175 == V_27 -> V_182 )
V_27 -> V_183 = ( T_1 ) V_177 ;
else if ( V_175 == V_27 -> V_184 )
V_27 -> V_185 = ( T_1 ) V_177 ;
else if ( V_175 == V_27 -> V_186 )
V_27 -> V_187 = ( T_1 ) V_177 ;
else if ( V_175 == V_27 -> V_188 )
V_27 -> V_189 = ( T_1 ) V_177 ;
else if ( V_175 == V_27 -> V_195 )
V_27 -> V_196 = ( V_197 ) V_177 ;
else if ( V_175 == V_27 -> V_190 )
V_27 -> V_191 = ( T_1 ) ( V_177 & V_200 ) ;
else if ( V_175 == V_27 -> V_192 ) {
V_177 = F_37 ( V_177 ) ;
memcpy ( & V_27 -> V_193 , & V_177 , sizeof( struct V_194 ) ) ;
} else
F_38 ( V_27 , V_162 , V_198 ,
L_50 ) ;
return V_170 ;
}
static int
F_43 ( struct V_148 * V_148 , struct V_149 * V_149 )
{
return 0 ;
}
static int
F_44 ( struct V_148 * V_148 , struct V_149 * V_149 )
{
struct V_1 * V_2 = V_148 -> V_150 ;
struct V_151 * V_152 ;
int V_153 = - V_154 ;
V_152 = F_2 ( sizeof( * V_152 ) , V_14 ) ;
if ( ! V_152 )
goto V_156;
V_152 -> V_12 = F_2 ( V_116 , V_14 ) ;
if ( ! V_152 -> V_12 ) {
F_5 ( V_152 ) ;
goto V_156;
}
V_152 -> V_7 = F_18 ( V_2 , V_152 -> V_12 ,
V_116 ) ;
V_149 -> V_157 = V_152 ;
V_153 = 0 ;
V_156:
return V_153 ;
}
static T_5
F_45 ( struct V_149 * V_149 , T_5 V_75 , int V_201 )
{
struct V_151 * V_152 = V_149 -> V_157 ;
return F_46 ( V_149 , V_75 , V_201 , V_152 -> V_7 ) ;
}
static T_2
F_47 ( struct V_149 * V_149 , char T_3 * V_3 ,
T_4 V_170 , T_5 * V_171 )
{
struct V_151 * V_152 = V_149 -> V_157 ;
return F_39 ( V_3 , V_170 , V_171 , V_152 -> V_12 ,
V_152 -> V_7 ) ;
}
static int
F_48 ( struct V_148 * V_148 , struct V_149 * V_149 )
{
struct V_151 * V_152 = V_149 -> V_157 ;
F_5 ( V_152 -> V_12 ) ;
F_5 ( V_152 ) ;
return 0 ;
}
static int
F_49 ( struct V_148 * V_148 , struct V_149 * V_149 )
{
struct V_151 * V_152 = V_149 -> V_157 ;
V_152 -> V_12 = NULL ;
F_5 ( V_152 ) ;
return 0 ;
}
static int F_50 ( const char T_3 * V_3 , T_4 V_170 ,
struct V_202 * V_203 )
{
char V_204 [ 64 ] ;
char * V_205 , * V_206 ;
int V_5 ;
T_4 V_207 ;
if ( ! F_51 ( V_208 , V_3 , V_170 ) )
return - V_209 ;
memset ( V_204 , 0 , sizeof( V_204 ) ) ;
memset ( V_203 , 0 , sizeof( * V_203 ) ) ;
V_207 = F_52 ( V_170 , ( sizeof( V_204 ) - 1 ) ) ;
if ( F_41 ( V_204 , V_3 , V_207 ) )
return - V_209 ;
V_205 = & V_204 [ 0 ] ;
V_206 = F_53 ( & V_205 , L_51 ) ;
if ( ! V_206 )
return - V_210 ;
V_203 -> V_211 = F_54 ( V_206 , NULL , 0 ) ;
if ( V_203 -> V_211 == 0 )
return - V_210 ;
for ( V_5 = 0 ; V_5 < V_212 ; V_5 ++ ) {
V_206 = F_53 ( & V_205 , L_51 ) ;
if ( ! V_206 )
return V_5 ;
V_203 -> V_213 [ V_5 ] = F_54 ( V_206 , NULL , 0 ) ;
}
return V_5 ;
}
static int
F_55 ( struct V_148 * V_148 , struct V_149 * V_149 )
{
struct V_151 * V_152 ;
V_152 = F_2 ( sizeof( * V_152 ) , V_14 ) ;
if ( ! V_152 )
return - V_154 ;
V_152 -> V_150 = V_148 -> V_150 ;
V_152 -> V_12 = NULL ;
V_149 -> V_157 = V_152 ;
return 0 ;
}
static int
F_56 ( struct V_148 * V_148 , struct V_149 * V_149 )
{
struct V_151 * V_152 = V_149 -> V_157 ;
F_5 ( V_152 -> V_12 ) ;
F_5 ( V_152 ) ;
return 0 ;
}
static int
F_57 ( struct V_148 * V_148 , struct V_149 * V_149 )
{
struct V_151 * V_152 = V_149 -> V_157 ;
if ( V_152 -> V_214 == V_215 ) {
switch ( V_216 . V_217 . V_211 ) {
case V_218 :
case V_219 :
case V_220 :
case V_221 :
case V_222 :
case V_223 :
memset ( & V_216 , 0 , sizeof( V_216 ) ) ;
break;
default:
break;
}
}
F_5 ( V_152 -> V_12 ) ;
F_5 ( V_152 ) ;
return 0 ;
}
static T_2
F_58 ( struct V_149 * V_149 , char T_3 * V_3 , T_4 V_170 ,
T_5 * V_171 )
{
struct V_151 * V_152 = V_149 -> V_157 ;
struct V_26 * V_27 = (struct V_26 * ) V_152 -> V_150 ;
int V_224 , V_225 , V_7 = 0 , V_6 = V_226 ;
int V_227 , V_228 ;
char * V_229 ;
struct V_230 * V_231 ;
T_1 V_232 ;
T_6 V_233 ;
T_7 V_234 ;
V_231 = V_27 -> V_235 ;
if ( ! V_231 )
return 0 ;
V_152 -> V_214 = V_236 ;
if ( ! V_152 -> V_12 )
V_152 -> V_12 = F_2 ( V_237 , V_14 ) ;
if ( ! V_152 -> V_12 )
return 0 ;
V_229 = V_152 -> V_12 ;
if ( * V_171 )
return 0 ;
if ( V_216 . V_217 . V_211 == V_238 ) {
V_227 = V_216 . V_217 . V_213 [ V_239 ] ;
V_228 = V_216 . V_217 . V_213 [ V_240 ] ;
} else
return 0 ;
switch ( V_228 ) {
case V_241 :
F_59 ( V_231 , V_227 , & V_234 ) ;
V_7 += snprintf ( V_229 + V_7 , V_237 - V_7 ,
L_52 , V_227 , V_234 ) ;
break;
case V_242 :
F_60 ( V_231 , V_227 , & V_233 ) ;
V_7 += snprintf ( V_229 + V_7 , V_237 - V_7 ,
L_53 , V_227 , V_233 ) ;
break;
case V_243 :
F_61 ( V_231 , V_227 , & V_232 ) ;
V_7 += snprintf ( V_229 + V_7 , V_237 - V_7 ,
L_54 , V_227 , V_232 ) ;
break;
case V_244 :
goto V_245;
break;
default:
V_7 = 0 ;
break;
}
return F_39 ( V_3 , V_170 , V_171 , V_229 , V_7 ) ;
V_245:
V_224 = V_216 . V_225 . V_246 ;
V_225 = V_224 ;
V_7 += snprintf ( V_229 + V_7 , V_237 - V_7 ,
L_55 , V_224 ) ;
while ( V_6 > 0 ) {
F_61 ( V_231 , V_225 , & V_232 ) ;
V_7 += snprintf ( V_229 + V_7 , V_237 - V_7 ,
L_56 , V_232 ) ;
V_225 += sizeof( T_1 ) ;
if ( V_225 >= V_237 ) {
V_7 += snprintf ( V_229 + V_7 ,
V_237 - V_7 , L_41 ) ;
break;
}
V_6 -= sizeof( T_1 ) ;
if ( ! V_6 )
V_7 += snprintf ( V_229 + V_7 , V_237 - V_7 ,
L_41 ) ;
else if ( ! ( V_6 % ( 8 * sizeof( T_1 ) ) ) ) {
V_224 += ( 8 * sizeof( T_1 ) ) ;
V_7 += snprintf ( V_229 + V_7 , V_237 - V_7 ,
L_57 , V_224 ) ;
}
}
if ( V_6 == 0 ) {
V_216 . V_225 . V_246 += V_226 ;
if ( V_216 . V_225 . V_246 >= V_237 )
V_216 . V_225 . V_246 = 0 ;
} else
V_216 . V_225 . V_246 = 0 ;
return F_39 ( V_3 , V_170 , V_171 , V_229 , V_7 ) ;
}
static T_2
F_62 ( struct V_149 * V_149 , const char T_3 * V_3 ,
T_4 V_170 , T_5 * V_171 )
{
struct V_151 * V_152 = V_149 -> V_157 ;
struct V_26 * V_27 = (struct V_26 * ) V_152 -> V_150 ;
T_1 V_227 , V_247 , V_228 ;
T_1 V_232 ;
T_6 V_233 ;
T_7 V_234 ;
struct V_230 * V_231 ;
int V_153 ;
V_231 = V_27 -> V_235 ;
if ( ! V_231 )
return - V_209 ;
V_152 -> V_214 = V_215 ;
V_153 = F_50 ( V_3 , V_170 , & V_216 . V_217 ) ;
if ( V_153 < 0 )
return V_153 ;
if ( V_216 . V_217 . V_211 == V_238 ) {
if ( V_153 != V_248 )
goto V_249;
V_227 = V_216 . V_217 . V_213 [ V_239 ] ;
V_228 = V_216 . V_217 . V_213 [ V_240 ] ;
if ( V_228 == V_244 ) {
if ( V_227 % sizeof( T_1 ) )
goto V_249;
V_216 . V_225 . V_246 = V_227 ;
} else if ( ( V_228 != sizeof( T_7 ) ) &&
( V_228 != sizeof( T_6 ) ) &&
( V_228 != sizeof( T_1 ) ) )
goto V_249;
if ( V_228 == sizeof( T_7 ) ) {
if ( V_227 > V_237 - sizeof( T_7 ) )
goto V_249;
if ( V_227 % sizeof( T_7 ) )
goto V_249;
}
if ( V_228 == sizeof( T_6 ) ) {
if ( V_227 > V_237 - sizeof( T_6 ) )
goto V_249;
if ( V_227 % sizeof( T_6 ) )
goto V_249;
}
if ( V_228 == sizeof( T_1 ) ) {
if ( V_227 > V_237 - sizeof( T_1 ) )
goto V_249;
if ( V_227 % sizeof( T_1 ) )
goto V_249;
}
} else if ( V_216 . V_217 . V_211 == V_218 ||
V_216 . V_217 . V_211 == V_219 ||
V_216 . V_217 . V_211 == V_220 ) {
if ( V_153 != V_250 )
goto V_249;
V_227 = V_216 . V_217 . V_213 [ V_239 ] ;
V_228 = V_216 . V_217 . V_213 [ V_240 ] ;
V_247 = V_216 . V_217 . V_213 [ V_251 ] ;
if ( ( V_228 != sizeof( T_7 ) ) &&
( V_228 != sizeof( T_6 ) ) &&
( V_228 != sizeof( T_1 ) ) )
goto V_249;
if ( V_228 == sizeof( T_7 ) ) {
if ( V_227 > V_237 - sizeof( T_7 ) )
goto V_249;
if ( V_227 % sizeof( T_7 ) )
goto V_249;
if ( V_216 . V_217 . V_211 == V_218 )
F_63 ( V_231 , V_227 ,
( T_7 ) V_247 ) ;
if ( V_216 . V_217 . V_211 == V_219 ) {
V_153 = F_59 ( V_231 , V_227 , & V_234 ) ;
if ( ! V_153 ) {
V_234 |= ( T_7 ) V_247 ;
F_63 ( V_231 , V_227 ,
V_234 ) ;
}
}
if ( V_216 . V_217 . V_211 == V_220 ) {
V_153 = F_59 ( V_231 , V_227 , & V_234 ) ;
if ( ! V_153 ) {
V_234 &= ( T_7 ) ( ~ V_247 ) ;
F_63 ( V_231 , V_227 ,
V_234 ) ;
}
}
}
if ( V_228 == sizeof( T_6 ) ) {
if ( V_227 > V_237 - sizeof( T_6 ) )
goto V_249;
if ( V_227 % sizeof( T_6 ) )
goto V_249;
if ( V_216 . V_217 . V_211 == V_218 )
F_64 ( V_231 , V_227 ,
( T_6 ) V_247 ) ;
if ( V_216 . V_217 . V_211 == V_219 ) {
V_153 = F_60 ( V_231 , V_227 , & V_233 ) ;
if ( ! V_153 ) {
V_233 |= ( T_6 ) V_247 ;
F_64 ( V_231 , V_227 ,
V_233 ) ;
}
}
if ( V_216 . V_217 . V_211 == V_220 ) {
V_153 = F_60 ( V_231 , V_227 , & V_233 ) ;
if ( ! V_153 ) {
V_233 &= ( T_6 ) ( ~ V_247 ) ;
F_64 ( V_231 , V_227 ,
V_233 ) ;
}
}
}
if ( V_228 == sizeof( T_1 ) ) {
if ( V_227 > V_237 - sizeof( T_1 ) )
goto V_249;
if ( V_227 % sizeof( T_1 ) )
goto V_249;
if ( V_216 . V_217 . V_211 == V_218 )
F_65 ( V_231 , V_227 , V_247 ) ;
if ( V_216 . V_217 . V_211 == V_219 ) {
V_153 = F_61 ( V_231 , V_227 ,
& V_232 ) ;
if ( ! V_153 ) {
V_232 |= V_247 ;
F_65 ( V_231 , V_227 ,
V_232 ) ;
}
}
if ( V_216 . V_217 . V_211 == V_220 ) {
V_153 = F_61 ( V_231 , V_227 ,
& V_232 ) ;
if ( ! V_153 ) {
V_232 &= ~ V_247 ;
F_65 ( V_231 , V_227 ,
V_232 ) ;
}
}
}
} else
goto V_249;
return V_170 ;
V_249:
memset ( & V_216 , 0 , sizeof( V_216 ) ) ;
return - V_210 ;
}
static T_2
F_66 ( struct V_149 * V_149 , char T_3 * V_3 , T_4 V_170 ,
T_5 * V_171 )
{
struct V_151 * V_152 = V_149 -> V_157 ;
struct V_26 * V_27 = (struct V_26 * ) V_152 -> V_150 ;
int V_224 , V_225 , V_252 , V_7 = 0 , V_6 ;
int V_253 , V_254 , V_255 ;
char * V_229 ;
void T_8 * V_256 ;
T_1 V_257 ;
struct V_230 * V_231 ;
T_1 V_232 ;
V_231 = V_27 -> V_235 ;
if ( ! V_231 )
return 0 ;
V_152 -> V_214 = V_236 ;
if ( ! V_152 -> V_12 )
V_152 -> V_12 = F_2 ( V_258 , V_14 ) ;
if ( ! V_152 -> V_12 )
return 0 ;
V_229 = V_152 -> V_12 ;
if ( * V_171 )
return 0 ;
if ( V_216 . V_217 . V_211 == V_259 ) {
V_253 = V_216 . V_217 . V_213 [ V_260 ] ;
V_225 = V_216 . V_217 . V_213 [ V_261 ] ;
V_254 = V_216 . V_217 . V_213 [ V_262 ] ;
V_255 = V_216 . V_217 . V_213 [ V_263 ] ;
} else
return 0 ;
if ( V_254 == 0 )
return 0 ;
V_257 = F_67 ( V_264 , & V_27 -> V_265 . V_266 ) ;
if ( V_257 == V_267 ) {
if ( V_253 == V_268 )
V_256 = V_27 -> V_265 . V_269 ;
else if ( V_253 == V_270 )
V_256 = V_27 -> V_265 . V_271 ;
else if ( V_253 == V_272 )
V_256 = V_27 -> V_265 . V_273 ;
else
return 0 ;
} else if ( V_257 == V_274 ) {
if ( V_253 == V_268 )
V_256 = V_27 -> V_265 . V_269 ;
else
return 0 ;
} else
return 0 ;
if ( V_254 == V_275 ) {
V_252 = V_225 ;
V_232 = F_17 ( V_256 + V_252 ) ;
V_7 += snprintf ( V_229 + V_7 , V_258 - V_7 ,
L_58 , V_252 , V_232 ) ;
} else
goto V_276;
return F_39 ( V_3 , V_170 , V_171 , V_229 , V_7 ) ;
V_276:
V_224 = V_216 . V_225 . V_246 ;
V_252 = V_224 ;
V_7 += snprintf ( V_229 + V_7 , V_258 - V_7 ,
L_59 , V_224 ) ;
V_6 = V_277 ;
while ( V_6 > 0 ) {
V_232 = F_17 ( V_256 + V_252 ) ;
V_7 += snprintf ( V_229 + V_7 , V_258 - V_7 ,
L_56 , V_232 ) ;
V_252 += sizeof( T_1 ) ;
if ( V_254 == V_278 ) {
if ( V_252 >= V_255 ) {
V_7 += snprintf ( V_229 + V_7 ,
V_258 - V_7 , L_41 ) ;
break;
}
} else {
if ( V_252 >= V_225 +
( V_254 * sizeof( T_1 ) ) ) {
V_7 += snprintf ( V_229 + V_7 ,
V_258 - V_7 , L_41 ) ;
break;
}
}
V_6 -= sizeof( T_1 ) ;
if ( ! V_6 )
V_7 += snprintf ( V_229 + V_7 ,
V_258 - V_7 , L_41 ) ;
else if ( ! ( V_6 % ( 8 * sizeof( T_1 ) ) ) ) {
V_224 += ( 8 * sizeof( T_1 ) ) ;
V_7 += snprintf ( V_229 + V_7 ,
V_258 - V_7 ,
L_60 , V_224 ) ;
}
}
if ( V_6 == 0 ) {
V_216 . V_225 . V_246 += V_277 ;
if ( V_254 == V_278 ) {
if ( V_216 . V_225 . V_246 >= V_255 )
V_216 . V_225 . V_246 = 0 ;
} else {
if ( V_252 >= V_225 +
( V_254 * sizeof( T_1 ) ) )
V_216 . V_225 . V_246 = V_225 ;
}
} else {
if ( V_254 == V_278 )
V_216 . V_225 . V_246 = 0 ;
else
V_216 . V_225 . V_246 = V_225 ;
}
return F_39 ( V_3 , V_170 , V_171 , V_229 , V_7 ) ;
}
static T_2
F_68 ( struct V_149 * V_149 , const char T_3 * V_3 ,
T_4 V_170 , T_5 * V_171 )
{
struct V_151 * V_152 = V_149 -> V_157 ;
struct V_26 * V_27 = (struct V_26 * ) V_152 -> V_150 ;
T_1 V_253 , V_255 , V_225 , V_247 , V_254 ;
struct V_230 * V_231 ;
void T_8 * V_256 ;
T_1 V_257 ;
T_1 V_232 ;
int V_153 ;
V_231 = V_27 -> V_235 ;
if ( ! V_231 )
return - V_209 ;
V_152 -> V_214 = V_215 ;
V_153 = F_50 ( V_3 , V_170 , & V_216 . V_217 ) ;
if ( V_153 < 0 )
return V_153 ;
V_257 = F_67 ( V_264 , & V_27 -> V_265 . V_266 ) ;
V_253 = V_216 . V_217 . V_213 [ V_260 ] ;
if ( V_257 == V_267 ) {
if ( ( V_253 != V_268 ) &&
( V_253 != V_270 ) &&
( V_253 != V_272 ) )
goto V_249;
} else if ( V_257 == V_274 ) {
if ( V_253 != V_268 )
goto V_249;
} else
goto V_249;
if ( V_257 == V_267 ) {
if ( V_253 == V_268 ) {
V_216 . V_217 . V_213 [ V_263 ] =
V_279 ;
V_256 = V_27 -> V_265 . V_269 ;
} else if ( V_253 == V_270 ) {
V_216 . V_217 . V_213 [ V_263 ] =
V_280 ;
V_256 = V_27 -> V_265 . V_271 ;
} else if ( V_253 == V_272 ) {
V_216 . V_217 . V_213 [ V_263 ] =
V_281 ;
V_256 = V_27 -> V_265 . V_273 ;
} else
goto V_249;
} else if ( V_257 == V_274 ) {
if ( V_253 == V_268 ) {
V_216 . V_217 . V_213 [ V_263 ] =
V_282 ;
V_256 = V_27 -> V_265 . V_269 ;
} else
goto V_249;
} else
goto V_249;
V_225 = V_216 . V_217 . V_213 [ V_261 ] ;
if ( V_225 % sizeof( T_1 ) )
goto V_249;
V_255 = V_216 . V_217 . V_213 [ V_263 ] ;
if ( V_216 . V_217 . V_211 == V_259 ) {
if ( V_153 != V_283 )
goto V_249;
V_254 = V_216 . V_217 . V_213 [ V_262 ] ;
if ( V_254 == V_278 ) {
if ( V_225 > V_255 - sizeof( T_1 ) )
goto V_249;
V_216 . V_225 . V_246 = V_225 ;
} else if ( V_254 > V_275 ) {
if ( V_225 + V_254 * sizeof( T_1 ) > V_255 )
goto V_249;
V_216 . V_225 . V_246 = V_225 ;
} else if ( V_254 != V_275 )
goto V_249;
} else if ( V_216 . V_217 . V_211 == V_284 ||
V_216 . V_217 . V_211 == V_285 ||
V_216 . V_217 . V_211 == V_286 ) {
if ( V_153 != V_287 )
goto V_249;
V_254 = V_275 ;
V_247 = V_216 . V_217 . V_213 [ V_288 ] ;
if ( V_216 . V_217 . V_211 == V_284 ) {
F_69 ( V_247 , V_256 + V_225 ) ;
F_17 ( V_256 + V_225 ) ;
}
if ( V_216 . V_217 . V_211 == V_285 ) {
V_232 = F_17 ( V_256 + V_225 ) ;
V_232 |= V_247 ;
F_69 ( V_232 , V_256 + V_225 ) ;
F_17 ( V_256 + V_225 ) ;
}
if ( V_216 . V_217 . V_211 == V_286 ) {
V_232 = F_17 ( V_256 + V_225 ) ;
V_232 &= ~ V_247 ;
F_69 ( V_232 , V_256 + V_225 ) ;
F_17 ( V_256 + V_225 ) ;
}
} else
goto V_249;
return V_170 ;
V_249:
memset ( & V_216 , 0 , sizeof( V_216 ) ) ;
return - V_210 ;
}
static T_2
F_70 ( struct V_149 * V_149 , char T_3 * V_3 , T_4 V_170 ,
T_5 * V_171 )
{
struct V_151 * V_152 = V_149 -> V_157 ;
struct V_26 * V_27 = (struct V_26 * ) V_152 -> V_150 ;
int V_7 = 0 ;
char * V_229 ;
int V_289 , V_109 ;
int V_290 ;
struct V_291 * V_292 = NULL ;
if ( ! V_152 -> V_12 )
V_152 -> V_12 = F_2 ( V_293 , V_14 ) ;
if ( ! V_152 -> V_12 )
return 0 ;
V_229 = V_152 -> V_12 ;
V_290 = V_293 - 128 ;
if ( * V_171 )
return 0 ;
F_8 ( & V_27 -> V_49 ) ;
if ( V_27 -> V_265 . V_294 && V_27 -> V_295 ) {
V_109 = V_27 -> V_295 ;
for ( V_289 = 0 ; V_289 < V_109 ; V_289 ++ ) {
V_292 = V_27 -> V_265 . V_294 [ V_289 ] ;
if ( ! V_292 )
goto V_296;
V_7 += snprintf ( V_229 + V_7 ,
V_293 - V_7 ,
L_61
L_62
L_63 ,
V_292 -> V_297 , V_292 -> V_298 ,
V_292 -> V_299 , ( unsigned long long ) V_292 -> V_300 ) ;
V_7 += snprintf ( V_229 + V_7 ,
V_293 - V_7 ,
L_64
L_65
L_66 ,
V_292 -> V_301 ,
V_292 -> V_59 ,
V_292 -> V_302 ,
V_292 -> V_303 ,
V_292 -> V_304 ) ;
V_292 -> V_305 = 0 ;
V_7 += snprintf ( V_229 + V_7 ,
V_293 - V_7 , L_41 ) ;
if ( V_7 >= V_290 )
goto V_306;
V_296:
V_292 = V_27 -> V_265 . V_307 [ V_289 ] ;
V_7 += snprintf ( V_229 + V_7 ,
V_293 - V_7 ,
L_67 ) ;
V_7 += snprintf ( V_229 + V_7 ,
V_293 - V_7 ,
L_68
L_69
L_70 ,
V_292 -> V_308 ,
V_292 -> V_297 , V_292 -> V_298 ,
V_292 -> V_299 , ( unsigned long long ) V_292 -> V_300 ) ;
V_7 += snprintf ( V_229 + V_7 ,
V_293 - V_7 ,
L_71
L_65
L_66 ,
V_292 -> V_301 , V_292 -> V_59 ,
V_292 -> V_302 , V_292 -> V_303 ,
V_292 -> V_304 ) ;
V_292 -> V_309 = 0 ;
V_7 += snprintf ( V_229 + V_7 ,
V_293 - V_7 , L_41 ) ;
if ( V_7 >= V_290 )
goto V_306;
V_292 = V_27 -> V_265 . V_310 [ V_289 ] ;
V_7 += snprintf ( V_229 + V_7 ,
V_293 - V_7 ,
L_72 ) ;
V_7 += snprintf ( V_229 + V_7 ,
V_293 - V_7 ,
L_73
L_74 ,
V_292 -> V_308 ,
V_292 -> V_297 , ( unsigned long long ) V_292 -> V_300 ) ;
V_7 += snprintf ( V_229 + V_7 ,
V_293 - V_7 ,
L_75
L_65
L_66 ,
V_292 -> V_301 ,
V_292 -> V_59 ,
V_292 -> V_302 ,
V_292 -> V_303 ,
V_292 -> V_304 ) ;
V_7 += snprintf ( V_229 + V_7 ,
V_293 - V_7 , L_41 ) ;
if ( V_7 >= V_290 )
goto V_306;
if ( V_289 )
continue;
V_292 = V_27 -> V_265 . V_311 ;
if ( V_292 ) {
V_7 += snprintf ( V_229 + V_7 ,
V_293 - V_7 ,
L_76 ) ;
V_7 += snprintf ( V_229 + V_7 ,
V_293 - V_7 ,
L_68
L_77
L_70 ,
V_292 -> V_308 ,
V_292 -> V_297 , V_292 -> V_298 ,
V_292 -> V_299 ,
( unsigned long long ) V_292 -> V_300 ) ;
V_7 += snprintf ( V_229 + V_7 ,
V_293 - V_7 ,
L_71
L_65
L_66 ,
V_292 -> V_301 , V_292 -> V_59 ,
V_292 -> V_302 , V_292 -> V_303 ,
V_292 -> V_304 ) ;
V_7 += snprintf ( V_229 + V_7 ,
V_293 - V_7 , L_41 ) ;
if ( V_7 >= V_290 )
goto V_306;
}
V_292 = V_27 -> V_265 . V_312 ;
if ( V_292 ) {
V_7 += snprintf ( V_229 + V_7 ,
V_293 - V_7 ,
L_78 ) ;
V_7 += snprintf ( V_229 + V_7 ,
V_293 - V_7 ,
L_79 ,
V_27 -> V_265 . V_312 -> V_308 ) ;
V_7 += snprintf ( V_229 + V_7 ,
V_293 - V_7 ,
L_75
L_65
L_66 ,
V_292 -> V_301 , V_292 -> V_59 ,
V_292 -> V_302 , V_292 -> V_303 ,
V_292 -> V_304 ) ;
V_7 += snprintf ( V_229 + V_7 ,
V_293 - V_7 , L_41 ) ;
if ( V_7 >= V_290 )
goto V_306;
}
V_292 = V_27 -> V_265 . V_313 ;
if ( V_292 ) {
V_7 += snprintf ( V_229 + V_7 ,
V_293 - V_7 ,
L_80 ) ;
V_7 += snprintf ( V_229 + V_7 ,
V_293 - V_7 ,
L_68
L_81
L_70 ,
V_292 -> V_308 ,
V_292 -> V_297 , V_292 -> V_298 ,
V_292 -> V_299 ,
( unsigned long long ) V_292 -> V_300 ) ;
V_7 += snprintf ( V_229 + V_7 ,
V_293 - V_7 ,
L_82
L_65
L_66 ,
V_292 -> V_301 , V_292 -> V_59 ,
V_292 -> V_302 , V_292 -> V_303 ,
V_292 -> V_304 ) ;
V_292 -> V_309 = 0 ;
V_7 += snprintf ( V_229 + V_7 ,
V_293 - V_7 , L_41 ) ;
if ( V_7 >= V_290 )
goto V_306;
}
V_292 = V_27 -> V_265 . V_314 ;
if ( V_292 ) {
V_7 += snprintf ( V_229 + V_7 ,
V_293 - V_7 ,
L_83 ) ;
V_7 += snprintf ( V_229 + V_7 ,
V_293 - V_7 ,
L_73
L_84
L_85 ,
V_292 -> V_308 ,
V_292 -> V_297 ,
( unsigned long long ) V_292 -> V_300 ) ;
V_7 += snprintf ( V_229 + V_7 ,
V_293 - V_7 ,
L_75
L_65
L_66 ,
V_292 -> V_301 , V_292 -> V_59 ,
V_292 -> V_302 , V_292 -> V_303 ,
V_292 -> V_304 ) ;
V_7 += snprintf ( V_229 + V_7 ,
V_293 - V_7 , L_41 ) ;
if ( V_7 >= V_290 )
goto V_306;
}
if ( V_27 -> V_265 . V_315 && V_27 -> V_265 . V_316 ) {
V_292 = V_27 -> V_265 . V_315 ;
V_7 += snprintf ( V_229 + V_7 ,
V_293 - V_7 ,
L_86 ) ;
V_7 += snprintf ( V_229 + V_7 ,
V_293 - V_7 ,
L_73
L_87
L_88 ,
V_292 -> V_308 ,
V_292 -> V_297 , V_292 -> V_298 ,
V_292 -> V_299 ,
( unsigned long long ) V_292 -> V_300 ) ;
V_7 += snprintf ( V_229 + V_7 ,
V_293 - V_7 ,
L_89
L_65
L_90 ,
V_292 -> V_301 ,
V_292 -> V_59 ,
V_292 -> V_302 ,
V_292 -> V_303 ,
V_292 -> V_304 ) ;
V_292 = V_27 -> V_265 . V_316 ;
V_7 += snprintf ( V_229 + V_7 ,
V_293 - V_7 ,
L_91
L_65
L_90 ,
V_292 -> V_301 ,
V_292 -> V_59 ,
V_292 -> V_302 ,
V_292 -> V_303 ,
V_292 -> V_304 ) ;
V_7 += snprintf ( V_229 + V_7 ,
V_293 - V_7 , L_41 ) ;
}
}
}
if ( V_27 -> V_317 ) {
V_292 = V_27 -> V_265 . V_318 ;
if ( ! V_292 )
goto V_156;
V_7 += snprintf ( V_229 + V_7 ,
V_293 - V_7 ,
L_92
L_62
L_63 ,
V_292 -> V_297 , V_292 -> V_298 ,
V_292 -> V_299 , ( unsigned long long ) V_292 -> V_300 ) ;
V_7 += snprintf ( V_229 + V_7 ,
V_293 - V_7 ,
L_64
L_65
L_66 ,
V_292 -> V_301 ,
V_292 -> V_59 ,
V_292 -> V_302 ,
V_292 -> V_303 ,
V_292 -> V_304 ) ;
V_292 -> V_305 = 0 ;
V_7 += snprintf ( V_229 + V_7 ,
V_293 - V_7 , L_41 ) ;
if ( V_7 >= V_290 )
goto V_306;
}
if ( V_27 -> V_317 ) {
V_292 = V_27 -> V_265 . V_319 ;
if ( V_292 ) {
V_7 += snprintf ( V_229 + V_7 ,
V_293 - V_7 ,
L_93 ) ;
V_7 += snprintf ( V_229 + V_7 ,
V_293 - V_7 ,
L_68
L_69
L_70 ,
V_292 -> V_308 ,
V_292 -> V_297 , V_292 -> V_298 ,
V_292 -> V_299 , ( unsigned long long ) V_292 -> V_300 ) ;
V_7 += snprintf ( V_229 + V_7 ,
V_293 - V_7 ,
L_71
L_65
L_66 ,
V_292 -> V_301 , V_292 -> V_59 ,
V_292 -> V_302 , V_292 -> V_303 ,
V_292 -> V_304 ) ;
V_292 -> V_309 = 0 ;
V_7 += snprintf ( V_229 + V_7 ,
V_293 - V_7 , L_41 ) ;
if ( V_7 >= V_290 )
goto V_306;
}
V_292 = V_27 -> V_265 . V_320 ;
if ( V_292 ) {
V_7 += snprintf ( V_229 + V_7 ,
V_293 - V_7 ,
L_94 ) ;
V_7 += snprintf ( V_229 + V_7 ,
V_293 - V_7 ,
L_73
L_74 ,
V_292 -> V_308 ,
V_292 -> V_297 , ( unsigned long long ) V_292 -> V_300 ) ;
V_7 += snprintf ( V_229 + V_7 ,
V_293 - V_7 ,
L_75
L_65
L_66 ,
V_292 -> V_301 ,
V_292 -> V_59 ,
V_292 -> V_302 ,
V_292 -> V_303 ,
V_292 -> V_304 ) ;
V_7 += snprintf ( V_229 + V_7 ,
V_293 - V_7 , L_41 ) ;
if ( V_7 >= V_290 )
goto V_306;
}
}
V_156:
F_13 ( & V_27 -> V_49 ) ;
return F_39 ( V_3 , V_170 , V_171 , V_229 , V_7 ) ;
V_306:
V_7 += snprintf ( V_229 + V_7 ,
V_293 - V_7 , L_95 ) ;
F_13 ( & V_27 -> V_49 ) ;
return F_39 ( V_3 , V_170 , V_171 , V_229 , V_7 ) ;
}
static int
F_71 ( struct V_291 * V_321 , int V_6 , int V_228 )
{
if ( ( V_228 != 1 ) && ( V_228 != V_322 ) )
return - V_210 ;
if ( V_6 > V_321 -> V_59 - 1 )
return - V_210 ;
return 0 ;
}
static int
F_72 ( char * V_229 , int V_7 , struct V_291 * V_323 ,
T_1 V_6 )
{
int V_225 , V_324 ;
T_1 * V_325 ;
if ( ! V_229 || ! V_323 )
return 0 ;
V_324 = V_323 -> V_302 ;
V_7 += snprintf ( V_229 + V_7 , V_326 - V_7 ,
L_96 , V_6 ) ;
V_225 = 0 ;
V_325 = V_323 -> V_327 [ V_6 ] . V_328 ;
while ( V_324 > 0 ) {
V_7 += snprintf ( V_229 + V_7 , V_326 - V_7 ,
L_56 , * V_325 ) ;
V_325 ++ ;
V_225 += sizeof( T_1 ) ;
V_324 -= sizeof( T_1 ) ;
if ( V_324 > 0 && ! ( V_225 % ( 4 * sizeof( T_1 ) ) ) )
V_7 += snprintf ( V_229 + V_7 ,
V_326 - V_7 , L_41 ) ;
}
V_7 += snprintf ( V_229 + V_7 , V_326 - V_7 , L_41 ) ;
return V_7 ;
}
static T_2
F_73 ( struct V_149 * V_149 , char T_3 * V_3 , T_4 V_170 ,
T_5 * V_171 )
{
struct V_151 * V_152 = V_149 -> V_157 ;
T_1 V_329 , V_6 , V_228 ;
struct V_291 * V_323 = NULL ;
char * V_229 ;
int V_7 = 0 ;
V_152 -> V_214 = V_236 ;
if ( ! V_152 -> V_12 )
V_152 -> V_12 = F_2 ( V_326 , V_14 ) ;
if ( ! V_152 -> V_12 )
return 0 ;
V_229 = V_152 -> V_12 ;
if ( * V_171 )
return 0 ;
if ( V_216 . V_217 . V_211 == V_330 ) {
V_6 = V_216 . V_217 . V_213 [ V_331 ] ;
V_228 = V_216 . V_217 . V_213 [ V_332 ] ;
V_323 = (struct V_291 * ) V_216 . V_333 ;
} else
return 0 ;
if ( V_228 == V_322 )
goto V_334;
V_7 = F_72 ( V_229 , V_7 , V_323 , V_6 ) ;
return F_39 ( V_3 , V_170 , V_171 , V_229 , V_7 ) ;
V_334:
V_329 = V_216 . V_225 . V_246 ;
V_6 = V_329 ;
while ( V_7 < V_335 - V_323 -> V_302 ) {
V_7 = F_72 ( V_229 , V_7 , V_323 , V_6 ) ;
V_6 ++ ;
if ( V_6 > V_323 -> V_59 - 1 )
break;
}
if ( V_6 > V_323 -> V_59 - 1 )
V_6 = 0 ;
V_216 . V_225 . V_246 = V_6 ;
return F_39 ( V_3 , V_170 , V_171 , V_229 , V_7 ) ;
}
static T_2
F_74 ( struct V_149 * V_149 , const char T_3 * V_3 ,
T_4 V_170 , T_5 * V_171 )
{
struct V_151 * V_152 = V_149 -> V_157 ;
struct V_26 * V_27 = (struct V_26 * ) V_152 -> V_150 ;
T_1 V_336 , V_337 , V_338 , V_6 , V_228 , V_225 , V_247 ;
T_1 * V_325 ;
struct V_291 * V_323 ;
int V_153 ;
V_152 -> V_214 = V_215 ;
V_153 = F_50 ( V_3 , V_170 , & V_216 . V_217 ) ;
if ( V_153 < 0 )
return V_153 ;
V_337 = V_216 . V_217 . V_213 [ V_339 ] ;
V_338 = V_216 . V_217 . V_213 [ V_340 ] ;
V_6 = V_216 . V_217 . V_213 [ V_331 ] ;
V_228 = V_216 . V_217 . V_213 [ V_332 ] ;
V_225 = V_216 . V_217 . V_213 [ V_341 ] ;
V_247 = V_216 . V_217 . V_213 [ V_342 ] ;
if ( V_216 . V_217 . V_211 == V_221 ||
V_216 . V_217 . V_211 == V_222 ||
V_216 . V_217 . V_211 == V_223 ) {
if ( V_153 != V_343 )
goto V_249;
if ( V_228 != 1 )
goto V_249;
} else if ( V_216 . V_217 . V_211 == V_330 ) {
if ( V_153 != V_344 )
goto V_249;
} else
goto V_249;
switch ( V_337 ) {
case V_345 :
if ( V_27 -> V_265 . V_294 ) {
for ( V_336 = 0 ; V_336 < V_27 -> V_295 ;
V_336 ++ ) {
if ( V_27 -> V_265 . V_294 [ V_336 ] &&
V_27 -> V_265 . V_294 [ V_336 ] -> V_301 ==
V_338 ) {
V_153 = F_71 (
V_27 -> V_265 . V_294 [ V_336 ] ,
V_6 , V_228 ) ;
if ( V_153 )
goto V_249;
V_216 . V_333 =
V_27 -> V_265 . V_294 [ V_336 ] ;
goto V_346;
}
}
}
goto V_249;
break;
case V_347 :
if ( V_27 -> V_265 . V_311 &&
V_27 -> V_265 . V_311 -> V_301 == V_338 ) {
V_153 = F_71 (
V_27 -> V_265 . V_311 , V_6 , V_228 ) ;
if ( V_153 )
goto V_249;
V_216 . V_333 = V_27 -> V_265 . V_311 ;
goto V_346;
}
if ( V_27 -> V_265 . V_313 &&
V_27 -> V_265 . V_313 -> V_301 == V_338 ) {
V_153 = F_71 (
V_27 -> V_265 . V_313 , V_6 , V_228 ) ;
if ( V_153 )
goto V_249;
V_216 . V_333 = V_27 -> V_265 . V_313 ;
goto V_346;
}
if ( V_27 -> V_265 . V_307 ) {
V_336 = 0 ;
do {
if ( V_27 -> V_265 . V_307 [ V_336 ] &&
V_27 -> V_265 . V_307 [ V_336 ] -> V_301 ==
V_338 ) {
V_153 = F_71 (
V_27 -> V_265 . V_307 [ V_336 ] ,
V_6 , V_228 ) ;
if ( V_153 )
goto V_249;
V_216 . V_333 =
V_27 -> V_265 . V_307 [ V_336 ] ;
goto V_346;
}
} while ( ++ V_336 < V_27 -> V_295 );
}
goto V_249;
break;
case V_348 :
if ( V_27 -> V_265 . V_312 &&
V_27 -> V_265 . V_312 -> V_301 == V_338 ) {
V_153 = F_71 (
V_27 -> V_265 . V_312 , V_6 , V_228 ) ;
if ( V_153 )
goto V_249;
V_216 . V_333 = V_27 -> V_265 . V_312 ;
goto V_346;
}
goto V_249;
break;
case V_349 :
if ( V_27 -> V_265 . V_314 &&
V_27 -> V_265 . V_314 -> V_301 == V_338 ) {
V_153 = F_71 (
V_27 -> V_265 . V_314 , V_6 , V_228 ) ;
if ( V_153 )
goto V_249;
V_216 . V_333 = V_27 -> V_265 . V_314 ;
goto V_346;
}
if ( V_27 -> V_265 . V_310 ) {
for ( V_336 = 0 ; V_336 < V_27 -> V_295 ;
V_336 ++ ) {
if ( ! V_27 -> V_265 . V_310 [ V_336 ] )
continue;
if ( V_27 -> V_265 . V_310 [ V_336 ] -> V_301 ==
V_338 ) {
V_153 = F_71 (
V_27 -> V_265 . V_310 [ V_336 ] ,
V_6 , V_228 ) ;
if ( V_153 )
goto V_249;
V_216 . V_333 =
V_27 -> V_265 . V_310 [ V_336 ] ;
goto V_346;
}
}
}
goto V_249;
break;
case V_350 :
if ( V_27 -> V_265 . V_315 &&
V_27 -> V_265 . V_315 -> V_301 == V_338 ) {
V_153 = F_71 (
V_27 -> V_265 . V_315 , V_6 , V_228 ) ;
if ( V_153 )
goto V_249;
V_216 . V_333 = V_27 -> V_265 . V_315 ;
goto V_346;
}
if ( V_27 -> V_265 . V_316 &&
V_27 -> V_265 . V_316 -> V_301 == V_338 ) {
V_153 = F_71 (
V_27 -> V_265 . V_316 , V_6 , V_228 ) ;
if ( V_153 )
goto V_249;
V_216 . V_333 = V_27 -> V_265 . V_316 ;
goto V_346;
}
goto V_249;
break;
default:
goto V_249;
break;
}
V_346:
if ( V_216 . V_217 . V_211 == V_330 ) {
if ( V_228 == V_322 )
V_216 . V_225 . V_246 = V_6 ;
}
if ( V_216 . V_217 . V_211 == V_221 ||
V_216 . V_217 . V_211 == V_222 ||
V_216 . V_217 . V_211 == V_223 ) {
V_323 = (struct V_291 * ) V_216 . V_333 ;
if ( V_225 > V_323 -> V_302 / sizeof( T_1 ) - 1 )
goto V_249;
V_325 = V_323 -> V_327 [ V_6 ] . V_328 ;
V_325 += V_225 ;
if ( V_216 . V_217 . V_211 == V_221 )
* V_325 = V_247 ;
if ( V_216 . V_217 . V_211 == V_222 )
* V_325 |= V_247 ;
if ( V_216 . V_217 . V_211 == V_223 )
* V_325 &= ~ V_247 ;
}
return V_170 ;
V_249:
memset ( & V_216 , 0 , sizeof( V_216 ) ) ;
return - V_210 ;
}
static int
F_75 ( struct V_26 * V_27 , char * V_229 ,
int V_7 , T_1 V_351 )
{
if ( ! V_229 )
return 0 ;
switch ( V_351 ) {
case V_352 :
V_7 += snprintf ( V_229 + V_7 , V_353 - V_7 ,
L_97 ,
F_17 ( V_27 -> V_265 . V_354 ) ) ;
break;
case V_355 :
V_7 += snprintf ( V_229 + V_7 , V_353 - V_7 ,
L_98 ,
F_17 ( V_27 -> V_265 . V_356 ) ) ;
break;
case V_357 :
V_7 += snprintf ( V_229 + V_7 , V_353 - V_7 ,
L_99 ,
F_17 ( V_27 -> V_265 . V_358 ) ) ;
break;
case V_359 :
V_7 += snprintf ( V_229 + V_7 , V_353 - V_7 ,
L_100 ,
F_17 ( V_27 -> V_265 . V_360 ) ) ;
break;
default:
break;
}
return V_7 ;
}
static T_2
F_76 ( struct V_149 * V_149 , char T_3 * V_3 , T_4 V_170 ,
T_5 * V_171 )
{
struct V_151 * V_152 = V_149 -> V_157 ;
struct V_26 * V_27 = (struct V_26 * ) V_152 -> V_150 ;
T_1 V_361 , V_5 ;
char * V_229 ;
int V_7 = 0 ;
V_152 -> V_214 = V_236 ;
if ( ! V_152 -> V_12 )
V_152 -> V_12 = F_2 ( V_353 , V_14 ) ;
if ( ! V_152 -> V_12 )
return 0 ;
V_229 = V_152 -> V_12 ;
if ( * V_171 )
return 0 ;
if ( V_216 . V_217 . V_211 == V_362 )
V_361 = V_216 . V_217 . V_213 [ V_363 ] ;
else
return 0 ;
if ( V_361 == V_364 )
for ( V_5 = 1 ; V_5 <= V_365 ; V_5 ++ )
V_7 = F_75 ( V_27 ,
V_229 , V_7 , V_5 ) ;
else
V_7 = F_75 ( V_27 ,
V_229 , V_7 , V_361 ) ;
return F_39 ( V_3 , V_170 , V_171 , V_229 , V_7 ) ;
}
static T_2
F_77 ( struct V_149 * V_149 , const char T_3 * V_3 ,
T_4 V_170 , T_5 * V_171 )
{
struct V_151 * V_152 = V_149 -> V_157 ;
struct V_26 * V_27 = (struct V_26 * ) V_152 -> V_150 ;
T_1 V_361 , V_247 , V_366 = 0 ;
void T_8 * V_367 ;
int V_153 ;
V_152 -> V_214 = V_215 ;
V_153 = F_50 ( V_3 , V_170 , & V_216 . V_217 ) ;
if ( V_153 < 0 )
return V_153 ;
V_361 = V_216 . V_217 . V_213 [ V_363 ] ;
V_247 = V_216 . V_217 . V_213 [ V_368 ] ;
if ( V_216 . V_217 . V_211 == V_369 ||
V_216 . V_217 . V_211 == V_370 ||
V_216 . V_217 . V_211 == V_371 ) {
if ( V_153 != V_372 )
goto V_249;
if ( V_361 > V_365 )
goto V_249;
} else if ( V_216 . V_217 . V_211 == V_362 ) {
if ( V_153 != V_373 )
goto V_249;
if ( ( V_361 > V_365 ) &&
( V_361 != V_364 ) )
goto V_249;
} else
goto V_249;
if ( V_216 . V_217 . V_211 == V_369 ||
V_216 . V_217 . V_211 == V_370 ||
V_216 . V_217 . V_211 == V_371 ) {
switch ( V_361 ) {
case V_352 :
V_367 = V_27 -> V_265 . V_354 ;
break;
case V_355 :
V_367 = V_27 -> V_265 . V_356 ;
break;
case V_357 :
V_367 = V_27 -> V_265 . V_358 ;
break;
case V_359 :
V_367 = V_27 -> V_265 . V_360 ;
break;
default:
goto V_249;
}
if ( V_216 . V_217 . V_211 == V_369 )
V_366 = V_247 ;
if ( V_216 . V_217 . V_211 == V_370 ) {
V_366 = F_17 ( V_367 ) ;
V_366 |= V_247 ;
}
if ( V_216 . V_217 . V_211 == V_371 ) {
V_366 = F_17 ( V_367 ) ;
V_366 &= ~ V_247 ;
}
F_69 ( V_366 , V_367 ) ;
F_17 ( V_367 ) ;
}
return V_170 ;
V_249:
memset ( & V_216 , 0 , sizeof( V_216 ) ) ;
return - V_210 ;
}
static int
F_78 ( struct V_26 * V_27 , char * V_229 ,
int V_7 , T_1 V_374 )
{
if ( ! V_229 )
return 0 ;
switch ( V_374 ) {
case V_375 :
V_7 += snprintf ( V_229 + V_7 , V_376 - V_7 ,
L_101 ,
F_17 ( V_27 -> V_265 . V_269 +
V_377 ) ) ;
break;
case V_378 :
V_7 += snprintf ( V_229 + V_7 , V_376 - V_7 ,
L_102 ,
F_17 ( V_27 -> V_265 . V_269 +
V_379 ) ) ;
break;
case V_380 :
V_7 += snprintf ( V_229 + V_7 , V_376 - V_7 ,
L_103 ,
F_17 ( V_27 -> V_265 . V_269 +
V_381 ) ) ;
break;
case V_382 :
V_7 += snprintf ( V_229 + V_7 , V_376 - V_7 ,
L_104 ,
F_17 ( V_27 -> V_265 . V_269 +
V_383 ) ) ;
break;
case V_384 :
V_7 += snprintf ( V_229 + V_7 , V_376 - V_7 ,
L_105 ,
F_17 ( V_27 -> V_265 . V_269 +
V_385 ) ) ;
break;
case V_386 :
V_7 += snprintf ( V_229 + V_7 , V_376 - V_7 ,
L_106 ,
F_17 ( V_27 -> V_265 . V_269 +
V_387 ) ) ;
break;
default:
break;
}
return V_7 ;
}
static T_2
F_79 ( struct V_149 * V_149 , char T_3 * V_3 , T_4 V_170 ,
T_5 * V_171 )
{
struct V_151 * V_152 = V_149 -> V_157 ;
struct V_26 * V_27 = (struct V_26 * ) V_152 -> V_150 ;
T_1 V_388 , V_5 ;
char * V_229 ;
int V_7 = 0 ;
V_152 -> V_214 = V_236 ;
if ( ! V_152 -> V_12 )
V_152 -> V_12 = F_2 ( V_376 , V_14 ) ;
if ( ! V_152 -> V_12 )
return 0 ;
V_229 = V_152 -> V_12 ;
if ( * V_171 )
return 0 ;
if ( V_216 . V_217 . V_211 == V_389 )
V_388 = V_216 . V_217 . V_213 [ V_390 ] ;
else
return 0 ;
if ( V_388 == V_391 )
for ( V_5 = 1 ; V_5 <= V_392 ; V_5 ++ )
V_7 = F_78 ( V_27 ,
V_229 , V_7 , V_5 ) ;
else
V_7 = F_78 ( V_27 ,
V_229 , V_7 , V_388 ) ;
return F_39 ( V_3 , V_170 , V_171 , V_229 , V_7 ) ;
}
static T_2
F_80 ( struct V_149 * V_149 , const char T_3 * V_3 ,
T_4 V_170 , T_5 * V_171 )
{
struct V_151 * V_152 = V_149 -> V_157 ;
struct V_26 * V_27 = (struct V_26 * ) V_152 -> V_150 ;
T_1 V_388 , V_247 , V_366 = 0 ;
void T_8 * V_393 ;
int V_153 ;
V_152 -> V_214 = V_215 ;
V_153 = F_50 ( V_3 , V_170 , & V_216 . V_217 ) ;
if ( V_153 < 0 )
return V_153 ;
V_388 = V_216 . V_217 . V_213 [ V_390 ] ;
V_247 = V_216 . V_217 . V_213 [ V_394 ] ;
if ( V_216 . V_217 . V_211 == V_395 ||
V_216 . V_217 . V_211 == V_396 ||
V_216 . V_217 . V_211 == V_397 ) {
if ( V_153 != V_398 )
goto V_249;
if ( V_388 > V_392 )
goto V_249;
} else if ( V_216 . V_217 . V_211 == V_389 ) {
if ( V_153 != V_399 )
goto V_249;
if ( ( V_388 > V_392 ) &&
( V_388 != V_391 ) )
goto V_249;
} else
goto V_249;
if ( V_216 . V_217 . V_211 == V_395 ||
V_216 . V_217 . V_211 == V_396 ||
V_216 . V_217 . V_211 == V_397 ) {
switch ( V_388 ) {
case V_375 :
V_393 = V_27 -> V_265 . V_269 +
V_377 ;
break;
case V_378 :
V_393 = V_27 -> V_265 . V_269 +
V_379 ;
break;
case V_380 :
V_393 = V_27 -> V_265 . V_269 +
V_381 ;
break;
case V_382 :
V_393 = V_27 -> V_265 . V_269 +
V_383 ;
break;
case V_384 :
V_393 = V_27 -> V_265 . V_269 +
V_385 ;
break;
case V_386 :
V_393 = V_27 -> V_265 . V_269 +
V_387 ;
break;
default:
goto V_249;
}
if ( V_216 . V_217 . V_211 == V_395 )
V_366 = V_247 ;
if ( V_216 . V_217 . V_211 == V_396 ) {
V_366 = F_17 ( V_393 ) ;
V_366 |= V_247 ;
}
if ( V_216 . V_217 . V_211 == V_397 ) {
V_366 = F_17 ( V_393 ) ;
V_366 &= ~ V_247 ;
}
F_69 ( V_366 , V_393 ) ;
F_17 ( V_393 ) ;
}
return V_170 ;
V_249:
memset ( & V_216 , 0 , sizeof( V_216 ) ) ;
return - V_210 ;
}
static int
F_81 ( struct V_26 * V_27 , char * V_229 )
{
T_1 V_400 , V_401 , V_402 , V_403 ;
int V_7 = 0 ;
V_403 = V_216 . V_217 . V_213 [ V_404 ] ;
V_400 = V_216 . V_217 . V_213 [ V_405 ] ;
V_401 = V_216 . V_217 . V_213 [ V_406 ] ;
V_402 = V_216 . V_217 . V_213 [ V_407 ] ;
V_7 += snprintf ( V_229 + V_7 , V_408 - V_7 ,
L_107 , V_400 ) ;
V_7 += snprintf ( V_229 + V_7 , V_408 - V_7 ,
L_108 , V_401 ) ;
V_7 += snprintf ( V_229 + V_7 , V_408 - V_7 ,
L_109 , V_402 ) ;
V_7 += snprintf ( V_229 + V_7 , V_408 - V_7 ,
L_110 , V_403 ) ;
return V_7 ;
}
static T_2
F_82 ( struct V_149 * V_149 , char T_3 * V_3 , T_4 V_170 ,
T_5 * V_171 )
{
struct V_151 * V_152 = V_149 -> V_157 ;
struct V_26 * V_27 = (struct V_26 * ) V_152 -> V_150 ;
char * V_229 ;
int V_7 = 0 ;
V_152 -> V_214 = V_236 ;
if ( ! V_152 -> V_12 )
V_152 -> V_12 = F_2 ( V_408 , V_14 ) ;
if ( ! V_152 -> V_12 )
return 0 ;
V_229 = V_152 -> V_12 ;
if ( * V_171 )
return 0 ;
if ( ( V_216 . V_217 . V_211 != V_409 ) &&
( V_216 . V_217 . V_211 != V_410 ) )
return 0 ;
V_7 = F_81 ( V_27 , V_229 ) ;
return F_39 ( V_3 , V_170 , V_171 , V_229 , V_7 ) ;
}
static T_2
F_83 ( struct V_149 * V_149 , const char T_3 * V_3 ,
T_4 V_170 , T_5 * V_171 )
{
struct V_151 * V_152 = V_149 -> V_157 ;
T_1 V_400 , V_401 , V_402 , V_403 ;
int V_153 ;
V_152 -> V_214 = V_215 ;
V_153 = F_50 ( V_3 , V_170 , & V_216 . V_217 ) ;
if ( V_153 < 0 )
return V_153 ;
V_403 = V_216 . V_217 . V_213 [ V_404 ] ;
V_400 = V_216 . V_217 . V_213 [ V_405 ] ;
V_401 = V_216 . V_217 . V_213 [ V_406 ] ;
V_402 = V_216 . V_217 . V_213 [ V_407 ] ;
if ( V_216 . V_217 . V_211 == V_409 ) {
if ( ! ( V_400 & V_411 ) )
goto V_249;
if ( ( V_400 & ~ V_411 ) &&
( V_400 != V_412 ) )
goto V_249;
if ( V_402 > sizeof( V_91 ) )
goto V_249;
} else if ( V_216 . V_217 . V_211 == V_410 ) {
if ( ! ( V_400 & V_413 ) )
goto V_249;
if ( ( V_400 & ~ V_413 ) &&
( V_400 != V_412 ) )
goto V_249;
if ( V_402 > ( V_414 ) / 4 )
goto V_249;
if ( V_403 != 0x9b )
goto V_249;
} else
goto V_249;
if ( V_402 == 0 )
goto V_249;
if ( V_153 != V_415 )
goto V_249;
if ( V_403 & ~ 0xff )
goto V_249;
if ( V_401 == 0 )
goto V_416;
return V_170 ;
V_416:
memset ( & V_216 , 0 , sizeof( V_216 ) ) ;
return V_170 ;
V_249:
memset ( & V_216 , 0 , sizeof( V_216 ) ) ;
return - V_210 ;
}
static int
F_84 ( struct V_26 * V_27 , char * V_229 , int V_7 )
{
T_6 V_417 , V_418 ;
V_7 += snprintf ( V_229 + V_7 , V_419 - V_7 ,
L_111 ) ;
V_7 += snprintf ( V_229 + V_7 , V_419 - V_7 ,
L_112 ) ;
F_85 ( V_27 , V_420 ,
& V_417 , & V_418 ) ;
V_7 += snprintf ( V_229 + V_7 , V_419 - V_7 ,
L_113 , V_417 , V_418 ) ;
V_7 += snprintf ( V_229 + V_7 , V_419 - V_7 ,
L_114 ) ;
F_85 ( V_27 , V_421 ,
& V_417 , & V_418 ) ;
V_7 += snprintf ( V_229 + V_7 , V_419 - V_7 ,
L_113 , V_417 , V_418 ) ;
V_7 += snprintf ( V_229 + V_7 , V_419 - V_7 ,
L_115 ) ;
F_85 ( V_27 , V_422 ,
& V_417 , & V_418 ) ;
V_7 += snprintf ( V_229 + V_7 , V_419 - V_7 ,
L_113 , V_417 , V_418 ) ;
V_7 += snprintf ( V_229 + V_7 , V_419 - V_7 ,
L_116 ) ;
F_85 ( V_27 , V_423 ,
& V_417 , & V_418 ) ;
V_7 += snprintf ( V_229 + V_7 , V_419 - V_7 ,
L_113 , V_417 , V_418 ) ;
return V_7 ;
}
static int
F_86 ( struct V_26 * V_27 , char * V_229 , int V_7 )
{
T_6 V_417 , V_418 ;
int V_153 ;
V_7 += snprintf ( V_229 + V_7 , V_419 - V_7 ,
L_117 ) ;
V_7 += snprintf ( V_229 + V_7 , V_419 - V_7 ,
L_118 ) ;
V_153 = F_87 ( V_27 , V_420 ,
& V_417 , & V_418 ) ;
if ( ! V_153 )
V_7 += snprintf ( V_229 + V_7 , V_419 - V_7 ,
L_119 ,
V_27 -> V_424 , V_417 , V_418 ) ;
else
V_7 += snprintf ( V_229 + V_7 , V_419 - V_7 ,
L_120 ) ;
V_7 += snprintf ( V_229 + V_7 , V_419 - V_7 ,
L_121 ) ;
V_153 = F_87 ( V_27 , V_421 ,
& V_417 , & V_418 ) ;
if ( ! V_153 )
V_7 += snprintf ( V_229 + V_7 , V_419 - V_7 ,
L_119 ,
V_27 -> V_424 , V_417 , V_418 ) ;
else
V_7 += snprintf ( V_229 + V_7 , V_419 - V_7 ,
L_120 ) ;
V_7 += snprintf ( V_229 + V_7 , V_419 - V_7 ,
L_122 ) ;
V_153 = F_87 ( V_27 , V_422 ,
& V_417 , & V_418 ) ;
if ( ! V_153 )
V_7 += snprintf ( V_229 + V_7 , V_419 - V_7 ,
L_119 ,
V_27 -> V_424 , V_417 , V_418 ) ;
else
V_7 += snprintf ( V_229 + V_7 , V_419 - V_7 ,
L_120 ) ;
V_7 += snprintf ( V_229 + V_7 , V_419 - V_7 ,
L_123 ) ;
V_153 = F_87 ( V_27 , V_423 ,
& V_417 , & V_418 ) ;
if ( ! V_153 )
V_7 += snprintf ( V_229 + V_7 , V_419 - V_7 ,
L_119 ,
V_27 -> V_424 , V_417 , V_418 ) ;
else
V_7 += snprintf ( V_229 + V_7 , V_419 - V_7 ,
L_120 ) ;
return V_7 ;
}
static int
F_88 ( struct V_26 * V_27 , char * V_229 , int V_7 )
{
struct V_425 * V_426 ;
int V_6 ;
V_7 += snprintf ( V_229 + V_7 , V_419 - V_7 ,
L_124 ) ;
V_7 += snprintf ( V_229 + V_7 , V_419 - V_7 ,
L_125 ) ;
V_6 = 0 ;
F_10 (rsrc_blks, &phba->lpfc_vpi_blk_list, list) {
V_7 += snprintf ( V_229 + V_7 , V_419 - V_7 ,
L_126 ,
V_6 , V_426 -> V_427 ,
V_426 -> V_428 ) ;
V_6 ++ ;
}
V_7 += snprintf ( V_229 + V_7 , V_419 - V_7 ,
L_127 ) ;
V_6 = 0 ;
F_10 (rsrc_blks, &phba->sli4_hba.lpfc_vfi_blk_list,
list) {
V_7 += snprintf ( V_229 + V_7 , V_419 - V_7 ,
L_126 ,
V_6 , V_426 -> V_427 ,
V_426 -> V_428 ) ;
V_6 ++ ;
}
V_7 += snprintf ( V_229 + V_7 , V_419 - V_7 ,
L_128 ) ;
V_6 = 0 ;
F_10 (rsrc_blks, &phba->sli4_hba.lpfc_rpi_blk_list,
list) {
V_7 += snprintf ( V_229 + V_7 , V_419 - V_7 ,
L_126 ,
V_6 , V_426 -> V_427 ,
V_426 -> V_428 ) ;
V_6 ++ ;
}
V_7 += snprintf ( V_229 + V_7 , V_419 - V_7 ,
L_129 ) ;
V_6 = 0 ;
F_10 (rsrc_blks, &phba->sli4_hba.lpfc_xri_blk_list,
list) {
V_7 += snprintf ( V_229 + V_7 , V_419 - V_7 ,
L_126 ,
V_6 , V_426 -> V_427 ,
V_426 -> V_428 ) ;
V_6 ++ ;
}
return V_7 ;
}
static T_2
F_89 ( struct V_149 * V_149 , const char T_3 * V_3 ,
T_4 V_170 , T_5 * V_171 )
{
struct V_151 * V_152 = V_149 -> V_157 ;
T_1 V_429 ;
int V_153 ;
V_152 -> V_214 = V_215 ;
V_153 = F_50 ( V_3 , V_170 , & V_216 . V_217 ) ;
if ( V_153 < 0 )
return V_153 ;
V_429 = V_216 . V_217 . V_213 [ V_430 ] ;
if ( V_216 . V_217 . V_211 != V_431 )
goto V_249;
if ( V_153 != V_432 )
goto V_249;
if ( ! ( V_429 & V_433 ) )
goto V_249;
return V_170 ;
V_249:
memset ( & V_216 , 0 , sizeof( V_216 ) ) ;
return - V_210 ;
}
static T_2
F_90 ( struct V_149 * V_149 , char T_3 * V_3 , T_4 V_170 ,
T_5 * V_171 )
{
struct V_151 * V_152 = V_149 -> V_157 ;
struct V_26 * V_27 = (struct V_26 * ) V_152 -> V_150 ;
char * V_229 ;
T_1 V_429 ;
int V_7 = 0 ;
V_152 -> V_214 = V_236 ;
if ( ! V_152 -> V_12 )
V_152 -> V_12 = F_2 ( V_419 , V_14 ) ;
if ( ! V_152 -> V_12 )
return 0 ;
V_229 = V_152 -> V_12 ;
if ( * V_171 )
return 0 ;
if ( V_216 . V_217 . V_211 != V_431 )
return 0 ;
V_429 = V_216 . V_217 . V_213 [ V_430 ] ;
if ( V_429 & V_434 )
V_7 = F_84 ( V_27 , V_229 , V_7 ) ;
if ( V_429 & V_435 )
V_7 = F_86 ( V_27 , V_229 , V_7 ) ;
if ( V_429 & V_436 )
V_7 = F_88 ( V_27 , V_229 , V_7 ) ;
return F_39 ( V_3 , V_170 , V_171 , V_229 , V_7 ) ;
}
void
F_91 ( struct V_26 * V_27 , enum V_437 V_438 ,
enum V_439 V_440 , enum V_441 V_442 ,
enum V_443 V_444 ,
struct V_44 * V_445 , T_1 V_446 )
{
#ifdef F_21
T_1 * V_403 , * V_400 , * V_401 , * V_402 ;
char V_447 [ V_448 ] ;
int V_7 = 0 ;
T_1 V_449 = 0 ;
T_1 * V_450 ;
T_1 V_5 ;
if ( V_216 . V_217 . V_211 != V_410 )
return;
V_403 = & V_216 . V_217 . V_213 [ V_404 ] ;
V_400 = & V_216 . V_217 . V_213 [ V_405 ] ;
V_401 = & V_216 . V_217 . V_213 [ V_406 ] ;
V_402 = & V_216 . V_217 . V_213 [ V_407 ] ;
if ( ! ( * V_400 & V_412 ) ||
( * V_401 == 0 ) ||
( * V_402 == 0 ) )
return;
if ( * V_403 != 0x9B )
return;
if ( ( V_440 == V_451 ) && ( V_442 == V_452 ) ) {
if ( * V_400 & V_453 ) {
V_449 |= V_453 ;
F_31 ( V_162 L_130
L_131 ,
V_444 , V_438 , V_446 ) ;
}
}
if ( ( V_440 == V_451 ) && ( V_442 == V_454 ) ) {
if ( * V_400 & V_455 ) {
V_449 |= V_455 ;
F_31 ( V_162 L_132
L_133 ,
V_444 , V_438 , V_446 ) ;
}
}
if ( ( V_440 == V_456 ) && ( V_442 == V_452 ) ) {
if ( * V_400 & V_457 ) {
V_449 |= V_457 ;
F_31 ( V_162 L_134
L_131 ,
V_444 , V_438 , V_446 ) ;
}
}
if ( ( V_440 == V_456 ) && ( V_442 == V_454 ) ) {
if ( * V_400 & V_458 ) {
V_449 |= V_458 ;
F_31 ( V_162 L_135
L_133 ,
V_444 , V_438 , V_446 ) ;
}
}
if ( V_449 ) {
V_450 = ( T_1 * ) V_445 -> V_72 ;
for ( V_5 = 0 ; V_5 < * V_402 ; V_5 ++ ) {
if ( ! ( V_5 % 8 ) ) {
if ( V_5 != 0 )
F_31 ( V_162 L_136 , V_447 ) ;
V_7 = 0 ;
V_7 += snprintf ( V_447 + V_7 ,
V_448 - V_7 ,
L_137 , V_5 ) ;
}
V_7 += snprintf ( V_447 + V_7 , V_448 - V_7 ,
L_56 , ( T_1 ) * V_450 ) ;
V_450 ++ ;
}
if ( ( V_5 - 1 ) % 8 )
F_31 ( V_162 L_136 , V_447 ) ;
( * V_401 ) -- ;
}
if ( * V_401 == 0 )
memset ( & V_216 , 0 , sizeof( V_216 ) ) ;
return;
#endif
}
void
F_92 ( struct V_26 * V_27 , V_91 * V_459 )
{
#ifdef F_21
T_1 * V_400 , * V_401 , * V_402 , * V_403 ;
char V_447 [ V_448 ] ;
int V_7 = 0 ;
T_1 * V_450 ;
T_7 * V_460 ;
T_1 V_5 , V_31 ;
if ( V_216 . V_217 . V_211 != V_409 )
return;
V_403 = & V_216 . V_217 . V_213 [ V_404 ] ;
V_400 = & V_216 . V_217 . V_213 [ V_405 ] ;
V_401 = & V_216 . V_217 . V_213 [ V_406 ] ;
V_402 = & V_216 . V_217 . V_213 [ V_407 ] ;
if ( ! ( * V_400 & V_411 ) ||
( * V_401 == 0 ) ||
( * V_402 == 0 ) )
return;
if ( ( * V_403 != V_461 ) &&
( * V_403 != V_459 -> V_462 ) )
return;
if ( * V_400 & V_463 ) {
F_31 ( V_162 L_138 ,
V_459 -> V_462 ) ;
V_450 = ( T_1 * ) V_459 ;
for ( V_5 = 0 ; V_5 < * V_402 ; V_5 ++ ) {
if ( ! ( V_5 % 8 ) ) {
if ( V_5 != 0 )
F_31 ( V_162 L_136 , V_447 ) ;
V_7 = 0 ;
memset ( V_447 , 0 , V_448 ) ;
V_7 += snprintf ( V_447 + V_7 ,
V_448 - V_7 ,
L_137 , V_5 ) ;
}
V_7 += snprintf ( V_447 + V_7 , V_448 - V_7 ,
L_56 ,
( ( T_1 ) * V_450 ) & 0xffffffff ) ;
V_450 ++ ;
}
if ( ( V_5 - 1 ) % 8 )
F_31 ( V_162 L_136 , V_447 ) ;
F_31 ( V_162 L_41 ) ;
}
if ( * V_400 & V_464 ) {
F_31 ( V_162 L_139 ,
V_459 -> V_462 ) ;
V_460 = ( T_7 * ) V_459 ;
for ( V_5 = 0 ; V_5 < * V_402 ; V_5 ++ ) {
if ( ! ( V_5 % 8 ) ) {
if ( V_5 != 0 )
F_31 ( V_162 L_136 , V_447 ) ;
V_7 = 0 ;
memset ( V_447 , 0 , V_448 ) ;
V_7 += snprintf ( V_447 + V_7 ,
V_448 - V_7 ,
L_137 , V_5 ) ;
}
for ( V_31 = 0 ; V_31 < 4 ; V_31 ++ ) {
V_7 += snprintf ( V_447 + V_7 ,
V_448 - V_7 ,
L_140 ,
( ( T_7 ) * V_460 ) & 0xff ) ;
V_460 ++ ;
}
V_7 += snprintf ( V_447 + V_7 ,
V_448 - V_7 , L_141 ) ;
}
if ( ( V_5 - 1 ) % 8 )
F_31 ( V_162 L_136 , V_447 ) ;
F_31 ( V_162 L_41 ) ;
}
( * V_401 ) -- ;
if ( * V_401 == 0 )
memset ( & V_216 , 0 , sizeof( V_216 ) ) ;
return;
#endif
}
inline void
F_93 ( struct V_1 * V_2 )
{
#ifdef F_21
struct V_26 * V_27 = V_2 -> V_27 ;
char V_115 [ 64 ] ;
T_1 V_465 , V_5 ;
bool V_466 = false ;
if ( ! V_15 )
return;
if ( ! V_467 ) {
V_467 = F_94 ( L_142 , NULL ) ;
F_95 ( & V_468 , 0 ) ;
if ( ! V_467 ) {
F_96 ( V_2 , V_162 , V_198 ,
L_143 ) ;
goto V_469;
}
}
if ( ! V_21 )
V_21 = V_147 ;
snprintf ( V_115 , sizeof( V_115 ) , L_144 , V_27 -> V_424 ) ;
if ( ! V_27 -> V_470 ) {
V_466 = true ;
V_27 -> V_470 =
F_94 ( V_115 , V_467 ) ;
if ( ! V_27 -> V_470 ) {
F_96 ( V_2 , V_162 , V_198 ,
L_145 ) ;
goto V_469;
}
F_97 ( & V_468 ) ;
F_95 ( & V_27 -> V_471 , 0 ) ;
snprintf ( V_115 , sizeof( V_115 ) , L_146 ) ;
V_27 -> V_472 =
F_98 ( V_115 , V_473 | V_474 | V_475 ,
V_27 -> V_470 ,
V_27 , & V_476 ) ;
if ( ! V_27 -> V_472 ) {
F_96 ( V_2 , V_162 , V_198 ,
L_147 ) ;
goto V_469;
}
if ( V_27 -> V_48 < V_477 ) {
snprintf ( V_115 , sizeof( V_115 ) , L_148 ) ;
V_27 -> V_478 =
F_98 ( V_115 ,
V_473 | V_474 | V_475 ,
V_27 -> V_470 ,
V_27 , & V_479 ) ;
if ( ! V_27 -> V_478 ) {
F_96 ( V_2 , V_162 , V_198 ,
L_149
L_150 ) ;
goto V_469;
}
} else
V_27 -> V_478 = NULL ;
if ( V_27 -> V_48 < V_477 ) {
snprintf ( V_115 , sizeof( V_115 ) , L_151 ) ;
V_27 -> V_480 =
F_98 ( V_115 ,
V_473 | V_474 | V_475 ,
V_27 -> V_470 ,
V_27 , & V_481 ) ;
if ( ! V_27 -> V_480 ) {
F_96 ( V_2 , V_162 , V_198 ,
L_152
L_153 ) ;
goto V_469;
}
} else
V_27 -> V_480 = NULL ;
snprintf ( V_115 , sizeof( V_115 ) , L_154 ) ;
V_27 -> V_482 =
F_98 ( V_115 , V_473 | V_474 | V_475 ,
V_27 -> V_470 ,
V_27 , & V_483 ) ;
if ( ! V_27 -> V_482 ) {
F_96 ( V_2 , V_162 , V_198 ,
L_155 ) ;
goto V_469;
}
snprintf ( V_115 , sizeof( V_115 ) , L_156 ) ;
V_27 -> V_484 =
F_98 ( V_115 , V_473 | V_474 | V_475 ,
V_27 -> V_470 ,
V_27 , & V_485 ) ;
if ( ! V_27 -> V_484 ) {
F_96 ( V_2 , V_162 , V_198 ,
L_157 ) ;
goto V_469;
}
snprintf ( V_115 , sizeof( V_115 ) , L_158 ) ;
V_27 -> V_195 =
F_98 ( V_115 , V_473 | V_474 | V_475 ,
V_27 -> V_470 ,
V_27 , & V_486 ) ;
if ( ! V_27 -> V_195 ) {
F_96 ( V_2 , V_162 , V_198 ,
L_159 ) ;
goto V_469;
}
V_27 -> V_196 = V_487 ;
snprintf ( V_115 , sizeof( V_115 ) , L_160 ) ;
V_27 -> V_190 =
F_98 ( V_115 , V_473 | V_474 | V_475 ,
V_27 -> V_470 ,
V_27 , & V_486 ) ;
if ( ! V_27 -> V_190 ) {
F_96 ( V_2 , V_162 , V_198 ,
L_161 ) ;
goto V_469;
}
snprintf ( V_115 , sizeof( V_115 ) , L_162 ) ;
V_27 -> V_192 =
F_98 ( V_115 , V_473 | V_474 | V_475 ,
V_27 -> V_470 ,
V_27 , & V_486 ) ;
if ( ! V_27 -> V_192 ) {
F_96 ( V_2 , V_162 , V_198 ,
L_163 ) ;
goto V_469;
}
snprintf ( V_115 , sizeof( V_115 ) , L_164 ) ;
V_27 -> V_178 =
F_98 ( V_115 , V_473 | V_474 | V_475 ,
V_27 -> V_470 ,
V_27 , & V_486 ) ;
if ( ! V_27 -> V_178 ) {
F_96 ( V_2 , V_162 , V_198 ,
L_165 ) ;
goto V_469;
}
snprintf ( V_115 , sizeof( V_115 ) , L_166 ) ;
V_27 -> V_180 =
F_98 ( V_115 , V_473 | V_474 | V_475 ,
V_27 -> V_470 ,
V_27 , & V_486 ) ;
if ( ! V_27 -> V_180 ) {
F_96 ( V_2 , V_162 , V_198 ,
L_167 ) ;
goto V_469;
}
snprintf ( V_115 , sizeof( V_115 ) , L_168 ) ;
V_27 -> V_182 =
F_98 ( V_115 , V_473 | V_474 | V_475 ,
V_27 -> V_470 ,
V_27 , & V_486 ) ;
if ( ! V_27 -> V_182 ) {
F_96 ( V_2 , V_162 , V_198 ,
L_169 ) ;
goto V_469;
}
snprintf ( V_115 , sizeof( V_115 ) , L_170 ) ;
V_27 -> V_184 =
F_98 ( V_115 , V_473 | V_474 | V_475 ,
V_27 -> V_470 ,
V_27 , & V_486 ) ;
if ( ! V_27 -> V_184 ) {
F_96 ( V_2 , V_162 , V_198 ,
L_171 ) ;
goto V_469;
}
snprintf ( V_115 , sizeof( V_115 ) , L_172 ) ;
V_27 -> V_186 =
F_98 ( V_115 , V_473 | V_474 | V_475 ,
V_27 -> V_470 ,
V_27 , & V_486 ) ;
if ( ! V_27 -> V_186 ) {
F_96 ( V_2 , V_162 , V_198 ,
L_173 ) ;
goto V_469;
}
snprintf ( V_115 , sizeof( V_115 ) , L_174 ) ;
V_27 -> V_188 =
F_98 ( V_115 , V_473 | V_474 | V_475 ,
V_27 -> V_470 ,
V_27 , & V_486 ) ;
if ( ! V_27 -> V_188 ) {
F_96 ( V_2 , V_162 , V_198 ,
L_175 ) ;
goto V_469;
}
if ( V_29 ) {
V_465 = V_29 - 1 ;
if ( V_465 & V_29 ) {
V_465 = V_29 ;
V_5 = 0 ;
while ( V_465 > 1 ) {
V_465 = V_465 >> 1 ;
V_5 ++ ;
}
V_29 = ( 1 << V_5 ) ;
F_31 ( V_162
L_176
L_177 , V_17 ) ;
}
}
snprintf ( V_115 , sizeof( V_115 ) , L_178 ) ;
V_27 -> V_488 =
F_98 ( V_115 , V_473 | V_474 | V_475 ,
V_27 -> V_470 ,
V_27 , & V_489 ) ;
if ( ! V_27 -> V_488 ) {
F_96 ( V_2 , V_162 , V_198 ,
L_179
L_180 ) ;
goto V_469;
}
if ( ! V_27 -> V_30 ) {
V_27 -> V_30 = F_2 (
( sizeof( struct V_10 ) *
V_29 ) ,
V_14 ) ;
if ( ! V_27 -> V_30 ) {
F_96 ( V_2 , V_162 , V_198 ,
L_181
L_182 ) ;
goto V_469;
}
F_95 ( & V_27 -> V_28 , 0 ) ;
memset ( V_27 -> V_30 , 0 ,
( sizeof( struct V_10 ) *
V_29 ) ) ;
}
}
snprintf ( V_115 , sizeof( V_115 ) , L_183 , V_2 -> V_490 ) ;
if ( ! V_2 -> V_491 ) {
V_2 -> V_491 =
F_94 ( V_115 , V_27 -> V_470 ) ;
if ( ! V_2 -> V_491 ) {
F_96 ( V_2 , V_162 , V_198 ,
L_184 ) ;
goto V_469;
}
F_97 ( & V_27 -> V_471 ) ;
}
if ( V_17 ) {
V_465 = V_17 - 1 ;
if ( V_465 & V_17 ) {
V_465 = V_17 ;
V_5 = 0 ;
while ( V_465 > 1 ) {
V_465 = V_465 >> 1 ;
V_5 ++ ;
}
V_17 = ( 1 << V_5 ) ;
F_31 ( V_162
L_185 ,
V_17 ) ;
}
}
V_2 -> V_18 = F_99 (
( sizeof( struct V_10 ) * V_17 ) ,
V_14 ) ;
if ( ! V_2 -> V_18 ) {
F_96 ( V_2 , V_162 , V_198 ,
L_186
L_187 ) ;
goto V_469;
}
F_95 ( & V_2 -> V_16 , 0 ) ;
snprintf ( V_115 , sizeof( V_115 ) , L_188 ) ;
V_2 -> V_492 =
F_98 ( V_115 , V_473 | V_474 | V_475 ,
V_2 -> V_491 ,
V_2 , & V_493 ) ;
if ( ! V_2 -> V_492 ) {
F_96 ( V_2 , V_162 , V_198 ,
L_189
L_190 ) ;
goto V_469;
}
snprintf ( V_115 , sizeof( V_115 ) , L_191 ) ;
V_2 -> V_494 =
F_98 ( V_115 , V_473 | V_474 | V_475 ,
V_2 -> V_491 ,
V_2 , & V_495 ) ;
if ( ! V_2 -> V_494 ) {
F_96 ( V_2 , V_162 , V_198 ,
L_192 ) ;
goto V_469;
}
if ( ! V_466 )
goto V_469;
if ( V_27 -> V_48 < V_477 )
goto V_469;
snprintf ( V_115 , sizeof( V_115 ) , L_193 ) ;
if ( ! V_27 -> V_496 ) {
V_27 -> V_496 =
F_94 ( V_115 , V_27 -> V_470 ) ;
if ( ! V_27 -> V_496 ) {
F_96 ( V_2 , V_162 , V_198 ,
L_194 ) ;
goto V_469;
}
memset ( & V_216 , 0 , sizeof( V_216 ) ) ;
}
snprintf ( V_115 , sizeof( V_115 ) , L_195 ) ;
if ( ! V_27 -> V_497 ) {
V_27 -> V_497 =
F_98 ( V_115 , V_473 | V_474 | V_475 ,
V_27 -> V_496 , V_27 , & V_498 ) ;
if ( ! V_27 -> V_497 ) {
F_96 ( V_2 , V_162 , V_198 ,
L_196 ) ;
goto V_469;
}
V_216 . V_225 . V_246 = 0 ;
}
snprintf ( V_115 , sizeof( V_115 ) , L_197 ) ;
if ( ! V_27 -> V_499 ) {
V_27 -> V_499 =
F_98 ( V_115 , V_473 | V_474 | V_475 ,
V_27 -> V_496 , V_27 , & V_500 ) ;
if ( ! V_27 -> V_499 ) {
F_96 ( V_2 , V_162 , V_198 ,
L_198 ) ;
goto V_469;
}
V_216 . V_225 . V_246 = 0 ;
}
snprintf ( V_115 , sizeof( V_115 ) , L_199 ) ;
if ( ! V_27 -> V_501 ) {
V_27 -> V_501 =
F_98 ( V_115 , V_473 | V_474 ,
V_27 -> V_496 , V_27 , & V_502 ) ;
if ( ! V_27 -> V_501 ) {
F_96 ( V_2 , V_162 , V_198 ,
L_200 ) ;
goto V_469;
}
}
snprintf ( V_115 , sizeof( V_115 ) , L_201 ) ;
if ( ! V_27 -> V_503 ) {
V_27 -> V_503 =
F_98 ( V_115 , V_473 | V_474 | V_475 ,
V_27 -> V_496 , V_27 , & V_504 ) ;
if ( ! V_27 -> V_503 ) {
F_96 ( V_2 , V_162 , V_198 ,
L_202 ) ;
goto V_469;
}
}
snprintf ( V_115 , sizeof( V_115 ) , L_203 ) ;
if ( ! V_27 -> V_505 ) {
V_27 -> V_505 =
F_98 ( V_115 , V_473 | V_474 | V_475 ,
V_27 -> V_496 , V_27 , & V_506 ) ;
if ( ! V_27 -> V_505 ) {
F_96 ( V_2 , V_162 , V_198 ,
L_204 ) ;
goto V_469;
}
}
snprintf ( V_115 , sizeof( V_115 ) , L_205 ) ;
if ( ! V_27 -> V_507 ) {
V_27 -> V_507 =
F_98 ( V_115 , V_473 | V_474 | V_475 ,
V_27 -> V_496 , V_27 , & V_508 ) ;
if ( ! V_27 -> V_507 ) {
F_96 ( V_2 , V_162 , V_198 ,
L_206 ) ;
goto V_469;
}
}
snprintf ( V_115 , sizeof( V_115 ) , L_207 ) ;
if ( ! V_27 -> V_509 ) {
V_27 -> V_509 =
F_98 ( V_115 , V_473 | V_474 | V_475 ,
V_27 -> V_496 , V_27 , & V_510 ) ;
if ( ! V_27 -> V_509 ) {
F_96 ( V_2 , V_162 , V_198 ,
L_208 ) ;
goto V_469;
}
}
if ( V_27 -> V_265 . V_511 ) {
snprintf ( V_115 , sizeof( V_115 ) , L_209 ) ;
if ( ! V_27 -> V_512 ) {
V_27 -> V_512 =
F_98 ( V_115 ,
V_473 | V_474 | V_475 ,
V_27 -> V_496 , V_27 ,
& V_513 ) ;
if ( ! V_27 -> V_512 ) {
F_96 ( V_2 , V_162 , V_198 ,
L_210
L_211 ) ;
goto V_469;
}
}
}
V_469:
return;
#endif
}
inline void
F_100 ( struct V_1 * V_2 )
{
#ifdef F_21
struct V_26 * V_27 = V_2 -> V_27 ;
if ( V_2 -> V_18 ) {
F_5 ( V_2 -> V_18 ) ;
V_2 -> V_18 = NULL ;
}
if ( V_2 -> V_492 ) {
F_101 ( V_2 -> V_492 ) ;
V_2 -> V_492 = NULL ;
}
if ( V_2 -> V_494 ) {
F_101 ( V_2 -> V_494 ) ;
V_2 -> V_494 = NULL ;
}
if ( V_2 -> V_491 ) {
F_101 ( V_2 -> V_491 ) ;
V_2 -> V_491 = NULL ;
F_102 ( & V_27 -> V_471 ) ;
}
if ( F_3 ( & V_27 -> V_471 ) == 0 ) {
if ( V_27 -> V_472 ) {
F_101 ( V_27 -> V_472 ) ;
V_27 -> V_472 = NULL ;
}
if ( V_27 -> V_478 ) {
F_101 ( V_27 -> V_478 ) ;
V_27 -> V_478 = NULL ;
}
if ( V_27 -> V_480 ) {
F_101 ( V_27 -> V_480 ) ;
V_27 -> V_480 = NULL ;
}
if ( V_27 -> V_482 ) {
F_101 ( V_27 -> V_482 ) ;
V_27 -> V_482 = NULL ;
}
if ( V_27 -> V_484 ) {
F_101 ( V_27 -> V_484 ) ;
V_27 -> V_484 = NULL ;
}
if ( V_27 -> V_195 ) {
F_101 ( V_27 -> V_195 ) ;
V_27 -> V_195 = NULL ;
}
if ( V_27 -> V_190 ) {
F_101 ( V_27 -> V_190 ) ;
V_27 -> V_190 = NULL ;
}
if ( V_27 -> V_192 ) {
F_101 ( V_27 -> V_192 ) ;
V_27 -> V_192 = NULL ;
}
if ( V_27 -> V_178 ) {
F_101 ( V_27 -> V_178 ) ;
V_27 -> V_178 = NULL ;
}
if ( V_27 -> V_180 ) {
F_101 ( V_27 -> V_180 ) ;
V_27 -> V_180 = NULL ;
}
if ( V_27 -> V_182 ) {
F_101 ( V_27 -> V_182 ) ;
V_27 -> V_182 = NULL ;
}
if ( V_27 -> V_184 ) {
F_101 ( V_27 -> V_184 ) ;
V_27 -> V_184 = NULL ;
}
if ( V_27 -> V_186 ) {
F_101 ( V_27 -> V_186 ) ;
V_27 -> V_186 = NULL ;
}
if ( V_27 -> V_188 ) {
F_101 ( V_27 -> V_188 ) ;
V_27 -> V_188 = NULL ;
}
if ( V_27 -> V_30 ) {
F_5 ( V_27 -> V_30 ) ;
V_27 -> V_30 = NULL ;
}
if ( V_27 -> V_488 ) {
F_101 ( V_27 -> V_488 ) ;
V_27 -> V_488 = NULL ;
}
if ( V_27 -> V_48 == V_477 ) {
if ( V_27 -> V_512 ) {
F_101 ( V_27 -> V_512 ) ;
V_27 -> V_512 = NULL ;
}
if ( V_27 -> V_509 ) {
F_101 ( V_27 -> V_509 ) ;
V_27 -> V_509 = NULL ;
}
if ( V_27 -> V_507 ) {
F_101 ( V_27 -> V_507 ) ;
V_27 -> V_507 = NULL ;
}
if ( V_27 -> V_505 ) {
F_101 ( V_27 -> V_505 ) ;
V_27 -> V_505 = NULL ;
}
if ( V_27 -> V_503 ) {
F_101 ( V_27 -> V_503 ) ;
V_27 -> V_503 = NULL ;
}
if ( V_27 -> V_501 ) {
F_101 ( V_27 -> V_501 ) ;
V_27 -> V_501 = NULL ;
}
if ( V_27 -> V_499 ) {
F_101 ( V_27 -> V_499 ) ;
V_27 -> V_499 = NULL ;
}
if ( V_27 -> V_497 ) {
F_101 ( V_27 -> V_497 ) ;
V_27 -> V_497 = NULL ;
}
if ( V_27 -> V_496 ) {
F_101 ( V_27 -> V_496 ) ;
V_27 -> V_496 = NULL ;
}
}
if ( V_27 -> V_470 ) {
F_101 ( V_27 -> V_470 ) ;
V_27 -> V_470 = NULL ;
F_102 ( & V_468 ) ;
}
if ( F_3 ( & V_468 ) == 0 ) {
F_101 ( V_467 ) ;
V_467 = NULL ;
}
}
#endif
return;
}
void
F_103 ( struct V_26 * V_27 )
{
int V_514 ;
F_104 ( V_27 ) ;
F_105 ( V_27 ) ;
for ( V_514 = 0 ; V_514 < V_27 -> V_295 ; V_514 ++ )
F_106 ( V_27 , V_514 ) ;
F_107 ( V_27 ) ;
F_108 ( V_27 ) ;
F_109 ( V_27 ) ;
F_110 ( V_27 ) ;
for ( V_514 = 0 ; V_514 < V_27 -> V_295 ; V_514 ++ )
F_111 ( V_27 , V_514 ) ;
for ( V_514 = 0 ; V_514 < V_27 -> V_295 ; V_514 ++ )
F_112 ( V_27 , V_514 ) ;
}
