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
static void F_50 ( struct V_119 * V_120 )
{
struct V_84 * V_121 = F_42 ( V_120 , struct V_84 , V_108 . V_120 ) ;
struct V_8 * V_9 = & V_121 -> V_9 ;
if ( V_9 -> V_97 ) {
F_41 ( V_9 , 0 ) ;
F_49 ( V_9 , 0 ) ;
F_43 ( V_9 , 1 ) ;
}
}
static int F_51 ( struct V_81 * V_31 )
{
struct V_84 * V_85 ;
if ( ! V_31 || V_31 -> V_32 != V_122 )
return - V_88 ;
V_85 = F_42 ( V_31 -> V_86 , struct V_84 , V_30 ) ;
if ( V_85 != V_20 )
return - V_88 ;
V_85 -> V_9 . V_117 = 1 ;
F_26 ( & V_85 -> V_9 ) ;
return 0 ;
}
static int F_52 ( struct V_81 * V_31 )
{
struct V_84 * V_85 ;
if ( ! V_31 )
return - V_88 ;
V_85 = F_42 ( V_31 -> V_86 , struct V_84 , V_30 ) ;
if ( V_85 != V_20 )
return - V_88 ;
F_48 ( L_10 ) ;
V_85 -> V_9 . V_104 = 0 ;
F_26 ( & V_85 -> V_9 ) ;
return 0 ;
}
T_4 F_53 ( int V_123 , void * V_124 )
{
struct V_8 * V_9 = & ( (struct V_84 * ) V_124 ) -> V_9 ;
struct V_81 * V_31 = ( (struct V_84 * ) V_124 ) -> V_30 . V_31 ;
T_1 V_125 , V_126 ;
V_126 = F_12 ( & V_6 -> V_12 ) ;
V_125 = V_126 & V_13 & ( V_126 >> 8 ) ;
F_10 ( V_126 , & V_6 -> V_12 ) ;
V_9 -> V_97 = ( V_126 & V_109 ) ? 1 : 0 ;
V_31 -> V_114 = ( V_9 -> V_97 == 0 ) ;
if ( V_125 ) {
if ( V_125 & V_127 ) {
V_9 -> V_97 = ( V_126 & V_109 ) ? 1 : 0 ;
V_31 -> V_114 = ( V_9 -> V_97 == 0 ) ;
if ( V_9 -> V_97 )
V_9 -> V_128 = 0 ;
else
V_9 -> V_129 = 0 ;
if ( V_31 -> V_36 )
V_31 -> V_36 -> V_107 = V_9 -> V_97 ;
if ( V_31 -> V_99 )
V_31 -> V_99 -> V_118 = ! V_9 -> V_97 ;
F_25 ( L_11 , V_9 -> V_97 ) ;
if ( V_9 -> V_97 ) {
F_45 (
& ( (struct V_84 * ) V_124 ) -> V_108 ,
100 ) ;
} else {
F_54 ( &
( (struct V_84 * ) V_124 ) ->
V_108 ) ;
F_43 ( V_9 , 0 ) ;
F_49 ( V_9 , 1 ) ;
F_41 ( V_9 , 1 ) ;
}
return V_130 ;
}
}
return V_131 ;
}
static int F_55 ( struct V_132 * V_133 )
{
struct V_84 * V_134 ;
int V_135 ;
if ( V_20 )
return 0 ;
V_134 = F_56 ( sizeof( struct V_84 ) , V_136 ) ;
if ( ! V_134 )
return - V_43 ;
V_134 -> V_30 . V_31 = F_56 ( sizeof( struct V_81 ) , V_136 ) ;
if ( ! V_134 -> V_30 . V_31 ) {
F_31 ( V_134 ) ;
return - V_43 ;
}
F_57 ( & V_134 -> V_108 , F_50 ) ;
F_58 ( & V_77 ) ;
V_135 = F_28 ( & V_134 -> V_9 ) ;
if ( V_135 ) {
F_59 ( L_12 ) ;
goto V_137;
}
F_60 ( & V_134 -> V_9 . V_138 ) ;
V_134 -> V_9 . V_115 = & V_139 ;
V_134 -> V_30 . V_140 = V_141 ;
V_134 -> V_30 . V_83 = & V_133 -> V_83 ;
V_134 -> V_30 . V_31 -> V_86 = & V_134 -> V_30 ;
V_134 -> V_30 . V_31 -> V_142 = F_44 ;
V_134 -> V_30 . V_31 -> V_143 = F_46 ;
V_134 -> V_30 . V_31 -> V_144 = F_52 ;
V_134 -> V_30 . V_31 -> V_145 = F_51 ;
V_20 = V_134 ;
V_135 = F_61 ( & V_134 -> V_30 , V_146 ) ;
if ( V_135 ) {
F_62 ( V_147 L_13 ) ;
goto V_137;
}
return 0 ;
V_137:
F_30 () ;
F_31 ( V_134 -> V_30 . V_31 ) ;
F_31 ( V_134 ) ;
return V_135 ;
}
int F_63 ( struct V_132 * V_133 )
{
struct V_84 * V_148 ;
struct V_86 * V_149 = F_64 ( V_146 ) ;
struct V_8 * V_9 ;
int V_135 ;
struct V_150 * V_151 ;
T_1 V_5 ;
struct V_152 * V_153 = F_65 ( & V_133 -> V_83 ) ;
V_148 = F_42 ( V_149 , struct V_84 , V_30 ) ;
V_9 = & V_148 -> V_9 ;
F_66 ( V_149 , V_110 ) ;
V_9 -> V_31 = V_148 -> V_30 . V_31 ;
V_151 = F_67 ( V_133 , V_154 , 0 ) ;
if ( ! V_151 )
return - V_155 ;
V_6 = F_68 ( V_151 -> V_156 , sizeof( struct V_157 ) ) ;
V_148 -> V_21 = (struct V_157 * ) V_6 ;
V_153 -> V_158 = ( void * ) V_6 ;
if ( V_153 -> V_159 && V_153 -> V_159 ( V_133 ) != 0 )
return - V_160 ;
if ( V_153 -> V_161 ) {
V_162 = F_1 ;
V_163 = F_5 ;
} else {
V_162 = F_3 ;
V_163 = F_7 ;
}
V_148 -> V_123 = F_69 ( V_133 , 0 ) ;
V_135 = F_70 ( V_148 -> V_123 , F_53 ,
V_164 , V_165 , V_148 ) ;
if ( V_135 ) {
F_71 ( V_148 -> V_30 . V_83 , L_14 ,
V_148 -> V_123 , V_135 ) ;
F_72 ( V_148 -> V_21 ) ;
F_31 ( V_148 -> V_30 . V_31 ) ;
F_31 ( V_148 ) ;
return V_135 ;
}
V_5 = F_12 ( & V_148 -> V_21 -> V_80 ) ;
V_5 &= ~ V_166 ;
F_10 ( V_5 , & V_148 -> V_21 -> V_80 ) ;
V_5 = F_12 ( & V_148 -> V_21 -> V_80 ) ;
V_5 |= V_167 ;
F_10 ( V_5 , & V_148 -> V_21 -> V_80 ) ;
while ( F_12 ( & V_148 -> V_21 -> V_80 ) & V_167 )
;
V_5 = V_168 | ( V_153 -> V_169 ? V_170 : 0 ) ;
F_10 ( V_5 , & V_148 -> V_21 -> V_171 ) ;
V_5 = F_12 ( & V_148 -> V_21 -> V_16 ) ;
V_5 &= ~ ( V_172 | V_173 ) ;
switch ( V_153 -> V_174 ) {
case V_175 :
V_5 |= V_176 ;
break;
case V_177 :
V_5 |= V_178 ;
case V_179 :
V_5 |= V_180 ;
default:
break;
}
F_10 ( V_5 , & V_148 -> V_21 -> V_16 ) ;
if ( V_153 -> V_181 ) {
V_5 = F_73 ( & V_148 -> V_21 -> V_182 ) ;
V_5 |= V_183 ;
F_74 ( V_5 , & V_148 -> V_21 -> V_182 ) ;
}
V_5 = F_12 ( & V_148 -> V_21 -> V_12 ) ;
V_5 &= ~ V_184 ;
V_5 |= V_185 | V_14 ;
F_10 ( V_5 , & V_148 -> V_21 -> V_12 ) ;
if ( F_12 ( & V_148 -> V_21 -> V_12 ) & V_109 ) {
V_148 -> V_30 . V_31 -> V_32 = V_110 ;
V_148 -> V_9 . V_97 = 1 ;
} else {
V_148 -> V_30 . V_31 -> V_32 = V_186 ;
V_148 -> V_9 . V_97 = 0 ;
}
F_48 ( L_15 , V_148 -> V_9 . V_97 ) ;
V_5 = F_12 ( & V_148 -> V_21 -> V_12 ) ;
V_5 |= V_187 ;
V_5 &= ~ ( V_14 | V_188 ) ;
F_10 ( V_5 , & V_148 -> V_21 -> V_12 ) ;
return 0 ;
}
static int F_75 ( struct V_82 * V_83 ,
struct V_189 * V_190 , char * V_191 )
{
struct V_8 * V_9 = & V_20 -> V_9 ;
char * V_192 = V_191 ;
unsigned V_193 = V_194 ;
int V_63 ;
F_76 ( & V_9 -> V_138 ) ;
V_63 = F_77 ( V_192 , V_193 ,
V_141 L_16 L_17 ,
V_195 ) ;
V_193 -= V_63 ;
V_192 += V_63 ;
V_63 = F_77 ( V_192 , V_193 ,
L_18
L_19
L_20
L_21
L_22
L_23 ,
F_12 ( & V_6 -> V_12 ) ,
F_12 ( & V_6 -> V_16 ) ,
F_12 ( & V_6 -> V_171 ) ,
F_12 ( & V_6 -> V_80 ) ,
F_12 ( & V_6 -> V_196 ) ,
F_12 ( & V_6 -> V_197 ) ) ;
V_193 -= V_63 ;
V_192 += V_63 ;
V_63 = F_77 ( V_192 , V_193 ,
L_24 ,
F_78 ( V_20 -> V_30 . V_31 -> V_32 ) ) ;
V_193 -= V_63 ;
V_192 += V_63 ;
V_63 = F_77 ( V_192 , V_193 ,
L_25
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
L_39 ,
V_9 -> V_104 ,
V_9 -> V_117 ,
V_9 -> V_198 ,
V_9 -> V_199 ,
V_9 -> V_129 ,
V_9 -> V_200 ,
V_9 -> V_201 ,
V_9 -> V_90 ,
V_9 -> V_202 ,
V_9 -> V_203 ,
V_9 -> V_128 ,
V_9 -> V_55 ,
V_9 -> V_204 ,
V_9 -> V_34 ,
V_9 -> V_97 ) ;
V_193 -= V_63 ;
V_192 += V_63 ;
F_79 ( & V_9 -> V_138 ) ;
return V_194 - V_193 ;
}
static long F_80 ( struct V_205 * V_205 , unsigned int V_206 ,
unsigned long V_207 )
{
T_1 V_87 = 0 ;
switch ( V_206 ) {
case V_208 :
V_87 = V_20 -> V_92 ;
break;
case V_209 :
V_20 -> V_9 . V_210 = V_207 ;
break;
case V_211 :
V_20 -> V_9 . V_103 = V_207 ;
break;
case V_212 :
V_20 -> V_9 . V_104 = V_207 ;
break;
case V_213 :
V_20 -> V_9 . V_117 = V_207 ;
break;
default:
break;
}
F_26 ( & V_20 -> V_9 ) ;
return V_87 ;
}
static int F_81 ( struct V_214 * V_214 , struct V_205 * V_205 )
{
return 0 ;
}
static int F_82 ( struct V_214 * V_214 , struct V_205 * V_205 )
{
return 0 ;
}
static int F_83 ( struct V_132 * V_133 )
{
int V_215 ;
if ( ! F_65 ( & V_133 -> V_83 ) )
return - V_88 ;
V_215 = F_55 ( V_133 ) ;
if ( V_215 ) {
F_84 ( & V_133 -> V_83 , L_40 ) ;
return V_215 ;
}
V_215 = F_63 ( V_133 ) ;
if ( V_215 ) {
F_84 ( & V_133 -> V_83 , L_41 ) ;
return V_215 ;
}
V_215 = F_85 ( V_216 , V_147 , & V_217 ) ;
if ( V_215 ) {
F_84 ( & V_133 -> V_83 , L_42 ) ;
return V_215 ;
}
V_215 = F_86 ( & V_133 -> V_83 , & V_218 ) ;
if ( V_215 )
F_87 ( & V_133 -> V_83 , L_43 ) ;
return V_215 ;
}
static int F_88 ( struct V_132 * V_133 )
{
struct V_152 * V_153 = F_65 ( & V_133 -> V_83 ) ;
F_89 ( & V_20 -> V_30 ) ;
F_90 ( V_20 -> V_123 , V_20 ) ;
F_72 ( ( void * ) V_6 ) ;
F_30 () ;
F_31 ( V_20 -> V_30 . V_31 ) ;
F_31 ( V_20 ) ;
F_91 ( & V_133 -> V_83 , & V_218 ) ;
F_92 ( V_216 , V_147 ) ;
if ( V_153 -> exit )
V_153 -> exit ( V_133 ) ;
return 0 ;
}
