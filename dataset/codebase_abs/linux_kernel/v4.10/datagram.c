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
V_5 -> V_27 = V_7 -> V_28 ;
if ( ! V_5 -> V_17 )
V_5 -> V_17 = V_11 -> V_29 . V_30 ;
if ( ! V_5 -> V_17 && F_6 ( & V_5 -> V_14 ) )
V_5 -> V_17 = V_11 -> V_31 ;
F_7 ( V_7 , F_8 ( V_5 ) ) ;
}
int F_9 ( struct V_6 * V_7 , bool V_32 )
{
struct V_33 * V_25 = NULL ;
struct V_1 * V_34 , V_35 ;
struct V_36 * V_37 ;
struct V_38 * V_39 ;
struct V_8 * V_9 = F_4 ( V_7 ) ;
struct V_10 * V_11 = F_5 ( V_7 ) ;
struct V_4 V_5 ;
int V_40 = 0 ;
if ( V_11 -> V_41 && ( V_11 -> V_26 & V_42 ) ) {
V_25 = F_10 ( V_7 , V_11 -> V_26 ) ;
if ( ! V_25 )
return - V_43 ;
}
F_3 ( & V_5 , V_7 ) ;
F_11 () ;
V_37 = V_25 ? V_25 -> V_37 : F_12 ( V_11 -> V_37 ) ;
V_34 = F_13 ( & V_5 , V_37 , & V_35 ) ;
F_14 () ;
V_39 = F_15 ( V_7 , & V_5 , V_34 ) ;
if ( F_16 ( V_39 ) ) {
V_40 = F_17 ( V_39 ) ;
goto V_44;
}
if ( V_32 ) {
if ( F_18 ( & V_11 -> V_16 ) )
V_11 -> V_16 = V_5 . V_16 ;
if ( F_18 ( & V_7 -> V_45 ) ) {
V_7 -> V_45 = V_5 . V_16 ;
V_9 -> V_46 = V_47 ;
if ( V_7 -> V_48 -> V_49 )
V_7 -> V_48 -> V_49 ( V_7 ) ;
}
}
F_19 ( V_7 , V_39 ,
F_20 ( & V_5 . V_14 , & V_7 -> V_15 ) ?
& V_7 -> V_15 : NULL ,
#ifdef F_21
F_20 ( & V_5 . V_16 , & V_11 -> V_16 ) ?
& V_11 -> V_16 :
#endif
NULL ) ;
V_44:
F_22 ( V_25 ) ;
return V_40 ;
}
void F_23 ( struct V_6 * V_7 )
{
struct V_38 * V_39 ;
if ( F_2 ( & V_7 -> V_15 ) )
return;
F_11 () ;
V_39 = F_24 ( V_7 ) ;
if ( ! V_39 || ! V_39 -> V_50 ||
V_39 -> V_51 -> V_52 ( V_39 , F_5 ( V_7 ) -> V_53 ) ) {
F_14 () ;
return;
}
F_14 () ;
F_9 ( V_7 , false ) ;
}
int F_25 ( struct V_6 * V_7 , struct V_54 * V_55 ,
int V_56 )
{
struct V_57 * V_58 = (struct V_57 * ) V_55 ;
struct V_8 * V_9 = F_4 ( V_7 ) ;
struct V_10 * V_11 = F_5 ( V_7 ) ;
struct V_1 * V_14 ;
int V_59 ;
int V_40 ;
T_1 V_60 = 0 ;
if ( V_58 -> V_61 == V_62 ) {
if ( F_26 ( V_7 ) )
return - V_63 ;
V_40 = F_27 ( V_7 , V_55 , V_56 ) ;
goto V_64;
}
if ( V_56 < V_65 )
return - V_43 ;
if ( V_58 -> V_61 != V_66 )
return - V_63 ;
if ( V_11 -> V_41 )
V_60 = V_58 -> V_67 & V_68 ;
if ( F_18 ( & V_58 -> V_69 ) ) {
if ( F_2 ( & V_7 -> V_45 ) )
F_28 ( F_29 ( V_70 ) ,
& V_58 -> V_69 ) ;
else
V_58 -> V_69 = V_71 ;
}
V_59 = F_30 ( & V_58 -> V_69 ) ;
V_14 = & V_58 -> V_69 ;
if ( V_59 & V_72 ) {
struct V_73 sin ;
if ( F_26 ( V_7 ) ) {
V_40 = - V_74 ;
goto V_44;
}
sin . V_75 = V_62 ;
sin . V_76 . V_77 = V_14 -> V_3 [ 3 ] ;
sin . V_78 = V_58 -> V_79 ;
V_40 = F_27 ( V_7 ,
(struct V_54 * ) & sin ,
sizeof( sin ) ) ;
V_64:
if ( V_40 )
goto V_44;
F_28 ( V_9 -> V_80 , & V_7 -> V_15 ) ;
if ( F_18 ( & V_11 -> V_16 ) ||
F_1 ( & V_11 -> V_16 ) )
F_28 ( V_9 -> V_81 , & V_11 -> V_16 ) ;
if ( F_18 ( & V_7 -> V_45 ) ||
F_1 ( & V_7 -> V_45 ) ) {
F_28 ( V_9 -> V_46 ,
& V_7 -> V_45 ) ;
if ( V_7 -> V_48 -> V_49 )
V_7 -> V_48 -> V_49 ( V_7 ) ;
}
goto V_44;
}
if ( F_31 ( V_59 ) ) {
if ( V_56 >= sizeof( struct V_57 ) &&
V_58 -> V_82 ) {
if ( V_7 -> V_18 &&
V_7 -> V_18 != V_58 -> V_82 ) {
V_40 = - V_43 ;
goto V_44;
}
V_7 -> V_18 = V_58 -> V_82 ;
}
if ( ! V_7 -> V_18 && ( V_59 & V_83 ) )
V_7 -> V_18 = V_11 -> V_31 ;
if ( ! V_7 -> V_18 ) {
V_40 = - V_43 ;
goto V_44;
}
}
V_7 -> V_15 = * V_14 ;
V_11 -> V_26 = V_60 ;
V_9 -> V_22 = V_58 -> V_79 ;
V_40 = F_9 ( V_7 , true ) ;
if ( V_40 )
goto V_44;
V_7 -> V_84 = V_85 ;
F_32 ( V_7 ) ;
V_44:
return V_40 ;
}
int F_33 ( struct V_6 * V_7 , struct V_54 * V_55 , int V_56 )
{
int V_86 ;
F_34 ( V_7 ) ;
V_86 = F_25 ( V_7 , V_55 , V_56 ) ;
F_35 ( V_7 ) ;
return V_86 ;
}
int F_36 ( struct V_6 * V_7 , struct V_54 * V_55 ,
int V_56 )
{
F_37 ( struct V_57 * , V_87 , V_55 ) ;
if ( V_87 -> V_61 != V_66 )
return - V_63 ;
return F_33 ( V_7 , V_55 , V_56 ) ;
}
void F_38 ( struct V_6 * V_7 , struct V_88 * V_89 , int V_40 ,
T_2 V_90 , T_3 V_91 , T_4 * V_92 )
{
struct V_10 * V_11 = F_5 ( V_7 ) ;
struct V_93 * V_94 = F_39 ( V_89 ) ;
struct V_95 * V_96 ;
if ( ! V_11 -> V_97 )
return;
V_89 = F_40 ( V_89 , V_98 ) ;
if ( ! V_89 )
return;
V_89 -> V_99 = F_41 ( V_100 ) ;
V_96 = F_42 ( V_89 ) ;
V_96 -> V_101 . V_102 = V_40 ;
V_96 -> V_101 . V_103 = V_104 ;
V_96 -> V_101 . V_105 = V_94 -> V_106 ;
V_96 -> V_101 . V_107 = V_94 -> V_108 ;
V_96 -> V_101 . V_109 = 0 ;
V_96 -> V_101 . V_110 = V_91 ;
V_96 -> V_101 . V_111 = 0 ;
V_96 -> V_112 = ( T_4 * ) & ( ( (struct V_113 * ) ( V_94 + 1 ) ) -> V_14 ) -
F_43 ( V_89 ) ;
V_96 -> V_90 = V_90 ;
F_44 ( V_89 , V_92 - V_89 -> V_114 ) ;
F_45 ( V_89 ) ;
if ( F_46 ( V_7 , V_89 ) )
F_47 ( V_89 ) ;
}
void F_48 ( struct V_6 * V_7 , int V_40 , struct V_4 * V_5 , T_3 V_91 )
{
const struct V_10 * V_11 = F_5 ( V_7 ) ;
struct V_95 * V_96 ;
struct V_113 * V_115 ;
struct V_88 * V_89 ;
if ( ! V_11 -> V_97 )
return;
V_89 = F_49 ( sizeof( struct V_113 ) , V_98 ) ;
if ( ! V_89 )
return;
V_89 -> V_99 = F_41 ( V_100 ) ;
F_50 ( V_89 , sizeof( struct V_113 ) ) ;
F_51 ( V_89 ) ;
V_115 = F_52 ( V_89 ) ;
V_115 -> V_14 = V_5 -> V_14 ;
V_96 = F_42 ( V_89 ) ;
V_96 -> V_101 . V_102 = V_40 ;
V_96 -> V_101 . V_103 = V_116 ;
V_96 -> V_101 . V_105 = 0 ;
V_96 -> V_101 . V_107 = 0 ;
V_96 -> V_101 . V_109 = 0 ;
V_96 -> V_101 . V_110 = V_91 ;
V_96 -> V_101 . V_111 = 0 ;
V_96 -> V_112 = ( T_4 * ) & V_115 -> V_14 - F_43 ( V_89 ) ;
V_96 -> V_90 = V_5 -> V_21 ;
F_44 ( V_89 , F_53 ( V_89 ) - V_89 -> V_114 ) ;
F_45 ( V_89 ) ;
if ( F_46 ( V_7 , V_89 ) )
F_47 ( V_89 ) ;
}
void F_54 ( struct V_6 * V_7 , struct V_4 * V_5 , T_3 V_117 )
{
struct V_10 * V_11 = F_5 ( V_7 ) ;
struct V_113 * V_115 ;
struct V_88 * V_89 ;
struct V_118 * V_119 ;
if ( ! V_11 -> V_120 . V_121 . V_122 )
return;
V_89 = F_49 ( sizeof( struct V_113 ) , V_98 ) ;
if ( ! V_89 )
return;
F_50 ( V_89 , sizeof( struct V_113 ) ) ;
F_51 ( V_89 ) ;
V_115 = F_52 ( V_89 ) ;
V_115 -> V_14 = V_5 -> V_14 ;
V_119 = F_55 ( V_89 ) ;
V_119 -> V_123 = V_117 ;
V_119 -> V_124 . V_61 = V_66 ;
V_119 -> V_124 . V_79 = 0 ;
V_119 -> V_124 . V_67 = 0 ;
V_119 -> V_124 . V_82 = V_5 -> V_17 ;
V_119 -> V_124 . V_69 = F_52 ( V_89 ) -> V_14 ;
F_44 ( V_89 , F_53 ( V_89 ) - V_89 -> V_114 ) ;
F_45 ( V_89 ) ;
V_89 = F_56 ( & V_11 -> V_122 , V_89 ) ;
F_47 ( V_89 ) ;
}
static inline bool F_57 ( struct V_95 * V_96 )
{
return V_96 -> V_101 . V_103 == V_104 ||
V_96 -> V_101 . V_103 == V_125 ||
V_96 -> V_101 . V_103 == V_116 || V_96 -> V_90 ;
}
static bool F_58 ( struct V_88 * V_89 ,
struct V_95 * V_96 )
{
if ( V_96 -> V_101 . V_103 == V_125 ||
V_96 -> V_101 . V_103 == V_104 )
return true ;
if ( V_96 -> V_101 . V_103 == V_116 )
return false ;
if ( ! V_89 -> V_126 )
return false ;
if ( V_89 -> V_99 == F_41 ( V_100 ) )
F_59 ( V_89 ) -> V_127 = V_89 -> V_126 -> V_128 ;
else
F_60 ( V_89 ) -> V_129 = V_89 -> V_126 -> V_128 ;
return true ;
}
int F_61 ( struct V_6 * V_7 , struct V_130 * V_131 , int V_132 , int * V_56 )
{
struct V_10 * V_11 = F_5 ( V_7 ) ;
struct V_95 * V_96 ;
struct V_88 * V_89 ;
F_37 ( struct V_57 * , sin , V_131 -> V_133 ) ;
struct {
struct V_134 V_101 ;
struct V_57 V_135 ;
} V_136 ;
int V_40 ;
int V_137 ;
V_40 = - V_138 ;
V_89 = F_62 ( V_7 ) ;
if ( ! V_89 )
goto V_44;
V_137 = V_89 -> V_132 ;
if ( V_137 > V_132 ) {
V_131 -> V_139 |= V_140 ;
V_137 = V_132 ;
}
V_40 = F_63 ( V_89 , 0 , V_131 , V_137 ) ;
if ( F_64 ( V_40 ) ) {
F_47 ( V_89 ) ;
return V_40 ;
}
F_65 ( V_131 , V_7 , V_89 ) ;
V_96 = F_42 ( V_89 ) ;
if ( sin && F_57 ( V_96 ) ) {
const unsigned char * V_141 = F_43 ( V_89 ) ;
sin -> V_61 = V_66 ;
sin -> V_67 = 0 ;
sin -> V_79 = V_96 -> V_90 ;
if ( V_89 -> V_99 == F_41 ( V_100 ) ) {
const struct V_113 * V_142 = F_66 ( (struct V_1 * ) ( V_141 + V_96 -> V_112 ) ,
struct V_113 , V_14 ) ;
sin -> V_69 = V_142 -> V_14 ;
if ( V_11 -> V_41 )
sin -> V_67 = F_67 ( V_142 ) ;
sin -> V_82 =
F_68 ( & sin -> V_69 ,
F_59 ( V_89 ) -> V_127 ) ;
} else {
F_28 ( * ( T_1 * ) ( V_141 + V_96 -> V_112 ) ,
& sin -> V_69 ) ;
sin -> V_82 = 0 ;
}
* V_56 = sizeof( * sin ) ;
}
memcpy ( & V_136 . V_101 , & V_96 -> V_101 , sizeof( struct V_134 ) ) ;
sin = & V_136 . V_135 ;
memset ( sin , 0 , sizeof( * sin ) ) ;
if ( F_58 ( V_89 , V_96 ) ) {
sin -> V_61 = V_66 ;
if ( V_11 -> V_120 . V_143 )
F_69 ( V_7 , V_131 , V_89 ) ;
if ( V_89 -> V_99 == F_41 ( V_100 ) ) {
sin -> V_69 = F_52 ( V_89 ) -> V_16 ;
if ( V_11 -> V_120 . V_143 )
F_70 ( V_7 , V_131 , V_89 ) ;
sin -> V_82 =
F_68 ( & sin -> V_69 ,
F_59 ( V_89 ) -> V_127 ) ;
} else {
F_28 ( F_71 ( V_89 ) -> V_16 ,
& sin -> V_69 ) ;
if ( F_4 ( V_7 ) -> V_144 )
F_72 ( V_131 , V_89 ) ;
}
}
F_73 ( V_131 , V_145 , V_146 , sizeof( V_136 ) , & V_136 ) ;
V_131 -> V_139 |= V_147 ;
V_40 = V_137 ;
F_74 ( V_89 ) ;
V_44:
return V_40 ;
}
int F_75 ( struct V_6 * V_7 , struct V_130 * V_131 , int V_132 ,
int * V_56 )
{
struct V_10 * V_11 = F_5 ( V_7 ) ;
struct V_88 * V_89 ;
struct V_118 V_119 ;
F_37 ( struct V_57 * , sin , V_131 -> V_133 ) ;
int V_40 ;
int V_137 ;
V_40 = - V_138 ;
V_89 = F_56 ( & V_11 -> V_122 , NULL ) ;
if ( ! V_89 )
goto V_44;
V_137 = V_89 -> V_132 ;
if ( V_137 > V_132 ) {
V_131 -> V_139 |= V_140 ;
V_137 = V_132 ;
}
V_40 = F_63 ( V_89 , 0 , V_131 , V_137 ) ;
if ( V_40 )
goto V_148;
F_65 ( V_131 , V_7 , V_89 ) ;
memcpy ( & V_119 , F_55 ( V_89 ) , sizeof( V_119 ) ) ;
if ( sin ) {
sin -> V_61 = V_66 ;
sin -> V_67 = 0 ;
sin -> V_79 = 0 ;
sin -> V_82 = V_119 . V_124 . V_82 ;
sin -> V_69 = V_119 . V_124 . V_69 ;
* V_56 = sizeof( * sin ) ;
}
F_73 ( V_131 , V_145 , V_149 , sizeof( V_119 ) , & V_119 ) ;
V_40 = V_137 ;
V_148:
F_47 ( V_89 ) ;
V_44:
return V_40 ;
}
void F_69 ( struct V_6 * V_7 , struct V_130 * V_131 ,
struct V_88 * V_89 )
{
struct V_10 * V_11 = F_5 ( V_7 ) ;
bool V_150 = V_89 -> V_99 == F_41 ( V_100 ) ;
if ( V_11 -> V_120 . V_121 . V_151 ) {
struct V_152 V_153 ;
if ( V_150 ) {
V_153 . V_30 = F_59 ( V_89 ) -> V_127 ;
V_153 . V_154 = F_52 ( V_89 ) -> V_14 ;
} else {
V_153 . V_30 =
F_60 ( V_89 ) -> V_129 ;
F_28 ( F_71 ( V_89 ) -> V_14 ,
& V_153 . V_154 ) ;
}
if ( V_153 . V_30 >= 0 )
F_73 ( V_131 , V_145 , V_155 ,
sizeof( V_153 ) , & V_153 ) ;
}
}
void F_70 ( struct V_6 * V_7 , struct V_130 * V_131 ,
struct V_88 * V_89 )
{
struct V_10 * V_11 = F_5 ( V_7 ) ;
struct V_156 * V_37 = F_59 ( V_89 ) ;
unsigned char * V_141 = F_43 ( V_89 ) ;
if ( V_11 -> V_120 . V_121 . V_157 ) {
int V_158 = F_52 ( V_89 ) -> V_159 ;
F_73 ( V_131 , V_145 , V_160 , sizeof( V_158 ) , & V_158 ) ;
}
if ( V_11 -> V_120 . V_121 . V_161 ) {
int V_162 = F_76 ( F_52 ( V_89 ) ) ;
F_73 ( V_131 , V_145 , V_163 , sizeof( V_162 ) , & V_162 ) ;
}
if ( V_11 -> V_120 . V_121 . V_164 ) {
T_1 V_165 = F_67 ( (struct V_113 * ) V_141 ) ;
if ( V_165 )
F_73 ( V_131 , V_145 , V_166 , sizeof( V_165 ) , & V_165 ) ;
}
if ( V_11 -> V_120 . V_121 . V_167 && ( V_37 -> V_168 & V_169 ) ) {
T_4 * V_170 = V_141 + sizeof( struct V_113 ) ;
F_73 ( V_131 , V_145 , V_171 , ( V_170 [ 1 ] + 1 ) << 3 , V_170 ) ;
}
if ( V_37 -> V_172 &&
( V_11 -> V_120 . V_121 . V_173 || V_11 -> V_120 . V_121 . V_174 ) ) {
unsigned int V_175 = sizeof( struct V_113 ) ;
T_4 V_176 = F_52 ( V_89 ) -> V_176 ;
while ( V_175 <= V_37 -> V_172 ) {
unsigned int V_132 ;
T_4 * V_170 = V_141 + V_175 ;
switch ( V_176 ) {
case V_177 :
V_176 = V_170 [ 0 ] ;
V_132 = ( V_170 [ 1 ] + 1 ) << 3 ;
if ( V_11 -> V_120 . V_121 . V_173 )
F_73 ( V_131 , V_145 , V_178 , V_132 , V_170 ) ;
break;
case V_179 :
V_176 = V_170 [ 0 ] ;
V_132 = ( V_170 [ 1 ] + 1 ) << 3 ;
if ( V_11 -> V_120 . V_121 . V_174 )
F_73 ( V_131 , V_145 , V_180 , V_132 , V_170 ) ;
break;
case V_181 :
V_176 = V_170 [ 0 ] ;
V_132 = ( V_170 [ 1 ] + 2 ) << 2 ;
break;
default:
V_176 = V_170 [ 0 ] ;
V_132 = ( V_170 [ 1 ] + 1 ) << 3 ;
break;
}
V_175 += V_132 ;
}
}
if ( V_11 -> V_120 . V_121 . V_182 ) {
struct V_152 V_153 ;
V_153 . V_30 = V_37 -> V_127 ;
V_153 . V_154 = F_52 ( V_89 ) -> V_14 ;
F_73 ( V_131 , V_145 , V_183 , sizeof( V_153 ) , & V_153 ) ;
}
if ( V_11 -> V_120 . V_121 . V_184 ) {
int V_158 = F_52 ( V_89 ) -> V_159 ;
F_73 ( V_131 , V_145 , V_185 , sizeof( V_158 ) , & V_158 ) ;
}
if ( V_11 -> V_120 . V_121 . V_186 && ( V_37 -> V_168 & V_169 ) ) {
T_4 * V_170 = V_141 + sizeof( struct V_113 ) ;
F_73 ( V_131 , V_145 , V_187 , ( V_170 [ 1 ] + 1 ) << 3 , V_170 ) ;
}
if ( V_11 -> V_120 . V_121 . V_188 && V_37 -> V_189 ) {
T_4 * V_170 = V_141 + V_37 -> V_189 ;
F_73 ( V_131 , V_145 , V_190 , ( V_170 [ 1 ] + 1 ) << 3 , V_170 ) ;
}
if ( V_11 -> V_120 . V_121 . V_191 && V_37 -> V_174 ) {
struct V_192 * V_193 = (struct V_192 * ) ( V_141 + V_37 -> V_174 ) ;
F_73 ( V_131 , V_145 , V_194 , ( V_193 -> V_195 + 1 ) << 3 , V_193 ) ;
}
if ( V_11 -> V_120 . V_121 . V_188 && V_37 -> V_196 ) {
T_4 * V_170 = V_141 + V_37 -> V_196 ;
F_73 ( V_131 , V_145 , V_190 , ( V_170 [ 1 ] + 1 ) << 3 , V_170 ) ;
}
if ( V_11 -> V_120 . V_121 . V_197 ) {
struct V_57 V_87 ;
T_2 * V_198 = ( T_2 * ) F_77 ( V_89 ) ;
if ( F_78 ( V_89 ) + 4 <= ( int ) V_89 -> V_132 ) {
V_87 . V_61 = V_66 ;
V_87 . V_69 = F_52 ( V_89 ) -> V_14 ;
V_87 . V_79 = V_198 [ 1 ] ;
V_87 . V_67 = 0 ;
V_87 . V_82 =
F_68 ( & F_52 ( V_89 ) -> V_14 ,
V_37 -> V_127 ) ;
F_73 ( V_131 , V_145 , V_199 , sizeof( V_87 ) , & V_87 ) ;
}
}
if ( V_11 -> V_120 . V_121 . V_200 && V_37 -> V_201 ) {
int V_202 = V_37 -> V_201 ;
F_73 ( V_131 , V_145 , V_203 , sizeof( V_202 ) , & V_202 ) ;
}
}
void F_79 ( struct V_6 * V_7 , struct V_130 * V_131 ,
struct V_88 * V_89 )
{
F_69 ( V_7 , V_131 , V_89 ) ;
F_70 ( V_7 , V_131 , V_89 ) ;
}
int F_80 ( struct V_204 * V_204 , struct V_6 * V_7 ,
struct V_130 * V_131 , struct V_4 * V_5 ,
struct V_205 * V_206 , struct V_207 * V_208 )
{
struct V_152 * V_153 ;
struct V_209 * V_210 ;
struct V_192 * V_193 ;
struct V_211 * V_212 ;
struct V_36 * V_37 = V_206 -> V_37 ;
int V_132 ;
int V_40 = 0 ;
F_81 (cmsg, msg) {
int V_59 ;
if ( ! F_82 ( V_131 , V_210 ) ) {
V_40 = - V_43 ;
goto V_213;
}
if ( V_210 -> V_214 == V_215 ) {
V_40 = F_83 ( V_7 , V_131 , V_210 , V_208 ) ;
if ( V_40 )
return V_40 ;
continue;
}
if ( V_210 -> V_214 != V_145 )
continue;
switch ( V_210 -> V_216 ) {
case V_155 :
case V_183 :
{
struct V_217 * V_126 = NULL ;
if ( V_210 -> V_218 < F_84 ( sizeof( struct V_152 ) ) ) {
V_40 = - V_43 ;
goto V_213;
}
V_153 = (struct V_152 * ) F_85 ( V_210 ) ;
if ( V_153 -> V_30 ) {
if ( V_5 -> V_17 &&
V_153 -> V_30 != V_5 -> V_17 )
return - V_43 ;
V_5 -> V_17 = V_153 -> V_30 ;
}
V_59 = F_86 ( & V_153 -> V_154 ) ;
F_11 () ;
if ( V_5 -> V_17 ) {
V_126 = F_87 ( V_204 , V_5 -> V_17 ) ;
if ( ! V_126 ) {
F_14 () ;
return - V_219 ;
}
} else if ( V_59 & V_220 ) {
F_14 () ;
return - V_43 ;
}
if ( V_59 != V_221 ) {
int V_222 = F_88 ( V_59 ) <= V_223 ;
if ( ! ( F_4 ( V_7 ) -> V_224 || F_4 ( V_7 ) -> V_225 ) &&
! F_89 ( V_204 , & V_153 -> V_154 ,
V_222 ? V_126 : NULL , 0 ) &&
! F_90 ( V_204 , V_126 ,
& V_153 -> V_154 ) )
V_40 = - V_43 ;
else
V_5 -> V_16 = V_153 -> V_154 ;
}
F_14 () ;
if ( V_40 )
goto V_213;
break;
}
case V_166 :
if ( V_210 -> V_218 < F_84 ( 4 ) ) {
V_40 = - V_43 ;
goto V_213;
}
if ( V_5 -> V_25 & V_68 ) {
if ( ( V_5 -> V_25 ^ * ( T_1 * ) F_85 ( V_210 ) ) & ~ V_68 ) {
V_40 = - V_43 ;
goto V_213;
}
}
V_5 -> V_25 = V_68 & * ( T_1 * ) F_85 ( V_210 ) ;
break;
case V_187 :
case V_171 :
if ( V_37 -> V_226 || V_210 -> V_218 < F_84 ( sizeof( struct V_211 ) ) ) {
V_40 = - V_43 ;
goto V_213;
}
V_212 = (struct V_211 * ) F_85 ( V_210 ) ;
V_132 = ( ( V_212 -> V_195 + 1 ) << 3 ) ;
if ( V_210 -> V_218 < F_84 ( V_132 ) ) {
V_40 = - V_43 ;
goto V_213;
}
if ( ! F_91 ( V_204 -> V_227 , V_228 ) ) {
V_40 = - V_229 ;
goto V_213;
}
V_37 -> V_230 += V_132 ;
V_37 -> V_226 = V_212 ;
break;
case V_190 :
if ( V_210 -> V_218 < F_84 ( sizeof( struct V_211 ) ) ) {
V_40 = - V_43 ;
goto V_213;
}
V_212 = (struct V_211 * ) F_85 ( V_210 ) ;
V_132 = ( ( V_212 -> V_195 + 1 ) << 3 ) ;
if ( V_210 -> V_218 < F_84 ( V_132 ) ) {
V_40 = - V_43 ;
goto V_213;
}
if ( ! F_91 ( V_204 -> V_227 , V_228 ) ) {
V_40 = - V_229 ;
goto V_213;
}
if ( V_37 -> V_231 ) {
V_40 = - V_43 ;
goto V_213;
}
V_37 -> V_232 += V_132 ;
V_37 -> V_231 = V_212 ;
break;
case V_178 :
case V_233 :
if ( V_210 -> V_218 < F_84 ( sizeof( struct V_211 ) ) ) {
V_40 = - V_43 ;
goto V_213;
}
V_212 = (struct V_211 * ) F_85 ( V_210 ) ;
V_132 = ( ( V_212 -> V_195 + 1 ) << 3 ) ;
if ( V_210 -> V_218 < F_84 ( V_132 ) ) {
V_40 = - V_43 ;
goto V_213;
}
if ( ! F_91 ( V_204 -> V_227 , V_228 ) ) {
V_40 = - V_229 ;
goto V_213;
}
if ( V_210 -> V_216 == V_178 ) {
V_37 -> V_232 += V_132 ;
V_37 -> V_231 = V_212 ;
} else {
V_37 -> V_230 += V_132 ;
V_37 -> V_234 = V_212 ;
}
break;
case V_194 :
case V_180 :
if ( V_210 -> V_218 < F_84 ( sizeof( struct V_192 ) ) ) {
V_40 = - V_43 ;
goto V_213;
}
V_193 = (struct V_192 * ) F_85 ( V_210 ) ;
switch ( V_193 -> type ) {
#if F_92 ( V_235 )
case V_236 :
if ( V_193 -> V_195 != 2 ||
V_193 -> V_237 != 1 ) {
V_40 = - V_43 ;
goto V_213;
}
break;
#endif
default:
V_40 = - V_43 ;
goto V_213;
}
V_132 = ( ( V_193 -> V_195 + 1 ) << 3 ) ;
if ( V_210 -> V_218 < F_84 ( V_132 ) ) {
V_40 = - V_43 ;
goto V_213;
}
if ( ( V_193 -> V_195 >> 1 ) != V_193 -> V_237 ) {
V_40 = - V_43 ;
goto V_213;
}
V_37 -> V_230 += V_132 ;
V_37 -> V_174 = V_193 ;
if ( V_210 -> V_216 == V_194 && V_37 -> V_231 ) {
int V_238 = ( ( V_37 -> V_231 -> V_195 + 1 ) << 3 ) ;
V_37 -> V_230 += V_238 ;
V_37 -> V_234 = V_37 -> V_231 ;
V_37 -> V_231 = NULL ;
V_37 -> V_232 -= V_238 ;
}
break;
case V_185 :
case V_160 :
if ( V_210 -> V_218 != F_84 ( sizeof( int ) ) ) {
V_40 = - V_43 ;
goto V_213;
}
V_206 -> V_239 = * ( int * ) F_85 ( V_210 ) ;
if ( V_206 -> V_239 < - 1 || V_206 -> V_239 > 0xff ) {
V_40 = - V_43 ;
goto V_213;
}
break;
case V_163 :
{
int V_240 ;
V_40 = - V_43 ;
if ( V_210 -> V_218 != F_84 ( sizeof( int ) ) )
goto V_213;
V_240 = * ( int * ) F_85 ( V_210 ) ;
if ( V_240 < - 1 || V_240 > 0xff )
goto V_213;
V_40 = 0 ;
V_206 -> V_162 = V_240 ;
break;
}
case V_241 :
{
int V_242 ;
V_40 = - V_43 ;
if ( V_210 -> V_218 != F_84 ( sizeof( int ) ) )
goto V_213;
V_242 = * ( int * ) F_85 ( V_210 ) ;
if ( V_242 < 0 || V_242 > 1 )
goto V_213;
V_40 = 0 ;
V_206 -> V_243 = V_242 ;
break;
}
default:
F_93 ( L_1 ,
V_210 -> V_216 ) ;
V_40 = - V_43 ;
goto V_213;
}
}
V_213:
return V_40 ;
}
void F_94 ( struct V_244 * V_245 , struct V_6 * V_246 ,
T_5 V_247 , T_5 V_248 , int V_249 )
{
const struct V_1 * V_250 , * V_251 ;
V_250 = & V_246 -> V_15 ;
V_251 = & V_246 -> V_45 ;
F_95 ( V_245 ,
L_2
L_3 ,
V_249 ,
V_251 -> V_3 [ 0 ] , V_251 -> V_3 [ 1 ] ,
V_251 -> V_3 [ 2 ] , V_251 -> V_3 [ 3 ] , V_247 ,
V_250 -> V_3 [ 0 ] , V_250 -> V_3 [ 1 ] ,
V_250 -> V_3 [ 2 ] , V_250 -> V_3 [ 3 ] , V_248 ,
V_246 -> V_84 ,
F_96 ( V_246 ) ,
F_97 ( V_246 ) ,
0 , 0L , 0 ,
F_98 ( F_99 ( V_245 ) , F_100 ( V_246 ) ) ,
0 ,
F_101 ( V_246 ) ,
F_102 ( & V_246 -> V_252 ) , V_246 ,
F_102 ( & V_246 -> V_253 ) ) ;
}
