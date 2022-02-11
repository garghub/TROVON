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
V_30 = F_7 ( V_14 -> V_19 -> V_32 , * V_28 ,
& V_14 -> V_33 ) ;
if ( V_30 != 0 ) {
F_8 ( L_3 ) ;
return V_30 ;
}
* ( void * * ) V_26 = V_14 -> V_33 -> V_34 ;
* V_27 = V_14 -> V_33 -> V_35 ;
memset ( * V_26 , 0 , * V_28 ) ;
V_14 -> V_31 = true ;
return V_30 ;
}
static int F_9 ( struct V_13 * V_14 , V_5 * V_36 ,
T_2 V_37 , T_1 V_38 , bool V_39 )
{
struct V_25 * V_40 ;
F_2 ( ! V_14 || ! V_36 || ! V_37 ) ;
V_40 = (struct V_25 * ) V_36 ;
memset ( V_36 , 0 , sizeof( struct V_25 ) ) ;
V_40 -> V_9 . V_10 = F_3 ( V_41 ,
sizeof( struct V_25 ) ) ;
V_40 -> V_42 . V_43 = V_38 ;
V_40 -> V_42 . V_39 = V_39 ? 1 : 0 ;
V_40 -> V_42 . V_44 = 0 ;
V_40 -> V_42 . V_45 = 1 ;
V_40 -> V_46 = F_10 ( V_37 ) ;
V_40 -> V_47 . V_48 = F_11 ( V_37 ) ;
return 0 ;
}
static int F_12 ( struct V_13 * V_14 , V_5 * V_36 ,
struct V_49 * V_50 )
{
struct V_23 * V_40 ;
struct V_51 * V_52 ;
V_5 V_53 ;
F_2 ( ! V_14 || ! V_36 || ! V_50 ) ;
V_40 = (struct V_23 * ) V_36 ;
F_5 ( L_4 , V_54 ) ;
memset ( V_36 , 0 , sizeof( struct V_23 ) ) ;
V_40 -> V_9 . V_10 = F_3 ( V_55 ,
sizeof( struct V_23 ) ) ;
V_40 -> V_56 . V_57 = ( V_50 -> V_58 ) ? 1 : 0 ;
V_40 -> V_56 . V_59 = 1 ;
V_40 -> V_56 . V_60 = V_50 -> V_61 -> V_62 -> V_60 ;
V_40 -> V_47 . V_63 = V_50 -> V_63 ;
V_40 -> V_64 . V_65 = V_50 -> V_65 ;
V_40 -> V_64 . V_66 = V_50 -> V_66 ;
V_40 -> V_64 . V_67 = V_50 -> V_67 ;
V_53 = 0 ;
F_13 (cur, &qpd->queues_list, list)
V_53 ++ ;
V_40 -> V_64 . V_53 = ( V_50 -> V_58 ) ? 0 : V_53 ;
V_40 -> V_68 = V_50 -> V_68 ;
V_40 -> V_69 = V_50 -> V_69 ;
V_40 -> V_70 = V_50 -> V_70 ;
V_40 -> V_71 = V_50 -> V_71 ;
V_40 -> V_72 = F_10 ( V_50 -> V_73 ) ;
V_40 -> V_74 = F_11 ( V_50 -> V_73 ) ;
return 0 ;
}
static int F_14 ( struct V_13 * V_14 , V_5 * V_36 ,
struct V_51 * V_75 , bool V_76 )
{
struct V_24 * V_40 ;
bool V_77 = V_76 ;
F_2 ( ! V_14 || ! V_36 || ! V_75 ) ;
F_5 ( L_4 , V_54 ) ;
V_40 = (struct V_24 * ) V_36 ;
memset ( V_36 , 0 , sizeof( struct V_24 ) ) ;
V_40 -> V_9 . V_10 = F_3 ( V_78 ,
sizeof( struct V_24 ) ) ;
V_40 -> V_56 . V_79 =
V_80 ;
V_40 -> V_56 . V_53 = 1 ;
V_40 -> V_56 . V_81 =
V_82 ;
V_40 -> V_56 . V_83 = ( V_75 -> V_84 . V_85 ) ?
V_86 :
V_87 ;
switch ( V_75 -> V_84 . type ) {
case V_88 :
case V_89 :
V_40 -> V_56 . V_90 =
V_91 ;
break;
case V_92 :
V_40 -> V_56 . V_90 =
V_93 ;
V_77 = false ;
break;
default:
F_15 () ;
break;
}
V_40 -> V_94 [ 0 ] . V_47 . V_95 =
V_75 -> V_84 . V_96 ;
V_40 -> V_94 [ 0 ] . V_47 . V_76 =
( V_77 == true ) ? 1 : 0 ;
V_40 -> V_94 [ 0 ] . V_97 =
F_10 ( V_75 -> V_98 ) ;
V_40 -> V_94 [ 0 ] . V_99 =
F_11 ( V_75 -> V_98 ) ;
V_40 -> V_94 [ 0 ] . V_100 =
F_10 ( ( T_2 ) V_75 -> V_84 . V_101 ) ;
V_40 -> V_94 [ 0 ] . V_102 =
F_11 ( ( T_2 ) V_75 -> V_84 . V_101 ) ;
return 0 ;
}
static int F_16 ( struct V_13 * V_14 ,
struct V_103 * V_104 ,
T_2 * V_105 ,
T_1 * V_106 )
{
unsigned int V_107 ;
unsigned int * V_26 , V_108 , V_109 ;
int V_30 , V_110 ;
struct V_111 * V_52 ;
struct V_49 * V_50 ;
struct V_51 * V_75 ;
struct V_112 * V_113 ;
bool V_29 ;
F_2 ( ! V_14 || ! V_104 || ! V_106 || ! V_105 ) ;
V_108 = V_30 = V_110 = 0 ;
V_30 = F_6 ( V_14 , & V_26 , V_105 ,
& V_107 , & V_29 ) ;
if ( V_30 != 0 )
return V_30 ;
* V_106 = V_107 ;
F_5 ( L_4 , V_54 ) ;
F_5 ( L_5 ,
V_14 -> V_19 -> V_20 , V_14 -> V_19 -> V_18 ) ;
F_13 (cur, queues, list) {
V_50 = V_52 -> V_50 ;
if ( V_110 >= V_14 -> V_19 -> V_20 ) {
F_5 ( L_6 ) ;
F_17 ( V_14 ) ;
return - V_114 ;
}
V_30 = F_12 ( V_14 , & V_26 [ V_108 ] , V_50 ) ;
if ( V_30 != 0 )
return V_30 ;
V_110 ++ ;
F_1 ( & V_108 , sizeof( struct V_23 ) ,
V_107 ) ;
F_13 (kq, &qpd->priv_queue_list, list) {
if ( V_113 -> V_51 -> V_84 . V_115 != true )
continue;
F_5 ( L_7 ,
V_113 -> V_51 -> V_51 , V_50 -> V_58 ) ;
V_30 = F_14 ( V_14 , & V_26 [ V_108 ] ,
V_113 -> V_51 , V_50 -> V_58 ) ;
if ( V_30 != 0 )
return V_30 ;
F_1 ( & V_108 ,
sizeof( struct V_24 ) ,
V_107 ) ;
}
F_13 (q, &qpd->queues_list, list) {
if ( V_75 -> V_84 . V_115 != true )
continue;
F_5 ( L_8 ,
V_75 -> V_51 , V_50 -> V_58 ) ;
V_30 = F_14 ( V_14 , & V_26 [ V_108 ] ,
V_75 , V_50 -> V_58 ) ;
if ( V_30 != 0 )
return V_30 ;
F_1 ( & V_108 ,
sizeof( struct V_24 ) ,
V_107 ) ;
}
}
F_5 ( L_9 ) ;
if ( V_29 )
F_9 ( V_14 , & V_26 [ V_108 ] , * V_105 ,
V_107 / sizeof( V_5 ) , true ) ;
for ( V_109 = 0 ; V_109 < V_107 / sizeof( V_5 ) ; V_109 ++ )
F_5 ( L_10 , V_26 [ V_109 ] ) ;
F_5 ( L_11 ) ;
return 0 ;
}
int F_18 ( struct V_13 * V_14 , struct V_116 * V_19 )
{
F_2 ( ! V_19 ) ;
V_14 -> V_19 = V_19 ;
F_19 ( & V_14 -> V_117 ) ;
V_14 -> V_118 = F_20 ( V_19 -> V_32 , V_119 ) ;
if ( V_14 -> V_118 == NULL ) {
F_21 ( & V_14 -> V_117 ) ;
return - V_114 ;
}
V_14 -> V_31 = false ;
return 0 ;
}
void F_22 ( struct V_13 * V_14 )
{
F_2 ( ! V_14 ) ;
F_21 ( & V_14 -> V_117 ) ;
F_23 ( V_14 -> V_118 ) ;
}
int F_24 ( struct V_13 * V_14 ,
struct V_120 * V_121 )
{
struct V_122 * V_40 ;
F_2 ( ! V_14 || ! V_121 ) ;
F_5 ( L_4 , V_54 ) ;
F_25 ( & V_14 -> V_117 ) ;
V_14 -> V_118 -> V_123 . V_124 ( V_14 -> V_118 ,
sizeof( * V_40 ) / sizeof( V_5 ) ,
( unsigned int * * ) & V_40 ) ;
if ( V_40 == NULL ) {
F_26 ( & V_14 -> V_117 ) ;
F_8 ( L_12 ) ;
return - V_114 ;
}
memset ( V_40 , 0 , sizeof( struct V_122 ) ) ;
V_40 -> V_9 . V_10 = F_3 ( V_125 ,
sizeof( struct V_122 ) ) ;
V_40 -> V_56 . V_126 =
V_127 ;
V_40 -> V_56 . V_128 = V_121 -> V_128 ;
V_40 -> V_56 . V_129 = V_130 ;
V_40 -> V_131 . V_132 = V_121 -> V_132 ;
V_40 -> V_133 . V_134 = V_121 -> V_134 ;
V_40 -> V_133 . V_135 = V_121 -> V_135 ;
V_40 -> V_136 = F_10 ( V_121 -> V_137 ) ;
V_40 -> V_138 = F_11 ( V_121 -> V_137 ) ;
V_40 -> V_139 = F_10 ( V_121 -> V_140 ) ;
V_40 -> V_141 = F_11 ( V_121 -> V_140 ) ;
V_14 -> V_118 -> V_123 . V_142 ( V_14 -> V_118 ) ;
F_26 ( & V_14 -> V_117 ) ;
return 0 ;
}
int F_27 ( struct V_13 * V_14 , struct V_103 * V_143 )
{
T_2 V_144 ;
V_5 * V_26 ;
T_1 V_145 , V_146 ;
int V_30 ;
F_2 ( ! V_14 || ! V_143 ) ;
V_30 = F_16 ( V_14 , V_143 , & V_144 ,
& V_145 ) ;
if ( V_30 != 0 )
goto V_147;
F_5 ( L_13 , V_144 ) ;
V_146 = sizeof( struct V_25 ) / sizeof( V_5 ) ;
F_25 ( & V_14 -> V_117 ) ;
V_30 = V_14 -> V_118 -> V_123 . V_124 ( V_14 -> V_118 ,
V_146 , & V_26 ) ;
if ( V_30 != 0 )
goto V_148;
V_30 = F_9 ( V_14 , V_26 , V_144 ,
V_145 / sizeof( V_5 ) , false ) ;
if ( V_30 != 0 )
goto V_149;
V_14 -> V_118 -> V_123 . V_142 ( V_14 -> V_118 ) ;
F_26 ( & V_14 -> V_117 ) ;
return V_30 ;
V_149:
V_14 -> V_118 -> V_123 . V_150 ( V_14 -> V_118 ) ;
V_148:
F_26 ( & V_14 -> V_117 ) ;
V_147:
if ( V_14 -> V_31 == true )
F_17 ( V_14 ) ;
return V_30 ;
}
int F_28 ( struct V_13 * V_14 , T_2 V_151 ,
V_5 V_152 )
{
int V_30 ;
struct V_153 * V_40 ;
F_2 ( ! V_14 || ! V_151 ) ;
F_25 ( & V_14 -> V_117 ) ;
V_30 = V_14 -> V_118 -> V_123 . V_124 (
V_14 -> V_118 ,
sizeof( struct V_153 ) / sizeof( V_5 ) ,
( unsigned int * * ) & V_40 ) ;
if ( V_30 != 0 )
goto V_148;
V_40 -> V_9 . V_10 = F_3 ( V_154 ,
sizeof( struct V_153 ) ) ;
V_40 -> V_56 . V_155 = 0 ;
V_40 -> V_56 . V_156 =
V_157 ;
V_40 -> V_56 . V_158 =
V_159 ;
V_40 -> V_160 = F_11 ( ( T_2 ) V_151 ) ;
V_40 -> V_161 = F_10 ( ( T_2 ) V_151 ) ;
V_40 -> V_162 = F_11 ( ( T_2 ) V_152 ) ;
V_40 -> V_163 = F_10 ( ( T_2 ) V_152 ) ;
V_14 -> V_118 -> V_123 . V_142 ( V_14 -> V_118 ) ;
F_26 ( & V_14 -> V_117 ) ;
return 0 ;
V_148:
F_26 ( & V_14 -> V_117 ) ;
return V_30 ;
}
int F_29 ( struct V_13 * V_14 , enum V_164 type ,
enum V_165 V_166 ,
V_5 V_167 , bool V_168 ,
unsigned int V_169 )
{
int V_30 ;
V_5 * V_36 ;
struct V_170 * V_40 ;
F_2 ( ! V_14 ) ;
F_25 ( & V_14 -> V_117 ) ;
V_30 = V_14 -> V_118 -> V_123 . V_124 (
V_14 -> V_118 ,
sizeof( struct V_170 ) / sizeof( V_5 ) ,
& V_36 ) ;
if ( V_30 != 0 )
goto V_171;
V_40 = (struct V_170 * ) V_36 ;
memset ( V_36 , 0 , sizeof( struct V_170 ) ) ;
F_5 ( L_14 ,
V_166 , V_168 , type ) ;
V_40 -> V_9 . V_10 = F_3 ( V_172 ,
sizeof( struct V_170 ) ) ;
switch ( type ) {
case V_88 :
case V_89 :
V_40 -> V_56 . V_90 =
V_173 ;
break;
case V_92 :
V_40 -> V_56 . V_90 =
V_174 + V_169 ;
break;
default:
F_15 () ;
break;
}
if ( V_168 )
V_40 -> V_56 . V_175 =
V_176 ;
else
V_40 -> V_56 . V_175 =
V_177 ;
switch ( V_166 ) {
case V_178 :
V_40 -> V_56 . V_81 =
V_179 ;
V_40 -> V_56 . V_53 = 1 ;
V_40 -> V_180 . V_181 = V_167 ;
break;
case V_182 :
V_40 -> V_56 . V_81 =
V_183 ;
V_40 -> V_184 . V_60 = V_167 ;
break;
case V_185 :
V_40 -> V_56 . V_81 =
V_186 ;
break;
case V_187 :
V_40 -> V_56 . V_81 =
V_188 ;
break;
default:
F_15 () ;
break;
} ;
V_14 -> V_118 -> V_123 . V_142 ( V_14 -> V_118 ) ;
F_26 ( & V_14 -> V_117 ) ;
return 0 ;
V_171:
F_26 ( & V_14 -> V_117 ) ;
return V_30 ;
}
void F_17 ( struct V_13 * V_14 )
{
F_2 ( ! V_14 ) ;
F_25 ( & V_14 -> V_117 ) ;
if ( V_14 -> V_31 ) {
F_30 ( V_14 -> V_19 -> V_32 , V_14 -> V_33 ) ;
V_14 -> V_31 = false ;
}
F_26 ( & V_14 -> V_117 ) ;
}
