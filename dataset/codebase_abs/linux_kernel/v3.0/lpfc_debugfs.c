static int
F_1 ( struct V_1 * V_2 , char * V_3 , int V_4 )
{
int V_5 , V_6 , V_7 , V_8 ;
T_1 V_9 ;
struct V_10 * V_11 ;
char V_12 [ V_13 ] ;
V_8 = V_14 ;
V_14 = 0 ;
V_7 = 0 ;
V_6 = ( F_2 ( & V_2 -> V_15 ) + 1 ) &
( V_16 - 1 ) ;
for ( V_5 = V_6 ; V_5 < V_16 ; V_5 ++ ) {
V_11 = V_2 -> V_17 + V_5 ;
if ( ! V_11 -> V_18 )
continue;
V_9 = F_3 ( V_11 -> V_19 - V_20 ) ;
snprintf ( V_12 ,
V_13 , L_1 ,
V_11 -> V_21 , V_9 , V_11 -> V_18 ) ;
V_7 += snprintf ( V_3 + V_7 , V_4 - V_7 , V_12 ,
V_11 -> V_22 , V_11 -> V_23 , V_11 -> V_24 ) ;
}
for ( V_5 = 0 ; V_5 < V_6 ; V_5 ++ ) {
V_11 = V_2 -> V_17 + V_5 ;
if ( ! V_11 -> V_18 )
continue;
V_9 = F_3 ( V_11 -> V_19 - V_20 ) ;
snprintf ( V_12 ,
V_13 , L_1 ,
V_11 -> V_21 , V_9 , V_11 -> V_18 ) ;
V_7 += snprintf ( V_3 + V_7 , V_4 - V_7 , V_12 ,
V_11 -> V_22 , V_11 -> V_23 , V_11 -> V_24 ) ;
}
V_14 = V_8 ;
return V_7 ;
}
static int
F_4 ( struct V_25 * V_26 , char * V_3 , int V_4 )
{
int V_5 , V_6 , V_7 , V_8 ;
T_1 V_9 ;
struct V_10 * V_11 ;
char V_12 [ V_13 ] ;
V_8 = V_14 ;
V_14 = 0 ;
V_7 = 0 ;
V_6 = ( F_2 ( & V_26 -> V_27 ) + 1 ) &
( V_28 - 1 ) ;
for ( V_5 = V_6 ; V_5 < V_28 ; V_5 ++ ) {
V_11 = V_26 -> V_29 + V_5 ;
if ( ! V_11 -> V_18 )
continue;
V_9 = F_3 ( V_11 -> V_19 - V_20 ) ;
snprintf ( V_12 ,
V_13 , L_1 ,
V_11 -> V_21 , V_9 , V_11 -> V_18 ) ;
V_7 += snprintf ( V_3 + V_7 , V_4 - V_7 , V_12 ,
V_11 -> V_22 , V_11 -> V_23 , V_11 -> V_24 ) ;
}
for ( V_5 = 0 ; V_5 < V_6 ; V_5 ++ ) {
V_11 = V_26 -> V_29 + V_5 ;
if ( ! V_11 -> V_18 )
continue;
V_9 = F_3 ( V_11 -> V_19 - V_20 ) ;
snprintf ( V_12 ,
V_13 , L_1 ,
V_11 -> V_21 , V_9 , V_11 -> V_18 ) ;
V_7 += snprintf ( V_3 + V_7 , V_4 - V_7 , V_12 ,
V_11 -> V_22 , V_11 -> V_23 , V_11 -> V_24 ) ;
}
V_14 = V_8 ;
return V_7 ;
}
static int
F_5 ( struct V_25 * V_26 , char * V_3 , int V_4 )
{
int V_7 = 0 ;
int V_30 , V_5 , V_31 , V_32 , V_33 , V_34 ;
T_1 V_35 , V_36 , V_37 ;
struct V_38 * V_39 ;
struct V_40 * V_41 ;
struct V_42 * V_43 ;
struct V_44 * V_45 ;
struct V_46 * V_47 ;
if ( V_26 -> V_48 != 3 )
return 0 ;
V_30 = V_49 ;
F_6 ( & V_26 -> V_50 ) ;
V_5 = F_7 () ;
if ( V_5 > 1 ) {
V_51 ++ ;
if ( V_51 >= V_5 )
V_51 = 0 ;
}
else
V_51 = 0 ;
V_5 = V_51 ;
V_7 += snprintf ( V_3 + V_7 , V_4 - V_7 , L_2 , V_5 ) ;
V_41 = & V_26 -> V_41 [ V_5 ] ;
V_33 = 0 ;
F_8 (d_buf, &hbqs->hbq_buffer_list, list)
V_33 ++ ;
V_39 = V_52 [ V_5 ] ;
V_7 += snprintf ( V_3 + V_7 , V_4 - V_7 ,
L_3 ,
V_39 -> V_53 , V_39 -> V_54 , V_39 -> V_55 ,
V_39 -> V_56 , V_39 -> V_57 , V_39 -> V_58 , V_33 ) ;
V_36 = V_26 -> V_59 [ V_5 ] ;
V_37 = F_9 ( V_36 ) ;
V_7 += snprintf ( V_3 + V_7 , V_4 - V_7 ,
L_4 ,
V_41 -> V_60 , V_41 -> V_56 , V_41 -> V_61 ,
V_41 -> V_62 , V_41 -> V_63 , V_37 ) ;
V_43 = (struct V_42 * ) V_26 -> V_41 [ V_5 ] . V_64 ;
for ( V_31 = 0 ; V_31 < V_41 -> V_60 ; V_31 ++ ) {
V_7 += snprintf ( V_3 + V_7 , V_4 - V_7 ,
L_5 , V_31 ,
F_9 ( V_43 -> V_65 . V_66 ) ,
F_9 ( V_43 -> V_65 . V_67 . V_68 ) ,
F_9 ( V_43 -> V_69 ) ) ;
V_5 = 0 ;
V_32 = 0 ;
V_34 = V_41 -> V_61 - V_33 ;
if ( V_34 >= 0 ) {
if ( ( V_31 >= V_41 -> V_61 ) || ( V_31 < V_34 ) ) {
V_7 += snprintf ( V_3 + V_7 , V_4 - V_7 , L_6 ) ;
goto V_70;
}
}
else {
if ( ( V_31 >= V_41 -> V_61 ) &&
( V_31 < ( V_41 -> V_60 + V_34 ) ) ) {
V_7 += snprintf ( V_3 + V_7 , V_4 - V_7 , L_6 ) ;
goto V_70;
}
}
F_8 (d_buf, &hbqs->hbq_buffer_list, list) {
V_47 = F_10 ( V_45 , struct V_46 , V_71 ) ;
V_35 = ( ( V_72 ) V_47 -> V_71 . V_35 & 0xffffffff ) ;
if ( V_35 == F_9 ( V_43 -> V_65 . V_66 ) ) {
V_7 += snprintf ( V_3 + V_7 , V_4 - V_7 ,
L_7 , V_5 ,
V_47 -> V_71 . V_73 , V_47 -> V_74 ) ;
V_32 = 1 ;
break;
}
V_5 ++ ;
}
if ( ! V_32 ) {
V_7 += snprintf ( V_3 + V_7 , V_4 - V_7 , L_8 ) ;
}
V_70:
V_43 ++ ;
if ( V_7 > V_49 - 54 )
break;
}
F_11 ( & V_26 -> V_50 ) ;
return V_7 ;
}
static int
F_12 ( struct V_25 * V_26 , char * V_3 , int V_4 )
{
int V_7 = 0 ;
int V_5 , V_75 ;
T_1 * V_76 ;
char V_12 [ 1024 ] ;
V_75 = 0 ;
F_6 ( & V_26 -> V_50 ) ;
V_7 += snprintf ( V_3 + V_7 , V_4 - V_7 , L_9 ) ;
F_13 ( V_12 ,
V_26 -> V_77 + V_78 , 1024 ) ;
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
F_11 ( & V_26 -> V_50 ) ;
return V_7 ;
}
static int
F_14 ( struct V_25 * V_26 , char * V_3 , int V_4 )
{
int V_7 = 0 ;
int V_5 , V_75 ;
T_1 V_79 , V_80 , V_81 , V_82 ;
T_1 * V_76 ;
struct V_83 * V_84 ;
struct V_85 * V_86 = & V_26 -> V_87 ;
struct V_88 * V_89 ;
V_75 = 0 ;
F_6 ( & V_26 -> V_50 ) ;
V_7 += snprintf ( V_3 + V_7 , V_4 - V_7 , L_11 ) ;
V_76 = ( T_1 * ) V_26 -> V_90 . V_73 ;
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
V_76 = ( T_1 * ) V_26 -> V_92 ;
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
V_84 = & V_26 -> V_94 [ V_5 ] ;
V_89 = & V_86 -> V_95 [ V_5 ] ;
V_7 += snprintf ( V_3 + V_7 , V_4 - V_7 ,
L_13
L_14 ,
V_5 , V_84 -> V_96 , V_89 -> V_97 ,
V_89 -> V_98 , V_89 -> V_99 ,
V_89 -> V_100 , V_84 -> V_101 , V_89 -> V_102 ) ;
}
if ( V_26 -> V_48 <= V_103 ) {
V_79 = F_15 ( V_26 -> V_104 ) ;
V_80 = F_15 ( V_26 -> V_105 ) ;
V_81 = F_15 ( V_26 -> V_106 ) ;
V_82 = F_15 ( V_26 -> V_107 ) ;
V_7 += snprintf ( V_3 + V_7 , V_4 - V_7 , L_15
L_16 , V_79 , V_80 , V_81 , V_82 ) ;
}
F_11 ( & V_26 -> V_50 ) ;
return V_7 ;
}
static int
F_16 ( struct V_1 * V_2 , char * V_3 , int V_4 )
{
int V_7 = 0 ;
int V_30 ;
struct V_108 * V_109 = F_17 ( V_2 ) ;
struct V_110 * V_111 ;
unsigned char * V_112 , * V_113 ;
V_30 = ( V_114 / V_115 ) ;
F_6 ( V_109 -> V_116 ) ;
F_8 (ndlp, &vport->fc_nodes, nlp_listp) {
if ( ! V_30 ) {
V_7 += snprintf ( V_3 + V_7 , V_4 - V_7 ,
L_17 ) ;
break;
}
V_30 -- ;
switch ( V_111 -> V_117 ) {
case V_118 :
V_112 = L_18 ;
break;
case V_119 :
V_112 = L_19 ;
break;
case V_120 :
V_112 = L_20 ;
break;
case V_121 :
V_112 = L_21 ;
break;
case V_122 :
V_112 = L_22 ;
break;
case V_123 :
V_112 = L_23 ;
break;
case V_124 :
V_112 = L_24 ;
break;
case V_125 :
V_112 = L_25 ;
break;
default:
V_112 = L_26 ;
}
V_7 += snprintf ( V_3 + V_7 , V_4 - V_7 , L_27 ,
V_112 , V_111 -> V_126 ) ;
V_113 = ( unsigned char * ) & V_111 -> V_127 ;
V_7 += snprintf ( V_3 + V_7 , V_4 - V_7 ,
L_28 ,
* V_113 , * ( V_113 + 1 ) , * ( V_113 + 2 ) , * ( V_113 + 3 ) ,
* ( V_113 + 4 ) , * ( V_113 + 5 ) , * ( V_113 + 6 ) , * ( V_113 + 7 ) ) ;
V_113 = ( unsigned char * ) & V_111 -> V_128 ;
V_7 += snprintf ( V_3 + V_7 , V_4 - V_7 ,
L_29 ,
* V_113 , * ( V_113 + 1 ) , * ( V_113 + 2 ) , * ( V_113 + 3 ) ,
* ( V_113 + 4 ) , * ( V_113 + 5 ) , * ( V_113 + 6 ) , * ( V_113 + 7 ) ) ;
V_7 += snprintf ( V_3 + V_7 , V_4 - V_7 , L_30 ,
V_111 -> V_129 , V_111 -> V_130 ) ;
if ( ! V_111 -> V_131 )
V_7 += snprintf ( V_3 + V_7 , V_4 - V_7 , L_31 ) ;
if ( V_111 -> V_131 & V_132 )
V_7 += snprintf ( V_3 + V_7 , V_4 - V_7 , L_32 ) ;
if ( V_111 -> V_131 & V_133 )
V_7 += snprintf ( V_3 + V_7 , V_4 - V_7 , L_33 ) ;
if ( V_111 -> V_131 & V_134 )
V_7 += snprintf ( V_3 + V_7 , V_4 - V_7 , L_34 ,
V_111 -> V_135 ) ;
if ( V_111 -> V_131 & V_136 )
V_7 += snprintf ( V_3 + V_7 , V_4 - V_7 , L_35 ) ;
V_7 += snprintf ( V_3 + V_7 , V_4 - V_7 , L_36 ,
V_111 -> V_137 ) ;
V_7 += snprintf ( V_3 + V_7 , V_4 - V_7 , L_37 ,
F_2 ( & V_111 -> V_138 . V_139 ) ) ;
V_7 += snprintf ( V_3 + V_7 , V_4 - V_7 , L_38 ) ;
}
F_11 ( V_109 -> V_116 ) ;
return V_7 ;
}
inline void
F_18 ( struct V_1 * V_2 , int V_140 , char * V_18 ,
T_1 V_22 , T_1 V_23 , T_1 V_24 )
{
#ifdef F_19
struct V_10 * V_11 ;
int V_6 ;
if ( ! ( V_141 & V_140 ) )
return;
if ( ! V_14 || ! V_16 ||
! V_2 || ! V_2 -> V_17 )
return;
V_6 = F_20 ( & V_2 -> V_15 ) &
( V_16 - 1 ) ;
V_11 = V_2 -> V_17 + V_6 ;
V_11 -> V_18 = V_18 ;
V_11 -> V_22 = V_22 ;
V_11 -> V_23 = V_23 ;
V_11 -> V_24 = V_24 ;
V_11 -> V_21 = F_20 ( & V_142 ) ;
V_11 -> V_19 = V_143 ;
#endif
return;
}
inline void
F_21 ( struct V_25 * V_26 , char * V_18 ,
T_1 V_22 , T_1 V_23 , T_1 V_24 )
{
#ifdef F_19
struct V_10 * V_11 ;
int V_6 ;
if ( ! V_14 || ! V_28 ||
! V_26 || ! V_26 -> V_29 )
return;
V_6 = F_20 ( & V_26 -> V_27 ) &
( V_28 - 1 ) ;
V_11 = V_26 -> V_29 + V_6 ;
V_11 -> V_18 = V_18 ;
V_11 -> V_22 = V_22 ;
V_11 -> V_23 = V_23 ;
V_11 -> V_24 = V_24 ;
V_11 -> V_21 = F_20 ( & V_142 ) ;
V_11 -> V_19 = V_143 ;
#endif
return;
}
static int
F_22 ( struct V_144 * V_144 , struct V_145 * V_145 )
{
struct V_1 * V_2 = V_144 -> V_146 ;
struct V_147 * V_148 ;
int V_4 ;
int V_149 = - V_150 ;
if ( ! V_16 ) {
V_149 = - V_151 ;
goto V_152;
}
V_148 = F_23 ( sizeof( * V_148 ) , V_153 ) ;
if ( ! V_148 )
goto V_152;
V_4 = ( V_16 * V_13 ) ;
V_4 = F_24 ( V_4 ) ;
V_148 -> V_12 = F_23 ( V_4 , V_153 ) ;
if ( ! V_148 -> V_12 ) {
F_25 ( V_148 ) ;
goto V_152;
}
V_148 -> V_7 = F_1 ( V_2 , V_148 -> V_12 , V_4 ) ;
V_145 -> V_154 = V_148 ;
V_149 = 0 ;
V_152:
return V_149 ;
}
static int
F_26 ( struct V_144 * V_144 , struct V_145 * V_145 )
{
struct V_25 * V_26 = V_144 -> V_146 ;
struct V_147 * V_148 ;
int V_4 ;
int V_149 = - V_150 ;
if ( ! V_28 ) {
V_149 = - V_151 ;
goto V_152;
}
V_148 = F_23 ( sizeof( * V_148 ) , V_153 ) ;
if ( ! V_148 )
goto V_152;
V_4 = ( V_28 * V_13 ) ;
V_4 = F_24 ( V_4 ) ;
V_148 -> V_12 = F_23 ( V_4 , V_153 ) ;
if ( ! V_148 -> V_12 ) {
F_25 ( V_148 ) ;
goto V_152;
}
V_148 -> V_7 = F_4 ( V_26 , V_148 -> V_12 , V_4 ) ;
V_145 -> V_154 = V_148 ;
V_149 = 0 ;
V_152:
return V_149 ;
}
static int
F_27 ( struct V_144 * V_144 , struct V_145 * V_145 )
{
struct V_25 * V_26 = V_144 -> V_146 ;
struct V_147 * V_148 ;
int V_149 = - V_150 ;
V_148 = F_23 ( sizeof( * V_148 ) , V_153 ) ;
if ( ! V_148 )
goto V_152;
V_148 -> V_12 = F_23 ( V_49 , V_153 ) ;
if ( ! V_148 -> V_12 ) {
F_25 ( V_148 ) ;
goto V_152;
}
V_148 -> V_7 = F_5 ( V_26 , V_148 -> V_12 ,
V_49 ) ;
V_145 -> V_154 = V_148 ;
V_149 = 0 ;
V_152:
return V_149 ;
}
static int
F_28 ( struct V_144 * V_144 , struct V_145 * V_145 )
{
struct V_25 * V_26 = V_144 -> V_146 ;
struct V_147 * V_148 ;
int V_149 = - V_150 ;
V_148 = F_23 ( sizeof( * V_148 ) , V_153 ) ;
if ( ! V_148 )
goto V_152;
V_148 -> V_12 = F_23 ( V_155 , V_153 ) ;
if ( ! V_148 -> V_12 ) {
F_25 ( V_148 ) ;
goto V_152;
}
V_148 -> V_7 = F_12 ( V_26 , V_148 -> V_12 ,
V_155 ) ;
V_145 -> V_154 = V_148 ;
V_149 = 0 ;
V_152:
return V_149 ;
}
static int
F_29 ( struct V_144 * V_144 , struct V_145 * V_145 )
{
struct V_25 * V_26 = V_144 -> V_146 ;
struct V_147 * V_148 ;
int V_149 = - V_150 ;
V_148 = F_23 ( sizeof( * V_148 ) , V_153 ) ;
if ( ! V_148 )
goto V_152;
V_148 -> V_12 = F_23 ( V_156 , V_153 ) ;
if ( ! V_148 -> V_12 ) {
F_25 ( V_148 ) ;
goto V_152;
}
V_148 -> V_7 = F_14 ( V_26 , V_148 -> V_12 ,
V_156 ) ;
V_145 -> V_154 = V_148 ;
V_149 = 0 ;
V_152:
return V_149 ;
}
static int
F_30 ( struct V_144 * V_144 , struct V_145 * V_145 )
{
struct V_147 * V_148 ;
int V_149 = - V_150 ;
if ( ! V_157 )
return - V_158 ;
V_148 = F_23 ( sizeof( * V_148 ) , V_153 ) ;
if ( ! V_148 )
goto V_152;
F_31 ( V_159 L_39 ,
V_160 , V_157 ) ;
V_148 -> V_12 = V_157 ;
if ( ! V_148 -> V_12 ) {
F_25 ( V_148 ) ;
goto V_152;
}
V_148 -> V_7 = ( 1 << V_161 ) << V_162 ;
V_145 -> V_154 = V_148 ;
V_149 = 0 ;
V_152:
return V_149 ;
}
static int
F_32 ( struct V_144 * V_144 , struct V_145 * V_145 )
{
struct V_147 * V_148 ;
int V_149 = - V_150 ;
if ( ! V_163 )
return - V_158 ;
V_148 = F_23 ( sizeof( * V_148 ) , V_153 ) ;
if ( ! V_148 )
goto V_152;
F_31 ( V_159 L_40 ,
V_160 , V_163 , V_145 -> V_164 -> V_165 . V_113 ) ;
V_148 -> V_12 = V_163 ;
if ( ! V_148 -> V_12 ) {
F_25 ( V_148 ) ;
goto V_152;
}
V_148 -> V_7 = ( 1 << V_166 ) << V_162 ;
V_145 -> V_154 = V_148 ;
V_149 = 0 ;
V_152:
return V_149 ;
}
static T_2
F_33 ( struct V_145 * V_145 , const char T_3 * V_3 ,
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
F_36 ( struct V_144 * V_144 , struct V_145 * V_145 )
{
struct V_1 * V_2 = V_144 -> V_146 ;
struct V_147 * V_148 ;
int V_149 = - V_150 ;
V_148 = F_23 ( sizeof( * V_148 ) , V_153 ) ;
if ( ! V_148 )
goto V_152;
V_148 -> V_12 = F_23 ( V_114 , V_153 ) ;
if ( ! V_148 -> V_12 ) {
F_25 ( V_148 ) ;
goto V_152;
}
V_148 -> V_7 = F_16 ( V_2 , V_148 -> V_12 ,
V_114 ) ;
V_145 -> V_154 = V_148 ;
V_149 = 0 ;
V_152:
return V_149 ;
}
static T_5
F_37 ( struct V_145 * V_145 , T_5 V_75 , int V_171 )
{
struct V_147 * V_148 ;
T_5 V_172 = - 1 ;
V_148 = V_145 -> V_154 ;
switch ( V_171 ) {
case 0 :
V_172 = V_75 ;
break;
case 1 :
V_172 = V_145 -> V_173 + V_75 ;
break;
case 2 :
V_172 = V_148 -> V_7 - V_75 ;
}
return ( V_172 < 0 || V_172 > V_148 -> V_7 ) ? - V_174 : ( V_145 -> V_173 = V_172 ) ;
}
static T_2
F_38 ( struct V_145 * V_145 , char T_3 * V_3 ,
T_4 V_167 , T_5 * V_168 )
{
struct V_147 * V_148 = V_145 -> V_154 ;
return F_39 ( V_3 , V_167 , V_168 , V_148 -> V_12 ,
V_148 -> V_7 ) ;
}
static int
F_40 ( struct V_144 * V_144 , struct V_145 * V_145 )
{
struct V_147 * V_148 = V_145 -> V_154 ;
F_25 ( V_148 -> V_12 ) ;
F_25 ( V_148 ) ;
return 0 ;
}
static int
F_41 ( struct V_144 * V_144 , struct V_145 * V_145 )
{
struct V_147 * V_148 = V_145 -> V_154 ;
V_148 -> V_12 = NULL ;
F_25 ( V_148 ) ;
return 0 ;
}
static int F_42 ( const char T_3 * V_3 , T_4 V_167 ,
struct V_175 * V_176 )
{
char V_177 [ 64 ] ;
char * V_178 , * V_179 ;
int V_180 , V_5 ;
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
F_48 ( struct V_144 * V_144 , struct V_145 * V_145 )
{
struct V_147 * V_148 ;
V_148 = F_23 ( sizeof( * V_148 ) , V_153 ) ;
if ( ! V_148 )
return - V_150 ;
V_148 -> V_146 = V_144 -> V_146 ;
V_148 -> V_12 = NULL ;
V_145 -> V_154 = V_148 ;
return 0 ;
}
static int
F_49 ( struct V_144 * V_144 , struct V_145 * V_145 )
{
struct V_147 * V_148 = V_145 -> V_154 ;
F_25 ( V_148 -> V_12 ) ;
F_25 ( V_148 ) ;
return 0 ;
}
static int
F_50 ( struct V_144 * V_144 , struct V_145 * V_145 )
{
struct V_147 * V_148 = V_145 -> V_154 ;
if ( V_148 -> V_186 == V_187 ) {
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
F_25 ( V_148 -> V_12 ) ;
F_25 ( V_148 ) ;
return 0 ;
}
static T_2
F_51 ( struct V_145 * V_145 , char T_3 * V_3 , T_4 V_167 ,
T_5 * V_168 )
{
struct V_147 * V_148 = V_145 -> V_154 ;
struct V_25 * V_26 = (struct V_25 * ) V_148 -> V_146 ;
int V_196 , V_197 , V_7 = 0 , V_6 = V_198 ;
int V_199 , V_200 ;
char * V_201 ;
struct V_202 * V_203 ;
T_1 V_204 ;
T_6 V_205 ;
T_7 V_206 ;
V_203 = V_26 -> V_207 ;
if ( ! V_203 )
return 0 ;
V_148 -> V_186 = V_208 ;
if ( ! V_148 -> V_12 )
V_148 -> V_12 = F_23 ( V_209 , V_153 ) ;
if ( ! V_148 -> V_12 )
return 0 ;
V_201 = V_148 -> V_12 ;
if ( * V_168 )
return 0 ;
if ( V_188 . V_189 . V_183 == V_210 ) {
V_199 = V_188 . V_189 . V_185 [ 0 ] ;
V_200 = V_188 . V_189 . V_185 [ 1 ] ;
} else
return 0 ;
switch ( V_200 ) {
case V_211 :
F_52 ( V_203 , V_199 , & V_206 ) ;
V_7 += snprintf ( V_201 + V_7 , V_209 - V_7 ,
L_42 , V_199 , V_206 ) ;
break;
case V_212 :
F_53 ( V_203 , V_199 , & V_205 ) ;
V_7 += snprintf ( V_201 + V_7 , V_209 - V_7 ,
L_43 , V_199 , V_205 ) ;
break;
case V_213 :
F_54 ( V_203 , V_199 , & V_204 ) ;
V_7 += snprintf ( V_201 + V_7 , V_209 - V_7 ,
L_44 , V_199 , V_204 ) ;
break;
case V_214 :
goto V_215;
break;
default:
V_7 = 0 ;
break;
}
return F_39 ( V_3 , V_167 , V_168 , V_201 , V_7 ) ;
V_215:
V_196 = V_188 . V_197 . V_216 ;
V_197 = V_196 ;
V_7 += snprintf ( V_201 + V_7 , V_209 - V_7 ,
L_45 , V_196 ) ;
while ( V_6 > 0 ) {
F_54 ( V_203 , V_197 , & V_204 ) ;
V_7 += snprintf ( V_201 + V_7 , V_209 - V_7 ,
L_46 , V_204 ) ;
V_197 += sizeof( T_1 ) ;
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
V_188 . V_197 . V_216 += V_198 ;
if ( V_188 . V_197 . V_216 >= V_209 )
V_188 . V_197 . V_216 = 0 ;
return F_39 ( V_3 , V_167 , V_168 , V_201 , V_7 ) ;
}
static T_2
F_55 ( struct V_145 * V_145 , const char T_3 * V_3 ,
T_4 V_167 , T_5 * V_168 )
{
struct V_147 * V_148 = V_145 -> V_154 ;
struct V_25 * V_26 = (struct V_25 * ) V_148 -> V_146 ;
T_1 V_199 , V_217 , V_200 ;
T_1 V_204 ;
T_6 V_205 ;
T_7 V_206 ;
struct V_202 * V_203 ;
int V_149 ;
V_203 = V_26 -> V_207 ;
if ( ! V_203 )
return - V_182 ;
V_148 -> V_186 = V_187 ;
V_149 = F_42 ( V_3 , V_167 , & V_188 . V_189 ) ;
if ( V_149 < 0 )
return V_149 ;
if ( V_188 . V_189 . V_183 == V_210 ) {
if ( V_149 != V_218 )
goto V_219;
V_199 = V_188 . V_189 . V_185 [ 0 ] ;
V_200 = V_188 . V_189 . V_185 [ 1 ] ;
if ( V_200 == V_214 ) {
if ( V_199 % sizeof( T_1 ) )
goto V_219;
V_188 . V_197 . V_216 = V_199 ;
} else if ( ( V_200 != sizeof( T_7 ) ) &&
( V_200 != sizeof( T_6 ) ) &&
( V_200 != sizeof( T_1 ) ) )
goto V_219;
if ( V_200 == sizeof( T_7 ) ) {
if ( V_199 > V_209 - sizeof( T_7 ) )
goto V_219;
if ( V_199 % sizeof( T_7 ) )
goto V_219;
}
if ( V_200 == sizeof( T_6 ) ) {
if ( V_199 > V_209 - sizeof( T_6 ) )
goto V_219;
if ( V_199 % sizeof( T_6 ) )
goto V_219;
}
if ( V_200 == sizeof( T_1 ) ) {
if ( V_199 > V_209 - sizeof( T_1 ) )
goto V_219;
if ( V_199 % sizeof( T_1 ) )
goto V_219;
}
} else if ( V_188 . V_189 . V_183 == V_190 ||
V_188 . V_189 . V_183 == V_191 ||
V_188 . V_189 . V_183 == V_192 ) {
if ( V_149 != V_220 )
goto V_219;
V_199 = V_188 . V_189 . V_185 [ 0 ] ;
V_200 = V_188 . V_189 . V_185 [ 1 ] ;
V_217 = V_188 . V_189 . V_185 [ 2 ] ;
if ( ( V_200 != sizeof( T_7 ) ) &&
( V_200 != sizeof( T_6 ) ) &&
( V_200 != sizeof( T_1 ) ) )
goto V_219;
if ( V_200 == sizeof( T_7 ) ) {
if ( V_199 > V_209 - sizeof( T_7 ) )
goto V_219;
if ( V_199 % sizeof( T_7 ) )
goto V_219;
if ( V_188 . V_189 . V_183 == V_190 )
F_56 ( V_203 , V_199 ,
( T_7 ) V_217 ) ;
if ( V_188 . V_189 . V_183 == V_191 ) {
V_149 = F_52 ( V_203 , V_199 , & V_206 ) ;
if ( ! V_149 ) {
V_206 |= ( T_7 ) V_217 ;
F_56 ( V_203 , V_199 ,
V_206 ) ;
}
}
if ( V_188 . V_189 . V_183 == V_192 ) {
V_149 = F_52 ( V_203 , V_199 , & V_206 ) ;
if ( ! V_149 ) {
V_206 &= ( T_7 ) ( ~ V_217 ) ;
F_56 ( V_203 , V_199 ,
V_206 ) ;
}
}
}
if ( V_200 == sizeof( T_6 ) ) {
if ( V_199 > V_209 - sizeof( T_6 ) )
goto V_219;
if ( V_199 % sizeof( T_6 ) )
goto V_219;
if ( V_188 . V_189 . V_183 == V_190 )
F_57 ( V_203 , V_199 ,
( T_6 ) V_217 ) ;
if ( V_188 . V_189 . V_183 == V_191 ) {
V_149 = F_53 ( V_203 , V_199 , & V_205 ) ;
if ( ! V_149 ) {
V_205 |= ( T_6 ) V_217 ;
F_57 ( V_203 , V_199 ,
V_205 ) ;
}
}
if ( V_188 . V_189 . V_183 == V_192 ) {
V_149 = F_53 ( V_203 , V_199 , & V_205 ) ;
if ( ! V_149 ) {
V_205 &= ( T_6 ) ( ~ V_217 ) ;
F_57 ( V_203 , V_199 ,
V_205 ) ;
}
}
}
if ( V_200 == sizeof( T_1 ) ) {
if ( V_199 > V_209 - sizeof( T_1 ) )
goto V_219;
if ( V_199 % sizeof( T_1 ) )
goto V_219;
if ( V_188 . V_189 . V_183 == V_190 )
F_58 ( V_203 , V_199 , V_217 ) ;
if ( V_188 . V_189 . V_183 == V_191 ) {
V_149 = F_54 ( V_203 , V_199 ,
& V_204 ) ;
if ( ! V_149 ) {
V_204 |= V_217 ;
F_58 ( V_203 , V_199 ,
V_204 ) ;
}
}
if ( V_188 . V_189 . V_183 == V_192 ) {
V_149 = F_54 ( V_203 , V_199 ,
& V_204 ) ;
if ( ! V_149 ) {
V_204 &= ~ V_217 ;
F_58 ( V_203 , V_199 ,
V_204 ) ;
}
}
}
} else
goto V_219;
return V_167 ;
V_219:
memset ( & V_188 , 0 , sizeof( V_188 ) ) ;
return - V_174 ;
}
static T_2
F_59 ( struct V_145 * V_145 , char T_3 * V_3 , T_4 V_167 ,
T_5 * V_168 )
{
struct V_147 * V_148 = V_145 -> V_154 ;
struct V_25 * V_26 = (struct V_25 * ) V_148 -> V_146 ;
int V_7 = 0 , V_221 ;
char * V_201 ;
if ( ! V_148 -> V_12 )
V_148 -> V_12 = F_23 ( V_222 , V_153 ) ;
if ( ! V_148 -> V_12 )
return 0 ;
V_201 = V_148 -> V_12 ;
if ( * V_168 )
return 0 ;
V_7 += snprintf ( V_201 + V_7 , V_222 - V_7 ,
L_48 ) ;
V_7 += snprintf ( V_201 + V_7 , V_222 - V_7 ,
L_49
L_50
L_51 ,
V_26 -> V_223 . V_224 -> V_225 ,
V_26 -> V_223 . V_224 -> V_60 ,
V_26 -> V_223 . V_224 -> V_226 ,
V_26 -> V_223 . V_224 -> V_227 ,
V_26 -> V_223 . V_224 -> V_228 ) ;
V_7 += snprintf ( V_201 + V_7 , V_222 - V_7 ,
L_52 ) ;
for ( V_221 = 0 ; V_221 < V_26 -> V_229 ; V_221 ++ ) {
V_7 += snprintf ( V_201 + V_7 , V_222 - V_7 ,
L_49
L_50
L_53 ,
V_26 -> V_223 . V_230 [ V_221 ] -> V_225 ,
V_26 -> V_223 . V_230 [ V_221 ] -> V_60 ,
V_26 -> V_223 . V_230 [ V_221 ] -> V_226 ,
V_26 -> V_223 . V_230 [ V_221 ] -> V_227 ,
V_26 -> V_223 . V_230 [ V_221 ] -> V_228 ) ;
}
V_7 += snprintf ( V_201 + V_7 , V_222 - V_7 , L_38 ) ;
V_7 += snprintf ( V_201 + V_7 , V_222 - V_7 ,
L_54 ) ;
V_7 += snprintf ( V_201 + V_7 , V_222 - V_7 ,
L_55 ,
V_26 -> V_223 . V_231 -> V_232 ) ;
V_7 += snprintf ( V_201 + V_7 , V_222 - V_7 ,
L_56
L_50
L_51 ,
V_26 -> V_223 . V_231 -> V_225 ,
V_26 -> V_223 . V_231 -> V_60 ,
V_26 -> V_223 . V_231 -> V_226 ,
V_26 -> V_223 . V_231 -> V_227 ,
V_26 -> V_223 . V_231 -> V_228 ) ;
V_7 += snprintf ( V_201 + V_7 , V_222 - V_7 ,
L_57 ) ;
V_7 += snprintf ( V_201 + V_7 , V_222 - V_7 ,
L_55 ,
V_26 -> V_223 . V_233 -> V_232 ) ;
V_7 += snprintf ( V_201 + V_7 , V_222 - V_7 ,
L_58
L_50
L_51 ,
V_26 -> V_223 . V_233 -> V_225 ,
V_26 -> V_223 . V_233 -> V_60 ,
V_26 -> V_223 . V_233 -> V_226 ,
V_26 -> V_223 . V_233 -> V_227 ,
V_26 -> V_223 . V_233 -> V_228 ) ;
V_7 += snprintf ( V_201 + V_7 , V_222 - V_7 ,
L_59 ) ;
V_221 = 0 ;
do {
V_7 += snprintf ( V_201 + V_7 , V_222 - V_7 ,
L_55 ,
V_26 -> V_223 . V_234 [ V_221 ] -> V_232 ) ;
V_7 += snprintf ( V_201 + V_7 , V_222 - V_7 ,
L_56
L_50
L_53 ,
V_26 -> V_223 . V_234 [ V_221 ] -> V_225 ,
V_26 -> V_223 . V_234 [ V_221 ] -> V_60 ,
V_26 -> V_223 . V_234 [ V_221 ] -> V_226 ,
V_26 -> V_223 . V_234 [ V_221 ] -> V_227 ,
V_26 -> V_223 . V_234 [ V_221 ] -> V_228 ) ;
} while ( ++ V_221 < V_26 -> V_229 );
V_7 += snprintf ( V_201 + V_7 , V_222 - V_7 , L_38 ) ;
V_7 += snprintf ( V_201 + V_7 , V_222 - V_7 ,
L_60 ) ;
V_7 += snprintf ( V_201 + V_7 , V_222 - V_7 ,
L_61 ,
V_26 -> V_223 . V_235 -> V_232 ) ;
V_7 += snprintf ( V_201 + V_7 , V_222 - V_7 ,
L_62
L_50
L_51 ,
V_26 -> V_223 . V_235 -> V_225 ,
V_26 -> V_223 . V_235 -> V_60 ,
V_26 -> V_223 . V_235 -> V_226 ,
V_26 -> V_223 . V_235 -> V_227 ,
V_26 -> V_223 . V_235 -> V_228 ) ;
V_7 += snprintf ( V_201 + V_7 , V_222 - V_7 ,
L_63 ) ;
V_7 += snprintf ( V_201 + V_7 , V_222 - V_7 ,
L_61 ,
V_26 -> V_223 . V_236 -> V_232 ) ;
V_7 += snprintf ( V_201 + V_7 , V_222 - V_7 ,
L_62
L_50
L_51 ,
V_26 -> V_223 . V_236 -> V_225 ,
V_26 -> V_223 . V_236 -> V_60 ,
V_26 -> V_223 . V_236 -> V_226 ,
V_26 -> V_223 . V_236 -> V_227 ,
V_26 -> V_223 . V_236 -> V_228 ) ;
V_7 += snprintf ( V_201 + V_7 , V_222 - V_7 ,
L_64 ) ;
for ( V_221 = 0 ; V_221 < V_26 -> V_237 ; V_221 ++ ) {
V_7 += snprintf ( V_201 + V_7 , V_222 - V_7 ,
L_61 ,
V_26 -> V_223 . V_238 [ V_221 ] -> V_232 ) ;
V_7 += snprintf ( V_201 + V_7 , V_222 - V_7 ,
L_62
L_65
L_53 ,
V_26 -> V_223 . V_238 [ V_221 ] -> V_225 ,
V_26 -> V_223 . V_238 [ V_221 ] -> V_60 ,
V_26 -> V_223 . V_238 [ V_221 ] -> V_226 ,
V_26 -> V_223 . V_238 [ V_221 ] -> V_227 ,
V_26 -> V_223 . V_238 [ V_221 ] -> V_228 ) ;
}
V_7 += snprintf ( V_201 + V_7 , V_222 - V_7 , L_38 ) ;
V_7 += snprintf ( V_201 + V_7 , V_222 - V_7 ,
L_66 ) ;
V_7 += snprintf ( V_201 + V_7 , V_222 - V_7 ,
L_61 ,
V_26 -> V_223 . V_239 -> V_232 ) ;
V_7 += snprintf ( V_201 + V_7 , V_222 - V_7 ,
L_67
L_50
L_53 ,
V_26 -> V_223 . V_239 -> V_225 ,
V_26 -> V_223 . V_239 -> V_60 ,
V_26 -> V_223 . V_239 -> V_226 ,
V_26 -> V_223 . V_239 -> V_227 ,
V_26 -> V_223 . V_239 -> V_228 ) ;
V_7 += snprintf ( V_201 + V_7 , V_222 - V_7 ,
L_68
L_50
L_53 ,
V_26 -> V_223 . V_240 -> V_225 ,
V_26 -> V_223 . V_240 -> V_60 ,
V_26 -> V_223 . V_240 -> V_226 ,
V_26 -> V_223 . V_240 -> V_227 ,
V_26 -> V_223 . V_240 -> V_228 ) ;
return F_39 ( V_3 , V_167 , V_168 , V_201 , V_7 ) ;
}
static int
F_60 ( struct V_241 * V_242 , int V_6 , int V_200 )
{
if ( ( V_200 != 1 ) && ( V_200 != V_243 ) )
return - V_174 ;
if ( V_6 > V_242 -> V_60 - 1 )
return - V_174 ;
return 0 ;
}
static int
F_61 ( char * V_201 , int V_7 , struct V_241 * V_244 ,
T_1 V_6 )
{
int V_197 , V_245 ;
T_1 * V_246 ;
if ( ! V_201 || ! V_244 )
return 0 ;
V_245 = V_244 -> V_226 ;
V_7 += snprintf ( V_201 + V_7 , V_247 - V_7 ,
L_69 , V_6 ) ;
V_197 = 0 ;
V_246 = V_244 -> V_248 [ V_6 ] . V_249 ;
while ( V_245 > 0 ) {
V_7 += snprintf ( V_201 + V_7 , V_247 - V_7 ,
L_46 , * V_246 ) ;
V_246 ++ ;
V_197 += sizeof( T_1 ) ;
V_245 -= sizeof( T_1 ) ;
if ( V_245 > 0 && ! ( V_197 % ( 4 * sizeof( T_1 ) ) ) )
V_7 += snprintf ( V_201 + V_7 ,
V_247 - V_7 , L_38 ) ;
}
V_7 += snprintf ( V_201 + V_7 , V_247 - V_7 , L_38 ) ;
return V_7 ;
}
static T_2
F_62 ( struct V_145 * V_145 , char T_3 * V_3 , T_4 V_167 ,
T_5 * V_168 )
{
struct V_147 * V_148 = V_145 -> V_154 ;
T_1 V_250 , V_6 , V_200 ;
struct V_241 * V_244 = NULL ;
char * V_201 ;
int V_7 = 0 ;
V_148 -> V_186 = V_208 ;
if ( ! V_148 -> V_12 )
V_148 -> V_12 = F_23 ( V_247 , V_153 ) ;
if ( ! V_148 -> V_12 )
return 0 ;
V_201 = V_148 -> V_12 ;
if ( * V_168 )
return 0 ;
if ( V_188 . V_189 . V_183 == V_251 ) {
V_6 = V_188 . V_189 . V_185 [ 2 ] ;
V_200 = V_188 . V_189 . V_185 [ 3 ] ;
V_244 = (struct V_241 * ) V_188 . V_252 ;
} else
return 0 ;
if ( V_200 == V_243 )
goto V_253;
V_7 = F_61 ( V_201 , V_7 , V_244 , V_6 ) ;
return F_39 ( V_3 , V_167 , V_168 , V_201 , V_7 ) ;
V_253:
V_250 = V_188 . V_197 . V_216 ;
V_6 = V_250 ;
while ( V_7 < V_254 - V_244 -> V_226 ) {
V_7 = F_61 ( V_201 , V_7 , V_244 , V_6 ) ;
V_6 ++ ;
if ( V_6 > V_244 -> V_60 - 1 )
break;
}
if ( V_6 > V_244 -> V_60 - 1 )
V_6 = 0 ;
V_188 . V_197 . V_216 = V_6 ;
return F_39 ( V_3 , V_167 , V_168 , V_201 , V_7 ) ;
}
static T_2
F_63 ( struct V_145 * V_145 , const char T_3 * V_3 ,
T_4 V_167 , T_5 * V_168 )
{
struct V_147 * V_148 = V_145 -> V_154 ;
struct V_25 * V_26 = (struct V_25 * ) V_148 -> V_146 ;
T_1 V_255 , V_256 , V_257 , V_6 , V_200 , V_197 , V_217 ;
T_1 * V_246 ;
struct V_241 * V_244 ;
int V_149 ;
V_148 -> V_186 = V_187 ;
V_149 = F_42 ( V_3 , V_167 , & V_188 . V_189 ) ;
if ( V_149 < 0 )
return V_149 ;
V_256 = V_188 . V_189 . V_185 [ 0 ] ;
V_257 = V_188 . V_189 . V_185 [ 1 ] ;
V_6 = V_188 . V_189 . V_185 [ 2 ] ;
V_200 = V_188 . V_189 . V_185 [ 3 ] ;
V_197 = V_188 . V_189 . V_185 [ 4 ] ;
V_217 = V_188 . V_189 . V_185 [ 5 ] ;
if ( V_188 . V_189 . V_183 == V_193 ||
V_188 . V_189 . V_183 == V_194 ||
V_188 . V_189 . V_183 == V_195 ) {
if ( V_149 != V_258 )
goto V_219;
if ( V_200 != 1 )
goto V_219;
} else if ( V_188 . V_189 . V_183 == V_251 ) {
if ( V_149 != V_259 )
goto V_219;
} else
goto V_219;
switch ( V_256 ) {
case V_260 :
if ( V_26 -> V_223 . V_224 -> V_225 == V_257 ) {
V_149 = F_60 (
V_26 -> V_223 . V_224 , V_6 , V_200 ) ;
if ( V_149 )
goto V_219;
V_188 . V_252 = V_26 -> V_223 . V_224 ;
goto V_261;
}
for ( V_255 = 0 ; V_255 < V_26 -> V_229 ; V_255 ++ ) {
if ( V_26 -> V_223 . V_230 [ V_255 ] -> V_225 == V_257 ) {
V_149 = F_60 (
V_26 -> V_223 . V_230 [ V_255 ] ,
V_6 , V_200 ) ;
if ( V_149 )
goto V_219;
V_188 . V_252 = V_26 -> V_223 . V_230 [ V_255 ] ;
goto V_261;
}
}
goto V_219;
break;
case V_262 :
if ( V_26 -> V_223 . V_231 -> V_225 == V_257 ) {
V_149 = F_60 (
V_26 -> V_223 . V_231 , V_6 , V_200 ) ;
if ( V_149 )
goto V_219;
V_188 . V_252 = V_26 -> V_223 . V_231 ;
goto V_261;
}
if ( V_26 -> V_223 . V_233 -> V_225 == V_257 ) {
V_149 = F_60 (
V_26 -> V_223 . V_233 , V_6 , V_200 ) ;
if ( V_149 )
goto V_219;
V_188 . V_252 = V_26 -> V_223 . V_233 ;
goto V_261;
}
V_255 = 0 ;
do {
if ( V_26 -> V_223 . V_234 [ V_255 ] -> V_225 == V_257 ) {
V_149 = F_60 (
V_26 -> V_223 . V_234 [ V_255 ] ,
V_6 , V_200 ) ;
if ( V_149 )
goto V_219;
V_188 . V_252 =
V_26 -> V_223 . V_234 [ V_255 ] ;
goto V_261;
}
} while ( ++ V_255 < V_26 -> V_229 );
goto V_219;
break;
case V_263 :
if ( V_26 -> V_223 . V_235 -> V_225 == V_257 ) {
V_149 = F_60 (
V_26 -> V_223 . V_235 , V_6 , V_200 ) ;
if ( V_149 )
goto V_219;
V_188 . V_252 = V_26 -> V_223 . V_235 ;
goto V_261;
}
break;
case V_264 :
if ( V_26 -> V_223 . V_236 -> V_225 == V_257 ) {
V_149 = F_60 (
V_26 -> V_223 . V_236 , V_6 , V_200 ) ;
if ( V_149 )
goto V_219;
V_188 . V_252 = V_26 -> V_223 . V_236 ;
goto V_261;
}
for ( V_255 = 0 ; V_255 < V_26 -> V_237 ; V_255 ++ ) {
if ( V_26 -> V_223 . V_238 [ V_255 ] -> V_225 == V_257 ) {
V_149 = F_60 (
V_26 -> V_223 . V_238 [ V_255 ] ,
V_6 , V_200 ) ;
if ( V_149 )
goto V_219;
V_188 . V_252 =
V_26 -> V_223 . V_238 [ V_255 ] ;
goto V_261;
}
}
goto V_219;
break;
case V_265 :
if ( V_26 -> V_223 . V_239 -> V_225 == V_257 ) {
V_149 = F_60 (
V_26 -> V_223 . V_239 , V_6 , V_200 ) ;
if ( V_149 )
goto V_219;
V_188 . V_252 = V_26 -> V_223 . V_239 ;
goto V_261;
}
if ( V_26 -> V_223 . V_240 -> V_225 == V_257 ) {
V_149 = F_60 (
V_26 -> V_223 . V_240 , V_6 , V_200 ) ;
if ( V_149 )
goto V_219;
V_188 . V_252 = V_26 -> V_223 . V_240 ;
goto V_261;
}
goto V_219;
break;
default:
goto V_219;
break;
}
V_261:
if ( V_188 . V_189 . V_183 == V_251 ) {
if ( V_200 == V_243 )
V_188 . V_197 . V_216 = V_6 ;
}
if ( V_188 . V_189 . V_183 == V_193 ||
V_188 . V_189 . V_183 == V_194 ||
V_188 . V_189 . V_183 == V_195 ) {
V_244 = (struct V_241 * ) V_188 . V_252 ;
if ( V_197 > V_244 -> V_226 / sizeof( T_1 ) - 1 )
goto V_219;
V_246 = V_244 -> V_248 [ V_6 ] . V_249 ;
V_246 += V_197 ;
if ( V_188 . V_189 . V_183 == V_193 )
* V_246 = V_217 ;
if ( V_188 . V_189 . V_183 == V_194 )
* V_246 |= V_217 ;
if ( V_188 . V_189 . V_183 == V_195 )
* V_246 &= ~ V_217 ;
}
return V_167 ;
V_219:
memset ( & V_188 , 0 , sizeof( V_188 ) ) ;
return - V_174 ;
}
static int
F_64 ( struct V_25 * V_26 , char * V_201 ,
int V_7 , T_1 V_266 )
{
if ( ! V_201 )
return 0 ;
switch ( V_266 ) {
case V_267 :
V_7 += snprintf ( V_201 + V_7 , V_268 - V_7 ,
L_70 ,
F_15 ( V_26 -> V_223 . V_269 ) ) ;
break;
case V_270 :
V_7 += snprintf ( V_201 + V_7 , V_268 - V_7 ,
L_71 ,
F_15 ( V_26 -> V_223 . V_271 ) ) ;
break;
case V_272 :
V_7 += snprintf ( V_201 + V_7 , V_268 - V_7 ,
L_72 ,
F_15 ( V_26 -> V_223 . V_273 ) ) ;
break;
case V_274 :
V_7 += snprintf ( V_201 + V_7 , V_268 - V_7 ,
L_73 ,
F_15 ( V_26 -> V_223 . V_275 ) ) ;
break;
default:
break;
}
return V_7 ;
}
static T_2
F_65 ( struct V_145 * V_145 , char T_3 * V_3 , T_4 V_167 ,
T_5 * V_168 )
{
struct V_147 * V_148 = V_145 -> V_154 ;
struct V_25 * V_26 = (struct V_25 * ) V_148 -> V_146 ;
T_1 V_276 , V_5 ;
char * V_201 ;
int V_7 = 0 ;
V_148 -> V_186 = V_208 ;
if ( ! V_148 -> V_12 )
V_148 -> V_12 = F_23 ( V_268 , V_153 ) ;
if ( ! V_148 -> V_12 )
return 0 ;
V_201 = V_148 -> V_12 ;
if ( * V_168 )
return 0 ;
if ( V_188 . V_189 . V_183 == V_277 )
V_276 = V_188 . V_189 . V_185 [ 0 ] ;
else
return 0 ;
if ( V_276 == V_278 )
for ( V_5 = 1 ; V_5 <= V_279 ; V_5 ++ )
V_7 = F_64 ( V_26 ,
V_201 , V_7 , V_5 ) ;
else
V_7 = F_64 ( V_26 ,
V_201 , V_7 , V_276 ) ;
return F_39 ( V_3 , V_167 , V_168 , V_201 , V_7 ) ;
}
static T_2
F_66 ( struct V_145 * V_145 , const char T_3 * V_3 ,
T_4 V_167 , T_5 * V_168 )
{
struct V_147 * V_148 = V_145 -> V_154 ;
struct V_25 * V_26 = (struct V_25 * ) V_148 -> V_146 ;
T_1 V_276 , V_217 , V_280 ;
void T_8 * V_281 ;
int V_149 ;
V_148 -> V_186 = V_187 ;
V_149 = F_42 ( V_3 , V_167 , & V_188 . V_189 ) ;
if ( V_149 < 0 )
return V_149 ;
V_276 = V_188 . V_189 . V_185 [ 0 ] ;
V_217 = V_188 . V_189 . V_185 [ 1 ] ;
if ( V_188 . V_189 . V_183 == V_282 ||
V_188 . V_189 . V_183 == V_283 ||
V_188 . V_189 . V_183 == V_284 ) {
if ( V_149 != V_285 )
goto V_219;
if ( V_276 > V_279 )
goto V_219;
} else if ( V_188 . V_189 . V_183 == V_277 ) {
if ( V_149 != V_286 )
goto V_219;
if ( ( V_276 > V_279 ) &&
( V_276 != V_278 ) )
goto V_219;
} else
goto V_219;
if ( V_188 . V_189 . V_183 == V_282 ||
V_188 . V_189 . V_183 == V_283 ||
V_188 . V_189 . V_183 == V_284 ) {
switch ( V_276 ) {
case V_267 :
V_281 = V_26 -> V_223 . V_269 ;
break;
case V_270 :
V_281 = V_26 -> V_223 . V_271 ;
break;
case V_272 :
V_281 = V_26 -> V_223 . V_273 ;
break;
case V_274 :
V_281 = V_26 -> V_223 . V_275 ;
break;
default:
goto V_219;
}
if ( V_188 . V_189 . V_183 == V_282 )
V_280 = V_217 ;
if ( V_188 . V_189 . V_183 == V_283 ) {
V_280 = F_15 ( V_281 ) ;
V_280 |= V_217 ;
}
if ( V_188 . V_189 . V_183 == V_284 ) {
V_280 = F_15 ( V_281 ) ;
V_280 &= ~ V_217 ;
}
F_67 ( V_280 , V_281 ) ;
F_15 ( V_281 ) ;
}
return V_167 ;
V_219:
memset ( & V_188 , 0 , sizeof( V_188 ) ) ;
return - V_174 ;
}
inline void
F_68 ( struct V_1 * V_2 )
{
#ifdef F_19
struct V_25 * V_26 = V_2 -> V_26 ;
char V_113 [ 64 ] ;
T_1 V_287 , V_5 ;
if ( ! V_14 )
return;
if ( ! V_288 ) {
V_288 = F_69 ( L_74 , NULL ) ;
F_70 ( & V_289 , 0 ) ;
if ( ! V_288 ) {
F_71 ( V_2 , V_159 , V_290 ,
L_75 ) ;
goto V_291;
}
}
if ( ! V_20 )
V_20 = V_143 ;
snprintf ( V_113 , sizeof( V_113 ) , L_76 , V_26 -> V_292 ) ;
if ( ! V_26 -> V_293 ) {
V_26 -> V_293 =
F_69 ( V_113 , V_288 ) ;
if ( ! V_26 -> V_293 ) {
F_71 ( V_2 , V_159 , V_290 ,
L_77 ) ;
goto V_291;
}
F_72 ( & V_289 ) ;
F_70 ( & V_26 -> V_294 , 0 ) ;
snprintf ( V_113 , sizeof( V_113 ) , L_78 ) ;
V_26 -> V_295 =
F_73 ( V_113 , V_296 | V_297 | V_298 ,
V_26 -> V_293 ,
V_26 , & V_299 ) ;
if ( ! V_26 -> V_295 ) {
F_71 ( V_2 , V_159 , V_290 ,
L_79 ) ;
goto V_291;
}
if ( V_26 -> V_48 < V_300 ) {
snprintf ( V_113 , sizeof( V_113 ) , L_80 ) ;
V_26 -> V_301 =
F_73 ( V_113 ,
V_296 | V_297 | V_298 ,
V_26 -> V_293 ,
V_26 , & V_302 ) ;
if ( ! V_26 -> V_301 ) {
F_71 ( V_2 , V_159 , V_290 ,
L_81
L_82 ) ;
goto V_291;
}
} else
V_26 -> V_301 = NULL ;
if ( V_26 -> V_48 < V_300 ) {
snprintf ( V_113 , sizeof( V_113 ) , L_83 ) ;
V_26 -> V_303 =
F_73 ( V_113 ,
V_296 | V_297 | V_298 ,
V_26 -> V_293 ,
V_26 , & V_304 ) ;
if ( ! V_26 -> V_303 ) {
F_71 ( V_2 , V_159 , V_290 ,
L_84
L_85 ) ;
goto V_291;
}
} else
V_26 -> V_301 = NULL ;
snprintf ( V_113 , sizeof( V_113 ) , L_86 ) ;
V_26 -> V_305 =
F_73 ( V_113 , V_296 | V_297 | V_298 ,
V_26 -> V_293 ,
V_26 , & V_306 ) ;
if ( ! V_26 -> V_305 ) {
F_71 ( V_2 , V_159 , V_290 ,
L_87 ) ;
goto V_291;
}
snprintf ( V_113 , sizeof( V_113 ) , L_88 ) ;
V_26 -> V_307 =
F_73 ( V_113 , V_296 | V_297 | V_298 ,
V_26 -> V_293 ,
V_26 , & V_308 ) ;
if ( ! V_26 -> V_307 ) {
F_71 ( V_2 , V_159 , V_290 ,
L_89 ) ;
goto V_291;
}
if ( V_28 ) {
V_287 = V_28 - 1 ;
if ( V_287 & V_28 ) {
V_287 = V_28 ;
V_5 = 0 ;
while ( V_287 > 1 ) {
V_287 = V_287 >> 1 ;
V_5 ++ ;
}
V_28 = ( 1 << V_5 ) ;
F_31 ( V_159
L_90
L_91 , V_16 ) ;
}
}
snprintf ( V_113 , sizeof( V_113 ) , L_92 ) ;
V_26 -> V_309 =
F_73 ( V_113 , V_296 | V_297 | V_298 ,
V_26 -> V_293 ,
V_26 , & V_310 ) ;
if ( ! V_26 -> V_309 ) {
F_71 ( V_2 , V_159 , V_290 ,
L_93
L_94 ) ;
goto V_291;
}
if ( ! V_26 -> V_29 ) {
V_26 -> V_29 = F_23 (
( sizeof( struct V_10 ) *
V_28 ) ,
V_153 ) ;
if ( ! V_26 -> V_29 ) {
F_71 ( V_2 , V_159 , V_290 ,
L_95
L_96 ) ;
goto V_291;
}
F_70 ( & V_26 -> V_27 , 0 ) ;
memset ( V_26 -> V_29 , 0 ,
( sizeof( struct V_10 ) *
V_28 ) ) ;
}
}
snprintf ( V_113 , sizeof( V_113 ) , L_97 , V_2 -> V_311 ) ;
if ( ! V_2 -> V_312 ) {
V_2 -> V_312 =
F_69 ( V_113 , V_26 -> V_293 ) ;
if ( ! V_2 -> V_312 ) {
F_71 ( V_2 , V_159 , V_290 ,
L_98 ) ;
goto V_291;
}
F_72 ( & V_26 -> V_294 ) ;
}
if ( V_16 ) {
V_287 = V_16 - 1 ;
if ( V_287 & V_16 ) {
V_287 = V_16 ;
V_5 = 0 ;
while ( V_287 > 1 ) {
V_287 = V_287 >> 1 ;
V_5 ++ ;
}
V_16 = ( 1 << V_5 ) ;
F_31 ( V_159
L_99 ,
V_16 ) ;
}
}
V_2 -> V_17 = F_74 (
( sizeof( struct V_10 ) * V_16 ) ,
V_153 ) ;
if ( ! V_2 -> V_17 ) {
F_71 ( V_2 , V_159 , V_290 ,
L_100
L_101 ) ;
goto V_291;
}
F_70 ( & V_2 -> V_15 , 0 ) ;
snprintf ( V_113 , sizeof( V_113 ) , L_102 ) ;
V_2 -> V_313 =
F_73 ( V_113 , V_296 | V_297 | V_298 ,
V_2 -> V_312 ,
V_2 , & V_314 ) ;
if ( ! V_2 -> V_313 ) {
F_71 ( V_2 , V_159 , V_290 ,
L_103
L_104 ) ;
goto V_291;
}
snprintf ( V_113 , sizeof( V_113 ) , L_105 ) ;
V_2 -> V_315 =
F_73 ( V_113 , V_296 | V_297 | V_298 ,
V_2 -> V_312 ,
V_2 , & V_316 ) ;
if ( ! V_2 -> V_315 ) {
F_71 ( V_2 , V_159 , V_290 ,
L_106 ) ;
goto V_291;
}
if ( V_26 -> V_48 < V_300 )
goto V_291;
snprintf ( V_113 , sizeof( V_113 ) , L_107 ) ;
if ( ! V_26 -> V_317 ) {
V_26 -> V_317 =
F_69 ( V_113 , V_26 -> V_293 ) ;
if ( ! V_26 -> V_317 ) {
F_71 ( V_2 , V_159 , V_290 ,
L_108 ) ;
goto V_291;
}
memset ( & V_188 , 0 , sizeof( V_188 ) ) ;
}
snprintf ( V_113 , sizeof( V_113 ) , L_109 ) ;
if ( ! V_26 -> V_318 ) {
V_26 -> V_318 =
F_73 ( V_113 , V_296 | V_297 | V_298 ,
V_26 -> V_317 , V_26 , & V_319 ) ;
if ( ! V_26 -> V_318 ) {
F_71 ( V_2 , V_159 , V_290 ,
L_110 ) ;
goto V_291;
}
V_188 . V_197 . V_216 = 0 ;
}
snprintf ( V_113 , sizeof( V_113 ) , L_111 ) ;
if ( ! V_26 -> V_320 ) {
V_26 -> V_320 =
F_73 ( V_113 , V_296 | V_297 ,
V_26 -> V_317 , V_26 , & V_321 ) ;
if ( ! V_26 -> V_320 ) {
F_71 ( V_2 , V_159 , V_290 ,
L_112 ) ;
goto V_291;
}
}
snprintf ( V_113 , sizeof( V_113 ) , L_113 ) ;
if ( ! V_26 -> V_322 ) {
V_26 -> V_322 =
F_73 ( V_113 , V_296 | V_297 | V_298 ,
V_26 -> V_317 , V_26 , & V_323 ) ;
if ( ! V_26 -> V_322 ) {
F_71 ( V_2 , V_159 , V_290 ,
L_114 ) ;
goto V_291;
}
}
snprintf ( V_113 , sizeof( V_113 ) , L_115 ) ;
if ( ! V_26 -> V_324 ) {
V_26 -> V_324 =
F_73 ( V_113 , V_296 | V_297 | V_298 ,
V_26 -> V_317 , V_26 , & V_325 ) ;
if ( ! V_26 -> V_324 ) {
F_71 ( V_2 , V_159 , V_290 ,
L_116 ) ;
goto V_291;
}
}
V_291:
return;
#endif
}
inline void
F_75 ( struct V_1 * V_2 )
{
#ifdef F_19
struct V_25 * V_26 = V_2 -> V_26 ;
if ( V_2 -> V_17 ) {
F_25 ( V_2 -> V_17 ) ;
V_2 -> V_17 = NULL ;
}
if ( V_2 -> V_313 ) {
F_76 ( V_2 -> V_313 ) ;
V_2 -> V_313 = NULL ;
}
if ( V_2 -> V_315 ) {
F_76 ( V_2 -> V_315 ) ;
V_2 -> V_315 = NULL ;
}
if ( V_2 -> V_312 ) {
F_76 ( V_2 -> V_312 ) ;
V_2 -> V_312 = NULL ;
F_77 ( & V_26 -> V_294 ) ;
}
if ( F_2 ( & V_26 -> V_294 ) == 0 ) {
if ( V_26 -> V_295 ) {
F_76 ( V_26 -> V_295 ) ;
V_26 -> V_295 = NULL ;
}
if ( V_26 -> V_301 ) {
F_76 ( V_26 -> V_301 ) ;
V_26 -> V_301 = NULL ;
}
if ( V_26 -> V_303 ) {
F_76 ( V_26 -> V_303 ) ;
V_26 -> V_303 = NULL ;
}
if ( V_26 -> V_305 ) {
F_76 ( V_26 -> V_305 ) ;
V_26 -> V_305 = NULL ;
}
if ( V_26 -> V_307 ) {
F_76 ( V_26 -> V_307 ) ;
V_26 -> V_307 = NULL ;
}
if ( V_26 -> V_29 ) {
F_25 ( V_26 -> V_29 ) ;
V_26 -> V_29 = NULL ;
}
if ( V_26 -> V_309 ) {
F_76 ( V_26 -> V_309 ) ;
V_26 -> V_309 = NULL ;
}
if ( V_26 -> V_48 == V_300 ) {
if ( V_26 -> V_324 ) {
F_76 ( V_26 -> V_324 ) ;
V_26 -> V_324 = NULL ;
}
if ( V_26 -> V_322 ) {
F_76 ( V_26 -> V_322 ) ;
V_26 -> V_322 = NULL ;
}
if ( V_26 -> V_320 ) {
F_76 ( V_26 -> V_320 ) ;
V_26 -> V_320 = NULL ;
}
if ( V_26 -> V_318 ) {
F_76 ( V_26 -> V_318 ) ;
V_26 -> V_318 = NULL ;
}
if ( V_26 -> V_317 ) {
F_76 ( V_26 -> V_317 ) ;
V_26 -> V_317 = NULL ;
}
}
if ( V_26 -> V_293 ) {
F_76 ( V_26 -> V_293 ) ;
V_26 -> V_293 = NULL ;
F_77 ( & V_289 ) ;
}
if ( F_2 ( & V_289 ) == 0 ) {
F_76 ( V_288 ) ;
V_288 = NULL ;
}
}
#endif
return;
}
