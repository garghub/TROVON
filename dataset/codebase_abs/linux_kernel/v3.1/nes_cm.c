static struct V_1 * F_1 ( struct V_2 * V_3 ,
enum V_4 type )
{
struct V_1 * V_5 ;
if ( ! V_3 -> V_6 )
return NULL ;
V_5 = F_2 ( sizeof( * V_5 ) , V_7 ) ;
if ( ! V_5 )
return NULL ;
V_5 -> type = type ;
V_5 -> V_3 = V_3 ;
V_5 -> V_8 . V_9 = V_3 -> V_9 ;
V_5 -> V_8 . V_10 = V_3 -> V_10 ;
V_5 -> V_8 . V_11 = V_3 -> V_11 ;
V_5 -> V_8 . V_12 = V_3 -> V_12 ;
V_5 -> V_8 . V_6 = V_3 -> V_6 ;
F_3 ( V_13 , L_1
L_2 ,
V_3 , V_5 , type , V_5 -> V_8 . V_10 ,
V_5 -> V_8 . V_12 , V_5 -> V_8 . V_9 ,
V_5 -> V_8 . V_11 ) ;
F_4 ( V_5 ) ;
return V_5 ;
}
static int F_5 ( struct V_2 * V_3 , struct V_14 * V_15 )
{
if ( ! V_15 ) {
F_3 ( V_13 , L_3 ) ;
return - 1 ;
}
F_6 ( V_15 , V_3 , NULL , 0 , & V_3 -> V_16 ,
V_3 -> V_17 , V_18 ) ;
return F_7 ( V_3 , V_15 , V_19 , 1 , 0 ) ;
}
static int F_8 ( struct V_2 * V_3 )
{
struct V_14 * V_15 = NULL ;
V_15 = F_9 ( V_20 ) ;
if ( ! V_15 ) {
F_3 ( V_13 , L_4 ) ;
return - V_21 ;
}
F_6 ( V_15 , V_3 , NULL , 0 , & V_3 -> V_16 ,
V_3 -> V_17 , V_18 | V_22 ) ;
V_3 -> V_23 = V_24 ;
return F_7 ( V_3 , V_15 , V_19 , 1 , 0 ) ;
}
static int F_10 ( struct V_2 * V_3 , T_1 * V_25 , T_2 * type ,
T_2 V_26 )
{
struct V_27 * V_16 ;
* type = V_28 ;
if ( V_26 < sizeof( struct V_27 ) ) {
F_3 ( V_13 , L_5 , V_26 ) ;
return - V_29 ;
}
V_16 = (struct V_27 * ) V_25 ;
V_3 -> V_17 = F_11 ( V_16 -> V_30 ) ;
if ( V_3 -> V_17 > V_31 ) {
F_3 ( V_13 , L_6
L_7 ) ;
return - V_29 ;
}
if ( V_16 -> V_32 != V_33 ) {
F_3 ( V_13 , L_8
L_9 ) ;
return - V_29 ;
}
if ( V_3 -> V_23 != V_34 ) {
if ( memcmp ( V_16 -> V_35 , V_36 , V_37 ) ) {
F_3 ( V_13 , L_10 ) ;
return - V_29 ;
}
} else {
if ( memcmp ( V_16 -> V_35 , V_38 , V_37 ) ) {
F_3 ( V_13 , L_10 ) ;
return - V_29 ;
}
}
if ( V_3 -> V_17 + sizeof( struct V_27 ) != V_26 ) {
F_3 ( V_13 , L_11
L_12 ,
V_3 -> V_17 ,
( T_2 ) sizeof( struct V_27 ) , V_26 ) ;
return - V_29 ;
}
if ( V_26 > V_20 ) {
F_3 ( V_13 , L_13
L_14 ,
V_3 -> V_17 ,
( T_2 ) sizeof( struct V_27 ) , V_26 ) ;
return - V_29 ;
}
memcpy ( V_3 -> V_39 , V_25 + sizeof( struct V_27 ) ,
V_3 -> V_17 ) ;
if ( V_16 -> V_40 & V_41 )
* type = V_42 ;
return 0 ;
}
static void F_6 ( struct V_14 * V_15 ,
struct V_2 * V_3 , void * V_43 , T_2 V_44 ,
void * V_45 , T_2 V_46 , T_1 V_40 )
{
struct V_47 * V_48 ;
struct V_49 * V_50 ;
struct V_51 * V_52 ;
T_1 * V_53 ;
T_3 V_54 = sizeof( * V_50 ) ;
V_54 += sizeof( * V_48 ) ;
V_54 += V_44 + V_46 ;
memset ( V_15 -> V_45 , 0x00 , V_55 + sizeof( * V_50 ) + sizeof( * V_48 ) ) ;
V_15 -> V_26 = 0 ;
V_53 = F_12 ( V_15 , V_54 + V_55 ) ;
V_52 = (struct V_51 * ) V_53 ;
V_53 += V_55 ;
V_50 = (struct V_49 * ) V_53 ;
V_53 += sizeof( * V_50 ) ;
V_48 = (struct V_47 * ) V_53 ;
F_13 ( V_15 ) ;
F_14 ( V_15 , V_55 ) ;
F_15 ( V_15 , V_55 + sizeof( * V_50 ) ) ;
V_53 += sizeof( * V_48 ) ;
V_15 -> V_56 = V_57 ;
V_15 -> V_58 = F_16 ( 0x800 ) ;
V_15 -> V_59 = 0 ;
V_15 -> V_60 = V_55 ;
memcpy ( V_52 -> V_61 , V_3 -> V_62 , V_63 ) ;
memcpy ( V_52 -> V_64 , V_3 -> V_65 , V_63 ) ;
V_52 -> V_66 = F_16 ( 0x0800 ) ;
V_50 -> V_67 = V_68 ;
V_50 -> V_69 = 5 ;
V_50 -> V_70 = 0 ;
V_50 -> V_71 = F_16 ( V_54 ) ;
V_50 -> V_72 = F_16 ( ++ V_3 -> V_73 . V_74 ) ;
V_50 -> V_75 = F_16 ( 0x4000 ) ;
V_50 -> V_76 = 0x40 ;
V_50 -> V_58 = 0x06 ;
V_50 -> V_77 = F_17 ( V_3 -> V_10 ) ;
V_50 -> V_78 = F_17 ( V_3 -> V_9 ) ;
V_48 -> V_79 = F_16 ( V_3 -> V_12 ) ;
V_48 -> V_80 = F_16 ( V_3 -> V_11 ) ;
V_48 -> V_81 = F_17 ( V_3 -> V_73 . V_82 ) ;
if ( V_40 & V_18 ) {
V_3 -> V_73 . V_83 = V_3 -> V_73 . V_84 ;
V_48 -> V_85 = F_17 ( V_3 -> V_73 . V_83 ) ;
V_48 -> V_86 = 1 ;
} else
V_48 -> V_85 = 0 ;
if ( V_40 & V_87 ) {
V_3 -> V_73 . V_82 ++ ;
V_48 -> V_88 = 1 ;
} else
V_3 -> V_73 . V_82 += V_46 ;
if ( V_40 & V_22 ) {
V_3 -> V_73 . V_82 ++ ;
V_48 -> V_89 = 1 ;
}
if ( V_40 & V_90 )
V_48 -> V_91 = 1 ;
V_48 -> V_92 = ( T_3 ) ( ( sizeof( * V_48 ) + V_44 + 3 ) >> 2 ) ;
V_48 -> V_93 = F_16 ( V_3 -> V_73 . V_94 ) ;
V_48 -> V_95 = 0 ;
if ( V_44 )
memcpy ( V_53 , V_43 , V_44 ) ;
V_53 += V_44 ;
if ( V_46 )
memcpy ( V_53 , V_45 , V_46 ) ;
F_18 ( V_15 ) -> V_96 = 0 ;
V_97 ++ ;
}
static void F_19 ( struct V_98 * V_99 )
{
F_3 ( V_13 , L_15 ) ;
F_3 ( V_13 , L_16 , V_99 ) ;
if ( ! V_99 )
return;
F_3 ( V_13 , L_15 ) ;
F_3 ( V_13 , L_17 , V_99 -> V_23 ) ;
F_3 ( V_13 , L_18 , F_20 ( & V_99 -> V_100 ) ) ;
F_3 ( V_13 , L_19 , F_20 ( & V_99 -> V_101 ) ) ;
F_3 ( V_13 , L_20 , V_99 ) ;
F_3 ( V_13 , L_21 ) ;
}
int F_7 ( struct V_2 * V_3 , struct V_14 * V_15 ,
enum V_102 type , int V_103 ,
int V_104 )
{
unsigned long V_40 ;
struct V_98 * V_105 = V_3 -> V_105 ;
struct V_106 * V_107 ;
int V_108 = 0 ;
T_2 V_109 ;
V_107 = F_2 ( sizeof( * V_107 ) , V_7 ) ;
if ( ! V_107 )
return - V_21 ;
V_107 -> V_110 = V_111 ;
V_107 -> V_112 = V_113 ;
V_107 -> V_15 = V_15 ;
V_107 -> V_114 = V_115 ;
V_107 -> type = type ;
V_107 -> V_116 = V_3 -> V_116 ;
V_107 -> V_103 = V_103 ;
V_107 -> V_104 = V_104 ;
if ( type == V_117 ) {
V_107 -> V_114 += ( V_118 / 10 ) ;
if ( V_3 -> V_119 ) {
F_21 ( V_107 ) ;
F_22 ( 1 ) ;
return - V_29 ;
}
V_3 -> V_119 = V_107 ;
}
if ( type == V_19 ) {
V_107 -> V_120 = F_23 ( F_24 ( V_15 ) -> V_81 ) ;
F_25 ( & V_107 -> V_15 -> V_121 ) ;
F_26 ( & V_3 -> V_122 , V_40 ) ;
V_3 -> V_123 = V_107 ;
F_27 ( V_3 ) ;
F_28 ( & V_3 -> V_122 , V_40 ) ;
V_107 -> V_114 = V_115 + V_124 ;
V_108 = F_29 ( V_107 -> V_15 , V_3 -> V_116 ) ;
if ( V_108 != V_125 ) {
F_3 ( V_13 , L_22
L_23 , V_107 , V_115 ) ;
V_107 -> V_114 = V_115 ;
V_108 = V_125 ;
} else {
V_126 ++ ;
if ( ! V_103 ) {
F_30 ( V_3 ) ;
if ( V_104 )
F_31 ( V_105 , V_3 ) ;
return V_108 ;
}
}
}
V_109 = F_32 ( & V_105 -> V_127 ) ;
if ( ! V_109 ) {
V_105 -> V_127 . V_128 = V_107 -> V_114 ;
F_33 ( & V_105 -> V_127 ) ;
}
return V_108 ;
}
static void F_34 ( struct V_2 * V_3 )
{
struct V_129 * V_6 = V_3 -> V_6 ;
enum V_130 V_23 = V_3 -> V_23 ;
V_3 -> V_23 = V_131 ;
switch ( V_23 ) {
case V_132 :
case V_133 :
F_31 ( V_3 -> V_105 , V_3 ) ;
break;
case V_134 :
case V_24 :
if ( V_3 -> V_6 )
V_6 -> V_135 ( V_6 ) ;
F_35 ( V_3 , NULL ) ;
break;
default:
F_27 ( V_3 ) ;
F_35 ( V_3 , NULL ) ;
F_1 ( V_3 , V_136 ) ;
}
}
static void F_36 ( struct V_2 * V_3 , T_2 V_137 )
{
struct V_106 * V_119 = V_3 -> V_119 ;
struct V_129 * V_6 = V_3 -> V_6 ;
struct V_138 * V_139 ;
unsigned long V_140 ;
if ( ! V_119 )
return;
V_139 = (struct V_138 * ) V_119 -> V_15 ;
if ( V_139 ) {
F_26 ( & V_139 -> V_141 , V_140 ) ;
if ( V_139 -> V_6 ) {
F_3 ( V_13 , L_24
L_25
L_26
L_27 , V_139 -> V_142 . V_143 , V_6 ,
F_20 ( & V_139 -> V_144 ) ) ;
V_139 -> V_145 = V_146 ;
V_139 -> V_147 = V_148 ;
V_139 -> V_149 = V_150 ;
F_28 ( & V_139 -> V_141 , V_140 ) ;
F_37 ( V_139 ) ;
} else {
F_28 ( & V_139 -> V_141 , V_140 ) ;
F_3 ( V_13 , L_24
L_25
L_28
L_27 , V_139 -> V_142 . V_143 , V_6 ,
F_20 ( & V_139 -> V_144 ) ) ;
}
} else if ( V_137 ) {
F_31 ( V_3 -> V_105 , V_3 ) ;
}
if ( V_3 -> V_6 )
V_6 -> V_135 ( V_6 ) ;
F_21 ( V_119 ) ;
V_3 -> V_119 = NULL ;
}
static void F_38 ( unsigned long V_151 )
{
unsigned long V_40 ;
unsigned long V_152 = V_115 + V_153 ;
struct V_2 * V_3 ;
struct V_106 * V_123 , * V_119 ;
struct V_154 * V_155 ;
struct V_154 * V_156 ;
struct V_98 * V_105 = V_157 ;
T_2 V_158 = 0 ;
unsigned long V_114 ;
int V_108 = V_125 ;
struct V_154 V_159 ;
F_39 ( & V_159 ) ;
F_26 ( & V_105 -> V_160 , V_40 ) ;
F_40 (list_node, list_core_temp,
&cm_core->connected_nodes) {
V_3 = F_41 ( V_156 , struct V_2 , V_161 ) ;
if ( ( V_3 -> V_119 ) || ( V_3 -> V_123 ) ) {
F_27 ( V_3 ) ;
F_42 ( & V_3 -> V_162 , & V_159 ) ;
}
}
F_28 ( & V_105 -> V_160 , V_40 ) ;
F_40 (list_node, list_core_temp, &timer_list) {
V_3 = F_41 ( V_156 , struct V_2 ,
V_162 ) ;
V_119 = V_3 -> V_119 ;
if ( V_119 ) {
if ( F_43 ( V_119 -> V_114 , V_115 ) ) {
if ( V_152 > V_119 -> V_114 ||
! V_158 ) {
V_152 = V_119 -> V_114 ;
V_158 = 1 ;
}
} else
F_36 ( V_3 , 1 ) ;
}
F_26 ( & V_3 -> V_122 , V_40 ) ;
do {
V_123 = V_3 -> V_123 ;
if ( ! V_123 )
break;
if ( F_43 ( V_123 -> V_114 , V_115 ) ) {
if ( V_3 -> V_23 != V_163 ) {
if ( ( V_152 >
V_123 -> V_114 ) ||
! V_158 ) {
V_152 =
V_123 -> V_114 ;
V_158 = 1 ;
}
} else {
F_44 ( V_3 ) ;
}
break;
}
if ( ( V_3 -> V_23 == V_163 ) ||
( V_3 -> V_23 == V_131 ) ) {
F_44 ( V_3 ) ;
break;
}
if ( ! V_123 -> V_112 ||
! V_123 -> V_110 ) {
V_164 ++ ;
F_44 ( V_3 ) ;
F_28 (
& V_3 -> V_122 , V_40 ) ;
F_34 ( V_3 ) ;
V_3 -> V_23 = V_131 ;
F_26 ( & V_3 -> V_122 ,
V_40 ) ;
break;
}
F_25 ( & V_123 -> V_15 -> V_121 ) ;
V_165 ++ ;
F_3 ( V_13 , L_29
L_30
L_31
L_32
L_33 , V_123 , V_3 , V_115 ,
V_123 -> V_114 ,
V_123 -> V_112 ,
V_123 -> V_120 ,
V_3 -> V_73 . V_166 ) ;
F_28 ( & V_3 -> V_122 ,
V_40 ) ;
V_108 = F_29 ( V_123 -> V_15 , V_3 -> V_116 ) ;
F_26 ( & V_3 -> V_122 , V_40 ) ;
if ( V_108 != V_125 ) {
F_3 ( V_13 , L_34
L_35 , V_3 ) ;
V_167 ++ ;
V_123 -> V_110 -- ;
V_152 = V_115 + V_168 ;
V_158 = 1 ;
break;
} else {
V_126 ++ ;
}
F_3 ( V_13 , L_36
L_37 ,
V_123 -> V_112 ,
V_123 -> V_110 ) ;
if ( V_123 -> V_103 ) {
V_123 -> V_112 -- ;
V_114 = ( V_124 <<
( V_113 - V_123 -> V_112 ) ) ;
V_123 -> V_114 = V_115 +
F_45 ( V_114 , V_169 ) ;
if ( V_152 > V_123 -> V_114 ||
! V_158 ) {
V_152 = V_123 -> V_114 ;
V_158 = 1 ;
}
} else {
int V_104 ;
V_104 =
V_123 -> V_104 ;
F_3 ( V_13 , L_38 ,
V_3 , V_3 -> V_23 ) ;
F_44 ( V_3 ) ;
if ( V_104 )
F_31 ( V_3 -> V_105 ,
V_3 ) ;
}
} while ( 0 );
F_28 ( & V_3 -> V_122 , V_40 ) ;
F_31 ( V_3 -> V_105 , V_3 ) ;
}
if ( V_158 ) {
if ( ! F_32 ( & V_105 -> V_127 ) ) {
V_105 -> V_127 . V_128 = V_152 ;
F_33 ( & V_105 -> V_127 ) ;
}
}
}
static int F_46 ( struct V_2 * V_3 , T_2 V_170 ,
struct V_14 * V_15 )
{
int V_108 ;
int V_40 = V_87 ;
char V_171 [ sizeof( struct V_172 ) +
sizeof( struct V_173 ) + sizeof( struct V_174 ) +
V_175 ] ;
int V_176 = 0 ;
union V_177 * V_43 ;
if ( ! V_3 )
return - V_29 ;
V_43 = (union V_177 * ) & V_171 [ V_176 ] ;
V_43 -> V_178 . V_179 = V_180 ;
V_43 -> V_178 . V_181 = sizeof( struct V_172 ) ;
V_43 -> V_178 . V_182 = F_16 ( V_3 -> V_73 . V_182 ) ;
V_176 += sizeof( struct V_172 ) ;
V_43 = (union V_177 * ) & V_171 [ V_176 ] ;
V_43 -> V_183 . V_179 = V_184 ;
V_43 -> V_183 . V_181 = sizeof( struct V_173 ) ;
V_43 -> V_183 . V_185 = V_3 -> V_73 . V_186 ;
V_176 += sizeof( struct V_173 ) ;
if ( V_170 && ! ( V_187 & V_188 ) ) {
V_43 = (union V_177 * ) & V_171 [ V_176 ] ;
V_43 -> V_189 . V_179 = V_190 ;
V_43 -> V_189 . V_181 = sizeof( struct V_174 ) ;
V_176 += sizeof( struct V_174 ) ;
V_43 = (union V_177 * ) & V_171 [ V_176 ] ;
V_43 -> V_191 = 1 ;
V_176 += 1 ;
V_43 = (union V_177 * ) & V_171 [ V_176 ] ;
V_43 -> V_191 = 1 ;
V_176 += 1 ;
}
V_43 = (union V_177 * ) & V_171 [ V_176 ] ;
V_43 -> V_191 = V_192 ;
V_176 += 1 ;
if ( ! V_15 )
V_15 = F_9 ( V_20 ) ;
if ( ! V_15 ) {
F_3 ( V_13 , L_4 ) ;
return - 1 ;
}
if ( V_170 )
V_40 |= V_18 ;
F_6 ( V_15 , V_3 , V_171 , V_176 , NULL , 0 , V_40 ) ;
V_108 = F_7 ( V_3 , V_15 , V_19 , 1 , 0 ) ;
return V_108 ;
}
static int F_35 ( struct V_2 * V_3 , struct V_14 * V_15 )
{
int V_108 ;
int V_40 = V_90 | V_18 ;
if ( ! V_15 )
V_15 = F_9 ( V_20 ) ;
if ( ! V_15 ) {
F_3 ( V_13 , L_4 ) ;
return - V_21 ;
}
F_6 ( V_15 , V_3 , NULL , 0 , NULL , 0 , V_40 ) ;
V_108 = F_7 ( V_3 , V_15 , V_19 , 0 , 1 ) ;
return V_108 ;
}
static int F_47 ( struct V_2 * V_3 , struct V_14 * V_15 )
{
int V_108 ;
if ( ! V_15 )
V_15 = F_9 ( V_20 ) ;
if ( ! V_15 ) {
F_3 ( V_13 , L_4 ) ;
return - 1 ;
}
F_6 ( V_15 , V_3 , NULL , 0 , NULL , 0 , V_18 ) ;
V_108 = F_7 ( V_3 , V_15 , V_19 , 0 , 0 ) ;
return V_108 ;
}
static int F_48 ( struct V_2 * V_3 , struct V_14 * V_15 )
{
int V_108 ;
if ( ! V_15 )
V_15 = F_9 ( V_20 ) ;
if ( ! V_15 ) {
F_3 ( V_13 , L_4 ) ;
return - 1 ;
}
F_6 ( V_15 , V_3 , NULL , 0 , NULL , 0 , V_18 | V_22 ) ;
V_108 = F_7 ( V_3 , V_15 , V_19 , 1 , 0 ) ;
return V_108 ;
}
static struct V_2 * F_49 ( struct V_98 * V_105 ,
T_3 V_11 , T_4 V_9 , T_3 V_12 , T_4 V_10 )
{
unsigned long V_40 ;
struct V_154 * V_193 ;
struct V_2 * V_3 ;
V_193 = & V_105 -> V_194 ;
F_26 ( & V_105 -> V_160 , V_40 ) ;
F_50 (cm_node, hte, list) {
F_3 ( V_13 , L_39 ,
V_3 -> V_10 , V_3 -> V_12 ,
V_10 , V_12 ,
V_3 -> V_9 , V_3 -> V_11 ,
V_9 , V_11 ) ;
if ( ( V_3 -> V_10 == V_10 ) && ( V_3 -> V_12 == V_12 ) &&
( V_3 -> V_9 == V_9 ) && ( V_3 -> V_11 == V_11 ) ) {
F_27 ( V_3 ) ;
F_28 ( & V_105 -> V_160 , V_40 ) ;
return V_3 ;
}
}
F_28 ( & V_105 -> V_160 , V_40 ) ;
return NULL ;
}
static struct V_195 * F_51 ( struct V_98 * V_105 ,
T_4 V_196 , T_3 V_197 , enum V_198 V_199 )
{
unsigned long V_40 ;
struct V_195 * V_200 ;
F_26 ( & V_105 -> V_201 , V_40 ) ;
F_50 (listen_node, &cm_core->listen_list.list, list) {
if ( ( ( V_200 -> V_10 == V_196 ) ||
V_200 -> V_10 == 0x00000000 ) &&
( V_200 -> V_12 == V_197 ) &&
( V_199 & V_200 -> V_199 ) ) {
F_25 ( & V_200 -> V_202 ) ;
F_28 ( & V_105 -> V_201 , V_40 ) ;
return V_200 ;
}
}
F_28 ( & V_105 -> V_201 , V_40 ) ;
return NULL ;
}
static int F_52 ( struct V_98 * V_105 , struct V_2 * V_3 )
{
unsigned long V_40 ;
struct V_154 * V_193 ;
if ( ! V_3 || ! V_105 )
return - V_29 ;
F_3 ( V_13 , L_40 ,
V_3 ) ;
F_26 ( & V_105 -> V_160 , V_40 ) ;
V_193 = & V_105 -> V_194 ;
F_53 ( & V_3 -> V_161 , V_193 ) ;
F_25 ( & V_105 -> V_203 ) ;
F_28 ( & V_105 -> V_160 , V_40 ) ;
return 0 ;
}
static int F_54 ( struct V_98 * V_105 ,
struct V_195 * V_204 , int V_205 )
{
int V_108 = - V_29 ;
int V_206 = 0 ;
unsigned long V_40 ;
struct V_154 * V_207 = NULL ;
struct V_154 * V_208 = NULL ;
struct V_2 * V_3 = NULL ;
struct V_154 V_209 ;
F_3 ( V_13 , L_41
L_42 , V_204 , V_205 ,
F_20 ( & V_204 -> V_202 ) ) ;
F_39 ( & V_209 ) ;
if ( V_205 ) {
F_26 ( & V_105 -> V_160 , V_40 ) ;
F_40 (list_pos, list_temp,
&g_cm_core->connected_nodes) {
V_3 = F_41 ( V_207 , struct V_2 ,
V_161 ) ;
if ( ( V_3 -> V_204 == V_204 ) &&
( ! V_3 -> V_210 ) ) {
F_27 ( V_3 ) ;
F_42 ( & V_3 -> V_211 , & V_209 ) ;
}
}
F_28 ( & V_105 -> V_160 , V_40 ) ;
}
F_40 (list_pos, list_temp, &reset_list) {
V_3 = F_41 ( V_207 , struct V_2 ,
V_211 ) ;
{
struct V_2 * V_212 = V_3 -> V_213 ;
enum V_130 V_214 ;
if ( V_24 <= V_3 -> V_23 ) {
F_31 ( V_3 -> V_105 , V_3 ) ;
} else {
if ( ! V_212 ) {
F_30 ( V_3 ) ;
V_206 = F_35 ( V_3 , NULL ) ;
if ( V_206 ) {
V_3 -> V_23 =
V_131 ;
F_22 ( 1 ) ;
} else {
V_214 = V_3 -> V_23 ;
V_3 -> V_23 = V_215 ;
if ( V_214 != V_216 )
F_31 (
V_3 -> V_105 ,
V_3 ) ;
}
} else {
struct V_1 V_5 ;
V_5 . V_3 = V_212 ;
V_5 . V_8 . V_9 =
V_212 -> V_9 ;
V_5 . V_8 . V_10 =
V_212 -> V_10 ;
V_5 . V_8 . V_11 =
V_212 -> V_11 ;
V_5 . V_8 . V_12 =
V_212 -> V_12 ;
V_5 . V_8 . V_6 = V_212 -> V_6 ;
F_27 ( V_212 ) ;
V_212 -> V_23 = V_131 ;
F_55 ( & V_5 ) ;
V_3 -> V_23 = V_215 ;
F_31 ( V_3 -> V_105 ,
V_3 ) ;
}
}
}
}
F_26 ( & V_105 -> V_201 , V_40 ) ;
if ( ! F_56 ( & V_204 -> V_202 ) ) {
F_57 ( & V_204 -> V_161 ) ;
F_58 ( & V_105 -> V_100 ) ;
F_28 ( & V_105 -> V_201 , V_40 ) ;
if ( V_204 -> V_217 ) {
F_59 ( V_204 -> V_217 , V_204 -> V_12 ,
F_60 ( V_204 -> V_217 -> V_218 -> V_219 -> V_220 ) , V_221 ) ;
}
F_3 ( V_13 , L_43 , V_204 ) ;
F_21 ( V_204 ) ;
V_204 = NULL ;
V_108 = 0 ;
F_25 ( & V_222 ) ;
} else {
F_28 ( & V_105 -> V_201 , V_40 ) ;
}
if ( V_204 ) {
if ( F_20 ( & V_204 -> V_223 ) > 0 )
F_3 ( V_13 , L_44
L_45 ,
V_204 , F_20 ( & V_204 -> V_223 ) ) ;
}
return V_108 ;
}
static int F_61 ( struct V_98 * V_105 ,
struct V_195 * V_204 )
{
V_204 -> V_199 = V_224 ;
V_204 -> V_6 = NULL ;
return F_54 ( V_105 , V_204 , 1 ) ;
}
static inline int F_62 ( struct V_98 * V_105 ,
struct V_2 * V_3 )
{
T_2 V_109 ;
V_3 -> V_210 = 1 ;
if ( V_3 -> V_225 ) {
F_63 ( ! V_3 -> V_204 ) ;
F_58 ( & V_3 -> V_204 -> V_223 ) ;
V_3 -> V_225 = 0 ;
F_63 ( F_20 ( & V_3 -> V_204 -> V_223 ) < 0 ) ;
}
V_109 = F_32 ( & V_105 -> V_127 ) ;
if ( ! V_109 ) {
V_105 -> V_127 . V_128 = V_115 + V_168 ;
F_33 ( & V_105 -> V_127 ) ;
}
return 0 ;
}
static int F_64 ( struct V_226 * V_217 , T_2 V_227 , int V_228 )
{
struct V_229 * V_230 ;
struct V_231 * V_232 ;
int V_233 = V_228 ;
struct V_234 * V_116 ;
struct V_235 * V_236 = V_217 -> V_218 -> V_236 ;
V_230 = F_65 ( & V_237 , F_17 ( V_227 ) , 0 , 0 , 0 ) ;
if ( F_66 ( V_230 ) ) {
F_67 ( V_238 L_46 ,
V_239 , V_227 ) ;
return V_233 ;
}
if ( F_68 ( V_217 -> V_116 ) )
V_116 = V_217 -> V_116 -> V_240 ;
else
V_116 = V_217 -> V_116 ;
V_232 = F_69 ( & V_241 , & V_230 -> V_242 , V_116 ) ;
if ( V_232 ) {
if ( V_232 -> V_243 & V_244 ) {
F_3 ( V_13 , L_47
L_48 , V_227 ,
V_232 -> V_245 , F_23 ( V_230 -> V_242 ) ) ;
if ( V_228 >= 0 ) {
if ( ! memcmp ( V_236 -> V_246 [ V_228 ] . V_247 ,
V_232 -> V_245 , V_63 ) ) {
F_70 ( V_232 ) ;
F_71 ( V_230 ) ;
return V_233 ;
}
F_72 ( V_217 -> V_116 ,
V_236 -> V_246 [ V_228 ] . V_247 ,
V_227 , V_248 ) ;
}
F_72 ( V_217 -> V_116 , V_232 -> V_245 ,
V_227 , V_249 ) ;
V_233 = F_73 ( V_217 -> V_218 , V_227 , NULL ,
V_250 ) ;
}
F_70 ( V_232 ) ;
}
if ( ( V_232 == NULL ) || ( ! ( V_232 -> V_243 & V_244 ) ) )
F_74 ( F_75 ( & V_230 -> V_251 ) , NULL ) ;
F_71 ( V_230 ) ;
return V_233 ;
}
static struct V_2 * F_76 ( struct V_98 * V_105 ,
struct V_226 * V_217 , struct V_252 * V_8 ,
struct V_195 * V_204 )
{
struct V_2 * V_3 ;
struct V_253 V_254 ;
int V_255 = 0 ;
int V_228 = 0 ;
struct V_256 * V_218 ;
struct V_235 * V_236 ;
V_3 = F_2 ( sizeof( * V_3 ) , V_7 ) ;
if ( ! V_3 )
return NULL ;
V_3 -> V_10 = V_8 -> V_10 ;
V_3 -> V_9 = V_8 -> V_9 ;
V_3 -> V_12 = V_8 -> V_12 ;
V_3 -> V_11 = V_8 -> V_11 ;
V_3 -> V_257 = V_258 ;
F_3 ( V_13 , L_49 ,
& V_3 -> V_10 , V_3 -> V_12 ,
& V_3 -> V_9 , V_3 -> V_11 ) ;
V_3 -> V_204 = V_204 ;
V_3 -> V_116 = V_217 -> V_116 ;
V_3 -> V_6 = V_8 -> V_6 ;
memcpy ( V_3 -> V_65 , V_217 -> V_116 -> V_259 , V_63 ) ;
F_3 ( V_13 , L_50 , V_3 -> V_204 ,
V_3 -> V_6 ) ;
F_77 ( & V_3 -> V_122 ) ;
V_3 -> V_213 = NULL ;
F_78 ( & V_3 -> V_202 , 1 ) ;
V_3 -> V_105 = V_105 ;
V_3 -> V_73 . V_74 = V_260 ;
V_3 -> V_73 . V_186 = V_261 ;
V_3 -> V_73 . V_94 = V_262 >>
V_261 ;
V_254 = F_79 () ;
V_3 -> V_73 . V_82 = F_17 ( V_254 . V_263 ) ;
V_3 -> V_73 . V_182 = V_217 -> V_264 - sizeof( struct V_49 ) -
sizeof( struct V_47 ) - V_55 - V_265 ;
V_3 -> V_73 . V_84 = 0 ;
F_25 ( & V_105 -> V_101 ) ;
V_3 -> V_266 = V_8 -> V_266 ;
V_3 -> V_267 = 0 ;
V_3 -> V_225 = 0 ;
V_3 -> V_217 = V_217 ;
V_218 = V_217 -> V_218 ;
V_236 = V_218 -> V_236 ;
V_3 -> V_213 = NULL ;
if ( F_80 ( F_17 ( V_3 -> V_9 ) ) )
V_228 = F_73 ( V_218 , F_23 ( V_217 -> V_268 ) , NULL , V_250 ) ;
else {
V_255 = F_73 ( V_218 , V_3 -> V_9 , NULL , V_250 ) ;
V_228 = F_64 ( V_217 , V_8 -> V_9 , V_255 ) ;
}
if ( V_228 < 0 ) {
F_21 ( V_3 ) ;
return NULL ;
}
memcpy ( V_3 -> V_62 , V_236 -> V_246 [ V_228 ] . V_247 , V_63 ) ;
F_3 ( V_13 , L_51 ,
V_3 -> V_62 ) ;
F_52 ( V_105 , V_3 ) ;
F_25 ( & V_269 ) ;
return V_3 ;
}
static int F_27 ( struct V_2 * V_3 )
{
F_25 ( & V_3 -> V_202 ) ;
return 0 ;
}
static int F_31 ( struct V_98 * V_105 ,
struct V_2 * V_3 )
{
unsigned long V_40 ;
struct V_138 * V_139 ;
if ( ! V_3 )
return - V_29 ;
F_26 ( & V_3 -> V_105 -> V_160 , V_40 ) ;
if ( F_56 ( & V_3 -> V_202 ) ) {
F_28 ( & V_3 -> V_105 -> V_160 , V_40 ) ;
return 0 ;
}
F_57 ( & V_3 -> V_161 ) ;
F_58 ( & V_105 -> V_203 ) ;
F_28 ( & V_3 -> V_105 -> V_160 , V_40 ) ;
if ( ! V_3 -> V_210 && V_3 -> V_225 ) {
F_63 ( ! V_3 -> V_204 ) ;
F_58 ( & V_3 -> V_204 -> V_223 ) ;
F_63 ( F_20 ( & V_3 -> V_204 -> V_223 ) < 0 ) ;
}
F_22 ( V_3 -> V_123 ) ;
if ( V_3 -> V_119 )
F_36 ( V_3 , 0 ) ;
if ( V_3 -> V_204 ) {
F_54 ( V_105 , V_3 -> V_204 , 0 ) ;
} else {
if ( V_3 -> V_267 && V_3 -> V_217 ) {
F_59 ( V_3 -> V_217 , V_3 -> V_12 ,
F_60 (
V_3 -> V_217 -> V_218 -> V_219 -> V_220 ) ,
V_221 ) ;
}
}
F_58 ( & V_105 -> V_101 ) ;
F_25 ( & V_270 ) ;
V_139 = V_3 -> V_139 ;
if ( V_139 ) {
V_139 -> V_3 = NULL ;
F_81 ( & V_139 -> V_271 ) ;
V_3 -> V_139 = NULL ;
}
F_21 ( V_3 ) ;
return 0 ;
}
static int F_82 ( struct V_2 * V_3 , T_1 * V_272 ,
T_2 V_44 , T_2 V_273 )
{
T_2 V_274 ;
T_2 V_275 = 0 ;
union V_177 * V_276 ;
char V_277 = 0 ;
while ( V_275 < V_44 ) {
V_276 = (union V_177 * ) ( V_272 + V_275 ) ;
switch ( V_276 -> V_189 . V_179 ) {
case V_192 :
V_275 = V_44 ;
break;
case V_278 :
V_275 += 1 ;
continue;
case V_180 :
F_3 ( V_13 , L_52
L_53 , V_239 ,
V_276 -> V_178 . V_181 , V_275 , V_44 ) ;
V_277 = 1 ;
if ( V_276 -> V_178 . V_181 != 4 ) {
return 1 ;
} else {
V_274 = F_11 ( V_276 -> V_178 . V_182 ) ;
if ( V_274 > 0 && V_274 <
V_3 -> V_73 . V_182 )
V_3 -> V_73 . V_182 = V_274 ;
}
break;
case V_184 :
V_3 -> V_73 . V_279 =
V_276 -> V_183 . V_185 ;
break;
case V_190 :
V_3 -> V_257 = 1 ;
break;
default:
F_3 ( V_13 , L_54 ,
V_276 -> V_189 . V_179 ) ;
break;
}
V_275 += V_276 -> V_189 . V_181 ;
}
if ( ( ! V_277 ) && ( V_273 ) )
V_3 -> V_73 . V_182 = V_280 ;
return 0 ;
}
static void F_83 ( struct V_14 * V_15 )
{
F_25 ( & V_281 ) ;
F_84 ( V_15 ) ;
}
static void F_85 ( struct V_2 * V_3 )
{
F_3 ( V_13 , L_55
L_42 , V_3 , V_3 -> V_23 ,
F_20 ( & V_3 -> V_202 ) ) ;
switch ( V_3 -> V_23 ) {
case V_132 :
case V_282 :
case V_283 :
case V_284 :
V_3 -> V_73 . V_84 ++ ;
F_30 ( V_3 ) ;
V_3 -> V_23 = V_134 ;
F_48 ( V_3 , NULL ) ;
break;
case V_34 :
F_1 ( V_3 , V_136 ) ;
V_3 -> V_73 . V_84 ++ ;
F_30 ( V_3 ) ;
V_3 -> V_23 = V_131 ;
F_27 ( V_3 ) ;
F_35 ( V_3 , NULL ) ;
break;
case V_24 :
V_3 -> V_73 . V_84 ++ ;
F_30 ( V_3 ) ;
V_3 -> V_23 = V_133 ;
F_47 ( V_3 , NULL ) ;
break;
case V_285 :
V_3 -> V_73 . V_84 ++ ;
F_30 ( V_3 ) ;
V_3 -> V_23 = V_286 ;
F_47 ( V_3 , NULL ) ;
F_7 ( V_3 , NULL , V_117 , 1 , 0 ) ;
break;
case V_286 :
V_3 -> V_73 . V_84 ++ ;
F_30 ( V_3 ) ;
V_3 -> V_23 = V_131 ;
F_31 ( V_3 -> V_105 , V_3 ) ;
break;
case V_163 :
default:
F_3 ( V_13 , L_56 ,
V_3 , V_3 -> V_23 ) ;
break;
}
}
static void F_86 ( struct V_2 * V_3 , struct V_14 * V_15 ,
struct V_47 * V_48 )
{
int V_287 = 0 ;
F_25 ( & V_288 ) ;
F_3 ( V_13 , L_57
L_58 , V_3 , V_3 -> V_23 ,
F_20 ( & V_3 -> V_202 ) ) ;
F_30 ( V_3 ) ;
switch ( V_3 -> V_23 ) {
case V_282 :
case V_34 :
F_3 ( V_13 , L_59
L_60 , V_239 , __LINE__ , V_3 ,
V_3 -> V_204 , V_3 -> V_23 ) ;
F_87 ( V_3 , V_15 , V_287 ) ;
break;
case V_216 :
F_25 ( & V_3 -> V_289 ) ;
F_84 ( V_15 ) ;
break;
case V_283 :
case V_132 :
case V_290 :
F_3 ( V_13 , L_61 , V_239 , __LINE__ ) ;
F_88 ( V_3 , V_15 , V_287 ) ;
break;
case V_163 :
F_87 ( V_3 , V_15 , V_287 ) ;
break;
case V_131 :
F_83 ( V_15 ) ;
break;
case V_285 :
case V_24 :
case V_134 :
V_3 -> V_6 -> V_135 ( V_3 -> V_6 ) ;
case V_286 :
V_3 -> V_23 = V_131 ;
F_31 ( V_3 -> V_105 , V_3 ) ;
F_83 ( V_15 ) ;
break;
default:
F_83 ( V_15 ) ;
break;
}
}
static void F_89 ( struct V_2 * V_3 , struct V_14 * V_15 )
{
int V_108 = 0 ;
int V_46 = V_15 -> V_26 ;
T_1 * V_291 = V_15 -> V_45 ;
enum V_4 type = V_292 ;
T_2 V_293 ;
V_108 = F_10 ( V_3 , V_291 , & V_293 , V_46 ) ;
if ( V_108 ) {
F_3 ( V_13 , L_62 ) ;
if ( V_3 -> V_23 == V_34 ) {
F_3 ( V_13 , L_63
L_64 , V_239 ,
__LINE__ , V_3 , V_3 -> V_204 ,
V_3 -> V_23 ) ;
F_87 ( V_3 , V_15 , 1 ) ;
} else {
F_88 ( V_3 , V_15 , 1 ) ;
}
return;
}
switch ( V_3 -> V_23 ) {
case V_283 :
if ( V_293 == V_42 ) {
F_22 ( 1 ) ;
}
V_3 -> V_23 = V_216 ;
type = V_294 ;
F_78 ( & V_3 -> V_289 ,
V_295 ) ;
break;
case V_34 :
F_30 ( V_3 ) ;
if ( V_293 == V_42 ) {
type = V_296 ;
V_3 -> V_23 = V_284 ;
} else {
type = V_297 ;
V_3 -> V_23 = V_163 ;
}
break;
default:
F_22 ( 1 ) ;
break;
}
F_84 ( V_15 ) ;
F_1 ( V_3 , type ) ;
}
static void F_90 ( struct V_2 * V_3 , struct V_14 * V_15 )
{
switch ( V_3 -> V_23 ) {
case V_282 :
case V_34 :
F_3 ( V_13 , L_59
L_60 , V_239 , __LINE__ , V_3 ,
V_3 -> V_204 , V_3 -> V_23 ) ;
F_87 ( V_3 , V_15 , 1 ) ;
break;
case V_283 :
case V_132 :
F_88 ( V_3 , V_15 , 1 ) ;
break;
case V_163 :
default:
F_83 ( V_15 ) ;
}
}
static int F_91 ( struct V_2 * V_3 , struct V_47 * V_48 ,
struct V_14 * V_15 )
{
int V_206 ;
V_206 = ( ( F_23 ( V_48 -> V_85 ) == V_3 -> V_73 . V_82 ) ) ? 0 : 1 ;
if ( V_206 )
F_87 ( V_3 , V_15 , 1 ) ;
return V_206 ;
}
static int F_92 ( struct V_2 * V_3 , struct V_47 * V_48 ,
struct V_14 * V_15 )
{
int V_206 = 0 ;
T_2 V_81 ;
T_2 V_85 ;
T_2 V_82 = V_3 -> V_73 . V_82 ;
T_2 V_84 = V_3 -> V_73 . V_84 ;
T_2 V_94 ;
V_81 = F_23 ( V_48 -> V_81 ) ;
V_85 = F_23 ( V_48 -> V_85 ) ;
V_94 = V_3 -> V_73 . V_94 ;
if ( V_85 != V_82 )
V_206 = 1 ;
else if ( ! F_93 ( V_81 , V_84 , ( V_84 + V_94 ) ) )
V_206 = 1 ;
if ( V_206 ) {
F_3 ( V_13 , L_59
L_60 , V_239 , __LINE__ , V_3 ,
V_3 -> V_204 , V_3 -> V_23 ) ;
F_90 ( V_3 , V_15 ) ;
F_3 ( V_13 , L_65
L_66 , V_3 , V_81 , V_84 ,
V_94 ) ;
}
return V_206 ;
}
static void F_94 ( struct V_2 * V_3 , struct V_14 * V_15 ,
struct V_47 * V_48 )
{
int V_108 ;
T_2 V_298 ;
int V_44 ;
V_44 = ( V_48 -> V_92 << 2 ) - sizeof( struct V_47 ) ;
F_95 ( V_15 , 0 ) ;
V_298 = F_23 ( V_48 -> V_81 ) ;
switch ( V_3 -> V_23 ) {
case V_282 :
case V_34 :
F_87 ( V_3 , V_15 , 1 ) ;
break;
case V_290 :
if ( F_20 ( & V_3 -> V_204 -> V_223 ) >
V_3 -> V_204 -> V_299 ) {
F_3 ( V_13 , L_67
L_68 ) ;
V_300 ++ ;
F_88 ( V_3 , V_15 , 0 ) ;
break;
}
V_108 = F_96 ( V_3 , V_48 , V_15 , V_44 ,
1 ) ;
if ( V_108 ) {
F_88 ( V_3 , V_15 , 0 ) ;
break;
}
V_3 -> V_73 . V_84 = V_298 + 1 ;
F_63 ( V_3 -> V_123 ) ;
V_3 -> V_225 = 1 ;
F_25 ( & V_3 -> V_204 -> V_223 ) ;
V_3 -> V_23 = V_132 ;
F_46 ( V_3 , 1 , V_15 ) ;
break;
case V_131 :
F_30 ( V_3 ) ;
F_27 ( V_3 ) ;
F_35 ( V_3 , V_15 ) ;
break;
case V_163 :
case V_283 :
case V_24 :
case V_285 :
case V_216 :
case V_134 :
case V_133 :
case V_301 :
default:
F_83 ( V_15 ) ;
break;
}
}
static void F_97 ( struct V_2 * V_3 , struct V_14 * V_15 ,
struct V_47 * V_48 )
{
int V_108 ;
T_2 V_298 ;
int V_44 ;
V_44 = ( V_48 -> V_92 << 2 ) - sizeof( struct V_47 ) ;
F_95 ( V_15 , 0 ) ;
V_298 = F_23 ( V_48 -> V_81 ) ;
switch ( V_3 -> V_23 ) {
case V_282 :
F_30 ( V_3 ) ;
if ( F_91 ( V_3 , V_48 , V_15 ) )
return;
V_3 -> V_73 . V_166 = F_23 ( V_48 -> V_85 ) ;
V_108 = F_96 ( V_3 , V_48 , V_15 , V_44 , 0 ) ;
if ( V_108 ) {
F_3 ( V_13 , L_69 ,
V_3 ) ;
break;
}
F_30 ( V_3 ) ;
V_3 -> V_73 . V_84 = V_298 + 1 ;
F_5 ( V_3 , V_15 ) ;
V_3 -> V_23 = V_34 ;
break;
case V_216 :
F_88 ( V_3 , V_15 , 1 ) ;
break;
case V_290 :
V_3 -> V_73 . V_82 = F_23 ( V_48 -> V_85 ) ;
F_30 ( V_3 ) ;
V_3 -> V_23 = V_131 ;
F_35 ( V_3 , V_15 ) ;
break;
case V_131 :
V_3 -> V_73 . V_82 = F_23 ( V_48 -> V_85 ) ;
F_30 ( V_3 ) ;
F_27 ( V_3 ) ;
F_35 ( V_3 , V_15 ) ;
break;
case V_283 :
case V_24 :
case V_285 :
case V_134 :
case V_163 :
case V_133 :
case V_301 :
case V_34 :
default:
F_83 ( V_15 ) ;
break;
}
}
static int F_98 ( struct V_2 * V_3 , struct V_14 * V_15 ,
struct V_47 * V_48 )
{
int V_46 = 0 ;
T_2 V_298 ;
int V_108 = 0 ;
int V_44 ;
V_44 = ( V_48 -> V_92 << 2 ) - sizeof( struct V_47 ) ;
if ( F_92 ( V_3 , V_48 , V_15 ) )
return - V_29 ;
F_99 ( V_15 , V_48 -> V_92 << 2 ) ;
V_298 = F_23 ( V_48 -> V_81 ) ;
V_46 = V_15 -> V_26 ;
switch ( V_3 -> V_23 ) {
case V_132 :
F_30 ( V_3 ) ;
V_108 = F_96 ( V_3 , V_48 , V_15 , V_44 , 1 ) ;
if ( V_108 )
break;
V_3 -> V_73 . V_166 = F_23 ( V_48 -> V_85 ) ;
V_3 -> V_23 = V_283 ;
if ( V_46 ) {
V_3 -> V_73 . V_84 = V_298 + V_46 ;
F_89 ( V_3 , V_15 ) ;
} else
F_84 ( V_15 ) ;
break;
case V_283 :
F_30 ( V_3 ) ;
if ( V_46 ) {
V_3 -> V_73 . V_84 = V_298 + V_46 ;
F_89 ( V_3 , V_15 ) ;
} else
F_83 ( V_15 ) ;
break;
case V_34 :
V_3 -> V_73 . V_166 = F_23 ( V_48 -> V_85 ) ;
if ( V_46 ) {
V_3 -> V_73 . V_84 = V_298 + V_46 ;
F_89 ( V_3 , V_15 ) ;
} else
F_84 ( V_15 ) ;
break;
case V_290 :
F_30 ( V_3 ) ;
V_3 -> V_23 = V_131 ;
F_35 ( V_3 , V_15 ) ;
break;
case V_131 :
F_30 ( V_3 ) ;
F_27 ( V_3 ) ;
F_35 ( V_3 , V_15 ) ;
break;
case V_134 :
case V_133 :
F_30 ( V_3 ) ;
V_3 -> V_23 = V_131 ;
V_3 -> V_6 -> V_135 ( V_3 -> V_6 ) ;
F_31 ( V_3 -> V_105 , V_3 ) ;
F_83 ( V_15 ) ;
break;
case V_24 :
F_30 ( V_3 ) ;
F_83 ( V_15 ) ;
V_3 -> V_23 = V_285 ;
break;
case V_282 :
case V_285 :
case V_163 :
case V_216 :
case V_301 :
default:
F_30 ( V_3 ) ;
F_83 ( V_15 ) ;
break;
}
return V_108 ;
}
static int F_96 ( struct V_2 * V_3 , struct V_47 * V_48 ,
struct V_14 * V_15 , int V_44 , int V_302 )
{
T_1 * V_272 = ( T_1 * ) & V_48 [ 1 ] ;
if ( V_44 ) {
if ( F_82 ( V_3 , V_272 , V_44 ,
( T_2 ) V_48 -> V_88 ) ) {
F_3 ( V_13 , L_70 ,
V_239 , V_3 ) ;
if ( V_302 )
F_88 ( V_3 , V_15 , 1 ) ;
else
F_87 ( V_3 , V_15 , 1 ) ;
return 1 ;
}
}
V_3 -> V_73 . V_303 = F_11 ( V_48 -> V_93 ) <<
V_3 -> V_73 . V_279 ;
if ( V_3 -> V_73 . V_303 > V_3 -> V_73 . V_304 )
V_3 -> V_73 . V_304 = V_3 -> V_73 . V_303 ;
return 0 ;
}
static void F_87 ( struct V_2 * V_3 , struct V_14 * V_15 ,
int V_287 )
{
F_30 ( V_3 ) ;
if ( V_287 ) {
F_3 ( V_13 , L_71
L_72 , V_3 , V_3 -> V_23 ) ;
F_27 ( V_3 ) ;
F_35 ( V_3 , V_15 ) ;
} else
F_84 ( V_15 ) ;
V_3 -> V_23 = V_131 ;
F_1 ( V_3 , V_136 ) ;
}
static void F_88 ( struct V_2 * V_3 , struct V_14 * V_15 ,
int V_287 )
{
F_30 ( V_3 ) ;
V_3 -> V_23 = V_131 ;
if ( V_287 ) {
F_3 ( V_13 , L_73
L_74 , V_3 , V_3 -> V_23 ) ;
F_35 ( V_3 , V_15 ) ;
} else {
F_84 ( V_15 ) ;
F_31 ( V_3 -> V_105 , V_3 ) ;
}
}
static void F_44 ( struct V_2 * V_3 )
{
struct V_106 * V_123 ;
V_123 = V_3 -> V_123 ;
if ( V_123 ) {
V_3 -> V_123 = NULL ;
F_84 ( V_123 -> V_15 ) ;
F_21 ( V_123 ) ;
F_31 ( V_3 -> V_105 , V_3 ) ;
}
}
static void F_30 ( struct V_2 * V_3 )
{
unsigned long V_40 ;
F_26 ( & V_3 -> V_122 , V_40 ) ;
F_44 ( V_3 ) ;
F_28 ( & V_3 -> V_122 , V_40 ) ;
}
static void F_100 ( struct V_2 * V_3 , struct V_14 * V_15 ,
struct V_98 * V_105 )
{
enum V_305 V_306 = V_307 ;
struct V_47 * V_48 = F_24 ( V_15 ) ;
T_2 V_308 = 0 ;
int V_108 = 0 ;
F_99 ( V_15 , F_101 ( V_15 ) -> V_69 << 2 ) ;
F_3 ( V_13 , L_75
L_76 , V_3 , V_3 -> V_23 , V_48 -> V_88 ,
V_48 -> V_86 , V_48 -> V_91 , V_48 -> V_89 ) ;
if ( V_48 -> V_91 )
V_306 = V_309 ;
else if ( V_48 -> V_88 ) {
V_306 = V_310 ;
if ( V_48 -> V_86 )
V_306 = V_311 ;
} else if ( V_48 -> V_86 )
V_306 = V_312 ;
if ( V_48 -> V_89 )
V_308 = 1 ;
switch ( V_306 ) {
case V_310 :
F_94 ( V_3 , V_15 , V_48 ) ;
break;
case V_311 :
F_97 ( V_3 , V_15 , V_48 ) ;
break;
case V_312 :
V_108 = F_98 ( V_3 , V_15 , V_48 ) ;
if ( V_308 && ! V_108 )
F_85 ( V_3 ) ;
break;
case V_309 :
F_86 ( V_3 , V_15 , V_48 ) ;
break;
default:
if ( ( V_308 ) && ( ! F_92 ( V_3 , V_48 , V_15 ) ) )
F_85 ( V_3 ) ;
F_83 ( V_15 ) ;
break;
}
}
static struct V_195 * F_102 ( struct V_98 * V_105 ,
struct V_226 * V_217 , struct V_252 * V_8 )
{
struct V_195 * V_204 ;
unsigned long V_40 ;
F_3 ( V_13 , L_77 ,
V_8 -> V_10 , V_8 -> V_12 ) ;
V_204 = F_51 ( V_105 , F_17 ( V_8 -> V_10 ) ,
F_16 ( V_8 -> V_12 ) , V_313 ) ;
if ( V_204 && V_204 -> V_199 == V_314 ) {
F_58 ( & V_204 -> V_202 ) ;
F_3 ( V_13 , L_78 ) ;
return NULL ;
}
if ( ! V_204 ) {
V_204 = F_2 ( sizeof( * V_204 ) , V_7 ) ;
if ( ! V_204 ) {
F_3 ( V_13 , L_79 ) ;
return NULL ;
}
V_204 -> V_10 = F_17 ( V_8 -> V_10 ) ;
V_204 -> V_12 = F_16 ( V_8 -> V_12 ) ;
V_204 -> V_315 = 0 ;
F_78 ( & V_204 -> V_202 , 1 ) ;
}
else {
V_204 -> V_315 = 1 ;
}
V_204 -> V_6 = V_8 -> V_6 ;
F_78 ( & V_204 -> V_223 , 0 ) ;
V_204 -> V_105 = V_105 ;
V_204 -> V_217 = V_217 ;
F_25 ( & V_105 -> V_101 ) ;
V_204 -> V_266 = V_8 -> V_266 ;
V_204 -> V_299 = V_8 -> V_299 ;
V_204 -> V_199 = V_314 ;
if ( ! V_204 -> V_315 ) {
F_26 ( & V_105 -> V_201 , V_40 ) ;
F_42 ( & V_204 -> V_161 , & V_105 -> V_316 . V_161 ) ;
F_28 ( & V_105 -> V_201 , V_40 ) ;
F_25 ( & V_105 -> V_100 ) ;
}
F_3 ( V_13 , L_80
L_81 ,
V_8 -> V_10 , V_8 -> V_12 ,
V_204 , V_204 -> V_299 , V_204 -> V_6 ) ;
return V_204 ;
}
static struct V_2 * F_103 ( struct V_98 * V_105 ,
struct V_226 * V_217 , T_3 V_317 ,
void * V_318 , struct V_252 * V_8 )
{
int V_108 = 0 ;
struct V_2 * V_3 ;
struct V_195 * V_319 ;
struct V_2 * V_320 ;
struct V_252 V_321 ;
T_3 V_17 = sizeof( struct V_27 ) + V_317 ;
struct V_27 * V_16 = NULL ;
V_3 = F_76 ( V_105 , V_217 , V_8 , NULL ) ;
if ( ! V_3 )
return NULL ;
V_16 = & V_3 -> V_16 ;
memcpy ( V_16 -> V_35 , V_36 , V_37 ) ;
V_16 -> V_40 = V_322 ;
V_16 -> V_32 = V_323 ;
V_16 -> V_30 = F_16 ( V_317 ) ;
V_3 -> V_73 . V_324 = 1 ;
V_3 -> V_73 . V_186 = V_261 ;
if ( V_8 -> V_10 == V_8 -> V_9 ) {
V_319 = F_51 ( V_105 ,
F_23 ( V_217 -> V_268 ) , V_3 -> V_11 ,
V_314 ) ;
if ( V_319 == NULL ) {
F_1 ( V_3 , V_136 ) ;
} else {
V_321 = * V_8 ;
V_321 . V_12 = V_8 -> V_11 ;
V_321 . V_11 = V_8 -> V_12 ;
V_321 . V_6 = V_319 -> V_6 ;
V_320 = F_76 ( V_105 , V_217 ,
& V_321 , V_319 ) ;
if ( ! V_320 ) {
F_31 ( V_3 -> V_105 , V_3 ) ;
return NULL ;
}
F_25 ( & V_325 ) ;
V_320 -> V_213 = V_3 ;
V_320 -> V_73 . V_186 =
V_261 ;
V_3 -> V_213 = V_320 ;
memcpy ( V_320 -> V_39 , V_318 ,
V_317 ) ;
V_320 -> V_17 = V_317 ;
V_3 -> V_23 = V_163 ;
V_3 -> V_73 . V_84 =
V_320 -> V_73 . V_82 ;
V_320 -> V_73 . V_84 =
V_3 -> V_73 . V_82 ;
V_3 -> V_73 . V_304 =
V_320 -> V_73 . V_94 ;
V_320 -> V_73 . V_304 =
V_3 -> V_73 . V_94 ;
V_3 -> V_73 . V_303 =
V_320 -> V_73 . V_94 ;
V_320 -> V_73 . V_303 =
V_3 -> V_73 . V_94 ;
V_3 -> V_73 . V_279 =
V_320 -> V_73 . V_186 ;
V_320 -> V_73 . V_279 =
V_3 -> V_73 . V_186 ;
V_320 -> V_23 = V_216 ;
F_1 ( V_320 , V_294 ) ;
}
return V_3 ;
}
V_3 -> V_73 . V_324 = 1 ;
memcpy ( V_16 -> V_326 , V_318 , V_317 ) ;
V_3 -> V_17 = V_17 ;
V_3 -> V_23 = V_282 ;
V_108 = F_46 ( V_3 , 0 , NULL ) ;
if ( V_108 ) {
F_3 ( V_13 , L_82
L_83 ,
V_3 -> V_9 , V_3 -> V_11 , V_3 ,
V_3 -> V_6 ) ;
F_31 ( V_3 -> V_105 , V_3 ) ;
V_3 = NULL ;
}
if ( V_3 )
F_3 ( V_13 , L_84
L_85 ,
V_3 -> V_9 , V_3 -> V_11 , V_3 ,
V_3 -> V_6 ) ;
return V_3 ;
}
static int F_104 ( struct V_98 * V_105 ,
struct V_27 * V_16 , struct V_2 * V_3 )
{
return 0 ;
}
static int F_105 ( struct V_98 * V_105 ,
struct V_27 * V_16 , struct V_2 * V_3 )
{
int V_108 = 0 ;
int V_206 = 0 ;
int V_289 ;
struct V_1 V_5 ;
struct V_129 * V_6 = V_3 -> V_6 ;
struct V_2 * V_212 = V_3 -> V_213 ;
F_3 ( V_13 , L_86 ,
V_239 , V_3 , V_3 -> V_73 . V_324 , V_3 -> V_23 ) ;
if ( V_3 -> V_73 . V_324 )
return V_108 ;
F_30 ( V_3 ) ;
if ( ! V_212 ) {
V_289 = F_106 ( 1 , & V_3 -> V_289 ) ;
if ( V_289 == V_327 ) {
V_3 -> V_23 = V_131 ;
F_31 ( V_105 , V_3 ) ;
} else {
if ( V_3 -> V_23 == V_215 ) {
F_31 ( V_105 , V_3 ) ;
} else {
V_108 = F_8 ( V_3 ) ;
if ( V_108 ) {
V_3 -> V_23 = V_131 ;
V_206 = F_35 ( V_3 , NULL ) ;
if ( V_206 )
F_22 ( 1 ) ;
} else
V_6 -> V_328 ( V_6 ) ;
}
}
} else {
V_3 -> V_6 = NULL ;
if ( V_3 -> V_23 == V_215 ) {
F_31 ( V_105 , V_3 ) ;
F_31 ( V_105 , V_212 ) ;
} else {
V_5 . V_3 = V_212 ;
V_5 . V_8 . V_9 = V_212 -> V_9 ;
V_5 . V_8 . V_10 = V_212 -> V_10 ;
V_5 . V_8 . V_11 = V_212 -> V_11 ;
V_5 . V_8 . V_12 = V_212 -> V_12 ;
V_5 . V_8 . V_6 = V_212 -> V_6 ;
F_107 ( & V_5 ) ;
F_31 ( V_105 , V_3 ) ;
V_212 -> V_23 = V_133 ;
V_6 = V_212 -> V_6 ;
F_31 ( V_105 , V_212 ) ;
V_6 -> V_135 ( V_6 ) ;
}
}
return V_108 ;
}
static int F_108 ( struct V_98 * V_105 , struct V_2 * V_3 )
{
int V_108 = 0 ;
if ( ! V_105 || ! V_3 )
return - V_29 ;
switch ( V_3 -> V_23 ) {
case V_132 :
case V_282 :
case V_329 :
case V_283 :
case V_330 :
case V_34 :
case V_216 :
F_30 ( V_3 ) ;
F_35 ( V_3 , NULL ) ;
break;
case V_331 :
V_3 -> V_23 = V_134 ;
F_48 ( V_3 , NULL ) ;
break;
case V_24 :
case V_285 :
case V_134 :
case V_286 :
case V_133 :
V_108 = - 1 ;
break;
case V_290 :
F_30 ( V_3 ) ;
F_35 ( V_3 , NULL ) ;
break;
case V_284 :
case V_301 :
case V_332 :
case V_131 :
case V_215 :
V_108 = F_31 ( V_105 , V_3 ) ;
break;
case V_163 :
if ( V_3 -> V_123 )
F_67 ( V_238 L_87
L_88 , V_3 -> V_123 ) ;
V_108 = F_31 ( V_105 , V_3 ) ;
break;
}
return V_108 ;
}
static int F_109 ( struct V_98 * V_105 ,
struct V_226 * V_217 , struct V_14 * V_15 )
{
struct V_2 * V_3 = NULL ;
struct V_195 * V_204 = NULL ;
struct V_49 * V_50 ;
struct V_47 * V_48 ;
struct V_252 V_333 ;
int V_334 = 1 ;
T_5 V_335 , V_336 ;
if ( ! V_15 )
return 0 ;
if ( V_15 -> V_26 < sizeof( struct V_49 ) + sizeof( struct V_47 ) ) {
return 0 ;
}
V_50 = (struct V_49 * ) V_15 -> V_45 ;
V_48 = (struct V_47 * ) ( V_15 -> V_45 + sizeof( struct V_49 ) ) ;
V_333 . V_10 = F_23 ( V_50 -> V_78 ) ;
V_333 . V_12 = F_11 ( V_48 -> V_80 ) ;
V_333 . V_9 = F_23 ( V_50 -> V_77 ) ;
V_333 . V_11 = F_11 ( V_48 -> V_79 ) ;
V_335 = F_110 ( V_50 -> V_78 ) ;
V_336 = F_110 ( V_50 -> V_77 ) ;
F_3 ( V_13 , L_89 ,
& V_335 , V_48 -> V_80 , & V_336 , V_48 -> V_79 ) ;
do {
V_3 = F_49 ( V_105 ,
V_333 . V_11 , V_333 . V_9 ,
V_333 . V_12 , V_333 . V_10 ) ;
if ( ! V_3 ) {
if ( ( ! V_48 -> V_88 ) || ( V_48 -> V_86 ) ) {
V_334 = 0 ;
break;
}
V_204 = F_51 ( V_105 , V_333 . V_10 ,
V_333 . V_12 ,
V_314 ) ;
if ( ! V_204 ) {
V_333 . V_6 = NULL ;
V_333 . V_266 = 0 ;
F_3 ( V_13 , L_90 ) ;
V_334 = 0 ;
break;
}
V_333 . V_6 = V_204 -> V_6 ;
V_333 . V_266 = V_204 -> V_266 ;
V_3 = F_76 ( V_105 , V_217 , & V_333 ,
V_204 ) ;
if ( ! V_3 ) {
F_3 ( V_13 , L_91
L_92 ) ;
V_164 ++ ;
F_58 ( & V_204 -> V_202 ) ;
F_84 ( V_15 ) ;
break;
}
if ( ! V_48 -> V_91 && ! V_48 -> V_89 ) {
V_3 -> V_23 = V_290 ;
} else {
V_164 ++ ;
F_31 ( V_105 , V_3 ) ;
F_84 ( V_15 ) ;
break;
}
F_27 ( V_3 ) ;
} else if ( V_3 -> V_23 == V_163 ) {
F_31 ( V_105 , V_3 ) ;
F_25 ( & V_281 ) ;
F_84 ( V_15 ) ;
break;
}
F_111 ( V_15 ) ;
F_15 ( V_15 , sizeof( * V_48 ) ) ;
V_15 -> V_26 = F_11 ( V_50 -> V_71 ) ;
F_100 ( V_3 , V_15 , V_105 ) ;
F_31 ( V_105 , V_3 ) ;
} while ( 0 );
return V_334 ;
}
static struct V_98 * F_112 ( void )
{
struct V_98 * V_105 ;
V_105 = F_2 ( sizeof( * V_105 ) , V_337 ) ;
if ( ! V_105 )
return NULL ;
F_39 ( & V_105 -> V_194 ) ;
F_113 ( & V_105 -> V_127 ) ;
V_105 -> V_127 . V_338 = F_38 ;
V_105 -> V_339 = V_340 ;
V_105 -> V_23 = V_332 ;
V_105 -> V_341 = V_342 ;
F_78 ( & V_105 -> V_343 , 0 ) ;
V_105 -> V_344 = & V_345 ;
F_77 ( & V_105 -> V_160 ) ;
F_77 ( & V_105 -> V_201 ) ;
F_39 ( & V_105 -> V_316 . V_161 ) ;
F_3 ( V_13 , L_93 , V_105 ) ;
F_3 ( V_13 , L_94 ) ;
V_105 -> V_346 = F_114 ( L_95 ) ;
V_105 -> V_347 = F_4 ;
F_3 ( V_13 , L_96 ) ;
V_105 -> V_348 = F_114 ( L_97 ) ;
F_19 ( V_105 ) ;
return V_105 ;
}
static int F_115 ( struct V_98 * V_105 )
{
F_3 ( V_13 , L_98 , V_105 ) ;
if ( ! V_105 )
return - V_29 ;
F_116 () ;
if ( F_32 ( & V_105 -> V_127 ) ) {
F_117 ( & V_105 -> V_127 ) ;
}
F_118 ( V_105 -> V_346 ) ;
F_118 ( V_105 -> V_348 ) ;
F_3 ( V_13 , L_99 ) ;
F_21 ( V_105 ) ;
return 0 ;
}
static int F_119 ( struct V_98 * V_105 )
{
return V_105 -> V_23 ;
}
static int F_120 ( struct V_98 * V_105 , T_2 type , T_2 V_349 )
{
int V_108 = 0 ;
switch ( type ) {
case V_350 :
V_105 -> V_339 = V_349 ;
break;
case V_351 :
V_105 -> V_341 = V_349 ;
break;
default:
V_108 = - V_29 ;
}
return V_108 ;
}
static int F_121 ( struct V_138 * V_139 , struct V_2 * V_3 )
{
int V_108 = 0 ;
if ( ! V_139 )
return - V_29 ;
V_139 -> V_352 -> V_353 |= F_122 ( V_354 |
V_355 | V_356 |
V_357 ) ;
if ( V_3 -> V_73 . V_279 || V_3 -> V_73 . V_186 )
V_139 -> V_352 -> V_353 |= F_122 ( V_358 ) ;
V_139 -> V_352 -> V_359 |= F_122 ( 64 << V_360 ) ;
V_139 -> V_352 -> V_182 |= F_122 ( ( ( T_2 ) V_3 -> V_73 . V_182 ) << 16 ) ;
V_139 -> V_352 -> V_361 |= F_122 (
( T_2 ) V_362 << V_363 ) ;
V_139 -> V_352 -> V_364 |= F_122 (
( V_3 -> V_73 . V_279 << V_365 ) &
V_366 ) ;
V_139 -> V_352 -> V_364 |= F_122 (
( V_3 -> V_73 . V_186 << V_367 ) &
V_368 ) ;
V_139 -> V_352 -> V_369 = F_122 ( 0x80 ) ;
V_139 -> V_352 -> V_370 = 0 ;
V_139 -> V_352 -> V_371 = 0 ;
V_139 -> V_352 -> V_372 = F_122 ( V_3 -> V_73 . V_82 ) ;
V_139 -> V_352 -> V_303 = F_122 ( V_3 -> V_73 . V_303 ) ;
V_139 -> V_352 -> V_84 = F_122 ( V_3 -> V_73 . V_84 ) ;
V_139 -> V_352 -> V_94 = F_122 ( V_3 -> V_73 . V_94 <<
V_3 -> V_73 . V_186 ) ;
V_139 -> V_352 -> V_373 = F_122 ( V_3 -> V_73 . V_82 ) ;
V_139 -> V_352 -> V_374 = F_122 ( V_3 -> V_73 . V_82 ) ;
V_139 -> V_352 -> V_375 = 0 ;
V_139 -> V_352 -> V_376 = F_122 ( 0x6 ) ;
V_139 -> V_352 -> V_377 = F_122 ( 0x3FFFC000 ) ;
V_139 -> V_352 -> V_378 = F_122 ( 2 * V_3 -> V_73 . V_182 ) ;
V_139 -> V_352 -> V_379 = F_122 ( V_3 -> V_73 . V_84 ) ;
V_139 -> V_352 -> V_380 = F_122 ( V_3 -> V_73 . V_82 ) ;
V_139 -> V_352 -> V_304 = F_122 ( V_3 -> V_73 . V_304 ) ;
F_3 ( V_13 , L_100
L_101 ,
V_139 -> V_142 . V_143 , F_123 ( V_139 -> V_352 -> V_84 ) ,
F_123 ( V_139 -> V_352 -> V_372 ) ,
V_3 -> V_73 . V_182 , F_123 ( V_139 -> V_352 -> V_364 ) ,
F_123 ( V_139 -> V_352 -> V_94 ) ,
F_123 ( V_139 -> V_352 -> V_353 ) ) ;
F_3 ( V_13 , L_102 , F_123 ( V_139 -> V_352 -> V_303 ) ) ;
F_3 ( V_13 , L_103 , F_123 ( V_139 -> V_352 -> V_378 ) ) ;
F_3 ( V_13 , L_104 , F_123 ( V_139 -> V_352 -> V_304 ) ) ;
F_3 ( V_13 , L_105 ) ;
V_3 -> V_23 = V_163 ;
return V_108 ;
}
int F_37 ( struct V_138 * V_139 )
{
struct V_381 * V_382 ;
V_382 = F_2 ( sizeof *V_382 , V_7 ) ;
if ( ! V_382 )
return - V_21 ;
F_124 ( & V_139 -> V_271 ) ;
V_382 -> V_139 = V_139 ;
F_125 ( & V_382 -> V_382 , V_383 ) ;
F_126 ( V_157 -> V_348 , & V_382 -> V_382 ) ;
return 0 ;
}
static void V_383 ( struct V_384 * V_382 )
{
struct V_381 * V_385 = F_41 ( V_382 , struct V_381 , V_382 ) ;
struct V_138 * V_139 = V_385 -> V_139 ;
F_21 ( V_385 ) ;
F_3 ( V_13 , L_106 ,
V_139 -> V_147 , V_139 -> V_142 . V_143 ) ;
F_127 ( V_139 ) ;
F_81 ( & V_139 -> V_271 ) ;
}
static int F_127 ( struct V_138 * V_139 )
{
unsigned long V_40 ;
int V_108 = 0 ;
struct V_129 * V_6 ;
struct V_386 V_387 ;
struct V_226 * V_217 ;
T_3 V_388 ;
T_1 V_389 ;
T_1 V_390 ;
int V_391 = 0 ;
int V_392 = 0 ;
int V_393 = 0 ;
int V_394 = 0 ;
T_2 V_395 = V_396 ;
struct V_397 V_398 ;
if ( ! V_139 ) {
F_3 ( V_13 , L_107 ) ;
return - 1 ;
}
F_26 ( & V_139 -> V_141 , V_40 ) ;
V_6 = V_139 -> V_6 ;
if ( ! V_6 ) {
F_3 ( V_13 , L_108 ,
V_139 -> V_142 . V_143 ) ;
F_28 ( & V_139 -> V_141 , V_40 ) ;
return - 1 ;
}
V_217 = F_128 ( V_139 -> V_271 . V_399 ) ;
F_3 ( V_13 , L_109 , V_139 -> V_142 . V_143 ) ;
V_389 = V_139 -> V_145 ;
V_390 = V_139 -> V_149 ;
V_388 = V_139 -> V_147 ;
if ( V_139 -> V_400 ) {
V_392 = 1 ;
V_393 = 1 ;
V_139 -> V_6 = NULL ;
if ( V_139 -> V_401 == 0 ) {
V_139 -> V_401 = 1 ;
V_394 = 1 ;
}
} else if ( ( V_389 == V_402 ) ||
( ( V_390 == V_403 ) &&
( V_388 == V_404 ) ) ) {
V_392 = 1 ;
if ( V_388 == V_404 )
V_391 = - V_405 ;
}
if ( ( ( V_389 == V_146 ) ||
( V_389 == V_406 ) ||
( V_388 == V_407 ) ||
( V_388 == V_404 ) ) ) {
V_393 = 1 ;
V_139 -> V_6 = NULL ;
if ( V_139 -> V_401 == 0 ) {
V_139 -> V_401 = 1 ;
V_394 = 1 ;
}
}
F_28 ( & V_139 -> V_141 , V_40 ) ;
if ( ( V_394 ) && ( V_139 -> V_408 == 0 ) ) {
if ( V_139 -> V_409 >= V_410 )
V_395 |= V_411 ;
F_129 ( V_217 -> V_218 , V_139 , V_395 , 1 ) ;
if ( V_139 -> V_400 ) {
V_398 . V_399 = V_139 -> V_271 . V_399 ;
V_398 . V_5 = V_139 -> V_412 ;
V_398 . V_413 . V_414 = & V_139 -> V_271 ;
V_139 -> V_271 . V_415 ( & V_398 , V_139 -> V_271 . V_416 ) ;
}
}
if ( ( V_6 ) && ( V_6 -> V_415 ) ) {
if ( V_392 ) {
F_25 ( & V_417 ) ;
V_387 . V_5 = V_418 ;
V_387 . V_419 = V_391 ;
V_387 . V_420 = V_6 -> V_420 ;
V_387 . V_421 = V_6 -> V_421 ;
V_387 . V_318 = NULL ;
V_387 . V_317 = 0 ;
F_3 ( V_13 , L_110
L_111
L_112 ,
V_139 -> V_142 . V_143 , V_139 -> V_142 . V_422 ,
V_139 -> V_142 . V_423 , V_6 ,
F_20 ( & V_139 -> V_144 ) ) ;
V_108 = V_6 -> V_415 ( V_6 , & V_387 ) ;
if ( V_108 )
F_3 ( V_13 , L_113
L_114 , V_108 ) ;
}
if ( V_393 ) {
F_25 ( & V_424 ) ;
F_130 ( V_139 , 1 ) ;
V_6 -> V_425 = V_139 ;
V_387 . V_5 = V_426 ;
V_387 . V_419 = 0 ;
V_387 . V_425 = V_6 -> V_425 ;
V_387 . V_420 = V_6 -> V_420 ;
V_387 . V_421 = V_6 -> V_421 ;
V_387 . V_318 = NULL ;
V_387 . V_317 = 0 ;
V_108 = V_6 -> V_415 ( V_6 , & V_387 ) ;
if ( V_108 ) {
F_3 ( V_13 , L_115 , V_108 ) ;
}
V_6 -> V_135 ( V_6 ) ;
}
}
return 0 ;
}
static int F_130 ( struct V_138 * V_139 , int V_427 )
{
int V_108 = 0 ;
struct V_226 * V_217 ;
struct V_256 * V_218 ;
struct V_428 * V_429 ;
V_217 = F_128 ( V_139 -> V_271 . V_399 ) ;
if ( ! V_217 )
return - V_29 ;
V_218 = V_217 -> V_218 ;
V_429 = V_217 -> V_429 ;
F_3 ( V_13 , L_116 ,
F_131 ( V_217 -> V_116 ) ) ;
if ( V_139 -> V_430 ) {
V_139 -> V_430 = 0 ;
} else {
if ( V_139 -> V_431 ) {
if ( V_139 -> V_432 )
V_429 -> V_433 . V_434 ( V_139 -> V_432 ) ;
F_132 ( V_218 -> V_219 ,
V_139 -> V_317 + sizeof( struct V_27 ) ,
V_139 -> V_431 , V_139 -> V_435 ) ;
}
}
if ( V_139 -> V_3 ) {
F_3 ( V_13 , L_117 ) ;
V_157 -> V_344 -> V_436 ( V_157 , V_139 -> V_3 ) ;
}
return V_108 ;
}
int F_133 ( struct V_129 * V_6 , struct V_437 * V_438 )
{
T_6 V_439 ;
struct V_440 * V_271 ;
struct V_138 * V_139 ;
struct V_226 * V_217 ;
struct V_256 * V_218 ;
struct V_2 * V_3 ;
struct V_235 * V_441 ;
struct V_442 V_443 ;
struct V_386 V_387 ;
struct V_444 * V_445 ;
struct V_446 V_447 ;
T_2 V_448 ;
int V_108 ;
int V_289 ;
struct V_428 * V_429 ;
struct V_449 * V_450 = NULL ;
struct V_451 V_452 ;
struct V_453 * V_454 ;
T_6 V_455 ;
V_271 = F_134 ( V_6 -> V_399 , V_438 -> V_456 ) ;
if ( ! V_271 )
return - V_29 ;
V_139 = F_135 ( V_271 ) ;
V_217 = F_128 ( V_139 -> V_271 . V_399 ) ;
V_218 = V_217 -> V_218 ;
V_441 = V_218 -> V_236 ;
V_3 = (struct V_2 * ) V_6 -> V_425 ;
F_3 ( V_13 , L_118
L_119 , V_3 , V_217 , V_217 -> V_116 ,
V_217 -> V_116 -> V_457 ) ;
if ( V_215 == V_3 -> V_23 ) {
if ( V_3 -> V_213 )
F_31 ( V_3 -> V_105 , V_3 -> V_213 ) ;
F_31 ( V_3 -> V_105 , V_3 ) ;
return - V_29 ;
}
V_289 = F_106 ( 1 , & V_3 -> V_289 ) ;
if ( V_289 == V_327 ) {
F_31 ( V_3 -> V_105 , V_3 ) ;
return - V_405 ;
}
V_139 -> V_3 = ( void * ) V_3 ;
V_3 -> V_139 = V_139 ;
F_3 ( V_13 , L_120 ,
V_139 -> V_142 . V_143 , V_3 , V_115 , V_3 -> V_204 ) ;
F_25 ( & V_458 ) ;
F_3 ( V_13 , L_116 ,
F_131 ( V_217 -> V_116 ) ) ;
V_139 -> V_431 = F_136 ( V_218 -> V_219 ,
sizeof( struct V_27 ) + V_438 -> V_317 ,
& V_139 -> V_435 ) ;
if ( ! V_139 -> V_431 ) {
F_3 ( V_13 , L_121
L_122 ) ;
return - V_21 ;
}
V_139 -> V_317 = V_438 -> V_317 ;
memcpy ( V_139 -> V_431 -> V_35 , V_38 , V_37 ) ;
memcpy ( V_139 -> V_431 -> V_326 , V_438 -> V_318 ,
V_438 -> V_317 ) ;
V_139 -> V_431 -> V_30 =
F_137 ( V_438 -> V_317 ) ;
V_139 -> V_431 -> V_32 = V_33 ;
V_139 -> V_431 -> V_40 = V_322 ;
V_445 = & V_139 -> V_142 . V_459 [ 0 ] ;
if ( V_6 -> V_421 . V_460 . V_461 !=
V_6 -> V_420 . V_460 . V_461 ) {
V_439 = ( unsigned long ) V_139 ;
V_429 = V_217 -> V_429 ;
V_454 = V_139 -> V_454 ;
V_452 . V_462 = V_139 -> V_435 ;
V_452 . V_463 = V_438 -> V_317 +
sizeof( struct V_27 ) ;
V_455 = ( T_6 ) ( unsigned long ) V_139 -> V_431 ;
V_450 = V_429 -> V_433 . V_464 ( (struct V_465 * ) V_454 ,
& V_452 , 1 ,
V_466 ,
& V_455 ) ;
if ( ! V_450 ) {
F_3 ( V_13 , L_123
L_124 ,
V_3 ) ;
F_132 ( V_218 -> V_219 ,
V_139 -> V_317 + sizeof( struct V_27 ) ,
V_139 -> V_431 , V_139 -> V_435 ) ;
return - V_21 ;
}
V_450 -> V_467 = & V_454 -> V_468 ;
V_450 -> V_399 = V_454 -> V_468 . V_399 ;
V_139 -> V_432 = V_450 ;
V_439 |= V_469 >> 1 ;
F_138 ( V_445 -> V_470 ,
V_471 ,
V_439 ) ;
V_445 -> V_470 [ V_472 ] =
F_122 ( V_473 |
V_474 ) ;
V_445 -> V_470 [ V_475 ] =
F_122 ( V_438 -> V_317 +
sizeof( struct V_27 ) ) ;
F_138 ( V_445 -> V_470 ,
V_476 ,
( T_6 ) ( unsigned long ) V_139 -> V_431 ) ;
V_445 -> V_470 [ V_477 ] =
F_122 ( V_438 -> V_317 +
sizeof( struct V_27 ) ) ;
V_445 -> V_470 [ V_478 ] = V_450 -> V_479 ;
if ( V_139 -> V_480 ) {
V_139 -> V_480 = 0 ;
F_139 ( V_139 -> V_481 ) ;
}
V_139 -> V_352 -> V_482 |=
F_122 ( V_483 |
V_484 ) ;
} else {
V_139 -> V_352 -> V_482 |=
F_122 ( V_484 ) ;
}
V_139 -> V_485 = 1 ;
V_139 -> V_6 = V_6 ;
V_3 -> V_6 = V_6 ;
V_6 -> V_425 = V_139 ;
V_139 -> V_430 = 0 ;
if ( V_3 -> V_23 == V_163 )
F_3 ( V_13 , L_125 ,
V_3 ) ;
F_121 ( V_139 , V_3 ) ;
V_139 -> V_352 -> V_486 [ 0 ] =
F_140 ( F_11 ( V_6 -> V_420 . V_487 ) ) ;
V_139 -> V_352 -> V_486 [ 1 ] =
F_140 ( F_11 ( V_6 -> V_421 . V_487 ) ) ;
if ( F_80 ( V_6 -> V_421 . V_460 . V_461 ) )
V_139 -> V_352 -> V_488 =
F_122 ( F_23 ( V_217 -> V_268 ) ) ;
else
V_139 -> V_352 -> V_488 =
F_122 ( F_23 ( V_6 -> V_421 . V_460 . V_461 ) ) ;
V_139 -> V_352 -> V_359 |= F_122 (
( T_2 ) F_60 ( V_218 -> V_219 -> V_220 ) <<
V_489 ) ;
V_139 -> V_352 -> V_490 |=
F_122 ( F_73 ( V_218 ,
F_123 ( V_139 -> V_352 -> V_488 ) , NULL ,
V_250 ) << 16 ) ;
V_139 -> V_352 -> V_491 = F_122 (
V_115 - F_141 ( V_218 , V_492 ) ) ;
V_139 -> V_352 -> V_493 = F_122 ( V_139 -> V_142 . V_143 ) ;
V_139 -> V_352 -> V_482 |= F_122 (
( ( T_2 ) 1 << V_494 ) ) ;
V_139 -> V_352 -> V_482 |=
F_122 ( ( T_2 ) V_438 -> V_495 ) ;
memset ( & V_447 , 0 , sizeof( V_447 ) ) ;
V_447 . V_496 =
F_122 ( ( T_2 ) F_60 ( V_218 -> V_219 -> V_220 ) << 24 ) ;
if ( F_80 ( V_6 -> V_421 . V_460 . V_461 ) )
V_447 . V_497 = V_217 -> V_268 ;
else
V_447 . V_497 = V_6 -> V_421 . V_460 . V_461 ;
V_447 . V_498 [ 0 ] = V_6 -> V_421 . V_487 ;
V_447 . V_498 [ 1 ] = V_6 -> V_420 . V_487 ;
V_448 = F_142 ( & V_447 ) ;
V_139 -> V_499 = F_110 ( V_448 ^ 0xffffffff ) ;
F_3 ( V_13 , L_126 ,
V_139 -> V_499 , V_139 -> V_499 & V_441 -> V_500 ) ;
V_139 -> V_499 &= V_441 -> V_500 ;
V_139 -> V_352 -> V_499 = F_122 ( V_139 -> V_499 ) ;
V_3 -> V_105 -> V_344 -> V_210 ( V_3 -> V_105 , V_3 ) ;
F_3 ( V_13 , L_127
L_128
L_129 , V_139 -> V_142 . V_143 ,
F_23 ( V_6 -> V_421 . V_460 . V_461 ) ,
F_11 ( V_6 -> V_421 . V_487 ) ,
F_23 ( V_6 -> V_420 . V_460 . V_461 ) ,
F_11 ( V_6 -> V_420 . V_487 ) ,
F_123 ( V_139 -> V_352 -> V_84 ) ,
F_123 ( V_139 -> V_352 -> V_372 ) ,
V_438 -> V_317 +
sizeof( struct V_27 ) ) ;
V_6 -> V_328 ( V_6 ) ;
F_124 ( & V_139 -> V_271 ) ;
V_387 . V_5 = V_501 ;
V_387 . V_419 = 0 ;
V_387 . V_425 = ( void * ) V_139 ;
V_387 . V_420 = V_6 -> V_420 ;
V_387 . V_421 = V_6 -> V_421 ;
V_387 . V_318 = NULL ;
V_387 . V_317 = 0 ;
V_108 = V_6 -> V_415 ( V_6 , & V_387 ) ;
V_443 . V_502 = V_403 ;
F_143 ( & V_139 -> V_271 , & V_443 , V_503 , NULL ) ;
if ( V_3 -> V_213 ) {
V_3 -> V_213 -> V_17 =
V_139 -> V_317 ;
memcpy ( V_3 -> V_213 -> V_39 ,
V_139 -> V_431 -> V_326 , V_139 -> V_317 ) ;
F_1 ( V_3 -> V_213 , V_297 ) ;
}
if ( V_108 )
F_67 ( V_238 L_130
L_131 , V_239 , __LINE__ , V_108 ) ;
return 0 ;
}
int F_144 ( struct V_129 * V_6 , const void * V_504 , T_1 V_505 )
{
struct V_2 * V_3 ;
struct V_2 * V_212 ;
struct V_98 * V_105 ;
F_25 ( & V_506 ) ;
V_3 = (struct V_2 * ) V_6 -> V_425 ;
V_212 = V_3 -> V_213 ;
V_105 = V_3 -> V_105 ;
V_3 -> V_6 = V_6 ;
V_3 -> V_17 = sizeof( struct V_27 ) + V_505 ;
if ( V_3 -> V_17 > V_20 )
return - V_29 ;
memcpy ( & V_3 -> V_16 . V_35 [ 0 ] , V_38 , V_37 ) ;
if ( V_212 ) {
memcpy ( & V_212 -> V_16 . V_326 , V_504 , V_505 ) ;
V_212 -> V_16 . V_30 = V_505 ;
V_212 -> V_17 = sizeof( struct V_27 ) +
V_505 ;
} else {
memcpy ( & V_3 -> V_16 . V_326 , V_504 , V_505 ) ;
V_3 -> V_16 . V_30 = F_137 ( V_505 ) ;
}
V_3 -> V_16 . V_32 = V_33 ;
V_3 -> V_16 . V_40 = V_322 | V_41 ;
return V_105 -> V_344 -> V_507 ( V_105 , & V_3 -> V_16 , V_3 ) ;
}
int F_145 ( struct V_129 * V_6 , struct V_437 * V_438 )
{
struct V_440 * V_271 ;
struct V_138 * V_139 ;
struct V_226 * V_217 ;
struct V_256 * V_218 ;
struct V_2 * V_3 ;
struct V_252 V_8 ;
int V_267 = 0 ;
V_271 = F_134 ( V_6 -> V_399 , V_438 -> V_456 ) ;
if ( ! V_271 )
return - V_29 ;
V_139 = F_135 ( V_271 ) ;
if ( ! V_139 )
return - V_29 ;
V_217 = F_128 ( V_139 -> V_271 . V_399 ) ;
if ( ! V_217 )
return - V_29 ;
V_218 = V_217 -> V_218 ;
if ( ! V_218 )
return - V_29 ;
if ( ! ( V_6 -> V_420 . V_487 ) || ! ( V_6 -> V_421 . V_487 ) )
return - V_29 ;
F_3 ( V_13 , L_132
L_133 , V_139 -> V_142 . V_143 ,
F_23 ( V_217 -> V_268 ) ,
F_23 ( V_6 -> V_421 . V_460 . V_461 ) ,
F_11 ( V_6 -> V_421 . V_487 ) ,
F_23 ( V_6 -> V_420 . V_460 . V_461 ) ,
F_11 ( V_6 -> V_420 . V_487 ) ) ;
F_25 ( & V_508 ) ;
V_139 -> V_430 = 1 ;
V_139 -> V_6 = V_6 ;
V_6 -> V_425 = V_139 ;
V_139 -> V_317 = V_438 -> V_317 ;
V_139 -> V_352 -> V_482 |= F_122 ( ( T_2 ) V_438 -> V_495 ) ;
F_3 ( V_13 , L_134 , ( T_2 ) V_438 -> V_495 ) ;
F_3 ( V_13 , L_135 ,
V_438 -> V_317 ) ;
if ( V_6 -> V_420 . V_460 . V_461 !=
V_6 -> V_421 . V_460 . V_461 ) {
F_59 ( V_217 , F_11 ( V_6 -> V_420 . V_487 ) ,
F_60 ( V_218 -> V_219 -> V_220 ) , V_509 ) ;
V_267 = 1 ;
}
V_8 . V_10 = F_17 ( V_6 -> V_420 . V_460 . V_461 ) ;
V_8 . V_12 = F_16 ( V_6 -> V_420 . V_487 ) ;
V_8 . V_9 = F_17 ( V_6 -> V_421 . V_460 . V_461 ) ;
V_8 . V_11 = F_16 ( V_6 -> V_421 . V_487 ) ;
V_8 . V_6 = V_6 ;
V_8 . V_266 = V_510 ;
V_6 -> V_328 ( V_6 ) ;
V_3 = V_157 -> V_344 -> V_511 ( V_157 , V_217 ,
V_438 -> V_317 , ( void * ) V_438 -> V_318 ,
& V_8 ) ;
if ( ! V_3 ) {
if ( V_267 )
F_59 ( V_217 , F_11 ( V_6 -> V_420 . V_487 ) ,
F_60 ( V_218 -> V_219 -> V_220 ) ,
V_221 ) ;
V_6 -> V_135 ( V_6 ) ;
return - V_21 ;
}
V_3 -> V_267 = V_267 ;
V_139 -> V_3 = V_3 ;
V_3 -> V_139 = V_139 ;
F_124 ( & V_139 -> V_271 ) ;
return 0 ;
}
int F_146 ( struct V_129 * V_6 , int V_299 )
{
struct V_226 * V_217 ;
struct V_195 * V_3 ;
struct V_252 V_8 ;
int V_206 ;
F_3 ( V_13 , L_136 ,
V_6 , F_11 ( V_6 -> V_420 . V_487 ) ) ;
V_217 = F_128 ( V_6 -> V_399 ) ;
if ( ! V_217 )
return - V_29 ;
F_3 ( V_13 , L_137 ,
V_217 , V_217 -> V_116 , V_217 -> V_116 -> V_457 ) ;
F_3 ( V_13 , L_138 ,
V_217 -> V_268 , V_6 -> V_420 . V_460 . V_461 ) ;
V_8 . V_10 = V_217 -> V_268 ;
V_8 . V_12 = V_6 -> V_420 . V_487 ;
V_8 . V_299 = V_299 ;
V_8 . V_6 = V_6 ;
V_8 . V_266 = V_510 ;
V_3 = V_157 -> V_344 -> V_512 ( V_157 , V_217 , & V_8 ) ;
if ( ! V_3 ) {
F_67 ( V_238 L_139 ,
V_239 , __LINE__ ) ;
return - V_21 ;
}
V_6 -> V_425 = V_3 ;
if ( ! V_3 -> V_315 ) {
V_206 = F_59 ( V_217 ,
F_11 ( V_6 -> V_420 . V_487 ) ,
F_60 ( V_217 -> V_218 -> V_219 -> V_220 ) ,
V_509 ) ;
if ( V_206 ) {
F_67 ( V_238 L_140 ,
V_206 ) ;
V_157 -> V_344 -> V_513 ( V_157 , ( void * ) V_3 ) ;
return V_206 ;
}
F_25 ( & V_514 ) ;
}
V_6 -> V_328 ( V_6 ) ;
V_6 -> V_425 = ( void * ) V_3 ;
return 0 ;
}
int F_147 ( struct V_129 * V_6 )
{
if ( V_6 -> V_425 )
V_157 -> V_344 -> V_513 ( V_157 , V_6 -> V_425 ) ;
else
F_3 ( V_13 , L_141 ) ;
V_6 -> V_135 ( V_6 ) ;
return 0 ;
}
int F_148 ( struct V_14 * V_15 , struct V_234 * V_515 )
{
int V_233 = 0 ;
V_516 ++ ;
if ( ( V_157 ) && ( V_157 -> V_344 ) ) {
V_233 = V_157 -> V_344 -> V_517 ( V_157 , F_149 ( V_515 ) , V_15 ) ;
} else {
F_3 ( V_13 , L_142
L_143 ) ;
}
return V_233 ;
}
int F_150 ( void )
{
F_3 ( V_13 , L_99 ) ;
V_157 = F_112 () ;
if ( V_157 ) {
return 0 ;
} else {
return - V_21 ;
}
}
int F_151 ( void )
{
V_157 -> V_344 -> V_518 ( V_157 ) ;
return 0 ;
}
static void F_152 ( struct V_1 * V_5 )
{
T_6 V_439 ;
struct V_138 * V_139 ;
struct V_226 * V_217 ;
struct V_256 * V_218 ;
struct V_2 * V_3 ;
struct V_235 * V_236 ;
struct V_442 V_443 ;
struct V_129 * V_6 ;
struct V_386 V_387 ;
struct V_444 * V_445 ;
struct V_446 V_447 ;
T_2 V_448 ;
int V_108 ;
V_3 = V_5 -> V_3 ;
V_6 = V_3 -> V_6 ;
F_3 ( V_13 , L_144 , V_3 , V_6 ) ;
V_139 = (struct V_138 * ) V_6 -> V_425 ;
V_217 = F_128 ( V_139 -> V_271 . V_399 ) ;
V_218 = V_217 -> V_218 ;
V_236 = V_218 -> V_236 ;
if ( V_139 -> V_408 ) {
return;
}
F_25 ( & V_519 ) ;
F_3 ( V_13 , L_145
L_146 ,
V_139 -> V_142 . V_143 ,
F_23 ( V_6 -> V_421 . V_460 . V_461 ) ,
F_11 ( V_6 -> V_421 . V_487 ) ,
F_11 ( V_6 -> V_420 . V_487 ) ,
V_115 ) ;
F_121 ( V_139 , V_3 ) ;
V_139 -> V_352 -> V_486 [ 0 ] =
F_140 ( F_11 ( V_6 -> V_420 . V_487 ) ) ;
V_139 -> V_352 -> V_486 [ 1 ] =
F_140 ( F_11 ( V_6 -> V_421 . V_487 ) ) ;
if ( F_80 ( V_6 -> V_421 . V_460 . V_461 ) )
V_139 -> V_352 -> V_488 =
F_122 ( F_23 ( V_217 -> V_268 ) ) ;
else
V_139 -> V_352 -> V_488 =
F_122 ( F_23 ( V_6 -> V_421 . V_460 . V_461 ) ) ;
V_139 -> V_352 -> V_359 |= F_122 (
( T_2 ) F_60 ( V_218 -> V_219 -> V_220 ) <<
V_489 ) ;
V_139 -> V_352 -> V_490 |= F_122 (
F_73 ( V_218 ,
F_123 ( V_139 -> V_352 -> V_488 ) ,
NULL , V_250 ) << 16 ) ;
V_139 -> V_352 -> V_491 = F_122 (
V_115 - F_141 ( V_218 , V_492 ) ) ;
V_139 -> V_352 -> V_493 = F_122 ( V_139 -> V_142 . V_143 ) ;
V_139 -> V_352 -> V_482 |=
F_122 ( ( T_2 ) 1 <<
V_494 ) ;
V_139 -> V_142 . V_423 = 1 ;
#if F_153 ( V_520 )
if ( V_3 -> V_257 ) {
F_3 ( V_13 , L_147 ) ;
V_445 = & V_139 -> V_142 . V_459 [ 0 ] ;
V_439 = ( unsigned long ) V_139 ;
V_439 |= V_469 >> 1 ;
F_138 ( V_445 -> V_470 ,
V_471 , V_439 ) ;
V_445 -> V_470 [ V_472 ] =
F_122 ( V_521 ) ;
V_445 -> V_470 [ V_475 ] = 0 ;
V_445 -> V_470 [ V_476 ] = 0 ;
V_445 -> V_470 [ V_522 ] = 0 ;
V_445 -> V_470 [ V_477 ] = 0 ;
V_445 -> V_470 [ V_478 ] = 0 ;
if ( V_139 -> V_480 ) {
V_139 -> V_480 = 0 ;
F_139 ( V_139 -> V_481 ) ;
}
V_139 -> V_352 -> V_482 &=
F_122 ( ~ ( V_483 |
V_484 |
V_523 ) ) ;
V_139 -> V_485 = 1 ;
V_139 -> V_142 . V_423 = 0 ;
F_154 ( V_218 -> V_524 + V_525 ,
( 1 << 24 ) | 0x00800000 | V_139 -> V_142 . V_143 ) ;
}
#endif
memset ( & V_447 , 0 , sizeof( V_447 ) ) ;
V_447 . V_496 =
F_122 ( ( T_2 ) F_60 ( V_218 -> V_219 -> V_220 ) << 24 ) ;
if ( F_80 ( V_6 -> V_421 . V_460 . V_461 ) )
V_447 . V_497 = V_217 -> V_268 ;
else
V_447 . V_497 = V_6 -> V_421 . V_460 . V_461 ;
V_447 . V_498 [ 0 ] = V_6 -> V_421 . V_487 ;
V_447 . V_498 [ 1 ] = V_6 -> V_420 . V_487 ;
V_448 = F_142 ( & V_447 ) ;
V_139 -> V_499 = F_110 ( V_448 ^ 0xffffffff ) ;
F_3 ( V_13 , L_148 ,
V_139 -> V_499 , V_139 -> V_499 & V_236 -> V_500 ) ;
V_139 -> V_499 &= V_236 -> V_500 ;
V_139 -> V_352 -> V_499 = F_122 ( V_139 -> V_499 ) ;
V_139 -> V_431 = & V_3 -> V_16 ;
V_139 -> V_317 = ( T_1 ) V_3 -> V_17 ;
V_3 -> V_105 -> V_344 -> V_210 ( V_3 -> V_105 , V_3 ) ;
V_387 . V_5 = V_526 ;
V_387 . V_419 = 0 ;
V_387 . V_425 = V_6 -> V_425 ;
V_387 . V_420 . V_527 = V_528 ;
V_387 . V_420 . V_487 = V_6 -> V_420 . V_487 ;
V_387 . V_421 = V_6 -> V_421 ;
V_387 . V_318 = ( void * ) V_5 -> V_3 -> V_39 ;
V_387 . V_317 = ( T_1 ) V_5 -> V_3 -> V_17 ;
V_387 . V_420 . V_460 . V_461 = V_5 -> V_8 . V_9 ;
V_108 = V_6 -> V_415 ( V_6 , & V_387 ) ;
F_3 ( V_13 , L_115 , V_108 ) ;
if ( V_108 )
F_67 ( V_238 L_130
L_131 , V_239 , __LINE__ , V_108 ) ;
V_443 . V_502 = V_403 ;
F_143 ( & V_139 -> V_271 , & V_443 , V_503 , NULL ) ;
F_3 ( V_13 , L_149
L_150 , V_139 -> V_142 . V_143 , V_115 ) ;
return;
}
static void F_55 ( struct V_1 * V_5 )
{
struct V_138 * V_139 ;
struct V_129 * V_6 ;
struct V_386 V_387 ;
int V_108 ;
if ( ! V_5 -> V_3 )
return;
V_6 = V_5 -> V_3 -> V_6 ;
if ( ! V_6 ) {
return;
}
F_3 ( V_13 , L_151 , V_5 -> V_3 , V_6 ) ;
V_139 = V_6 -> V_425 ;
if ( ! V_139 ) {
return;
}
V_139 -> V_6 = NULL ;
V_6 -> V_425 = NULL ;
V_387 . V_5 = V_526 ;
V_387 . V_419 = - V_405 ;
V_387 . V_425 = V_6 -> V_425 ;
V_387 . V_420 = V_6 -> V_420 ;
V_387 . V_421 = V_6 -> V_421 ;
V_387 . V_318 = NULL ;
V_387 . V_317 = 0 ;
F_3 ( V_13 , L_152
L_153 , V_387 . V_420 . V_460 . V_461 ,
V_387 . V_421 . V_460 . V_461 ) ;
V_108 = V_6 -> V_415 ( V_6 , & V_387 ) ;
F_3 ( V_13 , L_115 , V_108 ) ;
if ( V_108 )
F_67 ( V_238 L_130
L_131 , V_239 , __LINE__ , V_108 ) ;
V_6 -> V_135 ( V_6 ) ;
F_31 ( V_5 -> V_3 -> V_105 , V_5 -> V_3 ) ;
return;
}
static void F_155 ( struct V_1 * V_5 )
{
struct V_138 * V_139 ;
struct V_129 * V_6 ;
struct V_386 V_387 ;
int V_108 ;
if ( ! V_5 -> V_3 )
return;
if ( ! V_5 -> V_3 -> V_6 )
return;
V_6 = V_5 -> V_3 -> V_6 ;
F_3 ( V_13 , L_154 , V_5 -> V_3 , V_6 ) ;
V_139 = V_6 -> V_425 ;
if ( ! V_139 )
return;
V_139 -> V_6 = NULL ;
V_387 . V_5 = V_418 ;
V_387 . V_419 = - V_405 ;
V_387 . V_425 = V_6 -> V_425 ;
V_387 . V_420 = V_6 -> V_420 ;
V_387 . V_421 = V_6 -> V_421 ;
V_387 . V_318 = NULL ;
V_387 . V_317 = 0 ;
V_6 -> V_328 ( V_6 ) ;
V_108 = V_6 -> V_415 ( V_6 , & V_387 ) ;
F_25 ( & V_424 ) ;
V_387 . V_5 = V_426 ;
V_387 . V_419 = 0 ;
V_387 . V_425 = V_6 -> V_425 ;
V_387 . V_420 = V_6 -> V_420 ;
V_387 . V_421 = V_6 -> V_421 ;
V_387 . V_318 = NULL ;
V_387 . V_317 = 0 ;
F_3 ( V_13 , L_155 , V_5 -> V_3 ) ;
V_108 = V_6 -> V_415 ( V_6 , & V_387 ) ;
F_3 ( V_13 , L_115 , V_108 ) ;
V_6 -> V_135 ( V_6 ) ;
return;
}
static void F_156 ( struct V_1 * V_5 )
{
struct V_129 * V_6 ;
struct V_386 V_387 ;
int V_108 ;
struct V_2 * V_3 ;
V_3 = V_5 -> V_3 ;
if ( ! V_3 )
return;
V_6 = V_3 -> V_6 ;
F_25 ( & V_529 ) ;
F_3 ( V_13 , L_156 ,
V_3 , V_6 , V_115 ) ;
V_387 . V_5 = V_530 ;
V_387 . V_419 = 0 ;
V_387 . V_425 = ( void * ) V_3 ;
V_387 . V_420 . V_527 = V_528 ;
V_387 . V_420 . V_487 = F_16 ( V_5 -> V_8 . V_12 ) ;
V_387 . V_420 . V_460 . V_461 = F_17 ( V_5 -> V_8 . V_10 ) ;
V_387 . V_421 . V_527 = V_528 ;
V_387 . V_421 . V_487 = F_16 ( V_5 -> V_8 . V_11 ) ;
V_387 . V_421 . V_460 . V_461 = F_17 ( V_5 -> V_8 . V_9 ) ;
V_387 . V_318 = V_3 -> V_39 ;
V_387 . V_317 = ( T_1 ) V_3 -> V_17 ;
V_108 = V_6 -> V_415 ( V_6 , & V_387 ) ;
if ( V_108 )
F_67 ( V_238 L_157 ,
V_239 , __LINE__ , V_108 ) ;
return;
}
static void F_107 ( struct V_1 * V_5 )
{
struct V_129 * V_6 ;
struct V_386 V_387 ;
struct V_2 * V_3 ;
int V_108 ;
V_3 = V_5 -> V_3 ;
if ( ! V_3 )
return;
V_6 = V_3 -> V_6 ;
F_25 ( & V_529 ) ;
F_3 ( V_13 , L_156 ,
V_3 , V_6 , V_115 ) ;
V_387 . V_5 = V_526 ;
V_387 . V_419 = - V_531 ;
V_387 . V_425 = V_6 -> V_425 ;
V_387 . V_420 . V_527 = V_528 ;
V_387 . V_420 . V_487 = F_16 ( V_5 -> V_8 . V_12 ) ;
V_387 . V_420 . V_460 . V_461 = F_17 ( V_5 -> V_8 . V_10 ) ;
V_387 . V_421 . V_527 = V_528 ;
V_387 . V_421 . V_487 = F_16 ( V_5 -> V_8 . V_11 ) ;
V_387 . V_421 . V_460 . V_461 = F_17 ( V_5 -> V_8 . V_9 ) ;
V_387 . V_318 = V_3 -> V_39 ;
V_387 . V_317 = ( T_1 ) V_3 -> V_17 ;
F_3 ( V_13 , L_158
L_153 ,
V_387 . V_420 . V_460 . V_461 ,
V_387 . V_421 . V_460 . V_461 ) ;
V_108 = V_6 -> V_415 ( V_6 , & V_387 ) ;
if ( V_108 )
F_67 ( V_238 L_157 ,
V_239 , __LINE__ , V_108 ) ;
return;
}
static int F_4 ( struct V_1 * V_5 )
{
F_25 ( & V_5 -> V_3 -> V_105 -> V_343 ) ;
F_27 ( V_5 -> V_3 ) ;
V_5 -> V_8 . V_6 -> V_328 ( V_5 -> V_8 . V_6 ) ;
F_125 ( & V_5 -> V_532 , V_533 ) ;
F_3 ( V_13 , L_159 ,
V_5 -> V_3 , V_5 ) ;
F_126 ( V_5 -> V_3 -> V_105 -> V_346 , & V_5 -> V_532 ) ;
F_3 ( V_13 , L_160 ) ;
return 0 ;
}
static void V_533 ( struct V_384 * V_382 )
{
struct V_1 * V_5 = F_41 ( V_382 , struct V_1 ,
V_532 ) ;
struct V_98 * V_105 ;
if ( ( ! V_5 ) || ( ! V_5 -> V_3 ) || ( ! V_5 -> V_3 -> V_105 ) )
return;
V_105 = V_5 -> V_3 -> V_105 ;
F_3 ( V_13 , L_161 ,
V_5 , V_5 -> type , F_20 ( & V_105 -> V_343 ) ) ;
switch ( V_5 -> type ) {
case V_294 :
F_156 ( V_5 ) ;
F_3 ( V_13 , L_162 ,
V_5 -> V_3 ) ;
break;
case V_534 :
F_3 ( V_13 , L_163 ,
V_5 -> V_3 ) ;
F_155 ( V_5 ) ;
break;
case V_297 :
if ( ( ! V_5 -> V_3 -> V_6 ) ||
( V_5 -> V_3 -> V_23 != V_163 ) )
break;
F_152 ( V_5 ) ;
F_3 ( V_13 , L_164 ) ;
break;
case V_296 :
if ( ( ! V_5 -> V_3 -> V_6 ) ||
( V_5 -> V_3 -> V_23 == V_163 ) )
break;
F_107 ( V_5 ) ;
F_3 ( V_13 , L_165 ) ;
break;
case V_136 :
if ( ( ! V_5 -> V_3 -> V_6 ) ||
( V_5 -> V_3 -> V_23 == V_163 ) )
break;
F_55 ( V_5 ) ;
F_3 ( V_13 , L_166 ) ;
break;
case V_535 :
F_3 ( V_13 , L_167 ) ;
break;
default:
F_3 ( V_13 , L_168 ) ;
break;
}
F_58 ( & V_105 -> V_343 ) ;
V_5 -> V_8 . V_6 -> V_135 ( V_5 -> V_8 . V_6 ) ;
F_31 ( V_105 , V_5 -> V_3 ) ;
F_21 ( V_5 ) ;
return;
}
