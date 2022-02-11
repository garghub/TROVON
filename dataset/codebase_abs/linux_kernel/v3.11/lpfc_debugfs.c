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
int V_31 , V_5 , V_32 , V_33 , V_34 , V_35 ;
T_1 V_36 , V_37 , V_38 ;
struct V_39 * V_40 ;
struct V_41 * V_42 ;
struct V_43 * V_44 ;
struct V_45 * V_46 ;
struct V_47 * V_48 ;
if ( V_27 -> V_49 != 3 )
return 0 ;
V_31 = V_50 ;
F_8 ( & V_27 -> V_51 ) ;
V_5 = F_9 () ;
if ( V_5 > 1 ) {
V_52 ++ ;
if ( V_52 >= V_5 )
V_52 = 0 ;
}
else
V_52 = 0 ;
V_5 = V_52 ;
V_7 += snprintf ( V_3 + V_7 , V_4 - V_7 , L_2 , V_5 ) ;
V_42 = & V_27 -> V_42 [ V_5 ] ;
V_34 = 0 ;
F_10 (d_buf, &hbqs->hbq_buffer_list, list)
V_34 ++ ;
V_40 = V_53 [ V_5 ] ;
V_7 += snprintf ( V_3 + V_7 , V_4 - V_7 ,
L_3 ,
V_40 -> V_54 , V_40 -> V_55 , V_40 -> V_56 ,
V_40 -> V_57 , V_40 -> V_58 , V_40 -> V_59 , V_34 ) ;
V_37 = V_27 -> V_60 [ V_5 ] ;
V_38 = F_11 ( V_37 ) ;
V_7 += snprintf ( V_3 + V_7 , V_4 - V_7 ,
L_4 ,
V_42 -> V_61 , V_42 -> V_57 , V_42 -> V_62 ,
V_42 -> V_63 , V_42 -> V_64 , V_38 ) ;
V_44 = (struct V_43 * ) V_27 -> V_42 [ V_5 ] . V_65 ;
for ( V_32 = 0 ; V_32 < V_42 -> V_61 ; V_32 ++ ) {
V_7 += snprintf ( V_3 + V_7 , V_4 - V_7 ,
L_5 , V_32 ,
F_11 ( V_44 -> V_66 . V_67 ) ,
F_11 ( V_44 -> V_66 . V_68 . V_69 ) ,
F_11 ( V_44 -> V_70 ) ) ;
V_5 = 0 ;
V_33 = 0 ;
V_35 = V_42 -> V_62 - V_34 ;
if ( V_35 >= 0 ) {
if ( ( V_32 >= V_42 -> V_62 ) || ( V_32 < V_35 ) ) {
V_7 += snprintf ( V_3 + V_7 , V_4 - V_7 , L_6 ) ;
goto V_71;
}
}
else {
if ( ( V_32 >= V_42 -> V_62 ) &&
( V_32 < ( V_42 -> V_61 + V_35 ) ) ) {
V_7 += snprintf ( V_3 + V_7 , V_4 - V_7 , L_6 ) ;
goto V_71;
}
}
F_10 (d_buf, &hbqs->hbq_buffer_list, list) {
V_48 = F_12 ( V_46 , struct V_47 , V_72 ) ;
V_36 = ( ( V_73 ) V_48 -> V_72 . V_36 & 0xffffffff ) ;
if ( V_36 == F_11 ( V_44 -> V_66 . V_67 ) ) {
V_7 += snprintf ( V_3 + V_7 , V_4 - V_7 ,
L_7 , V_5 ,
V_48 -> V_72 . V_74 , V_48 -> V_75 ) ;
V_33 = 1 ;
break;
}
V_5 ++ ;
}
if ( ! V_33 ) {
V_7 += snprintf ( V_3 + V_7 , V_4 - V_7 , L_8 ) ;
}
V_71:
V_44 ++ ;
if ( V_7 > V_50 - 54 )
break;
}
F_13 ( & V_27 -> V_51 ) ;
return V_7 ;
}
static int
F_14 ( struct V_26 * V_27 , char * V_3 , int V_4 )
{
int V_7 = 0 ;
int V_5 , V_76 ;
T_1 * V_77 ;
char * V_12 ;
V_12 = F_2 ( 1024 , V_14 ) ;
if ( ! V_12 )
return 0 ;
V_76 = 0 ;
F_8 ( & V_27 -> V_51 ) ;
V_7 += snprintf ( V_3 + V_7 , V_4 - V_7 , L_9 ) ;
F_15 ( V_12 ,
V_27 -> V_78 + V_79 , 1024 ) ;
V_77 = ( T_1 * ) & V_12 [ 0 ] ;
V_76 = V_79 ;
V_79 += 1024 ;
if ( V_79 >= 4096 )
V_79 = 0 ;
V_5 = 1024 ;
while ( V_5 > 0 ) {
V_7 += snprintf ( V_3 + V_7 , V_4 - V_7 ,
L_10 ,
V_76 , * V_77 , * ( V_77 + 1 ) , * ( V_77 + 2 ) , * ( V_77 + 3 ) , * ( V_77 + 4 ) ,
* ( V_77 + 5 ) , * ( V_77 + 6 ) , * ( V_77 + 7 ) ) ;
V_77 += 8 ;
V_5 -= ( 8 * sizeof( T_1 ) ) ;
V_76 += ( 8 * sizeof( T_1 ) ) ;
}
F_13 ( & V_27 -> V_51 ) ;
F_5 ( V_12 ) ;
return V_7 ;
}
static int
F_16 ( struct V_26 * V_27 , char * V_3 , int V_4 )
{
int V_7 = 0 ;
int V_5 , V_76 ;
T_1 V_80 , V_81 , V_82 , V_83 ;
T_1 * V_77 ;
struct V_84 * V_85 ;
struct V_86 * V_87 = & V_27 -> V_88 ;
struct V_89 * V_90 ;
V_76 = 0 ;
F_8 ( & V_27 -> V_51 ) ;
V_7 += snprintf ( V_3 + V_7 , V_4 - V_7 , L_11 ) ;
V_77 = ( T_1 * ) V_27 -> V_91 . V_74 ;
V_5 = sizeof( V_92 ) ;
while ( V_5 > 0 ) {
V_7 += snprintf ( V_3 + V_7 , V_4 - V_7 ,
L_10 ,
V_76 , * V_77 , * ( V_77 + 1 ) , * ( V_77 + 2 ) , * ( V_77 + 3 ) , * ( V_77 + 4 ) ,
* ( V_77 + 5 ) , * ( V_77 + 6 ) , * ( V_77 + 7 ) ) ;
V_77 += 8 ;
V_5 -= ( 8 * sizeof( T_1 ) ) ;
V_76 += ( 8 * sizeof( T_1 ) ) ;
}
V_7 += snprintf ( V_3 + V_7 , V_4 - V_7 , L_12 ) ;
V_77 = ( T_1 * ) V_27 -> V_93 ;
V_5 = sizeof( V_94 ) ;
while ( V_5 > 0 ) {
V_7 += snprintf ( V_3 + V_7 , V_4 - V_7 ,
L_10 ,
V_76 , * V_77 , * ( V_77 + 1 ) , * ( V_77 + 2 ) , * ( V_77 + 3 ) , * ( V_77 + 4 ) ,
* ( V_77 + 5 ) , * ( V_77 + 6 ) , * ( V_77 + 7 ) ) ;
V_77 += 8 ;
V_5 -= ( 8 * sizeof( T_1 ) ) ;
V_76 += ( 8 * sizeof( T_1 ) ) ;
}
for ( V_5 = 0 ; V_5 < 4 ; V_5 ++ ) {
V_85 = & V_27 -> V_95 [ V_5 ] ;
V_90 = & V_87 -> V_96 [ V_5 ] ;
V_7 += snprintf ( V_3 + V_7 , V_4 - V_7 ,
L_13
L_14 ,
V_5 , V_85 -> V_97 , V_90 -> V_88 . V_98 . V_99 ,
V_90 -> V_88 . V_98 . V_100 ,
V_90 -> V_88 . V_98 . V_101 ,
V_90 -> V_102 , V_85 -> V_103 ,
V_90 -> V_88 . V_98 . V_104 ) ;
}
if ( V_27 -> V_49 <= V_105 ) {
V_80 = F_17 ( V_27 -> V_106 ) ;
V_81 = F_17 ( V_27 -> V_107 ) ;
V_82 = F_17 ( V_27 -> V_108 ) ;
V_83 = F_17 ( V_27 -> V_109 ) ;
V_7 += snprintf ( V_3 + V_7 , V_4 - V_7 , L_15
L_16 , V_80 , V_81 , V_82 , V_83 ) ;
}
F_13 ( & V_27 -> V_51 ) ;
return V_7 ;
}
static int
F_18 ( struct V_1 * V_2 , char * V_3 , int V_4 )
{
int V_7 = 0 ;
int V_31 ;
struct V_110 * V_111 = F_19 ( V_2 ) ;
struct V_112 * V_113 ;
unsigned char * V_114 , * V_115 ;
V_31 = ( V_116 / V_117 ) ;
F_8 ( V_111 -> V_118 ) ;
F_10 (ndlp, &vport->fc_nodes, nlp_listp) {
if ( ! V_31 ) {
V_7 += snprintf ( V_3 + V_7 , V_4 - V_7 ,
L_17 ) ;
break;
}
V_31 -- ;
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
V_152 -> V_12 = F_2 ( V_50 , V_14 ) ;
if ( ! V_152 -> V_12 ) {
F_5 ( V_152 ) ;
goto V_156;
}
V_152 -> V_7 = F_7 ( V_27 , V_152 -> V_12 ,
V_50 ) ;
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
V_73 V_177 = 0 ;
int V_31 = 0 ;
if ( V_175 == V_27 -> V_178 )
V_31 = snprintf ( V_176 , 32 , L_44 , V_27 -> V_179 ) ;
else if ( V_175 == V_27 -> V_180 )
V_31 = snprintf ( V_176 , 32 , L_44 , V_27 -> V_181 ) ;
else if ( V_175 == V_27 -> V_182 )
V_31 = snprintf ( V_176 , 32 , L_44 , V_27 -> V_183 ) ;
else if ( V_175 == V_27 -> V_184 )
V_31 = snprintf ( V_176 , 32 , L_44 , V_27 -> V_185 ) ;
else if ( V_175 == V_27 -> V_186 )
V_31 = snprintf ( V_176 , 32 , L_44 , V_27 -> V_187 ) ;
else if ( V_175 == V_27 -> V_188 )
V_31 = snprintf ( V_176 , 32 , L_44 , V_27 -> V_189 ) ;
else if ( V_175 == V_27 -> V_190 )
V_31 = snprintf ( V_176 , 32 , L_45 , V_27 -> V_191 ) ;
else if ( V_175 == V_27 -> V_192 ) {
memcpy ( & V_177 , & V_27 -> V_193 , sizeof( struct V_194 ) ) ;
V_177 = F_37 ( V_177 ) ;
V_31 = snprintf ( V_176 , 32 , L_46 , V_177 ) ;
} else if ( V_175 == V_27 -> V_195 ) {
if ( V_27 -> V_196 == ( V_197 ) ( - 1 ) )
V_31 = snprintf ( V_176 , 32 , L_47 ) ;
else
V_31 = snprintf ( V_176 , 32 , L_48 ,
( V_73 ) V_27 -> V_196 ) ;
} else
F_38 ( V_27 , V_162 , V_198 ,
L_49 ) ;
return F_39 ( V_3 , V_170 , V_171 , & V_176 , V_31 ) ;
}
static T_2
F_40 ( struct V_149 * V_149 , const char T_3 * V_3 ,
T_4 V_170 , T_5 * V_171 )
{
struct V_174 * V_175 = V_149 -> V_167 ;
struct V_26 * V_27 = V_149 -> V_157 ;
char V_199 [ 32 ] ;
V_73 V_177 = 0 ;
int V_4 ;
memset ( V_199 , 0 , 32 ) ;
V_4 = ( V_170 < 32 ) ? V_170 : 32 ;
if ( F_41 ( V_199 , V_3 , V_4 ) )
return 0 ;
if ( V_175 == V_27 -> V_195 ) {
if ( ( V_3 [ 0 ] == 'o' ) && ( V_3 [ 1 ] == 'f' ) && ( V_3 [ 2 ] == 'f' ) )
V_177 = ( V_73 ) ( - 1 ) ;
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
F_45 ( struct V_149 * V_149 , T_5 V_76 , int V_201 )
{
struct V_151 * V_152 = V_149 -> V_157 ;
return F_46 ( V_149 , V_76 , V_201 , V_152 -> V_7 ) ;
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
int V_289 , V_31 ;
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
F_8 ( & V_27 -> V_51 ) ;
if ( V_27 -> V_265 . V_294 && V_27 -> V_295 ) {
V_31 = V_27 -> V_295 ;
for ( V_289 = 0 ; V_289 < V_31 ; V_289 ++ ) {
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
V_292 -> V_61 ,
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
V_292 -> V_301 , V_292 -> V_61 ,
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
V_292 -> V_61 ,
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
V_292 -> V_301 , V_292 -> V_61 ,
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
V_292 -> V_301 , V_292 -> V_61 ,
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
V_292 -> V_301 , V_292 -> V_61 ,
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
V_292 -> V_301 , V_292 -> V_61 ,
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
V_292 -> V_61 ,
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
V_292 -> V_61 ,
V_292 -> V_302 ,
V_292 -> V_303 ,
V_292 -> V_304 ) ;
V_7 += snprintf ( V_229 + V_7 ,
V_293 - V_7 , L_41 ) ;
}
}
}
F_13 ( & V_27 -> V_51 ) ;
return F_39 ( V_3 , V_170 , V_171 , V_229 , V_7 ) ;
V_306:
V_7 += snprintf ( V_229 + V_7 ,
V_293 - V_7 , L_92 ) ;
F_13 ( & V_27 -> V_51 ) ;
return F_39 ( V_3 , V_170 , V_171 , V_229 , V_7 ) ;
}
static int
F_71 ( struct V_291 * V_317 , int V_6 , int V_228 )
{
if ( ( V_228 != 1 ) && ( V_228 != V_318 ) )
return - V_210 ;
if ( V_6 > V_317 -> V_61 - 1 )
return - V_210 ;
return 0 ;
}
static int
F_72 ( char * V_229 , int V_7 , struct V_291 * V_319 ,
T_1 V_6 )
{
int V_225 , V_320 ;
T_1 * V_321 ;
if ( ! V_229 || ! V_319 )
return 0 ;
V_320 = V_319 -> V_302 ;
V_7 += snprintf ( V_229 + V_7 , V_322 - V_7 ,
L_93 , V_6 ) ;
V_225 = 0 ;
V_321 = V_319 -> V_323 [ V_6 ] . V_324 ;
while ( V_320 > 0 ) {
V_7 += snprintf ( V_229 + V_7 , V_322 - V_7 ,
L_56 , * V_321 ) ;
V_321 ++ ;
V_225 += sizeof( T_1 ) ;
V_320 -= sizeof( T_1 ) ;
if ( V_320 > 0 && ! ( V_225 % ( 4 * sizeof( T_1 ) ) ) )
V_7 += snprintf ( V_229 + V_7 ,
V_322 - V_7 , L_41 ) ;
}
V_7 += snprintf ( V_229 + V_7 , V_322 - V_7 , L_41 ) ;
return V_7 ;
}
static T_2
F_73 ( struct V_149 * V_149 , char T_3 * V_3 , T_4 V_170 ,
T_5 * V_171 )
{
struct V_151 * V_152 = V_149 -> V_157 ;
T_1 V_325 , V_6 , V_228 ;
struct V_291 * V_319 = NULL ;
char * V_229 ;
int V_7 = 0 ;
V_152 -> V_214 = V_236 ;
if ( ! V_152 -> V_12 )
V_152 -> V_12 = F_2 ( V_322 , V_14 ) ;
if ( ! V_152 -> V_12 )
return 0 ;
V_229 = V_152 -> V_12 ;
if ( * V_171 )
return 0 ;
if ( V_216 . V_217 . V_211 == V_326 ) {
V_6 = V_216 . V_217 . V_213 [ V_327 ] ;
V_228 = V_216 . V_217 . V_213 [ V_328 ] ;
V_319 = (struct V_291 * ) V_216 . V_329 ;
} else
return 0 ;
if ( V_228 == V_318 )
goto V_330;
V_7 = F_72 ( V_229 , V_7 , V_319 , V_6 ) ;
return F_39 ( V_3 , V_170 , V_171 , V_229 , V_7 ) ;
V_330:
V_325 = V_216 . V_225 . V_246 ;
V_6 = V_325 ;
while ( V_7 < V_331 - V_319 -> V_302 ) {
V_7 = F_72 ( V_229 , V_7 , V_319 , V_6 ) ;
V_6 ++ ;
if ( V_6 > V_319 -> V_61 - 1 )
break;
}
if ( V_6 > V_319 -> V_61 - 1 )
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
T_1 V_332 , V_333 , V_334 , V_6 , V_228 , V_225 , V_247 ;
T_1 * V_321 ;
struct V_291 * V_319 ;
int V_153 ;
V_152 -> V_214 = V_215 ;
V_153 = F_50 ( V_3 , V_170 , & V_216 . V_217 ) ;
if ( V_153 < 0 )
return V_153 ;
V_333 = V_216 . V_217 . V_213 [ V_335 ] ;
V_334 = V_216 . V_217 . V_213 [ V_336 ] ;
V_6 = V_216 . V_217 . V_213 [ V_327 ] ;
V_228 = V_216 . V_217 . V_213 [ V_328 ] ;
V_225 = V_216 . V_217 . V_213 [ V_337 ] ;
V_247 = V_216 . V_217 . V_213 [ V_338 ] ;
if ( V_216 . V_217 . V_211 == V_221 ||
V_216 . V_217 . V_211 == V_222 ||
V_216 . V_217 . V_211 == V_223 ) {
if ( V_153 != V_339 )
goto V_249;
if ( V_228 != 1 )
goto V_249;
} else if ( V_216 . V_217 . V_211 == V_326 ) {
if ( V_153 != V_340 )
goto V_249;
} else
goto V_249;
switch ( V_333 ) {
case V_341 :
if ( V_27 -> V_265 . V_294 ) {
for ( V_332 = 0 ; V_332 < V_27 -> V_295 ;
V_332 ++ ) {
if ( V_27 -> V_265 . V_294 [ V_332 ] &&
V_27 -> V_265 . V_294 [ V_332 ] -> V_301 ==
V_334 ) {
V_153 = F_71 (
V_27 -> V_265 . V_294 [ V_332 ] ,
V_6 , V_228 ) ;
if ( V_153 )
goto V_249;
V_216 . V_329 =
V_27 -> V_265 . V_294 [ V_332 ] ;
goto V_342;
}
}
}
goto V_249;
break;
case V_343 :
if ( V_27 -> V_265 . V_311 &&
V_27 -> V_265 . V_311 -> V_301 == V_334 ) {
V_153 = F_71 (
V_27 -> V_265 . V_311 , V_6 , V_228 ) ;
if ( V_153 )
goto V_249;
V_216 . V_329 = V_27 -> V_265 . V_311 ;
goto V_342;
}
if ( V_27 -> V_265 . V_313 &&
V_27 -> V_265 . V_313 -> V_301 == V_334 ) {
V_153 = F_71 (
V_27 -> V_265 . V_313 , V_6 , V_228 ) ;
if ( V_153 )
goto V_249;
V_216 . V_329 = V_27 -> V_265 . V_313 ;
goto V_342;
}
if ( V_27 -> V_265 . V_307 ) {
V_332 = 0 ;
do {
if ( V_27 -> V_265 . V_307 [ V_332 ] &&
V_27 -> V_265 . V_307 [ V_332 ] -> V_301 ==
V_334 ) {
V_153 = F_71 (
V_27 -> V_265 . V_307 [ V_332 ] ,
V_6 , V_228 ) ;
if ( V_153 )
goto V_249;
V_216 . V_329 =
V_27 -> V_265 . V_307 [ V_332 ] ;
goto V_342;
}
} while ( ++ V_332 < V_27 -> V_295 );
}
goto V_249;
break;
case V_344 :
if ( V_27 -> V_265 . V_312 &&
V_27 -> V_265 . V_312 -> V_301 == V_334 ) {
V_153 = F_71 (
V_27 -> V_265 . V_312 , V_6 , V_228 ) ;
if ( V_153 )
goto V_249;
V_216 . V_329 = V_27 -> V_265 . V_312 ;
goto V_342;
}
goto V_249;
break;
case V_345 :
if ( V_27 -> V_265 . V_314 &&
V_27 -> V_265 . V_314 -> V_301 == V_334 ) {
V_153 = F_71 (
V_27 -> V_265 . V_314 , V_6 , V_228 ) ;
if ( V_153 )
goto V_249;
V_216 . V_329 = V_27 -> V_265 . V_314 ;
goto V_342;
}
if ( V_27 -> V_265 . V_310 ) {
for ( V_332 = 0 ; V_332 < V_27 -> V_295 ;
V_332 ++ ) {
if ( ! V_27 -> V_265 . V_310 [ V_332 ] )
continue;
if ( V_27 -> V_265 . V_310 [ V_332 ] -> V_301 ==
V_334 ) {
V_153 = F_71 (
V_27 -> V_265 . V_310 [ V_332 ] ,
V_6 , V_228 ) ;
if ( V_153 )
goto V_249;
V_216 . V_329 =
V_27 -> V_265 . V_310 [ V_332 ] ;
goto V_342;
}
}
}
goto V_249;
break;
case V_346 :
if ( V_27 -> V_265 . V_315 &&
V_27 -> V_265 . V_315 -> V_301 == V_334 ) {
V_153 = F_71 (
V_27 -> V_265 . V_315 , V_6 , V_228 ) ;
if ( V_153 )
goto V_249;
V_216 . V_329 = V_27 -> V_265 . V_315 ;
goto V_342;
}
if ( V_27 -> V_265 . V_316 &&
V_27 -> V_265 . V_316 -> V_301 == V_334 ) {
V_153 = F_71 (
V_27 -> V_265 . V_316 , V_6 , V_228 ) ;
if ( V_153 )
goto V_249;
V_216 . V_329 = V_27 -> V_265 . V_316 ;
goto V_342;
}
goto V_249;
break;
default:
goto V_249;
break;
}
V_342:
if ( V_216 . V_217 . V_211 == V_326 ) {
if ( V_228 == V_318 )
V_216 . V_225 . V_246 = V_6 ;
}
if ( V_216 . V_217 . V_211 == V_221 ||
V_216 . V_217 . V_211 == V_222 ||
V_216 . V_217 . V_211 == V_223 ) {
V_319 = (struct V_291 * ) V_216 . V_329 ;
if ( V_225 > V_319 -> V_302 / sizeof( T_1 ) - 1 )
goto V_249;
V_321 = V_319 -> V_323 [ V_6 ] . V_324 ;
V_321 += V_225 ;
if ( V_216 . V_217 . V_211 == V_221 )
* V_321 = V_247 ;
if ( V_216 . V_217 . V_211 == V_222 )
* V_321 |= V_247 ;
if ( V_216 . V_217 . V_211 == V_223 )
* V_321 &= ~ V_247 ;
}
return V_170 ;
V_249:
memset ( & V_216 , 0 , sizeof( V_216 ) ) ;
return - V_210 ;
}
static int
F_75 ( struct V_26 * V_27 , char * V_229 ,
int V_7 , T_1 V_347 )
{
if ( ! V_229 )
return 0 ;
switch ( V_347 ) {
case V_348 :
V_7 += snprintf ( V_229 + V_7 , V_349 - V_7 ,
L_94 ,
F_17 ( V_27 -> V_265 . V_350 ) ) ;
break;
case V_351 :
V_7 += snprintf ( V_229 + V_7 , V_349 - V_7 ,
L_95 ,
F_17 ( V_27 -> V_265 . V_352 ) ) ;
break;
case V_353 :
V_7 += snprintf ( V_229 + V_7 , V_349 - V_7 ,
L_96 ,
F_17 ( V_27 -> V_265 . V_354 ) ) ;
break;
case V_355 :
V_7 += snprintf ( V_229 + V_7 , V_349 - V_7 ,
L_97 ,
F_17 ( V_27 -> V_265 . V_356 ) ) ;
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
T_1 V_357 , V_5 ;
char * V_229 ;
int V_7 = 0 ;
V_152 -> V_214 = V_236 ;
if ( ! V_152 -> V_12 )
V_152 -> V_12 = F_2 ( V_349 , V_14 ) ;
if ( ! V_152 -> V_12 )
return 0 ;
V_229 = V_152 -> V_12 ;
if ( * V_171 )
return 0 ;
if ( V_216 . V_217 . V_211 == V_358 )
V_357 = V_216 . V_217 . V_213 [ V_359 ] ;
else
return 0 ;
if ( V_357 == V_360 )
for ( V_5 = 1 ; V_5 <= V_361 ; V_5 ++ )
V_7 = F_75 ( V_27 ,
V_229 , V_7 , V_5 ) ;
else
V_7 = F_75 ( V_27 ,
V_229 , V_7 , V_357 ) ;
return F_39 ( V_3 , V_170 , V_171 , V_229 , V_7 ) ;
}
static T_2
F_77 ( struct V_149 * V_149 , const char T_3 * V_3 ,
T_4 V_170 , T_5 * V_171 )
{
struct V_151 * V_152 = V_149 -> V_157 ;
struct V_26 * V_27 = (struct V_26 * ) V_152 -> V_150 ;
T_1 V_357 , V_247 , V_362 = 0 ;
void T_8 * V_363 ;
int V_153 ;
V_152 -> V_214 = V_215 ;
V_153 = F_50 ( V_3 , V_170 , & V_216 . V_217 ) ;
if ( V_153 < 0 )
return V_153 ;
V_357 = V_216 . V_217 . V_213 [ V_359 ] ;
V_247 = V_216 . V_217 . V_213 [ V_364 ] ;
if ( V_216 . V_217 . V_211 == V_365 ||
V_216 . V_217 . V_211 == V_366 ||
V_216 . V_217 . V_211 == V_367 ) {
if ( V_153 != V_368 )
goto V_249;
if ( V_357 > V_361 )
goto V_249;
} else if ( V_216 . V_217 . V_211 == V_358 ) {
if ( V_153 != V_369 )
goto V_249;
if ( ( V_357 > V_361 ) &&
( V_357 != V_360 ) )
goto V_249;
} else
goto V_249;
if ( V_216 . V_217 . V_211 == V_365 ||
V_216 . V_217 . V_211 == V_366 ||
V_216 . V_217 . V_211 == V_367 ) {
switch ( V_357 ) {
case V_348 :
V_363 = V_27 -> V_265 . V_350 ;
break;
case V_351 :
V_363 = V_27 -> V_265 . V_352 ;
break;
case V_353 :
V_363 = V_27 -> V_265 . V_354 ;
break;
case V_355 :
V_363 = V_27 -> V_265 . V_356 ;
break;
default:
goto V_249;
}
if ( V_216 . V_217 . V_211 == V_365 )
V_362 = V_247 ;
if ( V_216 . V_217 . V_211 == V_366 ) {
V_362 = F_17 ( V_363 ) ;
V_362 |= V_247 ;
}
if ( V_216 . V_217 . V_211 == V_367 ) {
V_362 = F_17 ( V_363 ) ;
V_362 &= ~ V_247 ;
}
F_69 ( V_362 , V_363 ) ;
F_17 ( V_363 ) ;
}
return V_170 ;
V_249:
memset ( & V_216 , 0 , sizeof( V_216 ) ) ;
return - V_210 ;
}
static int
F_78 ( struct V_26 * V_27 , char * V_229 ,
int V_7 , T_1 V_370 )
{
if ( ! V_229 )
return 0 ;
switch ( V_370 ) {
case V_371 :
V_7 += snprintf ( V_229 + V_7 , V_372 - V_7 ,
L_98 ,
F_17 ( V_27 -> V_265 . V_269 +
V_373 ) ) ;
break;
case V_374 :
V_7 += snprintf ( V_229 + V_7 , V_372 - V_7 ,
L_99 ,
F_17 ( V_27 -> V_265 . V_269 +
V_375 ) ) ;
break;
case V_376 :
V_7 += snprintf ( V_229 + V_7 , V_372 - V_7 ,
L_100 ,
F_17 ( V_27 -> V_265 . V_269 +
V_377 ) ) ;
break;
case V_378 :
V_7 += snprintf ( V_229 + V_7 , V_372 - V_7 ,
L_101 ,
F_17 ( V_27 -> V_265 . V_269 +
V_379 ) ) ;
break;
case V_380 :
V_7 += snprintf ( V_229 + V_7 , V_372 - V_7 ,
L_102 ,
F_17 ( V_27 -> V_265 . V_269 +
V_381 ) ) ;
break;
case V_382 :
V_7 += snprintf ( V_229 + V_7 , V_372 - V_7 ,
L_103 ,
F_17 ( V_27 -> V_265 . V_269 +
V_383 ) ) ;
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
T_1 V_384 , V_5 ;
char * V_229 ;
int V_7 = 0 ;
V_152 -> V_214 = V_236 ;
if ( ! V_152 -> V_12 )
V_152 -> V_12 = F_2 ( V_372 , V_14 ) ;
if ( ! V_152 -> V_12 )
return 0 ;
V_229 = V_152 -> V_12 ;
if ( * V_171 )
return 0 ;
if ( V_216 . V_217 . V_211 == V_385 )
V_384 = V_216 . V_217 . V_213 [ V_386 ] ;
else
return 0 ;
if ( V_384 == V_387 )
for ( V_5 = 1 ; V_5 <= V_388 ; V_5 ++ )
V_7 = F_78 ( V_27 ,
V_229 , V_7 , V_5 ) ;
else
V_7 = F_78 ( V_27 ,
V_229 , V_7 , V_384 ) ;
return F_39 ( V_3 , V_170 , V_171 , V_229 , V_7 ) ;
}
static T_2
F_80 ( struct V_149 * V_149 , const char T_3 * V_3 ,
T_4 V_170 , T_5 * V_171 )
{
struct V_151 * V_152 = V_149 -> V_157 ;
struct V_26 * V_27 = (struct V_26 * ) V_152 -> V_150 ;
T_1 V_384 , V_247 , V_362 = 0 ;
void T_8 * V_389 ;
int V_153 ;
V_152 -> V_214 = V_215 ;
V_153 = F_50 ( V_3 , V_170 , & V_216 . V_217 ) ;
if ( V_153 < 0 )
return V_153 ;
V_384 = V_216 . V_217 . V_213 [ V_386 ] ;
V_247 = V_216 . V_217 . V_213 [ V_390 ] ;
if ( V_216 . V_217 . V_211 == V_391 ||
V_216 . V_217 . V_211 == V_392 ||
V_216 . V_217 . V_211 == V_393 ) {
if ( V_153 != V_394 )
goto V_249;
if ( V_384 > V_388 )
goto V_249;
} else if ( V_216 . V_217 . V_211 == V_385 ) {
if ( V_153 != V_395 )
goto V_249;
if ( ( V_384 > V_388 ) &&
( V_384 != V_387 ) )
goto V_249;
} else
goto V_249;
if ( V_216 . V_217 . V_211 == V_391 ||
V_216 . V_217 . V_211 == V_392 ||
V_216 . V_217 . V_211 == V_393 ) {
switch ( V_384 ) {
case V_371 :
V_389 = V_27 -> V_265 . V_269 +
V_373 ;
break;
case V_374 :
V_389 = V_27 -> V_265 . V_269 +
V_375 ;
break;
case V_376 :
V_389 = V_27 -> V_265 . V_269 +
V_377 ;
break;
case V_378 :
V_389 = V_27 -> V_265 . V_269 +
V_379 ;
break;
case V_380 :
V_389 = V_27 -> V_265 . V_269 +
V_381 ;
break;
case V_382 :
V_389 = V_27 -> V_265 . V_269 +
V_383 ;
break;
default:
goto V_249;
}
if ( V_216 . V_217 . V_211 == V_391 )
V_362 = V_247 ;
if ( V_216 . V_217 . V_211 == V_392 ) {
V_362 = F_17 ( V_389 ) ;
V_362 |= V_247 ;
}
if ( V_216 . V_217 . V_211 == V_393 ) {
V_362 = F_17 ( V_389 ) ;
V_362 &= ~ V_247 ;
}
F_69 ( V_362 , V_389 ) ;
F_17 ( V_389 ) ;
}
return V_170 ;
V_249:
memset ( & V_216 , 0 , sizeof( V_216 ) ) ;
return - V_210 ;
}
static int
F_81 ( struct V_26 * V_27 , char * V_229 )
{
T_1 V_396 , V_397 , V_398 , V_399 ;
int V_7 = 0 ;
V_399 = V_216 . V_217 . V_213 [ V_400 ] ;
V_396 = V_216 . V_217 . V_213 [ V_401 ] ;
V_397 = V_216 . V_217 . V_213 [ V_402 ] ;
V_398 = V_216 . V_217 . V_213 [ V_403 ] ;
V_7 += snprintf ( V_229 + V_7 , V_404 - V_7 ,
L_104 , V_396 ) ;
V_7 += snprintf ( V_229 + V_7 , V_404 - V_7 ,
L_105 , V_397 ) ;
V_7 += snprintf ( V_229 + V_7 , V_404 - V_7 ,
L_106 , V_398 ) ;
V_7 += snprintf ( V_229 + V_7 , V_404 - V_7 ,
L_107 , V_399 ) ;
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
V_152 -> V_12 = F_2 ( V_404 , V_14 ) ;
if ( ! V_152 -> V_12 )
return 0 ;
V_229 = V_152 -> V_12 ;
if ( * V_171 )
return 0 ;
if ( ( V_216 . V_217 . V_211 != V_405 ) &&
( V_216 . V_217 . V_211 != V_406 ) )
return 0 ;
V_7 = F_81 ( V_27 , V_229 ) ;
return F_39 ( V_3 , V_170 , V_171 , V_229 , V_7 ) ;
}
static T_2
F_83 ( struct V_149 * V_149 , const char T_3 * V_3 ,
T_4 V_170 , T_5 * V_171 )
{
struct V_151 * V_152 = V_149 -> V_157 ;
T_1 V_396 , V_397 , V_398 , V_399 ;
int V_153 ;
V_152 -> V_214 = V_215 ;
V_153 = F_50 ( V_3 , V_170 , & V_216 . V_217 ) ;
if ( V_153 < 0 )
return V_153 ;
V_399 = V_216 . V_217 . V_213 [ V_400 ] ;
V_396 = V_216 . V_217 . V_213 [ V_401 ] ;
V_397 = V_216 . V_217 . V_213 [ V_402 ] ;
V_398 = V_216 . V_217 . V_213 [ V_403 ] ;
if ( V_216 . V_217 . V_211 == V_405 ) {
if ( ! ( V_396 & V_407 ) )
goto V_249;
if ( ( V_396 & ~ V_407 ) &&
( V_396 != V_408 ) )
goto V_249;
if ( V_398 > sizeof( V_92 ) )
goto V_249;
} else if ( V_216 . V_217 . V_211 == V_406 ) {
if ( ! ( V_396 & V_409 ) )
goto V_249;
if ( ( V_396 & ~ V_409 ) &&
( V_396 != V_408 ) )
goto V_249;
if ( V_398 > ( V_410 ) / 4 )
goto V_249;
if ( V_399 != 0x9b )
goto V_249;
} else
goto V_249;
if ( V_398 == 0 )
goto V_249;
if ( V_153 != V_411 )
goto V_249;
if ( V_399 & ~ 0xff )
goto V_249;
if ( V_397 == 0 )
goto V_412;
return V_170 ;
V_412:
memset ( & V_216 , 0 , sizeof( V_216 ) ) ;
return V_170 ;
V_249:
memset ( & V_216 , 0 , sizeof( V_216 ) ) ;
return - V_210 ;
}
static int
F_84 ( struct V_26 * V_27 , char * V_229 , int V_7 )
{
T_6 V_413 , V_414 ;
V_7 += snprintf ( V_229 + V_7 , V_415 - V_7 ,
L_108 ) ;
V_7 += snprintf ( V_229 + V_7 , V_415 - V_7 ,
L_109 ) ;
F_85 ( V_27 , V_416 ,
& V_413 , & V_414 ) ;
V_7 += snprintf ( V_229 + V_7 , V_415 - V_7 ,
L_110 , V_413 , V_414 ) ;
V_7 += snprintf ( V_229 + V_7 , V_415 - V_7 ,
L_111 ) ;
F_85 ( V_27 , V_417 ,
& V_413 , & V_414 ) ;
V_7 += snprintf ( V_229 + V_7 , V_415 - V_7 ,
L_110 , V_413 , V_414 ) ;
V_7 += snprintf ( V_229 + V_7 , V_415 - V_7 ,
L_112 ) ;
F_85 ( V_27 , V_418 ,
& V_413 , & V_414 ) ;
V_7 += snprintf ( V_229 + V_7 , V_415 - V_7 ,
L_110 , V_413 , V_414 ) ;
V_7 += snprintf ( V_229 + V_7 , V_415 - V_7 ,
L_113 ) ;
F_85 ( V_27 , V_419 ,
& V_413 , & V_414 ) ;
V_7 += snprintf ( V_229 + V_7 , V_415 - V_7 ,
L_110 , V_413 , V_414 ) ;
return V_7 ;
}
static int
F_86 ( struct V_26 * V_27 , char * V_229 , int V_7 )
{
T_6 V_413 , V_414 ;
int V_153 ;
V_7 += snprintf ( V_229 + V_7 , V_415 - V_7 ,
L_114 ) ;
V_7 += snprintf ( V_229 + V_7 , V_415 - V_7 ,
L_115 ) ;
V_153 = F_87 ( V_27 , V_416 ,
& V_413 , & V_414 ) ;
if ( ! V_153 )
V_7 += snprintf ( V_229 + V_7 , V_415 - V_7 ,
L_116 ,
V_27 -> V_420 , V_413 , V_414 ) ;
else
V_7 += snprintf ( V_229 + V_7 , V_415 - V_7 ,
L_117 ) ;
V_7 += snprintf ( V_229 + V_7 , V_415 - V_7 ,
L_118 ) ;
V_153 = F_87 ( V_27 , V_417 ,
& V_413 , & V_414 ) ;
if ( ! V_153 )
V_7 += snprintf ( V_229 + V_7 , V_415 - V_7 ,
L_116 ,
V_27 -> V_420 , V_413 , V_414 ) ;
else
V_7 += snprintf ( V_229 + V_7 , V_415 - V_7 ,
L_117 ) ;
V_7 += snprintf ( V_229 + V_7 , V_415 - V_7 ,
L_119 ) ;
V_153 = F_87 ( V_27 , V_418 ,
& V_413 , & V_414 ) ;
if ( ! V_153 )
V_7 += snprintf ( V_229 + V_7 , V_415 - V_7 ,
L_116 ,
V_27 -> V_420 , V_413 , V_414 ) ;
else
V_7 += snprintf ( V_229 + V_7 , V_415 - V_7 ,
L_117 ) ;
V_7 += snprintf ( V_229 + V_7 , V_415 - V_7 ,
L_120 ) ;
V_153 = F_87 ( V_27 , V_419 ,
& V_413 , & V_414 ) ;
if ( ! V_153 )
V_7 += snprintf ( V_229 + V_7 , V_415 - V_7 ,
L_116 ,
V_27 -> V_420 , V_413 , V_414 ) ;
else
V_7 += snprintf ( V_229 + V_7 , V_415 - V_7 ,
L_117 ) ;
return V_7 ;
}
static int
F_88 ( struct V_26 * V_27 , char * V_229 , int V_7 )
{
struct V_421 * V_422 ;
int V_6 ;
V_7 += snprintf ( V_229 + V_7 , V_415 - V_7 ,
L_121 ) ;
V_7 += snprintf ( V_229 + V_7 , V_415 - V_7 ,
L_122 ) ;
V_6 = 0 ;
F_10 (rsrc_blks, &phba->lpfc_vpi_blk_list, list) {
V_7 += snprintf ( V_229 + V_7 , V_415 - V_7 ,
L_123 ,
V_6 , V_422 -> V_423 ,
V_422 -> V_424 ) ;
V_6 ++ ;
}
V_7 += snprintf ( V_229 + V_7 , V_415 - V_7 ,
L_124 ) ;
V_6 = 0 ;
F_10 (rsrc_blks, &phba->sli4_hba.lpfc_vfi_blk_list,
list) {
V_7 += snprintf ( V_229 + V_7 , V_415 - V_7 ,
L_123 ,
V_6 , V_422 -> V_423 ,
V_422 -> V_424 ) ;
V_6 ++ ;
}
V_7 += snprintf ( V_229 + V_7 , V_415 - V_7 ,
L_125 ) ;
V_6 = 0 ;
F_10 (rsrc_blks, &phba->sli4_hba.lpfc_rpi_blk_list,
list) {
V_7 += snprintf ( V_229 + V_7 , V_415 - V_7 ,
L_123 ,
V_6 , V_422 -> V_423 ,
V_422 -> V_424 ) ;
V_6 ++ ;
}
V_7 += snprintf ( V_229 + V_7 , V_415 - V_7 ,
L_126 ) ;
V_6 = 0 ;
F_10 (rsrc_blks, &phba->sli4_hba.lpfc_xri_blk_list,
list) {
V_7 += snprintf ( V_229 + V_7 , V_415 - V_7 ,
L_123 ,
V_6 , V_422 -> V_423 ,
V_422 -> V_424 ) ;
V_6 ++ ;
}
return V_7 ;
}
static T_2
F_89 ( struct V_149 * V_149 , const char T_3 * V_3 ,
T_4 V_170 , T_5 * V_171 )
{
struct V_151 * V_152 = V_149 -> V_157 ;
T_1 V_425 ;
int V_153 ;
V_152 -> V_214 = V_215 ;
V_153 = F_50 ( V_3 , V_170 , & V_216 . V_217 ) ;
if ( V_153 < 0 )
return V_153 ;
V_425 = V_216 . V_217 . V_213 [ V_426 ] ;
if ( V_216 . V_217 . V_211 != V_427 )
goto V_249;
if ( V_153 != V_428 )
goto V_249;
if ( ! ( V_425 & V_429 ) )
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
T_1 V_425 ;
int V_7 = 0 ;
V_152 -> V_214 = V_236 ;
if ( ! V_152 -> V_12 )
V_152 -> V_12 = F_2 ( V_415 , V_14 ) ;
if ( ! V_152 -> V_12 )
return 0 ;
V_229 = V_152 -> V_12 ;
if ( * V_171 )
return 0 ;
if ( V_216 . V_217 . V_211 != V_427 )
return 0 ;
V_425 = V_216 . V_217 . V_213 [ V_426 ] ;
if ( V_425 & V_430 )
V_7 = F_84 ( V_27 , V_229 , V_7 ) ;
if ( V_425 & V_431 )
V_7 = F_86 ( V_27 , V_229 , V_7 ) ;
if ( V_425 & V_432 )
V_7 = F_88 ( V_27 , V_229 , V_7 ) ;
return F_39 ( V_3 , V_170 , V_171 , V_229 , V_7 ) ;
}
void
F_91 ( struct V_26 * V_27 , enum V_433 V_434 ,
enum V_435 V_436 , enum V_437 V_438 ,
enum V_439 V_440 ,
struct V_45 * V_441 , T_1 V_442 )
{
#ifdef F_21
T_1 * V_399 , * V_396 , * V_397 , * V_398 ;
char V_443 [ V_444 ] ;
int V_7 = 0 ;
T_1 V_445 = 0 ;
T_1 * V_446 ;
T_1 V_5 ;
if ( V_216 . V_217 . V_211 != V_406 )
return;
V_399 = & V_216 . V_217 . V_213 [ V_400 ] ;
V_396 = & V_216 . V_217 . V_213 [ V_401 ] ;
V_397 = & V_216 . V_217 . V_213 [ V_402 ] ;
V_398 = & V_216 . V_217 . V_213 [ V_403 ] ;
if ( ! ( * V_396 & V_408 ) ||
( * V_397 == 0 ) ||
( * V_398 == 0 ) )
return;
if ( * V_399 != 0x9B )
return;
if ( ( V_436 == V_447 ) && ( V_438 == V_448 ) ) {
if ( * V_396 & V_449 ) {
V_445 |= V_449 ;
F_31 ( V_162 L_127
L_128 ,
V_440 , V_434 , V_442 ) ;
}
}
if ( ( V_436 == V_447 ) && ( V_438 == V_450 ) ) {
if ( * V_396 & V_451 ) {
V_445 |= V_451 ;
F_31 ( V_162 L_129
L_130 ,
V_440 , V_434 , V_442 ) ;
}
}
if ( ( V_436 == V_452 ) && ( V_438 == V_448 ) ) {
if ( * V_396 & V_453 ) {
V_445 |= V_453 ;
F_31 ( V_162 L_131
L_128 ,
V_440 , V_434 , V_442 ) ;
}
}
if ( ( V_436 == V_452 ) && ( V_438 == V_450 ) ) {
if ( * V_396 & V_454 ) {
V_445 |= V_454 ;
F_31 ( V_162 L_132
L_130 ,
V_440 , V_434 , V_442 ) ;
}
}
if ( V_445 ) {
V_446 = ( T_1 * ) V_441 -> V_74 ;
for ( V_5 = 0 ; V_5 < * V_398 ; V_5 ++ ) {
if ( ! ( V_5 % 8 ) ) {
if ( V_5 != 0 )
F_31 ( V_162 L_133 , V_443 ) ;
V_7 = 0 ;
V_7 += snprintf ( V_443 + V_7 ,
V_444 - V_7 ,
L_134 , V_5 ) ;
}
V_7 += snprintf ( V_443 + V_7 , V_444 - V_7 ,
L_56 , ( T_1 ) * V_446 ) ;
V_446 ++ ;
}
if ( ( V_5 - 1 ) % 8 )
F_31 ( V_162 L_133 , V_443 ) ;
( * V_397 ) -- ;
}
if ( * V_397 == 0 )
memset ( & V_216 , 0 , sizeof( V_216 ) ) ;
return;
#endif
}
void
F_92 ( struct V_26 * V_27 , V_92 * V_455 )
{
#ifdef F_21
T_1 * V_396 , * V_397 , * V_398 , * V_399 ;
char V_443 [ V_444 ] ;
int V_7 = 0 ;
T_1 * V_446 ;
T_7 * V_456 ;
T_1 V_5 , V_32 ;
if ( V_216 . V_217 . V_211 != V_405 )
return;
V_399 = & V_216 . V_217 . V_213 [ V_400 ] ;
V_396 = & V_216 . V_217 . V_213 [ V_401 ] ;
V_397 = & V_216 . V_217 . V_213 [ V_402 ] ;
V_398 = & V_216 . V_217 . V_213 [ V_403 ] ;
if ( ! ( * V_396 & V_407 ) ||
( * V_397 == 0 ) ||
( * V_398 == 0 ) )
return;
if ( ( * V_399 != V_457 ) &&
( * V_399 != V_455 -> V_458 ) )
return;
if ( * V_396 & V_459 ) {
F_31 ( V_162 L_135 ,
V_455 -> V_458 ) ;
V_446 = ( T_1 * ) V_455 ;
for ( V_5 = 0 ; V_5 < * V_398 ; V_5 ++ ) {
if ( ! ( V_5 % 8 ) ) {
if ( V_5 != 0 )
F_31 ( V_162 L_133 , V_443 ) ;
V_7 = 0 ;
memset ( V_443 , 0 , V_444 ) ;
V_7 += snprintf ( V_443 + V_7 ,
V_444 - V_7 ,
L_134 , V_5 ) ;
}
V_7 += snprintf ( V_443 + V_7 , V_444 - V_7 ,
L_56 ,
( ( T_1 ) * V_446 ) & 0xffffffff ) ;
V_446 ++ ;
}
if ( ( V_5 - 1 ) % 8 )
F_31 ( V_162 L_133 , V_443 ) ;
F_31 ( V_162 L_41 ) ;
}
if ( * V_396 & V_460 ) {
F_31 ( V_162 L_136 ,
V_455 -> V_458 ) ;
V_456 = ( T_7 * ) V_455 ;
for ( V_5 = 0 ; V_5 < * V_398 ; V_5 ++ ) {
if ( ! ( V_5 % 8 ) ) {
if ( V_5 != 0 )
F_31 ( V_162 L_133 , V_443 ) ;
V_7 = 0 ;
memset ( V_443 , 0 , V_444 ) ;
V_7 += snprintf ( V_443 + V_7 ,
V_444 - V_7 ,
L_134 , V_5 ) ;
}
for ( V_32 = 0 ; V_32 < 4 ; V_32 ++ ) {
V_7 += snprintf ( V_443 + V_7 ,
V_444 - V_7 ,
L_137 ,
( ( T_7 ) * V_456 ) & 0xff ) ;
V_456 ++ ;
}
V_7 += snprintf ( V_443 + V_7 ,
V_444 - V_7 , L_138 ) ;
}
if ( ( V_5 - 1 ) % 8 )
F_31 ( V_162 L_133 , V_443 ) ;
F_31 ( V_162 L_41 ) ;
}
( * V_397 ) -- ;
if ( * V_397 == 0 )
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
T_1 V_461 , V_5 ;
if ( ! V_15 )
return;
if ( ! V_462 ) {
V_462 = F_94 ( L_139 , NULL ) ;
F_95 ( & V_463 , 0 ) ;
if ( ! V_462 ) {
F_96 ( V_2 , V_162 , V_198 ,
L_140 ) ;
goto V_464;
}
}
if ( ! V_21 )
V_21 = V_147 ;
snprintf ( V_115 , sizeof( V_115 ) , L_141 , V_27 -> V_420 ) ;
if ( ! V_27 -> V_465 ) {
V_27 -> V_465 =
F_94 ( V_115 , V_462 ) ;
if ( ! V_27 -> V_465 ) {
F_96 ( V_2 , V_162 , V_198 ,
L_142 ) ;
goto V_464;
}
F_97 ( & V_463 ) ;
F_95 ( & V_27 -> V_466 , 0 ) ;
snprintf ( V_115 , sizeof( V_115 ) , L_143 ) ;
V_27 -> V_467 =
F_98 ( V_115 , V_468 | V_469 | V_470 ,
V_27 -> V_465 ,
V_27 , & V_471 ) ;
if ( ! V_27 -> V_467 ) {
F_96 ( V_2 , V_162 , V_198 ,
L_144 ) ;
goto V_464;
}
if ( V_27 -> V_49 < V_472 ) {
snprintf ( V_115 , sizeof( V_115 ) , L_145 ) ;
V_27 -> V_473 =
F_98 ( V_115 ,
V_468 | V_469 | V_470 ,
V_27 -> V_465 ,
V_27 , & V_474 ) ;
if ( ! V_27 -> V_473 ) {
F_96 ( V_2 , V_162 , V_198 ,
L_146
L_147 ) ;
goto V_464;
}
} else
V_27 -> V_473 = NULL ;
if ( V_27 -> V_49 < V_472 ) {
snprintf ( V_115 , sizeof( V_115 ) , L_148 ) ;
V_27 -> V_475 =
F_98 ( V_115 ,
V_468 | V_469 | V_470 ,
V_27 -> V_465 ,
V_27 , & V_476 ) ;
if ( ! V_27 -> V_475 ) {
F_96 ( V_2 , V_162 , V_198 ,
L_149
L_150 ) ;
goto V_464;
}
} else
V_27 -> V_473 = NULL ;
snprintf ( V_115 , sizeof( V_115 ) , L_151 ) ;
V_27 -> V_477 =
F_98 ( V_115 , V_468 | V_469 | V_470 ,
V_27 -> V_465 ,
V_27 , & V_478 ) ;
if ( ! V_27 -> V_477 ) {
F_96 ( V_2 , V_162 , V_198 ,
L_152 ) ;
goto V_464;
}
snprintf ( V_115 , sizeof( V_115 ) , L_153 ) ;
V_27 -> V_479 =
F_98 ( V_115 , V_468 | V_469 | V_470 ,
V_27 -> V_465 ,
V_27 , & V_480 ) ;
if ( ! V_27 -> V_479 ) {
F_96 ( V_2 , V_162 , V_198 ,
L_154 ) ;
goto V_464;
}
snprintf ( V_115 , sizeof( V_115 ) , L_155 ) ;
V_27 -> V_195 =
F_98 ( V_115 , V_468 | V_469 | V_470 ,
V_27 -> V_465 ,
V_27 , & V_481 ) ;
if ( ! V_27 -> V_195 ) {
F_96 ( V_2 , V_162 , V_198 ,
L_156 ) ;
goto V_464;
}
V_27 -> V_196 = V_482 ;
snprintf ( V_115 , sizeof( V_115 ) , L_157 ) ;
V_27 -> V_190 =
F_98 ( V_115 , V_468 | V_469 | V_470 ,
V_27 -> V_465 ,
V_27 , & V_481 ) ;
if ( ! V_27 -> V_190 ) {
F_96 ( V_2 , V_162 , V_198 ,
L_158 ) ;
goto V_464;
}
snprintf ( V_115 , sizeof( V_115 ) , L_159 ) ;
V_27 -> V_192 =
F_98 ( V_115 , V_468 | V_469 | V_470 ,
V_27 -> V_465 ,
V_27 , & V_481 ) ;
if ( ! V_27 -> V_192 ) {
F_96 ( V_2 , V_162 , V_198 ,
L_160 ) ;
goto V_464;
}
snprintf ( V_115 , sizeof( V_115 ) , L_161 ) ;
V_27 -> V_178 =
F_98 ( V_115 , V_468 | V_469 | V_470 ,
V_27 -> V_465 ,
V_27 , & V_481 ) ;
if ( ! V_27 -> V_178 ) {
F_96 ( V_2 , V_162 , V_198 ,
L_162 ) ;
goto V_464;
}
snprintf ( V_115 , sizeof( V_115 ) , L_163 ) ;
V_27 -> V_180 =
F_98 ( V_115 , V_468 | V_469 | V_470 ,
V_27 -> V_465 ,
V_27 , & V_481 ) ;
if ( ! V_27 -> V_180 ) {
F_96 ( V_2 , V_162 , V_198 ,
L_164 ) ;
goto V_464;
}
snprintf ( V_115 , sizeof( V_115 ) , L_165 ) ;
V_27 -> V_182 =
F_98 ( V_115 , V_468 | V_469 | V_470 ,
V_27 -> V_465 ,
V_27 , & V_481 ) ;
if ( ! V_27 -> V_182 ) {
F_96 ( V_2 , V_162 , V_198 ,
L_166 ) ;
goto V_464;
}
snprintf ( V_115 , sizeof( V_115 ) , L_167 ) ;
V_27 -> V_184 =
F_98 ( V_115 , V_468 | V_469 | V_470 ,
V_27 -> V_465 ,
V_27 , & V_481 ) ;
if ( ! V_27 -> V_184 ) {
F_96 ( V_2 , V_162 , V_198 ,
L_168 ) ;
goto V_464;
}
snprintf ( V_115 , sizeof( V_115 ) , L_169 ) ;
V_27 -> V_186 =
F_98 ( V_115 , V_468 | V_469 | V_470 ,
V_27 -> V_465 ,
V_27 , & V_481 ) ;
if ( ! V_27 -> V_186 ) {
F_96 ( V_2 , V_162 , V_198 ,
L_170 ) ;
goto V_464;
}
snprintf ( V_115 , sizeof( V_115 ) , L_171 ) ;
V_27 -> V_188 =
F_98 ( V_115 , V_468 | V_469 | V_470 ,
V_27 -> V_465 ,
V_27 , & V_481 ) ;
if ( ! V_27 -> V_188 ) {
F_96 ( V_2 , V_162 , V_198 ,
L_172 ) ;
goto V_464;
}
if ( V_29 ) {
V_461 = V_29 - 1 ;
if ( V_461 & V_29 ) {
V_461 = V_29 ;
V_5 = 0 ;
while ( V_461 > 1 ) {
V_461 = V_461 >> 1 ;
V_5 ++ ;
}
V_29 = ( 1 << V_5 ) ;
F_31 ( V_162
L_173
L_174 , V_17 ) ;
}
}
snprintf ( V_115 , sizeof( V_115 ) , L_175 ) ;
V_27 -> V_483 =
F_98 ( V_115 , V_468 | V_469 | V_470 ,
V_27 -> V_465 ,
V_27 , & V_484 ) ;
if ( ! V_27 -> V_483 ) {
F_96 ( V_2 , V_162 , V_198 ,
L_176
L_177 ) ;
goto V_464;
}
if ( ! V_27 -> V_30 ) {
V_27 -> V_30 = F_2 (
( sizeof( struct V_10 ) *
V_29 ) ,
V_14 ) ;
if ( ! V_27 -> V_30 ) {
F_96 ( V_2 , V_162 , V_198 ,
L_178
L_179 ) ;
goto V_464;
}
F_95 ( & V_27 -> V_28 , 0 ) ;
memset ( V_27 -> V_30 , 0 ,
( sizeof( struct V_10 ) *
V_29 ) ) ;
}
}
snprintf ( V_115 , sizeof( V_115 ) , L_180 , V_2 -> V_485 ) ;
if ( ! V_2 -> V_486 ) {
V_2 -> V_486 =
F_94 ( V_115 , V_27 -> V_465 ) ;
if ( ! V_2 -> V_486 ) {
F_96 ( V_2 , V_162 , V_198 ,
L_181 ) ;
goto V_464;
}
F_97 ( & V_27 -> V_466 ) ;
}
if ( V_17 ) {
V_461 = V_17 - 1 ;
if ( V_461 & V_17 ) {
V_461 = V_17 ;
V_5 = 0 ;
while ( V_461 > 1 ) {
V_461 = V_461 >> 1 ;
V_5 ++ ;
}
V_17 = ( 1 << V_5 ) ;
F_31 ( V_162
L_182 ,
V_17 ) ;
}
}
V_2 -> V_18 = F_99 (
( sizeof( struct V_10 ) * V_17 ) ,
V_14 ) ;
if ( ! V_2 -> V_18 ) {
F_96 ( V_2 , V_162 , V_198 ,
L_183
L_184 ) ;
goto V_464;
}
F_95 ( & V_2 -> V_16 , 0 ) ;
snprintf ( V_115 , sizeof( V_115 ) , L_185 ) ;
V_2 -> V_487 =
F_98 ( V_115 , V_468 | V_469 | V_470 ,
V_2 -> V_486 ,
V_2 , & V_488 ) ;
if ( ! V_2 -> V_487 ) {
F_96 ( V_2 , V_162 , V_198 ,
L_186
L_187 ) ;
goto V_464;
}
snprintf ( V_115 , sizeof( V_115 ) , L_188 ) ;
V_2 -> V_489 =
F_98 ( V_115 , V_468 | V_469 | V_470 ,
V_2 -> V_486 ,
V_2 , & V_490 ) ;
if ( ! V_2 -> V_489 ) {
F_96 ( V_2 , V_162 , V_198 ,
L_189 ) ;
goto V_464;
}
if ( V_27 -> V_49 < V_472 )
goto V_464;
snprintf ( V_115 , sizeof( V_115 ) , L_190 ) ;
if ( ! V_27 -> V_491 ) {
V_27 -> V_491 =
F_94 ( V_115 , V_27 -> V_465 ) ;
if ( ! V_27 -> V_491 ) {
F_96 ( V_2 , V_162 , V_198 ,
L_191 ) ;
goto V_464;
}
memset ( & V_216 , 0 , sizeof( V_216 ) ) ;
}
snprintf ( V_115 , sizeof( V_115 ) , L_192 ) ;
if ( ! V_27 -> V_492 ) {
V_27 -> V_492 =
F_98 ( V_115 , V_468 | V_469 | V_470 ,
V_27 -> V_491 , V_27 , & V_493 ) ;
if ( ! V_27 -> V_492 ) {
F_96 ( V_2 , V_162 , V_198 ,
L_193 ) ;
goto V_464;
}
V_216 . V_225 . V_246 = 0 ;
}
snprintf ( V_115 , sizeof( V_115 ) , L_194 ) ;
if ( ! V_27 -> V_494 ) {
V_27 -> V_494 =
F_98 ( V_115 , V_468 | V_469 | V_470 ,
V_27 -> V_491 , V_27 , & V_495 ) ;
if ( ! V_27 -> V_494 ) {
F_96 ( V_2 , V_162 , V_198 ,
L_195 ) ;
goto V_464;
}
V_216 . V_225 . V_246 = 0 ;
}
snprintf ( V_115 , sizeof( V_115 ) , L_196 ) ;
if ( ! V_27 -> V_496 ) {
V_27 -> V_496 =
F_98 ( V_115 , V_468 | V_469 ,
V_27 -> V_491 , V_27 , & V_497 ) ;
if ( ! V_27 -> V_496 ) {
F_96 ( V_2 , V_162 , V_198 ,
L_197 ) ;
goto V_464;
}
}
snprintf ( V_115 , sizeof( V_115 ) , L_198 ) ;
if ( ! V_27 -> V_498 ) {
V_27 -> V_498 =
F_98 ( V_115 , V_468 | V_469 | V_470 ,
V_27 -> V_491 , V_27 , & V_499 ) ;
if ( ! V_27 -> V_498 ) {
F_96 ( V_2 , V_162 , V_198 ,
L_199 ) ;
goto V_464;
}
}
snprintf ( V_115 , sizeof( V_115 ) , L_200 ) ;
if ( ! V_27 -> V_500 ) {
V_27 -> V_500 =
F_98 ( V_115 , V_468 | V_469 | V_470 ,
V_27 -> V_491 , V_27 , & V_501 ) ;
if ( ! V_27 -> V_500 ) {
F_96 ( V_2 , V_162 , V_198 ,
L_201 ) ;
goto V_464;
}
}
snprintf ( V_115 , sizeof( V_115 ) , L_202 ) ;
if ( ! V_27 -> V_502 ) {
V_27 -> V_502 =
F_98 ( V_115 , V_468 | V_469 | V_470 ,
V_27 -> V_491 , V_27 , & V_503 ) ;
if ( ! V_27 -> V_502 ) {
F_96 ( V_2 , V_162 , V_198 ,
L_203 ) ;
goto V_464;
}
}
snprintf ( V_115 , sizeof( V_115 ) , L_204 ) ;
if ( ! V_27 -> V_504 ) {
V_27 -> V_504 =
F_98 ( V_115 , V_468 | V_469 | V_470 ,
V_27 -> V_491 , V_27 , & V_505 ) ;
if ( ! V_27 -> V_504 ) {
F_96 ( V_2 , V_162 , V_198 ,
L_205 ) ;
goto V_464;
}
}
if ( V_27 -> V_265 . V_506 ) {
snprintf ( V_115 , sizeof( V_115 ) , L_206 ) ;
if ( ! V_27 -> V_507 ) {
V_27 -> V_507 =
F_98 ( V_115 ,
V_468 | V_469 | V_470 ,
V_27 -> V_491 , V_27 ,
& V_508 ) ;
if ( ! V_27 -> V_507 ) {
F_96 ( V_2 , V_162 , V_198 ,
L_207
L_208 ) ;
goto V_464;
}
}
}
V_464:
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
if ( V_2 -> V_487 ) {
F_101 ( V_2 -> V_487 ) ;
V_2 -> V_487 = NULL ;
}
if ( V_2 -> V_489 ) {
F_101 ( V_2 -> V_489 ) ;
V_2 -> V_489 = NULL ;
}
if ( V_2 -> V_486 ) {
F_101 ( V_2 -> V_486 ) ;
V_2 -> V_486 = NULL ;
F_102 ( & V_27 -> V_466 ) ;
}
if ( F_3 ( & V_27 -> V_466 ) == 0 ) {
if ( V_27 -> V_467 ) {
F_101 ( V_27 -> V_467 ) ;
V_27 -> V_467 = NULL ;
}
if ( V_27 -> V_473 ) {
F_101 ( V_27 -> V_473 ) ;
V_27 -> V_473 = NULL ;
}
if ( V_27 -> V_475 ) {
F_101 ( V_27 -> V_475 ) ;
V_27 -> V_475 = NULL ;
}
if ( V_27 -> V_477 ) {
F_101 ( V_27 -> V_477 ) ;
V_27 -> V_477 = NULL ;
}
if ( V_27 -> V_479 ) {
F_101 ( V_27 -> V_479 ) ;
V_27 -> V_479 = NULL ;
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
if ( V_27 -> V_483 ) {
F_101 ( V_27 -> V_483 ) ;
V_27 -> V_483 = NULL ;
}
if ( V_27 -> V_49 == V_472 ) {
if ( V_27 -> V_507 ) {
F_101 ( V_27 -> V_507 ) ;
V_27 -> V_507 = NULL ;
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
if ( V_27 -> V_494 ) {
F_101 ( V_27 -> V_494 ) ;
V_27 -> V_494 = NULL ;
}
if ( V_27 -> V_492 ) {
F_101 ( V_27 -> V_492 ) ;
V_27 -> V_492 = NULL ;
}
if ( V_27 -> V_491 ) {
F_101 ( V_27 -> V_491 ) ;
V_27 -> V_491 = NULL ;
}
}
if ( V_27 -> V_465 ) {
F_101 ( V_27 -> V_465 ) ;
V_27 -> V_465 = NULL ;
F_102 ( & V_463 ) ;
}
if ( F_3 ( & V_463 ) == 0 ) {
F_101 ( V_462 ) ;
V_462 = NULL ;
}
}
#endif
return;
}
void
F_103 ( struct V_26 * V_27 )
{
int V_509 ;
F_104 ( V_27 ) ;
F_105 ( V_27 ) ;
for ( V_509 = 0 ; V_509 < V_27 -> V_295 ; V_509 ++ )
F_106 ( V_27 , V_509 ) ;
F_107 ( V_27 ) ;
F_108 ( V_27 ) ;
F_109 ( V_27 ) ;
F_110 ( V_27 ) ;
for ( V_509 = 0 ; V_509 < V_27 -> V_295 ; V_509 ++ )
F_111 ( V_27 , V_509 ) ;
for ( V_509 = 0 ; V_509 < V_27 -> V_295 ; V_509 ++ )
F_112 ( V_27 , V_509 ) ;
}
