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
struct V_151 * V_152 ;
T_5 V_202 = - 1 ;
V_152 = V_149 -> V_157 ;
switch ( V_201 ) {
case 0 :
V_202 = V_76 ;
break;
case 1 :
V_202 = V_149 -> V_203 + V_76 ;
break;
case 2 :
V_202 = V_152 -> V_7 - V_76 ;
}
return ( V_202 < 0 || V_202 > V_152 -> V_7 ) ? - V_204 : ( V_149 -> V_203 = V_202 ) ;
}
static T_2
F_46 ( struct V_149 * V_149 , char T_3 * V_3 ,
T_4 V_170 , T_5 * V_171 )
{
struct V_151 * V_152 = V_149 -> V_157 ;
return F_39 ( V_3 , V_170 , V_171 , V_152 -> V_12 ,
V_152 -> V_7 ) ;
}
static int
F_47 ( struct V_148 * V_148 , struct V_149 * V_149 )
{
struct V_151 * V_152 = V_149 -> V_157 ;
F_5 ( V_152 -> V_12 ) ;
F_5 ( V_152 ) ;
return 0 ;
}
static int
F_48 ( struct V_148 * V_148 , struct V_149 * V_149 )
{
struct V_151 * V_152 = V_149 -> V_157 ;
V_152 -> V_12 = NULL ;
F_5 ( V_152 ) ;
return 0 ;
}
static int F_49 ( const char T_3 * V_3 , T_4 V_170 ,
struct V_205 * V_206 )
{
char V_207 [ 64 ] ;
char * V_208 , * V_209 ;
int V_5 ;
T_4 V_210 ;
if ( ! F_50 ( V_211 , V_3 , V_170 ) )
return - V_212 ;
memset ( V_207 , 0 , sizeof( V_207 ) ) ;
memset ( V_206 , 0 , sizeof( * V_206 ) ) ;
V_210 = F_51 ( V_170 , ( sizeof( V_207 ) - 1 ) ) ;
if ( F_41 ( V_207 , V_3 , V_210 ) )
return - V_212 ;
V_208 = & V_207 [ 0 ] ;
V_209 = F_52 ( & V_208 , L_51 ) ;
if ( ! V_209 )
return - V_204 ;
V_206 -> V_213 = F_53 ( V_209 , NULL , 0 ) ;
if ( V_206 -> V_213 == 0 )
return - V_204 ;
for ( V_5 = 0 ; V_5 < V_214 ; V_5 ++ ) {
V_209 = F_52 ( & V_208 , L_51 ) ;
if ( ! V_209 )
return V_5 ;
V_206 -> V_215 [ V_5 ] = F_53 ( V_209 , NULL , 0 ) ;
}
return V_5 ;
}
static int
F_54 ( struct V_148 * V_148 , struct V_149 * V_149 )
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
F_55 ( struct V_148 * V_148 , struct V_149 * V_149 )
{
struct V_151 * V_152 = V_149 -> V_157 ;
F_5 ( V_152 -> V_12 ) ;
F_5 ( V_152 ) ;
return 0 ;
}
static int
F_56 ( struct V_148 * V_148 , struct V_149 * V_149 )
{
struct V_151 * V_152 = V_149 -> V_157 ;
if ( V_152 -> V_216 == V_217 ) {
switch ( V_218 . V_219 . V_213 ) {
case V_220 :
case V_221 :
case V_222 :
case V_223 :
case V_224 :
case V_225 :
memset ( & V_218 , 0 , sizeof( V_218 ) ) ;
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
F_57 ( struct V_149 * V_149 , char T_3 * V_3 , T_4 V_170 ,
T_5 * V_171 )
{
struct V_151 * V_152 = V_149 -> V_157 ;
struct V_26 * V_27 = (struct V_26 * ) V_152 -> V_150 ;
int V_226 , V_227 , V_7 = 0 , V_6 = V_228 ;
int V_229 , V_230 ;
char * V_231 ;
struct V_232 * V_233 ;
T_1 V_234 ;
T_6 V_235 ;
T_7 V_236 ;
V_233 = V_27 -> V_237 ;
if ( ! V_233 )
return 0 ;
V_152 -> V_216 = V_238 ;
if ( ! V_152 -> V_12 )
V_152 -> V_12 = F_2 ( V_239 , V_14 ) ;
if ( ! V_152 -> V_12 )
return 0 ;
V_231 = V_152 -> V_12 ;
if ( * V_171 )
return 0 ;
if ( V_218 . V_219 . V_213 == V_240 ) {
V_229 = V_218 . V_219 . V_215 [ V_241 ] ;
V_230 = V_218 . V_219 . V_215 [ V_242 ] ;
} else
return 0 ;
switch ( V_230 ) {
case V_243 :
F_58 ( V_233 , V_229 , & V_236 ) ;
V_7 += snprintf ( V_231 + V_7 , V_239 - V_7 ,
L_52 , V_229 , V_236 ) ;
break;
case V_244 :
F_59 ( V_233 , V_229 , & V_235 ) ;
V_7 += snprintf ( V_231 + V_7 , V_239 - V_7 ,
L_53 , V_229 , V_235 ) ;
break;
case V_245 :
F_60 ( V_233 , V_229 , & V_234 ) ;
V_7 += snprintf ( V_231 + V_7 , V_239 - V_7 ,
L_54 , V_229 , V_234 ) ;
break;
case V_246 :
goto V_247;
break;
default:
V_7 = 0 ;
break;
}
return F_39 ( V_3 , V_170 , V_171 , V_231 , V_7 ) ;
V_247:
V_226 = V_218 . V_227 . V_248 ;
V_227 = V_226 ;
V_7 += snprintf ( V_231 + V_7 , V_239 - V_7 ,
L_55 , V_226 ) ;
while ( V_6 > 0 ) {
F_60 ( V_233 , V_227 , & V_234 ) ;
V_7 += snprintf ( V_231 + V_7 , V_239 - V_7 ,
L_56 , V_234 ) ;
V_227 += sizeof( T_1 ) ;
if ( V_227 >= V_239 ) {
V_7 += snprintf ( V_231 + V_7 ,
V_239 - V_7 , L_41 ) ;
break;
}
V_6 -= sizeof( T_1 ) ;
if ( ! V_6 )
V_7 += snprintf ( V_231 + V_7 , V_239 - V_7 ,
L_41 ) ;
else if ( ! ( V_6 % ( 8 * sizeof( T_1 ) ) ) ) {
V_226 += ( 8 * sizeof( T_1 ) ) ;
V_7 += snprintf ( V_231 + V_7 , V_239 - V_7 ,
L_57 , V_226 ) ;
}
}
if ( V_6 == 0 ) {
V_218 . V_227 . V_248 += V_228 ;
if ( V_218 . V_227 . V_248 >= V_239 )
V_218 . V_227 . V_248 = 0 ;
} else
V_218 . V_227 . V_248 = 0 ;
return F_39 ( V_3 , V_170 , V_171 , V_231 , V_7 ) ;
}
static T_2
F_61 ( struct V_149 * V_149 , const char T_3 * V_3 ,
T_4 V_170 , T_5 * V_171 )
{
struct V_151 * V_152 = V_149 -> V_157 ;
struct V_26 * V_27 = (struct V_26 * ) V_152 -> V_150 ;
T_1 V_229 , V_249 , V_230 ;
T_1 V_234 ;
T_6 V_235 ;
T_7 V_236 ;
struct V_232 * V_233 ;
int V_153 ;
V_233 = V_27 -> V_237 ;
if ( ! V_233 )
return - V_212 ;
V_152 -> V_216 = V_217 ;
V_153 = F_49 ( V_3 , V_170 , & V_218 . V_219 ) ;
if ( V_153 < 0 )
return V_153 ;
if ( V_218 . V_219 . V_213 == V_240 ) {
if ( V_153 != V_250 )
goto V_251;
V_229 = V_218 . V_219 . V_215 [ V_241 ] ;
V_230 = V_218 . V_219 . V_215 [ V_242 ] ;
if ( V_230 == V_246 ) {
if ( V_229 % sizeof( T_1 ) )
goto V_251;
V_218 . V_227 . V_248 = V_229 ;
} else if ( ( V_230 != sizeof( T_7 ) ) &&
( V_230 != sizeof( T_6 ) ) &&
( V_230 != sizeof( T_1 ) ) )
goto V_251;
if ( V_230 == sizeof( T_7 ) ) {
if ( V_229 > V_239 - sizeof( T_7 ) )
goto V_251;
if ( V_229 % sizeof( T_7 ) )
goto V_251;
}
if ( V_230 == sizeof( T_6 ) ) {
if ( V_229 > V_239 - sizeof( T_6 ) )
goto V_251;
if ( V_229 % sizeof( T_6 ) )
goto V_251;
}
if ( V_230 == sizeof( T_1 ) ) {
if ( V_229 > V_239 - sizeof( T_1 ) )
goto V_251;
if ( V_229 % sizeof( T_1 ) )
goto V_251;
}
} else if ( V_218 . V_219 . V_213 == V_220 ||
V_218 . V_219 . V_213 == V_221 ||
V_218 . V_219 . V_213 == V_222 ) {
if ( V_153 != V_252 )
goto V_251;
V_229 = V_218 . V_219 . V_215 [ V_241 ] ;
V_230 = V_218 . V_219 . V_215 [ V_242 ] ;
V_249 = V_218 . V_219 . V_215 [ V_253 ] ;
if ( ( V_230 != sizeof( T_7 ) ) &&
( V_230 != sizeof( T_6 ) ) &&
( V_230 != sizeof( T_1 ) ) )
goto V_251;
if ( V_230 == sizeof( T_7 ) ) {
if ( V_229 > V_239 - sizeof( T_7 ) )
goto V_251;
if ( V_229 % sizeof( T_7 ) )
goto V_251;
if ( V_218 . V_219 . V_213 == V_220 )
F_62 ( V_233 , V_229 ,
( T_7 ) V_249 ) ;
if ( V_218 . V_219 . V_213 == V_221 ) {
V_153 = F_58 ( V_233 , V_229 , & V_236 ) ;
if ( ! V_153 ) {
V_236 |= ( T_7 ) V_249 ;
F_62 ( V_233 , V_229 ,
V_236 ) ;
}
}
if ( V_218 . V_219 . V_213 == V_222 ) {
V_153 = F_58 ( V_233 , V_229 , & V_236 ) ;
if ( ! V_153 ) {
V_236 &= ( T_7 ) ( ~ V_249 ) ;
F_62 ( V_233 , V_229 ,
V_236 ) ;
}
}
}
if ( V_230 == sizeof( T_6 ) ) {
if ( V_229 > V_239 - sizeof( T_6 ) )
goto V_251;
if ( V_229 % sizeof( T_6 ) )
goto V_251;
if ( V_218 . V_219 . V_213 == V_220 )
F_63 ( V_233 , V_229 ,
( T_6 ) V_249 ) ;
if ( V_218 . V_219 . V_213 == V_221 ) {
V_153 = F_59 ( V_233 , V_229 , & V_235 ) ;
if ( ! V_153 ) {
V_235 |= ( T_6 ) V_249 ;
F_63 ( V_233 , V_229 ,
V_235 ) ;
}
}
if ( V_218 . V_219 . V_213 == V_222 ) {
V_153 = F_59 ( V_233 , V_229 , & V_235 ) ;
if ( ! V_153 ) {
V_235 &= ( T_6 ) ( ~ V_249 ) ;
F_63 ( V_233 , V_229 ,
V_235 ) ;
}
}
}
if ( V_230 == sizeof( T_1 ) ) {
if ( V_229 > V_239 - sizeof( T_1 ) )
goto V_251;
if ( V_229 % sizeof( T_1 ) )
goto V_251;
if ( V_218 . V_219 . V_213 == V_220 )
F_64 ( V_233 , V_229 , V_249 ) ;
if ( V_218 . V_219 . V_213 == V_221 ) {
V_153 = F_60 ( V_233 , V_229 ,
& V_234 ) ;
if ( ! V_153 ) {
V_234 |= V_249 ;
F_64 ( V_233 , V_229 ,
V_234 ) ;
}
}
if ( V_218 . V_219 . V_213 == V_222 ) {
V_153 = F_60 ( V_233 , V_229 ,
& V_234 ) ;
if ( ! V_153 ) {
V_234 &= ~ V_249 ;
F_64 ( V_233 , V_229 ,
V_234 ) ;
}
}
}
} else
goto V_251;
return V_170 ;
V_251:
memset ( & V_218 , 0 , sizeof( V_218 ) ) ;
return - V_204 ;
}
static T_2
F_65 ( struct V_149 * V_149 , char T_3 * V_3 , T_4 V_170 ,
T_5 * V_171 )
{
struct V_151 * V_152 = V_149 -> V_157 ;
struct V_26 * V_27 = (struct V_26 * ) V_152 -> V_150 ;
int V_226 , V_227 , V_254 , V_7 = 0 , V_6 ;
int V_255 , V_256 , V_257 ;
char * V_231 ;
void T_8 * V_258 ;
T_1 V_259 ;
struct V_232 * V_233 ;
T_1 V_234 ;
V_233 = V_27 -> V_237 ;
if ( ! V_233 )
return 0 ;
V_152 -> V_216 = V_238 ;
if ( ! V_152 -> V_12 )
V_152 -> V_12 = F_2 ( V_260 , V_14 ) ;
if ( ! V_152 -> V_12 )
return 0 ;
V_231 = V_152 -> V_12 ;
if ( * V_171 )
return 0 ;
if ( V_218 . V_219 . V_213 == V_261 ) {
V_255 = V_218 . V_219 . V_215 [ V_262 ] ;
V_227 = V_218 . V_219 . V_215 [ V_263 ] ;
V_256 = V_218 . V_219 . V_215 [ V_264 ] ;
V_257 = V_218 . V_219 . V_215 [ V_265 ] ;
} else
return 0 ;
if ( V_256 == 0 )
return 0 ;
V_259 = F_66 ( V_266 , & V_27 -> V_267 . V_268 ) ;
if ( V_259 == V_269 ) {
if ( V_255 == V_270 )
V_258 = V_27 -> V_267 . V_271 ;
else if ( V_255 == V_272 )
V_258 = V_27 -> V_267 . V_273 ;
else if ( V_255 == V_274 )
V_258 = V_27 -> V_267 . V_275 ;
else
return 0 ;
} else if ( V_259 == V_276 ) {
if ( V_255 == V_270 )
V_258 = V_27 -> V_267 . V_271 ;
else
return 0 ;
} else
return 0 ;
if ( V_256 == V_277 ) {
V_254 = V_227 ;
V_234 = F_17 ( V_258 + V_254 ) ;
V_7 += snprintf ( V_231 + V_7 , V_260 - V_7 ,
L_58 , V_254 , V_234 ) ;
} else
goto V_278;
return F_39 ( V_3 , V_170 , V_171 , V_231 , V_7 ) ;
V_278:
V_226 = V_218 . V_227 . V_248 ;
V_254 = V_226 ;
V_7 += snprintf ( V_231 + V_7 , V_260 - V_7 ,
L_59 , V_226 ) ;
V_6 = V_279 ;
while ( V_6 > 0 ) {
V_234 = F_17 ( V_258 + V_254 ) ;
V_7 += snprintf ( V_231 + V_7 , V_260 - V_7 ,
L_56 , V_234 ) ;
V_254 += sizeof( T_1 ) ;
if ( V_256 == V_280 ) {
if ( V_254 >= V_257 ) {
V_7 += snprintf ( V_231 + V_7 ,
V_260 - V_7 , L_41 ) ;
break;
}
} else {
if ( V_254 >= V_227 +
( V_256 * sizeof( T_1 ) ) ) {
V_7 += snprintf ( V_231 + V_7 ,
V_260 - V_7 , L_41 ) ;
break;
}
}
V_6 -= sizeof( T_1 ) ;
if ( ! V_6 )
V_7 += snprintf ( V_231 + V_7 ,
V_260 - V_7 , L_41 ) ;
else if ( ! ( V_6 % ( 8 * sizeof( T_1 ) ) ) ) {
V_226 += ( 8 * sizeof( T_1 ) ) ;
V_7 += snprintf ( V_231 + V_7 ,
V_260 - V_7 ,
L_60 , V_226 ) ;
}
}
if ( V_6 == 0 ) {
V_218 . V_227 . V_248 += V_279 ;
if ( V_256 == V_280 ) {
if ( V_218 . V_227 . V_248 >= V_257 )
V_218 . V_227 . V_248 = 0 ;
} else {
if ( V_254 >= V_227 +
( V_256 * sizeof( T_1 ) ) )
V_218 . V_227 . V_248 = V_227 ;
}
} else {
if ( V_256 == V_280 )
V_218 . V_227 . V_248 = 0 ;
else
V_218 . V_227 . V_248 = V_227 ;
}
return F_39 ( V_3 , V_170 , V_171 , V_231 , V_7 ) ;
}
static T_2
F_67 ( struct V_149 * V_149 , const char T_3 * V_3 ,
T_4 V_170 , T_5 * V_171 )
{
struct V_151 * V_152 = V_149 -> V_157 ;
struct V_26 * V_27 = (struct V_26 * ) V_152 -> V_150 ;
T_1 V_255 , V_257 , V_227 , V_249 , V_256 ;
struct V_232 * V_233 ;
void T_8 * V_258 ;
T_1 V_259 ;
T_1 V_234 ;
int V_153 ;
V_233 = V_27 -> V_237 ;
if ( ! V_233 )
return - V_212 ;
V_152 -> V_216 = V_217 ;
V_153 = F_49 ( V_3 , V_170 , & V_218 . V_219 ) ;
if ( V_153 < 0 )
return V_153 ;
V_259 = F_66 ( V_266 , & V_27 -> V_267 . V_268 ) ;
V_255 = V_218 . V_219 . V_215 [ V_262 ] ;
if ( V_259 == V_269 ) {
if ( ( V_255 != V_270 ) &&
( V_255 != V_272 ) &&
( V_255 != V_274 ) )
goto V_251;
} else if ( V_259 == V_276 ) {
if ( V_255 != V_270 )
goto V_251;
} else
goto V_251;
if ( V_259 == V_269 ) {
if ( V_255 == V_270 ) {
V_218 . V_219 . V_215 [ V_265 ] =
V_281 ;
V_258 = V_27 -> V_267 . V_271 ;
} else if ( V_255 == V_272 ) {
V_218 . V_219 . V_215 [ V_265 ] =
V_282 ;
V_258 = V_27 -> V_267 . V_273 ;
} else if ( V_255 == V_274 ) {
V_218 . V_219 . V_215 [ V_265 ] =
V_283 ;
V_258 = V_27 -> V_267 . V_275 ;
} else
goto V_251;
} else if ( V_259 == V_276 ) {
if ( V_255 == V_270 ) {
V_218 . V_219 . V_215 [ V_265 ] =
V_284 ;
V_258 = V_27 -> V_267 . V_271 ;
} else
goto V_251;
} else
goto V_251;
V_227 = V_218 . V_219 . V_215 [ V_263 ] ;
if ( V_227 % sizeof( T_1 ) )
goto V_251;
V_257 = V_218 . V_219 . V_215 [ V_265 ] ;
if ( V_218 . V_219 . V_213 == V_261 ) {
if ( V_153 != V_285 )
goto V_251;
V_256 = V_218 . V_219 . V_215 [ V_264 ] ;
if ( V_256 == V_280 ) {
if ( V_227 > V_257 - sizeof( T_1 ) )
goto V_251;
V_218 . V_227 . V_248 = V_227 ;
} else if ( V_256 > V_277 ) {
if ( V_227 + V_256 * sizeof( T_1 ) > V_257 )
goto V_251;
V_218 . V_227 . V_248 = V_227 ;
} else if ( V_256 != V_277 )
goto V_251;
} else if ( V_218 . V_219 . V_213 == V_286 ||
V_218 . V_219 . V_213 == V_287 ||
V_218 . V_219 . V_213 == V_288 ) {
if ( V_153 != V_289 )
goto V_251;
V_256 = V_277 ;
V_249 = V_218 . V_219 . V_215 [ V_290 ] ;
if ( V_218 . V_219 . V_213 == V_286 ) {
F_68 ( V_249 , V_258 + V_227 ) ;
F_17 ( V_258 + V_227 ) ;
}
if ( V_218 . V_219 . V_213 == V_287 ) {
V_234 = F_17 ( V_258 + V_227 ) ;
V_234 |= V_249 ;
F_68 ( V_234 , V_258 + V_227 ) ;
F_17 ( V_258 + V_227 ) ;
}
if ( V_218 . V_219 . V_213 == V_288 ) {
V_234 = F_17 ( V_258 + V_227 ) ;
V_234 &= ~ V_249 ;
F_68 ( V_234 , V_258 + V_227 ) ;
F_17 ( V_258 + V_227 ) ;
}
} else
goto V_251;
return V_170 ;
V_251:
memset ( & V_218 , 0 , sizeof( V_218 ) ) ;
return - V_204 ;
}
static T_2
F_69 ( struct V_149 * V_149 , char T_3 * V_3 , T_4 V_170 ,
T_5 * V_171 )
{
struct V_151 * V_152 = V_149 -> V_157 ;
struct V_26 * V_27 = (struct V_26 * ) V_152 -> V_150 ;
int V_7 = 0 ;
char * V_231 ;
int V_291 , V_31 ;
int V_292 ;
struct V_293 * V_294 = NULL ;
if ( ! V_152 -> V_12 )
V_152 -> V_12 = F_2 ( V_295 , V_14 ) ;
if ( ! V_152 -> V_12 )
return 0 ;
V_231 = V_152 -> V_12 ;
V_292 = V_295 - 128 ;
if ( * V_171 )
return 0 ;
F_8 ( & V_27 -> V_51 ) ;
if ( V_27 -> V_267 . V_296 && V_27 -> V_297 ) {
V_31 = V_27 -> V_297 ;
for ( V_291 = 0 ; V_291 < V_31 ; V_291 ++ ) {
V_294 = V_27 -> V_267 . V_296 [ V_291 ] ;
if ( ! V_294 )
goto V_298;
V_7 += snprintf ( V_231 + V_7 ,
V_295 - V_7 ,
L_61
L_62
L_63 ,
V_294 -> V_299 , V_294 -> V_300 ,
V_294 -> V_301 , ( unsigned long long ) V_294 -> V_302 ) ;
V_7 += snprintf ( V_231 + V_7 ,
V_295 - V_7 ,
L_64
L_65
L_66 ,
V_294 -> V_303 ,
V_294 -> V_61 ,
V_294 -> V_304 ,
V_294 -> V_305 ,
V_294 -> V_306 ) ;
V_294 -> V_307 = 0 ;
V_7 += snprintf ( V_231 + V_7 ,
V_295 - V_7 , L_41 ) ;
if ( V_7 >= V_292 )
goto V_308;
V_298:
V_294 = V_27 -> V_267 . V_309 [ V_291 ] ;
V_7 += snprintf ( V_231 + V_7 ,
V_295 - V_7 ,
L_67 ) ;
V_7 += snprintf ( V_231 + V_7 ,
V_295 - V_7 ,
L_68
L_69
L_70 ,
V_294 -> V_310 ,
V_294 -> V_299 , V_294 -> V_300 ,
V_294 -> V_301 , ( unsigned long long ) V_294 -> V_302 ) ;
V_7 += snprintf ( V_231 + V_7 ,
V_295 - V_7 ,
L_71
L_65
L_66 ,
V_294 -> V_303 , V_294 -> V_61 ,
V_294 -> V_304 , V_294 -> V_305 ,
V_294 -> V_306 ) ;
V_294 -> V_311 = 0 ;
V_7 += snprintf ( V_231 + V_7 ,
V_295 - V_7 , L_41 ) ;
if ( V_7 >= V_292 )
goto V_308;
V_294 = V_27 -> V_267 . V_312 [ V_291 ] ;
V_7 += snprintf ( V_231 + V_7 ,
V_295 - V_7 ,
L_72 ) ;
V_7 += snprintf ( V_231 + V_7 ,
V_295 - V_7 ,
L_73
L_74 ,
V_294 -> V_310 ,
V_294 -> V_299 , ( unsigned long long ) V_294 -> V_302 ) ;
V_7 += snprintf ( V_231 + V_7 ,
V_295 - V_7 ,
L_75
L_65
L_66 ,
V_294 -> V_303 ,
V_294 -> V_61 ,
V_294 -> V_304 ,
V_294 -> V_305 ,
V_294 -> V_306 ) ;
V_7 += snprintf ( V_231 + V_7 ,
V_295 - V_7 , L_41 ) ;
if ( V_7 >= V_292 )
goto V_308;
if ( V_291 )
continue;
V_294 = V_27 -> V_267 . V_313 ;
if ( V_294 ) {
V_7 += snprintf ( V_231 + V_7 ,
V_295 - V_7 ,
L_76 ) ;
V_7 += snprintf ( V_231 + V_7 ,
V_295 - V_7 ,
L_68
L_77
L_70 ,
V_294 -> V_310 ,
V_294 -> V_299 , V_294 -> V_300 ,
V_294 -> V_301 ,
( unsigned long long ) V_294 -> V_302 ) ;
V_7 += snprintf ( V_231 + V_7 ,
V_295 - V_7 ,
L_71
L_65
L_66 ,
V_294 -> V_303 , V_294 -> V_61 ,
V_294 -> V_304 , V_294 -> V_305 ,
V_294 -> V_306 ) ;
V_7 += snprintf ( V_231 + V_7 ,
V_295 - V_7 , L_41 ) ;
if ( V_7 >= V_292 )
goto V_308;
}
V_294 = V_27 -> V_267 . V_314 ;
if ( V_294 ) {
V_7 += snprintf ( V_231 + V_7 ,
V_295 - V_7 ,
L_78 ) ;
V_7 += snprintf ( V_231 + V_7 ,
V_295 - V_7 ,
L_79 ,
V_27 -> V_267 . V_314 -> V_310 ) ;
V_7 += snprintf ( V_231 + V_7 ,
V_295 - V_7 ,
L_75
L_65
L_66 ,
V_294 -> V_303 , V_294 -> V_61 ,
V_294 -> V_304 , V_294 -> V_305 ,
V_294 -> V_306 ) ;
V_7 += snprintf ( V_231 + V_7 ,
V_295 - V_7 , L_41 ) ;
if ( V_7 >= V_292 )
goto V_308;
}
V_294 = V_27 -> V_267 . V_315 ;
if ( V_294 ) {
V_7 += snprintf ( V_231 + V_7 ,
V_295 - V_7 ,
L_80 ) ;
V_7 += snprintf ( V_231 + V_7 ,
V_295 - V_7 ,
L_68
L_81
L_70 ,
V_294 -> V_310 ,
V_294 -> V_299 , V_294 -> V_300 ,
V_294 -> V_301 ,
( unsigned long long ) V_294 -> V_302 ) ;
V_7 += snprintf ( V_231 + V_7 ,
V_295 - V_7 ,
L_82
L_65
L_66 ,
V_294 -> V_303 , V_294 -> V_61 ,
V_294 -> V_304 , V_294 -> V_305 ,
V_294 -> V_306 ) ;
V_294 -> V_311 = 0 ;
V_7 += snprintf ( V_231 + V_7 ,
V_295 - V_7 , L_41 ) ;
if ( V_7 >= V_292 )
goto V_308;
}
V_294 = V_27 -> V_267 . V_316 ;
if ( V_294 ) {
V_7 += snprintf ( V_231 + V_7 ,
V_295 - V_7 ,
L_83 ) ;
V_7 += snprintf ( V_231 + V_7 ,
V_295 - V_7 ,
L_73
L_84
L_85 ,
V_294 -> V_310 ,
V_294 -> V_299 ,
( unsigned long long ) V_294 -> V_302 ) ;
V_7 += snprintf ( V_231 + V_7 ,
V_295 - V_7 ,
L_75
L_65
L_66 ,
V_294 -> V_303 , V_294 -> V_61 ,
V_294 -> V_304 , V_294 -> V_305 ,
V_294 -> V_306 ) ;
V_7 += snprintf ( V_231 + V_7 ,
V_295 - V_7 , L_41 ) ;
if ( V_7 >= V_292 )
goto V_308;
}
if ( V_27 -> V_267 . V_317 && V_27 -> V_267 . V_318 ) {
V_294 = V_27 -> V_267 . V_317 ;
V_7 += snprintf ( V_231 + V_7 ,
V_295 - V_7 ,
L_86 ) ;
V_7 += snprintf ( V_231 + V_7 ,
V_295 - V_7 ,
L_73
L_87
L_88 ,
V_294 -> V_310 ,
V_294 -> V_299 , V_294 -> V_300 ,
V_294 -> V_301 ,
( unsigned long long ) V_294 -> V_302 ) ;
V_7 += snprintf ( V_231 + V_7 ,
V_295 - V_7 ,
L_89
L_65
L_90 ,
V_294 -> V_303 ,
V_294 -> V_61 ,
V_294 -> V_304 ,
V_294 -> V_305 ,
V_294 -> V_306 ) ;
V_294 = V_27 -> V_267 . V_318 ;
V_7 += snprintf ( V_231 + V_7 ,
V_295 - V_7 ,
L_91
L_65
L_90 ,
V_294 -> V_303 ,
V_294 -> V_61 ,
V_294 -> V_304 ,
V_294 -> V_305 ,
V_294 -> V_306 ) ;
V_7 += snprintf ( V_231 + V_7 ,
V_295 - V_7 , L_41 ) ;
}
}
}
F_13 ( & V_27 -> V_51 ) ;
return F_39 ( V_3 , V_170 , V_171 , V_231 , V_7 ) ;
V_308:
V_7 += snprintf ( V_231 + V_7 ,
V_295 - V_7 , L_92 ) ;
F_13 ( & V_27 -> V_51 ) ;
return F_39 ( V_3 , V_170 , V_171 , V_231 , V_7 ) ;
}
static int
F_70 ( struct V_293 * V_319 , int V_6 , int V_230 )
{
if ( ( V_230 != 1 ) && ( V_230 != V_320 ) )
return - V_204 ;
if ( V_6 > V_319 -> V_61 - 1 )
return - V_204 ;
return 0 ;
}
static int
F_71 ( char * V_231 , int V_7 , struct V_293 * V_321 ,
T_1 V_6 )
{
int V_227 , V_322 ;
T_1 * V_323 ;
if ( ! V_231 || ! V_321 )
return 0 ;
V_322 = V_321 -> V_304 ;
V_7 += snprintf ( V_231 + V_7 , V_324 - V_7 ,
L_93 , V_6 ) ;
V_227 = 0 ;
V_323 = V_321 -> V_325 [ V_6 ] . V_326 ;
while ( V_322 > 0 ) {
V_7 += snprintf ( V_231 + V_7 , V_324 - V_7 ,
L_56 , * V_323 ) ;
V_323 ++ ;
V_227 += sizeof( T_1 ) ;
V_322 -= sizeof( T_1 ) ;
if ( V_322 > 0 && ! ( V_227 % ( 4 * sizeof( T_1 ) ) ) )
V_7 += snprintf ( V_231 + V_7 ,
V_324 - V_7 , L_41 ) ;
}
V_7 += snprintf ( V_231 + V_7 , V_324 - V_7 , L_41 ) ;
return V_7 ;
}
static T_2
F_72 ( struct V_149 * V_149 , char T_3 * V_3 , T_4 V_170 ,
T_5 * V_171 )
{
struct V_151 * V_152 = V_149 -> V_157 ;
T_1 V_327 , V_6 , V_230 ;
struct V_293 * V_321 = NULL ;
char * V_231 ;
int V_7 = 0 ;
V_152 -> V_216 = V_238 ;
if ( ! V_152 -> V_12 )
V_152 -> V_12 = F_2 ( V_324 , V_14 ) ;
if ( ! V_152 -> V_12 )
return 0 ;
V_231 = V_152 -> V_12 ;
if ( * V_171 )
return 0 ;
if ( V_218 . V_219 . V_213 == V_328 ) {
V_6 = V_218 . V_219 . V_215 [ V_329 ] ;
V_230 = V_218 . V_219 . V_215 [ V_330 ] ;
V_321 = (struct V_293 * ) V_218 . V_331 ;
} else
return 0 ;
if ( V_230 == V_320 )
goto V_332;
V_7 = F_71 ( V_231 , V_7 , V_321 , V_6 ) ;
return F_39 ( V_3 , V_170 , V_171 , V_231 , V_7 ) ;
V_332:
V_327 = V_218 . V_227 . V_248 ;
V_6 = V_327 ;
while ( V_7 < V_333 - V_321 -> V_304 ) {
V_7 = F_71 ( V_231 , V_7 , V_321 , V_6 ) ;
V_6 ++ ;
if ( V_6 > V_321 -> V_61 - 1 )
break;
}
if ( V_6 > V_321 -> V_61 - 1 )
V_6 = 0 ;
V_218 . V_227 . V_248 = V_6 ;
return F_39 ( V_3 , V_170 , V_171 , V_231 , V_7 ) ;
}
static T_2
F_73 ( struct V_149 * V_149 , const char T_3 * V_3 ,
T_4 V_170 , T_5 * V_171 )
{
struct V_151 * V_152 = V_149 -> V_157 ;
struct V_26 * V_27 = (struct V_26 * ) V_152 -> V_150 ;
T_1 V_334 , V_335 , V_336 , V_6 , V_230 , V_227 , V_249 ;
T_1 * V_323 ;
struct V_293 * V_321 ;
int V_153 ;
V_152 -> V_216 = V_217 ;
V_153 = F_49 ( V_3 , V_170 , & V_218 . V_219 ) ;
if ( V_153 < 0 )
return V_153 ;
V_335 = V_218 . V_219 . V_215 [ V_337 ] ;
V_336 = V_218 . V_219 . V_215 [ V_338 ] ;
V_6 = V_218 . V_219 . V_215 [ V_329 ] ;
V_230 = V_218 . V_219 . V_215 [ V_330 ] ;
V_227 = V_218 . V_219 . V_215 [ V_339 ] ;
V_249 = V_218 . V_219 . V_215 [ V_340 ] ;
if ( V_218 . V_219 . V_213 == V_223 ||
V_218 . V_219 . V_213 == V_224 ||
V_218 . V_219 . V_213 == V_225 ) {
if ( V_153 != V_341 )
goto V_251;
if ( V_230 != 1 )
goto V_251;
} else if ( V_218 . V_219 . V_213 == V_328 ) {
if ( V_153 != V_342 )
goto V_251;
} else
goto V_251;
switch ( V_335 ) {
case V_343 :
if ( V_27 -> V_267 . V_296 ) {
for ( V_334 = 0 ; V_334 < V_27 -> V_297 ;
V_334 ++ ) {
if ( V_27 -> V_267 . V_296 [ V_334 ] &&
V_27 -> V_267 . V_296 [ V_334 ] -> V_303 ==
V_336 ) {
V_153 = F_70 (
V_27 -> V_267 . V_296 [ V_334 ] ,
V_6 , V_230 ) ;
if ( V_153 )
goto V_251;
V_218 . V_331 =
V_27 -> V_267 . V_296 [ V_334 ] ;
goto V_344;
}
}
}
goto V_251;
break;
case V_345 :
if ( V_27 -> V_267 . V_313 &&
V_27 -> V_267 . V_313 -> V_303 == V_336 ) {
V_153 = F_70 (
V_27 -> V_267 . V_313 , V_6 , V_230 ) ;
if ( V_153 )
goto V_251;
V_218 . V_331 = V_27 -> V_267 . V_313 ;
goto V_344;
}
if ( V_27 -> V_267 . V_315 &&
V_27 -> V_267 . V_315 -> V_303 == V_336 ) {
V_153 = F_70 (
V_27 -> V_267 . V_315 , V_6 , V_230 ) ;
if ( V_153 )
goto V_251;
V_218 . V_331 = V_27 -> V_267 . V_315 ;
goto V_344;
}
if ( V_27 -> V_267 . V_309 ) {
V_334 = 0 ;
do {
if ( V_27 -> V_267 . V_309 [ V_334 ] &&
V_27 -> V_267 . V_309 [ V_334 ] -> V_303 ==
V_336 ) {
V_153 = F_70 (
V_27 -> V_267 . V_309 [ V_334 ] ,
V_6 , V_230 ) ;
if ( V_153 )
goto V_251;
V_218 . V_331 =
V_27 -> V_267 . V_309 [ V_334 ] ;
goto V_344;
}
} while ( ++ V_334 < V_27 -> V_297 );
}
goto V_251;
break;
case V_346 :
if ( V_27 -> V_267 . V_314 &&
V_27 -> V_267 . V_314 -> V_303 == V_336 ) {
V_153 = F_70 (
V_27 -> V_267 . V_314 , V_6 , V_230 ) ;
if ( V_153 )
goto V_251;
V_218 . V_331 = V_27 -> V_267 . V_314 ;
goto V_344;
}
goto V_251;
break;
case V_347 :
if ( V_27 -> V_267 . V_316 &&
V_27 -> V_267 . V_316 -> V_303 == V_336 ) {
V_153 = F_70 (
V_27 -> V_267 . V_316 , V_6 , V_230 ) ;
if ( V_153 )
goto V_251;
V_218 . V_331 = V_27 -> V_267 . V_316 ;
goto V_344;
}
if ( V_27 -> V_267 . V_312 ) {
for ( V_334 = 0 ; V_334 < V_27 -> V_297 ;
V_334 ++ ) {
if ( ! V_27 -> V_267 . V_312 [ V_334 ] )
continue;
if ( V_27 -> V_267 . V_312 [ V_334 ] -> V_303 ==
V_336 ) {
V_153 = F_70 (
V_27 -> V_267 . V_312 [ V_334 ] ,
V_6 , V_230 ) ;
if ( V_153 )
goto V_251;
V_218 . V_331 =
V_27 -> V_267 . V_312 [ V_334 ] ;
goto V_344;
}
}
}
goto V_251;
break;
case V_348 :
if ( V_27 -> V_267 . V_317 &&
V_27 -> V_267 . V_317 -> V_303 == V_336 ) {
V_153 = F_70 (
V_27 -> V_267 . V_317 , V_6 , V_230 ) ;
if ( V_153 )
goto V_251;
V_218 . V_331 = V_27 -> V_267 . V_317 ;
goto V_344;
}
if ( V_27 -> V_267 . V_318 &&
V_27 -> V_267 . V_318 -> V_303 == V_336 ) {
V_153 = F_70 (
V_27 -> V_267 . V_318 , V_6 , V_230 ) ;
if ( V_153 )
goto V_251;
V_218 . V_331 = V_27 -> V_267 . V_318 ;
goto V_344;
}
goto V_251;
break;
default:
goto V_251;
break;
}
V_344:
if ( V_218 . V_219 . V_213 == V_328 ) {
if ( V_230 == V_320 )
V_218 . V_227 . V_248 = V_6 ;
}
if ( V_218 . V_219 . V_213 == V_223 ||
V_218 . V_219 . V_213 == V_224 ||
V_218 . V_219 . V_213 == V_225 ) {
V_321 = (struct V_293 * ) V_218 . V_331 ;
if ( V_227 > V_321 -> V_304 / sizeof( T_1 ) - 1 )
goto V_251;
V_323 = V_321 -> V_325 [ V_6 ] . V_326 ;
V_323 += V_227 ;
if ( V_218 . V_219 . V_213 == V_223 )
* V_323 = V_249 ;
if ( V_218 . V_219 . V_213 == V_224 )
* V_323 |= V_249 ;
if ( V_218 . V_219 . V_213 == V_225 )
* V_323 &= ~ V_249 ;
}
return V_170 ;
V_251:
memset ( & V_218 , 0 , sizeof( V_218 ) ) ;
return - V_204 ;
}
static int
F_74 ( struct V_26 * V_27 , char * V_231 ,
int V_7 , T_1 V_349 )
{
if ( ! V_231 )
return 0 ;
switch ( V_349 ) {
case V_350 :
V_7 += snprintf ( V_231 + V_7 , V_351 - V_7 ,
L_94 ,
F_17 ( V_27 -> V_267 . V_352 ) ) ;
break;
case V_353 :
V_7 += snprintf ( V_231 + V_7 , V_351 - V_7 ,
L_95 ,
F_17 ( V_27 -> V_267 . V_354 ) ) ;
break;
case V_355 :
V_7 += snprintf ( V_231 + V_7 , V_351 - V_7 ,
L_96 ,
F_17 ( V_27 -> V_267 . V_356 ) ) ;
break;
case V_357 :
V_7 += snprintf ( V_231 + V_7 , V_351 - V_7 ,
L_97 ,
F_17 ( V_27 -> V_267 . V_358 ) ) ;
break;
default:
break;
}
return V_7 ;
}
static T_2
F_75 ( struct V_149 * V_149 , char T_3 * V_3 , T_4 V_170 ,
T_5 * V_171 )
{
struct V_151 * V_152 = V_149 -> V_157 ;
struct V_26 * V_27 = (struct V_26 * ) V_152 -> V_150 ;
T_1 V_359 , V_5 ;
char * V_231 ;
int V_7 = 0 ;
V_152 -> V_216 = V_238 ;
if ( ! V_152 -> V_12 )
V_152 -> V_12 = F_2 ( V_351 , V_14 ) ;
if ( ! V_152 -> V_12 )
return 0 ;
V_231 = V_152 -> V_12 ;
if ( * V_171 )
return 0 ;
if ( V_218 . V_219 . V_213 == V_360 )
V_359 = V_218 . V_219 . V_215 [ V_361 ] ;
else
return 0 ;
if ( V_359 == V_362 )
for ( V_5 = 1 ; V_5 <= V_363 ; V_5 ++ )
V_7 = F_74 ( V_27 ,
V_231 , V_7 , V_5 ) ;
else
V_7 = F_74 ( V_27 ,
V_231 , V_7 , V_359 ) ;
return F_39 ( V_3 , V_170 , V_171 , V_231 , V_7 ) ;
}
static T_2
F_76 ( struct V_149 * V_149 , const char T_3 * V_3 ,
T_4 V_170 , T_5 * V_171 )
{
struct V_151 * V_152 = V_149 -> V_157 ;
struct V_26 * V_27 = (struct V_26 * ) V_152 -> V_150 ;
T_1 V_359 , V_249 , V_364 = 0 ;
void T_8 * V_365 ;
int V_153 ;
V_152 -> V_216 = V_217 ;
V_153 = F_49 ( V_3 , V_170 , & V_218 . V_219 ) ;
if ( V_153 < 0 )
return V_153 ;
V_359 = V_218 . V_219 . V_215 [ V_361 ] ;
V_249 = V_218 . V_219 . V_215 [ V_366 ] ;
if ( V_218 . V_219 . V_213 == V_367 ||
V_218 . V_219 . V_213 == V_368 ||
V_218 . V_219 . V_213 == V_369 ) {
if ( V_153 != V_370 )
goto V_251;
if ( V_359 > V_363 )
goto V_251;
} else if ( V_218 . V_219 . V_213 == V_360 ) {
if ( V_153 != V_371 )
goto V_251;
if ( ( V_359 > V_363 ) &&
( V_359 != V_362 ) )
goto V_251;
} else
goto V_251;
if ( V_218 . V_219 . V_213 == V_367 ||
V_218 . V_219 . V_213 == V_368 ||
V_218 . V_219 . V_213 == V_369 ) {
switch ( V_359 ) {
case V_350 :
V_365 = V_27 -> V_267 . V_352 ;
break;
case V_353 :
V_365 = V_27 -> V_267 . V_354 ;
break;
case V_355 :
V_365 = V_27 -> V_267 . V_356 ;
break;
case V_357 :
V_365 = V_27 -> V_267 . V_358 ;
break;
default:
goto V_251;
}
if ( V_218 . V_219 . V_213 == V_367 )
V_364 = V_249 ;
if ( V_218 . V_219 . V_213 == V_368 ) {
V_364 = F_17 ( V_365 ) ;
V_364 |= V_249 ;
}
if ( V_218 . V_219 . V_213 == V_369 ) {
V_364 = F_17 ( V_365 ) ;
V_364 &= ~ V_249 ;
}
F_68 ( V_364 , V_365 ) ;
F_17 ( V_365 ) ;
}
return V_170 ;
V_251:
memset ( & V_218 , 0 , sizeof( V_218 ) ) ;
return - V_204 ;
}
static int
F_77 ( struct V_26 * V_27 , char * V_231 ,
int V_7 , T_1 V_372 )
{
if ( ! V_231 )
return 0 ;
switch ( V_372 ) {
case V_373 :
V_7 += snprintf ( V_231 + V_7 , V_374 - V_7 ,
L_98 ,
F_17 ( V_27 -> V_267 . V_271 +
V_375 ) ) ;
break;
case V_376 :
V_7 += snprintf ( V_231 + V_7 , V_374 - V_7 ,
L_99 ,
F_17 ( V_27 -> V_267 . V_271 +
V_377 ) ) ;
break;
case V_378 :
V_7 += snprintf ( V_231 + V_7 , V_374 - V_7 ,
L_100 ,
F_17 ( V_27 -> V_267 . V_271 +
V_379 ) ) ;
break;
case V_380 :
V_7 += snprintf ( V_231 + V_7 , V_374 - V_7 ,
L_101 ,
F_17 ( V_27 -> V_267 . V_271 +
V_381 ) ) ;
break;
case V_382 :
V_7 += snprintf ( V_231 + V_7 , V_374 - V_7 ,
L_102 ,
F_17 ( V_27 -> V_267 . V_271 +
V_383 ) ) ;
break;
case V_384 :
V_7 += snprintf ( V_231 + V_7 , V_374 - V_7 ,
L_103 ,
F_17 ( V_27 -> V_267 . V_271 +
V_385 ) ) ;
break;
default:
break;
}
return V_7 ;
}
static T_2
F_78 ( struct V_149 * V_149 , char T_3 * V_3 , T_4 V_170 ,
T_5 * V_171 )
{
struct V_151 * V_152 = V_149 -> V_157 ;
struct V_26 * V_27 = (struct V_26 * ) V_152 -> V_150 ;
T_1 V_386 , V_5 ;
char * V_231 ;
int V_7 = 0 ;
V_152 -> V_216 = V_238 ;
if ( ! V_152 -> V_12 )
V_152 -> V_12 = F_2 ( V_374 , V_14 ) ;
if ( ! V_152 -> V_12 )
return 0 ;
V_231 = V_152 -> V_12 ;
if ( * V_171 )
return 0 ;
if ( V_218 . V_219 . V_213 == V_387 )
V_386 = V_218 . V_219 . V_215 [ V_388 ] ;
else
return 0 ;
if ( V_386 == V_389 )
for ( V_5 = 1 ; V_5 <= V_390 ; V_5 ++ )
V_7 = F_77 ( V_27 ,
V_231 , V_7 , V_5 ) ;
else
V_7 = F_77 ( V_27 ,
V_231 , V_7 , V_386 ) ;
return F_39 ( V_3 , V_170 , V_171 , V_231 , V_7 ) ;
}
static T_2
F_79 ( struct V_149 * V_149 , const char T_3 * V_3 ,
T_4 V_170 , T_5 * V_171 )
{
struct V_151 * V_152 = V_149 -> V_157 ;
struct V_26 * V_27 = (struct V_26 * ) V_152 -> V_150 ;
T_1 V_386 , V_249 , V_364 = 0 ;
void T_8 * V_391 ;
int V_153 ;
V_152 -> V_216 = V_217 ;
V_153 = F_49 ( V_3 , V_170 , & V_218 . V_219 ) ;
if ( V_153 < 0 )
return V_153 ;
V_386 = V_218 . V_219 . V_215 [ V_388 ] ;
V_249 = V_218 . V_219 . V_215 [ V_392 ] ;
if ( V_218 . V_219 . V_213 == V_393 ||
V_218 . V_219 . V_213 == V_394 ||
V_218 . V_219 . V_213 == V_395 ) {
if ( V_153 != V_396 )
goto V_251;
if ( V_386 > V_390 )
goto V_251;
} else if ( V_218 . V_219 . V_213 == V_387 ) {
if ( V_153 != V_397 )
goto V_251;
if ( ( V_386 > V_390 ) &&
( V_386 != V_389 ) )
goto V_251;
} else
goto V_251;
if ( V_218 . V_219 . V_213 == V_393 ||
V_218 . V_219 . V_213 == V_394 ||
V_218 . V_219 . V_213 == V_395 ) {
switch ( V_386 ) {
case V_373 :
V_391 = V_27 -> V_267 . V_271 +
V_375 ;
break;
case V_376 :
V_391 = V_27 -> V_267 . V_271 +
V_377 ;
break;
case V_378 :
V_391 = V_27 -> V_267 . V_271 +
V_379 ;
break;
case V_380 :
V_391 = V_27 -> V_267 . V_271 +
V_381 ;
break;
case V_382 :
V_391 = V_27 -> V_267 . V_271 +
V_383 ;
break;
case V_384 :
V_391 = V_27 -> V_267 . V_271 +
V_385 ;
break;
default:
goto V_251;
}
if ( V_218 . V_219 . V_213 == V_393 )
V_364 = V_249 ;
if ( V_218 . V_219 . V_213 == V_394 ) {
V_364 = F_17 ( V_391 ) ;
V_364 |= V_249 ;
}
if ( V_218 . V_219 . V_213 == V_395 ) {
V_364 = F_17 ( V_391 ) ;
V_364 &= ~ V_249 ;
}
F_68 ( V_364 , V_391 ) ;
F_17 ( V_391 ) ;
}
return V_170 ;
V_251:
memset ( & V_218 , 0 , sizeof( V_218 ) ) ;
return - V_204 ;
}
static int
F_80 ( struct V_26 * V_27 , char * V_231 )
{
T_1 V_398 , V_399 , V_400 , V_401 ;
int V_7 = 0 ;
V_401 = V_218 . V_219 . V_215 [ V_402 ] ;
V_398 = V_218 . V_219 . V_215 [ V_403 ] ;
V_399 = V_218 . V_219 . V_215 [ V_404 ] ;
V_400 = V_218 . V_219 . V_215 [ V_405 ] ;
V_7 += snprintf ( V_231 + V_7 , V_406 - V_7 ,
L_104 , V_398 ) ;
V_7 += snprintf ( V_231 + V_7 , V_406 - V_7 ,
L_105 , V_399 ) ;
V_7 += snprintf ( V_231 + V_7 , V_406 - V_7 ,
L_106 , V_400 ) ;
V_7 += snprintf ( V_231 + V_7 , V_406 - V_7 ,
L_107 , V_401 ) ;
return V_7 ;
}
static T_2
F_81 ( struct V_149 * V_149 , char T_3 * V_3 , T_4 V_170 ,
T_5 * V_171 )
{
struct V_151 * V_152 = V_149 -> V_157 ;
struct V_26 * V_27 = (struct V_26 * ) V_152 -> V_150 ;
char * V_231 ;
int V_7 = 0 ;
V_152 -> V_216 = V_238 ;
if ( ! V_152 -> V_12 )
V_152 -> V_12 = F_2 ( V_406 , V_14 ) ;
if ( ! V_152 -> V_12 )
return 0 ;
V_231 = V_152 -> V_12 ;
if ( * V_171 )
return 0 ;
if ( ( V_218 . V_219 . V_213 != V_407 ) &&
( V_218 . V_219 . V_213 != V_408 ) )
return 0 ;
V_7 = F_80 ( V_27 , V_231 ) ;
return F_39 ( V_3 , V_170 , V_171 , V_231 , V_7 ) ;
}
static T_2
F_82 ( struct V_149 * V_149 , const char T_3 * V_3 ,
T_4 V_170 , T_5 * V_171 )
{
struct V_151 * V_152 = V_149 -> V_157 ;
T_1 V_398 , V_399 , V_400 , V_401 ;
int V_153 ;
V_152 -> V_216 = V_217 ;
V_153 = F_49 ( V_3 , V_170 , & V_218 . V_219 ) ;
if ( V_153 < 0 )
return V_153 ;
V_401 = V_218 . V_219 . V_215 [ V_402 ] ;
V_398 = V_218 . V_219 . V_215 [ V_403 ] ;
V_399 = V_218 . V_219 . V_215 [ V_404 ] ;
V_400 = V_218 . V_219 . V_215 [ V_405 ] ;
if ( V_218 . V_219 . V_213 == V_407 ) {
if ( ! ( V_398 & V_409 ) )
goto V_251;
if ( ( V_398 & ~ V_409 ) &&
( V_398 != V_410 ) )
goto V_251;
if ( V_400 > sizeof( V_92 ) )
goto V_251;
} else if ( V_218 . V_219 . V_213 == V_408 ) {
if ( ! ( V_398 & V_411 ) )
goto V_251;
if ( ( V_398 & ~ V_411 ) &&
( V_398 != V_410 ) )
goto V_251;
if ( V_400 > ( V_412 ) / 4 )
goto V_251;
if ( V_401 != 0x9b )
goto V_251;
} else
goto V_251;
if ( V_400 == 0 )
goto V_251;
if ( V_153 != V_413 )
goto V_251;
if ( V_401 & ~ 0xff )
goto V_251;
if ( V_399 == 0 )
goto V_414;
return V_170 ;
V_414:
memset ( & V_218 , 0 , sizeof( V_218 ) ) ;
return V_170 ;
V_251:
memset ( & V_218 , 0 , sizeof( V_218 ) ) ;
return - V_204 ;
}
static int
F_83 ( struct V_26 * V_27 , char * V_231 , int V_7 )
{
T_6 V_415 , V_416 ;
V_7 += snprintf ( V_231 + V_7 , V_417 - V_7 ,
L_108 ) ;
V_7 += snprintf ( V_231 + V_7 , V_417 - V_7 ,
L_109 ) ;
F_84 ( V_27 , V_418 ,
& V_415 , & V_416 ) ;
V_7 += snprintf ( V_231 + V_7 , V_417 - V_7 ,
L_110 , V_415 , V_416 ) ;
V_7 += snprintf ( V_231 + V_7 , V_417 - V_7 ,
L_111 ) ;
F_84 ( V_27 , V_419 ,
& V_415 , & V_416 ) ;
V_7 += snprintf ( V_231 + V_7 , V_417 - V_7 ,
L_110 , V_415 , V_416 ) ;
V_7 += snprintf ( V_231 + V_7 , V_417 - V_7 ,
L_112 ) ;
F_84 ( V_27 , V_420 ,
& V_415 , & V_416 ) ;
V_7 += snprintf ( V_231 + V_7 , V_417 - V_7 ,
L_110 , V_415 , V_416 ) ;
V_7 += snprintf ( V_231 + V_7 , V_417 - V_7 ,
L_113 ) ;
F_84 ( V_27 , V_421 ,
& V_415 , & V_416 ) ;
V_7 += snprintf ( V_231 + V_7 , V_417 - V_7 ,
L_110 , V_415 , V_416 ) ;
return V_7 ;
}
static int
F_85 ( struct V_26 * V_27 , char * V_231 , int V_7 )
{
T_6 V_415 , V_416 ;
int V_153 ;
V_7 += snprintf ( V_231 + V_7 , V_417 - V_7 ,
L_114 ) ;
V_7 += snprintf ( V_231 + V_7 , V_417 - V_7 ,
L_115 ) ;
V_153 = F_86 ( V_27 , V_418 ,
& V_415 , & V_416 ) ;
if ( ! V_153 )
V_7 += snprintf ( V_231 + V_7 , V_417 - V_7 ,
L_116 ,
V_27 -> V_422 , V_415 , V_416 ) ;
else
V_7 += snprintf ( V_231 + V_7 , V_417 - V_7 ,
L_117 ) ;
V_7 += snprintf ( V_231 + V_7 , V_417 - V_7 ,
L_118 ) ;
V_153 = F_86 ( V_27 , V_419 ,
& V_415 , & V_416 ) ;
if ( ! V_153 )
V_7 += snprintf ( V_231 + V_7 , V_417 - V_7 ,
L_116 ,
V_27 -> V_422 , V_415 , V_416 ) ;
else
V_7 += snprintf ( V_231 + V_7 , V_417 - V_7 ,
L_117 ) ;
V_7 += snprintf ( V_231 + V_7 , V_417 - V_7 ,
L_119 ) ;
V_153 = F_86 ( V_27 , V_420 ,
& V_415 , & V_416 ) ;
if ( ! V_153 )
V_7 += snprintf ( V_231 + V_7 , V_417 - V_7 ,
L_116 ,
V_27 -> V_422 , V_415 , V_416 ) ;
else
V_7 += snprintf ( V_231 + V_7 , V_417 - V_7 ,
L_117 ) ;
V_7 += snprintf ( V_231 + V_7 , V_417 - V_7 ,
L_120 ) ;
V_153 = F_86 ( V_27 , V_421 ,
& V_415 , & V_416 ) ;
if ( ! V_153 )
V_7 += snprintf ( V_231 + V_7 , V_417 - V_7 ,
L_116 ,
V_27 -> V_422 , V_415 , V_416 ) ;
else
V_7 += snprintf ( V_231 + V_7 , V_417 - V_7 ,
L_117 ) ;
return V_7 ;
}
static int
F_87 ( struct V_26 * V_27 , char * V_231 , int V_7 )
{
struct V_423 * V_424 ;
int V_6 ;
V_7 += snprintf ( V_231 + V_7 , V_417 - V_7 ,
L_121 ) ;
V_7 += snprintf ( V_231 + V_7 , V_417 - V_7 ,
L_122 ) ;
V_6 = 0 ;
F_10 (rsrc_blks, &phba->lpfc_vpi_blk_list, list) {
V_7 += snprintf ( V_231 + V_7 , V_417 - V_7 ,
L_123 ,
V_6 , V_424 -> V_425 ,
V_424 -> V_426 ) ;
V_6 ++ ;
}
V_7 += snprintf ( V_231 + V_7 , V_417 - V_7 ,
L_124 ) ;
V_6 = 0 ;
F_10 (rsrc_blks, &phba->sli4_hba.lpfc_vfi_blk_list,
list) {
V_7 += snprintf ( V_231 + V_7 , V_417 - V_7 ,
L_123 ,
V_6 , V_424 -> V_425 ,
V_424 -> V_426 ) ;
V_6 ++ ;
}
V_7 += snprintf ( V_231 + V_7 , V_417 - V_7 ,
L_125 ) ;
V_6 = 0 ;
F_10 (rsrc_blks, &phba->sli4_hba.lpfc_rpi_blk_list,
list) {
V_7 += snprintf ( V_231 + V_7 , V_417 - V_7 ,
L_123 ,
V_6 , V_424 -> V_425 ,
V_424 -> V_426 ) ;
V_6 ++ ;
}
V_7 += snprintf ( V_231 + V_7 , V_417 - V_7 ,
L_126 ) ;
V_6 = 0 ;
F_10 (rsrc_blks, &phba->sli4_hba.lpfc_xri_blk_list,
list) {
V_7 += snprintf ( V_231 + V_7 , V_417 - V_7 ,
L_123 ,
V_6 , V_424 -> V_425 ,
V_424 -> V_426 ) ;
V_6 ++ ;
}
return V_7 ;
}
static T_2
F_88 ( struct V_149 * V_149 , const char T_3 * V_3 ,
T_4 V_170 , T_5 * V_171 )
{
struct V_151 * V_152 = V_149 -> V_157 ;
T_1 V_427 ;
int V_153 ;
V_152 -> V_216 = V_217 ;
V_153 = F_49 ( V_3 , V_170 , & V_218 . V_219 ) ;
if ( V_153 < 0 )
return V_153 ;
V_427 = V_218 . V_219 . V_215 [ V_428 ] ;
if ( V_218 . V_219 . V_213 != V_429 )
goto V_251;
if ( V_153 != V_430 )
goto V_251;
if ( ! ( V_427 & V_431 ) )
goto V_251;
return V_170 ;
V_251:
memset ( & V_218 , 0 , sizeof( V_218 ) ) ;
return - V_204 ;
}
static T_2
F_89 ( struct V_149 * V_149 , char T_3 * V_3 , T_4 V_170 ,
T_5 * V_171 )
{
struct V_151 * V_152 = V_149 -> V_157 ;
struct V_26 * V_27 = (struct V_26 * ) V_152 -> V_150 ;
char * V_231 ;
T_1 V_427 ;
int V_7 = 0 ;
V_152 -> V_216 = V_238 ;
if ( ! V_152 -> V_12 )
V_152 -> V_12 = F_2 ( V_417 , V_14 ) ;
if ( ! V_152 -> V_12 )
return 0 ;
V_231 = V_152 -> V_12 ;
if ( * V_171 )
return 0 ;
if ( V_218 . V_219 . V_213 != V_429 )
return 0 ;
V_427 = V_218 . V_219 . V_215 [ V_428 ] ;
if ( V_427 & V_432 )
V_7 = F_83 ( V_27 , V_231 , V_7 ) ;
if ( V_427 & V_433 )
V_7 = F_85 ( V_27 , V_231 , V_7 ) ;
if ( V_427 & V_434 )
V_7 = F_87 ( V_27 , V_231 , V_7 ) ;
return F_39 ( V_3 , V_170 , V_171 , V_231 , V_7 ) ;
}
void
F_90 ( struct V_26 * V_27 , enum V_435 V_436 ,
enum V_437 V_438 , enum V_439 V_440 ,
enum V_441 V_442 ,
struct V_45 * V_443 , T_1 V_444 )
{
#ifdef F_21
T_1 * V_401 , * V_398 , * V_399 , * V_400 ;
char V_445 [ V_446 ] ;
int V_7 = 0 ;
T_1 V_447 = 0 ;
T_1 * V_448 ;
T_1 V_5 ;
if ( V_218 . V_219 . V_213 != V_408 )
return;
V_401 = & V_218 . V_219 . V_215 [ V_402 ] ;
V_398 = & V_218 . V_219 . V_215 [ V_403 ] ;
V_399 = & V_218 . V_219 . V_215 [ V_404 ] ;
V_400 = & V_218 . V_219 . V_215 [ V_405 ] ;
if ( ! ( * V_398 & V_410 ) ||
( * V_399 == 0 ) ||
( * V_400 == 0 ) )
return;
if ( * V_401 != 0x9B )
return;
if ( ( V_438 == V_449 ) && ( V_440 == V_450 ) ) {
if ( * V_398 & V_451 ) {
V_447 |= V_451 ;
F_31 ( V_162 L_127
L_128 ,
V_442 , V_436 , V_444 ) ;
}
}
if ( ( V_438 == V_449 ) && ( V_440 == V_452 ) ) {
if ( * V_398 & V_453 ) {
V_447 |= V_453 ;
F_31 ( V_162 L_129
L_130 ,
V_442 , V_436 , V_444 ) ;
}
}
if ( ( V_438 == V_454 ) && ( V_440 == V_450 ) ) {
if ( * V_398 & V_455 ) {
V_447 |= V_455 ;
F_31 ( V_162 L_131
L_128 ,
V_442 , V_436 , V_444 ) ;
}
}
if ( ( V_438 == V_454 ) && ( V_440 == V_452 ) ) {
if ( * V_398 & V_456 ) {
V_447 |= V_456 ;
F_31 ( V_162 L_132
L_130 ,
V_442 , V_436 , V_444 ) ;
}
}
if ( V_447 ) {
V_448 = ( T_1 * ) V_443 -> V_74 ;
for ( V_5 = 0 ; V_5 < * V_400 ; V_5 ++ ) {
if ( ! ( V_5 % 8 ) ) {
if ( V_5 != 0 )
F_31 ( V_162 L_133 , V_445 ) ;
V_7 = 0 ;
V_7 += snprintf ( V_445 + V_7 ,
V_446 - V_7 ,
L_134 , V_5 ) ;
}
V_7 += snprintf ( V_445 + V_7 , V_446 - V_7 ,
L_56 , ( T_1 ) * V_448 ) ;
V_448 ++ ;
}
if ( ( V_5 - 1 ) % 8 )
F_31 ( V_162 L_133 , V_445 ) ;
( * V_399 ) -- ;
}
if ( * V_399 == 0 )
memset ( & V_218 , 0 , sizeof( V_218 ) ) ;
return;
#endif
}
void
F_91 ( struct V_26 * V_27 , V_92 * V_457 )
{
#ifdef F_21
T_1 * V_398 , * V_399 , * V_400 , * V_401 ;
char V_445 [ V_446 ] ;
int V_7 = 0 ;
T_1 * V_448 ;
T_7 * V_458 ;
T_1 V_5 , V_32 ;
if ( V_218 . V_219 . V_213 != V_407 )
return;
V_401 = & V_218 . V_219 . V_215 [ V_402 ] ;
V_398 = & V_218 . V_219 . V_215 [ V_403 ] ;
V_399 = & V_218 . V_219 . V_215 [ V_404 ] ;
V_400 = & V_218 . V_219 . V_215 [ V_405 ] ;
if ( ! ( * V_398 & V_409 ) ||
( * V_399 == 0 ) ||
( * V_400 == 0 ) )
return;
if ( ( * V_401 != V_459 ) &&
( * V_401 != V_457 -> V_460 ) )
return;
if ( * V_398 & V_461 ) {
F_31 ( V_162 L_135 ,
V_457 -> V_460 ) ;
V_448 = ( T_1 * ) V_457 ;
for ( V_5 = 0 ; V_5 < * V_400 ; V_5 ++ ) {
if ( ! ( V_5 % 8 ) ) {
if ( V_5 != 0 )
F_31 ( V_162 L_133 , V_445 ) ;
V_7 = 0 ;
memset ( V_445 , 0 , V_446 ) ;
V_7 += snprintf ( V_445 + V_7 ,
V_446 - V_7 ,
L_134 , V_5 ) ;
}
V_7 += snprintf ( V_445 + V_7 , V_446 - V_7 ,
L_56 ,
( ( T_1 ) * V_448 ) & 0xffffffff ) ;
V_448 ++ ;
}
if ( ( V_5 - 1 ) % 8 )
F_31 ( V_162 L_133 , V_445 ) ;
F_31 ( V_162 L_41 ) ;
}
if ( * V_398 & V_462 ) {
F_31 ( V_162 L_136 ,
V_457 -> V_460 ) ;
V_458 = ( T_7 * ) V_457 ;
for ( V_5 = 0 ; V_5 < * V_400 ; V_5 ++ ) {
if ( ! ( V_5 % 8 ) ) {
if ( V_5 != 0 )
F_31 ( V_162 L_133 , V_445 ) ;
V_7 = 0 ;
memset ( V_445 , 0 , V_446 ) ;
V_7 += snprintf ( V_445 + V_7 ,
V_446 - V_7 ,
L_134 , V_5 ) ;
}
for ( V_32 = 0 ; V_32 < 4 ; V_32 ++ ) {
V_7 += snprintf ( V_445 + V_7 ,
V_446 - V_7 ,
L_137 ,
( ( T_7 ) * V_458 ) & 0xff ) ;
V_458 ++ ;
}
V_7 += snprintf ( V_445 + V_7 ,
V_446 - V_7 , L_138 ) ;
}
if ( ( V_5 - 1 ) % 8 )
F_31 ( V_162 L_133 , V_445 ) ;
F_31 ( V_162 L_41 ) ;
}
( * V_399 ) -- ;
if ( * V_399 == 0 )
memset ( & V_218 , 0 , sizeof( V_218 ) ) ;
return;
#endif
}
inline void
F_92 ( struct V_1 * V_2 )
{
#ifdef F_21
struct V_26 * V_27 = V_2 -> V_27 ;
char V_115 [ 64 ] ;
T_1 V_463 , V_5 ;
if ( ! V_15 )
return;
if ( ! V_464 ) {
V_464 = F_93 ( L_139 , NULL ) ;
F_94 ( & V_465 , 0 ) ;
if ( ! V_464 ) {
F_95 ( V_2 , V_162 , V_198 ,
L_140 ) ;
goto V_466;
}
}
if ( ! V_21 )
V_21 = V_147 ;
snprintf ( V_115 , sizeof( V_115 ) , L_141 , V_27 -> V_422 ) ;
if ( ! V_27 -> V_467 ) {
V_27 -> V_467 =
F_93 ( V_115 , V_464 ) ;
if ( ! V_27 -> V_467 ) {
F_95 ( V_2 , V_162 , V_198 ,
L_142 ) ;
goto V_466;
}
F_96 ( & V_465 ) ;
F_94 ( & V_27 -> V_468 , 0 ) ;
snprintf ( V_115 , sizeof( V_115 ) , L_143 ) ;
V_27 -> V_469 =
F_97 ( V_115 , V_470 | V_471 | V_472 ,
V_27 -> V_467 ,
V_27 , & V_473 ) ;
if ( ! V_27 -> V_469 ) {
F_95 ( V_2 , V_162 , V_198 ,
L_144 ) ;
goto V_466;
}
if ( V_27 -> V_49 < V_474 ) {
snprintf ( V_115 , sizeof( V_115 ) , L_145 ) ;
V_27 -> V_475 =
F_97 ( V_115 ,
V_470 | V_471 | V_472 ,
V_27 -> V_467 ,
V_27 , & V_476 ) ;
if ( ! V_27 -> V_475 ) {
F_95 ( V_2 , V_162 , V_198 ,
L_146
L_147 ) ;
goto V_466;
}
} else
V_27 -> V_475 = NULL ;
if ( V_27 -> V_49 < V_474 ) {
snprintf ( V_115 , sizeof( V_115 ) , L_148 ) ;
V_27 -> V_477 =
F_97 ( V_115 ,
V_470 | V_471 | V_472 ,
V_27 -> V_467 ,
V_27 , & V_478 ) ;
if ( ! V_27 -> V_477 ) {
F_95 ( V_2 , V_162 , V_198 ,
L_149
L_150 ) ;
goto V_466;
}
} else
V_27 -> V_475 = NULL ;
snprintf ( V_115 , sizeof( V_115 ) , L_151 ) ;
V_27 -> V_479 =
F_97 ( V_115 , V_470 | V_471 | V_472 ,
V_27 -> V_467 ,
V_27 , & V_480 ) ;
if ( ! V_27 -> V_479 ) {
F_95 ( V_2 , V_162 , V_198 ,
L_152 ) ;
goto V_466;
}
snprintf ( V_115 , sizeof( V_115 ) , L_153 ) ;
V_27 -> V_481 =
F_97 ( V_115 , V_470 | V_471 | V_472 ,
V_27 -> V_467 ,
V_27 , & V_482 ) ;
if ( ! V_27 -> V_481 ) {
F_95 ( V_2 , V_162 , V_198 ,
L_154 ) ;
goto V_466;
}
snprintf ( V_115 , sizeof( V_115 ) , L_155 ) ;
V_27 -> V_195 =
F_97 ( V_115 , V_470 | V_471 | V_472 ,
V_27 -> V_467 ,
V_27 , & V_483 ) ;
if ( ! V_27 -> V_195 ) {
F_95 ( V_2 , V_162 , V_198 ,
L_156 ) ;
goto V_466;
}
V_27 -> V_196 = V_484 ;
snprintf ( V_115 , sizeof( V_115 ) , L_157 ) ;
V_27 -> V_190 =
F_97 ( V_115 , V_470 | V_471 | V_472 ,
V_27 -> V_467 ,
V_27 , & V_483 ) ;
if ( ! V_27 -> V_190 ) {
F_95 ( V_2 , V_162 , V_198 ,
L_158 ) ;
goto V_466;
}
snprintf ( V_115 , sizeof( V_115 ) , L_159 ) ;
V_27 -> V_192 =
F_97 ( V_115 , V_470 | V_471 | V_472 ,
V_27 -> V_467 ,
V_27 , & V_483 ) ;
if ( ! V_27 -> V_192 ) {
F_95 ( V_2 , V_162 , V_198 ,
L_160 ) ;
goto V_466;
}
snprintf ( V_115 , sizeof( V_115 ) , L_161 ) ;
V_27 -> V_178 =
F_97 ( V_115 , V_470 | V_471 | V_472 ,
V_27 -> V_467 ,
V_27 , & V_483 ) ;
if ( ! V_27 -> V_178 ) {
F_95 ( V_2 , V_162 , V_198 ,
L_162 ) ;
goto V_466;
}
snprintf ( V_115 , sizeof( V_115 ) , L_163 ) ;
V_27 -> V_180 =
F_97 ( V_115 , V_470 | V_471 | V_472 ,
V_27 -> V_467 ,
V_27 , & V_483 ) ;
if ( ! V_27 -> V_180 ) {
F_95 ( V_2 , V_162 , V_198 ,
L_164 ) ;
goto V_466;
}
snprintf ( V_115 , sizeof( V_115 ) , L_165 ) ;
V_27 -> V_182 =
F_97 ( V_115 , V_470 | V_471 | V_472 ,
V_27 -> V_467 ,
V_27 , & V_483 ) ;
if ( ! V_27 -> V_182 ) {
F_95 ( V_2 , V_162 , V_198 ,
L_166 ) ;
goto V_466;
}
snprintf ( V_115 , sizeof( V_115 ) , L_167 ) ;
V_27 -> V_184 =
F_97 ( V_115 , V_470 | V_471 | V_472 ,
V_27 -> V_467 ,
V_27 , & V_483 ) ;
if ( ! V_27 -> V_184 ) {
F_95 ( V_2 , V_162 , V_198 ,
L_168 ) ;
goto V_466;
}
snprintf ( V_115 , sizeof( V_115 ) , L_169 ) ;
V_27 -> V_186 =
F_97 ( V_115 , V_470 | V_471 | V_472 ,
V_27 -> V_467 ,
V_27 , & V_483 ) ;
if ( ! V_27 -> V_186 ) {
F_95 ( V_2 , V_162 , V_198 ,
L_170 ) ;
goto V_466;
}
snprintf ( V_115 , sizeof( V_115 ) , L_171 ) ;
V_27 -> V_188 =
F_97 ( V_115 , V_470 | V_471 | V_472 ,
V_27 -> V_467 ,
V_27 , & V_483 ) ;
if ( ! V_27 -> V_188 ) {
F_95 ( V_2 , V_162 , V_198 ,
L_172 ) ;
goto V_466;
}
if ( V_29 ) {
V_463 = V_29 - 1 ;
if ( V_463 & V_29 ) {
V_463 = V_29 ;
V_5 = 0 ;
while ( V_463 > 1 ) {
V_463 = V_463 >> 1 ;
V_5 ++ ;
}
V_29 = ( 1 << V_5 ) ;
F_31 ( V_162
L_173
L_174 , V_17 ) ;
}
}
snprintf ( V_115 , sizeof( V_115 ) , L_175 ) ;
V_27 -> V_485 =
F_97 ( V_115 , V_470 | V_471 | V_472 ,
V_27 -> V_467 ,
V_27 , & V_486 ) ;
if ( ! V_27 -> V_485 ) {
F_95 ( V_2 , V_162 , V_198 ,
L_176
L_177 ) ;
goto V_466;
}
if ( ! V_27 -> V_30 ) {
V_27 -> V_30 = F_2 (
( sizeof( struct V_10 ) *
V_29 ) ,
V_14 ) ;
if ( ! V_27 -> V_30 ) {
F_95 ( V_2 , V_162 , V_198 ,
L_178
L_179 ) ;
goto V_466;
}
F_94 ( & V_27 -> V_28 , 0 ) ;
memset ( V_27 -> V_30 , 0 ,
( sizeof( struct V_10 ) *
V_29 ) ) ;
}
}
snprintf ( V_115 , sizeof( V_115 ) , L_180 , V_2 -> V_487 ) ;
if ( ! V_2 -> V_488 ) {
V_2 -> V_488 =
F_93 ( V_115 , V_27 -> V_467 ) ;
if ( ! V_2 -> V_488 ) {
F_95 ( V_2 , V_162 , V_198 ,
L_181 ) ;
goto V_466;
}
F_96 ( & V_27 -> V_468 ) ;
}
if ( V_17 ) {
V_463 = V_17 - 1 ;
if ( V_463 & V_17 ) {
V_463 = V_17 ;
V_5 = 0 ;
while ( V_463 > 1 ) {
V_463 = V_463 >> 1 ;
V_5 ++ ;
}
V_17 = ( 1 << V_5 ) ;
F_31 ( V_162
L_182 ,
V_17 ) ;
}
}
V_2 -> V_18 = F_98 (
( sizeof( struct V_10 ) * V_17 ) ,
V_14 ) ;
if ( ! V_2 -> V_18 ) {
F_95 ( V_2 , V_162 , V_198 ,
L_183
L_184 ) ;
goto V_466;
}
F_94 ( & V_2 -> V_16 , 0 ) ;
snprintf ( V_115 , sizeof( V_115 ) , L_185 ) ;
V_2 -> V_489 =
F_97 ( V_115 , V_470 | V_471 | V_472 ,
V_2 -> V_488 ,
V_2 , & V_490 ) ;
if ( ! V_2 -> V_489 ) {
F_95 ( V_2 , V_162 , V_198 ,
L_186
L_187 ) ;
goto V_466;
}
snprintf ( V_115 , sizeof( V_115 ) , L_188 ) ;
V_2 -> V_491 =
F_97 ( V_115 , V_470 | V_471 | V_472 ,
V_2 -> V_488 ,
V_2 , & V_492 ) ;
if ( ! V_2 -> V_491 ) {
F_95 ( V_2 , V_162 , V_198 ,
L_189 ) ;
goto V_466;
}
if ( V_27 -> V_49 < V_474 )
goto V_466;
snprintf ( V_115 , sizeof( V_115 ) , L_190 ) ;
if ( ! V_27 -> V_493 ) {
V_27 -> V_493 =
F_93 ( V_115 , V_27 -> V_467 ) ;
if ( ! V_27 -> V_493 ) {
F_95 ( V_2 , V_162 , V_198 ,
L_191 ) ;
goto V_466;
}
memset ( & V_218 , 0 , sizeof( V_218 ) ) ;
}
snprintf ( V_115 , sizeof( V_115 ) , L_192 ) ;
if ( ! V_27 -> V_494 ) {
V_27 -> V_494 =
F_97 ( V_115 , V_470 | V_471 | V_472 ,
V_27 -> V_493 , V_27 , & V_495 ) ;
if ( ! V_27 -> V_494 ) {
F_95 ( V_2 , V_162 , V_198 ,
L_193 ) ;
goto V_466;
}
V_218 . V_227 . V_248 = 0 ;
}
snprintf ( V_115 , sizeof( V_115 ) , L_194 ) ;
if ( ! V_27 -> V_496 ) {
V_27 -> V_496 =
F_97 ( V_115 , V_470 | V_471 | V_472 ,
V_27 -> V_493 , V_27 , & V_497 ) ;
if ( ! V_27 -> V_496 ) {
F_95 ( V_2 , V_162 , V_198 ,
L_195 ) ;
goto V_466;
}
V_218 . V_227 . V_248 = 0 ;
}
snprintf ( V_115 , sizeof( V_115 ) , L_196 ) ;
if ( ! V_27 -> V_498 ) {
V_27 -> V_498 =
F_97 ( V_115 , V_470 | V_471 ,
V_27 -> V_493 , V_27 , & V_499 ) ;
if ( ! V_27 -> V_498 ) {
F_95 ( V_2 , V_162 , V_198 ,
L_197 ) ;
goto V_466;
}
}
snprintf ( V_115 , sizeof( V_115 ) , L_198 ) ;
if ( ! V_27 -> V_500 ) {
V_27 -> V_500 =
F_97 ( V_115 , V_470 | V_471 | V_472 ,
V_27 -> V_493 , V_27 , & V_501 ) ;
if ( ! V_27 -> V_500 ) {
F_95 ( V_2 , V_162 , V_198 ,
L_199 ) ;
goto V_466;
}
}
snprintf ( V_115 , sizeof( V_115 ) , L_200 ) ;
if ( ! V_27 -> V_502 ) {
V_27 -> V_502 =
F_97 ( V_115 , V_470 | V_471 | V_472 ,
V_27 -> V_493 , V_27 , & V_503 ) ;
if ( ! V_27 -> V_502 ) {
F_95 ( V_2 , V_162 , V_198 ,
L_201 ) ;
goto V_466;
}
}
snprintf ( V_115 , sizeof( V_115 ) , L_202 ) ;
if ( ! V_27 -> V_504 ) {
V_27 -> V_504 =
F_97 ( V_115 , V_470 | V_471 | V_472 ,
V_27 -> V_493 , V_27 , & V_505 ) ;
if ( ! V_27 -> V_504 ) {
F_95 ( V_2 , V_162 , V_198 ,
L_203 ) ;
goto V_466;
}
}
snprintf ( V_115 , sizeof( V_115 ) , L_204 ) ;
if ( ! V_27 -> V_506 ) {
V_27 -> V_506 =
F_97 ( V_115 , V_470 | V_471 | V_472 ,
V_27 -> V_493 , V_27 , & V_507 ) ;
if ( ! V_27 -> V_506 ) {
F_95 ( V_2 , V_162 , V_198 ,
L_205 ) ;
goto V_466;
}
}
if ( V_27 -> V_267 . V_508 ) {
snprintf ( V_115 , sizeof( V_115 ) , L_206 ) ;
if ( ! V_27 -> V_509 ) {
V_27 -> V_509 =
F_97 ( V_115 ,
V_470 | V_471 | V_472 ,
V_27 -> V_493 , V_27 ,
& V_510 ) ;
if ( ! V_27 -> V_509 ) {
F_95 ( V_2 , V_162 , V_198 ,
L_207
L_208 ) ;
goto V_466;
}
}
}
V_466:
return;
#endif
}
inline void
F_99 ( struct V_1 * V_2 )
{
#ifdef F_21
struct V_26 * V_27 = V_2 -> V_27 ;
if ( V_2 -> V_18 ) {
F_5 ( V_2 -> V_18 ) ;
V_2 -> V_18 = NULL ;
}
if ( V_2 -> V_489 ) {
F_100 ( V_2 -> V_489 ) ;
V_2 -> V_489 = NULL ;
}
if ( V_2 -> V_491 ) {
F_100 ( V_2 -> V_491 ) ;
V_2 -> V_491 = NULL ;
}
if ( V_2 -> V_488 ) {
F_100 ( V_2 -> V_488 ) ;
V_2 -> V_488 = NULL ;
F_101 ( & V_27 -> V_468 ) ;
}
if ( F_3 ( & V_27 -> V_468 ) == 0 ) {
if ( V_27 -> V_469 ) {
F_100 ( V_27 -> V_469 ) ;
V_27 -> V_469 = NULL ;
}
if ( V_27 -> V_475 ) {
F_100 ( V_27 -> V_475 ) ;
V_27 -> V_475 = NULL ;
}
if ( V_27 -> V_477 ) {
F_100 ( V_27 -> V_477 ) ;
V_27 -> V_477 = NULL ;
}
if ( V_27 -> V_479 ) {
F_100 ( V_27 -> V_479 ) ;
V_27 -> V_479 = NULL ;
}
if ( V_27 -> V_481 ) {
F_100 ( V_27 -> V_481 ) ;
V_27 -> V_481 = NULL ;
}
if ( V_27 -> V_195 ) {
F_100 ( V_27 -> V_195 ) ;
V_27 -> V_195 = NULL ;
}
if ( V_27 -> V_190 ) {
F_100 ( V_27 -> V_190 ) ;
V_27 -> V_190 = NULL ;
}
if ( V_27 -> V_192 ) {
F_100 ( V_27 -> V_192 ) ;
V_27 -> V_192 = NULL ;
}
if ( V_27 -> V_178 ) {
F_100 ( V_27 -> V_178 ) ;
V_27 -> V_178 = NULL ;
}
if ( V_27 -> V_180 ) {
F_100 ( V_27 -> V_180 ) ;
V_27 -> V_180 = NULL ;
}
if ( V_27 -> V_182 ) {
F_100 ( V_27 -> V_182 ) ;
V_27 -> V_182 = NULL ;
}
if ( V_27 -> V_184 ) {
F_100 ( V_27 -> V_184 ) ;
V_27 -> V_184 = NULL ;
}
if ( V_27 -> V_186 ) {
F_100 ( V_27 -> V_186 ) ;
V_27 -> V_186 = NULL ;
}
if ( V_27 -> V_188 ) {
F_100 ( V_27 -> V_188 ) ;
V_27 -> V_188 = NULL ;
}
if ( V_27 -> V_30 ) {
F_5 ( V_27 -> V_30 ) ;
V_27 -> V_30 = NULL ;
}
if ( V_27 -> V_485 ) {
F_100 ( V_27 -> V_485 ) ;
V_27 -> V_485 = NULL ;
}
if ( V_27 -> V_49 == V_474 ) {
if ( V_27 -> V_509 ) {
F_100 ( V_27 -> V_509 ) ;
V_27 -> V_509 = NULL ;
}
if ( V_27 -> V_506 ) {
F_100 ( V_27 -> V_506 ) ;
V_27 -> V_506 = NULL ;
}
if ( V_27 -> V_504 ) {
F_100 ( V_27 -> V_504 ) ;
V_27 -> V_504 = NULL ;
}
if ( V_27 -> V_502 ) {
F_100 ( V_27 -> V_502 ) ;
V_27 -> V_502 = NULL ;
}
if ( V_27 -> V_500 ) {
F_100 ( V_27 -> V_500 ) ;
V_27 -> V_500 = NULL ;
}
if ( V_27 -> V_498 ) {
F_100 ( V_27 -> V_498 ) ;
V_27 -> V_498 = NULL ;
}
if ( V_27 -> V_496 ) {
F_100 ( V_27 -> V_496 ) ;
V_27 -> V_496 = NULL ;
}
if ( V_27 -> V_494 ) {
F_100 ( V_27 -> V_494 ) ;
V_27 -> V_494 = NULL ;
}
if ( V_27 -> V_493 ) {
F_100 ( V_27 -> V_493 ) ;
V_27 -> V_493 = NULL ;
}
}
if ( V_27 -> V_467 ) {
F_100 ( V_27 -> V_467 ) ;
V_27 -> V_467 = NULL ;
F_101 ( & V_465 ) ;
}
if ( F_3 ( & V_465 ) == 0 ) {
F_100 ( V_464 ) ;
V_464 = NULL ;
}
}
#endif
return;
}
void
F_102 ( struct V_26 * V_27 )
{
int V_511 ;
F_103 ( V_27 ) ;
F_104 ( V_27 ) ;
for ( V_511 = 0 ; V_511 < V_27 -> V_297 ; V_511 ++ )
F_105 ( V_27 , V_511 ) ;
F_106 ( V_27 ) ;
F_107 ( V_27 ) ;
F_108 ( V_27 ) ;
F_109 ( V_27 ) ;
for ( V_511 = 0 ; V_511 < V_27 -> V_297 ; V_511 ++ )
F_110 ( V_27 , V_511 ) ;
for ( V_511 = 0 ; V_511 < V_27 -> V_297 ; V_511 ++ )
F_111 ( V_27 , V_511 ) ;
}
