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
V_163 , V_166 , V_149 ) ;
V_152 -> V_12 = V_166 ;
if ( ! V_152 -> V_12 ) {
F_5 ( V_152 ) ;
goto V_156;
}
V_152 -> V_7 = ( 1 << V_167 ) << V_165 ;
V_149 -> V_157 = V_152 ;
V_153 = 0 ;
V_156:
return V_153 ;
}
static T_2
F_33 ( struct V_149 * V_149 , const char T_3 * V_3 ,
T_4 V_168 , T_5 * V_169 )
{
F_34 ( & V_170 ) ;
memset ( ( void * ) V_160 , 0 ,
( ( 1 << V_165 ) << V_164 ) ) ;
memset ( ( void * ) V_166 , 0 ,
( ( 1 << V_165 ) << V_167 ) ) ;
V_171 = 0 ;
F_35 ( & V_170 ) ;
return V_168 ;
}
static T_2
F_36 ( struct V_149 * V_149 , char T_3 * V_3 ,
T_4 V_168 , T_5 * V_169 )
{
struct V_172 * V_173 = V_149 -> V_174 . V_172 ;
struct V_26 * V_27 = V_149 -> V_157 ;
char V_175 [ 32 ] ;
V_71 V_176 = 0 ;
int V_109 = 0 ;
if ( V_173 == V_27 -> V_177 )
V_109 = snprintf ( V_175 , 32 , L_44 , V_27 -> V_178 ) ;
else if ( V_173 == V_27 -> V_179 )
V_109 = snprintf ( V_175 , 32 , L_44 , V_27 -> V_180 ) ;
else if ( V_173 == V_27 -> V_181 )
V_109 = snprintf ( V_175 , 32 , L_44 , V_27 -> V_182 ) ;
else if ( V_173 == V_27 -> V_183 )
V_109 = snprintf ( V_175 , 32 , L_44 , V_27 -> V_184 ) ;
else if ( V_173 == V_27 -> V_185 )
V_109 = snprintf ( V_175 , 32 , L_44 , V_27 -> V_186 ) ;
else if ( V_173 == V_27 -> V_187 )
V_109 = snprintf ( V_175 , 32 , L_44 , V_27 -> V_188 ) ;
else if ( V_173 == V_27 -> V_189 )
V_109 = snprintf ( V_175 , 32 , L_45 , V_27 -> V_190 ) ;
else if ( V_173 == V_27 -> V_191 ) {
memcpy ( & V_176 , & V_27 -> V_192 , sizeof( struct V_193 ) ) ;
V_176 = F_37 ( V_176 ) ;
V_109 = snprintf ( V_175 , 32 , L_46 , V_176 ) ;
} else if ( V_173 == V_27 -> V_194 ) {
if ( V_27 -> V_195 == ( V_196 ) ( - 1 ) )
V_109 = snprintf ( V_175 , 32 , L_47 ) ;
else
V_109 = snprintf ( V_175 , 32 , L_48 ,
( V_71 ) V_27 -> V_195 ) ;
} else
F_38 ( V_27 , V_162 , V_197 ,
L_49 ) ;
return F_39 ( V_3 , V_168 , V_169 , & V_175 , V_109 ) ;
}
static T_2
F_40 ( struct V_149 * V_149 , const char T_3 * V_3 ,
T_4 V_168 , T_5 * V_169 )
{
struct V_172 * V_173 = V_149 -> V_174 . V_172 ;
struct V_26 * V_27 = V_149 -> V_157 ;
char V_198 [ 32 ] ;
V_71 V_176 = 0 ;
int V_4 ;
memset ( V_198 , 0 , 32 ) ;
V_4 = ( V_168 < 32 ) ? V_168 : 32 ;
if ( F_41 ( V_198 , V_3 , V_4 ) )
return 0 ;
if ( V_173 == V_27 -> V_194 ) {
if ( ( V_3 [ 0 ] == 'o' ) && ( V_3 [ 1 ] == 'f' ) && ( V_3 [ 2 ] == 'f' ) )
V_176 = ( V_71 ) ( - 1 ) ;
}
if ( ( V_176 == 0 ) && ( F_42 ( V_198 , 0 , & V_176 ) ) )
return 0 ;
if ( V_173 == V_27 -> V_177 )
V_27 -> V_178 = ( T_1 ) V_176 ;
else if ( V_173 == V_27 -> V_179 )
V_27 -> V_180 = ( T_1 ) V_176 ;
else if ( V_173 == V_27 -> V_181 )
V_27 -> V_182 = ( T_1 ) V_176 ;
else if ( V_173 == V_27 -> V_183 )
V_27 -> V_184 = ( T_1 ) V_176 ;
else if ( V_173 == V_27 -> V_185 )
V_27 -> V_186 = ( T_1 ) V_176 ;
else if ( V_173 == V_27 -> V_187 )
V_27 -> V_188 = ( T_1 ) V_176 ;
else if ( V_173 == V_27 -> V_194 )
V_27 -> V_195 = ( V_196 ) V_176 ;
else if ( V_173 == V_27 -> V_189 )
V_27 -> V_190 = ( T_1 ) ( V_176 & V_199 ) ;
else if ( V_173 == V_27 -> V_191 ) {
V_176 = F_37 ( V_176 ) ;
memcpy ( & V_27 -> V_192 , & V_176 , sizeof( struct V_193 ) ) ;
} else
F_38 ( V_27 , V_162 , V_197 ,
L_50 ) ;
return V_168 ;
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
F_45 ( struct V_149 * V_149 , T_5 V_75 , int V_200 )
{
struct V_151 * V_152 = V_149 -> V_157 ;
return F_46 ( V_149 , V_75 , V_200 , V_152 -> V_7 ) ;
}
static T_2
F_47 ( struct V_149 * V_149 , char T_3 * V_3 ,
T_4 V_168 , T_5 * V_169 )
{
struct V_151 * V_152 = V_149 -> V_157 ;
return F_39 ( V_3 , V_168 , V_169 , V_152 -> V_12 ,
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
static int F_50 ( const char T_3 * V_3 , T_4 V_168 ,
struct V_201 * V_202 )
{
char V_203 [ 64 ] ;
char * V_204 , * V_205 ;
int V_5 ;
T_4 V_206 ;
if ( ! F_51 ( V_207 , V_3 , V_168 ) )
return - V_208 ;
memset ( V_203 , 0 , sizeof( V_203 ) ) ;
memset ( V_202 , 0 , sizeof( * V_202 ) ) ;
V_206 = F_52 ( V_168 , ( sizeof( V_203 ) - 1 ) ) ;
if ( F_41 ( V_203 , V_3 , V_206 ) )
return - V_208 ;
V_204 = & V_203 [ 0 ] ;
V_205 = F_53 ( & V_204 , L_51 ) ;
if ( ! V_205 )
return - V_209 ;
V_202 -> V_210 = F_54 ( V_205 , NULL , 0 ) ;
if ( V_202 -> V_210 == 0 )
return - V_209 ;
for ( V_5 = 0 ; V_5 < V_211 ; V_5 ++ ) {
V_205 = F_53 ( & V_204 , L_51 ) ;
if ( ! V_205 )
return V_5 ;
V_202 -> V_212 [ V_5 ] = F_54 ( V_205 , NULL , 0 ) ;
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
if ( V_152 -> V_213 == V_214 ) {
switch ( V_215 . V_216 . V_210 ) {
case V_217 :
case V_218 :
case V_219 :
case V_220 :
case V_221 :
case V_222 :
memset ( & V_215 , 0 , sizeof( V_215 ) ) ;
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
F_58 ( struct V_149 * V_149 , char T_3 * V_3 , T_4 V_168 ,
T_5 * V_169 )
{
struct V_151 * V_152 = V_149 -> V_157 ;
struct V_26 * V_27 = (struct V_26 * ) V_152 -> V_150 ;
int V_223 , V_224 , V_7 = 0 , V_6 = V_225 ;
int V_226 , V_227 ;
char * V_228 ;
struct V_229 * V_230 ;
T_1 V_231 ;
T_6 V_232 ;
T_7 V_233 ;
V_230 = V_27 -> V_234 ;
if ( ! V_230 )
return 0 ;
V_152 -> V_213 = V_235 ;
if ( ! V_152 -> V_12 )
V_152 -> V_12 = F_2 ( V_236 , V_14 ) ;
if ( ! V_152 -> V_12 )
return 0 ;
V_228 = V_152 -> V_12 ;
if ( * V_169 )
return 0 ;
if ( V_215 . V_216 . V_210 == V_237 ) {
V_226 = V_215 . V_216 . V_212 [ V_238 ] ;
V_227 = V_215 . V_216 . V_212 [ V_239 ] ;
} else
return 0 ;
switch ( V_227 ) {
case V_240 :
F_59 ( V_230 , V_226 , & V_233 ) ;
V_7 += snprintf ( V_228 + V_7 , V_236 - V_7 ,
L_52 , V_226 , V_233 ) ;
break;
case V_241 :
F_60 ( V_230 , V_226 , & V_232 ) ;
V_7 += snprintf ( V_228 + V_7 , V_236 - V_7 ,
L_53 , V_226 , V_232 ) ;
break;
case V_242 :
F_61 ( V_230 , V_226 , & V_231 ) ;
V_7 += snprintf ( V_228 + V_7 , V_236 - V_7 ,
L_54 , V_226 , V_231 ) ;
break;
case V_243 :
goto V_244;
break;
default:
V_7 = 0 ;
break;
}
return F_39 ( V_3 , V_168 , V_169 , V_228 , V_7 ) ;
V_244:
V_223 = V_215 . V_224 . V_245 ;
V_224 = V_223 ;
V_7 += snprintf ( V_228 + V_7 , V_236 - V_7 ,
L_55 , V_223 ) ;
while ( V_6 > 0 ) {
F_61 ( V_230 , V_224 , & V_231 ) ;
V_7 += snprintf ( V_228 + V_7 , V_236 - V_7 ,
L_56 , V_231 ) ;
V_224 += sizeof( T_1 ) ;
if ( V_224 >= V_236 ) {
V_7 += snprintf ( V_228 + V_7 ,
V_236 - V_7 , L_41 ) ;
break;
}
V_6 -= sizeof( T_1 ) ;
if ( ! V_6 )
V_7 += snprintf ( V_228 + V_7 , V_236 - V_7 ,
L_41 ) ;
else if ( ! ( V_6 % ( 8 * sizeof( T_1 ) ) ) ) {
V_223 += ( 8 * sizeof( T_1 ) ) ;
V_7 += snprintf ( V_228 + V_7 , V_236 - V_7 ,
L_57 , V_223 ) ;
}
}
if ( V_6 == 0 ) {
V_215 . V_224 . V_245 += V_225 ;
if ( V_215 . V_224 . V_245 >= V_236 )
V_215 . V_224 . V_245 = 0 ;
} else
V_215 . V_224 . V_245 = 0 ;
return F_39 ( V_3 , V_168 , V_169 , V_228 , V_7 ) ;
}
static T_2
F_62 ( struct V_149 * V_149 , const char T_3 * V_3 ,
T_4 V_168 , T_5 * V_169 )
{
struct V_151 * V_152 = V_149 -> V_157 ;
struct V_26 * V_27 = (struct V_26 * ) V_152 -> V_150 ;
T_1 V_226 , V_246 , V_227 ;
T_1 V_231 ;
T_6 V_232 ;
T_7 V_233 ;
struct V_229 * V_230 ;
int V_153 ;
V_230 = V_27 -> V_234 ;
if ( ! V_230 )
return - V_208 ;
V_152 -> V_213 = V_214 ;
V_153 = F_50 ( V_3 , V_168 , & V_215 . V_216 ) ;
if ( V_153 < 0 )
return V_153 ;
if ( V_215 . V_216 . V_210 == V_237 ) {
if ( V_153 != V_247 )
goto V_248;
V_226 = V_215 . V_216 . V_212 [ V_238 ] ;
V_227 = V_215 . V_216 . V_212 [ V_239 ] ;
if ( V_227 == V_243 ) {
if ( V_226 % sizeof( T_1 ) )
goto V_248;
V_215 . V_224 . V_245 = V_226 ;
} else if ( ( V_227 != sizeof( T_7 ) ) &&
( V_227 != sizeof( T_6 ) ) &&
( V_227 != sizeof( T_1 ) ) )
goto V_248;
if ( V_227 == sizeof( T_7 ) ) {
if ( V_226 > V_236 - sizeof( T_7 ) )
goto V_248;
if ( V_226 % sizeof( T_7 ) )
goto V_248;
}
if ( V_227 == sizeof( T_6 ) ) {
if ( V_226 > V_236 - sizeof( T_6 ) )
goto V_248;
if ( V_226 % sizeof( T_6 ) )
goto V_248;
}
if ( V_227 == sizeof( T_1 ) ) {
if ( V_226 > V_236 - sizeof( T_1 ) )
goto V_248;
if ( V_226 % sizeof( T_1 ) )
goto V_248;
}
} else if ( V_215 . V_216 . V_210 == V_217 ||
V_215 . V_216 . V_210 == V_218 ||
V_215 . V_216 . V_210 == V_219 ) {
if ( V_153 != V_249 )
goto V_248;
V_226 = V_215 . V_216 . V_212 [ V_238 ] ;
V_227 = V_215 . V_216 . V_212 [ V_239 ] ;
V_246 = V_215 . V_216 . V_212 [ V_250 ] ;
if ( ( V_227 != sizeof( T_7 ) ) &&
( V_227 != sizeof( T_6 ) ) &&
( V_227 != sizeof( T_1 ) ) )
goto V_248;
if ( V_227 == sizeof( T_7 ) ) {
if ( V_226 > V_236 - sizeof( T_7 ) )
goto V_248;
if ( V_226 % sizeof( T_7 ) )
goto V_248;
if ( V_215 . V_216 . V_210 == V_217 )
F_63 ( V_230 , V_226 ,
( T_7 ) V_246 ) ;
if ( V_215 . V_216 . V_210 == V_218 ) {
V_153 = F_59 ( V_230 , V_226 , & V_233 ) ;
if ( ! V_153 ) {
V_233 |= ( T_7 ) V_246 ;
F_63 ( V_230 , V_226 ,
V_233 ) ;
}
}
if ( V_215 . V_216 . V_210 == V_219 ) {
V_153 = F_59 ( V_230 , V_226 , & V_233 ) ;
if ( ! V_153 ) {
V_233 &= ( T_7 ) ( ~ V_246 ) ;
F_63 ( V_230 , V_226 ,
V_233 ) ;
}
}
}
if ( V_227 == sizeof( T_6 ) ) {
if ( V_226 > V_236 - sizeof( T_6 ) )
goto V_248;
if ( V_226 % sizeof( T_6 ) )
goto V_248;
if ( V_215 . V_216 . V_210 == V_217 )
F_64 ( V_230 , V_226 ,
( T_6 ) V_246 ) ;
if ( V_215 . V_216 . V_210 == V_218 ) {
V_153 = F_60 ( V_230 , V_226 , & V_232 ) ;
if ( ! V_153 ) {
V_232 |= ( T_6 ) V_246 ;
F_64 ( V_230 , V_226 ,
V_232 ) ;
}
}
if ( V_215 . V_216 . V_210 == V_219 ) {
V_153 = F_60 ( V_230 , V_226 , & V_232 ) ;
if ( ! V_153 ) {
V_232 &= ( T_6 ) ( ~ V_246 ) ;
F_64 ( V_230 , V_226 ,
V_232 ) ;
}
}
}
if ( V_227 == sizeof( T_1 ) ) {
if ( V_226 > V_236 - sizeof( T_1 ) )
goto V_248;
if ( V_226 % sizeof( T_1 ) )
goto V_248;
if ( V_215 . V_216 . V_210 == V_217 )
F_65 ( V_230 , V_226 , V_246 ) ;
if ( V_215 . V_216 . V_210 == V_218 ) {
V_153 = F_61 ( V_230 , V_226 ,
& V_231 ) ;
if ( ! V_153 ) {
V_231 |= V_246 ;
F_65 ( V_230 , V_226 ,
V_231 ) ;
}
}
if ( V_215 . V_216 . V_210 == V_219 ) {
V_153 = F_61 ( V_230 , V_226 ,
& V_231 ) ;
if ( ! V_153 ) {
V_231 &= ~ V_246 ;
F_65 ( V_230 , V_226 ,
V_231 ) ;
}
}
}
} else
goto V_248;
return V_168 ;
V_248:
memset ( & V_215 , 0 , sizeof( V_215 ) ) ;
return - V_209 ;
}
static T_2
F_66 ( struct V_149 * V_149 , char T_3 * V_3 , T_4 V_168 ,
T_5 * V_169 )
{
struct V_151 * V_152 = V_149 -> V_157 ;
struct V_26 * V_27 = (struct V_26 * ) V_152 -> V_150 ;
int V_223 , V_224 , V_251 , V_7 = 0 , V_6 ;
int V_252 , V_253 , V_254 ;
char * V_228 ;
void T_8 * V_255 ;
T_1 V_256 ;
struct V_229 * V_230 ;
T_1 V_231 ;
V_230 = V_27 -> V_234 ;
if ( ! V_230 )
return 0 ;
V_152 -> V_213 = V_235 ;
if ( ! V_152 -> V_12 )
V_152 -> V_12 = F_2 ( V_257 , V_14 ) ;
if ( ! V_152 -> V_12 )
return 0 ;
V_228 = V_152 -> V_12 ;
if ( * V_169 )
return 0 ;
if ( V_215 . V_216 . V_210 == V_258 ) {
V_252 = V_215 . V_216 . V_212 [ V_259 ] ;
V_224 = V_215 . V_216 . V_212 [ V_260 ] ;
V_253 = V_215 . V_216 . V_212 [ V_261 ] ;
V_254 = V_215 . V_216 . V_212 [ V_262 ] ;
} else
return 0 ;
if ( V_253 == 0 )
return 0 ;
V_256 = F_67 ( V_263 , & V_27 -> V_264 . V_265 ) ;
if ( V_256 == V_266 ) {
if ( V_252 == V_267 )
V_255 = V_27 -> V_264 . V_268 ;
else if ( V_252 == V_269 )
V_255 = V_27 -> V_264 . V_270 ;
else if ( V_252 == V_271 )
V_255 = V_27 -> V_264 . V_272 ;
else
return 0 ;
} else if ( V_256 == V_273 ) {
if ( V_252 == V_267 )
V_255 = V_27 -> V_264 . V_268 ;
else
return 0 ;
} else
return 0 ;
if ( V_253 == V_274 ) {
V_251 = V_224 ;
V_231 = F_17 ( V_255 + V_251 ) ;
V_7 += snprintf ( V_228 + V_7 , V_257 - V_7 ,
L_58 , V_251 , V_231 ) ;
} else
goto V_275;
return F_39 ( V_3 , V_168 , V_169 , V_228 , V_7 ) ;
V_275:
V_223 = V_215 . V_224 . V_245 ;
V_251 = V_223 ;
V_7 += snprintf ( V_228 + V_7 , V_257 - V_7 ,
L_59 , V_223 ) ;
V_6 = V_276 ;
while ( V_6 > 0 ) {
V_231 = F_17 ( V_255 + V_251 ) ;
V_7 += snprintf ( V_228 + V_7 , V_257 - V_7 ,
L_56 , V_231 ) ;
V_251 += sizeof( T_1 ) ;
if ( V_253 == V_277 ) {
if ( V_251 >= V_254 ) {
V_7 += snprintf ( V_228 + V_7 ,
V_257 - V_7 , L_41 ) ;
break;
}
} else {
if ( V_251 >= V_224 +
( V_253 * sizeof( T_1 ) ) ) {
V_7 += snprintf ( V_228 + V_7 ,
V_257 - V_7 , L_41 ) ;
break;
}
}
V_6 -= sizeof( T_1 ) ;
if ( ! V_6 )
V_7 += snprintf ( V_228 + V_7 ,
V_257 - V_7 , L_41 ) ;
else if ( ! ( V_6 % ( 8 * sizeof( T_1 ) ) ) ) {
V_223 += ( 8 * sizeof( T_1 ) ) ;
V_7 += snprintf ( V_228 + V_7 ,
V_257 - V_7 ,
L_60 , V_223 ) ;
}
}
if ( V_6 == 0 ) {
V_215 . V_224 . V_245 += V_276 ;
if ( V_253 == V_277 ) {
if ( V_215 . V_224 . V_245 >= V_254 )
V_215 . V_224 . V_245 = 0 ;
} else {
if ( V_251 >= V_224 +
( V_253 * sizeof( T_1 ) ) )
V_215 . V_224 . V_245 = V_224 ;
}
} else {
if ( V_253 == V_277 )
V_215 . V_224 . V_245 = 0 ;
else
V_215 . V_224 . V_245 = V_224 ;
}
return F_39 ( V_3 , V_168 , V_169 , V_228 , V_7 ) ;
}
static T_2
F_68 ( struct V_149 * V_149 , const char T_3 * V_3 ,
T_4 V_168 , T_5 * V_169 )
{
struct V_151 * V_152 = V_149 -> V_157 ;
struct V_26 * V_27 = (struct V_26 * ) V_152 -> V_150 ;
T_1 V_252 , V_254 , V_224 , V_246 , V_253 ;
struct V_229 * V_230 ;
void T_8 * V_255 ;
T_1 V_256 ;
T_1 V_231 ;
int V_153 ;
V_230 = V_27 -> V_234 ;
if ( ! V_230 )
return - V_208 ;
V_152 -> V_213 = V_214 ;
V_153 = F_50 ( V_3 , V_168 , & V_215 . V_216 ) ;
if ( V_153 < 0 )
return V_153 ;
V_256 = F_67 ( V_263 , & V_27 -> V_264 . V_265 ) ;
V_252 = V_215 . V_216 . V_212 [ V_259 ] ;
if ( V_256 == V_266 ) {
if ( ( V_252 != V_267 ) &&
( V_252 != V_269 ) &&
( V_252 != V_271 ) )
goto V_248;
} else if ( V_256 == V_273 ) {
if ( V_252 != V_267 )
goto V_248;
} else
goto V_248;
if ( V_256 == V_266 ) {
if ( V_252 == V_267 ) {
V_215 . V_216 . V_212 [ V_262 ] =
V_278 ;
V_255 = V_27 -> V_264 . V_268 ;
} else if ( V_252 == V_269 ) {
V_215 . V_216 . V_212 [ V_262 ] =
V_279 ;
V_255 = V_27 -> V_264 . V_270 ;
} else if ( V_252 == V_271 ) {
V_215 . V_216 . V_212 [ V_262 ] =
V_280 ;
V_255 = V_27 -> V_264 . V_272 ;
} else
goto V_248;
} else if ( V_256 == V_273 ) {
if ( V_252 == V_267 ) {
V_215 . V_216 . V_212 [ V_262 ] =
V_281 ;
V_255 = V_27 -> V_264 . V_268 ;
} else
goto V_248;
} else
goto V_248;
V_224 = V_215 . V_216 . V_212 [ V_260 ] ;
if ( V_224 % sizeof( T_1 ) )
goto V_248;
V_254 = V_215 . V_216 . V_212 [ V_262 ] ;
if ( V_215 . V_216 . V_210 == V_258 ) {
if ( V_153 != V_282 )
goto V_248;
V_253 = V_215 . V_216 . V_212 [ V_261 ] ;
if ( V_253 == V_277 ) {
if ( V_224 > V_254 - sizeof( T_1 ) )
goto V_248;
V_215 . V_224 . V_245 = V_224 ;
} else if ( V_253 > V_274 ) {
if ( V_224 + V_253 * sizeof( T_1 ) > V_254 )
goto V_248;
V_215 . V_224 . V_245 = V_224 ;
} else if ( V_253 != V_274 )
goto V_248;
} else if ( V_215 . V_216 . V_210 == V_283 ||
V_215 . V_216 . V_210 == V_284 ||
V_215 . V_216 . V_210 == V_285 ) {
if ( V_153 != V_286 )
goto V_248;
V_253 = V_274 ;
V_246 = V_215 . V_216 . V_212 [ V_287 ] ;
if ( V_215 . V_216 . V_210 == V_283 ) {
F_69 ( V_246 , V_255 + V_224 ) ;
F_17 ( V_255 + V_224 ) ;
}
if ( V_215 . V_216 . V_210 == V_284 ) {
V_231 = F_17 ( V_255 + V_224 ) ;
V_231 |= V_246 ;
F_69 ( V_231 , V_255 + V_224 ) ;
F_17 ( V_255 + V_224 ) ;
}
if ( V_215 . V_216 . V_210 == V_285 ) {
V_231 = F_17 ( V_255 + V_224 ) ;
V_231 &= ~ V_246 ;
F_69 ( V_231 , V_255 + V_224 ) ;
F_17 ( V_255 + V_224 ) ;
}
} else
goto V_248;
return V_168 ;
V_248:
memset ( & V_215 , 0 , sizeof( V_215 ) ) ;
return - V_209 ;
}
static T_2
F_70 ( struct V_149 * V_149 , char T_3 * V_3 , T_4 V_168 ,
T_5 * V_169 )
{
struct V_151 * V_152 = V_149 -> V_157 ;
struct V_26 * V_27 = (struct V_26 * ) V_152 -> V_150 ;
int V_7 = 0 ;
char * V_228 ;
int V_288 , V_109 ;
int V_289 ;
struct V_290 * V_291 = NULL ;
if ( ! V_152 -> V_12 )
V_152 -> V_12 = F_2 ( V_292 , V_14 ) ;
if ( ! V_152 -> V_12 )
return 0 ;
V_228 = V_152 -> V_12 ;
V_289 = V_292 - 128 ;
if ( * V_169 )
return 0 ;
F_8 ( & V_27 -> V_49 ) ;
if ( V_27 -> V_264 . V_293 && V_27 -> V_294 ) {
V_109 = V_27 -> V_294 ;
for ( V_288 = 0 ; V_288 < V_109 ; V_288 ++ ) {
V_291 = V_27 -> V_264 . V_293 [ V_288 ] ;
if ( ! V_291 )
goto V_295;
V_7 += snprintf ( V_228 + V_7 ,
V_292 - V_7 ,
L_61
L_62
L_63 ,
V_291 -> V_296 , V_291 -> V_297 ,
V_291 -> V_298 , ( unsigned long long ) V_291 -> V_299 ) ;
V_7 += snprintf ( V_228 + V_7 ,
V_292 - V_7 ,
L_64
L_65
L_66 ,
V_291 -> V_300 ,
V_291 -> V_59 ,
V_291 -> V_301 ,
V_291 -> V_302 ,
V_291 -> V_303 ) ;
V_291 -> V_304 = 0 ;
V_7 += snprintf ( V_228 + V_7 ,
V_292 - V_7 , L_41 ) ;
if ( V_7 >= V_289 )
goto V_305;
V_295:
V_291 = V_27 -> V_264 . V_306 [ V_288 ] ;
V_7 += snprintf ( V_228 + V_7 ,
V_292 - V_7 ,
L_67 ) ;
V_7 += snprintf ( V_228 + V_7 ,
V_292 - V_7 ,
L_68
L_69
L_70 ,
V_291 -> V_307 ,
V_291 -> V_296 , V_291 -> V_297 ,
V_291 -> V_298 , ( unsigned long long ) V_291 -> V_299 ) ;
V_7 += snprintf ( V_228 + V_7 ,
V_292 - V_7 ,
L_71
L_65
L_66 ,
V_291 -> V_300 , V_291 -> V_59 ,
V_291 -> V_301 , V_291 -> V_302 ,
V_291 -> V_303 ) ;
V_291 -> V_308 = 0 ;
V_7 += snprintf ( V_228 + V_7 ,
V_292 - V_7 , L_41 ) ;
if ( V_7 >= V_289 )
goto V_305;
V_291 = V_27 -> V_264 . V_309 [ V_288 ] ;
V_7 += snprintf ( V_228 + V_7 ,
V_292 - V_7 ,
L_72 ) ;
V_7 += snprintf ( V_228 + V_7 ,
V_292 - V_7 ,
L_73
L_74 ,
V_291 -> V_307 ,
V_291 -> V_296 , ( unsigned long long ) V_291 -> V_299 ) ;
V_7 += snprintf ( V_228 + V_7 ,
V_292 - V_7 ,
L_75
L_65
L_66 ,
V_291 -> V_300 ,
V_291 -> V_59 ,
V_291 -> V_301 ,
V_291 -> V_302 ,
V_291 -> V_303 ) ;
V_7 += snprintf ( V_228 + V_7 ,
V_292 - V_7 , L_41 ) ;
if ( V_7 >= V_289 )
goto V_305;
if ( V_288 )
continue;
V_291 = V_27 -> V_264 . V_310 ;
if ( V_291 ) {
V_7 += snprintf ( V_228 + V_7 ,
V_292 - V_7 ,
L_76 ) ;
V_7 += snprintf ( V_228 + V_7 ,
V_292 - V_7 ,
L_68
L_77
L_70 ,
V_291 -> V_307 ,
V_291 -> V_296 , V_291 -> V_297 ,
V_291 -> V_298 ,
( unsigned long long ) V_291 -> V_299 ) ;
V_7 += snprintf ( V_228 + V_7 ,
V_292 - V_7 ,
L_71
L_65
L_66 ,
V_291 -> V_300 , V_291 -> V_59 ,
V_291 -> V_301 , V_291 -> V_302 ,
V_291 -> V_303 ) ;
V_7 += snprintf ( V_228 + V_7 ,
V_292 - V_7 , L_41 ) ;
if ( V_7 >= V_289 )
goto V_305;
}
V_291 = V_27 -> V_264 . V_311 ;
if ( V_291 ) {
V_7 += snprintf ( V_228 + V_7 ,
V_292 - V_7 ,
L_78 ) ;
V_7 += snprintf ( V_228 + V_7 ,
V_292 - V_7 ,
L_79 ,
V_27 -> V_264 . V_311 -> V_307 ) ;
V_7 += snprintf ( V_228 + V_7 ,
V_292 - V_7 ,
L_75
L_65
L_66 ,
V_291 -> V_300 , V_291 -> V_59 ,
V_291 -> V_301 , V_291 -> V_302 ,
V_291 -> V_303 ) ;
V_7 += snprintf ( V_228 + V_7 ,
V_292 - V_7 , L_41 ) ;
if ( V_7 >= V_289 )
goto V_305;
}
V_291 = V_27 -> V_264 . V_312 ;
if ( V_291 ) {
V_7 += snprintf ( V_228 + V_7 ,
V_292 - V_7 ,
L_80 ) ;
V_7 += snprintf ( V_228 + V_7 ,
V_292 - V_7 ,
L_68
L_81
L_70 ,
V_291 -> V_307 ,
V_291 -> V_296 , V_291 -> V_297 ,
V_291 -> V_298 ,
( unsigned long long ) V_291 -> V_299 ) ;
V_7 += snprintf ( V_228 + V_7 ,
V_292 - V_7 ,
L_82
L_65
L_66 ,
V_291 -> V_300 , V_291 -> V_59 ,
V_291 -> V_301 , V_291 -> V_302 ,
V_291 -> V_303 ) ;
V_291 -> V_308 = 0 ;
V_7 += snprintf ( V_228 + V_7 ,
V_292 - V_7 , L_41 ) ;
if ( V_7 >= V_289 )
goto V_305;
}
V_291 = V_27 -> V_264 . V_313 ;
if ( V_291 ) {
V_7 += snprintf ( V_228 + V_7 ,
V_292 - V_7 ,
L_83 ) ;
V_7 += snprintf ( V_228 + V_7 ,
V_292 - V_7 ,
L_73
L_84
L_85 ,
V_291 -> V_307 ,
V_291 -> V_296 ,
( unsigned long long ) V_291 -> V_299 ) ;
V_7 += snprintf ( V_228 + V_7 ,
V_292 - V_7 ,
L_75
L_65
L_66 ,
V_291 -> V_300 , V_291 -> V_59 ,
V_291 -> V_301 , V_291 -> V_302 ,
V_291 -> V_303 ) ;
V_7 += snprintf ( V_228 + V_7 ,
V_292 - V_7 , L_41 ) ;
if ( V_7 >= V_289 )
goto V_305;
}
if ( V_27 -> V_264 . V_314 && V_27 -> V_264 . V_315 ) {
V_291 = V_27 -> V_264 . V_314 ;
V_7 += snprintf ( V_228 + V_7 ,
V_292 - V_7 ,
L_86 ) ;
V_7 += snprintf ( V_228 + V_7 ,
V_292 - V_7 ,
L_73
L_87
L_88 ,
V_291 -> V_307 ,
V_291 -> V_296 , V_291 -> V_297 ,
V_291 -> V_298 ,
( unsigned long long ) V_291 -> V_299 ) ;
V_7 += snprintf ( V_228 + V_7 ,
V_292 - V_7 ,
L_89
L_65
L_90 ,
V_291 -> V_300 ,
V_291 -> V_59 ,
V_291 -> V_301 ,
V_291 -> V_302 ,
V_291 -> V_303 ) ;
V_291 = V_27 -> V_264 . V_315 ;
V_7 += snprintf ( V_228 + V_7 ,
V_292 - V_7 ,
L_91
L_65
L_90 ,
V_291 -> V_300 ,
V_291 -> V_59 ,
V_291 -> V_301 ,
V_291 -> V_302 ,
V_291 -> V_303 ) ;
V_7 += snprintf ( V_228 + V_7 ,
V_292 - V_7 , L_41 ) ;
}
}
}
if ( V_27 -> V_316 ) {
V_291 = V_27 -> V_264 . V_317 ;
if ( ! V_291 )
goto V_156;
V_7 += snprintf ( V_228 + V_7 ,
V_292 - V_7 ,
L_92
L_62
L_63 ,
V_291 -> V_296 , V_291 -> V_297 ,
V_291 -> V_298 , ( unsigned long long ) V_291 -> V_299 ) ;
V_7 += snprintf ( V_228 + V_7 ,
V_292 - V_7 ,
L_64
L_65
L_66 ,
V_291 -> V_300 ,
V_291 -> V_59 ,
V_291 -> V_301 ,
V_291 -> V_302 ,
V_291 -> V_303 ) ;
V_291 -> V_304 = 0 ;
V_7 += snprintf ( V_228 + V_7 ,
V_292 - V_7 , L_41 ) ;
if ( V_7 >= V_289 )
goto V_305;
}
if ( V_27 -> V_316 ) {
V_291 = V_27 -> V_264 . V_318 ;
if ( V_291 ) {
V_7 += snprintf ( V_228 + V_7 ,
V_292 - V_7 ,
L_93 ) ;
V_7 += snprintf ( V_228 + V_7 ,
V_292 - V_7 ,
L_68
L_69
L_70 ,
V_291 -> V_307 ,
V_291 -> V_296 , V_291 -> V_297 ,
V_291 -> V_298 , ( unsigned long long ) V_291 -> V_299 ) ;
V_7 += snprintf ( V_228 + V_7 ,
V_292 - V_7 ,
L_71
L_65
L_66 ,
V_291 -> V_300 , V_291 -> V_59 ,
V_291 -> V_301 , V_291 -> V_302 ,
V_291 -> V_303 ) ;
V_291 -> V_308 = 0 ;
V_7 += snprintf ( V_228 + V_7 ,
V_292 - V_7 , L_41 ) ;
if ( V_7 >= V_289 )
goto V_305;
}
V_291 = V_27 -> V_264 . V_319 ;
if ( V_291 ) {
V_7 += snprintf ( V_228 + V_7 ,
V_292 - V_7 ,
L_94 ) ;
V_7 += snprintf ( V_228 + V_7 ,
V_292 - V_7 ,
L_73
L_74 ,
V_291 -> V_307 ,
V_291 -> V_296 , ( unsigned long long ) V_291 -> V_299 ) ;
V_7 += snprintf ( V_228 + V_7 ,
V_292 - V_7 ,
L_75
L_65
L_66 ,
V_291 -> V_300 ,
V_291 -> V_59 ,
V_291 -> V_301 ,
V_291 -> V_302 ,
V_291 -> V_303 ) ;
V_7 += snprintf ( V_228 + V_7 ,
V_292 - V_7 , L_41 ) ;
if ( V_7 >= V_289 )
goto V_305;
}
}
V_156:
F_13 ( & V_27 -> V_49 ) ;
return F_39 ( V_3 , V_168 , V_169 , V_228 , V_7 ) ;
V_305:
V_7 += snprintf ( V_228 + V_7 ,
V_292 - V_7 , L_95 ) ;
F_13 ( & V_27 -> V_49 ) ;
return F_39 ( V_3 , V_168 , V_169 , V_228 , V_7 ) ;
}
static int
F_71 ( struct V_290 * V_320 , int V_6 , int V_227 )
{
if ( ( V_227 != 1 ) && ( V_227 != V_321 ) )
return - V_209 ;
if ( V_6 > V_320 -> V_59 - 1 )
return - V_209 ;
return 0 ;
}
static int
F_72 ( char * V_228 , int V_7 , struct V_290 * V_322 ,
T_1 V_6 )
{
int V_224 , V_323 ;
T_1 * V_324 ;
if ( ! V_228 || ! V_322 )
return 0 ;
V_323 = V_322 -> V_301 ;
V_7 += snprintf ( V_228 + V_7 , V_325 - V_7 ,
L_96 , V_6 ) ;
V_224 = 0 ;
V_324 = V_322 -> V_326 [ V_6 ] . V_327 ;
while ( V_323 > 0 ) {
V_7 += snprintf ( V_228 + V_7 , V_325 - V_7 ,
L_56 , * V_324 ) ;
V_324 ++ ;
V_224 += sizeof( T_1 ) ;
V_323 -= sizeof( T_1 ) ;
if ( V_323 > 0 && ! ( V_224 % ( 4 * sizeof( T_1 ) ) ) )
V_7 += snprintf ( V_228 + V_7 ,
V_325 - V_7 , L_41 ) ;
}
V_7 += snprintf ( V_228 + V_7 , V_325 - V_7 , L_41 ) ;
return V_7 ;
}
static T_2
F_73 ( struct V_149 * V_149 , char T_3 * V_3 , T_4 V_168 ,
T_5 * V_169 )
{
struct V_151 * V_152 = V_149 -> V_157 ;
T_1 V_328 , V_6 , V_227 ;
struct V_290 * V_322 = NULL ;
char * V_228 ;
int V_7 = 0 ;
V_152 -> V_213 = V_235 ;
if ( ! V_152 -> V_12 )
V_152 -> V_12 = F_2 ( V_325 , V_14 ) ;
if ( ! V_152 -> V_12 )
return 0 ;
V_228 = V_152 -> V_12 ;
if ( * V_169 )
return 0 ;
if ( V_215 . V_216 . V_210 == V_329 ) {
V_6 = V_215 . V_216 . V_212 [ V_330 ] ;
V_227 = V_215 . V_216 . V_212 [ V_331 ] ;
V_322 = (struct V_290 * ) V_215 . V_332 ;
} else
return 0 ;
if ( V_227 == V_321 )
goto V_333;
V_7 = F_72 ( V_228 , V_7 , V_322 , V_6 ) ;
return F_39 ( V_3 , V_168 , V_169 , V_228 , V_7 ) ;
V_333:
V_328 = V_215 . V_224 . V_245 ;
V_6 = V_328 ;
while ( V_7 < V_334 - V_322 -> V_301 ) {
V_7 = F_72 ( V_228 , V_7 , V_322 , V_6 ) ;
V_6 ++ ;
if ( V_6 > V_322 -> V_59 - 1 )
break;
}
if ( V_6 > V_322 -> V_59 - 1 )
V_6 = 0 ;
V_215 . V_224 . V_245 = V_6 ;
return F_39 ( V_3 , V_168 , V_169 , V_228 , V_7 ) ;
}
static T_2
F_74 ( struct V_149 * V_149 , const char T_3 * V_3 ,
T_4 V_168 , T_5 * V_169 )
{
struct V_151 * V_152 = V_149 -> V_157 ;
struct V_26 * V_27 = (struct V_26 * ) V_152 -> V_150 ;
T_1 V_335 , V_336 , V_337 , V_6 , V_227 , V_224 , V_246 ;
T_1 * V_324 ;
struct V_290 * V_322 ;
int V_153 ;
V_152 -> V_213 = V_214 ;
V_153 = F_50 ( V_3 , V_168 , & V_215 . V_216 ) ;
if ( V_153 < 0 )
return V_153 ;
V_336 = V_215 . V_216 . V_212 [ V_338 ] ;
V_337 = V_215 . V_216 . V_212 [ V_339 ] ;
V_6 = V_215 . V_216 . V_212 [ V_330 ] ;
V_227 = V_215 . V_216 . V_212 [ V_331 ] ;
V_224 = V_215 . V_216 . V_212 [ V_340 ] ;
V_246 = V_215 . V_216 . V_212 [ V_341 ] ;
if ( V_215 . V_216 . V_210 == V_220 ||
V_215 . V_216 . V_210 == V_221 ||
V_215 . V_216 . V_210 == V_222 ) {
if ( V_153 != V_342 )
goto V_248;
if ( V_227 != 1 )
goto V_248;
} else if ( V_215 . V_216 . V_210 == V_329 ) {
if ( V_153 != V_343 )
goto V_248;
} else
goto V_248;
switch ( V_336 ) {
case V_344 :
if ( V_27 -> V_264 . V_293 ) {
for ( V_335 = 0 ; V_335 < V_27 -> V_294 ;
V_335 ++ ) {
if ( V_27 -> V_264 . V_293 [ V_335 ] &&
V_27 -> V_264 . V_293 [ V_335 ] -> V_300 ==
V_337 ) {
V_153 = F_71 (
V_27 -> V_264 . V_293 [ V_335 ] ,
V_6 , V_227 ) ;
if ( V_153 )
goto V_248;
V_215 . V_332 =
V_27 -> V_264 . V_293 [ V_335 ] ;
goto V_345;
}
}
}
goto V_248;
break;
case V_346 :
if ( V_27 -> V_264 . V_310 &&
V_27 -> V_264 . V_310 -> V_300 == V_337 ) {
V_153 = F_71 (
V_27 -> V_264 . V_310 , V_6 , V_227 ) ;
if ( V_153 )
goto V_248;
V_215 . V_332 = V_27 -> V_264 . V_310 ;
goto V_345;
}
if ( V_27 -> V_264 . V_312 &&
V_27 -> V_264 . V_312 -> V_300 == V_337 ) {
V_153 = F_71 (
V_27 -> V_264 . V_312 , V_6 , V_227 ) ;
if ( V_153 )
goto V_248;
V_215 . V_332 = V_27 -> V_264 . V_312 ;
goto V_345;
}
if ( V_27 -> V_264 . V_306 ) {
V_335 = 0 ;
do {
if ( V_27 -> V_264 . V_306 [ V_335 ] &&
V_27 -> V_264 . V_306 [ V_335 ] -> V_300 ==
V_337 ) {
V_153 = F_71 (
V_27 -> V_264 . V_306 [ V_335 ] ,
V_6 , V_227 ) ;
if ( V_153 )
goto V_248;
V_215 . V_332 =
V_27 -> V_264 . V_306 [ V_335 ] ;
goto V_345;
}
} while ( ++ V_335 < V_27 -> V_294 );
}
goto V_248;
break;
case V_347 :
if ( V_27 -> V_264 . V_311 &&
V_27 -> V_264 . V_311 -> V_300 == V_337 ) {
V_153 = F_71 (
V_27 -> V_264 . V_311 , V_6 , V_227 ) ;
if ( V_153 )
goto V_248;
V_215 . V_332 = V_27 -> V_264 . V_311 ;
goto V_345;
}
goto V_248;
break;
case V_348 :
if ( V_27 -> V_264 . V_313 &&
V_27 -> V_264 . V_313 -> V_300 == V_337 ) {
V_153 = F_71 (
V_27 -> V_264 . V_313 , V_6 , V_227 ) ;
if ( V_153 )
goto V_248;
V_215 . V_332 = V_27 -> V_264 . V_313 ;
goto V_345;
}
if ( V_27 -> V_264 . V_309 ) {
for ( V_335 = 0 ; V_335 < V_27 -> V_294 ;
V_335 ++ ) {
if ( ! V_27 -> V_264 . V_309 [ V_335 ] )
continue;
if ( V_27 -> V_264 . V_309 [ V_335 ] -> V_300 ==
V_337 ) {
V_153 = F_71 (
V_27 -> V_264 . V_309 [ V_335 ] ,
V_6 , V_227 ) ;
if ( V_153 )
goto V_248;
V_215 . V_332 =
V_27 -> V_264 . V_309 [ V_335 ] ;
goto V_345;
}
}
}
goto V_248;
break;
case V_349 :
if ( V_27 -> V_264 . V_314 &&
V_27 -> V_264 . V_314 -> V_300 == V_337 ) {
V_153 = F_71 (
V_27 -> V_264 . V_314 , V_6 , V_227 ) ;
if ( V_153 )
goto V_248;
V_215 . V_332 = V_27 -> V_264 . V_314 ;
goto V_345;
}
if ( V_27 -> V_264 . V_315 &&
V_27 -> V_264 . V_315 -> V_300 == V_337 ) {
V_153 = F_71 (
V_27 -> V_264 . V_315 , V_6 , V_227 ) ;
if ( V_153 )
goto V_248;
V_215 . V_332 = V_27 -> V_264 . V_315 ;
goto V_345;
}
goto V_248;
break;
default:
goto V_248;
break;
}
V_345:
if ( V_215 . V_216 . V_210 == V_329 ) {
if ( V_227 == V_321 )
V_215 . V_224 . V_245 = V_6 ;
}
if ( V_215 . V_216 . V_210 == V_220 ||
V_215 . V_216 . V_210 == V_221 ||
V_215 . V_216 . V_210 == V_222 ) {
V_322 = (struct V_290 * ) V_215 . V_332 ;
if ( V_224 > V_322 -> V_301 / sizeof( T_1 ) - 1 )
goto V_248;
V_324 = V_322 -> V_326 [ V_6 ] . V_327 ;
V_324 += V_224 ;
if ( V_215 . V_216 . V_210 == V_220 )
* V_324 = V_246 ;
if ( V_215 . V_216 . V_210 == V_221 )
* V_324 |= V_246 ;
if ( V_215 . V_216 . V_210 == V_222 )
* V_324 &= ~ V_246 ;
}
return V_168 ;
V_248:
memset ( & V_215 , 0 , sizeof( V_215 ) ) ;
return - V_209 ;
}
static int
F_75 ( struct V_26 * V_27 , char * V_228 ,
int V_7 , T_1 V_350 )
{
if ( ! V_228 )
return 0 ;
switch ( V_350 ) {
case V_351 :
V_7 += snprintf ( V_228 + V_7 , V_352 - V_7 ,
L_97 ,
F_17 ( V_27 -> V_264 . V_353 ) ) ;
break;
case V_354 :
V_7 += snprintf ( V_228 + V_7 , V_352 - V_7 ,
L_98 ,
F_17 ( V_27 -> V_264 . V_355 ) ) ;
break;
case V_356 :
V_7 += snprintf ( V_228 + V_7 , V_352 - V_7 ,
L_99 ,
F_17 ( V_27 -> V_264 . V_357 ) ) ;
break;
case V_358 :
V_7 += snprintf ( V_228 + V_7 , V_352 - V_7 ,
L_100 ,
F_17 ( V_27 -> V_264 . V_359 ) ) ;
break;
default:
break;
}
return V_7 ;
}
static T_2
F_76 ( struct V_149 * V_149 , char T_3 * V_3 , T_4 V_168 ,
T_5 * V_169 )
{
struct V_151 * V_152 = V_149 -> V_157 ;
struct V_26 * V_27 = (struct V_26 * ) V_152 -> V_150 ;
T_1 V_360 , V_5 ;
char * V_228 ;
int V_7 = 0 ;
V_152 -> V_213 = V_235 ;
if ( ! V_152 -> V_12 )
V_152 -> V_12 = F_2 ( V_352 , V_14 ) ;
if ( ! V_152 -> V_12 )
return 0 ;
V_228 = V_152 -> V_12 ;
if ( * V_169 )
return 0 ;
if ( V_215 . V_216 . V_210 == V_361 )
V_360 = V_215 . V_216 . V_212 [ V_362 ] ;
else
return 0 ;
if ( V_360 == V_363 )
for ( V_5 = 1 ; V_5 <= V_364 ; V_5 ++ )
V_7 = F_75 ( V_27 ,
V_228 , V_7 , V_5 ) ;
else
V_7 = F_75 ( V_27 ,
V_228 , V_7 , V_360 ) ;
return F_39 ( V_3 , V_168 , V_169 , V_228 , V_7 ) ;
}
static T_2
F_77 ( struct V_149 * V_149 , const char T_3 * V_3 ,
T_4 V_168 , T_5 * V_169 )
{
struct V_151 * V_152 = V_149 -> V_157 ;
struct V_26 * V_27 = (struct V_26 * ) V_152 -> V_150 ;
T_1 V_360 , V_246 , V_365 = 0 ;
void T_8 * V_366 ;
int V_153 ;
V_152 -> V_213 = V_214 ;
V_153 = F_50 ( V_3 , V_168 , & V_215 . V_216 ) ;
if ( V_153 < 0 )
return V_153 ;
V_360 = V_215 . V_216 . V_212 [ V_362 ] ;
V_246 = V_215 . V_216 . V_212 [ V_367 ] ;
if ( V_215 . V_216 . V_210 == V_368 ||
V_215 . V_216 . V_210 == V_369 ||
V_215 . V_216 . V_210 == V_370 ) {
if ( V_153 != V_371 )
goto V_248;
if ( V_360 > V_364 )
goto V_248;
} else if ( V_215 . V_216 . V_210 == V_361 ) {
if ( V_153 != V_372 )
goto V_248;
if ( ( V_360 > V_364 ) &&
( V_360 != V_363 ) )
goto V_248;
} else
goto V_248;
if ( V_215 . V_216 . V_210 == V_368 ||
V_215 . V_216 . V_210 == V_369 ||
V_215 . V_216 . V_210 == V_370 ) {
switch ( V_360 ) {
case V_351 :
V_366 = V_27 -> V_264 . V_353 ;
break;
case V_354 :
V_366 = V_27 -> V_264 . V_355 ;
break;
case V_356 :
V_366 = V_27 -> V_264 . V_357 ;
break;
case V_358 :
V_366 = V_27 -> V_264 . V_359 ;
break;
default:
goto V_248;
}
if ( V_215 . V_216 . V_210 == V_368 )
V_365 = V_246 ;
if ( V_215 . V_216 . V_210 == V_369 ) {
V_365 = F_17 ( V_366 ) ;
V_365 |= V_246 ;
}
if ( V_215 . V_216 . V_210 == V_370 ) {
V_365 = F_17 ( V_366 ) ;
V_365 &= ~ V_246 ;
}
F_69 ( V_365 , V_366 ) ;
F_17 ( V_366 ) ;
}
return V_168 ;
V_248:
memset ( & V_215 , 0 , sizeof( V_215 ) ) ;
return - V_209 ;
}
static int
F_78 ( struct V_26 * V_27 , char * V_228 ,
int V_7 , T_1 V_373 )
{
if ( ! V_228 )
return 0 ;
switch ( V_373 ) {
case V_374 :
V_7 += snprintf ( V_228 + V_7 , V_375 - V_7 ,
L_101 ,
F_17 ( V_27 -> V_264 . V_268 +
V_376 ) ) ;
break;
case V_377 :
V_7 += snprintf ( V_228 + V_7 , V_375 - V_7 ,
L_102 ,
F_17 ( V_27 -> V_264 . V_268 +
V_378 ) ) ;
break;
case V_379 :
V_7 += snprintf ( V_228 + V_7 , V_375 - V_7 ,
L_103 ,
F_17 ( V_27 -> V_264 . V_268 +
V_380 ) ) ;
break;
case V_381 :
V_7 += snprintf ( V_228 + V_7 , V_375 - V_7 ,
L_104 ,
F_17 ( V_27 -> V_264 . V_268 +
V_382 ) ) ;
break;
case V_383 :
V_7 += snprintf ( V_228 + V_7 , V_375 - V_7 ,
L_105 ,
F_17 ( V_27 -> V_264 . V_268 +
V_384 ) ) ;
break;
case V_385 :
V_7 += snprintf ( V_228 + V_7 , V_375 - V_7 ,
L_106 ,
F_17 ( V_27 -> V_264 . V_268 +
V_386 ) ) ;
break;
default:
break;
}
return V_7 ;
}
static T_2
F_79 ( struct V_149 * V_149 , char T_3 * V_3 , T_4 V_168 ,
T_5 * V_169 )
{
struct V_151 * V_152 = V_149 -> V_157 ;
struct V_26 * V_27 = (struct V_26 * ) V_152 -> V_150 ;
T_1 V_387 , V_5 ;
char * V_228 ;
int V_7 = 0 ;
V_152 -> V_213 = V_235 ;
if ( ! V_152 -> V_12 )
V_152 -> V_12 = F_2 ( V_375 , V_14 ) ;
if ( ! V_152 -> V_12 )
return 0 ;
V_228 = V_152 -> V_12 ;
if ( * V_169 )
return 0 ;
if ( V_215 . V_216 . V_210 == V_388 )
V_387 = V_215 . V_216 . V_212 [ V_389 ] ;
else
return 0 ;
if ( V_387 == V_390 )
for ( V_5 = 1 ; V_5 <= V_391 ; V_5 ++ )
V_7 = F_78 ( V_27 ,
V_228 , V_7 , V_5 ) ;
else
V_7 = F_78 ( V_27 ,
V_228 , V_7 , V_387 ) ;
return F_39 ( V_3 , V_168 , V_169 , V_228 , V_7 ) ;
}
static T_2
F_80 ( struct V_149 * V_149 , const char T_3 * V_3 ,
T_4 V_168 , T_5 * V_169 )
{
struct V_151 * V_152 = V_149 -> V_157 ;
struct V_26 * V_27 = (struct V_26 * ) V_152 -> V_150 ;
T_1 V_387 , V_246 , V_365 = 0 ;
void T_8 * V_392 ;
int V_153 ;
V_152 -> V_213 = V_214 ;
V_153 = F_50 ( V_3 , V_168 , & V_215 . V_216 ) ;
if ( V_153 < 0 )
return V_153 ;
V_387 = V_215 . V_216 . V_212 [ V_389 ] ;
V_246 = V_215 . V_216 . V_212 [ V_393 ] ;
if ( V_215 . V_216 . V_210 == V_394 ||
V_215 . V_216 . V_210 == V_395 ||
V_215 . V_216 . V_210 == V_396 ) {
if ( V_153 != V_397 )
goto V_248;
if ( V_387 > V_391 )
goto V_248;
} else if ( V_215 . V_216 . V_210 == V_388 ) {
if ( V_153 != V_398 )
goto V_248;
if ( ( V_387 > V_391 ) &&
( V_387 != V_390 ) )
goto V_248;
} else
goto V_248;
if ( V_215 . V_216 . V_210 == V_394 ||
V_215 . V_216 . V_210 == V_395 ||
V_215 . V_216 . V_210 == V_396 ) {
switch ( V_387 ) {
case V_374 :
V_392 = V_27 -> V_264 . V_268 +
V_376 ;
break;
case V_377 :
V_392 = V_27 -> V_264 . V_268 +
V_378 ;
break;
case V_379 :
V_392 = V_27 -> V_264 . V_268 +
V_380 ;
break;
case V_381 :
V_392 = V_27 -> V_264 . V_268 +
V_382 ;
break;
case V_383 :
V_392 = V_27 -> V_264 . V_268 +
V_384 ;
break;
case V_385 :
V_392 = V_27 -> V_264 . V_268 +
V_386 ;
break;
default:
goto V_248;
}
if ( V_215 . V_216 . V_210 == V_394 )
V_365 = V_246 ;
if ( V_215 . V_216 . V_210 == V_395 ) {
V_365 = F_17 ( V_392 ) ;
V_365 |= V_246 ;
}
if ( V_215 . V_216 . V_210 == V_396 ) {
V_365 = F_17 ( V_392 ) ;
V_365 &= ~ V_246 ;
}
F_69 ( V_365 , V_392 ) ;
F_17 ( V_392 ) ;
}
return V_168 ;
V_248:
memset ( & V_215 , 0 , sizeof( V_215 ) ) ;
return - V_209 ;
}
static int
F_81 ( struct V_26 * V_27 , char * V_228 )
{
T_1 V_399 , V_400 , V_401 , V_402 ;
int V_7 = 0 ;
V_402 = V_215 . V_216 . V_212 [ V_403 ] ;
V_399 = V_215 . V_216 . V_212 [ V_404 ] ;
V_400 = V_215 . V_216 . V_212 [ V_405 ] ;
V_401 = V_215 . V_216 . V_212 [ V_406 ] ;
V_7 += snprintf ( V_228 + V_7 , V_407 - V_7 ,
L_107 , V_399 ) ;
V_7 += snprintf ( V_228 + V_7 , V_407 - V_7 ,
L_108 , V_400 ) ;
V_7 += snprintf ( V_228 + V_7 , V_407 - V_7 ,
L_109 , V_401 ) ;
V_7 += snprintf ( V_228 + V_7 , V_407 - V_7 ,
L_110 , V_402 ) ;
return V_7 ;
}
static T_2
F_82 ( struct V_149 * V_149 , char T_3 * V_3 , T_4 V_168 ,
T_5 * V_169 )
{
struct V_151 * V_152 = V_149 -> V_157 ;
struct V_26 * V_27 = (struct V_26 * ) V_152 -> V_150 ;
char * V_228 ;
int V_7 = 0 ;
V_152 -> V_213 = V_235 ;
if ( ! V_152 -> V_12 )
V_152 -> V_12 = F_2 ( V_407 , V_14 ) ;
if ( ! V_152 -> V_12 )
return 0 ;
V_228 = V_152 -> V_12 ;
if ( * V_169 )
return 0 ;
if ( ( V_215 . V_216 . V_210 != V_408 ) &&
( V_215 . V_216 . V_210 != V_409 ) )
return 0 ;
V_7 = F_81 ( V_27 , V_228 ) ;
return F_39 ( V_3 , V_168 , V_169 , V_228 , V_7 ) ;
}
static T_2
F_83 ( struct V_149 * V_149 , const char T_3 * V_3 ,
T_4 V_168 , T_5 * V_169 )
{
struct V_151 * V_152 = V_149 -> V_157 ;
T_1 V_399 , V_400 , V_401 , V_402 ;
int V_153 ;
V_152 -> V_213 = V_214 ;
V_153 = F_50 ( V_3 , V_168 , & V_215 . V_216 ) ;
if ( V_153 < 0 )
return V_153 ;
V_402 = V_215 . V_216 . V_212 [ V_403 ] ;
V_399 = V_215 . V_216 . V_212 [ V_404 ] ;
V_400 = V_215 . V_216 . V_212 [ V_405 ] ;
V_401 = V_215 . V_216 . V_212 [ V_406 ] ;
if ( V_215 . V_216 . V_210 == V_408 ) {
if ( ! ( V_399 & V_410 ) )
goto V_248;
if ( ( V_399 & ~ V_410 ) &&
( V_399 != V_411 ) )
goto V_248;
if ( V_401 > sizeof( V_91 ) )
goto V_248;
} else if ( V_215 . V_216 . V_210 == V_409 ) {
if ( ! ( V_399 & V_412 ) )
goto V_248;
if ( ( V_399 & ~ V_412 ) &&
( V_399 != V_411 ) )
goto V_248;
if ( V_401 > ( V_413 ) / 4 )
goto V_248;
if ( V_402 != 0x9b )
goto V_248;
} else
goto V_248;
if ( V_401 == 0 )
goto V_248;
if ( V_153 != V_414 )
goto V_248;
if ( V_402 & ~ 0xff )
goto V_248;
if ( V_400 == 0 )
goto V_415;
return V_168 ;
V_415:
memset ( & V_215 , 0 , sizeof( V_215 ) ) ;
return V_168 ;
V_248:
memset ( & V_215 , 0 , sizeof( V_215 ) ) ;
return - V_209 ;
}
static int
F_84 ( struct V_26 * V_27 , char * V_228 , int V_7 )
{
T_6 V_416 , V_417 ;
V_7 += snprintf ( V_228 + V_7 , V_418 - V_7 ,
L_111 ) ;
V_7 += snprintf ( V_228 + V_7 , V_418 - V_7 ,
L_112 ) ;
F_85 ( V_27 , V_419 ,
& V_416 , & V_417 ) ;
V_7 += snprintf ( V_228 + V_7 , V_418 - V_7 ,
L_113 , V_416 , V_417 ) ;
V_7 += snprintf ( V_228 + V_7 , V_418 - V_7 ,
L_114 ) ;
F_85 ( V_27 , V_420 ,
& V_416 , & V_417 ) ;
V_7 += snprintf ( V_228 + V_7 , V_418 - V_7 ,
L_113 , V_416 , V_417 ) ;
V_7 += snprintf ( V_228 + V_7 , V_418 - V_7 ,
L_115 ) ;
F_85 ( V_27 , V_421 ,
& V_416 , & V_417 ) ;
V_7 += snprintf ( V_228 + V_7 , V_418 - V_7 ,
L_113 , V_416 , V_417 ) ;
V_7 += snprintf ( V_228 + V_7 , V_418 - V_7 ,
L_116 ) ;
F_85 ( V_27 , V_422 ,
& V_416 , & V_417 ) ;
V_7 += snprintf ( V_228 + V_7 , V_418 - V_7 ,
L_113 , V_416 , V_417 ) ;
return V_7 ;
}
static int
F_86 ( struct V_26 * V_27 , char * V_228 , int V_7 )
{
T_6 V_416 , V_417 ;
int V_153 ;
V_7 += snprintf ( V_228 + V_7 , V_418 - V_7 ,
L_117 ) ;
V_7 += snprintf ( V_228 + V_7 , V_418 - V_7 ,
L_118 ) ;
V_153 = F_87 ( V_27 , V_419 ,
& V_416 , & V_417 ) ;
if ( ! V_153 )
V_7 += snprintf ( V_228 + V_7 , V_418 - V_7 ,
L_119 ,
V_27 -> V_423 , V_416 , V_417 ) ;
else
V_7 += snprintf ( V_228 + V_7 , V_418 - V_7 ,
L_120 ) ;
V_7 += snprintf ( V_228 + V_7 , V_418 - V_7 ,
L_121 ) ;
V_153 = F_87 ( V_27 , V_420 ,
& V_416 , & V_417 ) ;
if ( ! V_153 )
V_7 += snprintf ( V_228 + V_7 , V_418 - V_7 ,
L_119 ,
V_27 -> V_423 , V_416 , V_417 ) ;
else
V_7 += snprintf ( V_228 + V_7 , V_418 - V_7 ,
L_120 ) ;
V_7 += snprintf ( V_228 + V_7 , V_418 - V_7 ,
L_122 ) ;
V_153 = F_87 ( V_27 , V_421 ,
& V_416 , & V_417 ) ;
if ( ! V_153 )
V_7 += snprintf ( V_228 + V_7 , V_418 - V_7 ,
L_119 ,
V_27 -> V_423 , V_416 , V_417 ) ;
else
V_7 += snprintf ( V_228 + V_7 , V_418 - V_7 ,
L_120 ) ;
V_7 += snprintf ( V_228 + V_7 , V_418 - V_7 ,
L_123 ) ;
V_153 = F_87 ( V_27 , V_422 ,
& V_416 , & V_417 ) ;
if ( ! V_153 )
V_7 += snprintf ( V_228 + V_7 , V_418 - V_7 ,
L_119 ,
V_27 -> V_423 , V_416 , V_417 ) ;
else
V_7 += snprintf ( V_228 + V_7 , V_418 - V_7 ,
L_120 ) ;
return V_7 ;
}
static int
F_88 ( struct V_26 * V_27 , char * V_228 , int V_7 )
{
struct V_424 * V_425 ;
int V_6 ;
V_7 += snprintf ( V_228 + V_7 , V_418 - V_7 ,
L_124 ) ;
V_7 += snprintf ( V_228 + V_7 , V_418 - V_7 ,
L_125 ) ;
V_6 = 0 ;
F_10 (rsrc_blks, &phba->lpfc_vpi_blk_list, list) {
V_7 += snprintf ( V_228 + V_7 , V_418 - V_7 ,
L_126 ,
V_6 , V_425 -> V_426 ,
V_425 -> V_427 ) ;
V_6 ++ ;
}
V_7 += snprintf ( V_228 + V_7 , V_418 - V_7 ,
L_127 ) ;
V_6 = 0 ;
F_10 (rsrc_blks, &phba->sli4_hba.lpfc_vfi_blk_list,
list) {
V_7 += snprintf ( V_228 + V_7 , V_418 - V_7 ,
L_126 ,
V_6 , V_425 -> V_426 ,
V_425 -> V_427 ) ;
V_6 ++ ;
}
V_7 += snprintf ( V_228 + V_7 , V_418 - V_7 ,
L_128 ) ;
V_6 = 0 ;
F_10 (rsrc_blks, &phba->sli4_hba.lpfc_rpi_blk_list,
list) {
V_7 += snprintf ( V_228 + V_7 , V_418 - V_7 ,
L_126 ,
V_6 , V_425 -> V_426 ,
V_425 -> V_427 ) ;
V_6 ++ ;
}
V_7 += snprintf ( V_228 + V_7 , V_418 - V_7 ,
L_129 ) ;
V_6 = 0 ;
F_10 (rsrc_blks, &phba->sli4_hba.lpfc_xri_blk_list,
list) {
V_7 += snprintf ( V_228 + V_7 , V_418 - V_7 ,
L_126 ,
V_6 , V_425 -> V_426 ,
V_425 -> V_427 ) ;
V_6 ++ ;
}
return V_7 ;
}
static T_2
F_89 ( struct V_149 * V_149 , const char T_3 * V_3 ,
T_4 V_168 , T_5 * V_169 )
{
struct V_151 * V_152 = V_149 -> V_157 ;
T_1 V_428 ;
int V_153 ;
V_152 -> V_213 = V_214 ;
V_153 = F_50 ( V_3 , V_168 , & V_215 . V_216 ) ;
if ( V_153 < 0 )
return V_153 ;
V_428 = V_215 . V_216 . V_212 [ V_429 ] ;
if ( V_215 . V_216 . V_210 != V_430 )
goto V_248;
if ( V_153 != V_431 )
goto V_248;
if ( ! ( V_428 & V_432 ) )
goto V_248;
return V_168 ;
V_248:
memset ( & V_215 , 0 , sizeof( V_215 ) ) ;
return - V_209 ;
}
static T_2
F_90 ( struct V_149 * V_149 , char T_3 * V_3 , T_4 V_168 ,
T_5 * V_169 )
{
struct V_151 * V_152 = V_149 -> V_157 ;
struct V_26 * V_27 = (struct V_26 * ) V_152 -> V_150 ;
char * V_228 ;
T_1 V_428 ;
int V_7 = 0 ;
V_152 -> V_213 = V_235 ;
if ( ! V_152 -> V_12 )
V_152 -> V_12 = F_2 ( V_418 , V_14 ) ;
if ( ! V_152 -> V_12 )
return 0 ;
V_228 = V_152 -> V_12 ;
if ( * V_169 )
return 0 ;
if ( V_215 . V_216 . V_210 != V_430 )
return 0 ;
V_428 = V_215 . V_216 . V_212 [ V_429 ] ;
if ( V_428 & V_433 )
V_7 = F_84 ( V_27 , V_228 , V_7 ) ;
if ( V_428 & V_434 )
V_7 = F_86 ( V_27 , V_228 , V_7 ) ;
if ( V_428 & V_435 )
V_7 = F_88 ( V_27 , V_228 , V_7 ) ;
return F_39 ( V_3 , V_168 , V_169 , V_228 , V_7 ) ;
}
void
F_91 ( struct V_26 * V_27 , enum V_436 V_437 ,
enum V_438 V_439 , enum V_440 V_441 ,
enum V_442 V_443 ,
struct V_44 * V_444 , T_1 V_445 )
{
#ifdef F_21
T_1 * V_402 , * V_399 , * V_400 , * V_401 ;
char V_446 [ V_447 ] ;
int V_7 = 0 ;
T_1 V_448 = 0 ;
T_1 * V_449 ;
T_1 V_5 ;
if ( V_215 . V_216 . V_210 != V_409 )
return;
V_402 = & V_215 . V_216 . V_212 [ V_403 ] ;
V_399 = & V_215 . V_216 . V_212 [ V_404 ] ;
V_400 = & V_215 . V_216 . V_212 [ V_405 ] ;
V_401 = & V_215 . V_216 . V_212 [ V_406 ] ;
if ( ! ( * V_399 & V_411 ) ||
( * V_400 == 0 ) ||
( * V_401 == 0 ) )
return;
if ( * V_402 != 0x9B )
return;
if ( ( V_439 == V_450 ) && ( V_441 == V_451 ) ) {
if ( * V_399 & V_452 ) {
V_448 |= V_452 ;
F_31 ( V_162 L_130
L_131 ,
V_443 , V_437 , V_445 ) ;
}
}
if ( ( V_439 == V_450 ) && ( V_441 == V_453 ) ) {
if ( * V_399 & V_454 ) {
V_448 |= V_454 ;
F_31 ( V_162 L_132
L_133 ,
V_443 , V_437 , V_445 ) ;
}
}
if ( ( V_439 == V_455 ) && ( V_441 == V_451 ) ) {
if ( * V_399 & V_456 ) {
V_448 |= V_456 ;
F_31 ( V_162 L_134
L_131 ,
V_443 , V_437 , V_445 ) ;
}
}
if ( ( V_439 == V_455 ) && ( V_441 == V_453 ) ) {
if ( * V_399 & V_457 ) {
V_448 |= V_457 ;
F_31 ( V_162 L_135
L_133 ,
V_443 , V_437 , V_445 ) ;
}
}
if ( V_448 ) {
V_449 = ( T_1 * ) V_444 -> V_72 ;
for ( V_5 = 0 ; V_5 < * V_401 ; V_5 ++ ) {
if ( ! ( V_5 % 8 ) ) {
if ( V_5 != 0 )
F_31 ( V_162 L_136 , V_446 ) ;
V_7 = 0 ;
V_7 += snprintf ( V_446 + V_7 ,
V_447 - V_7 ,
L_137 , V_5 ) ;
}
V_7 += snprintf ( V_446 + V_7 , V_447 - V_7 ,
L_56 , ( T_1 ) * V_449 ) ;
V_449 ++ ;
}
if ( ( V_5 - 1 ) % 8 )
F_31 ( V_162 L_136 , V_446 ) ;
( * V_400 ) -- ;
}
if ( * V_400 == 0 )
memset ( & V_215 , 0 , sizeof( V_215 ) ) ;
return;
#endif
}
void
F_92 ( struct V_26 * V_27 , V_91 * V_458 )
{
#ifdef F_21
T_1 * V_399 , * V_400 , * V_401 , * V_402 ;
char V_446 [ V_447 ] ;
int V_7 = 0 ;
T_1 * V_449 ;
T_7 * V_459 ;
T_1 V_5 , V_31 ;
if ( V_215 . V_216 . V_210 != V_408 )
return;
V_402 = & V_215 . V_216 . V_212 [ V_403 ] ;
V_399 = & V_215 . V_216 . V_212 [ V_404 ] ;
V_400 = & V_215 . V_216 . V_212 [ V_405 ] ;
V_401 = & V_215 . V_216 . V_212 [ V_406 ] ;
if ( ! ( * V_399 & V_410 ) ||
( * V_400 == 0 ) ||
( * V_401 == 0 ) )
return;
if ( ( * V_402 != V_460 ) &&
( * V_402 != V_458 -> V_461 ) )
return;
if ( * V_399 & V_462 ) {
F_31 ( V_162 L_138 ,
V_458 -> V_461 ) ;
V_449 = ( T_1 * ) V_458 ;
for ( V_5 = 0 ; V_5 < * V_401 ; V_5 ++ ) {
if ( ! ( V_5 % 8 ) ) {
if ( V_5 != 0 )
F_31 ( V_162 L_136 , V_446 ) ;
V_7 = 0 ;
memset ( V_446 , 0 , V_447 ) ;
V_7 += snprintf ( V_446 + V_7 ,
V_447 - V_7 ,
L_137 , V_5 ) ;
}
V_7 += snprintf ( V_446 + V_7 , V_447 - V_7 ,
L_56 ,
( ( T_1 ) * V_449 ) & 0xffffffff ) ;
V_449 ++ ;
}
if ( ( V_5 - 1 ) % 8 )
F_31 ( V_162 L_136 , V_446 ) ;
F_31 ( V_162 L_41 ) ;
}
if ( * V_399 & V_463 ) {
F_31 ( V_162 L_139 ,
V_458 -> V_461 ) ;
V_459 = ( T_7 * ) V_458 ;
for ( V_5 = 0 ; V_5 < * V_401 ; V_5 ++ ) {
if ( ! ( V_5 % 8 ) ) {
if ( V_5 != 0 )
F_31 ( V_162 L_136 , V_446 ) ;
V_7 = 0 ;
memset ( V_446 , 0 , V_447 ) ;
V_7 += snprintf ( V_446 + V_7 ,
V_447 - V_7 ,
L_137 , V_5 ) ;
}
for ( V_31 = 0 ; V_31 < 4 ; V_31 ++ ) {
V_7 += snprintf ( V_446 + V_7 ,
V_447 - V_7 ,
L_140 ,
( ( T_7 ) * V_459 ) & 0xff ) ;
V_459 ++ ;
}
V_7 += snprintf ( V_446 + V_7 ,
V_447 - V_7 , L_141 ) ;
}
if ( ( V_5 - 1 ) % 8 )
F_31 ( V_162 L_136 , V_446 ) ;
F_31 ( V_162 L_41 ) ;
}
( * V_400 ) -- ;
if ( * V_400 == 0 )
memset ( & V_215 , 0 , sizeof( V_215 ) ) ;
return;
#endif
}
inline void
F_93 ( struct V_1 * V_2 )
{
#ifdef F_21
struct V_26 * V_27 = V_2 -> V_27 ;
char V_115 [ 64 ] ;
T_1 V_464 , V_5 ;
bool V_465 = false ;
if ( ! V_15 )
return;
if ( ! V_466 ) {
V_466 = F_94 ( L_142 , NULL ) ;
F_95 ( & V_467 , 0 ) ;
if ( ! V_466 ) {
F_96 ( V_2 , V_162 , V_197 ,
L_143 ) ;
goto V_468;
}
}
if ( ! V_21 )
V_21 = V_147 ;
snprintf ( V_115 , sizeof( V_115 ) , L_144 , V_27 -> V_423 ) ;
if ( ! V_27 -> V_469 ) {
V_465 = true ;
V_27 -> V_469 =
F_94 ( V_115 , V_466 ) ;
if ( ! V_27 -> V_469 ) {
F_96 ( V_2 , V_162 , V_197 ,
L_145 ) ;
goto V_468;
}
F_97 ( & V_467 ) ;
F_95 ( & V_27 -> V_470 , 0 ) ;
snprintf ( V_115 , sizeof( V_115 ) , L_146 ) ;
V_27 -> V_471 =
F_98 ( V_115 , V_472 | V_473 | V_474 ,
V_27 -> V_469 ,
V_27 , & V_475 ) ;
if ( ! V_27 -> V_471 ) {
F_96 ( V_2 , V_162 , V_197 ,
L_147 ) ;
goto V_468;
}
if ( V_27 -> V_48 < V_476 ) {
snprintf ( V_115 , sizeof( V_115 ) , L_148 ) ;
V_27 -> V_477 =
F_98 ( V_115 ,
V_472 | V_473 | V_474 ,
V_27 -> V_469 ,
V_27 , & V_478 ) ;
if ( ! V_27 -> V_477 ) {
F_96 ( V_2 , V_162 , V_197 ,
L_149
L_150 ) ;
goto V_468;
}
} else
V_27 -> V_477 = NULL ;
if ( V_27 -> V_48 < V_476 ) {
snprintf ( V_115 , sizeof( V_115 ) , L_151 ) ;
V_27 -> V_479 =
F_98 ( V_115 ,
V_472 | V_473 | V_474 ,
V_27 -> V_469 ,
V_27 , & V_480 ) ;
if ( ! V_27 -> V_479 ) {
F_96 ( V_2 , V_162 , V_197 ,
L_152
L_153 ) ;
goto V_468;
}
} else
V_27 -> V_479 = NULL ;
snprintf ( V_115 , sizeof( V_115 ) , L_154 ) ;
V_27 -> V_481 =
F_98 ( V_115 , V_472 | V_473 | V_474 ,
V_27 -> V_469 ,
V_27 , & V_482 ) ;
if ( ! V_27 -> V_481 ) {
F_96 ( V_2 , V_162 , V_197 ,
L_155 ) ;
goto V_468;
}
snprintf ( V_115 , sizeof( V_115 ) , L_156 ) ;
V_27 -> V_483 =
F_98 ( V_115 , V_472 | V_473 | V_474 ,
V_27 -> V_469 ,
V_27 , & V_484 ) ;
if ( ! V_27 -> V_483 ) {
F_96 ( V_2 , V_162 , V_197 ,
L_157 ) ;
goto V_468;
}
snprintf ( V_115 , sizeof( V_115 ) , L_158 ) ;
V_27 -> V_194 =
F_98 ( V_115 , V_472 | V_473 | V_474 ,
V_27 -> V_469 ,
V_27 , & V_485 ) ;
if ( ! V_27 -> V_194 ) {
F_96 ( V_2 , V_162 , V_197 ,
L_159 ) ;
goto V_468;
}
V_27 -> V_195 = V_486 ;
snprintf ( V_115 , sizeof( V_115 ) , L_160 ) ;
V_27 -> V_189 =
F_98 ( V_115 , V_472 | V_473 | V_474 ,
V_27 -> V_469 ,
V_27 , & V_485 ) ;
if ( ! V_27 -> V_189 ) {
F_96 ( V_2 , V_162 , V_197 ,
L_161 ) ;
goto V_468;
}
snprintf ( V_115 , sizeof( V_115 ) , L_162 ) ;
V_27 -> V_191 =
F_98 ( V_115 , V_472 | V_473 | V_474 ,
V_27 -> V_469 ,
V_27 , & V_485 ) ;
if ( ! V_27 -> V_191 ) {
F_96 ( V_2 , V_162 , V_197 ,
L_163 ) ;
goto V_468;
}
snprintf ( V_115 , sizeof( V_115 ) , L_164 ) ;
V_27 -> V_177 =
F_98 ( V_115 , V_472 | V_473 | V_474 ,
V_27 -> V_469 ,
V_27 , & V_485 ) ;
if ( ! V_27 -> V_177 ) {
F_96 ( V_2 , V_162 , V_197 ,
L_165 ) ;
goto V_468;
}
snprintf ( V_115 , sizeof( V_115 ) , L_166 ) ;
V_27 -> V_179 =
F_98 ( V_115 , V_472 | V_473 | V_474 ,
V_27 -> V_469 ,
V_27 , & V_485 ) ;
if ( ! V_27 -> V_179 ) {
F_96 ( V_2 , V_162 , V_197 ,
L_167 ) ;
goto V_468;
}
snprintf ( V_115 , sizeof( V_115 ) , L_168 ) ;
V_27 -> V_181 =
F_98 ( V_115 , V_472 | V_473 | V_474 ,
V_27 -> V_469 ,
V_27 , & V_485 ) ;
if ( ! V_27 -> V_181 ) {
F_96 ( V_2 , V_162 , V_197 ,
L_169 ) ;
goto V_468;
}
snprintf ( V_115 , sizeof( V_115 ) , L_170 ) ;
V_27 -> V_183 =
F_98 ( V_115 , V_472 | V_473 | V_474 ,
V_27 -> V_469 ,
V_27 , & V_485 ) ;
if ( ! V_27 -> V_183 ) {
F_96 ( V_2 , V_162 , V_197 ,
L_171 ) ;
goto V_468;
}
snprintf ( V_115 , sizeof( V_115 ) , L_172 ) ;
V_27 -> V_185 =
F_98 ( V_115 , V_472 | V_473 | V_474 ,
V_27 -> V_469 ,
V_27 , & V_485 ) ;
if ( ! V_27 -> V_185 ) {
F_96 ( V_2 , V_162 , V_197 ,
L_173 ) ;
goto V_468;
}
snprintf ( V_115 , sizeof( V_115 ) , L_174 ) ;
V_27 -> V_187 =
F_98 ( V_115 , V_472 | V_473 | V_474 ,
V_27 -> V_469 ,
V_27 , & V_485 ) ;
if ( ! V_27 -> V_187 ) {
F_96 ( V_2 , V_162 , V_197 ,
L_175 ) ;
goto V_468;
}
if ( V_29 ) {
V_464 = V_29 - 1 ;
if ( V_464 & V_29 ) {
V_464 = V_29 ;
V_5 = 0 ;
while ( V_464 > 1 ) {
V_464 = V_464 >> 1 ;
V_5 ++ ;
}
V_29 = ( 1 << V_5 ) ;
F_31 ( V_162
L_176
L_177 , V_17 ) ;
}
}
snprintf ( V_115 , sizeof( V_115 ) , L_178 ) ;
V_27 -> V_487 =
F_98 ( V_115 , V_472 | V_473 | V_474 ,
V_27 -> V_469 ,
V_27 , & V_488 ) ;
if ( ! V_27 -> V_487 ) {
F_96 ( V_2 , V_162 , V_197 ,
L_179
L_180 ) ;
goto V_468;
}
if ( ! V_27 -> V_30 ) {
V_27 -> V_30 = F_2 (
( sizeof( struct V_10 ) *
V_29 ) ,
V_14 ) ;
if ( ! V_27 -> V_30 ) {
F_96 ( V_2 , V_162 , V_197 ,
L_181
L_182 ) ;
goto V_468;
}
F_95 ( & V_27 -> V_28 , 0 ) ;
memset ( V_27 -> V_30 , 0 ,
( sizeof( struct V_10 ) *
V_29 ) ) ;
}
}
snprintf ( V_115 , sizeof( V_115 ) , L_183 , V_2 -> V_489 ) ;
if ( ! V_2 -> V_490 ) {
V_2 -> V_490 =
F_94 ( V_115 , V_27 -> V_469 ) ;
if ( ! V_2 -> V_490 ) {
F_96 ( V_2 , V_162 , V_197 ,
L_184 ) ;
goto V_468;
}
F_97 ( & V_27 -> V_470 ) ;
}
if ( V_17 ) {
V_464 = V_17 - 1 ;
if ( V_464 & V_17 ) {
V_464 = V_17 ;
V_5 = 0 ;
while ( V_464 > 1 ) {
V_464 = V_464 >> 1 ;
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
F_96 ( V_2 , V_162 , V_197 ,
L_186
L_187 ) ;
goto V_468;
}
F_95 ( & V_2 -> V_16 , 0 ) ;
snprintf ( V_115 , sizeof( V_115 ) , L_188 ) ;
V_2 -> V_491 =
F_98 ( V_115 , V_472 | V_473 | V_474 ,
V_2 -> V_490 ,
V_2 , & V_492 ) ;
if ( ! V_2 -> V_491 ) {
F_96 ( V_2 , V_162 , V_197 ,
L_189
L_190 ) ;
goto V_468;
}
snprintf ( V_115 , sizeof( V_115 ) , L_191 ) ;
V_2 -> V_493 =
F_98 ( V_115 , V_472 | V_473 | V_474 ,
V_2 -> V_490 ,
V_2 , & V_494 ) ;
if ( ! V_2 -> V_493 ) {
F_96 ( V_2 , V_162 , V_197 ,
L_192 ) ;
goto V_468;
}
if ( ! V_465 )
goto V_468;
if ( V_27 -> V_48 < V_476 )
goto V_468;
snprintf ( V_115 , sizeof( V_115 ) , L_193 ) ;
if ( ! V_27 -> V_495 ) {
V_27 -> V_495 =
F_94 ( V_115 , V_27 -> V_469 ) ;
if ( ! V_27 -> V_495 ) {
F_96 ( V_2 , V_162 , V_197 ,
L_194 ) ;
goto V_468;
}
memset ( & V_215 , 0 , sizeof( V_215 ) ) ;
}
snprintf ( V_115 , sizeof( V_115 ) , L_195 ) ;
if ( ! V_27 -> V_496 ) {
V_27 -> V_496 =
F_98 ( V_115 , V_472 | V_473 | V_474 ,
V_27 -> V_495 , V_27 , & V_497 ) ;
if ( ! V_27 -> V_496 ) {
F_96 ( V_2 , V_162 , V_197 ,
L_196 ) ;
goto V_468;
}
V_215 . V_224 . V_245 = 0 ;
}
snprintf ( V_115 , sizeof( V_115 ) , L_197 ) ;
if ( ! V_27 -> V_498 ) {
V_27 -> V_498 =
F_98 ( V_115 , V_472 | V_473 | V_474 ,
V_27 -> V_495 , V_27 , & V_499 ) ;
if ( ! V_27 -> V_498 ) {
F_96 ( V_2 , V_162 , V_197 ,
L_198 ) ;
goto V_468;
}
V_215 . V_224 . V_245 = 0 ;
}
snprintf ( V_115 , sizeof( V_115 ) , L_199 ) ;
if ( ! V_27 -> V_500 ) {
V_27 -> V_500 =
F_98 ( V_115 , V_472 | V_473 ,
V_27 -> V_495 , V_27 , & V_501 ) ;
if ( ! V_27 -> V_500 ) {
F_96 ( V_2 , V_162 , V_197 ,
L_200 ) ;
goto V_468;
}
}
snprintf ( V_115 , sizeof( V_115 ) , L_201 ) ;
if ( ! V_27 -> V_502 ) {
V_27 -> V_502 =
F_98 ( V_115 , V_472 | V_473 | V_474 ,
V_27 -> V_495 , V_27 , & V_503 ) ;
if ( ! V_27 -> V_502 ) {
F_96 ( V_2 , V_162 , V_197 ,
L_202 ) ;
goto V_468;
}
}
snprintf ( V_115 , sizeof( V_115 ) , L_203 ) ;
if ( ! V_27 -> V_504 ) {
V_27 -> V_504 =
F_98 ( V_115 , V_472 | V_473 | V_474 ,
V_27 -> V_495 , V_27 , & V_505 ) ;
if ( ! V_27 -> V_504 ) {
F_96 ( V_2 , V_162 , V_197 ,
L_204 ) ;
goto V_468;
}
}
snprintf ( V_115 , sizeof( V_115 ) , L_205 ) ;
if ( ! V_27 -> V_506 ) {
V_27 -> V_506 =
F_98 ( V_115 , V_472 | V_473 | V_474 ,
V_27 -> V_495 , V_27 , & V_507 ) ;
if ( ! V_27 -> V_506 ) {
F_96 ( V_2 , V_162 , V_197 ,
L_206 ) ;
goto V_468;
}
}
snprintf ( V_115 , sizeof( V_115 ) , L_207 ) ;
if ( ! V_27 -> V_508 ) {
V_27 -> V_508 =
F_98 ( V_115 , V_472 | V_473 | V_474 ,
V_27 -> V_495 , V_27 , & V_509 ) ;
if ( ! V_27 -> V_508 ) {
F_96 ( V_2 , V_162 , V_197 ,
L_208 ) ;
goto V_468;
}
}
if ( V_27 -> V_264 . V_510 ) {
snprintf ( V_115 , sizeof( V_115 ) , L_209 ) ;
if ( ! V_27 -> V_511 ) {
V_27 -> V_511 =
F_98 ( V_115 ,
V_472 | V_473 | V_474 ,
V_27 -> V_495 , V_27 ,
& V_512 ) ;
if ( ! V_27 -> V_511 ) {
F_96 ( V_2 , V_162 , V_197 ,
L_210
L_211 ) ;
goto V_468;
}
}
}
V_468:
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
if ( V_2 -> V_491 ) {
F_101 ( V_2 -> V_491 ) ;
V_2 -> V_491 = NULL ;
}
if ( V_2 -> V_493 ) {
F_101 ( V_2 -> V_493 ) ;
V_2 -> V_493 = NULL ;
}
if ( V_2 -> V_490 ) {
F_101 ( V_2 -> V_490 ) ;
V_2 -> V_490 = NULL ;
F_102 ( & V_27 -> V_470 ) ;
}
if ( F_3 ( & V_27 -> V_470 ) == 0 ) {
if ( V_27 -> V_471 ) {
F_101 ( V_27 -> V_471 ) ;
V_27 -> V_471 = NULL ;
}
if ( V_27 -> V_477 ) {
F_101 ( V_27 -> V_477 ) ;
V_27 -> V_477 = NULL ;
}
if ( V_27 -> V_479 ) {
F_101 ( V_27 -> V_479 ) ;
V_27 -> V_479 = NULL ;
}
if ( V_27 -> V_481 ) {
F_101 ( V_27 -> V_481 ) ;
V_27 -> V_481 = NULL ;
}
if ( V_27 -> V_483 ) {
F_101 ( V_27 -> V_483 ) ;
V_27 -> V_483 = NULL ;
}
if ( V_27 -> V_194 ) {
F_101 ( V_27 -> V_194 ) ;
V_27 -> V_194 = NULL ;
}
if ( V_27 -> V_189 ) {
F_101 ( V_27 -> V_189 ) ;
V_27 -> V_189 = NULL ;
}
if ( V_27 -> V_191 ) {
F_101 ( V_27 -> V_191 ) ;
V_27 -> V_191 = NULL ;
}
if ( V_27 -> V_177 ) {
F_101 ( V_27 -> V_177 ) ;
V_27 -> V_177 = NULL ;
}
if ( V_27 -> V_179 ) {
F_101 ( V_27 -> V_179 ) ;
V_27 -> V_179 = NULL ;
}
if ( V_27 -> V_181 ) {
F_101 ( V_27 -> V_181 ) ;
V_27 -> V_181 = NULL ;
}
if ( V_27 -> V_183 ) {
F_101 ( V_27 -> V_183 ) ;
V_27 -> V_183 = NULL ;
}
if ( V_27 -> V_185 ) {
F_101 ( V_27 -> V_185 ) ;
V_27 -> V_185 = NULL ;
}
if ( V_27 -> V_187 ) {
F_101 ( V_27 -> V_187 ) ;
V_27 -> V_187 = NULL ;
}
if ( V_27 -> V_30 ) {
F_5 ( V_27 -> V_30 ) ;
V_27 -> V_30 = NULL ;
}
if ( V_27 -> V_487 ) {
F_101 ( V_27 -> V_487 ) ;
V_27 -> V_487 = NULL ;
}
if ( V_27 -> V_48 == V_476 ) {
if ( V_27 -> V_511 ) {
F_101 ( V_27 -> V_511 ) ;
V_27 -> V_511 = NULL ;
}
if ( V_27 -> V_508 ) {
F_101 ( V_27 -> V_508 ) ;
V_27 -> V_508 = NULL ;
}
if ( V_27 -> V_506 ) {
F_101 ( V_27 -> V_506 ) ;
V_27 -> V_506 = NULL ;
}
if ( V_27 -> V_504 ) {
F_101 ( V_27 -> V_504 ) ;
V_27 -> V_504 = NULL ;
}
if ( V_27 -> V_502 ) {
F_101 ( V_27 -> V_502 ) ;
V_27 -> V_502 = NULL ;
}
if ( V_27 -> V_500 ) {
F_101 ( V_27 -> V_500 ) ;
V_27 -> V_500 = NULL ;
}
if ( V_27 -> V_498 ) {
F_101 ( V_27 -> V_498 ) ;
V_27 -> V_498 = NULL ;
}
if ( V_27 -> V_496 ) {
F_101 ( V_27 -> V_496 ) ;
V_27 -> V_496 = NULL ;
}
if ( V_27 -> V_495 ) {
F_101 ( V_27 -> V_495 ) ;
V_27 -> V_495 = NULL ;
}
}
if ( V_27 -> V_469 ) {
F_101 ( V_27 -> V_469 ) ;
V_27 -> V_469 = NULL ;
F_102 ( & V_467 ) ;
}
if ( F_3 ( & V_467 ) == 0 ) {
F_101 ( V_466 ) ;
V_466 = NULL ;
}
}
#endif
return;
}
void
F_103 ( struct V_26 * V_27 )
{
int V_513 ;
F_104 ( V_27 ) ;
F_105 ( V_27 ) ;
for ( V_513 = 0 ; V_513 < V_27 -> V_294 ; V_513 ++ )
F_106 ( V_27 , V_513 ) ;
F_107 ( V_27 ) ;
F_108 ( V_27 ) ;
F_109 ( V_27 ) ;
F_110 ( V_27 ) ;
for ( V_513 = 0 ; V_513 < V_27 -> V_294 ; V_513 ++ )
F_111 ( V_27 , V_513 ) ;
for ( V_513 = 0 ; V_513 < V_27 -> V_294 ; V_513 ++ )
F_112 ( V_27 , V_513 ) ;
}
