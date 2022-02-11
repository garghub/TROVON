static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_5 = V_4 -> V_5 ;
struct V_6 * V_6 = F_2 ( V_2 -> V_7 ) ;
struct V_8 * V_9 = F_3 ( V_6 ) ;
struct V_10 V_11 ;
int V_12 ;
F_4 ( V_6 -> V_13 ) ;
F_5 ( V_9 , F_6 ( V_6 ) ) ;
F_7 ( V_9 ) ;
F_8 ( & V_11 , V_6 , NULL , NULL , 0 ) ;
V_12 = F_9 ( & V_11 , V_5 -> V_14 ) ;
if ( V_12 ) {
F_10 ( V_9 ) ;
goto V_15;
}
F_11 ( & V_11 ) ;
F_10 ( V_9 ) ;
F_12 ( V_9 , V_11 . V_16 ) ;
F_13 ( V_2 -> V_7 ) ;
F_14 ( V_5 ) ;
if ( F_15 ( V_5 -> V_17 != V_6 -> V_18 ||
F_16 ( V_5 ) > F_17 ( V_6 ) ||
! F_18 ( V_5 ) ) ) {
F_19 ( V_5 ) ;
V_12 = - V_19 ;
goto V_15;
}
if ( F_20 ( V_5 ) )
goto V_20;
if ( ( ( V_21 ) ( V_5 -> V_14 + 1 ) << V_22 ) >
F_17 ( V_6 ) ) {
unsigned V_23 ;
V_23 = F_17 ( V_6 ) & ~ V_24 ;
F_21 ( V_5 , V_23 , V_25 ) ;
}
F_22 ( V_5 ) ;
if ( ! F_18 ( V_5 ) )
F_23 ( V_5 ) ;
F_24 ( V_5 , V_26 ) ;
V_20:
F_25 ( V_5 , V_26 , false ) ;
if ( F_26 ( V_6 ) && F_27 ( V_6 -> V_27 ) )
F_28 ( V_9 , V_11 . V_28 ) ;
F_29 ( V_5 ) ;
V_15:
F_30 ( V_6 -> V_13 ) ;
F_31 ( V_9 , V_29 ) ;
return F_32 ( V_12 ) ;
}
static int F_33 ( struct V_6 * V_6 , T_1 * V_30 )
{
struct V_31 * V_31 ;
V_6 = F_34 ( V_6 ) ;
V_31 = F_35 ( V_6 ) ;
F_36 ( V_6 ) ;
if ( ! V_31 )
return 0 ;
if ( F_37 ( V_6 , V_6 , & V_31 -> V_32 ) ) {
F_38 ( V_31 ) ;
return 0 ;
}
* V_30 = F_39 ( V_31 ) ;
F_38 ( V_31 ) ;
return 1 ;
}
static inline bool F_40 ( struct V_6 * V_6 )
{
struct V_8 * V_9 = F_3 ( V_6 ) ;
bool V_33 = false ;
if ( ! F_27 ( V_6 -> V_27 ) || V_6 -> V_34 != 1 )
V_33 = true ;
else if ( F_41 ( V_9 , V_35 ) )
V_33 = true ;
else if ( F_42 ( V_6 ) )
V_33 = true ;
else if ( ! F_43 ( V_9 ) )
V_33 = true ;
else if ( ! F_44 ( V_9 , F_45 ( V_6 ) -> V_36 ) )
V_33 = true ;
else if ( F_45 ( V_6 ) -> V_37 == F_46 ( F_47 ( V_9 ) ) )
V_33 = true ;
else if ( F_48 ( V_9 , V_38 ) )
V_33 = true ;
else if ( V_9 -> V_39 == 2 )
V_33 = true ;
return V_33 ;
}
static bool F_49 ( struct V_8 * V_9 , T_1 V_40 )
{
struct V_5 * V_41 = F_50 ( F_51 ( V_9 ) , V_40 ) ;
bool V_42 = false ;
if ( ( V_41 && F_52 ( V_41 ) ) || F_53 ( V_9 , V_40 ) )
V_42 = true ;
F_54 ( V_41 , 0 ) ;
return V_42 ;
}
static void F_55 ( struct V_6 * V_6 )
{
struct V_43 * V_44 = F_45 ( V_6 ) ;
T_1 V_30 ;
F_56 ( & V_44 -> V_45 ) ;
V_44 -> V_37 = 0 ;
if ( F_42 ( V_6 ) && V_6 -> V_34 == 1 &&
F_33 ( V_6 , & V_30 ) ) {
F_57 ( V_6 , V_30 ) ;
F_58 ( V_6 ) ;
}
F_59 ( & V_44 -> V_45 ) ;
}
static int F_60 ( struct V_46 * V_46 , V_21 V_47 , V_21 V_48 ,
int V_49 , bool V_50 )
{
struct V_6 * V_6 = V_46 -> V_51 -> V_52 ;
struct V_8 * V_9 = F_3 ( V_6 ) ;
T_1 V_40 = V_6 -> V_53 ;
int V_42 = 0 ;
bool V_33 = false ;
struct V_54 V_55 = {
. V_56 = V_57 ,
. V_58 = V_59 ,
. V_60 = 0 ,
} ;
if ( F_15 ( F_61 ( V_6 -> V_13 ) ) )
return 0 ;
F_62 ( V_6 ) ;
if ( V_49 || F_63 ( V_6 ) <= F_64 ( V_9 ) -> V_61 )
F_65 ( V_6 , V_62 ) ;
V_42 = F_66 ( V_6 -> V_18 , V_47 , V_48 ) ;
F_67 ( V_6 , V_62 ) ;
if ( V_42 ) {
F_68 ( V_6 , V_33 , V_49 , V_42 ) ;
return V_42 ;
}
if ( ! V_49 && ! F_69 ( V_6 ) ) {
F_70 ( V_6 , NULL ) ;
goto V_63;
}
if ( ! F_71 ( V_6 , V_64 ) &&
! F_72 ( V_9 , V_40 , V_65 ) ) {
if ( F_49 ( V_9 , V_40 ) )
goto V_63;
if ( F_71 ( V_6 , V_66 ) ||
F_72 ( V_9 , V_40 , V_67 ) )
goto V_68;
goto V_15;
}
V_63:
F_73 ( & F_45 ( V_6 ) -> V_45 ) ;
V_33 = F_40 ( V_6 ) ;
F_74 ( & F_45 ( V_6 ) -> V_45 ) ;
if ( V_33 ) {
V_42 = F_75 ( V_6 -> V_13 , 1 ) ;
F_55 ( V_6 ) ;
F_67 ( V_6 , V_64 ) ;
F_67 ( V_6 , V_66 ) ;
goto V_15;
}
V_69:
V_42 = F_76 ( V_9 , V_6 , & V_55 , V_50 ) ;
if ( V_42 )
goto V_15;
if ( F_15 ( F_77 ( V_9 ) ) ) {
V_42 = - V_70 ;
goto V_15;
}
if ( F_53 ( V_9 , V_40 ) ) {
F_78 ( V_6 ) ;
F_70 ( V_6 , NULL ) ;
goto V_69;
}
V_42 = F_79 ( V_9 , V_40 ) ;
if ( V_42 )
goto V_15;
F_80 ( V_9 , V_40 , V_65 ) ;
F_67 ( V_6 , V_64 ) ;
V_68:
F_80 ( V_9 , V_40 , V_67 ) ;
F_67 ( V_6 , V_66 ) ;
V_42 = F_81 ( V_9 ) ;
F_31 ( V_9 , V_29 ) ;
V_15:
F_68 ( V_6 , V_33 , V_49 , V_42 ) ;
F_82 ( NULL , 1 ) ;
return V_42 ;
}
int F_83 ( struct V_46 * V_46 , V_21 V_47 , V_21 V_48 , int V_49 )
{
return F_60 ( V_46 , V_47 , V_48 , V_49 , false ) ;
}
static T_2 F_84 ( struct V_71 * V_17 ,
T_2 V_72 , int V_73 )
{
struct V_74 V_75 ;
int V_76 ;
if ( V_73 != V_77 )
return 0 ;
F_85 ( & V_75 , 0 ) ;
V_76 = F_86 ( & V_75 , V_17 , & V_72 ,
V_78 , 1 ) ;
V_72 = V_76 ? V_75 . V_79 [ 0 ] -> V_14 : V_80 ;
F_87 ( & V_75 ) ;
return V_72 ;
}
static bool F_88 ( T_3 V_81 , T_2 V_82 , T_2 V_72 ,
int V_73 )
{
switch ( V_73 ) {
case V_77 :
if ( ( V_81 == V_83 && V_82 == V_72 ) ||
( V_81 != V_83 && V_81 != V_84 ) )
return true ;
break;
case V_85 :
if ( V_81 == V_84 )
return true ;
break;
}
return false ;
}
static V_21 F_89 ( struct V_46 * V_46 , V_21 V_23 , int V_73 )
{
struct V_6 * V_6 = V_46 -> V_51 -> V_52 ;
V_21 V_86 = V_6 -> V_13 -> V_87 ;
struct V_10 V_11 ;
T_2 V_72 , V_88 , V_82 ;
V_21 V_89 = V_23 ;
V_21 V_90 ;
int V_12 = 0 ;
F_90 ( V_6 ) ;
V_90 = F_17 ( V_6 ) ;
if ( V_23 >= V_90 )
goto V_91;
if ( F_6 ( V_6 ) || F_91 ( V_6 ) ) {
if ( V_73 == V_85 )
V_89 = V_90 ;
goto V_92;
}
V_72 = ( T_2 ) ( V_23 >> V_22 ) ;
V_82 = F_84 ( V_6 -> V_18 , V_72 , V_73 ) ;
for (; V_89 < V_90 ; V_89 = ( V_21 ) V_72 << V_22 ) {
F_8 ( & V_11 , V_6 , NULL , NULL , 0 ) ;
V_12 = F_92 ( & V_11 , V_72 , V_93 ) ;
if ( V_12 && V_12 != - V_94 ) {
goto V_91;
} else if ( V_12 == - V_94 ) {
if ( V_73 == V_77 ) {
V_72 = F_93 ( & V_11 , V_72 ) ;
continue;
} else {
goto V_92;
}
}
V_88 = F_94 ( V_11 . V_95 , V_6 ) ;
for (; V_11 . V_96 < V_88 ;
V_11 . V_96 ++ , V_72 ++ ,
V_89 = ( V_21 ) V_72 << V_22 ) {
T_3 V_81 ;
V_81 = F_95 ( V_11 . V_95 , V_11 . V_96 ) ;
if ( F_88 ( V_81 , V_82 , V_72 , V_73 ) ) {
F_11 ( & V_11 ) ;
goto V_92;
}
}
F_11 ( & V_11 ) ;
}
if ( V_73 == V_77 )
goto V_91;
V_92:
if ( V_73 == V_85 && V_89 > V_90 )
V_89 = V_90 ;
F_96 ( V_6 ) ;
return F_97 ( V_46 , V_89 , V_86 ) ;
V_91:
F_96 ( V_6 ) ;
return - V_97 ;
}
static V_21 F_98 ( struct V_46 * V_46 , V_21 V_23 , int V_73 )
{
struct V_6 * V_6 = V_46 -> V_51 -> V_52 ;
V_21 V_86 = V_6 -> V_13 -> V_87 ;
switch ( V_73 ) {
case V_98 :
case V_99 :
case V_100 :
return F_99 ( V_46 , V_23 , V_73 ,
V_86 , F_17 ( V_6 ) ) ;
case V_77 :
case V_85 :
if ( V_23 < 0 )
return - V_97 ;
return F_89 ( V_46 , V_23 , V_73 ) ;
}
return - V_101 ;
}
static int F_100 ( struct V_46 * V_46 , struct V_1 * V_2 )
{
struct V_6 * V_6 = F_2 ( V_46 ) ;
int V_12 ;
if ( F_26 ( V_6 ) ) {
V_12 = F_101 ( V_6 ) ;
if ( V_12 )
return 0 ;
if ( ! F_26 ( V_6 ) )
return - V_102 ;
}
V_12 = F_102 ( V_6 ) ;
if ( V_12 )
return V_12 ;
F_103 ( V_46 ) ;
V_2 -> V_103 = & V_104 ;
return 0 ;
}
static int F_104 ( struct V_6 * V_6 , struct V_46 * V_105 )
{
int V_42 = F_105 ( V_6 , V_105 ) ;
struct V_31 * V_106 ;
if ( ! V_42 && F_26 ( V_6 ) ) {
V_42 = F_101 ( V_6 ) ;
if ( V_42 )
return - V_107 ;
if ( ! F_106 ( V_6 ) )
return - V_102 ;
}
V_106 = F_107 ( F_108 ( V_105 ) ) ;
if ( F_26 ( F_109 ( V_106 ) ) &&
! F_110 ( F_109 ( V_106 ) , V_6 ) ) {
F_38 ( V_106 ) ;
return - V_108 ;
}
F_38 ( V_106 ) ;
return V_42 ;
}
int F_111 ( struct V_10 * V_11 , int V_109 )
{
struct V_8 * V_9 = F_3 ( V_11 -> V_6 ) ;
struct V_110 * V_111 ;
int V_112 = 0 , V_113 = V_11 -> V_96 , V_114 = V_109 ;
T_4 * V_115 ;
V_111 = F_112 ( V_11 -> V_95 ) ;
V_115 = F_113 ( V_111 ) + V_113 ;
for (; V_109 > 0 ; V_109 -- , V_115 ++ , V_11 -> V_96 ++ ) {
T_3 V_81 = F_114 ( * V_115 ) ;
if ( V_81 == V_84 )
continue;
V_11 -> V_28 = V_84 ;
F_115 ( V_11 ) ;
F_116 ( V_9 , V_81 ) ;
if ( V_11 -> V_96 == 0 && F_117 ( V_11 -> V_95 ) )
F_67 ( V_11 -> V_6 , V_116 ) ;
V_112 ++ ;
}
if ( V_112 ) {
T_2 V_117 ;
V_117 = F_118 ( F_119 ( V_11 -> V_95 ) ,
V_11 -> V_6 ) + V_113 ;
F_120 ( V_11 , V_117 , 0 , V_114 ) ;
F_121 ( V_9 , V_11 -> V_6 , V_112 ) ;
}
V_11 -> V_96 = V_113 ;
F_31 ( V_9 , V_29 ) ;
F_122 ( V_11 -> V_6 , V_11 -> V_118 ,
V_11 -> V_96 , V_112 ) ;
return V_112 ;
}
void F_123 ( struct V_10 * V_11 )
{
F_111 ( V_11 , V_119 ) ;
}
static int F_124 ( struct V_6 * V_6 , T_5 V_120 ,
bool V_121 )
{
unsigned V_23 = V_120 & ( V_25 - 1 ) ;
T_2 V_14 = V_120 >> V_22 ;
struct V_71 * V_17 = V_6 -> V_18 ;
struct V_5 * V_5 ;
if ( ! V_23 && ! V_121 )
return 0 ;
if ( V_121 ) {
V_5 = F_125 ( V_17 , V_14 ) ;
if ( V_5 && F_18 ( V_5 ) )
goto V_122;
F_54 ( V_5 , 1 ) ;
return 0 ;
}
V_5 = F_126 ( V_6 , V_14 , true ) ;
if ( F_127 ( V_5 ) )
return 0 ;
V_122:
F_25 ( V_5 , V_26 , true ) ;
F_128 ( V_5 , V_23 , V_25 - V_23 ) ;
if ( ! V_121 || ! F_26 ( V_6 ) ||
! F_27 ( V_6 -> V_27 ) )
F_22 ( V_5 ) ;
F_54 ( V_5 , 1 ) ;
return 0 ;
}
int F_129 ( struct V_6 * V_6 , T_5 V_120 , bool V_123 )
{
struct V_8 * V_9 = F_3 ( V_6 ) ;
unsigned int V_124 = V_6 -> V_13 -> V_125 ;
struct V_10 V_11 ;
T_2 V_126 ;
int V_109 = 0 , V_12 = 0 ;
struct V_5 * V_127 ;
bool V_128 = false ;
F_130 ( V_6 , V_120 ) ;
V_126 = ( T_2 ) F_131 ( V_120 + V_124 - 1 ) ;
if ( V_126 >= V_9 -> V_129 )
goto V_130;
if ( V_123 )
F_7 ( V_9 ) ;
V_127 = F_132 ( V_9 , V_6 -> V_53 ) ;
if ( F_127 ( V_127 ) ) {
V_12 = F_133 ( V_127 ) ;
goto V_15;
}
if ( F_6 ( V_6 ) ) {
if ( F_134 ( V_127 , V_120 ) )
F_22 ( V_127 ) ;
F_54 ( V_127 , 1 ) ;
V_128 = true ;
goto V_15;
}
F_8 ( & V_11 , V_6 , V_127 , NULL , 0 ) ;
V_12 = F_92 ( & V_11 , V_126 , V_131 ) ;
if ( V_12 ) {
if ( V_12 == - V_94 )
goto V_132;
goto V_15;
}
V_109 = F_94 ( V_11 . V_95 , V_6 ) ;
V_109 -= V_11 . V_96 ;
F_5 ( V_9 , V_109 < 0 ) ;
if ( V_11 . V_96 || F_117 ( V_11 . V_95 ) ) {
F_111 ( & V_11 , V_109 ) ;
V_126 += V_109 ;
}
F_11 ( & V_11 ) ;
V_132:
V_12 = F_135 ( V_6 , V_126 ) ;
V_15:
if ( V_123 )
F_10 ( V_9 ) ;
V_130:
if ( ! V_12 )
V_12 = F_124 ( V_6 , V_120 , V_128 ) ;
F_136 ( V_6 , V_12 ) ;
return V_12 ;
}
int F_137 ( struct V_6 * V_6 )
{
int V_12 ;
if ( ! ( F_27 ( V_6 -> V_27 ) || F_138 ( V_6 -> V_27 ) ||
F_139 ( V_6 -> V_27 ) ) )
return 0 ;
F_140 ( V_6 ) ;
if ( ! F_141 ( V_6 ) ) {
V_12 = F_102 ( V_6 ) ;
if ( V_12 )
return V_12 ;
}
V_12 = F_129 ( V_6 , F_17 ( V_6 ) , true ) ;
if ( V_12 )
return V_12 ;
V_6 -> V_133 = V_6 -> V_134 = F_142 ( V_6 ) ;
F_78 ( V_6 ) ;
return 0 ;
}
int F_143 ( struct V_135 * V_136 ,
struct V_31 * V_31 , struct V_137 * V_138 )
{
struct V_6 * V_6 = F_109 ( V_31 ) ;
F_144 ( V_6 , V_138 ) ;
V_138 -> V_139 <<= 3 ;
return 0 ;
}
static void F_145 ( struct V_6 * V_6 , const struct V_140 * V_141 )
{
unsigned int V_142 = V_141 -> V_142 ;
if ( V_142 & V_143 )
V_6 -> V_144 = V_141 -> V_145 ;
if ( V_142 & V_146 )
V_6 -> V_147 = V_141 -> V_148 ;
if ( V_142 & V_149 )
V_6 -> V_150 = F_146 ( V_141 -> V_151 ,
V_6 -> V_13 -> V_152 ) ;
if ( V_142 & V_153 )
V_6 -> V_133 = F_146 ( V_141 -> V_154 ,
V_6 -> V_13 -> V_152 ) ;
if ( V_142 & V_155 )
V_6 -> V_134 = F_146 ( V_141 -> V_156 ,
V_6 -> V_13 -> V_152 ) ;
if ( V_142 & V_157 ) {
T_6 V_158 = V_141 -> V_159 ;
if ( ! F_147 ( V_6 -> V_147 ) && ! F_148 ( V_160 ) )
V_158 &= ~ V_161 ;
F_149 ( V_6 , V_158 ) ;
}
}
int F_150 ( struct V_31 * V_31 , struct V_140 * V_141 )
{
struct V_6 * V_6 = F_109 ( V_31 ) ;
int V_12 ;
V_12 = F_151 ( V_31 , V_141 ) ;
if ( V_12 )
return V_12 ;
if ( V_141 -> V_142 & V_162 ) {
if ( F_26 ( V_6 ) &&
F_101 ( V_6 ) )
return - V_107 ;
if ( V_141 -> V_163 <= F_17 ( V_6 ) ) {
F_152 ( V_6 , V_141 -> V_163 ) ;
V_12 = F_137 ( V_6 ) ;
if ( V_12 )
return V_12 ;
F_12 ( F_3 ( V_6 ) , true ) ;
} else {
F_152 ( V_6 , V_141 -> V_163 ) ;
if ( ! F_141 ( V_6 ) ) {
V_12 = F_102 ( V_6 ) ;
if ( V_12 )
return V_12 ;
}
V_6 -> V_133 = V_6 -> V_134 = F_142 ( V_6 ) ;
}
}
F_145 ( V_6 , V_141 ) ;
if ( V_141 -> V_142 & V_157 ) {
V_12 = F_153 ( V_6 , F_154 ( V_6 ) ) ;
if ( V_12 || F_71 ( V_6 , V_164 ) ) {
V_6 -> V_27 = F_45 ( V_6 ) -> V_165 ;
F_67 ( V_6 , V_164 ) ;
}
}
F_78 ( V_6 ) ;
return V_12 ;
}
static int F_155 ( struct V_6 * V_6 , T_2 V_14 ,
V_21 V_47 , V_21 V_114 )
{
struct V_8 * V_9 = F_3 ( V_6 ) ;
struct V_5 * V_5 ;
if ( ! V_114 )
return 0 ;
F_12 ( V_9 , true ) ;
F_7 ( V_9 ) ;
V_5 = F_156 ( V_6 , NULL , V_14 , false ) ;
F_10 ( V_9 ) ;
if ( F_127 ( V_5 ) )
return F_133 ( V_5 ) ;
F_25 ( V_5 , V_26 , true ) ;
F_128 ( V_5 , V_47 , V_114 ) ;
F_22 ( V_5 ) ;
F_54 ( V_5 , 1 ) ;
return 0 ;
}
int F_157 ( struct V_6 * V_6 , T_2 V_166 , T_2 V_167 )
{
int V_12 ;
while ( V_166 < V_167 ) {
struct V_10 V_11 ;
T_2 V_88 , V_109 ;
F_8 ( & V_11 , V_6 , NULL , NULL , 0 ) ;
V_12 = F_92 ( & V_11 , V_166 , V_93 ) ;
if ( V_12 ) {
if ( V_12 == - V_94 ) {
V_166 ++ ;
continue;
}
return V_12 ;
}
V_88 = F_94 ( V_11 . V_95 , V_6 ) ;
V_109 = F_158 ( V_88 - V_11 . V_96 , V_167 - V_166 ) ;
F_5 ( F_3 ( V_6 ) , V_109 == 0 || V_109 > V_88 ) ;
F_111 ( & V_11 , V_109 ) ;
F_11 ( & V_11 ) ;
V_166 += V_109 ;
}
return 0 ;
}
static int F_159 ( struct V_6 * V_6 , V_21 V_23 , V_21 V_114 )
{
T_2 V_166 , V_167 ;
V_21 V_168 , V_169 ;
int V_42 ;
V_42 = F_102 ( V_6 ) ;
if ( V_42 )
return V_42 ;
V_166 = ( ( unsigned long long ) V_23 ) >> V_22 ;
V_167 = ( ( unsigned long long ) V_23 + V_114 ) >> V_22 ;
V_168 = V_23 & ( V_25 - 1 ) ;
V_169 = ( V_23 + V_114 ) & ( V_25 - 1 ) ;
if ( V_166 == V_167 ) {
V_42 = F_155 ( V_6 , V_166 , V_168 ,
V_169 - V_168 ) ;
if ( V_42 )
return V_42 ;
} else {
if ( V_168 ) {
V_42 = F_155 ( V_6 , V_166 ++ , V_168 ,
V_25 - V_168 ) ;
if ( V_42 )
return V_42 ;
}
if ( V_169 ) {
V_42 = F_155 ( V_6 , V_167 , 0 , V_169 ) ;
if ( V_42 )
return V_42 ;
}
if ( V_166 < V_167 ) {
struct V_71 * V_17 = V_6 -> V_18 ;
V_21 V_170 , V_171 ;
struct V_8 * V_9 = F_3 ( V_6 ) ;
F_12 ( V_9 , true ) ;
V_170 = ( V_21 ) V_166 << V_22 ;
V_171 = ( V_21 ) V_167 << V_22 ;
F_160 ( V_17 , V_170 ,
V_171 - 1 ) ;
F_7 ( V_9 ) ;
V_42 = F_157 ( V_6 , V_166 , V_167 ) ;
F_10 ( V_9 ) ;
}
}
return V_42 ;
}
static int F_161 ( struct V_6 * V_6 , T_3 * V_81 ,
int * V_172 , T_2 V_173 , T_2 V_114 )
{
struct V_8 * V_9 = F_3 ( V_6 ) ;
struct V_10 V_11 ;
int V_42 , V_174 , V_41 ;
V_175:
F_8 ( & V_11 , V_6 , NULL , NULL , 0 ) ;
V_42 = F_92 ( & V_11 , V_173 , V_131 ) ;
if ( V_42 && V_42 != - V_94 ) {
return V_42 ;
} else if ( V_42 == - V_94 ) {
if ( V_11 . V_176 == 0 )
return - V_94 ;
V_174 = F_158 ( ( T_2 ) V_119 - V_11 . V_96 , V_114 ) ;
V_81 += V_174 ;
V_172 += V_174 ;
goto V_177;
}
V_174 = F_158 ( ( T_2 ) F_94 ( V_11 . V_95 , V_6 ) -
V_11 . V_96 , V_114 ) ;
for ( V_41 = 0 ; V_41 < V_174 ; V_41 ++ , V_81 ++ , V_172 ++ , V_11 . V_96 ++ ) {
* V_81 = F_95 ( V_11 . V_95 , V_11 . V_96 ) ;
if ( ! F_162 ( V_9 , * V_81 ) ) {
if ( F_48 ( V_9 , V_178 ) ) {
F_11 ( & V_11 ) ;
return - V_179 ;
}
F_163 ( & V_11 , V_84 ) ;
* V_172 = 1 ;
}
}
F_11 ( & V_11 ) ;
V_177:
V_114 -= V_174 ;
V_173 += V_174 ;
if ( V_114 )
goto V_175;
return 0 ;
}
static int F_164 ( struct V_6 * V_6 , T_3 * V_81 ,
int * V_172 , T_2 V_173 , int V_114 )
{
struct V_8 * V_9 = F_3 ( V_6 ) ;
struct V_10 V_11 ;
int V_42 , V_41 ;
for ( V_41 = 0 ; V_41 < V_114 ; V_41 ++ , V_172 ++ , V_81 ++ ) {
if ( * V_172 == 0 )
continue;
F_8 ( & V_11 , V_6 , NULL , NULL , 0 ) ;
V_42 = F_92 ( & V_11 , V_173 + V_41 , V_131 ) ;
if ( V_42 ) {
F_121 ( V_9 , V_6 , 1 ) ;
F_116 ( V_9 , * V_81 ) ;
} else {
F_163 ( & V_11 , * V_81 ) ;
}
F_11 ( & V_11 ) ;
}
return 0 ;
}
static int F_165 ( struct V_6 * V_180 , struct V_6 * V_181 ,
T_3 * V_81 , int * V_172 ,
T_2 V_182 , T_2 V_183 , T_2 V_114 , bool V_184 )
{
struct V_8 * V_9 = F_3 ( V_180 ) ;
T_2 V_41 = 0 ;
int V_42 ;
while ( V_41 < V_114 ) {
if ( V_81 [ V_41 ] == V_84 && ! V_184 ) {
V_41 ++ ;
continue;
}
if ( V_172 [ V_41 ] || V_81 [ V_41 ] == V_84 ) {
struct V_10 V_11 ;
struct V_185 V_186 ;
T_7 V_187 ;
T_2 V_188 ;
F_8 ( & V_11 , V_181 , NULL , NULL , 0 ) ;
V_42 = F_92 ( & V_11 , V_183 + V_41 , V_189 ) ;
if ( V_42 )
return V_42 ;
F_166 ( V_9 , V_11 . V_118 , & V_186 ) ;
V_188 = F_158 ( ( T_2 )
F_94 ( V_11 . V_95 , V_181 ) -
V_11 . V_96 , V_114 - V_41 ) ;
do {
V_11 . V_28 = F_95 ( V_11 . V_95 ,
V_11 . V_96 ) ;
F_111 ( & V_11 , 1 ) ;
if ( V_172 [ V_41 ] ) {
F_167 ( V_180 ,
1 , false ) ;
F_167 ( V_181 ,
1 , true ) ;
F_168 ( V_9 , & V_11 , V_11 . V_28 ,
V_81 [ V_41 ] , V_186 . V_190 , true , false ) ;
V_172 [ V_41 ] = 0 ;
}
V_11 . V_96 ++ ;
V_41 ++ ;
V_187 = ( V_183 + V_41 ) << V_22 ;
if ( V_181 -> V_191 < V_187 )
F_169 ( V_181 , V_187 ) ;
} while ( ( V_172 [ V_41 ] || V_81 [ V_41 ] == V_84 ) && -- V_188 );
F_11 ( & V_11 ) ;
} else {
struct V_5 * V_192 , * V_193 ;
V_192 = F_126 ( V_180 , V_182 + V_41 , true ) ;
if ( F_127 ( V_192 ) )
return F_133 ( V_192 ) ;
V_193 = F_156 ( V_181 , NULL , V_183 + V_41 ,
true ) ;
if ( F_127 ( V_193 ) ) {
F_54 ( V_192 , 1 ) ;
return F_133 ( V_193 ) ;
}
F_170 ( V_192 , V_193 ) ;
F_22 ( V_193 ) ;
F_54 ( V_193 , 1 ) ;
F_54 ( V_192 , 1 ) ;
V_42 = F_157 ( V_180 , V_182 + V_41 , V_182 + V_41 + 1 ) ;
if ( V_42 )
return V_42 ;
V_41 ++ ;
}
}
return 0 ;
}
static int F_171 ( struct V_6 * V_180 ,
struct V_6 * V_181 , T_2 V_182 , T_2 V_183 ,
T_2 V_114 , bool V_184 )
{
T_3 * V_194 ;
int * V_172 ;
T_2 V_195 ;
int V_42 ;
while ( V_114 ) {
V_195 = F_158 ( ( T_2 ) 4 * V_119 , V_114 ) ;
V_194 = F_172 ( sizeof( T_3 ) * V_195 , V_196 ) ;
if ( ! V_194 )
return - V_197 ;
V_172 = F_172 ( sizeof( int ) * V_195 , V_196 ) ;
if ( ! V_172 ) {
F_173 ( V_194 ) ;
return - V_197 ;
}
V_42 = F_161 ( V_180 , V_194 ,
V_172 , V_182 , V_195 ) ;
if ( V_42 )
goto V_198;
V_42 = F_165 ( V_180 , V_181 , V_194 ,
V_172 , V_182 , V_183 , V_195 , V_184 ) ;
if ( V_42 )
goto V_198;
V_182 += V_195 ;
V_183 += V_195 ;
V_114 -= V_195 ;
F_173 ( V_194 ) ;
F_173 ( V_172 ) ;
}
return 0 ;
V_198:
F_164 ( V_180 , V_194 , V_172 , V_182 , V_114 ) ;
F_173 ( V_194 ) ;
F_173 ( V_172 ) ;
return V_42 ;
}
static int F_174 ( struct V_6 * V_6 , T_2 V_47 , T_2 V_48 )
{
struct V_8 * V_9 = F_3 ( V_6 ) ;
T_2 V_199 = ( F_17 ( V_6 ) + V_25 - 1 ) / V_25 ;
int V_42 ;
F_12 ( V_9 , true ) ;
F_7 ( V_9 ) ;
F_175 ( V_6 ) ;
V_42 = F_171 ( V_6 , V_6 , V_48 , V_47 , V_199 - V_48 , true ) ;
F_10 ( V_9 ) ;
return V_42 ;
}
static int F_176 ( struct V_6 * V_6 , V_21 V_23 , V_21 V_114 )
{
T_2 V_166 , V_167 ;
V_21 V_187 ;
int V_42 ;
if ( V_23 + V_114 >= F_17 ( V_6 ) )
return - V_101 ;
if ( V_23 & ( V_200 - 1 ) || V_114 & ( V_200 - 1 ) )
return - V_101 ;
V_42 = F_102 ( V_6 ) ;
if ( V_42 )
return V_42 ;
V_166 = V_23 >> V_22 ;
V_167 = ( V_23 + V_114 ) >> V_22 ;
V_42 = F_66 ( V_6 -> V_18 , V_23 , V_201 ) ;
if ( V_42 )
return V_42 ;
F_177 ( V_6 , V_23 ) ;
V_42 = F_174 ( V_6 , V_166 , V_167 ) ;
if ( V_42 )
return V_42 ;
F_66 ( V_6 -> V_18 , V_23 , V_201 ) ;
F_177 ( V_6 , V_23 ) ;
V_187 = F_17 ( V_6 ) - V_114 ;
F_177 ( V_6 , V_187 ) ;
V_42 = F_129 ( V_6 , V_187 , true ) ;
if ( ! V_42 )
F_169 ( V_6 , V_187 ) ;
return V_42 ;
}
static int F_178 ( struct V_10 * V_11 , T_2 V_47 ,
T_2 V_48 )
{
struct V_8 * V_9 = F_3 ( V_11 -> V_6 ) ;
T_2 V_14 = V_47 ;
unsigned int V_96 = V_11 -> V_96 ;
T_8 V_109 = 0 ;
int V_42 ;
for (; V_14 < V_48 ; V_14 ++ , V_11 -> V_96 ++ ) {
if ( F_95 ( V_11 -> V_95 , V_11 -> V_96 ) == V_84 )
V_109 ++ ;
}
V_11 -> V_96 = V_96 ;
V_42 = F_179 ( V_11 , V_109 ) ;
if ( V_42 )
return V_42 ;
V_11 -> V_96 = V_96 ;
for ( V_14 = V_47 ; V_14 < V_48 ; V_14 ++ , V_11 -> V_96 ++ ) {
V_11 -> V_28 =
F_95 ( V_11 -> V_95 , V_11 -> V_96 ) ;
if ( V_11 -> V_28 == V_84 ) {
V_42 = - V_202 ;
break;
}
if ( V_11 -> V_28 != V_83 ) {
F_116 ( V_9 , V_11 -> V_28 ) ;
V_11 -> V_28 = V_83 ;
F_115 ( V_11 ) ;
}
}
F_120 ( V_11 , V_47 , 0 , V_14 - V_47 ) ;
return V_42 ;
}
static int F_180 ( struct V_6 * V_6 , V_21 V_23 , V_21 V_114 ,
int V_158 )
{
struct V_8 * V_9 = F_3 ( V_6 ) ;
struct V_71 * V_17 = V_6 -> V_18 ;
T_2 V_14 , V_166 , V_167 ;
V_21 V_187 = F_17 ( V_6 ) ;
V_21 V_168 , V_169 ;
int V_42 = 0 ;
V_42 = F_181 ( V_6 , ( V_114 + V_23 ) ) ;
if ( V_42 )
return V_42 ;
V_42 = F_102 ( V_6 ) ;
if ( V_42 )
return V_42 ;
V_42 = F_66 ( V_17 , V_23 , V_23 + V_114 - 1 ) ;
if ( V_42 )
return V_42 ;
F_182 ( V_6 , V_23 , V_23 + V_114 - 1 ) ;
V_166 = ( ( unsigned long long ) V_23 ) >> V_22 ;
V_167 = ( ( unsigned long long ) V_23 + V_114 ) >> V_22 ;
V_168 = V_23 & ( V_25 - 1 ) ;
V_169 = ( V_23 + V_114 ) & ( V_25 - 1 ) ;
if ( V_166 == V_167 ) {
V_42 = F_155 ( V_6 , V_166 , V_168 ,
V_169 - V_168 ) ;
if ( V_42 )
return V_42 ;
if ( V_23 + V_114 > V_187 )
V_187 = V_23 + V_114 ;
V_187 = F_183 ( V_21 , V_187 , V_23 + V_114 ) ;
} else {
if ( V_168 ) {
V_42 = F_155 ( V_6 , V_166 ++ , V_168 ,
V_25 - V_168 ) ;
if ( V_42 )
return V_42 ;
V_187 = F_183 ( V_21 , V_187 ,
( V_21 ) V_166 << V_22 ) ;
}
for ( V_14 = V_166 ; V_14 < V_167 ; ) {
struct V_10 V_11 ;
unsigned int V_88 ;
T_2 V_48 ;
F_7 ( V_9 ) ;
F_8 ( & V_11 , V_6 , NULL , NULL , 0 ) ;
V_42 = F_92 ( & V_11 , V_14 , V_189 ) ;
if ( V_42 ) {
F_10 ( V_9 ) ;
goto V_15;
}
V_88 = F_94 ( V_11 . V_95 , V_6 ) ;
V_48 = F_158 ( V_167 , V_88 - V_11 . V_96 + V_14 ) ;
V_42 = F_178 ( & V_11 , V_14 , V_48 ) ;
F_11 ( & V_11 ) ;
F_10 ( V_9 ) ;
if ( V_42 )
goto V_15;
V_14 = V_48 ;
V_187 = F_183 ( V_21 , V_187 ,
( V_21 ) V_14 << V_22 ) ;
}
if ( V_169 ) {
V_42 = F_155 ( V_6 , V_167 , 0 , V_169 ) ;
if ( V_42 )
goto V_15;
V_187 = F_183 ( V_21 , V_187 , V_23 + V_114 ) ;
}
}
V_15:
if ( ! ( V_158 & V_203 ) && F_17 ( V_6 ) < V_187 )
F_169 ( V_6 , V_187 ) ;
return V_42 ;
}
static int F_184 ( struct V_6 * V_6 , V_21 V_23 , V_21 V_114 )
{
struct V_8 * V_9 = F_3 ( V_6 ) ;
T_2 V_204 , V_166 , V_167 , V_205 , V_206 ;
V_21 V_187 ;
int V_42 = 0 ;
V_187 = F_17 ( V_6 ) + V_114 ;
if ( V_187 > V_6 -> V_13 -> V_87 )
return - V_207 ;
if ( V_23 >= F_17 ( V_6 ) )
return - V_101 ;
if ( V_23 & ( V_200 - 1 ) || V_114 & ( V_200 - 1 ) )
return - V_101 ;
V_42 = F_102 ( V_6 ) ;
if ( V_42 )
return V_42 ;
F_12 ( V_9 , true ) ;
V_42 = F_129 ( V_6 , F_17 ( V_6 ) , true ) ;
if ( V_42 )
return V_42 ;
V_42 = F_66 ( V_6 -> V_18 , V_23 , V_201 ) ;
if ( V_42 )
return V_42 ;
F_177 ( V_6 , V_23 ) ;
V_166 = V_23 >> V_22 ;
V_167 = ( V_23 + V_114 ) >> V_22 ;
V_205 = V_167 - V_166 ;
V_206 = ( F_17 ( V_6 ) + V_25 - 1 ) / V_25 ;
while ( ! V_42 && V_206 > V_166 ) {
V_204 = V_206 - V_166 ;
if ( V_204 > V_205 )
V_204 = V_205 ;
V_206 -= V_204 ;
F_7 ( V_9 ) ;
F_175 ( V_6 ) ;
V_42 = F_171 ( V_6 , V_6 , V_206 ,
V_206 + V_205 , V_204 , false ) ;
F_10 ( V_9 ) ;
}
F_66 ( V_6 -> V_18 , V_23 , V_201 ) ;
F_177 ( V_6 , V_23 ) ;
if ( ! V_42 )
F_169 ( V_6 , V_187 ) ;
return V_42 ;
}
static int F_185 ( struct V_6 * V_6 , V_21 V_23 ,
V_21 V_114 , int V_158 )
{
struct V_8 * V_9 = F_3 ( V_6 ) ;
struct V_208 V_209 = { . V_210 = NULL } ;
T_2 V_167 ;
V_21 V_187 = F_17 ( V_6 ) ;
V_21 V_169 ;
int V_42 ;
V_42 = F_181 ( V_6 , ( V_114 + V_23 ) ) ;
if ( V_42 )
return V_42 ;
V_42 = F_102 ( V_6 ) ;
if ( V_42 )
return V_42 ;
F_12 ( V_9 , true ) ;
V_167 = ( ( unsigned long long ) V_23 + V_114 ) >> V_22 ;
V_169 = ( V_23 + V_114 ) & ( V_25 - 1 ) ;
V_209 . V_211 = ( ( unsigned long long ) V_23 ) >> V_22 ;
V_209 . V_212 = V_167 - V_209 . V_211 ;
if ( V_169 )
V_209 . V_212 ++ ;
V_42 = V_208 ( V_6 , & V_209 , 1 , V_213 ) ;
if ( V_42 ) {
T_2 V_214 ;
if ( ! V_209 . V_212 )
return V_42 ;
V_214 = V_209 . V_211 + V_209 . V_212 - 1 ;
V_187 = ( V_214 == V_167 ) ? V_23 + V_114 :
( V_21 ) ( V_214 + 1 ) << V_22 ;
} else {
V_187 = ( ( V_21 ) V_167 << V_22 ) + V_169 ;
}
if ( ! ( V_158 & V_203 ) && F_17 ( V_6 ) < V_187 )
F_169 ( V_6 , V_187 ) ;
return V_42 ;
}
static long F_186 ( struct V_46 * V_46 , int V_158 ,
V_21 V_23 , V_21 V_114 )
{
struct V_6 * V_6 = F_2 ( V_46 ) ;
long V_42 = 0 ;
if ( ! F_27 ( V_6 -> V_27 ) )
return - V_101 ;
if ( F_26 ( V_6 ) &&
( V_158 & ( V_215 | V_216 ) ) )
return - V_217 ;
if ( V_158 & ~ ( V_203 | V_218 |
V_215 | V_219 |
V_216 ) )
return - V_217 ;
F_90 ( V_6 ) ;
if ( V_158 & V_218 ) {
if ( V_23 >= V_6 -> V_191 )
goto V_15;
V_42 = F_159 ( V_6 , V_23 , V_114 ) ;
} else if ( V_158 & V_215 ) {
V_42 = F_176 ( V_6 , V_23 , V_114 ) ;
} else if ( V_158 & V_219 ) {
V_42 = F_180 ( V_6 , V_23 , V_114 , V_158 ) ;
} else if ( V_158 & V_216 ) {
V_42 = F_184 ( V_6 , V_23 , V_114 ) ;
} else {
V_42 = F_185 ( V_6 , V_23 , V_114 , V_158 ) ;
}
if ( ! V_42 ) {
V_6 -> V_133 = V_6 -> V_134 = F_142 ( V_6 ) ;
F_78 ( V_6 ) ;
F_31 ( F_3 ( V_6 ) , V_29 ) ;
}
V_15:
F_96 ( V_6 ) ;
F_187 ( V_6 , V_158 , V_23 , V_114 , V_42 ) ;
return V_42 ;
}
static int F_188 ( struct V_6 * V_6 , struct V_46 * V_105 )
{
if ( ! ( V_105 -> V_220 & V_221 ) ||
F_189 ( & V_6 -> V_222 ) != 1 )
return 0 ;
if ( F_190 ( V_6 ) )
F_191 ( V_6 ) ;
if ( F_192 ( V_6 ) ) {
F_67 ( V_6 , V_223 ) ;
F_65 ( V_6 , V_224 ) ;
F_193 ( V_6 -> V_18 ) ;
F_67 ( V_6 , V_224 ) ;
}
return 0 ;
}
static inline T_9 F_194 ( T_6 V_158 , T_9 V_225 )
{
if ( F_138 ( V_158 ) )
return V_225 ;
else if ( F_27 ( V_158 ) )
return V_225 & V_226 ;
else
return V_225 & V_227 ;
}
static int F_195 ( struct V_46 * V_105 , unsigned long V_228 )
{
struct V_6 * V_6 = F_2 ( V_105 ) ;
struct V_43 * V_44 = F_45 ( V_6 ) ;
unsigned int V_225 = V_44 -> V_229 & V_230 ;
return F_196 ( V_225 , ( int V_231 * ) V_228 ) ;
}
static int F_197 ( struct V_46 * V_105 , unsigned long V_228 )
{
struct V_6 * V_6 = F_2 ( V_105 ) ;
struct V_43 * V_44 = F_45 ( V_6 ) ;
unsigned int V_225 ;
unsigned int V_232 ;
int V_42 ;
if ( ! F_198 ( V_6 ) )
return - V_107 ;
if ( F_199 ( V_225 , ( int V_231 * ) V_228 ) )
return - V_19 ;
V_42 = F_200 ( V_105 ) ;
if ( V_42 )
return V_42 ;
V_225 = F_194 ( V_6 -> V_27 , V_225 ) ;
F_90 ( V_6 ) ;
V_232 = V_44 -> V_229 ;
if ( ( V_225 ^ V_232 ) & ( V_233 | V_234 ) ) {
if ( ! F_148 ( V_235 ) ) {
F_96 ( V_6 ) ;
V_42 = - V_108 ;
goto V_15;
}
}
V_225 = V_225 & V_236 ;
V_225 |= V_232 & ~ V_236 ;
V_44 -> V_229 = V_225 ;
F_96 ( V_6 ) ;
V_6 -> V_134 = F_142 ( V_6 ) ;
F_201 ( V_6 ) ;
V_15:
F_202 ( V_105 ) ;
return V_42 ;
}
static int F_203 ( struct V_46 * V_105 , unsigned long V_228 )
{
struct V_6 * V_6 = F_2 ( V_105 ) ;
return F_196 ( V_6 -> V_237 , ( int V_231 * ) V_228 ) ;
}
static int F_204 ( struct V_46 * V_105 )
{
struct V_6 * V_6 = F_2 ( V_105 ) ;
int V_42 ;
if ( ! F_198 ( V_6 ) )
return - V_107 ;
V_42 = F_200 ( V_105 ) ;
if ( V_42 )
return V_42 ;
F_90 ( V_6 ) ;
if ( F_190 ( V_6 ) )
goto V_15;
V_42 = F_102 ( V_6 ) ;
if ( V_42 )
goto V_15;
F_65 ( V_6 , V_238 ) ;
F_31 ( F_3 ( V_6 ) , V_29 ) ;
if ( ! F_63 ( V_6 ) )
goto V_15;
F_205 ( F_3 ( V_6 ) -> V_239 , V_240 ,
L_1 ,
V_6 -> V_53 , F_63 ( V_6 ) ) ;
V_42 = F_66 ( V_6 -> V_18 , 0 , V_201 ) ;
if ( V_42 )
F_67 ( V_6 , V_238 ) ;
V_15:
F_96 ( V_6 ) ;
F_202 ( V_105 ) ;
return V_42 ;
}
static int F_206 ( struct V_46 * V_105 )
{
struct V_6 * V_6 = F_2 ( V_105 ) ;
int V_42 ;
if ( ! F_198 ( V_6 ) )
return - V_107 ;
V_42 = F_200 ( V_105 ) ;
if ( V_42 )
return V_42 ;
F_90 ( V_6 ) ;
if ( F_192 ( V_6 ) )
goto V_241;
if ( F_190 ( V_6 ) ) {
F_67 ( V_6 , V_238 ) ;
V_42 = F_207 ( V_6 ) ;
if ( V_42 ) {
F_65 ( V_6 , V_238 ) ;
goto V_241;
}
}
V_42 = F_60 ( V_105 , 0 , V_201 , 0 , true ) ;
V_241:
F_96 ( V_6 ) ;
F_202 ( V_105 ) ;
return V_42 ;
}
static int F_208 ( struct V_46 * V_105 )
{
struct V_6 * V_6 = F_2 ( V_105 ) ;
int V_42 ;
if ( ! F_198 ( V_6 ) )
return - V_107 ;
V_42 = F_200 ( V_105 ) ;
if ( V_42 )
return V_42 ;
F_90 ( V_6 ) ;
if ( F_192 ( V_6 ) )
goto V_15;
V_42 = F_102 ( V_6 ) ;
if ( V_42 )
goto V_15;
F_65 ( V_6 , V_223 ) ;
F_31 ( F_3 ( V_6 ) , V_29 ) ;
V_15:
F_96 ( V_6 ) ;
F_202 ( V_105 ) ;
return V_42 ;
}
static int F_209 ( struct V_46 * V_105 )
{
struct V_6 * V_6 = F_2 ( V_105 ) ;
int V_42 ;
if ( ! F_198 ( V_6 ) )
return - V_107 ;
V_42 = F_200 ( V_105 ) ;
if ( V_42 )
return V_42 ;
F_90 ( V_6 ) ;
if ( ! F_192 ( V_6 ) )
goto V_15;
if ( ! F_210 ( V_6 ) ) {
V_42 = F_124 ( V_6 , 0 , true ) ;
goto V_15;
}
V_42 = F_159 ( V_6 , 0 , V_200 ) ;
V_15:
F_96 ( V_6 ) ;
F_202 ( V_105 ) ;
return V_42 ;
}
static int F_211 ( struct V_46 * V_105 )
{
struct V_6 * V_6 = F_2 ( V_105 ) ;
int V_42 ;
if ( ! F_198 ( V_6 ) )
return - V_107 ;
V_42 = F_200 ( V_105 ) ;
if ( V_42 )
return V_42 ;
F_90 ( V_6 ) ;
if ( F_190 ( V_6 ) )
F_191 ( V_6 ) ;
if ( F_192 ( V_6 ) ) {
F_67 ( V_6 , V_223 ) ;
V_42 = F_60 ( V_105 , 0 , V_201 , 0 , true ) ;
}
F_96 ( V_6 ) ;
F_202 ( V_105 ) ;
F_31 ( F_3 ( V_6 ) , V_29 ) ;
return V_42 ;
}
static int F_212 ( struct V_46 * V_105 , unsigned long V_228 )
{
struct V_6 * V_6 = F_2 ( V_105 ) ;
struct V_8 * V_9 = F_3 ( V_6 ) ;
struct V_242 * V_239 = V_9 -> V_239 ;
T_9 V_243 ;
int V_42 ;
if ( ! F_148 ( V_244 ) )
return - V_108 ;
if ( F_199 ( V_243 , ( T_9 V_231 * ) V_228 ) )
return - V_19 ;
V_42 = F_200 ( V_105 ) ;
if ( V_42 )
return V_42 ;
switch ( V_243 ) {
case V_245 :
V_239 = F_213 ( V_239 -> V_246 ) ;
if ( V_239 && ! F_127 ( V_239 ) ) {
F_214 ( V_9 , false ) ;
F_215 ( V_239 -> V_246 , V_239 ) ;
}
break;
case V_247 :
F_75 ( V_239 , 1 ) ;
F_214 ( V_9 , false ) ;
break;
case V_248 :
F_214 ( V_9 , false ) ;
break;
case V_249 :
F_216 ( V_9 , V_250 , V_59 ) ;
F_214 ( V_9 , false ) ;
break;
default:
V_42 = - V_101 ;
goto V_15;
}
F_31 ( V_9 , V_29 ) ;
V_15:
F_202 ( V_105 ) ;
return V_42 ;
}
static int F_217 ( struct V_46 * V_105 , unsigned long V_228 )
{
struct V_6 * V_6 = F_2 ( V_105 ) ;
struct V_242 * V_239 = V_6 -> V_13 ;
struct V_251 * V_252 = F_218 ( V_239 -> V_246 ) ;
struct V_253 V_254 ;
int V_42 ;
if ( ! F_148 ( V_244 ) )
return - V_108 ;
if ( ! F_219 ( V_252 ) )
return - V_217 ;
if ( F_220 ( & V_254 , (struct V_253 V_231 * ) V_228 ,
sizeof( V_254 ) ) )
return - V_19 ;
V_42 = F_200 ( V_105 ) ;
if ( V_42 )
return V_42 ;
V_254 . V_255 = F_221 ( ( unsigned int ) V_254 . V_255 ,
V_252 -> V_256 . V_257 ) ;
V_42 = F_222 ( F_223 ( V_239 ) , & V_254 ) ;
F_202 ( V_105 ) ;
if ( V_42 < 0 )
return V_42 ;
if ( F_224 ( (struct V_253 V_231 * ) V_228 , & V_254 ,
sizeof( V_254 ) ) )
return - V_19 ;
F_31 ( F_3 ( V_6 ) , V_29 ) ;
return 0 ;
}
static bool F_225 ( T_10 V_258 [ 16 ] )
{
int V_41 ;
for ( V_41 = 0 ; V_41 < 16 ; V_41 ++ )
if ( V_258 [ V_41 ] )
return true ;
return false ;
}
static int F_226 ( struct V_46 * V_105 , unsigned long V_228 )
{
struct V_259 V_260 ;
struct V_6 * V_6 = F_2 ( V_105 ) ;
if ( F_220 ( & V_260 , (struct V_259 V_231 * ) V_228 ,
sizeof( V_260 ) ) )
return - V_19 ;
F_31 ( F_3 ( V_6 ) , V_29 ) ;
return F_227 ( V_105 , & V_260 ) ;
}
static int F_228 ( struct V_46 * V_105 , unsigned long V_228 )
{
struct V_259 V_260 ;
struct V_6 * V_6 = F_2 ( V_105 ) ;
int V_12 ;
V_12 = F_229 ( V_6 , & V_260 ) ;
if ( V_12 )
return V_12 ;
if ( F_224 ( (struct V_259 V_231 * ) V_228 , & V_260 , sizeof( V_260 ) ) )
return - V_19 ;
return 0 ;
}
static int F_230 ( struct V_46 * V_105 , unsigned long V_228 )
{
struct V_6 * V_6 = F_2 ( V_105 ) ;
struct V_8 * V_9 = F_3 ( V_6 ) ;
int V_12 ;
if ( ! F_231 ( V_6 -> V_13 ) )
return - V_217 ;
if ( F_225 ( V_9 -> V_261 -> V_262 ) )
goto V_263;
V_12 = F_200 ( V_105 ) ;
if ( V_12 )
return V_12 ;
F_232 ( V_9 -> V_261 -> V_262 ) ;
V_12 = F_233 ( V_9 , false ) ;
if ( V_12 ) {
memset ( V_9 -> V_261 -> V_262 , 0 , 16 ) ;
F_202 ( V_105 ) ;
return V_12 ;
}
F_202 ( V_105 ) ;
V_263:
if ( F_224 ( ( T_10 V_231 * ) V_228 , V_9 -> V_261 -> V_262 ,
16 ) )
return - V_19 ;
return 0 ;
}
static int F_234 ( struct V_46 * V_105 , unsigned long V_228 )
{
struct V_6 * V_6 = F_2 ( V_105 ) ;
struct V_8 * V_9 = F_3 ( V_6 ) ;
T_9 V_264 ;
int V_42 ;
if ( ! F_148 ( V_244 ) )
return - V_108 ;
if ( F_199 ( V_264 , ( T_9 V_231 * ) V_228 ) )
return - V_19 ;
if ( F_61 ( V_9 -> V_239 ) )
return - V_265 ;
V_42 = F_200 ( V_105 ) ;
if ( V_42 )
return V_42 ;
if ( ! V_264 ) {
if ( ! F_235 ( & V_9 -> V_266 ) ) {
V_42 = - V_267 ;
goto V_15;
}
} else {
F_236 ( & V_9 -> V_266 ) ;
}
V_42 = F_237 ( V_9 , V_264 ) ;
V_15:
F_202 ( V_105 ) ;
return V_42 ;
}
static int F_238 ( struct V_46 * V_105 , unsigned long V_228 )
{
struct V_6 * V_6 = F_2 ( V_105 ) ;
struct V_8 * V_9 = F_3 ( V_6 ) ;
int V_42 ;
if ( ! F_148 ( V_244 ) )
return - V_108 ;
if ( F_61 ( V_9 -> V_239 ) )
return - V_265 ;
V_42 = F_200 ( V_105 ) ;
if ( V_42 )
return V_42 ;
V_42 = F_75 ( V_9 -> V_239 , 1 ) ;
F_202 ( V_105 ) ;
return V_42 ;
}
static int F_239 ( struct V_8 * V_9 ,
struct V_46 * V_105 ,
struct V_268 * V_254 )
{
struct V_6 * V_6 = F_2 ( V_105 ) ;
struct V_208 V_209 = { . V_210 = NULL } ;
struct V_269 V_270 ;
T_2 V_166 , V_167 ;
unsigned int V_271 = V_9 -> V_272 ;
unsigned int V_273 = 0 , V_274 ;
unsigned int V_275 = V_9 -> V_276 * V_271 ;
T_3 V_171 = 0 ;
bool V_277 = false ;
int V_12 ;
if ( F_240 ( V_6 ) )
return - V_101 ;
V_166 = V_254 -> V_47 >> V_22 ;
V_167 = ( V_254 -> V_47 + V_254 -> V_114 ) >> V_22 ;
F_12 ( V_9 , true ) ;
F_90 ( V_6 ) ;
V_12 = F_66 ( V_6 -> V_18 , V_254 -> V_47 ,
V_254 -> V_47 + V_254 -> V_114 - 1 ) ;
if ( V_12 )
goto V_15;
if ( F_241 ( V_6 , V_166 , & V_270 ) ) {
if ( V_270 . V_117 + V_270 . V_114 >= V_167 )
goto V_15;
}
V_209 . V_211 = V_166 ;
while ( V_209 . V_211 < V_167 ) {
V_209 . V_212 = V_167 - V_209 . V_211 ;
V_12 = V_208 ( V_6 , & V_209 , 0 , V_278 ) ;
if ( V_12 )
goto V_15;
if ( ! ( V_209 . V_279 & V_280 ) ) {
V_209 . V_211 ++ ;
continue;
}
if ( V_171 && V_171 != V_209 . V_281 ) {
V_277 = true ;
break;
}
V_171 = V_209 . V_281 + V_209 . V_212 ;
V_209 . V_211 += V_209 . V_212 ;
}
if ( ! V_277 )
goto V_15;
V_209 . V_211 = V_166 ;
V_209 . V_212 = V_167 - V_166 ;
V_274 = ( V_209 . V_212 + V_275 - 1 ) / V_275 ;
if ( F_242 ( V_9 , 0 , V_274 ) ) {
V_12 = - V_282 ;
goto V_15;
}
while ( V_209 . V_211 < V_167 ) {
T_2 V_206 ;
int V_283 = 0 ;
V_284:
V_209 . V_212 = V_167 - V_209 . V_211 ;
V_12 = V_208 ( V_6 , & V_209 , 0 , V_278 ) ;
if ( V_12 )
goto V_285;
if ( ! ( V_209 . V_279 & V_280 ) ) {
V_209 . V_211 ++ ;
continue;
}
F_65 ( V_6 , V_286 ) ;
V_206 = V_209 . V_211 ;
while ( V_206 < V_209 . V_211 + V_209 . V_212 && V_283 < V_271 ) {
struct V_5 * V_5 ;
V_5 = F_126 ( V_6 , V_206 , true ) ;
if ( F_127 ( V_5 ) ) {
V_12 = F_133 ( V_5 ) ;
goto V_285;
}
F_22 ( V_5 ) ;
F_54 ( V_5 , 1 ) ;
V_206 ++ ;
V_283 ++ ;
V_273 ++ ;
}
V_209 . V_211 = V_206 ;
if ( V_206 < V_167 && V_283 < V_271 )
goto V_284;
F_67 ( V_6 , V_286 ) ;
V_12 = F_193 ( V_6 -> V_18 ) ;
if ( V_12 )
goto V_15;
}
V_285:
F_67 ( V_6 , V_286 ) ;
V_15:
F_96 ( V_6 ) ;
if ( ! V_12 )
V_254 -> V_114 = ( T_5 ) V_273 << V_22 ;
return V_12 ;
}
static int F_243 ( struct V_46 * V_105 , unsigned long V_228 )
{
struct V_6 * V_6 = F_2 ( V_105 ) ;
struct V_8 * V_9 = F_3 ( V_6 ) ;
struct V_268 V_254 ;
int V_12 ;
if ( ! F_148 ( V_244 ) )
return - V_108 ;
if ( ! F_27 ( V_6 -> V_27 ) )
return - V_101 ;
V_12 = F_200 ( V_105 ) ;
if ( V_12 )
return V_12 ;
if ( F_61 ( V_9 -> V_239 ) ) {
V_12 = - V_265 ;
goto V_15;
}
if ( F_220 ( & V_254 , (struct V_268 V_231 * ) V_228 ,
sizeof( V_254 ) ) ) {
V_12 = - V_19 ;
goto V_15;
}
if ( V_254 . V_47 & ( V_200 - 1 ) ||
V_254 . V_114 & ( V_200 - 1 ) ) {
V_12 = - V_101 ;
goto V_15;
}
V_12 = F_239 ( V_9 , V_105 , & V_254 ) ;
F_31 ( V_9 , V_29 ) ;
if ( V_12 < 0 )
goto V_15;
if ( F_224 ( (struct V_268 V_231 * ) V_228 , & V_254 ,
sizeof( V_254 ) ) )
V_12 = - V_19 ;
V_15:
F_202 ( V_105 ) ;
return V_12 ;
}
static int F_244 ( struct V_46 * V_287 , V_21 V_288 ,
struct V_46 * V_289 , V_21 V_290 , T_7 V_114 )
{
struct V_6 * V_182 = F_2 ( V_287 ) ;
struct V_6 * V_183 = F_2 ( V_289 ) ;
struct V_8 * V_9 = F_3 ( V_182 ) ;
T_7 V_195 = V_114 , V_291 = 0 ;
T_7 V_292 ;
int V_42 ;
if ( V_287 -> V_293 . V_136 != V_289 -> V_293 . V_136 ||
V_182 -> V_13 != V_183 -> V_13 )
return - V_294 ;
if ( F_15 ( F_61 ( V_182 -> V_13 ) ) )
return - V_265 ;
if ( ! F_27 ( V_182 -> V_27 ) || ! F_27 ( V_183 -> V_27 ) )
return - V_101 ;
if ( F_26 ( V_182 ) || F_26 ( V_183 ) )
return - V_217 ;
if ( V_182 == V_183 ) {
if ( V_288 == V_290 )
return 0 ;
if ( V_290 > V_288 && V_290 < V_288 + V_114 )
return - V_101 ;
}
F_90 ( V_182 ) ;
if ( V_182 != V_183 ) {
if ( ! F_245 ( V_183 ) ) {
V_42 = - V_267 ;
goto V_15;
}
}
V_42 = - V_101 ;
if ( V_288 + V_114 > V_182 -> V_191 || V_288 + V_114 < V_288 )
goto V_295;
if ( V_114 == 0 )
V_195 = V_114 = V_182 -> V_191 - V_288 ;
if ( V_288 + V_114 == V_182 -> V_191 )
V_114 = F_246 ( V_182 -> V_191 , V_200 ) - V_288 ;
if ( V_114 == 0 ) {
V_42 = 0 ;
goto V_295;
}
V_292 = V_183 -> V_191 ;
if ( V_290 + V_195 > V_183 -> V_191 )
V_291 = V_290 + V_195 ;
if ( ! F_247 ( V_288 , V_200 ) ||
! F_247 ( V_288 + V_114 , V_200 ) ||
! F_247 ( V_290 , V_200 ) )
goto V_295;
V_42 = F_102 ( V_182 ) ;
if ( V_42 )
goto V_295;
V_42 = F_102 ( V_183 ) ;
if ( V_42 )
goto V_295;
V_42 = F_66 ( V_182 -> V_18 ,
V_288 , V_288 + V_114 ) ;
if ( V_42 )
goto V_295;
V_42 = F_66 ( V_183 -> V_18 ,
V_290 , V_290 + V_114 ) ;
if ( V_42 )
goto V_295;
F_12 ( V_9 , true ) ;
F_7 ( V_9 ) ;
V_42 = F_171 ( V_182 , V_183 , V_288 >> V_296 ,
V_290 >> V_296 ,
V_114 >> V_296 , false ) ;
if ( ! V_42 ) {
if ( V_291 )
F_169 ( V_183 , V_291 ) ;
else if ( V_292 != V_183 -> V_191 )
F_169 ( V_183 , V_292 ) ;
}
F_10 ( V_9 ) ;
V_295:
if ( V_182 != V_183 )
F_96 ( V_183 ) ;
V_15:
F_96 ( V_182 ) ;
return V_42 ;
}
static int F_248 ( struct V_46 * V_105 , unsigned long V_228 )
{
struct V_297 V_254 ;
struct V_298 V_183 ;
int V_12 ;
if ( ! ( V_105 -> V_220 & V_299 ) ||
! ( V_105 -> V_220 & V_221 ) )
return - V_300 ;
if ( F_220 ( & V_254 , (struct V_297 V_231 * ) V_228 ,
sizeof( V_254 ) ) )
return - V_19 ;
V_183 = F_249 ( V_254 . V_301 ) ;
if ( ! V_183 . V_46 )
return - V_300 ;
if ( ! ( V_183 . V_46 -> V_220 & V_221 ) ) {
V_12 = - V_300 ;
goto V_241;
}
V_12 = F_200 ( V_105 ) ;
if ( V_12 )
goto V_241;
V_12 = F_244 ( V_105 , V_254 . V_288 , V_183 . V_46 ,
V_254 . V_290 , V_254 . V_114 ) ;
F_202 ( V_105 ) ;
if ( F_224 ( (struct V_297 V_231 * ) V_228 ,
& V_254 , sizeof( V_254 ) ) )
V_12 = - V_19 ;
V_241:
F_250 ( V_183 ) ;
return V_12 ;
}
long F_251 ( struct V_46 * V_105 , unsigned int V_302 , unsigned long V_228 )
{
switch ( V_302 ) {
case V_303 :
return F_195 ( V_105 , V_228 ) ;
case V_304 :
return F_197 ( V_105 , V_228 ) ;
case V_305 :
return F_203 ( V_105 , V_228 ) ;
case V_306 :
return F_204 ( V_105 ) ;
case V_307 :
return F_206 ( V_105 ) ;
case V_308 :
return F_208 ( V_105 ) ;
case V_309 :
return F_209 ( V_105 ) ;
case V_310 :
return F_211 ( V_105 ) ;
case V_311 :
return F_212 ( V_105 , V_228 ) ;
case V_312 :
return F_217 ( V_105 , V_228 ) ;
case V_313 :
return F_226 ( V_105 , V_228 ) ;
case V_314 :
return F_228 ( V_105 , V_228 ) ;
case V_315 :
return F_230 ( V_105 , V_228 ) ;
case V_316 :
return F_234 ( V_105 , V_228 ) ;
case V_317 :
return F_238 ( V_105 , V_228 ) ;
case V_318 :
return F_243 ( V_105 , V_228 ) ;
case V_319 :
return F_248 ( V_105 , V_228 ) ;
default:
return - V_320 ;
}
}
static T_11 F_252 ( struct V_321 * V_322 , struct V_323 * V_120 )
{
struct V_46 * V_46 = V_322 -> V_324 ;
struct V_6 * V_6 = F_2 ( V_46 ) ;
struct V_325 V_326 ;
T_11 V_42 ;
if ( F_26 ( V_6 ) &&
! F_106 ( V_6 ) &&
F_101 ( V_6 ) )
return - V_107 ;
F_90 ( V_6 ) ;
V_42 = F_253 ( V_322 , V_120 ) ;
if ( V_42 > 0 ) {
V_42 = F_254 ( V_322 , V_120 ) ;
if ( ! V_42 ) {
F_255 ( & V_326 ) ;
V_42 = F_256 ( V_322 , V_120 ) ;
F_257 ( & V_326 ) ;
}
}
F_96 ( V_6 ) ;
if ( V_42 > 0 )
V_42 = F_258 ( V_322 , V_42 ) ;
return V_42 ;
}
long F_259 ( struct V_46 * V_46 , unsigned int V_302 , unsigned long V_228 )
{
switch ( V_302 ) {
case V_327 :
V_302 = V_303 ;
break;
case V_328 :
V_302 = V_304 ;
break;
case V_329 :
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
return - V_330 ;
}
return F_251 ( V_46 , V_302 , ( unsigned long ) F_260 ( V_228 ) ) ;
}
