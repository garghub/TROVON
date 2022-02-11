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
if ( ( ( V_20 ) ( V_5 -> V_14 + 1 ) << V_21 ) >
F_17 ( V_6 ) ) {
unsigned V_22 ;
V_22 = F_17 ( V_6 ) & ~ V_23 ;
F_21 ( V_5 , V_22 , V_24 ) ;
}
F_22 ( V_5 ) ;
F_23 ( V_5 ) ;
F_24 ( V_5 , V_25 ) ;
V_19:
F_25 ( V_5 , V_25 ) ;
if ( F_26 ( V_6 ) && F_27 ( V_6 -> V_26 ) )
F_28 ( V_9 , V_11 . V_27 ) ;
F_29 ( V_5 ) ;
V_15:
F_30 ( V_6 -> V_13 ) ;
return F_31 ( V_12 ) ;
}
static int F_32 ( struct V_6 * V_6 , T_1 * V_28 )
{
struct V_29 * V_29 ;
V_6 = F_33 ( V_6 ) ;
V_29 = F_34 ( V_6 ) ;
F_35 ( V_6 ) ;
if ( ! V_29 )
return 0 ;
if ( F_36 ( V_6 , V_6 , & V_29 -> V_30 ) ) {
F_37 ( V_29 ) ;
return 0 ;
}
* V_28 = F_38 ( V_29 ) ;
F_37 ( V_29 ) ;
return 1 ;
}
static inline bool F_39 ( struct V_6 * V_6 )
{
struct V_8 * V_9 = F_3 ( V_6 ) ;
bool V_31 = false ;
if ( ! F_27 ( V_6 -> V_26 ) || V_6 -> V_32 != 1 )
V_31 = true ;
else if ( F_40 ( V_6 ) && F_41 ( V_9 , V_6 -> V_33 ) )
V_31 = true ;
else if ( F_42 ( V_6 ) )
V_31 = true ;
else if ( ! F_43 ( V_9 ) )
V_31 = true ;
else if ( ! F_44 ( V_9 , F_45 ( V_6 ) -> V_34 ) )
V_31 = true ;
else if ( F_45 ( V_6 ) -> V_35 == F_46 ( F_47 ( V_9 ) ) )
V_31 = true ;
else if ( F_48 ( V_9 , V_36 ) )
V_31 = true ;
else if ( V_9 -> V_37 == 2 )
V_31 = true ;
return V_31 ;
}
static bool F_49 ( struct V_8 * V_9 , T_1 V_38 )
{
struct V_5 * V_39 = F_50 ( F_51 ( V_9 ) , V_38 ) ;
bool V_40 = false ;
if ( ( V_39 && F_52 ( V_39 ) ) || F_53 ( V_9 , V_38 ) )
V_40 = true ;
F_54 ( V_39 , 0 ) ;
return V_40 ;
}
static void F_55 ( struct V_6 * V_6 )
{
struct V_41 * V_42 = F_45 ( V_6 ) ;
T_1 V_28 ;
F_56 ( & V_42 -> V_43 ) ;
V_42 -> V_35 = 0 ;
if ( F_42 ( V_6 ) && V_6 -> V_32 == 1 &&
F_32 ( V_6 , & V_28 ) ) {
V_42 -> V_34 = V_28 ;
F_57 ( V_6 ) ;
F_58 ( & V_42 -> V_43 ) ;
F_59 ( V_6 ) ;
F_60 ( V_6 , NULL ) ;
} else {
F_58 ( & V_42 -> V_43 ) ;
}
}
int F_61 ( struct V_44 * V_44 , V_20 V_45 , V_20 V_46 , int V_47 )
{
struct V_6 * V_6 = V_44 -> V_48 -> V_49 ;
struct V_41 * V_42 = F_45 ( V_6 ) ;
struct V_8 * V_9 = F_3 ( V_6 ) ;
T_1 V_38 = V_6 -> V_33 ;
int V_40 = 0 ;
bool V_31 = false ;
struct V_50 V_51 = {
. V_52 = V_53 ,
. V_54 = V_55 ,
. V_56 = 0 ,
} ;
if ( F_15 ( F_62 ( V_6 -> V_13 ) ) )
return 0 ;
F_63 ( V_6 ) ;
if ( F_64 ( V_6 ) <= F_65 ( V_9 ) -> V_57 )
F_66 ( V_42 , V_58 ) ;
V_40 = F_67 ( V_6 -> V_17 , V_45 , V_46 ) ;
F_68 ( V_42 , V_58 ) ;
if ( V_40 ) {
F_69 ( V_6 , V_31 , V_47 , V_40 ) ;
return V_40 ;
}
if ( ! V_47 ) {
F_60 ( V_6 , NULL ) ;
goto V_59;
}
if ( ! F_70 ( V_42 , V_60 ) &&
! F_71 ( V_9 , V_38 , V_61 ) ) {
if ( F_49 ( V_9 , V_38 ) )
goto V_59;
if ( F_70 ( V_42 , V_62 ) ||
F_71 ( V_9 , V_38 , V_63 ) )
goto V_64;
goto V_15;
}
V_59:
F_4 ( V_9 ) ;
F_72 ( & V_42 -> V_43 ) ;
V_31 = F_39 ( V_6 ) ;
F_73 ( & V_42 -> V_43 ) ;
if ( V_31 ) {
V_40 = F_74 ( V_6 -> V_13 , 1 ) ;
F_55 ( V_6 ) ;
F_68 ( V_42 , V_60 ) ;
F_68 ( V_42 , V_62 ) ;
goto V_15;
}
V_65:
F_75 ( V_9 , V_38 , & V_51 ) ;
if ( F_15 ( F_76 ( V_9 ) ) )
goto V_15;
if ( F_53 ( V_9 , V_38 ) ) {
F_59 ( V_6 ) ;
F_60 ( V_6 , NULL ) ;
goto V_65;
}
V_40 = F_77 ( V_9 , V_38 ) ;
if ( V_40 )
goto V_15;
F_78 ( V_9 , V_38 , V_61 ) ;
F_68 ( V_42 , V_60 ) ;
V_64:
F_78 ( V_9 , V_38 , V_63 ) ;
F_68 ( V_42 , V_62 ) ;
V_40 = F_79 ( V_9 ) ;
V_15:
F_69 ( V_6 , V_31 , V_47 , V_40 ) ;
F_80 ( NULL , 1 ) ;
return V_40 ;
}
static T_2 F_81 ( struct V_66 * V_16 ,
T_2 V_67 , int V_68 )
{
struct V_69 V_70 ;
int V_71 ;
if ( V_68 != V_72 )
return 0 ;
F_82 ( & V_70 , 0 ) ;
V_71 = F_83 ( & V_70 , V_16 , & V_67 ,
V_73 , 1 ) ;
V_67 = V_71 ? V_70 . V_74 [ 0 ] -> V_14 : V_55 ;
F_84 ( & V_70 ) ;
return V_67 ;
}
static bool F_85 ( T_3 V_75 , T_2 V_76 , T_2 V_67 ,
int V_68 )
{
switch ( V_68 ) {
case V_72 :
if ( ( V_75 == V_77 && V_76 == V_67 ) ||
( V_75 != V_77 && V_75 != V_78 ) )
return true ;
break;
case V_79 :
if ( V_75 == V_78 )
return true ;
break;
}
return false ;
}
static V_20 F_86 ( struct V_44 * V_44 , V_20 V_22 , int V_68 )
{
struct V_6 * V_6 = V_44 -> V_48 -> V_49 ;
V_20 V_80 = V_6 -> V_13 -> V_81 ;
struct V_10 V_11 ;
T_2 V_67 , V_82 , V_76 ;
V_20 V_83 = V_22 ;
V_20 V_84 ;
int V_12 = 0 ;
F_87 ( & V_6 -> V_85 ) ;
V_84 = F_17 ( V_6 ) ;
if ( V_22 >= V_84 )
goto V_86;
if ( F_7 ( V_6 ) || F_88 ( V_6 ) ) {
if ( V_68 == V_79 )
V_83 = V_84 ;
goto V_87;
}
V_67 = ( T_2 ) ( V_22 >> V_21 ) ;
V_76 = F_81 ( V_6 -> V_17 , V_67 , V_68 ) ;
for (; V_83 < V_84 ; V_83 = ( V_20 ) V_67 << V_21 ) {
F_9 ( & V_11 , V_6 , NULL , NULL , 0 ) ;
V_12 = F_89 ( & V_11 , V_67 , V_88 ) ;
if ( V_12 && V_12 != - V_89 ) {
goto V_86;
} else if ( V_12 == - V_89 ) {
if ( V_68 == V_72 ) {
V_67 = F_90 ( V_67 ,
F_45 ( V_6 ) ) ;
continue;
} else {
goto V_87;
}
}
V_82 = F_91 ( V_11 . V_90 , F_45 ( V_6 ) ) ;
for (; V_11 . V_91 < V_82 ;
V_11 . V_91 ++ , V_67 ++ ,
V_83 = ( V_20 ) V_67 << V_21 ) {
T_3 V_75 ;
V_75 = F_92 ( V_11 . V_90 , V_11 . V_91 ) ;
if ( F_85 ( V_75 , V_76 , V_67 , V_68 ) ) {
F_12 ( & V_11 ) ;
goto V_87;
}
}
F_12 ( & V_11 ) ;
}
if ( V_68 == V_72 )
goto V_86;
V_87:
if ( V_68 == V_79 && V_83 > V_84 )
V_83 = V_84 ;
F_93 ( & V_6 -> V_85 ) ;
return F_94 ( V_44 , V_83 , V_80 ) ;
V_86:
F_93 ( & V_6 -> V_85 ) ;
return - V_92 ;
}
static V_20 F_95 ( struct V_44 * V_44 , V_20 V_22 , int V_68 )
{
struct V_6 * V_6 = V_44 -> V_48 -> V_49 ;
V_20 V_80 = V_6 -> V_13 -> V_81 ;
switch ( V_68 ) {
case V_93 :
case V_94 :
case V_95 :
return F_96 ( V_44 , V_22 , V_68 ,
V_80 , F_17 ( V_6 ) ) ;
case V_72 :
case V_79 :
if ( V_22 < 0 )
return - V_92 ;
return F_86 ( V_44 , V_22 , V_68 ) ;
}
return - V_96 ;
}
static int F_97 ( struct V_44 * V_44 , struct V_1 * V_2 )
{
struct V_6 * V_6 = F_2 ( V_44 ) ;
if ( F_26 ( V_6 ) ) {
int V_12 = F_98 ( V_6 ) ;
if ( V_12 )
return 0 ;
}
if ( F_7 ( V_6 ) ) {
int V_12 = F_99 ( V_6 ) ;
if ( V_12 )
return V_12 ;
}
F_100 ( V_44 ) ;
V_2 -> V_97 = & V_98 ;
return 0 ;
}
static int F_101 ( struct V_6 * V_6 , struct V_44 * V_99 )
{
int V_40 = F_102 ( V_6 , V_99 ) ;
if ( ! V_40 && F_26 ( V_6 ) ) {
V_40 = F_98 ( V_6 ) ;
if ( V_40 )
V_40 = - V_100 ;
}
return V_40 ;
}
int F_103 ( struct V_10 * V_11 , int V_101 )
{
struct V_8 * V_9 = F_3 ( V_11 -> V_6 ) ;
struct V_102 * V_103 ;
int V_104 = 0 , V_105 = V_11 -> V_91 , V_106 = V_101 ;
T_4 * V_107 ;
V_103 = F_104 ( V_11 -> V_90 ) ;
V_107 = F_105 ( V_103 ) + V_105 ;
for (; V_101 > 0 ; V_101 -- , V_107 ++ , V_11 -> V_91 ++ ) {
T_3 V_75 = F_106 ( * V_107 ) ;
if ( V_75 == V_78 )
continue;
V_11 -> V_27 = V_78 ;
F_107 ( V_11 ) ;
F_108 ( V_9 , V_75 ) ;
if ( V_11 -> V_91 == 0 && F_109 ( V_11 -> V_90 ) )
F_68 ( F_45 ( V_11 -> V_6 ) ,
V_108 ) ;
V_104 ++ ;
}
if ( V_104 ) {
T_2 V_109 ;
V_109 = F_110 ( F_111 ( V_11 -> V_90 ) ,
F_45 ( V_11 -> V_6 ) ) + V_105 ;
F_112 ( V_11 , V_109 , 0 , V_106 ) ;
F_113 ( V_9 , V_11 -> V_6 , V_104 ) ;
F_22 ( V_11 -> V_90 ) ;
F_114 ( V_11 ) ;
}
V_11 -> V_91 = V_105 ;
F_115 ( V_11 -> V_6 , V_11 -> V_110 ,
V_11 -> V_91 , V_104 ) ;
return V_104 ;
}
void F_116 ( struct V_10 * V_11 )
{
F_103 ( V_11 , V_111 ) ;
}
static int F_117 ( struct V_6 * V_6 , T_5 V_112 ,
bool V_113 )
{
unsigned V_22 = V_112 & ( V_24 - 1 ) ;
T_2 V_14 = V_112 >> V_21 ;
struct V_66 * V_16 = V_6 -> V_17 ;
struct V_5 * V_5 ;
if ( ! V_22 && ! V_113 )
return 0 ;
if ( V_113 ) {
V_5 = F_118 ( V_16 , V_14 , false ) ;
if ( V_5 && F_18 ( V_5 ) )
goto V_114;
F_54 ( V_5 , 1 ) ;
return 0 ;
}
V_5 = F_119 ( V_6 , V_14 , true ) ;
if ( F_120 ( V_5 ) )
return 0 ;
V_114:
F_25 ( V_5 , V_25 ) ;
F_121 ( V_5 , V_22 , V_24 - V_22 ) ;
if ( ! V_113 || ! F_26 ( V_6 ) || ! F_27 ( V_6 -> V_26 ) )
F_22 ( V_5 ) ;
F_54 ( V_5 , 1 ) ;
return 0 ;
}
int F_122 ( struct V_6 * V_6 , T_5 V_112 , bool V_115 )
{
struct V_8 * V_9 = F_3 ( V_6 ) ;
unsigned int V_116 = V_6 -> V_13 -> V_117 ;
struct V_10 V_11 ;
T_2 V_118 ;
int V_101 = 0 , V_12 = 0 ;
struct V_5 * V_119 ;
bool V_120 = false ;
F_123 ( V_6 , V_112 ) ;
V_118 = ( T_2 ) F_124 ( V_112 + V_116 - 1 ) ;
if ( V_115 )
F_8 ( V_9 ) ;
V_119 = F_125 ( V_9 , V_6 -> V_33 ) ;
if ( F_120 ( V_119 ) ) {
V_12 = F_126 ( V_119 ) ;
goto V_15;
}
if ( F_7 ( V_6 ) ) {
if ( F_127 ( V_119 , V_112 ) )
F_22 ( V_119 ) ;
F_54 ( V_119 , 1 ) ;
V_120 = true ;
goto V_15;
}
F_9 ( & V_11 , V_6 , V_119 , NULL , 0 ) ;
V_12 = F_89 ( & V_11 , V_118 , V_121 ) ;
if ( V_12 ) {
if ( V_12 == - V_89 )
goto V_122;
goto V_15;
}
V_101 = F_91 ( V_11 . V_90 , F_45 ( V_6 ) ) ;
V_101 -= V_11 . V_91 ;
F_6 ( V_9 , V_101 < 0 ) ;
if ( V_11 . V_91 || F_109 ( V_11 . V_90 ) ) {
F_103 ( & V_11 , V_101 ) ;
V_118 += V_101 ;
}
F_12 ( & V_11 ) ;
V_122:
V_12 = F_128 ( V_6 , V_118 ) ;
V_15:
if ( V_115 )
F_11 ( V_9 ) ;
if ( ! V_12 )
V_12 = F_117 ( V_6 , V_112 , V_120 ) ;
F_129 ( V_6 , V_12 ) ;
return V_12 ;
}
int F_130 ( struct V_6 * V_6 , bool V_115 )
{
int V_12 ;
if ( ! ( F_27 ( V_6 -> V_26 ) || F_131 ( V_6 -> V_26 ) ||
F_132 ( V_6 -> V_26 ) ) )
return 0 ;
F_133 ( V_6 ) ;
if ( F_7 ( V_6 ) && ! F_134 ( V_6 ) ) {
V_12 = F_99 ( V_6 ) ;
if ( V_12 )
return V_12 ;
}
V_12 = F_122 ( V_6 , F_17 ( V_6 ) , V_115 ) ;
if ( V_12 )
return V_12 ;
V_6 -> V_123 = V_6 -> V_124 = V_125 ;
F_135 ( V_6 ) ;
return 0 ;
}
int F_136 ( struct V_126 * V_127 ,
struct V_29 * V_29 , struct V_128 * V_129 )
{
struct V_6 * V_6 = F_137 ( V_29 ) ;
F_138 ( V_6 , V_129 ) ;
V_129 -> V_130 <<= 3 ;
return 0 ;
}
static void F_139 ( struct V_6 * V_6 , const struct V_131 * V_132 )
{
struct V_41 * V_42 = F_45 ( V_6 ) ;
unsigned int V_133 = V_132 -> V_133 ;
if ( V_133 & V_134 )
V_6 -> V_135 = V_132 -> V_136 ;
if ( V_133 & V_137 )
V_6 -> V_138 = V_132 -> V_139 ;
if ( V_133 & V_140 )
V_6 -> V_141 = F_140 ( V_132 -> V_142 ,
V_6 -> V_13 -> V_143 ) ;
if ( V_133 & V_144 )
V_6 -> V_123 = F_140 ( V_132 -> V_145 ,
V_6 -> V_13 -> V_143 ) ;
if ( V_133 & V_146 )
V_6 -> V_124 = F_140 ( V_132 -> V_147 ,
V_6 -> V_13 -> V_143 ) ;
if ( V_133 & V_148 ) {
T_6 V_149 = V_132 -> V_150 ;
if ( ! F_141 ( V_6 -> V_138 ) && ! F_142 ( V_151 ) )
V_149 &= ~ V_152 ;
F_143 ( V_42 , V_149 ) ;
}
}
int F_144 ( struct V_29 * V_29 , struct V_131 * V_132 )
{
struct V_6 * V_6 = F_137 ( V_29 ) ;
struct V_41 * V_42 = F_45 ( V_6 ) ;
int V_12 ;
V_12 = F_145 ( V_6 , V_132 ) ;
if ( V_12 )
return V_12 ;
if ( V_132 -> V_133 & V_153 ) {
if ( F_26 ( V_6 ) &&
F_98 ( V_6 ) )
return - V_100 ;
if ( V_132 -> V_154 <= F_17 ( V_6 ) ) {
F_146 ( V_6 , V_132 -> V_154 ) ;
V_12 = F_130 ( V_6 , true ) ;
if ( V_12 )
return V_12 ;
F_4 ( F_3 ( V_6 ) ) ;
} else {
F_146 ( V_6 , V_132 -> V_154 ) ;
V_6 -> V_123 = V_6 -> V_124 = V_125 ;
}
}
F_139 ( V_6 , V_132 ) ;
if ( V_132 -> V_133 & V_148 ) {
V_12 = F_147 ( V_6 , F_148 ( V_6 ) ) ;
if ( V_12 || F_70 ( V_42 , V_155 ) ) {
V_6 -> V_26 = V_42 -> V_156 ;
F_68 ( V_42 , V_155 ) ;
}
}
F_135 ( V_6 ) ;
return V_12 ;
}
static int F_149 ( struct V_6 * V_6 , T_2 V_14 ,
V_20 V_45 , V_20 V_106 )
{
struct V_8 * V_9 = F_3 ( V_6 ) ;
struct V_5 * V_5 ;
if ( ! V_106 )
return 0 ;
F_4 ( V_9 ) ;
F_8 ( V_9 ) ;
V_5 = F_150 ( V_6 , NULL , V_14 , false ) ;
F_11 ( V_9 ) ;
if ( F_120 ( V_5 ) )
return F_126 ( V_5 ) ;
F_25 ( V_5 , V_25 ) ;
F_121 ( V_5 , V_45 , V_106 ) ;
F_22 ( V_5 ) ;
F_54 ( V_5 , 1 ) ;
return 0 ;
}
int F_151 ( struct V_6 * V_6 , T_2 V_157 , T_2 V_158 )
{
int V_12 ;
while ( V_157 < V_158 ) {
struct V_10 V_11 ;
T_2 V_82 , V_101 ;
F_9 ( & V_11 , V_6 , NULL , NULL , 0 ) ;
V_12 = F_89 ( & V_11 , V_157 , V_121 ) ;
if ( V_12 ) {
if ( V_12 == - V_89 ) {
V_157 ++ ;
continue;
}
return V_12 ;
}
V_82 = F_91 ( V_11 . V_90 , F_45 ( V_6 ) ) ;
V_101 = F_152 ( V_82 - V_11 . V_91 , V_158 - V_157 ) ;
F_6 ( F_3 ( V_6 ) , V_101 == 0 || V_101 > V_82 ) ;
F_103 ( & V_11 , V_101 ) ;
F_12 ( & V_11 ) ;
V_157 += V_101 ;
}
return 0 ;
}
static int F_153 ( struct V_6 * V_6 , V_20 V_22 , V_20 V_106 )
{
T_2 V_157 , V_158 ;
V_20 V_159 , V_160 ;
int V_40 = 0 ;
if ( F_7 ( V_6 ) ) {
V_40 = F_99 ( V_6 ) ;
if ( V_40 )
return V_40 ;
}
V_157 = ( ( unsigned long long ) V_22 ) >> V_21 ;
V_158 = ( ( unsigned long long ) V_22 + V_106 ) >> V_21 ;
V_159 = V_22 & ( V_24 - 1 ) ;
V_160 = ( V_22 + V_106 ) & ( V_24 - 1 ) ;
if ( V_157 == V_158 ) {
V_40 = F_149 ( V_6 , V_157 , V_159 ,
V_160 - V_159 ) ;
if ( V_40 )
return V_40 ;
} else {
if ( V_159 ) {
V_40 = F_149 ( V_6 , V_157 ++ , V_159 ,
V_24 - V_159 ) ;
if ( V_40 )
return V_40 ;
}
if ( V_160 ) {
V_40 = F_149 ( V_6 , V_158 , 0 , V_160 ) ;
if ( V_40 )
return V_40 ;
}
if ( V_157 < V_158 ) {
struct V_66 * V_16 = V_6 -> V_17 ;
V_20 V_161 , V_162 ;
struct V_8 * V_9 = F_3 ( V_6 ) ;
F_4 ( V_9 ) ;
V_161 = ( V_20 ) V_157 << V_21 ;
V_162 = ( V_20 ) V_158 << V_21 ;
F_154 ( V_16 , V_161 ,
V_162 - 1 ) ;
F_8 ( V_9 ) ;
V_40 = F_151 ( V_6 , V_157 , V_158 ) ;
F_11 ( V_9 ) ;
}
}
return V_40 ;
}
static int F_155 ( struct V_6 * V_6 , T_2 V_163 ,
T_2 V_164 , bool V_165 )
{
struct V_8 * V_9 = F_3 ( V_6 ) ;
struct V_10 V_11 ;
T_3 V_166 ;
bool V_167 = false ;
int V_40 ;
F_9 ( & V_11 , V_6 , NULL , NULL , 0 ) ;
V_40 = F_89 ( & V_11 , V_163 , V_88 ) ;
if ( V_40 && V_40 != - V_89 ) {
return V_40 ;
} else if ( V_40 == - V_89 ) {
V_166 = V_78 ;
} else {
V_166 = V_11 . V_27 ;
if ( ! F_156 ( V_9 , V_166 ) ) {
V_11 . V_27 = V_78 ;
F_107 ( & V_11 ) ;
F_157 ( & V_11 ) ;
V_167 = true ;
}
F_12 ( & V_11 ) ;
}
if ( V_166 == V_78 )
return V_165 ? F_151 ( V_6 , V_164 , V_164 + 1 ) : 0 ;
if ( V_167 ) {
struct V_5 * V_119 = F_125 ( V_9 , V_6 -> V_33 ) ;
struct V_168 V_169 ;
if ( F_120 ( V_119 ) ) {
V_40 = F_126 ( V_119 ) ;
goto V_170;
}
F_9 ( & V_11 , V_6 , V_119 , NULL , 0 ) ;
V_40 = F_10 ( & V_11 , V_164 ) ;
if ( V_40 )
goto V_170;
F_103 ( & V_11 , 1 ) ;
F_158 ( V_9 , V_11 . V_110 , & V_169 ) ;
F_159 ( V_9 , & V_11 , V_11 . V_27 , V_166 ,
V_169 . V_171 , true ) ;
F_12 ( & V_11 ) ;
} else {
struct V_5 * V_172 , * V_173 ;
V_172 = F_119 ( V_6 , V_163 , true ) ;
if ( F_120 ( V_172 ) )
return F_126 ( V_172 ) ;
V_173 = F_150 ( V_6 , NULL , V_164 , false ) ;
if ( F_120 ( V_173 ) ) {
F_54 ( V_172 , 1 ) ;
return F_126 ( V_173 ) ;
}
F_160 ( V_172 , V_173 ) ;
F_22 ( V_173 ) ;
F_54 ( V_173 , 1 ) ;
F_54 ( V_172 , 1 ) ;
return F_151 ( V_6 , V_163 , V_163 + 1 ) ;
}
return 0 ;
V_170:
if ( ! F_89 ( & V_11 , V_163 , V_121 ) ) {
V_11 . V_27 = V_166 ;
F_107 ( & V_11 ) ;
F_157 ( & V_11 ) ;
F_12 ( & V_11 ) ;
}
return V_40 ;
}
static int F_161 ( struct V_6 * V_6 , T_2 V_45 , T_2 V_46 )
{
struct V_8 * V_9 = F_3 ( V_6 ) ;
T_2 V_174 = ( F_17 ( V_6 ) + V_175 - 1 ) / V_175 ;
int V_40 = 0 ;
for (; V_46 < V_174 ; V_45 ++ , V_46 ++ ) {
F_4 ( V_9 ) ;
F_8 ( V_9 ) ;
V_40 = F_155 ( V_6 , V_46 , V_45 , true ) ;
F_11 ( V_9 ) ;
if ( V_40 )
break;
}
return V_40 ;
}
static int F_162 ( struct V_6 * V_6 , V_20 V_22 , V_20 V_106 )
{
T_2 V_157 , V_158 ;
V_20 V_176 ;
int V_40 ;
if ( V_22 + V_106 >= F_17 ( V_6 ) )
return - V_96 ;
if ( V_22 & ( V_177 - 1 ) || V_106 & ( V_177 - 1 ) )
return - V_96 ;
F_4 ( F_3 ( V_6 ) ) ;
if ( F_7 ( V_6 ) ) {
V_40 = F_99 ( V_6 ) ;
if ( V_40 )
return V_40 ;
}
V_157 = V_22 >> V_21 ;
V_158 = ( V_22 + V_106 ) >> V_21 ;
V_40 = F_67 ( V_6 -> V_17 , V_22 , V_178 ) ;
if ( V_40 )
return V_40 ;
F_163 ( V_6 , V_22 ) ;
V_40 = F_161 ( V_6 , V_157 , V_158 ) ;
if ( V_40 )
return V_40 ;
F_67 ( V_6 -> V_17 , V_22 , V_178 ) ;
F_163 ( V_6 , V_22 ) ;
V_176 = F_17 ( V_6 ) - V_106 ;
F_163 ( V_6 , V_176 ) ;
V_40 = F_122 ( V_6 , V_176 , true ) ;
if ( ! V_40 )
F_164 ( V_6 , V_176 ) ;
return V_40 ;
}
static int F_165 ( struct V_6 * V_6 , V_20 V_22 , V_20 V_106 ,
int V_149 )
{
struct V_8 * V_9 = F_3 ( V_6 ) ;
struct V_66 * V_16 = V_6 -> V_17 ;
T_2 V_14 , V_157 , V_158 ;
V_20 V_176 = F_17 ( V_6 ) ;
V_20 V_159 , V_160 ;
int V_40 = 0 ;
V_40 = F_166 ( V_6 , ( V_106 + V_22 ) ) ;
if ( V_40 )
return V_40 ;
F_4 ( V_9 ) ;
if ( F_7 ( V_6 ) ) {
V_40 = F_99 ( V_6 ) ;
if ( V_40 )
return V_40 ;
}
V_40 = F_67 ( V_16 , V_22 , V_22 + V_106 - 1 ) ;
if ( V_40 )
return V_40 ;
F_167 ( V_6 , V_22 , V_22 + V_106 - 1 ) ;
V_157 = ( ( unsigned long long ) V_22 ) >> V_21 ;
V_158 = ( ( unsigned long long ) V_22 + V_106 ) >> V_21 ;
V_159 = V_22 & ( V_24 - 1 ) ;
V_160 = ( V_22 + V_106 ) & ( V_24 - 1 ) ;
if ( V_157 == V_158 ) {
V_40 = F_149 ( V_6 , V_157 , V_159 ,
V_160 - V_159 ) ;
if ( V_40 )
return V_40 ;
if ( V_22 + V_106 > V_176 )
V_176 = V_22 + V_106 ;
V_176 = F_168 ( V_20 , V_176 , V_22 + V_106 ) ;
} else {
if ( V_159 ) {
V_40 = F_149 ( V_6 , V_157 ++ , V_159 ,
V_24 - V_159 ) ;
if ( V_40 )
return V_40 ;
V_176 = F_168 ( V_20 , V_176 ,
( V_20 ) V_157 << V_21 ) ;
}
for ( V_14 = V_157 ; V_14 < V_158 ; V_14 ++ ) {
struct V_10 V_11 ;
struct V_5 * V_119 ;
F_8 ( V_9 ) ;
V_119 = F_125 ( V_9 , V_6 -> V_33 ) ;
if ( F_120 ( V_119 ) ) {
V_40 = F_126 ( V_119 ) ;
F_11 ( V_9 ) ;
goto V_15;
}
F_9 ( & V_11 , V_6 , V_119 , NULL , 0 ) ;
V_40 = F_10 ( & V_11 , V_14 ) ;
if ( V_40 ) {
F_11 ( V_9 ) ;
goto V_15;
}
if ( V_11 . V_27 != V_77 ) {
F_108 ( V_9 , V_11 . V_27 ) ;
V_11 . V_27 = V_77 ;
F_107 ( & V_11 ) ;
V_11 . V_27 = V_78 ;
F_157 ( & V_11 ) ;
}
F_12 ( & V_11 ) ;
F_11 ( V_9 ) ;
V_176 = F_168 ( V_20 , V_176 ,
( V_20 ) ( V_14 + 1 ) << V_21 ) ;
}
if ( V_160 ) {
V_40 = F_149 ( V_6 , V_158 , 0 , V_160 ) ;
if ( V_40 )
goto V_15;
V_176 = F_168 ( V_20 , V_176 , V_22 + V_106 ) ;
}
}
V_15:
if ( ! ( V_149 & V_179 ) && F_17 ( V_6 ) < V_176 ) {
F_164 ( V_6 , V_176 ) ;
F_135 ( V_6 ) ;
F_169 ( V_6 ) ;
}
return V_40 ;
}
static int F_170 ( struct V_6 * V_6 , V_20 V_22 , V_20 V_106 )
{
struct V_8 * V_9 = F_3 ( V_6 ) ;
T_2 V_157 , V_158 , V_180 , V_174 , V_181 ;
V_20 V_176 ;
int V_40 = 0 ;
V_176 = F_17 ( V_6 ) + V_106 ;
if ( V_176 > V_6 -> V_13 -> V_81 )
return - V_182 ;
if ( V_22 >= F_17 ( V_6 ) )
return - V_96 ;
if ( V_22 & ( V_177 - 1 ) || V_106 & ( V_177 - 1 ) )
return - V_96 ;
F_4 ( V_9 ) ;
if ( F_7 ( V_6 ) ) {
V_40 = F_99 ( V_6 ) ;
if ( V_40 )
return V_40 ;
}
V_40 = F_122 ( V_6 , F_17 ( V_6 ) , true ) ;
if ( V_40 )
return V_40 ;
V_40 = F_67 ( V_6 -> V_17 , V_22 , V_178 ) ;
if ( V_40 )
return V_40 ;
F_163 ( V_6 , V_22 ) ;
V_157 = V_22 >> V_21 ;
V_158 = ( V_22 + V_106 ) >> V_21 ;
V_180 = V_158 - V_157 ;
V_174 = ( F_17 ( V_6 ) + V_175 - 1 ) / V_175 ;
for ( V_181 = V_174 - 1 ; V_181 >= V_157 && V_181 != - 1 ; V_181 -- ) {
F_8 ( V_9 ) ;
V_40 = F_155 ( V_6 , V_181 , V_181 + V_180 , false ) ;
F_11 ( V_9 ) ;
if ( V_40 )
break;
}
F_67 ( V_6 -> V_17 , V_22 , V_178 ) ;
F_163 ( V_6 , V_22 ) ;
if ( ! V_40 )
F_164 ( V_6 , V_176 ) ;
return V_40 ;
}
static int F_171 ( struct V_6 * V_6 , V_20 V_22 ,
V_20 V_106 , int V_149 )
{
struct V_8 * V_9 = F_3 ( V_6 ) ;
T_2 V_14 , V_157 , V_158 ;
V_20 V_176 = F_17 ( V_6 ) ;
V_20 V_159 , V_160 ;
int V_40 = 0 ;
F_4 ( V_9 ) ;
V_40 = F_166 ( V_6 , ( V_106 + V_22 ) ) ;
if ( V_40 )
return V_40 ;
if ( F_7 ( V_6 ) ) {
V_40 = F_99 ( V_6 ) ;
if ( V_40 )
return V_40 ;
}
V_157 = ( ( unsigned long long ) V_22 ) >> V_21 ;
V_158 = ( ( unsigned long long ) V_22 + V_106 ) >> V_21 ;
V_159 = V_22 & ( V_24 - 1 ) ;
V_160 = ( V_22 + V_106 ) & ( V_24 - 1 ) ;
F_8 ( V_9 ) ;
for ( V_14 = V_157 ; V_14 <= V_158 ; V_14 ++ ) {
struct V_10 V_11 ;
if ( V_14 == V_158 && ! V_160 )
goto V_183;
F_9 ( & V_11 , V_6 , NULL , NULL , 0 ) ;
V_40 = F_10 ( & V_11 , V_14 ) ;
if ( V_40 )
break;
V_183:
if ( V_157 == V_158 )
V_176 = V_22 + V_106 ;
else if ( V_14 == V_157 && V_159 )
V_176 = ( V_20 ) ( V_14 + 1 ) << V_21 ;
else if ( V_14 == V_158 )
V_176 = ( ( V_20 ) V_14 << V_21 ) +
V_160 ;
else
V_176 += V_24 ;
}
if ( ! ( V_149 & V_179 ) &&
F_17 ( V_6 ) < V_176 ) {
F_164 ( V_6 , V_176 ) ;
F_135 ( V_6 ) ;
F_169 ( V_6 ) ;
}
F_11 ( V_9 ) ;
return V_40 ;
}
static long F_172 ( struct V_44 * V_44 , int V_149 ,
V_20 V_22 , V_20 V_106 )
{
struct V_6 * V_6 = F_2 ( V_44 ) ;
long V_40 = 0 ;
if ( ! F_27 ( V_6 -> V_26 ) )
return - V_96 ;
if ( F_26 ( V_6 ) &&
( V_149 & ( V_184 | V_185 ) ) )
return - V_186 ;
if ( V_149 & ~ ( V_179 | V_187 |
V_184 | V_188 |
V_185 ) )
return - V_186 ;
F_87 ( & V_6 -> V_85 ) ;
if ( V_149 & V_187 ) {
if ( V_22 >= V_6 -> V_189 )
goto V_15;
V_40 = F_153 ( V_6 , V_22 , V_106 ) ;
} else if ( V_149 & V_184 ) {
V_40 = F_162 ( V_6 , V_22 , V_106 ) ;
} else if ( V_149 & V_188 ) {
V_40 = F_165 ( V_6 , V_22 , V_106 , V_149 ) ;
} else if ( V_149 & V_185 ) {
V_40 = F_170 ( V_6 , V_22 , V_106 ) ;
} else {
V_40 = F_171 ( V_6 , V_22 , V_106 , V_149 ) ;
}
if ( ! V_40 ) {
V_6 -> V_123 = V_6 -> V_124 = V_125 ;
F_135 ( V_6 ) ;
}
V_15:
F_93 ( & V_6 -> V_85 ) ;
F_173 ( V_6 , V_149 , V_22 , V_106 , V_40 ) ;
return V_40 ;
}
static int F_174 ( struct V_6 * V_6 , struct V_44 * V_99 )
{
if ( F_175 ( V_6 ) )
F_176 ( V_6 , true ) ;
if ( F_177 ( V_6 ) ) {
F_66 ( F_45 ( V_6 ) , V_190 ) ;
F_178 ( V_6 -> V_17 ) ;
F_68 ( F_45 ( V_6 ) , V_190 ) ;
}
return 0 ;
}
static inline T_7 F_179 ( T_6 V_149 , T_7 V_191 )
{
if ( F_131 ( V_149 ) )
return V_191 ;
else if ( F_27 ( V_149 ) )
return V_191 & V_192 ;
else
return V_191 & V_193 ;
}
static int F_180 ( struct V_44 * V_99 , unsigned long V_194 )
{
struct V_6 * V_6 = F_2 ( V_99 ) ;
struct V_41 * V_42 = F_45 ( V_6 ) ;
unsigned int V_191 = V_42 -> V_195 & V_196 ;
return F_181 ( V_191 , ( int V_197 * ) V_194 ) ;
}
static int F_182 ( struct V_44 * V_99 , unsigned long V_194 )
{
struct V_6 * V_6 = F_2 ( V_99 ) ;
struct V_41 * V_42 = F_45 ( V_6 ) ;
unsigned int V_191 = V_42 -> V_195 & V_196 ;
unsigned int V_198 ;
int V_40 ;
V_40 = F_183 ( V_99 ) ;
if ( V_40 )
return V_40 ;
if ( ! F_184 ( V_6 ) ) {
V_40 = - V_100 ;
goto V_15;
}
if ( F_185 ( V_191 , ( int V_197 * ) V_194 ) ) {
V_40 = - V_18 ;
goto V_15;
}
V_191 = F_179 ( V_6 -> V_26 , V_191 ) ;
F_87 ( & V_6 -> V_85 ) ;
V_198 = V_42 -> V_195 ;
if ( ( V_191 ^ V_198 ) & ( V_199 | V_200 ) ) {
if ( ! F_142 ( V_201 ) ) {
F_93 ( & V_6 -> V_85 ) ;
V_40 = - V_202 ;
goto V_15;
}
}
V_191 = V_191 & V_203 ;
V_191 |= V_198 & ~ V_203 ;
V_42 -> V_195 = V_191 ;
F_93 ( & V_6 -> V_85 ) ;
F_186 ( V_6 ) ;
V_6 -> V_124 = V_125 ;
F_135 ( V_6 ) ;
V_15:
F_187 ( V_99 ) ;
return V_40 ;
}
static int F_188 ( struct V_44 * V_99 , unsigned long V_194 )
{
struct V_6 * V_6 = F_2 ( V_99 ) ;
return F_181 ( V_6 -> V_204 , ( int V_197 * ) V_194 ) ;
}
static int F_189 ( struct V_44 * V_99 )
{
struct V_6 * V_6 = F_2 ( V_99 ) ;
int V_40 ;
if ( ! F_184 ( V_6 ) )
return - V_100 ;
F_4 ( F_3 ( V_6 ) ) ;
if ( F_175 ( V_6 ) )
return 0 ;
V_40 = F_99 ( V_6 ) ;
if ( V_40 )
return V_40 ;
F_66 ( F_45 ( V_6 ) , V_205 ) ;
return 0 ;
}
static int F_190 ( struct V_44 * V_99 )
{
struct V_6 * V_6 = F_2 ( V_99 ) ;
int V_40 ;
if ( ! F_184 ( V_6 ) )
return - V_100 ;
if ( F_177 ( V_6 ) )
return 0 ;
V_40 = F_183 ( V_99 ) ;
if ( V_40 )
return V_40 ;
if ( F_175 ( V_6 ) ) {
F_68 ( F_45 ( V_6 ) , V_205 ) ;
V_40 = F_176 ( V_6 , false ) ;
if ( V_40 )
goto V_170;
}
V_40 = F_61 ( V_99 , 0 , V_178 , 0 ) ;
V_170:
F_187 ( V_99 ) ;
return V_40 ;
}
static int F_191 ( struct V_44 * V_99 )
{
struct V_6 * V_6 = F_2 ( V_99 ) ;
int V_40 ;
if ( ! F_184 ( V_6 ) )
return - V_100 ;
if ( F_177 ( V_6 ) )
return 0 ;
V_40 = F_99 ( V_6 ) ;
if ( V_40 )
return V_40 ;
F_66 ( F_45 ( V_6 ) , V_206 ) ;
return 0 ;
}
static int F_192 ( struct V_44 * V_99 )
{
struct V_6 * V_6 = F_2 ( V_99 ) ;
if ( ! F_184 ( V_6 ) )
return - V_100 ;
if ( ! F_177 ( V_6 ) )
return 0 ;
if ( ! F_193 ( V_6 ) )
return F_117 ( V_6 , 0 , true ) ;
return F_153 ( V_6 , 0 , V_177 ) ;
}
static int F_194 ( struct V_44 * V_99 )
{
struct V_6 * V_6 = F_2 ( V_99 ) ;
int V_40 ;
if ( ! F_184 ( V_6 ) )
return - V_100 ;
V_40 = F_183 ( V_99 ) ;
if ( V_40 )
return V_40 ;
F_4 ( F_3 ( V_6 ) ) ;
F_68 ( F_45 ( V_6 ) , V_205 ) ;
F_68 ( F_45 ( V_6 ) , V_206 ) ;
F_176 ( V_6 , true ) ;
F_187 ( V_99 ) ;
return V_40 ;
}
static int F_195 ( struct V_44 * V_99 , unsigned long V_194 )
{
struct V_6 * V_6 = F_2 ( V_99 ) ;
struct V_8 * V_9 = F_3 ( V_6 ) ;
struct V_207 * V_208 = V_9 -> V_208 ;
T_7 V_209 ;
if ( ! F_142 ( V_210 ) )
return - V_202 ;
if ( F_185 ( V_209 , ( T_7 V_197 * ) V_194 ) )
return - V_18 ;
switch ( V_209 ) {
case V_211 :
V_208 = F_196 ( V_208 -> V_212 ) ;
if ( V_208 && ! F_120 ( V_208 ) ) {
F_197 ( V_9 ) ;
F_198 ( V_208 -> V_212 , V_208 ) ;
}
break;
case V_213 :
F_74 ( V_208 , 1 ) ;
F_197 ( V_9 ) ;
break;
case V_214 :
F_197 ( V_9 ) ;
break;
case V_215 :
F_199 ( V_9 , V_216 , V_55 ) ;
F_197 ( V_9 ) ;
break;
default:
return - V_96 ;
}
return 0 ;
}
static int F_200 ( struct V_44 * V_99 , unsigned long V_194 )
{
struct V_6 * V_6 = F_2 ( V_99 ) ;
struct V_207 * V_208 = V_6 -> V_13 ;
struct V_217 * V_218 = F_201 ( V_208 -> V_212 ) ;
struct V_219 V_220 ;
int V_40 ;
if ( ! F_142 ( V_210 ) )
return - V_202 ;
if ( ! F_202 ( V_218 ) )
return - V_186 ;
if ( F_203 ( & V_220 , (struct V_219 V_197 * ) V_194 ,
sizeof( V_220 ) ) )
return - V_18 ;
V_220 . V_221 = F_204 ( ( unsigned int ) V_220 . V_221 ,
V_218 -> V_222 . V_223 ) ;
V_40 = F_205 ( F_206 ( V_208 ) , & V_220 ) ;
if ( V_40 < 0 )
return V_40 ;
if ( F_207 ( (struct V_219 V_197 * ) V_194 , & V_220 ,
sizeof( V_220 ) ) )
return - V_18 ;
return 0 ;
}
static bool F_208 ( T_8 V_224 [ 16 ] )
{
int V_39 ;
for ( V_39 = 0 ; V_39 < 16 ; V_39 ++ )
if ( V_224 [ V_39 ] )
return true ;
return false ;
}
static int F_209 ( struct V_44 * V_99 , unsigned long V_194 )
{
#ifdef F_210
struct V_225 V_226 ;
struct V_6 * V_6 = F_2 ( V_99 ) ;
if ( F_203 ( & V_226 , (struct V_225 V_197 * ) V_194 ,
sizeof( V_226 ) ) )
return - V_18 ;
return F_211 ( & V_226 , V_6 ) ;
#else
return - V_186 ;
#endif
}
static int F_212 ( struct V_44 * V_99 , unsigned long V_194 )
{
#ifdef F_210
struct V_225 V_226 ;
struct V_6 * V_6 = F_2 ( V_99 ) ;
int V_12 ;
V_12 = F_213 ( V_6 , & V_226 ) ;
if ( V_12 )
return V_12 ;
if ( F_207 ( (struct V_225 V_197 * ) V_194 , & V_226 ,
sizeof( V_226 ) ) )
return - V_18 ;
return 0 ;
#else
return - V_186 ;
#endif
}
static int F_214 ( struct V_44 * V_99 , unsigned long V_194 )
{
struct V_6 * V_6 = F_2 ( V_99 ) ;
struct V_8 * V_9 = F_3 ( V_6 ) ;
int V_12 ;
if ( ! F_215 ( V_6 -> V_13 ) )
return - V_186 ;
if ( F_208 ( V_9 -> V_227 -> V_228 ) )
goto V_229;
V_12 = F_183 ( V_99 ) ;
if ( V_12 )
return V_12 ;
F_216 ( V_9 -> V_227 -> V_228 ) ;
V_12 = F_217 ( V_9 , false ) ;
F_187 ( V_99 ) ;
if ( V_12 ) {
memset ( V_9 -> V_227 -> V_228 , 0 , 16 ) ;
return V_12 ;
}
V_229:
if ( F_207 ( ( T_8 V_197 * ) V_194 , V_9 -> V_227 -> V_228 ,
16 ) )
return - V_18 ;
return 0 ;
}
static int F_218 ( struct V_44 * V_99 , unsigned long V_194 )
{
struct V_6 * V_6 = F_2 ( V_99 ) ;
struct V_8 * V_9 = F_3 ( V_6 ) ;
T_7 V_230 ;
if ( ! F_142 ( V_210 ) )
return - V_202 ;
if ( F_185 ( V_230 , ( T_7 V_197 * ) V_194 ) )
return - V_18 ;
if ( F_62 ( V_9 -> V_208 ) )
return - V_231 ;
if ( ! V_230 ) {
if ( ! F_219 ( & V_9 -> V_232 ) )
return - V_233 ;
} else {
F_87 ( & V_9 -> V_232 ) ;
}
return F_220 ( V_9 , V_230 ) ;
}
static int F_221 ( struct V_44 * V_99 , unsigned long V_194 )
{
struct V_6 * V_6 = F_2 ( V_99 ) ;
struct V_8 * V_9 = F_3 ( V_6 ) ;
struct V_234 V_235 ;
if ( ! F_142 ( V_210 ) )
return - V_202 ;
if ( F_62 ( V_9 -> V_208 ) )
return - V_231 ;
V_235 . V_236 = F_222 ( V_9 ) ;
F_87 ( & V_9 -> V_232 ) ;
F_223 ( V_9 , & V_235 ) ;
F_93 ( & V_9 -> V_232 ) ;
return 0 ;
}
long F_224 ( struct V_44 * V_99 , unsigned int V_237 , unsigned long V_194 )
{
switch ( V_237 ) {
case V_238 :
return F_180 ( V_99 , V_194 ) ;
case V_239 :
return F_182 ( V_99 , V_194 ) ;
case V_240 :
return F_188 ( V_99 , V_194 ) ;
case V_241 :
return F_189 ( V_99 ) ;
case V_242 :
return F_190 ( V_99 ) ;
case V_243 :
return F_191 ( V_99 ) ;
case V_244 :
return F_192 ( V_99 ) ;
case V_245 :
return F_194 ( V_99 ) ;
case V_246 :
return F_195 ( V_99 , V_194 ) ;
case V_247 :
return F_200 ( V_99 , V_194 ) ;
case V_248 :
return F_209 ( V_99 , V_194 ) ;
case V_249 :
return F_212 ( V_99 , V_194 ) ;
case V_250 :
return F_214 ( V_99 , V_194 ) ;
case V_251 :
return F_218 ( V_99 , V_194 ) ;
case V_252 :
return F_221 ( V_99 , V_194 ) ;
default:
return - V_253 ;
}
}
static T_9 F_225 ( struct V_254 * V_255 , struct V_256 * V_112 )
{
struct V_6 * V_6 = F_2 ( V_255 -> V_257 ) ;
if ( F_26 ( V_6 ) &&
! F_226 ( V_6 ) &&
F_98 ( V_6 ) )
return - V_100 ;
return F_227 ( V_255 , V_112 ) ;
}
long F_228 ( struct V_44 * V_44 , unsigned int V_237 , unsigned long V_194 )
{
switch ( V_237 ) {
case V_258 :
V_237 = V_238 ;
break;
case V_259 :
V_237 = V_239 ;
break;
default:
return - V_260 ;
}
return F_224 ( V_44 , V_237 , ( unsigned long ) F_229 ( V_194 ) ) ;
}
