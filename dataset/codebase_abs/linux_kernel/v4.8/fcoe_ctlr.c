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
V_6 -> V_20 = false ;
F_10 ( & V_6 -> V_21 ) ;
F_11 ( & V_6 -> V_22 ) ;
F_12 ( & V_6 -> V_23 ) ;
V_6 -> V_24 = V_25 ;
F_13 ( & V_6 -> V_26 , V_27 , ( unsigned long ) V_6 ) ;
F_14 ( & V_6 -> V_28 , V_29 ) ;
F_14 ( & V_6 -> V_30 , V_31 ) ;
F_15 ( & V_6 -> V_32 ) ;
}
static int F_16 ( struct V_8 * V_33 )
{
struct V_5 * V_6 = V_33 -> V_6 ;
struct V_34 * V_35 ;
struct V_36 * V_37 , * V_38 ;
int V_39 = - V_40 ;
F_4 ( V_6 , L_3 ,
V_33 -> V_41 , V_33 -> V_42 ) ;
V_37 = F_17 ( sizeof( * V_37 ) , V_43 ) ;
if ( ! V_37 )
goto V_44;
V_37 -> V_41 = V_33 -> V_41 ;
V_37 -> V_45 = V_33 -> V_45 ;
V_37 -> V_46 = V_33 -> V_46 ;
V_37 -> V_47 = V_33 -> V_47 ;
memcpy ( V_37 -> V_48 , V_33 -> V_42 , V_49 ) ;
V_37 -> V_50 = V_33 -> V_51 ;
V_37 -> V_52 = V_33 -> V_52 ;
V_37 -> V_53 = 0 ;
V_35 = F_18 ( V_6 ) ;
if ( V_35 ) {
F_19 ( & V_35 -> V_54 ) ;
V_38 = F_20 ( V_35 , V_37 ) ;
if ( F_21 ( ! V_38 ) ) {
V_39 = - V_40 ;
F_22 ( & V_35 -> V_54 ) ;
goto V_44;
}
F_23 ( V_38 -> V_55 ) ;
V_38 -> V_55 = V_33 ;
V_33 -> V_38 = V_38 ;
F_22 ( & V_35 -> V_54 ) ;
}
F_24 ( & V_33 -> V_56 , & V_6 -> V_21 ) ;
V_6 -> V_57 ++ ;
V_39 = 0 ;
V_44:
F_25 ( V_37 ) ;
return V_39 ;
}
static void F_26 ( struct V_8 * V_33 )
{
struct V_5 * V_6 = V_33 -> V_6 ;
struct V_34 * V_58 ;
struct V_36 * V_38 ;
F_27 ( & V_33 -> V_56 ) ;
V_6 -> V_57 -- ;
V_58 = F_18 ( V_6 ) ;
if ( V_58 ) {
F_19 ( & V_58 -> V_54 ) ;
V_38 = F_28 ( V_33 ) ;
F_29 ( ! V_38 ) ;
V_33 -> V_38 = NULL ;
F_30 ( V_38 ) ;
F_25 ( V_33 ) ;
F_22 ( & V_58 -> V_54 ) ;
}
}
static void F_31 ( struct V_5 * V_6 )
{
struct V_8 * V_9 ;
struct V_8 * V_59 ;
V_6 -> V_60 = NULL ;
F_32 (fcf, next, &fip->fcfs, list) {
F_26 ( V_9 ) ;
}
F_29 ( V_6 -> V_57 ) ;
V_6 -> V_61 = 0 ;
}
void F_33 ( struct V_5 * V_6 )
{
F_34 ( & V_6 -> V_30 ) ;
F_35 ( & V_6 -> V_32 ) ;
F_19 ( & V_6 -> V_22 ) ;
F_3 ( V_6 , V_62 ) ;
F_31 ( V_6 ) ;
F_22 ( & V_6 -> V_22 ) ;
F_36 ( & V_6 -> V_26 ) ;
F_34 ( & V_6 -> V_28 ) ;
}
static void F_37 ( struct V_5 * V_6 )
{
struct V_8 * V_63 ;
struct V_8 * V_9 ;
F_19 ( & V_6 -> V_22 ) ;
F_38 ( & V_6 -> V_23 ) ;
F_39 ( V_6 -> V_64 ) ;
V_6 -> V_64 = NULL ;
F_40 (fcf, &fip->fcfs, list)
V_9 -> V_65 = 0 ;
F_41 ( & V_6 -> V_23 ) ;
V_63 = V_6 -> V_60 ;
if ( V_63 && F_42 ( V_63 -> V_42 , V_6 -> V_15 ) )
goto V_66;
if ( ! F_43 ( V_6 -> V_15 ) ) {
F_44 ( V_67 L_4
L_5 ,
V_6 -> V_7 -> V_68 -> V_69 , V_6 -> V_15 ) ;
memset ( V_6 -> V_15 , 0 , V_49 ) ;
}
if ( V_63 ) {
F_44 ( V_70 L_6
L_7 ,
V_6 -> V_7 -> V_68 -> V_69 , V_63 -> V_42 ) ;
memcpy ( V_6 -> V_15 , V_63 -> V_71 , V_49 ) ;
V_6 -> V_18 = 0 ;
}
V_66:
F_22 ( & V_6 -> V_22 ) ;
}
static inline T_2 F_45 ( struct V_5 * V_6 )
{
return V_6 -> V_7 -> V_72 + sizeof( struct V_73 ) +
sizeof( struct V_74 ) + sizeof( struct V_75 ) ;
}
static void F_46 ( struct V_5 * V_6 , struct V_8 * V_9 )
{
struct V_76 * V_77 ;
struct V_78 {
struct V_79 V_80 ;
struct V_81 V_6 ;
struct {
struct V_82 V_48 ;
struct V_83 V_84 ;
struct V_85 V_86 ;
} V_87 V_88 ;
} V_87 * V_89 ;
T_2 V_90 ;
V_77 = F_47 ( sizeof( * V_89 ) ) ;
if ( ! V_77 )
return;
V_89 = (struct V_78 * ) V_77 -> V_91 ;
memset ( V_89 , 0 , sizeof( * V_89 ) ) ;
memcpy ( V_89 -> V_80 . V_92 , V_9 ? V_9 -> V_42 : V_93 , V_49 ) ;
memcpy ( V_89 -> V_80 . V_94 , V_6 -> V_95 , V_49 ) ;
V_89 -> V_80 . V_96 = F_48 ( V_97 ) ;
V_89 -> V_6 . V_98 = F_49 ( V_99 ) ;
V_89 -> V_6 . V_100 = F_48 ( V_101 ) ;
V_89 -> V_6 . V_102 = V_103 ;
V_89 -> V_6 . V_104 = F_48 ( sizeof( V_89 -> V_88 ) / V_105 ) ;
V_89 -> V_6 . V_106 = F_48 ( V_107 ) ;
if ( V_6 -> V_108 )
V_89 -> V_6 . V_106 |= F_48 ( V_109 ) ;
V_89 -> V_88 . V_48 . V_110 . V_111 = V_112 ;
V_89 -> V_88 . V_48 . V_110 . V_113 = sizeof( V_89 -> V_88 . V_48 ) / V_105 ;
memcpy ( V_89 -> V_88 . V_48 . V_114 , V_6 -> V_95 , V_49 ) ;
V_89 -> V_88 . V_84 . V_110 . V_111 = V_115 ;
V_89 -> V_88 . V_84 . V_110 . V_113 = sizeof( V_89 -> V_88 . V_84 ) / V_105 ;
F_50 ( V_6 -> V_7 -> V_84 , & V_89 -> V_88 . V_84 . V_116 ) ;
V_90 = F_45 ( V_6 ) ;
V_89 -> V_88 . V_86 . V_110 . V_111 = V_117 ;
V_89 -> V_88 . V_86 . V_110 . V_113 = sizeof( V_89 -> V_88 . V_86 ) / V_105 ;
V_89 -> V_88 . V_86 . V_118 = F_48 ( V_90 ) ;
F_51 ( V_77 , sizeof( * V_89 ) ) ;
V_77 -> V_119 = F_48 ( V_97 ) ;
V_77 -> V_50 = V_6 -> V_50 ;
F_52 ( V_77 ) ;
F_53 ( V_77 ) ;
V_6 -> V_120 ( V_6 , V_77 ) ;
if ( ! V_9 )
V_6 -> V_121 = V_122 ;
}
void F_54 ( struct V_5 * V_6 )
{
F_19 ( & V_6 -> V_22 ) ;
if ( V_6 -> V_2 == V_123 || V_6 -> V_2 == V_124 ) {
F_22 ( & V_6 -> V_22 ) ;
F_55 ( V_6 -> V_7 ) ;
} else if ( V_6 -> V_2 == V_19 ) {
F_3 ( V_6 , V_6 -> V_13 ) ;
switch ( V_6 -> V_13 ) {
default:
F_4 ( V_6 , L_8 , V_6 -> V_13 ) ;
case V_125 :
F_4 ( V_6 , L_9 , L_10 ) ;
case V_126 :
case V_127 :
F_22 ( & V_6 -> V_22 ) ;
F_55 ( V_6 -> V_7 ) ;
F_46 ( V_6 , NULL ) ;
break;
case V_14 :
F_56 ( V_6 ) ;
F_22 ( & V_6 -> V_22 ) ;
F_55 ( V_6 -> V_7 ) ;
break;
}
} else
F_22 ( & V_6 -> V_22 ) ;
}
static void F_57 ( struct V_5 * V_6 )
{
F_31 ( V_6 ) ;
F_58 ( & V_6 -> V_26 ) ;
V_6 -> V_128 = 0 ;
V_6 -> V_129 = 0 ;
V_6 -> V_121 = 0 ;
V_6 -> V_24 = V_25 ;
F_7 ( V_6 ) ;
}
int F_59 ( struct V_5 * V_6 )
{
int V_130 ;
F_4 ( V_6 , L_11 ) ;
F_19 ( & V_6 -> V_22 ) ;
F_57 ( V_6 ) ;
V_130 = V_6 -> V_2 != V_19 ;
F_3 ( V_6 , V_19 ) ;
F_22 ( & V_6 -> V_22 ) ;
if ( V_130 )
F_60 ( V_6 -> V_7 ) ;
return V_130 ;
}
static void F_61 ( struct V_5 * V_6 ,
struct V_131 * V_132 ,
int V_133 , T_3 * V_134 )
{
struct V_76 * V_77 ;
struct V_135 {
struct V_79 V_80 ;
struct V_81 V_6 ;
struct V_82 V_48 ;
} V_87 * V_136 ;
struct V_137 * V_138 ;
T_2 V_139 ;
struct V_131 * V_7 ;
struct V_8 * V_9 ;
V_9 = V_6 -> V_60 ;
V_7 = V_6 -> V_7 ;
if ( ! V_9 || ( V_133 && ! V_7 -> V_140 ) )
return;
V_139 = sizeof( * V_136 ) + V_133 * sizeof( * V_138 ) ;
V_77 = F_47 ( V_139 ) ;
if ( ! V_77 )
return;
V_136 = (struct V_135 * ) V_77 -> V_91 ;
memset ( V_136 , 0 , V_139 ) ;
memcpy ( V_136 -> V_80 . V_92 , V_9 -> V_42 , V_49 ) ;
memcpy ( V_136 -> V_80 . V_94 , V_134 , V_49 ) ;
V_136 -> V_80 . V_96 = F_48 ( V_97 ) ;
V_136 -> V_6 . V_98 = F_49 ( V_99 ) ;
V_136 -> V_6 . V_100 = F_48 ( V_141 ) ;
V_136 -> V_6 . V_102 = V_142 ;
V_136 -> V_6 . V_104 = F_48 ( ( sizeof( V_136 -> V_48 ) +
V_133 * sizeof( * V_138 ) ) / V_105 ) ;
V_136 -> V_6 . V_106 = F_48 ( V_107 ) ;
if ( V_6 -> V_108 )
V_136 -> V_6 . V_106 |= F_48 ( V_109 ) ;
V_136 -> V_48 . V_110 . V_111 = V_112 ;
V_136 -> V_48 . V_110 . V_113 = sizeof( V_136 -> V_48 ) / V_105 ;
memcpy ( V_136 -> V_48 . V_114 , V_6 -> V_95 , V_49 ) ;
if ( V_133 ) {
V_138 = (struct V_137 * ) ( V_136 + 1 ) ;
V_138 -> V_110 . V_111 = V_143 ;
V_138 -> V_110 . V_113 = sizeof( * V_138 ) / V_105 ;
memcpy ( V_138 -> V_114 , V_6 -> V_144 ( V_132 ) , V_49 ) ;
F_8 ( V_138 -> V_145 , V_132 -> V_140 ) ;
F_50 ( V_132 -> V_146 , & V_138 -> V_147 ) ;
}
F_51 ( V_77 , V_139 ) ;
V_77 -> V_119 = F_48 ( V_97 ) ;
V_77 -> V_50 = V_6 -> V_50 ;
F_52 ( V_77 ) ;
F_53 ( V_77 ) ;
V_6 -> V_120 ( V_6 , V_77 ) ;
}
static int F_62 ( struct V_5 * V_6 , struct V_131 * V_132 ,
T_3 V_148 , struct V_76 * V_77 , T_2 V_149 )
{
struct V_150 {
struct V_79 V_80 ;
struct V_81 V_6 ;
struct V_151 V_152 ;
} V_87 * V_153 ;
struct V_73 * V_154 ;
struct V_82 * V_48 ;
struct V_8 * V_9 ;
T_4 V_155 ;
T_1 V_106 ;
T_3 V_156 ;
V_154 = (struct V_73 * ) V_77 -> V_91 ;
V_156 = * ( T_3 * ) ( V_154 + 1 ) ;
V_155 = sizeof( struct V_151 ) + V_77 -> V_139 ;
V_153 = (struct V_150 * ) F_63 ( V_77 , sizeof( * V_153 ) ) ;
memset ( V_153 , 0 , sizeof( * V_153 ) ) ;
if ( V_132 -> V_157 ) {
if ( F_64 ( V_6 , V_149 , V_153 -> V_80 . V_92 ) )
return - V_158 ;
V_106 = 0 ;
} else {
V_9 = V_6 -> V_60 ;
if ( ! V_9 )
return - V_158 ;
V_106 = V_9 -> V_10 ;
V_106 &= V_6 -> V_108 ? V_109 | V_107 :
V_107 ;
if ( ! V_106 )
return - V_158 ;
memcpy ( V_153 -> V_80 . V_92 , V_9 -> V_42 , V_49 ) ;
}
memcpy ( V_153 -> V_80 . V_94 , V_6 -> V_95 , V_49 ) ;
V_153 -> V_80 . V_96 = F_48 ( V_97 ) ;
V_153 -> V_6 . V_98 = F_49 ( V_99 ) ;
V_153 -> V_6 . V_100 = F_48 ( V_159 ) ;
if ( V_156 == V_160 || V_156 == V_161 )
V_153 -> V_6 . V_102 = V_162 ;
else
V_153 -> V_6 . V_102 = V_163 ;
V_153 -> V_6 . V_106 = F_48 ( V_106 ) ;
V_153 -> V_152 . V_110 . V_111 = V_148 ;
V_153 -> V_152 . V_110 . V_113 = V_155 / V_105 ;
if ( V_156 != V_161 ) {
V_155 += sizeof( * V_48 ) ;
V_48 = (struct V_82 * ) F_51 ( V_77 , sizeof( * V_48 ) ) ;
memset ( V_48 , 0 , sizeof( * V_48 ) ) ;
V_48 -> V_110 . V_111 = V_112 ;
V_48 -> V_110 . V_113 = sizeof( * V_48 ) / V_105 ;
if ( V_148 != V_164 && V_148 != V_165 ) {
memcpy ( V_48 -> V_114 , V_6 -> V_144 ( V_132 ) , V_49 ) ;
} else if ( V_6 -> V_13 == V_14 ) {
F_8 ( V_48 -> V_114 , V_16 ) ;
F_8 ( V_48 -> V_114 + 3 , V_6 -> V_140 ) ;
} else if ( V_106 & V_109 ) {
F_4 ( V_6 , L_12 ) ;
memcpy ( V_48 -> V_114 , V_6 -> V_95 , V_49 ) ;
} else {
F_4 ( V_6 , L_13 ) ;
}
}
V_153 -> V_6 . V_104 = F_48 ( V_155 / V_105 ) ;
V_77 -> V_119 = F_48 ( V_97 ) ;
V_77 -> V_50 = V_6 -> V_50 ;
F_52 ( V_77 ) ;
F_53 ( V_77 ) ;
return 0 ;
}
int F_65 ( struct V_5 * V_6 , struct V_131 * V_132 ,
struct V_76 * V_77 )
{
struct V_166 * V_167 ;
struct V_73 * V_154 ;
T_1 V_168 ;
T_3 V_156 ;
T_3 V_48 [ V_49 ] ;
V_167 = F_66 ( V_77 , struct V_166 , V_77 ) ;
V_154 = (struct V_73 * ) V_77 -> V_91 ;
V_156 = * ( T_3 * ) ( V_154 + 1 ) ;
if ( V_156 == V_169 && V_6 -> V_13 != V_14 ) {
V_168 = V_6 -> V_24 ;
V_6 -> V_24 = F_67 ( V_154 -> V_170 ) ;
if ( V_6 -> V_2 == V_124 ) {
if ( V_168 == V_25 )
V_6 -> V_171 = 0 ;
V_6 -> V_171 ++ ;
if ( V_6 -> V_171 < 3 )
goto V_172;
F_7 ( V_6 ) ;
return 0 ;
}
if ( V_6 -> V_2 == V_123 )
F_7 ( V_6 ) ;
}
if ( V_6 -> V_2 == V_123 )
return 0 ;
if ( ! V_6 -> V_60 && V_6 -> V_13 != V_14 )
goto V_172;
switch ( V_156 ) {
case V_169 :
V_156 = V_164 ;
if ( V_6 -> V_13 == V_14 )
break;
F_38 ( & V_6 -> V_23 ) ;
F_39 ( V_6 -> V_64 ) ;
V_6 -> V_64 = V_77 ;
V_6 -> V_173 = 1 ;
F_41 ( & V_6 -> V_23 ) ;
F_68 ( & V_6 -> V_28 ) ;
return - V_174 ;
case V_175 :
if ( F_69 ( V_154 -> V_176 ) )
return 0 ;
V_156 = V_165 ;
break;
case V_177 :
if ( V_6 -> V_13 == V_14 ) {
if ( V_6 -> V_2 != V_178 )
return - V_179 ;
if ( F_69 ( V_154 -> V_180 ) == V_181 )
return - V_179 ;
} else {
if ( V_6 -> V_2 != V_182 )
return 0 ;
if ( F_69 ( V_154 -> V_180 ) != V_181 )
return 0 ;
}
V_156 = V_183 ;
break;
case V_160 :
if ( V_6 -> V_2 == V_123 ) {
if ( V_6 -> V_24 == V_25 )
return 0 ;
V_6 -> V_24 = V_25 ;
F_70 ( V_48 , V_154 -> V_180 ) ;
V_6 -> V_184 ( V_132 , V_48 ) ;
}
case V_161 :
V_156 = F_71 ( V_167 ) ;
if ( V_156 )
break;
return 0 ;
default:
if ( V_6 -> V_2 != V_182 &&
V_6 -> V_2 != V_178 )
goto V_172;
return 0 ;
}
F_4 ( V_6 , L_14 ,
V_156 , F_69 ( V_154 -> V_180 ) ) ;
if ( F_62 ( V_6 , V_132 , V_156 , V_77 , F_69 ( V_154 -> V_180 ) ) )
goto V_172;
V_6 -> V_120 ( V_6 , V_77 ) ;
return - V_174 ;
V_172:
F_39 ( V_77 ) ;
return - V_179 ;
}
static unsigned long F_72 ( struct V_5 * V_6 )
{
struct V_8 * V_9 ;
struct V_8 * V_59 ;
unsigned long V_185 = V_122 + F_73 ( V_186 ) ;
unsigned long V_187 ;
unsigned long V_61 = 0 ;
struct V_188 V_189 ;
struct V_190 * V_191 ;
F_10 ( & V_189 ) ;
V_191 = F_74 ( V_6 -> V_7 -> V_191 , F_75 () ) ;
F_32 (fcf, next, &fip->fcfs, list) {
V_187 = V_9 -> time + V_9 -> V_52 + V_9 -> V_52 / 2 ;
if ( V_6 -> V_60 == V_9 ) {
if ( F_76 ( V_122 , V_187 ) ) {
V_191 -> V_192 ++ ;
F_44 ( V_70 L_4
L_15
L_16 ,
V_6 -> V_7 -> V_68 -> V_69 , V_9 -> V_41 ,
V_191 -> V_192 ) ;
} else if ( F_76 ( V_185 , V_187 ) )
V_185 = V_187 ;
}
V_187 += V_9 -> V_52 ;
if ( F_77 ( V_122 , V_187 ) ) {
if ( V_6 -> V_60 == V_9 )
V_6 -> V_60 = NULL ;
F_27 ( & V_9 -> V_56 ) ;
F_24 ( & V_9 -> V_56 , & V_189 ) ;
V_191 -> V_193 ++ ;
} else {
if ( F_76 ( V_185 , V_187 ) )
V_185 = V_187 ;
if ( F_5 ( V_9 ) &&
( ! V_61 || F_78 ( V_61 , V_9 -> time ) ) )
V_61 = V_9 -> time ;
}
}
F_79 () ;
F_32 (fcf, next, &del_list, list) {
F_26 ( V_9 ) ;
}
if ( V_61 && ! V_6 -> V_60 && ! V_6 -> V_61 ) {
V_61 += F_73 ( V_194 ) ;
V_6 -> V_61 = V_61 ;
}
return V_185 ;
}
static int F_80 ( struct V_5 * V_6 ,
struct V_76 * V_77 , struct V_8 * V_9 )
{
struct V_81 * V_195 ;
struct V_196 * V_88 = NULL ;
struct V_83 * V_197 ;
struct V_198 * V_199 ;
struct V_200 * V_201 ;
unsigned long V_202 ;
T_4 V_203 ;
T_4 V_155 ;
T_2 V_204 ;
memset ( V_9 , 0 , sizeof( * V_9 ) ) ;
V_9 -> V_52 = F_73 ( V_205 ) ;
V_195 = (struct V_81 * ) V_77 -> V_91 ;
V_9 -> V_10 = F_67 ( V_195 -> V_106 ) ;
V_204 = F_81 ( V_206 ) | F_81 ( V_112 ) | F_81 ( V_115 ) |
F_81 ( V_207 ) | F_81 ( V_208 ) ;
V_203 = F_67 ( V_195 -> V_104 ) * 4 ;
if ( V_203 + sizeof( * V_195 ) > V_77 -> V_139 )
return - V_179 ;
V_88 = (struct V_196 * ) ( V_195 + 1 ) ;
while ( V_203 > 0 ) {
V_155 = V_88 -> V_113 * V_105 ;
if ( V_155 < sizeof( * V_88 ) || V_155 > V_203 )
return - V_179 ;
if ( ( V_88 -> V_111 < 32 ) &&
! ( V_204 & 1U << V_88 -> V_111 ) ) {
F_4 ( V_6 , L_17
L_18 ) ;
return - V_179 ;
}
switch ( V_88 -> V_111 ) {
case V_206 :
if ( V_155 != sizeof( struct V_209 ) )
goto V_210;
V_9 -> V_51 = ( (struct V_209 * ) V_88 ) -> V_211 ;
V_204 &= ~ F_81 ( V_206 ) ;
break;
case V_112 :
if ( V_155 != sizeof( struct V_82 ) )
goto V_210;
memcpy ( V_9 -> V_42 ,
( (struct V_82 * ) V_88 ) -> V_114 ,
V_49 ) ;
memcpy ( V_9 -> V_71 , V_9 -> V_42 , V_49 ) ;
if ( ! F_82 ( V_9 -> V_42 ) ) {
F_4 ( V_6 ,
L_19 ,
V_9 -> V_42 ) ;
return - V_179 ;
}
V_204 &= ~ F_81 ( V_112 ) ;
break;
case V_115 :
if ( V_155 != sizeof( struct V_83 ) )
goto V_210;
V_197 = (struct V_83 * ) V_88 ;
V_9 -> V_45 = F_83 ( & V_197 -> V_116 ) ;
V_204 &= ~ F_81 ( V_115 ) ;
break;
case V_207 :
if ( V_155 != sizeof( struct V_198 ) )
goto V_210;
V_199 = (struct V_198 * ) V_88 ;
V_9 -> V_41 = F_83 ( & V_199 -> V_116 ) ;
V_9 -> V_47 = F_67 ( V_199 -> V_212 ) ;
V_9 -> V_46 = F_69 ( V_199 -> V_213 ) ;
V_204 &= ~ F_81 ( V_207 ) ;
break;
case V_208 :
if ( V_155 != sizeof( struct V_200 ) )
goto V_210;
V_201 = (struct V_200 * ) V_88 ;
if ( V_201 -> V_214 & V_215 )
V_9 -> V_214 = 1 ;
V_202 = F_84 ( V_201 -> V_216 ) ;
if ( V_202 >= V_217 )
V_9 -> V_52 = F_73 ( V_202 ) ;
V_204 &= ~ F_81 ( V_208 ) ;
break;
case V_218 :
case V_117 :
case V_164 :
case V_165 :
case V_183 :
case V_219 :
default:
F_4 ( V_6 , L_20
L_21 , V_88 -> V_111 ) ;
if ( V_88 -> V_111 < V_220 )
return - V_179 ;
break;
}
V_88 = (struct V_196 * ) ( ( char * ) V_88 + V_155 ) ;
V_203 -= V_155 ;
}
if ( ! V_9 -> V_46 || ( V_9 -> V_46 & 0x10000 ) )
return - V_179 ;
if ( ! V_9 -> V_45 )
return - V_179 ;
if ( V_204 ) {
F_4 ( V_6 , L_22 ,
V_204 ) ;
return - V_179 ;
}
return 0 ;
V_210:
F_4 ( V_6 , L_23 ,
V_88 -> V_111 , V_155 ) ;
return - V_179 ;
}
static void F_85 ( struct V_5 * V_6 , struct V_76 * V_77 )
{
struct V_8 * V_9 ;
struct V_8 V_33 ;
unsigned long V_221 = F_73 ( V_222 ) ;
int V_223 = 0 ;
int V_224 ;
int V_225 = 0 ;
int V_39 = 0 ;
if ( F_80 ( V_6 , V_77 , & V_33 ) )
return;
F_19 ( & V_6 -> V_22 ) ;
V_223 = F_86 ( & V_6 -> V_21 ) ;
F_40 (fcf, &fip->fcfs, list) {
if ( V_9 -> V_45 == V_33 . V_45 &&
V_9 -> V_41 == V_33 . V_41 &&
V_9 -> V_46 == V_33 . V_46 &&
F_42 ( V_9 -> V_42 , V_33 . V_42 ) ) {
V_225 = 1 ;
break;
}
}
if ( ! V_225 ) {
if ( V_6 -> V_57 >= V_226 )
goto V_44;
V_9 = F_87 ( sizeof( * V_9 ) , V_227 ) ;
if ( ! V_9 )
goto V_44;
memcpy ( V_9 , & V_33 , sizeof( V_33 ) ) ;
V_9 -> V_6 = V_6 ;
V_39 = F_16 ( V_9 ) ;
if ( V_39 ) {
F_44 ( V_228 L_24
L_25 ,
V_33 . V_41 , V_33 . V_42 ) ;
F_25 ( V_9 ) ;
goto V_44;
}
} else {
V_9 -> V_214 = V_33 . V_214 ;
if ( ! F_6 ( V_9 ) )
V_9 -> V_10 = V_33 . V_10 ;
if ( V_9 == V_6 -> V_60 && ! V_9 -> V_214 ) {
V_6 -> V_128 -= V_9 -> V_52 ;
V_6 -> V_128 += V_33 . V_52 ;
if ( F_78 ( V_6 -> V_128 , V_6 -> V_26 . V_229 ) )
F_88 ( & V_6 -> V_26 , V_6 -> V_128 ) ;
}
V_9 -> V_52 = V_33 . V_52 ;
memcpy ( V_9 -> V_42 , V_33 . V_42 , V_49 ) ;
}
V_224 = F_5 ( V_9 ) ;
V_9 -> time = V_122 ;
if ( ! V_225 )
F_4 ( V_6 , L_3 ,
V_9 -> V_41 , V_9 -> V_42 ) ;
if ( ! V_224 )
F_46 ( V_6 , V_9 ) ;
if ( V_223 && F_76 ( V_122 , V_6 -> V_121 + V_221 ) )
F_46 ( V_6 , NULL ) ;
if ( V_224 )
F_89 ( & V_9 -> V_56 , & V_6 -> V_21 ) ;
if ( V_224 && ! V_6 -> V_60 && ! V_6 -> V_61 &&
F_6 ( V_9 ) ) {
V_6 -> V_61 = V_122 +
F_73 ( V_194 ) ;
if ( ! F_90 ( & V_6 -> V_26 ) ||
F_78 ( V_6 -> V_61 , V_6 -> V_26 . V_229 ) )
F_88 ( & V_6 -> V_26 , V_6 -> V_61 ) ;
}
V_44:
F_22 ( & V_6 -> V_22 ) ;
}
static void F_91 ( struct V_5 * V_6 , struct V_76 * V_77 )
{
struct V_131 * V_132 = V_6 -> V_7 ;
struct V_81 * V_195 ;
struct V_166 * V_167 = (struct V_166 * ) V_77 ;
struct V_73 * V_154 = NULL ;
struct V_196 * V_88 ;
struct V_151 * V_230 ;
struct V_8 * V_63 ;
struct V_190 * V_191 ;
enum V_231 V_232 = 0 ;
T_3 V_233 ;
T_3 V_234 ;
T_3 V_235 [ V_49 ] = { 0 } ;
T_4 V_236 = 0 ;
T_4 V_203 ;
T_4 V_155 ;
T_2 V_204 = 0 ;
T_2 V_237 = 0 ;
V_195 = (struct V_81 * ) V_77 -> V_91 ;
V_234 = V_195 -> V_102 ;
if ( V_234 != V_163 && V_234 != V_162 )
goto V_172;
V_203 = F_67 ( V_195 -> V_104 ) * 4 ;
if ( V_203 + sizeof( * V_195 ) > V_77 -> V_139 )
goto V_172;
V_88 = (struct V_196 * ) ( V_195 + 1 ) ;
while ( V_203 > 0 ) {
V_237 ++ ;
V_155 = V_88 -> V_113 * V_105 ;
if ( V_155 < sizeof( * V_88 ) || V_155 > V_203 )
goto V_172;
if ( V_88 -> V_111 < 32 ) {
if ( ( V_88 -> V_111 != V_112 ) &&
( V_204 & 1U << V_88 -> V_111 ) ) {
F_4 ( V_6 , L_17
L_26 ) ;
goto V_172;
}
V_204 |= ( 1 << V_88 -> V_111 ) ;
}
switch ( V_88 -> V_111 ) {
case V_112 :
V_63 = V_6 -> V_60 ;
if ( V_237 == 1 ) {
F_4 ( V_6 , L_27
L_28 ) ;
goto V_172;
}
if ( V_237 == 2 )
memcpy ( V_235 ,
( (struct V_82 * ) V_88 ) -> V_114 ,
V_49 ) ;
if ( V_155 != sizeof( struct V_82 ) )
goto V_210;
if ( ( V_237 == 3 ) && ( V_63 ) )
memcpy ( V_63 -> V_71 ,
( (struct V_82 * ) V_88 ) -> V_114 ,
V_49 ) ;
break;
case V_164 :
case V_165 :
case V_183 :
case V_219 :
if ( V_237 != 1 ) {
F_4 ( V_6 , L_27
L_28 ) ;
goto V_172;
}
if ( V_154 )
goto V_172;
if ( V_155 < sizeof( * V_230 ) + sizeof( * V_154 ) + 1 )
goto V_210;
V_236 = V_155 - sizeof( * V_230 ) ;
V_230 = (struct V_151 * ) V_88 ;
V_154 = (struct V_73 * ) ( V_230 + 1 ) ;
V_232 = V_88 -> V_111 ;
break;
default:
F_4 ( V_6 , L_20
L_21 , V_88 -> V_111 ) ;
if ( V_88 -> V_111 < V_220 )
goto V_172;
if ( V_237 <= 2 ) {
F_4 ( V_6 , L_27
L_28 ) ;
goto V_172;
}
break;
}
V_88 = (struct V_196 * ) ( ( char * ) V_88 + V_155 ) ;
V_203 -= V_155 ;
}
if ( ! V_154 )
goto V_172;
V_233 = * ( T_3 * ) ( V_154 + 1 ) ;
if ( ( V_232 == V_164 || V_232 == V_165 ) &&
V_234 == V_162 && V_6 -> V_13 != V_14 ) {
if ( V_233 == V_160 ) {
if ( ! F_82 ( V_235 ) ) {
F_4 ( V_6 ,
L_29 ,
V_235 ) ;
goto V_172;
}
memcpy ( F_92 ( V_167 ) -> V_235 , V_235 , V_49 ) ;
if ( V_6 -> V_24 == F_67 ( V_154 -> V_170 ) ) {
V_6 -> V_24 = V_25 ;
if ( V_232 == V_164 )
F_37 ( V_6 ) ;
}
} else if ( V_232 == V_164 &&
! F_93 ( V_6 ) )
goto V_172;
}
if ( ( V_237 == 0 ) || ( ( V_233 != V_161 ) &&
( ! ( 1U << V_112 & V_204 ) ) ) ) {
F_4 ( V_6 , L_30
L_31 ) ;
goto V_172;
}
F_94 ( V_77 , ( T_3 * ) V_154 - V_77 -> V_91 ) ;
F_95 ( V_77 , V_236 ) ;
V_167 = (struct V_166 * ) V_77 ;
F_96 ( V_167 ) ;
F_97 ( V_167 ) = V_238 ;
F_98 ( V_167 ) = V_239 ;
F_99 ( V_167 ) = V_132 ;
F_71 ( V_167 ) = V_232 ;
V_191 = F_74 ( V_132 -> V_191 , F_75 () ) ;
V_191 -> V_240 ++ ;
V_191 -> V_241 += V_77 -> V_139 / V_105 ;
F_79 () ;
F_100 ( V_132 , V_167 ) ;
return;
V_210:
F_4 ( V_6 , L_23 ,
V_88 -> V_111 , V_155 ) ;
V_172:
F_39 ( V_77 ) ;
}
static void F_101 ( struct V_5 * V_6 ,
struct V_81 * V_154 )
{
struct V_196 * V_88 ;
struct V_82 * V_242 ;
struct V_83 * V_243 ;
struct V_137 * V_244 ;
T_4 V_203 ;
T_4 V_155 ;
struct V_8 * V_9 = V_6 -> V_60 ;
struct V_131 * V_132 = V_6 -> V_7 ;
struct V_131 * V_245 = NULL ;
T_2 V_204 ;
int V_246 ;
int V_247 = 0 ;
struct V_137 * * V_248 = NULL ;
F_4 ( V_6 , L_32 ) ;
if ( ! V_9 || ! V_132 -> V_140 ) {
F_19 ( & V_6 -> V_22 ) ;
F_57 ( V_6 ) ;
F_22 ( & V_6 -> V_22 ) ;
return;
}
V_204 = F_81 ( V_112 ) | F_81 ( V_115 ) ;
V_203 = F_67 ( V_154 -> V_104 ) * V_105 ;
V_88 = (struct V_196 * ) ( V_154 + 1 ) ;
V_246 = V_203 / sizeof( * V_244 ) ;
if ( V_246 )
V_248 = F_87 ( sizeof( V_244 ) * V_246 ,
V_227 ) ;
if ( ! V_248 )
return;
V_246 = 0 ;
while ( V_203 >= sizeof( * V_88 ) ) {
V_155 = V_88 -> V_113 * V_105 ;
if ( V_155 > V_203 )
goto V_249;
if ( ( V_88 -> V_111 < 32 ) &&
( V_88 -> V_111 != V_143 ) &&
! ( V_204 & 1U << V_88 -> V_111 ) ) {
F_4 ( V_6 , L_17
L_33 ) ;
goto V_249;
}
switch ( V_88 -> V_111 ) {
case V_112 :
V_242 = (struct V_82 * ) V_88 ;
if ( V_155 < sizeof( * V_242 ) )
goto V_249;
if ( ! F_42 ( V_242 -> V_114 , V_9 -> V_42 ) )
goto V_249;
V_204 &= ~ F_81 ( V_112 ) ;
break;
case V_115 :
V_243 = (struct V_83 * ) V_88 ;
if ( V_155 < sizeof( * V_243 ) )
goto V_249;
if ( F_83 ( & V_243 -> V_116 ) != V_9 -> V_45 )
goto V_249;
V_204 &= ~ F_81 ( V_115 ) ;
break;
case V_143 :
V_244 = (struct V_137 * ) V_88 ;
if ( V_155 < sizeof( * V_244 ) )
goto V_249;
V_248 [ V_246 ++ ] = V_244 ;
V_245 = F_102 ( V_132 ,
F_69 ( V_244 -> V_145 ) ) ;
if ( V_245 && ( V_245 == V_132 ) ) {
F_19 ( & V_6 -> V_22 ) ;
F_74 ( V_132 -> V_191 ,
F_75 () ) -> V_193 ++ ;
F_79 () ;
F_57 ( V_6 ) ;
F_22 ( & V_6 -> V_22 ) ;
}
break;
default:
if ( V_88 -> V_111 < V_220 )
goto V_249;
break;
}
V_88 = (struct V_196 * ) ( ( char * ) V_88 + V_155 ) ;
V_203 -= V_155 ;
}
if ( V_204 )
F_4 ( V_6 , L_34 ,
V_204 ) ;
else if ( ! V_246 ) {
F_4 ( V_6 , L_35 ) ;
F_19 ( & V_6 -> V_22 ) ;
F_74 ( V_132 -> V_191 , F_75 () ) -> V_193 ++ ;
F_79 () ;
F_57 ( V_6 ) ;
F_22 ( & V_6 -> V_22 ) ;
F_19 ( & V_132 -> V_250 ) ;
F_40 (vn_port, &lport->vports, list)
F_103 ( V_245 ) ;
F_22 ( & V_132 -> V_250 ) ;
F_103 ( V_6 -> V_7 ) ;
F_46 ( V_6 , NULL ) ;
} else {
int V_251 ;
F_4 ( V_6 , L_36 ) ;
for ( V_251 = 0 ; V_251 < V_246 ; V_251 ++ ) {
V_244 = V_248 [ V_251 ] ;
V_245 = F_102 ( V_132 ,
F_69 ( V_244 -> V_145 ) ) ;
if ( ! V_245 )
continue;
if ( ! F_42 ( V_6 -> V_144 ( V_245 ) ,
V_244 -> V_114 ) ||
F_83 ( & V_244 -> V_147 ) !=
V_245 -> V_146 )
continue;
if ( V_245 == V_132 )
V_247 = 1 ;
else
F_103 ( V_245 ) ;
}
if ( V_247 ) {
F_103 ( V_6 -> V_7 ) ;
F_46 ( V_6 , NULL ) ;
}
}
V_249:
F_25 ( V_248 ) ;
}
void F_104 ( struct V_5 * V_6 , struct V_76 * V_77 )
{
V_77 = F_105 ( V_77 , V_227 ) ;
if ( ! V_77 )
return;
F_106 ( & V_6 -> V_32 , V_77 ) ;
F_68 ( & V_6 -> V_30 ) ;
}
static int F_107 ( struct V_5 * V_6 , struct V_76 * V_77 )
{
struct V_81 * V_195 ;
struct V_79 * V_252 ;
enum V_1 V_2 ;
bool V_253 = false ;
T_1 V_156 ;
T_3 V_234 ;
if ( F_108 ( V_77 ) )
goto V_172;
if ( V_77 -> V_139 < sizeof( * V_195 ) )
goto V_172;
V_252 = F_109 ( V_77 ) ;
if ( V_6 -> V_13 == V_14 ) {
if ( ! F_42 ( V_252 -> V_92 , V_6 -> V_95 ) &&
! F_42 ( V_252 -> V_92 , V_254 ) &&
! F_42 ( V_252 -> V_92 , V_255 ) )
goto V_172;
} else if ( ! F_42 ( V_252 -> V_92 , V_6 -> V_95 ) &&
! F_42 ( V_252 -> V_92 , V_256 ) )
goto V_172;
V_195 = (struct V_81 * ) V_77 -> V_91 ;
V_156 = F_67 ( V_195 -> V_100 ) ;
V_234 = V_195 -> V_102 ;
if ( F_110 ( V_195 -> V_98 ) != V_99 )
goto V_172;
if ( F_67 ( V_195 -> V_104 ) * V_105 + sizeof( * V_195 ) > V_77 -> V_139 )
goto V_172;
F_19 ( & V_6 -> V_22 ) ;
V_2 = V_6 -> V_2 ;
if ( V_2 == V_124 ) {
V_6 -> V_18 = 0 ;
F_3 ( V_6 , V_182 ) ;
V_2 = V_182 ;
F_4 ( V_6 , L_37 ) ;
}
V_253 = V_6 -> V_20 ;
F_22 ( & V_6 -> V_22 ) ;
if ( V_6 -> V_13 == V_14 && V_156 == V_257 )
return F_111 ( V_6 , V_77 ) ;
if ( V_253 && V_156 == V_258 ) {
F_4 ( V_6 , L_38 ) ;
return F_112 ( V_6 , V_77 ) ;
}
if ( V_2 != V_182 && V_2 != V_178 &&
V_2 != V_259 )
goto V_172;
if ( V_156 == V_159 ) {
F_91 ( V_6 , V_77 ) ;
return 0 ;
}
if ( V_2 != V_182 )
goto V_172;
if ( V_156 == V_101 && V_234 == V_260 )
F_85 ( V_6 , V_77 ) ;
else if ( V_156 == V_141 && V_234 == V_261 )
F_101 ( V_6 , V_195 ) ;
F_39 ( V_77 ) ;
return 0 ;
V_172:
F_39 ( V_77 ) ;
return - 1 ;
}
static struct V_8 * F_113 ( struct V_5 * V_6 )
{
struct V_8 * V_9 ;
struct V_8 * V_262 = V_6 -> V_60 ;
F_40 (fcf, &fip->fcfs, list) {
F_4 ( V_6 , L_39
L_40
L_41 ,
V_9 -> V_41 , V_9 -> V_47 , V_9 -> V_42 ,
V_9 -> V_46 , F_5 ( V_9 ) ,
V_9 -> V_65 , V_9 -> V_51 ) ;
if ( ! F_6 ( V_9 ) ) {
F_4 ( V_6 , L_42
L_43 ,
V_9 -> V_41 , V_9 -> V_46 ,
( V_9 -> V_10 & V_11 ) ? L_44 : L_45 ,
( V_9 -> V_10 & V_12 ) ?
L_44 : L_46 ) ;
continue;
}
if ( ! V_262 || V_9 -> V_51 < V_262 -> V_51 || V_262 -> V_65 )
V_262 = V_9 ;
if ( V_9 -> V_41 != V_262 -> V_41 ||
V_9 -> V_47 != V_262 -> V_47 ||
V_9 -> V_46 != V_262 -> V_46 ) {
F_4 ( V_6 , L_47
L_48 ) ;
return NULL ;
}
}
V_6 -> V_60 = V_262 ;
if ( V_262 ) {
F_4 ( V_6 , L_49 , V_262 -> V_42 ) ;
V_6 -> V_129 = V_122 +
F_73 ( V_186 ) ;
V_6 -> V_128 = V_122 + V_262 -> V_52 ;
if ( F_78 ( V_6 -> V_128 , V_6 -> V_26 . V_229 ) )
F_88 ( & V_6 -> V_26 , V_6 -> V_128 ) ;
}
return V_262 ;
}
static int F_114 ( struct V_5 * V_6 )
{
struct V_76 * V_77 ;
struct V_76 * V_263 ;
struct V_73 * V_154 ;
int error ;
V_263 = V_6 -> V_64 ;
if ( ! V_263 )
return - V_179 ;
V_77 = F_115 ( V_263 , V_227 ) ;
if ( ! V_77 ) {
V_77 = V_263 ;
V_6 -> V_64 = NULL ;
}
V_154 = (struct V_73 * ) V_77 -> V_91 ;
error = F_62 ( V_6 , V_6 -> V_7 , V_164 , V_77 ,
F_69 ( V_154 -> V_180 ) ) ;
if ( error ) {
F_39 ( V_77 ) ;
return error ;
}
V_6 -> V_120 ( V_6 , V_77 ) ;
V_6 -> V_60 -> V_65 = 1 ;
return 0 ;
}
static int F_93 ( struct V_5 * V_6 )
{
struct V_8 * V_9 ;
int error ;
F_19 ( & V_6 -> V_22 ) ;
F_38 ( & V_6 -> V_23 ) ;
F_4 ( V_6 , L_50 ) ;
V_9 = F_113 ( V_6 ) ;
if ( ! V_9 || V_9 -> V_65 ) {
F_39 ( V_6 -> V_64 ) ;
V_6 -> V_64 = NULL ;
error = - V_264 ;
} else {
F_46 ( V_6 , NULL ) ;
error = F_114 ( V_6 ) ;
}
F_41 ( & V_6 -> V_23 ) ;
F_22 ( & V_6 -> V_22 ) ;
return error ;
}
static void F_116 ( struct V_5 * V_6 )
{
struct V_8 * V_9 ;
F_38 ( & V_6 -> V_23 ) ;
V_9 = V_6 -> V_60 ;
if ( ! V_9 || ! V_6 -> V_173 )
goto V_66;
F_4 ( V_6 , L_51 ) ;
if ( V_9 -> V_65 ) {
F_4 ( V_6 , L_52 ) ;
V_9 = F_113 ( V_6 ) ;
if ( ! V_9 || V_9 -> V_65 ) {
F_4 ( V_6 , L_53 ) ;
F_40 (fcf, &fip->fcfs, list)
V_9 -> V_65 = 0 ;
V_9 = F_113 ( V_6 ) ;
}
}
if ( V_9 ) {
F_114 ( V_6 ) ;
V_6 -> V_173 = 0 ;
} else
F_4 ( V_6 , L_54 ) ;
V_66:
F_41 ( & V_6 -> V_23 ) ;
}
static void V_27 ( unsigned long V_265 )
{
struct V_5 * V_6 = (struct V_5 * ) V_265 ;
F_68 ( & V_6 -> V_28 ) ;
}
static void V_29 ( struct V_266 * V_267 )
{
struct V_5 * V_6 ;
struct V_131 * V_268 ;
T_3 * V_48 ;
T_3 V_269 = 0 ;
T_3 V_270 = 0 ;
T_3 V_271 = 0 ;
struct V_8 * V_63 ;
struct V_8 * V_9 ;
unsigned long V_185 ;
V_6 = F_66 ( V_267 , struct V_5 , V_28 ) ;
if ( V_6 -> V_13 == V_14 )
return F_117 ( V_6 ) ;
F_19 ( & V_6 -> V_22 ) ;
if ( V_6 -> V_2 == V_62 ) {
F_22 ( & V_6 -> V_22 ) ;
return;
}
V_9 = V_6 -> V_60 ;
V_185 = F_72 ( V_6 ) ;
V_63 = V_6 -> V_60 ;
if ( ! V_63 && V_6 -> V_61 ) {
if ( F_77 ( V_122 , V_6 -> V_61 ) ) {
V_63 = F_113 ( V_6 ) ;
V_6 -> V_61 = 0 ;
} else if ( F_76 ( V_185 , V_6 -> V_61 ) )
V_185 = V_6 -> V_61 ;
}
if ( V_63 && V_6 -> V_173 )
F_116 ( V_6 ) ;
else if ( ! V_63 && V_9 )
V_269 = 1 ;
if ( V_63 && ! V_63 -> V_214 ) {
if ( F_77 ( V_122 , V_6 -> V_128 ) ) {
V_6 -> V_128 = V_122 + V_63 -> V_52 ;
V_270 = 1 ;
}
if ( F_76 ( V_185 , V_6 -> V_128 ) )
V_185 = V_6 -> V_128 ;
if ( F_77 ( V_122 , V_6 -> V_129 ) ) {
V_6 -> V_129 = V_122 +
F_73 ( V_186 ) ;
V_271 = 1 ;
}
if ( F_76 ( V_185 , V_6 -> V_129 ) )
V_185 = V_6 -> V_129 ;
}
if ( ! F_86 ( & V_6 -> V_21 ) )
F_88 ( & V_6 -> V_26 , V_185 ) ;
F_22 ( & V_6 -> V_22 ) ;
if ( V_269 ) {
F_103 ( V_6 -> V_7 ) ;
F_46 ( V_6 , NULL ) ;
}
if ( V_270 )
F_61 ( V_6 , NULL , 0 , V_6 -> V_95 ) ;
if ( V_271 ) {
F_19 ( & V_6 -> V_7 -> V_250 ) ;
V_48 = V_6 -> V_144 ( V_6 -> V_7 ) ;
F_61 ( V_6 , V_6 -> V_7 , 1 , V_48 ) ;
F_40 (vport, &fip->lp->vports, list) {
V_48 = V_6 -> V_144 ( V_268 ) ;
F_61 ( V_6 , V_268 , 1 , V_48 ) ;
}
F_22 ( & V_6 -> V_7 -> V_250 ) ;
}
}
static void V_31 ( struct V_266 * V_30 )
{
struct V_5 * V_6 ;
struct V_76 * V_77 ;
V_6 = F_66 ( V_30 , struct V_5 , V_30 ) ;
while ( ( V_77 = F_118 ( & V_6 -> V_32 ) ) )
F_107 ( V_6 , V_77 ) ;
}
int F_119 ( struct V_5 * V_6 , struct V_131 * V_132 ,
struct V_166 * V_167 )
{
struct V_73 * V_154 ;
T_3 V_156 ;
T_3 * V_134 ;
V_134 = F_109 ( & V_167 -> V_77 ) -> V_94 ;
V_154 = F_120 ( V_167 ) ;
if ( V_154 -> V_272 != V_273 )
return 0 ;
V_156 = F_121 ( V_167 ) ;
if ( V_156 == V_160 && V_154 -> V_274 == V_275 &&
V_6 -> V_24 == F_67 ( V_154 -> V_170 ) ) {
F_19 ( & V_6 -> V_22 ) ;
if ( V_6 -> V_2 != V_124 && V_6 -> V_2 != V_123 ) {
F_22 ( & V_6 -> V_22 ) ;
return - V_179 ;
}
F_3 ( V_6 , V_123 ) ;
F_4 ( V_6 ,
L_55 ) ;
if ( F_42 ( V_134 , ( T_3 [ 6 ] ) V_276 ) ) {
F_7 ( V_6 ) ;
} else {
memcpy ( V_6 -> V_15 , V_134 , V_49 ) ;
V_6 -> V_18 = 0 ;
}
V_6 -> V_24 = V_25 ;
F_22 ( & V_6 -> V_22 ) ;
F_70 ( F_92 ( V_167 ) -> V_235 , V_154 -> V_180 ) ;
} else if ( V_156 == V_169 && V_154 -> V_274 == V_277 && V_134 ) {
F_19 ( & V_6 -> V_22 ) ;
if ( V_6 -> V_2 == V_124 || V_6 -> V_2 == V_123 ) {
memcpy ( V_6 -> V_15 , V_134 , V_49 ) ;
V_6 -> V_18 = 0 ;
if ( V_6 -> V_2 == V_124 )
F_4 ( V_6 , L_56
L_57 ) ;
F_3 ( V_6 , V_123 ) ;
}
F_22 ( & V_6 -> V_22 ) ;
}
return 0 ;
}
T_5 F_122 ( unsigned char V_48 [ V_278 ] ,
unsigned int V_279 , unsigned int V_280 )
{
T_5 V_197 ;
T_5 V_281 ;
V_281 = ( ( T_5 ) V_48 [ 0 ] << 40 ) |
( ( T_5 ) V_48 [ 1 ] << 32 ) |
( ( T_5 ) V_48 [ 2 ] << 24 ) |
( ( T_5 ) V_48 [ 3 ] << 16 ) |
( ( T_5 ) V_48 [ 4 ] << 8 ) |
( T_5 ) V_48 [ 5 ] ;
F_29 ( V_281 >= ( 1ULL << 48 ) ) ;
V_197 = V_281 | ( ( T_5 ) V_279 << 60 ) ;
switch ( V_279 ) {
case 1 :
F_29 ( V_280 != 0 ) ;
break;
case 2 :
F_29 ( V_280 >= 0xfff ) ;
V_197 |= ( T_5 ) V_280 << 48 ;
break;
default:
F_29 ( 1 ) ;
break;
}
return V_197 ;
}
static inline struct V_282 * F_123 ( struct V_283 * V_284 )
{
return (struct V_282 * ) ( V_284 + 1 ) ;
}
static void F_124 ( struct V_5 * V_6 ,
enum V_285 V_234 ,
const T_3 * V_286 , T_4 V_287 )
{
struct V_76 * V_77 ;
struct V_288 {
struct V_79 V_80 ;
struct V_81 V_6 ;
struct V_82 V_48 ;
struct V_83 V_84 ;
struct V_137 V_138 ;
} V_87 * V_289 ;
struct V_290 * V_291 ;
struct V_85 * V_86 ;
T_2 V_292 ;
T_4 V_139 ;
T_4 V_155 ;
V_139 = sizeof( * V_289 ) ;
V_155 = 0 ;
if ( V_234 == V_293 || V_234 == V_294 ) {
V_155 = sizeof( struct V_290 ) +
sizeof( struct V_85 ) ;
V_139 += V_155 ;
}
V_155 += sizeof( V_289 -> V_48 ) + sizeof( V_289 -> V_84 ) + sizeof( V_289 -> V_138 ) ;
V_139 = F_125 ( V_139 , V_287 + sizeof( struct V_79 ) ) ;
V_77 = F_47 ( V_139 ) ;
if ( ! V_77 )
return;
V_289 = (struct V_288 * ) V_77 -> V_91 ;
memset ( V_289 , 0 , V_139 ) ;
memcpy ( V_289 -> V_80 . V_92 , V_286 , V_49 ) ;
if ( V_234 == V_295 ) {
F_8 ( V_289 -> V_80 . V_94 , V_16 ) ;
F_8 ( V_289 -> V_80 . V_94 + 3 , V_6 -> V_140 ) ;
} else {
memcpy ( V_289 -> V_80 . V_94 , V_6 -> V_95 , V_49 ) ;
}
V_289 -> V_80 . V_96 = F_48 ( V_97 ) ;
V_289 -> V_6 . V_98 = F_49 ( V_99 ) ;
V_289 -> V_6 . V_100 = F_48 ( V_257 ) ;
V_289 -> V_6 . V_102 = V_234 ;
V_289 -> V_6 . V_104 = F_48 ( V_155 / V_105 ) ;
V_289 -> V_48 . V_110 . V_111 = V_112 ;
V_289 -> V_48 . V_110 . V_113 = sizeof( V_289 -> V_48 ) / V_105 ;
memcpy ( V_289 -> V_48 . V_114 , V_6 -> V_95 , V_49 ) ;
V_289 -> V_84 . V_110 . V_111 = V_115 ;
V_289 -> V_84 . V_110 . V_113 = sizeof( V_289 -> V_84 ) / V_105 ;
F_50 ( V_6 -> V_7 -> V_84 , & V_289 -> V_84 . V_116 ) ;
V_289 -> V_138 . V_110 . V_111 = V_143 ;
V_289 -> V_138 . V_110 . V_113 = sizeof( V_289 -> V_138 ) / V_105 ;
F_8 ( V_289 -> V_138 . V_114 , V_16 ) ;
F_8 ( V_289 -> V_138 . V_114 + 3 , V_6 -> V_140 ) ;
F_8 ( V_289 -> V_138 . V_145 , V_6 -> V_140 ) ;
F_50 ( V_6 -> V_7 -> V_146 , & V_289 -> V_138 . V_147 ) ;
if ( V_234 == V_293 || V_234 == V_294 ) {
V_291 = (struct V_290 * ) ( V_289 + 1 ) ;
V_291 -> V_110 . V_111 = V_296 ;
V_291 -> V_110 . V_113 = sizeof( * V_291 ) / V_105 ;
V_291 -> V_297 = V_6 -> V_7 -> V_298 ;
V_292 = 0 ;
if ( V_6 -> V_7 -> V_299 & V_300 )
V_292 |= V_301 ;
if ( V_6 -> V_7 -> V_299 & V_302 )
V_292 |= V_303 ;
V_292 <<= ( V_304 * 4 ) % 32 ;
V_291 -> V_305 . V_306 [ V_304 * 4 / 32 ] = F_126 ( V_292 ) ;
V_86 = (struct V_85 * ) ( V_291 + 1 ) ;
V_86 -> V_110 . V_111 = V_117 ;
V_86 -> V_110 . V_113 = sizeof( * V_86 ) / V_105 ;
V_86 -> V_118 = F_48 ( F_45 ( V_6 ) ) ;
}
F_51 ( V_77 , V_139 ) ;
V_77 -> V_119 = F_48 ( V_97 ) ;
V_77 -> V_50 = V_6 -> V_50 ;
F_52 ( V_77 ) ;
F_53 ( V_77 ) ;
V_6 -> V_120 ( V_6 , V_77 ) ;
}
static void F_127 ( struct V_131 * V_132 ,
struct V_283 * V_284 ,
enum V_307 V_308 )
{
struct V_5 * V_6 = V_132 -> V_309 . V_55 ;
struct V_282 * V_310 = F_123 ( V_284 ) ;
F_4 ( V_6 , L_58 ,
V_284 -> V_311 . V_140 , V_308 ) ;
F_19 ( & V_6 -> V_22 ) ;
switch ( V_308 ) {
case V_312 :
V_310 -> V_313 = 0 ;
break;
case V_314 :
case V_315 :
case V_316 :
V_310 -> V_313 ++ ;
if ( V_310 -> V_313 > V_317 ) {
F_4 ( V_6 ,
L_59 ,
V_284 -> V_311 . V_140 ) ;
V_132 -> V_318 . V_319 ( V_284 ) ;
}
break;
default:
break;
}
F_22 ( & V_6 -> V_22 ) ;
}
static void F_128 ( struct V_131 * V_132 )
{
struct V_283 * V_284 ;
F_19 ( & V_132 -> V_309 . V_320 ) ;
F_129 (rdata, &lport->disc.rports, peers)
V_132 -> V_318 . V_319 ( V_284 ) ;
V_132 -> V_309 . V_321 = NULL ;
F_22 ( & V_132 -> V_309 . V_320 ) ;
}
static void F_130 ( struct V_131 * V_132 )
{
struct V_5 * V_6 = V_132 -> V_309 . V_55 ;
F_19 ( & V_6 -> V_22 ) ;
F_128 ( V_132 ) ;
F_22 ( & V_6 -> V_22 ) ;
}
static void F_131 ( struct V_131 * V_132 )
{
F_130 ( V_132 ) ;
V_132 -> V_318 . V_322 () ;
F_132 () ;
}
static void F_133 ( struct V_5 * V_6 )
{
unsigned long V_323 ;
T_2 V_140 ;
F_128 ( V_6 -> V_7 ) ;
V_140 = V_6 -> V_140 ;
if ( V_6 -> V_324 )
V_140 = F_134 ( & V_6 -> V_325 ) & 0xffff ;
else if ( ! V_140 )
V_140 = V_6 -> V_7 -> V_146 & 0xffff ;
if ( ! V_140 || V_140 == 0xffff )
V_140 = 1 ;
V_6 -> V_140 = V_140 ;
if ( V_6 -> V_324 < V_326 ) {
V_6 -> V_324 ++ ;
V_323 = F_135 () % V_327 ;
} else
V_323 = V_328 ;
F_88 ( & V_6 -> V_26 , V_122 + F_73 ( V_323 ) ) ;
F_3 ( V_6 , V_329 ) ;
}
static void F_56 ( struct V_5 * V_6 )
{
V_6 -> V_324 = 0 ;
F_136 ( & V_6 -> V_325 , V_6 -> V_7 -> V_146 ) ;
F_133 ( V_6 ) ;
}
static int F_137 ( struct V_5 * V_6 ,
struct V_76 * V_77 ,
struct V_283 * V_284 )
{
struct V_81 * V_195 ;
struct V_196 * V_88 = NULL ;
struct V_82 * V_330 = NULL ;
struct V_83 * V_197 = NULL ;
struct V_137 * V_138 = NULL ;
struct V_85 * V_86 = NULL ;
struct V_282 * V_310 ;
T_4 V_203 ;
T_4 V_155 ;
T_2 V_204 = 0 ;
T_2 V_148 ;
T_3 V_234 ;
memset ( V_284 , 0 , sizeof( * V_284 ) + sizeof( * V_310 ) ) ;
V_310 = F_123 ( V_284 ) ;
V_195 = (struct V_81 * ) V_77 -> V_91 ;
V_310 -> V_10 = F_67 ( V_195 -> V_106 ) ;
V_234 = V_195 -> V_102 ;
switch ( V_234 ) {
case V_331 :
case V_332 :
case V_295 :
V_204 = F_81 ( V_112 ) | F_81 ( V_115 ) |
F_81 ( V_143 ) ;
break;
case V_293 :
case V_294 :
V_204 = F_81 ( V_112 ) | F_81 ( V_115 ) |
F_81 ( V_143 ) | F_81 ( V_296 ) |
F_81 ( V_117 ) ;
break;
default:
F_4 ( V_6 , L_60 , V_234 ) ;
return - V_179 ;
}
V_203 = F_67 ( V_195 -> V_104 ) * 4 ;
if ( V_203 + sizeof( * V_195 ) > V_77 -> V_139 )
return - V_179 ;
V_88 = (struct V_196 * ) ( V_195 + 1 ) ;
while ( V_203 > 0 ) {
V_155 = V_88 -> V_113 * V_105 ;
if ( V_155 < sizeof( * V_88 ) || V_155 > V_203 )
return - V_179 ;
V_148 = V_88 -> V_111 ;
if ( V_148 < 32 ) {
if ( ! ( V_204 & F_81 ( V_148 ) ) ) {
F_4 ( V_6 ,
L_61
L_62
L_63 ,
V_148 , V_234 ) ;
return - V_179 ;
}
V_204 &= ~ F_81 ( V_148 ) ;
}
switch ( V_148 ) {
case V_112 :
if ( V_155 != sizeof( struct V_82 ) )
goto V_210;
V_330 = (struct V_82 * ) V_88 ;
if ( ! F_82 ( V_330 -> V_114 ) ) {
F_4 ( V_6 ,
L_64 ,
V_330 -> V_114 ) ;
return - V_179 ;
}
memcpy ( V_310 -> V_333 , V_330 -> V_114 , V_49 ) ;
break;
case V_115 :
if ( V_155 != sizeof( struct V_83 ) )
goto V_210;
V_197 = (struct V_83 * ) V_88 ;
V_284 -> V_311 . V_334 = F_83 ( & V_197 -> V_116 ) ;
break;
case V_143 :
if ( V_155 != sizeof( struct V_137 ) )
goto V_210;
V_138 = (struct V_137 * ) V_88 ;
memcpy ( V_310 -> V_335 , V_138 -> V_114 , V_49 ) ;
V_284 -> V_311 . V_140 = F_69 ( V_138 -> V_145 ) ;
V_284 -> V_311 . V_336 = F_83 ( & V_138 -> V_147 ) ;
break;
case V_296 :
if ( V_155 != sizeof( struct V_290 ) )
goto V_210;
break;
case V_117 :
if ( V_155 != sizeof( struct V_85 ) )
goto V_210;
V_86 = (struct V_85 * ) V_88 ;
V_310 -> V_337 = F_67 ( V_86 -> V_118 ) ;
break;
default:
F_4 ( V_6 , L_20
L_65 , V_148 ) ;
if ( V_148 < V_220 )
return - V_179 ;
break;
}
V_88 = (struct V_196 * ) ( ( char * ) V_88 + V_155 ) ;
V_203 -= V_155 ;
}
return 0 ;
V_210:
F_4 ( V_6 , L_23 ,
V_148 , V_155 ) ;
return - V_179 ;
}
static void F_138 ( struct V_5 * V_6 )
{
F_124 ( V_6 , V_293 , V_254 , 0 ) ;
V_6 -> V_121 = V_122 ;
}
static void F_139 ( struct V_5 * V_6 ,
struct V_283 * V_284 )
{
struct V_282 * V_310 = F_123 ( V_284 ) ;
if ( V_284 -> V_311 . V_140 != V_6 -> V_140 )
return;
switch ( V_6 -> V_2 ) {
case V_259 :
case V_178 :
F_124 ( V_6 , V_332 ,
V_310 -> V_333 , 0 ) ;
break;
case V_338 :
case V_339 :
if ( V_6 -> V_7 -> V_146 > V_284 -> V_311 . V_336 &&
! ( V_310 -> V_10 & V_340 ) ) {
F_124 ( V_6 , V_332 ,
V_310 -> V_333 , 0 ) ;
break;
}
case V_329 :
F_133 ( V_6 ) ;
break;
default:
break;
}
}
static void F_140 ( struct V_5 * V_6 ,
struct V_283 * V_284 )
{
if ( V_284 -> V_311 . V_140 != V_6 -> V_140 )
return;
switch ( V_6 -> V_2 ) {
case V_329 :
case V_338 :
case V_339 :
case V_259 :
F_133 ( V_6 ) ;
break;
case V_178 :
F_138 ( V_6 ) ;
break;
default:
break;
}
}
static void F_141 ( struct V_5 * V_6 , struct V_283 * V_33 )
{
struct V_131 * V_132 = V_6 -> V_7 ;
struct V_283 * V_284 ;
struct V_341 * V_311 ;
struct V_282 * V_310 ;
T_2 V_140 ;
V_140 = V_33 -> V_311 . V_140 ;
if ( V_140 == V_6 -> V_140 )
return;
F_19 ( & V_132 -> V_309 . V_320 ) ;
V_284 = V_132 -> V_318 . V_342 ( V_132 , V_140 ) ;
if ( ! V_284 ) {
F_22 ( & V_132 -> V_309 . V_320 ) ;
return;
}
V_284 -> V_343 = & V_344 ;
V_284 -> V_345 = V_132 -> V_309 . V_345 ;
V_311 = & V_284 -> V_311 ;
if ( ( V_311 -> V_336 != - 1 && V_311 -> V_336 != V_33 -> V_311 . V_336 ) ||
( V_311 -> V_334 != - 1 && V_311 -> V_334 != V_33 -> V_311 . V_334 ) )
V_132 -> V_318 . V_319 ( V_284 ) ;
V_311 -> V_336 = V_33 -> V_311 . V_336 ;
V_311 -> V_334 = V_33 -> V_311 . V_334 ;
F_22 ( & V_132 -> V_309 . V_320 ) ;
V_310 = F_123 ( V_284 ) ;
F_4 ( V_6 , L_66 ,
V_140 , V_310 -> V_337 ? L_67 : L_68 ) ;
* V_310 = * F_123 ( V_33 ) ;
V_310 -> time = 0 ;
}
static int F_64 ( struct V_5 * V_6 , T_2 V_140 , T_3 * V_48 )
{
struct V_131 * V_132 = V_6 -> V_7 ;
struct V_283 * V_284 ;
struct V_282 * V_310 ;
int V_346 = - 1 ;
V_284 = V_132 -> V_318 . V_347 ( V_132 , V_140 ) ;
if ( V_284 ) {
V_310 = F_123 ( V_284 ) ;
memcpy ( V_48 , V_310 -> V_333 , V_49 ) ;
V_346 = 0 ;
F_142 ( & V_284 -> V_348 , V_132 -> V_318 . V_349 ) ;
}
return V_346 ;
}
static void F_143 ( struct V_5 * V_6 ,
struct V_283 * V_33 )
{
struct V_282 * V_310 = F_123 ( V_33 ) ;
if ( V_310 -> V_10 & V_340 ) {
F_124 ( V_6 , V_331 , V_254 , 0 ) ;
return;
}
switch ( V_6 -> V_2 ) {
case V_329 :
case V_338 :
case V_339 :
if ( V_33 -> V_311 . V_140 == V_6 -> V_140 )
F_133 ( V_6 ) ;
break;
case V_259 :
case V_178 :
if ( V_33 -> V_311 . V_140 == V_6 -> V_140 ) {
if ( V_33 -> V_311 . V_336 > V_6 -> V_7 -> V_146 ) {
F_133 ( V_6 ) ;
break;
}
F_138 ( V_6 ) ;
break;
}
F_124 ( V_6 , V_294 , V_310 -> V_333 ,
F_144 ( ( T_2 ) V_310 -> V_337 ,
F_45 ( V_6 ) ) ) ;
F_141 ( V_6 , V_33 ) ;
break;
default:
break;
}
}
static void F_145 ( struct V_5 * V_6 ,
struct V_283 * V_33 )
{
F_4 ( V_6 , L_69 ,
V_33 -> V_311 . V_140 , F_1 ( V_6 -> V_2 ) ) ;
if ( V_6 -> V_2 == V_178 || V_6 -> V_2 == V_259 )
F_141 ( V_6 , V_33 ) ;
}
static void F_146 ( struct V_5 * V_6 ,
struct V_283 * V_33 )
{
struct V_131 * V_132 = V_6 -> V_7 ;
struct V_283 * V_284 ;
struct V_282 * V_310 ;
V_310 = F_123 ( V_33 ) ;
if ( V_310 -> V_10 & V_340 ) {
F_124 ( V_6 , V_331 , V_254 , 0 ) ;
return;
}
V_284 = V_132 -> V_318 . V_347 ( V_132 , V_33 -> V_311 . V_140 ) ;
if ( V_284 ) {
if ( V_284 -> V_311 . V_334 == V_33 -> V_311 . V_334 &&
V_284 -> V_311 . V_336 == V_33 -> V_311 . V_336 ) {
V_310 = F_123 ( V_284 ) ;
if ( ! V_310 -> time && V_6 -> V_2 == V_178 )
V_132 -> V_318 . V_350 ( V_284 ) ;
V_310 -> time = V_122 ;
}
F_142 ( & V_284 -> V_348 , V_132 -> V_318 . V_349 ) ;
return;
}
if ( V_6 -> V_2 != V_178 )
return;
F_4 ( V_6 , L_70 ,
V_33 -> V_311 . V_140 ) ;
if ( F_76 ( V_122 ,
V_6 -> V_121 + F_73 ( V_351 ) ) )
F_138 ( V_6 ) ;
}
static unsigned long F_147 ( struct V_5 * V_6 )
{
struct V_131 * V_132 = V_6 -> V_7 ;
struct V_283 * V_284 ;
struct V_282 * V_310 ;
unsigned long V_352 ;
unsigned long V_187 ;
V_352 = V_122 + F_73 ( V_353 * 10 ) ;
F_19 ( & V_132 -> V_309 . V_320 ) ;
F_129 (rdata, &lport->disc.rports, peers) {
V_310 = F_123 ( V_284 ) ;
if ( ! V_310 -> time )
continue;
V_187 = V_310 -> time +
F_73 ( V_353 * 25 / 10 ) ;
if ( F_77 ( V_122 , V_187 ) ) {
V_310 -> time = 0 ;
F_4 ( V_6 ,
L_71 ,
V_284 -> V_311 . V_336 , V_284 -> V_311 . V_140 ) ;
V_132 -> V_318 . V_319 ( V_284 ) ;
} else if ( F_78 ( V_187 , V_352 ) )
V_352 = V_187 ;
}
F_22 ( & V_132 -> V_309 . V_320 ) ;
return V_352 ;
}
static int F_111 ( struct V_5 * V_6 , struct V_76 * V_77 )
{
struct V_81 * V_195 ;
enum V_285 V_234 ;
struct {
struct V_283 V_284 ;
struct V_282 V_310 ;
} V_354 ;
int V_39 ;
V_195 = (struct V_81 * ) V_77 -> V_91 ;
V_234 = V_195 -> V_102 ;
V_39 = F_137 ( V_6 , V_77 , & V_354 . V_284 ) ;
if ( V_39 ) {
F_4 ( V_6 , L_72 , V_39 ) ;
goto V_172;
}
F_19 ( & V_6 -> V_22 ) ;
switch ( V_234 ) {
case V_331 :
F_139 ( V_6 , & V_354 . V_284 ) ;
break;
case V_332 :
F_140 ( V_6 , & V_354 . V_284 ) ;
break;
case V_293 :
F_143 ( V_6 , & V_354 . V_284 ) ;
break;
case V_294 :
F_145 ( V_6 , & V_354 . V_284 ) ;
break;
case V_295 :
F_146 ( V_6 , & V_354 . V_284 ) ;
break;
default:
F_4 ( V_6 , L_73 , V_234 ) ;
V_39 = - 1 ;
break;
}
F_22 ( & V_6 -> V_22 ) ;
V_172:
F_39 ( V_77 ) ;
return V_39 ;
}
static int F_148 ( struct V_5 * V_6 ,
struct V_76 * V_77 ,
struct V_283 * V_284 )
{
struct V_81 * V_195 ;
struct V_196 * V_88 = NULL ;
struct V_82 * V_330 = NULL ;
struct V_83 * V_197 = NULL ;
struct V_282 * V_310 ;
T_4 V_203 ;
T_4 V_155 ;
T_2 V_204 = 0 ;
T_2 V_148 ;
T_3 V_234 ;
memset ( V_284 , 0 , sizeof( * V_284 ) + sizeof( * V_310 ) ) ;
V_310 = F_123 ( V_284 ) ;
V_195 = (struct V_81 * ) V_77 -> V_91 ;
V_310 -> V_10 = F_67 ( V_195 -> V_106 ) ;
V_234 = V_195 -> V_102 ;
switch ( V_234 ) {
case V_355 :
V_204 = F_81 ( V_112 ) | F_81 ( V_115 ) ;
break;
default:
F_4 ( V_6 , L_60 , V_234 ) ;
return - V_179 ;
}
V_203 = F_67 ( V_195 -> V_104 ) * 4 ;
if ( V_203 + sizeof( * V_195 ) > V_77 -> V_139 )
return - V_179 ;
V_88 = (struct V_196 * ) ( V_195 + 1 ) ;
while ( V_203 > 0 ) {
V_155 = V_88 -> V_113 * V_105 ;
if ( V_155 < sizeof( * V_88 ) || V_155 > V_203 )
return - V_179 ;
V_148 = V_88 -> V_111 ;
if ( V_148 < 32 ) {
if ( ! ( V_204 & F_81 ( V_148 ) ) ) {
F_4 ( V_6 ,
L_61
L_62
L_63 ,
V_148 , V_234 ) ;
return - V_179 ;
}
V_204 &= ~ F_81 ( V_148 ) ;
}
switch ( V_148 ) {
case V_112 :
if ( V_155 != sizeof( struct V_82 ) )
goto V_210;
V_330 = (struct V_82 * ) V_88 ;
if ( ! F_82 ( V_330 -> V_114 ) ) {
F_4 ( V_6 ,
L_64 ,
V_330 -> V_114 ) ;
return - V_179 ;
}
memcpy ( V_310 -> V_333 , V_330 -> V_114 , V_49 ) ;
break;
case V_115 :
if ( V_155 != sizeof( struct V_83 ) )
goto V_210;
V_197 = (struct V_83 * ) V_88 ;
V_284 -> V_311 . V_334 = F_83 ( & V_197 -> V_116 ) ;
break;
default:
F_4 ( V_6 , L_20
L_65 , V_148 ) ;
if ( V_148 < V_220 )
return - V_179 ;
break;
}
V_88 = (struct V_196 * ) ( ( char * ) V_88 + V_155 ) ;
V_203 -= V_155 ;
}
return 0 ;
V_210:
F_4 ( V_6 , L_23 ,
V_148 , V_155 ) ;
return - V_179 ;
}
static void F_149 ( struct V_5 * V_6 ,
enum V_356 V_234 ,
const T_3 * V_286 )
{
struct V_76 * V_77 ;
struct V_357 {
struct V_79 V_80 ;
struct V_81 V_6 ;
struct V_82 V_48 ;
struct V_358 V_359 ;
} V_87 * V_289 ;
T_4 V_139 ;
T_4 V_155 ;
V_139 = sizeof( * V_289 ) ;
V_155 = sizeof( V_289 -> V_48 ) + sizeof( V_289 -> V_359 ) ;
V_139 = F_125 ( V_139 , sizeof( struct V_79 ) ) ;
V_77 = F_47 ( V_139 ) ;
if ( ! V_77 )
return;
F_4 ( V_6 , L_74 ,
V_6 -> V_13 == V_14 ? L_75 : L_76 ,
V_6 -> V_7 -> V_359 ) ;
V_289 = (struct V_357 * ) V_77 -> V_91 ;
memset ( V_289 , 0 , V_139 ) ;
memcpy ( V_289 -> V_80 . V_92 , V_286 , V_49 ) ;
memcpy ( V_289 -> V_80 . V_94 , V_6 -> V_95 , V_49 ) ;
V_289 -> V_80 . V_96 = F_48 ( V_97 ) ;
V_289 -> V_6 . V_98 = F_49 ( V_99 ) ;
V_289 -> V_6 . V_100 = F_48 ( V_258 ) ;
V_289 -> V_6 . V_102 = V_234 ;
V_289 -> V_6 . V_104 = F_48 ( V_155 / V_105 ) ;
V_289 -> V_48 . V_110 . V_111 = V_112 ;
V_289 -> V_48 . V_110 . V_113 = sizeof( V_289 -> V_48 ) / V_105 ;
memcpy ( V_289 -> V_48 . V_114 , V_6 -> V_95 , V_49 ) ;
V_289 -> V_359 . V_110 . V_111 = V_360 ;
V_289 -> V_359 . V_110 . V_113 = sizeof( V_289 -> V_359 ) / V_105 ;
F_150 ( V_6 -> V_7 -> V_359 , & V_289 -> V_359 . V_361 ) ;
F_51 ( V_77 , V_139 ) ;
V_77 -> V_119 = F_48 ( V_97 ) ;
V_77 -> V_50 = V_6 -> V_50 ;
F_52 ( V_77 ) ;
F_53 ( V_77 ) ;
V_6 -> V_120 ( V_6 , V_77 ) ;
}
static void F_151 ( struct V_5 * V_6 ,
struct V_283 * V_284 )
{
struct V_282 * V_310 = F_123 ( V_284 ) ;
enum V_356 V_234 = V_362 ;
if ( V_6 -> V_13 == V_14 )
V_234 = V_363 ;
F_149 ( V_6 , V_234 , V_310 -> V_333 ) ;
}
static int F_112 ( struct V_5 * V_6 , struct V_76 * V_77 )
{
struct V_81 * V_195 ;
enum V_356 V_234 ;
struct {
struct V_283 V_284 ;
struct V_282 V_310 ;
} V_354 ;
int V_39 ;
V_195 = (struct V_81 * ) V_77 -> V_91 ;
V_234 = V_195 -> V_102 ;
V_39 = F_148 ( V_6 , V_77 , & V_354 . V_284 ) ;
if ( V_39 ) {
F_4 ( V_6 , L_77 , V_39 ) ;
goto V_172;
}
F_19 ( & V_6 -> V_22 ) ;
if ( V_234 == V_355 )
F_151 ( V_6 , & V_354 . V_284 ) ;
F_22 ( & V_6 -> V_22 ) ;
V_172:
F_39 ( V_77 ) ;
return V_39 ;
}
static void F_152 ( struct V_131 * V_132 , struct V_166 * V_167 )
{
struct V_364 V_365 ;
V_365 . V_366 = V_367 ;
V_365 . V_368 = V_369 ;
V_132 -> V_318 . V_370 ( V_167 , V_161 , & V_365 ) ;
F_153 ( V_167 ) ;
}
static void F_154 ( void (* F_155)( struct V_131 * ,
enum V_371 ) ,
struct V_131 * V_132 )
{
struct V_372 * V_309 = & V_132 -> V_309 ;
struct V_5 * V_6 = V_309 -> V_55 ;
F_19 ( & V_309 -> V_320 ) ;
V_309 -> V_321 = F_155 ;
V_309 -> V_345 = ( V_309 -> V_345 + 2 ) | 1 ;
V_309 -> V_373 = 1 ;
F_68 ( & V_6 -> V_28 ) ;
F_22 ( & V_309 -> V_320 ) ;
}
static void F_156 ( struct V_5 * V_6 )
{
struct V_131 * V_132 = V_6 -> V_7 ;
struct V_372 * V_309 = & V_132 -> V_309 ;
struct V_283 * V_284 ;
struct V_282 * V_310 ;
void (* F_155)( struct V_131 * , enum V_371 );
F_19 ( & V_309 -> V_320 ) ;
F_155 = V_309 -> V_373 ? V_309 -> V_321 : NULL ;
V_309 -> V_373 = 0 ;
F_129 (rdata, &disc->rports, peers) {
V_310 = F_123 ( V_284 ) ;
if ( V_310 -> time )
V_132 -> V_318 . V_350 ( V_284 ) ;
}
F_22 ( & V_309 -> V_320 ) ;
if ( F_155 )
F_155 ( V_132 , V_374 ) ;
}
static void F_117 ( struct V_5 * V_6 )
{
unsigned long V_352 ;
T_3 V_48 [ V_49 ] ;
T_2 V_375 = 0 ;
F_19 ( & V_6 -> V_22 ) ;
switch ( V_6 -> V_2 ) {
case V_329 :
F_3 ( V_6 , V_338 ) ;
F_124 ( V_6 , V_331 , V_254 , 0 ) ;
V_352 = V_122 + F_73 ( V_327 ) ;
break;
case V_338 :
F_3 ( V_6 , V_339 ) ;
F_124 ( V_6 , V_331 , V_254 , 0 ) ;
V_352 = V_122 + F_73 ( V_351 ) ;
break;
case V_339 :
F_3 ( V_6 , V_259 ) ;
V_375 = V_6 -> V_140 ;
F_8 ( V_48 , V_16 ) ;
F_8 ( V_48 + 3 , V_375 ) ;
F_7 ( V_6 ) ;
V_6 -> V_184 ( V_6 -> V_7 , V_48 ) ;
F_138 ( V_6 ) ;
V_352 = V_122 + F_73 ( V_351 ) ;
break;
case V_259 :
V_352 = V_6 -> V_121 + F_73 ( V_351 ) ;
if ( F_77 ( V_122 , V_352 ) ) {
F_3 ( V_6 , V_178 ) ;
F_124 ( V_6 , V_295 ,
V_254 , 0 ) ;
V_352 = V_122 + F_73 ( V_351 ) ;
V_6 -> V_129 = V_352 ;
}
F_156 ( V_6 ) ;
break;
case V_178 :
V_352 = F_147 ( V_6 ) ;
if ( F_77 ( V_122 , V_6 -> V_129 ) ) {
F_124 ( V_6 , V_295 ,
V_254 , 0 ) ;
V_6 -> V_129 = V_122 +
F_73 ( V_353 +
( F_135 () % V_376 ) ) ;
}
if ( F_78 ( V_6 -> V_129 , V_352 ) )
V_352 = V_6 -> V_129 ;
break;
case V_19 :
goto V_66;
default:
F_157 ( 1 , L_78 , V_6 -> V_2 ) ;
goto V_66;
}
F_88 ( & V_6 -> V_26 , V_352 ) ;
V_66:
F_22 ( & V_6 -> V_22 ) ;
if ( V_375 )
F_158 ( V_6 -> V_7 , V_375 ) ;
}
static void F_159 ( struct V_131 * V_132 , struct V_5 * V_6 ,
enum V_377 V_377 )
{
void * V_55 ;
F_29 ( V_132 -> V_2 != V_378 &&
V_132 -> V_2 != V_379 ) ;
if ( V_377 == V_14 ) {
V_132 -> V_380 = sizeof( struct V_282 ) ;
V_132 -> V_157 = 1 ;
V_132 -> V_318 . V_381 = F_152 ;
V_132 -> V_318 . V_382 = F_154 ;
V_132 -> V_318 . V_383 = F_130 ;
V_132 -> V_318 . V_384 = F_131 ;
V_55 = V_6 ;
} else {
V_132 -> V_380 = 0 ;
V_132 -> V_157 = 0 ;
V_132 -> V_318 . V_381 = NULL ;
V_132 -> V_318 . V_382 = NULL ;
V_132 -> V_318 . V_383 = NULL ;
V_132 -> V_318 . V_384 = NULL ;
V_55 = V_132 ;
}
F_160 ( V_132 , V_55 ) ;
}
int F_161 ( struct V_131 * V_132 , struct V_5 * V_6 ,
const struct V_385 * V_318 , int V_386 )
{
memcpy ( & V_132 -> V_318 , V_318 , sizeof( * V_318 ) ) ;
if ( V_386 && F_162 ( V_132 ) )
return - V_40 ;
F_163 ( V_132 ) ;
F_164 ( V_132 ) ;
F_165 ( V_132 ) ;
F_166 ( V_132 ) ;
F_167 ( V_132 ) ;
F_159 ( V_132 , V_6 , V_6 -> V_13 ) ;
return 0 ;
}
void F_168 ( struct V_36 * V_38 )
{
struct V_34 * V_35 = F_169 ( V_38 ) ;
struct V_5 * V_6 = F_170 ( V_35 ) ;
struct V_8 * V_9 ;
F_19 ( & V_6 -> V_22 ) ;
F_19 ( & V_35 -> V_54 ) ;
V_9 = F_171 ( V_38 ) ;
if ( V_9 )
V_38 -> V_53 = ( V_9 == V_6 -> V_60 ) ? 1 : 0 ;
else
V_38 -> V_53 = 0 ;
F_22 ( & V_35 -> V_54 ) ;
F_22 ( & V_6 -> V_22 ) ;
}
void F_172 ( struct V_34 * V_35 )
{
struct V_5 * V_387 = F_170 ( V_35 ) ;
struct V_131 * V_132 = V_387 -> V_7 ;
F_19 ( & V_387 -> V_22 ) ;
switch ( V_35 -> V_13 ) {
case V_388 :
V_387 -> V_13 = V_14 ;
break;
case V_389 :
default:
V_387 -> V_13 = V_126 ;
break;
}
F_22 ( & V_387 -> V_22 ) ;
F_159 ( V_132 , V_387 , V_387 -> V_13 ) ;
}
