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
static T_2
F_36 ( struct V_146 * V_146 , char T_3 * V_3 ,
T_4 V_167 , T_5 * V_168 )
{
struct V_171 * V_172 = V_146 -> V_164 ;
struct V_26 * V_27 = V_146 -> V_154 ;
char V_173 [ 32 ] ;
V_73 V_174 = 0 ;
int V_31 = 0 ;
if ( V_172 == V_27 -> V_175 )
V_31 = snprintf ( V_173 , 32 , L_41 , V_27 -> V_176 ) ;
else if ( V_172 == V_27 -> V_177 )
V_31 = snprintf ( V_173 , 32 , L_41 , V_27 -> V_178 ) ;
else if ( V_172 == V_27 -> V_179 )
V_31 = snprintf ( V_173 , 32 , L_41 , V_27 -> V_180 ) ;
else if ( V_172 == V_27 -> V_181 )
V_31 = snprintf ( V_173 , 32 , L_41 , V_27 -> V_182 ) ;
else if ( V_172 == V_27 -> V_183 )
V_31 = snprintf ( V_173 , 32 , L_41 , V_27 -> V_184 ) ;
else if ( V_172 == V_27 -> V_185 )
V_31 = snprintf ( V_173 , 32 , L_41 , V_27 -> V_186 ) ;
else if ( V_172 == V_27 -> V_187 )
V_31 = snprintf ( V_173 , 32 , L_42 , V_27 -> V_188 ) ;
else if ( V_172 == V_27 -> V_189 ) {
memcpy ( & V_174 , & V_27 -> V_190 , sizeof( struct V_191 ) ) ;
V_174 = F_37 ( V_174 ) ;
V_31 = snprintf ( V_173 , 32 , L_43 , V_174 ) ;
} else if ( V_172 == V_27 -> V_192 ) {
if ( V_27 -> V_193 == ( V_194 ) ( - 1 ) )
V_31 = snprintf ( V_173 , 32 , L_44 ) ;
else
V_31 = snprintf ( V_173 , 32 , L_45 ,
( V_73 ) V_27 -> V_193 ) ;
} else
F_38 ( V_27 , V_159 , V_195 ,
L_46 ) ;
return F_39 ( V_3 , V_167 , V_168 , & V_173 , V_31 ) ;
}
static T_2
F_40 ( struct V_146 * V_146 , const char T_3 * V_3 ,
T_4 V_167 , T_5 * V_168 )
{
struct V_171 * V_172 = V_146 -> V_164 ;
struct V_26 * V_27 = V_146 -> V_154 ;
char V_196 [ 32 ] ;
V_73 V_174 = 0 ;
int V_4 ;
memset ( V_196 , 0 , 32 ) ;
V_4 = ( V_167 < 32 ) ? V_167 : 32 ;
if ( F_41 ( V_196 , V_3 , V_4 ) )
return 0 ;
if ( V_172 == V_27 -> V_192 ) {
if ( ( V_3 [ 0 ] == 'o' ) && ( V_3 [ 1 ] == 'f' ) && ( V_3 [ 2 ] == 'f' ) )
V_174 = ( V_73 ) ( - 1 ) ;
}
if ( ( V_174 == 0 ) && ( F_42 ( V_196 , 0 , & V_174 ) ) )
return 0 ;
if ( V_172 == V_27 -> V_175 )
V_27 -> V_176 = ( T_1 ) V_174 ;
else if ( V_172 == V_27 -> V_177 )
V_27 -> V_178 = ( T_1 ) V_174 ;
else if ( V_172 == V_27 -> V_179 )
V_27 -> V_180 = ( T_1 ) V_174 ;
else if ( V_172 == V_27 -> V_181 )
V_27 -> V_182 = ( T_1 ) V_174 ;
else if ( V_172 == V_27 -> V_183 )
V_27 -> V_184 = ( T_1 ) V_174 ;
else if ( V_172 == V_27 -> V_185 )
V_27 -> V_186 = ( T_1 ) V_174 ;
else if ( V_172 == V_27 -> V_192 )
V_27 -> V_193 = ( V_194 ) V_174 ;
else if ( V_172 == V_27 -> V_187 )
V_27 -> V_188 = ( T_1 ) ( V_174 & V_197 ) ;
else if ( V_172 == V_27 -> V_189 ) {
V_174 = F_37 ( V_174 ) ;
memcpy ( & V_27 -> V_190 , & V_174 , sizeof( struct V_191 ) ) ;
} else
F_38 ( V_27 , V_159 , V_195 ,
L_47 ) ;
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
F_45 ( struct V_146 * V_146 , T_5 V_76 , int V_198 )
{
struct V_148 * V_149 ;
T_5 V_199 = - 1 ;
V_149 = V_146 -> V_154 ;
switch ( V_198 ) {
case 0 :
V_199 = V_76 ;
break;
case 1 :
V_199 = V_146 -> V_200 + V_76 ;
break;
case 2 :
V_199 = V_149 -> V_7 - V_76 ;
}
return ( V_199 < 0 || V_199 > V_149 -> V_7 ) ? - V_201 : ( V_146 -> V_200 = V_199 ) ;
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
struct V_202 * V_203 )
{
char V_204 [ 64 ] ;
char * V_205 , * V_206 ;
int V_5 ;
T_4 V_207 ;
if ( ! F_50 ( V_208 , V_3 , V_167 ) )
return - V_209 ;
memset ( V_204 , 0 , sizeof( V_204 ) ) ;
memset ( V_203 , 0 , sizeof( * V_203 ) ) ;
V_207 = F_51 ( V_167 , ( sizeof( V_204 ) - 1 ) ) ;
if ( F_41 ( V_204 , V_3 , V_207 ) )
return - V_209 ;
V_205 = & V_204 [ 0 ] ;
V_206 = F_52 ( & V_205 , L_48 ) ;
if ( ! V_206 )
return - V_201 ;
V_203 -> V_210 = F_53 ( V_206 , NULL , 0 ) ;
if ( V_203 -> V_210 == 0 )
return - V_201 ;
for ( V_5 = 0 ; V_5 < V_211 ; V_5 ++ ) {
V_206 = F_52 ( & V_205 , L_48 ) ;
if ( ! V_206 )
return V_5 ;
V_203 -> V_212 [ V_5 ] = F_53 ( V_206 , NULL , 0 ) ;
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
if ( V_149 -> V_213 == V_214 ) {
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
V_149 -> V_213 = V_235 ;
if ( ! V_149 -> V_12 )
V_149 -> V_12 = F_2 ( V_236 , V_14 ) ;
if ( ! V_149 -> V_12 )
return 0 ;
V_228 = V_149 -> V_12 ;
if ( * V_168 )
return 0 ;
if ( V_215 . V_216 . V_210 == V_237 ) {
V_226 = V_215 . V_216 . V_212 [ V_238 ] ;
V_227 = V_215 . V_216 . V_212 [ V_239 ] ;
} else
return 0 ;
switch ( V_227 ) {
case V_240 :
F_58 ( V_230 , V_226 , & V_233 ) ;
V_7 += snprintf ( V_228 + V_7 , V_236 - V_7 ,
L_49 , V_226 , V_233 ) ;
break;
case V_241 :
F_59 ( V_230 , V_226 , & V_232 ) ;
V_7 += snprintf ( V_228 + V_7 , V_236 - V_7 ,
L_50 , V_226 , V_232 ) ;
break;
case V_242 :
F_60 ( V_230 , V_226 , & V_231 ) ;
V_7 += snprintf ( V_228 + V_7 , V_236 - V_7 ,
L_51 , V_226 , V_231 ) ;
break;
case V_243 :
goto V_244;
break;
default:
V_7 = 0 ;
break;
}
return F_39 ( V_3 , V_167 , V_168 , V_228 , V_7 ) ;
V_244:
V_223 = V_215 . V_224 . V_245 ;
V_224 = V_223 ;
V_7 += snprintf ( V_228 + V_7 , V_236 - V_7 ,
L_52 , V_223 ) ;
while ( V_6 > 0 ) {
F_60 ( V_230 , V_224 , & V_231 ) ;
V_7 += snprintf ( V_228 + V_7 , V_236 - V_7 ,
L_53 , V_231 ) ;
V_224 += sizeof( T_1 ) ;
if ( V_224 >= V_236 ) {
V_7 += snprintf ( V_228 + V_7 ,
V_236 - V_7 , L_38 ) ;
break;
}
V_6 -= sizeof( T_1 ) ;
if ( ! V_6 )
V_7 += snprintf ( V_228 + V_7 , V_236 - V_7 ,
L_38 ) ;
else if ( ! ( V_6 % ( 8 * sizeof( T_1 ) ) ) ) {
V_223 += ( 8 * sizeof( T_1 ) ) ;
V_7 += snprintf ( V_228 + V_7 , V_236 - V_7 ,
L_54 , V_223 ) ;
}
}
if ( V_6 == 0 ) {
V_215 . V_224 . V_245 += V_225 ;
if ( V_215 . V_224 . V_245 >= V_236 )
V_215 . V_224 . V_245 = 0 ;
} else
V_215 . V_224 . V_245 = 0 ;
return F_39 ( V_3 , V_167 , V_168 , V_228 , V_7 ) ;
}
static T_2
F_61 ( struct V_146 * V_146 , const char T_3 * V_3 ,
T_4 V_167 , T_5 * V_168 )
{
struct V_148 * V_149 = V_146 -> V_154 ;
struct V_26 * V_27 = (struct V_26 * ) V_149 -> V_147 ;
T_1 V_226 , V_246 , V_227 ;
T_1 V_231 ;
T_6 V_232 ;
T_7 V_233 ;
struct V_229 * V_230 ;
int V_150 ;
V_230 = V_27 -> V_234 ;
if ( ! V_230 )
return - V_209 ;
V_149 -> V_213 = V_214 ;
V_150 = F_49 ( V_3 , V_167 , & V_215 . V_216 ) ;
if ( V_150 < 0 )
return V_150 ;
if ( V_215 . V_216 . V_210 == V_237 ) {
if ( V_150 != V_247 )
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
if ( V_150 != V_249 )
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
F_62 ( V_230 , V_226 ,
( T_7 ) V_246 ) ;
if ( V_215 . V_216 . V_210 == V_218 ) {
V_150 = F_58 ( V_230 , V_226 , & V_233 ) ;
if ( ! V_150 ) {
V_233 |= ( T_7 ) V_246 ;
F_62 ( V_230 , V_226 ,
V_233 ) ;
}
}
if ( V_215 . V_216 . V_210 == V_219 ) {
V_150 = F_58 ( V_230 , V_226 , & V_233 ) ;
if ( ! V_150 ) {
V_233 &= ( T_7 ) ( ~ V_246 ) ;
F_62 ( V_230 , V_226 ,
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
F_63 ( V_230 , V_226 ,
( T_6 ) V_246 ) ;
if ( V_215 . V_216 . V_210 == V_218 ) {
V_150 = F_59 ( V_230 , V_226 , & V_232 ) ;
if ( ! V_150 ) {
V_232 |= ( T_6 ) V_246 ;
F_63 ( V_230 , V_226 ,
V_232 ) ;
}
}
if ( V_215 . V_216 . V_210 == V_219 ) {
V_150 = F_59 ( V_230 , V_226 , & V_232 ) ;
if ( ! V_150 ) {
V_232 &= ( T_6 ) ( ~ V_246 ) ;
F_63 ( V_230 , V_226 ,
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
F_64 ( V_230 , V_226 , V_246 ) ;
if ( V_215 . V_216 . V_210 == V_218 ) {
V_150 = F_60 ( V_230 , V_226 ,
& V_231 ) ;
if ( ! V_150 ) {
V_231 |= V_246 ;
F_64 ( V_230 , V_226 ,
V_231 ) ;
}
}
if ( V_215 . V_216 . V_210 == V_219 ) {
V_150 = F_60 ( V_230 , V_226 ,
& V_231 ) ;
if ( ! V_150 ) {
V_231 &= ~ V_246 ;
F_64 ( V_230 , V_226 ,
V_231 ) ;
}
}
}
} else
goto V_248;
return V_167 ;
V_248:
memset ( & V_215 , 0 , sizeof( V_215 ) ) ;
return - V_201 ;
}
static T_2
F_65 ( struct V_146 * V_146 , char T_3 * V_3 , T_4 V_167 ,
T_5 * V_168 )
{
struct V_148 * V_149 = V_146 -> V_154 ;
struct V_26 * V_27 = (struct V_26 * ) V_149 -> V_147 ;
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
V_149 -> V_213 = V_235 ;
if ( ! V_149 -> V_12 )
V_149 -> V_12 = F_2 ( V_257 , V_14 ) ;
if ( ! V_149 -> V_12 )
return 0 ;
V_228 = V_149 -> V_12 ;
if ( * V_168 )
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
V_256 = F_66 ( V_263 , & V_27 -> V_264 . V_265 ) ;
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
L_55 , V_251 , V_231 ) ;
} else
goto V_275;
return F_39 ( V_3 , V_167 , V_168 , V_228 , V_7 ) ;
V_275:
V_223 = V_215 . V_224 . V_245 ;
V_251 = V_223 ;
V_7 += snprintf ( V_228 + V_7 , V_257 - V_7 ,
L_56 , V_223 ) ;
V_6 = V_276 ;
while ( V_6 > 0 ) {
V_231 = F_17 ( V_255 + V_251 ) ;
V_7 += snprintf ( V_228 + V_7 , V_257 - V_7 ,
L_53 , V_231 ) ;
V_251 += sizeof( T_1 ) ;
if ( V_253 == V_277 ) {
if ( V_251 >= V_254 ) {
V_7 += snprintf ( V_228 + V_7 ,
V_257 - V_7 , L_38 ) ;
break;
}
} else {
if ( V_251 >= V_224 +
( V_253 * sizeof( T_1 ) ) ) {
V_7 += snprintf ( V_228 + V_7 ,
V_257 - V_7 , L_38 ) ;
break;
}
}
V_6 -= sizeof( T_1 ) ;
if ( ! V_6 )
V_7 += snprintf ( V_228 + V_7 ,
V_257 - V_7 , L_38 ) ;
else if ( ! ( V_6 % ( 8 * sizeof( T_1 ) ) ) ) {
V_223 += ( 8 * sizeof( T_1 ) ) ;
V_7 += snprintf ( V_228 + V_7 ,
V_257 - V_7 ,
L_57 , V_223 ) ;
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
return F_39 ( V_3 , V_167 , V_168 , V_228 , V_7 ) ;
}
static T_2
F_67 ( struct V_146 * V_146 , const char T_3 * V_3 ,
T_4 V_167 , T_5 * V_168 )
{
struct V_148 * V_149 = V_146 -> V_154 ;
struct V_26 * V_27 = (struct V_26 * ) V_149 -> V_147 ;
T_1 V_252 , V_254 , V_224 , V_246 , V_253 ;
struct V_229 * V_230 ;
void T_8 * V_255 ;
T_1 V_256 ;
T_1 V_231 ;
int V_150 ;
V_230 = V_27 -> V_234 ;
if ( ! V_230 )
return - V_209 ;
V_149 -> V_213 = V_214 ;
V_150 = F_49 ( V_3 , V_167 , & V_215 . V_216 ) ;
if ( V_150 < 0 )
return V_150 ;
V_256 = F_66 ( V_263 , & V_27 -> V_264 . V_265 ) ;
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
if ( V_150 != V_282 )
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
if ( V_150 != V_286 )
goto V_248;
V_253 = V_274 ;
V_246 = V_215 . V_216 . V_212 [ V_287 ] ;
if ( V_215 . V_216 . V_210 == V_283 ) {
F_68 ( V_246 , V_255 + V_224 ) ;
F_17 ( V_255 + V_224 ) ;
}
if ( V_215 . V_216 . V_210 == V_284 ) {
V_231 = F_17 ( V_255 + V_224 ) ;
V_231 |= V_246 ;
F_68 ( V_231 , V_255 + V_224 ) ;
F_17 ( V_255 + V_224 ) ;
}
if ( V_215 . V_216 . V_210 == V_285 ) {
V_231 = F_17 ( V_255 + V_224 ) ;
V_231 &= ~ V_246 ;
F_68 ( V_231 , V_255 + V_224 ) ;
F_17 ( V_255 + V_224 ) ;
}
} else
goto V_248;
return V_167 ;
V_248:
memset ( & V_215 , 0 , sizeof( V_215 ) ) ;
return - V_201 ;
}
static T_2
F_69 ( struct V_146 * V_146 , char T_3 * V_3 , T_4 V_167 ,
T_5 * V_168 )
{
struct V_148 * V_149 = V_146 -> V_154 ;
struct V_26 * V_27 = (struct V_26 * ) V_149 -> V_147 ;
int V_7 = 0 , V_288 ;
char * V_228 ;
if ( ! V_149 -> V_12 )
V_149 -> V_12 = F_2 ( V_289 , V_14 ) ;
if ( ! V_149 -> V_12 )
return 0 ;
V_228 = V_149 -> V_12 ;
if ( * V_168 )
return 0 ;
V_7 += snprintf ( V_228 + V_7 , V_289 - V_7 ,
L_58 ) ;
if ( V_27 -> V_264 . V_290 ) {
V_7 += snprintf ( V_228 + V_7 , V_289 - V_7 ,
L_59
L_60
L_61 ,
V_27 -> V_264 . V_290 -> V_291 ,
V_27 -> V_264 . V_290 -> V_61 ,
V_27 -> V_264 . V_290 -> V_292 ,
V_27 -> V_264 . V_290 -> V_293 ,
V_27 -> V_264 . V_290 -> V_294 ) ;
}
V_7 += snprintf ( V_228 + V_7 , V_289 - V_7 ,
L_62 ) ;
if ( V_27 -> V_264 . V_295 ) {
for ( V_288 = 0 ; V_288 < V_27 -> V_296 ;
V_288 ++ ) {
if ( V_27 -> V_264 . V_295 [ V_288 ] ) {
V_7 += snprintf ( V_228 + V_7 ,
V_289 - V_7 ,
L_59
L_60
L_63 ,
V_27 -> V_264 . V_295 [ V_288 ] -> V_291 ,
V_27 -> V_264 . V_295 [ V_288 ] -> V_61 ,
V_27 -> V_264 . V_295 [ V_288 ] -> V_292 ,
V_27 -> V_264 . V_295 [ V_288 ] -> V_293 ,
V_27 -> V_264 . V_295 [ V_288 ] -> V_294 ) ;
}
}
}
V_7 += snprintf ( V_228 + V_7 , V_289 - V_7 , L_38 ) ;
V_7 += snprintf ( V_228 + V_7 , V_289 - V_7 ,
L_64 ) ;
if ( V_27 -> V_264 . V_297 ) {
V_7 += snprintf ( V_228 + V_7 , V_289 - V_7 ,
L_65 ,
V_27 -> V_264 . V_297 -> V_298 ) ;
V_7 += snprintf ( V_228 + V_7 , V_289 - V_7 ,
L_66
L_60
L_61 ,
V_27 -> V_264 . V_297 -> V_291 ,
V_27 -> V_264 . V_297 -> V_61 ,
V_27 -> V_264 . V_297 -> V_292 ,
V_27 -> V_264 . V_297 -> V_293 ,
V_27 -> V_264 . V_297 -> V_294 ) ;
}
V_7 += snprintf ( V_228 + V_7 , V_289 - V_7 ,
L_67 ) ;
if ( V_27 -> V_264 . V_299 ) {
V_7 += snprintf ( V_228 + V_7 , V_289 - V_7 ,
L_65 ,
V_27 -> V_264 . V_299 -> V_298 ) ;
V_7 += snprintf ( V_228 + V_7 , V_289 - V_7 ,
L_68
L_60
L_61 ,
V_27 -> V_264 . V_299 -> V_291 ,
V_27 -> V_264 . V_299 -> V_61 ,
V_27 -> V_264 . V_299 -> V_292 ,
V_27 -> V_264 . V_299 -> V_293 ,
V_27 -> V_264 . V_299 -> V_294 ) ;
}
V_7 += snprintf ( V_228 + V_7 , V_289 - V_7 ,
L_69 ) ;
V_288 = 0 ;
if ( V_27 -> V_264 . V_300 ) {
do {
if ( V_27 -> V_264 . V_300 [ V_288 ] ) {
V_7 += snprintf ( V_228 + V_7 ,
V_289 - V_7 ,
L_65 ,
V_27 -> V_264 . V_300 [ V_288 ] -> V_298 ) ;
V_7 += snprintf ( V_228 + V_7 ,
V_289 - V_7 ,
L_66
L_60
L_63 ,
V_27 -> V_264 . V_300 [ V_288 ] -> V_291 ,
V_27 -> V_264 . V_300 [ V_288 ] -> V_61 ,
V_27 -> V_264 . V_300 [ V_288 ] -> V_292 ,
V_27 -> V_264 . V_300 [ V_288 ] -> V_293 ,
V_27 -> V_264 . V_300 [ V_288 ] -> V_294 ) ;
}
} while ( ++ V_288 < V_27 -> V_296 );
V_7 += snprintf ( V_228 + V_7 ,
V_289 - V_7 , L_38 ) ;
}
V_7 += snprintf ( V_228 + V_7 , V_289 - V_7 ,
L_70 ) ;
if ( V_27 -> V_264 . V_301 ) {
V_7 += snprintf ( V_228 + V_7 , V_289 - V_7 ,
L_71 ,
V_27 -> V_264 . V_301 -> V_298 ) ;
V_7 += snprintf ( V_228 + V_7 , V_289 - V_7 ,
L_72
L_60
L_61 ,
V_27 -> V_264 . V_301 -> V_291 ,
V_27 -> V_264 . V_301 -> V_61 ,
V_27 -> V_264 . V_301 -> V_292 ,
V_27 -> V_264 . V_301 -> V_293 ,
V_27 -> V_264 . V_301 -> V_294 ) ;
}
V_7 += snprintf ( V_228 + V_7 , V_289 - V_7 ,
L_73 ) ;
if ( V_27 -> V_264 . V_302 ) {
V_7 += snprintf ( V_228 + V_7 , V_289 - V_7 ,
L_71 ,
V_27 -> V_264 . V_302 -> V_298 ) ;
V_7 += snprintf ( V_228 + V_7 , V_289 - V_7 ,
L_72
L_60
L_61 ,
V_27 -> V_264 . V_302 -> V_291 ,
V_27 -> V_264 . V_302 -> V_61 ,
V_27 -> V_264 . V_302 -> V_292 ,
V_27 -> V_264 . V_302 -> V_293 ,
V_27 -> V_264 . V_302 -> V_294 ) ;
}
V_7 += snprintf ( V_228 + V_7 , V_289 - V_7 ,
L_74 ) ;
if ( V_27 -> V_264 . V_303 ) {
for ( V_288 = 0 ; V_288 < V_27 -> V_304 ;
V_288 ++ ) {
if ( ! V_27 -> V_264 . V_303 [ V_288 ] )
continue;
V_7 += snprintf ( V_228 + V_7 ,
V_289 - V_7 ,
L_71 ,
V_27 -> V_264 . V_303 [ V_288 ] -> V_298 ) ;
V_7 += snprintf ( V_228 + V_7 ,
V_289 - V_7 ,
L_72
L_75
L_63 ,
V_27 -> V_264 . V_303 [ V_288 ] -> V_291 ,
V_27 -> V_264 . V_303 [ V_288 ] -> V_61 ,
V_27 -> V_264 . V_303 [ V_288 ] -> V_292 ,
V_27 -> V_264 . V_303 [ V_288 ] -> V_293 ,
V_27 -> V_264 . V_303 [ V_288 ] -> V_294 ) ;
}
V_7 += snprintf ( V_228 + V_7 ,
V_289 - V_7 , L_38 ) ;
}
V_7 += snprintf ( V_228 + V_7 , V_289 - V_7 ,
L_76 ) ;
if ( V_27 -> V_264 . V_305 && V_27 -> V_264 . V_306 ) {
V_7 += snprintf ( V_228 + V_7 , V_289 - V_7 ,
L_71 ,
V_27 -> V_264 . V_305 -> V_298 ) ;
V_7 += snprintf ( V_228 + V_7 , V_289 - V_7 ,
L_77
L_60
L_63 ,
V_27 -> V_264 . V_305 -> V_291 ,
V_27 -> V_264 . V_305 -> V_61 ,
V_27 -> V_264 . V_305 -> V_292 ,
V_27 -> V_264 . V_305 -> V_293 ,
V_27 -> V_264 . V_305 -> V_294 ) ;
V_7 += snprintf ( V_228 + V_7 , V_289 - V_7 ,
L_78
L_60
L_63 ,
V_27 -> V_264 . V_306 -> V_291 ,
V_27 -> V_264 . V_306 -> V_61 ,
V_27 -> V_264 . V_306 -> V_292 ,
V_27 -> V_264 . V_306 -> V_293 ,
V_27 -> V_264 . V_306 -> V_294 ) ;
}
return F_39 ( V_3 , V_167 , V_168 , V_228 , V_7 ) ;
}
static int
F_70 ( struct V_307 * V_308 , int V_6 , int V_227 )
{
if ( ( V_227 != 1 ) && ( V_227 != V_309 ) )
return - V_201 ;
if ( V_6 > V_308 -> V_61 - 1 )
return - V_201 ;
return 0 ;
}
static int
F_71 ( char * V_228 , int V_7 , struct V_307 * V_310 ,
T_1 V_6 )
{
int V_224 , V_311 ;
T_1 * V_312 ;
if ( ! V_228 || ! V_310 )
return 0 ;
V_311 = V_310 -> V_292 ;
V_7 += snprintf ( V_228 + V_7 , V_313 - V_7 ,
L_79 , V_6 ) ;
V_224 = 0 ;
V_312 = V_310 -> V_314 [ V_6 ] . V_315 ;
while ( V_311 > 0 ) {
V_7 += snprintf ( V_228 + V_7 , V_313 - V_7 ,
L_53 , * V_312 ) ;
V_312 ++ ;
V_224 += sizeof( T_1 ) ;
V_311 -= sizeof( T_1 ) ;
if ( V_311 > 0 && ! ( V_224 % ( 4 * sizeof( T_1 ) ) ) )
V_7 += snprintf ( V_228 + V_7 ,
V_313 - V_7 , L_38 ) ;
}
V_7 += snprintf ( V_228 + V_7 , V_313 - V_7 , L_38 ) ;
return V_7 ;
}
static T_2
F_72 ( struct V_146 * V_146 , char T_3 * V_3 , T_4 V_167 ,
T_5 * V_168 )
{
struct V_148 * V_149 = V_146 -> V_154 ;
T_1 V_316 , V_6 , V_227 ;
struct V_307 * V_310 = NULL ;
char * V_228 ;
int V_7 = 0 ;
V_149 -> V_213 = V_235 ;
if ( ! V_149 -> V_12 )
V_149 -> V_12 = F_2 ( V_313 , V_14 ) ;
if ( ! V_149 -> V_12 )
return 0 ;
V_228 = V_149 -> V_12 ;
if ( * V_168 )
return 0 ;
if ( V_215 . V_216 . V_210 == V_317 ) {
V_6 = V_215 . V_216 . V_212 [ V_318 ] ;
V_227 = V_215 . V_216 . V_212 [ V_319 ] ;
V_310 = (struct V_307 * ) V_215 . V_320 ;
} else
return 0 ;
if ( V_227 == V_309 )
goto V_321;
V_7 = F_71 ( V_228 , V_7 , V_310 , V_6 ) ;
return F_39 ( V_3 , V_167 , V_168 , V_228 , V_7 ) ;
V_321:
V_316 = V_215 . V_224 . V_245 ;
V_6 = V_316 ;
while ( V_7 < V_322 - V_310 -> V_292 ) {
V_7 = F_71 ( V_228 , V_7 , V_310 , V_6 ) ;
V_6 ++ ;
if ( V_6 > V_310 -> V_61 - 1 )
break;
}
if ( V_6 > V_310 -> V_61 - 1 )
V_6 = 0 ;
V_215 . V_224 . V_245 = V_6 ;
return F_39 ( V_3 , V_167 , V_168 , V_228 , V_7 ) ;
}
static T_2
F_73 ( struct V_146 * V_146 , const char T_3 * V_3 ,
T_4 V_167 , T_5 * V_168 )
{
struct V_148 * V_149 = V_146 -> V_154 ;
struct V_26 * V_27 = (struct V_26 * ) V_149 -> V_147 ;
T_1 V_323 , V_324 , V_325 , V_6 , V_227 , V_224 , V_246 ;
T_1 * V_312 ;
struct V_307 * V_310 ;
int V_150 ;
V_149 -> V_213 = V_214 ;
V_150 = F_49 ( V_3 , V_167 , & V_215 . V_216 ) ;
if ( V_150 < 0 )
return V_150 ;
V_324 = V_215 . V_216 . V_212 [ V_326 ] ;
V_325 = V_215 . V_216 . V_212 [ V_327 ] ;
V_6 = V_215 . V_216 . V_212 [ V_318 ] ;
V_227 = V_215 . V_216 . V_212 [ V_319 ] ;
V_224 = V_215 . V_216 . V_212 [ V_328 ] ;
V_246 = V_215 . V_216 . V_212 [ V_329 ] ;
if ( V_215 . V_216 . V_210 == V_220 ||
V_215 . V_216 . V_210 == V_221 ||
V_215 . V_216 . V_210 == V_222 ) {
if ( V_150 != V_330 )
goto V_248;
if ( V_227 != 1 )
goto V_248;
} else if ( V_215 . V_216 . V_210 == V_317 ) {
if ( V_150 != V_331 )
goto V_248;
} else
goto V_248;
switch ( V_324 ) {
case V_332 :
if ( V_27 -> V_264 . V_290 &&
V_27 -> V_264 . V_290 -> V_291 == V_325 ) {
V_150 = F_70 (
V_27 -> V_264 . V_290 , V_6 , V_227 ) ;
if ( V_150 )
goto V_248;
V_215 . V_320 = V_27 -> V_264 . V_290 ;
goto V_333;
}
if ( V_27 -> V_264 . V_295 ) {
for ( V_323 = 0 ; V_323 < V_27 -> V_296 ; V_323 ++ ) {
if ( V_27 -> V_264 . V_295 [ V_323 ] &&
V_27 -> V_264 . V_295 [ V_323 ] -> V_291 ==
V_325 ) {
V_150 = F_70 (
V_27 -> V_264 . V_295 [ V_323 ] ,
V_6 , V_227 ) ;
if ( V_150 )
goto V_248;
V_215 . V_320 =
V_27 -> V_264 . V_295 [ V_323 ] ;
goto V_333;
}
}
}
goto V_248;
break;
case V_334 :
if ( V_27 -> V_264 . V_297 &&
V_27 -> V_264 . V_297 -> V_291 == V_325 ) {
V_150 = F_70 (
V_27 -> V_264 . V_297 , V_6 , V_227 ) ;
if ( V_150 )
goto V_248;
V_215 . V_320 = V_27 -> V_264 . V_297 ;
goto V_333;
}
if ( V_27 -> V_264 . V_299 &&
V_27 -> V_264 . V_299 -> V_291 == V_325 ) {
V_150 = F_70 (
V_27 -> V_264 . V_299 , V_6 , V_227 ) ;
if ( V_150 )
goto V_248;
V_215 . V_320 = V_27 -> V_264 . V_299 ;
goto V_333;
}
if ( V_27 -> V_264 . V_300 ) {
V_323 = 0 ;
do {
if ( V_27 -> V_264 . V_300 [ V_323 ] &&
V_27 -> V_264 . V_300 [ V_323 ] -> V_291 ==
V_325 ) {
V_150 = F_70 (
V_27 -> V_264 . V_300 [ V_323 ] ,
V_6 , V_227 ) ;
if ( V_150 )
goto V_248;
V_215 . V_320 =
V_27 -> V_264 . V_300 [ V_323 ] ;
goto V_333;
}
} while ( ++ V_323 < V_27 -> V_296 );
}
goto V_248;
break;
case V_335 :
if ( V_27 -> V_264 . V_301 &&
V_27 -> V_264 . V_301 -> V_291 == V_325 ) {
V_150 = F_70 (
V_27 -> V_264 . V_301 , V_6 , V_227 ) ;
if ( V_150 )
goto V_248;
V_215 . V_320 = V_27 -> V_264 . V_301 ;
goto V_333;
}
goto V_248;
break;
case V_336 :
if ( V_27 -> V_264 . V_302 &&
V_27 -> V_264 . V_302 -> V_291 == V_325 ) {
V_150 = F_70 (
V_27 -> V_264 . V_302 , V_6 , V_227 ) ;
if ( V_150 )
goto V_248;
V_215 . V_320 = V_27 -> V_264 . V_302 ;
goto V_333;
}
if ( V_27 -> V_264 . V_303 ) {
for ( V_323 = 0 ; V_323 < V_27 -> V_304 ; V_323 ++ ) {
if ( ! V_27 -> V_264 . V_303 [ V_323 ] )
continue;
if ( V_27 -> V_264 . V_303 [ V_323 ] -> V_291 ==
V_325 ) {
V_150 = F_70 (
V_27 -> V_264 . V_303 [ V_323 ] ,
V_6 , V_227 ) ;
if ( V_150 )
goto V_248;
V_215 . V_320 =
V_27 -> V_264 . V_303 [ V_323 ] ;
goto V_333;
}
}
}
goto V_248;
break;
case V_337 :
if ( V_27 -> V_264 . V_305 &&
V_27 -> V_264 . V_305 -> V_291 == V_325 ) {
V_150 = F_70 (
V_27 -> V_264 . V_305 , V_6 , V_227 ) ;
if ( V_150 )
goto V_248;
V_215 . V_320 = V_27 -> V_264 . V_305 ;
goto V_333;
}
if ( V_27 -> V_264 . V_306 &&
V_27 -> V_264 . V_306 -> V_291 == V_325 ) {
V_150 = F_70 (
V_27 -> V_264 . V_306 , V_6 , V_227 ) ;
if ( V_150 )
goto V_248;
V_215 . V_320 = V_27 -> V_264 . V_306 ;
goto V_333;
}
goto V_248;
break;
default:
goto V_248;
break;
}
V_333:
if ( V_215 . V_216 . V_210 == V_317 ) {
if ( V_227 == V_309 )
V_215 . V_224 . V_245 = V_6 ;
}
if ( V_215 . V_216 . V_210 == V_220 ||
V_215 . V_216 . V_210 == V_221 ||
V_215 . V_216 . V_210 == V_222 ) {
V_310 = (struct V_307 * ) V_215 . V_320 ;
if ( V_224 > V_310 -> V_292 / sizeof( T_1 ) - 1 )
goto V_248;
V_312 = V_310 -> V_314 [ V_6 ] . V_315 ;
V_312 += V_224 ;
if ( V_215 . V_216 . V_210 == V_220 )
* V_312 = V_246 ;
if ( V_215 . V_216 . V_210 == V_221 )
* V_312 |= V_246 ;
if ( V_215 . V_216 . V_210 == V_222 )
* V_312 &= ~ V_246 ;
}
return V_167 ;
V_248:
memset ( & V_215 , 0 , sizeof( V_215 ) ) ;
return - V_201 ;
}
static int
F_74 ( struct V_26 * V_27 , char * V_228 ,
int V_7 , T_1 V_338 )
{
if ( ! V_228 )
return 0 ;
switch ( V_338 ) {
case V_339 :
V_7 += snprintf ( V_228 + V_7 , V_340 - V_7 ,
L_80 ,
F_17 ( V_27 -> V_264 . V_341 ) ) ;
break;
case V_342 :
V_7 += snprintf ( V_228 + V_7 , V_340 - V_7 ,
L_81 ,
F_17 ( V_27 -> V_264 . V_343 ) ) ;
break;
case V_344 :
V_7 += snprintf ( V_228 + V_7 , V_340 - V_7 ,
L_82 ,
F_17 ( V_27 -> V_264 . V_345 ) ) ;
break;
case V_346 :
V_7 += snprintf ( V_228 + V_7 , V_340 - V_7 ,
L_83 ,
F_17 ( V_27 -> V_264 . V_347 ) ) ;
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
T_1 V_348 , V_5 ;
char * V_228 ;
int V_7 = 0 ;
V_149 -> V_213 = V_235 ;
if ( ! V_149 -> V_12 )
V_149 -> V_12 = F_2 ( V_340 , V_14 ) ;
if ( ! V_149 -> V_12 )
return 0 ;
V_228 = V_149 -> V_12 ;
if ( * V_168 )
return 0 ;
if ( V_215 . V_216 . V_210 == V_349 )
V_348 = V_215 . V_216 . V_212 [ V_350 ] ;
else
return 0 ;
if ( V_348 == V_351 )
for ( V_5 = 1 ; V_5 <= V_352 ; V_5 ++ )
V_7 = F_74 ( V_27 ,
V_228 , V_7 , V_5 ) ;
else
V_7 = F_74 ( V_27 ,
V_228 , V_7 , V_348 ) ;
return F_39 ( V_3 , V_167 , V_168 , V_228 , V_7 ) ;
}
static T_2
F_76 ( struct V_146 * V_146 , const char T_3 * V_3 ,
T_4 V_167 , T_5 * V_168 )
{
struct V_148 * V_149 = V_146 -> V_154 ;
struct V_26 * V_27 = (struct V_26 * ) V_149 -> V_147 ;
T_1 V_348 , V_246 , V_353 = 0 ;
void T_8 * V_354 ;
int V_150 ;
V_149 -> V_213 = V_214 ;
V_150 = F_49 ( V_3 , V_167 , & V_215 . V_216 ) ;
if ( V_150 < 0 )
return V_150 ;
V_348 = V_215 . V_216 . V_212 [ V_350 ] ;
V_246 = V_215 . V_216 . V_212 [ V_355 ] ;
if ( V_215 . V_216 . V_210 == V_356 ||
V_215 . V_216 . V_210 == V_357 ||
V_215 . V_216 . V_210 == V_358 ) {
if ( V_150 != V_359 )
goto V_248;
if ( V_348 > V_352 )
goto V_248;
} else if ( V_215 . V_216 . V_210 == V_349 ) {
if ( V_150 != V_360 )
goto V_248;
if ( ( V_348 > V_352 ) &&
( V_348 != V_351 ) )
goto V_248;
} else
goto V_248;
if ( V_215 . V_216 . V_210 == V_356 ||
V_215 . V_216 . V_210 == V_357 ||
V_215 . V_216 . V_210 == V_358 ) {
switch ( V_348 ) {
case V_339 :
V_354 = V_27 -> V_264 . V_341 ;
break;
case V_342 :
V_354 = V_27 -> V_264 . V_343 ;
break;
case V_344 :
V_354 = V_27 -> V_264 . V_345 ;
break;
case V_346 :
V_354 = V_27 -> V_264 . V_347 ;
break;
default:
goto V_248;
}
if ( V_215 . V_216 . V_210 == V_356 )
V_353 = V_246 ;
if ( V_215 . V_216 . V_210 == V_357 ) {
V_353 = F_17 ( V_354 ) ;
V_353 |= V_246 ;
}
if ( V_215 . V_216 . V_210 == V_358 ) {
V_353 = F_17 ( V_354 ) ;
V_353 &= ~ V_246 ;
}
F_68 ( V_353 , V_354 ) ;
F_17 ( V_354 ) ;
}
return V_167 ;
V_248:
memset ( & V_215 , 0 , sizeof( V_215 ) ) ;
return - V_201 ;
}
static int
F_77 ( struct V_26 * V_27 , char * V_228 ,
int V_7 , T_1 V_361 )
{
if ( ! V_228 )
return 0 ;
switch ( V_361 ) {
case V_362 :
V_7 += snprintf ( V_228 + V_7 , V_363 - V_7 ,
L_84 ,
F_17 ( V_27 -> V_264 . V_268 +
V_364 ) ) ;
break;
case V_365 :
V_7 += snprintf ( V_228 + V_7 , V_363 - V_7 ,
L_85 ,
F_17 ( V_27 -> V_264 . V_268 +
V_366 ) ) ;
break;
case V_367 :
V_7 += snprintf ( V_228 + V_7 , V_363 - V_7 ,
L_86 ,
F_17 ( V_27 -> V_264 . V_268 +
V_368 ) ) ;
break;
case V_369 :
V_7 += snprintf ( V_228 + V_7 , V_363 - V_7 ,
L_87 ,
F_17 ( V_27 -> V_264 . V_268 +
V_370 ) ) ;
break;
case V_371 :
V_7 += snprintf ( V_228 + V_7 , V_363 - V_7 ,
L_88 ,
F_17 ( V_27 -> V_264 . V_268 +
V_372 ) ) ;
break;
case V_373 :
V_7 += snprintf ( V_228 + V_7 , V_363 - V_7 ,
L_89 ,
F_17 ( V_27 -> V_264 . V_268 +
V_374 ) ) ;
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
T_1 V_375 , V_5 ;
char * V_228 ;
int V_7 = 0 ;
V_149 -> V_213 = V_235 ;
if ( ! V_149 -> V_12 )
V_149 -> V_12 = F_2 ( V_363 , V_14 ) ;
if ( ! V_149 -> V_12 )
return 0 ;
V_228 = V_149 -> V_12 ;
if ( * V_168 )
return 0 ;
if ( V_215 . V_216 . V_210 == V_376 )
V_375 = V_215 . V_216 . V_212 [ V_377 ] ;
else
return 0 ;
if ( V_375 == V_378 )
for ( V_5 = 1 ; V_5 <= V_379 ; V_5 ++ )
V_7 = F_77 ( V_27 ,
V_228 , V_7 , V_5 ) ;
else
V_7 = F_77 ( V_27 ,
V_228 , V_7 , V_375 ) ;
return F_39 ( V_3 , V_167 , V_168 , V_228 , V_7 ) ;
}
static T_2
F_79 ( struct V_146 * V_146 , const char T_3 * V_3 ,
T_4 V_167 , T_5 * V_168 )
{
struct V_148 * V_149 = V_146 -> V_154 ;
struct V_26 * V_27 = (struct V_26 * ) V_149 -> V_147 ;
T_1 V_375 , V_246 , V_353 = 0 ;
void T_8 * V_380 ;
int V_150 ;
V_149 -> V_213 = V_214 ;
V_150 = F_49 ( V_3 , V_167 , & V_215 . V_216 ) ;
if ( V_150 < 0 )
return V_150 ;
V_375 = V_215 . V_216 . V_212 [ V_377 ] ;
V_246 = V_215 . V_216 . V_212 [ V_381 ] ;
if ( V_215 . V_216 . V_210 == V_382 ||
V_215 . V_216 . V_210 == V_383 ||
V_215 . V_216 . V_210 == V_384 ) {
if ( V_150 != V_385 )
goto V_248;
if ( V_375 > V_379 )
goto V_248;
} else if ( V_215 . V_216 . V_210 == V_376 ) {
if ( V_150 != V_386 )
goto V_248;
if ( ( V_375 > V_379 ) &&
( V_375 != V_378 ) )
goto V_248;
} else
goto V_248;
if ( V_215 . V_216 . V_210 == V_382 ||
V_215 . V_216 . V_210 == V_383 ||
V_215 . V_216 . V_210 == V_384 ) {
switch ( V_375 ) {
case V_362 :
V_380 = V_27 -> V_264 . V_268 +
V_364 ;
break;
case V_365 :
V_380 = V_27 -> V_264 . V_268 +
V_366 ;
break;
case V_367 :
V_380 = V_27 -> V_264 . V_268 +
V_368 ;
break;
case V_369 :
V_380 = V_27 -> V_264 . V_268 +
V_370 ;
break;
case V_371 :
V_380 = V_27 -> V_264 . V_268 +
V_372 ;
break;
case V_373 :
V_380 = V_27 -> V_264 . V_268 +
V_374 ;
break;
default:
goto V_248;
}
if ( V_215 . V_216 . V_210 == V_382 )
V_353 = V_246 ;
if ( V_215 . V_216 . V_210 == V_383 ) {
V_353 = F_17 ( V_380 ) ;
V_353 |= V_246 ;
}
if ( V_215 . V_216 . V_210 == V_384 ) {
V_353 = F_17 ( V_380 ) ;
V_353 &= ~ V_246 ;
}
F_68 ( V_353 , V_380 ) ;
F_17 ( V_380 ) ;
}
return V_167 ;
V_248:
memset ( & V_215 , 0 , sizeof( V_215 ) ) ;
return - V_201 ;
}
static int
F_80 ( struct V_26 * V_27 , char * V_228 )
{
T_1 V_387 , V_388 , V_389 , V_390 ;
int V_7 = 0 ;
V_390 = V_215 . V_216 . V_212 [ V_391 ] ;
V_387 = V_215 . V_216 . V_212 [ V_392 ] ;
V_388 = V_215 . V_216 . V_212 [ V_393 ] ;
V_389 = V_215 . V_216 . V_212 [ V_394 ] ;
V_7 += snprintf ( V_228 + V_7 , V_395 - V_7 ,
L_90 , V_387 ) ;
V_7 += snprintf ( V_228 + V_7 , V_395 - V_7 ,
L_91 , V_388 ) ;
V_7 += snprintf ( V_228 + V_7 , V_395 - V_7 ,
L_92 , V_389 ) ;
V_7 += snprintf ( V_228 + V_7 , V_395 - V_7 ,
L_93 , V_390 ) ;
return V_7 ;
}
static T_2
F_81 ( struct V_146 * V_146 , char T_3 * V_3 , T_4 V_167 ,
T_5 * V_168 )
{
struct V_148 * V_149 = V_146 -> V_154 ;
struct V_26 * V_27 = (struct V_26 * ) V_149 -> V_147 ;
char * V_228 ;
int V_7 = 0 ;
V_149 -> V_213 = V_235 ;
if ( ! V_149 -> V_12 )
V_149 -> V_12 = F_2 ( V_395 , V_14 ) ;
if ( ! V_149 -> V_12 )
return 0 ;
V_228 = V_149 -> V_12 ;
if ( * V_168 )
return 0 ;
if ( ( V_215 . V_216 . V_210 != V_396 ) &&
( V_215 . V_216 . V_210 != V_397 ) )
return 0 ;
V_7 = F_80 ( V_27 , V_228 ) ;
return F_39 ( V_3 , V_167 , V_168 , V_228 , V_7 ) ;
}
static T_2
F_82 ( struct V_146 * V_146 , const char T_3 * V_3 ,
T_4 V_167 , T_5 * V_168 )
{
struct V_148 * V_149 = V_146 -> V_154 ;
T_1 V_387 , V_388 , V_389 , V_390 ;
int V_150 ;
V_149 -> V_213 = V_214 ;
V_150 = F_49 ( V_3 , V_167 , & V_215 . V_216 ) ;
if ( V_150 < 0 )
return V_150 ;
V_390 = V_215 . V_216 . V_212 [ V_391 ] ;
V_387 = V_215 . V_216 . V_212 [ V_392 ] ;
V_388 = V_215 . V_216 . V_212 [ V_393 ] ;
V_389 = V_215 . V_216 . V_212 [ V_394 ] ;
if ( V_215 . V_216 . V_210 == V_396 ) {
if ( ! ( V_387 & V_398 ) )
goto V_248;
if ( ( V_387 & ~ V_398 ) &&
( V_387 != V_399 ) )
goto V_248;
if ( V_389 > sizeof( V_92 ) )
goto V_248;
} else if ( V_215 . V_216 . V_210 == V_397 ) {
if ( ! ( V_387 & V_400 ) )
goto V_248;
if ( ( V_387 & ~ V_400 ) &&
( V_387 != V_399 ) )
goto V_248;
if ( V_389 > ( V_401 ) / 4 )
goto V_248;
if ( V_390 != 0x9b )
goto V_248;
} else
goto V_248;
if ( V_389 == 0 )
goto V_248;
if ( V_150 != V_402 )
goto V_248;
if ( V_390 & ~ 0xff )
goto V_248;
if ( V_388 == 0 )
goto V_403;
return V_167 ;
V_403:
memset ( & V_215 , 0 , sizeof( V_215 ) ) ;
return V_167 ;
V_248:
memset ( & V_215 , 0 , sizeof( V_215 ) ) ;
return - V_201 ;
}
static int
F_83 ( struct V_26 * V_27 , char * V_228 , int V_7 )
{
T_6 V_404 , V_405 ;
V_7 += snprintf ( V_228 + V_7 , V_406 - V_7 ,
L_94 ) ;
V_7 += snprintf ( V_228 + V_7 , V_406 - V_7 ,
L_95 ) ;
F_84 ( V_27 , V_407 ,
& V_404 , & V_405 ) ;
V_7 += snprintf ( V_228 + V_7 , V_406 - V_7 ,
L_96 , V_404 , V_405 ) ;
V_7 += snprintf ( V_228 + V_7 , V_406 - V_7 ,
L_97 ) ;
F_84 ( V_27 , V_408 ,
& V_404 , & V_405 ) ;
V_7 += snprintf ( V_228 + V_7 , V_406 - V_7 ,
L_96 , V_404 , V_405 ) ;
V_7 += snprintf ( V_228 + V_7 , V_406 - V_7 ,
L_98 ) ;
F_84 ( V_27 , V_409 ,
& V_404 , & V_405 ) ;
V_7 += snprintf ( V_228 + V_7 , V_406 - V_7 ,
L_96 , V_404 , V_405 ) ;
V_7 += snprintf ( V_228 + V_7 , V_406 - V_7 ,
L_99 ) ;
F_84 ( V_27 , V_410 ,
& V_404 , & V_405 ) ;
V_7 += snprintf ( V_228 + V_7 , V_406 - V_7 ,
L_96 , V_404 , V_405 ) ;
return V_7 ;
}
static int
F_85 ( struct V_26 * V_27 , char * V_228 , int V_7 )
{
T_6 V_404 , V_405 ;
int V_150 ;
V_7 += snprintf ( V_228 + V_7 , V_406 - V_7 ,
L_100 ) ;
V_7 += snprintf ( V_228 + V_7 , V_406 - V_7 ,
L_101 ) ;
V_150 = F_86 ( V_27 , V_407 ,
& V_404 , & V_405 ) ;
if ( ! V_150 )
V_7 += snprintf ( V_228 + V_7 , V_406 - V_7 ,
L_102 ,
V_27 -> V_411 , V_404 , V_405 ) ;
else
V_7 += snprintf ( V_228 + V_7 , V_406 - V_7 ,
L_103 ) ;
V_7 += snprintf ( V_228 + V_7 , V_406 - V_7 ,
L_104 ) ;
V_150 = F_86 ( V_27 , V_408 ,
& V_404 , & V_405 ) ;
if ( ! V_150 )
V_7 += snprintf ( V_228 + V_7 , V_406 - V_7 ,
L_102 ,
V_27 -> V_411 , V_404 , V_405 ) ;
else
V_7 += snprintf ( V_228 + V_7 , V_406 - V_7 ,
L_103 ) ;
V_7 += snprintf ( V_228 + V_7 , V_406 - V_7 ,
L_105 ) ;
V_150 = F_86 ( V_27 , V_409 ,
& V_404 , & V_405 ) ;
if ( ! V_150 )
V_7 += snprintf ( V_228 + V_7 , V_406 - V_7 ,
L_102 ,
V_27 -> V_411 , V_404 , V_405 ) ;
else
V_7 += snprintf ( V_228 + V_7 , V_406 - V_7 ,
L_103 ) ;
V_7 += snprintf ( V_228 + V_7 , V_406 - V_7 ,
L_106 ) ;
V_150 = F_86 ( V_27 , V_410 ,
& V_404 , & V_405 ) ;
if ( ! V_150 )
V_7 += snprintf ( V_228 + V_7 , V_406 - V_7 ,
L_102 ,
V_27 -> V_411 , V_404 , V_405 ) ;
else
V_7 += snprintf ( V_228 + V_7 , V_406 - V_7 ,
L_103 ) ;
return V_7 ;
}
static int
F_87 ( struct V_26 * V_27 , char * V_228 , int V_7 )
{
struct V_412 * V_413 ;
int V_6 ;
V_7 += snprintf ( V_228 + V_7 , V_406 - V_7 ,
L_107 ) ;
V_7 += snprintf ( V_228 + V_7 , V_406 - V_7 ,
L_108 ) ;
V_6 = 0 ;
F_10 (rsrc_blks, &phba->lpfc_vpi_blk_list, list) {
V_7 += snprintf ( V_228 + V_7 , V_406 - V_7 ,
L_109 ,
V_6 , V_413 -> V_414 ,
V_413 -> V_415 ) ;
V_6 ++ ;
}
V_7 += snprintf ( V_228 + V_7 , V_406 - V_7 ,
L_110 ) ;
V_6 = 0 ;
F_10 (rsrc_blks, &phba->sli4_hba.lpfc_vfi_blk_list,
list) {
V_7 += snprintf ( V_228 + V_7 , V_406 - V_7 ,
L_109 ,
V_6 , V_413 -> V_414 ,
V_413 -> V_415 ) ;
V_6 ++ ;
}
V_7 += snprintf ( V_228 + V_7 , V_406 - V_7 ,
L_111 ) ;
V_6 = 0 ;
F_10 (rsrc_blks, &phba->sli4_hba.lpfc_rpi_blk_list,
list) {
V_7 += snprintf ( V_228 + V_7 , V_406 - V_7 ,
L_109 ,
V_6 , V_413 -> V_414 ,
V_413 -> V_415 ) ;
V_6 ++ ;
}
V_7 += snprintf ( V_228 + V_7 , V_406 - V_7 ,
L_112 ) ;
V_6 = 0 ;
F_10 (rsrc_blks, &phba->sli4_hba.lpfc_xri_blk_list,
list) {
V_7 += snprintf ( V_228 + V_7 , V_406 - V_7 ,
L_109 ,
V_6 , V_413 -> V_414 ,
V_413 -> V_415 ) ;
V_6 ++ ;
}
return V_7 ;
}
static T_2
F_88 ( struct V_146 * V_146 , const char T_3 * V_3 ,
T_4 V_167 , T_5 * V_168 )
{
struct V_148 * V_149 = V_146 -> V_154 ;
T_1 V_416 ;
int V_150 ;
V_149 -> V_213 = V_214 ;
V_150 = F_49 ( V_3 , V_167 , & V_215 . V_216 ) ;
if ( V_150 < 0 )
return V_150 ;
V_416 = V_215 . V_216 . V_212 [ V_417 ] ;
if ( V_215 . V_216 . V_210 != V_418 )
goto V_248;
if ( V_150 != V_419 )
goto V_248;
if ( ! ( V_416 & V_420 ) )
goto V_248;
return V_167 ;
V_248:
memset ( & V_215 , 0 , sizeof( V_215 ) ) ;
return - V_201 ;
}
static T_2
F_89 ( struct V_146 * V_146 , char T_3 * V_3 , T_4 V_167 ,
T_5 * V_168 )
{
struct V_148 * V_149 = V_146 -> V_154 ;
struct V_26 * V_27 = (struct V_26 * ) V_149 -> V_147 ;
char * V_228 ;
T_1 V_416 ;
int V_7 = 0 ;
V_149 -> V_213 = V_235 ;
if ( ! V_149 -> V_12 )
V_149 -> V_12 = F_2 ( V_406 , V_14 ) ;
if ( ! V_149 -> V_12 )
return 0 ;
V_228 = V_149 -> V_12 ;
if ( * V_168 )
return 0 ;
if ( V_215 . V_216 . V_210 != V_418 )
return 0 ;
V_416 = V_215 . V_216 . V_212 [ V_417 ] ;
if ( V_416 & V_421 )
V_7 = F_83 ( V_27 , V_228 , V_7 ) ;
if ( V_416 & V_422 )
V_7 = F_85 ( V_27 , V_228 , V_7 ) ;
if ( V_416 & V_423 )
V_7 = F_87 ( V_27 , V_228 , V_7 ) ;
return F_39 ( V_3 , V_167 , V_168 , V_228 , V_7 ) ;
}
void
F_90 ( struct V_26 * V_27 , enum V_424 V_425 ,
enum V_426 V_427 , enum V_428 V_429 ,
enum V_430 V_431 ,
struct V_45 * V_432 , T_1 V_433 )
{
#ifdef F_21
T_1 * V_390 , * V_387 , * V_388 , * V_389 ;
char V_434 [ V_435 ] ;
int V_7 = 0 ;
T_1 V_436 = 0 ;
T_1 * V_437 ;
T_1 V_5 ;
if ( V_215 . V_216 . V_210 != V_397 )
return;
V_390 = & V_215 . V_216 . V_212 [ V_391 ] ;
V_387 = & V_215 . V_216 . V_212 [ V_392 ] ;
V_388 = & V_215 . V_216 . V_212 [ V_393 ] ;
V_389 = & V_215 . V_216 . V_212 [ V_394 ] ;
if ( ! ( * V_387 & V_399 ) ||
( * V_388 == 0 ) ||
( * V_389 == 0 ) )
return;
if ( * V_390 != 0x9B )
return;
if ( ( V_427 == V_438 ) && ( V_429 == V_439 ) ) {
if ( * V_387 & V_440 ) {
V_436 |= V_440 ;
F_31 ( V_159 L_113
L_114 ,
V_431 , V_425 , V_433 ) ;
}
}
if ( ( V_427 == V_438 ) && ( V_429 == V_441 ) ) {
if ( * V_387 & V_442 ) {
V_436 |= V_442 ;
F_31 ( V_159 L_115
L_116 ,
V_431 , V_425 , V_433 ) ;
}
}
if ( ( V_427 == V_443 ) && ( V_429 == V_439 ) ) {
if ( * V_387 & V_444 ) {
V_436 |= V_444 ;
F_31 ( V_159 L_117
L_114 ,
V_431 , V_425 , V_433 ) ;
}
}
if ( ( V_427 == V_443 ) && ( V_429 == V_441 ) ) {
if ( * V_387 & V_445 ) {
V_436 |= V_445 ;
F_31 ( V_159 L_118
L_116 ,
V_431 , V_425 , V_433 ) ;
}
}
if ( V_436 ) {
V_437 = ( T_1 * ) V_432 -> V_74 ;
for ( V_5 = 0 ; V_5 < * V_389 ; V_5 ++ ) {
if ( ! ( V_5 % 8 ) ) {
if ( V_5 != 0 )
F_31 ( V_159 L_119 , V_434 ) ;
V_7 = 0 ;
V_7 += snprintf ( V_434 + V_7 ,
V_435 - V_7 ,
L_120 , V_5 ) ;
}
V_7 += snprintf ( V_434 + V_7 , V_435 - V_7 ,
L_53 , ( T_1 ) * V_437 ) ;
V_437 ++ ;
}
if ( ( V_5 - 1 ) % 8 )
F_31 ( V_159 L_119 , V_434 ) ;
( * V_388 ) -- ;
}
if ( * V_388 == 0 )
memset ( & V_215 , 0 , sizeof( V_215 ) ) ;
return;
#endif
}
void
F_91 ( struct V_26 * V_27 , V_92 * V_446 )
{
#ifdef F_21
T_1 * V_387 , * V_388 , * V_389 , * V_390 ;
char V_434 [ V_435 ] ;
int V_7 = 0 ;
T_1 * V_437 ;
T_7 * V_447 ;
T_1 V_5 , V_32 ;
if ( V_215 . V_216 . V_210 != V_396 )
return;
V_390 = & V_215 . V_216 . V_212 [ V_391 ] ;
V_387 = & V_215 . V_216 . V_212 [ V_392 ] ;
V_388 = & V_215 . V_216 . V_212 [ V_393 ] ;
V_389 = & V_215 . V_216 . V_212 [ V_394 ] ;
if ( ! ( * V_387 & V_398 ) ||
( * V_388 == 0 ) ||
( * V_389 == 0 ) )
return;
if ( ( * V_390 != V_448 ) &&
( * V_390 != V_446 -> V_449 ) )
return;
if ( * V_387 & V_450 ) {
F_31 ( V_159 L_121 ,
V_446 -> V_449 ) ;
V_437 = ( T_1 * ) V_446 ;
for ( V_5 = 0 ; V_5 < * V_389 ; V_5 ++ ) {
if ( ! ( V_5 % 8 ) ) {
if ( V_5 != 0 )
F_31 ( V_159 L_119 , V_434 ) ;
V_7 = 0 ;
memset ( V_434 , 0 , V_435 ) ;
V_7 += snprintf ( V_434 + V_7 ,
V_435 - V_7 ,
L_120 , V_5 ) ;
}
V_7 += snprintf ( V_434 + V_7 , V_435 - V_7 ,
L_53 ,
( ( T_1 ) * V_437 ) & 0xffffffff ) ;
V_437 ++ ;
}
if ( ( V_5 - 1 ) % 8 )
F_31 ( V_159 L_119 , V_434 ) ;
F_31 ( V_159 L_38 ) ;
}
if ( * V_387 & V_451 ) {
F_31 ( V_159 L_122 ,
V_446 -> V_449 ) ;
V_447 = ( T_7 * ) V_446 ;
for ( V_5 = 0 ; V_5 < * V_389 ; V_5 ++ ) {
if ( ! ( V_5 % 8 ) ) {
if ( V_5 != 0 )
F_31 ( V_159 L_119 , V_434 ) ;
V_7 = 0 ;
memset ( V_434 , 0 , V_435 ) ;
V_7 += snprintf ( V_434 + V_7 ,
V_435 - V_7 ,
L_120 , V_5 ) ;
}
for ( V_32 = 0 ; V_32 < 4 ; V_32 ++ ) {
V_7 += snprintf ( V_434 + V_7 ,
V_435 - V_7 ,
L_123 ,
( ( T_7 ) * V_447 ) & 0xff ) ;
V_447 ++ ;
}
V_7 += snprintf ( V_434 + V_7 ,
V_435 - V_7 , L_124 ) ;
}
if ( ( V_5 - 1 ) % 8 )
F_31 ( V_159 L_119 , V_434 ) ;
F_31 ( V_159 L_38 ) ;
}
( * V_388 ) -- ;
if ( * V_388 == 0 )
memset ( & V_215 , 0 , sizeof( V_215 ) ) ;
return;
#endif
}
inline void
F_92 ( struct V_1 * V_2 )
{
#ifdef F_21
struct V_26 * V_27 = V_2 -> V_27 ;
char V_114 [ 64 ] ;
T_1 V_452 , V_5 ;
if ( ! V_15 )
return;
if ( ! V_453 ) {
V_453 = F_93 ( L_125 , NULL ) ;
F_94 ( & V_454 , 0 ) ;
if ( ! V_453 ) {
F_95 ( V_2 , V_159 , V_195 ,
L_126 ) ;
goto V_455;
}
}
if ( ! V_21 )
V_21 = V_144 ;
snprintf ( V_114 , sizeof( V_114 ) , L_127 , V_27 -> V_411 ) ;
if ( ! V_27 -> V_456 ) {
V_27 -> V_456 =
F_93 ( V_114 , V_453 ) ;
if ( ! V_27 -> V_456 ) {
F_95 ( V_2 , V_159 , V_195 ,
L_128 ) ;
goto V_455;
}
F_96 ( & V_454 ) ;
F_94 ( & V_27 -> V_457 , 0 ) ;
snprintf ( V_114 , sizeof( V_114 ) , L_129 ) ;
V_27 -> V_458 =
F_97 ( V_114 , V_459 | V_460 | V_461 ,
V_27 -> V_456 ,
V_27 , & V_462 ) ;
if ( ! V_27 -> V_458 ) {
F_95 ( V_2 , V_159 , V_195 ,
L_130 ) ;
goto V_455;
}
if ( V_27 -> V_49 < V_463 ) {
snprintf ( V_114 , sizeof( V_114 ) , L_131 ) ;
V_27 -> V_464 =
F_97 ( V_114 ,
V_459 | V_460 | V_461 ,
V_27 -> V_456 ,
V_27 , & V_465 ) ;
if ( ! V_27 -> V_464 ) {
F_95 ( V_2 , V_159 , V_195 ,
L_132
L_133 ) ;
goto V_455;
}
} else
V_27 -> V_464 = NULL ;
if ( V_27 -> V_49 < V_463 ) {
snprintf ( V_114 , sizeof( V_114 ) , L_134 ) ;
V_27 -> V_466 =
F_97 ( V_114 ,
V_459 | V_460 | V_461 ,
V_27 -> V_456 ,
V_27 , & V_467 ) ;
if ( ! V_27 -> V_466 ) {
F_95 ( V_2 , V_159 , V_195 ,
L_135
L_136 ) ;
goto V_455;
}
} else
V_27 -> V_464 = NULL ;
snprintf ( V_114 , sizeof( V_114 ) , L_137 ) ;
V_27 -> V_468 =
F_97 ( V_114 , V_459 | V_460 | V_461 ,
V_27 -> V_456 ,
V_27 , & V_469 ) ;
if ( ! V_27 -> V_468 ) {
F_95 ( V_2 , V_159 , V_195 ,
L_138 ) ;
goto V_455;
}
snprintf ( V_114 , sizeof( V_114 ) , L_139 ) ;
V_27 -> V_470 =
F_97 ( V_114 , V_459 | V_460 | V_461 ,
V_27 -> V_456 ,
V_27 , & V_471 ) ;
if ( ! V_27 -> V_470 ) {
F_95 ( V_2 , V_159 , V_195 ,
L_140 ) ;
goto V_455;
}
snprintf ( V_114 , sizeof( V_114 ) , L_141 ) ;
V_27 -> V_192 =
F_97 ( V_114 , V_459 | V_460 | V_461 ,
V_27 -> V_456 ,
V_27 , & V_472 ) ;
if ( ! V_27 -> V_192 ) {
F_95 ( V_2 , V_159 , V_195 ,
L_142 ) ;
goto V_455;
}
V_27 -> V_193 = V_473 ;
snprintf ( V_114 , sizeof( V_114 ) , L_143 ) ;
V_27 -> V_187 =
F_97 ( V_114 , V_459 | V_460 | V_461 ,
V_27 -> V_456 ,
V_27 , & V_472 ) ;
if ( ! V_27 -> V_187 ) {
F_95 ( V_2 , V_159 , V_195 ,
L_144 ) ;
goto V_455;
}
snprintf ( V_114 , sizeof( V_114 ) , L_145 ) ;
V_27 -> V_189 =
F_97 ( V_114 , V_459 | V_460 | V_461 ,
V_27 -> V_456 ,
V_27 , & V_472 ) ;
if ( ! V_27 -> V_189 ) {
F_95 ( V_2 , V_159 , V_195 ,
L_146 ) ;
goto V_455;
}
snprintf ( V_114 , sizeof( V_114 ) , L_147 ) ;
V_27 -> V_175 =
F_97 ( V_114 , V_459 | V_460 | V_461 ,
V_27 -> V_456 ,
V_27 , & V_472 ) ;
if ( ! V_27 -> V_175 ) {
F_95 ( V_2 , V_159 , V_195 ,
L_148 ) ;
goto V_455;
}
snprintf ( V_114 , sizeof( V_114 ) , L_149 ) ;
V_27 -> V_177 =
F_97 ( V_114 , V_459 | V_460 | V_461 ,
V_27 -> V_456 ,
V_27 , & V_472 ) ;
if ( ! V_27 -> V_177 ) {
F_95 ( V_2 , V_159 , V_195 ,
L_150 ) ;
goto V_455;
}
snprintf ( V_114 , sizeof( V_114 ) , L_151 ) ;
V_27 -> V_179 =
F_97 ( V_114 , V_459 | V_460 | V_461 ,
V_27 -> V_456 ,
V_27 , & V_472 ) ;
if ( ! V_27 -> V_179 ) {
F_95 ( V_2 , V_159 , V_195 ,
L_152 ) ;
goto V_455;
}
snprintf ( V_114 , sizeof( V_114 ) , L_153 ) ;
V_27 -> V_181 =
F_97 ( V_114 , V_459 | V_460 | V_461 ,
V_27 -> V_456 ,
V_27 , & V_472 ) ;
if ( ! V_27 -> V_181 ) {
F_95 ( V_2 , V_159 , V_195 ,
L_154 ) ;
goto V_455;
}
snprintf ( V_114 , sizeof( V_114 ) , L_155 ) ;
V_27 -> V_183 =
F_97 ( V_114 , V_459 | V_460 | V_461 ,
V_27 -> V_456 ,
V_27 , & V_472 ) ;
if ( ! V_27 -> V_183 ) {
F_95 ( V_2 , V_159 , V_195 ,
L_156 ) ;
goto V_455;
}
snprintf ( V_114 , sizeof( V_114 ) , L_157 ) ;
V_27 -> V_185 =
F_97 ( V_114 , V_459 | V_460 | V_461 ,
V_27 -> V_456 ,
V_27 , & V_472 ) ;
if ( ! V_27 -> V_185 ) {
F_95 ( V_2 , V_159 , V_195 ,
L_158 ) ;
goto V_455;
}
if ( V_29 ) {
V_452 = V_29 - 1 ;
if ( V_452 & V_29 ) {
V_452 = V_29 ;
V_5 = 0 ;
while ( V_452 > 1 ) {
V_452 = V_452 >> 1 ;
V_5 ++ ;
}
V_29 = ( 1 << V_5 ) ;
F_31 ( V_159
L_159
L_160 , V_17 ) ;
}
}
snprintf ( V_114 , sizeof( V_114 ) , L_161 ) ;
V_27 -> V_474 =
F_97 ( V_114 , V_459 | V_460 | V_461 ,
V_27 -> V_456 ,
V_27 , & V_475 ) ;
if ( ! V_27 -> V_474 ) {
F_95 ( V_2 , V_159 , V_195 ,
L_162
L_163 ) ;
goto V_455;
}
if ( ! V_27 -> V_30 ) {
V_27 -> V_30 = F_2 (
( sizeof( struct V_10 ) *
V_29 ) ,
V_14 ) ;
if ( ! V_27 -> V_30 ) {
F_95 ( V_2 , V_159 , V_195 ,
L_164
L_165 ) ;
goto V_455;
}
F_94 ( & V_27 -> V_28 , 0 ) ;
memset ( V_27 -> V_30 , 0 ,
( sizeof( struct V_10 ) *
V_29 ) ) ;
}
}
snprintf ( V_114 , sizeof( V_114 ) , L_166 , V_2 -> V_476 ) ;
if ( ! V_2 -> V_477 ) {
V_2 -> V_477 =
F_93 ( V_114 , V_27 -> V_456 ) ;
if ( ! V_2 -> V_477 ) {
F_95 ( V_2 , V_159 , V_195 ,
L_167 ) ;
goto V_455;
}
F_96 ( & V_27 -> V_457 ) ;
}
if ( V_17 ) {
V_452 = V_17 - 1 ;
if ( V_452 & V_17 ) {
V_452 = V_17 ;
V_5 = 0 ;
while ( V_452 > 1 ) {
V_452 = V_452 >> 1 ;
V_5 ++ ;
}
V_17 = ( 1 << V_5 ) ;
F_31 ( V_159
L_168 ,
V_17 ) ;
}
}
V_2 -> V_18 = F_98 (
( sizeof( struct V_10 ) * V_17 ) ,
V_14 ) ;
if ( ! V_2 -> V_18 ) {
F_95 ( V_2 , V_159 , V_195 ,
L_169
L_170 ) ;
goto V_455;
}
F_94 ( & V_2 -> V_16 , 0 ) ;
snprintf ( V_114 , sizeof( V_114 ) , L_171 ) ;
V_2 -> V_478 =
F_97 ( V_114 , V_459 | V_460 | V_461 ,
V_2 -> V_477 ,
V_2 , & V_479 ) ;
if ( ! V_2 -> V_478 ) {
F_95 ( V_2 , V_159 , V_195 ,
L_172
L_173 ) ;
goto V_455;
}
snprintf ( V_114 , sizeof( V_114 ) , L_174 ) ;
V_2 -> V_480 =
F_97 ( V_114 , V_459 | V_460 | V_461 ,
V_2 -> V_477 ,
V_2 , & V_481 ) ;
if ( ! V_2 -> V_480 ) {
F_95 ( V_2 , V_159 , V_195 ,
L_175 ) ;
goto V_455;
}
if ( V_27 -> V_49 < V_463 )
goto V_455;
snprintf ( V_114 , sizeof( V_114 ) , L_176 ) ;
if ( ! V_27 -> V_482 ) {
V_27 -> V_482 =
F_93 ( V_114 , V_27 -> V_456 ) ;
if ( ! V_27 -> V_482 ) {
F_95 ( V_2 , V_159 , V_195 ,
L_177 ) ;
goto V_455;
}
memset ( & V_215 , 0 , sizeof( V_215 ) ) ;
}
snprintf ( V_114 , sizeof( V_114 ) , L_178 ) ;
if ( ! V_27 -> V_483 ) {
V_27 -> V_483 =
F_97 ( V_114 , V_459 | V_460 | V_461 ,
V_27 -> V_482 , V_27 , & V_484 ) ;
if ( ! V_27 -> V_483 ) {
F_95 ( V_2 , V_159 , V_195 ,
L_179 ) ;
goto V_455;
}
V_215 . V_224 . V_245 = 0 ;
}
snprintf ( V_114 , sizeof( V_114 ) , L_180 ) ;
if ( ! V_27 -> V_485 ) {
V_27 -> V_485 =
F_97 ( V_114 , V_459 | V_460 | V_461 ,
V_27 -> V_482 , V_27 , & V_486 ) ;
if ( ! V_27 -> V_485 ) {
F_95 ( V_2 , V_159 , V_195 ,
L_181 ) ;
goto V_455;
}
V_215 . V_224 . V_245 = 0 ;
}
snprintf ( V_114 , sizeof( V_114 ) , L_182 ) ;
if ( ! V_27 -> V_487 ) {
V_27 -> V_487 =
F_97 ( V_114 , V_459 | V_460 ,
V_27 -> V_482 , V_27 , & V_488 ) ;
if ( ! V_27 -> V_487 ) {
F_95 ( V_2 , V_159 , V_195 ,
L_183 ) ;
goto V_455;
}
}
snprintf ( V_114 , sizeof( V_114 ) , L_184 ) ;
if ( ! V_27 -> V_489 ) {
V_27 -> V_489 =
F_97 ( V_114 , V_459 | V_460 | V_461 ,
V_27 -> V_482 , V_27 , & V_490 ) ;
if ( ! V_27 -> V_489 ) {
F_95 ( V_2 , V_159 , V_195 ,
L_185 ) ;
goto V_455;
}
}
snprintf ( V_114 , sizeof( V_114 ) , L_186 ) ;
if ( ! V_27 -> V_491 ) {
V_27 -> V_491 =
F_97 ( V_114 , V_459 | V_460 | V_461 ,
V_27 -> V_482 , V_27 , & V_492 ) ;
if ( ! V_27 -> V_491 ) {
F_95 ( V_2 , V_159 , V_195 ,
L_187 ) ;
goto V_455;
}
}
snprintf ( V_114 , sizeof( V_114 ) , L_188 ) ;
if ( ! V_27 -> V_493 ) {
V_27 -> V_493 =
F_97 ( V_114 , V_459 | V_460 | V_461 ,
V_27 -> V_482 , V_27 , & V_494 ) ;
if ( ! V_27 -> V_493 ) {
F_95 ( V_2 , V_159 , V_195 ,
L_189 ) ;
goto V_455;
}
}
snprintf ( V_114 , sizeof( V_114 ) , L_190 ) ;
if ( ! V_27 -> V_495 ) {
V_27 -> V_495 =
F_97 ( V_114 , V_459 | V_460 | V_461 ,
V_27 -> V_482 , V_27 , & V_496 ) ;
if ( ! V_27 -> V_495 ) {
F_95 ( V_2 , V_159 , V_195 ,
L_191 ) ;
goto V_455;
}
}
if ( V_27 -> V_264 . V_497 ) {
snprintf ( V_114 , sizeof( V_114 ) , L_192 ) ;
if ( ! V_27 -> V_498 ) {
V_27 -> V_498 =
F_97 ( V_114 ,
V_459 | V_460 | V_461 ,
V_27 -> V_482 , V_27 ,
& V_499 ) ;
if ( ! V_27 -> V_498 ) {
F_95 ( V_2 , V_159 , V_195 ,
L_193
L_194 ) ;
goto V_455;
}
}
}
V_455:
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
if ( V_2 -> V_478 ) {
F_100 ( V_2 -> V_478 ) ;
V_2 -> V_478 = NULL ;
}
if ( V_2 -> V_480 ) {
F_100 ( V_2 -> V_480 ) ;
V_2 -> V_480 = NULL ;
}
if ( V_2 -> V_477 ) {
F_100 ( V_2 -> V_477 ) ;
V_2 -> V_477 = NULL ;
F_101 ( & V_27 -> V_457 ) ;
}
if ( F_3 ( & V_27 -> V_457 ) == 0 ) {
if ( V_27 -> V_458 ) {
F_100 ( V_27 -> V_458 ) ;
V_27 -> V_458 = NULL ;
}
if ( V_27 -> V_464 ) {
F_100 ( V_27 -> V_464 ) ;
V_27 -> V_464 = NULL ;
}
if ( V_27 -> V_466 ) {
F_100 ( V_27 -> V_466 ) ;
V_27 -> V_466 = NULL ;
}
if ( V_27 -> V_468 ) {
F_100 ( V_27 -> V_468 ) ;
V_27 -> V_468 = NULL ;
}
if ( V_27 -> V_470 ) {
F_100 ( V_27 -> V_470 ) ;
V_27 -> V_470 = NULL ;
}
if ( V_27 -> V_192 ) {
F_100 ( V_27 -> V_192 ) ;
V_27 -> V_192 = NULL ;
}
if ( V_27 -> V_187 ) {
F_100 ( V_27 -> V_187 ) ;
V_27 -> V_187 = NULL ;
}
if ( V_27 -> V_189 ) {
F_100 ( V_27 -> V_189 ) ;
V_27 -> V_189 = NULL ;
}
if ( V_27 -> V_175 ) {
F_100 ( V_27 -> V_175 ) ;
V_27 -> V_175 = NULL ;
}
if ( V_27 -> V_177 ) {
F_100 ( V_27 -> V_177 ) ;
V_27 -> V_177 = NULL ;
}
if ( V_27 -> V_179 ) {
F_100 ( V_27 -> V_179 ) ;
V_27 -> V_179 = NULL ;
}
if ( V_27 -> V_181 ) {
F_100 ( V_27 -> V_181 ) ;
V_27 -> V_181 = NULL ;
}
if ( V_27 -> V_183 ) {
F_100 ( V_27 -> V_183 ) ;
V_27 -> V_183 = NULL ;
}
if ( V_27 -> V_185 ) {
F_100 ( V_27 -> V_185 ) ;
V_27 -> V_185 = NULL ;
}
if ( V_27 -> V_30 ) {
F_5 ( V_27 -> V_30 ) ;
V_27 -> V_30 = NULL ;
}
if ( V_27 -> V_474 ) {
F_100 ( V_27 -> V_474 ) ;
V_27 -> V_474 = NULL ;
}
if ( V_27 -> V_49 == V_463 ) {
if ( V_27 -> V_498 ) {
F_100 ( V_27 -> V_498 ) ;
V_27 -> V_498 = NULL ;
}
if ( V_27 -> V_495 ) {
F_100 ( V_27 -> V_495 ) ;
V_27 -> V_495 = NULL ;
}
if ( V_27 -> V_493 ) {
F_100 ( V_27 -> V_493 ) ;
V_27 -> V_493 = NULL ;
}
if ( V_27 -> V_491 ) {
F_100 ( V_27 -> V_491 ) ;
V_27 -> V_491 = NULL ;
}
if ( V_27 -> V_489 ) {
F_100 ( V_27 -> V_489 ) ;
V_27 -> V_489 = NULL ;
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
if ( V_27 -> V_482 ) {
F_100 ( V_27 -> V_482 ) ;
V_27 -> V_482 = NULL ;
}
}
if ( V_27 -> V_456 ) {
F_100 ( V_27 -> V_456 ) ;
V_27 -> V_456 = NULL ;
F_101 ( & V_454 ) ;
}
if ( F_3 ( & V_454 ) == 0 ) {
F_100 ( V_453 ) ;
V_453 = NULL ;
}
}
#endif
return;
}
