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
V_12 = F_6 ( V_6 , V_14 + 1 , V_5 ) ;
if ( V_12 )
goto V_15;
F_7 ( V_9 ) ;
F_8 ( & V_11 , V_6 , NULL , NULL , 0 ) ;
V_12 = F_9 ( & V_11 , V_5 -> V_16 ) ;
F_10 ( V_9 ) ;
if ( V_12 )
goto V_15;
F_11 ( V_2 -> V_7 ) ;
F_12 ( V_5 ) ;
if ( F_13 ( V_5 -> V_17 != V_6 -> V_18 ||
F_14 ( V_5 ) > F_15 ( V_6 ) ||
! F_16 ( V_5 ) ) ) {
F_17 ( V_5 ) ;
V_12 = - V_19 ;
goto V_15;
}
if ( F_18 ( V_5 ) )
goto V_20;
if ( ( ( V_5 -> V_16 + 1 ) << V_21 ) > F_15 ( V_6 ) ) {
unsigned V_22 ;
V_22 = F_15 ( V_6 ) & ~ V_23 ;
F_19 ( V_5 , V_22 , V_24 ) ;
}
F_20 ( V_5 ) ;
F_21 ( V_5 ) ;
F_22 ( V_5 , V_25 ) ;
V_20:
F_23 ( V_5 , V_25 ) ;
V_15:
F_24 ( V_6 -> V_13 ) ;
return F_25 ( V_12 ) ;
}
static int F_26 ( struct V_6 * V_6 , T_1 * V_26 )
{
struct V_27 * V_27 ;
V_6 = F_27 ( V_6 ) ;
V_27 = F_28 ( V_6 ) ;
F_29 ( V_6 ) ;
if ( ! V_27 )
return 0 ;
if ( F_30 ( V_6 , & V_27 -> V_28 ) ) {
F_31 ( V_27 ) ;
return 0 ;
}
* V_26 = F_32 ( V_27 ) ;
F_31 ( V_27 ) ;
return 1 ;
}
static inline bool F_33 ( struct V_6 * V_6 )
{
struct V_8 * V_9 = F_3 ( V_6 ) ;
bool V_29 = false ;
if ( ! F_34 ( V_6 -> V_30 ) || V_6 -> V_31 != 1 )
V_29 = true ;
else if ( F_35 ( V_6 ) )
V_29 = true ;
else if ( ! F_36 ( V_9 ) )
V_29 = true ;
else if ( ! F_37 ( V_9 , F_38 ( V_6 ) -> V_32 ) )
V_29 = true ;
else if ( F_38 ( V_6 ) -> V_33 == F_39 ( F_40 ( V_9 ) ) )
V_29 = true ;
return V_29 ;
}
int F_41 ( struct V_34 * V_34 , T_2 V_35 , T_2 V_36 , int V_37 )
{
struct V_6 * V_6 = V_34 -> V_38 -> V_39 ;
struct V_40 * V_41 = F_38 ( V_6 ) ;
struct V_8 * V_9 = F_3 ( V_6 ) ;
T_1 V_42 = V_6 -> V_43 ;
int V_44 = 0 ;
bool V_29 = false ;
struct V_45 V_46 = {
. V_47 = V_48 ,
. V_49 = V_50 ,
. V_51 = 0 ,
} ;
if ( F_13 ( F_42 ( V_6 -> V_13 ) ) )
return 0 ;
F_43 ( V_6 ) ;
if ( F_44 ( V_6 ) <= F_45 ( V_9 ) -> V_52 )
F_46 ( V_41 , V_53 ) ;
V_44 = F_47 ( V_6 -> V_18 , V_35 , V_36 ) ;
F_48 ( V_41 , V_53 ) ;
if ( V_44 ) {
F_49 ( V_6 , V_29 , V_37 , V_44 ) ;
return V_44 ;
}
if ( ! F_50 ( V_41 , V_54 ) &&
! F_51 ( V_9 , V_42 , V_55 ) ) {
struct V_5 * V_56 = F_52 ( F_53 ( V_9 ) , V_42 ) ;
if ( ( V_56 && F_54 ( V_56 ) ) || F_55 ( V_9 , V_42 ) ) {
F_56 ( V_56 , 0 ) ;
goto V_57;
}
F_56 ( V_56 , 0 ) ;
if ( F_50 ( V_41 , V_58 ) ||
F_51 ( V_9 , V_42 , V_59 ) )
goto V_60;
goto V_15;
}
V_57:
F_4 ( V_9 ) ;
F_57 ( & V_41 -> V_61 ) ;
V_29 = F_33 ( V_6 ) ;
F_58 ( & V_41 -> V_61 ) ;
if ( V_29 ) {
T_1 V_26 ;
V_44 = F_59 ( V_6 -> V_13 , 1 ) ;
F_60 ( & V_41 -> V_61 ) ;
F_38 ( V_6 ) -> V_33 = 0 ;
if ( F_35 ( V_6 ) && V_6 -> V_31 == 1 &&
F_26 ( V_6 , & V_26 ) ) {
F_38 ( V_6 ) -> V_32 = V_26 ;
F_61 ( V_6 ) ;
F_62 ( & V_41 -> V_61 ) ;
F_63 ( V_6 ) ;
V_44 = F_64 ( V_6 , NULL ) ;
if ( V_44 )
goto V_15;
} else {
F_62 ( & V_41 -> V_61 ) ;
}
} else {
V_62:
F_65 ( V_9 , V_42 , & V_46 ) ;
if ( F_55 ( V_9 , V_42 ) ) {
F_63 ( V_6 ) ;
V_44 = F_64 ( V_6 , NULL ) ;
if ( V_44 )
goto V_15;
goto V_62;
}
V_44 = F_66 ( V_9 , V_42 ) ;
if ( V_44 )
goto V_15;
F_67 ( V_9 , V_42 , V_55 ) ;
F_48 ( V_41 , V_54 ) ;
V_60:
F_67 ( V_9 , V_42 , V_59 ) ;
F_48 ( V_41 , V_58 ) ;
V_44 = F_68 ( F_3 ( V_6 ) ) ;
}
V_15:
F_49 ( V_6 , V_29 , V_37 , V_44 ) ;
return V_44 ;
}
static T_3 F_69 ( struct V_63 * V_17 ,
T_3 V_64 , int V_65 )
{
struct V_66 V_67 ;
int V_68 ;
if ( V_65 != V_69 )
return 0 ;
F_70 ( & V_67 , 0 ) ;
V_68 = F_71 ( & V_67 , V_17 , & V_64 ,
V_70 , 1 ) ;
V_64 = V_68 ? V_67 . V_71 [ 0 ] -> V_16 : V_50 ;
F_72 ( & V_67 ) ;
return V_64 ;
}
static bool F_73 ( T_4 V_72 , T_3 V_73 , T_3 V_64 ,
int V_65 )
{
switch ( V_65 ) {
case V_69 :
if ( ( V_72 == V_74 && V_73 == V_64 ) ||
( V_72 != V_74 && V_72 != V_75 ) )
return true ;
break;
case V_76 :
if ( V_72 == V_75 )
return true ;
break;
}
return false ;
}
static T_2 F_74 ( struct V_34 * V_34 , T_2 V_22 , int V_65 )
{
struct V_6 * V_6 = V_34 -> V_38 -> V_39 ;
T_2 V_77 = V_6 -> V_13 -> V_78 ;
struct V_10 V_11 ;
T_3 V_64 , V_79 , V_73 ;
T_2 V_80 = V_22 ;
T_2 V_81 ;
int V_12 = 0 ;
F_75 ( & V_6 -> V_82 ) ;
V_81 = F_15 ( V_6 ) ;
if ( V_22 >= V_81 )
goto V_83;
if ( F_76 ( V_6 ) ) {
if ( V_65 == V_76 )
V_80 = V_81 ;
goto V_84;
}
V_64 = ( T_3 ) ( V_22 >> V_21 ) ;
V_73 = F_69 ( V_6 -> V_18 , V_64 , V_65 ) ;
for (; V_80 < V_81 ; V_80 = V_64 << V_21 ) {
F_8 ( & V_11 , V_6 , NULL , NULL , 0 ) ;
V_12 = F_77 ( & V_11 , V_64 , V_85 ) ;
if ( V_12 && V_12 != - V_86 ) {
goto V_83;
} else if ( V_12 == - V_86 ) {
if ( V_65 == V_69 ) {
V_64 = F_78 ( V_64 ,
F_38 ( V_6 ) ) ;
continue;
} else {
goto V_84;
}
}
V_79 = F_79 ( V_11 . V_87 , F_38 ( V_6 ) ) ;
for (; V_11 . V_88 < V_79 ;
V_11 . V_88 ++ , V_64 ++ ,
V_80 = V_64 << V_21 ) {
T_4 V_72 ;
V_72 = F_80 ( V_11 . V_87 , V_11 . V_88 ) ;
if ( F_73 ( V_72 , V_73 , V_64 , V_65 ) ) {
F_81 ( & V_11 ) ;
goto V_84;
}
}
F_81 ( & V_11 ) ;
}
if ( V_65 == V_69 )
goto V_83;
V_84:
if ( V_65 == V_76 && V_80 > V_81 )
V_80 = V_81 ;
F_82 ( & V_6 -> V_82 ) ;
return F_83 ( V_34 , V_80 , V_77 ) ;
V_83:
F_82 ( & V_6 -> V_82 ) ;
return - V_89 ;
}
static T_2 F_84 ( struct V_34 * V_34 , T_2 V_22 , int V_65 )
{
struct V_6 * V_6 = V_34 -> V_38 -> V_39 ;
T_2 V_77 = V_6 -> V_13 -> V_78 ;
switch ( V_65 ) {
case V_90 :
case V_91 :
case V_92 :
return F_85 ( V_34 , V_22 , V_65 ,
V_77 , F_15 ( V_6 ) ) ;
case V_69 :
case V_76 :
if ( V_22 < 0 )
return - V_89 ;
return F_74 ( V_34 , V_22 , V_65 ) ;
}
return - V_93 ;
}
static int F_86 ( struct V_34 * V_34 , struct V_1 * V_2 )
{
F_87 ( V_34 ) ;
V_2 -> V_94 = & V_95 ;
return 0 ;
}
int F_88 ( struct V_10 * V_11 , int V_96 )
{
int V_97 = 0 , V_98 = V_11 -> V_88 ;
struct V_8 * V_9 = F_3 ( V_11 -> V_6 ) ;
struct V_99 * V_100 ;
T_5 * V_101 ;
V_100 = F_89 ( V_11 -> V_87 ) ;
V_101 = F_90 ( V_100 ) + V_98 ;
for (; V_96 > 0 ; V_96 -- , V_101 ++ , V_11 -> V_88 ++ ) {
T_4 V_72 = F_91 ( * V_101 ) ;
if ( V_72 == V_75 )
continue;
F_92 ( V_75 , V_11 ) ;
F_93 ( V_9 , V_72 ) ;
V_97 ++ ;
}
if ( V_97 ) {
F_94 ( V_9 , V_11 -> V_6 , V_97 ) ;
F_20 ( V_11 -> V_87 ) ;
F_95 ( V_11 ) ;
}
V_11 -> V_88 = V_98 ;
F_96 ( V_11 -> V_6 , V_11 -> V_102 ,
V_11 -> V_88 , V_97 ) ;
return V_97 ;
}
void F_97 ( struct V_10 * V_11 )
{
F_88 ( V_11 , V_103 ) ;
}
static void F_98 ( struct V_6 * V_6 , T_6 V_104 )
{
unsigned V_22 = V_104 & ( V_24 - 1 ) ;
struct V_5 * V_5 ;
if ( F_76 ( V_6 ) )
return F_99 ( V_6 , V_104 ) ;
if ( ! V_22 )
return;
V_5 = F_100 ( V_6 , V_104 >> V_21 , false ) ;
if ( F_101 ( V_5 ) )
return;
F_12 ( V_5 ) ;
if ( F_13 ( ! F_16 ( V_5 ) ||
V_5 -> V_17 != V_6 -> V_18 ) )
goto V_15;
F_23 ( V_5 , V_25 ) ;
F_102 ( V_5 , V_22 , V_24 - V_22 ) ;
F_20 ( V_5 ) ;
V_15:
F_56 ( V_5 , 1 ) ;
}
int F_103 ( struct V_6 * V_6 , T_6 V_104 , bool V_105 )
{
struct V_8 * V_9 = F_3 ( V_6 ) ;
unsigned int V_106 = V_6 -> V_13 -> V_107 ;
struct V_10 V_11 ;
T_3 V_108 ;
int V_96 = 0 , V_12 = 0 ;
F_104 ( V_6 , V_104 ) ;
if ( F_76 ( V_6 ) )
goto V_109;
V_108 = ( T_3 )
( ( V_104 + V_106 - 1 ) >> ( V_9 -> V_110 ) ) ;
if ( V_105 )
F_7 ( V_9 ) ;
F_8 ( & V_11 , V_6 , NULL , NULL , 0 ) ;
V_12 = F_77 ( & V_11 , V_108 , V_111 ) ;
if ( V_12 ) {
if ( V_12 == - V_86 )
goto V_112;
if ( V_105 )
F_10 ( V_9 ) ;
F_105 ( V_6 , V_12 ) ;
return V_12 ;
}
V_96 = F_79 ( V_11 . V_87 , F_38 ( V_6 ) ) ;
V_96 -= V_11 . V_88 ;
F_106 ( V_9 , V_96 < 0 ) ;
if ( V_11 . V_88 || F_107 ( V_11 . V_87 ) ) {
F_88 ( & V_11 , V_96 ) ;
V_108 += V_96 ;
}
F_81 ( & V_11 ) ;
V_112:
V_12 = F_108 ( V_6 , V_108 ) ;
if ( V_105 )
F_10 ( V_9 ) ;
V_109:
F_98 ( V_6 , V_104 ) ;
F_105 ( V_6 , V_12 ) ;
return V_12 ;
}
void F_109 ( struct V_6 * V_6 )
{
if ( ! ( F_34 ( V_6 -> V_30 ) || F_110 ( V_6 -> V_30 ) ||
F_111 ( V_6 -> V_30 ) ) )
return;
F_112 ( V_6 ) ;
if ( ! F_103 ( V_6 , F_15 ( V_6 ) , true ) ) {
V_6 -> V_113 = V_6 -> V_114 = V_115 ;
F_113 ( V_6 ) ;
}
}
int F_114 ( struct V_116 * V_117 ,
struct V_27 * V_27 , struct V_118 * V_119 )
{
struct V_6 * V_6 = V_27 -> V_120 ;
F_115 ( V_6 , V_119 ) ;
V_119 -> V_121 <<= 3 ;
return 0 ;
}
static void F_116 ( struct V_6 * V_6 , const struct V_122 * V_123 )
{
struct V_40 * V_41 = F_38 ( V_6 ) ;
unsigned int V_124 = V_123 -> V_124 ;
if ( V_124 & V_125 )
V_6 -> V_126 = V_123 -> V_127 ;
if ( V_124 & V_128 )
V_6 -> V_129 = V_123 -> V_130 ;
if ( V_124 & V_131 )
V_6 -> V_132 = F_117 ( V_123 -> V_133 ,
V_6 -> V_13 -> V_134 ) ;
if ( V_124 & V_135 )
V_6 -> V_113 = F_117 ( V_123 -> V_136 ,
V_6 -> V_13 -> V_134 ) ;
if ( V_124 & V_137 )
V_6 -> V_114 = F_117 ( V_123 -> V_138 ,
V_6 -> V_13 -> V_134 ) ;
if ( V_124 & V_139 ) {
T_7 V_140 = V_123 -> V_141 ;
if ( ! F_118 ( V_6 -> V_129 ) && ! F_119 ( V_142 ) )
V_140 &= ~ V_143 ;
F_120 ( V_41 , V_140 ) ;
}
}
int F_121 ( struct V_27 * V_27 , struct V_122 * V_123 )
{
struct V_6 * V_6 = V_27 -> V_120 ;
struct V_40 * V_41 = F_38 ( V_6 ) ;
int V_12 ;
V_12 = F_122 ( V_6 , V_123 ) ;
if ( V_12 )
return V_12 ;
if ( V_123 -> V_124 & V_144 ) {
V_12 = F_6 ( V_6 , V_123 -> V_145 , NULL ) ;
if ( V_12 )
return V_12 ;
if ( V_123 -> V_145 != F_15 ( V_6 ) ) {
F_123 ( V_6 , V_123 -> V_145 ) ;
F_109 ( V_6 ) ;
F_4 ( F_3 ( V_6 ) ) ;
} else {
F_109 ( V_6 ) ;
}
}
F_116 ( V_6 , V_123 ) ;
if ( V_123 -> V_124 & V_139 ) {
V_12 = F_124 ( V_6 , F_125 ( V_6 ) ) ;
if ( V_12 || F_50 ( V_41 , V_146 ) ) {
V_6 -> V_30 = V_41 -> V_147 ;
F_48 ( V_41 , V_146 ) ;
}
}
F_113 ( V_6 ) ;
return V_12 ;
}
static void F_126 ( struct V_6 * V_6 , T_3 V_16 ,
T_2 V_35 , T_2 V_148 )
{
struct V_8 * V_9 = F_3 ( V_6 ) ;
struct V_5 * V_5 ;
if ( ! V_148 )
return;
F_4 ( V_9 ) ;
F_7 ( V_9 ) ;
V_5 = F_127 ( V_6 , NULL , V_16 , false ) ;
F_10 ( V_9 ) ;
if ( ! F_101 ( V_5 ) ) {
F_23 ( V_5 , V_25 ) ;
F_102 ( V_5 , V_35 , V_148 ) ;
F_20 ( V_5 ) ;
F_56 ( V_5 , 1 ) ;
}
}
int F_128 ( struct V_6 * V_6 , T_3 V_149 , T_3 V_150 )
{
T_3 V_16 ;
int V_12 ;
for ( V_16 = V_149 ; V_16 < V_150 ; V_16 ++ ) {
struct V_10 V_11 ;
F_8 ( & V_11 , V_6 , NULL , NULL , 0 ) ;
V_12 = F_77 ( & V_11 , V_16 , V_111 ) ;
if ( V_12 ) {
if ( V_12 == - V_86 )
continue;
return V_12 ;
}
if ( V_11 . V_151 != V_75 )
F_88 ( & V_11 , 1 ) ;
F_81 ( & V_11 ) ;
}
return 0 ;
}
static int F_129 ( struct V_6 * V_6 , T_2 V_22 , T_2 V_148 )
{
T_3 V_149 , V_150 ;
T_2 V_152 , V_153 ;
int V_44 = 0 ;
if ( ! F_34 ( V_6 -> V_30 ) )
return - V_154 ;
if ( V_22 >= V_6 -> V_155 )
return V_44 ;
V_44 = F_6 ( V_6 , V_14 + 1 , NULL ) ;
if ( V_44 )
return V_44 ;
V_149 = ( ( unsigned long long ) V_22 ) >> V_21 ;
V_150 = ( ( unsigned long long ) V_22 + V_148 ) >> V_21 ;
V_152 = V_22 & ( V_24 - 1 ) ;
V_153 = ( V_22 + V_148 ) & ( V_24 - 1 ) ;
if ( V_149 == V_150 ) {
F_126 ( V_6 , V_149 , V_152 ,
V_153 - V_152 ) ;
} else {
if ( V_152 )
F_126 ( V_6 , V_149 ++ , V_152 ,
V_24 - V_152 ) ;
if ( V_153 )
F_126 ( V_6 , V_150 , 0 , V_153 ) ;
if ( V_149 < V_150 ) {
struct V_63 * V_17 = V_6 -> V_18 ;
T_2 V_156 , V_157 ;
struct V_8 * V_9 = F_3 ( V_6 ) ;
F_4 ( V_9 ) ;
V_156 = V_149 << V_21 ;
V_157 = V_150 << V_21 ;
F_130 ( V_17 , V_156 ,
V_157 - 1 ) ;
F_7 ( V_9 ) ;
V_44 = F_128 ( V_6 , V_149 , V_150 ) ;
F_10 ( V_9 ) ;
}
}
return V_44 ;
}
static int F_131 ( struct V_6 * V_6 , T_2 V_22 ,
T_2 V_148 , int V_140 )
{
struct V_8 * V_9 = F_3 ( V_6 ) ;
T_3 V_16 , V_149 , V_150 ;
T_2 V_158 = F_15 ( V_6 ) ;
T_2 V_152 , V_153 ;
int V_44 = 0 ;
F_4 ( V_9 ) ;
V_44 = F_132 ( V_6 , ( V_148 + V_22 ) ) ;
if ( V_44 )
return V_44 ;
V_44 = F_6 ( V_6 , V_22 + V_148 , NULL ) ;
if ( V_44 )
return V_44 ;
V_149 = ( ( unsigned long long ) V_22 ) >> V_21 ;
V_150 = ( ( unsigned long long ) V_22 + V_148 ) >> V_21 ;
V_152 = V_22 & ( V_24 - 1 ) ;
V_153 = ( V_22 + V_148 ) & ( V_24 - 1 ) ;
F_7 ( V_9 ) ;
for ( V_16 = V_149 ; V_16 <= V_150 ; V_16 ++ ) {
struct V_10 V_11 ;
if ( V_16 == V_150 && ! V_153 )
goto V_159;
F_8 ( & V_11 , V_6 , NULL , NULL , 0 ) ;
V_44 = F_9 ( & V_11 , V_16 ) ;
if ( V_44 )
break;
V_159:
if ( V_149 == V_150 )
V_158 = V_22 + V_148 ;
else if ( V_16 == V_149 && V_152 )
V_158 = ( V_16 + 1 ) << V_21 ;
else if ( V_16 == V_150 )
V_158 = ( V_16 << V_21 ) + V_153 ;
else
V_158 += V_24 ;
}
if ( ! ( V_140 & V_160 ) &&
F_15 ( V_6 ) < V_158 ) {
F_133 ( V_6 , V_158 ) ;
F_113 ( V_6 ) ;
F_134 ( V_6 ) ;
}
F_10 ( V_9 ) ;
return V_44 ;
}
static long F_135 ( struct V_34 * V_34 , int V_140 ,
T_2 V_22 , T_2 V_148 )
{
struct V_6 * V_6 = F_2 ( V_34 ) ;
long V_44 ;
if ( V_140 & ~ ( V_160 | V_161 ) )
return - V_154 ;
F_75 ( & V_6 -> V_82 ) ;
if ( V_140 & V_161 )
V_44 = F_129 ( V_6 , V_22 , V_148 ) ;
else
V_44 = F_131 ( V_6 , V_22 , V_148 , V_140 ) ;
if ( ! V_44 ) {
V_6 -> V_113 = V_6 -> V_114 = V_115 ;
F_113 ( V_6 ) ;
}
F_82 ( & V_6 -> V_82 ) ;
F_136 ( V_6 , V_140 , V_22 , V_148 , V_44 ) ;
return V_44 ;
}
static inline T_8 F_137 ( T_7 V_140 , T_8 V_162 )
{
if ( F_110 ( V_140 ) )
return V_162 ;
else if ( F_34 ( V_140 ) )
return V_162 & V_163 ;
else
return V_162 & V_164 ;
}
static int F_138 ( struct V_34 * V_165 , unsigned long V_166 )
{
struct V_6 * V_6 = F_2 ( V_165 ) ;
struct V_40 * V_41 = F_38 ( V_6 ) ;
unsigned int V_162 = V_41 -> V_167 & V_168 ;
return F_139 ( V_162 , ( int V_169 * ) V_166 ) ;
}
static int F_140 ( struct V_34 * V_165 , unsigned long V_166 )
{
struct V_6 * V_6 = F_2 ( V_165 ) ;
struct V_40 * V_41 = F_38 ( V_6 ) ;
unsigned int V_162 = V_41 -> V_167 & V_168 ;
unsigned int V_170 ;
int V_44 ;
V_44 = F_141 ( V_165 ) ;
if ( V_44 )
return V_44 ;
if ( ! F_142 ( V_6 ) ) {
V_44 = - V_171 ;
goto V_15;
}
if ( F_143 ( V_162 , ( int V_169 * ) V_166 ) ) {
V_44 = - V_19 ;
goto V_15;
}
V_162 = F_137 ( V_6 -> V_30 , V_162 ) ;
F_75 ( & V_6 -> V_82 ) ;
V_170 = V_41 -> V_167 ;
if ( ( V_162 ^ V_170 ) & ( V_172 | V_173 ) ) {
if ( ! F_119 ( V_174 ) ) {
F_82 ( & V_6 -> V_82 ) ;
V_44 = - V_175 ;
goto V_15;
}
}
V_162 = V_162 & V_176 ;
V_162 |= V_170 & ~ V_176 ;
V_41 -> V_167 = V_162 ;
F_82 ( & V_6 -> V_82 ) ;
F_144 ( V_6 ) ;
V_6 -> V_114 = V_115 ;
F_113 ( V_6 ) ;
V_15:
F_145 ( V_165 ) ;
return V_44 ;
}
static int F_146 ( struct V_34 * V_165 )
{
struct V_6 * V_6 = F_2 ( V_165 ) ;
struct V_8 * V_9 = F_3 ( V_6 ) ;
if ( ! F_142 ( V_6 ) )
return - V_171 ;
F_4 ( V_9 ) ;
F_46 ( F_38 ( V_6 ) , V_177 ) ;
return F_6 ( V_6 , V_14 + 1 , NULL ) ;
}
static int F_147 ( struct V_34 * V_165 )
{
struct V_6 * V_6 = F_2 ( V_165 ) ;
int V_44 ;
if ( ! F_142 ( V_6 ) )
return - V_171 ;
if ( F_148 ( V_6 ) )
return 0 ;
V_44 = F_141 ( V_165 ) ;
if ( V_44 )
return V_44 ;
if ( F_149 ( V_6 ) )
F_150 ( V_6 , false ) ;
V_44 = F_41 ( V_165 , 0 , V_50 , 0 ) ;
F_145 ( V_165 ) ;
return V_44 ;
}
static int F_151 ( struct V_34 * V_165 )
{
struct V_6 * V_6 = F_2 ( V_165 ) ;
if ( ! F_142 ( V_6 ) )
return - V_171 ;
F_46 ( F_38 ( V_6 ) , V_178 ) ;
return 0 ;
}
static int F_152 ( struct V_34 * V_165 , unsigned long V_166 )
{
struct V_6 * V_6 = F_2 ( V_165 ) ;
struct V_179 * V_180 = V_6 -> V_13 ;
struct V_181 * V_182 = F_153 ( V_180 -> V_183 ) ;
struct V_184 V_185 ;
int V_44 ;
if ( ! F_119 ( V_186 ) )
return - V_175 ;
if ( ! F_154 ( V_182 ) )
return - V_154 ;
if ( F_155 ( & V_185 , (struct V_184 V_169 * ) V_166 ,
sizeof( V_185 ) ) )
return - V_19 ;
V_185 . V_187 = F_156 ( ( unsigned int ) V_185 . V_187 ,
V_182 -> V_188 . V_189 ) ;
V_44 = F_157 ( F_158 ( V_180 ) , & V_185 ) ;
if ( V_44 < 0 )
return V_44 ;
if ( F_159 ( (struct V_184 V_169 * ) V_166 , & V_185 ,
sizeof( V_185 ) ) )
return - V_19 ;
return 0 ;
}
long F_160 ( struct V_34 * V_165 , unsigned int V_190 , unsigned long V_166 )
{
switch ( V_190 ) {
case V_191 :
return F_138 ( V_165 , V_166 ) ;
case V_192 :
return F_140 ( V_165 , V_166 ) ;
case V_193 :
return F_146 ( V_165 ) ;
case V_194 :
return F_147 ( V_165 ) ;
case V_195 :
return F_151 ( V_165 ) ;
case V_196 :
return F_152 ( V_165 , V_166 ) ;
default:
return - V_197 ;
}
}
long F_161 ( struct V_34 * V_34 , unsigned int V_190 , unsigned long V_166 )
{
switch ( V_190 ) {
case V_198 :
V_190 = V_191 ;
break;
case V_199 :
V_190 = V_192 ;
break;
default:
return - V_200 ;
}
return F_160 ( V_34 , V_190 , ( unsigned long ) F_162 ( V_166 ) ) ;
}
