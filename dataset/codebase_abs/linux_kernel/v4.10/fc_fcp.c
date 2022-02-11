static struct V_1 * F_1 ( struct V_2 * V_3 , T_1 V_4 )
{
struct V_5 * V_6 = F_2 ( V_3 ) ;
struct V_1 * V_7 ;
V_7 = F_3 ( V_6 -> V_8 , V_4 ) ;
if ( V_7 ) {
memset ( V_7 , 0 , sizeof( * V_7 ) ) ;
V_7 -> V_9 = V_3 ;
V_7 -> V_10 = V_11 ;
F_4 ( & V_7 -> V_12 , 1 ) ;
F_5 ( & V_7 -> V_13 ) ;
V_7 -> V_13 . V_14 = ( unsigned long ) V_7 ;
F_6 ( & V_7 -> V_15 ) ;
F_7 ( & V_7 -> V_16 ) ;
} else {
F_8 ( V_3 -> V_17 , F_9 () ) -> V_18 ++ ;
F_10 () ;
}
return V_7 ;
}
static void F_11 ( struct V_1 * V_7 )
{
if ( F_12 ( & V_7 -> V_12 ) ) {
struct V_5 * V_6 = F_2 ( V_7 -> V_9 ) ;
F_13 ( V_7 , V_6 -> V_8 ) ;
}
}
static void F_14 ( struct V_1 * V_7 )
{
F_15 ( & V_7 -> V_12 ) ;
}
static void F_16 ( struct V_19 * V_20 , void * V_7 )
{
F_11 ( V_7 ) ;
}
static inline int F_17 ( struct V_1 * V_7 )
{
F_18 ( & V_7 -> V_16 ) ;
if ( V_7 -> V_21 & V_22 ) {
F_19 ( & V_7 -> V_16 ) ;
return - V_23 ;
}
F_14 ( V_7 ) ;
return 0 ;
}
static inline void F_20 ( struct V_1 * V_7 )
{
F_19 ( & V_7 -> V_16 ) ;
F_11 ( V_7 ) ;
}
static void F_21 ( struct V_1 * V_7 , unsigned long V_24 )
{
if ( ! ( V_7 -> V_21 & V_22 ) ) {
F_22 ( & V_7 -> V_13 , V_25 + V_24 ) ;
V_7 -> V_26 = V_24 ;
}
}
static void F_23 ( struct V_1 * V_7 )
{
V_7 -> V_21 |= V_27 ;
V_7 -> V_21 &= ~ V_28 ;
if ( V_7 -> V_29 )
F_24 ( & V_7 -> V_30 ) ;
else
F_25 ( V_7 ) ;
}
static int F_26 ( struct V_1 * V_7 )
{
int V_31 ;
if ( ! V_7 -> V_32 )
return - V_33 ;
F_8 ( V_7 -> V_9 -> V_17 , F_9 () ) -> V_34 ++ ;
F_10 () ;
V_7 -> V_21 |= V_28 ;
V_31 = F_27 ( V_7 -> V_32 , 0 ) ;
if ( V_31 == - V_35 ) {
F_23 ( V_7 ) ;
V_31 = 0 ;
}
return V_31 ;
}
static void F_28 ( struct V_1 * V_7 , int V_36 )
{
if ( V_7 -> V_32 ) {
F_29 ( V_7 -> V_32 ) ;
V_7 -> V_32 = NULL ;
}
V_7 -> V_21 &= ~ V_28 ;
V_7 -> V_37 = 0 ;
V_7 -> V_36 = V_36 ;
F_25 ( V_7 ) ;
}
void F_30 ( struct V_1 * V_7 , T_2 V_38 )
{
struct V_2 * V_3 ;
V_3 = V_7 -> V_9 ;
if ( ( V_7 -> V_39 & V_40 ) &&
( V_3 -> V_41 ) && ( V_3 -> V_42 . V_43 ) ) {
if ( V_3 -> V_42 . V_43 ( V_3 , V_38 , F_31 ( V_7 -> V_44 ) ,
F_32 ( V_7 -> V_44 ) ) )
V_7 -> V_10 = V_38 ;
}
}
void F_33 ( struct V_1 * V_7 )
{
struct V_2 * V_3 ;
if ( ! V_7 )
return;
if ( V_7 -> V_10 == V_11 )
return;
V_3 = V_7 -> V_9 ;
if ( V_3 -> V_42 . V_45 ) {
V_7 -> V_46 = V_3 -> V_42 . V_45 ( V_3 , V_7 -> V_10 ) ;
V_7 -> V_10 = V_11 ;
}
}
static void F_34 ( struct V_2 * V_3 )
{
struct V_5 * V_6 = F_2 ( V_3 ) ;
unsigned long V_47 ;
int V_48 ;
F_35 ( V_3 -> V_49 -> V_50 , V_47 ) ;
if ( V_6 -> V_51 &&
( F_36 ( V_25 , V_6 -> V_51 +
V_52 ) ) )
goto V_53;
if ( F_36 ( V_25 , V_6 -> V_54 +
V_52 ) )
goto V_53;
V_6 -> V_51 = V_25 ;
V_48 = V_3 -> V_49 -> V_48 << 1 ;
if ( V_48 >= V_6 -> V_55 ) {
V_48 = V_6 -> V_55 ;
V_6 -> V_54 = 0 ;
}
V_3 -> V_49 -> V_48 = V_48 ;
F_37 ( V_56 , V_3 -> V_49 , L_1
L_2 , V_48 ) ;
V_53:
F_38 ( V_3 -> V_49 -> V_50 , V_47 ) ;
}
static void F_39 ( struct V_2 * V_3 )
{
struct V_5 * V_6 = F_2 ( V_3 ) ;
unsigned long V_47 ;
int V_48 ;
F_35 ( V_3 -> V_49 -> V_50 , V_47 ) ;
if ( V_6 -> V_54 &&
( F_36 ( V_25 , V_6 -> V_54 +
V_52 ) ) )
goto V_53;
V_6 -> V_54 = V_25 ;
V_48 = V_3 -> V_49 -> V_48 ;
V_48 >>= 1 ;
if ( ! V_48 )
V_48 = 1 ;
V_3 -> V_49 -> V_48 = V_48 ;
V_53:
F_38 ( V_3 -> V_49 -> V_50 , V_47 ) ;
}
static inline struct V_57 * F_40 ( struct V_2 * V_3 ,
T_3 V_58 )
{
struct V_57 * V_59 ;
V_59 = F_41 ( V_3 , V_58 ) ;
if ( F_42 ( V_59 ) )
return V_59 ;
F_8 ( V_3 -> V_17 , F_9 () ) -> V_60 ++ ;
F_10 () ;
F_39 ( V_3 ) ;
F_37 ( V_56 , V_3 -> V_49 ,
L_3
L_4 , V_3 -> V_49 -> V_48 ) ;
return NULL ;
}
static inline unsigned int F_43 ( struct V_1 * V_7 )
{
struct V_61 * V_62 = V_7 -> V_63 -> V_64 ;
unsigned int V_65 = V_66 ;
if ( V_62 && V_62 -> V_65 > V_65 )
V_65 = V_62 -> V_65 ;
return F_44 ( V_65 ) + V_67 ;
}
static void F_45 ( struct V_1 * V_7 , struct V_57 * V_59 )
{
struct V_68 * V_69 = V_7 -> V_44 ;
struct V_2 * V_3 = V_7 -> V_9 ;
struct V_70 * V_17 ;
struct V_71 * V_72 ;
T_3 V_73 ;
T_3 V_74 ;
T_4 V_75 ;
T_4 V_76 = 0 ;
T_3 V_58 ;
void * V_77 ;
struct V_78 * V_79 ;
T_4 V_80 ;
T_5 V_81 = V_82 ;
V_72 = F_46 ( V_59 ) ;
V_74 = F_47 ( V_72 -> V_83 ) ;
V_73 = V_74 ;
V_58 = F_48 ( V_59 ) - sizeof( * V_72 ) ;
V_77 = F_49 ( V_59 , 0 ) ;
if ( V_7 -> V_10 != V_11 ) {
F_33 ( V_7 ) ;
F_50 ( V_7 , L_5 ) ;
V_81 = V_84 ;
goto V_85;
}
if ( V_74 + V_58 > V_7 -> V_86 ) {
if ( ( F_51 ( V_59 ) & V_87 ) &&
F_52 ( V_59 ) )
goto V_88;
F_50 ( V_7 , L_6
L_7 , V_58 , V_74 , V_7 -> V_86 ) ;
V_81 = V_89 ;
goto V_85;
}
if ( V_74 != V_7 -> V_46 )
V_7 -> V_21 |= V_90 ;
V_79 = F_31 ( V_69 ) ;
V_80 = F_32 ( V_69 ) ;
if ( ! ( F_51 ( V_59 ) & V_87 ) ) {
V_76 = F_53 ( V_77 , V_58 , V_79 , & V_80 ,
& V_74 , NULL ) ;
} else {
V_75 = F_54 ( ~ 0 , ( T_5 * ) V_72 , sizeof( * V_72 ) ) ;
V_76 = F_53 ( V_77 , V_58 , V_79 , & V_80 ,
& V_74 , & V_75 ) ;
V_77 = F_49 ( V_59 , 0 ) ;
if ( V_58 % 4 )
V_75 = F_54 ( V_75 , V_77 + V_58 , 4 - ( V_58 % 4 ) ) ;
if ( ~ V_75 != F_55 ( F_56 ( V_59 ) ) ) {
V_88:
V_17 = F_8 ( V_3 -> V_17 , F_9 () ) ;
V_17 -> V_91 ++ ;
if ( V_17 -> V_92 ++ < V_93 )
F_57 ( V_94 L_8
L_9 ,
V_3 -> V_95 ) ;
F_10 () ;
if ( V_7 -> V_21 & V_90 ) {
V_81 = V_96 ;
goto V_85;
}
return;
}
}
if ( V_7 -> V_97 == V_73 )
V_7 -> V_97 += V_76 ;
V_7 -> V_46 += V_76 ;
if ( F_58 ( V_7 -> V_21 & V_98 ) &&
V_7 -> V_46 == V_7 -> V_86 - V_7 -> V_99 ) {
F_50 ( V_7 , L_10 ) ;
F_25 ( V_7 ) ;
}
return;
V_85:
F_59 ( V_7 , V_81 ) ;
}
static int F_60 ( struct V_1 * V_7 , struct V_19 * V_20 ,
T_3 V_74 , T_3 V_100 )
{
struct V_101 * V_102 ;
struct V_68 * V_69 ;
struct V_78 * V_79 ;
struct V_57 * V_59 = NULL ;
struct V_2 * V_3 = V_7 -> V_9 ;
struct V_103 * V_103 ;
T_3 V_104 ;
T_3 V_105 ;
T_3 V_106 ;
T_3 V_107 ;
T_3 V_108 , V_83 ;
T_3 V_109 ;
int error ;
void * V_14 = NULL ;
void * V_110 ;
int V_111 = V_3 -> V_112 ;
T_4 V_113 ;
F_61 ( V_100 <= 0 ) ;
if ( F_58 ( V_74 + V_100 > V_7 -> V_86 ) ) {
F_50 ( V_7 , L_11
L_12 , V_100 , V_74 ) ;
F_26 ( V_7 ) ;
return 0 ;
} else if ( V_74 != V_7 -> V_46 ) {
F_50 ( V_7 , L_13
L_14 , V_100 , V_74 ) ;
}
V_105 = V_7 -> V_114 ;
if ( V_3 -> V_115 ) {
V_105 = F_62 ( V_100 , ( T_3 ) V_3 -> V_116 ) ;
F_50 ( V_7 , L_15 ,
V_7 , V_100 , V_3 -> V_116 , V_105 ) ;
}
if ( V_105 > 512 )
V_105 &= ~ ( 512 - 1 ) ;
V_69 = V_7 -> V_44 ;
V_104 = V_100 ;
V_83 = V_108 = V_74 ;
V_106 = 0 ;
V_20 = F_63 ( V_20 ) ;
V_113 = V_117 ;
F_61 ( ! V_20 ) ;
V_79 = F_31 ( V_69 ) ;
while ( V_104 > 0 && V_79 ) {
if ( V_74 >= V_79 -> V_118 ) {
V_74 -= V_79 -> V_118 ;
V_79 = F_64 ( V_79 ) ;
continue;
}
if ( ! V_59 ) {
V_106 = F_62 ( V_105 , V_104 ) ;
if ( V_106 % 4 )
V_111 = 0 ;
V_59 = F_41 ( V_3 , V_111 ? 0 : V_106 ) ;
if ( ! V_59 )
return - V_119 ;
V_14 = F_46 ( V_59 ) + 1 ;
V_83 = V_108 ;
F_65 ( V_59 ) = V_7 -> V_114 ;
}
V_109 = V_74 + V_79 -> V_74 ;
V_107 = F_62 ( V_106 , V_79 -> V_118 - V_74 ) ;
V_107 = F_62 ( V_107 ,
( T_3 ) ( V_120 - ( V_109 & ~ V_121 ) ) ) ;
V_103 = F_66 ( V_79 ) + ( V_109 >> V_122 ) ;
if ( V_111 ) {
F_67 ( V_103 ) ;
F_68 ( F_69 ( V_59 ) ,
F_70 ( F_69 ( V_59 ) ) -> V_123 ,
V_103 , V_109 & ~ V_121 , V_107 ) ;
F_69 ( V_59 ) -> V_86 += V_107 ;
F_48 ( V_59 ) += V_107 ;
F_69 ( V_59 ) -> V_124 += V_120 ;
} else {
V_110 = F_71 ( V_103 ) ;
memcpy ( V_14 , ( char * ) V_110 + ( V_109 & ~ V_121 ) ,
V_107 ) ;
F_72 ( V_110 ) ;
V_14 += V_107 ;
}
V_74 += V_107 ;
V_108 += V_107 ;
V_106 -= V_107 ;
V_104 -= V_107 ;
if ( ( F_70 ( F_69 ( V_59 ) ) -> V_123 < V_125 ) &&
( V_106 ) )
continue;
if ( V_104 == 0 )
V_113 |= V_126 | V_127 ;
V_102 = F_73 ( V_20 ) ;
F_74 ( V_59 , V_128 , V_102 -> V_129 , V_102 -> V_130 ,
V_131 , V_113 , V_83 ) ;
error = F_75 ( V_3 , V_20 , V_59 ) ;
if ( error ) {
F_61 ( 1 ) ;
return error ;
}
V_59 = NULL ;
}
V_7 -> V_46 += V_100 ;
return 0 ;
}
static void F_76 ( struct V_1 * V_7 , struct V_57 * V_59 )
{
int V_132 = 1 ;
struct V_133 * V_134 ;
struct V_71 * V_72 ;
V_72 = F_46 ( V_59 ) ;
switch ( V_72 -> V_135 ) {
case V_136 :
break;
case V_137 :
V_134 = F_49 ( V_59 , sizeof( * V_134 ) ) ;
if ( V_134 && V_134 -> V_138 == V_139 )
break;
default:
V_132 = 0 ;
}
if ( V_132 )
F_23 ( V_7 ) ;
}
static void F_77 ( struct V_19 * V_20 , struct V_57 * V_59 , void * V_140 )
{
struct V_1 * V_7 = (struct V_1 * ) V_140 ;
struct V_2 * V_3 = V_7 -> V_9 ;
struct V_71 * V_72 ;
struct V_141 * V_142 ;
T_5 V_143 ;
int V_31 = 0 ;
if ( F_78 ( V_59 ) ) {
F_79 ( V_7 , V_59 ) ;
return;
}
V_72 = F_46 ( V_59 ) ;
V_143 = V_72 -> V_135 ;
if ( V_3 -> V_21 != V_144 ) {
F_50 ( V_7 , L_16 ,
V_3 -> V_21 , V_143 ) ;
goto V_145;
}
if ( F_17 ( V_7 ) )
goto V_145;
if ( V_72 -> V_146 == V_147 ) {
F_76 ( V_7 , V_59 ) ;
goto V_53;
}
if ( V_7 -> V_21 & ( V_27 | V_28 ) ) {
F_50 ( V_7 , L_17 , V_143 ) ;
goto V_53;
}
if ( V_143 == V_148 ) {
F_61 ( F_51 ( V_59 ) & V_87 ) ;
V_142 = F_49 ( V_59 , sizeof( * V_142 ) ) ;
F_61 ( ! V_142 ) ;
V_31 = F_60 ( V_7 , V_20 ,
( T_3 ) F_47 ( V_142 -> V_149 ) ,
( T_3 ) F_47 ( V_142 -> V_150 ) ) ;
if ( ! V_31 )
V_20 -> V_151 = V_7 -> V_46 ;
} else if ( V_143 == V_128 ) {
F_61 ( F_48 ( V_59 ) < sizeof( * V_72 ) ) ;
F_45 ( V_7 , V_59 ) ;
V_20 -> V_151 = V_7 -> V_97 ;
} else if ( V_143 == V_152 ) {
F_61 ( F_51 ( V_59 ) & V_87 ) ;
F_80 ( V_7 , V_59 ) ;
} else {
F_50 ( V_7 , L_18 , V_143 ) ;
}
V_53:
F_20 ( V_7 ) ;
V_145:
F_81 ( V_59 ) ;
}
static void F_80 ( struct V_1 * V_7 , struct V_57 * V_59 )
{
struct V_71 * V_72 ;
struct V_153 * V_154 ;
struct V_155 * V_156 ;
struct V_157 * V_158 ;
T_4 V_159 ;
T_4 V_160 ;
T_4 V_161 = 0 ;
T_4 V_162 = 0 ;
T_5 V_47 = 0 ;
V_159 = F_48 ( V_59 ) ;
V_72 = (struct V_71 * ) F_82 ( V_59 ) ;
if ( F_58 ( V_159 < sizeof( * V_72 ) + sizeof( * V_154 ) ) )
goto V_163;
V_159 -= sizeof( * V_72 ) ;
V_154 = (struct V_153 * ) ( V_72 + 1 ) ;
V_7 -> V_164 = V_154 -> V_165 ;
V_47 = V_154 -> F_51 ;
V_7 -> V_166 = V_47 ;
V_160 = V_7 -> V_86 ;
F_33 ( V_7 ) ;
if ( F_58 ( ( V_47 & ~ V_167 ) || V_154 -> V_165 ) ) {
V_156 = ( void * ) ( V_154 + 1 ) ;
if ( V_47 & ( V_168 | V_169 ) ) {
if ( V_159 < sizeof( * V_154 ) + sizeof( * V_156 ) )
goto V_163;
V_158 = (struct V_157 * ) ( V_156 + 1 ) ;
if ( V_47 & V_168 ) {
V_161 = F_47 ( V_156 -> V_170 ) ;
if ( ( V_161 != V_171 ) &&
( V_161 != V_172 ) )
goto V_163;
if ( V_7 -> V_29 ) {
V_7 -> V_164 = V_158 -> V_173 ;
F_24 ( & V_7 -> V_30 ) ;
return;
}
}
if ( V_47 & V_169 ) {
V_162 = F_47 ( V_156 -> V_174 ) ;
if ( V_162 > V_175 )
V_162 = V_175 ;
memcpy ( V_7 -> V_44 -> V_176 ,
( char * ) V_158 + V_161 , V_162 ) ;
}
}
if ( V_47 & ( V_177 | V_178 ) ) {
if ( V_159 < sizeof( * V_154 ) + sizeof( V_156 -> V_179 ) )
goto V_163;
if ( V_47 & V_177 ) {
V_7 -> V_99 = F_47 ( V_156 -> V_179 ) ;
if ( ! ( V_47 & V_169 ) &&
( V_154 -> V_165 == 0 ) &&
( F_83 ( V_7 -> V_44 ) -
V_7 -> V_99 ) < V_7 -> V_44 -> V_180 )
goto V_85;
V_160 -= V_7 -> V_99 ;
} else {
V_7 -> V_36 = V_84 ;
}
}
}
V_7 -> V_21 |= V_98 ;
if ( F_58 ( V_7 -> V_164 == V_181 &&
V_7 -> V_46 != V_160 ) ) {
if ( V_7 -> V_46 < V_160 ) {
if ( V_7 -> V_9 -> V_182 ) {
F_50 ( V_7 , L_19 ,
V_7 -> V_63 -> V_95 ) ;
return;
}
F_50 ( V_7 , L_20
L_21 ,
V_7 -> V_63 -> V_95 ,
V_7 -> V_46 , V_160 , V_7 -> V_86 ) ;
F_21 ( V_7 , F_43 ( V_7 ) ) ;
return;
}
V_7 -> V_36 = V_89 ;
F_50 ( V_7 , L_22
L_21 ,
V_7 -> V_63 -> V_95 ,
V_7 -> V_46 , V_160 , V_7 -> V_86 ) ;
}
F_25 ( V_7 ) ;
return;
V_163:
F_50 ( V_7 , L_23
L_24 , V_47 , F_48 ( V_59 ) , V_161 , V_162 ) ;
V_85:
V_7 -> V_36 = V_84 ;
F_25 ( V_7 ) ;
}
static void F_25 ( struct V_1 * V_7 )
{
struct V_2 * V_3 = V_7 -> V_9 ;
struct V_19 * V_20 ;
struct V_101 * V_102 ;
T_4 V_113 ;
if ( V_7 -> V_21 & V_28 )
return;
if ( V_7 -> V_21 & V_27 ) {
if ( ! V_7 -> V_36 )
V_7 -> V_36 = V_183 ;
} else {
if ( V_7 -> V_164 == V_181 &&
V_7 -> V_46 < V_7 -> V_86 && ! V_7 -> V_37 &&
( ! ( V_7 -> V_166 & V_177 ) ||
V_7 -> V_46 < V_7 -> V_86 - V_7 -> V_99 ) ) {
F_50 ( V_7 , L_25 ,
V_7 -> V_46 , V_7 -> V_86 ) ;
V_7 -> V_36 = V_184 ;
}
}
V_20 = V_7 -> V_32 ;
if ( V_20 ) {
V_7 -> V_32 = NULL ;
if ( F_58 ( V_7 -> V_166 & V_167 ) ) {
struct V_57 * V_185 ;
struct V_19 * V_186 ;
V_186 = F_63 ( V_20 ) ;
V_185 = F_40 ( V_7 -> V_9 , 0 ) ;
if ( V_185 ) {
V_113 = V_126 ;
V_113 |= V_187 | V_127 ;
V_102 = F_73 ( V_20 ) ;
F_74 ( V_185 , V_188 ,
V_102 -> V_129 , V_102 -> V_130 ,
V_131 , V_113 , 0 ) ;
F_75 ( V_3 , V_186 , V_185 ) ;
}
}
F_29 ( V_20 ) ;
}
if ( V_7 -> V_44 )
F_84 ( V_7 ) ;
}
static void F_85 ( struct V_1 * V_7 , int error )
{
if ( V_7 -> V_32 ) {
F_29 ( V_7 -> V_32 ) ;
V_7 -> V_32 = NULL ;
}
V_7 -> V_36 = error ;
}
static void F_86 ( struct V_2 * V_3 , unsigned int V_189 ,
unsigned int V_190 , int error )
{
struct V_5 * V_6 = F_2 ( V_3 ) ;
struct V_1 * V_7 ;
struct V_68 * V_191 ;
unsigned long V_47 ;
F_35 ( & V_6 -> V_192 , V_47 ) ;
V_193:
F_87 (fsp, &si->scsi_pkt_queue, list) {
V_191 = V_7 -> V_44 ;
if ( V_189 != - 1 && F_88 ( V_191 ) != V_189 )
continue;
if ( V_190 != - 1 && V_191 -> V_194 -> V_190 != V_190 )
continue;
F_14 ( V_7 ) ;
F_38 ( & V_6 -> V_192 , V_47 ) ;
F_18 ( & V_7 -> V_16 ) ;
if ( ! ( V_7 -> V_21 & V_22 ) ) {
V_7 -> V_21 |= V_22 ;
F_19 ( & V_7 -> V_16 ) ;
F_85 ( V_7 , error ) ;
F_18 ( & V_7 -> V_16 ) ;
F_84 ( V_7 ) ;
}
F_19 ( & V_7 -> V_16 ) ;
F_11 ( V_7 ) ;
F_35 ( & V_6 -> V_192 , V_47 ) ;
goto V_193;
}
F_38 ( & V_6 -> V_192 , V_47 ) ;
}
static void F_89 ( struct V_2 * V_3 )
{
F_86 ( V_3 , - 1 , - 1 , V_195 ) ;
}
static int F_90 ( struct V_2 * V_3 , struct V_1 * V_7 )
{
struct V_5 * V_6 = F_2 ( V_3 ) ;
unsigned long V_47 ;
int V_31 ;
V_7 -> V_44 -> V_196 . V_197 = ( char * ) V_7 ;
V_7 -> V_198 . V_199 = F_91 ( V_7 -> V_86 ) ;
V_7 -> V_198 . V_200 = V_7 -> V_39 & ~ V_201 ;
F_92 ( V_7 -> V_44 -> V_194 -> V_190 , & V_7 -> V_198 . V_202 ) ;
memcpy ( V_7 -> V_198 . V_203 , V_7 -> V_44 -> V_204 , V_7 -> V_44 -> V_205 ) ;
F_35 ( & V_6 -> V_192 , V_47 ) ;
F_93 ( & V_7 -> V_15 , & V_6 -> V_206 ) ;
F_38 ( & V_6 -> V_192 , V_47 ) ;
V_31 = V_3 -> V_42 . V_207 ( V_3 , V_7 , F_77 ) ;
if ( F_58 ( V_31 ) ) {
F_35 ( & V_6 -> V_192 , V_47 ) ;
V_7 -> V_44 -> V_196 . V_197 = NULL ;
F_94 ( & V_7 -> V_15 ) ;
F_38 ( & V_6 -> V_192 , V_47 ) ;
}
return V_31 ;
}
static int F_95 ( struct V_2 * V_3 , struct V_1 * V_7 ,
void (* F_96)( struct V_19 * ,
struct V_57 * V_59 ,
void * V_140 ) )
{
struct V_57 * V_59 ;
struct V_19 * V_20 ;
struct V_208 * V_63 ;
struct V_61 * V_62 ;
const T_3 V_58 = sizeof( V_7 -> V_198 ) ;
int V_31 = 0 ;
if ( F_17 ( V_7 ) )
return 0 ;
V_59 = F_40 ( V_3 , sizeof( V_7 -> V_198 ) ) ;
if ( ! V_59 ) {
V_31 = - 1 ;
goto V_53;
}
memcpy ( F_49 ( V_59 , V_58 ) , & V_7 -> V_198 , V_58 ) ;
F_97 ( V_59 ) = V_7 ;
V_63 = V_7 -> V_63 ;
V_7 -> V_114 = V_63 -> V_209 ;
V_62 = V_63 -> V_64 ;
F_74 ( V_59 , V_210 , V_63 -> V_95 ,
V_62 -> V_211 -> V_95 , V_131 ,
V_212 , 0 ) ;
V_20 = F_98 ( V_3 , V_59 , F_96 , F_16 , V_7 , 0 ) ;
if ( ! V_20 ) {
V_31 = - 1 ;
goto V_53;
}
V_7 -> V_32 = V_20 ;
F_14 ( V_7 ) ;
F_99 ( & V_7 -> V_13 , V_213 , ( unsigned long ) V_7 ) ;
if ( V_62 -> V_47 & V_214 )
F_21 ( V_7 , F_43 ( V_7 ) ) ;
V_53:
F_20 ( V_7 ) ;
return V_31 ;
}
static void F_79 ( struct V_1 * V_7 , struct V_57 * V_59 )
{
int error = F_100 ( V_59 ) ;
if ( F_17 ( V_7 ) )
return;
if ( error == - V_215 ) {
F_28 ( V_7 , V_84 ) ;
goto V_53;
}
V_7 -> V_21 &= ~ V_28 ;
V_7 -> V_36 = V_216 ;
F_25 ( V_7 ) ;
V_53:
F_20 ( V_7 ) ;
}
static int F_101 ( struct V_1 * V_7 )
{
int V_31 = V_217 ;
unsigned long V_218 ;
F_50 ( V_7 , L_26 , V_7 -> V_21 ) ;
if ( F_26 ( V_7 ) ) {
F_50 ( V_7 , L_27 ) ;
return V_217 ;
}
if ( V_7 -> V_21 & V_27 ) {
F_50 ( V_7 , L_28 ) ;
return V_219 ;
}
F_102 ( & V_7 -> V_30 ) ;
V_7 -> V_29 = 1 ;
F_19 ( & V_7 -> V_16 ) ;
V_218 = F_103 ( & V_7 -> V_30 ,
V_220 ) ;
F_18 ( & V_7 -> V_16 ) ;
V_7 -> V_29 = 0 ;
if ( ! V_218 ) {
F_50 ( V_7 , L_29 ) ;
} else if ( V_7 -> V_21 & V_27 ) {
F_50 ( V_7 , L_30 ) ;
V_31 = V_219 ;
F_25 ( V_7 ) ;
}
return V_31 ;
}
static void F_104 ( unsigned long V_14 )
{
struct V_1 * V_7 = (struct V_1 * ) V_14 ;
struct V_2 * V_3 = V_7 -> V_9 ;
if ( V_3 -> V_42 . V_207 ( V_3 , V_7 , V_221 ) ) {
if ( V_7 -> V_222 ++ >= V_223 )
return;
if ( F_17 ( V_7 ) )
return;
F_99 ( & V_7 -> V_13 , F_104 , ( unsigned long ) V_7 ) ;
F_21 ( V_7 , F_43 ( V_7 ) ) ;
F_20 ( V_7 ) ;
}
}
static int F_105 ( struct V_2 * V_3 , struct V_1 * V_7 ,
unsigned int V_189 , unsigned int V_190 )
{
int V_31 ;
V_7 -> V_198 . V_199 = F_91 ( V_7 -> V_86 ) ;
V_7 -> V_198 . V_224 = V_225 ;
F_92 ( V_190 , & V_7 -> V_198 . V_202 ) ;
V_7 -> V_29 = 1 ;
F_102 ( & V_7 -> V_30 ) ;
F_104 ( ( unsigned long ) V_7 ) ;
V_31 = F_103 ( & V_7 -> V_30 , V_220 ) ;
F_18 ( & V_7 -> V_16 ) ;
V_7 -> V_21 |= V_22 ;
F_19 ( & V_7 -> V_16 ) ;
F_106 ( & V_7 -> V_13 ) ;
F_18 ( & V_7 -> V_16 ) ;
if ( V_7 -> V_32 ) {
F_29 ( V_7 -> V_32 ) ;
V_7 -> V_32 = NULL ;
}
V_7 -> V_29 = 0 ;
F_19 ( & V_7 -> V_16 ) ;
if ( ! V_31 ) {
F_107 ( V_3 , L_31 ) ;
return V_217 ;
}
if ( V_7 -> V_164 != V_226 )
return V_217 ;
F_107 ( V_3 , L_32 , V_190 ) ;
F_86 ( V_3 , V_189 , V_190 , V_183 ) ;
return V_219 ;
}
static void V_221 ( struct V_19 * V_20 , struct V_57 * V_59 , void * V_140 )
{
struct V_1 * V_7 = V_140 ;
struct V_71 * V_72 ;
if ( F_78 ( V_59 ) ) {
return;
}
if ( F_17 ( V_7 ) )
goto V_145;
if ( ! V_7 -> V_32 || ! V_7 -> V_29 )
goto V_227;
V_72 = F_46 ( V_59 ) ;
if ( V_72 -> V_146 != V_147 )
F_80 ( V_7 , V_59 ) ;
V_7 -> V_32 = NULL ;
F_29 ( V_20 ) ;
V_227:
F_20 ( V_7 ) ;
V_145:
F_81 ( V_59 ) ;
}
static void F_108 ( struct V_2 * V_3 )
{
F_86 ( V_3 , - 1 , - 1 , V_84 ) ;
}
static void V_213 ( unsigned long V_14 )
{
struct V_1 * V_7 = (struct V_1 * ) V_14 ;
struct V_208 * V_63 = V_7 -> V_63 ;
struct V_61 * V_62 = V_63 -> V_64 ;
if ( F_17 ( V_7 ) )
return;
if ( V_7 -> V_198 . V_224 )
goto V_53;
if ( V_7 -> V_9 -> V_182 ) {
F_50 ( V_7 , L_33 ,
V_7 -> V_26 ) ;
F_99 ( & V_7 -> V_13 , V_213 , ( unsigned long ) V_7 ) ;
F_21 ( V_7 , V_7 -> V_26 ) ;
goto V_53;
}
F_50 ( V_7 , L_34 ,
V_7 -> V_26 , V_62 -> V_47 , V_7 -> V_21 ) ;
V_7 -> V_21 |= V_228 ;
if ( V_62 -> V_47 & V_214 )
F_109 ( V_7 ) ;
else if ( V_7 -> V_21 & V_98 )
F_25 ( V_7 ) ;
else
F_59 ( V_7 , V_229 ) ;
V_7 -> V_21 &= ~ V_228 ;
V_53:
F_20 ( V_7 ) ;
}
static void F_109 ( struct V_1 * V_7 )
{
struct V_2 * V_3 ;
struct V_57 * V_59 ;
struct V_208 * V_63 ;
struct V_61 * V_62 ;
V_3 = V_7 -> V_9 ;
V_63 = V_7 -> V_63 ;
V_62 = V_63 -> V_64 ;
if ( ! V_7 -> V_32 || V_62 -> V_230 != V_231 ) {
V_7 -> V_36 = V_195 ;
V_7 -> V_37 = 0 ;
F_25 ( V_7 ) ;
return;
}
V_59 = F_40 ( V_3 , sizeof( struct V_232 ) ) ;
if ( ! V_59 )
goto V_233;
F_110 ( V_59 ) = V_7 -> V_32 ;
F_74 ( V_59 , V_234 , V_63 -> V_95 ,
V_62 -> V_211 -> V_95 , V_235 ,
V_212 , 0 ) ;
if ( V_3 -> V_42 . V_236 ( V_3 , V_63 -> V_95 , V_59 , V_237 ,
V_238 , V_7 ,
2 * V_3 -> V_239 ) ) {
F_14 ( V_7 ) ;
return;
}
V_233:
if ( V_7 -> V_222 ++ < V_223 )
F_21 ( V_7 , F_43 ( V_7 ) ) ;
else
F_59 ( V_7 , V_229 ) ;
}
static void V_238 ( struct V_19 * V_20 , struct V_57 * V_59 , void * V_140 )
{
struct V_1 * V_7 = (struct V_1 * ) V_140 ;
struct V_240 * V_241 ;
struct V_242 * V_243 ;
T_4 V_244 ;
T_5 V_245 ;
T_4 V_74 ;
enum V_246 V_247 ;
enum V_248 V_143 ;
struct V_61 * V_62 ;
if ( F_78 ( V_59 ) ) {
F_111 ( V_7 , V_59 ) ;
return;
}
if ( F_17 ( V_7 ) )
goto V_145;
V_7 -> V_222 = 0 ;
V_245 = F_112 ( V_59 ) ;
if ( V_245 == V_249 ) {
V_243 = F_49 ( V_59 , sizeof( * V_243 ) ) ;
switch ( V_243 -> V_250 ) {
default:
F_50 ( V_7 ,
L_35 ,
V_7 -> V_63 -> V_95 , V_243 -> V_250 ,
V_243 -> V_251 ) ;
case V_252 :
F_50 ( V_7 , L_36 ) ;
V_62 = V_7 -> V_63 -> V_64 ;
V_62 -> V_47 &= ~ V_214 ;
break;
case V_253 :
case V_254 :
F_50 ( V_7 , L_37 ,
V_7 -> V_63 -> V_95 , V_243 -> V_250 ,
V_243 -> V_251 ) ;
if ( V_243 -> V_251 == V_255 ) {
struct V_101 * V_102 = F_73 ( V_7 -> V_32 ) ;
V_102 -> V_21 |= V_256 ;
V_7 -> V_21 |= V_27 ;
F_28 ( V_7 , V_257 ) ;
break;
}
F_59 ( V_7 , V_257 ) ;
break;
}
} else if ( V_245 == V_258 ) {
if ( V_7 -> V_21 & V_27 )
goto V_259;
V_247 = V_7 -> V_44 -> V_260 ;
V_241 = F_49 ( V_59 , sizeof( * V_241 ) ) ;
V_74 = F_47 ( V_241 -> V_261 ) ;
V_244 = F_47 ( V_241 -> V_262 ) ;
if ( V_244 & V_263 ) {
if ( V_247 == V_264 ) {
V_143 = V_152 ;
} else if ( V_7 -> V_97 == V_74 ) {
V_143 = V_152 ;
} else {
V_74 = V_7 -> V_97 ;
V_143 = V_128 ;
}
F_113 ( V_7 , V_143 , V_74 ) ;
} else if ( V_244 & V_265 ) {
F_21 ( V_7 , F_43 ( V_7 ) ) ;
} else {
V_143 = V_128 ;
if ( V_247 == V_264 ) {
V_143 = V_152 ;
if ( V_74 < V_7 -> V_86 )
V_143 = V_148 ;
} else if ( V_74 == V_7 -> V_97 ) {
V_143 = V_152 ;
} else if ( V_7 -> V_97 < V_74 ) {
V_74 = V_7 -> V_97 ;
}
F_113 ( V_7 , V_143 , V_74 ) ;
}
}
V_259:
F_20 ( V_7 ) ;
V_145:
F_11 ( V_7 ) ;
F_81 ( V_59 ) ;
}
static void F_111 ( struct V_1 * V_7 , struct V_57 * V_59 )
{
int error = F_100 ( V_59 ) ;
if ( F_17 ( V_7 ) )
goto V_145;
switch ( error ) {
case - V_215 :
F_50 ( V_7 , L_38 ,
V_7 , V_7 -> V_63 -> V_95 ) ;
F_28 ( V_7 , V_84 ) ;
break;
default:
F_50 ( V_7 , L_39 ,
V_7 , V_7 -> V_63 -> V_95 , error ) ;
V_7 -> V_36 = V_216 ;
case - V_266 :
F_50 ( V_7 , L_40 ,
V_7 , V_7 -> V_63 -> V_95 , V_7 -> V_222 ,
V_223 ) ;
if ( V_7 -> V_222 ++ < V_223 )
F_109 ( V_7 ) ;
else
F_59 ( V_7 , V_84 ) ;
break;
}
F_20 ( V_7 ) ;
V_145:
F_11 ( V_7 ) ;
}
static void F_59 ( struct V_1 * V_7 , T_5 V_267 )
{
F_50 ( V_7 , L_41 , V_267 ) ;
V_7 -> V_36 = V_267 ;
V_7 -> V_164 = 0 ;
V_7 -> V_37 = 0 ;
F_26 ( V_7 ) ;
}
static void F_113 ( struct V_1 * V_7 , enum V_248 V_143 , T_4 V_74 )
{
struct V_2 * V_3 = V_7 -> V_9 ;
struct V_208 * V_63 ;
struct V_61 * V_62 ;
struct V_101 * V_102 = F_73 ( V_7 -> V_32 ) ;
struct V_19 * V_20 ;
struct V_268 * V_269 ;
struct V_57 * V_59 ;
V_63 = V_7 -> V_63 ;
V_62 = V_63 -> V_64 ;
if ( ! ( V_62 -> V_47 & V_270 ) ||
V_62 -> V_230 != V_231 )
goto V_233;
V_59 = F_40 ( V_3 , sizeof( * V_269 ) ) ;
if ( ! V_59 )
goto V_233;
V_269 = F_49 ( V_59 , sizeof( * V_269 ) ) ;
memset ( V_269 , 0 , sizeof( * V_269 ) ) ;
V_269 -> V_271 = V_272 ;
V_269 -> V_273 = F_114 ( V_102 -> V_274 ) ;
V_269 -> V_275 = F_114 ( V_102 -> V_276 ) ;
V_269 -> V_277 = V_143 ;
V_269 -> V_278 = F_91 ( V_74 ) ;
F_74 ( V_59 , V_279 , V_63 -> V_95 ,
V_62 -> V_211 -> V_95 , V_131 ,
V_212 , 0 ) ;
V_20 = F_98 ( V_3 , V_59 , V_280 ,
F_16 ,
V_7 , F_43 ( V_7 ) ) ;
if ( ! V_20 )
goto V_233;
V_7 -> V_281 = V_20 ;
V_7 -> V_46 = V_74 ;
V_7 -> V_97 = V_74 ;
V_7 -> V_21 &= ~ V_98 ;
F_14 ( V_7 ) ;
return;
V_233:
F_28 ( V_7 , V_257 ) ;
}
static void V_280 ( struct V_19 * V_20 , struct V_57 * V_59 , void * V_140 )
{
struct V_1 * V_7 = V_140 ;
struct V_71 * V_72 ;
if ( F_78 ( V_59 ) ) {
F_115 ( V_7 , V_59 ) ;
return;
}
if ( F_17 ( V_7 ) )
goto V_145;
V_72 = F_46 ( V_59 ) ;
if ( V_72 -> V_146 == V_147 ) {
F_20 ( V_7 ) ;
return;
}
switch ( F_112 ( V_59 ) ) {
case V_258 :
V_7 -> V_222 = 0 ;
F_21 ( V_7 , F_43 ( V_7 ) ) ;
break;
case V_249 :
default:
F_59 ( V_7 , V_84 ) ;
break;
}
F_20 ( V_7 ) ;
V_145:
F_29 ( V_20 ) ;
F_81 ( V_59 ) ;
}
static void F_115 ( struct V_1 * V_7 , struct V_57 * V_59 )
{
if ( F_17 ( V_7 ) )
goto V_145;
switch ( F_100 ( V_59 ) ) {
case - V_266 :
F_50 ( V_7 , L_42 , V_7 -> V_222 ) ;
if ( V_7 -> V_222 ++ < V_223 )
F_109 ( V_7 ) ;
else
F_59 ( V_7 , V_229 ) ;
break;
case - V_215 :
F_50 ( V_7 , L_43 ) ;
default:
F_28 ( V_7 , V_84 ) ;
break;
}
F_20 ( V_7 ) ;
V_145:
F_29 ( V_7 -> V_281 ) ;
}
static inline int F_116 ( struct V_2 * V_3 )
{
return ( V_3 -> V_21 == V_144 ) &&
V_3 -> V_282 && ! V_3 -> V_182 ;
}
int F_117 ( struct V_283 * V_284 , struct V_68 * V_191 )
{
struct V_2 * V_3 = F_118 ( V_284 ) ;
struct V_208 * V_63 = F_119 ( F_120 ( V_191 -> V_194 ) ) ;
struct V_1 * V_7 ;
struct V_61 * V_62 ;
int V_285 ;
int V_31 = 0 ;
struct V_70 * V_17 ;
V_285 = F_121 ( V_63 ) ;
if ( V_285 ) {
V_191 -> V_286 = V_285 ;
V_191 -> V_287 ( V_191 ) ;
return 0 ;
}
if ( ! * (struct V_288 * * ) V_63 -> V_64 ) {
V_191 -> V_286 = V_289 << 16 ;
V_191 -> V_287 ( V_191 ) ;
goto V_145;
}
V_62 = V_63 -> V_64 ;
if ( ! F_116 ( V_3 ) ) {
if ( V_3 -> V_182 ) {
F_39 ( V_3 ) ;
F_37 ( V_56 , V_3 -> V_49 ,
L_44
L_4 ,
V_3 -> V_49 -> V_48 ) ;
}
V_31 = V_290 ;
goto V_145;
}
V_7 = F_1 ( V_3 , V_291 ) ;
if ( V_7 == NULL ) {
V_31 = V_290 ;
goto V_145;
}
V_7 -> V_44 = V_191 ;
V_7 -> V_63 = V_63 ;
V_7 -> V_86 = F_83 ( V_191 ) ;
V_7 -> V_46 = 0 ;
V_17 = F_8 ( V_3 -> V_17 , F_9 () ) ;
if ( V_191 -> V_260 == V_292 ) {
V_7 -> V_39 = V_40 ;
V_17 -> V_293 ++ ;
V_17 -> V_294 += V_7 -> V_86 ;
} else if ( V_191 -> V_260 == V_264 ) {
V_7 -> V_39 = V_295 ;
V_17 -> V_296 ++ ;
V_17 -> V_297 += V_7 -> V_86 ;
} else {
V_7 -> V_39 = 0 ;
V_17 -> V_298 ++ ;
}
F_10 () ;
V_285 = F_90 ( V_3 , V_7 ) ;
if ( V_285 != 0 ) {
V_7 -> V_21 = V_299 ;
F_11 ( V_7 ) ;
V_31 = V_290 ;
}
V_145:
return V_31 ;
}
static void F_84 ( struct V_1 * V_7 )
{
struct V_5 * V_6 ;
struct V_68 * V_191 ;
struct V_2 * V_3 ;
unsigned long V_47 ;
F_33 ( V_7 ) ;
V_7 -> V_21 |= V_22 ;
if ( ! ( V_7 -> V_21 & V_228 ) ) {
F_19 ( & V_7 -> V_16 ) ;
F_106 ( & V_7 -> V_13 ) ;
F_18 ( & V_7 -> V_16 ) ;
}
V_3 = V_7 -> V_9 ;
V_6 = F_2 ( V_3 ) ;
if ( V_6 -> V_54 )
F_34 ( V_3 ) ;
V_191 = V_7 -> V_44 ;
F_122 ( V_191 ) = V_7 -> V_164 ;
switch ( V_7 -> V_36 ) {
case V_82 :
if ( V_7 -> V_164 == 0 ) {
V_191 -> V_286 = V_300 << 16 ;
if ( V_7 -> V_99 )
F_123 ( V_191 ) = V_7 -> V_99 ;
} else {
V_191 -> V_286 = ( V_300 << 16 ) | V_7 -> V_164 ;
}
break;
case V_84 :
F_50 ( V_7 , L_45
L_46 ) ;
V_191 -> V_286 = V_301 << 16 ;
break;
case V_184 :
if ( ( V_7 -> V_164 == 0 ) && ! ( V_7 -> V_39 & V_40 ) ) {
if ( V_7 -> V_21 & V_98 ) {
V_191 -> V_286 = V_300 << 16 ;
} else {
F_50 ( V_7 , L_47
L_48 ) ;
V_191 -> V_286 = V_301 << 16 ;
}
} else {
F_50 ( V_7 , L_45
L_49 ) ;
F_123 ( V_191 ) = V_7 -> V_99 ;
V_191 -> V_286 = ( V_301 << 16 ) | V_7 -> V_164 ;
}
break;
case V_89 :
F_50 ( V_7 , L_45
L_50 ) ;
V_191 -> V_286 = ( V_301 << 16 ) | V_7 -> V_164 ;
break;
case V_183 :
if ( F_124 ( V_191 -> V_286 ) == V_302 )
F_50 ( V_7 , L_51
L_52 ) ;
else {
F_50 ( V_7 , L_45
L_52 ) ;
F_125 ( V_191 , V_301 ) ;
}
V_191 -> V_286 |= V_7 -> V_37 ;
break;
case V_303 :
F_50 ( V_7 , L_53
L_54 ) ;
V_191 -> V_286 = ( V_304 << 16 ) ;
break;
case V_257 :
F_50 ( V_7 , L_55
L_56 ) ;
V_191 -> V_286 = ( V_305 << 16 ) ;
break;
case V_195 :
F_50 ( V_7 , L_57
L_58 ) ;
V_191 -> V_286 = ( V_306 << 16 ) ;
break;
case V_96 :
F_50 ( V_7 , L_59
L_60 ) ;
V_191 -> V_286 = ( V_307 << 16 ) ;
break;
case V_229 :
F_50 ( V_7 , L_61
L_62 ) ;
V_191 -> V_286 = ( V_308 << 16 ) | V_7 -> V_37 ;
break;
default:
F_50 ( V_7 , L_45
L_63 ) ;
V_191 -> V_286 = ( V_301 << 16 ) ;
break;
}
if ( V_3 -> V_21 != V_144 && V_7 -> V_36 != V_82 )
V_191 -> V_286 = ( V_309 << 16 ) ;
F_35 ( & V_6 -> V_192 , V_47 ) ;
F_94 ( & V_7 -> V_15 ) ;
V_191 -> V_196 . V_197 = NULL ;
F_38 ( & V_6 -> V_192 , V_47 ) ;
V_191 -> V_287 ( V_191 ) ;
F_11 ( V_7 ) ;
}
int F_126 ( struct V_68 * V_191 )
{
struct V_1 * V_7 ;
struct V_2 * V_3 ;
struct V_5 * V_6 ;
int V_31 = V_217 ;
unsigned long V_47 ;
int V_285 ;
V_285 = F_127 ( V_191 ) ;
if ( V_285 )
return V_285 ;
V_3 = F_118 ( V_191 -> V_194 -> V_49 ) ;
if ( V_3 -> V_21 != V_144 )
return V_31 ;
else if ( ! V_3 -> V_282 )
return V_31 ;
V_6 = F_2 ( V_3 ) ;
F_35 ( & V_6 -> V_192 , V_47 ) ;
V_7 = F_128 ( V_191 ) ;
if ( ! V_7 ) {
F_38 ( & V_6 -> V_192 , V_47 ) ;
return V_219 ;
}
F_14 ( V_7 ) ;
F_38 ( & V_6 -> V_192 , V_47 ) ;
if ( F_17 ( V_7 ) ) {
V_31 = V_219 ;
goto V_310;
}
V_31 = F_101 ( V_7 ) ;
F_20 ( V_7 ) ;
V_310:
F_11 ( V_7 ) ;
return V_31 ;
}
int F_129 ( struct V_68 * V_191 )
{
struct V_2 * V_3 ;
struct V_1 * V_7 ;
struct V_208 * V_63 = F_119 ( F_120 ( V_191 -> V_194 ) ) ;
int V_31 = V_217 ;
int V_285 ;
V_285 = F_127 ( V_191 ) ;
if ( V_285 )
return V_285 ;
V_3 = F_118 ( V_191 -> V_194 -> V_49 ) ;
if ( V_3 -> V_21 != V_144 )
return V_31 ;
F_107 ( V_3 , L_64 , V_63 -> V_95 ) ;
V_7 = F_1 ( V_3 , V_311 ) ;
if ( V_7 == NULL ) {
F_57 ( V_94 L_65 ) ;
goto V_145;
}
V_7 -> V_63 = V_63 ;
V_31 = F_105 ( V_3 , V_7 , F_88 ( V_191 ) , V_191 -> V_194 -> V_190 ) ;
V_7 -> V_21 = V_299 ;
F_11 ( V_7 ) ;
V_145:
return V_31 ;
}
int F_130 ( struct V_68 * V_191 )
{
struct V_283 * V_284 = V_191 -> V_194 -> V_49 ;
struct V_2 * V_3 = F_118 ( V_284 ) ;
unsigned long V_312 ;
F_107 ( V_3 , L_66 ) ;
F_127 ( V_191 ) ;
F_131 ( V_3 ) ;
V_312 = V_25 + V_313 ;
while ( ! F_116 ( V_3 ) && F_36 ( V_25 ,
V_312 ) )
F_132 ( 1000 ) ;
if ( F_116 ( V_3 ) ) {
F_37 ( V_314 , V_284 , L_67
L_68 , V_3 -> V_95 ) ;
return V_219 ;
} else {
F_37 ( V_314 , V_284 , L_69
L_70 ,
V_3 -> V_95 ) ;
return V_217 ;
}
}
int F_133 ( struct V_315 * V_316 )
{
struct V_208 * V_63 = F_119 ( F_120 ( V_316 ) ) ;
if ( ! V_63 || F_121 ( V_63 ) )
return - V_35 ;
F_134 ( V_316 , V_317 ) ;
return 0 ;
}
void F_135 ( struct V_2 * V_3 )
{
struct V_5 * V_6 = F_2 ( V_3 ) ;
if ( ! F_136 ( & V_6 -> V_206 ) )
F_57 ( V_56 L_71
L_72 , V_3 -> V_95 ) ;
F_137 ( V_6 -> V_8 ) ;
F_138 ( V_6 ) ;
V_3 -> V_318 = NULL ;
}
int F_139 ( void )
{
int V_31 = 0 ;
V_319 = F_140 ( L_73 ,
sizeof( struct V_1 ) ,
0 , V_320 , NULL ) ;
if ( ! V_319 ) {
F_57 ( V_56 L_74
L_75 ) ;
V_31 = - V_119 ;
}
return V_31 ;
}
void F_141 ( void )
{
if ( V_319 )
F_142 ( V_319 ) ;
}
int F_143 ( struct V_2 * V_3 )
{
int V_31 ;
struct V_5 * V_6 ;
if ( ! V_3 -> V_42 . V_207 )
V_3 -> V_42 . V_207 = F_95 ;
if ( ! V_3 -> V_42 . V_321 )
V_3 -> V_42 . V_321 = F_108 ;
if ( ! V_3 -> V_42 . V_322 )
V_3 -> V_42 . V_322 = F_89 ;
V_6 = F_144 ( sizeof( struct V_5 ) , V_323 ) ;
if ( ! V_6 )
return - V_119 ;
V_3 -> V_318 = V_6 ;
V_6 -> V_55 = V_3 -> V_49 -> V_48 ;
F_6 ( & V_6 -> V_206 ) ;
F_7 ( & V_6 -> V_192 ) ;
V_6 -> V_8 = F_145 ( 2 , V_319 ) ;
if ( ! V_6 -> V_8 ) {
V_31 = - V_119 ;
goto V_324;
}
return 0 ;
V_324:
F_138 ( V_6 ) ;
return V_31 ;
}
