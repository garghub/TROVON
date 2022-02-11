int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ) {
int V_7 ;
struct V_8 V_9 ;
if ( ! V_6 -> V_10 ) {
V_4 -> V_11 = V_12 ;
V_4 -> V_13 = V_14 ;
V_4 -> V_15 . V_16 = 0 ;
V_2 -> V_17 . V_18 = 0 ;
V_2 -> V_17 . V_19 = 0 ;
V_2 -> V_17 . V_20 = 0 ;
return 0 ;
}
switch ( V_6 -> V_21 ) {
case V_22 :
V_4 -> V_23 = V_24 ;
break;
case V_25 :
V_4 -> V_23 = V_26 ;
break;
case V_27 :
V_4 -> V_23 = V_28 ;
break;
default:
V_4 -> V_23 = V_29 ;
break;
}
V_4 -> V_30 |= V_31 ;
for ( V_7 = 0 ; V_7 < V_6 -> V_32 . V_33 ; V_7 ++ ) {
switch ( V_6 -> V_32 . V_34 [ V_7 ] ) {
case V_35 :
if ( V_6 -> V_32 . V_36 &
V_37 ) {
V_4 -> V_11 = V_38 ;
V_4 -> V_13 = V_39 ;
}
if ( V_6 -> V_32 . V_36 &
V_40 ) {
V_4 -> V_11 |= V_41 ;
V_4 -> V_13 = V_39 ;
}
break;
case V_42 :
if ( V_6 -> V_32 . V_36 &
V_37 ) {
V_4 -> V_11 = V_38 ;
V_4 -> V_13 = V_43 ;
}
if ( V_6 -> V_32 . V_36 &
V_40 ) {
V_4 -> V_11 |= V_41 ;
V_4 -> V_13 = V_43 ;
}
break;
default:
break;
}
}
for ( V_7 = 0 ; V_7 < V_6 -> V_32 . V_44 ; V_7 ++ ) {
switch ( V_6 -> V_32 . V_45 [ V_7 ] ) {
case V_46 :
case V_47 :
break;
case V_48 :
if ( V_6 -> V_32 . V_36 & V_37 )
V_4 -> V_15 . V_49 |=
V_50 ;
if ( V_6 -> V_32 . V_36 & V_40 )
V_4 -> V_15 . V_51 |=
V_50 ;
break;
case V_52 :
if ( V_6 -> V_32 . V_36 & V_37 )
V_4 -> V_15 . V_49 |=
V_53 ;
if ( V_6 -> V_32 . V_36 & V_40 )
V_4 -> V_15 . V_51 |=
V_53 ;
default:
break;
}
}
switch ( V_6 -> V_32 . V_54 ) {
case V_46 :
case V_47 :
if ( V_2 -> V_17 . V_18 ) {
V_4 -> V_11 = V_55 ;
V_4 -> V_13 = V_14 ;
V_4 -> V_15 . V_16 = 0 ;
for ( V_7 = 0 ; V_7 < V_56 ; V_7 ++ ) {
V_9 = V_2 -> V_9 [ V_7 ] ;
V_4 -> V_57 [ V_7 ] . V_58 = V_7 ;
if ( V_2 -> V_59 == V_7 )
V_4 -> V_57 [ V_7 ] . V_60 = 1 ;
else
V_4 -> V_57 [ V_7 ] . V_60 = 0 ;
V_4 -> V_57 [ V_7 ] . V_16 =
V_9 . V_61 ;
memcpy ( & V_4 -> V_57 [ V_7 ] . V_62 ,
& V_9 . V_63 ,
V_9 . V_61 ) ;
}
}
break;
case V_48 :
V_4 -> V_15 . V_64 = V_50 ;
break;
case V_52 :
V_4 -> V_15 . V_64 = V_53 ;
break;
default:
break;
}
return 0 ;
}
void
F_2 ( struct V_1 * V_2 ,
struct V_3 * V_65 ,
struct V_5 * V_6 )
{
const T_1 * V_66 ;
if ( ! F_3 ( V_2 -> V_67 -> V_68 ) )
return;
V_66 = F_4 ( V_69 , V_6 -> V_70 . V_71 ,
V_6 -> V_70 . V_72 ) ;
if ( V_66 ) {
memcpy ( & V_65 -> V_73 , V_66 + 2 ,
sizeof( struct V_74 ) ) ;
} else {
memset ( & V_65 -> V_73 , 0 , sizeof( struct V_74 ) ) ;
V_65 -> V_73 . V_75 = F_5 ( V_76 ) ;
V_65 -> V_73 . V_77 = V_78 ;
}
return;
}
void F_6 ( struct V_3 * V_79 )
{
V_79 -> V_80 = 0x7F ;
V_79 -> V_81 = 0x7F ;
V_79 -> V_82 = 0x7F ;
V_79 -> V_83 = 0x7FFF ;
V_79 -> V_23 = 0x7F ;
V_79 -> V_84 = 0x7FFF ;
V_79 -> V_85 = 0x7FFF ;
V_79 -> V_86 = 0x7F ;
}
static void
F_7 ( T_1 * * V_87 , void * V_88 , T_2 * V_89 )
{
struct V_90 * V_91 ;
struct V_92 * V_93 ;
struct V_94 * V_95 ;
struct V_96 * V_97 ;
struct V_3 * V_65 = V_88 ;
T_2 V_98 = * V_89 ;
T_1 * V_99 = * V_87 ;
V_97 = (struct V_96 * ) V_99 ;
V_97 -> V_99 . type = F_5 ( V_100 ) ;
V_97 -> V_99 . V_101 = F_5 ( sizeof( struct V_96 ) -
sizeof( struct V_102 ) ) ;
V_97 -> V_30 = F_5 ( V_65 -> V_30 ) ;
V_97 -> V_13 = F_5 ( V_65 -> V_13 ) ;
V_98 += sizeof( struct V_96 ) ;
V_99 += sizeof( struct V_96 ) ;
if ( V_65 -> V_15 . V_49 & V_103 ) {
V_91 = (struct V_90 * ) V_99 ;
V_91 -> V_99 . type = F_5 ( V_104 ) ;
V_91 -> V_99 . V_101 =
F_5 ( sizeof( struct V_90 ) -
sizeof( struct V_102 ) ) ;
V_91 -> V_105 = F_5 ( V_38 ) ;
V_91 -> V_106 = V_65 -> V_15 . V_49 ;
V_98 += sizeof( struct V_90 ) ;
V_99 += sizeof( struct V_90 ) ;
}
if ( V_65 -> V_15 . V_51 & V_103 ) {
V_91 = (struct V_90 * ) V_99 ;
V_91 -> V_99 . type = F_5 ( V_104 ) ;
V_91 -> V_99 . V_101 =
F_5 ( sizeof( struct V_90 ) -
sizeof( struct V_102 ) ) ;
V_91 -> V_105 = F_5 ( V_41 ) ;
V_91 -> V_106 = V_65 -> V_15 . V_51 ;
V_98 += sizeof( struct V_90 ) ;
V_99 += sizeof( struct V_90 ) ;
}
if ( V_65 -> V_15 . V_64 & V_103 ) {
V_93 = (struct V_92 * ) V_99 ;
V_93 -> V_99 . type = F_5 ( V_107 ) ;
V_93 -> V_99 . V_101 =
F_5 ( sizeof( struct V_92 ) -
sizeof( struct V_102 ) ) ;
V_93 -> V_106 = V_65 -> V_15 . V_64 ;
V_98 += sizeof( struct V_92 ) ;
V_99 += sizeof( struct V_92 ) ;
}
if ( V_65 -> V_15 . V_16 ) {
V_95 = (struct V_94 * ) V_99 ;
V_95 -> V_99 . type = F_5 ( V_108 ) ;
V_95 -> V_99 . V_101 = F_5 ( V_65 -> V_15 . V_16 ) ;
memcpy ( V_95 -> V_95 , V_65 -> V_15 . V_95 ,
V_65 -> V_15 . V_16 ) ;
V_98 += sizeof( struct V_102 ) +
V_65 -> V_15 . V_16 ;
V_99 += sizeof( struct V_102 ) + V_65 -> V_15 . V_16 ;
}
* V_89 = V_98 ;
* V_87 = V_99 ;
return;
}
static void
F_8 ( T_1 * * V_87 , void * V_88 , T_2 * V_89 )
{
struct V_109 * V_9 ;
T_2 V_98 = * V_89 ;
int V_7 ;
T_1 * V_99 = * V_87 ;
struct V_3 * V_65 = V_88 ;
for ( V_7 = 0 ; V_7 < V_56 ; V_7 ++ ) {
if ( V_65 -> V_57 [ V_7 ] . V_16 &&
( V_65 -> V_57 [ V_7 ] . V_16 == V_110 ||
V_65 -> V_57 [ V_7 ] . V_16 == V_111 ) ) {
V_9 = (struct V_109 * ) V_99 ;
V_9 -> V_99 . type = F_5 ( V_112 ) ;
V_9 -> V_99 . V_101 =
F_5 ( V_65 -> V_57 [ V_7 ] . V_16 + 2 ) ;
V_9 -> V_58 = V_65 -> V_57 [ V_7 ] . V_58 ;
V_9 -> V_60 = V_65 -> V_57 [ V_7 ] . V_60 ;
memcpy ( V_9 -> V_62 , V_65 -> V_57 [ V_7 ] . V_62 ,
V_65 -> V_57 [ V_7 ] . V_16 ) ;
V_98 += sizeof( struct V_102 ) + 2 +
V_65 -> V_57 [ V_7 ] . V_16 ;
V_99 += sizeof( struct V_102 ) + 2 +
V_65 -> V_57 [ V_7 ] . V_16 ;
}
}
* V_89 = V_98 ;
* V_87 = V_99 ;
return;
}
static int
F_9 ( T_1 * V_99 , void * V_88 , T_2 * V_89 )
{
struct V_113 * V_82 ;
struct V_114 * V_83 ;
struct V_115 * V_116 ;
struct V_117 * V_118 ;
struct V_119 * V_120 ;
struct V_121 * V_85 ;
struct V_122 * V_84 ;
struct V_123 * V_86 ;
struct V_124 * V_125 ;
struct V_126 * V_21 ;
struct V_127 * V_128 ;
struct V_3 * V_65 = V_88 ;
T_2 V_98 = * V_89 ;
if ( V_65 -> V_116 . V_129 ) {
V_116 = (struct V_115 * ) V_99 ;
V_116 -> V_99 . type = F_5 ( V_130 ) ;
V_116 -> V_99 . V_101 = F_5 ( ( T_2 ) V_65 -> V_116 . V_129 ) ;
memcpy ( V_116 -> V_116 , V_65 -> V_116 . V_116 , V_65 -> V_116 . V_129 ) ;
V_98 += sizeof( struct V_102 ) +
V_65 -> V_116 . V_129 ;
V_99 += sizeof( struct V_102 ) + V_65 -> V_116 . V_129 ;
V_118 = (struct V_117 * ) V_99 ;
V_118 -> V_99 . type = F_5 ( V_131 ) ;
V_118 -> V_99 . V_101 =
F_5 ( sizeof( V_118 -> V_132 ) ) ;
V_118 -> V_132 = V_65 -> V_80 ;
V_98 += sizeof( struct V_117 ) ;
V_99 += sizeof( struct V_117 ) ;
}
if ( V_65 -> V_133 && V_65 -> V_133 <= V_134 ) {
V_120 = (struct V_119 * ) V_99 ;
V_120 -> V_99 . type = F_5 ( V_135 ) ;
V_120 -> V_99 . V_101 =
F_5 ( sizeof( struct V_119 ) -
sizeof( struct V_102 ) ) ;
V_120 -> V_136 = V_65 -> V_137 ;
V_120 -> V_133 = V_65 -> V_133 ;
V_98 += sizeof( struct V_119 ) ;
V_99 += sizeof( struct V_119 ) ;
}
if ( V_65 -> V_83 >= V_138 &&
V_65 -> V_83 <= V_139 ) {
V_83 = (struct V_114 * ) V_99 ;
V_83 -> V_99 . type =
F_5 ( V_140 ) ;
V_83 -> V_99 . V_101 =
F_5 ( sizeof( struct V_114 ) -
sizeof( struct V_102 ) ) ;
V_83 -> V_141 = F_5 ( V_65 -> V_83 ) ;
V_98 += sizeof( struct V_114 ) ;
V_99 += sizeof( struct V_114 ) ;
}
if ( V_65 -> V_82 >= V_142 &&
V_65 -> V_82 <= V_143 ) {
V_82 = (struct V_113 * ) V_99 ;
V_82 -> V_99 . type = F_5 ( V_144 ) ;
V_82 -> V_99 . V_101 =
F_5 ( sizeof( struct V_113 ) -
sizeof( struct V_102 ) ) ;
V_82 -> V_141 = V_65 -> V_82 ;
V_98 += sizeof( struct V_113 ) ;
V_99 += sizeof( struct V_113 ) ;
}
if ( V_65 -> V_84 <= V_145 ) {
V_84 = (struct V_122 * ) V_99 ;
V_84 -> V_99 . type =
F_5 ( V_146 ) ;
V_84 -> V_99 . V_101 =
F_5 ( sizeof( struct V_122 ) -
sizeof( struct V_102 ) ) ;
V_84 -> V_147 = F_5 ( V_65 -> V_84 ) ;
V_98 += sizeof( struct V_121 ) ;
V_99 += sizeof( struct V_121 ) ;
}
if ( ( V_65 -> V_85 >= V_148 ) &&
( V_65 -> V_85 <= V_149 ) ) {
V_85 = (struct V_121 * ) V_99 ;
V_85 -> V_99 . type =
F_5 ( V_150 ) ;
V_85 -> V_99 . V_101 =
F_5 ( sizeof( struct V_121 ) -
sizeof( struct V_102 ) ) ;
V_85 -> V_151 = F_5 ( V_65 -> V_85 ) ;
V_98 += sizeof( struct V_121 ) ;
V_99 += sizeof( struct V_121 ) ;
}
if ( V_65 -> V_86 <= V_152 ) {
V_86 = (struct V_123 * ) V_99 ;
V_86 -> V_99 . type = F_5 ( V_153 ) ;
V_86 -> V_99 . V_101 =
F_5 ( sizeof( struct V_123 ) -
sizeof( struct V_102 ) ) ;
V_86 -> V_154 = ( T_1 ) V_65 -> V_86 ;
V_98 += sizeof( struct V_123 ) ;
V_99 += sizeof( struct V_123 ) ;
}
if ( ( V_65 -> V_11 & V_38 ) ||
( V_65 -> V_11 & V_41 ) ||
( V_65 -> V_11 & V_155 ) )
F_7 ( & V_99 , V_88 , & V_98 ) ;
else
F_8 ( & V_99 , V_88 , & V_98 ) ;
if ( ( V_65 -> V_23 <= V_26 ) ||
( V_65 -> V_23 == V_29 ) ) {
V_21 = (struct V_126 * ) V_99 ;
V_21 -> V_99 . type = F_5 ( V_156 ) ;
V_21 -> V_99 . V_101 =
F_5 ( sizeof( struct V_126 ) -
sizeof( struct V_102 ) ) ;
V_21 -> V_21 = ( T_1 ) V_65 -> V_23 ;
V_98 += sizeof( struct V_126 ) ;
V_99 += sizeof( struct V_126 ) ;
}
if ( V_65 -> V_11 ) {
V_125 = (struct V_124 * ) V_99 ;
V_125 -> V_99 . type =
F_5 ( V_157 ) ;
V_125 -> V_99 . V_101 =
F_5 ( sizeof( struct V_124 )
- sizeof( struct V_102 ) ) ;
V_125 -> V_105 = F_5 ( V_65 -> V_11 ) ;
V_98 += sizeof( struct V_124 ) ;
V_99 += sizeof( struct V_124 ) ;
}
if ( V_65 -> V_73 . V_75 ) {
V_128 = (struct V_127 * ) V_99 ;
V_128 -> V_158 . type = F_5 ( V_69 ) ;
V_128 -> V_158 . V_101 =
F_5 ( sizeof( struct V_74 ) ) ;
V_128 -> V_73 . V_75 = V_65 -> V_73 . V_75 ;
V_128 -> V_73 . V_77 =
V_65 -> V_73 . V_77 ;
memcpy ( & V_128 -> V_73 . V_159 , & V_65 -> V_73 . V_159 ,
sizeof( struct V_160 ) ) ;
V_128 -> V_73 . V_161 =
V_65 -> V_73 . V_161 ;
V_128 -> V_73 . V_162 = V_65 -> V_73 . V_162 ;
V_128 -> V_73 . V_163 =
V_65 -> V_73 . V_163 ;
V_98 += sizeof( struct V_127 ) ;
V_99 += sizeof( struct V_127 ) ;
}
* V_89 = V_98 ;
return 0 ;
}
static int F_10 ( T_1 * V_99 , void * V_88 , T_2 * V_164 )
{
struct V_165 * V_166 = V_88 ;
struct V_102 * V_167 = (struct V_102 * ) V_99 ;
if ( ! V_166 || ! V_166 -> V_101 || ! V_166 -> V_168 )
return - 1 ;
* V_164 += F_11 ( V_166 -> V_101 ) + sizeof( struct V_102 ) ;
V_167 -> type = F_5 ( V_169 ) ;
V_167 -> V_101 = V_166 -> V_101 ;
V_99 += sizeof( struct V_102 ) ;
memcpy ( V_99 , V_166 -> V_168 , F_11 ( V_166 -> V_101 ) ) ;
return 0 ;
}
static int
F_12 ( struct V_170 * V_171 , T_2 V_172 ,
T_3 type , void * V_88 )
{
T_1 * V_99 ;
T_2 V_98 , V_89 , V_164 ;
struct V_173 * V_174 ;
V_171 -> V_175 = F_5 ( V_176 ) ;
V_98 = ( T_2 ) ( sizeof( struct V_173 ) + V_177 ) ;
V_174 = (struct V_173 * ) & V_171 -> V_6 . V_178 ;
V_174 -> V_179 = F_5 ( V_172 ) ;
V_99 = V_174 -> V_99 ;
switch ( type ) {
case V_180 :
V_89 = V_98 ;
if ( F_9 ( V_99 , V_88 , & V_89 ) )
return - 1 ;
V_171 -> V_181 = F_5 ( V_89 ) ;
break;
case V_182 :
V_164 = V_98 ;
if ( F_10 ( V_99 , V_88 , & V_164 ) )
return - 1 ;
V_171 -> V_181 = F_5 ( V_164 ) ;
break;
default:
return - 1 ;
}
return 0 ;
}
int F_13 ( struct V_1 * V_2 , T_2 V_183 ,
T_2 V_172 , T_3 type ,
void * V_184 , void * V_88 )
{
struct V_170 * V_171 = V_88 ;
switch ( V_183 ) {
case V_176 :
if ( F_12 ( V_171 , V_172 , type , V_184 ) )
return - 1 ;
break;
case V_185 :
case V_186 :
V_171 -> V_175 = F_5 ( V_183 ) ;
V_171 -> V_181 = F_5 ( V_177 ) ;
break;
default:
F_14 ( V_2 -> V_67 -> V_187 ,
L_1 , V_183 ) ;
return - 1 ;
}
return 0 ;
}
