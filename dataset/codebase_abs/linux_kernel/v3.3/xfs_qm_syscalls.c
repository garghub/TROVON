int
F_1 (
T_1 * V_1 ,
T_2 V_2 )
{
struct V_3 * V_4 = V_1 -> V_5 ;
T_2 V_6 ;
int error ;
T_2 V_7 ;
T_3 * V_8 ;
int V_9 ;
if ( ( V_1 -> V_10 & V_2 ) == 0 )
return F_2 ( V_11 ) ;
error = 0 ;
V_2 &= ( V_12 | V_13 ) ;
ASSERT ( V_4 ) ;
F_3 ( & V_4 -> V_14 ) ;
if ( ( V_2 & V_12 ) == 0 ) {
V_1 -> V_10 &= ~ ( V_2 ) ;
F_4 ( & V_1 -> V_15 ) ;
V_1 -> V_16 . V_17 = V_1 -> V_10 ;
F_5 ( & V_1 -> V_15 ) ;
F_6 ( & V_4 -> V_14 ) ;
error = F_7 ( V_1 , V_18 ) ;
return ( error ) ;
}
V_6 = 0 ;
V_7 = 0 ;
if ( V_2 & V_19 ) {
V_6 |= V_20 ;
V_2 |= ( V_21 | V_22 ) ;
V_7 |= V_23 ;
}
if ( V_2 & V_24 ) {
V_6 |= V_25 ;
V_2 |= ( V_26 | V_27 ) ;
V_7 |= V_28 ;
} else if ( V_2 & V_29 ) {
V_6 |= V_30 ;
V_2 |= ( V_26 | V_27 ) ;
V_7 |= V_31 ;
}
if ( ( V_1 -> V_10 & V_2 ) == 0 )
goto V_32;
error = F_8 ( V_1 , & V_8 , V_2 ) ;
if ( error )
goto V_32;
V_1 -> V_10 &= ~ V_7 ;
F_9 ( V_1 , V_2 ) ;
V_1 -> V_10 &= ~ ( V_2 ) ;
while ( ( V_9 = F_10 ( V_1 , V_6 ) ) )
F_11 ( 10 * V_9 ) ;
error = F_12 ( V_1 , V_8 , V_2 ) ;
if ( error ) {
F_13 ( V_1 , V_33 ) ;
goto V_32;
}
if ( ( ( V_2 & V_34 ) == V_35 ) ||
( ( V_2 & V_34 ) == V_36 ) ) {
F_6 ( & V_4 -> V_14 ) ;
F_14 ( V_1 ) ;
return ( 0 ) ;
}
if ( ( V_6 & V_20 ) && V_4 -> V_37 ) {
F_15 ( V_4 -> V_37 ) ;
V_4 -> V_37 = NULL ;
}
if ( ( V_6 & ( V_25 | V_30 ) ) && V_4 -> V_38 ) {
F_15 ( V_4 -> V_38 ) ;
V_4 -> V_38 = NULL ;
}
V_32:
F_6 ( & V_4 -> V_14 ) ;
return error ;
}
STATIC int
F_16 (
struct V_39 * V_1 ,
T_4 V_40 )
{
struct V_41 * V_42 ;
struct V_43 * V_44 ;
int error ;
if ( V_40 == V_45 )
return 0 ;
error = F_17 ( V_1 , NULL , V_40 , 0 , 0 , & V_42 ) ;
if ( error )
return error ;
F_18 ( V_42 , V_46 ) ;
V_44 = F_19 ( V_1 , V_47 ) ;
error = F_20 ( V_44 , 0 , F_21 ( V_1 ) , 0 ,
V_48 ,
V_49 ) ;
if ( error ) {
F_22 ( V_44 , 0 ) ;
F_23 ( V_42 , V_46 ) ;
goto V_50;
}
F_18 ( V_42 , V_51 ) ;
F_24 ( V_44 , V_42 , 0 ) ;
V_42 -> V_52 . V_53 = 0 ;
F_25 ( V_44 , V_42 , V_54 ) ;
error = F_26 ( & V_44 , V_42 , V_55 , 0 ) ;
if ( error ) {
F_22 ( V_44 , V_56 |
V_57 ) ;
goto V_32;
}
ASSERT ( V_42 -> V_52 . V_58 == 0 ) ;
F_27 ( V_44 , V_42 , V_59 | V_60 ) ;
error = F_28 ( V_44 , V_56 ) ;
V_32:
F_23 ( V_42 , V_51 | V_46 ) ;
V_50:
F_15 ( V_42 ) ;
return error ;
}
int
F_29 (
T_1 * V_1 ,
T_2 V_2 )
{
int error = 0 , V_61 = 0 ;
if ( ! F_30 ( & V_1 -> V_16 ) || V_2 == 0 ) {
F_31 ( V_1 , L_1 ,
V_62 , V_2 , V_1 -> V_10 ) ;
return F_2 ( V_63 ) ;
}
if ( V_2 & V_64 )
error = F_16 ( V_1 , V_1 -> V_16 . V_65 ) ;
if ( V_2 & ( V_66 | V_67 ) )
V_61 = F_16 ( V_1 , V_1 -> V_16 . V_68 ) ;
return error ? error : V_61 ;
}
int
F_32 (
T_1 * V_1 ,
T_2 V_2 )
{
int error ;
T_2 V_69 ;
T_5 V_70 ;
V_2 &= ( V_12 | V_13 ) ;
V_2 &= ~ ( V_12 ) ;
V_70 = 0 ;
if ( V_2 == 0 ) {
F_31 ( V_1 , L_2 ,
V_62 , V_1 -> V_10 ) ;
return F_2 ( V_63 ) ;
}
ASSERT ( ( V_2 & V_12 ) == 0 ) ;
if ( ( ( V_2 & V_19 ) == 0 &&
( V_1 -> V_16 . V_17 & V_19 ) == 0 &&
( V_2 & V_22 ) )
||
( ( V_2 & V_29 ) == 0 &&
( V_1 -> V_16 . V_17 & V_29 ) == 0 &&
( V_2 & V_24 ) == 0 &&
( V_1 -> V_16 . V_17 & V_24 ) == 0 &&
( V_2 & V_27 ) ) ) {
F_31 ( V_1 ,
L_3 ,
V_62 , V_2 , V_1 -> V_16 . V_17 ) ;
return F_2 ( V_63 ) ;
}
if ( ( V_1 -> V_10 & V_2 ) == V_2 )
return F_2 ( V_11 ) ;
F_4 ( & V_1 -> V_15 ) ;
V_69 = V_1 -> V_16 . V_17 ;
V_1 -> V_16 . V_17 = V_69 | V_2 ;
F_5 ( & V_1 -> V_15 ) ;
if ( ( V_69 & V_2 ) == V_2 && V_70 == 0 )
return F_2 ( V_11 ) ;
V_70 |= V_18 ;
if ( ( error = F_7 ( V_1 , V_70 ) ) )
return ( error ) ;
if ( ( ( V_1 -> V_16 . V_17 & V_19 ) !=
( V_1 -> V_10 & V_19 ) ) ||
( ( V_1 -> V_16 . V_17 & V_29 ) !=
( V_1 -> V_10 & V_29 ) ) ||
( ( V_1 -> V_16 . V_17 & V_24 ) !=
( V_1 -> V_10 & V_24 ) ) ||
( V_2 & V_13 ) == 0 )
return ( 0 ) ;
if ( ! F_33 ( V_1 ) )
return F_2 ( V_71 ) ;
F_3 ( & V_1 -> V_5 -> V_14 ) ;
V_1 -> V_10 |= ( V_2 & V_13 ) ;
F_6 ( & V_1 -> V_5 -> V_14 ) ;
return ( 0 ) ;
}
int
F_34 (
struct V_39 * V_1 ,
struct V_72 * V_73 )
{
struct V_3 * V_4 = V_1 -> V_5 ;
struct V_41 * V_74 , * V_75 ;
T_6 V_76 , V_77 ;
V_74 = V_75 = NULL ;
V_76 = V_77 = V_78 ;
memset ( V_73 , 0 , sizeof( V_79 ) ) ;
V_73 -> V_80 = V_81 ;
if ( ! F_30 ( & V_1 -> V_16 ) ) {
V_73 -> V_82 . V_83 = V_45 ;
V_73 -> V_84 . V_83 = V_45 ;
return ( 0 ) ;
}
V_73 -> V_85 = ( V_86 ) F_35 ( V_1 -> V_10 &
( V_12 |
V_13 ) ) ;
V_73 -> V_87 = 0 ;
V_73 -> V_82 . V_83 = V_1 -> V_16 . V_65 ;
V_73 -> V_84 . V_83 = V_1 -> V_16 . V_68 ;
if ( V_4 ) {
V_74 = V_4 -> V_37 ;
V_75 = V_4 -> V_38 ;
}
if ( ! V_74 && V_1 -> V_16 . V_65 != V_45 ) {
if ( F_17 ( V_1 , NULL , V_1 -> V_16 . V_65 ,
0 , 0 , & V_74 ) == 0 )
V_76 = V_88 ;
}
if ( ! V_75 && V_1 -> V_16 . V_68 != V_45 ) {
if ( F_17 ( V_1 , NULL , V_1 -> V_16 . V_68 ,
0 , 0 , & V_75 ) == 0 )
V_77 = V_88 ;
}
if ( V_74 ) {
V_73 -> V_82 . V_89 = V_74 -> V_52 . V_90 ;
V_73 -> V_82 . V_91 = V_74 -> V_52 . V_58 ;
if ( V_76 )
F_15 ( V_74 ) ;
}
if ( V_75 ) {
V_73 -> V_84 . V_89 = V_75 -> V_52 . V_90 ;
V_73 -> V_84 . V_91 = V_75 -> V_52 . V_58 ;
if ( V_77 )
F_15 ( V_75 ) ;
}
if ( V_4 ) {
V_73 -> V_92 = V_4 -> V_93 ;
V_73 -> V_94 = V_4 -> V_95 ;
V_73 -> V_96 = V_4 -> V_97 ;
V_73 -> V_98 = V_4 -> V_99 ;
V_73 -> V_100 = V_4 -> V_101 ;
V_73 -> V_102 = V_4 -> V_103 ;
}
return 0 ;
}
int
F_36 (
T_1 * V_1 ,
T_7 V_104 ,
T_2 type ,
T_8 * V_105 )
{
struct V_3 * V_4 = V_1 -> V_5 ;
T_9 * V_106 ;
T_10 * V_107 ;
T_11 * V_44 ;
int error ;
T_12 V_108 , V_109 ;
if ( V_105 -> V_110 & ~ V_111 )
return V_63 ;
if ( ( V_105 -> V_110 & V_111 ) == 0 )
return 0 ;
V_44 = F_19 ( V_1 , V_112 ) ;
if ( ( error = F_20 ( V_44 , 0 , sizeof( T_9 ) + 128 ,
0 , 0 , V_113 ) ) ) {
F_22 ( V_44 , 0 ) ;
return ( error ) ;
}
F_3 ( & V_4 -> V_14 ) ;
if ( ( error = F_37 ( V_1 , NULL , V_104 , type , V_114 , & V_107 ) ) ) {
F_22 ( V_44 , V_57 ) ;
ASSERT ( error != V_115 ) ;
goto V_32;
}
F_38 ( V_44 , V_107 ) ;
V_106 = & V_107 -> V_116 ;
V_108 = ( V_105 -> V_110 & V_117 ) ?
( T_12 ) F_39 ( V_1 , V_105 -> V_118 ) :
F_40 ( V_106 -> V_118 ) ;
V_109 = ( V_105 -> V_110 & V_119 ) ?
( T_12 ) F_39 ( V_1 , V_105 -> V_120 ) :
F_40 ( V_106 -> V_120 ) ;
if ( V_108 == 0 || V_108 >= V_109 ) {
V_106 -> V_118 = F_41 ( V_108 ) ;
V_106 -> V_120 = F_41 ( V_109 ) ;
if ( V_104 == 0 ) {
V_4 -> V_121 = V_108 ;
V_4 -> V_122 = V_109 ;
}
} else {
F_31 ( V_1 , L_4 , V_108 , V_109 ) ;
}
V_108 = ( V_105 -> V_110 & V_123 ) ?
( T_12 ) F_39 ( V_1 , V_105 -> V_124 ) :
F_40 ( V_106 -> V_124 ) ;
V_109 = ( V_105 -> V_110 & V_125 ) ?
( T_12 ) F_39 ( V_1 , V_105 -> V_126 ) :
F_40 ( V_106 -> V_126 ) ;
if ( V_108 == 0 || V_108 >= V_109 ) {
V_106 -> V_124 = F_41 ( V_108 ) ;
V_106 -> V_126 = F_41 ( V_109 ) ;
if ( V_104 == 0 ) {
V_4 -> V_127 = V_108 ;
V_4 -> V_128 = V_109 ;
}
} else {
F_31 ( V_1 , L_5 , V_108 , V_109 ) ;
}
V_108 = ( V_105 -> V_110 & V_129 ) ?
( T_12 ) V_105 -> V_130 :
F_40 ( V_106 -> V_130 ) ;
V_109 = ( V_105 -> V_110 & V_131 ) ?
( T_12 ) V_105 -> V_132 :
F_40 ( V_106 -> V_132 ) ;
if ( V_108 == 0 || V_108 >= V_109 ) {
V_106 -> V_130 = F_41 ( V_108 ) ;
V_106 -> V_132 = F_41 ( V_109 ) ;
if ( V_104 == 0 ) {
V_4 -> V_133 = V_108 ;
V_4 -> V_134 = V_109 ;
}
} else {
F_31 ( V_1 , L_6 , V_108 , V_109 ) ;
}
if ( V_105 -> V_110 & V_135 )
V_106 -> V_136 = F_42 ( V_105 -> V_136 ) ;
if ( V_105 -> V_110 & V_137 )
V_106 -> V_138 = F_42 ( V_105 -> V_138 ) ;
if ( V_105 -> V_110 & V_139 )
V_106 -> V_140 = F_42 ( V_105 -> V_140 ) ;
if ( V_104 == 0 ) {
if ( V_105 -> V_110 & V_141 ) {
V_4 -> V_95 = V_105 -> V_142 ;
V_106 -> V_142 = F_43 ( V_105 -> V_142 ) ;
}
if ( V_105 -> V_110 & V_143 ) {
V_4 -> V_97 = V_105 -> V_144 ;
V_106 -> V_144 = F_43 ( V_105 -> V_144 ) ;
}
if ( V_105 -> V_110 & V_145 ) {
V_4 -> V_99 = V_105 -> V_146 ;
V_106 -> V_146 = F_43 ( V_105 -> V_146 ) ;
}
if ( V_105 -> V_110 & V_135 )
V_4 -> V_101 = V_105 -> V_136 ;
if ( V_105 -> V_110 & V_137 )
V_4 -> V_103 = V_105 -> V_138 ;
if ( V_105 -> V_110 & V_139 )
V_4 -> V_147 = V_105 -> V_140 ;
} else {
F_44 ( V_1 , V_106 ) ;
}
V_107 -> V_148 |= V_149 ;
F_45 ( V_44 , V_107 ) ;
error = F_28 ( V_44 , 0 ) ;
F_46 ( V_107 ) ;
V_32:
F_6 ( & V_4 -> V_14 ) ;
return error ;
}
int
F_47 (
T_1 * V_1 ,
T_7 V_104 ,
T_2 type ,
T_8 * V_73 )
{
T_10 * V_107 ;
int error ;
if ( ( error = F_37 ( V_1 , NULL , V_104 , type , 0 , & V_107 ) ) ) {
return ( error ) ;
}
if ( F_48 ( V_107 ) ) {
F_49 ( V_107 ) ;
return F_2 ( V_115 ) ;
}
F_50 ( V_1 , & V_107 -> V_116 , V_73 ) ;
F_49 ( V_107 ) ;
return ( error ? F_2 ( V_150 ) : 0 ) ;
}
STATIC int
F_12 (
T_1 * V_1 ,
T_3 * V_151 ,
T_2 V_2 )
{
T_11 * V_44 ;
int error ;
T_3 * V_152 ;
V_44 = F_19 ( V_1 , V_153 ) ;
if ( ( error = F_20 ( V_44 , 0 , sizeof( T_3 ) * 2 ,
0 , 0 , V_113 ) ) ) {
F_22 ( V_44 , 0 ) ;
return ( error ) ;
}
V_152 = F_51 ( V_44 , V_151 ,
V_2 & V_12 ) ;
F_52 ( V_44 , V_152 ) ;
F_53 ( V_44 ) ;
error = F_28 ( V_44 , 0 ) ;
return ( error ) ;
}
STATIC int
F_8 (
T_1 * V_1 ,
T_3 * * V_154 ,
T_2 V_2 )
{
T_11 * V_44 ;
int error ;
T_3 * V_152 = NULL ;
T_2 V_155 = 0 ;
V_44 = F_19 ( V_1 , V_156 ) ;
if ( ( error = F_20 ( V_44 , 0 ,
sizeof( T_3 ) * 2 +
V_1 -> V_16 . V_157 + 128 ,
0 ,
0 ,
V_113 ) ) ) {
goto V_158;
}
V_152 = F_51 ( V_44 , NULL , V_2 & V_12 ) ;
F_52 ( V_44 , V_152 ) ;
F_4 ( & V_1 -> V_15 ) ;
V_155 = V_1 -> V_16 . V_17 ;
V_1 -> V_16 . V_17 = ( V_1 -> V_10 & ~ ( V_2 ) ) & V_34 ;
F_5 ( & V_1 -> V_15 ) ;
F_54 ( V_44 , V_18 ) ;
F_53 ( V_44 ) ;
error = F_28 ( V_44 , 0 ) ;
V_158:
if ( error ) {
F_22 ( V_44 , 0 ) ;
F_4 ( & V_1 -> V_15 ) ;
V_1 -> V_16 . V_17 = V_155 ;
F_5 ( & V_1 -> V_15 ) ;
}
* V_154 = V_152 ;
return ( error ) ;
}
STATIC void
F_50 (
T_1 * V_1 ,
T_9 * V_159 ,
struct V_160 * V_161 )
{
memset ( V_161 , 0 , sizeof( * V_161 ) ) ;
V_161 -> V_162 = V_163 ;
V_161 -> V_164 = F_55 ( V_159 -> V_164 ) ;
V_161 -> V_165 = F_56 ( V_159 -> V_165 ) ;
V_161 -> V_118 =
F_57 ( V_1 , F_40 ( V_159 -> V_118 ) ) ;
V_161 -> V_120 =
F_57 ( V_1 , F_40 ( V_159 -> V_120 ) ) ;
V_161 -> V_130 = F_40 ( V_159 -> V_130 ) ;
V_161 -> V_132 = F_40 ( V_159 -> V_132 ) ;
V_161 -> V_166 = F_57 ( V_1 , F_40 ( V_159 -> V_166 ) ) ;
V_161 -> V_167 = F_40 ( V_159 -> V_167 ) ;
V_161 -> V_142 = F_56 ( V_159 -> V_142 ) ;
V_161 -> V_144 = F_56 ( V_159 -> V_144 ) ;
V_161 -> V_138 = F_58 ( V_159 -> V_138 ) ;
V_161 -> V_136 = F_58 ( V_159 -> V_136 ) ;
V_161 -> V_124 =
F_57 ( V_1 , F_40 ( V_159 -> V_124 ) ) ;
V_161 -> V_126 =
F_57 ( V_1 , F_40 ( V_159 -> V_126 ) ) ;
V_161 -> V_168 = F_57 ( V_1 , F_40 ( V_159 -> V_168 ) ) ;
V_161 -> V_146 = F_56 ( V_159 -> V_146 ) ;
V_161 -> V_140 = F_58 ( V_159 -> V_140 ) ;
if ( ( ! F_59 ( V_1 ) && V_159 -> V_164 == V_64 ) ||
( ! F_60 ( V_1 ) &&
( V_159 -> V_164 & ( V_67 | V_66 ) ) ) ) {
V_161 -> V_142 = 0 ;
V_161 -> V_144 = 0 ;
V_161 -> V_146 = 0 ;
}
#ifdef F_61
if ( ( ( F_59 ( V_1 ) && V_161 -> V_164 == V_169 ) ||
( F_60 ( V_1 ) &&
( V_161 -> V_164 & ( V_170 | V_171 ) ) ) ) &&
V_161 -> V_165 != 0 ) {
if ( ( ( int ) V_161 -> V_166 > ( int ) V_161 -> V_120 ) &&
( V_161 -> V_120 > 0 ) ) {
ASSERT ( V_161 -> V_142 != 0 ) ;
}
if ( ( ( int ) V_161 -> V_167 > ( int ) V_161 -> V_132 ) &&
( V_161 -> V_132 > 0 ) ) {
ASSERT ( V_161 -> V_144 != 0 ) ;
}
}
#endif
}
STATIC T_2
F_55 (
T_2 V_2 )
{
ASSERT ( ( V_2 & ( V_170 | V_169 ) ) !=
( V_170 | V_169 ) ) ;
ASSERT ( ( V_2 & ( V_170 | V_171 ) ) !=
( V_170 | V_171 ) ) ;
ASSERT ( ( V_2 & ( V_169 | V_171 ) ) !=
( V_169 | V_171 ) ) ;
ASSERT ( ( V_2 & ( V_170 | V_169 | V_171 ) ) != 0 ) ;
return ( V_2 & V_64 ) ?
V_169 : ( V_2 & V_67 ) ?
V_170 : V_171 ;
}
STATIC T_2
F_35 (
T_2 V_2 )
{
T_2 V_172 ;
V_172 = 0 ;
if ( V_2 & V_19 )
V_172 |= V_173 ;
if ( V_2 & V_29 )
V_172 |= V_174 ;
if ( V_2 & V_24 )
V_172 |= V_175 ;
if ( V_2 & V_22 )
V_172 |= V_176 ;
if ( V_2 & ( V_27 ) ) {
V_172 |= ( V_2 & V_24 ) ?
V_177 : V_178 ;
}
return ( V_172 ) ;
}
STATIC int
F_62 (
struct V_41 * V_42 ,
struct V_179 * V_180 ,
int V_2 )
{
if ( V_42 == V_42 -> V_181 -> V_5 -> V_37 ||
V_42 == V_42 -> V_181 -> V_5 -> V_38 ) {
ASSERT ( V_42 -> V_182 == NULL ) ;
ASSERT ( V_42 -> V_183 == NULL ) ;
return 0 ;
}
F_18 ( V_42 , V_51 ) ;
if ( ( V_2 & V_19 ) && V_42 -> V_182 ) {
F_46 ( V_42 -> V_182 ) ;
V_42 -> V_182 = NULL ;
}
if ( V_2 & ( V_29 | V_24 ) && V_42 -> V_183 ) {
F_46 ( V_42 -> V_183 ) ;
V_42 -> V_183 = NULL ;
}
F_23 ( V_42 , V_51 ) ;
return 0 ;
}
void
F_9 (
struct V_39 * V_1 ,
T_2 V_2 )
{
ASSERT ( V_1 -> V_5 ) ;
F_63 ( V_1 , F_62 , V_2 ) ;
}
