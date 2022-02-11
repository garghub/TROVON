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
F_29 ( V_8 , V_27 ) ;
V_21:
F_30 ( V_8 , V_27 , false ) ;
if ( F_31 ( V_3 ) && F_32 ( V_3 -> V_28 ) )
F_33 ( V_10 , V_12 . V_29 ) ;
V_20:
F_6 ( & F_4 ( V_3 ) -> V_7 ) ;
V_15:
F_34 ( V_3 -> V_13 ) ;
F_35 ( V_10 , V_30 ) ;
return F_36 ( V_6 ) ;
}
static int F_37 ( struct V_3 * V_3 , T_1 * V_31 )
{
struct V_32 * V_32 ;
V_3 = F_38 ( V_3 ) ;
V_32 = F_39 ( V_3 ) ;
F_40 ( V_3 ) ;
if ( ! V_32 )
return 0 ;
* V_31 = F_41 ( V_32 ) ;
F_42 ( V_32 ) ;
return 1 ;
}
static inline bool F_43 ( struct V_3 * V_3 )
{
struct V_9 * V_10 = F_8 ( V_3 ) ;
bool V_33 = false ;
if ( ! F_32 ( V_3 -> V_28 ) || V_3 -> V_34 != 1 )
V_33 = true ;
else if ( F_44 ( V_10 , V_35 ) )
V_33 = true ;
else if ( F_45 ( V_3 ) )
V_33 = true ;
else if ( ! F_46 ( V_10 ) )
V_33 = true ;
else if ( ! F_47 ( V_10 , F_4 ( V_3 ) -> V_36 ) )
V_33 = true ;
else if ( F_48 ( V_10 , V_37 ) )
V_33 = true ;
else if ( V_10 -> V_38 == 2 )
V_33 = true ;
return V_33 ;
}
static bool F_49 ( struct V_9 * V_10 , T_1 V_39 )
{
struct V_8 * V_40 = F_50 ( F_51 ( V_10 ) , V_39 ) ;
bool V_41 = false ;
if ( ( V_40 && F_52 ( V_40 ) ) || F_53 ( V_10 , V_39 ) )
V_41 = true ;
F_54 ( V_40 , 0 ) ;
return V_41 ;
}
static void F_55 ( struct V_3 * V_3 )
{
struct V_42 * V_43 = F_4 ( V_3 ) ;
T_1 V_31 ;
F_56 ( & V_43 -> V_44 ) ;
if ( F_45 ( V_3 ) && V_3 -> V_34 == 1 &&
F_37 ( V_3 , & V_31 ) ) {
F_57 ( V_3 , V_31 ) ;
F_58 ( V_3 ) ;
}
F_59 ( & V_43 -> V_44 ) ;
}
static int F_60 ( struct V_45 * V_45 , V_22 V_46 , V_22 V_47 ,
int V_48 , bool V_49 )
{
struct V_3 * V_3 = V_45 -> V_50 -> V_51 ;
struct V_9 * V_10 = F_8 ( V_3 ) ;
T_1 V_39 = V_3 -> V_52 ;
int V_41 = 0 ;
bool V_33 = false ;
struct V_53 V_54 = {
. V_55 = V_56 ,
. V_57 = V_58 ,
. V_59 = 0 ,
} ;
if ( F_20 ( F_61 ( V_3 -> V_13 ) ) )
return 0 ;
F_62 ( V_3 ) ;
if ( V_48 || F_63 ( V_3 ) <= F_64 ( V_10 ) -> V_60 )
F_65 ( V_3 , V_61 ) ;
V_41 = F_66 ( V_3 -> V_18 , V_46 , V_47 ) ;
F_67 ( V_3 , V_61 ) ;
if ( V_41 ) {
F_68 ( V_3 , V_33 , V_48 , V_41 ) ;
return V_41 ;
}
if ( ! F_69 ( V_3 , V_48 ) ) {
F_70 ( V_3 , NULL ) ;
goto V_62;
}
if ( ! F_71 ( V_3 , V_63 ) &&
! F_72 ( V_10 , V_39 , V_64 ) ) {
if ( F_49 ( V_10 , V_39 ) )
goto V_62;
if ( F_71 ( V_3 , V_65 ) ||
F_72 ( V_10 , V_39 , V_66 ) )
goto V_67;
goto V_15;
}
V_62:
F_3 ( & F_4 ( V_3 ) -> V_44 ) ;
V_33 = F_43 ( V_3 ) ;
F_6 ( & F_4 ( V_3 ) -> V_44 ) ;
if ( V_33 ) {
V_41 = F_73 ( V_3 -> V_13 , 1 ) ;
F_55 ( V_3 ) ;
F_67 ( V_3 , V_63 ) ;
F_67 ( V_3 , V_65 ) ;
goto V_15;
}
V_68:
V_41 = F_74 ( V_10 , V_3 , & V_54 , V_49 ) ;
if ( V_41 )
goto V_15;
if ( F_20 ( F_75 ( V_10 ) ) ) {
V_41 = - V_69 ;
goto V_15;
}
if ( F_53 ( V_10 , V_39 ) ) {
F_76 ( V_3 , true ) ;
F_70 ( V_3 , NULL ) ;
goto V_68;
}
V_41 = F_77 ( V_10 , V_39 ) ;
if ( V_41 )
goto V_15;
F_78 ( V_10 , V_39 , V_64 ) ;
F_67 ( V_3 , V_63 ) ;
V_67:
F_78 ( V_10 , V_39 , V_66 ) ;
F_67 ( V_3 , V_65 ) ;
if ( ! V_49 )
V_41 = F_79 ( V_10 ) ;
F_35 ( V_10 , V_30 ) ;
V_15:
F_68 ( V_3 , V_33 , V_48 , V_41 ) ;
F_80 ( NULL , 1 ) ;
return V_41 ;
}
int F_81 ( struct V_45 * V_45 , V_22 V_46 , V_22 V_47 , int V_48 )
{
return F_60 ( V_45 , V_46 , V_47 , V_48 , false ) ;
}
static T_2 F_82 ( struct V_70 * V_17 ,
T_2 V_71 , int V_72 )
{
struct V_73 V_74 ;
int V_75 ;
if ( V_72 != V_76 )
return 0 ;
F_83 ( & V_74 , 0 ) ;
V_75 = F_84 ( & V_74 , V_17 , & V_71 ,
V_77 , 1 ) ;
V_71 = V_75 ? V_74 . V_78 [ 0 ] -> V_14 : V_79 ;
F_85 ( & V_74 ) ;
return V_71 ;
}
static bool F_86 ( T_3 V_80 , T_2 V_81 , T_2 V_71 ,
int V_72 )
{
switch ( V_72 ) {
case V_76 :
if ( ( V_80 == V_82 && V_81 == V_71 ) ||
( V_80 != V_82 && V_80 != V_83 ) )
return true ;
break;
case V_84 :
if ( V_80 == V_83 )
return true ;
break;
}
return false ;
}
static V_22 F_87 ( struct V_45 * V_45 , V_22 V_24 , int V_72 )
{
struct V_3 * V_3 = V_45 -> V_50 -> V_51 ;
V_22 V_85 = V_3 -> V_13 -> V_86 ;
struct V_11 V_12 ;
T_2 V_71 , V_87 , V_81 ;
V_22 V_88 = V_24 ;
V_22 V_89 ;
int V_6 = 0 ;
F_88 ( V_3 ) ;
V_89 = F_22 ( V_3 ) ;
if ( V_24 >= V_89 )
goto V_90;
if ( F_11 ( V_3 ) || F_89 ( V_3 ) ) {
if ( V_72 == V_84 )
V_88 = V_89 ;
goto V_91;
}
V_71 = ( T_2 ) ( V_24 >> V_23 ) ;
V_81 = F_82 ( V_3 -> V_18 , V_71 , V_72 ) ;
for (; V_88 < V_89 ; V_88 = ( V_22 ) V_71 << V_23 ) {
F_13 ( & V_12 , V_3 , NULL , NULL , 0 ) ;
V_6 = F_90 ( & V_12 , V_71 , V_92 ) ;
if ( V_6 && V_6 != - V_93 ) {
goto V_90;
} else if ( V_6 == - V_93 ) {
if ( V_72 == V_76 ) {
V_71 = F_91 ( & V_12 , V_71 ) ;
continue;
} else {
goto V_91;
}
}
V_87 = F_92 ( V_12 . V_94 , V_3 ) ;
for (; V_12 . V_95 < V_87 ;
V_12 . V_95 ++ , V_71 ++ ,
V_88 = ( V_22 ) V_71 << V_23 ) {
T_3 V_80 ;
V_80 = F_93 ( V_12 . V_94 , V_12 . V_95 ) ;
if ( F_86 ( V_80 , V_81 , V_71 , V_72 ) ) {
F_16 ( & V_12 ) ;
goto V_91;
}
}
F_16 ( & V_12 ) ;
}
if ( V_72 == V_76 )
goto V_90;
V_91:
if ( V_72 == V_84 && V_88 > V_89 )
V_88 = V_89 ;
F_94 ( V_3 ) ;
return F_95 ( V_45 , V_88 , V_85 ) ;
V_90:
F_94 ( V_3 ) ;
return - V_96 ;
}
static V_22 F_96 ( struct V_45 * V_45 , V_22 V_24 , int V_72 )
{
struct V_3 * V_3 = V_45 -> V_50 -> V_51 ;
V_22 V_85 = V_3 -> V_13 -> V_86 ;
switch ( V_72 ) {
case V_97 :
case V_98 :
case V_99 :
return F_97 ( V_45 , V_24 , V_72 ,
V_85 , F_22 ( V_3 ) ) ;
case V_76 :
case V_84 :
if ( V_24 < 0 )
return - V_96 ;
return F_87 ( V_45 , V_24 , V_72 ) ;
}
return - V_100 ;
}
static int F_98 ( struct V_45 * V_45 , struct V_101 * V_4 )
{
struct V_3 * V_3 = F_2 ( V_45 ) ;
int V_6 ;
V_6 = F_99 ( V_3 ) ;
if ( V_6 )
return V_6 ;
F_100 ( V_45 ) ;
V_4 -> V_102 = & V_103 ;
return 0 ;
}
static int F_101 ( struct V_3 * V_3 , struct V_45 * V_104 )
{
struct V_32 * V_105 ;
if ( F_31 ( V_3 ) ) {
int V_41 = F_102 ( V_3 ) ;
if ( V_41 )
return - V_106 ;
if ( ! F_103 ( V_3 ) )
return - V_107 ;
}
V_105 = F_104 ( F_105 ( V_104 ) ) ;
if ( F_31 ( F_106 ( V_105 ) ) &&
! F_107 ( F_106 ( V_105 ) , V_3 ) ) {
F_42 ( V_105 ) ;
return - V_108 ;
}
F_42 ( V_105 ) ;
return F_108 ( V_3 , V_104 ) ;
}
int F_109 ( struct V_11 * V_12 , int V_109 )
{
struct V_9 * V_10 = F_8 ( V_12 -> V_3 ) ;
struct V_110 * V_111 ;
int V_112 = 0 , V_113 = V_12 -> V_95 , V_114 = V_109 ;
T_4 * V_115 ;
V_111 = F_110 ( V_12 -> V_94 ) ;
V_115 = F_111 ( V_111 ) + V_113 ;
for (; V_109 > 0 ; V_109 -- , V_115 ++ , V_12 -> V_95 ++ ) {
T_3 V_80 = F_112 ( * V_115 ) ;
if ( V_80 == V_83 )
continue;
V_12 -> V_29 = V_83 ;
F_113 ( V_12 ) ;
F_114 ( V_10 , V_80 ) ;
if ( V_12 -> V_95 == 0 && F_115 ( V_12 -> V_94 ) )
F_67 ( V_12 -> V_3 , V_116 ) ;
V_112 ++ ;
}
if ( V_112 ) {
T_2 V_117 ;
V_117 = F_116 ( F_117 ( V_12 -> V_94 ) ,
V_12 -> V_3 ) + V_113 ;
F_118 ( V_12 , V_117 , 0 , V_114 ) ;
F_119 ( V_10 , V_12 -> V_3 , V_112 ) ;
}
V_12 -> V_95 = V_113 ;
F_35 ( V_10 , V_30 ) ;
F_120 ( V_12 -> V_3 , V_12 -> V_118 ,
V_12 -> V_95 , V_112 ) ;
return V_112 ;
}
void F_121 ( struct V_11 * V_12 )
{
F_109 ( V_12 , V_119 ) ;
}
static int F_122 ( struct V_3 * V_3 , T_5 V_120 ,
bool V_121 )
{
unsigned V_24 = V_120 & ( V_26 - 1 ) ;
T_2 V_14 = V_120 >> V_23 ;
struct V_70 * V_17 = V_3 -> V_18 ;
struct V_8 * V_8 ;
if ( ! V_24 && ! V_121 )
return 0 ;
if ( V_121 ) {
V_8 = F_123 ( V_17 , V_14 ) ;
if ( V_8 && F_23 ( V_8 ) )
goto V_122;
F_54 ( V_8 , 1 ) ;
return 0 ;
}
V_8 = F_124 ( V_3 , V_14 , true ) ;
if ( F_125 ( V_8 ) )
return F_126 ( V_8 ) == - V_93 ? 0 : F_126 ( V_8 ) ;
V_122:
F_30 ( V_8 , V_27 , true ) ;
F_127 ( V_8 , V_24 , V_26 - V_24 ) ;
F_10 ( F_8 ( V_3 ) , V_121 && F_31 ( V_3 ) ) ;
if ( ! V_121 )
F_27 ( V_8 ) ;
F_54 ( V_8 , 1 ) ;
return 0 ;
}
int F_128 ( struct V_3 * V_3 , T_5 V_120 , bool V_123 )
{
struct V_9 * V_10 = F_8 ( V_3 ) ;
unsigned int V_124 = V_3 -> V_13 -> V_125 ;
struct V_11 V_12 ;
T_2 V_126 ;
int V_109 = 0 , V_6 = 0 ;
struct V_8 * V_127 ;
bool V_128 = false ;
F_129 ( V_3 , V_120 ) ;
V_126 = ( T_2 ) F_130 ( V_120 + V_124 - 1 ) ;
if ( V_126 >= V_10 -> V_129 )
goto V_130;
if ( V_123 )
F_12 ( V_10 ) ;
V_127 = F_131 ( V_10 , V_3 -> V_52 ) ;
if ( F_125 ( V_127 ) ) {
V_6 = F_126 ( V_127 ) ;
goto V_15;
}
if ( F_11 ( V_3 ) ) {
F_132 ( V_3 , V_127 , V_120 ) ;
F_54 ( V_127 , 1 ) ;
V_128 = true ;
goto V_15;
}
F_13 ( & V_12 , V_3 , V_127 , NULL , 0 ) ;
V_6 = F_90 ( & V_12 , V_126 , V_131 ) ;
if ( V_6 ) {
if ( V_6 == - V_93 )
goto V_132;
goto V_15;
}
V_109 = F_92 ( V_12 . V_94 , V_3 ) ;
V_109 -= V_12 . V_95 ;
F_10 ( V_10 , V_109 < 0 ) ;
if ( V_12 . V_95 || F_115 ( V_12 . V_94 ) ) {
F_109 ( & V_12 , V_109 ) ;
V_126 += V_109 ;
}
F_16 ( & V_12 ) ;
V_132:
V_6 = F_133 ( V_3 , V_126 ) ;
V_15:
if ( V_123 )
F_15 ( V_10 ) ;
V_130:
if ( ! V_6 )
V_6 = F_122 ( V_3 , V_120 , V_128 ) ;
F_134 ( V_3 , V_6 ) ;
return V_6 ;
}
int F_135 ( struct V_3 * V_3 )
{
int V_6 ;
if ( ! ( F_32 ( V_3 -> V_28 ) || F_136 ( V_3 -> V_28 ) ||
F_137 ( V_3 -> V_28 ) ) )
return 0 ;
F_138 ( V_3 ) ;
#ifdef F_139
if ( F_140 ( F_8 ( V_3 ) , V_133 ) ) {
F_141 ( V_133 ) ;
return - V_69 ;
}
#endif
if ( ! F_142 ( V_3 ) ) {
V_6 = F_99 ( V_3 ) ;
if ( V_6 )
return V_6 ;
}
V_6 = F_128 ( V_3 , F_22 ( V_3 ) , true ) ;
if ( V_6 )
return V_6 ;
V_3 -> V_134 = V_3 -> V_135 = F_143 ( V_3 ) ;
F_76 ( V_3 , false ) ;
return 0 ;
}
int F_144 ( const struct V_136 * V_136 , struct V_137 * V_138 ,
T_6 V_139 , unsigned int V_140 )
{
struct V_3 * V_3 = F_106 ( V_136 -> V_32 ) ;
struct V_42 * V_43 = F_4 ( V_3 ) ;
unsigned int V_141 ;
V_141 = V_43 -> V_142 & V_143 ;
if ( V_141 & V_144 )
V_138 -> V_145 |= V_146 ;
if ( V_141 & V_147 )
V_138 -> V_145 |= V_148 ;
if ( F_31 ( V_3 ) )
V_138 -> V_145 |= V_149 ;
if ( V_141 & V_150 )
V_138 -> V_145 |= V_151 ;
if ( V_141 & V_152 )
V_138 -> V_145 |= V_153 ;
V_138 -> V_154 |= ( V_146 |
V_148 |
V_149 |
V_151 |
V_153 ) ;
F_145 ( V_3 , V_138 ) ;
return 0 ;
}
static void F_146 ( struct V_3 * V_3 , const struct V_155 * V_156 )
{
unsigned int V_157 = V_156 -> V_157 ;
if ( V_157 & V_158 )
V_3 -> V_159 = V_156 -> V_160 ;
if ( V_157 & V_161 )
V_3 -> V_162 = V_156 -> V_163 ;
if ( V_157 & V_164 )
V_3 -> V_165 = F_147 ( V_156 -> V_166 ,
V_3 -> V_13 -> V_167 ) ;
if ( V_157 & V_168 )
V_3 -> V_134 = F_147 ( V_156 -> V_169 ,
V_3 -> V_13 -> V_167 ) ;
if ( V_157 & V_170 )
V_3 -> V_135 = F_147 ( V_156 -> V_171 ,
V_3 -> V_13 -> V_167 ) ;
if ( V_157 & V_172 ) {
T_7 V_173 = V_156 -> V_174 ;
if ( ! F_148 ( V_3 -> V_162 ) && ! F_149 ( V_175 ) )
V_173 &= ~ V_176 ;
F_150 ( V_3 , V_173 ) ;
}
}
int F_151 ( struct V_32 * V_32 , struct V_155 * V_156 )
{
struct V_3 * V_3 = F_106 ( V_32 ) ;
int V_6 ;
bool V_177 = false ;
V_6 = F_152 ( V_32 , V_156 ) ;
if ( V_6 )
return V_6 ;
if ( F_153 ( V_3 , V_156 ) ) {
V_6 = F_154 ( V_3 ) ;
if ( V_6 )
return V_6 ;
}
if ( ( V_156 -> V_157 & V_158 &&
! F_155 ( V_156 -> V_160 , V_3 -> V_159 ) ) ||
( V_156 -> V_157 & V_161 &&
! F_156 ( V_156 -> V_163 , V_3 -> V_162 ) ) ) {
V_6 = F_157 ( V_3 , V_156 ) ;
if ( V_6 )
return V_6 ;
}
if ( V_156 -> V_157 & V_178 ) {
if ( F_31 ( V_3 ) ) {
V_6 = F_102 ( V_3 ) ;
if ( V_6 )
return V_6 ;
if ( ! F_103 ( V_3 ) )
return - V_107 ;
}
if ( V_156 -> V_179 <= F_22 ( V_3 ) ) {
F_56 ( & F_4 ( V_3 ) -> V_7 ) ;
F_158 ( V_3 , V_156 -> V_179 ) ;
V_6 = F_135 ( V_3 ) ;
F_59 ( & F_4 ( V_3 ) -> V_7 ) ;
if ( V_6 )
return V_6 ;
} else {
F_56 ( & F_4 ( V_3 ) -> V_7 ) ;
F_158 ( V_3 , V_156 -> V_179 ) ;
F_59 ( & F_4 ( V_3 ) -> V_7 ) ;
if ( ! F_142 ( V_3 ) ) {
V_6 = F_99 ( V_3 ) ;
if ( V_6 )
return V_6 ;
}
V_3 -> V_134 = V_3 -> V_135 = F_143 ( V_3 ) ;
}
V_177 = true ;
}
F_146 ( V_3 , V_156 ) ;
if ( V_156 -> V_157 & V_172 ) {
V_6 = F_159 ( V_3 , F_160 ( V_3 ) ) ;
if ( V_6 || F_71 ( V_3 , V_180 ) ) {
V_3 -> V_28 = F_4 ( V_3 ) -> V_181 ;
F_67 ( V_3 , V_180 ) ;
}
}
F_76 ( V_3 , V_177 ) ;
F_17 ( F_8 ( V_3 ) , true ) ;
return V_6 ;
}
static int F_161 ( struct V_3 * V_3 , T_2 V_14 ,
V_22 V_46 , V_22 V_114 )
{
struct V_9 * V_10 = F_8 ( V_3 ) ;
struct V_8 * V_8 ;
if ( ! V_114 )
return 0 ;
F_17 ( V_10 , true ) ;
F_12 ( V_10 ) ;
V_8 = F_162 ( V_3 , NULL , V_14 , false ) ;
F_15 ( V_10 ) ;
if ( F_125 ( V_8 ) )
return F_126 ( V_8 ) ;
F_30 ( V_8 , V_27 , true ) ;
F_127 ( V_8 , V_46 , V_114 ) ;
F_27 ( V_8 ) ;
F_54 ( V_8 , 1 ) ;
return 0 ;
}
int F_163 ( struct V_3 * V_3 , T_2 V_182 , T_2 V_183 )
{
int V_6 ;
while ( V_182 < V_183 ) {
struct V_11 V_12 ;
T_2 V_87 , V_109 ;
F_13 ( & V_12 , V_3 , NULL , NULL , 0 ) ;
V_6 = F_90 ( & V_12 , V_182 , V_92 ) ;
if ( V_6 ) {
if ( V_6 == - V_93 ) {
V_182 ++ ;
continue;
}
return V_6 ;
}
V_87 = F_92 ( V_12 . V_94 , V_3 ) ;
V_109 = F_164 ( V_87 - V_12 . V_95 , V_183 - V_182 ) ;
F_10 ( F_8 ( V_3 ) , V_109 == 0 || V_109 > V_87 ) ;
F_109 ( & V_12 , V_109 ) ;
F_16 ( & V_12 ) ;
V_182 += V_109 ;
}
return 0 ;
}
static int F_165 ( struct V_3 * V_3 , V_22 V_24 , V_22 V_114 )
{
T_2 V_182 , V_183 ;
V_22 V_184 , V_185 ;
int V_41 ;
V_41 = F_99 ( V_3 ) ;
if ( V_41 )
return V_41 ;
V_182 = ( ( unsigned long long ) V_24 ) >> V_23 ;
V_183 = ( ( unsigned long long ) V_24 + V_114 ) >> V_23 ;
V_184 = V_24 & ( V_26 - 1 ) ;
V_185 = ( V_24 + V_114 ) & ( V_26 - 1 ) ;
if ( V_182 == V_183 ) {
V_41 = F_161 ( V_3 , V_182 , V_184 ,
V_185 - V_184 ) ;
if ( V_41 )
return V_41 ;
} else {
if ( V_184 ) {
V_41 = F_161 ( V_3 , V_182 ++ , V_184 ,
V_26 - V_184 ) ;
if ( V_41 )
return V_41 ;
}
if ( V_185 ) {
V_41 = F_161 ( V_3 , V_183 , 0 , V_185 ) ;
if ( V_41 )
return V_41 ;
}
if ( V_182 < V_183 ) {
struct V_70 * V_17 = V_3 -> V_18 ;
V_22 V_186 , V_187 ;
struct V_9 * V_10 = F_8 ( V_3 ) ;
F_17 ( V_10 , true ) ;
V_186 = ( V_22 ) V_182 << V_23 ;
V_187 = ( V_22 ) V_183 << V_23 ;
F_56 ( & F_4 ( V_3 ) -> V_7 ) ;
F_166 ( V_17 , V_186 ,
V_187 - 1 ) ;
F_12 ( V_10 ) ;
V_41 = F_163 ( V_3 , V_182 , V_183 ) ;
F_15 ( V_10 ) ;
F_59 ( & F_4 ( V_3 ) -> V_7 ) ;
}
}
return V_41 ;
}
static int F_167 ( struct V_3 * V_3 , T_3 * V_80 ,
int * V_188 , T_2 V_189 , T_2 V_114 )
{
struct V_9 * V_10 = F_8 ( V_3 ) ;
struct V_11 V_12 ;
int V_41 , V_190 , V_40 ;
V_191:
F_13 ( & V_12 , V_3 , NULL , NULL , 0 ) ;
V_41 = F_90 ( & V_12 , V_189 , V_131 ) ;
if ( V_41 && V_41 != - V_93 ) {
return V_41 ;
} else if ( V_41 == - V_93 ) {
if ( V_12 . V_192 == 0 )
return - V_93 ;
V_190 = F_164 ( ( T_2 ) V_119 - V_12 . V_95 , V_114 ) ;
V_80 += V_190 ;
V_188 += V_190 ;
goto V_193;
}
V_190 = F_164 ( ( T_2 ) F_92 ( V_12 . V_94 , V_3 ) -
V_12 . V_95 , V_114 ) ;
for ( V_40 = 0 ; V_40 < V_190 ; V_40 ++ , V_80 ++ , V_188 ++ , V_12 . V_95 ++ ) {
* V_80 = F_93 ( V_12 . V_94 , V_12 . V_95 ) ;
if ( ! F_168 ( V_10 , * V_80 ) ) {
if ( F_48 ( V_10 , V_194 ) ) {
F_16 ( & V_12 ) ;
return - V_195 ;
}
F_169 ( & V_12 , V_83 ) ;
* V_188 = 1 ;
}
}
F_16 ( & V_12 ) ;
V_193:
V_114 -= V_190 ;
V_189 += V_190 ;
if ( V_114 )
goto V_191;
return 0 ;
}
static int F_170 ( struct V_3 * V_3 , T_3 * V_80 ,
int * V_188 , T_2 V_189 , int V_114 )
{
struct V_9 * V_10 = F_8 ( V_3 ) ;
struct V_11 V_12 ;
int V_41 , V_40 ;
for ( V_40 = 0 ; V_40 < V_114 ; V_40 ++ , V_188 ++ , V_80 ++ ) {
if ( * V_188 == 0 )
continue;
F_13 ( & V_12 , V_3 , NULL , NULL , 0 ) ;
V_41 = F_90 ( & V_12 , V_189 + V_40 , V_131 ) ;
if ( V_41 ) {
F_119 ( V_10 , V_3 , 1 ) ;
F_114 ( V_10 , * V_80 ) ;
} else {
F_169 ( & V_12 , * V_80 ) ;
}
F_16 ( & V_12 ) ;
}
return 0 ;
}
static int F_171 ( struct V_3 * V_196 , struct V_3 * V_197 ,
T_3 * V_80 , int * V_188 ,
T_2 V_198 , T_2 V_199 , T_2 V_114 , bool V_200 )
{
struct V_9 * V_10 = F_8 ( V_196 ) ;
T_2 V_40 = 0 ;
int V_41 ;
while ( V_40 < V_114 ) {
if ( V_80 [ V_40 ] == V_83 && ! V_200 ) {
V_40 ++ ;
continue;
}
if ( V_188 [ V_40 ] || V_80 [ V_40 ] == V_83 ) {
struct V_11 V_12 ;
struct V_201 V_202 ;
T_8 V_203 ;
T_2 V_204 ;
F_13 ( & V_12 , V_197 , NULL , NULL , 0 ) ;
V_41 = F_90 ( & V_12 , V_199 + V_40 , V_205 ) ;
if ( V_41 )
return V_41 ;
F_172 ( V_10 , V_12 . V_118 , & V_202 ) ;
V_204 = F_164 ( ( T_2 )
F_92 ( V_12 . V_94 , V_197 ) -
V_12 . V_95 , V_114 - V_40 ) ;
do {
V_12 . V_29 = F_93 ( V_12 . V_94 ,
V_12 . V_95 ) ;
F_109 ( & V_12 , 1 ) ;
if ( V_188 [ V_40 ] ) {
F_173 ( V_196 ,
1 , false , false ) ;
F_173 ( V_197 ,
1 , true , false ) ;
F_174 ( V_10 , & V_12 , V_12 . V_29 ,
V_80 [ V_40 ] , V_202 . V_206 , true , false ) ;
V_188 [ V_40 ] = 0 ;
}
V_12 . V_95 ++ ;
V_40 ++ ;
V_203 = ( V_199 + V_40 ) << V_23 ;
if ( V_197 -> V_207 < V_203 )
F_175 ( V_197 , V_203 ) ;
} while ( -- V_204 && ( V_188 [ V_40 ] || V_80 [ V_40 ] == V_83 ) );
F_16 ( & V_12 ) ;
} else {
struct V_8 * V_208 , * V_209 ;
V_208 = F_124 ( V_196 , V_198 + V_40 , true ) ;
if ( F_125 ( V_208 ) )
return F_126 ( V_208 ) ;
V_209 = F_162 ( V_197 , NULL , V_199 + V_40 ,
true ) ;
if ( F_125 ( V_209 ) ) {
F_54 ( V_208 , 1 ) ;
return F_126 ( V_209 ) ;
}
F_176 ( V_208 , V_209 ) ;
F_27 ( V_209 ) ;
F_54 ( V_209 , 1 ) ;
F_54 ( V_208 , 1 ) ;
V_41 = F_163 ( V_196 , V_198 + V_40 , V_198 + V_40 + 1 ) ;
if ( V_41 )
return V_41 ;
V_40 ++ ;
}
}
return 0 ;
}
static int F_177 ( struct V_3 * V_196 ,
struct V_3 * V_197 , T_2 V_198 , T_2 V_199 ,
T_2 V_114 , bool V_200 )
{
T_3 * V_210 ;
int * V_188 ;
T_2 V_211 ;
int V_41 ;
while ( V_114 ) {
V_211 = F_164 ( ( T_2 ) 4 * V_119 , V_114 ) ;
V_210 = F_178 ( sizeof( T_3 ) * V_211 , V_212 ) ;
if ( ! V_210 )
return - V_213 ;
V_188 = F_178 ( sizeof( int ) * V_211 , V_212 ) ;
if ( ! V_188 ) {
F_179 ( V_210 ) ;
return - V_213 ;
}
V_41 = F_167 ( V_196 , V_210 ,
V_188 , V_198 , V_211 ) ;
if ( V_41 )
goto V_214;
V_41 = F_171 ( V_196 , V_197 , V_210 ,
V_188 , V_198 , V_199 , V_211 , V_200 ) ;
if ( V_41 )
goto V_214;
V_198 += V_211 ;
V_199 += V_211 ;
V_114 -= V_211 ;
F_179 ( V_210 ) ;
F_179 ( V_188 ) ;
}
return 0 ;
V_214:
F_170 ( V_196 , V_210 , V_188 , V_198 , V_114 ) ;
F_179 ( V_210 ) ;
F_179 ( V_188 ) ;
return V_41 ;
}
static int F_180 ( struct V_3 * V_3 , T_2 V_46 , T_2 V_47 )
{
struct V_9 * V_10 = F_8 ( V_3 ) ;
T_2 V_215 = ( F_22 ( V_3 ) + V_26 - 1 ) / V_26 ;
int V_41 ;
F_17 ( V_10 , true ) ;
F_12 ( V_10 ) ;
F_181 ( V_3 ) ;
V_41 = F_177 ( V_3 , V_3 , V_47 , V_46 , V_215 - V_47 , true ) ;
F_15 ( V_10 ) ;
return V_41 ;
}
static int F_182 ( struct V_3 * V_3 , V_22 V_24 , V_22 V_114 )
{
T_2 V_182 , V_183 ;
V_22 V_203 ;
int V_41 ;
if ( V_24 + V_114 >= F_22 ( V_3 ) )
return - V_100 ;
if ( V_24 & ( V_216 - 1 ) || V_114 & ( V_216 - 1 ) )
return - V_100 ;
V_41 = F_99 ( V_3 ) ;
if ( V_41 )
return V_41 ;
V_182 = V_24 >> V_23 ;
V_183 = ( V_24 + V_114 ) >> V_23 ;
F_56 ( & F_4 ( V_3 ) -> V_7 ) ;
V_41 = F_66 ( V_3 -> V_18 , V_24 , V_217 ) ;
if ( V_41 )
goto V_15;
F_183 ( V_3 , V_24 ) ;
V_41 = F_180 ( V_3 , V_182 , V_183 ) ;
if ( V_41 )
goto V_15;
F_66 ( V_3 -> V_18 , V_24 , V_217 ) ;
F_183 ( V_3 , V_24 ) ;
V_203 = F_22 ( V_3 ) - V_114 ;
F_183 ( V_3 , V_203 ) ;
V_41 = F_128 ( V_3 , V_203 , true ) ;
if ( ! V_41 )
F_175 ( V_3 , V_203 ) ;
V_15:
F_59 ( & F_4 ( V_3 ) -> V_7 ) ;
return V_41 ;
}
static int F_184 ( struct V_11 * V_12 , T_2 V_46 ,
T_2 V_47 )
{
struct V_9 * V_10 = F_8 ( V_12 -> V_3 ) ;
T_2 V_14 = V_46 ;
unsigned int V_95 = V_12 -> V_95 ;
T_9 V_109 = 0 ;
int V_41 ;
for (; V_14 < V_47 ; V_14 ++ , V_12 -> V_95 ++ ) {
if ( F_93 ( V_12 -> V_94 , V_12 -> V_95 ) == V_83 )
V_109 ++ ;
}
V_12 -> V_95 = V_95 ;
V_41 = F_185 ( V_12 , V_109 ) ;
if ( V_41 )
return V_41 ;
V_12 -> V_95 = V_95 ;
for ( V_14 = V_46 ; V_14 < V_47 ; V_14 ++ , V_12 -> V_95 ++ ) {
V_12 -> V_29 =
F_93 ( V_12 -> V_94 , V_12 -> V_95 ) ;
if ( V_12 -> V_29 == V_83 ) {
V_41 = - V_218 ;
break;
}
if ( V_12 -> V_29 != V_82 ) {
F_114 ( V_10 , V_12 -> V_29 ) ;
V_12 -> V_29 = V_82 ;
F_113 ( V_12 ) ;
}
}
F_118 ( V_12 , V_46 , 0 , V_14 - V_46 ) ;
return V_41 ;
}
static int F_186 ( struct V_3 * V_3 , V_22 V_24 , V_22 V_114 ,
int V_173 )
{
struct V_9 * V_10 = F_8 ( V_3 ) ;
struct V_70 * V_17 = V_3 -> V_18 ;
T_2 V_14 , V_182 , V_183 ;
V_22 V_203 = F_22 ( V_3 ) ;
V_22 V_184 , V_185 ;
int V_41 = 0 ;
V_41 = F_187 ( V_3 , ( V_114 + V_24 ) ) ;
if ( V_41 )
return V_41 ;
V_41 = F_99 ( V_3 ) ;
if ( V_41 )
return V_41 ;
F_56 ( & F_4 ( V_3 ) -> V_7 ) ;
V_41 = F_66 ( V_17 , V_24 , V_24 + V_114 - 1 ) ;
if ( V_41 )
goto V_20;
F_188 ( V_3 , V_24 , V_24 + V_114 - 1 ) ;
V_182 = ( ( unsigned long long ) V_24 ) >> V_23 ;
V_183 = ( ( unsigned long long ) V_24 + V_114 ) >> V_23 ;
V_184 = V_24 & ( V_26 - 1 ) ;
V_185 = ( V_24 + V_114 ) & ( V_26 - 1 ) ;
if ( V_182 == V_183 ) {
V_41 = F_161 ( V_3 , V_182 , V_184 ,
V_185 - V_184 ) ;
if ( V_41 )
goto V_20;
V_203 = F_189 ( V_22 , V_203 , V_24 + V_114 ) ;
} else {
if ( V_184 ) {
V_41 = F_161 ( V_3 , V_182 ++ , V_184 ,
V_26 - V_184 ) ;
if ( V_41 )
goto V_20;
V_203 = F_189 ( V_22 , V_203 ,
( V_22 ) V_182 << V_23 ) ;
}
for ( V_14 = V_182 ; V_14 < V_183 ; ) {
struct V_11 V_12 ;
unsigned int V_87 ;
T_2 V_47 ;
F_12 ( V_10 ) ;
F_13 ( & V_12 , V_3 , NULL , NULL , 0 ) ;
V_41 = F_90 ( & V_12 , V_14 , V_205 ) ;
if ( V_41 ) {
F_15 ( V_10 ) ;
goto V_15;
}
V_87 = F_92 ( V_12 . V_94 , V_3 ) ;
V_47 = F_164 ( V_183 , V_87 - V_12 . V_95 + V_14 ) ;
V_41 = F_184 ( & V_12 , V_14 , V_47 ) ;
F_16 ( & V_12 ) ;
F_15 ( V_10 ) ;
F_17 ( V_10 , V_12 . V_16 ) ;
if ( V_41 )
goto V_15;
V_14 = V_47 ;
V_203 = F_189 ( V_22 , V_203 ,
( V_22 ) V_14 << V_23 ) ;
}
if ( V_185 ) {
V_41 = F_161 ( V_3 , V_183 , 0 , V_185 ) ;
if ( V_41 )
goto V_15;
V_203 = F_189 ( V_22 , V_203 , V_24 + V_114 ) ;
}
}
V_15:
if ( ! ( V_173 & V_219 ) && F_22 ( V_3 ) < V_203 )
F_175 ( V_3 , V_203 ) ;
V_20:
F_59 ( & F_4 ( V_3 ) -> V_7 ) ;
return V_41 ;
}
static int F_190 ( struct V_3 * V_3 , V_22 V_24 , V_22 V_114 )
{
struct V_9 * V_10 = F_8 ( V_3 ) ;
T_2 V_220 , V_182 , V_183 , V_221 , V_222 ;
V_22 V_203 ;
int V_41 = 0 ;
V_203 = F_22 ( V_3 ) + V_114 ;
V_41 = F_187 ( V_3 , V_203 ) ;
if ( V_41 )
return V_41 ;
if ( V_24 >= F_22 ( V_3 ) )
return - V_100 ;
if ( V_24 & ( V_216 - 1 ) || V_114 & ( V_216 - 1 ) )
return - V_100 ;
V_41 = F_99 ( V_3 ) ;
if ( V_41 )
return V_41 ;
F_17 ( V_10 , true ) ;
F_56 ( & F_4 ( V_3 ) -> V_7 ) ;
V_41 = F_128 ( V_3 , F_22 ( V_3 ) , true ) ;
if ( V_41 )
goto V_15;
V_41 = F_66 ( V_3 -> V_18 , V_24 , V_217 ) ;
if ( V_41 )
goto V_15;
F_183 ( V_3 , V_24 ) ;
V_182 = V_24 >> V_23 ;
V_183 = ( V_24 + V_114 ) >> V_23 ;
V_221 = V_183 - V_182 ;
V_222 = ( F_22 ( V_3 ) + V_26 - 1 ) / V_26 ;
while ( ! V_41 && V_222 > V_182 ) {
V_220 = V_222 - V_182 ;
if ( V_220 > V_221 )
V_220 = V_221 ;
V_222 -= V_220 ;
F_12 ( V_10 ) ;
F_181 ( V_3 ) ;
V_41 = F_177 ( V_3 , V_3 , V_222 ,
V_222 + V_221 , V_220 , false ) ;
F_15 ( V_10 ) ;
}
F_66 ( V_3 -> V_18 , V_24 , V_217 ) ;
F_183 ( V_3 , V_24 ) ;
if ( ! V_41 )
F_175 ( V_3 , V_203 ) ;
V_15:
F_59 ( & F_4 ( V_3 ) -> V_7 ) ;
return V_41 ;
}
static int F_191 ( struct V_3 * V_3 , V_22 V_24 ,
V_22 V_114 , int V_173 )
{
struct V_9 * V_10 = F_8 ( V_3 ) ;
struct V_223 V_224 = { . V_225 = NULL } ;
T_2 V_183 ;
V_22 V_203 = F_22 ( V_3 ) ;
V_22 V_185 ;
int V_6 ;
V_6 = F_187 ( V_3 , ( V_114 + V_24 ) ) ;
if ( V_6 )
return V_6 ;
V_6 = F_99 ( V_3 ) ;
if ( V_6 )
return V_6 ;
F_17 ( V_10 , true ) ;
V_183 = ( ( unsigned long long ) V_24 + V_114 ) >> V_23 ;
V_185 = ( V_24 + V_114 ) & ( V_26 - 1 ) ;
V_224 . V_226 = ( ( unsigned long long ) V_24 ) >> V_23 ;
V_224 . V_227 = V_183 - V_224 . V_226 ;
if ( V_185 )
V_224 . V_227 ++ ;
V_6 = V_223 ( V_3 , & V_224 , 1 , V_228 ) ;
if ( V_6 ) {
T_2 V_229 ;
if ( ! V_224 . V_227 )
return V_6 ;
V_229 = V_224 . V_226 + V_224 . V_227 - 1 ;
V_203 = ( V_229 == V_183 ) ? V_24 + V_114 :
( V_22 ) ( V_229 + 1 ) << V_23 ;
} else {
V_203 = ( ( V_22 ) V_183 << V_23 ) + V_185 ;
}
if ( ! ( V_173 & V_219 ) && F_22 ( V_3 ) < V_203 )
F_175 ( V_3 , V_203 ) ;
return V_6 ;
}
static long F_192 ( struct V_45 * V_45 , int V_173 ,
V_22 V_24 , V_22 V_114 )
{
struct V_3 * V_3 = F_2 ( V_45 ) ;
long V_41 = 0 ;
if ( ! F_32 ( V_3 -> V_28 ) )
return - V_100 ;
if ( F_31 ( V_3 ) &&
( V_173 & ( V_230 | V_231 ) ) )
return - V_232 ;
if ( V_173 & ~ ( V_219 | V_233 |
V_230 | V_234 |
V_231 ) )
return - V_232 ;
F_88 ( V_3 ) ;
if ( V_173 & V_233 ) {
if ( V_24 >= V_3 -> V_207 )
goto V_15;
V_41 = F_165 ( V_3 , V_24 , V_114 ) ;
} else if ( V_173 & V_230 ) {
V_41 = F_182 ( V_3 , V_24 , V_114 ) ;
} else if ( V_173 & V_234 ) {
V_41 = F_186 ( V_3 , V_24 , V_114 , V_173 ) ;
} else if ( V_173 & V_231 ) {
V_41 = F_190 ( V_3 , V_24 , V_114 ) ;
} else {
V_41 = F_191 ( V_3 , V_24 , V_114 , V_173 ) ;
}
if ( ! V_41 ) {
V_3 -> V_134 = V_3 -> V_135 = F_143 ( V_3 ) ;
F_76 ( V_3 , false ) ;
if ( V_173 & V_219 )
F_193 ( V_3 ) ;
F_35 ( F_8 ( V_3 ) , V_30 ) ;
}
V_15:
F_94 ( V_3 ) ;
F_194 ( V_3 , V_173 , V_24 , V_114 , V_41 ) ;
return V_41 ;
}
static int F_195 ( struct V_3 * V_3 , struct V_45 * V_104 )
{
if ( ! ( V_104 -> V_235 & V_236 ) ||
F_196 ( & V_3 -> V_237 ) != 1 )
return 0 ;
if ( F_197 ( V_3 ) )
F_198 ( V_3 ) ;
if ( F_199 ( V_3 ) ) {
F_67 ( V_3 , V_238 ) ;
F_200 ( V_3 ) ;
F_65 ( V_3 , V_239 ) ;
F_201 ( V_3 -> V_18 ) ;
F_67 ( V_3 , V_239 ) ;
}
return 0 ;
}
static inline T_10 F_202 ( T_7 V_173 , T_10 V_141 )
{
if ( F_136 ( V_173 ) )
return V_141 ;
else if ( F_32 ( V_173 ) )
return V_141 & V_240 ;
else
return V_141 & V_241 ;
}
static int F_203 ( struct V_45 * V_104 , unsigned long V_242 )
{
struct V_3 * V_3 = F_2 ( V_104 ) ;
struct V_42 * V_43 = F_4 ( V_3 ) ;
unsigned int V_141 = V_43 -> V_142 & V_143 ;
return F_204 ( V_141 , ( int V_243 * ) V_242 ) ;
}
static int F_205 ( struct V_45 * V_104 , unsigned long V_242 )
{
struct V_3 * V_3 = F_2 ( V_104 ) ;
struct V_42 * V_43 = F_4 ( V_3 ) ;
unsigned int V_141 ;
unsigned int V_244 ;
int V_41 ;
if ( ! F_206 ( V_3 ) )
return - V_106 ;
if ( F_207 ( V_141 , ( int V_243 * ) V_242 ) )
return - V_19 ;
V_41 = F_208 ( V_104 ) ;
if ( V_41 )
return V_41 ;
F_88 ( V_3 ) ;
if ( F_209 ( V_3 ) ) {
V_41 = - V_108 ;
goto V_245;
}
V_141 = F_202 ( V_3 -> V_28 , V_141 ) ;
V_244 = V_43 -> V_142 ;
if ( ( V_141 ^ V_244 ) & ( V_144 | V_150 ) ) {
if ( ! F_149 ( V_246 ) ) {
V_41 = - V_108 ;
goto V_245;
}
}
V_141 = V_141 & V_247 ;
V_141 |= V_244 & ~ V_247 ;
V_43 -> V_142 = V_141 ;
V_3 -> V_135 = F_143 ( V_3 ) ;
F_210 ( V_3 ) ;
F_76 ( V_3 , false ) ;
V_245:
F_94 ( V_3 ) ;
F_211 ( V_104 ) ;
return V_41 ;
}
static int F_212 ( struct V_45 * V_104 , unsigned long V_242 )
{
struct V_3 * V_3 = F_2 ( V_104 ) ;
return F_204 ( V_3 -> V_248 , ( int V_243 * ) V_242 ) ;
}
static int F_213 ( struct V_45 * V_104 )
{
struct V_3 * V_3 = F_2 ( V_104 ) ;
int V_41 ;
if ( ! F_206 ( V_3 ) )
return - V_106 ;
if ( ! F_32 ( V_3 -> V_28 ) )
return - V_100 ;
V_41 = F_208 ( V_104 ) ;
if ( V_41 )
return V_41 ;
F_88 ( V_3 ) ;
if ( F_197 ( V_3 ) )
goto V_15;
V_41 = F_99 ( V_3 ) ;
if ( V_41 )
goto V_15;
F_65 ( V_3 , V_249 ) ;
F_65 ( V_3 , V_250 ) ;
F_35 ( F_8 ( V_3 ) , V_30 ) ;
if ( ! F_63 ( V_3 ) )
goto V_251;
F_214 ( F_8 ( V_3 ) -> V_252 , V_253 ,
L_1 ,
V_3 -> V_52 , F_63 ( V_3 ) ) ;
V_41 = F_66 ( V_3 -> V_18 , 0 , V_217 ) ;
if ( V_41 ) {
F_67 ( V_3 , V_249 ) ;
goto V_15;
}
V_251:
F_215 ( V_3 ) ;
F_216 ( V_3 ) ;
V_15:
F_94 ( V_3 ) ;
F_211 ( V_104 ) ;
return V_41 ;
}
static int F_217 ( struct V_45 * V_104 )
{
struct V_3 * V_3 = F_2 ( V_104 ) ;
int V_41 ;
if ( ! F_206 ( V_3 ) )
return - V_106 ;
V_41 = F_208 ( V_104 ) ;
if ( V_41 )
return V_41 ;
F_88 ( V_3 ) ;
if ( F_199 ( V_3 ) )
goto V_254;
if ( F_197 ( V_3 ) ) {
V_41 = F_218 ( V_3 ) ;
if ( V_41 )
goto V_254;
V_41 = F_60 ( V_104 , 0 , V_217 , 0 , true ) ;
if ( ! V_41 ) {
F_67 ( V_3 , V_249 ) ;
F_219 ( V_3 ) ;
}
} else {
V_41 = F_60 ( V_104 , 0 , V_217 , 0 , true ) ;
}
V_254:
F_94 ( V_3 ) ;
F_211 ( V_104 ) ;
return V_41 ;
}
static int F_220 ( struct V_45 * V_104 )
{
struct V_3 * V_3 = F_2 ( V_104 ) ;
int V_41 ;
if ( ! F_206 ( V_3 ) )
return - V_106 ;
if ( ! F_32 ( V_3 -> V_28 ) )
return - V_100 ;
V_41 = F_208 ( V_104 ) ;
if ( V_41 )
return V_41 ;
F_88 ( V_3 ) ;
if ( F_199 ( V_3 ) )
goto V_15;
V_41 = F_99 ( V_3 ) ;
if ( V_41 )
goto V_15;
F_221 ( V_3 ) ;
F_222 ( V_3 ) ;
F_65 ( V_3 , V_238 ) ;
F_35 ( F_8 ( V_3 ) , V_30 ) ;
V_15:
F_94 ( V_3 ) ;
F_211 ( V_104 ) ;
return V_41 ;
}
static int F_223 ( struct V_45 * V_104 )
{
struct V_3 * V_3 = F_2 ( V_104 ) ;
int V_41 ;
if ( ! F_206 ( V_3 ) )
return - V_106 ;
V_41 = F_208 ( V_104 ) ;
if ( V_41 )
return V_41 ;
F_88 ( V_3 ) ;
if ( ! F_199 ( V_3 ) )
goto V_15;
if ( ! F_224 ( V_3 ) ) {
V_41 = F_122 ( V_3 , 0 , true ) ;
goto V_15;
}
V_41 = F_165 ( V_3 , 0 , V_216 ) ;
V_15:
F_94 ( V_3 ) ;
F_211 ( V_104 ) ;
return V_41 ;
}
static int F_225 ( struct V_45 * V_104 )
{
struct V_3 * V_3 = F_2 ( V_104 ) ;
int V_41 ;
if ( ! F_206 ( V_3 ) )
return - V_106 ;
V_41 = F_208 ( V_104 ) ;
if ( V_41 )
return V_41 ;
F_88 ( V_3 ) ;
if ( F_197 ( V_3 ) )
F_198 ( V_3 ) ;
if ( F_199 ( V_3 ) ) {
F_67 ( V_3 , V_238 ) ;
F_200 ( V_3 ) ;
V_41 = F_60 ( V_104 , 0 , V_217 , 0 , true ) ;
}
F_94 ( V_3 ) ;
F_211 ( V_104 ) ;
F_35 ( F_8 ( V_3 ) , V_30 ) ;
return V_41 ;
}
static int F_226 ( struct V_45 * V_104 , unsigned long V_242 )
{
struct V_3 * V_3 = F_2 ( V_104 ) ;
struct V_9 * V_10 = F_8 ( V_3 ) ;
struct V_255 * V_252 = V_10 -> V_252 ;
T_10 V_256 ;
int V_41 ;
if ( ! F_149 ( V_257 ) )
return - V_108 ;
if ( F_207 ( V_256 , ( T_10 V_243 * ) V_242 ) )
return - V_19 ;
V_41 = F_208 ( V_104 ) ;
if ( V_41 )
return V_41 ;
switch ( V_256 ) {
case V_258 :
V_252 = F_227 ( V_252 -> V_259 ) ;
if ( V_252 && ! F_125 ( V_252 ) ) {
F_228 ( V_10 , false ) ;
F_229 ( V_252 -> V_259 , V_252 ) ;
}
break;
case V_260 :
F_73 ( V_252 , 1 ) ;
F_228 ( V_10 , false ) ;
break;
case V_261 :
F_228 ( V_10 , false ) ;
break;
case V_262 :
F_230 ( V_10 , V_263 , V_58 ) ;
F_228 ( V_10 , false ) ;
break;
default:
V_41 = - V_100 ;
goto V_15;
}
F_35 ( V_10 , V_30 ) ;
V_15:
F_211 ( V_104 ) ;
return V_41 ;
}
static int F_231 ( struct V_45 * V_104 , unsigned long V_242 )
{
struct V_3 * V_3 = F_2 ( V_104 ) ;
struct V_255 * V_252 = V_3 -> V_13 ;
struct V_264 * V_265 = F_232 ( V_252 -> V_259 ) ;
struct V_266 V_267 ;
int V_41 ;
if ( ! F_149 ( V_257 ) )
return - V_108 ;
if ( ! F_233 ( V_265 ) )
return - V_232 ;
if ( F_234 ( & V_267 , (struct V_266 V_243 * ) V_242 ,
sizeof( V_267 ) ) )
return - V_19 ;
V_41 = F_208 ( V_104 ) ;
if ( V_41 )
return V_41 ;
V_267 . V_268 = F_235 ( ( unsigned int ) V_267 . V_268 ,
V_265 -> V_269 . V_270 ) ;
V_41 = F_236 ( F_237 ( V_252 ) , & V_267 ) ;
F_211 ( V_104 ) ;
if ( V_41 < 0 )
return V_41 ;
if ( F_238 ( (struct V_266 V_243 * ) V_242 , & V_267 ,
sizeof( V_267 ) ) )
return - V_19 ;
F_35 ( F_8 ( V_3 ) , V_30 ) ;
return 0 ;
}
static bool F_239 ( T_11 V_271 [ 16 ] )
{
int V_40 ;
for ( V_40 = 0 ; V_40 < 16 ; V_40 ++ )
if ( V_271 [ V_40 ] )
return true ;
return false ;
}
static int F_240 ( struct V_45 * V_104 , unsigned long V_242 )
{
struct V_3 * V_3 = F_2 ( V_104 ) ;
F_35 ( F_8 ( V_3 ) , V_30 ) ;
return F_241 ( V_104 , ( const void V_243 * ) V_242 ) ;
}
static int F_242 ( struct V_45 * V_104 , unsigned long V_242 )
{
return F_243 ( V_104 , ( void V_243 * ) V_242 ) ;
}
static int F_244 ( struct V_45 * V_104 , unsigned long V_242 )
{
struct V_3 * V_3 = F_2 ( V_104 ) ;
struct V_9 * V_10 = F_8 ( V_3 ) ;
int V_6 ;
if ( ! F_245 ( V_3 -> V_13 ) )
return - V_232 ;
if ( F_239 ( V_10 -> V_272 -> V_273 ) )
goto V_274;
V_6 = F_208 ( V_104 ) ;
if ( V_6 )
return V_6 ;
F_246 ( V_10 -> V_272 -> V_273 ) ;
V_6 = F_247 ( V_10 , false ) ;
if ( V_6 ) {
memset ( V_10 -> V_272 -> V_273 , 0 , 16 ) ;
F_211 ( V_104 ) ;
return V_6 ;
}
F_211 ( V_104 ) ;
V_274:
if ( F_238 ( ( T_11 V_243 * ) V_242 , V_10 -> V_272 -> V_273 ,
16 ) )
return - V_19 ;
return 0 ;
}
static int F_248 ( struct V_45 * V_104 , unsigned long V_242 )
{
struct V_3 * V_3 = F_2 ( V_104 ) ;
struct V_9 * V_10 = F_8 ( V_3 ) ;
T_10 V_275 ;
int V_41 ;
if ( ! F_149 ( V_257 ) )
return - V_108 ;
if ( F_207 ( V_275 , ( T_10 V_243 * ) V_242 ) )
return - V_19 ;
if ( F_61 ( V_10 -> V_252 ) )
return - V_276 ;
V_41 = F_208 ( V_104 ) ;
if ( V_41 )
return V_41 ;
if ( ! V_275 ) {
if ( ! F_249 ( & V_10 -> V_277 ) ) {
V_41 = - V_278 ;
goto V_15;
}
} else {
F_250 ( & V_10 -> V_277 ) ;
}
V_41 = F_251 ( V_10 , V_275 , true , V_279 ) ;
V_15:
F_211 ( V_104 ) ;
return V_41 ;
}
static int F_252 ( struct V_45 * V_104 , unsigned long V_242 )
{
struct V_3 * V_3 = F_2 ( V_104 ) ;
struct V_9 * V_10 = F_8 ( V_3 ) ;
struct V_280 V_267 ;
T_5 V_47 ;
int V_41 ;
if ( ! F_149 ( V_257 ) )
return - V_108 ;
if ( F_234 ( & V_267 , (struct V_280 V_243 * ) V_242 ,
sizeof( V_267 ) ) )
return - V_19 ;
if ( F_61 ( V_10 -> V_252 ) )
return - V_276 ;
V_41 = F_208 ( V_104 ) ;
if ( V_41 )
return V_41 ;
V_47 = V_267 . V_46 + V_267 . V_114 ;
if ( V_267 . V_46 < F_253 ( V_10 ) || V_47 >= F_254 ( V_10 ) )
return - V_100 ;
V_281:
if ( ! V_267 . V_275 ) {
if ( ! F_249 ( & V_10 -> V_277 ) ) {
V_41 = - V_278 ;
goto V_15;
}
} else {
F_250 ( & V_10 -> V_277 ) ;
}
V_41 = F_251 ( V_10 , V_267 . V_275 , true , F_255 ( V_10 , V_267 . V_46 ) ) ;
V_267 . V_46 += V_10 -> V_282 ;
if ( V_267 . V_46 <= V_47 )
goto V_281;
V_15:
F_211 ( V_104 ) ;
return V_41 ;
}
static int F_256 ( struct V_45 * V_104 , unsigned long V_242 )
{
struct V_3 * V_3 = F_2 ( V_104 ) ;
struct V_9 * V_10 = F_8 ( V_3 ) ;
int V_41 ;
if ( ! F_149 ( V_257 ) )
return - V_108 ;
if ( F_61 ( V_10 -> V_252 ) )
return - V_276 ;
V_41 = F_208 ( V_104 ) ;
if ( V_41 )
return V_41 ;
V_41 = F_73 ( V_10 -> V_252 , 1 ) ;
F_211 ( V_104 ) ;
return V_41 ;
}
static int F_257 ( struct V_9 * V_10 ,
struct V_45 * V_104 ,
struct V_283 * V_267 )
{
struct V_3 * V_3 = F_2 ( V_104 ) ;
struct V_223 V_224 = { . V_225 = NULL } ;
struct V_284 V_285 = { 0 , 0 , 0 } ;
T_2 V_182 , V_183 ;
unsigned int V_286 = V_10 -> V_282 ;
unsigned int V_287 = 0 , V_288 ;
T_3 V_187 = 0 ;
bool V_289 = false ;
int V_6 ;
if ( F_258 ( V_3 , NULL ) )
return - V_100 ;
V_182 = V_267 -> V_46 >> V_23 ;
V_183 = ( V_267 -> V_46 + V_267 -> V_114 ) >> V_23 ;
F_17 ( V_10 , true ) ;
F_88 ( V_3 ) ;
V_6 = F_66 ( V_3 -> V_18 , V_267 -> V_46 ,
V_267 -> V_46 + V_267 -> V_114 - 1 ) ;
if ( V_6 )
goto V_15;
if ( F_259 ( V_3 , V_182 , & V_285 ) ) {
if ( V_285 . V_117 + V_285 . V_114 >= V_183 )
goto V_15;
}
V_224 . V_226 = V_182 ;
while ( V_224 . V_226 < V_183 ) {
V_224 . V_227 = V_183 - V_224 . V_226 ;
V_6 = V_223 ( V_3 , & V_224 , 0 , V_290 ) ;
if ( V_6 )
goto V_15;
if ( ! ( V_224 . V_291 & V_292 ) ) {
V_224 . V_226 ++ ;
continue;
}
if ( V_187 && V_187 != V_224 . V_293 ) {
V_289 = true ;
break;
}
V_187 = V_224 . V_293 + V_224 . V_227 ;
V_224 . V_226 += V_224 . V_227 ;
}
if ( ! V_289 )
goto V_15;
V_224 . V_226 = V_182 ;
V_224 . V_227 = V_183 - V_182 ;
V_288 = ( V_224 . V_227 + F_260 ( V_10 ) - 1 ) / F_260 ( V_10 ) ;
if ( F_261 ( V_10 , 0 , V_288 ) ) {
V_6 = - V_294 ;
goto V_15;
}
while ( V_224 . V_226 < V_183 ) {
T_2 V_222 ;
int V_295 = 0 ;
V_296:
V_224 . V_227 = V_183 - V_224 . V_226 ;
V_6 = V_223 ( V_3 , & V_224 , 0 , V_290 ) ;
if ( V_6 )
goto V_297;
if ( ! ( V_224 . V_291 & V_292 ) ) {
V_224 . V_226 ++ ;
continue;
}
F_65 ( V_3 , V_298 ) ;
V_222 = V_224 . V_226 ;
while ( V_222 < V_224 . V_226 + V_224 . V_227 && V_295 < V_286 ) {
struct V_8 * V_8 ;
V_8 = F_124 ( V_3 , V_222 , true ) ;
if ( F_125 ( V_8 ) ) {
V_6 = F_126 ( V_8 ) ;
goto V_297;
}
F_27 ( V_8 ) ;
F_54 ( V_8 , 1 ) ;
V_222 ++ ;
V_295 ++ ;
V_287 ++ ;
}
V_224 . V_226 = V_222 ;
if ( V_222 < V_183 && V_295 < V_286 )
goto V_296;
F_67 ( V_3 , V_298 ) ;
V_6 = F_201 ( V_3 -> V_18 ) ;
if ( V_6 )
goto V_15;
}
V_297:
F_67 ( V_3 , V_298 ) ;
V_15:
F_94 ( V_3 ) ;
if ( ! V_6 )
V_267 -> V_114 = ( T_5 ) V_287 << V_23 ;
return V_6 ;
}
static int F_262 ( struct V_45 * V_104 , unsigned long V_242 )
{
struct V_3 * V_3 = F_2 ( V_104 ) ;
struct V_9 * V_10 = F_8 ( V_3 ) ;
struct V_283 V_267 ;
int V_6 ;
if ( ! F_149 ( V_257 ) )
return - V_108 ;
if ( ! F_32 ( V_3 -> V_28 ) || F_197 ( V_3 ) )
return - V_100 ;
if ( F_61 ( V_10 -> V_252 ) )
return - V_276 ;
if ( F_234 ( & V_267 , (struct V_283 V_243 * ) V_242 ,
sizeof( V_267 ) ) )
return - V_19 ;
if ( V_267 . V_46 & ( V_216 - 1 ) || V_267 . V_114 & ( V_216 - 1 ) )
return - V_100 ;
if ( F_20 ( ( V_267 . V_46 + V_267 . V_114 ) >> V_23 >
V_10 -> V_129 ) )
return - V_100 ;
V_6 = F_208 ( V_104 ) ;
if ( V_6 )
return V_6 ;
V_6 = F_257 ( V_10 , V_104 , & V_267 ) ;
F_211 ( V_104 ) ;
F_35 ( V_10 , V_30 ) ;
if ( V_6 < 0 )
return V_6 ;
if ( F_238 ( (struct V_283 V_243 * ) V_242 , & V_267 ,
sizeof( V_267 ) ) )
return - V_19 ;
return 0 ;
}
static int F_263 ( struct V_45 * V_299 , V_22 V_300 ,
struct V_45 * V_301 , V_22 V_302 , T_8 V_114 )
{
struct V_3 * V_198 = F_2 ( V_299 ) ;
struct V_3 * V_199 = F_2 ( V_301 ) ;
struct V_9 * V_10 = F_8 ( V_198 ) ;
T_8 V_211 = V_114 , V_303 = 0 ;
T_8 V_304 ;
int V_41 ;
if ( V_299 -> V_305 . V_306 != V_301 -> V_305 . V_306 ||
V_198 -> V_13 != V_199 -> V_13 )
return - V_307 ;
if ( F_20 ( F_61 ( V_198 -> V_13 ) ) )
return - V_276 ;
if ( ! F_32 ( V_198 -> V_28 ) || ! F_32 ( V_199 -> V_28 ) )
return - V_100 ;
if ( F_31 ( V_198 ) || F_31 ( V_199 ) )
return - V_232 ;
if ( V_198 == V_199 ) {
if ( V_300 == V_302 )
return 0 ;
if ( V_302 > V_300 && V_302 < V_300 + V_114 )
return - V_100 ;
}
F_88 ( V_198 ) ;
if ( V_198 != V_199 ) {
if ( ! F_264 ( V_199 ) ) {
V_41 = - V_278 ;
goto V_15;
}
}
V_41 = - V_100 ;
if ( V_300 + V_114 > V_198 -> V_207 || V_300 + V_114 < V_300 )
goto V_308;
if ( V_114 == 0 )
V_211 = V_114 = V_198 -> V_207 - V_300 ;
if ( V_300 + V_114 == V_198 -> V_207 )
V_114 = F_265 ( V_198 -> V_207 , V_216 ) - V_300 ;
if ( V_114 == 0 ) {
V_41 = 0 ;
goto V_308;
}
V_304 = V_199 -> V_207 ;
if ( V_302 + V_211 > V_199 -> V_207 )
V_303 = V_302 + V_211 ;
if ( ! F_266 ( V_300 , V_216 ) ||
! F_266 ( V_300 + V_114 , V_216 ) ||
! F_266 ( V_302 , V_216 ) )
goto V_308;
V_41 = F_99 ( V_198 ) ;
if ( V_41 )
goto V_308;
V_41 = F_99 ( V_199 ) ;
if ( V_41 )
goto V_308;
V_41 = F_66 ( V_198 -> V_18 ,
V_300 , V_300 + V_114 ) ;
if ( V_41 )
goto V_308;
V_41 = F_66 ( V_199 -> V_18 ,
V_302 , V_302 + V_114 ) ;
if ( V_41 )
goto V_308;
F_17 ( V_10 , true ) ;
F_12 ( V_10 ) ;
V_41 = F_177 ( V_198 , V_199 , V_300 >> V_309 ,
V_302 >> V_309 ,
V_114 >> V_309 , false ) ;
if ( ! V_41 ) {
if ( V_303 )
F_175 ( V_199 , V_303 ) ;
else if ( V_304 != V_199 -> V_207 )
F_175 ( V_199 , V_304 ) ;
}
F_15 ( V_10 ) ;
V_308:
if ( V_198 != V_199 )
F_94 ( V_199 ) ;
V_15:
F_94 ( V_198 ) ;
return V_41 ;
}
static int F_267 ( struct V_45 * V_104 , unsigned long V_242 )
{
struct V_310 V_267 ;
struct V_311 V_199 ;
int V_6 ;
if ( ! ( V_104 -> V_235 & V_312 ) ||
! ( V_104 -> V_235 & V_236 ) )
return - V_313 ;
if ( F_234 ( & V_267 , (struct V_310 V_243 * ) V_242 ,
sizeof( V_267 ) ) )
return - V_19 ;
V_199 = F_268 ( V_267 . V_314 ) ;
if ( ! V_199 . V_45 )
return - V_313 ;
if ( ! ( V_199 . V_45 -> V_235 & V_236 ) ) {
V_6 = - V_313 ;
goto V_254;
}
V_6 = F_208 ( V_104 ) ;
if ( V_6 )
goto V_254;
V_6 = F_263 ( V_104 , V_267 . V_300 , V_199 . V_45 ,
V_267 . V_302 , V_267 . V_114 ) ;
F_211 ( V_104 ) ;
if ( V_6 )
goto V_254;
if ( F_238 ( (struct V_310 V_243 * ) V_242 ,
& V_267 , sizeof( V_267 ) ) )
V_6 = - V_19 ;
V_254:
F_269 ( V_199 ) ;
return V_6 ;
}
static int F_270 ( struct V_45 * V_104 , unsigned long V_242 )
{
struct V_3 * V_3 = F_2 ( V_104 ) ;
struct V_9 * V_10 = F_8 ( V_3 ) ;
struct V_315 * V_316 = F_271 ( V_10 ) ;
unsigned int V_317 = 0 , V_318 = 0 ;
unsigned int V_319 = 0 , V_320 = 0 ;
struct V_321 V_267 ;
int V_41 ;
if ( ! F_149 ( V_257 ) )
return - V_108 ;
if ( F_61 ( V_10 -> V_252 ) )
return - V_276 ;
if ( F_234 ( & V_267 , (struct V_321 V_243 * ) V_242 ,
sizeof( V_267 ) ) )
return - V_19 ;
if ( V_10 -> V_322 <= 1 || V_10 -> V_322 - 1 <= V_267 . V_323 ||
V_10 -> V_324 != 1 ) {
F_214 ( V_10 -> V_252 , V_253 ,
L_2 ,
V_267 . V_323 , V_10 -> V_322 ,
V_10 -> V_324 ) ;
return - V_100 ;
}
V_41 = F_208 ( V_104 ) ;
if ( V_41 )
return V_41 ;
if ( V_267 . V_323 != 0 )
V_319 = F_255 ( V_10 , F_272 ( V_267 . V_323 ) . V_325 ) ;
V_320 = F_255 ( V_10 , F_272 ( V_267 . V_323 ) . V_326 ) ;
V_317 = V_316 -> V_327 [ V_328 ] ;
if ( V_317 < V_319 || V_317 >= V_320 )
V_317 = V_319 ;
V_318 = F_164 ( V_317 + V_267 . V_329 , V_320 ) ;
while ( V_317 < V_318 ) {
if ( ! F_249 ( & V_10 -> V_277 ) ) {
V_41 = - V_278 ;
goto V_15;
}
V_316 -> V_327 [ V_330 ] = V_318 + 1 ;
V_316 -> V_327 [ V_331 ] = V_318 + 1 ;
V_316 -> V_327 [ V_332 ] = V_318 + 1 ;
V_41 = F_251 ( V_10 , true , true , V_317 ) ;
if ( V_41 == - V_294 )
V_41 = 0 ;
else if ( V_41 < 0 )
break;
V_317 ++ ;
}
V_15:
F_211 ( V_104 ) ;
return V_41 ;
}
long F_273 ( struct V_45 * V_104 , unsigned int V_333 , unsigned long V_242 )
{
switch ( V_333 ) {
case V_334 :
return F_203 ( V_104 , V_242 ) ;
case V_335 :
return F_205 ( V_104 , V_242 ) ;
case V_336 :
return F_212 ( V_104 , V_242 ) ;
case V_337 :
return F_213 ( V_104 ) ;
case V_338 :
return F_217 ( V_104 ) ;
case V_339 :
return F_220 ( V_104 ) ;
case V_340 :
return F_223 ( V_104 ) ;
case V_341 :
return F_225 ( V_104 ) ;
case V_342 :
return F_226 ( V_104 , V_242 ) ;
case V_343 :
return F_231 ( V_104 , V_242 ) ;
case V_344 :
return F_240 ( V_104 , V_242 ) ;
case V_345 :
return F_242 ( V_104 , V_242 ) ;
case V_346 :
return F_244 ( V_104 , V_242 ) ;
case V_347 :
return F_248 ( V_104 , V_242 ) ;
case V_348 :
return F_252 ( V_104 , V_242 ) ;
case V_349 :
return F_256 ( V_104 , V_242 ) ;
case V_350 :
return F_262 ( V_104 , V_242 ) ;
case V_351 :
return F_267 ( V_104 , V_242 ) ;
case V_352 :
return F_270 ( V_104 , V_242 ) ;
default:
return - V_353 ;
}
}
static T_12 F_274 ( struct V_354 * V_355 , struct V_356 * V_120 )
{
struct V_45 * V_45 = V_355 -> V_357 ;
struct V_3 * V_3 = F_2 ( V_45 ) ;
struct V_358 V_359 ;
T_12 V_41 ;
F_88 ( V_3 ) ;
V_41 = F_275 ( V_355 , V_120 ) ;
if ( V_41 > 0 ) {
int V_6 ;
if ( F_276 ( V_120 , F_277 ( V_120 ) ) )
F_65 ( V_3 , V_360 ) ;
V_6 = F_278 ( V_355 , V_120 ) ;
if ( V_6 ) {
F_94 ( V_3 ) ;
return V_6 ;
}
F_279 ( & V_359 ) ;
V_41 = F_280 ( V_355 , V_120 ) ;
F_281 ( & V_359 ) ;
F_67 ( V_3 , V_360 ) ;
}
F_94 ( V_3 ) ;
if ( V_41 > 0 )
V_41 = F_282 ( V_355 , V_41 ) ;
return V_41 ;
}
long F_283 ( struct V_45 * V_45 , unsigned int V_333 , unsigned long V_242 )
{
switch ( V_333 ) {
case V_361 :
V_333 = V_334 ;
break;
case V_362 :
V_333 = V_335 ;
break;
case V_363 :
V_333 = V_336 ;
break;
case V_337 :
case V_338 :
case V_339 :
case V_340 :
case V_341 :
case V_342 :
case V_344 :
case V_346 :
case V_345 :
case V_347 :
case V_348 :
case V_349 :
case V_350 :
case V_351 :
case V_352 :
break;
default:
return - V_364 ;
}
return F_273 ( V_45 , V_333 , ( unsigned long ) F_284 ( V_242 ) ) ;
}
