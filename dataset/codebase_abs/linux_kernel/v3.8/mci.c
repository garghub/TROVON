static struct V_1 *
F_1 ( struct V_2 * V_3 ,
struct V_1 * V_4 )
{
struct V_1 * V_5 ;
if ( F_2 ( & V_3 -> V_4 ) )
return NULL ;
F_3 (entry, &mci->info, list) {
if ( V_5 -> V_6 == V_4 -> V_6 )
return V_5 ;
}
return NULL ;
}
static bool F_4 ( struct V_7 * V_8 ,
struct V_2 * V_3 ,
struct V_1 * V_4 )
{
struct V_1 * V_5 ;
T_1 V_9 [] = { 110 , 110 , 110 , 112 , 110 , 110 , 114 , 116 , 118 } ;
if ( ( V_3 -> V_10 == V_11 ) &&
( V_4 -> type == V_12 ) )
return false ;
if ( ( ( F_5 ( V_3 ) - V_3 -> V_10 ) == V_13 ) &&
( V_4 -> type != V_12 ) )
return false ;
V_5 = F_6 ( sizeof( * V_5 ) , V_14 ) ;
if ( ! V_5 )
return false ;
memcpy ( V_5 , V_4 , 10 ) ;
F_7 ( V_3 , V_4 ) ;
F_8 ( & V_5 -> V_15 , & V_3 -> V_4 ) ;
if ( V_4 -> type == V_12 ) {
if ( V_4 -> V_16 < sizeof( V_9 ) )
V_3 -> V_9 = V_9 [ V_4 -> V_16 ] ;
else
V_3 -> V_9 = 110 ;
}
return true ;
}
static void F_9 ( struct V_7 * V_8 ,
struct V_2 * V_3 ,
struct V_1 * V_5 )
{
if ( ! V_5 )
return;
F_10 ( V_3 , V_5 ) ;
F_11 ( & V_5 -> V_15 ) ;
F_12 ( V_5 ) ;
}
void F_13 ( struct V_2 * V_3 )
{
struct V_1 * V_4 , * V_17 ;
V_3 -> V_18 = 0 ;
V_3 -> V_19 = 0 ;
if ( F_2 ( & V_3 -> V_4 ) )
return;
F_14 (info, tinfo, &mci->info, list) {
F_11 ( & V_4 -> V_15 ) ;
F_10 ( V_3 , V_4 ) ;
F_12 ( V_4 ) ;
}
}
static void F_15 ( struct V_20 * V_21 )
{
struct V_2 * V_3 = & V_21 -> V_3 ;
T_2 V_22 = V_21 -> V_23 *
( 100 - V_21 -> V_24 ) / 100 ;
if ( ( V_22 <= 4 ) &&
( ! V_3 -> V_18 || ( V_3 -> V_18 > ( 2 * V_22 ) ) ) )
V_3 -> V_18 = 2 * V_22 ;
}
static void F_16 ( struct V_25 * V_26 )
{
struct V_7 * V_8 = F_17 ( V_26 -> V_27 ) ;
struct V_20 * V_21 = & V_26 -> V_21 ;
struct V_2 * V_3 = & V_21 -> V_3 ;
struct V_28 * V_29 = & V_26 -> V_27 -> V_30 . V_3 ;
struct V_1 * V_4 ;
T_2 V_31 = F_5 ( V_3 ) ;
if ( V_29 -> V_32 & V_33 )
goto V_34;
V_3 -> V_18 = 0 ;
V_21 -> V_24 = V_35 [ V_31 ] ;
V_21 -> V_23 = V_36 ;
if ( F_5 ( V_3 ) )
V_21 -> V_37 = V_38 ;
else
V_21 -> V_37 = V_3 -> V_19 ? V_39 :
V_38 ;
if ( V_31 == 1 ) {
V_4 = F_18 ( & V_3 -> V_4 ,
struct V_1 ,
V_15 ) ;
if ( V_3 -> V_10 ) {
if ( V_4 -> V_40 == 12 )
V_3 -> V_18 = 8 ;
else if ( V_4 -> V_40 == 6 ) {
V_3 -> V_18 = 6 ;
V_21 -> V_24 = 30 ;
} else
V_3 -> V_18 = 6 ;
F_19 ( V_8 , V_41 ,
L_1 ,
V_3 -> V_18 ) ;
} else if ( V_3 -> V_42 || V_3 -> V_43 ) {
V_21 -> V_24 = F_20 ( V_26 -> V_27 ) ? 40 : 35 ;
V_21 -> V_23 = 53 ;
F_19 ( V_8 , V_41 ,
L_2 ,
V_21 -> V_24 , V_21 -> V_23 ) ;
} else if ( V_3 -> V_44 ) {
V_21 -> V_24 = 30 ;
V_3 -> V_18 = 6 ;
F_19 ( V_8 , V_41 ,
L_3
L_4 ) ;
}
} else if ( V_31 == 2 ) {
if ( V_3 -> V_44 == 2 )
V_21 -> V_24 = 30 ;
V_3 -> V_18 = 6 ;
F_19 ( V_8 , V_41 ,
L_5 ,
V_21 -> V_24 ) ;
} else if ( V_31 >= 3 ) {
V_3 -> V_18 = 4 ;
F_19 ( V_8 , V_41 ,
L_6 ) ;
}
V_34:
if ( F_21 ( V_26 -> V_27 -> V_45 ) ) {
if ( F_22 ( V_26 -> V_27 -> V_45 ) )
F_15 ( V_21 ) ;
else
V_21 -> V_23 >>= 1 ;
}
F_23 ( V_26 ) ;
F_24 ( V_26 -> V_27 ) ;
if ( F_25 ( V_26 -> V_27 -> V_45 ) )
return;
V_21 -> V_24 += ( V_3 -> V_46 ? V_47 : 0 ) ;
if ( V_21 -> V_24 > V_48 )
V_21 -> V_24 = V_48 ;
V_21 -> V_49 = V_21 -> V_23 * 1000 *
( 100 - V_21 -> V_24 ) / 100 ;
F_26 ( V_26 -> V_27 ) ;
F_27 ( V_26 ) ;
}
static void F_28 ( struct V_25 * V_26 , T_1 V_50 , T_1 * V_51 )
{
struct V_52 * V_53 = V_26 -> V_27 ;
struct V_7 * V_8 = F_17 ( V_53 ) ;
struct V_28 * V_29 = & V_53 -> V_30 . V_3 ;
T_2 V_54 [ 4 ] = { 0 , 0 , 0 , 0 } ;
switch ( V_50 ) {
case V_55 :
if ( V_29 -> V_56 == V_57 ) {
V_29 -> V_56 = V_58 ;
F_29 ( V_26 , V_59 ) ;
}
F_19 ( V_8 , V_41 , L_7 , V_29 -> V_56 ) ;
break;
case V_60 :
F_30 ( V_54 , V_61 ) ;
F_31 ( V_26 -> V_27 , V_62 , 0 , V_54 ,
16 , false , true ) ;
break;
default:
F_19 ( V_8 , V_41 , L_8 ) ;
break;
}
}
static void F_32 ( struct V_63 * V_64 )
{
struct V_25 * V_26 = F_33 ( V_64 , struct V_25 , V_65 ) ;
F_16 ( V_26 ) ;
}
static void F_34 ( T_1 V_66 , T_1 * V_67 )
{
if ( V_66 < V_67 [ V_68 ] )
V_67 [ V_68 ] = V_66 ;
if ( V_66 > V_67 [ V_39 ] )
V_67 [ V_39 ] = V_66 ;
if ( ( V_66 > V_69 ) &&
( V_66 < V_67 [ V_38 ] ) )
V_67 [ V_38 ] = V_66 ;
}
static void F_35 ( struct V_25 * V_26 )
{
struct V_20 * V_21 = & V_26 -> V_21 ;
struct V_2 * V_3 = & V_21 -> V_3 ;
T_1 V_70 [ V_71 ] ;
memset ( V_70 , 0 , sizeof( V_70 ) ) ;
if ( V_3 -> V_19 ) {
V_70 [ V_39 ] = V_72 ;
if ( ! V_3 -> V_42 && ! V_3 -> V_43 )
V_70 [ V_68 ] =
V_72 ;
} else {
T_1 V_73 [] = { 50 , 90 , 94 , 52 } ;
V_70 [ V_38 ] =
V_70 [ V_68 ] = 0xff ;
if ( V_3 -> V_10 )
F_34 ( V_3 -> V_9 ,
V_70 ) ;
if ( V_3 -> V_43 )
F_34 ( V_73 [ 0 ] , V_70 ) ;
if ( V_3 -> V_74 )
F_34 ( V_73 [ 1 ] , V_70 ) ;
if ( V_3 -> V_44 )
F_34 ( V_73 [ 2 ] , V_70 ) ;
if ( V_3 -> V_42 )
F_34 ( V_73 [ 3 ] , V_70 ) ;
if ( V_70 [ V_68 ] == 0xff )
V_70 [ V_68 ] = 0 ;
if ( V_70 [ V_38 ] == 0xff )
V_70 [ V_38 ] = 0 ;
}
F_36 ( V_26 -> V_27 , V_70 ) ;
}
static T_1 F_37 ( struct V_25 * V_26 ,
struct V_1 * V_4 )
{
struct V_7 * V_8 = F_17 ( V_26 -> V_27 ) ;
struct V_20 * V_21 = & V_26 -> V_21 ;
struct V_2 * V_3 = & V_21 -> V_3 ;
struct V_1 * V_5 = NULL ;
V_5 = F_1 ( V_3 , V_4 ) ;
if ( V_5 ) {
if ( V_5 -> type != V_4 -> type ) {
F_10 ( V_3 , V_5 ) ;
F_7 ( V_3 , V_4 ) ;
}
memcpy ( V_5 , V_4 , 10 ) ;
}
if ( V_4 -> V_75 ) {
if ( ! V_5 && ! F_4 ( V_8 , V_3 , V_4 ) )
return 0 ;
} else
F_9 ( V_8 , V_3 , V_5 ) ;
F_35 ( V_26 ) ;
return 1 ;
}
static T_1 F_38 ( struct V_25 * V_26 ,
struct V_76 * V_77 )
{
struct V_20 * V_21 = & V_26 -> V_21 ;
struct V_2 * V_3 = & V_21 -> V_3 ;
struct V_1 V_4 ;
int V_78 = 0 , V_79 = V_3 -> V_19 ;
if ( V_77 -> V_80 )
return 0 ;
V_4 . V_6 = V_77 -> V_6 ;
if ( F_1 ( V_3 , & V_4 ) )
return 0 ;
if ( V_77 -> V_6 >= V_81 )
return 0 ;
if ( V_77 -> V_82 )
F_39 ( V_77 -> V_6 , V_3 -> V_77 ) ;
else
F_40 ( V_77 -> V_6 , V_3 -> V_77 ) ;
V_3 -> V_19 = 0 ;
do {
if ( F_41 ( V_78 , V_3 -> V_77 ) )
V_3 -> V_19 ++ ;
} while ( ++ V_78 < V_81 );
F_35 ( V_26 ) ;
if ( V_79 != V_3 -> V_19 )
return 1 ;
return 0 ;
}
static void F_42 ( struct V_25 * V_26 , T_1 V_50 , T_1 * V_51 )
{
struct V_52 * V_53 = V_26 -> V_27 ;
struct V_1 V_83 ;
struct V_76 V_84 ;
struct V_7 * V_8 = F_17 ( V_26 -> V_27 ) ;
T_1 V_85 , V_86 , V_87 = 0 ;
T_2 V_88 ;
if ( F_43 ( V_53 , V_89 ) &&
F_43 ( V_53 , V_90 ) ) {
F_19 ( V_8 , V_41 , L_9 ) ;
F_13 ( & V_26 -> V_21 . V_3 ) ;
F_43 ( V_53 , V_91 ) ;
}
switch ( V_50 ) {
case V_92 :
F_43 ( V_53 , V_93 ) ;
break;
case V_94 :
V_85 = * ( V_51 + V_95 ) ;
V_86 = * ( V_51 + V_96 ) ;
F_44 ( V_53 , V_85 , V_86 ) ;
break;
case V_97 :
F_45 ( V_53 ) ;
break;
case V_98 :
memcpy ( & V_83 ,
( V_51 + V_99 ) , 10 ) ;
if ( ( V_83 . type == V_100 ) ||
( V_83 . type >= V_101 ) ) {
F_19 ( V_8 , V_41 ,
L_10 ,
V_83 . type ,
V_83 . V_75 ) ;
break;
}
V_87 += F_37 ( V_26 , & V_83 ) ;
break;
case V_102 :
V_84 . V_80 = * ( V_51 +
V_103 ) ;
V_84 . V_6 = * ( V_51 +
V_104 ) ;
V_84 . V_82 = * ( V_51 +
V_105 ) ;
V_88 = * ( ( T_2 * ) ( V_51 + 12 ) ) ;
F_19 ( V_8 , V_41 ,
L_11 ,
V_84 . V_80 , V_84 . V_6 ,
V_84 . V_82 , V_88 ) ;
V_87 += F_38 ( V_26 , & V_84 ) ;
break;
default:
F_19 ( V_8 , V_41 , L_12 , V_50 ) ;
break;
}
if ( V_87 )
F_46 ( V_26 -> V_106 , & V_26 -> V_65 ) ;
}
int F_47 ( struct V_25 * V_26 )
{
struct V_7 * V_8 = F_17 ( V_26 -> V_27 ) ;
struct V_107 * V_3 = & V_26 -> V_108 ;
struct V_109 * V_110 = & V_3 -> V_111 ;
int V_112 ;
V_110 -> V_113 = F_48 ( V_26 -> V_114 ,
V_115 + V_116 ,
& V_110 -> V_117 , V_118 ) ;
if ( V_110 -> V_113 == NULL ) {
F_19 ( V_8 , V_119 , L_13 ) ;
return - V_120 ;
}
memset ( V_110 -> V_113 , V_121 ,
V_115 + V_116 ) ;
V_3 -> V_111 . V_122 = V_115 ;
V_3 -> V_123 . V_122 = V_116 ;
V_3 -> V_123 . V_113 = ( T_1 * ) V_3 -> V_111 . V_113 + V_3 -> V_111 . V_122 ;
V_3 -> V_123 . V_117 = V_3 -> V_111 . V_117 + V_3 -> V_111 . V_122 ;
V_112 = F_49 ( V_26 -> V_27 , V_3 -> V_123 . V_117 ,
V_3 -> V_123 . V_113 , ( V_3 -> V_123 . V_122 >> 4 ) ,
V_3 -> V_111 . V_117 ) ;
if ( V_112 ) {
F_50 ( V_8 , L_14 ) ;
return V_112 ;
}
F_51 ( & V_26 -> V_65 , F_32 ) ;
F_19 ( V_8 , V_41 , L_15 ) ;
return 0 ;
}
void F_52 ( struct V_25 * V_26 )
{
struct V_7 * V_8 = F_17 ( V_26 -> V_27 ) ;
struct V_52 * V_53 = V_26 -> V_27 ;
struct V_107 * V_3 = & V_26 -> V_108 ;
struct V_109 * V_110 = & V_3 -> V_111 ;
if ( V_110 -> V_113 )
F_53 ( V_26 -> V_114 ,
V_115 + V_116 ,
V_110 -> V_113 , V_110 -> V_117 ) ;
F_54 ( V_53 ) ;
F_19 ( V_8 , V_41 , L_16 ) ;
}
void F_55 ( struct V_25 * V_26 )
{
struct V_107 * V_3 = & V_26 -> V_108 ;
struct V_52 * V_53 = V_26 -> V_27 ;
struct V_7 * V_8 = F_17 ( V_53 ) ;
struct V_28 * V_29 = & V_53 -> V_30 . V_3 ;
T_2 V_124 , V_125 ;
T_2 V_126 , V_127 , V_50 ;
T_2 * V_128 ;
T_2 V_129 = V_130 ;
bool V_131 = false ;
F_56 ( V_26 -> V_27 , & V_124 , & V_125 ) ;
if ( F_43 ( V_53 , V_90 ) == 0 ) {
F_57 ( V_53 , true , NULL ) ;
return;
}
if ( V_125 & V_132 ) {
T_2 V_54 [ 4 ] = { 0xffffffff , 0xffffffff ,
0xffffffff , 0xffffff00 } ;
F_31 ( V_53 , V_133 , 0 ,
V_54 , 16 , true , false ) ;
F_31 ( V_53 , V_134 , 0 ,
NULL , 0 , true , false ) ;
V_125 &= ~ V_132 ;
F_43 ( V_53 , V_135 ) ;
F_43 ( V_53 , V_136 ) ;
}
if ( V_125 & V_137 ) {
V_125 &= ~ V_137 ;
if ( ( V_29 -> V_56 == V_138 ) &&
( F_43 ( V_53 , V_139 ) !=
V_138 ) )
F_43 ( V_53 , V_136 ) ;
}
if ( V_125 & V_140 ) {
V_125 &= ~ V_140 ;
if ( ( V_29 -> V_56 == V_57 ) &&
( F_43 ( V_53 , V_139 ) !=
V_57 ) )
V_29 -> V_56 = V_138 ;
}
if ( ( V_124 & V_141 ) ||
( V_124 & V_142 ) ) {
F_43 ( V_53 , V_143 ) ;
V_131 = true ;
}
if ( V_125 & V_144 ) {
V_125 &= ~ V_144 ;
V_126 = F_43 ( V_53 , V_145 ) ;
}
if ( V_125 & V_146 ) {
V_125 &= ~ V_146 ;
while ( V_129 == V_130 ) {
if ( F_41 ( V_147 , & V_26 -> V_148 ) )
return;
V_128 = V_3 -> V_123 . V_113 ;
V_126 = F_57 ( V_53 , false ,
& V_129 ) ;
if ( V_126 == V_149 )
break;
V_128 += ( V_126 >> 2 ) ;
V_127 = F_58 ( V_128 ) ;
V_50 = F_59 ( V_128 ) ;
if ( V_131 )
goto V_150;
if ( F_60 ( V_127 ) ) {
F_28 ( V_26 , V_127 , ( T_1 * ) V_128 ) ;
} else {
switch ( V_127 ) {
case V_151 :
F_42 ( V_26 , V_50 , ( T_1 * ) V_128 ) ;
break;
default:
break;
}
}
V_150:
F_61 ( V_128 ) ;
}
}
if ( V_125 & V_152 ) {
if ( V_125 & V_153 )
V_125 &= ~ V_153 ;
if ( V_125 & V_154 )
V_125 &= ~ V_154 ;
if ( V_125 & V_155 ) {
int V_156 = F_62 ( V_29 -> V_157 ,
V_158 ) ;
V_125 &= ~ V_155 ;
F_19 ( V_8 , V_41 ,
L_17 ,
F_62 ( V_29 -> V_157 , V_159 ) ?
L_18 : L_19 ,
F_62 ( V_29 -> V_157 , V_160 ) ,
V_156 ) ;
}
if ( V_125 & V_161 )
V_125 &= ~ V_161 ;
if ( V_125 & V_162 )
V_125 &= ~ V_162 ;
}
if ( ( V_124 & V_141 ) ||
( V_124 & V_142 ) ) {
V_124 &= ~ ( V_141 |
V_142 ) ;
F_42 ( V_26 , V_163 , NULL ) ;
}
}
void F_63 ( struct V_25 * V_26 )
{
struct V_7 * V_8 = F_17 ( V_26 -> V_27 ) ;
if ( ! V_8 -> V_164 )
return;
if ( V_26 -> V_27 -> V_165 . V_166 & V_167 )
V_26 -> V_27 -> V_168 |= V_169 ;
}
void F_64 ( struct V_25 * V_26 , bool V_170 )
{
struct V_52 * V_53 = V_26 -> V_27 ;
struct V_28 * V_3 = & V_53 -> V_30 . V_3 ;
struct V_171 * V_172 = V_53 -> V_45 ;
T_2 V_173 [] = { 0x00000000 , 0xffff0000 , 0xffffffff , 0x7fffffff } ;
int V_78 ;
T_3 V_174 , V_175 ;
T_4 V_176 ;
if ( ! V_172 || ! F_21 ( V_172 ) )
return;
if ( V_170 )
goto V_177;
V_176 = V_172 -> V_178 - 2402 ;
V_174 = V_176 - 10 ;
V_175 = V_176 + 10 ;
if ( V_172 -> V_179 == V_180 )
V_175 += 20 ;
else if ( V_172 -> V_179 == V_181 )
V_174 -= 20 ;
V_174 -= 7 ;
V_175 += 7 ;
if ( V_174 <= 0 )
V_174 = 0 ;
if ( V_175 >= V_182 )
V_175 = V_182 - 1 ;
F_19 ( F_17 ( V_53 ) , V_41 ,
L_20 ,
V_176 , V_174 , V_175 ) ;
for ( V_78 = V_174 ; V_78 < V_175 ; V_78 ++ )
F_65 ( & V_173 , V_78 ) ;
V_177:
for ( V_78 = 0 ; V_78 < 4 ; V_78 ++ )
V_3 -> V_183 [ V_78 ] = V_173 [ V_78 ] ;
F_45 ( V_53 ) ;
F_43 ( V_53 , V_184 ) ;
}
void F_66 ( struct V_25 * V_26 , bool V_185 ,
bool V_186 )
{
struct V_52 * V_53 = V_26 -> V_27 ;
struct V_28 * V_29 = & V_26 -> V_27 -> V_30 . V_3 ;
bool V_187 = V_29 -> V_186 ;
if ( ! ( V_29 -> V_32 & V_188 ) ) {
V_29 -> V_186 = false ;
return;
}
if ( ! F_21 ( V_53 -> V_45 ) )
return;
if ( V_185 ) {
struct V_189 * V_190 = & V_26 -> V_190 ;
if ( ( V_190 -> V_179 == V_180 ) &&
( V_53 -> V_45 -> V_178 > V_190 -> V_178 ) &&
( V_53 -> V_45 -> V_178 <= V_190 -> V_178 + 20 ) )
return;
if ( ( V_190 -> V_179 == V_181 ) &&
( V_53 -> V_45 -> V_178 < V_190 -> V_178 ) &&
( V_53 -> V_45 -> V_178 >= V_190 -> V_178 - 20 ) )
return;
V_29 -> V_186 = false ;
} else
V_29 -> V_186 = V_186 ;
if ( V_187 != V_29 -> V_186 )
F_67 ( V_53 , V_26 -> V_32 . V_191 , false ) ;
}
static void F_68 ( struct V_25 * V_26 )
{
struct V_52 * V_53 = V_26 -> V_27 ;
struct V_20 * V_21 = & V_26 -> V_21 ;
struct V_2 * V_3 = & V_21 -> V_3 ;
if ( ! V_3 -> V_10 && ! V_3 -> V_74 )
return;
if ( V_53 -> V_192 . V_193 > 25 ) {
V_21 -> V_194 = 0 ;
return;
}
V_21 -> V_194 ++ ;
}
void F_69 ( struct V_25 * V_26 )
{
struct V_52 * V_53 = V_26 -> V_27 ;
struct V_20 * V_21 = & V_26 -> V_21 ;
struct V_28 * V_29 = & V_26 -> V_27 -> V_30 . V_3 ;
F_68 ( V_26 ) ;
if ( ! ( V_29 -> V_32 & V_188 ) )
return;
if ( V_53 -> V_192 . V_193 >= 40 ) {
if ( V_21 -> V_195 < 0 )
V_21 -> V_195 = 0 ;
if ( ++ V_21 -> V_195 >= V_196 ) {
V_21 -> V_195 = 0 ;
F_66 ( V_26 , false , true ) ;
}
} else {
if ( V_21 -> V_195 > 0 )
V_21 -> V_195 = 0 ;
if ( -- V_21 -> V_195 <= - V_196 ) {
V_21 -> V_195 = 0 ;
F_66 ( V_26 , false , false ) ;
}
}
}
