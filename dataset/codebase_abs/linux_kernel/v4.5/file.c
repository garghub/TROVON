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
F_25 ( V_5 , V_26 ) ;
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
V_70 = V_74 ? V_73 . V_77 [ 0 ] -> V_14 : V_57 ;
F_85 ( & V_73 ) ;
return V_70 ;
}
static bool F_86 ( T_3 V_78 , T_2 V_79 , T_2 V_70 ,
int V_71 )
{
switch ( V_71 ) {
case V_75 :
if ( ( V_78 == V_80 && V_79 == V_70 ) ||
( V_78 != V_80 && V_78 != V_81 ) )
return true ;
break;
case V_82 :
if ( V_78 == V_81 )
return true ;
break;
}
return false ;
}
static V_21 F_87 ( struct V_46 * V_46 , V_21 V_23 , int V_71 )
{
struct V_6 * V_6 = V_46 -> V_50 -> V_51 ;
V_21 V_83 = V_6 -> V_13 -> V_84 ;
struct V_10 V_11 ;
T_2 V_70 , V_85 , V_79 ;
V_21 V_86 = V_23 ;
V_21 V_87 ;
int V_12 = 0 ;
F_88 ( V_6 ) ;
V_87 = F_17 ( V_6 ) ;
if ( V_23 >= V_87 )
goto V_88;
if ( F_6 ( V_6 ) || F_89 ( V_6 ) ) {
if ( V_71 == V_82 )
V_86 = V_87 ;
goto V_89;
}
V_70 = ( T_2 ) ( V_23 >> V_22 ) ;
V_79 = F_82 ( V_6 -> V_18 , V_70 , V_71 ) ;
for (; V_86 < V_87 ; V_86 = ( V_21 ) V_70 << V_22 ) {
F_8 ( & V_11 , V_6 , NULL , NULL , 0 ) ;
V_12 = F_90 ( & V_11 , V_70 , V_90 ) ;
if ( V_12 && V_12 != - V_91 ) {
goto V_88;
} else if ( V_12 == - V_91 ) {
if ( V_71 == V_75 ) {
V_70 = F_91 ( V_70 ,
F_46 ( V_6 ) ) ;
continue;
} else {
goto V_89;
}
}
V_85 = F_92 ( V_11 . V_92 , F_46 ( V_6 ) ) ;
for (; V_11 . V_93 < V_85 ;
V_11 . V_93 ++ , V_70 ++ ,
V_86 = ( V_21 ) V_70 << V_22 ) {
T_3 V_78 ;
V_78 = F_93 ( V_11 . V_92 , V_11 . V_93 ) ;
if ( F_86 ( V_78 , V_79 , V_70 , V_71 ) ) {
F_11 ( & V_11 ) ;
goto V_89;
}
}
F_11 ( & V_11 ) ;
}
if ( V_71 == V_75 )
goto V_88;
V_89:
if ( V_71 == V_82 && V_86 > V_87 )
V_86 = V_87 ;
F_94 ( V_6 ) ;
return F_95 ( V_46 , V_86 , V_83 ) ;
V_88:
F_94 ( V_6 ) ;
return - V_94 ;
}
static V_21 F_96 ( struct V_46 * V_46 , V_21 V_23 , int V_71 )
{
struct V_6 * V_6 = V_46 -> V_50 -> V_51 ;
V_21 V_83 = V_6 -> V_13 -> V_84 ;
switch ( V_71 ) {
case V_95 :
case V_96 :
case V_97 :
return F_97 ( V_46 , V_23 , V_71 ,
V_83 , F_17 ( V_6 ) ) ;
case V_75 :
case V_82 :
if ( V_23 < 0 )
return - V_94 ;
return F_87 ( V_46 , V_23 , V_71 ) ;
}
return - V_98 ;
}
static int F_98 ( struct V_46 * V_46 , struct V_1 * V_2 )
{
struct V_6 * V_6 = F_2 ( V_46 ) ;
int V_12 ;
if ( F_26 ( V_6 ) ) {
V_12 = F_99 ( V_6 ) ;
if ( V_12 )
return 0 ;
}
V_12 = F_100 ( V_6 ) ;
if ( V_12 )
return V_12 ;
F_101 ( V_46 ) ;
V_2 -> V_99 = & V_100 ;
return 0 ;
}
static int F_102 ( struct V_6 * V_6 , struct V_46 * V_101 )
{
int V_42 = F_103 ( V_6 , V_101 ) ;
if ( ! V_42 && F_26 ( V_6 ) ) {
V_42 = F_99 ( V_6 ) ;
if ( V_42 )
V_42 = - V_102 ;
}
return V_42 ;
}
int F_104 ( struct V_10 * V_11 , int V_103 )
{
struct V_8 * V_9 = F_3 ( V_11 -> V_6 ) ;
struct V_104 * V_105 ;
int V_106 = 0 , V_107 = V_11 -> V_93 , V_108 = V_103 ;
T_4 * V_109 ;
V_105 = F_105 ( V_11 -> V_92 ) ;
V_109 = F_106 ( V_105 ) + V_107 ;
for (; V_103 > 0 ; V_103 -- , V_109 ++ , V_11 -> V_93 ++ ) {
T_3 V_78 = F_107 ( * V_109 ) ;
if ( V_78 == V_81 )
continue;
V_11 -> V_28 = V_81 ;
F_108 ( V_11 ) ;
F_109 ( V_9 , V_78 ) ;
if ( V_11 -> V_93 == 0 && F_110 ( V_11 -> V_92 ) )
F_69 ( F_46 ( V_11 -> V_6 ) ,
V_110 ) ;
V_106 ++ ;
}
if ( V_106 ) {
T_2 V_111 ;
V_111 = F_111 ( F_112 ( V_11 -> V_92 ) ,
F_46 ( V_11 -> V_6 ) ) + V_107 ;
F_113 ( V_11 , V_111 , 0 , V_108 ) ;
F_114 ( V_9 , V_11 -> V_6 , V_106 ) ;
F_115 ( V_11 ) ;
}
V_11 -> V_93 = V_107 ;
F_31 ( V_9 , V_29 ) ;
F_116 ( V_11 -> V_6 , V_11 -> V_112 ,
V_11 -> V_93 , V_106 ) ;
return V_106 ;
}
void F_117 ( struct V_10 * V_11 )
{
F_104 ( V_11 , V_113 ) ;
}
static int F_118 ( struct V_6 * V_6 , T_5 V_114 ,
bool V_115 )
{
unsigned V_23 = V_114 & ( V_25 - 1 ) ;
T_2 V_14 = V_114 >> V_22 ;
struct V_69 * V_17 = V_6 -> V_18 ;
struct V_5 * V_5 ;
if ( ! V_23 && ! V_115 )
return 0 ;
if ( V_115 ) {
V_5 = F_119 ( V_17 , V_14 , false ) ;
if ( V_5 && F_18 ( V_5 ) )
goto V_116;
F_55 ( V_5 , 1 ) ;
return 0 ;
}
V_5 = F_120 ( V_6 , V_14 , true ) ;
if ( F_121 ( V_5 ) )
return 0 ;
V_116:
F_25 ( V_5 , V_26 ) ;
F_122 ( V_5 , V_23 , V_25 - V_23 ) ;
if ( ! V_115 || ! F_26 ( V_6 ) || ! F_27 ( V_6 -> V_27 ) )
F_22 ( V_5 ) ;
F_55 ( V_5 , 1 ) ;
return 0 ;
}
int F_123 ( struct V_6 * V_6 , T_5 V_114 , bool V_117 )
{
struct V_8 * V_9 = F_3 ( V_6 ) ;
unsigned int V_118 = V_6 -> V_13 -> V_119 ;
struct V_10 V_11 ;
T_2 V_120 ;
int V_103 = 0 , V_12 = 0 ;
struct V_5 * V_121 ;
bool V_122 = false ;
F_124 ( V_6 , V_114 ) ;
V_120 = ( T_2 ) F_125 ( V_114 + V_118 - 1 ) ;
if ( V_117 )
F_7 ( V_9 ) ;
V_121 = F_126 ( V_9 , V_6 -> V_35 ) ;
if ( F_121 ( V_121 ) ) {
V_12 = F_127 ( V_121 ) ;
goto V_15;
}
if ( F_6 ( V_6 ) ) {
if ( F_128 ( V_121 , V_114 ) )
F_22 ( V_121 ) ;
F_55 ( V_121 , 1 ) ;
V_122 = true ;
goto V_15;
}
F_8 ( & V_11 , V_6 , V_121 , NULL , 0 ) ;
V_12 = F_90 ( & V_11 , V_120 , V_123 ) ;
if ( V_12 ) {
if ( V_12 == - V_91 )
goto V_124;
goto V_15;
}
V_103 = F_92 ( V_11 . V_92 , F_46 ( V_6 ) ) ;
V_103 -= V_11 . V_93 ;
F_5 ( V_9 , V_103 < 0 ) ;
if ( V_11 . V_93 || F_110 ( V_11 . V_92 ) ) {
F_104 ( & V_11 , V_103 ) ;
V_120 += V_103 ;
}
F_11 ( & V_11 ) ;
V_124:
V_12 = F_129 ( V_6 , V_120 ) ;
V_15:
if ( V_117 )
F_10 ( V_9 ) ;
if ( ! V_12 )
V_12 = F_118 ( V_6 , V_114 , V_122 ) ;
F_130 ( V_6 , V_12 ) ;
return V_12 ;
}
int F_131 ( struct V_6 * V_6 , bool V_117 )
{
int V_12 ;
if ( ! ( F_27 ( V_6 -> V_27 ) || F_132 ( V_6 -> V_27 ) ||
F_133 ( V_6 -> V_27 ) ) )
return 0 ;
F_134 ( V_6 ) ;
if ( ! F_135 ( V_6 ) ) {
V_12 = F_100 ( V_6 ) ;
if ( V_12 )
return V_12 ;
}
V_12 = F_123 ( V_6 , F_17 ( V_6 ) , V_117 ) ;
if ( V_12 )
return V_12 ;
V_6 -> V_125 = V_6 -> V_126 = V_127 ;
F_136 ( V_6 ) ;
return 0 ;
}
int F_137 ( struct V_128 * V_129 ,
struct V_31 * V_31 , struct V_130 * V_131 )
{
struct V_6 * V_6 = F_138 ( V_31 ) ;
F_139 ( V_6 , V_131 ) ;
V_131 -> V_132 <<= 3 ;
return 0 ;
}
static void F_140 ( struct V_6 * V_6 , const struct V_133 * V_134 )
{
struct V_43 * V_44 = F_46 ( V_6 ) ;
unsigned int V_135 = V_134 -> V_135 ;
if ( V_135 & V_136 )
V_6 -> V_137 = V_134 -> V_138 ;
if ( V_135 & V_139 )
V_6 -> V_140 = V_134 -> V_141 ;
if ( V_135 & V_142 )
V_6 -> V_143 = F_141 ( V_134 -> V_144 ,
V_6 -> V_13 -> V_145 ) ;
if ( V_135 & V_146 )
V_6 -> V_125 = F_141 ( V_134 -> V_147 ,
V_6 -> V_13 -> V_145 ) ;
if ( V_135 & V_148 )
V_6 -> V_126 = F_141 ( V_134 -> V_149 ,
V_6 -> V_13 -> V_145 ) ;
if ( V_135 & V_150 ) {
T_6 V_151 = V_134 -> V_152 ;
if ( ! F_142 ( V_6 -> V_140 ) && ! F_143 ( V_153 ) )
V_151 &= ~ V_154 ;
F_144 ( V_44 , V_151 ) ;
}
}
int F_145 ( struct V_31 * V_31 , struct V_133 * V_134 )
{
struct V_6 * V_6 = F_138 ( V_31 ) ;
struct V_43 * V_44 = F_46 ( V_6 ) ;
int V_12 ;
V_12 = F_146 ( V_6 , V_134 ) ;
if ( V_12 )
return V_12 ;
if ( V_134 -> V_135 & V_155 ) {
if ( F_26 ( V_6 ) &&
F_99 ( V_6 ) )
return - V_102 ;
if ( V_134 -> V_156 <= F_17 ( V_6 ) ) {
F_147 ( V_6 , V_134 -> V_156 ) ;
V_12 = F_131 ( V_6 , true ) ;
if ( V_12 )
return V_12 ;
F_12 ( F_3 ( V_6 ) , true ) ;
} else {
F_147 ( V_6 , V_134 -> V_156 ) ;
if ( ! F_135 ( V_6 ) ) {
V_12 = F_100 ( V_6 ) ;
if ( V_12 )
return V_12 ;
}
V_6 -> V_125 = V_6 -> V_126 = V_127 ;
}
}
F_140 ( V_6 , V_134 ) ;
if ( V_134 -> V_135 & V_150 ) {
V_12 = F_148 ( V_6 , F_149 ( V_6 ) ) ;
if ( V_12 || F_71 ( V_44 , V_157 ) ) {
V_6 -> V_27 = V_44 -> V_158 ;
F_69 ( V_44 , V_157 ) ;
}
}
F_136 ( V_6 ) ;
return V_12 ;
}
static int F_150 ( struct V_6 * V_6 , T_2 V_14 ,
V_21 V_47 , V_21 V_108 )
{
struct V_8 * V_9 = F_3 ( V_6 ) ;
struct V_5 * V_5 ;
if ( ! V_108 )
return 0 ;
F_12 ( V_9 , true ) ;
F_7 ( V_9 ) ;
V_5 = F_151 ( V_6 , NULL , V_14 , false ) ;
F_10 ( V_9 ) ;
if ( F_121 ( V_5 ) )
return F_127 ( V_5 ) ;
F_25 ( V_5 , V_26 ) ;
F_122 ( V_5 , V_47 , V_108 ) ;
F_22 ( V_5 ) ;
F_55 ( V_5 , 1 ) ;
return 0 ;
}
int F_152 ( struct V_6 * V_6 , T_2 V_159 , T_2 V_160 )
{
int V_12 ;
while ( V_159 < V_160 ) {
struct V_10 V_11 ;
T_2 V_85 , V_103 ;
F_8 ( & V_11 , V_6 , NULL , NULL , 0 ) ;
V_12 = F_90 ( & V_11 , V_159 , V_123 ) ;
if ( V_12 ) {
if ( V_12 == - V_91 ) {
V_159 ++ ;
continue;
}
return V_12 ;
}
V_85 = F_92 ( V_11 . V_92 , F_46 ( V_6 ) ) ;
V_103 = F_153 ( V_85 - V_11 . V_93 , V_160 - V_159 ) ;
F_5 ( F_3 ( V_6 ) , V_103 == 0 || V_103 > V_85 ) ;
F_104 ( & V_11 , V_103 ) ;
F_11 ( & V_11 ) ;
V_159 += V_103 ;
}
return 0 ;
}
static int F_154 ( struct V_6 * V_6 , V_21 V_23 , V_21 V_108 )
{
T_2 V_159 , V_160 ;
V_21 V_161 , V_162 ;
int V_42 ;
V_42 = F_100 ( V_6 ) ;
if ( V_42 )
return V_42 ;
V_159 = ( ( unsigned long long ) V_23 ) >> V_22 ;
V_160 = ( ( unsigned long long ) V_23 + V_108 ) >> V_22 ;
V_161 = V_23 & ( V_25 - 1 ) ;
V_162 = ( V_23 + V_108 ) & ( V_25 - 1 ) ;
if ( V_159 == V_160 ) {
V_42 = F_150 ( V_6 , V_159 , V_161 ,
V_162 - V_161 ) ;
if ( V_42 )
return V_42 ;
} else {
if ( V_161 ) {
V_42 = F_150 ( V_6 , V_159 ++ , V_161 ,
V_25 - V_161 ) ;
if ( V_42 )
return V_42 ;
}
if ( V_162 ) {
V_42 = F_150 ( V_6 , V_160 , 0 , V_162 ) ;
if ( V_42 )
return V_42 ;
}
if ( V_159 < V_160 ) {
struct V_69 * V_17 = V_6 -> V_18 ;
V_21 V_163 , V_164 ;
struct V_8 * V_9 = F_3 ( V_6 ) ;
F_12 ( V_9 , true ) ;
V_163 = ( V_21 ) V_159 << V_22 ;
V_164 = ( V_21 ) V_160 << V_22 ;
F_155 ( V_17 , V_163 ,
V_164 - 1 ) ;
F_7 ( V_9 ) ;
V_42 = F_152 ( V_6 , V_159 , V_160 ) ;
F_10 ( V_9 ) ;
}
}
return V_42 ;
}
static int F_156 ( struct V_6 * V_6 , T_2 V_165 ,
T_2 V_166 , bool V_167 )
{
struct V_8 * V_9 = F_3 ( V_6 ) ;
struct V_10 V_11 ;
T_3 V_168 ;
bool V_169 = false ;
int V_42 ;
F_8 ( & V_11 , V_6 , NULL , NULL , 0 ) ;
V_42 = F_90 ( & V_11 , V_165 , V_90 ) ;
if ( V_42 && V_42 != - V_91 ) {
return V_42 ;
} else if ( V_42 == - V_91 ) {
V_168 = V_81 ;
} else {
V_168 = V_11 . V_28 ;
if ( ! F_157 ( V_9 , V_168 ) ) {
V_11 . V_28 = V_81 ;
F_108 ( & V_11 ) ;
F_158 ( & V_11 ) ;
V_169 = true ;
}
F_11 ( & V_11 ) ;
}
if ( V_168 == V_81 )
return V_167 ? F_152 ( V_6 , V_166 , V_166 + 1 ) : 0 ;
if ( V_169 ) {
struct V_5 * V_121 = F_126 ( V_9 , V_6 -> V_35 ) ;
struct V_170 V_171 ;
if ( F_121 ( V_121 ) ) {
V_42 = F_127 ( V_121 ) ;
goto V_172;
}
F_8 ( & V_11 , V_6 , V_121 , NULL , 0 ) ;
V_42 = F_9 ( & V_11 , V_166 ) ;
if ( V_42 )
goto V_172;
F_104 ( & V_11 , 1 ) ;
F_159 ( V_9 , V_11 . V_112 , & V_171 ) ;
F_160 ( V_9 , & V_11 , V_11 . V_28 , V_168 ,
V_171 . V_173 , true ) ;
F_11 ( & V_11 ) ;
} else {
struct V_5 * V_174 , * V_175 ;
V_174 = F_120 ( V_6 , V_165 , true ) ;
if ( F_121 ( V_174 ) )
return F_127 ( V_174 ) ;
V_175 = F_151 ( V_6 , NULL , V_166 , false ) ;
if ( F_121 ( V_175 ) ) {
F_55 ( V_174 , 1 ) ;
return F_127 ( V_175 ) ;
}
F_161 ( V_174 , V_175 ) ;
F_22 ( V_175 ) ;
F_55 ( V_175 , 1 ) ;
F_55 ( V_174 , 1 ) ;
return F_152 ( V_6 , V_165 , V_165 + 1 ) ;
}
return 0 ;
V_172:
if ( ! F_90 ( & V_11 , V_165 , V_123 ) ) {
V_11 . V_28 = V_168 ;
F_108 ( & V_11 ) ;
F_158 ( & V_11 ) ;
F_11 ( & V_11 ) ;
}
return V_42 ;
}
static int F_162 ( struct V_6 * V_6 , T_2 V_47 , T_2 V_48 )
{
struct V_8 * V_9 = F_3 ( V_6 ) ;
T_2 V_176 = ( F_17 ( V_6 ) + V_177 - 1 ) / V_177 ;
int V_42 = 0 ;
for (; V_48 < V_176 ; V_47 ++ , V_48 ++ ) {
F_12 ( V_9 , true ) ;
F_7 ( V_9 ) ;
V_42 = F_156 ( V_6 , V_48 , V_47 , true ) ;
F_10 ( V_9 ) ;
if ( V_42 )
break;
}
return V_42 ;
}
static int F_163 ( struct V_6 * V_6 , V_21 V_23 , V_21 V_108 )
{
T_2 V_159 , V_160 ;
V_21 V_178 ;
int V_42 ;
if ( V_23 + V_108 >= F_17 ( V_6 ) )
return - V_98 ;
if ( V_23 & ( V_179 - 1 ) || V_108 & ( V_179 - 1 ) )
return - V_98 ;
V_42 = F_100 ( V_6 ) ;
if ( V_42 )
return V_42 ;
V_159 = V_23 >> V_22 ;
V_160 = ( V_23 + V_108 ) >> V_22 ;
V_42 = F_68 ( V_6 -> V_18 , V_23 , V_180 ) ;
if ( V_42 )
return V_42 ;
F_164 ( V_6 , V_23 ) ;
V_42 = F_162 ( V_6 , V_159 , V_160 ) ;
if ( V_42 )
return V_42 ;
F_68 ( V_6 -> V_18 , V_23 , V_180 ) ;
F_164 ( V_6 , V_23 ) ;
V_178 = F_17 ( V_6 ) - V_108 ;
F_164 ( V_6 , V_178 ) ;
V_42 = F_123 ( V_6 , V_178 , true ) ;
if ( ! V_42 )
F_165 ( V_6 , V_178 ) ;
return V_42 ;
}
static int F_166 ( struct V_6 * V_6 , V_21 V_23 , V_21 V_108 ,
int V_151 )
{
struct V_8 * V_9 = F_3 ( V_6 ) ;
struct V_69 * V_17 = V_6 -> V_18 ;
T_2 V_14 , V_159 , V_160 ;
V_21 V_178 = F_17 ( V_6 ) ;
V_21 V_161 , V_162 ;
int V_42 = 0 ;
V_42 = F_167 ( V_6 , ( V_108 + V_23 ) ) ;
if ( V_42 )
return V_42 ;
V_42 = F_100 ( V_6 ) ;
if ( V_42 )
return V_42 ;
V_42 = F_68 ( V_17 , V_23 , V_23 + V_108 - 1 ) ;
if ( V_42 )
return V_42 ;
F_168 ( V_6 , V_23 , V_23 + V_108 - 1 ) ;
V_159 = ( ( unsigned long long ) V_23 ) >> V_22 ;
V_160 = ( ( unsigned long long ) V_23 + V_108 ) >> V_22 ;
V_161 = V_23 & ( V_25 - 1 ) ;
V_162 = ( V_23 + V_108 ) & ( V_25 - 1 ) ;
if ( V_159 == V_160 ) {
V_42 = F_150 ( V_6 , V_159 , V_161 ,
V_162 - V_161 ) ;
if ( V_42 )
return V_42 ;
if ( V_23 + V_108 > V_178 )
V_178 = V_23 + V_108 ;
V_178 = F_169 ( V_21 , V_178 , V_23 + V_108 ) ;
} else {
if ( V_161 ) {
V_42 = F_150 ( V_6 , V_159 ++ , V_161 ,
V_25 - V_161 ) ;
if ( V_42 )
return V_42 ;
V_178 = F_169 ( V_21 , V_178 ,
( V_21 ) V_159 << V_22 ) ;
}
for ( V_14 = V_159 ; V_14 < V_160 ; V_14 ++ ) {
struct V_10 V_11 ;
struct V_5 * V_121 ;
F_7 ( V_9 ) ;
V_121 = F_126 ( V_9 , V_6 -> V_35 ) ;
if ( F_121 ( V_121 ) ) {
V_42 = F_127 ( V_121 ) ;
F_10 ( V_9 ) ;
goto V_15;
}
F_8 ( & V_11 , V_6 , V_121 , NULL , 0 ) ;
V_42 = F_9 ( & V_11 , V_14 ) ;
if ( V_42 ) {
F_10 ( V_9 ) ;
goto V_15;
}
if ( V_11 . V_28 != V_80 ) {
F_109 ( V_9 , V_11 . V_28 ) ;
V_11 . V_28 = V_80 ;
F_108 ( & V_11 ) ;
V_11 . V_28 = V_81 ;
F_158 ( & V_11 ) ;
}
F_11 ( & V_11 ) ;
F_10 ( V_9 ) ;
V_178 = F_169 ( V_21 , V_178 ,
( V_21 ) ( V_14 + 1 ) << V_22 ) ;
}
if ( V_162 ) {
V_42 = F_150 ( V_6 , V_160 , 0 , V_162 ) ;
if ( V_42 )
goto V_15;
V_178 = F_169 ( V_21 , V_178 , V_23 + V_108 ) ;
}
}
V_15:
if ( ! ( V_151 & V_181 ) && F_17 ( V_6 ) < V_178 ) {
F_165 ( V_6 , V_178 ) ;
F_136 ( V_6 ) ;
F_170 ( V_6 ) ;
}
return V_42 ;
}
static int F_171 ( struct V_6 * V_6 , V_21 V_23 , V_21 V_108 )
{
struct V_8 * V_9 = F_3 ( V_6 ) ;
T_2 V_159 , V_160 , V_182 , V_176 , V_183 ;
V_21 V_178 ;
int V_42 = 0 ;
V_178 = F_17 ( V_6 ) + V_108 ;
if ( V_178 > V_6 -> V_13 -> V_84 )
return - V_184 ;
if ( V_23 >= F_17 ( V_6 ) )
return - V_98 ;
if ( V_23 & ( V_179 - 1 ) || V_108 & ( V_179 - 1 ) )
return - V_98 ;
V_42 = F_100 ( V_6 ) ;
if ( V_42 )
return V_42 ;
F_12 ( V_9 , true ) ;
V_42 = F_123 ( V_6 , F_17 ( V_6 ) , true ) ;
if ( V_42 )
return V_42 ;
V_42 = F_68 ( V_6 -> V_18 , V_23 , V_180 ) ;
if ( V_42 )
return V_42 ;
F_164 ( V_6 , V_23 ) ;
V_159 = V_23 >> V_22 ;
V_160 = ( V_23 + V_108 ) >> V_22 ;
V_182 = V_160 - V_159 ;
V_176 = ( F_17 ( V_6 ) + V_177 - 1 ) / V_177 ;
for ( V_183 = V_176 - 1 ; V_183 >= V_159 && V_183 != - 1 ; V_183 -- ) {
F_7 ( V_9 ) ;
V_42 = F_156 ( V_6 , V_183 , V_183 + V_182 , false ) ;
F_10 ( V_9 ) ;
if ( V_42 )
break;
}
F_68 ( V_6 -> V_18 , V_23 , V_180 ) ;
F_164 ( V_6 , V_23 ) ;
if ( ! V_42 )
F_165 ( V_6 , V_178 ) ;
return V_42 ;
}
static int F_172 ( struct V_6 * V_6 , V_21 V_23 ,
V_21 V_108 , int V_151 )
{
struct V_8 * V_9 = F_3 ( V_6 ) ;
T_2 V_14 , V_159 , V_160 ;
V_21 V_178 = F_17 ( V_6 ) ;
V_21 V_161 , V_162 ;
int V_42 = 0 ;
V_42 = F_167 ( V_6 , ( V_108 + V_23 ) ) ;
if ( V_42 )
return V_42 ;
V_42 = F_100 ( V_6 ) ;
if ( V_42 )
return V_42 ;
F_12 ( V_9 , true ) ;
V_159 = ( ( unsigned long long ) V_23 ) >> V_22 ;
V_160 = ( ( unsigned long long ) V_23 + V_108 ) >> V_22 ;
V_161 = V_23 & ( V_25 - 1 ) ;
V_162 = ( V_23 + V_108 ) & ( V_25 - 1 ) ;
F_7 ( V_9 ) ;
for ( V_14 = V_159 ; V_14 <= V_160 ; V_14 ++ ) {
struct V_10 V_11 ;
if ( V_14 == V_160 && ! V_162 )
goto V_185;
F_8 ( & V_11 , V_6 , NULL , NULL , 0 ) ;
V_42 = F_9 ( & V_11 , V_14 ) ;
if ( V_42 )
break;
V_185:
if ( V_159 == V_160 )
V_178 = V_23 + V_108 ;
else if ( V_14 == V_159 && V_161 )
V_178 = ( V_21 ) ( V_14 + 1 ) << V_22 ;
else if ( V_14 == V_160 )
V_178 = ( ( V_21 ) V_14 << V_22 ) +
V_162 ;
else
V_178 += V_25 ;
}
if ( ! ( V_151 & V_181 ) &&
F_17 ( V_6 ) < V_178 ) {
F_165 ( V_6 , V_178 ) ;
F_136 ( V_6 ) ;
F_170 ( V_6 ) ;
}
F_10 ( V_9 ) ;
return V_42 ;
}
static long F_173 ( struct V_46 * V_46 , int V_151 ,
V_21 V_23 , V_21 V_108 )
{
struct V_6 * V_6 = F_2 ( V_46 ) ;
long V_42 = 0 ;
if ( ! F_27 ( V_6 -> V_27 ) )
return - V_98 ;
if ( F_26 ( V_6 ) &&
( V_151 & ( V_186 | V_187 ) ) )
return - V_188 ;
if ( V_151 & ~ ( V_181 | V_189 |
V_186 | V_190 |
V_187 ) )
return - V_188 ;
F_88 ( V_6 ) ;
if ( V_151 & V_189 ) {
if ( V_23 >= V_6 -> V_191 )
goto V_15;
V_42 = F_154 ( V_6 , V_23 , V_108 ) ;
} else if ( V_151 & V_186 ) {
V_42 = F_163 ( V_6 , V_23 , V_108 ) ;
} else if ( V_151 & V_190 ) {
V_42 = F_166 ( V_6 , V_23 , V_108 , V_151 ) ;
} else if ( V_151 & V_187 ) {
V_42 = F_171 ( V_6 , V_23 , V_108 ) ;
} else {
V_42 = F_172 ( V_6 , V_23 , V_108 , V_151 ) ;
}
if ( ! V_42 ) {
V_6 -> V_125 = V_6 -> V_126 = V_127 ;
F_136 ( V_6 ) ;
F_31 ( F_3 ( V_6 ) , V_29 ) ;
}
V_15:
F_94 ( V_6 ) ;
F_174 ( V_6 , V_151 , V_23 , V_108 , V_42 ) ;
return V_42 ;
}
static int F_175 ( struct V_6 * V_6 , struct V_46 * V_101 )
{
if ( F_176 ( V_6 ) )
F_177 ( V_6 , true ) ;
if ( F_178 ( V_6 ) ) {
F_67 ( F_46 ( V_6 ) , V_192 ) ;
F_179 ( V_6 -> V_18 ) ;
F_69 ( F_46 ( V_6 ) , V_192 ) ;
}
return 0 ;
}
static inline T_7 F_180 ( T_6 V_151 , T_7 V_193 )
{
if ( F_132 ( V_151 ) )
return V_193 ;
else if ( F_27 ( V_151 ) )
return V_193 & V_194 ;
else
return V_193 & V_195 ;
}
static int F_181 ( struct V_46 * V_101 , unsigned long V_196 )
{
struct V_6 * V_6 = F_2 ( V_101 ) ;
struct V_43 * V_44 = F_46 ( V_6 ) ;
unsigned int V_193 = V_44 -> V_197 & V_198 ;
return F_182 ( V_193 , ( int V_199 * ) V_196 ) ;
}
static int F_183 ( struct V_46 * V_101 , unsigned long V_196 )
{
struct V_6 * V_6 = F_2 ( V_101 ) ;
struct V_43 * V_44 = F_46 ( V_6 ) ;
unsigned int V_193 = V_44 -> V_197 & V_198 ;
unsigned int V_200 ;
int V_42 ;
V_42 = F_184 ( V_101 ) ;
if ( V_42 )
return V_42 ;
if ( ! F_185 ( V_6 ) ) {
V_42 = - V_102 ;
goto V_15;
}
if ( F_186 ( V_193 , ( int V_199 * ) V_196 ) ) {
V_42 = - V_19 ;
goto V_15;
}
V_193 = F_180 ( V_6 -> V_27 , V_193 ) ;
F_88 ( V_6 ) ;
V_200 = V_44 -> V_197 ;
if ( ( V_193 ^ V_200 ) & ( V_201 | V_202 ) ) {
if ( ! F_143 ( V_203 ) ) {
F_94 ( V_6 ) ;
V_42 = - V_204 ;
goto V_15;
}
}
V_193 = V_193 & V_205 ;
V_193 |= V_200 & ~ V_205 ;
V_44 -> V_197 = V_193 ;
F_94 ( V_6 ) ;
F_187 ( V_6 ) ;
V_6 -> V_126 = V_127 ;
F_136 ( V_6 ) ;
V_15:
F_188 ( V_101 ) ;
return V_42 ;
}
static int F_189 ( struct V_46 * V_101 , unsigned long V_196 )
{
struct V_6 * V_6 = F_2 ( V_101 ) ;
return F_182 ( V_6 -> V_206 , ( int V_199 * ) V_196 ) ;
}
static int F_190 ( struct V_46 * V_101 )
{
struct V_6 * V_6 = F_2 ( V_101 ) ;
int V_42 ;
if ( ! F_185 ( V_6 ) )
return - V_102 ;
if ( F_176 ( V_6 ) )
return 0 ;
V_42 = F_100 ( V_6 ) ;
if ( V_42 )
return V_42 ;
F_67 ( F_46 ( V_6 ) , V_207 ) ;
F_31 ( F_3 ( V_6 ) , V_29 ) ;
return 0 ;
}
static int F_191 ( struct V_46 * V_101 )
{
struct V_6 * V_6 = F_2 ( V_101 ) ;
int V_42 ;
if ( ! F_185 ( V_6 ) )
return - V_102 ;
if ( F_178 ( V_6 ) )
return 0 ;
V_42 = F_184 ( V_101 ) ;
if ( V_42 )
return V_42 ;
if ( F_176 ( V_6 ) ) {
F_69 ( F_46 ( V_6 ) , V_207 ) ;
V_42 = F_177 ( V_6 , false ) ;
if ( V_42 ) {
F_67 ( F_46 ( V_6 ) , V_207 ) ;
goto V_172;
}
}
V_42 = F_62 ( V_101 , 0 , V_180 , 0 ) ;
V_172:
F_188 ( V_101 ) ;
return V_42 ;
}
static int F_192 ( struct V_46 * V_101 )
{
struct V_6 * V_6 = F_2 ( V_101 ) ;
int V_42 ;
if ( ! F_185 ( V_6 ) )
return - V_102 ;
if ( F_178 ( V_6 ) )
return 0 ;
V_42 = F_100 ( V_6 ) ;
if ( V_42 )
return V_42 ;
F_67 ( F_46 ( V_6 ) , V_208 ) ;
F_31 ( F_3 ( V_6 ) , V_29 ) ;
return 0 ;
}
static int F_193 ( struct V_46 * V_101 )
{
struct V_6 * V_6 = F_2 ( V_101 ) ;
if ( ! F_185 ( V_6 ) )
return - V_102 ;
if ( ! F_178 ( V_6 ) )
return 0 ;
if ( ! F_194 ( V_6 ) )
return F_118 ( V_6 , 0 , true ) ;
return F_154 ( V_6 , 0 , V_179 ) ;
}
static int F_195 ( struct V_46 * V_101 )
{
struct V_6 * V_6 = F_2 ( V_101 ) ;
int V_42 ;
if ( ! F_185 ( V_6 ) )
return - V_102 ;
V_42 = F_184 ( V_101 ) ;
if ( V_42 )
return V_42 ;
if ( F_176 ( V_6 ) ) {
F_69 ( F_46 ( V_6 ) , V_207 ) ;
F_177 ( V_6 , true ) ;
}
if ( F_178 ( V_6 ) ) {
F_69 ( F_46 ( V_6 ) , V_208 ) ;
V_42 = F_62 ( V_101 , 0 , V_180 , 0 ) ;
}
F_188 ( V_101 ) ;
F_31 ( F_3 ( V_6 ) , V_29 ) ;
return V_42 ;
}
static int F_196 ( struct V_46 * V_101 , unsigned long V_196 )
{
struct V_6 * V_6 = F_2 ( V_101 ) ;
struct V_8 * V_9 = F_3 ( V_6 ) ;
struct V_209 * V_210 = V_9 -> V_210 ;
T_7 V_211 ;
if ( ! F_143 ( V_212 ) )
return - V_204 ;
if ( F_186 ( V_211 , ( T_7 V_199 * ) V_196 ) )
return - V_19 ;
switch ( V_211 ) {
case V_213 :
V_210 = F_197 ( V_210 -> V_214 ) ;
if ( V_210 && ! F_121 ( V_210 ) ) {
F_198 ( V_9 ) ;
F_199 ( V_210 -> V_214 , V_210 ) ;
}
break;
case V_215 :
F_75 ( V_210 , 1 ) ;
F_198 ( V_9 ) ;
break;
case V_216 :
F_198 ( V_9 ) ;
break;
case V_217 :
F_200 ( V_9 , V_218 , V_57 ) ;
F_198 ( V_9 ) ;
break;
default:
return - V_98 ;
}
F_31 ( V_9 , V_29 ) ;
return 0 ;
}
static int F_201 ( struct V_46 * V_101 , unsigned long V_196 )
{
struct V_6 * V_6 = F_2 ( V_101 ) ;
struct V_209 * V_210 = V_6 -> V_13 ;
struct V_219 * V_220 = F_202 ( V_210 -> V_214 ) ;
struct V_221 V_222 ;
int V_42 ;
if ( ! F_143 ( V_212 ) )
return - V_204 ;
if ( ! F_203 ( V_220 ) )
return - V_188 ;
if ( F_204 ( & V_222 , (struct V_221 V_199 * ) V_196 ,
sizeof( V_222 ) ) )
return - V_19 ;
V_222 . V_223 = F_205 ( ( unsigned int ) V_222 . V_223 ,
V_220 -> V_224 . V_225 ) ;
V_42 = F_206 ( F_207 ( V_210 ) , & V_222 ) ;
if ( V_42 < 0 )
return V_42 ;
if ( F_208 ( (struct V_221 V_199 * ) V_196 , & V_222 ,
sizeof( V_222 ) ) )
return - V_19 ;
F_31 ( F_3 ( V_6 ) , V_29 ) ;
return 0 ;
}
static bool F_209 ( T_8 V_226 [ 16 ] )
{
int V_41 ;
for ( V_41 = 0 ; V_41 < 16 ; V_41 ++ )
if ( V_226 [ V_41 ] )
return true ;
return false ;
}
static int F_210 ( struct V_46 * V_101 , unsigned long V_196 )
{
#ifdef F_211
struct V_227 V_228 ;
struct V_6 * V_6 = F_2 ( V_101 ) ;
if ( F_204 ( & V_228 , (struct V_227 V_199 * ) V_196 ,
sizeof( V_228 ) ) )
return - V_19 ;
F_31 ( F_3 ( V_6 ) , V_29 ) ;
return F_212 ( & V_228 , V_6 ) ;
#else
return - V_188 ;
#endif
}
static int F_213 ( struct V_46 * V_101 , unsigned long V_196 )
{
#ifdef F_211
struct V_227 V_228 ;
struct V_6 * V_6 = F_2 ( V_101 ) ;
int V_12 ;
V_12 = F_214 ( V_6 , & V_228 ) ;
if ( V_12 )
return V_12 ;
if ( F_208 ( (struct V_227 V_199 * ) V_196 , & V_228 ,
sizeof( V_228 ) ) )
return - V_19 ;
return 0 ;
#else
return - V_188 ;
#endif
}
static int F_215 ( struct V_46 * V_101 , unsigned long V_196 )
{
struct V_6 * V_6 = F_2 ( V_101 ) ;
struct V_8 * V_9 = F_3 ( V_6 ) ;
int V_12 ;
if ( ! F_216 ( V_6 -> V_13 ) )
return - V_188 ;
if ( F_209 ( V_9 -> V_229 -> V_230 ) )
goto V_231;
V_12 = F_184 ( V_101 ) ;
if ( V_12 )
return V_12 ;
F_217 ( V_9 -> V_229 -> V_230 ) ;
V_12 = F_218 ( V_9 , false ) ;
if ( V_12 ) {
memset ( V_9 -> V_229 -> V_230 , 0 , 16 ) ;
F_188 ( V_101 ) ;
return V_12 ;
}
F_188 ( V_101 ) ;
V_231:
if ( F_208 ( ( T_8 V_199 * ) V_196 , V_9 -> V_229 -> V_230 ,
16 ) )
return - V_19 ;
return 0 ;
}
static int F_219 ( struct V_46 * V_101 , unsigned long V_196 )
{
struct V_6 * V_6 = F_2 ( V_101 ) ;
struct V_8 * V_9 = F_3 ( V_6 ) ;
T_7 V_232 ;
if ( ! F_143 ( V_212 ) )
return - V_204 ;
if ( F_186 ( V_232 , ( T_7 V_199 * ) V_196 ) )
return - V_19 ;
if ( F_63 ( V_9 -> V_210 ) )
return - V_233 ;
if ( ! V_232 ) {
if ( ! F_220 ( & V_9 -> V_234 ) )
return - V_235 ;
} else {
F_221 ( & V_9 -> V_234 ) ;
}
return F_222 ( V_9 , V_232 ) ;
}
static int F_223 ( struct V_46 * V_101 , unsigned long V_196 )
{
struct V_6 * V_6 = F_2 ( V_101 ) ;
struct V_8 * V_9 = F_3 ( V_6 ) ;
if ( ! F_143 ( V_212 ) )
return - V_204 ;
if ( F_63 ( V_9 -> V_210 ) )
return - V_233 ;
return F_75 ( V_9 -> V_210 , 1 ) ;
}
static int F_224 ( struct V_8 * V_9 ,
struct V_46 * V_101 ,
struct V_236 * V_222 )
{
struct V_6 * V_6 = F_2 ( V_101 ) ;
struct V_237 V_238 ;
struct V_239 V_240 ;
T_2 V_159 , V_160 ;
unsigned int V_241 = V_9 -> V_242 ;
unsigned int V_243 = 0 , V_244 ;
unsigned int V_245 = V_9 -> V_246 * V_241 ;
T_3 V_164 = 0 ;
bool V_247 = false ;
int V_12 ;
if ( F_225 ( V_6 ) )
return - V_98 ;
V_159 = V_222 -> V_47 >> V_22 ;
V_160 = ( V_222 -> V_47 + V_222 -> V_108 ) >> V_22 ;
F_12 ( V_9 , true ) ;
F_88 ( V_6 ) ;
V_12 = F_68 ( V_6 -> V_18 , V_222 -> V_47 ,
V_222 -> V_47 + V_222 -> V_108 - 1 ) ;
if ( V_12 )
goto V_15;
if ( F_226 ( V_6 , V_159 , & V_240 ) ) {
if ( V_240 . V_111 + V_240 . V_108 >= V_160 )
goto V_15;
}
V_238 . V_248 = V_159 ;
while ( V_238 . V_248 < V_160 ) {
V_238 . V_249 = V_160 - V_238 . V_248 ;
V_12 = V_237 ( V_6 , & V_238 , 0 , V_250 ) ;
if ( V_12 )
goto V_15;
if ( ! ( V_238 . V_251 & V_252 ) ) {
V_238 . V_248 ++ ;
continue;
}
if ( V_164 && V_164 != V_238 . V_253 ) {
V_247 = true ;
break;
}
V_164 = V_238 . V_253 + V_238 . V_249 ;
V_238 . V_248 += V_238 . V_249 ;
}
if ( ! V_247 )
goto V_15;
V_238 . V_248 = V_159 ;
V_238 . V_249 = V_160 - V_159 ;
V_244 = ( V_238 . V_249 + V_245 - 1 ) / V_245 ;
if ( F_227 ( V_9 , V_244 ) ) {
V_12 = - V_254 ;
goto V_15;
}
while ( V_238 . V_248 < V_160 ) {
T_2 V_183 ;
int V_255 = 0 ;
V_256:
V_238 . V_249 = V_160 - V_238 . V_248 ;
V_12 = V_237 ( V_6 , & V_238 , 0 , V_250 ) ;
if ( V_12 )
goto V_257;
if ( ! ( V_238 . V_251 & V_252 ) ) {
V_238 . V_248 ++ ;
continue;
}
F_67 ( F_46 ( V_6 ) , V_258 ) ;
V_183 = V_238 . V_248 ;
while ( V_183 < V_238 . V_248 + V_238 . V_249 && V_255 < V_241 ) {
struct V_5 * V_5 ;
V_5 = F_120 ( V_6 , V_183 , true ) ;
if ( F_121 ( V_5 ) ) {
V_12 = F_127 ( V_5 ) ;
goto V_257;
}
F_22 ( V_5 ) ;
F_55 ( V_5 , 1 ) ;
V_183 ++ ;
V_255 ++ ;
V_243 ++ ;
}
V_238 . V_248 = V_183 ;
if ( V_183 < V_160 && V_255 < V_241 )
goto V_256;
F_69 ( F_46 ( V_6 ) , V_258 ) ;
V_12 = F_179 ( V_6 -> V_18 ) ;
if ( V_12 )
goto V_15;
}
V_257:
F_69 ( F_46 ( V_6 ) , V_258 ) ;
V_15:
F_94 ( V_6 ) ;
if ( ! V_12 )
V_222 -> V_108 = ( T_5 ) V_243 << V_22 ;
return V_12 ;
}
static int F_228 ( struct V_46 * V_101 , unsigned long V_196 )
{
struct V_6 * V_6 = F_2 ( V_101 ) ;
struct V_8 * V_9 = F_3 ( V_6 ) ;
struct V_236 V_222 ;
int V_12 ;
if ( ! F_143 ( V_212 ) )
return - V_204 ;
if ( ! F_27 ( V_6 -> V_27 ) )
return - V_98 ;
V_12 = F_184 ( V_101 ) ;
if ( V_12 )
return V_12 ;
if ( F_63 ( V_9 -> V_210 ) ) {
V_12 = - V_233 ;
goto V_15;
}
if ( F_204 ( & V_222 , (struct V_236 V_199 * ) V_196 ,
sizeof( V_222 ) ) ) {
V_12 = - V_19 ;
goto V_15;
}
if ( V_222 . V_47 & ( V_179 - 1 ) ||
V_222 . V_108 & ( V_179 - 1 ) ) {
V_12 = - V_98 ;
goto V_15;
}
V_12 = F_224 ( V_9 , V_101 , & V_222 ) ;
F_31 ( V_9 , V_29 ) ;
if ( V_12 < 0 )
goto V_15;
if ( F_208 ( (struct V_236 V_199 * ) V_196 , & V_222 ,
sizeof( V_222 ) ) )
V_12 = - V_19 ;
V_15:
F_188 ( V_101 ) ;
return V_12 ;
}
long F_229 ( struct V_46 * V_101 , unsigned int V_259 , unsigned long V_196 )
{
switch ( V_259 ) {
case V_260 :
return F_181 ( V_101 , V_196 ) ;
case V_261 :
return F_183 ( V_101 , V_196 ) ;
case V_262 :
return F_189 ( V_101 , V_196 ) ;
case V_263 :
return F_190 ( V_101 ) ;
case V_264 :
return F_191 ( V_101 ) ;
case V_265 :
return F_192 ( V_101 ) ;
case V_266 :
return F_193 ( V_101 ) ;
case V_267 :
return F_195 ( V_101 ) ;
case V_268 :
return F_196 ( V_101 , V_196 ) ;
case V_269 :
return F_201 ( V_101 , V_196 ) ;
case V_270 :
return F_210 ( V_101 , V_196 ) ;
case V_271 :
return F_213 ( V_101 , V_196 ) ;
case V_272 :
return F_215 ( V_101 , V_196 ) ;
case V_273 :
return F_219 ( V_101 , V_196 ) ;
case V_274 :
return F_223 ( V_101 , V_196 ) ;
case V_275 :
return F_228 ( V_101 , V_196 ) ;
default:
return - V_276 ;
}
}
static T_9 F_230 ( struct V_277 * V_278 , struct V_279 * V_114 )
{
struct V_6 * V_6 = F_2 ( V_278 -> V_280 ) ;
if ( F_26 ( V_6 ) &&
! F_231 ( V_6 ) &&
F_99 ( V_6 ) )
return - V_102 ;
return F_232 ( V_278 , V_114 ) ;
}
long F_233 ( struct V_46 * V_46 , unsigned int V_259 , unsigned long V_196 )
{
switch ( V_259 ) {
case V_281 :
V_259 = V_260 ;
break;
case V_282 :
V_259 = V_261 ;
break;
case V_283 :
V_259 = V_262 ;
break;
case V_263 :
case V_264 :
case V_265 :
case V_266 :
case V_267 :
case V_268 :
case V_270 :
case V_272 :
case V_271 :
case V_273 :
case V_274 :
case V_275 :
break;
default:
return - V_284 ;
}
return F_229 ( V_46 , V_259 , ( unsigned long ) F_234 ( V_196 ) ) ;
}
