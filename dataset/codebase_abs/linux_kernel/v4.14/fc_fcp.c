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
static bool F_39 ( struct V_2 * V_3 )
{
struct V_5 * V_6 = F_2 ( V_3 ) ;
unsigned long V_47 ;
int V_48 ;
bool V_57 = false ;
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
V_57 = true ;
V_53:
F_38 ( V_3 -> V_49 -> V_50 , V_47 ) ;
return V_57 ;
}
static inline struct V_58 * F_40 ( struct V_2 * V_3 ,
T_3 V_59 )
{
struct V_58 * V_60 ;
V_60 = F_41 ( V_3 , V_59 ) ;
if ( F_42 ( V_60 ) )
return V_60 ;
F_8 ( V_3 -> V_17 , F_9 () ) -> V_61 ++ ;
F_10 () ;
F_39 ( V_3 ) ;
F_37 ( V_56 , V_3 -> V_49 ,
L_3
L_4 , V_3 -> V_49 -> V_48 ) ;
return NULL ;
}
static inline unsigned int F_43 ( struct V_1 * V_7 )
{
struct V_62 * V_63 = V_7 -> V_64 -> V_65 ;
unsigned int V_66 = V_67 ;
if ( V_63 && V_63 -> V_66 > V_66 )
V_66 = V_63 -> V_66 ;
return F_44 ( V_66 ) + V_68 ;
}
static void F_45 ( struct V_1 * V_7 , struct V_58 * V_60 )
{
struct V_69 * V_70 = V_7 -> V_44 ;
struct V_2 * V_3 = V_7 -> V_9 ;
struct V_71 * V_17 ;
struct V_72 * V_73 ;
T_3 V_74 ;
T_3 V_75 ;
T_4 V_76 ;
T_4 V_77 = 0 ;
T_3 V_59 ;
void * V_78 ;
struct V_79 * V_80 ;
T_4 V_81 ;
T_5 V_82 = V_83 ;
V_73 = F_46 ( V_60 ) ;
V_75 = F_47 ( V_73 -> V_84 ) ;
V_74 = V_75 ;
V_59 = F_48 ( V_60 ) - sizeof( * V_73 ) ;
V_78 = F_49 ( V_60 , 0 ) ;
if ( V_7 -> V_10 != V_11 ) {
F_33 ( V_7 ) ;
F_50 ( V_7 , L_5 ) ;
V_82 = V_85 ;
goto V_86;
}
if ( V_75 + V_59 > V_7 -> V_87 ) {
if ( ( F_51 ( V_60 ) & V_88 ) &&
F_52 ( V_60 ) )
goto V_89;
F_50 ( V_7 , L_6
L_7 , V_59 , V_75 , V_7 -> V_87 ) ;
V_82 = V_90 ;
goto V_86;
}
if ( V_75 != V_7 -> V_46 )
V_7 -> V_21 |= V_91 ;
V_80 = F_31 ( V_70 ) ;
V_81 = F_32 ( V_70 ) ;
if ( ! ( F_51 ( V_60 ) & V_88 ) ) {
V_77 = F_53 ( V_78 , V_59 , V_80 , & V_81 ,
& V_75 , NULL ) ;
} else {
V_76 = F_54 ( ~ 0 , ( T_5 * ) V_73 , sizeof( * V_73 ) ) ;
V_77 = F_53 ( V_78 , V_59 , V_80 , & V_81 ,
& V_75 , & V_76 ) ;
V_78 = F_49 ( V_60 , 0 ) ;
if ( V_59 % 4 )
V_76 = F_54 ( V_76 , V_78 + V_59 , 4 - ( V_59 % 4 ) ) ;
if ( ~ V_76 != F_55 ( F_56 ( V_60 ) ) ) {
V_89:
V_17 = F_8 ( V_3 -> V_17 , F_9 () ) ;
V_17 -> V_92 ++ ;
if ( V_17 -> V_93 ++ < V_94 )
F_57 ( V_95 L_8
L_9 ,
V_3 -> V_96 ) ;
F_10 () ;
if ( V_7 -> V_21 & V_91 ) {
V_82 = V_97 ;
goto V_86;
}
return;
}
}
if ( V_7 -> V_98 == V_74 )
V_7 -> V_98 += V_77 ;
V_7 -> V_46 += V_77 ;
if ( F_58 ( V_7 -> V_21 & V_99 ) &&
V_7 -> V_46 == V_7 -> V_87 - V_7 -> V_100 ) {
F_50 ( V_7 , L_10 ) ;
F_25 ( V_7 ) ;
}
return;
V_86:
F_59 ( V_7 , V_82 ) ;
}
static int F_60 ( struct V_1 * V_7 , struct V_19 * V_20 ,
T_3 V_75 , T_3 V_101 )
{
struct V_102 * V_103 ;
struct V_69 * V_70 ;
struct V_79 * V_80 ;
struct V_58 * V_60 = NULL ;
struct V_2 * V_3 = V_7 -> V_9 ;
struct V_104 * V_104 ;
T_3 V_105 ;
T_3 V_106 ;
T_3 V_107 ;
T_3 V_108 ;
T_3 V_109 , V_84 ;
T_3 V_110 ;
int error ;
void * V_14 = NULL ;
void * V_111 ;
int V_112 = V_3 -> V_113 ;
T_4 V_114 ;
F_61 ( V_101 <= 0 ) ;
if ( F_58 ( V_75 + V_101 > V_7 -> V_87 ) ) {
F_50 ( V_7 , L_11
L_12 , V_101 , V_75 ) ;
F_26 ( V_7 ) ;
return 0 ;
} else if ( V_75 != V_7 -> V_46 ) {
F_50 ( V_7 , L_13
L_14 , V_101 , V_75 ) ;
}
V_106 = V_7 -> V_115 ;
if ( V_3 -> V_116 ) {
V_106 = F_62 ( V_101 , ( T_3 ) V_3 -> V_117 ) ;
F_50 ( V_7 , L_15 ,
V_7 , V_101 , V_3 -> V_117 , V_106 ) ;
}
if ( V_106 > 512 )
V_106 &= ~ ( 512 - 1 ) ;
V_70 = V_7 -> V_44 ;
V_105 = V_101 ;
V_84 = V_109 = V_75 ;
V_107 = 0 ;
V_20 = F_63 ( V_20 ) ;
V_114 = V_118 ;
F_61 ( ! V_20 ) ;
V_80 = F_31 ( V_70 ) ;
while ( V_105 > 0 && V_80 ) {
if ( V_75 >= V_80 -> V_119 ) {
V_75 -= V_80 -> V_119 ;
V_80 = F_64 ( V_80 ) ;
continue;
}
if ( ! V_60 ) {
V_107 = F_62 ( V_106 , V_105 ) ;
if ( V_107 % 4 )
V_112 = 0 ;
V_60 = F_41 ( V_3 , V_112 ? 0 : V_107 ) ;
if ( ! V_60 )
return - V_120 ;
V_14 = F_46 ( V_60 ) + 1 ;
V_84 = V_109 ;
F_65 ( V_60 ) = V_7 -> V_115 ;
}
V_110 = V_75 + V_80 -> V_75 ;
V_108 = F_62 ( V_107 , V_80 -> V_119 - V_75 ) ;
V_108 = F_62 ( V_108 ,
( T_3 ) ( V_121 - ( V_110 & ~ V_122 ) ) ) ;
V_104 = F_66 ( V_80 ) + ( V_110 >> V_123 ) ;
if ( V_112 ) {
F_67 ( V_104 ) ;
F_68 ( F_69 ( V_60 ) ,
F_70 ( F_69 ( V_60 ) ) -> V_124 ,
V_104 , V_110 & ~ V_122 , V_108 ) ;
F_69 ( V_60 ) -> V_87 += V_108 ;
F_48 ( V_60 ) += V_108 ;
F_69 ( V_60 ) -> V_125 += V_121 ;
} else {
V_111 = F_71 ( V_104 ) ;
memcpy ( V_14 , ( char * ) V_111 + ( V_110 & ~ V_122 ) ,
V_108 ) ;
F_72 ( V_111 ) ;
V_14 += V_108 ;
}
V_75 += V_108 ;
V_109 += V_108 ;
V_107 -= V_108 ;
V_105 -= V_108 ;
if ( ( F_70 ( F_69 ( V_60 ) ) -> V_124 < V_126 ) &&
( V_107 ) )
continue;
if ( V_105 == 0 )
V_114 |= V_127 | V_128 ;
V_103 = F_73 ( V_20 ) ;
F_74 ( V_60 , V_129 , V_103 -> V_130 , V_103 -> V_131 ,
V_132 , V_114 , V_84 ) ;
error = F_75 ( V_3 , V_20 , V_60 ) ;
if ( error ) {
F_61 ( 1 ) ;
return error ;
}
V_60 = NULL ;
}
V_7 -> V_46 += V_101 ;
return 0 ;
}
static void F_76 ( struct V_1 * V_7 , struct V_58 * V_60 )
{
int V_133 = 1 ;
struct V_134 * V_135 ;
struct V_72 * V_73 ;
V_73 = F_46 ( V_60 ) ;
switch ( V_73 -> V_136 ) {
case V_137 :
break;
case V_138 :
V_135 = F_49 ( V_60 , sizeof( * V_135 ) ) ;
if ( V_135 && V_135 -> V_139 == V_140 )
break;
default:
V_133 = 0 ;
}
if ( V_133 )
F_23 ( V_7 ) ;
}
static void F_77 ( struct V_19 * V_20 , struct V_58 * V_60 , void * V_141 )
{
struct V_1 * V_7 = (struct V_1 * ) V_141 ;
struct V_2 * V_3 = V_7 -> V_9 ;
struct V_72 * V_73 ;
struct V_142 * V_143 ;
T_5 V_144 ;
int V_31 = 0 ;
if ( F_78 ( V_60 ) ) {
F_79 ( V_7 , V_60 ) ;
return;
}
V_73 = F_46 ( V_60 ) ;
V_144 = V_73 -> V_136 ;
if ( V_3 -> V_21 != V_145 ) {
F_50 ( V_7 , L_16 ,
V_3 -> V_21 , V_144 ) ;
goto V_146;
}
if ( F_17 ( V_7 ) )
goto V_146;
if ( V_73 -> V_147 == V_148 ) {
F_76 ( V_7 , V_60 ) ;
goto V_53;
}
if ( V_7 -> V_21 & ( V_27 | V_28 ) ) {
F_50 ( V_7 , L_17 , V_144 ) ;
goto V_53;
}
if ( V_144 == V_149 ) {
F_61 ( F_51 ( V_60 ) & V_88 ) ;
V_143 = F_49 ( V_60 , sizeof( * V_143 ) ) ;
F_61 ( ! V_143 ) ;
V_31 = F_60 ( V_7 , V_20 ,
( T_3 ) F_47 ( V_143 -> V_150 ) ,
( T_3 ) F_47 ( V_143 -> V_151 ) ) ;
if ( ! V_31 )
V_20 -> V_152 = V_7 -> V_46 ;
} else if ( V_144 == V_129 ) {
F_61 ( F_48 ( V_60 ) < sizeof( * V_73 ) ) ;
F_45 ( V_7 , V_60 ) ;
V_20 -> V_152 = V_7 -> V_98 ;
} else if ( V_144 == V_153 ) {
F_61 ( F_51 ( V_60 ) & V_88 ) ;
F_80 ( V_7 , V_60 ) ;
} else {
F_50 ( V_7 , L_18 , V_144 ) ;
}
V_53:
F_20 ( V_7 ) ;
V_146:
F_81 ( V_60 ) ;
}
static void F_80 ( struct V_1 * V_7 , struct V_58 * V_60 )
{
struct V_72 * V_73 ;
struct V_154 * V_155 ;
struct V_156 * V_157 ;
struct V_158 * V_159 ;
T_4 V_160 ;
T_4 V_161 ;
T_4 V_162 = 0 ;
T_4 V_163 = 0 ;
T_5 V_47 = 0 ;
V_160 = F_48 ( V_60 ) ;
V_73 = (struct V_72 * ) F_82 ( V_60 ) ;
if ( F_58 ( V_160 < sizeof( * V_73 ) + sizeof( * V_155 ) ) )
goto V_164;
V_160 -= sizeof( * V_73 ) ;
V_155 = (struct V_154 * ) ( V_73 + 1 ) ;
V_7 -> V_165 = V_155 -> V_166 ;
V_47 = V_155 -> F_51 ;
V_7 -> V_167 = V_47 ;
V_161 = V_7 -> V_87 ;
F_33 ( V_7 ) ;
if ( F_58 ( ( V_47 & ~ V_168 ) || V_155 -> V_166 ) ) {
V_157 = ( void * ) ( V_155 + 1 ) ;
if ( V_47 & ( V_169 | V_170 ) ) {
if ( V_160 < sizeof( * V_155 ) + sizeof( * V_157 ) )
goto V_164;
V_159 = (struct V_158 * ) ( V_157 + 1 ) ;
if ( V_47 & V_169 ) {
V_162 = F_47 ( V_157 -> V_171 ) ;
if ( ( V_162 != V_172 ) &&
( V_162 != V_173 ) )
goto V_164;
if ( V_7 -> V_29 ) {
V_7 -> V_165 = V_159 -> V_174 ;
F_24 ( & V_7 -> V_30 ) ;
return;
}
}
if ( V_47 & V_170 ) {
V_163 = F_47 ( V_157 -> V_175 ) ;
if ( V_163 > V_176 )
V_163 = V_176 ;
memcpy ( V_7 -> V_44 -> V_177 ,
( char * ) V_159 + V_162 , V_163 ) ;
}
}
if ( V_47 & ( V_178 | V_179 ) ) {
if ( V_160 < sizeof( * V_155 ) + sizeof( V_157 -> V_180 ) )
goto V_164;
if ( V_47 & V_178 ) {
V_7 -> V_100 = F_47 ( V_157 -> V_180 ) ;
if ( ! ( V_47 & V_170 ) &&
( V_155 -> V_166 == 0 ) &&
( F_83 ( V_7 -> V_44 ) -
V_7 -> V_100 ) < V_7 -> V_44 -> V_181 )
goto V_86;
V_161 -= V_7 -> V_100 ;
} else {
V_7 -> V_36 = V_85 ;
}
}
}
V_7 -> V_21 |= V_99 ;
if ( F_58 ( V_7 -> V_165 == V_182 &&
V_7 -> V_46 != V_161 ) ) {
if ( V_7 -> V_46 < V_161 ) {
if ( V_7 -> V_9 -> V_183 ) {
F_50 ( V_7 , L_19 ,
V_7 -> V_64 -> V_96 ) ;
return;
}
F_50 ( V_7 , L_20
L_21 ,
V_7 -> V_64 -> V_96 ,
V_7 -> V_46 , V_161 , V_7 -> V_87 ) ;
F_21 ( V_7 , F_43 ( V_7 ) ) ;
return;
}
V_7 -> V_36 = V_90 ;
F_50 ( V_7 , L_22
L_21 ,
V_7 -> V_64 -> V_96 ,
V_7 -> V_46 , V_161 , V_7 -> V_87 ) ;
}
F_25 ( V_7 ) ;
return;
V_164:
F_50 ( V_7 , L_23
L_24 , V_47 , F_48 ( V_60 ) , V_162 , V_163 ) ;
V_86:
V_7 -> V_36 = V_85 ;
F_25 ( V_7 ) ;
}
static void F_25 ( struct V_1 * V_7 )
{
struct V_2 * V_3 = V_7 -> V_9 ;
struct V_19 * V_20 ;
struct V_102 * V_103 ;
T_4 V_114 ;
if ( V_7 -> V_21 & V_28 )
return;
if ( V_7 -> V_21 & V_27 ) {
if ( ! V_7 -> V_36 )
V_7 -> V_36 = V_184 ;
} else {
if ( V_7 -> V_165 == V_182 &&
V_7 -> V_46 < V_7 -> V_87 && ! V_7 -> V_37 &&
( ! ( V_7 -> V_167 & V_178 ) ||
V_7 -> V_46 < V_7 -> V_87 - V_7 -> V_100 ) ) {
F_50 ( V_7 , L_25 ,
V_7 -> V_46 , V_7 -> V_87 ) ;
V_7 -> V_36 = V_185 ;
}
}
V_20 = V_7 -> V_32 ;
if ( V_20 ) {
V_7 -> V_32 = NULL ;
if ( F_58 ( V_7 -> V_167 & V_168 ) ) {
struct V_58 * V_186 ;
struct V_19 * V_187 ;
V_187 = F_63 ( V_20 ) ;
V_186 = F_40 ( V_7 -> V_9 , 0 ) ;
if ( V_186 ) {
V_114 = V_127 ;
V_114 |= V_188 | V_128 ;
V_103 = F_73 ( V_20 ) ;
F_74 ( V_186 , V_189 ,
V_103 -> V_130 , V_103 -> V_131 ,
V_132 , V_114 , 0 ) ;
F_75 ( V_3 , V_187 , V_186 ) ;
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
static void F_86 ( struct V_2 * V_3 , unsigned int V_190 ,
unsigned int V_191 , int error )
{
struct V_5 * V_6 = F_2 ( V_3 ) ;
struct V_1 * V_7 ;
struct V_69 * V_192 ;
unsigned long V_47 ;
F_35 ( & V_6 -> V_193 , V_47 ) ;
V_194:
F_87 (fsp, &si->scsi_pkt_queue, list) {
V_192 = V_7 -> V_44 ;
if ( V_190 != - 1 && F_88 ( V_192 ) != V_190 )
continue;
if ( V_191 != - 1 && V_192 -> V_195 -> V_191 != V_191 )
continue;
F_14 ( V_7 ) ;
F_38 ( & V_6 -> V_193 , V_47 ) ;
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
F_35 ( & V_6 -> V_193 , V_47 ) ;
goto V_194;
}
F_38 ( & V_6 -> V_193 , V_47 ) ;
}
static void F_89 ( struct V_2 * V_3 )
{
F_86 ( V_3 , - 1 , - 1 , V_196 ) ;
}
static int F_90 ( struct V_2 * V_3 , struct V_1 * V_7 )
{
struct V_5 * V_6 = F_2 ( V_3 ) ;
unsigned long V_47 ;
int V_31 ;
V_7 -> V_44 -> V_197 . V_198 = ( char * ) V_7 ;
V_7 -> V_199 . V_200 = F_91 ( V_7 -> V_87 ) ;
V_7 -> V_199 . V_201 = V_7 -> V_39 & ~ V_202 ;
F_92 ( V_7 -> V_44 -> V_195 -> V_191 , & V_7 -> V_199 . V_203 ) ;
memcpy ( V_7 -> V_199 . V_204 , V_7 -> V_44 -> V_205 , V_7 -> V_44 -> V_206 ) ;
F_35 ( & V_6 -> V_193 , V_47 ) ;
F_93 ( & V_7 -> V_15 , & V_6 -> V_207 ) ;
F_38 ( & V_6 -> V_193 , V_47 ) ;
V_31 = V_3 -> V_42 . V_208 ( V_3 , V_7 , F_77 ) ;
if ( F_58 ( V_31 ) ) {
F_35 ( & V_6 -> V_193 , V_47 ) ;
V_7 -> V_44 -> V_197 . V_198 = NULL ;
F_94 ( & V_7 -> V_15 ) ;
F_38 ( & V_6 -> V_193 , V_47 ) ;
}
return V_31 ;
}
static int F_95 ( struct V_2 * V_3 , struct V_1 * V_7 ,
void (* F_96)( struct V_19 * ,
struct V_58 * V_60 ,
void * V_141 ) )
{
struct V_58 * V_60 ;
struct V_19 * V_20 ;
struct V_209 * V_64 ;
struct V_62 * V_63 ;
const T_3 V_59 = sizeof( V_7 -> V_199 ) ;
int V_31 = 0 ;
if ( F_17 ( V_7 ) )
return 0 ;
V_60 = F_40 ( V_3 , sizeof( V_7 -> V_199 ) ) ;
if ( ! V_60 ) {
V_31 = - 1 ;
goto V_53;
}
memcpy ( F_49 ( V_60 , V_59 ) , & V_7 -> V_199 , V_59 ) ;
F_97 ( V_60 ) = V_7 ;
V_64 = V_7 -> V_64 ;
V_7 -> V_115 = V_64 -> V_210 ;
V_63 = V_64 -> V_65 ;
F_74 ( V_60 , V_211 , V_64 -> V_96 ,
V_63 -> V_212 -> V_96 , V_132 ,
V_213 , 0 ) ;
V_20 = F_98 ( V_3 , V_60 , F_96 , F_16 , V_7 , 0 ) ;
if ( ! V_20 ) {
V_31 = - 1 ;
goto V_53;
}
V_7 -> V_32 = V_20 ;
F_14 ( V_7 ) ;
F_99 ( & V_7 -> V_13 , V_214 , ( unsigned long ) V_7 ) ;
if ( V_63 -> V_47 & V_215 )
F_21 ( V_7 , F_43 ( V_7 ) ) ;
V_53:
F_20 ( V_7 ) ;
return V_31 ;
}
static void F_79 ( struct V_1 * V_7 , struct V_58 * V_60 )
{
int error = F_100 ( V_60 ) ;
if ( F_17 ( V_7 ) )
return;
if ( error == - V_216 ) {
F_28 ( V_7 , V_85 ) ;
goto V_53;
}
V_7 -> V_21 &= ~ V_28 ;
V_7 -> V_36 = V_217 ;
F_25 ( V_7 ) ;
V_53:
F_20 ( V_7 ) ;
}
static int F_101 ( struct V_1 * V_7 )
{
int V_31 = V_218 ;
unsigned long V_219 ;
F_50 ( V_7 , L_26 , V_7 -> V_21 ) ;
if ( F_26 ( V_7 ) ) {
F_50 ( V_7 , L_27 ) ;
return V_218 ;
}
if ( V_7 -> V_21 & V_27 ) {
F_50 ( V_7 , L_28 ) ;
return V_220 ;
}
F_102 ( & V_7 -> V_30 ) ;
V_7 -> V_29 = 1 ;
F_19 ( & V_7 -> V_16 ) ;
V_219 = F_103 ( & V_7 -> V_30 ,
V_221 ) ;
F_18 ( & V_7 -> V_16 ) ;
V_7 -> V_29 = 0 ;
if ( ! V_219 ) {
F_50 ( V_7 , L_29 ) ;
} else if ( V_7 -> V_21 & V_27 ) {
F_50 ( V_7 , L_30 ) ;
V_31 = V_220 ;
F_25 ( V_7 ) ;
}
return V_31 ;
}
static void F_104 ( unsigned long V_14 )
{
struct V_1 * V_7 = (struct V_1 * ) V_14 ;
struct V_2 * V_3 = V_7 -> V_9 ;
if ( V_3 -> V_42 . V_208 ( V_3 , V_7 , V_222 ) ) {
if ( V_7 -> V_223 ++ >= V_224 )
return;
if ( F_17 ( V_7 ) )
return;
F_99 ( & V_7 -> V_13 , F_104 , ( unsigned long ) V_7 ) ;
F_21 ( V_7 , F_43 ( V_7 ) ) ;
F_20 ( V_7 ) ;
}
}
static int F_105 ( struct V_2 * V_3 , struct V_1 * V_7 ,
unsigned int V_190 , unsigned int V_191 )
{
int V_31 ;
V_7 -> V_199 . V_200 = F_91 ( V_7 -> V_87 ) ;
V_7 -> V_199 . V_225 = V_226 ;
F_92 ( V_191 , & V_7 -> V_199 . V_203 ) ;
V_7 -> V_29 = 1 ;
F_102 ( & V_7 -> V_30 ) ;
F_104 ( ( unsigned long ) V_7 ) ;
V_31 = F_103 ( & V_7 -> V_30 , V_221 ) ;
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
return V_218 ;
}
if ( V_7 -> V_165 != V_227 )
return V_218 ;
F_107 ( V_3 , L_32 , V_191 ) ;
F_86 ( V_3 , V_190 , V_191 , V_184 ) ;
return V_220 ;
}
static void V_222 ( struct V_19 * V_20 , struct V_58 * V_60 , void * V_141 )
{
struct V_1 * V_7 = V_141 ;
struct V_72 * V_73 ;
if ( F_78 ( V_60 ) ) {
return;
}
if ( F_17 ( V_7 ) )
goto V_146;
if ( ! V_7 -> V_32 || ! V_7 -> V_29 )
goto V_228;
V_73 = F_46 ( V_60 ) ;
if ( V_73 -> V_147 != V_148 )
F_80 ( V_7 , V_60 ) ;
V_7 -> V_32 = NULL ;
F_29 ( V_20 ) ;
V_228:
F_20 ( V_7 ) ;
V_146:
F_81 ( V_60 ) ;
}
static void F_108 ( struct V_2 * V_3 )
{
F_86 ( V_3 , - 1 , - 1 , V_85 ) ;
}
static void V_214 ( unsigned long V_14 )
{
struct V_1 * V_7 = (struct V_1 * ) V_14 ;
struct V_209 * V_64 = V_7 -> V_64 ;
struct V_62 * V_63 = V_64 -> V_65 ;
if ( F_17 ( V_7 ) )
return;
if ( V_7 -> V_199 . V_225 )
goto V_53;
if ( V_7 -> V_9 -> V_183 ) {
F_50 ( V_7 , L_33 ,
V_7 -> V_26 ) ;
F_99 ( & V_7 -> V_13 , V_214 , ( unsigned long ) V_7 ) ;
F_21 ( V_7 , V_7 -> V_26 ) ;
goto V_53;
}
F_50 ( V_7 , L_34 ,
V_7 -> V_26 , V_63 -> V_47 , V_7 -> V_21 ) ;
V_7 -> V_21 |= V_229 ;
if ( V_63 -> V_47 & V_215 )
F_109 ( V_7 ) ;
else if ( V_7 -> V_21 & V_99 )
F_25 ( V_7 ) ;
else
F_59 ( V_7 , V_230 ) ;
V_7 -> V_21 &= ~ V_229 ;
V_53:
F_20 ( V_7 ) ;
}
static void F_109 ( struct V_1 * V_7 )
{
struct V_2 * V_3 ;
struct V_58 * V_60 ;
struct V_209 * V_64 ;
struct V_62 * V_63 ;
V_3 = V_7 -> V_9 ;
V_64 = V_7 -> V_64 ;
V_63 = V_64 -> V_65 ;
if ( ! V_7 -> V_32 || V_63 -> V_231 != V_232 ) {
V_7 -> V_36 = V_196 ;
V_7 -> V_37 = 0 ;
F_25 ( V_7 ) ;
return;
}
V_60 = F_40 ( V_3 , sizeof( struct V_233 ) ) ;
if ( ! V_60 )
goto V_234;
F_110 ( V_60 ) = V_7 -> V_32 ;
F_74 ( V_60 , V_235 , V_64 -> V_96 ,
V_63 -> V_212 -> V_96 , V_236 ,
V_213 , 0 ) ;
if ( V_3 -> V_42 . V_237 ( V_3 , V_64 -> V_96 , V_60 , V_238 ,
V_239 , V_7 ,
2 * V_3 -> V_240 ) ) {
F_14 ( V_7 ) ;
return;
}
V_234:
if ( V_7 -> V_223 ++ < V_224 )
F_21 ( V_7 , F_43 ( V_7 ) ) ;
else
F_59 ( V_7 , V_230 ) ;
}
static void V_239 ( struct V_19 * V_20 , struct V_58 * V_60 , void * V_141 )
{
struct V_1 * V_7 = (struct V_1 * ) V_141 ;
struct V_241 * V_242 ;
struct V_243 * V_244 ;
T_4 V_245 ;
T_5 V_246 ;
T_4 V_75 ;
enum V_247 V_248 ;
enum V_249 V_144 ;
struct V_62 * V_63 ;
if ( F_78 ( V_60 ) ) {
F_111 ( V_7 , V_60 ) ;
return;
}
if ( F_17 ( V_7 ) )
goto V_146;
V_7 -> V_223 = 0 ;
V_246 = F_112 ( V_60 ) ;
if ( V_246 == V_250 ) {
V_244 = F_49 ( V_60 , sizeof( * V_244 ) ) ;
switch ( V_244 -> V_251 ) {
default:
F_50 ( V_7 ,
L_35 ,
V_7 -> V_64 -> V_96 , V_244 -> V_251 ,
V_244 -> V_252 ) ;
case V_253 :
F_50 ( V_7 , L_36 ) ;
V_63 = V_7 -> V_64 -> V_65 ;
V_63 -> V_47 &= ~ V_215 ;
break;
case V_254 :
case V_255 :
F_50 ( V_7 , L_37 ,
V_7 -> V_64 -> V_96 , V_244 -> V_251 ,
V_244 -> V_252 ) ;
if ( V_244 -> V_252 == V_256 ) {
struct V_102 * V_103 = F_73 ( V_7 -> V_32 ) ;
V_103 -> V_21 |= V_257 ;
V_7 -> V_21 |= V_27 ;
F_28 ( V_7 , V_258 ) ;
break;
}
F_59 ( V_7 , V_258 ) ;
break;
}
} else if ( V_246 == V_259 ) {
if ( V_7 -> V_21 & V_27 )
goto V_260;
V_248 = V_7 -> V_44 -> V_261 ;
V_242 = F_49 ( V_60 , sizeof( * V_242 ) ) ;
V_75 = F_47 ( V_242 -> V_262 ) ;
V_245 = F_47 ( V_242 -> V_263 ) ;
if ( V_245 & V_264 ) {
if ( V_248 == V_265 ) {
V_144 = V_153 ;
} else if ( V_7 -> V_98 == V_75 ) {
V_144 = V_153 ;
} else {
V_75 = V_7 -> V_98 ;
V_144 = V_129 ;
}
F_113 ( V_7 , V_144 , V_75 ) ;
} else if ( V_245 & V_266 ) {
F_21 ( V_7 , F_43 ( V_7 ) ) ;
} else {
V_144 = V_129 ;
if ( V_248 == V_265 ) {
V_144 = V_153 ;
if ( V_75 < V_7 -> V_87 )
V_144 = V_149 ;
} else if ( V_75 == V_7 -> V_98 ) {
V_144 = V_153 ;
} else if ( V_7 -> V_98 < V_75 ) {
V_75 = V_7 -> V_98 ;
}
F_113 ( V_7 , V_144 , V_75 ) ;
}
}
V_260:
F_20 ( V_7 ) ;
V_146:
F_11 ( V_7 ) ;
F_81 ( V_60 ) ;
}
static void F_111 ( struct V_1 * V_7 , struct V_58 * V_60 )
{
int error = F_100 ( V_60 ) ;
if ( F_17 ( V_7 ) )
goto V_146;
switch ( error ) {
case - V_216 :
F_50 ( V_7 , L_38 ,
V_7 , V_7 -> V_64 -> V_96 ) ;
F_28 ( V_7 , V_85 ) ;
break;
default:
F_50 ( V_7 , L_39 ,
V_7 , V_7 -> V_64 -> V_96 , error ) ;
V_7 -> V_36 = V_217 ;
case - V_267 :
F_50 ( V_7 , L_40 ,
V_7 , V_7 -> V_64 -> V_96 , V_7 -> V_223 ,
V_224 ) ;
if ( V_7 -> V_223 ++ < V_224 )
F_109 ( V_7 ) ;
else
F_59 ( V_7 , V_85 ) ;
break;
}
F_20 ( V_7 ) ;
V_146:
F_11 ( V_7 ) ;
}
static void F_59 ( struct V_1 * V_7 , T_5 V_268 )
{
F_50 ( V_7 , L_41 , V_268 ) ;
V_7 -> V_36 = V_268 ;
V_7 -> V_165 = 0 ;
V_7 -> V_37 = 0 ;
F_26 ( V_7 ) ;
}
static void F_113 ( struct V_1 * V_7 , enum V_249 V_144 , T_4 V_75 )
{
struct V_2 * V_3 = V_7 -> V_9 ;
struct V_209 * V_64 ;
struct V_62 * V_63 ;
struct V_102 * V_103 = F_73 ( V_7 -> V_32 ) ;
struct V_19 * V_20 ;
struct V_269 * V_270 ;
struct V_58 * V_60 ;
V_64 = V_7 -> V_64 ;
V_63 = V_64 -> V_65 ;
if ( ! ( V_63 -> V_47 & V_271 ) ||
V_63 -> V_231 != V_232 )
goto V_234;
V_60 = F_40 ( V_3 , sizeof( * V_270 ) ) ;
if ( ! V_60 )
goto V_234;
V_270 = F_49 ( V_60 , sizeof( * V_270 ) ) ;
memset ( V_270 , 0 , sizeof( * V_270 ) ) ;
V_270 -> V_272 = V_273 ;
V_270 -> V_274 = F_114 ( V_103 -> V_275 ) ;
V_270 -> V_276 = F_114 ( V_103 -> V_277 ) ;
V_270 -> V_278 = V_144 ;
V_270 -> V_279 = F_91 ( V_75 ) ;
F_74 ( V_60 , V_280 , V_64 -> V_96 ,
V_63 -> V_212 -> V_96 , V_132 ,
V_213 , 0 ) ;
V_20 = F_98 ( V_3 , V_60 , V_281 ,
F_16 ,
V_7 , F_43 ( V_7 ) ) ;
if ( ! V_20 )
goto V_234;
V_7 -> V_282 = V_20 ;
V_7 -> V_46 = V_75 ;
V_7 -> V_98 = V_75 ;
V_7 -> V_21 &= ~ V_99 ;
F_14 ( V_7 ) ;
return;
V_234:
F_28 ( V_7 , V_258 ) ;
}
static void V_281 ( struct V_19 * V_20 , struct V_58 * V_60 , void * V_141 )
{
struct V_1 * V_7 = V_141 ;
struct V_72 * V_73 ;
if ( F_78 ( V_60 ) ) {
F_115 ( V_7 , V_60 ) ;
return;
}
if ( F_17 ( V_7 ) )
goto V_146;
V_73 = F_46 ( V_60 ) ;
if ( V_73 -> V_147 == V_148 ) {
F_20 ( V_7 ) ;
return;
}
switch ( F_112 ( V_60 ) ) {
case V_259 :
V_7 -> V_223 = 0 ;
F_21 ( V_7 , F_43 ( V_7 ) ) ;
break;
case V_250 :
default:
F_59 ( V_7 , V_85 ) ;
break;
}
F_20 ( V_7 ) ;
V_146:
F_29 ( V_20 ) ;
F_81 ( V_60 ) ;
}
static void F_115 ( struct V_1 * V_7 , struct V_58 * V_60 )
{
if ( F_17 ( V_7 ) )
goto V_146;
switch ( F_100 ( V_60 ) ) {
case - V_267 :
F_50 ( V_7 , L_42 , V_7 -> V_223 ) ;
if ( V_7 -> V_223 ++ < V_224 )
F_109 ( V_7 ) ;
else
F_59 ( V_7 , V_230 ) ;
break;
case - V_216 :
F_50 ( V_7 , L_43 ) ;
default:
F_28 ( V_7 , V_85 ) ;
break;
}
F_20 ( V_7 ) ;
V_146:
F_29 ( V_7 -> V_282 ) ;
}
static inline int F_116 ( struct V_2 * V_3 )
{
return ( V_3 -> V_21 == V_145 ) &&
V_3 -> V_283 && ! V_3 -> V_183 ;
}
int F_117 ( struct V_284 * V_285 , struct V_69 * V_192 )
{
struct V_2 * V_3 = F_118 ( V_285 ) ;
struct V_209 * V_64 = F_119 ( F_120 ( V_192 -> V_195 ) ) ;
struct V_1 * V_7 ;
struct V_62 * V_63 ;
int V_286 ;
int V_31 = 0 ;
struct V_71 * V_17 ;
V_286 = F_121 ( V_64 ) ;
if ( V_286 ) {
V_192 -> V_287 = V_286 ;
V_192 -> V_288 ( V_192 ) ;
return 0 ;
}
if ( ! * (struct V_289 * * ) V_64 -> V_65 ) {
V_192 -> V_287 = V_290 << 16 ;
V_192 -> V_288 ( V_192 ) ;
goto V_146;
}
V_63 = V_64 -> V_65 ;
if ( ! F_116 ( V_3 ) ) {
if ( V_3 -> V_183 ) {
if ( F_39 ( V_3 ) )
F_37 ( V_56 , V_3 -> V_49 ,
L_44
L_4 ,
V_3 -> V_49 -> V_48 ) ;
}
V_31 = V_291 ;
goto V_146;
}
V_7 = F_1 ( V_3 , V_292 ) ;
if ( V_7 == NULL ) {
V_31 = V_291 ;
goto V_146;
}
V_7 -> V_44 = V_192 ;
V_7 -> V_64 = V_64 ;
V_7 -> V_87 = F_83 ( V_192 ) ;
V_7 -> V_46 = 0 ;
V_17 = F_8 ( V_3 -> V_17 , F_9 () ) ;
if ( V_192 -> V_261 == V_293 ) {
V_7 -> V_39 = V_40 ;
V_17 -> V_294 ++ ;
V_17 -> V_295 += V_7 -> V_87 ;
} else if ( V_192 -> V_261 == V_265 ) {
V_7 -> V_39 = V_296 ;
V_17 -> V_297 ++ ;
V_17 -> V_298 += V_7 -> V_87 ;
} else {
V_7 -> V_39 = 0 ;
V_17 -> V_299 ++ ;
}
F_10 () ;
V_286 = F_90 ( V_3 , V_7 ) ;
if ( V_286 != 0 ) {
V_7 -> V_21 = V_300 ;
F_11 ( V_7 ) ;
V_31 = V_291 ;
}
V_146:
return V_31 ;
}
static void F_84 ( struct V_1 * V_7 )
{
struct V_5 * V_6 ;
struct V_69 * V_192 ;
struct V_2 * V_3 ;
unsigned long V_47 ;
F_33 ( V_7 ) ;
V_7 -> V_21 |= V_22 ;
if ( ! ( V_7 -> V_21 & V_229 ) ) {
F_19 ( & V_7 -> V_16 ) ;
F_106 ( & V_7 -> V_13 ) ;
F_18 ( & V_7 -> V_16 ) ;
}
V_3 = V_7 -> V_9 ;
V_6 = F_2 ( V_3 ) ;
if ( V_6 -> V_54 )
F_34 ( V_3 ) ;
V_192 = V_7 -> V_44 ;
F_122 ( V_192 ) = V_7 -> V_165 ;
switch ( V_7 -> V_36 ) {
case V_83 :
if ( V_7 -> V_165 == 0 ) {
V_192 -> V_287 = V_301 << 16 ;
if ( V_7 -> V_100 )
F_123 ( V_192 ) = V_7 -> V_100 ;
} else {
V_192 -> V_287 = ( V_301 << 16 ) | V_7 -> V_165 ;
}
break;
case V_85 :
F_50 ( V_7 , L_45
L_46 ) ;
V_192 -> V_287 = V_302 << 16 ;
break;
case V_185 :
if ( ( V_7 -> V_165 == 0 ) && ! ( V_7 -> V_39 & V_40 ) ) {
if ( V_7 -> V_21 & V_99 ) {
V_192 -> V_287 = V_301 << 16 ;
} else {
F_50 ( V_7 , L_47
L_48 ) ;
V_192 -> V_287 = V_302 << 16 ;
}
} else {
F_50 ( V_7 , L_45
L_49 ) ;
F_123 ( V_192 ) = V_7 -> V_100 ;
V_192 -> V_287 = ( V_302 << 16 ) | V_7 -> V_165 ;
}
break;
case V_90 :
F_50 ( V_7 , L_45
L_50 ) ;
V_192 -> V_287 = ( V_302 << 16 ) | V_7 -> V_165 ;
break;
case V_184 :
if ( F_124 ( V_192 -> V_287 ) == V_303 )
F_50 ( V_7 , L_51
L_52 ) ;
else {
F_50 ( V_7 , L_45
L_52 ) ;
F_125 ( V_192 , V_302 ) ;
}
V_192 -> V_287 |= V_7 -> V_37 ;
break;
case V_304 :
F_50 ( V_7 , L_53
L_54 ) ;
V_192 -> V_287 = ( V_305 << 16 ) ;
break;
case V_258 :
F_50 ( V_7 , L_55
L_56 ) ;
V_192 -> V_287 = ( V_306 << 16 ) ;
break;
case V_196 :
F_50 ( V_7 , L_57
L_58 ) ;
V_192 -> V_287 = ( V_307 << 16 ) ;
break;
case V_97 :
F_50 ( V_7 , L_59
L_60 ) ;
V_192 -> V_287 = ( V_308 << 16 ) ;
break;
case V_230 :
F_50 ( V_7 , L_61
L_62 ) ;
V_192 -> V_287 = ( V_309 << 16 ) | V_7 -> V_37 ;
break;
default:
F_50 ( V_7 , L_45
L_63 ) ;
V_192 -> V_287 = ( V_302 << 16 ) ;
break;
}
if ( V_3 -> V_21 != V_145 && V_7 -> V_36 != V_83 )
V_192 -> V_287 = ( V_310 << 16 ) ;
F_35 ( & V_6 -> V_193 , V_47 ) ;
F_94 ( & V_7 -> V_15 ) ;
V_192 -> V_197 . V_198 = NULL ;
F_38 ( & V_6 -> V_193 , V_47 ) ;
V_192 -> V_288 ( V_192 ) ;
F_11 ( V_7 ) ;
}
int F_126 ( struct V_69 * V_192 )
{
struct V_1 * V_7 ;
struct V_2 * V_3 ;
struct V_5 * V_6 ;
int V_31 = V_218 ;
unsigned long V_47 ;
int V_286 ;
V_286 = F_127 ( V_192 ) ;
if ( V_286 )
return V_286 ;
V_3 = F_118 ( V_192 -> V_195 -> V_49 ) ;
if ( V_3 -> V_21 != V_145 )
return V_31 ;
else if ( ! V_3 -> V_283 )
return V_31 ;
V_6 = F_2 ( V_3 ) ;
F_35 ( & V_6 -> V_193 , V_47 ) ;
V_7 = F_128 ( V_192 ) ;
if ( ! V_7 ) {
F_38 ( & V_6 -> V_193 , V_47 ) ;
return V_220 ;
}
F_14 ( V_7 ) ;
F_38 ( & V_6 -> V_193 , V_47 ) ;
if ( F_17 ( V_7 ) ) {
V_31 = V_220 ;
goto V_311;
}
V_31 = F_101 ( V_7 ) ;
F_20 ( V_7 ) ;
V_311:
F_11 ( V_7 ) ;
return V_31 ;
}
int F_129 ( struct V_69 * V_192 )
{
struct V_2 * V_3 ;
struct V_1 * V_7 ;
struct V_209 * V_64 = F_119 ( F_120 ( V_192 -> V_195 ) ) ;
int V_31 = V_218 ;
int V_286 ;
V_286 = F_127 ( V_192 ) ;
if ( V_286 )
return V_286 ;
V_3 = F_118 ( V_192 -> V_195 -> V_49 ) ;
if ( V_3 -> V_21 != V_145 )
return V_31 ;
F_107 ( V_3 , L_64 , V_64 -> V_96 ) ;
V_7 = F_1 ( V_3 , V_312 ) ;
if ( V_7 == NULL ) {
F_57 ( V_95 L_65 ) ;
goto V_146;
}
V_7 -> V_64 = V_64 ;
V_31 = F_105 ( V_3 , V_7 , F_88 ( V_192 ) , V_192 -> V_195 -> V_191 ) ;
V_7 -> V_21 = V_300 ;
F_11 ( V_7 ) ;
V_146:
return V_31 ;
}
int F_130 ( struct V_69 * V_192 )
{
struct V_284 * V_285 = V_192 -> V_195 -> V_49 ;
struct V_2 * V_3 = F_118 ( V_285 ) ;
unsigned long V_313 ;
F_107 ( V_3 , L_66 ) ;
F_131 ( V_3 ) ;
V_313 = V_25 + V_314 ;
while ( ! F_116 ( V_3 ) && F_36 ( V_25 ,
V_313 ) )
F_132 ( 1000 ) ;
if ( F_116 ( V_3 ) ) {
F_37 ( V_315 , V_285 , L_67
L_68 , V_3 -> V_96 ) ;
return V_220 ;
} else {
F_37 ( V_315 , V_285 , L_69
L_70 ,
V_3 -> V_96 ) ;
return V_218 ;
}
}
int F_133 ( struct V_316 * V_317 )
{
struct V_209 * V_64 = F_119 ( F_120 ( V_317 ) ) ;
if ( ! V_64 || F_121 ( V_64 ) )
return - V_35 ;
F_134 ( V_317 , V_318 ) ;
return 0 ;
}
void F_135 ( struct V_2 * V_3 )
{
struct V_5 * V_6 = F_2 ( V_3 ) ;
if ( ! F_136 ( & V_6 -> V_207 ) )
F_57 ( V_56 L_71
L_72 , V_3 -> V_96 ) ;
F_137 ( V_6 -> V_8 ) ;
F_138 ( V_6 ) ;
V_3 -> V_319 = NULL ;
}
int F_139 ( void )
{
int V_31 = 0 ;
V_320 = F_140 ( L_73 ,
sizeof( struct V_1 ) ,
0 , V_321 , NULL ) ;
if ( ! V_320 ) {
F_57 ( V_56 L_74
L_75 ) ;
V_31 = - V_120 ;
}
return V_31 ;
}
void F_141 ( void )
{
if ( V_320 )
F_142 ( V_320 ) ;
}
int F_143 ( struct V_2 * V_3 )
{
int V_31 ;
struct V_5 * V_6 ;
if ( ! V_3 -> V_42 . V_208 )
V_3 -> V_42 . V_208 = F_95 ;
if ( ! V_3 -> V_42 . V_322 )
V_3 -> V_42 . V_322 = F_108 ;
if ( ! V_3 -> V_42 . V_323 )
V_3 -> V_42 . V_323 = F_89 ;
V_6 = F_144 ( sizeof( struct V_5 ) , V_324 ) ;
if ( ! V_6 )
return - V_120 ;
V_3 -> V_319 = V_6 ;
V_6 -> V_55 = V_3 -> V_49 -> V_48 ;
F_6 ( & V_6 -> V_207 ) ;
F_7 ( & V_6 -> V_193 ) ;
V_6 -> V_8 = F_145 ( 2 , V_320 ) ;
if ( ! V_6 -> V_8 ) {
V_31 = - V_120 ;
goto V_325;
}
return 0 ;
V_325:
F_138 ( V_6 ) ;
return V_31 ;
}
