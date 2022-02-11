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
void F_15 ( struct V_8 * V_9 , int V_10 )
{
T_1 V_11 ;
V_11 = F_12 ( & V_5 -> V_12 ) & ~ V_13 ;
if ( V_10 )
V_11 = ( V_11 & ~ V_14 ) |
V_15 ;
else
V_11 &= ~ V_15 ;
F_10 ( V_11 , & V_5 -> V_12 ) ;
}
void F_16 ( int V_10 )
{
T_1 V_11 ;
V_11 = F_12 ( & V_5 -> V_12 ) & ~ V_13 ;
if ( V_10 )
V_11 = ( V_11 & ~ V_15 ) |
V_14 ;
else
V_11 &= ~ V_14 ;
F_10 ( V_11 , & V_5 -> V_12 ) ;
}
void F_17 ( struct V_8 * V_9 , int V_10 )
{
T_1 V_11 ;
if ( V_10 ) {
V_11 = F_12 ( & V_5 -> V_16 ) & ~ V_17 ;
F_10 ( V_11 | V_18 , & V_5 -> V_16 ) ;
} else {
V_11 = F_12 ( & V_5 -> V_16 ) &
~ V_17 & ~ V_18 ;
F_10 ( V_11 , & V_5 -> V_16 ) ;
}
}
void F_18 ( struct V_8 * V_9 , int V_10 )
{
T_1 V_11 ;
V_11 = F_12 ( & V_5 -> V_12 ) & ~ V_13 ;
if ( V_10 )
V_11 |= V_19 ;
else
V_11 &= ~ V_19 ;
F_10 ( V_11 , & V_5 -> V_12 ) ;
}
void F_19 ( struct V_8 * V_9 , int V_10 )
{
T_1 V_11 ;
V_11 = F_12 ( & V_20 -> V_21 -> V_16 ) & ~ V_17 ;
if ( V_10 )
V_11 |= V_22 ;
else
V_11 |= V_23 ;
F_10 ( V_11 , & V_20 -> V_21 -> V_16 ) ;
}
void F_20 ( struct V_8 * V_9 )
{
T_1 V_11 ;
V_24 = 0 ;
#ifdef F_21
V_11 = F_12 ( & V_5 -> V_12 ) & ~ V_13 ;
V_11 |= V_25 ;
F_10 ( V_11 , & V_5 -> V_12 ) ;
#else
F_18 ( 1 ) ;
#endif
F_22 ( V_9 , V_26 ) ;
}
void F_23 ( unsigned long V_27 )
{
#ifdef F_21
#else
F_18 ( 0 ) ;
#endif
F_24 () ;
}
void F_24 ( void )
{
V_24 = 0 ;
F_15 ( & V_20 -> V_9 , 1 ) ;
F_22 ( & V_20 -> V_9 , V_28 ) ;
}
void F_25 ( unsigned long V_27 )
{
F_15 ( & V_20 -> V_9 , 0 ) ;
F_16 ( 1 ) ;
F_22 ( & V_20 -> V_9 , V_29 ) ;
}
void F_26 ( unsigned long V_27 )
{
F_16 ( 0 ) ;
V_24 = 1 ;
if ( ( V_20 -> V_30 . V_31 == V_32 ) &&
V_20 -> V_9 . V_33 )
V_20 -> V_9 . V_34 = 1 ;
}
void F_27 ( unsigned long V_27 )
{
F_28 ( L_1 ) ;
if ( ! V_20 -> V_30 . V_35 -> V_36 -> V_37 )
F_22 ( & V_20 -> V_9 , V_38 ) ;
else
F_29 ( & V_20 -> V_9 ) ;
}
void F_30 ( unsigned long V_39 )
{
* ( int * ) V_39 = 1 ;
}
int F_31 ( struct V_8 * V_9 )
{
V_40 = F_32 ( & F_30 , V_41 ,
( unsigned long ) & V_9 -> V_42 ) ;
if ( ! V_40 )
return - V_43 ;
V_44 = F_32 ( & F_30 , V_45 ,
( unsigned long ) & V_9 -> V_46 ) ;
if ( ! V_44 )
return - V_43 ;
V_47 = F_32 ( & F_30 , V_48 ,
( unsigned long ) & V_9 -> V_49 ) ;
if ( ! V_47 )
return - V_43 ;
V_50 = F_32 ( & F_30 , V_51 ,
( unsigned long ) & V_9 -> V_52 ) ;
if ( ! V_50 )
return - V_43 ;
V_53 = F_32 ( & F_30 , V_54 ,
( unsigned long ) & V_9 -> V_55 ) ;
if ( ! V_53 )
return - V_43 ;
V_56 = F_32 ( & F_30 , V_57 ,
( unsigned long ) & V_9 -> V_34 ) ;
if ( ! V_56 )
return - V_43 ;
V_38 = F_32 ( & F_27 , 10 ,
( unsigned long ) & V_9 ) ;
if ( ! V_38 )
return - V_43 ;
V_29 = F_32 ( & F_26 , V_58 , 0 ) ;
if ( ! V_29 )
return - V_43 ;
V_26 = F_32 ( & F_23 ,
V_59 , 0 ) ;
if ( ! V_26 )
return - V_43 ;
V_28 = F_32 ( & F_25 ,
V_60 , 0 ) ;
if ( ! V_28 )
return - V_43 ;
return 0 ;
}
void F_33 ( void )
{
F_34 ( V_40 ) ;
F_34 ( V_44 ) ;
F_34 ( V_47 ) ;
F_34 ( V_50 ) ;
F_34 ( V_53 ) ;
F_34 ( V_56 ) ;
F_34 ( V_38 ) ;
F_34 ( V_29 ) ;
F_34 ( V_26 ) ;
F_34 ( V_28 ) ;
}
static struct V_61 * F_35 ( enum V_62 V_63 )
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
void F_22 ( struct V_8 * V_9 , void * V_72 )
{
struct V_61 * V_64 = V_72 ;
struct V_61 * V_73 ;
F_36 (tmp_timer, &active_timers, list)
if ( V_73 == V_64 ) {
V_64 -> V_74 = V_64 -> V_75 ;
return;
}
V_64 -> V_74 = V_64 -> V_75 ;
F_37 ( & V_64 -> V_76 , & V_77 ) ;
}
static void F_38 ( struct V_8 * V_9 , enum V_62 V_63 )
{
struct V_61 * V_64 ;
V_64 = F_35 ( V_63 ) ;
if ( ! V_64 )
return;
F_22 ( V_9 , V_64 ) ;
}
void F_39 ( struct V_8 * V_9 , void * V_72 )
{
struct V_61 * V_64 = V_72 ;
struct V_61 * V_73 , * V_78 ;
F_40 (tmp_timer, del_tmp, &active_timers, list)
if ( V_73 == V_64 )
F_41 ( & V_64 -> V_76 ) ;
}
static void F_42 ( struct V_8 * V_9 , enum V_62 V_63 )
{
struct V_61 * V_64 ;
V_64 = F_35 ( V_63 ) ;
if ( ! V_64 )
return;
F_39 ( V_9 , V_64 ) ;
}
int F_43 ( void )
{
struct V_61 * V_73 , * V_78 ;
int V_79 = 0 ;
F_40 (tmp_timer, del_tmp, &active_timers, list) {
V_73 -> V_74 -- ;
if ( ! V_73 -> V_74 ) {
F_41 ( & V_73 -> V_76 ) ;
V_73 -> V_80 ( V_73 -> V_7 ) ;
V_79 = 1 ;
}
}
return V_79 ;
}
void F_44 ( void )
{
T_1 V_81 ;
V_81 = F_12 ( & V_5 -> V_82 ) ;
V_81 |= ( 1 << 1 ) ;
F_10 ( V_81 , & V_5 -> V_82 ) ;
while ( F_12 ( & V_5 -> V_82 ) & ( 1 << 1 ) )
;
}
int F_45 ( struct V_8 * V_9 , int V_10 )
{
struct V_83 * V_35 = V_9 -> V_35 ;
struct V_84 * V_85 ;
struct V_86 * V_87 = F_46 ( V_35 -> V_30 , struct V_86 , V_30 ) ;
T_1 V_88 = 0 ;
if ( ! V_35 -> V_36 )
return - V_89 ;
V_85 = V_35 -> V_36 -> V_90 ;
V_9 -> V_91 =
! ! ( F_12 ( & V_5 -> V_12 ) & V_92 ) ;
if ( V_10 ) {
if ( V_87 -> V_93 )
goto V_94;
else {
F_44 () ;
F_28 ( L_2 ) ;
if ( V_85 -> V_95 -> V_96 && V_85 -> V_95 -> V_96 -> V_97 ) {
V_88 = V_85 -> V_95 -> V_96 -> V_97 ( V_85 ) ;
if ( V_9 -> V_98 ) {
F_17 ( V_9 , 1 ) ;
F_14 ( 0x0c , 0x20 ) ;
}
}
V_87 -> V_93 = 1 ;
}
} else {
if ( ! V_87 -> V_93 )
goto V_94;
else {
F_28 ( L_3 ) ;
if ( V_85 && V_85 -> V_95 ) {
if ( V_85 -> V_95 -> V_96 && V_85 -> V_95 -> V_96 -> V_99 )
V_88 = V_85 -> V_95 -> V_96 -> V_99 ( V_85 ) ;
if ( V_9 -> V_98 )
F_17 ( V_9 , 0 ) ;
}
V_87 -> V_93 = 0 ;
}
}
V_94:
return V_88 ;
}
int F_47 ( struct V_8 * V_9 , int V_10 )
{
struct V_83 * V_35 = V_9 -> V_35 ;
struct V_84 * V_85 ;
if ( ! V_35 -> V_100 || ! V_35 -> V_100 -> V_85 . V_101 )
return - V_89 ;
F_28 ( L_4 , V_10 ? L_5 : L_6 ) ;
V_85 = V_35 -> V_100 -> V_85 . V_101 ;
if ( V_10 ) {
if ( V_85 -> V_95 -> V_97 )
V_85 -> V_95 -> V_97 ( V_85 ) ;
} else {
if ( V_85 -> V_95 -> V_99 )
V_85 -> V_95 -> V_99 ( V_85 , V_102 ) ;
}
return 0 ;
}
static int F_48 ( struct V_83 * V_35 , struct V_103 * V_36 )
{
struct V_86 * V_87 ;
if ( ! V_35 )
return - V_89 ;
V_87 = F_46 ( V_35 -> V_30 , struct V_86 , V_30 ) ;
if ( V_87 != V_20 )
return - V_89 ;
V_35 -> V_36 = V_36 ;
V_87 -> V_9 . V_104 = 0 ;
V_87 -> V_9 . V_105 = 1 ;
if ( V_36 ) {
F_28 ( L_3 ) ;
V_35 -> V_36 -> V_106 = V_107 . V_106 ;
V_35 -> V_36 -> V_108 = V_87 -> V_9 . V_98 ;
V_87 -> V_93 = 1 ;
F_49 ( & V_87 -> V_109 , 100 ) ;
return 0 ;
} else {
if ( ! ( F_12 ( & V_87 -> V_21 -> V_12 ) &
V_110 ) ) {
struct V_8 * V_9 = & V_87 -> V_9 ;
V_35 -> V_30 -> V_31 = V_111 ;
V_9 -> V_112 = V_113 ;
}
}
V_87 -> V_93 = 0 ;
F_29 ( & V_87 -> V_9 ) ;
return 0 ;
}
static int F_50 ( struct V_83 * V_35 ,
struct V_114 * V_100 )
{
struct V_86 * V_87 ;
if ( ! V_35 )
return - V_89 ;
V_87 = F_46 ( V_35 -> V_30 , struct V_86 , V_30 ) ;
F_28 ( L_7 , ( int ) V_87 ) ;
F_28 ( L_8 , ( int ) V_20 ) ;
if ( V_87 != V_20 )
return - V_89 ;
if ( ! V_100 ) {
if ( ! V_35 -> V_115 )
V_35 -> V_100 -> V_116 -> V_117 ( V_35 -> V_100 , 0 ) ;
F_51 ( V_35 -> V_100 ) ;
V_35 -> V_100 = 0 ;
V_87 -> V_9 . V_118 = 0 ;
F_29 ( & V_87 -> V_9 ) ;
return 0 ;
}
V_35 -> V_100 = V_100 ;
V_35 -> V_100 -> V_119 = ! V_87 -> V_9 . V_98 ;
V_87 -> V_9 . V_118 = 1 ;
F_52 ( L_9 , V_87 -> V_9 . V_98 ) ;
if ( V_87 -> V_9 . V_98 == 1 ) {
F_45 ( & V_87 -> V_9 , 0 ) ;
F_53 ( & V_87 -> V_9 , 0 ) ;
F_47 ( & V_87 -> V_9 , 1 ) ;
}
return 0 ;
}
static int F_54 ( struct V_120 * V_30 , unsigned V_121 )
{
if ( ! V_20 )
return - V_89 ;
if ( V_30 -> V_31 == V_122 )
F_55 ( L_10 , V_121 ) ;
return 0 ;
}
static void F_56 ( struct V_123 * V_124 )
{
struct V_86 * V_125 = F_46 ( V_124 , struct V_86 , V_109 . V_124 ) ;
struct V_8 * V_9 = & V_125 -> V_9 ;
if ( V_9 -> V_98 ) {
F_45 ( V_9 , 0 ) ;
F_53 ( V_9 , 0 ) ;
F_47 ( V_9 , 1 ) ;
}
}
static int F_57 ( struct V_83 * V_35 )
{
struct V_86 * V_87 ;
if ( ! V_35 || V_35 -> V_30 -> V_31 != V_126 )
return - V_89 ;
V_87 = F_46 ( V_35 -> V_30 , struct V_86 , V_30 ) ;
if ( V_87 != V_20 )
return - V_89 ;
V_87 -> V_9 . V_118 = 1 ;
F_29 ( & V_87 -> V_9 ) ;
return 0 ;
}
static int F_58 ( struct V_83 * V_35 )
{
struct V_86 * V_87 ;
if ( ! V_35 )
return - V_89 ;
V_87 = F_46 ( V_35 -> V_30 , struct V_86 , V_30 ) ;
if ( V_87 != V_20 )
return - V_89 ;
F_52 ( L_11 ) ;
V_87 -> V_9 . V_105 = 0 ;
F_29 ( & V_87 -> V_9 ) ;
return 0 ;
}
T_4 F_59 ( int V_127 , void * V_128 )
{
struct V_8 * V_9 = & ( (struct V_86 * ) V_128 ) -> V_9 ;
struct V_83 * V_35 = ( (struct V_86 * ) V_128 ) -> V_30 . V_35 ;
T_1 V_129 , V_130 ;
V_130 = F_12 ( & V_5 -> V_12 ) ;
V_129 = V_130 & V_13 & ( V_130 >> 8 ) ;
F_10 ( V_130 , & V_5 -> V_12 ) ;
V_9 -> V_98 = ( V_130 & V_110 ) ? 1 : 0 ;
V_35 -> V_115 = ( V_9 -> V_98 == 0 ) ;
if ( V_129 ) {
if ( V_129 & V_131 ) {
V_9 -> V_98 = ( V_130 & V_110 ) ? 1 : 0 ;
V_35 -> V_115 = ( V_9 -> V_98 == 0 ) ;
if ( V_9 -> V_98 )
V_9 -> V_132 = 0 ;
else
V_9 -> V_133 = 0 ;
if ( V_35 -> V_36 )
V_35 -> V_36 -> V_108 = V_9 -> V_98 ;
if ( V_35 -> V_100 )
V_35 -> V_100 -> V_119 = ! V_9 -> V_98 ;
F_28 ( L_12 , V_9 -> V_98 ) ;
if ( V_9 -> V_98 ) {
F_49 (
& ( (struct V_86 * ) V_128 ) -> V_109 ,
100 ) ;
} else {
F_60 ( &
( (struct V_86 * ) V_128 ) ->
V_109 ) ;
F_47 ( V_9 , 0 ) ;
F_53 ( V_9 , 1 ) ;
F_45 ( V_9 , 1 ) ;
}
return V_134 ;
}
}
return V_135 ;
}
static int F_61 ( struct V_136 * V_137 )
{
struct V_86 * V_138 ;
int V_139 ;
if ( V_20 )
return 0 ;
V_138 = F_62 ( sizeof( struct V_86 ) , V_140 ) ;
if ( ! V_138 )
return - V_43 ;
V_138 -> V_30 . V_35 = F_62 ( sizeof( struct V_83 ) , V_140 ) ;
if ( ! V_138 -> V_30 . V_35 ) {
F_34 ( V_138 ) ;
return - V_43 ;
}
F_63 ( & V_138 -> V_109 , F_56 ) ;
F_64 ( & V_77 ) ;
V_139 = F_31 ( & V_138 -> V_9 ) ;
if ( V_139 ) {
F_55 ( L_13 ) ;
goto V_141;
}
F_65 ( & V_138 -> V_9 . V_142 ) ;
V_138 -> V_9 . V_116 = & V_143 ;
V_138 -> V_30 . V_144 = V_145 ;
V_138 -> V_30 . V_85 = & V_137 -> V_85 ;
V_138 -> V_30 . V_146 = F_54 ;
V_138 -> V_30 . V_35 -> V_30 = & V_138 -> V_30 ;
V_138 -> V_30 . V_35 -> V_147 = F_48 ;
V_138 -> V_30 . V_35 -> V_148 = F_50 ;
V_138 -> V_30 . V_35 -> V_149 = F_58 ;
V_138 -> V_30 . V_35 -> V_150 = F_57 ;
V_20 = V_138 ;
V_139 = F_66 ( & V_138 -> V_30 , V_151 ) ;
if ( V_139 ) {
F_67 ( V_152 L_14 ) ;
goto V_141;
}
return 0 ;
V_141:
F_33 () ;
F_34 ( V_138 -> V_30 . V_35 ) ;
F_34 ( V_138 ) ;
return V_139 ;
}
int F_68 ( struct V_136 * V_137 )
{
struct V_86 * V_153 ;
struct V_120 * V_154 = F_69 ( V_151 ) ;
struct V_8 * V_9 ;
int V_139 ;
struct V_155 * V_156 ;
T_1 V_4 ;
struct V_157 * V_158 = F_70 ( & V_137 -> V_85 ) ;
V_153 = F_46 ( V_154 , struct V_86 , V_30 ) ;
V_9 = & V_153 -> V_9 ;
F_71 ( V_154 , V_111 ) ;
V_9 -> V_35 = V_153 -> V_30 . V_35 ;
V_156 = F_72 ( V_137 , V_159 , 0 ) ;
if ( ! V_156 )
return - V_160 ;
V_5 = F_73 ( V_156 -> V_161 , sizeof( struct V_162 ) ) ;
V_153 -> V_21 = (struct V_162 * ) V_5 ;
V_158 -> V_163 = ( void * ) V_5 ;
if ( V_158 -> V_164 && V_158 -> V_164 ( V_137 ) != 0 )
return - V_165 ;
if ( V_158 -> V_166 ) {
V_167 = F_1 ;
V_168 = F_5 ;
} else {
V_167 = F_3 ;
V_168 = F_7 ;
}
V_153 -> V_127 = F_74 ( V_137 , 0 ) ;
V_139 = F_75 ( V_153 -> V_127 , F_59 ,
V_169 , V_170 , V_153 ) ;
if ( V_139 ) {
F_76 ( V_153 -> V_30 . V_85 , L_15 ,
V_153 -> V_127 , V_139 ) ;
F_77 ( V_153 -> V_21 ) ;
F_34 ( V_153 -> V_30 . V_35 ) ;
F_34 ( V_153 ) ;
return V_139 ;
}
V_4 = F_12 ( & V_153 -> V_21 -> V_82 ) ;
V_4 &= ~ V_171 ;
F_10 ( V_4 , & V_153 -> V_21 -> V_82 ) ;
V_4 = F_12 ( & V_153 -> V_21 -> V_82 ) ;
V_4 |= V_172 ;
F_10 ( V_4 , & V_153 -> V_21 -> V_82 ) ;
while ( F_12 ( & V_153 -> V_21 -> V_82 ) & V_172 )
;
V_4 = V_173 | ( V_158 -> V_174 ? V_175 : 0 ) ;
F_10 ( V_4 , & V_153 -> V_21 -> V_176 ) ;
V_4 = F_12 ( & V_153 -> V_21 -> V_16 ) ;
V_4 &= ~ ( V_177 | V_178 ) ;
switch ( V_158 -> V_179 ) {
case V_180 :
V_4 |= V_181 ;
break;
case V_182 :
V_4 |= V_183 ;
case V_184 :
V_4 |= V_185 ;
default:
break;
}
F_10 ( V_4 , & V_153 -> V_21 -> V_16 ) ;
if ( V_158 -> V_186 ) {
V_4 = F_78 ( & V_153 -> V_21 -> V_187 ) ;
V_4 |= V_188 ;
F_79 ( V_4 , & V_153 -> V_21 -> V_187 ) ;
}
V_4 = F_12 ( & V_153 -> V_21 -> V_12 ) ;
V_4 &= ~ V_189 ;
V_4 |= V_190 | V_14 ;
F_10 ( V_4 , & V_153 -> V_21 -> V_12 ) ;
if ( F_12 ( & V_153 -> V_21 -> V_12 ) & V_110 ) {
V_153 -> V_30 . V_31 = V_111 ;
V_153 -> V_9 . V_98 = 1 ;
} else {
V_153 -> V_30 . V_31 = V_191 ;
V_153 -> V_9 . V_98 = 0 ;
}
F_52 ( L_16 , V_153 -> V_9 . V_98 ) ;
V_4 = F_12 ( & V_153 -> V_21 -> V_12 ) ;
V_4 |= V_192 ;
V_4 &= ~ ( V_14 | V_193 ) ;
F_10 ( V_4 , & V_153 -> V_21 -> V_12 ) ;
return 0 ;
}
static int F_80 ( struct V_84 * V_85 ,
struct V_194 * V_195 , char * V_196 )
{
struct V_8 * V_9 = & V_20 -> V_9 ;
char * V_197 = V_196 ;
unsigned V_198 = V_199 ;
unsigned long V_200 ;
int V_63 ;
F_81 ( & V_9 -> V_142 , V_200 ) ;
V_63 = F_82 ( V_197 , V_198 ,
V_145 L_17 L_18 ,
V_201 ) ;
V_198 -= V_63 ;
V_197 += V_63 ;
V_63 = F_82 ( V_197 , V_198 ,
L_19
L_20
L_21
L_22
L_23
L_24 ,
F_12 ( & V_5 -> V_12 ) ,
F_12 ( & V_5 -> V_16 ) ,
F_12 ( & V_5 -> V_176 ) ,
F_12 ( & V_5 -> V_82 ) ,
F_12 ( & V_5 -> V_202 ) ,
F_12 ( & V_5 -> V_203 ) ) ;
V_198 -= V_63 ;
V_197 += V_63 ;
V_63 = F_82 ( V_197 , V_198 ,
L_25 ,
F_83 ( V_20 -> V_30 . V_31 ) ) ;
V_198 -= V_63 ;
V_197 += V_63 ;
V_63 = F_82 ( V_197 , V_198 ,
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
V_9 -> V_105 ,
V_9 -> V_118 ,
V_9 -> V_204 ,
V_9 -> V_205 ,
V_9 -> V_133 ,
V_9 -> V_206 ,
V_9 -> V_207 ,
V_9 -> V_91 ,
V_9 -> V_208 ,
V_9 -> V_209 ,
V_9 -> V_132 ,
V_9 -> V_55 ,
V_9 -> V_210 ,
V_9 -> V_33 ,
V_9 -> V_98 ) ;
V_198 -= V_63 ;
V_197 += V_63 ;
F_84 ( & V_9 -> V_142 , V_200 ) ;
return V_199 - V_198 ;
}
static long F_85 ( struct V_211 * V_211 , unsigned int V_212 ,
unsigned long V_213 )
{
T_1 V_88 = 0 ;
switch ( V_212 ) {
case V_214 :
V_88 = V_20 -> V_93 ;
break;
case V_215 :
V_20 -> V_9 . V_216 = V_213 ;
break;
case V_217 :
V_20 -> V_9 . V_104 = V_213 ;
break;
case V_218 :
V_20 -> V_9 . V_105 = V_213 ;
break;
case V_219 :
V_20 -> V_9 . V_118 = V_213 ;
break;
default:
break;
}
F_29 ( & V_20 -> V_9 ) ;
return V_88 ;
}
static int F_86 ( struct V_220 * V_220 , struct V_211 * V_211 )
{
return 0 ;
}
static int F_87 ( struct V_220 * V_220 , struct V_211 * V_211 )
{
return 0 ;
}
static int F_88 ( struct V_136 * V_137 )
{
int V_221 ;
if ( ! F_70 ( & V_137 -> V_85 ) )
return - V_89 ;
V_221 = F_61 ( V_137 ) ;
if ( V_221 ) {
F_89 ( & V_137 -> V_85 , L_41 ) ;
return V_221 ;
}
V_221 = F_68 ( V_137 ) ;
if ( V_221 ) {
F_89 ( & V_137 -> V_85 , L_42 ) ;
return V_221 ;
}
V_221 = F_90 ( V_222 , V_152 , & V_223 ) ;
if ( V_221 ) {
F_89 ( & V_137 -> V_85 , L_43 ) ;
return V_221 ;
}
V_221 = F_91 ( & V_137 -> V_85 , & V_224 ) ;
if ( V_221 )
F_92 ( & V_137 -> V_85 , L_44 ) ;
return V_221 ;
}
static int F_93 ( struct V_136 * V_137 )
{
struct V_157 * V_158 = F_70 ( & V_137 -> V_85 ) ;
F_94 ( & V_20 -> V_30 ) ;
F_95 ( V_20 -> V_127 , V_20 ) ;
F_77 ( ( void * ) V_5 ) ;
F_33 () ;
F_34 ( V_20 -> V_30 . V_35 ) ;
F_34 ( V_20 ) ;
F_96 ( & V_137 -> V_85 , & V_224 ) ;
F_97 ( V_222 , V_152 ) ;
if ( V_158 -> exit )
V_158 -> exit ( V_137 ) ;
return 0 ;
}
