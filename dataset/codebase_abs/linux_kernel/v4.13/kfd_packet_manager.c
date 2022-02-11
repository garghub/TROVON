static inline void F_1 ( unsigned int * V_1 , unsigned int V_2 ,
unsigned int V_3 )
{
unsigned int V_4 = * V_1 + V_2 / sizeof( V_5 ) ;
F_2 ( ( V_4 * sizeof( V_5 ) ) > V_3 ) ;
* V_1 = V_4 ;
}
static unsigned int F_3 ( unsigned int V_6 , T_1 V_7 )
{
union V_8 V_9 ;
V_9 . V_10 = 0 ;
V_9 . V_6 = V_6 ;
V_9 . V_11 = V_7 / sizeof( V_5 ) - 2 ;
V_9 . type = V_12 ;
return V_9 . V_10 ;
}
static void F_4 ( struct V_13 * V_14 ,
unsigned int * V_15 ,
bool * V_16 )
{
unsigned int V_17 , V_18 ;
unsigned int V_19 ;
F_2 ( ! V_14 || ! V_15 || ! V_16 ) ;
V_17 = V_14 -> V_20 -> V_21 ;
V_18 = V_14 -> V_20 -> V_18 ;
* V_16 = false ;
if ( ( V_17 > 1 ) || V_18 > F_5 ( V_14 -> V_20 ) ) {
* V_16 = true ;
F_6 ( L_1 ) ;
}
V_19 =
( V_14 -> V_20 -> V_22 -> V_23 -> V_24 == V_25 ) ?
sizeof( struct V_26 ) :
sizeof( struct V_27 ) ;
* V_15 = V_17 * sizeof( struct V_28 ) +
V_18 * V_19 ;
if ( * V_16 )
* V_15 += sizeof( struct V_29 ) ;
F_6 ( L_2 , * V_15 ) ;
}
static int F_7 ( struct V_13 * V_14 ,
unsigned int * * V_30 ,
T_2 * V_31 ,
unsigned int * V_32 ,
bool * V_33 )
{
int V_34 ;
F_2 ( ! V_14 ) ;
F_2 ( V_14 -> V_35 ) ;
F_2 ( V_33 == NULL ) ;
F_4 ( V_14 , V_32 , V_33 ) ;
V_34 = F_8 ( V_14 -> V_20 -> V_22 , * V_32 ,
& V_14 -> V_36 ) ;
if ( V_34 != 0 ) {
F_9 ( L_3 ) ;
return V_34 ;
}
* ( void * * ) V_30 = V_14 -> V_36 -> V_37 ;
* V_31 = V_14 -> V_36 -> V_38 ;
memset ( * V_30 , 0 , * V_32 ) ;
V_14 -> V_35 = true ;
return V_34 ;
}
static int F_10 ( struct V_13 * V_14 , V_5 * V_39 ,
T_2 V_40 , T_1 V_41 , bool V_42 )
{
struct V_29 * V_43 ;
F_2 ( ! V_14 || ! V_39 || ! V_40 ) ;
V_43 = (struct V_29 * ) V_39 ;
memset ( V_39 , 0 , sizeof( struct V_29 ) ) ;
V_43 -> V_9 . V_10 = F_3 ( V_44 ,
sizeof( struct V_29 ) ) ;
V_43 -> V_45 . V_46 = V_41 ;
V_43 -> V_45 . V_42 = V_42 ? 1 : 0 ;
V_43 -> V_45 . V_47 = 0 ;
V_43 -> V_45 . V_48 = 1 ;
V_43 -> V_49 = F_11 ( V_40 ) ;
V_43 -> V_50 . V_51 = F_12 ( V_40 ) ;
return 0 ;
}
static int F_13 ( struct V_13 * V_14 , V_5 * V_39 ,
struct V_52 * V_53 )
{
struct V_28 * V_43 ;
struct V_54 * V_55 ;
V_5 V_56 ;
F_2 ( ! V_14 || ! V_39 || ! V_53 ) ;
V_43 = (struct V_28 * ) V_39 ;
F_6 ( L_4 , V_57 ) ;
memset ( V_39 , 0 , sizeof( struct V_28 ) ) ;
V_43 -> V_9 . V_10 = F_3 ( V_58 ,
sizeof( struct V_28 ) ) ;
V_43 -> V_59 . V_60 = ( V_53 -> V_61 ) ? 1 : 0 ;
V_43 -> V_59 . V_62 = 1 ;
V_43 -> V_59 . V_63 = V_53 -> V_64 -> V_65 -> V_63 ;
V_43 -> V_50 . V_66 = V_53 -> V_66 ;
V_43 -> V_67 . V_68 = V_53 -> V_68 ;
V_43 -> V_67 . V_69 = V_53 -> V_69 ;
V_43 -> V_67 . V_70 = V_53 -> V_70 ;
V_56 = 0 ;
F_14 (cur, &qpd->queues_list, list)
V_56 ++ ;
V_43 -> V_67 . V_56 = ( V_53 -> V_61 ) ? 0 : V_56 ;
V_43 -> V_71 = V_53 -> V_71 ;
V_43 -> V_72 = V_53 -> V_72 ;
V_43 -> V_73 = V_53 -> V_73 ;
V_43 -> V_74 = V_53 -> V_74 ;
V_43 -> V_75 = F_11 ( V_53 -> V_76 ) ;
V_43 -> V_77 = F_12 ( V_53 -> V_76 ) ;
return 0 ;
}
static int F_15 ( struct V_13 * V_14 , V_5 * V_39 ,
struct V_54 * V_78 , bool V_79 )
{
struct V_26 * V_43 ;
bool V_80 = V_79 ;
F_2 ( ! V_14 || ! V_39 || ! V_78 ) ;
F_6 ( L_4 , V_57 ) ;
V_43 = (struct V_26 * ) V_39 ;
memset ( V_39 , 0 , sizeof( struct V_27 ) ) ;
V_43 -> V_9 . V_10 = F_3 ( V_81 ,
sizeof( struct V_27 ) ) ;
V_43 -> V_59 . V_82 =
V_83 ;
V_43 -> V_59 . V_56 = 1 ;
V_43 -> V_59 . V_84 =
V_85 ;
V_43 -> V_59 . V_86 =
V_87 ;
V_43 -> V_59 . V_88 =
V_89 ;
switch ( V_78 -> V_90 . type ) {
case V_91 :
if ( V_80 )
V_43 -> V_59 . V_88 =
V_92 ;
break;
case V_93 :
V_43 -> V_59 . V_88 =
V_94 ;
break;
case V_95 :
V_43 -> V_59 . V_86 =
V_96 ;
V_80 = false ;
break;
default:
F_9 ( L_5 , V_57 ,
V_78 -> V_90 . type ) ;
F_16 () ;
break;
}
V_43 -> V_50 . V_97 =
V_78 -> V_90 . V_98 ;
V_43 -> V_99 =
F_11 ( V_78 -> V_100 ) ;
V_43 -> V_101 =
F_12 ( V_78 -> V_100 ) ;
V_43 -> V_102 =
F_11 ( ( T_2 ) V_78 -> V_90 . V_103 ) ;
V_43 -> V_104 =
F_12 ( ( T_2 ) V_78 -> V_90 . V_103 ) ;
return 0 ;
}
static int F_17 ( struct V_13 * V_14 , V_5 * V_39 ,
struct V_54 * V_78 , bool V_79 )
{
struct V_27 * V_43 ;
bool V_80 = V_79 ;
F_2 ( ! V_14 || ! V_39 || ! V_78 ) ;
F_6 ( L_4 , V_57 ) ;
V_43 = (struct V_27 * ) V_39 ;
memset ( V_39 , 0 , sizeof( struct V_27 ) ) ;
V_43 -> V_9 . V_10 = F_3 ( V_81 ,
sizeof( struct V_27 ) ) ;
V_43 -> V_59 . V_82 =
V_105 ;
V_43 -> V_59 . V_56 = 1 ;
V_43 -> V_59 . V_84 =
V_106 ;
V_43 -> V_59 . V_107 = ( V_78 -> V_90 . V_108 ) ?
V_109 :
V_110 ;
switch ( V_78 -> V_90 . type ) {
case V_91 :
case V_93 :
V_43 -> V_59 . V_86 =
V_111 ;
break;
case V_95 :
V_43 -> V_59 . V_86 =
V_112 ;
V_80 = false ;
break;
default:
F_16 () ;
break;
}
V_43 -> V_113 [ 0 ] . V_50 . V_97 =
V_78 -> V_90 . V_98 ;
V_43 -> V_113 [ 0 ] . V_50 . V_79 =
( V_80 ) ? 1 : 0 ;
V_43 -> V_113 [ 0 ] . V_99 =
F_11 ( V_78 -> V_100 ) ;
V_43 -> V_113 [ 0 ] . V_101 =
F_12 ( V_78 -> V_100 ) ;
V_43 -> V_113 [ 0 ] . V_102 =
F_11 ( ( T_2 ) V_78 -> V_90 . V_103 ) ;
V_43 -> V_113 [ 0 ] . V_104 =
F_12 ( ( T_2 ) V_78 -> V_90 . V_103 ) ;
return 0 ;
}
static int F_18 ( struct V_13 * V_14 ,
struct V_114 * V_115 ,
T_2 * V_116 ,
T_1 * V_117 )
{
unsigned int V_118 ;
unsigned int * V_30 , V_119 , V_120 ;
int V_34 , V_121 ;
struct V_122 * V_55 ;
struct V_52 * V_53 ;
struct V_54 * V_78 ;
struct V_123 * V_124 ;
bool V_33 ;
F_2 ( ! V_14 || ! V_115 || ! V_117 || ! V_116 ) ;
V_119 = V_34 = V_121 = 0 ;
V_34 = F_7 ( V_14 , & V_30 , V_116 ,
& V_118 , & V_33 ) ;
if ( V_34 != 0 )
return V_34 ;
* V_117 = V_118 ;
F_6 ( L_4 , V_57 ) ;
F_6 ( L_6 ,
V_14 -> V_20 -> V_21 , V_14 -> V_20 -> V_18 ) ;
F_14 (cur, queues, list) {
V_53 = V_55 -> V_53 ;
if ( V_121 >= V_14 -> V_20 -> V_21 ) {
F_6 ( L_7 ) ;
F_19 ( V_14 ) ;
return - V_125 ;
}
V_34 = F_13 ( V_14 , & V_30 [ V_119 ] , V_53 ) ;
if ( V_34 != 0 )
return V_34 ;
V_121 ++ ;
F_1 ( & V_119 , sizeof( struct V_28 ) ,
V_118 ) ;
F_14 (kq, &qpd->priv_queue_list, list) {
if ( ! V_124 -> V_54 -> V_90 . V_126 )
continue;
F_6 ( L_8 ,
V_124 -> V_54 -> V_54 , V_53 -> V_61 ) ;
if ( V_14 -> V_20 -> V_22 -> V_23 -> V_24 ==
V_25 )
V_34 = F_15 ( V_14 ,
& V_30 [ V_119 ] ,
V_124 -> V_54 ,
V_53 -> V_61 ) ;
else
V_34 = F_17 ( V_14 ,
& V_30 [ V_119 ] ,
V_124 -> V_54 ,
V_53 -> V_61 ) ;
if ( V_34 != 0 )
return V_34 ;
F_1 ( & V_119 ,
sizeof( struct V_27 ) ,
V_118 ) ;
}
F_14 (q, &qpd->queues_list, list) {
if ( ! V_78 -> V_90 . V_126 )
continue;
F_6 ( L_9 ,
V_78 -> V_54 , V_53 -> V_61 ) ;
if ( V_14 -> V_20 -> V_22 -> V_23 -> V_24 ==
V_25 )
V_34 = F_15 ( V_14 ,
& V_30 [ V_119 ] ,
V_78 ,
V_53 -> V_61 ) ;
else
V_34 = F_17 ( V_14 ,
& V_30 [ V_119 ] ,
V_78 ,
V_53 -> V_61 ) ;
if ( V_34 != 0 )
return V_34 ;
F_1 ( & V_119 ,
sizeof( struct V_27 ) ,
V_118 ) ;
}
}
F_6 ( L_10 ) ;
if ( V_33 )
F_10 ( V_14 , & V_30 [ V_119 ] , * V_116 ,
V_118 / sizeof( V_5 ) , true ) ;
for ( V_120 = 0 ; V_120 < V_118 / sizeof( V_5 ) ; V_120 ++ )
F_6 ( L_11 , V_30 [ V_120 ] ) ;
F_6 ( L_12 ) ;
return 0 ;
}
int F_20 ( struct V_13 * V_14 , struct V_127 * V_20 )
{
F_2 ( ! V_20 ) ;
V_14 -> V_20 = V_20 ;
F_21 ( & V_14 -> V_128 ) ;
V_14 -> V_129 = F_22 ( V_20 -> V_22 , V_130 ) ;
if ( V_14 -> V_129 == NULL ) {
F_23 ( & V_14 -> V_128 ) ;
return - V_125 ;
}
V_14 -> V_35 = false ;
return 0 ;
}
void F_24 ( struct V_13 * V_14 )
{
F_2 ( ! V_14 ) ;
F_23 ( & V_14 -> V_128 ) ;
F_25 ( V_14 -> V_129 ) ;
}
int F_26 ( struct V_13 * V_14 ,
struct V_131 * V_132 )
{
struct V_133 * V_43 ;
F_2 ( ! V_14 || ! V_132 ) ;
F_6 ( L_4 , V_57 ) ;
F_27 ( & V_14 -> V_128 ) ;
V_14 -> V_129 -> V_134 . V_135 ( V_14 -> V_129 ,
sizeof( * V_43 ) / sizeof( V_5 ) ,
( unsigned int * * ) & V_43 ) ;
if ( V_43 == NULL ) {
F_28 ( & V_14 -> V_128 ) ;
F_9 ( L_13 ) ;
return - V_125 ;
}
memset ( V_43 , 0 , sizeof( struct V_133 ) ) ;
V_43 -> V_9 . V_10 = F_3 ( V_136 ,
sizeof( struct V_133 ) ) ;
V_43 -> V_59 . V_88 =
V_137 ;
V_43 -> V_59 . V_138 = V_132 -> V_138 ;
V_43 -> V_59 . V_139 = V_140 ;
V_43 -> V_141 . V_142 = V_132 -> V_142 ;
V_43 -> V_143 . V_144 = V_132 -> V_144 ;
V_43 -> V_143 . V_145 = V_132 -> V_145 ;
V_43 -> V_146 = F_11 ( V_132 -> V_147 ) ;
V_43 -> V_148 = F_12 ( V_132 -> V_147 ) ;
V_43 -> V_149 = F_11 ( V_132 -> V_150 ) ;
V_43 -> V_151 = F_12 ( V_132 -> V_150 ) ;
V_14 -> V_129 -> V_134 . V_152 ( V_14 -> V_129 ) ;
F_28 ( & V_14 -> V_128 ) ;
return 0 ;
}
int F_29 ( struct V_13 * V_14 , struct V_114 * V_153 )
{
T_2 V_154 ;
V_5 * V_30 ;
T_1 V_155 , V_156 ;
int V_34 ;
F_2 ( ! V_14 || ! V_153 ) ;
V_34 = F_18 ( V_14 , V_153 , & V_154 ,
& V_155 ) ;
if ( V_34 != 0 )
goto V_157;
F_6 ( L_14 , V_154 ) ;
V_156 = sizeof( struct V_29 ) / sizeof( V_5 ) ;
F_27 ( & V_14 -> V_128 ) ;
V_34 = V_14 -> V_129 -> V_134 . V_135 ( V_14 -> V_129 ,
V_156 , & V_30 ) ;
if ( V_34 != 0 )
goto V_158;
V_34 = F_10 ( V_14 , V_30 , V_154 ,
V_155 / sizeof( V_5 ) , false ) ;
if ( V_34 != 0 )
goto V_159;
V_14 -> V_129 -> V_134 . V_152 ( V_14 -> V_129 ) ;
F_28 ( & V_14 -> V_128 ) ;
return V_34 ;
V_159:
V_14 -> V_129 -> V_134 . V_160 ( V_14 -> V_129 ) ;
V_158:
F_28 ( & V_14 -> V_128 ) ;
V_157:
if ( V_14 -> V_35 )
F_19 ( V_14 ) ;
return V_34 ;
}
int F_30 ( struct V_13 * V_14 , T_2 V_161 ,
V_5 V_162 )
{
int V_34 ;
struct V_163 * V_43 ;
F_2 ( ! V_14 || ! V_161 ) ;
F_27 ( & V_14 -> V_128 ) ;
V_34 = V_14 -> V_129 -> V_134 . V_135 (
V_14 -> V_129 ,
sizeof( struct V_163 ) / sizeof( V_5 ) ,
( unsigned int * * ) & V_43 ) ;
if ( V_34 != 0 )
goto V_158;
V_43 -> V_9 . V_10 = F_3 ( V_164 ,
sizeof( struct V_163 ) ) ;
V_43 -> V_59 . V_165 = 0 ;
V_43 -> V_59 . V_166 =
V_167 ;
V_43 -> V_59 . V_168 =
V_169 ;
V_43 -> V_170 = F_12 ( ( T_2 ) V_161 ) ;
V_43 -> V_171 = F_11 ( ( T_2 ) V_161 ) ;
V_43 -> V_172 = F_12 ( ( T_2 ) V_162 ) ;
V_43 -> V_173 = F_11 ( ( T_2 ) V_162 ) ;
V_14 -> V_129 -> V_134 . V_152 ( V_14 -> V_129 ) ;
F_28 ( & V_14 -> V_128 ) ;
return 0 ;
V_158:
F_28 ( & V_14 -> V_128 ) ;
return V_34 ;
}
int F_31 ( struct V_13 * V_14 , enum V_174 type ,
enum V_175 V_176 ,
V_5 V_177 , bool V_178 ,
unsigned int V_179 )
{
int V_34 ;
V_5 * V_39 ;
struct V_180 * V_43 ;
F_2 ( ! V_14 ) ;
F_27 ( & V_14 -> V_128 ) ;
V_34 = V_14 -> V_129 -> V_134 . V_135 (
V_14 -> V_129 ,
sizeof( struct V_180 ) / sizeof( V_5 ) ,
& V_39 ) ;
if ( V_34 != 0 )
goto V_181;
V_43 = (struct V_180 * ) V_39 ;
memset ( V_39 , 0 , sizeof( struct V_180 ) ) ;
F_6 ( L_15 ,
V_176 , V_178 , type ) ;
V_43 -> V_9 . V_10 = F_3 ( V_182 ,
sizeof( struct V_180 ) ) ;
switch ( type ) {
case V_91 :
case V_93 :
V_43 -> V_59 . V_86 =
V_183 ;
break;
case V_95 :
V_43 -> V_59 . V_86 =
V_184 + V_179 ;
break;
default:
F_16 () ;
break;
}
if ( V_178 )
V_43 -> V_59 . V_185 =
V_186 ;
else
V_43 -> V_59 . V_185 =
V_187 ;
switch ( V_176 ) {
case V_188 :
V_43 -> V_59 . V_84 =
V_189 ;
V_43 -> V_59 . V_56 = 1 ;
V_43 -> V_190 . V_191 = V_177 ;
break;
case V_192 :
V_43 -> V_59 . V_84 =
V_193 ;
V_43 -> V_194 . V_63 = V_177 ;
break;
case V_195 :
V_43 -> V_59 . V_84 =
V_196 ;
break;
case V_197 :
V_43 -> V_59 . V_84 =
V_198 ;
break;
default:
F_16 () ;
break;
}
V_14 -> V_129 -> V_134 . V_152 ( V_14 -> V_129 ) ;
F_28 ( & V_14 -> V_128 ) ;
return 0 ;
V_181:
F_28 ( & V_14 -> V_128 ) ;
return V_34 ;
}
void F_19 ( struct V_13 * V_14 )
{
F_2 ( ! V_14 ) ;
F_27 ( & V_14 -> V_128 ) ;
if ( V_14 -> V_35 ) {
F_32 ( V_14 -> V_20 -> V_22 , V_14 -> V_36 ) ;
V_14 -> V_35 = false ;
}
F_28 ( & V_14 -> V_128 ) ;
}
