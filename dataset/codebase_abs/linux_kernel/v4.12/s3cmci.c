static void F_1 ( struct V_1 * V_2 , char * V_3 )
{
T_1 V_4 , V_5 , V_6 , V_7 , V_8 , V_9 , V_10 , V_11 , V_12 , V_13 , V_14 ;
T_1 V_15 , V_16 , V_17 , V_18 , V_19 ;
V_4 = F_2 ( V_2 -> V_20 + V_21 ) ;
V_5 = F_2 ( V_2 -> V_20 + V_22 ) ;
V_6 = F_2 ( V_2 -> V_20 + V_23 ) ;
V_7 = F_2 ( V_2 -> V_20 + V_24 ) ;
V_8 = F_2 ( V_2 -> V_20 + V_25 ) ;
V_9 = F_2 ( V_2 -> V_20 + V_26 ) ;
V_10 = F_2 ( V_2 -> V_20 + V_27 ) ;
V_11 = F_2 ( V_2 -> V_20 + V_28 ) ;
V_12 = F_2 ( V_2 -> V_20 + V_29 ) ;
V_13 = F_2 ( V_2 -> V_20 + V_30 ) ;
V_14 = F_2 ( V_2 -> V_20 + V_31 ) ;
V_15 = F_2 ( V_2 -> V_20 + V_32 ) ;
V_16 = F_2 ( V_2 -> V_20 + V_33 ) ;
V_17 = F_2 ( V_2 -> V_20 + V_34 ) ;
V_18 = F_2 ( V_2 -> V_20 + V_35 ) ;
V_19 = F_2 ( V_2 -> V_20 + V_2 -> V_36 ) ;
F_3 ( V_2 , V_37 , L_1 ,
V_3 , V_4 , V_5 , V_13 ) ;
F_3 ( V_2 , V_37 , L_2 ,
V_3 , V_7 , V_6 , V_8 ) ;
F_3 ( V_2 , V_37 , L_3
L_4 ,
V_3 , V_15 , V_18 , V_17 , V_16 ) ;
F_3 ( V_2 , V_37 , L_5
L_6 ,
V_3 , V_9 , V_10 , V_11 , V_12 ) ;
}
static void F_4 ( struct V_1 * V_2 , struct V_38 * V_39 ,
int V_40 )
{
snprintf ( V_2 -> V_41 , 300 ,
L_7 ,
V_2 -> V_42 , ( V_40 ? L_8 : L_9 ) ,
V_39 -> V_43 , V_39 -> V_44 , V_39 -> V_45 , V_39 -> V_46 ) ;
if ( V_39 -> V_47 ) {
snprintf ( V_2 -> V_48 , 300 ,
L_10 ,
V_2 -> V_49 , V_39 -> V_47 -> V_50 ,
V_39 -> V_47 -> V_51 ,
V_39 -> V_47 -> V_51 * V_39 -> V_47 -> V_50 ) ;
} else {
V_2 -> V_48 [ 0 ] = '\0' ;
}
}
static void F_5 ( struct V_1 * V_2 , struct V_38 * V_39 ,
int V_52 )
{
unsigned int V_53 = V_52 ? V_54 : V_37 ;
if ( ! V_39 )
return;
if ( V_39 -> error == 0 ) {
F_3 ( V_2 , V_53 , L_11 ,
V_2 -> V_41 , V_39 -> V_55 [ 0 ] ) ;
} else {
F_3 ( V_2 , V_53 , L_12 ,
V_39 -> error , V_2 -> V_41 , V_2 -> V_56 ) ;
}
if ( ! V_39 -> V_47 )
return;
if ( V_39 -> V_47 -> error == 0 ) {
F_3 ( V_2 , V_53 , L_13 , V_2 -> V_48 ) ;
} else {
F_3 ( V_2 , V_53 , L_14 ,
V_39 -> V_47 -> error , V_2 -> V_48 ,
F_2 ( V_2 -> V_20 + V_33 ) ) ;
}
}
static void F_5 ( struct V_1 * V_2 ,
struct V_38 * V_39 , int V_52 ) { }
static void F_4 ( struct V_1 * V_2 , struct V_38 * V_39 ,
int V_40 ) { }
static void F_1 ( struct V_1 * V_2 , char * V_3 ) { }
static inline bool F_6 ( struct V_1 * V_2 )
{
#ifdef F_7
return false ;
#else
return true ;
#endif
}
static inline T_1 F_8 ( struct V_1 * V_2 , T_1 V_19 )
{
T_1 V_57 ;
V_57 = F_2 ( V_2 -> V_20 + V_2 -> V_36 ) ;
V_57 |= V_19 ;
F_9 ( V_57 , V_2 -> V_20 + V_2 -> V_36 ) ;
return V_57 ;
}
static inline T_1 F_10 ( struct V_1 * V_2 , T_1 V_19 )
{
T_1 V_57 ;
V_57 = F_2 ( V_2 -> V_20 + V_2 -> V_36 ) ;
V_57 &= ~ V_19 ;
F_9 ( V_57 , V_2 -> V_20 + V_2 -> V_36 ) ;
return V_57 ;
}
static inline void F_11 ( struct V_1 * V_2 )
{
T_1 V_58 = F_2 ( V_2 -> V_20 + V_2 -> V_36 ) ;
V_58 &= V_59 ;
F_9 ( V_58 , V_2 -> V_20 + V_2 -> V_36 ) ;
}
static void F_12 ( struct V_1 * V_2 )
{
if ( V_2 -> V_60 ) {
if ( F_13 ( F_14 ( 8 ) ) == 0 ) {
F_15 ( L_15 , V_61 ) ;
F_16 ( V_2 -> V_62 ) ;
}
}
}
static inline int F_17 ( struct V_1 * V_2 ,
T_1 * V_63 , T_1 * * V_64 )
{
struct V_65 * V_66 ;
if ( V_2 -> V_67 == V_68 )
return - V_69 ;
if ( ( ! V_2 -> V_70 ) || ( ! V_2 -> V_70 -> V_47 ) )
return - V_69 ;
if ( V_2 -> V_71 >= V_2 -> V_70 -> V_47 -> V_72 ) {
F_3 ( V_2 , V_37 , L_16 ,
V_2 -> V_71 , V_2 -> V_70 -> V_47 -> V_72 ) ;
return - V_73 ;
}
V_66 = & V_2 -> V_70 -> V_47 -> V_66 [ V_2 -> V_71 ] ;
* V_63 = V_66 -> V_74 ;
* V_64 = F_18 ( V_66 ) ;
V_2 -> V_71 ++ ;
F_3 ( V_2 , V_75 , L_17 ,
V_2 -> V_71 , V_2 -> V_70 -> V_47 -> V_72 ) ;
return 0 ;
}
static inline T_1 F_19 ( struct V_1 * V_2 )
{
T_1 V_76 = F_2 ( V_2 -> V_20 + V_35 ) ;
V_76 &= V_77 ;
return V_76 ;
}
static inline T_1 F_20 ( struct V_1 * V_2 )
{
T_1 V_76 = F_2 ( V_2 -> V_20 + V_35 ) ;
V_76 &= V_77 ;
return 63 - V_76 ;
}
static void F_21 ( struct V_1 * V_2 , bool V_78 )
{
unsigned long V_45 ;
bool V_79 = false ;
F_22 ( V_45 ) ;
V_2 -> V_80 = V_78 ;
V_2 -> V_81 = false ;
V_79 = V_78 | V_2 -> V_60 ;
if ( V_2 -> V_82 != V_79 ) {
V_2 -> V_82 = V_79 ;
if ( V_79 )
F_23 ( V_2 -> V_83 ) ;
else
F_24 ( V_2 -> V_83 ) ;
}
F_25 ( V_45 ) ;
}
static void F_26 ( struct V_1 * V_2 , bool V_84 )
{
unsigned long V_45 ;
F_22 ( V_45 ) ;
V_2 -> V_81 = V_84 ;
if ( V_84 && V_2 -> V_82 ) {
V_2 -> V_82 = false ;
F_24 ( V_2 -> V_83 ) ;
}
F_25 ( V_45 ) ;
}
static void F_27 ( struct V_1 * V_2 )
{
int V_85 ;
T_1 V_86 ;
T_1 * V_87 ;
T_1 V_88 ;
void T_2 * V_89 ;
F_9 ( V_2 -> V_90 , V_2 -> V_20 + V_22 ) ;
V_89 = V_2 -> V_20 + V_2 -> V_91 ;
while ( ( V_86 = F_19 ( V_2 ) ) ) {
if ( ! V_2 -> V_92 ) {
V_85 = F_17 ( V_2 , & V_2 -> V_92 ,
& V_2 -> V_93 ) ;
if ( V_85 ) {
V_2 -> V_67 = V_68 ;
V_2 -> V_94 = V_95 ;
F_3 ( V_2 , V_96 , L_18
L_19 ) ;
return;
}
F_3 ( V_2 , V_96 ,
L_20 ,
V_2 -> V_92 , V_2 -> V_93 ) ;
}
F_3 ( V_2 , V_96 ,
L_21 ,
V_86 , V_2 -> V_92 ,
F_2 ( V_2 -> V_20 + V_33 ) ) ;
if ( V_86 >= V_2 -> V_92 )
V_86 = V_2 -> V_92 ;
else
V_86 -= V_86 & 3 ;
V_2 -> V_92 -= V_86 ;
V_2 -> V_97 += V_86 ;
V_88 = V_86 >> 2 ;
V_87 = V_2 -> V_93 ;
while ( V_88 -- )
* V_87 ++ = F_2 ( V_89 ) ;
V_2 -> V_93 = V_87 ;
if ( V_86 & 3 ) {
T_1 V_98 = V_86 & 3 ;
T_1 V_47 = F_2 ( V_89 ) ;
T_3 * V_99 = ( T_3 * ) V_2 -> V_93 ;
while ( V_98 -- ) {
* V_99 ++ = V_47 ;
V_47 >>= 8 ;
}
}
}
if ( ! V_2 -> V_92 ) {
V_85 = F_17 ( V_2 , & V_2 -> V_92 , & V_2 -> V_93 ) ;
if ( V_85 ) {
F_3 ( V_2 , V_96 ,
L_22 ) ;
V_2 -> V_67 = V_68 ;
V_2 -> V_94 = V_95 ;
return;
}
}
F_8 ( V_2 ,
V_100 | V_101 ) ;
}
static void F_28 ( struct V_1 * V_2 )
{
void T_2 * V_102 ;
int V_85 ;
T_1 V_86 ;
T_1 * V_87 ;
V_102 = V_2 -> V_20 + V_2 -> V_91 ;
while ( ( V_86 = F_20 ( V_2 ) ) > 3 ) {
if ( ! V_2 -> V_92 ) {
V_85 = F_17 ( V_2 , & V_2 -> V_92 ,
& V_2 -> V_93 ) ;
if ( V_85 ) {
F_3 ( V_2 , V_96 ,
L_23 ) ;
V_2 -> V_67 = V_68 ;
return;
}
F_3 ( V_2 , V_96 ,
L_24 ,
V_2 -> V_92 , V_2 -> V_93 ) ;
}
if ( V_86 >= V_2 -> V_92 )
V_86 = V_2 -> V_92 ;
else
V_86 -= V_86 & 3 ;
V_2 -> V_92 -= V_86 ;
V_2 -> V_97 += V_86 ;
V_86 = ( V_86 + 3 ) >> 2 ;
V_87 = V_2 -> V_93 ;
while ( V_86 -- )
F_9 ( * V_87 ++ , V_102 ) ;
V_2 -> V_93 = V_87 ;
}
F_8 ( V_2 , V_103 ) ;
}
static void F_29 ( unsigned long V_47 )
{
struct V_1 * V_2 = (struct V_1 * ) V_47 ;
F_26 ( V_2 , true ) ;
if ( V_2 -> V_67 == V_104 )
F_28 ( V_2 ) ;
if ( V_2 -> V_67 == V_105 )
F_27 ( V_2 ) ;
if ( V_2 -> V_94 == V_95 ) {
F_11 ( V_2 ) ;
if ( V_2 -> V_67 != V_68 ) {
F_3 ( V_2 , V_106 , L_25
L_26 ,
( V_2 -> V_67 == V_105 ) ? L_27 : L_28 ,
V_2 -> V_97 , V_2 -> V_92 ) ;
if ( V_2 -> V_70 -> V_47 )
V_2 -> V_70 -> V_47 -> error = - V_69 ;
}
F_21 ( V_2 , false ) ;
F_30 ( V_2 ) ;
} else
F_21 ( V_2 , true ) ;
}
static T_4 F_31 ( int V_83 , void * V_107 )
{
struct V_1 * V_2 = V_107 ;
struct V_38 * V_39 ;
T_1 V_108 , V_109 , V_110 , V_111 , V_112 ;
T_1 V_113 = 0 , V_114 ;
unsigned long V_115 ;
V_109 = F_2 ( V_2 -> V_20 + V_34 ) ;
V_112 = F_2 ( V_2 -> V_20 + V_2 -> V_36 ) ;
if ( V_109 & V_116 ) {
if ( V_112 & V_59 ) {
V_114 = V_116 ;
F_9 ( V_114 , V_2 -> V_20 + V_34 ) ;
F_16 ( V_2 -> V_62 ) ;
return V_117 ;
}
}
F_32 ( & V_2 -> V_118 , V_115 ) ;
V_108 = F_2 ( V_2 -> V_20 + V_25 ) ;
V_111 = F_2 ( V_2 -> V_20 + V_33 ) ;
V_110 = F_2 ( V_2 -> V_20 + V_35 ) ;
V_114 = 0 ;
if ( ( V_2 -> V_94 == V_119 ) ||
( V_2 -> V_94 == V_95 ) ) {
V_2 -> V_56 = L_29 ;
F_11 ( V_2 ) ;
goto V_120;
}
if ( ! V_2 -> V_70 ) {
V_2 -> V_56 = L_30 ;
F_11 ( V_2 ) ;
goto V_120;
}
V_39 = V_2 -> V_121 ? V_2 -> V_70 -> V_40 : V_2 -> V_70 -> V_39 ;
if ( ! V_39 ) {
V_2 -> V_56 = L_31 ;
F_11 ( V_2 ) ;
goto V_120;
}
if ( ! F_6 ( V_2 ) ) {
if ( ( V_2 -> V_67 == V_104 ) &&
( V_110 & V_122 ) ) {
F_10 ( V_2 , V_103 ) ;
F_33 ( & V_2 -> F_29 ) ;
V_2 -> V_56 = L_32 ;
}
if ( ( V_2 -> V_67 == V_105 ) &&
( V_110 & V_123 ) ) {
F_10 ( V_2 ,
V_100 |
V_101 ) ;
F_33 ( & V_2 -> F_29 ) ;
V_2 -> V_56 = L_33 ;
}
}
if ( V_108 & V_124 ) {
F_3 ( V_2 , V_106 , L_34 ) ;
V_39 -> error = - V_125 ;
V_2 -> V_56 = L_35 ;
goto V_126;
}
if ( V_108 & V_127 ) {
if ( V_2 -> V_94 == V_128 ) {
V_2 -> V_56 = L_36 ;
goto V_129;
}
V_113 |= V_127 ;
}
if ( V_108 & V_130 ) {
if ( V_39 -> V_45 & V_131 ) {
if ( V_2 -> V_70 -> V_39 -> V_45 & V_132 ) {
F_3 ( V_2 , V_133 ,
L_37 ) ;
} else {
}
}
V_113 |= V_130 ;
}
if ( V_108 & V_134 ) {
if ( V_2 -> V_94 == V_135 ) {
V_2 -> V_56 = L_38 ;
goto V_129;
}
if ( V_2 -> V_94 == V_136 )
V_2 -> V_94 = V_137 ;
V_113 |= V_134 ;
}
if ( ! V_39 -> V_47 )
goto V_138;
if ( V_2 -> V_139 ) {
if ( V_110 & V_140 ) {
F_3 ( V_2 , V_106 , L_39 ) ;
V_2 -> V_70 -> V_47 -> error = - V_141 ;
V_2 -> V_56 = L_40 ;
goto V_126;
}
} else {
if ( V_109 & V_142 ) {
F_3 ( V_2 , V_106 , L_39 ) ;
V_39 -> V_47 -> error = - V_141 ;
V_2 -> V_56 = L_41 ;
goto V_126;
}
}
if ( V_109 & V_143 ) {
F_3 ( V_2 , V_106 , L_42 ) ;
V_39 -> V_47 -> error = - V_141 ;
V_2 -> V_56 = L_43 ;
goto V_126;
}
if ( V_109 & V_144 ) {
F_3 ( V_2 , V_106 , L_44 ) ;
V_39 -> V_47 -> error = - V_141 ;
V_2 -> V_56 = L_45 ;
goto V_126;
}
if ( V_109 & V_145 ) {
F_3 ( V_2 , V_106 , L_46 ) ;
V_39 -> V_47 -> error = - V_125 ;
V_2 -> V_56 = L_47 ;
goto V_126;
}
if ( V_109 & V_146 ) {
if ( V_2 -> V_94 == V_137 ) {
V_2 -> V_56 = L_48 ;
goto V_129;
}
if ( V_2 -> V_94 == V_136 )
V_2 -> V_94 = V_135 ;
V_114 |= V_146 ;
}
V_138:
F_9 ( V_113 , V_2 -> V_20 + V_25 ) ;
F_9 ( V_114 , V_2 -> V_20 + V_34 ) ;
goto V_120;
V_126:
V_2 -> V_67 = V_68 ;
V_129:
V_2 -> V_94 = V_95 ;
F_11 ( V_2 ) ;
F_33 ( & V_2 -> F_29 ) ;
goto V_120;
V_120:
F_3 ( V_2 , V_133 ,
L_49 ,
V_108 , V_109 , V_110 , V_111 , V_2 -> V_56 ) ;
F_34 ( & V_2 -> V_118 , V_115 ) ;
return V_117 ;
}
static void F_35 ( void * V_44 )
{
struct V_1 * V_2 = V_44 ;
unsigned long V_115 ;
F_36 ( ! V_2 -> V_70 ) ;
F_36 ( ! V_2 -> V_70 -> V_47 ) ;
F_32 ( & V_2 -> V_118 , V_115 ) ;
F_3 ( V_2 , V_147 , L_50 ) ;
V_2 -> V_148 = 1 ;
V_2 -> V_94 = V_95 ;
F_33 ( & V_2 -> F_29 ) ;
F_34 ( & V_2 -> V_118 , V_115 ) ;
}
static void F_30 ( struct V_1 * V_2 )
{
struct V_149 * V_70 = V_2 -> V_70 ;
struct V_38 * V_39 ;
int V_150 = 0 ;
if ( V_2 -> V_94 != V_95 )
return;
if ( ! V_70 )
return;
V_39 = V_2 -> V_121 ? V_70 -> V_40 : V_70 -> V_39 ;
if ( V_39 -> V_47 && ( V_39 -> error == 0 ) &&
( V_39 -> V_47 -> error == 0 ) ) {
if ( F_6 ( V_2 ) && ( ! V_2 -> V_148 ) ) {
F_3 ( V_2 , V_147 , L_51 ,
V_2 -> V_148 ) ;
return;
}
}
V_39 -> V_55 [ 0 ] = F_2 ( V_2 -> V_20 + V_26 ) ;
V_39 -> V_55 [ 1 ] = F_2 ( V_2 -> V_20 + V_27 ) ;
V_39 -> V_55 [ 2 ] = F_2 ( V_2 -> V_20 + V_28 ) ;
V_39 -> V_55 [ 3 ] = F_2 ( V_2 -> V_20 + V_29 ) ;
F_9 ( V_2 -> V_90 , V_2 -> V_20 + V_22 ) ;
if ( V_39 -> error )
V_150 = 1 ;
if ( V_39 -> V_47 && V_39 -> V_47 -> error )
V_150 = 1 ;
F_5 ( V_2 , V_39 , V_150 ) ;
F_9 ( 0 , V_2 -> V_20 + V_23 ) ;
F_9 ( V_151 , V_2 -> V_20 + V_32 ) ;
F_9 ( 0 , V_2 -> V_20 + V_24 ) ;
F_11 ( V_2 ) ;
if ( V_39 -> V_47 && V_39 -> error )
V_39 -> V_47 -> error = V_39 -> error ;
if ( V_39 -> V_47 && V_39 -> V_47 -> V_40 && ( ! V_2 -> V_121 ) ) {
V_2 -> V_121 = 1 ;
F_37 ( V_2 -> V_62 ) ;
return;
}
if ( ! V_70 -> V_47 )
goto V_152;
if ( V_70 -> V_47 -> error == 0 ) {
V_70 -> V_47 -> V_153 =
( V_70 -> V_47 -> V_51 * V_70 -> V_47 -> V_50 ) ;
} else {
V_70 -> V_47 -> V_153 = 0 ;
}
if ( V_70 -> V_47 -> error != 0 ) {
if ( F_6 ( V_2 ) )
F_38 ( V_2 -> V_154 ) ;
if ( V_2 -> V_139 ) {
F_9 ( V_155 |
V_140 ,
V_2 -> V_20 + V_35 ) ;
} else {
T_1 V_156 ;
V_156 = F_2 ( V_2 -> V_20 + V_21 ) ;
V_156 |= V_157 ;
F_9 ( V_156 , V_2 -> V_20 + V_21 ) ;
}
}
V_152:
V_2 -> V_94 = V_119 ;
V_2 -> V_70 = NULL ;
F_12 ( V_2 ) ;
F_39 ( V_2 -> V_62 , V_70 ) ;
}
static void F_40 ( struct V_1 * V_2 ,
struct V_38 * V_39 )
{
T_1 V_158 , V_159 ;
V_159 = V_160 | V_161 |
V_162 | V_163 |
V_164 ;
F_8 ( V_2 , V_159 ) ;
if ( V_39 -> V_47 )
V_2 -> V_94 = V_136 ;
else if ( V_39 -> V_45 & V_165 )
V_2 -> V_94 = V_135 ;
else
V_2 -> V_94 = V_128 ;
F_9 ( V_39 -> V_44 , V_2 -> V_20 + V_23 ) ;
V_158 = V_39 -> V_43 & V_166 ;
V_158 |= V_167 | V_168 ;
if ( V_39 -> V_45 & V_165 )
V_158 |= V_169 ;
if ( V_39 -> V_45 & V_132 )
V_158 |= V_170 ;
F_9 ( V_158 , V_2 -> V_20 + V_24 ) ;
}
static int F_41 ( struct V_1 * V_2 , struct V_171 * V_47 )
{
T_1 V_172 , V_159 , V_173 = 3 ;
if ( ! V_47 ) {
F_9 ( 0 , V_2 -> V_20 + V_32 ) ;
return 0 ;
}
if ( ( V_47 -> V_50 & 3 ) != 0 ) {
if ( V_47 -> V_51 > 1 ) {
F_42 ( L_52 ,
V_61 , V_47 -> V_50 ) ;
return - V_69 ;
}
}
while ( F_2 ( V_2 -> V_20 + V_34 ) &
( V_174 | V_175 ) ) {
F_3 ( V_2 , V_106 ,
L_53 ) ;
F_9 ( V_151 , V_2 -> V_20 + V_32 ) ;
F_43 ( V_2 ) ;
if ( ( V_173 -- ) == 0 ) {
F_1 ( V_2 , L_54 ) ;
return - V_69 ;
}
}
V_172 = V_47 -> V_51 & V_176 ;
if ( F_6 ( V_2 ) )
V_172 |= V_177 ;
if ( V_2 -> V_178 == V_179 )
V_172 |= V_180 ;
V_172 |= V_181 ;
if ( V_47 -> V_45 & V_182 ) {
V_172 |= V_183 ;
V_172 |= V_184 ;
}
if ( V_47 -> V_45 & V_185 ) {
V_172 |= V_186 ;
V_172 |= V_187 ;
}
if ( V_2 -> V_139 ) {
V_172 |= V_188 ;
V_172 |= V_189 ;
}
F_9 ( V_172 , V_2 -> V_20 + V_32 ) ;
F_9 ( V_47 -> V_50 , V_2 -> V_20 + V_31 ) ;
V_159 = V_190 | V_191 |
V_192 | V_193 ;
F_8 ( V_2 , V_159 ) ;
if ( V_2 -> V_139 ) {
F_9 ( 0x007FFFFF , V_2 -> V_20 + V_30 ) ;
} else {
F_9 ( 0x0000FFFF , V_2 -> V_20 + V_30 ) ;
if ( V_47 -> V_45 & V_185 )
F_9 ( 0xFF , V_2 -> V_20 + V_22 ) ;
}
return 0 ;
}
static int F_44 ( struct V_1 * V_2 , struct V_171 * V_47 )
{
int V_194 = ( V_47 -> V_45 & V_182 ) ? 1 : 0 ;
F_36 ( ( V_47 -> V_45 & V_195 ) == V_195 ) ;
V_2 -> V_71 = 0 ;
V_2 -> V_92 = 0 ;
V_2 -> V_97 = 0 ;
V_2 -> V_67 = V_194 ? V_104 : V_105 ;
if ( V_194 ) {
F_28 ( V_2 ) ;
F_8 ( V_2 , V_103 ) ;
} else {
F_8 ( V_2 , V_100
| V_101 ) ;
}
return 0 ;
}
static int F_45 ( struct V_1 * V_2 , struct V_171 * V_47 )
{
int V_194 = V_47 -> V_45 & V_182 ;
struct V_196 * V_197 ;
struct V_198 V_199 = {
. V_200 = V_2 -> V_201 -> V_202 + V_2 -> V_91 ,
. V_203 = V_2 -> V_201 -> V_202 + V_2 -> V_91 ,
. V_204 = V_205 ,
. V_206 = V_205 ,
} ;
F_36 ( ( V_47 -> V_45 & V_195 ) == V_195 ) ;
F_9 ( V_2 -> V_90 , V_2 -> V_20 + V_22 ) ;
if ( ! V_194 )
V_199 . V_207 = V_208 ;
else
V_199 . V_207 = V_209 ;
F_46 ( F_47 ( V_2 -> V_62 ) , V_47 -> V_66 , V_47 -> V_72 ,
F_48 ( V_47 ) ) ;
F_49 ( V_2 -> V_154 , & V_199 ) ;
V_197 = F_50 ( V_2 -> V_154 , V_47 -> V_66 , V_47 -> V_72 ,
V_199 . V_207 ,
V_210 | V_211 ) ;
if ( ! V_197 )
goto V_212;
V_197 -> V_213 = F_35 ;
V_197 -> V_214 = V_2 ;
F_51 ( V_197 ) ;
F_52 ( V_2 -> V_154 ) ;
return 0 ;
V_212:
F_53 ( F_47 ( V_2 -> V_62 ) , V_47 -> V_66 , V_47 -> V_72 ,
F_48 ( V_47 ) ) ;
return - V_215 ;
}
static void F_37 ( struct V_216 * V_62 )
{
struct V_1 * V_2 = F_54 ( V_62 ) ;
struct V_149 * V_70 = V_2 -> V_70 ;
struct V_38 * V_39 = V_2 -> V_121 ? V_70 -> V_40 : V_70 -> V_39 ;
V_2 -> V_42 ++ ;
F_4 ( V_2 , V_39 , V_2 -> V_121 ) ;
F_9 ( 0xFFFFFFFF , V_2 -> V_20 + V_25 ) ;
F_9 ( 0xFFFFFFFF , V_2 -> V_20 + V_34 ) ;
F_9 ( 0xFFFFFFFF , V_2 -> V_20 + V_35 ) ;
if ( V_39 -> V_47 ) {
int V_85 = F_41 ( V_2 , V_39 -> V_47 ) ;
V_2 -> V_49 ++ ;
if ( V_85 ) {
F_3 ( V_2 , V_106 , L_55 , V_85 ) ;
V_39 -> error = V_85 ;
V_39 -> V_47 -> error = V_85 ;
F_39 ( V_62 , V_70 ) ;
return;
}
if ( F_6 ( V_2 ) )
V_85 = F_45 ( V_2 , V_39 -> V_47 ) ;
else
V_85 = F_44 ( V_2 , V_39 -> V_47 ) ;
if ( V_85 ) {
F_3 ( V_2 , V_106 , L_56 , V_85 ) ;
V_39 -> error = V_85 ;
V_39 -> V_47 -> error = V_85 ;
F_39 ( V_62 , V_70 ) ;
return;
}
}
F_40 ( V_2 , V_39 ) ;
F_21 ( V_2 , true ) ;
}
static void F_55 ( struct V_216 * V_62 , struct V_149 * V_70 )
{
struct V_1 * V_2 = F_54 ( V_62 ) ;
V_2 -> V_56 = L_57 ;
V_2 -> V_121 = 0 ;
V_2 -> V_70 = V_70 ;
if ( F_56 ( V_62 ) == 0 ) {
F_3 ( V_2 , V_106 , L_58 , V_61 ) ;
V_2 -> V_70 -> V_39 -> error = - V_217 ;
F_39 ( V_62 , V_70 ) ;
} else
F_37 ( V_62 ) ;
}
static void F_57 ( struct V_1 * V_2 , struct V_218 * V_219 )
{
T_1 V_220 ;
for ( V_220 = 0 ; V_220 < 255 ; V_220 ++ ) {
V_2 -> V_221 = V_2 -> V_222 / ( V_2 -> V_223 * ( V_220 + 1 ) ) ;
if ( V_2 -> V_221 <= V_219 -> clock )
break;
}
if ( V_220 > 255 )
V_220 = 255 ;
V_2 -> V_90 = V_220 ;
F_9 ( V_2 -> V_90 , V_2 -> V_20 + V_22 ) ;
if ( V_219 -> clock == 0 )
V_2 -> V_221 = 0 ;
}
static void F_58 ( struct V_216 * V_62 , struct V_218 * V_219 )
{
struct V_1 * V_2 = F_54 ( V_62 ) ;
T_1 V_156 ;
V_156 = F_2 ( V_2 -> V_20 + V_21 ) ;
switch ( V_219 -> V_224 ) {
case V_225 :
case V_226 :
if ( ! V_2 -> V_227 -> V_228 . V_229 )
F_59 ( F_14 ( 5 ) , 6 , F_60 ( 2 ) ,
V_230 ) ;
if ( V_2 -> V_231 -> V_232 )
V_2 -> V_231 -> V_232 ( V_219 -> V_224 , V_219 -> V_233 ) ;
if ( ! V_2 -> V_139 )
V_156 |= V_157 ;
break;
case V_234 :
default:
if ( ! V_2 -> V_227 -> V_228 . V_229 )
F_61 ( F_14 ( 5 ) , 0 ) ;
if ( V_2 -> V_139 )
V_156 |= V_235 ;
if ( V_2 -> V_231 -> V_232 )
V_2 -> V_231 -> V_232 ( V_219 -> V_224 , V_219 -> V_233 ) ;
break;
}
F_57 ( V_2 , V_219 ) ;
if ( V_219 -> clock )
V_156 |= V_236 ;
else
V_156 &= ~ V_236 ;
F_9 ( V_156 , V_2 -> V_20 + V_21 ) ;
if ( ( V_219 -> V_224 == V_225 ) ||
( V_219 -> V_224 == V_226 ) ) {
F_3 ( V_2 , V_237 , L_59 ,
V_2 -> V_221 / 1000 , V_219 -> clock / 1000 ) ;
} else {
F_3 ( V_2 , V_237 , L_60 ) ;
}
V_2 -> V_178 = V_219 -> V_178 ;
}
static void F_43 ( struct V_1 * V_2 )
{
T_1 V_4 = F_2 ( V_2 -> V_20 + V_21 ) ;
V_4 |= V_235 ;
F_9 ( V_4 , V_2 -> V_20 + V_21 ) ;
}
static void F_62 ( struct V_216 * V_62 , int V_79 )
{
struct V_1 * V_2 = F_54 ( V_62 ) ;
unsigned long V_45 ;
T_1 V_4 ;
F_22 ( V_45 ) ;
V_4 = F_2 ( V_2 -> V_20 + V_21 ) ;
V_2 -> V_60 = V_79 ;
if ( V_79 == V_2 -> V_60 )
goto V_238;
if ( V_79 ) {
V_4 |= V_239 ;
F_8 ( V_2 , V_59 ) ;
if ( ! V_2 -> V_82 && ! V_2 -> V_81 ) {
V_2 -> V_82 = true ;
F_23 ( V_2 -> V_83 ) ;
}
} else {
F_10 ( V_2 , V_59 ) ;
V_4 &= ~ V_239 ;
if ( ! V_2 -> V_80 && V_2 -> V_82 ) {
F_63 ( V_2 -> V_83 ) ;
V_2 -> V_82 = false ;
}
}
F_9 ( V_4 , V_2 -> V_20 + V_21 ) ;
V_238:
F_25 ( V_45 ) ;
F_12 ( V_2 ) ;
}
static int F_64 ( struct V_240 * V_241 ,
unsigned long V_242 , void * V_47 )
{
struct V_1 * V_2 ;
struct V_216 * V_62 ;
unsigned long V_243 ;
unsigned long V_45 ;
V_2 = F_65 ( V_241 , struct V_1 , V_244 ) ;
V_243 = F_66 ( V_2 -> V_245 ) ;
V_62 = V_2 -> V_62 ;
if ( ( V_242 == V_246 && V_243 > V_2 -> V_222 ) ||
( V_242 == V_247 && V_243 < V_2 -> V_222 ) ) {
F_32 ( & V_62 -> V_248 , V_45 ) ;
V_2 -> V_222 = V_243 ;
if ( V_62 -> V_219 . V_224 != V_234 &&
V_62 -> V_219 . clock != 0 )
F_57 ( V_2 , & V_62 -> V_219 ) ;
F_34 ( & V_62 -> V_248 , V_45 ) ;
}
return 0 ;
}
static inline int F_67 ( struct V_1 * V_2 )
{
V_2 -> V_244 . V_249 = F_64 ;
return F_68 ( & V_2 -> V_244 ,
V_250 ) ;
}
static inline void F_69 ( struct V_1 * V_2 )
{
F_70 ( & V_2 -> V_244 ,
V_250 ) ;
}
static inline int F_67 ( struct V_1 * V_2 )
{
return 0 ;
}
static inline void F_69 ( struct V_1 * V_2 )
{
}
static int F_71 ( struct V_251 * V_252 , void * V_253 )
{
struct V_1 * V_2 = V_252 -> V_254 ;
F_72 ( V_252 , L_61 , ( T_1 ) V_2 -> V_20 ) ;
F_72 ( V_252 , L_62 , V_2 -> V_222 ) ;
F_72 ( V_252 , L_63 , V_2 -> V_90 ) ;
F_72 ( V_252 , L_64 , V_2 -> V_139 ) ;
F_72 ( V_252 , L_65 , V_2 -> V_83 ) ;
F_72 ( V_252 , L_66 , V_2 -> V_80 ) ;
F_72 ( V_252 , L_67 , V_2 -> V_81 ) ;
F_72 ( V_252 , L_68 , V_2 -> V_82 ) ;
F_72 ( V_252 , L_69 , V_2 -> V_255 ) ;
F_72 ( V_252 , L_70 , F_6 ( V_2 ) ) ;
F_72 ( V_252 , L_71 , V_2 -> V_36 ) ;
F_72 ( V_252 , L_72 , V_2 -> V_91 ) ;
return 0 ;
}
static int F_73 ( struct V_256 * V_256 , struct V_257 * V_257 )
{
return F_74 ( V_257 , F_71 , V_256 -> V_258 ) ;
}
static int F_75 ( struct V_251 * V_252 , void * V_253 )
{
struct V_1 * V_2 = V_252 -> V_254 ;
struct V_259 * V_260 = V_261 ;
for (; V_260 -> V_262 ; V_260 ++ )
F_72 ( V_252 , L_73 , V_260 -> V_262 ,
F_2 ( V_2 -> V_20 + V_260 -> V_263 ) ) ;
F_72 ( V_252 , L_74 , F_2 ( V_2 -> V_20 + V_2 -> V_36 ) ) ;
return 0 ;
}
static int F_76 ( struct V_256 * V_256 , struct V_257 * V_257 )
{
return F_74 ( V_257 , F_75 , V_256 -> V_258 ) ;
}
static void F_77 ( struct V_1 * V_2 )
{
struct V_264 * V_228 = & V_2 -> V_227 -> V_228 ;
V_2 -> V_265 = F_78 ( F_79 ( V_228 ) , NULL ) ;
if ( F_80 ( V_2 -> V_265 ) ) {
F_81 ( V_228 , L_75 ) ;
return;
}
V_2 -> V_266 = F_82 ( L_76 , 0444 ,
V_2 -> V_265 , V_2 ,
& V_267 ) ;
if ( F_80 ( V_2 -> V_266 ) )
F_81 ( V_228 , L_77 ) ;
V_2 -> V_261 = F_82 ( L_78 , 0444 ,
V_2 -> V_265 , V_2 ,
& V_268 ) ;
if ( F_80 ( V_2 -> V_261 ) )
F_81 ( V_228 , L_79 ) ;
}
static void F_83 ( struct V_1 * V_2 )
{
F_84 ( V_2 -> V_261 ) ;
F_84 ( V_2 -> V_266 ) ;
F_84 ( V_2 -> V_265 ) ;
}
static inline void F_77 ( struct V_1 * V_2 ) { }
static inline void F_83 ( struct V_1 * V_2 ) { }
static int F_85 ( struct V_1 * V_2 )
{
struct V_269 * V_227 = V_2 -> V_227 ;
struct V_216 * V_62 = V_2 -> V_62 ;
struct V_270 * V_231 ;
int V_271 , V_272 ;
V_2 -> V_139 = F_86 ( V_227 ) -> V_273 ;
for ( V_271 = F_14 ( 5 ) ; V_271 <= F_14 ( 10 ) ; V_271 ++ ) {
V_272 = F_87 ( V_271 , F_79 ( & V_227 -> V_228 ) ) ;
if ( V_272 ) {
F_81 ( & V_227 -> V_228 , L_80 , V_271 ) ;
for ( V_271 -- ; V_271 >= F_14 ( 5 ) ; V_271 -- )
F_88 ( V_271 ) ;
return V_272 ;
}
}
if ( ! V_227 -> V_228 . V_274 )
V_227 -> V_228 . V_274 = & V_275 ;
V_231 = V_227 -> V_228 . V_274 ;
if ( V_231 -> V_276 )
V_62 -> V_277 |= V_278 ;
if ( V_231 -> V_279 )
V_62 -> V_280 |= V_281 ;
if ( V_231 -> V_282 )
V_62 -> V_277 |= V_283 ;
if ( V_231 -> V_284 )
V_62 -> V_277 |= V_285 ;
if ( F_89 ( V_231 -> V_286 ) ) {
V_272 = F_90 ( V_62 , V_231 -> V_286 , 0 ) ;
if ( V_272 ) {
F_81 ( & V_227 -> V_228 , L_81 ,
V_272 ) ;
return V_272 ;
}
}
if ( F_89 ( V_231 -> V_287 ) ) {
V_272 = F_91 ( V_62 , V_231 -> V_287 ) ;
if ( V_272 ) {
F_81 ( & V_227 -> V_228 , L_82 ,
V_272 ) ;
return V_272 ;
}
}
return 0 ;
}
static int F_92 ( struct V_1 * V_2 )
{
struct V_269 * V_227 = V_2 -> V_227 ;
struct V_270 * V_231 ;
struct V_216 * V_62 = V_2 -> V_62 ;
int V_272 ;
V_2 -> V_139 = ( int ) F_93 ( & V_227 -> V_228 ) ;
V_272 = F_94 ( V_62 ) ;
if ( V_272 )
return V_272 ;
V_231 = F_95 ( & V_227 -> V_228 , sizeof( * V_231 ) , V_288 ) ;
if ( ! V_231 )
return - V_215 ;
V_227 -> V_228 . V_274 = V_231 ;
return 0 ;
}
static int F_96 ( struct V_269 * V_227 )
{
struct V_1 * V_2 ;
struct V_216 * V_62 ;
int V_272 ;
int V_271 ;
V_62 = F_97 ( sizeof( struct V_1 ) , & V_227 -> V_228 ) ;
if ( ! V_62 ) {
V_272 = - V_215 ;
goto V_289;
}
V_2 = F_54 ( V_62 ) ;
V_2 -> V_62 = V_62 ;
V_2 -> V_227 = V_227 ;
if ( V_227 -> V_228 . V_229 )
V_272 = F_92 ( V_2 ) ;
else
V_272 = F_85 ( V_2 ) ;
if ( V_272 )
goto V_290;
V_2 -> V_231 = V_227 -> V_228 . V_274 ;
F_98 ( & V_2 -> V_118 ) ;
F_99 ( & V_2 -> F_29 , F_29 , ( unsigned long ) V_2 ) ;
if ( V_2 -> V_139 ) {
V_2 -> V_36 = V_291 ;
V_2 -> V_91 = V_292 ;
V_2 -> V_223 = 1 ;
} else {
V_2 -> V_36 = V_293 ;
V_2 -> V_91 = V_294 ;
V_2 -> V_223 = 2 ;
}
V_2 -> V_94 = V_119 ;
V_2 -> V_67 = V_68 ;
V_2 -> V_201 = F_100 ( V_227 , V_295 , 0 ) ;
if ( ! V_2 -> V_201 ) {
F_81 ( & V_227 -> V_228 ,
L_83 ) ;
V_272 = - V_296 ;
goto V_297;
}
V_2 -> V_201 = F_101 ( V_2 -> V_201 -> V_202 ,
F_102 ( V_2 -> V_201 ) , V_227 -> V_262 ) ;
if ( ! V_2 -> V_201 ) {
F_81 ( & V_227 -> V_228 , L_84 ) ;
V_272 = - V_296 ;
goto V_297;
}
V_2 -> V_20 = F_103 ( V_2 -> V_201 -> V_202 , F_102 ( V_2 -> V_201 ) ) ;
if ( ! V_2 -> V_20 ) {
F_81 ( & V_227 -> V_228 , L_85 ) ;
V_272 = - V_69 ;
goto V_298;
}
V_2 -> V_83 = F_104 ( V_227 , 0 ) ;
if ( V_2 -> V_83 == 0 ) {
F_81 ( & V_227 -> V_228 , L_86 ) ;
V_272 = - V_69 ;
goto V_299;
}
if ( F_105 ( V_2 -> V_83 , F_31 , 0 , V_300 , V_2 ) ) {
F_81 ( & V_227 -> V_228 , L_87 ) ;
V_272 = - V_296 ;
goto V_299;
}
F_24 ( V_2 -> V_83 ) ;
V_2 -> V_82 = false ;
if ( F_6 ( V_2 ) ) {
V_2 -> V_154 = F_106 ( & V_227 -> V_228 , L_88 ) ;
V_272 = F_107 ( V_2 -> V_154 ) ;
if ( V_272 ) {
F_81 ( & V_227 -> V_228 , L_89 ) ;
goto V_301;
}
}
V_2 -> V_245 = F_108 ( & V_227 -> V_228 , L_90 ) ;
if ( F_80 ( V_2 -> V_245 ) ) {
F_81 ( & V_227 -> V_228 , L_91 ) ;
V_272 = F_109 ( V_2 -> V_245 ) ;
V_2 -> V_245 = NULL ;
goto V_302;
}
V_272 = F_110 ( V_2 -> V_245 ) ;
if ( V_272 ) {
F_81 ( & V_227 -> V_228 , L_92 ) ;
goto V_303;
}
V_2 -> V_222 = F_66 ( V_2 -> V_245 ) ;
V_62 -> V_304 = & V_305 ;
V_62 -> V_306 = V_307 | V_308 ;
#ifdef F_111
V_62 -> V_280 = V_309 | V_310 ;
#else
V_62 -> V_280 = V_309 ;
#endif
V_62 -> V_311 = V_2 -> V_222 / ( V_2 -> V_223 * 256 ) ;
V_62 -> V_312 = V_2 -> V_222 / V_2 -> V_223 ;
if ( V_2 -> V_231 -> V_306 )
V_62 -> V_306 = V_2 -> V_231 -> V_306 ;
V_62 -> V_313 = 4095 ;
V_62 -> V_314 = 4095 ;
V_62 -> V_315 = 4095 * 512 ;
V_62 -> V_316 = V_62 -> V_315 ;
V_62 -> V_317 = 128 ;
F_3 ( V_2 , V_37 ,
L_93 ,
( V_2 -> V_139 ? L_94 : L_9 ) ,
V_2 -> V_20 , V_2 -> V_83 , V_2 -> V_255 , V_2 -> V_154 ) ;
V_272 = F_67 ( V_2 ) ;
if ( V_272 ) {
F_81 ( & V_227 -> V_228 , L_95 ) ;
goto V_318;
}
V_272 = F_112 ( V_62 ) ;
if ( V_272 ) {
F_81 ( & V_227 -> V_228 , L_96 ) ;
goto V_319;
}
F_77 ( V_2 ) ;
F_113 ( V_227 , V_62 ) ;
F_114 ( & V_227 -> V_228 , L_97 , F_115 ( V_62 ) ,
F_6 ( V_2 ) ? L_98 : L_99 ,
V_62 -> V_280 & V_310 ? L_100 : L_101 ) ;
return 0 ;
V_319:
F_69 ( V_2 ) ;
V_318:
F_116 ( V_2 -> V_245 ) ;
V_303:
F_117 ( V_2 -> V_245 ) ;
V_302:
if ( F_6 ( V_2 ) )
F_118 ( V_2 -> V_154 ) ;
V_301:
F_119 ( V_2 -> V_83 , V_2 ) ;
V_299:
F_120 ( V_2 -> V_20 ) ;
V_298:
F_121 ( V_2 -> V_201 -> V_202 , F_102 ( V_2 -> V_201 ) ) ;
V_297:
if ( ! V_227 -> V_228 . V_229 )
for ( V_271 = F_14 ( 5 ) ; V_271 <= F_14 ( 10 ) ; V_271 ++ )
F_88 ( V_271 ) ;
V_290:
F_122 ( V_62 ) ;
V_289:
return V_272 ;
}
static void F_123 ( struct V_269 * V_227 )
{
struct V_216 * V_62 = F_124 ( V_227 ) ;
struct V_1 * V_2 = F_54 ( V_62 ) ;
if ( V_2 -> V_255 >= 0 )
F_119 ( V_2 -> V_255 , V_2 ) ;
F_83 ( V_2 ) ;
F_69 ( V_2 ) ;
F_125 ( V_62 ) ;
F_116 ( V_2 -> V_245 ) ;
}
static int F_126 ( struct V_269 * V_227 )
{
struct V_216 * V_62 = F_124 ( V_227 ) ;
struct V_1 * V_2 = F_54 ( V_62 ) ;
int V_271 ;
F_123 ( V_227 ) ;
F_117 ( V_2 -> V_245 ) ;
F_127 ( & V_2 -> F_29 ) ;
if ( F_6 ( V_2 ) )
F_118 ( V_2 -> V_154 ) ;
F_119 ( V_2 -> V_83 , V_2 ) ;
if ( ! V_227 -> V_228 . V_229 )
for ( V_271 = F_14 ( 5 ) ; V_271 <= F_14 ( 10 ) ; V_271 ++ )
F_88 ( V_271 ) ;
F_120 ( V_2 -> V_20 ) ;
F_121 ( V_2 -> V_201 -> V_202 , F_102 ( V_2 -> V_201 ) ) ;
F_122 ( V_62 ) ;
return 0 ;
}
