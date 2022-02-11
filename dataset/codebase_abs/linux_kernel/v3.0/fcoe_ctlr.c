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
F_41 ( V_53 ) ;
F_42 ( V_53 ) ;
V_6 -> V_97 ( V_6 , V_53 ) ;
if ( ! V_9 )
V_6 -> V_98 = V_99 ;
}
void F_43 ( struct V_5 * V_6 )
{
F_23 ( & V_6 -> V_21 ) ;
if ( V_6 -> V_2 == V_100 || V_6 -> V_2 == V_101 ) {
F_24 ( & V_6 -> V_21 ) ;
F_44 ( V_6 -> V_7 ) ;
} else if ( V_6 -> V_2 == V_19 ) {
F_3 ( V_6 , V_6 -> V_13 ) ;
switch ( V_6 -> V_13 ) {
default:
F_4 ( V_6 , L_7 , V_6 -> V_13 ) ;
case V_102 :
F_4 ( V_6 , L_8 , L_9 ) ;
case V_103 :
case V_104 :
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
V_6 -> V_105 = 0 ;
V_6 -> V_106 = 0 ;
V_6 -> V_98 = 0 ;
V_6 -> V_23 = V_24 ;
F_7 ( V_6 ) ;
}
int F_48 ( struct V_5 * V_6 )
{
int V_107 ;
F_4 ( V_6 , L_10 ) ;
F_23 ( & V_6 -> V_21 ) ;
F_46 ( V_6 ) ;
V_107 = V_6 -> V_2 != V_19 ;
F_3 ( V_6 , V_19 ) ;
F_24 ( & V_6 -> V_21 ) ;
if ( V_107 )
F_49 ( V_6 -> V_7 ) ;
return V_107 ;
}
static void F_50 ( struct V_5 * V_6 ,
struct V_108 * V_109 ,
int V_110 , T_3 * V_111 )
{
struct V_52 * V_53 ;
struct V_112 {
struct V_55 V_56 ;
struct V_57 V_6 ;
struct V_58 V_59 ;
} V_64 * V_113 ;
struct V_114 * V_115 ;
T_2 V_116 ;
struct V_108 * V_7 ;
struct V_8 * V_9 ;
V_9 = V_6 -> V_33 ;
V_7 = V_6 -> V_7 ;
if ( ! V_9 || ( V_110 && ! V_7 -> V_117 ) )
return;
V_116 = sizeof( * V_113 ) + V_110 * sizeof( * V_115 ) ;
V_53 = F_36 ( V_116 ) ;
if ( ! V_53 )
return;
V_113 = (struct V_112 * ) V_53 -> V_68 ;
memset ( V_113 , 0 , V_116 ) ;
memcpy ( V_113 -> V_56 . V_69 , V_9 -> V_41 , V_46 ) ;
memcpy ( V_113 -> V_56 . V_71 , V_111 , V_46 ) ;
V_113 -> V_56 . V_73 = F_37 ( V_74 ) ;
V_113 -> V_6 . V_75 = F_38 ( V_76 ) ;
V_113 -> V_6 . V_77 = F_37 ( V_118 ) ;
V_113 -> V_6 . V_79 = V_119 ;
V_113 -> V_6 . V_81 = F_37 ( ( sizeof( V_113 -> V_59 ) +
V_110 * sizeof( * V_115 ) ) / V_82 ) ;
V_113 -> V_6 . V_83 = F_37 ( V_84 ) ;
if ( V_6 -> V_85 )
V_113 -> V_6 . V_83 |= F_37 ( V_86 ) ;
V_113 -> V_59 . V_87 . V_88 = V_89 ;
V_113 -> V_59 . V_87 . V_90 = sizeof( V_113 -> V_59 ) / V_82 ;
memcpy ( V_113 -> V_59 . V_91 , V_6 -> V_72 , V_46 ) ;
if ( V_110 ) {
V_115 = (struct V_114 * ) ( V_113 + 1 ) ;
V_115 -> V_87 . V_88 = V_120 ;
V_115 -> V_87 . V_90 = sizeof( * V_115 ) / V_82 ;
memcpy ( V_115 -> V_91 , V_6 -> V_121 ( V_109 ) , V_46 ) ;
F_8 ( V_115 -> V_122 , V_109 -> V_117 ) ;
F_39 ( V_109 -> V_123 , & V_115 -> V_124 ) ;
}
F_40 ( V_53 , V_116 ) ;
V_53 -> V_96 = F_37 ( V_74 ) ;
F_41 ( V_53 ) ;
F_42 ( V_53 ) ;
V_6 -> V_97 ( V_6 , V_53 ) ;
}
static int F_51 ( struct V_5 * V_6 , struct V_108 * V_109 ,
T_3 V_125 , struct V_52 * V_53 , T_2 V_126 )
{
struct V_127 {
struct V_55 V_56 ;
struct V_57 V_6 ;
struct V_128 V_129 ;
} V_64 * V_130 ;
struct V_49 * V_131 ;
struct V_58 * V_59 ;
struct V_8 * V_9 ;
T_4 V_132 ;
T_1 V_83 ;
T_3 V_133 ;
V_131 = (struct V_49 * ) V_53 -> V_68 ;
V_133 = * ( T_3 * ) ( V_131 + 1 ) ;
V_132 = sizeof( struct V_128 ) + V_53 -> V_116 ;
V_130 = (struct V_127 * ) F_52 ( V_53 , sizeof( * V_130 ) ) ;
memset ( V_130 , 0 , sizeof( * V_130 ) ) ;
if ( V_109 -> V_134 ) {
if ( F_53 ( V_6 , V_126 , V_130 -> V_56 . V_69 ) )
return - V_135 ;
V_83 = 0 ;
} else {
V_9 = V_6 -> V_33 ;
if ( ! V_9 )
return - V_135 ;
V_83 = V_9 -> V_10 ;
V_83 &= V_6 -> V_85 ? V_86 | V_84 :
V_84 ;
if ( ! V_83 )
return - V_135 ;
memcpy ( V_130 -> V_56 . V_69 , V_9 -> V_41 , V_46 ) ;
}
memcpy ( V_130 -> V_56 . V_71 , V_6 -> V_72 , V_46 ) ;
V_130 -> V_56 . V_73 = F_37 ( V_74 ) ;
V_130 -> V_6 . V_75 = F_38 ( V_76 ) ;
V_130 -> V_6 . V_77 = F_37 ( V_136 ) ;
if ( V_133 == V_137 || V_133 == V_138 )
V_130 -> V_6 . V_79 = V_139 ;
else
V_130 -> V_6 . V_79 = V_140 ;
V_130 -> V_6 . V_83 = F_37 ( V_83 ) ;
V_130 -> V_129 . V_87 . V_88 = V_125 ;
V_130 -> V_129 . V_87 . V_90 = V_132 / V_82 ;
if ( V_133 != V_138 ) {
V_132 += sizeof( * V_59 ) ;
V_59 = (struct V_58 * ) F_40 ( V_53 , sizeof( * V_59 ) ) ;
memset ( V_59 , 0 , sizeof( * V_59 ) ) ;
V_59 -> V_87 . V_88 = V_89 ;
V_59 -> V_87 . V_90 = sizeof( * V_59 ) / V_82 ;
if ( V_125 != V_141 && V_125 != V_142 ) {
memcpy ( V_59 -> V_91 , V_6 -> V_121 ( V_109 ) , V_46 ) ;
} else if ( V_6 -> V_13 == V_14 ) {
F_8 ( V_59 -> V_91 , V_16 ) ;
F_8 ( V_59 -> V_91 + 3 , V_6 -> V_117 ) ;
} else if ( V_83 & V_86 ) {
F_4 ( V_6 , L_11 ) ;
memcpy ( V_59 -> V_91 , V_6 -> V_72 , V_46 ) ;
} else {
F_4 ( V_6 , L_12 ) ;
}
}
V_130 -> V_6 . V_81 = F_37 ( V_132 / V_82 ) ;
V_53 -> V_96 = F_37 ( V_74 ) ;
F_41 ( V_53 ) ;
F_42 ( V_53 ) ;
return 0 ;
}
int F_54 ( struct V_5 * V_6 , struct V_108 * V_109 ,
struct V_52 * V_53 )
{
struct V_143 * V_144 ;
struct V_49 * V_131 ;
T_1 V_145 ;
T_3 V_133 ;
T_3 V_59 [ V_46 ] ;
V_144 = F_55 ( V_53 , struct V_143 , V_53 ) ;
V_131 = (struct V_49 * ) V_53 -> V_68 ;
V_133 = * ( T_3 * ) ( V_131 + 1 ) ;
if ( V_133 == V_146 && V_6 -> V_13 != V_14 ) {
V_145 = V_6 -> V_23 ;
V_6 -> V_23 = F_56 ( V_131 -> V_147 ) ;
if ( V_6 -> V_2 == V_101 ) {
if ( V_145 == V_24 )
V_6 -> V_148 = 0 ;
V_6 -> V_148 ++ ;
if ( V_6 -> V_148 < 3 )
goto V_149;
F_7 ( V_6 ) ;
return 0 ;
}
if ( V_6 -> V_2 == V_100 )
F_7 ( V_6 ) ;
}
if ( V_6 -> V_2 == V_100 )
return 0 ;
if ( ! V_6 -> V_33 && V_6 -> V_13 != V_14 )
goto V_149;
switch ( V_133 ) {
case V_146 :
V_133 = V_141 ;
if ( V_6 -> V_13 == V_14 )
break;
F_27 ( & V_6 -> V_22 ) ;
F_28 ( V_6 -> V_39 ) ;
V_6 -> V_39 = V_53 ;
V_6 -> V_150 = 1 ;
F_30 ( & V_6 -> V_22 ) ;
F_57 ( & V_6 -> V_27 ) ;
return - V_151 ;
case V_152 :
if ( F_58 ( V_131 -> V_153 ) )
return 0 ;
V_133 = V_142 ;
break;
case V_154 :
if ( V_6 -> V_13 == V_14 ) {
if ( V_6 -> V_2 != V_155 )
return - V_156 ;
if ( F_58 ( V_131 -> V_157 ) == V_158 )
return - V_156 ;
} else {
if ( V_6 -> V_2 != V_159 )
return 0 ;
if ( F_58 ( V_131 -> V_157 ) != V_158 )
return 0 ;
}
V_133 = V_160 ;
break;
case V_137 :
if ( V_6 -> V_2 == V_100 ) {
if ( V_6 -> V_23 == V_24 )
return 0 ;
V_6 -> V_23 = V_24 ;
F_59 ( V_59 , V_131 -> V_157 ) ;
V_6 -> V_161 ( V_109 , V_59 ) ;
}
case V_138 :
V_133 = F_60 ( V_144 ) ;
if ( V_133 )
break;
return 0 ;
default:
if ( V_6 -> V_2 != V_159 &&
V_6 -> V_2 != V_155 )
goto V_149;
return 0 ;
}
F_4 ( V_6 , L_13 ,
V_133 , F_58 ( V_131 -> V_157 ) ) ;
if ( F_51 ( V_6 , V_109 , V_133 , V_53 , F_58 ( V_131 -> V_157 ) ) )
goto V_149;
V_6 -> V_97 ( V_6 , V_53 ) ;
return - V_151 ;
V_149:
F_28 ( V_53 ) ;
return - V_156 ;
}
static unsigned long F_61 ( struct V_5 * V_6 )
{
struct V_8 * V_9 ;
struct V_8 * V_32 ;
unsigned long V_162 = V_99 + F_62 ( V_163 ) ;
unsigned long V_164 ;
unsigned long V_36 = 0 ;
struct V_165 * V_166 ;
V_166 = F_63 ( V_6 -> V_7 -> V_167 , F_64 () ) ;
F_17 (fcf, next, &fip->fcfs, list) {
V_164 = V_9 -> time + V_9 -> V_168 + V_9 -> V_168 / 2 ;
if ( V_6 -> V_33 == V_9 ) {
if ( F_65 ( V_99 , V_164 ) ) {
V_166 -> V_169 ++ ;
F_33 ( V_47 L_3
L_14
L_15 ,
V_6 -> V_7 -> V_44 -> V_45 , V_9 -> V_170 ,
V_166 -> V_169 ) ;
} else if ( F_65 ( V_162 , V_164 ) )
V_162 = V_164 ;
}
V_164 += V_9 -> V_168 ;
if ( F_66 ( V_99 , V_164 ) ) {
if ( V_6 -> V_33 == V_9 )
V_6 -> V_33 = NULL ;
F_18 ( & V_9 -> V_34 ) ;
F_67 ( ! V_6 -> V_35 ) ;
V_6 -> V_35 -- ;
F_19 ( V_9 ) ;
V_166 -> V_171 ++ ;
} else {
if ( F_65 ( V_162 , V_164 ) )
V_162 = V_164 ;
if ( F_5 ( V_9 ) &&
( ! V_36 || F_68 ( V_36 , V_9 -> time ) ) )
V_36 = V_9 -> time ;
}
}
F_69 () ;
if ( V_36 && ! V_6 -> V_33 && ! V_6 -> V_36 ) {
V_36 += F_62 ( V_172 ) ;
V_6 -> V_36 = V_36 ;
}
return V_162 ;
}
static int F_70 ( struct V_5 * V_6 ,
struct V_52 * V_53 , struct V_8 * V_9 )
{
struct V_57 * V_173 ;
struct V_174 * V_65 = NULL ;
struct V_60 * V_175 ;
struct V_176 * V_177 ;
struct V_178 * V_179 ;
unsigned long V_180 ;
T_4 V_181 ;
T_4 V_132 ;
T_2 V_182 ;
memset ( V_9 , 0 , sizeof( * V_9 ) ) ;
V_9 -> V_168 = F_62 ( V_183 ) ;
V_173 = (struct V_57 * ) V_53 -> V_68 ;
V_9 -> V_10 = F_56 ( V_173 -> V_83 ) ;
V_182 = F_71 ( V_184 ) | F_71 ( V_89 ) | F_71 ( V_92 ) |
F_71 ( V_185 ) | F_71 ( V_186 ) ;
V_181 = F_56 ( V_173 -> V_81 ) * 4 ;
if ( V_181 + sizeof( * V_173 ) > V_53 -> V_116 )
return - V_156 ;
V_65 = (struct V_174 * ) ( V_173 + 1 ) ;
while ( V_181 > 0 ) {
V_132 = V_65 -> V_90 * V_82 ;
if ( V_132 < sizeof( * V_65 ) || V_132 > V_181 )
return - V_156 ;
if ( ( V_65 -> V_88 < 32 ) &&
! ( V_182 & 1U << V_65 -> V_88 ) ) {
F_4 ( V_6 , L_16
L_17 ) ;
return - V_156 ;
}
switch ( V_65 -> V_88 ) {
case V_184 :
if ( V_132 != sizeof( struct V_187 ) )
goto V_188;
V_9 -> V_189 = ( (struct V_187 * ) V_65 ) -> V_190 ;
V_182 &= ~ F_71 ( V_184 ) ;
break;
case V_89 :
if ( V_132 != sizeof( struct V_58 ) )
goto V_188;
memcpy ( V_9 -> V_41 ,
( (struct V_58 * ) V_65 ) -> V_91 ,
V_46 ) ;
if ( ! F_72 ( V_9 -> V_41 ) ) {
F_4 ( V_6 ,
L_18 ,
V_9 -> V_41 ) ;
return - V_156 ;
}
V_182 &= ~ F_71 ( V_89 ) ;
break;
case V_92 :
if ( V_132 != sizeof( struct V_60 ) )
goto V_188;
V_175 = (struct V_60 * ) V_65 ;
V_9 -> V_191 = F_73 ( & V_175 -> V_93 ) ;
V_182 &= ~ F_71 ( V_92 ) ;
break;
case V_185 :
if ( V_132 != sizeof( struct V_176 ) )
goto V_188;
V_177 = (struct V_176 * ) V_65 ;
V_9 -> V_170 = F_73 ( & V_177 -> V_93 ) ;
V_9 -> V_192 = F_56 ( V_177 -> V_193 ) ;
V_9 -> V_194 = F_58 ( V_177 -> V_195 ) ;
V_182 &= ~ F_71 ( V_185 ) ;
break;
case V_186 :
if ( V_132 != sizeof( struct V_178 ) )
goto V_188;
V_179 = (struct V_178 * ) V_65 ;
if ( V_179 -> V_196 & V_197 )
V_9 -> V_196 = 1 ;
V_180 = F_74 ( V_179 -> V_198 ) ;
if ( V_180 >= V_199 )
V_9 -> V_168 = F_62 ( V_180 ) ;
V_182 &= ~ F_71 ( V_186 ) ;
break;
case V_200 :
case V_94 :
case V_141 :
case V_142 :
case V_160 :
case V_201 :
default:
F_4 ( V_6 , L_19
L_20 , V_65 -> V_88 ) ;
if ( V_65 -> V_88 < V_202 )
return - V_156 ;
break;
}
V_65 = (struct V_174 * ) ( ( char * ) V_65 + V_132 ) ;
V_181 -= V_132 ;
}
if ( ! V_9 -> V_194 || ( V_9 -> V_194 & 0x10000 ) )
return - V_156 ;
if ( ! V_9 -> V_191 )
return - V_156 ;
if ( V_182 ) {
F_4 ( V_6 , L_21 ,
V_182 ) ;
return - V_156 ;
}
return 0 ;
V_188:
F_4 ( V_6 , L_22 ,
V_65 -> V_88 , V_132 ) ;
return - V_156 ;
}
static void F_75 ( struct V_5 * V_6 , struct V_52 * V_53 )
{
struct V_8 * V_9 ;
struct V_8 V_203 ;
struct V_8 * V_204 ;
unsigned long V_205 = F_62 ( V_206 ) ;
int V_207 = 0 ;
int V_208 ;
if ( F_70 ( V_6 , V_53 , & V_203 ) )
return;
F_23 ( & V_6 -> V_21 ) ;
V_207 = F_76 ( & V_6 -> V_20 ) ;
V_204 = NULL ;
F_29 (fcf, &fip->fcfs, list) {
if ( V_9 -> V_191 == V_203 . V_191 &&
V_9 -> V_170 == V_203 . V_170 &&
V_9 -> V_194 == V_203 . V_194 &&
F_31 ( V_9 -> V_41 , V_203 . V_41 ) == 0 ) {
V_204 = V_9 ;
break;
}
}
if ( ! V_204 ) {
if ( V_6 -> V_35 >= V_209 )
goto V_210;
V_9 = F_77 ( sizeof( * V_9 ) , V_211 ) ;
if ( ! V_9 )
goto V_210;
V_6 -> V_35 ++ ;
memcpy ( V_9 , & V_203 , sizeof( V_203 ) ) ;
F_78 ( & V_9 -> V_34 , & V_6 -> V_20 ) ;
} else {
V_9 -> V_196 = V_203 . V_196 ;
if ( ! F_6 ( V_9 ) )
V_9 -> V_10 = V_203 . V_10 ;
if ( V_9 == V_6 -> V_33 && ! V_9 -> V_196 ) {
V_6 -> V_105 -= V_9 -> V_168 ;
V_6 -> V_105 += V_203 . V_168 ;
if ( F_68 ( V_6 -> V_105 , V_6 -> V_25 . V_212 ) )
F_79 ( & V_6 -> V_25 , V_6 -> V_105 ) ;
}
V_9 -> V_168 = V_203 . V_168 ;
memcpy ( V_9 -> V_41 , V_203 . V_41 , V_46 ) ;
}
V_208 = F_5 ( V_9 ) ;
V_9 -> time = V_99 ;
if ( ! V_204 )
F_4 ( V_6 , L_23 ,
V_9 -> V_170 , V_9 -> V_41 ) ;
if ( ! V_208 )
F_35 ( V_6 , V_9 ) ;
if ( V_207 && F_65 ( V_99 , V_6 -> V_98 + V_205 ) )
F_35 ( V_6 , NULL ) ;
if ( V_208 )
F_80 ( & V_9 -> V_34 , & V_6 -> V_20 ) ;
if ( V_208 && ! V_6 -> V_33 && F_6 ( V_9 ) ) {
V_6 -> V_36 = V_99 +
F_62 ( V_172 ) ;
if ( ! F_81 ( & V_6 -> V_25 ) ||
F_68 ( V_6 -> V_36 , V_6 -> V_25 . V_212 ) )
F_79 ( & V_6 -> V_25 , V_6 -> V_36 ) ;
}
V_210:
F_24 ( & V_6 -> V_21 ) ;
}
static void F_82 ( struct V_5 * V_6 , struct V_52 * V_53 )
{
struct V_108 * V_109 = V_6 -> V_7 ;
struct V_57 * V_173 ;
struct V_143 * V_144 = (struct V_143 * ) V_53 ;
struct V_49 * V_131 = NULL ;
struct V_174 * V_65 ;
struct V_128 * V_213 ;
struct V_165 * V_166 ;
enum V_214 V_215 = 0 ;
T_3 V_216 ;
T_3 V_217 ;
T_3 V_218 [ V_46 ] = { 0 } ;
T_4 V_219 = 0 ;
T_4 V_181 ;
T_4 V_132 ;
T_2 V_182 = 0 ;
T_2 V_220 = 0 ;
V_173 = (struct V_57 * ) V_53 -> V_68 ;
V_217 = V_173 -> V_79 ;
if ( V_217 != V_140 && V_217 != V_139 )
goto V_149;
V_181 = F_56 ( V_173 -> V_81 ) * 4 ;
if ( V_181 + sizeof( * V_173 ) > V_53 -> V_116 )
goto V_149;
V_65 = (struct V_174 * ) ( V_173 + 1 ) ;
while ( V_181 > 0 ) {
V_220 ++ ;
V_132 = V_65 -> V_90 * V_82 ;
if ( V_132 < sizeof( * V_65 ) || V_132 > V_181 )
goto V_149;
if ( V_65 -> V_88 < 32 ) {
if ( V_182 & 1U << V_65 -> V_88 ) {
F_4 ( V_6 , L_16
L_24 ) ;
goto V_149;
}
V_182 |= ( 1 << V_65 -> V_88 ) ;
}
switch ( V_65 -> V_88 ) {
case V_89 :
if ( V_220 == 1 ) {
F_4 ( V_6 , L_25
L_26 ) ;
goto V_149;
}
if ( V_132 != sizeof( struct V_58 ) )
goto V_188;
memcpy ( V_218 ,
( (struct V_58 * ) V_65 ) -> V_91 ,
V_46 ) ;
break;
case V_141 :
case V_142 :
case V_160 :
case V_201 :
if ( V_220 != 1 ) {
F_4 ( V_6 , L_25
L_26 ) ;
goto V_149;
}
if ( V_131 )
goto V_149;
if ( V_132 < sizeof( * V_213 ) + sizeof( * V_131 ) + 1 )
goto V_188;
V_219 = V_132 - sizeof( * V_213 ) ;
V_213 = (struct V_128 * ) V_65 ;
V_131 = (struct V_49 * ) ( V_213 + 1 ) ;
V_215 = V_65 -> V_88 ;
break;
default:
F_4 ( V_6 , L_19
L_20 , V_65 -> V_88 ) ;
if ( V_65 -> V_88 < V_202 )
goto V_149;
if ( V_220 <= 2 ) {
F_4 ( V_6 , L_25
L_26 ) ;
goto V_149;
}
break;
}
V_65 = (struct V_174 * ) ( ( char * ) V_65 + V_132 ) ;
V_181 -= V_132 ;
}
if ( ! V_131 )
goto V_149;
V_216 = * ( T_3 * ) ( V_131 + 1 ) ;
if ( ( V_215 == V_141 || V_215 == V_142 ) &&
V_217 == V_139 && V_6 -> V_13 != V_14 ) {
if ( V_216 == V_137 ) {
if ( ! F_72 ( V_218 ) ) {
F_4 ( V_6 ,
L_27 ,
V_218 ) ;
goto V_149;
}
memcpy ( F_83 ( V_144 ) -> V_218 , V_218 , V_46 ) ;
if ( V_6 -> V_23 == F_56 ( V_131 -> V_147 ) ) {
V_6 -> V_23 = V_24 ;
if ( V_215 == V_141 )
F_26 ( V_6 ) ;
}
} else if ( V_215 == V_141 &&
! F_84 ( V_6 ) )
goto V_149;
}
if ( ( V_220 == 0 ) || ( ( V_216 != V_138 ) &&
( ! ( 1U << V_89 & V_182 ) ) ) ) {
F_4 ( V_6 , L_28
L_29 ) ;
goto V_149;
}
F_85 ( V_53 , ( T_3 * ) V_131 - V_53 -> V_68 ) ;
F_86 ( V_53 , V_219 ) ;
V_144 = (struct V_143 * ) V_53 ;
F_87 ( V_144 ) ;
F_88 ( V_144 ) = V_221 ;
F_89 ( V_144 ) = V_222 ;
F_90 ( V_144 ) = V_109 ;
F_60 ( V_144 ) = V_215 ;
V_166 = F_63 ( V_109 -> V_167 , F_64 () ) ;
V_166 -> V_223 ++ ;
V_166 -> V_224 += V_53 -> V_116 / V_82 ;
F_69 () ;
F_91 ( V_109 , V_144 ) ;
return;
V_188:
F_4 ( V_6 , L_22 ,
V_65 -> V_88 , V_132 ) ;
V_149:
F_28 ( V_53 ) ;
}
static void F_92 ( struct V_5 * V_6 ,
struct V_57 * V_131 )
{
struct V_174 * V_65 ;
struct V_58 * V_225 ;
struct V_60 * V_226 ;
struct V_114 * V_227 ;
T_4 V_181 ;
T_4 V_132 ;
struct V_8 * V_9 = V_6 -> V_33 ;
struct V_108 * V_109 = V_6 -> V_7 ;
struct V_108 * V_228 = NULL ;
T_2 V_182 ;
int V_229 ;
int V_230 = 0 ;
struct V_114 * * V_231 = NULL ;
F_4 ( V_6 , L_30 ) ;
if ( ! V_9 || ! V_109 -> V_117 )
return;
V_182 = F_71 ( V_89 ) | F_71 ( V_92 ) ;
V_181 = F_56 ( V_131 -> V_81 ) * V_82 ;
V_65 = (struct V_174 * ) ( V_131 + 1 ) ;
V_229 = V_181 / sizeof( * V_227 ) ;
if ( V_229 )
V_231 = F_77 ( sizeof( V_227 ) * V_229 ,
V_211 ) ;
if ( ! V_231 )
return;
V_229 = 0 ;
while ( V_181 >= sizeof( * V_65 ) ) {
V_132 = V_65 -> V_90 * V_82 ;
if ( V_132 > V_181 )
goto V_232;
if ( ( V_65 -> V_88 < 32 ) &&
( V_65 -> V_88 != V_120 ) &&
! ( V_182 & 1U << V_65 -> V_88 ) ) {
F_4 ( V_6 , L_16
L_31 ) ;
goto V_232;
}
switch ( V_65 -> V_88 ) {
case V_89 :
V_225 = (struct V_58 * ) V_65 ;
if ( V_132 < sizeof( * V_225 ) )
goto V_232;
if ( F_31 ( V_225 -> V_91 , V_9 -> V_41 ) )
goto V_232;
V_182 &= ~ F_71 ( V_89 ) ;
break;
case V_92 :
V_226 = (struct V_60 * ) V_65 ;
if ( V_132 < sizeof( * V_226 ) )
goto V_232;
if ( F_73 ( & V_226 -> V_93 ) != V_9 -> V_191 )
goto V_232;
V_182 &= ~ F_71 ( V_92 ) ;
break;
case V_120 :
V_227 = (struct V_114 * ) V_65 ;
if ( V_132 < sizeof( * V_227 ) )
goto V_232;
V_231 [ V_229 ++ ] = V_227 ;
V_228 = F_93 ( V_109 ,
F_58 ( V_227 -> V_122 ) ) ;
if ( V_228 && ( V_228 == V_109 ) ) {
F_23 ( & V_6 -> V_21 ) ;
F_63 ( V_109 -> V_167 ,
F_64 () ) -> V_171 ++ ;
F_69 () ;
F_46 ( V_6 ) ;
F_24 ( & V_6 -> V_21 ) ;
}
break;
default:
if ( V_65 -> V_88 < V_202 )
goto V_232;
break;
}
V_65 = (struct V_174 * ) ( ( char * ) V_65 + V_132 ) ;
V_181 -= V_132 ;
}
if ( V_182 )
F_4 ( V_6 , L_32 ,
V_182 ) ;
else if ( ! V_229 ) {
F_4 ( V_6 , L_33 ) ;
F_23 ( & V_109 -> V_233 ) ;
F_29 (vn_port, &lport->vports, list)
F_94 ( V_228 ) ;
F_24 ( & V_109 -> V_233 ) ;
F_23 ( & V_6 -> V_21 ) ;
F_63 ( V_109 -> V_167 ,
F_64 () ) -> V_171 ++ ;
F_69 () ;
F_46 ( V_6 ) ;
F_24 ( & V_6 -> V_21 ) ;
F_94 ( V_6 -> V_7 ) ;
F_35 ( V_6 , NULL ) ;
} else {
int V_234 ;
F_4 ( V_6 , L_34 ) ;
for ( V_234 = 0 ; V_234 < V_229 ; V_234 ++ ) {
V_227 = V_231 [ V_234 ] ;
V_228 = F_93 ( V_109 ,
F_58 ( V_227 -> V_122 ) ) ;
if ( ! V_228 )
continue;
if ( F_31 ( V_6 -> V_121 ( V_228 ) ,
V_227 -> V_91 ) != 0 ||
F_73 ( & V_227 -> V_124 ) !=
V_228 -> V_123 )
continue;
if ( V_228 == V_109 )
V_230 = 1 ;
else
F_94 ( V_228 ) ;
}
if ( V_230 ) {
F_94 ( V_6 -> V_7 ) ;
F_35 ( V_6 , NULL ) ;
}
}
V_232:
F_19 ( V_231 ) ;
}
void F_95 ( struct V_5 * V_6 , struct V_52 * V_53 )
{
F_96 ( & V_6 -> V_31 , V_53 ) ;
F_57 ( & V_6 -> V_29 ) ;
}
static int F_97 ( struct V_5 * V_6 , struct V_52 * V_53 )
{
struct V_57 * V_173 ;
struct V_55 * V_235 ;
enum V_1 V_2 ;
T_1 V_133 ;
T_3 V_217 ;
if ( F_98 ( V_53 ) )
goto V_149;
if ( V_53 -> V_116 < sizeof( * V_173 ) )
goto V_149;
V_235 = F_99 ( V_53 ) ;
if ( V_6 -> V_13 == V_14 ) {
if ( F_31 ( V_235 -> V_69 , V_6 -> V_72 ) &&
F_31 ( V_235 -> V_69 , V_236 ) &&
F_31 ( V_235 -> V_69 , V_237 ) )
goto V_149;
} else if ( F_31 ( V_235 -> V_69 , V_6 -> V_72 ) &&
F_31 ( V_235 -> V_69 , V_238 ) )
goto V_149;
V_173 = (struct V_57 * ) V_53 -> V_68 ;
V_133 = F_56 ( V_173 -> V_77 ) ;
V_217 = V_173 -> V_79 ;
if ( F_100 ( V_173 -> V_75 ) != V_76 )
goto V_149;
if ( F_56 ( V_173 -> V_81 ) * V_82 + sizeof( * V_173 ) > V_53 -> V_116 )
goto V_149;
F_23 ( & V_6 -> V_21 ) ;
V_2 = V_6 -> V_2 ;
if ( V_2 == V_101 ) {
V_6 -> V_18 = 0 ;
F_3 ( V_6 , V_159 ) ;
V_2 = V_159 ;
F_4 ( V_6 , L_35 ) ;
}
F_24 ( & V_6 -> V_21 ) ;
if ( V_6 -> V_13 == V_14 && V_133 == V_239 )
return F_101 ( V_6 , V_53 ) ;
if ( V_2 != V_159 && V_2 != V_155 &&
V_2 != V_240 )
goto V_149;
if ( V_133 == V_136 ) {
F_82 ( V_6 , V_53 ) ;
return 0 ;
}
if ( V_2 != V_159 )
goto V_149;
if ( V_133 == V_78 && V_217 == V_241 )
F_75 ( V_6 , V_53 ) ;
else if ( V_133 == V_118 && V_217 == V_242 )
F_92 ( V_6 , V_173 ) ;
F_28 ( V_53 ) ;
return 0 ;
V_149:
F_28 ( V_53 ) ;
return - 1 ;
}
static struct V_8 * F_102 ( struct V_5 * V_6 )
{
struct V_8 * V_9 ;
struct V_8 * V_243 = V_6 -> V_33 ;
struct V_8 * V_207 ;
V_207 = F_103 ( & V_6 -> V_20 , struct V_8 , V_34 ) ;
F_29 (fcf, &fip->fcfs, list) {
F_4 ( V_6 , L_36
L_37
L_38 ,
V_9 -> V_170 , V_9 -> V_192 , V_9 -> V_41 ,
V_9 -> V_194 , F_5 ( V_9 ) ,
V_9 -> V_40 , V_9 -> V_189 ) ;
if ( V_9 -> V_170 != V_207 -> V_170 ||
V_9 -> V_192 != V_207 -> V_192 ||
V_9 -> V_194 != V_207 -> V_194 ) {
F_4 ( V_6 , L_39
L_40 ) ;
return NULL ;
}
if ( V_9 -> V_40 )
continue;
if ( ! F_6 ( V_9 ) ) {
F_4 ( V_6 , L_41
L_42 ,
V_9 -> V_170 , V_9 -> V_194 ,
( V_9 -> V_10 & V_11 ) ? L_43 : L_44 ,
( V_9 -> V_10 & V_12 ) ?
L_43 : L_45 ) ;
continue;
}
if ( ! V_243 || V_9 -> V_189 < V_243 -> V_189 || V_243 -> V_40 )
V_243 = V_9 ;
}
V_6 -> V_33 = V_243 ;
if ( V_243 ) {
F_4 ( V_6 , L_46 , V_243 -> V_41 ) ;
V_6 -> V_106 = V_99 +
F_62 ( V_163 ) ;
V_6 -> V_105 = V_99 + V_243 -> V_168 ;
if ( F_68 ( V_6 -> V_105 , V_6 -> V_25 . V_212 ) )
F_79 ( & V_6 -> V_25 , V_6 -> V_105 ) ;
}
return V_243 ;
}
static int F_104 ( struct V_5 * V_6 )
{
struct V_52 * V_53 ;
struct V_52 * V_244 ;
struct V_49 * V_131 ;
int error ;
V_244 = V_6 -> V_39 ;
if ( ! V_244 )
return - V_156 ;
V_53 = F_105 ( V_244 , V_211 ) ;
if ( ! V_53 ) {
V_53 = V_244 ;
V_6 -> V_39 = NULL ;
}
V_131 = (struct V_49 * ) V_53 -> V_68 ;
error = F_51 ( V_6 , V_6 -> V_7 , V_141 , V_53 ,
F_58 ( V_131 -> V_157 ) ) ;
if ( error ) {
F_28 ( V_53 ) ;
return error ;
}
V_6 -> V_97 ( V_6 , V_53 ) ;
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
error = - V_245 ;
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
if ( ! V_9 || ! V_6 -> V_150 )
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
V_6 -> V_150 = 0 ;
} else
F_4 ( V_6 , L_51 ) ;
V_42:
F_30 ( & V_6 -> V_22 ) ;
}
static void V_26 ( unsigned long V_246 )
{
struct V_5 * V_6 = (struct V_5 * ) V_246 ;
F_57 ( & V_6 -> V_27 ) ;
}
static void V_28 ( struct V_247 * V_248 )
{
struct V_5 * V_6 ;
struct V_108 * V_249 ;
T_3 * V_59 ;
T_3 V_250 = 0 ;
T_3 V_251 = 0 ;
T_3 V_252 = 0 ;
struct V_8 * V_38 ;
struct V_8 * V_9 ;
unsigned long V_162 ;
V_6 = F_55 ( V_248 , struct V_5 , V_27 ) ;
if ( V_6 -> V_13 == V_14 )
return F_107 ( V_6 ) ;
F_23 ( & V_6 -> V_21 ) ;
if ( V_6 -> V_2 == V_37 ) {
F_24 ( & V_6 -> V_21 ) ;
return;
}
V_9 = V_6 -> V_33 ;
V_162 = F_61 ( V_6 ) ;
V_38 = V_6 -> V_33 ;
if ( ! V_38 && V_6 -> V_36 ) {
if ( F_66 ( V_99 , V_6 -> V_36 ) ) {
V_38 = F_102 ( V_6 ) ;
V_6 -> V_36 = 0 ;
} else if ( F_65 ( V_162 , V_6 -> V_36 ) )
V_162 = V_6 -> V_36 ;
}
if ( V_38 && V_6 -> V_150 )
F_106 ( V_6 ) ;
else if ( ! V_38 && V_9 )
V_250 = 1 ;
if ( V_38 && ! V_38 -> V_196 ) {
if ( F_66 ( V_99 , V_6 -> V_105 ) ) {
V_6 -> V_105 = V_99 + V_38 -> V_168 ;
V_251 = 1 ;
}
if ( F_65 ( V_162 , V_6 -> V_105 ) )
V_162 = V_6 -> V_105 ;
if ( F_66 ( V_99 , V_6 -> V_106 ) ) {
V_6 -> V_106 = V_99 +
F_62 ( V_163 ) ;
V_252 = 1 ;
}
if ( F_65 ( V_162 , V_6 -> V_106 ) )
V_162 = V_6 -> V_106 ;
}
if ( ! F_76 ( & V_6 -> V_20 ) )
F_79 ( & V_6 -> V_25 , V_162 ) ;
F_24 ( & V_6 -> V_21 ) ;
if ( V_250 ) {
F_94 ( V_6 -> V_7 ) ;
F_35 ( V_6 , NULL ) ;
}
if ( V_251 )
F_50 ( V_6 , NULL , 0 , V_6 -> V_72 ) ;
if ( V_252 ) {
F_23 ( & V_6 -> V_7 -> V_233 ) ;
V_59 = V_6 -> V_121 ( V_6 -> V_7 ) ;
F_50 ( V_6 , V_6 -> V_7 , 1 , V_59 ) ;
F_29 (vport, &fip->lp->vports, list) {
V_59 = V_6 -> V_121 ( V_249 ) ;
F_50 ( V_6 , V_249 , 1 , V_59 ) ;
}
F_24 ( & V_6 -> V_7 -> V_233 ) ;
}
}
static void V_30 ( struct V_247 * V_29 )
{
struct V_5 * V_6 ;
struct V_52 * V_53 ;
V_6 = F_55 ( V_29 , struct V_5 , V_29 ) ;
while ( ( V_53 = F_108 ( & V_6 -> V_31 ) ) )
F_97 ( V_6 , V_53 ) ;
}
int F_109 ( struct V_5 * V_6 , struct V_108 * V_109 ,
struct V_143 * V_144 )
{
struct V_49 * V_131 ;
T_3 V_133 ;
T_3 * V_111 ;
V_111 = F_99 ( & V_144 -> V_53 ) -> V_71 ;
V_131 = F_110 ( V_144 ) ;
if ( V_131 -> V_253 != V_254 )
return 0 ;
V_133 = F_111 ( V_144 ) ;
if ( V_133 == V_137 && V_131 -> V_255 == V_256 &&
V_6 -> V_23 == F_56 ( V_131 -> V_147 ) ) {
F_23 ( & V_6 -> V_21 ) ;
if ( V_6 -> V_2 != V_101 && V_6 -> V_2 != V_100 ) {
F_24 ( & V_6 -> V_21 ) ;
return - V_156 ;
}
F_3 ( V_6 , V_100 ) ;
F_4 ( V_6 ,
L_52 ) ;
if ( ! F_31 ( V_111 , ( T_3 [ 6 ] ) V_257 ) ) {
F_7 ( V_6 ) ;
} else {
memcpy ( V_6 -> V_15 , V_111 , V_46 ) ;
V_6 -> V_18 = 0 ;
}
V_6 -> V_23 = V_24 ;
F_24 ( & V_6 -> V_21 ) ;
F_59 ( F_83 ( V_144 ) -> V_218 , V_131 -> V_157 ) ;
} else if ( V_133 == V_146 && V_131 -> V_255 == V_258 && V_111 ) {
F_23 ( & V_6 -> V_21 ) ;
if ( V_6 -> V_2 == V_101 || V_6 -> V_2 == V_100 ) {
memcpy ( V_6 -> V_15 , V_111 , V_46 ) ;
V_6 -> V_18 = 0 ;
if ( V_6 -> V_2 == V_101 )
F_4 ( V_6 , L_53
L_54 ) ;
F_3 ( V_6 , V_100 ) ;
}
F_24 ( & V_6 -> V_21 ) ;
}
return 0 ;
}
T_5 F_112 ( unsigned char V_59 [ V_259 ] ,
unsigned int V_260 , unsigned int V_261 )
{
T_5 V_175 ;
T_5 V_262 ;
V_262 = ( ( T_5 ) V_59 [ 0 ] << 40 ) |
( ( T_5 ) V_59 [ 1 ] << 32 ) |
( ( T_5 ) V_59 [ 2 ] << 24 ) |
( ( T_5 ) V_59 [ 3 ] << 16 ) |
( ( T_5 ) V_59 [ 4 ] << 8 ) |
( T_5 ) V_59 [ 5 ] ;
F_67 ( V_262 >= ( 1ULL << 48 ) ) ;
V_175 = V_262 | ( ( T_5 ) V_260 << 60 ) ;
switch ( V_260 ) {
case 1 :
F_67 ( V_261 != 0 ) ;
break;
case 2 :
F_67 ( V_261 >= 0xfff ) ;
V_175 |= ( T_5 ) V_261 << 48 ;
break;
default:
F_67 ( 1 ) ;
break;
}
return V_175 ;
}
static inline struct V_263 * F_113 ( struct V_264 * V_265 )
{
return (struct V_263 * ) ( V_265 + 1 ) ;
}
static void F_114 ( struct V_5 * V_6 ,
enum V_266 V_217 ,
const T_3 * V_267 , T_4 V_268 )
{
struct V_52 * V_53 ;
struct V_269 {
struct V_55 V_56 ;
struct V_57 V_6 ;
struct V_58 V_59 ;
struct V_60 V_61 ;
struct V_114 V_115 ;
} V_64 * V_270 ;
struct V_271 * V_272 ;
struct V_62 * V_63 ;
T_2 V_273 ;
T_4 V_116 ;
T_4 V_132 ;
V_116 = sizeof( * V_270 ) ;
V_132 = 0 ;
if ( V_217 == V_274 || V_217 == V_275 ) {
V_132 = sizeof( struct V_271 ) +
sizeof( struct V_62 ) ;
V_116 += V_132 ;
}
V_132 += sizeof( V_270 -> V_59 ) + sizeof( V_270 -> V_61 ) + sizeof( V_270 -> V_115 ) ;
V_116 = F_115 ( V_116 , V_268 + sizeof( struct V_55 ) ) ;
V_53 = F_36 ( V_116 ) ;
if ( ! V_53 )
return;
V_270 = (struct V_269 * ) V_53 -> V_68 ;
memset ( V_270 , 0 , V_116 ) ;
memcpy ( V_270 -> V_56 . V_69 , V_267 , V_46 ) ;
memcpy ( V_270 -> V_56 . V_71 , V_6 -> V_72 , V_46 ) ;
V_270 -> V_56 . V_73 = F_37 ( V_74 ) ;
V_270 -> V_6 . V_75 = F_38 ( V_76 ) ;
V_270 -> V_6 . V_77 = F_37 ( V_239 ) ;
V_270 -> V_6 . V_79 = V_217 ;
V_270 -> V_6 . V_81 = F_37 ( V_132 / V_82 ) ;
V_270 -> V_59 . V_87 . V_88 = V_89 ;
V_270 -> V_59 . V_87 . V_90 = sizeof( V_270 -> V_59 ) / V_82 ;
memcpy ( V_270 -> V_59 . V_91 , V_6 -> V_72 , V_46 ) ;
V_270 -> V_61 . V_87 . V_88 = V_92 ;
V_270 -> V_61 . V_87 . V_90 = sizeof( V_270 -> V_61 ) / V_82 ;
F_39 ( V_6 -> V_7 -> V_61 , & V_270 -> V_61 . V_93 ) ;
V_270 -> V_115 . V_87 . V_88 = V_120 ;
V_270 -> V_115 . V_87 . V_90 = sizeof( V_270 -> V_115 ) / V_82 ;
F_8 ( V_270 -> V_115 . V_91 , V_16 ) ;
F_8 ( V_270 -> V_115 . V_91 + 3 , V_6 -> V_117 ) ;
F_8 ( V_270 -> V_115 . V_122 , V_6 -> V_117 ) ;
F_39 ( V_6 -> V_7 -> V_123 , & V_270 -> V_115 . V_124 ) ;
if ( V_217 == V_274 || V_217 == V_275 ) {
V_272 = (struct V_271 * ) ( V_270 + 1 ) ;
V_272 -> V_87 . V_88 = V_276 ;
V_272 -> V_87 . V_90 = sizeof( * V_272 ) / V_82 ;
V_272 -> V_277 = V_6 -> V_7 -> V_278 ;
V_273 = 0 ;
if ( V_6 -> V_7 -> V_279 & V_280 )
V_273 |= V_281 ;
if ( V_6 -> V_7 -> V_279 & V_282 )
V_273 |= V_283 ;
V_273 <<= ( V_284 * 4 ) % 32 ;
V_272 -> V_285 . V_286 [ V_284 * 4 / 32 ] = F_116 ( V_273 ) ;
V_63 = (struct V_62 * ) ( V_272 + 1 ) ;
V_63 -> V_87 . V_88 = V_94 ;
V_63 -> V_87 . V_90 = sizeof( * V_63 ) / V_82 ;
V_63 -> V_95 = F_37 ( F_34 ( V_6 ) ) ;
}
F_40 ( V_53 , V_116 ) ;
V_53 -> V_96 = F_37 ( V_74 ) ;
F_41 ( V_53 ) ;
F_42 ( V_53 ) ;
V_6 -> V_97 ( V_6 , V_53 ) ;
}
static void F_117 ( struct V_108 * V_109 ,
struct V_264 * V_265 ,
enum V_287 V_288 )
{
struct V_5 * V_6 = V_109 -> V_289 . V_290 ;
struct V_263 * V_291 = F_113 ( V_265 ) ;
F_4 ( V_6 , L_55 ,
V_265 -> V_292 . V_117 , V_288 ) ;
F_23 ( & V_6 -> V_21 ) ;
switch ( V_288 ) {
case V_293 :
V_291 -> V_294 = 0 ;
break;
case V_295 :
case V_296 :
case V_297 :
V_291 -> V_294 ++ ;
if ( V_291 -> V_294 > V_298 ) {
F_4 ( V_6 ,
L_56 ,
V_265 -> V_292 . V_117 ) ;
V_109 -> V_299 . V_300 ( V_265 ) ;
}
break;
default:
break;
}
F_24 ( & V_6 -> V_21 ) ;
}
static void F_118 ( struct V_108 * V_109 )
{
F_23 ( & V_109 -> V_289 . V_301 ) ;
V_109 -> V_289 . V_302 = NULL ;
F_24 ( & V_109 -> V_289 . V_301 ) ;
}
static void F_119 ( struct V_108 * V_109 )
{
struct V_5 * V_6 = V_109 -> V_289 . V_290 ;
F_23 ( & V_6 -> V_21 ) ;
F_118 ( V_109 ) ;
F_24 ( & V_6 -> V_21 ) ;
}
static void F_120 ( struct V_108 * V_109 )
{
F_119 ( V_109 ) ;
V_109 -> V_299 . V_303 () ;
F_121 () ;
}
static void F_122 ( struct V_5 * V_6 )
{
unsigned long V_304 ;
T_2 V_117 ;
F_118 ( V_6 -> V_7 ) ;
V_117 = V_6 -> V_117 ;
if ( V_6 -> V_305 )
V_117 = F_123 ( & V_6 -> V_306 ) & 0xffff ;
else if ( ! V_117 )
V_117 = V_6 -> V_7 -> V_123 & 0xffff ;
if ( ! V_117 || V_117 == 0xffff )
V_117 = 1 ;
V_6 -> V_117 = V_117 ;
if ( V_6 -> V_305 < V_307 ) {
V_6 -> V_305 ++ ;
V_304 = F_124 () % V_308 ;
} else
V_304 = V_309 ;
F_79 ( & V_6 -> V_25 , V_99 + F_62 ( V_304 ) ) ;
F_3 ( V_6 , V_310 ) ;
}
static void F_45 ( struct V_5 * V_6 )
{
V_6 -> V_305 = 0 ;
F_125 ( & V_6 -> V_306 , V_6 -> V_7 -> V_123 ) ;
F_122 ( V_6 ) ;
}
static int F_126 ( struct V_5 * V_6 ,
struct V_52 * V_53 ,
struct V_264 * V_265 )
{
struct V_57 * V_173 ;
struct V_174 * V_65 = NULL ;
struct V_58 * V_311 = NULL ;
struct V_60 * V_175 = NULL ;
struct V_114 * V_115 = NULL ;
struct V_62 * V_63 = NULL ;
struct V_263 * V_291 ;
T_4 V_181 ;
T_4 V_132 ;
T_2 V_182 = 0 ;
T_2 V_125 ;
T_3 V_217 ;
memset ( V_265 , 0 , sizeof( * V_265 ) + sizeof( * V_291 ) ) ;
V_291 = F_113 ( V_265 ) ;
V_173 = (struct V_57 * ) V_53 -> V_68 ;
V_291 -> V_10 = F_56 ( V_173 -> V_83 ) ;
V_217 = V_173 -> V_79 ;
switch ( V_217 ) {
case V_312 :
case V_313 :
case V_314 :
V_182 = F_71 ( V_89 ) | F_71 ( V_92 ) |
F_71 ( V_120 ) ;
break;
case V_274 :
case V_275 :
V_182 = F_71 ( V_89 ) | F_71 ( V_92 ) |
F_71 ( V_120 ) | F_71 ( V_276 ) |
F_71 ( V_94 ) ;
break;
default:
F_4 ( V_6 , L_57 , V_217 ) ;
return - V_156 ;
}
V_181 = F_56 ( V_173 -> V_81 ) * 4 ;
if ( V_181 + sizeof( * V_173 ) > V_53 -> V_116 )
return - V_156 ;
V_65 = (struct V_174 * ) ( V_173 + 1 ) ;
while ( V_181 > 0 ) {
V_132 = V_65 -> V_90 * V_82 ;
if ( V_132 < sizeof( * V_65 ) || V_132 > V_181 )
return - V_156 ;
V_125 = V_65 -> V_88 ;
if ( V_125 < 32 ) {
if ( ! ( V_182 & F_71 ( V_125 ) ) ) {
F_4 ( V_6 ,
L_58
L_59
L_60 ,
V_125 , V_217 ) ;
return - V_156 ;
}
V_182 &= ~ F_71 ( V_125 ) ;
}
switch ( V_125 ) {
case V_89 :
if ( V_132 != sizeof( struct V_58 ) )
goto V_188;
V_311 = (struct V_58 * ) V_65 ;
if ( ! F_72 ( V_311 -> V_91 ) ) {
F_4 ( V_6 ,
L_61 ,
V_311 -> V_91 ) ;
return - V_156 ;
}
memcpy ( V_291 -> V_315 , V_311 -> V_91 , V_46 ) ;
break;
case V_92 :
if ( V_132 != sizeof( struct V_60 ) )
goto V_188;
V_175 = (struct V_60 * ) V_65 ;
V_265 -> V_292 . V_316 = F_73 ( & V_175 -> V_93 ) ;
break;
case V_120 :
if ( V_132 != sizeof( struct V_114 ) )
goto V_188;
V_115 = (struct V_114 * ) V_65 ;
memcpy ( V_291 -> V_317 , V_115 -> V_91 , V_46 ) ;
V_265 -> V_292 . V_117 = F_58 ( V_115 -> V_122 ) ;
V_265 -> V_292 . V_318 = F_73 ( & V_115 -> V_124 ) ;
break;
case V_276 :
if ( V_132 != sizeof( struct V_271 ) )
goto V_188;
break;
case V_94 :
if ( V_132 != sizeof( struct V_62 ) )
goto V_188;
V_63 = (struct V_62 * ) V_65 ;
V_291 -> V_319 = F_56 ( V_63 -> V_95 ) ;
break;
default:
F_4 ( V_6 , L_19
L_62 , V_125 ) ;
if ( V_125 < V_202 )
return - V_156 ;
break;
}
V_65 = (struct V_174 * ) ( ( char * ) V_65 + V_132 ) ;
V_181 -= V_132 ;
}
return 0 ;
V_188:
F_4 ( V_6 , L_22 ,
V_125 , V_132 ) ;
return - V_156 ;
}
static void F_127 ( struct V_5 * V_6 )
{
F_114 ( V_6 , V_274 , V_236 , 0 ) ;
V_6 -> V_98 = V_99 ;
}
static void F_128 ( struct V_5 * V_6 ,
struct V_264 * V_265 )
{
struct V_263 * V_291 = F_113 ( V_265 ) ;
if ( V_265 -> V_292 . V_117 != V_6 -> V_117 )
return;
switch ( V_6 -> V_2 ) {
case V_240 :
case V_155 :
F_114 ( V_6 , V_313 ,
V_291 -> V_315 , 0 ) ;
break;
case V_320 :
case V_321 :
if ( V_6 -> V_7 -> V_123 > V_265 -> V_292 . V_318 &&
! ( V_291 -> V_10 & V_322 ) ) {
F_114 ( V_6 , V_313 ,
V_291 -> V_315 , 0 ) ;
break;
}
case V_310 :
F_122 ( V_6 ) ;
break;
default:
break;
}
}
static void F_129 ( struct V_5 * V_6 ,
struct V_264 * V_265 )
{
if ( V_265 -> V_292 . V_117 != V_6 -> V_117 )
return;
switch ( V_6 -> V_2 ) {
case V_310 :
case V_320 :
case V_321 :
case V_240 :
F_122 ( V_6 ) ;
break;
case V_155 :
F_127 ( V_6 ) ;
break;
default:
break;
}
}
static void F_130 ( struct V_5 * V_6 , struct V_264 * V_203 )
{
struct V_108 * V_109 = V_6 -> V_7 ;
struct V_264 * V_265 ;
struct V_323 * V_292 ;
struct V_263 * V_291 ;
T_2 V_117 ;
V_117 = V_203 -> V_292 . V_117 ;
if ( V_117 == V_6 -> V_117 )
return;
F_23 ( & V_109 -> V_289 . V_301 ) ;
V_265 = V_109 -> V_299 . V_324 ( V_109 , V_117 ) ;
if ( ! V_265 ) {
F_24 ( & V_109 -> V_289 . V_301 ) ;
return;
}
V_265 -> V_325 = & V_326 ;
V_265 -> V_327 = V_109 -> V_289 . V_327 ;
V_292 = & V_265 -> V_292 ;
if ( ( V_292 -> V_318 != - 1 && V_292 -> V_318 != V_203 -> V_292 . V_318 ) ||
( V_292 -> V_316 != - 1 && V_292 -> V_316 != V_203 -> V_292 . V_316 ) )
V_109 -> V_299 . V_300 ( V_265 ) ;
V_292 -> V_318 = V_203 -> V_292 . V_318 ;
V_292 -> V_316 = V_203 -> V_292 . V_316 ;
F_24 ( & V_109 -> V_289 . V_301 ) ;
V_291 = F_113 ( V_265 ) ;
F_4 ( V_6 , L_63 ,
V_117 , V_291 -> V_319 ? L_64 : L_65 ) ;
* V_291 = * F_113 ( V_203 ) ;
V_291 -> time = 0 ;
}
static int F_53 ( struct V_5 * V_6 , T_2 V_117 , T_3 * V_59 )
{
struct V_108 * V_109 = V_6 -> V_7 ;
struct V_264 * V_265 ;
struct V_263 * V_291 ;
int V_328 = - 1 ;
F_131 () ;
V_265 = V_109 -> V_299 . V_329 ( V_109 , V_117 ) ;
if ( V_265 ) {
V_291 = F_113 ( V_265 ) ;
memcpy ( V_59 , V_291 -> V_315 , V_46 ) ;
V_328 = 0 ;
}
F_132 () ;
return V_328 ;
}
static void F_133 ( struct V_5 * V_6 ,
struct V_264 * V_203 )
{
struct V_263 * V_291 = F_113 ( V_203 ) ;
if ( V_291 -> V_10 & V_322 ) {
F_114 ( V_6 , V_312 , V_236 , 0 ) ;
return;
}
switch ( V_6 -> V_2 ) {
case V_310 :
case V_320 :
case V_321 :
if ( V_203 -> V_292 . V_117 == V_6 -> V_117 )
F_122 ( V_6 ) ;
break;
case V_240 :
case V_155 :
if ( V_203 -> V_292 . V_117 == V_6 -> V_117 ) {
if ( V_203 -> V_292 . V_318 > V_6 -> V_7 -> V_123 ) {
F_122 ( V_6 ) ;
break;
}
F_127 ( V_6 ) ;
break;
}
F_114 ( V_6 , V_275 , V_291 -> V_315 ,
F_134 ( ( T_2 ) V_291 -> V_319 ,
F_34 ( V_6 ) ) ) ;
F_130 ( V_6 , V_203 ) ;
break;
default:
break;
}
}
static void F_135 ( struct V_5 * V_6 ,
struct V_264 * V_203 )
{
F_4 ( V_6 , L_66 ,
V_203 -> V_292 . V_117 , F_1 ( V_6 -> V_2 ) ) ;
if ( V_6 -> V_2 == V_155 || V_6 -> V_2 == V_240 )
F_130 ( V_6 , V_203 ) ;
}
static void F_136 ( struct V_5 * V_6 ,
struct V_264 * V_203 )
{
struct V_108 * V_109 = V_6 -> V_7 ;
struct V_264 * V_265 ;
struct V_263 * V_291 ;
V_291 = F_113 ( V_203 ) ;
if ( V_291 -> V_10 & V_322 ) {
F_114 ( V_6 , V_312 , V_236 , 0 ) ;
return;
}
F_23 ( & V_109 -> V_289 . V_301 ) ;
V_265 = V_109 -> V_299 . V_329 ( V_109 , V_203 -> V_292 . V_117 ) ;
if ( V_265 )
F_137 ( & V_265 -> V_330 ) ;
F_24 ( & V_109 -> V_289 . V_301 ) ;
if ( V_265 ) {
if ( V_265 -> V_292 . V_316 == V_203 -> V_292 . V_316 &&
V_265 -> V_292 . V_318 == V_203 -> V_292 . V_318 ) {
V_291 = F_113 ( V_265 ) ;
if ( ! V_291 -> time && V_6 -> V_2 == V_155 )
V_109 -> V_299 . V_331 ( V_265 ) ;
V_291 -> time = V_99 ;
}
F_138 ( & V_265 -> V_330 , V_109 -> V_299 . V_332 ) ;
return;
}
if ( V_6 -> V_2 != V_155 )
return;
F_4 ( V_6 , L_67 ,
V_203 -> V_292 . V_117 ) ;
if ( F_65 ( V_99 ,
V_6 -> V_98 + F_62 ( V_333 ) ) )
F_127 ( V_6 ) ;
}
static unsigned long F_139 ( struct V_5 * V_6 )
{
struct V_108 * V_109 = V_6 -> V_7 ;
struct V_264 * V_265 ;
struct V_263 * V_291 ;
unsigned long V_334 ;
unsigned long V_164 ;
V_334 = V_99 + F_62 ( V_335 * 10 ) ;
F_23 ( & V_109 -> V_289 . V_301 ) ;
F_140 (rdata, &lport->disc.rports, peers) {
V_291 = F_113 ( V_265 ) ;
if ( ! V_291 -> time )
continue;
V_164 = V_291 -> time +
F_62 ( V_335 * 25 / 10 ) ;
if ( F_66 ( V_99 , V_164 ) ) {
V_291 -> time = 0 ;
F_4 ( V_6 ,
L_68 ,
V_265 -> V_292 . V_318 , V_265 -> V_292 . V_117 ) ;
V_109 -> V_299 . V_300 ( V_265 ) ;
} else if ( F_68 ( V_164 , V_334 ) )
V_334 = V_164 ;
}
F_24 ( & V_109 -> V_289 . V_301 ) ;
return V_334 ;
}
static int F_101 ( struct V_5 * V_6 , struct V_52 * V_53 )
{
struct V_57 * V_173 ;
enum V_266 V_217 ;
struct {
struct V_264 V_265 ;
struct V_263 V_291 ;
} V_336 ;
int V_337 ;
V_173 = (struct V_57 * ) V_53 -> V_68 ;
V_217 = V_173 -> V_79 ;
V_337 = F_126 ( V_6 , V_53 , & V_336 . V_265 ) ;
if ( V_337 ) {
F_4 ( V_6 , L_69 , V_337 ) ;
goto V_149;
}
F_23 ( & V_6 -> V_21 ) ;
switch ( V_217 ) {
case V_312 :
F_128 ( V_6 , & V_336 . V_265 ) ;
break;
case V_313 :
F_129 ( V_6 , & V_336 . V_265 ) ;
break;
case V_274 :
F_133 ( V_6 , & V_336 . V_265 ) ;
break;
case V_275 :
F_135 ( V_6 , & V_336 . V_265 ) ;
break;
case V_314 :
F_136 ( V_6 , & V_336 . V_265 ) ;
break;
default:
F_4 ( V_6 , L_70 , V_217 ) ;
V_337 = - 1 ;
break;
}
F_24 ( & V_6 -> V_21 ) ;
V_149:
F_28 ( V_53 ) ;
return V_337 ;
}
static void F_141 ( struct V_108 * V_109 , struct V_143 * V_144 )
{
struct V_338 V_339 ;
V_339 . V_340 = V_341 ;
V_339 . V_342 = V_343 ;
V_109 -> V_299 . V_344 ( V_144 , V_138 , & V_339 ) ;
F_142 ( V_144 ) ;
}
static void F_143 ( void (* F_144)( struct V_108 * ,
enum V_345 ) ,
struct V_108 * V_109 )
{
struct V_346 * V_289 = & V_109 -> V_289 ;
struct V_5 * V_6 = V_289 -> V_290 ;
F_23 ( & V_289 -> V_301 ) ;
V_289 -> V_302 = F_144 ;
V_289 -> V_327 = ( V_289 -> V_327 + 2 ) | 1 ;
V_289 -> V_347 = 1 ;
F_57 ( & V_6 -> V_27 ) ;
F_24 ( & V_289 -> V_301 ) ;
}
static void F_145 ( struct V_5 * V_6 )
{
struct V_108 * V_109 = V_6 -> V_7 ;
struct V_346 * V_289 = & V_109 -> V_289 ;
struct V_264 * V_265 ;
struct V_263 * V_291 ;
void (* F_144)( struct V_108 * , enum V_345 );
F_23 ( & V_289 -> V_301 ) ;
F_144 = V_289 -> V_347 ? V_289 -> V_302 : NULL ;
V_289 -> V_347 = 0 ;
F_140 (rdata, &disc->rports, peers) {
V_291 = F_113 ( V_265 ) ;
if ( V_291 -> time )
V_109 -> V_299 . V_331 ( V_265 ) ;
}
F_24 ( & V_289 -> V_301 ) ;
if ( F_144 )
F_144 ( V_109 , V_348 ) ;
}
static void F_107 ( struct V_5 * V_6 )
{
unsigned long V_334 ;
T_3 V_59 [ V_46 ] ;
T_2 V_349 = 0 ;
F_23 ( & V_6 -> V_21 ) ;
switch ( V_6 -> V_2 ) {
case V_310 :
F_3 ( V_6 , V_320 ) ;
F_114 ( V_6 , V_312 , V_236 , 0 ) ;
V_334 = V_99 + F_62 ( V_308 ) ;
break;
case V_320 :
F_3 ( V_6 , V_321 ) ;
F_114 ( V_6 , V_312 , V_236 , 0 ) ;
V_334 = V_99 + F_62 ( V_333 ) ;
break;
case V_321 :
F_3 ( V_6 , V_240 ) ;
V_349 = V_6 -> V_117 ;
F_8 ( V_59 , V_16 ) ;
F_8 ( V_59 + 3 , V_349 ) ;
F_7 ( V_6 ) ;
V_6 -> V_161 ( V_6 -> V_7 , V_59 ) ;
F_127 ( V_6 ) ;
V_334 = V_99 + F_62 ( V_333 ) ;
break;
case V_240 :
V_334 = V_6 -> V_98 + F_62 ( V_333 ) ;
if ( F_66 ( V_99 , V_334 ) ) {
F_3 ( V_6 , V_155 ) ;
F_114 ( V_6 , V_314 ,
V_236 , 0 ) ;
V_334 = V_99 + F_62 ( V_333 ) ;
V_6 -> V_106 = V_334 ;
}
F_145 ( V_6 ) ;
break;
case V_155 :
V_334 = F_139 ( V_6 ) ;
if ( F_66 ( V_99 , V_6 -> V_106 ) ) {
F_114 ( V_6 , V_314 ,
V_236 , 0 ) ;
V_6 -> V_106 = V_99 +
F_62 ( V_335 +
( F_124 () % V_350 ) ) ;
}
if ( F_68 ( V_6 -> V_106 , V_334 ) )
V_334 = V_6 -> V_106 ;
break;
case V_19 :
goto V_42;
default:
F_146 ( 1 , L_71 , V_6 -> V_2 ) ;
goto V_42;
}
F_79 ( & V_6 -> V_25 , V_334 ) ;
V_42:
F_24 ( & V_6 -> V_21 ) ;
if ( V_349 )
F_147 ( V_6 -> V_7 , V_349 ) ;
}
int F_148 ( struct V_108 * V_109 , struct V_5 * V_6 ,
const struct V_351 * V_299 , int V_352 )
{
memcpy ( & V_109 -> V_299 , V_299 , sizeof( * V_299 ) ) ;
if ( V_352 && F_149 ( V_109 ) )
return - V_353 ;
F_150 ( V_109 ) ;
F_151 ( V_109 ) ;
F_152 ( V_109 ) ;
if ( V_6 -> V_13 == V_14 )
V_109 -> V_354 = sizeof( struct V_263 ) ;
F_153 ( V_109 ) ;
if ( V_6 -> V_13 == V_14 ) {
V_109 -> V_134 = 1 ;
V_109 -> V_299 . V_355 = F_141 ;
V_109 -> V_299 . V_356 = F_143 ;
V_109 -> V_299 . V_357 = F_119 ;
V_109 -> V_299 . V_358 = F_120 ;
F_11 ( & V_109 -> V_289 . V_301 ) ;
F_10 ( & V_109 -> V_289 . V_359 ) ;
V_109 -> V_289 . V_290 = V_6 ;
} else {
F_154 ( V_109 ) ;
}
return 0 ;
}
