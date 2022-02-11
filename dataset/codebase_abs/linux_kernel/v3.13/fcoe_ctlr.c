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
struct V_33 * V_34 ;
struct V_35 * V_36 , * V_37 ;
int V_38 = - V_39 ;
F_4 ( V_6 , L_3 ,
V_32 -> V_40 , V_32 -> V_41 ) ;
V_36 = F_17 ( sizeof( * V_36 ) , V_42 ) ;
if ( ! V_36 )
goto V_43;
V_36 -> V_40 = V_32 -> V_40 ;
V_36 -> V_44 = V_32 -> V_44 ;
V_36 -> V_45 = V_32 -> V_45 ;
V_36 -> V_46 = V_32 -> V_46 ;
memcpy ( V_36 -> V_47 , V_32 -> V_41 , V_48 ) ;
V_36 -> V_49 = V_32 -> V_50 ;
V_36 -> V_51 = V_32 -> V_51 ;
V_36 -> V_52 = 0 ;
V_34 = F_18 ( V_6 ) ;
if ( V_34 ) {
F_19 ( & V_34 -> V_53 ) ;
V_37 = F_20 ( V_34 , V_36 ) ;
if ( F_21 ( ! V_37 ) ) {
V_38 = - V_39 ;
F_22 ( & V_34 -> V_53 ) ;
goto V_43;
}
F_23 ( V_37 -> V_54 ) ;
V_37 -> V_54 = V_32 ;
V_32 -> V_37 = V_37 ;
F_22 ( & V_34 -> V_53 ) ;
}
F_24 ( & V_32 -> V_55 , & V_6 -> V_20 ) ;
V_6 -> V_56 ++ ;
V_38 = 0 ;
V_43:
F_25 ( V_36 ) ;
return V_38 ;
}
static void F_26 ( struct V_8 * V_32 )
{
struct V_5 * V_6 = V_32 -> V_6 ;
struct V_33 * V_57 ;
struct V_35 * V_37 ;
F_27 ( & V_32 -> V_55 ) ;
V_6 -> V_56 -- ;
V_57 = F_18 ( V_6 ) ;
if ( V_57 ) {
F_19 ( & V_57 -> V_53 ) ;
V_37 = F_28 ( V_32 ) ;
F_29 ( ! V_37 ) ;
V_32 -> V_37 = NULL ;
F_30 ( V_37 ) ;
F_25 ( V_32 ) ;
F_22 ( & V_57 -> V_53 ) ;
}
}
static void F_31 ( struct V_5 * V_6 )
{
struct V_8 * V_9 ;
struct V_8 * V_58 ;
V_6 -> V_59 = NULL ;
F_32 (fcf, next, &fip->fcfs, list) {
F_26 ( V_9 ) ;
}
F_29 ( V_6 -> V_56 ) ;
V_6 -> V_60 = 0 ;
}
void F_33 ( struct V_5 * V_6 )
{
F_34 ( & V_6 -> V_29 ) ;
F_35 ( & V_6 -> V_31 ) ;
F_19 ( & V_6 -> V_21 ) ;
F_3 ( V_6 , V_61 ) ;
F_31 ( V_6 ) ;
F_22 ( & V_6 -> V_21 ) ;
F_36 ( & V_6 -> V_25 ) ;
F_34 ( & V_6 -> V_27 ) ;
}
static void F_37 ( struct V_5 * V_6 )
{
struct V_8 * V_62 ;
struct V_8 * V_9 ;
F_19 ( & V_6 -> V_21 ) ;
F_38 ( & V_6 -> V_22 ) ;
F_39 ( V_6 -> V_63 ) ;
V_6 -> V_63 = NULL ;
F_40 (fcf, &fip->fcfs, list)
V_9 -> V_64 = 0 ;
F_41 ( & V_6 -> V_22 ) ;
V_62 = V_6 -> V_59 ;
if ( V_62 && F_42 ( V_62 -> V_41 , V_6 -> V_15 ) )
goto V_65;
if ( ! F_43 ( V_6 -> V_15 ) ) {
F_44 ( V_66 L_4
L_5 ,
V_6 -> V_7 -> V_67 -> V_68 , V_6 -> V_15 ) ;
memset ( V_6 -> V_15 , 0 , V_48 ) ;
}
if ( V_62 ) {
F_44 ( V_69 L_6
L_7 ,
V_6 -> V_7 -> V_67 -> V_68 , V_62 -> V_41 ) ;
memcpy ( V_6 -> V_15 , V_62 -> V_70 , V_48 ) ;
V_6 -> V_18 = 0 ;
}
V_65:
F_22 ( & V_6 -> V_21 ) ;
}
static inline T_2 F_45 ( struct V_5 * V_6 )
{
return V_6 -> V_7 -> V_71 + sizeof( struct V_72 ) +
sizeof( struct V_73 ) + sizeof( struct V_74 ) ;
}
static void F_46 ( struct V_5 * V_6 , struct V_8 * V_9 )
{
struct V_75 * V_76 ;
struct V_77 {
struct V_78 V_79 ;
struct V_80 V_6 ;
struct {
struct V_81 V_47 ;
struct V_82 V_83 ;
struct V_84 V_85 ;
} V_86 V_87 ;
} V_86 * V_88 ;
T_2 V_89 ;
V_76 = F_47 ( sizeof( * V_88 ) ) ;
if ( ! V_76 )
return;
V_88 = (struct V_77 * ) V_76 -> V_90 ;
memset ( V_88 , 0 , sizeof( * V_88 ) ) ;
memcpy ( V_88 -> V_79 . V_91 , V_9 ? V_9 -> V_41 : V_92 , V_48 ) ;
memcpy ( V_88 -> V_79 . V_93 , V_6 -> V_94 , V_48 ) ;
V_88 -> V_79 . V_95 = F_48 ( V_96 ) ;
V_88 -> V_6 . V_97 = F_49 ( V_98 ) ;
V_88 -> V_6 . V_99 = F_48 ( V_100 ) ;
V_88 -> V_6 . V_101 = V_102 ;
V_88 -> V_6 . V_103 = F_48 ( sizeof( V_88 -> V_87 ) / V_104 ) ;
V_88 -> V_6 . V_105 = F_48 ( V_106 ) ;
if ( V_6 -> V_107 )
V_88 -> V_6 . V_105 |= F_48 ( V_108 ) ;
V_88 -> V_87 . V_47 . V_109 . V_110 = V_111 ;
V_88 -> V_87 . V_47 . V_109 . V_112 = sizeof( V_88 -> V_87 . V_47 ) / V_104 ;
memcpy ( V_88 -> V_87 . V_47 . V_113 , V_6 -> V_94 , V_48 ) ;
V_88 -> V_87 . V_83 . V_109 . V_110 = V_114 ;
V_88 -> V_87 . V_83 . V_109 . V_112 = sizeof( V_88 -> V_87 . V_83 ) / V_104 ;
F_50 ( V_6 -> V_7 -> V_83 , & V_88 -> V_87 . V_83 . V_115 ) ;
V_89 = F_45 ( V_6 ) ;
V_88 -> V_87 . V_85 . V_109 . V_110 = V_116 ;
V_88 -> V_87 . V_85 . V_109 . V_112 = sizeof( V_88 -> V_87 . V_85 ) / V_104 ;
V_88 -> V_87 . V_85 . V_117 = F_48 ( V_89 ) ;
F_51 ( V_76 , sizeof( * V_88 ) ) ;
V_76 -> V_118 = F_48 ( V_96 ) ;
V_76 -> V_49 = V_6 -> V_49 ;
F_52 ( V_76 ) ;
F_53 ( V_76 ) ;
V_6 -> V_119 ( V_6 , V_76 ) ;
if ( ! V_9 )
V_6 -> V_120 = V_121 ;
}
void F_54 ( struct V_5 * V_6 )
{
F_19 ( & V_6 -> V_21 ) ;
if ( V_6 -> V_2 == V_122 || V_6 -> V_2 == V_123 ) {
F_22 ( & V_6 -> V_21 ) ;
F_55 ( V_6 -> V_7 ) ;
} else if ( V_6 -> V_2 == V_19 ) {
F_3 ( V_6 , V_6 -> V_13 ) ;
switch ( V_6 -> V_13 ) {
default:
F_4 ( V_6 , L_8 , V_6 -> V_13 ) ;
case V_124 :
F_4 ( V_6 , L_9 , L_10 ) ;
case V_125 :
case V_126 :
F_22 ( & V_6 -> V_21 ) ;
F_55 ( V_6 -> V_7 ) ;
F_46 ( V_6 , NULL ) ;
break;
case V_14 :
F_56 ( V_6 ) ;
F_22 ( & V_6 -> V_21 ) ;
F_55 ( V_6 -> V_7 ) ;
break;
}
} else
F_22 ( & V_6 -> V_21 ) ;
}
static void F_57 ( struct V_5 * V_6 )
{
F_31 ( V_6 ) ;
F_58 ( & V_6 -> V_25 ) ;
V_6 -> V_127 = 0 ;
V_6 -> V_128 = 0 ;
V_6 -> V_120 = 0 ;
V_6 -> V_23 = V_24 ;
F_7 ( V_6 ) ;
}
int F_59 ( struct V_5 * V_6 )
{
int V_129 ;
F_4 ( V_6 , L_11 ) ;
F_19 ( & V_6 -> V_21 ) ;
F_57 ( V_6 ) ;
V_129 = V_6 -> V_2 != V_19 ;
F_3 ( V_6 , V_19 ) ;
F_22 ( & V_6 -> V_21 ) ;
if ( V_129 )
F_60 ( V_6 -> V_7 ) ;
return V_129 ;
}
static void F_61 ( struct V_5 * V_6 ,
struct V_130 * V_131 ,
int V_132 , T_3 * V_133 )
{
struct V_75 * V_76 ;
struct V_134 {
struct V_78 V_79 ;
struct V_80 V_6 ;
struct V_81 V_47 ;
} V_86 * V_135 ;
struct V_136 * V_137 ;
T_2 V_138 ;
struct V_130 * V_7 ;
struct V_8 * V_9 ;
V_9 = V_6 -> V_59 ;
V_7 = V_6 -> V_7 ;
if ( ! V_9 || ( V_132 && ! V_7 -> V_139 ) )
return;
V_138 = sizeof( * V_135 ) + V_132 * sizeof( * V_137 ) ;
V_76 = F_47 ( V_138 ) ;
if ( ! V_76 )
return;
V_135 = (struct V_134 * ) V_76 -> V_90 ;
memset ( V_135 , 0 , V_138 ) ;
memcpy ( V_135 -> V_79 . V_91 , V_9 -> V_41 , V_48 ) ;
memcpy ( V_135 -> V_79 . V_93 , V_133 , V_48 ) ;
V_135 -> V_79 . V_95 = F_48 ( V_96 ) ;
V_135 -> V_6 . V_97 = F_49 ( V_98 ) ;
V_135 -> V_6 . V_99 = F_48 ( V_140 ) ;
V_135 -> V_6 . V_101 = V_141 ;
V_135 -> V_6 . V_103 = F_48 ( ( sizeof( V_135 -> V_47 ) +
V_132 * sizeof( * V_137 ) ) / V_104 ) ;
V_135 -> V_6 . V_105 = F_48 ( V_106 ) ;
if ( V_6 -> V_107 )
V_135 -> V_6 . V_105 |= F_48 ( V_108 ) ;
V_135 -> V_47 . V_109 . V_110 = V_111 ;
V_135 -> V_47 . V_109 . V_112 = sizeof( V_135 -> V_47 ) / V_104 ;
memcpy ( V_135 -> V_47 . V_113 , V_6 -> V_94 , V_48 ) ;
if ( V_132 ) {
V_137 = (struct V_136 * ) ( V_135 + 1 ) ;
V_137 -> V_109 . V_110 = V_142 ;
V_137 -> V_109 . V_112 = sizeof( * V_137 ) / V_104 ;
memcpy ( V_137 -> V_113 , V_6 -> V_143 ( V_131 ) , V_48 ) ;
F_8 ( V_137 -> V_144 , V_131 -> V_139 ) ;
F_50 ( V_131 -> V_145 , & V_137 -> V_146 ) ;
}
F_51 ( V_76 , V_138 ) ;
V_76 -> V_118 = F_48 ( V_96 ) ;
V_76 -> V_49 = V_6 -> V_49 ;
F_52 ( V_76 ) ;
F_53 ( V_76 ) ;
V_6 -> V_119 ( V_6 , V_76 ) ;
}
static int F_62 ( struct V_5 * V_6 , struct V_130 * V_131 ,
T_3 V_147 , struct V_75 * V_76 , T_2 V_148 )
{
struct V_149 {
struct V_78 V_79 ;
struct V_80 V_6 ;
struct V_150 V_151 ;
} V_86 * V_152 ;
struct V_72 * V_153 ;
struct V_81 * V_47 ;
struct V_8 * V_9 ;
T_4 V_154 ;
T_1 V_105 ;
T_3 V_155 ;
V_153 = (struct V_72 * ) V_76 -> V_90 ;
V_155 = * ( T_3 * ) ( V_153 + 1 ) ;
V_154 = sizeof( struct V_150 ) + V_76 -> V_138 ;
V_152 = (struct V_149 * ) F_63 ( V_76 , sizeof( * V_152 ) ) ;
memset ( V_152 , 0 , sizeof( * V_152 ) ) ;
if ( V_131 -> V_156 ) {
if ( F_64 ( V_6 , V_148 , V_152 -> V_79 . V_91 ) )
return - V_157 ;
V_105 = 0 ;
} else {
V_9 = V_6 -> V_59 ;
if ( ! V_9 )
return - V_157 ;
V_105 = V_9 -> V_10 ;
V_105 &= V_6 -> V_107 ? V_108 | V_106 :
V_106 ;
if ( ! V_105 )
return - V_157 ;
memcpy ( V_152 -> V_79 . V_91 , V_9 -> V_41 , V_48 ) ;
}
memcpy ( V_152 -> V_79 . V_93 , V_6 -> V_94 , V_48 ) ;
V_152 -> V_79 . V_95 = F_48 ( V_96 ) ;
V_152 -> V_6 . V_97 = F_49 ( V_98 ) ;
V_152 -> V_6 . V_99 = F_48 ( V_158 ) ;
if ( V_155 == V_159 || V_155 == V_160 )
V_152 -> V_6 . V_101 = V_161 ;
else
V_152 -> V_6 . V_101 = V_162 ;
V_152 -> V_6 . V_105 = F_48 ( V_105 ) ;
V_152 -> V_151 . V_109 . V_110 = V_147 ;
V_152 -> V_151 . V_109 . V_112 = V_154 / V_104 ;
if ( V_155 != V_160 ) {
V_154 += sizeof( * V_47 ) ;
V_47 = (struct V_81 * ) F_51 ( V_76 , sizeof( * V_47 ) ) ;
memset ( V_47 , 0 , sizeof( * V_47 ) ) ;
V_47 -> V_109 . V_110 = V_111 ;
V_47 -> V_109 . V_112 = sizeof( * V_47 ) / V_104 ;
if ( V_147 != V_163 && V_147 != V_164 ) {
memcpy ( V_47 -> V_113 , V_6 -> V_143 ( V_131 ) , V_48 ) ;
} else if ( V_6 -> V_13 == V_14 ) {
F_8 ( V_47 -> V_113 , V_16 ) ;
F_8 ( V_47 -> V_113 + 3 , V_6 -> V_139 ) ;
} else if ( V_105 & V_108 ) {
F_4 ( V_6 , L_12 ) ;
memcpy ( V_47 -> V_113 , V_6 -> V_94 , V_48 ) ;
} else {
F_4 ( V_6 , L_13 ) ;
}
}
V_152 -> V_6 . V_103 = F_48 ( V_154 / V_104 ) ;
V_76 -> V_118 = F_48 ( V_96 ) ;
V_76 -> V_49 = V_6 -> V_49 ;
F_52 ( V_76 ) ;
F_53 ( V_76 ) ;
return 0 ;
}
int F_65 ( struct V_5 * V_6 , struct V_130 * V_131 ,
struct V_75 * V_76 )
{
struct V_165 * V_166 ;
struct V_72 * V_153 ;
T_1 V_167 ;
T_3 V_155 ;
T_3 V_47 [ V_48 ] ;
V_166 = F_66 ( V_76 , struct V_165 , V_76 ) ;
V_153 = (struct V_72 * ) V_76 -> V_90 ;
V_155 = * ( T_3 * ) ( V_153 + 1 ) ;
if ( V_155 == V_168 && V_6 -> V_13 != V_14 ) {
V_167 = V_6 -> V_23 ;
V_6 -> V_23 = F_67 ( V_153 -> V_169 ) ;
if ( V_6 -> V_2 == V_123 ) {
if ( V_167 == V_24 )
V_6 -> V_170 = 0 ;
V_6 -> V_170 ++ ;
if ( V_6 -> V_170 < 3 )
goto V_171;
F_7 ( V_6 ) ;
return 0 ;
}
if ( V_6 -> V_2 == V_122 )
F_7 ( V_6 ) ;
}
if ( V_6 -> V_2 == V_122 )
return 0 ;
if ( ! V_6 -> V_59 && V_6 -> V_13 != V_14 )
goto V_171;
switch ( V_155 ) {
case V_168 :
V_155 = V_163 ;
if ( V_6 -> V_13 == V_14 )
break;
F_38 ( & V_6 -> V_22 ) ;
F_39 ( V_6 -> V_63 ) ;
V_6 -> V_63 = V_76 ;
V_6 -> V_172 = 1 ;
F_41 ( & V_6 -> V_22 ) ;
F_68 ( & V_6 -> V_27 ) ;
return - V_173 ;
case V_174 :
if ( F_69 ( V_153 -> V_175 ) )
return 0 ;
V_155 = V_164 ;
break;
case V_176 :
if ( V_6 -> V_13 == V_14 ) {
if ( V_6 -> V_2 != V_177 )
return - V_178 ;
if ( F_69 ( V_153 -> V_179 ) == V_180 )
return - V_178 ;
} else {
if ( V_6 -> V_2 != V_181 )
return 0 ;
if ( F_69 ( V_153 -> V_179 ) != V_180 )
return 0 ;
}
V_155 = V_182 ;
break;
case V_159 :
if ( V_6 -> V_2 == V_122 ) {
if ( V_6 -> V_23 == V_24 )
return 0 ;
V_6 -> V_23 = V_24 ;
F_70 ( V_47 , V_153 -> V_179 ) ;
V_6 -> V_183 ( V_131 , V_47 ) ;
}
case V_160 :
V_155 = F_71 ( V_166 ) ;
if ( V_155 )
break;
return 0 ;
default:
if ( V_6 -> V_2 != V_181 &&
V_6 -> V_2 != V_177 )
goto V_171;
return 0 ;
}
F_4 ( V_6 , L_14 ,
V_155 , F_69 ( V_153 -> V_179 ) ) ;
if ( F_62 ( V_6 , V_131 , V_155 , V_76 , F_69 ( V_153 -> V_179 ) ) )
goto V_171;
V_6 -> V_119 ( V_6 , V_76 ) ;
return - V_173 ;
V_171:
F_39 ( V_76 ) ;
return - V_178 ;
}
static unsigned long F_72 ( struct V_5 * V_6 )
{
struct V_8 * V_9 ;
struct V_8 * V_58 ;
unsigned long V_184 = V_121 + F_73 ( V_185 ) ;
unsigned long V_186 ;
unsigned long V_60 = 0 ;
struct V_187 V_188 ;
struct V_189 * V_190 ;
F_10 ( & V_188 ) ;
V_190 = F_74 ( V_6 -> V_7 -> V_190 , F_75 () ) ;
F_32 (fcf, next, &fip->fcfs, list) {
V_186 = V_9 -> time + V_9 -> V_51 + V_9 -> V_51 / 2 ;
if ( V_6 -> V_59 == V_9 ) {
if ( F_76 ( V_121 , V_186 ) ) {
V_190 -> V_191 ++ ;
F_44 ( V_69 L_4
L_15
L_16 ,
V_6 -> V_7 -> V_67 -> V_68 , V_9 -> V_40 ,
V_190 -> V_191 ) ;
} else if ( F_76 ( V_184 , V_186 ) )
V_184 = V_186 ;
}
V_186 += V_9 -> V_51 ;
if ( F_77 ( V_121 , V_186 ) ) {
if ( V_6 -> V_59 == V_9 )
V_6 -> V_59 = NULL ;
F_27 ( & V_9 -> V_55 ) ;
F_24 ( & V_9 -> V_55 , & V_188 ) ;
V_190 -> V_192 ++ ;
} else {
if ( F_76 ( V_184 , V_186 ) )
V_184 = V_186 ;
if ( F_5 ( V_9 ) &&
( ! V_60 || F_78 ( V_60 , V_9 -> time ) ) )
V_60 = V_9 -> time ;
}
}
F_79 () ;
F_32 (fcf, next, &del_list, list) {
F_26 ( V_9 ) ;
}
if ( V_60 && ! V_6 -> V_59 && ! V_6 -> V_60 ) {
V_60 += F_73 ( V_193 ) ;
V_6 -> V_60 = V_60 ;
}
return V_184 ;
}
static int F_80 ( struct V_5 * V_6 ,
struct V_75 * V_76 , struct V_8 * V_9 )
{
struct V_80 * V_194 ;
struct V_195 * V_87 = NULL ;
struct V_82 * V_196 ;
struct V_197 * V_198 ;
struct V_199 * V_200 ;
unsigned long V_201 ;
T_4 V_202 ;
T_4 V_154 ;
T_2 V_203 ;
memset ( V_9 , 0 , sizeof( * V_9 ) ) ;
V_9 -> V_51 = F_73 ( V_204 ) ;
V_194 = (struct V_80 * ) V_76 -> V_90 ;
V_9 -> V_10 = F_67 ( V_194 -> V_105 ) ;
V_203 = F_81 ( V_205 ) | F_81 ( V_111 ) | F_81 ( V_114 ) |
F_81 ( V_206 ) | F_81 ( V_207 ) ;
V_202 = F_67 ( V_194 -> V_103 ) * 4 ;
if ( V_202 + sizeof( * V_194 ) > V_76 -> V_138 )
return - V_178 ;
V_87 = (struct V_195 * ) ( V_194 + 1 ) ;
while ( V_202 > 0 ) {
V_154 = V_87 -> V_112 * V_104 ;
if ( V_154 < sizeof( * V_87 ) || V_154 > V_202 )
return - V_178 ;
if ( ( V_87 -> V_110 < 32 ) &&
! ( V_203 & 1U << V_87 -> V_110 ) ) {
F_4 ( V_6 , L_17
L_18 ) ;
return - V_178 ;
}
switch ( V_87 -> V_110 ) {
case V_205 :
if ( V_154 != sizeof( struct V_208 ) )
goto V_209;
V_9 -> V_50 = ( (struct V_208 * ) V_87 ) -> V_210 ;
V_203 &= ~ F_81 ( V_205 ) ;
break;
case V_111 :
if ( V_154 != sizeof( struct V_81 ) )
goto V_209;
memcpy ( V_9 -> V_41 ,
( (struct V_81 * ) V_87 ) -> V_113 ,
V_48 ) ;
memcpy ( V_9 -> V_70 , V_9 -> V_41 , V_48 ) ;
if ( ! F_82 ( V_9 -> V_41 ) ) {
F_4 ( V_6 ,
L_19 ,
V_9 -> V_41 ) ;
return - V_178 ;
}
V_203 &= ~ F_81 ( V_111 ) ;
break;
case V_114 :
if ( V_154 != sizeof( struct V_82 ) )
goto V_209;
V_196 = (struct V_82 * ) V_87 ;
V_9 -> V_44 = F_83 ( & V_196 -> V_115 ) ;
V_203 &= ~ F_81 ( V_114 ) ;
break;
case V_206 :
if ( V_154 != sizeof( struct V_197 ) )
goto V_209;
V_198 = (struct V_197 * ) V_87 ;
V_9 -> V_40 = F_83 ( & V_198 -> V_115 ) ;
V_9 -> V_46 = F_67 ( V_198 -> V_211 ) ;
V_9 -> V_45 = F_69 ( V_198 -> V_212 ) ;
V_203 &= ~ F_81 ( V_206 ) ;
break;
case V_207 :
if ( V_154 != sizeof( struct V_199 ) )
goto V_209;
V_200 = (struct V_199 * ) V_87 ;
if ( V_200 -> V_213 & V_214 )
V_9 -> V_213 = 1 ;
V_201 = F_84 ( V_200 -> V_215 ) ;
if ( V_201 >= V_216 )
V_9 -> V_51 = F_73 ( V_201 ) ;
V_203 &= ~ F_81 ( V_207 ) ;
break;
case V_217 :
case V_116 :
case V_163 :
case V_164 :
case V_182 :
case V_218 :
default:
F_4 ( V_6 , L_20
L_21 , V_87 -> V_110 ) ;
if ( V_87 -> V_110 < V_219 )
return - V_178 ;
break;
}
V_87 = (struct V_195 * ) ( ( char * ) V_87 + V_154 ) ;
V_202 -= V_154 ;
}
if ( ! V_9 -> V_45 || ( V_9 -> V_45 & 0x10000 ) )
return - V_178 ;
if ( ! V_9 -> V_44 )
return - V_178 ;
if ( V_203 ) {
F_4 ( V_6 , L_22 ,
V_203 ) ;
return - V_178 ;
}
return 0 ;
V_209:
F_4 ( V_6 , L_23 ,
V_87 -> V_110 , V_154 ) ;
return - V_178 ;
}
static void F_85 ( struct V_5 * V_6 , struct V_75 * V_76 )
{
struct V_8 * V_9 ;
struct V_8 V_32 ;
unsigned long V_220 = F_73 ( V_221 ) ;
int V_222 = 0 ;
int V_223 ;
int V_224 = 0 ;
int V_38 = 0 ;
if ( F_80 ( V_6 , V_76 , & V_32 ) )
return;
F_19 ( & V_6 -> V_21 ) ;
V_222 = F_86 ( & V_6 -> V_20 ) ;
F_40 (fcf, &fip->fcfs, list) {
if ( V_9 -> V_44 == V_32 . V_44 &&
V_9 -> V_40 == V_32 . V_40 &&
V_9 -> V_45 == V_32 . V_45 &&
F_42 ( V_9 -> V_41 , V_32 . V_41 ) ) {
V_224 = 1 ;
break;
}
}
if ( ! V_224 ) {
if ( V_6 -> V_56 >= V_225 )
goto V_43;
V_9 = F_87 ( sizeof( * V_9 ) , V_226 ) ;
if ( ! V_9 )
goto V_43;
memcpy ( V_9 , & V_32 , sizeof( V_32 ) ) ;
V_9 -> V_6 = V_6 ;
V_38 = F_16 ( V_9 ) ;
if ( V_38 ) {
F_44 ( V_227 L_24
L_25 ,
V_32 . V_40 , V_32 . V_41 ) ;
F_25 ( V_9 ) ;
goto V_43;
}
} else {
V_9 -> V_213 = V_32 . V_213 ;
if ( ! F_6 ( V_9 ) )
V_9 -> V_10 = V_32 . V_10 ;
if ( V_9 == V_6 -> V_59 && ! V_9 -> V_213 ) {
V_6 -> V_127 -= V_9 -> V_51 ;
V_6 -> V_127 += V_32 . V_51 ;
if ( F_78 ( V_6 -> V_127 , V_6 -> V_25 . V_228 ) )
F_88 ( & V_6 -> V_25 , V_6 -> V_127 ) ;
}
V_9 -> V_51 = V_32 . V_51 ;
memcpy ( V_9 -> V_41 , V_32 . V_41 , V_48 ) ;
}
V_223 = F_5 ( V_9 ) ;
V_9 -> time = V_121 ;
if ( ! V_224 )
F_4 ( V_6 , L_3 ,
V_9 -> V_40 , V_9 -> V_41 ) ;
if ( ! V_223 )
F_46 ( V_6 , V_9 ) ;
if ( V_222 && F_76 ( V_121 , V_6 -> V_120 + V_220 ) )
F_46 ( V_6 , NULL ) ;
if ( V_223 )
F_89 ( & V_9 -> V_55 , & V_6 -> V_20 ) ;
if ( V_223 && ! V_6 -> V_59 && F_6 ( V_9 ) ) {
V_6 -> V_60 = V_121 +
F_73 ( V_193 ) ;
if ( ! F_90 ( & V_6 -> V_25 ) ||
F_78 ( V_6 -> V_60 , V_6 -> V_25 . V_228 ) )
F_88 ( & V_6 -> V_25 , V_6 -> V_60 ) ;
}
V_43:
F_22 ( & V_6 -> V_21 ) ;
}
static void F_91 ( struct V_5 * V_6 , struct V_75 * V_76 )
{
struct V_130 * V_131 = V_6 -> V_7 ;
struct V_80 * V_194 ;
struct V_165 * V_166 = (struct V_165 * ) V_76 ;
struct V_72 * V_153 = NULL ;
struct V_195 * V_87 ;
struct V_150 * V_229 ;
struct V_8 * V_62 ;
struct V_189 * V_190 ;
enum V_230 V_231 = 0 ;
T_3 V_232 ;
T_3 V_233 ;
T_3 V_234 [ V_48 ] = { 0 } ;
T_4 V_235 = 0 ;
T_4 V_202 ;
T_4 V_154 ;
T_2 V_203 = 0 ;
T_2 V_236 = 0 ;
V_194 = (struct V_80 * ) V_76 -> V_90 ;
V_233 = V_194 -> V_101 ;
if ( V_233 != V_162 && V_233 != V_161 )
goto V_171;
V_202 = F_67 ( V_194 -> V_103 ) * 4 ;
if ( V_202 + sizeof( * V_194 ) > V_76 -> V_138 )
goto V_171;
V_87 = (struct V_195 * ) ( V_194 + 1 ) ;
while ( V_202 > 0 ) {
V_236 ++ ;
V_154 = V_87 -> V_112 * V_104 ;
if ( V_154 < sizeof( * V_87 ) || V_154 > V_202 )
goto V_171;
if ( V_87 -> V_110 < 32 ) {
if ( ( V_87 -> V_110 != V_111 ) &&
( V_203 & 1U << V_87 -> V_110 ) ) {
F_4 ( V_6 , L_17
L_26 ) ;
goto V_171;
}
V_203 |= ( 1 << V_87 -> V_110 ) ;
}
switch ( V_87 -> V_110 ) {
case V_111 :
V_62 = V_6 -> V_59 ;
if ( V_236 == 1 ) {
F_4 ( V_6 , L_27
L_28 ) ;
goto V_171;
}
if ( V_236 == 2 )
memcpy ( V_234 ,
( (struct V_81 * ) V_87 ) -> V_113 ,
V_48 ) ;
if ( V_154 != sizeof( struct V_81 ) )
goto V_209;
if ( ( V_236 == 3 ) && ( V_62 ) )
memcpy ( V_62 -> V_70 ,
( (struct V_81 * ) V_87 ) -> V_113 ,
V_48 ) ;
break;
case V_163 :
case V_164 :
case V_182 :
case V_218 :
if ( V_236 != 1 ) {
F_4 ( V_6 , L_27
L_28 ) ;
goto V_171;
}
if ( V_153 )
goto V_171;
if ( V_154 < sizeof( * V_229 ) + sizeof( * V_153 ) + 1 )
goto V_209;
V_235 = V_154 - sizeof( * V_229 ) ;
V_229 = (struct V_150 * ) V_87 ;
V_153 = (struct V_72 * ) ( V_229 + 1 ) ;
V_231 = V_87 -> V_110 ;
break;
default:
F_4 ( V_6 , L_20
L_21 , V_87 -> V_110 ) ;
if ( V_87 -> V_110 < V_219 )
goto V_171;
if ( V_236 <= 2 ) {
F_4 ( V_6 , L_27
L_28 ) ;
goto V_171;
}
break;
}
V_87 = (struct V_195 * ) ( ( char * ) V_87 + V_154 ) ;
V_202 -= V_154 ;
}
if ( ! V_153 )
goto V_171;
V_232 = * ( T_3 * ) ( V_153 + 1 ) ;
if ( ( V_231 == V_163 || V_231 == V_164 ) &&
V_233 == V_161 && V_6 -> V_13 != V_14 ) {
if ( V_232 == V_159 ) {
if ( ! F_82 ( V_234 ) ) {
F_4 ( V_6 ,
L_29 ,
V_234 ) ;
goto V_171;
}
memcpy ( F_92 ( V_166 ) -> V_234 , V_234 , V_48 ) ;
if ( V_6 -> V_23 == F_67 ( V_153 -> V_169 ) ) {
V_6 -> V_23 = V_24 ;
if ( V_231 == V_163 )
F_37 ( V_6 ) ;
}
} else if ( V_231 == V_163 &&
! F_93 ( V_6 ) )
goto V_171;
}
if ( ( V_236 == 0 ) || ( ( V_232 != V_160 ) &&
( ! ( 1U << V_111 & V_203 ) ) ) ) {
F_4 ( V_6 , L_30
L_31 ) ;
goto V_171;
}
F_94 ( V_76 , ( T_3 * ) V_153 - V_76 -> V_90 ) ;
F_95 ( V_76 , V_235 ) ;
V_166 = (struct V_165 * ) V_76 ;
F_96 ( V_166 ) ;
F_97 ( V_166 ) = V_237 ;
F_98 ( V_166 ) = V_238 ;
F_99 ( V_166 ) = V_131 ;
F_71 ( V_166 ) = V_231 ;
V_190 = F_74 ( V_131 -> V_190 , F_75 () ) ;
V_190 -> V_239 ++ ;
V_190 -> V_240 += V_76 -> V_138 / V_104 ;
F_79 () ;
F_100 ( V_131 , V_166 ) ;
return;
V_209:
F_4 ( V_6 , L_23 ,
V_87 -> V_110 , V_154 ) ;
V_171:
F_39 ( V_76 ) ;
}
static void F_101 ( struct V_5 * V_6 ,
struct V_80 * V_153 )
{
struct V_195 * V_87 ;
struct V_81 * V_241 ;
struct V_82 * V_242 ;
struct V_136 * V_243 ;
T_4 V_202 ;
T_4 V_154 ;
struct V_8 * V_9 = V_6 -> V_59 ;
struct V_130 * V_131 = V_6 -> V_7 ;
struct V_130 * V_244 = NULL ;
T_2 V_203 ;
int V_245 ;
int V_246 = 0 ;
struct V_136 * * V_247 = NULL ;
F_4 ( V_6 , L_32 ) ;
if ( ! V_9 || ! V_131 -> V_139 ) {
F_19 ( & V_6 -> V_21 ) ;
F_57 ( V_6 ) ;
F_22 ( & V_6 -> V_21 ) ;
return;
}
V_203 = F_81 ( V_111 ) | F_81 ( V_114 ) ;
V_202 = F_67 ( V_153 -> V_103 ) * V_104 ;
V_87 = (struct V_195 * ) ( V_153 + 1 ) ;
V_245 = V_202 / sizeof( * V_243 ) ;
if ( V_245 )
V_247 = F_87 ( sizeof( V_243 ) * V_245 ,
V_226 ) ;
if ( ! V_247 )
return;
V_245 = 0 ;
while ( V_202 >= sizeof( * V_87 ) ) {
V_154 = V_87 -> V_112 * V_104 ;
if ( V_154 > V_202 )
goto V_248;
if ( ( V_87 -> V_110 < 32 ) &&
( V_87 -> V_110 != V_142 ) &&
! ( V_203 & 1U << V_87 -> V_110 ) ) {
F_4 ( V_6 , L_17
L_33 ) ;
goto V_248;
}
switch ( V_87 -> V_110 ) {
case V_111 :
V_241 = (struct V_81 * ) V_87 ;
if ( V_154 < sizeof( * V_241 ) )
goto V_248;
if ( ! F_42 ( V_241 -> V_113 , V_9 -> V_41 ) )
goto V_248;
V_203 &= ~ F_81 ( V_111 ) ;
break;
case V_114 :
V_242 = (struct V_82 * ) V_87 ;
if ( V_154 < sizeof( * V_242 ) )
goto V_248;
if ( F_83 ( & V_242 -> V_115 ) != V_9 -> V_44 )
goto V_248;
V_203 &= ~ F_81 ( V_114 ) ;
break;
case V_142 :
V_243 = (struct V_136 * ) V_87 ;
if ( V_154 < sizeof( * V_243 ) )
goto V_248;
V_247 [ V_245 ++ ] = V_243 ;
V_244 = F_102 ( V_131 ,
F_69 ( V_243 -> V_144 ) ) ;
if ( V_244 && ( V_244 == V_131 ) ) {
F_19 ( & V_6 -> V_21 ) ;
F_74 ( V_131 -> V_190 ,
F_75 () ) -> V_192 ++ ;
F_79 () ;
F_57 ( V_6 ) ;
F_22 ( & V_6 -> V_21 ) ;
}
break;
default:
if ( V_87 -> V_110 < V_219 )
goto V_248;
break;
}
V_87 = (struct V_195 * ) ( ( char * ) V_87 + V_154 ) ;
V_202 -= V_154 ;
}
if ( V_203 )
F_4 ( V_6 , L_34 ,
V_203 ) ;
else if ( ! V_245 ) {
F_4 ( V_6 , L_35 ) ;
F_19 ( & V_6 -> V_21 ) ;
F_74 ( V_131 -> V_190 , F_75 () ) -> V_192 ++ ;
F_79 () ;
F_57 ( V_6 ) ;
F_22 ( & V_6 -> V_21 ) ;
F_19 ( & V_131 -> V_249 ) ;
F_40 (vn_port, &lport->vports, list)
F_103 ( V_244 ) ;
F_22 ( & V_131 -> V_249 ) ;
F_103 ( V_6 -> V_7 ) ;
F_46 ( V_6 , NULL ) ;
} else {
int V_250 ;
F_4 ( V_6 , L_36 ) ;
for ( V_250 = 0 ; V_250 < V_245 ; V_250 ++ ) {
V_243 = V_247 [ V_250 ] ;
V_244 = F_102 ( V_131 ,
F_69 ( V_243 -> V_144 ) ) ;
if ( ! V_244 )
continue;
if ( ! F_42 ( V_6 -> V_143 ( V_244 ) ,
V_243 -> V_113 ) ||
F_83 ( & V_243 -> V_146 ) !=
V_244 -> V_145 )
continue;
if ( V_244 == V_131 )
V_246 = 1 ;
else
F_103 ( V_244 ) ;
}
if ( V_246 ) {
F_103 ( V_6 -> V_7 ) ;
F_46 ( V_6 , NULL ) ;
}
}
V_248:
F_25 ( V_247 ) ;
}
void F_104 ( struct V_5 * V_6 , struct V_75 * V_76 )
{
V_76 = F_105 ( V_76 , V_226 ) ;
if ( ! V_76 )
return;
F_106 ( & V_6 -> V_31 , V_76 ) ;
F_68 ( & V_6 -> V_29 ) ;
}
static int F_107 ( struct V_5 * V_6 , struct V_75 * V_76 )
{
struct V_80 * V_194 ;
struct V_78 * V_251 ;
enum V_1 V_2 ;
T_1 V_155 ;
T_3 V_233 ;
if ( F_108 ( V_76 ) )
goto V_171;
if ( V_76 -> V_138 < sizeof( * V_194 ) )
goto V_171;
V_251 = F_109 ( V_76 ) ;
if ( V_6 -> V_13 == V_14 ) {
if ( ! F_42 ( V_251 -> V_91 , V_6 -> V_94 ) &&
! F_42 ( V_251 -> V_91 , V_252 ) &&
! F_42 ( V_251 -> V_91 , V_253 ) )
goto V_171;
} else if ( ! F_42 ( V_251 -> V_91 , V_6 -> V_94 ) &&
! F_42 ( V_251 -> V_91 , V_254 ) )
goto V_171;
V_194 = (struct V_80 * ) V_76 -> V_90 ;
V_155 = F_67 ( V_194 -> V_99 ) ;
V_233 = V_194 -> V_101 ;
if ( F_110 ( V_194 -> V_97 ) != V_98 )
goto V_171;
if ( F_67 ( V_194 -> V_103 ) * V_104 + sizeof( * V_194 ) > V_76 -> V_138 )
goto V_171;
F_19 ( & V_6 -> V_21 ) ;
V_2 = V_6 -> V_2 ;
if ( V_2 == V_123 ) {
V_6 -> V_18 = 0 ;
F_3 ( V_6 , V_181 ) ;
V_2 = V_181 ;
F_4 ( V_6 , L_37 ) ;
}
F_22 ( & V_6 -> V_21 ) ;
if ( V_6 -> V_13 == V_14 && V_155 == V_255 )
return F_111 ( V_6 , V_76 ) ;
if ( V_2 != V_181 && V_2 != V_177 &&
V_2 != V_256 )
goto V_171;
if ( V_155 == V_158 ) {
F_91 ( V_6 , V_76 ) ;
return 0 ;
}
if ( V_2 != V_181 )
goto V_171;
if ( V_155 == V_100 && V_233 == V_257 )
F_85 ( V_6 , V_76 ) ;
else if ( V_155 == V_140 && V_233 == V_258 )
F_101 ( V_6 , V_194 ) ;
F_39 ( V_76 ) ;
return 0 ;
V_171:
F_39 ( V_76 ) ;
return - 1 ;
}
static struct V_8 * F_112 ( struct V_5 * V_6 )
{
struct V_8 * V_9 ;
struct V_8 * V_259 = V_6 -> V_59 ;
F_40 (fcf, &fip->fcfs, list) {
F_4 ( V_6 , L_38
L_39
L_40 ,
V_9 -> V_40 , V_9 -> V_46 , V_9 -> V_41 ,
V_9 -> V_45 , F_5 ( V_9 ) ,
V_9 -> V_64 , V_9 -> V_50 ) ;
if ( ! F_6 ( V_9 ) ) {
F_4 ( V_6 , L_41
L_42 ,
V_9 -> V_40 , V_9 -> V_45 ,
( V_9 -> V_10 & V_11 ) ? L_43 : L_44 ,
( V_9 -> V_10 & V_12 ) ?
L_43 : L_45 ) ;
continue;
}
if ( ! V_259 || V_9 -> V_50 < V_259 -> V_50 || V_259 -> V_64 )
V_259 = V_9 ;
if ( V_9 -> V_40 != V_259 -> V_40 ||
V_9 -> V_46 != V_259 -> V_46 ||
V_9 -> V_45 != V_259 -> V_45 ) {
F_4 ( V_6 , L_46
L_47 ) ;
return NULL ;
}
}
V_6 -> V_59 = V_259 ;
if ( V_259 ) {
F_4 ( V_6 , L_48 , V_259 -> V_41 ) ;
V_6 -> V_128 = V_121 +
F_73 ( V_185 ) ;
V_6 -> V_127 = V_121 + V_259 -> V_51 ;
if ( F_78 ( V_6 -> V_127 , V_6 -> V_25 . V_228 ) )
F_88 ( & V_6 -> V_25 , V_6 -> V_127 ) ;
}
return V_259 ;
}
static int F_113 ( struct V_5 * V_6 )
{
struct V_75 * V_76 ;
struct V_75 * V_260 ;
struct V_72 * V_153 ;
int error ;
V_260 = V_6 -> V_63 ;
if ( ! V_260 )
return - V_178 ;
V_76 = F_114 ( V_260 , V_226 ) ;
if ( ! V_76 ) {
V_76 = V_260 ;
V_6 -> V_63 = NULL ;
}
V_153 = (struct V_72 * ) V_76 -> V_90 ;
error = F_62 ( V_6 , V_6 -> V_7 , V_163 , V_76 ,
F_69 ( V_153 -> V_179 ) ) ;
if ( error ) {
F_39 ( V_76 ) ;
return error ;
}
V_6 -> V_119 ( V_6 , V_76 ) ;
V_6 -> V_59 -> V_64 = 1 ;
return 0 ;
}
static int F_93 ( struct V_5 * V_6 )
{
struct V_8 * V_9 ;
int error ;
F_19 ( & V_6 -> V_21 ) ;
F_38 ( & V_6 -> V_22 ) ;
F_4 ( V_6 , L_49 ) ;
V_9 = F_112 ( V_6 ) ;
if ( ! V_9 || V_9 -> V_64 ) {
F_39 ( V_6 -> V_63 ) ;
V_6 -> V_63 = NULL ;
error = - V_261 ;
} else {
F_46 ( V_6 , NULL ) ;
error = F_113 ( V_6 ) ;
}
F_41 ( & V_6 -> V_22 ) ;
F_22 ( & V_6 -> V_21 ) ;
return error ;
}
static void F_115 ( struct V_5 * V_6 )
{
struct V_8 * V_9 ;
F_38 ( & V_6 -> V_22 ) ;
V_9 = V_6 -> V_59 ;
if ( ! V_9 || ! V_6 -> V_172 )
goto V_65;
F_4 ( V_6 , L_50 ) ;
if ( V_9 -> V_64 ) {
F_4 ( V_6 , L_51 ) ;
V_9 = F_112 ( V_6 ) ;
if ( ! V_9 || V_9 -> V_64 ) {
F_4 ( V_6 , L_52 ) ;
F_40 (fcf, &fip->fcfs, list)
V_9 -> V_64 = 0 ;
V_9 = F_112 ( V_6 ) ;
}
}
if ( V_9 ) {
F_113 ( V_6 ) ;
V_6 -> V_172 = 0 ;
} else
F_4 ( V_6 , L_53 ) ;
V_65:
F_41 ( & V_6 -> V_22 ) ;
}
static void V_26 ( unsigned long V_262 )
{
struct V_5 * V_6 = (struct V_5 * ) V_262 ;
F_68 ( & V_6 -> V_27 ) ;
}
static void V_28 ( struct V_263 * V_264 )
{
struct V_5 * V_6 ;
struct V_130 * V_265 ;
T_3 * V_47 ;
T_3 V_266 = 0 ;
T_3 V_267 = 0 ;
T_3 V_268 = 0 ;
struct V_8 * V_62 ;
struct V_8 * V_9 ;
unsigned long V_184 ;
V_6 = F_66 ( V_264 , struct V_5 , V_27 ) ;
if ( V_6 -> V_13 == V_14 )
return F_116 ( V_6 ) ;
F_19 ( & V_6 -> V_21 ) ;
if ( V_6 -> V_2 == V_61 ) {
F_22 ( & V_6 -> V_21 ) ;
return;
}
V_9 = V_6 -> V_59 ;
V_184 = F_72 ( V_6 ) ;
V_62 = V_6 -> V_59 ;
if ( ! V_62 && V_6 -> V_60 ) {
if ( F_77 ( V_121 , V_6 -> V_60 ) ) {
V_62 = F_112 ( V_6 ) ;
V_6 -> V_60 = 0 ;
} else if ( F_76 ( V_184 , V_6 -> V_60 ) )
V_184 = V_6 -> V_60 ;
}
if ( V_62 && V_6 -> V_172 )
F_115 ( V_6 ) ;
else if ( ! V_62 && V_9 )
V_266 = 1 ;
if ( V_62 && ! V_62 -> V_213 ) {
if ( F_77 ( V_121 , V_6 -> V_127 ) ) {
V_6 -> V_127 = V_121 + V_62 -> V_51 ;
V_267 = 1 ;
}
if ( F_76 ( V_184 , V_6 -> V_127 ) )
V_184 = V_6 -> V_127 ;
if ( F_77 ( V_121 , V_6 -> V_128 ) ) {
V_6 -> V_128 = V_121 +
F_73 ( V_185 ) ;
V_268 = 1 ;
}
if ( F_76 ( V_184 , V_6 -> V_128 ) )
V_184 = V_6 -> V_128 ;
}
if ( ! F_86 ( & V_6 -> V_20 ) )
F_88 ( & V_6 -> V_25 , V_184 ) ;
F_22 ( & V_6 -> V_21 ) ;
if ( V_266 ) {
F_103 ( V_6 -> V_7 ) ;
F_46 ( V_6 , NULL ) ;
}
if ( V_267 )
F_61 ( V_6 , NULL , 0 , V_6 -> V_94 ) ;
if ( V_268 ) {
F_19 ( & V_6 -> V_7 -> V_249 ) ;
V_47 = V_6 -> V_143 ( V_6 -> V_7 ) ;
F_61 ( V_6 , V_6 -> V_7 , 1 , V_47 ) ;
F_40 (vport, &fip->lp->vports, list) {
V_47 = V_6 -> V_143 ( V_265 ) ;
F_61 ( V_6 , V_265 , 1 , V_47 ) ;
}
F_22 ( & V_6 -> V_7 -> V_249 ) ;
}
}
static void V_30 ( struct V_263 * V_29 )
{
struct V_5 * V_6 ;
struct V_75 * V_76 ;
V_6 = F_66 ( V_29 , struct V_5 , V_29 ) ;
while ( ( V_76 = F_117 ( & V_6 -> V_31 ) ) )
F_107 ( V_6 , V_76 ) ;
}
int F_118 ( struct V_5 * V_6 , struct V_130 * V_131 ,
struct V_165 * V_166 )
{
struct V_72 * V_153 ;
T_3 V_155 ;
T_3 * V_133 ;
V_133 = F_109 ( & V_166 -> V_76 ) -> V_93 ;
V_153 = F_119 ( V_166 ) ;
if ( V_153 -> V_269 != V_270 )
return 0 ;
V_155 = F_120 ( V_166 ) ;
if ( V_155 == V_159 && V_153 -> V_271 == V_272 &&
V_6 -> V_23 == F_67 ( V_153 -> V_169 ) ) {
F_19 ( & V_6 -> V_21 ) ;
if ( V_6 -> V_2 != V_123 && V_6 -> V_2 != V_122 ) {
F_22 ( & V_6 -> V_21 ) ;
return - V_178 ;
}
F_3 ( V_6 , V_122 ) ;
F_4 ( V_6 ,
L_54 ) ;
if ( F_42 ( V_133 , ( T_3 [ 6 ] ) V_273 ) ) {
F_7 ( V_6 ) ;
} else {
memcpy ( V_6 -> V_15 , V_133 , V_48 ) ;
V_6 -> V_18 = 0 ;
}
V_6 -> V_23 = V_24 ;
F_22 ( & V_6 -> V_21 ) ;
F_70 ( F_92 ( V_166 ) -> V_234 , V_153 -> V_179 ) ;
} else if ( V_155 == V_168 && V_153 -> V_271 == V_274 && V_133 ) {
F_19 ( & V_6 -> V_21 ) ;
if ( V_6 -> V_2 == V_123 || V_6 -> V_2 == V_122 ) {
memcpy ( V_6 -> V_15 , V_133 , V_48 ) ;
V_6 -> V_18 = 0 ;
if ( V_6 -> V_2 == V_123 )
F_4 ( V_6 , L_55
L_56 ) ;
F_3 ( V_6 , V_122 ) ;
}
F_22 ( & V_6 -> V_21 ) ;
}
return 0 ;
}
T_5 F_121 ( unsigned char V_47 [ V_275 ] ,
unsigned int V_276 , unsigned int V_277 )
{
T_5 V_196 ;
T_5 V_278 ;
V_278 = ( ( T_5 ) V_47 [ 0 ] << 40 ) |
( ( T_5 ) V_47 [ 1 ] << 32 ) |
( ( T_5 ) V_47 [ 2 ] << 24 ) |
( ( T_5 ) V_47 [ 3 ] << 16 ) |
( ( T_5 ) V_47 [ 4 ] << 8 ) |
( T_5 ) V_47 [ 5 ] ;
F_29 ( V_278 >= ( 1ULL << 48 ) ) ;
V_196 = V_278 | ( ( T_5 ) V_276 << 60 ) ;
switch ( V_276 ) {
case 1 :
F_29 ( V_277 != 0 ) ;
break;
case 2 :
F_29 ( V_277 >= 0xfff ) ;
V_196 |= ( T_5 ) V_277 << 48 ;
break;
default:
F_29 ( 1 ) ;
break;
}
return V_196 ;
}
static inline struct V_279 * F_122 ( struct V_280 * V_281 )
{
return (struct V_279 * ) ( V_281 + 1 ) ;
}
static void F_123 ( struct V_5 * V_6 ,
enum V_282 V_233 ,
const T_3 * V_283 , T_4 V_284 )
{
struct V_75 * V_76 ;
struct V_285 {
struct V_78 V_79 ;
struct V_80 V_6 ;
struct V_81 V_47 ;
struct V_82 V_83 ;
struct V_136 V_137 ;
} V_86 * V_286 ;
struct V_287 * V_288 ;
struct V_84 * V_85 ;
T_2 V_289 ;
T_4 V_138 ;
T_4 V_154 ;
V_138 = sizeof( * V_286 ) ;
V_154 = 0 ;
if ( V_233 == V_290 || V_233 == V_291 ) {
V_154 = sizeof( struct V_287 ) +
sizeof( struct V_84 ) ;
V_138 += V_154 ;
}
V_154 += sizeof( V_286 -> V_47 ) + sizeof( V_286 -> V_83 ) + sizeof( V_286 -> V_137 ) ;
V_138 = F_124 ( V_138 , V_284 + sizeof( struct V_78 ) ) ;
V_76 = F_47 ( V_138 ) ;
if ( ! V_76 )
return;
V_286 = (struct V_285 * ) V_76 -> V_90 ;
memset ( V_286 , 0 , V_138 ) ;
memcpy ( V_286 -> V_79 . V_91 , V_283 , V_48 ) ;
if ( V_233 == V_292 ) {
F_8 ( V_286 -> V_79 . V_93 , V_16 ) ;
F_8 ( V_286 -> V_79 . V_93 + 3 , V_6 -> V_139 ) ;
} else {
memcpy ( V_286 -> V_79 . V_93 , V_6 -> V_94 , V_48 ) ;
}
V_286 -> V_79 . V_95 = F_48 ( V_96 ) ;
V_286 -> V_6 . V_97 = F_49 ( V_98 ) ;
V_286 -> V_6 . V_99 = F_48 ( V_255 ) ;
V_286 -> V_6 . V_101 = V_233 ;
V_286 -> V_6 . V_103 = F_48 ( V_154 / V_104 ) ;
V_286 -> V_47 . V_109 . V_110 = V_111 ;
V_286 -> V_47 . V_109 . V_112 = sizeof( V_286 -> V_47 ) / V_104 ;
memcpy ( V_286 -> V_47 . V_113 , V_6 -> V_94 , V_48 ) ;
V_286 -> V_83 . V_109 . V_110 = V_114 ;
V_286 -> V_83 . V_109 . V_112 = sizeof( V_286 -> V_83 ) / V_104 ;
F_50 ( V_6 -> V_7 -> V_83 , & V_286 -> V_83 . V_115 ) ;
V_286 -> V_137 . V_109 . V_110 = V_142 ;
V_286 -> V_137 . V_109 . V_112 = sizeof( V_286 -> V_137 ) / V_104 ;
F_8 ( V_286 -> V_137 . V_113 , V_16 ) ;
F_8 ( V_286 -> V_137 . V_113 + 3 , V_6 -> V_139 ) ;
F_8 ( V_286 -> V_137 . V_144 , V_6 -> V_139 ) ;
F_50 ( V_6 -> V_7 -> V_145 , & V_286 -> V_137 . V_146 ) ;
if ( V_233 == V_290 || V_233 == V_291 ) {
V_288 = (struct V_287 * ) ( V_286 + 1 ) ;
V_288 -> V_109 . V_110 = V_293 ;
V_288 -> V_109 . V_112 = sizeof( * V_288 ) / V_104 ;
V_288 -> V_294 = V_6 -> V_7 -> V_295 ;
V_289 = 0 ;
if ( V_6 -> V_7 -> V_296 & V_297 )
V_289 |= V_298 ;
if ( V_6 -> V_7 -> V_296 & V_299 )
V_289 |= V_300 ;
V_289 <<= ( V_301 * 4 ) % 32 ;
V_288 -> V_302 . V_303 [ V_301 * 4 / 32 ] = F_125 ( V_289 ) ;
V_85 = (struct V_84 * ) ( V_288 + 1 ) ;
V_85 -> V_109 . V_110 = V_116 ;
V_85 -> V_109 . V_112 = sizeof( * V_85 ) / V_104 ;
V_85 -> V_117 = F_48 ( F_45 ( V_6 ) ) ;
}
F_51 ( V_76 , V_138 ) ;
V_76 -> V_118 = F_48 ( V_96 ) ;
V_76 -> V_49 = V_6 -> V_49 ;
F_52 ( V_76 ) ;
F_53 ( V_76 ) ;
V_6 -> V_119 ( V_6 , V_76 ) ;
}
static void F_126 ( struct V_130 * V_131 ,
struct V_280 * V_281 ,
enum V_304 V_305 )
{
struct V_5 * V_6 = V_131 -> V_306 . V_54 ;
struct V_279 * V_307 = F_122 ( V_281 ) ;
F_4 ( V_6 , L_57 ,
V_281 -> V_308 . V_139 , V_305 ) ;
F_19 ( & V_6 -> V_21 ) ;
switch ( V_305 ) {
case V_309 :
V_307 -> V_310 = 0 ;
break;
case V_311 :
case V_312 :
case V_313 :
V_307 -> V_310 ++ ;
if ( V_307 -> V_310 > V_314 ) {
F_4 ( V_6 ,
L_58 ,
V_281 -> V_308 . V_139 ) ;
V_131 -> V_315 . V_316 ( V_281 ) ;
}
break;
default:
break;
}
F_22 ( & V_6 -> V_21 ) ;
}
static void F_127 ( struct V_130 * V_131 )
{
struct V_280 * V_281 ;
F_19 ( & V_131 -> V_306 . V_317 ) ;
F_128 (rdata, &lport->disc.rports, peers)
V_131 -> V_315 . V_316 ( V_281 ) ;
V_131 -> V_306 . V_318 = NULL ;
F_22 ( & V_131 -> V_306 . V_317 ) ;
}
static void F_129 ( struct V_130 * V_131 )
{
struct V_5 * V_6 = V_131 -> V_306 . V_54 ;
F_19 ( & V_6 -> V_21 ) ;
F_127 ( V_131 ) ;
F_22 ( & V_6 -> V_21 ) ;
}
static void F_130 ( struct V_130 * V_131 )
{
F_129 ( V_131 ) ;
V_131 -> V_315 . V_319 () ;
F_131 () ;
}
static void F_132 ( struct V_5 * V_6 )
{
unsigned long V_320 ;
T_2 V_139 ;
F_127 ( V_6 -> V_7 ) ;
V_139 = V_6 -> V_139 ;
if ( V_6 -> V_321 )
V_139 = F_133 ( & V_6 -> V_322 ) & 0xffff ;
else if ( ! V_139 )
V_139 = V_6 -> V_7 -> V_145 & 0xffff ;
if ( ! V_139 || V_139 == 0xffff )
V_139 = 1 ;
V_6 -> V_139 = V_139 ;
if ( V_6 -> V_321 < V_323 ) {
V_6 -> V_321 ++ ;
V_320 = F_134 () % V_324 ;
} else
V_320 = V_325 ;
F_88 ( & V_6 -> V_25 , V_121 + F_73 ( V_320 ) ) ;
F_3 ( V_6 , V_326 ) ;
}
static void F_56 ( struct V_5 * V_6 )
{
V_6 -> V_321 = 0 ;
F_135 ( & V_6 -> V_322 , V_6 -> V_7 -> V_145 ) ;
F_132 ( V_6 ) ;
}
static int F_136 ( struct V_5 * V_6 ,
struct V_75 * V_76 ,
struct V_280 * V_281 )
{
struct V_80 * V_194 ;
struct V_195 * V_87 = NULL ;
struct V_81 * V_327 = NULL ;
struct V_82 * V_196 = NULL ;
struct V_136 * V_137 = NULL ;
struct V_84 * V_85 = NULL ;
struct V_279 * V_307 ;
T_4 V_202 ;
T_4 V_154 ;
T_2 V_203 = 0 ;
T_2 V_147 ;
T_3 V_233 ;
memset ( V_281 , 0 , sizeof( * V_281 ) + sizeof( * V_307 ) ) ;
V_307 = F_122 ( V_281 ) ;
V_194 = (struct V_80 * ) V_76 -> V_90 ;
V_307 -> V_10 = F_67 ( V_194 -> V_105 ) ;
V_233 = V_194 -> V_101 ;
switch ( V_233 ) {
case V_328 :
case V_329 :
case V_292 :
V_203 = F_81 ( V_111 ) | F_81 ( V_114 ) |
F_81 ( V_142 ) ;
break;
case V_290 :
case V_291 :
V_203 = F_81 ( V_111 ) | F_81 ( V_114 ) |
F_81 ( V_142 ) | F_81 ( V_293 ) |
F_81 ( V_116 ) ;
break;
default:
F_4 ( V_6 , L_59 , V_233 ) ;
return - V_178 ;
}
V_202 = F_67 ( V_194 -> V_103 ) * 4 ;
if ( V_202 + sizeof( * V_194 ) > V_76 -> V_138 )
return - V_178 ;
V_87 = (struct V_195 * ) ( V_194 + 1 ) ;
while ( V_202 > 0 ) {
V_154 = V_87 -> V_112 * V_104 ;
if ( V_154 < sizeof( * V_87 ) || V_154 > V_202 )
return - V_178 ;
V_147 = V_87 -> V_110 ;
if ( V_147 < 32 ) {
if ( ! ( V_203 & F_81 ( V_147 ) ) ) {
F_4 ( V_6 ,
L_60
L_61
L_62 ,
V_147 , V_233 ) ;
return - V_178 ;
}
V_203 &= ~ F_81 ( V_147 ) ;
}
switch ( V_147 ) {
case V_111 :
if ( V_154 != sizeof( struct V_81 ) )
goto V_209;
V_327 = (struct V_81 * ) V_87 ;
if ( ! F_82 ( V_327 -> V_113 ) ) {
F_4 ( V_6 ,
L_63 ,
V_327 -> V_113 ) ;
return - V_178 ;
}
memcpy ( V_307 -> V_330 , V_327 -> V_113 , V_48 ) ;
break;
case V_114 :
if ( V_154 != sizeof( struct V_82 ) )
goto V_209;
V_196 = (struct V_82 * ) V_87 ;
V_281 -> V_308 . V_331 = F_83 ( & V_196 -> V_115 ) ;
break;
case V_142 :
if ( V_154 != sizeof( struct V_136 ) )
goto V_209;
V_137 = (struct V_136 * ) V_87 ;
memcpy ( V_307 -> V_332 , V_137 -> V_113 , V_48 ) ;
V_281 -> V_308 . V_139 = F_69 ( V_137 -> V_144 ) ;
V_281 -> V_308 . V_333 = F_83 ( & V_137 -> V_146 ) ;
break;
case V_293 :
if ( V_154 != sizeof( struct V_287 ) )
goto V_209;
break;
case V_116 :
if ( V_154 != sizeof( struct V_84 ) )
goto V_209;
V_85 = (struct V_84 * ) V_87 ;
V_307 -> V_334 = F_67 ( V_85 -> V_117 ) ;
break;
default:
F_4 ( V_6 , L_20
L_64 , V_147 ) ;
if ( V_147 < V_219 )
return - V_178 ;
break;
}
V_87 = (struct V_195 * ) ( ( char * ) V_87 + V_154 ) ;
V_202 -= V_154 ;
}
return 0 ;
V_209:
F_4 ( V_6 , L_23 ,
V_147 , V_154 ) ;
return - V_178 ;
}
static void F_137 ( struct V_5 * V_6 )
{
F_123 ( V_6 , V_290 , V_252 , 0 ) ;
V_6 -> V_120 = V_121 ;
}
static void F_138 ( struct V_5 * V_6 ,
struct V_280 * V_281 )
{
struct V_279 * V_307 = F_122 ( V_281 ) ;
if ( V_281 -> V_308 . V_139 != V_6 -> V_139 )
return;
switch ( V_6 -> V_2 ) {
case V_256 :
case V_177 :
F_123 ( V_6 , V_329 ,
V_307 -> V_330 , 0 ) ;
break;
case V_335 :
case V_336 :
if ( V_6 -> V_7 -> V_145 > V_281 -> V_308 . V_333 &&
! ( V_307 -> V_10 & V_337 ) ) {
F_123 ( V_6 , V_329 ,
V_307 -> V_330 , 0 ) ;
break;
}
case V_326 :
F_132 ( V_6 ) ;
break;
default:
break;
}
}
static void F_139 ( struct V_5 * V_6 ,
struct V_280 * V_281 )
{
if ( V_281 -> V_308 . V_139 != V_6 -> V_139 )
return;
switch ( V_6 -> V_2 ) {
case V_326 :
case V_335 :
case V_336 :
case V_256 :
F_132 ( V_6 ) ;
break;
case V_177 :
F_137 ( V_6 ) ;
break;
default:
break;
}
}
static void F_140 ( struct V_5 * V_6 , struct V_280 * V_32 )
{
struct V_130 * V_131 = V_6 -> V_7 ;
struct V_280 * V_281 ;
struct V_338 * V_308 ;
struct V_279 * V_307 ;
T_2 V_139 ;
V_139 = V_32 -> V_308 . V_139 ;
if ( V_139 == V_6 -> V_139 )
return;
F_19 ( & V_131 -> V_306 . V_317 ) ;
V_281 = V_131 -> V_315 . V_339 ( V_131 , V_139 ) ;
if ( ! V_281 ) {
F_22 ( & V_131 -> V_306 . V_317 ) ;
return;
}
V_281 -> V_340 = & V_341 ;
V_281 -> V_342 = V_131 -> V_306 . V_342 ;
V_308 = & V_281 -> V_308 ;
if ( ( V_308 -> V_333 != - 1 && V_308 -> V_333 != V_32 -> V_308 . V_333 ) ||
( V_308 -> V_331 != - 1 && V_308 -> V_331 != V_32 -> V_308 . V_331 ) )
V_131 -> V_315 . V_316 ( V_281 ) ;
V_308 -> V_333 = V_32 -> V_308 . V_333 ;
V_308 -> V_331 = V_32 -> V_308 . V_331 ;
F_22 ( & V_131 -> V_306 . V_317 ) ;
V_307 = F_122 ( V_281 ) ;
F_4 ( V_6 , L_65 ,
V_139 , V_307 -> V_334 ? L_66 : L_67 ) ;
* V_307 = * F_122 ( V_32 ) ;
V_307 -> time = 0 ;
}
static int F_64 ( struct V_5 * V_6 , T_2 V_139 , T_3 * V_47 )
{
struct V_130 * V_131 = V_6 -> V_7 ;
struct V_280 * V_281 ;
struct V_279 * V_307 ;
int V_343 = - 1 ;
F_141 () ;
V_281 = V_131 -> V_315 . V_344 ( V_131 , V_139 ) ;
if ( V_281 ) {
V_307 = F_122 ( V_281 ) ;
memcpy ( V_47 , V_307 -> V_330 , V_48 ) ;
V_343 = 0 ;
}
F_142 () ;
return V_343 ;
}
static void F_143 ( struct V_5 * V_6 ,
struct V_280 * V_32 )
{
struct V_279 * V_307 = F_122 ( V_32 ) ;
if ( V_307 -> V_10 & V_337 ) {
F_123 ( V_6 , V_328 , V_252 , 0 ) ;
return;
}
switch ( V_6 -> V_2 ) {
case V_326 :
case V_335 :
case V_336 :
if ( V_32 -> V_308 . V_139 == V_6 -> V_139 )
F_132 ( V_6 ) ;
break;
case V_256 :
case V_177 :
if ( V_32 -> V_308 . V_139 == V_6 -> V_139 ) {
if ( V_32 -> V_308 . V_333 > V_6 -> V_7 -> V_145 ) {
F_132 ( V_6 ) ;
break;
}
F_137 ( V_6 ) ;
break;
}
F_123 ( V_6 , V_291 , V_307 -> V_330 ,
F_144 ( ( T_2 ) V_307 -> V_334 ,
F_45 ( V_6 ) ) ) ;
F_140 ( V_6 , V_32 ) ;
break;
default:
break;
}
}
static void F_145 ( struct V_5 * V_6 ,
struct V_280 * V_32 )
{
F_4 ( V_6 , L_68 ,
V_32 -> V_308 . V_139 , F_1 ( V_6 -> V_2 ) ) ;
if ( V_6 -> V_2 == V_177 || V_6 -> V_2 == V_256 )
F_140 ( V_6 , V_32 ) ;
}
static void F_146 ( struct V_5 * V_6 ,
struct V_280 * V_32 )
{
struct V_130 * V_131 = V_6 -> V_7 ;
struct V_280 * V_281 ;
struct V_279 * V_307 ;
V_307 = F_122 ( V_32 ) ;
if ( V_307 -> V_10 & V_337 ) {
F_123 ( V_6 , V_328 , V_252 , 0 ) ;
return;
}
F_19 ( & V_131 -> V_306 . V_317 ) ;
V_281 = V_131 -> V_315 . V_344 ( V_131 , V_32 -> V_308 . V_139 ) ;
if ( V_281 )
F_147 ( & V_281 -> V_345 ) ;
F_22 ( & V_131 -> V_306 . V_317 ) ;
if ( V_281 ) {
if ( V_281 -> V_308 . V_331 == V_32 -> V_308 . V_331 &&
V_281 -> V_308 . V_333 == V_32 -> V_308 . V_333 ) {
V_307 = F_122 ( V_281 ) ;
if ( ! V_307 -> time && V_6 -> V_2 == V_177 )
V_131 -> V_315 . V_346 ( V_281 ) ;
V_307 -> time = V_121 ;
}
F_148 ( & V_281 -> V_345 , V_131 -> V_315 . V_347 ) ;
return;
}
if ( V_6 -> V_2 != V_177 )
return;
F_4 ( V_6 , L_69 ,
V_32 -> V_308 . V_139 ) ;
if ( F_76 ( V_121 ,
V_6 -> V_120 + F_73 ( V_348 ) ) )
F_137 ( V_6 ) ;
}
static unsigned long F_149 ( struct V_5 * V_6 )
{
struct V_130 * V_131 = V_6 -> V_7 ;
struct V_280 * V_281 ;
struct V_279 * V_307 ;
unsigned long V_349 ;
unsigned long V_186 ;
V_349 = V_121 + F_73 ( V_350 * 10 ) ;
F_19 ( & V_131 -> V_306 . V_317 ) ;
F_128 (rdata, &lport->disc.rports, peers) {
V_307 = F_122 ( V_281 ) ;
if ( ! V_307 -> time )
continue;
V_186 = V_307 -> time +
F_73 ( V_350 * 25 / 10 ) ;
if ( F_77 ( V_121 , V_186 ) ) {
V_307 -> time = 0 ;
F_4 ( V_6 ,
L_70 ,
V_281 -> V_308 . V_333 , V_281 -> V_308 . V_139 ) ;
V_131 -> V_315 . V_316 ( V_281 ) ;
} else if ( F_78 ( V_186 , V_349 ) )
V_349 = V_186 ;
}
F_22 ( & V_131 -> V_306 . V_317 ) ;
return V_349 ;
}
static int F_111 ( struct V_5 * V_6 , struct V_75 * V_76 )
{
struct V_80 * V_194 ;
enum V_282 V_233 ;
struct {
struct V_280 V_281 ;
struct V_279 V_307 ;
} V_351 ;
int V_38 ;
V_194 = (struct V_80 * ) V_76 -> V_90 ;
V_233 = V_194 -> V_101 ;
V_38 = F_136 ( V_6 , V_76 , & V_351 . V_281 ) ;
if ( V_38 ) {
F_4 ( V_6 , L_71 , V_38 ) ;
goto V_171;
}
F_19 ( & V_6 -> V_21 ) ;
switch ( V_233 ) {
case V_328 :
F_138 ( V_6 , & V_351 . V_281 ) ;
break;
case V_329 :
F_139 ( V_6 , & V_351 . V_281 ) ;
break;
case V_290 :
F_143 ( V_6 , & V_351 . V_281 ) ;
break;
case V_291 :
F_145 ( V_6 , & V_351 . V_281 ) ;
break;
case V_292 :
F_146 ( V_6 , & V_351 . V_281 ) ;
break;
default:
F_4 ( V_6 , L_72 , V_233 ) ;
V_38 = - 1 ;
break;
}
F_22 ( & V_6 -> V_21 ) ;
V_171:
F_39 ( V_76 ) ;
return V_38 ;
}
static void F_150 ( struct V_130 * V_131 , struct V_165 * V_166 )
{
struct V_352 V_353 ;
V_353 . V_354 = V_355 ;
V_353 . V_356 = V_357 ;
V_131 -> V_315 . V_358 ( V_166 , V_160 , & V_353 ) ;
F_151 ( V_166 ) ;
}
static void F_152 ( void (* F_153)( struct V_130 * ,
enum V_359 ) ,
struct V_130 * V_131 )
{
struct V_360 * V_306 = & V_131 -> V_306 ;
struct V_5 * V_6 = V_306 -> V_54 ;
F_19 ( & V_306 -> V_317 ) ;
V_306 -> V_318 = F_153 ;
V_306 -> V_342 = ( V_306 -> V_342 + 2 ) | 1 ;
V_306 -> V_361 = 1 ;
F_68 ( & V_6 -> V_27 ) ;
F_22 ( & V_306 -> V_317 ) ;
}
static void F_154 ( struct V_5 * V_6 )
{
struct V_130 * V_131 = V_6 -> V_7 ;
struct V_360 * V_306 = & V_131 -> V_306 ;
struct V_280 * V_281 ;
struct V_279 * V_307 ;
void (* F_153)( struct V_130 * , enum V_359 );
F_19 ( & V_306 -> V_317 ) ;
F_153 = V_306 -> V_361 ? V_306 -> V_318 : NULL ;
V_306 -> V_361 = 0 ;
F_128 (rdata, &disc->rports, peers) {
V_307 = F_122 ( V_281 ) ;
if ( V_307 -> time )
V_131 -> V_315 . V_346 ( V_281 ) ;
}
F_22 ( & V_306 -> V_317 ) ;
if ( F_153 )
F_153 ( V_131 , V_362 ) ;
}
static void F_116 ( struct V_5 * V_6 )
{
unsigned long V_349 ;
T_3 V_47 [ V_48 ] ;
T_2 V_363 = 0 ;
F_19 ( & V_6 -> V_21 ) ;
switch ( V_6 -> V_2 ) {
case V_326 :
F_3 ( V_6 , V_335 ) ;
F_123 ( V_6 , V_328 , V_252 , 0 ) ;
V_349 = V_121 + F_73 ( V_324 ) ;
break;
case V_335 :
F_3 ( V_6 , V_336 ) ;
F_123 ( V_6 , V_328 , V_252 , 0 ) ;
V_349 = V_121 + F_73 ( V_348 ) ;
break;
case V_336 :
F_3 ( V_6 , V_256 ) ;
V_363 = V_6 -> V_139 ;
F_8 ( V_47 , V_16 ) ;
F_8 ( V_47 + 3 , V_363 ) ;
F_7 ( V_6 ) ;
V_6 -> V_183 ( V_6 -> V_7 , V_47 ) ;
F_137 ( V_6 ) ;
V_349 = V_121 + F_73 ( V_348 ) ;
break;
case V_256 :
V_349 = V_6 -> V_120 + F_73 ( V_348 ) ;
if ( F_77 ( V_121 , V_349 ) ) {
F_3 ( V_6 , V_177 ) ;
F_123 ( V_6 , V_292 ,
V_252 , 0 ) ;
V_349 = V_121 + F_73 ( V_348 ) ;
V_6 -> V_128 = V_349 ;
}
F_154 ( V_6 ) ;
break;
case V_177 :
V_349 = F_149 ( V_6 ) ;
if ( F_77 ( V_121 , V_6 -> V_128 ) ) {
F_123 ( V_6 , V_292 ,
V_252 , 0 ) ;
V_6 -> V_128 = V_121 +
F_73 ( V_350 +
( F_134 () % V_364 ) ) ;
}
if ( F_78 ( V_6 -> V_128 , V_349 ) )
V_349 = V_6 -> V_128 ;
break;
case V_19 :
goto V_65;
default:
F_155 ( 1 , L_73 , V_6 -> V_2 ) ;
goto V_65;
}
F_88 ( & V_6 -> V_25 , V_349 ) ;
V_65:
F_22 ( & V_6 -> V_21 ) ;
if ( V_363 )
F_156 ( V_6 -> V_7 , V_363 ) ;
}
static void F_157 ( struct V_130 * V_131 , struct V_5 * V_6 ,
enum V_1 V_365 )
{
void * V_54 ;
F_29 ( V_131 -> V_2 != V_366 &&
V_131 -> V_2 != V_367 ) ;
if ( V_365 == V_14 ) {
V_131 -> V_368 = sizeof( struct V_279 ) ;
V_131 -> V_156 = 1 ;
V_131 -> V_315 . V_369 = F_150 ;
V_131 -> V_315 . V_370 = F_152 ;
V_131 -> V_315 . V_371 = F_129 ;
V_131 -> V_315 . V_372 = F_130 ;
V_54 = V_6 ;
} else {
V_131 -> V_368 = 0 ;
V_131 -> V_156 = 0 ;
V_131 -> V_315 . V_369 = NULL ;
V_131 -> V_315 . V_370 = NULL ;
V_131 -> V_315 . V_371 = NULL ;
V_131 -> V_315 . V_372 = NULL ;
V_54 = V_131 ;
}
F_158 ( V_131 , V_54 ) ;
}
int F_159 ( struct V_130 * V_131 , struct V_5 * V_6 ,
const struct V_373 * V_315 , int V_374 )
{
memcpy ( & V_131 -> V_315 , V_315 , sizeof( * V_315 ) ) ;
if ( V_374 && F_160 ( V_131 ) )
return - V_39 ;
F_161 ( V_131 ) ;
F_162 ( V_131 ) ;
F_163 ( V_131 ) ;
F_164 ( V_131 ) ;
F_165 ( V_131 ) ;
F_157 ( V_131 , V_6 , V_6 -> V_13 ) ;
return 0 ;
}
void F_166 ( struct V_35 * V_37 )
{
struct V_33 * V_34 = F_167 ( V_37 ) ;
struct V_5 * V_6 = F_168 ( V_34 ) ;
struct V_8 * V_9 ;
F_19 ( & V_6 -> V_21 ) ;
F_19 ( & V_34 -> V_53 ) ;
V_9 = F_169 ( V_37 ) ;
if ( V_9 )
V_37 -> V_52 = ( V_9 == V_6 -> V_59 ) ? 1 : 0 ;
else
V_37 -> V_52 = 0 ;
F_22 ( & V_34 -> V_53 ) ;
F_22 ( & V_6 -> V_21 ) ;
}
void F_170 ( struct V_33 * V_34 )
{
struct V_5 * V_375 = F_168 ( V_34 ) ;
struct V_130 * V_131 = V_375 -> V_7 ;
F_19 ( & V_375 -> V_21 ) ;
switch ( V_34 -> V_13 ) {
case V_376 :
V_375 -> V_13 = V_14 ;
break;
case V_377 :
default:
V_375 -> V_13 = V_125 ;
break;
}
F_22 ( & V_375 -> V_21 ) ;
F_157 ( V_131 , V_375 , V_375 -> V_13 ) ;
}
