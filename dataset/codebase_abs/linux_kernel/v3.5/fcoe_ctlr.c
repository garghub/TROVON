static const char * F_1 ( enum V_1 V_2 )
{
const char * V_3 = L_1 ;
if ( V_2 < F_2 ( V_4 ) )
V_3 = V_4 [ V_2 ] ;
if ( ! V_3 )
V_3 = L_1 ;
return V_3 ;
}
static void F_3 ( struct V_5 * V_6 , enum V_1 V_2 )
{
if ( V_2 == V_6 -> V_2 )
return;
if ( V_6 -> V_7 )
F_4 ( V_6 , L_2 ,
F_1 ( V_6 -> V_2 ) , F_1 ( V_2 ) ) ;
V_6 -> V_2 = V_2 ;
}
static inline int F_5 ( const struct V_8 * V_9 )
{
return ( V_9 -> V_10 & V_11 ) != 0 ;
}
static inline int F_6 ( struct V_8 * V_9 )
{
T_1 V_10 = V_11 | V_12 ;
return ( V_9 -> V_10 & V_10 ) == V_10 ;
}
static void F_7 ( struct V_5 * V_6 )
{
if ( V_6 -> V_13 == V_14 )
F_8 ( V_6 -> V_15 , V_16 ) ;
else
F_8 ( V_6 -> V_15 , V_17 ) ;
F_8 ( V_6 -> V_15 + 3 , 0 ) ;
V_6 -> V_18 = 1 ;
}
void F_9 ( struct V_5 * V_6 , enum V_1 V_13 )
{
F_3 ( V_6 , V_19 ) ;
V_6 -> V_13 = V_13 ;
F_10 ( & V_6 -> V_20 ) ;
F_11 ( & V_6 -> V_21 ) ;
F_12 ( & V_6 -> V_22 ) ;
V_6 -> V_23 = V_24 ;
F_13 ( & V_6 -> V_25 , V_26 , ( unsigned long ) V_6 ) ;
F_14 ( & V_6 -> V_27 , V_28 ) ;
F_14 ( & V_6 -> V_29 , V_30 ) ;
F_15 ( & V_6 -> V_31 ) ;
}
static int F_16 ( struct V_8 * V_32 )
{
struct V_5 * V_6 = V_32 -> V_6 ;
struct V_33 * V_34 = F_17 ( V_6 ) ;
struct V_35 V_36 , * V_37 ;
int V_38 = 0 ;
F_4 ( V_6 , L_3 ,
V_32 -> V_39 , V_32 -> V_40 ) ;
F_18 ( & V_34 -> V_41 ) ;
V_36 . V_39 = V_32 -> V_39 ;
V_36 . V_42 = V_32 -> V_42 ;
V_36 . V_43 = V_32 -> V_43 ;
V_36 . V_44 = V_32 -> V_44 ;
memcpy ( V_36 . V_45 , V_32 -> V_40 , V_46 ) ;
V_36 . V_47 = V_32 -> V_48 ;
V_36 . V_49 = V_32 -> V_49 ;
V_36 . V_50 = 0 ;
V_37 = F_19 ( V_34 , & V_36 ) ;
if ( F_20 ( ! V_37 ) ) {
V_38 = - V_51 ;
goto V_52;
}
F_21 ( V_37 -> V_53 ) ;
V_37 -> V_53 = V_32 ;
V_32 -> V_37 = V_37 ;
F_22 ( & V_32 -> V_54 , & V_6 -> V_20 ) ;
V_6 -> V_55 ++ ;
V_52:
F_23 ( & V_34 -> V_41 ) ;
return V_38 ;
}
static void F_24 ( struct V_8 * V_32 )
{
struct V_5 * V_6 = V_32 -> V_6 ;
struct V_33 * V_34 = F_17 ( V_6 ) ;
struct V_35 * V_37 ;
F_25 ( & V_32 -> V_54 ) ;
V_6 -> V_55 -- ;
F_18 ( & V_34 -> V_41 ) ;
V_37 = F_26 ( V_32 ) ;
F_27 ( ! V_37 ) ;
V_32 -> V_37 = NULL ;
F_28 ( V_37 ) ;
F_29 ( V_32 ) ;
F_23 ( & V_34 -> V_41 ) ;
}
static void F_30 ( struct V_5 * V_6 )
{
struct V_8 * V_9 ;
struct V_8 * V_56 ;
V_6 -> V_57 = NULL ;
F_31 (fcf, next, &fip->fcfs, list) {
F_24 ( V_9 ) ;
}
F_27 ( V_6 -> V_55 ) ;
V_6 -> V_58 = 0 ;
}
void F_32 ( struct V_5 * V_6 )
{
F_33 ( & V_6 -> V_29 ) ;
F_34 ( & V_6 -> V_31 ) ;
F_18 ( & V_6 -> V_21 ) ;
F_3 ( V_6 , V_59 ) ;
F_30 ( V_6 ) ;
F_23 ( & V_6 -> V_21 ) ;
F_35 ( & V_6 -> V_25 ) ;
F_33 ( & V_6 -> V_27 ) ;
}
static void F_36 ( struct V_5 * V_6 )
{
struct V_8 * V_60 ;
struct V_8 * V_9 ;
F_18 ( & V_6 -> V_21 ) ;
F_37 ( & V_6 -> V_22 ) ;
F_38 ( V_6 -> V_61 ) ;
V_6 -> V_61 = NULL ;
F_39 (fcf, &fip->fcfs, list)
V_9 -> V_62 = 0 ;
F_40 ( & V_6 -> V_22 ) ;
V_60 = V_6 -> V_57 ;
if ( V_60 && ! F_41 ( V_60 -> V_40 , V_6 -> V_15 ) )
goto V_63;
if ( ! F_42 ( V_6 -> V_15 ) ) {
F_43 ( V_64 L_4
L_5 ,
V_6 -> V_7 -> V_65 -> V_66 , V_6 -> V_15 ) ;
memset ( V_6 -> V_15 , 0 , V_46 ) ;
}
if ( V_60 ) {
F_43 ( V_67 L_6
L_7 ,
V_6 -> V_7 -> V_65 -> V_66 , V_60 -> V_40 ) ;
memcpy ( V_6 -> V_15 , V_60 -> V_68 , V_46 ) ;
V_6 -> V_18 = 0 ;
}
V_63:
F_23 ( & V_6 -> V_21 ) ;
}
static inline T_2 F_44 ( struct V_5 * V_6 )
{
return V_6 -> V_7 -> V_69 + sizeof( struct V_70 ) +
sizeof( struct V_71 ) + sizeof( struct V_72 ) ;
}
static void F_45 ( struct V_5 * V_6 , struct V_8 * V_9 )
{
struct V_73 * V_74 ;
struct V_75 {
struct V_76 V_77 ;
struct V_78 V_6 ;
struct {
struct V_79 V_45 ;
struct V_80 V_81 ;
struct V_82 V_83 ;
} V_84 V_85 ;
} V_84 * V_86 ;
T_2 V_87 ;
V_74 = F_46 ( sizeof( * V_86 ) ) ;
if ( ! V_74 )
return;
V_86 = (struct V_75 * ) V_74 -> V_88 ;
memset ( V_86 , 0 , sizeof( * V_86 ) ) ;
memcpy ( V_86 -> V_77 . V_89 , V_9 ? V_9 -> V_40 : V_90 , V_46 ) ;
memcpy ( V_86 -> V_77 . V_91 , V_6 -> V_92 , V_46 ) ;
V_86 -> V_77 . V_93 = F_47 ( V_94 ) ;
V_86 -> V_6 . V_95 = F_48 ( V_96 ) ;
V_86 -> V_6 . V_97 = F_47 ( V_98 ) ;
V_86 -> V_6 . V_99 = V_100 ;
V_86 -> V_6 . V_101 = F_47 ( sizeof( V_86 -> V_85 ) / V_102 ) ;
V_86 -> V_6 . V_103 = F_47 ( V_104 ) ;
if ( V_6 -> V_105 )
V_86 -> V_6 . V_103 |= F_47 ( V_106 ) ;
V_86 -> V_85 . V_45 . V_107 . V_108 = V_109 ;
V_86 -> V_85 . V_45 . V_107 . V_110 = sizeof( V_86 -> V_85 . V_45 ) / V_102 ;
memcpy ( V_86 -> V_85 . V_45 . V_111 , V_6 -> V_92 , V_46 ) ;
V_86 -> V_85 . V_81 . V_107 . V_108 = V_112 ;
V_86 -> V_85 . V_81 . V_107 . V_110 = sizeof( V_86 -> V_85 . V_81 ) / V_102 ;
F_49 ( V_6 -> V_7 -> V_81 , & V_86 -> V_85 . V_81 . V_113 ) ;
V_87 = F_44 ( V_6 ) ;
V_86 -> V_85 . V_83 . V_107 . V_108 = V_114 ;
V_86 -> V_85 . V_83 . V_107 . V_110 = sizeof( V_86 -> V_85 . V_83 ) / V_102 ;
V_86 -> V_85 . V_83 . V_115 = F_47 ( V_87 ) ;
F_50 ( V_74 , sizeof( * V_86 ) ) ;
V_74 -> V_116 = F_47 ( V_94 ) ;
V_74 -> V_47 = V_6 -> V_47 ;
F_51 ( V_74 ) ;
F_52 ( V_74 ) ;
V_6 -> V_117 ( V_6 , V_74 ) ;
if ( ! V_9 )
V_6 -> V_118 = V_119 ;
}
void F_53 ( struct V_5 * V_6 )
{
F_18 ( & V_6 -> V_21 ) ;
if ( V_6 -> V_2 == V_120 || V_6 -> V_2 == V_121 ) {
F_23 ( & V_6 -> V_21 ) ;
F_54 ( V_6 -> V_7 ) ;
} else if ( V_6 -> V_2 == V_19 ) {
F_3 ( V_6 , V_6 -> V_13 ) ;
switch ( V_6 -> V_13 ) {
default:
F_4 ( V_6 , L_8 , V_6 -> V_13 ) ;
case V_122 :
F_4 ( V_6 , L_9 , L_10 ) ;
case V_123 :
case V_124 :
F_23 ( & V_6 -> V_21 ) ;
F_54 ( V_6 -> V_7 ) ;
F_45 ( V_6 , NULL ) ;
break;
case V_14 :
F_55 ( V_6 ) ;
F_23 ( & V_6 -> V_21 ) ;
F_54 ( V_6 -> V_7 ) ;
break;
}
} else
F_23 ( & V_6 -> V_21 ) ;
}
static void F_56 ( struct V_5 * V_6 )
{
F_30 ( V_6 ) ;
F_57 ( & V_6 -> V_25 ) ;
V_6 -> V_125 = 0 ;
V_6 -> V_126 = 0 ;
V_6 -> V_118 = 0 ;
V_6 -> V_23 = V_24 ;
F_7 ( V_6 ) ;
}
int F_58 ( struct V_5 * V_6 )
{
int V_127 ;
F_4 ( V_6 , L_11 ) ;
F_18 ( & V_6 -> V_21 ) ;
F_56 ( V_6 ) ;
V_127 = V_6 -> V_2 != V_19 ;
F_3 ( V_6 , V_19 ) ;
F_23 ( & V_6 -> V_21 ) ;
if ( V_127 )
F_59 ( V_6 -> V_7 ) ;
return V_127 ;
}
static void F_60 ( struct V_5 * V_6 ,
struct V_128 * V_129 ,
int V_130 , T_3 * V_131 )
{
struct V_73 * V_74 ;
struct V_132 {
struct V_76 V_77 ;
struct V_78 V_6 ;
struct V_79 V_45 ;
} V_84 * V_133 ;
struct V_134 * V_135 ;
T_2 V_136 ;
struct V_128 * V_7 ;
struct V_8 * V_9 ;
V_9 = V_6 -> V_57 ;
V_7 = V_6 -> V_7 ;
if ( ! V_9 || ( V_130 && ! V_7 -> V_137 ) )
return;
V_136 = sizeof( * V_133 ) + V_130 * sizeof( * V_135 ) ;
V_74 = F_46 ( V_136 ) ;
if ( ! V_74 )
return;
V_133 = (struct V_132 * ) V_74 -> V_88 ;
memset ( V_133 , 0 , V_136 ) ;
memcpy ( V_133 -> V_77 . V_89 , V_9 -> V_40 , V_46 ) ;
memcpy ( V_133 -> V_77 . V_91 , V_131 , V_46 ) ;
V_133 -> V_77 . V_93 = F_47 ( V_94 ) ;
V_133 -> V_6 . V_95 = F_48 ( V_96 ) ;
V_133 -> V_6 . V_97 = F_47 ( V_138 ) ;
V_133 -> V_6 . V_99 = V_139 ;
V_133 -> V_6 . V_101 = F_47 ( ( sizeof( V_133 -> V_45 ) +
V_130 * sizeof( * V_135 ) ) / V_102 ) ;
V_133 -> V_6 . V_103 = F_47 ( V_104 ) ;
if ( V_6 -> V_105 )
V_133 -> V_6 . V_103 |= F_47 ( V_106 ) ;
V_133 -> V_45 . V_107 . V_108 = V_109 ;
V_133 -> V_45 . V_107 . V_110 = sizeof( V_133 -> V_45 ) / V_102 ;
memcpy ( V_133 -> V_45 . V_111 , V_6 -> V_92 , V_46 ) ;
if ( V_130 ) {
V_135 = (struct V_134 * ) ( V_133 + 1 ) ;
V_135 -> V_107 . V_108 = V_140 ;
V_135 -> V_107 . V_110 = sizeof( * V_135 ) / V_102 ;
memcpy ( V_135 -> V_111 , V_6 -> V_141 ( V_129 ) , V_46 ) ;
F_8 ( V_135 -> V_142 , V_129 -> V_137 ) ;
F_49 ( V_129 -> V_143 , & V_135 -> V_144 ) ;
}
F_50 ( V_74 , V_136 ) ;
V_74 -> V_116 = F_47 ( V_94 ) ;
V_74 -> V_47 = V_6 -> V_47 ;
F_51 ( V_74 ) ;
F_52 ( V_74 ) ;
V_6 -> V_117 ( V_6 , V_74 ) ;
}
static int F_61 ( struct V_5 * V_6 , struct V_128 * V_129 ,
T_3 V_145 , struct V_73 * V_74 , T_2 V_146 )
{
struct V_147 {
struct V_76 V_77 ;
struct V_78 V_6 ;
struct V_148 V_149 ;
} V_84 * V_150 ;
struct V_70 * V_151 ;
struct V_79 * V_45 ;
struct V_8 * V_9 ;
T_4 V_152 ;
T_1 V_103 ;
T_3 V_153 ;
V_151 = (struct V_70 * ) V_74 -> V_88 ;
V_153 = * ( T_3 * ) ( V_151 + 1 ) ;
V_152 = sizeof( struct V_148 ) + V_74 -> V_136 ;
V_150 = (struct V_147 * ) F_62 ( V_74 , sizeof( * V_150 ) ) ;
memset ( V_150 , 0 , sizeof( * V_150 ) ) ;
if ( V_129 -> V_154 ) {
if ( F_63 ( V_6 , V_146 , V_150 -> V_77 . V_89 ) )
return - V_155 ;
V_103 = 0 ;
} else {
V_9 = V_6 -> V_57 ;
if ( ! V_9 )
return - V_155 ;
V_103 = V_9 -> V_10 ;
V_103 &= V_6 -> V_105 ? V_106 | V_104 :
V_104 ;
if ( ! V_103 )
return - V_155 ;
memcpy ( V_150 -> V_77 . V_89 , V_9 -> V_40 , V_46 ) ;
}
memcpy ( V_150 -> V_77 . V_91 , V_6 -> V_92 , V_46 ) ;
V_150 -> V_77 . V_93 = F_47 ( V_94 ) ;
V_150 -> V_6 . V_95 = F_48 ( V_96 ) ;
V_150 -> V_6 . V_97 = F_47 ( V_156 ) ;
if ( V_153 == V_157 || V_153 == V_158 )
V_150 -> V_6 . V_99 = V_159 ;
else
V_150 -> V_6 . V_99 = V_160 ;
V_150 -> V_6 . V_103 = F_47 ( V_103 ) ;
V_150 -> V_149 . V_107 . V_108 = V_145 ;
V_150 -> V_149 . V_107 . V_110 = V_152 / V_102 ;
if ( V_153 != V_158 ) {
V_152 += sizeof( * V_45 ) ;
V_45 = (struct V_79 * ) F_50 ( V_74 , sizeof( * V_45 ) ) ;
memset ( V_45 , 0 , sizeof( * V_45 ) ) ;
V_45 -> V_107 . V_108 = V_109 ;
V_45 -> V_107 . V_110 = sizeof( * V_45 ) / V_102 ;
if ( V_145 != V_161 && V_145 != V_162 ) {
memcpy ( V_45 -> V_111 , V_6 -> V_141 ( V_129 ) , V_46 ) ;
} else if ( V_6 -> V_13 == V_14 ) {
F_8 ( V_45 -> V_111 , V_16 ) ;
F_8 ( V_45 -> V_111 + 3 , V_6 -> V_137 ) ;
} else if ( V_103 & V_106 ) {
F_4 ( V_6 , L_12 ) ;
memcpy ( V_45 -> V_111 , V_6 -> V_92 , V_46 ) ;
} else {
F_4 ( V_6 , L_13 ) ;
}
}
V_150 -> V_6 . V_101 = F_47 ( V_152 / V_102 ) ;
V_74 -> V_116 = F_47 ( V_94 ) ;
V_74 -> V_47 = V_6 -> V_47 ;
F_51 ( V_74 ) ;
F_52 ( V_74 ) ;
return 0 ;
}
int F_64 ( struct V_5 * V_6 , struct V_128 * V_129 ,
struct V_73 * V_74 )
{
struct V_163 * V_164 ;
struct V_70 * V_151 ;
T_1 V_165 ;
T_3 V_153 ;
T_3 V_45 [ V_46 ] ;
V_164 = F_65 ( V_74 , struct V_163 , V_74 ) ;
V_151 = (struct V_70 * ) V_74 -> V_88 ;
V_153 = * ( T_3 * ) ( V_151 + 1 ) ;
if ( V_153 == V_166 && V_6 -> V_13 != V_14 ) {
V_165 = V_6 -> V_23 ;
V_6 -> V_23 = F_66 ( V_151 -> V_167 ) ;
if ( V_6 -> V_2 == V_121 ) {
if ( V_165 == V_24 )
V_6 -> V_168 = 0 ;
V_6 -> V_168 ++ ;
if ( V_6 -> V_168 < 3 )
goto V_169;
F_7 ( V_6 ) ;
return 0 ;
}
if ( V_6 -> V_2 == V_120 )
F_7 ( V_6 ) ;
}
if ( V_6 -> V_2 == V_120 )
return 0 ;
if ( ! V_6 -> V_57 && V_6 -> V_13 != V_14 )
goto V_169;
switch ( V_153 ) {
case V_166 :
V_153 = V_161 ;
if ( V_6 -> V_13 == V_14 )
break;
F_37 ( & V_6 -> V_22 ) ;
F_38 ( V_6 -> V_61 ) ;
V_6 -> V_61 = V_74 ;
V_6 -> V_170 = 1 ;
F_40 ( & V_6 -> V_22 ) ;
F_67 ( & V_6 -> V_27 ) ;
return - V_171 ;
case V_172 :
if ( F_68 ( V_151 -> V_173 ) )
return 0 ;
V_153 = V_162 ;
break;
case V_174 :
if ( V_6 -> V_13 == V_14 ) {
if ( V_6 -> V_2 != V_175 )
return - V_176 ;
if ( F_68 ( V_151 -> V_177 ) == V_178 )
return - V_176 ;
} else {
if ( V_6 -> V_2 != V_179 )
return 0 ;
if ( F_68 ( V_151 -> V_177 ) != V_178 )
return 0 ;
}
V_153 = V_180 ;
break;
case V_157 :
if ( V_6 -> V_2 == V_120 ) {
if ( V_6 -> V_23 == V_24 )
return 0 ;
V_6 -> V_23 = V_24 ;
F_69 ( V_45 , V_151 -> V_177 ) ;
V_6 -> V_181 ( V_129 , V_45 ) ;
}
case V_158 :
V_153 = F_70 ( V_164 ) ;
if ( V_153 )
break;
return 0 ;
default:
if ( V_6 -> V_2 != V_179 &&
V_6 -> V_2 != V_175 )
goto V_169;
return 0 ;
}
F_4 ( V_6 , L_14 ,
V_153 , F_68 ( V_151 -> V_177 ) ) ;
if ( F_61 ( V_6 , V_129 , V_153 , V_74 , F_68 ( V_151 -> V_177 ) ) )
goto V_169;
V_6 -> V_117 ( V_6 , V_74 ) ;
return - V_171 ;
V_169:
F_38 ( V_74 ) ;
return - V_176 ;
}
static unsigned long F_71 ( struct V_5 * V_6 )
{
struct V_8 * V_9 ;
struct V_8 * V_56 ;
unsigned long V_182 = V_119 + F_72 ( V_183 ) ;
unsigned long V_184 ;
unsigned long V_58 = 0 ;
struct V_185 V_186 ;
struct V_187 * V_188 ;
F_10 ( & V_186 ) ;
V_188 = F_73 ( V_6 -> V_7 -> V_189 , F_74 () ) ;
F_31 (fcf, next, &fip->fcfs, list) {
V_184 = V_9 -> time + V_9 -> V_49 + V_9 -> V_49 / 2 ;
if ( V_6 -> V_57 == V_9 ) {
if ( F_75 ( V_119 , V_184 ) ) {
V_188 -> V_190 ++ ;
F_43 ( V_67 L_4
L_15
L_16 ,
V_6 -> V_7 -> V_65 -> V_66 , V_9 -> V_39 ,
V_188 -> V_190 ) ;
} else if ( F_75 ( V_182 , V_184 ) )
V_182 = V_184 ;
}
V_184 += V_9 -> V_49 ;
if ( F_76 ( V_119 , V_184 ) ) {
if ( V_6 -> V_57 == V_9 )
V_6 -> V_57 = NULL ;
F_25 ( & V_9 -> V_54 ) ;
F_22 ( & V_9 -> V_54 , & V_186 ) ;
V_188 -> V_191 ++ ;
} else {
if ( F_75 ( V_182 , V_184 ) )
V_182 = V_184 ;
if ( F_5 ( V_9 ) &&
( ! V_58 || F_77 ( V_58 , V_9 -> time ) ) )
V_58 = V_9 -> time ;
}
}
F_78 () ;
F_31 (fcf, next, &del_list, list) {
F_24 ( V_9 ) ;
}
if ( V_58 && ! V_6 -> V_57 && ! V_6 -> V_58 ) {
V_58 += F_72 ( V_192 ) ;
V_6 -> V_58 = V_58 ;
}
return V_182 ;
}
static int F_79 ( struct V_5 * V_6 ,
struct V_73 * V_74 , struct V_8 * V_9 )
{
struct V_78 * V_193 ;
struct V_194 * V_85 = NULL ;
struct V_80 * V_195 ;
struct V_196 * V_197 ;
struct V_198 * V_199 ;
unsigned long V_200 ;
T_4 V_201 ;
T_4 V_152 ;
T_2 V_202 ;
memset ( V_9 , 0 , sizeof( * V_9 ) ) ;
V_9 -> V_49 = F_72 ( V_203 ) ;
V_193 = (struct V_78 * ) V_74 -> V_88 ;
V_9 -> V_10 = F_66 ( V_193 -> V_103 ) ;
V_202 = F_80 ( V_204 ) | F_80 ( V_109 ) | F_80 ( V_112 ) |
F_80 ( V_205 ) | F_80 ( V_206 ) ;
V_201 = F_66 ( V_193 -> V_101 ) * 4 ;
if ( V_201 + sizeof( * V_193 ) > V_74 -> V_136 )
return - V_176 ;
V_85 = (struct V_194 * ) ( V_193 + 1 ) ;
while ( V_201 > 0 ) {
V_152 = V_85 -> V_110 * V_102 ;
if ( V_152 < sizeof( * V_85 ) || V_152 > V_201 )
return - V_176 ;
if ( ( V_85 -> V_108 < 32 ) &&
! ( V_202 & 1U << V_85 -> V_108 ) ) {
F_4 ( V_6 , L_17
L_18 ) ;
return - V_176 ;
}
switch ( V_85 -> V_108 ) {
case V_204 :
if ( V_152 != sizeof( struct V_207 ) )
goto V_208;
V_9 -> V_48 = ( (struct V_207 * ) V_85 ) -> V_209 ;
V_202 &= ~ F_80 ( V_204 ) ;
break;
case V_109 :
if ( V_152 != sizeof( struct V_79 ) )
goto V_208;
memcpy ( V_9 -> V_40 ,
( (struct V_79 * ) V_85 ) -> V_111 ,
V_46 ) ;
memcpy ( V_9 -> V_68 , V_9 -> V_40 , V_46 ) ;
if ( ! F_81 ( V_9 -> V_40 ) ) {
F_4 ( V_6 ,
L_19 ,
V_9 -> V_40 ) ;
return - V_176 ;
}
V_202 &= ~ F_80 ( V_109 ) ;
break;
case V_112 :
if ( V_152 != sizeof( struct V_80 ) )
goto V_208;
V_195 = (struct V_80 * ) V_85 ;
V_9 -> V_42 = F_82 ( & V_195 -> V_113 ) ;
V_202 &= ~ F_80 ( V_112 ) ;
break;
case V_205 :
if ( V_152 != sizeof( struct V_196 ) )
goto V_208;
V_197 = (struct V_196 * ) V_85 ;
V_9 -> V_39 = F_82 ( & V_197 -> V_113 ) ;
V_9 -> V_44 = F_66 ( V_197 -> V_210 ) ;
V_9 -> V_43 = F_68 ( V_197 -> V_211 ) ;
V_202 &= ~ F_80 ( V_205 ) ;
break;
case V_206 :
if ( V_152 != sizeof( struct V_198 ) )
goto V_208;
V_199 = (struct V_198 * ) V_85 ;
if ( V_199 -> V_212 & V_213 )
V_9 -> V_212 = 1 ;
V_200 = F_83 ( V_199 -> V_214 ) ;
if ( V_200 >= V_215 )
V_9 -> V_49 = F_72 ( V_200 ) ;
V_202 &= ~ F_80 ( V_206 ) ;
break;
case V_216 :
case V_114 :
case V_161 :
case V_162 :
case V_180 :
case V_217 :
default:
F_4 ( V_6 , L_20
L_21 , V_85 -> V_108 ) ;
if ( V_85 -> V_108 < V_218 )
return - V_176 ;
break;
}
V_85 = (struct V_194 * ) ( ( char * ) V_85 + V_152 ) ;
V_201 -= V_152 ;
}
if ( ! V_9 -> V_43 || ( V_9 -> V_43 & 0x10000 ) )
return - V_176 ;
if ( ! V_9 -> V_42 )
return - V_176 ;
if ( V_202 ) {
F_4 ( V_6 , L_22 ,
V_202 ) ;
return - V_176 ;
}
return 0 ;
V_208:
F_4 ( V_6 , L_23 ,
V_85 -> V_108 , V_152 ) ;
return - V_176 ;
}
static void F_84 ( struct V_5 * V_6 , struct V_73 * V_74 )
{
struct V_8 * V_9 ;
struct V_8 V_32 ;
unsigned long V_219 = F_72 ( V_220 ) ;
int V_221 = 0 ;
int V_222 ;
int V_223 = 0 ;
int V_38 = 0 ;
if ( F_79 ( V_6 , V_74 , & V_32 ) )
return;
F_18 ( & V_6 -> V_21 ) ;
V_221 = F_85 ( & V_6 -> V_20 ) ;
F_39 (fcf, &fip->fcfs, list) {
if ( V_9 -> V_42 == V_32 . V_42 &&
V_9 -> V_39 == V_32 . V_39 &&
V_9 -> V_43 == V_32 . V_43 &&
F_41 ( V_9 -> V_40 , V_32 . V_40 ) == 0 ) {
V_223 = 1 ;
break;
}
}
if ( ! V_223 ) {
if ( V_6 -> V_55 >= V_224 )
goto V_52;
V_9 = F_86 ( sizeof( * V_9 ) , V_225 ) ;
if ( ! V_9 )
goto V_52;
memcpy ( V_9 , & V_32 , sizeof( V_32 ) ) ;
V_9 -> V_6 = V_6 ;
V_38 = F_16 ( V_9 ) ;
if ( V_38 ) {
F_43 ( V_226 L_24
L_25 ,
V_32 . V_39 , V_32 . V_40 ) ;
F_29 ( V_9 ) ;
goto V_52;
}
} else {
V_9 -> V_212 = V_32 . V_212 ;
if ( ! F_6 ( V_9 ) )
V_9 -> V_10 = V_32 . V_10 ;
if ( V_9 == V_6 -> V_57 && ! V_9 -> V_212 ) {
V_6 -> V_125 -= V_9 -> V_49 ;
V_6 -> V_125 += V_32 . V_49 ;
if ( F_77 ( V_6 -> V_125 , V_6 -> V_25 . V_227 ) )
F_87 ( & V_6 -> V_25 , V_6 -> V_125 ) ;
}
V_9 -> V_49 = V_32 . V_49 ;
memcpy ( V_9 -> V_40 , V_32 . V_40 , V_46 ) ;
}
V_222 = F_5 ( V_9 ) ;
V_9 -> time = V_119 ;
if ( ! V_223 )
F_4 ( V_6 , L_3 ,
V_9 -> V_39 , V_9 -> V_40 ) ;
if ( ! V_222 )
F_45 ( V_6 , V_9 ) ;
if ( V_221 && F_75 ( V_119 , V_6 -> V_118 + V_219 ) )
F_45 ( V_6 , NULL ) ;
if ( V_222 )
F_88 ( & V_9 -> V_54 , & V_6 -> V_20 ) ;
if ( V_222 && ! V_6 -> V_57 && F_6 ( V_9 ) ) {
V_6 -> V_58 = V_119 +
F_72 ( V_192 ) ;
if ( ! F_89 ( & V_6 -> V_25 ) ||
F_77 ( V_6 -> V_58 , V_6 -> V_25 . V_227 ) )
F_87 ( & V_6 -> V_25 , V_6 -> V_58 ) ;
}
V_52:
F_23 ( & V_6 -> V_21 ) ;
}
static void F_90 ( struct V_5 * V_6 , struct V_73 * V_74 )
{
struct V_128 * V_129 = V_6 -> V_7 ;
struct V_78 * V_193 ;
struct V_163 * V_164 = (struct V_163 * ) V_74 ;
struct V_70 * V_151 = NULL ;
struct V_194 * V_85 ;
struct V_148 * V_228 ;
struct V_187 * V_188 ;
struct V_8 * V_60 ;
enum V_229 V_230 = 0 ;
T_3 V_231 ;
T_3 V_232 ;
T_3 V_233 [ V_46 ] = { 0 } ;
T_4 V_234 = 0 ;
T_4 V_201 ;
T_4 V_152 ;
T_2 V_202 = 0 ;
T_2 V_235 = 0 ;
V_193 = (struct V_78 * ) V_74 -> V_88 ;
V_232 = V_193 -> V_99 ;
if ( V_232 != V_160 && V_232 != V_159 )
goto V_169;
V_201 = F_66 ( V_193 -> V_101 ) * 4 ;
if ( V_201 + sizeof( * V_193 ) > V_74 -> V_136 )
goto V_169;
V_85 = (struct V_194 * ) ( V_193 + 1 ) ;
while ( V_201 > 0 ) {
V_235 ++ ;
V_152 = V_85 -> V_110 * V_102 ;
if ( V_152 < sizeof( * V_85 ) || V_152 > V_201 )
goto V_169;
if ( V_85 -> V_108 < 32 ) {
if ( ( V_85 -> V_108 != V_109 ) &&
( V_202 & 1U << V_85 -> V_108 ) ) {
F_4 ( V_6 , L_17
L_26 ) ;
goto V_169;
}
V_202 |= ( 1 << V_85 -> V_108 ) ;
}
switch ( V_85 -> V_108 ) {
case V_109 :
V_60 = V_6 -> V_57 ;
if ( V_235 == 1 ) {
F_4 ( V_6 , L_27
L_28 ) ;
goto V_169;
}
if ( V_235 == 2 )
memcpy ( V_233 ,
( (struct V_79 * ) V_85 ) -> V_111 ,
V_46 ) ;
if ( V_152 != sizeof( struct V_79 ) )
goto V_208;
if ( ( V_235 == 3 ) && ( V_60 ) )
memcpy ( V_60 -> V_68 ,
( (struct V_79 * ) V_85 ) -> V_111 ,
V_46 ) ;
break;
case V_161 :
case V_162 :
case V_180 :
case V_217 :
if ( V_235 != 1 ) {
F_4 ( V_6 , L_27
L_28 ) ;
goto V_169;
}
if ( V_151 )
goto V_169;
if ( V_152 < sizeof( * V_228 ) + sizeof( * V_151 ) + 1 )
goto V_208;
V_234 = V_152 - sizeof( * V_228 ) ;
V_228 = (struct V_148 * ) V_85 ;
V_151 = (struct V_70 * ) ( V_228 + 1 ) ;
V_230 = V_85 -> V_108 ;
break;
default:
F_4 ( V_6 , L_20
L_21 , V_85 -> V_108 ) ;
if ( V_85 -> V_108 < V_218 )
goto V_169;
if ( V_235 <= 2 ) {
F_4 ( V_6 , L_27
L_28 ) ;
goto V_169;
}
break;
}
V_85 = (struct V_194 * ) ( ( char * ) V_85 + V_152 ) ;
V_201 -= V_152 ;
}
if ( ! V_151 )
goto V_169;
V_231 = * ( T_3 * ) ( V_151 + 1 ) ;
if ( ( V_230 == V_161 || V_230 == V_162 ) &&
V_232 == V_159 && V_6 -> V_13 != V_14 ) {
if ( V_231 == V_157 ) {
if ( ! F_81 ( V_233 ) ) {
F_4 ( V_6 ,
L_29 ,
V_233 ) ;
goto V_169;
}
memcpy ( F_91 ( V_164 ) -> V_233 , V_233 , V_46 ) ;
if ( V_6 -> V_23 == F_66 ( V_151 -> V_167 ) ) {
V_6 -> V_23 = V_24 ;
if ( V_230 == V_161 )
F_36 ( V_6 ) ;
}
} else if ( V_230 == V_161 &&
! F_92 ( V_6 ) )
goto V_169;
}
if ( ( V_235 == 0 ) || ( ( V_231 != V_158 ) &&
( ! ( 1U << V_109 & V_202 ) ) ) ) {
F_4 ( V_6 , L_30
L_31 ) ;
goto V_169;
}
F_93 ( V_74 , ( T_3 * ) V_151 - V_74 -> V_88 ) ;
F_94 ( V_74 , V_234 ) ;
V_164 = (struct V_163 * ) V_74 ;
F_95 ( V_164 ) ;
F_96 ( V_164 ) = V_236 ;
F_97 ( V_164 ) = V_237 ;
F_98 ( V_164 ) = V_129 ;
F_70 ( V_164 ) = V_230 ;
V_188 = F_73 ( V_129 -> V_189 , F_74 () ) ;
V_188 -> V_238 ++ ;
V_188 -> V_239 += V_74 -> V_136 / V_102 ;
F_78 () ;
F_99 ( V_129 , V_164 ) ;
return;
V_208:
F_4 ( V_6 , L_23 ,
V_85 -> V_108 , V_152 ) ;
V_169:
F_38 ( V_74 ) ;
}
static void F_100 ( struct V_5 * V_6 ,
struct V_78 * V_151 )
{
struct V_194 * V_85 ;
struct V_79 * V_240 ;
struct V_80 * V_241 ;
struct V_134 * V_242 ;
T_4 V_201 ;
T_4 V_152 ;
struct V_8 * V_9 = V_6 -> V_57 ;
struct V_128 * V_129 = V_6 -> V_7 ;
struct V_128 * V_243 = NULL ;
T_2 V_202 ;
int V_244 ;
int V_245 = 0 ;
struct V_134 * * V_246 = NULL ;
F_4 ( V_6 , L_32 ) ;
if ( ! V_9 || ! V_129 -> V_137 )
return;
V_202 = F_80 ( V_109 ) | F_80 ( V_112 ) ;
V_201 = F_66 ( V_151 -> V_101 ) * V_102 ;
V_85 = (struct V_194 * ) ( V_151 + 1 ) ;
V_244 = V_201 / sizeof( * V_242 ) ;
if ( V_244 )
V_246 = F_86 ( sizeof( V_242 ) * V_244 ,
V_225 ) ;
if ( ! V_246 )
return;
V_244 = 0 ;
while ( V_201 >= sizeof( * V_85 ) ) {
V_152 = V_85 -> V_110 * V_102 ;
if ( V_152 > V_201 )
goto V_247;
if ( ( V_85 -> V_108 < 32 ) &&
( V_85 -> V_108 != V_140 ) &&
! ( V_202 & 1U << V_85 -> V_108 ) ) {
F_4 ( V_6 , L_17
L_33 ) ;
goto V_247;
}
switch ( V_85 -> V_108 ) {
case V_109 :
V_240 = (struct V_79 * ) V_85 ;
if ( V_152 < sizeof( * V_240 ) )
goto V_247;
if ( F_41 ( V_240 -> V_111 , V_9 -> V_40 ) )
goto V_247;
V_202 &= ~ F_80 ( V_109 ) ;
break;
case V_112 :
V_241 = (struct V_80 * ) V_85 ;
if ( V_152 < sizeof( * V_241 ) )
goto V_247;
if ( F_82 ( & V_241 -> V_113 ) != V_9 -> V_42 )
goto V_247;
V_202 &= ~ F_80 ( V_112 ) ;
break;
case V_140 :
V_242 = (struct V_134 * ) V_85 ;
if ( V_152 < sizeof( * V_242 ) )
goto V_247;
V_246 [ V_244 ++ ] = V_242 ;
V_243 = F_101 ( V_129 ,
F_68 ( V_242 -> V_142 ) ) ;
if ( V_243 && ( V_243 == V_129 ) ) {
F_18 ( & V_6 -> V_21 ) ;
F_73 ( V_129 -> V_189 ,
F_74 () ) -> V_191 ++ ;
F_78 () ;
F_56 ( V_6 ) ;
F_23 ( & V_6 -> V_21 ) ;
}
break;
default:
if ( V_85 -> V_108 < V_218 )
goto V_247;
break;
}
V_85 = (struct V_194 * ) ( ( char * ) V_85 + V_152 ) ;
V_201 -= V_152 ;
}
if ( V_202 )
F_4 ( V_6 , L_34 ,
V_202 ) ;
else if ( ! V_244 ) {
F_4 ( V_6 , L_35 ) ;
F_18 ( & V_6 -> V_21 ) ;
F_73 ( V_129 -> V_189 ,
F_74 () ) -> V_191 ++ ;
F_78 () ;
F_56 ( V_6 ) ;
F_23 ( & V_6 -> V_21 ) ;
F_18 ( & V_129 -> V_248 ) ;
F_39 (vn_port, &lport->vports, list)
F_102 ( V_243 ) ;
F_23 ( & V_129 -> V_248 ) ;
F_102 ( V_6 -> V_7 ) ;
F_45 ( V_6 , NULL ) ;
} else {
int V_249 ;
F_4 ( V_6 , L_36 ) ;
for ( V_249 = 0 ; V_249 < V_244 ; V_249 ++ ) {
V_242 = V_246 [ V_249 ] ;
V_243 = F_101 ( V_129 ,
F_68 ( V_242 -> V_142 ) ) ;
if ( ! V_243 )
continue;
if ( F_41 ( V_6 -> V_141 ( V_243 ) ,
V_242 -> V_111 ) != 0 ||
F_82 ( & V_242 -> V_144 ) !=
V_243 -> V_143 )
continue;
if ( V_243 == V_129 )
V_245 = 1 ;
else
F_102 ( V_243 ) ;
}
if ( V_245 ) {
F_102 ( V_6 -> V_7 ) ;
F_45 ( V_6 , NULL ) ;
}
}
V_247:
F_29 ( V_246 ) ;
}
void F_103 ( struct V_5 * V_6 , struct V_73 * V_74 )
{
F_104 ( & V_6 -> V_31 , V_74 ) ;
F_67 ( & V_6 -> V_29 ) ;
}
static int F_105 ( struct V_5 * V_6 , struct V_73 * V_74 )
{
struct V_78 * V_193 ;
struct V_76 * V_250 ;
enum V_1 V_2 ;
T_1 V_153 ;
T_3 V_232 ;
if ( F_106 ( V_74 ) )
goto V_169;
if ( V_74 -> V_136 < sizeof( * V_193 ) )
goto V_169;
V_250 = F_107 ( V_74 ) ;
if ( V_6 -> V_13 == V_14 ) {
if ( F_41 ( V_250 -> V_89 , V_6 -> V_92 ) &&
F_41 ( V_250 -> V_89 , V_251 ) &&
F_41 ( V_250 -> V_89 , V_252 ) )
goto V_169;
} else if ( F_41 ( V_250 -> V_89 , V_6 -> V_92 ) &&
F_41 ( V_250 -> V_89 , V_253 ) )
goto V_169;
V_193 = (struct V_78 * ) V_74 -> V_88 ;
V_153 = F_66 ( V_193 -> V_97 ) ;
V_232 = V_193 -> V_99 ;
if ( F_108 ( V_193 -> V_95 ) != V_96 )
goto V_169;
if ( F_66 ( V_193 -> V_101 ) * V_102 + sizeof( * V_193 ) > V_74 -> V_136 )
goto V_169;
F_18 ( & V_6 -> V_21 ) ;
V_2 = V_6 -> V_2 ;
if ( V_2 == V_121 ) {
V_6 -> V_18 = 0 ;
F_3 ( V_6 , V_179 ) ;
V_2 = V_179 ;
F_4 ( V_6 , L_37 ) ;
}
F_23 ( & V_6 -> V_21 ) ;
if ( V_6 -> V_13 == V_14 && V_153 == V_254 )
return F_109 ( V_6 , V_74 ) ;
if ( V_2 != V_179 && V_2 != V_175 &&
V_2 != V_255 )
goto V_169;
if ( V_153 == V_156 ) {
F_90 ( V_6 , V_74 ) ;
return 0 ;
}
if ( V_2 != V_179 )
goto V_169;
if ( V_153 == V_98 && V_232 == V_256 )
F_84 ( V_6 , V_74 ) ;
else if ( V_153 == V_138 && V_232 == V_257 )
F_100 ( V_6 , V_193 ) ;
F_38 ( V_74 ) ;
return 0 ;
V_169:
F_38 ( V_74 ) ;
return - 1 ;
}
static struct V_8 * F_110 ( struct V_5 * V_6 )
{
struct V_8 * V_9 ;
struct V_8 * V_258 = V_6 -> V_57 ;
struct V_8 * V_221 ;
V_221 = F_111 ( & V_6 -> V_20 , struct V_8 , V_54 ) ;
F_39 (fcf, &fip->fcfs, list) {
F_4 ( V_6 , L_38
L_39
L_40 ,
V_9 -> V_39 , V_9 -> V_44 , V_9 -> V_40 ,
V_9 -> V_43 , F_5 ( V_9 ) ,
V_9 -> V_62 , V_9 -> V_48 ) ;
if ( V_9 -> V_39 != V_221 -> V_39 ||
V_9 -> V_44 != V_221 -> V_44 ||
V_9 -> V_43 != V_221 -> V_43 ) {
F_4 ( V_6 , L_41
L_42 ) ;
return NULL ;
}
if ( V_9 -> V_62 )
continue;
if ( ! F_6 ( V_9 ) ) {
F_4 ( V_6 , L_43
L_44 ,
V_9 -> V_39 , V_9 -> V_43 ,
( V_9 -> V_10 & V_11 ) ? L_45 : L_46 ,
( V_9 -> V_10 & V_12 ) ?
L_45 : L_47 ) ;
continue;
}
if ( ! V_258 || V_9 -> V_48 < V_258 -> V_48 || V_258 -> V_62 )
V_258 = V_9 ;
}
V_6 -> V_57 = V_258 ;
if ( V_258 ) {
F_4 ( V_6 , L_48 , V_258 -> V_40 ) ;
V_6 -> V_126 = V_119 +
F_72 ( V_183 ) ;
V_6 -> V_125 = V_119 + V_258 -> V_49 ;
if ( F_77 ( V_6 -> V_125 , V_6 -> V_25 . V_227 ) )
F_87 ( & V_6 -> V_25 , V_6 -> V_125 ) ;
}
return V_258 ;
}
static int F_112 ( struct V_5 * V_6 )
{
struct V_73 * V_74 ;
struct V_73 * V_259 ;
struct V_70 * V_151 ;
int error ;
V_259 = V_6 -> V_61 ;
if ( ! V_259 )
return - V_176 ;
V_74 = F_113 ( V_259 , V_225 ) ;
if ( ! V_74 ) {
V_74 = V_259 ;
V_6 -> V_61 = NULL ;
}
V_151 = (struct V_70 * ) V_74 -> V_88 ;
error = F_61 ( V_6 , V_6 -> V_7 , V_161 , V_74 ,
F_68 ( V_151 -> V_177 ) ) ;
if ( error ) {
F_38 ( V_74 ) ;
return error ;
}
V_6 -> V_117 ( V_6 , V_74 ) ;
V_6 -> V_57 -> V_62 = 1 ;
return 0 ;
}
static int F_92 ( struct V_5 * V_6 )
{
struct V_8 * V_9 ;
int error ;
F_18 ( & V_6 -> V_21 ) ;
F_37 ( & V_6 -> V_22 ) ;
F_4 ( V_6 , L_49 ) ;
V_9 = F_110 ( V_6 ) ;
if ( ! V_9 || V_9 -> V_62 ) {
F_38 ( V_6 -> V_61 ) ;
V_6 -> V_61 = NULL ;
error = - V_260 ;
} else {
F_45 ( V_6 , NULL ) ;
error = F_112 ( V_6 ) ;
}
F_40 ( & V_6 -> V_22 ) ;
F_23 ( & V_6 -> V_21 ) ;
return error ;
}
static void F_114 ( struct V_5 * V_6 )
{
struct V_8 * V_9 ;
F_37 ( & V_6 -> V_22 ) ;
V_9 = V_6 -> V_57 ;
if ( ! V_9 || ! V_6 -> V_170 )
goto V_63;
F_4 ( V_6 , L_50 ) ;
if ( V_9 -> V_62 ) {
F_4 ( V_6 , L_51 ) ;
V_9 = F_110 ( V_6 ) ;
if ( ! V_9 || V_9 -> V_62 ) {
F_4 ( V_6 , L_52 ) ;
F_39 (fcf, &fip->fcfs, list)
V_9 -> V_62 = 0 ;
V_9 = F_110 ( V_6 ) ;
}
}
if ( V_9 ) {
F_112 ( V_6 ) ;
V_6 -> V_170 = 0 ;
} else
F_4 ( V_6 , L_53 ) ;
V_63:
F_40 ( & V_6 -> V_22 ) ;
}
static void V_26 ( unsigned long V_261 )
{
struct V_5 * V_6 = (struct V_5 * ) V_261 ;
F_67 ( & V_6 -> V_27 ) ;
}
static void V_28 ( struct V_262 * V_263 )
{
struct V_5 * V_6 ;
struct V_128 * V_264 ;
T_3 * V_45 ;
T_3 V_265 = 0 ;
T_3 V_266 = 0 ;
T_3 V_267 = 0 ;
struct V_8 * V_60 ;
struct V_8 * V_9 ;
unsigned long V_182 ;
V_6 = F_65 ( V_263 , struct V_5 , V_27 ) ;
if ( V_6 -> V_13 == V_14 )
return F_115 ( V_6 ) ;
F_18 ( & V_6 -> V_21 ) ;
if ( V_6 -> V_2 == V_59 ) {
F_23 ( & V_6 -> V_21 ) ;
return;
}
V_9 = V_6 -> V_57 ;
V_182 = F_71 ( V_6 ) ;
V_60 = V_6 -> V_57 ;
if ( ! V_60 && V_6 -> V_58 ) {
if ( F_76 ( V_119 , V_6 -> V_58 ) ) {
V_60 = F_110 ( V_6 ) ;
V_6 -> V_58 = 0 ;
} else if ( F_75 ( V_182 , V_6 -> V_58 ) )
V_182 = V_6 -> V_58 ;
}
if ( V_60 && V_6 -> V_170 )
F_114 ( V_6 ) ;
else if ( ! V_60 && V_9 )
V_265 = 1 ;
if ( V_60 && ! V_60 -> V_212 ) {
if ( F_76 ( V_119 , V_6 -> V_125 ) ) {
V_6 -> V_125 = V_119 + V_60 -> V_49 ;
V_266 = 1 ;
}
if ( F_75 ( V_182 , V_6 -> V_125 ) )
V_182 = V_6 -> V_125 ;
if ( F_76 ( V_119 , V_6 -> V_126 ) ) {
V_6 -> V_126 = V_119 +
F_72 ( V_183 ) ;
V_267 = 1 ;
}
if ( F_75 ( V_182 , V_6 -> V_126 ) )
V_182 = V_6 -> V_126 ;
}
if ( ! F_85 ( & V_6 -> V_20 ) )
F_87 ( & V_6 -> V_25 , V_182 ) ;
F_23 ( & V_6 -> V_21 ) ;
if ( V_265 ) {
F_102 ( V_6 -> V_7 ) ;
F_45 ( V_6 , NULL ) ;
}
if ( V_266 )
F_60 ( V_6 , NULL , 0 , V_6 -> V_92 ) ;
if ( V_267 ) {
F_18 ( & V_6 -> V_7 -> V_248 ) ;
V_45 = V_6 -> V_141 ( V_6 -> V_7 ) ;
F_60 ( V_6 , V_6 -> V_7 , 1 , V_45 ) ;
F_39 (vport, &fip->lp->vports, list) {
V_45 = V_6 -> V_141 ( V_264 ) ;
F_60 ( V_6 , V_264 , 1 , V_45 ) ;
}
F_23 ( & V_6 -> V_7 -> V_248 ) ;
}
}
static void V_30 ( struct V_262 * V_29 )
{
struct V_5 * V_6 ;
struct V_73 * V_74 ;
V_6 = F_65 ( V_29 , struct V_5 , V_29 ) ;
while ( ( V_74 = F_116 ( & V_6 -> V_31 ) ) )
F_105 ( V_6 , V_74 ) ;
}
int F_117 ( struct V_5 * V_6 , struct V_128 * V_129 ,
struct V_163 * V_164 )
{
struct V_70 * V_151 ;
T_3 V_153 ;
T_3 * V_131 ;
V_131 = F_107 ( & V_164 -> V_74 ) -> V_91 ;
V_151 = F_118 ( V_164 ) ;
if ( V_151 -> V_268 != V_269 )
return 0 ;
V_153 = F_119 ( V_164 ) ;
if ( V_153 == V_157 && V_151 -> V_270 == V_271 &&
V_6 -> V_23 == F_66 ( V_151 -> V_167 ) ) {
F_18 ( & V_6 -> V_21 ) ;
if ( V_6 -> V_2 != V_121 && V_6 -> V_2 != V_120 ) {
F_23 ( & V_6 -> V_21 ) ;
return - V_176 ;
}
F_3 ( V_6 , V_120 ) ;
F_4 ( V_6 ,
L_54 ) ;
if ( ! F_41 ( V_131 , ( T_3 [ 6 ] ) V_272 ) ) {
F_7 ( V_6 ) ;
} else {
memcpy ( V_6 -> V_15 , V_131 , V_46 ) ;
V_6 -> V_18 = 0 ;
}
V_6 -> V_23 = V_24 ;
F_23 ( & V_6 -> V_21 ) ;
F_69 ( F_91 ( V_164 ) -> V_233 , V_151 -> V_177 ) ;
} else if ( V_153 == V_166 && V_151 -> V_270 == V_273 && V_131 ) {
F_18 ( & V_6 -> V_21 ) ;
if ( V_6 -> V_2 == V_121 || V_6 -> V_2 == V_120 ) {
memcpy ( V_6 -> V_15 , V_131 , V_46 ) ;
V_6 -> V_18 = 0 ;
if ( V_6 -> V_2 == V_121 )
F_4 ( V_6 , L_55
L_56 ) ;
F_3 ( V_6 , V_120 ) ;
}
F_23 ( & V_6 -> V_21 ) ;
}
return 0 ;
}
T_5 F_120 ( unsigned char V_45 [ V_274 ] ,
unsigned int V_275 , unsigned int V_276 )
{
T_5 V_195 ;
T_5 V_277 ;
V_277 = ( ( T_5 ) V_45 [ 0 ] << 40 ) |
( ( T_5 ) V_45 [ 1 ] << 32 ) |
( ( T_5 ) V_45 [ 2 ] << 24 ) |
( ( T_5 ) V_45 [ 3 ] << 16 ) |
( ( T_5 ) V_45 [ 4 ] << 8 ) |
( T_5 ) V_45 [ 5 ] ;
F_27 ( V_277 >= ( 1ULL << 48 ) ) ;
V_195 = V_277 | ( ( T_5 ) V_275 << 60 ) ;
switch ( V_275 ) {
case 1 :
F_27 ( V_276 != 0 ) ;
break;
case 2 :
F_27 ( V_276 >= 0xfff ) ;
V_195 |= ( T_5 ) V_276 << 48 ;
break;
default:
F_27 ( 1 ) ;
break;
}
return V_195 ;
}
static inline struct V_278 * F_121 ( struct V_279 * V_280 )
{
return (struct V_278 * ) ( V_280 + 1 ) ;
}
static void F_122 ( struct V_5 * V_6 ,
enum V_281 V_232 ,
const T_3 * V_282 , T_4 V_283 )
{
struct V_73 * V_74 ;
struct V_284 {
struct V_76 V_77 ;
struct V_78 V_6 ;
struct V_79 V_45 ;
struct V_80 V_81 ;
struct V_134 V_135 ;
} V_84 * V_285 ;
struct V_286 * V_287 ;
struct V_82 * V_83 ;
T_2 V_288 ;
T_4 V_136 ;
T_4 V_152 ;
V_136 = sizeof( * V_285 ) ;
V_152 = 0 ;
if ( V_232 == V_289 || V_232 == V_290 ) {
V_152 = sizeof( struct V_286 ) +
sizeof( struct V_82 ) ;
V_136 += V_152 ;
}
V_152 += sizeof( V_285 -> V_45 ) + sizeof( V_285 -> V_81 ) + sizeof( V_285 -> V_135 ) ;
V_136 = F_123 ( V_136 , V_283 + sizeof( struct V_76 ) ) ;
V_74 = F_46 ( V_136 ) ;
if ( ! V_74 )
return;
V_285 = (struct V_284 * ) V_74 -> V_88 ;
memset ( V_285 , 0 , V_136 ) ;
memcpy ( V_285 -> V_77 . V_89 , V_282 , V_46 ) ;
if ( V_232 == V_291 ) {
F_8 ( V_285 -> V_77 . V_91 , V_16 ) ;
F_8 ( V_285 -> V_77 . V_91 + 3 , V_6 -> V_137 ) ;
} else {
memcpy ( V_285 -> V_77 . V_91 , V_6 -> V_92 , V_46 ) ;
}
V_285 -> V_77 . V_93 = F_47 ( V_94 ) ;
V_285 -> V_6 . V_95 = F_48 ( V_96 ) ;
V_285 -> V_6 . V_97 = F_47 ( V_254 ) ;
V_285 -> V_6 . V_99 = V_232 ;
V_285 -> V_6 . V_101 = F_47 ( V_152 / V_102 ) ;
V_285 -> V_45 . V_107 . V_108 = V_109 ;
V_285 -> V_45 . V_107 . V_110 = sizeof( V_285 -> V_45 ) / V_102 ;
memcpy ( V_285 -> V_45 . V_111 , V_6 -> V_92 , V_46 ) ;
V_285 -> V_81 . V_107 . V_108 = V_112 ;
V_285 -> V_81 . V_107 . V_110 = sizeof( V_285 -> V_81 ) / V_102 ;
F_49 ( V_6 -> V_7 -> V_81 , & V_285 -> V_81 . V_113 ) ;
V_285 -> V_135 . V_107 . V_108 = V_140 ;
V_285 -> V_135 . V_107 . V_110 = sizeof( V_285 -> V_135 ) / V_102 ;
F_8 ( V_285 -> V_135 . V_111 , V_16 ) ;
F_8 ( V_285 -> V_135 . V_111 + 3 , V_6 -> V_137 ) ;
F_8 ( V_285 -> V_135 . V_142 , V_6 -> V_137 ) ;
F_49 ( V_6 -> V_7 -> V_143 , & V_285 -> V_135 . V_144 ) ;
if ( V_232 == V_289 || V_232 == V_290 ) {
V_287 = (struct V_286 * ) ( V_285 + 1 ) ;
V_287 -> V_107 . V_108 = V_292 ;
V_287 -> V_107 . V_110 = sizeof( * V_287 ) / V_102 ;
V_287 -> V_293 = V_6 -> V_7 -> V_294 ;
V_288 = 0 ;
if ( V_6 -> V_7 -> V_295 & V_296 )
V_288 |= V_297 ;
if ( V_6 -> V_7 -> V_295 & V_298 )
V_288 |= V_299 ;
V_288 <<= ( V_300 * 4 ) % 32 ;
V_287 -> V_301 . V_302 [ V_300 * 4 / 32 ] = F_124 ( V_288 ) ;
V_83 = (struct V_82 * ) ( V_287 + 1 ) ;
V_83 -> V_107 . V_108 = V_114 ;
V_83 -> V_107 . V_110 = sizeof( * V_83 ) / V_102 ;
V_83 -> V_115 = F_47 ( F_44 ( V_6 ) ) ;
}
F_50 ( V_74 , V_136 ) ;
V_74 -> V_116 = F_47 ( V_94 ) ;
V_74 -> V_47 = V_6 -> V_47 ;
F_51 ( V_74 ) ;
F_52 ( V_74 ) ;
V_6 -> V_117 ( V_6 , V_74 ) ;
}
static void F_125 ( struct V_128 * V_129 ,
struct V_279 * V_280 ,
enum V_303 V_304 )
{
struct V_5 * V_6 = V_129 -> V_305 . V_53 ;
struct V_278 * V_306 = F_121 ( V_280 ) ;
F_4 ( V_6 , L_57 ,
V_280 -> V_307 . V_137 , V_304 ) ;
F_18 ( & V_6 -> V_21 ) ;
switch ( V_304 ) {
case V_308 :
V_306 -> V_309 = 0 ;
break;
case V_310 :
case V_311 :
case V_312 :
V_306 -> V_309 ++ ;
if ( V_306 -> V_309 > V_313 ) {
F_4 ( V_6 ,
L_58 ,
V_280 -> V_307 . V_137 ) ;
V_129 -> V_314 . V_315 ( V_280 ) ;
}
break;
default:
break;
}
F_23 ( & V_6 -> V_21 ) ;
}
static void F_126 ( struct V_128 * V_129 )
{
F_18 ( & V_129 -> V_305 . V_316 ) ;
V_129 -> V_305 . V_317 = NULL ;
F_23 ( & V_129 -> V_305 . V_316 ) ;
}
static void F_127 ( struct V_128 * V_129 )
{
struct V_5 * V_6 = V_129 -> V_305 . V_53 ;
F_18 ( & V_6 -> V_21 ) ;
F_126 ( V_129 ) ;
F_23 ( & V_6 -> V_21 ) ;
}
static void F_128 ( struct V_128 * V_129 )
{
F_127 ( V_129 ) ;
V_129 -> V_314 . V_318 () ;
F_129 () ;
}
static void F_130 ( struct V_5 * V_6 )
{
unsigned long V_319 ;
T_2 V_137 ;
F_126 ( V_6 -> V_7 ) ;
V_137 = V_6 -> V_137 ;
if ( V_6 -> V_320 )
V_137 = F_131 ( & V_6 -> V_321 ) & 0xffff ;
else if ( ! V_137 )
V_137 = V_6 -> V_7 -> V_143 & 0xffff ;
if ( ! V_137 || V_137 == 0xffff )
V_137 = 1 ;
V_6 -> V_137 = V_137 ;
if ( V_6 -> V_320 < V_322 ) {
V_6 -> V_320 ++ ;
V_319 = F_132 () % V_323 ;
} else
V_319 = V_324 ;
F_87 ( & V_6 -> V_25 , V_119 + F_72 ( V_319 ) ) ;
F_3 ( V_6 , V_325 ) ;
}
static void F_55 ( struct V_5 * V_6 )
{
V_6 -> V_320 = 0 ;
F_133 ( & V_6 -> V_321 , V_6 -> V_7 -> V_143 ) ;
F_130 ( V_6 ) ;
}
static int F_134 ( struct V_5 * V_6 ,
struct V_73 * V_74 ,
struct V_279 * V_280 )
{
struct V_78 * V_193 ;
struct V_194 * V_85 = NULL ;
struct V_79 * V_326 = NULL ;
struct V_80 * V_195 = NULL ;
struct V_134 * V_135 = NULL ;
struct V_82 * V_83 = NULL ;
struct V_278 * V_306 ;
T_4 V_201 ;
T_4 V_152 ;
T_2 V_202 = 0 ;
T_2 V_145 ;
T_3 V_232 ;
memset ( V_280 , 0 , sizeof( * V_280 ) + sizeof( * V_306 ) ) ;
V_306 = F_121 ( V_280 ) ;
V_193 = (struct V_78 * ) V_74 -> V_88 ;
V_306 -> V_10 = F_66 ( V_193 -> V_103 ) ;
V_232 = V_193 -> V_99 ;
switch ( V_232 ) {
case V_327 :
case V_328 :
case V_291 :
V_202 = F_80 ( V_109 ) | F_80 ( V_112 ) |
F_80 ( V_140 ) ;
break;
case V_289 :
case V_290 :
V_202 = F_80 ( V_109 ) | F_80 ( V_112 ) |
F_80 ( V_140 ) | F_80 ( V_292 ) |
F_80 ( V_114 ) ;
break;
default:
F_4 ( V_6 , L_59 , V_232 ) ;
return - V_176 ;
}
V_201 = F_66 ( V_193 -> V_101 ) * 4 ;
if ( V_201 + sizeof( * V_193 ) > V_74 -> V_136 )
return - V_176 ;
V_85 = (struct V_194 * ) ( V_193 + 1 ) ;
while ( V_201 > 0 ) {
V_152 = V_85 -> V_110 * V_102 ;
if ( V_152 < sizeof( * V_85 ) || V_152 > V_201 )
return - V_176 ;
V_145 = V_85 -> V_108 ;
if ( V_145 < 32 ) {
if ( ! ( V_202 & F_80 ( V_145 ) ) ) {
F_4 ( V_6 ,
L_60
L_61
L_62 ,
V_145 , V_232 ) ;
return - V_176 ;
}
V_202 &= ~ F_80 ( V_145 ) ;
}
switch ( V_145 ) {
case V_109 :
if ( V_152 != sizeof( struct V_79 ) )
goto V_208;
V_326 = (struct V_79 * ) V_85 ;
if ( ! F_81 ( V_326 -> V_111 ) ) {
F_4 ( V_6 ,
L_63 ,
V_326 -> V_111 ) ;
return - V_176 ;
}
memcpy ( V_306 -> V_329 , V_326 -> V_111 , V_46 ) ;
break;
case V_112 :
if ( V_152 != sizeof( struct V_80 ) )
goto V_208;
V_195 = (struct V_80 * ) V_85 ;
V_280 -> V_307 . V_330 = F_82 ( & V_195 -> V_113 ) ;
break;
case V_140 :
if ( V_152 != sizeof( struct V_134 ) )
goto V_208;
V_135 = (struct V_134 * ) V_85 ;
memcpy ( V_306 -> V_331 , V_135 -> V_111 , V_46 ) ;
V_280 -> V_307 . V_137 = F_68 ( V_135 -> V_142 ) ;
V_280 -> V_307 . V_332 = F_82 ( & V_135 -> V_144 ) ;
break;
case V_292 :
if ( V_152 != sizeof( struct V_286 ) )
goto V_208;
break;
case V_114 :
if ( V_152 != sizeof( struct V_82 ) )
goto V_208;
V_83 = (struct V_82 * ) V_85 ;
V_306 -> V_333 = F_66 ( V_83 -> V_115 ) ;
break;
default:
F_4 ( V_6 , L_20
L_64 , V_145 ) ;
if ( V_145 < V_218 )
return - V_176 ;
break;
}
V_85 = (struct V_194 * ) ( ( char * ) V_85 + V_152 ) ;
V_201 -= V_152 ;
}
return 0 ;
V_208:
F_4 ( V_6 , L_23 ,
V_145 , V_152 ) ;
return - V_176 ;
}
static void F_135 ( struct V_5 * V_6 )
{
F_122 ( V_6 , V_289 , V_251 , 0 ) ;
V_6 -> V_118 = V_119 ;
}
static void F_136 ( struct V_5 * V_6 ,
struct V_279 * V_280 )
{
struct V_278 * V_306 = F_121 ( V_280 ) ;
if ( V_280 -> V_307 . V_137 != V_6 -> V_137 )
return;
switch ( V_6 -> V_2 ) {
case V_255 :
case V_175 :
F_122 ( V_6 , V_328 ,
V_306 -> V_329 , 0 ) ;
break;
case V_334 :
case V_335 :
if ( V_6 -> V_7 -> V_143 > V_280 -> V_307 . V_332 &&
! ( V_306 -> V_10 & V_336 ) ) {
F_122 ( V_6 , V_328 ,
V_306 -> V_329 , 0 ) ;
break;
}
case V_325 :
F_130 ( V_6 ) ;
break;
default:
break;
}
}
static void F_137 ( struct V_5 * V_6 ,
struct V_279 * V_280 )
{
if ( V_280 -> V_307 . V_137 != V_6 -> V_137 )
return;
switch ( V_6 -> V_2 ) {
case V_325 :
case V_334 :
case V_335 :
case V_255 :
F_130 ( V_6 ) ;
break;
case V_175 :
F_135 ( V_6 ) ;
break;
default:
break;
}
}
static void F_138 ( struct V_5 * V_6 , struct V_279 * V_32 )
{
struct V_128 * V_129 = V_6 -> V_7 ;
struct V_279 * V_280 ;
struct V_337 * V_307 ;
struct V_278 * V_306 ;
T_2 V_137 ;
V_137 = V_32 -> V_307 . V_137 ;
if ( V_137 == V_6 -> V_137 )
return;
F_18 ( & V_129 -> V_305 . V_316 ) ;
V_280 = V_129 -> V_314 . V_338 ( V_129 , V_137 ) ;
if ( ! V_280 ) {
F_23 ( & V_129 -> V_305 . V_316 ) ;
return;
}
V_280 -> V_339 = & V_340 ;
V_280 -> V_341 = V_129 -> V_305 . V_341 ;
V_307 = & V_280 -> V_307 ;
if ( ( V_307 -> V_332 != - 1 && V_307 -> V_332 != V_32 -> V_307 . V_332 ) ||
( V_307 -> V_330 != - 1 && V_307 -> V_330 != V_32 -> V_307 . V_330 ) )
V_129 -> V_314 . V_315 ( V_280 ) ;
V_307 -> V_332 = V_32 -> V_307 . V_332 ;
V_307 -> V_330 = V_32 -> V_307 . V_330 ;
F_23 ( & V_129 -> V_305 . V_316 ) ;
V_306 = F_121 ( V_280 ) ;
F_4 ( V_6 , L_65 ,
V_137 , V_306 -> V_333 ? L_66 : L_67 ) ;
* V_306 = * F_121 ( V_32 ) ;
V_306 -> time = 0 ;
}
static int F_63 ( struct V_5 * V_6 , T_2 V_137 , T_3 * V_45 )
{
struct V_128 * V_129 = V_6 -> V_7 ;
struct V_279 * V_280 ;
struct V_278 * V_306 ;
int V_342 = - 1 ;
F_139 () ;
V_280 = V_129 -> V_314 . V_343 ( V_129 , V_137 ) ;
if ( V_280 ) {
V_306 = F_121 ( V_280 ) ;
memcpy ( V_45 , V_306 -> V_329 , V_46 ) ;
V_342 = 0 ;
}
F_140 () ;
return V_342 ;
}
static void F_141 ( struct V_5 * V_6 ,
struct V_279 * V_32 )
{
struct V_278 * V_306 = F_121 ( V_32 ) ;
if ( V_306 -> V_10 & V_336 ) {
F_122 ( V_6 , V_327 , V_251 , 0 ) ;
return;
}
switch ( V_6 -> V_2 ) {
case V_325 :
case V_334 :
case V_335 :
if ( V_32 -> V_307 . V_137 == V_6 -> V_137 )
F_130 ( V_6 ) ;
break;
case V_255 :
case V_175 :
if ( V_32 -> V_307 . V_137 == V_6 -> V_137 ) {
if ( V_32 -> V_307 . V_332 > V_6 -> V_7 -> V_143 ) {
F_130 ( V_6 ) ;
break;
}
F_135 ( V_6 ) ;
break;
}
F_122 ( V_6 , V_290 , V_306 -> V_329 ,
F_142 ( ( T_2 ) V_306 -> V_333 ,
F_44 ( V_6 ) ) ) ;
F_138 ( V_6 , V_32 ) ;
break;
default:
break;
}
}
static void F_143 ( struct V_5 * V_6 ,
struct V_279 * V_32 )
{
F_4 ( V_6 , L_68 ,
V_32 -> V_307 . V_137 , F_1 ( V_6 -> V_2 ) ) ;
if ( V_6 -> V_2 == V_175 || V_6 -> V_2 == V_255 )
F_138 ( V_6 , V_32 ) ;
}
static void F_144 ( struct V_5 * V_6 ,
struct V_279 * V_32 )
{
struct V_128 * V_129 = V_6 -> V_7 ;
struct V_279 * V_280 ;
struct V_278 * V_306 ;
V_306 = F_121 ( V_32 ) ;
if ( V_306 -> V_10 & V_336 ) {
F_122 ( V_6 , V_327 , V_251 , 0 ) ;
return;
}
F_18 ( & V_129 -> V_305 . V_316 ) ;
V_280 = V_129 -> V_314 . V_343 ( V_129 , V_32 -> V_307 . V_137 ) ;
if ( V_280 )
F_145 ( & V_280 -> V_344 ) ;
F_23 ( & V_129 -> V_305 . V_316 ) ;
if ( V_280 ) {
if ( V_280 -> V_307 . V_330 == V_32 -> V_307 . V_330 &&
V_280 -> V_307 . V_332 == V_32 -> V_307 . V_332 ) {
V_306 = F_121 ( V_280 ) ;
if ( ! V_306 -> time && V_6 -> V_2 == V_175 )
V_129 -> V_314 . V_345 ( V_280 ) ;
V_306 -> time = V_119 ;
}
F_146 ( & V_280 -> V_344 , V_129 -> V_314 . V_346 ) ;
return;
}
if ( V_6 -> V_2 != V_175 )
return;
F_4 ( V_6 , L_69 ,
V_32 -> V_307 . V_137 ) ;
if ( F_75 ( V_119 ,
V_6 -> V_118 + F_72 ( V_347 ) ) )
F_135 ( V_6 ) ;
}
static unsigned long F_147 ( struct V_5 * V_6 )
{
struct V_128 * V_129 = V_6 -> V_7 ;
struct V_279 * V_280 ;
struct V_278 * V_306 ;
unsigned long V_348 ;
unsigned long V_184 ;
V_348 = V_119 + F_72 ( V_349 * 10 ) ;
F_18 ( & V_129 -> V_305 . V_316 ) ;
F_148 (rdata, &lport->disc.rports, peers) {
V_306 = F_121 ( V_280 ) ;
if ( ! V_306 -> time )
continue;
V_184 = V_306 -> time +
F_72 ( V_349 * 25 / 10 ) ;
if ( F_76 ( V_119 , V_184 ) ) {
V_306 -> time = 0 ;
F_4 ( V_6 ,
L_70 ,
V_280 -> V_307 . V_332 , V_280 -> V_307 . V_137 ) ;
V_129 -> V_314 . V_315 ( V_280 ) ;
} else if ( F_77 ( V_184 , V_348 ) )
V_348 = V_184 ;
}
F_23 ( & V_129 -> V_305 . V_316 ) ;
return V_348 ;
}
static int F_109 ( struct V_5 * V_6 , struct V_73 * V_74 )
{
struct V_78 * V_193 ;
enum V_281 V_232 ;
struct {
struct V_279 V_280 ;
struct V_278 V_306 ;
} V_350 ;
int V_38 ;
V_193 = (struct V_78 * ) V_74 -> V_88 ;
V_232 = V_193 -> V_99 ;
V_38 = F_134 ( V_6 , V_74 , & V_350 . V_280 ) ;
if ( V_38 ) {
F_4 ( V_6 , L_71 , V_38 ) ;
goto V_169;
}
F_18 ( & V_6 -> V_21 ) ;
switch ( V_232 ) {
case V_327 :
F_136 ( V_6 , & V_350 . V_280 ) ;
break;
case V_328 :
F_137 ( V_6 , & V_350 . V_280 ) ;
break;
case V_289 :
F_141 ( V_6 , & V_350 . V_280 ) ;
break;
case V_290 :
F_143 ( V_6 , & V_350 . V_280 ) ;
break;
case V_291 :
F_144 ( V_6 , & V_350 . V_280 ) ;
break;
default:
F_4 ( V_6 , L_72 , V_232 ) ;
V_38 = - 1 ;
break;
}
F_23 ( & V_6 -> V_21 ) ;
V_169:
F_38 ( V_74 ) ;
return V_38 ;
}
static void F_149 ( struct V_128 * V_129 , struct V_163 * V_164 )
{
struct V_351 V_352 ;
V_352 . V_353 = V_354 ;
V_352 . V_355 = V_356 ;
V_129 -> V_314 . V_357 ( V_164 , V_158 , & V_352 ) ;
F_150 ( V_164 ) ;
}
static void F_151 ( void (* F_152)( struct V_128 * ,
enum V_358 ) ,
struct V_128 * V_129 )
{
struct V_359 * V_305 = & V_129 -> V_305 ;
struct V_5 * V_6 = V_305 -> V_53 ;
F_18 ( & V_305 -> V_316 ) ;
V_305 -> V_317 = F_152 ;
V_305 -> V_341 = ( V_305 -> V_341 + 2 ) | 1 ;
V_305 -> V_360 = 1 ;
F_67 ( & V_6 -> V_27 ) ;
F_23 ( & V_305 -> V_316 ) ;
}
static void F_153 ( struct V_5 * V_6 )
{
struct V_128 * V_129 = V_6 -> V_7 ;
struct V_359 * V_305 = & V_129 -> V_305 ;
struct V_279 * V_280 ;
struct V_278 * V_306 ;
void (* F_152)( struct V_128 * , enum V_358 );
F_18 ( & V_305 -> V_316 ) ;
F_152 = V_305 -> V_360 ? V_305 -> V_317 : NULL ;
V_305 -> V_360 = 0 ;
F_148 (rdata, &disc->rports, peers) {
V_306 = F_121 ( V_280 ) ;
if ( V_306 -> time )
V_129 -> V_314 . V_345 ( V_280 ) ;
}
F_23 ( & V_305 -> V_316 ) ;
if ( F_152 )
F_152 ( V_129 , V_361 ) ;
}
static void F_115 ( struct V_5 * V_6 )
{
unsigned long V_348 ;
T_3 V_45 [ V_46 ] ;
T_2 V_362 = 0 ;
F_18 ( & V_6 -> V_21 ) ;
switch ( V_6 -> V_2 ) {
case V_325 :
F_3 ( V_6 , V_334 ) ;
F_122 ( V_6 , V_327 , V_251 , 0 ) ;
V_348 = V_119 + F_72 ( V_323 ) ;
break;
case V_334 :
F_3 ( V_6 , V_335 ) ;
F_122 ( V_6 , V_327 , V_251 , 0 ) ;
V_348 = V_119 + F_72 ( V_347 ) ;
break;
case V_335 :
F_3 ( V_6 , V_255 ) ;
V_362 = V_6 -> V_137 ;
F_8 ( V_45 , V_16 ) ;
F_8 ( V_45 + 3 , V_362 ) ;
F_7 ( V_6 ) ;
V_6 -> V_181 ( V_6 -> V_7 , V_45 ) ;
F_135 ( V_6 ) ;
V_348 = V_119 + F_72 ( V_347 ) ;
break;
case V_255 :
V_348 = V_6 -> V_118 + F_72 ( V_347 ) ;
if ( F_76 ( V_119 , V_348 ) ) {
F_3 ( V_6 , V_175 ) ;
F_122 ( V_6 , V_291 ,
V_251 , 0 ) ;
V_348 = V_119 + F_72 ( V_347 ) ;
V_6 -> V_126 = V_348 ;
}
F_153 ( V_6 ) ;
break;
case V_175 :
V_348 = F_147 ( V_6 ) ;
if ( F_76 ( V_119 , V_6 -> V_126 ) ) {
F_122 ( V_6 , V_291 ,
V_251 , 0 ) ;
V_6 -> V_126 = V_119 +
F_72 ( V_349 +
( F_132 () % V_363 ) ) ;
}
if ( F_77 ( V_6 -> V_126 , V_348 ) )
V_348 = V_6 -> V_126 ;
break;
case V_19 :
goto V_63;
default:
F_154 ( 1 , L_73 , V_6 -> V_2 ) ;
goto V_63;
}
F_87 ( & V_6 -> V_25 , V_348 ) ;
V_63:
F_23 ( & V_6 -> V_21 ) ;
if ( V_362 )
F_155 ( V_6 -> V_7 , V_362 ) ;
}
int F_156 ( struct V_128 * V_129 , struct V_5 * V_6 ,
const struct V_364 * V_314 , int V_365 )
{
memcpy ( & V_129 -> V_314 , V_314 , sizeof( * V_314 ) ) ;
if ( V_365 && F_157 ( V_129 ) )
return - V_51 ;
F_158 ( V_129 ) ;
F_159 ( V_129 ) ;
F_160 ( V_129 ) ;
if ( V_6 -> V_13 == V_14 )
V_129 -> V_366 = sizeof( struct V_278 ) ;
F_161 ( V_129 ) ;
if ( V_6 -> V_13 == V_14 ) {
V_129 -> V_154 = 1 ;
V_129 -> V_314 . V_367 = F_149 ;
V_129 -> V_314 . V_368 = F_151 ;
V_129 -> V_314 . V_369 = F_127 ;
V_129 -> V_314 . V_370 = F_128 ;
F_11 ( & V_129 -> V_305 . V_316 ) ;
F_10 ( & V_129 -> V_305 . V_371 ) ;
V_129 -> V_305 . V_53 = V_6 ;
} else {
F_162 ( V_129 ) ;
}
return 0 ;
}
void F_163 ( struct V_35 * V_37 )
{
struct V_33 * V_34 = F_164 ( V_37 ) ;
struct V_5 * V_6 = F_165 ( V_34 ) ;
struct V_8 * V_9 ;
F_18 ( & V_6 -> V_21 ) ;
F_18 ( & V_34 -> V_41 ) ;
V_9 = F_166 ( V_37 ) ;
if ( V_9 )
V_37 -> V_50 = ( V_9 == V_6 -> V_57 ) ? 1 : 0 ;
else
V_37 -> V_50 = 0 ;
F_23 ( & V_34 -> V_41 ) ;
F_23 ( & V_6 -> V_21 ) ;
}
void F_167 ( struct V_33 * V_34 )
{
struct V_5 * V_372 = F_165 ( V_34 ) ;
F_18 ( & V_372 -> V_21 ) ;
switch ( V_372 -> V_13 ) {
case V_123 :
V_34 -> V_13 = V_373 ;
break;
case V_14 :
V_34 -> V_13 = V_374 ;
break;
default:
V_34 -> V_13 = V_375 ;
break;
}
F_23 ( & V_372 -> V_21 ) ;
}
