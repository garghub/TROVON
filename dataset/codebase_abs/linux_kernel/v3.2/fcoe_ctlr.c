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
memcpy ( V_6 -> V_15 , V_38 -> V_41 , V_46 ) ;
V_6 -> V_18 = 0 ;
}
V_42:
F_24 ( & V_6 -> V_21 ) ;
}
static inline T_2 F_34 ( struct V_5 * V_6 )
{
return V_6 -> V_7 -> V_48 + sizeof( struct V_49 ) +
sizeof( struct V_50 ) + sizeof( struct V_51 ) ;
}
static void F_35 ( struct V_5 * V_6 , struct V_8 * V_9 )
{
struct V_52 * V_53 ;
struct V_54 {
struct V_55 V_56 ;
struct V_57 V_6 ;
struct {
struct V_58 V_59 ;
struct V_60 V_61 ;
struct V_62 V_63 ;
} V_64 V_65 ;
} V_64 * V_66 ;
T_2 V_67 ;
V_53 = F_36 ( sizeof( * V_66 ) ) ;
if ( ! V_53 )
return;
V_66 = (struct V_54 * ) V_53 -> V_68 ;
memset ( V_66 , 0 , sizeof( * V_66 ) ) ;
memcpy ( V_66 -> V_56 . V_69 , V_9 ? V_9 -> V_41 : V_70 , V_46 ) ;
memcpy ( V_66 -> V_56 . V_71 , V_6 -> V_72 , V_46 ) ;
V_66 -> V_56 . V_73 = F_37 ( V_74 ) ;
V_66 -> V_6 . V_75 = F_38 ( V_76 ) ;
V_66 -> V_6 . V_77 = F_37 ( V_78 ) ;
V_66 -> V_6 . V_79 = V_80 ;
V_66 -> V_6 . V_81 = F_37 ( sizeof( V_66 -> V_65 ) / V_82 ) ;
V_66 -> V_6 . V_83 = F_37 ( V_84 ) ;
if ( V_6 -> V_85 )
V_66 -> V_6 . V_83 |= F_37 ( V_86 ) ;
V_66 -> V_65 . V_59 . V_87 . V_88 = V_89 ;
V_66 -> V_65 . V_59 . V_87 . V_90 = sizeof( V_66 -> V_65 . V_59 ) / V_82 ;
memcpy ( V_66 -> V_65 . V_59 . V_91 , V_6 -> V_72 , V_46 ) ;
V_66 -> V_65 . V_61 . V_87 . V_88 = V_92 ;
V_66 -> V_65 . V_61 . V_87 . V_90 = sizeof( V_66 -> V_65 . V_61 ) / V_82 ;
F_39 ( V_6 -> V_7 -> V_61 , & V_66 -> V_65 . V_61 . V_93 ) ;
V_67 = F_34 ( V_6 ) ;
V_66 -> V_65 . V_63 . V_87 . V_88 = V_94 ;
V_66 -> V_65 . V_63 . V_87 . V_90 = sizeof( V_66 -> V_65 . V_63 ) / V_82 ;
V_66 -> V_65 . V_63 . V_95 = F_37 ( V_67 ) ;
F_40 ( V_53 , sizeof( * V_66 ) ) ;
V_53 -> V_96 = F_37 ( V_74 ) ;
V_53 -> V_97 = V_6 -> V_97 ;
F_41 ( V_53 ) ;
F_42 ( V_53 ) ;
V_6 -> V_98 ( V_6 , V_53 ) ;
if ( ! V_9 )
V_6 -> V_99 = V_100 ;
}
void F_43 ( struct V_5 * V_6 )
{
F_23 ( & V_6 -> V_21 ) ;
if ( V_6 -> V_2 == V_101 || V_6 -> V_2 == V_102 ) {
F_24 ( & V_6 -> V_21 ) ;
F_44 ( V_6 -> V_7 ) ;
} else if ( V_6 -> V_2 == V_19 ) {
F_3 ( V_6 , V_6 -> V_13 ) ;
switch ( V_6 -> V_13 ) {
default:
F_4 ( V_6 , L_7 , V_6 -> V_13 ) ;
case V_103 :
F_4 ( V_6 , L_8 , L_9 ) ;
case V_104 :
case V_105 :
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
V_6 -> V_106 = 0 ;
V_6 -> V_107 = 0 ;
V_6 -> V_99 = 0 ;
V_6 -> V_23 = V_24 ;
F_7 ( V_6 ) ;
}
int F_48 ( struct V_5 * V_6 )
{
int V_108 ;
F_4 ( V_6 , L_10 ) ;
F_23 ( & V_6 -> V_21 ) ;
F_46 ( V_6 ) ;
V_108 = V_6 -> V_2 != V_19 ;
F_3 ( V_6 , V_19 ) ;
F_24 ( & V_6 -> V_21 ) ;
if ( V_108 )
F_49 ( V_6 -> V_7 ) ;
return V_108 ;
}
static void F_50 ( struct V_5 * V_6 ,
struct V_109 * V_110 ,
int V_111 , T_3 * V_112 )
{
struct V_52 * V_53 ;
struct V_113 {
struct V_55 V_56 ;
struct V_57 V_6 ;
struct V_58 V_59 ;
} V_64 * V_114 ;
struct V_115 * V_116 ;
T_2 V_117 ;
struct V_109 * V_7 ;
struct V_8 * V_9 ;
V_9 = V_6 -> V_33 ;
V_7 = V_6 -> V_7 ;
if ( ! V_9 || ( V_111 && ! V_7 -> V_118 ) )
return;
V_117 = sizeof( * V_114 ) + V_111 * sizeof( * V_116 ) ;
V_53 = F_36 ( V_117 ) ;
if ( ! V_53 )
return;
V_114 = (struct V_113 * ) V_53 -> V_68 ;
memset ( V_114 , 0 , V_117 ) ;
memcpy ( V_114 -> V_56 . V_69 , V_9 -> V_41 , V_46 ) ;
memcpy ( V_114 -> V_56 . V_71 , V_112 , V_46 ) ;
V_114 -> V_56 . V_73 = F_37 ( V_74 ) ;
V_114 -> V_6 . V_75 = F_38 ( V_76 ) ;
V_114 -> V_6 . V_77 = F_37 ( V_119 ) ;
V_114 -> V_6 . V_79 = V_120 ;
V_114 -> V_6 . V_81 = F_37 ( ( sizeof( V_114 -> V_59 ) +
V_111 * sizeof( * V_116 ) ) / V_82 ) ;
V_114 -> V_6 . V_83 = F_37 ( V_84 ) ;
if ( V_6 -> V_85 )
V_114 -> V_6 . V_83 |= F_37 ( V_86 ) ;
V_114 -> V_59 . V_87 . V_88 = V_89 ;
V_114 -> V_59 . V_87 . V_90 = sizeof( V_114 -> V_59 ) / V_82 ;
memcpy ( V_114 -> V_59 . V_91 , V_6 -> V_72 , V_46 ) ;
if ( V_111 ) {
V_116 = (struct V_115 * ) ( V_114 + 1 ) ;
V_116 -> V_87 . V_88 = V_121 ;
V_116 -> V_87 . V_90 = sizeof( * V_116 ) / V_82 ;
memcpy ( V_116 -> V_91 , V_6 -> V_122 ( V_110 ) , V_46 ) ;
F_8 ( V_116 -> V_123 , V_110 -> V_118 ) ;
F_39 ( V_110 -> V_124 , & V_116 -> V_125 ) ;
}
F_40 ( V_53 , V_117 ) ;
V_53 -> V_96 = F_37 ( V_74 ) ;
V_53 -> V_97 = V_6 -> V_97 ;
F_41 ( V_53 ) ;
F_42 ( V_53 ) ;
V_6 -> V_98 ( V_6 , V_53 ) ;
}
static int F_51 ( struct V_5 * V_6 , struct V_109 * V_110 ,
T_3 V_126 , struct V_52 * V_53 , T_2 V_127 )
{
struct V_128 {
struct V_55 V_56 ;
struct V_57 V_6 ;
struct V_129 V_130 ;
} V_64 * V_131 ;
struct V_49 * V_132 ;
struct V_58 * V_59 ;
struct V_8 * V_9 ;
T_4 V_133 ;
T_1 V_83 ;
T_3 V_134 ;
V_132 = (struct V_49 * ) V_53 -> V_68 ;
V_134 = * ( T_3 * ) ( V_132 + 1 ) ;
V_133 = sizeof( struct V_129 ) + V_53 -> V_117 ;
V_131 = (struct V_128 * ) F_52 ( V_53 , sizeof( * V_131 ) ) ;
memset ( V_131 , 0 , sizeof( * V_131 ) ) ;
if ( V_110 -> V_135 ) {
if ( F_53 ( V_6 , V_127 , V_131 -> V_56 . V_69 ) )
return - V_136 ;
V_83 = 0 ;
} else {
V_9 = V_6 -> V_33 ;
if ( ! V_9 )
return - V_136 ;
V_83 = V_9 -> V_10 ;
V_83 &= V_6 -> V_85 ? V_86 | V_84 :
V_84 ;
if ( ! V_83 )
return - V_136 ;
memcpy ( V_131 -> V_56 . V_69 , V_9 -> V_41 , V_46 ) ;
}
memcpy ( V_131 -> V_56 . V_71 , V_6 -> V_72 , V_46 ) ;
V_131 -> V_56 . V_73 = F_37 ( V_74 ) ;
V_131 -> V_6 . V_75 = F_38 ( V_76 ) ;
V_131 -> V_6 . V_77 = F_37 ( V_137 ) ;
if ( V_134 == V_138 || V_134 == V_139 )
V_131 -> V_6 . V_79 = V_140 ;
else
V_131 -> V_6 . V_79 = V_141 ;
V_131 -> V_6 . V_83 = F_37 ( V_83 ) ;
V_131 -> V_130 . V_87 . V_88 = V_126 ;
V_131 -> V_130 . V_87 . V_90 = V_133 / V_82 ;
if ( V_134 != V_139 ) {
V_133 += sizeof( * V_59 ) ;
V_59 = (struct V_58 * ) F_40 ( V_53 , sizeof( * V_59 ) ) ;
memset ( V_59 , 0 , sizeof( * V_59 ) ) ;
V_59 -> V_87 . V_88 = V_89 ;
V_59 -> V_87 . V_90 = sizeof( * V_59 ) / V_82 ;
if ( V_126 != V_142 && V_126 != V_143 ) {
memcpy ( V_59 -> V_91 , V_6 -> V_122 ( V_110 ) , V_46 ) ;
} else if ( V_6 -> V_13 == V_14 ) {
F_8 ( V_59 -> V_91 , V_16 ) ;
F_8 ( V_59 -> V_91 + 3 , V_6 -> V_118 ) ;
} else if ( V_83 & V_86 ) {
F_4 ( V_6 , L_11 ) ;
memcpy ( V_59 -> V_91 , V_6 -> V_72 , V_46 ) ;
} else {
F_4 ( V_6 , L_12 ) ;
}
}
V_131 -> V_6 . V_81 = F_37 ( V_133 / V_82 ) ;
V_53 -> V_96 = F_37 ( V_74 ) ;
V_53 -> V_97 = V_6 -> V_97 ;
F_41 ( V_53 ) ;
F_42 ( V_53 ) ;
return 0 ;
}
int F_54 ( struct V_5 * V_6 , struct V_109 * V_110 ,
struct V_52 * V_53 )
{
struct V_144 * V_145 ;
struct V_49 * V_132 ;
T_1 V_146 ;
T_3 V_134 ;
T_3 V_59 [ V_46 ] ;
V_145 = F_55 ( V_53 , struct V_144 , V_53 ) ;
V_132 = (struct V_49 * ) V_53 -> V_68 ;
V_134 = * ( T_3 * ) ( V_132 + 1 ) ;
if ( V_134 == V_147 && V_6 -> V_13 != V_14 ) {
V_146 = V_6 -> V_23 ;
V_6 -> V_23 = F_56 ( V_132 -> V_148 ) ;
if ( V_6 -> V_2 == V_102 ) {
if ( V_146 == V_24 )
V_6 -> V_149 = 0 ;
V_6 -> V_149 ++ ;
if ( V_6 -> V_149 < 3 )
goto V_150;
F_7 ( V_6 ) ;
return 0 ;
}
if ( V_6 -> V_2 == V_101 )
F_7 ( V_6 ) ;
}
if ( V_6 -> V_2 == V_101 )
return 0 ;
if ( ! V_6 -> V_33 && V_6 -> V_13 != V_14 )
goto V_150;
switch ( V_134 ) {
case V_147 :
V_134 = V_142 ;
if ( V_6 -> V_13 == V_14 )
break;
F_27 ( & V_6 -> V_22 ) ;
F_28 ( V_6 -> V_39 ) ;
V_6 -> V_39 = V_53 ;
V_6 -> V_151 = 1 ;
F_30 ( & V_6 -> V_22 ) ;
F_57 ( & V_6 -> V_27 ) ;
return - V_152 ;
case V_153 :
if ( F_58 ( V_132 -> V_154 ) )
return 0 ;
V_134 = V_143 ;
break;
case V_155 :
if ( V_6 -> V_13 == V_14 ) {
if ( V_6 -> V_2 != V_156 )
return - V_157 ;
if ( F_58 ( V_132 -> V_158 ) == V_159 )
return - V_157 ;
} else {
if ( V_6 -> V_2 != V_160 )
return 0 ;
if ( F_58 ( V_132 -> V_158 ) != V_159 )
return 0 ;
}
V_134 = V_161 ;
break;
case V_138 :
if ( V_6 -> V_2 == V_101 ) {
if ( V_6 -> V_23 == V_24 )
return 0 ;
V_6 -> V_23 = V_24 ;
F_59 ( V_59 , V_132 -> V_158 ) ;
V_6 -> V_162 ( V_110 , V_59 ) ;
}
case V_139 :
V_134 = F_60 ( V_145 ) ;
if ( V_134 )
break;
return 0 ;
default:
if ( V_6 -> V_2 != V_160 &&
V_6 -> V_2 != V_156 )
goto V_150;
return 0 ;
}
F_4 ( V_6 , L_13 ,
V_134 , F_58 ( V_132 -> V_158 ) ) ;
if ( F_51 ( V_6 , V_110 , V_134 , V_53 , F_58 ( V_132 -> V_158 ) ) )
goto V_150;
V_6 -> V_98 ( V_6 , V_53 ) ;
return - V_152 ;
V_150:
F_28 ( V_53 ) ;
return - V_157 ;
}
static unsigned long F_61 ( struct V_5 * V_6 )
{
struct V_8 * V_9 ;
struct V_8 * V_32 ;
unsigned long V_163 = V_100 + F_62 ( V_164 ) ;
unsigned long V_165 ;
unsigned long V_36 = 0 ;
struct V_166 * V_167 ;
V_167 = F_63 ( V_6 -> V_7 -> V_168 , F_64 () ) ;
F_17 (fcf, next, &fip->fcfs, list) {
V_165 = V_9 -> time + V_9 -> V_169 + V_9 -> V_169 / 2 ;
if ( V_6 -> V_33 == V_9 ) {
if ( F_65 ( V_100 , V_165 ) ) {
V_167 -> V_170 ++ ;
F_33 ( V_47 L_3
L_14
L_15 ,
V_6 -> V_7 -> V_44 -> V_45 , V_9 -> V_171 ,
V_167 -> V_170 ) ;
} else if ( F_65 ( V_163 , V_165 ) )
V_163 = V_165 ;
}
V_165 += V_9 -> V_169 ;
if ( F_66 ( V_100 , V_165 ) ) {
if ( V_6 -> V_33 == V_9 )
V_6 -> V_33 = NULL ;
F_18 ( & V_9 -> V_34 ) ;
F_67 ( ! V_6 -> V_35 ) ;
V_6 -> V_35 -- ;
F_19 ( V_9 ) ;
V_167 -> V_172 ++ ;
} else {
if ( F_65 ( V_163 , V_165 ) )
V_163 = V_165 ;
if ( F_5 ( V_9 ) &&
( ! V_36 || F_68 ( V_36 , V_9 -> time ) ) )
V_36 = V_9 -> time ;
}
}
F_69 () ;
if ( V_36 && ! V_6 -> V_33 && ! V_6 -> V_36 ) {
V_36 += F_62 ( V_173 ) ;
V_6 -> V_36 = V_36 ;
}
return V_163 ;
}
static int F_70 ( struct V_5 * V_6 ,
struct V_52 * V_53 , struct V_8 * V_9 )
{
struct V_57 * V_174 ;
struct V_175 * V_65 = NULL ;
struct V_60 * V_176 ;
struct V_177 * V_178 ;
struct V_179 * V_180 ;
unsigned long V_181 ;
T_4 V_182 ;
T_4 V_133 ;
T_2 V_183 ;
memset ( V_9 , 0 , sizeof( * V_9 ) ) ;
V_9 -> V_169 = F_62 ( V_184 ) ;
V_174 = (struct V_57 * ) V_53 -> V_68 ;
V_9 -> V_10 = F_56 ( V_174 -> V_83 ) ;
V_183 = F_71 ( V_185 ) | F_71 ( V_89 ) | F_71 ( V_92 ) |
F_71 ( V_186 ) | F_71 ( V_187 ) ;
V_182 = F_56 ( V_174 -> V_81 ) * 4 ;
if ( V_182 + sizeof( * V_174 ) > V_53 -> V_117 )
return - V_157 ;
V_65 = (struct V_175 * ) ( V_174 + 1 ) ;
while ( V_182 > 0 ) {
V_133 = V_65 -> V_90 * V_82 ;
if ( V_133 < sizeof( * V_65 ) || V_133 > V_182 )
return - V_157 ;
if ( ( V_65 -> V_88 < 32 ) &&
! ( V_183 & 1U << V_65 -> V_88 ) ) {
F_4 ( V_6 , L_16
L_17 ) ;
return - V_157 ;
}
switch ( V_65 -> V_88 ) {
case V_185 :
if ( V_133 != sizeof( struct V_188 ) )
goto V_189;
V_9 -> V_190 = ( (struct V_188 * ) V_65 ) -> V_191 ;
V_183 &= ~ F_71 ( V_185 ) ;
break;
case V_89 :
if ( V_133 != sizeof( struct V_58 ) )
goto V_189;
memcpy ( V_9 -> V_41 ,
( (struct V_58 * ) V_65 ) -> V_91 ,
V_46 ) ;
if ( ! F_72 ( V_9 -> V_41 ) ) {
F_4 ( V_6 ,
L_18 ,
V_9 -> V_41 ) ;
return - V_157 ;
}
V_183 &= ~ F_71 ( V_89 ) ;
break;
case V_92 :
if ( V_133 != sizeof( struct V_60 ) )
goto V_189;
V_176 = (struct V_60 * ) V_65 ;
V_9 -> V_192 = F_73 ( & V_176 -> V_93 ) ;
V_183 &= ~ F_71 ( V_92 ) ;
break;
case V_186 :
if ( V_133 != sizeof( struct V_177 ) )
goto V_189;
V_178 = (struct V_177 * ) V_65 ;
V_9 -> V_171 = F_73 ( & V_178 -> V_93 ) ;
V_9 -> V_193 = F_56 ( V_178 -> V_194 ) ;
V_9 -> V_195 = F_58 ( V_178 -> V_196 ) ;
V_183 &= ~ F_71 ( V_186 ) ;
break;
case V_187 :
if ( V_133 != sizeof( struct V_179 ) )
goto V_189;
V_180 = (struct V_179 * ) V_65 ;
if ( V_180 -> V_197 & V_198 )
V_9 -> V_197 = 1 ;
V_181 = F_74 ( V_180 -> V_199 ) ;
if ( V_181 >= V_200 )
V_9 -> V_169 = F_62 ( V_181 ) ;
V_183 &= ~ F_71 ( V_187 ) ;
break;
case V_201 :
case V_94 :
case V_142 :
case V_143 :
case V_161 :
case V_202 :
default:
F_4 ( V_6 , L_19
L_20 , V_65 -> V_88 ) ;
if ( V_65 -> V_88 < V_203 )
return - V_157 ;
break;
}
V_65 = (struct V_175 * ) ( ( char * ) V_65 + V_133 ) ;
V_182 -= V_133 ;
}
if ( ! V_9 -> V_195 || ( V_9 -> V_195 & 0x10000 ) )
return - V_157 ;
if ( ! V_9 -> V_192 )
return - V_157 ;
if ( V_183 ) {
F_4 ( V_6 , L_21 ,
V_183 ) ;
return - V_157 ;
}
return 0 ;
V_189:
F_4 ( V_6 , L_22 ,
V_65 -> V_88 , V_133 ) ;
return - V_157 ;
}
static void F_75 ( struct V_5 * V_6 , struct V_52 * V_53 )
{
struct V_8 * V_9 ;
struct V_8 V_204 ;
struct V_8 * V_205 ;
unsigned long V_206 = F_62 ( V_207 ) ;
int V_208 = 0 ;
int V_209 ;
if ( F_70 ( V_6 , V_53 , & V_204 ) )
return;
F_23 ( & V_6 -> V_21 ) ;
V_208 = F_76 ( & V_6 -> V_20 ) ;
V_205 = NULL ;
F_29 (fcf, &fip->fcfs, list) {
if ( V_9 -> V_192 == V_204 . V_192 &&
V_9 -> V_171 == V_204 . V_171 &&
V_9 -> V_195 == V_204 . V_195 &&
F_31 ( V_9 -> V_41 , V_204 . V_41 ) == 0 ) {
V_205 = V_9 ;
break;
}
}
if ( ! V_205 ) {
if ( V_6 -> V_35 >= V_210 )
goto V_211;
V_9 = F_77 ( sizeof( * V_9 ) , V_212 ) ;
if ( ! V_9 )
goto V_211;
V_6 -> V_35 ++ ;
memcpy ( V_9 , & V_204 , sizeof( V_204 ) ) ;
F_78 ( & V_9 -> V_34 , & V_6 -> V_20 ) ;
} else {
V_9 -> V_197 = V_204 . V_197 ;
if ( ! F_6 ( V_9 ) )
V_9 -> V_10 = V_204 . V_10 ;
if ( V_9 == V_6 -> V_33 && ! V_9 -> V_197 ) {
V_6 -> V_106 -= V_9 -> V_169 ;
V_6 -> V_106 += V_204 . V_169 ;
if ( F_68 ( V_6 -> V_106 , V_6 -> V_25 . V_213 ) )
F_79 ( & V_6 -> V_25 , V_6 -> V_106 ) ;
}
V_9 -> V_169 = V_204 . V_169 ;
memcpy ( V_9 -> V_41 , V_204 . V_41 , V_46 ) ;
}
V_209 = F_5 ( V_9 ) ;
V_9 -> time = V_100 ;
if ( ! V_205 )
F_4 ( V_6 , L_23 ,
V_9 -> V_171 , V_9 -> V_41 ) ;
if ( ! V_209 )
F_35 ( V_6 , V_9 ) ;
if ( V_208 && F_65 ( V_100 , V_6 -> V_99 + V_206 ) )
F_35 ( V_6 , NULL ) ;
if ( V_209 )
F_80 ( & V_9 -> V_34 , & V_6 -> V_20 ) ;
if ( V_209 && ! V_6 -> V_33 && F_6 ( V_9 ) ) {
V_6 -> V_36 = V_100 +
F_62 ( V_173 ) ;
if ( ! F_81 ( & V_6 -> V_25 ) ||
F_68 ( V_6 -> V_36 , V_6 -> V_25 . V_213 ) )
F_79 ( & V_6 -> V_25 , V_6 -> V_36 ) ;
}
V_211:
F_24 ( & V_6 -> V_21 ) ;
}
static void F_82 ( struct V_5 * V_6 , struct V_52 * V_53 )
{
struct V_109 * V_110 = V_6 -> V_7 ;
struct V_57 * V_174 ;
struct V_144 * V_145 = (struct V_144 * ) V_53 ;
struct V_49 * V_132 = NULL ;
struct V_175 * V_65 ;
struct V_129 * V_214 ;
struct V_166 * V_167 ;
enum V_215 V_216 = 0 ;
T_3 V_217 ;
T_3 V_218 ;
T_3 V_219 [ V_46 ] = { 0 } ;
T_4 V_220 = 0 ;
T_4 V_182 ;
T_4 V_133 ;
T_2 V_183 = 0 ;
T_2 V_221 = 0 ;
V_174 = (struct V_57 * ) V_53 -> V_68 ;
V_218 = V_174 -> V_79 ;
if ( V_218 != V_141 && V_218 != V_140 )
goto V_150;
V_182 = F_56 ( V_174 -> V_81 ) * 4 ;
if ( V_182 + sizeof( * V_174 ) > V_53 -> V_117 )
goto V_150;
V_65 = (struct V_175 * ) ( V_174 + 1 ) ;
while ( V_182 > 0 ) {
V_221 ++ ;
V_133 = V_65 -> V_90 * V_82 ;
if ( V_133 < sizeof( * V_65 ) || V_133 > V_182 )
goto V_150;
if ( V_65 -> V_88 < 32 ) {
if ( V_183 & 1U << V_65 -> V_88 ) {
F_4 ( V_6 , L_16
L_24 ) ;
goto V_150;
}
V_183 |= ( 1 << V_65 -> V_88 ) ;
}
switch ( V_65 -> V_88 ) {
case V_89 :
if ( V_221 == 1 ) {
F_4 ( V_6 , L_25
L_26 ) ;
goto V_150;
}
if ( V_133 != sizeof( struct V_58 ) )
goto V_189;
memcpy ( V_219 ,
( (struct V_58 * ) V_65 ) -> V_91 ,
V_46 ) ;
break;
case V_142 :
case V_143 :
case V_161 :
case V_202 :
if ( V_221 != 1 ) {
F_4 ( V_6 , L_25
L_26 ) ;
goto V_150;
}
if ( V_132 )
goto V_150;
if ( V_133 < sizeof( * V_214 ) + sizeof( * V_132 ) + 1 )
goto V_189;
V_220 = V_133 - sizeof( * V_214 ) ;
V_214 = (struct V_129 * ) V_65 ;
V_132 = (struct V_49 * ) ( V_214 + 1 ) ;
V_216 = V_65 -> V_88 ;
break;
default:
F_4 ( V_6 , L_19
L_20 , V_65 -> V_88 ) ;
if ( V_65 -> V_88 < V_203 )
goto V_150;
if ( V_221 <= 2 ) {
F_4 ( V_6 , L_25
L_26 ) ;
goto V_150;
}
break;
}
V_65 = (struct V_175 * ) ( ( char * ) V_65 + V_133 ) ;
V_182 -= V_133 ;
}
if ( ! V_132 )
goto V_150;
V_217 = * ( T_3 * ) ( V_132 + 1 ) ;
if ( ( V_216 == V_142 || V_216 == V_143 ) &&
V_218 == V_140 && V_6 -> V_13 != V_14 ) {
if ( V_217 == V_138 ) {
if ( ! F_72 ( V_219 ) ) {
F_4 ( V_6 ,
L_27 ,
V_219 ) ;
goto V_150;
}
memcpy ( F_83 ( V_145 ) -> V_219 , V_219 , V_46 ) ;
if ( V_6 -> V_23 == F_56 ( V_132 -> V_148 ) ) {
V_6 -> V_23 = V_24 ;
if ( V_216 == V_142 )
F_26 ( V_6 ) ;
}
} else if ( V_216 == V_142 &&
! F_84 ( V_6 ) )
goto V_150;
}
if ( ( V_221 == 0 ) || ( ( V_217 != V_139 ) &&
( ! ( 1U << V_89 & V_183 ) ) ) ) {
F_4 ( V_6 , L_28
L_29 ) ;
goto V_150;
}
F_85 ( V_53 , ( T_3 * ) V_132 - V_53 -> V_68 ) ;
F_86 ( V_53 , V_220 ) ;
V_145 = (struct V_144 * ) V_53 ;
F_87 ( V_145 ) ;
F_88 ( V_145 ) = V_222 ;
F_89 ( V_145 ) = V_223 ;
F_90 ( V_145 ) = V_110 ;
F_60 ( V_145 ) = V_216 ;
V_167 = F_63 ( V_110 -> V_168 , F_64 () ) ;
V_167 -> V_224 ++ ;
V_167 -> V_225 += V_53 -> V_117 / V_82 ;
F_69 () ;
F_91 ( V_110 , V_145 ) ;
return;
V_189:
F_4 ( V_6 , L_22 ,
V_65 -> V_88 , V_133 ) ;
V_150:
F_28 ( V_53 ) ;
}
static void F_92 ( struct V_5 * V_6 ,
struct V_57 * V_132 )
{
struct V_175 * V_65 ;
struct V_58 * V_226 ;
struct V_60 * V_227 ;
struct V_115 * V_228 ;
T_4 V_182 ;
T_4 V_133 ;
struct V_8 * V_9 = V_6 -> V_33 ;
struct V_109 * V_110 = V_6 -> V_7 ;
struct V_109 * V_229 = NULL ;
T_2 V_183 ;
int V_230 ;
int V_231 = 0 ;
struct V_115 * * V_232 = NULL ;
F_4 ( V_6 , L_30 ) ;
if ( ! V_9 || ! V_110 -> V_118 )
return;
V_183 = F_71 ( V_89 ) | F_71 ( V_92 ) ;
V_182 = F_56 ( V_132 -> V_81 ) * V_82 ;
V_65 = (struct V_175 * ) ( V_132 + 1 ) ;
V_230 = V_182 / sizeof( * V_228 ) ;
if ( V_230 )
V_232 = F_77 ( sizeof( V_228 ) * V_230 ,
V_212 ) ;
if ( ! V_232 )
return;
V_230 = 0 ;
while ( V_182 >= sizeof( * V_65 ) ) {
V_133 = V_65 -> V_90 * V_82 ;
if ( V_133 > V_182 )
goto V_233;
if ( ( V_65 -> V_88 < 32 ) &&
( V_65 -> V_88 != V_121 ) &&
! ( V_183 & 1U << V_65 -> V_88 ) ) {
F_4 ( V_6 , L_16
L_31 ) ;
goto V_233;
}
switch ( V_65 -> V_88 ) {
case V_89 :
V_226 = (struct V_58 * ) V_65 ;
if ( V_133 < sizeof( * V_226 ) )
goto V_233;
if ( F_31 ( V_226 -> V_91 , V_9 -> V_41 ) )
goto V_233;
V_183 &= ~ F_71 ( V_89 ) ;
break;
case V_92 :
V_227 = (struct V_60 * ) V_65 ;
if ( V_133 < sizeof( * V_227 ) )
goto V_233;
if ( F_73 ( & V_227 -> V_93 ) != V_9 -> V_192 )
goto V_233;
V_183 &= ~ F_71 ( V_92 ) ;
break;
case V_121 :
V_228 = (struct V_115 * ) V_65 ;
if ( V_133 < sizeof( * V_228 ) )
goto V_233;
V_232 [ V_230 ++ ] = V_228 ;
V_229 = F_93 ( V_110 ,
F_58 ( V_228 -> V_123 ) ) ;
if ( V_229 && ( V_229 == V_110 ) ) {
F_23 ( & V_6 -> V_21 ) ;
F_63 ( V_110 -> V_168 ,
F_64 () ) -> V_172 ++ ;
F_69 () ;
F_46 ( V_6 ) ;
F_24 ( & V_6 -> V_21 ) ;
}
break;
default:
if ( V_65 -> V_88 < V_203 )
goto V_233;
break;
}
V_65 = (struct V_175 * ) ( ( char * ) V_65 + V_133 ) ;
V_182 -= V_133 ;
}
if ( V_183 )
F_4 ( V_6 , L_32 ,
V_183 ) ;
else if ( ! V_230 ) {
F_4 ( V_6 , L_33 ) ;
F_23 ( & V_110 -> V_234 ) ;
F_29 (vn_port, &lport->vports, list)
F_94 ( V_229 ) ;
F_24 ( & V_110 -> V_234 ) ;
F_23 ( & V_6 -> V_21 ) ;
F_63 ( V_110 -> V_168 ,
F_64 () ) -> V_172 ++ ;
F_69 () ;
F_46 ( V_6 ) ;
F_24 ( & V_6 -> V_21 ) ;
F_94 ( V_6 -> V_7 ) ;
F_35 ( V_6 , NULL ) ;
} else {
int V_235 ;
F_4 ( V_6 , L_34 ) ;
for ( V_235 = 0 ; V_235 < V_230 ; V_235 ++ ) {
V_228 = V_232 [ V_235 ] ;
V_229 = F_93 ( V_110 ,
F_58 ( V_228 -> V_123 ) ) ;
if ( ! V_229 )
continue;
if ( F_31 ( V_6 -> V_122 ( V_229 ) ,
V_228 -> V_91 ) != 0 ||
F_73 ( & V_228 -> V_125 ) !=
V_229 -> V_124 )
continue;
if ( V_229 == V_110 )
V_231 = 1 ;
else
F_94 ( V_229 ) ;
}
if ( V_231 ) {
F_94 ( V_6 -> V_7 ) ;
F_35 ( V_6 , NULL ) ;
}
}
V_233:
F_19 ( V_232 ) ;
}
void F_95 ( struct V_5 * V_6 , struct V_52 * V_53 )
{
F_96 ( & V_6 -> V_31 , V_53 ) ;
F_57 ( & V_6 -> V_29 ) ;
}
static int F_97 ( struct V_5 * V_6 , struct V_52 * V_53 )
{
struct V_57 * V_174 ;
struct V_55 * V_236 ;
enum V_1 V_2 ;
T_1 V_134 ;
T_3 V_218 ;
if ( F_98 ( V_53 ) )
goto V_150;
if ( V_53 -> V_117 < sizeof( * V_174 ) )
goto V_150;
V_236 = F_99 ( V_53 ) ;
if ( V_6 -> V_13 == V_14 ) {
if ( F_31 ( V_236 -> V_69 , V_6 -> V_72 ) &&
F_31 ( V_236 -> V_69 , V_237 ) &&
F_31 ( V_236 -> V_69 , V_238 ) )
goto V_150;
} else if ( F_31 ( V_236 -> V_69 , V_6 -> V_72 ) &&
F_31 ( V_236 -> V_69 , V_239 ) )
goto V_150;
V_174 = (struct V_57 * ) V_53 -> V_68 ;
V_134 = F_56 ( V_174 -> V_77 ) ;
V_218 = V_174 -> V_79 ;
if ( F_100 ( V_174 -> V_75 ) != V_76 )
goto V_150;
if ( F_56 ( V_174 -> V_81 ) * V_82 + sizeof( * V_174 ) > V_53 -> V_117 )
goto V_150;
F_23 ( & V_6 -> V_21 ) ;
V_2 = V_6 -> V_2 ;
if ( V_2 == V_102 ) {
V_6 -> V_18 = 0 ;
F_3 ( V_6 , V_160 ) ;
V_2 = V_160 ;
F_4 ( V_6 , L_35 ) ;
}
F_24 ( & V_6 -> V_21 ) ;
if ( V_6 -> V_13 == V_14 && V_134 == V_240 )
return F_101 ( V_6 , V_53 ) ;
if ( V_2 != V_160 && V_2 != V_156 &&
V_2 != V_241 )
goto V_150;
if ( V_134 == V_137 ) {
F_82 ( V_6 , V_53 ) ;
return 0 ;
}
if ( V_2 != V_160 )
goto V_150;
if ( V_134 == V_78 && V_218 == V_242 )
F_75 ( V_6 , V_53 ) ;
else if ( V_134 == V_119 && V_218 == V_243 )
F_92 ( V_6 , V_174 ) ;
F_28 ( V_53 ) ;
return 0 ;
V_150:
F_28 ( V_53 ) ;
return - 1 ;
}
static struct V_8 * F_102 ( struct V_5 * V_6 )
{
struct V_8 * V_9 ;
struct V_8 * V_244 = V_6 -> V_33 ;
struct V_8 * V_208 ;
V_208 = F_103 ( & V_6 -> V_20 , struct V_8 , V_34 ) ;
F_29 (fcf, &fip->fcfs, list) {
F_4 ( V_6 , L_36
L_37
L_38 ,
V_9 -> V_171 , V_9 -> V_193 , V_9 -> V_41 ,
V_9 -> V_195 , F_5 ( V_9 ) ,
V_9 -> V_40 , V_9 -> V_190 ) ;
if ( V_9 -> V_171 != V_208 -> V_171 ||
V_9 -> V_193 != V_208 -> V_193 ||
V_9 -> V_195 != V_208 -> V_195 ) {
F_4 ( V_6 , L_39
L_40 ) ;
return NULL ;
}
if ( V_9 -> V_40 )
continue;
if ( ! F_6 ( V_9 ) ) {
F_4 ( V_6 , L_41
L_42 ,
V_9 -> V_171 , V_9 -> V_195 ,
( V_9 -> V_10 & V_11 ) ? L_43 : L_44 ,
( V_9 -> V_10 & V_12 ) ?
L_43 : L_45 ) ;
continue;
}
if ( ! V_244 || V_9 -> V_190 < V_244 -> V_190 || V_244 -> V_40 )
V_244 = V_9 ;
}
V_6 -> V_33 = V_244 ;
if ( V_244 ) {
F_4 ( V_6 , L_46 , V_244 -> V_41 ) ;
V_6 -> V_107 = V_100 +
F_62 ( V_164 ) ;
V_6 -> V_106 = V_100 + V_244 -> V_169 ;
if ( F_68 ( V_6 -> V_106 , V_6 -> V_25 . V_213 ) )
F_79 ( & V_6 -> V_25 , V_6 -> V_106 ) ;
}
return V_244 ;
}
static int F_104 ( struct V_5 * V_6 )
{
struct V_52 * V_53 ;
struct V_52 * V_245 ;
struct V_49 * V_132 ;
int error ;
V_245 = V_6 -> V_39 ;
if ( ! V_245 )
return - V_157 ;
V_53 = F_105 ( V_245 , V_212 ) ;
if ( ! V_53 ) {
V_53 = V_245 ;
V_6 -> V_39 = NULL ;
}
V_132 = (struct V_49 * ) V_53 -> V_68 ;
error = F_51 ( V_6 , V_6 -> V_7 , V_142 , V_53 ,
F_58 ( V_132 -> V_158 ) ) ;
if ( error ) {
F_28 ( V_53 ) ;
return error ;
}
V_6 -> V_98 ( V_6 , V_53 ) ;
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
error = - V_246 ;
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
if ( ! V_9 || ! V_6 -> V_151 )
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
V_6 -> V_151 = 0 ;
} else
F_4 ( V_6 , L_51 ) ;
V_42:
F_30 ( & V_6 -> V_22 ) ;
}
static void V_26 ( unsigned long V_247 )
{
struct V_5 * V_6 = (struct V_5 * ) V_247 ;
F_57 ( & V_6 -> V_27 ) ;
}
static void V_28 ( struct V_248 * V_249 )
{
struct V_5 * V_6 ;
struct V_109 * V_250 ;
T_3 * V_59 ;
T_3 V_251 = 0 ;
T_3 V_252 = 0 ;
T_3 V_253 = 0 ;
struct V_8 * V_38 ;
struct V_8 * V_9 ;
unsigned long V_163 ;
V_6 = F_55 ( V_249 , struct V_5 , V_27 ) ;
if ( V_6 -> V_13 == V_14 )
return F_107 ( V_6 ) ;
F_23 ( & V_6 -> V_21 ) ;
if ( V_6 -> V_2 == V_37 ) {
F_24 ( & V_6 -> V_21 ) ;
return;
}
V_9 = V_6 -> V_33 ;
V_163 = F_61 ( V_6 ) ;
V_38 = V_6 -> V_33 ;
if ( ! V_38 && V_6 -> V_36 ) {
if ( F_66 ( V_100 , V_6 -> V_36 ) ) {
V_38 = F_102 ( V_6 ) ;
V_6 -> V_36 = 0 ;
} else if ( F_65 ( V_163 , V_6 -> V_36 ) )
V_163 = V_6 -> V_36 ;
}
if ( V_38 && V_6 -> V_151 )
F_106 ( V_6 ) ;
else if ( ! V_38 && V_9 )
V_251 = 1 ;
if ( V_38 && ! V_38 -> V_197 ) {
if ( F_66 ( V_100 , V_6 -> V_106 ) ) {
V_6 -> V_106 = V_100 + V_38 -> V_169 ;
V_252 = 1 ;
}
if ( F_65 ( V_163 , V_6 -> V_106 ) )
V_163 = V_6 -> V_106 ;
if ( F_66 ( V_100 , V_6 -> V_107 ) ) {
V_6 -> V_107 = V_100 +
F_62 ( V_164 ) ;
V_253 = 1 ;
}
if ( F_65 ( V_163 , V_6 -> V_107 ) )
V_163 = V_6 -> V_107 ;
}
if ( ! F_76 ( & V_6 -> V_20 ) )
F_79 ( & V_6 -> V_25 , V_163 ) ;
F_24 ( & V_6 -> V_21 ) ;
if ( V_251 ) {
F_94 ( V_6 -> V_7 ) ;
F_35 ( V_6 , NULL ) ;
}
if ( V_252 )
F_50 ( V_6 , NULL , 0 , V_6 -> V_72 ) ;
if ( V_253 ) {
F_23 ( & V_6 -> V_7 -> V_234 ) ;
V_59 = V_6 -> V_122 ( V_6 -> V_7 ) ;
F_50 ( V_6 , V_6 -> V_7 , 1 , V_59 ) ;
F_29 (vport, &fip->lp->vports, list) {
V_59 = V_6 -> V_122 ( V_250 ) ;
F_50 ( V_6 , V_250 , 1 , V_59 ) ;
}
F_24 ( & V_6 -> V_7 -> V_234 ) ;
}
}
static void V_30 ( struct V_248 * V_29 )
{
struct V_5 * V_6 ;
struct V_52 * V_53 ;
V_6 = F_55 ( V_29 , struct V_5 , V_29 ) ;
while ( ( V_53 = F_108 ( & V_6 -> V_31 ) ) )
F_97 ( V_6 , V_53 ) ;
}
int F_109 ( struct V_5 * V_6 , struct V_109 * V_110 ,
struct V_144 * V_145 )
{
struct V_49 * V_132 ;
T_3 V_134 ;
T_3 * V_112 ;
V_112 = F_99 ( & V_145 -> V_53 ) -> V_71 ;
V_132 = F_110 ( V_145 ) ;
if ( V_132 -> V_254 != V_255 )
return 0 ;
V_134 = F_111 ( V_145 ) ;
if ( V_134 == V_138 && V_132 -> V_256 == V_257 &&
V_6 -> V_23 == F_56 ( V_132 -> V_148 ) ) {
F_23 ( & V_6 -> V_21 ) ;
if ( V_6 -> V_2 != V_102 && V_6 -> V_2 != V_101 ) {
F_24 ( & V_6 -> V_21 ) ;
return - V_157 ;
}
F_3 ( V_6 , V_101 ) ;
F_4 ( V_6 ,
L_52 ) ;
if ( ! F_31 ( V_112 , ( T_3 [ 6 ] ) V_258 ) ) {
F_7 ( V_6 ) ;
} else {
memcpy ( V_6 -> V_15 , V_112 , V_46 ) ;
V_6 -> V_18 = 0 ;
}
V_6 -> V_23 = V_24 ;
F_24 ( & V_6 -> V_21 ) ;
F_59 ( F_83 ( V_145 ) -> V_219 , V_132 -> V_158 ) ;
} else if ( V_134 == V_147 && V_132 -> V_256 == V_259 && V_112 ) {
F_23 ( & V_6 -> V_21 ) ;
if ( V_6 -> V_2 == V_102 || V_6 -> V_2 == V_101 ) {
memcpy ( V_6 -> V_15 , V_112 , V_46 ) ;
V_6 -> V_18 = 0 ;
if ( V_6 -> V_2 == V_102 )
F_4 ( V_6 , L_53
L_54 ) ;
F_3 ( V_6 , V_101 ) ;
}
F_24 ( & V_6 -> V_21 ) ;
}
return 0 ;
}
T_5 F_112 ( unsigned char V_59 [ V_260 ] ,
unsigned int V_261 , unsigned int V_262 )
{
T_5 V_176 ;
T_5 V_263 ;
V_263 = ( ( T_5 ) V_59 [ 0 ] << 40 ) |
( ( T_5 ) V_59 [ 1 ] << 32 ) |
( ( T_5 ) V_59 [ 2 ] << 24 ) |
( ( T_5 ) V_59 [ 3 ] << 16 ) |
( ( T_5 ) V_59 [ 4 ] << 8 ) |
( T_5 ) V_59 [ 5 ] ;
F_67 ( V_263 >= ( 1ULL << 48 ) ) ;
V_176 = V_263 | ( ( T_5 ) V_261 << 60 ) ;
switch ( V_261 ) {
case 1 :
F_67 ( V_262 != 0 ) ;
break;
case 2 :
F_67 ( V_262 >= 0xfff ) ;
V_176 |= ( T_5 ) V_262 << 48 ;
break;
default:
F_67 ( 1 ) ;
break;
}
return V_176 ;
}
static inline struct V_264 * F_113 ( struct V_265 * V_266 )
{
return (struct V_264 * ) ( V_266 + 1 ) ;
}
static void F_114 ( struct V_5 * V_6 ,
enum V_267 V_218 ,
const T_3 * V_268 , T_4 V_269 )
{
struct V_52 * V_53 ;
struct V_270 {
struct V_55 V_56 ;
struct V_57 V_6 ;
struct V_58 V_59 ;
struct V_60 V_61 ;
struct V_115 V_116 ;
} V_64 * V_271 ;
struct V_272 * V_273 ;
struct V_62 * V_63 ;
T_2 V_274 ;
T_4 V_117 ;
T_4 V_133 ;
V_117 = sizeof( * V_271 ) ;
V_133 = 0 ;
if ( V_218 == V_275 || V_218 == V_276 ) {
V_133 = sizeof( struct V_272 ) +
sizeof( struct V_62 ) ;
V_117 += V_133 ;
}
V_133 += sizeof( V_271 -> V_59 ) + sizeof( V_271 -> V_61 ) + sizeof( V_271 -> V_116 ) ;
V_117 = F_115 ( V_117 , V_269 + sizeof( struct V_55 ) ) ;
V_53 = F_36 ( V_117 ) ;
if ( ! V_53 )
return;
V_271 = (struct V_270 * ) V_53 -> V_68 ;
memset ( V_271 , 0 , V_117 ) ;
memcpy ( V_271 -> V_56 . V_69 , V_268 , V_46 ) ;
memcpy ( V_271 -> V_56 . V_71 , V_6 -> V_72 , V_46 ) ;
V_271 -> V_56 . V_73 = F_37 ( V_74 ) ;
V_271 -> V_6 . V_75 = F_38 ( V_76 ) ;
V_271 -> V_6 . V_77 = F_37 ( V_240 ) ;
V_271 -> V_6 . V_79 = V_218 ;
V_271 -> V_6 . V_81 = F_37 ( V_133 / V_82 ) ;
V_271 -> V_59 . V_87 . V_88 = V_89 ;
V_271 -> V_59 . V_87 . V_90 = sizeof( V_271 -> V_59 ) / V_82 ;
memcpy ( V_271 -> V_59 . V_91 , V_6 -> V_72 , V_46 ) ;
V_271 -> V_61 . V_87 . V_88 = V_92 ;
V_271 -> V_61 . V_87 . V_90 = sizeof( V_271 -> V_61 ) / V_82 ;
F_39 ( V_6 -> V_7 -> V_61 , & V_271 -> V_61 . V_93 ) ;
V_271 -> V_116 . V_87 . V_88 = V_121 ;
V_271 -> V_116 . V_87 . V_90 = sizeof( V_271 -> V_116 ) / V_82 ;
F_8 ( V_271 -> V_116 . V_91 , V_16 ) ;
F_8 ( V_271 -> V_116 . V_91 + 3 , V_6 -> V_118 ) ;
F_8 ( V_271 -> V_116 . V_123 , V_6 -> V_118 ) ;
F_39 ( V_6 -> V_7 -> V_124 , & V_271 -> V_116 . V_125 ) ;
if ( V_218 == V_275 || V_218 == V_276 ) {
V_273 = (struct V_272 * ) ( V_271 + 1 ) ;
V_273 -> V_87 . V_88 = V_277 ;
V_273 -> V_87 . V_90 = sizeof( * V_273 ) / V_82 ;
V_273 -> V_278 = V_6 -> V_7 -> V_279 ;
V_274 = 0 ;
if ( V_6 -> V_7 -> V_280 & V_281 )
V_274 |= V_282 ;
if ( V_6 -> V_7 -> V_280 & V_283 )
V_274 |= V_284 ;
V_274 <<= ( V_285 * 4 ) % 32 ;
V_273 -> V_286 . V_287 [ V_285 * 4 / 32 ] = F_116 ( V_274 ) ;
V_63 = (struct V_62 * ) ( V_273 + 1 ) ;
V_63 -> V_87 . V_88 = V_94 ;
V_63 -> V_87 . V_90 = sizeof( * V_63 ) / V_82 ;
V_63 -> V_95 = F_37 ( F_34 ( V_6 ) ) ;
}
F_40 ( V_53 , V_117 ) ;
V_53 -> V_96 = F_37 ( V_74 ) ;
V_53 -> V_97 = V_6 -> V_97 ;
F_41 ( V_53 ) ;
F_42 ( V_53 ) ;
V_6 -> V_98 ( V_6 , V_53 ) ;
}
static void F_117 ( struct V_109 * V_110 ,
struct V_265 * V_266 ,
enum V_288 V_289 )
{
struct V_5 * V_6 = V_110 -> V_290 . V_291 ;
struct V_264 * V_292 = F_113 ( V_266 ) ;
F_4 ( V_6 , L_55 ,
V_266 -> V_293 . V_118 , V_289 ) ;
F_23 ( & V_6 -> V_21 ) ;
switch ( V_289 ) {
case V_294 :
V_292 -> V_295 = 0 ;
break;
case V_296 :
case V_297 :
case V_298 :
V_292 -> V_295 ++ ;
if ( V_292 -> V_295 > V_299 ) {
F_4 ( V_6 ,
L_56 ,
V_266 -> V_293 . V_118 ) ;
V_110 -> V_300 . V_301 ( V_266 ) ;
}
break;
default:
break;
}
F_24 ( & V_6 -> V_21 ) ;
}
static void F_118 ( struct V_109 * V_110 )
{
F_23 ( & V_110 -> V_290 . V_302 ) ;
V_110 -> V_290 . V_303 = NULL ;
F_24 ( & V_110 -> V_290 . V_302 ) ;
}
static void F_119 ( struct V_109 * V_110 )
{
struct V_5 * V_6 = V_110 -> V_290 . V_291 ;
F_23 ( & V_6 -> V_21 ) ;
F_118 ( V_110 ) ;
F_24 ( & V_6 -> V_21 ) ;
}
static void F_120 ( struct V_109 * V_110 )
{
F_119 ( V_110 ) ;
V_110 -> V_300 . V_304 () ;
F_121 () ;
}
static void F_122 ( struct V_5 * V_6 )
{
unsigned long V_305 ;
T_2 V_118 ;
F_118 ( V_6 -> V_7 ) ;
V_118 = V_6 -> V_118 ;
if ( V_6 -> V_306 )
V_118 = F_123 ( & V_6 -> V_307 ) & 0xffff ;
else if ( ! V_118 )
V_118 = V_6 -> V_7 -> V_124 & 0xffff ;
if ( ! V_118 || V_118 == 0xffff )
V_118 = 1 ;
V_6 -> V_118 = V_118 ;
if ( V_6 -> V_306 < V_308 ) {
V_6 -> V_306 ++ ;
V_305 = F_124 () % V_309 ;
} else
V_305 = V_310 ;
F_79 ( & V_6 -> V_25 , V_100 + F_62 ( V_305 ) ) ;
F_3 ( V_6 , V_311 ) ;
}
static void F_45 ( struct V_5 * V_6 )
{
V_6 -> V_306 = 0 ;
F_125 ( & V_6 -> V_307 , V_6 -> V_7 -> V_124 ) ;
F_122 ( V_6 ) ;
}
static int F_126 ( struct V_5 * V_6 ,
struct V_52 * V_53 ,
struct V_265 * V_266 )
{
struct V_57 * V_174 ;
struct V_175 * V_65 = NULL ;
struct V_58 * V_312 = NULL ;
struct V_60 * V_176 = NULL ;
struct V_115 * V_116 = NULL ;
struct V_62 * V_63 = NULL ;
struct V_264 * V_292 ;
T_4 V_182 ;
T_4 V_133 ;
T_2 V_183 = 0 ;
T_2 V_126 ;
T_3 V_218 ;
memset ( V_266 , 0 , sizeof( * V_266 ) + sizeof( * V_292 ) ) ;
V_292 = F_113 ( V_266 ) ;
V_174 = (struct V_57 * ) V_53 -> V_68 ;
V_292 -> V_10 = F_56 ( V_174 -> V_83 ) ;
V_218 = V_174 -> V_79 ;
switch ( V_218 ) {
case V_313 :
case V_314 :
case V_315 :
V_183 = F_71 ( V_89 ) | F_71 ( V_92 ) |
F_71 ( V_121 ) ;
break;
case V_275 :
case V_276 :
V_183 = F_71 ( V_89 ) | F_71 ( V_92 ) |
F_71 ( V_121 ) | F_71 ( V_277 ) |
F_71 ( V_94 ) ;
break;
default:
F_4 ( V_6 , L_57 , V_218 ) ;
return - V_157 ;
}
V_182 = F_56 ( V_174 -> V_81 ) * 4 ;
if ( V_182 + sizeof( * V_174 ) > V_53 -> V_117 )
return - V_157 ;
V_65 = (struct V_175 * ) ( V_174 + 1 ) ;
while ( V_182 > 0 ) {
V_133 = V_65 -> V_90 * V_82 ;
if ( V_133 < sizeof( * V_65 ) || V_133 > V_182 )
return - V_157 ;
V_126 = V_65 -> V_88 ;
if ( V_126 < 32 ) {
if ( ! ( V_183 & F_71 ( V_126 ) ) ) {
F_4 ( V_6 ,
L_58
L_59
L_60 ,
V_126 , V_218 ) ;
return - V_157 ;
}
V_183 &= ~ F_71 ( V_126 ) ;
}
switch ( V_126 ) {
case V_89 :
if ( V_133 != sizeof( struct V_58 ) )
goto V_189;
V_312 = (struct V_58 * ) V_65 ;
if ( ! F_72 ( V_312 -> V_91 ) ) {
F_4 ( V_6 ,
L_61 ,
V_312 -> V_91 ) ;
return - V_157 ;
}
memcpy ( V_292 -> V_316 , V_312 -> V_91 , V_46 ) ;
break;
case V_92 :
if ( V_133 != sizeof( struct V_60 ) )
goto V_189;
V_176 = (struct V_60 * ) V_65 ;
V_266 -> V_293 . V_317 = F_73 ( & V_176 -> V_93 ) ;
break;
case V_121 :
if ( V_133 != sizeof( struct V_115 ) )
goto V_189;
V_116 = (struct V_115 * ) V_65 ;
memcpy ( V_292 -> V_318 , V_116 -> V_91 , V_46 ) ;
V_266 -> V_293 . V_118 = F_58 ( V_116 -> V_123 ) ;
V_266 -> V_293 . V_319 = F_73 ( & V_116 -> V_125 ) ;
break;
case V_277 :
if ( V_133 != sizeof( struct V_272 ) )
goto V_189;
break;
case V_94 :
if ( V_133 != sizeof( struct V_62 ) )
goto V_189;
V_63 = (struct V_62 * ) V_65 ;
V_292 -> V_320 = F_56 ( V_63 -> V_95 ) ;
break;
default:
F_4 ( V_6 , L_19
L_62 , V_126 ) ;
if ( V_126 < V_203 )
return - V_157 ;
break;
}
V_65 = (struct V_175 * ) ( ( char * ) V_65 + V_133 ) ;
V_182 -= V_133 ;
}
return 0 ;
V_189:
F_4 ( V_6 , L_22 ,
V_126 , V_133 ) ;
return - V_157 ;
}
static void F_127 ( struct V_5 * V_6 )
{
F_114 ( V_6 , V_275 , V_237 , 0 ) ;
V_6 -> V_99 = V_100 ;
}
static void F_128 ( struct V_5 * V_6 ,
struct V_265 * V_266 )
{
struct V_264 * V_292 = F_113 ( V_266 ) ;
if ( V_266 -> V_293 . V_118 != V_6 -> V_118 )
return;
switch ( V_6 -> V_2 ) {
case V_241 :
case V_156 :
F_114 ( V_6 , V_314 ,
V_292 -> V_316 , 0 ) ;
break;
case V_321 :
case V_322 :
if ( V_6 -> V_7 -> V_124 > V_266 -> V_293 . V_319 &&
! ( V_292 -> V_10 & V_323 ) ) {
F_114 ( V_6 , V_314 ,
V_292 -> V_316 , 0 ) ;
break;
}
case V_311 :
F_122 ( V_6 ) ;
break;
default:
break;
}
}
static void F_129 ( struct V_5 * V_6 ,
struct V_265 * V_266 )
{
if ( V_266 -> V_293 . V_118 != V_6 -> V_118 )
return;
switch ( V_6 -> V_2 ) {
case V_311 :
case V_321 :
case V_322 :
case V_241 :
F_122 ( V_6 ) ;
break;
case V_156 :
F_127 ( V_6 ) ;
break;
default:
break;
}
}
static void F_130 ( struct V_5 * V_6 , struct V_265 * V_204 )
{
struct V_109 * V_110 = V_6 -> V_7 ;
struct V_265 * V_266 ;
struct V_324 * V_293 ;
struct V_264 * V_292 ;
T_2 V_118 ;
V_118 = V_204 -> V_293 . V_118 ;
if ( V_118 == V_6 -> V_118 )
return;
F_23 ( & V_110 -> V_290 . V_302 ) ;
V_266 = V_110 -> V_300 . V_325 ( V_110 , V_118 ) ;
if ( ! V_266 ) {
F_24 ( & V_110 -> V_290 . V_302 ) ;
return;
}
V_266 -> V_326 = & V_327 ;
V_266 -> V_328 = V_110 -> V_290 . V_328 ;
V_293 = & V_266 -> V_293 ;
if ( ( V_293 -> V_319 != - 1 && V_293 -> V_319 != V_204 -> V_293 . V_319 ) ||
( V_293 -> V_317 != - 1 && V_293 -> V_317 != V_204 -> V_293 . V_317 ) )
V_110 -> V_300 . V_301 ( V_266 ) ;
V_293 -> V_319 = V_204 -> V_293 . V_319 ;
V_293 -> V_317 = V_204 -> V_293 . V_317 ;
F_24 ( & V_110 -> V_290 . V_302 ) ;
V_292 = F_113 ( V_266 ) ;
F_4 ( V_6 , L_63 ,
V_118 , V_292 -> V_320 ? L_64 : L_65 ) ;
* V_292 = * F_113 ( V_204 ) ;
V_292 -> time = 0 ;
}
static int F_53 ( struct V_5 * V_6 , T_2 V_118 , T_3 * V_59 )
{
struct V_109 * V_110 = V_6 -> V_7 ;
struct V_265 * V_266 ;
struct V_264 * V_292 ;
int V_329 = - 1 ;
F_131 () ;
V_266 = V_110 -> V_300 . V_330 ( V_110 , V_118 ) ;
if ( V_266 ) {
V_292 = F_113 ( V_266 ) ;
memcpy ( V_59 , V_292 -> V_316 , V_46 ) ;
V_329 = 0 ;
}
F_132 () ;
return V_329 ;
}
static void F_133 ( struct V_5 * V_6 ,
struct V_265 * V_204 )
{
struct V_264 * V_292 = F_113 ( V_204 ) ;
if ( V_292 -> V_10 & V_323 ) {
F_114 ( V_6 , V_313 , V_237 , 0 ) ;
return;
}
switch ( V_6 -> V_2 ) {
case V_311 :
case V_321 :
case V_322 :
if ( V_204 -> V_293 . V_118 == V_6 -> V_118 )
F_122 ( V_6 ) ;
break;
case V_241 :
case V_156 :
if ( V_204 -> V_293 . V_118 == V_6 -> V_118 ) {
if ( V_204 -> V_293 . V_319 > V_6 -> V_7 -> V_124 ) {
F_122 ( V_6 ) ;
break;
}
F_127 ( V_6 ) ;
break;
}
F_114 ( V_6 , V_276 , V_292 -> V_316 ,
F_134 ( ( T_2 ) V_292 -> V_320 ,
F_34 ( V_6 ) ) ) ;
F_130 ( V_6 , V_204 ) ;
break;
default:
break;
}
}
static void F_135 ( struct V_5 * V_6 ,
struct V_265 * V_204 )
{
F_4 ( V_6 , L_66 ,
V_204 -> V_293 . V_118 , F_1 ( V_6 -> V_2 ) ) ;
if ( V_6 -> V_2 == V_156 || V_6 -> V_2 == V_241 )
F_130 ( V_6 , V_204 ) ;
}
static void F_136 ( struct V_5 * V_6 ,
struct V_265 * V_204 )
{
struct V_109 * V_110 = V_6 -> V_7 ;
struct V_265 * V_266 ;
struct V_264 * V_292 ;
V_292 = F_113 ( V_204 ) ;
if ( V_292 -> V_10 & V_323 ) {
F_114 ( V_6 , V_313 , V_237 , 0 ) ;
return;
}
F_23 ( & V_110 -> V_290 . V_302 ) ;
V_266 = V_110 -> V_300 . V_330 ( V_110 , V_204 -> V_293 . V_118 ) ;
if ( V_266 )
F_137 ( & V_266 -> V_331 ) ;
F_24 ( & V_110 -> V_290 . V_302 ) ;
if ( V_266 ) {
if ( V_266 -> V_293 . V_317 == V_204 -> V_293 . V_317 &&
V_266 -> V_293 . V_319 == V_204 -> V_293 . V_319 ) {
V_292 = F_113 ( V_266 ) ;
if ( ! V_292 -> time && V_6 -> V_2 == V_156 )
V_110 -> V_300 . V_332 ( V_266 ) ;
V_292 -> time = V_100 ;
}
F_138 ( & V_266 -> V_331 , V_110 -> V_300 . V_333 ) ;
return;
}
if ( V_6 -> V_2 != V_156 )
return;
F_4 ( V_6 , L_67 ,
V_204 -> V_293 . V_118 ) ;
if ( F_65 ( V_100 ,
V_6 -> V_99 + F_62 ( V_334 ) ) )
F_127 ( V_6 ) ;
}
static unsigned long F_139 ( struct V_5 * V_6 )
{
struct V_109 * V_110 = V_6 -> V_7 ;
struct V_265 * V_266 ;
struct V_264 * V_292 ;
unsigned long V_335 ;
unsigned long V_165 ;
V_335 = V_100 + F_62 ( V_336 * 10 ) ;
F_23 ( & V_110 -> V_290 . V_302 ) ;
F_140 (rdata, &lport->disc.rports, peers) {
V_292 = F_113 ( V_266 ) ;
if ( ! V_292 -> time )
continue;
V_165 = V_292 -> time +
F_62 ( V_336 * 25 / 10 ) ;
if ( F_66 ( V_100 , V_165 ) ) {
V_292 -> time = 0 ;
F_4 ( V_6 ,
L_68 ,
V_266 -> V_293 . V_319 , V_266 -> V_293 . V_118 ) ;
V_110 -> V_300 . V_301 ( V_266 ) ;
} else if ( F_68 ( V_165 , V_335 ) )
V_335 = V_165 ;
}
F_24 ( & V_110 -> V_290 . V_302 ) ;
return V_335 ;
}
static int F_101 ( struct V_5 * V_6 , struct V_52 * V_53 )
{
struct V_57 * V_174 ;
enum V_267 V_218 ;
struct {
struct V_265 V_266 ;
struct V_264 V_292 ;
} V_337 ;
int V_338 ;
V_174 = (struct V_57 * ) V_53 -> V_68 ;
V_218 = V_174 -> V_79 ;
V_338 = F_126 ( V_6 , V_53 , & V_337 . V_266 ) ;
if ( V_338 ) {
F_4 ( V_6 , L_69 , V_338 ) ;
goto V_150;
}
F_23 ( & V_6 -> V_21 ) ;
switch ( V_218 ) {
case V_313 :
F_128 ( V_6 , & V_337 . V_266 ) ;
break;
case V_314 :
F_129 ( V_6 , & V_337 . V_266 ) ;
break;
case V_275 :
F_133 ( V_6 , & V_337 . V_266 ) ;
break;
case V_276 :
F_135 ( V_6 , & V_337 . V_266 ) ;
break;
case V_315 :
F_136 ( V_6 , & V_337 . V_266 ) ;
break;
default:
F_4 ( V_6 , L_70 , V_218 ) ;
V_338 = - 1 ;
break;
}
F_24 ( & V_6 -> V_21 ) ;
V_150:
F_28 ( V_53 ) ;
return V_338 ;
}
static void F_141 ( struct V_109 * V_110 , struct V_144 * V_145 )
{
struct V_339 V_340 ;
V_340 . V_341 = V_342 ;
V_340 . V_343 = V_344 ;
V_110 -> V_300 . V_345 ( V_145 , V_139 , & V_340 ) ;
F_142 ( V_145 ) ;
}
static void F_143 ( void (* F_144)( struct V_109 * ,
enum V_346 ) ,
struct V_109 * V_110 )
{
struct V_347 * V_290 = & V_110 -> V_290 ;
struct V_5 * V_6 = V_290 -> V_291 ;
F_23 ( & V_290 -> V_302 ) ;
V_290 -> V_303 = F_144 ;
V_290 -> V_328 = ( V_290 -> V_328 + 2 ) | 1 ;
V_290 -> V_348 = 1 ;
F_57 ( & V_6 -> V_27 ) ;
F_24 ( & V_290 -> V_302 ) ;
}
static void F_145 ( struct V_5 * V_6 )
{
struct V_109 * V_110 = V_6 -> V_7 ;
struct V_347 * V_290 = & V_110 -> V_290 ;
struct V_265 * V_266 ;
struct V_264 * V_292 ;
void (* F_144)( struct V_109 * , enum V_346 );
F_23 ( & V_290 -> V_302 ) ;
F_144 = V_290 -> V_348 ? V_290 -> V_303 : NULL ;
V_290 -> V_348 = 0 ;
F_140 (rdata, &disc->rports, peers) {
V_292 = F_113 ( V_266 ) ;
if ( V_292 -> time )
V_110 -> V_300 . V_332 ( V_266 ) ;
}
F_24 ( & V_290 -> V_302 ) ;
if ( F_144 )
F_144 ( V_110 , V_349 ) ;
}
static void F_107 ( struct V_5 * V_6 )
{
unsigned long V_335 ;
T_3 V_59 [ V_46 ] ;
T_2 V_350 = 0 ;
F_23 ( & V_6 -> V_21 ) ;
switch ( V_6 -> V_2 ) {
case V_311 :
F_3 ( V_6 , V_321 ) ;
F_114 ( V_6 , V_313 , V_237 , 0 ) ;
V_335 = V_100 + F_62 ( V_309 ) ;
break;
case V_321 :
F_3 ( V_6 , V_322 ) ;
F_114 ( V_6 , V_313 , V_237 , 0 ) ;
V_335 = V_100 + F_62 ( V_334 ) ;
break;
case V_322 :
F_3 ( V_6 , V_241 ) ;
V_350 = V_6 -> V_118 ;
F_8 ( V_59 , V_16 ) ;
F_8 ( V_59 + 3 , V_350 ) ;
F_7 ( V_6 ) ;
V_6 -> V_162 ( V_6 -> V_7 , V_59 ) ;
F_127 ( V_6 ) ;
V_335 = V_100 + F_62 ( V_334 ) ;
break;
case V_241 :
V_335 = V_6 -> V_99 + F_62 ( V_334 ) ;
if ( F_66 ( V_100 , V_335 ) ) {
F_3 ( V_6 , V_156 ) ;
F_114 ( V_6 , V_315 ,
V_237 , 0 ) ;
V_335 = V_100 + F_62 ( V_334 ) ;
V_6 -> V_107 = V_335 ;
}
F_145 ( V_6 ) ;
break;
case V_156 :
V_335 = F_139 ( V_6 ) ;
if ( F_66 ( V_100 , V_6 -> V_107 ) ) {
F_114 ( V_6 , V_315 ,
V_237 , 0 ) ;
V_6 -> V_107 = V_100 +
F_62 ( V_336 +
( F_124 () % V_351 ) ) ;
}
if ( F_68 ( V_6 -> V_107 , V_335 ) )
V_335 = V_6 -> V_107 ;
break;
case V_19 :
goto V_42;
default:
F_146 ( 1 , L_71 , V_6 -> V_2 ) ;
goto V_42;
}
F_79 ( & V_6 -> V_25 , V_335 ) ;
V_42:
F_24 ( & V_6 -> V_21 ) ;
if ( V_350 )
F_147 ( V_6 -> V_7 , V_350 ) ;
}
int F_148 ( struct V_109 * V_110 , struct V_5 * V_6 ,
const struct V_352 * V_300 , int V_353 )
{
memcpy ( & V_110 -> V_300 , V_300 , sizeof( * V_300 ) ) ;
if ( V_353 && F_149 ( V_110 ) )
return - V_354 ;
F_150 ( V_110 ) ;
F_151 ( V_110 ) ;
F_152 ( V_110 ) ;
if ( V_6 -> V_13 == V_14 )
V_110 -> V_355 = sizeof( struct V_264 ) ;
F_153 ( V_110 ) ;
if ( V_6 -> V_13 == V_14 ) {
V_110 -> V_135 = 1 ;
V_110 -> V_300 . V_356 = F_141 ;
V_110 -> V_300 . V_357 = F_143 ;
V_110 -> V_300 . V_358 = F_119 ;
V_110 -> V_300 . V_359 = F_120 ;
F_11 ( & V_110 -> V_290 . V_302 ) ;
F_10 ( & V_110 -> V_290 . V_360 ) ;
V_110 -> V_290 . V_291 = V_6 ;
} else {
F_154 ( V_110 ) ;
}
return 0 ;
}
