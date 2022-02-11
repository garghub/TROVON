static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = V_2 -> V_3 ;
struct V_4 * V_4 = F_2 ( V_2 -> V_5 -> V_6 ) ;
struct V_7 * V_8 = F_3 ( V_4 ) ;
struct V_9 V_10 ;
int V_11 ;
F_4 ( V_4 -> V_12 ) ;
F_5 ( V_8 , F_6 ( V_4 ) ) ;
F_7 ( V_8 ) ;
F_8 ( & V_10 , V_4 , NULL , NULL , 0 ) ;
V_11 = F_9 ( & V_10 , V_3 -> V_13 ) ;
if ( V_11 ) {
F_10 ( V_8 ) ;
goto V_14;
}
F_11 ( & V_10 ) ;
F_10 ( V_8 ) ;
F_12 ( V_8 , V_10 . V_15 ) ;
F_13 ( V_2 -> V_5 -> V_6 ) ;
F_14 ( V_3 ) ;
if ( F_15 ( V_3 -> V_16 != V_4 -> V_17 ||
F_16 ( V_3 ) > F_17 ( V_4 ) ||
! F_18 ( V_3 ) ) ) {
F_19 ( V_3 ) ;
V_11 = - V_18 ;
goto V_14;
}
if ( F_20 ( V_3 ) )
goto V_19;
if ( ( ( V_20 ) ( V_3 -> V_13 + 1 ) << V_21 ) >
F_17 ( V_4 ) ) {
unsigned V_22 ;
V_22 = F_17 ( V_4 ) & ~ V_23 ;
F_21 ( V_3 , V_22 , V_24 ) ;
}
F_22 ( V_3 ) ;
if ( ! F_18 ( V_3 ) )
F_23 ( V_3 ) ;
F_24 ( V_3 , V_25 ) ;
V_19:
F_25 ( V_3 , V_25 , false ) ;
if ( F_26 ( V_4 ) && F_27 ( V_4 -> V_26 ) )
F_28 ( V_8 , V_10 . V_27 ) ;
V_14:
F_29 ( V_4 -> V_12 ) ;
F_30 ( V_8 , V_28 ) ;
return F_31 ( V_11 ) ;
}
static int F_32 ( struct V_4 * V_4 , T_1 * V_29 )
{
struct V_30 * V_30 ;
V_4 = F_33 ( V_4 ) ;
V_30 = F_34 ( V_4 ) ;
F_35 ( V_4 ) ;
if ( ! V_30 )
return 0 ;
if ( F_36 ( V_4 , V_4 , & V_30 -> V_31 ) ) {
F_37 ( V_30 ) ;
return 0 ;
}
* V_29 = F_38 ( V_30 ) ;
F_37 ( V_30 ) ;
return 1 ;
}
static inline bool F_39 ( struct V_4 * V_4 )
{
struct V_7 * V_8 = F_3 ( V_4 ) ;
bool V_32 = false ;
if ( ! F_27 ( V_4 -> V_26 ) || V_4 -> V_33 != 1 )
V_32 = true ;
else if ( F_40 ( V_8 , V_34 ) )
V_32 = true ;
else if ( F_41 ( V_4 ) )
V_32 = true ;
else if ( ! F_42 ( V_8 ) )
V_32 = true ;
else if ( ! F_43 ( V_8 , F_44 ( V_4 ) -> V_35 ) )
V_32 = true ;
else if ( F_45 ( V_8 , V_36 ) )
V_32 = true ;
else if ( V_8 -> V_37 == 2 )
V_32 = true ;
return V_32 ;
}
static bool F_46 ( struct V_7 * V_8 , T_1 V_38 )
{
struct V_3 * V_39 = F_47 ( F_48 ( V_8 ) , V_38 ) ;
bool V_40 = false ;
if ( ( V_39 && F_49 ( V_39 ) ) || F_50 ( V_8 , V_38 ) )
V_40 = true ;
F_51 ( V_39 , 0 ) ;
return V_40 ;
}
static void F_52 ( struct V_4 * V_4 )
{
struct V_41 * V_42 = F_44 ( V_4 ) ;
T_1 V_29 ;
F_53 ( & V_42 -> V_43 ) ;
if ( F_41 ( V_4 ) && V_4 -> V_33 == 1 &&
F_32 ( V_4 , & V_29 ) ) {
F_54 ( V_4 , V_29 ) ;
F_55 ( V_4 ) ;
}
F_56 ( & V_42 -> V_43 ) ;
}
static int F_57 ( struct V_44 * V_44 , V_20 V_45 , V_20 V_46 ,
int V_47 , bool V_48 )
{
struct V_4 * V_4 = V_44 -> V_49 -> V_50 ;
struct V_7 * V_8 = F_3 ( V_4 ) ;
T_1 V_38 = V_4 -> V_51 ;
int V_40 = 0 ;
bool V_32 = false ;
struct V_52 V_53 = {
. V_54 = V_55 ,
. V_56 = V_57 ,
. V_58 = 0 ,
} ;
if ( F_15 ( F_58 ( V_4 -> V_12 ) ) )
return 0 ;
F_59 ( V_4 ) ;
if ( V_47 || F_60 ( V_4 ) <= F_61 ( V_8 ) -> V_59 )
F_62 ( V_4 , V_60 ) ;
V_40 = F_63 ( V_4 -> V_17 , V_45 , V_46 ) ;
F_64 ( V_4 , V_60 ) ;
if ( V_40 ) {
F_65 ( V_4 , V_32 , V_47 , V_40 ) ;
return V_40 ;
}
if ( ! F_66 ( V_4 , V_47 ) ) {
F_67 ( V_4 , NULL ) ;
goto V_61;
}
if ( ! F_68 ( V_4 , V_62 ) &&
! F_69 ( V_8 , V_38 , V_63 ) ) {
if ( F_46 ( V_8 , V_38 ) )
goto V_61;
if ( F_68 ( V_4 , V_64 ) ||
F_69 ( V_8 , V_38 , V_65 ) )
goto V_66;
goto V_14;
}
V_61:
F_70 ( & F_44 ( V_4 ) -> V_43 ) ;
V_32 = F_39 ( V_4 ) ;
F_71 ( & F_44 ( V_4 ) -> V_43 ) ;
if ( V_32 ) {
V_40 = F_72 ( V_4 -> V_12 , 1 ) ;
F_52 ( V_4 ) ;
F_64 ( V_4 , V_62 ) ;
F_64 ( V_4 , V_64 ) ;
goto V_14;
}
V_67:
V_40 = F_73 ( V_8 , V_4 , & V_53 , V_48 ) ;
if ( V_40 )
goto V_14;
if ( F_15 ( F_74 ( V_8 ) ) ) {
V_40 = - V_68 ;
goto V_14;
}
if ( F_50 ( V_8 , V_38 ) ) {
F_75 ( V_4 , true ) ;
F_67 ( V_4 , NULL ) ;
goto V_67;
}
V_40 = F_76 ( V_8 , V_38 ) ;
if ( V_40 )
goto V_14;
F_77 ( V_8 , V_38 , V_63 ) ;
F_64 ( V_4 , V_62 ) ;
V_66:
F_77 ( V_8 , V_38 , V_65 ) ;
F_64 ( V_4 , V_64 ) ;
if ( ! V_48 )
V_40 = F_78 ( V_8 ) ;
F_30 ( V_8 , V_28 ) ;
V_14:
F_65 ( V_4 , V_32 , V_47 , V_40 ) ;
F_79 ( NULL , 1 ) ;
return V_40 ;
}
int F_80 ( struct V_44 * V_44 , V_20 V_45 , V_20 V_46 , int V_47 )
{
return F_57 ( V_44 , V_45 , V_46 , V_47 , false ) ;
}
static T_2 F_81 ( struct V_69 * V_16 ,
T_2 V_70 , int V_71 )
{
struct V_72 V_73 ;
int V_74 ;
if ( V_71 != V_75 )
return 0 ;
F_82 ( & V_73 , 0 ) ;
V_74 = F_83 ( & V_73 , V_16 , & V_70 ,
V_76 , 1 ) ;
V_70 = V_74 ? V_73 . V_77 [ 0 ] -> V_13 : V_78 ;
F_84 ( & V_73 ) ;
return V_70 ;
}
static bool F_85 ( T_3 V_79 , T_2 V_80 , T_2 V_70 ,
int V_71 )
{
switch ( V_71 ) {
case V_75 :
if ( ( V_79 == V_81 && V_80 == V_70 ) ||
( V_79 != V_81 && V_79 != V_82 ) )
return true ;
break;
case V_83 :
if ( V_79 == V_82 )
return true ;
break;
}
return false ;
}
static V_20 F_86 ( struct V_44 * V_44 , V_20 V_22 , int V_71 )
{
struct V_4 * V_4 = V_44 -> V_49 -> V_50 ;
V_20 V_84 = V_4 -> V_12 -> V_85 ;
struct V_9 V_10 ;
T_2 V_70 , V_86 , V_80 ;
V_20 V_87 = V_22 ;
V_20 V_88 ;
int V_11 = 0 ;
F_87 ( V_4 ) ;
V_88 = F_17 ( V_4 ) ;
if ( V_22 >= V_88 )
goto V_89;
if ( F_6 ( V_4 ) || F_88 ( V_4 ) ) {
if ( V_71 == V_83 )
V_87 = V_88 ;
goto V_90;
}
V_70 = ( T_2 ) ( V_22 >> V_21 ) ;
V_80 = F_81 ( V_4 -> V_17 , V_70 , V_71 ) ;
for (; V_87 < V_88 ; V_87 = ( V_20 ) V_70 << V_21 ) {
F_8 ( & V_10 , V_4 , NULL , NULL , 0 ) ;
V_11 = F_89 ( & V_10 , V_70 , V_91 ) ;
if ( V_11 && V_11 != - V_92 ) {
goto V_89;
} else if ( V_11 == - V_92 ) {
if ( V_71 == V_75 ) {
V_70 = F_90 ( & V_10 , V_70 ) ;
continue;
} else {
goto V_90;
}
}
V_86 = F_91 ( V_10 . V_93 , V_4 ) ;
for (; V_10 . V_94 < V_86 ;
V_10 . V_94 ++ , V_70 ++ ,
V_87 = ( V_20 ) V_70 << V_21 ) {
T_3 V_79 ;
V_79 = F_92 ( V_10 . V_93 , V_10 . V_94 ) ;
if ( F_85 ( V_79 , V_80 , V_70 , V_71 ) ) {
F_11 ( & V_10 ) ;
goto V_90;
}
}
F_11 ( & V_10 ) ;
}
if ( V_71 == V_75 )
goto V_89;
V_90:
if ( V_71 == V_83 && V_87 > V_88 )
V_87 = V_88 ;
F_93 ( V_4 ) ;
return F_94 ( V_44 , V_87 , V_84 ) ;
V_89:
F_93 ( V_4 ) ;
return - V_95 ;
}
static V_20 F_95 ( struct V_44 * V_44 , V_20 V_22 , int V_71 )
{
struct V_4 * V_4 = V_44 -> V_49 -> V_50 ;
V_20 V_84 = V_4 -> V_12 -> V_85 ;
switch ( V_71 ) {
case V_96 :
case V_97 :
case V_98 :
return F_96 ( V_44 , V_22 , V_71 ,
V_84 , F_17 ( V_4 ) ) ;
case V_75 :
case V_83 :
if ( V_22 < 0 )
return - V_95 ;
return F_86 ( V_44 , V_22 , V_71 ) ;
}
return - V_99 ;
}
static int F_97 ( struct V_44 * V_44 , struct V_100 * V_5 )
{
struct V_4 * V_4 = F_2 ( V_44 ) ;
int V_11 ;
if ( F_26 ( V_4 ) ) {
V_11 = F_98 ( V_4 ) ;
if ( V_11 )
return 0 ;
if ( ! F_26 ( V_4 ) )
return - V_101 ;
}
V_11 = F_99 ( V_4 ) ;
if ( V_11 )
return V_11 ;
F_100 ( V_44 ) ;
V_5 -> V_102 = & V_103 ;
return 0 ;
}
static int F_101 ( struct V_4 * V_4 , struct V_44 * V_104 )
{
int V_40 = F_102 ( V_4 , V_104 ) ;
struct V_30 * V_105 ;
if ( ! V_40 && F_26 ( V_4 ) ) {
V_40 = F_98 ( V_4 ) ;
if ( V_40 )
return - V_106 ;
if ( ! F_103 ( V_4 ) )
return - V_101 ;
}
V_105 = F_104 ( F_105 ( V_104 ) ) ;
if ( F_26 ( F_106 ( V_105 ) ) &&
! F_107 ( F_106 ( V_105 ) , V_4 ) ) {
F_37 ( V_105 ) ;
return - V_107 ;
}
F_37 ( V_105 ) ;
return V_40 ;
}
int F_108 ( struct V_9 * V_10 , int V_108 )
{
struct V_7 * V_8 = F_3 ( V_10 -> V_4 ) ;
struct V_109 * V_110 ;
int V_111 = 0 , V_112 = V_10 -> V_94 , V_113 = V_108 ;
T_4 * V_114 ;
V_110 = F_109 ( V_10 -> V_93 ) ;
V_114 = F_110 ( V_110 ) + V_112 ;
for (; V_108 > 0 ; V_108 -- , V_114 ++ , V_10 -> V_94 ++ ) {
T_3 V_79 = F_111 ( * V_114 ) ;
if ( V_79 == V_82 )
continue;
V_10 -> V_27 = V_82 ;
F_112 ( V_10 ) ;
F_113 ( V_8 , V_79 ) ;
if ( V_10 -> V_94 == 0 && F_114 ( V_10 -> V_93 ) )
F_64 ( V_10 -> V_4 , V_115 ) ;
V_111 ++ ;
}
if ( V_111 ) {
T_2 V_116 ;
V_116 = F_115 ( F_116 ( V_10 -> V_93 ) ,
V_10 -> V_4 ) + V_112 ;
F_117 ( V_10 , V_116 , 0 , V_113 ) ;
F_118 ( V_8 , V_10 -> V_4 , V_111 ) ;
}
V_10 -> V_94 = V_112 ;
F_30 ( V_8 , V_28 ) ;
F_119 ( V_10 -> V_4 , V_10 -> V_117 ,
V_10 -> V_94 , V_111 ) ;
return V_111 ;
}
void F_120 ( struct V_9 * V_10 )
{
F_108 ( V_10 , V_118 ) ;
}
static int F_121 ( struct V_4 * V_4 , T_5 V_119 ,
bool V_120 )
{
unsigned V_22 = V_119 & ( V_24 - 1 ) ;
T_2 V_13 = V_119 >> V_21 ;
struct V_69 * V_16 = V_4 -> V_17 ;
struct V_3 * V_3 ;
if ( ! V_22 && ! V_120 )
return 0 ;
if ( V_120 ) {
V_3 = F_122 ( V_16 , V_13 ) ;
if ( V_3 && F_18 ( V_3 ) )
goto V_121;
F_51 ( V_3 , 1 ) ;
return 0 ;
}
V_3 = F_123 ( V_4 , V_13 , true ) ;
if ( F_124 ( V_3 ) )
return 0 ;
V_121:
F_25 ( V_3 , V_25 , true ) ;
F_125 ( V_3 , V_22 , V_24 - V_22 ) ;
if ( ! V_120 || ! F_26 ( V_4 ) ||
! F_27 ( V_4 -> V_26 ) )
F_22 ( V_3 ) ;
F_51 ( V_3 , 1 ) ;
return 0 ;
}
int F_126 ( struct V_4 * V_4 , T_5 V_119 , bool V_122 )
{
struct V_7 * V_8 = F_3 ( V_4 ) ;
unsigned int V_123 = V_4 -> V_12 -> V_124 ;
struct V_9 V_10 ;
T_2 V_125 ;
int V_108 = 0 , V_11 = 0 ;
struct V_3 * V_126 ;
bool V_127 = false ;
F_127 ( V_4 , V_119 ) ;
V_125 = ( T_2 ) F_128 ( V_119 + V_123 - 1 ) ;
if ( V_125 >= V_8 -> V_128 )
goto V_129;
if ( V_122 )
F_7 ( V_8 ) ;
V_126 = F_129 ( V_8 , V_4 -> V_51 ) ;
if ( F_124 ( V_126 ) ) {
V_11 = F_130 ( V_126 ) ;
goto V_14;
}
if ( F_6 ( V_4 ) ) {
F_131 ( V_126 , V_119 ) ;
if ( V_119 == 0 )
F_64 ( V_4 , V_130 ) ;
F_51 ( V_126 , 1 ) ;
V_127 = true ;
goto V_14;
}
F_8 ( & V_10 , V_4 , V_126 , NULL , 0 ) ;
V_11 = F_89 ( & V_10 , V_125 , V_131 ) ;
if ( V_11 ) {
if ( V_11 == - V_92 )
goto V_132;
goto V_14;
}
V_108 = F_91 ( V_10 . V_93 , V_4 ) ;
V_108 -= V_10 . V_94 ;
F_5 ( V_8 , V_108 < 0 ) ;
if ( V_10 . V_94 || F_114 ( V_10 . V_93 ) ) {
F_108 ( & V_10 , V_108 ) ;
V_125 += V_108 ;
}
F_11 ( & V_10 ) ;
V_132:
V_11 = F_132 ( V_4 , V_125 ) ;
V_14:
if ( V_122 )
F_10 ( V_8 ) ;
V_129:
if ( ! V_11 )
V_11 = F_121 ( V_4 , V_119 , V_127 ) ;
F_133 ( V_4 , V_11 ) ;
return V_11 ;
}
int F_134 ( struct V_4 * V_4 )
{
int V_11 ;
if ( ! ( F_27 ( V_4 -> V_26 ) || F_135 ( V_4 -> V_26 ) ||
F_136 ( V_4 -> V_26 ) ) )
return 0 ;
F_137 ( V_4 ) ;
if ( ! F_138 ( V_4 ) ) {
V_11 = F_99 ( V_4 ) ;
if ( V_11 )
return V_11 ;
}
V_11 = F_126 ( V_4 , F_17 ( V_4 ) , true ) ;
if ( V_11 )
return V_11 ;
V_4 -> V_133 = V_4 -> V_134 = F_139 ( V_4 ) ;
F_75 ( V_4 , false ) ;
return 0 ;
}
int F_140 ( const struct V_135 * V_135 , struct V_136 * V_137 ,
T_6 V_138 , unsigned int V_139 )
{
struct V_4 * V_4 = F_106 ( V_135 -> V_30 ) ;
F_141 ( V_4 , V_137 ) ;
V_137 -> V_140 <<= 3 ;
return 0 ;
}
static void F_142 ( struct V_4 * V_4 , const struct V_141 * V_142 )
{
unsigned int V_143 = V_142 -> V_143 ;
if ( V_143 & V_144 )
V_4 -> V_145 = V_142 -> V_146 ;
if ( V_143 & V_147 )
V_4 -> V_148 = V_142 -> V_149 ;
if ( V_143 & V_150 )
V_4 -> V_151 = F_143 ( V_142 -> V_152 ,
V_4 -> V_12 -> V_153 ) ;
if ( V_143 & V_154 )
V_4 -> V_133 = F_143 ( V_142 -> V_155 ,
V_4 -> V_12 -> V_153 ) ;
if ( V_143 & V_156 )
V_4 -> V_134 = F_143 ( V_142 -> V_157 ,
V_4 -> V_12 -> V_153 ) ;
if ( V_143 & V_158 ) {
T_7 V_159 = V_142 -> V_160 ;
if ( ! F_144 ( V_4 -> V_148 ) && ! F_145 ( V_161 ) )
V_159 &= ~ V_162 ;
F_146 ( V_4 , V_159 ) ;
}
}
int F_147 ( struct V_30 * V_30 , struct V_141 * V_142 )
{
struct V_4 * V_4 = F_106 ( V_30 ) ;
int V_11 ;
bool V_163 = false ;
V_11 = F_148 ( V_30 , V_142 ) ;
if ( V_11 )
return V_11 ;
if ( V_142 -> V_143 & V_164 ) {
if ( F_26 ( V_4 ) &&
F_98 ( V_4 ) )
return - V_106 ;
if ( V_142 -> V_165 <= F_17 ( V_4 ) ) {
F_149 ( V_4 , V_142 -> V_165 ) ;
V_11 = F_134 ( V_4 ) ;
if ( V_11 )
return V_11 ;
} else {
F_149 ( V_4 , V_142 -> V_165 ) ;
if ( ! F_138 ( V_4 ) ) {
V_11 = F_99 ( V_4 ) ;
if ( V_11 )
return V_11 ;
}
V_4 -> V_133 = V_4 -> V_134 = F_139 ( V_4 ) ;
}
V_163 = true ;
}
F_142 ( V_4 , V_142 ) ;
if ( V_142 -> V_143 & V_158 ) {
V_11 = F_150 ( V_4 , F_151 ( V_4 ) ) ;
if ( V_11 || F_68 ( V_4 , V_166 ) ) {
V_4 -> V_26 = F_44 ( V_4 ) -> V_167 ;
F_64 ( V_4 , V_166 ) ;
}
}
F_75 ( V_4 , V_163 ) ;
F_12 ( F_3 ( V_4 ) , true ) ;
return V_11 ;
}
static int F_152 ( struct V_4 * V_4 , T_2 V_13 ,
V_20 V_45 , V_20 V_113 )
{
struct V_7 * V_8 = F_3 ( V_4 ) ;
struct V_3 * V_3 ;
if ( ! V_113 )
return 0 ;
F_12 ( V_8 , true ) ;
F_7 ( V_8 ) ;
V_3 = F_153 ( V_4 , NULL , V_13 , false ) ;
F_10 ( V_8 ) ;
if ( F_124 ( V_3 ) )
return F_130 ( V_3 ) ;
F_25 ( V_3 , V_25 , true ) ;
F_125 ( V_3 , V_45 , V_113 ) ;
F_22 ( V_3 ) ;
F_51 ( V_3 , 1 ) ;
return 0 ;
}
int F_154 ( struct V_4 * V_4 , T_2 V_168 , T_2 V_169 )
{
int V_11 ;
while ( V_168 < V_169 ) {
struct V_9 V_10 ;
T_2 V_86 , V_108 ;
F_8 ( & V_10 , V_4 , NULL , NULL , 0 ) ;
V_11 = F_89 ( & V_10 , V_168 , V_91 ) ;
if ( V_11 ) {
if ( V_11 == - V_92 ) {
V_168 ++ ;
continue;
}
return V_11 ;
}
V_86 = F_91 ( V_10 . V_93 , V_4 ) ;
V_108 = F_155 ( V_86 - V_10 . V_94 , V_169 - V_168 ) ;
F_5 ( F_3 ( V_4 ) , V_108 == 0 || V_108 > V_86 ) ;
F_108 ( & V_10 , V_108 ) ;
F_11 ( & V_10 ) ;
V_168 += V_108 ;
}
return 0 ;
}
static int F_156 ( struct V_4 * V_4 , V_20 V_22 , V_20 V_113 )
{
T_2 V_168 , V_169 ;
V_20 V_170 , V_171 ;
int V_40 ;
V_40 = F_99 ( V_4 ) ;
if ( V_40 )
return V_40 ;
V_168 = ( ( unsigned long long ) V_22 ) >> V_21 ;
V_169 = ( ( unsigned long long ) V_22 + V_113 ) >> V_21 ;
V_170 = V_22 & ( V_24 - 1 ) ;
V_171 = ( V_22 + V_113 ) & ( V_24 - 1 ) ;
if ( V_168 == V_169 ) {
V_40 = F_152 ( V_4 , V_168 , V_170 ,
V_171 - V_170 ) ;
if ( V_40 )
return V_40 ;
} else {
if ( V_170 ) {
V_40 = F_152 ( V_4 , V_168 ++ , V_170 ,
V_24 - V_170 ) ;
if ( V_40 )
return V_40 ;
}
if ( V_171 ) {
V_40 = F_152 ( V_4 , V_169 , 0 , V_171 ) ;
if ( V_40 )
return V_40 ;
}
if ( V_168 < V_169 ) {
struct V_69 * V_16 = V_4 -> V_17 ;
V_20 V_172 , V_173 ;
struct V_7 * V_8 = F_3 ( V_4 ) ;
F_12 ( V_8 , true ) ;
V_172 = ( V_20 ) V_168 << V_21 ;
V_173 = ( V_20 ) V_169 << V_21 ;
F_157 ( V_16 , V_172 ,
V_173 - 1 ) ;
F_7 ( V_8 ) ;
V_40 = F_154 ( V_4 , V_168 , V_169 ) ;
F_10 ( V_8 ) ;
}
}
return V_40 ;
}
static int F_158 ( struct V_4 * V_4 , T_3 * V_79 ,
int * V_174 , T_2 V_175 , T_2 V_113 )
{
struct V_7 * V_8 = F_3 ( V_4 ) ;
struct V_9 V_10 ;
int V_40 , V_176 , V_39 ;
V_177:
F_8 ( & V_10 , V_4 , NULL , NULL , 0 ) ;
V_40 = F_89 ( & V_10 , V_175 , V_131 ) ;
if ( V_40 && V_40 != - V_92 ) {
return V_40 ;
} else if ( V_40 == - V_92 ) {
if ( V_10 . V_178 == 0 )
return - V_92 ;
V_176 = F_155 ( ( T_2 ) V_118 - V_10 . V_94 , V_113 ) ;
V_79 += V_176 ;
V_174 += V_176 ;
goto V_179;
}
V_176 = F_155 ( ( T_2 ) F_91 ( V_10 . V_93 , V_4 ) -
V_10 . V_94 , V_113 ) ;
for ( V_39 = 0 ; V_39 < V_176 ; V_39 ++ , V_79 ++ , V_174 ++ , V_10 . V_94 ++ ) {
* V_79 = F_92 ( V_10 . V_93 , V_10 . V_94 ) ;
if ( ! F_159 ( V_8 , * V_79 ) ) {
if ( F_45 ( V_8 , V_180 ) ) {
F_11 ( & V_10 ) ;
return - V_181 ;
}
F_160 ( & V_10 , V_82 ) ;
* V_174 = 1 ;
}
}
F_11 ( & V_10 ) ;
V_179:
V_113 -= V_176 ;
V_175 += V_176 ;
if ( V_113 )
goto V_177;
return 0 ;
}
static int F_161 ( struct V_4 * V_4 , T_3 * V_79 ,
int * V_174 , T_2 V_175 , int V_113 )
{
struct V_7 * V_8 = F_3 ( V_4 ) ;
struct V_9 V_10 ;
int V_40 , V_39 ;
for ( V_39 = 0 ; V_39 < V_113 ; V_39 ++ , V_174 ++ , V_79 ++ ) {
if ( * V_174 == 0 )
continue;
F_8 ( & V_10 , V_4 , NULL , NULL , 0 ) ;
V_40 = F_89 ( & V_10 , V_175 + V_39 , V_131 ) ;
if ( V_40 ) {
F_118 ( V_8 , V_4 , 1 ) ;
F_113 ( V_8 , * V_79 ) ;
} else {
F_160 ( & V_10 , * V_79 ) ;
}
F_11 ( & V_10 ) ;
}
return 0 ;
}
static int F_162 ( struct V_4 * V_182 , struct V_4 * V_183 ,
T_3 * V_79 , int * V_174 ,
T_2 V_184 , T_2 V_185 , T_2 V_113 , bool V_186 )
{
struct V_7 * V_8 = F_3 ( V_182 ) ;
T_2 V_39 = 0 ;
int V_40 ;
while ( V_39 < V_113 ) {
if ( V_79 [ V_39 ] == V_82 && ! V_186 ) {
V_39 ++ ;
continue;
}
if ( V_174 [ V_39 ] || V_79 [ V_39 ] == V_82 ) {
struct V_9 V_10 ;
struct V_187 V_188 ;
T_8 V_189 ;
T_2 V_190 ;
F_8 ( & V_10 , V_183 , NULL , NULL , 0 ) ;
V_40 = F_89 ( & V_10 , V_185 + V_39 , V_191 ) ;
if ( V_40 )
return V_40 ;
F_163 ( V_8 , V_10 . V_117 , & V_188 ) ;
V_190 = F_155 ( ( T_2 )
F_91 ( V_10 . V_93 , V_183 ) -
V_10 . V_94 , V_113 - V_39 ) ;
do {
V_10 . V_27 = F_92 ( V_10 . V_93 ,
V_10 . V_94 ) ;
F_108 ( & V_10 , 1 ) ;
if ( V_174 [ V_39 ] ) {
F_164 ( V_182 ,
1 , false ) ;
F_164 ( V_183 ,
1 , true ) ;
F_165 ( V_8 , & V_10 , V_10 . V_27 ,
V_79 [ V_39 ] , V_188 . V_192 , true , false ) ;
V_174 [ V_39 ] = 0 ;
}
V_10 . V_94 ++ ;
V_39 ++ ;
V_189 = ( V_185 + V_39 ) << V_21 ;
if ( V_183 -> V_193 < V_189 )
F_166 ( V_183 , V_189 ) ;
} while ( -- V_190 && ( V_174 [ V_39 ] || V_79 [ V_39 ] == V_82 ) );
F_11 ( & V_10 ) ;
} else {
struct V_3 * V_194 , * V_195 ;
V_194 = F_123 ( V_182 , V_184 + V_39 , true ) ;
if ( F_124 ( V_194 ) )
return F_130 ( V_194 ) ;
V_195 = F_153 ( V_183 , NULL , V_185 + V_39 ,
true ) ;
if ( F_124 ( V_195 ) ) {
F_51 ( V_194 , 1 ) ;
return F_130 ( V_195 ) ;
}
F_167 ( V_194 , V_195 ) ;
F_22 ( V_195 ) ;
F_51 ( V_195 , 1 ) ;
F_51 ( V_194 , 1 ) ;
V_40 = F_154 ( V_182 , V_184 + V_39 , V_184 + V_39 + 1 ) ;
if ( V_40 )
return V_40 ;
V_39 ++ ;
}
}
return 0 ;
}
static int F_168 ( struct V_4 * V_182 ,
struct V_4 * V_183 , T_2 V_184 , T_2 V_185 ,
T_2 V_113 , bool V_186 )
{
T_3 * V_196 ;
int * V_174 ;
T_2 V_197 ;
int V_40 ;
while ( V_113 ) {
V_197 = F_155 ( ( T_2 ) 4 * V_118 , V_113 ) ;
V_196 = F_169 ( sizeof( T_3 ) * V_197 , V_198 ) ;
if ( ! V_196 )
return - V_199 ;
V_174 = F_169 ( sizeof( int ) * V_197 , V_198 ) ;
if ( ! V_174 ) {
F_170 ( V_196 ) ;
return - V_199 ;
}
V_40 = F_158 ( V_182 , V_196 ,
V_174 , V_184 , V_197 ) ;
if ( V_40 )
goto V_200;
V_40 = F_162 ( V_182 , V_183 , V_196 ,
V_174 , V_184 , V_185 , V_197 , V_186 ) ;
if ( V_40 )
goto V_200;
V_184 += V_197 ;
V_185 += V_197 ;
V_113 -= V_197 ;
F_170 ( V_196 ) ;
F_170 ( V_174 ) ;
}
return 0 ;
V_200:
F_161 ( V_182 , V_196 , V_174 , V_184 , V_113 ) ;
F_170 ( V_196 ) ;
F_170 ( V_174 ) ;
return V_40 ;
}
static int F_171 ( struct V_4 * V_4 , T_2 V_45 , T_2 V_46 )
{
struct V_7 * V_8 = F_3 ( V_4 ) ;
T_2 V_201 = ( F_17 ( V_4 ) + V_24 - 1 ) / V_24 ;
int V_40 ;
F_12 ( V_8 , true ) ;
F_7 ( V_8 ) ;
F_172 ( V_4 ) ;
V_40 = F_168 ( V_4 , V_4 , V_46 , V_45 , V_201 - V_46 , true ) ;
F_10 ( V_8 ) ;
return V_40 ;
}
static int F_173 ( struct V_4 * V_4 , V_20 V_22 , V_20 V_113 )
{
T_2 V_168 , V_169 ;
V_20 V_189 ;
int V_40 ;
if ( V_22 + V_113 >= F_17 ( V_4 ) )
return - V_99 ;
if ( V_22 & ( V_202 - 1 ) || V_113 & ( V_202 - 1 ) )
return - V_99 ;
V_40 = F_99 ( V_4 ) ;
if ( V_40 )
return V_40 ;
V_168 = V_22 >> V_21 ;
V_169 = ( V_22 + V_113 ) >> V_21 ;
V_40 = F_63 ( V_4 -> V_17 , V_22 , V_203 ) ;
if ( V_40 )
return V_40 ;
F_174 ( V_4 , V_22 ) ;
V_40 = F_171 ( V_4 , V_168 , V_169 ) ;
if ( V_40 )
return V_40 ;
F_63 ( V_4 -> V_17 , V_22 , V_203 ) ;
F_174 ( V_4 , V_22 ) ;
V_189 = F_17 ( V_4 ) - V_113 ;
F_174 ( V_4 , V_189 ) ;
V_40 = F_126 ( V_4 , V_189 , true ) ;
if ( ! V_40 )
F_166 ( V_4 , V_189 ) ;
return V_40 ;
}
static int F_175 ( struct V_9 * V_10 , T_2 V_45 ,
T_2 V_46 )
{
struct V_7 * V_8 = F_3 ( V_10 -> V_4 ) ;
T_2 V_13 = V_45 ;
unsigned int V_94 = V_10 -> V_94 ;
T_9 V_108 = 0 ;
int V_40 ;
for (; V_13 < V_46 ; V_13 ++ , V_10 -> V_94 ++ ) {
if ( F_92 ( V_10 -> V_93 , V_10 -> V_94 ) == V_82 )
V_108 ++ ;
}
V_10 -> V_94 = V_94 ;
V_40 = F_176 ( V_10 , V_108 ) ;
if ( V_40 )
return V_40 ;
V_10 -> V_94 = V_94 ;
for ( V_13 = V_45 ; V_13 < V_46 ; V_13 ++ , V_10 -> V_94 ++ ) {
V_10 -> V_27 =
F_92 ( V_10 -> V_93 , V_10 -> V_94 ) ;
if ( V_10 -> V_27 == V_82 ) {
V_40 = - V_204 ;
break;
}
if ( V_10 -> V_27 != V_81 ) {
F_113 ( V_8 , V_10 -> V_27 ) ;
V_10 -> V_27 = V_81 ;
F_112 ( V_10 ) ;
}
}
F_117 ( V_10 , V_45 , 0 , V_13 - V_45 ) ;
return V_40 ;
}
static int F_177 ( struct V_4 * V_4 , V_20 V_22 , V_20 V_113 ,
int V_159 )
{
struct V_7 * V_8 = F_3 ( V_4 ) ;
struct V_69 * V_16 = V_4 -> V_17 ;
T_2 V_13 , V_168 , V_169 ;
V_20 V_189 = F_17 ( V_4 ) ;
V_20 V_170 , V_171 ;
int V_40 = 0 ;
V_40 = F_178 ( V_4 , ( V_113 + V_22 ) ) ;
if ( V_40 )
return V_40 ;
V_40 = F_99 ( V_4 ) ;
if ( V_40 )
return V_40 ;
V_40 = F_63 ( V_16 , V_22 , V_22 + V_113 - 1 ) ;
if ( V_40 )
return V_40 ;
F_179 ( V_4 , V_22 , V_22 + V_113 - 1 ) ;
V_168 = ( ( unsigned long long ) V_22 ) >> V_21 ;
V_169 = ( ( unsigned long long ) V_22 + V_113 ) >> V_21 ;
V_170 = V_22 & ( V_24 - 1 ) ;
V_171 = ( V_22 + V_113 ) & ( V_24 - 1 ) ;
if ( V_168 == V_169 ) {
V_40 = F_152 ( V_4 , V_168 , V_170 ,
V_171 - V_170 ) ;
if ( V_40 )
return V_40 ;
if ( V_22 + V_113 > V_189 )
V_189 = V_22 + V_113 ;
V_189 = F_180 ( V_20 , V_189 , V_22 + V_113 ) ;
} else {
if ( V_170 ) {
V_40 = F_152 ( V_4 , V_168 ++ , V_170 ,
V_24 - V_170 ) ;
if ( V_40 )
return V_40 ;
V_189 = F_180 ( V_20 , V_189 ,
( V_20 ) V_168 << V_21 ) ;
}
for ( V_13 = V_168 ; V_13 < V_169 ; ) {
struct V_9 V_10 ;
unsigned int V_86 ;
T_2 V_46 ;
F_7 ( V_8 ) ;
F_8 ( & V_10 , V_4 , NULL , NULL , 0 ) ;
V_40 = F_89 ( & V_10 , V_13 , V_191 ) ;
if ( V_40 ) {
F_10 ( V_8 ) ;
goto V_14;
}
V_86 = F_91 ( V_10 . V_93 , V_4 ) ;
V_46 = F_155 ( V_169 , V_86 - V_10 . V_94 + V_13 ) ;
V_40 = F_175 ( & V_10 , V_13 , V_46 ) ;
F_11 ( & V_10 ) ;
F_10 ( V_8 ) ;
F_12 ( V_8 , V_10 . V_15 ) ;
if ( V_40 )
goto V_14;
V_13 = V_46 ;
V_189 = F_180 ( V_20 , V_189 ,
( V_20 ) V_13 << V_21 ) ;
}
if ( V_171 ) {
V_40 = F_152 ( V_4 , V_169 , 0 , V_171 ) ;
if ( V_40 )
goto V_14;
V_189 = F_180 ( V_20 , V_189 , V_22 + V_113 ) ;
}
}
V_14:
if ( ! ( V_159 & V_205 ) && F_17 ( V_4 ) < V_189 )
F_166 ( V_4 , V_189 ) ;
return V_40 ;
}
static int F_181 ( struct V_4 * V_4 , V_20 V_22 , V_20 V_113 )
{
struct V_7 * V_8 = F_3 ( V_4 ) ;
T_2 V_206 , V_168 , V_169 , V_207 , V_208 ;
V_20 V_189 ;
int V_40 = 0 ;
V_189 = F_17 ( V_4 ) + V_113 ;
if ( V_189 > V_4 -> V_12 -> V_85 )
return - V_209 ;
if ( V_22 >= F_17 ( V_4 ) )
return - V_99 ;
if ( V_22 & ( V_202 - 1 ) || V_113 & ( V_202 - 1 ) )
return - V_99 ;
V_40 = F_99 ( V_4 ) ;
if ( V_40 )
return V_40 ;
F_12 ( V_8 , true ) ;
V_40 = F_126 ( V_4 , F_17 ( V_4 ) , true ) ;
if ( V_40 )
return V_40 ;
V_40 = F_63 ( V_4 -> V_17 , V_22 , V_203 ) ;
if ( V_40 )
return V_40 ;
F_174 ( V_4 , V_22 ) ;
V_168 = V_22 >> V_21 ;
V_169 = ( V_22 + V_113 ) >> V_21 ;
V_207 = V_169 - V_168 ;
V_208 = ( F_17 ( V_4 ) + V_24 - 1 ) / V_24 ;
while ( ! V_40 && V_208 > V_168 ) {
V_206 = V_208 - V_168 ;
if ( V_206 > V_207 )
V_206 = V_207 ;
V_208 -= V_206 ;
F_7 ( V_8 ) ;
F_172 ( V_4 ) ;
V_40 = F_168 ( V_4 , V_4 , V_208 ,
V_208 + V_207 , V_206 , false ) ;
F_10 ( V_8 ) ;
}
F_63 ( V_4 -> V_17 , V_22 , V_203 ) ;
F_174 ( V_4 , V_22 ) ;
if ( ! V_40 )
F_166 ( V_4 , V_189 ) ;
return V_40 ;
}
static int F_182 ( struct V_4 * V_4 , V_20 V_22 ,
V_20 V_113 , int V_159 )
{
struct V_7 * V_8 = F_3 ( V_4 ) ;
struct V_210 V_211 = { . V_212 = NULL } ;
T_2 V_169 ;
V_20 V_189 = F_17 ( V_4 ) ;
V_20 V_171 ;
int V_11 ;
V_11 = F_178 ( V_4 , ( V_113 + V_22 ) ) ;
if ( V_11 )
return V_11 ;
V_11 = F_99 ( V_4 ) ;
if ( V_11 )
return V_11 ;
F_12 ( V_8 , true ) ;
V_169 = ( ( unsigned long long ) V_22 + V_113 ) >> V_21 ;
V_171 = ( V_22 + V_113 ) & ( V_24 - 1 ) ;
V_211 . V_213 = ( ( unsigned long long ) V_22 ) >> V_21 ;
V_211 . V_214 = V_169 - V_211 . V_213 ;
if ( V_171 )
V_211 . V_214 ++ ;
V_11 = V_210 ( V_4 , & V_211 , 1 , V_215 ) ;
if ( V_11 ) {
T_2 V_216 ;
if ( ! V_211 . V_214 )
return V_11 ;
V_216 = V_211 . V_213 + V_211 . V_214 - 1 ;
V_189 = ( V_216 == V_169 ) ? V_22 + V_113 :
( V_20 ) ( V_216 + 1 ) << V_21 ;
} else {
V_189 = ( ( V_20 ) V_169 << V_21 ) + V_171 ;
}
if ( ! ( V_159 & V_205 ) && F_17 ( V_4 ) < V_189 )
F_166 ( V_4 , V_189 ) ;
return V_11 ;
}
static long F_183 ( struct V_44 * V_44 , int V_159 ,
V_20 V_22 , V_20 V_113 )
{
struct V_4 * V_4 = F_2 ( V_44 ) ;
long V_40 = 0 ;
if ( ! F_27 ( V_4 -> V_26 ) )
return - V_99 ;
if ( F_26 ( V_4 ) &&
( V_159 & ( V_217 | V_218 ) ) )
return - V_219 ;
if ( V_159 & ~ ( V_205 | V_220 |
V_217 | V_221 |
V_218 ) )
return - V_219 ;
F_87 ( V_4 ) ;
if ( V_159 & V_220 ) {
if ( V_22 >= V_4 -> V_193 )
goto V_14;
V_40 = F_156 ( V_4 , V_22 , V_113 ) ;
} else if ( V_159 & V_217 ) {
V_40 = F_173 ( V_4 , V_22 , V_113 ) ;
} else if ( V_159 & V_221 ) {
V_40 = F_177 ( V_4 , V_22 , V_113 , V_159 ) ;
} else if ( V_159 & V_218 ) {
V_40 = F_181 ( V_4 , V_22 , V_113 ) ;
} else {
V_40 = F_182 ( V_4 , V_22 , V_113 , V_159 ) ;
}
if ( ! V_40 ) {
V_4 -> V_133 = V_4 -> V_134 = F_139 ( V_4 ) ;
F_75 ( V_4 , false ) ;
if ( V_159 & V_205 )
F_184 ( V_4 ) ;
F_30 ( F_3 ( V_4 ) , V_28 ) ;
}
V_14:
F_93 ( V_4 ) ;
F_185 ( V_4 , V_159 , V_22 , V_113 , V_40 ) ;
return V_40 ;
}
static int F_186 ( struct V_4 * V_4 , struct V_44 * V_104 )
{
if ( ! ( V_104 -> V_222 & V_223 ) ||
F_187 ( & V_4 -> V_224 ) != 1 )
return 0 ;
if ( F_188 ( V_4 ) )
F_189 ( V_4 ) ;
if ( F_190 ( V_4 ) ) {
F_64 ( V_4 , V_225 ) ;
F_62 ( V_4 , V_226 ) ;
F_191 ( V_4 -> V_17 ) ;
F_64 ( V_4 , V_226 ) ;
}
return 0 ;
}
static inline T_10 F_192 ( T_7 V_159 , T_10 V_139 )
{
if ( F_135 ( V_159 ) )
return V_139 ;
else if ( F_27 ( V_159 ) )
return V_139 & V_227 ;
else
return V_139 & V_228 ;
}
static int F_193 ( struct V_44 * V_104 , unsigned long V_229 )
{
struct V_4 * V_4 = F_2 ( V_104 ) ;
struct V_41 * V_42 = F_44 ( V_4 ) ;
unsigned int V_139 = V_42 -> V_230 & V_231 ;
return F_194 ( V_139 , ( int V_232 * ) V_229 ) ;
}
static int F_195 ( struct V_44 * V_104 , unsigned long V_229 )
{
struct V_4 * V_4 = F_2 ( V_104 ) ;
struct V_41 * V_42 = F_44 ( V_4 ) ;
unsigned int V_139 ;
unsigned int V_233 ;
int V_40 ;
if ( ! F_196 ( V_4 ) )
return - V_106 ;
if ( F_197 ( V_139 , ( int V_232 * ) V_229 ) )
return - V_18 ;
V_40 = F_198 ( V_104 ) ;
if ( V_40 )
return V_40 ;
V_139 = F_192 ( V_4 -> V_26 , V_139 ) ;
F_87 ( V_4 ) ;
V_233 = V_42 -> V_230 ;
if ( ( V_139 ^ V_233 ) & ( V_234 | V_235 ) ) {
if ( ! F_145 ( V_236 ) ) {
F_93 ( V_4 ) ;
V_40 = - V_107 ;
goto V_14;
}
}
V_139 = V_139 & V_237 ;
V_139 |= V_233 & ~ V_237 ;
V_42 -> V_230 = V_139 ;
F_93 ( V_4 ) ;
V_4 -> V_134 = F_139 ( V_4 ) ;
F_199 ( V_4 ) ;
V_14:
F_200 ( V_104 ) ;
return V_40 ;
}
static int F_201 ( struct V_44 * V_104 , unsigned long V_229 )
{
struct V_4 * V_4 = F_2 ( V_104 ) ;
return F_194 ( V_4 -> V_238 , ( int V_232 * ) V_229 ) ;
}
static int F_202 ( struct V_44 * V_104 )
{
struct V_4 * V_4 = F_2 ( V_104 ) ;
int V_40 ;
if ( ! F_196 ( V_4 ) )
return - V_106 ;
V_40 = F_198 ( V_104 ) ;
if ( V_40 )
return V_40 ;
F_87 ( V_4 ) ;
if ( F_188 ( V_4 ) )
goto V_14;
V_40 = F_99 ( V_4 ) ;
if ( V_40 )
goto V_14;
F_62 ( V_4 , V_239 ) ;
F_30 ( F_3 ( V_4 ) , V_28 ) ;
if ( ! F_60 ( V_4 ) )
goto V_14;
F_203 ( F_3 ( V_4 ) -> V_240 , V_241 ,
L_1 ,
V_4 -> V_51 , F_60 ( V_4 ) ) ;
V_40 = F_63 ( V_4 -> V_17 , 0 , V_203 ) ;
if ( V_40 )
F_64 ( V_4 , V_239 ) ;
V_14:
F_204 ( V_4 ) ;
F_205 ( V_4 ) ;
F_93 ( V_4 ) ;
F_200 ( V_104 ) ;
return V_40 ;
}
static int F_206 ( struct V_44 * V_104 )
{
struct V_4 * V_4 = F_2 ( V_104 ) ;
int V_40 ;
if ( ! F_196 ( V_4 ) )
return - V_106 ;
V_40 = F_198 ( V_104 ) ;
if ( V_40 )
return V_40 ;
F_87 ( V_4 ) ;
if ( F_190 ( V_4 ) )
goto V_242;
if ( F_188 ( V_4 ) ) {
V_40 = F_207 ( V_4 ) ;
if ( V_40 )
goto V_242;
V_40 = F_57 ( V_104 , 0 , V_203 , 0 , true ) ;
if ( ! V_40 ) {
F_64 ( V_4 , V_239 ) ;
F_208 ( V_4 ) ;
}
} else {
V_40 = F_57 ( V_104 , 0 , V_203 , 0 , true ) ;
}
V_242:
F_93 ( V_4 ) ;
F_200 ( V_104 ) ;
return V_40 ;
}
static int F_209 ( struct V_44 * V_104 )
{
struct V_4 * V_4 = F_2 ( V_104 ) ;
int V_40 ;
if ( ! F_196 ( V_4 ) )
return - V_106 ;
V_40 = F_198 ( V_104 ) ;
if ( V_40 )
return V_40 ;
F_87 ( V_4 ) ;
if ( F_190 ( V_4 ) )
goto V_14;
V_40 = F_99 ( V_4 ) ;
if ( V_40 )
goto V_14;
F_62 ( V_4 , V_225 ) ;
F_30 ( F_3 ( V_4 ) , V_28 ) ;
V_14:
F_93 ( V_4 ) ;
F_200 ( V_104 ) ;
return V_40 ;
}
static int F_210 ( struct V_44 * V_104 )
{
struct V_4 * V_4 = F_2 ( V_104 ) ;
int V_40 ;
if ( ! F_196 ( V_4 ) )
return - V_106 ;
V_40 = F_198 ( V_104 ) ;
if ( V_40 )
return V_40 ;
F_87 ( V_4 ) ;
if ( ! F_190 ( V_4 ) )
goto V_14;
if ( ! F_211 ( V_4 ) ) {
V_40 = F_121 ( V_4 , 0 , true ) ;
goto V_14;
}
V_40 = F_156 ( V_4 , 0 , V_202 ) ;
V_14:
F_93 ( V_4 ) ;
F_200 ( V_104 ) ;
return V_40 ;
}
static int F_212 ( struct V_44 * V_104 )
{
struct V_4 * V_4 = F_2 ( V_104 ) ;
int V_40 ;
if ( ! F_196 ( V_4 ) )
return - V_106 ;
V_40 = F_198 ( V_104 ) ;
if ( V_40 )
return V_40 ;
F_87 ( V_4 ) ;
if ( F_188 ( V_4 ) )
F_189 ( V_4 ) ;
if ( F_190 ( V_4 ) ) {
F_64 ( V_4 , V_225 ) ;
V_40 = F_57 ( V_104 , 0 , V_203 , 0 , true ) ;
}
F_93 ( V_4 ) ;
F_200 ( V_104 ) ;
F_30 ( F_3 ( V_4 ) , V_28 ) ;
return V_40 ;
}
static int F_213 ( struct V_44 * V_104 , unsigned long V_229 )
{
struct V_4 * V_4 = F_2 ( V_104 ) ;
struct V_7 * V_8 = F_3 ( V_4 ) ;
struct V_243 * V_240 = V_8 -> V_240 ;
T_10 V_244 ;
int V_40 ;
if ( ! F_145 ( V_245 ) )
return - V_107 ;
if ( F_197 ( V_244 , ( T_10 V_232 * ) V_229 ) )
return - V_18 ;
V_40 = F_198 ( V_104 ) ;
if ( V_40 )
return V_40 ;
switch ( V_244 ) {
case V_246 :
V_240 = F_214 ( V_240 -> V_247 ) ;
if ( V_240 && ! F_124 ( V_240 ) ) {
F_215 ( V_8 , false ) ;
F_216 ( V_240 -> V_247 , V_240 ) ;
}
break;
case V_248 :
F_72 ( V_240 , 1 ) ;
F_215 ( V_8 , false ) ;
break;
case V_249 :
F_215 ( V_8 , false ) ;
break;
case V_250 :
F_217 ( V_8 , V_251 , V_57 ) ;
F_215 ( V_8 , false ) ;
break;
default:
V_40 = - V_99 ;
goto V_14;
}
F_30 ( V_8 , V_28 ) ;
V_14:
F_200 ( V_104 ) ;
return V_40 ;
}
static int F_218 ( struct V_44 * V_104 , unsigned long V_229 )
{
struct V_4 * V_4 = F_2 ( V_104 ) ;
struct V_243 * V_240 = V_4 -> V_12 ;
struct V_252 * V_253 = F_219 ( V_240 -> V_247 ) ;
struct V_254 V_255 ;
int V_40 ;
if ( ! F_145 ( V_245 ) )
return - V_107 ;
if ( ! F_220 ( V_253 ) )
return - V_219 ;
if ( F_221 ( & V_255 , (struct V_254 V_232 * ) V_229 ,
sizeof( V_255 ) ) )
return - V_18 ;
V_40 = F_198 ( V_104 ) ;
if ( V_40 )
return V_40 ;
V_255 . V_256 = F_222 ( ( unsigned int ) V_255 . V_256 ,
V_253 -> V_257 . V_258 ) ;
V_40 = F_223 ( F_224 ( V_240 ) , & V_255 ) ;
F_200 ( V_104 ) ;
if ( V_40 < 0 )
return V_40 ;
if ( F_225 ( (struct V_254 V_232 * ) V_229 , & V_255 ,
sizeof( V_255 ) ) )
return - V_18 ;
F_30 ( F_3 ( V_4 ) , V_28 ) ;
return 0 ;
}
static bool F_226 ( T_11 V_259 [ 16 ] )
{
int V_39 ;
for ( V_39 = 0 ; V_39 < 16 ; V_39 ++ )
if ( V_259 [ V_39 ] )
return true ;
return false ;
}
static int F_227 ( struct V_44 * V_104 , unsigned long V_229 )
{
struct V_4 * V_4 = F_2 ( V_104 ) ;
F_30 ( F_3 ( V_4 ) , V_28 ) ;
return F_228 ( V_104 , ( const void V_232 * ) V_229 ) ;
}
static int F_229 ( struct V_44 * V_104 , unsigned long V_229 )
{
return F_230 ( V_104 , ( void V_232 * ) V_229 ) ;
}
static int F_231 ( struct V_44 * V_104 , unsigned long V_229 )
{
struct V_4 * V_4 = F_2 ( V_104 ) ;
struct V_7 * V_8 = F_3 ( V_4 ) ;
int V_11 ;
if ( ! F_232 ( V_4 -> V_12 ) )
return - V_219 ;
if ( F_226 ( V_8 -> V_260 -> V_261 ) )
goto V_262;
V_11 = F_198 ( V_104 ) ;
if ( V_11 )
return V_11 ;
F_233 ( V_8 -> V_260 -> V_261 ) ;
V_11 = F_234 ( V_8 , false ) ;
if ( V_11 ) {
memset ( V_8 -> V_260 -> V_261 , 0 , 16 ) ;
F_200 ( V_104 ) ;
return V_11 ;
}
F_200 ( V_104 ) ;
V_262:
if ( F_225 ( ( T_11 V_232 * ) V_229 , V_8 -> V_260 -> V_261 ,
16 ) )
return - V_18 ;
return 0 ;
}
static int F_235 ( struct V_44 * V_104 , unsigned long V_229 )
{
struct V_4 * V_4 = F_2 ( V_104 ) ;
struct V_7 * V_8 = F_3 ( V_4 ) ;
T_10 V_263 ;
int V_40 ;
if ( ! F_145 ( V_245 ) )
return - V_107 ;
if ( F_197 ( V_263 , ( T_10 V_232 * ) V_229 ) )
return - V_18 ;
if ( F_58 ( V_8 -> V_240 ) )
return - V_264 ;
V_40 = F_198 ( V_104 ) ;
if ( V_40 )
return V_40 ;
if ( ! V_263 ) {
if ( ! F_236 ( & V_8 -> V_265 ) ) {
V_40 = - V_266 ;
goto V_14;
}
} else {
F_237 ( & V_8 -> V_265 ) ;
}
V_40 = F_238 ( V_8 , V_263 , true ) ;
V_14:
F_200 ( V_104 ) ;
return V_40 ;
}
static int F_239 ( struct V_44 * V_104 , unsigned long V_229 )
{
struct V_4 * V_4 = F_2 ( V_104 ) ;
struct V_7 * V_8 = F_3 ( V_4 ) ;
int V_40 ;
if ( ! F_145 ( V_245 ) )
return - V_107 ;
if ( F_58 ( V_8 -> V_240 ) )
return - V_264 ;
V_40 = F_198 ( V_104 ) ;
if ( V_40 )
return V_40 ;
V_40 = F_72 ( V_8 -> V_240 , 1 ) ;
F_200 ( V_104 ) ;
return V_40 ;
}
static int F_240 ( struct V_7 * V_8 ,
struct V_44 * V_104 ,
struct V_267 * V_255 )
{
struct V_4 * V_4 = F_2 ( V_104 ) ;
struct V_210 V_211 = { . V_212 = NULL } ;
struct V_268 V_269 = { 0 , 0 , 0 } ;
T_2 V_168 , V_169 ;
unsigned int V_270 = V_8 -> V_271 ;
unsigned int V_272 = 0 , V_273 ;
unsigned int V_274 = V_8 -> V_275 * V_270 ;
T_3 V_173 = 0 ;
bool V_276 = false ;
int V_11 ;
if ( F_241 ( V_4 ) )
return - V_99 ;
V_168 = V_255 -> V_45 >> V_21 ;
V_169 = ( V_255 -> V_45 + V_255 -> V_113 ) >> V_21 ;
F_12 ( V_8 , true ) ;
F_87 ( V_4 ) ;
V_11 = F_63 ( V_4 -> V_17 , V_255 -> V_45 ,
V_255 -> V_45 + V_255 -> V_113 - 1 ) ;
if ( V_11 )
goto V_14;
if ( F_242 ( V_4 , V_168 , & V_269 ) ) {
if ( V_269 . V_116 + V_269 . V_113 >= V_169 )
goto V_14;
}
V_211 . V_213 = V_168 ;
while ( V_211 . V_213 < V_169 ) {
V_211 . V_214 = V_169 - V_211 . V_213 ;
V_11 = V_210 ( V_4 , & V_211 , 0 , V_277 ) ;
if ( V_11 )
goto V_14;
if ( ! ( V_211 . V_278 & V_279 ) ) {
V_211 . V_213 ++ ;
continue;
}
if ( V_173 && V_173 != V_211 . V_280 ) {
V_276 = true ;
break;
}
V_173 = V_211 . V_280 + V_211 . V_214 ;
V_211 . V_213 += V_211 . V_214 ;
}
if ( ! V_276 )
goto V_14;
V_211 . V_213 = V_168 ;
V_211 . V_214 = V_169 - V_168 ;
V_273 = ( V_211 . V_214 + V_274 - 1 ) / V_274 ;
if ( F_243 ( V_8 , 0 , V_273 ) ) {
V_11 = - V_281 ;
goto V_14;
}
while ( V_211 . V_213 < V_169 ) {
T_2 V_208 ;
int V_282 = 0 ;
V_283:
V_211 . V_214 = V_169 - V_211 . V_213 ;
V_11 = V_210 ( V_4 , & V_211 , 0 , V_277 ) ;
if ( V_11 )
goto V_284;
if ( ! ( V_211 . V_278 & V_279 ) ) {
V_211 . V_213 ++ ;
continue;
}
F_62 ( V_4 , V_285 ) ;
V_208 = V_211 . V_213 ;
while ( V_208 < V_211 . V_213 + V_211 . V_214 && V_282 < V_270 ) {
struct V_3 * V_3 ;
V_3 = F_123 ( V_4 , V_208 , true ) ;
if ( F_124 ( V_3 ) ) {
V_11 = F_130 ( V_3 ) ;
goto V_284;
}
F_22 ( V_3 ) ;
F_51 ( V_3 , 1 ) ;
V_208 ++ ;
V_282 ++ ;
V_272 ++ ;
}
V_211 . V_213 = V_208 ;
if ( V_208 < V_169 && V_282 < V_270 )
goto V_283;
F_64 ( V_4 , V_285 ) ;
V_11 = F_191 ( V_4 -> V_17 ) ;
if ( V_11 )
goto V_14;
}
V_284:
F_64 ( V_4 , V_285 ) ;
V_14:
F_93 ( V_4 ) ;
if ( ! V_11 )
V_255 -> V_113 = ( T_5 ) V_272 << V_21 ;
return V_11 ;
}
static int F_244 ( struct V_44 * V_104 , unsigned long V_229 )
{
struct V_4 * V_4 = F_2 ( V_104 ) ;
struct V_7 * V_8 = F_3 ( V_4 ) ;
struct V_267 V_255 ;
int V_11 ;
if ( ! F_145 ( V_245 ) )
return - V_107 ;
if ( ! F_27 ( V_4 -> V_26 ) )
return - V_99 ;
V_11 = F_198 ( V_104 ) ;
if ( V_11 )
return V_11 ;
if ( F_58 ( V_8 -> V_240 ) ) {
V_11 = - V_264 ;
goto V_14;
}
if ( F_221 ( & V_255 , (struct V_267 V_232 * ) V_229 ,
sizeof( V_255 ) ) ) {
V_11 = - V_18 ;
goto V_14;
}
if ( V_255 . V_45 & ( V_202 - 1 ) ||
V_255 . V_113 & ( V_202 - 1 ) ) {
V_11 = - V_99 ;
goto V_14;
}
V_11 = F_240 ( V_8 , V_104 , & V_255 ) ;
F_30 ( V_8 , V_28 ) ;
if ( V_11 < 0 )
goto V_14;
if ( F_225 ( (struct V_267 V_232 * ) V_229 , & V_255 ,
sizeof( V_255 ) ) )
V_11 = - V_18 ;
V_14:
F_200 ( V_104 ) ;
return V_11 ;
}
static int F_245 ( struct V_44 * V_286 , V_20 V_287 ,
struct V_44 * V_288 , V_20 V_289 , T_8 V_113 )
{
struct V_4 * V_184 = F_2 ( V_286 ) ;
struct V_4 * V_185 = F_2 ( V_288 ) ;
struct V_7 * V_8 = F_3 ( V_184 ) ;
T_8 V_197 = V_113 , V_290 = 0 ;
T_8 V_291 ;
int V_40 ;
if ( V_286 -> V_292 . V_293 != V_288 -> V_292 . V_293 ||
V_184 -> V_12 != V_185 -> V_12 )
return - V_294 ;
if ( F_15 ( F_58 ( V_184 -> V_12 ) ) )
return - V_264 ;
if ( ! F_27 ( V_184 -> V_26 ) || ! F_27 ( V_185 -> V_26 ) )
return - V_99 ;
if ( F_26 ( V_184 ) || F_26 ( V_185 ) )
return - V_219 ;
if ( V_184 == V_185 ) {
if ( V_287 == V_289 )
return 0 ;
if ( V_289 > V_287 && V_289 < V_287 + V_113 )
return - V_99 ;
}
F_87 ( V_184 ) ;
if ( V_184 != V_185 ) {
if ( ! F_246 ( V_185 ) ) {
V_40 = - V_266 ;
goto V_14;
}
}
V_40 = - V_99 ;
if ( V_287 + V_113 > V_184 -> V_193 || V_287 + V_113 < V_287 )
goto V_295;
if ( V_113 == 0 )
V_197 = V_113 = V_184 -> V_193 - V_287 ;
if ( V_287 + V_113 == V_184 -> V_193 )
V_113 = F_247 ( V_184 -> V_193 , V_202 ) - V_287 ;
if ( V_113 == 0 ) {
V_40 = 0 ;
goto V_295;
}
V_291 = V_185 -> V_193 ;
if ( V_289 + V_197 > V_185 -> V_193 )
V_290 = V_289 + V_197 ;
if ( ! F_248 ( V_287 , V_202 ) ||
! F_248 ( V_287 + V_113 , V_202 ) ||
! F_248 ( V_289 , V_202 ) )
goto V_295;
V_40 = F_99 ( V_184 ) ;
if ( V_40 )
goto V_295;
V_40 = F_99 ( V_185 ) ;
if ( V_40 )
goto V_295;
V_40 = F_63 ( V_184 -> V_17 ,
V_287 , V_287 + V_113 ) ;
if ( V_40 )
goto V_295;
V_40 = F_63 ( V_185 -> V_17 ,
V_289 , V_289 + V_113 ) ;
if ( V_40 )
goto V_295;
F_12 ( V_8 , true ) ;
F_7 ( V_8 ) ;
V_40 = F_168 ( V_184 , V_185 , V_287 >> V_296 ,
V_289 >> V_296 ,
V_113 >> V_296 , false ) ;
if ( ! V_40 ) {
if ( V_290 )
F_166 ( V_185 , V_290 ) ;
else if ( V_291 != V_185 -> V_193 )
F_166 ( V_185 , V_291 ) ;
}
F_10 ( V_8 ) ;
V_295:
if ( V_184 != V_185 )
F_93 ( V_185 ) ;
V_14:
F_93 ( V_184 ) ;
return V_40 ;
}
static int F_249 ( struct V_44 * V_104 , unsigned long V_229 )
{
struct V_297 V_255 ;
struct V_298 V_185 ;
int V_11 ;
if ( ! ( V_104 -> V_222 & V_299 ) ||
! ( V_104 -> V_222 & V_223 ) )
return - V_300 ;
if ( F_221 ( & V_255 , (struct V_297 V_232 * ) V_229 ,
sizeof( V_255 ) ) )
return - V_18 ;
V_185 = F_250 ( V_255 . V_301 ) ;
if ( ! V_185 . V_44 )
return - V_300 ;
if ( ! ( V_185 . V_44 -> V_222 & V_223 ) ) {
V_11 = - V_300 ;
goto V_242;
}
V_11 = F_198 ( V_104 ) ;
if ( V_11 )
goto V_242;
V_11 = F_245 ( V_104 , V_255 . V_287 , V_185 . V_44 ,
V_255 . V_289 , V_255 . V_113 ) ;
F_200 ( V_104 ) ;
if ( F_225 ( (struct V_297 V_232 * ) V_229 ,
& V_255 , sizeof( V_255 ) ) )
V_11 = - V_18 ;
V_242:
F_251 ( V_185 ) ;
return V_11 ;
}
long F_252 ( struct V_44 * V_104 , unsigned int V_302 , unsigned long V_229 )
{
switch ( V_302 ) {
case V_303 :
return F_193 ( V_104 , V_229 ) ;
case V_304 :
return F_195 ( V_104 , V_229 ) ;
case V_305 :
return F_201 ( V_104 , V_229 ) ;
case V_306 :
return F_202 ( V_104 ) ;
case V_307 :
return F_206 ( V_104 ) ;
case V_308 :
return F_209 ( V_104 ) ;
case V_309 :
return F_210 ( V_104 ) ;
case V_310 :
return F_212 ( V_104 ) ;
case V_311 :
return F_213 ( V_104 , V_229 ) ;
case V_312 :
return F_218 ( V_104 , V_229 ) ;
case V_313 :
return F_227 ( V_104 , V_229 ) ;
case V_314 :
return F_229 ( V_104 , V_229 ) ;
case V_315 :
return F_231 ( V_104 , V_229 ) ;
case V_316 :
return F_235 ( V_104 , V_229 ) ;
case V_317 :
return F_239 ( V_104 , V_229 ) ;
case V_318 :
return F_244 ( V_104 , V_229 ) ;
case V_319 :
return F_249 ( V_104 , V_229 ) ;
default:
return - V_320 ;
}
}
static T_12 F_253 ( struct V_321 * V_322 , struct V_323 * V_119 )
{
struct V_44 * V_44 = V_322 -> V_324 ;
struct V_4 * V_4 = F_2 ( V_44 ) ;
struct V_325 V_326 ;
T_12 V_40 ;
if ( F_26 ( V_4 ) &&
! F_103 ( V_4 ) &&
F_98 ( V_4 ) )
return - V_106 ;
F_87 ( V_4 ) ;
V_40 = F_254 ( V_322 , V_119 ) ;
if ( V_40 > 0 ) {
int V_11 ;
if ( F_255 ( V_119 , F_256 ( V_119 ) ) )
F_62 ( V_4 , V_327 ) ;
V_11 = F_257 ( V_322 , V_119 ) ;
if ( V_11 ) {
F_93 ( V_4 ) ;
return V_11 ;
}
F_258 ( & V_326 ) ;
V_40 = F_259 ( V_322 , V_119 ) ;
F_260 ( & V_326 ) ;
F_64 ( V_4 , V_327 ) ;
}
F_93 ( V_4 ) ;
if ( V_40 > 0 )
V_40 = F_261 ( V_322 , V_40 ) ;
return V_40 ;
}
long F_262 ( struct V_44 * V_44 , unsigned int V_302 , unsigned long V_229 )
{
switch ( V_302 ) {
case V_328 :
V_302 = V_303 ;
break;
case V_329 :
V_302 = V_304 ;
break;
case V_330 :
V_302 = V_305 ;
break;
case V_306 :
case V_307 :
case V_308 :
case V_309 :
case V_310 :
case V_311 :
case V_313 :
case V_315 :
case V_314 :
case V_316 :
case V_317 :
case V_318 :
break;
case V_319 :
break;
default:
return - V_331 ;
}
return F_252 ( V_44 , V_302 , ( unsigned long ) F_263 ( V_229 ) ) ;
}
