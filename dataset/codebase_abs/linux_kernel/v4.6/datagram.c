static bool F_1 ( const struct V_1 * V_2 )
{
return F_2 ( V_2 ) && ( V_2 -> V_3 [ 3 ] == 0 ) ;
}
static void F_3 ( struct V_4 * V_5 , struct V_6 * V_7 )
{
struct V_8 * V_9 = F_4 ( V_7 ) ;
struct V_10 * V_11 = F_5 ( V_7 ) ;
memset ( V_5 , 0 , sizeof( * V_5 ) ) ;
V_5 -> V_12 = V_7 -> V_13 ;
V_5 -> V_14 = V_7 -> V_15 ;
V_5 -> V_16 = V_11 -> V_16 ;
V_5 -> V_17 = V_7 -> V_18 ;
V_5 -> V_19 = V_7 -> V_20 ;
V_5 -> V_21 = V_9 -> V_22 ;
V_5 -> V_23 = V_9 -> V_24 ;
V_5 -> V_25 = V_11 -> V_26 ;
if ( ! V_5 -> V_17 )
V_5 -> V_17 = V_11 -> V_27 . V_28 ;
if ( ! V_5 -> V_17 && F_6 ( & V_5 -> V_14 ) )
V_5 -> V_17 = V_11 -> V_29 ;
F_7 ( V_7 , F_8 ( V_5 ) ) ;
}
int F_9 ( struct V_6 * V_7 , bool V_30 )
{
struct V_31 * V_25 = NULL ;
struct V_1 * V_32 , V_33 ;
struct V_34 * V_35 ;
struct V_36 * V_37 ;
struct V_8 * V_9 = F_4 ( V_7 ) ;
struct V_10 * V_11 = F_5 ( V_7 ) ;
struct V_4 V_5 ;
int V_38 = 0 ;
if ( V_11 -> V_39 && ( V_11 -> V_26 & V_40 ) ) {
V_25 = F_10 ( V_7 , V_11 -> V_26 ) ;
if ( ! V_25 )
return - V_41 ;
}
F_3 ( & V_5 , V_7 ) ;
F_11 () ;
V_35 = V_25 ? V_25 -> V_35 : F_12 ( V_11 -> V_35 ) ;
V_32 = F_13 ( & V_5 , V_35 , & V_33 ) ;
F_14 () ;
V_37 = F_15 ( V_7 , & V_5 , V_32 ) ;
if ( F_16 ( V_37 ) ) {
V_38 = F_17 ( V_37 ) ;
goto V_42;
}
if ( V_30 ) {
if ( F_18 ( & V_11 -> V_16 ) )
V_11 -> V_16 = V_5 . V_16 ;
if ( F_18 ( & V_7 -> V_43 ) ) {
V_7 -> V_43 = V_5 . V_16 ;
V_9 -> V_44 = V_45 ;
if ( V_7 -> V_46 -> V_47 )
V_7 -> V_46 -> V_47 ( V_7 ) ;
}
}
F_19 ( V_7 , V_37 ,
F_20 ( & V_5 . V_14 , & V_7 -> V_15 ) ?
& V_7 -> V_15 : NULL ,
#ifdef F_21
F_20 ( & V_5 . V_16 , & V_11 -> V_16 ) ?
& V_11 -> V_16 :
#endif
NULL ) ;
V_42:
F_22 ( V_25 ) ;
return V_38 ;
}
void F_23 ( struct V_6 * V_7 )
{
struct V_36 * V_37 ;
if ( F_2 ( & V_7 -> V_15 ) )
return;
F_11 () ;
V_37 = F_24 ( V_7 ) ;
if ( ! V_37 || ! V_37 -> V_48 ||
V_37 -> V_49 -> V_50 ( V_37 , F_5 ( V_7 ) -> V_51 ) ) {
F_14 () ;
return;
}
F_14 () ;
F_9 ( V_7 , false ) ;
}
static int F_25 ( struct V_6 * V_7 , struct V_52 * V_53 , int V_54 )
{
struct V_55 * V_56 = (struct V_55 * ) V_53 ;
struct V_8 * V_9 = F_4 ( V_7 ) ;
struct V_10 * V_11 = F_5 ( V_7 ) ;
struct V_1 * V_14 ;
int V_57 ;
int V_38 ;
T_1 V_58 = 0 ;
if ( V_56 -> V_59 == V_60 ) {
if ( F_26 ( V_7 ) )
return - V_61 ;
V_38 = F_27 ( V_7 , V_53 , V_54 ) ;
goto V_62;
}
if ( V_54 < V_63 )
return - V_41 ;
if ( V_56 -> V_59 != V_64 )
return - V_61 ;
if ( V_11 -> V_39 )
V_58 = V_56 -> V_65 & V_66 ;
V_57 = F_28 ( & V_56 -> V_67 ) ;
if ( V_57 == V_68 ) {
V_56 -> V_67 . V_69 [ 15 ] = 0x01 ;
}
V_14 = & V_56 -> V_67 ;
if ( V_57 == V_70 ) {
struct V_71 sin ;
if ( F_26 ( V_7 ) ) {
V_38 = - V_72 ;
goto V_42;
}
sin . V_73 = V_60 ;
sin . V_74 . V_75 = V_14 -> V_3 [ 3 ] ;
sin . V_76 = V_56 -> V_77 ;
V_38 = F_27 ( V_7 ,
(struct V_52 * ) & sin ,
sizeof( sin ) ) ;
V_62:
if ( V_38 )
goto V_42;
F_29 ( V_9 -> V_78 , & V_7 -> V_15 ) ;
if ( F_18 ( & V_11 -> V_16 ) ||
F_1 ( & V_11 -> V_16 ) )
F_29 ( V_9 -> V_79 , & V_11 -> V_16 ) ;
if ( F_18 ( & V_7 -> V_43 ) ||
F_1 ( & V_7 -> V_43 ) ) {
F_29 ( V_9 -> V_44 ,
& V_7 -> V_43 ) ;
if ( V_7 -> V_46 -> V_47 )
V_7 -> V_46 -> V_47 ( V_7 ) ;
}
goto V_42;
}
if ( F_30 ( V_57 ) ) {
if ( V_54 >= sizeof( struct V_55 ) &&
V_56 -> V_80 ) {
if ( V_7 -> V_18 &&
V_7 -> V_18 != V_56 -> V_80 ) {
V_38 = - V_41 ;
goto V_42;
}
V_7 -> V_18 = V_56 -> V_80 ;
}
if ( ! V_7 -> V_18 && ( V_57 & V_81 ) )
V_7 -> V_18 = V_11 -> V_29 ;
if ( ! V_7 -> V_18 ) {
V_38 = - V_41 ;
goto V_42;
}
}
V_7 -> V_15 = * V_14 ;
V_11 -> V_26 = V_58 ;
V_9 -> V_22 = V_56 -> V_77 ;
V_38 = F_9 ( V_7 , true ) ;
if ( V_38 )
goto V_42;
V_7 -> V_82 = V_83 ;
F_31 ( V_7 ) ;
V_42:
return V_38 ;
}
int F_32 ( struct V_6 * V_7 , struct V_52 * V_53 , int V_54 )
{
int V_84 ;
F_33 ( V_7 ) ;
V_84 = F_25 ( V_7 , V_53 , V_54 ) ;
F_34 ( V_7 ) ;
return V_84 ;
}
int F_35 ( struct V_6 * V_7 , struct V_52 * V_53 ,
int V_54 )
{
F_36 ( struct V_55 * , V_85 , V_53 ) ;
if ( V_85 -> V_59 != V_64 )
return - V_61 ;
return F_32 ( V_7 , V_53 , V_54 ) ;
}
void F_37 ( struct V_6 * V_7 , struct V_86 * V_87 , int V_38 ,
T_2 V_88 , T_3 V_89 , T_4 * V_90 )
{
struct V_10 * V_11 = F_5 ( V_7 ) ;
struct V_91 * V_92 = F_38 ( V_87 ) ;
struct V_93 * V_94 ;
if ( ! V_11 -> V_95 )
return;
V_87 = F_39 ( V_87 , V_96 ) ;
if ( ! V_87 )
return;
V_87 -> V_97 = F_40 ( V_98 ) ;
V_94 = F_41 ( V_87 ) ;
V_94 -> V_99 . V_100 = V_38 ;
V_94 -> V_99 . V_101 = V_102 ;
V_94 -> V_99 . V_103 = V_92 -> V_104 ;
V_94 -> V_99 . V_105 = V_92 -> V_106 ;
V_94 -> V_99 . V_107 = 0 ;
V_94 -> V_99 . V_108 = V_89 ;
V_94 -> V_99 . V_109 = 0 ;
V_94 -> V_110 = ( T_4 * ) & ( ( (struct V_111 * ) ( V_92 + 1 ) ) -> V_14 ) -
F_42 ( V_87 ) ;
V_94 -> V_88 = V_88 ;
F_43 ( V_87 , V_90 - V_87 -> V_112 ) ;
F_44 ( V_87 ) ;
if ( F_45 ( V_7 , V_87 ) )
F_46 ( V_87 ) ;
}
void F_47 ( struct V_6 * V_7 , int V_38 , struct V_4 * V_5 , T_3 V_89 )
{
const struct V_10 * V_11 = F_5 ( V_7 ) ;
struct V_93 * V_94 ;
struct V_111 * V_113 ;
struct V_86 * V_87 ;
if ( ! V_11 -> V_95 )
return;
V_87 = F_48 ( sizeof( struct V_111 ) , V_96 ) ;
if ( ! V_87 )
return;
V_87 -> V_97 = F_40 ( V_98 ) ;
F_49 ( V_87 , sizeof( struct V_111 ) ) ;
F_50 ( V_87 ) ;
V_113 = F_51 ( V_87 ) ;
V_113 -> V_14 = V_5 -> V_14 ;
V_94 = F_41 ( V_87 ) ;
V_94 -> V_99 . V_100 = V_38 ;
V_94 -> V_99 . V_101 = V_114 ;
V_94 -> V_99 . V_103 = 0 ;
V_94 -> V_99 . V_105 = 0 ;
V_94 -> V_99 . V_107 = 0 ;
V_94 -> V_99 . V_108 = V_89 ;
V_94 -> V_99 . V_109 = 0 ;
V_94 -> V_110 = ( T_4 * ) & V_113 -> V_14 - F_42 ( V_87 ) ;
V_94 -> V_88 = V_5 -> V_21 ;
F_43 ( V_87 , F_52 ( V_87 ) - V_87 -> V_112 ) ;
F_44 ( V_87 ) ;
if ( F_45 ( V_7 , V_87 ) )
F_46 ( V_87 ) ;
}
void F_53 ( struct V_6 * V_7 , struct V_4 * V_5 , T_3 V_115 )
{
struct V_10 * V_11 = F_5 ( V_7 ) ;
struct V_111 * V_113 ;
struct V_86 * V_87 ;
struct V_116 * V_117 ;
if ( ! V_11 -> V_118 . V_119 . V_120 )
return;
V_87 = F_48 ( sizeof( struct V_111 ) , V_96 ) ;
if ( ! V_87 )
return;
F_49 ( V_87 , sizeof( struct V_111 ) ) ;
F_50 ( V_87 ) ;
V_113 = F_51 ( V_87 ) ;
V_113 -> V_14 = V_5 -> V_14 ;
V_117 = F_54 ( V_87 ) ;
V_117 -> V_121 = V_115 ;
V_117 -> V_122 . V_59 = V_64 ;
V_117 -> V_122 . V_77 = 0 ;
V_117 -> V_122 . V_65 = 0 ;
V_117 -> V_122 . V_80 = V_5 -> V_17 ;
V_117 -> V_122 . V_67 = F_51 ( V_87 ) -> V_14 ;
F_43 ( V_87 , F_52 ( V_87 ) - V_87 -> V_112 ) ;
F_44 ( V_87 ) ;
V_87 = F_55 ( & V_11 -> V_120 , V_87 ) ;
F_46 ( V_87 ) ;
}
static inline bool F_56 ( struct V_93 * V_94 )
{
return V_94 -> V_99 . V_101 == V_102 ||
V_94 -> V_99 . V_101 == V_123 ||
V_94 -> V_99 . V_101 == V_114 || V_94 -> V_88 ;
}
static bool F_57 ( struct V_86 * V_87 ,
struct V_93 * V_94 )
{
if ( V_94 -> V_99 . V_101 == V_123 ||
V_94 -> V_99 . V_101 == V_102 )
return true ;
if ( V_94 -> V_99 . V_101 == V_114 )
return false ;
if ( ! V_87 -> V_124 )
return false ;
if ( V_87 -> V_97 == F_40 ( V_98 ) )
F_58 ( V_87 ) -> V_125 = V_87 -> V_124 -> V_126 ;
else
F_59 ( V_87 ) -> V_127 = V_87 -> V_124 -> V_126 ;
return true ;
}
int F_60 ( struct V_6 * V_7 , struct V_128 * V_129 , int V_130 , int * V_54 )
{
struct V_10 * V_11 = F_5 ( V_7 ) ;
struct V_93 * V_94 ;
struct V_86 * V_87 ;
F_36 ( struct V_55 * , sin , V_129 -> V_131 ) ;
struct {
struct V_132 V_99 ;
struct V_55 V_133 ;
} V_134 ;
int V_38 ;
int V_135 ;
V_38 = - V_136 ;
V_87 = F_61 ( V_7 ) ;
if ( ! V_87 )
goto V_42;
V_135 = V_87 -> V_130 ;
if ( V_135 > V_130 ) {
V_129 -> V_137 |= V_138 ;
V_135 = V_130 ;
}
V_38 = F_62 ( V_87 , 0 , V_129 , V_135 ) ;
if ( V_38 )
goto V_139;
F_63 ( V_129 , V_7 , V_87 ) ;
V_94 = F_41 ( V_87 ) ;
if ( sin && F_56 ( V_94 ) ) {
const unsigned char * V_140 = F_42 ( V_87 ) ;
sin -> V_59 = V_64 ;
sin -> V_65 = 0 ;
sin -> V_77 = V_94 -> V_88 ;
if ( V_87 -> V_97 == F_40 ( V_98 ) ) {
const struct V_111 * V_141 = F_64 ( (struct V_1 * ) ( V_140 + V_94 -> V_110 ) ,
struct V_111 , V_14 ) ;
sin -> V_67 = V_141 -> V_14 ;
if ( V_11 -> V_39 )
sin -> V_65 = F_65 ( V_141 ) ;
sin -> V_80 =
F_66 ( & sin -> V_67 ,
F_58 ( V_87 ) -> V_125 ) ;
} else {
F_29 ( * ( T_1 * ) ( V_140 + V_94 -> V_110 ) ,
& sin -> V_67 ) ;
sin -> V_80 = 0 ;
}
* V_54 = sizeof( * sin ) ;
}
memcpy ( & V_134 . V_99 , & V_94 -> V_99 , sizeof( struct V_132 ) ) ;
sin = & V_134 . V_133 ;
memset ( sin , 0 , sizeof( * sin ) ) ;
if ( F_57 ( V_87 , V_94 ) ) {
sin -> V_59 = V_64 ;
if ( V_11 -> V_118 . V_142 )
F_67 ( V_7 , V_129 , V_87 ) ;
if ( V_87 -> V_97 == F_40 ( V_98 ) ) {
sin -> V_67 = F_51 ( V_87 ) -> V_16 ;
if ( V_11 -> V_118 . V_142 )
F_68 ( V_7 , V_129 , V_87 ) ;
sin -> V_80 =
F_66 ( & sin -> V_67 ,
F_58 ( V_87 ) -> V_125 ) ;
} else {
F_29 ( F_69 ( V_87 ) -> V_16 ,
& sin -> V_67 ) ;
if ( F_4 ( V_7 ) -> V_143 )
F_70 ( V_129 , V_87 ) ;
}
}
F_71 ( V_129 , V_144 , V_145 , sizeof( V_134 ) , & V_134 ) ;
V_129 -> V_137 |= V_146 ;
V_38 = V_135 ;
V_139:
F_46 ( V_87 ) ;
V_42:
return V_38 ;
}
int F_72 ( struct V_6 * V_7 , struct V_128 * V_129 , int V_130 ,
int * V_54 )
{
struct V_10 * V_11 = F_5 ( V_7 ) ;
struct V_86 * V_87 ;
struct V_116 V_117 ;
F_36 ( struct V_55 * , sin , V_129 -> V_131 ) ;
int V_38 ;
int V_135 ;
V_38 = - V_136 ;
V_87 = F_55 ( & V_11 -> V_120 , NULL ) ;
if ( ! V_87 )
goto V_42;
V_135 = V_87 -> V_130 ;
if ( V_135 > V_130 ) {
V_129 -> V_137 |= V_138 ;
V_135 = V_130 ;
}
V_38 = F_62 ( V_87 , 0 , V_129 , V_135 ) ;
if ( V_38 )
goto V_139;
F_63 ( V_129 , V_7 , V_87 ) ;
memcpy ( & V_117 , F_54 ( V_87 ) , sizeof( V_117 ) ) ;
if ( sin ) {
sin -> V_59 = V_64 ;
sin -> V_65 = 0 ;
sin -> V_77 = 0 ;
sin -> V_80 = V_117 . V_122 . V_80 ;
sin -> V_67 = V_117 . V_122 . V_67 ;
* V_54 = sizeof( * sin ) ;
}
F_71 ( V_129 , V_144 , V_147 , sizeof( V_117 ) , & V_117 ) ;
V_38 = V_135 ;
V_139:
F_46 ( V_87 ) ;
V_42:
return V_38 ;
}
void F_67 ( struct V_6 * V_7 , struct V_128 * V_129 ,
struct V_86 * V_87 )
{
struct V_10 * V_11 = F_5 ( V_7 ) ;
bool V_148 = V_87 -> V_97 == F_40 ( V_98 ) ;
if ( V_11 -> V_118 . V_119 . V_149 ) {
struct V_150 V_151 ;
if ( V_148 ) {
V_151 . V_28 = F_58 ( V_87 ) -> V_125 ;
V_151 . V_152 = F_51 ( V_87 ) -> V_14 ;
} else {
V_151 . V_28 =
F_59 ( V_87 ) -> V_127 ;
F_29 ( F_69 ( V_87 ) -> V_14 ,
& V_151 . V_152 ) ;
}
if ( V_151 . V_28 >= 0 )
F_71 ( V_129 , V_144 , V_153 ,
sizeof( V_151 ) , & V_151 ) ;
}
}
void F_68 ( struct V_6 * V_7 , struct V_128 * V_129 ,
struct V_86 * V_87 )
{
struct V_10 * V_11 = F_5 ( V_7 ) ;
struct V_154 * V_35 = F_58 ( V_87 ) ;
unsigned char * V_140 = F_42 ( V_87 ) ;
if ( V_11 -> V_118 . V_119 . V_155 ) {
int V_156 = F_51 ( V_87 ) -> V_157 ;
F_71 ( V_129 , V_144 , V_158 , sizeof( V_156 ) , & V_156 ) ;
}
if ( V_11 -> V_118 . V_119 . V_159 ) {
int V_160 = F_73 ( F_51 ( V_87 ) ) ;
F_71 ( V_129 , V_144 , V_161 , sizeof( V_160 ) , & V_160 ) ;
}
if ( V_11 -> V_118 . V_119 . V_162 ) {
T_1 V_163 = F_65 ( (struct V_111 * ) V_140 ) ;
if ( V_163 )
F_71 ( V_129 , V_144 , V_164 , sizeof( V_163 ) , & V_163 ) ;
}
if ( V_11 -> V_118 . V_119 . V_165 && ( V_35 -> V_166 & V_167 ) ) {
T_4 * V_168 = V_140 + sizeof( struct V_111 ) ;
F_71 ( V_129 , V_144 , V_169 , ( V_168 [ 1 ] + 1 ) << 3 , V_168 ) ;
}
if ( V_35 -> V_170 &&
( V_11 -> V_118 . V_119 . V_171 || V_11 -> V_118 . V_119 . V_172 ) ) {
unsigned int V_173 = sizeof( struct V_111 ) ;
T_4 V_174 = F_51 ( V_87 ) -> V_174 ;
while ( V_173 <= V_35 -> V_170 ) {
unsigned int V_130 ;
T_4 * V_168 = V_140 + V_173 ;
switch ( V_174 ) {
case V_175 :
V_174 = V_168 [ 0 ] ;
V_130 = ( V_168 [ 1 ] + 1 ) << 3 ;
if ( V_11 -> V_118 . V_119 . V_171 )
F_71 ( V_129 , V_144 , V_176 , V_130 , V_168 ) ;
break;
case V_177 :
V_174 = V_168 [ 0 ] ;
V_130 = ( V_168 [ 1 ] + 1 ) << 3 ;
if ( V_11 -> V_118 . V_119 . V_172 )
F_71 ( V_129 , V_144 , V_178 , V_130 , V_168 ) ;
break;
case V_179 :
V_174 = V_168 [ 0 ] ;
V_130 = ( V_168 [ 1 ] + 2 ) << 2 ;
break;
default:
V_174 = V_168 [ 0 ] ;
V_130 = ( V_168 [ 1 ] + 1 ) << 3 ;
break;
}
V_173 += V_130 ;
}
}
if ( V_11 -> V_118 . V_119 . V_180 ) {
struct V_150 V_151 ;
V_151 . V_28 = V_35 -> V_125 ;
V_151 . V_152 = F_51 ( V_87 ) -> V_14 ;
F_71 ( V_129 , V_144 , V_181 , sizeof( V_151 ) , & V_151 ) ;
}
if ( V_11 -> V_118 . V_119 . V_182 ) {
int V_156 = F_51 ( V_87 ) -> V_157 ;
F_71 ( V_129 , V_144 , V_183 , sizeof( V_156 ) , & V_156 ) ;
}
if ( V_11 -> V_118 . V_119 . V_184 && ( V_35 -> V_166 & V_167 ) ) {
T_4 * V_168 = V_140 + sizeof( struct V_111 ) ;
F_71 ( V_129 , V_144 , V_185 , ( V_168 [ 1 ] + 1 ) << 3 , V_168 ) ;
}
if ( V_11 -> V_118 . V_119 . V_186 && V_35 -> V_187 ) {
T_4 * V_168 = V_140 + V_35 -> V_187 ;
F_71 ( V_129 , V_144 , V_188 , ( V_168 [ 1 ] + 1 ) << 3 , V_168 ) ;
}
if ( V_11 -> V_118 . V_119 . V_189 && V_35 -> V_172 ) {
struct V_190 * V_191 = (struct V_190 * ) ( V_140 + V_35 -> V_172 ) ;
F_71 ( V_129 , V_144 , V_192 , ( V_191 -> V_193 + 1 ) << 3 , V_191 ) ;
}
if ( V_11 -> V_118 . V_119 . V_186 && V_35 -> V_194 ) {
T_4 * V_168 = V_140 + V_35 -> V_194 ;
F_71 ( V_129 , V_144 , V_188 , ( V_168 [ 1 ] + 1 ) << 3 , V_168 ) ;
}
if ( V_11 -> V_118 . V_119 . V_195 ) {
struct V_55 V_85 ;
T_2 * V_196 = ( T_2 * ) F_74 ( V_87 ) ;
if ( F_75 ( V_87 ) + 4 <= V_87 -> V_130 ) {
V_85 . V_59 = V_64 ;
V_85 . V_67 = F_51 ( V_87 ) -> V_14 ;
V_85 . V_77 = V_196 [ 1 ] ;
V_85 . V_65 = 0 ;
V_85 . V_80 =
F_66 ( & F_51 ( V_87 ) -> V_14 ,
V_35 -> V_125 ) ;
F_71 ( V_129 , V_144 , V_197 , sizeof( V_85 ) , & V_85 ) ;
}
}
}
void F_76 ( struct V_6 * V_7 , struct V_128 * V_129 ,
struct V_86 * V_87 )
{
F_67 ( V_7 , V_129 , V_87 ) ;
F_68 ( V_7 , V_129 , V_87 ) ;
}
int F_77 ( struct V_198 * V_198 , struct V_6 * V_7 ,
struct V_128 * V_129 , struct V_4 * V_5 ,
struct V_34 * V_35 ,
int * V_199 , int * V_160 , int * V_200 )
{
struct V_150 * V_151 ;
struct V_201 * V_202 ;
struct V_190 * V_191 ;
struct V_203 * V_204 ;
int V_130 ;
int V_38 = 0 ;
F_78 (cmsg, msg) {
int V_57 ;
if ( ! F_79 ( V_129 , V_202 ) ) {
V_38 = - V_41 ;
goto V_205;
}
if ( V_202 -> V_206 != V_144 )
continue;
switch ( V_202 -> V_207 ) {
case V_153 :
case V_181 :
{
struct V_208 * V_124 = NULL ;
if ( V_202 -> V_209 < F_80 ( sizeof( struct V_150 ) ) ) {
V_38 = - V_41 ;
goto V_205;
}
V_151 = (struct V_150 * ) F_81 ( V_202 ) ;
if ( V_151 -> V_28 ) {
if ( V_5 -> V_17 &&
V_151 -> V_28 != V_5 -> V_17 )
return - V_41 ;
V_5 -> V_17 = V_151 -> V_28 ;
}
V_57 = F_82 ( & V_151 -> V_152 ) ;
F_11 () ;
if ( V_5 -> V_17 ) {
V_124 = F_83 ( V_198 , V_5 -> V_17 ) ;
if ( ! V_124 ) {
F_14 () ;
return - V_210 ;
}
} else if ( V_57 & V_211 ) {
F_14 () ;
return - V_41 ;
}
if ( V_57 != V_68 ) {
int V_212 = F_84 ( V_57 ) <= V_213 ;
if ( ! ( F_4 ( V_7 ) -> V_214 || F_4 ( V_7 ) -> V_215 ) &&
! F_85 ( V_198 , & V_151 -> V_152 ,
V_212 ? V_124 : NULL , 0 ) &&
! F_86 ( V_198 , V_124 ,
& V_151 -> V_152 ) )
V_38 = - V_41 ;
else
V_5 -> V_16 = V_151 -> V_152 ;
}
F_14 () ;
if ( V_38 )
goto V_205;
break;
}
case V_164 :
if ( V_202 -> V_209 < F_80 ( 4 ) ) {
V_38 = - V_41 ;
goto V_205;
}
if ( V_5 -> V_25 & V_66 ) {
if ( ( V_5 -> V_25 ^ * ( T_1 * ) F_81 ( V_202 ) ) & ~ V_66 ) {
V_38 = - V_41 ;
goto V_205;
}
}
V_5 -> V_25 = V_66 & * ( T_1 * ) F_81 ( V_202 ) ;
break;
case V_185 :
case V_169 :
if ( V_35 -> V_216 || V_202 -> V_209 < F_80 ( sizeof( struct V_203 ) ) ) {
V_38 = - V_41 ;
goto V_205;
}
V_204 = (struct V_203 * ) F_81 ( V_202 ) ;
V_130 = ( ( V_204 -> V_193 + 1 ) << 3 ) ;
if ( V_202 -> V_209 < F_80 ( V_130 ) ) {
V_38 = - V_41 ;
goto V_205;
}
if ( ! F_87 ( V_198 -> V_217 , V_218 ) ) {
V_38 = - V_219 ;
goto V_205;
}
V_35 -> V_220 += V_130 ;
V_35 -> V_216 = V_204 ;
break;
case V_188 :
if ( V_202 -> V_209 < F_80 ( sizeof( struct V_203 ) ) ) {
V_38 = - V_41 ;
goto V_205;
}
V_204 = (struct V_203 * ) F_81 ( V_202 ) ;
V_130 = ( ( V_204 -> V_193 + 1 ) << 3 ) ;
if ( V_202 -> V_209 < F_80 ( V_130 ) ) {
V_38 = - V_41 ;
goto V_205;
}
if ( ! F_87 ( V_198 -> V_217 , V_218 ) ) {
V_38 = - V_219 ;
goto V_205;
}
if ( V_35 -> V_221 ) {
V_38 = - V_41 ;
goto V_205;
}
V_35 -> V_222 += V_130 ;
V_35 -> V_221 = V_204 ;
break;
case V_176 :
case V_223 :
if ( V_202 -> V_209 < F_80 ( sizeof( struct V_203 ) ) ) {
V_38 = - V_41 ;
goto V_205;
}
V_204 = (struct V_203 * ) F_81 ( V_202 ) ;
V_130 = ( ( V_204 -> V_193 + 1 ) << 3 ) ;
if ( V_202 -> V_209 < F_80 ( V_130 ) ) {
V_38 = - V_41 ;
goto V_205;
}
if ( ! F_87 ( V_198 -> V_217 , V_218 ) ) {
V_38 = - V_219 ;
goto V_205;
}
if ( V_202 -> V_207 == V_176 ) {
V_35 -> V_222 += V_130 ;
V_35 -> V_221 = V_204 ;
} else {
V_35 -> V_220 += V_130 ;
V_35 -> V_224 = V_204 ;
}
break;
case V_192 :
case V_178 :
if ( V_202 -> V_209 < F_80 ( sizeof( struct V_190 ) ) ) {
V_38 = - V_41 ;
goto V_205;
}
V_191 = (struct V_190 * ) F_81 ( V_202 ) ;
switch ( V_191 -> type ) {
#if F_88 ( V_225 )
case V_226 :
if ( V_191 -> V_193 != 2 ||
V_191 -> V_227 != 1 ) {
V_38 = - V_41 ;
goto V_205;
}
break;
#endif
default:
V_38 = - V_41 ;
goto V_205;
}
V_130 = ( ( V_191 -> V_193 + 1 ) << 3 ) ;
if ( V_202 -> V_209 < F_80 ( V_130 ) ) {
V_38 = - V_41 ;
goto V_205;
}
if ( ( V_191 -> V_193 >> 1 ) != V_191 -> V_227 ) {
V_38 = - V_41 ;
goto V_205;
}
V_35 -> V_220 += V_130 ;
V_35 -> V_172 = V_191 ;
if ( V_202 -> V_207 == V_192 && V_35 -> V_221 ) {
int V_228 = ( ( V_35 -> V_221 -> V_193 + 1 ) << 3 ) ;
V_35 -> V_220 += V_228 ;
V_35 -> V_224 = V_35 -> V_221 ;
V_35 -> V_221 = NULL ;
V_35 -> V_222 -= V_228 ;
}
break;
case V_183 :
case V_158 :
if ( V_202 -> V_209 != F_80 ( sizeof( int ) ) ) {
V_38 = - V_41 ;
goto V_205;
}
* V_199 = * ( int * ) F_81 ( V_202 ) ;
if ( * V_199 < - 1 || * V_199 > 0xff ) {
V_38 = - V_41 ;
goto V_205;
}
break;
case V_161 :
{
int V_229 ;
V_38 = - V_41 ;
if ( V_202 -> V_209 != F_80 ( sizeof( int ) ) )
goto V_205;
V_229 = * ( int * ) F_81 ( V_202 ) ;
if ( V_229 < - 1 || V_229 > 0xff )
goto V_205;
V_38 = 0 ;
* V_160 = V_229 ;
break;
}
case V_230 :
{
int V_231 ;
V_38 = - V_41 ;
if ( V_202 -> V_209 != F_80 ( sizeof( int ) ) )
goto V_205;
V_231 = * ( int * ) F_81 ( V_202 ) ;
if ( V_231 < 0 || V_231 > 1 )
goto V_205;
V_38 = 0 ;
* V_200 = V_231 ;
break;
}
default:
F_89 ( L_1 ,
V_202 -> V_207 ) ;
V_38 = - V_41 ;
goto V_205;
}
}
V_205:
return V_38 ;
}
void F_90 ( struct V_232 * V_233 , struct V_6 * V_234 ,
T_5 V_235 , T_5 V_236 , int V_237 )
{
const struct V_1 * V_238 , * V_239 ;
V_238 = & V_234 -> V_15 ;
V_239 = & V_234 -> V_43 ;
F_91 ( V_233 ,
L_2
L_3 ,
V_237 ,
V_239 -> V_3 [ 0 ] , V_239 -> V_3 [ 1 ] ,
V_239 -> V_3 [ 2 ] , V_239 -> V_3 [ 3 ] , V_235 ,
V_238 -> V_3 [ 0 ] , V_238 -> V_3 [ 1 ] ,
V_238 -> V_3 [ 2 ] , V_238 -> V_3 [ 3 ] , V_236 ,
V_234 -> V_82 ,
F_92 ( V_234 ) ,
F_93 ( V_234 ) ,
0 , 0L , 0 ,
F_94 ( F_95 ( V_233 ) , F_96 ( V_234 ) ) ,
0 ,
F_97 ( V_234 ) ,
F_98 ( & V_234 -> V_240 ) , V_234 ,
F_98 ( & V_234 -> V_241 ) ) ;
}
