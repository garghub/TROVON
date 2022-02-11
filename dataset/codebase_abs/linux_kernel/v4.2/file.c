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
V_15:
F_26 ( V_6 -> V_13 ) ;
return F_27 ( V_12 ) ;
}
static int F_28 ( struct V_6 * V_6 , T_1 * V_25 )
{
struct V_26 * V_26 ;
V_6 = F_29 ( V_6 ) ;
V_26 = F_30 ( V_6 ) ;
F_31 ( V_6 ) ;
if ( ! V_26 )
return 0 ;
if ( F_32 ( V_6 , V_6 , & V_26 -> V_27 ) ) {
F_33 ( V_26 ) ;
return 0 ;
}
* V_25 = F_34 ( V_26 ) ;
F_33 ( V_26 ) ;
return 1 ;
}
static inline bool F_35 ( struct V_6 * V_6 )
{
struct V_8 * V_9 = F_3 ( V_6 ) ;
bool V_28 = false ;
if ( ! F_36 ( V_6 -> V_29 ) || V_6 -> V_30 != 1 )
V_28 = true ;
else if ( F_37 ( V_6 ) && F_38 ( V_9 , V_6 -> V_31 ) )
V_28 = true ;
else if ( F_39 ( V_6 ) )
V_28 = true ;
else if ( ! F_40 ( V_9 ) )
V_28 = true ;
else if ( ! F_41 ( V_9 , F_42 ( V_6 ) -> V_32 ) )
V_28 = true ;
else if ( F_42 ( V_6 ) -> V_33 == F_43 ( F_44 ( V_9 ) ) )
V_28 = true ;
else if ( F_45 ( V_9 , V_34 ) )
V_28 = true ;
else if ( V_9 -> V_35 == 2 )
V_28 = true ;
return V_28 ;
}
static bool F_46 ( struct V_8 * V_9 , T_1 V_36 )
{
struct V_5 * V_37 = F_47 ( F_48 ( V_9 ) , V_36 ) ;
bool V_38 = false ;
if ( ( V_37 && F_49 ( V_37 ) ) || F_50 ( V_9 , V_36 ) )
V_38 = true ;
F_51 ( V_37 , 0 ) ;
return V_38 ;
}
static void F_52 ( struct V_6 * V_6 )
{
struct V_39 * V_40 = F_42 ( V_6 ) ;
T_1 V_25 ;
F_53 ( & V_40 -> V_41 ) ;
V_40 -> V_33 = 0 ;
if ( F_39 ( V_6 ) && V_6 -> V_30 == 1 &&
F_28 ( V_6 , & V_25 ) ) {
V_40 -> V_32 = V_25 ;
F_54 ( V_6 ) ;
F_55 ( & V_40 -> V_41 ) ;
F_56 ( V_6 ) ;
F_57 ( V_6 , NULL ) ;
} else {
F_55 ( & V_40 -> V_41 ) ;
}
}
int F_58 ( struct V_42 * V_42 , T_2 V_43 , T_2 V_44 , int V_45 )
{
struct V_6 * V_6 = V_42 -> V_46 -> V_47 ;
struct V_39 * V_40 = F_42 ( V_6 ) ;
struct V_8 * V_9 = F_3 ( V_6 ) ;
T_1 V_36 = V_6 -> V_31 ;
int V_38 = 0 ;
bool V_28 = false ;
struct V_48 V_49 = {
. V_50 = V_51 ,
. V_52 = V_53 ,
. V_54 = 0 ,
} ;
if ( F_15 ( F_59 ( V_6 -> V_13 ) ) )
return 0 ;
F_60 ( V_6 ) ;
if ( F_61 ( V_6 ) <= F_62 ( V_9 ) -> V_55 )
F_63 ( V_40 , V_56 ) ;
V_38 = F_64 ( V_6 -> V_17 , V_43 , V_44 ) ;
F_65 ( V_40 , V_56 ) ;
if ( V_38 ) {
F_66 ( V_6 , V_28 , V_45 , V_38 ) ;
return V_38 ;
}
if ( ! V_45 && F_67 ( V_40 , V_57 ) ) {
F_68 ( V_6 ) ;
goto V_58;
}
if ( ! F_67 ( V_40 , V_59 ) &&
! F_69 ( V_9 , V_36 , V_60 ) ) {
if ( F_46 ( V_9 , V_36 ) )
goto V_58;
if ( F_67 ( V_40 , V_61 ) ||
F_69 ( V_9 , V_36 , V_62 ) )
goto V_63;
goto V_15;
}
V_58:
F_4 ( V_9 ) ;
F_70 ( & V_40 -> V_41 ) ;
V_28 = F_35 ( V_6 ) ;
F_71 ( & V_40 -> V_41 ) ;
if ( V_28 ) {
V_38 = F_72 ( V_6 -> V_13 , 1 ) ;
F_52 ( V_6 ) ;
F_65 ( V_40 , V_59 ) ;
F_65 ( V_40 , V_61 ) ;
goto V_15;
}
V_64:
F_73 ( V_9 , V_36 , & V_49 ) ;
if ( F_15 ( F_74 ( V_9 ) ) )
goto V_15;
if ( F_50 ( V_9 , V_36 ) ) {
F_56 ( V_6 ) ;
F_57 ( V_6 , NULL ) ;
goto V_64;
}
V_38 = F_75 ( V_9 , V_36 ) ;
if ( V_38 )
goto V_15;
F_76 ( V_9 , V_36 , V_60 ) ;
F_65 ( V_40 , V_59 ) ;
V_63:
F_76 ( V_9 , V_36 , V_62 ) ;
F_65 ( V_40 , V_61 ) ;
V_38 = F_77 ( V_9 ) ;
V_15:
F_66 ( V_6 , V_28 , V_45 , V_38 ) ;
F_78 ( NULL , 1 ) ;
return V_38 ;
}
static T_3 F_79 ( struct V_65 * V_16 ,
T_3 V_66 , int V_67 )
{
struct V_68 V_69 ;
int V_70 ;
if ( V_67 != V_71 )
return 0 ;
F_80 ( & V_69 , 0 ) ;
V_70 = F_81 ( & V_69 , V_16 , & V_66 ,
V_72 , 1 ) ;
V_66 = V_70 ? V_69 . V_73 [ 0 ] -> V_14 : V_53 ;
F_82 ( & V_69 ) ;
return V_66 ;
}
static bool F_83 ( T_4 V_74 , T_3 V_75 , T_3 V_66 ,
int V_67 )
{
switch ( V_67 ) {
case V_71 :
if ( ( V_74 == V_76 && V_75 == V_66 ) ||
( V_74 != V_76 && V_74 != V_77 ) )
return true ;
break;
case V_78 :
if ( V_74 == V_77 )
return true ;
break;
}
return false ;
}
static T_2 F_84 ( struct V_42 * V_42 , T_2 V_21 , int V_67 )
{
struct V_6 * V_6 = V_42 -> V_46 -> V_47 ;
T_2 V_79 = V_6 -> V_13 -> V_80 ;
struct V_10 V_11 ;
T_3 V_66 , V_81 , V_75 ;
T_2 V_82 = V_21 ;
T_2 V_83 ;
int V_12 = 0 ;
F_85 ( & V_6 -> V_84 ) ;
V_83 = F_17 ( V_6 ) ;
if ( V_21 >= V_83 )
goto V_85;
if ( F_7 ( V_6 ) || F_86 ( V_6 ) ) {
if ( V_67 == V_78 )
V_82 = V_83 ;
goto V_86;
}
V_66 = ( T_3 ) ( V_21 >> V_20 ) ;
V_75 = F_79 ( V_6 -> V_17 , V_66 , V_67 ) ;
for (; V_82 < V_83 ; V_82 = V_66 << V_20 ) {
F_9 ( & V_11 , V_6 , NULL , NULL , 0 ) ;
V_12 = F_87 ( & V_11 , V_66 , V_87 ) ;
if ( V_12 && V_12 != - V_88 ) {
goto V_85;
} else if ( V_12 == - V_88 ) {
if ( V_67 == V_71 ) {
V_66 = F_88 ( V_66 ,
F_42 ( V_6 ) ) ;
continue;
} else {
goto V_86;
}
}
V_81 = F_89 ( V_11 . V_89 , F_42 ( V_6 ) ) ;
for (; V_11 . V_90 < V_81 ;
V_11 . V_90 ++ , V_66 ++ ,
V_82 = ( T_2 ) V_66 << V_20 ) {
T_4 V_74 ;
V_74 = F_90 ( V_11 . V_89 , V_11 . V_90 ) ;
if ( F_83 ( V_74 , V_75 , V_66 , V_67 ) ) {
F_12 ( & V_11 ) ;
goto V_86;
}
}
F_12 ( & V_11 ) ;
}
if ( V_67 == V_71 )
goto V_85;
V_86:
if ( V_67 == V_78 && V_82 > V_83 )
V_82 = V_83 ;
F_91 ( & V_6 -> V_84 ) ;
return F_92 ( V_42 , V_82 , V_79 ) ;
V_85:
F_91 ( & V_6 -> V_84 ) ;
return - V_91 ;
}
static T_2 F_93 ( struct V_42 * V_42 , T_2 V_21 , int V_67 )
{
struct V_6 * V_6 = V_42 -> V_46 -> V_47 ;
T_2 V_79 = V_6 -> V_13 -> V_80 ;
switch ( V_67 ) {
case V_92 :
case V_93 :
case V_94 :
return F_94 ( V_42 , V_21 , V_67 ,
V_79 , F_17 ( V_6 ) ) ;
case V_71 :
case V_78 :
if ( V_21 < 0 )
return - V_91 ;
return F_84 ( V_42 , V_21 , V_67 ) ;
}
return - V_95 ;
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
V_2 -> V_96 = & V_97 ;
return 0 ;
}
static int F_100 ( struct V_6 * V_6 , struct V_42 * V_98 )
{
int V_38 = F_101 ( V_6 , V_98 ) ;
if ( ! V_38 && F_96 ( V_6 ) ) {
V_38 = F_97 ( V_6 ) ;
if ( V_38 )
V_38 = - V_99 ;
}
return V_38 ;
}
int F_102 ( struct V_10 * V_11 , int V_100 )
{
int V_101 = 0 , V_102 = V_11 -> V_90 ;
struct V_8 * V_9 = F_3 ( V_11 -> V_6 ) ;
struct V_103 * V_104 ;
T_5 * V_105 ;
V_104 = F_103 ( V_11 -> V_89 ) ;
V_105 = F_104 ( V_104 ) + V_102 ;
for (; V_100 > 0 ; V_100 -- , V_105 ++ , V_11 -> V_90 ++ ) {
T_4 V_74 = F_105 ( * V_105 ) ;
if ( V_74 == V_77 )
continue;
V_11 -> V_106 = V_77 ;
F_106 ( V_11 ) ;
F_107 ( V_11 ) ;
F_108 ( V_9 , V_74 ) ;
if ( V_11 -> V_90 == 0 && F_109 ( V_11 -> V_89 ) )
F_65 ( F_42 ( V_11 -> V_6 ) ,
V_107 ) ;
V_101 ++ ;
}
if ( V_101 ) {
F_110 ( V_9 , V_11 -> V_6 , V_101 ) ;
F_22 ( V_11 -> V_89 ) ;
F_111 ( V_11 ) ;
}
V_11 -> V_90 = V_102 ;
F_112 ( V_11 -> V_6 , V_11 -> V_108 ,
V_11 -> V_90 , V_101 ) ;
return V_101 ;
}
void F_113 ( struct V_10 * V_11 )
{
F_102 ( V_11 , V_109 ) ;
}
static int F_114 ( struct V_6 * V_6 , T_6 V_110 ,
bool V_111 )
{
unsigned V_21 = V_110 & ( V_23 - 1 ) ;
T_3 V_14 = V_110 >> V_20 ;
struct V_65 * V_16 = V_6 -> V_17 ;
struct V_5 * V_5 ;
if ( ! V_21 && ! V_111 )
return 0 ;
if ( V_111 ) {
V_5 = F_115 ( V_16 , V_14 ) ;
if ( V_5 && F_18 ( V_5 ) )
goto V_112;
F_51 ( V_5 , 1 ) ;
return 0 ;
}
V_5 = F_116 ( V_6 , V_14 ) ;
if ( F_117 ( V_5 ) )
return 0 ;
V_112:
F_25 ( V_5 , V_24 ) ;
F_118 ( V_5 , V_21 , V_23 - V_21 ) ;
if ( ! V_111 || ! F_96 ( V_6 ) || ! F_36 ( V_6 -> V_29 ) )
F_22 ( V_5 ) ;
F_51 ( V_5 , 1 ) ;
return 0 ;
}
int F_119 ( struct V_6 * V_6 , T_6 V_110 , bool V_113 )
{
struct V_8 * V_9 = F_3 ( V_6 ) ;
unsigned int V_114 = V_6 -> V_13 -> V_115 ;
struct V_10 V_11 ;
T_3 V_116 ;
int V_100 = 0 , V_12 = 0 ;
struct V_5 * V_117 ;
bool V_118 = false ;
F_120 ( V_6 , V_110 ) ;
V_116 = ( T_3 ) F_121 ( V_110 + V_114 - 1 ) ;
if ( V_113 )
F_8 ( V_9 ) ;
V_117 = F_122 ( V_9 , V_6 -> V_31 ) ;
if ( F_117 ( V_117 ) ) {
V_12 = F_123 ( V_117 ) ;
goto V_15;
}
if ( F_7 ( V_6 ) ) {
if ( F_124 ( V_117 , V_110 ) )
F_22 ( V_117 ) ;
F_51 ( V_117 , 1 ) ;
V_118 = true ;
goto V_15;
}
F_9 ( & V_11 , V_6 , V_117 , NULL , 0 ) ;
V_12 = F_87 ( & V_11 , V_116 , V_119 ) ;
if ( V_12 ) {
if ( V_12 == - V_88 )
goto V_120;
goto V_15;
}
V_100 = F_89 ( V_11 . V_89 , F_42 ( V_6 ) ) ;
V_100 -= V_11 . V_90 ;
F_6 ( V_9 , V_100 < 0 ) ;
if ( V_11 . V_90 || F_109 ( V_11 . V_89 ) ) {
F_102 ( & V_11 , V_100 ) ;
V_116 += V_100 ;
}
F_12 ( & V_11 ) ;
V_120:
V_12 = F_125 ( V_6 , V_116 ) ;
V_15:
if ( V_113 )
F_11 ( V_9 ) ;
if ( ! V_12 )
V_12 = F_114 ( V_6 , V_110 , V_118 ) ;
F_126 ( V_6 , V_12 ) ;
return V_12 ;
}
void F_127 ( struct V_6 * V_6 )
{
if ( ! ( F_36 ( V_6 -> V_29 ) || F_128 ( V_6 -> V_29 ) ||
F_129 ( V_6 -> V_29 ) ) )
return;
F_130 ( V_6 ) ;
if ( F_7 ( V_6 ) && ! F_131 ( V_6 ) ) {
if ( F_98 ( V_6 ) )
return;
}
if ( ! F_119 ( V_6 , F_17 ( V_6 ) , true ) ) {
V_6 -> V_121 = V_6 -> V_122 = V_123 ;
F_132 ( V_6 ) ;
}
}
int F_133 ( struct V_124 * V_125 ,
struct V_26 * V_26 , struct V_126 * V_127 )
{
struct V_6 * V_6 = F_134 ( V_26 ) ;
F_135 ( V_6 , V_127 ) ;
V_127 -> V_128 <<= 3 ;
return 0 ;
}
static void F_136 ( struct V_6 * V_6 , const struct V_129 * V_130 )
{
struct V_39 * V_40 = F_42 ( V_6 ) ;
unsigned int V_131 = V_130 -> V_131 ;
if ( V_131 & V_132 )
V_6 -> V_133 = V_130 -> V_134 ;
if ( V_131 & V_135 )
V_6 -> V_136 = V_130 -> V_137 ;
if ( V_131 & V_138 )
V_6 -> V_139 = F_137 ( V_130 -> V_140 ,
V_6 -> V_13 -> V_141 ) ;
if ( V_131 & V_142 )
V_6 -> V_121 = F_137 ( V_130 -> V_143 ,
V_6 -> V_13 -> V_141 ) ;
if ( V_131 & V_144 )
V_6 -> V_122 = F_137 ( V_130 -> V_145 ,
V_6 -> V_13 -> V_141 ) ;
if ( V_131 & V_146 ) {
T_7 V_147 = V_130 -> V_148 ;
if ( ! F_138 ( V_6 -> V_136 ) && ! F_139 ( V_149 ) )
V_147 &= ~ V_150 ;
F_140 ( V_40 , V_147 ) ;
}
}
int F_141 ( struct V_26 * V_26 , struct V_129 * V_130 )
{
struct V_6 * V_6 = F_134 ( V_26 ) ;
struct V_39 * V_40 = F_42 ( V_6 ) ;
int V_12 ;
V_12 = F_142 ( V_6 , V_130 ) ;
if ( V_12 )
return V_12 ;
if ( V_130 -> V_131 & V_151 ) {
if ( F_96 ( V_6 ) &&
F_97 ( V_6 ) )
return - V_99 ;
if ( V_130 -> V_152 <= F_17 ( V_6 ) ) {
F_143 ( V_6 , V_130 -> V_152 ) ;
F_127 ( V_6 ) ;
F_4 ( F_3 ( V_6 ) ) ;
} else {
F_143 ( V_6 , V_130 -> V_152 ) ;
}
}
F_136 ( V_6 , V_130 ) ;
if ( V_130 -> V_131 & V_146 ) {
V_12 = F_144 ( V_6 , F_145 ( V_6 ) ) ;
if ( V_12 || F_67 ( V_40 , V_153 ) ) {
V_6 -> V_29 = V_40 -> V_154 ;
F_65 ( V_40 , V_153 ) ;
}
}
F_132 ( V_6 ) ;
return V_12 ;
}
static void F_146 ( struct V_6 * V_6 , T_3 V_14 ,
T_2 V_43 , T_2 V_155 )
{
struct V_8 * V_9 = F_3 ( V_6 ) ;
struct V_5 * V_5 ;
if ( ! V_155 )
return;
F_4 ( V_9 ) ;
F_8 ( V_9 ) ;
V_5 = F_147 ( V_6 , NULL , V_14 , false ) ;
F_11 ( V_9 ) ;
if ( ! F_117 ( V_5 ) ) {
F_25 ( V_5 , V_24 ) ;
F_118 ( V_5 , V_43 , V_155 ) ;
F_22 ( V_5 ) ;
F_51 ( V_5 , 1 ) ;
}
}
int F_148 ( struct V_6 * V_6 , T_3 V_156 , T_3 V_157 )
{
T_3 V_14 ;
int V_12 ;
for ( V_14 = V_156 ; V_14 < V_157 ; V_14 ++ ) {
struct V_10 V_11 ;
F_9 ( & V_11 , V_6 , NULL , NULL , 0 ) ;
V_12 = F_87 ( & V_11 , V_14 , V_119 ) ;
if ( V_12 ) {
if ( V_12 == - V_88 )
continue;
return V_12 ;
}
if ( V_11 . V_106 != V_77 )
F_102 ( & V_11 , 1 ) ;
F_12 ( & V_11 ) ;
}
return 0 ;
}
static int F_149 ( struct V_6 * V_6 , T_2 V_21 , T_2 V_155 )
{
T_3 V_156 , V_157 ;
T_2 V_158 , V_159 ;
int V_38 = 0 ;
if ( ! F_36 ( V_6 -> V_29 ) )
return - V_160 ;
if ( F_7 ( V_6 ) ) {
V_38 = F_98 ( V_6 ) ;
if ( V_38 )
return V_38 ;
}
V_156 = ( ( unsigned long long ) V_21 ) >> V_20 ;
V_157 = ( ( unsigned long long ) V_21 + V_155 ) >> V_20 ;
V_158 = V_21 & ( V_23 - 1 ) ;
V_159 = ( V_21 + V_155 ) & ( V_23 - 1 ) ;
if ( V_156 == V_157 ) {
F_146 ( V_6 , V_156 , V_158 ,
V_159 - V_158 ) ;
} else {
if ( V_158 )
F_146 ( V_6 , V_156 ++ , V_158 ,
V_23 - V_158 ) ;
if ( V_159 )
F_146 ( V_6 , V_157 , 0 , V_159 ) ;
if ( V_156 < V_157 ) {
struct V_65 * V_16 = V_6 -> V_17 ;
T_2 V_161 , V_162 ;
struct V_8 * V_9 = F_3 ( V_6 ) ;
F_4 ( V_9 ) ;
V_161 = V_156 << V_20 ;
V_162 = V_157 << V_20 ;
F_150 ( V_16 , V_161 ,
V_162 - 1 ) ;
F_8 ( V_9 ) ;
V_38 = F_148 ( V_6 , V_156 , V_157 ) ;
F_11 ( V_9 ) ;
}
}
return V_38 ;
}
static int F_151 ( struct V_6 * V_6 , T_3 V_43 , T_3 V_44 )
{
struct V_8 * V_9 = F_3 ( V_6 ) ;
struct V_10 V_11 ;
T_3 V_163 = ( F_17 ( V_6 ) + V_164 - 1 ) / V_164 ;
int V_38 = 0 ;
F_8 ( V_9 ) ;
for (; V_44 < V_163 ; V_43 ++ , V_44 ++ ) {
T_4 V_165 , V_166 ;
F_9 ( & V_11 , V_6 , NULL , NULL , 0 ) ;
V_38 = F_87 ( & V_11 , V_44 , V_87 ) ;
if ( V_38 && V_38 != - V_88 ) {
goto V_15;
} else if ( V_38 == - V_88 ) {
V_165 = V_77 ;
} else {
V_165 = V_11 . V_106 ;
F_102 ( & V_11 , 1 ) ;
F_12 ( & V_11 ) ;
}
if ( V_165 == V_77 ) {
F_9 ( & V_11 , V_6 , NULL , NULL , 0 ) ;
V_38 = F_87 ( & V_11 , V_43 , V_87 ) ;
if ( V_38 && V_38 != - V_88 )
goto V_15;
else if ( V_38 == - V_88 )
continue;
if ( V_11 . V_106 == V_77 ) {
F_12 ( & V_11 ) ;
continue;
} else {
F_102 ( & V_11 , 1 ) ;
}
F_12 ( & V_11 ) ;
} else {
struct V_5 * V_117 ;
V_117 = F_122 ( V_9 , V_6 -> V_31 ) ;
if ( F_117 ( V_117 ) ) {
V_38 = F_123 ( V_117 ) ;
goto V_15;
}
F_9 ( & V_11 , V_6 , V_117 , NULL , 0 ) ;
V_38 = F_10 ( & V_11 , V_43 ) ;
if ( V_38 )
goto V_15;
V_166 = V_11 . V_106 ;
if ( V_166 != V_76 && V_165 == V_76 ) {
V_11 . V_106 = V_77 ;
F_107 ( & V_11 ) ;
F_108 ( V_9 , V_166 ) ;
V_11 . V_106 = V_165 ;
F_106 ( & V_11 ) ;
} else if ( V_165 != V_76 ) {
struct V_167 V_168 ;
F_152 ( V_9 , V_11 . V_108 , & V_168 ) ;
F_153 ( V_9 , & V_11 , V_166 , V_165 ,
V_168 . V_169 , true ) ;
}
F_12 ( & V_11 ) ;
}
}
V_38 = 0 ;
V_15:
F_11 ( V_9 ) ;
return V_38 ;
}
static int F_154 ( struct V_6 * V_6 , T_2 V_21 , T_2 V_155 )
{
T_3 V_156 , V_157 ;
T_2 V_170 ;
int V_38 ;
if ( ! F_36 ( V_6 -> V_29 ) )
return - V_95 ;
if ( V_21 + V_155 >= F_17 ( V_6 ) )
return - V_95 ;
if ( V_21 & ( V_171 - 1 ) || V_155 & ( V_171 - 1 ) )
return - V_95 ;
V_156 = V_21 >> V_20 ;
V_157 = ( V_21 + V_155 ) >> V_20 ;
V_38 = F_64 ( V_6 -> V_17 , V_21 , V_172 ) ;
if ( V_38 )
return V_38 ;
F_155 ( V_6 , V_21 ) ;
V_38 = F_151 ( V_6 , V_156 , V_157 ) ;
if ( V_38 )
return V_38 ;
V_170 = F_17 ( V_6 ) - V_155 ;
V_38 = F_119 ( V_6 , V_170 , true ) ;
if ( ! V_38 )
F_156 ( V_6 , V_170 ) ;
return V_38 ;
}
static int F_157 ( struct V_6 * V_6 , T_2 V_21 , T_2 V_155 ,
int V_147 )
{
struct V_8 * V_9 = F_3 ( V_6 ) ;
struct V_65 * V_16 = V_6 -> V_17 ;
T_3 V_14 , V_156 , V_157 ;
T_2 V_170 = F_17 ( V_6 ) ;
T_2 V_158 , V_159 ;
int V_38 = 0 ;
if ( ! F_36 ( V_6 -> V_29 ) )
return - V_95 ;
V_38 = F_158 ( V_6 , ( V_155 + V_21 ) ) ;
if ( V_38 )
return V_38 ;
F_4 ( V_9 ) ;
if ( F_7 ( V_6 ) ) {
V_38 = F_98 ( V_6 ) ;
if ( V_38 )
return V_38 ;
}
V_38 = F_64 ( V_16 , V_21 , V_21 + V_155 - 1 ) ;
if ( V_38 )
return V_38 ;
F_159 ( V_6 , V_21 , V_21 + V_155 - 1 ) ;
V_156 = ( ( unsigned long long ) V_21 ) >> V_20 ;
V_157 = ( ( unsigned long long ) V_21 + V_155 ) >> V_20 ;
V_158 = V_21 & ( V_23 - 1 ) ;
V_159 = ( V_21 + V_155 ) & ( V_23 - 1 ) ;
if ( V_156 == V_157 ) {
F_146 ( V_6 , V_156 , V_158 , V_159 - V_158 ) ;
if ( V_21 + V_155 > V_170 )
V_170 = V_21 + V_155 ;
V_170 = F_160 ( T_2 , V_170 , V_21 + V_155 ) ;
} else {
if ( V_158 ) {
F_146 ( V_6 , V_156 ++ , V_158 ,
V_23 - V_158 ) ;
V_170 = F_160 ( T_2 , V_170 ,
V_156 << V_20 ) ;
}
for ( V_14 = V_156 ; V_14 < V_157 ; V_14 ++ ) {
struct V_10 V_11 ;
struct V_5 * V_117 ;
F_8 ( V_9 ) ;
V_117 = F_122 ( V_9 , V_6 -> V_31 ) ;
if ( F_117 ( V_117 ) ) {
V_38 = F_123 ( V_117 ) ;
F_11 ( V_9 ) ;
goto V_15;
}
F_9 ( & V_11 , V_6 , V_117 , NULL , 0 ) ;
V_38 = F_10 ( & V_11 , V_14 ) ;
if ( V_38 ) {
F_11 ( V_9 ) ;
goto V_15;
}
if ( V_11 . V_106 != V_76 ) {
F_108 ( V_9 , V_11 . V_106 ) ;
V_11 . V_106 = V_76 ;
F_106 ( & V_11 ) ;
V_11 . V_106 = V_77 ;
F_107 ( & V_11 ) ;
}
F_12 ( & V_11 ) ;
F_11 ( V_9 ) ;
V_170 = F_160 ( T_2 , V_170 ,
( V_14 + 1 ) << V_20 ) ;
}
if ( V_159 ) {
F_146 ( V_6 , V_157 , 0 , V_159 ) ;
V_170 = F_160 ( T_2 , V_170 , V_21 + V_155 ) ;
}
}
V_15:
if ( ! ( V_147 & V_173 ) && F_17 ( V_6 ) < V_170 ) {
F_156 ( V_6 , V_170 ) ;
F_132 ( V_6 ) ;
F_68 ( V_6 ) ;
}
return V_38 ;
}
static int F_161 ( struct V_6 * V_6 , T_2 V_21 , T_2 V_155 )
{
struct V_8 * V_9 = F_3 ( V_6 ) ;
T_3 V_156 , V_157 , V_174 , V_163 , V_175 ;
T_2 V_170 ;
int V_38 ;
if ( ! F_36 ( V_6 -> V_29 ) )
return - V_95 ;
V_170 = F_17 ( V_6 ) + V_155 ;
if ( V_170 > V_6 -> V_13 -> V_80 )
return - V_176 ;
if ( V_21 >= F_17 ( V_6 ) )
return - V_95 ;
if ( V_21 & ( V_171 - 1 ) || V_155 & ( V_171 - 1 ) )
return - V_95 ;
F_4 ( V_9 ) ;
V_38 = F_119 ( V_6 , F_17 ( V_6 ) , true ) ;
if ( V_38 )
return V_38 ;
V_38 = F_64 ( V_6 -> V_17 , V_21 , V_172 ) ;
if ( V_38 )
return V_38 ;
F_155 ( V_6 , V_21 ) ;
V_156 = V_21 >> V_20 ;
V_157 = ( V_21 + V_155 ) >> V_20 ;
V_174 = V_157 - V_156 ;
V_163 = ( F_17 ( V_6 ) + V_164 - 1 ) / V_164 ;
for ( V_175 = V_163 - 1 ; V_175 >= V_156 && V_175 != - 1 ; V_175 -- ) {
struct V_10 V_11 ;
struct V_5 * V_117 ;
T_4 V_165 , V_166 ;
F_8 ( V_9 ) ;
F_9 ( & V_11 , V_6 , NULL , NULL , 0 ) ;
V_38 = F_87 ( & V_11 , V_175 , V_87 ) ;
if ( V_38 && V_38 != - V_88 ) {
goto V_15;
} else if ( V_38 == - V_88 ) {
goto V_177;
} else if ( V_11 . V_106 == V_77 ) {
F_12 ( & V_11 ) ;
goto V_177;
} else {
V_165 = V_11 . V_106 ;
F_102 ( & V_11 , 1 ) ;
F_12 ( & V_11 ) ;
}
V_117 = F_122 ( V_9 , V_6 -> V_31 ) ;
if ( F_117 ( V_117 ) ) {
V_38 = F_123 ( V_117 ) ;
goto V_15;
}
F_9 ( & V_11 , V_6 , V_117 , NULL , 0 ) ;
V_38 = F_10 ( & V_11 , V_175 + V_174 ) ;
if ( V_38 )
goto V_15;
V_166 = V_11 . V_106 ;
F_6 ( V_9 , V_166 != V_76 ) ;
if ( V_165 != V_76 ) {
struct V_167 V_168 ;
F_152 ( V_9 , V_11 . V_108 , & V_168 ) ;
F_153 ( V_9 , & V_11 , V_166 , V_165 ,
V_168 . V_169 , true ) ;
}
F_12 ( & V_11 ) ;
V_177:
F_11 ( V_9 ) ;
}
F_156 ( V_6 , V_170 ) ;
return 0 ;
V_15:
F_11 ( V_9 ) ;
return V_38 ;
}
static int F_162 ( struct V_6 * V_6 , T_2 V_21 ,
T_2 V_155 , int V_147 )
{
struct V_8 * V_9 = F_3 ( V_6 ) ;
T_3 V_14 , V_156 , V_157 ;
T_2 V_170 = F_17 ( V_6 ) ;
T_2 V_158 , V_159 ;
int V_38 = 0 ;
F_4 ( V_9 ) ;
V_38 = F_158 ( V_6 , ( V_155 + V_21 ) ) ;
if ( V_38 )
return V_38 ;
if ( F_7 ( V_6 ) ) {
V_38 = F_98 ( V_6 ) ;
if ( V_38 )
return V_38 ;
}
V_156 = ( ( unsigned long long ) V_21 ) >> V_20 ;
V_157 = ( ( unsigned long long ) V_21 + V_155 ) >> V_20 ;
V_158 = V_21 & ( V_23 - 1 ) ;
V_159 = ( V_21 + V_155 ) & ( V_23 - 1 ) ;
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
V_170 = V_21 + V_155 ;
else if ( V_14 == V_156 && V_158 )
V_170 = ( V_14 + 1 ) << V_20 ;
else if ( V_14 == V_157 )
V_170 = ( V_14 << V_20 ) + V_159 ;
else
V_170 += V_23 ;
}
if ( ! ( V_147 & V_173 ) &&
F_17 ( V_6 ) < V_170 ) {
F_156 ( V_6 , V_170 ) ;
F_132 ( V_6 ) ;
F_68 ( V_6 ) ;
}
F_11 ( V_9 ) ;
return V_38 ;
}
static long F_163 ( struct V_42 * V_42 , int V_147 ,
T_2 V_21 , T_2 V_155 )
{
struct V_6 * V_6 = F_2 ( V_42 ) ;
long V_38 = 0 ;
if ( F_96 ( V_6 ) &&
( V_147 & ( V_179 | V_180 ) ) )
return - V_160 ;
if ( V_147 & ~ ( V_173 | V_181 |
V_179 | V_182 |
V_180 ) )
return - V_160 ;
F_85 ( & V_6 -> V_84 ) ;
if ( V_147 & V_181 ) {
if ( V_21 >= V_6 -> V_183 )
goto V_15;
V_38 = F_149 ( V_6 , V_21 , V_155 ) ;
} else if ( V_147 & V_179 ) {
V_38 = F_154 ( V_6 , V_21 , V_155 ) ;
} else if ( V_147 & V_182 ) {
V_38 = F_157 ( V_6 , V_21 , V_155 , V_147 ) ;
} else if ( V_147 & V_180 ) {
V_38 = F_161 ( V_6 , V_21 , V_155 ) ;
} else {
V_38 = F_162 ( V_6 , V_21 , V_155 , V_147 ) ;
}
if ( ! V_38 ) {
V_6 -> V_121 = V_6 -> V_122 = V_123 ;
F_132 ( V_6 ) ;
}
V_15:
F_91 ( & V_6 -> V_84 ) ;
F_164 ( V_6 , V_147 , V_21 , V_155 , V_38 ) ;
return V_38 ;
}
static int F_165 ( struct V_6 * V_6 , struct V_42 * V_98 )
{
if ( F_166 ( V_6 ) )
F_167 ( V_6 , true ) ;
if ( F_168 ( V_6 ) ) {
F_63 ( F_42 ( V_6 ) , V_184 ) ;
F_169 ( V_6 -> V_17 ) ;
F_65 ( F_42 ( V_6 ) , V_184 ) ;
}
return 0 ;
}
static inline T_8 F_170 ( T_7 V_147 , T_8 V_185 )
{
if ( F_128 ( V_147 ) )
return V_185 ;
else if ( F_36 ( V_147 ) )
return V_185 & V_186 ;
else
return V_185 & V_187 ;
}
static int F_171 ( struct V_42 * V_98 , unsigned long V_188 )
{
struct V_6 * V_6 = F_2 ( V_98 ) ;
struct V_39 * V_40 = F_42 ( V_6 ) ;
unsigned int V_185 = V_40 -> V_189 & V_190 ;
return F_172 ( V_185 , ( int V_191 * ) V_188 ) ;
}
static int F_173 ( struct V_42 * V_98 , unsigned long V_188 )
{
struct V_6 * V_6 = F_2 ( V_98 ) ;
struct V_39 * V_40 = F_42 ( V_6 ) ;
unsigned int V_185 = V_40 -> V_189 & V_190 ;
unsigned int V_192 ;
int V_38 ;
V_38 = F_174 ( V_98 ) ;
if ( V_38 )
return V_38 ;
if ( ! F_175 ( V_6 ) ) {
V_38 = - V_99 ;
goto V_15;
}
if ( F_176 ( V_185 , ( int V_191 * ) V_188 ) ) {
V_38 = - V_18 ;
goto V_15;
}
V_185 = F_170 ( V_6 -> V_29 , V_185 ) ;
F_85 ( & V_6 -> V_84 ) ;
V_192 = V_40 -> V_189 ;
if ( ( V_185 ^ V_192 ) & ( V_193 | V_194 ) ) {
if ( ! F_139 ( V_195 ) ) {
F_91 ( & V_6 -> V_84 ) ;
V_38 = - V_196 ;
goto V_15;
}
}
V_185 = V_185 & V_197 ;
V_185 |= V_192 & ~ V_197 ;
V_40 -> V_189 = V_185 ;
F_91 ( & V_6 -> V_84 ) ;
F_177 ( V_6 ) ;
V_6 -> V_122 = V_123 ;
F_132 ( V_6 ) ;
V_15:
F_178 ( V_98 ) ;
return V_38 ;
}
static int F_179 ( struct V_42 * V_98 , unsigned long V_188 )
{
struct V_6 * V_6 = F_2 ( V_98 ) ;
return F_172 ( V_6 -> V_198 , ( int V_191 * ) V_188 ) ;
}
static int F_180 ( struct V_42 * V_98 )
{
struct V_6 * V_6 = F_2 ( V_98 ) ;
if ( ! F_175 ( V_6 ) )
return - V_99 ;
F_4 ( F_3 ( V_6 ) ) ;
if ( F_166 ( V_6 ) )
return 0 ;
F_63 ( F_42 ( V_6 ) , V_199 ) ;
return F_98 ( V_6 ) ;
}
static int F_181 ( struct V_42 * V_98 )
{
struct V_6 * V_6 = F_2 ( V_98 ) ;
int V_38 ;
if ( ! F_175 ( V_6 ) )
return - V_99 ;
if ( F_168 ( V_6 ) )
return 0 ;
V_38 = F_174 ( V_98 ) ;
if ( V_38 )
return V_38 ;
if ( F_166 ( V_6 ) ) {
F_65 ( F_42 ( V_6 ) , V_199 ) ;
F_167 ( V_6 , false ) ;
}
V_38 = F_58 ( V_98 , 0 , V_53 , 0 ) ;
F_178 ( V_98 ) ;
return V_38 ;
}
static int F_182 ( struct V_42 * V_98 )
{
struct V_6 * V_6 = F_2 ( V_98 ) ;
if ( ! F_175 ( V_6 ) )
return - V_99 ;
if ( F_168 ( V_6 ) )
return 0 ;
F_63 ( F_42 ( V_6 ) , V_200 ) ;
return F_98 ( V_6 ) ;
}
static int F_183 ( struct V_42 * V_98 )
{
struct V_6 * V_6 = F_2 ( V_98 ) ;
if ( ! F_175 ( V_6 ) )
return - V_99 ;
if ( ! F_168 ( V_6 ) )
return 0 ;
if ( ! F_184 ( V_6 ) )
return F_114 ( V_6 , 0 , true ) ;
F_149 ( V_6 , 0 , V_171 ) ;
return 0 ;
}
static int F_185 ( struct V_42 * V_98 )
{
struct V_6 * V_6 = F_2 ( V_98 ) ;
int V_38 ;
if ( ! F_175 ( V_6 ) )
return - V_99 ;
V_38 = F_174 ( V_98 ) ;
if ( V_38 )
return V_38 ;
F_4 ( F_3 ( V_6 ) ) ;
if ( F_166 ( V_6 ) ) {
F_65 ( F_42 ( V_6 ) , V_199 ) ;
F_167 ( V_6 , false ) ;
}
if ( F_168 ( V_6 ) )
F_65 ( F_42 ( V_6 ) , V_200 ) ;
F_178 ( V_98 ) ;
return V_38 ;
}
static int F_186 ( struct V_42 * V_98 , unsigned long V_188 )
{
struct V_6 * V_6 = F_2 ( V_98 ) ;
struct V_8 * V_9 = F_3 ( V_6 ) ;
struct V_201 * V_202 = V_9 -> V_202 ;
T_8 V_203 ;
if ( ! F_139 ( V_204 ) )
return - V_196 ;
if ( F_176 ( V_203 , ( T_8 V_191 * ) V_188 ) )
return - V_18 ;
switch ( V_203 ) {
case V_205 :
V_202 = F_187 ( V_202 -> V_206 ) ;
if ( V_202 && ! F_117 ( V_202 ) ) {
F_188 ( V_9 ) ;
F_189 ( V_202 -> V_206 , V_202 ) ;
}
break;
case V_207 :
F_72 ( V_202 , 1 ) ;
F_188 ( V_9 ) ;
break;
case V_208 :
F_188 ( V_9 ) ;
break;
default:
return - V_95 ;
}
return 0 ;
}
static int F_190 ( struct V_42 * V_98 , unsigned long V_188 )
{
struct V_6 * V_6 = F_2 ( V_98 ) ;
struct V_201 * V_202 = V_6 -> V_13 ;
struct V_209 * V_210 = F_191 ( V_202 -> V_206 ) ;
struct V_211 V_212 ;
int V_38 ;
if ( ! F_139 ( V_204 ) )
return - V_196 ;
if ( ! F_192 ( V_210 ) )
return - V_160 ;
if ( F_193 ( & V_212 , (struct V_211 V_191 * ) V_188 ,
sizeof( V_212 ) ) )
return - V_18 ;
V_212 . V_213 = F_194 ( ( unsigned int ) V_212 . V_213 ,
V_210 -> V_214 . V_215 ) ;
V_38 = F_195 ( F_196 ( V_202 ) , & V_212 ) ;
if ( V_38 < 0 )
return V_38 ;
if ( F_197 ( (struct V_211 V_191 * ) V_188 , & V_212 ,
sizeof( V_212 ) ) )
return - V_18 ;
return 0 ;
}
static bool F_198 ( T_9 V_216 [ 16 ] )
{
int V_37 ;
for ( V_37 = 0 ; V_37 < 16 ; V_37 ++ )
if ( V_216 [ V_37 ] )
return true ;
return false ;
}
static int F_199 ( struct V_42 * V_98 , unsigned long V_188 )
{
#ifdef F_200
struct V_217 V_218 ;
struct V_6 * V_6 = F_2 ( V_98 ) ;
if ( F_193 ( & V_218 , (struct V_217 V_191 * ) V_188 ,
sizeof( V_218 ) ) )
return - V_18 ;
return F_201 ( & V_218 , V_6 ) ;
#else
return - V_160 ;
#endif
}
static int F_202 ( struct V_42 * V_98 , unsigned long V_188 )
{
#ifdef F_200
struct V_217 V_218 ;
struct V_6 * V_6 = F_2 ( V_98 ) ;
int V_12 ;
V_12 = F_203 ( V_6 , & V_218 ) ;
if ( V_12 )
return V_12 ;
if ( F_197 ( (struct V_217 V_191 * ) V_188 , & V_218 ,
sizeof( V_218 ) ) )
return - V_18 ;
return 0 ;
#else
return - V_160 ;
#endif
}
static int F_204 ( struct V_42 * V_98 , unsigned long V_188 )
{
struct V_6 * V_6 = F_2 ( V_98 ) ;
struct V_8 * V_9 = F_3 ( V_6 ) ;
int V_12 ;
if ( ! F_205 ( V_6 -> V_13 ) )
return - V_160 ;
if ( F_198 ( V_9 -> V_219 -> V_220 ) )
goto V_221;
V_12 = F_174 ( V_98 ) ;
if ( V_12 )
return V_12 ;
F_206 ( V_9 -> V_219 -> V_220 ) ;
V_12 = F_207 ( V_9 , false ) ;
F_178 ( V_98 ) ;
if ( V_12 ) {
memset ( V_9 -> V_219 -> V_220 , 0 , 16 ) ;
return V_12 ;
}
V_221:
if ( F_197 ( ( T_9 V_191 * ) V_188 , V_9 -> V_219 -> V_220 ,
16 ) )
return - V_18 ;
return 0 ;
}
long F_208 ( struct V_42 * V_98 , unsigned int V_222 , unsigned long V_188 )
{
switch ( V_222 ) {
case V_223 :
return F_171 ( V_98 , V_188 ) ;
case V_224 :
return F_173 ( V_98 , V_188 ) ;
case V_225 :
return F_179 ( V_98 , V_188 ) ;
case V_226 :
return F_180 ( V_98 ) ;
case V_227 :
return F_181 ( V_98 ) ;
case V_228 :
return F_182 ( V_98 ) ;
case V_229 :
return F_183 ( V_98 ) ;
case V_230 :
return F_185 ( V_98 ) ;
case V_231 :
return F_186 ( V_98 , V_188 ) ;
case V_232 :
return F_190 ( V_98 , V_188 ) ;
case V_233 :
return F_199 ( V_98 , V_188 ) ;
case V_234 :
return F_202 ( V_98 , V_188 ) ;
case V_235 :
return F_204 ( V_98 , V_188 ) ;
default:
return - V_236 ;
}
}
static T_10 F_209 ( struct V_237 * V_238 , struct V_239 * V_110 )
{
struct V_6 * V_6 = F_2 ( V_238 -> V_240 ) ;
if ( F_96 ( V_6 ) &&
! F_210 ( V_6 ) &&
F_97 ( V_6 ) )
return - V_99 ;
return F_211 ( V_238 , V_110 ) ;
}
long F_212 ( struct V_42 * V_42 , unsigned int V_222 , unsigned long V_188 )
{
switch ( V_222 ) {
case V_241 :
V_222 = V_223 ;
break;
case V_242 :
V_222 = V_224 ;
break;
default:
return - V_243 ;
}
return F_208 ( V_42 , V_222 , ( unsigned long ) F_213 ( V_188 ) ) ;
}
