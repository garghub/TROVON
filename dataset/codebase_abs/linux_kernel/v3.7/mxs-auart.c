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
if ( F_23 ( & V_43 -> V_6 -> V_5 ) )
V_52 |= V_54 ;
}
V_2 -> V_52 = V_51 ;
F_3 ( V_52 , V_43 -> V_7 + V_53 ) ;
}
static T_1 F_24 ( struct V_42 * V_43 )
{
struct V_1 * V_2 = F_19 ( V_43 ) ;
T_1 V_22 = F_2 ( V_43 -> V_7 + V_8 ) ;
int V_56 = F_2 ( V_43 -> V_7 + V_53 ) ;
T_1 V_51 = V_2 -> V_52 ;
V_51 &= ~ V_57 ;
if ( V_22 & V_58 )
V_51 |= V_57 ;
if ( V_56 & V_59 )
V_51 |= V_55 ;
return V_51 ;
}
static void F_25 ( struct V_42 * V_43 ,
struct V_60 * V_61 ,
struct V_60 * V_62 )
{
T_1 V_63 , V_52 , V_56 , div ;
unsigned int V_64 , V_65 ;
V_64 = V_61 -> V_66 ;
V_52 = V_67 ;
V_56 = F_2 ( V_43 -> V_7 + V_53 ) ;
switch ( V_64 & V_68 ) {
case V_69 :
V_63 = 0 ;
break;
case V_70 :
V_63 = 1 ;
break;
case V_71 :
V_63 = 2 ;
break;
case V_72 :
V_63 = 3 ;
break;
default:
return;
}
V_52 |= F_26 ( V_63 ) ;
if ( V_64 & V_73 ) {
V_52 |= V_74 ;
if ( ( V_64 & V_75 ) == 0 )
V_52 |= V_76 ;
}
V_43 -> V_33 = 0 ;
if ( V_61 -> V_77 & V_78 )
V_43 -> V_33 |= V_29 ;
if ( V_61 -> V_77 & ( V_79 | V_80 ) )
V_43 -> V_33 |= V_26 ;
V_43 -> V_81 = 0 ;
if ( V_61 -> V_77 & V_82 )
V_43 -> V_81 |= V_29 ;
if ( V_61 -> V_77 & V_83 ) {
V_43 -> V_81 |= V_26 ;
if ( V_61 -> V_77 & V_82 )
V_43 -> V_81 |= V_37 ;
}
if ( V_64 & V_84 )
V_56 |= V_85 ;
else
V_56 &= ~ V_85 ;
if ( V_64 & V_86 )
V_52 |= V_87 ;
if ( V_64 & V_88 )
V_56 |= V_89 | V_54 ;
else
V_56 &= ~ ( V_89 | V_54 ) ;
V_65 = F_27 ( V_43 , V_61 , V_62 , 0 , V_43 -> V_90 ) ;
div = V_43 -> V_90 * 32 / V_65 ;
V_52 |= F_28 ( div & 0x3F ) ;
V_52 |= F_29 ( div >> 6 ) ;
F_3 ( V_52 , V_43 -> V_7 + V_91 ) ;
F_3 ( V_56 , V_43 -> V_7 + V_53 ) ;
F_30 ( V_43 , V_61 -> V_66 , V_65 ) ;
}
static T_3 F_31 ( int V_92 , void * V_93 )
{
T_1 V_94 , V_95 ;
struct V_1 * V_2 = V_93 ;
T_1 V_22 = F_2 ( V_2 -> V_5 . V_7 + V_8 ) ;
V_94 = V_95 = F_2 ( V_2 -> V_5 . V_7 + V_96 ) ;
if ( V_95 & V_97 ) {
F_32 ( & V_2 -> V_5 , V_22 & V_58 ) ;
F_3 ( V_97 ,
V_2 -> V_5 . V_7 + V_19 ) ;
V_95 &= ~ V_97 ;
}
if ( V_95 & ( V_98 | V_99 ) ) {
F_13 ( V_2 ) ;
V_95 &= ~ ( V_98 | V_99 ) ;
}
if ( V_95 & V_100 ) {
F_1 ( V_2 ) ;
V_95 &= ~ V_100 ;
}
F_3 ( V_94 & ( V_98
| V_100
| V_99
| V_97 ) ,
V_2 -> V_5 . V_7 + V_19 ) ;
return V_101 ;
}
static void F_33 ( struct V_42 * V_43 )
{
int V_102 ;
unsigned int V_103 ;
F_3 ( V_104 , V_43 -> V_7 + V_105 ) ;
for ( V_102 = 0 ; V_102 < 10000 ; V_102 ++ ) {
V_103 = F_2 ( V_43 -> V_7 + V_106 ) ;
if ( ! ( V_103 & V_104 ) )
break;
F_34 ( 3 ) ;
}
F_3 ( V_107 , V_43 -> V_7 + V_105 ) ;
}
static int F_35 ( struct V_42 * V_43 )
{
struct V_1 * V_2 = F_19 ( V_43 ) ;
F_36 ( V_2 -> V_108 ) ;
F_3 ( V_107 , V_43 -> V_7 + V_105 ) ;
F_3 ( V_109 , V_43 -> V_7 + V_110 ) ;
F_3 ( V_111 | V_112 | V_113 ,
V_43 -> V_7 + V_96 ) ;
F_3 ( V_67 , V_43 -> V_7 + V_114 ) ;
return 0 ;
}
static void F_37 ( struct V_42 * V_43 )
{
struct V_1 * V_2 = F_19 ( V_43 ) ;
F_3 ( V_109 , V_43 -> V_7 + V_115 ) ;
F_3 ( V_111 | V_112 | V_113 ,
V_43 -> V_7 + V_19 ) ;
F_3 ( V_107 , V_43 -> V_7 + V_116 ) ;
F_38 ( V_2 -> V_108 ) ;
}
static unsigned int F_39 ( struct V_42 * V_43 )
{
if ( F_2 ( V_43 -> V_7 + V_8 ) & V_117 )
return V_118 ;
else
return 0 ;
}
static void F_40 ( struct V_42 * V_43 )
{
struct V_1 * V_2 = F_19 ( V_43 ) ;
F_3 ( V_119 , V_43 -> V_7 + V_110 ) ;
F_1 ( V_2 ) ;
}
static void F_8 ( struct V_42 * V_43 )
{
F_3 ( V_119 , V_43 -> V_7 + V_115 ) ;
}
static void F_41 ( struct V_42 * V_43 )
{
F_3 ( V_85 , V_43 -> V_7 + V_115 ) ;
}
static void F_42 ( struct V_42 * V_43 , int V_120 )
{
if ( V_120 )
F_3 ( V_121 ,
V_43 -> V_7 + V_114 ) ;
else
F_3 ( V_121 ,
V_43 -> V_7 + V_122 ) ;
}
static void F_43 ( struct V_42 * V_5 )
{
}
static void F_44 ( struct V_42 * V_5 , int V_123 )
{
unsigned int V_124 = 1000 ;
while ( F_2 ( V_5 -> V_7 + V_8 ) & V_9 ) {
if ( ! V_124 -- )
break;
F_34 ( 1 ) ;
}
F_3 ( V_123 , V_5 -> V_7 + V_13 ) ;
}
static void
F_45 ( struct V_125 * V_126 , const char * V_127 , unsigned int V_128 )
{
struct V_1 * V_2 ;
struct V_42 * V_5 ;
unsigned int V_129 , V_130 ;
unsigned int V_124 = 1000 ;
if ( V_126 -> V_131 > V_132 || V_126 -> V_131 < 0 )
return;
V_2 = V_133 [ V_126 -> V_131 ] ;
V_5 = & V_2 -> V_5 ;
F_46 ( V_2 -> V_108 ) ;
V_130 = F_2 ( V_5 -> V_7 + V_53 ) ;
V_129 = F_2 ( V_5 -> V_7 + V_106 ) ;
F_3 ( V_107 ,
V_5 -> V_7 + V_105 ) ;
F_3 ( V_109 | V_119 ,
V_5 -> V_7 + V_110 ) ;
F_47 ( V_5 , V_127 , V_128 , F_44 ) ;
while ( F_2 ( V_5 -> V_7 + V_8 ) & V_134 ) {
if ( ! V_124 -- )
break;
F_34 ( 1 ) ;
}
F_3 ( V_129 , V_5 -> V_7 + V_106 ) ;
F_3 ( V_130 , V_5 -> V_7 + V_53 ) ;
F_48 ( V_2 -> V_108 ) ;
}
static void T_4
F_49 ( struct V_42 * V_5 , int * V_65 ,
int * V_30 , int * V_135 )
{
unsigned int V_136 , V_137 ;
if ( ! ( F_2 ( V_5 -> V_7 + V_53 ) & V_109 ) )
return;
V_136 = F_2 ( V_5 -> V_7 + V_91 ) ;
* V_30 = 'n' ;
if ( V_136 & V_74 ) {
if ( V_136 & V_76 )
* V_30 = 'e' ;
else
* V_30 = 'o' ;
}
if ( ( V_136 & V_138 ) == F_26 ( 2 ) )
* V_135 = 7 ;
else
* V_135 = 8 ;
V_137 = ( ( F_2 ( V_5 -> V_7 + V_91 )
& V_139 ) )
>> ( V_140 - 6 ) ;
V_137 |= ( ( F_2 ( V_5 -> V_7 + V_91 )
& V_141 ) )
>> V_142 ;
if ( V_137 == 0 )
V_137 = 1 ;
* V_65 = ( V_5 -> V_90 << 2 ) / V_137 ;
}
static int T_4
F_50 ( struct V_125 * V_126 , char * V_143 )
{
struct V_1 * V_2 ;
int V_65 = 9600 ;
int V_135 = 8 ;
int V_30 = 'n' ;
int V_144 = 'n' ;
int V_145 ;
if ( V_126 -> V_131 == - 1 || V_126 -> V_131 >= F_51 ( V_133 ) )
V_126 -> V_131 = 0 ;
V_2 = V_133 [ V_126 -> V_131 ] ;
if ( ! V_2 )
return - V_146 ;
F_36 ( V_2 -> V_108 ) ;
if ( V_143 )
F_52 ( V_143 , & V_65 , & V_30 , & V_135 , & V_144 ) ;
else
F_49 ( & V_2 -> V_5 , & V_65 , & V_30 , & V_135 ) ;
V_145 = F_53 ( & V_2 -> V_5 , V_126 , V_65 , V_30 , V_135 , V_144 ) ;
F_38 ( V_2 -> V_108 ) ;
return V_145 ;
}
static int F_54 ( struct V_1 * V_2 ,
struct V_147 * V_148 )
{
struct V_149 * V_150 = V_148 -> V_50 . V_151 ;
int V_145 ;
if ( ! V_150 )
return 1 ;
V_145 = F_55 ( V_150 , L_1 ) ;
if ( V_145 < 0 ) {
F_56 ( & V_148 -> V_50 , L_2 , V_145 ) ;
return V_145 ;
}
V_2 -> V_5 . line = V_145 ;
return 0 ;
}
static int T_5 F_57 ( struct V_147 * V_148 )
{
struct V_1 * V_2 ;
T_1 V_152 ;
int V_145 = 0 ;
struct V_153 * V_154 ;
struct V_155 * V_155 ;
V_2 = F_58 ( sizeof( struct V_1 ) , V_156 ) ;
if ( ! V_2 ) {
V_145 = - V_157 ;
goto V_28;
}
V_145 = F_54 ( V_2 , V_148 ) ;
if ( V_145 > 0 )
V_2 -> V_5 . line = V_148 -> V_158 < 0 ? 0 : V_148 -> V_158 ;
else if ( V_145 < 0 )
goto V_159;
V_155 = F_59 ( & V_148 -> V_50 ) ;
if ( F_60 ( V_155 ) ) {
V_145 = F_61 ( V_155 ) ;
goto V_159;
}
V_2 -> V_108 = F_62 ( & V_148 -> V_50 , NULL ) ;
if ( F_60 ( V_2 -> V_108 ) ) {
V_145 = F_61 ( V_2 -> V_108 ) ;
goto V_159;
}
V_154 = F_63 ( V_148 , V_160 , 0 ) ;
if ( ! V_154 ) {
V_145 = - V_161 ;
goto V_162;
}
V_2 -> V_5 . V_163 = V_154 -> V_164 ;
V_2 -> V_5 . V_7 = F_64 ( V_154 -> V_164 , F_65 ( V_154 ) ) ;
V_2 -> V_5 . V_165 = & V_166 ;
V_2 -> V_5 . V_167 = V_168 ;
V_2 -> V_5 . V_169 = 16 ;
V_2 -> V_5 . V_90 = F_66 ( V_2 -> V_108 ) ;
V_2 -> V_5 . type = V_47 ;
V_2 -> V_5 . V_50 = V_2 -> V_50 = F_67 ( & V_148 -> V_50 ) ;
V_2 -> V_49 = 0 ;
V_2 -> V_52 = 0 ;
V_2 -> V_92 = F_68 ( V_148 , 0 ) ;
V_2 -> V_5 . V_92 = V_2 -> V_92 ;
V_145 = F_69 ( V_2 -> V_92 , F_31 , 0 , F_20 ( & V_148 -> V_50 ) , V_2 ) ;
if ( V_145 )
goto V_162;
F_70 ( V_148 , V_2 ) ;
V_133 [ V_2 -> V_5 . line ] = V_2 ;
F_33 ( & V_2 -> V_5 ) ;
V_145 = F_71 ( & V_170 , & V_2 -> V_5 ) ;
if ( V_145 )
goto V_171;
V_152 = F_2 ( V_2 -> V_5 . V_7 + V_172 ) ;
F_72 ( & V_148 -> V_50 , L_3 ,
( V_152 >> 24 ) & 0xff ,
( V_152 >> 16 ) & 0xff , V_152 & 0xffff ) ;
return 0 ;
V_171:
V_133 [ V_148 -> V_158 ] = NULL ;
F_73 ( V_2 -> V_92 , V_2 ) ;
V_162:
F_74 ( V_2 -> V_50 ) ;
F_75 ( V_2 -> V_108 ) ;
V_159:
F_76 ( V_2 ) ;
V_28:
return V_145 ;
}
static int T_6 F_77 ( struct V_147 * V_148 )
{
struct V_1 * V_2 = F_78 ( V_148 ) ;
F_79 ( & V_170 , & V_2 -> V_5 ) ;
V_133 [ V_148 -> V_158 ] = NULL ;
F_74 ( V_2 -> V_50 ) ;
F_75 ( V_2 -> V_108 ) ;
F_73 ( V_2 -> V_92 , V_2 ) ;
F_76 ( V_2 ) ;
return 0 ;
}
static int T_4 F_80 ( void )
{
int V_154 ;
V_154 = F_81 ( & V_170 ) ;
if ( V_154 )
goto V_28;
V_154 = F_82 ( & V_173 ) ;
if ( V_154 )
goto V_174;
return 0 ;
V_174:
F_83 ( & V_170 ) ;
V_28:
return V_154 ;
}
static void T_7 F_84 ( void )
{
F_85 ( & V_173 ) ;
F_83 ( & V_170 ) ;
}
