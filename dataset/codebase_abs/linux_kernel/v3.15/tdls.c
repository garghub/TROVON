static void
F_1 ( struct V_1 * V_2 , T_1 * V_3 , T_1 V_4 )
{
struct V_5 * V_6 ;
struct V_7 * V_8 ;
struct V_9 * V_10 , * V_11 ;
struct V_12 * V_13 ;
unsigned long V_14 ;
T_2 V_15 ;
T_1 V_16 ;
F_2 ( V_2 -> V_17 -> V_18 , L_1 , V_19 , V_3 ) ;
F_3 ( & V_2 -> V_20 . V_21 , V_14 ) ;
F_4 (&priv->tdls_txq, skb, tmp) {
if ( ! F_5 ( V_3 , V_10 -> V_22 ) )
continue;
F_6 ( V_10 , & V_2 -> V_23 ) ;
V_13 = F_7 ( V_10 ) ;
V_15 = V_10 -> V_24 ;
V_16 = F_8 ( V_2 , V_15 ) ;
if ( V_4 == V_25 ) {
V_6 = F_9 ( V_2 , V_15 , V_3 ) ;
V_6 -> V_26 = true ;
V_13 -> V_14 |= V_27 ;
} else {
V_8 = & V_2 -> V_20 . V_28 [ V_16 ] . V_6 ;
if ( ! F_10 ( V_8 ) )
V_6 = F_11 ( V_8 ,
struct V_5 , V_29 ) ;
else
V_6 = NULL ;
V_13 -> V_14 &= ~ V_27 ;
}
if ( ! V_6 ) {
F_12 ( V_2 -> V_17 , V_10 , 0 , - 1 ) ;
continue;
}
F_13 ( & V_6 -> V_30 , V_10 ) ;
V_6 -> V_31 ++ ;
V_6 -> V_32 ++ ;
if ( F_14 ( & V_2 -> V_20 . V_33 ) <
V_34 [ V_16 ] )
F_15 ( & V_2 -> V_20 . V_33 ,
V_34 [ V_16 ] ) ;
F_16 ( & V_2 -> V_20 . V_35 ) ;
}
F_17 ( & V_2 -> V_20 . V_21 , V_14 ) ;
return;
}
static void F_18 ( struct V_1 * V_2 , T_1 * V_3 )
{
struct V_5 * V_6 ;
struct V_7 * V_36 ;
struct V_9 * V_10 , * V_11 ;
unsigned long V_14 ;
int V_37 ;
F_2 ( V_2 -> V_17 -> V_18 , L_1 , V_19 , V_3 ) ;
F_3 ( & V_2 -> V_20 . V_21 , V_14 ) ;
for ( V_37 = 0 ; V_37 < V_38 ; V_37 ++ ) {
if ( ! F_10 ( & V_2 -> V_20 . V_28 [ V_37 ] . V_6 ) ) {
V_36 = & V_2 -> V_20 . V_28 [ V_37 ] . V_6 ;
F_19 (ra_list, ra_list_head, list) {
F_4 (&ra_list->skb_head, skb,
tmp) {
if ( ! F_5 ( V_3 , V_10 -> V_22 ) )
continue;
F_6 ( V_10 , & V_6 -> V_30 ) ;
F_20 ( & V_2 -> V_20 . V_35 ) ;
V_6 -> V_32 -- ;
F_13 ( & V_2 -> V_23 , V_10 ) ;
}
}
}
}
F_17 ( & V_2 -> V_20 . V_21 , V_14 ) ;
return;
}
static int
F_21 ( struct V_1 * V_2 ,
struct V_9 * V_10 )
{
T_1 V_39 [ V_40 ] , * V_41 ;
T_3 V_42 , V_43 , V_44 ;
memset ( V_39 , 0 , sizeof( V_39 ) ) ;
V_42 = F_22 ( V_2 , V_39 ) ;
V_43 = F_23 ( T_3 , V_42 , V_45 ) ;
if ( F_24 ( V_10 ) < V_42 + 4 ) {
F_25 ( V_2 -> V_17 -> V_18 ,
L_2 ) ;
return - V_46 ;
}
V_41 = F_26 ( V_10 , V_43 + 2 ) ;
* V_41 ++ = V_47 ;
* V_41 ++ = V_43 ;
memcpy ( V_41 , V_39 , V_43 ) ;
if ( V_42 > V_45 ) {
V_44 = V_42 - V_45 ;
V_41 = F_26 ( V_10 , V_44 + 2 ) ;
* V_41 ++ = V_48 ;
* V_41 ++ = V_44 ;
memcpy ( V_41 , V_39 + V_45 ,
V_44 ) ;
}
return 0 ;
}
static void F_27 ( struct V_1 * V_2 ,
struct V_9 * V_10 )
{
struct V_49 * V_50 ;
T_1 * V_41 ;
V_50 = (struct V_49 * ) & V_2 -> V_51 ;
V_41 = ( void * ) F_26 ( V_10 , 4 ) ;
* V_41 ++ = V_52 ;
* V_41 ++ = 2 ;
* V_41 ++ = F_28 ( V_50 -> V_53 ) ;
return;
}
static int F_29 ( struct V_1 * V_2 ,
struct V_9 * V_10 )
{
struct V_54 V_55 ;
T_1 * V_41 ;
V_41 = ( void * ) F_26 ( V_10 , sizeof( struct V_54 ) + 2 ) ;
* V_41 ++ = V_56 ;
* V_41 ++ = sizeof( struct V_54 ) ;
memset ( & V_55 , 0 , sizeof( struct V_54 ) ) ;
F_30 ( V_2 , & V_55 , V_2 -> V_57 . V_58 ) ;
memcpy ( V_41 , & V_55 , sizeof( V_55 ) ) ;
return 0 ;
}
static int F_31 ( struct V_1 * V_2 ,
T_1 * V_3 , struct V_9 * V_10 )
{
struct V_59 * V_60 ;
struct V_61 * V_62 ;
struct V_54 * V_55 , * V_63 = NULL ;
struct V_64 * V_65 ;
struct V_66 * V_17 = V_2 -> V_17 ;
T_1 V_67 , V_68 ;
T_1 * V_41 , V_69 , V_70 ;
T_3 V_71 , V_72 , V_73 ;
T_3 V_74 , V_75 , V_76 ;
T_2 V_77 ;
V_60 = & V_2 -> V_57 . V_78 ;
V_65 = F_32 ( V_2 , V_3 ) ;
if ( F_33 ( ! V_65 ) ) {
F_34 ( V_17 -> V_18 , L_3 ) ;
return - 1 ;
}
if ( ! F_35 ( V_2 ) ) {
if ( V_65 -> V_79 . V_80 . V_81 [ 7 ] &
V_82 ) {
F_2 ( V_17 -> V_18 ,
L_4 ) ;
return 0 ;
}
} else {
V_63 = V_60 -> V_83 ;
}
V_41 = ( void * ) F_26 ( V_10 , sizeof( struct V_61 ) + 2 ) ;
* V_41 ++ = V_84 ;
* V_41 ++ = sizeof( struct V_61 ) ;
V_62 = (struct V_61 * ) V_41 ;
if ( V_60 -> V_85 & V_86 )
V_77 = V_17 -> V_87 ;
else
V_77 = V_17 -> V_88 ;
V_55 = & V_65 -> V_79 . V_89 ;
V_67 = F_36 ( V_77 ) ;
V_68 =
F_36 ( F_37 ( V_55 -> V_90 ) ) ;
V_67 = F_23 ( T_1 , V_67 , V_68 ) ;
if ( V_63 && V_65 -> V_79 . V_80 . V_81 [ 7 ] &
V_82 ) {
V_69 =
F_36 ( F_37 ( V_63 -> V_90 ) ) ;
V_67 = F_23 ( T_1 , V_67 , V_69 ) ;
}
switch ( V_67 ) {
case V_91 :
V_62 -> V_92 = V_91 ;
break;
case V_93 :
V_62 -> V_92 = V_93 ;
break;
case V_94 :
V_62 -> V_92 = V_94 ;
break;
default:
V_62 -> V_92 = V_95 ;
break;
}
V_71 = F_38 ( V_17 -> V_96 ) ;
V_72 = F_28 ( V_55 -> V_97 . V_98 ) ;
V_73 = 0 ;
for ( V_76 = 1 ; V_76 <= 8 ; V_76 ++ ) {
V_74 = F_39 ( V_71 , V_76 ) ;
V_75 = F_39 ( V_72 , V_76 ) ;
if ( ( V_74 == V_99 ) ||
( V_75 == V_99 ) )
F_40 ( V_73 , V_76 ,
V_99 ) ;
else
F_40 ( V_73 , V_76 ,
F_23 ( T_3 , V_74 , V_75 ) ) ;
}
V_62 -> V_100 = F_41 ( V_73 ) ;
switch ( V_62 -> V_92 ) {
case V_91 :
V_70 = V_91 ;
break;
case V_93 :
V_70 = V_93 ;
break;
case V_94 :
V_70 = V_91 ;
break;
default:
V_70 = V_95 ;
break;
}
V_62 -> V_101 =
F_42 ( V_2 , V_102 ,
V_60 -> V_103 ,
V_70 ) ;
return 0 ;
}
static void F_43 ( struct V_1 * V_2 ,
struct V_9 * V_10 )
{
struct V_104 * V_80 ;
V_80 = ( void * ) F_26 ( V_10 , sizeof( struct V_104 ) ) ;
V_80 -> V_105 . V_106 = V_107 ;
V_80 -> V_105 . V_108 = 8 ;
memset ( V_80 -> V_81 , 0 , 8 ) ;
V_80 -> V_81 [ 4 ] |= V_109 ;
if ( V_2 -> V_17 -> V_110 )
V_80 -> V_81 [ 7 ] |= V_82 ;
}
static void F_44 ( struct V_9 * V_10 )
{
T_1 * V_41 = ( void * ) F_26 ( V_10 , 3 ) ;
* V_41 ++ = V_111 ;
* V_41 ++ = 1 ;
* V_41 ++ = V_112 ;
}
static int F_45 ( struct V_1 * V_2 ,
T_1 * V_113 , T_1 V_114 , T_1 V_115 ,
T_3 V_116 , struct V_9 * V_10 )
{
struct V_117 * V_118 ;
int V_119 ;
T_3 V_120 ;
struct V_121 * V_122 ;
T_1 V_123 , * V_41 ;
V_120 = V_2 -> V_57 . V_78 . V_124 ;
V_118 = ( void * ) F_26 ( V_10 , F_46 ( struct V_117 , V_125 ) ) ;
memcpy ( V_118 -> V_126 , V_113 , V_127 ) ;
memcpy ( V_118 -> V_128 , V_2 -> V_129 , V_127 ) ;
V_118 -> V_130 = F_47 ( V_131 ) ;
V_118 -> V_132 = V_133 ;
switch ( V_114 ) {
case V_134 :
V_118 -> V_135 = V_136 ;
V_118 -> V_114 = V_134 ;
F_26 ( V_10 , sizeof( V_118 -> V_125 . V_137 ) ) ;
V_118 -> V_125 . V_137 . V_115 = V_115 ;
V_118 -> V_125 . V_137 . V_138 = F_41 ( V_120 ) ;
V_119 = F_21 ( V_2 , V_10 ) ;
if ( V_119 ) {
F_48 ( V_10 ) ;
return V_119 ;
}
V_41 = ( void * ) F_26 ( V_10 , sizeof( struct V_121 ) + 2 ) ;
* V_41 ++ = V_139 ;
* V_41 ++ = sizeof( struct V_121 ) ;
V_122 = ( void * ) V_41 ;
V_123 = F_49 ( V_2 -> V_57 . V_58 ) ;
V_119 = F_50 ( V_2 , V_123 , V_122 ) ;
if ( V_119 ) {
F_48 ( V_10 ) ;
return V_119 ;
}
if ( V_2 -> V_17 -> V_110 ) {
V_119 = F_29 ( V_2 , V_10 ) ;
if ( V_119 ) {
F_48 ( V_10 ) ;
return V_119 ;
}
F_27 ( V_2 , V_10 ) ;
}
F_43 ( V_2 , V_10 ) ;
F_44 ( V_10 ) ;
break;
case V_140 :
V_118 -> V_135 = V_136 ;
V_118 -> V_114 = V_140 ;
F_26 ( V_10 , sizeof( V_118 -> V_125 . V_141 ) ) ;
V_118 -> V_125 . V_141 . V_116 = F_41 ( V_116 ) ;
V_118 -> V_125 . V_141 . V_115 = V_115 ;
V_118 -> V_125 . V_141 . V_138 = F_41 ( V_120 ) ;
V_119 = F_21 ( V_2 , V_10 ) ;
if ( V_119 ) {
F_48 ( V_10 ) ;
return V_119 ;
}
V_41 = ( void * ) F_26 ( V_10 , sizeof( struct V_121 ) + 2 ) ;
* V_41 ++ = V_139 ;
* V_41 ++ = sizeof( struct V_121 ) ;
V_122 = ( void * ) V_41 ;
V_123 = F_49 ( V_2 -> V_57 . V_58 ) ;
V_119 = F_50 ( V_2 , V_123 , V_122 ) ;
if ( V_119 ) {
F_48 ( V_10 ) ;
return V_119 ;
}
if ( V_2 -> V_17 -> V_110 ) {
V_119 = F_29 ( V_2 , V_10 ) ;
if ( V_119 ) {
F_48 ( V_10 ) ;
return V_119 ;
}
F_27 ( V_2 , V_10 ) ;
}
F_43 ( V_2 , V_10 ) ;
F_44 ( V_10 ) ;
break;
case V_142 :
V_118 -> V_135 = V_136 ;
V_118 -> V_114 = V_142 ;
F_26 ( V_10 , sizeof( V_118 -> V_125 . V_143 ) ) ;
V_118 -> V_125 . V_143 . V_116 = F_41 ( V_116 ) ;
V_118 -> V_125 . V_143 . V_115 = V_115 ;
if ( V_2 -> V_17 -> V_110 ) {
V_119 = F_31 ( V_2 , V_113 , V_10 ) ;
if ( V_119 ) {
F_48 ( V_10 ) ;
return V_119 ;
}
}
break;
case V_144 :
V_118 -> V_135 = V_136 ;
V_118 -> V_114 = V_144 ;
F_26 ( V_10 , sizeof( V_118 -> V_125 . V_145 ) ) ;
V_118 -> V_125 . V_145 . V_146 = F_41 ( V_116 ) ;
break;
case V_147 :
V_118 -> V_135 = V_136 ;
V_118 -> V_114 = V_147 ;
F_26 ( V_10 , sizeof( V_118 -> V_125 . V_148 ) ) ;
V_118 -> V_125 . V_148 . V_115 = V_115 ;
break;
default:
F_25 ( V_2 -> V_17 -> V_18 , L_5 ) ;
return - V_149 ;
}
return 0 ;
}
static void
F_51 ( struct V_9 * V_10 , T_1 * V_150 , T_1 * V_113 , T_1 * V_151 )
{
struct V_152 * V_153 ;
V_153 = ( void * ) F_26 ( V_10 , sizeof( struct V_152 ) ) ;
V_153 -> V_154 = V_155 ;
V_153 -> V_156 = sizeof( struct V_152 ) -
sizeof( struct V_157 ) ;
memcpy ( V_153 -> V_151 , V_151 , V_127 ) ;
memcpy ( V_153 -> V_158 , V_150 , V_127 ) ;
memcpy ( V_153 -> V_159 , V_113 , V_127 ) ;
}
int F_52 ( struct V_1 * V_2 ,
T_1 * V_113 , T_1 V_114 , T_1 V_115 ,
T_3 V_116 , const T_1 * V_160 ,
T_4 V_161 )
{
struct V_9 * V_10 ;
struct V_12 * V_13 ;
struct V_162 V_163 ;
int V_119 ;
T_3 V_164 ;
V_164 = V_165 +
F_53 ( sizeof( struct V_166 ) ,
sizeof( struct V_117 ) ) +
V_167 +
V_40 +
3 +
sizeof( struct V_104 ) +
sizeof( struct V_121 ) +
sizeof( struct V_168 ) +
sizeof( struct V_169 ) +
sizeof( struct V_152 ) +
V_161 ;
if ( V_2 -> V_17 -> V_110 )
V_164 += sizeof( struct V_170 ) +
sizeof( struct V_171 ) +
sizeof( struct V_172 ) ;
V_10 = F_54 ( V_164 ) ;
if ( ! V_10 ) {
F_25 ( V_2 -> V_17 -> V_18 ,
L_6 ) ;
return - V_46 ;
}
F_55 ( V_10 , V_165 ) ;
switch ( V_114 ) {
case V_134 :
case V_142 :
case V_144 :
case V_147 :
V_119 = F_45 ( V_2 , V_113 , V_114 ,
V_115 , V_116 ,
V_10 ) ;
if ( V_119 ) {
F_48 ( V_10 ) ;
return V_119 ;
}
if ( V_161 )
memcpy ( F_26 ( V_10 , V_161 ) , V_160 ,
V_161 ) ;
F_51 ( V_10 , V_2 -> V_129 , V_113 ,
V_2 -> V_173 ) ;
break;
case V_140 :
V_119 = F_45 ( V_2 , V_113 , V_114 ,
V_115 , V_116 ,
V_10 ) ;
if ( V_119 ) {
F_48 ( V_10 ) ;
return V_119 ;
}
if ( V_161 )
memcpy ( F_26 ( V_10 , V_161 ) , V_160 ,
V_161 ) ;
F_51 ( V_10 , V_113 , V_2 -> V_129 ,
V_2 -> V_173 ) ;
break;
}
switch ( V_114 ) {
case V_134 :
case V_140 :
V_10 -> V_24 = V_174 ;
break;
default:
V_10 -> V_24 = V_175 ;
break;
}
V_13 = F_7 ( V_10 ) ;
V_13 -> V_176 = V_2 -> V_176 ;
V_13 -> V_177 = V_2 -> V_177 ;
F_56 ( & V_163 ) ;
V_10 -> V_178 = F_57 ( V_163 ) ;
F_58 ( V_2 , V_10 ) ;
return 0 ;
}
static int
F_59 ( struct V_1 * V_2 , T_1 * V_113 ,
T_1 V_114 , T_1 V_115 ,
T_3 V_116 , struct V_9 * V_10 )
{
struct V_166 * V_179 ;
T_1 V_180 [] = { 0xff , 0xff , 0xff , 0xff , 0xff , 0xff } ;
int V_119 ;
T_3 V_120 ;
struct V_121 * V_122 ;
T_1 V_123 , * V_41 ;
V_120 = V_2 -> V_57 . V_78 . V_124 ;
V_179 = ( void * ) F_26 ( V_10 , F_46 ( struct V_166 , V_125 ) ) ;
memset ( V_179 , 0 , 24 ) ;
memcpy ( V_179 -> V_126 , V_113 , V_127 ) ;
memcpy ( V_179 -> V_128 , V_2 -> V_129 , V_127 ) ;
memcpy ( V_179 -> V_151 , V_2 -> V_173 , V_127 ) ;
V_179 -> V_181 = F_41 ( V_182 |
V_183 ) ;
V_41 = F_26 ( V_10 , V_127 ) ;
switch ( V_114 ) {
case V_184 :
F_26 ( V_10 , sizeof( V_179 -> V_125 . V_185 . V_125 . V_186 ) + 1 ) ;
V_179 -> V_125 . V_185 . V_135 = V_187 ;
V_179 -> V_125 . V_185 . V_125 . V_186 . V_114 =
V_184 ;
V_179 -> V_125 . V_185 . V_125 . V_186 . V_115 =
V_115 ;
V_179 -> V_125 . V_185 . V_125 . V_186 . V_138 =
F_41 ( V_120 ) ;
memmove ( V_41 + V_127 , & V_179 -> V_125 . V_185 . V_135 ,
sizeof( V_179 -> V_125 . V_185 . V_125 . V_186 ) ) ;
memcpy ( V_41 , V_180 , V_127 ) ;
V_119 = F_21 ( V_2 , V_10 ) ;
if ( V_119 ) {
F_48 ( V_10 ) ;
return V_119 ;
}
V_41 = ( void * ) F_26 ( V_10 , sizeof( struct V_121 ) + 2 ) ;
* V_41 ++ = V_139 ;
* V_41 ++ = sizeof( struct V_121 ) ;
V_122 = ( void * ) V_41 ;
V_123 = F_49 ( V_2 -> V_57 . V_58 ) ;
V_119 = F_50 ( V_2 , V_123 , V_122 ) ;
if ( V_119 ) {
F_48 ( V_10 ) ;
return V_119 ;
}
if ( V_2 -> V_17 -> V_110 ) {
V_119 = F_29 ( V_2 , V_10 ) ;
if ( V_119 ) {
F_48 ( V_10 ) ;
return V_119 ;
}
F_27 ( V_2 , V_10 ) ;
}
F_43 ( V_2 , V_10 ) ;
F_44 ( V_10 ) ;
break;
default:
F_25 ( V_2 -> V_17 -> V_18 , L_7 ) ;
return - V_149 ;
}
return 0 ;
}
int F_60 ( struct V_1 * V_2 ,
T_1 * V_113 , T_1 V_114 , T_1 V_115 ,
T_3 V_116 , const T_1 * V_160 ,
T_4 V_161 )
{
struct V_9 * V_10 ;
struct V_12 * V_13 ;
struct V_162 V_163 ;
T_1 * V_41 ;
T_2 V_188 , V_189 ;
T_3 V_190 , V_164 ;
V_164 = V_165 +
F_53 ( sizeof( struct V_166 ) ,
sizeof( struct V_117 ) ) +
V_167 +
V_40 +
sizeof( struct V_104 ) +
sizeof( struct V_121 ) +
sizeof( struct V_168 ) +
sizeof( struct V_169 ) +
sizeof( struct V_152 ) +
V_161 +
3 +
V_127 ;
if ( V_2 -> V_17 -> V_110 )
V_164 += sizeof( struct V_170 ) +
sizeof( struct V_171 ) +
sizeof( struct V_172 ) ;
V_10 = F_54 ( V_164 ) ;
if ( ! V_10 ) {
F_25 ( V_2 -> V_17 -> V_18 ,
L_6 ) ;
return - V_46 ;
}
F_55 ( V_10 , V_165 ) ;
V_188 = V_191 ;
V_189 = 0 ;
V_41 = F_26 ( V_10 , V_167 + sizeof( V_190 ) ) ;
memset ( V_41 , 0 , V_167 + sizeof( V_190 ) ) ;
memcpy ( V_41 , & V_188 , sizeof( V_188 ) ) ;
memcpy ( V_41 + sizeof( V_188 ) , & V_189 , sizeof( V_189 ) ) ;
if ( F_59 ( V_2 , V_113 , V_114 ,
V_115 , V_116 ,
V_10 ) ) {
F_48 ( V_10 ) ;
return - V_149 ;
}
if ( V_161 )
memcpy ( F_26 ( V_10 , V_161 ) , V_160 , V_161 ) ;
F_51 ( V_10 , V_113 , V_2 -> V_129 ,
V_2 -> V_173 ) ;
V_10 -> V_24 = V_175 ;
V_13 = F_7 ( V_10 ) ;
V_13 -> V_176 = V_2 -> V_176 ;
V_13 -> V_177 = V_2 -> V_177 ;
V_13 -> V_14 |= V_27 ;
V_190 = V_10 -> V_108 - V_167 - sizeof( V_190 ) ;
memcpy ( V_10 -> V_22 + V_167 , & V_190 ,
sizeof( V_190 ) ) ;
F_56 ( & V_163 ) ;
V_10 -> V_178 = F_57 ( V_163 ) ;
F_58 ( V_2 , V_10 ) ;
return 0 ;
}
void F_61 ( struct V_1 * V_2 ,
T_1 * V_192 , int V_108 )
{
struct V_64 * V_65 ;
T_1 * V_113 , * V_41 , * V_193 ;
T_1 V_37 , V_185 , V_194 ;
int V_156 = 0 ;
if ( V_108 < ( sizeof( struct V_195 ) + 3 ) )
return;
if ( * ( V_192 + sizeof( struct V_195 ) ) != V_133 )
return;
if ( * ( V_192 + sizeof( struct V_195 ) + 1 ) != V_136 )
return;
V_113 = V_192 + V_127 ;
V_185 = * ( V_192 + sizeof( struct V_195 ) + 2 ) ;
if ( V_185 > V_142 )
return;
F_2 ( V_2 -> V_17 -> V_18 ,
L_8 , V_113 , V_185 ) ;
V_65 = F_62 ( V_2 , V_113 ) ;
if ( ! V_65 )
return;
switch ( V_185 ) {
case V_134 :
if ( V_108 < ( sizeof( struct V_195 ) + V_196 ) )
return;
V_41 = V_192 + sizeof( struct V_195 ) + 4 ;
V_65 -> V_79 . V_120 = F_41 ( * ( T_3 * ) V_41 ) ;
V_156 = V_108 - sizeof( struct V_195 ) - V_196 ;
V_41 += 2 ;
break;
case V_140 :
if ( V_108 < ( sizeof( struct V_195 ) + V_197 ) )
return;
V_41 = V_192 + sizeof( struct V_195 ) + 6 ;
V_65 -> V_79 . V_120 = F_41 ( * ( T_3 * ) V_41 ) ;
V_156 = V_108 - sizeof( struct V_195 ) - V_197 ;
V_41 += 2 ;
break;
case V_142 :
if ( V_108 < ( sizeof( struct V_195 ) + V_198 ) )
return;
V_41 = V_192 + sizeof( struct V_195 ) + V_198 ;
V_156 = V_108 - sizeof( struct V_195 ) - V_198 ;
break;
default:
F_34 ( V_2 -> V_17 -> V_18 , L_5 ) ;
return;
}
for ( V_193 = V_41 + V_156 ; V_41 + 1 < V_193 ; V_41 += 2 + V_41 [ 1 ] ) {
if ( V_41 + 2 + V_41 [ 1 ] > V_193 )
break;
switch ( * V_41 ) {
case V_47 :
V_65 -> V_79 . V_199 = V_41 [ 1 ] ;
for ( V_37 = 0 ; V_37 < V_41 [ 1 ] ; V_37 ++ )
V_65 -> V_79 . V_39 [ V_37 ] = V_41 [ V_37 + 2 ] ;
break;
case V_48 :
V_194 = V_65 -> V_79 . V_199 ;
for ( V_37 = 0 ; V_37 < V_41 [ 1 ] ; V_37 ++ )
V_65 -> V_79 . V_39 [ V_194 + V_37 ] = V_41 [ V_37 + 2 ] ;
V_65 -> V_79 . V_199 += V_41 [ 1 ] ;
break;
case V_139 :
memcpy ( ( T_1 * ) & V_65 -> V_79 . V_200 , V_41 ,
sizeof( struct V_121 ) ) ;
V_65 -> V_201 = 1 ;
break;
case V_202 :
memcpy ( & V_65 -> V_79 . V_203 , V_41 ,
sizeof( struct V_169 ) ) ;
break;
case V_204 :
V_65 -> V_79 . V_205 = V_41 [ 2 ] ;
break;
case V_107 :
memcpy ( ( T_1 * ) & V_65 -> V_79 . V_80 , V_41 ,
sizeof( struct V_157 ) +
F_23 ( T_1 , V_41 [ 1 ] , 8 ) ) ;
break;
case V_206 :
memcpy ( ( T_1 * ) & V_65 -> V_79 . V_207 , V_41 ,
sizeof( struct V_157 ) + V_41 [ 1 ] ) ;
break;
case V_111 :
V_65 -> V_79 . V_208 = V_41 [ 2 ] ;
break;
case V_84 :
if ( V_2 -> V_17 -> V_110 )
memcpy ( & V_65 -> V_79 . V_209 , V_41 ,
sizeof( struct V_61 ) ) ;
break;
case V_56 :
if ( V_2 -> V_17 -> V_110 ) {
memcpy ( ( T_1 * ) & V_65 -> V_79 . V_89 , V_41 ,
sizeof( struct V_54 ) ) ;
V_65 -> V_210 = 1 ;
}
break;
case V_52 :
if ( V_2 -> V_17 -> V_110 )
V_65 -> V_79 . V_211 =
F_28 ( * ( V_212 * ) ( V_41 + 2 ) ) ;
default:
break;
}
}
return;
}
static int
F_63 ( struct V_1 * V_2 , T_1 * V_113 )
{
struct V_64 * V_65 ;
struct V_213 V_214 ;
memset ( & V_214 , 0 , sizeof( struct V_213 ) ) ;
V_65 = F_32 ( V_2 , V_113 ) ;
if ( ! V_65 || V_65 -> V_215 == V_216 ) {
F_25 ( V_2 -> V_17 -> V_18 ,
L_9 , V_113 ) ;
return - V_149 ;
}
memcpy ( & V_214 . V_217 , V_113 , V_127 ) ;
V_214 . V_218 = V_219 ;
return F_64 ( V_2 , V_220 ,
V_221 , 0 , & V_214 , true ) ;
}
static int
F_65 ( struct V_1 * V_2 , T_1 * V_113 )
{
struct V_64 * V_65 ;
struct V_213 V_214 ;
memset ( & V_214 , 0 , sizeof( struct V_213 ) ) ;
V_65 = F_32 ( V_2 , V_113 ) ;
if ( V_65 && V_65 -> V_215 == V_222 ) {
F_2 ( V_2 -> V_17 -> V_18 ,
L_10 , V_113 ) ;
return 0 ;
}
V_65 = F_62 ( V_2 , V_113 ) ;
if ( ! V_65 )
return - V_46 ;
V_65 -> V_215 = V_222 ;
F_18 ( V_2 , V_113 ) ;
memcpy ( & V_214 . V_217 , V_113 , V_127 ) ;
V_214 . V_218 = V_223 ;
return F_64 ( V_2 , V_220 ,
V_221 , 0 , & V_214 , true ) ;
}
static int
F_66 ( struct V_1 * V_2 , T_1 * V_113 )
{
struct V_64 * V_65 ;
struct V_213 V_214 ;
unsigned long V_14 ;
memset ( & V_214 , 0 , sizeof( struct V_213 ) ) ;
V_65 = F_32 ( V_2 , V_113 ) ;
if ( V_65 ) {
if ( V_65 -> V_201 ) {
F_67 ( V_2 ) ;
F_3 ( & V_2 -> V_20 . V_21 ,
V_14 ) ;
F_68 ( V_2 ) ;
F_17 ( & V_2 -> V_20 . V_21 ,
V_14 ) ;
}
F_69 ( V_2 , V_113 ) ;
}
F_1 ( V_2 , V_113 , V_224 ) ;
memcpy ( & V_214 . V_217 , V_113 , V_127 ) ;
V_214 . V_218 = V_225 ;
return F_64 ( V_2 , V_220 ,
V_221 , 0 , & V_214 , true ) ;
}
static int
F_70 ( struct V_1 * V_2 , T_1 * V_113 )
{
struct V_64 * V_65 ;
struct V_226 V_227 ;
unsigned long V_14 ;
int V_37 ;
V_65 = F_32 ( V_2 , V_113 ) ;
if ( V_65 && ( V_65 -> V_215 != V_216 ) ) {
F_2 ( V_2 -> V_17 -> V_18 ,
L_11 , V_113 ) ;
V_65 -> V_215 = V_25 ;
V_227 = V_65 -> V_79 . V_200 . V_227 ;
if ( V_227 . V_228 [ 0 ] != 0xff )
V_65 -> V_201 = true ;
if ( V_65 -> V_201 ) {
if ( F_28 ( V_65 -> V_79 . V_200 . V_229 ) &
V_230 )
V_65 -> V_231 =
V_232 ;
else
V_65 -> V_231 =
V_233 ;
for ( V_37 = 0 ; V_37 < V_38 ; V_37 ++ )
V_65 -> V_234 [ V_37 ] =
V_2 -> V_235 [ V_37 ] . V_236 ;
} else {
for ( V_37 = 0 ; V_37 < V_38 ; V_37 ++ )
V_65 -> V_234 [ V_37 ] = V_237 ;
}
memset ( V_65 -> V_238 , 0xff , sizeof( V_65 -> V_238 ) ) ;
F_1 ( V_2 , V_113 , V_25 ) ;
} else {
F_2 ( V_2 -> V_17 -> V_18 ,
L_12 , V_113 ) ;
if ( V_65 ) {
F_67 ( V_2 ) ;
F_3 ( & V_2 -> V_20 . V_21 ,
V_14 ) ;
F_68 ( V_2 ) ;
F_17 ( & V_2 -> V_20 . V_21 ,
V_14 ) ;
F_69 ( V_2 , V_113 ) ;
}
F_1 ( V_2 , V_113 , V_224 ) ;
return - 1 ;
}
return 0 ;
}
int F_71 ( struct V_1 * V_2 , T_1 * V_113 , T_1 V_185 )
{
switch ( V_185 ) {
case V_239 :
return F_70 ( V_2 , V_113 ) ;
case V_225 :
return F_66 ( V_2 , V_113 ) ;
case V_223 :
return F_65 ( V_2 , V_113 ) ;
case V_219 :
return F_63 ( V_2 , V_113 ) ;
}
return 0 ;
}
int F_72 ( struct V_1 * V_2 , T_1 * V_3 )
{
struct V_64 * V_65 ;
V_65 = F_32 ( V_2 , V_3 ) ;
if ( V_65 )
return V_65 -> V_215 ;
return V_240 ;
}
void F_73 ( struct V_1 * V_2 )
{
struct V_64 * V_65 ;
struct V_213 V_214 ;
unsigned long V_14 ;
if ( F_10 ( & V_2 -> V_241 ) )
return;
F_19 (sta_ptr, &priv->sta_list, list) {
memset ( & V_214 , 0 , sizeof( struct V_213 ) ) ;
if ( V_65 -> V_201 ) {
F_67 ( V_2 ) ;
F_3 ( & V_2 -> V_20 . V_21 ,
V_14 ) ;
F_68 ( V_2 ) ;
F_17 ( & V_2 -> V_20 . V_21 ,
V_14 ) ;
}
F_1 ( V_2 , V_65 -> V_242 ,
V_224 ) ;
memcpy ( & V_214 . V_217 , V_65 -> V_242 , V_127 ) ;
V_214 . V_218 = V_225 ;
if ( F_64 ( V_2 , V_220 ,
V_221 , 0 , & V_214 , false ) )
F_34 ( V_2 -> V_17 -> V_18 ,
L_13 ,
V_65 -> V_242 ) ;
}
F_74 ( V_2 ) ;
}
