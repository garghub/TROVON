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
F_6 ( & V_7 -> V_14 ) ;
F_7 ( & V_7 -> V_15 ) ;
}
return V_7 ;
}
static void F_8 ( struct V_1 * V_7 )
{
if ( F_9 ( & V_7 -> V_12 ) ) {
struct V_5 * V_6 = F_2 ( V_7 -> V_9 ) ;
F_10 ( V_7 , V_6 -> V_8 ) ;
}
}
static void F_11 ( struct V_1 * V_7 )
{
F_12 ( & V_7 -> V_12 ) ;
}
static void F_13 ( struct V_16 * V_17 , void * V_7 )
{
F_8 ( V_7 ) ;
}
static inline int F_14 ( struct V_1 * V_7 )
{
F_15 ( & V_7 -> V_15 ) ;
if ( V_7 -> V_18 & V_19 ) {
F_16 ( & V_7 -> V_15 ) ;
return - V_20 ;
}
F_11 ( V_7 ) ;
return 0 ;
}
static inline void F_17 ( struct V_1 * V_7 )
{
F_16 ( & V_7 -> V_15 ) ;
F_8 ( V_7 ) ;
}
static void F_18 ( struct V_1 * V_7 , unsigned long V_21 )
{
if ( ! ( V_7 -> V_18 & V_19 ) )
F_19 ( & V_7 -> V_13 , V_22 + V_21 ) ;
}
static int F_20 ( struct V_1 * V_7 )
{
if ( ! V_7 -> V_23 )
return - V_24 ;
V_7 -> V_18 |= V_25 ;
return V_7 -> V_9 -> V_26 . V_27 ( V_7 -> V_23 , 0 ) ;
}
static void F_21 ( struct V_1 * V_7 )
{
if ( V_7 -> V_23 ) {
V_7 -> V_9 -> V_26 . V_28 ( V_7 -> V_23 ) ;
V_7 -> V_23 = NULL ;
}
V_7 -> V_18 &= ~ V_25 ;
V_7 -> V_29 = 0 ;
V_7 -> V_30 = V_31 ;
F_22 ( V_7 ) ;
}
void F_23 ( struct V_1 * V_7 , T_2 V_32 )
{
struct V_2 * V_3 ;
V_3 = V_7 -> V_9 ;
if ( ( V_7 -> V_33 & V_34 ) &&
( V_3 -> V_35 ) && ( V_3 -> V_26 . V_36 ) ) {
if ( V_3 -> V_26 . V_36 ( V_3 , V_32 , F_24 ( V_7 -> V_37 ) ,
F_25 ( V_7 -> V_37 ) ) )
V_7 -> V_10 = V_32 ;
}
}
void F_26 ( struct V_1 * V_7 )
{
struct V_2 * V_3 ;
if ( ! V_7 )
return;
if ( V_7 -> V_10 == V_11 )
return;
V_3 = V_7 -> V_9 ;
if ( V_3 -> V_26 . V_38 ) {
V_7 -> V_39 = V_3 -> V_26 . V_38 ( V_3 , V_7 -> V_10 ) ;
V_7 -> V_10 = V_11 ;
}
}
static void F_27 ( struct V_2 * V_3 )
{
struct V_5 * V_6 = F_2 ( V_3 ) ;
unsigned long V_40 ;
int V_41 ;
F_28 ( V_3 -> V_42 -> V_43 , V_40 ) ;
if ( V_6 -> V_44 &&
( F_29 ( V_22 , V_6 -> V_44 +
V_45 ) ) )
goto V_46;
if ( F_29 ( V_22 , V_6 -> V_47 +
V_45 ) )
goto V_46;
V_6 -> V_44 = V_22 ;
V_41 = V_3 -> V_42 -> V_41 << 1 ;
if ( V_41 >= V_6 -> V_48 ) {
V_41 = V_6 -> V_48 ;
V_6 -> V_47 = 0 ;
}
V_3 -> V_42 -> V_41 = V_41 ;
F_30 ( V_49 , V_3 -> V_42 , L_1
L_2 , V_41 ) ;
V_46:
F_31 ( V_3 -> V_42 -> V_43 , V_40 ) ;
}
static void F_32 ( struct V_2 * V_3 )
{
struct V_5 * V_6 = F_2 ( V_3 ) ;
unsigned long V_40 ;
int V_41 ;
F_28 ( V_3 -> V_42 -> V_43 , V_40 ) ;
if ( V_6 -> V_47 &&
( F_29 ( V_22 , V_6 -> V_47 +
V_45 ) ) )
goto V_46;
V_6 -> V_47 = V_22 ;
V_41 = V_3 -> V_42 -> V_41 ;
V_41 >>= 1 ;
if ( ! V_41 )
V_41 = 1 ;
V_3 -> V_42 -> V_41 = V_41 ;
F_30 ( V_49 , V_3 -> V_42 , L_3
L_4 , V_41 ) ;
V_46:
F_31 ( V_3 -> V_42 -> V_43 , V_40 ) ;
}
static inline struct V_50 * F_33 ( struct V_2 * V_3 ,
T_3 V_51 )
{
struct V_50 * V_52 ;
V_52 = F_34 ( V_3 , V_51 ) ;
if ( F_35 ( V_52 ) )
return V_52 ;
F_32 ( V_3 ) ;
return NULL ;
}
static void F_36 ( struct V_1 * V_7 , struct V_50 * V_52 )
{
struct V_53 * V_54 = V_7 -> V_37 ;
struct V_2 * V_3 = V_7 -> V_9 ;
struct V_55 * V_56 ;
struct V_57 * V_58 ;
T_3 V_59 ;
T_3 V_60 ;
T_4 V_61 ;
T_4 V_62 = 0 ;
T_3 V_51 ;
void * V_63 ;
struct V_64 * V_65 ;
T_4 V_66 ;
T_5 V_67 = V_68 ;
V_58 = F_37 ( V_52 ) ;
V_60 = F_38 ( V_58 -> V_69 ) ;
V_59 = V_60 ;
V_51 = F_39 ( V_52 ) - sizeof( * V_58 ) ;
V_63 = F_40 ( V_52 , 0 ) ;
if ( V_7 -> V_10 != V_11 ) {
F_26 ( V_7 ) ;
F_41 ( V_7 , L_5 ) ;
V_67 = V_31 ;
goto V_70;
}
if ( V_60 + V_51 > V_7 -> V_71 ) {
if ( ( F_42 ( V_52 ) & V_72 ) &&
F_43 ( V_52 ) )
goto V_73;
F_41 ( V_7 , L_6
L_7 , V_51 , V_60 , V_7 -> V_71 ) ;
V_67 = V_74 ;
goto V_70;
}
if ( V_60 != V_7 -> V_39 )
V_7 -> V_18 |= V_75 ;
V_65 = F_24 ( V_54 ) ;
V_66 = F_25 ( V_54 ) ;
if ( ! ( F_42 ( V_52 ) & V_72 ) ) {
V_62 = F_44 ( V_63 , V_51 , V_65 , & V_66 ,
& V_60 , V_76 , NULL ) ;
} else {
V_61 = F_45 ( ~ 0 , ( T_5 * ) V_58 , sizeof( * V_58 ) ) ;
V_62 = F_44 ( V_63 , V_51 , V_65 , & V_66 ,
& V_60 , V_76 , & V_61 ) ;
V_63 = F_40 ( V_52 , 0 ) ;
if ( V_51 % 4 )
V_61 = F_45 ( V_61 , V_63 + V_51 , 4 - ( V_51 % 4 ) ) ;
if ( ~ V_61 != F_46 ( F_47 ( V_52 ) ) ) {
V_73:
V_56 = F_48 ( V_3 -> V_77 , F_49 () ) ;
V_56 -> V_78 ++ ;
if ( V_56 -> V_79 ++ < 5 )
F_50 ( V_80 L_8
L_9 ,
V_3 -> V_81 ) ;
F_51 () ;
if ( V_7 -> V_18 & V_75 ) {
V_67 = V_82 ;
goto V_70;
}
return;
}
}
if ( V_7 -> V_83 == V_59 )
V_7 -> V_83 += V_62 ;
V_7 -> V_39 += V_62 ;
if ( F_52 ( V_7 -> V_18 & V_84 ) &&
V_7 -> V_39 == V_7 -> V_71 - V_7 -> V_85 )
F_22 ( V_7 ) ;
return;
V_70:
F_53 ( V_7 , V_67 ) ;
}
static int F_54 ( struct V_1 * V_7 , struct V_16 * V_17 ,
T_3 V_60 , T_3 V_86 )
{
struct V_87 * V_88 ;
struct V_53 * V_54 ;
struct V_64 * V_65 ;
struct V_50 * V_52 = NULL ;
struct V_2 * V_3 = V_7 -> V_9 ;
struct V_89 * V_89 ;
T_3 V_90 ;
T_3 V_91 ;
T_3 V_92 ;
T_3 V_93 ;
T_3 V_94 , V_69 ;
T_3 V_95 ;
int error ;
void * V_96 = NULL ;
void * V_97 ;
int V_98 = V_3 -> V_99 ;
T_4 V_100 ;
F_55 ( V_86 <= 0 ) ;
if ( F_52 ( V_60 + V_86 > V_7 -> V_71 ) ) {
F_41 ( V_7 , L_10
L_11 , V_86 , V_60 ) ;
F_20 ( V_7 ) ;
return 0 ;
} else if ( V_60 != V_7 -> V_39 ) {
F_41 ( V_7 , L_12
L_13 , V_86 , V_60 ) ;
}
V_91 = V_7 -> V_101 ;
if ( V_3 -> V_102 ) {
V_91 = F_56 ( V_86 , ( T_3 ) V_3 -> V_103 ) ;
F_41 ( V_7 , L_14 ,
V_7 , V_86 , V_3 -> V_103 , V_91 ) ;
}
if ( V_91 > 512 )
V_91 &= ~ ( 512 - 1 ) ;
V_54 = V_7 -> V_37 ;
V_90 = V_86 ;
V_69 = V_94 = V_60 ;
V_92 = 0 ;
V_17 = V_3 -> V_26 . V_104 ( V_17 ) ;
V_100 = V_105 ;
F_55 ( ! V_17 ) ;
V_65 = F_24 ( V_54 ) ;
while ( V_90 > 0 && V_65 ) {
if ( V_60 >= V_65 -> V_106 ) {
V_60 -= V_65 -> V_106 ;
V_65 = F_57 ( V_65 ) ;
continue;
}
if ( ! V_52 ) {
V_92 = F_56 ( V_91 , V_90 ) ;
if ( V_92 % 4 )
V_98 = 0 ;
V_52 = F_34 ( V_3 , V_98 ? 0 : V_92 ) ;
if ( ! V_52 )
return - V_107 ;
V_96 = F_37 ( V_52 ) + 1 ;
V_69 = V_94 ;
F_58 ( V_52 ) = V_7 -> V_101 ;
}
V_95 = V_60 + V_65 -> V_60 ;
V_93 = F_56 ( V_92 , V_65 -> V_106 - V_60 ) ;
V_93 = F_56 ( V_93 ,
( T_3 ) ( V_108 - ( V_95 & ~ V_109 ) ) ) ;
V_89 = F_59 ( V_65 ) + ( V_95 >> V_110 ) ;
if ( V_98 ) {
F_60 ( V_89 ) ;
F_61 ( F_62 ( V_52 ) ,
F_63 ( F_62 ( V_52 ) ) -> V_111 ,
V_89 , V_95 & ~ V_109 , V_93 ) ;
F_62 ( V_52 ) -> V_71 += V_93 ;
F_39 ( V_52 ) += V_93 ;
F_62 ( V_52 ) -> V_112 += V_108 ;
} else {
V_97 = F_64 ( V_89 , V_76 ) ;
memcpy ( V_96 , ( char * ) V_97 + ( V_95 & ~ V_109 ) ,
V_93 ) ;
F_65 ( V_97 , V_76 ) ;
V_96 += V_93 ;
}
V_60 += V_93 ;
V_94 += V_93 ;
V_92 -= V_93 ;
V_90 -= V_93 ;
if ( ( F_63 ( F_62 ( V_52 ) ) -> V_111 < V_113 ) &&
( V_92 ) )
continue;
if ( V_90 == 0 )
V_100 |= V_114 | V_115 ;
V_88 = F_66 ( V_17 ) ;
F_67 ( V_52 , V_116 , V_88 -> V_117 , V_88 -> V_118 ,
V_119 , V_100 , V_69 ) ;
error = V_3 -> V_26 . V_120 ( V_3 , V_17 , V_52 ) ;
if ( error ) {
F_55 ( 1 ) ;
return error ;
}
V_52 = NULL ;
}
V_7 -> V_39 += V_86 ;
return 0 ;
}
static void F_68 ( struct V_1 * V_7 , struct V_50 * V_52 )
{
int V_121 = 1 ;
struct V_122 * V_123 ;
struct V_57 * V_58 ;
V_58 = F_37 ( V_52 ) ;
switch ( V_58 -> V_124 ) {
case V_125 :
break;
case V_126 :
V_123 = F_40 ( V_52 , sizeof( * V_123 ) ) ;
if ( V_123 && V_123 -> V_127 == V_128 )
break;
default:
V_121 = 0 ;
}
if ( V_121 ) {
V_7 -> V_18 |= V_129 ;
V_7 -> V_18 &= ~ V_25 ;
if ( V_7 -> V_130 )
F_69 ( & V_7 -> V_131 ) ;
else
F_22 ( V_7 ) ;
}
}
static void F_70 ( struct V_16 * V_17 , struct V_50 * V_52 , void * V_132 )
{
struct V_1 * V_7 = (struct V_1 * ) V_132 ;
struct V_2 * V_3 = V_7 -> V_9 ;
struct V_57 * V_58 ;
struct V_133 * V_134 ;
T_5 V_135 ;
int V_136 = 0 ;
if ( F_71 ( V_52 ) ) {
F_72 ( V_7 , V_52 ) ;
return;
}
V_58 = F_37 ( V_52 ) ;
V_135 = V_58 -> V_124 ;
if ( V_3 -> V_18 != V_137 )
goto V_138;
if ( F_14 ( V_7 ) )
goto V_138;
V_7 -> V_139 = V_22 ;
if ( V_58 -> V_140 == V_141 ) {
F_68 ( V_7 , V_52 ) ;
goto V_46;
}
if ( V_7 -> V_18 & ( V_129 | V_25 ) )
goto V_46;
if ( V_135 == V_142 ) {
F_55 ( F_42 ( V_52 ) & V_72 ) ;
V_134 = F_40 ( V_52 , sizeof( * V_134 ) ) ;
F_55 ( ! V_134 ) ;
V_136 = F_54 ( V_7 , V_17 ,
( T_3 ) F_38 ( V_134 -> V_143 ) ,
( T_3 ) F_38 ( V_134 -> V_144 ) ) ;
if ( ! V_136 )
V_17 -> V_145 = V_7 -> V_39 ;
} else if ( V_135 == V_116 ) {
F_55 ( F_39 ( V_52 ) < sizeof( * V_58 ) ) ;
F_36 ( V_7 , V_52 ) ;
V_17 -> V_145 = V_7 -> V_83 ;
} else if ( V_135 == V_146 ) {
F_55 ( F_42 ( V_52 ) & V_72 ) ;
F_73 ( V_7 , V_52 ) ;
} else {
F_41 ( V_7 , L_15 , V_135 ) ;
}
V_46:
F_17 ( V_7 ) ;
V_138:
F_74 ( V_52 ) ;
}
static void F_73 ( struct V_1 * V_7 , struct V_50 * V_52 )
{
struct V_57 * V_58 ;
struct V_147 * V_148 ;
struct V_149 * V_150 ;
struct V_151 * V_152 ;
T_4 V_153 ;
T_4 V_154 ;
T_4 V_155 = 0 ;
T_4 V_156 = 0 ;
T_5 V_40 = 0 ;
V_153 = F_39 ( V_52 ) ;
V_58 = (struct V_57 * ) F_75 ( V_52 ) ;
if ( F_52 ( V_153 < sizeof( * V_58 ) + sizeof( * V_148 ) ) )
goto V_157;
V_153 -= sizeof( * V_58 ) ;
V_148 = (struct V_147 * ) ( V_58 + 1 ) ;
V_7 -> V_158 = V_148 -> V_159 ;
V_40 = V_148 -> F_42 ;
V_7 -> V_160 = V_40 ;
V_154 = V_7 -> V_71 ;
F_26 ( V_7 ) ;
if ( F_52 ( ( V_40 & ~ V_161 ) || V_148 -> V_159 ) ) {
V_150 = ( void * ) ( V_148 + 1 ) ;
if ( V_40 & ( V_162 | V_163 ) ) {
if ( V_153 < sizeof( * V_148 ) + sizeof( * V_150 ) )
goto V_157;
V_152 = (struct V_151 * ) ( V_150 + 1 ) ;
if ( V_40 & V_162 ) {
V_155 = F_38 ( V_150 -> V_164 ) ;
if ( V_155 != sizeof( * V_152 ) )
goto V_157;
if ( V_7 -> V_130 ) {
V_7 -> V_158 = V_152 -> V_165 ;
F_69 ( & V_7 -> V_131 ) ;
return;
}
}
if ( V_40 & V_163 ) {
V_156 = F_38 ( V_150 -> V_166 ) ;
if ( V_156 > V_167 )
V_156 = V_167 ;
memcpy ( V_7 -> V_37 -> V_168 ,
( char * ) V_152 + V_155 , V_156 ) ;
}
}
if ( V_40 & ( V_169 | V_170 ) ) {
if ( V_153 < sizeof( * V_148 ) + sizeof( V_150 -> V_171 ) )
goto V_157;
if ( V_40 & V_169 ) {
V_7 -> V_85 = F_38 ( V_150 -> V_171 ) ;
if ( ! ( V_40 & V_163 ) &&
( V_148 -> V_159 == 0 ) &&
( F_76 ( V_7 -> V_37 ) -
V_7 -> V_85 ) < V_7 -> V_37 -> V_172 )
goto V_70;
V_154 -= V_7 -> V_85 ;
} else {
V_7 -> V_30 = V_31 ;
}
}
}
V_7 -> V_18 |= V_84 ;
if ( F_52 ( V_7 -> V_39 != V_154 ) ) {
if ( V_7 -> V_39 < V_154 ) {
F_18 ( V_7 , 2 ) ;
return;
}
V_7 -> V_30 = V_74 ;
F_41 ( V_7 , L_16
L_17 ,
V_7 -> V_173 -> V_81 ,
V_7 -> V_39 , V_154 , V_7 -> V_71 ) ;
}
F_22 ( V_7 ) ;
return;
V_157:
F_41 ( V_7 , L_18
L_19 , V_40 , F_39 ( V_52 ) , V_155 , V_156 ) ;
V_70:
V_7 -> V_30 = V_31 ;
F_22 ( V_7 ) ;
}
static void F_22 ( struct V_1 * V_7 )
{
struct V_2 * V_3 = V_7 -> V_9 ;
struct V_16 * V_17 ;
struct V_87 * V_88 ;
T_4 V_100 ;
if ( V_7 -> V_18 & V_25 )
return;
if ( V_7 -> V_18 & V_129 ) {
if ( ! V_7 -> V_30 )
V_7 -> V_30 = V_174 ;
} else {
if ( V_7 -> V_39 < V_7 -> V_71 && ! V_7 -> V_29 &&
( ! ( V_7 -> V_160 & V_169 ) ||
V_7 -> V_39 < V_7 -> V_71 - V_7 -> V_85 ) ) {
V_7 -> V_30 = V_175 ;
V_7 -> V_29 = 0 ;
}
}
V_17 = V_7 -> V_23 ;
if ( V_17 ) {
V_7 -> V_23 = NULL ;
if ( F_52 ( V_7 -> V_160 & V_161 ) ) {
struct V_50 * V_176 ;
struct V_16 * V_177 ;
V_177 = V_3 -> V_26 . V_104 ( V_17 ) ;
V_176 = F_33 ( V_7 -> V_9 , 0 ) ;
if ( V_176 ) {
V_100 = V_114 ;
V_100 |= V_178 | V_115 ;
V_88 = F_66 ( V_17 ) ;
F_67 ( V_176 , V_179 ,
V_88 -> V_117 , V_88 -> V_118 ,
V_119 , V_100 , 0 ) ;
V_3 -> V_26 . V_120 ( V_3 , V_177 , V_176 ) ;
}
}
V_3 -> V_26 . V_28 ( V_17 ) ;
}
if ( V_7 -> V_37 )
F_77 ( V_7 ) ;
}
static void F_78 ( struct V_1 * V_7 , int error )
{
struct V_2 * V_3 = V_7 -> V_9 ;
if ( V_7 -> V_23 ) {
V_3 -> V_26 . V_28 ( V_7 -> V_23 ) ;
V_7 -> V_23 = NULL ;
}
V_7 -> V_30 = error ;
}
static void F_79 ( struct V_2 * V_3 , unsigned int V_180 ,
unsigned int V_181 , int error )
{
struct V_5 * V_6 = F_2 ( V_3 ) ;
struct V_1 * V_7 ;
struct V_53 * V_182 ;
unsigned long V_40 ;
F_28 ( & V_6 -> V_183 , V_40 ) ;
V_184:
F_80 (fsp, &si->scsi_pkt_queue, list) {
V_182 = V_7 -> V_37 ;
if ( V_180 != - 1 && F_81 ( V_182 ) != V_180 )
continue;
if ( V_181 != - 1 && V_182 -> V_185 -> V_181 != V_181 )
continue;
F_11 ( V_7 ) ;
F_31 ( & V_6 -> V_183 , V_40 ) ;
if ( ! F_14 ( V_7 ) ) {
F_78 ( V_7 , error ) ;
F_77 ( V_7 ) ;
F_17 ( V_7 ) ;
}
F_8 ( V_7 ) ;
F_28 ( & V_6 -> V_183 , V_40 ) ;
goto V_184;
}
F_31 ( & V_6 -> V_183 , V_40 ) ;
}
static void F_82 ( struct V_2 * V_3 )
{
F_79 ( V_3 , - 1 , - 1 , V_186 ) ;
}
static int F_83 ( struct V_2 * V_3 , struct V_1 * V_7 )
{
struct V_5 * V_6 = F_2 ( V_3 ) ;
unsigned long V_40 ;
int V_136 ;
V_7 -> V_37 -> V_187 . V_188 = ( char * ) V_7 ;
V_7 -> V_189 . V_190 = F_84 ( V_7 -> V_71 ) ;
V_7 -> V_189 . V_191 = V_7 -> V_33 & ~ V_192 ;
F_85 ( V_7 -> V_37 -> V_185 -> V_181 ,
(struct V_193 * ) V_7 -> V_189 . V_194 ) ;
memcpy ( V_7 -> V_189 . V_195 , V_7 -> V_37 -> V_196 , V_7 -> V_37 -> V_197 ) ;
F_28 ( & V_6 -> V_183 , V_40 ) ;
F_86 ( & V_7 -> V_14 , & V_6 -> V_198 ) ;
F_31 ( & V_6 -> V_183 , V_40 ) ;
V_136 = V_3 -> V_26 . V_199 ( V_3 , V_7 , F_70 ) ;
if ( F_52 ( V_136 ) ) {
F_28 ( & V_6 -> V_183 , V_40 ) ;
F_87 ( & V_7 -> V_14 ) ;
F_31 ( & V_6 -> V_183 , V_40 ) ;
}
return V_136 ;
}
static inline unsigned int F_88 ( struct V_1 * V_7 )
{
struct V_200 * V_201 = V_7 -> V_173 -> V_202 ;
return F_89 ( V_201 -> V_203 ) + V_204 ;
}
static int F_90 ( struct V_2 * V_3 , struct V_1 * V_7 ,
void (* F_91)( struct V_16 * ,
struct V_50 * V_52 ,
void * V_132 ) )
{
struct V_50 * V_52 ;
struct V_16 * V_17 ;
struct V_205 * V_173 ;
struct V_200 * V_201 ;
const T_3 V_51 = sizeof( V_7 -> V_189 ) ;
int V_136 = 0 ;
if ( F_14 ( V_7 ) )
return 0 ;
V_52 = F_33 ( V_3 , sizeof( V_7 -> V_189 ) ) ;
if ( ! V_52 ) {
V_136 = - 1 ;
goto V_46;
}
memcpy ( F_40 ( V_52 , V_51 ) , & V_7 -> V_189 , V_51 ) ;
F_92 ( V_52 ) = V_7 ;
V_173 = V_7 -> V_173 ;
V_7 -> V_101 = V_173 -> V_206 ;
V_201 = V_173 -> V_202 ;
F_67 ( V_52 , V_207 , V_173 -> V_81 ,
V_201 -> V_208 -> V_81 , V_119 ,
V_209 , 0 ) ;
V_17 = V_3 -> V_26 . V_210 ( V_3 , V_52 , F_91 , F_13 ,
V_7 , 0 ) ;
if ( ! V_17 ) {
V_136 = - 1 ;
goto V_46;
}
V_7 -> V_139 = V_22 ;
V_7 -> V_23 = V_17 ;
F_11 ( V_7 ) ;
F_93 ( & V_7 -> V_13 , V_211 , ( unsigned long ) V_7 ) ;
if ( V_201 -> V_40 & V_212 )
F_18 ( V_7 , F_88 ( V_7 ) ) ;
V_46:
F_17 ( V_7 ) ;
return V_136 ;
}
static void F_72 ( struct V_1 * V_7 , struct V_50 * V_52 )
{
int error = F_94 ( V_52 ) ;
if ( F_14 ( V_7 ) )
return;
if ( error == - V_213 ) {
F_21 ( V_7 ) ;
goto V_46;
}
V_7 -> V_18 &= ~ V_25 ;
V_7 -> V_30 = V_214 ;
F_22 ( V_7 ) ;
V_46:
F_17 ( V_7 ) ;
}
static int F_95 ( struct V_1 * V_7 )
{
int V_136 = V_215 ;
unsigned long V_216 ;
if ( F_20 ( V_7 ) )
return V_215 ;
F_96 ( & V_7 -> V_131 ) ;
V_7 -> V_130 = 1 ;
F_16 ( & V_7 -> V_15 ) ;
V_216 = F_97 ( & V_7 -> V_131 ,
V_217 ) ;
F_15 ( & V_7 -> V_15 ) ;
V_7 -> V_130 = 0 ;
if ( ! V_216 ) {
F_41 ( V_7 , L_20 ) ;
} else if ( V_7 -> V_18 & V_129 ) {
F_41 ( V_7 , L_21 ) ;
V_136 = V_218 ;
F_22 ( V_7 ) ;
}
return V_136 ;
}
static void F_98 ( unsigned long V_96 )
{
struct V_1 * V_7 = (struct V_1 * ) V_96 ;
struct V_2 * V_3 = V_7 -> V_9 ;
if ( V_3 -> V_26 . V_199 ( V_3 , V_7 , V_219 ) ) {
if ( V_7 -> V_220 ++ >= V_221 )
return;
if ( F_14 ( V_7 ) )
return;
F_93 ( & V_7 -> V_13 , F_98 , ( unsigned long ) V_7 ) ;
F_18 ( V_7 , F_88 ( V_7 ) ) ;
F_17 ( V_7 ) ;
}
}
static int F_99 ( struct V_2 * V_3 , struct V_1 * V_7 ,
unsigned int V_180 , unsigned int V_181 )
{
int V_136 ;
V_7 -> V_189 . V_190 = F_84 ( V_7 -> V_71 ) ;
V_7 -> V_189 . V_222 = V_223 ;
F_85 ( V_181 , (struct V_193 * ) V_7 -> V_189 . V_194 ) ;
V_7 -> V_130 = 1 ;
F_96 ( & V_7 -> V_131 ) ;
F_98 ( ( unsigned long ) V_7 ) ;
V_136 = F_97 ( & V_7 -> V_131 , V_217 ) ;
F_15 ( & V_7 -> V_15 ) ;
V_7 -> V_18 |= V_19 ;
F_16 ( & V_7 -> V_15 ) ;
F_100 ( & V_7 -> V_13 ) ;
F_15 ( & V_7 -> V_15 ) ;
if ( V_7 -> V_23 ) {
V_3 -> V_26 . V_28 ( V_7 -> V_23 ) ;
V_7 -> V_23 = NULL ;
}
V_7 -> V_130 = 0 ;
F_16 ( & V_7 -> V_15 ) ;
if ( ! V_136 ) {
F_101 ( V_3 , L_22 ) ;
return V_215 ;
}
if ( V_7 -> V_158 != V_224 )
return V_215 ;
F_101 ( V_3 , L_23 , V_181 ) ;
F_79 ( V_3 , V_180 , V_181 , V_174 ) ;
return V_218 ;
}
static void V_219 ( struct V_16 * V_17 , struct V_50 * V_52 , void * V_132 )
{
struct V_1 * V_7 = V_132 ;
struct V_57 * V_58 ;
if ( F_71 ( V_52 ) ) {
return;
}
if ( F_14 ( V_7 ) )
goto V_138;
if ( ! V_7 -> V_23 || ! V_7 -> V_130 )
goto V_225;
V_58 = F_37 ( V_52 ) ;
if ( V_58 -> V_140 != V_141 )
F_73 ( V_7 , V_52 ) ;
V_7 -> V_23 = NULL ;
V_7 -> V_9 -> V_26 . V_28 ( V_17 ) ;
V_225:
F_17 ( V_7 ) ;
V_138:
F_74 ( V_52 ) ;
}
static void F_102 ( struct V_2 * V_3 )
{
F_79 ( V_3 , - 1 , - 1 , V_31 ) ;
}
static void V_211 ( unsigned long V_96 )
{
struct V_1 * V_7 = (struct V_1 * ) V_96 ;
struct V_205 * V_173 = V_7 -> V_173 ;
struct V_200 * V_201 = V_173 -> V_202 ;
if ( F_14 ( V_7 ) )
return;
if ( V_7 -> V_189 . V_222 )
goto V_46;
V_7 -> V_18 |= V_226 ;
if ( V_201 -> V_40 & V_212 )
F_103 ( V_7 ) ;
else if ( V_7 -> V_18 & V_84 )
F_22 ( V_7 ) ;
else
F_53 ( V_7 , V_227 ) ;
V_7 -> V_18 &= ~ V_226 ;
V_46:
F_17 ( V_7 ) ;
}
static void F_103 ( struct V_1 * V_7 )
{
struct V_2 * V_3 ;
struct V_50 * V_52 ;
struct V_205 * V_173 ;
struct V_200 * V_201 ;
V_3 = V_7 -> V_9 ;
V_173 = V_7 -> V_173 ;
V_201 = V_173 -> V_202 ;
if ( ! V_7 -> V_23 || V_201 -> V_228 != V_229 ) {
V_7 -> V_30 = V_186 ;
V_7 -> V_29 = 0 ;
F_22 ( V_7 ) ;
return;
}
V_52 = F_33 ( V_3 , sizeof( struct V_230 ) ) ;
if ( ! V_52 )
goto V_231;
F_104 ( V_52 ) = V_7 -> V_23 ;
F_67 ( V_52 , V_232 , V_173 -> V_81 ,
V_201 -> V_208 -> V_81 , V_233 ,
V_209 , 0 ) ;
if ( V_3 -> V_26 . V_234 ( V_3 , V_173 -> V_81 , V_52 , V_235 ,
V_236 , V_7 ,
2 * V_3 -> V_237 ) ) {
F_11 ( V_7 ) ;
return;
}
V_231:
if ( V_7 -> V_220 ++ < V_221 )
F_18 ( V_7 , F_88 ( V_7 ) ) ;
else
F_53 ( V_7 , V_227 ) ;
}
static void V_236 ( struct V_16 * V_17 , struct V_50 * V_52 , void * V_132 )
{
struct V_1 * V_7 = (struct V_1 * ) V_132 ;
struct V_238 * V_239 ;
struct V_240 * V_241 ;
T_4 V_242 ;
T_5 V_243 ;
T_4 V_60 ;
enum V_244 V_245 ;
enum V_246 V_135 ;
struct V_200 * V_201 ;
if ( F_71 ( V_52 ) ) {
F_105 ( V_7 , V_52 ) ;
return;
}
if ( F_14 ( V_7 ) )
goto V_138;
V_7 -> V_220 = 0 ;
V_243 = F_106 ( V_52 ) ;
if ( V_243 == V_247 ) {
V_241 = F_40 ( V_52 , sizeof( * V_241 ) ) ;
switch ( V_241 -> V_248 ) {
default:
F_41 ( V_7 , L_24
L_25 ,
V_7 -> V_173 -> V_81 , V_241 -> V_248 ,
V_241 -> V_249 ) ;
case V_250 :
F_41 ( V_7 , L_26 ) ;
V_201 = V_7 -> V_173 -> V_202 ;
V_201 -> V_40 &= ~ V_212 ;
break;
case V_251 :
case V_252 :
if ( V_241 -> V_249 == V_253 &&
V_7 -> V_39 == 0 ) {
F_21 ( V_7 ) ;
break;
}
F_53 ( V_7 , V_31 ) ;
break;
}
} else if ( V_243 == V_254 ) {
if ( V_7 -> V_18 & V_129 )
goto V_255;
V_245 = V_7 -> V_37 -> V_256 ;
V_239 = F_40 ( V_52 , sizeof( * V_239 ) ) ;
V_60 = F_38 ( V_239 -> V_257 ) ;
V_242 = F_38 ( V_239 -> V_258 ) ;
if ( V_242 & V_259 ) {
if ( V_245 == V_260 ) {
V_135 = V_146 ;
} else if ( V_7 -> V_83 == V_60 ) {
V_135 = V_146 ;
} else {
V_60 = V_7 -> V_83 ;
V_135 = V_116 ;
}
F_107 ( V_7 , V_135 , V_60 ) ;
} else if ( V_242 & V_261 ) {
F_18 ( V_7 , F_88 ( V_7 ) ) ;
} else {
V_135 = V_116 ;
if ( V_245 == V_260 ) {
V_135 = V_146 ;
if ( V_60 < V_7 -> V_71 )
V_135 = V_142 ;
} else if ( V_60 == V_7 -> V_83 ) {
V_135 = V_146 ;
} else if ( V_7 -> V_83 < V_60 ) {
V_60 = V_7 -> V_83 ;
}
F_107 ( V_7 , V_135 , V_60 ) ;
}
}
V_255:
F_17 ( V_7 ) ;
V_138:
F_8 ( V_7 ) ;
F_74 ( V_52 ) ;
}
static void F_105 ( struct V_1 * V_7 , struct V_50 * V_52 )
{
int error = F_94 ( V_52 ) ;
if ( F_14 ( V_7 ) )
goto V_138;
switch ( error ) {
case - V_213 :
F_21 ( V_7 ) ;
break;
default:
F_41 ( V_7 , L_27 ,
V_7 , V_7 -> V_173 -> V_81 , error ) ;
V_7 -> V_30 = V_214 ;
case - V_262 :
F_41 ( V_7 , L_28 ,
V_7 -> V_173 -> V_81 , error , V_7 -> V_220 ,
V_221 ) ;
if ( V_7 -> V_220 ++ < V_221 )
F_103 ( V_7 ) ;
else
F_53 ( V_7 , V_31 ) ;
break;
}
F_17 ( V_7 ) ;
V_138:
F_8 ( V_7 ) ;
}
static void F_53 ( struct V_1 * V_7 , T_5 V_263 )
{
V_7 -> V_30 = V_263 ;
V_7 -> V_158 = 0 ;
V_7 -> V_29 = 0 ;
F_20 ( V_7 ) ;
}
static void F_107 ( struct V_1 * V_7 , enum V_246 V_135 , T_4 V_60 )
{
struct V_2 * V_3 = V_7 -> V_9 ;
struct V_205 * V_173 ;
struct V_200 * V_201 ;
struct V_87 * V_88 = F_66 ( V_7 -> V_23 ) ;
struct V_16 * V_17 ;
struct V_264 * V_265 ;
struct V_50 * V_52 ;
T_5 V_266 ;
unsigned int V_267 ;
V_173 = V_7 -> V_173 ;
V_201 = V_173 -> V_202 ;
V_266 = V_7 -> V_189 . V_195 [ 0 ] ;
if ( ! ( V_201 -> V_40 & V_268 ) ||
V_201 -> V_228 != V_229 )
goto V_231;
V_52 = F_33 ( V_3 , sizeof( * V_265 ) ) ;
if ( ! V_52 )
goto V_231;
V_265 = F_40 ( V_52 , sizeof( * V_265 ) ) ;
memset ( V_265 , 0 , sizeof( * V_265 ) ) ;
V_265 -> V_269 = V_270 ;
V_265 -> V_271 = F_108 ( V_88 -> V_272 ) ;
V_265 -> V_273 = F_108 ( V_88 -> V_274 ) ;
V_265 -> V_275 = V_135 ;
V_265 -> V_276 = F_84 ( V_60 ) ;
F_67 ( V_52 , V_277 , V_173 -> V_81 ,
V_201 -> V_208 -> V_81 , V_119 ,
V_209 , 0 ) ;
V_267 = F_88 ( V_7 ) ;
V_17 = V_3 -> V_26 . V_210 ( V_3 , V_52 , V_278 ,
F_13 ,
V_7 , F_109 ( V_267 ) ) ;
if ( ! V_17 )
goto V_231;
V_7 -> V_279 = V_17 ;
V_7 -> V_39 = V_60 ;
V_7 -> V_83 = V_60 ;
V_7 -> V_18 &= ~ V_84 ;
F_11 ( V_7 ) ;
return;
V_231:
F_21 ( V_7 ) ;
}
static void V_278 ( struct V_16 * V_17 , struct V_50 * V_52 , void * V_132 )
{
struct V_1 * V_7 = V_132 ;
struct V_57 * V_58 ;
if ( F_71 ( V_52 ) ) {
F_110 ( V_7 , V_52 ) ;
return;
}
if ( F_14 ( V_7 ) )
goto V_138;
V_58 = F_37 ( V_52 ) ;
if ( V_58 -> V_140 == V_141 ) {
F_17 ( V_7 ) ;
return;
}
switch ( F_106 ( V_52 ) ) {
case V_254 :
V_7 -> V_220 = 0 ;
F_18 ( V_7 , F_88 ( V_7 ) ) ;
break;
case V_247 :
default:
F_53 ( V_7 , V_31 ) ;
break;
}
F_17 ( V_7 ) ;
V_138:
V_7 -> V_9 -> V_26 . V_28 ( V_17 ) ;
F_74 ( V_52 ) ;
}
static void F_110 ( struct V_1 * V_7 , struct V_50 * V_52 )
{
if ( F_14 ( V_7 ) )
goto V_138;
switch ( F_94 ( V_52 ) ) {
case - V_262 :
if ( V_7 -> V_220 ++ < V_221 )
F_103 ( V_7 ) ;
else
F_53 ( V_7 , V_227 ) ;
break;
case - V_213 :
default:
F_21 ( V_7 ) ;
break;
}
F_17 ( V_7 ) ;
V_138:
V_7 -> V_9 -> V_26 . V_28 ( V_7 -> V_279 ) ;
}
static inline int F_111 ( struct V_2 * V_3 )
{
return ( V_3 -> V_18 == V_137 ) &&
V_3 -> V_280 && ! V_3 -> V_281 ;
}
int F_112 ( struct V_282 * V_283 , struct V_53 * V_182 )
{
struct V_2 * V_3 = F_113 ( V_283 ) ;
struct V_205 * V_173 = F_114 ( F_115 ( V_182 -> V_185 ) ) ;
struct V_1 * V_7 ;
struct V_200 * V_201 ;
int V_284 ;
int V_136 = 0 ;
struct V_55 * V_56 ;
V_284 = F_116 ( V_173 ) ;
if ( V_284 ) {
V_182 -> V_285 = V_284 ;
V_182 -> V_286 ( V_182 ) ;
return 0 ;
}
if ( ! * (struct V_287 * * ) V_173 -> V_202 ) {
V_182 -> V_285 = V_288 << 16 ;
V_182 -> V_286 ( V_182 ) ;
goto V_138;
}
V_201 = V_173 -> V_202 ;
if ( ! F_111 ( V_3 ) ) {
if ( V_3 -> V_281 )
F_32 ( V_3 ) ;
V_136 = V_289 ;
goto V_138;
}
V_7 = F_1 ( V_3 , V_290 ) ;
if ( V_7 == NULL ) {
V_136 = V_289 ;
goto V_138;
}
V_7 -> V_37 = V_182 ;
V_7 -> V_173 = V_173 ;
V_7 -> V_71 = F_76 ( V_182 ) ;
V_7 -> V_39 = 0 ;
V_56 = F_48 ( V_3 -> V_77 , F_49 () ) ;
if ( V_182 -> V_256 == V_291 ) {
V_7 -> V_33 = V_34 ;
V_56 -> V_292 ++ ;
V_56 -> V_293 += V_7 -> V_71 ;
} else if ( V_182 -> V_256 == V_260 ) {
V_7 -> V_33 = V_294 ;
V_56 -> V_295 ++ ;
V_56 -> V_296 += V_7 -> V_71 ;
} else {
V_7 -> V_33 = 0 ;
V_56 -> V_297 ++ ;
}
F_51 () ;
F_5 ( & V_7 -> V_13 ) ;
V_7 -> V_13 . V_96 = ( unsigned long ) V_7 ;
V_284 = F_83 ( V_3 , V_7 ) ;
if ( V_284 != 0 ) {
V_7 -> V_18 = V_298 ;
F_8 ( V_7 ) ;
V_136 = V_289 ;
}
V_138:
return V_136 ;
}
static void F_77 ( struct V_1 * V_7 )
{
struct V_5 * V_6 ;
struct V_53 * V_182 ;
struct V_2 * V_3 ;
unsigned long V_40 ;
F_26 ( V_7 ) ;
V_7 -> V_18 |= V_19 ;
if ( ! ( V_7 -> V_18 & V_226 ) ) {
F_16 ( & V_7 -> V_15 ) ;
F_100 ( & V_7 -> V_13 ) ;
F_15 ( & V_7 -> V_15 ) ;
}
V_3 = V_7 -> V_9 ;
V_6 = F_2 ( V_3 ) ;
if ( V_6 -> V_47 )
F_27 ( V_3 ) ;
V_182 = V_7 -> V_37 ;
F_117 ( V_182 ) = V_7 -> V_158 ;
switch ( V_7 -> V_30 ) {
case V_68 :
if ( V_7 -> V_158 == 0 ) {
V_182 -> V_285 = V_299 << 16 ;
if ( V_7 -> V_85 )
F_118 ( V_182 ) = V_7 -> V_85 ;
} else {
V_182 -> V_285 = ( V_299 << 16 ) | V_7 -> V_158 ;
}
break;
case V_31 :
F_41 ( V_7 , L_29
L_30 ) ;
V_182 -> V_285 = V_300 << 16 ;
break;
case V_175 :
if ( ( V_7 -> V_158 == 0 ) && ! ( V_7 -> V_33 & V_34 ) ) {
if ( V_7 -> V_18 & V_84 ) {
V_182 -> V_285 = V_299 << 16 ;
} else {
F_41 ( V_7 , L_31
L_32 ) ;
V_182 -> V_285 = V_300 << 16 ;
}
} else {
F_41 ( V_7 , L_29
L_33 ) ;
F_118 ( V_182 ) = V_7 -> V_85 ;
V_182 -> V_285 = ( V_300 << 16 ) | V_7 -> V_158 ;
}
break;
case V_74 :
F_41 ( V_7 , L_29
L_34 ) ;
V_182 -> V_285 = ( V_300 << 16 ) | V_7 -> V_158 ;
break;
case V_174 :
F_41 ( V_7 , L_29
L_35 ) ;
V_182 -> V_285 = ( V_300 << 16 ) | V_7 -> V_29 ;
break;
case V_301 :
F_41 ( V_7 , L_36
L_37 ) ;
V_182 -> V_285 = ( V_302 << 16 ) ;
break;
case V_186 :
F_41 ( V_7 , L_38
L_39 ) ;
V_182 -> V_285 = ( V_303 << 16 ) ;
break;
case V_82 :
F_41 ( V_7 , L_40
L_41 ) ;
V_182 -> V_285 = ( V_304 << 16 ) ;
break;
case V_227 :
F_41 ( V_7 , L_42
L_43 ) ;
V_182 -> V_285 = ( V_305 << 16 ) | V_7 -> V_29 ;
break;
default:
F_41 ( V_7 , L_29
L_44 ) ;
V_182 -> V_285 = ( V_300 << 16 ) ;
break;
}
if ( V_3 -> V_18 != V_137 && V_7 -> V_30 != V_68 )
V_182 -> V_285 = ( V_306 << 16 ) ;
F_28 ( & V_6 -> V_183 , V_40 ) ;
F_87 ( & V_7 -> V_14 ) ;
V_182 -> V_187 . V_188 = NULL ;
F_31 ( & V_6 -> V_183 , V_40 ) ;
V_182 -> V_286 ( V_182 ) ;
F_8 ( V_7 ) ;
}
int F_119 ( struct V_53 * V_182 )
{
struct V_1 * V_7 ;
struct V_2 * V_3 ;
struct V_5 * V_6 ;
int V_136 = V_215 ;
unsigned long V_40 ;
V_3 = F_113 ( V_182 -> V_185 -> V_42 ) ;
if ( V_3 -> V_18 != V_137 )
return V_136 ;
else if ( ! V_3 -> V_280 )
return V_136 ;
V_6 = F_2 ( V_3 ) ;
F_28 ( & V_6 -> V_183 , V_40 ) ;
V_7 = F_120 ( V_182 ) ;
if ( ! V_7 ) {
F_31 ( & V_6 -> V_183 , V_40 ) ;
return V_218 ;
}
F_11 ( V_7 ) ;
F_31 ( & V_6 -> V_183 , V_40 ) ;
if ( F_14 ( V_7 ) ) {
V_136 = V_218 ;
goto V_307;
}
V_136 = F_95 ( V_7 ) ;
F_17 ( V_7 ) ;
V_307:
F_8 ( V_7 ) ;
return V_136 ;
}
int F_121 ( struct V_53 * V_182 )
{
struct V_2 * V_3 ;
struct V_1 * V_7 ;
struct V_205 * V_173 = F_114 ( F_115 ( V_182 -> V_185 ) ) ;
int V_136 = V_215 ;
int V_284 ;
V_284 = F_116 ( V_173 ) ;
if ( V_284 )
goto V_138;
V_3 = F_113 ( V_182 -> V_185 -> V_42 ) ;
if ( V_3 -> V_18 != V_137 )
return V_136 ;
F_101 ( V_3 , L_45 , V_173 -> V_81 ) ;
V_7 = F_1 ( V_3 , V_308 ) ;
if ( V_7 == NULL ) {
F_50 ( V_80 L_46 ) ;
goto V_138;
}
V_7 -> V_173 = V_173 ;
V_136 = F_99 ( V_3 , V_7 , F_81 ( V_182 ) , V_182 -> V_185 -> V_181 ) ;
V_7 -> V_18 = V_298 ;
F_8 ( V_7 ) ;
V_138:
return V_136 ;
}
int F_122 ( struct V_53 * V_182 )
{
struct V_282 * V_283 = V_182 -> V_185 -> V_42 ;
struct V_2 * V_3 = F_113 ( V_283 ) ;
unsigned long V_309 ;
F_101 ( V_3 , L_47 ) ;
V_3 -> V_26 . V_310 ( V_3 ) ;
V_309 = V_22 + V_311 ;
while ( ! F_111 ( V_3 ) && F_29 ( V_22 ,
V_309 ) )
F_123 ( 1000 ) ;
if ( F_111 ( V_3 ) ) {
F_30 ( V_312 , V_283 , L_48
L_49 , V_3 -> V_81 ) ;
return V_218 ;
} else {
F_30 ( V_312 , V_283 , L_50
L_51 ,
V_3 -> V_81 ) ;
return V_215 ;
}
}
int F_124 ( struct V_313 * V_314 )
{
struct V_205 * V_173 = F_114 ( F_115 ( V_314 ) ) ;
if ( ! V_173 || F_116 ( V_173 ) )
return - V_315 ;
if ( V_314 -> V_316 )
F_125 ( V_314 , V_317 ) ;
else
F_126 ( V_314 , F_127 ( V_314 ) ,
V_317 ) ;
return 0 ;
}
int F_128 ( struct V_313 * V_314 , int V_318 , int V_319 )
{
switch ( V_319 ) {
case V_320 :
F_126 ( V_314 , F_127 ( V_314 ) , V_318 ) ;
break;
case V_321 :
F_129 ( V_314 , V_318 ) ;
break;
case V_322 :
F_126 ( V_314 , F_127 ( V_314 ) , V_318 ) ;
break;
default:
return - V_323 ;
}
return V_314 -> V_324 ;
}
int F_130 ( struct V_313 * V_314 , int V_325 )
{
if ( V_314 -> V_316 ) {
F_131 ( V_314 , V_325 ) ;
if ( V_325 )
F_125 ( V_314 , V_314 -> V_324 ) ;
else
F_132 ( V_314 , V_314 -> V_324 ) ;
} else
V_325 = 0 ;
return V_325 ;
}
void F_133 ( struct V_2 * V_3 )
{
struct V_5 * V_6 = F_2 ( V_3 ) ;
if ( ! F_134 ( & V_6 -> V_198 ) )
F_50 ( V_49 L_52
L_53 , V_3 -> V_81 ) ;
F_135 ( V_6 -> V_8 ) ;
F_136 ( V_6 ) ;
V_3 -> V_326 = NULL ;
}
int F_137 ( void )
{
int V_136 = 0 ;
V_327 = F_138 ( L_54 ,
sizeof( struct V_1 ) ,
0 , V_328 , NULL ) ;
if ( ! V_327 ) {
F_50 ( V_49 L_55
L_56 ) ;
V_136 = - V_107 ;
}
return V_136 ;
}
void F_139 ( void )
{
if ( V_327 )
F_140 ( V_327 ) ;
}
int F_141 ( struct V_2 * V_3 )
{
int V_136 ;
struct V_5 * V_6 ;
if ( ! V_3 -> V_26 . V_199 )
V_3 -> V_26 . V_199 = F_90 ;
if ( ! V_3 -> V_26 . V_329 )
V_3 -> V_26 . V_329 = F_102 ;
if ( ! V_3 -> V_26 . V_330 )
V_3 -> V_26 . V_330 = F_82 ;
V_6 = F_142 ( sizeof( struct V_5 ) , V_331 ) ;
if ( ! V_6 )
return - V_107 ;
V_3 -> V_326 = V_6 ;
V_6 -> V_48 = V_3 -> V_42 -> V_41 ;
F_6 ( & V_6 -> V_198 ) ;
F_7 ( & V_6 -> V_183 ) ;
V_6 -> V_8 = F_143 ( 2 , V_327 ) ;
if ( ! V_6 -> V_8 ) {
V_136 = - V_107 ;
goto V_332;
}
return 0 ;
V_332:
F_136 ( V_6 ) ;
return V_136 ;
}
