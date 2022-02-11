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
int F_62 ( struct V_46 * V_46 , V_21 V_47 , V_21 V_48 , int V_49 )
{
struct V_6 * V_6 = V_46 -> V_50 -> V_51 ;
struct V_43 * V_44 = F_46 ( V_6 ) ;
struct V_8 * V_9 = F_3 ( V_6 ) ;
T_1 V_40 = V_6 -> V_35 ;
int V_42 = 0 ;
bool V_33 = false ;
struct V_52 V_53 = {
. V_54 = V_55 ,
. V_56 = V_57 ,
. V_58 = 0 ,
} ;
if ( F_15 ( F_63 ( V_6 -> V_13 ) ) )
return 0 ;
F_64 ( V_6 ) ;
if ( V_49 || F_65 ( V_6 ) <= F_66 ( V_9 ) -> V_59 )
F_67 ( V_44 , V_60 ) ;
V_42 = F_68 ( V_6 -> V_18 , V_47 , V_48 ) ;
F_69 ( V_44 , V_60 ) ;
if ( V_42 ) {
F_70 ( V_6 , V_33 , V_49 , V_42 ) ;
return V_42 ;
}
if ( ! V_49 ) {
F_61 ( V_6 , NULL ) ;
goto V_61;
}
if ( ! F_71 ( V_44 , V_62 ) &&
! F_72 ( V_9 , V_40 , V_63 ) ) {
if ( F_50 ( V_9 , V_40 ) )
goto V_61;
if ( F_71 ( V_44 , V_64 ) ||
F_72 ( V_9 , V_40 , V_65 ) )
goto V_66;
goto V_15;
}
V_61:
F_73 ( & V_44 -> V_45 ) ;
V_33 = F_40 ( V_6 ) ;
F_74 ( & V_44 -> V_45 ) ;
if ( V_33 ) {
V_42 = F_75 ( V_6 -> V_13 , 1 ) ;
F_56 ( V_6 ) ;
F_69 ( V_44 , V_62 ) ;
F_69 ( V_44 , V_64 ) ;
goto V_15;
}
V_67:
F_76 ( V_9 , V_40 , & V_53 ) ;
if ( F_15 ( F_77 ( V_9 ) ) ) {
V_42 = - V_68 ;
goto V_15;
}
if ( F_54 ( V_9 , V_40 ) ) {
F_60 ( V_6 ) ;
F_61 ( V_6 , NULL ) ;
goto V_67;
}
V_42 = F_78 ( V_9 , V_40 ) ;
if ( V_42 )
goto V_15;
F_79 ( V_9 , V_40 , V_63 ) ;
F_69 ( V_44 , V_62 ) ;
V_66:
F_79 ( V_9 , V_40 , V_65 ) ;
F_69 ( V_44 , V_64 ) ;
V_42 = F_80 ( V_9 ) ;
F_31 ( V_9 , V_29 ) ;
V_15:
F_70 ( V_6 , V_33 , V_49 , V_42 ) ;
F_81 ( NULL , 1 ) ;
return V_42 ;
}
static T_2 F_82 ( struct V_69 * V_17 ,
T_2 V_70 , int V_71 )
{
struct V_72 V_73 ;
int V_74 ;
if ( V_71 != V_75 )
return 0 ;
F_83 ( & V_73 , 0 ) ;
V_74 = F_84 ( & V_73 , V_17 , & V_70 ,
V_76 , 1 ) ;
V_70 = V_74 ? V_73 . V_77 [ 0 ] -> V_14 : V_78 ;
F_85 ( & V_73 ) ;
return V_70 ;
}
static bool F_86 ( T_3 V_79 , T_2 V_80 , T_2 V_70 ,
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
static V_21 F_87 ( struct V_46 * V_46 , V_21 V_23 , int V_71 )
{
struct V_6 * V_6 = V_46 -> V_50 -> V_51 ;
V_21 V_84 = V_6 -> V_13 -> V_85 ;
struct V_10 V_11 ;
T_2 V_70 , V_86 , V_80 ;
V_21 V_87 = V_23 ;
V_21 V_88 ;
int V_12 = 0 ;
F_88 ( V_6 ) ;
V_88 = F_17 ( V_6 ) ;
if ( V_23 >= V_88 )
goto V_89;
if ( F_6 ( V_6 ) || F_89 ( V_6 ) ) {
if ( V_71 == V_83 )
V_87 = V_88 ;
goto V_90;
}
V_70 = ( T_2 ) ( V_23 >> V_22 ) ;
V_80 = F_82 ( V_6 -> V_18 , V_70 , V_71 ) ;
for (; V_87 < V_88 ; V_87 = ( V_21 ) V_70 << V_22 ) {
F_8 ( & V_11 , V_6 , NULL , NULL , 0 ) ;
V_12 = F_90 ( & V_11 , V_70 , V_91 ) ;
if ( V_12 && V_12 != - V_92 ) {
goto V_89;
} else if ( V_12 == - V_92 ) {
if ( V_71 == V_75 ) {
V_70 = F_91 ( & V_11 , V_70 ) ;
continue;
} else {
goto V_90;
}
}
V_86 = F_92 ( V_11 . V_93 , V_6 ) ;
for (; V_11 . V_94 < V_86 ;
V_11 . V_94 ++ , V_70 ++ ,
V_87 = ( V_21 ) V_70 << V_22 ) {
T_3 V_79 ;
V_79 = F_93 ( V_11 . V_93 , V_11 . V_94 ) ;
if ( F_86 ( V_79 , V_80 , V_70 , V_71 ) ) {
F_11 ( & V_11 ) ;
goto V_90;
}
}
F_11 ( & V_11 ) ;
}
if ( V_71 == V_75 )
goto V_89;
V_90:
if ( V_71 == V_83 && V_87 > V_88 )
V_87 = V_88 ;
F_94 ( V_6 ) ;
return F_95 ( V_46 , V_87 , V_84 ) ;
V_89:
F_94 ( V_6 ) ;
return - V_95 ;
}
static V_21 F_96 ( struct V_46 * V_46 , V_21 V_23 , int V_71 )
{
struct V_6 * V_6 = V_46 -> V_50 -> V_51 ;
V_21 V_84 = V_6 -> V_13 -> V_85 ;
switch ( V_71 ) {
case V_96 :
case V_97 :
case V_98 :
return F_97 ( V_46 , V_23 , V_71 ,
V_84 , F_17 ( V_6 ) ) ;
case V_75 :
case V_83 :
if ( V_23 < 0 )
return - V_95 ;
return F_87 ( V_46 , V_23 , V_71 ) ;
}
return - V_99 ;
}
static int F_98 ( struct V_46 * V_46 , struct V_1 * V_2 )
{
struct V_6 * V_6 = F_2 ( V_46 ) ;
int V_12 ;
if ( F_26 ( V_6 ) ) {
V_12 = F_99 ( V_6 ) ;
if ( V_12 )
return 0 ;
if ( ! F_26 ( V_6 ) )
return - V_100 ;
}
V_12 = F_100 ( V_6 ) ;
if ( V_12 )
return V_12 ;
F_101 ( V_46 ) ;
V_2 -> V_101 = & V_102 ;
return 0 ;
}
static int F_102 ( struct V_6 * V_6 , struct V_46 * V_103 )
{
int V_42 = F_103 ( V_6 , V_103 ) ;
struct V_31 * V_104 ;
if ( ! V_42 && F_26 ( V_6 ) ) {
V_42 = F_99 ( V_6 ) ;
if ( V_42 )
return - V_105 ;
if ( ! F_104 ( V_6 ) )
return - V_100 ;
}
V_104 = F_105 ( F_106 ( V_103 ) ) ;
if ( F_26 ( F_107 ( V_104 ) ) &&
! F_108 ( F_107 ( V_104 ) , V_6 ) ) {
F_38 ( V_104 ) ;
return - V_106 ;
}
F_38 ( V_104 ) ;
return V_42 ;
}
int F_109 ( struct V_10 * V_11 , int V_107 )
{
struct V_8 * V_9 = F_3 ( V_11 -> V_6 ) ;
struct V_108 * V_109 ;
int V_110 = 0 , V_111 = V_11 -> V_94 , V_112 = V_107 ;
T_4 * V_113 ;
V_109 = F_110 ( V_11 -> V_93 ) ;
V_113 = F_111 ( V_109 ) + V_111 ;
for (; V_107 > 0 ; V_107 -- , V_113 ++ , V_11 -> V_94 ++ ) {
T_3 V_79 = F_112 ( * V_113 ) ;
if ( V_79 == V_82 )
continue;
V_11 -> V_28 = V_82 ;
F_113 ( V_11 ) ;
F_114 ( V_9 , V_79 ) ;
if ( V_11 -> V_94 == 0 && F_115 ( V_11 -> V_93 ) )
F_69 ( F_46 ( V_11 -> V_6 ) ,
V_114 ) ;
V_110 ++ ;
}
if ( V_110 ) {
T_2 V_115 ;
V_115 = F_116 ( F_117 ( V_11 -> V_93 ) ,
V_11 -> V_6 ) + V_111 ;
F_118 ( V_11 , V_115 , 0 , V_112 ) ;
F_119 ( V_9 , V_11 -> V_6 , V_110 ) ;
F_120 ( V_11 ) ;
}
V_11 -> V_94 = V_111 ;
F_31 ( V_9 , V_29 ) ;
F_121 ( V_11 -> V_6 , V_11 -> V_116 ,
V_11 -> V_94 , V_110 ) ;
return V_110 ;
}
void F_122 ( struct V_10 * V_11 )
{
F_109 ( V_11 , V_117 ) ;
}
static int F_123 ( struct V_6 * V_6 , T_5 V_118 ,
bool V_119 )
{
unsigned V_23 = V_118 & ( V_25 - 1 ) ;
T_2 V_14 = V_118 >> V_22 ;
struct V_69 * V_17 = V_6 -> V_18 ;
struct V_5 * V_5 ;
if ( ! V_23 && ! V_119 )
return 0 ;
if ( V_119 ) {
V_5 = F_124 ( V_17 , V_14 , false ) ;
if ( V_5 && F_18 ( V_5 ) )
goto V_120;
F_55 ( V_5 , 1 ) ;
return 0 ;
}
V_5 = F_125 ( V_6 , V_14 , true ) ;
if ( F_126 ( V_5 ) )
return 0 ;
V_120:
F_25 ( V_5 , V_26 , true ) ;
F_127 ( V_5 , V_23 , V_25 - V_23 ) ;
if ( ! V_119 || ! F_26 ( V_6 ) ||
! F_27 ( V_6 -> V_27 ) )
F_22 ( V_5 ) ;
F_55 ( V_5 , 1 ) ;
return 0 ;
}
int F_128 ( struct V_6 * V_6 , T_5 V_118 , bool V_121 )
{
struct V_8 * V_9 = F_3 ( V_6 ) ;
unsigned int V_122 = V_6 -> V_13 -> V_123 ;
struct V_10 V_11 ;
T_2 V_124 ;
int V_107 = 0 , V_12 = 0 ;
struct V_5 * V_125 ;
bool V_126 = false ;
F_129 ( V_6 , V_118 ) ;
V_124 = ( T_2 ) F_130 ( V_118 + V_122 - 1 ) ;
if ( V_121 )
F_7 ( V_9 ) ;
V_125 = F_131 ( V_9 , V_6 -> V_35 ) ;
if ( F_126 ( V_125 ) ) {
V_12 = F_132 ( V_125 ) ;
goto V_15;
}
if ( F_6 ( V_6 ) ) {
if ( F_133 ( V_125 , V_118 ) )
F_22 ( V_125 ) ;
F_55 ( V_125 , 1 ) ;
V_126 = true ;
goto V_15;
}
F_8 ( & V_11 , V_6 , V_125 , NULL , 0 ) ;
V_12 = F_90 ( & V_11 , V_124 , V_127 ) ;
if ( V_12 ) {
if ( V_12 == - V_92 )
goto V_128;
goto V_15;
}
V_107 = F_92 ( V_11 . V_93 , V_6 ) ;
V_107 -= V_11 . V_94 ;
F_5 ( V_9 , V_107 < 0 ) ;
if ( V_11 . V_94 || F_115 ( V_11 . V_93 ) ) {
F_109 ( & V_11 , V_107 ) ;
V_124 += V_107 ;
}
F_11 ( & V_11 ) ;
V_128:
V_12 = F_134 ( V_6 , V_124 ) ;
V_15:
if ( V_121 )
F_10 ( V_9 ) ;
if ( ! V_12 )
V_12 = F_123 ( V_6 , V_118 , V_126 ) ;
F_135 ( V_6 , V_12 ) ;
return V_12 ;
}
int F_136 ( struct V_6 * V_6 , bool V_121 )
{
int V_12 ;
if ( ! ( F_27 ( V_6 -> V_27 ) || F_137 ( V_6 -> V_27 ) ||
F_138 ( V_6 -> V_27 ) ) )
return 0 ;
F_139 ( V_6 ) ;
if ( ! F_140 ( V_6 ) ) {
V_12 = F_100 ( V_6 ) ;
if ( V_12 )
return V_12 ;
}
V_12 = F_128 ( V_6 , F_17 ( V_6 ) , V_121 ) ;
if ( V_12 )
return V_12 ;
V_6 -> V_129 = V_6 -> V_130 = V_131 ;
F_141 ( V_6 ) ;
return 0 ;
}
int F_142 ( struct V_132 * V_133 ,
struct V_31 * V_31 , struct V_134 * V_135 )
{
struct V_6 * V_6 = F_107 ( V_31 ) ;
F_143 ( V_6 , V_135 ) ;
V_135 -> V_136 <<= 3 ;
return 0 ;
}
static void F_144 ( struct V_6 * V_6 , const struct V_137 * V_138 )
{
struct V_43 * V_44 = F_46 ( V_6 ) ;
unsigned int V_139 = V_138 -> V_139 ;
if ( V_139 & V_140 )
V_6 -> V_141 = V_138 -> V_142 ;
if ( V_139 & V_143 )
V_6 -> V_144 = V_138 -> V_145 ;
if ( V_139 & V_146 )
V_6 -> V_147 = F_145 ( V_138 -> V_148 ,
V_6 -> V_13 -> V_149 ) ;
if ( V_139 & V_150 )
V_6 -> V_129 = F_145 ( V_138 -> V_151 ,
V_6 -> V_13 -> V_149 ) ;
if ( V_139 & V_152 )
V_6 -> V_130 = F_145 ( V_138 -> V_153 ,
V_6 -> V_13 -> V_149 ) ;
if ( V_139 & V_154 ) {
T_6 V_155 = V_138 -> V_156 ;
if ( ! F_146 ( V_6 -> V_144 ) && ! F_147 ( V_157 ) )
V_155 &= ~ V_158 ;
F_148 ( V_44 , V_155 ) ;
}
}
int F_149 ( struct V_31 * V_31 , struct V_137 * V_138 )
{
struct V_6 * V_6 = F_107 ( V_31 ) ;
struct V_43 * V_44 = F_46 ( V_6 ) ;
int V_12 ;
V_12 = F_150 ( V_6 , V_138 ) ;
if ( V_12 )
return V_12 ;
if ( V_138 -> V_139 & V_159 ) {
if ( F_26 ( V_6 ) &&
F_99 ( V_6 ) )
return - V_105 ;
if ( V_138 -> V_160 <= F_17 ( V_6 ) ) {
F_151 ( V_6 , V_138 -> V_160 ) ;
V_12 = F_136 ( V_6 , true ) ;
if ( V_12 )
return V_12 ;
F_12 ( F_3 ( V_6 ) , true ) ;
} else {
F_151 ( V_6 , V_138 -> V_160 ) ;
if ( ! F_140 ( V_6 ) ) {
V_12 = F_100 ( V_6 ) ;
if ( V_12 )
return V_12 ;
}
V_6 -> V_129 = V_6 -> V_130 = V_131 ;
}
}
F_144 ( V_6 , V_138 ) ;
if ( V_138 -> V_139 & V_154 ) {
V_12 = F_152 ( V_6 , F_153 ( V_6 ) ) ;
if ( V_12 || F_71 ( V_44 , V_161 ) ) {
V_6 -> V_27 = V_44 -> V_162 ;
F_69 ( V_44 , V_161 ) ;
}
}
F_141 ( V_6 ) ;
return V_12 ;
}
static int F_154 ( struct V_6 * V_6 , T_2 V_14 ,
V_21 V_47 , V_21 V_112 )
{
struct V_8 * V_9 = F_3 ( V_6 ) ;
struct V_5 * V_5 ;
if ( ! V_112 )
return 0 ;
F_12 ( V_9 , true ) ;
F_7 ( V_9 ) ;
V_5 = F_155 ( V_6 , NULL , V_14 , false ) ;
F_10 ( V_9 ) ;
if ( F_126 ( V_5 ) )
return F_132 ( V_5 ) ;
F_25 ( V_5 , V_26 , true ) ;
F_127 ( V_5 , V_47 , V_112 ) ;
F_22 ( V_5 ) ;
F_55 ( V_5 , 1 ) ;
return 0 ;
}
int F_156 ( struct V_6 * V_6 , T_2 V_163 , T_2 V_164 )
{
int V_12 ;
while ( V_163 < V_164 ) {
struct V_10 V_11 ;
T_2 V_86 , V_107 ;
F_8 ( & V_11 , V_6 , NULL , NULL , 0 ) ;
V_12 = F_90 ( & V_11 , V_163 , V_127 ) ;
if ( V_12 ) {
if ( V_12 == - V_92 ) {
V_163 ++ ;
continue;
}
return V_12 ;
}
V_86 = F_92 ( V_11 . V_93 , V_6 ) ;
V_107 = F_157 ( V_86 - V_11 . V_94 , V_164 - V_163 ) ;
F_5 ( F_3 ( V_6 ) , V_107 == 0 || V_107 > V_86 ) ;
F_109 ( & V_11 , V_107 ) ;
F_11 ( & V_11 ) ;
V_163 += V_107 ;
}
return 0 ;
}
static int F_158 ( struct V_6 * V_6 , V_21 V_23 , V_21 V_112 )
{
T_2 V_163 , V_164 ;
V_21 V_165 , V_166 ;
int V_42 ;
V_42 = F_100 ( V_6 ) ;
if ( V_42 )
return V_42 ;
V_163 = ( ( unsigned long long ) V_23 ) >> V_22 ;
V_164 = ( ( unsigned long long ) V_23 + V_112 ) >> V_22 ;
V_165 = V_23 & ( V_25 - 1 ) ;
V_166 = ( V_23 + V_112 ) & ( V_25 - 1 ) ;
if ( V_163 == V_164 ) {
V_42 = F_154 ( V_6 , V_163 , V_165 ,
V_166 - V_165 ) ;
if ( V_42 )
return V_42 ;
} else {
if ( V_165 ) {
V_42 = F_154 ( V_6 , V_163 ++ , V_165 ,
V_25 - V_165 ) ;
if ( V_42 )
return V_42 ;
}
if ( V_166 ) {
V_42 = F_154 ( V_6 , V_164 , 0 , V_166 ) ;
if ( V_42 )
return V_42 ;
}
if ( V_163 < V_164 ) {
struct V_69 * V_17 = V_6 -> V_18 ;
V_21 V_167 , V_168 ;
struct V_8 * V_9 = F_3 ( V_6 ) ;
F_12 ( V_9 , true ) ;
V_167 = ( V_21 ) V_163 << V_22 ;
V_168 = ( V_21 ) V_164 << V_22 ;
F_159 ( V_17 , V_167 ,
V_168 - 1 ) ;
F_7 ( V_9 ) ;
V_42 = F_156 ( V_6 , V_163 , V_164 ) ;
F_10 ( V_9 ) ;
}
}
return V_42 ;
}
static int F_160 ( struct V_6 * V_6 , T_2 V_169 ,
T_2 V_170 , bool V_171 )
{
struct V_8 * V_9 = F_3 ( V_6 ) ;
struct V_10 V_11 ;
T_3 V_172 ;
bool V_173 = false ;
int V_42 ;
F_8 ( & V_11 , V_6 , NULL , NULL , 0 ) ;
V_42 = F_90 ( & V_11 , V_169 , V_91 ) ;
if ( V_42 && V_42 != - V_92 ) {
return V_42 ;
} else if ( V_42 == - V_92 ) {
V_172 = V_82 ;
} else {
V_172 = V_11 . V_28 ;
if ( ! F_161 ( V_9 , V_172 ) ) {
F_162 ( & V_11 , V_82 ) ;
V_173 = true ;
}
F_11 ( & V_11 ) ;
}
if ( V_172 == V_82 )
return V_171 ? F_156 ( V_6 , V_170 , V_170 + 1 ) : 0 ;
if ( V_173 ) {
struct V_5 * V_125 = F_131 ( V_9 , V_6 -> V_35 ) ;
struct V_174 V_175 ;
if ( F_126 ( V_125 ) ) {
V_42 = F_132 ( V_125 ) ;
goto V_176;
}
F_8 ( & V_11 , V_6 , V_125 , NULL , 0 ) ;
V_42 = F_9 ( & V_11 , V_170 ) ;
if ( V_42 )
goto V_176;
F_109 ( & V_11 , 1 ) ;
F_163 ( V_9 , V_11 . V_116 , & V_175 ) ;
F_164 ( V_9 , & V_11 , V_11 . V_28 , V_172 ,
V_175 . V_177 , true , false ) ;
F_11 ( & V_11 ) ;
} else {
struct V_5 * V_178 , * V_179 ;
V_178 = F_125 ( V_6 , V_169 , true ) ;
if ( F_126 ( V_178 ) )
return F_132 ( V_178 ) ;
V_179 = F_155 ( V_6 , NULL , V_170 , true ) ;
if ( F_126 ( V_179 ) ) {
F_55 ( V_178 , 1 ) ;
return F_132 ( V_179 ) ;
}
F_165 ( V_178 , V_179 ) ;
F_22 ( V_179 ) ;
F_55 ( V_179 , 1 ) ;
F_55 ( V_178 , 1 ) ;
return F_156 ( V_6 , V_169 , V_169 + 1 ) ;
}
return 0 ;
V_176:
if ( ! F_90 ( & V_11 , V_169 , V_127 ) ) {
F_162 ( & V_11 , V_172 ) ;
F_11 ( & V_11 ) ;
}
return V_42 ;
}
static int F_166 ( struct V_6 * V_6 , T_2 V_47 , T_2 V_48 )
{
struct V_8 * V_9 = F_3 ( V_6 ) ;
T_2 V_180 = ( F_17 ( V_6 ) + V_25 - 1 ) / V_25 ;
int V_42 = 0 ;
for (; V_48 < V_180 ; V_47 ++ , V_48 ++ ) {
F_12 ( V_9 , true ) ;
F_7 ( V_9 ) ;
V_42 = F_160 ( V_6 , V_48 , V_47 , true ) ;
F_10 ( V_9 ) ;
if ( V_42 )
break;
}
return V_42 ;
}
static int F_167 ( struct V_6 * V_6 , V_21 V_23 , V_21 V_112 )
{
T_2 V_163 , V_164 ;
V_21 V_181 ;
int V_42 ;
if ( V_23 + V_112 >= F_17 ( V_6 ) )
return - V_99 ;
if ( V_23 & ( V_182 - 1 ) || V_112 & ( V_182 - 1 ) )
return - V_99 ;
V_42 = F_100 ( V_6 ) ;
if ( V_42 )
return V_42 ;
V_163 = V_23 >> V_22 ;
V_164 = ( V_23 + V_112 ) >> V_22 ;
V_42 = F_68 ( V_6 -> V_18 , V_23 , V_183 ) ;
if ( V_42 )
return V_42 ;
F_168 ( V_6 , V_23 ) ;
V_42 = F_166 ( V_6 , V_163 , V_164 ) ;
if ( V_42 )
return V_42 ;
F_68 ( V_6 -> V_18 , V_23 , V_183 ) ;
F_168 ( V_6 , V_23 ) ;
V_181 = F_17 ( V_6 ) - V_112 ;
F_168 ( V_6 , V_181 ) ;
V_42 = F_128 ( V_6 , V_181 , true ) ;
if ( ! V_42 )
F_169 ( V_6 , V_181 ) ;
return V_42 ;
}
static int F_170 ( struct V_6 * V_6 , V_21 V_23 , V_21 V_112 ,
int V_155 )
{
struct V_8 * V_9 = F_3 ( V_6 ) ;
struct V_69 * V_17 = V_6 -> V_18 ;
T_2 V_14 , V_163 , V_164 ;
V_21 V_181 = F_17 ( V_6 ) ;
V_21 V_165 , V_166 ;
int V_42 = 0 ;
V_42 = F_171 ( V_6 , ( V_112 + V_23 ) ) ;
if ( V_42 )
return V_42 ;
V_42 = F_100 ( V_6 ) ;
if ( V_42 )
return V_42 ;
V_42 = F_68 ( V_17 , V_23 , V_23 + V_112 - 1 ) ;
if ( V_42 )
return V_42 ;
F_172 ( V_6 , V_23 , V_23 + V_112 - 1 ) ;
V_163 = ( ( unsigned long long ) V_23 ) >> V_22 ;
V_164 = ( ( unsigned long long ) V_23 + V_112 ) >> V_22 ;
V_165 = V_23 & ( V_25 - 1 ) ;
V_166 = ( V_23 + V_112 ) & ( V_25 - 1 ) ;
if ( V_163 == V_164 ) {
V_42 = F_154 ( V_6 , V_163 , V_165 ,
V_166 - V_165 ) ;
if ( V_42 )
return V_42 ;
if ( V_23 + V_112 > V_181 )
V_181 = V_23 + V_112 ;
V_181 = F_173 ( V_21 , V_181 , V_23 + V_112 ) ;
} else {
if ( V_165 ) {
V_42 = F_154 ( V_6 , V_163 ++ , V_165 ,
V_25 - V_165 ) ;
if ( V_42 )
return V_42 ;
V_181 = F_173 ( V_21 , V_181 ,
( V_21 ) V_163 << V_22 ) ;
}
for ( V_14 = V_163 ; V_14 < V_164 ; V_14 ++ ) {
struct V_10 V_11 ;
struct V_5 * V_125 ;
F_7 ( V_9 ) ;
V_125 = F_131 ( V_9 , V_6 -> V_35 ) ;
if ( F_126 ( V_125 ) ) {
V_42 = F_132 ( V_125 ) ;
F_10 ( V_9 ) ;
goto V_15;
}
F_8 ( & V_11 , V_6 , V_125 , NULL , 0 ) ;
V_42 = F_9 ( & V_11 , V_14 ) ;
if ( V_42 ) {
F_10 ( V_9 ) ;
goto V_15;
}
if ( V_11 . V_28 != V_81 ) {
F_114 ( V_9 , V_11 . V_28 ) ;
F_162 ( & V_11 , V_81 ) ;
}
F_11 ( & V_11 ) ;
F_10 ( V_9 ) ;
V_181 = F_173 ( V_21 , V_181 ,
( V_21 ) ( V_14 + 1 ) << V_22 ) ;
}
if ( V_166 ) {
V_42 = F_154 ( V_6 , V_164 , 0 , V_166 ) ;
if ( V_42 )
goto V_15;
V_181 = F_173 ( V_21 , V_181 , V_23 + V_112 ) ;
}
}
V_15:
if ( ! ( V_155 & V_184 ) && F_17 ( V_6 ) < V_181 ) {
F_169 ( V_6 , V_181 ) ;
F_141 ( V_6 ) ;
F_174 ( V_6 ) ;
}
return V_42 ;
}
static int F_175 ( struct V_6 * V_6 , V_21 V_23 , V_21 V_112 )
{
struct V_8 * V_9 = F_3 ( V_6 ) ;
T_2 V_163 , V_164 , V_185 , V_180 , V_186 ;
V_21 V_181 ;
int V_42 = 0 ;
V_181 = F_17 ( V_6 ) + V_112 ;
if ( V_181 > V_6 -> V_13 -> V_85 )
return - V_187 ;
if ( V_23 >= F_17 ( V_6 ) )
return - V_99 ;
if ( V_23 & ( V_182 - 1 ) || V_112 & ( V_182 - 1 ) )
return - V_99 ;
V_42 = F_100 ( V_6 ) ;
if ( V_42 )
return V_42 ;
F_12 ( V_9 , true ) ;
V_42 = F_128 ( V_6 , F_17 ( V_6 ) , true ) ;
if ( V_42 )
return V_42 ;
V_42 = F_68 ( V_6 -> V_18 , V_23 , V_183 ) ;
if ( V_42 )
return V_42 ;
F_168 ( V_6 , V_23 ) ;
V_163 = V_23 >> V_22 ;
V_164 = ( V_23 + V_112 ) >> V_22 ;
V_185 = V_164 - V_163 ;
V_180 = ( F_17 ( V_6 ) + V_25 - 1 ) / V_25 ;
for ( V_186 = V_180 - 1 ; V_186 >= V_163 && V_186 != - 1 ; V_186 -- ) {
F_7 ( V_9 ) ;
V_42 = F_160 ( V_6 , V_186 , V_186 + V_185 , false ) ;
F_10 ( V_9 ) ;
if ( V_42 )
break;
}
F_68 ( V_6 -> V_18 , V_23 , V_183 ) ;
F_168 ( V_6 , V_23 ) ;
if ( ! V_42 )
F_169 ( V_6 , V_181 ) ;
return V_42 ;
}
static int F_176 ( struct V_6 * V_6 , V_21 V_23 ,
V_21 V_112 , int V_155 )
{
struct V_8 * V_9 = F_3 ( V_6 ) ;
T_2 V_14 , V_163 , V_164 ;
V_21 V_181 = F_17 ( V_6 ) ;
V_21 V_165 , V_166 ;
int V_42 = 0 ;
V_42 = F_171 ( V_6 , ( V_112 + V_23 ) ) ;
if ( V_42 )
return V_42 ;
V_42 = F_100 ( V_6 ) ;
if ( V_42 )
return V_42 ;
F_12 ( V_9 , true ) ;
V_163 = ( ( unsigned long long ) V_23 ) >> V_22 ;
V_164 = ( ( unsigned long long ) V_23 + V_112 ) >> V_22 ;
V_165 = V_23 & ( V_25 - 1 ) ;
V_166 = ( V_23 + V_112 ) & ( V_25 - 1 ) ;
F_7 ( V_9 ) ;
for ( V_14 = V_163 ; V_14 <= V_164 ; V_14 ++ ) {
struct V_10 V_11 ;
if ( V_14 == V_164 && ! V_166 )
goto V_188;
F_8 ( & V_11 , V_6 , NULL , NULL , 0 ) ;
V_42 = F_9 ( & V_11 , V_14 ) ;
if ( V_42 )
break;
V_188:
if ( V_163 == V_164 )
V_181 = V_23 + V_112 ;
else if ( V_14 == V_163 && V_165 )
V_181 = ( V_21 ) ( V_14 + 1 ) << V_22 ;
else if ( V_14 == V_164 )
V_181 = ( ( V_21 ) V_14 << V_22 ) +
V_166 ;
else
V_181 += V_25 ;
}
if ( ! ( V_155 & V_184 ) &&
F_17 ( V_6 ) < V_181 ) {
F_169 ( V_6 , V_181 ) ;
F_141 ( V_6 ) ;
F_174 ( V_6 ) ;
}
F_10 ( V_9 ) ;
return V_42 ;
}
static long F_177 ( struct V_46 * V_46 , int V_155 ,
V_21 V_23 , V_21 V_112 )
{
struct V_6 * V_6 = F_2 ( V_46 ) ;
long V_42 = 0 ;
if ( ! F_27 ( V_6 -> V_27 ) )
return - V_99 ;
if ( F_26 ( V_6 ) &&
( V_155 & ( V_189 | V_190 ) ) )
return - V_191 ;
if ( V_155 & ~ ( V_184 | V_192 |
V_189 | V_193 |
V_190 ) )
return - V_191 ;
F_88 ( V_6 ) ;
if ( V_155 & V_192 ) {
if ( V_23 >= V_6 -> V_194 )
goto V_15;
V_42 = F_158 ( V_6 , V_23 , V_112 ) ;
} else if ( V_155 & V_189 ) {
V_42 = F_167 ( V_6 , V_23 , V_112 ) ;
} else if ( V_155 & V_193 ) {
V_42 = F_170 ( V_6 , V_23 , V_112 , V_155 ) ;
} else if ( V_155 & V_190 ) {
V_42 = F_175 ( V_6 , V_23 , V_112 ) ;
} else {
V_42 = F_176 ( V_6 , V_23 , V_112 , V_155 ) ;
}
if ( ! V_42 ) {
V_6 -> V_129 = V_6 -> V_130 = V_131 ;
F_141 ( V_6 ) ;
F_31 ( F_3 ( V_6 ) , V_29 ) ;
}
V_15:
F_94 ( V_6 ) ;
F_178 ( V_6 , V_155 , V_23 , V_112 , V_42 ) ;
return V_42 ;
}
static int F_179 ( struct V_6 * V_6 , struct V_46 * V_103 )
{
if ( F_180 ( V_6 ) )
F_181 ( V_6 ) ;
if ( F_182 ( V_6 ) ) {
F_67 ( F_46 ( V_6 ) , V_195 ) ;
F_183 ( V_6 -> V_18 ) ;
F_69 ( F_46 ( V_6 ) , V_195 ) ;
}
return 0 ;
}
static inline T_7 F_184 ( T_6 V_155 , T_7 V_196 )
{
if ( F_137 ( V_155 ) )
return V_196 ;
else if ( F_27 ( V_155 ) )
return V_196 & V_197 ;
else
return V_196 & V_198 ;
}
static int F_185 ( struct V_46 * V_103 , unsigned long V_199 )
{
struct V_6 * V_6 = F_2 ( V_103 ) ;
struct V_43 * V_44 = F_46 ( V_6 ) ;
unsigned int V_196 = V_44 -> V_200 & V_201 ;
return F_186 ( V_196 , ( int V_202 * ) V_199 ) ;
}
static int F_187 ( struct V_46 * V_103 , unsigned long V_199 )
{
struct V_6 * V_6 = F_2 ( V_103 ) ;
struct V_43 * V_44 = F_46 ( V_6 ) ;
unsigned int V_196 = V_44 -> V_200 & V_201 ;
unsigned int V_203 ;
int V_42 ;
V_42 = F_188 ( V_103 ) ;
if ( V_42 )
return V_42 ;
if ( ! F_189 ( V_6 ) ) {
V_42 = - V_105 ;
goto V_15;
}
if ( F_190 ( V_196 , ( int V_202 * ) V_199 ) ) {
V_42 = - V_19 ;
goto V_15;
}
V_196 = F_184 ( V_6 -> V_27 , V_196 ) ;
F_88 ( V_6 ) ;
V_203 = V_44 -> V_200 ;
if ( ( V_196 ^ V_203 ) & ( V_204 | V_205 ) ) {
if ( ! F_147 ( V_206 ) ) {
F_94 ( V_6 ) ;
V_42 = - V_106 ;
goto V_15;
}
}
V_196 = V_196 & V_207 ;
V_196 |= V_203 & ~ V_207 ;
V_44 -> V_200 = V_196 ;
F_94 ( V_6 ) ;
F_191 ( V_6 ) ;
V_6 -> V_130 = V_131 ;
F_141 ( V_6 ) ;
V_15:
F_192 ( V_103 ) ;
return V_42 ;
}
static int F_193 ( struct V_46 * V_103 , unsigned long V_199 )
{
struct V_6 * V_6 = F_2 ( V_103 ) ;
return F_186 ( V_6 -> V_208 , ( int V_202 * ) V_199 ) ;
}
static int F_194 ( struct V_46 * V_103 )
{
struct V_6 * V_6 = F_2 ( V_103 ) ;
int V_42 ;
if ( ! F_189 ( V_6 ) )
return - V_105 ;
if ( F_180 ( V_6 ) )
return 0 ;
V_42 = F_100 ( V_6 ) ;
if ( V_42 )
return V_42 ;
F_67 ( F_46 ( V_6 ) , V_209 ) ;
F_31 ( F_3 ( V_6 ) , V_29 ) ;
return 0 ;
}
static int F_195 ( struct V_46 * V_103 )
{
struct V_6 * V_6 = F_2 ( V_103 ) ;
int V_42 ;
if ( ! F_189 ( V_6 ) )
return - V_105 ;
if ( F_182 ( V_6 ) )
return 0 ;
V_42 = F_188 ( V_103 ) ;
if ( V_42 )
return V_42 ;
if ( F_180 ( V_6 ) ) {
F_69 ( F_46 ( V_6 ) , V_209 ) ;
V_42 = F_196 ( V_6 ) ;
if ( V_42 ) {
F_67 ( F_46 ( V_6 ) , V_209 ) ;
goto V_176;
}
}
V_42 = F_62 ( V_103 , 0 , V_183 , 0 ) ;
V_176:
F_192 ( V_103 ) ;
return V_42 ;
}
static int F_197 ( struct V_46 * V_103 )
{
struct V_6 * V_6 = F_2 ( V_103 ) ;
int V_42 ;
if ( ! F_189 ( V_6 ) )
return - V_105 ;
if ( F_182 ( V_6 ) )
return 0 ;
V_42 = F_100 ( V_6 ) ;
if ( V_42 )
return V_42 ;
F_67 ( F_46 ( V_6 ) , V_210 ) ;
F_31 ( F_3 ( V_6 ) , V_29 ) ;
return 0 ;
}
static int F_198 ( struct V_46 * V_103 )
{
struct V_6 * V_6 = F_2 ( V_103 ) ;
if ( ! F_189 ( V_6 ) )
return - V_105 ;
if ( ! F_182 ( V_6 ) )
return 0 ;
if ( ! F_199 ( V_6 ) )
return F_123 ( V_6 , 0 , true ) ;
return F_158 ( V_6 , 0 , V_182 ) ;
}
static int F_200 ( struct V_46 * V_103 )
{
struct V_6 * V_6 = F_2 ( V_103 ) ;
int V_42 ;
if ( ! F_189 ( V_6 ) )
return - V_105 ;
V_42 = F_188 ( V_103 ) ;
if ( V_42 )
return V_42 ;
if ( F_180 ( V_6 ) ) {
F_69 ( F_46 ( V_6 ) , V_209 ) ;
F_181 ( V_6 ) ;
}
if ( F_182 ( V_6 ) ) {
F_69 ( F_46 ( V_6 ) , V_210 ) ;
V_42 = F_62 ( V_103 , 0 , V_183 , 0 ) ;
}
F_192 ( V_103 ) ;
F_31 ( F_3 ( V_6 ) , V_29 ) ;
return V_42 ;
}
static int F_201 ( struct V_46 * V_103 , unsigned long V_199 )
{
struct V_6 * V_6 = F_2 ( V_103 ) ;
struct V_8 * V_9 = F_3 ( V_6 ) ;
struct V_211 * V_212 = V_9 -> V_212 ;
T_7 V_213 ;
if ( ! F_147 ( V_214 ) )
return - V_106 ;
if ( F_190 ( V_213 , ( T_7 V_202 * ) V_199 ) )
return - V_19 ;
switch ( V_213 ) {
case V_215 :
V_212 = F_202 ( V_212 -> V_216 ) ;
if ( V_212 && ! F_126 ( V_212 ) ) {
F_203 ( V_9 ) ;
F_204 ( V_212 -> V_216 , V_212 ) ;
}
break;
case V_217 :
F_75 ( V_212 , 1 ) ;
F_203 ( V_9 ) ;
break;
case V_218 :
F_203 ( V_9 ) ;
break;
case V_219 :
F_205 ( V_9 , V_220 , V_57 ) ;
F_203 ( V_9 ) ;
break;
default:
return - V_99 ;
}
F_31 ( V_9 , V_29 ) ;
return 0 ;
}
static int F_206 ( struct V_46 * V_103 , unsigned long V_199 )
{
struct V_6 * V_6 = F_2 ( V_103 ) ;
struct V_211 * V_212 = V_6 -> V_13 ;
struct V_221 * V_222 = F_207 ( V_212 -> V_216 ) ;
struct V_223 V_224 ;
int V_42 ;
if ( ! F_147 ( V_214 ) )
return - V_106 ;
if ( ! F_208 ( V_222 ) )
return - V_191 ;
if ( F_209 ( & V_224 , (struct V_223 V_202 * ) V_199 ,
sizeof( V_224 ) ) )
return - V_19 ;
V_224 . V_225 = F_210 ( ( unsigned int ) V_224 . V_225 ,
V_222 -> V_226 . V_227 ) ;
V_42 = F_211 ( F_212 ( V_212 ) , & V_224 ) ;
if ( V_42 < 0 )
return V_42 ;
if ( F_213 ( (struct V_223 V_202 * ) V_199 , & V_224 ,
sizeof( V_224 ) ) )
return - V_19 ;
F_31 ( F_3 ( V_6 ) , V_29 ) ;
return 0 ;
}
static bool F_214 ( T_8 V_228 [ 16 ] )
{
int V_41 ;
for ( V_41 = 0 ; V_41 < 16 ; V_41 ++ )
if ( V_228 [ V_41 ] )
return true ;
return false ;
}
static int F_215 ( struct V_46 * V_103 , unsigned long V_199 )
{
struct V_229 V_230 ;
struct V_6 * V_6 = F_2 ( V_103 ) ;
if ( F_209 ( & V_230 , (struct V_229 V_202 * ) V_199 ,
sizeof( V_230 ) ) )
return - V_19 ;
F_31 ( F_3 ( V_6 ) , V_29 ) ;
return F_216 ( V_6 , & V_230 ) ;
}
static int F_217 ( struct V_46 * V_103 , unsigned long V_199 )
{
struct V_229 V_230 ;
struct V_6 * V_6 = F_2 ( V_103 ) ;
int V_12 ;
V_12 = F_218 ( V_6 , & V_230 ) ;
if ( V_12 )
return V_12 ;
if ( F_213 ( (struct V_229 V_202 * ) V_199 , & V_230 , sizeof( V_230 ) ) )
return - V_19 ;
return 0 ;
}
static int F_219 ( struct V_46 * V_103 , unsigned long V_199 )
{
struct V_6 * V_6 = F_2 ( V_103 ) ;
struct V_8 * V_9 = F_3 ( V_6 ) ;
int V_12 ;
if ( ! F_220 ( V_6 -> V_13 ) )
return - V_191 ;
if ( F_214 ( V_9 -> V_231 -> V_232 ) )
goto V_233;
V_12 = F_188 ( V_103 ) ;
if ( V_12 )
return V_12 ;
F_221 ( V_9 -> V_231 -> V_232 ) ;
V_12 = F_222 ( V_9 , false ) ;
if ( V_12 ) {
memset ( V_9 -> V_231 -> V_232 , 0 , 16 ) ;
F_192 ( V_103 ) ;
return V_12 ;
}
F_192 ( V_103 ) ;
V_233:
if ( F_213 ( ( T_8 V_202 * ) V_199 , V_9 -> V_231 -> V_232 ,
16 ) )
return - V_19 ;
return 0 ;
}
static int F_223 ( struct V_46 * V_103 , unsigned long V_199 )
{
struct V_6 * V_6 = F_2 ( V_103 ) ;
struct V_8 * V_9 = F_3 ( V_6 ) ;
T_7 V_234 ;
if ( ! F_147 ( V_214 ) )
return - V_106 ;
if ( F_190 ( V_234 , ( T_7 V_202 * ) V_199 ) )
return - V_19 ;
if ( F_63 ( V_9 -> V_212 ) )
return - V_235 ;
if ( ! V_234 ) {
if ( ! F_224 ( & V_9 -> V_236 ) )
return - V_237 ;
} else {
F_225 ( & V_9 -> V_236 ) ;
}
return F_226 ( V_9 , V_234 ) ;
}
static int F_227 ( struct V_46 * V_103 , unsigned long V_199 )
{
struct V_6 * V_6 = F_2 ( V_103 ) ;
struct V_8 * V_9 = F_3 ( V_6 ) ;
if ( ! F_147 ( V_214 ) )
return - V_106 ;
if ( F_63 ( V_9 -> V_212 ) )
return - V_235 ;
return F_75 ( V_9 -> V_212 , 1 ) ;
}
static int F_228 ( struct V_8 * V_9 ,
struct V_46 * V_103 ,
struct V_238 * V_224 )
{
struct V_6 * V_6 = F_2 ( V_103 ) ;
struct V_239 V_240 = { . V_241 = NULL } ;
struct V_242 V_243 ;
T_2 V_163 , V_164 ;
unsigned int V_244 = V_9 -> V_245 ;
unsigned int V_246 = 0 , V_247 ;
unsigned int V_248 = V_9 -> V_249 * V_244 ;
T_3 V_168 = 0 ;
bool V_250 = false ;
int V_12 ;
if ( F_229 ( V_6 ) )
return - V_99 ;
V_163 = V_224 -> V_47 >> V_22 ;
V_164 = ( V_224 -> V_47 + V_224 -> V_112 ) >> V_22 ;
F_12 ( V_9 , true ) ;
F_88 ( V_6 ) ;
V_12 = F_68 ( V_6 -> V_18 , V_224 -> V_47 ,
V_224 -> V_47 + V_224 -> V_112 - 1 ) ;
if ( V_12 )
goto V_15;
if ( F_230 ( V_6 , V_163 , & V_243 ) ) {
if ( V_243 . V_115 + V_243 . V_112 >= V_164 )
goto V_15;
}
V_240 . V_251 = V_163 ;
while ( V_240 . V_251 < V_164 ) {
V_240 . V_252 = V_164 - V_240 . V_251 ;
V_12 = V_239 ( V_6 , & V_240 , 0 , V_253 ) ;
if ( V_12 )
goto V_15;
if ( ! ( V_240 . V_254 & V_255 ) ) {
V_240 . V_251 ++ ;
continue;
}
if ( V_168 && V_168 != V_240 . V_256 ) {
V_250 = true ;
break;
}
V_168 = V_240 . V_256 + V_240 . V_252 ;
V_240 . V_251 += V_240 . V_252 ;
}
if ( ! V_250 )
goto V_15;
V_240 . V_251 = V_163 ;
V_240 . V_252 = V_164 - V_163 ;
V_247 = ( V_240 . V_252 + V_248 - 1 ) / V_248 ;
if ( F_231 ( V_9 , V_247 ) ) {
V_12 = - V_257 ;
goto V_15;
}
while ( V_240 . V_251 < V_164 ) {
T_2 V_186 ;
int V_258 = 0 ;
V_259:
V_240 . V_252 = V_164 - V_240 . V_251 ;
V_12 = V_239 ( V_6 , & V_240 , 0 , V_253 ) ;
if ( V_12 )
goto V_260;
if ( ! ( V_240 . V_254 & V_255 ) ) {
V_240 . V_251 ++ ;
continue;
}
F_67 ( F_46 ( V_6 ) , V_261 ) ;
V_186 = V_240 . V_251 ;
while ( V_186 < V_240 . V_251 + V_240 . V_252 && V_258 < V_244 ) {
struct V_5 * V_5 ;
V_5 = F_125 ( V_6 , V_186 , true ) ;
if ( F_126 ( V_5 ) ) {
V_12 = F_132 ( V_5 ) ;
goto V_260;
}
F_22 ( V_5 ) ;
F_55 ( V_5 , 1 ) ;
V_186 ++ ;
V_258 ++ ;
V_246 ++ ;
}
V_240 . V_251 = V_186 ;
if ( V_186 < V_164 && V_258 < V_244 )
goto V_259;
F_69 ( F_46 ( V_6 ) , V_261 ) ;
V_12 = F_183 ( V_6 -> V_18 ) ;
if ( V_12 )
goto V_15;
}
V_260:
F_69 ( F_46 ( V_6 ) , V_261 ) ;
V_15:
F_94 ( V_6 ) ;
if ( ! V_12 )
V_224 -> V_112 = ( T_5 ) V_246 << V_22 ;
return V_12 ;
}
static int F_232 ( struct V_46 * V_103 , unsigned long V_199 )
{
struct V_6 * V_6 = F_2 ( V_103 ) ;
struct V_8 * V_9 = F_3 ( V_6 ) ;
struct V_238 V_224 ;
int V_12 ;
if ( ! F_147 ( V_214 ) )
return - V_106 ;
if ( ! F_27 ( V_6 -> V_27 ) )
return - V_99 ;
V_12 = F_188 ( V_103 ) ;
if ( V_12 )
return V_12 ;
if ( F_63 ( V_9 -> V_212 ) ) {
V_12 = - V_235 ;
goto V_15;
}
if ( F_209 ( & V_224 , (struct V_238 V_202 * ) V_199 ,
sizeof( V_224 ) ) ) {
V_12 = - V_19 ;
goto V_15;
}
if ( V_224 . V_47 & ( V_182 - 1 ) ||
V_224 . V_112 & ( V_182 - 1 ) ) {
V_12 = - V_99 ;
goto V_15;
}
V_12 = F_228 ( V_9 , V_103 , & V_224 ) ;
F_31 ( V_9 , V_29 ) ;
if ( V_12 < 0 )
goto V_15;
if ( F_213 ( (struct V_238 V_202 * ) V_199 , & V_224 ,
sizeof( V_224 ) ) )
V_12 = - V_19 ;
V_15:
F_192 ( V_103 ) ;
return V_12 ;
}
long F_233 ( struct V_46 * V_103 , unsigned int V_262 , unsigned long V_199 )
{
switch ( V_262 ) {
case V_263 :
return F_185 ( V_103 , V_199 ) ;
case V_264 :
return F_187 ( V_103 , V_199 ) ;
case V_265 :
return F_193 ( V_103 , V_199 ) ;
case V_266 :
return F_194 ( V_103 ) ;
case V_267 :
return F_195 ( V_103 ) ;
case V_268 :
return F_197 ( V_103 ) ;
case V_269 :
return F_198 ( V_103 ) ;
case V_270 :
return F_200 ( V_103 ) ;
case V_271 :
return F_201 ( V_103 , V_199 ) ;
case V_272 :
return F_206 ( V_103 , V_199 ) ;
case V_273 :
return F_215 ( V_103 , V_199 ) ;
case V_274 :
return F_217 ( V_103 , V_199 ) ;
case V_275 :
return F_219 ( V_103 , V_199 ) ;
case V_276 :
return F_223 ( V_103 , V_199 ) ;
case V_277 :
return F_227 ( V_103 , V_199 ) ;
case V_278 :
return F_232 ( V_103 , V_199 ) ;
default:
return - V_279 ;
}
}
static T_9 F_234 ( struct V_280 * V_281 , struct V_282 * V_118 )
{
struct V_46 * V_46 = V_281 -> V_283 ;
struct V_6 * V_6 = F_2 ( V_46 ) ;
T_9 V_42 ;
if ( F_26 ( V_6 ) &&
! F_104 ( V_6 ) &&
F_99 ( V_6 ) )
return - V_105 ;
F_88 ( V_6 ) ;
V_42 = F_235 ( V_281 , V_118 ) ;
if ( V_42 > 0 ) {
V_42 = F_236 ( V_281 , V_118 ) ;
if ( ! V_42 )
V_42 = F_237 ( V_281 , V_118 ) ;
}
F_94 ( V_6 ) ;
if ( V_42 > 0 ) {
T_9 V_12 ;
V_12 = F_238 ( V_46 , V_281 -> V_284 - V_42 , V_42 ) ;
if ( V_12 < 0 )
V_42 = V_12 ;
}
return V_42 ;
}
long F_239 ( struct V_46 * V_46 , unsigned int V_262 , unsigned long V_199 )
{
switch ( V_262 ) {
case V_285 :
V_262 = V_263 ;
break;
case V_286 :
V_262 = V_264 ;
break;
case V_287 :
V_262 = V_265 ;
break;
case V_266 :
case V_267 :
case V_268 :
case V_269 :
case V_270 :
case V_271 :
case V_273 :
case V_275 :
case V_274 :
case V_276 :
case V_277 :
case V_278 :
break;
default:
return - V_288 ;
}
return F_233 ( V_46 , V_262 , ( unsigned long ) F_240 ( V_199 ) ) ;
}
