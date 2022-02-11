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
( L_1 ) ) ;
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
break;
case V_31 :
return 0x12 ;
break;
case V_32 :
return 0x22 ;
break;
default:
F_8 ( V_4 , V_16 , V_33 ,
( L_2 ,
V_27 -> V_29 ) ) ;
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
( L_3 ) ) ;
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
F_8 ( V_4 , V_16 , V_17 , ( L_4 ,
V_76 ) ) ;
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
( L_5
L_6 , V_9 ) ) ;
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
( L_7
L_6 , V_9 ) ) ;
goto V_88;
}
V_84 = F_4 ( V_2 ) ;
if ( V_84 != true ) {
F_8 ( V_4 , V_69 , V_33 ,
( L_8 ) ) ;
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
( L_9
L_10 , V_9 ) ) ;
goto V_88;
}
F_8 ( V_4 , V_16 , V_17 ,
( L_11
L_12 , V_9 ) ) ;
V_83 = 2000 ;
do {
V_9 = F_5 ( V_4 , V_14 ) ;
if ( V_9 & V_92 )
break;
F_9 ( 40 ) ;
} while ( V_83 -- );
F_8 ( V_4 , V_16 , V_17 ,
( L_13
L_14 , V_9 ) ) ;
if ( ( ( V_9 & V_93 ) != V_93 ) ||
( V_83 <= 0 ) ) {
F_8 ( V_4 , V_69 , V_33 ,
( L_15
L_16 , V_9 ) ) ;
goto V_88;
}
V_82 = F_25 ( V_4 , V_14 ) ;
F_2 ( V_4 , V_14 , ( V_82 & ( ~ V_94 ) ) ) ;
V_82 = F_25 ( V_4 , V_95 ) ;
F_2 ( V_4 , V_95 , ( V_82 | V_96 |
V_97 | V_98 ) ) ;
F_8 ( V_4 , V_16 , V_17 ,
( L_17 , V_82 ) ) ;
F_3 ( V_4 , V_99 , V_100 ) ;
break;
default:
F_8 ( V_4 , V_16 , V_33 ,
( L_18 ) ) ;
V_84 = false ;
break;
}
V_88:
F_8 ( V_4 , V_16 , V_17 , ( L_19
L_20 , V_76 , V_84 ) ) ;
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
if ( ! V_78 -> V_81 )
return 1 ;
V_80 = (struct V_79 * ) V_78 -> V_81 ;
V_80 -> V_85 = V_21 ;
V_103 = V_80 -> V_107 ;
V_80 -> V_102 = (struct V_101 * ) V_103 ;
V_102 = V_80 -> V_102 ;
V_80 -> V_108 = F_27 ( V_102 -> V_109 , 0 ) ;
V_80 -> V_102 -> V_110 . V_111 = 1 ;
F_8 ( V_4 , V_16 , V_17 , ( L_21
L_22
L_23 , V_102 -> V_112 ,
V_102 -> V_109 , V_102 -> V_113 ,
V_102 -> V_114 , V_102 -> V_115 ) ) ;
if ( ( V_102 -> V_114 == 0 ) || ( V_102 -> V_114 >
sizeof( V_80 -> V_116 ) ) ) {
F_8 ( V_4 , V_69 , V_33 ,
( L_24 ) ) ;
goto V_117;
} else {
V_103 += V_105 ;
memcpy ( V_80 -> V_116 , V_103 ,
V_102 -> V_114 ) ;
V_80 -> V_118 = V_102 -> V_114 ;
}
if ( V_102 -> V_115 > sizeof( V_80 -> V_119 ) ) {
F_8 ( V_4 , V_69 , V_33 ,
( L_25 ) ) ;
goto V_117;
} else {
V_103 += V_80 -> V_118 ;
memcpy ( V_80 -> V_119 , V_103 ,
V_102 -> V_115 ) ;
V_80 -> V_120 = V_102 -> V_115 ;
}
V_85 = F_10 ( V_80 -> V_85 ) ;
while ( V_85 != V_25 ) {
switch ( V_85 ) {
case V_22 :
V_103 = V_80 -> V_116 ;
V_104 = V_80 -> V_118 ;
break;
case V_23 :
V_103 = V_80 -> V_119 ;
V_104 = V_80 -> V_120 ;
break;
case V_24 :
V_102 = V_80 -> V_102 ;
V_35 = & V_102 -> V_110 ;
F_12 ( V_2 , V_35 ) ;
V_103 = ( T_3 * ) ( V_80 -> V_102 ) +
V_121 ;
V_104 = V_105 -
V_121 ;
break;
default:
F_8 ( V_4 , V_69 , V_33 ,
( L_26 ) ) ;
goto V_117;
break;
}
V_84 = F_20 ( V_2 , V_103 ,
V_104 ) ;
if ( V_84 != true ) {
F_8 ( V_4 , V_69 , V_33 , ( L_27 ) ) ;
goto V_117;
}
V_84 = F_24 ( V_2 , V_85 ) ;
if ( V_84 != true ) {
F_8 ( V_4 , V_69 , V_33 , ( L_27 ) ) ;
goto V_117;
}
V_85 = F_10 ( V_80 -> V_85 ) ;
}
return V_84 ;
V_117:
return 0 ;
}
static T_1 F_28 ( struct V_37 * V_38 , T_1 V_122 ,
T_1 V_123 , T_1 * V_124 , T_1 * V_125 ,
T_3 * * V_126 , T_3 * V_127 )
{
T_1 V_128 = 0 , V_129 = 0 , V_130 = 0 ;
T_1 V_131 = 0 ;
T_3 * V_132 ;
T_3 V_133 = 0 ;
do {
V_129 = V_134 + F_29 ( V_125 [ V_133 ] , 8 ) ;
if ( V_122 < V_128 + V_129 + V_130 )
break;
V_132 = ( T_3 * ) F_23 ( V_38 , ( T_1 ) V_129 ) ;
memset ( ( V_132 + V_128 + V_130 ) , 0 , V_129 ) ;
F_30 ( ( V_132 + V_128 + V_130 ) ,
0 , 16 , V_125 [ V_133 ] ) ;
F_30 ( ( V_132 + V_128 + V_130 ) ,
16 , 8 , V_124 [ V_133 ] ) ;
* V_127 = * V_127 % 0x80 ;
F_30 ( ( V_132 + V_128 + V_130 ) ,
24 , 7 , * V_127 ) ;
++ * V_127 ;
memcpy ( ( V_132 + V_128 + V_130 +
V_134 ) , V_126 [ V_133 ] , V_125 [ V_133 ] ) ;
if ( V_133 < V_123 - 1 )
F_30 ( ( V_132 + V_131 ) ,
31 , 1 , 1 ) ;
V_131 = V_128 ;
V_128 += V_129 ;
} while ( ++ V_133 < V_123 );
return V_128 ;
}
static T_1 F_31 ( T_1 V_122 , T_1 V_123 , T_1 * V_125 )
{
T_1 V_128 = 0 , V_129 = 0 , V_130 = 0 ;
T_3 V_133 = 0 ;
do {
V_129 = V_134 + F_29 ( V_125 [ V_133 ] , 8 ) ;
if ( V_122 < V_128 + V_129 + V_130 )
break;
V_128 += V_129 ;
} while ( ++ V_133 < V_123 );
return V_128 + V_130 ;
}
static bool F_32 ( struct V_1 * V_2 , T_3 V_135 ,
T_3 * V_136 )
{
struct V_3 * V_4 = V_3 ( V_2 ) ;
struct V_77 * V_78 = V_77 ( V_3 ( V_2 ) ) ;
struct V_60 * V_137 ;
struct V_37 * V_38 ;
T_1 V_138 = 0 ;
T_1 V_139 = 0 ;
T_1 V_129 ;
switch ( V_135 ) {
case V_140 :
V_138 = V_141 ;
V_139 = sizeof( struct V_142 ) ;
break;
case V_143 :
V_138 = V_144 ;
V_139 = sizeof( struct V_145 ) ;
break;
case V_146 :
V_138 = V_147 ;
V_139 = sizeof( struct V_148 ) ;
break;
case V_149 :
V_138 = V_150 ;
V_139 = sizeof( unsigned long long ) ;
break;
case V_151 :
V_138 = V_152 ;
V_139 = sizeof( T_3 ) ;
break;
default:
break;
}
V_129 = F_31 ( V_153 , 1 , & V_139 ) ;
V_38 = F_21 ( V_129 ) ;
if ( ! V_38 )
return false ;
V_137 = (struct V_60 * ) ( V_38 -> V_70 ) ;
V_137 -> V_71 = V_49 ;
V_137 -> V_72 = V_154 ;
V_137 -> V_68 = false ;
F_28 ( V_38 , V_153 , 1 , & V_138 ,
& V_139 , & V_136 , & V_78 -> V_155 ) ;
F_13 ( V_2 , V_38 , false ) ;
V_4 -> V_55 -> V_56 -> V_156 ( V_2 , V_49 ) ;
return true ;
}
void F_33 ( struct V_1 * V_2 , T_3 V_157 )
{
struct V_158 * V_159 = V_158 ( V_3 ( V_2 ) ) ;
struct V_160 * V_161 = F_34 ( V_3 ( V_2 ) ) ;
struct V_142 V_162 ;
T_2 V_163 = 0 ;
V_162 . V_164 = V_157 ;
V_162 . V_165 = 0 ;
V_162 . V_166 = 0 ;
V_162 . V_167 = 0 ;
V_162 . V_168 = 0 ;
V_162 . V_169 = 0 ;
V_162 . V_170 = 0 ;
F_35 ( ( T_3 * ) ( & V_162 ) + 8 , 0 , 16 ,
V_159 -> V_171 -> V_172 . V_173 ) ;
V_162 . V_174 = 0 ;
V_162 . V_175 = V_161 -> V_176 ;
V_162 . V_177 = 1 ;
V_162 . V_178 = 10 ;
if ( V_162 . V_164 == V_179 )
V_163 = V_159 -> V_171 -> V_172 . V_173 ;
else if ( V_162 . V_164 == V_180 )
V_163 = V_159 -> V_171 -> V_172 . V_173 *
V_159 -> V_171 -> V_172 . V_181 ;
if ( V_163 >= 500 )
V_162 . V_182 = 1 ;
else if ( ( V_163 >= 300 ) && ( V_163 < 500 ) )
V_162 . V_182 = 2 ;
else if ( ( V_163 >= 200 ) && ( V_163 < 300 ) )
V_162 . V_182 = 3 ;
else if ( ( V_163 >= 20 ) && ( V_163 < 200 ) )
V_162 . V_182 = 5 ;
else
V_162 . V_182 = 1 ;
F_32 ( V_2 , V_140 , ( T_3 * ) & V_162 ) ;
}
void F_36 ( struct V_1 * V_2 ,
T_3 V_183 , T_3 V_184 )
{
struct V_158 * V_159 = V_158 ( V_3 ( V_2 ) ) ;
struct V_145 V_185 ;
V_185 . V_186 = V_183 ;
V_185 . V_187 = V_184 ;
V_185 . V_188 [ 0 ] = V_159 -> V_188 [ 0 ] ;
V_185 . V_188 [ 1 ] = V_159 -> V_188 [ 1 ] ;
V_185 . V_188 [ 2 ] = V_159 -> V_188 [ 2 ] ;
V_185 . V_188 [ 3 ] = V_159 -> V_188 [ 3 ] ;
V_185 . V_188 [ 4 ] = V_159 -> V_188 [ 4 ] ;
V_185 . V_188 [ 5 ] = V_159 -> V_188 [ 5 ] ;
F_35 ( ( T_3 * ) ( & V_185 ) + 8 , 0 , 16 ,
V_159 -> V_171 -> V_172 . V_173 ) ;
F_35 ( ( T_3 * ) ( & V_185 ) + 10 , 0 , 16 , V_159 -> V_189 ) ;
F_32 ( V_2 , V_143 , ( T_3 * ) & V_185 ) ;
}
