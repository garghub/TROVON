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
V_15:
F_29 ( V_6 -> V_13 ) ;
F_30 ( V_9 , V_29 ) ;
return F_31 ( V_12 ) ;
}
static int F_32 ( struct V_6 * V_6 , T_1 * V_30 )
{
struct V_31 * V_31 ;
V_6 = F_33 ( V_6 ) ;
V_31 = F_34 ( V_6 ) ;
F_35 ( V_6 ) ;
if ( ! V_31 )
return 0 ;
if ( F_36 ( V_6 , V_6 , & V_31 -> V_32 ) ) {
F_37 ( V_31 ) ;
return 0 ;
}
* V_30 = F_38 ( V_31 ) ;
F_37 ( V_31 ) ;
return 1 ;
}
static inline bool F_39 ( struct V_6 * V_6 )
{
struct V_8 * V_9 = F_3 ( V_6 ) ;
bool V_33 = false ;
if ( ! F_27 ( V_6 -> V_27 ) || V_6 -> V_34 != 1 )
V_33 = true ;
else if ( F_40 ( V_9 , V_35 ) )
V_33 = true ;
else if ( F_41 ( V_6 ) )
V_33 = true ;
else if ( ! F_42 ( V_9 ) )
V_33 = true ;
else if ( ! F_43 ( V_9 , F_44 ( V_6 ) -> V_36 ) )
V_33 = true ;
else if ( F_44 ( V_6 ) -> V_37 == F_45 ( F_46 ( V_9 ) ) )
V_33 = true ;
else if ( F_47 ( V_9 , V_38 ) )
V_33 = true ;
else if ( V_9 -> V_39 == 2 )
V_33 = true ;
return V_33 ;
}
static bool F_48 ( struct V_8 * V_9 , T_1 V_40 )
{
struct V_5 * V_41 = F_49 ( F_50 ( V_9 ) , V_40 ) ;
bool V_42 = false ;
if ( ( V_41 && F_51 ( V_41 ) ) || F_52 ( V_9 , V_40 ) )
V_42 = true ;
F_53 ( V_41 , 0 ) ;
return V_42 ;
}
static void F_54 ( struct V_6 * V_6 )
{
struct V_43 * V_44 = F_44 ( V_6 ) ;
T_1 V_30 ;
F_55 ( & V_44 -> V_45 ) ;
V_44 -> V_37 = 0 ;
if ( F_41 ( V_6 ) && V_6 -> V_34 == 1 &&
F_32 ( V_6 , & V_30 ) ) {
F_56 ( V_6 , V_30 ) ;
F_57 ( V_6 ) ;
}
F_58 ( & V_44 -> V_45 ) ;
}
static int F_59 ( struct V_46 * V_46 , V_21 V_47 , V_21 V_48 ,
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
if ( F_15 ( F_60 ( V_6 -> V_13 ) ) )
return 0 ;
F_61 ( V_6 ) ;
if ( V_49 || F_62 ( V_6 ) <= F_63 ( V_9 ) -> V_61 )
F_64 ( V_6 , V_62 ) ;
V_42 = F_65 ( V_6 -> V_18 , V_47 , V_48 ) ;
F_66 ( V_6 , V_62 ) ;
if ( V_42 ) {
F_67 ( V_6 , V_33 , V_49 , V_42 ) ;
return V_42 ;
}
if ( ! F_68 ( V_6 , V_49 ) ) {
F_69 ( V_6 , NULL ) ;
goto V_63;
}
if ( ! F_70 ( V_6 , V_64 ) &&
! F_71 ( V_9 , V_40 , V_65 ) ) {
if ( F_48 ( V_9 , V_40 ) )
goto V_63;
if ( F_70 ( V_6 , V_66 ) ||
F_71 ( V_9 , V_40 , V_67 ) )
goto V_68;
goto V_15;
}
V_63:
F_72 ( & F_44 ( V_6 ) -> V_45 ) ;
V_33 = F_39 ( V_6 ) ;
F_73 ( & F_44 ( V_6 ) -> V_45 ) ;
if ( V_33 ) {
V_42 = F_74 ( V_6 -> V_13 , 1 ) ;
F_54 ( V_6 ) ;
F_66 ( V_6 , V_64 ) ;
F_66 ( V_6 , V_66 ) ;
goto V_15;
}
V_69:
V_42 = F_75 ( V_9 , V_6 , & V_55 , V_50 ) ;
if ( V_42 )
goto V_15;
if ( F_15 ( F_76 ( V_9 ) ) ) {
V_42 = - V_70 ;
goto V_15;
}
if ( F_52 ( V_9 , V_40 ) ) {
F_77 ( V_6 , true ) ;
F_69 ( V_6 , NULL ) ;
goto V_69;
}
V_42 = F_78 ( V_9 , V_40 ) ;
if ( V_42 )
goto V_15;
F_79 ( V_9 , V_40 , V_65 ) ;
F_66 ( V_6 , V_64 ) ;
V_68:
F_79 ( V_9 , V_40 , V_67 ) ;
F_66 ( V_6 , V_66 ) ;
V_42 = F_80 ( V_9 ) ;
F_30 ( V_9 , V_29 ) ;
V_15:
F_67 ( V_6 , V_33 , V_49 , V_42 ) ;
F_81 ( NULL , 1 ) ;
return V_42 ;
}
int F_82 ( struct V_46 * V_46 , V_21 V_47 , V_21 V_48 , int V_49 )
{
return F_59 ( V_46 , V_47 , V_48 , V_49 , false ) ;
}
static T_2 F_83 ( struct V_71 * V_17 ,
T_2 V_72 , int V_73 )
{
struct V_74 V_75 ;
int V_76 ;
if ( V_73 != V_77 )
return 0 ;
F_84 ( & V_75 , 0 ) ;
V_76 = F_85 ( & V_75 , V_17 , & V_72 ,
V_78 , 1 ) ;
V_72 = V_76 ? V_75 . V_79 [ 0 ] -> V_14 : V_80 ;
F_86 ( & V_75 ) ;
return V_72 ;
}
static bool F_87 ( T_3 V_81 , T_2 V_82 , T_2 V_72 ,
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
static V_21 F_88 ( struct V_46 * V_46 , V_21 V_23 , int V_73 )
{
struct V_6 * V_6 = V_46 -> V_51 -> V_52 ;
V_21 V_86 = V_6 -> V_13 -> V_87 ;
struct V_10 V_11 ;
T_2 V_72 , V_88 , V_82 ;
V_21 V_89 = V_23 ;
V_21 V_90 ;
int V_12 = 0 ;
F_89 ( V_6 ) ;
V_90 = F_17 ( V_6 ) ;
if ( V_23 >= V_90 )
goto V_91;
if ( F_6 ( V_6 ) || F_90 ( V_6 ) ) {
if ( V_73 == V_85 )
V_89 = V_90 ;
goto V_92;
}
V_72 = ( T_2 ) ( V_23 >> V_22 ) ;
V_82 = F_83 ( V_6 -> V_18 , V_72 , V_73 ) ;
for (; V_89 < V_90 ; V_89 = ( V_21 ) V_72 << V_22 ) {
F_8 ( & V_11 , V_6 , NULL , NULL , 0 ) ;
V_12 = F_91 ( & V_11 , V_72 , V_93 ) ;
if ( V_12 && V_12 != - V_94 ) {
goto V_91;
} else if ( V_12 == - V_94 ) {
if ( V_73 == V_77 ) {
V_72 = F_92 ( & V_11 , V_72 ) ;
continue;
} else {
goto V_92;
}
}
V_88 = F_93 ( V_11 . V_95 , V_6 ) ;
for (; V_11 . V_96 < V_88 ;
V_11 . V_96 ++ , V_72 ++ ,
V_89 = ( V_21 ) V_72 << V_22 ) {
T_3 V_81 ;
V_81 = F_94 ( V_11 . V_95 , V_11 . V_96 ) ;
if ( F_87 ( V_81 , V_82 , V_72 , V_73 ) ) {
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
F_95 ( V_6 ) ;
return F_96 ( V_46 , V_89 , V_86 ) ;
V_91:
F_95 ( V_6 ) ;
return - V_97 ;
}
static V_21 F_97 ( struct V_46 * V_46 , V_21 V_23 , int V_73 )
{
struct V_6 * V_6 = V_46 -> V_51 -> V_52 ;
V_21 V_86 = V_6 -> V_13 -> V_87 ;
switch ( V_73 ) {
case V_98 :
case V_99 :
case V_100 :
return F_98 ( V_46 , V_23 , V_73 ,
V_86 , F_17 ( V_6 ) ) ;
case V_77 :
case V_85 :
if ( V_23 < 0 )
return - V_97 ;
return F_88 ( V_46 , V_23 , V_73 ) ;
}
return - V_101 ;
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
return - V_102 ;
}
V_12 = F_101 ( V_6 ) ;
if ( V_12 )
return V_12 ;
F_102 ( V_46 ) ;
V_2 -> V_103 = & V_104 ;
return 0 ;
}
static int F_103 ( struct V_6 * V_6 , struct V_46 * V_105 )
{
int V_42 = F_104 ( V_6 , V_105 ) ;
struct V_31 * V_106 ;
if ( ! V_42 && F_26 ( V_6 ) ) {
V_42 = F_100 ( V_6 ) ;
if ( V_42 )
return - V_107 ;
if ( ! F_105 ( V_6 ) )
return - V_102 ;
}
V_106 = F_106 ( F_107 ( V_105 ) ) ;
if ( F_26 ( F_108 ( V_106 ) ) &&
! F_109 ( F_108 ( V_106 ) , V_6 ) ) {
F_37 ( V_106 ) ;
return - V_108 ;
}
F_37 ( V_106 ) ;
return V_42 ;
}
int F_110 ( struct V_10 * V_11 , int V_109 )
{
struct V_8 * V_9 = F_3 ( V_11 -> V_6 ) ;
struct V_110 * V_111 ;
int V_112 = 0 , V_113 = V_11 -> V_96 , V_114 = V_109 ;
T_4 * V_115 ;
V_111 = F_111 ( V_11 -> V_95 ) ;
V_115 = F_112 ( V_111 ) + V_113 ;
for (; V_109 > 0 ; V_109 -- , V_115 ++ , V_11 -> V_96 ++ ) {
T_3 V_81 = F_113 ( * V_115 ) ;
if ( V_81 == V_84 )
continue;
V_11 -> V_28 = V_84 ;
F_114 ( V_11 ) ;
F_115 ( V_9 , V_81 ) ;
if ( V_11 -> V_96 == 0 && F_116 ( V_11 -> V_95 ) )
F_66 ( V_11 -> V_6 , V_116 ) ;
V_112 ++ ;
}
if ( V_112 ) {
T_2 V_117 ;
V_117 = F_117 ( F_118 ( V_11 -> V_95 ) ,
V_11 -> V_6 ) + V_113 ;
F_119 ( V_11 , V_117 , 0 , V_114 ) ;
F_120 ( V_9 , V_11 -> V_6 , V_112 ) ;
}
V_11 -> V_96 = V_113 ;
F_30 ( V_9 , V_29 ) ;
F_121 ( V_11 -> V_6 , V_11 -> V_118 ,
V_11 -> V_96 , V_112 ) ;
return V_112 ;
}
void F_122 ( struct V_10 * V_11 )
{
F_110 ( V_11 , V_119 ) ;
}
static int F_123 ( struct V_6 * V_6 , T_5 V_120 ,
bool V_121 )
{
unsigned V_23 = V_120 & ( V_25 - 1 ) ;
T_2 V_14 = V_120 >> V_22 ;
struct V_71 * V_17 = V_6 -> V_18 ;
struct V_5 * V_5 ;
if ( ! V_23 && ! V_121 )
return 0 ;
if ( V_121 ) {
V_5 = F_124 ( V_17 , V_14 ) ;
if ( V_5 && F_18 ( V_5 ) )
goto V_122;
F_53 ( V_5 , 1 ) ;
return 0 ;
}
V_5 = F_125 ( V_6 , V_14 , true ) ;
if ( F_126 ( V_5 ) )
return 0 ;
V_122:
F_25 ( V_5 , V_26 , true ) ;
F_127 ( V_5 , V_23 , V_25 - V_23 ) ;
if ( ! V_121 || ! F_26 ( V_6 ) ||
! F_27 ( V_6 -> V_27 ) )
F_22 ( V_5 ) ;
F_53 ( V_5 , 1 ) ;
return 0 ;
}
int F_128 ( struct V_6 * V_6 , T_5 V_120 , bool V_123 )
{
struct V_8 * V_9 = F_3 ( V_6 ) ;
unsigned int V_124 = V_6 -> V_13 -> V_125 ;
struct V_10 V_11 ;
T_2 V_126 ;
int V_109 = 0 , V_12 = 0 ;
struct V_5 * V_127 ;
bool V_128 = false ;
F_129 ( V_6 , V_120 ) ;
V_126 = ( T_2 ) F_130 ( V_120 + V_124 - 1 ) ;
if ( V_126 >= V_9 -> V_129 )
goto V_130;
if ( V_123 )
F_7 ( V_9 ) ;
V_127 = F_131 ( V_9 , V_6 -> V_53 ) ;
if ( F_126 ( V_127 ) ) {
V_12 = F_132 ( V_127 ) ;
goto V_15;
}
if ( F_6 ( V_6 ) ) {
if ( F_133 ( V_127 , V_120 ) )
F_22 ( V_127 ) ;
F_53 ( V_127 , 1 ) ;
V_128 = true ;
goto V_15;
}
F_8 ( & V_11 , V_6 , V_127 , NULL , 0 ) ;
V_12 = F_91 ( & V_11 , V_126 , V_131 ) ;
if ( V_12 ) {
if ( V_12 == - V_94 )
goto V_132;
goto V_15;
}
V_109 = F_93 ( V_11 . V_95 , V_6 ) ;
V_109 -= V_11 . V_96 ;
F_5 ( V_9 , V_109 < 0 ) ;
if ( V_11 . V_96 || F_116 ( V_11 . V_95 ) ) {
F_110 ( & V_11 , V_109 ) ;
V_126 += V_109 ;
}
F_11 ( & V_11 ) ;
V_132:
V_12 = F_134 ( V_6 , V_126 ) ;
V_15:
if ( V_123 )
F_10 ( V_9 ) ;
V_130:
if ( ! V_12 )
V_12 = F_123 ( V_6 , V_120 , V_128 ) ;
F_135 ( V_6 , V_12 ) ;
return V_12 ;
}
int F_136 ( struct V_6 * V_6 )
{
int V_12 ;
if ( ! ( F_27 ( V_6 -> V_27 ) || F_137 ( V_6 -> V_27 ) ||
F_138 ( V_6 -> V_27 ) ) )
return 0 ;
F_139 ( V_6 ) ;
if ( ! F_140 ( V_6 ) ) {
V_12 = F_101 ( V_6 ) ;
if ( V_12 )
return V_12 ;
}
V_12 = F_128 ( V_6 , F_17 ( V_6 ) , true ) ;
if ( V_12 )
return V_12 ;
V_6 -> V_133 = V_6 -> V_134 = F_141 ( V_6 ) ;
F_77 ( V_6 , false ) ;
return 0 ;
}
int F_142 ( struct V_135 * V_136 ,
struct V_31 * V_31 , struct V_137 * V_138 )
{
struct V_6 * V_6 = F_108 ( V_31 ) ;
F_143 ( V_6 , V_138 ) ;
V_138 -> V_139 <<= 3 ;
return 0 ;
}
static void F_144 ( struct V_6 * V_6 , const struct V_140 * V_141 )
{
unsigned int V_142 = V_141 -> V_142 ;
if ( V_142 & V_143 )
V_6 -> V_144 = V_141 -> V_145 ;
if ( V_142 & V_146 )
V_6 -> V_147 = V_141 -> V_148 ;
if ( V_142 & V_149 )
V_6 -> V_150 = F_145 ( V_141 -> V_151 ,
V_6 -> V_13 -> V_152 ) ;
if ( V_142 & V_153 )
V_6 -> V_133 = F_145 ( V_141 -> V_154 ,
V_6 -> V_13 -> V_152 ) ;
if ( V_142 & V_155 )
V_6 -> V_134 = F_145 ( V_141 -> V_156 ,
V_6 -> V_13 -> V_152 ) ;
if ( V_142 & V_157 ) {
T_6 V_158 = V_141 -> V_159 ;
if ( ! F_146 ( V_6 -> V_147 ) && ! F_147 ( V_160 ) )
V_158 &= ~ V_161 ;
F_148 ( V_6 , V_158 ) ;
}
}
int F_149 ( struct V_31 * V_31 , struct V_140 * V_141 )
{
struct V_6 * V_6 = F_108 ( V_31 ) ;
int V_12 ;
bool V_162 = false ;
V_12 = F_150 ( V_31 , V_141 ) ;
if ( V_12 )
return V_12 ;
if ( V_141 -> V_142 & V_163 ) {
if ( F_26 ( V_6 ) &&
F_100 ( V_6 ) )
return - V_107 ;
if ( V_141 -> V_164 <= F_17 ( V_6 ) ) {
F_151 ( V_6 , V_141 -> V_164 ) ;
V_12 = F_136 ( V_6 ) ;
if ( V_12 )
return V_12 ;
} else {
F_151 ( V_6 , V_141 -> V_164 ) ;
if ( ! F_140 ( V_6 ) ) {
V_12 = F_101 ( V_6 ) ;
if ( V_12 )
return V_12 ;
}
V_6 -> V_133 = V_6 -> V_134 = F_141 ( V_6 ) ;
}
V_162 = true ;
}
F_144 ( V_6 , V_141 ) ;
if ( V_141 -> V_142 & V_157 ) {
V_12 = F_152 ( V_6 , F_153 ( V_6 ) ) ;
if ( V_12 || F_70 ( V_6 , V_165 ) ) {
V_6 -> V_27 = F_44 ( V_6 ) -> V_166 ;
F_66 ( V_6 , V_165 ) ;
}
}
F_77 ( V_6 , V_162 ) ;
F_12 ( F_3 ( V_6 ) , true ) ;
return V_12 ;
}
static int F_154 ( struct V_6 * V_6 , T_2 V_14 ,
V_21 V_47 , V_21 V_114 )
{
struct V_8 * V_9 = F_3 ( V_6 ) ;
struct V_5 * V_5 ;
if ( ! V_114 )
return 0 ;
F_12 ( V_9 , true ) ;
F_7 ( V_9 ) ;
V_5 = F_155 ( V_6 , NULL , V_14 , false ) ;
F_10 ( V_9 ) ;
if ( F_126 ( V_5 ) )
return F_132 ( V_5 ) ;
F_25 ( V_5 , V_26 , true ) ;
F_127 ( V_5 , V_47 , V_114 ) ;
F_22 ( V_5 ) ;
F_53 ( V_5 , 1 ) ;
return 0 ;
}
int F_156 ( struct V_6 * V_6 , T_2 V_167 , T_2 V_168 )
{
int V_12 ;
while ( V_167 < V_168 ) {
struct V_10 V_11 ;
T_2 V_88 , V_109 ;
F_8 ( & V_11 , V_6 , NULL , NULL , 0 ) ;
V_12 = F_91 ( & V_11 , V_167 , V_93 ) ;
if ( V_12 ) {
if ( V_12 == - V_94 ) {
V_167 ++ ;
continue;
}
return V_12 ;
}
V_88 = F_93 ( V_11 . V_95 , V_6 ) ;
V_109 = F_157 ( V_88 - V_11 . V_96 , V_168 - V_167 ) ;
F_5 ( F_3 ( V_6 ) , V_109 == 0 || V_109 > V_88 ) ;
F_110 ( & V_11 , V_109 ) ;
F_11 ( & V_11 ) ;
V_167 += V_109 ;
}
return 0 ;
}
static int F_158 ( struct V_6 * V_6 , V_21 V_23 , V_21 V_114 )
{
T_2 V_167 , V_168 ;
V_21 V_169 , V_170 ;
int V_42 ;
V_42 = F_101 ( V_6 ) ;
if ( V_42 )
return V_42 ;
V_167 = ( ( unsigned long long ) V_23 ) >> V_22 ;
V_168 = ( ( unsigned long long ) V_23 + V_114 ) >> V_22 ;
V_169 = V_23 & ( V_25 - 1 ) ;
V_170 = ( V_23 + V_114 ) & ( V_25 - 1 ) ;
if ( V_167 == V_168 ) {
V_42 = F_154 ( V_6 , V_167 , V_169 ,
V_170 - V_169 ) ;
if ( V_42 )
return V_42 ;
} else {
if ( V_169 ) {
V_42 = F_154 ( V_6 , V_167 ++ , V_169 ,
V_25 - V_169 ) ;
if ( V_42 )
return V_42 ;
}
if ( V_170 ) {
V_42 = F_154 ( V_6 , V_168 , 0 , V_170 ) ;
if ( V_42 )
return V_42 ;
}
if ( V_167 < V_168 ) {
struct V_71 * V_17 = V_6 -> V_18 ;
V_21 V_171 , V_172 ;
struct V_8 * V_9 = F_3 ( V_6 ) ;
F_12 ( V_9 , true ) ;
V_171 = ( V_21 ) V_167 << V_22 ;
V_172 = ( V_21 ) V_168 << V_22 ;
F_159 ( V_17 , V_171 ,
V_172 - 1 ) ;
F_7 ( V_9 ) ;
V_42 = F_156 ( V_6 , V_167 , V_168 ) ;
F_10 ( V_9 ) ;
}
}
return V_42 ;
}
static int F_160 ( struct V_6 * V_6 , T_3 * V_81 ,
int * V_173 , T_2 V_174 , T_2 V_114 )
{
struct V_8 * V_9 = F_3 ( V_6 ) ;
struct V_10 V_11 ;
int V_42 , V_175 , V_41 ;
V_176:
F_8 ( & V_11 , V_6 , NULL , NULL , 0 ) ;
V_42 = F_91 ( & V_11 , V_174 , V_131 ) ;
if ( V_42 && V_42 != - V_94 ) {
return V_42 ;
} else if ( V_42 == - V_94 ) {
if ( V_11 . V_177 == 0 )
return - V_94 ;
V_175 = F_157 ( ( T_2 ) V_119 - V_11 . V_96 , V_114 ) ;
V_81 += V_175 ;
V_173 += V_175 ;
goto V_178;
}
V_175 = F_157 ( ( T_2 ) F_93 ( V_11 . V_95 , V_6 ) -
V_11 . V_96 , V_114 ) ;
for ( V_41 = 0 ; V_41 < V_175 ; V_41 ++ , V_81 ++ , V_173 ++ , V_11 . V_96 ++ ) {
* V_81 = F_94 ( V_11 . V_95 , V_11 . V_96 ) ;
if ( ! F_161 ( V_9 , * V_81 ) ) {
if ( F_47 ( V_9 , V_179 ) ) {
F_11 ( & V_11 ) ;
return - V_180 ;
}
F_162 ( & V_11 , V_84 ) ;
* V_173 = 1 ;
}
}
F_11 ( & V_11 ) ;
V_178:
V_114 -= V_175 ;
V_174 += V_175 ;
if ( V_114 )
goto V_176;
return 0 ;
}
static int F_163 ( struct V_6 * V_6 , T_3 * V_81 ,
int * V_173 , T_2 V_174 , int V_114 )
{
struct V_8 * V_9 = F_3 ( V_6 ) ;
struct V_10 V_11 ;
int V_42 , V_41 ;
for ( V_41 = 0 ; V_41 < V_114 ; V_41 ++ , V_173 ++ , V_81 ++ ) {
if ( * V_173 == 0 )
continue;
F_8 ( & V_11 , V_6 , NULL , NULL , 0 ) ;
V_42 = F_91 ( & V_11 , V_174 + V_41 , V_131 ) ;
if ( V_42 ) {
F_120 ( V_9 , V_6 , 1 ) ;
F_115 ( V_9 , * V_81 ) ;
} else {
F_162 ( & V_11 , * V_81 ) ;
}
F_11 ( & V_11 ) ;
}
return 0 ;
}
static int F_164 ( struct V_6 * V_181 , struct V_6 * V_182 ,
T_3 * V_81 , int * V_173 ,
T_2 V_183 , T_2 V_184 , T_2 V_114 , bool V_185 )
{
struct V_8 * V_9 = F_3 ( V_181 ) ;
T_2 V_41 = 0 ;
int V_42 ;
while ( V_41 < V_114 ) {
if ( V_81 [ V_41 ] == V_84 && ! V_185 ) {
V_41 ++ ;
continue;
}
if ( V_173 [ V_41 ] || V_81 [ V_41 ] == V_84 ) {
struct V_10 V_11 ;
struct V_186 V_187 ;
T_7 V_188 ;
T_2 V_189 ;
F_8 ( & V_11 , V_182 , NULL , NULL , 0 ) ;
V_42 = F_91 ( & V_11 , V_184 + V_41 , V_190 ) ;
if ( V_42 )
return V_42 ;
F_165 ( V_9 , V_11 . V_118 , & V_187 ) ;
V_189 = F_157 ( ( T_2 )
F_93 ( V_11 . V_95 , V_182 ) -
V_11 . V_96 , V_114 - V_41 ) ;
do {
V_11 . V_28 = F_94 ( V_11 . V_95 ,
V_11 . V_96 ) ;
F_110 ( & V_11 , 1 ) ;
if ( V_173 [ V_41 ] ) {
F_166 ( V_181 ,
1 , false ) ;
F_166 ( V_182 ,
1 , true ) ;
F_167 ( V_9 , & V_11 , V_11 . V_28 ,
V_81 [ V_41 ] , V_187 . V_191 , true , false ) ;
V_173 [ V_41 ] = 0 ;
}
V_11 . V_96 ++ ;
V_41 ++ ;
V_188 = ( V_184 + V_41 ) << V_22 ;
if ( V_182 -> V_192 < V_188 )
F_168 ( V_182 , V_188 ) ;
} while ( -- V_189 && ( V_173 [ V_41 ] || V_81 [ V_41 ] == V_84 ) );
F_11 ( & V_11 ) ;
} else {
struct V_5 * V_193 , * V_194 ;
V_193 = F_125 ( V_181 , V_183 + V_41 , true ) ;
if ( F_126 ( V_193 ) )
return F_132 ( V_193 ) ;
V_194 = F_155 ( V_182 , NULL , V_184 + V_41 ,
true ) ;
if ( F_126 ( V_194 ) ) {
F_53 ( V_193 , 1 ) ;
return F_132 ( V_194 ) ;
}
F_169 ( V_193 , V_194 ) ;
F_22 ( V_194 ) ;
F_53 ( V_194 , 1 ) ;
F_53 ( V_193 , 1 ) ;
V_42 = F_156 ( V_181 , V_183 + V_41 , V_183 + V_41 + 1 ) ;
if ( V_42 )
return V_42 ;
V_41 ++ ;
}
}
return 0 ;
}
static int F_170 ( struct V_6 * V_181 ,
struct V_6 * V_182 , T_2 V_183 , T_2 V_184 ,
T_2 V_114 , bool V_185 )
{
T_3 * V_195 ;
int * V_173 ;
T_2 V_196 ;
int V_42 ;
while ( V_114 ) {
V_196 = F_157 ( ( T_2 ) 4 * V_119 , V_114 ) ;
V_195 = F_171 ( sizeof( T_3 ) * V_196 , V_197 ) ;
if ( ! V_195 )
return - V_198 ;
V_173 = F_171 ( sizeof( int ) * V_196 , V_197 ) ;
if ( ! V_173 ) {
F_172 ( V_195 ) ;
return - V_198 ;
}
V_42 = F_160 ( V_181 , V_195 ,
V_173 , V_183 , V_196 ) ;
if ( V_42 )
goto V_199;
V_42 = F_164 ( V_181 , V_182 , V_195 ,
V_173 , V_183 , V_184 , V_196 , V_185 ) ;
if ( V_42 )
goto V_199;
V_183 += V_196 ;
V_184 += V_196 ;
V_114 -= V_196 ;
F_172 ( V_195 ) ;
F_172 ( V_173 ) ;
}
return 0 ;
V_199:
F_163 ( V_181 , V_195 , V_173 , V_183 , V_114 ) ;
F_172 ( V_195 ) ;
F_172 ( V_173 ) ;
return V_42 ;
}
static int F_173 ( struct V_6 * V_6 , T_2 V_47 , T_2 V_48 )
{
struct V_8 * V_9 = F_3 ( V_6 ) ;
T_2 V_200 = ( F_17 ( V_6 ) + V_25 - 1 ) / V_25 ;
int V_42 ;
F_12 ( V_9 , true ) ;
F_7 ( V_9 ) ;
F_174 ( V_6 ) ;
V_42 = F_170 ( V_6 , V_6 , V_48 , V_47 , V_200 - V_48 , true ) ;
F_10 ( V_9 ) ;
return V_42 ;
}
static int F_175 ( struct V_6 * V_6 , V_21 V_23 , V_21 V_114 )
{
T_2 V_167 , V_168 ;
V_21 V_188 ;
int V_42 ;
if ( V_23 + V_114 >= F_17 ( V_6 ) )
return - V_101 ;
if ( V_23 & ( V_201 - 1 ) || V_114 & ( V_201 - 1 ) )
return - V_101 ;
V_42 = F_101 ( V_6 ) ;
if ( V_42 )
return V_42 ;
V_167 = V_23 >> V_22 ;
V_168 = ( V_23 + V_114 ) >> V_22 ;
V_42 = F_65 ( V_6 -> V_18 , V_23 , V_202 ) ;
if ( V_42 )
return V_42 ;
F_176 ( V_6 , V_23 ) ;
V_42 = F_173 ( V_6 , V_167 , V_168 ) ;
if ( V_42 )
return V_42 ;
F_65 ( V_6 -> V_18 , V_23 , V_202 ) ;
F_176 ( V_6 , V_23 ) ;
V_188 = F_17 ( V_6 ) - V_114 ;
F_176 ( V_6 , V_188 ) ;
V_42 = F_128 ( V_6 , V_188 , true ) ;
if ( ! V_42 )
F_168 ( V_6 , V_188 ) ;
return V_42 ;
}
static int F_177 ( struct V_10 * V_11 , T_2 V_47 ,
T_2 V_48 )
{
struct V_8 * V_9 = F_3 ( V_11 -> V_6 ) ;
T_2 V_14 = V_47 ;
unsigned int V_96 = V_11 -> V_96 ;
T_8 V_109 = 0 ;
int V_42 ;
for (; V_14 < V_48 ; V_14 ++ , V_11 -> V_96 ++ ) {
if ( F_94 ( V_11 -> V_95 , V_11 -> V_96 ) == V_84 )
V_109 ++ ;
}
V_11 -> V_96 = V_96 ;
V_42 = F_178 ( V_11 , V_109 ) ;
if ( V_42 )
return V_42 ;
V_11 -> V_96 = V_96 ;
for ( V_14 = V_47 ; V_14 < V_48 ; V_14 ++ , V_11 -> V_96 ++ ) {
V_11 -> V_28 =
F_94 ( V_11 -> V_95 , V_11 -> V_96 ) ;
if ( V_11 -> V_28 == V_84 ) {
V_42 = - V_203 ;
break;
}
if ( V_11 -> V_28 != V_83 ) {
F_115 ( V_9 , V_11 -> V_28 ) ;
V_11 -> V_28 = V_83 ;
F_114 ( V_11 ) ;
}
}
F_119 ( V_11 , V_47 , 0 , V_14 - V_47 ) ;
return V_42 ;
}
static int F_179 ( struct V_6 * V_6 , V_21 V_23 , V_21 V_114 ,
int V_158 )
{
struct V_8 * V_9 = F_3 ( V_6 ) ;
struct V_71 * V_17 = V_6 -> V_18 ;
T_2 V_14 , V_167 , V_168 ;
V_21 V_188 = F_17 ( V_6 ) ;
V_21 V_169 , V_170 ;
int V_42 = 0 ;
V_42 = F_180 ( V_6 , ( V_114 + V_23 ) ) ;
if ( V_42 )
return V_42 ;
V_42 = F_101 ( V_6 ) ;
if ( V_42 )
return V_42 ;
V_42 = F_65 ( V_17 , V_23 , V_23 + V_114 - 1 ) ;
if ( V_42 )
return V_42 ;
F_181 ( V_6 , V_23 , V_23 + V_114 - 1 ) ;
V_167 = ( ( unsigned long long ) V_23 ) >> V_22 ;
V_168 = ( ( unsigned long long ) V_23 + V_114 ) >> V_22 ;
V_169 = V_23 & ( V_25 - 1 ) ;
V_170 = ( V_23 + V_114 ) & ( V_25 - 1 ) ;
if ( V_167 == V_168 ) {
V_42 = F_154 ( V_6 , V_167 , V_169 ,
V_170 - V_169 ) ;
if ( V_42 )
return V_42 ;
if ( V_23 + V_114 > V_188 )
V_188 = V_23 + V_114 ;
V_188 = F_182 ( V_21 , V_188 , V_23 + V_114 ) ;
} else {
if ( V_169 ) {
V_42 = F_154 ( V_6 , V_167 ++ , V_169 ,
V_25 - V_169 ) ;
if ( V_42 )
return V_42 ;
V_188 = F_182 ( V_21 , V_188 ,
( V_21 ) V_167 << V_22 ) ;
}
for ( V_14 = V_167 ; V_14 < V_168 ; ) {
struct V_10 V_11 ;
unsigned int V_88 ;
T_2 V_48 ;
F_7 ( V_9 ) ;
F_8 ( & V_11 , V_6 , NULL , NULL , 0 ) ;
V_42 = F_91 ( & V_11 , V_14 , V_190 ) ;
if ( V_42 ) {
F_10 ( V_9 ) ;
goto V_15;
}
V_88 = F_93 ( V_11 . V_95 , V_6 ) ;
V_48 = F_157 ( V_168 , V_88 - V_11 . V_96 + V_14 ) ;
V_42 = F_177 ( & V_11 , V_14 , V_48 ) ;
F_11 ( & V_11 ) ;
F_10 ( V_9 ) ;
F_12 ( V_9 , V_11 . V_16 ) ;
if ( V_42 )
goto V_15;
V_14 = V_48 ;
V_188 = F_182 ( V_21 , V_188 ,
( V_21 ) V_14 << V_22 ) ;
}
if ( V_170 ) {
V_42 = F_154 ( V_6 , V_168 , 0 , V_170 ) ;
if ( V_42 )
goto V_15;
V_188 = F_182 ( V_21 , V_188 , V_23 + V_114 ) ;
}
}
V_15:
if ( ! ( V_158 & V_204 ) && F_17 ( V_6 ) < V_188 )
F_168 ( V_6 , V_188 ) ;
return V_42 ;
}
static int F_183 ( struct V_6 * V_6 , V_21 V_23 , V_21 V_114 )
{
struct V_8 * V_9 = F_3 ( V_6 ) ;
T_2 V_205 , V_167 , V_168 , V_206 , V_207 ;
V_21 V_188 ;
int V_42 = 0 ;
V_188 = F_17 ( V_6 ) + V_114 ;
if ( V_188 > V_6 -> V_13 -> V_87 )
return - V_208 ;
if ( V_23 >= F_17 ( V_6 ) )
return - V_101 ;
if ( V_23 & ( V_201 - 1 ) || V_114 & ( V_201 - 1 ) )
return - V_101 ;
V_42 = F_101 ( V_6 ) ;
if ( V_42 )
return V_42 ;
F_12 ( V_9 , true ) ;
V_42 = F_128 ( V_6 , F_17 ( V_6 ) , true ) ;
if ( V_42 )
return V_42 ;
V_42 = F_65 ( V_6 -> V_18 , V_23 , V_202 ) ;
if ( V_42 )
return V_42 ;
F_176 ( V_6 , V_23 ) ;
V_167 = V_23 >> V_22 ;
V_168 = ( V_23 + V_114 ) >> V_22 ;
V_206 = V_168 - V_167 ;
V_207 = ( F_17 ( V_6 ) + V_25 - 1 ) / V_25 ;
while ( ! V_42 && V_207 > V_167 ) {
V_205 = V_207 - V_167 ;
if ( V_205 > V_206 )
V_205 = V_206 ;
V_207 -= V_205 ;
F_7 ( V_9 ) ;
F_174 ( V_6 ) ;
V_42 = F_170 ( V_6 , V_6 , V_207 ,
V_207 + V_206 , V_205 , false ) ;
F_10 ( V_9 ) ;
}
F_65 ( V_6 -> V_18 , V_23 , V_202 ) ;
F_176 ( V_6 , V_23 ) ;
if ( ! V_42 )
F_168 ( V_6 , V_188 ) ;
return V_42 ;
}
static int F_184 ( struct V_6 * V_6 , V_21 V_23 ,
V_21 V_114 , int V_158 )
{
struct V_8 * V_9 = F_3 ( V_6 ) ;
struct V_209 V_210 = { . V_211 = NULL } ;
T_2 V_168 ;
V_21 V_188 = F_17 ( V_6 ) ;
V_21 V_170 ;
int V_12 ;
V_12 = F_180 ( V_6 , ( V_114 + V_23 ) ) ;
if ( V_12 )
return V_12 ;
V_12 = F_101 ( V_6 ) ;
if ( V_12 )
return V_12 ;
F_12 ( V_9 , true ) ;
V_168 = ( ( unsigned long long ) V_23 + V_114 ) >> V_22 ;
V_170 = ( V_23 + V_114 ) & ( V_25 - 1 ) ;
V_210 . V_212 = ( ( unsigned long long ) V_23 ) >> V_22 ;
V_210 . V_213 = V_168 - V_210 . V_212 ;
if ( V_170 )
V_210 . V_213 ++ ;
V_12 = V_209 ( V_6 , & V_210 , 1 , V_214 ) ;
if ( V_12 ) {
T_2 V_215 ;
if ( ! V_210 . V_213 )
return V_12 ;
V_215 = V_210 . V_212 + V_210 . V_213 - 1 ;
V_188 = ( V_215 == V_168 ) ? V_23 + V_114 :
( V_21 ) ( V_215 + 1 ) << V_22 ;
} else {
V_188 = ( ( V_21 ) V_168 << V_22 ) + V_170 ;
}
if ( ! ( V_158 & V_204 ) && F_17 ( V_6 ) < V_188 )
F_168 ( V_6 , V_188 ) ;
return V_12 ;
}
static long F_185 ( struct V_46 * V_46 , int V_158 ,
V_21 V_23 , V_21 V_114 )
{
struct V_6 * V_6 = F_2 ( V_46 ) ;
long V_42 = 0 ;
if ( ! F_27 ( V_6 -> V_27 ) )
return - V_101 ;
if ( F_26 ( V_6 ) &&
( V_158 & ( V_216 | V_217 ) ) )
return - V_218 ;
if ( V_158 & ~ ( V_204 | V_219 |
V_216 | V_220 |
V_217 ) )
return - V_218 ;
F_89 ( V_6 ) ;
if ( V_158 & V_219 ) {
if ( V_23 >= V_6 -> V_192 )
goto V_15;
V_42 = F_158 ( V_6 , V_23 , V_114 ) ;
} else if ( V_158 & V_216 ) {
V_42 = F_175 ( V_6 , V_23 , V_114 ) ;
} else if ( V_158 & V_220 ) {
V_42 = F_179 ( V_6 , V_23 , V_114 , V_158 ) ;
} else if ( V_158 & V_217 ) {
V_42 = F_183 ( V_6 , V_23 , V_114 ) ;
} else {
V_42 = F_184 ( V_6 , V_23 , V_114 , V_158 ) ;
}
if ( ! V_42 ) {
V_6 -> V_133 = V_6 -> V_134 = F_141 ( V_6 ) ;
F_77 ( V_6 , false ) ;
if ( V_158 & V_204 )
F_186 ( V_6 ) ;
F_30 ( F_3 ( V_6 ) , V_29 ) ;
}
V_15:
F_95 ( V_6 ) ;
F_187 ( V_6 , V_158 , V_23 , V_114 , V_42 ) ;
return V_42 ;
}
static int F_188 ( struct V_6 * V_6 , struct V_46 * V_105 )
{
if ( ! ( V_105 -> V_221 & V_222 ) ||
F_189 ( & V_6 -> V_223 ) != 1 )
return 0 ;
if ( F_190 ( V_6 ) )
F_191 ( V_6 ) ;
if ( F_192 ( V_6 ) ) {
F_66 ( V_6 , V_224 ) ;
F_64 ( V_6 , V_225 ) ;
F_193 ( V_6 -> V_18 ) ;
F_66 ( V_6 , V_225 ) ;
}
return 0 ;
}
static inline T_9 F_194 ( T_6 V_158 , T_9 V_226 )
{
if ( F_137 ( V_158 ) )
return V_226 ;
else if ( F_27 ( V_158 ) )
return V_226 & V_227 ;
else
return V_226 & V_228 ;
}
static int F_195 ( struct V_46 * V_105 , unsigned long V_229 )
{
struct V_6 * V_6 = F_2 ( V_105 ) ;
struct V_43 * V_44 = F_44 ( V_6 ) ;
unsigned int V_226 = V_44 -> V_230 & V_231 ;
return F_196 ( V_226 , ( int V_232 * ) V_229 ) ;
}
static int F_197 ( struct V_46 * V_105 , unsigned long V_229 )
{
struct V_6 * V_6 = F_2 ( V_105 ) ;
struct V_43 * V_44 = F_44 ( V_6 ) ;
unsigned int V_226 ;
unsigned int V_233 ;
int V_42 ;
if ( ! F_198 ( V_6 ) )
return - V_107 ;
if ( F_199 ( V_226 , ( int V_232 * ) V_229 ) )
return - V_19 ;
V_42 = F_200 ( V_105 ) ;
if ( V_42 )
return V_42 ;
V_226 = F_194 ( V_6 -> V_27 , V_226 ) ;
F_89 ( V_6 ) ;
V_233 = V_44 -> V_230 ;
if ( ( V_226 ^ V_233 ) & ( V_234 | V_235 ) ) {
if ( ! F_147 ( V_236 ) ) {
F_95 ( V_6 ) ;
V_42 = - V_108 ;
goto V_15;
}
}
V_226 = V_226 & V_237 ;
V_226 |= V_233 & ~ V_237 ;
V_44 -> V_230 = V_226 ;
F_95 ( V_6 ) ;
V_6 -> V_134 = F_141 ( V_6 ) ;
F_201 ( V_6 ) ;
V_15:
F_202 ( V_105 ) ;
return V_42 ;
}
static int F_203 ( struct V_46 * V_105 , unsigned long V_229 )
{
struct V_6 * V_6 = F_2 ( V_105 ) ;
return F_196 ( V_6 -> V_238 , ( int V_232 * ) V_229 ) ;
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
F_89 ( V_6 ) ;
if ( F_190 ( V_6 ) )
goto V_15;
V_42 = F_101 ( V_6 ) ;
if ( V_42 )
goto V_15;
F_64 ( V_6 , V_239 ) ;
F_30 ( F_3 ( V_6 ) , V_29 ) ;
if ( ! F_62 ( V_6 ) )
goto V_15;
F_205 ( F_3 ( V_6 ) -> V_240 , V_241 ,
L_1 ,
V_6 -> V_53 , F_62 ( V_6 ) ) ;
V_42 = F_65 ( V_6 -> V_18 , 0 , V_202 ) ;
if ( V_42 )
F_66 ( V_6 , V_239 ) ;
V_15:
F_95 ( V_6 ) ;
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
F_89 ( V_6 ) ;
if ( F_192 ( V_6 ) )
goto V_242;
if ( F_190 ( V_6 ) ) {
F_66 ( V_6 , V_239 ) ;
V_42 = F_207 ( V_6 ) ;
if ( V_42 ) {
F_64 ( V_6 , V_239 ) ;
goto V_242;
}
}
V_42 = F_59 ( V_105 , 0 , V_202 , 0 , true ) ;
V_242:
F_95 ( V_6 ) ;
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
F_89 ( V_6 ) ;
if ( F_192 ( V_6 ) )
goto V_15;
V_42 = F_101 ( V_6 ) ;
if ( V_42 )
goto V_15;
F_64 ( V_6 , V_224 ) ;
F_30 ( F_3 ( V_6 ) , V_29 ) ;
V_15:
F_95 ( V_6 ) ;
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
F_89 ( V_6 ) ;
if ( ! F_192 ( V_6 ) )
goto V_15;
if ( ! F_210 ( V_6 ) ) {
V_42 = F_123 ( V_6 , 0 , true ) ;
goto V_15;
}
V_42 = F_158 ( V_6 , 0 , V_201 ) ;
V_15:
F_95 ( V_6 ) ;
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
F_89 ( V_6 ) ;
if ( F_190 ( V_6 ) )
F_191 ( V_6 ) ;
if ( F_192 ( V_6 ) ) {
F_66 ( V_6 , V_224 ) ;
V_42 = F_59 ( V_105 , 0 , V_202 , 0 , true ) ;
}
F_95 ( V_6 ) ;
F_202 ( V_105 ) ;
F_30 ( F_3 ( V_6 ) , V_29 ) ;
return V_42 ;
}
static int F_212 ( struct V_46 * V_105 , unsigned long V_229 )
{
struct V_6 * V_6 = F_2 ( V_105 ) ;
struct V_8 * V_9 = F_3 ( V_6 ) ;
struct V_243 * V_240 = V_9 -> V_240 ;
T_9 V_244 ;
int V_42 ;
if ( ! F_147 ( V_245 ) )
return - V_108 ;
if ( F_199 ( V_244 , ( T_9 V_232 * ) V_229 ) )
return - V_19 ;
V_42 = F_200 ( V_105 ) ;
if ( V_42 )
return V_42 ;
switch ( V_244 ) {
case V_246 :
V_240 = F_213 ( V_240 -> V_247 ) ;
if ( V_240 && ! F_126 ( V_240 ) ) {
F_214 ( V_9 , false ) ;
F_215 ( V_240 -> V_247 , V_240 ) ;
}
break;
case V_248 :
F_74 ( V_240 , 1 ) ;
F_214 ( V_9 , false ) ;
break;
case V_249 :
F_214 ( V_9 , false ) ;
break;
case V_250 :
F_216 ( V_9 , V_251 , V_59 ) ;
F_214 ( V_9 , false ) ;
break;
default:
V_42 = - V_101 ;
goto V_15;
}
F_30 ( V_9 , V_29 ) ;
V_15:
F_202 ( V_105 ) ;
return V_42 ;
}
static int F_217 ( struct V_46 * V_105 , unsigned long V_229 )
{
struct V_6 * V_6 = F_2 ( V_105 ) ;
struct V_243 * V_240 = V_6 -> V_13 ;
struct V_252 * V_253 = F_218 ( V_240 -> V_247 ) ;
struct V_254 V_255 ;
int V_42 ;
if ( ! F_147 ( V_245 ) )
return - V_108 ;
if ( ! F_219 ( V_253 ) )
return - V_218 ;
if ( F_220 ( & V_255 , (struct V_254 V_232 * ) V_229 ,
sizeof( V_255 ) ) )
return - V_19 ;
V_42 = F_200 ( V_105 ) ;
if ( V_42 )
return V_42 ;
V_255 . V_256 = F_221 ( ( unsigned int ) V_255 . V_256 ,
V_253 -> V_257 . V_258 ) ;
V_42 = F_222 ( F_223 ( V_240 ) , & V_255 ) ;
F_202 ( V_105 ) ;
if ( V_42 < 0 )
return V_42 ;
if ( F_224 ( (struct V_254 V_232 * ) V_229 , & V_255 ,
sizeof( V_255 ) ) )
return - V_19 ;
F_30 ( F_3 ( V_6 ) , V_29 ) ;
return 0 ;
}
static bool F_225 ( T_10 V_259 [ 16 ] )
{
int V_41 ;
for ( V_41 = 0 ; V_41 < 16 ; V_41 ++ )
if ( V_259 [ V_41 ] )
return true ;
return false ;
}
static int F_226 ( struct V_46 * V_105 , unsigned long V_229 )
{
struct V_6 * V_6 = F_2 ( V_105 ) ;
F_30 ( F_3 ( V_6 ) , V_29 ) ;
return F_227 ( V_105 , ( const void V_232 * ) V_229 ) ;
}
static int F_228 ( struct V_46 * V_105 , unsigned long V_229 )
{
return F_229 ( V_105 , ( void V_232 * ) V_229 ) ;
}
static int F_230 ( struct V_46 * V_105 , unsigned long V_229 )
{
struct V_6 * V_6 = F_2 ( V_105 ) ;
struct V_8 * V_9 = F_3 ( V_6 ) ;
int V_12 ;
if ( ! F_231 ( V_6 -> V_13 ) )
return - V_218 ;
if ( F_225 ( V_9 -> V_260 -> V_261 ) )
goto V_262;
V_12 = F_200 ( V_105 ) ;
if ( V_12 )
return V_12 ;
F_232 ( V_9 -> V_260 -> V_261 ) ;
V_12 = F_233 ( V_9 , false ) ;
if ( V_12 ) {
memset ( V_9 -> V_260 -> V_261 , 0 , 16 ) ;
F_202 ( V_105 ) ;
return V_12 ;
}
F_202 ( V_105 ) ;
V_262:
if ( F_224 ( ( T_10 V_232 * ) V_229 , V_9 -> V_260 -> V_261 ,
16 ) )
return - V_19 ;
return 0 ;
}
static int F_234 ( struct V_46 * V_105 , unsigned long V_229 )
{
struct V_6 * V_6 = F_2 ( V_105 ) ;
struct V_8 * V_9 = F_3 ( V_6 ) ;
T_9 V_263 ;
int V_42 ;
if ( ! F_147 ( V_245 ) )
return - V_108 ;
if ( F_199 ( V_263 , ( T_9 V_232 * ) V_229 ) )
return - V_19 ;
if ( F_60 ( V_9 -> V_240 ) )
return - V_264 ;
V_42 = F_200 ( V_105 ) ;
if ( V_42 )
return V_42 ;
if ( ! V_263 ) {
if ( ! F_235 ( & V_9 -> V_265 ) ) {
V_42 = - V_266 ;
goto V_15;
}
} else {
F_236 ( & V_9 -> V_265 ) ;
}
V_42 = F_237 ( V_9 , V_263 , true ) ;
V_15:
F_202 ( V_105 ) ;
return V_42 ;
}
static int F_238 ( struct V_46 * V_105 , unsigned long V_229 )
{
struct V_6 * V_6 = F_2 ( V_105 ) ;
struct V_8 * V_9 = F_3 ( V_6 ) ;
int V_42 ;
if ( ! F_147 ( V_245 ) )
return - V_108 ;
if ( F_60 ( V_9 -> V_240 ) )
return - V_264 ;
V_42 = F_200 ( V_105 ) ;
if ( V_42 )
return V_42 ;
V_42 = F_74 ( V_9 -> V_240 , 1 ) ;
F_202 ( V_105 ) ;
return V_42 ;
}
static int F_239 ( struct V_8 * V_9 ,
struct V_46 * V_105 ,
struct V_267 * V_255 )
{
struct V_6 * V_6 = F_2 ( V_105 ) ;
struct V_209 V_210 = { . V_211 = NULL } ;
struct V_268 V_269 ;
T_2 V_167 , V_168 ;
unsigned int V_270 = V_9 -> V_271 ;
unsigned int V_272 = 0 , V_273 ;
unsigned int V_274 = V_9 -> V_275 * V_270 ;
T_3 V_172 = 0 ;
bool V_276 = false ;
int V_12 ;
if ( F_240 ( V_6 ) )
return - V_101 ;
V_167 = V_255 -> V_47 >> V_22 ;
V_168 = ( V_255 -> V_47 + V_255 -> V_114 ) >> V_22 ;
F_12 ( V_9 , true ) ;
F_89 ( V_6 ) ;
V_12 = F_65 ( V_6 -> V_18 , V_255 -> V_47 ,
V_255 -> V_47 + V_255 -> V_114 - 1 ) ;
if ( V_12 )
goto V_15;
if ( F_241 ( V_6 , V_167 , & V_269 ) ) {
if ( V_269 . V_117 + V_269 . V_114 >= V_168 )
goto V_15;
}
V_210 . V_212 = V_167 ;
while ( V_210 . V_212 < V_168 ) {
V_210 . V_213 = V_168 - V_210 . V_212 ;
V_12 = V_209 ( V_6 , & V_210 , 0 , V_277 ) ;
if ( V_12 )
goto V_15;
if ( ! ( V_210 . V_278 & V_279 ) ) {
V_210 . V_212 ++ ;
continue;
}
if ( V_172 && V_172 != V_210 . V_280 ) {
V_276 = true ;
break;
}
V_172 = V_210 . V_280 + V_210 . V_213 ;
V_210 . V_212 += V_210 . V_213 ;
}
if ( ! V_276 )
goto V_15;
V_210 . V_212 = V_167 ;
V_210 . V_213 = V_168 - V_167 ;
V_273 = ( V_210 . V_213 + V_274 - 1 ) / V_274 ;
if ( F_242 ( V_9 , 0 , V_273 ) ) {
V_12 = - V_281 ;
goto V_15;
}
while ( V_210 . V_212 < V_168 ) {
T_2 V_207 ;
int V_282 = 0 ;
V_283:
V_210 . V_213 = V_168 - V_210 . V_212 ;
V_12 = V_209 ( V_6 , & V_210 , 0 , V_277 ) ;
if ( V_12 )
goto V_284;
if ( ! ( V_210 . V_278 & V_279 ) ) {
V_210 . V_212 ++ ;
continue;
}
F_64 ( V_6 , V_285 ) ;
V_207 = V_210 . V_212 ;
while ( V_207 < V_210 . V_212 + V_210 . V_213 && V_282 < V_270 ) {
struct V_5 * V_5 ;
V_5 = F_125 ( V_6 , V_207 , true ) ;
if ( F_126 ( V_5 ) ) {
V_12 = F_132 ( V_5 ) ;
goto V_284;
}
F_22 ( V_5 ) ;
F_53 ( V_5 , 1 ) ;
V_207 ++ ;
V_282 ++ ;
V_272 ++ ;
}
V_210 . V_212 = V_207 ;
if ( V_207 < V_168 && V_282 < V_270 )
goto V_283;
F_66 ( V_6 , V_285 ) ;
V_12 = F_193 ( V_6 -> V_18 ) ;
if ( V_12 )
goto V_15;
}
V_284:
F_66 ( V_6 , V_285 ) ;
V_15:
F_95 ( V_6 ) ;
if ( ! V_12 )
V_255 -> V_114 = ( T_5 ) V_272 << V_22 ;
return V_12 ;
}
static int F_243 ( struct V_46 * V_105 , unsigned long V_229 )
{
struct V_6 * V_6 = F_2 ( V_105 ) ;
struct V_8 * V_9 = F_3 ( V_6 ) ;
struct V_267 V_255 ;
int V_12 ;
if ( ! F_147 ( V_245 ) )
return - V_108 ;
if ( ! F_27 ( V_6 -> V_27 ) )
return - V_101 ;
V_12 = F_200 ( V_105 ) ;
if ( V_12 )
return V_12 ;
if ( F_60 ( V_9 -> V_240 ) ) {
V_12 = - V_264 ;
goto V_15;
}
if ( F_220 ( & V_255 , (struct V_267 V_232 * ) V_229 ,
sizeof( V_255 ) ) ) {
V_12 = - V_19 ;
goto V_15;
}
if ( V_255 . V_47 & ( V_201 - 1 ) ||
V_255 . V_114 & ( V_201 - 1 ) ) {
V_12 = - V_101 ;
goto V_15;
}
V_12 = F_239 ( V_9 , V_105 , & V_255 ) ;
F_30 ( V_9 , V_29 ) ;
if ( V_12 < 0 )
goto V_15;
if ( F_224 ( (struct V_267 V_232 * ) V_229 , & V_255 ,
sizeof( V_255 ) ) )
V_12 = - V_19 ;
V_15:
F_202 ( V_105 ) ;
return V_12 ;
}
static int F_244 ( struct V_46 * V_286 , V_21 V_287 ,
struct V_46 * V_288 , V_21 V_289 , T_7 V_114 )
{
struct V_6 * V_183 = F_2 ( V_286 ) ;
struct V_6 * V_184 = F_2 ( V_288 ) ;
struct V_8 * V_9 = F_3 ( V_183 ) ;
T_7 V_196 = V_114 , V_290 = 0 ;
T_7 V_291 ;
int V_42 ;
if ( V_286 -> V_292 . V_136 != V_288 -> V_292 . V_136 ||
V_183 -> V_13 != V_184 -> V_13 )
return - V_293 ;
if ( F_15 ( F_60 ( V_183 -> V_13 ) ) )
return - V_264 ;
if ( ! F_27 ( V_183 -> V_27 ) || ! F_27 ( V_184 -> V_27 ) )
return - V_101 ;
if ( F_26 ( V_183 ) || F_26 ( V_184 ) )
return - V_218 ;
if ( V_183 == V_184 ) {
if ( V_287 == V_289 )
return 0 ;
if ( V_289 > V_287 && V_289 < V_287 + V_114 )
return - V_101 ;
}
F_89 ( V_183 ) ;
if ( V_183 != V_184 ) {
if ( ! F_245 ( V_184 ) ) {
V_42 = - V_266 ;
goto V_15;
}
}
V_42 = - V_101 ;
if ( V_287 + V_114 > V_183 -> V_192 || V_287 + V_114 < V_287 )
goto V_294;
if ( V_114 == 0 )
V_196 = V_114 = V_183 -> V_192 - V_287 ;
if ( V_287 + V_114 == V_183 -> V_192 )
V_114 = F_246 ( V_183 -> V_192 , V_201 ) - V_287 ;
if ( V_114 == 0 ) {
V_42 = 0 ;
goto V_294;
}
V_291 = V_184 -> V_192 ;
if ( V_289 + V_196 > V_184 -> V_192 )
V_290 = V_289 + V_196 ;
if ( ! F_247 ( V_287 , V_201 ) ||
! F_247 ( V_287 + V_114 , V_201 ) ||
! F_247 ( V_289 , V_201 ) )
goto V_294;
V_42 = F_101 ( V_183 ) ;
if ( V_42 )
goto V_294;
V_42 = F_101 ( V_184 ) ;
if ( V_42 )
goto V_294;
V_42 = F_65 ( V_183 -> V_18 ,
V_287 , V_287 + V_114 ) ;
if ( V_42 )
goto V_294;
V_42 = F_65 ( V_184 -> V_18 ,
V_289 , V_289 + V_114 ) ;
if ( V_42 )
goto V_294;
F_12 ( V_9 , true ) ;
F_7 ( V_9 ) ;
V_42 = F_170 ( V_183 , V_184 , V_287 >> V_295 ,
V_289 >> V_295 ,
V_114 >> V_295 , false ) ;
if ( ! V_42 ) {
if ( V_290 )
F_168 ( V_184 , V_290 ) ;
else if ( V_291 != V_184 -> V_192 )
F_168 ( V_184 , V_291 ) ;
}
F_10 ( V_9 ) ;
V_294:
if ( V_183 != V_184 )
F_95 ( V_184 ) ;
V_15:
F_95 ( V_183 ) ;
return V_42 ;
}
static int F_248 ( struct V_46 * V_105 , unsigned long V_229 )
{
struct V_296 V_255 ;
struct V_297 V_184 ;
int V_12 ;
if ( ! ( V_105 -> V_221 & V_298 ) ||
! ( V_105 -> V_221 & V_222 ) )
return - V_299 ;
if ( F_220 ( & V_255 , (struct V_296 V_232 * ) V_229 ,
sizeof( V_255 ) ) )
return - V_19 ;
V_184 = F_249 ( V_255 . V_300 ) ;
if ( ! V_184 . V_46 )
return - V_299 ;
if ( ! ( V_184 . V_46 -> V_221 & V_222 ) ) {
V_12 = - V_299 ;
goto V_242;
}
V_12 = F_200 ( V_105 ) ;
if ( V_12 )
goto V_242;
V_12 = F_244 ( V_105 , V_255 . V_287 , V_184 . V_46 ,
V_255 . V_289 , V_255 . V_114 ) ;
F_202 ( V_105 ) ;
if ( F_224 ( (struct V_296 V_232 * ) V_229 ,
& V_255 , sizeof( V_255 ) ) )
V_12 = - V_19 ;
V_242:
F_250 ( V_184 ) ;
return V_12 ;
}
long F_251 ( struct V_46 * V_105 , unsigned int V_301 , unsigned long V_229 )
{
switch ( V_301 ) {
case V_302 :
return F_195 ( V_105 , V_229 ) ;
case V_303 :
return F_197 ( V_105 , V_229 ) ;
case V_304 :
return F_203 ( V_105 , V_229 ) ;
case V_305 :
return F_204 ( V_105 ) ;
case V_306 :
return F_206 ( V_105 ) ;
case V_307 :
return F_208 ( V_105 ) ;
case V_308 :
return F_209 ( V_105 ) ;
case V_309 :
return F_211 ( V_105 ) ;
case V_310 :
return F_212 ( V_105 , V_229 ) ;
case V_311 :
return F_217 ( V_105 , V_229 ) ;
case V_312 :
return F_226 ( V_105 , V_229 ) ;
case V_313 :
return F_228 ( V_105 , V_229 ) ;
case V_314 :
return F_230 ( V_105 , V_229 ) ;
case V_315 :
return F_234 ( V_105 , V_229 ) ;
case V_316 :
return F_238 ( V_105 , V_229 ) ;
case V_317 :
return F_243 ( V_105 , V_229 ) ;
case V_318 :
return F_248 ( V_105 , V_229 ) ;
default:
return - V_319 ;
}
}
static T_11 F_252 ( struct V_320 * V_321 , struct V_322 * V_120 )
{
struct V_46 * V_46 = V_321 -> V_323 ;
struct V_6 * V_6 = F_2 ( V_46 ) ;
struct V_324 V_325 ;
T_11 V_42 ;
if ( F_26 ( V_6 ) &&
! F_105 ( V_6 ) &&
F_100 ( V_6 ) )
return - V_107 ;
F_89 ( V_6 ) ;
V_42 = F_253 ( V_321 , V_120 ) ;
if ( V_42 > 0 ) {
int V_12 = F_254 ( V_321 , V_120 ) ;
if ( V_12 ) {
F_95 ( V_6 ) ;
return V_12 ;
}
F_255 ( & V_325 ) ;
V_42 = F_256 ( V_321 , V_120 ) ;
F_257 ( & V_325 ) ;
}
F_95 ( V_6 ) ;
if ( V_42 > 0 )
V_42 = F_258 ( V_321 , V_42 ) ;
return V_42 ;
}
long F_259 ( struct V_46 * V_46 , unsigned int V_301 , unsigned long V_229 )
{
switch ( V_301 ) {
case V_326 :
V_301 = V_302 ;
break;
case V_327 :
V_301 = V_303 ;
break;
case V_328 :
V_301 = V_304 ;
break;
case V_305 :
case V_306 :
case V_307 :
case V_308 :
case V_309 :
case V_310 :
case V_312 :
case V_314 :
case V_313 :
case V_315 :
case V_316 :
case V_317 :
break;
case V_318 :
break;
default:
return - V_329 ;
}
return F_251 ( V_46 , V_301 , ( unsigned long ) F_260 ( V_229 ) ) ;
}
