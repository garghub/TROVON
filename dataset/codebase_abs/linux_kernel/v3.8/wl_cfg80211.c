static bool F_1 ( struct V_1 * V_2 )
{
if ( ! F_2 ( V_3 , & V_2 -> V_4 ) ) {
F_3 ( V_5 , L_1 ,
V_2 -> V_4 ) ;
return false ;
}
return true ;
}
static T_1 F_4 ( T_2 V_6 )
{
T_3 V_7 = 1 ;
int V_8 = V_6 - V_9 ;
if ( V_8 >= V_10 )
return 0xFFFF ;
while ( V_8 < 0 ) {
V_8 += 40 ;
V_7 *= 10 ;
}
return ( V_11 [ V_8 ] + V_7 / 2 ) / V_7 ;
}
static T_2 F_5 ( T_1 V_12 )
{
T_2 V_6 ;
int V_13 ;
T_3 V_14 = V_12 ;
T_3 V_15 ;
if ( V_14 <= 1 )
return 0 ;
V_13 = V_9 ;
while ( V_14 < V_16 ) {
V_14 *= 10 ;
V_13 -= 40 ;
}
for ( V_6 = 0 ; V_6 < V_10 - 1 ; V_6 ++ ) {
V_15 = V_11 [ V_6 ] + ( V_11 [ V_6 + 1 ] -
V_11 [ V_6 ] ) / 2 ;
if ( V_14 < V_15 )
break;
}
V_6 += ( T_2 ) V_13 ;
return V_6 ;
}
static T_1 F_6 ( struct V_17 * V_18 )
{
T_1 V_19 ;
V_19 = F_7 ( V_18 -> V_20 ) ;
V_19 &= V_21 ;
if ( V_18 -> V_22 == V_23 )
V_19 |= V_24 ;
else
V_19 |= V_25 ;
if ( V_18 -> V_26 & V_27 ) {
V_19 |= V_28 ;
V_19 |= V_29 ;
} else {
V_19 |= V_30 ;
if ( V_18 -> V_26 & V_31 )
V_19 |= V_32 ;
else
V_19 |= V_33 ;
}
return V_19 ;
}
static void F_8 ( struct V_34 * V_35 ,
struct V_36 * V_37 )
{
V_37 -> V_38 = F_9 ( V_35 -> V_38 ) ;
V_37 -> V_39 = F_9 ( V_35 -> V_39 ) ;
V_37 -> V_40 = F_9 ( V_35 -> V_40 ) ;
V_37 -> V_26 = F_9 ( V_35 -> V_26 ) ;
V_37 -> V_41 . V_42 = F_9 ( V_35 -> V_41 . V_42 ) ;
V_37 -> V_41 . V_43 = F_10 ( V_35 -> V_41 . V_43 ) ;
V_37 -> V_44 = F_9 ( V_35 -> V_44 ) ;
memcpy ( V_37 -> V_45 , V_35 -> V_45 , sizeof( V_35 -> V_45 ) ) ;
memcpy ( V_37 -> V_46 , V_35 -> V_46 , sizeof( V_35 -> V_46 ) ) ;
}
static int
F_11 ( struct V_47 * V_48 , struct V_34 * V_35 )
{
int V_49 ;
struct V_36 V_37 ;
F_8 ( V_35 , & V_37 ) ;
F_12 ( V_48 ) ;
V_49 = F_13 ( F_14 ( V_48 ) , L_2 , & V_37 ,
sizeof( V_37 ) ) ;
if ( V_49 )
F_15 ( L_3 , V_49 ) ;
return V_49 ;
}
static T_4
F_16 ( struct V_50 * V_50 , struct V_47 * V_48 ,
enum V_51 type , T_5 * V_26 ,
struct V_52 * V_53 )
{
struct V_54 * V_55 = F_14 ( V_48 ) ;
struct V_1 * V_2 = V_55 -> V_2 ;
T_4 V_56 = 0 ;
T_4 V_57 = 0 ;
T_4 V_49 = 0 ;
F_3 ( V_58 , L_4 , V_48 , type ) ;
switch ( type ) {
case V_59 :
case V_60 :
F_15 ( L_5 ,
type ) ;
return - V_61 ;
case V_62 :
V_2 -> V_63 = V_64 ;
V_56 = 0 ;
break;
case V_65 :
V_2 -> V_63 = V_66 ;
V_56 = 1 ;
break;
case V_67 :
V_2 -> V_63 = V_68 ;
V_57 = 1 ;
break;
default:
V_49 = - V_69 ;
goto V_70;
}
if ( V_57 ) {
F_17 ( V_71 , & V_2 -> V_4 ) ;
F_3 ( V_5 , L_6 ) ;
} else {
V_49 = F_18 ( V_55 , V_72 , V_56 ) ;
if ( V_49 ) {
F_15 ( L_7 , V_49 ) ;
V_49 = - V_73 ;
goto V_70;
}
F_3 ( V_5 , L_8 , ( V_2 -> V_63 == V_64 ) ?
L_9 : L_10 ) ;
}
V_48 -> V_74 -> V_75 = type ;
V_70:
F_3 ( V_58 , L_11 ) ;
return V_49 ;
}
static void F_19 ( struct V_47 * V_48 , int V_76 )
{
struct V_54 * V_55 = F_14 ( V_48 ) ;
T_4 V_49 = 0 ;
if ( F_1 ( V_55 -> V_2 ) ) {
V_49 = F_20 ( V_55 , L_12 , V_76 ) ;
if ( V_49 ) {
F_15 ( L_13 ) ;
return;
}
F_3 ( V_5 , L_14 , V_76 ) ;
}
}
static void F_21 ( struct V_77 * V_78 ,
struct V_79 * V_80 )
{
T_5 V_81 ;
T_5 V_82 ;
T_4 V_83 ;
T_4 V_13 ;
T_1 V_19 ;
char * V_84 ;
struct V_85 V_86 ;
memset ( V_78 -> V_87 , 0xFF , V_88 ) ;
V_78 -> V_89 = V_90 ;
V_78 -> V_91 = 0 ;
V_78 -> V_92 = 0 ;
V_78 -> V_93 = F_9 ( - 1 ) ;
V_78 -> V_94 = F_9 ( - 1 ) ;
V_78 -> V_95 = F_9 ( - 1 ) ;
V_78 -> V_96 = F_9 ( - 1 ) ;
memset ( & V_78 -> V_86 , 0 , sizeof( V_78 -> V_86 ) ) ;
if ( ! V_80 )
return;
V_81 = V_80 -> V_81 ;
V_82 = V_80 -> V_82 ;
F_3 ( V_97 , L_15 ,
V_82 ) ;
if ( V_82 > 0 ) {
for ( V_83 = 0 ; V_83 < V_82 ; V_83 ++ ) {
V_19 = F_6 ( V_80 -> V_98 [ V_83 ] ) ;
F_3 ( V_97 , L_16 ,
V_80 -> V_98 [ V_83 ] -> V_99 , V_19 ) ;
V_78 -> V_100 [ V_83 ] = F_10 ( V_19 ) ;
}
} else {
F_3 ( V_97 , L_17 ) ;
}
F_3 ( V_97 , L_18 , V_81 ) ;
if ( V_81 > 0 ) {
V_13 = F_22 ( struct V_77 , V_100 ) +
V_82 * sizeof( T_1 ) ;
V_13 = F_23 ( V_13 , sizeof( T_5 ) ) ;
V_84 = ( char * ) V_78 + V_13 ;
for ( V_83 = 0 ; V_83 < V_81 ; V_83 ++ ) {
memset ( & V_86 , 0 , sizeof( V_86 ) ) ;
V_86 . V_101 =
F_9 ( V_80 -> V_102 [ V_83 ] . V_103 ) ;
memcpy ( V_86 . V_104 , V_80 -> V_102 [ V_83 ] . V_105 ,
V_80 -> V_102 [ V_83 ] . V_103 ) ;
if ( ! V_86 . V_101 )
F_3 ( V_97 , L_19 , V_83 ) ;
else
F_3 ( V_97 , L_20 ,
V_83 , V_86 . V_104 , V_86 . V_101 ) ;
memcpy ( V_84 , & V_86 , sizeof( V_86 ) ) ;
V_84 += sizeof( V_86 ) ;
}
} else {
F_3 ( V_97 , L_21 , V_80 -> V_102 ) ;
if ( ( V_80 -> V_102 ) && V_80 -> V_102 -> V_103 ) {
F_3 ( V_97 , L_22 ,
V_78 -> V_86 . V_104 ,
V_80 -> V_102 -> V_103 ) ;
V_78 -> V_86 . V_101 =
F_9 ( V_80 -> V_102 -> V_103 ) ;
memcpy ( & V_78 -> V_86 . V_104 , V_80 -> V_102 -> V_105 ,
V_80 -> V_102 -> V_103 ) ;
}
}
V_78 -> V_92 =
F_9 ( ( V_81 << V_106 ) |
( V_82 & V_107 ) ) ;
}
static T_4
F_24 ( struct V_108 * V_109 ,
struct V_47 * V_48 ,
bool V_110 , bool V_111 )
{
struct V_77 V_78 ;
struct V_79 * V_112 ;
T_4 V_49 = 0 ;
F_3 ( V_97 , L_23 ) ;
V_112 = V_109 -> V_112 ;
V_109 -> V_112 = NULL ;
if ( F_25 ( & V_109 -> V_113 ) )
F_26 ( & V_109 -> V_113 ) ;
if ( V_111 ) {
F_3 ( V_97 , L_24 ) ;
memset ( & V_78 , 0 , sizeof( V_78 ) ) ;
memset ( V_78 . V_87 , 0xFF , V_88 ) ;
V_78 . V_89 = V_90 ;
V_78 . V_91 = 0 ;
V_78 . V_92 = F_9 ( 1 ) ;
V_78 . V_93 = F_9 ( 1 ) ;
V_78 . V_94 = F_9 ( - 1 ) ;
V_78 . V_95 = F_9 ( - 1 ) ;
V_78 . V_96 = F_9 ( - 1 ) ;
V_78 . V_100 [ 0 ] = F_10 ( - 1 ) ;
V_49 = F_27 ( F_14 ( V_48 ) , V_114 ,
& V_78 , sizeof( V_78 ) ) ;
if ( V_49 )
F_15 ( L_25 ) ;
}
if ( V_109 -> V_115 ) {
F_3 ( V_97 , L_26 ) ;
V_109 -> V_115 = false ;
if ( ! V_110 )
F_28 ( F_29 ( V_109 ) ) ;
F_19 ( V_48 , 1 ) ;
} else if ( V_112 ) {
F_3 ( V_97 , L_27 ,
V_110 ? L_28 : L_29 ) ;
F_30 ( V_112 , V_110 ) ;
F_19 ( V_48 , 1 ) ;
}
if ( ! F_31 ( V_116 , & V_109 -> V_117 ) ) {
F_15 ( L_30 ) ;
return - V_118 ;
}
return V_49 ;
}
static T_4
F_32 ( struct V_108 * V_109 , struct V_47 * V_48 ,
struct V_79 * V_80 , T_1 V_119 )
{
T_4 V_120 = V_121 +
F_22 ( struct V_122 , V_78 ) ;
struct V_122 * V_53 ;
T_4 V_49 = 0 ;
F_3 ( V_97 , L_31 ) ;
if ( V_80 != NULL ) {
V_120 += sizeof( T_5 ) * ( ( V_80 -> V_82 + 1 ) / 2 ) ;
V_120 += sizeof( struct V_123 ) * V_80 -> V_81 ;
}
V_53 = F_33 ( V_120 , V_124 ) ;
if ( ! V_53 ) {
V_49 = - V_125 ;
goto exit;
}
F_34 ( V_120 + sizeof( L_32 ) >= V_126 ) ;
F_21 ( & V_53 -> V_78 , V_80 ) ;
V_53 -> V_127 = F_9 ( V_128 ) ;
V_53 -> V_119 = F_10 ( V_119 ) ;
V_53 -> V_129 = F_10 ( 0x1234 ) ;
V_49 = F_35 ( F_14 ( V_48 ) , L_32 ,
V_53 , V_120 ) ;
if ( V_49 ) {
if ( V_49 == - V_130 )
F_3 ( V_5 , L_33 ) ;
else
F_15 ( L_34 , V_49 ) ;
}
F_36 ( V_53 ) ;
exit:
return V_49 ;
}
static T_4
F_37 ( struct V_108 * V_109 , struct V_50 * V_50 ,
struct V_47 * V_48 , struct V_79 * V_80 )
{
T_4 V_49 ;
T_5 V_131 ;
struct V_132 * V_133 ;
F_3 ( V_97 , L_23 ) ;
V_109 -> V_134 . V_48 = V_48 ;
V_109 -> V_134 . V_50 = V_50 ;
V_109 -> V_134 . V_135 = V_136 ;
V_131 = V_109 -> V_137 ? 0 : 1 ;
V_49 = F_18 ( F_14 ( V_48 ) , V_138 ,
V_131 ) ;
if ( V_49 ) {
F_15 ( L_34 , V_49 ) ;
return V_49 ;
}
F_19 ( V_48 , 0 ) ;
V_133 = (struct V_132 * ) V_109 -> V_134 . V_139 ;
V_133 -> V_127 = 0 ;
V_133 -> V_140 = 0 ;
V_133 -> V_141 = V_142 ;
V_49 = F_32 ( V_109 , V_48 , V_80 , V_143 ) ;
if ( V_49 )
F_19 ( V_48 , 1 ) ;
return V_49 ;
}
static T_4
F_38 ( struct V_50 * V_50 , struct V_47 * V_48 ,
struct V_79 * V_80 ,
struct V_144 * V_145 )
{
struct V_54 * V_55 = F_14 ( V_48 ) ;
struct V_108 * V_109 = F_39 ( V_48 ) ;
struct V_144 * V_102 ;
struct V_146 * V_147 = & V_109 -> V_148 ;
T_5 V_131 ;
bool V_149 ;
bool V_150 ;
T_4 V_49 ;
T_5 V_101 ;
F_3 ( V_97 , L_35 ) ;
if ( F_2 ( V_116 , & V_109 -> V_117 ) ) {
F_15 ( L_36 , V_109 -> V_117 ) ;
return - V_73 ;
}
if ( F_2 ( V_151 , & V_109 -> V_117 ) ) {
F_15 ( L_37 ,
V_109 -> V_117 ) ;
return - V_73 ;
}
if ( F_2 ( V_152 , & V_55 -> V_2 -> V_4 ) ) {
F_15 ( L_38 , V_55 -> V_2 -> V_4 ) ;
return - V_73 ;
}
F_40 ( & V_109 -> V_113 , V_153 +
V_154 * V_155 / 1000 ) ;
V_149 = false ;
if ( V_80 ) {
V_102 = V_80 -> V_102 ;
V_149 = true ;
} else {
V_102 = V_145 ;
}
V_109 -> V_112 = V_80 ;
F_17 ( V_116 , & V_109 -> V_117 ) ;
if ( V_149 ) {
V_49 = F_37 ( V_109 , V_50 , V_48 , V_80 ) ;
if ( V_49 )
goto V_156;
} else {
F_3 ( V_97 , L_39 ,
V_102 -> V_105 , V_102 -> V_103 ) ;
memset ( & V_147 -> V_86 , 0 , sizeof( V_147 -> V_86 ) ) ;
V_101 = F_41 ( T_2 , sizeof( V_147 -> V_86 . V_104 ) , V_102 -> V_103 ) ;
V_147 -> V_86 . V_101 = F_9 ( 0 ) ;
V_150 = false ;
if ( V_101 ) {
memcpy ( V_147 -> V_86 . V_104 , V_102 -> V_105 , V_101 ) ;
V_147 -> V_86 . V_101 = F_9 ( V_101 ) ;
V_150 = true ;
} else
F_3 ( V_97 , L_40 ) ;
V_131 = V_109 -> V_137 ? 0 : 1 ;
V_49 = F_18 ( V_55 , V_138 ,
V_131 ) ;
if ( V_49 ) {
F_15 ( L_41 , V_49 ) ;
goto V_156;
}
F_19 ( V_48 , 0 ) ;
V_49 = F_27 ( V_55 , V_114 ,
& V_147 -> V_86 , sizeof( V_147 -> V_86 ) ) ;
if ( V_49 ) {
if ( V_49 == - V_130 )
F_3 ( V_5 , L_42 ,
V_147 -> V_86 . V_104 ) ;
else
F_15 ( L_43 , V_49 ) ;
F_19 ( V_48 , 1 ) ;
goto V_156;
}
}
return 0 ;
V_156:
F_42 ( V_116 , & V_109 -> V_117 ) ;
if ( F_25 ( & V_109 -> V_113 ) )
F_26 ( & V_109 -> V_113 ) ;
V_109 -> V_112 = NULL ;
return V_49 ;
}
static T_4
F_43 ( struct V_50 * V_50 , struct V_79 * V_80 )
{
struct V_47 * V_48 = V_80 -> V_157 -> V_158 ;
T_4 V_49 = 0 ;
F_3 ( V_58 , L_23 ) ;
if ( ! F_1 ( F_44 ( V_80 -> V_157 ,
struct V_1 , V_157 ) ) )
return - V_159 ;
V_49 = F_38 ( V_50 , V_48 , V_80 , NULL ) ;
if ( V_49 )
F_15 ( L_44 , V_49 ) ;
F_3 ( V_58 , L_11 ) ;
return V_49 ;
}
static T_4 F_45 ( struct V_47 * V_48 , T_5 V_160 )
{
T_4 V_49 = 0 ;
V_49 = F_20 ( F_14 ( V_48 ) , L_45 ,
V_160 ) ;
if ( V_49 )
F_15 ( L_46 , V_49 ) ;
return V_49 ;
}
static T_4 F_46 ( struct V_47 * V_48 , T_5 V_161 )
{
T_4 V_49 = 0 ;
V_49 = F_20 ( F_14 ( V_48 ) , L_47 ,
V_161 ) ;
if ( V_49 )
F_15 ( L_46 , V_49 ) ;
return V_49 ;
}
static T_4 F_47 ( struct V_47 * V_48 , T_5 V_162 , bool V_163 )
{
T_4 V_49 = 0 ;
T_5 V_164 = ( V_163 ? V_165 : V_166 ) ;
V_49 = F_18 ( F_14 ( V_48 ) , V_164 , V_162 ) ;
if ( V_49 ) {
F_15 ( L_48 , V_164 , V_49 ) ;
return V_49 ;
}
return V_49 ;
}
static T_4 F_48 ( struct V_50 * V_50 , T_5 V_167 )
{
struct V_108 * V_109 = F_49 ( V_50 ) ;
struct V_47 * V_48 = F_50 ( V_109 ) ;
struct V_54 * V_55 = F_14 ( V_48 ) ;
T_4 V_49 = 0 ;
F_3 ( V_58 , L_23 ) ;
if ( ! F_1 ( V_55 -> V_2 ) )
return - V_159 ;
if ( V_167 & V_168 &&
( V_109 -> V_169 -> V_160 != V_50 -> V_160 ) ) {
V_109 -> V_169 -> V_160 = V_50 -> V_160 ;
V_49 = F_45 ( V_48 , V_109 -> V_169 -> V_160 ) ;
if ( ! V_49 )
goto V_70;
}
if ( V_167 & V_170 &&
( V_109 -> V_169 -> V_161 != V_50 -> V_161 ) ) {
V_109 -> V_169 -> V_161 = V_50 -> V_161 ;
V_49 = F_46 ( V_48 , V_109 -> V_169 -> V_161 ) ;
if ( ! V_49 )
goto V_70;
}
if ( V_167 & V_171
&& ( V_109 -> V_169 -> V_172 != V_50 -> V_172 ) ) {
V_109 -> V_169 -> V_172 = V_50 -> V_172 ;
V_49 = F_47 ( V_48 , V_109 -> V_169 -> V_172 , true ) ;
if ( ! V_49 )
goto V_70;
}
if ( V_167 & V_173
&& ( V_109 -> V_169 -> V_174 != V_50 -> V_174 ) ) {
V_109 -> V_169 -> V_174 = V_50 -> V_174 ;
V_49 = F_47 ( V_48 , V_109 -> V_169 -> V_174 , false ) ;
if ( ! V_49 )
goto V_70;
}
V_70:
F_3 ( V_58 , L_11 ) ;
return V_49 ;
}
static void F_51 ( struct V_175 * V_176 )
{
memset ( V_176 , 0 , sizeof( * V_176 ) ) ;
}
static void F_52 ( int V_18 , struct V_177 * V_178 ,
T_6 * V_179 )
{
T_1 V_19 = 0 ;
if ( V_18 != 0 ) {
if ( V_18 <= V_180 )
V_19 |= V_24 ;
else
V_19 |= V_25 ;
V_19 |= V_28 ;
V_19 |= V_29 ;
* V_179 += V_181 +
sizeof( T_1 ) ;
V_19 |= ( V_18 & V_21 ) ;
V_178 -> V_78 . V_182 [ 0 ] = F_10 ( V_19 ) ;
V_178 -> V_78 . V_183 = F_9 ( 1 ) ;
F_3 ( V_184 , L_49 , V_18 , V_19 ) ;
}
}
static void F_53 ( struct V_1 * V_2 )
{
T_4 V_49 = 0 ;
F_3 ( V_58 , L_23 ) ;
if ( F_2 ( V_185 , & V_2 -> V_4 ) ) {
F_3 ( V_5 , L_50 ) ;
V_49 = F_27 ( V_2 -> V_55 ,
V_186 , NULL , 0 ) ;
if ( V_49 )
F_15 ( L_51 , V_49 ) ;
F_42 ( V_185 , & V_2 -> V_4 ) ;
}
F_42 ( V_152 , & V_2 -> V_4 ) ;
F_3 ( V_58 , L_11 ) ;
}
static T_4
F_54 ( struct V_50 * V_50 , struct V_47 * V_48 ,
struct V_187 * V_53 )
{
struct V_108 * V_109 = F_49 ( V_50 ) ;
struct V_54 * V_55 = F_14 ( V_48 ) ;
struct V_175 * V_188 = & V_55 -> V_2 -> V_188 ;
struct V_177 V_178 ;
T_6 V_179 = 0 ;
T_4 V_49 = 0 ;
T_4 V_189 = 0 ;
T_4 V_190 ;
F_3 ( V_58 , L_23 ) ;
if ( ! F_1 ( V_55 -> V_2 ) )
return - V_159 ;
if ( V_53 -> V_105 )
F_3 ( V_184 , L_52 , V_53 -> V_105 ) ;
else {
F_3 ( V_184 , L_53 ) ;
return - V_61 ;
}
F_17 ( V_152 , & V_55 -> V_2 -> V_4 ) ;
if ( V_53 -> V_87 )
F_3 ( V_184 , L_54 , V_53 -> V_87 ) ;
else
F_3 ( V_184 , L_55 ) ;
if ( V_53 -> V_191 . V_192 )
F_3 ( V_184 , L_56 ,
V_53 -> V_191 . V_192 -> V_20 ) ;
else
F_3 ( V_184 , L_57 ) ;
if ( V_53 -> V_193 )
F_3 ( V_184 , L_58 ) ;
else
F_3 ( V_184 , L_59 ) ;
if ( V_53 -> V_194 && V_53 -> V_195 )
F_3 ( V_184 , L_60 , V_53 -> V_195 ) ;
else
F_3 ( V_184 , L_61 ) ;
if ( V_53 -> V_196 )
F_3 ( V_184 , L_62 ,
V_53 -> V_196 ) ;
else
F_3 ( V_184 , L_63 ) ;
if ( V_53 -> V_197 )
F_3 ( V_184 , L_64 , V_53 -> V_197 ) ;
else
F_3 ( V_184 , L_65 ) ;
if ( V_53 -> V_198 )
F_3 ( V_184 , L_66 ) ;
else
F_3 ( V_184 , L_67 ) ;
if ( V_53 -> V_198 )
V_189 |= V_199 ;
V_49 = F_20 ( V_55 , L_68 , V_189 ) ;
if ( V_49 ) {
F_15 ( L_69 , V_49 ) ;
goto V_70;
}
if ( V_53 -> V_196 )
V_190 = V_53 -> V_196 ;
else
V_190 = 100 ;
V_49 = F_18 ( V_55 , V_200 , V_190 ) ;
if ( V_49 ) {
F_15 ( L_70 , V_49 ) ;
goto V_70;
}
memset ( & V_178 , 0 , sizeof( struct V_177 ) ) ;
V_188 -> V_105 . V_101 = F_41 ( T_5 , V_53 -> V_103 , 32 ) ;
memcpy ( V_188 -> V_105 . V_104 , V_53 -> V_105 , V_188 -> V_105 . V_101 ) ;
memcpy ( V_178 . V_86 . V_104 , V_53 -> V_105 , V_188 -> V_105 . V_101 ) ;
V_178 . V_86 . V_101 = F_9 ( V_188 -> V_105 . V_101 ) ;
V_179 = sizeof( V_178 . V_86 ) ;
if ( V_53 -> V_87 ) {
memcpy ( V_178 . V_78 . V_87 , V_53 -> V_87 , V_88 ) ;
V_179 = sizeof( V_178 . V_86 ) +
V_181 ;
memcpy ( V_188 -> V_87 , V_53 -> V_87 , V_88 ) ;
} else {
memset ( V_178 . V_78 . V_87 , 0xFF , V_88 ) ;
memset ( V_188 -> V_87 , 0 , V_88 ) ;
}
if ( V_53 -> V_191 . V_192 ) {
T_5 V_201 ;
V_109 -> V_202 =
F_7 (
V_53 -> V_191 . V_192 -> V_20 ) ;
if ( V_53 -> V_193 ) {
F_52 ( V_109 -> V_202 ,
& V_178 , & V_179 ) ;
}
V_201 = V_109 -> V_202 ;
V_49 = F_18 ( V_55 , V_203 ,
V_201 ) ;
if ( V_49 ) {
F_15 ( L_71 , V_49 ) ;
goto V_70;
}
} else
V_109 -> V_202 = 0 ;
V_109 -> V_204 = false ;
V_49 = F_27 ( V_55 , V_205 ,
& V_178 , V_179 ) ;
if ( V_49 ) {
F_15 ( L_72 , V_49 ) ;
goto V_70;
}
V_70:
if ( V_49 )
F_42 ( V_152 , & V_55 -> V_2 -> V_4 ) ;
F_3 ( V_58 , L_11 ) ;
return V_49 ;
}
static T_4
F_55 ( struct V_50 * V_50 , struct V_47 * V_48 )
{
struct V_54 * V_55 = F_14 ( V_48 ) ;
T_4 V_49 = 0 ;
F_3 ( V_58 , L_23 ) ;
if ( ! F_1 ( V_55 -> V_2 ) )
return - V_159 ;
F_53 ( V_55 -> V_2 ) ;
F_3 ( V_58 , L_11 ) ;
return V_49 ;
}
static T_4 F_56 ( struct V_47 * V_48 ,
struct V_206 * V_207 )
{
struct V_175 * V_188 = F_57 ( V_48 ) ;
struct V_208 * V_209 ;
T_4 V_210 = 0 ;
T_4 V_49 = 0 ;
if ( V_207 -> V_211 . V_212 & V_213 )
V_210 = V_214 | V_215 ;
else if ( V_207 -> V_211 . V_212 & V_216 )
V_210 = V_217 | V_218 ;
else
V_210 = V_219 ;
F_3 ( V_184 , L_73 , V_210 ) ;
V_49 = F_20 ( F_14 ( V_48 ) , L_74 , V_210 ) ;
if ( V_49 ) {
F_15 ( L_75 , V_49 ) ;
return V_49 ;
}
V_209 = & V_188 -> V_209 ;
V_209 -> V_212 = V_207 -> V_211 . V_212 ;
return V_49 ;
}
static T_4 F_58 ( struct V_47 * V_48 ,
struct V_206 * V_207 )
{
struct V_175 * V_188 = F_57 ( V_48 ) ;
struct V_208 * V_209 ;
T_4 V_210 = 0 ;
T_4 V_49 = 0 ;
switch ( V_207 -> V_220 ) {
case V_221 :
V_210 = 0 ;
F_3 ( V_184 , L_76 ) ;
break;
case V_222 :
V_210 = 1 ;
F_3 ( V_184 , L_77 ) ;
break;
case V_223 :
V_210 = 2 ;
F_3 ( V_184 , L_78 ) ;
break;
case V_224 :
F_3 ( V_184 , L_79 ) ;
default:
V_210 = 2 ;
F_15 ( L_80 , V_207 -> V_220 ) ;
break;
}
V_49 = F_20 ( F_14 ( V_48 ) , L_81 , V_210 ) ;
if ( V_49 ) {
F_15 ( L_82 , V_49 ) ;
return V_49 ;
}
V_209 = & V_188 -> V_209 ;
V_209 -> V_220 = V_207 -> V_220 ;
return V_49 ;
}
static T_4
F_59 ( struct V_47 * V_48 ,
struct V_206 * V_207 )
{
struct V_175 * V_188 = F_57 ( V_48 ) ;
struct V_208 * V_209 ;
T_4 V_225 = 0 ;
T_4 V_226 = 0 ;
T_4 V_49 = 0 ;
if ( V_207 -> V_211 . V_227 ) {
switch ( V_207 -> V_211 . V_228 [ 0 ] ) {
case V_229 :
case V_230 :
V_225 = V_199 ;
break;
case V_231 :
V_225 = V_232 ;
break;
case V_233 :
V_225 = V_234 ;
break;
case V_235 :
V_225 = V_234 ;
break;
default:
F_15 ( L_83 ,
V_207 -> V_211 . V_228 [ 0 ] ) ;
return - V_69 ;
}
}
if ( V_207 -> V_211 . V_236 ) {
switch ( V_207 -> V_211 . V_236 ) {
case V_229 :
case V_230 :
V_226 = V_199 ;
break;
case V_231 :
V_226 = V_232 ;
break;
case V_233 :
V_226 = V_234 ;
break;
case V_235 :
V_226 = V_234 ;
break;
default:
F_15 ( L_84 ,
V_207 -> V_211 . V_236 ) ;
return - V_69 ;
}
}
F_3 ( V_184 , L_85 , V_225 , V_226 ) ;
V_49 = F_20 ( F_14 ( V_48 ) , L_68 , V_225 | V_226 ) ;
if ( V_49 ) {
F_15 ( L_34 , V_49 ) ;
return V_49 ;
}
V_209 = & V_188 -> V_209 ;
V_209 -> V_237 = V_207 -> V_211 . V_228 [ 0 ] ;
V_209 -> V_236 = V_207 -> V_211 . V_236 ;
return V_49 ;
}
static T_4
F_60 ( struct V_47 * V_48 , struct V_206 * V_207 )
{
struct V_175 * V_188 = F_57 ( V_48 ) ;
struct V_208 * V_209 ;
T_4 V_210 = 0 ;
T_4 V_49 = 0 ;
if ( V_207 -> V_211 . V_238 ) {
V_49 = F_61 ( F_14 ( V_48 ) ,
L_74 , & V_210 ) ;
if ( V_49 ) {
F_15 ( L_86 , V_49 ) ;
return V_49 ;
}
if ( V_210 & ( V_214 | V_215 ) ) {
switch ( V_207 -> V_211 . V_239 [ 0 ] ) {
case V_240 :
V_210 = V_215 ;
break;
case V_241 :
V_210 = V_214 ;
break;
default:
F_15 ( L_84 ,
V_207 -> V_211 . V_236 ) ;
return - V_69 ;
}
} else if ( V_210 & ( V_217 | V_218 ) ) {
switch ( V_207 -> V_211 . V_239 [ 0 ] ) {
case V_240 :
V_210 = V_218 ;
break;
case V_241 :
V_210 = V_217 ;
break;
default:
F_15 ( L_84 ,
V_207 -> V_211 . V_236 ) ;
return - V_69 ;
}
}
F_3 ( V_184 , L_87 , V_210 ) ;
V_49 = F_20 ( F_14 ( V_48 ) ,
L_74 , V_210 ) ;
if ( V_49 ) {
F_15 ( L_88 , V_49 ) ;
return V_49 ;
}
}
V_209 = & V_188 -> V_209 ;
V_209 -> V_242 = V_207 -> V_211 . V_239 [ 0 ] ;
return V_49 ;
}
static T_4
F_62 ( struct V_47 * V_48 ,
struct V_206 * V_207 )
{
struct V_175 * V_188 = F_57 ( V_48 ) ;
struct V_208 * V_209 ;
struct V_34 V_35 ;
T_4 V_210 ;
T_4 V_49 = 0 ;
F_3 ( V_184 , L_89 , V_207 -> V_243 ) ;
if ( V_207 -> V_243 == 0 )
return 0 ;
V_209 = & V_188 -> V_209 ;
F_3 ( V_184 , L_90 ,
V_209 -> V_212 , V_209 -> V_237 ) ;
if ( V_209 -> V_212 & ( V_213 | V_216 ) )
return 0 ;
if ( ! ( V_209 -> V_237 &
( V_229 | V_230 ) ) )
return 0 ;
memset ( & V_35 , 0 , sizeof( V_35 ) ) ;
V_35 . V_39 = ( T_5 ) V_207 -> V_243 ;
V_35 . V_38 = ( T_5 ) V_207 -> V_244 ;
if ( V_35 . V_39 > sizeof( V_35 . V_45 ) ) {
F_15 ( L_91 , V_35 . V_39 ) ;
return - V_69 ;
}
memcpy ( V_35 . V_45 , V_207 -> V_35 , V_35 . V_39 ) ;
V_35 . V_26 = V_245 ;
switch ( V_209 -> V_237 ) {
case V_229 :
V_35 . V_40 = V_246 ;
break;
case V_230 :
V_35 . V_40 = V_247 ;
break;
default:
F_15 ( L_92 ,
V_207 -> V_211 . V_228 [ 0 ] ) ;
return - V_69 ;
}
F_3 ( V_184 , L_93 ,
V_35 . V_39 , V_35 . V_38 , V_35 . V_40 ) ;
F_3 ( V_184 , L_94 , V_35 . V_45 ) ;
V_49 = F_11 ( V_48 , & V_35 ) ;
if ( V_49 )
return V_49 ;
if ( V_209 -> V_220 == V_222 ) {
F_3 ( V_184 , L_95 ) ;
V_210 = V_248 ;
V_49 = F_63 ( F_14 ( V_48 ) , L_81 , V_210 ) ;
if ( V_49 )
F_15 ( L_82 , V_49 ) ;
}
return V_49 ;
}
static T_4
F_64 ( struct V_50 * V_50 , struct V_47 * V_48 ,
struct V_206 * V_207 )
{
struct V_108 * V_109 = F_49 ( V_50 ) ;
struct V_54 * V_55 = F_14 ( V_48 ) ;
struct V_175 * V_188 = & V_55 -> V_2 -> V_188 ;
struct V_17 * V_192 = V_207 -> V_202 ;
struct V_177 V_178 ;
T_6 V_179 ;
struct V_123 V_105 ;
T_4 V_49 = 0 ;
F_3 ( V_58 , L_23 ) ;
if ( ! F_1 ( V_55 -> V_2 ) )
return - V_159 ;
if ( ! V_207 -> V_105 ) {
F_15 ( L_96 ) ;
return - V_61 ;
}
F_17 ( V_152 , & V_55 -> V_2 -> V_4 ) ;
if ( V_192 ) {
V_109 -> V_202 =
F_7 ( V_192 -> V_20 ) ;
F_3 ( V_184 , L_97 ,
V_109 -> V_202 , V_192 -> V_20 ) ;
} else
V_109 -> V_202 = 0 ;
F_3 ( V_5 , L_98 , V_207 -> V_194 , V_207 -> V_195 ) ;
V_49 = F_56 ( V_48 , V_207 ) ;
if ( V_49 ) {
F_15 ( L_99 , V_49 ) ;
goto V_70;
}
V_49 = F_58 ( V_48 , V_207 ) ;
if ( V_49 ) {
F_15 ( L_100 , V_49 ) ;
goto V_70;
}
V_49 = F_59 ( V_48 , V_207 ) ;
if ( V_49 ) {
F_15 ( L_101 , V_49 ) ;
goto V_70;
}
V_49 = F_60 ( V_48 , V_207 ) ;
if ( V_49 ) {
F_15 ( L_102 , V_49 ) ;
goto V_70;
}
V_49 = F_62 ( V_48 , V_207 ) ;
if ( V_49 ) {
F_15 ( L_103 , V_49 ) ;
goto V_70;
}
memset ( & V_178 , 0 , sizeof( V_178 ) ) ;
V_179 = sizeof( V_178 . V_86 ) ;
V_188 -> V_105 . V_101 = F_41 ( T_5 ,
sizeof( V_105 . V_104 ) , ( T_5 ) V_207 -> V_103 ) ;
memcpy ( & V_178 . V_86 . V_104 , V_207 -> V_105 , V_188 -> V_105 . V_101 ) ;
memcpy ( & V_188 -> V_105 . V_104 , V_207 -> V_105 , V_188 -> V_105 . V_101 ) ;
V_178 . V_86 . V_101 = F_9 ( V_188 -> V_105 . V_101 ) ;
memset ( V_178 . V_78 . V_87 , 0xFF , V_88 ) ;
if ( V_105 . V_101 < V_249 )
F_3 ( V_184 , L_104 ,
V_105 . V_104 , V_105 . V_101 ) ;
F_52 ( V_109 -> V_202 ,
& V_178 , & V_179 ) ;
V_49 = F_27 ( V_55 , V_205 ,
& V_178 , V_179 ) ;
if ( V_49 )
F_15 ( L_72 , V_49 ) ;
V_70:
if ( V_49 )
F_42 ( V_152 , & V_55 -> V_2 -> V_4 ) ;
F_3 ( V_58 , L_11 ) ;
return V_49 ;
}
static T_4
F_65 ( struct V_50 * V_50 , struct V_47 * V_48 ,
T_1 V_250 )
{
struct V_54 * V_55 = F_14 ( V_48 ) ;
struct V_175 * V_188 = & V_55 -> V_2 -> V_188 ;
struct V_251 V_252 ;
T_4 V_49 = 0 ;
F_3 ( V_58 , L_105 , V_250 ) ;
if ( ! F_1 ( V_55 -> V_2 ) )
return - V_159 ;
F_42 ( V_185 , & V_55 -> V_2 -> V_4 ) ;
memcpy ( & V_252 . V_46 , & V_188 -> V_87 , V_88 ) ;
V_252 . V_210 = F_9 ( V_250 ) ;
V_49 = F_27 ( V_55 , V_186 ,
& V_252 , sizeof( V_252 ) ) ;
if ( V_49 )
F_15 ( L_34 , V_49 ) ;
F_3 ( V_58 , L_11 ) ;
return V_49 ;
}
static T_4
F_66 ( struct V_50 * V_50 , struct V_253 * V_157 ,
enum V_254 type , T_4 V_255 )
{
struct V_108 * V_109 = F_49 ( V_50 ) ;
struct V_47 * V_48 = F_50 ( V_109 ) ;
struct V_54 * V_55 = F_14 ( V_48 ) ;
T_1 V_256 ;
T_4 V_49 = 0 ;
T_4 V_257 = 0 ;
T_4 V_258 = F_67 ( V_255 ) ;
F_3 ( V_58 , L_23 ) ;
if ( ! F_1 ( V_55 -> V_2 ) )
return - V_159 ;
switch ( type ) {
case V_259 :
break;
case V_260 :
case V_261 :
if ( V_258 < 0 ) {
F_15 ( L_106 ) ;
V_49 = - V_69 ;
goto V_70;
}
break;
}
V_257 = V_262 << 16 ;
V_49 = F_18 ( V_55 , V_263 , V_257 ) ;
if ( V_49 )
F_15 ( L_107 , V_49 ) ;
if ( V_258 > 0xffff )
V_256 = 0xffff ;
else
V_256 = ( T_1 ) V_258 ;
V_49 = F_20 ( V_55 , L_108 ,
( T_4 ) F_5 ( V_256 ) ) ;
if ( V_49 )
F_15 ( L_109 , V_49 ) ;
V_109 -> V_169 -> V_264 = V_258 ;
V_70:
F_3 ( V_58 , L_11 ) ;
return V_49 ;
}
static T_4 F_68 ( struct V_50 * V_50 ,
struct V_253 * V_157 ,
T_4 * V_258 )
{
struct V_108 * V_109 = F_49 ( V_50 ) ;
struct V_54 * V_55 = F_14 ( F_50 ( V_109 ) ) ;
T_4 V_265 ;
T_2 V_266 ;
T_4 V_49 = 0 ;
F_3 ( V_58 , L_23 ) ;
if ( ! F_1 ( V_55 -> V_2 ) )
return - V_159 ;
V_49 = F_61 ( V_55 , L_108 , & V_265 ) ;
if ( V_49 ) {
F_15 ( L_34 , V_49 ) ;
goto V_70;
}
V_266 = ( T_2 ) ( V_265 & ~ V_267 ) ;
* V_258 = ( T_4 ) F_4 ( V_266 ) ;
V_70:
F_3 ( V_58 , L_11 ) ;
return V_49 ;
}
static T_4
F_69 ( struct V_50 * V_50 , struct V_47 * V_48 ,
T_2 V_244 , bool V_268 , bool V_269 )
{
struct V_54 * V_55 = F_14 ( V_48 ) ;
T_5 V_38 ;
T_5 V_189 ;
T_4 V_49 = 0 ;
F_3 ( V_58 , L_23 ) ;
F_3 ( V_184 , L_110 , V_244 ) ;
if ( ! F_1 ( V_55 -> V_2 ) )
return - V_159 ;
V_49 = F_70 ( V_55 , L_68 , & V_189 ) ;
if ( V_49 ) {
F_15 ( L_111 , V_49 ) ;
goto V_70;
}
if ( V_189 & V_199 ) {
V_38 = V_244 ;
V_49 = F_18 ( V_55 ,
V_270 , V_38 ) ;
if ( V_49 )
F_15 ( L_34 , V_49 ) ;
}
V_70:
F_3 ( V_58 , L_11 ) ;
return V_49 ;
}
static T_4
F_71 ( struct V_50 * V_50 , struct V_47 * V_48 ,
T_2 V_244 , const T_2 * V_271 , struct V_272 * V_53 )
{
struct V_34 V_35 ;
T_4 V_49 = 0 ;
memset ( & V_35 , 0 , sizeof( V_35 ) ) ;
V_35 . V_38 = ( T_5 ) V_244 ;
if ( ! F_72 ( V_271 ) )
memcpy ( ( char * ) & V_35 . V_46 , ( void * ) V_271 , V_88 ) ;
V_35 . V_39 = ( T_5 ) V_53 -> V_243 ;
if ( V_35 . V_39 == 0 ) {
V_49 = F_11 ( V_48 , & V_35 ) ;
if ( V_49 )
F_15 ( L_112 , V_49 ) ;
} else {
if ( V_35 . V_39 > sizeof( V_35 . V_45 ) ) {
F_15 ( L_113 , V_35 . V_39 ) ;
return - V_69 ;
}
F_3 ( V_184 , L_114 , V_35 . V_38 ) ;
memcpy ( V_35 . V_45 , V_53 -> V_35 , V_35 . V_39 ) ;
if ( V_53 -> V_273 == V_231 ) {
T_2 V_274 [ 8 ] ;
memcpy ( V_274 , & V_35 . V_45 [ 24 ] , sizeof( V_274 ) ) ;
memcpy ( & V_35 . V_45 [ 24 ] , & V_35 . V_45 [ 16 ] , sizeof( V_274 ) ) ;
memcpy ( & V_35 . V_45 [ 16 ] , V_274 , sizeof( V_274 ) ) ;
}
if ( V_53 -> V_275 && V_53 -> V_276 == 6 ) {
T_2 * V_277 ;
V_277 = ( T_2 * ) V_53 -> V_275 ;
V_35 . V_41 . V_42 = ( V_277 [ 5 ] << 24 ) | ( V_277 [ 4 ] << 16 ) |
( V_277 [ 3 ] << 8 ) | V_277 [ 2 ] ;
V_35 . V_41 . V_43 = ( V_277 [ 1 ] << 8 ) | V_277 [ 0 ] ;
V_35 . V_44 = true ;
}
switch ( V_53 -> V_273 ) {
case V_229 :
V_35 . V_40 = V_246 ;
F_3 ( V_184 , L_115 ) ;
break;
case V_230 :
V_35 . V_40 = V_247 ;
F_3 ( V_184 , L_116 ) ;
break;
case V_231 :
V_35 . V_40 = V_278 ;
F_3 ( V_184 , L_117 ) ;
break;
case V_235 :
V_35 . V_40 = V_279 ;
F_3 ( V_184 , L_118 ) ;
break;
case V_233 :
V_35 . V_40 = V_279 ;
F_3 ( V_184 , L_119 ) ;
break;
default:
F_15 ( L_120 , V_53 -> V_273 ) ;
return - V_69 ;
}
V_49 = F_11 ( V_48 , & V_35 ) ;
if ( V_49 )
F_15 ( L_3 , V_49 ) ;
}
return V_49 ;
}
static T_4
F_73 ( struct V_50 * V_50 , struct V_47 * V_48 ,
T_2 V_244 , bool V_280 , const T_2 * V_271 ,
struct V_272 * V_53 )
{
struct V_54 * V_55 = F_14 ( V_48 ) ;
struct V_34 V_35 ;
T_4 V_210 ;
T_4 V_189 ;
T_4 V_49 = 0 ;
T_2 V_274 [ 8 ] ;
F_3 ( V_58 , L_23 ) ;
F_3 ( V_184 , L_110 , V_244 ) ;
if ( ! F_1 ( V_55 -> V_2 ) )
return - V_159 ;
if ( V_271 ) {
F_3 ( V_58 , L_121 ) ;
return F_71 ( V_50 , V_48 , V_244 , V_271 , V_53 ) ;
}
memset ( & V_35 , 0 , sizeof( V_35 ) ) ;
V_35 . V_39 = ( T_5 ) V_53 -> V_243 ;
V_35 . V_38 = ( T_5 ) V_244 ;
if ( V_35 . V_39 > sizeof( V_35 . V_45 ) ) {
F_15 ( L_91 , V_35 . V_39 ) ;
V_49 = - V_69 ;
goto V_70;
}
memcpy ( V_35 . V_45 , V_53 -> V_35 , V_35 . V_39 ) ;
V_35 . V_26 = V_245 ;
switch ( V_53 -> V_273 ) {
case V_229 :
V_35 . V_40 = V_246 ;
V_210 = V_199 ;
F_3 ( V_184 , L_115 ) ;
break;
case V_230 :
V_35 . V_40 = V_247 ;
V_210 = V_199 ;
F_3 ( V_184 , L_116 ) ;
break;
case V_231 :
if ( V_55 -> V_2 -> V_63 != V_68 ) {
F_3 ( V_184 , L_122 ) ;
memcpy ( V_274 , & V_35 . V_45 [ 24 ] , sizeof( V_274 ) ) ;
memcpy ( & V_35 . V_45 [ 24 ] , & V_35 . V_45 [ 16 ] , sizeof( V_274 ) ) ;
memcpy ( & V_35 . V_45 [ 16 ] , V_274 , sizeof( V_274 ) ) ;
}
V_35 . V_40 = V_278 ;
V_210 = V_232 ;
F_3 ( V_184 , L_117 ) ;
break;
case V_235 :
V_35 . V_40 = V_279 ;
V_210 = V_234 ;
F_3 ( V_184 , L_118 ) ;
break;
case V_233 :
V_35 . V_40 = V_279 ;
V_210 = V_234 ;
F_3 ( V_184 , L_119 ) ;
break;
default:
F_15 ( L_120 , V_53 -> V_273 ) ;
V_49 = - V_69 ;
goto V_70;
}
V_49 = F_11 ( V_48 , & V_35 ) ;
if ( V_49 )
goto V_70;
V_49 = F_70 ( V_55 , L_68 , & V_189 ) ;
if ( V_49 ) {
F_15 ( L_123 , V_49 ) ;
goto V_70;
}
V_189 |= V_210 ;
V_49 = F_63 ( V_55 , L_68 , V_189 ) ;
if ( V_49 ) {
F_15 ( L_124 , V_49 ) ;
goto V_70;
}
V_70:
F_3 ( V_58 , L_11 ) ;
return V_49 ;
}
static T_4
F_74 ( struct V_50 * V_50 , struct V_47 * V_48 ,
T_2 V_244 , bool V_280 , const T_2 * V_271 )
{
struct V_54 * V_55 = F_14 ( V_48 ) ;
struct V_34 V_35 ;
T_4 V_49 = 0 ;
F_3 ( V_58 , L_23 ) ;
if ( ! F_1 ( V_55 -> V_2 ) )
return - V_159 ;
if ( V_244 >= V_281 ) {
F_15 ( L_125 , V_244 ) ;
return - V_69 ;
}
memset ( & V_35 , 0 , sizeof( V_35 ) ) ;
V_35 . V_38 = ( T_5 ) V_244 ;
V_35 . V_26 = V_245 ;
V_35 . V_40 = V_282 ;
F_3 ( V_184 , L_110 , V_244 ) ;
V_49 = F_11 ( V_48 , & V_35 ) ;
F_3 ( V_58 , L_11 ) ;
return V_49 ;
}
static T_4
F_75 ( struct V_50 * V_50 , struct V_47 * V_48 ,
T_2 V_244 , bool V_280 , const T_2 * V_271 , void * V_283 ,
void (* F_76) ( void * V_283 , struct V_272 * V_53 ) )
{
struct V_272 V_53 ;
struct V_54 * V_55 = F_14 ( V_48 ) ;
struct V_175 * V_188 = & V_55 -> V_2 -> V_188 ;
struct V_208 * V_209 ;
T_4 V_189 ;
T_4 V_49 = 0 ;
F_3 ( V_58 , L_23 ) ;
F_3 ( V_184 , L_110 , V_244 ) ;
if ( ! F_1 ( V_55 -> V_2 ) )
return - V_159 ;
memset ( & V_53 , 0 , sizeof( V_53 ) ) ;
V_49 = F_70 ( V_55 , L_68 , & V_189 ) ;
if ( V_49 ) {
F_15 ( L_111 , V_49 ) ;
V_49 = - V_73 ;
goto V_70;
}
switch ( V_189 & ~ V_284 ) {
case V_199 :
V_209 = & V_188 -> V_209 ;
if ( V_209 -> V_237 & V_229 ) {
V_53 . V_273 = V_229 ;
F_3 ( V_184 , L_115 ) ;
} else if ( V_209 -> V_237 & V_230 ) {
V_53 . V_273 = V_230 ;
F_3 ( V_184 , L_116 ) ;
}
break;
case V_232 :
V_53 . V_273 = V_231 ;
F_3 ( V_184 , L_117 ) ;
break;
case V_234 :
V_53 . V_273 = V_235 ;
F_3 ( V_184 , L_118 ) ;
break;
default:
F_15 ( L_126 , V_189 ) ;
V_49 = - V_69 ;
goto V_70;
}
F_76 ( V_283 , & V_53 ) ;
V_70:
F_3 ( V_58 , L_11 ) ;
return V_49 ;
}
static T_4
F_77 ( struct V_50 * V_50 ,
struct V_47 * V_48 , T_2 V_244 )
{
F_3 ( V_5 , L_127 ) ;
return - V_61 ;
}
static T_4
F_78 ( struct V_50 * V_50 , struct V_47 * V_48 ,
T_2 * V_285 , struct V_286 * V_287 )
{
struct V_54 * V_55 = F_14 ( V_48 ) ;
struct V_175 * V_188 = & V_55 -> V_2 -> V_188 ;
struct V_251 V_288 ;
int V_289 ;
T_4 V_290 ;
T_4 V_49 = 0 ;
T_2 * V_87 = V_188 -> V_87 ;
struct V_291 V_292 ;
F_3 ( V_58 , L_128 , V_285 ) ;
if ( ! F_1 ( V_55 -> V_2 ) )
return - V_159 ;
if ( V_55 -> V_2 -> V_63 == V_68 ) {
memcpy ( & V_292 , V_285 , V_88 ) ;
V_49 = F_79 ( V_55 , L_129 ,
& V_292 ,
sizeof( V_292 ) ) ;
if ( V_49 < 0 ) {
F_15 ( L_130 , V_49 ) ;
goto V_70;
}
V_287 -> V_293 = V_294 ;
V_287 -> V_295 = F_80 ( V_292 . V_296 ) * 1000 ;
if ( F_80 ( V_292 . V_26 ) & V_297 ) {
V_287 -> V_293 |= V_298 ;
V_287 -> V_299 = F_80 ( V_292 . V_300 ) ;
}
F_3 ( V_58 , L_131 ,
V_287 -> V_295 , V_287 -> V_299 ) ;
} else if ( V_55 -> V_2 -> V_63 == V_66 ) {
if ( memcmp ( V_285 , V_87 , V_88 ) ) {
F_15 ( L_132 ,
V_285 , V_87 ) ;
V_49 = - V_301 ;
goto V_70;
}
V_49 = F_81 ( V_55 , V_302 , & V_290 ) ;
if ( V_49 ) {
F_15 ( L_133 , V_49 ) ;
goto V_70;
} else {
V_287 -> V_293 |= V_303 ;
V_287 -> V_304 . V_305 = V_290 * 5 ;
F_3 ( V_184 , L_134 , V_290 / 2 ) ;
}
if ( F_2 ( V_185 ,
& V_55 -> V_2 -> V_4 ) ) {
memset ( & V_288 , 0 , sizeof( V_288 ) ) ;
V_49 = F_82 ( V_55 , V_306 ,
& V_288 , sizeof( V_288 ) ) ;
if ( V_49 ) {
F_15 ( L_135 , V_49 ) ;
goto V_70;
} else {
V_289 = F_80 ( V_288 . V_210 ) ;
V_287 -> V_293 |= V_307 ;
V_287 -> signal = V_289 ;
F_3 ( V_184 , L_136 , V_289 ) ;
}
}
} else
V_49 = - V_118 ;
V_70:
F_3 ( V_58 , L_11 ) ;
return V_49 ;
}
static T_4
F_83 ( struct V_50 * V_50 , struct V_47 * V_48 ,
bool V_308 , T_4 V_309 )
{
T_4 V_310 ;
T_4 V_49 = 0 ;
struct V_108 * V_109 = F_49 ( V_50 ) ;
struct V_54 * V_55 = F_14 ( V_48 ) ;
F_3 ( V_58 , L_23 ) ;
V_109 -> V_311 = V_308 ;
if ( ! F_1 ( V_55 -> V_2 ) ) {
F_3 ( V_5 , L_137 ) ;
goto V_70;
}
V_310 = V_308 ? V_312 : V_313 ;
F_3 ( V_5 , L_138 , ( V_310 ? L_139 : L_140 ) ) ;
V_49 = F_18 ( V_55 , V_314 , V_310 ) ;
if ( V_49 ) {
if ( V_49 == - V_315 )
F_15 ( L_141 ) ;
else
F_15 ( L_34 , V_49 ) ;
}
V_70:
F_3 ( V_58 , L_11 ) ;
return V_49 ;
}
static T_4
F_84 ( struct V_50 * V_50 , struct V_47 * V_48 ,
const T_2 * V_316 ,
const struct V_317 * V_318 )
{
struct V_54 * V_55 = F_14 ( V_48 ) ;
struct V_319 V_320 ;
T_4 V_290 ;
T_4 V_210 ;
T_4 V_321 ;
T_4 V_322 ;
T_5 V_305 ;
T_4 V_49 = 0 ;
F_3 ( V_58 , L_23 ) ;
if ( ! F_1 ( V_55 -> V_2 ) )
return - V_159 ;
V_49 = F_82 ( V_55 , V_323 ,
& V_320 , sizeof( V_320 ) ) ;
if ( V_49 ) {
F_15 ( L_142 , V_49 ) ;
goto V_70;
}
V_305 = F_85 ( V_318 -> V_324 [ V_23 ] . V_305 & 0xFFFF ) ;
if ( ! V_305 )
V_305 = F_85 ( V_318 -> V_324 [ V_325 ] . V_305 &
0xFFFF ) ;
V_210 = V_326 [ V_305 - 1 ] . V_327 * 100000 ;
if ( V_210 < F_80 ( V_320 . V_140 ) )
V_290 = V_320 . V_328 [ V_210 ] & 0x7f ;
else
V_290 = V_210 / 500000 ;
F_3 ( V_184 , L_143 , V_290 / 2 ) ;
V_321 = F_20 ( V_55 , L_144 , V_290 ) ;
V_322 = F_20 ( V_55 , L_145 , V_290 ) ;
if ( V_321 && V_322 ) {
F_15 ( L_146 , V_321 ,
V_322 ) ;
V_49 = V_321 | V_322 ;
}
V_70:
F_3 ( V_58 , L_11 ) ;
return V_49 ;
}
static T_4 F_86 ( struct V_108 * V_109 ,
struct V_329 * V_330 )
{
struct V_50 * V_50 = F_29 ( V_109 ) ;
struct V_17 * V_331 ;
struct V_332 * V_333 ;
struct V_334 * V_22 ;
T_4 V_49 = 0 ;
T_1 V_202 ;
T_5 V_335 ;
T_1 V_336 ;
T_1 V_337 ;
T_2 * V_338 ;
T_6 V_339 ;
T_4 V_340 ;
if ( F_80 ( V_330 -> V_341 ) > V_342 ) {
F_15 ( L_147 ) ;
return 0 ;
}
V_202 = V_330 -> V_343 ? V_330 -> V_343 :
F_87 ( F_88 ( V_330 -> V_19 ) ) ;
if ( V_202 <= V_180 )
V_22 = V_50 -> V_344 [ V_23 ] ;
else
V_22 = V_50 -> V_344 [ V_325 ] ;
V_335 = F_89 ( V_202 , V_22 -> V_22 ) ;
V_331 = F_90 ( V_50 , V_335 ) ;
V_336 = F_88 ( V_330 -> V_345 ) ;
V_337 = F_88 ( V_330 -> V_346 ) ;
V_338 = ( T_2 * ) V_330 + F_88 ( V_330 -> V_347 ) ;
V_339 = F_80 ( V_330 -> V_348 ) ;
V_340 = ( V_349 ) F_88 ( V_330 -> V_350 ) * 100 ;
F_3 ( V_184 , L_148 , V_330 -> V_351 ) ;
F_3 ( V_184 , L_149 , V_202 , V_335 ) ;
F_3 ( V_184 , L_150 , V_336 ) ;
F_3 ( V_184 , L_151 , V_337 ) ;
F_3 ( V_184 , L_152 , V_340 ) ;
V_333 = F_91 ( V_50 , V_331 , ( const T_2 * ) V_330 -> V_351 ,
0 , V_336 , V_337 , V_338 ,
V_339 , V_340 , V_124 ) ;
if ( ! V_333 )
return - V_125 ;
F_92 ( V_333 ) ;
return V_49 ;
}
static struct V_329 *
F_93 ( struct V_132 * V_352 , struct V_329 * V_333 )
{
if ( V_333 == NULL )
return V_352 -> V_353 ;
return (struct V_329 * ) ( ( unsigned long ) V_333 +
F_80 ( V_333 -> V_341 ) ) ;
}
static T_4 F_94 ( struct V_108 * V_109 )
{
struct V_132 * V_354 ;
struct V_329 * V_330 = NULL ;
T_4 V_49 = 0 ;
int V_83 ;
V_354 = V_109 -> V_354 ;
if ( V_354 -> V_140 != 0 &&
V_354 -> V_127 != V_355 ) {
F_15 ( L_153 ,
V_354 -> V_127 ) ;
return - V_61 ;
}
F_3 ( V_97 , L_154 , V_354 -> V_140 ) ;
for ( V_83 = 0 ; V_83 < V_354 -> V_140 ; V_83 ++ ) {
V_330 = F_93 ( V_354 , V_330 ) ;
V_49 = F_86 ( V_109 , V_330 ) ;
if ( V_49 )
break;
}
return V_49 ;
}
static T_4 F_95 ( struct V_108 * V_109 ,
struct V_47 * V_48 , const T_2 * V_87 )
{
struct V_50 * V_50 = F_29 ( V_109 ) ;
struct V_17 * V_331 ;
struct V_329 * V_330 = NULL ;
struct V_334 * V_22 ;
struct V_332 * V_333 ;
T_2 * V_356 = NULL ;
T_4 V_49 = 0 ;
T_1 V_202 ;
T_5 V_335 ;
T_1 V_336 ;
T_1 V_337 ;
T_2 * V_338 ;
T_6 V_339 ;
T_4 V_340 ;
F_3 ( V_58 , L_23 ) ;
V_356 = F_33 ( V_342 , V_124 ) ;
if ( V_356 == NULL ) {
V_49 = - V_125 ;
goto V_357;
}
* ( V_358 * ) V_356 = F_9 ( V_342 ) ;
V_49 = F_82 ( F_14 ( V_48 ) , V_359 ,
V_356 , V_342 ) ;
if ( V_49 ) {
F_15 ( L_155 , V_49 ) ;
goto V_357;
}
V_330 = (struct V_329 * ) ( V_356 + 4 ) ;
V_202 = V_330 -> V_343 ? V_330 -> V_343 :
F_87 ( F_88 ( V_330 -> V_19 ) ) ;
if ( V_202 <= V_180 )
V_22 = V_50 -> V_344 [ V_23 ] ;
else
V_22 = V_50 -> V_344 [ V_325 ] ;
V_335 = F_89 ( V_202 , V_22 -> V_22 ) ;
V_331 = F_90 ( V_50 , V_335 ) ;
V_336 = F_88 ( V_330 -> V_345 ) ;
V_337 = F_88 ( V_330 -> V_346 ) ;
V_338 = ( T_2 * ) V_330 + F_88 ( V_330 -> V_347 ) ;
V_339 = F_80 ( V_330 -> V_348 ) ;
V_340 = ( V_349 ) F_88 ( V_330 -> V_350 ) * 100 ;
F_3 ( V_184 , L_156 , V_202 , V_335 ) ;
F_3 ( V_184 , L_157 , V_336 ) ;
F_3 ( V_184 , L_62 , V_337 ) ;
F_3 ( V_184 , L_158 , V_340 ) ;
V_333 = F_91 ( V_50 , V_331 , V_87 ,
0 , V_336 , V_337 ,
V_338 , V_339 , V_340 , V_124 ) ;
if ( ! V_333 ) {
V_49 = - V_125 ;
goto V_357;
}
F_92 ( V_333 ) ;
V_357:
F_36 ( V_356 ) ;
F_3 ( V_58 , L_11 ) ;
return V_49 ;
}
static bool F_96 ( struct V_1 * V_2 )
{
return V_2 -> V_63 == V_64 ;
}
static struct V_360 * F_97 ( void * V_356 , int V_141 , T_3 V_35 )
{
struct V_360 * V_361 ;
int V_362 ;
V_361 = (struct V_360 * ) V_356 ;
V_362 = V_141 ;
while ( V_362 >= V_363 ) {
int V_39 = V_361 -> V_39 ;
if ( ( V_361 -> V_364 == V_35 ) && ( V_362 >= ( V_39 + V_363 ) ) )
return V_361 ;
V_361 = (struct V_360 * ) ( ( T_2 * ) V_361 + ( V_39 + V_363 ) ) ;
V_362 -= ( V_39 + V_363 ) ;
}
return NULL ;
}
static bool
F_98 ( T_2 * V_194 , T_2 * * V_365 , T_5 * V_366 ,
T_2 * V_367 , T_5 V_368 , T_2 type )
{
if ( V_194 [ V_369 ] >= V_368 + 1 &&
! memcmp ( & V_194 [ V_370 ] , V_367 , V_368 ) &&
type == V_194 [ V_370 + V_368 ] ) {
return true ;
}
if ( V_365 == NULL )
return false ;
V_194 += V_194 [ V_369 ] + V_363 ;
* V_366 -= ( int ) ( V_194 - * V_365 ) ;
* V_365 = V_194 ;
return false ;
}
static struct V_371 *
F_99 ( T_2 * V_372 , T_5 V_39 )
{
struct V_360 * V_194 ;
while ( ( V_194 = F_97 ( V_372 , V_39 , V_373 ) ) ) {
if ( F_98 ( ( T_2 * ) V_194 , & V_372 , & V_39 ,
V_374 , V_375 , V_376 ) )
return (struct V_371 * ) V_194 ;
}
return NULL ;
}
static T_4 F_100 ( struct V_108 * V_109 )
{
struct V_47 * V_48 = F_50 ( V_109 ) ;
struct V_175 * V_188 = F_57 ( V_48 ) ;
struct V_54 * V_55 = F_14 ( V_48 ) ;
struct V_329 * V_330 ;
struct V_123 * V_105 ;
struct V_360 * V_377 ;
T_1 V_196 ;
T_2 V_378 ;
T_6 V_195 ;
T_2 * V_194 ;
T_4 V_49 = 0 ;
F_3 ( V_58 , L_23 ) ;
if ( F_96 ( V_55 -> V_2 ) )
return V_49 ;
V_105 = & V_188 -> V_105 ;
* ( V_358 * ) V_109 -> V_379 = F_9 ( V_380 ) ;
V_49 = F_82 ( V_55 , V_359 ,
V_109 -> V_379 , V_380 ) ;
if ( V_49 ) {
F_15 ( L_159 , V_49 ) ;
goto V_381;
}
V_330 = (struct V_329 * ) ( V_109 -> V_379 + 4 ) ;
V_49 = F_86 ( V_109 , V_330 ) ;
if ( V_49 )
goto V_381;
V_194 = ( ( T_2 * ) V_330 ) + F_88 ( V_330 -> V_347 ) ;
V_195 = F_80 ( V_330 -> V_348 ) ;
V_196 = F_88 ( V_330 -> V_346 ) ;
V_377 = F_97 ( V_194 , V_195 , V_382 ) ;
if ( V_377 )
V_378 = V_377 -> V_45 [ 1 ] ;
else {
T_5 V_383 ;
V_49 = F_61 ( V_55 , L_160 , & V_383 ) ;
if ( V_49 ) {
F_15 ( L_161 , V_49 ) ;
goto V_381;
}
V_378 = ( T_2 ) V_383 ;
}
V_381:
F_3 ( V_58 , L_121 ) ;
return V_49 ;
}
static void F_101 ( struct V_108 * V_109 )
{
struct V_134 * V_384 = & V_109 -> V_134 ;
F_17 ( V_151 , & V_109 -> V_117 ) ;
if ( V_109 -> V_112 ) {
V_384 -> V_135 = V_385 ;
F_24 ( V_109 , V_384 -> V_48 , true , true ) ;
}
F_42 ( V_116 , & V_109 -> V_117 ) ;
F_42 ( V_151 , & V_109 -> V_117 ) ;
}
static void F_102 ( struct V_386 * V_387 )
{
struct V_108 * V_109 =
F_44 ( V_387 , struct V_108 ,
V_388 ) ;
F_24 ( V_109 ,
V_109 -> V_134 . V_48 , true , true ) ;
}
static void F_103 ( unsigned long V_45 )
{
struct V_108 * V_109 =
(struct V_108 * ) V_45 ;
if ( V_109 -> V_112 ) {
F_15 ( L_162 ) ;
F_104 ( & V_109 -> V_388 ) ;
}
}
static T_4
F_105 ( struct V_329 * V_333 ,
struct V_329 * V_353 )
{
if ( ! memcmp ( & V_353 -> V_351 , & V_333 -> V_351 , V_88 ) &&
( F_106 ( F_88 ( V_353 -> V_19 ) ) ==
F_106 ( F_88 ( V_333 -> V_19 ) ) ) &&
V_353 -> V_101 == V_333 -> V_101 &&
! memcmp ( V_353 -> V_104 , V_333 -> V_104 , V_353 -> V_101 ) ) {
if ( ( V_333 -> V_26 & V_389 ) ==
( V_353 -> V_26 & V_389 ) ) {
V_349 V_390 = F_88 ( V_333 -> V_350 ) ;
V_349 V_391 = F_88 ( V_353 -> V_350 ) ;
if ( V_391 > V_390 )
V_333 -> V_350 = V_353 -> V_350 ;
} else if ( ( V_333 -> V_26 & V_389 ) &&
( V_353 -> V_26 & V_389 ) == 0 ) {
V_333 -> V_350 = V_353 -> V_350 ;
V_333 -> V_26 |= V_389 ;
}
return 1 ;
}
return 0 ;
}
static T_4
F_107 ( struct V_54 * V_55 ,
const struct V_392 * V_393 , void * V_45 )
{
struct V_108 * V_109 = V_55 -> V_394 -> V_395 ;
struct V_47 * V_48 = V_55 -> V_48 ;
T_4 V_396 ;
T_4 V_49 = 0 ;
struct V_397 * V_398 ;
struct V_329 * V_353 ;
struct V_329 * V_333 = NULL ;
T_5 V_399 ;
struct V_132 * V_352 ;
T_5 V_83 ;
bool V_110 ;
V_396 = V_393 -> V_396 ;
if ( ! V_48 || ! F_2 ( V_116 , & V_109 -> V_117 ) ) {
F_15 ( L_163 , V_48 ,
! F_2 ( V_116 , & V_109 -> V_117 ) ) ;
return - V_118 ;
}
if ( V_396 == V_400 ) {
F_3 ( V_97 , L_164 ) ;
V_398 = (struct V_397 * ) V_45 ;
if ( ! V_398 ) {
F_15 ( L_165 ) ;
goto exit;
}
if ( ! V_109 -> V_112 ) {
F_3 ( V_97 , L_166 ) ;
goto exit;
}
if ( F_88 ( V_398 -> V_401 ) != 1 ) {
F_15 ( L_167 ,
V_398 -> V_401 ) ;
goto exit;
}
V_353 = & V_398 -> V_353 ;
V_399 = F_80 ( V_353 -> V_341 ) ;
if ( V_399 != ( F_80 ( V_398 -> V_141 ) -
V_142 ) ) {
F_15 ( L_168 ,
V_399 ) ;
goto exit;
}
if ( ! ( F_29 ( V_109 ) -> V_402 &
F_108 ( V_62 ) ) ) {
if ( F_88 ( V_353 -> V_345 ) &
V_403 ) {
F_15 ( L_169 ) ;
goto exit;
}
}
V_352 = (struct V_132 * )
V_109 -> V_134 . V_139 ;
if ( V_399 > V_404 - V_352 -> V_141 ) {
F_15 ( L_170 ) ;
goto exit;
}
for ( V_83 = 0 ; V_83 < V_352 -> V_140 ; V_83 ++ ) {
V_333 = V_333 ? (struct V_329 * )
( ( unsigned char * ) V_333 +
F_80 ( V_333 -> V_341 ) ) : V_352 -> V_353 ;
if ( F_105 ( V_333 , V_353 ) )
goto exit;
}
memcpy ( & ( V_109 -> V_134 . V_139 [ V_352 -> V_141 ] ) ,
V_353 , V_399 ) ;
V_352 -> V_127 = F_80 ( V_353 -> V_127 ) ;
V_352 -> V_141 += V_399 ;
V_352 -> V_140 ++ ;
} else {
V_109 -> V_134 . V_135 = V_385 ;
if ( V_109 -> V_112 ) {
V_109 -> V_354 = (struct V_132 * )
V_109 -> V_134 . V_139 ;
F_94 ( V_109 ) ;
V_110 = V_396 != V_405 ;
F_24 ( V_109 , V_48 , V_110 ,
false ) ;
} else
F_15 ( L_171 , V_396 ) ;
}
exit:
return V_49 ;
}
static void F_109 ( struct V_108 * V_109 )
{
F_110 ( V_109 -> V_406 , V_407 ,
F_107 ) ;
V_109 -> V_134 . V_135 = V_385 ;
F_111 ( & V_109 -> V_113 ) ;
V_109 -> V_113 . V_45 = ( unsigned long ) V_109 ;
V_109 -> V_113 . V_408 = F_103 ;
F_112 ( & V_109 -> V_388 ,
F_102 ) ;
}
static T_7 void F_113 ( T_5 V_409 )
{
if ( V_409 < 1000 / V_155 ) {
F_114 () ;
F_115 ( V_409 ) ;
} else {
F_116 ( V_409 ) ;
}
}
static T_4 F_117 ( struct V_50 * V_50 )
{
F_3 ( V_58 , L_23 ) ;
return 0 ;
}
static T_4 F_118 ( struct V_50 * V_50 ,
struct V_410 * V_411 )
{
struct V_108 * V_109 = F_49 ( V_50 ) ;
struct V_47 * V_48 = F_50 ( V_109 ) ;
struct V_1 * V_2 ;
F_3 ( V_58 , L_23 ) ;
V_2 = ( (struct V_54 * ) F_14 ( V_48 ) ) -> V_2 ;
if ( ! F_1 ( V_2 ) )
goto exit;
F_119 (vif, &cfg->vif_list, list) {
if ( ! F_2 ( V_3 , & V_2 -> V_4 ) )
continue;
F_53 ( V_2 ) ;
F_113 ( 500 ) ;
}
if ( F_2 ( V_116 , & V_109 -> V_117 ) )
F_101 ( V_109 ) ;
F_19 ( V_48 , 1 ) ;
exit:
F_3 ( V_58 , L_11 ) ;
V_109 -> V_117 = 0 ;
return 0 ;
}
static T_8 T_4
F_120 ( struct V_47 * V_48 ,
struct V_412 * V_413 , T_4 V_49 )
{
int V_83 , V_414 ;
int V_415 ;
V_415 = F_80 ( V_413 -> V_416 . V_417 ) ;
F_3 ( V_184 , L_172 , V_415 ) ;
for ( V_83 = 0 ; V_83 < V_415 ; V_83 ++ ) {
F_3 ( V_184 , L_173 , V_83 ,
& V_413 -> V_416 . V_418 [ V_83 ] . V_351 ) ;
for ( V_414 = 0 ; V_414 < V_419 ; V_414 ++ )
F_3 ( V_184 , L_174 ,
V_413 -> V_416 . V_418 [ V_83 ] . V_420 [ V_414 ] ) ;
}
if ( ! V_49 )
F_35 ( F_14 ( V_48 ) , L_175 ,
( char * ) V_413 , sizeof( * V_413 ) ) ;
return V_49 ;
}
static T_4
F_121 ( struct V_50 * V_50 , struct V_47 * V_48 ,
struct V_421 * V_422 )
{
struct V_108 * V_109 = F_49 ( V_50 ) ;
struct V_54 * V_55 = F_14 ( V_48 ) ;
struct V_423 * V_416 = & V_109 -> V_413 -> V_416 ;
T_4 V_49 = 0 ;
int V_83 ;
int V_415 ;
F_3 ( V_58 , L_23 ) ;
if ( ! F_1 ( V_55 -> V_2 ) )
return - V_159 ;
V_415 = F_80 ( V_416 -> V_417 ) ;
for ( V_83 = 0 ; V_83 < V_415 ; V_83 ++ )
if ( ! memcmp ( V_422 -> V_87 , V_416 -> V_418 [ V_83 ] . V_351 , V_88 ) )
break;
if ( V_83 < V_424 ) {
memcpy ( V_416 -> V_418 [ V_83 ] . V_351 , V_422 -> V_87 , V_88 ) ;
memcpy ( V_416 -> V_418 [ V_83 ] . V_420 , V_422 -> V_418 , V_419 ) ;
if ( V_83 == V_415 ) {
V_415 ++ ;
V_416 -> V_417 = F_9 ( V_415 ) ;
}
} else
V_49 = - V_69 ;
F_3 ( V_184 , L_176 ,
V_416 -> V_418 [ V_415 ] . V_351 ) ;
for ( V_83 = 0 ; V_83 < V_419 ; V_83 ++ )
F_3 ( V_184 , L_174 , V_416 -> V_418 [ V_415 ] . V_420 [ V_83 ] ) ;
V_49 = F_120 ( V_48 , V_109 -> V_413 , V_49 ) ;
F_3 ( V_58 , L_11 ) ;
return V_49 ;
}
static T_4
F_122 ( struct V_50 * V_50 , struct V_47 * V_48 ,
struct V_421 * V_422 )
{
struct V_108 * V_109 = F_49 ( V_50 ) ;
struct V_54 * V_55 = F_14 ( V_48 ) ;
struct V_423 V_418 ;
T_4 V_49 = 0 ;
int V_83 , V_415 ;
F_3 ( V_58 , L_23 ) ;
if ( ! F_1 ( V_55 -> V_2 ) )
return - V_159 ;
memcpy ( & V_418 . V_418 [ 0 ] . V_351 , V_422 -> V_87 , V_88 ) ;
memcpy ( & V_418 . V_418 [ 0 ] . V_420 , V_422 -> V_418 , V_419 ) ;
F_3 ( V_184 , L_177 ,
& V_418 . V_418 [ 0 ] . V_351 ) ;
for ( V_83 = 0 ; V_83 < V_419 ; V_83 ++ )
F_3 ( V_184 , L_174 , V_418 . V_418 [ 0 ] . V_420 [ V_83 ] ) ;
V_415 = F_80 ( V_109 -> V_413 -> V_416 . V_417 ) ;
for ( V_83 = 0 ; V_83 < V_415 ; V_83 ++ )
if ( ! memcmp
( V_422 -> V_87 , & V_109 -> V_413 -> V_416 . V_418 [ V_83 ] . V_351 ,
V_88 ) )
break;
if ( ( V_415 > 0 )
&& ( V_83 < V_415 ) ) {
memset ( & V_109 -> V_413 -> V_416 . V_418 [ V_83 ] , 0 ,
sizeof( struct V_418 ) ) ;
for (; V_83 < ( V_415 - 1 ) ; V_83 ++ ) {
memcpy ( & V_109 -> V_413 -> V_416 . V_418 [ V_83 ] . V_351 ,
& V_109 -> V_413 -> V_416 . V_418 [ V_83 + 1 ] . V_351 ,
V_88 ) ;
memcpy ( & V_109 -> V_413 -> V_416 . V_418 [ V_83 ] . V_420 ,
& V_109 -> V_413 -> V_416 . V_418 [ V_83 + 1 ] . V_420 ,
V_419 ) ;
}
V_109 -> V_413 -> V_416 . V_417 = F_9 ( V_415 - 1 ) ;
} else
V_49 = - V_69 ;
V_49 = F_120 ( V_48 , V_109 -> V_413 , V_49 ) ;
F_3 ( V_58 , L_11 ) ;
return V_49 ;
}
static T_4
F_123 ( struct V_50 * V_50 , struct V_47 * V_48 )
{
struct V_108 * V_109 = F_49 ( V_50 ) ;
struct V_54 * V_55 = F_14 ( V_48 ) ;
T_4 V_49 = 0 ;
F_3 ( V_58 , L_23 ) ;
if ( ! F_1 ( V_55 -> V_2 ) )
return - V_159 ;
memset ( V_109 -> V_413 , 0 , sizeof( * V_109 -> V_413 ) ) ;
V_49 = F_120 ( V_48 , V_109 -> V_413 , V_49 ) ;
F_3 ( V_58 , L_11 ) ;
return V_49 ;
}
static T_4
F_124 ( struct V_54 * V_55 ,
const struct V_392 * V_393 , void * V_45 )
{
struct V_108 * V_109 = V_55 -> V_394 -> V_395 ;
struct V_47 * V_48 = V_55 -> V_48 ;
struct V_425 * V_426 , * V_427 ;
struct V_79 * V_80 = NULL ;
struct V_144 * V_105 = NULL ;
struct V_17 * V_202 = NULL ;
struct V_50 * V_50 = F_29 ( V_109 ) ;
int V_49 = 0 ;
int V_428 = 0 ;
int V_22 = 0 ;
struct V_429 * V_430 ;
T_5 V_431 ;
T_5 V_396 ;
F_3 ( V_97 , L_23 ) ;
if ( V_393 -> V_432 == V_433 ) {
F_3 ( V_97 , L_178 ) ;
return 0 ;
}
V_430 = (struct V_429 * ) V_45 ;
V_431 = F_80 ( V_430 -> V_140 ) ;
V_396 = F_80 ( V_430 -> V_396 ) ;
F_125 ( V_396 != V_434 ) ;
F_3 ( V_97 , L_179 , V_431 ) ;
if ( V_431 > 0 ) {
int V_83 ;
V_80 = F_33 ( sizeof( * V_80 ) , V_124 ) ;
V_105 = F_126 ( V_431 , sizeof( * V_105 ) , V_124 ) ;
V_202 = F_126 ( V_431 , sizeof( * V_202 ) , V_124 ) ;
if ( ! V_80 || ! V_105 || ! V_202 ) {
V_49 = - V_125 ;
goto V_435;
}
V_80 -> V_50 = V_50 ;
V_45 += sizeof( struct V_429 ) ;
V_427 = (struct V_425 * ) V_45 ;
for ( V_83 = 0 ; V_83 < V_431 ; V_83 ++ ) {
V_426 = & V_427 [ V_83 ] ;
if ( ! V_426 ) {
F_15 ( L_180 ,
V_83 ) ;
V_49 = - V_69 ;
goto V_435;
}
F_3 ( V_97 , L_181 ,
V_426 -> V_104 , V_426 -> V_202 ) ;
memcpy ( V_105 [ V_83 ] . V_105 , V_426 -> V_104 , V_426 -> V_101 ) ;
V_105 [ V_83 ] . V_103 = V_426 -> V_101 ;
V_80 -> V_81 ++ ;
V_428 = V_426 -> V_202 ;
if ( V_428 <= V_180 )
V_22 = V_436 ;
else
V_22 = V_437 ;
V_202 [ V_83 ] . V_20 =
F_89 ( V_428 ,
V_22 ) ;
V_202 [ V_83 ] . V_22 = V_22 ;
V_202 [ V_83 ] . V_26 |= V_27 ;
V_80 -> V_98 [ V_83 ] = & V_202 [ V_83 ] ;
V_80 -> V_82 ++ ;
}
if ( V_80 -> V_81 )
V_80 -> V_102 = & V_105 [ 0 ] ;
if ( F_2 ( V_116 , & V_109 -> V_117 ) ) {
F_101 ( V_109 ) ;
}
F_17 ( V_116 , & V_109 -> V_117 ) ;
V_49 = F_37 ( V_109 , V_50 , V_48 , V_80 ) ;
if ( V_49 ) {
F_42 ( V_116 , & V_109 -> V_117 ) ;
goto V_435;
}
V_109 -> V_115 = true ;
V_109 -> V_112 = V_80 ;
} else {
F_15 ( L_182 ) ;
goto V_435;
}
F_36 ( V_105 ) ;
F_36 ( V_202 ) ;
F_36 ( V_80 ) ;
return 0 ;
V_435:
F_36 ( V_105 ) ;
F_36 ( V_202 ) ;
F_36 ( V_80 ) ;
F_127 ( V_50 ) ;
return V_49 ;
}
static int F_128 ( struct V_47 * V_48 )
{
int V_438 ;
V_438 = F_20 ( F_14 ( V_48 ) , L_183 , 0 ) ;
if ( V_438 == 0 ) {
V_438 = F_35 ( F_14 ( V_48 ) , L_184 ,
NULL , 0 ) ;
}
if ( V_438 < 0 )
F_15 ( L_185 , V_438 ) ;
return V_438 ;
}
static int F_129 ( struct V_47 * V_48 )
{
struct V_439 V_440 ;
memset ( & V_440 , 0 , sizeof( V_440 ) ) ;
V_440 . V_127 = F_9 ( V_441 ) ;
V_440 . V_26 = F_10 ( 1 << V_442 ) ;
V_440 . V_443 = V_444 ;
V_440 . exp = V_445 ;
V_440 . V_446 = F_9 ( V_447 ) ;
return F_35 ( F_14 ( V_48 ) , L_186 ,
& V_440 , sizeof( V_440 ) ) ;
}
static int
F_130 ( struct V_50 * V_50 ,
struct V_47 * V_48 ,
struct V_448 * V_80 )
{
struct V_54 * V_55 = F_14 ( V_48 ) ;
struct V_108 * V_109 = F_131 ( V_50 ) ;
struct V_449 V_450 ;
int V_83 ;
int V_438 = 0 ;
F_3 ( V_97 , L_187 ,
V_80 -> V_451 , V_80 -> V_81 ) ;
if ( F_2 ( V_116 , & V_109 -> V_117 ) ) {
F_15 ( L_36 , V_109 -> V_117 ) ;
return - V_73 ;
}
if ( ! V_80 || ! V_80 -> V_81 || ! V_80 -> V_451 ) {
F_15 ( L_188 ,
V_80 ? V_80 -> V_81 : 0 ) ;
return - V_69 ;
}
if ( V_80 -> V_81 > 0 ) {
for ( V_83 = 0 ; V_83 < V_80 -> V_81 ; V_83 ++ ) {
F_3 ( V_97 , L_189 ,
V_80 -> V_102 [ V_83 ] . V_105 ) ;
}
}
if ( V_80 -> V_451 > 0 ) {
V_438 = F_128 ( V_48 ) ;
if ( V_438 < 0 ) {
F_15 ( L_190 , V_438 ) ;
return V_438 ;
}
V_438 = F_129 ( V_48 ) ;
if ( V_438 < 0 ) {
F_15 ( L_191 , V_438 ) ;
return - V_69 ;
}
for ( V_83 = 0 ; V_83 < V_80 -> V_451 ; V_83 ++ ) {
struct V_144 * V_105 ;
T_5 V_103 ;
V_105 = & V_80 -> V_452 [ V_83 ] . V_105 ;
V_103 = V_105 -> V_103 ;
if ( ! V_103 ) {
F_15 ( L_192 ) ;
continue;
}
V_450 . V_453 = F_9 ( V_454 ) ;
V_450 . V_242 = F_9 ( V_455 ) ;
V_450 . V_189 = F_9 ( 0 ) ;
V_450 . V_56 = F_9 ( 1 ) ;
V_450 . V_26 = F_9 ( 1 << V_456 ) ;
V_450 . V_105 . V_101 = F_9 ( V_103 ) ;
memcpy ( V_450 . V_105 . V_104 , V_105 -> V_105 , V_103 ) ;
V_438 = F_35 ( V_55 , L_193 , & V_450 ,
sizeof( V_450 ) ) ;
F_3 ( V_97 , L_194 ,
V_438 == 0 ? L_195 : L_196 , V_105 -> V_105 ) ;
}
if ( F_20 ( V_55 , L_183 , 1 ) < 0 ) {
F_15 ( L_197 , V_438 ) ;
return - V_69 ;
}
} else {
return - V_69 ;
}
return 0 ;
}
static int F_132 ( struct V_50 * V_50 ,
struct V_47 * V_48 )
{
struct V_108 * V_109 = F_49 ( V_50 ) ;
F_3 ( V_97 , L_198 ) ;
F_128 ( V_48 ) ;
if ( V_109 -> V_115 )
F_24 ( V_109 , V_48 , true , true ) ;
return 0 ;
}
static int F_133 ( struct V_50 * V_50 , void * V_45 , int V_39 )
{
struct V_108 * V_109 = F_49 ( V_50 ) ;
struct V_47 * V_48 = F_50 ( V_109 ) ;
struct V_457 * V_458 = V_45 ;
struct V_459 * V_460 ;
int V_438 ;
F_3 ( V_58 , L_199 , V_458 -> V_164 , V_458 -> V_461 ,
V_458 -> V_356 , V_458 -> V_39 ) ;
if ( V_458 -> V_461 )
V_438 = F_27 ( F_14 ( V_48 ) , V_458 -> V_164 ,
V_458 -> V_356 , V_458 -> V_39 ) ;
else
V_438 = F_82 ( F_14 ( V_48 ) , V_458 -> V_164 ,
V_458 -> V_356 , V_458 -> V_39 ) ;
if ( V_438 == 0 ) {
V_460 = F_134 ( V_50 , sizeof( * V_458 ) ) ;
F_135 ( V_460 , V_462 , sizeof( * V_458 ) , V_458 ) ;
V_438 = F_136 ( V_460 ) ;
}
return V_438 ;
}
static T_4 F_137 ( struct V_47 * V_48 , T_4 V_463 )
{
struct V_54 * V_55 = F_14 ( V_48 ) ;
T_4 V_49 ;
V_49 = F_63 ( V_55 , L_81 , 0 ) ;
if ( V_49 < 0 ) {
F_15 ( L_200 , V_49 ) ;
return V_49 ;
}
V_49 = F_63 ( V_55 , L_68 , 0 ) ;
if ( V_49 < 0 ) {
F_15 ( L_201 , V_49 ) ;
return V_49 ;
}
V_49 = F_63 ( V_55 , L_74 , V_464 ) ;
if ( V_49 < 0 ) {
F_15 ( L_202 , V_49 ) ;
return V_49 ;
}
return 0 ;
}
static bool F_138 ( T_2 * V_367 , bool V_465 )
{
if ( V_465 )
return ( memcmp ( V_367 , V_466 , V_375 ) == 0 ) ;
return ( memcmp ( V_367 , V_374 , V_375 ) == 0 ) ;
}
static T_4
F_139 ( struct V_47 * V_48 , struct V_371 * V_467 ,
bool V_465 )
{
struct V_54 * V_55 = F_14 ( V_48 ) ;
T_5 V_453 = 0 ;
T_1 V_140 ;
T_4 V_49 = 0 ;
T_4 V_39 = 0 ;
T_5 V_83 ;
T_5 V_189 ;
T_5 V_225 = 0 ;
T_5 V_226 = 0 ;
T_5 V_242 = 0 ;
T_5 V_13 ;
T_2 * V_45 ;
T_1 V_468 ;
T_5 V_469 ;
F_3 ( V_58 , L_23 ) ;
if ( V_467 == NULL )
goto exit;
V_39 = V_467 -> V_39 + V_363 ;
V_45 = ( T_2 * ) V_467 ;
V_13 = V_363 ;
if ( ! V_465 )
V_13 += V_470 ;
else
V_13 += V_471 ;
if ( V_13 + V_472 > V_39 ) {
V_49 = - V_69 ;
F_15 ( L_203 ) ;
goto exit;
}
if ( ! F_138 ( & V_45 [ V_13 ] , V_465 ) ) {
V_49 = - V_69 ;
F_15 ( L_204 ) ;
goto exit;
}
V_13 += V_375 ;
switch ( V_45 [ V_13 ] ) {
case V_473 :
V_226 = 0 ;
break;
case V_474 :
case V_475 :
V_226 = V_199 ;
break;
case V_476 :
V_226 = V_232 ;
break;
case V_477 :
V_226 = V_234 ;
break;
default:
V_49 = - V_69 ;
F_15 ( L_205 ) ;
goto exit;
}
V_13 ++ ;
V_140 = V_45 [ V_13 ] + ( V_45 [ V_13 + 1 ] << 8 ) ;
V_13 += V_478 ;
if ( V_13 + ( V_472 * V_140 ) > V_39 ) {
V_49 = - V_69 ;
F_15 ( L_206 ) ;
goto exit;
}
for ( V_83 = 0 ; V_83 < V_140 ; V_83 ++ ) {
if ( ! F_138 ( & V_45 [ V_13 ] , V_465 ) ) {
V_49 = - V_69 ;
F_15 ( L_204 ) ;
goto exit;
}
V_13 += V_375 ;
switch ( V_45 [ V_13 ] ) {
case V_473 :
break;
case V_474 :
case V_475 :
V_225 |= V_199 ;
break;
case V_476 :
V_225 |= V_232 ;
break;
case V_477 :
V_225 |= V_234 ;
break;
default:
F_15 ( L_207 ) ;
}
V_13 ++ ;
}
V_140 = V_45 [ V_13 ] + ( V_45 [ V_13 + 1 ] << 8 ) ;
V_13 += V_478 ;
if ( V_13 + ( V_472 * V_140 ) > V_39 ) {
V_49 = - V_69 ;
F_15 ( L_208 ) ;
goto exit;
}
for ( V_83 = 0 ; V_83 < V_140 ; V_83 ++ ) {
if ( ! F_138 ( & V_45 [ V_13 ] , V_465 ) ) {
V_49 = - V_69 ;
F_15 ( L_204 ) ;
goto exit;
}
V_13 += V_375 ;
switch ( V_45 [ V_13 ] ) {
case V_479 :
F_3 ( V_58 , L_209 ) ;
V_242 |= V_464 ;
break;
case V_480 :
F_3 ( V_58 , L_210 ) ;
V_465 ? ( V_242 |= V_218 ) :
( V_242 |= V_215 ) ;
break;
case V_481 :
F_3 ( V_58 , L_211 ) ;
V_465 ? ( V_242 |= V_217 ) :
( V_242 |= V_214 ) ;
break;
default:
F_15 ( L_212 ) ;
}
V_13 ++ ;
}
if ( V_465 ) {
V_469 = 1 ;
if ( ( V_13 + V_482 ) <= V_39 ) {
V_468 = V_45 [ V_13 ] + ( V_45 [ V_13 + 1 ] << 8 ) ;
if ( V_468 & V_483 )
V_469 = 0 ;
}
V_49 = F_63 ( V_55 , L_213 ,
V_469 ) ;
if ( V_49 < 0 ) {
F_15 ( L_214 , V_49 ) ;
goto exit;
}
}
V_189 = ( V_225 | V_226 | V_284 ) ;
V_49 = F_63 ( V_55 , L_81 , V_453 ) ;
if ( V_49 < 0 ) {
F_15 ( L_200 , V_49 ) ;
goto exit;
}
V_49 = F_63 ( V_55 , L_68 , V_189 ) ;
if ( V_49 < 0 ) {
F_15 ( L_201 , V_49 ) ;
goto exit;
}
V_49 = F_63 ( V_55 , L_74 , V_242 ) ;
if ( V_49 < 0 ) {
F_15 ( L_202 , V_49 ) ;
goto exit;
}
exit:
return V_49 ;
}
static T_4
F_140 ( const T_2 * V_484 , T_5 V_485 ,
struct V_486 * V_487 )
{
T_4 V_49 = 0 ;
struct V_371 * V_488 ;
struct V_360 * V_194 ;
struct V_489 * V_490 ;
T_4 V_491 ;
V_491 = ( T_4 ) V_485 ;
memset ( V_487 , 0 , sizeof( * V_487 ) ) ;
V_194 = (struct V_360 * ) V_484 ;
while ( V_194 ) {
if ( V_194 -> V_364 != V_373 )
goto V_492;
V_488 = (struct V_371 * ) V_194 ;
if ( V_488 -> V_39 < ( V_470 - V_363 + 1 ) ) {
F_15 ( L_215 ,
V_488 -> V_39 ) ;
goto V_492;
}
if ( ! memcmp ( V_488 -> V_367 , ( T_2 * ) V_374 , V_375 ) &&
( ( V_488 -> V_493 == V_376 ) ||
( V_488 -> V_493 == V_494 ) ) ) {
F_3 ( V_58 , L_216 ) ;
goto V_492;
}
V_490 = & V_487 -> V_495 [ V_487 -> V_140 ] ;
V_490 -> V_496 = ( char * ) V_488 ;
V_490 -> V_195 = V_488 -> V_39 + V_363 ;
memcpy ( & V_490 -> V_488 , V_488 , sizeof( * V_488 ) ) ;
V_487 -> V_140 ++ ;
F_3 ( V_58 , L_217 ,
V_490 -> V_488 . V_367 [ 0 ] ,
V_490 -> V_488 . V_367 [ 1 ] ,
V_490 -> V_488 . V_367 [ 2 ] ,
V_490 -> V_488 . V_493 ) ;
if ( V_487 -> V_140 >= V_497 )
break;
V_492:
V_491 -= ( V_194 -> V_39 + V_363 ) ;
if ( V_491 <= V_363 )
V_194 = NULL ;
else
V_194 = (struct V_360 * ) ( ( ( T_2 * ) V_194 ) + V_194 -> V_39 +
V_363 ) ;
}
return V_49 ;
}
static T_5
F_141 ( T_2 * V_498 , T_4 V_499 , T_2 * V_496 , T_5 V_195 , T_9 * V_500 )
{
V_358 V_501 ;
V_358 V_502 ;
strncpy ( V_498 , V_500 , V_503 - 1 ) ;
V_498 [ V_503 - 1 ] = '\0' ;
V_501 = F_9 ( 1 ) ;
memcpy ( & V_498 [ V_504 ] , & V_501 , sizeof( V_501 ) ) ;
V_502 = F_9 ( V_499 ) ;
memcpy ( & V_498 [ V_505 ] , & V_502 , sizeof( V_502 ) ) ;
memcpy ( & V_498 [ V_506 ] , V_496 , V_195 ) ;
return V_195 + V_507 ;
}
static
T_4 F_142 ( struct V_1 * V_2 , T_4 V_499 ,
const T_2 * V_484 , T_5 V_485 )
{
struct V_54 * V_55 ;
struct V_508 * V_509 ;
T_4 V_49 = 0 ;
T_2 * V_510 ;
T_2 * V_511 ;
T_2 * V_512 = NULL ;
int V_513 ;
T_5 * V_514 ;
T_5 V_515 = 0 ;
T_5 V_516 = 0 ;
T_5 V_517 = 0 ;
struct V_486 V_518 ;
struct V_486 V_519 ;
struct V_489 * V_520 ;
T_4 V_83 ;
T_2 * V_84 ;
int V_521 ;
if ( ! V_2 )
return - V_315 ;
V_55 = V_2 -> V_55 ;
V_509 = & V_2 -> V_509 ;
F_3 ( V_58 , L_218 , V_55 -> V_463 , V_499 ) ;
V_510 = F_33 ( V_380 , V_124 ) ;
if ( ! V_510 )
return - V_125 ;
V_511 = V_510 ;
if ( V_55 -> V_2 -> V_63 == V_68 ) {
switch ( V_499 ) {
case V_522 :
V_512 = V_509 -> V_523 ;
V_514 = & V_509 -> V_524 ;
V_513 = sizeof( V_509 -> V_523 ) ;
break;
case V_525 :
V_512 = V_509 -> V_526 ;
V_514 = & V_509 -> V_527 ;
V_513 = sizeof( V_509 -> V_526 ) ;
break;
default:
V_49 = - V_118 ;
F_15 ( L_219 ) ;
goto exit;
}
} else {
V_49 = - V_118 ;
F_15 ( L_219 ) ;
goto exit;
}
if ( V_485 > V_513 ) {
V_49 = - V_125 ;
F_15 ( L_220 ) ;
goto exit;
}
if ( V_484 && V_485 && V_511 ) {
V_84 = V_511 ;
F_140 ( V_484 , V_485 , & V_519 ) ;
for ( V_83 = 0 ; V_83 < V_519 . V_140 ; V_83 ++ ) {
V_520 = & V_519 . V_495 [ V_83 ] ;
memcpy ( V_84 + V_517 , V_520 -> V_496 ,
V_520 -> V_195 ) ;
V_517 += V_520 -> V_195 ;
}
}
if ( V_512 && * V_514 ) {
if ( V_517 && ( V_517 == * V_514 ) &&
( memcmp ( V_512 , V_511 ,
V_517 ) == 0 ) ) {
F_3 ( V_58 , L_221 ) ;
goto exit;
}
F_140 ( V_512 , * V_514 , & V_518 ) ;
for ( V_83 = 0 ; V_83 < V_518 . V_140 ; V_83 ++ ) {
V_520 = & V_518 . V_495 [ V_83 ] ;
F_3 ( V_58 , L_222 ,
V_520 -> V_488 . V_364 ,
V_520 -> V_488 . V_39 ,
V_520 -> V_488 . V_367 [ 0 ] ,
V_520 -> V_488 . V_367 [ 1 ] ,
V_520 -> V_488 . V_367 [ 2 ] ) ;
V_515 = F_141 ( V_511 , V_499 ,
V_520 -> V_496 ,
V_520 -> V_195 ,
L_223 ) ;
V_511 += V_515 ;
V_516 += V_515 ;
}
}
* V_514 = 0 ;
if ( V_512 && V_517 ) {
V_84 = V_512 ;
V_521 = V_513 ;
for ( V_83 = 0 ; V_83 < V_519 . V_140 ; V_83 ++ ) {
V_520 = & V_519 . V_495 [ V_83 ] ;
if ( V_521 < ( V_520 -> V_488 . V_39 +
V_506 ) ) {
F_15 ( L_224 ,
V_521 ) ;
break;
}
V_521 -= ( V_520 -> V_195 +
V_506 ) ;
F_3 ( V_58 , L_225 ,
V_520 -> V_488 . V_364 ,
V_520 -> V_488 . V_39 ,
V_520 -> V_488 . V_367 [ 0 ] ,
V_520 -> V_488 . V_367 [ 1 ] ,
V_520 -> V_488 . V_367 [ 2 ] ) ;
V_515 = F_141 ( V_511 , V_499 ,
V_520 -> V_496 ,
V_520 -> V_195 ,
L_226 ) ;
memcpy ( V_84 + ( * V_514 ) , V_520 -> V_496 ,
V_520 -> V_195 ) ;
* V_514 += V_520 -> V_195 ;
V_511 += V_515 ;
V_516 += V_515 ;
}
}
if ( V_516 ) {
V_49 = F_13 ( V_55 , L_227 , V_510 ,
V_516 ) ;
if ( V_49 )
F_15 ( L_228 , V_49 ) ;
}
exit:
F_36 ( V_510 ) ;
return V_49 ;
}
static T_4
F_143 ( struct V_50 * V_50 , struct V_47 * V_48 ,
struct V_528 * V_529 )
{
T_4 V_347 ;
struct V_54 * V_55 = F_14 ( V_48 ) ;
struct V_360 * V_530 ;
struct V_85 V_86 ;
T_4 V_49 = - V_118 ;
struct V_360 * V_531 ;
struct V_371 * V_467 ;
struct V_177 V_178 ;
T_4 V_463 = 0 ;
F_3 ( V_58 , L_229 ,
F_144 ( & V_529 -> V_191 ) ,
V_529 -> V_196 ,
V_529 -> V_378 ) ;
F_3 ( V_58 , L_230 ,
V_529 -> V_105 , V_529 -> V_103 , V_529 -> V_220 ,
V_529 -> V_532 ) ;
if ( ! F_2 ( V_71 , & V_55 -> V_2 -> V_4 ) ) {
F_15 ( L_231 ) ;
return - V_118 ;
}
memset ( & V_86 , 0 , sizeof( V_86 ) ) ;
if ( V_529 -> V_105 == NULL || V_529 -> V_103 == 0 ) {
V_347 = V_533 + V_534 ;
V_530 = F_97 (
( T_2 * ) & V_529 -> V_535 . V_536 [ V_347 ] ,
V_529 -> V_535 . V_537 - V_347 ,
V_538 ) ;
if ( ! V_530 )
return - V_69 ;
memcpy ( V_86 . V_104 , V_530 -> V_45 , V_530 -> V_39 ) ;
V_86 . V_101 = F_9 ( V_530 -> V_39 ) ;
F_3 ( V_58 , L_232 , V_86 . V_104 ) ;
} else {
memcpy ( V_86 . V_104 , V_529 -> V_105 , V_529 -> V_103 ) ;
V_86 . V_101 = F_9 ( ( T_5 ) V_529 -> V_103 ) ;
}
F_19 ( V_48 , 0 ) ;
V_49 = F_18 ( V_55 , V_539 , 1 ) ;
if ( V_49 < 0 ) {
F_15 ( L_233 , V_49 ) ;
goto exit;
}
V_49 = F_18 ( V_55 , V_72 , 1 ) ;
if ( V_49 < 0 ) {
F_15 ( L_234 , V_49 ) ;
goto exit;
}
V_49 = F_18 ( V_55 , V_540 , 1 ) ;
if ( V_49 < 0 ) {
F_15 ( L_235 , V_49 ) ;
goto exit;
}
V_531 = F_97 ( ( T_2 * ) V_529 -> V_535 . V_541 ,
V_529 -> V_535 . V_542 , V_543 ) ;
V_467 = F_99 ( ( T_2 * ) V_529 -> V_535 . V_541 ,
V_529 -> V_535 . V_542 ) ;
if ( ( V_467 != NULL || V_531 != NULL ) ) {
F_3 ( V_58 , L_236 ) ;
if ( V_467 != NULL ) {
V_49 = F_139 ( V_48 , V_467 , false ) ;
if ( V_49 < 0 )
goto exit;
} else {
V_49 = F_139 ( V_48 ,
(struct V_371 * ) V_531 , true ) ;
if ( V_49 < 0 )
goto exit;
}
} else {
F_3 ( V_58 , L_237 ) ;
F_137 ( V_48 , V_463 ) ;
}
V_49 = F_142 ( F_145 ( V_48 ) ,
V_525 ,
V_529 -> V_535 . V_541 ,
V_529 -> V_535 . V_542 ) ;
if ( V_49 )
F_15 ( L_238 ) ;
else
F_3 ( V_58 , L_239 ) ;
V_49 = F_142 ( F_145 ( V_48 ) ,
V_522 ,
V_529 -> V_535 . V_544 ,
V_529 -> V_535 . V_545 ) ;
if ( V_49 )
F_15 ( L_240 ) ;
else
F_3 ( V_58 , L_241 ) ;
if ( V_529 -> V_196 ) {
V_49 = F_18 ( V_55 , V_200 ,
V_529 -> V_196 ) ;
if ( V_49 < 0 ) {
F_15 ( L_242 , V_49 ) ;
goto exit;
}
}
if ( V_529 -> V_378 ) {
V_49 = F_18 ( V_55 , V_546 ,
V_529 -> V_378 ) ;
if ( V_49 < 0 ) {
F_15 ( L_243 , V_49 ) ;
goto exit;
}
}
V_49 = F_18 ( V_55 , V_547 , 1 ) ;
if ( V_49 < 0 ) {
F_15 ( L_244 , V_49 ) ;
goto exit;
}
memset ( & V_178 , 0 , sizeof( V_178 ) ) ;
memcpy ( & V_178 . V_86 , & V_86 , sizeof( V_86 ) ) ;
V_49 = F_27 ( V_55 , V_205 ,
& V_178 , sizeof( V_178 ) ) ;
if ( V_49 < 0 ) {
F_15 ( L_245 , V_49 ) ;
goto exit;
}
F_42 ( V_71 , & V_55 -> V_2 -> V_4 ) ;
F_17 ( V_548 , & V_55 -> V_2 -> V_4 ) ;
exit:
if ( V_49 )
F_19 ( V_48 , 1 ) ;
return V_49 ;
}
static int F_146 ( struct V_50 * V_50 , struct V_47 * V_48 )
{
struct V_54 * V_55 = F_14 ( V_48 ) ;
T_4 V_49 = - V_118 ;
F_3 ( V_58 , L_23 ) ;
if ( V_55 -> V_2 -> V_63 == V_68 ) {
F_116 ( 400 ) ;
V_49 = F_18 ( V_55 , V_540 , 0 ) ;
if ( V_49 < 0 ) {
F_15 ( L_235 , V_49 ) ;
goto exit;
}
V_49 = F_18 ( V_55 , V_547 , 0 ) ;
if ( V_49 < 0 ) {
F_15 ( L_246 , V_49 ) ;
goto exit;
}
F_19 ( V_48 , 1 ) ;
F_42 ( V_71 , & V_55 -> V_2 -> V_4 ) ;
F_42 ( V_548 , & V_55 -> V_2 -> V_4 ) ;
}
exit:
return V_49 ;
}
static int
F_147 ( struct V_50 * V_50 , struct V_47 * V_48 ,
T_2 * V_285 )
{
struct V_251 V_252 ;
struct V_54 * V_55 = F_14 ( V_48 ) ;
T_4 V_49 ;
if ( ! V_285 )
return - V_549 ;
F_3 ( V_58 , L_247 , V_285 ) ;
if ( ! F_1 ( V_55 -> V_2 ) )
return - V_159 ;
memcpy ( & V_252 . V_46 , V_285 , V_88 ) ;
V_252 . V_210 = F_9 ( V_550 ) ;
V_49 = F_27 ( V_55 , V_551 ,
& V_252 , sizeof( V_252 ) ) ;
if ( V_49 )
F_15 ( L_248 , V_49 ) ;
F_3 ( V_58 , L_11 ) ;
return V_49 ;
}
static T_4 F_148 ( T_4 V_63 )
{
T_4 V_49 = 0 ;
switch ( V_63 ) {
case V_66 :
return V_65 ;
case V_64 :
return V_62 ;
default:
return V_552 ;
}
return V_49 ;
}
static void F_149 ( struct V_50 * V_50 )
{
V_50 -> V_553 = V_554 ;
V_50 -> V_555 = V_554 ;
V_50 -> V_556 = V_557 ;
V_50 -> V_26 |= V_558 ;
}
static struct V_50 * F_150 ( struct V_559 * V_560 )
{
struct V_50 * V_50 ;
T_4 V_49 = 0 ;
V_50 = F_151 ( & V_561 , sizeof( struct V_108 ) ) ;
if ( ! V_50 ) {
F_15 ( L_249 ) ;
return F_152 ( - V_125 ) ;
}
F_153 ( V_50 , V_560 ) ;
V_50 -> V_562 = V_563 ;
V_50 -> V_564 = V_424 ;
V_50 -> V_402 = F_108 ( V_65 ) |
F_108 ( V_62 ) |
F_108 ( V_67 ) ;
V_50 -> V_344 [ V_23 ] = & V_565 ;
V_50 -> V_344 [ V_325 ] = & V_566 ;
V_50 -> V_567 = V_568 ;
V_50 -> V_569 = V_570 ;
V_50 -> V_571 = F_154 ( V_570 ) ;
V_50 -> V_26 |= V_572 ;
F_149 ( V_50 ) ;
V_49 = F_155 ( V_50 ) ;
if ( V_49 < 0 ) {
F_15 ( L_250 , V_49 ) ;
F_156 ( V_50 ) ;
return F_152 ( V_49 ) ;
}
return V_50 ;
}
static
struct V_1 * F_157 ( struct V_108 * V_109 ,
struct V_47 * V_158 ,
T_4 V_63 , bool V_573 )
{
struct V_1 * V_2 ;
if ( V_109 -> V_574 == V_575 )
return F_152 ( - V_576 ) ;
V_2 = F_33 ( sizeof( * V_2 ) , V_124 ) ;
if ( ! V_2 )
return F_152 ( - V_125 ) ;
V_2 -> V_157 . V_50 = V_109 -> V_50 ;
V_2 -> V_157 . V_158 = V_158 ;
V_2 -> V_157 . V_75 = F_148 ( V_63 ) ;
if ( V_158 ) {
V_2 -> V_55 = F_14 ( V_158 ) ;
V_158 -> V_74 = & V_2 -> V_157 ;
F_158 ( V_158 , F_159 ( V_109 -> V_50 ) ) ;
}
V_2 -> V_63 = V_63 ;
V_2 -> V_573 = V_573 ;
V_2 -> V_577 = - 1 ;
F_51 ( & V_2 -> V_188 ) ;
F_160 ( & V_2 -> V_352 , & V_109 -> V_578 ) ;
V_109 -> V_574 ++ ;
return V_2 ;
}
static void F_161 ( struct V_1 * V_2 )
{
struct V_108 * V_109 ;
struct V_50 * V_50 ;
V_50 = V_2 -> V_157 . V_50 ;
V_109 = F_131 ( V_50 ) ;
F_162 ( & V_2 -> V_352 ) ;
V_109 -> V_574 -- ;
F_36 ( V_2 ) ;
if ( ! V_109 -> V_574 ) {
F_163 ( V_50 ) ;
F_156 ( V_50 ) ;
}
}
static bool F_164 ( const struct V_392 * V_393 )
{
T_5 V_579 = V_393 -> V_432 ;
T_5 V_396 = V_393 -> V_396 ;
if ( V_579 == V_580 && V_396 == V_405 ) {
F_3 ( V_184 , L_251 ) ;
return true ;
}
return false ;
}
static bool F_165 ( const struct V_392 * V_393 )
{
T_5 V_579 = V_393 -> V_432 ;
T_1 V_26 = V_393 -> V_26 ;
if ( V_579 == V_581 && ( ! ( V_26 & V_582 ) ) ) {
F_3 ( V_184 , L_252 ) ;
return true ;
}
return false ;
}
static bool F_166 ( struct V_108 * V_109 ,
const struct V_392 * V_393 )
{
T_5 V_579 = V_393 -> V_432 ;
T_5 V_396 = V_393 -> V_396 ;
if ( V_579 == V_581 && V_396 == V_583 ) {
F_3 ( V_184 , L_253 ,
V_393 -> V_26 & V_582 ? L_254 : L_255 ) ;
return true ;
}
if ( V_579 == V_580 && V_396 != V_405 ) {
F_3 ( V_184 , L_256 ) ;
return true ;
}
return false ;
}
static void F_167 ( struct V_108 * V_109 )
{
struct V_584 * V_585 = F_168 ( V_109 ) ;
F_36 ( V_585 -> V_586 ) ;
V_585 -> V_586 = NULL ;
V_585 -> V_587 = 0 ;
F_36 ( V_585 -> V_588 ) ;
V_585 -> V_588 = NULL ;
V_585 -> V_589 = 0 ;
}
static T_4 F_169 ( struct V_108 * V_109 )
{
struct V_54 * V_55 = F_14 ( F_50 ( V_109 ) ) ;
struct V_590 * V_591 ;
struct V_584 * V_585 = F_168 ( V_109 ) ;
T_5 V_592 ;
T_5 V_593 ;
T_4 V_49 = 0 ;
F_167 ( V_109 ) ;
V_49 = F_79 ( V_55 , L_257 ,
V_109 -> V_379 , V_594 ) ;
if ( V_49 ) {
F_15 ( L_258 , V_49 ) ;
return V_49 ;
}
V_591 =
(struct V_590 * ) V_109 -> V_379 ;
V_592 = F_80 ( V_591 -> V_592 ) ;
V_593 = F_80 ( V_591 -> V_593 ) ;
if ( V_592 ) {
V_49 = F_79 ( V_55 , L_259 ,
V_109 -> V_379 ,
V_594 ) ;
if ( V_49 ) {
F_15 ( L_260 , V_49 ) ;
return V_49 ;
}
V_585 -> V_587 = V_592 ;
V_585 -> V_586 =
F_170 ( V_109 -> V_379 , V_585 -> V_587 ,
V_124 ) ;
} else {
V_585 -> V_587 = 0 ;
V_585 -> V_586 = NULL ;
}
if ( V_593 ) {
V_49 = F_79 ( V_55 , L_261 ,
V_109 -> V_379 ,
V_594 ) ;
if ( V_49 ) {
F_15 ( L_262 , V_49 ) ;
return V_49 ;
}
V_585 -> V_589 = V_593 ;
V_585 -> V_588 =
F_170 ( V_109 -> V_379 , V_585 -> V_589 ,
V_124 ) ;
} else {
V_585 -> V_589 = 0 ;
V_585 -> V_588 = NULL ;
}
F_3 ( V_184 , L_263 ,
V_585 -> V_587 , V_585 -> V_589 ) ;
return V_49 ;
}
static T_4
F_171 ( struct V_108 * V_109 ,
struct V_47 * V_48 ,
const struct V_392 * V_393 )
{
struct V_54 * V_55 = F_14 ( V_48 ) ;
struct V_175 * V_188 = & V_55 -> V_2 -> V_188 ;
struct V_584 * V_585 = F_168 ( V_109 ) ;
struct V_50 * V_50 = F_29 ( V_109 ) ;
struct V_17 * V_331 = NULL ;
struct V_334 * V_22 ;
struct V_329 * V_330 ;
T_5 V_335 ;
T_4 V_49 = 0 ;
T_5 V_201 ;
T_2 * V_356 ;
F_3 ( V_58 , L_23 ) ;
F_169 ( V_109 ) ;
memcpy ( V_188 -> V_87 , V_393 -> V_316 , V_88 ) ;
F_100 ( V_109 ) ;
V_356 = F_33 ( V_342 , V_124 ) ;
if ( V_356 == NULL ) {
V_49 = - V_125 ;
goto V_70;
}
* ( V_358 * ) V_356 = F_9 ( V_342 ) ;
V_49 = F_82 ( V_55 , V_359 ,
V_356 , V_342 ) ;
if ( V_49 )
goto V_70;
V_330 = (struct V_329 * ) ( V_356 + 4 ) ;
V_201 = V_330 -> V_343 ? V_330 -> V_343 :
F_87 ( F_88 ( V_330 -> V_19 ) ) ;
if ( V_201 <= V_180 )
V_22 = V_50 -> V_344 [ V_23 ] ;
else
V_22 = V_50 -> V_344 [ V_325 ] ;
V_335 = F_89 ( V_201 , V_22 -> V_22 ) ;
V_331 = F_90 ( V_50 , V_335 ) ;
V_70:
F_36 ( V_356 ) ;
F_172 ( V_48 , V_331 , ( T_2 * ) V_188 -> V_87 ,
V_585 -> V_586 , V_585 -> V_587 ,
V_585 -> V_588 , V_585 -> V_589 , V_124 ) ;
F_3 ( V_184 , L_264 ) ;
F_17 ( V_185 , & V_55 -> V_2 -> V_4 ) ;
F_3 ( V_58 , L_11 ) ;
return V_49 ;
}
static T_4
F_173 ( struct V_108 * V_109 ,
struct V_47 * V_48 , const struct V_392 * V_393 ,
bool V_595 )
{
struct V_54 * V_55 = F_14 ( V_48 ) ;
struct V_175 * V_188 = & V_55 -> V_2 -> V_188 ;
struct V_584 * V_585 = F_168 ( V_109 ) ;
T_4 V_49 = 0 ;
F_3 ( V_58 , L_23 ) ;
if ( F_31 ( V_152 ,
& V_55 -> V_2 -> V_4 ) ) {
if ( V_595 ) {
F_169 ( V_109 ) ;
memcpy ( V_188 -> V_87 , V_393 -> V_316 , V_88 ) ;
F_100 ( V_109 ) ;
}
F_174 ( V_48 ,
( T_2 * ) V_188 -> V_87 ,
V_585 -> V_586 ,
V_585 -> V_587 ,
V_585 -> V_588 ,
V_585 -> V_589 ,
V_595 ? V_596 :
V_597 ,
V_124 ) ;
if ( V_595 )
F_17 ( V_185 ,
& V_55 -> V_2 -> V_4 ) ;
F_3 ( V_184 , L_265 ,
V_595 ? L_266 : L_196 ) ;
}
F_3 ( V_58 , L_11 ) ;
return V_49 ;
}
static T_4
F_175 ( struct V_108 * V_109 ,
struct V_47 * V_48 ,
const struct V_392 * V_393 , void * V_45 )
{
T_4 V_49 = 0 ;
T_5 V_579 = V_393 -> V_432 ;
T_5 V_598 = V_393 -> V_598 ;
T_5 V_39 = V_393 -> V_599 ;
static int V_600 ;
struct V_286 V_287 ;
F_3 ( V_184 , L_267 , V_579 , V_598 ) ;
memset ( & V_287 , 0 , sizeof( V_287 ) ) ;
V_287 . V_293 = 0 ;
if ( ( ( V_579 == V_601 ) || ( V_579 == V_602 ) ) &&
V_598 == V_405 ) {
V_287 . V_293 = V_603 ;
if ( ! V_45 ) {
F_15 ( L_268 ) ;
return - V_69 ;
}
V_287 . V_604 = V_45 ;
V_287 . V_605 = V_39 ;
V_600 ++ ;
V_287 . V_600 = V_600 ;
F_176 ( V_48 , V_393 -> V_316 , & V_287 , V_606 ) ;
} else if ( ( V_579 == V_607 ) ||
( V_579 == V_608 ) ||
( V_579 == V_609 ) ) {
V_600 ++ ;
V_287 . V_600 = V_600 ;
F_177 ( V_48 , V_393 -> V_316 , V_606 ) ;
}
return V_49 ;
}
static T_4
F_178 ( struct V_54 * V_55 ,
const struct V_392 * V_393 , void * V_45 )
{
struct V_108 * V_109 = V_55 -> V_394 -> V_395 ;
struct V_47 * V_48 = V_55 -> V_48 ;
struct V_175 * V_188 = & V_55 -> V_2 -> V_188 ;
T_4 V_49 = 0 ;
if ( V_55 -> V_2 -> V_63 == V_68 ) {
V_49 = F_175 ( V_109 , V_48 , V_393 , V_45 ) ;
} else if ( F_164 ( V_393 ) ) {
F_3 ( V_184 , L_269 ) ;
if ( F_96 ( V_55 -> V_2 ) ) {
memcpy ( V_188 -> V_87 , V_393 -> V_316 , V_88 ) ;
F_95 ( V_109 , V_48 , V_393 -> V_316 ) ;
F_179 ( V_48 , V_393 -> V_316 , V_124 ) ;
F_42 ( V_152 ,
& V_55 -> V_2 -> V_4 ) ;
F_17 ( V_185 ,
& V_55 -> V_2 -> V_4 ) ;
} else
F_173 ( V_109 , V_48 , V_393 , true ) ;
} else if ( F_165 ( V_393 ) ) {
F_3 ( V_184 , L_270 ) ;
if ( ! F_96 ( V_55 -> V_2 ) ) {
F_173 ( V_109 , V_48 , V_393 , false ) ;
if ( F_31 ( V_185 ,
& V_55 -> V_2 -> V_4 ) )
F_180 ( V_48 , 0 , NULL , 0 ,
V_124 ) ;
}
F_53 ( V_55 -> V_2 ) ;
F_51 ( F_57 ( V_48 ) ) ;
} else if ( F_166 ( V_109 , V_393 ) ) {
if ( F_96 ( V_55 -> V_2 ) )
F_42 ( V_152 ,
& V_55 -> V_2 -> V_4 ) ;
else
F_173 ( V_109 , V_48 , V_393 , false ) ;
}
return V_49 ;
}
static T_4
F_181 ( struct V_54 * V_55 ,
const struct V_392 * V_393 , void * V_45 )
{
struct V_108 * V_109 = V_55 -> V_394 -> V_395 ;
T_4 V_49 = 0 ;
T_5 V_579 = V_393 -> V_432 ;
T_5 V_396 = V_393 -> V_396 ;
if ( V_579 == V_610 && V_396 == V_405 ) {
if ( F_2 ( V_185 , & V_55 -> V_2 -> V_4 ) )
F_171 ( V_109 , V_55 -> V_48 , V_393 ) ;
else
F_173 ( V_109 , V_55 -> V_48 , V_393 , true ) ;
}
return V_49 ;
}
static T_4
F_182 ( struct V_54 * V_55 ,
const struct V_392 * V_393 , void * V_45 )
{
T_1 V_26 = V_393 -> V_26 ;
enum V_611 V_612 ;
if ( V_26 & V_613 )
V_612 = V_614 ;
else
V_612 = V_615 ;
F_183 ( V_55 -> V_48 , ( T_2 * ) & V_393 -> V_316 , V_612 , - 1 ,
NULL , V_124 ) ;
return 0 ;
}
static void F_184 ( struct V_616 * V_169 )
{
V_169 -> V_161 = ( T_5 ) - 1 ;
V_169 -> V_160 = ( T_5 ) - 1 ;
V_169 -> V_174 = ( T_5 ) - 1 ;
V_169 -> V_172 = ( T_5 ) - 1 ;
V_169 -> V_264 = - 1 ;
}
static void F_185 ( struct V_108 * V_109 )
{
F_110 ( V_109 -> V_406 , V_581 ,
F_178 ) ;
F_110 ( V_109 -> V_406 , V_608 ,
F_178 ) ;
F_110 ( V_109 -> V_406 , V_609 ,
F_178 ) ;
F_110 ( V_109 -> V_406 , V_607 ,
F_178 ) ;
F_110 ( V_109 -> V_406 , V_601 ,
F_178 ) ;
F_110 ( V_109 -> V_406 , V_602 ,
F_178 ) ;
F_110 ( V_109 -> V_406 , V_610 ,
F_181 ) ;
F_110 ( V_109 -> V_406 , V_617 ,
F_182 ) ;
F_110 ( V_109 -> V_406 , V_580 ,
F_178 ) ;
F_110 ( V_109 -> V_406 , V_618 ,
F_124 ) ;
}
static void F_186 ( struct V_108 * V_109 )
{
F_36 ( V_109 -> V_169 ) ;
V_109 -> V_169 = NULL ;
F_36 ( V_109 -> V_619 ) ;
V_109 -> V_619 = NULL ;
F_36 ( V_109 -> V_379 ) ;
V_109 -> V_379 = NULL ;
F_36 ( V_109 -> V_413 ) ;
V_109 -> V_413 = NULL ;
}
static T_4 F_187 ( struct V_108 * V_109 )
{
V_109 -> V_169 = F_33 ( sizeof( * V_109 -> V_169 ) , V_124 ) ;
if ( ! V_109 -> V_169 )
goto V_620;
V_109 -> V_619 = F_33 ( V_126 , V_124 ) ;
if ( ! V_109 -> V_619 )
goto V_620;
V_109 -> V_379 = F_33 ( V_380 , V_124 ) ;
if ( ! V_109 -> V_379 )
goto V_620;
V_109 -> V_413 = F_33 ( sizeof( * V_109 -> V_413 ) , V_124 ) ;
if ( ! V_109 -> V_413 )
goto V_620;
return 0 ;
V_620:
F_186 ( V_109 ) ;
return - V_125 ;
}
static T_4 F_188 ( struct V_108 * V_109 )
{
T_4 V_49 = 0 ;
V_109 -> V_112 = NULL ;
V_109 -> V_311 = true ;
V_109 -> V_621 = true ;
V_109 -> V_137 = true ;
V_109 -> V_622 = false ;
V_49 = F_187 ( V_109 ) ;
if ( V_49 )
return V_49 ;
F_185 ( V_109 ) ;
F_189 ( & V_109 -> V_623 ) ;
F_109 ( V_109 ) ;
F_184 ( V_109 -> V_169 ) ;
return V_49 ;
}
static void F_190 ( struct V_108 * V_109 )
{
V_109 -> V_622 = false ;
F_101 ( V_109 ) ;
F_186 ( V_109 ) ;
}
struct V_108 * F_191 ( struct V_624 * V_394 ,
struct V_559 * V_625 )
{
struct V_47 * V_48 = V_394 -> V_626 [ 0 ] -> V_48 ;
struct V_108 * V_109 ;
struct V_50 * V_50 ;
struct V_1 * V_2 ;
struct V_54 * V_55 ;
T_4 V_49 = 0 ;
if ( ! V_48 ) {
F_15 ( L_271 ) ;
return NULL ;
}
V_55 = F_14 ( V_48 ) ;
V_50 = F_150 ( V_625 ) ;
if ( F_192 ( V_50 ) )
return NULL ;
V_109 = F_131 ( V_50 ) ;
V_109 -> V_50 = V_50 ;
V_109 -> V_406 = V_394 ;
F_193 ( & V_109 -> V_578 ) ;
V_2 = F_157 ( V_109 , V_48 , V_66 , false ) ;
if ( F_192 ( V_2 ) ) {
F_156 ( V_50 ) ;
return NULL ;
}
V_49 = F_188 ( V_109 ) ;
if ( V_49 ) {
F_15 ( L_272 , V_49 ) ;
goto V_627;
}
V_55 -> V_2 = V_2 ;
return V_109 ;
V_627:
F_161 ( V_2 ) ;
return NULL ;
}
void F_194 ( struct V_108 * V_109 )
{
struct V_1 * V_2 ;
struct V_1 * V_628 ;
F_190 ( V_109 ) ;
F_195 (vif, tmp, &cfg->vif_list, list) {
F_161 ( V_2 ) ;
}
}
static T_4
F_196 ( struct V_47 * V_48 , T_5 V_629 , T_5 V_630 )
{
struct V_54 * V_55 = F_14 ( V_48 ) ;
T_4 V_49 = 0 ;
V_358 V_631 [ 2 ] ;
V_358 V_632 [ 2 ] ;
if ( V_629 ) {
V_49 = F_20 ( V_55 , L_273 , V_630 ) ;
if ( V_49 ) {
F_15 ( L_274 , V_49 ) ;
goto V_633;
}
}
F_3 ( V_5 , L_275 , V_629 ? L_276 : L_277 ) ;
V_49 = F_20 ( V_55 , L_278 , V_629 ) ;
if ( V_49 ) {
F_15 ( L_279 , V_49 ) ;
goto V_633;
}
V_631 [ 0 ] = F_9 ( V_634 ) ;
V_631 [ 1 ] = F_9 ( V_635 ) ;
V_49 = F_27 ( V_55 , V_636 ,
( void * ) V_631 , sizeof( V_631 ) ) ;
if ( V_49 ) {
F_15 ( L_280 , V_49 ) ;
goto V_633;
}
V_632 [ 0 ] = F_9 ( V_637 ) ;
V_632 [ 1 ] = F_9 ( V_635 ) ;
V_49 = F_27 ( V_55 , V_638 ,
( void * ) V_632 , sizeof( V_632 ) ) ;
if ( V_49 ) {
F_15 ( L_281 , V_49 ) ;
goto V_633;
}
V_633:
return V_49 ;
}
static T_4
F_197 ( struct V_47 * V_48 , T_4 V_639 ,
T_4 V_640 , T_4 V_641 )
{
struct V_54 * V_55 = F_14 ( V_48 ) ;
T_4 V_49 = 0 ;
V_49 = F_18 ( V_55 , V_642 ,
V_639 ) ;
if ( V_49 ) {
if ( V_49 == - V_61 )
F_3 ( V_5 , L_282 ) ;
else
F_15 ( L_283 , V_49 ) ;
goto V_643;
}
V_49 = F_18 ( V_55 , V_644 ,
V_640 ) ;
if ( V_49 ) {
if ( V_49 == - V_61 )
F_3 ( V_5 , L_284 ) ;
else
F_15 ( L_285 , V_49 ) ;
goto V_643;
}
V_49 = F_18 ( V_55 , V_645 ,
V_641 ) ;
if ( V_49 ) {
if ( V_49 == - V_61 )
F_3 ( V_5 , L_286 ) ;
else
F_15 ( L_287 , V_49 ) ;
goto V_643;
}
V_643:
return V_49 ;
}
static T_4 F_198 ( struct V_108 * V_109 )
{
struct V_54 * V_55 = F_14 ( F_50 ( V_109 ) ) ;
struct V_50 * V_50 ;
T_4 V_646 ;
T_9 V_647 ;
T_4 V_49 = 0 ;
V_49 = F_82 ( V_55 , V_648 ,
& V_646 , sizeof( V_646 ) ) ;
if ( V_49 ) {
F_15 ( L_34 , V_49 ) ;
return V_49 ;
}
V_647 = ( ( char * ) & V_646 ) [ 0 ] ;
F_3 ( V_5 , L_288 , V_647 ) ;
if ( V_647 == 'n' || V_647 == 'a' ) {
V_50 = F_29 ( V_109 ) ;
V_50 -> V_344 [ V_325 ] = & V_649 ;
}
return V_49 ;
}
static T_4 F_199 ( struct V_108 * V_109 )
{
return F_198 ( V_109 ) ;
}
static T_4 F_200 ( struct V_108 * V_109 )
{
struct V_47 * V_48 ;
struct V_253 * V_157 ;
T_4 V_650 ;
T_4 V_49 = 0 ;
if ( V_109 -> V_622 )
return V_49 ;
V_48 = F_50 ( V_109 ) ;
V_157 = V_48 -> V_74 ;
F_197 ( V_48 , V_651 ,
V_652 , V_653 ) ;
V_650 = V_109 -> V_311 ? V_312 : V_313 ;
V_49 = F_18 ( F_14 ( V_48 ) , V_314 ,
V_650 ) ;
if ( V_49 )
goto V_654;
F_3 ( V_5 , L_289 ,
( V_650 ? L_139 : L_140 ) ) ;
V_49 = F_196 ( V_48 , ( V_109 -> V_621 ? 0 : 1 ) ,
V_655 ) ;
if ( V_49 )
goto V_654;
V_49 = F_16 ( V_157 -> V_50 , V_48 , V_157 -> V_75 ,
NULL , NULL ) ;
if ( V_49 && V_49 != - V_656 )
goto V_654;
V_49 = F_199 ( V_109 ) ;
if ( V_49 )
goto V_654;
V_654:
V_109 -> V_622 = true ;
return V_49 ;
}
static T_4 F_201 ( struct V_54 * V_55 )
{
F_17 ( V_3 , & V_55 -> V_2 -> V_4 ) ;
if ( V_55 -> V_8 )
return 0 ;
return F_200 ( V_55 -> V_394 -> V_395 ) ;
}
static T_4 F_202 ( struct V_54 * V_55 )
{
struct V_108 * V_109 = V_55 -> V_394 -> V_395 ;
if ( F_1 ( V_55 -> V_2 ) ) {
F_53 ( V_55 -> V_2 ) ;
F_113 ( 500 ) ;
}
F_101 ( V_109 ) ;
F_42 ( V_3 , & V_55 -> V_2 -> V_4 ) ;
return 0 ;
}
T_4 F_203 ( struct V_47 * V_48 )
{
struct V_54 * V_55 = F_14 ( V_48 ) ;
struct V_108 * V_109 = V_55 -> V_394 -> V_395 ;
T_4 V_49 = 0 ;
F_204 ( & V_109 -> V_623 ) ;
V_49 = F_201 ( V_55 ) ;
F_205 ( & V_109 -> V_623 ) ;
return V_49 ;
}
T_4 F_206 ( struct V_47 * V_48 )
{
struct V_54 * V_55 = F_14 ( V_48 ) ;
struct V_108 * V_109 = V_55 -> V_394 -> V_395 ;
T_4 V_49 = 0 ;
F_204 ( & V_109 -> V_623 ) ;
V_49 = F_202 ( V_55 ) ;
F_205 ( & V_109 -> V_623 ) ;
return V_49 ;
}
