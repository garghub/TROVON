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
if ( F_32 ( V_6 , & V_26 -> V_27 ) ) {
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
else if ( F_37 ( V_6 ) )
V_28 = true ;
else if ( ! F_38 ( V_9 ) )
V_28 = true ;
else if ( ! F_39 ( V_9 , F_40 ( V_6 ) -> V_31 ) )
V_28 = true ;
else if ( F_40 ( V_6 ) -> V_32 == F_41 ( F_42 ( V_9 ) ) )
V_28 = true ;
else if ( F_43 ( V_9 , V_33 ) )
V_28 = true ;
else if ( V_9 -> V_34 == 2 )
V_28 = true ;
return V_28 ;
}
static bool F_44 ( struct V_8 * V_9 , T_1 V_35 )
{
struct V_5 * V_36 = F_45 ( F_46 ( V_9 ) , V_35 ) ;
bool V_37 = false ;
if ( ( V_36 && F_47 ( V_36 ) ) || F_48 ( V_9 , V_35 ) )
V_37 = true ;
F_49 ( V_36 , 0 ) ;
return V_37 ;
}
static void F_50 ( struct V_6 * V_6 )
{
struct V_38 * V_39 = F_40 ( V_6 ) ;
T_1 V_25 ;
F_51 ( & V_39 -> V_40 ) ;
V_39 -> V_32 = 0 ;
if ( F_37 ( V_6 ) && V_6 -> V_30 == 1 &&
F_28 ( V_6 , & V_25 ) ) {
V_39 -> V_31 = V_25 ;
F_52 ( V_6 ) ;
F_53 ( & V_39 -> V_40 ) ;
F_54 ( V_6 ) ;
F_55 ( V_6 , NULL ) ;
} else {
F_53 ( & V_39 -> V_40 ) ;
}
}
int F_56 ( struct V_41 * V_41 , T_2 V_42 , T_2 V_43 , int V_44 )
{
struct V_6 * V_6 = V_41 -> V_45 -> V_46 ;
struct V_38 * V_39 = F_40 ( V_6 ) ;
struct V_8 * V_9 = F_3 ( V_6 ) ;
T_1 V_35 = V_6 -> V_47 ;
int V_37 = 0 ;
bool V_28 = false ;
struct V_48 V_49 = {
. V_50 = V_51 ,
. V_52 = V_53 ,
. V_54 = 0 ,
} ;
if ( F_15 ( F_57 ( V_6 -> V_13 ) ) )
return 0 ;
F_58 ( V_6 ) ;
if ( F_59 ( V_6 ) <= F_60 ( V_9 ) -> V_55 )
F_61 ( V_39 , V_56 ) ;
V_37 = F_62 ( V_6 -> V_17 , V_42 , V_43 ) ;
F_63 ( V_39 , V_56 ) ;
if ( V_37 ) {
F_64 ( V_6 , V_28 , V_44 , V_37 ) ;
return V_37 ;
}
if ( ! V_44 && F_65 ( V_39 , V_57 ) ) {
F_66 ( V_6 ) ;
goto V_58;
}
if ( ! F_65 ( V_39 , V_59 ) &&
! F_67 ( V_9 , V_35 , V_60 ) ) {
if ( F_44 ( V_9 , V_35 ) )
goto V_58;
if ( F_65 ( V_39 , V_61 ) ||
F_67 ( V_9 , V_35 , V_62 ) )
goto V_63;
goto V_15;
}
V_58:
F_4 ( V_9 ) ;
F_68 ( & V_39 -> V_40 ) ;
V_28 = F_35 ( V_6 ) ;
F_69 ( & V_39 -> V_40 ) ;
if ( V_28 ) {
V_37 = F_70 ( V_6 -> V_13 , 1 ) ;
F_50 ( V_6 ) ;
F_63 ( V_39 , V_59 ) ;
F_63 ( V_39 , V_61 ) ;
goto V_15;
}
V_64:
F_71 ( V_9 , V_35 , & V_49 ) ;
if ( F_15 ( F_72 ( V_9 ) ) )
goto V_15;
if ( F_48 ( V_9 , V_35 ) ) {
F_54 ( V_6 ) ;
F_55 ( V_6 , NULL ) ;
goto V_64;
}
V_37 = F_73 ( V_9 , V_35 ) ;
if ( V_37 )
goto V_15;
F_74 ( V_9 , V_35 , V_60 ) ;
F_63 ( V_39 , V_59 ) ;
V_63:
F_74 ( V_9 , V_35 , V_62 ) ;
F_63 ( V_39 , V_61 ) ;
V_37 = F_75 ( V_9 ) ;
V_15:
F_64 ( V_6 , V_28 , V_44 , V_37 ) ;
F_76 ( NULL , NULL , 1 ) ;
return V_37 ;
}
static T_3 F_77 ( struct V_65 * V_16 ,
T_3 V_66 , int V_67 )
{
struct V_68 V_69 ;
int V_70 ;
if ( V_67 != V_71 )
return 0 ;
F_78 ( & V_69 , 0 ) ;
V_70 = F_79 ( & V_69 , V_16 , & V_66 ,
V_72 , 1 ) ;
V_66 = V_70 ? V_69 . V_73 [ 0 ] -> V_14 : V_53 ;
F_80 ( & V_69 ) ;
return V_66 ;
}
static bool F_81 ( T_4 V_74 , T_3 V_75 , T_3 V_66 ,
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
static T_2 F_82 ( struct V_41 * V_41 , T_2 V_21 , int V_67 )
{
struct V_6 * V_6 = V_41 -> V_45 -> V_46 ;
T_2 V_79 = V_6 -> V_13 -> V_80 ;
struct V_10 V_11 ;
T_3 V_66 , V_81 , V_75 ;
T_2 V_82 = V_21 ;
T_2 V_83 ;
int V_12 = 0 ;
F_83 ( & V_6 -> V_84 ) ;
V_83 = F_17 ( V_6 ) ;
if ( V_21 >= V_83 )
goto V_85;
if ( F_7 ( V_6 ) || F_84 ( V_6 ) ) {
if ( V_67 == V_78 )
V_82 = V_83 ;
goto V_86;
}
V_66 = ( T_3 ) ( V_21 >> V_20 ) ;
V_75 = F_77 ( V_6 -> V_17 , V_66 , V_67 ) ;
for (; V_82 < V_83 ; V_82 = V_66 << V_20 ) {
F_9 ( & V_11 , V_6 , NULL , NULL , 0 ) ;
V_12 = F_85 ( & V_11 , V_66 , V_87 ) ;
if ( V_12 && V_12 != - V_88 ) {
goto V_85;
} else if ( V_12 == - V_88 ) {
if ( V_67 == V_71 ) {
V_66 = F_86 ( V_66 ,
F_40 ( V_6 ) ) ;
continue;
} else {
goto V_86;
}
}
V_81 = F_87 ( V_11 . V_89 , F_40 ( V_6 ) ) ;
for (; V_11 . V_90 < V_81 ;
V_11 . V_90 ++ , V_66 ++ ,
V_82 = ( T_2 ) V_66 << V_20 ) {
T_4 V_74 ;
V_74 = F_88 ( V_11 . V_89 , V_11 . V_90 ) ;
if ( F_81 ( V_74 , V_75 , V_66 , V_67 ) ) {
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
F_89 ( & V_6 -> V_84 ) ;
return F_90 ( V_41 , V_82 , V_79 ) ;
V_85:
F_89 ( & V_6 -> V_84 ) ;
return - V_91 ;
}
static T_2 F_91 ( struct V_41 * V_41 , T_2 V_21 , int V_67 )
{
struct V_6 * V_6 = V_41 -> V_45 -> V_46 ;
T_2 V_79 = V_6 -> V_13 -> V_80 ;
switch ( V_67 ) {
case V_92 :
case V_93 :
case V_94 :
return F_92 ( V_41 , V_21 , V_67 ,
V_79 , F_17 ( V_6 ) ) ;
case V_71 :
case V_78 :
if ( V_21 < 0 )
return - V_91 ;
return F_82 ( V_41 , V_21 , V_67 ) ;
}
return - V_95 ;
}
static int F_93 ( struct V_41 * V_41 , struct V_1 * V_2 )
{
struct V_6 * V_6 = F_2 ( V_41 ) ;
if ( F_7 ( V_6 ) ) {
int V_12 = F_94 ( V_6 ) ;
if ( V_12 )
return V_12 ;
}
F_95 ( V_41 ) ;
V_2 -> V_96 = & V_97 ;
return 0 ;
}
int F_96 ( struct V_10 * V_11 , int V_98 )
{
int V_99 = 0 , V_100 = V_11 -> V_90 ;
struct V_8 * V_9 = F_3 ( V_11 -> V_6 ) ;
struct V_101 * V_102 ;
T_5 * V_103 ;
V_102 = F_97 ( V_11 -> V_89 ) ;
V_103 = F_98 ( V_102 ) + V_100 ;
for (; V_98 > 0 ; V_98 -- , V_103 ++ , V_11 -> V_90 ++ ) {
T_4 V_74 = F_99 ( * V_103 ) ;
if ( V_74 == V_77 )
continue;
V_11 -> V_104 = V_77 ;
F_100 ( V_11 ) ;
F_101 ( V_11 ) ;
F_102 ( V_9 , V_74 ) ;
if ( V_11 -> V_90 == 0 && F_103 ( V_11 -> V_89 ) )
F_63 ( F_40 ( V_11 -> V_6 ) ,
V_105 ) ;
V_99 ++ ;
}
if ( V_99 ) {
F_104 ( V_9 , V_11 -> V_6 , V_99 ) ;
F_22 ( V_11 -> V_89 ) ;
F_105 ( V_11 ) ;
}
V_11 -> V_90 = V_100 ;
F_106 ( V_11 -> V_6 , V_11 -> V_106 ,
V_11 -> V_90 , V_99 ) ;
return V_99 ;
}
void F_107 ( struct V_10 * V_11 )
{
F_96 ( V_11 , V_107 ) ;
}
static int F_108 ( struct V_6 * V_6 , T_6 V_108 ,
bool V_109 )
{
unsigned V_21 = V_108 & ( V_23 - 1 ) ;
struct V_5 * V_5 ;
if ( ! V_21 && ! V_109 )
return 0 ;
V_5 = F_109 ( V_6 , V_108 >> V_20 , V_109 ) ;
if ( F_110 ( V_5 ) )
return 0 ;
F_14 ( V_5 ) ;
if ( F_15 ( ! F_18 ( V_5 ) ||
V_5 -> V_16 != V_6 -> V_17 ) )
goto V_15;
F_25 ( V_5 , V_24 ) ;
F_111 ( V_5 , V_21 , V_23 - V_21 ) ;
if ( ! V_109 )
F_22 ( V_5 ) ;
V_15:
F_49 ( V_5 , 1 ) ;
return 0 ;
}
int F_112 ( struct V_6 * V_6 , T_6 V_108 , bool V_110 )
{
struct V_8 * V_9 = F_3 ( V_6 ) ;
unsigned int V_111 = V_6 -> V_13 -> V_112 ;
struct V_10 V_11 ;
T_3 V_113 ;
int V_98 = 0 , V_12 = 0 ;
struct V_5 * V_114 ;
bool V_115 = false ;
F_113 ( V_6 , V_108 ) ;
V_113 = ( T_3 ) F_114 ( V_108 + V_111 - 1 ) ;
if ( V_110 )
F_8 ( V_9 ) ;
V_114 = F_115 ( V_9 , V_6 -> V_47 ) ;
if ( F_110 ( V_114 ) ) {
V_12 = F_116 ( V_114 ) ;
goto V_15;
}
if ( F_7 ( V_6 ) ) {
if ( F_117 ( V_114 , V_108 ) )
F_22 ( V_114 ) ;
F_49 ( V_114 , 1 ) ;
V_115 = true ;
goto V_15;
}
F_9 ( & V_11 , V_6 , V_114 , NULL , 0 ) ;
V_12 = F_85 ( & V_11 , V_113 , V_116 ) ;
if ( V_12 ) {
if ( V_12 == - V_88 )
goto V_117;
goto V_15;
}
V_98 = F_87 ( V_11 . V_89 , F_40 ( V_6 ) ) ;
V_98 -= V_11 . V_90 ;
F_6 ( V_9 , V_98 < 0 ) ;
if ( V_11 . V_90 || F_103 ( V_11 . V_89 ) ) {
F_96 ( & V_11 , V_98 ) ;
V_113 += V_98 ;
}
F_12 ( & V_11 ) ;
V_117:
V_12 = F_118 ( V_6 , V_113 ) ;
V_15:
if ( V_110 )
F_11 ( V_9 ) ;
if ( ! V_12 )
V_12 = F_108 ( V_6 , V_108 , V_115 ) ;
F_119 ( V_6 , V_12 ) ;
return V_12 ;
}
void F_120 ( struct V_6 * V_6 )
{
if ( ! ( F_36 ( V_6 -> V_29 ) || F_121 ( V_6 -> V_29 ) ||
F_122 ( V_6 -> V_29 ) ) )
return;
F_123 ( V_6 ) ;
if ( F_7 ( V_6 ) && ! F_124 ( V_6 ) ) {
if ( F_94 ( V_6 ) )
return;
}
if ( ! F_112 ( V_6 , F_17 ( V_6 ) , true ) ) {
V_6 -> V_118 = V_6 -> V_119 = V_120 ;
F_125 ( V_6 ) ;
}
}
int F_126 ( struct V_121 * V_122 ,
struct V_26 * V_26 , struct V_123 * V_124 )
{
struct V_6 * V_6 = F_127 ( V_26 ) ;
F_128 ( V_6 , V_124 ) ;
V_124 -> V_125 <<= 3 ;
return 0 ;
}
static void F_129 ( struct V_6 * V_6 , const struct V_126 * V_127 )
{
struct V_38 * V_39 = F_40 ( V_6 ) ;
unsigned int V_128 = V_127 -> V_128 ;
if ( V_128 & V_129 )
V_6 -> V_130 = V_127 -> V_131 ;
if ( V_128 & V_132 )
V_6 -> V_133 = V_127 -> V_134 ;
if ( V_128 & V_135 )
V_6 -> V_136 = F_130 ( V_127 -> V_137 ,
V_6 -> V_13 -> V_138 ) ;
if ( V_128 & V_139 )
V_6 -> V_118 = F_130 ( V_127 -> V_140 ,
V_6 -> V_13 -> V_138 ) ;
if ( V_128 & V_141 )
V_6 -> V_119 = F_130 ( V_127 -> V_142 ,
V_6 -> V_13 -> V_138 ) ;
if ( V_128 & V_143 ) {
T_7 V_144 = V_127 -> V_145 ;
if ( ! F_131 ( V_6 -> V_133 ) && ! F_132 ( V_146 ) )
V_144 &= ~ V_147 ;
F_133 ( V_39 , V_144 ) ;
}
}
int F_134 ( struct V_26 * V_26 , struct V_126 * V_127 )
{
struct V_6 * V_6 = F_127 ( V_26 ) ;
struct V_38 * V_39 = F_40 ( V_6 ) ;
int V_12 ;
V_12 = F_135 ( V_6 , V_127 ) ;
if ( V_12 )
return V_12 ;
if ( V_127 -> V_128 & V_148 ) {
if ( V_127 -> V_149 != F_17 ( V_6 ) ) {
F_136 ( V_6 , V_127 -> V_149 ) ;
F_120 ( V_6 ) ;
F_4 ( F_3 ( V_6 ) ) ;
} else {
F_120 ( V_6 ) ;
}
}
F_129 ( V_6 , V_127 ) ;
if ( V_127 -> V_128 & V_143 ) {
V_12 = F_137 ( V_6 , F_138 ( V_6 ) ) ;
if ( V_12 || F_65 ( V_39 , V_150 ) ) {
V_6 -> V_29 = V_39 -> V_151 ;
F_63 ( V_39 , V_150 ) ;
}
}
F_125 ( V_6 ) ;
return V_12 ;
}
static void F_139 ( struct V_6 * V_6 , T_3 V_14 ,
T_2 V_42 , T_2 V_152 )
{
struct V_8 * V_9 = F_3 ( V_6 ) ;
struct V_5 * V_5 ;
if ( ! V_152 )
return;
F_4 ( V_9 ) ;
F_8 ( V_9 ) ;
V_5 = F_140 ( V_6 , NULL , V_14 , false ) ;
F_11 ( V_9 ) ;
if ( ! F_110 ( V_5 ) ) {
F_25 ( V_5 , V_24 ) ;
F_111 ( V_5 , V_42 , V_152 ) ;
F_22 ( V_5 ) ;
F_49 ( V_5 , 1 ) ;
}
}
int F_141 ( struct V_6 * V_6 , T_3 V_153 , T_3 V_154 )
{
T_3 V_14 ;
int V_12 ;
for ( V_14 = V_153 ; V_14 < V_154 ; V_14 ++ ) {
struct V_10 V_11 ;
F_9 ( & V_11 , V_6 , NULL , NULL , 0 ) ;
V_12 = F_85 ( & V_11 , V_14 , V_116 ) ;
if ( V_12 ) {
if ( V_12 == - V_88 )
continue;
return V_12 ;
}
if ( V_11 . V_104 != V_77 )
F_96 ( & V_11 , 1 ) ;
F_12 ( & V_11 ) ;
}
return 0 ;
}
static int F_142 ( struct V_6 * V_6 , T_2 V_21 , T_2 V_152 )
{
T_3 V_153 , V_154 ;
T_2 V_155 , V_156 ;
int V_37 = 0 ;
if ( ! F_36 ( V_6 -> V_29 ) )
return - V_157 ;
if ( V_21 >= V_6 -> V_158 )
return V_37 ;
if ( F_7 ( V_6 ) ) {
V_37 = F_94 ( V_6 ) ;
if ( V_37 )
return V_37 ;
}
V_153 = ( ( unsigned long long ) V_21 ) >> V_20 ;
V_154 = ( ( unsigned long long ) V_21 + V_152 ) >> V_20 ;
V_155 = V_21 & ( V_23 - 1 ) ;
V_156 = ( V_21 + V_152 ) & ( V_23 - 1 ) ;
if ( V_153 == V_154 ) {
F_139 ( V_6 , V_153 , V_155 ,
V_156 - V_155 ) ;
} else {
if ( V_155 )
F_139 ( V_6 , V_153 ++ , V_155 ,
V_23 - V_155 ) ;
if ( V_156 )
F_139 ( V_6 , V_154 , 0 , V_156 ) ;
if ( V_153 < V_154 ) {
struct V_65 * V_16 = V_6 -> V_17 ;
T_2 V_159 , V_160 ;
struct V_8 * V_9 = F_3 ( V_6 ) ;
F_4 ( V_9 ) ;
V_159 = V_153 << V_20 ;
V_160 = V_154 << V_20 ;
F_143 ( V_16 , V_159 ,
V_160 - 1 ) ;
F_8 ( V_9 ) ;
V_37 = F_141 ( V_6 , V_153 , V_154 ) ;
F_11 ( V_9 ) ;
}
}
return V_37 ;
}
static int F_144 ( struct V_6 * V_6 , T_2 V_21 ,
T_2 V_152 , int V_144 )
{
struct V_8 * V_9 = F_3 ( V_6 ) ;
T_3 V_14 , V_153 , V_154 ;
T_2 V_161 = F_17 ( V_6 ) ;
T_2 V_155 , V_156 ;
int V_37 = 0 ;
F_4 ( V_9 ) ;
V_37 = F_145 ( V_6 , ( V_152 + V_21 ) ) ;
if ( V_37 )
return V_37 ;
if ( F_7 ( V_6 ) ) {
V_37 = F_94 ( V_6 ) ;
if ( V_37 )
return V_37 ;
}
V_153 = ( ( unsigned long long ) V_21 ) >> V_20 ;
V_154 = ( ( unsigned long long ) V_21 + V_152 ) >> V_20 ;
V_155 = V_21 & ( V_23 - 1 ) ;
V_156 = ( V_21 + V_152 ) & ( V_23 - 1 ) ;
F_8 ( V_9 ) ;
for ( V_14 = V_153 ; V_14 <= V_154 ; V_14 ++ ) {
struct V_10 V_11 ;
if ( V_14 == V_154 && ! V_156 )
goto V_162;
F_9 ( & V_11 , V_6 , NULL , NULL , 0 ) ;
V_37 = F_10 ( & V_11 , V_14 ) ;
if ( V_37 )
break;
V_162:
if ( V_153 == V_154 )
V_161 = V_21 + V_152 ;
else if ( V_14 == V_153 && V_155 )
V_161 = ( V_14 + 1 ) << V_20 ;
else if ( V_14 == V_154 )
V_161 = ( V_14 << V_20 ) + V_156 ;
else
V_161 += V_23 ;
}
if ( ! ( V_144 & V_163 ) &&
F_17 ( V_6 ) < V_161 ) {
F_146 ( V_6 , V_161 ) ;
F_125 ( V_6 ) ;
F_66 ( V_6 ) ;
}
F_11 ( V_9 ) ;
return V_37 ;
}
static long F_147 ( struct V_41 * V_41 , int V_144 ,
T_2 V_21 , T_2 V_152 )
{
struct V_6 * V_6 = F_2 ( V_41 ) ;
long V_37 ;
if ( V_144 & ~ ( V_163 | V_164 ) )
return - V_157 ;
F_83 ( & V_6 -> V_84 ) ;
if ( V_144 & V_164 )
V_37 = F_142 ( V_6 , V_21 , V_152 ) ;
else
V_37 = F_144 ( V_6 , V_21 , V_152 , V_144 ) ;
if ( ! V_37 ) {
V_6 -> V_118 = V_6 -> V_119 = V_120 ;
F_125 ( V_6 ) ;
}
F_89 ( & V_6 -> V_84 ) ;
F_148 ( V_6 , V_144 , V_21 , V_152 , V_37 ) ;
return V_37 ;
}
static int F_149 ( struct V_6 * V_6 , struct V_41 * V_165 )
{
if ( F_150 ( V_6 ) )
F_151 ( V_6 , true ) ;
if ( F_152 ( V_6 ) ) {
F_61 ( F_40 ( V_6 ) , V_166 ) ;
F_153 ( V_6 -> V_17 ) ;
F_63 ( F_40 ( V_6 ) , V_166 ) ;
}
return 0 ;
}
static inline T_8 F_154 ( T_7 V_144 , T_8 V_167 )
{
if ( F_121 ( V_144 ) )
return V_167 ;
else if ( F_36 ( V_144 ) )
return V_167 & V_168 ;
else
return V_167 & V_169 ;
}
static int F_155 ( struct V_41 * V_165 , unsigned long V_170 )
{
struct V_6 * V_6 = F_2 ( V_165 ) ;
struct V_38 * V_39 = F_40 ( V_6 ) ;
unsigned int V_167 = V_39 -> V_171 & V_172 ;
return F_156 ( V_167 , ( int V_173 * ) V_170 ) ;
}
static int F_157 ( struct V_41 * V_165 , unsigned long V_170 )
{
struct V_6 * V_6 = F_2 ( V_165 ) ;
struct V_38 * V_39 = F_40 ( V_6 ) ;
unsigned int V_167 = V_39 -> V_171 & V_172 ;
unsigned int V_174 ;
int V_37 ;
V_37 = F_158 ( V_165 ) ;
if ( V_37 )
return V_37 ;
if ( ! F_159 ( V_6 ) ) {
V_37 = - V_175 ;
goto V_15;
}
if ( F_160 ( V_167 , ( int V_173 * ) V_170 ) ) {
V_37 = - V_18 ;
goto V_15;
}
V_167 = F_154 ( V_6 -> V_29 , V_167 ) ;
F_83 ( & V_6 -> V_84 ) ;
V_174 = V_39 -> V_171 ;
if ( ( V_167 ^ V_174 ) & ( V_176 | V_177 ) ) {
if ( ! F_132 ( V_178 ) ) {
F_89 ( & V_6 -> V_84 ) ;
V_37 = - V_179 ;
goto V_15;
}
}
V_167 = V_167 & V_180 ;
V_167 |= V_174 & ~ V_180 ;
V_39 -> V_171 = V_167 ;
F_89 ( & V_6 -> V_84 ) ;
F_161 ( V_6 ) ;
V_6 -> V_119 = V_120 ;
F_125 ( V_6 ) ;
V_15:
F_162 ( V_165 ) ;
return V_37 ;
}
static int F_163 ( struct V_41 * V_165 , unsigned long V_170 )
{
struct V_6 * V_6 = F_2 ( V_165 ) ;
return F_156 ( V_6 -> V_181 , ( int V_173 * ) V_170 ) ;
}
static int F_164 ( struct V_41 * V_165 )
{
struct V_6 * V_6 = F_2 ( V_165 ) ;
if ( ! F_159 ( V_6 ) )
return - V_175 ;
F_4 ( F_3 ( V_6 ) ) ;
if ( F_150 ( V_6 ) )
return 0 ;
F_61 ( F_40 ( V_6 ) , V_182 ) ;
return F_94 ( V_6 ) ;
}
static int F_165 ( struct V_41 * V_165 )
{
struct V_6 * V_6 = F_2 ( V_165 ) ;
int V_37 ;
if ( ! F_159 ( V_6 ) )
return - V_175 ;
if ( F_152 ( V_6 ) )
return 0 ;
V_37 = F_158 ( V_165 ) ;
if ( V_37 )
return V_37 ;
if ( F_150 ( V_6 ) )
F_151 ( V_6 , false ) ;
V_37 = F_56 ( V_165 , 0 , V_53 , 0 ) ;
F_162 ( V_165 ) ;
F_63 ( F_40 ( V_6 ) , V_182 ) ;
return V_37 ;
}
static int F_166 ( struct V_41 * V_165 )
{
struct V_6 * V_6 = F_2 ( V_165 ) ;
if ( ! F_159 ( V_6 ) )
return - V_175 ;
if ( F_152 ( V_6 ) )
return 0 ;
F_61 ( F_40 ( V_6 ) , V_183 ) ;
return F_94 ( V_6 ) ;
}
static int F_167 ( struct V_41 * V_165 )
{
struct V_6 * V_6 = F_2 ( V_165 ) ;
if ( ! F_159 ( V_6 ) )
return - V_175 ;
if ( ! F_152 ( V_6 ) )
return 0 ;
if ( ! F_168 ( V_6 ) )
return F_108 ( V_6 , 0 , true ) ;
F_142 ( V_6 , 0 , V_184 ) ;
return 0 ;
}
static int F_169 ( struct V_41 * V_165 )
{
struct V_6 * V_6 = F_2 ( V_165 ) ;
int V_37 ;
if ( ! F_159 ( V_6 ) )
return - V_175 ;
V_37 = F_158 ( V_165 ) ;
if ( V_37 )
return V_37 ;
F_4 ( F_3 ( V_6 ) ) ;
if ( F_150 ( V_6 ) ) {
F_151 ( V_6 , false ) ;
F_63 ( F_40 ( V_6 ) , V_182 ) ;
}
if ( F_152 ( V_6 ) ) {
F_63 ( F_40 ( V_6 ) , V_183 ) ;
F_153 ( V_6 -> V_17 ) ;
F_61 ( F_40 ( V_6 ) , V_183 ) ;
}
F_162 ( V_165 ) ;
return V_37 ;
}
static int F_170 ( struct V_41 * V_165 , unsigned long V_170 )
{
struct V_6 * V_6 = F_2 ( V_165 ) ;
struct V_8 * V_9 = F_3 ( V_6 ) ;
struct V_185 * V_186 = V_9 -> V_186 ;
T_8 V_187 ;
if ( ! F_132 ( V_188 ) )
return - V_179 ;
if ( F_160 ( V_187 , ( T_8 V_173 * ) V_170 ) )
return - V_18 ;
switch ( V_187 ) {
case V_189 :
V_186 = F_171 ( V_186 -> V_190 ) ;
if ( V_186 && ! F_110 ( V_186 ) ) {
F_172 ( V_9 ) ;
F_173 ( V_186 -> V_190 , V_186 ) ;
}
break;
case V_191 :
F_70 ( V_186 , 1 ) ;
F_172 ( V_9 ) ;
break;
case V_192 :
F_172 ( V_9 ) ;
break;
default:
return - V_95 ;
}
return 0 ;
}
static int F_174 ( struct V_41 * V_165 , unsigned long V_170 )
{
struct V_6 * V_6 = F_2 ( V_165 ) ;
struct V_185 * V_186 = V_6 -> V_13 ;
struct V_193 * V_194 = F_175 ( V_186 -> V_190 ) ;
struct V_195 V_196 ;
int V_37 ;
if ( ! F_132 ( V_188 ) )
return - V_179 ;
if ( ! F_176 ( V_194 ) )
return - V_157 ;
if ( F_177 ( & V_196 , (struct V_195 V_173 * ) V_170 ,
sizeof( V_196 ) ) )
return - V_18 ;
V_196 . V_197 = F_178 ( ( unsigned int ) V_196 . V_197 ,
V_194 -> V_198 . V_199 ) ;
V_37 = F_179 ( F_180 ( V_186 ) , & V_196 ) ;
if ( V_37 < 0 )
return V_37 ;
if ( F_181 ( (struct V_195 V_173 * ) V_170 , & V_196 ,
sizeof( V_196 ) ) )
return - V_18 ;
return 0 ;
}
long F_182 ( struct V_41 * V_165 , unsigned int V_200 , unsigned long V_170 )
{
switch ( V_200 ) {
case V_201 :
return F_155 ( V_165 , V_170 ) ;
case V_202 :
return F_157 ( V_165 , V_170 ) ;
case V_203 :
return F_163 ( V_165 , V_170 ) ;
case V_204 :
return F_164 ( V_165 ) ;
case V_205 :
return F_165 ( V_165 ) ;
case V_206 :
return F_166 ( V_165 ) ;
case V_207 :
return F_167 ( V_165 ) ;
case V_208 :
return F_169 ( V_165 ) ;
case V_209 :
return F_170 ( V_165 , V_170 ) ;
case V_210 :
return F_174 ( V_165 , V_170 ) ;
default:
return - V_211 ;
}
}
long F_183 ( struct V_41 * V_41 , unsigned int V_200 , unsigned long V_170 )
{
switch ( V_200 ) {
case V_212 :
V_200 = V_201 ;
break;
case V_213 :
V_200 = V_202 ;
break;
default:
return - V_214 ;
}
return F_182 ( V_41 , V_200 , ( unsigned long ) F_184 ( V_170 ) ) ;
}
