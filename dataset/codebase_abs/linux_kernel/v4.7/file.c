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
else if ( F_41 ( V_6 ) && F_42 ( V_9 , V_6 -> V_35 ) )
V_33 = true ;
else if ( F_43 ( V_6 ) )
V_33 = true ;
else if ( ! F_44 ( V_9 ) )
V_33 = true ;
else if ( ! F_45 ( V_9 , F_46 ( V_6 ) -> V_36 ) )
V_33 = true ;
else if ( F_46 ( V_6 ) -> V_37 == F_47 ( F_48 ( V_9 ) ) )
V_33 = true ;
else if ( F_49 ( V_9 , V_38 ) )
V_33 = true ;
else if ( V_9 -> V_39 == 2 )
V_33 = true ;
return V_33 ;
}
static bool F_50 ( struct V_8 * V_9 , T_1 V_40 )
{
struct V_5 * V_41 = F_51 ( F_52 ( V_9 ) , V_40 ) ;
bool V_42 = false ;
if ( ( V_41 && F_53 ( V_41 ) ) || F_54 ( V_9 , V_40 ) )
V_42 = true ;
F_55 ( V_41 , 0 ) ;
return V_42 ;
}
static void F_56 ( struct V_6 * V_6 )
{
struct V_43 * V_44 = F_46 ( V_6 ) ;
T_1 V_30 ;
F_57 ( & V_44 -> V_45 ) ;
V_44 -> V_37 = 0 ;
if ( F_43 ( V_6 ) && V_6 -> V_34 == 1 &&
F_33 ( V_6 , & V_30 ) ) {
V_44 -> V_36 = V_30 ;
F_58 ( V_6 ) ;
F_59 ( & V_44 -> V_45 ) ;
F_60 ( V_6 ) ;
F_61 ( V_6 , NULL ) ;
} else {
F_59 ( & V_44 -> V_45 ) ;
}
}
static int F_62 ( struct V_46 * V_46 , V_21 V_47 , V_21 V_48 ,
int V_49 , bool V_50 )
{
struct V_6 * V_6 = V_46 -> V_51 -> V_52 ;
struct V_43 * V_44 = F_46 ( V_6 ) ;
struct V_8 * V_9 = F_3 ( V_6 ) ;
T_1 V_40 = V_6 -> V_35 ;
int V_42 = 0 ;
bool V_33 = false ;
struct V_53 V_54 = {
. V_55 = V_56 ,
. V_57 = V_58 ,
. V_59 = 0 ,
} ;
if ( F_15 ( F_63 ( V_6 -> V_13 ) ) )
return 0 ;
F_64 ( V_6 ) ;
if ( V_49 || F_65 ( V_6 ) <= F_66 ( V_9 ) -> V_60 )
F_67 ( V_44 , V_61 ) ;
V_42 = F_68 ( V_6 -> V_18 , V_47 , V_48 ) ;
F_69 ( V_44 , V_61 ) ;
if ( V_42 ) {
F_70 ( V_6 , V_33 , V_49 , V_42 ) ;
return V_42 ;
}
if ( ! V_49 ) {
F_61 ( V_6 , NULL ) ;
goto V_62;
}
if ( ! F_71 ( V_44 , V_63 ) &&
! F_72 ( V_9 , V_40 , V_64 ) ) {
if ( F_50 ( V_9 , V_40 ) )
goto V_62;
if ( F_71 ( V_44 , V_65 ) ||
F_72 ( V_9 , V_40 , V_66 ) )
goto V_67;
goto V_15;
}
V_62:
F_73 ( & V_44 -> V_45 ) ;
V_33 = F_40 ( V_6 ) ;
F_74 ( & V_44 -> V_45 ) ;
if ( V_33 ) {
V_42 = F_75 ( V_6 -> V_13 , 1 ) ;
F_56 ( V_6 ) ;
F_69 ( V_44 , V_63 ) ;
F_69 ( V_44 , V_65 ) ;
goto V_15;
}
V_68:
V_42 = F_76 ( V_9 , V_40 , & V_54 , V_50 ) ;
if ( V_42 )
goto V_15;
if ( F_15 ( F_77 ( V_9 ) ) ) {
V_42 = - V_69 ;
goto V_15;
}
if ( F_54 ( V_9 , V_40 ) ) {
F_60 ( V_6 ) ;
F_61 ( V_6 , NULL ) ;
goto V_68;
}
V_42 = F_78 ( V_9 , V_40 ) ;
if ( V_42 )
goto V_15;
F_79 ( V_9 , V_40 , V_64 ) ;
F_69 ( V_44 , V_63 ) ;
V_67:
F_79 ( V_9 , V_40 , V_66 ) ;
F_69 ( V_44 , V_65 ) ;
V_42 = F_80 ( V_9 ) ;
F_31 ( V_9 , V_29 ) ;
V_15:
F_70 ( V_6 , V_33 , V_49 , V_42 ) ;
F_81 ( NULL , 1 ) ;
return V_42 ;
}
int F_82 ( struct V_46 * V_46 , V_21 V_47 , V_21 V_48 , int V_49 )
{
return F_62 ( V_46 , V_47 , V_48 , V_49 , false ) ;
}
static T_2 F_83 ( struct V_70 * V_17 ,
T_2 V_71 , int V_72 )
{
struct V_73 V_74 ;
int V_75 ;
if ( V_72 != V_76 )
return 0 ;
F_84 ( & V_74 , 0 ) ;
V_75 = F_85 ( & V_74 , V_17 , & V_71 ,
V_77 , 1 ) ;
V_71 = V_75 ? V_74 . V_78 [ 0 ] -> V_14 : V_79 ;
F_86 ( & V_74 ) ;
return V_71 ;
}
static bool F_87 ( T_3 V_80 , T_2 V_81 , T_2 V_71 ,
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
static V_21 F_88 ( struct V_46 * V_46 , V_21 V_23 , int V_72 )
{
struct V_6 * V_6 = V_46 -> V_51 -> V_52 ;
V_21 V_85 = V_6 -> V_13 -> V_86 ;
struct V_10 V_11 ;
T_2 V_71 , V_87 , V_81 ;
V_21 V_88 = V_23 ;
V_21 V_89 ;
int V_12 = 0 ;
F_89 ( V_6 ) ;
V_89 = F_17 ( V_6 ) ;
if ( V_23 >= V_89 )
goto V_90;
if ( F_6 ( V_6 ) || F_90 ( V_6 ) ) {
if ( V_72 == V_84 )
V_88 = V_89 ;
goto V_91;
}
V_71 = ( T_2 ) ( V_23 >> V_22 ) ;
V_81 = F_83 ( V_6 -> V_18 , V_71 , V_72 ) ;
for (; V_88 < V_89 ; V_88 = ( V_21 ) V_71 << V_22 ) {
F_8 ( & V_11 , V_6 , NULL , NULL , 0 ) ;
V_12 = F_91 ( & V_11 , V_71 , V_92 ) ;
if ( V_12 && V_12 != - V_93 ) {
goto V_90;
} else if ( V_12 == - V_93 ) {
if ( V_72 == V_76 ) {
V_71 = F_92 ( & V_11 , V_71 ) ;
continue;
} else {
goto V_91;
}
}
V_87 = F_93 ( V_11 . V_94 , V_6 ) ;
for (; V_11 . V_95 < V_87 ;
V_11 . V_95 ++ , V_71 ++ ,
V_88 = ( V_21 ) V_71 << V_22 ) {
T_3 V_80 ;
V_80 = F_94 ( V_11 . V_94 , V_11 . V_95 ) ;
if ( F_87 ( V_80 , V_81 , V_71 , V_72 ) ) {
F_11 ( & V_11 ) ;
goto V_91;
}
}
F_11 ( & V_11 ) ;
}
if ( V_72 == V_76 )
goto V_90;
V_91:
if ( V_72 == V_84 && V_88 > V_89 )
V_88 = V_89 ;
F_95 ( V_6 ) ;
return F_96 ( V_46 , V_88 , V_85 ) ;
V_90:
F_95 ( V_6 ) ;
return - V_96 ;
}
static V_21 F_97 ( struct V_46 * V_46 , V_21 V_23 , int V_72 )
{
struct V_6 * V_6 = V_46 -> V_51 -> V_52 ;
V_21 V_85 = V_6 -> V_13 -> V_86 ;
switch ( V_72 ) {
case V_97 :
case V_98 :
case V_99 :
return F_98 ( V_46 , V_23 , V_72 ,
V_85 , F_17 ( V_6 ) ) ;
case V_76 :
case V_84 :
if ( V_23 < 0 )
return - V_96 ;
return F_88 ( V_46 , V_23 , V_72 ) ;
}
return - V_100 ;
}
static int F_99 ( struct V_46 * V_46 , struct V_1 * V_2 )
{
struct V_6 * V_6 = F_2 ( V_46 ) ;
int V_12 ;
if ( F_26 ( V_6 ) ) {
V_12 = F_100 ( V_6 ) ;
if ( V_12 )
return 0 ;
if ( ! F_26 ( V_6 ) )
return - V_101 ;
}
V_12 = F_101 ( V_6 ) ;
if ( V_12 )
return V_12 ;
F_102 ( V_46 ) ;
V_2 -> V_102 = & V_103 ;
return 0 ;
}
static int F_103 ( struct V_6 * V_6 , struct V_46 * V_104 )
{
int V_42 = F_104 ( V_6 , V_104 ) ;
struct V_31 * V_105 ;
if ( ! V_42 && F_26 ( V_6 ) ) {
V_42 = F_100 ( V_6 ) ;
if ( V_42 )
return - V_106 ;
if ( ! F_105 ( V_6 ) )
return - V_101 ;
}
V_105 = F_106 ( F_107 ( V_104 ) ) ;
if ( F_26 ( F_108 ( V_105 ) ) &&
! F_109 ( F_108 ( V_105 ) , V_6 ) ) {
F_38 ( V_105 ) ;
return - V_107 ;
}
F_38 ( V_105 ) ;
return V_42 ;
}
int F_110 ( struct V_10 * V_11 , int V_108 )
{
struct V_8 * V_9 = F_3 ( V_11 -> V_6 ) ;
struct V_109 * V_110 ;
int V_111 = 0 , V_112 = V_11 -> V_95 , V_113 = V_108 ;
T_4 * V_114 ;
V_110 = F_111 ( V_11 -> V_94 ) ;
V_114 = F_112 ( V_110 ) + V_112 ;
for (; V_108 > 0 ; V_108 -- , V_114 ++ , V_11 -> V_95 ++ ) {
T_3 V_80 = F_113 ( * V_114 ) ;
if ( V_80 == V_83 )
continue;
V_11 -> V_28 = V_83 ;
F_114 ( V_11 ) ;
F_115 ( V_9 , V_80 ) ;
if ( V_11 -> V_95 == 0 && F_116 ( V_11 -> V_94 ) )
F_69 ( F_46 ( V_11 -> V_6 ) ,
V_115 ) ;
V_111 ++ ;
}
if ( V_111 ) {
T_2 V_116 ;
V_116 = F_117 ( F_118 ( V_11 -> V_94 ) ,
V_11 -> V_6 ) + V_112 ;
F_119 ( V_11 , V_116 , 0 , V_113 ) ;
F_120 ( V_9 , V_11 -> V_6 , V_111 ) ;
F_121 ( V_11 ) ;
}
V_11 -> V_95 = V_112 ;
F_31 ( V_9 , V_29 ) ;
F_122 ( V_11 -> V_6 , V_11 -> V_117 ,
V_11 -> V_95 , V_111 ) ;
return V_111 ;
}
void F_123 ( struct V_10 * V_11 )
{
F_110 ( V_11 , V_118 ) ;
}
static int F_124 ( struct V_6 * V_6 , T_5 V_119 ,
bool V_120 )
{
unsigned V_23 = V_119 & ( V_25 - 1 ) ;
T_2 V_14 = V_119 >> V_22 ;
struct V_70 * V_17 = V_6 -> V_18 ;
struct V_5 * V_5 ;
if ( ! V_23 && ! V_120 )
return 0 ;
if ( V_120 ) {
V_5 = F_125 ( V_17 , V_14 , false ) ;
if ( V_5 && F_18 ( V_5 ) )
goto V_121;
F_55 ( V_5 , 1 ) ;
return 0 ;
}
V_5 = F_126 ( V_6 , V_14 , true ) ;
if ( F_127 ( V_5 ) )
return 0 ;
V_121:
F_25 ( V_5 , V_26 , true ) ;
F_128 ( V_5 , V_23 , V_25 - V_23 ) ;
if ( ! V_120 || ! F_26 ( V_6 ) ||
! F_27 ( V_6 -> V_27 ) )
F_22 ( V_5 ) ;
F_55 ( V_5 , 1 ) ;
return 0 ;
}
int F_129 ( struct V_6 * V_6 , T_5 V_119 , bool V_122 )
{
struct V_8 * V_9 = F_3 ( V_6 ) ;
unsigned int V_123 = V_6 -> V_13 -> V_124 ;
struct V_10 V_11 ;
T_2 V_125 ;
int V_108 = 0 , V_12 = 0 ;
struct V_5 * V_126 ;
bool V_127 = false ;
F_130 ( V_6 , V_119 ) ;
V_125 = ( T_2 ) F_131 ( V_119 + V_123 - 1 ) ;
if ( V_125 >= V_9 -> V_128 )
goto V_129;
if ( V_122 )
F_7 ( V_9 ) ;
V_126 = F_132 ( V_9 , V_6 -> V_35 ) ;
if ( F_127 ( V_126 ) ) {
V_12 = F_133 ( V_126 ) ;
goto V_15;
}
if ( F_6 ( V_6 ) ) {
if ( F_134 ( V_126 , V_119 ) )
F_22 ( V_126 ) ;
F_55 ( V_126 , 1 ) ;
V_127 = true ;
goto V_15;
}
F_8 ( & V_11 , V_6 , V_126 , NULL , 0 ) ;
V_12 = F_91 ( & V_11 , V_125 , V_92 ) ;
if ( V_12 ) {
if ( V_12 == - V_93 )
goto V_130;
goto V_15;
}
V_108 = F_93 ( V_11 . V_94 , V_6 ) ;
V_108 -= V_11 . V_95 ;
F_5 ( V_9 , V_108 < 0 ) ;
if ( V_11 . V_95 || F_116 ( V_11 . V_94 ) ) {
F_110 ( & V_11 , V_108 ) ;
V_125 += V_108 ;
}
F_11 ( & V_11 ) ;
V_130:
V_12 = F_135 ( V_6 , V_125 ) ;
V_15:
if ( V_122 )
F_10 ( V_9 ) ;
V_129:
if ( ! V_12 )
V_12 = F_124 ( V_6 , V_119 , V_127 ) ;
F_136 ( V_6 , V_12 ) ;
return V_12 ;
}
int F_137 ( struct V_6 * V_6 , bool V_122 )
{
int V_12 ;
if ( ! ( F_27 ( V_6 -> V_27 ) || F_138 ( V_6 -> V_27 ) ||
F_139 ( V_6 -> V_27 ) ) )
return 0 ;
F_140 ( V_6 ) ;
if ( ! F_141 ( V_6 ) ) {
V_12 = F_101 ( V_6 ) ;
if ( V_12 )
return V_12 ;
}
V_12 = F_129 ( V_6 , F_17 ( V_6 ) , V_122 ) ;
if ( V_12 )
return V_12 ;
V_6 -> V_131 = V_6 -> V_132 = V_133 ;
F_142 ( V_6 ) ;
return 0 ;
}
int F_143 ( struct V_134 * V_135 ,
struct V_31 * V_31 , struct V_136 * V_137 )
{
struct V_6 * V_6 = F_108 ( V_31 ) ;
F_144 ( V_6 , V_137 ) ;
V_137 -> V_138 <<= 3 ;
return 0 ;
}
static void F_145 ( struct V_6 * V_6 , const struct V_139 * V_140 )
{
struct V_43 * V_44 = F_46 ( V_6 ) ;
unsigned int V_141 = V_140 -> V_141 ;
if ( V_141 & V_142 )
V_6 -> V_143 = V_140 -> V_144 ;
if ( V_141 & V_145 )
V_6 -> V_146 = V_140 -> V_147 ;
if ( V_141 & V_148 )
V_6 -> V_149 = F_146 ( V_140 -> V_150 ,
V_6 -> V_13 -> V_151 ) ;
if ( V_141 & V_152 )
V_6 -> V_131 = F_146 ( V_140 -> V_153 ,
V_6 -> V_13 -> V_151 ) ;
if ( V_141 & V_154 )
V_6 -> V_132 = F_146 ( V_140 -> V_155 ,
V_6 -> V_13 -> V_151 ) ;
if ( V_141 & V_156 ) {
T_6 V_157 = V_140 -> V_158 ;
if ( ! F_147 ( V_6 -> V_146 ) && ! F_148 ( V_159 ) )
V_157 &= ~ V_160 ;
F_149 ( V_44 , V_157 ) ;
}
}
int F_150 ( struct V_31 * V_31 , struct V_139 * V_140 )
{
struct V_6 * V_6 = F_108 ( V_31 ) ;
struct V_43 * V_44 = F_46 ( V_6 ) ;
int V_12 ;
V_12 = F_151 ( V_6 , V_140 ) ;
if ( V_12 )
return V_12 ;
if ( V_140 -> V_141 & V_161 ) {
if ( F_26 ( V_6 ) &&
F_100 ( V_6 ) )
return - V_106 ;
if ( V_140 -> V_162 <= F_17 ( V_6 ) ) {
F_152 ( V_6 , V_140 -> V_162 ) ;
V_12 = F_137 ( V_6 , true ) ;
if ( V_12 )
return V_12 ;
F_12 ( F_3 ( V_6 ) , true ) ;
} else {
F_152 ( V_6 , V_140 -> V_162 ) ;
if ( ! F_141 ( V_6 ) ) {
V_12 = F_101 ( V_6 ) ;
if ( V_12 )
return V_12 ;
}
V_6 -> V_131 = V_6 -> V_132 = V_133 ;
}
}
F_145 ( V_6 , V_140 ) ;
if ( V_140 -> V_141 & V_156 ) {
V_12 = F_153 ( V_6 , F_154 ( V_6 ) ) ;
if ( V_12 || F_71 ( V_44 , V_163 ) ) {
V_6 -> V_27 = V_44 -> V_164 ;
F_69 ( V_44 , V_163 ) ;
}
}
F_142 ( V_6 ) ;
return V_12 ;
}
static int F_155 ( struct V_6 * V_6 , T_2 V_14 ,
V_21 V_47 , V_21 V_113 )
{
struct V_8 * V_9 = F_3 ( V_6 ) ;
struct V_5 * V_5 ;
if ( ! V_113 )
return 0 ;
F_12 ( V_9 , true ) ;
F_7 ( V_9 ) ;
V_5 = F_156 ( V_6 , NULL , V_14 , false ) ;
F_10 ( V_9 ) ;
if ( F_127 ( V_5 ) )
return F_133 ( V_5 ) ;
F_25 ( V_5 , V_26 , true ) ;
F_128 ( V_5 , V_47 , V_113 ) ;
F_22 ( V_5 ) ;
F_55 ( V_5 , 1 ) ;
return 0 ;
}
int F_157 ( struct V_6 * V_6 , T_2 V_165 , T_2 V_166 )
{
int V_12 ;
while ( V_165 < V_166 ) {
struct V_10 V_11 ;
T_2 V_87 , V_108 ;
F_8 ( & V_11 , V_6 , NULL , NULL , 0 ) ;
V_12 = F_91 ( & V_11 , V_165 , V_167 ) ;
if ( V_12 ) {
if ( V_12 == - V_93 ) {
V_165 ++ ;
continue;
}
return V_12 ;
}
V_87 = F_93 ( V_11 . V_94 , V_6 ) ;
V_108 = F_158 ( V_87 - V_11 . V_95 , V_166 - V_165 ) ;
F_5 ( F_3 ( V_6 ) , V_108 == 0 || V_108 > V_87 ) ;
F_110 ( & V_11 , V_108 ) ;
F_11 ( & V_11 ) ;
V_165 += V_108 ;
}
return 0 ;
}
static int F_159 ( struct V_6 * V_6 , V_21 V_23 , V_21 V_113 )
{
T_2 V_165 , V_166 ;
V_21 V_168 , V_169 ;
int V_42 ;
V_42 = F_101 ( V_6 ) ;
if ( V_42 )
return V_42 ;
V_165 = ( ( unsigned long long ) V_23 ) >> V_22 ;
V_166 = ( ( unsigned long long ) V_23 + V_113 ) >> V_22 ;
V_168 = V_23 & ( V_25 - 1 ) ;
V_169 = ( V_23 + V_113 ) & ( V_25 - 1 ) ;
if ( V_165 == V_166 ) {
V_42 = F_155 ( V_6 , V_165 , V_168 ,
V_169 - V_168 ) ;
if ( V_42 )
return V_42 ;
} else {
if ( V_168 ) {
V_42 = F_155 ( V_6 , V_165 ++ , V_168 ,
V_25 - V_168 ) ;
if ( V_42 )
return V_42 ;
}
if ( V_169 ) {
V_42 = F_155 ( V_6 , V_166 , 0 , V_169 ) ;
if ( V_42 )
return V_42 ;
}
if ( V_165 < V_166 ) {
struct V_70 * V_17 = V_6 -> V_18 ;
V_21 V_170 , V_171 ;
struct V_8 * V_9 = F_3 ( V_6 ) ;
F_12 ( V_9 , true ) ;
V_170 = ( V_21 ) V_165 << V_22 ;
V_171 = ( V_21 ) V_166 << V_22 ;
F_160 ( V_17 , V_170 ,
V_171 - 1 ) ;
F_7 ( V_9 ) ;
V_42 = F_157 ( V_6 , V_165 , V_166 ) ;
F_10 ( V_9 ) ;
}
}
return V_42 ;
}
static int F_161 ( struct V_6 * V_6 , T_2 V_172 ,
T_2 V_173 , bool V_174 )
{
struct V_8 * V_9 = F_3 ( V_6 ) ;
struct V_10 V_11 ;
T_3 V_175 ;
bool V_176 = false ;
int V_42 ;
F_8 ( & V_11 , V_6 , NULL , NULL , 0 ) ;
V_42 = F_91 ( & V_11 , V_172 , V_92 ) ;
if ( V_42 && V_42 != - V_93 ) {
return V_42 ;
} else if ( V_42 == - V_93 ) {
V_175 = V_83 ;
} else {
V_175 = V_11 . V_28 ;
if ( ! F_162 ( V_9 , V_175 ) ) {
F_163 ( & V_11 , V_83 ) ;
V_176 = true ;
}
F_11 ( & V_11 ) ;
}
if ( V_175 == V_83 )
return V_174 ? F_157 ( V_6 , V_173 , V_173 + 1 ) : 0 ;
if ( V_176 ) {
struct V_5 * V_126 = F_132 ( V_9 , V_6 -> V_35 ) ;
struct V_177 V_178 ;
if ( F_127 ( V_126 ) ) {
V_42 = F_133 ( V_126 ) ;
goto V_179;
}
F_8 ( & V_11 , V_6 , V_126 , NULL , 0 ) ;
V_42 = F_9 ( & V_11 , V_173 ) ;
if ( V_42 )
goto V_179;
F_110 ( & V_11 , 1 ) ;
F_164 ( V_9 , V_11 . V_117 , & V_178 ) ;
F_165 ( V_9 , & V_11 , V_11 . V_28 , V_175 ,
V_178 . V_180 , true , false ) ;
F_11 ( & V_11 ) ;
} else {
struct V_5 * V_181 , * V_182 ;
V_181 = F_126 ( V_6 , V_172 , true ) ;
if ( F_127 ( V_181 ) )
return F_133 ( V_181 ) ;
V_182 = F_156 ( V_6 , NULL , V_173 , true ) ;
if ( F_127 ( V_182 ) ) {
F_55 ( V_181 , 1 ) ;
return F_133 ( V_182 ) ;
}
F_166 ( V_181 , V_182 ) ;
F_22 ( V_182 ) ;
F_55 ( V_182 , 1 ) ;
F_55 ( V_181 , 1 ) ;
return F_157 ( V_6 , V_172 , V_172 + 1 ) ;
}
return 0 ;
V_179:
if ( ! F_91 ( & V_11 , V_172 , V_167 ) ) {
F_163 ( & V_11 , V_175 ) ;
F_11 ( & V_11 ) ;
}
return V_42 ;
}
static int F_167 ( struct V_6 * V_6 , T_2 V_47 , T_2 V_48 )
{
struct V_8 * V_9 = F_3 ( V_6 ) ;
T_2 V_183 = ( F_17 ( V_6 ) + V_25 - 1 ) / V_25 ;
int V_42 = 0 ;
for (; V_48 < V_183 ; V_47 ++ , V_48 ++ ) {
F_12 ( V_9 , true ) ;
F_7 ( V_9 ) ;
V_42 = F_161 ( V_6 , V_48 , V_47 , true ) ;
F_10 ( V_9 ) ;
if ( V_42 )
break;
}
return V_42 ;
}
static int F_168 ( struct V_6 * V_6 , V_21 V_23 , V_21 V_113 )
{
T_2 V_165 , V_166 ;
V_21 V_184 ;
int V_42 ;
if ( V_23 + V_113 >= F_17 ( V_6 ) )
return - V_100 ;
if ( V_23 & ( V_185 - 1 ) || V_113 & ( V_185 - 1 ) )
return - V_100 ;
V_42 = F_101 ( V_6 ) ;
if ( V_42 )
return V_42 ;
V_165 = V_23 >> V_22 ;
V_166 = ( V_23 + V_113 ) >> V_22 ;
V_42 = F_68 ( V_6 -> V_18 , V_23 , V_186 ) ;
if ( V_42 )
return V_42 ;
F_169 ( V_6 , V_23 ) ;
V_42 = F_167 ( V_6 , V_165 , V_166 ) ;
if ( V_42 )
return V_42 ;
F_68 ( V_6 -> V_18 , V_23 , V_186 ) ;
F_169 ( V_6 , V_23 ) ;
V_184 = F_17 ( V_6 ) - V_113 ;
F_169 ( V_6 , V_184 ) ;
V_42 = F_129 ( V_6 , V_184 , true ) ;
if ( ! V_42 )
F_170 ( V_6 , V_184 ) ;
return V_42 ;
}
static int F_171 ( struct V_10 * V_11 , T_2 V_47 ,
T_2 V_48 )
{
struct V_8 * V_9 = F_3 ( V_11 -> V_6 ) ;
T_2 V_14 = V_47 ;
unsigned int V_95 = V_11 -> V_95 ;
T_7 V_108 = 0 ;
int V_42 ;
for (; V_14 < V_48 ; V_14 ++ , V_11 -> V_95 ++ ) {
if ( F_94 ( V_11 -> V_94 , V_11 -> V_95 ) == V_83 )
V_108 ++ ;
}
V_11 -> V_95 = V_95 ;
V_42 = F_172 ( V_11 , V_108 ) ;
if ( V_42 )
return V_42 ;
V_11 -> V_95 = V_95 ;
for ( V_14 = V_47 ; V_14 < V_48 ; V_14 ++ , V_11 -> V_95 ++ ) {
V_11 -> V_28 =
F_94 ( V_11 -> V_94 , V_11 -> V_95 ) ;
if ( V_11 -> V_28 == V_83 ) {
V_42 = - V_187 ;
break;
}
if ( V_11 -> V_28 != V_82 ) {
F_115 ( V_9 , V_11 -> V_28 ) ;
V_11 -> V_28 = V_82 ;
F_114 ( V_11 ) ;
}
}
F_119 ( V_11 , V_47 , 0 , V_14 - V_47 ) ;
return V_42 ;
}
static int F_173 ( struct V_6 * V_6 , V_21 V_23 , V_21 V_113 ,
int V_157 )
{
struct V_8 * V_9 = F_3 ( V_6 ) ;
struct V_70 * V_17 = V_6 -> V_18 ;
T_2 V_14 , V_165 , V_166 ;
V_21 V_184 = F_17 ( V_6 ) ;
V_21 V_168 , V_169 ;
int V_42 = 0 ;
V_42 = F_174 ( V_6 , ( V_113 + V_23 ) ) ;
if ( V_42 )
return V_42 ;
V_42 = F_101 ( V_6 ) ;
if ( V_42 )
return V_42 ;
V_42 = F_68 ( V_17 , V_23 , V_23 + V_113 - 1 ) ;
if ( V_42 )
return V_42 ;
F_175 ( V_6 , V_23 , V_23 + V_113 - 1 ) ;
V_165 = ( ( unsigned long long ) V_23 ) >> V_22 ;
V_166 = ( ( unsigned long long ) V_23 + V_113 ) >> V_22 ;
V_168 = V_23 & ( V_25 - 1 ) ;
V_169 = ( V_23 + V_113 ) & ( V_25 - 1 ) ;
if ( V_165 == V_166 ) {
V_42 = F_155 ( V_6 , V_165 , V_168 ,
V_169 - V_168 ) ;
if ( V_42 )
return V_42 ;
if ( V_23 + V_113 > V_184 )
V_184 = V_23 + V_113 ;
V_184 = F_176 ( V_21 , V_184 , V_23 + V_113 ) ;
} else {
if ( V_168 ) {
V_42 = F_155 ( V_6 , V_165 ++ , V_168 ,
V_25 - V_168 ) ;
if ( V_42 )
return V_42 ;
V_184 = F_176 ( V_21 , V_184 ,
( V_21 ) V_165 << V_22 ) ;
}
for ( V_14 = V_165 ; V_14 < V_166 ; ) {
struct V_10 V_11 ;
unsigned int V_87 ;
T_2 V_48 ;
F_7 ( V_9 ) ;
F_8 ( & V_11 , V_6 , NULL , NULL , 0 ) ;
V_42 = F_91 ( & V_11 , V_14 , V_188 ) ;
if ( V_42 ) {
F_10 ( V_9 ) ;
goto V_15;
}
V_87 = F_93 ( V_11 . V_94 , V_6 ) ;
V_48 = F_158 ( V_166 , V_87 - V_11 . V_95 + V_14 ) ;
V_42 = F_171 ( & V_11 , V_14 , V_48 ) ;
F_11 ( & V_11 ) ;
F_10 ( V_9 ) ;
if ( V_42 )
goto V_15;
V_14 = V_48 ;
V_184 = F_176 ( V_21 , V_184 ,
( V_21 ) V_14 << V_22 ) ;
}
if ( V_169 ) {
V_42 = F_155 ( V_6 , V_166 , 0 , V_169 ) ;
if ( V_42 )
goto V_15;
V_184 = F_176 ( V_21 , V_184 , V_23 + V_113 ) ;
}
}
V_15:
if ( ! ( V_157 & V_189 ) && F_17 ( V_6 ) < V_184 ) {
F_170 ( V_6 , V_184 ) ;
F_142 ( V_6 ) ;
F_177 ( V_6 ) ;
}
return V_42 ;
}
static int F_178 ( struct V_6 * V_6 , V_21 V_23 , V_21 V_113 )
{
struct V_8 * V_9 = F_3 ( V_6 ) ;
T_2 V_165 , V_166 , V_190 , V_183 , V_191 ;
V_21 V_184 ;
int V_42 = 0 ;
V_184 = F_17 ( V_6 ) + V_113 ;
if ( V_184 > V_6 -> V_13 -> V_86 )
return - V_192 ;
if ( V_23 >= F_17 ( V_6 ) )
return - V_100 ;
if ( V_23 & ( V_185 - 1 ) || V_113 & ( V_185 - 1 ) )
return - V_100 ;
V_42 = F_101 ( V_6 ) ;
if ( V_42 )
return V_42 ;
F_12 ( V_9 , true ) ;
V_42 = F_129 ( V_6 , F_17 ( V_6 ) , true ) ;
if ( V_42 )
return V_42 ;
V_42 = F_68 ( V_6 -> V_18 , V_23 , V_186 ) ;
if ( V_42 )
return V_42 ;
F_169 ( V_6 , V_23 ) ;
V_165 = V_23 >> V_22 ;
V_166 = ( V_23 + V_113 ) >> V_22 ;
V_190 = V_166 - V_165 ;
V_183 = ( F_17 ( V_6 ) + V_25 - 1 ) / V_25 ;
for ( V_191 = V_183 - 1 ; V_191 >= V_165 && V_191 != - 1 ; V_191 -- ) {
F_7 ( V_9 ) ;
V_42 = F_161 ( V_6 , V_191 , V_191 + V_190 , false ) ;
F_10 ( V_9 ) ;
if ( V_42 )
break;
}
F_68 ( V_6 -> V_18 , V_23 , V_186 ) ;
F_169 ( V_6 , V_23 ) ;
if ( ! V_42 )
F_170 ( V_6 , V_184 ) ;
return V_42 ;
}
static int F_179 ( struct V_6 * V_6 , V_21 V_23 ,
V_21 V_113 , int V_157 )
{
struct V_8 * V_9 = F_3 ( V_6 ) ;
struct V_193 V_194 = { . V_195 = NULL } ;
T_2 V_166 ;
V_21 V_184 = F_17 ( V_6 ) ;
V_21 V_169 ;
int V_42 ;
V_42 = F_174 ( V_6 , ( V_113 + V_23 ) ) ;
if ( V_42 )
return V_42 ;
V_42 = F_101 ( V_6 ) ;
if ( V_42 )
return V_42 ;
F_12 ( V_9 , true ) ;
V_166 = ( ( unsigned long long ) V_23 + V_113 ) >> V_22 ;
V_169 = ( V_23 + V_113 ) & ( V_25 - 1 ) ;
V_194 . V_196 = ( ( unsigned long long ) V_23 ) >> V_22 ;
V_194 . V_197 = V_166 - V_194 . V_196 ;
if ( V_169 )
V_194 . V_197 ++ ;
V_42 = V_193 ( V_6 , & V_194 , 1 , V_198 ) ;
if ( V_42 ) {
T_2 V_199 ;
if ( ! V_194 . V_197 )
return V_42 ;
V_199 = V_194 . V_196 + V_194 . V_197 - 1 ;
V_184 = ( V_199 == V_166 ) ? V_23 + V_113 :
( V_21 ) ( V_199 + 1 ) << V_22 ;
} else {
V_184 = ( ( V_21 ) V_166 << V_22 ) + V_169 ;
}
if ( ! ( V_157 & V_189 ) && F_17 ( V_6 ) < V_184 ) {
F_170 ( V_6 , V_184 ) ;
F_142 ( V_6 ) ;
F_177 ( V_6 ) ;
}
return V_42 ;
}
static long F_180 ( struct V_46 * V_46 , int V_157 ,
V_21 V_23 , V_21 V_113 )
{
struct V_6 * V_6 = F_2 ( V_46 ) ;
long V_42 = 0 ;
if ( ! F_27 ( V_6 -> V_27 ) )
return - V_100 ;
if ( F_26 ( V_6 ) &&
( V_157 & ( V_200 | V_201 ) ) )
return - V_202 ;
if ( V_157 & ~ ( V_189 | V_203 |
V_200 | V_204 |
V_201 ) )
return - V_202 ;
F_89 ( V_6 ) ;
if ( V_157 & V_203 ) {
if ( V_23 >= V_6 -> V_205 )
goto V_15;
V_42 = F_159 ( V_6 , V_23 , V_113 ) ;
} else if ( V_157 & V_200 ) {
V_42 = F_168 ( V_6 , V_23 , V_113 ) ;
} else if ( V_157 & V_204 ) {
V_42 = F_173 ( V_6 , V_23 , V_113 , V_157 ) ;
} else if ( V_157 & V_201 ) {
V_42 = F_178 ( V_6 , V_23 , V_113 ) ;
} else {
V_42 = F_179 ( V_6 , V_23 , V_113 , V_157 ) ;
}
if ( ! V_42 ) {
V_6 -> V_131 = V_6 -> V_132 = V_133 ;
F_142 ( V_6 ) ;
F_31 ( F_3 ( V_6 ) , V_29 ) ;
}
V_15:
F_95 ( V_6 ) ;
F_181 ( V_6 , V_157 , V_23 , V_113 , V_42 ) ;
return V_42 ;
}
static int F_182 ( struct V_6 * V_6 , struct V_46 * V_104 )
{
if ( ! ( V_104 -> V_206 & V_207 ) ||
F_183 ( & V_6 -> V_208 ) != 1 )
return 0 ;
if ( F_184 ( V_6 ) )
F_185 ( V_6 ) ;
if ( F_186 ( V_6 ) ) {
F_69 ( F_46 ( V_6 ) , V_209 ) ;
F_67 ( F_46 ( V_6 ) , V_210 ) ;
F_187 ( V_6 -> V_18 ) ;
F_69 ( F_46 ( V_6 ) , V_210 ) ;
}
return 0 ;
}
static inline T_8 F_188 ( T_6 V_157 , T_8 V_211 )
{
if ( F_138 ( V_157 ) )
return V_211 ;
else if ( F_27 ( V_157 ) )
return V_211 & V_212 ;
else
return V_211 & V_213 ;
}
static int F_189 ( struct V_46 * V_104 , unsigned long V_214 )
{
struct V_6 * V_6 = F_2 ( V_104 ) ;
struct V_43 * V_44 = F_46 ( V_6 ) ;
unsigned int V_211 = V_44 -> V_215 & V_216 ;
return F_190 ( V_211 , ( int V_217 * ) V_214 ) ;
}
static int F_191 ( struct V_46 * V_104 , unsigned long V_214 )
{
struct V_6 * V_6 = F_2 ( V_104 ) ;
struct V_43 * V_44 = F_46 ( V_6 ) ;
unsigned int V_211 = V_44 -> V_215 & V_216 ;
unsigned int V_218 ;
int V_42 ;
if ( ! F_192 ( V_6 ) )
return - V_106 ;
if ( F_193 ( V_211 , ( int V_217 * ) V_214 ) )
return - V_19 ;
V_42 = F_194 ( V_104 ) ;
if ( V_42 )
return V_42 ;
V_211 = F_188 ( V_6 -> V_27 , V_211 ) ;
F_89 ( V_6 ) ;
V_218 = V_44 -> V_215 ;
if ( ( V_211 ^ V_218 ) & ( V_219 | V_220 ) ) {
if ( ! F_148 ( V_221 ) ) {
F_95 ( V_6 ) ;
V_42 = - V_107 ;
goto V_15;
}
}
V_211 = V_211 & V_222 ;
V_211 |= V_218 & ~ V_222 ;
V_44 -> V_215 = V_211 ;
F_95 ( V_6 ) ;
F_195 ( V_6 ) ;
V_6 -> V_132 = V_133 ;
F_142 ( V_6 ) ;
V_15:
F_196 ( V_104 ) ;
return V_42 ;
}
static int F_197 ( struct V_46 * V_104 , unsigned long V_214 )
{
struct V_6 * V_6 = F_2 ( V_104 ) ;
return F_190 ( V_6 -> V_223 , ( int V_217 * ) V_214 ) ;
}
static int F_198 ( struct V_46 * V_104 )
{
struct V_6 * V_6 = F_2 ( V_104 ) ;
int V_42 ;
if ( ! F_192 ( V_6 ) )
return - V_106 ;
V_42 = F_194 ( V_104 ) ;
if ( V_42 )
return V_42 ;
F_89 ( V_6 ) ;
if ( F_184 ( V_6 ) )
goto V_15;
V_42 = F_101 ( V_6 ) ;
if ( V_42 )
goto V_15;
F_67 ( F_46 ( V_6 ) , V_224 ) ;
F_31 ( F_3 ( V_6 ) , V_29 ) ;
if ( ! F_65 ( V_6 ) )
goto V_15;
F_199 ( F_3 ( V_6 ) -> V_225 , V_226 ,
L_1 ,
V_6 -> V_35 , F_65 ( V_6 ) ) ;
V_42 = F_68 ( V_6 -> V_18 , 0 , V_186 ) ;
if ( V_42 )
F_69 ( F_46 ( V_6 ) , V_224 ) ;
V_15:
F_95 ( V_6 ) ;
F_196 ( V_104 ) ;
return V_42 ;
}
static int F_200 ( struct V_46 * V_104 )
{
struct V_6 * V_6 = F_2 ( V_104 ) ;
int V_42 ;
if ( ! F_192 ( V_6 ) )
return - V_106 ;
V_42 = F_194 ( V_104 ) ;
if ( V_42 )
return V_42 ;
F_89 ( V_6 ) ;
if ( F_186 ( V_6 ) )
goto V_179;
if ( F_184 ( V_6 ) ) {
F_69 ( F_46 ( V_6 ) , V_224 ) ;
V_42 = F_201 ( V_6 ) ;
if ( V_42 ) {
F_67 ( F_46 ( V_6 ) , V_224 ) ;
goto V_179;
}
}
V_42 = F_62 ( V_104 , 0 , V_186 , 0 , true ) ;
V_179:
F_95 ( V_6 ) ;
F_196 ( V_104 ) ;
return V_42 ;
}
static int F_202 ( struct V_46 * V_104 )
{
struct V_6 * V_6 = F_2 ( V_104 ) ;
int V_42 ;
if ( ! F_192 ( V_6 ) )
return - V_106 ;
V_42 = F_194 ( V_104 ) ;
if ( V_42 )
return V_42 ;
F_89 ( V_6 ) ;
if ( F_186 ( V_6 ) )
goto V_15;
V_42 = F_101 ( V_6 ) ;
if ( V_42 )
goto V_15;
F_67 ( F_46 ( V_6 ) , V_209 ) ;
F_31 ( F_3 ( V_6 ) , V_29 ) ;
V_15:
F_95 ( V_6 ) ;
F_196 ( V_104 ) ;
return V_42 ;
}
static int F_203 ( struct V_46 * V_104 )
{
struct V_6 * V_6 = F_2 ( V_104 ) ;
int V_42 ;
if ( ! F_192 ( V_6 ) )
return - V_106 ;
V_42 = F_194 ( V_104 ) ;
if ( V_42 )
return V_42 ;
F_89 ( V_6 ) ;
if ( ! F_186 ( V_6 ) )
goto V_15;
if ( ! F_204 ( V_6 ) ) {
V_42 = F_124 ( V_6 , 0 , true ) ;
goto V_15;
}
V_42 = F_159 ( V_6 , 0 , V_185 ) ;
V_15:
F_95 ( V_6 ) ;
F_196 ( V_104 ) ;
return V_42 ;
}
static int F_205 ( struct V_46 * V_104 )
{
struct V_6 * V_6 = F_2 ( V_104 ) ;
int V_42 ;
if ( ! F_192 ( V_6 ) )
return - V_106 ;
V_42 = F_194 ( V_104 ) ;
if ( V_42 )
return V_42 ;
F_89 ( V_6 ) ;
if ( F_184 ( V_6 ) )
F_185 ( V_6 ) ;
if ( F_186 ( V_6 ) ) {
F_69 ( F_46 ( V_6 ) , V_209 ) ;
V_42 = F_62 ( V_104 , 0 , V_186 , 0 , true ) ;
}
F_95 ( V_6 ) ;
F_196 ( V_104 ) ;
F_31 ( F_3 ( V_6 ) , V_29 ) ;
return V_42 ;
}
static int F_206 ( struct V_46 * V_104 , unsigned long V_214 )
{
struct V_6 * V_6 = F_2 ( V_104 ) ;
struct V_8 * V_9 = F_3 ( V_6 ) ;
struct V_227 * V_225 = V_9 -> V_225 ;
T_8 V_228 ;
int V_42 ;
if ( ! F_148 ( V_229 ) )
return - V_107 ;
if ( F_193 ( V_228 , ( T_8 V_217 * ) V_214 ) )
return - V_19 ;
V_42 = F_194 ( V_104 ) ;
if ( V_42 )
return V_42 ;
switch ( V_228 ) {
case V_230 :
V_225 = F_207 ( V_225 -> V_231 ) ;
if ( V_225 && ! F_127 ( V_225 ) ) {
F_208 ( V_9 , false ) ;
F_209 ( V_225 -> V_231 , V_225 ) ;
}
break;
case V_232 :
F_75 ( V_225 , 1 ) ;
F_208 ( V_9 , false ) ;
break;
case V_233 :
F_208 ( V_9 , false ) ;
break;
case V_234 :
F_210 ( V_9 , V_235 , V_58 ) ;
F_208 ( V_9 , false ) ;
break;
default:
V_42 = - V_100 ;
goto V_15;
}
F_31 ( V_9 , V_29 ) ;
V_15:
F_196 ( V_104 ) ;
return V_42 ;
}
static int F_211 ( struct V_46 * V_104 , unsigned long V_214 )
{
struct V_6 * V_6 = F_2 ( V_104 ) ;
struct V_227 * V_225 = V_6 -> V_13 ;
struct V_236 * V_237 = F_212 ( V_225 -> V_231 ) ;
struct V_238 V_239 ;
int V_42 ;
if ( ! F_148 ( V_229 ) )
return - V_107 ;
if ( ! F_213 ( V_237 ) )
return - V_202 ;
if ( F_214 ( & V_239 , (struct V_238 V_217 * ) V_214 ,
sizeof( V_239 ) ) )
return - V_19 ;
V_42 = F_194 ( V_104 ) ;
if ( V_42 )
return V_42 ;
V_239 . V_240 = F_215 ( ( unsigned int ) V_239 . V_240 ,
V_237 -> V_241 . V_242 ) ;
V_42 = F_216 ( F_217 ( V_225 ) , & V_239 ) ;
F_196 ( V_104 ) ;
if ( V_42 < 0 )
return V_42 ;
if ( F_218 ( (struct V_238 V_217 * ) V_214 , & V_239 ,
sizeof( V_239 ) ) )
return - V_19 ;
F_31 ( F_3 ( V_6 ) , V_29 ) ;
return 0 ;
}
static bool F_219 ( T_9 V_243 [ 16 ] )
{
int V_41 ;
for ( V_41 = 0 ; V_41 < 16 ; V_41 ++ )
if ( V_243 [ V_41 ] )
return true ;
return false ;
}
static int F_220 ( struct V_46 * V_104 , unsigned long V_214 )
{
struct V_244 V_245 ;
struct V_6 * V_6 = F_2 ( V_104 ) ;
int V_42 ;
if ( F_214 ( & V_245 , (struct V_244 V_217 * ) V_214 ,
sizeof( V_245 ) ) )
return - V_19 ;
V_42 = F_194 ( V_104 ) ;
if ( V_42 )
return V_42 ;
F_31 ( F_3 ( V_6 ) , V_29 ) ;
V_42 = F_221 ( V_6 , & V_245 ) ;
F_196 ( V_104 ) ;
return V_42 ;
}
static int F_222 ( struct V_46 * V_104 , unsigned long V_214 )
{
struct V_244 V_245 ;
struct V_6 * V_6 = F_2 ( V_104 ) ;
int V_12 ;
V_12 = F_223 ( V_6 , & V_245 ) ;
if ( V_12 )
return V_12 ;
if ( F_218 ( (struct V_244 V_217 * ) V_214 , & V_245 , sizeof( V_245 ) ) )
return - V_19 ;
return 0 ;
}
static int F_224 ( struct V_46 * V_104 , unsigned long V_214 )
{
struct V_6 * V_6 = F_2 ( V_104 ) ;
struct V_8 * V_9 = F_3 ( V_6 ) ;
int V_12 ;
if ( ! F_225 ( V_6 -> V_13 ) )
return - V_202 ;
if ( F_219 ( V_9 -> V_246 -> V_247 ) )
goto V_248;
V_12 = F_194 ( V_104 ) ;
if ( V_12 )
return V_12 ;
F_226 ( V_9 -> V_246 -> V_247 ) ;
V_12 = F_227 ( V_9 , false ) ;
if ( V_12 ) {
memset ( V_9 -> V_246 -> V_247 , 0 , 16 ) ;
F_196 ( V_104 ) ;
return V_12 ;
}
F_196 ( V_104 ) ;
V_248:
if ( F_218 ( ( T_9 V_217 * ) V_214 , V_9 -> V_246 -> V_247 ,
16 ) )
return - V_19 ;
return 0 ;
}
static int F_228 ( struct V_46 * V_104 , unsigned long V_214 )
{
struct V_6 * V_6 = F_2 ( V_104 ) ;
struct V_8 * V_9 = F_3 ( V_6 ) ;
T_8 V_249 ;
int V_42 ;
if ( ! F_148 ( V_229 ) )
return - V_107 ;
if ( F_193 ( V_249 , ( T_8 V_217 * ) V_214 ) )
return - V_19 ;
if ( F_63 ( V_9 -> V_225 ) )
return - V_250 ;
V_42 = F_194 ( V_104 ) ;
if ( V_42 )
return V_42 ;
if ( ! V_249 ) {
if ( ! F_229 ( & V_9 -> V_251 ) ) {
V_42 = - V_252 ;
goto V_15;
}
} else {
F_230 ( & V_9 -> V_251 ) ;
}
V_42 = F_231 ( V_9 , V_249 ) ;
V_15:
F_196 ( V_104 ) ;
return V_42 ;
}
static int F_232 ( struct V_46 * V_104 , unsigned long V_214 )
{
struct V_6 * V_6 = F_2 ( V_104 ) ;
struct V_8 * V_9 = F_3 ( V_6 ) ;
int V_42 ;
if ( ! F_148 ( V_229 ) )
return - V_107 ;
if ( F_63 ( V_9 -> V_225 ) )
return - V_250 ;
V_42 = F_194 ( V_104 ) ;
if ( V_42 )
return V_42 ;
V_42 = F_75 ( V_9 -> V_225 , 1 ) ;
F_196 ( V_104 ) ;
return V_42 ;
}
static int F_233 ( struct V_8 * V_9 ,
struct V_46 * V_104 ,
struct V_253 * V_239 )
{
struct V_6 * V_6 = F_2 ( V_104 ) ;
struct V_193 V_194 = { . V_195 = NULL } ;
struct V_254 V_255 ;
T_2 V_165 , V_166 ;
unsigned int V_256 = V_9 -> V_257 ;
unsigned int V_258 = 0 , V_259 ;
unsigned int V_260 = V_9 -> V_261 * V_256 ;
T_3 V_171 = 0 ;
bool V_262 = false ;
int V_12 ;
if ( F_234 ( V_6 ) )
return - V_100 ;
V_165 = V_239 -> V_47 >> V_22 ;
V_166 = ( V_239 -> V_47 + V_239 -> V_113 ) >> V_22 ;
F_12 ( V_9 , true ) ;
F_89 ( V_6 ) ;
V_12 = F_68 ( V_6 -> V_18 , V_239 -> V_47 ,
V_239 -> V_47 + V_239 -> V_113 - 1 ) ;
if ( V_12 )
goto V_15;
if ( F_235 ( V_6 , V_165 , & V_255 ) ) {
if ( V_255 . V_116 + V_255 . V_113 >= V_166 )
goto V_15;
}
V_194 . V_196 = V_165 ;
while ( V_194 . V_196 < V_166 ) {
V_194 . V_197 = V_166 - V_194 . V_196 ;
V_12 = V_193 ( V_6 , & V_194 , 0 , V_263 ) ;
if ( V_12 )
goto V_15;
if ( ! ( V_194 . V_264 & V_265 ) ) {
V_194 . V_196 ++ ;
continue;
}
if ( V_171 && V_171 != V_194 . V_266 ) {
V_262 = true ;
break;
}
V_171 = V_194 . V_266 + V_194 . V_197 ;
V_194 . V_196 += V_194 . V_197 ;
}
if ( ! V_262 )
goto V_15;
V_194 . V_196 = V_165 ;
V_194 . V_197 = V_166 - V_165 ;
V_259 = ( V_194 . V_197 + V_260 - 1 ) / V_260 ;
if ( F_236 ( V_9 , V_259 ) ) {
V_12 = - V_267 ;
goto V_15;
}
while ( V_194 . V_196 < V_166 ) {
T_2 V_191 ;
int V_268 = 0 ;
V_269:
V_194 . V_197 = V_166 - V_194 . V_196 ;
V_12 = V_193 ( V_6 , & V_194 , 0 , V_263 ) ;
if ( V_12 )
goto V_270;
if ( ! ( V_194 . V_264 & V_265 ) ) {
V_194 . V_196 ++ ;
continue;
}
F_67 ( F_46 ( V_6 ) , V_271 ) ;
V_191 = V_194 . V_196 ;
while ( V_191 < V_194 . V_196 + V_194 . V_197 && V_268 < V_256 ) {
struct V_5 * V_5 ;
V_5 = F_126 ( V_6 , V_191 , true ) ;
if ( F_127 ( V_5 ) ) {
V_12 = F_133 ( V_5 ) ;
goto V_270;
}
F_22 ( V_5 ) ;
F_55 ( V_5 , 1 ) ;
V_191 ++ ;
V_268 ++ ;
V_258 ++ ;
}
V_194 . V_196 = V_191 ;
if ( V_191 < V_166 && V_268 < V_256 )
goto V_269;
F_69 ( F_46 ( V_6 ) , V_271 ) ;
V_12 = F_187 ( V_6 -> V_18 ) ;
if ( V_12 )
goto V_15;
}
V_270:
F_69 ( F_46 ( V_6 ) , V_271 ) ;
V_15:
F_95 ( V_6 ) ;
if ( ! V_12 )
V_239 -> V_113 = ( T_5 ) V_258 << V_22 ;
return V_12 ;
}
static int F_237 ( struct V_46 * V_104 , unsigned long V_214 )
{
struct V_6 * V_6 = F_2 ( V_104 ) ;
struct V_8 * V_9 = F_3 ( V_6 ) ;
struct V_253 V_239 ;
int V_12 ;
if ( ! F_148 ( V_229 ) )
return - V_107 ;
if ( ! F_27 ( V_6 -> V_27 ) )
return - V_100 ;
V_12 = F_194 ( V_104 ) ;
if ( V_12 )
return V_12 ;
if ( F_63 ( V_9 -> V_225 ) ) {
V_12 = - V_250 ;
goto V_15;
}
if ( F_214 ( & V_239 , (struct V_253 V_217 * ) V_214 ,
sizeof( V_239 ) ) ) {
V_12 = - V_19 ;
goto V_15;
}
if ( V_239 . V_47 & ( V_185 - 1 ) ||
V_239 . V_113 & ( V_185 - 1 ) ) {
V_12 = - V_100 ;
goto V_15;
}
V_12 = F_233 ( V_9 , V_104 , & V_239 ) ;
F_31 ( V_9 , V_29 ) ;
if ( V_12 < 0 )
goto V_15;
if ( F_218 ( (struct V_253 V_217 * ) V_214 , & V_239 ,
sizeof( V_239 ) ) )
V_12 = - V_19 ;
V_15:
F_196 ( V_104 ) ;
return V_12 ;
}
long F_238 ( struct V_46 * V_104 , unsigned int V_272 , unsigned long V_214 )
{
switch ( V_272 ) {
case V_273 :
return F_189 ( V_104 , V_214 ) ;
case V_274 :
return F_191 ( V_104 , V_214 ) ;
case V_275 :
return F_197 ( V_104 , V_214 ) ;
case V_276 :
return F_198 ( V_104 ) ;
case V_277 :
return F_200 ( V_104 ) ;
case V_278 :
return F_202 ( V_104 ) ;
case V_279 :
return F_203 ( V_104 ) ;
case V_280 :
return F_205 ( V_104 ) ;
case V_281 :
return F_206 ( V_104 , V_214 ) ;
case V_282 :
return F_211 ( V_104 , V_214 ) ;
case V_283 :
return F_220 ( V_104 , V_214 ) ;
case V_284 :
return F_222 ( V_104 , V_214 ) ;
case V_285 :
return F_224 ( V_104 , V_214 ) ;
case V_286 :
return F_228 ( V_104 , V_214 ) ;
case V_287 :
return F_232 ( V_104 , V_214 ) ;
case V_288 :
return F_237 ( V_104 , V_214 ) ;
default:
return - V_289 ;
}
}
static T_10 F_239 ( struct V_290 * V_291 , struct V_292 * V_119 )
{
struct V_46 * V_46 = V_291 -> V_293 ;
struct V_6 * V_6 = F_2 ( V_46 ) ;
T_10 V_42 ;
if ( F_26 ( V_6 ) &&
! F_105 ( V_6 ) &&
F_100 ( V_6 ) )
return - V_106 ;
F_89 ( V_6 ) ;
V_42 = F_240 ( V_291 , V_119 ) ;
if ( V_42 > 0 ) {
V_42 = F_241 ( V_291 , V_119 ) ;
if ( ! V_42 )
V_42 = F_242 ( V_291 , V_119 ) ;
}
F_95 ( V_6 ) ;
if ( V_42 > 0 )
V_42 = F_243 ( V_291 , V_42 ) ;
return V_42 ;
}
long F_244 ( struct V_46 * V_46 , unsigned int V_272 , unsigned long V_214 )
{
switch ( V_272 ) {
case V_294 :
V_272 = V_273 ;
break;
case V_295 :
V_272 = V_274 ;
break;
case V_296 :
V_272 = V_275 ;
break;
case V_276 :
case V_277 :
case V_278 :
case V_279 :
case V_280 :
case V_281 :
case V_283 :
case V_285 :
case V_284 :
case V_286 :
case V_287 :
case V_288 :
break;
default:
return - V_297 ;
}
return F_238 ( V_46 , V_272 , ( unsigned long ) F_245 ( V_214 ) ) ;
}
