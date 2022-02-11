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
F_2 ( ! V_14 || ! V_15 || ! V_16 ) ;
V_17 = V_14 -> V_19 -> V_20 ;
V_18 = V_14 -> V_19 -> V_18 ;
* V_16 = false ;
if ( ( V_17 > 1 ) ||
V_18 > V_21 * V_22 ) {
* V_16 = true ;
F_5 ( L_1 ) ;
}
* V_15 = V_17 * sizeof( struct V_23 ) +
V_18 * sizeof( struct V_24 ) ;
if ( * V_16 )
* V_15 += sizeof( struct V_25 ) ;
F_5 ( L_2 , * V_15 ) ;
}
static int F_6 ( struct V_13 * V_14 ,
unsigned int * * V_26 ,
T_2 * V_27 ,
unsigned int * V_28 ,
bool * V_29 )
{
int V_30 ;
F_2 ( ! V_14 ) ;
F_2 ( V_14 -> V_31 == true ) ;
F_2 ( V_29 == NULL ) ;
F_4 ( V_14 , V_28 , V_29 ) ;
V_30 = V_32 -> V_33 ( V_14 -> V_19 -> V_34 -> V_35 ,
* V_28 ,
V_36 ,
V_37 ,
(struct V_38 * * ) & V_14 -> V_39 ) ;
if ( V_30 != 0 ) {
F_7 ( L_3 ) ;
return V_30 ;
}
* ( void * * ) V_26 = V_14 -> V_39 -> V_40 ;
* V_27 = V_14 -> V_39 -> V_41 ;
memset ( * V_26 , 0 , * V_28 ) ;
V_14 -> V_31 = true ;
return V_30 ;
}
static int F_8 ( struct V_13 * V_14 , V_5 * V_42 ,
T_2 V_43 , T_1 V_44 , bool V_45 )
{
struct V_25 * V_46 ;
F_2 ( ! V_14 || ! V_42 || ! V_43 ) ;
V_46 = (struct V_25 * ) V_42 ;
memset ( V_42 , 0 , sizeof( struct V_25 ) ) ;
V_46 -> V_9 . V_10 = F_3 ( V_47 ,
sizeof( struct V_25 ) ) ;
V_46 -> V_48 . V_49 = V_44 ;
V_46 -> V_48 . V_45 = V_45 ? 1 : 0 ;
V_46 -> V_48 . V_50 = 0 ;
V_46 -> V_48 . V_51 = 1 ;
V_46 -> V_52 = F_9 ( V_43 ) ;
V_46 -> V_53 . V_54 = F_10 ( V_43 ) ;
return 0 ;
}
static int F_11 ( struct V_13 * V_14 , V_5 * V_42 ,
struct V_55 * V_56 )
{
struct V_23 * V_46 ;
struct V_57 * V_58 ;
V_5 V_59 ;
F_2 ( ! V_14 || ! V_42 || ! V_56 ) ;
V_46 = (struct V_23 * ) V_42 ;
F_5 ( L_4 , V_60 ) ;
memset ( V_42 , 0 , sizeof( struct V_23 ) ) ;
V_46 -> V_9 . V_10 = F_3 ( V_61 ,
sizeof( struct V_23 ) ) ;
V_46 -> V_62 . V_63 = ( V_56 -> V_64 ) ? 1 : 0 ;
V_46 -> V_62 . V_65 = 1 ;
V_46 -> V_62 . V_66 = V_56 -> V_67 -> V_68 -> V_66 ;
V_46 -> V_53 . V_69 = V_56 -> V_69 ;
V_46 -> V_70 . V_71 = V_56 -> V_71 ;
V_46 -> V_70 . V_72 = V_56 -> V_72 ;
V_46 -> V_70 . V_73 = V_56 -> V_73 ;
V_59 = 0 ;
F_12 (cur, &qpd->queues_list, list)
V_59 ++ ;
V_46 -> V_70 . V_59 = V_59 ;
V_46 -> V_74 = V_56 -> V_74 ;
V_46 -> V_75 = V_56 -> V_75 ;
V_46 -> V_76 = V_56 -> V_76 ;
V_46 -> V_77 = V_56 -> V_77 ;
V_46 -> V_78 = F_9 ( V_56 -> V_79 ) ;
V_46 -> V_80 = F_10 ( V_56 -> V_79 ) ;
return 0 ;
}
static int F_13 ( struct V_13 * V_14 , V_5 * V_42 ,
struct V_57 * V_81 )
{
struct V_24 * V_46 ;
F_2 ( ! V_14 || ! V_42 || ! V_81 ) ;
F_5 ( L_4 , V_60 ) ;
V_46 = (struct V_24 * ) V_42 ;
memset ( V_42 , 0 , sizeof( struct V_24 ) ) ;
V_46 -> V_9 . V_10 = F_3 ( V_82 ,
sizeof( struct V_24 ) ) ;
V_46 -> V_62 . V_83 =
V_84 ;
V_46 -> V_62 . V_59 = 1 ;
V_46 -> V_62 . V_85 =
V_86 ;
V_46 -> V_62 . V_87 = ( V_81 -> V_88 . V_89 ) ?
V_90 :
V_91 ;
switch ( V_81 -> V_88 . type ) {
case V_92 :
case V_93 :
V_46 -> V_62 . V_94 =
V_95 ;
break;
case V_96 :
V_46 -> V_62 . V_94 =
V_97 ;
break;
default:
F_14 () ;
break;
}
V_46 -> V_98 [ 0 ] . V_53 . V_99 =
V_81 -> V_88 . V_100 ;
V_46 -> V_98 [ 0 ] . V_101 =
F_9 ( V_81 -> V_102 ) ;
V_46 -> V_98 [ 0 ] . V_103 =
F_10 ( V_81 -> V_102 ) ;
V_46 -> V_98 [ 0 ] . V_104 =
F_9 ( ( T_2 ) V_81 -> V_88 . V_105 ) ;
V_46 -> V_98 [ 0 ] . V_106 =
F_10 ( ( T_2 ) V_81 -> V_88 . V_105 ) ;
return 0 ;
}
static int F_15 ( struct V_13 * V_14 ,
struct V_107 * V_108 ,
T_2 * V_109 ,
T_1 * V_110 )
{
unsigned int V_111 ;
unsigned int * V_26 , V_112 , V_113 ;
int V_30 , V_114 ;
struct V_115 * V_58 ;
struct V_55 * V_56 ;
struct V_57 * V_81 ;
struct V_116 * V_117 ;
bool V_29 ;
F_2 ( ! V_14 || ! V_108 || ! V_110 || ! V_109 ) ;
V_112 = V_30 = V_114 = 0 ;
V_30 = F_6 ( V_14 , & V_26 , V_109 ,
& V_111 , & V_29 ) ;
if ( V_30 != 0 )
return V_30 ;
* V_110 = V_111 ;
F_5 ( L_4 , V_60 ) ;
F_5 ( L_5 ,
V_14 -> V_19 -> V_20 , V_14 -> V_19 -> V_18 ) ;
F_12 (cur, queues, list) {
V_56 = V_58 -> V_56 ;
if ( V_114 >= V_14 -> V_19 -> V_20 ) {
F_5 ( L_6 ) ;
F_16 ( V_14 ) ;
return - V_118 ;
}
V_30 = F_11 ( V_14 , & V_26 [ V_112 ] , V_56 ) ;
if ( V_30 != 0 )
return V_30 ;
V_114 ++ ;
F_1 ( & V_112 , sizeof( struct V_23 ) ,
V_111 ) ;
F_12 (kq, &qpd->priv_queue_list, list) {
if ( V_117 -> V_57 -> V_88 . V_119 != true )
continue;
V_30 = F_13 ( V_14 , & V_26 [ V_112 ] ,
V_117 -> V_57 ) ;
if ( V_30 != 0 )
return V_30 ;
F_1 ( & V_112 , sizeof( struct V_24 ) ,
V_111 ) ;
}
F_12 (q, &qpd->queues_list, list) {
if ( V_81 -> V_88 . V_119 != true )
continue;
V_30 = F_13 ( V_14 ,
& V_26 [ V_112 ] , V_81 ) ;
if ( V_30 != 0 )
return V_30 ;
F_1 ( & V_112 , sizeof( struct V_24 ) ,
V_111 ) ;
}
}
F_5 ( L_7 ) ;
if ( V_29 )
F_8 ( V_14 , & V_26 [ V_112 ] , * V_109 ,
V_111 / sizeof( V_5 ) , true ) ;
for ( V_113 = 0 ; V_113 < V_111 / sizeof( V_5 ) ; V_113 ++ )
F_5 ( L_8 , V_26 [ V_113 ] ) ;
F_5 ( L_9 ) ;
return 0 ;
}
int F_17 ( struct V_13 * V_14 , struct V_120 * V_19 )
{
F_2 ( ! V_19 ) ;
V_14 -> V_19 = V_19 ;
F_18 ( & V_14 -> V_121 ) ;
V_14 -> V_122 = F_19 ( V_19 -> V_34 , V_123 ) ;
if ( V_14 -> V_122 == NULL ) {
F_20 ( & V_14 -> V_121 ) ;
return - V_118 ;
}
V_14 -> V_31 = false ;
return 0 ;
}
void F_21 ( struct V_13 * V_14 )
{
F_2 ( ! V_14 ) ;
F_20 ( & V_14 -> V_121 ) ;
F_22 ( V_14 -> V_122 ) ;
}
int F_23 ( struct V_13 * V_14 ,
struct V_124 * V_125 )
{
struct V_126 * V_46 ;
F_2 ( ! V_14 || ! V_125 ) ;
F_5 ( L_4 , V_60 ) ;
F_24 ( & V_14 -> V_121 ) ;
V_14 -> V_122 -> V_127 ( V_14 -> V_122 ,
sizeof( * V_46 ) / sizeof( V_5 ) ,
( unsigned int * * ) & V_46 ) ;
if ( V_46 == NULL ) {
F_25 ( & V_14 -> V_121 ) ;
F_7 ( L_10 ) ;
return - V_118 ;
}
memset ( V_46 , 0 , sizeof( struct V_126 ) ) ;
V_46 -> V_9 . V_10 = F_3 ( V_128 ,
sizeof( struct V_126 ) ) ;
V_46 -> V_62 . V_129 =
V_130 ;
V_46 -> V_62 . V_131 = V_125 -> V_131 ;
V_46 -> V_62 . V_132 = V_133 ;
V_46 -> V_134 . V_135 = V_125 -> V_135 ;
V_46 -> V_136 . V_137 = V_125 -> V_137 ;
V_46 -> V_136 . V_138 = V_125 -> V_138 ;
V_46 -> V_139 = F_9 ( V_125 -> V_140 ) ;
V_46 -> V_141 = F_10 ( V_125 -> V_140 ) ;
V_46 -> V_142 = F_9 ( V_125 -> V_143 ) ;
V_46 -> V_144 = F_10 ( V_125 -> V_143 ) ;
V_14 -> V_122 -> V_145 ( V_14 -> V_122 ) ;
V_14 -> V_122 -> V_146 ( V_14 -> V_122 , V_147 ) ;
F_25 ( & V_14 -> V_121 ) ;
return 0 ;
}
int F_26 ( struct V_13 * V_14 , struct V_107 * V_148 )
{
T_2 V_149 ;
V_5 * V_26 ;
T_1 V_150 , V_151 ;
int V_30 ;
F_2 ( ! V_14 || ! V_148 ) ;
V_30 = F_15 ( V_14 , V_148 , & V_149 ,
& V_150 ) ;
if ( V_30 != 0 )
goto V_152;
F_5 ( L_11 , V_149 ) ;
V_151 = sizeof( struct V_25 ) / sizeof( V_5 ) ;
F_24 ( & V_14 -> V_121 ) ;
V_30 = V_14 -> V_122 -> V_127 ( V_14 -> V_122 ,
V_151 , & V_26 ) ;
if ( V_30 != 0 )
goto V_153;
V_30 = F_8 ( V_14 , V_26 , V_149 ,
V_150 / sizeof( V_5 ) , false ) ;
if ( V_30 != 0 )
goto V_154;
V_14 -> V_122 -> V_145 ( V_14 -> V_122 ) ;
V_14 -> V_122 -> V_146 ( V_14 -> V_122 , V_147 ) ;
F_25 ( & V_14 -> V_121 ) ;
return V_30 ;
V_154:
V_14 -> V_122 -> V_155 ( V_14 -> V_122 ) ;
V_153:
F_25 ( & V_14 -> V_121 ) ;
V_152:
if ( V_14 -> V_31 == true )
F_16 ( V_14 ) ;
return V_30 ;
}
int F_27 ( struct V_13 * V_14 , T_2 V_156 ,
V_5 V_157 )
{
int V_30 ;
struct V_158 * V_46 ;
F_2 ( ! V_14 || ! V_156 ) ;
F_24 ( & V_14 -> V_121 ) ;
V_30 = V_14 -> V_122 -> V_127 (
V_14 -> V_122 ,
sizeof( struct V_158 ) / sizeof( V_5 ) ,
( unsigned int * * ) & V_46 ) ;
if ( V_30 != 0 )
goto V_153;
V_46 -> V_9 . V_10 = F_3 ( V_159 ,
sizeof( struct V_158 ) ) ;
V_46 -> V_62 . V_160 = 0 ;
V_46 -> V_62 . V_161 =
V_162 ;
V_46 -> V_62 . V_163 =
V_164 ;
V_46 -> V_165 = F_10 ( ( T_2 ) V_156 ) ;
V_46 -> V_166 = F_9 ( ( T_2 ) V_156 ) ;
V_46 -> V_167 = F_10 ( ( T_2 ) V_157 ) ;
V_46 -> V_168 = F_9 ( ( T_2 ) V_157 ) ;
V_14 -> V_122 -> V_145 ( V_14 -> V_122 ) ;
V_14 -> V_122 -> V_146 ( V_14 -> V_122 , V_147 ) ;
F_25 ( & V_14 -> V_121 ) ;
return 0 ;
V_153:
F_25 ( & V_14 -> V_121 ) ;
return V_30 ;
}
int F_28 ( struct V_13 * V_14 , enum V_169 type ,
enum V_170 V_171 ,
V_5 V_172 , bool V_173 ,
unsigned int V_174 )
{
int V_30 ;
V_5 * V_42 ;
struct V_175 * V_46 ;
F_2 ( ! V_14 ) ;
F_24 ( & V_14 -> V_121 ) ;
V_30 = V_14 -> V_122 -> V_127 (
V_14 -> V_122 ,
sizeof( struct V_175 ) / sizeof( V_5 ) ,
& V_42 ) ;
if ( V_30 != 0 )
goto V_176;
V_46 = (struct V_175 * ) V_42 ;
memset ( V_42 , 0 , sizeof( struct V_175 ) ) ;
V_46 -> V_9 . V_10 = F_3 ( V_177 ,
sizeof( struct V_175 ) ) ;
switch ( type ) {
case V_92 :
case V_93 :
V_46 -> V_62 . V_94 =
V_178 ;
break;
case V_96 :
V_46 -> V_62 . V_94 =
V_179 + V_174 ;
break;
default:
F_14 () ;
break;
}
if ( V_173 )
V_46 -> V_62 . V_180 =
V_181 ;
else
V_46 -> V_62 . V_180 =
V_182 ;
switch ( V_171 ) {
case V_183 :
V_46 -> V_62 . V_85 =
V_184 ;
V_46 -> V_62 . V_59 = 1 ;
V_46 -> V_185 . V_186 = V_172 ;
break;
case V_187 :
V_46 -> V_62 . V_85 =
V_188 ;
V_46 -> V_189 . V_66 = V_172 ;
break;
case V_190 :
V_46 -> V_62 . V_85 =
V_191 ;
break;
default:
F_14 () ;
break;
} ;
V_14 -> V_122 -> V_145 ( V_14 -> V_122 ) ;
V_14 -> V_122 -> V_146 ( V_14 -> V_122 , V_147 ) ;
F_25 ( & V_14 -> V_121 ) ;
return 0 ;
V_176:
F_25 ( & V_14 -> V_121 ) ;
return V_30 ;
}
void F_16 ( struct V_13 * V_14 )
{
F_2 ( ! V_14 ) ;
F_24 ( & V_14 -> V_121 ) ;
if ( V_14 -> V_31 ) {
V_32 -> V_192 ( V_14 -> V_19 -> V_34 -> V_35 ,
(struct V_38 * ) V_14 -> V_39 ) ;
V_14 -> V_31 = false ;
}
F_25 ( & V_14 -> V_121 ) ;
}
