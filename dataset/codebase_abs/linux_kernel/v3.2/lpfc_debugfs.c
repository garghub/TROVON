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
V_146 -> V_154 = V_145 -> V_147 ;
return 0 ;
}
static T_2
F_37 ( struct V_146 * V_146 , char T_3 * V_3 ,
T_4 V_167 , T_5 * V_168 )
{
struct V_171 * V_172 = V_146 -> V_164 ;
struct V_26 * V_27 = V_146 -> V_154 ;
char V_173 [ 16 ] ;
int V_31 = 0 ;
if ( V_172 == V_27 -> V_174 )
V_31 = snprintf ( V_173 , 16 , L_41 , V_27 -> V_175 ) ;
else if ( V_172 == V_27 -> V_176 )
V_31 = snprintf ( V_173 , 16 , L_41 , V_27 -> V_177 ) ;
else if ( V_172 == V_27 -> V_178 )
V_31 = snprintf ( V_173 , 16 , L_41 , V_27 -> V_179 ) ;
else if ( V_172 == V_27 -> V_180 )
V_31 = snprintf ( V_173 , 16 , L_41 , V_27 -> V_181 ) ;
else if ( V_172 == V_27 -> V_182 )
V_31 = snprintf ( V_173 , 16 , L_41 , V_27 -> V_183 ) ;
else if ( V_172 == V_27 -> V_184 )
V_31 = snprintf ( V_173 , 16 , L_42 ,
( unsigned long ) V_27 -> V_185 ) ;
else
F_38 ( V_27 , V_159 , V_186 ,
L_43 ) ;
return F_39 ( V_3 , V_167 , V_168 , & V_173 , V_31 ) ;
}
static T_2
F_40 ( struct V_146 * V_146 , const char T_3 * V_3 ,
T_4 V_167 , T_5 * V_168 )
{
struct V_171 * V_172 = V_146 -> V_164 ;
struct V_26 * V_27 = V_146 -> V_154 ;
char V_187 [ 32 ] ;
unsigned long V_188 ;
int V_4 ;
memset ( V_187 , 0 , 32 ) ;
V_4 = ( V_167 < 32 ) ? V_167 : 32 ;
if ( F_41 ( V_187 , V_3 , V_4 ) )
return 0 ;
if ( F_42 ( V_187 , 0 , & V_188 ) )
return 0 ;
if ( V_172 == V_27 -> V_174 )
V_27 -> V_175 = ( T_1 ) V_188 ;
else if ( V_172 == V_27 -> V_176 )
V_27 -> V_177 = ( T_1 ) V_188 ;
else if ( V_172 == V_27 -> V_178 )
V_27 -> V_179 = ( T_1 ) V_188 ;
else if ( V_172 == V_27 -> V_180 )
V_27 -> V_181 = ( T_1 ) V_188 ;
else if ( V_172 == V_27 -> V_182 )
V_27 -> V_183 = ( T_1 ) V_188 ;
else if ( V_172 == V_27 -> V_184 )
V_27 -> V_185 = ( V_189 ) V_188 ;
else
F_38 ( V_27 , V_159 , V_186 ,
L_44 ) ;
return V_167 ;
}
static int
F_43 ( struct V_145 * V_145 , struct V_146 * V_146 )
{
return 0 ;
}
static int
F_44 ( struct V_145 * V_145 , struct V_146 * V_146 )
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
F_45 ( struct V_146 * V_146 , T_5 V_76 , int V_190 )
{
struct V_148 * V_149 ;
T_5 V_191 = - 1 ;
V_149 = V_146 -> V_154 ;
switch ( V_190 ) {
case 0 :
V_191 = V_76 ;
break;
case 1 :
V_191 = V_146 -> V_192 + V_76 ;
break;
case 2 :
V_191 = V_149 -> V_7 - V_76 ;
}
return ( V_191 < 0 || V_191 > V_149 -> V_7 ) ? - V_193 : ( V_146 -> V_192 = V_191 ) ;
}
static T_2
F_46 ( struct V_146 * V_146 , char T_3 * V_3 ,
T_4 V_167 , T_5 * V_168 )
{
struct V_148 * V_149 = V_146 -> V_154 ;
return F_39 ( V_3 , V_167 , V_168 , V_149 -> V_12 ,
V_149 -> V_7 ) ;
}
static int
F_47 ( struct V_145 * V_145 , struct V_146 * V_146 )
{
struct V_148 * V_149 = V_146 -> V_154 ;
F_5 ( V_149 -> V_12 ) ;
F_5 ( V_149 ) ;
return 0 ;
}
static int
F_48 ( struct V_145 * V_145 , struct V_146 * V_146 )
{
struct V_148 * V_149 = V_146 -> V_154 ;
V_149 -> V_12 = NULL ;
F_5 ( V_149 ) ;
return 0 ;
}
static int F_49 ( const char T_3 * V_3 , T_4 V_167 ,
struct V_194 * V_195 )
{
char V_196 [ 64 ] ;
char * V_197 , * V_198 ;
int V_5 ;
T_4 V_199 ;
if ( ! F_50 ( V_200 , V_3 , V_167 ) )
return - V_201 ;
memset ( V_196 , 0 , sizeof( V_196 ) ) ;
memset ( V_195 , 0 , sizeof( * V_195 ) ) ;
V_199 = F_51 ( V_167 , ( sizeof( V_196 ) - 1 ) ) ;
if ( F_41 ( V_196 , V_3 , V_199 ) )
return - V_201 ;
V_197 = & V_196 [ 0 ] ;
V_198 = F_52 ( & V_197 , L_45 ) ;
if ( ! V_198 )
return - V_193 ;
V_195 -> V_202 = F_53 ( V_198 , NULL , 0 ) ;
if ( V_195 -> V_202 == 0 )
return - V_193 ;
for ( V_5 = 0 ; V_5 < V_203 ; V_5 ++ ) {
V_198 = F_52 ( & V_197 , L_45 ) ;
if ( ! V_198 )
return V_5 ;
V_195 -> V_204 [ V_5 ] = F_53 ( V_198 , NULL , 0 ) ;
}
return V_5 ;
}
static int
F_54 ( struct V_145 * V_145 , struct V_146 * V_146 )
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
F_55 ( struct V_145 * V_145 , struct V_146 * V_146 )
{
struct V_148 * V_149 = V_146 -> V_154 ;
F_5 ( V_149 -> V_12 ) ;
F_5 ( V_149 ) ;
return 0 ;
}
static int
F_56 ( struct V_145 * V_145 , struct V_146 * V_146 )
{
struct V_148 * V_149 = V_146 -> V_154 ;
if ( V_149 -> V_205 == V_206 ) {
switch ( V_207 . V_208 . V_202 ) {
case V_209 :
case V_210 :
case V_211 :
case V_212 :
case V_213 :
case V_214 :
memset ( & V_207 , 0 , sizeof( V_207 ) ) ;
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
F_57 ( struct V_146 * V_146 , char T_3 * V_3 , T_4 V_167 ,
T_5 * V_168 )
{
struct V_148 * V_149 = V_146 -> V_154 ;
struct V_26 * V_27 = (struct V_26 * ) V_149 -> V_147 ;
int V_215 , V_216 , V_7 = 0 , V_6 = V_217 ;
int V_218 , V_219 ;
char * V_220 ;
struct V_221 * V_222 ;
T_1 V_223 ;
T_6 V_224 ;
T_7 V_225 ;
V_222 = V_27 -> V_226 ;
if ( ! V_222 )
return 0 ;
V_149 -> V_205 = V_227 ;
if ( ! V_149 -> V_12 )
V_149 -> V_12 = F_2 ( V_228 , V_14 ) ;
if ( ! V_149 -> V_12 )
return 0 ;
V_220 = V_149 -> V_12 ;
if ( * V_168 )
return 0 ;
if ( V_207 . V_208 . V_202 == V_229 ) {
V_218 = V_207 . V_208 . V_204 [ V_230 ] ;
V_219 = V_207 . V_208 . V_204 [ V_231 ] ;
} else
return 0 ;
switch ( V_219 ) {
case V_232 :
F_58 ( V_222 , V_218 , & V_225 ) ;
V_7 += snprintf ( V_220 + V_7 , V_228 - V_7 ,
L_46 , V_218 , V_225 ) ;
break;
case V_233 :
F_59 ( V_222 , V_218 , & V_224 ) ;
V_7 += snprintf ( V_220 + V_7 , V_228 - V_7 ,
L_47 , V_218 , V_224 ) ;
break;
case V_234 :
F_60 ( V_222 , V_218 , & V_223 ) ;
V_7 += snprintf ( V_220 + V_7 , V_228 - V_7 ,
L_48 , V_218 , V_223 ) ;
break;
case V_235 :
goto V_236;
break;
default:
V_7 = 0 ;
break;
}
return F_39 ( V_3 , V_167 , V_168 , V_220 , V_7 ) ;
V_236:
V_215 = V_207 . V_216 . V_237 ;
V_216 = V_215 ;
V_7 += snprintf ( V_220 + V_7 , V_228 - V_7 ,
L_49 , V_215 ) ;
while ( V_6 > 0 ) {
F_60 ( V_222 , V_216 , & V_223 ) ;
V_7 += snprintf ( V_220 + V_7 , V_228 - V_7 ,
L_50 , V_223 ) ;
V_216 += sizeof( T_1 ) ;
if ( V_216 >= V_228 ) {
V_7 += snprintf ( V_220 + V_7 ,
V_228 - V_7 , L_38 ) ;
break;
}
V_6 -= sizeof( T_1 ) ;
if ( ! V_6 )
V_7 += snprintf ( V_220 + V_7 , V_228 - V_7 ,
L_38 ) ;
else if ( ! ( V_6 % ( 8 * sizeof( T_1 ) ) ) ) {
V_215 += ( 8 * sizeof( T_1 ) ) ;
V_7 += snprintf ( V_220 + V_7 , V_228 - V_7 ,
L_51 , V_215 ) ;
}
}
if ( V_6 == 0 ) {
V_207 . V_216 . V_237 += V_217 ;
if ( V_207 . V_216 . V_237 >= V_228 )
V_207 . V_216 . V_237 = 0 ;
} else
V_207 . V_216 . V_237 = 0 ;
return F_39 ( V_3 , V_167 , V_168 , V_220 , V_7 ) ;
}
static T_2
F_61 ( struct V_146 * V_146 , const char T_3 * V_3 ,
T_4 V_167 , T_5 * V_168 )
{
struct V_148 * V_149 = V_146 -> V_154 ;
struct V_26 * V_27 = (struct V_26 * ) V_149 -> V_147 ;
T_1 V_218 , V_238 , V_219 ;
T_1 V_223 ;
T_6 V_224 ;
T_7 V_225 ;
struct V_221 * V_222 ;
int V_150 ;
V_222 = V_27 -> V_226 ;
if ( ! V_222 )
return - V_201 ;
V_149 -> V_205 = V_206 ;
V_150 = F_49 ( V_3 , V_167 , & V_207 . V_208 ) ;
if ( V_150 < 0 )
return V_150 ;
if ( V_207 . V_208 . V_202 == V_229 ) {
if ( V_150 != V_239 )
goto V_240;
V_218 = V_207 . V_208 . V_204 [ V_230 ] ;
V_219 = V_207 . V_208 . V_204 [ V_231 ] ;
if ( V_219 == V_235 ) {
if ( V_218 % sizeof( T_1 ) )
goto V_240;
V_207 . V_216 . V_237 = V_218 ;
} else if ( ( V_219 != sizeof( T_7 ) ) &&
( V_219 != sizeof( T_6 ) ) &&
( V_219 != sizeof( T_1 ) ) )
goto V_240;
if ( V_219 == sizeof( T_7 ) ) {
if ( V_218 > V_228 - sizeof( T_7 ) )
goto V_240;
if ( V_218 % sizeof( T_7 ) )
goto V_240;
}
if ( V_219 == sizeof( T_6 ) ) {
if ( V_218 > V_228 - sizeof( T_6 ) )
goto V_240;
if ( V_218 % sizeof( T_6 ) )
goto V_240;
}
if ( V_219 == sizeof( T_1 ) ) {
if ( V_218 > V_228 - sizeof( T_1 ) )
goto V_240;
if ( V_218 % sizeof( T_1 ) )
goto V_240;
}
} else if ( V_207 . V_208 . V_202 == V_209 ||
V_207 . V_208 . V_202 == V_210 ||
V_207 . V_208 . V_202 == V_211 ) {
if ( V_150 != V_241 )
goto V_240;
V_218 = V_207 . V_208 . V_204 [ V_230 ] ;
V_219 = V_207 . V_208 . V_204 [ V_231 ] ;
V_238 = V_207 . V_208 . V_204 [ V_242 ] ;
if ( ( V_219 != sizeof( T_7 ) ) &&
( V_219 != sizeof( T_6 ) ) &&
( V_219 != sizeof( T_1 ) ) )
goto V_240;
if ( V_219 == sizeof( T_7 ) ) {
if ( V_218 > V_228 - sizeof( T_7 ) )
goto V_240;
if ( V_218 % sizeof( T_7 ) )
goto V_240;
if ( V_207 . V_208 . V_202 == V_209 )
F_62 ( V_222 , V_218 ,
( T_7 ) V_238 ) ;
if ( V_207 . V_208 . V_202 == V_210 ) {
V_150 = F_58 ( V_222 , V_218 , & V_225 ) ;
if ( ! V_150 ) {
V_225 |= ( T_7 ) V_238 ;
F_62 ( V_222 , V_218 ,
V_225 ) ;
}
}
if ( V_207 . V_208 . V_202 == V_211 ) {
V_150 = F_58 ( V_222 , V_218 , & V_225 ) ;
if ( ! V_150 ) {
V_225 &= ( T_7 ) ( ~ V_238 ) ;
F_62 ( V_222 , V_218 ,
V_225 ) ;
}
}
}
if ( V_219 == sizeof( T_6 ) ) {
if ( V_218 > V_228 - sizeof( T_6 ) )
goto V_240;
if ( V_218 % sizeof( T_6 ) )
goto V_240;
if ( V_207 . V_208 . V_202 == V_209 )
F_63 ( V_222 , V_218 ,
( T_6 ) V_238 ) ;
if ( V_207 . V_208 . V_202 == V_210 ) {
V_150 = F_59 ( V_222 , V_218 , & V_224 ) ;
if ( ! V_150 ) {
V_224 |= ( T_6 ) V_238 ;
F_63 ( V_222 , V_218 ,
V_224 ) ;
}
}
if ( V_207 . V_208 . V_202 == V_211 ) {
V_150 = F_59 ( V_222 , V_218 , & V_224 ) ;
if ( ! V_150 ) {
V_224 &= ( T_6 ) ( ~ V_238 ) ;
F_63 ( V_222 , V_218 ,
V_224 ) ;
}
}
}
if ( V_219 == sizeof( T_1 ) ) {
if ( V_218 > V_228 - sizeof( T_1 ) )
goto V_240;
if ( V_218 % sizeof( T_1 ) )
goto V_240;
if ( V_207 . V_208 . V_202 == V_209 )
F_64 ( V_222 , V_218 , V_238 ) ;
if ( V_207 . V_208 . V_202 == V_210 ) {
V_150 = F_60 ( V_222 , V_218 ,
& V_223 ) ;
if ( ! V_150 ) {
V_223 |= V_238 ;
F_64 ( V_222 , V_218 ,
V_223 ) ;
}
}
if ( V_207 . V_208 . V_202 == V_211 ) {
V_150 = F_60 ( V_222 , V_218 ,
& V_223 ) ;
if ( ! V_150 ) {
V_223 &= ~ V_238 ;
F_64 ( V_222 , V_218 ,
V_223 ) ;
}
}
}
} else
goto V_240;
return V_167 ;
V_240:
memset ( & V_207 , 0 , sizeof( V_207 ) ) ;
return - V_193 ;
}
static T_2
F_65 ( struct V_146 * V_146 , char T_3 * V_3 , T_4 V_167 ,
T_5 * V_168 )
{
struct V_148 * V_149 = V_146 -> V_154 ;
struct V_26 * V_27 = (struct V_26 * ) V_149 -> V_147 ;
int V_215 , V_216 , V_243 , V_7 = 0 , V_6 ;
int V_244 , V_245 , V_246 ;
char * V_220 ;
void T_8 * V_247 ;
T_1 V_248 ;
struct V_221 * V_222 ;
T_1 V_223 ;
V_222 = V_27 -> V_226 ;
if ( ! V_222 )
return 0 ;
V_149 -> V_205 = V_227 ;
if ( ! V_149 -> V_12 )
V_149 -> V_12 = F_2 ( V_249 , V_14 ) ;
if ( ! V_149 -> V_12 )
return 0 ;
V_220 = V_149 -> V_12 ;
if ( * V_168 )
return 0 ;
if ( V_207 . V_208 . V_202 == V_250 ) {
V_244 = V_207 . V_208 . V_204 [ V_251 ] ;
V_216 = V_207 . V_208 . V_204 [ V_252 ] ;
V_245 = V_207 . V_208 . V_204 [ V_253 ] ;
V_246 = V_207 . V_208 . V_204 [ V_254 ] ;
} else
return 0 ;
if ( V_245 == 0 )
return 0 ;
V_248 = F_66 ( V_255 , & V_27 -> V_256 . V_257 ) ;
if ( V_248 == V_258 ) {
if ( V_244 == V_259 )
V_247 = V_27 -> V_256 . V_260 ;
else if ( V_244 == V_261 )
V_247 = V_27 -> V_256 . V_262 ;
else if ( V_244 == V_263 )
V_247 = V_27 -> V_256 . V_264 ;
else
return 0 ;
} else if ( V_248 == V_265 ) {
if ( V_244 == V_259 )
V_247 = V_27 -> V_256 . V_260 ;
else
return 0 ;
} else
return 0 ;
if ( V_245 == V_266 ) {
V_243 = V_216 ;
V_223 = F_17 ( V_247 + V_243 ) ;
V_7 += snprintf ( V_220 + V_7 , V_249 - V_7 ,
L_52 , V_243 , V_223 ) ;
} else
goto V_267;
return F_39 ( V_3 , V_167 , V_168 , V_220 , V_7 ) ;
V_267:
V_215 = V_207 . V_216 . V_237 ;
V_243 = V_215 ;
V_7 += snprintf ( V_220 + V_7 , V_249 - V_7 ,
L_53 , V_215 ) ;
V_6 = V_268 ;
while ( V_6 > 0 ) {
V_223 = F_17 ( V_247 + V_243 ) ;
V_7 += snprintf ( V_220 + V_7 , V_249 - V_7 ,
L_50 , V_223 ) ;
V_243 += sizeof( T_1 ) ;
if ( V_245 == V_269 ) {
if ( V_243 >= V_246 ) {
V_7 += snprintf ( V_220 + V_7 ,
V_249 - V_7 , L_38 ) ;
break;
}
} else {
if ( V_243 >= V_216 +
( V_245 * sizeof( T_1 ) ) ) {
V_7 += snprintf ( V_220 + V_7 ,
V_249 - V_7 , L_38 ) ;
break;
}
}
V_6 -= sizeof( T_1 ) ;
if ( ! V_6 )
V_7 += snprintf ( V_220 + V_7 ,
V_249 - V_7 , L_38 ) ;
else if ( ! ( V_6 % ( 8 * sizeof( T_1 ) ) ) ) {
V_215 += ( 8 * sizeof( T_1 ) ) ;
V_7 += snprintf ( V_220 + V_7 ,
V_249 - V_7 ,
L_54 , V_215 ) ;
}
}
if ( V_6 == 0 ) {
V_207 . V_216 . V_237 += V_268 ;
if ( V_245 == V_269 ) {
if ( V_207 . V_216 . V_237 >= V_246 )
V_207 . V_216 . V_237 = 0 ;
} else {
if ( V_243 >= V_216 +
( V_245 * sizeof( T_1 ) ) )
V_207 . V_216 . V_237 = V_216 ;
}
} else {
if ( V_245 == V_269 )
V_207 . V_216 . V_237 = 0 ;
else
V_207 . V_216 . V_237 = V_216 ;
}
return F_39 ( V_3 , V_167 , V_168 , V_220 , V_7 ) ;
}
static T_2
F_67 ( struct V_146 * V_146 , const char T_3 * V_3 ,
T_4 V_167 , T_5 * V_168 )
{
struct V_148 * V_149 = V_146 -> V_154 ;
struct V_26 * V_27 = (struct V_26 * ) V_149 -> V_147 ;
T_1 V_244 , V_246 , V_216 , V_238 , V_245 ;
struct V_221 * V_222 ;
void T_8 * V_247 ;
T_1 V_248 ;
T_1 V_223 ;
int V_150 ;
V_222 = V_27 -> V_226 ;
if ( ! V_222 )
return - V_201 ;
V_149 -> V_205 = V_206 ;
V_150 = F_49 ( V_3 , V_167 , & V_207 . V_208 ) ;
if ( V_150 < 0 )
return V_150 ;
V_248 = F_66 ( V_255 , & V_27 -> V_256 . V_257 ) ;
V_244 = V_207 . V_208 . V_204 [ V_251 ] ;
if ( V_248 == V_258 ) {
if ( ( V_244 != V_259 ) &&
( V_244 != V_261 ) &&
( V_244 != V_263 ) )
goto V_240;
} else if ( V_248 == V_265 ) {
if ( V_244 != V_259 )
goto V_240;
} else
goto V_240;
if ( V_248 == V_258 ) {
if ( V_244 == V_259 ) {
V_207 . V_208 . V_204 [ V_254 ] =
V_270 ;
V_247 = V_27 -> V_256 . V_260 ;
} else if ( V_244 == V_261 ) {
V_207 . V_208 . V_204 [ V_254 ] =
V_271 ;
V_247 = V_27 -> V_256 . V_262 ;
} else if ( V_244 == V_263 ) {
V_207 . V_208 . V_204 [ V_254 ] =
V_272 ;
V_247 = V_27 -> V_256 . V_264 ;
} else
goto V_240;
} else if ( V_248 == V_265 ) {
if ( V_244 == V_259 ) {
V_207 . V_208 . V_204 [ V_254 ] =
V_273 ;
V_247 = V_27 -> V_256 . V_260 ;
} else
goto V_240;
} else
goto V_240;
V_216 = V_207 . V_208 . V_204 [ V_252 ] ;
if ( V_216 % sizeof( T_1 ) )
goto V_240;
V_246 = V_207 . V_208 . V_204 [ V_254 ] ;
if ( V_207 . V_208 . V_202 == V_250 ) {
if ( V_150 != V_274 )
goto V_240;
V_245 = V_207 . V_208 . V_204 [ V_253 ] ;
if ( V_245 == V_269 ) {
if ( V_216 > V_246 - sizeof( T_1 ) )
goto V_240;
V_207 . V_216 . V_237 = V_216 ;
} else if ( V_245 > V_266 ) {
if ( V_216 + V_245 * sizeof( T_1 ) > V_246 )
goto V_240;
V_207 . V_216 . V_237 = V_216 ;
} else if ( V_245 != V_266 )
goto V_240;
} else if ( V_207 . V_208 . V_202 == V_275 ||
V_207 . V_208 . V_202 == V_276 ||
V_207 . V_208 . V_202 == V_277 ) {
if ( V_150 != V_278 )
goto V_240;
V_245 = V_266 ;
V_238 = V_207 . V_208 . V_204 [ V_279 ] ;
if ( V_207 . V_208 . V_202 == V_275 ) {
F_68 ( V_238 , V_247 + V_216 ) ;
F_17 ( V_247 + V_216 ) ;
}
if ( V_207 . V_208 . V_202 == V_276 ) {
V_223 = F_17 ( V_247 + V_216 ) ;
V_223 |= V_238 ;
F_68 ( V_223 , V_247 + V_216 ) ;
F_17 ( V_247 + V_216 ) ;
}
if ( V_207 . V_208 . V_202 == V_277 ) {
V_223 = F_17 ( V_247 + V_216 ) ;
V_223 &= ~ V_238 ;
F_68 ( V_223 , V_247 + V_216 ) ;
F_17 ( V_247 + V_216 ) ;
}
} else
goto V_240;
return V_167 ;
V_240:
memset ( & V_207 , 0 , sizeof( V_207 ) ) ;
return - V_193 ;
}
static T_2
F_69 ( struct V_146 * V_146 , char T_3 * V_3 , T_4 V_167 ,
T_5 * V_168 )
{
struct V_148 * V_149 = V_146 -> V_154 ;
struct V_26 * V_27 = (struct V_26 * ) V_149 -> V_147 ;
int V_7 = 0 , V_280 ;
char * V_220 ;
if ( ! V_149 -> V_12 )
V_149 -> V_12 = F_2 ( V_281 , V_14 ) ;
if ( ! V_149 -> V_12 )
return 0 ;
V_220 = V_149 -> V_12 ;
if ( * V_168 )
return 0 ;
V_7 += snprintf ( V_220 + V_7 , V_281 - V_7 ,
L_55 ) ;
V_7 += snprintf ( V_220 + V_7 , V_281 - V_7 ,
L_56
L_57
L_58 ,
V_27 -> V_256 . V_282 -> V_283 ,
V_27 -> V_256 . V_282 -> V_61 ,
V_27 -> V_256 . V_282 -> V_284 ,
V_27 -> V_256 . V_282 -> V_285 ,
V_27 -> V_256 . V_282 -> V_286 ) ;
V_7 += snprintf ( V_220 + V_7 , V_281 - V_7 ,
L_59 ) ;
for ( V_280 = 0 ; V_280 < V_27 -> V_287 ; V_280 ++ ) {
V_7 += snprintf ( V_220 + V_7 , V_281 - V_7 ,
L_56
L_57
L_60 ,
V_27 -> V_256 . V_288 [ V_280 ] -> V_283 ,
V_27 -> V_256 . V_288 [ V_280 ] -> V_61 ,
V_27 -> V_256 . V_288 [ V_280 ] -> V_284 ,
V_27 -> V_256 . V_288 [ V_280 ] -> V_285 ,
V_27 -> V_256 . V_288 [ V_280 ] -> V_286 ) ;
}
V_7 += snprintf ( V_220 + V_7 , V_281 - V_7 , L_38 ) ;
V_7 += snprintf ( V_220 + V_7 , V_281 - V_7 ,
L_61 ) ;
V_7 += snprintf ( V_220 + V_7 , V_281 - V_7 ,
L_62 ,
V_27 -> V_256 . V_289 -> V_290 ) ;
V_7 += snprintf ( V_220 + V_7 , V_281 - V_7 ,
L_63
L_57
L_58 ,
V_27 -> V_256 . V_289 -> V_283 ,
V_27 -> V_256 . V_289 -> V_61 ,
V_27 -> V_256 . V_289 -> V_284 ,
V_27 -> V_256 . V_289 -> V_285 ,
V_27 -> V_256 . V_289 -> V_286 ) ;
V_7 += snprintf ( V_220 + V_7 , V_281 - V_7 ,
L_64 ) ;
V_7 += snprintf ( V_220 + V_7 , V_281 - V_7 ,
L_62 ,
V_27 -> V_256 . V_291 -> V_290 ) ;
V_7 += snprintf ( V_220 + V_7 , V_281 - V_7 ,
L_65
L_57
L_58 ,
V_27 -> V_256 . V_291 -> V_283 ,
V_27 -> V_256 . V_291 -> V_61 ,
V_27 -> V_256 . V_291 -> V_284 ,
V_27 -> V_256 . V_291 -> V_285 ,
V_27 -> V_256 . V_291 -> V_286 ) ;
V_7 += snprintf ( V_220 + V_7 , V_281 - V_7 ,
L_66 ) ;
V_280 = 0 ;
do {
V_7 += snprintf ( V_220 + V_7 , V_281 - V_7 ,
L_62 ,
V_27 -> V_256 . V_292 [ V_280 ] -> V_290 ) ;
V_7 += snprintf ( V_220 + V_7 , V_281 - V_7 ,
L_63
L_57
L_60 ,
V_27 -> V_256 . V_292 [ V_280 ] -> V_283 ,
V_27 -> V_256 . V_292 [ V_280 ] -> V_61 ,
V_27 -> V_256 . V_292 [ V_280 ] -> V_284 ,
V_27 -> V_256 . V_292 [ V_280 ] -> V_285 ,
V_27 -> V_256 . V_292 [ V_280 ] -> V_286 ) ;
} while ( ++ V_280 < V_27 -> V_287 );
V_7 += snprintf ( V_220 + V_7 , V_281 - V_7 , L_38 ) ;
V_7 += snprintf ( V_220 + V_7 , V_281 - V_7 ,
L_67 ) ;
V_7 += snprintf ( V_220 + V_7 , V_281 - V_7 ,
L_68 ,
V_27 -> V_256 . V_293 -> V_290 ) ;
V_7 += snprintf ( V_220 + V_7 , V_281 - V_7 ,
L_69
L_57
L_58 ,
V_27 -> V_256 . V_293 -> V_283 ,
V_27 -> V_256 . V_293 -> V_61 ,
V_27 -> V_256 . V_293 -> V_284 ,
V_27 -> V_256 . V_293 -> V_285 ,
V_27 -> V_256 . V_293 -> V_286 ) ;
V_7 += snprintf ( V_220 + V_7 , V_281 - V_7 ,
L_70 ) ;
V_7 += snprintf ( V_220 + V_7 , V_281 - V_7 ,
L_68 ,
V_27 -> V_256 . V_294 -> V_290 ) ;
V_7 += snprintf ( V_220 + V_7 , V_281 - V_7 ,
L_69
L_57
L_58 ,
V_27 -> V_256 . V_294 -> V_283 ,
V_27 -> V_256 . V_294 -> V_61 ,
V_27 -> V_256 . V_294 -> V_284 ,
V_27 -> V_256 . V_294 -> V_285 ,
V_27 -> V_256 . V_294 -> V_286 ) ;
V_7 += snprintf ( V_220 + V_7 , V_281 - V_7 ,
L_71 ) ;
for ( V_280 = 0 ; V_280 < V_27 -> V_295 ; V_280 ++ ) {
V_7 += snprintf ( V_220 + V_7 , V_281 - V_7 ,
L_68 ,
V_27 -> V_256 . V_296 [ V_280 ] -> V_290 ) ;
V_7 += snprintf ( V_220 + V_7 , V_281 - V_7 ,
L_69
L_72
L_60 ,
V_27 -> V_256 . V_296 [ V_280 ] -> V_283 ,
V_27 -> V_256 . V_296 [ V_280 ] -> V_61 ,
V_27 -> V_256 . V_296 [ V_280 ] -> V_284 ,
V_27 -> V_256 . V_296 [ V_280 ] -> V_285 ,
V_27 -> V_256 . V_296 [ V_280 ] -> V_286 ) ;
}
V_7 += snprintf ( V_220 + V_7 , V_281 - V_7 , L_38 ) ;
V_7 += snprintf ( V_220 + V_7 , V_281 - V_7 ,
L_73 ) ;
V_7 += snprintf ( V_220 + V_7 , V_281 - V_7 ,
L_68 ,
V_27 -> V_256 . V_297 -> V_290 ) ;
V_7 += snprintf ( V_220 + V_7 , V_281 - V_7 ,
L_74
L_57
L_60 ,
V_27 -> V_256 . V_297 -> V_283 ,
V_27 -> V_256 . V_297 -> V_61 ,
V_27 -> V_256 . V_297 -> V_284 ,
V_27 -> V_256 . V_297 -> V_285 ,
V_27 -> V_256 . V_297 -> V_286 ) ;
V_7 += snprintf ( V_220 + V_7 , V_281 - V_7 ,
L_75
L_57
L_60 ,
V_27 -> V_256 . V_298 -> V_283 ,
V_27 -> V_256 . V_298 -> V_61 ,
V_27 -> V_256 . V_298 -> V_284 ,
V_27 -> V_256 . V_298 -> V_285 ,
V_27 -> V_256 . V_298 -> V_286 ) ;
return F_39 ( V_3 , V_167 , V_168 , V_220 , V_7 ) ;
}
static int
F_70 ( struct V_299 * V_300 , int V_6 , int V_219 )
{
if ( ( V_219 != 1 ) && ( V_219 != V_301 ) )
return - V_193 ;
if ( V_6 > V_300 -> V_61 - 1 )
return - V_193 ;
return 0 ;
}
static int
F_71 ( char * V_220 , int V_7 , struct V_299 * V_302 ,
T_1 V_6 )
{
int V_216 , V_303 ;
T_1 * V_304 ;
if ( ! V_220 || ! V_302 )
return 0 ;
V_303 = V_302 -> V_284 ;
V_7 += snprintf ( V_220 + V_7 , V_305 - V_7 ,
L_76 , V_6 ) ;
V_216 = 0 ;
V_304 = V_302 -> V_306 [ V_6 ] . V_307 ;
while ( V_303 > 0 ) {
V_7 += snprintf ( V_220 + V_7 , V_305 - V_7 ,
L_50 , * V_304 ) ;
V_304 ++ ;
V_216 += sizeof( T_1 ) ;
V_303 -= sizeof( T_1 ) ;
if ( V_303 > 0 && ! ( V_216 % ( 4 * sizeof( T_1 ) ) ) )
V_7 += snprintf ( V_220 + V_7 ,
V_305 - V_7 , L_38 ) ;
}
V_7 += snprintf ( V_220 + V_7 , V_305 - V_7 , L_38 ) ;
return V_7 ;
}
static T_2
F_72 ( struct V_146 * V_146 , char T_3 * V_3 , T_4 V_167 ,
T_5 * V_168 )
{
struct V_148 * V_149 = V_146 -> V_154 ;
T_1 V_308 , V_6 , V_219 ;
struct V_299 * V_302 = NULL ;
char * V_220 ;
int V_7 = 0 ;
V_149 -> V_205 = V_227 ;
if ( ! V_149 -> V_12 )
V_149 -> V_12 = F_2 ( V_305 , V_14 ) ;
if ( ! V_149 -> V_12 )
return 0 ;
V_220 = V_149 -> V_12 ;
if ( * V_168 )
return 0 ;
if ( V_207 . V_208 . V_202 == V_309 ) {
V_6 = V_207 . V_208 . V_204 [ V_310 ] ;
V_219 = V_207 . V_208 . V_204 [ V_311 ] ;
V_302 = (struct V_299 * ) V_207 . V_312 ;
} else
return 0 ;
if ( V_219 == V_301 )
goto V_313;
V_7 = F_71 ( V_220 , V_7 , V_302 , V_6 ) ;
return F_39 ( V_3 , V_167 , V_168 , V_220 , V_7 ) ;
V_313:
V_308 = V_207 . V_216 . V_237 ;
V_6 = V_308 ;
while ( V_7 < V_314 - V_302 -> V_284 ) {
V_7 = F_71 ( V_220 , V_7 , V_302 , V_6 ) ;
V_6 ++ ;
if ( V_6 > V_302 -> V_61 - 1 )
break;
}
if ( V_6 > V_302 -> V_61 - 1 )
V_6 = 0 ;
V_207 . V_216 . V_237 = V_6 ;
return F_39 ( V_3 , V_167 , V_168 , V_220 , V_7 ) ;
}
static T_2
F_73 ( struct V_146 * V_146 , const char T_3 * V_3 ,
T_4 V_167 , T_5 * V_168 )
{
struct V_148 * V_149 = V_146 -> V_154 ;
struct V_26 * V_27 = (struct V_26 * ) V_149 -> V_147 ;
T_1 V_315 , V_316 , V_317 , V_6 , V_219 , V_216 , V_238 ;
T_1 * V_304 ;
struct V_299 * V_302 ;
int V_150 ;
V_149 -> V_205 = V_206 ;
V_150 = F_49 ( V_3 , V_167 , & V_207 . V_208 ) ;
if ( V_150 < 0 )
return V_150 ;
V_316 = V_207 . V_208 . V_204 [ V_318 ] ;
V_317 = V_207 . V_208 . V_204 [ V_319 ] ;
V_6 = V_207 . V_208 . V_204 [ V_310 ] ;
V_219 = V_207 . V_208 . V_204 [ V_311 ] ;
V_216 = V_207 . V_208 . V_204 [ V_320 ] ;
V_238 = V_207 . V_208 . V_204 [ V_321 ] ;
if ( V_207 . V_208 . V_202 == V_212 ||
V_207 . V_208 . V_202 == V_213 ||
V_207 . V_208 . V_202 == V_214 ) {
if ( V_150 != V_322 )
goto V_240;
if ( V_219 != 1 )
goto V_240;
} else if ( V_207 . V_208 . V_202 == V_309 ) {
if ( V_150 != V_323 )
goto V_240;
} else
goto V_240;
switch ( V_316 ) {
case V_324 :
if ( V_27 -> V_256 . V_282 -> V_283 == V_317 ) {
V_150 = F_70 (
V_27 -> V_256 . V_282 , V_6 , V_219 ) ;
if ( V_150 )
goto V_240;
V_207 . V_312 = V_27 -> V_256 . V_282 ;
goto V_325;
}
for ( V_315 = 0 ; V_315 < V_27 -> V_287 ; V_315 ++ ) {
if ( V_27 -> V_256 . V_288 [ V_315 ] -> V_283 == V_317 ) {
V_150 = F_70 (
V_27 -> V_256 . V_288 [ V_315 ] ,
V_6 , V_219 ) ;
if ( V_150 )
goto V_240;
V_207 . V_312 = V_27 -> V_256 . V_288 [ V_315 ] ;
goto V_325;
}
}
goto V_240;
break;
case V_326 :
if ( V_27 -> V_256 . V_289 -> V_283 == V_317 ) {
V_150 = F_70 (
V_27 -> V_256 . V_289 , V_6 , V_219 ) ;
if ( V_150 )
goto V_240;
V_207 . V_312 = V_27 -> V_256 . V_289 ;
goto V_325;
}
if ( V_27 -> V_256 . V_291 -> V_283 == V_317 ) {
V_150 = F_70 (
V_27 -> V_256 . V_291 , V_6 , V_219 ) ;
if ( V_150 )
goto V_240;
V_207 . V_312 = V_27 -> V_256 . V_291 ;
goto V_325;
}
V_315 = 0 ;
do {
if ( V_27 -> V_256 . V_292 [ V_315 ] -> V_283 == V_317 ) {
V_150 = F_70 (
V_27 -> V_256 . V_292 [ V_315 ] ,
V_6 , V_219 ) ;
if ( V_150 )
goto V_240;
V_207 . V_312 =
V_27 -> V_256 . V_292 [ V_315 ] ;
goto V_325;
}
} while ( ++ V_315 < V_27 -> V_287 );
goto V_240;
break;
case V_327 :
if ( V_27 -> V_256 . V_293 -> V_283 == V_317 ) {
V_150 = F_70 (
V_27 -> V_256 . V_293 , V_6 , V_219 ) ;
if ( V_150 )
goto V_240;
V_207 . V_312 = V_27 -> V_256 . V_293 ;
goto V_325;
}
break;
case V_328 :
if ( V_27 -> V_256 . V_294 -> V_283 == V_317 ) {
V_150 = F_70 (
V_27 -> V_256 . V_294 , V_6 , V_219 ) ;
if ( V_150 )
goto V_240;
V_207 . V_312 = V_27 -> V_256 . V_294 ;
goto V_325;
}
for ( V_315 = 0 ; V_315 < V_27 -> V_295 ; V_315 ++ ) {
if ( V_27 -> V_256 . V_296 [ V_315 ] -> V_283 == V_317 ) {
V_150 = F_70 (
V_27 -> V_256 . V_296 [ V_315 ] ,
V_6 , V_219 ) ;
if ( V_150 )
goto V_240;
V_207 . V_312 =
V_27 -> V_256 . V_296 [ V_315 ] ;
goto V_325;
}
}
goto V_240;
break;
case V_329 :
if ( V_27 -> V_256 . V_297 -> V_283 == V_317 ) {
V_150 = F_70 (
V_27 -> V_256 . V_297 , V_6 , V_219 ) ;
if ( V_150 )
goto V_240;
V_207 . V_312 = V_27 -> V_256 . V_297 ;
goto V_325;
}
if ( V_27 -> V_256 . V_298 -> V_283 == V_317 ) {
V_150 = F_70 (
V_27 -> V_256 . V_298 , V_6 , V_219 ) ;
if ( V_150 )
goto V_240;
V_207 . V_312 = V_27 -> V_256 . V_298 ;
goto V_325;
}
goto V_240;
break;
default:
goto V_240;
break;
}
V_325:
if ( V_207 . V_208 . V_202 == V_309 ) {
if ( V_219 == V_301 )
V_207 . V_216 . V_237 = V_6 ;
}
if ( V_207 . V_208 . V_202 == V_212 ||
V_207 . V_208 . V_202 == V_213 ||
V_207 . V_208 . V_202 == V_214 ) {
V_302 = (struct V_299 * ) V_207 . V_312 ;
if ( V_216 > V_302 -> V_284 / sizeof( T_1 ) - 1 )
goto V_240;
V_304 = V_302 -> V_306 [ V_6 ] . V_307 ;
V_304 += V_216 ;
if ( V_207 . V_208 . V_202 == V_212 )
* V_304 = V_238 ;
if ( V_207 . V_208 . V_202 == V_213 )
* V_304 |= V_238 ;
if ( V_207 . V_208 . V_202 == V_214 )
* V_304 &= ~ V_238 ;
}
return V_167 ;
V_240:
memset ( & V_207 , 0 , sizeof( V_207 ) ) ;
return - V_193 ;
}
static int
F_74 ( struct V_26 * V_27 , char * V_220 ,
int V_7 , T_1 V_330 )
{
if ( ! V_220 )
return 0 ;
switch ( V_330 ) {
case V_331 :
V_7 += snprintf ( V_220 + V_7 , V_332 - V_7 ,
L_77 ,
F_17 ( V_27 -> V_256 . V_333 ) ) ;
break;
case V_334 :
V_7 += snprintf ( V_220 + V_7 , V_332 - V_7 ,
L_78 ,
F_17 ( V_27 -> V_256 . V_335 ) ) ;
break;
case V_336 :
V_7 += snprintf ( V_220 + V_7 , V_332 - V_7 ,
L_79 ,
F_17 ( V_27 -> V_256 . V_337 ) ) ;
break;
case V_338 :
V_7 += snprintf ( V_220 + V_7 , V_332 - V_7 ,
L_80 ,
F_17 ( V_27 -> V_256 . V_339 ) ) ;
break;
default:
break;
}
return V_7 ;
}
static T_2
F_75 ( struct V_146 * V_146 , char T_3 * V_3 , T_4 V_167 ,
T_5 * V_168 )
{
struct V_148 * V_149 = V_146 -> V_154 ;
struct V_26 * V_27 = (struct V_26 * ) V_149 -> V_147 ;
T_1 V_340 , V_5 ;
char * V_220 ;
int V_7 = 0 ;
V_149 -> V_205 = V_227 ;
if ( ! V_149 -> V_12 )
V_149 -> V_12 = F_2 ( V_332 , V_14 ) ;
if ( ! V_149 -> V_12 )
return 0 ;
V_220 = V_149 -> V_12 ;
if ( * V_168 )
return 0 ;
if ( V_207 . V_208 . V_202 == V_341 )
V_340 = V_207 . V_208 . V_204 [ V_342 ] ;
else
return 0 ;
if ( V_340 == V_343 )
for ( V_5 = 1 ; V_5 <= V_344 ; V_5 ++ )
V_7 = F_74 ( V_27 ,
V_220 , V_7 , V_5 ) ;
else
V_7 = F_74 ( V_27 ,
V_220 , V_7 , V_340 ) ;
return F_39 ( V_3 , V_167 , V_168 , V_220 , V_7 ) ;
}
static T_2
F_76 ( struct V_146 * V_146 , const char T_3 * V_3 ,
T_4 V_167 , T_5 * V_168 )
{
struct V_148 * V_149 = V_146 -> V_154 ;
struct V_26 * V_27 = (struct V_26 * ) V_149 -> V_147 ;
T_1 V_340 , V_238 , V_345 = 0 ;
void T_8 * V_346 ;
int V_150 ;
V_149 -> V_205 = V_206 ;
V_150 = F_49 ( V_3 , V_167 , & V_207 . V_208 ) ;
if ( V_150 < 0 )
return V_150 ;
V_340 = V_207 . V_208 . V_204 [ V_342 ] ;
V_238 = V_207 . V_208 . V_204 [ V_347 ] ;
if ( V_207 . V_208 . V_202 == V_348 ||
V_207 . V_208 . V_202 == V_349 ||
V_207 . V_208 . V_202 == V_350 ) {
if ( V_150 != V_351 )
goto V_240;
if ( V_340 > V_344 )
goto V_240;
} else if ( V_207 . V_208 . V_202 == V_341 ) {
if ( V_150 != V_352 )
goto V_240;
if ( ( V_340 > V_344 ) &&
( V_340 != V_343 ) )
goto V_240;
} else
goto V_240;
if ( V_207 . V_208 . V_202 == V_348 ||
V_207 . V_208 . V_202 == V_349 ||
V_207 . V_208 . V_202 == V_350 ) {
switch ( V_340 ) {
case V_331 :
V_346 = V_27 -> V_256 . V_333 ;
break;
case V_334 :
V_346 = V_27 -> V_256 . V_335 ;
break;
case V_336 :
V_346 = V_27 -> V_256 . V_337 ;
break;
case V_338 :
V_346 = V_27 -> V_256 . V_339 ;
break;
default:
goto V_240;
}
if ( V_207 . V_208 . V_202 == V_348 )
V_345 = V_238 ;
if ( V_207 . V_208 . V_202 == V_349 ) {
V_345 = F_17 ( V_346 ) ;
V_345 |= V_238 ;
}
if ( V_207 . V_208 . V_202 == V_350 ) {
V_345 = F_17 ( V_346 ) ;
V_345 &= ~ V_238 ;
}
F_68 ( V_345 , V_346 ) ;
F_17 ( V_346 ) ;
}
return V_167 ;
V_240:
memset ( & V_207 , 0 , sizeof( V_207 ) ) ;
return - V_193 ;
}
static int
F_77 ( struct V_26 * V_27 , char * V_220 ,
int V_7 , T_1 V_353 )
{
if ( ! V_220 )
return 0 ;
switch ( V_353 ) {
case V_354 :
V_7 += snprintf ( V_220 + V_7 , V_355 - V_7 ,
L_81 ,
F_17 ( V_27 -> V_256 . V_260 +
V_356 ) ) ;
break;
case V_357 :
V_7 += snprintf ( V_220 + V_7 , V_355 - V_7 ,
L_82 ,
F_17 ( V_27 -> V_256 . V_260 +
V_358 ) ) ;
break;
case V_359 :
V_7 += snprintf ( V_220 + V_7 , V_355 - V_7 ,
L_83 ,
F_17 ( V_27 -> V_256 . V_260 +
V_360 ) ) ;
break;
case V_361 :
V_7 += snprintf ( V_220 + V_7 , V_355 - V_7 ,
L_84 ,
F_17 ( V_27 -> V_256 . V_260 +
V_362 ) ) ;
break;
case V_363 :
V_7 += snprintf ( V_220 + V_7 , V_355 - V_7 ,
L_85 ,
F_17 ( V_27 -> V_256 . V_260 +
V_364 ) ) ;
break;
case V_365 :
V_7 += snprintf ( V_220 + V_7 , V_355 - V_7 ,
L_86 ,
F_17 ( V_27 -> V_256 . V_260 +
V_366 ) ) ;
break;
default:
break;
}
return V_7 ;
}
static T_2
F_78 ( struct V_146 * V_146 , char T_3 * V_3 , T_4 V_167 ,
T_5 * V_168 )
{
struct V_148 * V_149 = V_146 -> V_154 ;
struct V_26 * V_27 = (struct V_26 * ) V_149 -> V_147 ;
T_1 V_367 , V_5 ;
char * V_220 ;
int V_7 = 0 ;
V_149 -> V_205 = V_227 ;
if ( ! V_149 -> V_12 )
V_149 -> V_12 = F_2 ( V_355 , V_14 ) ;
if ( ! V_149 -> V_12 )
return 0 ;
V_220 = V_149 -> V_12 ;
if ( * V_168 )
return 0 ;
if ( V_207 . V_208 . V_202 == V_368 )
V_367 = V_207 . V_208 . V_204 [ V_369 ] ;
else
return 0 ;
if ( V_367 == V_370 )
for ( V_5 = 1 ; V_5 <= V_371 ; V_5 ++ )
V_7 = F_77 ( V_27 ,
V_220 , V_7 , V_5 ) ;
else
V_7 = F_77 ( V_27 ,
V_220 , V_7 , V_367 ) ;
return F_39 ( V_3 , V_167 , V_168 , V_220 , V_7 ) ;
}
static T_2
F_79 ( struct V_146 * V_146 , const char T_3 * V_3 ,
T_4 V_167 , T_5 * V_168 )
{
struct V_148 * V_149 = V_146 -> V_154 ;
struct V_26 * V_27 = (struct V_26 * ) V_149 -> V_147 ;
T_1 V_367 , V_238 , V_345 = 0 ;
void T_8 * V_372 ;
int V_150 ;
V_149 -> V_205 = V_206 ;
V_150 = F_49 ( V_3 , V_167 , & V_207 . V_208 ) ;
if ( V_150 < 0 )
return V_150 ;
V_367 = V_207 . V_208 . V_204 [ V_369 ] ;
V_238 = V_207 . V_208 . V_204 [ V_373 ] ;
if ( V_207 . V_208 . V_202 == V_374 ||
V_207 . V_208 . V_202 == V_375 ||
V_207 . V_208 . V_202 == V_376 ) {
if ( V_150 != V_377 )
goto V_240;
if ( V_367 > V_371 )
goto V_240;
} else if ( V_207 . V_208 . V_202 == V_368 ) {
if ( V_150 != V_378 )
goto V_240;
if ( ( V_367 > V_371 ) &&
( V_367 != V_370 ) )
goto V_240;
} else
goto V_240;
if ( V_207 . V_208 . V_202 == V_374 ||
V_207 . V_208 . V_202 == V_375 ||
V_207 . V_208 . V_202 == V_376 ) {
switch ( V_367 ) {
case V_354 :
V_372 = V_27 -> V_256 . V_260 +
V_356 ;
break;
case V_357 :
V_372 = V_27 -> V_256 . V_260 +
V_358 ;
break;
case V_359 :
V_372 = V_27 -> V_256 . V_260 +
V_360 ;
break;
case V_361 :
V_372 = V_27 -> V_256 . V_260 +
V_362 ;
break;
case V_363 :
V_372 = V_27 -> V_256 . V_260 +
V_364 ;
break;
case V_365 :
V_372 = V_27 -> V_256 . V_260 +
V_366 ;
break;
default:
goto V_240;
}
if ( V_207 . V_208 . V_202 == V_374 )
V_345 = V_238 ;
if ( V_207 . V_208 . V_202 == V_375 ) {
V_345 = F_17 ( V_372 ) ;
V_345 |= V_238 ;
}
if ( V_207 . V_208 . V_202 == V_376 ) {
V_345 = F_17 ( V_372 ) ;
V_345 &= ~ V_238 ;
}
F_68 ( V_345 , V_372 ) ;
F_17 ( V_372 ) ;
}
return V_167 ;
V_240:
memset ( & V_207 , 0 , sizeof( V_207 ) ) ;
return - V_193 ;
}
static int
F_80 ( struct V_26 * V_27 , char * V_220 )
{
T_1 V_379 , V_380 , V_381 , V_382 ;
int V_7 = 0 ;
V_382 = V_207 . V_208 . V_204 [ V_383 ] ;
V_379 = V_207 . V_208 . V_204 [ V_384 ] ;
V_380 = V_207 . V_208 . V_204 [ V_385 ] ;
V_381 = V_207 . V_208 . V_204 [ V_386 ] ;
V_7 += snprintf ( V_220 + V_7 , V_387 - V_7 ,
L_87 , V_379 ) ;
V_7 += snprintf ( V_220 + V_7 , V_387 - V_7 ,
L_88 , V_380 ) ;
V_7 += snprintf ( V_220 + V_7 , V_387 - V_7 ,
L_89 , V_381 ) ;
V_7 += snprintf ( V_220 + V_7 , V_387 - V_7 ,
L_90 , V_382 ) ;
return V_7 ;
}
static T_2
F_81 ( struct V_146 * V_146 , char T_3 * V_3 , T_4 V_167 ,
T_5 * V_168 )
{
struct V_148 * V_149 = V_146 -> V_154 ;
struct V_26 * V_27 = (struct V_26 * ) V_149 -> V_147 ;
char * V_220 ;
int V_7 = 0 ;
V_149 -> V_205 = V_227 ;
if ( ! V_149 -> V_12 )
V_149 -> V_12 = F_2 ( V_387 , V_14 ) ;
if ( ! V_149 -> V_12 )
return 0 ;
V_220 = V_149 -> V_12 ;
if ( * V_168 )
return 0 ;
if ( ( V_207 . V_208 . V_202 != V_388 ) &&
( V_207 . V_208 . V_202 != V_389 ) )
return 0 ;
V_7 = F_80 ( V_27 , V_220 ) ;
return F_39 ( V_3 , V_167 , V_168 , V_220 , V_7 ) ;
}
static T_2
F_82 ( struct V_146 * V_146 , const char T_3 * V_3 ,
T_4 V_167 , T_5 * V_168 )
{
struct V_148 * V_149 = V_146 -> V_154 ;
T_1 V_379 , V_380 , V_381 , V_382 ;
int V_150 ;
V_149 -> V_205 = V_206 ;
V_150 = F_49 ( V_3 , V_167 , & V_207 . V_208 ) ;
if ( V_150 < 0 )
return V_150 ;
V_382 = V_207 . V_208 . V_204 [ V_383 ] ;
V_379 = V_207 . V_208 . V_204 [ V_384 ] ;
V_380 = V_207 . V_208 . V_204 [ V_385 ] ;
V_381 = V_207 . V_208 . V_204 [ V_386 ] ;
if ( V_207 . V_208 . V_202 == V_388 ) {
if ( ! ( V_379 & V_390 ) )
goto V_240;
if ( ( V_379 & ~ V_390 ) &&
( V_379 != V_391 ) )
goto V_240;
if ( V_381 > sizeof( V_92 ) )
goto V_240;
} else if ( V_207 . V_208 . V_202 == V_389 ) {
if ( ! ( V_379 & V_392 ) )
goto V_240;
if ( ( V_379 & ~ V_392 ) &&
( V_379 != V_391 ) )
goto V_240;
if ( V_381 > ( V_393 ) / 4 )
goto V_240;
if ( V_382 != 0x9b )
goto V_240;
} else
goto V_240;
if ( V_381 == 0 )
goto V_240;
if ( V_150 != V_394 )
goto V_240;
if ( V_382 & ~ 0xff )
goto V_240;
if ( V_380 == 0 )
goto V_395;
return V_167 ;
V_395:
memset ( & V_207 , 0 , sizeof( V_207 ) ) ;
return V_167 ;
V_240:
memset ( & V_207 , 0 , sizeof( V_207 ) ) ;
return - V_193 ;
}
static int
F_83 ( struct V_26 * V_27 , char * V_220 , int V_7 )
{
T_6 V_396 , V_397 ;
V_7 += snprintf ( V_220 + V_7 , V_398 - V_7 ,
L_91 ) ;
V_7 += snprintf ( V_220 + V_7 , V_398 - V_7 ,
L_92 ) ;
F_84 ( V_27 , V_399 ,
& V_396 , & V_397 ) ;
V_7 += snprintf ( V_220 + V_7 , V_398 - V_7 ,
L_93 , V_396 , V_397 ) ;
V_7 += snprintf ( V_220 + V_7 , V_398 - V_7 ,
L_94 ) ;
F_84 ( V_27 , V_400 ,
& V_396 , & V_397 ) ;
V_7 += snprintf ( V_220 + V_7 , V_398 - V_7 ,
L_93 , V_396 , V_397 ) ;
V_7 += snprintf ( V_220 + V_7 , V_398 - V_7 ,
L_95 ) ;
F_84 ( V_27 , V_401 ,
& V_396 , & V_397 ) ;
V_7 += snprintf ( V_220 + V_7 , V_398 - V_7 ,
L_93 , V_396 , V_397 ) ;
V_7 += snprintf ( V_220 + V_7 , V_398 - V_7 ,
L_96 ) ;
F_84 ( V_27 , V_402 ,
& V_396 , & V_397 ) ;
V_7 += snprintf ( V_220 + V_7 , V_398 - V_7 ,
L_93 , V_396 , V_397 ) ;
return V_7 ;
}
static int
F_85 ( struct V_26 * V_27 , char * V_220 , int V_7 )
{
T_6 V_396 , V_397 ;
int V_150 ;
V_7 += snprintf ( V_220 + V_7 , V_398 - V_7 ,
L_97 ) ;
V_7 += snprintf ( V_220 + V_7 , V_398 - V_7 ,
L_98 ) ;
V_150 = F_86 ( V_27 , V_399 ,
& V_396 , & V_397 ) ;
if ( ! V_150 )
V_7 += snprintf ( V_220 + V_7 , V_398 - V_7 ,
L_99 ,
V_27 -> V_403 , V_396 , V_397 ) ;
else
V_7 += snprintf ( V_220 + V_7 , V_398 - V_7 ,
L_100 ) ;
V_7 += snprintf ( V_220 + V_7 , V_398 - V_7 ,
L_101 ) ;
V_150 = F_86 ( V_27 , V_400 ,
& V_396 , & V_397 ) ;
if ( ! V_150 )
V_7 += snprintf ( V_220 + V_7 , V_398 - V_7 ,
L_99 ,
V_27 -> V_403 , V_396 , V_397 ) ;
else
V_7 += snprintf ( V_220 + V_7 , V_398 - V_7 ,
L_100 ) ;
V_7 += snprintf ( V_220 + V_7 , V_398 - V_7 ,
L_102 ) ;
V_150 = F_86 ( V_27 , V_401 ,
& V_396 , & V_397 ) ;
if ( ! V_150 )
V_7 += snprintf ( V_220 + V_7 , V_398 - V_7 ,
L_99 ,
V_27 -> V_403 , V_396 , V_397 ) ;
else
V_7 += snprintf ( V_220 + V_7 , V_398 - V_7 ,
L_100 ) ;
V_7 += snprintf ( V_220 + V_7 , V_398 - V_7 ,
L_103 ) ;
V_150 = F_86 ( V_27 , V_402 ,
& V_396 , & V_397 ) ;
if ( ! V_150 )
V_7 += snprintf ( V_220 + V_7 , V_398 - V_7 ,
L_99 ,
V_27 -> V_403 , V_396 , V_397 ) ;
else
V_7 += snprintf ( V_220 + V_7 , V_398 - V_7 ,
L_100 ) ;
return V_7 ;
}
static int
F_87 ( struct V_26 * V_27 , char * V_220 , int V_7 )
{
struct V_404 * V_405 ;
int V_6 ;
V_7 += snprintf ( V_220 + V_7 , V_398 - V_7 ,
L_104 ) ;
V_7 += snprintf ( V_220 + V_7 , V_398 - V_7 ,
L_105 ) ;
V_6 = 0 ;
F_10 (rsrc_blks, &phba->lpfc_vpi_blk_list, list) {
V_7 += snprintf ( V_220 + V_7 , V_398 - V_7 ,
L_106 ,
V_6 , V_405 -> V_406 ,
V_405 -> V_407 ) ;
V_6 ++ ;
}
V_7 += snprintf ( V_220 + V_7 , V_398 - V_7 ,
L_107 ) ;
V_6 = 0 ;
F_10 (rsrc_blks, &phba->sli4_hba.lpfc_vfi_blk_list,
list) {
V_7 += snprintf ( V_220 + V_7 , V_398 - V_7 ,
L_106 ,
V_6 , V_405 -> V_406 ,
V_405 -> V_407 ) ;
V_6 ++ ;
}
V_7 += snprintf ( V_220 + V_7 , V_398 - V_7 ,
L_108 ) ;
V_6 = 0 ;
F_10 (rsrc_blks, &phba->sli4_hba.lpfc_rpi_blk_list,
list) {
V_7 += snprintf ( V_220 + V_7 , V_398 - V_7 ,
L_106 ,
V_6 , V_405 -> V_406 ,
V_405 -> V_407 ) ;
V_6 ++ ;
}
V_7 += snprintf ( V_220 + V_7 , V_398 - V_7 ,
L_109 ) ;
V_6 = 0 ;
F_10 (rsrc_blks, &phba->sli4_hba.lpfc_xri_blk_list,
list) {
V_7 += snprintf ( V_220 + V_7 , V_398 - V_7 ,
L_106 ,
V_6 , V_405 -> V_406 ,
V_405 -> V_407 ) ;
V_6 ++ ;
}
return V_7 ;
}
static T_2
F_88 ( struct V_146 * V_146 , const char T_3 * V_3 ,
T_4 V_167 , T_5 * V_168 )
{
struct V_148 * V_149 = V_146 -> V_154 ;
T_1 V_408 ;
int V_150 ;
V_149 -> V_205 = V_206 ;
V_150 = F_49 ( V_3 , V_167 , & V_207 . V_208 ) ;
if ( V_150 < 0 )
return V_150 ;
V_408 = V_207 . V_208 . V_204 [ V_409 ] ;
if ( V_207 . V_208 . V_202 != V_410 )
goto V_240;
if ( V_150 != V_411 )
goto V_240;
if ( ! ( V_408 & V_412 ) )
goto V_240;
return V_167 ;
V_240:
memset ( & V_207 , 0 , sizeof( V_207 ) ) ;
return - V_193 ;
}
static T_2
F_89 ( struct V_146 * V_146 , char T_3 * V_3 , T_4 V_167 ,
T_5 * V_168 )
{
struct V_148 * V_149 = V_146 -> V_154 ;
struct V_26 * V_27 = (struct V_26 * ) V_149 -> V_147 ;
char * V_220 ;
T_1 V_408 ;
int V_7 = 0 ;
V_149 -> V_205 = V_227 ;
if ( ! V_149 -> V_12 )
V_149 -> V_12 = F_2 ( V_398 , V_14 ) ;
if ( ! V_149 -> V_12 )
return 0 ;
V_220 = V_149 -> V_12 ;
if ( * V_168 )
return 0 ;
if ( V_207 . V_208 . V_202 != V_410 )
return 0 ;
V_408 = V_207 . V_208 . V_204 [ V_409 ] ;
if ( V_408 & V_413 )
V_7 = F_83 ( V_27 , V_220 , V_7 ) ;
if ( V_408 & V_414 )
V_7 = F_85 ( V_27 , V_220 , V_7 ) ;
if ( V_408 & V_415 )
V_7 = F_87 ( V_27 , V_220 , V_7 ) ;
return F_39 ( V_3 , V_167 , V_168 , V_220 , V_7 ) ;
}
void
F_90 ( struct V_26 * V_27 , enum V_416 V_417 ,
enum V_418 V_419 , enum V_420 V_421 ,
enum V_422 V_423 ,
struct V_45 * V_424 , T_1 V_425 )
{
#ifdef F_21
T_1 * V_382 , * V_379 , * V_380 , * V_381 ;
char V_426 [ V_427 ] ;
int V_7 = 0 ;
T_1 V_428 = 0 ;
T_1 * V_429 ;
T_1 V_5 ;
if ( V_207 . V_208 . V_202 != V_389 )
return;
V_382 = & V_207 . V_208 . V_204 [ V_383 ] ;
V_379 = & V_207 . V_208 . V_204 [ V_384 ] ;
V_380 = & V_207 . V_208 . V_204 [ V_385 ] ;
V_381 = & V_207 . V_208 . V_204 [ V_386 ] ;
if ( ! ( * V_379 & V_391 ) ||
( * V_380 == 0 ) ||
( * V_381 == 0 ) )
return;
if ( * V_382 != 0x9B )
return;
if ( ( V_419 == V_430 ) && ( V_421 == V_431 ) ) {
if ( * V_379 & V_432 ) {
V_428 |= V_432 ;
F_31 ( V_159 L_110
L_111 ,
V_423 , V_417 , V_425 ) ;
}
}
if ( ( V_419 == V_430 ) && ( V_421 == V_433 ) ) {
if ( * V_379 & V_434 ) {
V_428 |= V_434 ;
F_31 ( V_159 L_112
L_113 ,
V_423 , V_417 , V_425 ) ;
}
}
if ( ( V_419 == V_435 ) && ( V_421 == V_431 ) ) {
if ( * V_379 & V_436 ) {
V_428 |= V_436 ;
F_31 ( V_159 L_114
L_111 ,
V_423 , V_417 , V_425 ) ;
}
}
if ( ( V_419 == V_435 ) && ( V_421 == V_433 ) ) {
if ( * V_379 & V_437 ) {
V_428 |= V_437 ;
F_31 ( V_159 L_115
L_113 ,
V_423 , V_417 , V_425 ) ;
}
}
if ( V_428 ) {
V_429 = ( T_1 * ) V_424 -> V_74 ;
for ( V_5 = 0 ; V_5 < * V_381 ; V_5 ++ ) {
if ( ! ( V_5 % 8 ) ) {
if ( V_5 != 0 )
F_31 ( V_159 L_116 , V_426 ) ;
V_7 = 0 ;
V_7 += snprintf ( V_426 + V_7 ,
V_427 - V_7 ,
L_117 , V_5 ) ;
}
V_7 += snprintf ( V_426 + V_7 , V_427 - V_7 ,
L_50 , ( T_1 ) * V_429 ) ;
V_429 ++ ;
}
if ( ( V_5 - 1 ) % 8 )
F_31 ( V_159 L_116 , V_426 ) ;
( * V_380 ) -- ;
}
if ( * V_380 == 0 )
memset ( & V_207 , 0 , sizeof( V_207 ) ) ;
return;
#endif
}
void
F_91 ( struct V_26 * V_27 , V_92 * V_438 )
{
#ifdef F_21
T_1 * V_379 , * V_380 , * V_381 , * V_382 ;
char V_426 [ V_427 ] ;
int V_7 = 0 ;
T_1 * V_429 ;
T_7 * V_439 ;
T_1 V_5 , V_32 ;
if ( V_207 . V_208 . V_202 != V_388 )
return;
V_382 = & V_207 . V_208 . V_204 [ V_383 ] ;
V_379 = & V_207 . V_208 . V_204 [ V_384 ] ;
V_380 = & V_207 . V_208 . V_204 [ V_385 ] ;
V_381 = & V_207 . V_208 . V_204 [ V_386 ] ;
if ( ! ( * V_379 & V_390 ) ||
( * V_380 == 0 ) ||
( * V_381 == 0 ) )
return;
if ( ( * V_382 != V_440 ) &&
( * V_382 != V_438 -> V_441 ) )
return;
if ( * V_379 & V_442 ) {
F_31 ( V_159 L_118 ,
V_438 -> V_441 ) ;
V_429 = ( T_1 * ) V_438 ;
for ( V_5 = 0 ; V_5 < * V_381 ; V_5 ++ ) {
if ( ! ( V_5 % 8 ) ) {
if ( V_5 != 0 )
F_31 ( V_159 L_116 , V_426 ) ;
V_7 = 0 ;
memset ( V_426 , 0 , V_427 ) ;
V_7 += snprintf ( V_426 + V_7 ,
V_427 - V_7 ,
L_117 , V_5 ) ;
}
V_7 += snprintf ( V_426 + V_7 , V_427 - V_7 ,
L_50 ,
( ( T_1 ) * V_429 ) & 0xffffffff ) ;
V_429 ++ ;
}
if ( ( V_5 - 1 ) % 8 )
F_31 ( V_159 L_116 , V_426 ) ;
F_31 ( V_159 L_38 ) ;
}
if ( * V_379 & V_443 ) {
F_31 ( V_159 L_119 ,
V_438 -> V_441 ) ;
V_439 = ( T_7 * ) V_438 ;
for ( V_5 = 0 ; V_5 < * V_381 ; V_5 ++ ) {
if ( ! ( V_5 % 8 ) ) {
if ( V_5 != 0 )
F_31 ( V_159 L_116 , V_426 ) ;
V_7 = 0 ;
memset ( V_426 , 0 , V_427 ) ;
V_7 += snprintf ( V_426 + V_7 ,
V_427 - V_7 ,
L_117 , V_5 ) ;
}
for ( V_32 = 0 ; V_32 < 4 ; V_32 ++ ) {
V_7 += snprintf ( V_426 + V_7 ,
V_427 - V_7 ,
L_120 ,
( ( T_7 ) * V_439 ) & 0xff ) ;
V_439 ++ ;
}
V_7 += snprintf ( V_426 + V_7 ,
V_427 - V_7 , L_121 ) ;
}
if ( ( V_5 - 1 ) % 8 )
F_31 ( V_159 L_116 , V_426 ) ;
F_31 ( V_159 L_38 ) ;
}
( * V_380 ) -- ;
if ( * V_380 == 0 )
memset ( & V_207 , 0 , sizeof( V_207 ) ) ;
return;
#endif
}
inline void
F_92 ( struct V_1 * V_2 )
{
#ifdef F_21
struct V_26 * V_27 = V_2 -> V_27 ;
char V_114 [ 64 ] ;
T_1 V_444 , V_5 ;
if ( ! V_15 )
return;
if ( ! V_445 ) {
V_445 = F_93 ( L_122 , NULL ) ;
F_94 ( & V_446 , 0 ) ;
if ( ! V_445 ) {
F_95 ( V_2 , V_159 , V_186 ,
L_123 ) ;
goto V_447;
}
}
if ( ! V_21 )
V_21 = V_144 ;
snprintf ( V_114 , sizeof( V_114 ) , L_124 , V_27 -> V_403 ) ;
if ( ! V_27 -> V_448 ) {
V_27 -> V_448 =
F_93 ( V_114 , V_445 ) ;
if ( ! V_27 -> V_448 ) {
F_95 ( V_2 , V_159 , V_186 ,
L_125 ) ;
goto V_447;
}
F_96 ( & V_446 ) ;
F_94 ( & V_27 -> V_449 , 0 ) ;
snprintf ( V_114 , sizeof( V_114 ) , L_126 ) ;
V_27 -> V_450 =
F_97 ( V_114 , V_451 | V_452 | V_453 ,
V_27 -> V_448 ,
V_27 , & V_454 ) ;
if ( ! V_27 -> V_450 ) {
F_95 ( V_2 , V_159 , V_186 ,
L_127 ) ;
goto V_447;
}
if ( V_27 -> V_49 < V_455 ) {
snprintf ( V_114 , sizeof( V_114 ) , L_128 ) ;
V_27 -> V_456 =
F_97 ( V_114 ,
V_451 | V_452 | V_453 ,
V_27 -> V_448 ,
V_27 , & V_457 ) ;
if ( ! V_27 -> V_456 ) {
F_95 ( V_2 , V_159 , V_186 ,
L_129
L_130 ) ;
goto V_447;
}
} else
V_27 -> V_456 = NULL ;
if ( V_27 -> V_49 < V_455 ) {
snprintf ( V_114 , sizeof( V_114 ) , L_131 ) ;
V_27 -> V_458 =
F_97 ( V_114 ,
V_451 | V_452 | V_453 ,
V_27 -> V_448 ,
V_27 , & V_459 ) ;
if ( ! V_27 -> V_458 ) {
F_95 ( V_2 , V_159 , V_186 ,
L_132
L_133 ) ;
goto V_447;
}
} else
V_27 -> V_456 = NULL ;
snprintf ( V_114 , sizeof( V_114 ) , L_134 ) ;
V_27 -> V_460 =
F_97 ( V_114 , V_451 | V_452 | V_453 ,
V_27 -> V_448 ,
V_27 , & V_461 ) ;
if ( ! V_27 -> V_460 ) {
F_95 ( V_2 , V_159 , V_186 ,
L_135 ) ;
goto V_447;
}
snprintf ( V_114 , sizeof( V_114 ) , L_136 ) ;
V_27 -> V_462 =
F_97 ( V_114 , V_451 | V_452 | V_453 ,
V_27 -> V_448 ,
V_27 , & V_463 ) ;
if ( ! V_27 -> V_462 ) {
F_95 ( V_2 , V_159 , V_186 ,
L_137 ) ;
goto V_447;
}
snprintf ( V_114 , sizeof( V_114 ) , L_138 ) ;
V_27 -> V_184 =
F_97 ( V_114 , V_451 | V_452 | V_453 ,
V_27 -> V_448 ,
V_27 , & V_464 ) ;
if ( ! V_27 -> V_184 ) {
F_95 ( V_2 , V_159 , V_186 ,
L_139 ) ;
goto V_447;
}
V_27 -> V_185 = V_465 ;
snprintf ( V_114 , sizeof( V_114 ) , L_140 ) ;
V_27 -> V_174 =
F_97 ( V_114 , V_451 | V_452 | V_453 ,
V_27 -> V_448 ,
V_27 , & V_464 ) ;
if ( ! V_27 -> V_174 ) {
F_95 ( V_2 , V_159 , V_186 ,
L_141 ) ;
goto V_447;
}
snprintf ( V_114 , sizeof( V_114 ) , L_142 ) ;
V_27 -> V_176 =
F_97 ( V_114 , V_451 | V_452 | V_453 ,
V_27 -> V_448 ,
V_27 , & V_464 ) ;
if ( ! V_27 -> V_176 ) {
F_95 ( V_2 , V_159 , V_186 ,
L_143 ) ;
goto V_447;
}
snprintf ( V_114 , sizeof( V_114 ) , L_144 ) ;
V_27 -> V_178 =
F_97 ( V_114 , V_451 | V_452 | V_453 ,
V_27 -> V_448 ,
V_27 , & V_464 ) ;
if ( ! V_27 -> V_178 ) {
F_95 ( V_2 , V_159 , V_186 ,
L_145 ) ;
goto V_447;
}
snprintf ( V_114 , sizeof( V_114 ) , L_146 ) ;
V_27 -> V_180 =
F_97 ( V_114 , V_451 | V_452 | V_453 ,
V_27 -> V_448 ,
V_27 , & V_464 ) ;
if ( ! V_27 -> V_180 ) {
F_95 ( V_2 , V_159 , V_186 ,
L_147 ) ;
goto V_447;
}
snprintf ( V_114 , sizeof( V_114 ) , L_148 ) ;
V_27 -> V_182 =
F_97 ( V_114 , V_451 | V_452 | V_453 ,
V_27 -> V_448 ,
V_27 , & V_464 ) ;
if ( ! V_27 -> V_182 ) {
F_95 ( V_2 , V_159 , V_186 ,
L_149 ) ;
goto V_447;
}
if ( V_29 ) {
V_444 = V_29 - 1 ;
if ( V_444 & V_29 ) {
V_444 = V_29 ;
V_5 = 0 ;
while ( V_444 > 1 ) {
V_444 = V_444 >> 1 ;
V_5 ++ ;
}
V_29 = ( 1 << V_5 ) ;
F_31 ( V_159
L_150
L_151 , V_17 ) ;
}
}
snprintf ( V_114 , sizeof( V_114 ) , L_152 ) ;
V_27 -> V_466 =
F_97 ( V_114 , V_451 | V_452 | V_453 ,
V_27 -> V_448 ,
V_27 , & V_467 ) ;
if ( ! V_27 -> V_466 ) {
F_95 ( V_2 , V_159 , V_186 ,
L_153
L_154 ) ;
goto V_447;
}
if ( ! V_27 -> V_30 ) {
V_27 -> V_30 = F_2 (
( sizeof( struct V_10 ) *
V_29 ) ,
V_14 ) ;
if ( ! V_27 -> V_30 ) {
F_95 ( V_2 , V_159 , V_186 ,
L_155
L_156 ) ;
goto V_447;
}
F_94 ( & V_27 -> V_28 , 0 ) ;
memset ( V_27 -> V_30 , 0 ,
( sizeof( struct V_10 ) *
V_29 ) ) ;
}
}
snprintf ( V_114 , sizeof( V_114 ) , L_157 , V_2 -> V_468 ) ;
if ( ! V_2 -> V_469 ) {
V_2 -> V_469 =
F_93 ( V_114 , V_27 -> V_448 ) ;
if ( ! V_2 -> V_469 ) {
F_95 ( V_2 , V_159 , V_186 ,
L_158 ) ;
goto V_447;
}
F_96 ( & V_27 -> V_449 ) ;
}
if ( V_17 ) {
V_444 = V_17 - 1 ;
if ( V_444 & V_17 ) {
V_444 = V_17 ;
V_5 = 0 ;
while ( V_444 > 1 ) {
V_444 = V_444 >> 1 ;
V_5 ++ ;
}
V_17 = ( 1 << V_5 ) ;
F_31 ( V_159
L_159 ,
V_17 ) ;
}
}
V_2 -> V_18 = F_98 (
( sizeof( struct V_10 ) * V_17 ) ,
V_14 ) ;
if ( ! V_2 -> V_18 ) {
F_95 ( V_2 , V_159 , V_186 ,
L_160
L_161 ) ;
goto V_447;
}
F_94 ( & V_2 -> V_16 , 0 ) ;
snprintf ( V_114 , sizeof( V_114 ) , L_162 ) ;
V_2 -> V_470 =
F_97 ( V_114 , V_451 | V_452 | V_453 ,
V_2 -> V_469 ,
V_2 , & V_471 ) ;
if ( ! V_2 -> V_470 ) {
F_95 ( V_2 , V_159 , V_186 ,
L_163
L_164 ) ;
goto V_447;
}
snprintf ( V_114 , sizeof( V_114 ) , L_165 ) ;
V_2 -> V_472 =
F_97 ( V_114 , V_451 | V_452 | V_453 ,
V_2 -> V_469 ,
V_2 , & V_473 ) ;
if ( ! V_2 -> V_472 ) {
F_95 ( V_2 , V_159 , V_186 ,
L_166 ) ;
goto V_447;
}
if ( V_27 -> V_49 < V_455 )
goto V_447;
snprintf ( V_114 , sizeof( V_114 ) , L_167 ) ;
if ( ! V_27 -> V_474 ) {
V_27 -> V_474 =
F_93 ( V_114 , V_27 -> V_448 ) ;
if ( ! V_27 -> V_474 ) {
F_95 ( V_2 , V_159 , V_186 ,
L_168 ) ;
goto V_447;
}
memset ( & V_207 , 0 , sizeof( V_207 ) ) ;
}
snprintf ( V_114 , sizeof( V_114 ) , L_169 ) ;
if ( ! V_27 -> V_475 ) {
V_27 -> V_475 =
F_97 ( V_114 , V_451 | V_452 | V_453 ,
V_27 -> V_474 , V_27 , & V_476 ) ;
if ( ! V_27 -> V_475 ) {
F_95 ( V_2 , V_159 , V_186 ,
L_170 ) ;
goto V_447;
}
V_207 . V_216 . V_237 = 0 ;
}
snprintf ( V_114 , sizeof( V_114 ) , L_171 ) ;
if ( ! V_27 -> V_477 ) {
V_27 -> V_477 =
F_97 ( V_114 , V_451 | V_452 | V_453 ,
V_27 -> V_474 , V_27 , & V_478 ) ;
if ( ! V_27 -> V_477 ) {
F_95 ( V_2 , V_159 , V_186 ,
L_172 ) ;
goto V_447;
}
V_207 . V_216 . V_237 = 0 ;
}
snprintf ( V_114 , sizeof( V_114 ) , L_173 ) ;
if ( ! V_27 -> V_479 ) {
V_27 -> V_479 =
F_97 ( V_114 , V_451 | V_452 ,
V_27 -> V_474 , V_27 , & V_480 ) ;
if ( ! V_27 -> V_479 ) {
F_95 ( V_2 , V_159 , V_186 ,
L_174 ) ;
goto V_447;
}
}
snprintf ( V_114 , sizeof( V_114 ) , L_175 ) ;
if ( ! V_27 -> V_481 ) {
V_27 -> V_481 =
F_97 ( V_114 , V_451 | V_452 | V_453 ,
V_27 -> V_474 , V_27 , & V_482 ) ;
if ( ! V_27 -> V_481 ) {
F_95 ( V_2 , V_159 , V_186 ,
L_176 ) ;
goto V_447;
}
}
snprintf ( V_114 , sizeof( V_114 ) , L_177 ) ;
if ( ! V_27 -> V_483 ) {
V_27 -> V_483 =
F_97 ( V_114 , V_451 | V_452 | V_453 ,
V_27 -> V_474 , V_27 , & V_484 ) ;
if ( ! V_27 -> V_483 ) {
F_95 ( V_2 , V_159 , V_186 ,
L_178 ) ;
goto V_447;
}
}
snprintf ( V_114 , sizeof( V_114 ) , L_179 ) ;
if ( ! V_27 -> V_485 ) {
V_27 -> V_485 =
F_97 ( V_114 , V_451 | V_452 | V_453 ,
V_27 -> V_474 , V_27 , & V_486 ) ;
if ( ! V_27 -> V_485 ) {
F_95 ( V_2 , V_159 , V_186 ,
L_180 ) ;
goto V_447;
}
}
snprintf ( V_114 , sizeof( V_114 ) , L_181 ) ;
if ( ! V_27 -> V_487 ) {
V_27 -> V_487 =
F_97 ( V_114 , V_451 | V_452 | V_453 ,
V_27 -> V_474 , V_27 , & V_488 ) ;
if ( ! V_27 -> V_487 ) {
F_95 ( V_2 , V_159 , V_186 ,
L_182 ) ;
goto V_447;
}
}
if ( V_27 -> V_256 . V_489 ) {
snprintf ( V_114 , sizeof( V_114 ) , L_183 ) ;
if ( ! V_27 -> V_490 ) {
V_27 -> V_490 =
F_97 ( V_114 ,
V_451 | V_452 | V_453 ,
V_27 -> V_474 , V_27 ,
& V_491 ) ;
if ( ! V_27 -> V_490 ) {
F_95 ( V_2 , V_159 , V_186 ,
L_184
L_185 ) ;
goto V_447;
}
}
}
V_447:
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
if ( V_2 -> V_470 ) {
F_100 ( V_2 -> V_470 ) ;
V_2 -> V_470 = NULL ;
}
if ( V_2 -> V_472 ) {
F_100 ( V_2 -> V_472 ) ;
V_2 -> V_472 = NULL ;
}
if ( V_2 -> V_469 ) {
F_100 ( V_2 -> V_469 ) ;
V_2 -> V_469 = NULL ;
F_101 ( & V_27 -> V_449 ) ;
}
if ( F_3 ( & V_27 -> V_449 ) == 0 ) {
if ( V_27 -> V_450 ) {
F_100 ( V_27 -> V_450 ) ;
V_27 -> V_450 = NULL ;
}
if ( V_27 -> V_456 ) {
F_100 ( V_27 -> V_456 ) ;
V_27 -> V_456 = NULL ;
}
if ( V_27 -> V_458 ) {
F_100 ( V_27 -> V_458 ) ;
V_27 -> V_458 = NULL ;
}
if ( V_27 -> V_460 ) {
F_100 ( V_27 -> V_460 ) ;
V_27 -> V_460 = NULL ;
}
if ( V_27 -> V_462 ) {
F_100 ( V_27 -> V_462 ) ;
V_27 -> V_462 = NULL ;
}
if ( V_27 -> V_184 ) {
F_100 ( V_27 -> V_184 ) ;
V_27 -> V_184 = NULL ;
}
if ( V_27 -> V_174 ) {
F_100 ( V_27 -> V_174 ) ;
V_27 -> V_174 = NULL ;
}
if ( V_27 -> V_176 ) {
F_100 ( V_27 -> V_176 ) ;
V_27 -> V_176 = NULL ;
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
if ( V_27 -> V_30 ) {
F_5 ( V_27 -> V_30 ) ;
V_27 -> V_30 = NULL ;
}
if ( V_27 -> V_466 ) {
F_100 ( V_27 -> V_466 ) ;
V_27 -> V_466 = NULL ;
}
if ( V_27 -> V_49 == V_455 ) {
if ( V_27 -> V_490 ) {
F_100 ( V_27 -> V_490 ) ;
V_27 -> V_490 = NULL ;
}
if ( V_27 -> V_487 ) {
F_100 ( V_27 -> V_487 ) ;
V_27 -> V_487 = NULL ;
}
if ( V_27 -> V_485 ) {
F_100 ( V_27 -> V_485 ) ;
V_27 -> V_485 = NULL ;
}
if ( V_27 -> V_483 ) {
F_100 ( V_27 -> V_483 ) ;
V_27 -> V_483 = NULL ;
}
if ( V_27 -> V_481 ) {
F_100 ( V_27 -> V_481 ) ;
V_27 -> V_481 = NULL ;
}
if ( V_27 -> V_479 ) {
F_100 ( V_27 -> V_479 ) ;
V_27 -> V_479 = NULL ;
}
if ( V_27 -> V_477 ) {
F_100 ( V_27 -> V_477 ) ;
V_27 -> V_477 = NULL ;
}
if ( V_27 -> V_475 ) {
F_100 ( V_27 -> V_475 ) ;
V_27 -> V_475 = NULL ;
}
if ( V_27 -> V_474 ) {
F_100 ( V_27 -> V_474 ) ;
V_27 -> V_474 = NULL ;
}
}
if ( V_27 -> V_448 ) {
F_100 ( V_27 -> V_448 ) ;
V_27 -> V_448 = NULL ;
F_101 ( & V_446 ) ;
}
if ( F_3 ( & V_446 ) == 0 ) {
F_100 ( V_445 ) ;
V_445 = NULL ;
}
}
#endif
return;
}
