static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_5 = V_4 -> V_5 ;
struct V_6 * V_6 = F_2 ( V_2 -> V_7 ) ;
struct V_8 * V_9 = F_3 ( V_6 -> V_10 ) ;
struct V_11 V_12 ;
int V_13 ;
F_4 ( V_9 ) ;
F_5 ( V_6 -> V_10 ) ;
F_6 ( V_9 ) ;
F_7 ( & V_12 , V_6 , NULL , NULL , 0 ) ;
V_13 = F_8 ( & V_12 , V_5 -> V_14 ) ;
F_9 ( V_9 ) ;
if ( V_13 )
goto V_15;
F_10 ( V_2 -> V_7 ) ;
F_11 ( V_5 ) ;
if ( F_12 ( V_5 -> V_16 != V_6 -> V_17 ||
F_13 ( V_5 ) > F_14 ( V_6 ) ||
! F_15 ( V_5 ) ) ) {
F_16 ( V_5 ) ;
V_13 = - V_18 ;
goto V_15;
}
if ( F_17 ( V_5 ) )
goto V_19;
if ( ( ( V_5 -> V_14 + 1 ) << V_20 ) > F_14 ( V_6 ) ) {
unsigned V_21 ;
V_21 = F_14 ( V_6 ) & ~ V_22 ;
F_18 ( V_5 , V_21 , V_23 ) ;
}
F_19 ( V_5 ) ;
F_20 ( V_5 ) ;
F_21 ( V_5 , V_24 ) ;
V_19:
F_22 ( V_5 , V_24 ) ;
V_15:
F_23 ( V_6 -> V_10 ) ;
return F_24 ( V_13 ) ;
}
static int F_25 ( struct V_6 * V_6 , T_1 * V_25 )
{
struct V_26 * V_26 ;
V_6 = F_26 ( V_6 ) ;
V_26 = F_27 ( V_6 ) ;
F_28 ( V_6 ) ;
if ( ! V_26 )
return 0 ;
if ( F_29 ( V_6 , & V_26 -> V_27 ) ) {
F_30 ( V_26 ) ;
return 0 ;
}
* V_25 = F_31 ( V_26 ) ;
F_30 ( V_26 ) ;
return 1 ;
}
int F_32 ( struct V_28 * V_28 , T_2 V_29 , T_2 V_30 , int V_31 )
{
struct V_6 * V_6 = V_28 -> V_32 -> V_33 ;
struct V_34 * V_35 = F_33 ( V_6 ) ;
struct V_8 * V_9 = F_3 ( V_6 -> V_10 ) ;
int V_36 = 0 ;
bool V_37 = false ;
struct V_38 V_39 = {
. V_40 = V_41 ,
. V_42 = V_43 ,
. V_44 = 0 ,
} ;
if ( F_12 ( F_34 ( V_6 -> V_10 ) ) )
return 0 ;
F_35 ( V_6 ) ;
V_36 = F_36 ( V_6 -> V_17 , V_29 , V_30 ) ;
if ( V_36 ) {
F_37 ( V_6 , V_37 , V_31 , V_36 ) ;
return V_36 ;
}
F_4 ( V_9 ) ;
F_38 ( & V_35 -> V_45 ) ;
if ( ! F_39 ( V_6 -> V_46 ) || V_6 -> V_47 != 1 )
V_37 = true ;
else if ( F_40 ( V_6 ) )
V_37 = true ;
else if ( ! F_41 ( V_9 ) )
V_37 = true ;
else if ( ! F_42 ( V_9 , F_33 ( V_6 ) -> V_48 ) )
V_37 = true ;
else if ( F_33 ( V_6 ) -> V_49 == F_43 ( F_44 ( V_9 ) ) )
V_37 = true ;
F_45 ( & V_35 -> V_45 ) ;
if ( V_37 ) {
T_1 V_25 ;
V_36 = F_46 ( V_6 -> V_10 , 1 ) ;
F_47 ( & V_35 -> V_45 ) ;
F_33 ( V_6 ) -> V_49 = 0 ;
if ( F_40 ( V_6 ) && V_6 -> V_47 == 1 &&
F_25 ( V_6 , & V_25 ) ) {
F_33 ( V_6 ) -> V_48 = V_25 ;
F_48 ( V_6 ) ;
F_49 ( & V_35 -> V_45 ) ;
F_50 ( V_6 ) ;
V_36 = F_51 ( V_6 , NULL ) ;
if ( V_36 )
goto V_15;
} else {
F_49 ( & V_35 -> V_45 ) ;
}
} else {
while ( ! F_52 ( V_9 , V_6 -> V_50 , & V_39 ) ) {
if ( F_53 ( V_9 , V_6 -> V_50 ) )
goto V_15;
F_50 ( V_6 ) ;
V_36 = F_51 ( V_6 , NULL ) ;
if ( V_36 )
goto V_15;
}
V_36 = F_54 ( V_9 , V_6 -> V_50 ) ;
if ( V_36 )
goto V_15;
V_36 = F_55 ( F_3 ( V_6 -> V_10 ) ) ;
}
V_15:
F_37 ( V_6 , V_37 , V_31 , V_36 ) ;
return V_36 ;
}
static T_3 F_56 ( struct V_51 * V_16 ,
T_3 V_52 , int V_53 )
{
struct V_54 V_55 ;
int V_56 ;
if ( V_53 != V_57 )
return 0 ;
F_57 ( & V_55 , 0 ) ;
V_56 = F_58 ( & V_55 , V_16 , & V_52 , V_58 , 1 ) ;
V_52 = V_56 ? V_55 . V_59 [ 0 ] -> V_14 : V_43 ;
F_59 ( & V_55 ) ;
return V_52 ;
}
static bool F_60 ( T_4 V_60 , T_3 V_61 , T_3 V_52 ,
int V_53 )
{
switch ( V_53 ) {
case V_57 :
if ( ( V_60 == V_62 && V_61 == V_52 ) ||
( V_60 != V_62 && V_60 != V_63 ) )
return true ;
break;
case V_64 :
if ( V_60 == V_63 )
return true ;
break;
}
return false ;
}
static T_2 F_61 ( struct V_28 * V_28 , T_2 V_21 , int V_53 )
{
struct V_6 * V_6 = V_28 -> V_32 -> V_33 ;
T_2 V_65 = V_6 -> V_10 -> V_66 ;
struct V_11 V_12 ;
T_3 V_52 , V_67 , V_61 ;
T_2 V_68 = V_21 ;
T_2 V_69 ;
int V_13 = 0 ;
F_62 ( & V_6 -> V_70 ) ;
V_69 = F_14 ( V_6 ) ;
if ( V_21 >= V_69 )
goto V_71;
if ( F_63 ( V_6 ) ) {
if ( V_53 == V_64 )
V_68 = V_69 ;
goto V_72;
}
V_52 = ( T_3 ) ( V_21 >> V_20 ) ;
V_61 = F_56 ( V_6 -> V_17 , V_52 , V_53 ) ;
for (; V_68 < V_69 ; V_68 = V_52 << V_20 ) {
F_7 ( & V_12 , V_6 , NULL , NULL , 0 ) ;
V_13 = F_64 ( & V_12 , V_52 , V_73 ) ;
if ( V_13 && V_13 != - V_74 ) {
goto V_71;
} else if ( V_13 == - V_74 ) {
if ( V_53 == V_57 ) {
V_52 = F_65 ( V_52 ,
F_33 ( V_6 ) ) ;
continue;
} else {
goto V_72;
}
}
V_67 = F_66 ( V_12 . V_75 ) ?
F_67 ( F_33 ( V_6 ) ) : V_76 ;
for (; V_12 . V_77 < V_67 ;
V_12 . V_77 ++ , V_52 ++ ,
V_68 = V_52 << V_20 ) {
T_4 V_60 ;
V_60 = F_68 ( V_12 . V_75 , V_12 . V_77 ) ;
if ( F_60 ( V_60 , V_61 , V_52 , V_53 ) ) {
F_69 ( & V_12 ) ;
goto V_72;
}
}
F_69 ( & V_12 ) ;
}
if ( V_53 == V_57 )
goto V_71;
V_72:
if ( V_53 == V_64 && V_68 > V_69 )
V_68 = V_69 ;
F_70 ( & V_6 -> V_70 ) ;
return F_71 ( V_28 , V_68 , V_65 ) ;
V_71:
F_70 ( & V_6 -> V_70 ) ;
return - V_78 ;
}
static T_2 F_72 ( struct V_28 * V_28 , T_2 V_21 , int V_53 )
{
struct V_6 * V_6 = V_28 -> V_32 -> V_33 ;
T_2 V_65 = V_6 -> V_10 -> V_66 ;
switch ( V_53 ) {
case V_79 :
case V_80 :
case V_81 :
return F_73 ( V_28 , V_21 , V_53 ,
V_65 , F_14 ( V_6 ) ) ;
case V_57 :
case V_64 :
return F_61 ( V_28 , V_21 , V_53 ) ;
}
return - V_82 ;
}
static int F_74 ( struct V_28 * V_28 , struct V_1 * V_2 )
{
F_75 ( V_28 ) ;
V_2 -> V_83 = & V_84 ;
return 0 ;
}
int F_76 ( struct V_11 * V_12 , int V_85 )
{
int V_86 = 0 , V_87 = V_12 -> V_77 ;
struct V_8 * V_9 = F_3 ( V_12 -> V_6 -> V_10 ) ;
struct V_88 * V_89 ;
T_5 * V_90 ;
V_89 = F_77 ( V_12 -> V_75 ) ;
V_90 = F_78 ( V_89 ) + V_87 ;
for (; V_85 > 0 ; V_85 -- , V_90 ++ , V_12 -> V_77 ++ ) {
T_4 V_60 = F_79 ( * V_90 ) ;
if ( V_60 == V_63 )
continue;
F_80 ( V_63 , V_12 ) ;
F_81 ( V_9 , V_60 ) ;
V_86 ++ ;
}
if ( V_86 ) {
F_82 ( V_9 , V_12 -> V_6 , V_86 ) ;
F_19 ( V_12 -> V_75 ) ;
F_83 ( V_12 ) ;
}
V_12 -> V_77 = V_87 ;
F_84 ( V_12 -> V_6 , V_12 -> V_91 ,
V_12 -> V_77 , V_86 ) ;
return V_86 ;
}
void F_85 ( struct V_11 * V_12 )
{
F_76 ( V_12 , V_76 ) ;
}
static void F_86 ( struct V_6 * V_6 , T_6 V_92 )
{
unsigned V_21 = V_92 & ( V_23 - 1 ) ;
struct V_5 * V_5 ;
if ( F_63 ( V_6 ) )
return F_87 ( V_6 , V_92 ) ;
if ( ! V_21 )
return;
V_5 = F_88 ( V_6 , V_92 >> V_20 , false ) ;
if ( F_89 ( V_5 ) )
return;
F_11 ( V_5 ) ;
if ( F_12 ( V_5 -> V_16 != V_6 -> V_17 ) ) {
F_90 ( V_5 , 1 ) ;
return;
}
F_22 ( V_5 , V_24 ) ;
F_91 ( V_5 , V_21 , V_23 - V_21 ) ;
F_19 ( V_5 ) ;
F_90 ( V_5 , 1 ) ;
}
int F_92 ( struct V_6 * V_6 , T_6 V_92 )
{
struct V_8 * V_9 = F_3 ( V_6 -> V_10 ) ;
unsigned int V_93 = V_6 -> V_10 -> V_94 ;
struct V_11 V_12 ;
T_3 V_95 ;
int V_85 = 0 , V_13 = 0 ;
F_93 ( V_6 , V_92 ) ;
if ( F_63 ( V_6 ) )
goto V_96;
V_95 = ( T_3 )
( ( V_92 + V_93 - 1 ) >> ( V_9 -> V_97 ) ) ;
F_6 ( V_9 ) ;
F_7 ( & V_12 , V_6 , NULL , NULL , 0 ) ;
V_13 = F_64 ( & V_12 , V_95 , V_98 ) ;
if ( V_13 ) {
if ( V_13 == - V_74 )
goto V_99;
F_9 ( V_9 ) ;
F_94 ( V_6 , V_13 ) ;
return V_13 ;
}
V_85 = F_95 ( V_12 . V_75 , F_33 ( V_6 ) ) ;
V_85 -= V_12 . V_77 ;
F_96 ( V_85 < 0 ) ;
if ( V_12 . V_77 || F_66 ( V_12 . V_75 ) ) {
F_76 ( & V_12 , V_85 ) ;
V_95 += V_85 ;
}
F_69 ( & V_12 ) ;
V_99:
V_13 = F_97 ( V_6 , V_95 ) ;
F_9 ( V_9 ) ;
V_96:
F_86 ( V_6 , V_92 ) ;
F_94 ( V_6 , V_13 ) ;
return V_13 ;
}
void F_98 ( struct V_6 * V_6 )
{
if ( ! ( F_39 ( V_6 -> V_46 ) || F_99 ( V_6 -> V_46 ) ||
F_100 ( V_6 -> V_46 ) ) )
return;
F_101 ( V_6 ) ;
if ( ! F_92 ( V_6 , F_14 ( V_6 ) ) ) {
V_6 -> V_100 = V_6 -> V_101 = V_102 ;
F_102 ( V_6 ) ;
}
}
int F_103 ( struct V_103 * V_104 ,
struct V_26 * V_26 , struct V_105 * V_106 )
{
struct V_6 * V_6 = V_26 -> V_107 ;
F_104 ( V_6 , V_106 ) ;
V_106 -> V_108 <<= 3 ;
return 0 ;
}
static void F_105 ( struct V_6 * V_6 , const struct V_109 * V_110 )
{
struct V_34 * V_35 = F_33 ( V_6 ) ;
unsigned int V_111 = V_110 -> V_111 ;
if ( V_111 & V_112 )
V_6 -> V_113 = V_110 -> V_114 ;
if ( V_111 & V_115 )
V_6 -> V_116 = V_110 -> V_117 ;
if ( V_111 & V_118 )
V_6 -> V_119 = F_106 ( V_110 -> V_120 ,
V_6 -> V_10 -> V_121 ) ;
if ( V_111 & V_122 )
V_6 -> V_100 = F_106 ( V_110 -> V_123 ,
V_6 -> V_10 -> V_121 ) ;
if ( V_111 & V_124 )
V_6 -> V_101 = F_106 ( V_110 -> V_125 ,
V_6 -> V_10 -> V_121 ) ;
if ( V_111 & V_126 ) {
T_7 V_127 = V_110 -> V_128 ;
if ( ! F_107 ( V_6 -> V_116 ) && ! F_108 ( V_129 ) )
V_127 &= ~ V_130 ;
F_109 ( V_35 , V_127 ) ;
}
}
int F_110 ( struct V_26 * V_26 , struct V_109 * V_110 )
{
struct V_6 * V_6 = V_26 -> V_107 ;
struct V_34 * V_35 = F_33 ( V_6 ) ;
int V_13 ;
V_13 = F_111 ( V_6 , V_110 ) ;
if ( V_13 )
return V_13 ;
if ( ( V_110 -> V_111 & V_131 ) &&
V_110 -> V_132 != F_14 ( V_6 ) ) {
V_13 = F_112 ( V_6 , V_110 -> V_132 ) ;
if ( V_13 )
return V_13 ;
F_113 ( V_6 , V_110 -> V_132 ) ;
F_98 ( V_6 ) ;
F_4 ( F_3 ( V_6 -> V_10 ) ) ;
}
F_105 ( V_6 , V_110 ) ;
if ( V_110 -> V_111 & V_126 ) {
V_13 = F_114 ( V_6 , F_115 ( V_6 ) ) ;
if ( V_13 || F_116 ( V_35 , V_133 ) ) {
V_6 -> V_46 = V_35 -> V_134 ;
F_117 ( V_35 , V_133 ) ;
}
}
F_102 ( V_6 ) ;
return V_13 ;
}
static void F_118 ( struct V_6 * V_6 , T_3 V_14 ,
T_2 V_29 , T_2 V_135 )
{
struct V_8 * V_9 = F_3 ( V_6 -> V_10 ) ;
struct V_5 * V_5 ;
if ( ! V_135 )
return;
F_4 ( V_9 ) ;
F_6 ( V_9 ) ;
V_5 = F_119 ( V_6 , NULL , V_14 , false ) ;
F_9 ( V_9 ) ;
if ( ! F_89 ( V_5 ) ) {
F_22 ( V_5 , V_24 ) ;
F_91 ( V_5 , V_29 , V_135 ) ;
F_19 ( V_5 ) ;
F_90 ( V_5 , 1 ) ;
}
}
int F_120 ( struct V_6 * V_6 , T_3 V_136 , T_3 V_137 )
{
T_3 V_14 ;
int V_13 ;
for ( V_14 = V_136 ; V_14 < V_137 ; V_14 ++ ) {
struct V_11 V_12 ;
F_7 ( & V_12 , V_6 , NULL , NULL , 0 ) ;
V_13 = F_64 ( & V_12 , V_14 , V_98 ) ;
if ( V_13 ) {
if ( V_13 == - V_74 )
continue;
return V_13 ;
}
if ( V_12 . V_138 != V_63 )
F_76 ( & V_12 , 1 ) ;
F_69 ( & V_12 ) ;
}
return 0 ;
}
static int F_121 ( struct V_6 * V_6 , T_2 V_21 , T_2 V_135 )
{
T_3 V_136 , V_137 ;
T_2 V_139 , V_140 ;
int V_36 = 0 ;
V_36 = F_112 ( V_6 , V_141 + 1 ) ;
if ( V_36 )
return V_36 ;
V_136 = ( ( unsigned long long ) V_21 ) >> V_20 ;
V_137 = ( ( unsigned long long ) V_21 + V_135 ) >> V_20 ;
V_139 = V_21 & ( V_23 - 1 ) ;
V_140 = ( V_21 + V_135 ) & ( V_23 - 1 ) ;
if ( V_136 == V_137 ) {
F_118 ( V_6 , V_136 , V_139 ,
V_140 - V_139 ) ;
} else {
if ( V_139 )
F_118 ( V_6 , V_136 ++ , V_139 ,
V_23 - V_139 ) ;
if ( V_140 )
F_118 ( V_6 , V_137 , 0 , V_140 ) ;
if ( V_136 < V_137 ) {
struct V_51 * V_16 = V_6 -> V_17 ;
T_2 V_142 , V_143 ;
struct V_8 * V_9 = F_3 ( V_6 -> V_10 ) ;
F_4 ( V_9 ) ;
V_142 = V_136 << V_20 ;
V_143 = V_137 << V_20 ;
F_122 ( V_16 , V_142 ,
V_143 - 1 ) ;
F_6 ( V_9 ) ;
V_36 = F_120 ( V_6 , V_136 , V_137 ) ;
F_9 ( V_9 ) ;
}
}
return V_36 ;
}
static int F_123 ( struct V_6 * V_6 , T_2 V_21 ,
T_2 V_135 , int V_127 )
{
struct V_8 * V_9 = F_3 ( V_6 -> V_10 ) ;
T_3 V_14 , V_136 , V_137 ;
T_2 V_144 = F_14 ( V_6 ) ;
T_2 V_139 , V_140 ;
int V_36 = 0 ;
V_36 = F_124 ( V_6 , ( V_135 + V_21 ) ) ;
if ( V_36 )
return V_36 ;
V_36 = F_112 ( V_6 , V_21 + V_135 ) ;
if ( V_36 )
return V_36 ;
V_136 = ( ( unsigned long long ) V_21 ) >> V_20 ;
V_137 = ( ( unsigned long long ) V_21 + V_135 ) >> V_20 ;
V_139 = V_21 & ( V_23 - 1 ) ;
V_140 = ( V_21 + V_135 ) & ( V_23 - 1 ) ;
F_6 ( V_9 ) ;
for ( V_14 = V_136 ; V_14 <= V_137 ; V_14 ++ ) {
struct V_11 V_12 ;
if ( V_14 == V_137 && ! V_140 )
goto V_145;
F_7 ( & V_12 , V_6 , NULL , NULL , 0 ) ;
V_36 = F_8 ( & V_12 , V_14 ) ;
if ( V_36 )
break;
V_145:
if ( V_136 == V_137 )
V_144 = V_21 + V_135 ;
else if ( V_14 == V_136 && V_139 )
V_144 = ( V_14 + 1 ) << V_20 ;
else if ( V_14 == V_137 )
V_144 = ( V_14 << V_20 ) + V_140 ;
else
V_144 += V_23 ;
}
if ( ! ( V_127 & V_146 ) &&
F_14 ( V_6 ) < V_144 ) {
F_125 ( V_6 , V_144 ) ;
F_102 ( V_6 ) ;
F_126 ( V_6 ) ;
}
F_9 ( V_9 ) ;
return V_36 ;
}
static long F_127 ( struct V_28 * V_28 , int V_127 ,
T_2 V_21 , T_2 V_135 )
{
struct V_6 * V_6 = F_2 ( V_28 ) ;
long V_36 ;
if ( V_127 & ~ ( V_146 | V_147 ) )
return - V_148 ;
F_62 ( & V_6 -> V_70 ) ;
if ( V_127 & V_147 )
V_36 = F_121 ( V_6 , V_21 , V_135 ) ;
else
V_36 = F_123 ( V_6 , V_21 , V_135 , V_127 ) ;
if ( ! V_36 ) {
V_6 -> V_100 = V_6 -> V_101 = V_102 ;
F_102 ( V_6 ) ;
}
F_70 ( & V_6 -> V_70 ) ;
F_128 ( V_6 , V_127 , V_21 , V_135 , V_36 ) ;
return V_36 ;
}
static inline T_8 F_129 ( T_7 V_127 , T_8 V_149 )
{
if ( F_99 ( V_127 ) )
return V_149 ;
else if ( F_39 ( V_127 ) )
return V_149 & V_150 ;
else
return V_149 & V_151 ;
}
long F_130 ( struct V_28 * V_152 , unsigned int V_153 , unsigned long V_154 )
{
struct V_6 * V_6 = F_2 ( V_152 ) ;
struct V_34 * V_35 = F_33 ( V_6 ) ;
unsigned int V_149 ;
int V_36 ;
switch ( V_153 ) {
case V_155 :
V_149 = V_35 -> V_156 & V_157 ;
return F_131 ( V_149 , ( int V_158 * ) V_154 ) ;
case V_159 :
{
unsigned int V_160 ;
V_36 = F_132 ( V_152 ) ;
if ( V_36 )
return V_36 ;
if ( ! F_133 ( V_6 ) ) {
V_36 = - V_161 ;
goto V_15;
}
if ( F_134 ( V_149 , ( int V_158 * ) V_154 ) ) {
V_36 = - V_18 ;
goto V_15;
}
V_149 = F_129 ( V_6 -> V_46 , V_149 ) ;
F_62 ( & V_6 -> V_70 ) ;
V_160 = V_35 -> V_156 ;
if ( ( V_149 ^ V_160 ) & ( V_162 | V_163 ) ) {
if ( ! F_108 ( V_164 ) ) {
F_70 ( & V_6 -> V_70 ) ;
V_36 = - V_165 ;
goto V_15;
}
}
V_149 = V_149 & V_166 ;
V_149 |= V_160 & ~ V_166 ;
V_35 -> V_156 = V_149 ;
F_70 ( & V_6 -> V_70 ) ;
F_135 ( V_6 ) ;
V_6 -> V_101 = V_102 ;
F_102 ( V_6 ) ;
V_15:
F_136 ( V_152 ) ;
return V_36 ;
}
default:
return - V_167 ;
}
}
long F_137 ( struct V_28 * V_28 , unsigned int V_153 , unsigned long V_154 )
{
switch ( V_153 ) {
case V_168 :
V_153 = V_155 ;
break;
case V_169 :
V_153 = V_159 ;
break;
default:
return - V_170 ;
}
return F_130 ( V_28 , V_153 , ( unsigned long ) F_138 ( V_154 ) ) ;
}
