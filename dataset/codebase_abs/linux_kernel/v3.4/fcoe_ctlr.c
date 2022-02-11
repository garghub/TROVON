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
static void F_16 ( struct V_5 * V_6 )
{
struct V_8 * V_9 ;
struct V_8 * V_32 ;
V_6 -> V_33 = NULL ;
F_17 (fcf, next, &fip->fcfs, list) {
F_18 ( & V_9 -> V_34 ) ;
F_19 ( V_9 ) ;
}
V_6 -> V_35 = 0 ;
V_6 -> V_36 = 0 ;
}
void F_20 ( struct V_5 * V_6 )
{
F_21 ( & V_6 -> V_29 ) ;
F_22 ( & V_6 -> V_31 ) ;
F_23 ( & V_6 -> V_21 ) ;
F_3 ( V_6 , V_37 ) ;
F_16 ( V_6 ) ;
F_24 ( & V_6 -> V_21 ) ;
F_25 ( & V_6 -> V_25 ) ;
F_21 ( & V_6 -> V_27 ) ;
}
static void F_26 ( struct V_5 * V_6 )
{
struct V_8 * V_38 ;
struct V_8 * V_9 ;
F_23 ( & V_6 -> V_21 ) ;
F_27 ( & V_6 -> V_22 ) ;
F_28 ( V_6 -> V_39 ) ;
V_6 -> V_39 = NULL ;
F_29 (fcf, &fip->fcfs, list)
V_9 -> V_40 = 0 ;
F_30 ( & V_6 -> V_22 ) ;
V_38 = V_6 -> V_33 ;
if ( V_38 && ! F_31 ( V_38 -> V_41 , V_6 -> V_15 ) )
goto V_42;
if ( ! F_32 ( V_6 -> V_15 ) ) {
F_33 ( V_43 L_3
L_4 ,
V_6 -> V_7 -> V_44 -> V_45 , V_6 -> V_15 ) ;
memset ( V_6 -> V_15 , 0 , V_46 ) ;
}
if ( V_38 ) {
F_33 ( V_47 L_5
L_6 ,
V_6 -> V_7 -> V_44 -> V_45 , V_38 -> V_41 ) ;
memcpy ( V_6 -> V_15 , V_38 -> V_48 , V_46 ) ;
V_6 -> V_18 = 0 ;
}
V_42:
F_24 ( & V_6 -> V_21 ) ;
}
static inline T_2 F_34 ( struct V_5 * V_6 )
{
return V_6 -> V_7 -> V_49 + sizeof( struct V_50 ) +
sizeof( struct V_51 ) + sizeof( struct V_52 ) ;
}
static void F_35 ( struct V_5 * V_6 , struct V_8 * V_9 )
{
struct V_53 * V_54 ;
struct V_55 {
struct V_56 V_57 ;
struct V_58 V_6 ;
struct {
struct V_59 V_60 ;
struct V_61 V_62 ;
struct V_63 V_64 ;
} V_65 V_66 ;
} V_65 * V_67 ;
T_2 V_68 ;
V_54 = F_36 ( sizeof( * V_67 ) ) ;
if ( ! V_54 )
return;
V_67 = (struct V_55 * ) V_54 -> V_69 ;
memset ( V_67 , 0 , sizeof( * V_67 ) ) ;
memcpy ( V_67 -> V_57 . V_70 , V_9 ? V_9 -> V_41 : V_71 , V_46 ) ;
memcpy ( V_67 -> V_57 . V_72 , V_6 -> V_73 , V_46 ) ;
V_67 -> V_57 . V_74 = F_37 ( V_75 ) ;
V_67 -> V_6 . V_76 = F_38 ( V_77 ) ;
V_67 -> V_6 . V_78 = F_37 ( V_79 ) ;
V_67 -> V_6 . V_80 = V_81 ;
V_67 -> V_6 . V_82 = F_37 ( sizeof( V_67 -> V_66 ) / V_83 ) ;
V_67 -> V_6 . V_84 = F_37 ( V_85 ) ;
if ( V_6 -> V_86 )
V_67 -> V_6 . V_84 |= F_37 ( V_87 ) ;
V_67 -> V_66 . V_60 . V_88 . V_89 = V_90 ;
V_67 -> V_66 . V_60 . V_88 . V_91 = sizeof( V_67 -> V_66 . V_60 ) / V_83 ;
memcpy ( V_67 -> V_66 . V_60 . V_92 , V_6 -> V_73 , V_46 ) ;
V_67 -> V_66 . V_62 . V_88 . V_89 = V_93 ;
V_67 -> V_66 . V_62 . V_88 . V_91 = sizeof( V_67 -> V_66 . V_62 ) / V_83 ;
F_39 ( V_6 -> V_7 -> V_62 , & V_67 -> V_66 . V_62 . V_94 ) ;
V_68 = F_34 ( V_6 ) ;
V_67 -> V_66 . V_64 . V_88 . V_89 = V_95 ;
V_67 -> V_66 . V_64 . V_88 . V_91 = sizeof( V_67 -> V_66 . V_64 ) / V_83 ;
V_67 -> V_66 . V_64 . V_96 = F_37 ( V_68 ) ;
F_40 ( V_54 , sizeof( * V_67 ) ) ;
V_54 -> V_97 = F_37 ( V_75 ) ;
V_54 -> V_98 = V_6 -> V_98 ;
F_41 ( V_54 ) ;
F_42 ( V_54 ) ;
V_6 -> V_99 ( V_6 , V_54 ) ;
if ( ! V_9 )
V_6 -> V_100 = V_101 ;
}
void F_43 ( struct V_5 * V_6 )
{
F_23 ( & V_6 -> V_21 ) ;
if ( V_6 -> V_2 == V_102 || V_6 -> V_2 == V_103 ) {
F_24 ( & V_6 -> V_21 ) ;
F_44 ( V_6 -> V_7 ) ;
} else if ( V_6 -> V_2 == V_19 ) {
F_3 ( V_6 , V_6 -> V_13 ) ;
switch ( V_6 -> V_13 ) {
default:
F_4 ( V_6 , L_7 , V_6 -> V_13 ) ;
case V_104 :
F_4 ( V_6 , L_8 , L_9 ) ;
case V_105 :
case V_106 :
F_24 ( & V_6 -> V_21 ) ;
F_44 ( V_6 -> V_7 ) ;
F_35 ( V_6 , NULL ) ;
break;
case V_14 :
F_45 ( V_6 ) ;
F_24 ( & V_6 -> V_21 ) ;
F_44 ( V_6 -> V_7 ) ;
break;
}
} else
F_24 ( & V_6 -> V_21 ) ;
}
static void F_46 ( struct V_5 * V_6 )
{
F_16 ( V_6 ) ;
F_47 ( & V_6 -> V_25 ) ;
V_6 -> V_107 = 0 ;
V_6 -> V_108 = 0 ;
V_6 -> V_100 = 0 ;
V_6 -> V_23 = V_24 ;
F_7 ( V_6 ) ;
}
int F_48 ( struct V_5 * V_6 )
{
int V_109 ;
F_4 ( V_6 , L_10 ) ;
F_23 ( & V_6 -> V_21 ) ;
F_46 ( V_6 ) ;
V_109 = V_6 -> V_2 != V_19 ;
F_3 ( V_6 , V_19 ) ;
F_24 ( & V_6 -> V_21 ) ;
if ( V_109 )
F_49 ( V_6 -> V_7 ) ;
return V_109 ;
}
static void F_50 ( struct V_5 * V_6 ,
struct V_110 * V_111 ,
int V_112 , T_3 * V_113 )
{
struct V_53 * V_54 ;
struct V_114 {
struct V_56 V_57 ;
struct V_58 V_6 ;
struct V_59 V_60 ;
} V_65 * V_115 ;
struct V_116 * V_117 ;
T_2 V_118 ;
struct V_110 * V_7 ;
struct V_8 * V_9 ;
V_9 = V_6 -> V_33 ;
V_7 = V_6 -> V_7 ;
if ( ! V_9 || ( V_112 && ! V_7 -> V_119 ) )
return;
V_118 = sizeof( * V_115 ) + V_112 * sizeof( * V_117 ) ;
V_54 = F_36 ( V_118 ) ;
if ( ! V_54 )
return;
V_115 = (struct V_114 * ) V_54 -> V_69 ;
memset ( V_115 , 0 , V_118 ) ;
memcpy ( V_115 -> V_57 . V_70 , V_9 -> V_41 , V_46 ) ;
memcpy ( V_115 -> V_57 . V_72 , V_113 , V_46 ) ;
V_115 -> V_57 . V_74 = F_37 ( V_75 ) ;
V_115 -> V_6 . V_76 = F_38 ( V_77 ) ;
V_115 -> V_6 . V_78 = F_37 ( V_120 ) ;
V_115 -> V_6 . V_80 = V_121 ;
V_115 -> V_6 . V_82 = F_37 ( ( sizeof( V_115 -> V_60 ) +
V_112 * sizeof( * V_117 ) ) / V_83 ) ;
V_115 -> V_6 . V_84 = F_37 ( V_85 ) ;
if ( V_6 -> V_86 )
V_115 -> V_6 . V_84 |= F_37 ( V_87 ) ;
V_115 -> V_60 . V_88 . V_89 = V_90 ;
V_115 -> V_60 . V_88 . V_91 = sizeof( V_115 -> V_60 ) / V_83 ;
memcpy ( V_115 -> V_60 . V_92 , V_6 -> V_73 , V_46 ) ;
if ( V_112 ) {
V_117 = (struct V_116 * ) ( V_115 + 1 ) ;
V_117 -> V_88 . V_89 = V_122 ;
V_117 -> V_88 . V_91 = sizeof( * V_117 ) / V_83 ;
memcpy ( V_117 -> V_92 , V_6 -> V_123 ( V_111 ) , V_46 ) ;
F_8 ( V_117 -> V_124 , V_111 -> V_119 ) ;
F_39 ( V_111 -> V_125 , & V_117 -> V_126 ) ;
}
F_40 ( V_54 , V_118 ) ;
V_54 -> V_97 = F_37 ( V_75 ) ;
V_54 -> V_98 = V_6 -> V_98 ;
F_41 ( V_54 ) ;
F_42 ( V_54 ) ;
V_6 -> V_99 ( V_6 , V_54 ) ;
}
static int F_51 ( struct V_5 * V_6 , struct V_110 * V_111 ,
T_3 V_127 , struct V_53 * V_54 , T_2 V_128 )
{
struct V_129 {
struct V_56 V_57 ;
struct V_58 V_6 ;
struct V_130 V_131 ;
} V_65 * V_132 ;
struct V_50 * V_133 ;
struct V_59 * V_60 ;
struct V_8 * V_9 ;
T_4 V_134 ;
T_1 V_84 ;
T_3 V_135 ;
V_133 = (struct V_50 * ) V_54 -> V_69 ;
V_135 = * ( T_3 * ) ( V_133 + 1 ) ;
V_134 = sizeof( struct V_130 ) + V_54 -> V_118 ;
V_132 = (struct V_129 * ) F_52 ( V_54 , sizeof( * V_132 ) ) ;
memset ( V_132 , 0 , sizeof( * V_132 ) ) ;
if ( V_111 -> V_136 ) {
if ( F_53 ( V_6 , V_128 , V_132 -> V_57 . V_70 ) )
return - V_137 ;
V_84 = 0 ;
} else {
V_9 = V_6 -> V_33 ;
if ( ! V_9 )
return - V_137 ;
V_84 = V_9 -> V_10 ;
V_84 &= V_6 -> V_86 ? V_87 | V_85 :
V_85 ;
if ( ! V_84 )
return - V_137 ;
memcpy ( V_132 -> V_57 . V_70 , V_9 -> V_41 , V_46 ) ;
}
memcpy ( V_132 -> V_57 . V_72 , V_6 -> V_73 , V_46 ) ;
V_132 -> V_57 . V_74 = F_37 ( V_75 ) ;
V_132 -> V_6 . V_76 = F_38 ( V_77 ) ;
V_132 -> V_6 . V_78 = F_37 ( V_138 ) ;
if ( V_135 == V_139 || V_135 == V_140 )
V_132 -> V_6 . V_80 = V_141 ;
else
V_132 -> V_6 . V_80 = V_142 ;
V_132 -> V_6 . V_84 = F_37 ( V_84 ) ;
V_132 -> V_131 . V_88 . V_89 = V_127 ;
V_132 -> V_131 . V_88 . V_91 = V_134 / V_83 ;
if ( V_135 != V_140 ) {
V_134 += sizeof( * V_60 ) ;
V_60 = (struct V_59 * ) F_40 ( V_54 , sizeof( * V_60 ) ) ;
memset ( V_60 , 0 , sizeof( * V_60 ) ) ;
V_60 -> V_88 . V_89 = V_90 ;
V_60 -> V_88 . V_91 = sizeof( * V_60 ) / V_83 ;
if ( V_127 != V_143 && V_127 != V_144 ) {
memcpy ( V_60 -> V_92 , V_6 -> V_123 ( V_111 ) , V_46 ) ;
} else if ( V_6 -> V_13 == V_14 ) {
F_8 ( V_60 -> V_92 , V_16 ) ;
F_8 ( V_60 -> V_92 + 3 , V_6 -> V_119 ) ;
} else if ( V_84 & V_87 ) {
F_4 ( V_6 , L_11 ) ;
memcpy ( V_60 -> V_92 , V_6 -> V_73 , V_46 ) ;
} else {
F_4 ( V_6 , L_12 ) ;
}
}
V_132 -> V_6 . V_82 = F_37 ( V_134 / V_83 ) ;
V_54 -> V_97 = F_37 ( V_75 ) ;
V_54 -> V_98 = V_6 -> V_98 ;
F_41 ( V_54 ) ;
F_42 ( V_54 ) ;
return 0 ;
}
int F_54 ( struct V_5 * V_6 , struct V_110 * V_111 ,
struct V_53 * V_54 )
{
struct V_145 * V_146 ;
struct V_50 * V_133 ;
T_1 V_147 ;
T_3 V_135 ;
T_3 V_60 [ V_46 ] ;
V_146 = F_55 ( V_54 , struct V_145 , V_54 ) ;
V_133 = (struct V_50 * ) V_54 -> V_69 ;
V_135 = * ( T_3 * ) ( V_133 + 1 ) ;
if ( V_135 == V_148 && V_6 -> V_13 != V_14 ) {
V_147 = V_6 -> V_23 ;
V_6 -> V_23 = F_56 ( V_133 -> V_149 ) ;
if ( V_6 -> V_2 == V_103 ) {
if ( V_147 == V_24 )
V_6 -> V_150 = 0 ;
V_6 -> V_150 ++ ;
if ( V_6 -> V_150 < 3 )
goto V_151;
F_7 ( V_6 ) ;
return 0 ;
}
if ( V_6 -> V_2 == V_102 )
F_7 ( V_6 ) ;
}
if ( V_6 -> V_2 == V_102 )
return 0 ;
if ( ! V_6 -> V_33 && V_6 -> V_13 != V_14 )
goto V_151;
switch ( V_135 ) {
case V_148 :
V_135 = V_143 ;
if ( V_6 -> V_13 == V_14 )
break;
F_27 ( & V_6 -> V_22 ) ;
F_28 ( V_6 -> V_39 ) ;
V_6 -> V_39 = V_54 ;
V_6 -> V_152 = 1 ;
F_30 ( & V_6 -> V_22 ) ;
F_57 ( & V_6 -> V_27 ) ;
return - V_153 ;
case V_154 :
if ( F_58 ( V_133 -> V_155 ) )
return 0 ;
V_135 = V_144 ;
break;
case V_156 :
if ( V_6 -> V_13 == V_14 ) {
if ( V_6 -> V_2 != V_157 )
return - V_158 ;
if ( F_58 ( V_133 -> V_159 ) == V_160 )
return - V_158 ;
} else {
if ( V_6 -> V_2 != V_161 )
return 0 ;
if ( F_58 ( V_133 -> V_159 ) != V_160 )
return 0 ;
}
V_135 = V_162 ;
break;
case V_139 :
if ( V_6 -> V_2 == V_102 ) {
if ( V_6 -> V_23 == V_24 )
return 0 ;
V_6 -> V_23 = V_24 ;
F_59 ( V_60 , V_133 -> V_159 ) ;
V_6 -> V_163 ( V_111 , V_60 ) ;
}
case V_140 :
V_135 = F_60 ( V_146 ) ;
if ( V_135 )
break;
return 0 ;
default:
if ( V_6 -> V_2 != V_161 &&
V_6 -> V_2 != V_157 )
goto V_151;
return 0 ;
}
F_4 ( V_6 , L_13 ,
V_135 , F_58 ( V_133 -> V_159 ) ) ;
if ( F_51 ( V_6 , V_111 , V_135 , V_54 , F_58 ( V_133 -> V_159 ) ) )
goto V_151;
V_6 -> V_99 ( V_6 , V_54 ) ;
return - V_153 ;
V_151:
F_28 ( V_54 ) ;
return - V_158 ;
}
static unsigned long F_61 ( struct V_5 * V_6 )
{
struct V_8 * V_9 ;
struct V_8 * V_32 ;
unsigned long V_164 = V_101 + F_62 ( V_165 ) ;
unsigned long V_166 ;
unsigned long V_36 = 0 ;
struct V_167 * V_168 ;
V_168 = F_63 ( V_6 -> V_7 -> V_169 , F_64 () ) ;
F_17 (fcf, next, &fip->fcfs, list) {
V_166 = V_9 -> time + V_9 -> V_170 + V_9 -> V_170 / 2 ;
if ( V_6 -> V_33 == V_9 ) {
if ( F_65 ( V_101 , V_166 ) ) {
V_168 -> V_171 ++ ;
F_33 ( V_47 L_3
L_14
L_15 ,
V_6 -> V_7 -> V_44 -> V_45 , V_9 -> V_172 ,
V_168 -> V_171 ) ;
} else if ( F_65 ( V_164 , V_166 ) )
V_164 = V_166 ;
}
V_166 += V_9 -> V_170 ;
if ( F_66 ( V_101 , V_166 ) ) {
if ( V_6 -> V_33 == V_9 )
V_6 -> V_33 = NULL ;
F_18 ( & V_9 -> V_34 ) ;
F_67 ( ! V_6 -> V_35 ) ;
V_6 -> V_35 -- ;
F_19 ( V_9 ) ;
V_168 -> V_173 ++ ;
} else {
if ( F_65 ( V_164 , V_166 ) )
V_164 = V_166 ;
if ( F_5 ( V_9 ) &&
( ! V_36 || F_68 ( V_36 , V_9 -> time ) ) )
V_36 = V_9 -> time ;
}
}
F_69 () ;
if ( V_36 && ! V_6 -> V_33 && ! V_6 -> V_36 ) {
V_36 += F_62 ( V_174 ) ;
V_6 -> V_36 = V_36 ;
}
return V_164 ;
}
static int F_70 ( struct V_5 * V_6 ,
struct V_53 * V_54 , struct V_8 * V_9 )
{
struct V_58 * V_175 ;
struct V_176 * V_66 = NULL ;
struct V_61 * V_177 ;
struct V_178 * V_179 ;
struct V_180 * V_181 ;
unsigned long V_182 ;
T_4 V_183 ;
T_4 V_134 ;
T_2 V_184 ;
memset ( V_9 , 0 , sizeof( * V_9 ) ) ;
V_9 -> V_170 = F_62 ( V_185 ) ;
V_175 = (struct V_58 * ) V_54 -> V_69 ;
V_9 -> V_10 = F_56 ( V_175 -> V_84 ) ;
V_184 = F_71 ( V_186 ) | F_71 ( V_90 ) | F_71 ( V_93 ) |
F_71 ( V_187 ) | F_71 ( V_188 ) ;
V_183 = F_56 ( V_175 -> V_82 ) * 4 ;
if ( V_183 + sizeof( * V_175 ) > V_54 -> V_118 )
return - V_158 ;
V_66 = (struct V_176 * ) ( V_175 + 1 ) ;
while ( V_183 > 0 ) {
V_134 = V_66 -> V_91 * V_83 ;
if ( V_134 < sizeof( * V_66 ) || V_134 > V_183 )
return - V_158 ;
if ( ( V_66 -> V_89 < 32 ) &&
! ( V_184 & 1U << V_66 -> V_89 ) ) {
F_4 ( V_6 , L_16
L_17 ) ;
return - V_158 ;
}
switch ( V_66 -> V_89 ) {
case V_186 :
if ( V_134 != sizeof( struct V_189 ) )
goto V_190;
V_9 -> V_191 = ( (struct V_189 * ) V_66 ) -> V_192 ;
V_184 &= ~ F_71 ( V_186 ) ;
break;
case V_90 :
if ( V_134 != sizeof( struct V_59 ) )
goto V_190;
memcpy ( V_9 -> V_41 ,
( (struct V_59 * ) V_66 ) -> V_92 ,
V_46 ) ;
memcpy ( V_9 -> V_48 , V_9 -> V_41 , V_46 ) ;
if ( ! F_72 ( V_9 -> V_41 ) ) {
F_4 ( V_6 ,
L_18 ,
V_9 -> V_41 ) ;
return - V_158 ;
}
V_184 &= ~ F_71 ( V_90 ) ;
break;
case V_93 :
if ( V_134 != sizeof( struct V_61 ) )
goto V_190;
V_177 = (struct V_61 * ) V_66 ;
V_9 -> V_193 = F_73 ( & V_177 -> V_94 ) ;
V_184 &= ~ F_71 ( V_93 ) ;
break;
case V_187 :
if ( V_134 != sizeof( struct V_178 ) )
goto V_190;
V_179 = (struct V_178 * ) V_66 ;
V_9 -> V_172 = F_73 ( & V_179 -> V_94 ) ;
V_9 -> V_194 = F_56 ( V_179 -> V_195 ) ;
V_9 -> V_196 = F_58 ( V_179 -> V_197 ) ;
V_184 &= ~ F_71 ( V_187 ) ;
break;
case V_188 :
if ( V_134 != sizeof( struct V_180 ) )
goto V_190;
V_181 = (struct V_180 * ) V_66 ;
if ( V_181 -> V_198 & V_199 )
V_9 -> V_198 = 1 ;
V_182 = F_74 ( V_181 -> V_200 ) ;
if ( V_182 >= V_201 )
V_9 -> V_170 = F_62 ( V_182 ) ;
V_184 &= ~ F_71 ( V_188 ) ;
break;
case V_202 :
case V_95 :
case V_143 :
case V_144 :
case V_162 :
case V_203 :
default:
F_4 ( V_6 , L_19
L_20 , V_66 -> V_89 ) ;
if ( V_66 -> V_89 < V_204 )
return - V_158 ;
break;
}
V_66 = (struct V_176 * ) ( ( char * ) V_66 + V_134 ) ;
V_183 -= V_134 ;
}
if ( ! V_9 -> V_196 || ( V_9 -> V_196 & 0x10000 ) )
return - V_158 ;
if ( ! V_9 -> V_193 )
return - V_158 ;
if ( V_184 ) {
F_4 ( V_6 , L_21 ,
V_184 ) ;
return - V_158 ;
}
return 0 ;
V_190:
F_4 ( V_6 , L_22 ,
V_66 -> V_89 , V_134 ) ;
return - V_158 ;
}
static void F_75 ( struct V_5 * V_6 , struct V_53 * V_54 )
{
struct V_8 * V_9 ;
struct V_8 V_205 ;
struct V_8 * V_206 ;
unsigned long V_207 = F_62 ( V_208 ) ;
int V_209 = 0 ;
int V_210 ;
if ( F_70 ( V_6 , V_54 , & V_205 ) )
return;
F_23 ( & V_6 -> V_21 ) ;
V_209 = F_76 ( & V_6 -> V_20 ) ;
V_206 = NULL ;
F_29 (fcf, &fip->fcfs, list) {
if ( V_9 -> V_193 == V_205 . V_193 &&
V_9 -> V_172 == V_205 . V_172 &&
V_9 -> V_196 == V_205 . V_196 &&
F_31 ( V_9 -> V_41 , V_205 . V_41 ) == 0 ) {
V_206 = V_9 ;
break;
}
}
if ( ! V_206 ) {
if ( V_6 -> V_35 >= V_211 )
goto V_212;
V_9 = F_77 ( sizeof( * V_9 ) , V_213 ) ;
if ( ! V_9 )
goto V_212;
V_6 -> V_35 ++ ;
memcpy ( V_9 , & V_205 , sizeof( V_205 ) ) ;
F_78 ( & V_9 -> V_34 , & V_6 -> V_20 ) ;
} else {
V_9 -> V_198 = V_205 . V_198 ;
if ( ! F_6 ( V_9 ) )
V_9 -> V_10 = V_205 . V_10 ;
if ( V_9 == V_6 -> V_33 && ! V_9 -> V_198 ) {
V_6 -> V_107 -= V_9 -> V_170 ;
V_6 -> V_107 += V_205 . V_170 ;
if ( F_68 ( V_6 -> V_107 , V_6 -> V_25 . V_214 ) )
F_79 ( & V_6 -> V_25 , V_6 -> V_107 ) ;
}
V_9 -> V_170 = V_205 . V_170 ;
memcpy ( V_9 -> V_41 , V_205 . V_41 , V_46 ) ;
}
V_210 = F_5 ( V_9 ) ;
V_9 -> time = V_101 ;
if ( ! V_206 )
F_4 ( V_6 , L_23 ,
V_9 -> V_172 , V_9 -> V_41 ) ;
if ( ! V_210 )
F_35 ( V_6 , V_9 ) ;
if ( V_209 && F_65 ( V_101 , V_6 -> V_100 + V_207 ) )
F_35 ( V_6 , NULL ) ;
if ( V_210 )
F_80 ( & V_9 -> V_34 , & V_6 -> V_20 ) ;
if ( V_210 && ! V_6 -> V_33 && F_6 ( V_9 ) ) {
V_6 -> V_36 = V_101 +
F_62 ( V_174 ) ;
if ( ! F_81 ( & V_6 -> V_25 ) ||
F_68 ( V_6 -> V_36 , V_6 -> V_25 . V_214 ) )
F_79 ( & V_6 -> V_25 , V_6 -> V_36 ) ;
}
V_212:
F_24 ( & V_6 -> V_21 ) ;
}
static void F_82 ( struct V_5 * V_6 , struct V_53 * V_54 )
{
struct V_110 * V_111 = V_6 -> V_7 ;
struct V_58 * V_175 ;
struct V_145 * V_146 = (struct V_145 * ) V_54 ;
struct V_50 * V_133 = NULL ;
struct V_176 * V_66 ;
struct V_130 * V_215 ;
struct V_167 * V_168 ;
struct V_8 * V_38 ;
enum V_216 V_217 = 0 ;
T_3 V_218 ;
T_3 V_219 ;
T_3 V_220 [ V_46 ] = { 0 } ;
T_4 V_221 = 0 ;
T_4 V_183 ;
T_4 V_134 ;
T_2 V_184 = 0 ;
T_2 V_222 = 0 ;
V_175 = (struct V_58 * ) V_54 -> V_69 ;
V_219 = V_175 -> V_80 ;
if ( V_219 != V_142 && V_219 != V_141 )
goto V_151;
V_183 = F_56 ( V_175 -> V_82 ) * 4 ;
if ( V_183 + sizeof( * V_175 ) > V_54 -> V_118 )
goto V_151;
V_66 = (struct V_176 * ) ( V_175 + 1 ) ;
while ( V_183 > 0 ) {
V_222 ++ ;
V_134 = V_66 -> V_91 * V_83 ;
if ( V_134 < sizeof( * V_66 ) || V_134 > V_183 )
goto V_151;
if ( V_66 -> V_89 < 32 ) {
if ( ( V_66 -> V_89 != V_90 ) &&
( V_184 & 1U << V_66 -> V_89 ) ) {
F_4 ( V_6 , L_16
L_24 ) ;
goto V_151;
}
V_184 |= ( 1 << V_66 -> V_89 ) ;
}
switch ( V_66 -> V_89 ) {
case V_90 :
V_38 = V_6 -> V_33 ;
if ( V_222 == 1 ) {
F_4 ( V_6 , L_25
L_26 ) ;
goto V_151;
}
if ( V_222 == 2 )
memcpy ( V_220 ,
( (struct V_59 * ) V_66 ) -> V_92 ,
V_46 ) ;
if ( V_134 != sizeof( struct V_59 ) )
goto V_190;
if ( ( V_222 == 3 ) && ( V_38 ) )
memcpy ( V_38 -> V_48 ,
( (struct V_59 * ) V_66 ) -> V_92 ,
V_46 ) ;
break;
case V_143 :
case V_144 :
case V_162 :
case V_203 :
if ( V_222 != 1 ) {
F_4 ( V_6 , L_25
L_26 ) ;
goto V_151;
}
if ( V_133 )
goto V_151;
if ( V_134 < sizeof( * V_215 ) + sizeof( * V_133 ) + 1 )
goto V_190;
V_221 = V_134 - sizeof( * V_215 ) ;
V_215 = (struct V_130 * ) V_66 ;
V_133 = (struct V_50 * ) ( V_215 + 1 ) ;
V_217 = V_66 -> V_89 ;
break;
default:
F_4 ( V_6 , L_19
L_20 , V_66 -> V_89 ) ;
if ( V_66 -> V_89 < V_204 )
goto V_151;
if ( V_222 <= 2 ) {
F_4 ( V_6 , L_25
L_26 ) ;
goto V_151;
}
break;
}
V_66 = (struct V_176 * ) ( ( char * ) V_66 + V_134 ) ;
V_183 -= V_134 ;
}
if ( ! V_133 )
goto V_151;
V_218 = * ( T_3 * ) ( V_133 + 1 ) ;
if ( ( V_217 == V_143 || V_217 == V_144 ) &&
V_219 == V_141 && V_6 -> V_13 != V_14 ) {
if ( V_218 == V_139 ) {
if ( ! F_72 ( V_220 ) ) {
F_4 ( V_6 ,
L_27 ,
V_220 ) ;
goto V_151;
}
memcpy ( F_83 ( V_146 ) -> V_220 , V_220 , V_46 ) ;
if ( V_6 -> V_23 == F_56 ( V_133 -> V_149 ) ) {
V_6 -> V_23 = V_24 ;
if ( V_217 == V_143 )
F_26 ( V_6 ) ;
}
} else if ( V_217 == V_143 &&
! F_84 ( V_6 ) )
goto V_151;
}
if ( ( V_222 == 0 ) || ( ( V_218 != V_140 ) &&
( ! ( 1U << V_90 & V_184 ) ) ) ) {
F_4 ( V_6 , L_28
L_29 ) ;
goto V_151;
}
F_85 ( V_54 , ( T_3 * ) V_133 - V_54 -> V_69 ) ;
F_86 ( V_54 , V_221 ) ;
V_146 = (struct V_145 * ) V_54 ;
F_87 ( V_146 ) ;
F_88 ( V_146 ) = V_223 ;
F_89 ( V_146 ) = V_224 ;
F_90 ( V_146 ) = V_111 ;
F_60 ( V_146 ) = V_217 ;
V_168 = F_63 ( V_111 -> V_169 , F_64 () ) ;
V_168 -> V_225 ++ ;
V_168 -> V_226 += V_54 -> V_118 / V_83 ;
F_69 () ;
F_91 ( V_111 , V_146 ) ;
return;
V_190:
F_4 ( V_6 , L_22 ,
V_66 -> V_89 , V_134 ) ;
V_151:
F_28 ( V_54 ) ;
}
static void F_92 ( struct V_5 * V_6 ,
struct V_58 * V_133 )
{
struct V_176 * V_66 ;
struct V_59 * V_227 ;
struct V_61 * V_228 ;
struct V_116 * V_229 ;
T_4 V_183 ;
T_4 V_134 ;
struct V_8 * V_9 = V_6 -> V_33 ;
struct V_110 * V_111 = V_6 -> V_7 ;
struct V_110 * V_230 = NULL ;
T_2 V_184 ;
int V_231 ;
int V_232 = 0 ;
struct V_116 * * V_233 = NULL ;
F_4 ( V_6 , L_30 ) ;
if ( ! V_9 || ! V_111 -> V_119 )
return;
V_184 = F_71 ( V_90 ) | F_71 ( V_93 ) ;
V_183 = F_56 ( V_133 -> V_82 ) * V_83 ;
V_66 = (struct V_176 * ) ( V_133 + 1 ) ;
V_231 = V_183 / sizeof( * V_229 ) ;
if ( V_231 )
V_233 = F_77 ( sizeof( V_229 ) * V_231 ,
V_213 ) ;
if ( ! V_233 )
return;
V_231 = 0 ;
while ( V_183 >= sizeof( * V_66 ) ) {
V_134 = V_66 -> V_91 * V_83 ;
if ( V_134 > V_183 )
goto V_234;
if ( ( V_66 -> V_89 < 32 ) &&
( V_66 -> V_89 != V_122 ) &&
! ( V_184 & 1U << V_66 -> V_89 ) ) {
F_4 ( V_6 , L_16
L_31 ) ;
goto V_234;
}
switch ( V_66 -> V_89 ) {
case V_90 :
V_227 = (struct V_59 * ) V_66 ;
if ( V_134 < sizeof( * V_227 ) )
goto V_234;
if ( F_31 ( V_227 -> V_92 , V_9 -> V_41 ) )
goto V_234;
V_184 &= ~ F_71 ( V_90 ) ;
break;
case V_93 :
V_228 = (struct V_61 * ) V_66 ;
if ( V_134 < sizeof( * V_228 ) )
goto V_234;
if ( F_73 ( & V_228 -> V_94 ) != V_9 -> V_193 )
goto V_234;
V_184 &= ~ F_71 ( V_93 ) ;
break;
case V_122 :
V_229 = (struct V_116 * ) V_66 ;
if ( V_134 < sizeof( * V_229 ) )
goto V_234;
V_233 [ V_231 ++ ] = V_229 ;
V_230 = F_93 ( V_111 ,
F_58 ( V_229 -> V_124 ) ) ;
if ( V_230 && ( V_230 == V_111 ) ) {
F_23 ( & V_6 -> V_21 ) ;
F_63 ( V_111 -> V_169 ,
F_64 () ) -> V_173 ++ ;
F_69 () ;
F_46 ( V_6 ) ;
F_24 ( & V_6 -> V_21 ) ;
}
break;
default:
if ( V_66 -> V_89 < V_204 )
goto V_234;
break;
}
V_66 = (struct V_176 * ) ( ( char * ) V_66 + V_134 ) ;
V_183 -= V_134 ;
}
if ( V_184 )
F_4 ( V_6 , L_32 ,
V_184 ) ;
else if ( ! V_231 ) {
F_4 ( V_6 , L_33 ) ;
F_23 ( & V_6 -> V_21 ) ;
F_63 ( V_111 -> V_169 ,
F_64 () ) -> V_173 ++ ;
F_69 () ;
F_46 ( V_6 ) ;
F_24 ( & V_6 -> V_21 ) ;
F_23 ( & V_111 -> V_235 ) ;
F_29 (vn_port, &lport->vports, list)
F_94 ( V_230 ) ;
F_24 ( & V_111 -> V_235 ) ;
F_94 ( V_6 -> V_7 ) ;
F_35 ( V_6 , NULL ) ;
} else {
int V_236 ;
F_4 ( V_6 , L_34 ) ;
for ( V_236 = 0 ; V_236 < V_231 ; V_236 ++ ) {
V_229 = V_233 [ V_236 ] ;
V_230 = F_93 ( V_111 ,
F_58 ( V_229 -> V_124 ) ) ;
if ( ! V_230 )
continue;
if ( F_31 ( V_6 -> V_123 ( V_230 ) ,
V_229 -> V_92 ) != 0 ||
F_73 ( & V_229 -> V_126 ) !=
V_230 -> V_125 )
continue;
if ( V_230 == V_111 )
V_232 = 1 ;
else
F_94 ( V_230 ) ;
}
if ( V_232 ) {
F_94 ( V_6 -> V_7 ) ;
F_35 ( V_6 , NULL ) ;
}
}
V_234:
F_19 ( V_233 ) ;
}
void F_95 ( struct V_5 * V_6 , struct V_53 * V_54 )
{
F_96 ( & V_6 -> V_31 , V_54 ) ;
F_57 ( & V_6 -> V_29 ) ;
}
static int F_97 ( struct V_5 * V_6 , struct V_53 * V_54 )
{
struct V_58 * V_175 ;
struct V_56 * V_237 ;
enum V_1 V_2 ;
T_1 V_135 ;
T_3 V_219 ;
if ( F_98 ( V_54 ) )
goto V_151;
if ( V_54 -> V_118 < sizeof( * V_175 ) )
goto V_151;
V_237 = F_99 ( V_54 ) ;
if ( V_6 -> V_13 == V_14 ) {
if ( F_31 ( V_237 -> V_70 , V_6 -> V_73 ) &&
F_31 ( V_237 -> V_70 , V_238 ) &&
F_31 ( V_237 -> V_70 , V_239 ) )
goto V_151;
} else if ( F_31 ( V_237 -> V_70 , V_6 -> V_73 ) &&
F_31 ( V_237 -> V_70 , V_240 ) )
goto V_151;
V_175 = (struct V_58 * ) V_54 -> V_69 ;
V_135 = F_56 ( V_175 -> V_78 ) ;
V_219 = V_175 -> V_80 ;
if ( F_100 ( V_175 -> V_76 ) != V_77 )
goto V_151;
if ( F_56 ( V_175 -> V_82 ) * V_83 + sizeof( * V_175 ) > V_54 -> V_118 )
goto V_151;
F_23 ( & V_6 -> V_21 ) ;
V_2 = V_6 -> V_2 ;
if ( V_2 == V_103 ) {
V_6 -> V_18 = 0 ;
F_3 ( V_6 , V_161 ) ;
V_2 = V_161 ;
F_4 ( V_6 , L_35 ) ;
}
F_24 ( & V_6 -> V_21 ) ;
if ( V_6 -> V_13 == V_14 && V_135 == V_241 )
return F_101 ( V_6 , V_54 ) ;
if ( V_2 != V_161 && V_2 != V_157 &&
V_2 != V_242 )
goto V_151;
if ( V_135 == V_138 ) {
F_82 ( V_6 , V_54 ) ;
return 0 ;
}
if ( V_2 != V_161 )
goto V_151;
if ( V_135 == V_79 && V_219 == V_243 )
F_75 ( V_6 , V_54 ) ;
else if ( V_135 == V_120 && V_219 == V_244 )
F_92 ( V_6 , V_175 ) ;
F_28 ( V_54 ) ;
return 0 ;
V_151:
F_28 ( V_54 ) ;
return - 1 ;
}
static struct V_8 * F_102 ( struct V_5 * V_6 )
{
struct V_8 * V_9 ;
struct V_8 * V_245 = V_6 -> V_33 ;
struct V_8 * V_209 ;
V_209 = F_103 ( & V_6 -> V_20 , struct V_8 , V_34 ) ;
F_29 (fcf, &fip->fcfs, list) {
F_4 ( V_6 , L_36
L_37
L_38 ,
V_9 -> V_172 , V_9 -> V_194 , V_9 -> V_41 ,
V_9 -> V_196 , F_5 ( V_9 ) ,
V_9 -> V_40 , V_9 -> V_191 ) ;
if ( V_9 -> V_172 != V_209 -> V_172 ||
V_9 -> V_194 != V_209 -> V_194 ||
V_9 -> V_196 != V_209 -> V_196 ) {
F_4 ( V_6 , L_39
L_40 ) ;
return NULL ;
}
if ( V_9 -> V_40 )
continue;
if ( ! F_6 ( V_9 ) ) {
F_4 ( V_6 , L_41
L_42 ,
V_9 -> V_172 , V_9 -> V_196 ,
( V_9 -> V_10 & V_11 ) ? L_43 : L_44 ,
( V_9 -> V_10 & V_12 ) ?
L_43 : L_45 ) ;
continue;
}
if ( ! V_245 || V_9 -> V_191 < V_245 -> V_191 || V_245 -> V_40 )
V_245 = V_9 ;
}
V_6 -> V_33 = V_245 ;
if ( V_245 ) {
F_4 ( V_6 , L_46 , V_245 -> V_41 ) ;
V_6 -> V_108 = V_101 +
F_62 ( V_165 ) ;
V_6 -> V_107 = V_101 + V_245 -> V_170 ;
if ( F_68 ( V_6 -> V_107 , V_6 -> V_25 . V_214 ) )
F_79 ( & V_6 -> V_25 , V_6 -> V_107 ) ;
}
return V_245 ;
}
static int F_104 ( struct V_5 * V_6 )
{
struct V_53 * V_54 ;
struct V_53 * V_246 ;
struct V_50 * V_133 ;
int error ;
V_246 = V_6 -> V_39 ;
if ( ! V_246 )
return - V_158 ;
V_54 = F_105 ( V_246 , V_213 ) ;
if ( ! V_54 ) {
V_54 = V_246 ;
V_6 -> V_39 = NULL ;
}
V_133 = (struct V_50 * ) V_54 -> V_69 ;
error = F_51 ( V_6 , V_6 -> V_7 , V_143 , V_54 ,
F_58 ( V_133 -> V_159 ) ) ;
if ( error ) {
F_28 ( V_54 ) ;
return error ;
}
V_6 -> V_99 ( V_6 , V_54 ) ;
V_6 -> V_33 -> V_40 = 1 ;
return 0 ;
}
static int F_84 ( struct V_5 * V_6 )
{
struct V_8 * V_9 ;
int error ;
F_23 ( & V_6 -> V_21 ) ;
F_27 ( & V_6 -> V_22 ) ;
F_4 ( V_6 , L_47 ) ;
V_9 = F_102 ( V_6 ) ;
if ( ! V_9 || V_9 -> V_40 ) {
F_28 ( V_6 -> V_39 ) ;
V_6 -> V_39 = NULL ;
error = - V_247 ;
} else {
F_35 ( V_6 , NULL ) ;
error = F_104 ( V_6 ) ;
}
F_30 ( & V_6 -> V_22 ) ;
F_24 ( & V_6 -> V_21 ) ;
return error ;
}
static void F_106 ( struct V_5 * V_6 )
{
struct V_8 * V_9 ;
F_27 ( & V_6 -> V_22 ) ;
V_9 = V_6 -> V_33 ;
if ( ! V_9 || ! V_6 -> V_152 )
goto V_42;
F_4 ( V_6 , L_48 ) ;
if ( V_9 -> V_40 ) {
F_4 ( V_6 , L_49 ) ;
V_9 = F_102 ( V_6 ) ;
if ( ! V_9 || V_9 -> V_40 ) {
F_4 ( V_6 , L_50 ) ;
F_29 (fcf, &fip->fcfs, list)
V_9 -> V_40 = 0 ;
V_9 = F_102 ( V_6 ) ;
}
}
if ( V_9 ) {
F_104 ( V_6 ) ;
V_6 -> V_152 = 0 ;
} else
F_4 ( V_6 , L_51 ) ;
V_42:
F_30 ( & V_6 -> V_22 ) ;
}
static void V_26 ( unsigned long V_248 )
{
struct V_5 * V_6 = (struct V_5 * ) V_248 ;
F_57 ( & V_6 -> V_27 ) ;
}
static void V_28 ( struct V_249 * V_250 )
{
struct V_5 * V_6 ;
struct V_110 * V_251 ;
T_3 * V_60 ;
T_3 V_252 = 0 ;
T_3 V_253 = 0 ;
T_3 V_254 = 0 ;
struct V_8 * V_38 ;
struct V_8 * V_9 ;
unsigned long V_164 ;
V_6 = F_55 ( V_250 , struct V_5 , V_27 ) ;
if ( V_6 -> V_13 == V_14 )
return F_107 ( V_6 ) ;
F_23 ( & V_6 -> V_21 ) ;
if ( V_6 -> V_2 == V_37 ) {
F_24 ( & V_6 -> V_21 ) ;
return;
}
V_9 = V_6 -> V_33 ;
V_164 = F_61 ( V_6 ) ;
V_38 = V_6 -> V_33 ;
if ( ! V_38 && V_6 -> V_36 ) {
if ( F_66 ( V_101 , V_6 -> V_36 ) ) {
V_38 = F_102 ( V_6 ) ;
V_6 -> V_36 = 0 ;
} else if ( F_65 ( V_164 , V_6 -> V_36 ) )
V_164 = V_6 -> V_36 ;
}
if ( V_38 && V_6 -> V_152 )
F_106 ( V_6 ) ;
else if ( ! V_38 && V_9 )
V_252 = 1 ;
if ( V_38 && ! V_38 -> V_198 ) {
if ( F_66 ( V_101 , V_6 -> V_107 ) ) {
V_6 -> V_107 = V_101 + V_38 -> V_170 ;
V_253 = 1 ;
}
if ( F_65 ( V_164 , V_6 -> V_107 ) )
V_164 = V_6 -> V_107 ;
if ( F_66 ( V_101 , V_6 -> V_108 ) ) {
V_6 -> V_108 = V_101 +
F_62 ( V_165 ) ;
V_254 = 1 ;
}
if ( F_65 ( V_164 , V_6 -> V_108 ) )
V_164 = V_6 -> V_108 ;
}
if ( ! F_76 ( & V_6 -> V_20 ) )
F_79 ( & V_6 -> V_25 , V_164 ) ;
F_24 ( & V_6 -> V_21 ) ;
if ( V_252 ) {
F_94 ( V_6 -> V_7 ) ;
F_35 ( V_6 , NULL ) ;
}
if ( V_253 )
F_50 ( V_6 , NULL , 0 , V_6 -> V_73 ) ;
if ( V_254 ) {
F_23 ( & V_6 -> V_7 -> V_235 ) ;
V_60 = V_6 -> V_123 ( V_6 -> V_7 ) ;
F_50 ( V_6 , V_6 -> V_7 , 1 , V_60 ) ;
F_29 (vport, &fip->lp->vports, list) {
V_60 = V_6 -> V_123 ( V_251 ) ;
F_50 ( V_6 , V_251 , 1 , V_60 ) ;
}
F_24 ( & V_6 -> V_7 -> V_235 ) ;
}
}
static void V_30 ( struct V_249 * V_29 )
{
struct V_5 * V_6 ;
struct V_53 * V_54 ;
V_6 = F_55 ( V_29 , struct V_5 , V_29 ) ;
while ( ( V_54 = F_108 ( & V_6 -> V_31 ) ) )
F_97 ( V_6 , V_54 ) ;
}
int F_109 ( struct V_5 * V_6 , struct V_110 * V_111 ,
struct V_145 * V_146 )
{
struct V_50 * V_133 ;
T_3 V_135 ;
T_3 * V_113 ;
V_113 = F_99 ( & V_146 -> V_54 ) -> V_72 ;
V_133 = F_110 ( V_146 ) ;
if ( V_133 -> V_255 != V_256 )
return 0 ;
V_135 = F_111 ( V_146 ) ;
if ( V_135 == V_139 && V_133 -> V_257 == V_258 &&
V_6 -> V_23 == F_56 ( V_133 -> V_149 ) ) {
F_23 ( & V_6 -> V_21 ) ;
if ( V_6 -> V_2 != V_103 && V_6 -> V_2 != V_102 ) {
F_24 ( & V_6 -> V_21 ) ;
return - V_158 ;
}
F_3 ( V_6 , V_102 ) ;
F_4 ( V_6 ,
L_52 ) ;
if ( ! F_31 ( V_113 , ( T_3 [ 6 ] ) V_259 ) ) {
F_7 ( V_6 ) ;
} else {
memcpy ( V_6 -> V_15 , V_113 , V_46 ) ;
V_6 -> V_18 = 0 ;
}
V_6 -> V_23 = V_24 ;
F_24 ( & V_6 -> V_21 ) ;
F_59 ( F_83 ( V_146 ) -> V_220 , V_133 -> V_159 ) ;
} else if ( V_135 == V_148 && V_133 -> V_257 == V_260 && V_113 ) {
F_23 ( & V_6 -> V_21 ) ;
if ( V_6 -> V_2 == V_103 || V_6 -> V_2 == V_102 ) {
memcpy ( V_6 -> V_15 , V_113 , V_46 ) ;
V_6 -> V_18 = 0 ;
if ( V_6 -> V_2 == V_103 )
F_4 ( V_6 , L_53
L_54 ) ;
F_3 ( V_6 , V_102 ) ;
}
F_24 ( & V_6 -> V_21 ) ;
}
return 0 ;
}
T_5 F_112 ( unsigned char V_60 [ V_261 ] ,
unsigned int V_262 , unsigned int V_263 )
{
T_5 V_177 ;
T_5 V_264 ;
V_264 = ( ( T_5 ) V_60 [ 0 ] << 40 ) |
( ( T_5 ) V_60 [ 1 ] << 32 ) |
( ( T_5 ) V_60 [ 2 ] << 24 ) |
( ( T_5 ) V_60 [ 3 ] << 16 ) |
( ( T_5 ) V_60 [ 4 ] << 8 ) |
( T_5 ) V_60 [ 5 ] ;
F_67 ( V_264 >= ( 1ULL << 48 ) ) ;
V_177 = V_264 | ( ( T_5 ) V_262 << 60 ) ;
switch ( V_262 ) {
case 1 :
F_67 ( V_263 != 0 ) ;
break;
case 2 :
F_67 ( V_263 >= 0xfff ) ;
V_177 |= ( T_5 ) V_263 << 48 ;
break;
default:
F_67 ( 1 ) ;
break;
}
return V_177 ;
}
static inline struct V_265 * F_113 ( struct V_266 * V_267 )
{
return (struct V_265 * ) ( V_267 + 1 ) ;
}
static void F_114 ( struct V_5 * V_6 ,
enum V_268 V_219 ,
const T_3 * V_269 , T_4 V_270 )
{
struct V_53 * V_54 ;
struct V_271 {
struct V_56 V_57 ;
struct V_58 V_6 ;
struct V_59 V_60 ;
struct V_61 V_62 ;
struct V_116 V_117 ;
} V_65 * V_272 ;
struct V_273 * V_274 ;
struct V_63 * V_64 ;
T_2 V_275 ;
T_4 V_118 ;
T_4 V_134 ;
V_118 = sizeof( * V_272 ) ;
V_134 = 0 ;
if ( V_219 == V_276 || V_219 == V_277 ) {
V_134 = sizeof( struct V_273 ) +
sizeof( struct V_63 ) ;
V_118 += V_134 ;
}
V_134 += sizeof( V_272 -> V_60 ) + sizeof( V_272 -> V_62 ) + sizeof( V_272 -> V_117 ) ;
V_118 = F_115 ( V_118 , V_270 + sizeof( struct V_56 ) ) ;
V_54 = F_36 ( V_118 ) ;
if ( ! V_54 )
return;
V_272 = (struct V_271 * ) V_54 -> V_69 ;
memset ( V_272 , 0 , V_118 ) ;
memcpy ( V_272 -> V_57 . V_70 , V_269 , V_46 ) ;
memcpy ( V_272 -> V_57 . V_72 , V_6 -> V_73 , V_46 ) ;
V_272 -> V_57 . V_74 = F_37 ( V_75 ) ;
V_272 -> V_6 . V_76 = F_38 ( V_77 ) ;
V_272 -> V_6 . V_78 = F_37 ( V_241 ) ;
V_272 -> V_6 . V_80 = V_219 ;
V_272 -> V_6 . V_82 = F_37 ( V_134 / V_83 ) ;
V_272 -> V_60 . V_88 . V_89 = V_90 ;
V_272 -> V_60 . V_88 . V_91 = sizeof( V_272 -> V_60 ) / V_83 ;
memcpy ( V_272 -> V_60 . V_92 , V_6 -> V_73 , V_46 ) ;
V_272 -> V_62 . V_88 . V_89 = V_93 ;
V_272 -> V_62 . V_88 . V_91 = sizeof( V_272 -> V_62 ) / V_83 ;
F_39 ( V_6 -> V_7 -> V_62 , & V_272 -> V_62 . V_94 ) ;
V_272 -> V_117 . V_88 . V_89 = V_122 ;
V_272 -> V_117 . V_88 . V_91 = sizeof( V_272 -> V_117 ) / V_83 ;
F_8 ( V_272 -> V_117 . V_92 , V_16 ) ;
F_8 ( V_272 -> V_117 . V_92 + 3 , V_6 -> V_119 ) ;
F_8 ( V_272 -> V_117 . V_124 , V_6 -> V_119 ) ;
F_39 ( V_6 -> V_7 -> V_125 , & V_272 -> V_117 . V_126 ) ;
if ( V_219 == V_276 || V_219 == V_277 ) {
V_274 = (struct V_273 * ) ( V_272 + 1 ) ;
V_274 -> V_88 . V_89 = V_278 ;
V_274 -> V_88 . V_91 = sizeof( * V_274 ) / V_83 ;
V_274 -> V_279 = V_6 -> V_7 -> V_280 ;
V_275 = 0 ;
if ( V_6 -> V_7 -> V_281 & V_282 )
V_275 |= V_283 ;
if ( V_6 -> V_7 -> V_281 & V_284 )
V_275 |= V_285 ;
V_275 <<= ( V_286 * 4 ) % 32 ;
V_274 -> V_287 . V_288 [ V_286 * 4 / 32 ] = F_116 ( V_275 ) ;
V_64 = (struct V_63 * ) ( V_274 + 1 ) ;
V_64 -> V_88 . V_89 = V_95 ;
V_64 -> V_88 . V_91 = sizeof( * V_64 ) / V_83 ;
V_64 -> V_96 = F_37 ( F_34 ( V_6 ) ) ;
}
F_40 ( V_54 , V_118 ) ;
V_54 -> V_97 = F_37 ( V_75 ) ;
V_54 -> V_98 = V_6 -> V_98 ;
F_41 ( V_54 ) ;
F_42 ( V_54 ) ;
V_6 -> V_99 ( V_6 , V_54 ) ;
}
static void F_117 ( struct V_110 * V_111 ,
struct V_266 * V_267 ,
enum V_289 V_290 )
{
struct V_5 * V_6 = V_111 -> V_291 . V_292 ;
struct V_265 * V_293 = F_113 ( V_267 ) ;
F_4 ( V_6 , L_55 ,
V_267 -> V_294 . V_119 , V_290 ) ;
F_23 ( & V_6 -> V_21 ) ;
switch ( V_290 ) {
case V_295 :
V_293 -> V_296 = 0 ;
break;
case V_297 :
case V_298 :
case V_299 :
V_293 -> V_296 ++ ;
if ( V_293 -> V_296 > V_300 ) {
F_4 ( V_6 ,
L_56 ,
V_267 -> V_294 . V_119 ) ;
V_111 -> V_301 . V_302 ( V_267 ) ;
}
break;
default:
break;
}
F_24 ( & V_6 -> V_21 ) ;
}
static void F_118 ( struct V_110 * V_111 )
{
F_23 ( & V_111 -> V_291 . V_303 ) ;
V_111 -> V_291 . V_304 = NULL ;
F_24 ( & V_111 -> V_291 . V_303 ) ;
}
static void F_119 ( struct V_110 * V_111 )
{
struct V_5 * V_6 = V_111 -> V_291 . V_292 ;
F_23 ( & V_6 -> V_21 ) ;
F_118 ( V_111 ) ;
F_24 ( & V_6 -> V_21 ) ;
}
static void F_120 ( struct V_110 * V_111 )
{
F_119 ( V_111 ) ;
V_111 -> V_301 . V_305 () ;
F_121 () ;
}
static void F_122 ( struct V_5 * V_6 )
{
unsigned long V_306 ;
T_2 V_119 ;
F_118 ( V_6 -> V_7 ) ;
V_119 = V_6 -> V_119 ;
if ( V_6 -> V_307 )
V_119 = F_123 ( & V_6 -> V_308 ) & 0xffff ;
else if ( ! V_119 )
V_119 = V_6 -> V_7 -> V_125 & 0xffff ;
if ( ! V_119 || V_119 == 0xffff )
V_119 = 1 ;
V_6 -> V_119 = V_119 ;
if ( V_6 -> V_307 < V_309 ) {
V_6 -> V_307 ++ ;
V_306 = F_124 () % V_310 ;
} else
V_306 = V_311 ;
F_79 ( & V_6 -> V_25 , V_101 + F_62 ( V_306 ) ) ;
F_3 ( V_6 , V_312 ) ;
}
static void F_45 ( struct V_5 * V_6 )
{
V_6 -> V_307 = 0 ;
F_125 ( & V_6 -> V_308 , V_6 -> V_7 -> V_125 ) ;
F_122 ( V_6 ) ;
}
static int F_126 ( struct V_5 * V_6 ,
struct V_53 * V_54 ,
struct V_266 * V_267 )
{
struct V_58 * V_175 ;
struct V_176 * V_66 = NULL ;
struct V_59 * V_313 = NULL ;
struct V_61 * V_177 = NULL ;
struct V_116 * V_117 = NULL ;
struct V_63 * V_64 = NULL ;
struct V_265 * V_293 ;
T_4 V_183 ;
T_4 V_134 ;
T_2 V_184 = 0 ;
T_2 V_127 ;
T_3 V_219 ;
memset ( V_267 , 0 , sizeof( * V_267 ) + sizeof( * V_293 ) ) ;
V_293 = F_113 ( V_267 ) ;
V_175 = (struct V_58 * ) V_54 -> V_69 ;
V_293 -> V_10 = F_56 ( V_175 -> V_84 ) ;
V_219 = V_175 -> V_80 ;
switch ( V_219 ) {
case V_314 :
case V_315 :
case V_316 :
V_184 = F_71 ( V_90 ) | F_71 ( V_93 ) |
F_71 ( V_122 ) ;
break;
case V_276 :
case V_277 :
V_184 = F_71 ( V_90 ) | F_71 ( V_93 ) |
F_71 ( V_122 ) | F_71 ( V_278 ) |
F_71 ( V_95 ) ;
break;
default:
F_4 ( V_6 , L_57 , V_219 ) ;
return - V_158 ;
}
V_183 = F_56 ( V_175 -> V_82 ) * 4 ;
if ( V_183 + sizeof( * V_175 ) > V_54 -> V_118 )
return - V_158 ;
V_66 = (struct V_176 * ) ( V_175 + 1 ) ;
while ( V_183 > 0 ) {
V_134 = V_66 -> V_91 * V_83 ;
if ( V_134 < sizeof( * V_66 ) || V_134 > V_183 )
return - V_158 ;
V_127 = V_66 -> V_89 ;
if ( V_127 < 32 ) {
if ( ! ( V_184 & F_71 ( V_127 ) ) ) {
F_4 ( V_6 ,
L_58
L_59
L_60 ,
V_127 , V_219 ) ;
return - V_158 ;
}
V_184 &= ~ F_71 ( V_127 ) ;
}
switch ( V_127 ) {
case V_90 :
if ( V_134 != sizeof( struct V_59 ) )
goto V_190;
V_313 = (struct V_59 * ) V_66 ;
if ( ! F_72 ( V_313 -> V_92 ) ) {
F_4 ( V_6 ,
L_61 ,
V_313 -> V_92 ) ;
return - V_158 ;
}
memcpy ( V_293 -> V_317 , V_313 -> V_92 , V_46 ) ;
break;
case V_93 :
if ( V_134 != sizeof( struct V_61 ) )
goto V_190;
V_177 = (struct V_61 * ) V_66 ;
V_267 -> V_294 . V_318 = F_73 ( & V_177 -> V_94 ) ;
break;
case V_122 :
if ( V_134 != sizeof( struct V_116 ) )
goto V_190;
V_117 = (struct V_116 * ) V_66 ;
memcpy ( V_293 -> V_319 , V_117 -> V_92 , V_46 ) ;
V_267 -> V_294 . V_119 = F_58 ( V_117 -> V_124 ) ;
V_267 -> V_294 . V_320 = F_73 ( & V_117 -> V_126 ) ;
break;
case V_278 :
if ( V_134 != sizeof( struct V_273 ) )
goto V_190;
break;
case V_95 :
if ( V_134 != sizeof( struct V_63 ) )
goto V_190;
V_64 = (struct V_63 * ) V_66 ;
V_293 -> V_321 = F_56 ( V_64 -> V_96 ) ;
break;
default:
F_4 ( V_6 , L_19
L_62 , V_127 ) ;
if ( V_127 < V_204 )
return - V_158 ;
break;
}
V_66 = (struct V_176 * ) ( ( char * ) V_66 + V_134 ) ;
V_183 -= V_134 ;
}
return 0 ;
V_190:
F_4 ( V_6 , L_22 ,
V_127 , V_134 ) ;
return - V_158 ;
}
static void F_127 ( struct V_5 * V_6 )
{
F_114 ( V_6 , V_276 , V_238 , 0 ) ;
V_6 -> V_100 = V_101 ;
}
static void F_128 ( struct V_5 * V_6 ,
struct V_266 * V_267 )
{
struct V_265 * V_293 = F_113 ( V_267 ) ;
if ( V_267 -> V_294 . V_119 != V_6 -> V_119 )
return;
switch ( V_6 -> V_2 ) {
case V_242 :
case V_157 :
F_114 ( V_6 , V_315 ,
V_293 -> V_317 , 0 ) ;
break;
case V_322 :
case V_323 :
if ( V_6 -> V_7 -> V_125 > V_267 -> V_294 . V_320 &&
! ( V_293 -> V_10 & V_324 ) ) {
F_114 ( V_6 , V_315 ,
V_293 -> V_317 , 0 ) ;
break;
}
case V_312 :
F_122 ( V_6 ) ;
break;
default:
break;
}
}
static void F_129 ( struct V_5 * V_6 ,
struct V_266 * V_267 )
{
if ( V_267 -> V_294 . V_119 != V_6 -> V_119 )
return;
switch ( V_6 -> V_2 ) {
case V_312 :
case V_322 :
case V_323 :
case V_242 :
F_122 ( V_6 ) ;
break;
case V_157 :
F_127 ( V_6 ) ;
break;
default:
break;
}
}
static void F_130 ( struct V_5 * V_6 , struct V_266 * V_205 )
{
struct V_110 * V_111 = V_6 -> V_7 ;
struct V_266 * V_267 ;
struct V_325 * V_294 ;
struct V_265 * V_293 ;
T_2 V_119 ;
V_119 = V_205 -> V_294 . V_119 ;
if ( V_119 == V_6 -> V_119 )
return;
F_23 ( & V_111 -> V_291 . V_303 ) ;
V_267 = V_111 -> V_301 . V_326 ( V_111 , V_119 ) ;
if ( ! V_267 ) {
F_24 ( & V_111 -> V_291 . V_303 ) ;
return;
}
V_267 -> V_327 = & V_328 ;
V_267 -> V_329 = V_111 -> V_291 . V_329 ;
V_294 = & V_267 -> V_294 ;
if ( ( V_294 -> V_320 != - 1 && V_294 -> V_320 != V_205 -> V_294 . V_320 ) ||
( V_294 -> V_318 != - 1 && V_294 -> V_318 != V_205 -> V_294 . V_318 ) )
V_111 -> V_301 . V_302 ( V_267 ) ;
V_294 -> V_320 = V_205 -> V_294 . V_320 ;
V_294 -> V_318 = V_205 -> V_294 . V_318 ;
F_24 ( & V_111 -> V_291 . V_303 ) ;
V_293 = F_113 ( V_267 ) ;
F_4 ( V_6 , L_63 ,
V_119 , V_293 -> V_321 ? L_64 : L_65 ) ;
* V_293 = * F_113 ( V_205 ) ;
V_293 -> time = 0 ;
}
static int F_53 ( struct V_5 * V_6 , T_2 V_119 , T_3 * V_60 )
{
struct V_110 * V_111 = V_6 -> V_7 ;
struct V_266 * V_267 ;
struct V_265 * V_293 ;
int V_330 = - 1 ;
F_131 () ;
V_267 = V_111 -> V_301 . V_331 ( V_111 , V_119 ) ;
if ( V_267 ) {
V_293 = F_113 ( V_267 ) ;
memcpy ( V_60 , V_293 -> V_317 , V_46 ) ;
V_330 = 0 ;
}
F_132 () ;
return V_330 ;
}
static void F_133 ( struct V_5 * V_6 ,
struct V_266 * V_205 )
{
struct V_265 * V_293 = F_113 ( V_205 ) ;
if ( V_293 -> V_10 & V_324 ) {
F_114 ( V_6 , V_314 , V_238 , 0 ) ;
return;
}
switch ( V_6 -> V_2 ) {
case V_312 :
case V_322 :
case V_323 :
if ( V_205 -> V_294 . V_119 == V_6 -> V_119 )
F_122 ( V_6 ) ;
break;
case V_242 :
case V_157 :
if ( V_205 -> V_294 . V_119 == V_6 -> V_119 ) {
if ( V_205 -> V_294 . V_320 > V_6 -> V_7 -> V_125 ) {
F_122 ( V_6 ) ;
break;
}
F_127 ( V_6 ) ;
break;
}
F_114 ( V_6 , V_277 , V_293 -> V_317 ,
F_134 ( ( T_2 ) V_293 -> V_321 ,
F_34 ( V_6 ) ) ) ;
F_130 ( V_6 , V_205 ) ;
break;
default:
break;
}
}
static void F_135 ( struct V_5 * V_6 ,
struct V_266 * V_205 )
{
F_4 ( V_6 , L_66 ,
V_205 -> V_294 . V_119 , F_1 ( V_6 -> V_2 ) ) ;
if ( V_6 -> V_2 == V_157 || V_6 -> V_2 == V_242 )
F_130 ( V_6 , V_205 ) ;
}
static void F_136 ( struct V_5 * V_6 ,
struct V_266 * V_205 )
{
struct V_110 * V_111 = V_6 -> V_7 ;
struct V_266 * V_267 ;
struct V_265 * V_293 ;
V_293 = F_113 ( V_205 ) ;
if ( V_293 -> V_10 & V_324 ) {
F_114 ( V_6 , V_314 , V_238 , 0 ) ;
return;
}
F_23 ( & V_111 -> V_291 . V_303 ) ;
V_267 = V_111 -> V_301 . V_331 ( V_111 , V_205 -> V_294 . V_119 ) ;
if ( V_267 )
F_137 ( & V_267 -> V_332 ) ;
F_24 ( & V_111 -> V_291 . V_303 ) ;
if ( V_267 ) {
if ( V_267 -> V_294 . V_318 == V_205 -> V_294 . V_318 &&
V_267 -> V_294 . V_320 == V_205 -> V_294 . V_320 ) {
V_293 = F_113 ( V_267 ) ;
if ( ! V_293 -> time && V_6 -> V_2 == V_157 )
V_111 -> V_301 . V_333 ( V_267 ) ;
V_293 -> time = V_101 ;
}
F_138 ( & V_267 -> V_332 , V_111 -> V_301 . V_334 ) ;
return;
}
if ( V_6 -> V_2 != V_157 )
return;
F_4 ( V_6 , L_67 ,
V_205 -> V_294 . V_119 ) ;
if ( F_65 ( V_101 ,
V_6 -> V_100 + F_62 ( V_335 ) ) )
F_127 ( V_6 ) ;
}
static unsigned long F_139 ( struct V_5 * V_6 )
{
struct V_110 * V_111 = V_6 -> V_7 ;
struct V_266 * V_267 ;
struct V_265 * V_293 ;
unsigned long V_336 ;
unsigned long V_166 ;
V_336 = V_101 + F_62 ( V_337 * 10 ) ;
F_23 ( & V_111 -> V_291 . V_303 ) ;
F_140 (rdata, &lport->disc.rports, peers) {
V_293 = F_113 ( V_267 ) ;
if ( ! V_293 -> time )
continue;
V_166 = V_293 -> time +
F_62 ( V_337 * 25 / 10 ) ;
if ( F_66 ( V_101 , V_166 ) ) {
V_293 -> time = 0 ;
F_4 ( V_6 ,
L_68 ,
V_267 -> V_294 . V_320 , V_267 -> V_294 . V_119 ) ;
V_111 -> V_301 . V_302 ( V_267 ) ;
} else if ( F_68 ( V_166 , V_336 ) )
V_336 = V_166 ;
}
F_24 ( & V_111 -> V_291 . V_303 ) ;
return V_336 ;
}
static int F_101 ( struct V_5 * V_6 , struct V_53 * V_54 )
{
struct V_58 * V_175 ;
enum V_268 V_219 ;
struct {
struct V_266 V_267 ;
struct V_265 V_293 ;
} V_338 ;
int V_339 ;
V_175 = (struct V_58 * ) V_54 -> V_69 ;
V_219 = V_175 -> V_80 ;
V_339 = F_126 ( V_6 , V_54 , & V_338 . V_267 ) ;
if ( V_339 ) {
F_4 ( V_6 , L_69 , V_339 ) ;
goto V_151;
}
F_23 ( & V_6 -> V_21 ) ;
switch ( V_219 ) {
case V_314 :
F_128 ( V_6 , & V_338 . V_267 ) ;
break;
case V_315 :
F_129 ( V_6 , & V_338 . V_267 ) ;
break;
case V_276 :
F_133 ( V_6 , & V_338 . V_267 ) ;
break;
case V_277 :
F_135 ( V_6 , & V_338 . V_267 ) ;
break;
case V_316 :
F_136 ( V_6 , & V_338 . V_267 ) ;
break;
default:
F_4 ( V_6 , L_70 , V_219 ) ;
V_339 = - 1 ;
break;
}
F_24 ( & V_6 -> V_21 ) ;
V_151:
F_28 ( V_54 ) ;
return V_339 ;
}
static void F_141 ( struct V_110 * V_111 , struct V_145 * V_146 )
{
struct V_340 V_341 ;
V_341 . V_342 = V_343 ;
V_341 . V_344 = V_345 ;
V_111 -> V_301 . V_346 ( V_146 , V_140 , & V_341 ) ;
F_142 ( V_146 ) ;
}
static void F_143 ( void (* F_144)( struct V_110 * ,
enum V_347 ) ,
struct V_110 * V_111 )
{
struct V_348 * V_291 = & V_111 -> V_291 ;
struct V_5 * V_6 = V_291 -> V_292 ;
F_23 ( & V_291 -> V_303 ) ;
V_291 -> V_304 = F_144 ;
V_291 -> V_329 = ( V_291 -> V_329 + 2 ) | 1 ;
V_291 -> V_349 = 1 ;
F_57 ( & V_6 -> V_27 ) ;
F_24 ( & V_291 -> V_303 ) ;
}
static void F_145 ( struct V_5 * V_6 )
{
struct V_110 * V_111 = V_6 -> V_7 ;
struct V_348 * V_291 = & V_111 -> V_291 ;
struct V_266 * V_267 ;
struct V_265 * V_293 ;
void (* F_144)( struct V_110 * , enum V_347 );
F_23 ( & V_291 -> V_303 ) ;
F_144 = V_291 -> V_349 ? V_291 -> V_304 : NULL ;
V_291 -> V_349 = 0 ;
F_140 (rdata, &disc->rports, peers) {
V_293 = F_113 ( V_267 ) ;
if ( V_293 -> time )
V_111 -> V_301 . V_333 ( V_267 ) ;
}
F_24 ( & V_291 -> V_303 ) ;
if ( F_144 )
F_144 ( V_111 , V_350 ) ;
}
static void F_107 ( struct V_5 * V_6 )
{
unsigned long V_336 ;
T_3 V_60 [ V_46 ] ;
T_2 V_351 = 0 ;
F_23 ( & V_6 -> V_21 ) ;
switch ( V_6 -> V_2 ) {
case V_312 :
F_3 ( V_6 , V_322 ) ;
F_114 ( V_6 , V_314 , V_238 , 0 ) ;
V_336 = V_101 + F_62 ( V_310 ) ;
break;
case V_322 :
F_3 ( V_6 , V_323 ) ;
F_114 ( V_6 , V_314 , V_238 , 0 ) ;
V_336 = V_101 + F_62 ( V_335 ) ;
break;
case V_323 :
F_3 ( V_6 , V_242 ) ;
V_351 = V_6 -> V_119 ;
F_8 ( V_60 , V_16 ) ;
F_8 ( V_60 + 3 , V_351 ) ;
F_7 ( V_6 ) ;
V_6 -> V_163 ( V_6 -> V_7 , V_60 ) ;
F_127 ( V_6 ) ;
V_336 = V_101 + F_62 ( V_335 ) ;
break;
case V_242 :
V_336 = V_6 -> V_100 + F_62 ( V_335 ) ;
if ( F_66 ( V_101 , V_336 ) ) {
F_3 ( V_6 , V_157 ) ;
F_114 ( V_6 , V_316 ,
V_238 , 0 ) ;
V_336 = V_101 + F_62 ( V_335 ) ;
V_6 -> V_108 = V_336 ;
}
F_145 ( V_6 ) ;
break;
case V_157 :
V_336 = F_139 ( V_6 ) ;
if ( F_66 ( V_101 , V_6 -> V_108 ) ) {
F_114 ( V_6 , V_316 ,
V_238 , 0 ) ;
V_6 -> V_108 = V_101 +
F_62 ( V_337 +
( F_124 () % V_352 ) ) ;
}
if ( F_68 ( V_6 -> V_108 , V_336 ) )
V_336 = V_6 -> V_108 ;
break;
case V_19 :
goto V_42;
default:
F_146 ( 1 , L_71 , V_6 -> V_2 ) ;
goto V_42;
}
F_79 ( & V_6 -> V_25 , V_336 ) ;
V_42:
F_24 ( & V_6 -> V_21 ) ;
if ( V_351 )
F_147 ( V_6 -> V_7 , V_351 ) ;
}
int F_148 ( struct V_110 * V_111 , struct V_5 * V_6 ,
const struct V_353 * V_301 , int V_354 )
{
memcpy ( & V_111 -> V_301 , V_301 , sizeof( * V_301 ) ) ;
if ( V_354 && F_149 ( V_111 ) )
return - V_355 ;
F_150 ( V_111 ) ;
F_151 ( V_111 ) ;
F_152 ( V_111 ) ;
if ( V_6 -> V_13 == V_14 )
V_111 -> V_356 = sizeof( struct V_265 ) ;
F_153 ( V_111 ) ;
if ( V_6 -> V_13 == V_14 ) {
V_111 -> V_136 = 1 ;
V_111 -> V_301 . V_357 = F_141 ;
V_111 -> V_301 . V_358 = F_143 ;
V_111 -> V_301 . V_359 = F_119 ;
V_111 -> V_301 . V_360 = F_120 ;
F_11 ( & V_111 -> V_291 . V_303 ) ;
F_10 ( & V_111 -> V_291 . V_361 ) ;
V_111 -> V_291 . V_292 = V_6 ;
} else {
F_154 ( V_111 ) ;
}
return 0 ;
}
