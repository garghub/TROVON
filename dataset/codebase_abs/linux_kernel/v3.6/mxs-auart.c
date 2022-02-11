static inline void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_5 . V_6 -> V_4 ;
while ( ! ( F_2 ( V_2 -> V_5 . V_7 + V_8 ) &
V_9 ) ) {
if ( V_2 -> V_5 . V_10 ) {
V_2 -> V_5 . V_11 . V_12 ++ ;
F_3 ( V_2 -> V_5 . V_10 ,
V_2 -> V_5 . V_7 + V_13 ) ;
V_2 -> V_5 . V_10 = 0 ;
continue;
}
if ( ! F_4 ( V_4 ) && ! F_5 ( & V_2 -> V_5 ) ) {
V_2 -> V_5 . V_11 . V_12 ++ ;
F_3 ( V_4 -> V_14 [ V_4 -> V_15 ] ,
V_2 -> V_5 . V_7 + V_13 ) ;
V_4 -> V_15 = ( V_4 -> V_15 + 1 ) & ( V_16 - 1 ) ;
} else
break;
}
if ( F_6 ( V_4 ) < V_17 )
F_7 ( & V_2 -> V_5 ) ;
if ( F_4 ( & ( V_2 -> V_5 . V_6 -> V_4 ) ) )
F_3 ( V_18 ,
V_2 -> V_5 . V_7 + V_19 ) ;
else
F_3 ( V_18 ,
V_2 -> V_5 . V_7 + V_20 ) ;
if ( F_5 ( & V_2 -> V_5 ) )
F_8 ( & V_2 -> V_5 ) ;
}
static void F_9 ( struct V_1 * V_2 )
{
int V_21 ;
T_1 V_22 ;
T_2 V_23 ;
V_23 = F_2 ( V_2 -> V_5 . V_7 + V_13 ) ;
V_22 = F_2 ( V_2 -> V_5 . V_7 + V_8 ) ;
V_21 = V_24 ;
V_2 -> V_5 . V_11 . V_25 ++ ;
if ( V_22 & V_26 ) {
V_2 -> V_5 . V_11 . V_27 ++ ;
if ( F_10 ( & V_2 -> V_5 ) )
goto V_28;
} else if ( V_22 & V_29 ) {
V_2 -> V_5 . V_11 . V_30 ++ ;
} else if ( V_22 & V_31 ) {
V_2 -> V_5 . V_11 . V_32 ++ ;
}
V_22 &= V_2 -> V_5 . V_33 ;
if ( V_22 & V_26 ) {
V_21 = V_34 ;
} else if ( V_22 & V_29 )
V_21 = V_35 ;
else if ( V_22 & V_31 )
V_21 = V_36 ;
if ( V_22 & V_37 )
V_2 -> V_5 . V_11 . V_38 ++ ;
if ( F_11 ( & V_2 -> V_5 , V_23 ) )
goto V_28;
F_12 ( & V_2 -> V_5 , V_22 , V_37 , V_23 , V_21 ) ;
V_28:
F_3 ( V_22 , V_2 -> V_5 . V_7 + V_8 ) ;
}
static void F_13 ( struct V_1 * V_2 )
{
struct V_39 * V_40 = V_2 -> V_5 . V_6 -> V_5 . V_40 ;
T_1 V_22 = 0 ;
for (; ; ) {
V_22 = F_2 ( V_2 -> V_5 . V_7 + V_8 ) ;
if ( V_22 & V_41 )
break;
F_9 ( V_2 ) ;
}
F_3 ( V_22 , V_2 -> V_5 . V_7 + V_8 ) ;
F_14 ( V_40 ) ;
}
static int F_15 ( struct V_42 * V_43 )
{
return 0 ;
}
static int F_16 ( struct V_42 * V_43 ,
struct V_44 * V_45 )
{
if ( V_43 -> type != V_46 && V_43 -> type != V_47 )
return - V_48 ;
return 0 ;
}
static void F_17 ( struct V_42 * V_43 , int V_49 )
{
}
static const char * F_18 ( struct V_42 * V_43 )
{
struct V_1 * V_2 = F_19 ( V_43 ) ;
return F_20 ( V_2 -> V_50 ) ;
}
static void F_21 ( struct V_42 * V_43 )
{
}
static void F_22 ( struct V_42 * V_43 , unsigned V_51 )
{
struct V_1 * V_2 = F_19 ( V_43 ) ;
T_1 V_52 = F_2 ( V_43 -> V_7 + V_53 ) ;
V_52 &= ~ V_54 ;
if ( V_51 & V_55 ) {
if ( V_43 -> V_6 -> V_5 . V_49 & V_56 )
V_52 |= V_54 ;
}
V_2 -> V_52 = V_51 ;
F_3 ( V_52 , V_43 -> V_7 + V_53 ) ;
}
static T_1 F_23 ( struct V_42 * V_43 )
{
struct V_1 * V_2 = F_19 ( V_43 ) ;
T_1 V_22 = F_2 ( V_43 -> V_7 + V_8 ) ;
int V_57 = F_2 ( V_43 -> V_7 + V_53 ) ;
T_1 V_51 = V_2 -> V_52 ;
V_51 &= ~ V_58 ;
if ( V_22 & V_59 )
V_51 |= V_58 ;
if ( V_57 & V_60 )
V_51 |= V_55 ;
return V_51 ;
}
static void F_24 ( struct V_42 * V_43 ,
struct V_61 * V_62 ,
struct V_61 * V_63 )
{
T_1 V_64 , V_52 , V_57 , div ;
unsigned int V_65 , V_66 ;
V_65 = V_62 -> V_67 ;
V_52 = V_68 ;
V_57 = F_2 ( V_43 -> V_7 + V_53 ) ;
switch ( V_65 & V_69 ) {
case V_70 :
V_64 = 0 ;
break;
case V_71 :
V_64 = 1 ;
break;
case V_72 :
V_64 = 2 ;
break;
case V_73 :
V_64 = 3 ;
break;
default:
return;
}
V_52 |= F_25 ( V_64 ) ;
if ( V_65 & V_74 ) {
V_52 |= V_75 ;
if ( ( V_65 & V_76 ) == 0 )
V_52 |= V_77 ;
}
V_43 -> V_33 = 0 ;
if ( V_62 -> V_78 & V_79 )
V_43 -> V_33 |= V_29 ;
if ( V_62 -> V_78 & ( V_80 | V_81 ) )
V_43 -> V_33 |= V_26 ;
V_43 -> V_82 = 0 ;
if ( V_62 -> V_78 & V_83 )
V_43 -> V_82 |= V_29 ;
if ( V_62 -> V_78 & V_84 ) {
V_43 -> V_82 |= V_26 ;
if ( V_62 -> V_78 & V_83 )
V_43 -> V_82 |= V_37 ;
}
if ( V_65 & V_85 )
V_57 |= V_86 ;
else
V_57 &= ~ V_86 ;
if ( V_65 & V_87 )
V_52 |= V_88 ;
if ( V_65 & V_89 )
V_57 |= V_90 | V_54 ;
else
V_57 &= ~ ( V_90 | V_54 ) ;
V_66 = F_26 ( V_43 , V_62 , V_63 , 0 , V_43 -> V_91 ) ;
div = V_43 -> V_91 * 32 / V_66 ;
V_52 |= F_27 ( div & 0x3F ) ;
V_52 |= F_28 ( div >> 6 ) ;
F_3 ( V_52 , V_43 -> V_7 + V_92 ) ;
F_3 ( V_57 , V_43 -> V_7 + V_53 ) ;
F_29 ( V_43 , V_62 -> V_67 , V_66 ) ;
}
static T_3 F_30 ( int V_93 , void * V_94 )
{
T_1 V_95 , V_96 ;
struct V_1 * V_2 = V_94 ;
T_1 V_22 = F_2 ( V_2 -> V_5 . V_7 + V_8 ) ;
V_95 = V_96 = F_2 ( V_2 -> V_5 . V_7 + V_97 ) ;
if ( V_96 & V_98 ) {
F_31 ( & V_2 -> V_5 , V_22 & V_59 ) ;
F_3 ( V_98 ,
V_2 -> V_5 . V_7 + V_19 ) ;
V_96 &= ~ V_98 ;
}
if ( V_96 & ( V_99 | V_100 ) ) {
F_13 ( V_2 ) ;
V_96 &= ~ ( V_99 | V_100 ) ;
}
if ( V_96 & V_101 ) {
F_1 ( V_2 ) ;
V_96 &= ~ V_101 ;
}
F_3 ( V_95 & ( V_99
| V_101
| V_100
| V_98 ) ,
V_2 -> V_5 . V_7 + V_19 ) ;
return V_102 ;
}
static void F_32 ( struct V_42 * V_43 )
{
int V_103 ;
unsigned int V_104 ;
F_3 ( V_105 , V_43 -> V_7 + V_106 ) ;
for ( V_103 = 0 ; V_103 < 10000 ; V_103 ++ ) {
V_104 = F_2 ( V_43 -> V_7 + V_107 ) ;
if ( ! ( V_104 & V_105 ) )
break;
F_33 ( 3 ) ;
}
F_3 ( V_108 , V_43 -> V_7 + V_106 ) ;
}
static int F_34 ( struct V_42 * V_43 )
{
struct V_1 * V_2 = F_19 ( V_43 ) ;
F_35 ( V_2 -> V_109 ) ;
F_3 ( V_108 , V_43 -> V_7 + V_106 ) ;
F_3 ( V_110 , V_43 -> V_7 + V_111 ) ;
F_3 ( V_112 | V_113 | V_114 ,
V_43 -> V_7 + V_97 ) ;
F_3 ( V_68 , V_43 -> V_7 + V_115 ) ;
return 0 ;
}
static void F_36 ( struct V_42 * V_43 )
{
struct V_1 * V_2 = F_19 ( V_43 ) ;
F_3 ( V_110 , V_43 -> V_7 + V_116 ) ;
F_3 ( V_108 , V_43 -> V_7 + V_117 ) ;
F_3 ( V_112 | V_113 | V_114 ,
V_43 -> V_7 + V_19 ) ;
F_37 ( V_2 -> V_109 ) ;
}
static unsigned int F_38 ( struct V_42 * V_43 )
{
if ( F_2 ( V_43 -> V_7 + V_8 ) & V_118 )
return V_119 ;
else
return 0 ;
}
static void F_39 ( struct V_42 * V_43 )
{
struct V_1 * V_2 = F_19 ( V_43 ) ;
F_3 ( V_120 , V_43 -> V_7 + V_111 ) ;
F_1 ( V_2 ) ;
}
static void F_8 ( struct V_42 * V_43 )
{
F_3 ( V_120 , V_43 -> V_7 + V_116 ) ;
}
static void F_40 ( struct V_42 * V_43 )
{
F_3 ( V_86 , V_43 -> V_7 + V_116 ) ;
}
static void F_41 ( struct V_42 * V_43 , int V_121 )
{
if ( V_121 )
F_3 ( V_122 ,
V_43 -> V_7 + V_115 ) ;
else
F_3 ( V_122 ,
V_43 -> V_7 + V_123 ) ;
}
static void F_42 ( struct V_42 * V_5 )
{
}
static void F_43 ( struct V_42 * V_5 , int V_124 )
{
unsigned int V_125 = 1000 ;
while ( F_2 ( V_5 -> V_7 + V_8 ) & V_9 ) {
if ( ! V_125 -- )
break;
F_33 ( 1 ) ;
}
F_3 ( V_124 , V_5 -> V_7 + V_13 ) ;
}
static void
F_44 ( struct V_126 * V_127 , const char * V_128 , unsigned int V_129 )
{
struct V_1 * V_2 ;
struct V_42 * V_5 ;
unsigned int V_130 , V_131 ;
unsigned int V_125 = 1000 ;
if ( V_127 -> V_132 > V_133 || V_127 -> V_132 < 0 )
return;
V_2 = V_134 [ V_127 -> V_132 ] ;
V_5 = & V_2 -> V_5 ;
F_45 ( V_2 -> V_109 ) ;
V_131 = F_2 ( V_5 -> V_7 + V_53 ) ;
V_130 = F_2 ( V_5 -> V_7 + V_107 ) ;
F_3 ( V_108 ,
V_5 -> V_7 + V_106 ) ;
F_3 ( V_110 | V_120 ,
V_5 -> V_7 + V_111 ) ;
F_46 ( V_5 , V_128 , V_129 , F_43 ) ;
while ( F_2 ( V_5 -> V_7 + V_8 ) & V_135 ) {
if ( ! V_125 -- )
break;
F_33 ( 1 ) ;
}
F_3 ( V_130 , V_5 -> V_7 + V_107 ) ;
F_3 ( V_131 , V_5 -> V_7 + V_53 ) ;
F_47 ( V_2 -> V_109 ) ;
}
static void T_4
F_48 ( struct V_42 * V_5 , int * V_66 ,
int * V_30 , int * V_136 )
{
unsigned int V_137 , V_138 ;
if ( ! ( F_2 ( V_5 -> V_7 + V_53 ) & V_110 ) )
return;
V_137 = F_2 ( V_5 -> V_7 + V_92 ) ;
* V_30 = 'n' ;
if ( V_137 & V_75 ) {
if ( V_137 & V_77 )
* V_30 = 'e' ;
else
* V_30 = 'o' ;
}
if ( ( V_137 & V_139 ) == F_25 ( 2 ) )
* V_136 = 7 ;
else
* V_136 = 8 ;
V_138 = ( ( F_2 ( V_5 -> V_7 + V_92 )
& V_140 ) )
>> ( V_141 - 6 ) ;
V_138 |= ( ( F_2 ( V_5 -> V_7 + V_92 )
& V_142 ) )
>> V_143 ;
if ( V_138 == 0 )
V_138 = 1 ;
* V_66 = ( V_5 -> V_91 << 2 ) / V_138 ;
}
static int T_4
F_49 ( struct V_126 * V_127 , char * V_144 )
{
struct V_1 * V_2 ;
int V_66 = 9600 ;
int V_136 = 8 ;
int V_30 = 'n' ;
int V_145 = 'n' ;
int V_146 ;
if ( V_127 -> V_132 == - 1 || V_127 -> V_132 >= F_50 ( V_134 ) )
V_127 -> V_132 = 0 ;
V_2 = V_134 [ V_127 -> V_132 ] ;
if ( ! V_2 )
return - V_147 ;
F_35 ( V_2 -> V_109 ) ;
if ( V_144 )
F_51 ( V_144 , & V_66 , & V_30 , & V_136 , & V_145 ) ;
else
F_48 ( & V_2 -> V_5 , & V_66 , & V_30 , & V_136 ) ;
V_146 = F_52 ( & V_2 -> V_5 , V_127 , V_66 , V_30 , V_136 , V_145 ) ;
F_37 ( V_2 -> V_109 ) ;
return V_146 ;
}
static int F_53 ( struct V_1 * V_2 ,
struct V_148 * V_149 )
{
struct V_150 * V_151 = V_149 -> V_50 . V_152 ;
int V_146 ;
if ( ! V_151 )
return 1 ;
V_146 = F_54 ( V_151 , L_1 ) ;
if ( V_146 < 0 ) {
F_55 ( & V_149 -> V_50 , L_2 , V_146 ) ;
return V_146 ;
}
V_2 -> V_5 . line = V_146 ;
return 0 ;
}
static int T_5 F_56 ( struct V_148 * V_149 )
{
struct V_1 * V_2 ;
T_1 V_153 ;
int V_146 = 0 ;
struct V_154 * V_155 ;
struct V_156 * V_156 ;
V_2 = F_57 ( sizeof( struct V_1 ) , V_157 ) ;
if ( ! V_2 ) {
V_146 = - V_158 ;
goto V_28;
}
V_146 = F_53 ( V_2 , V_149 ) ;
if ( V_146 > 0 )
V_2 -> V_5 . line = V_149 -> V_159 < 0 ? 0 : V_149 -> V_159 ;
else if ( V_146 < 0 )
goto V_160;
V_156 = F_58 ( & V_149 -> V_50 ) ;
if ( F_59 ( V_156 ) ) {
V_146 = F_60 ( V_156 ) ;
goto V_160;
}
V_2 -> V_109 = F_61 ( & V_149 -> V_50 , NULL ) ;
if ( F_59 ( V_2 -> V_109 ) ) {
V_146 = F_60 ( V_2 -> V_109 ) ;
goto V_160;
}
V_155 = F_62 ( V_149 , V_161 , 0 ) ;
if ( ! V_155 ) {
V_146 = - V_162 ;
goto V_163;
}
V_2 -> V_5 . V_164 = V_155 -> V_165 ;
V_2 -> V_5 . V_7 = F_63 ( V_155 -> V_165 , F_64 ( V_155 ) ) ;
V_2 -> V_5 . V_166 = & V_167 ;
V_2 -> V_5 . V_168 = V_169 ;
V_2 -> V_5 . V_170 = 16 ;
V_2 -> V_5 . V_91 = F_65 ( V_2 -> V_109 ) ;
V_2 -> V_5 . type = V_47 ;
V_2 -> V_5 . V_50 = V_2 -> V_50 = F_66 ( & V_149 -> V_50 ) ;
V_2 -> V_49 = 0 ;
V_2 -> V_52 = 0 ;
V_2 -> V_93 = F_67 ( V_149 , 0 ) ;
V_2 -> V_5 . V_93 = V_2 -> V_93 ;
V_146 = F_68 ( V_2 -> V_93 , F_30 , 0 , F_20 ( & V_149 -> V_50 ) , V_2 ) ;
if ( V_146 )
goto V_163;
F_69 ( V_149 , V_2 ) ;
V_134 [ V_2 -> V_5 . line ] = V_2 ;
F_32 ( & V_2 -> V_5 ) ;
V_146 = F_70 ( & V_171 , & V_2 -> V_5 ) ;
if ( V_146 )
goto V_172;
V_153 = F_2 ( V_2 -> V_5 . V_7 + V_173 ) ;
F_71 ( & V_149 -> V_50 , L_3 ,
( V_153 >> 24 ) & 0xff ,
( V_153 >> 16 ) & 0xff , V_153 & 0xffff ) ;
return 0 ;
V_172:
V_134 [ V_149 -> V_159 ] = NULL ;
F_72 ( V_2 -> V_93 , V_2 ) ;
V_163:
F_73 ( V_2 -> V_109 ) ;
V_160:
F_74 ( V_2 ) ;
V_28:
return V_146 ;
}
static int T_6 F_75 ( struct V_148 * V_149 )
{
struct V_1 * V_2 = F_76 ( V_149 ) ;
F_77 ( & V_171 , & V_2 -> V_5 ) ;
V_134 [ V_149 -> V_159 ] = NULL ;
F_73 ( V_2 -> V_109 ) ;
F_72 ( V_2 -> V_93 , V_2 ) ;
F_74 ( V_2 ) ;
return 0 ;
}
static int T_4 F_78 ( void )
{
int V_155 ;
V_155 = F_79 ( & V_171 ) ;
if ( V_155 )
goto V_28;
V_155 = F_80 ( & V_174 ) ;
if ( V_155 )
goto V_175;
return 0 ;
V_175:
F_81 ( & V_171 ) ;
V_28:
return V_155 ;
}
static void T_7 F_82 ( void )
{
F_83 ( & V_174 ) ;
F_81 ( & V_171 ) ;
}
