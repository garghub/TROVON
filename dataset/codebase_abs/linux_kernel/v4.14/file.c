static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = F_2 ( V_2 -> V_4 -> V_5 ) ;
int V_6 ;
F_3 ( & F_4 ( V_3 ) -> V_7 ) ;
V_6 = F_5 ( V_2 ) ;
F_6 ( & F_4 ( V_3 ) -> V_7 ) ;
return V_6 ;
}
static int F_7 ( struct V_1 * V_2 )
{
struct V_8 * V_8 = V_2 -> V_8 ;
struct V_3 * V_3 = F_2 ( V_2 -> V_4 -> V_5 ) ;
struct V_9 * V_10 = F_8 ( V_3 ) ;
struct V_11 V_12 ;
int V_6 ;
F_9 ( V_3 -> V_13 ) ;
F_10 ( V_10 , F_11 ( V_3 ) ) ;
F_12 ( V_10 ) ;
F_13 ( & V_12 , V_3 , NULL , NULL , 0 ) ;
V_6 = F_14 ( & V_12 , V_8 -> V_14 ) ;
if ( V_6 ) {
F_15 ( V_10 ) ;
goto V_15;
}
F_16 ( & V_12 ) ;
F_15 ( V_10 ) ;
F_17 ( V_10 , V_12 . V_16 ) ;
F_18 ( V_2 -> V_4 -> V_5 ) ;
F_3 ( & F_4 ( V_3 ) -> V_7 ) ;
F_19 ( V_8 ) ;
if ( F_20 ( V_8 -> V_17 != V_3 -> V_18 ||
F_21 ( V_8 ) > F_22 ( V_3 ) ||
! F_23 ( V_8 ) ) ) {
F_24 ( V_8 ) ;
V_6 = - V_19 ;
goto V_20;
}
if ( F_25 ( V_8 ) )
goto V_21;
if ( ( ( V_22 ) ( V_8 -> V_14 + 1 ) << V_23 ) >
F_22 ( V_3 ) ) {
unsigned V_24 ;
V_24 = F_22 ( V_3 ) & ~ V_25 ;
F_26 ( V_8 , V_24 , V_26 ) ;
}
F_27 ( V_8 ) ;
if ( ! F_23 ( V_8 ) )
F_28 ( V_8 ) ;
F_29 ( V_10 , V_27 , V_28 ) ;
F_30 ( V_8 , V_29 ) ;
V_21:
F_31 ( V_8 , V_29 , false ) ;
if ( F_32 ( V_3 ) )
F_33 ( V_10 , V_12 . V_30 ) ;
V_20:
F_6 ( & F_4 ( V_3 ) -> V_7 ) ;
V_15:
F_34 ( V_3 -> V_13 ) ;
F_35 ( V_10 , V_31 ) ;
return F_36 ( V_6 ) ;
}
static int F_37 ( struct V_3 * V_3 , T_1 * V_32 )
{
struct V_33 * V_33 ;
V_3 = F_38 ( V_3 ) ;
V_33 = F_39 ( V_3 ) ;
F_40 ( V_3 ) ;
if ( ! V_33 )
return 0 ;
* V_32 = F_41 ( V_33 ) ;
F_42 ( V_33 ) ;
return 1 ;
}
static inline bool F_43 ( struct V_3 * V_3 )
{
struct V_9 * V_10 = F_8 ( V_3 ) ;
bool V_34 = false ;
if ( ! F_44 ( V_3 -> V_35 ) || V_3 -> V_36 != 1 )
V_34 = true ;
else if ( F_45 ( V_10 , V_37 ) )
V_34 = true ;
else if ( F_46 ( V_3 ) )
V_34 = true ;
else if ( ! F_47 ( V_10 ) )
V_34 = true ;
else if ( ! F_48 ( V_10 , F_4 ( V_3 ) -> V_38 ) )
V_34 = true ;
else if ( F_49 ( V_10 , V_39 ) )
V_34 = true ;
else if ( V_10 -> V_40 == 2 )
V_34 = true ;
return V_34 ;
}
static bool F_50 ( struct V_9 * V_10 , T_1 V_41 )
{
struct V_8 * V_42 = F_51 ( F_52 ( V_10 ) , V_41 ) ;
bool V_43 = false ;
if ( ( V_42 && F_53 ( V_42 ) ) || F_54 ( V_10 , V_41 ) )
V_43 = true ;
F_55 ( V_42 , 0 ) ;
return V_43 ;
}
static void F_56 ( struct V_3 * V_3 )
{
struct V_44 * V_45 = F_4 ( V_3 ) ;
T_1 V_32 ;
F_57 ( & V_45 -> V_46 ) ;
if ( F_46 ( V_3 ) && V_3 -> V_36 == 1 &&
F_37 ( V_3 , & V_32 ) ) {
F_58 ( V_3 , V_32 ) ;
F_59 ( V_3 ) ;
}
F_60 ( & V_45 -> V_46 ) ;
}
static int F_61 ( struct V_47 * V_47 , V_22 V_48 , V_22 V_49 ,
int V_50 , bool V_51 )
{
struct V_3 * V_3 = V_47 -> V_52 -> V_53 ;
struct V_9 * V_10 = F_8 ( V_3 ) ;
T_1 V_41 = V_3 -> V_54 ;
int V_43 = 0 ;
bool V_34 = false ;
struct V_55 V_56 = {
. V_57 = V_58 ,
. V_59 = V_60 ,
. V_61 = 0 ,
} ;
if ( F_20 ( F_62 ( V_3 -> V_13 ) ) )
return 0 ;
F_63 ( V_3 ) ;
if ( V_50 || F_64 ( V_3 ) <= F_65 ( V_10 ) -> V_62 )
F_66 ( V_3 , V_63 ) ;
V_43 = F_67 ( V_47 , V_48 , V_49 ) ;
F_68 ( V_3 , V_63 ) ;
if ( V_43 ) {
F_69 ( V_3 , V_34 , V_50 , V_43 ) ;
return V_43 ;
}
if ( ! F_70 ( V_3 , V_50 ) ) {
F_71 ( V_3 , NULL ) ;
goto V_64;
}
if ( ! F_72 ( V_3 , V_65 ) &&
! F_73 ( V_10 , V_41 , V_66 ) ) {
if ( F_50 ( V_10 , V_41 ) )
goto V_64;
if ( F_72 ( V_3 , V_67 ) ||
F_73 ( V_10 , V_41 , V_68 ) )
goto V_69;
goto V_15;
}
V_64:
F_3 ( & F_4 ( V_3 ) -> V_46 ) ;
V_34 = F_43 ( V_3 ) ;
F_6 ( & F_4 ( V_3 ) -> V_46 ) ;
if ( V_34 ) {
V_43 = F_74 ( V_3 -> V_13 , 1 ) ;
F_56 ( V_3 ) ;
F_68 ( V_3 , V_65 ) ;
F_68 ( V_3 , V_67 ) ;
goto V_15;
}
V_70:
V_43 = F_75 ( V_10 , V_3 , & V_56 , V_51 ) ;
if ( V_43 )
goto V_15;
if ( F_20 ( F_76 ( V_10 ) ) ) {
V_43 = - V_71 ;
goto V_15;
}
if ( F_54 ( V_10 , V_41 ) ) {
F_77 ( V_3 , true ) ;
F_71 ( V_3 , NULL ) ;
goto V_70;
}
if ( ! V_51 ) {
V_43 = F_78 ( V_10 , V_41 ) ;
if ( V_43 )
goto V_15;
}
F_79 ( V_10 , V_41 , V_66 ) ;
F_68 ( V_3 , V_65 ) ;
V_69:
F_79 ( V_10 , V_41 , V_68 ) ;
F_68 ( V_3 , V_67 ) ;
if ( ! V_51 )
V_43 = F_80 ( V_10 ) ;
F_35 ( V_10 , V_31 ) ;
V_15:
F_69 ( V_3 , V_34 , V_50 , V_43 ) ;
F_81 ( NULL , 1 ) ;
return V_43 ;
}
int F_82 ( struct V_47 * V_47 , V_22 V_48 , V_22 V_49 , int V_50 )
{
return F_61 ( V_47 , V_48 , V_49 , V_50 , false ) ;
}
static T_2 F_83 ( struct V_72 * V_17 ,
T_2 V_73 , int V_74 )
{
struct V_75 V_76 ;
int V_77 ;
if ( V_74 != V_78 )
return 0 ;
F_84 ( & V_76 , 0 ) ;
V_77 = F_85 ( & V_76 , V_17 , & V_73 ,
V_79 , 1 ) ;
V_73 = V_77 ? V_76 . V_80 [ 0 ] -> V_14 : V_81 ;
F_86 ( & V_76 ) ;
return V_73 ;
}
static bool F_87 ( T_3 V_82 , T_2 V_83 , T_2 V_73 ,
int V_74 )
{
switch ( V_74 ) {
case V_78 :
if ( ( V_82 == V_84 && V_83 == V_73 ) ||
( V_82 != V_84 && V_82 != V_85 ) )
return true ;
break;
case V_86 :
if ( V_82 == V_85 )
return true ;
break;
}
return false ;
}
static V_22 F_88 ( struct V_47 * V_47 , V_22 V_24 , int V_74 )
{
struct V_3 * V_3 = V_47 -> V_52 -> V_53 ;
V_22 V_87 = V_3 -> V_13 -> V_88 ;
struct V_11 V_12 ;
T_2 V_73 , V_89 , V_83 ;
V_22 V_90 = V_24 ;
V_22 V_91 ;
int V_6 = 0 ;
F_89 ( V_3 ) ;
V_91 = F_22 ( V_3 ) ;
if ( V_24 >= V_91 )
goto V_92;
if ( F_11 ( V_3 ) || F_90 ( V_3 ) ) {
if ( V_74 == V_86 )
V_90 = V_91 ;
goto V_93;
}
V_73 = ( T_2 ) ( V_24 >> V_23 ) ;
V_83 = F_83 ( V_3 -> V_18 , V_73 , V_74 ) ;
for (; V_90 < V_91 ; V_90 = ( V_22 ) V_73 << V_23 ) {
F_13 ( & V_12 , V_3 , NULL , NULL , 0 ) ;
V_6 = F_91 ( & V_12 , V_73 , V_94 ) ;
if ( V_6 && V_6 != - V_95 ) {
goto V_92;
} else if ( V_6 == - V_95 ) {
if ( V_74 == V_78 ) {
V_73 = F_92 ( & V_12 , V_73 ) ;
continue;
} else {
goto V_93;
}
}
V_89 = F_93 ( V_12 . V_96 , V_3 ) ;
for (; V_12 . V_97 < V_89 ;
V_12 . V_97 ++ , V_73 ++ ,
V_90 = ( V_22 ) V_73 << V_23 ) {
T_3 V_82 ;
V_82 = F_94 ( V_12 . V_3 ,
V_12 . V_96 , V_12 . V_97 ) ;
if ( F_87 ( V_82 , V_83 , V_73 , V_74 ) ) {
F_16 ( & V_12 ) ;
goto V_93;
}
}
F_16 ( & V_12 ) ;
}
if ( V_74 == V_78 )
goto V_92;
V_93:
if ( V_74 == V_86 && V_90 > V_91 )
V_90 = V_91 ;
F_95 ( V_3 ) ;
return F_96 ( V_47 , V_90 , V_87 ) ;
V_92:
F_95 ( V_3 ) ;
return - V_98 ;
}
static V_22 F_97 ( struct V_47 * V_47 , V_22 V_24 , int V_74 )
{
struct V_3 * V_3 = V_47 -> V_52 -> V_53 ;
V_22 V_87 = V_3 -> V_13 -> V_88 ;
switch ( V_74 ) {
case V_99 :
case V_100 :
case V_101 :
return F_98 ( V_47 , V_24 , V_74 ,
V_87 , F_22 ( V_3 ) ) ;
case V_78 :
case V_86 :
if ( V_24 < 0 )
return - V_98 ;
return F_88 ( V_47 , V_24 , V_74 ) ;
}
return - V_102 ;
}
static int F_99 ( struct V_47 * V_47 , struct V_103 * V_4 )
{
struct V_3 * V_3 = F_2 ( V_47 ) ;
int V_6 ;
V_6 = F_100 ( V_3 ) ;
if ( V_6 )
return V_6 ;
F_101 ( V_47 ) ;
V_4 -> V_104 = & V_105 ;
return 0 ;
}
static int F_102 ( struct V_3 * V_3 , struct V_47 * V_106 )
{
struct V_33 * V_107 ;
if ( F_103 ( V_3 ) ) {
int V_43 = F_104 ( V_3 ) ;
if ( V_43 )
return - V_108 ;
if ( ! F_105 ( V_3 ) )
return - V_109 ;
}
V_107 = F_106 ( F_107 ( V_106 ) ) ;
if ( F_103 ( F_108 ( V_107 ) ) &&
! F_109 ( F_108 ( V_107 ) , V_3 ) ) {
F_42 ( V_107 ) ;
return - V_110 ;
}
F_42 ( V_107 ) ;
return F_110 ( V_3 , V_106 ) ;
}
int F_111 ( struct V_11 * V_12 , int V_111 )
{
struct V_9 * V_10 = F_8 ( V_12 -> V_3 ) ;
struct V_112 * V_113 ;
int V_114 = 0 , V_115 = V_12 -> V_97 , V_116 = V_111 ;
T_4 * V_117 ;
int V_118 = 0 ;
if ( F_112 ( V_12 -> V_96 ) && F_113 ( V_12 -> V_3 ) )
V_118 = F_114 ( V_12 -> V_3 ) ;
V_113 = F_115 ( V_12 -> V_96 ) ;
V_117 = F_116 ( V_113 ) + V_118 + V_115 ;
for (; V_111 > 0 ; V_111 -- , V_117 ++ , V_12 -> V_97 ++ ) {
T_3 V_82 = F_117 ( * V_117 ) ;
if ( V_82 == V_85 )
continue;
V_12 -> V_30 = V_85 ;
F_118 ( V_12 ) ;
F_119 ( V_10 , V_82 ) ;
if ( V_12 -> V_97 == 0 && F_112 ( V_12 -> V_96 ) )
F_68 ( V_12 -> V_3 , V_119 ) ;
V_114 ++ ;
}
if ( V_114 ) {
T_2 V_120 ;
V_120 = F_120 ( F_121 ( V_12 -> V_96 ) ,
V_12 -> V_3 ) + V_115 ;
F_122 ( V_12 , V_120 , 0 , V_116 ) ;
F_123 ( V_10 , V_12 -> V_3 , V_114 ) ;
}
V_12 -> V_97 = V_115 ;
F_35 ( V_10 , V_31 ) ;
F_124 ( V_12 -> V_3 , V_12 -> V_121 ,
V_12 -> V_97 , V_114 ) ;
return V_114 ;
}
void F_125 ( struct V_11 * V_12 )
{
F_111 ( V_12 , V_122 ) ;
}
static int F_126 ( struct V_3 * V_3 , T_5 V_123 ,
bool V_124 )
{
unsigned V_24 = V_123 & ( V_26 - 1 ) ;
T_2 V_14 = V_123 >> V_23 ;
struct V_72 * V_17 = V_3 -> V_18 ;
struct V_8 * V_8 ;
if ( ! V_24 && ! V_124 )
return 0 ;
if ( V_124 ) {
V_8 = F_127 ( V_17 , V_14 ) ;
if ( V_8 && F_23 ( V_8 ) )
goto V_125;
F_55 ( V_8 , 1 ) ;
return 0 ;
}
V_8 = F_128 ( V_3 , V_14 , true ) ;
if ( F_129 ( V_8 ) )
return F_130 ( V_8 ) == - V_95 ? 0 : F_130 ( V_8 ) ;
V_125:
F_31 ( V_8 , V_29 , true ) ;
F_131 ( V_8 , V_24 , V_26 - V_24 ) ;
F_10 ( F_8 ( V_3 ) , V_124 && F_103 ( V_3 ) ) ;
if ( ! V_124 )
F_27 ( V_8 ) ;
F_55 ( V_8 , 1 ) ;
return 0 ;
}
int F_132 ( struct V_3 * V_3 , T_5 V_123 , bool V_126 )
{
struct V_9 * V_10 = F_8 ( V_3 ) ;
unsigned int V_127 = V_3 -> V_13 -> V_128 ;
struct V_11 V_12 ;
T_2 V_129 ;
int V_111 = 0 , V_6 = 0 ;
struct V_8 * V_130 ;
bool V_131 = false ;
F_133 ( V_3 , V_123 ) ;
V_129 = ( T_2 ) F_134 ( V_123 + V_127 - 1 ) ;
if ( V_129 >= V_10 -> V_132 )
goto V_133;
if ( V_126 )
F_12 ( V_10 ) ;
V_130 = F_135 ( V_10 , V_3 -> V_54 ) ;
if ( F_129 ( V_130 ) ) {
V_6 = F_130 ( V_130 ) ;
goto V_15;
}
if ( F_11 ( V_3 ) ) {
F_136 ( V_3 , V_130 , V_123 ) ;
F_55 ( V_130 , 1 ) ;
V_131 = true ;
goto V_15;
}
F_13 ( & V_12 , V_3 , V_130 , NULL , 0 ) ;
V_6 = F_91 ( & V_12 , V_129 , V_134 ) ;
if ( V_6 ) {
if ( V_6 == - V_95 )
goto V_135;
goto V_15;
}
V_111 = F_93 ( V_12 . V_96 , V_3 ) ;
V_111 -= V_12 . V_97 ;
F_10 ( V_10 , V_111 < 0 ) ;
if ( V_12 . V_97 || F_112 ( V_12 . V_96 ) ) {
F_111 ( & V_12 , V_111 ) ;
V_129 += V_111 ;
}
F_16 ( & V_12 ) ;
V_135:
V_6 = F_137 ( V_3 , V_129 ) ;
V_15:
if ( V_126 )
F_15 ( V_10 ) ;
V_133:
if ( ! V_6 )
V_6 = F_126 ( V_3 , V_123 , V_131 ) ;
F_138 ( V_3 , V_6 ) ;
return V_6 ;
}
int F_139 ( struct V_3 * V_3 )
{
int V_6 ;
if ( ! ( F_44 ( V_3 -> V_35 ) || F_140 ( V_3 -> V_35 ) ||
F_141 ( V_3 -> V_35 ) ) )
return 0 ;
F_142 ( V_3 ) ;
#ifdef F_143
if ( F_144 ( F_8 ( V_3 ) , V_136 ) ) {
F_145 ( V_136 ) ;
return - V_71 ;
}
#endif
if ( ! F_146 ( V_3 ) ) {
V_6 = F_100 ( V_3 ) ;
if ( V_6 )
return V_6 ;
}
V_6 = F_132 ( V_3 , F_22 ( V_3 ) , true ) ;
if ( V_6 )
return V_6 ;
V_3 -> V_137 = V_3 -> V_138 = F_147 ( V_3 ) ;
F_77 ( V_3 , false ) ;
return 0 ;
}
int F_148 ( const struct V_139 * V_139 , struct V_140 * V_141 ,
T_6 V_142 , unsigned int V_143 )
{
struct V_3 * V_3 = F_108 ( V_139 -> V_33 ) ;
struct V_44 * V_45 = F_4 ( V_3 ) ;
unsigned int V_144 ;
V_144 = V_45 -> V_145 & ( V_146 | V_147 ) ;
if ( V_144 & V_148 )
V_141 -> V_149 |= V_150 ;
if ( V_144 & V_151 )
V_141 -> V_149 |= V_152 ;
if ( F_103 ( V_3 ) )
V_141 -> V_149 |= V_153 ;
if ( V_144 & V_154 )
V_141 -> V_149 |= V_155 ;
if ( V_144 & V_156 )
V_141 -> V_149 |= V_157 ;
V_141 -> V_158 |= ( V_150 |
V_152 |
V_153 |
V_155 |
V_157 ) ;
F_149 ( V_3 , V_141 ) ;
return 0 ;
}
static void F_150 ( struct V_3 * V_3 , const struct V_159 * V_160 )
{
unsigned int V_161 = V_160 -> V_161 ;
if ( V_161 & V_162 )
V_3 -> V_163 = V_160 -> V_164 ;
if ( V_161 & V_165 )
V_3 -> V_166 = V_160 -> V_167 ;
if ( V_161 & V_168 )
V_3 -> V_169 = F_151 ( V_160 -> V_170 ,
V_3 -> V_13 -> V_171 ) ;
if ( V_161 & V_172 )
V_3 -> V_137 = F_151 ( V_160 -> V_173 ,
V_3 -> V_13 -> V_171 ) ;
if ( V_161 & V_174 )
V_3 -> V_138 = F_151 ( V_160 -> V_175 ,
V_3 -> V_13 -> V_171 ) ;
if ( V_161 & V_176 ) {
T_7 V_177 = V_160 -> V_178 ;
if ( ! F_152 ( V_3 -> V_166 ) && ! F_153 ( V_179 ) )
V_177 &= ~ V_180 ;
F_154 ( V_3 , V_177 ) ;
}
}
int F_155 ( struct V_33 * V_33 , struct V_159 * V_160 )
{
struct V_3 * V_3 = F_108 ( V_33 ) ;
int V_6 ;
bool V_181 = false ;
V_6 = F_156 ( V_33 , V_160 ) ;
if ( V_6 )
return V_6 ;
if ( F_157 ( V_3 , V_160 ) ) {
V_6 = F_158 ( V_3 ) ;
if ( V_6 )
return V_6 ;
}
if ( ( V_160 -> V_161 & V_162 &&
! F_159 ( V_160 -> V_164 , V_3 -> V_163 ) ) ||
( V_160 -> V_161 & V_165 &&
! F_160 ( V_160 -> V_167 , V_3 -> V_166 ) ) ) {
V_6 = F_161 ( V_3 , V_160 ) ;
if ( V_6 )
return V_6 ;
}
if ( V_160 -> V_161 & V_182 ) {
if ( F_103 ( V_3 ) ) {
V_6 = F_104 ( V_3 ) ;
if ( V_6 )
return V_6 ;
if ( ! F_105 ( V_3 ) )
return - V_109 ;
}
if ( V_160 -> V_183 <= F_22 ( V_3 ) ) {
F_57 ( & F_4 ( V_3 ) -> V_7 ) ;
F_162 ( V_3 , V_160 -> V_183 ) ;
V_6 = F_139 ( V_3 ) ;
F_60 ( & F_4 ( V_3 ) -> V_7 ) ;
if ( V_6 )
return V_6 ;
} else {
F_57 ( & F_4 ( V_3 ) -> V_7 ) ;
F_162 ( V_3 , V_160 -> V_183 ) ;
F_60 ( & F_4 ( V_3 ) -> V_7 ) ;
if ( ! F_146 ( V_3 ) ) {
V_6 = F_100 ( V_3 ) ;
if ( V_6 )
return V_6 ;
}
V_3 -> V_137 = V_3 -> V_138 = F_147 ( V_3 ) ;
}
V_181 = true ;
}
F_150 ( V_3 , V_160 ) ;
if ( V_160 -> V_161 & V_176 ) {
V_6 = F_163 ( V_3 , F_164 ( V_3 ) ) ;
if ( V_6 || F_72 ( V_3 , V_184 ) ) {
V_3 -> V_35 = F_4 ( V_3 ) -> V_185 ;
F_68 ( V_3 , V_184 ) ;
}
}
F_77 ( V_3 , V_181 ) ;
F_17 ( F_8 ( V_3 ) , true ) ;
return V_6 ;
}
static int F_165 ( struct V_3 * V_3 , T_2 V_14 ,
V_22 V_48 , V_22 V_116 )
{
struct V_9 * V_10 = F_8 ( V_3 ) ;
struct V_8 * V_8 ;
if ( ! V_116 )
return 0 ;
F_17 ( V_10 , true ) ;
F_12 ( V_10 ) ;
V_8 = F_166 ( V_3 , NULL , V_14 , false ) ;
F_15 ( V_10 ) ;
if ( F_129 ( V_8 ) )
return F_130 ( V_8 ) ;
F_31 ( V_8 , V_29 , true ) ;
F_131 ( V_8 , V_48 , V_116 ) ;
F_27 ( V_8 ) ;
F_55 ( V_8 , 1 ) ;
return 0 ;
}
int F_167 ( struct V_3 * V_3 , T_2 V_186 , T_2 V_187 )
{
int V_6 ;
while ( V_186 < V_187 ) {
struct V_11 V_12 ;
T_2 V_89 , V_111 ;
F_13 ( & V_12 , V_3 , NULL , NULL , 0 ) ;
V_6 = F_91 ( & V_12 , V_186 , V_94 ) ;
if ( V_6 ) {
if ( V_6 == - V_95 ) {
V_186 ++ ;
continue;
}
return V_6 ;
}
V_89 = F_93 ( V_12 . V_96 , V_3 ) ;
V_111 = F_168 ( V_89 - V_12 . V_97 , V_187 - V_186 ) ;
F_10 ( F_8 ( V_3 ) , V_111 == 0 || V_111 > V_89 ) ;
F_111 ( & V_12 , V_111 ) ;
F_16 ( & V_12 ) ;
V_186 += V_111 ;
}
return 0 ;
}
static int F_169 ( struct V_3 * V_3 , V_22 V_24 , V_22 V_116 )
{
T_2 V_186 , V_187 ;
V_22 V_188 , V_189 ;
int V_43 ;
V_43 = F_100 ( V_3 ) ;
if ( V_43 )
return V_43 ;
V_186 = ( ( unsigned long long ) V_24 ) >> V_23 ;
V_187 = ( ( unsigned long long ) V_24 + V_116 ) >> V_23 ;
V_188 = V_24 & ( V_26 - 1 ) ;
V_189 = ( V_24 + V_116 ) & ( V_26 - 1 ) ;
if ( V_186 == V_187 ) {
V_43 = F_165 ( V_3 , V_186 , V_188 ,
V_189 - V_188 ) ;
if ( V_43 )
return V_43 ;
} else {
if ( V_188 ) {
V_43 = F_165 ( V_3 , V_186 ++ , V_188 ,
V_26 - V_188 ) ;
if ( V_43 )
return V_43 ;
}
if ( V_189 ) {
V_43 = F_165 ( V_3 , V_187 , 0 , V_189 ) ;
if ( V_43 )
return V_43 ;
}
if ( V_186 < V_187 ) {
struct V_72 * V_17 = V_3 -> V_18 ;
V_22 V_190 , V_191 ;
struct V_9 * V_10 = F_8 ( V_3 ) ;
F_17 ( V_10 , true ) ;
V_190 = ( V_22 ) V_186 << V_23 ;
V_191 = ( V_22 ) V_187 << V_23 ;
F_57 ( & F_4 ( V_3 ) -> V_7 ) ;
F_170 ( V_17 , V_190 ,
V_191 - 1 ) ;
F_12 ( V_10 ) ;
V_43 = F_167 ( V_3 , V_186 , V_187 ) ;
F_15 ( V_10 ) ;
F_60 ( & F_4 ( V_3 ) -> V_7 ) ;
}
}
return V_43 ;
}
static int F_171 ( struct V_3 * V_3 , T_3 * V_82 ,
int * V_192 , T_2 V_193 , T_2 V_116 )
{
struct V_9 * V_10 = F_8 ( V_3 ) ;
struct V_11 V_12 ;
int V_43 , V_194 , V_42 ;
V_195:
F_13 ( & V_12 , V_3 , NULL , NULL , 0 ) ;
V_43 = F_91 ( & V_12 , V_193 , V_134 ) ;
if ( V_43 && V_43 != - V_95 ) {
return V_43 ;
} else if ( V_43 == - V_95 ) {
if ( V_12 . V_196 == 0 )
return - V_95 ;
V_194 = F_168 ( ( T_2 ) V_122 - V_12 . V_97 , V_116 ) ;
V_82 += V_194 ;
V_192 += V_194 ;
goto V_197;
}
V_194 = F_168 ( ( T_2 ) F_93 ( V_12 . V_96 , V_3 ) -
V_12 . V_97 , V_116 ) ;
for ( V_42 = 0 ; V_42 < V_194 ; V_42 ++ , V_82 ++ , V_192 ++ , V_12 . V_97 ++ ) {
* V_82 = F_94 ( V_12 . V_3 ,
V_12 . V_96 , V_12 . V_97 ) ;
if ( ! F_172 ( V_10 , * V_82 ) ) {
if ( F_49 ( V_10 , V_198 ) ) {
F_16 ( & V_12 ) ;
return - V_199 ;
}
F_173 ( & V_12 , V_85 ) ;
* V_192 = 1 ;
}
}
F_16 ( & V_12 ) ;
V_197:
V_116 -= V_194 ;
V_193 += V_194 ;
if ( V_116 )
goto V_195;
return 0 ;
}
static int F_174 ( struct V_3 * V_3 , T_3 * V_82 ,
int * V_192 , T_2 V_193 , int V_116 )
{
struct V_9 * V_10 = F_8 ( V_3 ) ;
struct V_11 V_12 ;
int V_43 , V_42 ;
for ( V_42 = 0 ; V_42 < V_116 ; V_42 ++ , V_192 ++ , V_82 ++ ) {
if ( * V_192 == 0 )
continue;
F_13 ( & V_12 , V_3 , NULL , NULL , 0 ) ;
V_43 = F_91 ( & V_12 , V_193 + V_42 , V_134 ) ;
if ( V_43 ) {
F_123 ( V_10 , V_3 , 1 ) ;
F_119 ( V_10 , * V_82 ) ;
} else {
F_173 ( & V_12 , * V_82 ) ;
}
F_16 ( & V_12 ) ;
}
return 0 ;
}
static int F_175 ( struct V_3 * V_200 , struct V_3 * V_201 ,
T_3 * V_82 , int * V_192 ,
T_2 V_202 , T_2 V_203 , T_2 V_116 , bool V_204 )
{
struct V_9 * V_10 = F_8 ( V_200 ) ;
T_2 V_42 = 0 ;
int V_43 ;
while ( V_42 < V_116 ) {
if ( V_82 [ V_42 ] == V_85 && ! V_204 ) {
V_42 ++ ;
continue;
}
if ( V_192 [ V_42 ] || V_82 [ V_42 ] == V_85 ) {
struct V_11 V_12 ;
struct V_205 V_206 ;
T_8 V_207 ;
T_2 V_208 ;
F_13 ( & V_12 , V_201 , NULL , NULL , 0 ) ;
V_43 = F_91 ( & V_12 , V_203 + V_42 , V_209 ) ;
if ( V_43 )
return V_43 ;
F_176 ( V_10 , V_12 . V_121 , & V_206 ) ;
V_208 = F_168 ( ( T_2 )
F_93 ( V_12 . V_96 , V_201 ) -
V_12 . V_97 , V_116 - V_42 ) ;
do {
V_12 . V_30 = F_94 ( V_12 . V_3 ,
V_12 . V_96 , V_12 . V_97 ) ;
F_111 ( & V_12 , 1 ) ;
if ( V_192 [ V_42 ] ) {
F_177 ( V_200 ,
1 , false , false ) ;
F_177 ( V_201 ,
1 , true , false ) ;
F_178 ( V_10 , & V_12 , V_12 . V_30 ,
V_82 [ V_42 ] , V_206 . V_210 , true , false ) ;
V_192 [ V_42 ] = 0 ;
}
V_12 . V_97 ++ ;
V_42 ++ ;
V_207 = ( V_203 + V_42 ) << V_23 ;
if ( V_201 -> V_211 < V_207 )
F_179 ( V_201 , V_207 ) ;
} while ( -- V_208 && ( V_192 [ V_42 ] || V_82 [ V_42 ] == V_85 ) );
F_16 ( & V_12 ) ;
} else {
struct V_8 * V_212 , * V_213 ;
V_212 = F_128 ( V_200 , V_202 + V_42 , true ) ;
if ( F_129 ( V_212 ) )
return F_130 ( V_212 ) ;
V_213 = F_166 ( V_201 , NULL , V_203 + V_42 ,
true ) ;
if ( F_129 ( V_213 ) ) {
F_55 ( V_212 , 1 ) ;
return F_130 ( V_213 ) ;
}
F_180 ( V_212 , V_213 ) ;
F_27 ( V_213 ) ;
F_55 ( V_213 , 1 ) ;
F_55 ( V_212 , 1 ) ;
V_43 = F_167 ( V_200 , V_202 + V_42 , V_202 + V_42 + 1 ) ;
if ( V_43 )
return V_43 ;
V_42 ++ ;
}
}
return 0 ;
}
static int F_181 ( struct V_3 * V_200 ,
struct V_3 * V_201 , T_2 V_202 , T_2 V_203 ,
T_2 V_116 , bool V_204 )
{
T_3 * V_214 ;
int * V_192 ;
T_2 V_215 ;
int V_43 ;
while ( V_116 ) {
V_215 = F_168 ( ( T_2 ) 4 * V_122 , V_116 ) ;
V_214 = F_182 ( sizeof( T_3 ) * V_215 , V_216 ) ;
if ( ! V_214 )
return - V_217 ;
V_192 = F_182 ( sizeof( int ) * V_215 , V_216 ) ;
if ( ! V_192 ) {
F_183 ( V_214 ) ;
return - V_217 ;
}
V_43 = F_171 ( V_200 , V_214 ,
V_192 , V_202 , V_215 ) ;
if ( V_43 )
goto V_218;
V_43 = F_175 ( V_200 , V_201 , V_214 ,
V_192 , V_202 , V_203 , V_215 , V_204 ) ;
if ( V_43 )
goto V_218;
V_202 += V_215 ;
V_203 += V_215 ;
V_116 -= V_215 ;
F_183 ( V_214 ) ;
F_183 ( V_192 ) ;
}
return 0 ;
V_218:
F_174 ( V_200 , V_214 , V_192 , V_202 , V_116 ) ;
F_183 ( V_214 ) ;
F_183 ( V_192 ) ;
return V_43 ;
}
static int F_184 ( struct V_3 * V_3 , T_2 V_48 , T_2 V_49 )
{
struct V_9 * V_10 = F_8 ( V_3 ) ;
T_2 V_219 = ( F_22 ( V_3 ) + V_26 - 1 ) / V_26 ;
int V_43 ;
F_17 ( V_10 , true ) ;
F_12 ( V_10 ) ;
F_185 ( V_3 ) ;
V_43 = F_181 ( V_3 , V_3 , V_49 , V_48 , V_219 - V_49 , true ) ;
F_15 ( V_10 ) ;
return V_43 ;
}
static int F_186 ( struct V_3 * V_3 , V_22 V_24 , V_22 V_116 )
{
T_2 V_186 , V_187 ;
V_22 V_207 ;
int V_43 ;
if ( V_24 + V_116 >= F_22 ( V_3 ) )
return - V_102 ;
if ( V_24 & ( V_28 - 1 ) || V_116 & ( V_28 - 1 ) )
return - V_102 ;
V_43 = F_100 ( V_3 ) ;
if ( V_43 )
return V_43 ;
V_186 = V_24 >> V_23 ;
V_187 = ( V_24 + V_116 ) >> V_23 ;
F_57 ( & F_4 ( V_3 ) -> V_7 ) ;
V_43 = F_187 ( V_3 -> V_18 , V_24 , V_220 ) ;
if ( V_43 )
goto V_15;
F_188 ( V_3 , V_24 ) ;
V_43 = F_184 ( V_3 , V_186 , V_187 ) ;
if ( V_43 )
goto V_15;
F_187 ( V_3 -> V_18 , V_24 , V_220 ) ;
F_188 ( V_3 , V_24 ) ;
V_207 = F_22 ( V_3 ) - V_116 ;
F_188 ( V_3 , V_207 ) ;
V_43 = F_132 ( V_3 , V_207 , true ) ;
if ( ! V_43 )
F_179 ( V_3 , V_207 ) ;
V_15:
F_60 ( & F_4 ( V_3 ) -> V_7 ) ;
return V_43 ;
}
static int F_189 ( struct V_11 * V_12 , T_2 V_48 ,
T_2 V_49 )
{
struct V_9 * V_10 = F_8 ( V_12 -> V_3 ) ;
T_2 V_14 = V_48 ;
unsigned int V_97 = V_12 -> V_97 ;
T_9 V_111 = 0 ;
int V_43 ;
for (; V_14 < V_49 ; V_14 ++ , V_12 -> V_97 ++ ) {
if ( F_94 ( V_12 -> V_3 , V_12 -> V_96 ,
V_12 -> V_97 ) == V_85 )
V_111 ++ ;
}
V_12 -> V_97 = V_97 ;
V_43 = F_190 ( V_12 , V_111 ) ;
if ( V_43 )
return V_43 ;
V_12 -> V_97 = V_97 ;
for ( V_14 = V_48 ; V_14 < V_49 ; V_14 ++ , V_12 -> V_97 ++ ) {
V_12 -> V_30 = F_94 ( V_12 -> V_3 ,
V_12 -> V_96 , V_12 -> V_97 ) ;
if ( V_12 -> V_30 == V_85 ) {
V_43 = - V_221 ;
break;
}
if ( V_12 -> V_30 != V_84 ) {
F_119 ( V_10 , V_12 -> V_30 ) ;
V_12 -> V_30 = V_84 ;
F_118 ( V_12 ) ;
}
}
F_122 ( V_12 , V_48 , 0 , V_14 - V_48 ) ;
return V_43 ;
}
static int F_191 ( struct V_3 * V_3 , V_22 V_24 , V_22 V_116 ,
int V_177 )
{
struct V_9 * V_10 = F_8 ( V_3 ) ;
struct V_72 * V_17 = V_3 -> V_18 ;
T_2 V_14 , V_186 , V_187 ;
V_22 V_207 = F_22 ( V_3 ) ;
V_22 V_188 , V_189 ;
int V_43 = 0 ;
V_43 = F_192 ( V_3 , ( V_116 + V_24 ) ) ;
if ( V_43 )
return V_43 ;
V_43 = F_100 ( V_3 ) ;
if ( V_43 )
return V_43 ;
F_57 ( & F_4 ( V_3 ) -> V_7 ) ;
V_43 = F_187 ( V_17 , V_24 , V_24 + V_116 - 1 ) ;
if ( V_43 )
goto V_20;
F_193 ( V_3 , V_24 , V_24 + V_116 - 1 ) ;
V_186 = ( ( unsigned long long ) V_24 ) >> V_23 ;
V_187 = ( ( unsigned long long ) V_24 + V_116 ) >> V_23 ;
V_188 = V_24 & ( V_26 - 1 ) ;
V_189 = ( V_24 + V_116 ) & ( V_26 - 1 ) ;
if ( V_186 == V_187 ) {
V_43 = F_165 ( V_3 , V_186 , V_188 ,
V_189 - V_188 ) ;
if ( V_43 )
goto V_20;
V_207 = F_194 ( V_22 , V_207 , V_24 + V_116 ) ;
} else {
if ( V_188 ) {
V_43 = F_165 ( V_3 , V_186 ++ , V_188 ,
V_26 - V_188 ) ;
if ( V_43 )
goto V_20;
V_207 = F_194 ( V_22 , V_207 ,
( V_22 ) V_186 << V_23 ) ;
}
for ( V_14 = V_186 ; V_14 < V_187 ; ) {
struct V_11 V_12 ;
unsigned int V_89 ;
T_2 V_49 ;
F_12 ( V_10 ) ;
F_13 ( & V_12 , V_3 , NULL , NULL , 0 ) ;
V_43 = F_91 ( & V_12 , V_14 , V_209 ) ;
if ( V_43 ) {
F_15 ( V_10 ) ;
goto V_15;
}
V_89 = F_93 ( V_12 . V_96 , V_3 ) ;
V_49 = F_168 ( V_187 , V_89 - V_12 . V_97 + V_14 ) ;
V_43 = F_189 ( & V_12 , V_14 , V_49 ) ;
F_16 ( & V_12 ) ;
F_15 ( V_10 ) ;
F_17 ( V_10 , V_12 . V_16 ) ;
if ( V_43 )
goto V_15;
V_14 = V_49 ;
V_207 = F_194 ( V_22 , V_207 ,
( V_22 ) V_14 << V_23 ) ;
}
if ( V_189 ) {
V_43 = F_165 ( V_3 , V_187 , 0 , V_189 ) ;
if ( V_43 )
goto V_15;
V_207 = F_194 ( V_22 , V_207 , V_24 + V_116 ) ;
}
}
V_15:
if ( ! ( V_177 & V_222 ) && F_22 ( V_3 ) < V_207 )
F_179 ( V_3 , V_207 ) ;
V_20:
F_60 ( & F_4 ( V_3 ) -> V_7 ) ;
return V_43 ;
}
static int F_195 ( struct V_3 * V_3 , V_22 V_24 , V_22 V_116 )
{
struct V_9 * V_10 = F_8 ( V_3 ) ;
T_2 V_223 , V_186 , V_187 , V_224 , V_225 ;
V_22 V_207 ;
int V_43 = 0 ;
V_207 = F_22 ( V_3 ) + V_116 ;
V_43 = F_192 ( V_3 , V_207 ) ;
if ( V_43 )
return V_43 ;
if ( V_24 >= F_22 ( V_3 ) )
return - V_102 ;
if ( V_24 & ( V_28 - 1 ) || V_116 & ( V_28 - 1 ) )
return - V_102 ;
V_43 = F_100 ( V_3 ) ;
if ( V_43 )
return V_43 ;
F_17 ( V_10 , true ) ;
F_57 ( & F_4 ( V_3 ) -> V_7 ) ;
V_43 = F_132 ( V_3 , F_22 ( V_3 ) , true ) ;
if ( V_43 )
goto V_15;
V_43 = F_187 ( V_3 -> V_18 , V_24 , V_220 ) ;
if ( V_43 )
goto V_15;
F_188 ( V_3 , V_24 ) ;
V_186 = V_24 >> V_23 ;
V_187 = ( V_24 + V_116 ) >> V_23 ;
V_224 = V_187 - V_186 ;
V_225 = ( F_22 ( V_3 ) + V_26 - 1 ) / V_26 ;
while ( ! V_43 && V_225 > V_186 ) {
V_223 = V_225 - V_186 ;
if ( V_223 > V_224 )
V_223 = V_224 ;
V_225 -= V_223 ;
F_12 ( V_10 ) ;
F_185 ( V_3 ) ;
V_43 = F_181 ( V_3 , V_3 , V_225 ,
V_225 + V_224 , V_223 , false ) ;
F_15 ( V_10 ) ;
}
F_187 ( V_3 -> V_18 , V_24 , V_220 ) ;
F_188 ( V_3 , V_24 ) ;
if ( ! V_43 )
F_179 ( V_3 , V_207 ) ;
V_15:
F_60 ( & F_4 ( V_3 ) -> V_7 ) ;
return V_43 ;
}
static int F_196 ( struct V_3 * V_3 , V_22 V_24 ,
V_22 V_116 , int V_177 )
{
struct V_9 * V_10 = F_8 ( V_3 ) ;
struct V_226 V_227 = { . V_228 = NULL } ;
T_2 V_187 ;
V_22 V_207 = F_22 ( V_3 ) ;
V_22 V_189 ;
int V_6 ;
V_6 = F_192 ( V_3 , ( V_116 + V_24 ) ) ;
if ( V_6 )
return V_6 ;
V_6 = F_100 ( V_3 ) ;
if ( V_6 )
return V_6 ;
F_17 ( V_10 , true ) ;
V_187 = ( ( unsigned long long ) V_24 + V_116 ) >> V_23 ;
V_189 = ( V_24 + V_116 ) & ( V_26 - 1 ) ;
V_227 . V_229 = ( ( unsigned long long ) V_24 ) >> V_23 ;
V_227 . V_230 = V_187 - V_227 . V_229 ;
if ( V_189 )
V_227 . V_230 ++ ;
V_6 = V_226 ( V_3 , & V_227 , 1 , V_231 ) ;
if ( V_6 ) {
T_2 V_232 ;
if ( ! V_227 . V_230 )
return V_6 ;
V_232 = V_227 . V_229 + V_227 . V_230 - 1 ;
V_207 = ( V_232 == V_187 ) ? V_24 + V_116 :
( V_22 ) ( V_232 + 1 ) << V_23 ;
} else {
V_207 = ( ( V_22 ) V_187 << V_23 ) + V_189 ;
}
if ( ! ( V_177 & V_222 ) && F_22 ( V_3 ) < V_207 )
F_179 ( V_3 , V_207 ) ;
return V_6 ;
}
static long F_197 ( struct V_47 * V_47 , int V_177 ,
V_22 V_24 , V_22 V_116 )
{
struct V_3 * V_3 = F_2 ( V_47 ) ;
long V_43 = 0 ;
if ( ! F_44 ( V_3 -> V_35 ) )
return - V_102 ;
if ( F_103 ( V_3 ) &&
( V_177 & ( V_233 | V_234 ) ) )
return - V_235 ;
if ( V_177 & ~ ( V_222 | V_236 |
V_233 | V_237 |
V_234 ) )
return - V_235 ;
F_89 ( V_3 ) ;
if ( V_177 & V_236 ) {
if ( V_24 >= V_3 -> V_211 )
goto V_15;
V_43 = F_169 ( V_3 , V_24 , V_116 ) ;
} else if ( V_177 & V_233 ) {
V_43 = F_186 ( V_3 , V_24 , V_116 ) ;
} else if ( V_177 & V_237 ) {
V_43 = F_191 ( V_3 , V_24 , V_116 , V_177 ) ;
} else if ( V_177 & V_234 ) {
V_43 = F_195 ( V_3 , V_24 , V_116 ) ;
} else {
V_43 = F_196 ( V_3 , V_24 , V_116 , V_177 ) ;
}
if ( ! V_43 ) {
V_3 -> V_137 = V_3 -> V_138 = F_147 ( V_3 ) ;
F_77 ( V_3 , false ) ;
if ( V_177 & V_222 )
F_198 ( V_3 ) ;
F_35 ( F_8 ( V_3 ) , V_31 ) ;
}
V_15:
F_95 ( V_3 ) ;
F_199 ( V_3 , V_177 , V_24 , V_116 , V_43 ) ;
return V_43 ;
}
static int F_200 ( struct V_3 * V_3 , struct V_47 * V_106 )
{
if ( ! ( V_106 -> V_238 & V_239 ) ||
F_201 ( & V_3 -> V_240 ) != 1 )
return 0 ;
if ( F_202 ( V_3 ) )
F_203 ( V_3 ) ;
if ( F_204 ( V_3 ) ) {
F_68 ( V_3 , V_241 ) ;
F_205 ( V_3 ) ;
F_66 ( V_3 , V_242 ) ;
F_206 ( V_3 -> V_18 ) ;
F_68 ( V_3 , V_242 ) ;
}
return 0 ;
}
static int F_207 ( struct V_47 * V_47 , T_10 V_243 )
{
struct V_3 * V_3 = F_2 ( V_47 ) ;
if ( F_202 ( V_3 ) &&
F_4 ( V_3 ) -> V_244 == V_245 )
F_203 ( V_3 ) ;
return 0 ;
}
static int F_208 ( struct V_47 * V_106 , unsigned long V_246 )
{
struct V_3 * V_3 = F_2 ( V_106 ) ;
struct V_44 * V_45 = F_4 ( V_3 ) ;
unsigned int V_144 = V_45 -> V_145 &
( V_146 | V_147 ) ;
return F_209 ( V_144 , ( int V_247 * ) V_246 ) ;
}
static int F_210 ( struct V_3 * V_3 , unsigned int V_144 )
{
struct V_44 * V_45 = F_4 ( V_3 ) ;
unsigned int V_248 ;
if ( F_211 ( V_3 ) )
return - V_110 ;
V_144 = F_212 ( V_3 -> V_35 , V_144 ) ;
V_248 = V_45 -> V_145 ;
if ( ( V_144 ^ V_248 ) & ( V_148 | V_154 ) )
if ( ! F_153 ( V_249 ) )
return - V_110 ;
V_144 = V_144 & ( V_250 | V_147 ) ;
V_144 |= V_248 & ~ ( V_250 | V_147 ) ;
V_45 -> V_145 = V_144 ;
if ( V_45 -> V_145 & V_147 )
F_66 ( V_3 , V_251 ) ;
else
F_68 ( V_3 , V_251 ) ;
V_3 -> V_138 = F_147 ( V_3 ) ;
F_213 ( V_3 ) ;
F_77 ( V_3 , false ) ;
return 0 ;
}
static int F_214 ( struct V_47 * V_106 , unsigned long V_246 )
{
struct V_3 * V_3 = F_2 ( V_106 ) ;
unsigned int V_144 ;
int V_43 ;
if ( ! F_215 ( V_3 ) )
return - V_108 ;
if ( F_216 ( V_144 , ( int V_247 * ) V_246 ) )
return - V_19 ;
V_43 = F_217 ( V_106 ) ;
if ( V_43 )
return V_43 ;
F_89 ( V_3 ) ;
V_43 = F_210 ( V_3 , V_144 ) ;
F_95 ( V_3 ) ;
F_218 ( V_106 ) ;
return V_43 ;
}
static int F_219 ( struct V_47 * V_106 , unsigned long V_246 )
{
struct V_3 * V_3 = F_2 ( V_106 ) ;
return F_209 ( V_3 -> V_252 , ( int V_247 * ) V_246 ) ;
}
static int F_220 ( struct V_47 * V_106 )
{
struct V_3 * V_3 = F_2 ( V_106 ) ;
int V_43 ;
if ( ! F_215 ( V_3 ) )
return - V_108 ;
if ( ! F_44 ( V_3 -> V_35 ) )
return - V_102 ;
V_43 = F_217 ( V_106 ) ;
if ( V_43 )
return V_43 ;
F_89 ( V_3 ) ;
if ( F_202 ( V_3 ) )
goto V_15;
V_43 = F_100 ( V_3 ) ;
if ( V_43 )
goto V_15;
F_66 ( V_3 , V_253 ) ;
F_66 ( V_3 , V_254 ) ;
F_35 ( F_8 ( V_3 ) , V_31 ) ;
if ( ! F_64 ( V_3 ) )
goto V_255;
F_221 ( F_8 ( V_3 ) -> V_256 , V_257 ,
L_1 ,
V_3 -> V_54 , F_64 ( V_3 ) ) ;
V_43 = F_187 ( V_3 -> V_18 , 0 , V_220 ) ;
if ( V_43 ) {
F_68 ( V_3 , V_253 ) ;
F_68 ( V_3 , V_254 ) ;
goto V_15;
}
V_255:
F_4 ( V_3 ) -> V_244 = V_245 ;
F_222 ( V_3 ) ;
F_223 ( V_3 ) ;
V_15:
F_95 ( V_3 ) ;
F_218 ( V_106 ) ;
return V_43 ;
}
static int F_224 ( struct V_47 * V_106 )
{
struct V_3 * V_3 = F_2 ( V_106 ) ;
int V_43 ;
if ( ! F_215 ( V_3 ) )
return - V_108 ;
V_43 = F_217 ( V_106 ) ;
if ( V_43 )
return V_43 ;
F_89 ( V_3 ) ;
if ( F_204 ( V_3 ) )
goto V_258;
if ( F_202 ( V_3 ) ) {
V_43 = F_225 ( V_3 ) ;
if ( V_43 )
goto V_258;
V_43 = F_61 ( V_106 , 0 , V_220 , 0 , true ) ;
if ( ! V_43 ) {
F_68 ( V_3 , V_253 ) ;
F_68 ( V_3 , V_254 ) ;
F_226 ( V_3 ) ;
}
} else {
V_43 = F_61 ( V_106 , 0 , V_220 , 1 , false ) ;
}
V_258:
F_95 ( V_3 ) ;
F_218 ( V_106 ) ;
return V_43 ;
}
static int F_227 ( struct V_47 * V_106 )
{
struct V_3 * V_3 = F_2 ( V_106 ) ;
int V_43 ;
if ( ! F_215 ( V_3 ) )
return - V_108 ;
if ( ! F_44 ( V_3 -> V_35 ) )
return - V_102 ;
V_43 = F_217 ( V_106 ) ;
if ( V_43 )
return V_43 ;
F_89 ( V_3 ) ;
if ( F_204 ( V_3 ) )
goto V_15;
V_43 = F_100 ( V_3 ) ;
if ( V_43 )
goto V_15;
F_228 ( V_3 ) ;
F_229 ( V_3 ) ;
F_66 ( V_3 , V_241 ) ;
F_35 ( F_8 ( V_3 ) , V_31 ) ;
V_15:
F_95 ( V_3 ) ;
F_218 ( V_106 ) ;
return V_43 ;
}
static int F_230 ( struct V_47 * V_106 )
{
struct V_3 * V_3 = F_2 ( V_106 ) ;
int V_43 ;
if ( ! F_215 ( V_3 ) )
return - V_108 ;
V_43 = F_217 ( V_106 ) ;
if ( V_43 )
return V_43 ;
F_89 ( V_3 ) ;
if ( ! F_204 ( V_3 ) )
goto V_15;
if ( ! F_231 ( V_3 ) ) {
V_43 = F_126 ( V_3 , 0 , true ) ;
goto V_15;
}
V_43 = F_169 ( V_3 , 0 , V_28 ) ;
V_15:
F_95 ( V_3 ) ;
F_218 ( V_106 ) ;
return V_43 ;
}
static int F_232 ( struct V_47 * V_106 )
{
struct V_3 * V_3 = F_2 ( V_106 ) ;
int V_43 ;
if ( ! F_215 ( V_3 ) )
return - V_108 ;
V_43 = F_217 ( V_106 ) ;
if ( V_43 )
return V_43 ;
F_89 ( V_3 ) ;
if ( F_202 ( V_3 ) )
F_203 ( V_3 ) ;
if ( F_204 ( V_3 ) ) {
F_68 ( V_3 , V_241 ) ;
F_205 ( V_3 ) ;
V_43 = F_61 ( V_106 , 0 , V_220 , 0 , true ) ;
}
F_95 ( V_3 ) ;
F_218 ( V_106 ) ;
F_35 ( F_8 ( V_3 ) , V_31 ) ;
return V_43 ;
}
static int F_233 ( struct V_47 * V_106 , unsigned long V_246 )
{
struct V_3 * V_3 = F_2 ( V_106 ) ;
struct V_9 * V_10 = F_8 ( V_3 ) ;
struct V_259 * V_256 = V_10 -> V_256 ;
T_11 V_260 ;
int V_43 ;
if ( ! F_153 ( V_261 ) )
return - V_110 ;
if ( F_216 ( V_260 , ( T_11 V_247 * ) V_246 ) )
return - V_19 ;
V_43 = F_217 ( V_106 ) ;
if ( V_43 )
return V_43 ;
switch ( V_260 ) {
case V_262 :
V_256 = F_234 ( V_256 -> V_263 ) ;
if ( V_256 && ! F_129 ( V_256 ) ) {
F_235 ( V_10 , false ) ;
F_236 ( V_256 -> V_263 , V_256 ) ;
}
break;
case V_264 :
F_74 ( V_256 , 1 ) ;
F_235 ( V_10 , false ) ;
break;
case V_265 :
F_235 ( V_10 , false ) ;
break;
case V_266 :
F_237 ( V_10 , V_267 , V_60 , V_268 ) ;
F_235 ( V_10 , false ) ;
break;
default:
V_43 = - V_102 ;
goto V_15;
}
F_35 ( V_10 , V_31 ) ;
V_15:
F_218 ( V_106 ) ;
return V_43 ;
}
static int F_238 ( struct V_47 * V_106 , unsigned long V_246 )
{
struct V_3 * V_3 = F_2 ( V_106 ) ;
struct V_259 * V_256 = V_3 -> V_13 ;
struct V_269 * V_270 = F_239 ( V_256 -> V_263 ) ;
struct V_271 V_272 ;
int V_43 ;
if ( ! F_153 ( V_261 ) )
return - V_110 ;
if ( ! F_240 ( V_270 ) )
return - V_235 ;
if ( F_241 ( & V_272 , (struct V_271 V_247 * ) V_246 ,
sizeof( V_272 ) ) )
return - V_19 ;
V_43 = F_217 ( V_106 ) ;
if ( V_43 )
return V_43 ;
V_272 . V_273 = F_242 ( ( unsigned int ) V_272 . V_273 ,
V_270 -> V_274 . V_275 ) ;
V_43 = F_243 ( F_244 ( V_256 ) , & V_272 ) ;
F_218 ( V_106 ) ;
if ( V_43 < 0 )
return V_43 ;
if ( F_245 ( (struct V_271 V_247 * ) V_246 , & V_272 ,
sizeof( V_272 ) ) )
return - V_19 ;
F_35 ( F_8 ( V_3 ) , V_31 ) ;
return 0 ;
}
static bool F_246 ( T_12 V_276 [ 16 ] )
{
int V_42 ;
for ( V_42 = 0 ; V_42 < 16 ; V_42 ++ )
if ( V_276 [ V_42 ] )
return true ;
return false ;
}
static int F_247 ( struct V_47 * V_106 , unsigned long V_246 )
{
struct V_3 * V_3 = F_2 ( V_106 ) ;
F_35 ( F_8 ( V_3 ) , V_31 ) ;
return F_248 ( V_106 , ( const void V_247 * ) V_246 ) ;
}
static int F_249 ( struct V_47 * V_106 , unsigned long V_246 )
{
return F_250 ( V_106 , ( void V_247 * ) V_246 ) ;
}
static int F_251 ( struct V_47 * V_106 , unsigned long V_246 )
{
struct V_3 * V_3 = F_2 ( V_106 ) ;
struct V_9 * V_10 = F_8 ( V_3 ) ;
int V_6 ;
if ( ! F_252 ( V_3 -> V_13 ) )
return - V_235 ;
if ( F_246 ( V_10 -> V_277 -> V_278 ) )
goto V_279;
V_6 = F_217 ( V_106 ) ;
if ( V_6 )
return V_6 ;
F_253 ( V_10 -> V_277 -> V_278 ) ;
V_6 = F_254 ( V_10 , false ) ;
if ( V_6 ) {
memset ( V_10 -> V_277 -> V_278 , 0 , 16 ) ;
F_218 ( V_106 ) ;
return V_6 ;
}
F_218 ( V_106 ) ;
V_279:
if ( F_245 ( ( T_12 V_247 * ) V_246 , V_10 -> V_277 -> V_278 ,
16 ) )
return - V_19 ;
return 0 ;
}
static int F_255 ( struct V_47 * V_106 , unsigned long V_246 )
{
struct V_3 * V_3 = F_2 ( V_106 ) ;
struct V_9 * V_10 = F_8 ( V_3 ) ;
T_11 V_280 ;
int V_43 ;
if ( ! F_153 ( V_261 ) )
return - V_110 ;
if ( F_216 ( V_280 , ( T_11 V_247 * ) V_246 ) )
return - V_19 ;
if ( F_62 ( V_10 -> V_256 ) )
return - V_281 ;
V_43 = F_217 ( V_106 ) ;
if ( V_43 )
return V_43 ;
if ( ! V_280 ) {
if ( ! F_256 ( & V_10 -> V_282 ) ) {
V_43 = - V_283 ;
goto V_15;
}
} else {
F_257 ( & V_10 -> V_282 ) ;
}
V_43 = F_258 ( V_10 , V_280 , true , V_284 ) ;
V_15:
F_218 ( V_106 ) ;
return V_43 ;
}
static int F_259 ( struct V_47 * V_106 , unsigned long V_246 )
{
struct V_3 * V_3 = F_2 ( V_106 ) ;
struct V_9 * V_10 = F_8 ( V_3 ) ;
struct V_285 V_272 ;
T_5 V_49 ;
int V_43 ;
if ( ! F_153 ( V_261 ) )
return - V_110 ;
if ( F_241 ( & V_272 , (struct V_285 V_247 * ) V_246 ,
sizeof( V_272 ) ) )
return - V_19 ;
if ( F_62 ( V_10 -> V_256 ) )
return - V_281 ;
V_43 = F_217 ( V_106 ) ;
if ( V_43 )
return V_43 ;
V_49 = V_272 . V_48 + V_272 . V_116 ;
if ( V_272 . V_48 < F_260 ( V_10 ) || V_49 >= F_261 ( V_10 ) )
return - V_102 ;
V_286:
if ( ! V_272 . V_280 ) {
if ( ! F_256 ( & V_10 -> V_282 ) ) {
V_43 = - V_283 ;
goto V_15;
}
} else {
F_257 ( & V_10 -> V_282 ) ;
}
V_43 = F_258 ( V_10 , V_272 . V_280 , true , F_262 ( V_10 , V_272 . V_48 ) ) ;
V_272 . V_48 += V_10 -> V_287 ;
if ( V_272 . V_48 <= V_49 )
goto V_286;
V_15:
F_218 ( V_106 ) ;
return V_43 ;
}
static int F_263 ( struct V_47 * V_106 , unsigned long V_246 )
{
struct V_3 * V_3 = F_2 ( V_106 ) ;
struct V_9 * V_10 = F_8 ( V_3 ) ;
int V_43 ;
if ( ! F_153 ( V_261 ) )
return - V_110 ;
if ( F_62 ( V_10 -> V_256 ) )
return - V_281 ;
V_43 = F_217 ( V_106 ) ;
if ( V_43 )
return V_43 ;
V_43 = F_74 ( V_10 -> V_256 , 1 ) ;
F_218 ( V_106 ) ;
return V_43 ;
}
static int F_264 ( struct V_9 * V_10 ,
struct V_47 * V_106 ,
struct V_288 * V_272 )
{
struct V_3 * V_3 = F_2 ( V_106 ) ;
struct V_226 V_227 = { . V_228 = NULL } ;
struct V_289 V_290 = { 0 , 0 , 0 } ;
T_2 V_186 , V_187 ;
unsigned int V_291 = V_10 -> V_287 ;
unsigned int V_292 = 0 , V_293 ;
T_3 V_191 = 0 ;
bool V_294 = false ;
int V_6 ;
if ( F_265 ( V_3 , NULL ) )
return - V_102 ;
V_186 = V_272 -> V_48 >> V_23 ;
V_187 = ( V_272 -> V_48 + V_272 -> V_116 ) >> V_23 ;
F_17 ( V_10 , true ) ;
F_89 ( V_3 ) ;
V_6 = F_187 ( V_3 -> V_18 , V_272 -> V_48 ,
V_272 -> V_48 + V_272 -> V_116 - 1 ) ;
if ( V_6 )
goto V_15;
if ( F_266 ( V_3 , V_186 , & V_290 ) ) {
if ( V_290 . V_120 + V_290 . V_116 >= V_187 )
goto V_15;
}
V_227 . V_229 = V_186 ;
while ( V_227 . V_229 < V_187 ) {
V_227 . V_230 = V_187 - V_227 . V_229 ;
V_6 = V_226 ( V_3 , & V_227 , 0 , V_295 ) ;
if ( V_6 )
goto V_15;
if ( ! ( V_227 . V_296 & V_297 ) ) {
V_227 . V_229 ++ ;
continue;
}
if ( V_191 && V_191 != V_227 . V_298 ) {
V_294 = true ;
break;
}
V_191 = V_227 . V_298 + V_227 . V_230 ;
V_227 . V_229 += V_227 . V_230 ;
}
if ( ! V_294 )
goto V_15;
V_227 . V_229 = V_186 ;
V_227 . V_230 = V_187 - V_186 ;
V_293 = ( V_227 . V_230 + F_267 ( V_10 ) - 1 ) / F_267 ( V_10 ) ;
if ( F_268 ( V_10 , 0 , V_293 ) ) {
V_6 = - V_299 ;
goto V_15;
}
while ( V_227 . V_229 < V_187 ) {
T_2 V_225 ;
int V_300 = 0 ;
V_301:
V_227 . V_230 = V_187 - V_227 . V_229 ;
V_6 = V_226 ( V_3 , & V_227 , 0 , V_295 ) ;
if ( V_6 )
goto V_302;
if ( ! ( V_227 . V_296 & V_297 ) ) {
V_227 . V_229 ++ ;
continue;
}
F_66 ( V_3 , V_303 ) ;
V_225 = V_227 . V_229 ;
while ( V_225 < V_227 . V_229 + V_227 . V_230 && V_300 < V_291 ) {
struct V_8 * V_8 ;
V_8 = F_128 ( V_3 , V_225 , true ) ;
if ( F_129 ( V_8 ) ) {
V_6 = F_130 ( V_8 ) ;
goto V_302;
}
F_27 ( V_8 ) ;
F_55 ( V_8 , 1 ) ;
V_225 ++ ;
V_300 ++ ;
V_292 ++ ;
}
V_227 . V_229 = V_225 ;
if ( V_225 < V_187 && V_300 < V_291 )
goto V_301;
F_68 ( V_3 , V_303 ) ;
V_6 = F_206 ( V_3 -> V_18 ) ;
if ( V_6 )
goto V_15;
}
V_302:
F_68 ( V_3 , V_303 ) ;
V_15:
F_95 ( V_3 ) ;
if ( ! V_6 )
V_272 -> V_116 = ( T_5 ) V_292 << V_23 ;
return V_6 ;
}
static int F_269 ( struct V_47 * V_106 , unsigned long V_246 )
{
struct V_3 * V_3 = F_2 ( V_106 ) ;
struct V_9 * V_10 = F_8 ( V_3 ) ;
struct V_288 V_272 ;
int V_6 ;
if ( ! F_153 ( V_261 ) )
return - V_110 ;
if ( ! F_44 ( V_3 -> V_35 ) || F_202 ( V_3 ) )
return - V_102 ;
if ( F_62 ( V_10 -> V_256 ) )
return - V_281 ;
if ( F_241 ( & V_272 , (struct V_288 V_247 * ) V_246 ,
sizeof( V_272 ) ) )
return - V_19 ;
if ( V_272 . V_48 & ( V_28 - 1 ) || V_272 . V_116 & ( V_28 - 1 ) )
return - V_102 ;
if ( F_20 ( ( V_272 . V_48 + V_272 . V_116 ) >> V_23 >
V_10 -> V_132 ) )
return - V_102 ;
V_6 = F_217 ( V_106 ) ;
if ( V_6 )
return V_6 ;
V_6 = F_264 ( V_10 , V_106 , & V_272 ) ;
F_218 ( V_106 ) ;
F_35 ( V_10 , V_31 ) ;
if ( V_6 < 0 )
return V_6 ;
if ( F_245 ( (struct V_288 V_247 * ) V_246 , & V_272 ,
sizeof( V_272 ) ) )
return - V_19 ;
return 0 ;
}
static int F_270 ( struct V_47 * V_304 , V_22 V_305 ,
struct V_47 * V_306 , V_22 V_307 , T_8 V_116 )
{
struct V_3 * V_202 = F_2 ( V_304 ) ;
struct V_3 * V_203 = F_2 ( V_306 ) ;
struct V_9 * V_10 = F_8 ( V_202 ) ;
T_8 V_215 = V_116 , V_308 = 0 ;
T_8 V_309 ;
int V_43 ;
if ( V_304 -> V_310 . V_311 != V_306 -> V_310 . V_311 ||
V_202 -> V_13 != V_203 -> V_13 )
return - V_312 ;
if ( F_20 ( F_62 ( V_202 -> V_13 ) ) )
return - V_281 ;
if ( ! F_44 ( V_202 -> V_35 ) || ! F_44 ( V_203 -> V_35 ) )
return - V_102 ;
if ( F_103 ( V_202 ) || F_103 ( V_203 ) )
return - V_235 ;
if ( V_202 == V_203 ) {
if ( V_305 == V_307 )
return 0 ;
if ( V_307 > V_305 && V_307 < V_305 + V_116 )
return - V_102 ;
}
F_89 ( V_202 ) ;
if ( V_202 != V_203 ) {
if ( ! F_271 ( V_203 ) ) {
V_43 = - V_283 ;
goto V_15;
}
}
V_43 = - V_102 ;
if ( V_305 + V_116 > V_202 -> V_211 || V_305 + V_116 < V_305 )
goto V_313;
if ( V_116 == 0 )
V_215 = V_116 = V_202 -> V_211 - V_305 ;
if ( V_305 + V_116 == V_202 -> V_211 )
V_116 = F_272 ( V_202 -> V_211 , V_28 ) - V_305 ;
if ( V_116 == 0 ) {
V_43 = 0 ;
goto V_313;
}
V_309 = V_203 -> V_211 ;
if ( V_307 + V_215 > V_203 -> V_211 )
V_308 = V_307 + V_215 ;
if ( ! F_273 ( V_305 , V_28 ) ||
! F_273 ( V_305 + V_116 , V_28 ) ||
! F_273 ( V_307 , V_28 ) )
goto V_313;
V_43 = F_100 ( V_202 ) ;
if ( V_43 )
goto V_313;
V_43 = F_100 ( V_203 ) ;
if ( V_43 )
goto V_313;
V_43 = F_187 ( V_202 -> V_18 ,
V_305 , V_305 + V_116 ) ;
if ( V_43 )
goto V_313;
V_43 = F_187 ( V_203 -> V_18 ,
V_307 , V_307 + V_116 ) ;
if ( V_43 )
goto V_313;
F_17 ( V_10 , true ) ;
F_12 ( V_10 ) ;
V_43 = F_181 ( V_202 , V_203 , V_305 >> V_314 ,
V_307 >> V_314 ,
V_116 >> V_314 , false ) ;
if ( ! V_43 ) {
if ( V_308 )
F_179 ( V_203 , V_308 ) ;
else if ( V_309 != V_203 -> V_211 )
F_179 ( V_203 , V_309 ) ;
}
F_15 ( V_10 ) ;
V_313:
if ( V_202 != V_203 )
F_95 ( V_203 ) ;
V_15:
F_95 ( V_202 ) ;
return V_43 ;
}
static int F_274 ( struct V_47 * V_106 , unsigned long V_246 )
{
struct V_315 V_272 ;
struct V_316 V_203 ;
int V_6 ;
if ( ! ( V_106 -> V_238 & V_317 ) ||
! ( V_106 -> V_238 & V_239 ) )
return - V_318 ;
if ( F_241 ( & V_272 , (struct V_315 V_247 * ) V_246 ,
sizeof( V_272 ) ) )
return - V_19 ;
V_203 = F_275 ( V_272 . V_319 ) ;
if ( ! V_203 . V_47 )
return - V_318 ;
if ( ! ( V_203 . V_47 -> V_238 & V_239 ) ) {
V_6 = - V_318 ;
goto V_258;
}
V_6 = F_217 ( V_106 ) ;
if ( V_6 )
goto V_258;
V_6 = F_270 ( V_106 , V_272 . V_305 , V_203 . V_47 ,
V_272 . V_307 , V_272 . V_116 ) ;
F_218 ( V_106 ) ;
if ( V_6 )
goto V_258;
if ( F_245 ( (struct V_315 V_247 * ) V_246 ,
& V_272 , sizeof( V_272 ) ) )
V_6 = - V_19 ;
V_258:
F_276 ( V_203 ) ;
return V_6 ;
}
static int F_277 ( struct V_47 * V_106 , unsigned long V_246 )
{
struct V_3 * V_3 = F_2 ( V_106 ) ;
struct V_9 * V_10 = F_8 ( V_3 ) ;
struct V_320 * V_321 = F_278 ( V_10 ) ;
unsigned int V_322 = 0 , V_323 = 0 ;
unsigned int V_324 = 0 , V_325 = 0 ;
struct V_326 V_272 ;
int V_43 ;
if ( ! F_153 ( V_261 ) )
return - V_110 ;
if ( F_62 ( V_10 -> V_256 ) )
return - V_281 ;
if ( F_241 ( & V_272 , (struct V_326 V_247 * ) V_246 ,
sizeof( V_272 ) ) )
return - V_19 ;
if ( V_10 -> V_327 <= 1 || V_10 -> V_327 - 1 <= V_272 . V_328 ||
V_10 -> V_329 != 1 ) {
F_221 ( V_10 -> V_256 , V_257 ,
L_2 ,
V_272 . V_328 , V_10 -> V_327 ,
V_10 -> V_329 ) ;
return - V_102 ;
}
V_43 = F_217 ( V_106 ) ;
if ( V_43 )
return V_43 ;
if ( V_272 . V_328 != 0 )
V_324 = F_262 ( V_10 , F_279 ( V_272 . V_328 ) . V_330 ) ;
V_325 = F_262 ( V_10 , F_279 ( V_272 . V_328 ) . V_331 ) ;
V_322 = V_321 -> V_332 [ V_333 ] ;
if ( V_322 < V_324 || V_322 >= V_325 )
V_322 = V_324 ;
V_323 = F_168 ( V_322 + V_272 . V_334 , V_325 ) ;
while ( V_322 < V_323 ) {
if ( ! F_256 ( & V_10 -> V_282 ) ) {
V_43 = - V_283 ;
goto V_15;
}
V_321 -> V_332 [ V_335 ] = V_323 + 1 ;
V_321 -> V_332 [ V_336 ] = V_323 + 1 ;
V_321 -> V_332 [ V_337 ] = V_323 + 1 ;
V_43 = F_258 ( V_10 , true , true , V_322 ) ;
if ( V_43 == - V_299 )
V_43 = 0 ;
else if ( V_43 < 0 )
break;
V_322 ++ ;
}
V_15:
F_218 ( V_106 ) ;
return V_43 ;
}
static int F_280 ( struct V_47 * V_106 , unsigned long V_246 )
{
struct V_3 * V_3 = F_2 ( V_106 ) ;
T_6 V_338 = F_117 ( F_8 ( V_3 ) -> V_277 -> V_339 ) ;
V_338 |= V_340 ;
return F_209 ( V_338 , ( T_6 V_247 * ) V_246 ) ;
}
static int F_281 ( struct V_47 * V_106 , T_11 V_341 )
{
struct V_3 * V_3 = F_2 ( V_106 ) ;
struct V_44 * V_45 = F_4 ( V_3 ) ;
struct V_9 * V_10 = F_8 ( V_3 ) ;
struct V_259 * V_256 = V_10 -> V_256 ;
struct V_342 * V_343 [ V_344 ] = {} ;
struct V_8 * V_130 ;
T_13 V_345 ;
int V_6 ;
if ( ! F_282 ( V_256 ) ) {
if ( V_341 != V_346 )
return - V_235 ;
else
return 0 ;
}
if ( ! F_113 ( V_3 ) )
return - V_235 ;
V_345 = F_283 ( & V_347 , ( V_348 ) V_341 ) ;
if ( F_284 ( V_345 , F_4 ( V_3 ) -> V_349 ) )
return 0 ;
V_6 = F_217 ( V_106 ) ;
if ( V_6 )
return V_6 ;
V_6 = - V_110 ;
F_89 ( V_3 ) ;
if ( F_211 ( V_3 ) )
goto V_313;
V_130 = F_135 ( V_10 , V_3 -> V_54 ) ;
if ( F_129 ( V_130 ) ) {
V_6 = F_130 ( V_130 ) ;
goto V_313;
}
if ( ! F_285 ( F_286 ( V_130 ) , V_45 -> V_350 ,
V_349 ) ) {
V_6 = - V_351 ;
F_55 ( V_130 , 1 ) ;
goto V_313;
}
F_55 ( V_130 , 1 ) ;
F_158 ( V_3 ) ;
V_343 [ V_352 ] = F_287 ( V_256 , F_288 ( V_345 ) ) ;
if ( ! F_129 ( V_343 [ V_352 ] ) ) {
V_6 = F_289 ( V_3 , V_343 ) ;
F_290 ( V_343 [ V_352 ] ) ;
if ( V_6 )
goto V_353;
}
F_4 ( V_3 ) -> V_349 = V_345 ;
V_3 -> V_138 = F_147 ( V_3 ) ;
V_353:
F_77 ( V_3 , true ) ;
V_313:
F_95 ( V_3 ) ;
F_218 ( V_106 ) ;
return V_6 ;
}
static int F_281 ( struct V_47 * V_106 , T_11 V_341 )
{
if ( V_341 != V_346 )
return - V_235 ;
return 0 ;
}
static inline T_11 F_291 ( unsigned long V_354 )
{
T_11 V_355 = 0 ;
if ( V_354 & V_356 )
V_355 |= V_357 ;
if ( V_354 & V_154 )
V_355 |= V_358 ;
if ( V_354 & V_148 )
V_355 |= V_359 ;
if ( V_354 & V_156 )
V_355 |= V_360 ;
if ( V_354 & V_361 )
V_355 |= V_362 ;
if ( V_354 & V_147 )
V_355 |= V_363 ;
return V_355 ;
}
static inline unsigned long F_292 ( T_11 V_355 )
{
unsigned long V_354 = 0 ;
if ( V_355 & V_357 )
V_354 |= V_356 ;
if ( V_355 & V_358 )
V_354 |= V_154 ;
if ( V_355 & V_359 )
V_354 |= V_148 ;
if ( V_355 & V_360 )
V_354 |= V_156 ;
if ( V_355 & V_362 )
V_354 |= V_361 ;
if ( V_355 & V_363 )
V_354 |= V_147 ;
return V_354 ;
}
static int F_293 ( struct V_47 * V_106 , unsigned long V_246 )
{
struct V_3 * V_3 = F_2 ( V_106 ) ;
struct V_44 * V_45 = F_4 ( V_3 ) ;
struct V_364 V_365 ;
memset ( & V_365 , 0 , sizeof( struct V_364 ) ) ;
V_365 . V_366 = F_291 ( V_45 -> V_145 &
( V_146 | V_147 ) ) ;
if ( F_282 ( V_3 -> V_13 ) )
V_365 . V_367 = ( T_11 ) F_294 ( & V_347 ,
V_45 -> V_349 ) ;
if ( F_245 ( (struct V_364 V_247 * ) V_246 , & V_365 , sizeof( V_365 ) ) )
return - V_19 ;
return 0 ;
}
static int F_295 ( struct V_47 * V_106 , unsigned long V_246 )
{
struct V_3 * V_3 = F_2 ( V_106 ) ;
struct V_44 * V_45 = F_4 ( V_3 ) ;
struct V_364 V_365 ;
unsigned int V_144 ;
int V_6 ;
if ( F_241 ( & V_365 , (struct V_364 V_247 * ) V_246 , sizeof( V_365 ) ) )
return - V_19 ;
if ( ! F_215 ( V_3 ) )
return - V_108 ;
if ( V_365 . V_366 & ~ V_368 )
return - V_235 ;
V_144 = F_292 ( V_365 . V_366 ) ;
if ( F_212 ( V_3 -> V_35 , V_144 ) != V_144 )
return - V_235 ;
V_6 = F_217 ( V_106 ) ;
if ( V_6 )
return V_6 ;
F_89 ( V_3 ) ;
V_144 = ( V_45 -> V_145 & ~ V_369 ) |
( V_144 & V_369 ) ;
V_6 = F_210 ( V_3 , V_144 ) ;
F_95 ( V_3 ) ;
F_218 ( V_106 ) ;
if ( V_6 )
return V_6 ;
V_6 = F_281 ( V_106 , V_365 . V_367 ) ;
if ( V_6 )
return V_6 ;
return 0 ;
}
long F_296 ( struct V_47 * V_106 , unsigned int V_370 , unsigned long V_246 )
{
switch ( V_370 ) {
case V_371 :
return F_208 ( V_106 , V_246 ) ;
case V_372 :
return F_214 ( V_106 , V_246 ) ;
case V_373 :
return F_219 ( V_106 , V_246 ) ;
case V_374 :
return F_220 ( V_106 ) ;
case V_375 :
return F_224 ( V_106 ) ;
case V_376 :
return F_227 ( V_106 ) ;
case V_377 :
return F_230 ( V_106 ) ;
case V_378 :
return F_232 ( V_106 ) ;
case V_379 :
return F_233 ( V_106 , V_246 ) ;
case V_380 :
return F_238 ( V_106 , V_246 ) ;
case V_381 :
return F_247 ( V_106 , V_246 ) ;
case V_382 :
return F_249 ( V_106 , V_246 ) ;
case V_383 :
return F_251 ( V_106 , V_246 ) ;
case V_384 :
return F_255 ( V_106 , V_246 ) ;
case V_385 :
return F_259 ( V_106 , V_246 ) ;
case V_386 :
return F_263 ( V_106 , V_246 ) ;
case V_387 :
return F_269 ( V_106 , V_246 ) ;
case V_388 :
return F_274 ( V_106 , V_246 ) ;
case V_389 :
return F_277 ( V_106 , V_246 ) ;
case V_390 :
return F_280 ( V_106 , V_246 ) ;
case V_391 :
return F_293 ( V_106 , V_246 ) ;
case V_392 :
return F_295 ( V_106 , V_246 ) ;
default:
return - V_393 ;
}
}
static T_14 F_297 ( struct V_394 * V_395 , struct V_396 * V_123 )
{
struct V_47 * V_47 = V_395 -> V_397 ;
struct V_3 * V_3 = F_2 ( V_47 ) ;
struct V_398 V_399 ;
T_14 V_43 ;
F_89 ( V_3 ) ;
V_43 = F_298 ( V_395 , V_123 ) ;
if ( V_43 > 0 ) {
int V_6 ;
if ( F_299 ( V_123 , F_300 ( V_123 ) ) )
F_66 ( V_3 , V_400 ) ;
V_6 = F_301 ( V_395 , V_123 ) ;
if ( V_6 ) {
F_95 ( V_3 ) ;
return V_6 ;
}
F_302 ( & V_399 ) ;
V_43 = F_303 ( V_395 , V_123 ) ;
F_304 ( & V_399 ) ;
F_68 ( V_3 , V_400 ) ;
if ( V_43 > 0 )
F_29 ( F_8 ( V_3 ) , V_401 , V_43 ) ;
}
F_95 ( V_3 ) ;
if ( V_43 > 0 )
V_43 = F_305 ( V_395 , V_43 ) ;
return V_43 ;
}
long F_306 ( struct V_47 * V_47 , unsigned int V_370 , unsigned long V_246 )
{
switch ( V_370 ) {
case V_402 :
V_370 = V_371 ;
break;
case V_403 :
V_370 = V_372 ;
break;
case V_404 :
V_370 = V_373 ;
break;
case V_374 :
case V_375 :
case V_376 :
case V_377 :
case V_378 :
case V_379 :
case V_381 :
case V_383 :
case V_382 :
case V_384 :
case V_385 :
case V_386 :
case V_387 :
case V_388 :
case V_389 :
case V_390 :
case V_391 :
case V_392 :
break;
default:
return - V_405 ;
}
return F_296 ( V_47 , V_370 , ( unsigned long ) F_307 ( V_246 ) ) ;
}
