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
if ( ( V_17 > 1 ) ||
V_18 > V_22 * V_23 ) {
* V_16 = true ;
F_5 ( L_1 ) ;
}
V_19 =
( V_14 -> V_20 -> V_24 -> V_25 -> V_26 == V_27 ) ?
sizeof( struct V_28 ) :
sizeof( struct V_29 ) ;
* V_15 = V_17 * sizeof( struct V_30 ) +
V_18 * V_19 ;
if ( * V_16 )
* V_15 += sizeof( struct V_31 ) ;
F_5 ( L_2 , * V_15 ) ;
}
static int F_6 ( struct V_13 * V_14 ,
unsigned int * * V_32 ,
T_2 * V_33 ,
unsigned int * V_34 ,
bool * V_35 )
{
int V_36 ;
F_2 ( ! V_14 ) ;
F_2 ( V_14 -> V_37 == true ) ;
F_2 ( V_35 == NULL ) ;
F_4 ( V_14 , V_34 , V_35 ) ;
V_36 = F_7 ( V_14 -> V_20 -> V_24 , * V_34 ,
& V_14 -> V_38 ) ;
if ( V_36 != 0 ) {
F_8 ( L_3 ) ;
return V_36 ;
}
* ( void * * ) V_32 = V_14 -> V_38 -> V_39 ;
* V_33 = V_14 -> V_38 -> V_40 ;
memset ( * V_32 , 0 , * V_34 ) ;
V_14 -> V_37 = true ;
return V_36 ;
}
static int F_9 ( struct V_13 * V_14 , V_5 * V_41 ,
T_2 V_42 , T_1 V_43 , bool V_44 )
{
struct V_31 * V_45 ;
F_2 ( ! V_14 || ! V_41 || ! V_42 ) ;
V_45 = (struct V_31 * ) V_41 ;
memset ( V_41 , 0 , sizeof( struct V_31 ) ) ;
V_45 -> V_9 . V_10 = F_3 ( V_46 ,
sizeof( struct V_31 ) ) ;
V_45 -> V_47 . V_48 = V_43 ;
V_45 -> V_47 . V_44 = V_44 ? 1 : 0 ;
V_45 -> V_47 . V_49 = 0 ;
V_45 -> V_47 . V_50 = 1 ;
V_45 -> V_51 = F_10 ( V_42 ) ;
V_45 -> V_52 . V_53 = F_11 ( V_42 ) ;
return 0 ;
}
static int F_12 ( struct V_13 * V_14 , V_5 * V_41 ,
struct V_54 * V_55 )
{
struct V_30 * V_45 ;
struct V_56 * V_57 ;
V_5 V_58 ;
F_2 ( ! V_14 || ! V_41 || ! V_55 ) ;
V_45 = (struct V_30 * ) V_41 ;
F_5 ( L_4 , V_59 ) ;
memset ( V_41 , 0 , sizeof( struct V_30 ) ) ;
V_45 -> V_9 . V_10 = F_3 ( V_60 ,
sizeof( struct V_30 ) ) ;
V_45 -> V_61 . V_62 = ( V_55 -> V_63 ) ? 1 : 0 ;
V_45 -> V_61 . V_64 = 1 ;
V_45 -> V_61 . V_65 = V_55 -> V_66 -> V_67 -> V_65 ;
V_45 -> V_52 . V_68 = V_55 -> V_68 ;
V_45 -> V_69 . V_70 = V_55 -> V_70 ;
V_45 -> V_69 . V_71 = V_55 -> V_71 ;
V_45 -> V_69 . V_72 = V_55 -> V_72 ;
V_58 = 0 ;
F_13 (cur, &qpd->queues_list, list)
V_58 ++ ;
V_45 -> V_69 . V_58 = ( V_55 -> V_63 ) ? 0 : V_58 ;
V_45 -> V_73 = V_55 -> V_73 ;
V_45 -> V_74 = V_55 -> V_74 ;
V_45 -> V_75 = V_55 -> V_75 ;
V_45 -> V_76 = V_55 -> V_76 ;
V_45 -> V_77 = F_10 ( V_55 -> V_78 ) ;
V_45 -> V_79 = F_11 ( V_55 -> V_78 ) ;
return 0 ;
}
static int F_14 ( struct V_13 * V_14 , V_5 * V_41 ,
struct V_56 * V_80 , bool V_81 )
{
struct V_28 * V_45 ;
bool V_82 = V_81 ;
F_2 ( ! V_14 || ! V_41 || ! V_80 ) ;
F_5 ( L_4 , V_59 ) ;
V_45 = (struct V_28 * ) V_41 ;
memset ( V_41 , 0 , sizeof( struct V_29 ) ) ;
V_45 -> V_9 . V_10 = F_3 ( V_83 ,
sizeof( struct V_29 ) ) ;
V_45 -> V_61 . V_84 =
V_85 ;
V_45 -> V_61 . V_58 = 1 ;
V_45 -> V_61 . V_86 =
V_87 ;
V_45 -> V_61 . V_88 =
V_89 ;
V_45 -> V_61 . V_90 =
V_91 ;
switch ( V_80 -> V_92 . type ) {
case V_93 :
if ( V_82 )
V_45 -> V_61 . V_90 =
V_94 ;
break;
case V_95 :
V_45 -> V_61 . V_90 =
V_96 ;
break;
case V_97 :
V_45 -> V_61 . V_88 =
V_98 ;
V_82 = false ;
break;
default:
F_8 ( L_5 , V_59 ,
V_80 -> V_92 . type ) ;
F_15 () ;
break;
}
V_45 -> V_52 . V_99 =
V_80 -> V_92 . V_100 ;
V_45 -> V_101 =
F_10 ( V_80 -> V_102 ) ;
V_45 -> V_103 =
F_11 ( V_80 -> V_102 ) ;
V_45 -> V_104 =
F_10 ( ( T_2 ) V_80 -> V_92 . V_105 ) ;
V_45 -> V_106 =
F_11 ( ( T_2 ) V_80 -> V_92 . V_105 ) ;
return 0 ;
}
static int F_16 ( struct V_13 * V_14 , V_5 * V_41 ,
struct V_56 * V_80 , bool V_81 )
{
struct V_29 * V_45 ;
bool V_82 = V_81 ;
F_2 ( ! V_14 || ! V_41 || ! V_80 ) ;
F_5 ( L_4 , V_59 ) ;
V_45 = (struct V_29 * ) V_41 ;
memset ( V_41 , 0 , sizeof( struct V_29 ) ) ;
V_45 -> V_9 . V_10 = F_3 ( V_83 ,
sizeof( struct V_29 ) ) ;
V_45 -> V_61 . V_84 =
V_107 ;
V_45 -> V_61 . V_58 = 1 ;
V_45 -> V_61 . V_86 =
V_108 ;
V_45 -> V_61 . V_109 = ( V_80 -> V_92 . V_110 ) ?
V_111 :
V_112 ;
switch ( V_80 -> V_92 . type ) {
case V_93 :
case V_95 :
V_45 -> V_61 . V_88 =
V_113 ;
break;
case V_97 :
V_45 -> V_61 . V_88 =
V_114 ;
V_82 = false ;
break;
default:
F_15 () ;
break;
}
V_45 -> V_115 [ 0 ] . V_52 . V_99 =
V_80 -> V_92 . V_100 ;
V_45 -> V_115 [ 0 ] . V_52 . V_81 =
( V_82 == true ) ? 1 : 0 ;
V_45 -> V_115 [ 0 ] . V_101 =
F_10 ( V_80 -> V_102 ) ;
V_45 -> V_115 [ 0 ] . V_103 =
F_11 ( V_80 -> V_102 ) ;
V_45 -> V_115 [ 0 ] . V_104 =
F_10 ( ( T_2 ) V_80 -> V_92 . V_105 ) ;
V_45 -> V_115 [ 0 ] . V_106 =
F_11 ( ( T_2 ) V_80 -> V_92 . V_105 ) ;
return 0 ;
}
static int F_17 ( struct V_13 * V_14 ,
struct V_116 * V_117 ,
T_2 * V_118 ,
T_1 * V_119 )
{
unsigned int V_120 ;
unsigned int * V_32 , V_121 , V_122 ;
int V_36 , V_123 ;
struct V_124 * V_57 ;
struct V_54 * V_55 ;
struct V_56 * V_80 ;
struct V_125 * V_126 ;
bool V_35 ;
F_2 ( ! V_14 || ! V_117 || ! V_119 || ! V_118 ) ;
V_121 = V_36 = V_123 = 0 ;
V_36 = F_6 ( V_14 , & V_32 , V_118 ,
& V_120 , & V_35 ) ;
if ( V_36 != 0 )
return V_36 ;
* V_119 = V_120 ;
F_5 ( L_4 , V_59 ) ;
F_5 ( L_6 ,
V_14 -> V_20 -> V_21 , V_14 -> V_20 -> V_18 ) ;
F_13 (cur, queues, list) {
V_55 = V_57 -> V_55 ;
if ( V_123 >= V_14 -> V_20 -> V_21 ) {
F_5 ( L_7 ) ;
F_18 ( V_14 ) ;
return - V_127 ;
}
V_36 = F_12 ( V_14 , & V_32 [ V_121 ] , V_55 ) ;
if ( V_36 != 0 )
return V_36 ;
V_123 ++ ;
F_1 ( & V_121 , sizeof( struct V_30 ) ,
V_120 ) ;
F_13 (kq, &qpd->priv_queue_list, list) {
if ( V_126 -> V_56 -> V_92 . V_128 != true )
continue;
F_5 ( L_8 ,
V_126 -> V_56 -> V_56 , V_55 -> V_63 ) ;
if ( V_14 -> V_20 -> V_24 -> V_25 -> V_26 ==
V_27 )
V_36 = F_14 ( V_14 ,
& V_32 [ V_121 ] ,
V_126 -> V_56 ,
V_55 -> V_63 ) ;
else
V_36 = F_16 ( V_14 ,
& V_32 [ V_121 ] ,
V_126 -> V_56 ,
V_55 -> V_63 ) ;
if ( V_36 != 0 )
return V_36 ;
F_1 ( & V_121 ,
sizeof( struct V_29 ) ,
V_120 ) ;
}
F_13 (q, &qpd->queues_list, list) {
if ( V_80 -> V_92 . V_128 != true )
continue;
F_5 ( L_9 ,
V_80 -> V_56 , V_55 -> V_63 ) ;
if ( V_14 -> V_20 -> V_24 -> V_25 -> V_26 ==
V_27 )
V_36 = F_14 ( V_14 ,
& V_32 [ V_121 ] ,
V_80 ,
V_55 -> V_63 ) ;
else
V_36 = F_16 ( V_14 ,
& V_32 [ V_121 ] ,
V_80 ,
V_55 -> V_63 ) ;
if ( V_36 != 0 )
return V_36 ;
F_1 ( & V_121 ,
sizeof( struct V_29 ) ,
V_120 ) ;
}
}
F_5 ( L_10 ) ;
if ( V_35 )
F_9 ( V_14 , & V_32 [ V_121 ] , * V_118 ,
V_120 / sizeof( V_5 ) , true ) ;
for ( V_122 = 0 ; V_122 < V_120 / sizeof( V_5 ) ; V_122 ++ )
F_5 ( L_11 , V_32 [ V_122 ] ) ;
F_5 ( L_12 ) ;
return 0 ;
}
int F_19 ( struct V_13 * V_14 , struct V_129 * V_20 )
{
F_2 ( ! V_20 ) ;
V_14 -> V_20 = V_20 ;
F_20 ( & V_14 -> V_130 ) ;
V_14 -> V_131 = F_21 ( V_20 -> V_24 , V_132 ) ;
if ( V_14 -> V_131 == NULL ) {
F_22 ( & V_14 -> V_130 ) ;
return - V_127 ;
}
V_14 -> V_37 = false ;
return 0 ;
}
void F_23 ( struct V_13 * V_14 )
{
F_2 ( ! V_14 ) ;
F_22 ( & V_14 -> V_130 ) ;
F_24 ( V_14 -> V_131 ) ;
}
int F_25 ( struct V_13 * V_14 ,
struct V_133 * V_134 )
{
struct V_135 * V_45 ;
F_2 ( ! V_14 || ! V_134 ) ;
F_5 ( L_4 , V_59 ) ;
F_26 ( & V_14 -> V_130 ) ;
V_14 -> V_131 -> V_136 . V_137 ( V_14 -> V_131 ,
sizeof( * V_45 ) / sizeof( V_5 ) ,
( unsigned int * * ) & V_45 ) ;
if ( V_45 == NULL ) {
F_27 ( & V_14 -> V_130 ) ;
F_8 ( L_13 ) ;
return - V_127 ;
}
memset ( V_45 , 0 , sizeof( struct V_135 ) ) ;
V_45 -> V_9 . V_10 = F_3 ( V_138 ,
sizeof( struct V_135 ) ) ;
V_45 -> V_61 . V_90 =
V_139 ;
V_45 -> V_61 . V_140 = V_134 -> V_140 ;
V_45 -> V_61 . V_141 = V_142 ;
V_45 -> V_143 . V_144 = V_134 -> V_144 ;
V_45 -> V_145 . V_146 = V_134 -> V_146 ;
V_45 -> V_145 . V_147 = V_134 -> V_147 ;
V_45 -> V_148 = F_10 ( V_134 -> V_149 ) ;
V_45 -> V_150 = F_11 ( V_134 -> V_149 ) ;
V_45 -> V_151 = F_10 ( V_134 -> V_152 ) ;
V_45 -> V_153 = F_11 ( V_134 -> V_152 ) ;
V_14 -> V_131 -> V_136 . V_154 ( V_14 -> V_131 ) ;
F_27 ( & V_14 -> V_130 ) ;
return 0 ;
}
int F_28 ( struct V_13 * V_14 , struct V_116 * V_155 )
{
T_2 V_156 ;
V_5 * V_32 ;
T_1 V_157 , V_158 ;
int V_36 ;
F_2 ( ! V_14 || ! V_155 ) ;
V_36 = F_17 ( V_14 , V_155 , & V_156 ,
& V_157 ) ;
if ( V_36 != 0 )
goto V_159;
F_5 ( L_14 , V_156 ) ;
V_158 = sizeof( struct V_31 ) / sizeof( V_5 ) ;
F_26 ( & V_14 -> V_130 ) ;
V_36 = V_14 -> V_131 -> V_136 . V_137 ( V_14 -> V_131 ,
V_158 , & V_32 ) ;
if ( V_36 != 0 )
goto V_160;
V_36 = F_9 ( V_14 , V_32 , V_156 ,
V_157 / sizeof( V_5 ) , false ) ;
if ( V_36 != 0 )
goto V_161;
V_14 -> V_131 -> V_136 . V_154 ( V_14 -> V_131 ) ;
F_27 ( & V_14 -> V_130 ) ;
return V_36 ;
V_161:
V_14 -> V_131 -> V_136 . V_162 ( V_14 -> V_131 ) ;
V_160:
F_27 ( & V_14 -> V_130 ) ;
V_159:
if ( V_14 -> V_37 == true )
F_18 ( V_14 ) ;
return V_36 ;
}
int F_29 ( struct V_13 * V_14 , T_2 V_163 ,
V_5 V_164 )
{
int V_36 ;
struct V_165 * V_45 ;
F_2 ( ! V_14 || ! V_163 ) ;
F_26 ( & V_14 -> V_130 ) ;
V_36 = V_14 -> V_131 -> V_136 . V_137 (
V_14 -> V_131 ,
sizeof( struct V_165 ) / sizeof( V_5 ) ,
( unsigned int * * ) & V_45 ) ;
if ( V_36 != 0 )
goto V_160;
V_45 -> V_9 . V_10 = F_3 ( V_166 ,
sizeof( struct V_165 ) ) ;
V_45 -> V_61 . V_167 = 0 ;
V_45 -> V_61 . V_168 =
V_169 ;
V_45 -> V_61 . V_170 =
V_171 ;
V_45 -> V_172 = F_11 ( ( T_2 ) V_163 ) ;
V_45 -> V_173 = F_10 ( ( T_2 ) V_163 ) ;
V_45 -> V_174 = F_11 ( ( T_2 ) V_164 ) ;
V_45 -> V_175 = F_10 ( ( T_2 ) V_164 ) ;
V_14 -> V_131 -> V_136 . V_154 ( V_14 -> V_131 ) ;
F_27 ( & V_14 -> V_130 ) ;
return 0 ;
V_160:
F_27 ( & V_14 -> V_130 ) ;
return V_36 ;
}
int F_30 ( struct V_13 * V_14 , enum V_176 type ,
enum V_177 V_178 ,
V_5 V_179 , bool V_180 ,
unsigned int V_181 )
{
int V_36 ;
V_5 * V_41 ;
struct V_182 * V_45 ;
F_2 ( ! V_14 ) ;
F_26 ( & V_14 -> V_130 ) ;
V_36 = V_14 -> V_131 -> V_136 . V_137 (
V_14 -> V_131 ,
sizeof( struct V_182 ) / sizeof( V_5 ) ,
& V_41 ) ;
if ( V_36 != 0 )
goto V_183;
V_45 = (struct V_182 * ) V_41 ;
memset ( V_41 , 0 , sizeof( struct V_182 ) ) ;
F_5 ( L_15 ,
V_178 , V_180 , type ) ;
V_45 -> V_9 . V_10 = F_3 ( V_184 ,
sizeof( struct V_182 ) ) ;
switch ( type ) {
case V_93 :
case V_95 :
V_45 -> V_61 . V_88 =
V_185 ;
break;
case V_97 :
V_45 -> V_61 . V_88 =
V_186 + V_181 ;
break;
default:
F_15 () ;
break;
}
if ( V_180 )
V_45 -> V_61 . V_187 =
V_188 ;
else
V_45 -> V_61 . V_187 =
V_189 ;
switch ( V_178 ) {
case V_190 :
V_45 -> V_61 . V_86 =
V_191 ;
V_45 -> V_61 . V_58 = 1 ;
V_45 -> V_192 . V_193 = V_179 ;
break;
case V_194 :
V_45 -> V_61 . V_86 =
V_195 ;
V_45 -> V_196 . V_65 = V_179 ;
break;
case V_197 :
V_45 -> V_61 . V_86 =
V_198 ;
break;
case V_199 :
V_45 -> V_61 . V_86 =
V_200 ;
break;
default:
F_15 () ;
break;
} ;
V_14 -> V_131 -> V_136 . V_154 ( V_14 -> V_131 ) ;
F_27 ( & V_14 -> V_130 ) ;
return 0 ;
V_183:
F_27 ( & V_14 -> V_130 ) ;
return V_36 ;
}
void F_18 ( struct V_13 * V_14 )
{
F_2 ( ! V_14 ) ;
F_26 ( & V_14 -> V_130 ) ;
if ( V_14 -> V_37 ) {
F_31 ( V_14 -> V_20 -> V_24 , V_14 -> V_38 ) ;
V_14 -> V_37 = false ;
}
F_27 ( & V_14 -> V_130 ) ;
}
