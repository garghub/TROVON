static inline int F_1 ( struct V_1 * V_2 )
{
return V_2 -> V_3 == V_4 ;
}
static inline bool F_2 ( struct V_1 * V_2 )
{
return V_2 -> V_5 & V_6 ;
}
static void F_3 ( void * V_7 )
{
struct V_1 * V_2 = V_7 ;
struct V_8 * V_9 = & V_2 -> V_10 . V_11 -> V_9 ;
F_4 ( V_2 -> V_12 , & V_2 -> V_13 , 1 , V_14 ) ;
F_5 ( V_15 , & V_2 -> V_5 ) ;
F_6 () ;
if ( F_7 ( V_9 ) < V_16 )
F_8 ( & V_2 -> V_10 ) ;
F_9 ( V_2 ) ;
}
static int F_10 ( struct V_1 * V_2 , int V_17 )
{
struct V_18 * V_19 ;
struct V_20 * V_21 = & V_2 -> V_13 ;
struct V_22 * V_23 = V_2 -> V_24 ;
T_1 V_25 ;
V_25 = F_11 ( V_17 ) ;
V_19 = F_12 ( V_23 , (struct V_20 * ) & V_25 ,
1 , V_26 , 0 ) ;
if ( ! V_19 ) {
F_13 ( V_2 -> V_12 , L_1 ) ;
return - V_27 ;
}
F_14 ( V_21 , V_2 -> V_28 , V_17 ) ;
F_15 ( V_2 -> V_12 , V_21 , 1 , V_14 ) ;
V_19 = F_12 ( V_23 , V_21 ,
1 , V_29 , V_30 | V_31 ) ;
if ( ! V_19 ) {
F_13 ( V_2 -> V_12 , L_2 ) ;
return - V_27 ;
}
V_19 -> V_32 = F_3 ;
V_19 -> V_33 = V_2 ;
F_16 ( V_19 ) ;
F_17 ( V_23 ) ;
return 0 ;
}
static void F_9 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = & V_2 -> V_10 . V_11 -> V_9 ;
if ( F_2 ( V_2 ) ) {
T_1 V_34 = 0 ;
int V_17 ;
void * V_35 = V_2 -> V_28 ;
if ( F_18 ( V_15 , & V_2 -> V_5 ) )
return;
while ( ! F_19 ( V_9 ) && ! F_20 ( & V_2 -> V_10 ) ) {
V_17 = F_21 ( T_1 , V_36 - V_34 ,
F_22 ( V_9 -> V_37 ,
V_9 -> V_38 ,
V_36 ) ) ;
memcpy ( V_35 + V_34 , V_9 -> V_39 + V_9 -> V_38 , V_17 ) ;
V_9 -> V_38 = ( V_9 -> V_38 + V_17 ) & ( V_36 - 1 ) ;
V_34 += V_17 ;
if ( V_34 >= V_36 )
break;
}
if ( F_20 ( & V_2 -> V_10 ) )
F_23 ( & V_2 -> V_10 ) ;
if ( V_34 ) {
F_10 ( V_2 , V_34 ) ;
} else {
F_5 ( V_15 , & V_2 -> V_5 ) ;
F_6 () ;
}
return;
}
while ( ! ( F_24 ( V_2 -> V_10 . V_40 + V_41 ) &
V_42 ) ) {
if ( V_2 -> V_10 . V_43 ) {
V_2 -> V_10 . V_44 . V_45 ++ ;
F_25 ( V_2 -> V_10 . V_43 ,
V_2 -> V_10 . V_40 + V_46 ) ;
V_2 -> V_10 . V_43 = 0 ;
continue;
}
if ( ! F_19 ( V_9 ) && ! F_20 ( & V_2 -> V_10 ) ) {
V_2 -> V_10 . V_44 . V_45 ++ ;
F_25 ( V_9 -> V_39 [ V_9 -> V_38 ] ,
V_2 -> V_10 . V_40 + V_46 ) ;
V_9 -> V_38 = ( V_9 -> V_38 + 1 ) & ( V_36 - 1 ) ;
} else
break;
}
if ( F_7 ( V_9 ) < V_16 )
F_8 ( & V_2 -> V_10 ) ;
if ( F_19 ( & ( V_2 -> V_10 . V_11 -> V_9 ) ) )
F_25 ( V_47 ,
V_2 -> V_10 . V_40 + V_48 ) ;
else
F_25 ( V_47 ,
V_2 -> V_10 . V_40 + V_49 ) ;
if ( F_20 ( & V_2 -> V_10 ) )
F_23 ( & V_2 -> V_10 ) ;
}
static void F_26 ( struct V_1 * V_2 )
{
int V_50 ;
T_1 V_51 ;
T_2 V_52 ;
V_52 = F_24 ( V_2 -> V_10 . V_40 + V_46 ) ;
V_51 = F_24 ( V_2 -> V_10 . V_40 + V_41 ) ;
V_50 = V_53 ;
V_2 -> V_10 . V_44 . V_54 ++ ;
if ( V_51 & V_55 ) {
V_2 -> V_10 . V_44 . V_56 ++ ;
if ( F_27 ( & V_2 -> V_10 ) )
goto V_57;
} else if ( V_51 & V_58 ) {
V_2 -> V_10 . V_44 . V_59 ++ ;
} else if ( V_51 & V_60 ) {
V_2 -> V_10 . V_44 . V_61 ++ ;
}
V_51 &= V_2 -> V_10 . V_62 ;
if ( V_51 & V_55 ) {
V_50 = V_63 ;
} else if ( V_51 & V_58 )
V_50 = V_64 ;
else if ( V_51 & V_60 )
V_50 = V_65 ;
if ( V_51 & V_66 )
V_2 -> V_10 . V_44 . V_67 ++ ;
if ( F_28 ( & V_2 -> V_10 , V_52 ) )
goto V_57;
F_29 ( & V_2 -> V_10 , V_51 , V_66 , V_52 , V_50 ) ;
V_57:
F_25 ( V_51 , V_2 -> V_10 . V_40 + V_41 ) ;
}
static void F_30 ( struct V_1 * V_2 )
{
T_1 V_51 = 0 ;
for (; ; ) {
V_51 = F_24 ( V_2 -> V_10 . V_40 + V_41 ) ;
if ( V_51 & V_68 )
break;
F_26 ( V_2 ) ;
}
F_25 ( V_51 , V_2 -> V_10 . V_40 + V_41 ) ;
F_31 ( & V_2 -> V_10 . V_11 -> V_10 ) ;
}
static int F_32 ( struct V_69 * V_70 )
{
return 0 ;
}
static int F_33 ( struct V_69 * V_70 ,
struct V_71 * V_72 )
{
if ( V_70 -> type != V_73 && V_70 -> type != V_74 )
return - V_27 ;
return 0 ;
}
static void F_34 ( struct V_69 * V_70 , int V_5 )
{
}
static const char * F_35 ( struct V_69 * V_70 )
{
struct V_1 * V_2 = F_36 ( V_70 ) ;
return F_37 ( V_2 -> V_12 ) ;
}
static void F_38 ( struct V_69 * V_70 )
{
}
static void F_39 ( struct V_69 * V_70 , unsigned V_75 )
{
struct V_1 * V_2 = F_36 ( V_70 ) ;
T_1 V_76 = F_24 ( V_70 -> V_40 + V_77 ) ;
V_76 &= ~ ( V_78 | V_79 ) ;
if ( V_75 & V_80 ) {
if ( F_40 ( & V_70 -> V_11 -> V_10 ) )
V_76 |= V_78 ;
else
V_76 |= V_79 ;
}
V_2 -> V_76 = V_75 ;
F_25 ( V_76 , V_70 -> V_40 + V_77 ) ;
}
static T_1 F_41 ( struct V_69 * V_70 )
{
struct V_1 * V_2 = F_36 ( V_70 ) ;
T_1 V_51 = F_24 ( V_70 -> V_40 + V_41 ) ;
int V_81 = F_24 ( V_70 -> V_40 + V_77 ) ;
T_1 V_75 = V_2 -> V_76 ;
V_75 &= ~ V_82 ;
if ( V_51 & V_83 )
V_75 |= V_82 ;
if ( V_81 & V_79 )
V_75 |= V_80 ;
return V_75 ;
}
static void F_42 ( void * V_84 )
{
struct V_1 * V_2 = (struct V_1 * ) V_84 ;
struct V_85 * V_10 = & V_2 -> V_10 . V_11 -> V_10 ;
int V_86 ;
T_1 V_51 ;
F_4 ( V_2 -> V_12 , & V_2 -> V_87 , 1 , V_88 ) ;
V_51 = F_24 ( V_2 -> V_10 . V_40 + V_41 ) ;
V_51 &= ~ ( V_66 | V_55 |
V_58 | V_60 ) ;
V_86 = V_51 & V_89 ;
F_43 ( V_10 , V_2 -> V_90 , V_86 ) ;
F_25 ( V_51 , V_2 -> V_10 . V_40 + V_41 ) ;
F_31 ( V_10 ) ;
F_44 ( V_2 ) ;
}
static int F_44 ( struct V_1 * V_2 )
{
struct V_18 * V_19 ;
struct V_20 * V_21 = & V_2 -> V_87 ;
struct V_22 * V_23 = V_2 -> V_91 ;
T_1 V_25 [ 1 ] ;
V_25 [ 0 ] = V_92
| F_45 ( 0x80 )
| F_46 ( V_36 ) ;
V_19 = F_12 ( V_23 , (struct V_20 * ) V_25 ,
1 , V_26 , 0 ) ;
if ( ! V_19 ) {
F_13 ( V_2 -> V_12 , L_1 ) ;
return - V_27 ;
}
F_14 ( V_21 , V_2 -> V_90 , V_36 ) ;
F_15 ( V_2 -> V_12 , V_21 , 1 , V_88 ) ;
V_19 = F_12 ( V_23 , V_21 , 1 , V_93 ,
V_30 | V_31 ) ;
if ( ! V_19 ) {
F_13 ( V_2 -> V_12 , L_2 ) ;
return - 1 ;
}
V_19 -> V_32 = F_42 ;
V_19 -> V_33 = V_2 ;
F_16 ( V_19 ) ;
F_17 ( V_23 ) ;
return 0 ;
}
static void F_47 ( struct V_1 * V_2 )
{
if ( V_2 -> V_24 ) {
F_48 ( V_2 -> V_24 ) ;
V_2 -> V_24 = NULL ;
}
if ( V_2 -> V_91 ) {
F_48 ( V_2 -> V_91 ) ;
V_2 -> V_91 = NULL ;
}
F_49 ( V_2 -> V_28 ) ;
F_49 ( V_2 -> V_90 ) ;
V_2 -> V_28 = NULL ;
V_2 -> V_90 = NULL ;
}
static void F_50 ( struct V_1 * V_2 )
{
F_25 ( V_94 | V_95 | V_96 ,
V_2 -> V_10 . V_40 + V_97 ) ;
F_47 ( V_2 ) ;
V_2 -> V_5 &= ~ V_6 ;
F_5 ( V_15 , & V_2 -> V_5 ) ;
F_5 ( V_98 , & V_2 -> V_5 ) ;
}
static int F_51 ( struct V_1 * V_2 )
{
if ( F_2 ( V_2 ) )
return 0 ;
V_2 -> V_91 = F_52 ( V_2 -> V_12 , L_3 ) ;
if ( ! V_2 -> V_91 )
goto V_99;
V_2 -> V_90 = F_53 ( V_36 , V_100 | V_101 ) ;
if ( ! V_2 -> V_90 )
goto V_99;
V_2 -> V_24 = F_52 ( V_2 -> V_12 , L_4 ) ;
if ( ! V_2 -> V_24 )
goto V_99;
V_2 -> V_28 = F_53 ( V_36 , V_100 | V_101 ) ;
if ( ! V_2 -> V_28 )
goto V_99;
V_2 -> V_5 |= V_6 ;
F_54 ( V_2 -> V_12 , L_5 ) ;
return 0 ;
V_99:
F_47 ( V_2 ) ;
return - V_27 ;
}
static void F_55 ( struct V_69 * V_70 ,
struct V_102 * V_103 ,
struct V_102 * V_104 )
{
struct V_1 * V_2 = F_36 ( V_70 ) ;
T_1 V_105 , V_76 , V_81 , div ;
unsigned int V_106 , V_107 ;
V_106 = V_103 -> V_108 ;
V_76 = V_109 ;
V_81 = F_24 ( V_70 -> V_40 + V_77 ) ;
switch ( V_106 & V_110 ) {
case V_111 :
V_105 = 0 ;
break;
case V_112 :
V_105 = 1 ;
break;
case V_113 :
V_105 = 2 ;
break;
case V_114 :
V_105 = 3 ;
break;
default:
return;
}
V_76 |= F_56 ( V_105 ) ;
if ( V_106 & V_115 ) {
V_76 |= V_116 ;
if ( ( V_106 & V_117 ) == 0 )
V_76 |= V_118 ;
}
V_70 -> V_62 = 0 ;
if ( V_103 -> V_119 & V_120 )
V_70 -> V_62 |= V_58 ;
if ( V_103 -> V_119 & ( V_121 | V_122 ) )
V_70 -> V_62 |= V_55 ;
V_70 -> V_123 = 0 ;
if ( V_103 -> V_119 & V_124 )
V_70 -> V_123 |= V_58 ;
if ( V_103 -> V_119 & V_125 ) {
V_70 -> V_123 |= V_55 ;
if ( V_103 -> V_119 & V_124 )
V_70 -> V_123 |= V_66 ;
}
if ( V_106 & V_126 )
V_81 |= V_127 ;
else
V_81 &= ~ V_127 ;
if ( V_106 & V_128 )
V_76 |= V_129 ;
if ( V_106 & V_130 ) {
if ( F_1 ( V_2 ) && ( V_2 -> V_5 & V_131 ) ) {
if ( ! F_51 ( V_2 ) )
V_81 |= V_94 | V_95
| V_96 ;
}
V_81 |= V_132 | V_78 ;
} else {
V_81 &= ~ ( V_132 | V_78 ) ;
}
V_107 = F_57 ( V_70 , V_103 , V_104 , 0 , V_70 -> V_133 ) ;
div = V_70 -> V_133 * 32 / V_107 ;
V_76 |= F_58 ( div & 0x3F ) ;
V_76 |= F_59 ( div >> 6 ) ;
F_25 ( V_76 , V_70 -> V_40 + V_134 ) ;
F_25 ( V_81 , V_70 -> V_40 + V_77 ) ;
F_60 ( V_70 , V_103 -> V_108 , V_107 ) ;
if ( F_2 ( V_2 ) &&
! F_18 ( V_98 , & V_2 -> V_5 ) ) {
if ( ! F_44 ( V_2 ) ) {
F_25 ( V_135 | V_136 ,
V_70 -> V_40 + V_48 ) ;
} else {
F_50 ( V_2 ) ;
F_13 ( V_2 -> V_12 , L_6 ) ;
}
}
}
static T_3 F_61 ( int V_137 , void * V_138 )
{
T_1 V_139 ;
struct V_1 * V_2 = V_138 ;
T_1 V_51 = F_24 ( V_2 -> V_10 . V_40 + V_41 ) ;
V_139 = F_24 ( V_2 -> V_10 . V_40 + V_140 ) ;
F_25 ( V_139 & ( V_141
| V_142
| V_143
| V_144 ) ,
V_2 -> V_10 . V_40 + V_48 ) ;
if ( V_139 & V_144 ) {
F_62 ( & V_2 -> V_10 , V_51 & V_83 ) ;
F_25 ( V_144 ,
V_2 -> V_10 . V_40 + V_48 ) ;
V_139 &= ~ V_144 ;
}
if ( V_139 & ( V_141 | V_143 ) ) {
if ( ! F_2 ( V_2 ) )
F_30 ( V_2 ) ;
V_139 &= ~ ( V_141 | V_143 ) ;
}
if ( V_139 & V_142 ) {
F_9 ( V_2 ) ;
V_139 &= ~ V_142 ;
}
return V_145 ;
}
static void F_63 ( struct V_69 * V_70 )
{
int V_34 ;
unsigned int V_146 ;
F_25 ( V_147 , V_70 -> V_40 + V_148 ) ;
for ( V_34 = 0 ; V_34 < 10000 ; V_34 ++ ) {
V_146 = F_24 ( V_70 -> V_40 + V_149 ) ;
if ( ! ( V_146 & V_147 ) )
break;
F_64 ( 3 ) ;
}
F_25 ( V_150 , V_70 -> V_40 + V_148 ) ;
}
static int F_65 ( struct V_69 * V_70 )
{
struct V_1 * V_2 = F_36 ( V_70 ) ;
F_66 ( V_2 -> V_151 ) ;
F_25 ( V_150 , V_70 -> V_40 + V_148 ) ;
F_25 ( V_152 , V_70 -> V_40 + V_153 ) ;
F_25 ( V_135 | V_136 | V_154 ,
V_70 -> V_40 + V_140 ) ;
F_25 ( V_109 , V_70 -> V_40 + V_155 ) ;
return 0 ;
}
static void F_67 ( struct V_69 * V_70 )
{
struct V_1 * V_2 = F_36 ( V_70 ) ;
if ( F_2 ( V_2 ) )
F_50 ( V_2 ) ;
F_25 ( V_152 , V_70 -> V_40 + V_97 ) ;
F_25 ( V_135 | V_136 | V_154 ,
V_70 -> V_40 + V_48 ) ;
F_25 ( V_150 , V_70 -> V_40 + V_156 ) ;
F_68 ( V_2 -> V_151 ) ;
}
static unsigned int F_69 ( struct V_69 * V_70 )
{
if ( F_24 ( V_70 -> V_40 + V_41 ) & V_157 )
return V_158 ;
else
return 0 ;
}
static void F_70 ( struct V_69 * V_70 )
{
struct V_1 * V_2 = F_36 ( V_70 ) ;
F_25 ( V_159 , V_70 -> V_40 + V_153 ) ;
F_9 ( V_2 ) ;
}
static void F_23 ( struct V_69 * V_70 )
{
F_25 ( V_159 , V_70 -> V_40 + V_97 ) ;
}
static void F_71 ( struct V_69 * V_70 )
{
F_25 ( V_127 , V_70 -> V_40 + V_97 ) ;
}
static void F_72 ( struct V_69 * V_70 , int V_160 )
{
if ( V_160 )
F_25 ( V_161 ,
V_70 -> V_40 + V_155 ) ;
else
F_25 ( V_161 ,
V_70 -> V_40 + V_162 ) ;
}
static void F_73 ( struct V_69 * V_10 )
{
}
static void F_74 ( struct V_69 * V_10 , int V_163 )
{
unsigned int V_164 = 1000 ;
while ( F_24 ( V_10 -> V_40 + V_41 ) & V_42 ) {
if ( ! V_164 -- )
break;
F_64 ( 1 ) ;
}
F_25 ( V_163 , V_10 -> V_40 + V_46 ) ;
}
static void
F_75 ( struct V_165 * V_166 , const char * V_167 , unsigned int V_86 )
{
struct V_1 * V_2 ;
struct V_69 * V_10 ;
unsigned int V_168 , V_169 ;
unsigned int V_164 = 20000 ;
if ( V_166 -> V_170 >= V_171 || V_166 -> V_170 < 0 )
return;
V_2 = V_172 [ V_166 -> V_170 ] ;
V_10 = & V_2 -> V_10 ;
F_76 ( V_2 -> V_151 ) ;
V_169 = F_24 ( V_10 -> V_40 + V_77 ) ;
V_168 = F_24 ( V_10 -> V_40 + V_149 ) ;
F_25 ( V_150 ,
V_10 -> V_40 + V_148 ) ;
F_25 ( V_152 | V_159 ,
V_10 -> V_40 + V_153 ) ;
F_77 ( V_10 , V_167 , V_86 , F_74 ) ;
while ( F_24 ( V_10 -> V_40 + V_41 ) & V_173 ) {
F_64 ( 1 ) ;
if ( ! V_164 -- )
break;
}
if ( ! ( F_24 ( V_10 -> V_40 + V_41 ) & V_173 ) ) {
F_25 ( V_168 , V_10 -> V_40 + V_149 ) ;
F_25 ( V_169 , V_10 -> V_40 + V_77 ) ;
}
F_78 ( V_2 -> V_151 ) ;
}
static void T_4
F_79 ( struct V_69 * V_10 , int * V_107 ,
int * V_59 , int * V_174 )
{
unsigned int V_175 , V_176 ;
if ( ! ( F_24 ( V_10 -> V_40 + V_77 ) & V_152 ) )
return;
V_175 = F_24 ( V_10 -> V_40 + V_134 ) ;
* V_59 = 'n' ;
if ( V_175 & V_116 ) {
if ( V_175 & V_118 )
* V_59 = 'e' ;
else
* V_59 = 'o' ;
}
if ( ( V_175 & V_177 ) == F_56 ( 2 ) )
* V_174 = 7 ;
else
* V_174 = 8 ;
V_176 = ( ( F_24 ( V_10 -> V_40 + V_134 )
& V_178 ) )
>> ( V_179 - 6 ) ;
V_176 |= ( ( F_24 ( V_10 -> V_40 + V_134 )
& V_180 ) )
>> V_181 ;
if ( V_176 == 0 )
V_176 = 1 ;
* V_107 = ( V_10 -> V_133 << 2 ) / V_176 ;
}
static int T_4
F_80 ( struct V_165 * V_166 , char * V_182 )
{
struct V_1 * V_2 ;
int V_107 = 9600 ;
int V_174 = 8 ;
int V_59 = 'n' ;
int V_183 = 'n' ;
int V_184 ;
if ( V_166 -> V_170 == - 1 || V_166 -> V_170 >= F_81 ( V_172 ) )
V_166 -> V_170 = 0 ;
V_2 = V_172 [ V_166 -> V_170 ] ;
if ( ! V_2 )
return - V_185 ;
F_66 ( V_2 -> V_151 ) ;
if ( V_182 )
F_82 ( V_182 , & V_107 , & V_59 , & V_174 , & V_183 ) ;
else
F_79 ( & V_2 -> V_10 , & V_107 , & V_59 , & V_174 ) ;
V_184 = F_83 ( & V_2 -> V_10 , V_166 , V_107 , V_59 , V_174 , V_183 ) ;
F_68 ( V_2 -> V_151 ) ;
return V_184 ;
}
static int F_84 ( struct V_1 * V_2 ,
struct V_186 * V_187 )
{
struct V_188 * V_189 = V_187 -> V_12 . V_190 ;
int V_184 ;
if ( ! V_189 )
return 1 ;
V_184 = F_85 ( V_189 , L_7 ) ;
if ( V_184 < 0 ) {
F_13 ( & V_187 -> V_12 , L_8 , V_184 ) ;
return V_184 ;
}
V_2 -> V_10 . line = V_184 ;
V_2 -> V_5 |= V_131 ;
return 0 ;
}
static int F_86 ( struct V_186 * V_187 )
{
const struct V_191 * V_192 =
F_87 ( V_193 , & V_187 -> V_12 ) ;
struct V_1 * V_2 ;
T_1 V_194 ;
int V_184 = 0 ;
struct V_195 * V_196 ;
struct V_197 * V_197 ;
V_2 = F_53 ( sizeof( struct V_1 ) , V_100 ) ;
if ( ! V_2 ) {
V_184 = - V_198 ;
goto V_57;
}
V_184 = F_84 ( V_2 , V_187 ) ;
if ( V_184 > 0 )
V_2 -> V_10 . line = V_187 -> V_199 < 0 ? 0 : V_187 -> V_199 ;
else if ( V_184 < 0 )
goto V_200;
V_197 = F_88 ( & V_187 -> V_12 ) ;
if ( F_89 ( V_197 ) ) {
V_184 = F_90 ( V_197 ) ;
goto V_200;
}
if ( V_192 ) {
V_187 -> V_201 = V_192 -> V_202 ;
V_2 -> V_3 = V_187 -> V_201 -> V_203 ;
}
V_2 -> V_151 = F_91 ( & V_187 -> V_12 , NULL ) ;
if ( F_89 ( V_2 -> V_151 ) ) {
V_184 = F_90 ( V_2 -> V_151 ) ;
goto V_200;
}
V_196 = F_92 ( V_187 , V_204 , 0 ) ;
if ( ! V_196 ) {
V_184 = - V_205 ;
goto V_206;
}
V_2 -> V_10 . V_207 = V_196 -> V_208 ;
V_2 -> V_10 . V_40 = F_93 ( V_196 -> V_208 , F_94 ( V_196 ) ) ;
V_2 -> V_10 . V_209 = & V_210 ;
V_2 -> V_10 . V_211 = V_212 ;
V_2 -> V_10 . V_213 = 16 ;
V_2 -> V_10 . V_133 = F_95 ( V_2 -> V_151 ) ;
V_2 -> V_10 . type = V_74 ;
V_2 -> V_10 . V_12 = V_2 -> V_12 = & V_187 -> V_12 ;
V_2 -> V_76 = 0 ;
V_2 -> V_137 = F_96 ( V_187 , 0 ) ;
V_2 -> V_10 . V_137 = V_2 -> V_137 ;
V_184 = F_97 ( V_2 -> V_137 , F_61 , 0 , F_37 ( & V_187 -> V_12 ) , V_2 ) ;
if ( V_184 )
goto V_206;
F_98 ( V_187 , V_2 ) ;
V_172 [ V_2 -> V_10 . line ] = V_2 ;
F_63 ( & V_2 -> V_10 ) ;
V_184 = F_99 ( & V_214 , & V_2 -> V_10 ) ;
if ( V_184 )
goto V_215;
V_194 = F_24 ( V_2 -> V_10 . V_40 + V_216 ) ;
F_100 ( & V_187 -> V_12 , L_9 ,
( V_194 >> 24 ) & 0xff ,
( V_194 >> 16 ) & 0xff , V_194 & 0xffff ) ;
return 0 ;
V_215:
V_172 [ V_187 -> V_199 ] = NULL ;
F_101 ( V_2 -> V_137 , V_2 ) ;
V_206:
F_102 ( V_2 -> V_151 ) ;
V_200:
F_49 ( V_2 ) ;
V_57:
return V_184 ;
}
static int F_103 ( struct V_186 * V_187 )
{
struct V_1 * V_2 = F_104 ( V_187 ) ;
F_105 ( & V_214 , & V_2 -> V_10 ) ;
V_172 [ V_187 -> V_199 ] = NULL ;
F_102 ( V_2 -> V_151 ) ;
F_101 ( V_2 -> V_137 , V_2 ) ;
F_49 ( V_2 ) ;
return 0 ;
}
static int T_4 F_106 ( void )
{
int V_196 ;
V_196 = F_107 ( & V_214 ) ;
if ( V_196 )
goto V_57;
V_196 = F_108 ( & V_217 ) ;
if ( V_196 )
goto V_218;
return 0 ;
V_218:
F_109 ( & V_214 ) ;
V_57:
return V_196 ;
}
static void T_5 F_110 ( void )
{
F_111 ( & V_217 ) ;
F_109 ( & V_214 ) ;
}
