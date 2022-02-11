static inline bool F_1 ( struct V_1 * V_2 )
{
T_1 V_3 = F_2 ( V_2 -> V_4 + V_5 ) ;
return V_3 & V_6 ;
}
static int F_3 ( struct V_1 * V_2 , T_1 V_7 )
{
unsigned long V_8 ;
T_1 V_9 ;
V_8 = 0 ;
while ( ! F_1 ( V_2 ) ) {
F_4 ( V_10 , V_10 * 2 ) ;
if ( ++ V_8 > V_11 )
return - V_12 ;
}
if ( V_8 )
F_5 ( V_2 -> V_13 , L_1 ,
V_8 , V_7 ) ;
V_9 = F_2 ( V_2 -> V_4 + V_5 ) ;
if ( ( ( V_9 & V_14 ) == V_15 ) &&
( V_7 == V_16 ) ) {
F_6 ( V_17 , V_2 -> V_4 + V_5 ) ;
F_6 ( V_17 , V_2 -> V_4 + V_5 ) ;
} else {
V_9 &= ~ V_14 ;
V_9 |= V_7 ;
F_6 ( V_9 , V_2 -> V_4 + V_5 ) ;
}
V_8 = 0 ;
while ( ! F_1 ( V_2 ) ) {
F_4 ( V_10 , V_10 * 2 ) ;
if ( ++ V_8 > V_11 )
return - V_12 ;
}
return 0 ;
}
static void F_7 ( struct V_1 * V_2 ,
struct V_18 * V_19 )
{
T_2 * V_20 = V_19 -> V_20 ;
T_1 V_21 , V_7 ;
int V_22 , V_23 , V_24 ;
V_24 = V_2 -> V_24 ;
while ( V_2 -> V_25 < V_19 -> V_26 ) {
V_7 = F_2 ( V_2 -> V_4 + V_27 ) ;
if ( 0 == ( V_7 & V_28 ) )
break;
V_21 = F_2 ( V_2 -> V_4 + V_29 ) ;
if ( ! V_20 ) {
V_2 -> V_25 += V_24 ;
continue;
}
for ( V_22 = 0 ; V_22 < V_24 ; V_22 ++ , V_2 -> V_25 ++ ) {
V_23 = V_30 ;
V_23 *= ( V_24 - V_22 - 1 ) ;
V_20 [ V_2 -> V_25 ] = V_21 >> V_23 ;
}
}
}
static void F_8 ( struct V_1 * V_2 ,
struct V_18 * V_19 )
{
const T_2 * V_31 = V_19 -> V_31 ;
T_1 V_21 , V_7 , V_32 ;
int V_22 , V_24 ;
V_24 = V_2 -> V_24 ;
while ( V_2 -> V_33 < V_19 -> V_26 ) {
V_7 = F_2 ( V_2 -> V_4 + V_27 ) ;
if ( V_7 & V_34 )
break;
V_21 = 0 ;
for ( V_22 = 0 ; V_22 < V_24 ; V_22 ++ , V_2 -> V_33 ++ ) {
if ( ! V_31 ) {
V_2 -> V_33 += V_24 ;
break;
}
V_32 = V_31 [ V_2 -> V_33 ] ;
V_21 |= V_32 << ( V_30 * ( 3 - V_22 ) ) ;
}
F_6 ( V_21 , V_2 -> V_4 + V_35 ) ;
}
}
static void F_9 ( void * V_32 )
{
struct V_1 * V_36 = V_32 ;
F_10 ( & V_36 -> V_37 ) ;
}
static int F_11 ( struct V_38 * V_39 , struct V_18 * V_19 ,
enum V_40 V_41 ,
T_3 V_42 )
{
struct V_1 * V_36 = F_12 ( V_39 ) ;
unsigned long V_43 = V_44 | V_45 ;
struct V_46 * V_47 ;
struct V_48 * V_49 ;
struct V_50 * V_51 ;
T_4 V_52 ;
unsigned int V_53 ;
if ( V_41 == V_54 ) {
V_51 = V_39 -> V_55 ;
V_53 = V_19 -> V_56 . V_53 ;
V_49 = V_19 -> V_56 . V_49 ;
} else {
V_51 = V_39 -> V_57 ;
V_53 = V_19 -> V_58 . V_53 ;
V_49 = V_19 -> V_58 . V_49 ;
}
V_47 = F_13 ( V_51 , V_49 , V_53 , V_41 , V_43 ) ;
if ( ! V_47 )
return - V_59 ;
V_47 -> V_42 = V_42 ;
V_47 -> V_60 = V_36 ;
V_52 = F_14 ( V_47 ) ;
return F_15 ( V_52 ) ;
}
static void F_16 ( struct V_38 * V_39 ,
struct V_18 * V_19 )
{
if ( V_19 -> V_31 )
F_17 ( V_39 -> V_55 ) ;
if ( V_19 -> V_20 )
F_17 ( V_39 -> V_57 ) ;
}
static int F_18 ( struct V_38 * V_39 , struct V_18 * V_19 )
{
T_3 V_61 = NULL , V_62 = NULL ;
int V_63 ;
if ( V_19 -> V_20 )
V_61 = F_9 ;
else if ( V_19 -> V_31 )
V_62 = F_9 ;
if ( V_19 -> V_20 ) {
V_63 = F_11 ( V_39 , V_19 , V_64 , V_61 ) ;
if ( V_63 )
return V_63 ;
F_19 ( V_39 -> V_57 ) ;
}
if ( V_19 -> V_31 ) {
V_63 = F_11 ( V_39 , V_19 , V_54 , V_62 ) ;
if ( V_63 )
return V_63 ;
F_19 ( V_39 -> V_55 ) ;
}
return 0 ;
}
static int F_20 ( struct V_38 * V_39 , struct V_18 * V_19 )
{
struct V_1 * V_36 = F_12 ( V_39 ) ;
int V_63 ;
V_63 = F_3 ( V_36 , V_65 ) ;
if ( V_63 ) {
F_21 ( V_36 -> V_13 , L_2 ) ;
return V_63 ;
}
V_63 = F_3 ( V_36 , V_15 ) ;
if ( V_63 ) {
F_21 ( V_36 -> V_13 , L_3 ) ;
return V_63 ;
}
F_8 ( V_36 , V_19 ) ;
return 0 ;
}
static T_5 F_22 ( int V_66 , void * V_67 )
{
struct V_1 * V_2 = V_67 ;
struct V_18 * V_19 ;
T_1 V_68 , V_69 , V_70 ;
unsigned long V_43 ;
int error = 0 ;
F_23 ( & V_2 -> V_71 , V_43 ) ;
V_19 = V_2 -> V_19 ;
V_2 -> V_19 = NULL ;
F_24 ( & V_2 -> V_71 , V_43 ) ;
V_69 = F_2 ( V_2 -> V_4 + V_72 ) ;
V_70 = F_2 ( V_2 -> V_4 + V_73 ) ;
V_68 = F_2 ( V_2 -> V_4 + V_27 ) ;
F_6 ( V_69 , V_2 -> V_4 + V_72 ) ;
F_6 ( V_70 , V_2 -> V_4 + V_73 ) ;
F_6 ( V_68 , V_2 -> V_4 + V_27 ) ;
if ( ! V_19 ) {
F_25 ( V_2 -> V_13 , L_4 ,
V_69 , V_70 , V_68 ) ;
return V_74 ;
}
if ( V_69 ) {
if ( V_69 & V_75 )
F_21 ( V_2 -> V_13 , L_5 ) ;
if ( V_69 & V_76 )
F_21 ( V_2 -> V_13 , L_6 ) ;
if ( V_69 & V_77 )
F_21 ( V_2 -> V_13 , L_7 ) ;
if ( V_69 & V_78 )
F_21 ( V_2 -> V_13 , L_8 ) ;
error = - V_12 ;
}
if ( V_70 ) {
if ( V_70 & V_79 )
F_21 ( V_2 -> V_13 , L_9 ) ;
if ( V_70 & V_80 )
F_21 ( V_2 -> V_13 , L_10 ) ;
error = - V_12 ;
}
if ( ! V_2 -> V_81 ) {
if ( V_68 & V_82 )
F_7 ( V_2 , V_19 ) ;
if ( V_68 & V_83 )
F_8 ( V_2 , V_19 ) ;
}
F_23 ( & V_2 -> V_71 , V_43 ) ;
V_2 -> error = error ;
V_2 -> V_19 = V_19 ;
F_24 ( & V_2 -> V_71 , V_43 ) ;
if ( V_2 -> V_25 == V_19 -> V_26 || error )
F_10 ( & V_2 -> V_37 ) ;
return V_74 ;
}
static T_1
F_26 ( struct V_38 * V_39 , struct V_18 * V_19 )
{
struct V_1 * V_36 = F_12 ( V_39 ) ;
T_1 V_84 ;
V_36 -> V_24 = 4 ;
if ( V_19 -> V_85 <= 8 )
V_36 -> V_24 = 1 ;
else if ( V_19 -> V_85 <= 16 )
V_36 -> V_24 = 2 ;
V_36 -> V_86 = V_19 -> V_26 / V_36 -> V_24 ;
if ( V_36 -> V_86 <= ( V_36 -> V_87 / sizeof( T_1 ) ) )
V_84 = V_88 ;
else
V_84 = V_89 ;
return V_84 ;
}
static int F_27 ( struct V_90 * V_91 , struct V_18 * V_19 )
{
struct V_1 * V_2 = F_12 ( V_91 -> V_39 ) ;
T_1 V_92 , V_93 , V_84 , V_94 ;
int V_63 , V_86 ;
if ( V_91 -> V_84 & V_95 && V_19 -> V_26 > V_2 -> V_87 ) {
F_28 ( V_2 -> V_13 , L_11 ,
V_19 -> V_26 , V_2 -> V_87 ) ;
return - V_12 ;
}
V_63 = F_29 ( V_2 -> V_96 , V_19 -> V_97 ) ;
if ( V_63 ) {
F_28 ( V_2 -> V_13 , L_12 ,
V_19 -> V_97 ) ;
return - V_12 ;
}
if ( F_3 ( V_2 , V_16 ) ) {
F_28 ( V_2 -> V_13 , L_13 ) ;
return - V_12 ;
}
V_84 = F_26 ( V_91 -> V_39 , V_19 ) ;
V_86 = V_2 -> V_86 ;
if ( V_84 == V_88 ) {
F_6 ( V_86 , V_2 -> V_4 + V_98 ) ;
F_6 ( V_86 , V_2 -> V_4 + V_99 ) ;
F_6 ( 0 , V_2 -> V_4 + V_100 ) ;
F_6 ( 0 , V_2 -> V_4 + V_101 ) ;
} else if ( ! V_2 -> V_81 ) {
F_6 ( V_86 , V_2 -> V_4 + V_100 ) ;
F_6 ( V_86 , V_2 -> V_4 + V_101 ) ;
F_6 ( 0 , V_2 -> V_4 + V_98 ) ;
F_6 ( 0 , V_2 -> V_4 + V_99 ) ;
} else {
V_84 = V_102 ;
F_6 ( 0 , V_2 -> V_4 + V_98 ) ;
F_6 ( 0 , V_2 -> V_4 + V_99 ) ;
if ( ! V_2 -> V_103 ) {
void T_6 * V_104 ;
V_104 = V_2 -> V_4 + V_100 ;
if ( V_19 -> V_31 )
F_6 ( 0 , V_104 ) ;
else
F_6 ( V_86 , V_104 ) ;
F_6 ( 0 , V_2 -> V_4 + V_101 ) ;
}
}
V_93 = F_2 ( V_2 -> V_4 + V_105 ) ;
V_93 &= ~ ( V_106 | V_107 ) ;
if ( ! V_2 -> V_81 )
V_93 &= ~ ( V_108 | V_109 ) ;
else
V_93 |= V_108 | V_109 ;
V_93 |= ( V_84 << V_110 ) ;
V_93 |= ( V_84 << V_111 ) ;
F_6 ( V_93 , V_2 -> V_4 + V_105 ) ;
V_94 = F_2 ( V_2 -> V_4 + V_112 ) ;
if ( V_91 -> V_84 & V_113 )
V_94 |= V_114 ;
else
V_94 &= ~ V_114 ;
F_6 ( V_94 , V_2 -> V_4 + V_112 ) ;
V_92 = F_2 ( V_2 -> V_4 + V_115 ) ;
if ( V_91 -> V_84 & V_95 )
V_92 |= V_116 ;
else
V_92 &= ~ V_116 ;
if ( V_91 -> V_84 & V_117 )
V_92 &= ~ V_118 ;
else
V_92 |= V_118 ;
if ( ( V_19 -> V_97 >= V_119 ) && ! ( V_91 -> V_84 & V_95 ) )
V_92 |= V_120 ;
else
V_92 &= ~ V_120 ;
F_6 ( V_92 , V_2 -> V_4 + V_115 ) ;
V_92 = F_2 ( V_2 -> V_4 + V_121 ) ;
V_92 &= ~ ( V_122 | V_123 | V_124 ) ;
V_92 |= V_19 -> V_85 - 1 ;
V_92 |= V_125 ;
if ( V_2 -> V_81 ) {
if ( ! V_19 -> V_31 )
V_92 |= V_123 ;
if ( ! V_19 -> V_20 )
V_92 |= V_122 ;
}
F_6 ( V_92 , V_2 -> V_4 + V_121 ) ;
if ( ! V_2 -> V_103 ) {
T_1 V_126 = 0 ;
if ( V_84 == V_102 )
V_126 = V_82 | V_83 ;
F_6 ( V_126 , V_2 -> V_4 + V_127 ) ;
}
return 0 ;
}
static int F_30 ( struct V_38 * V_39 ,
struct V_90 * V_91 ,
struct V_18 * V_19 )
{
struct V_1 * V_2 = F_12 ( V_39 ) ;
unsigned long V_128 , V_43 ;
int V_63 = - V_12 ;
V_63 = F_27 ( V_91 , V_19 ) ;
if ( V_63 )
return V_63 ;
V_128 = F_31 ( V_19 -> V_97 , V_129 ) ;
V_128 = F_31 ( V_19 -> V_26 * 8 , V_128 ) ;
V_128 = 100 * F_32 ( V_128 ) ;
F_33 ( & V_2 -> V_37 ) ;
F_23 ( & V_2 -> V_71 , V_43 ) ;
V_2 -> V_19 = V_19 ;
V_2 -> error = 0 ;
V_2 -> V_25 = 0 ;
V_2 -> V_33 = 0 ;
F_24 ( & V_2 -> V_71 , V_43 ) ;
if ( V_2 -> V_81 )
V_63 = F_18 ( V_39 , V_19 ) ;
else
V_63 = F_20 ( V_39 , V_19 ) ;
if ( V_63 )
goto exit;
if ( F_3 ( V_2 , V_65 ) ) {
F_21 ( V_2 -> V_13 , L_14 ) ;
goto exit;
}
if ( ! F_34 ( & V_2 -> V_37 , V_128 ) )
V_63 = - V_130 ;
exit:
F_3 ( V_2 , V_16 ) ;
F_23 ( & V_2 -> V_71 , V_43 ) ;
V_2 -> V_19 = NULL ;
if ( ! V_63 )
V_63 = V_2 -> error ;
F_24 ( & V_2 -> V_71 , V_43 ) ;
if ( V_63 && V_2 -> V_81 )
F_16 ( V_39 , V_19 ) ;
return V_63 ;
}
static bool F_35 ( struct V_38 * V_39 , struct V_90 * V_91 ,
struct V_18 * V_19 )
{
struct V_1 * V_36 = F_12 ( V_39 ) ;
T_7 V_131 = F_36 () ;
T_1 V_84 ;
V_36 -> V_81 = 0 ;
if ( V_19 -> V_20 && ( V_19 -> V_26 % V_36 -> V_132 ||
F_37 ( V_39 -> V_57 ) ||
! F_38 ( ( T_7 ) V_19 -> V_20 , V_131 ) ) )
return false ;
if ( V_19 -> V_31 && ( V_19 -> V_26 % V_36 -> V_133 ||
F_37 ( V_39 -> V_55 ) ||
! F_38 ( ( T_7 ) V_19 -> V_31 , V_131 ) ) )
return false ;
V_84 = F_26 ( V_39 , V_19 ) ;
if ( V_84 == V_88 )
return false ;
V_36 -> V_81 = 1 ;
return true ;
}
static void F_39 ( struct V_38 * V_39 )
{
if ( ! F_37 ( V_39 -> V_57 ) )
F_40 ( V_39 -> V_57 ) ;
if ( ! F_37 ( V_39 -> V_55 ) )
F_40 ( V_39 -> V_55 ) ;
}
static int F_41 ( struct V_38 * V_39 , T_8 V_4 )
{
struct V_1 * V_91 = F_12 ( V_39 ) ;
struct V_134 * V_135 = & V_91 -> V_135 ,
* V_136 = & V_91 -> V_136 ;
struct V_137 * V_13 = V_91 -> V_13 ;
int V_63 ;
V_39 -> V_57 = F_42 ( V_13 , L_15 ) ;
if ( F_43 ( V_39 -> V_57 ) )
return F_44 ( V_39 -> V_57 ) ;
V_39 -> V_55 = F_42 ( V_13 , L_16 ) ;
if ( F_43 ( V_39 -> V_55 ) ) {
V_63 = F_44 ( V_39 -> V_55 ) ;
goto V_138;
}
V_135 -> V_139 = V_64 ;
V_135 -> V_140 = 1 ;
V_135 -> V_141 = V_4 + V_29 ;
V_135 -> V_142 = V_91 -> V_132 ;
V_136 -> V_139 = V_54 ;
V_136 -> V_140 = 1 ;
V_136 -> V_143 = V_4 + V_35 ;
V_136 -> V_144 = V_91 -> V_133 ;
V_63 = F_45 ( V_39 -> V_57 , V_135 ) ;
if ( V_63 ) {
F_28 ( V_13 , L_17 ) ;
goto V_145;
}
V_63 = F_45 ( V_39 -> V_55 , V_136 ) ;
if ( V_63 ) {
F_28 ( V_13 , L_18 ) ;
goto V_145;
}
return 0 ;
V_145:
F_40 ( V_39 -> V_55 ) ;
V_138:
F_40 ( V_39 -> V_57 ) ;
return V_63 ;
}
static int F_46 ( struct V_146 * V_147 )
{
struct V_38 * V_39 ;
struct V_148 * V_149 , * V_96 ;
struct V_1 * V_2 ;
struct V_150 * V_151 ;
struct V_137 * V_13 ;
void T_6 * V_4 ;
T_1 V_152 , V_93 , V_153 ;
int V_63 , V_66 , V_154 ;
V_13 = & V_147 -> V_13 ;
V_151 = F_47 ( V_147 , V_155 , 0 ) ;
V_4 = F_48 ( V_13 , V_151 ) ;
if ( F_43 ( V_4 ) )
return F_44 ( V_4 ) ;
V_66 = F_49 ( V_147 , 0 ) ;
if ( V_66 < 0 )
return V_66 ;
V_96 = F_50 ( V_13 , L_19 ) ;
if ( F_43 ( V_96 ) )
return F_44 ( V_96 ) ;
V_149 = F_50 ( V_13 , L_20 ) ;
if ( F_43 ( V_149 ) )
return F_44 ( V_149 ) ;
if ( F_51 ( V_13 -> V_156 , L_21 , & V_152 ) )
V_152 = V_157 ;
if ( ! V_152 || V_152 > V_157 ) {
F_28 ( V_13 , L_22 , V_152 ) ;
return - V_158 ;
}
V_63 = F_52 ( V_96 ) ;
if ( V_63 ) {
F_28 ( V_13 , L_23 ) ;
return V_63 ;
}
V_63 = F_52 ( V_149 ) ;
if ( V_63 ) {
F_53 ( V_96 ) ;
F_28 ( V_13 , L_24 ) ;
return V_63 ;
}
V_39 = F_54 ( V_13 , sizeof( struct V_1 ) ) ;
if ( ! V_39 ) {
F_53 ( V_96 ) ;
F_53 ( V_149 ) ;
F_28 ( V_13 , L_25 ) ;
return - V_159 ;
}
if ( F_51 ( V_13 -> V_156 , L_26 , & V_153 ) ||
V_153 > V_160 )
V_39 -> V_161 = V_160 ;
else
V_39 -> V_161 = V_153 ;
V_39 -> V_162 = V_147 -> V_163 ;
V_39 -> V_164 = V_113 | V_117 | V_165 | V_95 ;
V_39 -> V_166 = F_55 ( 4 , 32 ) ;
V_39 -> V_167 = V_152 ;
V_39 -> V_168 = F_30 ;
V_39 -> V_13 . V_156 = V_147 -> V_13 . V_156 ;
V_39 -> V_169 = true ;
V_39 -> V_170 = F_36 () ;
V_39 -> V_171 = V_172 ;
F_56 ( V_147 , V_39 ) ;
V_2 = F_12 ( V_39 ) ;
V_2 -> V_13 = V_13 ;
V_2 -> V_4 = V_4 ;
V_2 -> V_149 = V_149 ;
V_2 -> V_96 = V_96 ;
V_2 -> V_66 = V_66 ;
V_63 = F_41 ( V_39 , V_151 -> V_173 ) ;
if ( V_63 == - V_174 )
goto error;
else if ( ! V_63 )
V_39 -> V_175 = F_35 ;
if ( F_57 ( V_13 -> V_156 , L_27 ) )
V_2 -> V_103 = 1 ;
F_58 ( & V_2 -> V_71 ) ;
F_59 ( & V_2 -> V_37 ) ;
V_93 = F_2 ( V_4 + V_105 ) ;
V_154 = F_60 ( V_93 ) ;
if ( V_154 )
V_2 -> V_133 = V_154 * 16 ;
else
V_2 -> V_133 = 4 ;
V_154 = F_61 ( V_93 ) ;
if ( V_154 )
V_2 -> V_132 = V_154 * 16 ;
else
V_2 -> V_132 = 4 ;
V_154 = F_62 ( V_93 ) ;
V_2 -> V_176 = V_2 -> V_133 * ( 2 << V_154 ) ;
V_154 = F_63 ( V_93 ) ;
V_2 -> V_87 = V_2 -> V_132 * ( 2 << V_154 ) ;
F_64 ( V_13 , L_28 ,
V_2 -> V_132 , V_2 -> V_87 ,
V_2 -> V_133 , V_2 -> V_176 ) ;
F_6 ( 1 , V_4 + V_177 ) ;
V_63 = F_3 ( V_2 , V_16 ) ;
if ( V_63 ) {
F_28 ( V_13 , L_13 ) ;
goto V_178;
}
F_6 ( 0 , V_4 + V_27 ) ;
F_6 ( 0 , V_4 + V_105 ) ;
if ( ! V_2 -> V_103 )
F_6 ( 0 , V_4 + V_127 ) ;
F_6 ( V_80 | V_79 ,
V_4 + V_179 ) ;
if ( V_2 -> V_103 )
F_6 ( V_75 |
V_76 | V_77 ,
V_4 + V_180 ) ;
F_6 ( 0 , V_4 + V_115 ) ;
F_6 ( V_181 , V_4 + V_112 ) ;
V_63 = F_65 ( V_13 , V_66 , F_22 ,
V_182 , V_147 -> V_183 , V_2 ) ;
if ( V_63 )
goto V_178;
F_66 ( V_13 , V_129 ) ;
F_67 ( V_13 ) ;
F_68 ( V_13 ) ;
F_69 ( V_13 ) ;
V_63 = F_70 ( V_13 , V_39 ) ;
if ( V_63 )
goto V_184;
return 0 ;
V_184:
F_71 ( & V_147 -> V_13 ) ;
V_178:
F_39 ( V_39 ) ;
error:
F_53 ( V_96 ) ;
F_53 ( V_149 ) ;
F_72 ( V_39 ) ;
return V_63 ;
}
static int F_73 ( struct V_137 * V_137 )
{
struct V_38 * V_39 = F_74 ( V_137 ) ;
struct V_1 * V_2 = F_12 ( V_39 ) ;
T_1 V_92 ;
V_92 = F_75 ( V_2 -> V_4 + V_121 ) ;
V_92 |= V_185 ;
F_6 ( V_92 , V_2 -> V_4 + V_121 ) ;
F_53 ( V_2 -> V_96 ) ;
F_53 ( V_2 -> V_149 ) ;
return 0 ;
}
static int F_76 ( struct V_137 * V_137 )
{
struct V_38 * V_39 = F_74 ( V_137 ) ;
struct V_1 * V_2 = F_12 ( V_39 ) ;
T_1 V_92 ;
int V_63 ;
V_63 = F_52 ( V_2 -> V_149 ) ;
if ( V_63 )
return V_63 ;
V_63 = F_52 ( V_2 -> V_96 ) ;
if ( V_63 )
return V_63 ;
V_92 = F_2 ( V_2 -> V_4 + V_121 ) ;
V_92 &= ~ V_185 ;
F_6 ( V_92 , V_2 -> V_4 + V_121 ) ;
return 0 ;
}
static int F_77 ( struct V_137 * V_137 )
{
struct V_38 * V_39 = F_74 ( V_137 ) ;
struct V_1 * V_2 = F_12 ( V_39 ) ;
int V_63 ;
V_63 = F_78 ( V_39 ) ;
if ( V_63 )
return V_63 ;
V_63 = F_3 ( V_2 , V_16 ) ;
if ( V_63 )
return V_63 ;
F_53 ( V_2 -> V_96 ) ;
F_53 ( V_2 -> V_149 ) ;
return 0 ;
}
static int F_79 ( struct V_137 * V_137 )
{
struct V_38 * V_39 = F_74 ( V_137 ) ;
struct V_1 * V_2 = F_12 ( V_39 ) ;
int V_63 ;
V_63 = F_52 ( V_2 -> V_149 ) ;
if ( V_63 )
return V_63 ;
V_63 = F_52 ( V_2 -> V_96 ) ;
if ( V_63 )
return V_63 ;
V_63 = F_3 ( V_2 , V_16 ) ;
if ( V_63 )
return V_63 ;
return F_80 ( V_39 ) ;
}
static int F_81 ( struct V_146 * V_147 )
{
struct V_38 * V_39 = F_74 ( & V_147 -> V_13 ) ;
struct V_1 * V_2 = F_12 ( V_39 ) ;
int V_63 ;
V_63 = F_82 ( & V_147 -> V_13 ) ;
if ( V_63 < 0 )
return V_63 ;
V_63 = F_3 ( V_2 , V_16 ) ;
if ( V_63 )
return V_63 ;
F_39 ( V_39 ) ;
F_53 ( V_2 -> V_96 ) ;
F_53 ( V_2 -> V_149 ) ;
F_83 ( & V_147 -> V_13 ) ;
F_71 ( & V_147 -> V_13 ) ;
F_72 ( V_39 ) ;
return 0 ;
}
