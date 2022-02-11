static inline void F_1 ( unsigned int * V_1 , unsigned int V_2 ,
unsigned int V_3 )
{
unsigned int V_4 = * V_1 + V_2 / sizeof( V_5 ) ;
F_2 ( ( V_4 * sizeof( V_5 ) ) > V_3 ,
L_1 ) ;
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
V_17 = V_14 -> V_20 -> V_21 ;
V_18 = V_14 -> V_20 -> V_18 ;
* V_16 = false ;
if ( ( V_17 > 1 ) || V_18 > F_5 ( V_14 -> V_20 ) ) {
* V_16 = true ;
F_6 ( L_2 ) ;
}
V_19 = sizeof( struct V_22 ) ;
* V_15 = V_17 * sizeof( struct V_23 ) +
V_18 * V_19 ;
if ( * V_16 )
* V_15 += sizeof( struct V_24 ) ;
F_6 ( L_3 , * V_15 ) ;
}
static int F_7 ( struct V_13 * V_14 ,
unsigned int * * V_25 ,
T_2 * V_26 ,
unsigned int * V_27 ,
bool * V_28 )
{
int V_29 ;
if ( F_8 ( V_14 -> V_30 ) )
return - V_31 ;
F_4 ( V_14 , V_27 , V_28 ) ;
V_29 = F_9 ( V_14 -> V_20 -> V_32 , * V_27 ,
& V_14 -> V_33 ) ;
if ( V_29 ) {
F_10 ( L_4 ) ;
return V_29 ;
}
* ( void * * ) V_25 = V_14 -> V_33 -> V_34 ;
* V_26 = V_14 -> V_33 -> V_35 ;
memset ( * V_25 , 0 , * V_27 ) ;
V_14 -> V_30 = true ;
return V_29 ;
}
static int F_11 ( struct V_13 * V_14 , V_5 * V_36 ,
T_2 V_37 , T_1 V_38 , bool V_39 )
{
struct V_24 * V_40 ;
if ( F_8 ( ! V_37 ) )
return - V_41 ;
V_40 = (struct V_24 * ) V_36 ;
memset ( V_36 , 0 , sizeof( struct V_24 ) ) ;
V_40 -> V_9 . V_10 = F_3 ( V_42 ,
sizeof( struct V_24 ) ) ;
V_40 -> V_43 . V_44 = V_38 ;
V_40 -> V_43 . V_39 = V_39 ? 1 : 0 ;
V_40 -> V_43 . V_45 = 0 ;
V_40 -> V_43 . V_46 = 1 ;
V_40 -> V_47 = F_12 ( V_37 ) ;
V_40 -> V_48 . V_49 = F_13 ( V_37 ) ;
return 0 ;
}
static int F_14 ( struct V_13 * V_14 , V_5 * V_36 ,
struct V_50 * V_51 )
{
struct V_23 * V_40 ;
struct V_52 * V_53 ;
V_5 V_54 ;
V_40 = (struct V_23 * ) V_36 ;
memset ( V_36 , 0 , sizeof( struct V_23 ) ) ;
V_40 -> V_9 . V_10 = F_3 ( V_55 ,
sizeof( struct V_23 ) ) ;
V_40 -> V_56 . V_57 = ( V_51 -> V_58 ) ? 1 : 0 ;
V_40 -> V_56 . V_59 = 1 ;
V_40 -> V_56 . V_60 = V_51 -> V_61 -> V_62 -> V_60 ;
V_40 -> V_48 . V_63 = V_51 -> V_63 ;
V_40 -> V_64 . V_65 = V_51 -> V_65 ;
V_40 -> V_64 . V_66 = V_51 -> V_66 ;
V_40 -> V_64 . V_67 = V_51 -> V_67 ;
V_54 = 0 ;
F_15 (cur, &qpd->queues_list, list)
V_54 ++ ;
V_40 -> V_64 . V_54 = ( V_51 -> V_58 ) ? 0 : V_54 ;
V_40 -> V_68 = V_51 -> V_68 ;
V_40 -> V_69 = V_51 -> V_69 ;
V_40 -> V_70 = V_51 -> V_70 ;
V_40 -> V_71 = V_51 -> V_71 ;
V_40 -> V_72 = 0 ;
V_40 -> V_73 = F_12 ( V_51 -> V_74 ) ;
V_40 -> V_75 = F_13 ( V_51 -> V_74 ) ;
return 0 ;
}
static int F_16 ( struct V_13 * V_14 , V_5 * V_36 ,
struct V_52 * V_76 , bool V_77 )
{
struct V_22 * V_40 ;
bool V_78 = V_77 ;
V_40 = (struct V_22 * ) V_36 ;
memset ( V_36 , 0 , sizeof( struct V_22 ) ) ;
V_40 -> V_9 . V_10 = F_3 ( V_79 ,
sizeof( struct V_22 ) ) ;
V_40 -> V_56 . V_80 =
V_81 ;
V_40 -> V_56 . V_54 = 1 ;
V_40 -> V_56 . V_82 =
V_83 ;
V_40 -> V_56 . V_84 =
V_85 ;
V_40 -> V_56 . V_86 =
V_87 ;
switch ( V_76 -> V_88 . type ) {
case V_89 :
if ( V_78 )
V_40 -> V_56 . V_86 =
V_90 ;
break;
case V_91 :
V_40 -> V_56 . V_86 =
V_92 ;
break;
case V_93 :
V_40 -> V_56 . V_84 =
V_94 ;
V_78 = false ;
break;
default:
F_2 ( 1 , L_5 , V_76 -> V_88 . type ) ;
return - V_31 ;
}
V_40 -> V_48 . V_95 =
V_76 -> V_88 . V_96 ;
V_40 -> V_97 =
F_12 ( V_76 -> V_98 ) ;
V_40 -> V_99 =
F_13 ( V_76 -> V_98 ) ;
V_40 -> V_100 =
F_12 ( ( T_2 ) V_76 -> V_88 . V_101 ) ;
V_40 -> V_102 =
F_13 ( ( T_2 ) V_76 -> V_88 . V_101 ) ;
return 0 ;
}
static int F_17 ( struct V_13 * V_14 ,
struct V_103 * V_104 ,
T_2 * V_105 ,
T_1 * V_106 )
{
unsigned int V_107 ;
unsigned int * V_25 , V_108 , V_109 ;
int V_29 , V_110 ;
struct V_111 * V_53 ;
struct V_50 * V_51 ;
struct V_52 * V_76 ;
struct V_112 * V_113 ;
bool V_28 ;
V_108 = V_29 = V_110 = 0 ;
V_29 = F_7 ( V_14 , & V_25 , V_105 ,
& V_107 , & V_28 ) ;
if ( V_29 )
return V_29 ;
* V_106 = V_107 ;
F_6 ( L_6 ,
V_14 -> V_20 -> V_21 , V_14 -> V_20 -> V_18 ) ;
F_15 (cur, queues, list) {
V_51 = V_53 -> V_51 ;
if ( V_110 >= V_14 -> V_20 -> V_21 ) {
F_6 ( L_7 ) ;
F_18 ( V_14 ) ;
return - V_114 ;
}
V_29 = F_14 ( V_14 , & V_25 [ V_108 ] , V_51 ) ;
if ( V_29 )
return V_29 ;
V_110 ++ ;
F_1 ( & V_108 , sizeof( struct V_23 ) ,
V_107 ) ;
F_15 (kq, &qpd->priv_queue_list, list) {
if ( ! V_113 -> V_52 -> V_88 . V_115 )
continue;
F_6 ( L_8 ,
V_113 -> V_52 -> V_52 , V_51 -> V_58 ) ;
V_29 = F_16 ( V_14 ,
& V_25 [ V_108 ] ,
V_113 -> V_52 ,
V_51 -> V_58 ) ;
if ( V_29 )
return V_29 ;
F_1 ( & V_108 ,
sizeof( struct V_22 ) ,
V_107 ) ;
}
F_15 (q, &qpd->queues_list, list) {
if ( ! V_76 -> V_88 . V_115 )
continue;
F_6 ( L_9 ,
V_76 -> V_52 , V_51 -> V_58 ) ;
V_29 = F_16 ( V_14 ,
& V_25 [ V_108 ] ,
V_76 ,
V_51 -> V_58 ) ;
if ( V_29 )
return V_29 ;
F_1 ( & V_108 ,
sizeof( struct V_22 ) ,
V_107 ) ;
}
}
F_6 ( L_10 ) ;
if ( V_28 )
V_29 = F_11 ( V_14 , & V_25 [ V_108 ] ,
* V_105 ,
V_107 / sizeof( V_5 ) ,
true ) ;
for ( V_109 = 0 ; V_109 < V_107 / sizeof( V_5 ) ; V_109 ++ )
F_6 ( L_11 , V_25 [ V_109 ] ) ;
F_6 ( L_12 ) ;
return V_29 ;
}
int F_19 ( struct V_13 * V_14 , struct V_116 * V_20 )
{
V_14 -> V_20 = V_20 ;
F_20 ( & V_14 -> V_117 ) ;
V_14 -> V_118 = F_21 ( V_20 -> V_32 , V_119 ) ;
if ( ! V_14 -> V_118 ) {
F_22 ( & V_14 -> V_117 ) ;
return - V_114 ;
}
V_14 -> V_30 = false ;
return 0 ;
}
void F_23 ( struct V_13 * V_14 )
{
F_22 ( & V_14 -> V_117 ) ;
F_24 ( V_14 -> V_118 ) ;
}
int F_25 ( struct V_13 * V_14 ,
struct V_120 * V_121 )
{
struct V_122 * V_40 ;
int V_29 = 0 ;
F_26 ( & V_14 -> V_117 ) ;
V_14 -> V_118 -> V_123 . V_124 ( V_14 -> V_118 ,
sizeof( * V_40 ) / sizeof( V_5 ) ,
( unsigned int * * ) & V_40 ) ;
if ( ! V_40 ) {
F_10 ( L_13 ) ;
V_29 = - V_114 ;
goto V_125;
}
memset ( V_40 , 0 , sizeof( struct V_122 ) ) ;
V_40 -> V_9 . V_10 = F_3 ( V_126 ,
sizeof( struct V_122 ) ) ;
V_40 -> V_56 . V_86 =
V_127 ;
V_40 -> V_56 . V_128 = V_121 -> V_128 ;
V_40 -> V_56 . V_129 = V_130 ;
V_40 -> V_131 . V_132 = V_121 -> V_132 ;
V_40 -> V_133 . V_134 = V_121 -> V_134 ;
V_40 -> V_133 . V_135 = V_121 -> V_135 ;
V_40 -> V_136 = F_12 ( V_121 -> V_137 ) ;
V_40 -> V_138 = F_13 ( V_121 -> V_137 ) ;
V_40 -> V_139 = F_12 ( V_121 -> V_140 ) ;
V_40 -> V_141 = F_13 ( V_121 -> V_140 ) ;
V_14 -> V_118 -> V_123 . V_142 ( V_14 -> V_118 ) ;
V_125:
F_27 ( & V_14 -> V_117 ) ;
return V_29 ;
}
int F_28 ( struct V_13 * V_14 , struct V_103 * V_143 )
{
T_2 V_144 ;
V_5 * V_25 ;
T_1 V_145 , V_146 ;
int V_29 ;
V_29 = F_17 ( V_14 , V_143 , & V_144 ,
& V_145 ) ;
if ( V_29 )
goto V_147;
F_6 ( L_14 , V_144 ) ;
V_146 = sizeof( struct V_24 ) / sizeof( V_5 ) ;
F_26 ( & V_14 -> V_117 ) ;
V_29 = V_14 -> V_118 -> V_123 . V_124 ( V_14 -> V_118 ,
V_146 , & V_25 ) ;
if ( V_29 )
goto V_148;
V_29 = F_11 ( V_14 , V_25 , V_144 ,
V_145 / sizeof( V_5 ) , false ) ;
if ( V_29 )
goto V_149;
V_14 -> V_118 -> V_123 . V_142 ( V_14 -> V_118 ) ;
F_27 ( & V_14 -> V_117 ) ;
return V_29 ;
V_149:
V_14 -> V_118 -> V_123 . V_150 ( V_14 -> V_118 ) ;
V_148:
F_27 ( & V_14 -> V_117 ) ;
V_147:
F_18 ( V_14 ) ;
return V_29 ;
}
int F_29 ( struct V_13 * V_14 , T_2 V_151 ,
V_5 V_152 )
{
int V_29 ;
struct V_153 * V_40 ;
if ( F_8 ( ! V_151 ) )
return - V_41 ;
F_26 ( & V_14 -> V_117 ) ;
V_29 = V_14 -> V_118 -> V_123 . V_124 (
V_14 -> V_118 ,
sizeof( struct V_153 ) / sizeof( V_5 ) ,
( unsigned int * * ) & V_40 ) ;
if ( V_29 )
goto V_148;
V_40 -> V_9 . V_10 = F_3 ( V_154 ,
sizeof( struct V_153 ) ) ;
V_40 -> V_56 . V_155 = 0 ;
V_40 -> V_56 . V_156 =
V_157 ;
V_40 -> V_56 . V_158 =
V_159 ;
V_40 -> V_160 = F_13 ( ( T_2 ) V_151 ) ;
V_40 -> V_161 = F_12 ( ( T_2 ) V_151 ) ;
V_40 -> V_162 = F_13 ( ( T_2 ) V_152 ) ;
V_40 -> V_163 = F_12 ( ( T_2 ) V_152 ) ;
V_14 -> V_118 -> V_123 . V_142 ( V_14 -> V_118 ) ;
V_148:
F_27 ( & V_14 -> V_117 ) ;
return V_29 ;
}
int F_30 ( struct V_13 * V_14 , enum V_164 type ,
enum V_165 V_166 ,
V_5 V_167 , bool V_168 ,
unsigned int V_169 )
{
int V_29 ;
V_5 * V_36 ;
struct V_170 * V_40 ;
F_26 ( & V_14 -> V_117 ) ;
V_29 = V_14 -> V_118 -> V_123 . V_124 (
V_14 -> V_118 ,
sizeof( struct V_170 ) / sizeof( V_5 ) ,
& V_36 ) ;
if ( V_29 )
goto V_171;
V_40 = (struct V_170 * ) V_36 ;
memset ( V_36 , 0 , sizeof( struct V_170 ) ) ;
F_6 ( L_15 ,
V_166 , V_168 , type ) ;
V_40 -> V_9 . V_10 = F_3 ( V_172 ,
sizeof( struct V_170 ) ) ;
switch ( type ) {
case V_89 :
case V_91 :
V_40 -> V_56 . V_84 =
V_173 ;
break;
case V_93 :
V_40 -> V_56 . V_84 =
V_174 + V_169 ;
break;
default:
F_2 ( 1 , L_5 , type ) ;
V_29 = - V_31 ;
goto V_175;
}
if ( V_168 )
V_40 -> V_56 . V_176 =
V_177 ;
else
V_40 -> V_56 . V_176 =
V_178 ;
switch ( V_166 ) {
case V_179 :
V_40 -> V_56 . V_82 =
V_180 ;
V_40 -> V_56 . V_54 = 1 ;
V_40 -> V_181 . V_182 = V_167 ;
break;
case V_183 :
V_40 -> V_56 . V_82 =
V_184 ;
V_40 -> V_185 . V_60 = V_167 ;
break;
case V_186 :
V_40 -> V_56 . V_82 =
V_187 ;
break;
case V_188 :
V_40 -> V_56 . V_82 =
V_189 ;
break;
default:
F_2 ( 1 , L_16 , V_166 ) ;
V_29 = - V_31 ;
goto V_175;
}
V_14 -> V_118 -> V_123 . V_142 ( V_14 -> V_118 ) ;
F_27 ( & V_14 -> V_117 ) ;
return 0 ;
V_175:
V_14 -> V_118 -> V_123 . V_150 ( V_14 -> V_118 ) ;
V_171:
F_27 ( & V_14 -> V_117 ) ;
return V_29 ;
}
void F_18 ( struct V_13 * V_14 )
{
F_26 ( & V_14 -> V_117 ) ;
if ( V_14 -> V_30 ) {
F_31 ( V_14 -> V_20 -> V_32 , V_14 -> V_33 ) ;
V_14 -> V_30 = false ;
}
F_27 ( & V_14 -> V_117 ) ;
}
