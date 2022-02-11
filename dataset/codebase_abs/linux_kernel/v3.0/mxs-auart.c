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
if ( F_6 ( V_4 ) < V_17 )
F_7 ( & V_2 -> V_5 ) ;
} else
break;
}
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
if ( V_51 & V_55 )
V_52 |= V_54 ;
V_2 -> V_52 = V_51 ;
F_3 ( V_52 , V_43 -> V_7 + V_53 ) ;
}
static T_1 F_23 ( struct V_42 * V_43 )
{
struct V_1 * V_2 = F_19 ( V_43 ) ;
T_1 V_22 = F_2 ( V_43 -> V_7 + V_8 ) ;
int V_56 = F_2 ( V_43 -> V_7 + V_53 ) ;
T_1 V_51 = V_2 -> V_52 ;
V_51 &= ~ V_57 ;
if ( V_22 & V_58 )
V_51 |= V_57 ;
if ( V_56 & V_54 )
V_51 |= V_55 ;
return V_51 ;
}
static void F_24 ( struct V_42 * V_43 ,
struct V_59 * V_60 ,
struct V_59 * V_61 )
{
T_1 V_62 , V_52 , V_56 , div ;
unsigned int V_63 , V_64 ;
V_63 = V_60 -> V_65 ;
V_52 = V_66 ;
V_56 = F_2 ( V_43 -> V_7 + V_53 ) ;
switch ( V_63 & V_67 ) {
case V_68 :
V_62 = 0 ;
break;
case V_69 :
V_62 = 1 ;
break;
case V_70 :
V_62 = 2 ;
break;
case V_71 :
V_62 = 3 ;
break;
default:
return;
}
V_52 |= F_25 ( V_62 ) ;
if ( V_63 & V_72 ) {
V_52 |= V_73 ;
if ( ( V_63 & V_74 ) == 0 )
V_52 |= V_75 ;
}
V_43 -> V_33 = 0 ;
if ( V_60 -> V_76 & V_77 )
V_43 -> V_33 |= V_29 ;
if ( V_60 -> V_76 & ( V_78 | V_79 ) )
V_43 -> V_33 |= V_26 ;
V_43 -> V_80 = 0 ;
if ( V_60 -> V_76 & V_81 )
V_43 -> V_80 |= V_29 ;
if ( V_60 -> V_76 & V_82 ) {
V_43 -> V_80 |= V_26 ;
if ( V_60 -> V_76 & V_81 )
V_43 -> V_80 |= V_37 ;
}
if ( V_63 & V_83 )
V_56 |= V_84 ;
else
V_56 &= ~ V_84 ;
if ( V_63 & V_85 )
V_52 |= V_86 ;
if ( V_63 & V_87 )
V_56 |= V_88 ;
else
V_56 &= ~ V_88 ;
V_64 = F_26 ( V_43 , V_60 , V_61 , 0 , V_43 -> V_89 ) ;
div = V_43 -> V_89 * 32 / V_64 ;
V_52 |= F_27 ( div & 0x3F ) ;
V_52 |= F_28 ( div >> 6 ) ;
F_3 ( V_52 , V_43 -> V_7 + V_90 ) ;
F_3 ( V_56 , V_43 -> V_7 + V_53 ) ;
}
static T_3 F_29 ( int V_91 , void * V_92 )
{
T_1 V_93 , V_94 ;
struct V_1 * V_2 = V_92 ;
T_1 V_22 = F_2 ( V_2 -> V_5 . V_7 + V_8 ) ;
V_93 = V_94 = F_2 ( V_2 -> V_5 . V_7 + V_95 ) ;
if ( V_94 & V_96 ) {
F_30 ( & V_2 -> V_5 , V_22 & V_58 ) ;
F_3 ( V_96 ,
V_2 -> V_5 . V_7 + V_19 ) ;
V_94 &= ~ V_96 ;
}
if ( V_94 & ( V_97 | V_98 ) ) {
F_13 ( V_2 ) ;
V_94 &= ~ ( V_97 | V_98 ) ;
}
if ( V_94 & V_99 ) {
F_1 ( V_2 ) ;
V_94 &= ~ V_99 ;
}
F_3 ( V_93 & ( V_97
| V_99
| V_98
| V_96 ) ,
V_2 -> V_5 . V_7 + V_19 ) ;
return V_100 ;
}
static void F_31 ( struct V_42 * V_43 )
{
int V_101 ;
unsigned int V_102 ;
F_3 ( V_103 , V_43 -> V_7 + V_104 ) ;
for ( V_101 = 0 ; V_101 < 10000 ; V_101 ++ ) {
V_102 = F_2 ( V_43 -> V_7 + V_105 ) ;
if ( ! ( V_102 & V_103 ) )
break;
F_32 ( 3 ) ;
}
F_3 ( V_106 , V_43 -> V_7 + V_104 ) ;
}
static int F_33 ( struct V_42 * V_43 )
{
struct V_1 * V_2 = F_19 ( V_43 ) ;
F_34 ( V_2 -> V_107 ) ;
F_3 ( V_106 , V_43 -> V_7 + V_104 ) ;
F_3 ( V_108 , V_43 -> V_7 + V_109 ) ;
F_3 ( V_110 | V_111 | V_112 ,
V_43 -> V_7 + V_95 ) ;
F_3 ( V_66 , V_43 -> V_7 + V_113 ) ;
return 0 ;
}
static void F_35 ( struct V_42 * V_43 )
{
struct V_1 * V_2 = F_19 ( V_43 ) ;
F_3 ( V_108 , V_43 -> V_7 + V_114 ) ;
F_3 ( V_106 , V_43 -> V_7 + V_115 ) ;
F_3 ( V_110 | V_111 | V_112 ,
V_43 -> V_7 + V_19 ) ;
F_36 ( V_2 -> V_107 ) ;
}
static unsigned int F_37 ( struct V_42 * V_43 )
{
if ( F_2 ( V_43 -> V_7 + V_8 ) & V_116 )
return V_117 ;
else
return 0 ;
}
static void F_38 ( struct V_42 * V_43 )
{
struct V_1 * V_2 = F_19 ( V_43 ) ;
F_3 ( V_118 , V_43 -> V_7 + V_109 ) ;
F_1 ( V_2 ) ;
}
static void F_8 ( struct V_42 * V_43 )
{
F_3 ( V_118 , V_43 -> V_7 + V_114 ) ;
}
static void F_39 ( struct V_42 * V_43 )
{
F_3 ( V_84 , V_43 -> V_7 + V_114 ) ;
}
static void F_40 ( struct V_42 * V_43 , int V_119 )
{
if ( V_119 )
F_3 ( V_120 ,
V_43 -> V_7 + V_113 ) ;
else
F_3 ( V_120 ,
V_43 -> V_7 + V_121 ) ;
}
static void F_41 ( struct V_42 * V_5 )
{
}
static void F_42 ( struct V_42 * V_5 , int V_122 )
{
unsigned int V_123 = 1000 ;
while ( F_2 ( V_5 -> V_7 + V_8 ) & V_9 ) {
if ( ! V_123 -- )
break;
F_32 ( 1 ) ;
}
F_3 ( V_122 , V_5 -> V_7 + V_13 ) ;
}
static void
F_43 ( struct V_124 * V_125 , const char * V_126 , unsigned int V_127 )
{
struct V_1 * V_2 ;
struct V_42 * V_5 ;
unsigned int V_128 , V_129 ;
unsigned int V_123 = 1000 ;
if ( V_125 -> V_130 > V_131 || V_125 -> V_130 < 0 )
return;
V_2 = V_132 [ V_125 -> V_130 ] ;
V_5 = & V_2 -> V_5 ;
F_34 ( V_2 -> V_107 ) ;
V_129 = F_2 ( V_5 -> V_7 + V_53 ) ;
V_128 = F_2 ( V_5 -> V_7 + V_105 ) ;
F_3 ( V_106 ,
V_5 -> V_7 + V_104 ) ;
F_3 ( V_108 | V_118 ,
V_5 -> V_7 + V_109 ) ;
F_44 ( V_5 , V_126 , V_127 , F_42 ) ;
while ( F_2 ( V_5 -> V_7 + V_8 ) & V_133 ) {
if ( ! V_123 -- )
break;
F_32 ( 1 ) ;
}
F_3 ( V_128 , V_5 -> V_7 + V_105 ) ;
F_3 ( V_129 , V_5 -> V_7 + V_53 ) ;
F_36 ( V_2 -> V_107 ) ;
}
static void T_4
F_45 ( struct V_42 * V_5 , int * V_64 ,
int * V_30 , int * V_134 )
{
unsigned int V_135 , V_136 ;
if ( ! ( F_2 ( V_5 -> V_7 + V_53 ) & V_108 ) )
return;
V_135 = F_2 ( V_5 -> V_7 + V_90 ) ;
* V_30 = 'n' ;
if ( V_135 & V_73 ) {
if ( V_135 & V_75 )
* V_30 = 'e' ;
else
* V_30 = 'o' ;
}
if ( ( V_135 & V_137 ) == F_25 ( 2 ) )
* V_134 = 7 ;
else
* V_134 = 8 ;
V_136 = ( ( F_2 ( V_5 -> V_7 + V_90 )
& V_138 ) )
>> ( V_139 - 6 ) ;
V_136 |= ( ( F_2 ( V_5 -> V_7 + V_90 )
& V_140 ) )
>> V_141 ;
if ( V_136 == 0 )
V_136 = 1 ;
* V_64 = ( V_5 -> V_89 << 2 ) / V_136 ;
}
static int T_4
F_46 ( struct V_124 * V_125 , char * V_142 )
{
struct V_1 * V_2 ;
int V_64 = 9600 ;
int V_134 = 8 ;
int V_30 = 'n' ;
int V_143 = 'n' ;
int V_144 ;
if ( V_125 -> V_130 == - 1 || V_125 -> V_130 >= F_47 ( V_132 ) )
V_125 -> V_130 = 0 ;
V_2 = V_132 [ V_125 -> V_130 ] ;
if ( ! V_2 )
return - V_145 ;
F_34 ( V_2 -> V_107 ) ;
if ( V_142 )
F_48 ( V_142 , & V_64 , & V_30 , & V_134 , & V_143 ) ;
else
F_45 ( & V_2 -> V_5 , & V_64 , & V_30 , & V_134 ) ;
V_144 = F_49 ( & V_2 -> V_5 , V_125 , V_64 , V_30 , V_134 , V_143 ) ;
F_36 ( V_2 -> V_107 ) ;
return V_144 ;
}
static int T_5 F_50 ( struct V_146 * V_147 )
{
struct V_1 * V_2 ;
T_1 V_148 ;
int V_144 = 0 ;
struct V_149 * V_150 ;
V_2 = F_51 ( sizeof( struct V_1 ) , V_151 ) ;
if ( ! V_2 ) {
V_144 = - V_152 ;
goto V_28;
}
V_2 -> V_107 = F_52 ( & V_147 -> V_50 , NULL ) ;
if ( F_53 ( V_2 -> V_107 ) ) {
V_144 = F_54 ( V_2 -> V_107 ) ;
goto V_153;
}
V_150 = F_55 ( V_147 , V_154 , 0 ) ;
if ( ! V_150 ) {
V_144 = - V_155 ;
goto V_156;
}
V_2 -> V_5 . V_157 = V_150 -> V_158 ;
V_2 -> V_5 . V_7 = F_56 ( V_150 -> V_158 , F_57 ( V_150 ) ) ;
V_2 -> V_5 . V_159 = & V_160 ;
V_2 -> V_5 . V_161 = V_162 ;
V_2 -> V_5 . line = V_147 -> V_163 < 0 ? 0 : V_147 -> V_163 ;
V_2 -> V_5 . V_164 = 16 ;
V_2 -> V_5 . V_89 = F_58 ( V_2 -> V_107 ) ;
V_2 -> V_5 . type = V_47 ;
V_2 -> V_5 . V_50 = V_2 -> V_50 = F_59 ( & V_147 -> V_50 ) ;
V_2 -> V_49 = 0 ;
V_2 -> V_52 = 0 ;
V_2 -> V_91 = F_60 ( V_147 , 0 ) ;
V_2 -> V_5 . V_91 = V_2 -> V_91 ;
V_144 = F_61 ( V_2 -> V_91 , F_29 , 0 , F_20 ( & V_147 -> V_50 ) , V_2 ) ;
if ( V_144 )
goto V_156;
F_62 ( V_147 , V_2 ) ;
V_132 [ V_147 -> V_163 ] = V_2 ;
F_31 ( & V_2 -> V_5 ) ;
V_144 = F_63 ( & V_165 , & V_2 -> V_5 ) ;
if ( V_144 )
goto V_166;
V_148 = F_2 ( V_2 -> V_5 . V_7 + V_167 ) ;
F_64 ( & V_147 -> V_50 , L_1 ,
( V_148 >> 24 ) & 0xff ,
( V_148 >> 16 ) & 0xff , V_148 & 0xffff ) ;
return 0 ;
V_166:
V_132 [ V_147 -> V_163 ] = NULL ;
F_65 ( V_2 -> V_91 , V_2 ) ;
V_156:
F_66 ( V_2 -> V_107 ) ;
V_153:
F_67 ( V_2 ) ;
V_28:
return V_144 ;
}
static int T_6 F_68 ( struct V_146 * V_147 )
{
struct V_1 * V_2 = F_69 ( V_147 ) ;
F_70 ( & V_165 , & V_2 -> V_5 ) ;
V_132 [ V_147 -> V_163 ] = NULL ;
F_66 ( V_2 -> V_107 ) ;
F_65 ( V_2 -> V_91 , V_2 ) ;
F_67 ( V_2 ) ;
return 0 ;
}
static int T_4 F_71 ( void )
{
int V_150 ;
V_150 = F_72 ( & V_165 ) ;
if ( V_150 )
goto V_28;
V_150 = F_73 ( & V_168 ) ;
if ( V_150 )
goto V_169;
return 0 ;
V_169:
F_74 ( & V_165 ) ;
V_28:
return V_150 ;
}
static void T_7 F_75 ( void )
{
F_76 ( & V_168 ) ;
F_74 ( & V_165 ) ;
}
