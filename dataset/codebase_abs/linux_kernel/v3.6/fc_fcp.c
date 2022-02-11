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
if ( ! ( V_7 -> V_21 & V_22 ) )
F_22 ( & V_7 -> V_13 , V_25 + V_24 ) ;
}
static int F_23 ( struct V_1 * V_7 )
{
if ( ! V_7 -> V_26 )
return - V_27 ;
F_8 ( V_7 -> V_9 -> V_17 , F_9 () ) -> V_28 ++ ;
F_10 () ;
V_7 -> V_21 |= V_29 ;
return V_7 -> V_9 -> V_30 . V_31 ( V_7 -> V_26 , 0 ) ;
}
static void F_24 ( struct V_1 * V_7 )
{
if ( V_7 -> V_26 ) {
V_7 -> V_9 -> V_30 . V_32 ( V_7 -> V_26 ) ;
V_7 -> V_26 = NULL ;
}
V_7 -> V_21 &= ~ V_29 ;
V_7 -> V_33 = 0 ;
V_7 -> V_34 = V_35 ;
F_25 ( V_7 ) ;
}
void F_26 ( struct V_1 * V_7 , T_2 V_36 )
{
struct V_2 * V_3 ;
V_3 = V_7 -> V_9 ;
if ( ( V_7 -> V_37 & V_38 ) &&
( V_3 -> V_39 ) && ( V_3 -> V_30 . V_40 ) ) {
if ( V_3 -> V_30 . V_40 ( V_3 , V_36 , F_27 ( V_7 -> V_41 ) ,
F_28 ( V_7 -> V_41 ) ) )
V_7 -> V_10 = V_36 ;
}
}
void F_29 ( struct V_1 * V_7 )
{
struct V_2 * V_3 ;
if ( ! V_7 )
return;
if ( V_7 -> V_10 == V_11 )
return;
V_3 = V_7 -> V_9 ;
if ( V_3 -> V_30 . V_42 ) {
V_7 -> V_43 = V_3 -> V_30 . V_42 ( V_3 , V_7 -> V_10 ) ;
V_7 -> V_10 = V_11 ;
}
}
static void F_30 ( struct V_2 * V_3 )
{
struct V_5 * V_6 = F_2 ( V_3 ) ;
unsigned long V_44 ;
int V_45 ;
F_31 ( V_3 -> V_46 -> V_47 , V_44 ) ;
if ( V_6 -> V_48 &&
( F_32 ( V_25 , V_6 -> V_48 +
V_49 ) ) )
goto V_50;
if ( F_32 ( V_25 , V_6 -> V_51 +
V_49 ) )
goto V_50;
V_6 -> V_48 = V_25 ;
V_45 = V_3 -> V_46 -> V_45 << 1 ;
if ( V_45 >= V_6 -> V_52 ) {
V_45 = V_6 -> V_52 ;
V_6 -> V_51 = 0 ;
}
V_3 -> V_46 -> V_45 = V_45 ;
F_33 ( V_53 , V_3 -> V_46 , L_1
L_2 , V_45 ) ;
V_50:
F_34 ( V_3 -> V_46 -> V_47 , V_44 ) ;
}
static void F_35 ( struct V_2 * V_3 )
{
struct V_5 * V_6 = F_2 ( V_3 ) ;
unsigned long V_44 ;
int V_45 ;
F_31 ( V_3 -> V_46 -> V_47 , V_44 ) ;
if ( V_6 -> V_51 &&
( F_32 ( V_25 , V_6 -> V_51 +
V_49 ) ) )
goto V_50;
V_6 -> V_51 = V_25 ;
V_45 = V_3 -> V_46 -> V_45 ;
V_45 >>= 1 ;
if ( ! V_45 )
V_45 = 1 ;
V_3 -> V_46 -> V_45 = V_45 ;
F_33 ( V_53 , V_3 -> V_46 , L_3
L_4 , V_45 ) ;
V_50:
F_34 ( V_3 -> V_46 -> V_47 , V_44 ) ;
}
static inline struct V_54 * F_36 ( struct V_2 * V_3 ,
T_3 V_55 )
{
struct V_54 * V_56 ;
V_56 = F_37 ( V_3 , V_55 ) ;
if ( F_38 ( V_56 ) )
return V_56 ;
F_8 ( V_3 -> V_17 , F_9 () ) -> V_57 ++ ;
F_10 () ;
F_35 ( V_3 ) ;
return NULL ;
}
static void F_39 ( struct V_1 * V_7 , struct V_54 * V_56 )
{
struct V_58 * V_59 = V_7 -> V_41 ;
struct V_2 * V_3 = V_7 -> V_9 ;
struct V_60 * V_17 ;
struct V_61 * V_62 ;
T_3 V_63 ;
T_3 V_64 ;
T_4 V_65 ;
T_4 V_66 = 0 ;
T_3 V_55 ;
void * V_67 ;
struct V_68 * V_69 ;
T_4 V_70 ;
T_5 V_71 = V_72 ;
V_62 = F_40 ( V_56 ) ;
V_64 = F_41 ( V_62 -> V_73 ) ;
V_63 = V_64 ;
V_55 = F_42 ( V_56 ) - sizeof( * V_62 ) ;
V_67 = F_43 ( V_56 , 0 ) ;
if ( V_7 -> V_10 != V_11 ) {
F_29 ( V_7 ) ;
F_44 ( V_7 , L_5 ) ;
V_71 = V_35 ;
goto V_74;
}
if ( V_64 + V_55 > V_7 -> V_75 ) {
if ( ( F_45 ( V_56 ) & V_76 ) &&
F_46 ( V_56 ) )
goto V_77;
F_44 ( V_7 , L_6
L_7 , V_55 , V_64 , V_7 -> V_75 ) ;
V_71 = V_78 ;
goto V_74;
}
if ( V_64 != V_7 -> V_43 )
V_7 -> V_21 |= V_79 ;
V_69 = F_27 ( V_59 ) ;
V_70 = F_28 ( V_59 ) ;
if ( ! ( F_45 ( V_56 ) & V_76 ) ) {
V_66 = F_47 ( V_67 , V_55 , V_69 , & V_70 ,
& V_64 , NULL ) ;
} else {
V_65 = F_48 ( ~ 0 , ( T_5 * ) V_62 , sizeof( * V_62 ) ) ;
V_66 = F_47 ( V_67 , V_55 , V_69 , & V_70 ,
& V_64 , & V_65 ) ;
V_67 = F_43 ( V_56 , 0 ) ;
if ( V_55 % 4 )
V_65 = F_48 ( V_65 , V_67 + V_55 , 4 - ( V_55 % 4 ) ) ;
if ( ~ V_65 != F_49 ( F_50 ( V_56 ) ) ) {
V_77:
V_17 = F_8 ( V_3 -> V_17 , F_9 () ) ;
V_17 -> V_80 ++ ;
if ( V_17 -> V_81 ++ < V_82 )
F_51 ( V_83 L_8
L_9 ,
V_3 -> V_84 ) ;
F_10 () ;
if ( V_7 -> V_21 & V_79 ) {
V_71 = V_85 ;
goto V_74;
}
return;
}
}
if ( V_7 -> V_86 == V_63 )
V_7 -> V_86 += V_66 ;
V_7 -> V_43 += V_66 ;
if ( F_52 ( V_7 -> V_21 & V_87 ) &&
V_7 -> V_43 == V_7 -> V_75 - V_7 -> V_88 )
F_25 ( V_7 ) ;
return;
V_74:
F_53 ( V_7 , V_71 ) ;
}
static int F_54 ( struct V_1 * V_7 , struct V_19 * V_20 ,
T_3 V_64 , T_3 V_89 )
{
struct V_90 * V_91 ;
struct V_58 * V_59 ;
struct V_68 * V_69 ;
struct V_54 * V_56 = NULL ;
struct V_2 * V_3 = V_7 -> V_9 ;
struct V_92 * V_92 ;
T_3 V_93 ;
T_3 V_94 ;
T_3 V_95 ;
T_3 V_96 ;
T_3 V_97 , V_73 ;
T_3 V_98 ;
int error ;
void * V_14 = NULL ;
void * V_99 ;
int V_100 = V_3 -> V_101 ;
T_4 V_102 ;
F_55 ( V_89 <= 0 ) ;
if ( F_52 ( V_64 + V_89 > V_7 -> V_75 ) ) {
F_44 ( V_7 , L_10
L_11 , V_89 , V_64 ) ;
F_23 ( V_7 ) ;
return 0 ;
} else if ( V_64 != V_7 -> V_43 ) {
F_44 ( V_7 , L_12
L_13 , V_89 , V_64 ) ;
}
V_94 = V_7 -> V_103 ;
if ( V_3 -> V_104 ) {
V_94 = F_56 ( V_89 , ( T_3 ) V_3 -> V_105 ) ;
F_44 ( V_7 , L_14 ,
V_7 , V_89 , V_3 -> V_105 , V_94 ) ;
}
if ( V_94 > 512 )
V_94 &= ~ ( 512 - 1 ) ;
V_59 = V_7 -> V_41 ;
V_93 = V_89 ;
V_73 = V_97 = V_64 ;
V_95 = 0 ;
V_20 = V_3 -> V_30 . V_106 ( V_20 ) ;
V_102 = V_107 ;
F_55 ( ! V_20 ) ;
V_69 = F_27 ( V_59 ) ;
while ( V_93 > 0 && V_69 ) {
if ( V_64 >= V_69 -> V_108 ) {
V_64 -= V_69 -> V_108 ;
V_69 = F_57 ( V_69 ) ;
continue;
}
if ( ! V_56 ) {
V_95 = F_56 ( V_94 , V_93 ) ;
if ( V_95 % 4 )
V_100 = 0 ;
V_56 = F_37 ( V_3 , V_100 ? 0 : V_95 ) ;
if ( ! V_56 )
return - V_109 ;
V_14 = F_40 ( V_56 ) + 1 ;
V_73 = V_97 ;
F_58 ( V_56 ) = V_7 -> V_103 ;
}
V_98 = V_64 + V_69 -> V_64 ;
V_96 = F_56 ( V_95 , V_69 -> V_108 - V_64 ) ;
V_96 = F_56 ( V_96 ,
( T_3 ) ( V_110 - ( V_98 & ~ V_111 ) ) ) ;
V_92 = F_59 ( V_69 ) + ( V_98 >> V_112 ) ;
if ( V_100 ) {
F_60 ( V_92 ) ;
F_61 ( F_62 ( V_56 ) ,
F_63 ( F_62 ( V_56 ) ) -> V_113 ,
V_92 , V_98 & ~ V_111 , V_96 ) ;
F_62 ( V_56 ) -> V_75 += V_96 ;
F_42 ( V_56 ) += V_96 ;
F_62 ( V_56 ) -> V_114 += V_110 ;
} else {
V_99 = F_64 ( V_92 ) ;
memcpy ( V_14 , ( char * ) V_99 + ( V_98 & ~ V_111 ) ,
V_96 ) ;
F_65 ( V_99 ) ;
V_14 += V_96 ;
}
V_64 += V_96 ;
V_97 += V_96 ;
V_95 -= V_96 ;
V_93 -= V_96 ;
if ( ( F_63 ( F_62 ( V_56 ) ) -> V_113 < V_115 ) &&
( V_95 ) )
continue;
if ( V_93 == 0 )
V_102 |= V_116 | V_117 ;
V_91 = F_66 ( V_20 ) ;
F_67 ( V_56 , V_118 , V_91 -> V_119 , V_91 -> V_120 ,
V_121 , V_102 , V_73 ) ;
error = V_3 -> V_30 . V_122 ( V_3 , V_20 , V_56 ) ;
if ( error ) {
F_55 ( 1 ) ;
return error ;
}
V_56 = NULL ;
}
V_7 -> V_43 += V_89 ;
return 0 ;
}
static void F_68 ( struct V_1 * V_7 , struct V_54 * V_56 )
{
int V_123 = 1 ;
struct V_124 * V_125 ;
struct V_61 * V_62 ;
V_62 = F_40 ( V_56 ) ;
switch ( V_62 -> V_126 ) {
case V_127 :
break;
case V_128 :
V_125 = F_43 ( V_56 , sizeof( * V_125 ) ) ;
if ( V_125 && V_125 -> V_129 == V_130 )
break;
default:
V_123 = 0 ;
}
if ( V_123 ) {
V_7 -> V_21 |= V_131 ;
V_7 -> V_21 &= ~ V_29 ;
if ( V_7 -> V_132 )
F_69 ( & V_7 -> V_133 ) ;
else
F_25 ( V_7 ) ;
}
}
static void F_70 ( struct V_19 * V_20 , struct V_54 * V_56 , void * V_134 )
{
struct V_1 * V_7 = (struct V_1 * ) V_134 ;
struct V_2 * V_3 = V_7 -> V_9 ;
struct V_61 * V_62 ;
struct V_135 * V_136 ;
T_5 V_137 ;
int V_138 = 0 ;
if ( F_71 ( V_56 ) ) {
F_72 ( V_7 , V_56 ) ;
return;
}
V_62 = F_40 ( V_56 ) ;
V_137 = V_62 -> V_126 ;
if ( V_3 -> V_21 != V_139 )
goto V_140;
if ( F_17 ( V_7 ) )
goto V_140;
if ( V_62 -> V_141 == V_142 ) {
F_68 ( V_7 , V_56 ) ;
goto V_50;
}
if ( V_7 -> V_21 & ( V_131 | V_29 ) )
goto V_50;
if ( V_137 == V_143 ) {
F_55 ( F_45 ( V_56 ) & V_76 ) ;
V_136 = F_43 ( V_56 , sizeof( * V_136 ) ) ;
F_55 ( ! V_136 ) ;
V_138 = F_54 ( V_7 , V_20 ,
( T_3 ) F_41 ( V_136 -> V_144 ) ,
( T_3 ) F_41 ( V_136 -> V_145 ) ) ;
if ( ! V_138 )
V_20 -> V_146 = V_7 -> V_43 ;
} else if ( V_137 == V_118 ) {
F_55 ( F_42 ( V_56 ) < sizeof( * V_62 ) ) ;
F_39 ( V_7 , V_56 ) ;
V_20 -> V_146 = V_7 -> V_86 ;
} else if ( V_137 == V_147 ) {
F_55 ( F_45 ( V_56 ) & V_76 ) ;
F_73 ( V_7 , V_56 ) ;
} else {
F_44 ( V_7 , L_15 , V_137 ) ;
}
V_50:
F_20 ( V_7 ) ;
V_140:
F_74 ( V_56 ) ;
}
static void F_73 ( struct V_1 * V_7 , struct V_54 * V_56 )
{
struct V_61 * V_62 ;
struct V_148 * V_149 ;
struct V_150 * V_151 ;
struct V_152 * V_153 ;
T_4 V_154 ;
T_4 V_155 ;
T_4 V_156 = 0 ;
T_4 V_157 = 0 ;
T_5 V_44 = 0 ;
V_154 = F_42 ( V_56 ) ;
V_62 = (struct V_61 * ) F_75 ( V_56 ) ;
if ( F_52 ( V_154 < sizeof( * V_62 ) + sizeof( * V_149 ) ) )
goto V_158;
V_154 -= sizeof( * V_62 ) ;
V_149 = (struct V_148 * ) ( V_62 + 1 ) ;
V_7 -> V_159 = V_149 -> V_160 ;
V_44 = V_149 -> F_45 ;
V_7 -> V_161 = V_44 ;
V_155 = V_7 -> V_75 ;
F_29 ( V_7 ) ;
if ( F_52 ( ( V_44 & ~ V_162 ) || V_149 -> V_160 ) ) {
V_151 = ( void * ) ( V_149 + 1 ) ;
if ( V_44 & ( V_163 | V_164 ) ) {
if ( V_154 < sizeof( * V_149 ) + sizeof( * V_151 ) )
goto V_158;
V_153 = (struct V_152 * ) ( V_151 + 1 ) ;
if ( V_44 & V_163 ) {
V_156 = F_41 ( V_151 -> V_165 ) ;
if ( V_156 != sizeof( * V_153 ) )
goto V_158;
if ( V_7 -> V_132 ) {
V_7 -> V_159 = V_153 -> V_166 ;
F_69 ( & V_7 -> V_133 ) ;
return;
}
}
if ( V_44 & V_164 ) {
V_157 = F_41 ( V_151 -> V_167 ) ;
if ( V_157 > V_168 )
V_157 = V_168 ;
memcpy ( V_7 -> V_41 -> V_169 ,
( char * ) V_153 + V_156 , V_157 ) ;
}
}
if ( V_44 & ( V_170 | V_171 ) ) {
if ( V_154 < sizeof( * V_149 ) + sizeof( V_151 -> V_172 ) )
goto V_158;
if ( V_44 & V_170 ) {
V_7 -> V_88 = F_41 ( V_151 -> V_172 ) ;
if ( ! ( V_44 & V_164 ) &&
( V_149 -> V_160 == 0 ) &&
( F_76 ( V_7 -> V_41 ) -
V_7 -> V_88 ) < V_7 -> V_41 -> V_173 )
goto V_74;
V_155 -= V_7 -> V_88 ;
} else {
V_7 -> V_34 = V_35 ;
}
}
}
V_7 -> V_21 |= V_87 ;
if ( F_52 ( V_7 -> V_43 != V_155 ) ) {
if ( V_7 -> V_43 < V_155 ) {
F_21 ( V_7 , 2 ) ;
return;
}
V_7 -> V_34 = V_78 ;
F_44 ( V_7 , L_16
L_17 ,
V_7 -> V_174 -> V_84 ,
V_7 -> V_43 , V_155 , V_7 -> V_75 ) ;
}
F_25 ( V_7 ) ;
return;
V_158:
F_44 ( V_7 , L_18
L_19 , V_44 , F_42 ( V_56 ) , V_156 , V_157 ) ;
V_74:
V_7 -> V_34 = V_35 ;
F_25 ( V_7 ) ;
}
static void F_25 ( struct V_1 * V_7 )
{
struct V_2 * V_3 = V_7 -> V_9 ;
struct V_19 * V_20 ;
struct V_90 * V_91 ;
T_4 V_102 ;
if ( V_7 -> V_21 & V_29 )
return;
if ( V_7 -> V_21 & V_131 ) {
if ( ! V_7 -> V_34 )
V_7 -> V_34 = V_175 ;
} else {
if ( V_7 -> V_43 < V_7 -> V_75 && ! V_7 -> V_33 &&
( ! ( V_7 -> V_161 & V_170 ) ||
V_7 -> V_43 < V_7 -> V_75 - V_7 -> V_88 ) ) {
V_7 -> V_34 = V_176 ;
V_7 -> V_33 = 0 ;
}
}
V_20 = V_7 -> V_26 ;
if ( V_20 ) {
V_7 -> V_26 = NULL ;
if ( F_52 ( V_7 -> V_161 & V_162 ) ) {
struct V_54 * V_177 ;
struct V_19 * V_178 ;
V_178 = V_3 -> V_30 . V_106 ( V_20 ) ;
V_177 = F_36 ( V_7 -> V_9 , 0 ) ;
if ( V_177 ) {
V_102 = V_116 ;
V_102 |= V_179 | V_117 ;
V_91 = F_66 ( V_20 ) ;
F_67 ( V_177 , V_180 ,
V_91 -> V_119 , V_91 -> V_120 ,
V_121 , V_102 , 0 ) ;
V_3 -> V_30 . V_122 ( V_3 , V_178 , V_177 ) ;
}
}
V_3 -> V_30 . V_32 ( V_20 ) ;
}
if ( V_7 -> V_41 )
F_77 ( V_7 ) ;
}
static void F_78 ( struct V_1 * V_7 , int error )
{
struct V_2 * V_3 = V_7 -> V_9 ;
if ( V_7 -> V_26 ) {
V_3 -> V_30 . V_32 ( V_7 -> V_26 ) ;
V_7 -> V_26 = NULL ;
}
V_7 -> V_34 = error ;
}
static void F_79 ( struct V_2 * V_3 , unsigned int V_181 ,
unsigned int V_182 , int error )
{
struct V_5 * V_6 = F_2 ( V_3 ) ;
struct V_1 * V_7 ;
struct V_58 * V_183 ;
unsigned long V_44 ;
F_31 ( & V_6 -> V_184 , V_44 ) ;
V_185:
F_80 (fsp, &si->scsi_pkt_queue, list) {
V_183 = V_7 -> V_41 ;
if ( V_181 != - 1 && F_81 ( V_183 ) != V_181 )
continue;
if ( V_182 != - 1 && V_183 -> V_186 -> V_182 != V_182 )
continue;
F_14 ( V_7 ) ;
F_34 ( & V_6 -> V_184 , V_44 ) ;
if ( ! F_17 ( V_7 ) ) {
F_78 ( V_7 , error ) ;
F_77 ( V_7 ) ;
F_20 ( V_7 ) ;
}
F_11 ( V_7 ) ;
F_31 ( & V_6 -> V_184 , V_44 ) ;
goto V_185;
}
F_34 ( & V_6 -> V_184 , V_44 ) ;
}
static void F_82 ( struct V_2 * V_3 )
{
F_79 ( V_3 , - 1 , - 1 , V_187 ) ;
}
static int F_83 ( struct V_2 * V_3 , struct V_1 * V_7 )
{
struct V_5 * V_6 = F_2 ( V_3 ) ;
unsigned long V_44 ;
int V_138 ;
V_7 -> V_41 -> V_188 . V_189 = ( char * ) V_7 ;
V_7 -> V_190 . V_191 = F_84 ( V_7 -> V_75 ) ;
V_7 -> V_190 . V_192 = V_7 -> V_37 & ~ V_193 ;
F_85 ( V_7 -> V_41 -> V_186 -> V_182 , & V_7 -> V_190 . V_194 ) ;
memcpy ( V_7 -> V_190 . V_195 , V_7 -> V_41 -> V_196 , V_7 -> V_41 -> V_197 ) ;
F_31 ( & V_6 -> V_184 , V_44 ) ;
F_86 ( & V_7 -> V_15 , & V_6 -> V_198 ) ;
F_34 ( & V_6 -> V_184 , V_44 ) ;
V_138 = V_3 -> V_30 . V_199 ( V_3 , V_7 , F_70 ) ;
if ( F_52 ( V_138 ) ) {
F_31 ( & V_6 -> V_184 , V_44 ) ;
V_7 -> V_41 -> V_188 . V_189 = NULL ;
F_87 ( & V_7 -> V_15 ) ;
F_34 ( & V_6 -> V_184 , V_44 ) ;
}
return V_138 ;
}
static inline unsigned int F_88 ( struct V_1 * V_7 )
{
struct V_200 * V_201 = V_7 -> V_174 -> V_202 ;
return F_89 ( V_201 -> V_203 ) + V_204 ;
}
static int F_90 ( struct V_2 * V_3 , struct V_1 * V_7 ,
void (* F_91)( struct V_19 * ,
struct V_54 * V_56 ,
void * V_134 ) )
{
struct V_54 * V_56 ;
struct V_19 * V_20 ;
struct V_205 * V_174 ;
struct V_200 * V_201 ;
const T_3 V_55 = sizeof( V_7 -> V_190 ) ;
int V_138 = 0 ;
if ( F_17 ( V_7 ) )
return 0 ;
V_56 = F_36 ( V_3 , sizeof( V_7 -> V_190 ) ) ;
if ( ! V_56 ) {
V_138 = - 1 ;
goto V_50;
}
memcpy ( F_43 ( V_56 , V_55 ) , & V_7 -> V_190 , V_55 ) ;
F_92 ( V_56 ) = V_7 ;
V_174 = V_7 -> V_174 ;
V_7 -> V_103 = V_174 -> V_206 ;
V_201 = V_174 -> V_202 ;
F_67 ( V_56 , V_207 , V_174 -> V_84 ,
V_201 -> V_208 -> V_84 , V_121 ,
V_209 , 0 ) ;
V_20 = V_3 -> V_30 . V_210 ( V_3 , V_56 , F_91 , F_16 ,
V_7 , 0 ) ;
if ( ! V_20 ) {
V_138 = - 1 ;
goto V_50;
}
V_7 -> V_26 = V_20 ;
F_14 ( V_7 ) ;
F_93 ( & V_7 -> V_13 , V_211 , ( unsigned long ) V_7 ) ;
if ( V_201 -> V_44 & V_212 )
F_21 ( V_7 , F_88 ( V_7 ) ) ;
V_50:
F_20 ( V_7 ) ;
return V_138 ;
}
static void F_72 ( struct V_1 * V_7 , struct V_54 * V_56 )
{
int error = F_94 ( V_56 ) ;
if ( F_17 ( V_7 ) )
return;
if ( error == - V_213 ) {
F_24 ( V_7 ) ;
goto V_50;
}
V_7 -> V_21 &= ~ V_29 ;
V_7 -> V_34 = V_214 ;
F_25 ( V_7 ) ;
V_50:
F_20 ( V_7 ) ;
}
static int F_95 ( struct V_1 * V_7 )
{
int V_138 = V_215 ;
unsigned long V_216 ;
if ( F_23 ( V_7 ) )
return V_215 ;
F_96 ( & V_7 -> V_133 ) ;
V_7 -> V_132 = 1 ;
F_19 ( & V_7 -> V_16 ) ;
V_216 = F_97 ( & V_7 -> V_133 ,
V_217 ) ;
F_18 ( & V_7 -> V_16 ) ;
V_7 -> V_132 = 0 ;
if ( ! V_216 ) {
F_44 ( V_7 , L_20 ) ;
} else if ( V_7 -> V_21 & V_131 ) {
F_44 ( V_7 , L_21 ) ;
V_138 = V_218 ;
F_25 ( V_7 ) ;
}
return V_138 ;
}
static void F_98 ( unsigned long V_14 )
{
struct V_1 * V_7 = (struct V_1 * ) V_14 ;
struct V_2 * V_3 = V_7 -> V_9 ;
if ( V_3 -> V_30 . V_199 ( V_3 , V_7 , V_219 ) ) {
if ( V_7 -> V_220 ++ >= V_221 )
return;
if ( F_17 ( V_7 ) )
return;
F_93 ( & V_7 -> V_13 , F_98 , ( unsigned long ) V_7 ) ;
F_21 ( V_7 , F_88 ( V_7 ) ) ;
F_20 ( V_7 ) ;
}
}
static int F_99 ( struct V_2 * V_3 , struct V_1 * V_7 ,
unsigned int V_181 , unsigned int V_182 )
{
int V_138 ;
V_7 -> V_190 . V_191 = F_84 ( V_7 -> V_75 ) ;
V_7 -> V_190 . V_222 = V_223 ;
F_85 ( V_182 , & V_7 -> V_190 . V_194 ) ;
V_7 -> V_132 = 1 ;
F_96 ( & V_7 -> V_133 ) ;
F_98 ( ( unsigned long ) V_7 ) ;
V_138 = F_97 ( & V_7 -> V_133 , V_217 ) ;
F_18 ( & V_7 -> V_16 ) ;
V_7 -> V_21 |= V_22 ;
F_19 ( & V_7 -> V_16 ) ;
F_100 ( & V_7 -> V_13 ) ;
F_18 ( & V_7 -> V_16 ) ;
if ( V_7 -> V_26 ) {
V_3 -> V_30 . V_32 ( V_7 -> V_26 ) ;
V_7 -> V_26 = NULL ;
}
V_7 -> V_132 = 0 ;
F_19 ( & V_7 -> V_16 ) ;
if ( ! V_138 ) {
F_101 ( V_3 , L_22 ) ;
return V_215 ;
}
if ( V_7 -> V_159 != V_224 )
return V_215 ;
F_101 ( V_3 , L_23 , V_182 ) ;
F_79 ( V_3 , V_181 , V_182 , V_175 ) ;
return V_218 ;
}
static void V_219 ( struct V_19 * V_20 , struct V_54 * V_56 , void * V_134 )
{
struct V_1 * V_7 = V_134 ;
struct V_61 * V_62 ;
if ( F_71 ( V_56 ) ) {
return;
}
if ( F_17 ( V_7 ) )
goto V_140;
if ( ! V_7 -> V_26 || ! V_7 -> V_132 )
goto V_225;
V_62 = F_40 ( V_56 ) ;
if ( V_62 -> V_141 != V_142 )
F_73 ( V_7 , V_56 ) ;
V_7 -> V_26 = NULL ;
V_7 -> V_9 -> V_30 . V_32 ( V_20 ) ;
V_225:
F_20 ( V_7 ) ;
V_140:
F_74 ( V_56 ) ;
}
static void F_102 ( struct V_2 * V_3 )
{
F_79 ( V_3 , - 1 , - 1 , V_35 ) ;
}
static void V_211 ( unsigned long V_14 )
{
struct V_1 * V_7 = (struct V_1 * ) V_14 ;
struct V_205 * V_174 = V_7 -> V_174 ;
struct V_200 * V_201 = V_174 -> V_202 ;
if ( F_17 ( V_7 ) )
return;
if ( V_7 -> V_190 . V_222 )
goto V_50;
V_7 -> V_21 |= V_226 ;
if ( V_7 -> V_21 & V_87 )
F_25 ( V_7 ) ;
else if ( V_201 -> V_44 & V_212 )
F_103 ( V_7 ) ;
else
F_53 ( V_7 , V_227 ) ;
V_7 -> V_21 &= ~ V_226 ;
V_50:
F_20 ( V_7 ) ;
}
static void F_103 ( struct V_1 * V_7 )
{
struct V_2 * V_3 ;
struct V_54 * V_56 ;
struct V_205 * V_174 ;
struct V_200 * V_201 ;
V_3 = V_7 -> V_9 ;
V_174 = V_7 -> V_174 ;
V_201 = V_174 -> V_202 ;
if ( ! V_7 -> V_26 || V_201 -> V_228 != V_229 ) {
V_7 -> V_34 = V_187 ;
V_7 -> V_33 = 0 ;
F_25 ( V_7 ) ;
return;
}
V_56 = F_36 ( V_3 , sizeof( struct V_230 ) ) ;
if ( ! V_56 )
goto V_231;
F_104 ( V_56 ) = V_7 -> V_26 ;
F_67 ( V_56 , V_232 , V_174 -> V_84 ,
V_201 -> V_208 -> V_84 , V_233 ,
V_209 , 0 ) ;
if ( V_3 -> V_30 . V_234 ( V_3 , V_174 -> V_84 , V_56 , V_235 ,
V_236 , V_7 ,
2 * V_3 -> V_237 ) ) {
F_14 ( V_7 ) ;
return;
}
V_231:
if ( V_7 -> V_220 ++ < V_221 )
F_21 ( V_7 , F_88 ( V_7 ) ) ;
else
F_53 ( V_7 , V_227 ) ;
}
static void V_236 ( struct V_19 * V_20 , struct V_54 * V_56 , void * V_134 )
{
struct V_1 * V_7 = (struct V_1 * ) V_134 ;
struct V_238 * V_239 ;
struct V_240 * V_241 ;
T_4 V_242 ;
T_5 V_243 ;
T_4 V_64 ;
enum V_244 V_245 ;
enum V_246 V_137 ;
struct V_200 * V_201 ;
if ( F_71 ( V_56 ) ) {
F_105 ( V_7 , V_56 ) ;
return;
}
if ( F_17 ( V_7 ) )
goto V_140;
V_7 -> V_220 = 0 ;
V_243 = F_106 ( V_56 ) ;
if ( V_243 == V_247 ) {
V_241 = F_43 ( V_56 , sizeof( * V_241 ) ) ;
switch ( V_241 -> V_248 ) {
default:
F_44 ( V_7 , L_24
L_25 ,
V_7 -> V_174 -> V_84 , V_241 -> V_248 ,
V_241 -> V_249 ) ;
case V_250 :
F_44 ( V_7 , L_26 ) ;
V_201 = V_7 -> V_174 -> V_202 ;
V_201 -> V_44 &= ~ V_212 ;
break;
case V_251 :
case V_252 :
if ( V_241 -> V_249 == V_253 &&
V_7 -> V_43 == 0 ) {
F_24 ( V_7 ) ;
break;
}
F_53 ( V_7 , V_35 ) ;
break;
}
} else if ( V_243 == V_254 ) {
if ( V_7 -> V_21 & V_131 )
goto V_255;
V_245 = V_7 -> V_41 -> V_256 ;
V_239 = F_43 ( V_56 , sizeof( * V_239 ) ) ;
V_64 = F_41 ( V_239 -> V_257 ) ;
V_242 = F_41 ( V_239 -> V_258 ) ;
if ( V_242 & V_259 ) {
if ( V_245 == V_260 ) {
V_137 = V_147 ;
} else if ( V_7 -> V_86 == V_64 ) {
V_137 = V_147 ;
} else {
V_64 = V_7 -> V_86 ;
V_137 = V_118 ;
}
F_107 ( V_7 , V_137 , V_64 ) ;
} else if ( V_242 & V_261 ) {
F_21 ( V_7 , F_88 ( V_7 ) ) ;
} else {
V_137 = V_118 ;
if ( V_245 == V_260 ) {
V_137 = V_147 ;
if ( V_64 < V_7 -> V_75 )
V_137 = V_143 ;
} else if ( V_64 == V_7 -> V_86 ) {
V_137 = V_147 ;
} else if ( V_7 -> V_86 < V_64 ) {
V_64 = V_7 -> V_86 ;
}
F_107 ( V_7 , V_137 , V_64 ) ;
}
}
V_255:
F_20 ( V_7 ) ;
V_140:
F_11 ( V_7 ) ;
F_74 ( V_56 ) ;
}
static void F_105 ( struct V_1 * V_7 , struct V_54 * V_56 )
{
int error = F_94 ( V_56 ) ;
if ( F_17 ( V_7 ) )
goto V_140;
switch ( error ) {
case - V_213 :
F_24 ( V_7 ) ;
break;
default:
F_44 ( V_7 , L_27 ,
V_7 , V_7 -> V_174 -> V_84 , error ) ;
V_7 -> V_34 = V_214 ;
case - V_262 :
F_44 ( V_7 , L_28 ,
V_7 -> V_174 -> V_84 , error , V_7 -> V_220 ,
V_221 ) ;
if ( V_7 -> V_220 ++ < V_221 )
F_103 ( V_7 ) ;
else
F_53 ( V_7 , V_35 ) ;
break;
}
F_20 ( V_7 ) ;
V_140:
F_11 ( V_7 ) ;
}
static void F_53 ( struct V_1 * V_7 , T_5 V_263 )
{
V_7 -> V_34 = V_263 ;
V_7 -> V_159 = 0 ;
V_7 -> V_33 = 0 ;
F_23 ( V_7 ) ;
}
static void F_107 ( struct V_1 * V_7 , enum V_246 V_137 , T_4 V_64 )
{
struct V_2 * V_3 = V_7 -> V_9 ;
struct V_205 * V_174 ;
struct V_200 * V_201 ;
struct V_90 * V_91 = F_66 ( V_7 -> V_26 ) ;
struct V_19 * V_20 ;
struct V_264 * V_265 ;
struct V_54 * V_56 ;
unsigned int V_266 ;
V_174 = V_7 -> V_174 ;
V_201 = V_174 -> V_202 ;
if ( ! ( V_201 -> V_44 & V_267 ) ||
V_201 -> V_228 != V_229 )
goto V_231;
V_56 = F_36 ( V_3 , sizeof( * V_265 ) ) ;
if ( ! V_56 )
goto V_231;
V_265 = F_43 ( V_56 , sizeof( * V_265 ) ) ;
memset ( V_265 , 0 , sizeof( * V_265 ) ) ;
V_265 -> V_268 = V_269 ;
V_265 -> V_270 = F_108 ( V_91 -> V_271 ) ;
V_265 -> V_272 = F_108 ( V_91 -> V_273 ) ;
V_265 -> V_274 = V_137 ;
V_265 -> V_275 = F_84 ( V_64 ) ;
F_67 ( V_56 , V_276 , V_174 -> V_84 ,
V_201 -> V_208 -> V_84 , V_121 ,
V_209 , 0 ) ;
V_266 = F_88 ( V_7 ) ;
V_20 = V_3 -> V_30 . V_210 ( V_3 , V_56 , V_277 ,
F_16 ,
V_7 , F_109 ( V_266 ) ) ;
if ( ! V_20 )
goto V_231;
V_7 -> V_278 = V_20 ;
V_7 -> V_43 = V_64 ;
V_7 -> V_86 = V_64 ;
V_7 -> V_21 &= ~ V_87 ;
F_14 ( V_7 ) ;
return;
V_231:
F_24 ( V_7 ) ;
}
static void V_277 ( struct V_19 * V_20 , struct V_54 * V_56 , void * V_134 )
{
struct V_1 * V_7 = V_134 ;
struct V_61 * V_62 ;
if ( F_71 ( V_56 ) ) {
F_110 ( V_7 , V_56 ) ;
return;
}
if ( F_17 ( V_7 ) )
goto V_140;
V_62 = F_40 ( V_56 ) ;
if ( V_62 -> V_141 == V_142 ) {
F_20 ( V_7 ) ;
return;
}
switch ( F_106 ( V_56 ) ) {
case V_254 :
V_7 -> V_220 = 0 ;
F_21 ( V_7 , F_88 ( V_7 ) ) ;
break;
case V_247 :
default:
F_53 ( V_7 , V_35 ) ;
break;
}
F_20 ( V_7 ) ;
V_140:
V_7 -> V_9 -> V_30 . V_32 ( V_20 ) ;
F_74 ( V_56 ) ;
}
static void F_110 ( struct V_1 * V_7 , struct V_54 * V_56 )
{
if ( F_17 ( V_7 ) )
goto V_140;
switch ( F_94 ( V_56 ) ) {
case - V_262 :
if ( V_7 -> V_220 ++ < V_221 )
F_103 ( V_7 ) ;
else
F_53 ( V_7 , V_227 ) ;
break;
case - V_213 :
default:
F_24 ( V_7 ) ;
break;
}
F_20 ( V_7 ) ;
V_140:
V_7 -> V_9 -> V_30 . V_32 ( V_7 -> V_278 ) ;
}
static inline int F_111 ( struct V_2 * V_3 )
{
return ( V_3 -> V_21 == V_139 ) &&
V_3 -> V_279 && ! V_3 -> V_280 ;
}
int F_112 ( struct V_281 * V_282 , struct V_58 * V_183 )
{
struct V_2 * V_3 = F_113 ( V_282 ) ;
struct V_205 * V_174 = F_114 ( F_115 ( V_183 -> V_186 ) ) ;
struct V_1 * V_7 ;
struct V_200 * V_201 ;
int V_283 ;
int V_138 = 0 ;
struct V_60 * V_17 ;
V_283 = F_116 ( V_174 ) ;
if ( V_283 ) {
V_183 -> V_284 = V_283 ;
V_183 -> V_285 ( V_183 ) ;
return 0 ;
}
if ( ! * (struct V_286 * * ) V_174 -> V_202 ) {
V_183 -> V_284 = V_287 << 16 ;
V_183 -> V_285 ( V_183 ) ;
goto V_140;
}
V_201 = V_174 -> V_202 ;
if ( ! F_111 ( V_3 ) ) {
if ( V_3 -> V_280 )
F_35 ( V_3 ) ;
V_138 = V_288 ;
goto V_140;
}
V_7 = F_1 ( V_3 , V_289 ) ;
if ( V_7 == NULL ) {
V_138 = V_288 ;
goto V_140;
}
V_7 -> V_41 = V_183 ;
V_7 -> V_174 = V_174 ;
V_7 -> V_75 = F_76 ( V_183 ) ;
V_7 -> V_43 = 0 ;
V_17 = F_8 ( V_3 -> V_17 , F_9 () ) ;
if ( V_183 -> V_256 == V_290 ) {
V_7 -> V_37 = V_38 ;
V_17 -> V_291 ++ ;
V_17 -> V_292 += V_7 -> V_75 ;
} else if ( V_183 -> V_256 == V_260 ) {
V_7 -> V_37 = V_293 ;
V_17 -> V_294 ++ ;
V_17 -> V_295 += V_7 -> V_75 ;
} else {
V_7 -> V_37 = 0 ;
V_17 -> V_296 ++ ;
}
F_10 () ;
V_283 = F_83 ( V_3 , V_7 ) ;
if ( V_283 != 0 ) {
V_7 -> V_21 = V_297 ;
F_11 ( V_7 ) ;
V_138 = V_288 ;
}
V_140:
return V_138 ;
}
static void F_77 ( struct V_1 * V_7 )
{
struct V_5 * V_6 ;
struct V_58 * V_183 ;
struct V_2 * V_3 ;
unsigned long V_44 ;
F_29 ( V_7 ) ;
V_7 -> V_21 |= V_22 ;
if ( ! ( V_7 -> V_21 & V_226 ) ) {
F_19 ( & V_7 -> V_16 ) ;
F_100 ( & V_7 -> V_13 ) ;
F_18 ( & V_7 -> V_16 ) ;
}
V_3 = V_7 -> V_9 ;
V_6 = F_2 ( V_3 ) ;
if ( V_6 -> V_51 )
F_30 ( V_3 ) ;
V_183 = V_7 -> V_41 ;
F_117 ( V_183 ) = V_7 -> V_159 ;
switch ( V_7 -> V_34 ) {
case V_72 :
if ( V_7 -> V_159 == 0 ) {
V_183 -> V_284 = V_298 << 16 ;
if ( V_7 -> V_88 )
F_118 ( V_183 ) = V_7 -> V_88 ;
} else {
V_183 -> V_284 = ( V_298 << 16 ) | V_7 -> V_159 ;
}
break;
case V_35 :
F_44 ( V_7 , L_29
L_30 ) ;
V_183 -> V_284 = V_299 << 16 ;
break;
case V_176 :
if ( ( V_7 -> V_159 == 0 ) && ! ( V_7 -> V_37 & V_38 ) ) {
if ( V_7 -> V_21 & V_87 ) {
V_183 -> V_284 = V_298 << 16 ;
} else {
F_44 ( V_7 , L_31
L_32 ) ;
V_183 -> V_284 = V_299 << 16 ;
}
} else {
F_44 ( V_7 , L_29
L_33 ) ;
F_118 ( V_183 ) = V_7 -> V_88 ;
V_183 -> V_284 = ( V_299 << 16 ) | V_7 -> V_159 ;
}
break;
case V_78 :
F_44 ( V_7 , L_29
L_34 ) ;
V_183 -> V_284 = ( V_299 << 16 ) | V_7 -> V_159 ;
break;
case V_175 :
F_44 ( V_7 , L_29
L_35 ) ;
V_183 -> V_284 = ( V_299 << 16 ) | V_7 -> V_33 ;
break;
case V_300 :
F_44 ( V_7 , L_36
L_37 ) ;
V_183 -> V_284 = ( V_301 << 16 ) ;
break;
case V_187 :
F_44 ( V_7 , L_38
L_39 ) ;
V_183 -> V_284 = ( V_302 << 16 ) ;
break;
case V_85 :
F_44 ( V_7 , L_40
L_41 ) ;
V_183 -> V_284 = ( V_303 << 16 ) ;
break;
case V_227 :
F_44 ( V_7 , L_42
L_43 ) ;
V_183 -> V_284 = ( V_304 << 16 ) | V_7 -> V_33 ;
break;
default:
F_44 ( V_7 , L_29
L_44 ) ;
V_183 -> V_284 = ( V_299 << 16 ) ;
break;
}
if ( V_3 -> V_21 != V_139 && V_7 -> V_34 != V_72 )
V_183 -> V_284 = ( V_305 << 16 ) ;
F_31 ( & V_6 -> V_184 , V_44 ) ;
F_87 ( & V_7 -> V_15 ) ;
V_183 -> V_188 . V_189 = NULL ;
F_34 ( & V_6 -> V_184 , V_44 ) ;
V_183 -> V_285 ( V_183 ) ;
F_11 ( V_7 ) ;
}
int F_119 ( struct V_58 * V_183 )
{
struct V_1 * V_7 ;
struct V_2 * V_3 ;
struct V_5 * V_6 ;
int V_138 = V_215 ;
unsigned long V_44 ;
int V_283 ;
V_283 = F_120 ( V_183 ) ;
if ( V_283 )
return V_283 ;
V_3 = F_113 ( V_183 -> V_186 -> V_46 ) ;
if ( V_3 -> V_21 != V_139 )
return V_138 ;
else if ( ! V_3 -> V_279 )
return V_138 ;
V_6 = F_2 ( V_3 ) ;
F_31 ( & V_6 -> V_184 , V_44 ) ;
V_7 = F_121 ( V_183 ) ;
if ( ! V_7 ) {
F_34 ( & V_6 -> V_184 , V_44 ) ;
return V_218 ;
}
F_14 ( V_7 ) ;
F_34 ( & V_6 -> V_184 , V_44 ) ;
if ( F_17 ( V_7 ) ) {
V_138 = V_218 ;
goto V_306;
}
V_138 = F_95 ( V_7 ) ;
F_20 ( V_7 ) ;
V_306:
F_11 ( V_7 ) ;
return V_138 ;
}
int F_122 ( struct V_58 * V_183 )
{
struct V_2 * V_3 ;
struct V_1 * V_7 ;
struct V_205 * V_174 = F_114 ( F_115 ( V_183 -> V_186 ) ) ;
int V_138 = V_215 ;
int V_283 ;
V_283 = F_120 ( V_183 ) ;
if ( V_283 )
return V_283 ;
V_3 = F_113 ( V_183 -> V_186 -> V_46 ) ;
if ( V_3 -> V_21 != V_139 )
return V_138 ;
F_101 ( V_3 , L_45 , V_174 -> V_84 ) ;
V_7 = F_1 ( V_3 , V_307 ) ;
if ( V_7 == NULL ) {
F_51 ( V_83 L_46 ) ;
goto V_140;
}
V_7 -> V_174 = V_174 ;
V_138 = F_99 ( V_3 , V_7 , F_81 ( V_183 ) , V_183 -> V_186 -> V_182 ) ;
V_7 -> V_21 = V_297 ;
F_11 ( V_7 ) ;
V_140:
return V_138 ;
}
int F_123 ( struct V_58 * V_183 )
{
struct V_281 * V_282 = V_183 -> V_186 -> V_46 ;
struct V_2 * V_3 = F_113 ( V_282 ) ;
unsigned long V_308 ;
F_101 ( V_3 , L_47 ) ;
F_120 ( V_183 ) ;
V_3 -> V_30 . V_309 ( V_3 ) ;
V_308 = V_25 + V_310 ;
while ( ! F_111 ( V_3 ) && F_32 ( V_25 ,
V_308 ) )
F_124 ( 1000 ) ;
if ( F_111 ( V_3 ) ) {
F_33 ( V_311 , V_282 , L_48
L_49 , V_3 -> V_84 ) ;
return V_218 ;
} else {
F_33 ( V_311 , V_282 , L_50
L_51 ,
V_3 -> V_84 ) ;
return V_215 ;
}
}
int F_125 ( struct V_312 * V_313 )
{
struct V_205 * V_174 = F_114 ( F_115 ( V_313 ) ) ;
if ( ! V_174 || F_116 ( V_174 ) )
return - V_314 ;
if ( V_313 -> V_315 )
F_126 ( V_313 , V_316 ) ;
else
F_127 ( V_313 , F_128 ( V_313 ) ,
V_316 ) ;
return 0 ;
}
int F_129 ( struct V_312 * V_313 , int V_317 , int V_318 )
{
switch ( V_318 ) {
case V_319 :
F_127 ( V_313 , F_128 ( V_313 ) , V_317 ) ;
break;
case V_320 :
F_130 ( V_313 , V_317 ) ;
break;
case V_321 :
F_127 ( V_313 , F_128 ( V_313 ) , V_317 ) ;
break;
default:
return - V_322 ;
}
return V_313 -> V_323 ;
}
int F_131 ( struct V_312 * V_313 , int V_324 )
{
if ( V_313 -> V_315 ) {
F_132 ( V_313 , V_324 ) ;
if ( V_324 )
F_126 ( V_313 , V_313 -> V_323 ) ;
else
F_133 ( V_313 , V_313 -> V_323 ) ;
} else
V_324 = 0 ;
return V_324 ;
}
void F_134 ( struct V_2 * V_3 )
{
struct V_5 * V_6 = F_2 ( V_3 ) ;
if ( ! F_135 ( & V_6 -> V_198 ) )
F_51 ( V_53 L_52
L_53 , V_3 -> V_84 ) ;
F_136 ( V_6 -> V_8 ) ;
F_137 ( V_6 ) ;
V_3 -> V_325 = NULL ;
}
int F_138 ( void )
{
int V_138 = 0 ;
V_326 = F_139 ( L_54 ,
sizeof( struct V_1 ) ,
0 , V_327 , NULL ) ;
if ( ! V_326 ) {
F_51 ( V_53 L_55
L_56 ) ;
V_138 = - V_109 ;
}
return V_138 ;
}
void F_140 ( void )
{
if ( V_326 )
F_141 ( V_326 ) ;
}
int F_142 ( struct V_2 * V_3 )
{
int V_138 ;
struct V_5 * V_6 ;
if ( ! V_3 -> V_30 . V_199 )
V_3 -> V_30 . V_199 = F_90 ;
if ( ! V_3 -> V_30 . V_328 )
V_3 -> V_30 . V_328 = F_102 ;
if ( ! V_3 -> V_30 . V_329 )
V_3 -> V_30 . V_329 = F_82 ;
V_6 = F_143 ( sizeof( struct V_5 ) , V_330 ) ;
if ( ! V_6 )
return - V_109 ;
V_3 -> V_325 = V_6 ;
V_6 -> V_52 = V_3 -> V_46 -> V_45 ;
F_6 ( & V_6 -> V_198 ) ;
F_7 ( & V_6 -> V_184 ) ;
V_6 -> V_8 = F_144 ( 2 , V_326 ) ;
if ( ! V_6 -> V_8 ) {
V_138 = - V_109 ;
goto V_331;
}
return 0 ;
V_331:
F_137 ( V_6 ) ;
return V_138 ;
}
