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
V_9 -> V_16 = V_17 |
V_18 | V_19 ;
V_9 -> V_20 = V_9 -> V_16 | V_21 ;
return 0 ;
}
static int F_6 ( struct V_6 * V_6 , void * V_7 ,
struct V_22 * V_23 )
{
struct V_24 * V_25 = F_7 ( V_6 ) ;
struct V_26 * V_27 = F_8 ( V_25 ) ;
int V_28 = V_23 -> V_28 ;
if ( V_28 >= V_27 -> V_29 )
return - V_30 ;
if ( ! V_27 -> V_31 [ V_28 ] . V_32 )
return - V_30 ;
memset ( V_23 , 0 , sizeof( struct V_22 ) ) ;
strncpy ( V_23 -> V_33 , V_27 -> V_31 [ V_28 ] . V_32 -> V_33 ,
sizeof( V_23 -> V_33 ) - 1 ) ;
#ifndef F_9
if ( V_27 -> V_31 [ V_28 ] . V_34 &&
strlen ( V_27 -> V_31 [ V_28 ] . V_34 -> V_33 ) > 0 ) {
#else
if ( V_27 -> V_34 &&
strlen ( V_27 -> V_34 -> V_33 ) > 0 ) {
#endif
const int V_35 = strlen ( V_23 -> V_33 ) ;
const int V_36 = sizeof( V_23 -> V_33 ) - V_35 - 1 ;
if ( V_36 > 1 ) {
V_23 -> V_33 [ V_35 ] = '+' ;
strncpy ( & V_23 -> V_33 [ V_35 + 1 ] ,
#ifndef F_9
V_27 -> V_31 [ V_28 ] . V_34 -> V_33 , V_36 - 1 ) ;
#else
V_27 -> V_34 -> V_33 , V_36 - 1 ) ;
#endif
}
}
V_23 -> type = V_37 ;
V_23 -> V_28 = V_28 ;
V_23 -> V_38 [ 0 ] = V_27 -> V_31 [ V_28 ] . type ;
V_23 -> V_38 [ 1 ] = V_27 -> V_31 [ V_28 ] . V_39 ;
return 0 ;
}
static unsigned int F_10 (
struct V_40 * V_41 )
{
return V_41 -> V_42 . V_43 . V_44
+ V_41 -> V_45 . V_43 . V_44
+ V_41 -> V_46 . V_43 . V_44
+ V_41 -> V_47 . V_43 . V_44
+ V_41 -> V_48 . V_43 . V_44 ;
}
unsigned int F_11 ( struct V_26 * V_27 )
{
unsigned int V_3 , V_49 ;
for ( V_3 = 0 , V_49 = 0 ; V_3 < V_27 -> V_50 ; V_3 ++ )
V_49 += V_27 -> V_41 [ V_3 ] . V_44 ==
V_51 ;
return V_49 ;
}
unsigned int F_12 ( struct V_26 * V_27 )
{
unsigned int V_3 ;
for ( V_3 = 0 ; V_3 < V_27 -> V_50 ; V_3 ++ )
if ( V_27 -> V_41 [ V_3 ] . V_52 . V_53 )
return 1 ;
return 0 ;
}
static int F_13 ( struct V_6 * V_6 , void * V_7 , unsigned int * V_23 )
{
struct V_24 * V_25 = F_7 ( V_6 ) ;
struct V_26 * V_27 = F_8 ( V_25 ) ;
struct V_40 * V_41 = F_14 ( V_25 ) -> V_41 ;
F_15 ( & V_27 -> V_54 ) ;
* V_23 = V_41 -> V_55 ;
F_16 ( & V_27 -> V_54 ) ;
return 0 ;
}
static int F_17 ( struct V_6 * V_6 , void * V_7 , unsigned int V_23 )
{
struct V_24 * V_25 = F_7 ( V_6 ) ;
struct V_26 * V_27 = F_8 ( V_25 ) ;
struct V_40 * V_41 = F_14 ( V_25 ) -> V_41 ;
struct V_56 * V_32 = NULL ;
int V_57 ;
F_15 ( & V_27 -> V_54 ) ;
if ( V_23 >= V_58 || V_23 >= V_27 -> V_29 ) {
F_18 ( V_27 -> V_59 , L_1 , V_27 -> V_29 ) ;
V_57 = - V_30 ;
goto error;
}
if ( V_27 -> V_31 [ V_23 ] . V_41 != NULL && V_27 -> V_31 [ V_23 ] . V_41 != V_41 ) {
F_19 ( V_27 -> V_59 ,
L_2 , V_60 ,
V_27 -> V_31 [ V_23 ] . V_41 -> V_28 ) ;
V_57 = - V_61 ;
goto error;
}
V_32 = V_27 -> V_31 [ V_23 ] . V_32 ;
if ( ! V_32 ) {
F_19 ( V_27 -> V_59 , L_3 , V_60 ) ;
V_57 = - V_30 ;
goto error;
}
if ( F_10 ( V_41 ) ) {
F_19 ( V_27 -> V_59 ,
L_4 ) ;
V_57 = - V_30 ;
goto error;
}
if ( V_27 -> V_31 [ V_41 -> V_55 ] . V_41 == V_41 &&
V_41 -> V_55 != V_23 ) {
V_57 = F_20 ( V_27 -> V_31 [ V_41 -> V_55 ] . V_32 ,
V_62 , V_63 , 0 ) ;
if ( V_57 )
F_21 ( V_27 -> V_59 ,
L_5 ) ;
V_27 -> V_31 [ V_41 -> V_55 ] . V_41 = NULL ;
}
V_57 = F_20 ( V_27 -> V_31 [ V_23 ] . V_32 , V_62 , V_63 , 1 ) ;
if ( V_57 ) {
F_19 ( V_27 -> V_59 , L_6 ) ;
goto error;
}
F_22 ( V_41 ) ;
V_57 = F_20 ( V_27 -> V_31 [ V_23 ] . V_32 , V_64 , V_65 ,
0 , V_27 -> V_31 [ V_23 ] . V_66 , 0 ) ;
if ( V_57 && ( V_57 != - V_67 ) ) {
F_19 ( V_27 -> V_59 , L_7 ) ;
goto error;
}
#ifndef F_9
if ( ! V_27 -> V_68 . V_69 && V_27 -> V_31 [ V_23 ] . V_34 )
V_57 = F_20 ( V_27 -> V_31 [ V_23 ] . V_34 , V_62 ,
V_70 , 1 ) ;
#else
if ( V_27 -> V_34 )
V_57 = F_20 ( V_27 -> V_34 , V_62 , V_63 , 1 ) ;
if ( ! V_27 -> V_68 . V_69 && V_27 -> V_34 )
V_57 = F_20 ( V_27 -> V_34 , V_62 , V_70 , 1 ) ;
#endif
V_41 -> V_55 = V_23 ;
V_27 -> V_31 [ V_23 ] . V_41 = V_41 ;
F_16 ( & V_27 -> V_54 ) ;
return 0 ;
error:
F_16 ( & V_27 -> V_54 ) ;
return V_57 ;
}
static int F_23 ( struct V_6 * V_6 , void * V_7 ,
struct V_71 * V_72 )
{
struct V_24 * V_25 = F_7 ( V_6 ) ;
struct V_26 * V_27 = F_8 ( V_25 ) ;
struct V_40 * V_41 = F_14 ( V_25 ) -> V_41 ;
struct V_73 V_74 = { 0 } ;
unsigned int V_3 , V_75 = 0 ;
int V_76 ;
F_15 ( & V_27 -> V_54 ) ;
V_76 = F_20 ( V_27 -> V_31 [ V_41 -> V_55 ] . V_32 , V_77 ,
V_78 , NULL , & V_74 ) ;
if ( V_76 == - V_67 ) {
F_21 ( V_27 -> V_59 , L_8 ) ;
}
F_16 ( & V_27 -> V_54 ) ;
if ( V_76 )
return V_76 ;
for ( V_3 = 0 ; V_3 < F_2 ( V_4 ) ; V_3 ++ ) {
const struct V_1 * V_79 =
& V_4 [ V_3 ] ;
if ( V_79 -> V_80 == V_81
&& V_79 -> V_5 != V_74 . V_74 )
continue;
if ( V_75 < V_72 -> V_28 ) {
V_75 ++ ;
continue;
}
F_24 ( V_72 -> V_82 , V_79 -> V_82 ,
sizeof( V_72 -> V_82 ) ) ;
V_72 -> V_2 = V_79 -> V_2 ;
return 0 ;
}
return - V_30 ;
}
static int F_25 ( struct V_6 * V_6 , void * V_7 ,
struct V_83 * V_72 )
{
struct V_24 * V_25 = F_7 ( V_6 ) ;
struct V_26 * V_27 = F_8 ( V_25 ) ;
int V_57 ;
F_15 ( & V_27 -> V_54 ) ;
V_57 = F_26 ( V_25 , V_72 ) ;
F_16 ( & V_27 -> V_54 ) ;
return V_57 ;
}
static int F_27 ( struct V_6 * V_6 , void * V_7 ,
struct V_83 * V_72 )
{
struct V_24 * V_25 = F_7 ( V_6 ) ;
struct V_26 * V_27 = F_8 ( V_25 ) ;
struct V_84 * V_85 = F_14 ( V_25 ) ;
F_15 ( & V_27 -> V_54 ) ;
V_72 -> V_86 . V_87 = V_85 -> V_87 ;
F_16 ( & V_27 -> V_54 ) ;
return 0 ;
}
static int F_28 ( struct V_6 * V_6 , void * V_7 ,
struct V_83 * V_72 )
{
struct V_24 * V_25 = F_7 ( V_6 ) ;
struct V_26 * V_27 = F_8 ( V_25 ) ;
int V_57 ;
F_15 ( & V_27 -> V_54 ) ;
V_57 = F_29 ( V_25 , V_72 , NULL ) ;
F_16 ( & V_27 -> V_54 ) ;
return V_57 ;
}
static int F_30 ( struct V_6 * V_6 , void * V_7 ,
struct V_83 * V_72 )
{
struct V_24 * V_25 = F_7 ( V_6 ) ;
struct V_26 * V_27 = F_8 ( V_25 ) ;
int V_57 ;
F_15 ( & V_27 -> V_54 ) ;
if ( V_27 -> V_88 ) {
V_57 = - V_89 ;
F_16 ( & V_27 -> V_54 ) ;
return V_57 ;
}
V_57 = F_31 ( V_25 , V_72 ) ;
F_16 ( & V_27 -> V_54 ) ;
return V_57 ;
}
static int F_32 ( struct V_6 * V_6 , void * V_7 ,
struct V_83 * V_72 )
{
struct V_24 * V_25 = F_7 ( V_6 ) ;
struct V_26 * V_27 = F_8 ( V_25 ) ;
int V_57 ;
F_15 ( & V_27 -> V_54 ) ;
V_57 = F_33 ( V_25 , V_72 ) ;
F_16 ( & V_27 -> V_54 ) ;
return V_57 ;
}
void F_34 ( struct V_90 * V_91 )
{
struct V_92 * V_93 ;
if ( V_91 == NULL )
return;
V_93 = V_91 -> V_94 ;
if ( V_93 && V_93 -> V_95 ) {
F_35 ( V_93 -> V_95 ) ;
V_93 -> V_95 = NULL ;
}
}
static void F_36 ( struct V_96 * V_97 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < V_98 ; V_3 ++ ) {
F_34 ( V_97 -> V_99 [ V_3 ] ) ;
F_37 ( V_97 -> V_99 [ V_3 ] ) ;
V_97 -> V_99 [ V_3 ] = NULL ;
}
}
int F_38 ( struct V_40 * V_41 ,
T_2 V_100 )
{
struct V_26 * V_27 = V_41 -> V_27 ;
struct V_101 * V_102 = NULL , * V_103 ;
struct V_104 * V_105 = NULL , * V_106 ;
struct V_107 * V_108 = NULL , * V_109 ;
int V_110 ;
struct V_111 * V_112 =
F_39 ( & V_41 -> V_113 . V_114 ) ;
unsigned int V_3 ;
if ( F_40 ( & V_41 -> V_115 ) &&
V_41 -> V_113 . V_114 . V_116 . V_117 ) {
V_110 = V_118 +
V_119 ;
F_18 ( V_27 -> V_59 , L_9 , V_110 ) ;
while ( V_110 -- ) {
V_102 = F_41 ( sizeof( struct V_101 ) , V_120 ) ;
if ( ! V_102 ) {
F_19 ( V_27 -> V_59 , L_10 ) ;
goto error;
}
if ( F_42 (
V_41 , V_100 , V_102 , NULL , NULL ) ) {
F_37 ( V_102 ) ;
goto error;
}
F_43 ( & V_102 -> V_121 , & V_41 -> V_115 ) ;
}
}
if ( F_40 ( & V_41 -> V_122 ) && V_112 &&
V_112 -> V_117 ) {
V_110 = V_118 + 1 ;
F_18 ( V_27 -> V_59 , L_11 , V_110 ) ;
while ( V_110 -- ) {
V_105 = F_41 ( sizeof( struct V_104 ) , V_120 ) ;
if ( ! V_105 ) {
F_19 ( V_27 -> V_59 , L_12 ) ;
F_37 ( V_102 ) ;
goto error;
}
if ( F_42 (
V_41 , V_100 , NULL , V_105 , NULL ) ) {
F_37 ( V_105 ) ;
goto error;
}
F_43 ( & V_105 -> V_121 , & V_41 -> V_122 ) ;
}
}
for ( V_3 = 0 ; V_3 < V_123 ; V_3 ++ ) {
if ( F_40 ( & V_41 -> V_124 [ V_3 ] ) &&
F_40 ( & V_41 -> V_125 [ V_3 ] ) &&
F_40 ( & V_41 -> V_126 [ V_3 ] ) ) {
V_110 = V_118 +
V_127 ;
F_18 ( V_27 -> V_59 , L_13 ,
V_110 , V_3 ) ;
while ( V_110 -- ) {
V_108 = F_41 ( sizeof( struct V_107 ) ,
V_120 ) ;
if ( ! V_108 ) {
F_19 ( V_27 -> V_59 , L_14 ) ;
goto error;
}
if ( F_42 (
V_41 , V_100 , NULL , NULL , V_108 ) ) {
F_37 ( V_108 ) ;
goto error;
}
F_43 ( & V_108 -> V_121 , & V_41 -> V_124 [ V_3 ] ) ;
}
}
}
return 0 ;
error:
F_19 ( V_27 -> V_59 , L_15 ) ;
F_44 (dis_buf, _dis_buf, &asd->dis_stats, list) {
F_45 ( V_105 ) ;
F_46 ( & V_105 -> V_121 ) ;
F_37 ( V_105 ) ;
}
F_44 (s3a_buf, _s3a_buf, &asd->s3a_stats, list) {
F_47 ( V_102 ) ;
F_46 ( & V_102 -> V_121 ) ;
F_37 ( V_102 ) ;
}
for ( V_3 = 0 ; V_3 < V_123 ; V_3 ++ ) {
F_44 (md_buf, _md_buf, &asd->metadata[i],
list) {
F_48 ( V_108 ) ;
F_46 ( & V_108 -> V_121 ) ;
F_37 ( V_108 ) ;
}
}
return - V_128 ;
}
int F_49 ( struct V_6 * V_6 , void * V_7 ,
struct V_129 * V_130 )
{
struct V_24 * V_25 = F_7 ( V_6 ) ;
struct V_84 * V_85 = F_14 ( V_25 ) ;
struct V_40 * V_41 = V_85 -> V_41 ;
struct V_131 V_132 ;
struct V_133 * V_134 ;
struct V_92 * V_93 ;
T_2 V_135 = F_50 ( V_25 ) ;
T_2 V_100 = F_51 ( V_41 , V_135 ) ;
int V_57 = 0 , V_3 = 0 ;
if ( V_130 -> V_110 == 0 ) {
F_52 ( & V_85 -> V_43 . V_136 ) ;
if ( ! F_40 ( & V_85 -> V_43 . V_137 ) )
F_53 ( & V_85 -> V_43 ) ;
F_36 ( & V_85 -> V_43 ) ;
F_54 ( & V_85 -> V_43 . V_136 ) ;
memset ( V_85 -> V_138 , 0 ,
V_98 * sizeof( unsigned int ) ) ;
memset ( V_85 -> V_139 , 0 ,
V_98 *
sizeof( struct V_140 * ) ) ;
return 0 ;
}
V_57 = F_55 ( & V_85 -> V_43 , V_130 ) ;
if ( V_57 )
return V_57 ;
F_38 ( V_41 , V_100 ) ;
if ( V_130 -> V_141 == V_142 )
return 0 ;
V_57 = F_56 ( V_41 , V_135 , & V_132 ) ;
if ( V_57 )
return V_57 ;
for ( V_3 = 0 ; V_3 < V_130 -> V_110 ; V_3 ++ ) {
if ( F_57 ( & V_134 , & V_132 ) )
goto error;
V_93 = V_85 -> V_43 . V_99 [ V_3 ] -> V_94 ;
V_93 -> V_95 = V_134 ;
}
return V_57 ;
error:
while ( V_3 -- ) {
V_93 = V_85 -> V_43 . V_99 [ V_3 ] -> V_94 ;
F_35 ( V_93 -> V_95 ) ;
}
if ( V_41 -> V_143 )
F_35 ( V_41 -> V_143 ) ;
return - V_128 ;
}
int F_58 ( struct V_6 * V_6 , void * V_7 ,
struct V_129 * V_130 )
{
struct V_24 * V_25 = F_7 ( V_6 ) ;
struct V_26 * V_27 = F_8 ( V_25 ) ;
int V_57 ;
F_15 ( & V_27 -> V_54 ) ;
V_57 = F_49 ( V_6 , V_7 , V_130 ) ;
F_16 ( & V_27 -> V_54 ) ;
return V_57 ;
}
static int F_59 ( struct V_6 * V_6 , void * V_7 ,
struct V_129 * V_130 )
{
struct V_24 * V_25 = F_7 ( V_6 ) ;
struct V_84 * V_85 = F_14 ( V_25 ) ;
if ( V_130 -> V_110 == 0 ) {
F_52 ( & V_85 -> V_144 . V_136 ) ;
F_36 ( & V_85 -> V_144 ) ;
F_54 ( & V_85 -> V_144 . V_136 ) ;
return 0 ;
}
return F_55 ( & V_85 -> V_144 , V_130 ) ;
}
static int F_60 ( struct V_6 * V_6 , void * V_7 ,
struct V_145 * V_146 )
{
struct V_24 * V_25 = F_7 ( V_6 ) ;
struct V_84 * V_85 = F_14 ( V_25 ) ;
return F_61 ( & V_85 -> V_43 , V_146 ) ;
}
static int F_62 ( struct V_6 * V_6 , void * V_7 ,
struct V_145 * V_146 )
{
struct V_24 * V_25 = F_7 ( V_6 ) ;
struct V_84 * V_85 = F_14 ( V_25 ) ;
return F_61 ( & V_85 -> V_144 , V_146 ) ;
}
static int F_63 ( struct V_6 * V_6 , void * V_7 , struct V_145 * V_146 )
{
static const int V_147 = V_148 |
V_149 ;
struct V_24 * V_25 = F_7 ( V_6 ) ;
struct V_26 * V_27 = F_8 ( V_25 ) ;
struct V_84 * V_85 = F_14 ( V_25 ) ;
struct V_40 * V_41 = V_85 -> V_41 ;
struct V_90 * V_91 ;
struct V_92 * V_93 ;
struct V_131 V_132 ;
struct V_133 * V_150 = NULL ;
T_1 V_151 ;
T_1 V_152 ;
int V_57 = 0 ;
F_15 ( & V_27 -> V_54 ) ;
if ( V_27 -> V_88 ) {
V_57 = - V_89 ;
goto error;
}
if ( V_41 -> V_44 == V_153 ) {
F_19 ( V_27 -> V_59 , L_16 ,
V_60 ) ;
V_57 = - V_89 ;
goto error;
}
if ( ! V_146 || V_146 -> V_28 >= V_98 ||
! V_85 -> V_43 . V_99 [ V_146 -> V_28 ] ) {
F_19 ( V_27 -> V_59 , L_17 ) ;
V_57 = - V_30 ;
goto error;
}
if ( V_146 -> V_141 == V_142 ) {
struct V_154 V_155 ;
V_91 = V_85 -> V_43 . V_99 [ V_146 -> V_28 ] ;
V_93 = V_91 -> V_94 ;
if ( ! V_93 ) {
V_57 = - V_30 ;
goto error;
}
V_151 = V_91 -> V_156 ;
V_152 = ( V_151 + ( V_157 - 1 ) ) >> V_158 ;
if ( V_91 -> V_159 == V_146 -> V_160 . V_161 && V_93 -> V_95 )
goto V_162;
if ( F_56 ( V_41 ,
F_50 ( V_25 ) , & V_132 ) ) {
V_57 = - V_89 ;
goto error;
}
V_155 . V_152 = V_152 ;
#ifdef F_64
#ifndef F_9
V_155 . type = V_146 -> type == V_163
? V_164 : V_165 ;
#else
if ( V_146 -> V_38 & V_166 ) {
V_155 . type = V_164 ;
if ( V_41 -> V_167 -> V_168 != V_169 ) {
F_18 ( V_27 -> V_59 , L_18 ,
V_146 -> V_160 . V_161 , V_41 -> V_167 -> V_168 ) ;
if ( ( V_146 -> V_160 . V_161 &
( V_170 ) ) != 0 ) {
F_19 ( V_27 -> V_59 ,
L_19 ,
V_146 -> V_160 . V_161 ) ;
V_57 = - V_30 ;
goto error;
}
V_146 -> V_160 . V_161 |= V_41 -> V_167 -> V_168 <<
V_171 ;
} else {
F_19 ( V_27 -> V_59 , L_20 ) ;
V_57 = - V_30 ;
goto error;
}
} else {
V_155 . type = V_165 ;
}
#endif
#else
V_155 . type = V_165 ;
#endif
V_57 = F_65 ( & V_150 , & V_132 ,
( void * ) V_146 -> V_160 . V_161 ,
0 , & V_155 ) ;
if ( V_57 ) {
F_19 ( V_27 -> V_59 , L_21 ) ;
goto error;
}
if ( V_93 -> V_95 ) {
F_52 ( & V_85 -> V_43 . V_136 ) ;
F_35 ( V_93 -> V_95 ) ;
V_93 -> V_95 = NULL ;
V_91 -> V_172 = V_173 ;
F_54 ( & V_85 -> V_43 . V_136 ) ;
}
V_93 -> V_95 = V_150 ;
V_146 -> V_174 &= ~ V_175 ;
V_146 -> V_174 |= V_176 ;
V_146 -> V_174 &= ~ V_177 ;
} else if ( V_146 -> V_141 == V_178 ) {
V_146 -> V_174 |= V_175 ;
V_146 -> V_174 |= V_176 ;
V_146 -> V_174 &= ~ V_177 ;
}
V_162:
if ( ! ( ( V_146 -> V_174 & V_147 ) == V_147 ) )
F_66 () ;
if ( ! F_67 ( V_85 ) &&
( V_146 -> V_179 & V_180 ) ) {
V_85 -> V_138 [ V_146 -> V_28 ] = V_146 -> V_179 &
~ V_180 ;
F_18 ( V_27 -> V_59 , L_22 ,
V_85 -> V_138 [ V_146 -> V_28 ] ) ;
} else {
V_85 -> V_138 [ V_146 -> V_28 ] = 0 ;
}
V_85 -> V_139 [ V_146 -> V_28 ] = NULL ;
F_16 ( & V_27 -> V_54 ) ;
V_57 = F_68 ( & V_85 -> V_43 , V_146 ) ;
F_15 ( & V_27 -> V_54 ) ;
if ( V_57 )
goto error;
if ( V_41 -> V_44 == V_51 ) {
if ( ! F_40 ( & V_85 -> V_181 ) ) {
F_69 ( V_85 ) ;
} else {
F_70 ( V_41 ) ;
#ifndef F_9
if ( ! F_71 ( V_41 ) && F_72 ( V_41 ) )
F_73 ( V_41 ) ;
#else
if ( ! F_71 ( V_85 ) &&
F_74 ( V_85 ) )
F_73 ( V_85 ) ;
#endif
}
}
if ( V_41 -> V_182 -> V_168 &&
F_50 ( V_25 )
== V_183 &&
V_85 -> V_43 . V_44 &&
! V_41 -> V_184 -> V_168 &&
V_41 -> V_113 . V_185 . V_186 == 1 ) {
#ifndef F_9
V_41 -> V_187 ++ ;
F_18 ( V_27 -> V_59 , L_23 ) ;
#else
if ( V_41 -> V_188 ) {
V_57 = F_75 ( V_41 ,
V_41 -> V_113 . V_185 . V_186 ,
V_41 -> V_113 . V_185 . V_189 ,
V_41 -> V_113 . V_185 . V_190 ) ;
V_41 -> V_188 = false ;
F_18 ( V_27 -> V_59 , L_24 ,
V_60 , V_57 ) ;
} else {
V_41 -> V_187 ++ ;
V_41 -> V_188 = false ;
F_18 ( V_27 -> V_59 , L_23 ) ;
}
#endif
}
F_16 ( & V_27 -> V_54 ) ;
F_18 ( V_27 -> V_59 , L_25 , V_146 -> V_28 ,
V_25 -> V_33 , V_41 -> V_28 ) ;
return V_57 ;
error:
F_16 ( & V_27 -> V_54 ) ;
return V_57 ;
}
static int F_76 ( struct V_6 * V_6 , void * V_7 ,
struct V_145 * V_146 )
{
struct V_24 * V_25 = F_7 ( V_6 ) ;
struct V_26 * V_27 = F_8 ( V_25 ) ;
struct V_84 * V_85 = F_14 ( V_25 ) ;
int V_57 ;
F_15 ( & V_27 -> V_54 ) ;
if ( V_27 -> V_88 ) {
V_57 = - V_89 ;
goto error;
}
if ( ! V_146 || V_146 -> V_28 >= V_98 ||
! V_85 -> V_144 . V_99 [ V_146 -> V_28 ] ) {
F_19 ( V_27 -> V_59 , L_17 ) ;
V_57 = - V_30 ;
goto error;
}
if ( V_146 -> V_141 != V_178 ) {
F_19 ( V_27 -> V_59 , L_26 ) ;
V_57 = - V_30 ;
goto error;
}
if ( V_146 -> type != V_191 ) {
F_19 ( V_27 -> V_59 , L_27 ) ;
V_57 = - V_30 ;
goto error;
}
F_16 ( & V_27 -> V_54 ) ;
return F_68 ( & V_85 -> V_144 , V_146 ) ;
error:
F_16 ( & V_27 -> V_54 ) ;
return V_57 ;
}
static int F_77 ( struct V_84 * V_85 ,
struct V_145 * V_146 )
{
struct V_92 * V_93 ;
struct V_133 * V_150 ;
int V_3 ;
for ( V_3 = 0 ; V_85 -> V_43 . V_99 [ V_3 ] ; V_3 ++ ) {
V_93 = V_85 -> V_43 . V_99 [ V_3 ] -> V_94 ;
V_150 = V_93 -> V_95 ;
if ( V_146 -> V_28 == V_85 -> V_43 . V_99 [ V_3 ] -> V_3 && V_150 )
return V_150 -> V_192 ;
}
return - V_30 ;
}
static int F_78 ( struct V_6 * V_6 , void * V_7 , struct V_145 * V_146 )
{
struct V_24 * V_25 = F_7 ( V_6 ) ;
struct V_84 * V_85 = F_14 ( V_25 ) ;
struct V_40 * V_41 = V_85 -> V_41 ;
struct V_26 * V_27 = F_8 ( V_25 ) ;
int V_57 = 0 ;
F_15 ( & V_27 -> V_54 ) ;
if ( V_27 -> V_88 ) {
F_16 ( & V_27 -> V_54 ) ;
return - V_89 ;
}
if ( V_41 -> V_44 == V_153 ) {
F_16 ( & V_27 -> V_54 ) ;
F_19 ( V_27 -> V_59 , L_16 ,
V_60 ) ;
return - V_89 ;
}
F_16 ( & V_27 -> V_54 ) ;
V_57 = F_79 ( & V_85 -> V_43 , V_146 , V_6 -> V_193 & V_194 ) ;
if ( V_57 ) {
F_18 ( V_27 -> V_59 , L_28 , V_60 , V_57 ) ;
return V_57 ;
}
F_15 ( & V_27 -> V_54 ) ;
V_146 -> V_195 = V_85 -> V_87 . V_196 ;
V_146 -> V_38 = V_41 -> V_197 [ V_146 -> V_28 ] ;
V_146 -> V_38 &= 0x0000ffff ;
if ( ! ( V_146 -> V_174 & V_198 ) )
V_146 -> V_38 |= F_77 ( V_85 , V_146 ) << 16 ;
V_146 -> V_179 = V_85 -> V_199 [ V_146 -> V_28 ] ;
F_16 ( & V_27 -> V_54 ) ;
F_18 ( V_27 -> V_59 , L_29 ,
V_146 -> V_28 , V_25 -> V_33 , V_41 -> V_28 , V_146 -> V_38 >> 16 ,
V_146 -> V_179 ) ;
return 0 ;
}
enum V_200 F_80 ( struct V_40 * V_41 )
{
if ( F_81 ( V_41 ) )
return V_201 ;
if ( V_41 -> V_182 -> V_168 ) {
if ( V_41 -> V_202 -> V_168 == V_203 )
return V_204 ;
else
return V_205 ;
}
if ( V_41 -> V_206 -> V_168 == V_207 )
return V_204 ;
if ( V_41 -> V_206 -> V_168 == V_208 )
return V_209 ;
switch ( V_41 -> V_202 -> V_168 ) {
case V_210 :
return V_205 ;
case V_203 :
return V_204 ;
case V_211 :
default:
return V_209 ;
}
}
static unsigned int F_82 ( struct V_40 * V_41 )
{
struct V_26 * V_27 = V_41 -> V_27 ;
if ( V_27 -> V_31 [ V_41 -> V_55 ] . V_212 ->
V_213 [ V_41 -> V_214 ] . V_215 > 1 ) {
if ( V_41 -> V_216 )
return 1 ;
else
return 2 ;
}
if ( V_41 -> V_206 -> V_168 != V_217 ||
V_41 -> V_218 )
return 1 ;
if ( V_41 -> V_202 -> V_168 == V_203 ||
( V_41 -> V_202 -> V_168 == V_211 &&
! F_83 (
V_41 -> V_86 [
V_41 -> V_219 ] . V_86 . V_74 ) &&
! V_41 -> V_182 -> V_168 ) )
return 2 ;
else
return 1 ;
}
int F_84 ( struct V_26 * V_27 ,
bool V_220 )
{
unsigned int V_221 = - 1 , V_222 = - 1 , V_223 = 0 ;
int V_3 , V_57 ;
for ( V_3 = 0 ; V_3 < V_27 -> V_50 ; V_3 ++ ) {
int V_66 = V_27 -> V_41 [ V_3 ] . V_55 ;
if ( V_27 -> V_31 [ V_66 ] . V_212 ->
V_213 [ V_27 -> V_41 [ V_3 ] . V_214 ] . V_224 )
V_222 = V_66 ;
else
V_221 = V_66 ;
}
if ( V_221 == - 1 || V_222 == - 1 ) {
V_221 = V_225 ;
V_222 = V_226 ;
F_21 ( V_27 -> V_59 ,
L_30 ,
V_27 -> V_31 [ V_221 ] . V_32 -> V_33 ,
V_27 -> V_31 [ V_222 ] . V_32 -> V_33 ) ;
}
V_57 = F_20 ( V_27 -> V_31 [ V_221 ] . V_32 , V_62 ,
V_227 , V_228 ,
& V_223 ) ;
if ( V_57 )
F_21 ( V_27 -> V_59 ,
L_31 ,
V_27 -> V_31 [ V_221 ] . V_32 -> V_33 ) ;
V_57 = F_20 ( V_27 -> V_31 [ V_221 ] . V_32 ,
V_64 , V_229 , 1 ) ;
if ( V_57 ) {
F_19 ( V_27 -> V_59 , L_32 ,
V_27 -> V_31 [ V_221 ] . V_32 -> V_33 ) ;
return - V_30 ;
}
if ( V_223 != 0 )
F_85 ( V_223 ) ;
V_57 = F_20 ( V_27 -> V_31 [ V_222 ] . V_32 ,
V_64 , V_229 , 1 ) ;
if ( V_57 ) {
F_19 ( V_27 -> V_59 , L_33 ,
V_27 -> V_31 [ V_222 ] . V_32 -> V_33 ) ;
F_20 ( V_27 -> V_31 [ V_221 ] . V_32 , V_64 , V_229 , 0 ) ;
return - V_30 ;
}
return 0 ;
}
static void F_86 ( struct V_26 * V_27 )
{
struct V_230 V_231 = { 0 } ;
int V_3 ;
V_231 . type = V_232 ;
for ( V_3 = 0 ; V_3 < V_27 -> V_50 ; V_3 ++ ) {
int V_66 = V_27 -> V_41 [ V_3 ] . V_55 ;
if ( V_27 -> V_31 [ V_66 ] . V_212 ->
V_213 [ V_27 -> V_41 [ V_3 ] . V_214 ] . V_224 ) {
F_87 ( V_27 -> V_41 [ V_3 ] . V_233 . V_234 , & V_231 ) ;
break;
}
}
}
static void F_88 ( struct V_40 * V_41 )
{
struct V_235 * V_236 ;
V_236 = F_89 ( & V_41 -> V_233 , NULL ,
V_237 ,
V_238 ) ;
if ( V_236 -> V_239 * V_236 -> V_240 >= 4096 * 3072 )
F_90 ( V_241 , 0x7F ) ;
else
F_90 ( V_241 , 0x00 ) ;
}
static int F_91 ( struct V_6 * V_6 , void * V_7 ,
enum V_242 type )
{
struct V_24 * V_25 = F_7 ( V_6 ) ;
struct V_84 * V_85 = F_14 ( V_25 ) ;
struct V_40 * V_41 = V_85 -> V_41 ;
struct V_26 * V_27 = F_8 ( V_25 ) ;
enum V_200 V_243 ;
unsigned int V_244 ;
unsigned int V_245 = V_246 ;
int V_57 = 0 ;
unsigned long V_247 ;
F_18 ( V_27 -> V_59 , L_34 ,
F_50 ( V_25 ) , V_41 -> V_28 ) ;
if ( type != V_248 ) {
F_18 ( V_27 -> V_59 , L_35 ) ;
return - V_30 ;
}
F_15 ( & V_27 -> V_54 ) ;
if ( V_27 -> V_88 ) {
V_57 = - V_89 ;
goto V_249;
}
if ( V_41 -> V_44 == V_153 ) {
V_57 = - V_61 ;
goto V_249;
}
if ( V_85 -> V_43 . V_44 )
goto V_249;
F_88 ( V_41 ) ;
V_244 = F_82 ( V_41 ) ;
F_92 ( & V_85 -> V_250 , V_247 ) ;
if ( F_40 ( & ( V_85 -> V_43 . V_137 ) ) ) {
F_93 ( & V_85 -> V_250 , V_247 ) ;
F_18 ( V_27 -> V_59 , L_36 ) ;
V_57 = - V_30 ;
goto V_249;
}
F_93 ( & V_85 -> V_250 , V_247 ) ;
V_57 = F_94 ( & V_85 -> V_43 ) ;
if ( V_57 )
goto V_249;
V_41 -> V_187 = 0 ;
#ifdef F_9
V_41 -> V_188 = false ;
#endif
if ( ( F_10 ( V_41 ) > V_244 ) &&
( ! V_27 -> V_31 [ V_41 -> V_55 ] . V_212 -> V_251 ) ) {
if ( V_41 -> V_182 -> V_168 &&
F_50 ( V_25 )
== V_183 ) {
if ( V_41 -> V_202 -> V_168 == V_203 )
F_18 ( V_27 -> V_59 , L_37 ,
V_41 -> V_252 ) ;
else
F_18 ( V_27 -> V_59 , L_38 ,
V_41 -> V_252 ) ;
if ( V_41 -> V_253 == V_254 ) {
F_95 ( & V_41 -> V_255 ) ;
F_16 ( & V_27 -> V_54 ) ;
if ( F_96 (
& V_41 -> V_256 ) != 0 )
return - V_257 ;
F_15 ( & V_27 -> V_54 ) ;
}
F_69 ( V_85 ) ;
F_97 ( V_27 , V_258 , false ) ;
if ( ! V_41 -> V_184 -> V_168 ) {
V_57 = F_75 ( V_41 ,
V_41 -> V_113 . V_185 . V_186 ,
V_41 -> V_113 . V_185 . V_189 ,
V_41 -> V_113 . V_185 . V_190 ) ;
if ( V_57 ) {
V_57 = - V_30 ;
goto V_249;
}
if ( V_41 -> V_259 -> V_168 )
F_86 ( V_27 ) ;
}
}
F_70 ( V_41 ) ;
goto V_249;
}
if ( V_41 -> V_44 == V_51 ) {
F_70 ( V_41 ) ;
goto V_260;
}
V_243 = F_80 ( V_41 ) ;
V_57 = F_98 ( V_41 ) ;
if ( V_57 < 0 ) {
F_19 ( V_27 -> V_59 , L_39 ) ;
goto V_249;
}
if ( V_41 -> V_113 . V_261 ) {
F_99 ( V_41 , & V_41 -> V_113 . V_262 ) ;
if ( V_41 -> V_113 . V_262 . V_263 . V_264 )
F_100 ( V_41 ,
& V_41 -> V_113 . V_262 . V_264 ) ;
F_101 ( V_41 ) ;
V_41 -> V_113 . V_261 = false ;
memset ( & V_41 -> V_113 . V_262 . V_263 , 0 ,
sizeof( struct V_265 ) ) ;
}
V_41 -> V_113 . V_266 = NULL ;
V_57 = F_102 ( V_41 , V_243 , false ) ;
if ( V_57 )
goto V_249;
V_41 -> V_44 = V_51 ;
F_103 ( & V_41 -> V_267 , - 1 ) ;
F_103 ( & V_41 -> V_268 , - 1 ) ;
F_103 ( & V_41 -> V_269 , - 1 ) ;
if ( V_27 -> V_68 . V_69 )
V_245 = V_270 ;
V_41 -> V_113 . V_271 = false ;
V_41 -> V_252 = 0 ;
V_41 -> V_272 = 1 ;
V_41 -> V_273 = 1 ;
F_69 ( V_85 ) ;
F_70 ( V_41 ) ;
if ( F_10 ( V_41 ) < V_244 )
goto V_249;
V_260:
if ( V_27 -> V_274 ) {
V_41 -> V_113 . V_275 = 0 ;
V_41 -> V_113 . V_276 = V_277 ;
F_104 ( V_41 ) ;
}
if ( ! V_27 -> V_68 . V_69 ) {
F_105 ( V_27 , V_278 ,
F_106 ( V_27 ) ) ;
F_107 ( V_41 ) ;
if ( F_11 ( V_27 ) > 1 ) {
if ( F_97 ( V_27 ,
V_258 , false ) < 0 )
F_18 ( V_27 -> V_59 , L_40 ) ;
} else {
if ( F_97 ( V_27 ,
V_279 , false ) < 0 )
F_18 ( V_27 -> V_59 , L_40 ) ;
}
} else {
if ( F_97 ( V_27 , V_258 , false ) < 0 )
F_18 ( V_27 -> V_59 , L_40 ) ;
}
if ( V_41 -> V_259 -> V_168 && F_11 ( V_27 ) ==
V_280 ) {
V_57 = F_84 ( V_27 , false ) ;
if ( V_57 ) {
F_19 ( V_27 -> V_59 , L_41 ) ;
goto V_249;
}
#ifndef F_9
F_108 ( V_27 , V_245 ) ;
#else
F_108 ( V_85 , V_245 , true ) ;
#endif
goto V_281;
} else if ( V_41 -> V_259 -> V_168 && ( F_11 ( V_27 ) <
V_280 ) ) {
#ifdef F_9
F_108 ( V_85 , V_245 , false ) ;
#endif
goto V_281;
}
if ( V_27 -> V_282 . V_283 >= ( ( V_284 <<
V_285 ) | V_286 ) ) {
F_109 ( V_27 -> V_287 , V_288 ,
V_27 -> V_289 . V_290 |
V_291 ) ;
}
V_57 = F_20 ( V_27 -> V_31 [ V_41 -> V_55 ] . V_32 ,
V_64 , V_229 , 1 ) ;
if ( V_57 ) {
V_41 -> V_44 = V_292 ;
V_57 = - V_30 ;
goto V_249;
}
#ifndef F_9
if ( F_72 ( V_41 ) )
F_110 ( V_41 , V_245 ) ;
#else
if ( F_74 ( V_85 ) )
F_111 ( V_85 , V_245 ) ;
#endif
V_281:
if ( V_41 -> V_182 -> V_168 ) {
struct V_235 * V_236 ;
V_236 = F_89 ( & V_41 -> V_233 , NULL ,
V_237 ,
V_238 ) ;
F_112 ( & V_41 -> V_256 ) ;
V_41 -> V_253 = V_254 ;
F_113 ( V_41 -> V_293 , & V_41 -> V_255 ) ;
F_114 ( V_27 ,
F_115 ( V_236 -> V_240 ) ) ;
} else {
V_41 -> V_253 = V_294 ;
}
V_249:
F_16 ( & V_27 -> V_54 ) ;
return V_57 ;
}
int F_116 ( struct V_6 * V_6 , void * V_7 , enum V_242 type )
{
struct V_24 * V_25 = F_7 ( V_6 ) ;
struct V_26 * V_27 = F_8 ( V_25 ) ;
struct V_84 * V_85 = F_14 ( V_25 ) ;
struct V_40 * V_41 = V_85 -> V_41 ;
struct V_84 * V_295 = NULL ;
struct V_84 * V_296 = NULL ;
struct V_84 * V_297 = NULL ;
struct V_84 * V_298 = NULL ;
struct V_90 * V_91 , * V_299 ;
enum V_200 V_243 ;
int V_57 ;
unsigned long V_174 ;
bool V_300 = false ;
F_18 ( V_27 -> V_59 , L_42 ,
F_50 ( V_25 ) , V_41 -> V_28 ) ;
F_117 ( ! F_118 ( & V_27 -> V_54 ) ) ;
F_117 ( ! F_119 ( & V_27 -> V_301 ) ) ;
if ( type != V_248 ) {
F_18 ( V_27 -> V_59 , L_35 ) ;
return - V_30 ;
}
if ( ( V_41 -> V_182 -> V_168 ||
V_27 -> V_31 [ V_41 -> V_55 ] . V_212 -> V_251 ) &&
F_50 ( V_25 ) !=
V_302 &&
F_50 ( V_25 ) !=
V_303 ) {
if ( V_27 -> V_31 [ V_41 -> V_55 ] . V_212 -> V_251 ) {
F_20 ( V_27 -> V_31 [ V_41 -> V_55 ] . V_32 ,
V_64 , V_229 , 0 ) ;
} else if ( F_50 ( V_25 )
== V_183 ) {
if ( V_41 -> V_113 . V_185 . V_186 == - 1 )
F_75 ( V_41 ,
0 , 0 , 0 ) ;
F_97 ( V_27 , V_279 , false ) ;
}
if ( V_85 -> V_304 != 0 ) {
F_120 ( 1 , L_43 ,
V_60 , V_85 -> V_25 . V_33 ) ;
F_21 ( V_27 -> V_59 , L_44 ) ;
F_121 ( V_27 ) ;
}
return F_122 ( & V_85 -> V_43 ) ;
}
if ( ! V_85 -> V_43 . V_44 )
return 0 ;
F_92 ( & V_27 -> V_305 , V_174 ) ;
if ( V_41 -> V_44 == V_51 ) {
V_41 -> V_44 = V_153 ;
V_300 = true ;
}
F_93 ( & V_27 -> V_305 , V_174 ) ;
if ( V_300 ) {
F_16 ( & V_27 -> V_54 ) ;
F_123 ( V_41 , true ) ;
if ( V_27 -> V_68 . V_69 )
F_20 ( V_27 -> V_31 [ V_41 -> V_55 ] . V_32 ,
V_64 , V_229 , 0 ) ;
F_15 ( & V_27 -> V_54 ) ;
F_124 ( V_41 ) ;
}
F_92 ( & V_27 -> V_305 , V_174 ) ;
if ( F_10 ( V_41 ) == 1 )
V_41 -> V_44 = V_292 ;
F_93 ( & V_27 -> V_305 , V_174 ) ;
if ( ! V_300 ) {
V_57 = F_122 ( & V_85 -> V_43 ) ;
if ( V_57 )
return V_57 ;
goto V_306;
}
F_125 ( V_41 ) ;
if ( ! V_27 -> V_68 . V_69 )
F_105 ( V_27 , V_278 ,
false ) ;
if ( V_41 -> V_253 == V_254 ) {
F_126 ( & V_41 -> V_255 ) ;
V_41 -> V_253 = V_294 ;
}
if ( V_300 ) {
V_243 = F_80 ( V_41 ) ;
V_57 = F_127 ( V_41 , V_243 , false ) ;
}
if ( V_41 -> V_45 . V_307 ) {
V_295 = & V_41 -> V_45 ;
F_128 ( & V_295 -> V_43 . V_308 ) ;
}
if ( V_41 -> V_47 . V_307 ) {
V_296 = & V_41 -> V_47 ;
F_128 ( & V_296 -> V_43 . V_308 ) ;
}
if ( V_41 -> V_42 . V_307 ) {
V_297 = & V_41 -> V_42 ;
F_128 ( & V_297 -> V_43 . V_308 ) ;
}
if ( V_41 -> V_46 . V_307 ) {
V_298 = & V_41 -> V_46 ;
F_128 ( & V_298 -> V_43 . V_308 ) ;
}
V_57 = F_122 ( & V_85 -> V_43 ) ;
if ( V_57 )
return V_57 ;
F_92 ( & V_85 -> V_250 , V_174 ) ;
F_44 (vb, _vb, &pipe->activeq, queue) {
V_91 -> V_172 = V_309 ;
F_46 ( & V_91 -> V_310 ) ;
}
F_44 (vb, _vb, &pipe->buffers_waiting_for_param, queue) {
V_91 -> V_172 = V_309 ;
F_46 ( & V_91 -> V_310 ) ;
V_85 -> V_138 [ V_91 -> V_3 ] = 0 ;
}
F_93 ( & V_85 -> V_250 , V_174 ) ;
F_129 ( V_41 ) ;
V_306:
if ( F_10 ( V_41 ) + 1
!= F_82 ( V_41 ) )
return 0 ;
if ( ! V_27 -> V_68 . V_69 )
V_57 = F_20 ( V_27 -> V_31 [ V_41 -> V_55 ] . V_32 ,
V_64 , V_229 , 0 ) ;
if ( V_27 -> V_274 ) {
V_41 -> V_113 . V_275 = 0 ;
V_41 -> V_113 . V_276 = V_277 ;
}
if ( F_11 ( V_27 ) ) {
F_121 ( V_27 ) ;
return 0 ;
}
if ( V_27 -> V_282 . V_283 >= ( ( V_284 <<
V_285 ) | V_286 ) ) {
F_109 ( V_27 -> V_287 , V_288 ,
V_27 -> V_289 . V_290 &
~ V_291 ) ;
}
if ( F_97 ( V_27 , V_311 , false ) )
F_21 ( V_27 -> V_59 , L_45 ) ;
if ( V_27 -> V_68 . V_312 == V_313 ) {
unsigned int V_3 ;
bool V_314 [ V_315 ] = { 0 } ;
if ( V_27 -> V_220 )
F_19 ( V_27 -> V_59 , L_46 ,
V_60 ) ;
for ( V_3 = 0 ; V_3 < V_27 -> V_50 ; V_3 ++ ) {
if ( V_27 -> V_41 [ V_3 ] . V_316 ) {
F_130 ( & V_27 ->
V_41 [ V_3 ] ) ;
V_314 [ V_3 ] = true ;
}
}
F_131 ( V_27 -> V_287 , V_317 , V_27 -> V_289 . V_318 |
V_319 ) ;
F_19 ( V_27 -> V_59 , L_47 ) ;
F_132 ( V_27 ) ;
for ( V_3 = 0 ; V_3 < V_27 -> V_50 ; V_3 ++ ) {
if ( V_314 [ V_3 ] )
F_133 ( & V_27 -> V_41 [ V_3 ] ) ;
}
V_27 -> V_220 = false ;
}
return V_57 ;
}
static int F_134 ( struct V_6 * V_6 , void * V_7 ,
enum V_242 type )
{
struct V_24 * V_25 = F_7 ( V_6 ) ;
struct V_26 * V_27 = F_8 ( V_25 ) ;
int V_76 ;
F_52 ( & V_27 -> V_301 ) ;
F_15 ( & V_27 -> V_54 ) ;
V_76 = F_116 ( V_6 , V_7 , type ) ;
F_16 ( & V_27 -> V_54 ) ;
F_54 ( & V_27 -> V_301 ) ;
return V_76 ;
}
static int F_135 ( struct V_6 * V_6 , void * V_7 ,
struct V_320 * V_321 )
{
struct V_24 * V_25 = F_7 ( V_6 ) ;
struct V_40 * V_41 = F_14 ( V_25 ) -> V_41 ;
struct V_26 * V_27 = F_8 ( V_25 ) ;
int V_3 , V_57 = - V_30 ;
for ( V_3 = 0 ; V_3 < V_322 ; V_3 ++ ) {
if ( V_323 [ V_3 ] . V_324 == V_321 -> V_324 ) {
V_57 = 0 ;
break;
}
}
if ( V_57 )
return V_57 ;
F_15 ( & V_27 -> V_54 ) ;
switch ( V_321 -> V_324 ) {
case V_325 :
case V_326 :
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
F_16 ( & V_27 -> V_54 ) ;
return F_136 ( V_27 -> V_31 [ V_41 -> V_55 ] . V_32 ->
V_345 , V_321 ) ;
case V_346 :
V_57 = F_137 ( V_41 , 0 , & V_321 -> V_347 ) ;
break;
case V_348 :
V_57 = F_138 ( V_41 , 0 , & V_321 -> V_347 ) ;
break;
case V_349 :
V_57 = F_139 ( V_41 , 0 , & V_321 -> V_347 ) ;
break;
case V_350 :
V_57 = F_140 ( V_41 , 0 , & V_321 -> V_347 ) ;
break;
case V_351 :
V_57 = F_141 ( V_41 , 0 , & V_321 -> V_347 ) ;
break;
case V_352 :
V_57 = F_142 ( V_41 , 0 , & V_321 -> V_347 ) ;
break;
case V_353 :
V_57 = F_143 ( V_41 , 0 , & V_321 -> V_347 ) ;
break;
default:
V_57 = - V_30 ;
break;
}
F_16 ( & V_27 -> V_54 ) ;
return V_57 ;
}
static int F_144 ( struct V_6 * V_6 , void * V_7 ,
struct V_320 * V_321 )
{
struct V_24 * V_25 = F_7 ( V_6 ) ;
struct V_40 * V_41 = F_14 ( V_25 ) -> V_41 ;
struct V_26 * V_27 = F_8 ( V_25 ) ;
int V_3 , V_57 = - V_30 ;
for ( V_3 = 0 ; V_3 < V_322 ; V_3 ++ ) {
if ( V_323 [ V_3 ] . V_324 == V_321 -> V_324 ) {
V_57 = 0 ;
break;
}
}
if ( V_57 )
return V_57 ;
F_15 ( & V_27 -> V_54 ) ;
switch ( V_321 -> V_324 ) {
case V_329 :
case V_330 :
case V_331 :
case V_354 :
case V_332 :
case V_333 :
case V_334 :
case V_355 :
case V_356 :
case V_335 :
case V_336 :
case V_337 :
case V_338 :
case V_357 :
case V_340 :
case V_341 :
case V_342 :
case V_343 :
case V_344 :
F_16 ( & V_27 -> V_54 ) ;
return F_145 ( NULL ,
V_27 -> V_31 [ V_41 -> V_55 ] . V_32 ->
V_345 , V_321 ) ;
case V_346 :
V_57 = F_137 ( V_41 , 1 , & V_321 -> V_347 ) ;
break;
case V_348 :
V_57 = F_138 ( V_41 , 1 , & V_321 -> V_347 ) ;
break;
case V_349 :
V_57 = F_139 ( V_41 , 1 , & V_321 -> V_347 ) ;
break;
case V_350 :
V_57 = F_140 ( V_41 , 1 , & V_321 -> V_347 ) ;
break;
case V_351 :
V_57 = F_141 ( V_41 , 1 , & V_321 -> V_347 ) ;
break;
case V_352 :
V_57 = F_142 ( V_41 , 1 , & V_321 -> V_347 ) ;
break;
case V_358 :
V_57 = F_146 ( V_41 , V_321 -> V_347 ) ;
break;
case V_353 :
V_57 = F_143 ( V_41 , 1 , & V_321 -> V_347 ) ;
break;
default:
V_57 = - V_30 ;
break;
}
F_16 ( & V_27 -> V_54 ) ;
return V_57 ;
}
static int F_147 ( struct V_6 * V_6 , void * V_7 ,
struct V_359 * V_360 )
{
int V_3 , V_57 = - V_30 ;
struct V_24 * V_25 = F_7 ( V_6 ) ;
struct V_40 * V_41 = F_14 ( V_25 ) -> V_41 ;
struct V_26 * V_27 = F_8 ( V_25 ) ;
switch ( V_360 -> V_324 ) {
case V_361 :
case V_362 :
case V_363 :
#ifndef F_9
return V_359 ( V_27 -> V_31 [ V_41 -> V_55 ] . V_32 ->
V_345 , V_360 ) ;
#else
if ( V_27 -> V_34 )
return V_359 ( V_27 -> V_34 -> V_345 , V_360 ) ;
else
return V_359 ( V_27 -> V_31 [ V_41 -> V_55 ] .
V_32 -> V_345 , V_360 ) ;
#endif
}
if ( V_360 -> V_324 & V_364 )
return V_57 ;
for ( V_3 = 0 ; V_3 < V_322 ; V_3 ++ ) {
if ( V_323 [ V_3 ] . V_324 == V_360 -> V_324 ) {
memcpy ( V_360 , & V_323 [ V_3 ] ,
sizeof( struct V_359 ) ) ;
V_360 -> V_38 [ 0 ] = 0 ;
V_57 = 0 ;
break;
}
}
if ( V_57 != 0 )
V_360 -> V_174 = V_365 ;
return V_57 ;
}
static int F_148 ( struct V_6 * V_6 , void * V_7 ,
struct V_366 * V_367 )
{
struct V_24 * V_25 = F_7 ( V_6 ) ;
struct V_40 * V_41 = F_14 ( V_25 ) -> V_41 ;
struct V_26 * V_27 = F_8 ( V_25 ) ;
struct V_320 V_368 ;
int V_3 ;
int V_57 = 0 ;
for ( V_3 = 0 ; V_3 < V_367 -> V_110 ; V_3 ++ ) {
V_368 . V_324 = V_367 -> V_369 [ V_3 ] . V_324 ;
V_368 . V_347 = V_367 -> V_369 [ V_3 ] . V_347 ;
switch ( V_368 . V_324 ) {
case V_326 :
case V_331 :
case V_325 :
case V_327 :
case V_370 :
case V_371 :
case V_338 :
case V_340 :
case V_341 :
case V_342 :
case V_343 :
case V_344 :
V_57 =
F_136 ( V_27 -> V_31 [ V_41 -> V_55 ] . V_32 ->
V_345 , & V_368 ) ;
break;
case V_361 :
case V_362 :
case V_363 :
case V_372 :
#ifndef F_9
if ( V_27 -> V_31 [ V_41 -> V_55 ] . V_34 )
#else
if ( V_27 -> V_34 )
#endif
V_57 =
#ifndef F_9
F_136 ( V_27 -> V_31 [ V_41 -> V_55 ] .
V_34 -> V_345 , & V_368 ) ;
#else
F_136 ( V_27 -> V_34 -> V_345 ,
& V_368 ) ;
#endif
else
V_57 =
F_136 ( V_27 -> V_31 [ V_41 -> V_55 ] .
V_32 -> V_345 , & V_368 ) ;
break;
case V_373 :
case V_374 :
case V_375 :
case V_376 :
case V_377 :
case V_378 :
case V_379 :
case V_380 :
if ( V_27 -> V_274 )
V_57 =
F_136 ( V_27 -> V_274 -> V_345 ,
& V_368 ) ;
break;
case V_381 :
F_15 ( & V_27 -> V_54 ) ;
V_57 = F_149 ( V_41 , 0 , & V_368 . V_347 ) ;
F_16 ( & V_27 -> V_54 ) ;
break;
case V_382 :
V_57 = F_20 (
V_27 -> V_31 [ V_41 -> V_55 ] . V_32 ,
V_213 , V_383 , ( T_1 * ) & V_368 . V_347 ) ;
break;
default:
V_57 = - V_30 ;
}
if ( V_57 ) {
V_367 -> V_384 = V_3 ;
break;
}
V_367 -> V_369 [ V_3 ] . V_347 = V_368 . V_347 ;
}
return V_57 ;
}
static int F_150 ( struct V_6 * V_6 , void * V_7 ,
struct V_366 * V_367 )
{
struct V_320 V_368 ;
int V_3 , V_57 = 0 ;
V_57 = F_148 ( V_6 , V_7 , V_367 ) ;
if ( V_57 != - V_30 )
return V_57 ;
for ( V_3 = 0 ; V_3 < V_367 -> V_110 ; V_3 ++ ) {
V_368 . V_324 = V_367 -> V_369 [ V_3 ] . V_324 ;
V_368 . V_347 = V_367 -> V_369 [ V_3 ] . V_347 ;
V_57 = F_135 ( V_6 , V_7 , & V_368 ) ;
V_367 -> V_369 [ V_3 ] . V_347 = V_368 . V_347 ;
if ( V_57 ) {
V_367 -> V_384 = V_3 ;
break;
}
}
return V_57 ;
}
static int F_151 ( struct V_6 * V_6 , void * V_7 ,
struct V_366 * V_367 )
{
struct V_24 * V_25 = F_7 ( V_6 ) ;
struct V_40 * V_41 = F_14 ( V_25 ) -> V_41 ;
struct V_26 * V_27 = F_8 ( V_25 ) ;
struct V_320 V_368 ;
int V_3 ;
int V_57 = 0 ;
for ( V_3 = 0 ; V_3 < V_367 -> V_110 ; V_3 ++ ) {
struct V_385 * V_386 ;
V_368 . V_324 = V_367 -> V_369 [ V_3 ] . V_324 ;
V_368 . V_347 = V_367 -> V_369 [ V_3 ] . V_347 ;
switch ( V_368 . V_324 ) {
case V_326 :
case V_331 :
case V_356 :
case V_325 :
case V_327 :
case V_387 :
case V_388 :
case V_338 :
case V_340 :
case V_341 :
case V_342 :
case V_343 :
case V_344 :
V_57 = F_145 ( NULL ,
V_27 -> V_31 [ V_41 -> V_55 ] . V_32 ->
V_345 , & V_368 ) ;
break;
case V_361 :
case V_362 :
case V_363 :
case V_372 :
#ifndef F_9
if ( V_27 -> V_31 [ V_41 -> V_55 ] . V_34 )
#else
if ( V_27 -> V_34 )
#endif
V_57 = F_145 ( NULL ,
#ifndef F_9
V_27 -> V_31 [ V_41 -> V_55 ] .
V_34 -> V_345 , & V_368 ) ;
#else
V_27 -> V_34 -> V_345 ,
& V_368 ) ;
#endif
else
V_57 = F_145 ( NULL ,
V_27 -> V_31 [ V_41 -> V_55 ] .
V_32 -> V_345 , & V_368 ) ;
break;
case V_373 :
case V_374 :
case V_375 :
case V_376 :
case V_377 :
case V_378 :
case V_379 :
case V_380 :
F_15 ( & V_27 -> V_54 ) ;
if ( V_27 -> V_274 ) {
V_57 =
F_145 ( NULL , V_27 -> V_274 -> V_345 ,
& V_368 ) ;
if ( V_368 . V_324 == V_379 ) {
V_41 -> V_113 . V_276 =
V_277 ;
V_41 -> V_113 . V_275 = 0 ;
}
}
F_16 ( & V_27 -> V_54 ) ;
break;
case V_381 :
F_15 ( & V_27 -> V_54 ) ;
V_57 = F_149 ( V_41 , 1 , & V_368 . V_347 ) ;
F_16 ( & V_27 -> V_54 ) ;
break;
default:
V_386 = F_152 ( & V_41 -> V_345 , V_368 . V_324 ) ;
if ( V_386 )
V_57 = F_153 ( V_386 , V_368 . V_347 ) ;
else
V_57 = - V_30 ;
}
if ( V_57 ) {
V_367 -> V_384 = V_3 ;
break;
}
V_367 -> V_369 [ V_3 ] . V_347 = V_368 . V_347 ;
}
int F_154 ( struct V_6 * V_6 , void * V_7 ,
struct V_366 * V_367 )
{
struct V_320 V_368 ;
int V_3 , V_57 = 0 ;
V_57 = F_151 ( V_6 , V_7 , V_367 ) ;
if ( V_57 != - V_30 )
return V_57 ;
for ( V_3 = 0 ; V_3 < V_367 -> V_110 ; V_3 ++ ) {
V_368 . V_324 = V_367 -> V_369 [ V_3 ] . V_324 ;
V_368 . V_347 = V_367 -> V_369 [ V_3 ] . V_347 ;
V_57 = F_144 ( V_6 , V_7 , & V_368 ) ;
V_367 -> V_369 [ V_3 ] . V_347 = V_368 . V_347 ;
if ( V_57 ) {
V_367 -> V_384 = V_3 ;
break;
}
}
return V_57 ;
}
static int F_155 ( struct V_6 * V_6 , void * V_7 ,
struct V_389 * V_390 )
{
struct V_24 * V_25 = F_7 ( V_6 ) ;
struct V_40 * V_41 = F_14 ( V_25 ) -> V_41 ;
struct V_26 * V_27 = F_8 ( V_25 ) ;
if ( V_390 -> type != V_248 ) {
F_19 ( V_27 -> V_59 , L_48 ) ;
return - V_30 ;
}
F_15 ( & V_27 -> V_54 ) ;
V_390 -> V_390 . V_391 . V_392 = V_41 -> V_202 -> V_168 ;
F_16 ( & V_27 -> V_54 ) ;
return 0 ;
}
static int F_156 ( struct V_6 * V_6 , void * V_7 ,
struct V_389 * V_390 )
{
struct V_24 * V_25 = F_7 ( V_6 ) ;
struct V_26 * V_27 = F_8 ( V_25 ) ;
struct V_40 * V_41 = F_14 ( V_25 ) -> V_41 ;
int V_393 ;
int V_76 ;
int V_394 ;
if ( V_390 -> type != V_248 ) {
F_19 ( V_27 -> V_59 , L_48 ) ;
return - V_30 ;
}
F_15 ( & V_27 -> V_54 ) ;
V_41 -> V_216 = false ;
switch ( V_390 -> V_390 . V_391 . V_392 ) {
case V_395 : {
struct V_396 V_75 = { 0 } ;
V_75 . V_397 = V_390 -> V_390 . V_391 . V_398 ;
V_76 = F_20 ( V_27 -> V_31 [ V_41 -> V_55 ] . V_32 ,
V_64 , V_399 , & V_75 ) ;
if ( ! V_76 )
V_390 -> V_390 . V_391 . V_398 = V_75 . V_397 ;
if ( V_75 . V_397 . V_400 != 0 ) {
V_394 = V_75 . V_397 . V_401 / V_75 . V_397 . V_400 ;
if ( V_394 > 30 )
V_41 -> V_216 = true ;
}
goto V_249;
}
case V_402 :
V_393 = V_203 ;
break;
case V_403 :
V_393 = V_211 ;
break;
case V_404 :
V_393 = V_405 ;
break;
case V_406 :
V_393 = V_210 ;
break;
default:
V_76 = - V_30 ;
goto V_249;
}
V_76 = F_153 ( V_41 -> V_202 , V_393 ) ;
V_249:
F_16 ( & V_27 -> V_54 ) ;
return V_76 == - V_67 ? 0 : V_76 ;
}
static int F_157 ( struct V_6 * V_6 , void * V_7 ,
struct V_389 * V_390 )
{
struct V_24 * V_25 = F_7 ( V_6 ) ;
struct V_26 * V_27 = F_8 ( V_25 ) ;
if ( V_390 -> type != V_191 ) {
F_19 ( V_27 -> V_59 , L_49 ) ;
return - V_30 ;
}
F_15 ( & V_27 -> V_54 ) ;
V_27 -> V_68 . V_69 = 1 ;
F_16 ( & V_27 -> V_54 ) ;
return 0 ;
}
static long F_158 ( struct V_6 * V_6 , void * V_7 ,
bool V_407 , unsigned int V_408 , void * V_409 )
{
struct V_24 * V_25 = F_7 ( V_6 ) ;
struct V_26 * V_27 = F_8 ( V_25 ) ;
struct V_40 * V_41 ;
bool V_410 ;
int V_411 ;
V_410 = ! strncmp ( V_25 -> V_33 , L_50 ,
sizeof( V_25 -> V_33 ) ) ;
if ( V_410 )
V_41 = F_159 ( V_25 ) -> V_41 ;
else
V_41 = F_14 ( V_25 ) -> V_41 ;
switch ( V_408 ) {
case V_412 :
case V_413 :
case V_414 :
case V_415 :
case V_416 :
case V_417 :
case V_418 :
case V_419 :
case V_420 :
case V_421 :
#ifdef F_9
case V_422 :
#endif
break;
default:
F_15 ( & V_27 -> V_54 ) ;
break;
}
switch ( V_408 ) {
#ifdef F_9
case V_423 :
V_411 = F_160 ( V_41 , V_409 ) ;
break;
#endif
case V_424 :
V_411 = F_161 ( V_41 , 0 , V_409 ) ;
break;
case V_425 :
V_411 = F_161 ( V_41 , 1 , V_409 ) ;
break;
case V_426 :
V_411 = F_162 ( V_41 , 0 , V_409 ) ;
break;
case V_427 :
V_411 = F_162 ( V_41 , 1 , V_409 ) ;
break;
case V_428 :
V_411 = F_163 ( V_41 , 0 , V_409 ) ;
break;
case V_429 :
V_411 = F_163 ( V_41 , 1 , V_409 ) ;
break;
case V_430 :
V_411 = F_164 ( V_41 , 0 , V_409 ) ;
break;
case V_431 :
V_411 = F_164 ( V_41 , 1 , V_409 ) ;
break;
case V_432 :
V_411 = F_165 ( V_41 , 0 , V_409 ) ;
break;
case V_433 :
V_411 = F_165 ( V_41 , 1 , V_409 ) ;
break;
case V_434 :
V_411 = F_166 ( V_41 , V_409 ) ;
break;
case V_435 :
V_411 = F_167 ( V_41 , V_409 ) ;
break;
case V_436 :
V_411 = F_168 ( V_41 , V_409 ,
& V_41 -> V_113 . V_262 , true ) ;
if ( ! V_411 && V_409 )
V_41 -> V_113 . V_261 = true ;
break;
case V_437 :
V_411 = F_169 ( V_41 , V_409 ,
& V_41 -> V_113 . V_262 , true ) ;
if ( ! V_411 && V_409 )
V_41 -> V_113 . V_261 = true ;
break;
case V_438 :
V_411 = F_170 ( V_41 , 0 , V_409 ) ;
break;
case V_439 :
V_411 = F_170 ( V_41 , 1 , V_409 ) ;
break;
case V_440 :
V_411 = F_171 ( V_41 , 0 , V_409 ) ;
break;
case V_441 :
V_411 = F_172 ( V_41 , 0 , V_409 ) ;
break;
case V_442 :
V_411 = F_172 ( V_41 , 1 , V_409 ) ;
break;
case V_443 :
V_411 = F_173 ( V_41 , 0 , V_409 ) ;
break;
case V_444 :
V_411 = F_173 ( V_41 , 1 , V_409 ) ;
break;
case V_445 :
V_411 = F_174 ( V_41 , 0 , V_409 ) ;
break;
case V_446 :
V_411 = F_174 ( V_41 , 1 , V_409 ) ;
break;
case V_447 :
V_411 = F_175 ( V_41 , 0 , V_409 ) ;
break;
case V_448 :
V_411 = F_175 ( V_41 , 1 , V_409 ) ;
break;
case V_449 :
V_411 = F_176 ( V_41 , 0 , V_409 ) ;
break;
case V_450 :
V_411 = F_176 ( V_41 , 1 , V_409 ) ;
break;
case V_451 :
V_411 = F_177 ( V_41 , 0 , V_409 ) ;
break;
case V_452 :
V_411 = F_177 ( V_41 , 1 , V_409 ) ;
break;
case V_453 :
V_411 = F_178 ( V_41 , 0 , V_409 ) ;
break;
case V_454 :
V_411 = F_178 ( V_41 , 1 , V_409 ) ;
break;
case V_455 :
V_411 = F_179 ( V_41 , 0 , V_409 ) ;
break;
case V_456 :
V_411 = F_179 ( V_41 , 1 , V_409 ) ;
break;
case V_457 :
V_411 = F_180 ( V_41 , V_409 ) ;
break;
case V_458 :
V_411 = F_181 ( V_41 , V_409 ) ;
break;
case V_459 :
V_411 = F_182 ( V_41 , V_409 ) ;
break;
case V_412 :
#ifndef F_9
if ( V_27 -> V_31 [ V_41 -> V_55 ] . V_34 )
#else
if ( V_27 -> V_34 )
#endif
V_411 = F_20 (
#ifndef F_9
V_27 -> V_31 [ V_41 -> V_55 ] . V_34 ,
#else
V_27 -> V_34 ,
#endif
V_62 , V_227 , V_408 , V_409 ) ;
else
V_411 = F_20 (
V_27 -> V_31 [ V_41 -> V_55 ] . V_32 ,
V_62 , V_227 , V_408 , V_409 ) ;
break;
case V_413 :
case V_414 :
case V_415 :
case V_417 :
case V_418 :
case V_419 :
case V_420 :
#ifdef F_9
case V_422 :
#endif
V_411 = F_20 ( V_27 -> V_31 [ V_41 -> V_55 ] . V_32 ,
V_62 , V_227 , V_408 , V_409 ) ;
break;
case V_460 :
V_411 = F_183 ( V_41 , V_409 ) ;
break;
case V_461 :
V_411 = F_184 ( V_41 , V_409 ) ;
break;
case V_462 :
V_411 = F_185 ( V_41 , V_409 ) ;
break;
case V_463 :
V_411 = F_186 ( V_41 , V_409 ) ;
break;
case V_464 :
V_411 = F_187 ( V_41 , V_409 ) ;
break;
case V_465 :
V_411 = F_188 ( V_41 , V_409 ) ;
break;
case V_466 :
V_411 = F_189 ( V_41 , V_409 ) ;
break;
case V_467 :
V_411 = F_190 ( V_41 , V_409 ) ;
break;
case V_468 :
V_411 = F_191 ( V_41 , V_409 ) ;
break;
case V_469 :
V_411 = F_192 ( V_41 , 0 , V_409 ) ;
break;
case V_470 :
V_411 = F_192 ( V_41 , 1 , V_409 ) ;
break;
case V_471 :
V_411 = F_193 ( V_25 , V_409 ) ;
break;
case V_472 :
V_411 = F_194 ( V_41 , V_409 ) ;
break;
case V_473 :
V_411 = F_195 ( V_41 , 0 , V_409 ) ;
break;
case V_474 :
V_411 = F_196 ( V_41 , 0 , V_409 ) ;
break;
case V_416 :
V_411 = F_20 ( V_27 -> V_31 [ V_41 -> V_55 ] . V_32 ,
V_62 , V_227 , V_408 , V_409 ) ;
break;
case V_475 :
V_411 = F_197 ( V_41 , V_409 ) ;
break;
case V_476 :
V_411 = F_198 ( V_41 , V_409 ) ;
break;
case V_477 :
V_411 = F_199 ( V_41 , V_409 ) ;
break;
case V_478 :
V_411 = F_200 ( V_41 , 0 , V_409 ) ;
break;
case V_479 :
V_411 = F_200 ( V_41 , 1 , V_409 ) ;
break;
case V_480 :
V_411 = F_201 ( V_41 , V_409 ) ;
break;
case V_481 :
V_411 = F_202 ( V_41 , V_409 ) ;
break;
case V_482 :
V_411 = F_203 ( V_41 , V_409 ) ;
break;
case V_483 :
V_411 = F_204 ( V_41 , V_409 ) ;
break;
case V_484 :
V_411 = F_205 ( V_25 , V_409 ) ;
break;
case V_485 :
V_411 = F_206 ( V_41 , V_409 ) ;
break;
default:
V_411 = - V_30 ;
break;
}
switch ( V_408 ) {
case V_412 :
case V_413 :
case V_414 :
case V_415 :
case V_416 :
case V_417 :
case V_418 :
case V_419 :
case V_420 :
#ifdef F_9
case V_422 :
#endif
break;
default:
F_16 ( & V_27 -> V_54 ) ;
break;
}
return V_411 ;
}
