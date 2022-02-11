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
T_3 F_9 ( T_3 V_3 )
{
T_1 V_4 ;
V_4 = 0x40000000 | ( V_3 << 16 ) ;
F_10 ( V_4 , & V_5 -> V_6 ) ;
F_11 ( 1000 ) ;
while ( V_4 & 0x40 )
V_4 = F_12 ( & V_5 -> V_6 ) ;
return ( F_13 ( V_4 ) & 0x0000ff00 ) >> 8 ;
}
int F_14 ( T_3 V_3 , T_3 V_7 )
{
T_1 V_4 ;
V_4 = 0x60000000 | ( V_3 << 16 ) | V_7 ;
F_10 ( V_4 , & V_5 -> V_6 ) ;
return 0 ;
}
void F_15 ( int V_8 )
{
T_1 V_9 ;
V_9 = F_12 ( & V_5 -> V_10 ) & ~ V_11 ;
if ( V_8 )
V_9 = ( V_9 & ~ V_12 ) |
V_13 ;
else
V_9 &= ~ V_13 ;
F_10 ( V_9 , & V_5 -> V_10 ) ;
}
void F_16 ( int V_8 )
{
T_1 V_9 ;
V_9 = F_12 ( & V_5 -> V_10 ) & ~ V_11 ;
if ( V_8 )
V_9 = ( V_9 & ~ V_13 ) |
V_12 ;
else
V_9 &= ~ V_12 ;
F_10 ( V_9 , & V_5 -> V_10 ) ;
}
void F_17 ( int V_8 )
{
T_1 V_9 ;
if ( V_8 ) {
V_9 = F_12 ( & V_5 -> V_14 ) & ~ V_15 ;
F_10 ( V_9 | V_16 , & V_5 -> V_14 ) ;
} else {
V_9 = F_12 ( & V_5 -> V_14 ) &
~ V_15 & ~ V_16 ;
F_10 ( V_9 , & V_5 -> V_14 ) ;
}
}
void F_18 ( int V_8 )
{
T_1 V_9 ;
V_9 = F_12 ( & V_5 -> V_10 ) & ~ V_11 ;
if ( V_8 )
V_9 |= V_17 ;
else
V_9 &= ~ V_17 ;
F_10 ( V_9 , & V_5 -> V_10 ) ;
}
void F_19 ( int V_8 )
{
T_1 V_9 ;
V_9 = F_12 ( & V_18 -> V_19 -> V_14 ) & ~ V_15 ;
if ( V_8 )
V_9 |= V_20 ;
else
V_9 |= V_21 ;
F_10 ( V_9 , & V_18 -> V_19 -> V_14 ) ;
}
void F_20 ( void )
{
T_1 V_9 ;
V_22 = 0 ;
#ifdef F_21
V_9 = F_12 ( & V_5 -> V_10 ) & ~ V_11 ;
V_9 |= V_23 ;
F_10 ( V_9 , & V_5 -> V_10 ) ;
#else
F_18 ( 1 ) ;
#endif
F_22 ( V_24 ) ;
}
void F_23 ( unsigned long V_25 )
{
#ifdef F_21
#else
F_18 ( 0 ) ;
#endif
F_24 () ;
}
void F_24 ( void )
{
V_22 = 0 ;
F_15 ( 1 ) ;
F_22 ( V_26 ) ;
}
void F_25 ( unsigned long V_25 )
{
F_15 ( 0 ) ;
F_16 ( 1 ) ;
F_22 ( V_27 ) ;
}
void F_26 ( unsigned long V_25 )
{
F_16 ( 0 ) ;
V_22 = 1 ;
if ( ( V_18 -> V_28 . V_29 == V_30 ) &&
V_18 -> V_31 . V_32 )
V_18 -> V_31 . V_33 = 1 ;
}
void F_27 ( unsigned long V_25 )
{
F_28 ( L_1 ) ;
if ( ! V_18 -> V_28 . V_34 -> V_35 -> V_36 )
F_22 ( V_37 ) ;
else
F_29 ( & V_18 -> V_31 ) ;
}
void F_30 ( unsigned long V_38 )
{
* ( int * ) V_38 = 1 ;
}
int F_31 ( struct V_39 * V_31 )
{
V_40 = F_32 ( & F_30 , V_41 ,
( unsigned long ) & V_31 -> V_42 ) ;
if ( ! V_40 )
return - V_43 ;
V_44 = F_32 ( & F_30 , V_45 ,
( unsigned long ) & V_31 -> V_46 ) ;
if ( ! V_44 )
return - V_43 ;
V_47 = F_32 ( & F_30 , V_48 ,
( unsigned long ) & V_31 -> V_49 ) ;
if ( ! V_47 )
return - V_43 ;
V_50 = F_32 ( & F_30 , V_51 ,
( unsigned long ) & V_31 -> V_52 ) ;
if ( ! V_50 )
return - V_43 ;
V_53 = F_32 ( & F_30 , V_54 ,
( unsigned long ) & V_31 -> V_55 ) ;
if ( ! V_53 )
return - V_43 ;
V_56 = F_32 ( & F_30 , V_57 ,
( unsigned long ) & V_31 -> V_33 ) ;
if ( ! V_56 )
return - V_43 ;
V_37 = F_32 ( & F_27 , 10 ,
( unsigned long ) & V_31 ) ;
if ( ! V_37 )
return - V_43 ;
V_27 = F_32 ( & F_26 , V_58 , 0 ) ;
if ( ! V_27 )
return - V_43 ;
V_24 = F_32 ( & F_23 ,
V_59 , 0 ) ;
if ( ! V_24 )
return - V_43 ;
V_26 = F_32 ( & F_25 ,
V_60 , 0 ) ;
if ( ! V_26 )
return - V_43 ;
return 0 ;
}
void F_33 ( void )
{
if ( V_40 != NULL )
F_34 ( V_40 ) ;
if ( V_44 != NULL )
F_34 ( V_44 ) ;
if ( V_47 != NULL )
F_34 ( V_47 ) ;
if ( V_50 != NULL )
F_34 ( V_50 ) ;
if ( V_53 != NULL )
F_34 ( V_53 ) ;
if ( V_56 != NULL )
F_34 ( V_56 ) ;
if ( V_37 != NULL )
F_34 ( V_37 ) ;
if ( V_27 != NULL )
F_34 ( V_27 ) ;
if ( V_24 != NULL )
F_34 ( V_24 ) ;
if ( V_26 != NULL )
F_34 ( V_26 ) ;
}
void F_22 ( void * V_61 )
{
struct V_62 * V_63 = V_61 ;
struct V_62 * V_64 ;
F_35 (tmp_timer, &active_timers, list)
if ( V_64 == V_63 ) {
V_63 -> V_65 = V_63 -> V_66 ;
return;
}
V_63 -> V_65 = V_63 -> V_66 ;
F_36 ( & V_63 -> V_67 , & V_68 ) ;
}
void F_37 ( void * V_61 )
{
struct V_62 * V_63 = V_61 ;
struct V_62 * V_64 , * V_69 ;
F_38 (tmp_timer, del_tmp, &active_timers, list)
if ( V_64 == V_63 )
F_39 ( & V_63 -> V_67 ) ;
}
int F_40 ( void )
{
struct V_62 * V_64 , * V_69 ;
int V_70 = 0 ;
F_38 (tmp_timer, del_tmp, &active_timers, list) {
V_64 -> V_65 -- ;
if ( ! V_64 -> V_65 ) {
F_39 ( & V_64 -> V_67 ) ;
V_64 -> V_71 ( V_64 -> V_7 ) ;
V_70 = 1 ;
}
}
return V_70 ;
}
void F_41 ( void )
{
T_1 V_72 ;
V_72 = F_12 ( & V_5 -> V_73 ) ;
V_72 |= ( 1 << 1 ) ;
F_10 ( V_72 , & V_5 -> V_73 ) ;
while ( F_12 ( & V_5 -> V_73 ) & ( 1 << 1 ) )
;
}
int F_42 ( struct V_39 * V_31 , int V_8 )
{
struct V_74 * V_34 = V_31 -> V_34 ;
struct V_75 * V_76 ;
struct V_77 * V_78 = F_43 ( V_34 -> V_28 , struct V_77 , V_28 ) ;
T_1 V_79 = 0 ;
if ( ! V_34 -> V_35 )
return - V_80 ;
V_76 = V_34 -> V_35 -> V_81 ;
V_31 -> V_82 =
! ! ( F_12 ( & V_5 -> V_10 ) & V_83 ) ;
if ( V_8 ) {
if ( V_78 -> V_84 )
goto V_85;
else {
F_41 () ;
F_28 ( L_2 ) ;
if ( V_76 -> V_86 -> V_87 && V_76 -> V_86 -> V_87 -> V_88 ) {
V_79 = V_76 -> V_86 -> V_87 -> V_88 ( V_76 ) ;
if ( V_31 -> V_89 ) {
F_17 ( 1 ) ;
F_14 ( 0x0c , 0x20 ) ;
}
}
V_78 -> V_84 = 1 ;
}
} else {
if ( ! V_78 -> V_84 )
goto V_85;
else {
F_28 ( L_3 ) ;
if ( V_76 && V_76 -> V_86 ) {
if ( V_76 -> V_86 -> V_87 && V_76 -> V_86 -> V_87 -> V_90 )
V_79 = V_76 -> V_86 -> V_87 -> V_90 ( V_76 ) ;
if ( V_31 -> V_89 )
F_17 ( 0 ) ;
}
V_78 -> V_84 = 0 ;
}
}
V_85:
return V_79 ;
}
int F_44 ( struct V_39 * V_31 , int V_8 )
{
struct V_74 * V_34 = V_31 -> V_34 ;
struct V_75 * V_76 ;
if ( ! V_34 -> V_91 || ! V_34 -> V_91 -> V_76 . V_92 )
return - V_80 ;
F_28 ( L_4 , V_8 ? L_5 : L_6 ) ;
V_76 = V_34 -> V_91 -> V_76 . V_92 ;
if ( V_8 ) {
if ( V_76 -> V_86 -> V_88 )
V_76 -> V_86 -> V_88 ( V_76 ) ;
} else {
if ( V_76 -> V_86 -> V_90 )
V_76 -> V_86 -> V_90 ( V_76 , V_93 ) ;
}
return 0 ;
}
static int F_45 ( struct V_74 * V_34 , struct V_94 * V_35 )
{
struct V_77 * V_78 = F_43 ( V_34 -> V_28 , struct V_77 , V_28 ) ;
if ( ! V_34 || V_78 != V_18 )
return - V_80 ;
V_34 -> V_35 = V_35 ;
V_78 -> V_31 . V_95 = 0 ;
V_78 -> V_31 . V_96 = 1 ;
if ( V_35 ) {
F_28 ( L_3 ) ;
V_34 -> V_35 -> V_97 = V_98 . V_97 ;
V_34 -> V_35 -> V_99 = V_78 -> V_31 . V_89 ;
V_78 -> V_84 = 1 ;
F_46 ( & V_78 -> V_100 , 100 ) ;
return 0 ;
} else {
if ( ! ( F_12 ( & V_78 -> V_19 -> V_10 ) &
V_101 ) ) {
struct V_39 * V_31 = & V_78 -> V_31 ;
V_34 -> V_28 -> V_29 = V_102 ;
V_31 -> V_103 = V_104 ;
}
}
V_78 -> V_84 = 0 ;
F_29 ( & V_78 -> V_31 ) ;
return 0 ;
}
static int F_47 ( struct V_74 * V_34 ,
struct V_105 * V_91 )
{
struct V_77 * V_78 = F_43 ( V_34 -> V_28 , struct V_77 , V_28 ) ;
F_28 ( L_7 , ( int ) V_78 ) ;
F_28 ( L_8 , ( int ) V_18 ) ;
if ( ! V_34 || V_78 != V_18 )
return - V_80 ;
if ( ! V_91 ) {
if ( ! V_34 -> V_106 )
V_34 -> V_91 -> V_107 -> V_108 ( V_34 -> V_91 , 0 ) ;
F_48 ( V_34 -> V_91 ) ;
V_34 -> V_91 = 0 ;
V_78 -> V_31 . V_109 = 0 ;
F_29 ( & V_78 -> V_31 ) ;
return 0 ;
}
V_34 -> V_91 = V_91 ;
V_34 -> V_91 -> V_110 = ! V_78 -> V_31 . V_89 ;
V_78 -> V_31 . V_109 = 1 ;
F_49 ( L_9 , V_78 -> V_31 . V_89 ) ;
if ( V_78 -> V_31 . V_89 == 1 ) {
F_42 ( & V_78 -> V_31 , 0 ) ;
F_50 ( & V_78 -> V_31 , 0 ) ;
F_44 ( & V_78 -> V_31 , 1 ) ;
}
return 0 ;
}
static int F_51 ( struct V_111 * V_28 , unsigned V_112 )
{
if ( ! V_18 )
return - V_80 ;
if ( V_28 -> V_29 == V_113 )
F_52 ( L_10 , V_112 ) ;
return 0 ;
}
static void F_53 ( struct V_114 * V_115 )
{
struct V_77 * V_116 = F_43 ( V_115 , struct V_77 , V_100 . V_115 ) ;
struct V_39 * V_31 = & V_116 -> V_31 ;
if ( V_31 -> V_89 ) {
F_42 ( V_31 , 0 ) ;
F_50 ( V_31 , 0 ) ;
F_44 ( V_31 , 1 ) ;
}
}
static int F_54 ( struct V_74 * V_34 )
{
struct V_77 * V_78 = F_43 ( V_34 -> V_28 , struct V_77 , V_28 ) ;
if ( ! V_34 || V_78 != V_18
|| V_34 -> V_28 -> V_29 != V_117 )
return - V_80 ;
V_78 -> V_31 . V_109 = 1 ;
F_29 ( & V_78 -> V_31 ) ;
return 0 ;
}
static int F_55 ( struct V_74 * V_34 )
{
struct V_77 * V_78 = F_43 ( V_34 -> V_28 , struct V_77 , V_28 ) ;
if ( ! V_34 || V_78 != V_18 )
return - V_80 ;
F_49 ( L_11 ) ;
V_78 -> V_31 . V_96 = 0 ;
F_29 ( & V_78 -> V_31 ) ;
return 0 ;
}
T_4 F_56 ( int V_118 , void * V_119 )
{
struct V_39 * V_31 = & ( (struct V_77 * ) V_119 ) -> V_31 ;
struct V_74 * V_34 = ( (struct V_77 * ) V_119 ) -> V_28 . V_34 ;
T_1 V_120 , V_121 ;
V_121 = F_12 ( & V_5 -> V_10 ) ;
V_120 = V_121 & V_11 & ( V_121 >> 8 ) ;
F_10 ( V_121 , & V_5 -> V_10 ) ;
V_31 -> V_89 = ( V_121 & V_101 ) ? 1 : 0 ;
V_34 -> V_106 = ( V_31 -> V_89 == 0 ) ;
if ( V_120 ) {
if ( V_120 & V_122 ) {
V_31 -> V_89 = ( V_121 & V_101 ) ? 1 : 0 ;
V_34 -> V_106 = ( V_31 -> V_89 == 0 ) ;
if ( V_31 -> V_89 )
V_31 -> V_123 = 0 ;
else
V_31 -> V_124 = 0 ;
if ( V_34 -> V_35 )
V_34 -> V_35 -> V_99 = V_31 -> V_89 ;
if ( V_34 -> V_91 )
V_34 -> V_91 -> V_110 = ! V_31 -> V_89 ;
F_28 ( L_12 , V_31 -> V_89 ) ;
if ( V_31 -> V_89 ) {
F_46 (
& ( (struct V_77 * ) V_119 ) -> V_100 ,
100 ) ;
} else {
F_57 ( &
( (struct V_77 * ) V_119 ) ->
V_100 ) ;
F_44 ( V_31 , 0 ) ;
F_50 ( V_31 , 1 ) ;
F_42 ( V_31 , 1 ) ;
}
return V_125 ;
}
}
return V_126 ;
}
static int F_58 ( struct V_127 * V_128 )
{
struct V_77 * V_129 ;
int V_130 ;
if ( V_18 )
return 0 ;
V_129 = F_59 ( sizeof( struct V_77 ) , V_131 ) ;
if ( ! V_129 )
return - V_43 ;
V_129 -> V_28 . V_34 = F_59 ( sizeof( struct V_74 ) , V_131 ) ;
if ( ! V_129 -> V_28 . V_34 ) {
F_34 ( V_129 ) ;
return - V_43 ;
}
F_60 ( & V_129 -> V_100 , F_53 ) ;
F_61 ( & V_68 ) ;
V_130 = F_31 ( & V_129 -> V_31 ) ;
if ( V_130 ) {
F_52 ( L_13 ) ;
goto V_132;
}
F_62 ( & V_129 -> V_31 . V_133 ) ;
V_129 -> V_31 . V_107 = & V_134 ;
V_129 -> V_28 . V_135 = V_136 ;
V_129 -> V_28 . V_137 = F_51 ;
V_129 -> V_28 . V_34 -> V_28 = & V_129 -> V_28 ;
V_129 -> V_28 . V_34 -> V_138 = F_45 ;
V_129 -> V_28 . V_34 -> V_139 = F_47 ;
V_129 -> V_28 . V_34 -> V_140 = F_55 ;
V_129 -> V_28 . V_34 -> V_141 = F_54 ;
V_18 = V_129 ;
V_130 = F_63 ( & V_129 -> V_28 , V_142 ) ;
if ( V_130 ) {
F_64 ( V_143 L_14 ) ;
goto V_132;
}
return 0 ;
V_132:
F_33 () ;
F_34 ( V_129 -> V_28 . V_34 ) ;
F_34 ( V_129 ) ;
return V_130 ;
}
int F_65 ( struct V_127 * V_128 )
{
struct V_77 * V_144 ;
struct V_111 * V_145 = F_66 ( V_142 ) ;
struct V_39 * V_31 ;
int V_130 ;
struct V_146 * V_147 ;
T_1 V_4 ;
struct V_148 * V_149 = V_128 -> V_76 . V_150 ;
V_144 = F_43 ( V_145 , struct V_77 , V_28 ) ;
V_31 = & V_144 -> V_31 ;
F_67 ( V_145 , V_102 ) ;
V_31 -> V_34 = V_144 -> V_28 . V_34 ;
V_147 = F_68 ( V_128 , V_151 , 0 ) ;
if ( ! V_147 )
return - V_152 ;
V_5 = F_69 ( V_147 -> V_153 , sizeof( struct V_154 ) ) ;
V_144 -> V_19 = (struct V_154 * ) V_5 ;
V_149 -> V_155 = ( void * ) V_5 ;
if ( V_149 -> V_156 && V_149 -> V_156 ( V_128 ) != 0 )
return - V_157 ;
if ( V_149 -> V_158 ) {
V_159 = F_1 ;
V_160 = F_5 ;
} else {
V_159 = F_3 ;
V_160 = F_7 ;
}
V_144 -> V_118 = F_70 ( V_128 , 0 ) ;
V_130 = F_71 ( V_144 -> V_118 , F_56 ,
V_161 , V_162 , V_144 ) ;
if ( V_130 ) {
F_72 ( V_144 -> V_28 . V_76 , L_15 ,
V_144 -> V_118 , V_130 ) ;
F_73 ( V_144 -> V_19 ) ;
F_34 ( V_144 -> V_28 . V_34 ) ;
F_34 ( V_144 ) ;
return V_130 ;
}
V_4 = F_12 ( & V_144 -> V_19 -> V_73 ) ;
V_4 &= ~ V_163 ;
F_10 ( V_4 , & V_144 -> V_19 -> V_73 ) ;
V_4 = F_12 ( & V_144 -> V_19 -> V_73 ) ;
V_4 |= V_164 ;
F_10 ( V_4 , & V_144 -> V_19 -> V_73 ) ;
while ( F_12 ( & V_144 -> V_19 -> V_73 ) & V_164 )
;
V_4 = V_165 | ( V_149 -> V_166 ? V_167 : 0 ) ;
F_10 ( V_4 , & V_144 -> V_19 -> V_168 ) ;
V_4 = F_12 ( & V_144 -> V_19 -> V_14 ) ;
V_4 &= ~ ( V_169 | V_170 ) ;
switch ( V_149 -> V_171 ) {
case V_172 :
V_4 |= V_173 ;
break;
case V_174 :
V_4 |= V_175 ;
case V_176 :
V_4 |= V_177 ;
default:
break;
}
F_10 ( V_4 , & V_144 -> V_19 -> V_14 ) ;
if ( V_149 -> V_178 ) {
V_4 = F_74 ( & V_144 -> V_19 -> V_179 ) ;
V_4 |= V_180 ;
F_75 ( V_4 , & V_144 -> V_19 -> V_179 ) ;
}
V_4 = F_12 ( & V_144 -> V_19 -> V_10 ) ;
V_4 &= ~ V_181 ;
V_4 |= V_182 | V_12 ;
F_10 ( V_4 , & V_144 -> V_19 -> V_10 ) ;
if ( F_12 ( & V_144 -> V_19 -> V_10 ) & V_101 ) {
V_144 -> V_28 . V_29 = V_102 ;
V_144 -> V_31 . V_89 = 1 ;
} else {
V_144 -> V_28 . V_29 = V_183 ;
V_144 -> V_31 . V_89 = 0 ;
}
F_49 ( L_16 , V_144 -> V_31 . V_89 ) ;
V_4 = F_12 ( & V_144 -> V_19 -> V_10 ) ;
V_4 |= V_184 ;
V_4 &= ~ ( V_12 | V_185 ) ;
F_10 ( V_4 , & V_144 -> V_19 -> V_10 ) ;
return 0 ;
}
static int F_76 ( struct V_75 * V_76 ,
struct V_186 * V_187 , char * V_188 )
{
struct V_39 * V_31 = & V_18 -> V_31 ;
char * V_189 = V_188 ;
unsigned V_190 = V_191 ;
unsigned long V_192 ;
int V_193 ;
F_77 ( & V_31 -> V_133 , V_192 ) ;
V_193 = F_78 ( V_189 , V_190 ,
V_136 L_17 L_18 ,
V_194 ) ;
V_190 -= V_193 ;
V_189 += V_193 ;
V_193 = F_78 ( V_189 , V_190 ,
L_19
L_20
L_21
L_22
L_23
L_24 ,
F_12 ( & V_5 -> V_10 ) ,
F_12 ( & V_5 -> V_14 ) ,
F_12 ( & V_5 -> V_168 ) ,
F_12 ( & V_5 -> V_73 ) ,
F_12 ( & V_5 -> V_195 ) ,
F_12 ( & V_5 -> V_196 ) ) ;
V_190 -= V_193 ;
V_189 += V_193 ;
V_193 = F_78 ( V_189 , V_190 ,
L_25 ,
F_79 ( V_18 -> V_28 . V_29 ) ) ;
V_190 -= V_193 ;
V_189 += V_193 ;
V_193 = F_78 ( V_189 , V_190 ,
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
V_31 -> V_96 ,
V_31 -> V_109 ,
V_31 -> V_197 ,
V_31 -> V_198 ,
V_31 -> V_124 ,
V_31 -> V_199 ,
V_31 -> V_200 ,
V_31 -> V_82 ,
V_31 -> V_201 ,
V_31 -> V_202 ,
V_31 -> V_123 ,
V_31 -> V_55 ,
V_31 -> V_203 ,
V_31 -> V_32 ,
V_31 -> V_89 ) ;
V_190 -= V_193 ;
V_189 += V_193 ;
F_80 ( & V_31 -> V_133 , V_192 ) ;
return V_191 - V_190 ;
}
static long F_81 ( struct V_204 * V_204 , unsigned int V_205 ,
unsigned long V_206 )
{
T_1 V_79 = 0 ;
switch ( V_205 ) {
case V_207 :
V_79 = V_18 -> V_84 ;
break;
case V_208 :
V_18 -> V_31 . V_209 = V_206 ;
break;
case V_210 :
V_18 -> V_31 . V_95 = V_206 ;
break;
case V_211 :
V_18 -> V_31 . V_96 = V_206 ;
break;
case V_212 :
V_18 -> V_31 . V_109 = V_206 ;
break;
default:
break;
}
F_29 ( & V_18 -> V_31 ) ;
return V_79 ;
}
static int F_82 ( struct V_213 * V_213 , struct V_204 * V_204 )
{
return 0 ;
}
static int F_83 ( struct V_213 * V_213 , struct V_204 * V_204 )
{
return 0 ;
}
static int T_5 F_84 ( struct V_127 * V_128 )
{
int V_214 ;
if ( ! V_128 -> V_76 . V_150 )
return - V_80 ;
V_214 = F_58 ( V_128 ) ;
if ( V_214 ) {
F_85 ( & V_128 -> V_76 , L_41 ) ;
return V_214 ;
}
V_214 = F_65 ( V_128 ) ;
if ( V_214 ) {
F_85 ( & V_128 -> V_76 , L_42 ) ;
return V_214 ;
}
V_214 = F_86 ( V_215 , V_143 , & V_216 ) ;
if ( V_214 ) {
F_85 ( & V_128 -> V_76 , L_43 ) ;
return V_214 ;
}
V_214 = F_87 ( & V_128 -> V_76 , & V_217 ) ;
if ( V_214 )
F_88 ( & V_128 -> V_76 , L_44 ) ;
return V_214 ;
}
static int T_6 F_89 ( struct V_127 * V_128 )
{
struct V_148 * V_149 = V_128 -> V_76 . V_150 ;
F_90 ( & V_18 -> V_28 ) ;
F_91 ( V_18 -> V_118 , V_18 ) ;
F_73 ( ( void * ) V_5 ) ;
F_33 () ;
F_34 ( V_18 -> V_28 . V_34 ) ;
F_34 ( V_18 ) ;
F_92 ( & V_128 -> V_76 , & V_217 ) ;
F_93 ( V_215 , V_143 ) ;
if ( V_149 -> exit )
V_149 -> exit ( V_128 ) ;
return 0 ;
}
