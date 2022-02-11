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
V_40 -> V_64 . V_53 = V_53 ;
V_40 -> V_68 = V_50 -> V_68 ;
V_40 -> V_69 = V_50 -> V_69 ;
V_40 -> V_70 = V_50 -> V_70 ;
V_40 -> V_71 = V_50 -> V_71 ;
V_40 -> V_72 = F_10 ( V_50 -> V_73 ) ;
V_40 -> V_74 = F_11 ( V_50 -> V_73 ) ;
return 0 ;
}
static int F_14 ( struct V_13 * V_14 , V_5 * V_36 ,
struct V_51 * V_75 )
{
struct V_24 * V_40 ;
F_2 ( ! V_14 || ! V_36 || ! V_75 ) ;
F_5 ( L_4 , V_54 ) ;
V_40 = (struct V_24 * ) V_36 ;
memset ( V_36 , 0 , sizeof( struct V_24 ) ) ;
V_40 -> V_9 . V_10 = F_3 ( V_76 ,
sizeof( struct V_24 ) ) ;
V_40 -> V_56 . V_77 =
V_78 ;
V_40 -> V_56 . V_53 = 1 ;
V_40 -> V_56 . V_79 =
V_80 ;
V_40 -> V_56 . V_81 = ( V_75 -> V_82 . V_83 ) ?
V_84 :
V_85 ;
switch ( V_75 -> V_82 . type ) {
case V_86 :
case V_87 :
V_40 -> V_56 . V_88 =
V_89 ;
break;
case V_90 :
V_40 -> V_56 . V_88 =
V_91 ;
break;
default:
F_15 () ;
break;
}
V_40 -> V_92 [ 0 ] . V_47 . V_93 =
V_75 -> V_82 . V_94 ;
V_40 -> V_92 [ 0 ] . V_95 =
F_10 ( V_75 -> V_96 ) ;
V_40 -> V_92 [ 0 ] . V_97 =
F_11 ( V_75 -> V_96 ) ;
V_40 -> V_92 [ 0 ] . V_98 =
F_10 ( ( T_2 ) V_75 -> V_82 . V_99 ) ;
V_40 -> V_92 [ 0 ] . V_100 =
F_11 ( ( T_2 ) V_75 -> V_82 . V_99 ) ;
return 0 ;
}
static int F_16 ( struct V_13 * V_14 ,
struct V_101 * V_102 ,
T_2 * V_103 ,
T_1 * V_104 )
{
unsigned int V_105 ;
unsigned int * V_26 , V_106 , V_107 ;
int V_30 , V_108 ;
struct V_109 * V_52 ;
struct V_49 * V_50 ;
struct V_51 * V_75 ;
struct V_110 * V_111 ;
bool V_29 ;
F_2 ( ! V_14 || ! V_102 || ! V_104 || ! V_103 ) ;
V_106 = V_30 = V_108 = 0 ;
V_30 = F_6 ( V_14 , & V_26 , V_103 ,
& V_105 , & V_29 ) ;
if ( V_30 != 0 )
return V_30 ;
* V_104 = V_105 ;
F_5 ( L_4 , V_54 ) ;
F_5 ( L_5 ,
V_14 -> V_19 -> V_20 , V_14 -> V_19 -> V_18 ) ;
F_13 (cur, queues, list) {
V_50 = V_52 -> V_50 ;
if ( V_108 >= V_14 -> V_19 -> V_20 ) {
F_5 ( L_6 ) ;
F_17 ( V_14 ) ;
return - V_112 ;
}
V_30 = F_12 ( V_14 , & V_26 [ V_106 ] , V_50 ) ;
if ( V_30 != 0 )
return V_30 ;
V_108 ++ ;
F_1 ( & V_106 , sizeof( struct V_23 ) ,
V_105 ) ;
F_13 (kq, &qpd->priv_queue_list, list) {
if ( V_111 -> V_51 -> V_82 . V_113 != true )
continue;
V_30 = F_14 ( V_14 , & V_26 [ V_106 ] ,
V_111 -> V_51 ) ;
if ( V_30 != 0 )
return V_30 ;
F_1 ( & V_106 , sizeof( struct V_24 ) ,
V_105 ) ;
}
F_13 (q, &qpd->queues_list, list) {
if ( V_75 -> V_82 . V_113 != true )
continue;
V_30 = F_14 ( V_14 ,
& V_26 [ V_106 ] , V_75 ) ;
if ( V_30 != 0 )
return V_30 ;
F_1 ( & V_106 , sizeof( struct V_24 ) ,
V_105 ) ;
}
}
F_5 ( L_7 ) ;
if ( V_29 )
F_9 ( V_14 , & V_26 [ V_106 ] , * V_103 ,
V_105 / sizeof( V_5 ) , true ) ;
for ( V_107 = 0 ; V_107 < V_105 / sizeof( V_5 ) ; V_107 ++ )
F_5 ( L_8 , V_26 [ V_107 ] ) ;
F_5 ( L_9 ) ;
return 0 ;
}
int F_18 ( struct V_13 * V_14 , struct V_114 * V_19 )
{
F_2 ( ! V_19 ) ;
V_14 -> V_19 = V_19 ;
F_19 ( & V_14 -> V_115 ) ;
V_14 -> V_116 = F_20 ( V_19 -> V_32 , V_117 ) ;
if ( V_14 -> V_116 == NULL ) {
F_21 ( & V_14 -> V_115 ) ;
return - V_112 ;
}
V_14 -> V_31 = false ;
return 0 ;
}
void F_22 ( struct V_13 * V_14 )
{
F_2 ( ! V_14 ) ;
F_21 ( & V_14 -> V_115 ) ;
F_23 ( V_14 -> V_116 ) ;
}
int F_24 ( struct V_13 * V_14 ,
struct V_118 * V_119 )
{
struct V_120 * V_40 ;
F_2 ( ! V_14 || ! V_119 ) ;
F_5 ( L_4 , V_54 ) ;
F_25 ( & V_14 -> V_115 ) ;
V_14 -> V_116 -> V_121 . V_122 ( V_14 -> V_116 ,
sizeof( * V_40 ) / sizeof( V_5 ) ,
( unsigned int * * ) & V_40 ) ;
if ( V_40 == NULL ) {
F_26 ( & V_14 -> V_115 ) ;
F_8 ( L_10 ) ;
return - V_112 ;
}
memset ( V_40 , 0 , sizeof( struct V_120 ) ) ;
V_40 -> V_9 . V_10 = F_3 ( V_123 ,
sizeof( struct V_120 ) ) ;
V_40 -> V_56 . V_124 =
V_125 ;
V_40 -> V_56 . V_126 = V_119 -> V_126 ;
V_40 -> V_56 . V_127 = V_128 ;
V_40 -> V_129 . V_130 = V_119 -> V_130 ;
V_40 -> V_131 . V_132 = V_119 -> V_132 ;
V_40 -> V_131 . V_133 = V_119 -> V_133 ;
V_40 -> V_134 = F_10 ( V_119 -> V_135 ) ;
V_40 -> V_136 = F_11 ( V_119 -> V_135 ) ;
V_40 -> V_137 = F_10 ( V_119 -> V_138 ) ;
V_40 -> V_139 = F_11 ( V_119 -> V_138 ) ;
V_14 -> V_116 -> V_121 . V_140 ( V_14 -> V_116 ) ;
F_26 ( & V_14 -> V_115 ) ;
return 0 ;
}
int F_27 ( struct V_13 * V_14 , struct V_101 * V_141 )
{
T_2 V_142 ;
V_5 * V_26 ;
T_1 V_143 , V_144 ;
int V_30 ;
F_2 ( ! V_14 || ! V_141 ) ;
V_30 = F_16 ( V_14 , V_141 , & V_142 ,
& V_143 ) ;
if ( V_30 != 0 )
goto V_145;
F_5 ( L_11 , V_142 ) ;
V_144 = sizeof( struct V_25 ) / sizeof( V_5 ) ;
F_25 ( & V_14 -> V_115 ) ;
V_30 = V_14 -> V_116 -> V_121 . V_122 ( V_14 -> V_116 ,
V_144 , & V_26 ) ;
if ( V_30 != 0 )
goto V_146;
V_30 = F_9 ( V_14 , V_26 , V_142 ,
V_143 / sizeof( V_5 ) , false ) ;
if ( V_30 != 0 )
goto V_147;
V_14 -> V_116 -> V_121 . V_140 ( V_14 -> V_116 ) ;
F_26 ( & V_14 -> V_115 ) ;
return V_30 ;
V_147:
V_14 -> V_116 -> V_121 . V_148 ( V_14 -> V_116 ) ;
V_146:
F_26 ( & V_14 -> V_115 ) ;
V_145:
if ( V_14 -> V_31 == true )
F_17 ( V_14 ) ;
return V_30 ;
}
int F_28 ( struct V_13 * V_14 , T_2 V_149 ,
V_5 V_150 )
{
int V_30 ;
struct V_151 * V_40 ;
F_2 ( ! V_14 || ! V_149 ) ;
F_25 ( & V_14 -> V_115 ) ;
V_30 = V_14 -> V_116 -> V_121 . V_122 (
V_14 -> V_116 ,
sizeof( struct V_151 ) / sizeof( V_5 ) ,
( unsigned int * * ) & V_40 ) ;
if ( V_30 != 0 )
goto V_146;
V_40 -> V_9 . V_10 = F_3 ( V_152 ,
sizeof( struct V_151 ) ) ;
V_40 -> V_56 . V_153 = 0 ;
V_40 -> V_56 . V_154 =
V_155 ;
V_40 -> V_56 . V_156 =
V_157 ;
V_40 -> V_158 = F_11 ( ( T_2 ) V_149 ) ;
V_40 -> V_159 = F_10 ( ( T_2 ) V_149 ) ;
V_40 -> V_160 = F_11 ( ( T_2 ) V_150 ) ;
V_40 -> V_161 = F_10 ( ( T_2 ) V_150 ) ;
V_14 -> V_116 -> V_121 . V_140 ( V_14 -> V_116 ) ;
F_26 ( & V_14 -> V_115 ) ;
return 0 ;
V_146:
F_26 ( & V_14 -> V_115 ) ;
return V_30 ;
}
int F_29 ( struct V_13 * V_14 , enum V_162 type ,
enum V_163 V_164 ,
V_5 V_165 , bool V_166 ,
unsigned int V_167 )
{
int V_30 ;
V_5 * V_36 ;
struct V_168 * V_40 ;
F_2 ( ! V_14 ) ;
F_25 ( & V_14 -> V_115 ) ;
V_30 = V_14 -> V_116 -> V_121 . V_122 (
V_14 -> V_116 ,
sizeof( struct V_168 ) / sizeof( V_5 ) ,
& V_36 ) ;
if ( V_30 != 0 )
goto V_169;
V_40 = (struct V_168 * ) V_36 ;
memset ( V_36 , 0 , sizeof( struct V_168 ) ) ;
V_40 -> V_9 . V_10 = F_3 ( V_170 ,
sizeof( struct V_168 ) ) ;
switch ( type ) {
case V_86 :
case V_87 :
V_40 -> V_56 . V_88 =
V_171 ;
break;
case V_90 :
V_40 -> V_56 . V_88 =
V_172 + V_167 ;
break;
default:
F_15 () ;
break;
}
if ( V_166 )
V_40 -> V_56 . V_173 =
V_174 ;
else
V_40 -> V_56 . V_173 =
V_175 ;
switch ( V_164 ) {
case V_176 :
V_40 -> V_56 . V_79 =
V_177 ;
V_40 -> V_56 . V_53 = 1 ;
V_40 -> V_178 . V_179 = V_165 ;
break;
case V_180 :
V_40 -> V_56 . V_79 =
V_181 ;
V_40 -> V_182 . V_60 = V_165 ;
break;
case V_183 :
V_40 -> V_56 . V_79 =
V_184 ;
break;
default:
F_15 () ;
break;
} ;
V_14 -> V_116 -> V_121 . V_140 ( V_14 -> V_116 ) ;
F_26 ( & V_14 -> V_115 ) ;
return 0 ;
V_169:
F_26 ( & V_14 -> V_115 ) ;
return V_30 ;
}
void F_17 ( struct V_13 * V_14 )
{
F_2 ( ! V_14 ) ;
F_25 ( & V_14 -> V_115 ) ;
if ( V_14 -> V_31 ) {
F_30 ( V_14 -> V_19 -> V_32 , V_14 -> V_33 ) ;
V_14 -> V_31 = false ;
}
F_26 ( & V_14 -> V_115 ) ;
}
