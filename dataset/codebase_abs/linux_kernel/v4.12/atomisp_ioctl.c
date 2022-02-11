const struct V_1 * F_1 (
unsigned int V_2 )
{
unsigned int V_3 ;
for ( V_3 = 0 ; V_3 < F_2 ( V_4 ) ; V_3 ++ ) {
if ( V_4 [ V_3 ] . V_2 == V_2 )
return & V_4 [ V_3 ] ;
}
return NULL ;
}
const struct V_1 * F_3 (
T_1 V_5 )
{
unsigned int V_3 ;
for ( V_3 = 0 ; V_3 < F_2 ( V_4 ) ; V_3 ++ ) {
if ( V_5 == V_4 [ V_3 ] . V_5 )
return & V_4 [ V_3 ] ;
}
return NULL ;
}
static int F_4 ( struct V_6 * V_6 , void * V_7 ,
struct V_8 * V_9 )
{
memset ( V_9 , 0 , sizeof( struct V_8 ) ) ;
F_5 ( sizeof( V_10 ) > sizeof( V_9 -> V_11 ) ||
sizeof( V_12 ) > sizeof( V_9 -> V_13 ) ||
sizeof( V_14 ) > sizeof( V_9 -> V_15 ) ) ;
strncpy ( V_9 -> V_11 , V_10 , sizeof( V_9 -> V_11 ) - 1 ) ;
strncpy ( V_9 -> V_13 , V_12 , sizeof( V_9 -> V_13 ) - 1 ) ;
strncpy ( V_9 -> V_15 , V_14 , sizeof( V_9 -> V_13 ) - 1 ) ;
V_9 -> V_16 = V_17 ;
V_9 -> V_18 = V_19 |
V_20 | V_21 ;
V_9 -> V_22 = V_9 -> V_18 | V_23 ;
return 0 ;
}
static int F_6 ( struct V_6 * V_6 , void * V_7 ,
struct V_24 * V_25 )
{
struct V_26 * V_27 = F_7 ( V_6 ) ;
struct V_28 * V_29 = F_8 ( V_27 ) ;
int V_30 = V_25 -> V_30 ;
if ( V_30 >= V_29 -> V_31 )
return - V_32 ;
if ( ! V_29 -> V_33 [ V_30 ] . V_34 )
return - V_32 ;
memset ( V_25 , 0 , sizeof( struct V_24 ) ) ;
strncpy ( V_25 -> V_35 , V_29 -> V_33 [ V_30 ] . V_34 -> V_35 ,
sizeof( V_25 -> V_35 ) - 1 ) ;
#ifndef F_9
if ( V_29 -> V_33 [ V_30 ] . V_36 &&
strlen ( V_29 -> V_33 [ V_30 ] . V_36 -> V_35 ) > 0 ) {
#else
if ( V_29 -> V_36 &&
strlen ( V_29 -> V_36 -> V_35 ) > 0 ) {
#endif
const int V_37 = strlen ( V_25 -> V_35 ) ;
const int V_38 = sizeof( V_25 -> V_35 ) - V_37 - 1 ;
if ( V_38 > 1 ) {
V_25 -> V_35 [ V_37 ] = '+' ;
strncpy ( & V_25 -> V_35 [ V_37 + 1 ] ,
#ifndef F_9
V_29 -> V_33 [ V_30 ] . V_36 -> V_35 , V_38 - 1 ) ;
#else
V_29 -> V_36 -> V_35 , V_38 - 1 ) ;
#endif
}
}
V_25 -> type = V_39 ;
V_25 -> V_30 = V_30 ;
V_25 -> V_40 [ 0 ] = V_29 -> V_33 [ V_30 ] . type ;
V_25 -> V_40 [ 1 ] = V_29 -> V_33 [ V_30 ] . V_41 ;
return 0 ;
}
static unsigned int F_10 (
struct V_42 * V_43 )
{
return V_43 -> V_44 . V_45 . V_46
+ V_43 -> V_47 . V_45 . V_46
+ V_43 -> V_48 . V_45 . V_46
+ V_43 -> V_49 . V_45 . V_46
+ V_43 -> V_50 . V_45 . V_46 ;
}
unsigned int F_11 ( struct V_28 * V_29 )
{
unsigned int V_3 , V_51 ;
for ( V_3 = 0 , V_51 = 0 ; V_3 < V_29 -> V_52 ; V_3 ++ )
V_51 += V_29 -> V_43 [ V_3 ] . V_46 ==
V_53 ;
return V_51 ;
}
unsigned int F_12 ( struct V_28 * V_29 )
{
unsigned int V_3 ;
for ( V_3 = 0 ; V_3 < V_29 -> V_52 ; V_3 ++ )
if ( V_29 -> V_43 [ V_3 ] . V_54 . V_55 )
return 1 ;
return 0 ;
}
static int F_13 ( struct V_6 * V_6 , void * V_7 , unsigned int * V_25 )
{
struct V_26 * V_27 = F_7 ( V_6 ) ;
struct V_28 * V_29 = F_8 ( V_27 ) ;
struct V_42 * V_43 = F_14 ( V_27 ) -> V_43 ;
F_15 ( & V_29 -> V_56 ) ;
* V_25 = V_43 -> V_57 ;
F_16 ( & V_29 -> V_56 ) ;
return 0 ;
}
static int F_17 ( struct V_6 * V_6 , void * V_7 , unsigned int V_25 )
{
struct V_26 * V_27 = F_7 ( V_6 ) ;
struct V_28 * V_29 = F_8 ( V_27 ) ;
struct V_42 * V_43 = F_14 ( V_27 ) -> V_43 ;
struct V_58 * V_34 = NULL ;
int V_59 ;
F_15 ( & V_29 -> V_56 ) ;
if ( V_25 >= V_60 || V_25 > V_29 -> V_31 ) {
F_18 ( V_29 -> V_61 , L_1 , V_29 -> V_31 ) ;
V_59 = - V_32 ;
goto error;
}
if ( V_29 -> V_33 [ V_25 ] . V_43 != NULL && V_29 -> V_33 [ V_25 ] . V_43 != V_43 ) {
F_19 ( V_29 -> V_61 ,
L_2 , V_62 ,
V_29 -> V_33 [ V_25 ] . V_43 -> V_30 ) ;
V_59 = - V_63 ;
goto error;
}
V_34 = V_29 -> V_33 [ V_25 ] . V_34 ;
if ( ! V_34 ) {
F_19 ( V_29 -> V_61 , L_3 , V_62 ) ;
V_59 = - V_32 ;
goto error;
}
if ( F_10 ( V_43 ) ) {
F_19 ( V_29 -> V_61 ,
L_4 ) ;
V_59 = - V_32 ;
goto error;
}
if ( V_29 -> V_33 [ V_43 -> V_57 ] . V_43 == V_43 &&
V_43 -> V_57 != V_25 ) {
V_59 = F_20 ( V_29 -> V_33 [ V_43 -> V_57 ] . V_34 ,
V_64 , V_65 , 0 ) ;
if ( V_59 )
F_21 ( V_29 -> V_61 ,
L_5 ) ;
V_29 -> V_33 [ V_43 -> V_57 ] . V_43 = NULL ;
}
V_59 = F_20 ( V_29 -> V_33 [ V_25 ] . V_34 , V_64 , V_65 , 1 ) ;
if ( V_59 ) {
F_19 ( V_29 -> V_61 , L_6 ) ;
goto error;
}
F_22 ( V_43 ) ;
V_59 = F_20 ( V_29 -> V_33 [ V_25 ] . V_34 , V_66 , V_67 ,
0 , V_29 -> V_33 [ V_25 ] . V_68 , 0 ) ;
if ( V_59 && ( V_59 != - V_69 ) ) {
F_19 ( V_29 -> V_61 , L_7 ) ;
goto error;
}
#ifndef F_9
if ( ! V_29 -> V_70 . V_71 && V_29 -> V_33 [ V_25 ] . V_36 )
V_59 = F_20 ( V_29 -> V_33 [ V_25 ] . V_36 , V_64 ,
V_72 , 1 ) ;
#else
if ( V_29 -> V_36 )
V_59 = F_20 ( V_29 -> V_36 , V_64 , V_65 , 1 ) ;
if ( ! V_29 -> V_70 . V_71 && V_29 -> V_36 )
V_59 = F_20 ( V_29 -> V_36 , V_64 , V_72 , 1 ) ;
#endif
V_43 -> V_57 = V_25 ;
V_29 -> V_33 [ V_25 ] . V_43 = V_43 ;
F_16 ( & V_29 -> V_56 ) ;
return 0 ;
error:
F_16 ( & V_29 -> V_56 ) ;
return V_59 ;
}
static int F_23 ( struct V_6 * V_6 , void * V_7 ,
struct V_73 * V_74 )
{
struct V_26 * V_27 = F_7 ( V_6 ) ;
struct V_28 * V_29 = F_8 ( V_27 ) ;
struct V_42 * V_43 = F_14 ( V_27 ) -> V_43 ;
struct V_75 V_76 = { 0 } ;
unsigned int V_3 , V_77 = 0 ;
int V_78 ;
F_15 ( & V_29 -> V_56 ) ;
V_78 = F_20 ( V_29 -> V_33 [ V_43 -> V_57 ] . V_34 , V_79 ,
V_80 , NULL , & V_76 ) ;
if ( V_78 == - V_69 ) {
F_21 ( V_29 -> V_61 , L_8 ) ;
}
F_16 ( & V_29 -> V_56 ) ;
if ( V_78 )
return V_78 ;
for ( V_3 = 0 ; V_3 < F_2 ( V_4 ) ; V_3 ++ ) {
const struct V_1 * V_81 =
& V_4 [ V_3 ] ;
if ( V_81 -> V_82 == V_83
&& V_81 -> V_5 != V_76 . V_76 )
continue;
if ( V_77 < V_74 -> V_30 ) {
V_77 ++ ;
continue;
}
F_24 ( V_74 -> V_84 , V_81 -> V_84 ,
sizeof( V_74 -> V_84 ) ) ;
V_74 -> V_2 = V_81 -> V_2 ;
return 0 ;
}
return - V_32 ;
}
static int F_25 ( struct V_6 * V_6 , void * V_7 ,
struct V_85 * V_74 )
{
struct V_26 * V_27 = F_7 ( V_6 ) ;
struct V_28 * V_29 = F_8 ( V_27 ) ;
int V_59 ;
F_15 ( & V_29 -> V_56 ) ;
V_59 = F_26 ( V_27 , V_74 ) ;
F_16 ( & V_29 -> V_56 ) ;
return V_59 ;
}
static int F_27 ( struct V_6 * V_6 , void * V_7 ,
struct V_85 * V_74 )
{
struct V_26 * V_27 = F_7 ( V_6 ) ;
struct V_28 * V_29 = F_8 ( V_27 ) ;
struct V_86 * V_87 = F_14 ( V_27 ) ;
F_15 ( & V_29 -> V_56 ) ;
V_74 -> V_88 . V_89 = V_87 -> V_89 ;
F_16 ( & V_29 -> V_56 ) ;
return 0 ;
}
static int F_28 ( struct V_6 * V_6 , void * V_7 ,
struct V_85 * V_74 )
{
struct V_26 * V_27 = F_7 ( V_6 ) ;
struct V_28 * V_29 = F_8 ( V_27 ) ;
int V_59 ;
F_15 ( & V_29 -> V_56 ) ;
V_59 = F_29 ( V_27 , V_74 , NULL ) ;
F_16 ( & V_29 -> V_56 ) ;
return V_59 ;
}
static int F_30 ( struct V_6 * V_6 , void * V_7 ,
struct V_85 * V_74 )
{
struct V_26 * V_27 = F_7 ( V_6 ) ;
struct V_28 * V_29 = F_8 ( V_27 ) ;
int V_59 ;
F_15 ( & V_29 -> V_56 ) ;
if ( V_29 -> V_90 ) {
V_59 = - V_91 ;
F_16 ( & V_29 -> V_56 ) ;
return V_59 ;
}
V_59 = F_31 ( V_27 , V_74 ) ;
F_16 ( & V_29 -> V_56 ) ;
return V_59 ;
}
static int F_32 ( struct V_6 * V_6 , void * V_7 ,
struct V_85 * V_74 )
{
struct V_26 * V_27 = F_7 ( V_6 ) ;
struct V_28 * V_29 = F_8 ( V_27 ) ;
int V_59 ;
F_15 ( & V_29 -> V_56 ) ;
V_59 = F_33 ( V_27 , V_74 ) ;
F_16 ( & V_29 -> V_56 ) ;
return V_59 ;
}
void F_34 ( struct V_92 * V_93 )
{
struct V_94 * V_95 ;
if ( V_93 == NULL )
return;
V_95 = V_93 -> V_96 ;
if ( V_95 && V_95 -> V_97 ) {
F_35 ( V_95 -> V_97 ) ;
V_95 -> V_97 = NULL ;
}
}
static void F_36 ( struct V_98 * V_99 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < V_100 ; V_3 ++ ) {
F_34 ( V_99 -> V_101 [ V_3 ] ) ;
F_37 ( V_99 -> V_101 [ V_3 ] ) ;
V_99 -> V_101 [ V_3 ] = NULL ;
}
}
int F_38 ( struct V_42 * V_43 ,
T_2 V_102 )
{
struct V_28 * V_29 = V_43 -> V_29 ;
struct V_103 * V_104 = NULL , * V_105 ;
struct V_106 * V_107 = NULL , * V_108 ;
struct V_109 * V_110 = NULL , * V_111 ;
int V_112 ;
struct V_113 * V_114 =
F_39 ( & V_43 -> V_115 . V_116 ) ;
unsigned int V_3 ;
if ( F_40 ( & V_43 -> V_117 ) &&
V_43 -> V_115 . V_116 . V_118 . V_119 ) {
V_112 = V_120 +
V_121 ;
F_18 ( V_29 -> V_61 , L_9 , V_112 ) ;
while ( V_112 -- ) {
V_104 = F_41 ( sizeof( struct V_103 ) , V_122 ) ;
if ( ! V_104 ) {
F_19 ( V_29 -> V_61 , L_10 ) ;
goto error;
}
if ( F_42 (
V_43 , V_102 , V_104 , NULL , NULL ) ) {
F_37 ( V_104 ) ;
goto error;
}
F_43 ( & V_104 -> V_123 , & V_43 -> V_117 ) ;
}
}
if ( F_40 ( & V_43 -> V_124 ) && V_114 &&
V_114 -> V_119 ) {
V_112 = V_120 + 1 ;
F_18 ( V_29 -> V_61 , L_11 , V_112 ) ;
while ( V_112 -- ) {
V_107 = F_41 ( sizeof( struct V_106 ) , V_122 ) ;
if ( ! V_107 ) {
F_19 ( V_29 -> V_61 , L_12 ) ;
F_37 ( V_104 ) ;
goto error;
}
if ( F_42 (
V_43 , V_102 , NULL , V_107 , NULL ) ) {
F_37 ( V_107 ) ;
goto error;
}
F_43 ( & V_107 -> V_123 , & V_43 -> V_124 ) ;
}
}
for ( V_3 = 0 ; V_3 < V_125 ; V_3 ++ ) {
if ( F_40 ( & V_43 -> V_126 [ V_3 ] ) &&
F_40 ( & V_43 -> V_127 [ V_3 ] ) &&
F_40 ( & V_43 -> V_128 [ V_3 ] ) ) {
V_112 = V_120 +
V_129 ;
F_18 ( V_29 -> V_61 , L_13 ,
V_112 , V_3 ) ;
while ( V_112 -- ) {
V_110 = F_41 ( sizeof( struct V_109 ) ,
V_122 ) ;
if ( ! V_110 ) {
F_19 ( V_29 -> V_61 , L_14 ) ;
goto error;
}
if ( F_42 (
V_43 , V_102 , NULL , NULL , V_110 ) ) {
F_37 ( V_110 ) ;
goto error;
}
F_43 ( & V_110 -> V_123 , & V_43 -> V_126 [ V_3 ] ) ;
}
}
}
return 0 ;
error:
F_19 ( V_29 -> V_61 , L_15 ) ;
F_44 (dis_buf, _dis_buf, &asd->dis_stats, list) {
F_45 ( V_107 ) ;
F_46 ( & V_107 -> V_123 ) ;
F_37 ( V_107 ) ;
}
F_44 (s3a_buf, _s3a_buf, &asd->s3a_stats, list) {
F_47 ( V_104 ) ;
F_46 ( & V_104 -> V_123 ) ;
F_37 ( V_104 ) ;
}
for ( V_3 = 0 ; V_3 < V_125 ; V_3 ++ ) {
F_44 (md_buf, _md_buf, &asd->metadata[i],
list) {
F_48 ( V_110 ) ;
F_46 ( & V_110 -> V_123 ) ;
F_37 ( V_110 ) ;
}
}
return - V_130 ;
}
int F_49 ( struct V_6 * V_6 , void * V_7 ,
struct V_131 * V_132 )
{
struct V_26 * V_27 = F_7 ( V_6 ) ;
struct V_86 * V_87 = F_14 ( V_27 ) ;
struct V_42 * V_43 = V_87 -> V_43 ;
struct V_133 V_134 ;
struct V_135 * V_136 ;
struct V_94 * V_95 ;
T_2 V_137 = F_50 ( V_27 ) ;
T_2 V_102 = F_51 ( V_43 , V_137 ) ;
int V_59 = 0 , V_3 = 0 ;
if ( V_132 -> V_112 == 0 ) {
F_52 ( & V_87 -> V_45 . V_138 ) ;
if ( ! F_40 ( & V_87 -> V_45 . V_139 ) )
F_53 ( & V_87 -> V_45 ) ;
F_36 ( & V_87 -> V_45 ) ;
F_54 ( & V_87 -> V_45 . V_138 ) ;
memset ( V_87 -> V_140 , 0 ,
V_100 * sizeof( unsigned int ) ) ;
memset ( V_87 -> V_141 , 0 ,
V_100 *
sizeof( struct V_142 * ) ) ;
return 0 ;
}
V_59 = F_55 ( & V_87 -> V_45 , V_132 ) ;
if ( V_59 )
return V_59 ;
F_38 ( V_43 , V_102 ) ;
if ( V_132 -> V_143 == V_144 )
return 0 ;
V_59 = F_56 ( V_43 , V_137 , & V_134 ) ;
if ( V_59 )
return V_59 ;
for ( V_3 = 0 ; V_3 < V_132 -> V_112 ; V_3 ++ ) {
if ( F_57 ( & V_136 , & V_134 ) )
goto error;
V_95 = V_87 -> V_45 . V_101 [ V_3 ] -> V_96 ;
V_95 -> V_97 = V_136 ;
}
return V_59 ;
error:
while ( V_3 -- ) {
V_95 = V_87 -> V_45 . V_101 [ V_3 ] -> V_96 ;
F_35 ( V_95 -> V_97 ) ;
}
if ( V_43 -> V_145 )
F_35 ( V_43 -> V_145 ) ;
return - V_130 ;
}
int F_58 ( struct V_6 * V_6 , void * V_7 ,
struct V_131 * V_132 )
{
struct V_26 * V_27 = F_7 ( V_6 ) ;
struct V_28 * V_29 = F_8 ( V_27 ) ;
int V_59 ;
F_15 ( & V_29 -> V_56 ) ;
V_59 = F_49 ( V_6 , V_7 , V_132 ) ;
F_16 ( & V_29 -> V_56 ) ;
return V_59 ;
}
static int F_59 ( struct V_6 * V_6 , void * V_7 ,
struct V_131 * V_132 )
{
struct V_26 * V_27 = F_7 ( V_6 ) ;
struct V_86 * V_87 = F_14 ( V_27 ) ;
if ( V_132 -> V_112 == 0 ) {
F_52 ( & V_87 -> V_146 . V_138 ) ;
F_36 ( & V_87 -> V_146 ) ;
F_54 ( & V_87 -> V_146 . V_138 ) ;
return 0 ;
}
return F_55 ( & V_87 -> V_146 , V_132 ) ;
}
static int F_60 ( struct V_6 * V_6 , void * V_7 ,
struct V_147 * V_148 )
{
struct V_26 * V_27 = F_7 ( V_6 ) ;
struct V_86 * V_87 = F_14 ( V_27 ) ;
return F_61 ( & V_87 -> V_45 , V_148 ) ;
}
static int F_62 ( struct V_6 * V_6 , void * V_7 ,
struct V_147 * V_148 )
{
struct V_26 * V_27 = F_7 ( V_6 ) ;
struct V_86 * V_87 = F_14 ( V_27 ) ;
return F_61 ( & V_87 -> V_146 , V_148 ) ;
}
static int F_63 ( struct V_6 * V_6 , void * V_7 , struct V_147 * V_148 )
{
static const int V_149 = V_150 |
V_151 ;
struct V_26 * V_27 = F_7 ( V_6 ) ;
struct V_28 * V_29 = F_8 ( V_27 ) ;
struct V_86 * V_87 = F_14 ( V_27 ) ;
struct V_42 * V_43 = V_87 -> V_43 ;
struct V_92 * V_93 ;
struct V_94 * V_95 ;
struct V_133 V_134 ;
struct V_135 * V_152 = NULL ;
T_1 V_153 ;
T_1 V_154 ;
int V_59 = 0 ;
F_15 ( & V_29 -> V_56 ) ;
if ( V_29 -> V_90 ) {
V_59 = - V_91 ;
goto error;
}
if ( V_43 -> V_46 == V_155 ) {
F_19 ( V_29 -> V_61 , L_16 ,
V_62 ) ;
V_59 = - V_91 ;
goto error;
}
if ( ! V_148 || V_148 -> V_30 >= V_100 ||
! V_87 -> V_45 . V_101 [ V_148 -> V_30 ] ) {
F_19 ( V_29 -> V_61 , L_17 ) ;
V_59 = - V_32 ;
goto error;
}
if ( V_148 -> V_143 == V_144 ) {
struct V_156 V_157 ;
V_93 = V_87 -> V_45 . V_101 [ V_148 -> V_30 ] ;
V_95 = V_93 -> V_96 ;
if ( ! V_95 ) {
V_59 = - V_32 ;
goto error;
}
V_153 = V_93 -> V_158 ;
V_154 = ( V_153 + ( V_159 - 1 ) ) >> V_160 ;
if ( V_93 -> V_161 == V_148 -> V_162 . V_163 && V_95 -> V_97 )
goto V_164;
if ( F_56 ( V_43 ,
F_50 ( V_27 ) , & V_134 ) ) {
V_59 = - V_91 ;
goto error;
}
V_157 . V_154 = V_154 ;
#ifdef F_64
#ifndef F_9
V_157 . type = V_148 -> type == V_165
? V_166 : V_167 ;
#else
if ( V_148 -> V_40 & V_168 ) {
V_157 . type = V_166 ;
if ( V_43 -> V_169 -> V_170 != V_171 ) {
F_18 ( V_29 -> V_61 , L_18 ,
V_148 -> V_162 . V_163 , V_43 -> V_169 -> V_170 ) ;
if ( ( V_148 -> V_162 . V_163 &
( V_172 ) ) != 0 ) {
F_19 ( V_29 -> V_61 ,
L_19 ,
V_148 -> V_162 . V_163 ) ;
V_59 = - V_32 ;
goto error;
}
V_148 -> V_162 . V_163 |= V_43 -> V_169 -> V_170 <<
V_173 ;
} else {
F_19 ( V_29 -> V_61 , L_20 ) ;
V_59 = - V_32 ;
goto error;
}
} else {
V_157 . type = V_167 ;
}
#endif
#else
V_157 . type = V_167 ;
#endif
V_59 = F_65 ( & V_152 , & V_134 ,
( void * ) V_148 -> V_162 . V_163 ,
0 , & V_157 ) ;
if ( V_59 ) {
F_19 ( V_29 -> V_61 , L_21 ) ;
goto error;
}
if ( V_95 -> V_97 ) {
F_52 ( & V_87 -> V_45 . V_138 ) ;
F_35 ( V_95 -> V_97 ) ;
V_95 -> V_97 = NULL ;
V_93 -> V_174 = V_175 ;
F_54 ( & V_87 -> V_45 . V_138 ) ;
}
V_95 -> V_97 = V_152 ;
V_148 -> V_176 &= ~ V_177 ;
V_148 -> V_176 |= V_178 ;
V_148 -> V_176 &= ~ V_179 ;
} else if ( V_148 -> V_143 == V_180 ) {
V_148 -> V_176 |= V_177 ;
V_148 -> V_176 |= V_178 ;
V_148 -> V_176 &= ~ V_179 ;
}
V_164:
if ( ! ( ( V_148 -> V_176 & V_149 ) == V_149 ) )
F_66 () ;
if ( ! F_67 ( V_87 ) &&
( V_148 -> V_181 & V_182 ) ) {
V_87 -> V_140 [ V_148 -> V_30 ] = V_148 -> V_181 &
~ V_182 ;
F_18 ( V_29 -> V_61 , L_22 ,
V_87 -> V_140 [ V_148 -> V_30 ] ) ;
} else {
V_87 -> V_140 [ V_148 -> V_30 ] = 0 ;
}
V_87 -> V_141 [ V_148 -> V_30 ] = NULL ;
F_16 ( & V_29 -> V_56 ) ;
V_59 = F_68 ( & V_87 -> V_45 , V_148 ) ;
F_15 ( & V_29 -> V_56 ) ;
if ( V_59 )
goto error;
if ( V_43 -> V_46 == V_53 ) {
if ( ! F_40 ( & V_87 -> V_183 ) ) {
F_69 ( V_87 ) ;
} else {
F_70 ( V_43 ) ;
#ifndef F_9
if ( ! F_71 ( V_43 ) && F_72 ( V_43 ) )
F_73 ( V_43 ) ;
#else
if ( ! F_71 ( V_87 ) &&
F_74 ( V_87 ) )
F_73 ( V_87 ) ;
#endif
}
}
if ( V_43 -> V_184 -> V_170 &&
F_50 ( V_27 )
== V_185 &&
V_87 -> V_45 . V_46 &&
! V_43 -> V_186 -> V_170 &&
V_43 -> V_115 . V_187 . V_188 == 1 ) {
#ifndef F_9
V_43 -> V_189 ++ ;
F_18 ( V_29 -> V_61 , L_23 ) ;
#else
if ( V_43 -> V_190 ) {
V_59 = F_75 ( V_43 ,
V_43 -> V_115 . V_187 . V_188 ,
V_43 -> V_115 . V_187 . V_191 ,
V_43 -> V_115 . V_187 . V_192 ) ;
V_43 -> V_190 = false ;
F_18 ( V_29 -> V_61 , L_24 ,
V_62 , V_59 ) ;
} else {
V_43 -> V_189 ++ ;
V_43 -> V_190 = false ;
F_18 ( V_29 -> V_61 , L_23 ) ;
}
#endif
}
F_16 ( & V_29 -> V_56 ) ;
F_18 ( V_29 -> V_61 , L_25 , V_148 -> V_30 ,
V_27 -> V_35 , V_43 -> V_30 ) ;
return V_59 ;
error:
F_16 ( & V_29 -> V_56 ) ;
return V_59 ;
}
static int F_76 ( struct V_6 * V_6 , void * V_7 ,
struct V_147 * V_148 )
{
struct V_26 * V_27 = F_7 ( V_6 ) ;
struct V_28 * V_29 = F_8 ( V_27 ) ;
struct V_86 * V_87 = F_14 ( V_27 ) ;
int V_59 ;
F_15 ( & V_29 -> V_56 ) ;
if ( V_29 -> V_90 ) {
V_59 = - V_91 ;
goto error;
}
if ( ! V_148 || V_148 -> V_30 >= V_100 ||
! V_87 -> V_146 . V_101 [ V_148 -> V_30 ] ) {
F_19 ( V_29 -> V_61 , L_17 ) ;
V_59 = - V_32 ;
goto error;
}
if ( V_148 -> V_143 != V_180 ) {
F_19 ( V_29 -> V_61 , L_26 ) ;
V_59 = - V_32 ;
goto error;
}
if ( V_148 -> type != V_193 ) {
F_19 ( V_29 -> V_61 , L_27 ) ;
V_59 = - V_32 ;
goto error;
}
F_16 ( & V_29 -> V_56 ) ;
return F_68 ( & V_87 -> V_146 , V_148 ) ;
error:
F_16 ( & V_29 -> V_56 ) ;
return V_59 ;
}
static int F_77 ( struct V_86 * V_87 ,
struct V_147 * V_148 )
{
struct V_94 * V_95 ;
struct V_135 * V_152 ;
int V_3 ;
for ( V_3 = 0 ; V_87 -> V_45 . V_101 [ V_3 ] ; V_3 ++ ) {
V_95 = V_87 -> V_45 . V_101 [ V_3 ] -> V_96 ;
V_152 = V_95 -> V_97 ;
if ( V_148 -> V_30 == V_87 -> V_45 . V_101 [ V_3 ] -> V_3 && V_152 )
return V_152 -> V_194 ;
}
return - V_32 ;
}
static int F_78 ( struct V_6 * V_6 , void * V_7 , struct V_147 * V_148 )
{
struct V_26 * V_27 = F_7 ( V_6 ) ;
struct V_86 * V_87 = F_14 ( V_27 ) ;
struct V_42 * V_43 = V_87 -> V_43 ;
struct V_28 * V_29 = F_8 ( V_27 ) ;
int V_59 = 0 ;
F_15 ( & V_29 -> V_56 ) ;
if ( V_29 -> V_90 ) {
F_16 ( & V_29 -> V_56 ) ;
return - V_91 ;
}
if ( V_43 -> V_46 == V_155 ) {
F_16 ( & V_29 -> V_56 ) ;
F_19 ( V_29 -> V_61 , L_16 ,
V_62 ) ;
return - V_91 ;
}
F_16 ( & V_29 -> V_56 ) ;
V_59 = F_79 ( & V_87 -> V_45 , V_148 , V_6 -> V_195 & V_196 ) ;
if ( V_59 ) {
F_18 ( V_29 -> V_61 , L_28 , V_62 , V_59 ) ;
return V_59 ;
}
F_15 ( & V_29 -> V_56 ) ;
V_148 -> V_197 = V_87 -> V_89 . V_198 ;
V_148 -> V_40 = V_43 -> V_199 [ V_148 -> V_30 ] ;
V_148 -> V_40 &= 0x0000ffff ;
if ( ! ( V_148 -> V_176 & V_200 ) )
V_148 -> V_40 |= F_77 ( V_87 , V_148 ) << 16 ;
V_148 -> V_181 = V_87 -> V_201 [ V_148 -> V_30 ] ;
F_16 ( & V_29 -> V_56 ) ;
F_18 ( V_29 -> V_61 , L_29 ,
V_148 -> V_30 , V_27 -> V_35 , V_43 -> V_30 , V_148 -> V_40 >> 16 ,
V_148 -> V_181 ) ;
return 0 ;
}
enum V_202 F_80 ( struct V_42 * V_43 )
{
if ( F_81 ( V_43 ) )
return V_203 ;
if ( V_43 -> V_184 -> V_170 ) {
if ( V_43 -> V_204 -> V_170 == V_205 )
return V_206 ;
else
return V_207 ;
}
if ( V_43 -> V_208 -> V_170 == V_209 )
return V_206 ;
if ( V_43 -> V_208 -> V_170 == V_210 )
return V_211 ;
switch ( V_43 -> V_204 -> V_170 ) {
case V_212 :
return V_207 ;
case V_205 :
return V_206 ;
case V_213 :
default:
return V_211 ;
}
}
static unsigned int F_82 ( struct V_42 * V_43 )
{
struct V_28 * V_29 = V_43 -> V_29 ;
if ( V_29 -> V_33 [ V_43 -> V_57 ] . V_214 ->
V_215 [ V_43 -> V_216 ] . V_217 > 1 ) {
if ( V_43 -> V_218 )
return 1 ;
else
return 2 ;
}
if ( V_43 -> V_208 -> V_170 != V_219 ||
V_43 -> V_220 )
return 1 ;
if ( V_43 -> V_204 -> V_170 == V_205 ||
( V_43 -> V_204 -> V_170 == V_213 &&
! F_83 (
V_43 -> V_88 [
V_43 -> V_221 ] . V_88 . V_76 ) &&
! V_43 -> V_184 -> V_170 ) )
return 2 ;
else
return 1 ;
}
int F_84 ( struct V_28 * V_29 ,
bool V_222 )
{
unsigned int V_223 = - 1 , V_224 = - 1 , V_225 = 0 ;
int V_3 , V_59 ;
for ( V_3 = 0 ; V_3 < V_29 -> V_52 ; V_3 ++ ) {
int V_68 = V_29 -> V_43 [ V_3 ] . V_57 ;
if ( V_29 -> V_33 [ V_68 ] . V_214 ->
V_215 [ V_29 -> V_43 [ V_3 ] . V_216 ] . V_226 )
V_224 = V_68 ;
else
V_223 = V_68 ;
}
if ( V_223 == - 1 || V_224 == - 1 ) {
V_223 = V_227 ;
V_224 = V_228 ;
F_21 ( V_29 -> V_61 ,
L_30 ,
V_29 -> V_33 [ V_223 ] . V_34 -> V_35 ,
V_29 -> V_33 [ V_224 ] . V_34 -> V_35 ) ;
}
V_59 = F_20 ( V_29 -> V_33 [ V_223 ] . V_34 , V_64 ,
V_229 , V_230 ,
& V_225 ) ;
if ( V_59 )
F_21 ( V_29 -> V_61 ,
L_31 ,
V_29 -> V_33 [ V_223 ] . V_34 -> V_35 ) ;
V_59 = F_20 ( V_29 -> V_33 [ V_223 ] . V_34 ,
V_66 , V_231 , 1 ) ;
if ( V_59 ) {
F_19 ( V_29 -> V_61 , L_32 ,
V_29 -> V_33 [ V_223 ] . V_34 -> V_35 ) ;
return - V_32 ;
}
if ( V_225 != 0 )
F_85 ( V_225 ) ;
V_59 = F_20 ( V_29 -> V_33 [ V_224 ] . V_34 ,
V_66 , V_231 , 1 ) ;
if ( V_59 ) {
F_19 ( V_29 -> V_61 , L_33 ,
V_29 -> V_33 [ V_224 ] . V_34 -> V_35 ) ;
F_20 ( V_29 -> V_33 [ V_223 ] . V_34 , V_66 , V_231 , 0 ) ;
return - V_32 ;
}
return 0 ;
}
static void F_86 ( struct V_28 * V_29 )
{
struct V_232 V_233 = { 0 } ;
int V_3 ;
V_233 . type = V_234 ;
for ( V_3 = 0 ; V_3 < V_29 -> V_52 ; V_3 ++ ) {
int V_68 = V_29 -> V_43 [ V_3 ] . V_57 ;
if ( V_29 -> V_33 [ V_68 ] . V_214 ->
V_215 [ V_29 -> V_43 [ V_3 ] . V_216 ] . V_226 ) {
F_87 ( V_29 -> V_43 [ V_3 ] . V_235 . V_236 , & V_233 ) ;
break;
}
}
}
static void F_88 ( struct V_42 * V_43 )
{
struct V_237 * V_238 ;
V_238 = F_89 ( & V_43 -> V_235 , NULL ,
V_239 ,
V_240 ) ;
if ( V_238 -> V_241 * V_238 -> V_242 >= 4096 * 3072 )
F_90 ( V_243 , 0x7F ) ;
else
F_90 ( V_243 , 0x00 ) ;
}
static int F_91 ( struct V_6 * V_6 , void * V_7 ,
enum V_244 type )
{
struct V_26 * V_27 = F_7 ( V_6 ) ;
struct V_86 * V_87 = F_14 ( V_27 ) ;
struct V_42 * V_43 = V_87 -> V_43 ;
struct V_28 * V_29 = F_8 ( V_27 ) ;
enum V_202 V_245 ;
unsigned int V_246 ;
unsigned int V_247 = V_248 ;
int V_59 = 0 ;
unsigned long V_249 ;
F_18 ( V_29 -> V_61 , L_34 ,
F_50 ( V_27 ) , V_43 -> V_30 ) ;
if ( type != V_250 ) {
F_18 ( V_29 -> V_61 , L_35 ) ;
return - V_32 ;
}
F_15 ( & V_29 -> V_56 ) ;
if ( V_29 -> V_90 ) {
V_59 = - V_91 ;
goto V_251;
}
if ( V_43 -> V_46 == V_155 ) {
V_59 = - V_63 ;
goto V_251;
}
if ( V_87 -> V_45 . V_46 )
goto V_251;
F_88 ( V_43 ) ;
V_246 = F_82 ( V_43 ) ;
F_92 ( & V_87 -> V_252 , V_249 ) ;
if ( F_40 ( & ( V_87 -> V_45 . V_139 ) ) ) {
F_93 ( & V_87 -> V_252 , V_249 ) ;
F_18 ( V_29 -> V_61 , L_36 ) ;
V_59 = - V_32 ;
goto V_251;
}
F_93 ( & V_87 -> V_252 , V_249 ) ;
V_59 = F_94 ( & V_87 -> V_45 ) ;
if ( V_59 )
goto V_251;
V_43 -> V_189 = 0 ;
#ifdef F_9
V_43 -> V_190 = false ;
#endif
if ( ( F_10 ( V_43 ) > V_246 ) &&
( ! V_29 -> V_33 [ V_43 -> V_57 ] . V_214 -> V_253 ) ) {
if ( V_43 -> V_184 -> V_170 &&
F_50 ( V_27 )
== V_185 ) {
if ( V_43 -> V_204 -> V_170 == V_205 )
F_18 ( V_29 -> V_61 , L_37 ,
V_43 -> V_254 ) ;
else
F_18 ( V_29 -> V_61 , L_38 ,
V_43 -> V_254 ) ;
if ( V_43 -> V_255 == V_256 ) {
F_95 ( & V_43 -> V_257 ) ;
F_16 ( & V_29 -> V_56 ) ;
if ( F_96 (
& V_43 -> V_258 ) != 0 )
return - V_259 ;
F_15 ( & V_29 -> V_56 ) ;
}
F_69 ( V_87 ) ;
F_97 ( V_29 , V_260 , false ) ;
if ( ! V_43 -> V_186 -> V_170 ) {
V_59 = F_75 ( V_43 ,
V_43 -> V_115 . V_187 . V_188 ,
V_43 -> V_115 . V_187 . V_191 ,
V_43 -> V_115 . V_187 . V_192 ) ;
if ( V_59 ) {
V_59 = - V_32 ;
goto V_251;
}
if ( V_43 -> V_261 -> V_170 )
F_86 ( V_29 ) ;
}
}
F_70 ( V_43 ) ;
goto V_251;
}
if ( V_43 -> V_46 == V_53 ) {
F_70 ( V_43 ) ;
goto V_262;
}
V_245 = F_80 ( V_43 ) ;
V_59 = F_98 ( V_43 ) ;
if ( V_59 < 0 ) {
F_19 ( V_29 -> V_61 , L_39 ) ;
goto V_251;
}
if ( V_43 -> V_115 . V_263 ) {
F_99 ( V_43 , & V_43 -> V_115 . V_264 ) ;
if ( V_43 -> V_115 . V_264 . V_265 . V_266 )
F_100 ( V_43 ,
& V_43 -> V_115 . V_264 . V_266 ) ;
F_101 ( V_43 ) ;
V_43 -> V_115 . V_263 = false ;
memset ( & V_43 -> V_115 . V_264 . V_265 , 0 ,
sizeof( struct V_267 ) ) ;
}
V_43 -> V_115 . V_268 = NULL ;
V_59 = F_102 ( V_43 , V_245 , false ) ;
if ( V_59 )
goto V_251;
V_43 -> V_46 = V_53 ;
F_103 ( & V_43 -> V_269 , - 1 ) ;
F_103 ( & V_43 -> V_270 , - 1 ) ;
F_103 ( & V_43 -> V_271 , - 1 ) ;
if ( V_29 -> V_70 . V_71 )
V_247 = V_272 ;
V_43 -> V_115 . V_273 = false ;
V_43 -> V_254 = 0 ;
V_43 -> V_274 = 1 ;
V_43 -> V_275 = 1 ;
F_69 ( V_87 ) ;
F_70 ( V_43 ) ;
if ( F_10 ( V_43 ) < V_246 )
goto V_251;
V_262:
if ( V_29 -> V_276 ) {
V_43 -> V_115 . V_277 = 0 ;
V_43 -> V_115 . V_278 = V_279 ;
F_104 ( V_43 ) ;
}
if ( ! V_29 -> V_70 . V_71 ) {
F_105 ( V_29 , V_280 ,
F_106 ( V_29 ) ) ;
F_107 ( V_43 ) ;
if ( F_11 ( V_29 ) > 1 ) {
if ( F_97 ( V_29 ,
V_260 , false ) < 0 )
F_18 ( V_29 -> V_61 , L_40 ) ;
} else {
if ( F_97 ( V_29 ,
V_281 , false ) < 0 )
F_18 ( V_29 -> V_61 , L_40 ) ;
}
} else {
if ( F_97 ( V_29 , V_260 , false ) < 0 )
F_18 ( V_29 -> V_61 , L_40 ) ;
}
if ( V_43 -> V_261 -> V_170 && F_11 ( V_29 ) ==
V_282 ) {
V_59 = F_84 ( V_29 , false ) ;
if ( V_59 ) {
F_19 ( V_29 -> V_61 , L_41 ) ;
goto V_251;
}
#ifndef F_9
F_108 ( V_29 , V_247 ) ;
#else
F_108 ( V_87 , V_247 , true ) ;
#endif
goto V_283;
} else if ( V_43 -> V_261 -> V_170 && ( F_11 ( V_29 ) <
V_282 ) ) {
#ifdef F_9
F_108 ( V_87 , V_247 , false ) ;
#endif
goto V_283;
}
if ( V_29 -> V_284 . V_285 >= ( ( V_286 <<
V_287 ) | V_288 ) ) {
F_109 ( V_29 -> V_289 , V_290 ,
V_29 -> V_291 . V_292 |
V_293 ) ;
}
V_59 = F_20 ( V_29 -> V_33 [ V_43 -> V_57 ] . V_34 ,
V_66 , V_231 , 1 ) ;
if ( V_59 ) {
V_43 -> V_46 = V_294 ;
V_59 = - V_32 ;
goto V_251;
}
#ifndef F_9
if ( F_72 ( V_43 ) )
F_110 ( V_43 , V_247 ) ;
#else
if ( F_74 ( V_87 ) )
F_111 ( V_87 , V_247 ) ;
#endif
V_283:
if ( V_43 -> V_184 -> V_170 ) {
struct V_237 * V_238 ;
V_238 = F_89 ( & V_43 -> V_235 , NULL ,
V_239 ,
V_240 ) ;
F_112 ( & V_43 -> V_258 ) ;
V_43 -> V_255 = V_256 ;
F_113 ( V_43 -> V_295 , & V_43 -> V_257 ) ;
F_114 ( V_29 ,
F_115 ( V_238 -> V_242 ) ) ;
} else {
V_43 -> V_255 = V_296 ;
}
V_251:
F_16 ( & V_29 -> V_56 ) ;
return V_59 ;
}
int F_116 ( struct V_6 * V_6 , void * V_7 , enum V_244 type )
{
struct V_26 * V_27 = F_7 ( V_6 ) ;
struct V_28 * V_29 = F_8 ( V_27 ) ;
struct V_86 * V_87 = F_14 ( V_27 ) ;
struct V_42 * V_43 = V_87 -> V_43 ;
struct V_86 * V_297 = NULL ;
struct V_86 * V_298 = NULL ;
struct V_86 * V_299 = NULL ;
struct V_86 * V_300 = NULL ;
struct V_92 * V_93 , * V_301 ;
enum V_202 V_245 ;
int V_59 ;
unsigned long V_176 ;
bool V_302 = false ;
F_18 ( V_29 -> V_61 , L_42 ,
F_50 ( V_27 ) , V_43 -> V_30 ) ;
F_117 ( ! F_118 ( & V_29 -> V_56 ) ) ;
F_117 ( ! F_119 ( & V_29 -> V_303 ) ) ;
if ( type != V_250 ) {
F_18 ( V_29 -> V_61 , L_35 ) ;
return - V_32 ;
}
if ( ( V_43 -> V_184 -> V_170 ||
V_29 -> V_33 [ V_43 -> V_57 ] . V_214 -> V_253 ) &&
F_50 ( V_27 ) !=
V_304 &&
F_50 ( V_27 ) !=
V_305 ) {
if ( V_29 -> V_33 [ V_43 -> V_57 ] . V_214 -> V_253 ) {
F_20 ( V_29 -> V_33 [ V_43 -> V_57 ] . V_34 ,
V_66 , V_231 , 0 ) ;
} else if ( F_50 ( V_27 )
== V_185 ) {
if ( V_43 -> V_115 . V_187 . V_188 == - 1 )
F_75 ( V_43 ,
0 , 0 , 0 ) ;
F_97 ( V_29 , V_281 , false ) ;
}
if ( V_87 -> V_306 != 0 ) {
F_120 ( 1 , L_43 ,
V_62 , V_87 -> V_27 . V_35 ) ;
F_21 ( V_29 -> V_61 , L_44 ) ;
F_121 ( V_29 ) ;
}
return F_122 ( & V_87 -> V_45 ) ;
}
if ( ! V_87 -> V_45 . V_46 )
return 0 ;
F_92 ( & V_29 -> V_307 , V_176 ) ;
if ( V_43 -> V_46 == V_53 ) {
V_43 -> V_46 = V_155 ;
V_302 = true ;
}
F_93 ( & V_29 -> V_307 , V_176 ) ;
if ( V_302 ) {
F_16 ( & V_29 -> V_56 ) ;
F_123 ( V_43 , true ) ;
if ( V_29 -> V_70 . V_71 )
F_20 ( V_29 -> V_33 [ V_43 -> V_57 ] . V_34 ,
V_66 , V_231 , 0 ) ;
F_15 ( & V_29 -> V_56 ) ;
F_124 ( V_43 ) ;
}
F_92 ( & V_29 -> V_307 , V_176 ) ;
if ( F_10 ( V_43 ) == 1 )
V_43 -> V_46 = V_294 ;
F_93 ( & V_29 -> V_307 , V_176 ) ;
if ( ! V_302 ) {
V_59 = F_122 ( & V_87 -> V_45 ) ;
if ( V_59 )
return V_59 ;
goto V_308;
}
F_125 ( V_43 ) ;
if ( ! V_29 -> V_70 . V_71 )
F_105 ( V_29 , V_280 ,
false ) ;
if ( V_43 -> V_255 == V_256 ) {
F_126 ( & V_43 -> V_257 ) ;
V_43 -> V_255 = V_296 ;
}
if ( V_302 ) {
V_245 = F_80 ( V_43 ) ;
V_59 = F_127 ( V_43 , V_245 , false ) ;
}
if ( V_43 -> V_47 . V_309 ) {
V_297 = & V_43 -> V_47 ;
F_128 ( & V_297 -> V_45 . V_310 ) ;
}
if ( V_43 -> V_49 . V_309 ) {
V_298 = & V_43 -> V_49 ;
F_128 ( & V_298 -> V_45 . V_310 ) ;
}
if ( V_43 -> V_44 . V_309 ) {
V_299 = & V_43 -> V_44 ;
F_128 ( & V_299 -> V_45 . V_310 ) ;
}
if ( V_43 -> V_48 . V_309 ) {
V_300 = & V_43 -> V_48 ;
F_128 ( & V_300 -> V_45 . V_310 ) ;
}
V_59 = F_122 ( & V_87 -> V_45 ) ;
if ( V_59 )
return V_59 ;
F_92 ( & V_87 -> V_252 , V_176 ) ;
F_44 (vb, _vb, &pipe->activeq, queue) {
V_93 -> V_174 = V_311 ;
F_46 ( & V_93 -> V_312 ) ;
}
F_44 (vb, _vb, &pipe->buffers_waiting_for_param, queue) {
V_93 -> V_174 = V_311 ;
F_46 ( & V_93 -> V_312 ) ;
V_87 -> V_140 [ V_93 -> V_3 ] = 0 ;
}
F_93 ( & V_87 -> V_252 , V_176 ) ;
F_129 ( V_43 ) ;
V_308:
if ( F_10 ( V_43 ) + 1
!= F_82 ( V_43 ) )
return 0 ;
if ( ! V_29 -> V_70 . V_71 )
V_59 = F_20 ( V_29 -> V_33 [ V_43 -> V_57 ] . V_34 ,
V_66 , V_231 , 0 ) ;
if ( V_29 -> V_276 ) {
V_43 -> V_115 . V_277 = 0 ;
V_43 -> V_115 . V_278 = V_279 ;
}
if ( F_11 ( V_29 ) ) {
F_121 ( V_29 ) ;
return 0 ;
}
if ( V_29 -> V_284 . V_285 >= ( ( V_286 <<
V_287 ) | V_288 ) ) {
F_109 ( V_29 -> V_289 , V_290 ,
V_29 -> V_291 . V_292 &
~ V_293 ) ;
}
if ( F_97 ( V_29 , V_313 , false ) )
F_21 ( V_29 -> V_61 , L_45 ) ;
if ( V_29 -> V_70 . V_314 == V_315 ) {
unsigned int V_3 ;
bool V_316 [ V_317 ] = { 0 } ;
if ( V_29 -> V_222 )
F_19 ( V_29 -> V_61 , L_46 ,
V_62 ) ;
for ( V_3 = 0 ; V_3 < V_29 -> V_52 ; V_3 ++ ) {
if ( V_29 -> V_43 [ V_3 ] . V_318 ) {
F_130 ( & V_29 ->
V_43 [ V_3 ] ) ;
V_316 [ V_3 ] = true ;
}
}
F_131 ( V_29 -> V_289 , V_319 , V_29 -> V_291 . V_320 |
V_321 ) ;
F_19 ( V_29 -> V_61 , L_47 ) ;
F_132 ( V_29 ) ;
for ( V_3 = 0 ; V_3 < V_29 -> V_52 ; V_3 ++ ) {
if ( V_316 [ V_3 ] )
F_133 ( & V_29 -> V_43 [ V_3 ] ) ;
}
V_29 -> V_222 = false ;
}
return V_59 ;
}
static int F_134 ( struct V_6 * V_6 , void * V_7 ,
enum V_244 type )
{
struct V_26 * V_27 = F_7 ( V_6 ) ;
struct V_28 * V_29 = F_8 ( V_27 ) ;
int V_78 ;
F_52 ( & V_29 -> V_303 ) ;
F_15 ( & V_29 -> V_56 ) ;
V_78 = F_116 ( V_6 , V_7 , type ) ;
F_16 ( & V_29 -> V_56 ) ;
F_54 ( & V_29 -> V_303 ) ;
return V_78 ;
}
static int F_135 ( struct V_6 * V_6 , void * V_7 ,
struct V_322 * V_323 )
{
struct V_26 * V_27 = F_7 ( V_6 ) ;
struct V_42 * V_43 = F_14 ( V_27 ) -> V_43 ;
struct V_28 * V_29 = F_8 ( V_27 ) ;
int V_3 , V_59 = - V_32 ;
for ( V_3 = 0 ; V_3 < V_324 ; V_3 ++ ) {
if ( V_325 [ V_3 ] . V_326 == V_323 -> V_326 ) {
V_59 = 0 ;
break;
}
}
if ( V_59 )
return V_59 ;
F_15 ( & V_29 -> V_56 ) ;
switch ( V_323 -> V_326 ) {
case V_327 :
case V_328 :
case V_329 :
case V_330 :
case V_331 :
case V_332 :
case V_333 :
case V_334 :
case V_335 :
case V_336 :
case V_337 :
case V_338 :
case V_339 :
case V_340 :
case V_341 :
case V_342 :
case V_343 :
case V_344 :
case V_345 :
case V_346 :
F_16 ( & V_29 -> V_56 ) ;
return F_136 ( V_29 -> V_33 [ V_43 -> V_57 ] . V_34 ->
V_347 , V_323 ) ;
case V_348 :
V_59 = F_137 ( V_43 , 0 , & V_323 -> V_349 ) ;
break;
case V_350 :
V_59 = F_138 ( V_43 , 0 , & V_323 -> V_349 ) ;
break;
case V_351 :
V_59 = F_139 ( V_43 , 0 , & V_323 -> V_349 ) ;
break;
case V_352 :
V_59 = F_140 ( V_43 , 0 , & V_323 -> V_349 ) ;
break;
case V_353 :
V_59 = F_141 ( V_43 , 0 , & V_323 -> V_349 ) ;
break;
case V_354 :
V_59 = F_142 ( V_43 , 0 , & V_323 -> V_349 ) ;
break;
case V_355 :
V_59 = F_143 ( V_43 , 0 , & V_323 -> V_349 ) ;
break;
default:
V_59 = - V_32 ;
break;
}
F_16 ( & V_29 -> V_56 ) ;
return V_59 ;
}
static int F_144 ( struct V_6 * V_6 , void * V_7 ,
struct V_322 * V_323 )
{
struct V_26 * V_27 = F_7 ( V_6 ) ;
struct V_42 * V_43 = F_14 ( V_27 ) -> V_43 ;
struct V_28 * V_29 = F_8 ( V_27 ) ;
int V_3 , V_59 = - V_32 ;
for ( V_3 = 0 ; V_3 < V_324 ; V_3 ++ ) {
if ( V_325 [ V_3 ] . V_326 == V_323 -> V_326 ) {
V_59 = 0 ;
break;
}
}
if ( V_59 )
return V_59 ;
F_15 ( & V_29 -> V_56 ) ;
switch ( V_323 -> V_326 ) {
case V_331 :
case V_332 :
case V_333 :
case V_356 :
case V_334 :
case V_335 :
case V_336 :
case V_357 :
case V_358 :
case V_337 :
case V_338 :
case V_339 :
case V_340 :
case V_359 :
case V_342 :
case V_343 :
case V_344 :
case V_345 :
case V_346 :
F_16 ( & V_29 -> V_56 ) ;
return F_145 ( NULL ,
V_29 -> V_33 [ V_43 -> V_57 ] . V_34 ->
V_347 , V_323 ) ;
case V_348 :
V_59 = F_137 ( V_43 , 1 , & V_323 -> V_349 ) ;
break;
case V_350 :
V_59 = F_138 ( V_43 , 1 , & V_323 -> V_349 ) ;
break;
case V_351 :
V_59 = F_139 ( V_43 , 1 , & V_323 -> V_349 ) ;
break;
case V_352 :
V_59 = F_140 ( V_43 , 1 , & V_323 -> V_349 ) ;
break;
case V_353 :
V_59 = F_141 ( V_43 , 1 , & V_323 -> V_349 ) ;
break;
case V_354 :
V_59 = F_142 ( V_43 , 1 , & V_323 -> V_349 ) ;
break;
case V_360 :
V_59 = F_146 ( V_43 , V_323 -> V_349 ) ;
break;
case V_355 :
V_59 = F_143 ( V_43 , 1 , & V_323 -> V_349 ) ;
break;
default:
V_59 = - V_32 ;
break;
}
F_16 ( & V_29 -> V_56 ) ;
return V_59 ;
}
static int F_147 ( struct V_6 * V_6 , void * V_7 ,
struct V_361 * V_362 )
{
int V_3 , V_59 = - V_32 ;
struct V_26 * V_27 = F_7 ( V_6 ) ;
struct V_42 * V_43 = F_14 ( V_27 ) -> V_43 ;
struct V_28 * V_29 = F_8 ( V_27 ) ;
switch ( V_362 -> V_326 ) {
case V_363 :
case V_364 :
case V_365 :
#ifndef F_9
return V_361 ( V_29 -> V_33 [ V_43 -> V_57 ] . V_34 ->
V_347 , V_362 ) ;
#else
if ( V_29 -> V_36 )
return V_361 ( V_29 -> V_36 -> V_347 , V_362 ) ;
else
return V_361 ( V_29 -> V_33 [ V_43 -> V_57 ] .
V_34 -> V_347 , V_362 ) ;
#endif
}
if ( V_362 -> V_326 & V_366 )
return V_59 ;
for ( V_3 = 0 ; V_3 < V_324 ; V_3 ++ ) {
if ( V_325 [ V_3 ] . V_326 == V_362 -> V_326 ) {
memcpy ( V_362 , & V_325 [ V_3 ] ,
sizeof( struct V_361 ) ) ;
V_362 -> V_40 [ 0 ] = 0 ;
V_59 = 0 ;
break;
}
}
if ( V_59 != 0 )
V_362 -> V_176 = V_367 ;
return V_59 ;
}
static int F_148 ( struct V_6 * V_6 , void * V_7 ,
struct V_368 * V_369 )
{
struct V_26 * V_27 = F_7 ( V_6 ) ;
struct V_42 * V_43 = F_14 ( V_27 ) -> V_43 ;
struct V_28 * V_29 = F_8 ( V_27 ) ;
struct V_322 V_370 ;
int V_3 ;
int V_59 = 0 ;
for ( V_3 = 0 ; V_3 < V_369 -> V_112 ; V_3 ++ ) {
V_370 . V_326 = V_369 -> V_371 [ V_3 ] . V_326 ;
V_370 . V_349 = V_369 -> V_371 [ V_3 ] . V_349 ;
switch ( V_370 . V_326 ) {
case V_328 :
case V_333 :
case V_327 :
case V_329 :
case V_372 :
case V_373 :
case V_340 :
case V_342 :
case V_343 :
case V_344 :
case V_345 :
case V_346 :
V_59 =
F_136 ( V_29 -> V_33 [ V_43 -> V_57 ] . V_34 ->
V_347 , & V_370 ) ;
break;
case V_363 :
case V_364 :
case V_365 :
case V_374 :
#ifndef F_9
if ( V_29 -> V_33 [ V_43 -> V_57 ] . V_36 )
#else
if ( V_29 -> V_36 )
#endif
V_59 =
#ifndef F_9
F_136 ( V_29 -> V_33 [ V_43 -> V_57 ] .
V_36 -> V_347 , & V_370 ) ;
#else
F_136 ( V_29 -> V_36 -> V_347 ,
& V_370 ) ;
#endif
else
V_59 =
F_136 ( V_29 -> V_33 [ V_43 -> V_57 ] .
V_34 -> V_347 , & V_370 ) ;
break;
case V_375 :
case V_376 :
case V_377 :
case V_378 :
case V_379 :
case V_380 :
case V_381 :
case V_382 :
if ( V_29 -> V_276 )
V_59 =
F_136 ( V_29 -> V_276 -> V_347 ,
& V_370 ) ;
break;
case V_383 :
F_15 ( & V_29 -> V_56 ) ;
V_59 = F_149 ( V_43 , 0 , & V_370 . V_349 ) ;
F_16 ( & V_29 -> V_56 ) ;
break;
case V_384 :
V_59 = F_20 (
V_29 -> V_33 [ V_43 -> V_57 ] . V_34 ,
V_215 , V_385 , ( T_1 * ) & V_370 . V_349 ) ;
break;
default:
V_59 = - V_32 ;
}
if ( V_59 ) {
V_369 -> V_386 = V_3 ;
break;
}
V_369 -> V_371 [ V_3 ] . V_349 = V_370 . V_349 ;
}
return V_59 ;
}
static int F_150 ( struct V_6 * V_6 , void * V_7 ,
struct V_368 * V_369 )
{
struct V_322 V_370 ;
int V_3 , V_59 = 0 ;
V_59 = F_148 ( V_6 , V_7 , V_369 ) ;
if ( V_59 != - V_32 )
return V_59 ;
for ( V_3 = 0 ; V_3 < V_369 -> V_112 ; V_3 ++ ) {
V_370 . V_326 = V_369 -> V_371 [ V_3 ] . V_326 ;
V_370 . V_349 = V_369 -> V_371 [ V_3 ] . V_349 ;
V_59 = F_135 ( V_6 , V_7 , & V_370 ) ;
V_369 -> V_371 [ V_3 ] . V_349 = V_370 . V_349 ;
if ( V_59 ) {
V_369 -> V_386 = V_3 ;
break;
}
}
return V_59 ;
}
static int F_151 ( struct V_6 * V_6 , void * V_7 ,
struct V_368 * V_369 )
{
struct V_26 * V_27 = F_7 ( V_6 ) ;
struct V_42 * V_43 = F_14 ( V_27 ) -> V_43 ;
struct V_28 * V_29 = F_8 ( V_27 ) ;
struct V_322 V_370 ;
int V_3 ;
int V_59 = 0 ;
for ( V_3 = 0 ; V_3 < V_369 -> V_112 ; V_3 ++ ) {
struct V_387 * V_388 ;
V_370 . V_326 = V_369 -> V_371 [ V_3 ] . V_326 ;
V_370 . V_349 = V_369 -> V_371 [ V_3 ] . V_349 ;
switch ( V_370 . V_326 ) {
case V_328 :
case V_333 :
case V_358 :
case V_327 :
case V_329 :
case V_389 :
case V_390 :
case V_340 :
case V_342 :
case V_343 :
case V_344 :
case V_345 :
case V_346 :
V_59 = F_145 ( NULL ,
V_29 -> V_33 [ V_43 -> V_57 ] . V_34 ->
V_347 , & V_370 ) ;
break;
case V_363 :
case V_364 :
case V_365 :
case V_374 :
#ifndef F_9
if ( V_29 -> V_33 [ V_43 -> V_57 ] . V_36 )
#else
if ( V_29 -> V_36 )
#endif
V_59 = F_145 ( NULL ,
#ifndef F_9
V_29 -> V_33 [ V_43 -> V_57 ] .
V_36 -> V_347 , & V_370 ) ;
#else
V_29 -> V_36 -> V_347 ,
& V_370 ) ;
#endif
else
V_59 = F_145 ( NULL ,
V_29 -> V_33 [ V_43 -> V_57 ] .
V_34 -> V_347 , & V_370 ) ;
break;
case V_375 :
case V_376 :
case V_377 :
case V_378 :
case V_379 :
case V_380 :
case V_381 :
case V_382 :
F_15 ( & V_29 -> V_56 ) ;
if ( V_29 -> V_276 ) {
V_59 =
F_145 ( NULL , V_29 -> V_276 -> V_347 ,
& V_370 ) ;
if ( V_370 . V_326 == V_381 ) {
V_43 -> V_115 . V_278 =
V_279 ;
V_43 -> V_115 . V_277 = 0 ;
}
}
F_16 ( & V_29 -> V_56 ) ;
break;
case V_383 :
F_15 ( & V_29 -> V_56 ) ;
V_59 = F_149 ( V_43 , 1 , & V_370 . V_349 ) ;
F_16 ( & V_29 -> V_56 ) ;
break;
default:
V_388 = F_152 ( & V_43 -> V_347 , V_370 . V_326 ) ;
if ( V_388 )
V_59 = F_153 ( V_388 , V_370 . V_349 ) ;
else
V_59 = - V_32 ;
}
if ( V_59 ) {
V_369 -> V_386 = V_3 ;
break;
}
V_369 -> V_371 [ V_3 ] . V_349 = V_370 . V_349 ;
}
int F_154 ( struct V_6 * V_6 , void * V_7 ,
struct V_368 * V_369 )
{
struct V_322 V_370 ;
int V_3 , V_59 = 0 ;
V_59 = F_151 ( V_6 , V_7 , V_369 ) ;
if ( V_59 != - V_32 )
return V_59 ;
for ( V_3 = 0 ; V_3 < V_369 -> V_112 ; V_3 ++ ) {
V_370 . V_326 = V_369 -> V_371 [ V_3 ] . V_326 ;
V_370 . V_349 = V_369 -> V_371 [ V_3 ] . V_349 ;
V_59 = F_144 ( V_6 , V_7 , & V_370 ) ;
V_369 -> V_371 [ V_3 ] . V_349 = V_370 . V_349 ;
if ( V_59 ) {
V_369 -> V_386 = V_3 ;
break;
}
}
return V_59 ;
}
static int F_155 ( struct V_6 * V_6 , void * V_7 ,
struct V_391 * V_392 )
{
struct V_26 * V_27 = F_7 ( V_6 ) ;
struct V_42 * V_43 = F_14 ( V_27 ) -> V_43 ;
struct V_28 * V_29 = F_8 ( V_27 ) ;
if ( V_392 -> type != V_250 ) {
F_19 ( V_29 -> V_61 , L_48 ) ;
return - V_32 ;
}
F_15 ( & V_29 -> V_56 ) ;
V_392 -> V_392 . V_393 . V_394 = V_43 -> V_204 -> V_170 ;
F_16 ( & V_29 -> V_56 ) ;
return 0 ;
}
static int F_156 ( struct V_6 * V_6 , void * V_7 ,
struct V_391 * V_392 )
{
struct V_26 * V_27 = F_7 ( V_6 ) ;
struct V_28 * V_29 = F_8 ( V_27 ) ;
struct V_42 * V_43 = F_14 ( V_27 ) -> V_43 ;
int V_395 ;
int V_78 ;
int V_396 ;
if ( V_392 -> type != V_250 ) {
F_19 ( V_29 -> V_61 , L_48 ) ;
return - V_32 ;
}
F_15 ( & V_29 -> V_56 ) ;
V_43 -> V_218 = false ;
switch ( V_392 -> V_392 . V_393 . V_394 ) {
case V_397 : {
struct V_398 V_77 = { 0 } ;
V_77 . V_399 = V_392 -> V_392 . V_393 . V_400 ;
V_78 = F_20 ( V_29 -> V_33 [ V_43 -> V_57 ] . V_34 ,
V_66 , V_401 , & V_77 ) ;
if ( ! V_78 )
V_392 -> V_392 . V_393 . V_400 = V_77 . V_399 ;
if ( V_77 . V_399 . V_402 != 0 ) {
V_396 = V_77 . V_399 . V_403 / V_77 . V_399 . V_402 ;
if ( V_396 > 30 )
V_43 -> V_218 = true ;
}
goto V_251;
}
case V_404 :
V_395 = V_205 ;
break;
case V_405 :
V_395 = V_213 ;
break;
case V_406 :
V_395 = V_407 ;
break;
case V_408 :
V_395 = V_212 ;
break;
default:
V_78 = - V_32 ;
goto V_251;
}
V_78 = F_153 ( V_43 -> V_204 , V_395 ) ;
V_251:
F_16 ( & V_29 -> V_56 ) ;
return V_78 == - V_69 ? 0 : V_78 ;
}
static int F_157 ( struct V_6 * V_6 , void * V_7 ,
struct V_391 * V_392 )
{
struct V_26 * V_27 = F_7 ( V_6 ) ;
struct V_28 * V_29 = F_8 ( V_27 ) ;
if ( V_392 -> type != V_193 ) {
F_19 ( V_29 -> V_61 , L_49 ) ;
return - V_32 ;
}
F_15 ( & V_29 -> V_56 ) ;
V_29 -> V_70 . V_71 = 1 ;
F_16 ( & V_29 -> V_56 ) ;
return 0 ;
}
static long F_158 ( struct V_6 * V_6 , void * V_7 ,
bool V_409 , unsigned int V_410 , void * V_411 )
{
struct V_26 * V_27 = F_7 ( V_6 ) ;
struct V_28 * V_29 = F_8 ( V_27 ) ;
struct V_42 * V_43 ;
bool V_412 ;
int V_413 ;
V_412 = ! strncmp ( V_27 -> V_35 , L_50 ,
sizeof( V_27 -> V_35 ) ) ;
if ( V_412 )
V_43 = F_159 ( V_27 ) -> V_43 ;
else
V_43 = F_14 ( V_27 ) -> V_43 ;
switch ( V_410 ) {
case V_414 :
case V_415 :
case V_416 :
case V_417 :
case V_418 :
case V_419 :
case V_420 :
case V_421 :
case V_422 :
case V_423 :
#ifdef F_9
case V_424 :
#endif
break;
default:
F_15 ( & V_29 -> V_56 ) ;
break;
}
switch ( V_410 ) {
#ifdef F_9
case V_425 :
V_413 = F_160 ( V_43 , V_411 ) ;
break;
#endif
case V_426 :
V_413 = F_161 ( V_43 , 0 , V_411 ) ;
break;
case V_427 :
V_413 = F_161 ( V_43 , 1 , V_411 ) ;
break;
case V_428 :
V_413 = F_162 ( V_43 , 0 , V_411 ) ;
break;
case V_429 :
V_413 = F_162 ( V_43 , 1 , V_411 ) ;
break;
case V_430 :
V_413 = F_163 ( V_43 , 0 , V_411 ) ;
break;
case V_431 :
V_413 = F_163 ( V_43 , 1 , V_411 ) ;
break;
case V_432 :
V_413 = F_164 ( V_43 , 0 , V_411 ) ;
break;
case V_433 :
V_413 = F_164 ( V_43 , 1 , V_411 ) ;
break;
case V_434 :
V_413 = F_165 ( V_43 , 0 , V_411 ) ;
break;
case V_435 :
V_413 = F_165 ( V_43 , 1 , V_411 ) ;
break;
case V_436 :
V_413 = F_166 ( V_43 , V_411 ) ;
break;
case V_437 :
V_413 = F_167 ( V_43 , V_411 ) ;
break;
case V_438 :
V_413 = F_168 ( V_43 , V_411 ,
& V_43 -> V_115 . V_264 , true ) ;
if ( ! V_413 && V_411 )
V_43 -> V_115 . V_263 = true ;
break;
case V_439 :
V_413 = F_169 ( V_43 , V_411 ,
& V_43 -> V_115 . V_264 , true ) ;
if ( ! V_413 && V_411 )
V_43 -> V_115 . V_263 = true ;
break;
case V_440 :
V_413 = F_170 ( V_43 , 0 , V_411 ) ;
break;
case V_441 :
V_413 = F_170 ( V_43 , 1 , V_411 ) ;
break;
case V_442 :
V_413 = F_171 ( V_43 , 0 , V_411 ) ;
break;
case V_443 :
V_413 = F_172 ( V_43 , 0 , V_411 ) ;
break;
case V_444 :
V_413 = F_172 ( V_43 , 1 , V_411 ) ;
break;
case V_445 :
V_413 = F_173 ( V_43 , 0 , V_411 ) ;
break;
case V_446 :
V_413 = F_173 ( V_43 , 1 , V_411 ) ;
break;
case V_447 :
V_413 = F_174 ( V_43 , 0 , V_411 ) ;
break;
case V_448 :
V_413 = F_174 ( V_43 , 1 , V_411 ) ;
break;
case V_449 :
V_413 = F_175 ( V_43 , 0 , V_411 ) ;
break;
case V_450 :
V_413 = F_175 ( V_43 , 1 , V_411 ) ;
break;
case V_451 :
V_413 = F_176 ( V_43 , 0 , V_411 ) ;
break;
case V_452 :
V_413 = F_176 ( V_43 , 1 , V_411 ) ;
break;
case V_453 :
V_413 = F_177 ( V_43 , 0 , V_411 ) ;
break;
case V_454 :
V_413 = F_177 ( V_43 , 1 , V_411 ) ;
break;
case V_455 :
V_413 = F_178 ( V_43 , 0 , V_411 ) ;
break;
case V_456 :
V_413 = F_178 ( V_43 , 1 , V_411 ) ;
break;
case V_457 :
V_413 = F_179 ( V_43 , 0 , V_411 ) ;
break;
case V_458 :
V_413 = F_179 ( V_43 , 1 , V_411 ) ;
break;
case V_459 :
V_413 = F_180 ( V_43 , V_411 ) ;
break;
case V_460 :
V_413 = F_181 ( V_43 , V_411 ) ;
break;
case V_461 :
V_413 = F_182 ( V_43 , V_411 ) ;
break;
case V_414 :
#ifndef F_9
if ( V_29 -> V_33 [ V_43 -> V_57 ] . V_36 )
#else
if ( V_29 -> V_36 )
#endif
V_413 = F_20 (
#ifndef F_9
V_29 -> V_33 [ V_43 -> V_57 ] . V_36 ,
#else
V_29 -> V_36 ,
#endif
V_64 , V_229 , V_410 , V_411 ) ;
else
V_413 = F_20 (
V_29 -> V_33 [ V_43 -> V_57 ] . V_34 ,
V_64 , V_229 , V_410 , V_411 ) ;
break;
case V_415 :
case V_416 :
case V_417 :
case V_419 :
case V_420 :
case V_421 :
case V_422 :
#ifdef F_9
case V_424 :
#endif
V_413 = F_20 ( V_29 -> V_33 [ V_43 -> V_57 ] . V_34 ,
V_64 , V_229 , V_410 , V_411 ) ;
break;
case V_462 :
V_413 = F_183 ( V_43 , V_411 ) ;
break;
case V_463 :
V_413 = F_184 ( V_43 , V_411 ) ;
break;
case V_464 :
V_413 = F_185 ( V_43 , V_411 ) ;
break;
case V_465 :
V_413 = F_186 ( V_43 , V_411 ) ;
break;
case V_466 :
V_413 = F_187 ( V_43 , V_411 ) ;
break;
case V_467 :
V_413 = F_188 ( V_43 , V_411 ) ;
break;
case V_468 :
V_413 = F_189 ( V_43 , V_411 ) ;
break;
case V_469 :
V_413 = F_190 ( V_43 , V_411 ) ;
break;
case V_470 :
V_413 = F_191 ( V_43 , V_411 ) ;
break;
case V_471 :
V_413 = F_192 ( V_43 , 0 , V_411 ) ;
break;
case V_472 :
V_413 = F_192 ( V_43 , 1 , V_411 ) ;
break;
case V_473 :
V_413 = F_193 ( V_27 , V_411 ) ;
break;
case V_474 :
V_413 = F_194 ( V_43 , V_411 ) ;
break;
case V_475 :
V_413 = F_195 ( V_43 , 0 , V_411 ) ;
break;
case V_476 :
V_413 = F_196 ( V_43 , 0 , V_411 ) ;
break;
case V_418 :
V_413 = F_20 ( V_29 -> V_33 [ V_43 -> V_57 ] . V_34 ,
V_64 , V_229 , V_410 , V_411 ) ;
break;
case V_477 :
V_413 = F_197 ( V_43 , V_411 ) ;
break;
case V_478 :
V_413 = F_198 ( V_43 , V_411 ) ;
break;
case V_479 :
V_413 = F_199 ( V_43 , V_411 ) ;
break;
case V_480 :
V_413 = F_200 ( V_43 , 0 , V_411 ) ;
break;
case V_481 :
V_413 = F_200 ( V_43 , 1 , V_411 ) ;
break;
case V_482 :
V_413 = F_201 ( V_43 , V_411 ) ;
break;
case V_483 :
V_413 = F_202 ( V_43 , V_411 ) ;
break;
case V_484 :
V_413 = F_203 ( V_43 , V_411 ) ;
break;
case V_485 :
V_413 = F_204 ( V_43 , V_411 ) ;
break;
case V_486 :
V_413 = F_205 ( V_27 , V_411 ) ;
break;
case V_487 :
V_413 = F_206 ( V_43 , V_411 ) ;
break;
default:
V_413 = - V_32 ;
break;
}
switch ( V_410 ) {
case V_414 :
case V_415 :
case V_416 :
case V_417 :
case V_418 :
case V_419 :
case V_420 :
case V_421 :
case V_422 :
#ifdef F_9
case V_424 :
#endif
break;
default:
F_16 ( & V_29 -> V_56 ) ;
break;
}
return V_413 ;
}
