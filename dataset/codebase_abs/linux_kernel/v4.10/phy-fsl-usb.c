static T_1 F_1 ( const unsigned T_2 * V_1 )
{
return F_2 ( V_1 ) ;
}
static T_1 F_3 ( const unsigned T_2 * V_1 )
{
return F_4 ( V_1 ) ;
}
static void F_5 ( T_1 V_2 , unsigned T_2 * V_1 )
{
F_6 ( V_1 , V_2 ) ;
}
static void F_7 ( T_1 V_2 , unsigned T_2 * V_1 )
{
F_8 ( V_1 , V_2 ) ;
}
int F_9 ( T_3 V_3 , T_3 V_4 )
{
T_1 V_5 ;
V_5 = 0x60000000 | ( V_3 << 16 ) | V_4 ;
F_10 ( V_5 , & V_6 -> V_7 ) ;
return 0 ;
}
void F_11 ( struct V_8 * V_9 , int V_10 )
{
T_1 V_11 ;
V_11 = F_12 ( & V_6 -> V_12 ) & ~ V_13 ;
if ( V_10 )
V_11 = ( V_11 & ~ V_14 ) |
V_15 ;
else
V_11 &= ~ V_15 ;
F_10 ( V_11 , & V_6 -> V_12 ) ;
}
void F_13 ( int V_10 )
{
T_1 V_11 ;
V_11 = F_12 ( & V_6 -> V_12 ) & ~ V_13 ;
if ( V_10 )
V_11 = ( V_11 & ~ V_15 ) |
V_14 ;
else
V_11 &= ~ V_14 ;
F_10 ( V_11 , & V_6 -> V_12 ) ;
}
void F_14 ( struct V_8 * V_9 , int V_10 )
{
T_1 V_11 ;
if ( V_10 ) {
V_11 = F_12 ( & V_6 -> V_16 ) & ~ V_17 ;
F_10 ( V_11 | V_18 , & V_6 -> V_16 ) ;
} else {
V_11 = F_12 ( & V_6 -> V_16 ) &
~ V_17 & ~ V_18 ;
F_10 ( V_11 , & V_6 -> V_16 ) ;
}
}
void F_15 ( struct V_8 * V_9 , int V_10 )
{
T_1 V_11 ;
V_11 = F_12 ( & V_6 -> V_12 ) & ~ V_13 ;
if ( V_10 )
V_11 |= V_19 ;
else
V_11 &= ~ V_19 ;
F_10 ( V_11 , & V_6 -> V_12 ) ;
}
void F_16 ( struct V_8 * V_9 , int V_10 )
{
T_1 V_11 ;
V_11 = F_12 ( & V_20 -> V_21 -> V_16 ) & ~ V_17 ;
if ( V_10 )
V_11 |= V_22 ;
else
V_11 |= V_23 ;
F_10 ( V_11 , & V_20 -> V_21 -> V_16 ) ;
}
void F_17 ( struct V_8 * V_9 )
{
T_1 V_11 ;
V_24 = 0 ;
#ifdef F_18
V_11 = F_12 ( & V_6 -> V_12 ) & ~ V_13 ;
V_11 |= V_25 ;
F_10 ( V_11 , & V_6 -> V_12 ) ;
#else
F_15 ( 1 ) ;
#endif
F_19 ( V_9 , V_26 ) ;
}
void F_20 ( unsigned long V_27 )
{
#ifdef F_18
#else
F_15 ( 0 ) ;
#endif
F_21 () ;
}
void F_21 ( void )
{
V_24 = 0 ;
F_11 ( & V_20 -> V_9 , 1 ) ;
F_19 ( & V_20 -> V_9 , V_28 ) ;
}
void F_22 ( unsigned long V_27 )
{
F_11 ( & V_20 -> V_9 , 0 ) ;
F_13 ( 1 ) ;
F_19 ( & V_20 -> V_9 , V_29 ) ;
}
void F_23 ( unsigned long V_27 )
{
F_13 ( 0 ) ;
V_24 = 1 ;
if ( ( V_20 -> V_30 . V_31 -> V_32 == V_33 ) &&
V_20 -> V_9 . V_34 )
V_20 -> V_9 . V_35 = 1 ;
}
void F_24 ( unsigned long V_27 )
{
F_25 ( L_1 ) ;
if ( ! V_20 -> V_30 . V_31 -> V_36 -> V_37 )
F_19 ( & V_20 -> V_9 , V_38 ) ;
else
F_26 ( & V_20 -> V_9 ) ;
}
void F_27 ( unsigned long V_39 )
{
* ( int * ) V_39 = 1 ;
}
int F_28 ( struct V_8 * V_9 )
{
V_40 = F_29 ( & F_27 , V_41 ,
( unsigned long ) & V_9 -> V_42 ) ;
if ( ! V_40 )
return - V_43 ;
V_44 = F_29 ( & F_27 , V_45 ,
( unsigned long ) & V_9 -> V_46 ) ;
if ( ! V_44 )
return - V_43 ;
V_47 = F_29 ( & F_27 , V_48 ,
( unsigned long ) & V_9 -> V_49 ) ;
if ( ! V_47 )
return - V_43 ;
V_50 = F_29 ( & F_27 , V_51 ,
( unsigned long ) & V_9 -> V_52 ) ;
if ( ! V_50 )
return - V_43 ;
V_53 = F_29 ( & F_27 , V_54 ,
( unsigned long ) & V_9 -> V_55 ) ;
if ( ! V_53 )
return - V_43 ;
V_56 = F_29 ( & F_27 , V_57 ,
( unsigned long ) & V_9 -> V_35 ) ;
if ( ! V_56 )
return - V_43 ;
V_38 = F_29 ( & F_24 , 10 ,
( unsigned long ) & V_9 ) ;
if ( ! V_38 )
return - V_43 ;
V_29 = F_29 ( & F_23 , V_58 , 0 ) ;
if ( ! V_29 )
return - V_43 ;
V_26 = F_29 ( & F_20 ,
V_59 , 0 ) ;
if ( ! V_26 )
return - V_43 ;
V_28 = F_29 ( & F_22 ,
V_60 , 0 ) ;
if ( ! V_28 )
return - V_43 ;
return 0 ;
}
void F_30 ( void )
{
F_31 ( V_40 ) ;
F_31 ( V_44 ) ;
F_31 ( V_47 ) ;
F_31 ( V_50 ) ;
F_31 ( V_53 ) ;
F_31 ( V_56 ) ;
F_31 ( V_38 ) ;
F_31 ( V_29 ) ;
F_31 ( V_26 ) ;
F_31 ( V_28 ) ;
}
static struct V_61 * F_32 ( enum V_62 V_63 )
{
struct V_61 * V_64 ;
switch ( V_63 ) {
case V_65 :
V_64 = V_40 ;
break;
case V_66 :
V_64 = V_40 ;
break;
case V_67 :
V_64 = V_40 ;
break;
case V_68 :
V_64 = V_40 ;
break;
case V_69 :
V_64 = V_40 ;
break;
case V_70 :
V_64 = V_40 ;
break;
case V_71 :
V_64 = V_40 ;
break;
default:
V_64 = NULL ;
}
return V_64 ;
}
void F_19 ( struct V_8 * V_9 , void * V_72 )
{
struct V_61 * V_64 = V_72 ;
struct V_61 * V_73 ;
F_33 (tmp_timer, &active_timers, list)
if ( V_73 == V_64 ) {
V_64 -> V_74 = V_64 -> V_75 ;
return;
}
V_64 -> V_74 = V_64 -> V_75 ;
F_34 ( & V_64 -> V_76 , & V_77 ) ;
}
static void F_35 ( struct V_8 * V_9 , enum V_62 V_63 )
{
struct V_61 * V_64 ;
V_64 = F_32 ( V_63 ) ;
if ( ! V_64 )
return;
F_19 ( V_9 , V_64 ) ;
}
void F_36 ( struct V_8 * V_9 , void * V_72 )
{
struct V_61 * V_64 = V_72 ;
struct V_61 * V_73 , * V_78 ;
F_37 (tmp_timer, del_tmp, &active_timers, list)
if ( V_73 == V_64 )
F_38 ( & V_64 -> V_76 ) ;
}
static void F_39 ( struct V_8 * V_9 , enum V_62 V_63 )
{
struct V_61 * V_64 ;
V_64 = F_32 ( V_63 ) ;
if ( ! V_64 )
return;
F_36 ( V_9 , V_64 ) ;
}
void F_40 ( void )
{
T_1 V_79 ;
V_79 = F_12 ( & V_6 -> V_80 ) ;
V_79 |= ( 1 << 1 ) ;
F_10 ( V_79 , & V_6 -> V_80 ) ;
while ( F_12 ( & V_6 -> V_80 ) & ( 1 << 1 ) )
;
}
int F_41 ( struct V_8 * V_9 , int V_10 )
{
struct V_81 * V_31 = V_9 -> V_31 ;
struct V_82 * V_83 ;
struct V_84 * V_85 =
F_42 ( V_31 -> V_86 , struct V_84 , V_30 ) ;
T_1 V_87 = 0 ;
if ( ! V_31 -> V_36 )
return - V_88 ;
V_83 = V_31 -> V_36 -> V_89 ;
V_9 -> V_90 =
! ! ( F_12 ( & V_6 -> V_12 ) & V_91 ) ;
if ( V_10 ) {
if ( V_85 -> V_92 )
goto V_93;
else {
F_40 () ;
F_25 ( L_2 ) ;
if ( V_83 -> V_94 -> V_95 && V_83 -> V_94 -> V_95 -> V_96 ) {
V_87 = V_83 -> V_94 -> V_95 -> V_96 ( V_83 ) ;
if ( V_9 -> V_97 ) {
F_14 ( V_9 , 1 ) ;
F_9 ( 0x0c , 0x20 ) ;
}
}
V_85 -> V_92 = 1 ;
}
} else {
if ( ! V_85 -> V_92 )
goto V_93;
else {
F_25 ( L_3 ) ;
if ( V_83 && V_83 -> V_94 ) {
if ( V_83 -> V_94 -> V_95 && V_83 -> V_94 -> V_95 -> V_98 )
V_87 = V_83 -> V_94 -> V_95 -> V_98 ( V_83 ) ;
if ( V_9 -> V_97 )
F_14 ( V_9 , 0 ) ;
}
V_85 -> V_92 = 0 ;
}
}
V_93:
return V_87 ;
}
int F_43 ( struct V_8 * V_9 , int V_10 )
{
struct V_81 * V_31 = V_9 -> V_31 ;
struct V_82 * V_83 ;
if ( ! V_31 -> V_99 || ! V_31 -> V_99 -> V_83 . V_100 )
return - V_88 ;
F_25 ( L_4 , V_10 ? L_5 : L_6 ) ;
V_83 = V_31 -> V_99 -> V_83 . V_100 ;
if ( V_10 ) {
if ( V_83 -> V_94 -> V_96 )
V_83 -> V_94 -> V_96 ( V_83 ) ;
} else {
if ( V_83 -> V_94 -> V_98 )
V_83 -> V_94 -> V_98 ( V_83 , V_101 ) ;
}
return 0 ;
}
static int F_44 ( struct V_81 * V_31 , struct V_102 * V_36 )
{
struct V_84 * V_85 ;
if ( ! V_31 )
return - V_88 ;
V_85 = F_42 ( V_31 -> V_86 , struct V_84 , V_30 ) ;
if ( V_85 != V_20 )
return - V_88 ;
V_31 -> V_36 = V_36 ;
V_85 -> V_9 . V_103 = 0 ;
V_85 -> V_9 . V_104 = 1 ;
if ( V_36 ) {
F_25 ( L_3 ) ;
V_31 -> V_36 -> V_105 = V_106 . V_105 ;
V_31 -> V_36 -> V_107 = V_85 -> V_9 . V_97 ;
V_85 -> V_92 = 1 ;
F_45 ( & V_85 -> V_108 , 100 ) ;
return 0 ;
} else {
if ( ! ( F_12 ( & V_85 -> V_21 -> V_12 ) &
V_109 ) ) {
struct V_8 * V_9 = & V_85 -> V_9 ;
V_31 -> V_32 = V_110 ;
V_9 -> V_111 = V_112 ;
}
}
V_85 -> V_92 = 0 ;
F_26 ( & V_85 -> V_9 ) ;
return 0 ;
}
static int F_46 ( struct V_81 * V_31 ,
struct V_113 * V_99 )
{
struct V_84 * V_85 ;
if ( ! V_31 )
return - V_88 ;
V_85 = F_42 ( V_31 -> V_86 , struct V_84 , V_30 ) ;
F_25 ( L_7 , ( int ) V_85 ) ;
F_25 ( L_8 , ( int ) V_20 ) ;
if ( V_85 != V_20 )
return - V_88 ;
if ( ! V_99 ) {
if ( ! V_31 -> V_114 )
V_31 -> V_99 -> V_115 -> V_116 ( V_31 -> V_99 , 0 ) ;
F_47 ( V_31 -> V_99 ) ;
V_31 -> V_99 = 0 ;
V_85 -> V_9 . V_117 = 0 ;
F_26 ( & V_85 -> V_9 ) ;
return 0 ;
}
V_31 -> V_99 = V_99 ;
V_31 -> V_99 -> V_118 = ! V_85 -> V_9 . V_97 ;
V_85 -> V_9 . V_117 = 1 ;
F_48 ( L_9 , V_85 -> V_9 . V_97 ) ;
if ( V_85 -> V_9 . V_97 == 1 ) {
F_41 ( & V_85 -> V_9 , 0 ) ;
F_49 ( & V_85 -> V_9 , 0 ) ;
F_43 ( & V_85 -> V_9 , 1 ) ;
}
return 0 ;
}
static int F_50 ( struct V_86 * V_30 , unsigned V_119 )
{
if ( ! V_20 )
return - V_88 ;
if ( V_30 -> V_31 -> V_32 == V_120 )
F_51 ( L_10 , V_119 ) ;
return 0 ;
}
static void F_52 ( struct V_121 * V_122 )
{
struct V_84 * V_123 = F_42 ( V_122 , struct V_84 , V_108 . V_122 ) ;
struct V_8 * V_9 = & V_123 -> V_9 ;
if ( V_9 -> V_97 ) {
F_41 ( V_9 , 0 ) ;
F_49 ( V_9 , 0 ) ;
F_43 ( V_9 , 1 ) ;
}
}
static int F_53 ( struct V_81 * V_31 )
{
struct V_84 * V_85 ;
if ( ! V_31 || V_31 -> V_32 != V_124 )
return - V_88 ;
V_85 = F_42 ( V_31 -> V_86 , struct V_84 , V_30 ) ;
if ( V_85 != V_20 )
return - V_88 ;
V_85 -> V_9 . V_117 = 1 ;
F_26 ( & V_85 -> V_9 ) ;
return 0 ;
}
static int F_54 ( struct V_81 * V_31 )
{
struct V_84 * V_85 ;
if ( ! V_31 )
return - V_88 ;
V_85 = F_42 ( V_31 -> V_86 , struct V_84 , V_30 ) ;
if ( V_85 != V_20 )
return - V_88 ;
F_48 ( L_11 ) ;
V_85 -> V_9 . V_104 = 0 ;
F_26 ( & V_85 -> V_9 ) ;
return 0 ;
}
T_4 F_55 ( int V_125 , void * V_126 )
{
struct V_8 * V_9 = & ( (struct V_84 * ) V_126 ) -> V_9 ;
struct V_81 * V_31 = ( (struct V_84 * ) V_126 ) -> V_30 . V_31 ;
T_1 V_127 , V_128 ;
V_128 = F_12 ( & V_6 -> V_12 ) ;
V_127 = V_128 & V_13 & ( V_128 >> 8 ) ;
F_10 ( V_128 , & V_6 -> V_12 ) ;
V_9 -> V_97 = ( V_128 & V_109 ) ? 1 : 0 ;
V_31 -> V_114 = ( V_9 -> V_97 == 0 ) ;
if ( V_127 ) {
if ( V_127 & V_129 ) {
V_9 -> V_97 = ( V_128 & V_109 ) ? 1 : 0 ;
V_31 -> V_114 = ( V_9 -> V_97 == 0 ) ;
if ( V_9 -> V_97 )
V_9 -> V_130 = 0 ;
else
V_9 -> V_131 = 0 ;
if ( V_31 -> V_36 )
V_31 -> V_36 -> V_107 = V_9 -> V_97 ;
if ( V_31 -> V_99 )
V_31 -> V_99 -> V_118 = ! V_9 -> V_97 ;
F_25 ( L_12 , V_9 -> V_97 ) ;
if ( V_9 -> V_97 ) {
F_45 (
& ( (struct V_84 * ) V_126 ) -> V_108 ,
100 ) ;
} else {
F_56 ( &
( (struct V_84 * ) V_126 ) ->
V_108 ) ;
F_43 ( V_9 , 0 ) ;
F_49 ( V_9 , 1 ) ;
F_41 ( V_9 , 1 ) ;
}
return V_132 ;
}
}
return V_133 ;
}
static int F_57 ( struct V_134 * V_135 )
{
struct V_84 * V_136 ;
int V_137 ;
if ( V_20 )
return 0 ;
V_136 = F_58 ( sizeof( struct V_84 ) , V_138 ) ;
if ( ! V_136 )
return - V_43 ;
V_136 -> V_30 . V_31 = F_58 ( sizeof( struct V_81 ) , V_138 ) ;
if ( ! V_136 -> V_30 . V_31 ) {
F_31 ( V_136 ) ;
return - V_43 ;
}
F_59 ( & V_136 -> V_108 , F_52 ) ;
F_60 ( & V_77 ) ;
V_137 = F_28 ( & V_136 -> V_9 ) ;
if ( V_137 ) {
F_51 ( L_13 ) ;
goto V_139;
}
F_61 ( & V_136 -> V_9 . V_140 ) ;
V_136 -> V_9 . V_115 = & V_141 ;
V_136 -> V_30 . V_142 = V_143 ;
V_136 -> V_30 . V_83 = & V_135 -> V_83 ;
V_136 -> V_30 . V_144 = F_50 ;
V_136 -> V_30 . V_31 -> V_86 = & V_136 -> V_30 ;
V_136 -> V_30 . V_31 -> V_145 = F_44 ;
V_136 -> V_30 . V_31 -> V_146 = F_46 ;
V_136 -> V_30 . V_31 -> V_147 = F_54 ;
V_136 -> V_30 . V_31 -> V_148 = F_53 ;
V_20 = V_136 ;
V_137 = F_62 ( & V_136 -> V_30 , V_149 ) ;
if ( V_137 ) {
F_63 ( V_150 L_14 ) ;
goto V_139;
}
return 0 ;
V_139:
F_30 () ;
F_31 ( V_136 -> V_30 . V_31 ) ;
F_31 ( V_136 ) ;
return V_137 ;
}
int F_64 ( struct V_134 * V_135 )
{
struct V_84 * V_151 ;
struct V_86 * V_152 = F_65 ( V_149 ) ;
struct V_8 * V_9 ;
int V_137 ;
struct V_153 * V_154 ;
T_1 V_5 ;
struct V_155 * V_156 = F_66 ( & V_135 -> V_83 ) ;
V_151 = F_42 ( V_152 , struct V_84 , V_30 ) ;
V_9 = & V_151 -> V_9 ;
F_67 ( V_152 , V_110 ) ;
V_9 -> V_31 = V_151 -> V_30 . V_31 ;
V_154 = F_68 ( V_135 , V_157 , 0 ) ;
if ( ! V_154 )
return - V_158 ;
V_6 = F_69 ( V_154 -> V_159 , sizeof( struct V_160 ) ) ;
V_151 -> V_21 = (struct V_160 * ) V_6 ;
V_156 -> V_161 = ( void * ) V_6 ;
if ( V_156 -> V_162 && V_156 -> V_162 ( V_135 ) != 0 )
return - V_163 ;
if ( V_156 -> V_164 ) {
V_165 = F_1 ;
V_166 = F_5 ;
} else {
V_165 = F_3 ;
V_166 = F_7 ;
}
V_151 -> V_125 = F_70 ( V_135 , 0 ) ;
V_137 = F_71 ( V_151 -> V_125 , F_55 ,
V_167 , V_168 , V_151 ) ;
if ( V_137 ) {
F_72 ( V_151 -> V_30 . V_83 , L_15 ,
V_151 -> V_125 , V_137 ) ;
F_73 ( V_151 -> V_21 ) ;
F_31 ( V_151 -> V_30 . V_31 ) ;
F_31 ( V_151 ) ;
return V_137 ;
}
V_5 = F_12 ( & V_151 -> V_21 -> V_80 ) ;
V_5 &= ~ V_169 ;
F_10 ( V_5 , & V_151 -> V_21 -> V_80 ) ;
V_5 = F_12 ( & V_151 -> V_21 -> V_80 ) ;
V_5 |= V_170 ;
F_10 ( V_5 , & V_151 -> V_21 -> V_80 ) ;
while ( F_12 ( & V_151 -> V_21 -> V_80 ) & V_170 )
;
V_5 = V_171 | ( V_156 -> V_172 ? V_173 : 0 ) ;
F_10 ( V_5 , & V_151 -> V_21 -> V_174 ) ;
V_5 = F_12 ( & V_151 -> V_21 -> V_16 ) ;
V_5 &= ~ ( V_175 | V_176 ) ;
switch ( V_156 -> V_177 ) {
case V_178 :
V_5 |= V_179 ;
break;
case V_180 :
V_5 |= V_181 ;
case V_182 :
V_5 |= V_183 ;
default:
break;
}
F_10 ( V_5 , & V_151 -> V_21 -> V_16 ) ;
if ( V_156 -> V_184 ) {
V_5 = F_74 ( & V_151 -> V_21 -> V_185 ) ;
V_5 |= V_186 ;
F_75 ( V_5 , & V_151 -> V_21 -> V_185 ) ;
}
V_5 = F_12 ( & V_151 -> V_21 -> V_12 ) ;
V_5 &= ~ V_187 ;
V_5 |= V_188 | V_14 ;
F_10 ( V_5 , & V_151 -> V_21 -> V_12 ) ;
if ( F_12 ( & V_151 -> V_21 -> V_12 ) & V_109 ) {
V_151 -> V_30 . V_31 -> V_32 = V_110 ;
V_151 -> V_9 . V_97 = 1 ;
} else {
V_151 -> V_30 . V_31 -> V_32 = V_189 ;
V_151 -> V_9 . V_97 = 0 ;
}
F_48 ( L_16 , V_151 -> V_9 . V_97 ) ;
V_5 = F_12 ( & V_151 -> V_21 -> V_12 ) ;
V_5 |= V_190 ;
V_5 &= ~ ( V_14 | V_191 ) ;
F_10 ( V_5 , & V_151 -> V_21 -> V_12 ) ;
return 0 ;
}
static int F_76 ( struct V_82 * V_83 ,
struct V_192 * V_193 , char * V_194 )
{
struct V_8 * V_9 = & V_20 -> V_9 ;
char * V_195 = V_194 ;
unsigned V_196 = V_197 ;
int V_63 ;
F_77 ( & V_9 -> V_140 ) ;
V_63 = F_78 ( V_195 , V_196 ,
V_143 L_17 L_18 ,
V_198 ) ;
V_196 -= V_63 ;
V_195 += V_63 ;
V_63 = F_78 ( V_195 , V_196 ,
L_19
L_20
L_21
L_22
L_23
L_24 ,
F_12 ( & V_6 -> V_12 ) ,
F_12 ( & V_6 -> V_16 ) ,
F_12 ( & V_6 -> V_174 ) ,
F_12 ( & V_6 -> V_80 ) ,
F_12 ( & V_6 -> V_199 ) ,
F_12 ( & V_6 -> V_200 ) ) ;
V_196 -= V_63 ;
V_195 += V_63 ;
V_63 = F_78 ( V_195 , V_196 ,
L_25 ,
F_79 ( V_20 -> V_30 . V_31 -> V_32 ) ) ;
V_196 -= V_63 ;
V_195 += V_63 ;
V_63 = F_78 ( V_195 , V_196 ,
L_26
L_27
L_28
L_29
L_30
L_31
L_32
L_33
L_34
L_35
L_36
L_37
L_38
L_39
L_40 ,
V_9 -> V_104 ,
V_9 -> V_117 ,
V_9 -> V_201 ,
V_9 -> V_202 ,
V_9 -> V_131 ,
V_9 -> V_203 ,
V_9 -> V_204 ,
V_9 -> V_90 ,
V_9 -> V_205 ,
V_9 -> V_206 ,
V_9 -> V_130 ,
V_9 -> V_55 ,
V_9 -> V_207 ,
V_9 -> V_34 ,
V_9 -> V_97 ) ;
V_196 -= V_63 ;
V_195 += V_63 ;
F_80 ( & V_9 -> V_140 ) ;
return V_197 - V_196 ;
}
static long F_81 ( struct V_208 * V_208 , unsigned int V_209 ,
unsigned long V_210 )
{
T_1 V_87 = 0 ;
switch ( V_209 ) {
case V_211 :
V_87 = V_20 -> V_92 ;
break;
case V_212 :
V_20 -> V_9 . V_213 = V_210 ;
break;
case V_214 :
V_20 -> V_9 . V_103 = V_210 ;
break;
case V_215 :
V_20 -> V_9 . V_104 = V_210 ;
break;
case V_216 :
V_20 -> V_9 . V_117 = V_210 ;
break;
default:
break;
}
F_26 ( & V_20 -> V_9 ) ;
return V_87 ;
}
static int F_82 ( struct V_217 * V_217 , struct V_208 * V_208 )
{
return 0 ;
}
static int F_83 ( struct V_217 * V_217 , struct V_208 * V_208 )
{
return 0 ;
}
static int F_84 ( struct V_134 * V_135 )
{
int V_218 ;
if ( ! F_66 ( & V_135 -> V_83 ) )
return - V_88 ;
V_218 = F_57 ( V_135 ) ;
if ( V_218 ) {
F_85 ( & V_135 -> V_83 , L_41 ) ;
return V_218 ;
}
V_218 = F_64 ( V_135 ) ;
if ( V_218 ) {
F_85 ( & V_135 -> V_83 , L_42 ) ;
return V_218 ;
}
V_218 = F_86 ( V_219 , V_150 , & V_220 ) ;
if ( V_218 ) {
F_85 ( & V_135 -> V_83 , L_43 ) ;
return V_218 ;
}
V_218 = F_87 ( & V_135 -> V_83 , & V_221 ) ;
if ( V_218 )
F_88 ( & V_135 -> V_83 , L_44 ) ;
return V_218 ;
}
static int F_89 ( struct V_134 * V_135 )
{
struct V_155 * V_156 = F_66 ( & V_135 -> V_83 ) ;
F_90 ( & V_20 -> V_30 ) ;
F_91 ( V_20 -> V_125 , V_20 ) ;
F_73 ( ( void * ) V_6 ) ;
F_30 () ;
F_31 ( V_20 -> V_30 . V_31 ) ;
F_31 ( V_20 ) ;
F_92 ( & V_135 -> V_83 , & V_221 ) ;
F_93 ( V_219 , V_150 ) ;
if ( V_156 -> exit )
V_156 -> exit ( V_135 ) ;
return 0 ;
}
