static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_3 ( V_2 ) ;
F_2 ( V_4 , V_5 , 0xffffffff ) ;
F_2 ( V_4 , V_5 + 4 , 0xffffffff ) ;
F_3 ( V_4 , V_5 + 8 , 0xff ) ;
F_3 ( V_4 , V_5 + 0xB , 0x80 ) ;
}
static bool F_4 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_3 ( V_2 ) ;
T_1 V_6 = 200 ;
T_2 V_7 ;
T_3 V_8 , V_9 = 0 ;
F_1 ( V_2 ) ;
V_8 = F_5 ( V_4 , V_10 ) ;
F_3 ( V_4 , V_10 , ( V_8 | V_11 ) ) ;
V_7 = F_6 ( V_4 , V_12 ) ;
F_7 ( V_4 , V_12 , ( V_7 | V_13 ) ) ;
do {
V_9 = F_5 ( V_4 , V_14 ) ;
if ( V_9 & V_15 ) {
F_8 ( V_4 , V_16 , V_17 ,
L_1 ) ;
break;
}
F_9 ( 100 ) ;
} while ( V_6 -- );
if ( ! ( V_9 & V_15 ) )
return false ;
return true ;
}
static enum V_18 F_10 (
enum V_18 V_19 )
{
enum V_18 V_20 = 0 ;
switch ( V_19 ) {
case V_21 :
V_20 = V_22 ;
break;
case V_22 :
V_20 = V_23 ;
break;
case V_23 :
V_20 = V_24 ;
break;
case V_24 :
V_20 = V_25 ;
break;
default:
break;
}
return V_20 ;
}
static T_3 F_11 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_3 ( V_2 ) ;
struct V_26 * V_27 = & ( V_4 -> V_28 ) ;
switch ( V_27 -> V_29 ) {
case V_30 :
return 0x11 ;
case V_31 :
return 0x12 ;
case V_32 :
return 0x22 ;
default:
F_8 ( V_4 , V_16 , V_33 , L_2 ,
V_27 -> V_29 ) ;
break;
}
return 0x22 ;
}
static void F_12 ( struct V_1 * V_2 ,
struct V_34 * V_35 )
{
V_35 -> V_36 = F_11 ( V_2 ) ;
}
static bool F_13 ( struct V_1 * V_2 ,
struct V_37 * V_38 , T_3 V_39 )
{
struct V_3 * V_4 = V_3 ( V_2 ) ;
struct V_40 * V_41 = F_14 ( F_15 ( V_2 ) ) ;
struct V_42 * V_43 ;
struct V_44 * V_45 ;
unsigned long V_46 ;
T_3 V_47 = 0 ;
V_43 = & V_41 -> V_48 [ V_49 ] ;
F_16 ( & V_4 -> V_50 . V_51 , V_46 ) ;
V_47 = ( V_43 -> V_47 + F_17 ( & V_43 -> V_52 ) ) % V_43 -> V_53 ;
V_45 = & V_43 -> V_54 [ V_47 ] ;
V_4 -> V_55 -> V_56 -> V_57 ( V_2 , ( T_3 * ) V_45 , 1 , 1 , V_38 ) ;
F_18 ( & V_43 -> V_52 , V_38 ) ;
F_19 ( & V_4 -> V_50 . V_51 , V_46 ) ;
return true ;
}
static bool F_20 ( struct V_1 * V_2 ,
T_3 * V_58 , T_1 V_59 )
{
struct V_3 * V_4 = V_3 ( V_2 ) ;
struct V_37 * V_38 ;
struct V_60 * V_61 ;
unsigned char * V_62 ;
T_2 V_63 = V_64 ;
T_2 V_65 , V_66 = 0 ;
T_2 V_67 = 0 ;
T_3 V_68 = 0 ;
F_1 ( V_2 ) ;
if ( V_59 >= V_64 ) {
F_8 ( V_4 , V_69 , V_33 ,
L_3 ) ;
return false ;
}
V_67 = 0 ;
do {
if ( ( V_59 - V_66 ) > V_63 ) {
V_65 = V_63 + V_67 ;
} else {
V_65 = ( T_2 ) ( V_59 - V_66 +
V_67 ) ;
V_68 = 1 ;
}
V_38 = F_21 ( V_65 ) ;
if ( ! V_38 )
return false ;
F_22 ( V_38 , V_67 ) ;
V_62 = ( T_3 * ) F_23 ( V_38 , ( T_1 ) ( V_65 -
V_67 ) ) ;
memcpy ( V_62 , V_58 + V_66 ,
( T_1 ) ( V_65 - V_67 ) ) ;
V_61 = (struct V_60 * ) ( V_38 -> V_70 ) ;
V_61 -> V_71 = V_49 ;
V_61 -> V_72 = V_73 ;
V_61 -> V_68 = V_68 ;
F_13 ( V_2 , V_38 , V_68 ) ;
V_66 += ( V_65 - V_67 ) ;
} while ( V_66 < V_59 );
F_3 ( V_4 , V_74 , V_75 ) ;
return true ;
}
static bool F_24 ( struct V_1 * V_2 ,
T_3 V_76 )
{
struct V_3 * V_4 = V_3 ( V_2 ) ;
struct V_77 * V_78 = V_77 ( V_3 ( V_2 ) ) ;
struct V_79 * V_80 = (struct V_79 * ) V_78 -> V_81 ;
T_1 V_82 ;
T_3 V_9 = 0 ;
short V_83 = 1000 ;
bool V_84 = true ;
F_8 ( V_4 , V_16 , V_17 ,
L_4 , V_76 ) ;
V_80 -> V_85 = (enum V_18 ) V_76 ;
switch ( V_76 ) {
case V_22 :
do {
V_9 = F_5 ( V_4 , V_14 ) ;
if ( V_9 & V_86 )
break;
F_9 ( 5 ) ;
} while ( V_83 -- );
if ( ! ( V_9 & V_87 ) || ( V_83 <= 0 ) ) {
F_8 ( V_4 , V_69 , V_33 ,
L_5 ,
V_9 ) ;
goto V_88;
}
break;
case V_23 :
do {
V_9 = F_5 ( V_4 , V_14 ) ;
if ( V_9 & V_89 )
break;
F_9 ( 5 ) ;
} while ( V_83 -- );
if ( ! ( V_9 & V_90 ) || ( V_83 <= 0 ) ) {
F_8 ( V_4 , V_69 , V_33 ,
L_6 ,
V_9 ) ;
goto V_88;
}
V_84 = F_4 ( V_2 ) ;
if ( ! V_84 ) {
F_8 ( V_4 , V_69 , V_33 ,
L_7 ) ;
goto V_88;
}
break;
case V_24 :
do {
V_9 = F_5 ( V_4 , V_14 ) ;
if ( V_9 & V_91 )
break;
F_9 ( 5 ) ;
} while ( V_83 -- );
if ( ! ( V_9 & V_91 ) || ( V_83 <= 0 ) ) {
F_8 ( V_4 , V_69 , V_33 ,
L_8 ,
V_9 ) ;
goto V_88;
}
F_8 ( V_4 , V_16 , V_17 ,
L_9 ,
V_9 ) ;
V_83 = 2000 ;
do {
V_9 = F_5 ( V_4 , V_14 ) ;
if ( V_9 & V_92 )
break;
F_9 ( 40 ) ;
} while ( V_83 -- );
F_8 ( V_4 , V_16 , V_17 ,
L_10 ,
V_9 ) ;
if ( ( ( V_9 & V_93 ) != V_93 ) ||
( V_83 <= 0 ) ) {
F_8 ( V_4 , V_69 , V_33 ,
L_11 ,
V_9 ) ;
goto V_88;
}
V_82 = F_25 ( V_4 , V_14 ) ;
F_2 ( V_4 , V_14 , ( V_82 & ( ~ V_94 ) ) ) ;
V_82 = F_25 ( V_4 , V_95 ) ;
F_2 ( V_4 , V_95 , ( V_82 | V_96 |
V_97 | V_98 ) ) ;
F_8 ( V_4 , V_16 , V_17 ,
L_12 , V_82 ) ;
F_3 ( V_4 , V_99 , V_100 ) ;
break;
default:
F_8 ( V_4 , V_16 , V_33 ,
L_13 ) ;
V_84 = false ;
break;
}
V_88:
F_8 ( V_4 , V_16 , V_17 ,
L_14 ,
V_76 , V_84 ) ;
return V_84 ;
}
int F_26 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_3 ( V_2 ) ;
struct V_77 * V_78 = V_77 ( V_3 ( V_2 ) ) ;
struct V_79 * V_80 = NULL ;
struct V_101 * V_102 ;
struct V_34 * V_35 = NULL ;
T_3 * V_103 = NULL ;
T_1 V_104 = 0 ;
T_3 V_105 = V_106 ;
T_3 V_85 = V_21 ;
bool V_84 = true ;
if ( V_4 -> V_107 == 0 || ! V_78 -> V_81 )
return 1 ;
V_80 = (struct V_79 * ) V_78 -> V_81 ;
V_80 -> V_85 = V_21 ;
V_103 = V_80 -> V_108 ;
V_80 -> V_102 = (struct V_101 * ) V_103 ;
V_102 = V_80 -> V_102 ;
V_80 -> V_109 = F_27 ( V_102 -> V_110 , 0 ) ;
V_80 -> V_102 -> V_111 . V_112 = 1 ;
F_8 ( V_4 , V_16 , V_17 ,
L_15 ,
V_102 -> V_113 ,
V_102 -> V_110 , V_102 -> V_114 ,
V_102 -> V_115 , V_102 -> V_116 ) ;
if ( ( V_102 -> V_115 == 0 ) || ( V_102 -> V_115 >
sizeof( V_80 -> V_117 ) ) ) {
F_8 ( V_4 , V_69 , V_33 ,
L_16 ) ;
goto V_118;
} else {
V_103 += V_105 ;
memcpy ( V_80 -> V_117 , V_103 ,
V_102 -> V_115 ) ;
V_80 -> V_119 = V_102 -> V_115 ;
}
if ( V_102 -> V_116 > sizeof( V_80 -> V_120 ) ) {
F_8 ( V_4 , V_69 , V_33 ,
L_17 ) ;
goto V_118;
} else {
V_103 += V_80 -> V_119 ;
memcpy ( V_80 -> V_120 , V_103 ,
V_102 -> V_116 ) ;
V_80 -> V_121 = V_102 -> V_116 ;
}
V_85 = F_10 ( V_80 -> V_85 ) ;
while ( V_85 != V_25 ) {
switch ( V_85 ) {
case V_22 :
V_103 = V_80 -> V_117 ;
V_104 = V_80 -> V_119 ;
break;
case V_23 :
V_103 = V_80 -> V_120 ;
V_104 = V_80 -> V_121 ;
break;
case V_24 :
V_102 = V_80 -> V_102 ;
V_35 = & V_102 -> V_111 ;
F_12 ( V_2 , V_35 ) ;
V_103 = ( T_3 * ) ( V_80 -> V_102 ) +
V_122 ;
V_104 = V_105 -
V_122 ;
break;
default:
F_8 ( V_4 , V_69 , V_33 ,
L_18 ) ;
goto V_118;
}
V_84 = F_20 ( V_2 , V_103 ,
V_104 ) ;
if ( ! V_84 ) {
F_8 ( V_4 , V_69 , V_33 , L_19 ) ;
goto V_118;
}
V_84 = F_24 ( V_2 , V_85 ) ;
if ( ! V_84 ) {
F_8 ( V_4 , V_69 , V_33 , L_19 ) ;
goto V_118;
}
V_85 = F_10 ( V_80 -> V_85 ) ;
}
return V_84 ;
V_118:
return 0 ;
}
static T_1 F_28 ( struct V_37 * V_38 , T_1 V_123 ,
T_1 V_124 , T_1 * V_125 , T_1 * V_126 ,
T_3 * * V_127 , T_3 * V_128 )
{
T_1 V_129 = 0 , V_130 = 0 , V_131 = 0 ;
T_1 V_132 = 0 ;
T_3 * V_133 ;
T_3 V_134 = 0 ;
do {
V_130 = V_135 + F_29 ( V_126 [ V_134 ] , 8 ) ;
if ( V_123 < V_129 + V_130 + V_131 )
break;
V_133 = ( T_3 * ) F_23 ( V_38 , ( T_1 ) V_130 ) ;
memset ( ( V_133 + V_129 + V_131 ) , 0 , V_130 ) ;
F_30 ( ( V_133 + V_129 + V_131 ) ,
0 , 16 , V_126 [ V_134 ] ) ;
F_30 ( ( V_133 + V_129 + V_131 ) ,
16 , 8 , V_125 [ V_134 ] ) ;
* V_128 = * V_128 % 0x80 ;
F_30 ( ( V_133 + V_129 + V_131 ) ,
24 , 7 , * V_128 ) ;
++ * V_128 ;
memcpy ( ( V_133 + V_129 + V_131 +
V_135 ) , V_127 [ V_134 ] , V_126 [ V_134 ] ) ;
if ( V_134 < V_124 - 1 )
F_30 ( ( V_133 + V_132 ) ,
31 , 1 , 1 ) ;
V_132 = V_129 ;
V_129 += V_130 ;
} while ( ++ V_134 < V_124 );
return V_129 ;
}
static T_1 F_31 ( T_1 V_123 , T_1 V_124 , T_1 * V_126 )
{
T_1 V_129 = 0 , V_130 = 0 , V_131 = 0 ;
T_3 V_134 = 0 ;
do {
V_130 = V_135 + F_29 ( V_126 [ V_134 ] , 8 ) ;
if ( V_123 < V_129 + V_130 + V_131 )
break;
V_129 += V_130 ;
} while ( ++ V_134 < V_124 );
return V_129 + V_131 ;
}
static bool F_32 ( struct V_1 * V_2 , T_3 V_136 ,
T_3 * V_137 )
{
struct V_3 * V_4 = V_3 ( V_2 ) ;
struct V_77 * V_78 = V_77 ( V_3 ( V_2 ) ) ;
struct V_60 * V_138 ;
struct V_37 * V_38 ;
T_1 V_139 = 0 ;
T_1 V_140 = 0 ;
T_1 V_130 ;
switch ( V_136 ) {
case V_141 :
V_139 = V_142 ;
V_140 = sizeof( struct V_143 ) ;
break;
case V_144 :
V_139 = V_145 ;
V_140 = sizeof( struct V_146 ) ;
break;
case V_147 :
V_139 = V_148 ;
V_140 = sizeof( struct V_149 ) ;
break;
case V_150 :
V_139 = V_151 ;
V_140 = sizeof( unsigned long long ) ;
break;
case V_152 :
V_139 = V_153 ;
V_140 = sizeof( T_3 ) ;
break;
default:
break;
}
V_130 = F_31 ( V_154 , 1 , & V_140 ) ;
V_38 = F_21 ( V_130 ) ;
if ( ! V_38 )
return false ;
V_138 = (struct V_60 * ) ( V_38 -> V_70 ) ;
V_138 -> V_71 = V_49 ;
V_138 -> V_72 = V_155 ;
V_138 -> V_68 = false ;
F_28 ( V_38 , V_154 , 1 , & V_139 ,
& V_140 , & V_137 , & V_78 -> V_156 ) ;
F_13 ( V_2 , V_38 , false ) ;
V_4 -> V_55 -> V_56 -> V_157 ( V_2 , V_49 ) ;
return true ;
}
void F_33 ( struct V_1 * V_2 , T_3 V_158 )
{
struct V_159 * V_160 = V_159 ( V_3 ( V_2 ) ) ;
struct V_161 * V_162 = F_34 ( V_3 ( V_2 ) ) ;
struct V_143 V_163 ;
T_2 V_164 = 0 ;
V_163 . V_165 = V_158 ;
V_163 . V_166 = 0 ;
V_163 . V_167 = 0 ;
V_163 . V_168 = 0 ;
V_163 . V_169 = 0 ;
V_163 . V_170 = 0 ;
V_163 . V_171 = 0 ;
F_35 ( ( T_3 * ) ( & V_163 ) + 8 , 0 , 16 ,
V_160 -> V_172 -> V_173 . V_174 ) ;
V_163 . V_175 = 0 ;
V_163 . V_176 = V_162 -> V_177 ;
V_163 . V_178 = 1 ;
V_163 . V_179 = 10 ;
if ( V_163 . V_165 == V_180 )
V_164 = V_160 -> V_172 -> V_173 . V_174 ;
else if ( V_163 . V_165 == V_181 )
V_164 = V_160 -> V_172 -> V_173 . V_174 *
V_160 -> V_172 -> V_173 . V_182 ;
if ( V_164 >= 500 )
V_163 . V_183 = 1 ;
else if ( ( V_164 >= 300 ) && ( V_164 < 500 ) )
V_163 . V_183 = 2 ;
else if ( ( V_164 >= 200 ) && ( V_164 < 300 ) )
V_163 . V_183 = 3 ;
else if ( ( V_164 >= 20 ) && ( V_164 < 200 ) )
V_163 . V_183 = 5 ;
else
V_163 . V_183 = 1 ;
F_32 ( V_2 , V_141 , ( T_3 * ) & V_163 ) ;
}
void F_36 ( struct V_1 * V_2 ,
T_3 V_184 , T_3 V_185 )
{
struct V_159 * V_160 = V_159 ( V_3 ( V_2 ) ) ;
struct V_146 V_186 ;
V_186 . V_187 = V_184 ;
V_186 . V_188 = V_185 ;
V_186 . V_189 [ 0 ] = V_160 -> V_189 [ 0 ] ;
V_186 . V_189 [ 1 ] = V_160 -> V_189 [ 1 ] ;
V_186 . V_189 [ 2 ] = V_160 -> V_189 [ 2 ] ;
V_186 . V_189 [ 3 ] = V_160 -> V_189 [ 3 ] ;
V_186 . V_189 [ 4 ] = V_160 -> V_189 [ 4 ] ;
V_186 . V_189 [ 5 ] = V_160 -> V_189 [ 5 ] ;
F_35 ( ( T_3 * ) ( & V_186 ) + 8 , 0 , 16 ,
V_160 -> V_172 -> V_173 . V_174 ) ;
F_35 ( ( T_3 * ) ( & V_186 ) + 10 , 0 , 16 , V_160 -> V_190 ) ;
F_32 ( V_2 , V_144 , ( T_3 * ) & V_186 ) ;
}
