static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_5 = V_4 -> V_5 ;
struct V_6 * V_6 = F_2 ( V_2 -> V_7 ) ;
struct V_8 * V_9 = F_3 ( V_6 ) ;
struct V_10 V_11 ;
int V_12 ;
F_4 ( V_9 ) ;
F_5 ( V_6 -> V_13 ) ;
F_6 ( V_9 , F_7 ( V_6 ) ) ;
F_8 ( V_9 ) ;
F_9 ( & V_11 , V_6 , NULL , NULL , 0 ) ;
V_12 = F_10 ( & V_11 , V_5 -> V_14 ) ;
if ( V_12 ) {
F_11 ( V_9 ) ;
goto V_15;
}
F_12 ( & V_11 ) ;
F_11 ( V_9 ) ;
F_13 ( V_2 -> V_7 ) ;
F_14 ( V_5 ) ;
if ( F_15 ( V_5 -> V_16 != V_6 -> V_17 ||
F_16 ( V_5 ) > F_17 ( V_6 ) ||
! F_18 ( V_5 ) ) ) {
F_19 ( V_5 ) ;
V_12 = - V_18 ;
goto V_15;
}
if ( F_20 ( V_5 ) )
goto V_19;
if ( ( ( V_5 -> V_14 + 1 ) << V_20 ) > F_17 ( V_6 ) ) {
unsigned V_21 ;
V_21 = F_17 ( V_6 ) & ~ V_22 ;
F_21 ( V_5 , V_21 , V_23 ) ;
}
F_22 ( V_5 ) ;
F_23 ( V_5 ) ;
F_24 ( V_5 , V_24 ) ;
V_19:
F_25 ( V_5 , V_24 ) ;
F_26 ( V_5 ) ;
V_15:
F_27 ( V_6 -> V_13 ) ;
return F_28 ( V_12 ) ;
}
static int F_29 ( struct V_6 * V_6 , T_1 * V_25 )
{
struct V_26 * V_26 ;
V_6 = F_30 ( V_6 ) ;
V_26 = F_31 ( V_6 ) ;
F_32 ( V_6 ) ;
if ( ! V_26 )
return 0 ;
if ( F_33 ( V_6 , V_6 , & V_26 -> V_27 ) ) {
F_34 ( V_26 ) ;
return 0 ;
}
* V_25 = F_35 ( V_26 ) ;
F_34 ( V_26 ) ;
return 1 ;
}
static inline bool F_36 ( struct V_6 * V_6 )
{
struct V_8 * V_9 = F_3 ( V_6 ) ;
bool V_28 = false ;
if ( ! F_37 ( V_6 -> V_29 ) || V_6 -> V_30 != 1 )
V_28 = true ;
else if ( F_38 ( V_6 ) && F_39 ( V_9 , V_6 -> V_31 ) )
V_28 = true ;
else if ( F_40 ( V_6 ) )
V_28 = true ;
else if ( ! F_41 ( V_9 ) )
V_28 = true ;
else if ( ! F_42 ( V_9 , F_43 ( V_6 ) -> V_32 ) )
V_28 = true ;
else if ( F_43 ( V_6 ) -> V_33 == F_44 ( F_45 ( V_9 ) ) )
V_28 = true ;
else if ( F_46 ( V_9 , V_34 ) )
V_28 = true ;
else if ( V_9 -> V_35 == 2 )
V_28 = true ;
return V_28 ;
}
static bool F_47 ( struct V_8 * V_9 , T_1 V_36 )
{
struct V_5 * V_37 = F_48 ( F_49 ( V_9 ) , V_36 ) ;
bool V_38 = false ;
if ( ( V_37 && F_50 ( V_37 ) ) || F_51 ( V_9 , V_36 ) )
V_38 = true ;
F_52 ( V_37 , 0 ) ;
return V_38 ;
}
static void F_53 ( struct V_6 * V_6 )
{
struct V_39 * V_40 = F_43 ( V_6 ) ;
T_1 V_25 ;
F_54 ( & V_40 -> V_41 ) ;
V_40 -> V_33 = 0 ;
if ( F_40 ( V_6 ) && V_6 -> V_30 == 1 &&
F_29 ( V_6 , & V_25 ) ) {
V_40 -> V_32 = V_25 ;
F_55 ( V_6 ) ;
F_56 ( & V_40 -> V_41 ) ;
F_57 ( V_6 ) ;
F_58 ( V_6 , NULL ) ;
} else {
F_56 ( & V_40 -> V_41 ) ;
}
}
int F_59 ( struct V_42 * V_42 , T_2 V_43 , T_2 V_44 , int V_45 )
{
struct V_6 * V_6 = V_42 -> V_46 -> V_47 ;
struct V_39 * V_40 = F_43 ( V_6 ) ;
struct V_8 * V_9 = F_3 ( V_6 ) ;
T_1 V_36 = V_6 -> V_31 ;
int V_38 = 0 ;
bool V_28 = false ;
struct V_48 V_49 = {
. V_50 = V_51 ,
. V_52 = V_53 ,
. V_54 = 0 ,
} ;
if ( F_15 ( F_60 ( V_6 -> V_13 ) ) )
return 0 ;
F_61 ( V_6 ) ;
if ( F_62 ( V_6 ) <= F_63 ( V_9 ) -> V_55 )
F_64 ( V_40 , V_56 ) ;
V_38 = F_65 ( V_6 -> V_17 , V_43 , V_44 ) ;
F_66 ( V_40 , V_56 ) ;
if ( V_38 ) {
F_67 ( V_6 , V_28 , V_45 , V_38 ) ;
return V_38 ;
}
if ( ! V_45 ) {
F_58 ( V_6 , NULL ) ;
goto V_57;
}
if ( ! F_68 ( V_40 , V_58 ) &&
! F_69 ( V_9 , V_36 , V_59 ) ) {
if ( F_47 ( V_9 , V_36 ) )
goto V_57;
if ( F_68 ( V_40 , V_60 ) ||
F_69 ( V_9 , V_36 , V_61 ) )
goto V_62;
goto V_15;
}
V_57:
F_4 ( V_9 ) ;
F_70 ( & V_40 -> V_41 ) ;
V_28 = F_36 ( V_6 ) ;
F_71 ( & V_40 -> V_41 ) ;
if ( V_28 ) {
V_38 = F_72 ( V_6 -> V_13 , 1 ) ;
F_53 ( V_6 ) ;
F_66 ( V_40 , V_58 ) ;
F_66 ( V_40 , V_60 ) ;
goto V_15;
}
V_63:
F_73 ( V_9 , V_36 , & V_49 ) ;
if ( F_15 ( F_74 ( V_9 ) ) )
goto V_15;
if ( F_51 ( V_9 , V_36 ) ) {
F_57 ( V_6 ) ;
F_58 ( V_6 , NULL ) ;
goto V_63;
}
V_38 = F_75 ( V_9 , V_36 ) ;
if ( V_38 )
goto V_15;
F_76 ( V_9 , V_36 , V_59 ) ;
F_66 ( V_40 , V_58 ) ;
V_62:
F_76 ( V_9 , V_36 , V_61 ) ;
F_66 ( V_40 , V_60 ) ;
V_38 = F_77 ( V_9 ) ;
V_15:
F_67 ( V_6 , V_28 , V_45 , V_38 ) ;
F_78 ( NULL , 1 ) ;
return V_38 ;
}
static T_3 F_79 ( struct V_64 * V_16 ,
T_3 V_65 , int V_66 )
{
struct V_67 V_68 ;
int V_69 ;
if ( V_66 != V_70 )
return 0 ;
F_80 ( & V_68 , 0 ) ;
V_69 = F_81 ( & V_68 , V_16 , & V_65 ,
V_71 , 1 ) ;
V_65 = V_69 ? V_68 . V_72 [ 0 ] -> V_14 : V_53 ;
F_82 ( & V_68 ) ;
return V_65 ;
}
static bool F_83 ( T_4 V_73 , T_3 V_74 , T_3 V_65 ,
int V_66 )
{
switch ( V_66 ) {
case V_70 :
if ( ( V_73 == V_75 && V_74 == V_65 ) ||
( V_73 != V_75 && V_73 != V_76 ) )
return true ;
break;
case V_77 :
if ( V_73 == V_76 )
return true ;
break;
}
return false ;
}
static T_2 F_84 ( struct V_42 * V_42 , T_2 V_21 , int V_66 )
{
struct V_6 * V_6 = V_42 -> V_46 -> V_47 ;
T_2 V_78 = V_6 -> V_13 -> V_79 ;
struct V_10 V_11 ;
T_3 V_65 , V_80 , V_74 ;
T_2 V_81 = V_21 ;
T_2 V_82 ;
int V_12 = 0 ;
F_85 ( & V_6 -> V_83 ) ;
V_82 = F_17 ( V_6 ) ;
if ( V_21 >= V_82 )
goto V_84;
if ( F_7 ( V_6 ) || F_86 ( V_6 ) ) {
if ( V_66 == V_77 )
V_81 = V_82 ;
goto V_85;
}
V_65 = ( T_3 ) ( V_21 >> V_20 ) ;
V_74 = F_79 ( V_6 -> V_17 , V_65 , V_66 ) ;
for (; V_81 < V_82 ; V_81 = V_65 << V_20 ) {
F_9 ( & V_11 , V_6 , NULL , NULL , 0 ) ;
V_12 = F_87 ( & V_11 , V_65 , V_86 ) ;
if ( V_12 && V_12 != - V_87 ) {
goto V_84;
} else if ( V_12 == - V_87 ) {
if ( V_66 == V_70 ) {
V_65 = F_88 ( V_65 ,
F_43 ( V_6 ) ) ;
continue;
} else {
goto V_85;
}
}
V_80 = F_89 ( V_11 . V_88 , F_43 ( V_6 ) ) ;
for (; V_11 . V_89 < V_80 ;
V_11 . V_89 ++ , V_65 ++ ,
V_81 = ( T_2 ) V_65 << V_20 ) {
T_4 V_73 ;
V_73 = F_90 ( V_11 . V_88 , V_11 . V_89 ) ;
if ( F_83 ( V_73 , V_74 , V_65 , V_66 ) ) {
F_12 ( & V_11 ) ;
goto V_85;
}
}
F_12 ( & V_11 ) ;
}
if ( V_66 == V_70 )
goto V_84;
V_85:
if ( V_66 == V_77 && V_81 > V_82 )
V_81 = V_82 ;
F_91 ( & V_6 -> V_83 ) ;
return F_92 ( V_42 , V_81 , V_78 ) ;
V_84:
F_91 ( & V_6 -> V_83 ) ;
return - V_90 ;
}
static T_2 F_93 ( struct V_42 * V_42 , T_2 V_21 , int V_66 )
{
struct V_6 * V_6 = V_42 -> V_46 -> V_47 ;
T_2 V_78 = V_6 -> V_13 -> V_79 ;
switch ( V_66 ) {
case V_91 :
case V_92 :
case V_93 :
return F_94 ( V_42 , V_21 , V_66 ,
V_78 , F_17 ( V_6 ) ) ;
case V_70 :
case V_77 :
if ( V_21 < 0 )
return - V_90 ;
return F_84 ( V_42 , V_21 , V_66 ) ;
}
return - V_94 ;
}
static int F_95 ( struct V_42 * V_42 , struct V_1 * V_2 )
{
struct V_6 * V_6 = F_2 ( V_42 ) ;
if ( F_96 ( V_6 ) ) {
int V_12 = F_97 ( V_6 ) ;
if ( V_12 )
return 0 ;
}
if ( F_7 ( V_6 ) ) {
int V_12 = F_98 ( V_6 ) ;
if ( V_12 )
return V_12 ;
}
F_99 ( V_42 ) ;
V_2 -> V_95 = & V_96 ;
return 0 ;
}
static int F_100 ( struct V_6 * V_6 , struct V_42 * V_97 )
{
int V_38 = F_101 ( V_6 , V_97 ) ;
if ( ! V_38 && F_96 ( V_6 ) ) {
V_38 = F_97 ( V_6 ) ;
if ( V_38 )
V_38 = - V_98 ;
}
return V_38 ;
}
int F_102 ( struct V_10 * V_11 , int V_99 )
{
struct V_8 * V_9 = F_3 ( V_11 -> V_6 ) ;
struct V_100 * V_101 ;
int V_102 = 0 , V_103 = V_11 -> V_89 , V_104 = V_99 ;
T_5 * V_105 ;
V_101 = F_103 ( V_11 -> V_88 ) ;
V_105 = F_104 ( V_101 ) + V_103 ;
for (; V_99 > 0 ; V_99 -- , V_105 ++ , V_11 -> V_89 ++ ) {
T_4 V_73 = F_105 ( * V_105 ) ;
if ( V_73 == V_76 )
continue;
V_11 -> V_106 = V_76 ;
F_106 ( V_11 ) ;
F_107 ( V_9 , V_73 ) ;
if ( V_11 -> V_89 == 0 && F_108 ( V_11 -> V_88 ) )
F_66 ( F_43 ( V_11 -> V_6 ) ,
V_107 ) ;
V_102 ++ ;
}
if ( V_102 ) {
T_3 V_108 ;
V_108 = F_109 ( F_110 ( V_11 -> V_88 ) ,
F_43 ( V_11 -> V_6 ) ) + V_103 ;
F_111 ( V_11 , V_108 , 0 , V_104 ) ;
F_112 ( V_9 , V_11 -> V_6 , V_102 ) ;
F_22 ( V_11 -> V_88 ) ;
F_113 ( V_11 ) ;
}
V_11 -> V_89 = V_103 ;
F_114 ( V_11 -> V_6 , V_11 -> V_109 ,
V_11 -> V_89 , V_102 ) ;
return V_102 ;
}
void F_115 ( struct V_10 * V_11 )
{
F_102 ( V_11 , V_110 ) ;
}
static int F_116 ( struct V_6 * V_6 , T_6 V_111 ,
bool V_112 )
{
unsigned V_21 = V_111 & ( V_23 - 1 ) ;
T_3 V_14 = V_111 >> V_20 ;
struct V_64 * V_16 = V_6 -> V_17 ;
struct V_5 * V_5 ;
if ( ! V_21 && ! V_112 )
return 0 ;
if ( V_112 ) {
V_5 = F_117 ( V_16 , V_14 ) ;
if ( V_5 && F_18 ( V_5 ) )
goto V_113;
F_52 ( V_5 , 1 ) ;
return 0 ;
}
V_5 = F_118 ( V_6 , V_14 ) ;
if ( F_119 ( V_5 ) )
return 0 ;
V_113:
F_25 ( V_5 , V_24 ) ;
F_120 ( V_5 , V_21 , V_23 - V_21 ) ;
if ( ! V_112 || ! F_96 ( V_6 ) || ! F_37 ( V_6 -> V_29 ) )
F_22 ( V_5 ) ;
F_52 ( V_5 , 1 ) ;
return 0 ;
}
int F_121 ( struct V_6 * V_6 , T_6 V_111 , bool V_114 )
{
struct V_8 * V_9 = F_3 ( V_6 ) ;
unsigned int V_115 = V_6 -> V_13 -> V_116 ;
struct V_10 V_11 ;
T_3 V_117 ;
int V_99 = 0 , V_12 = 0 ;
struct V_5 * V_118 ;
bool V_119 = false ;
F_122 ( V_6 , V_111 ) ;
V_117 = ( T_3 ) F_123 ( V_111 + V_115 - 1 ) ;
if ( V_114 )
F_8 ( V_9 ) ;
V_118 = F_124 ( V_9 , V_6 -> V_31 ) ;
if ( F_119 ( V_118 ) ) {
V_12 = F_125 ( V_118 ) ;
goto V_15;
}
if ( F_7 ( V_6 ) ) {
if ( F_126 ( V_118 , V_111 ) )
F_22 ( V_118 ) ;
F_52 ( V_118 , 1 ) ;
V_119 = true ;
goto V_15;
}
F_9 ( & V_11 , V_6 , V_118 , NULL , 0 ) ;
V_12 = F_87 ( & V_11 , V_117 , V_120 ) ;
if ( V_12 ) {
if ( V_12 == - V_87 )
goto V_121;
goto V_15;
}
V_99 = F_89 ( V_11 . V_88 , F_43 ( V_6 ) ) ;
V_99 -= V_11 . V_89 ;
F_6 ( V_9 , V_99 < 0 ) ;
if ( V_11 . V_89 || F_108 ( V_11 . V_88 ) ) {
F_102 ( & V_11 , V_99 ) ;
V_117 += V_99 ;
}
F_12 ( & V_11 ) ;
V_121:
V_12 = F_127 ( V_6 , V_117 ) ;
V_15:
if ( V_114 )
F_11 ( V_9 ) ;
if ( ! V_12 )
V_12 = F_116 ( V_6 , V_111 , V_119 ) ;
F_128 ( V_6 , V_12 ) ;
return V_12 ;
}
int F_129 ( struct V_6 * V_6 , bool V_114 )
{
int V_12 ;
if ( ! ( F_37 ( V_6 -> V_29 ) || F_130 ( V_6 -> V_29 ) ||
F_131 ( V_6 -> V_29 ) ) )
return 0 ;
F_132 ( V_6 ) ;
if ( F_7 ( V_6 ) && ! F_133 ( V_6 ) ) {
V_12 = F_98 ( V_6 ) ;
if ( V_12 )
return V_12 ;
}
V_12 = F_121 ( V_6 , F_17 ( V_6 ) , V_114 ) ;
if ( V_12 )
return V_12 ;
V_6 -> V_122 = V_6 -> V_123 = V_124 ;
F_134 ( V_6 ) ;
return 0 ;
}
int F_135 ( struct V_125 * V_126 ,
struct V_26 * V_26 , struct V_127 * V_128 )
{
struct V_6 * V_6 = F_136 ( V_26 ) ;
F_137 ( V_6 , V_128 ) ;
V_128 -> V_129 <<= 3 ;
return 0 ;
}
static void F_138 ( struct V_6 * V_6 , const struct V_130 * V_131 )
{
struct V_39 * V_40 = F_43 ( V_6 ) ;
unsigned int V_132 = V_131 -> V_132 ;
if ( V_132 & V_133 )
V_6 -> V_134 = V_131 -> V_135 ;
if ( V_132 & V_136 )
V_6 -> V_137 = V_131 -> V_138 ;
if ( V_132 & V_139 )
V_6 -> V_140 = F_139 ( V_131 -> V_141 ,
V_6 -> V_13 -> V_142 ) ;
if ( V_132 & V_143 )
V_6 -> V_122 = F_139 ( V_131 -> V_144 ,
V_6 -> V_13 -> V_142 ) ;
if ( V_132 & V_145 )
V_6 -> V_123 = F_139 ( V_131 -> V_146 ,
V_6 -> V_13 -> V_142 ) ;
if ( V_132 & V_147 ) {
T_7 V_148 = V_131 -> V_149 ;
if ( ! F_140 ( V_6 -> V_137 ) && ! F_141 ( V_150 ) )
V_148 &= ~ V_151 ;
F_142 ( V_40 , V_148 ) ;
}
}
int F_143 ( struct V_26 * V_26 , struct V_130 * V_131 )
{
struct V_6 * V_6 = F_136 ( V_26 ) ;
struct V_39 * V_40 = F_43 ( V_6 ) ;
int V_12 ;
V_12 = F_144 ( V_6 , V_131 ) ;
if ( V_12 )
return V_12 ;
if ( V_131 -> V_132 & V_152 ) {
if ( F_96 ( V_6 ) &&
F_97 ( V_6 ) )
return - V_98 ;
if ( V_131 -> V_153 <= F_17 ( V_6 ) ) {
F_145 ( V_6 , V_131 -> V_153 ) ;
V_12 = F_129 ( V_6 , true ) ;
if ( V_12 )
return V_12 ;
F_4 ( F_3 ( V_6 ) ) ;
} else {
F_145 ( V_6 , V_131 -> V_153 ) ;
}
}
F_138 ( V_6 , V_131 ) ;
if ( V_131 -> V_132 & V_147 ) {
V_12 = F_146 ( V_6 , F_147 ( V_6 ) ) ;
if ( V_12 || F_68 ( V_40 , V_154 ) ) {
V_6 -> V_29 = V_40 -> V_155 ;
F_66 ( V_40 , V_154 ) ;
}
}
F_134 ( V_6 ) ;
return V_12 ;
}
static int F_148 ( struct V_6 * V_6 , T_3 V_14 ,
T_2 V_43 , T_2 V_104 )
{
struct V_8 * V_9 = F_3 ( V_6 ) ;
struct V_5 * V_5 ;
if ( ! V_104 )
return 0 ;
F_4 ( V_9 ) ;
F_8 ( V_9 ) ;
V_5 = F_149 ( V_6 , NULL , V_14 , false ) ;
F_11 ( V_9 ) ;
if ( F_119 ( V_5 ) )
return F_125 ( V_5 ) ;
F_25 ( V_5 , V_24 ) ;
F_120 ( V_5 , V_43 , V_104 ) ;
F_22 ( V_5 ) ;
F_52 ( V_5 , 1 ) ;
return 0 ;
}
int F_150 ( struct V_6 * V_6 , T_3 V_156 , T_3 V_157 )
{
T_3 V_14 ;
int V_12 ;
for ( V_14 = V_156 ; V_14 < V_157 ; V_14 ++ ) {
struct V_10 V_11 ;
F_9 ( & V_11 , V_6 , NULL , NULL , 0 ) ;
V_12 = F_87 ( & V_11 , V_14 , V_120 ) ;
if ( V_12 ) {
if ( V_12 == - V_87 )
continue;
return V_12 ;
}
if ( V_11 . V_106 != V_76 )
F_102 ( & V_11 , 1 ) ;
F_12 ( & V_11 ) ;
}
return 0 ;
}
static int F_151 ( struct V_6 * V_6 , T_2 V_21 , T_2 V_104 )
{
T_3 V_156 , V_157 ;
T_2 V_158 , V_159 ;
int V_38 = 0 ;
if ( ! F_37 ( V_6 -> V_29 ) )
return - V_160 ;
if ( F_7 ( V_6 ) ) {
V_38 = F_98 ( V_6 ) ;
if ( V_38 )
return V_38 ;
}
V_156 = ( ( unsigned long long ) V_21 ) >> V_20 ;
V_157 = ( ( unsigned long long ) V_21 + V_104 ) >> V_20 ;
V_158 = V_21 & ( V_23 - 1 ) ;
V_159 = ( V_21 + V_104 ) & ( V_23 - 1 ) ;
if ( V_156 == V_157 ) {
V_38 = F_148 ( V_6 , V_156 , V_158 ,
V_159 - V_158 ) ;
if ( V_38 )
return V_38 ;
} else {
if ( V_158 ) {
V_38 = F_148 ( V_6 , V_156 ++ , V_158 ,
V_23 - V_158 ) ;
if ( V_38 )
return V_38 ;
}
if ( V_159 ) {
V_38 = F_148 ( V_6 , V_157 , 0 , V_159 ) ;
if ( V_38 )
return V_38 ;
}
if ( V_156 < V_157 ) {
struct V_64 * V_16 = V_6 -> V_17 ;
T_2 V_161 , V_162 ;
struct V_8 * V_9 = F_3 ( V_6 ) ;
F_4 ( V_9 ) ;
V_161 = V_156 << V_20 ;
V_162 = V_157 << V_20 ;
F_152 ( V_16 , V_161 ,
V_162 - 1 ) ;
F_8 ( V_9 ) ;
V_38 = F_150 ( V_6 , V_156 , V_157 ) ;
F_11 ( V_9 ) ;
}
}
return V_38 ;
}
static int F_153 ( struct V_6 * V_6 , T_3 V_43 , T_3 V_44 )
{
struct V_8 * V_9 = F_3 ( V_6 ) ;
struct V_10 V_11 ;
T_3 V_163 = ( F_17 ( V_6 ) + V_164 - 1 ) / V_164 ;
int V_38 = 0 ;
for (; V_44 < V_163 ; V_43 ++ , V_44 ++ ) {
T_4 V_165 , V_166 ;
F_8 ( V_9 ) ;
F_9 ( & V_11 , V_6 , NULL , NULL , 0 ) ;
V_38 = F_87 ( & V_11 , V_44 , V_86 ) ;
if ( V_38 && V_38 != - V_87 ) {
goto V_15;
} else if ( V_38 == - V_87 ) {
V_165 = V_76 ;
} else {
V_165 = V_11 . V_106 ;
F_102 ( & V_11 , 1 ) ;
F_12 ( & V_11 ) ;
}
if ( V_165 == V_76 ) {
F_9 ( & V_11 , V_6 , NULL , NULL , 0 ) ;
V_38 = F_87 ( & V_11 , V_43 , V_86 ) ;
if ( V_38 && V_38 != - V_87 ) {
goto V_15;
} else if ( V_38 == - V_87 ) {
F_11 ( V_9 ) ;
continue;
}
if ( V_11 . V_106 == V_76 ) {
F_12 ( & V_11 ) ;
F_11 ( V_9 ) ;
continue;
} else {
F_102 ( & V_11 , 1 ) ;
}
F_12 ( & V_11 ) ;
} else {
struct V_5 * V_118 ;
V_118 = F_124 ( V_9 , V_6 -> V_31 ) ;
if ( F_119 ( V_118 ) ) {
V_38 = F_125 ( V_118 ) ;
goto V_15;
}
F_9 ( & V_11 , V_6 , V_118 , NULL , 0 ) ;
V_38 = F_10 ( & V_11 , V_43 ) ;
if ( V_38 )
goto V_15;
V_166 = V_11 . V_106 ;
if ( V_166 != V_75 && V_165 == V_75 ) {
V_11 . V_106 = V_76 ;
F_154 ( & V_11 ) ;
F_107 ( V_9 , V_166 ) ;
V_11 . V_106 = V_165 ;
F_106 ( & V_11 ) ;
} else if ( V_165 != V_75 ) {
struct V_167 V_168 ;
F_155 ( V_9 , V_11 . V_109 , & V_168 ) ;
F_156 ( V_9 , & V_11 , V_166 , V_165 ,
V_168 . V_169 , true ) ;
}
F_12 ( & V_11 ) ;
}
F_11 ( V_9 ) ;
}
return 0 ;
V_15:
F_11 ( V_9 ) ;
return V_38 ;
}
static int F_157 ( struct V_6 * V_6 , T_2 V_21 , T_2 V_104 )
{
T_3 V_156 , V_157 ;
T_2 V_170 ;
int V_38 ;
if ( ! F_37 ( V_6 -> V_29 ) )
return - V_94 ;
if ( V_21 + V_104 >= F_17 ( V_6 ) )
return - V_94 ;
if ( V_21 & ( V_171 - 1 ) || V_104 & ( V_171 - 1 ) )
return - V_94 ;
F_4 ( F_3 ( V_6 ) ) ;
if ( F_7 ( V_6 ) ) {
V_38 = F_98 ( V_6 ) ;
if ( V_38 )
return V_38 ;
}
V_156 = V_21 >> V_20 ;
V_157 = ( V_21 + V_104 ) >> V_20 ;
V_38 = F_65 ( V_6 -> V_17 , V_21 , V_172 ) ;
if ( V_38 )
return V_38 ;
F_158 ( V_6 , V_21 ) ;
V_38 = F_153 ( V_6 , V_156 , V_157 ) ;
if ( V_38 )
return V_38 ;
V_170 = F_17 ( V_6 ) - V_104 ;
V_38 = F_121 ( V_6 , V_170 , true ) ;
if ( ! V_38 )
F_159 ( V_6 , V_170 ) ;
return V_38 ;
}
static int F_160 ( struct V_6 * V_6 , T_2 V_21 , T_2 V_104 ,
int V_148 )
{
struct V_8 * V_9 = F_3 ( V_6 ) ;
struct V_64 * V_16 = V_6 -> V_17 ;
T_3 V_14 , V_156 , V_157 ;
T_2 V_170 = F_17 ( V_6 ) ;
T_2 V_158 , V_159 ;
int V_38 = 0 ;
if ( ! F_37 ( V_6 -> V_29 ) )
return - V_94 ;
V_38 = F_161 ( V_6 , ( V_104 + V_21 ) ) ;
if ( V_38 )
return V_38 ;
F_4 ( V_9 ) ;
if ( F_7 ( V_6 ) ) {
V_38 = F_98 ( V_6 ) ;
if ( V_38 )
return V_38 ;
}
V_38 = F_65 ( V_16 , V_21 , V_21 + V_104 - 1 ) ;
if ( V_38 )
return V_38 ;
F_162 ( V_6 , V_21 , V_21 + V_104 - 1 ) ;
V_156 = ( ( unsigned long long ) V_21 ) >> V_20 ;
V_157 = ( ( unsigned long long ) V_21 + V_104 ) >> V_20 ;
V_158 = V_21 & ( V_23 - 1 ) ;
V_159 = ( V_21 + V_104 ) & ( V_23 - 1 ) ;
if ( V_156 == V_157 ) {
V_38 = F_148 ( V_6 , V_156 , V_158 ,
V_159 - V_158 ) ;
if ( V_38 )
return V_38 ;
if ( V_21 + V_104 > V_170 )
V_170 = V_21 + V_104 ;
V_170 = F_163 ( T_2 , V_170 , V_21 + V_104 ) ;
} else {
if ( V_158 ) {
V_38 = F_148 ( V_6 , V_156 ++ , V_158 ,
V_23 - V_158 ) ;
if ( V_38 )
return V_38 ;
V_170 = F_163 ( T_2 , V_170 ,
V_156 << V_20 ) ;
}
for ( V_14 = V_156 ; V_14 < V_157 ; V_14 ++ ) {
struct V_10 V_11 ;
struct V_5 * V_118 ;
F_8 ( V_9 ) ;
V_118 = F_124 ( V_9 , V_6 -> V_31 ) ;
if ( F_119 ( V_118 ) ) {
V_38 = F_125 ( V_118 ) ;
F_11 ( V_9 ) ;
goto V_15;
}
F_9 ( & V_11 , V_6 , V_118 , NULL , 0 ) ;
V_38 = F_10 ( & V_11 , V_14 ) ;
if ( V_38 ) {
F_11 ( V_9 ) ;
goto V_15;
}
if ( V_11 . V_106 != V_75 ) {
F_107 ( V_9 , V_11 . V_106 ) ;
V_11 . V_106 = V_75 ;
F_106 ( & V_11 ) ;
V_11 . V_106 = V_76 ;
F_154 ( & V_11 ) ;
}
F_12 ( & V_11 ) ;
F_11 ( V_9 ) ;
V_170 = F_163 ( T_2 , V_170 ,
( V_14 + 1 ) << V_20 ) ;
}
if ( V_159 ) {
V_38 = F_148 ( V_6 , V_157 , 0 , V_159 ) ;
if ( V_38 )
goto V_15;
V_170 = F_163 ( T_2 , V_170 , V_21 + V_104 ) ;
}
}
V_15:
if ( ! ( V_148 & V_173 ) && F_17 ( V_6 ) < V_170 ) {
F_159 ( V_6 , V_170 ) ;
F_134 ( V_6 ) ;
F_164 ( V_6 ) ;
}
return V_38 ;
}
static int F_165 ( struct V_6 * V_6 , T_2 V_21 , T_2 V_104 )
{
struct V_8 * V_9 = F_3 ( V_6 ) ;
T_3 V_156 , V_157 , V_174 , V_163 , V_175 ;
T_2 V_170 ;
int V_38 ;
if ( ! F_37 ( V_6 -> V_29 ) )
return - V_94 ;
V_170 = F_17 ( V_6 ) + V_104 ;
if ( V_170 > V_6 -> V_13 -> V_79 )
return - V_176 ;
if ( V_21 >= F_17 ( V_6 ) )
return - V_94 ;
if ( V_21 & ( V_171 - 1 ) || V_104 & ( V_171 - 1 ) )
return - V_94 ;
F_4 ( V_9 ) ;
if ( F_7 ( V_6 ) ) {
V_38 = F_98 ( V_6 ) ;
if ( V_38 )
return V_38 ;
}
V_38 = F_121 ( V_6 , F_17 ( V_6 ) , true ) ;
if ( V_38 )
return V_38 ;
V_38 = F_65 ( V_6 -> V_17 , V_21 , V_172 ) ;
if ( V_38 )
return V_38 ;
F_158 ( V_6 , V_21 ) ;
V_156 = V_21 >> V_20 ;
V_157 = ( V_21 + V_104 ) >> V_20 ;
V_174 = V_157 - V_156 ;
V_163 = ( F_17 ( V_6 ) + V_164 - 1 ) / V_164 ;
for ( V_175 = V_163 - 1 ; V_175 >= V_156 && V_175 != - 1 ; V_175 -- ) {
struct V_10 V_11 ;
struct V_5 * V_118 ;
T_4 V_165 , V_166 ;
F_8 ( V_9 ) ;
F_9 ( & V_11 , V_6 , NULL , NULL , 0 ) ;
V_38 = F_87 ( & V_11 , V_175 , V_86 ) ;
if ( V_38 && V_38 != - V_87 ) {
goto V_15;
} else if ( V_38 == - V_87 ) {
goto V_177;
} else if ( V_11 . V_106 == V_76 ) {
F_12 ( & V_11 ) ;
goto V_177;
} else {
V_165 = V_11 . V_106 ;
F_102 ( & V_11 , 1 ) ;
F_12 ( & V_11 ) ;
}
V_118 = F_124 ( V_9 , V_6 -> V_31 ) ;
if ( F_119 ( V_118 ) ) {
V_38 = F_125 ( V_118 ) ;
goto V_15;
}
F_9 ( & V_11 , V_6 , V_118 , NULL , 0 ) ;
V_38 = F_10 ( & V_11 , V_175 + V_174 ) ;
if ( V_38 )
goto V_15;
V_166 = V_11 . V_106 ;
F_6 ( V_9 , V_166 != V_75 ) ;
if ( V_165 != V_75 ) {
struct V_167 V_168 ;
F_155 ( V_9 , V_11 . V_109 , & V_168 ) ;
F_156 ( V_9 , & V_11 , V_166 , V_165 ,
V_168 . V_169 , true ) ;
}
F_12 ( & V_11 ) ;
V_177:
F_11 ( V_9 ) ;
}
F_159 ( V_6 , V_170 ) ;
return 0 ;
V_15:
F_11 ( V_9 ) ;
return V_38 ;
}
static int F_166 ( struct V_6 * V_6 , T_2 V_21 ,
T_2 V_104 , int V_148 )
{
struct V_8 * V_9 = F_3 ( V_6 ) ;
T_3 V_14 , V_156 , V_157 ;
T_2 V_170 = F_17 ( V_6 ) ;
T_2 V_158 , V_159 ;
int V_38 = 0 ;
F_4 ( V_9 ) ;
V_38 = F_161 ( V_6 , ( V_104 + V_21 ) ) ;
if ( V_38 )
return V_38 ;
if ( F_7 ( V_6 ) ) {
V_38 = F_98 ( V_6 ) ;
if ( V_38 )
return V_38 ;
}
V_156 = ( ( unsigned long long ) V_21 ) >> V_20 ;
V_157 = ( ( unsigned long long ) V_21 + V_104 ) >> V_20 ;
V_158 = V_21 & ( V_23 - 1 ) ;
V_159 = ( V_21 + V_104 ) & ( V_23 - 1 ) ;
F_8 ( V_9 ) ;
for ( V_14 = V_156 ; V_14 <= V_157 ; V_14 ++ ) {
struct V_10 V_11 ;
if ( V_14 == V_157 && ! V_159 )
goto V_178;
F_9 ( & V_11 , V_6 , NULL , NULL , 0 ) ;
V_38 = F_10 ( & V_11 , V_14 ) ;
if ( V_38 )
break;
V_178:
if ( V_156 == V_157 )
V_170 = V_21 + V_104 ;
else if ( V_14 == V_156 && V_158 )
V_170 = ( V_14 + 1 ) << V_20 ;
else if ( V_14 == V_157 )
V_170 = ( V_14 << V_20 ) + V_159 ;
else
V_170 += V_23 ;
}
if ( ! ( V_148 & V_173 ) &&
F_17 ( V_6 ) < V_170 ) {
F_159 ( V_6 , V_170 ) ;
F_134 ( V_6 ) ;
F_164 ( V_6 ) ;
}
F_11 ( V_9 ) ;
return V_38 ;
}
static long F_167 ( struct V_42 * V_42 , int V_148 ,
T_2 V_21 , T_2 V_104 )
{
struct V_6 * V_6 = F_2 ( V_42 ) ;
long V_38 = 0 ;
if ( F_96 ( V_6 ) &&
( V_148 & ( V_179 | V_180 ) ) )
return - V_160 ;
if ( V_148 & ~ ( V_173 | V_181 |
V_179 | V_182 |
V_180 ) )
return - V_160 ;
F_85 ( & V_6 -> V_83 ) ;
if ( V_148 & V_181 ) {
if ( V_21 >= V_6 -> V_183 )
goto V_15;
V_38 = F_151 ( V_6 , V_21 , V_104 ) ;
} else if ( V_148 & V_179 ) {
V_38 = F_157 ( V_6 , V_21 , V_104 ) ;
} else if ( V_148 & V_182 ) {
V_38 = F_160 ( V_6 , V_21 , V_104 , V_148 ) ;
} else if ( V_148 & V_180 ) {
V_38 = F_165 ( V_6 , V_21 , V_104 ) ;
} else {
V_38 = F_166 ( V_6 , V_21 , V_104 , V_148 ) ;
}
if ( ! V_38 ) {
V_6 -> V_122 = V_6 -> V_123 = V_124 ;
F_134 ( V_6 ) ;
}
V_15:
F_91 ( & V_6 -> V_83 ) ;
F_168 ( V_6 , V_148 , V_21 , V_104 , V_38 ) ;
return V_38 ;
}
static int F_169 ( struct V_6 * V_6 , struct V_42 * V_97 )
{
if ( F_170 ( V_6 ) )
F_171 ( V_6 , true ) ;
if ( F_172 ( V_6 ) ) {
F_64 ( F_43 ( V_6 ) , V_184 ) ;
F_173 ( V_6 -> V_17 ) ;
F_66 ( F_43 ( V_6 ) , V_184 ) ;
}
return 0 ;
}
static inline T_8 F_174 ( T_7 V_148 , T_8 V_185 )
{
if ( F_130 ( V_148 ) )
return V_185 ;
else if ( F_37 ( V_148 ) )
return V_185 & V_186 ;
else
return V_185 & V_187 ;
}
static int F_175 ( struct V_42 * V_97 , unsigned long V_188 )
{
struct V_6 * V_6 = F_2 ( V_97 ) ;
struct V_39 * V_40 = F_43 ( V_6 ) ;
unsigned int V_185 = V_40 -> V_189 & V_190 ;
return F_176 ( V_185 , ( int V_191 * ) V_188 ) ;
}
static int F_177 ( struct V_42 * V_97 , unsigned long V_188 )
{
struct V_6 * V_6 = F_2 ( V_97 ) ;
struct V_39 * V_40 = F_43 ( V_6 ) ;
unsigned int V_185 = V_40 -> V_189 & V_190 ;
unsigned int V_192 ;
int V_38 ;
V_38 = F_178 ( V_97 ) ;
if ( V_38 )
return V_38 ;
if ( ! F_179 ( V_6 ) ) {
V_38 = - V_98 ;
goto V_15;
}
if ( F_180 ( V_185 , ( int V_191 * ) V_188 ) ) {
V_38 = - V_18 ;
goto V_15;
}
V_185 = F_174 ( V_6 -> V_29 , V_185 ) ;
F_85 ( & V_6 -> V_83 ) ;
V_192 = V_40 -> V_189 ;
if ( ( V_185 ^ V_192 ) & ( V_193 | V_194 ) ) {
if ( ! F_141 ( V_195 ) ) {
F_91 ( & V_6 -> V_83 ) ;
V_38 = - V_196 ;
goto V_15;
}
}
V_185 = V_185 & V_197 ;
V_185 |= V_192 & ~ V_197 ;
V_40 -> V_189 = V_185 ;
F_91 ( & V_6 -> V_83 ) ;
F_181 ( V_6 ) ;
V_6 -> V_123 = V_124 ;
F_134 ( V_6 ) ;
V_15:
F_182 ( V_97 ) ;
return V_38 ;
}
static int F_183 ( struct V_42 * V_97 , unsigned long V_188 )
{
struct V_6 * V_6 = F_2 ( V_97 ) ;
return F_176 ( V_6 -> V_198 , ( int V_191 * ) V_188 ) ;
}
static int F_184 ( struct V_42 * V_97 )
{
struct V_6 * V_6 = F_2 ( V_97 ) ;
int V_38 ;
if ( ! F_179 ( V_6 ) )
return - V_98 ;
F_4 ( F_3 ( V_6 ) ) ;
if ( F_170 ( V_6 ) )
return 0 ;
V_38 = F_98 ( V_6 ) ;
if ( V_38 )
return V_38 ;
F_64 ( F_43 ( V_6 ) , V_199 ) ;
return 0 ;
}
static int F_185 ( struct V_42 * V_97 )
{
struct V_6 * V_6 = F_2 ( V_97 ) ;
int V_38 ;
if ( ! F_179 ( V_6 ) )
return - V_98 ;
if ( F_172 ( V_6 ) )
return 0 ;
V_38 = F_178 ( V_97 ) ;
if ( V_38 )
return V_38 ;
if ( F_170 ( V_6 ) ) {
F_66 ( F_43 ( V_6 ) , V_199 ) ;
V_38 = F_171 ( V_6 , false ) ;
if ( V_38 )
goto V_200;
}
V_38 = F_59 ( V_97 , 0 , V_172 , 0 ) ;
V_200:
F_182 ( V_97 ) ;
return V_38 ;
}
static int F_186 ( struct V_42 * V_97 )
{
struct V_6 * V_6 = F_2 ( V_97 ) ;
int V_38 ;
if ( ! F_179 ( V_6 ) )
return - V_98 ;
if ( F_172 ( V_6 ) )
return 0 ;
V_38 = F_98 ( V_6 ) ;
if ( V_38 )
return V_38 ;
F_64 ( F_43 ( V_6 ) , V_201 ) ;
return 0 ;
}
static int F_187 ( struct V_42 * V_97 )
{
struct V_6 * V_6 = F_2 ( V_97 ) ;
if ( ! F_179 ( V_6 ) )
return - V_98 ;
if ( ! F_172 ( V_6 ) )
return 0 ;
if ( ! F_188 ( V_6 ) )
return F_116 ( V_6 , 0 , true ) ;
F_151 ( V_6 , 0 , V_171 ) ;
return 0 ;
}
static int F_189 ( struct V_42 * V_97 )
{
struct V_6 * V_6 = F_2 ( V_97 ) ;
int V_38 ;
if ( ! F_179 ( V_6 ) )
return - V_98 ;
V_38 = F_178 ( V_97 ) ;
if ( V_38 )
return V_38 ;
F_4 ( F_3 ( V_6 ) ) ;
if ( F_170 ( V_6 ) ) {
F_66 ( F_43 ( V_6 ) , V_199 ) ;
F_171 ( V_6 , true ) ;
}
if ( F_172 ( V_6 ) )
F_66 ( F_43 ( V_6 ) , V_201 ) ;
F_182 ( V_97 ) ;
return V_38 ;
}
static int F_190 ( struct V_42 * V_97 , unsigned long V_188 )
{
struct V_6 * V_6 = F_2 ( V_97 ) ;
struct V_8 * V_9 = F_3 ( V_6 ) ;
struct V_202 * V_203 = V_9 -> V_203 ;
T_8 V_204 ;
if ( ! F_141 ( V_205 ) )
return - V_196 ;
if ( F_180 ( V_204 , ( T_8 V_191 * ) V_188 ) )
return - V_18 ;
switch ( V_204 ) {
case V_206 :
V_203 = F_191 ( V_203 -> V_207 ) ;
if ( V_203 && ! F_119 ( V_203 ) ) {
F_192 ( V_9 ) ;
F_193 ( V_203 -> V_207 , V_203 ) ;
}
break;
case V_208 :
F_72 ( V_203 , 1 ) ;
F_192 ( V_9 ) ;
break;
case V_209 :
F_192 ( V_9 ) ;
break;
default:
return - V_94 ;
}
return 0 ;
}
static int F_194 ( struct V_42 * V_97 , unsigned long V_188 )
{
struct V_6 * V_6 = F_2 ( V_97 ) ;
struct V_202 * V_203 = V_6 -> V_13 ;
struct V_210 * V_211 = F_195 ( V_203 -> V_207 ) ;
struct V_212 V_213 ;
int V_38 ;
if ( ! F_141 ( V_205 ) )
return - V_196 ;
if ( ! F_196 ( V_211 ) )
return - V_160 ;
if ( F_197 ( & V_213 , (struct V_212 V_191 * ) V_188 ,
sizeof( V_213 ) ) )
return - V_18 ;
V_213 . V_214 = F_198 ( ( unsigned int ) V_213 . V_214 ,
V_211 -> V_215 . V_216 ) ;
V_38 = F_199 ( F_200 ( V_203 ) , & V_213 ) ;
if ( V_38 < 0 )
return V_38 ;
if ( F_201 ( (struct V_212 V_191 * ) V_188 , & V_213 ,
sizeof( V_213 ) ) )
return - V_18 ;
return 0 ;
}
static bool F_202 ( T_9 V_217 [ 16 ] )
{
int V_37 ;
for ( V_37 = 0 ; V_37 < 16 ; V_37 ++ )
if ( V_217 [ V_37 ] )
return true ;
return false ;
}
static int F_203 ( struct V_42 * V_97 , unsigned long V_188 )
{
#ifdef F_204
struct V_218 V_219 ;
struct V_6 * V_6 = F_2 ( V_97 ) ;
if ( F_197 ( & V_219 , (struct V_218 V_191 * ) V_188 ,
sizeof( V_219 ) ) )
return - V_18 ;
return F_205 ( & V_219 , V_6 ) ;
#else
return - V_160 ;
#endif
}
static int F_206 ( struct V_42 * V_97 , unsigned long V_188 )
{
#ifdef F_204
struct V_218 V_219 ;
struct V_6 * V_6 = F_2 ( V_97 ) ;
int V_12 ;
V_12 = F_207 ( V_6 , & V_219 ) ;
if ( V_12 )
return V_12 ;
if ( F_201 ( (struct V_218 V_191 * ) V_188 , & V_219 ,
sizeof( V_219 ) ) )
return - V_18 ;
return 0 ;
#else
return - V_160 ;
#endif
}
static int F_208 ( struct V_42 * V_97 , unsigned long V_188 )
{
struct V_6 * V_6 = F_2 ( V_97 ) ;
struct V_8 * V_9 = F_3 ( V_6 ) ;
int V_12 ;
if ( ! F_209 ( V_6 -> V_13 ) )
return - V_160 ;
if ( F_202 ( V_9 -> V_220 -> V_221 ) )
goto V_222;
V_12 = F_178 ( V_97 ) ;
if ( V_12 )
return V_12 ;
F_210 ( V_9 -> V_220 -> V_221 ) ;
V_12 = F_211 ( V_9 , false ) ;
F_182 ( V_97 ) ;
if ( V_12 ) {
memset ( V_9 -> V_220 -> V_221 , 0 , 16 ) ;
return V_12 ;
}
V_222:
if ( F_201 ( ( T_9 V_191 * ) V_188 , V_9 -> V_220 -> V_221 ,
16 ) )
return - V_18 ;
return 0 ;
}
static int F_212 ( struct V_42 * V_97 , unsigned long V_188 )
{
struct V_6 * V_6 = F_2 ( V_97 ) ;
struct V_8 * V_9 = F_3 ( V_6 ) ;
T_8 V_37 , V_99 ;
if ( ! F_141 ( V_205 ) )
return - V_196 ;
if ( F_180 ( V_99 , ( T_8 V_191 * ) V_188 ) )
return - V_18 ;
if ( ! V_99 || V_99 > V_223 )
return - V_94 ;
for ( V_37 = 0 ; V_37 < V_99 ; V_37 ++ ) {
if ( ! F_213 ( & V_9 -> V_224 ) )
break;
if ( F_214 ( V_9 ) )
break;
}
if ( F_176 ( V_37 , ( T_8 V_191 * ) V_188 ) )
return - V_18 ;
return 0 ;
}
long F_215 ( struct V_42 * V_97 , unsigned int V_225 , unsigned long V_188 )
{
switch ( V_225 ) {
case V_226 :
return F_175 ( V_97 , V_188 ) ;
case V_227 :
return F_177 ( V_97 , V_188 ) ;
case V_228 :
return F_183 ( V_97 , V_188 ) ;
case V_229 :
return F_184 ( V_97 ) ;
case V_230 :
return F_185 ( V_97 ) ;
case V_231 :
return F_186 ( V_97 ) ;
case V_232 :
return F_187 ( V_97 ) ;
case V_233 :
return F_189 ( V_97 ) ;
case V_234 :
return F_190 ( V_97 , V_188 ) ;
case V_235 :
return F_194 ( V_97 , V_188 ) ;
case V_236 :
return F_203 ( V_97 , V_188 ) ;
case V_237 :
return F_206 ( V_97 , V_188 ) ;
case V_238 :
return F_208 ( V_97 , V_188 ) ;
case V_239 :
return F_212 ( V_97 , V_188 ) ;
default:
return - V_240 ;
}
}
static T_10 F_216 ( struct V_241 * V_242 , struct V_243 * V_111 )
{
struct V_6 * V_6 = F_2 ( V_242 -> V_244 ) ;
if ( F_96 ( V_6 ) &&
! F_217 ( V_6 ) &&
F_97 ( V_6 ) )
return - V_98 ;
return F_218 ( V_242 , V_111 ) ;
}
long F_219 ( struct V_42 * V_42 , unsigned int V_225 , unsigned long V_188 )
{
switch ( V_225 ) {
case V_245 :
V_225 = V_226 ;
break;
case V_246 :
V_225 = V_227 ;
break;
default:
return - V_247 ;
}
return F_215 ( V_42 , V_225 , ( unsigned long ) F_220 ( V_188 ) ) ;
}
