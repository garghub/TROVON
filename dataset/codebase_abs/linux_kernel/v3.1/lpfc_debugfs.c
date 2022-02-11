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
V_5 , V_85 -> V_97 , V_90 -> V_98 ,
V_90 -> V_99 , V_90 -> V_100 ,
V_90 -> V_101 , V_85 -> V_102 , V_90 -> V_103 ) ;
}
if ( V_27 -> V_49 <= V_104 ) {
V_80 = F_17 ( V_27 -> V_105 ) ;
V_81 = F_17 ( V_27 -> V_106 ) ;
V_82 = F_17 ( V_27 -> V_107 ) ;
V_83 = F_17 ( V_27 -> V_108 ) ;
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
struct V_109 * V_110 = F_19 ( V_2 ) ;
struct V_111 * V_112 ;
unsigned char * V_113 , * V_114 ;
V_31 = ( V_115 / V_116 ) ;
F_8 ( V_110 -> V_117 ) ;
F_10 (ndlp, &vport->fc_nodes, nlp_listp) {
if ( ! V_31 ) {
V_7 += snprintf ( V_3 + V_7 , V_4 - V_7 ,
L_17 ) ;
break;
}
V_31 -- ;
switch ( V_112 -> V_118 ) {
case V_119 :
V_113 = L_18 ;
break;
case V_120 :
V_113 = L_19 ;
break;
case V_121 :
V_113 = L_20 ;
break;
case V_122 :
V_113 = L_21 ;
break;
case V_123 :
V_113 = L_22 ;
break;
case V_124 :
V_113 = L_23 ;
break;
case V_125 :
V_113 = L_24 ;
break;
case V_126 :
V_113 = L_25 ;
break;
default:
V_113 = L_26 ;
}
V_7 += snprintf ( V_3 + V_7 , V_4 - V_7 , L_27 ,
V_113 , V_112 -> V_127 ) ;
V_114 = ( unsigned char * ) & V_112 -> V_128 ;
V_7 += snprintf ( V_3 + V_7 , V_4 - V_7 ,
L_28 ,
* V_114 , * ( V_114 + 1 ) , * ( V_114 + 2 ) , * ( V_114 + 3 ) ,
* ( V_114 + 4 ) , * ( V_114 + 5 ) , * ( V_114 + 6 ) , * ( V_114 + 7 ) ) ;
V_114 = ( unsigned char * ) & V_112 -> V_129 ;
V_7 += snprintf ( V_3 + V_7 , V_4 - V_7 ,
L_29 ,
* V_114 , * ( V_114 + 1 ) , * ( V_114 + 2 ) , * ( V_114 + 3 ) ,
* ( V_114 + 4 ) , * ( V_114 + 5 ) , * ( V_114 + 6 ) , * ( V_114 + 7 ) ) ;
V_7 += snprintf ( V_3 + V_7 , V_4 - V_7 , L_30 ,
V_112 -> V_130 , V_112 -> V_131 ) ;
if ( ! V_112 -> V_132 )
V_7 += snprintf ( V_3 + V_7 , V_4 - V_7 , L_31 ) ;
if ( V_112 -> V_132 & V_133 )
V_7 += snprintf ( V_3 + V_7 , V_4 - V_7 , L_32 ) ;
if ( V_112 -> V_132 & V_134 )
V_7 += snprintf ( V_3 + V_7 , V_4 - V_7 , L_33 ) ;
if ( V_112 -> V_132 & V_135 )
V_7 += snprintf ( V_3 + V_7 , V_4 - V_7 , L_34 ,
V_112 -> V_136 ) ;
if ( V_112 -> V_132 & V_137 )
V_7 += snprintf ( V_3 + V_7 , V_4 - V_7 , L_35 ) ;
V_7 += snprintf ( V_3 + V_7 , V_4 - V_7 , L_36 ,
V_112 -> V_138 ) ;
V_7 += snprintf ( V_3 + V_7 , V_4 - V_7 , L_37 ,
F_3 ( & V_112 -> V_139 . V_140 ) ) ;
V_7 += snprintf ( V_3 + V_7 , V_4 - V_7 , L_38 ) ;
}
F_13 ( V_110 -> V_117 ) ;
return V_7 ;
}
inline void
F_20 ( struct V_1 * V_2 , int V_141 , char * V_19 ,
T_1 V_23 , T_1 V_24 , T_1 V_25 )
{
#ifdef F_21
struct V_10 * V_11 ;
int V_6 ;
if ( ! ( V_142 & V_141 ) )
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
V_11 -> V_22 = F_22 ( & V_143 ) ;
V_11 -> V_20 = V_144 ;
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
V_11 -> V_22 = F_22 ( & V_143 ) ;
V_11 -> V_20 = V_144 ;
#endif
return;
}
static int
F_24 ( struct V_145 * V_145 , struct V_146 * V_146 )
{
struct V_1 * V_2 = V_145 -> V_147 ;
struct V_148 * V_149 ;
int V_4 ;
int V_150 = - V_151 ;
if ( ! V_17 ) {
V_150 = - V_152 ;
goto V_153;
}
V_149 = F_2 ( sizeof( * V_149 ) , V_14 ) ;
if ( ! V_149 )
goto V_153;
V_4 = ( V_17 * V_13 ) ;
V_4 = F_25 ( V_4 ) ;
V_149 -> V_12 = F_2 ( V_4 , V_14 ) ;
if ( ! V_149 -> V_12 ) {
F_5 ( V_149 ) ;
goto V_153;
}
V_149 -> V_7 = F_1 ( V_2 , V_149 -> V_12 , V_4 ) ;
V_146 -> V_154 = V_149 ;
V_150 = 0 ;
V_153:
return V_150 ;
}
static int
F_26 ( struct V_145 * V_145 , struct V_146 * V_146 )
{
struct V_26 * V_27 = V_145 -> V_147 ;
struct V_148 * V_149 ;
int V_4 ;
int V_150 = - V_151 ;
if ( ! V_29 ) {
V_150 = - V_152 ;
goto V_153;
}
V_149 = F_2 ( sizeof( * V_149 ) , V_14 ) ;
if ( ! V_149 )
goto V_153;
V_4 = ( V_29 * V_13 ) ;
V_4 = F_25 ( V_4 ) ;
V_149 -> V_12 = F_2 ( V_4 , V_14 ) ;
if ( ! V_149 -> V_12 ) {
F_5 ( V_149 ) ;
goto V_153;
}
V_149 -> V_7 = F_6 ( V_27 , V_149 -> V_12 , V_4 ) ;
V_146 -> V_154 = V_149 ;
V_150 = 0 ;
V_153:
return V_150 ;
}
static int
F_27 ( struct V_145 * V_145 , struct V_146 * V_146 )
{
struct V_26 * V_27 = V_145 -> V_147 ;
struct V_148 * V_149 ;
int V_150 = - V_151 ;
V_149 = F_2 ( sizeof( * V_149 ) , V_14 ) ;
if ( ! V_149 )
goto V_153;
V_149 -> V_12 = F_2 ( V_50 , V_14 ) ;
if ( ! V_149 -> V_12 ) {
F_5 ( V_149 ) ;
goto V_153;
}
V_149 -> V_7 = F_7 ( V_27 , V_149 -> V_12 ,
V_50 ) ;
V_146 -> V_154 = V_149 ;
V_150 = 0 ;
V_153:
return V_150 ;
}
static int
F_28 ( struct V_145 * V_145 , struct V_146 * V_146 )
{
struct V_26 * V_27 = V_145 -> V_147 ;
struct V_148 * V_149 ;
int V_150 = - V_151 ;
V_149 = F_2 ( sizeof( * V_149 ) , V_14 ) ;
if ( ! V_149 )
goto V_153;
V_149 -> V_12 = F_2 ( V_155 , V_14 ) ;
if ( ! V_149 -> V_12 ) {
F_5 ( V_149 ) ;
goto V_153;
}
V_149 -> V_7 = F_14 ( V_27 , V_149 -> V_12 ,
V_155 ) ;
V_146 -> V_154 = V_149 ;
V_150 = 0 ;
V_153:
return V_150 ;
}
static int
F_29 ( struct V_145 * V_145 , struct V_146 * V_146 )
{
struct V_26 * V_27 = V_145 -> V_147 ;
struct V_148 * V_149 ;
int V_150 = - V_151 ;
V_149 = F_2 ( sizeof( * V_149 ) , V_14 ) ;
if ( ! V_149 )
goto V_153;
V_149 -> V_12 = F_2 ( V_156 , V_14 ) ;
if ( ! V_149 -> V_12 ) {
F_5 ( V_149 ) ;
goto V_153;
}
V_149 -> V_7 = F_16 ( V_27 , V_149 -> V_12 ,
V_156 ) ;
V_146 -> V_154 = V_149 ;
V_150 = 0 ;
V_153:
return V_150 ;
}
static int
F_30 ( struct V_145 * V_145 , struct V_146 * V_146 )
{
struct V_148 * V_149 ;
int V_150 = - V_151 ;
if ( ! V_157 )
return - V_158 ;
V_149 = F_2 ( sizeof( * V_149 ) , V_14 ) ;
if ( ! V_149 )
goto V_153;
F_31 ( V_159 L_39 ,
V_160 , V_157 ) ;
V_149 -> V_12 = V_157 ;
if ( ! V_149 -> V_12 ) {
F_5 ( V_149 ) ;
goto V_153;
}
V_149 -> V_7 = ( 1 << V_161 ) << V_162 ;
V_146 -> V_154 = V_149 ;
V_150 = 0 ;
V_153:
return V_150 ;
}
static int
F_32 ( struct V_145 * V_145 , struct V_146 * V_146 )
{
struct V_148 * V_149 ;
int V_150 = - V_151 ;
if ( ! V_163 )
return - V_158 ;
V_149 = F_2 ( sizeof( * V_149 ) , V_14 ) ;
if ( ! V_149 )
goto V_153;
F_31 ( V_159 L_40 ,
V_160 , V_163 , V_146 -> V_164 -> V_165 . V_114 ) ;
V_149 -> V_12 = V_163 ;
if ( ! V_149 -> V_12 ) {
F_5 ( V_149 ) ;
goto V_153;
}
V_149 -> V_7 = ( 1 << V_166 ) << V_162 ;
V_146 -> V_154 = V_149 ;
V_150 = 0 ;
V_153:
return V_150 ;
}
static T_2
F_33 ( struct V_146 * V_146 , const char T_3 * V_3 ,
T_4 V_167 , T_5 * V_168 )
{
F_34 ( & V_169 ) ;
memset ( ( void * ) V_157 , 0 ,
( ( 1 << V_162 ) << V_161 ) ) ;
memset ( ( void * ) V_163 , 0 ,
( ( 1 << V_162 ) << V_166 ) ) ;
V_170 = 0 ;
F_35 ( & V_169 ) ;
return V_167 ;
}
static int
F_36 ( struct V_145 * V_145 , struct V_146 * V_146 )
{
struct V_1 * V_2 = V_145 -> V_147 ;
struct V_148 * V_149 ;
int V_150 = - V_151 ;
V_149 = F_2 ( sizeof( * V_149 ) , V_14 ) ;
if ( ! V_149 )
goto V_153;
V_149 -> V_12 = F_2 ( V_115 , V_14 ) ;
if ( ! V_149 -> V_12 ) {
F_5 ( V_149 ) ;
goto V_153;
}
V_149 -> V_7 = F_18 ( V_2 , V_149 -> V_12 ,
V_115 ) ;
V_146 -> V_154 = V_149 ;
V_150 = 0 ;
V_153:
return V_150 ;
}
static T_5
F_37 ( struct V_146 * V_146 , T_5 V_76 , int V_171 )
{
struct V_148 * V_149 ;
T_5 V_172 = - 1 ;
V_149 = V_146 -> V_154 ;
switch ( V_171 ) {
case 0 :
V_172 = V_76 ;
break;
case 1 :
V_172 = V_146 -> V_173 + V_76 ;
break;
case 2 :
V_172 = V_149 -> V_7 - V_76 ;
}
return ( V_172 < 0 || V_172 > V_149 -> V_7 ) ? - V_174 : ( V_146 -> V_173 = V_172 ) ;
}
static T_2
F_38 ( struct V_146 * V_146 , char T_3 * V_3 ,
T_4 V_167 , T_5 * V_168 )
{
struct V_148 * V_149 = V_146 -> V_154 ;
return F_39 ( V_3 , V_167 , V_168 , V_149 -> V_12 ,
V_149 -> V_7 ) ;
}
static int
F_40 ( struct V_145 * V_145 , struct V_146 * V_146 )
{
struct V_148 * V_149 = V_146 -> V_154 ;
F_5 ( V_149 -> V_12 ) ;
F_5 ( V_149 ) ;
return 0 ;
}
static int
F_41 ( struct V_145 * V_145 , struct V_146 * V_146 )
{
struct V_148 * V_149 = V_146 -> V_154 ;
V_149 -> V_12 = NULL ;
F_5 ( V_149 ) ;
return 0 ;
}
static int F_42 ( const char T_3 * V_3 , T_4 V_167 ,
struct V_175 * V_176 )
{
char V_177 [ 64 ] ;
char * V_178 , * V_179 ;
int V_5 ;
T_4 V_180 ;
if ( ! F_43 ( V_181 , V_3 , V_167 ) )
return - V_182 ;
memset ( V_177 , 0 , sizeof( V_177 ) ) ;
memset ( V_176 , 0 , sizeof( * V_176 ) ) ;
V_180 = F_44 ( V_167 , ( sizeof( V_177 ) - 1 ) ) ;
if ( F_45 ( V_177 , V_3 , V_180 ) )
return - V_182 ;
V_178 = & V_177 [ 0 ] ;
V_179 = F_46 ( & V_178 , L_41 ) ;
if ( ! V_179 )
return - V_174 ;
V_176 -> V_183 = F_47 ( V_179 , NULL , 0 ) ;
if ( V_176 -> V_183 == 0 )
return - V_174 ;
for ( V_5 = 0 ; V_5 < V_184 ; V_5 ++ ) {
V_179 = F_46 ( & V_178 , L_41 ) ;
if ( ! V_179 )
return V_5 ;
V_176 -> V_185 [ V_5 ] = F_47 ( V_179 , NULL , 0 ) ;
}
return V_5 ;
}
static int
F_48 ( struct V_145 * V_145 , struct V_146 * V_146 )
{
struct V_148 * V_149 ;
V_149 = F_2 ( sizeof( * V_149 ) , V_14 ) ;
if ( ! V_149 )
return - V_151 ;
V_149 -> V_147 = V_145 -> V_147 ;
V_149 -> V_12 = NULL ;
V_146 -> V_154 = V_149 ;
return 0 ;
}
static int
F_49 ( struct V_145 * V_145 , struct V_146 * V_146 )
{
struct V_148 * V_149 = V_146 -> V_154 ;
F_5 ( V_149 -> V_12 ) ;
F_5 ( V_149 ) ;
return 0 ;
}
static int
F_50 ( struct V_145 * V_145 , struct V_146 * V_146 )
{
struct V_148 * V_149 = V_146 -> V_154 ;
if ( V_149 -> V_186 == V_187 ) {
switch ( V_188 . V_189 . V_183 ) {
case V_190 :
case V_191 :
case V_192 :
case V_193 :
case V_194 :
case V_195 :
memset ( & V_188 , 0 , sizeof( V_188 ) ) ;
break;
default:
break;
}
}
F_5 ( V_149 -> V_12 ) ;
F_5 ( V_149 ) ;
return 0 ;
}
static T_2
F_51 ( struct V_146 * V_146 , char T_3 * V_3 , T_4 V_167 ,
T_5 * V_168 )
{
struct V_148 * V_149 = V_146 -> V_154 ;
struct V_26 * V_27 = (struct V_26 * ) V_149 -> V_147 ;
int V_196 , V_197 , V_7 = 0 , V_6 = V_198 ;
int V_199 , V_200 ;
char * V_201 ;
struct V_202 * V_203 ;
T_1 V_204 ;
T_6 V_205 ;
T_7 V_206 ;
V_203 = V_27 -> V_207 ;
if ( ! V_203 )
return 0 ;
V_149 -> V_186 = V_208 ;
if ( ! V_149 -> V_12 )
V_149 -> V_12 = F_2 ( V_209 , V_14 ) ;
if ( ! V_149 -> V_12 )
return 0 ;
V_201 = V_149 -> V_12 ;
if ( * V_168 )
return 0 ;
if ( V_188 . V_189 . V_183 == V_210 ) {
V_199 = V_188 . V_189 . V_185 [ V_211 ] ;
V_200 = V_188 . V_189 . V_185 [ V_212 ] ;
} else
return 0 ;
switch ( V_200 ) {
case V_213 :
F_52 ( V_203 , V_199 , & V_206 ) ;
V_7 += snprintf ( V_201 + V_7 , V_209 - V_7 ,
L_42 , V_199 , V_206 ) ;
break;
case V_214 :
F_53 ( V_203 , V_199 , & V_205 ) ;
V_7 += snprintf ( V_201 + V_7 , V_209 - V_7 ,
L_43 , V_199 , V_205 ) ;
break;
case V_215 :
F_54 ( V_203 , V_199 , & V_204 ) ;
V_7 += snprintf ( V_201 + V_7 , V_209 - V_7 ,
L_44 , V_199 , V_204 ) ;
break;
case V_216 :
goto V_217;
break;
default:
V_7 = 0 ;
break;
}
return F_39 ( V_3 , V_167 , V_168 , V_201 , V_7 ) ;
V_217:
V_196 = V_188 . V_197 . V_218 ;
V_197 = V_196 ;
V_7 += snprintf ( V_201 + V_7 , V_209 - V_7 ,
L_45 , V_196 ) ;
while ( V_6 > 0 ) {
F_54 ( V_203 , V_197 , & V_204 ) ;
V_7 += snprintf ( V_201 + V_7 , V_209 - V_7 ,
L_46 , V_204 ) ;
V_197 += sizeof( T_1 ) ;
if ( V_197 >= V_209 ) {
V_7 += snprintf ( V_201 + V_7 ,
V_209 - V_7 , L_38 ) ;
break;
}
V_6 -= sizeof( T_1 ) ;
if ( ! V_6 )
V_7 += snprintf ( V_201 + V_7 , V_209 - V_7 ,
L_38 ) ;
else if ( ! ( V_6 % ( 8 * sizeof( T_1 ) ) ) ) {
V_196 += ( 8 * sizeof( T_1 ) ) ;
V_7 += snprintf ( V_201 + V_7 , V_209 - V_7 ,
L_47 , V_196 ) ;
}
}
if ( V_6 == 0 ) {
V_188 . V_197 . V_218 += V_198 ;
if ( V_188 . V_197 . V_218 >= V_209 )
V_188 . V_197 . V_218 = 0 ;
} else
V_188 . V_197 . V_218 = 0 ;
return F_39 ( V_3 , V_167 , V_168 , V_201 , V_7 ) ;
}
static T_2
F_55 ( struct V_146 * V_146 , const char T_3 * V_3 ,
T_4 V_167 , T_5 * V_168 )
{
struct V_148 * V_149 = V_146 -> V_154 ;
struct V_26 * V_27 = (struct V_26 * ) V_149 -> V_147 ;
T_1 V_199 , V_219 , V_200 ;
T_1 V_204 ;
T_6 V_205 ;
T_7 V_206 ;
struct V_202 * V_203 ;
int V_150 ;
V_203 = V_27 -> V_207 ;
if ( ! V_203 )
return - V_182 ;
V_149 -> V_186 = V_187 ;
V_150 = F_42 ( V_3 , V_167 , & V_188 . V_189 ) ;
if ( V_150 < 0 )
return V_150 ;
if ( V_188 . V_189 . V_183 == V_210 ) {
if ( V_150 != V_220 )
goto V_221;
V_199 = V_188 . V_189 . V_185 [ V_211 ] ;
V_200 = V_188 . V_189 . V_185 [ V_212 ] ;
if ( V_200 == V_216 ) {
if ( V_199 % sizeof( T_1 ) )
goto V_221;
V_188 . V_197 . V_218 = V_199 ;
} else if ( ( V_200 != sizeof( T_7 ) ) &&
( V_200 != sizeof( T_6 ) ) &&
( V_200 != sizeof( T_1 ) ) )
goto V_221;
if ( V_200 == sizeof( T_7 ) ) {
if ( V_199 > V_209 - sizeof( T_7 ) )
goto V_221;
if ( V_199 % sizeof( T_7 ) )
goto V_221;
}
if ( V_200 == sizeof( T_6 ) ) {
if ( V_199 > V_209 - sizeof( T_6 ) )
goto V_221;
if ( V_199 % sizeof( T_6 ) )
goto V_221;
}
if ( V_200 == sizeof( T_1 ) ) {
if ( V_199 > V_209 - sizeof( T_1 ) )
goto V_221;
if ( V_199 % sizeof( T_1 ) )
goto V_221;
}
} else if ( V_188 . V_189 . V_183 == V_190 ||
V_188 . V_189 . V_183 == V_191 ||
V_188 . V_189 . V_183 == V_192 ) {
if ( V_150 != V_222 )
goto V_221;
V_199 = V_188 . V_189 . V_185 [ V_211 ] ;
V_200 = V_188 . V_189 . V_185 [ V_212 ] ;
V_219 = V_188 . V_189 . V_185 [ V_223 ] ;
if ( ( V_200 != sizeof( T_7 ) ) &&
( V_200 != sizeof( T_6 ) ) &&
( V_200 != sizeof( T_1 ) ) )
goto V_221;
if ( V_200 == sizeof( T_7 ) ) {
if ( V_199 > V_209 - sizeof( T_7 ) )
goto V_221;
if ( V_199 % sizeof( T_7 ) )
goto V_221;
if ( V_188 . V_189 . V_183 == V_190 )
F_56 ( V_203 , V_199 ,
( T_7 ) V_219 ) ;
if ( V_188 . V_189 . V_183 == V_191 ) {
V_150 = F_52 ( V_203 , V_199 , & V_206 ) ;
if ( ! V_150 ) {
V_206 |= ( T_7 ) V_219 ;
F_56 ( V_203 , V_199 ,
V_206 ) ;
}
}
if ( V_188 . V_189 . V_183 == V_192 ) {
V_150 = F_52 ( V_203 , V_199 , & V_206 ) ;
if ( ! V_150 ) {
V_206 &= ( T_7 ) ( ~ V_219 ) ;
F_56 ( V_203 , V_199 ,
V_206 ) ;
}
}
}
if ( V_200 == sizeof( T_6 ) ) {
if ( V_199 > V_209 - sizeof( T_6 ) )
goto V_221;
if ( V_199 % sizeof( T_6 ) )
goto V_221;
if ( V_188 . V_189 . V_183 == V_190 )
F_57 ( V_203 , V_199 ,
( T_6 ) V_219 ) ;
if ( V_188 . V_189 . V_183 == V_191 ) {
V_150 = F_53 ( V_203 , V_199 , & V_205 ) ;
if ( ! V_150 ) {
V_205 |= ( T_6 ) V_219 ;
F_57 ( V_203 , V_199 ,
V_205 ) ;
}
}
if ( V_188 . V_189 . V_183 == V_192 ) {
V_150 = F_53 ( V_203 , V_199 , & V_205 ) ;
if ( ! V_150 ) {
V_205 &= ( T_6 ) ( ~ V_219 ) ;
F_57 ( V_203 , V_199 ,
V_205 ) ;
}
}
}
if ( V_200 == sizeof( T_1 ) ) {
if ( V_199 > V_209 - sizeof( T_1 ) )
goto V_221;
if ( V_199 % sizeof( T_1 ) )
goto V_221;
if ( V_188 . V_189 . V_183 == V_190 )
F_58 ( V_203 , V_199 , V_219 ) ;
if ( V_188 . V_189 . V_183 == V_191 ) {
V_150 = F_54 ( V_203 , V_199 ,
& V_204 ) ;
if ( ! V_150 ) {
V_204 |= V_219 ;
F_58 ( V_203 , V_199 ,
V_204 ) ;
}
}
if ( V_188 . V_189 . V_183 == V_192 ) {
V_150 = F_54 ( V_203 , V_199 ,
& V_204 ) ;
if ( ! V_150 ) {
V_204 &= ~ V_219 ;
F_58 ( V_203 , V_199 ,
V_204 ) ;
}
}
}
} else
goto V_221;
return V_167 ;
V_221:
memset ( & V_188 , 0 , sizeof( V_188 ) ) ;
return - V_174 ;
}
static T_2
F_59 ( struct V_146 * V_146 , char T_3 * V_3 , T_4 V_167 ,
T_5 * V_168 )
{
struct V_148 * V_149 = V_146 -> V_154 ;
struct V_26 * V_27 = (struct V_26 * ) V_149 -> V_147 ;
int V_196 , V_197 , V_224 , V_7 = 0 , V_6 ;
int V_225 , V_226 , V_227 ;
char * V_201 ;
void T_8 * V_228 ;
T_1 V_229 ;
struct V_202 * V_203 ;
T_1 V_204 ;
V_203 = V_27 -> V_207 ;
if ( ! V_203 )
return 0 ;
V_149 -> V_186 = V_208 ;
if ( ! V_149 -> V_12 )
V_149 -> V_12 = F_2 ( V_230 , V_14 ) ;
if ( ! V_149 -> V_12 )
return 0 ;
V_201 = V_149 -> V_12 ;
if ( * V_168 )
return 0 ;
if ( V_188 . V_189 . V_183 == V_231 ) {
V_225 = V_188 . V_189 . V_185 [ V_232 ] ;
V_197 = V_188 . V_189 . V_185 [ V_233 ] ;
V_226 = V_188 . V_189 . V_185 [ V_234 ] ;
V_227 = V_188 . V_189 . V_185 [ V_235 ] ;
} else
return 0 ;
if ( V_226 == 0 )
return 0 ;
V_229 = F_60 ( V_236 , & V_27 -> V_237 . V_238 ) ;
if ( V_229 == V_239 ) {
if ( V_225 == V_240 )
V_228 = V_27 -> V_237 . V_241 ;
else if ( V_225 == V_242 )
V_228 = V_27 -> V_237 . V_243 ;
else if ( V_225 == V_244 )
V_228 = V_27 -> V_237 . V_245 ;
else
return 0 ;
} else if ( V_229 == V_246 ) {
if ( V_225 == V_240 )
V_228 = V_27 -> V_237 . V_241 ;
else
return 0 ;
} else
return 0 ;
if ( V_226 == V_247 ) {
V_224 = V_197 ;
V_204 = F_17 ( V_228 + V_224 ) ;
V_7 += snprintf ( V_201 + V_7 , V_230 - V_7 ,
L_48 , V_224 , V_204 ) ;
} else
goto V_248;
return F_39 ( V_3 , V_167 , V_168 , V_201 , V_7 ) ;
V_248:
V_196 = V_188 . V_197 . V_218 ;
V_224 = V_196 ;
V_7 += snprintf ( V_201 + V_7 , V_230 - V_7 ,
L_49 , V_196 ) ;
V_6 = V_249 ;
while ( V_6 > 0 ) {
V_204 = F_17 ( V_228 + V_224 ) ;
V_7 += snprintf ( V_201 + V_7 , V_230 - V_7 ,
L_46 , V_204 ) ;
V_224 += sizeof( T_1 ) ;
if ( V_226 == V_250 ) {
if ( V_224 >= V_227 ) {
V_7 += snprintf ( V_201 + V_7 ,
V_230 - V_7 , L_38 ) ;
break;
}
} else {
if ( V_224 >= V_197 +
( V_226 * sizeof( T_1 ) ) ) {
V_7 += snprintf ( V_201 + V_7 ,
V_230 - V_7 , L_38 ) ;
break;
}
}
V_6 -= sizeof( T_1 ) ;
if ( ! V_6 )
V_7 += snprintf ( V_201 + V_7 ,
V_230 - V_7 , L_38 ) ;
else if ( ! ( V_6 % ( 8 * sizeof( T_1 ) ) ) ) {
V_196 += ( 8 * sizeof( T_1 ) ) ;
V_7 += snprintf ( V_201 + V_7 ,
V_230 - V_7 ,
L_50 , V_196 ) ;
}
}
if ( V_6 == 0 ) {
V_188 . V_197 . V_218 += V_249 ;
if ( V_226 == V_250 ) {
if ( V_188 . V_197 . V_218 >= V_227 )
V_188 . V_197 . V_218 = 0 ;
} else {
if ( V_224 >= V_197 +
( V_226 * sizeof( T_1 ) ) )
V_188 . V_197 . V_218 = V_197 ;
}
} else {
if ( V_226 == V_250 )
V_188 . V_197 . V_218 = 0 ;
else
V_188 . V_197 . V_218 = V_197 ;
}
return F_39 ( V_3 , V_167 , V_168 , V_201 , V_7 ) ;
}
static T_2
F_61 ( struct V_146 * V_146 , const char T_3 * V_3 ,
T_4 V_167 , T_5 * V_168 )
{
struct V_148 * V_149 = V_146 -> V_154 ;
struct V_26 * V_27 = (struct V_26 * ) V_149 -> V_147 ;
T_1 V_225 , V_227 , V_197 , V_219 , V_226 ;
struct V_202 * V_203 ;
void T_8 * V_228 ;
T_1 V_229 ;
T_1 V_204 ;
int V_150 ;
V_203 = V_27 -> V_207 ;
if ( ! V_203 )
return - V_182 ;
V_149 -> V_186 = V_187 ;
V_150 = F_42 ( V_3 , V_167 , & V_188 . V_189 ) ;
if ( V_150 < 0 )
return V_150 ;
V_229 = F_60 ( V_236 , & V_27 -> V_237 . V_238 ) ;
V_225 = V_188 . V_189 . V_185 [ V_232 ] ;
if ( V_229 == V_239 ) {
if ( ( V_225 != V_240 ) &&
( V_225 != V_242 ) &&
( V_225 != V_244 ) )
goto V_221;
} else if ( V_229 == V_246 ) {
if ( V_225 != V_240 )
goto V_221;
} else
goto V_221;
if ( V_229 == V_239 ) {
if ( V_225 == V_240 ) {
V_188 . V_189 . V_185 [ V_235 ] =
V_251 ;
V_228 = V_27 -> V_237 . V_241 ;
} else if ( V_225 == V_242 ) {
V_188 . V_189 . V_185 [ V_235 ] =
V_252 ;
V_228 = V_27 -> V_237 . V_243 ;
} else if ( V_225 == V_244 ) {
V_188 . V_189 . V_185 [ V_235 ] =
V_253 ;
V_228 = V_27 -> V_237 . V_245 ;
} else
goto V_221;
} else if ( V_229 == V_246 ) {
if ( V_225 == V_240 ) {
V_188 . V_189 . V_185 [ V_235 ] =
V_254 ;
V_228 = V_27 -> V_237 . V_241 ;
} else
goto V_221;
} else
goto V_221;
V_197 = V_188 . V_189 . V_185 [ V_233 ] ;
if ( V_197 % sizeof( T_1 ) )
goto V_221;
V_227 = V_188 . V_189 . V_185 [ V_235 ] ;
if ( V_188 . V_189 . V_183 == V_231 ) {
if ( V_150 != V_255 )
goto V_221;
V_226 = V_188 . V_189 . V_185 [ V_234 ] ;
if ( V_226 == V_250 ) {
if ( V_197 > V_227 - sizeof( T_1 ) )
goto V_221;
V_188 . V_197 . V_218 = V_197 ;
} else if ( V_226 > V_247 ) {
if ( V_197 + V_226 * sizeof( T_1 ) > V_227 )
goto V_221;
V_188 . V_197 . V_218 = V_197 ;
} else if ( V_226 != V_247 )
goto V_221;
} else if ( V_188 . V_189 . V_183 == V_256 ||
V_188 . V_189 . V_183 == V_257 ||
V_188 . V_189 . V_183 == V_258 ) {
if ( V_150 != V_259 )
goto V_221;
V_226 = V_247 ;
V_219 = V_188 . V_189 . V_185 [ V_260 ] ;
if ( V_188 . V_189 . V_183 == V_256 ) {
F_62 ( V_219 , V_228 + V_197 ) ;
F_17 ( V_228 + V_197 ) ;
}
if ( V_188 . V_189 . V_183 == V_257 ) {
V_204 = F_17 ( V_228 + V_197 ) ;
V_204 |= V_219 ;
F_62 ( V_204 , V_228 + V_197 ) ;
F_17 ( V_228 + V_197 ) ;
}
if ( V_188 . V_189 . V_183 == V_258 ) {
V_204 = F_17 ( V_228 + V_197 ) ;
V_204 &= ~ V_219 ;
F_62 ( V_204 , V_228 + V_197 ) ;
F_17 ( V_228 + V_197 ) ;
}
} else
goto V_221;
return V_167 ;
V_221:
memset ( & V_188 , 0 , sizeof( V_188 ) ) ;
return - V_174 ;
}
static T_2
F_63 ( struct V_146 * V_146 , char T_3 * V_3 , T_4 V_167 ,
T_5 * V_168 )
{
struct V_148 * V_149 = V_146 -> V_154 ;
struct V_26 * V_27 = (struct V_26 * ) V_149 -> V_147 ;
int V_7 = 0 , V_261 ;
char * V_201 ;
if ( ! V_149 -> V_12 )
V_149 -> V_12 = F_2 ( V_262 , V_14 ) ;
if ( ! V_149 -> V_12 )
return 0 ;
V_201 = V_149 -> V_12 ;
if ( * V_168 )
return 0 ;
V_7 += snprintf ( V_201 + V_7 , V_262 - V_7 ,
L_51 ) ;
V_7 += snprintf ( V_201 + V_7 , V_262 - V_7 ,
L_52
L_53
L_54 ,
V_27 -> V_237 . V_263 -> V_264 ,
V_27 -> V_237 . V_263 -> V_61 ,
V_27 -> V_237 . V_263 -> V_265 ,
V_27 -> V_237 . V_263 -> V_266 ,
V_27 -> V_237 . V_263 -> V_267 ) ;
V_7 += snprintf ( V_201 + V_7 , V_262 - V_7 ,
L_55 ) ;
for ( V_261 = 0 ; V_261 < V_27 -> V_268 ; V_261 ++ ) {
V_7 += snprintf ( V_201 + V_7 , V_262 - V_7 ,
L_52
L_53
L_56 ,
V_27 -> V_237 . V_269 [ V_261 ] -> V_264 ,
V_27 -> V_237 . V_269 [ V_261 ] -> V_61 ,
V_27 -> V_237 . V_269 [ V_261 ] -> V_265 ,
V_27 -> V_237 . V_269 [ V_261 ] -> V_266 ,
V_27 -> V_237 . V_269 [ V_261 ] -> V_267 ) ;
}
V_7 += snprintf ( V_201 + V_7 , V_262 - V_7 , L_38 ) ;
V_7 += snprintf ( V_201 + V_7 , V_262 - V_7 ,
L_57 ) ;
V_7 += snprintf ( V_201 + V_7 , V_262 - V_7 ,
L_58 ,
V_27 -> V_237 . V_270 -> V_271 ) ;
V_7 += snprintf ( V_201 + V_7 , V_262 - V_7 ,
L_59
L_53
L_54 ,
V_27 -> V_237 . V_270 -> V_264 ,
V_27 -> V_237 . V_270 -> V_61 ,
V_27 -> V_237 . V_270 -> V_265 ,
V_27 -> V_237 . V_270 -> V_266 ,
V_27 -> V_237 . V_270 -> V_267 ) ;
V_7 += snprintf ( V_201 + V_7 , V_262 - V_7 ,
L_60 ) ;
V_7 += snprintf ( V_201 + V_7 , V_262 - V_7 ,
L_58 ,
V_27 -> V_237 . V_272 -> V_271 ) ;
V_7 += snprintf ( V_201 + V_7 , V_262 - V_7 ,
L_61
L_53
L_54 ,
V_27 -> V_237 . V_272 -> V_264 ,
V_27 -> V_237 . V_272 -> V_61 ,
V_27 -> V_237 . V_272 -> V_265 ,
V_27 -> V_237 . V_272 -> V_266 ,
V_27 -> V_237 . V_272 -> V_267 ) ;
V_7 += snprintf ( V_201 + V_7 , V_262 - V_7 ,
L_62 ) ;
V_261 = 0 ;
do {
V_7 += snprintf ( V_201 + V_7 , V_262 - V_7 ,
L_58 ,
V_27 -> V_237 . V_273 [ V_261 ] -> V_271 ) ;
V_7 += snprintf ( V_201 + V_7 , V_262 - V_7 ,
L_59
L_53
L_56 ,
V_27 -> V_237 . V_273 [ V_261 ] -> V_264 ,
V_27 -> V_237 . V_273 [ V_261 ] -> V_61 ,
V_27 -> V_237 . V_273 [ V_261 ] -> V_265 ,
V_27 -> V_237 . V_273 [ V_261 ] -> V_266 ,
V_27 -> V_237 . V_273 [ V_261 ] -> V_267 ) ;
} while ( ++ V_261 < V_27 -> V_268 );
V_7 += snprintf ( V_201 + V_7 , V_262 - V_7 , L_38 ) ;
V_7 += snprintf ( V_201 + V_7 , V_262 - V_7 ,
L_63 ) ;
V_7 += snprintf ( V_201 + V_7 , V_262 - V_7 ,
L_64 ,
V_27 -> V_237 . V_274 -> V_271 ) ;
V_7 += snprintf ( V_201 + V_7 , V_262 - V_7 ,
L_65
L_53
L_54 ,
V_27 -> V_237 . V_274 -> V_264 ,
V_27 -> V_237 . V_274 -> V_61 ,
V_27 -> V_237 . V_274 -> V_265 ,
V_27 -> V_237 . V_274 -> V_266 ,
V_27 -> V_237 . V_274 -> V_267 ) ;
V_7 += snprintf ( V_201 + V_7 , V_262 - V_7 ,
L_66 ) ;
V_7 += snprintf ( V_201 + V_7 , V_262 - V_7 ,
L_64 ,
V_27 -> V_237 . V_275 -> V_271 ) ;
V_7 += snprintf ( V_201 + V_7 , V_262 - V_7 ,
L_65
L_53
L_54 ,
V_27 -> V_237 . V_275 -> V_264 ,
V_27 -> V_237 . V_275 -> V_61 ,
V_27 -> V_237 . V_275 -> V_265 ,
V_27 -> V_237 . V_275 -> V_266 ,
V_27 -> V_237 . V_275 -> V_267 ) ;
V_7 += snprintf ( V_201 + V_7 , V_262 - V_7 ,
L_67 ) ;
for ( V_261 = 0 ; V_261 < V_27 -> V_276 ; V_261 ++ ) {
V_7 += snprintf ( V_201 + V_7 , V_262 - V_7 ,
L_64 ,
V_27 -> V_237 . V_277 [ V_261 ] -> V_271 ) ;
V_7 += snprintf ( V_201 + V_7 , V_262 - V_7 ,
L_65
L_68
L_56 ,
V_27 -> V_237 . V_277 [ V_261 ] -> V_264 ,
V_27 -> V_237 . V_277 [ V_261 ] -> V_61 ,
V_27 -> V_237 . V_277 [ V_261 ] -> V_265 ,
V_27 -> V_237 . V_277 [ V_261 ] -> V_266 ,
V_27 -> V_237 . V_277 [ V_261 ] -> V_267 ) ;
}
V_7 += snprintf ( V_201 + V_7 , V_262 - V_7 , L_38 ) ;
V_7 += snprintf ( V_201 + V_7 , V_262 - V_7 ,
L_69 ) ;
V_7 += snprintf ( V_201 + V_7 , V_262 - V_7 ,
L_64 ,
V_27 -> V_237 . V_278 -> V_271 ) ;
V_7 += snprintf ( V_201 + V_7 , V_262 - V_7 ,
L_70
L_53
L_56 ,
V_27 -> V_237 . V_278 -> V_264 ,
V_27 -> V_237 . V_278 -> V_61 ,
V_27 -> V_237 . V_278 -> V_265 ,
V_27 -> V_237 . V_278 -> V_266 ,
V_27 -> V_237 . V_278 -> V_267 ) ;
V_7 += snprintf ( V_201 + V_7 , V_262 - V_7 ,
L_71
L_53
L_56 ,
V_27 -> V_237 . V_279 -> V_264 ,
V_27 -> V_237 . V_279 -> V_61 ,
V_27 -> V_237 . V_279 -> V_265 ,
V_27 -> V_237 . V_279 -> V_266 ,
V_27 -> V_237 . V_279 -> V_267 ) ;
return F_39 ( V_3 , V_167 , V_168 , V_201 , V_7 ) ;
}
static int
F_64 ( struct V_280 * V_281 , int V_6 , int V_200 )
{
if ( ( V_200 != 1 ) && ( V_200 != V_282 ) )
return - V_174 ;
if ( V_6 > V_281 -> V_61 - 1 )
return - V_174 ;
return 0 ;
}
static int
F_65 ( char * V_201 , int V_7 , struct V_280 * V_283 ,
T_1 V_6 )
{
int V_197 , V_284 ;
T_1 * V_285 ;
if ( ! V_201 || ! V_283 )
return 0 ;
V_284 = V_283 -> V_265 ;
V_7 += snprintf ( V_201 + V_7 , V_286 - V_7 ,
L_72 , V_6 ) ;
V_197 = 0 ;
V_285 = V_283 -> V_287 [ V_6 ] . V_288 ;
while ( V_284 > 0 ) {
V_7 += snprintf ( V_201 + V_7 , V_286 - V_7 ,
L_46 , * V_285 ) ;
V_285 ++ ;
V_197 += sizeof( T_1 ) ;
V_284 -= sizeof( T_1 ) ;
if ( V_284 > 0 && ! ( V_197 % ( 4 * sizeof( T_1 ) ) ) )
V_7 += snprintf ( V_201 + V_7 ,
V_286 - V_7 , L_38 ) ;
}
V_7 += snprintf ( V_201 + V_7 , V_286 - V_7 , L_38 ) ;
return V_7 ;
}
static T_2
F_66 ( struct V_146 * V_146 , char T_3 * V_3 , T_4 V_167 ,
T_5 * V_168 )
{
struct V_148 * V_149 = V_146 -> V_154 ;
T_1 V_289 , V_6 , V_200 ;
struct V_280 * V_283 = NULL ;
char * V_201 ;
int V_7 = 0 ;
V_149 -> V_186 = V_208 ;
if ( ! V_149 -> V_12 )
V_149 -> V_12 = F_2 ( V_286 , V_14 ) ;
if ( ! V_149 -> V_12 )
return 0 ;
V_201 = V_149 -> V_12 ;
if ( * V_168 )
return 0 ;
if ( V_188 . V_189 . V_183 == V_290 ) {
V_6 = V_188 . V_189 . V_185 [ V_291 ] ;
V_200 = V_188 . V_189 . V_185 [ V_292 ] ;
V_283 = (struct V_280 * ) V_188 . V_293 ;
} else
return 0 ;
if ( V_200 == V_282 )
goto V_294;
V_7 = F_65 ( V_201 , V_7 , V_283 , V_6 ) ;
return F_39 ( V_3 , V_167 , V_168 , V_201 , V_7 ) ;
V_294:
V_289 = V_188 . V_197 . V_218 ;
V_6 = V_289 ;
while ( V_7 < V_295 - V_283 -> V_265 ) {
V_7 = F_65 ( V_201 , V_7 , V_283 , V_6 ) ;
V_6 ++ ;
if ( V_6 > V_283 -> V_61 - 1 )
break;
}
if ( V_6 > V_283 -> V_61 - 1 )
V_6 = 0 ;
V_188 . V_197 . V_218 = V_6 ;
return F_39 ( V_3 , V_167 , V_168 , V_201 , V_7 ) ;
}
static T_2
F_67 ( struct V_146 * V_146 , const char T_3 * V_3 ,
T_4 V_167 , T_5 * V_168 )
{
struct V_148 * V_149 = V_146 -> V_154 ;
struct V_26 * V_27 = (struct V_26 * ) V_149 -> V_147 ;
T_1 V_296 , V_297 , V_298 , V_6 , V_200 , V_197 , V_219 ;
T_1 * V_285 ;
struct V_280 * V_283 ;
int V_150 ;
V_149 -> V_186 = V_187 ;
V_150 = F_42 ( V_3 , V_167 , & V_188 . V_189 ) ;
if ( V_150 < 0 )
return V_150 ;
V_297 = V_188 . V_189 . V_185 [ V_299 ] ;
V_298 = V_188 . V_189 . V_185 [ V_300 ] ;
V_6 = V_188 . V_189 . V_185 [ V_291 ] ;
V_200 = V_188 . V_189 . V_185 [ V_292 ] ;
V_197 = V_188 . V_189 . V_185 [ V_301 ] ;
V_219 = V_188 . V_189 . V_185 [ V_302 ] ;
if ( V_188 . V_189 . V_183 == V_193 ||
V_188 . V_189 . V_183 == V_194 ||
V_188 . V_189 . V_183 == V_195 ) {
if ( V_150 != V_303 )
goto V_221;
if ( V_200 != 1 )
goto V_221;
} else if ( V_188 . V_189 . V_183 == V_290 ) {
if ( V_150 != V_304 )
goto V_221;
} else
goto V_221;
switch ( V_297 ) {
case V_305 :
if ( V_27 -> V_237 . V_263 -> V_264 == V_298 ) {
V_150 = F_64 (
V_27 -> V_237 . V_263 , V_6 , V_200 ) ;
if ( V_150 )
goto V_221;
V_188 . V_293 = V_27 -> V_237 . V_263 ;
goto V_306;
}
for ( V_296 = 0 ; V_296 < V_27 -> V_268 ; V_296 ++ ) {
if ( V_27 -> V_237 . V_269 [ V_296 ] -> V_264 == V_298 ) {
V_150 = F_64 (
V_27 -> V_237 . V_269 [ V_296 ] ,
V_6 , V_200 ) ;
if ( V_150 )
goto V_221;
V_188 . V_293 = V_27 -> V_237 . V_269 [ V_296 ] ;
goto V_306;
}
}
goto V_221;
break;
case V_307 :
if ( V_27 -> V_237 . V_270 -> V_264 == V_298 ) {
V_150 = F_64 (
V_27 -> V_237 . V_270 , V_6 , V_200 ) ;
if ( V_150 )
goto V_221;
V_188 . V_293 = V_27 -> V_237 . V_270 ;
goto V_306;
}
if ( V_27 -> V_237 . V_272 -> V_264 == V_298 ) {
V_150 = F_64 (
V_27 -> V_237 . V_272 , V_6 , V_200 ) ;
if ( V_150 )
goto V_221;
V_188 . V_293 = V_27 -> V_237 . V_272 ;
goto V_306;
}
V_296 = 0 ;
do {
if ( V_27 -> V_237 . V_273 [ V_296 ] -> V_264 == V_298 ) {
V_150 = F_64 (
V_27 -> V_237 . V_273 [ V_296 ] ,
V_6 , V_200 ) ;
if ( V_150 )
goto V_221;
V_188 . V_293 =
V_27 -> V_237 . V_273 [ V_296 ] ;
goto V_306;
}
} while ( ++ V_296 < V_27 -> V_268 );
goto V_221;
break;
case V_308 :
if ( V_27 -> V_237 . V_274 -> V_264 == V_298 ) {
V_150 = F_64 (
V_27 -> V_237 . V_274 , V_6 , V_200 ) ;
if ( V_150 )
goto V_221;
V_188 . V_293 = V_27 -> V_237 . V_274 ;
goto V_306;
}
break;
case V_309 :
if ( V_27 -> V_237 . V_275 -> V_264 == V_298 ) {
V_150 = F_64 (
V_27 -> V_237 . V_275 , V_6 , V_200 ) ;
if ( V_150 )
goto V_221;
V_188 . V_293 = V_27 -> V_237 . V_275 ;
goto V_306;
}
for ( V_296 = 0 ; V_296 < V_27 -> V_276 ; V_296 ++ ) {
if ( V_27 -> V_237 . V_277 [ V_296 ] -> V_264 == V_298 ) {
V_150 = F_64 (
V_27 -> V_237 . V_277 [ V_296 ] ,
V_6 , V_200 ) ;
if ( V_150 )
goto V_221;
V_188 . V_293 =
V_27 -> V_237 . V_277 [ V_296 ] ;
goto V_306;
}
}
goto V_221;
break;
case V_310 :
if ( V_27 -> V_237 . V_278 -> V_264 == V_298 ) {
V_150 = F_64 (
V_27 -> V_237 . V_278 , V_6 , V_200 ) ;
if ( V_150 )
goto V_221;
V_188 . V_293 = V_27 -> V_237 . V_278 ;
goto V_306;
}
if ( V_27 -> V_237 . V_279 -> V_264 == V_298 ) {
V_150 = F_64 (
V_27 -> V_237 . V_279 , V_6 , V_200 ) ;
if ( V_150 )
goto V_221;
V_188 . V_293 = V_27 -> V_237 . V_279 ;
goto V_306;
}
goto V_221;
break;
default:
goto V_221;
break;
}
V_306:
if ( V_188 . V_189 . V_183 == V_290 ) {
if ( V_200 == V_282 )
V_188 . V_197 . V_218 = V_6 ;
}
if ( V_188 . V_189 . V_183 == V_193 ||
V_188 . V_189 . V_183 == V_194 ||
V_188 . V_189 . V_183 == V_195 ) {
V_283 = (struct V_280 * ) V_188 . V_293 ;
if ( V_197 > V_283 -> V_265 / sizeof( T_1 ) - 1 )
goto V_221;
V_285 = V_283 -> V_287 [ V_6 ] . V_288 ;
V_285 += V_197 ;
if ( V_188 . V_189 . V_183 == V_193 )
* V_285 = V_219 ;
if ( V_188 . V_189 . V_183 == V_194 )
* V_285 |= V_219 ;
if ( V_188 . V_189 . V_183 == V_195 )
* V_285 &= ~ V_219 ;
}
return V_167 ;
V_221:
memset ( & V_188 , 0 , sizeof( V_188 ) ) ;
return - V_174 ;
}
static int
F_68 ( struct V_26 * V_27 , char * V_201 ,
int V_7 , T_1 V_311 )
{
if ( ! V_201 )
return 0 ;
switch ( V_311 ) {
case V_312 :
V_7 += snprintf ( V_201 + V_7 , V_313 - V_7 ,
L_73 ,
F_17 ( V_27 -> V_237 . V_314 ) ) ;
break;
case V_315 :
V_7 += snprintf ( V_201 + V_7 , V_313 - V_7 ,
L_74 ,
F_17 ( V_27 -> V_237 . V_316 ) ) ;
break;
case V_317 :
V_7 += snprintf ( V_201 + V_7 , V_313 - V_7 ,
L_75 ,
F_17 ( V_27 -> V_237 . V_318 ) ) ;
break;
case V_319 :
V_7 += snprintf ( V_201 + V_7 , V_313 - V_7 ,
L_76 ,
F_17 ( V_27 -> V_237 . V_320 ) ) ;
break;
default:
break;
}
return V_7 ;
}
static T_2
F_69 ( struct V_146 * V_146 , char T_3 * V_3 , T_4 V_167 ,
T_5 * V_168 )
{
struct V_148 * V_149 = V_146 -> V_154 ;
struct V_26 * V_27 = (struct V_26 * ) V_149 -> V_147 ;
T_1 V_321 , V_5 ;
char * V_201 ;
int V_7 = 0 ;
V_149 -> V_186 = V_208 ;
if ( ! V_149 -> V_12 )
V_149 -> V_12 = F_2 ( V_313 , V_14 ) ;
if ( ! V_149 -> V_12 )
return 0 ;
V_201 = V_149 -> V_12 ;
if ( * V_168 )
return 0 ;
if ( V_188 . V_189 . V_183 == V_322 )
V_321 = V_188 . V_189 . V_185 [ V_323 ] ;
else
return 0 ;
if ( V_321 == V_324 )
for ( V_5 = 1 ; V_5 <= V_325 ; V_5 ++ )
V_7 = F_68 ( V_27 ,
V_201 , V_7 , V_5 ) ;
else
V_7 = F_68 ( V_27 ,
V_201 , V_7 , V_321 ) ;
return F_39 ( V_3 , V_167 , V_168 , V_201 , V_7 ) ;
}
static T_2
F_70 ( struct V_146 * V_146 , const char T_3 * V_3 ,
T_4 V_167 , T_5 * V_168 )
{
struct V_148 * V_149 = V_146 -> V_154 ;
struct V_26 * V_27 = (struct V_26 * ) V_149 -> V_147 ;
T_1 V_321 , V_219 , V_326 = 0 ;
void T_8 * V_327 ;
int V_150 ;
V_149 -> V_186 = V_187 ;
V_150 = F_42 ( V_3 , V_167 , & V_188 . V_189 ) ;
if ( V_150 < 0 )
return V_150 ;
V_321 = V_188 . V_189 . V_185 [ V_323 ] ;
V_219 = V_188 . V_189 . V_185 [ V_328 ] ;
if ( V_188 . V_189 . V_183 == V_329 ||
V_188 . V_189 . V_183 == V_330 ||
V_188 . V_189 . V_183 == V_331 ) {
if ( V_150 != V_332 )
goto V_221;
if ( V_321 > V_325 )
goto V_221;
} else if ( V_188 . V_189 . V_183 == V_322 ) {
if ( V_150 != V_333 )
goto V_221;
if ( ( V_321 > V_325 ) &&
( V_321 != V_324 ) )
goto V_221;
} else
goto V_221;
if ( V_188 . V_189 . V_183 == V_329 ||
V_188 . V_189 . V_183 == V_330 ||
V_188 . V_189 . V_183 == V_331 ) {
switch ( V_321 ) {
case V_312 :
V_327 = V_27 -> V_237 . V_314 ;
break;
case V_315 :
V_327 = V_27 -> V_237 . V_316 ;
break;
case V_317 :
V_327 = V_27 -> V_237 . V_318 ;
break;
case V_319 :
V_327 = V_27 -> V_237 . V_320 ;
break;
default:
goto V_221;
}
if ( V_188 . V_189 . V_183 == V_329 )
V_326 = V_219 ;
if ( V_188 . V_189 . V_183 == V_330 ) {
V_326 = F_17 ( V_327 ) ;
V_326 |= V_219 ;
}
if ( V_188 . V_189 . V_183 == V_331 ) {
V_326 = F_17 ( V_327 ) ;
V_326 &= ~ V_219 ;
}
F_62 ( V_326 , V_327 ) ;
F_17 ( V_327 ) ;
}
return V_167 ;
V_221:
memset ( & V_188 , 0 , sizeof( V_188 ) ) ;
return - V_174 ;
}
static int
F_71 ( struct V_26 * V_27 , char * V_201 ,
int V_7 , T_1 V_334 )
{
if ( ! V_201 )
return 0 ;
switch ( V_334 ) {
case V_335 :
V_7 += snprintf ( V_201 + V_7 , V_336 - V_7 ,
L_77 ,
F_17 ( V_27 -> V_237 . V_241 +
V_337 ) ) ;
break;
case V_338 :
V_7 += snprintf ( V_201 + V_7 , V_336 - V_7 ,
L_78 ,
F_17 ( V_27 -> V_237 . V_241 +
V_339 ) ) ;
break;
case V_340 :
V_7 += snprintf ( V_201 + V_7 , V_336 - V_7 ,
L_79 ,
F_17 ( V_27 -> V_237 . V_241 +
V_341 ) ) ;
break;
case V_342 :
V_7 += snprintf ( V_201 + V_7 , V_336 - V_7 ,
L_80 ,
F_17 ( V_27 -> V_237 . V_241 +
V_343 ) ) ;
break;
case V_344 :
V_7 += snprintf ( V_201 + V_7 , V_336 - V_7 ,
L_81 ,
F_17 ( V_27 -> V_237 . V_241 +
V_345 ) ) ;
break;
case V_346 :
V_7 += snprintf ( V_201 + V_7 , V_336 - V_7 ,
L_82 ,
F_17 ( V_27 -> V_237 . V_241 +
V_347 ) ) ;
break;
default:
break;
}
return V_7 ;
}
static T_2
F_72 ( struct V_146 * V_146 , char T_3 * V_3 , T_4 V_167 ,
T_5 * V_168 )
{
struct V_148 * V_149 = V_146 -> V_154 ;
struct V_26 * V_27 = (struct V_26 * ) V_149 -> V_147 ;
T_1 V_348 , V_5 ;
char * V_201 ;
int V_7 = 0 ;
V_149 -> V_186 = V_208 ;
if ( ! V_149 -> V_12 )
V_149 -> V_12 = F_2 ( V_336 , V_14 ) ;
if ( ! V_149 -> V_12 )
return 0 ;
V_201 = V_149 -> V_12 ;
if ( * V_168 )
return 0 ;
if ( V_188 . V_189 . V_183 == V_349 )
V_348 = V_188 . V_189 . V_185 [ V_350 ] ;
else
return 0 ;
if ( V_348 == V_351 )
for ( V_5 = 1 ; V_5 <= V_352 ; V_5 ++ )
V_7 = F_71 ( V_27 ,
V_201 , V_7 , V_5 ) ;
else
V_7 = F_71 ( V_27 ,
V_201 , V_7 , V_348 ) ;
return F_39 ( V_3 , V_167 , V_168 , V_201 , V_7 ) ;
}
static T_2
F_73 ( struct V_146 * V_146 , const char T_3 * V_3 ,
T_4 V_167 , T_5 * V_168 )
{
struct V_148 * V_149 = V_146 -> V_154 ;
struct V_26 * V_27 = (struct V_26 * ) V_149 -> V_147 ;
T_1 V_348 , V_219 , V_326 = 0 ;
void T_8 * V_353 ;
int V_150 ;
V_149 -> V_186 = V_187 ;
V_150 = F_42 ( V_3 , V_167 , & V_188 . V_189 ) ;
if ( V_150 < 0 )
return V_150 ;
V_348 = V_188 . V_189 . V_185 [ V_350 ] ;
V_219 = V_188 . V_189 . V_185 [ V_354 ] ;
if ( V_188 . V_189 . V_183 == V_355 ||
V_188 . V_189 . V_183 == V_356 ||
V_188 . V_189 . V_183 == V_357 ) {
if ( V_150 != V_358 )
goto V_221;
if ( V_348 > V_352 )
goto V_221;
} else if ( V_188 . V_189 . V_183 == V_349 ) {
if ( V_150 != V_359 )
goto V_221;
if ( ( V_348 > V_352 ) &&
( V_348 != V_351 ) )
goto V_221;
} else
goto V_221;
if ( V_188 . V_189 . V_183 == V_355 ||
V_188 . V_189 . V_183 == V_356 ||
V_188 . V_189 . V_183 == V_357 ) {
switch ( V_348 ) {
case V_335 :
V_353 = V_27 -> V_237 . V_241 +
V_337 ;
break;
case V_338 :
V_353 = V_27 -> V_237 . V_241 +
V_339 ;
break;
case V_340 :
V_353 = V_27 -> V_237 . V_241 +
V_341 ;
break;
case V_342 :
V_353 = V_27 -> V_237 . V_241 +
V_343 ;
break;
case V_344 :
V_353 = V_27 -> V_237 . V_241 +
V_345 ;
break;
case V_346 :
V_353 = V_27 -> V_237 . V_241 +
V_347 ;
break;
default:
goto V_221;
}
if ( V_188 . V_189 . V_183 == V_355 )
V_326 = V_219 ;
if ( V_188 . V_189 . V_183 == V_356 ) {
V_326 = F_17 ( V_353 ) ;
V_326 |= V_219 ;
}
if ( V_188 . V_189 . V_183 == V_357 ) {
V_326 = F_17 ( V_353 ) ;
V_326 &= ~ V_219 ;
}
F_62 ( V_326 , V_353 ) ;
F_17 ( V_353 ) ;
}
return V_167 ;
V_221:
memset ( & V_188 , 0 , sizeof( V_188 ) ) ;
return - V_174 ;
}
static int
F_74 ( struct V_26 * V_27 , char * V_201 )
{
T_1 V_360 , V_361 , V_362 , V_363 ;
int V_7 = 0 ;
V_363 = V_188 . V_189 . V_185 [ V_364 ] ;
V_360 = V_188 . V_189 . V_185 [ V_365 ] ;
V_361 = V_188 . V_189 . V_185 [ V_366 ] ;
V_362 = V_188 . V_189 . V_185 [ V_367 ] ;
V_7 += snprintf ( V_201 + V_7 , V_368 - V_7 ,
L_83 , V_360 ) ;
V_7 += snprintf ( V_201 + V_7 , V_368 - V_7 ,
L_84 , V_361 ) ;
V_7 += snprintf ( V_201 + V_7 , V_368 - V_7 ,
L_85 , V_362 ) ;
V_7 += snprintf ( V_201 + V_7 , V_368 - V_7 ,
L_86 , V_363 ) ;
return V_7 ;
}
static T_2
F_75 ( struct V_146 * V_146 , char T_3 * V_3 , T_4 V_167 ,
T_5 * V_168 )
{
struct V_148 * V_149 = V_146 -> V_154 ;
struct V_26 * V_27 = (struct V_26 * ) V_149 -> V_147 ;
char * V_201 ;
int V_7 = 0 ;
V_149 -> V_186 = V_208 ;
if ( ! V_149 -> V_12 )
V_149 -> V_12 = F_2 ( V_368 , V_14 ) ;
if ( ! V_149 -> V_12 )
return 0 ;
V_201 = V_149 -> V_12 ;
if ( * V_168 )
return 0 ;
if ( ( V_188 . V_189 . V_183 != V_369 ) &&
( V_188 . V_189 . V_183 != V_370 ) )
return 0 ;
V_7 = F_74 ( V_27 , V_201 ) ;
return F_39 ( V_3 , V_167 , V_168 , V_201 , V_7 ) ;
}
static T_2
F_76 ( struct V_146 * V_146 , const char T_3 * V_3 ,
T_4 V_167 , T_5 * V_168 )
{
struct V_148 * V_149 = V_146 -> V_154 ;
T_1 V_360 , V_361 , V_362 , V_363 ;
int V_150 ;
V_149 -> V_186 = V_187 ;
V_150 = F_42 ( V_3 , V_167 , & V_188 . V_189 ) ;
if ( V_150 < 0 )
return V_150 ;
V_363 = V_188 . V_189 . V_185 [ V_364 ] ;
V_360 = V_188 . V_189 . V_185 [ V_365 ] ;
V_361 = V_188 . V_189 . V_185 [ V_366 ] ;
V_362 = V_188 . V_189 . V_185 [ V_367 ] ;
if ( V_188 . V_189 . V_183 == V_369 ) {
if ( ! ( V_360 & V_371 ) )
goto V_221;
if ( ( V_360 & ~ V_371 ) &&
( V_360 != V_372 ) )
goto V_221;
if ( V_362 > sizeof( V_92 ) )
goto V_221;
} else if ( V_188 . V_189 . V_183 == V_370 ) {
if ( ! ( V_360 & V_373 ) )
goto V_221;
if ( ( V_360 & ~ V_373 ) &&
( V_360 != V_372 ) )
goto V_221;
if ( V_362 > ( V_374 ) / 4 )
goto V_221;
if ( V_363 != 0x9b )
goto V_221;
} else
goto V_221;
if ( V_362 == 0 )
goto V_221;
if ( V_150 != V_375 )
goto V_221;
if ( V_363 & ~ 0xff )
goto V_221;
if ( V_361 == 0 )
goto V_376;
return V_167 ;
V_376:
memset ( & V_188 , 0 , sizeof( V_188 ) ) ;
return V_167 ;
V_221:
memset ( & V_188 , 0 , sizeof( V_188 ) ) ;
return - V_174 ;
}
static int
F_77 ( struct V_26 * V_27 , char * V_201 , int V_7 )
{
T_6 V_377 , V_378 ;
V_7 += snprintf ( V_201 + V_7 , V_379 - V_7 ,
L_87 ) ;
V_7 += snprintf ( V_201 + V_7 , V_379 - V_7 ,
L_88 ) ;
F_78 ( V_27 , V_380 ,
& V_377 , & V_378 ) ;
V_7 += snprintf ( V_201 + V_7 , V_379 - V_7 ,
L_89 , V_377 , V_378 ) ;
V_7 += snprintf ( V_201 + V_7 , V_379 - V_7 ,
L_90 ) ;
F_78 ( V_27 , V_381 ,
& V_377 , & V_378 ) ;
V_7 += snprintf ( V_201 + V_7 , V_379 - V_7 ,
L_89 , V_377 , V_378 ) ;
V_7 += snprintf ( V_201 + V_7 , V_379 - V_7 ,
L_91 ) ;
F_78 ( V_27 , V_382 ,
& V_377 , & V_378 ) ;
V_7 += snprintf ( V_201 + V_7 , V_379 - V_7 ,
L_89 , V_377 , V_378 ) ;
V_7 += snprintf ( V_201 + V_7 , V_379 - V_7 ,
L_92 ) ;
F_78 ( V_27 , V_383 ,
& V_377 , & V_378 ) ;
V_7 += snprintf ( V_201 + V_7 , V_379 - V_7 ,
L_89 , V_377 , V_378 ) ;
return V_7 ;
}
static int
F_79 ( struct V_26 * V_27 , char * V_201 , int V_7 )
{
T_6 V_377 , V_378 ;
int V_150 ;
V_7 += snprintf ( V_201 + V_7 , V_379 - V_7 ,
L_93 ) ;
V_7 += snprintf ( V_201 + V_7 , V_379 - V_7 ,
L_94 ) ;
V_150 = F_80 ( V_27 , V_380 ,
& V_377 , & V_378 ) ;
if ( ! V_150 )
V_7 += snprintf ( V_201 + V_7 , V_379 - V_7 ,
L_95 ,
V_27 -> V_384 , V_377 , V_378 ) ;
else
V_7 += snprintf ( V_201 + V_7 , V_379 - V_7 ,
L_96 ) ;
V_7 += snprintf ( V_201 + V_7 , V_379 - V_7 ,
L_97 ) ;
V_150 = F_80 ( V_27 , V_381 ,
& V_377 , & V_378 ) ;
if ( ! V_150 )
V_7 += snprintf ( V_201 + V_7 , V_379 - V_7 ,
L_95 ,
V_27 -> V_384 , V_377 , V_378 ) ;
else
V_7 += snprintf ( V_201 + V_7 , V_379 - V_7 ,
L_96 ) ;
V_7 += snprintf ( V_201 + V_7 , V_379 - V_7 ,
L_98 ) ;
V_150 = F_80 ( V_27 , V_382 ,
& V_377 , & V_378 ) ;
if ( ! V_150 )
V_7 += snprintf ( V_201 + V_7 , V_379 - V_7 ,
L_95 ,
V_27 -> V_384 , V_377 , V_378 ) ;
else
V_7 += snprintf ( V_201 + V_7 , V_379 - V_7 ,
L_96 ) ;
V_7 += snprintf ( V_201 + V_7 , V_379 - V_7 ,
L_99 ) ;
V_150 = F_80 ( V_27 , V_383 ,
& V_377 , & V_378 ) ;
if ( ! V_150 )
V_7 += snprintf ( V_201 + V_7 , V_379 - V_7 ,
L_95 ,
V_27 -> V_384 , V_377 , V_378 ) ;
else
V_7 += snprintf ( V_201 + V_7 , V_379 - V_7 ,
L_96 ) ;
return V_7 ;
}
static int
F_81 ( struct V_26 * V_27 , char * V_201 , int V_7 )
{
struct V_385 * V_386 ;
int V_6 ;
V_7 += snprintf ( V_201 + V_7 , V_379 - V_7 ,
L_100 ) ;
V_7 += snprintf ( V_201 + V_7 , V_379 - V_7 ,
L_101 ) ;
V_6 = 0 ;
F_10 (rsrc_blks, &phba->lpfc_vpi_blk_list, list) {
V_7 += snprintf ( V_201 + V_7 , V_379 - V_7 ,
L_102 ,
V_6 , V_386 -> V_387 ,
V_386 -> V_388 ) ;
V_6 ++ ;
}
V_7 += snprintf ( V_201 + V_7 , V_379 - V_7 ,
L_103 ) ;
V_6 = 0 ;
F_10 (rsrc_blks, &phba->sli4_hba.lpfc_vfi_blk_list,
list) {
V_7 += snprintf ( V_201 + V_7 , V_379 - V_7 ,
L_102 ,
V_6 , V_386 -> V_387 ,
V_386 -> V_388 ) ;
V_6 ++ ;
}
V_7 += snprintf ( V_201 + V_7 , V_379 - V_7 ,
L_104 ) ;
V_6 = 0 ;
F_10 (rsrc_blks, &phba->sli4_hba.lpfc_rpi_blk_list,
list) {
V_7 += snprintf ( V_201 + V_7 , V_379 - V_7 ,
L_102 ,
V_6 , V_386 -> V_387 ,
V_386 -> V_388 ) ;
V_6 ++ ;
}
V_7 += snprintf ( V_201 + V_7 , V_379 - V_7 ,
L_105 ) ;
V_6 = 0 ;
F_10 (rsrc_blks, &phba->sli4_hba.lpfc_xri_blk_list,
list) {
V_7 += snprintf ( V_201 + V_7 , V_379 - V_7 ,
L_102 ,
V_6 , V_386 -> V_387 ,
V_386 -> V_388 ) ;
V_6 ++ ;
}
return V_7 ;
}
static T_2
F_82 ( struct V_146 * V_146 , const char T_3 * V_3 ,
T_4 V_167 , T_5 * V_168 )
{
struct V_148 * V_149 = V_146 -> V_154 ;
T_1 V_389 ;
int V_150 ;
V_149 -> V_186 = V_187 ;
V_150 = F_42 ( V_3 , V_167 , & V_188 . V_189 ) ;
if ( V_150 < 0 )
return V_150 ;
V_389 = V_188 . V_189 . V_185 [ V_390 ] ;
if ( V_188 . V_189 . V_183 != V_391 )
goto V_221;
if ( V_150 != V_392 )
goto V_221;
if ( ! ( V_389 & V_393 ) )
goto V_221;
return V_167 ;
V_221:
memset ( & V_188 , 0 , sizeof( V_188 ) ) ;
return - V_174 ;
}
static T_2
F_83 ( struct V_146 * V_146 , char T_3 * V_3 , T_4 V_167 ,
T_5 * V_168 )
{
struct V_148 * V_149 = V_146 -> V_154 ;
struct V_26 * V_27 = (struct V_26 * ) V_149 -> V_147 ;
char * V_201 ;
T_1 V_389 ;
int V_7 = 0 ;
V_149 -> V_186 = V_208 ;
if ( ! V_149 -> V_12 )
V_149 -> V_12 = F_2 ( V_379 , V_14 ) ;
if ( ! V_149 -> V_12 )
return 0 ;
V_201 = V_149 -> V_12 ;
if ( * V_168 )
return 0 ;
if ( V_188 . V_189 . V_183 != V_391 )
return 0 ;
V_389 = V_188 . V_189 . V_185 [ V_390 ] ;
if ( V_389 & V_394 )
V_7 = F_77 ( V_27 , V_201 , V_7 ) ;
if ( V_389 & V_395 )
V_7 = F_79 ( V_27 , V_201 , V_7 ) ;
if ( V_389 & V_396 )
V_7 = F_81 ( V_27 , V_201 , V_7 ) ;
return F_39 ( V_3 , V_167 , V_168 , V_201 , V_7 ) ;
}
void
F_84 ( struct V_26 * V_27 , enum V_397 V_398 ,
enum V_399 V_400 , enum V_401 V_402 ,
enum V_403 V_404 ,
struct V_45 * V_405 , T_1 V_406 )
{
#ifdef F_21
T_1 * V_363 , * V_360 , * V_361 , * V_362 ;
char V_407 [ V_408 ] ;
int V_7 = 0 ;
T_1 V_409 = 0 ;
T_1 * V_410 ;
T_1 V_5 ;
if ( V_188 . V_189 . V_183 != V_370 )
return;
V_363 = & V_188 . V_189 . V_185 [ V_364 ] ;
V_360 = & V_188 . V_189 . V_185 [ V_365 ] ;
V_361 = & V_188 . V_189 . V_185 [ V_366 ] ;
V_362 = & V_188 . V_189 . V_185 [ V_367 ] ;
if ( ! ( * V_360 & V_372 ) ||
( * V_361 == 0 ) ||
( * V_362 == 0 ) )
return;
if ( * V_363 != 0x9B )
return;
if ( ( V_400 == V_411 ) && ( V_402 == V_412 ) ) {
if ( * V_360 & V_413 ) {
V_409 |= V_413 ;
F_31 ( V_159 L_106
L_107 ,
V_404 , V_398 , V_406 ) ;
}
}
if ( ( V_400 == V_411 ) && ( V_402 == V_414 ) ) {
if ( * V_360 & V_415 ) {
V_409 |= V_415 ;
F_31 ( V_159 L_108
L_109 ,
V_404 , V_398 , V_406 ) ;
}
}
if ( ( V_400 == V_416 ) && ( V_402 == V_412 ) ) {
if ( * V_360 & V_417 ) {
V_409 |= V_417 ;
F_31 ( V_159 L_110
L_107 ,
V_404 , V_398 , V_406 ) ;
}
}
if ( ( V_400 == V_416 ) && ( V_402 == V_414 ) ) {
if ( * V_360 & V_418 ) {
V_409 |= V_418 ;
F_31 ( V_159 L_111
L_109 ,
V_404 , V_398 , V_406 ) ;
}
}
if ( V_409 ) {
V_410 = ( T_1 * ) V_405 -> V_74 ;
for ( V_5 = 0 ; V_5 < * V_362 ; V_5 ++ ) {
if ( ! ( V_5 % 8 ) ) {
if ( V_5 != 0 )
F_31 ( V_159 L_112 , V_407 ) ;
V_7 = 0 ;
V_7 += snprintf ( V_407 + V_7 ,
V_408 - V_7 ,
L_113 , V_5 ) ;
}
V_7 += snprintf ( V_407 + V_7 , V_408 - V_7 ,
L_46 , ( T_1 ) * V_410 ) ;
V_410 ++ ;
}
if ( ( V_5 - 1 ) % 8 )
F_31 ( V_159 L_112 , V_407 ) ;
( * V_361 ) -- ;
}
if ( * V_361 == 0 )
memset ( & V_188 , 0 , sizeof( V_188 ) ) ;
return;
#endif
}
void
F_85 ( struct V_26 * V_27 , V_92 * V_419 )
{
#ifdef F_21
T_1 * V_360 , * V_361 , * V_362 , * V_363 ;
char V_407 [ V_408 ] ;
int V_7 = 0 ;
T_1 * V_410 ;
T_7 * V_420 ;
T_1 V_5 , V_32 ;
if ( V_188 . V_189 . V_183 != V_369 )
return;
V_363 = & V_188 . V_189 . V_185 [ V_364 ] ;
V_360 = & V_188 . V_189 . V_185 [ V_365 ] ;
V_361 = & V_188 . V_189 . V_185 [ V_366 ] ;
V_362 = & V_188 . V_189 . V_185 [ V_367 ] ;
if ( ! ( * V_360 & V_371 ) ||
( * V_361 == 0 ) ||
( * V_362 == 0 ) )
return;
if ( ( * V_363 != V_421 ) &&
( * V_363 != V_419 -> V_422 ) )
return;
if ( * V_360 & V_423 ) {
F_31 ( V_159 L_114 ,
V_419 -> V_422 ) ;
V_410 = ( T_1 * ) V_419 ;
for ( V_5 = 0 ; V_5 < * V_362 ; V_5 ++ ) {
if ( ! ( V_5 % 8 ) ) {
if ( V_5 != 0 )
F_31 ( V_159 L_112 , V_407 ) ;
V_7 = 0 ;
memset ( V_407 , 0 , V_408 ) ;
V_7 += snprintf ( V_407 + V_7 ,
V_408 - V_7 ,
L_113 , V_5 ) ;
}
V_7 += snprintf ( V_407 + V_7 , V_408 - V_7 ,
L_46 ,
( ( T_1 ) * V_410 ) & 0xffffffff ) ;
V_410 ++ ;
}
if ( ( V_5 - 1 ) % 8 )
F_31 ( V_159 L_112 , V_407 ) ;
F_31 ( V_159 L_38 ) ;
}
if ( * V_360 & V_424 ) {
F_31 ( V_159 L_115 ,
V_419 -> V_422 ) ;
V_420 = ( T_7 * ) V_419 ;
for ( V_5 = 0 ; V_5 < * V_362 ; V_5 ++ ) {
if ( ! ( V_5 % 8 ) ) {
if ( V_5 != 0 )
F_31 ( V_159 L_112 , V_407 ) ;
V_7 = 0 ;
memset ( V_407 , 0 , V_408 ) ;
V_7 += snprintf ( V_407 + V_7 ,
V_408 - V_7 ,
L_113 , V_5 ) ;
}
for ( V_32 = 0 ; V_32 < 4 ; V_32 ++ ) {
V_7 += snprintf ( V_407 + V_7 ,
V_408 - V_7 ,
L_116 ,
( ( T_7 ) * V_420 ) & 0xff ) ;
V_420 ++ ;
}
V_7 += snprintf ( V_407 + V_7 ,
V_408 - V_7 , L_117 ) ;
}
if ( ( V_5 - 1 ) % 8 )
F_31 ( V_159 L_112 , V_407 ) ;
F_31 ( V_159 L_38 ) ;
}
( * V_361 ) -- ;
if ( * V_361 == 0 )
memset ( & V_188 , 0 , sizeof( V_188 ) ) ;
return;
#endif
}
inline void
F_86 ( struct V_1 * V_2 )
{
#ifdef F_21
struct V_26 * V_27 = V_2 -> V_27 ;
char V_114 [ 64 ] ;
T_1 V_425 , V_5 ;
if ( ! V_15 )
return;
if ( ! V_426 ) {
V_426 = F_87 ( L_118 , NULL ) ;
F_88 ( & V_427 , 0 ) ;
if ( ! V_426 ) {
F_89 ( V_2 , V_159 , V_428 ,
L_119 ) ;
goto V_429;
}
}
if ( ! V_21 )
V_21 = V_144 ;
snprintf ( V_114 , sizeof( V_114 ) , L_120 , V_27 -> V_384 ) ;
if ( ! V_27 -> V_430 ) {
V_27 -> V_430 =
F_87 ( V_114 , V_426 ) ;
if ( ! V_27 -> V_430 ) {
F_89 ( V_2 , V_159 , V_428 ,
L_121 ) ;
goto V_429;
}
F_90 ( & V_427 ) ;
F_88 ( & V_27 -> V_431 , 0 ) ;
snprintf ( V_114 , sizeof( V_114 ) , L_122 ) ;
V_27 -> V_432 =
F_91 ( V_114 , V_433 | V_434 | V_435 ,
V_27 -> V_430 ,
V_27 , & V_436 ) ;
if ( ! V_27 -> V_432 ) {
F_89 ( V_2 , V_159 , V_428 ,
L_123 ) ;
goto V_429;
}
if ( V_27 -> V_49 < V_437 ) {
snprintf ( V_114 , sizeof( V_114 ) , L_124 ) ;
V_27 -> V_438 =
F_91 ( V_114 ,
V_433 | V_434 | V_435 ,
V_27 -> V_430 ,
V_27 , & V_439 ) ;
if ( ! V_27 -> V_438 ) {
F_89 ( V_2 , V_159 , V_428 ,
L_125
L_126 ) ;
goto V_429;
}
} else
V_27 -> V_438 = NULL ;
if ( V_27 -> V_49 < V_437 ) {
snprintf ( V_114 , sizeof( V_114 ) , L_127 ) ;
V_27 -> V_440 =
F_91 ( V_114 ,
V_433 | V_434 | V_435 ,
V_27 -> V_430 ,
V_27 , & V_441 ) ;
if ( ! V_27 -> V_440 ) {
F_89 ( V_2 , V_159 , V_428 ,
L_128
L_129 ) ;
goto V_429;
}
} else
V_27 -> V_438 = NULL ;
snprintf ( V_114 , sizeof( V_114 ) , L_130 ) ;
V_27 -> V_442 =
F_91 ( V_114 , V_433 | V_434 | V_435 ,
V_27 -> V_430 ,
V_27 , & V_443 ) ;
if ( ! V_27 -> V_442 ) {
F_89 ( V_2 , V_159 , V_428 ,
L_131 ) ;
goto V_429;
}
snprintf ( V_114 , sizeof( V_114 ) , L_132 ) ;
V_27 -> V_444 =
F_91 ( V_114 , V_433 | V_434 | V_435 ,
V_27 -> V_430 ,
V_27 , & V_445 ) ;
if ( ! V_27 -> V_444 ) {
F_89 ( V_2 , V_159 , V_428 ,
L_133 ) ;
goto V_429;
}
if ( V_29 ) {
V_425 = V_29 - 1 ;
if ( V_425 & V_29 ) {
V_425 = V_29 ;
V_5 = 0 ;
while ( V_425 > 1 ) {
V_425 = V_425 >> 1 ;
V_5 ++ ;
}
V_29 = ( 1 << V_5 ) ;
F_31 ( V_159
L_134
L_135 , V_17 ) ;
}
}
snprintf ( V_114 , sizeof( V_114 ) , L_136 ) ;
V_27 -> V_446 =
F_91 ( V_114 , V_433 | V_434 | V_435 ,
V_27 -> V_430 ,
V_27 , & V_447 ) ;
if ( ! V_27 -> V_446 ) {
F_89 ( V_2 , V_159 , V_428 ,
L_137
L_138 ) ;
goto V_429;
}
if ( ! V_27 -> V_30 ) {
V_27 -> V_30 = F_2 (
( sizeof( struct V_10 ) *
V_29 ) ,
V_14 ) ;
if ( ! V_27 -> V_30 ) {
F_89 ( V_2 , V_159 , V_428 ,
L_139
L_140 ) ;
goto V_429;
}
F_88 ( & V_27 -> V_28 , 0 ) ;
memset ( V_27 -> V_30 , 0 ,
( sizeof( struct V_10 ) *
V_29 ) ) ;
}
}
snprintf ( V_114 , sizeof( V_114 ) , L_141 , V_2 -> V_448 ) ;
if ( ! V_2 -> V_449 ) {
V_2 -> V_449 =
F_87 ( V_114 , V_27 -> V_430 ) ;
if ( ! V_2 -> V_449 ) {
F_89 ( V_2 , V_159 , V_428 ,
L_142 ) ;
goto V_429;
}
F_90 ( & V_27 -> V_431 ) ;
}
if ( V_17 ) {
V_425 = V_17 - 1 ;
if ( V_425 & V_17 ) {
V_425 = V_17 ;
V_5 = 0 ;
while ( V_425 > 1 ) {
V_425 = V_425 >> 1 ;
V_5 ++ ;
}
V_17 = ( 1 << V_5 ) ;
F_31 ( V_159
L_143 ,
V_17 ) ;
}
}
V_2 -> V_18 = F_92 (
( sizeof( struct V_10 ) * V_17 ) ,
V_14 ) ;
if ( ! V_2 -> V_18 ) {
F_89 ( V_2 , V_159 , V_428 ,
L_144
L_145 ) ;
goto V_429;
}
F_88 ( & V_2 -> V_16 , 0 ) ;
snprintf ( V_114 , sizeof( V_114 ) , L_146 ) ;
V_2 -> V_450 =
F_91 ( V_114 , V_433 | V_434 | V_435 ,
V_2 -> V_449 ,
V_2 , & V_451 ) ;
if ( ! V_2 -> V_450 ) {
F_89 ( V_2 , V_159 , V_428 ,
L_147
L_148 ) ;
goto V_429;
}
snprintf ( V_114 , sizeof( V_114 ) , L_149 ) ;
V_2 -> V_452 =
F_91 ( V_114 , V_433 | V_434 | V_435 ,
V_2 -> V_449 ,
V_2 , & V_453 ) ;
if ( ! V_2 -> V_452 ) {
F_89 ( V_2 , V_159 , V_428 ,
L_150 ) ;
goto V_429;
}
if ( V_27 -> V_49 < V_437 )
goto V_429;
snprintf ( V_114 , sizeof( V_114 ) , L_151 ) ;
if ( ! V_27 -> V_454 ) {
V_27 -> V_454 =
F_87 ( V_114 , V_27 -> V_430 ) ;
if ( ! V_27 -> V_454 ) {
F_89 ( V_2 , V_159 , V_428 ,
L_152 ) ;
goto V_429;
}
memset ( & V_188 , 0 , sizeof( V_188 ) ) ;
}
snprintf ( V_114 , sizeof( V_114 ) , L_153 ) ;
if ( ! V_27 -> V_455 ) {
V_27 -> V_455 =
F_91 ( V_114 , V_433 | V_434 | V_435 ,
V_27 -> V_454 , V_27 , & V_456 ) ;
if ( ! V_27 -> V_455 ) {
F_89 ( V_2 , V_159 , V_428 ,
L_154 ) ;
goto V_429;
}
V_188 . V_197 . V_218 = 0 ;
}
snprintf ( V_114 , sizeof( V_114 ) , L_155 ) ;
if ( ! V_27 -> V_457 ) {
V_27 -> V_457 =
F_91 ( V_114 , V_433 | V_434 | V_435 ,
V_27 -> V_454 , V_27 , & V_458 ) ;
if ( ! V_27 -> V_457 ) {
F_89 ( V_2 , V_159 , V_428 ,
L_156 ) ;
goto V_429;
}
V_188 . V_197 . V_218 = 0 ;
}
snprintf ( V_114 , sizeof( V_114 ) , L_157 ) ;
if ( ! V_27 -> V_459 ) {
V_27 -> V_459 =
F_91 ( V_114 , V_433 | V_434 ,
V_27 -> V_454 , V_27 , & V_460 ) ;
if ( ! V_27 -> V_459 ) {
F_89 ( V_2 , V_159 , V_428 ,
L_158 ) ;
goto V_429;
}
}
snprintf ( V_114 , sizeof( V_114 ) , L_159 ) ;
if ( ! V_27 -> V_461 ) {
V_27 -> V_461 =
F_91 ( V_114 , V_433 | V_434 | V_435 ,
V_27 -> V_454 , V_27 , & V_462 ) ;
if ( ! V_27 -> V_461 ) {
F_89 ( V_2 , V_159 , V_428 ,
L_160 ) ;
goto V_429;
}
}
snprintf ( V_114 , sizeof( V_114 ) , L_161 ) ;
if ( ! V_27 -> V_463 ) {
V_27 -> V_463 =
F_91 ( V_114 , V_433 | V_434 | V_435 ,
V_27 -> V_454 , V_27 , & V_464 ) ;
if ( ! V_27 -> V_463 ) {
F_89 ( V_2 , V_159 , V_428 ,
L_162 ) ;
goto V_429;
}
}
snprintf ( V_114 , sizeof( V_114 ) , L_163 ) ;
if ( ! V_27 -> V_465 ) {
V_27 -> V_465 =
F_91 ( V_114 , V_433 | V_434 | V_435 ,
V_27 -> V_454 , V_27 , & V_466 ) ;
if ( ! V_27 -> V_465 ) {
F_89 ( V_2 , V_159 , V_428 ,
L_164 ) ;
goto V_429;
}
}
snprintf ( V_114 , sizeof( V_114 ) , L_165 ) ;
if ( ! V_27 -> V_467 ) {
V_27 -> V_467 =
F_91 ( V_114 , V_433 | V_434 | V_435 ,
V_27 -> V_454 , V_27 , & V_468 ) ;
if ( ! V_27 -> V_467 ) {
F_89 ( V_2 , V_159 , V_428 ,
L_166 ) ;
goto V_429;
}
}
if ( V_27 -> V_237 . V_469 ) {
snprintf ( V_114 , sizeof( V_114 ) , L_167 ) ;
if ( ! V_27 -> V_470 ) {
V_27 -> V_470 =
F_91 ( V_114 ,
V_433 | V_434 | V_435 ,
V_27 -> V_454 , V_27 ,
& V_471 ) ;
if ( ! V_27 -> V_470 ) {
F_89 ( V_2 , V_159 , V_428 ,
L_168
L_169 ) ;
goto V_429;
}
}
}
V_429:
return;
#endif
}
inline void
F_93 ( struct V_1 * V_2 )
{
#ifdef F_21
struct V_26 * V_27 = V_2 -> V_27 ;
if ( V_2 -> V_18 ) {
F_5 ( V_2 -> V_18 ) ;
V_2 -> V_18 = NULL ;
}
if ( V_2 -> V_450 ) {
F_94 ( V_2 -> V_450 ) ;
V_2 -> V_450 = NULL ;
}
if ( V_2 -> V_452 ) {
F_94 ( V_2 -> V_452 ) ;
V_2 -> V_452 = NULL ;
}
if ( V_2 -> V_449 ) {
F_94 ( V_2 -> V_449 ) ;
V_2 -> V_449 = NULL ;
F_95 ( & V_27 -> V_431 ) ;
}
if ( F_3 ( & V_27 -> V_431 ) == 0 ) {
if ( V_27 -> V_432 ) {
F_94 ( V_27 -> V_432 ) ;
V_27 -> V_432 = NULL ;
}
if ( V_27 -> V_438 ) {
F_94 ( V_27 -> V_438 ) ;
V_27 -> V_438 = NULL ;
}
if ( V_27 -> V_440 ) {
F_94 ( V_27 -> V_440 ) ;
V_27 -> V_440 = NULL ;
}
if ( V_27 -> V_442 ) {
F_94 ( V_27 -> V_442 ) ;
V_27 -> V_442 = NULL ;
}
if ( V_27 -> V_444 ) {
F_94 ( V_27 -> V_444 ) ;
V_27 -> V_444 = NULL ;
}
if ( V_27 -> V_30 ) {
F_5 ( V_27 -> V_30 ) ;
V_27 -> V_30 = NULL ;
}
if ( V_27 -> V_446 ) {
F_94 ( V_27 -> V_446 ) ;
V_27 -> V_446 = NULL ;
}
if ( V_27 -> V_49 == V_437 ) {
if ( V_27 -> V_470 ) {
F_94 ( V_27 -> V_470 ) ;
V_27 -> V_470 = NULL ;
}
if ( V_27 -> V_467 ) {
F_94 ( V_27 -> V_467 ) ;
V_27 -> V_467 = NULL ;
}
if ( V_27 -> V_465 ) {
F_94 ( V_27 -> V_465 ) ;
V_27 -> V_465 = NULL ;
}
if ( V_27 -> V_463 ) {
F_94 ( V_27 -> V_463 ) ;
V_27 -> V_463 = NULL ;
}
if ( V_27 -> V_461 ) {
F_94 ( V_27 -> V_461 ) ;
V_27 -> V_461 = NULL ;
}
if ( V_27 -> V_459 ) {
F_94 ( V_27 -> V_459 ) ;
V_27 -> V_459 = NULL ;
}
if ( V_27 -> V_457 ) {
F_94 ( V_27 -> V_457 ) ;
V_27 -> V_457 = NULL ;
}
if ( V_27 -> V_455 ) {
F_94 ( V_27 -> V_455 ) ;
V_27 -> V_455 = NULL ;
}
if ( V_27 -> V_454 ) {
F_94 ( V_27 -> V_454 ) ;
V_27 -> V_454 = NULL ;
}
}
if ( V_27 -> V_430 ) {
F_94 ( V_27 -> V_430 ) ;
V_27 -> V_430 = NULL ;
F_95 ( & V_427 ) ;
}
if ( F_3 ( & V_427 ) == 0 ) {
F_94 ( V_426 ) ;
V_426 = NULL ;
}
}
#endif
return;
}
