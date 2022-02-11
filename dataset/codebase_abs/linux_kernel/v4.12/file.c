static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = V_2 -> V_3 ;
struct V_4 * V_4 = F_2 ( V_2 -> V_5 -> V_6 ) ;
struct V_7 * V_8 = F_3 ( V_4 ) ;
struct V_9 V_10 ;
int V_11 ;
F_4 ( V_4 -> V_12 ) ;
F_5 ( V_8 , F_6 ( V_4 ) ) ;
F_7 ( V_8 ) ;
F_8 ( & V_10 , V_4 , NULL , NULL , 0 ) ;
V_11 = F_9 ( & V_10 , V_3 -> V_13 ) ;
if ( V_11 ) {
F_10 ( V_8 ) ;
goto V_14;
}
F_11 ( & V_10 ) ;
F_10 ( V_8 ) ;
F_12 ( V_8 , V_10 . V_15 ) ;
F_13 ( V_2 -> V_5 -> V_6 ) ;
F_14 ( V_3 ) ;
if ( F_15 ( V_3 -> V_16 != V_4 -> V_17 ||
F_16 ( V_3 ) > F_17 ( V_4 ) ||
! F_18 ( V_3 ) ) ) {
F_19 ( V_3 ) ;
V_11 = - V_18 ;
goto V_14;
}
if ( F_20 ( V_3 ) )
goto V_19;
if ( ( ( V_20 ) ( V_3 -> V_13 + 1 ) << V_21 ) >
F_17 ( V_4 ) ) {
unsigned V_22 ;
V_22 = F_17 ( V_4 ) & ~ V_23 ;
F_21 ( V_3 , V_22 , V_24 ) ;
}
F_22 ( V_3 ) ;
if ( ! F_18 ( V_3 ) )
F_23 ( V_3 ) ;
F_24 ( V_3 , V_25 ) ;
V_19:
F_25 ( V_3 , V_25 , false ) ;
if ( F_26 ( V_4 ) && F_27 ( V_4 -> V_26 ) )
F_28 ( V_8 , V_10 . V_27 ) ;
V_14:
F_29 ( V_4 -> V_12 ) ;
F_30 ( V_8 , V_28 ) ;
return F_31 ( V_11 ) ;
}
static int F_32 ( struct V_4 * V_4 , T_1 * V_29 )
{
struct V_30 * V_30 ;
V_4 = F_33 ( V_4 ) ;
V_30 = F_34 ( V_4 ) ;
F_35 ( V_4 ) ;
if ( ! V_30 )
return 0 ;
* V_29 = F_36 ( V_30 ) ;
F_37 ( V_30 ) ;
return 1 ;
}
static inline bool F_38 ( struct V_4 * V_4 )
{
struct V_7 * V_8 = F_3 ( V_4 ) ;
bool V_31 = false ;
if ( ! F_27 ( V_4 -> V_26 ) || V_4 -> V_32 != 1 )
V_31 = true ;
else if ( F_39 ( V_8 , V_33 ) )
V_31 = true ;
else if ( F_40 ( V_4 ) )
V_31 = true ;
else if ( ! F_41 ( V_8 ) )
V_31 = true ;
else if ( ! F_42 ( V_8 , F_43 ( V_4 ) -> V_34 ) )
V_31 = true ;
else if ( F_44 ( V_8 , V_35 ) )
V_31 = true ;
else if ( V_8 -> V_36 == 2 )
V_31 = true ;
return V_31 ;
}
static bool F_45 ( struct V_7 * V_8 , T_1 V_37 )
{
struct V_3 * V_38 = F_46 ( F_47 ( V_8 ) , V_37 ) ;
bool V_39 = false ;
if ( ( V_38 && F_48 ( V_38 ) ) || F_49 ( V_8 , V_37 ) )
V_39 = true ;
F_50 ( V_38 , 0 ) ;
return V_39 ;
}
static void F_51 ( struct V_4 * V_4 )
{
struct V_40 * V_41 = F_43 ( V_4 ) ;
T_1 V_29 ;
F_52 ( & V_41 -> V_42 ) ;
if ( F_40 ( V_4 ) && V_4 -> V_32 == 1 &&
F_32 ( V_4 , & V_29 ) ) {
F_53 ( V_4 , V_29 ) ;
F_54 ( V_4 ) ;
}
F_55 ( & V_41 -> V_42 ) ;
}
static int F_56 ( struct V_43 * V_43 , V_20 V_44 , V_20 V_45 ,
int V_46 , bool V_47 )
{
struct V_4 * V_4 = V_43 -> V_48 -> V_49 ;
struct V_7 * V_8 = F_3 ( V_4 ) ;
T_1 V_37 = V_4 -> V_50 ;
int V_39 = 0 ;
bool V_31 = false ;
struct V_51 V_52 = {
. V_53 = V_54 ,
. V_55 = V_56 ,
. V_57 = 0 ,
} ;
if ( F_15 ( F_57 ( V_4 -> V_12 ) ) )
return 0 ;
F_58 ( V_4 ) ;
if ( V_46 || F_59 ( V_4 ) <= F_60 ( V_8 ) -> V_58 )
F_61 ( V_4 , V_59 ) ;
V_39 = F_62 ( V_4 -> V_17 , V_44 , V_45 ) ;
F_63 ( V_4 , V_59 ) ;
if ( V_39 ) {
F_64 ( V_4 , V_31 , V_46 , V_39 ) ;
return V_39 ;
}
if ( ! F_65 ( V_4 , V_46 ) ) {
F_66 ( V_4 , NULL ) ;
goto V_60;
}
if ( ! F_67 ( V_4 , V_61 ) &&
! F_68 ( V_8 , V_37 , V_62 ) ) {
if ( F_45 ( V_8 , V_37 ) )
goto V_60;
if ( F_67 ( V_4 , V_63 ) ||
F_68 ( V_8 , V_37 , V_64 ) )
goto V_65;
goto V_14;
}
V_60:
F_69 ( & F_43 ( V_4 ) -> V_42 ) ;
V_31 = F_38 ( V_4 ) ;
F_70 ( & F_43 ( V_4 ) -> V_42 ) ;
if ( V_31 ) {
V_39 = F_71 ( V_4 -> V_12 , 1 ) ;
F_51 ( V_4 ) ;
F_63 ( V_4 , V_61 ) ;
F_63 ( V_4 , V_63 ) ;
goto V_14;
}
V_66:
V_39 = F_72 ( V_8 , V_4 , & V_52 , V_47 ) ;
if ( V_39 )
goto V_14;
if ( F_15 ( F_73 ( V_8 ) ) ) {
V_39 = - V_67 ;
goto V_14;
}
if ( F_49 ( V_8 , V_37 ) ) {
F_74 ( V_4 , true ) ;
F_66 ( V_4 , NULL ) ;
goto V_66;
}
V_39 = F_75 ( V_8 , V_37 ) ;
if ( V_39 )
goto V_14;
F_76 ( V_8 , V_37 , V_62 ) ;
F_63 ( V_4 , V_61 ) ;
V_65:
F_76 ( V_8 , V_37 , V_64 ) ;
F_63 ( V_4 , V_63 ) ;
if ( ! V_47 )
V_39 = F_77 ( V_8 ) ;
F_30 ( V_8 , V_28 ) ;
V_14:
F_64 ( V_4 , V_31 , V_46 , V_39 ) ;
F_78 ( NULL , 1 ) ;
return V_39 ;
}
int F_79 ( struct V_43 * V_43 , V_20 V_44 , V_20 V_45 , int V_46 )
{
return F_56 ( V_43 , V_44 , V_45 , V_46 , false ) ;
}
static T_2 F_80 ( struct V_68 * V_16 ,
T_2 V_69 , int V_70 )
{
struct V_71 V_72 ;
int V_73 ;
if ( V_70 != V_74 )
return 0 ;
F_81 ( & V_72 , 0 ) ;
V_73 = F_82 ( & V_72 , V_16 , & V_69 ,
V_75 , 1 ) ;
V_69 = V_73 ? V_72 . V_76 [ 0 ] -> V_13 : V_77 ;
F_83 ( & V_72 ) ;
return V_69 ;
}
static bool F_84 ( T_3 V_78 , T_2 V_79 , T_2 V_69 ,
int V_70 )
{
switch ( V_70 ) {
case V_74 :
if ( ( V_78 == V_80 && V_79 == V_69 ) ||
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
static V_20 F_85 ( struct V_43 * V_43 , V_20 V_22 , int V_70 )
{
struct V_4 * V_4 = V_43 -> V_48 -> V_49 ;
V_20 V_83 = V_4 -> V_12 -> V_84 ;
struct V_9 V_10 ;
T_2 V_69 , V_85 , V_79 ;
V_20 V_86 = V_22 ;
V_20 V_87 ;
int V_11 = 0 ;
F_86 ( V_4 ) ;
V_87 = F_17 ( V_4 ) ;
if ( V_22 >= V_87 )
goto V_88;
if ( F_6 ( V_4 ) || F_87 ( V_4 ) ) {
if ( V_70 == V_82 )
V_86 = V_87 ;
goto V_89;
}
V_69 = ( T_2 ) ( V_22 >> V_21 ) ;
V_79 = F_80 ( V_4 -> V_17 , V_69 , V_70 ) ;
for (; V_86 < V_87 ; V_86 = ( V_20 ) V_69 << V_21 ) {
F_8 ( & V_10 , V_4 , NULL , NULL , 0 ) ;
V_11 = F_88 ( & V_10 , V_69 , V_90 ) ;
if ( V_11 && V_11 != - V_91 ) {
goto V_88;
} else if ( V_11 == - V_91 ) {
if ( V_70 == V_74 ) {
V_69 = F_89 ( & V_10 , V_69 ) ;
continue;
} else {
goto V_89;
}
}
V_85 = F_90 ( V_10 . V_92 , V_4 ) ;
for (; V_10 . V_93 < V_85 ;
V_10 . V_93 ++ , V_69 ++ ,
V_86 = ( V_20 ) V_69 << V_21 ) {
T_3 V_78 ;
V_78 = F_91 ( V_10 . V_92 , V_10 . V_93 ) ;
if ( F_84 ( V_78 , V_79 , V_69 , V_70 ) ) {
F_11 ( & V_10 ) ;
goto V_89;
}
}
F_11 ( & V_10 ) ;
}
if ( V_70 == V_74 )
goto V_88;
V_89:
if ( V_70 == V_82 && V_86 > V_87 )
V_86 = V_87 ;
F_92 ( V_4 ) ;
return F_93 ( V_43 , V_86 , V_83 ) ;
V_88:
F_92 ( V_4 ) ;
return - V_94 ;
}
static V_20 F_94 ( struct V_43 * V_43 , V_20 V_22 , int V_70 )
{
struct V_4 * V_4 = V_43 -> V_48 -> V_49 ;
V_20 V_83 = V_4 -> V_12 -> V_84 ;
switch ( V_70 ) {
case V_95 :
case V_96 :
case V_97 :
return F_95 ( V_43 , V_22 , V_70 ,
V_83 , F_17 ( V_4 ) ) ;
case V_74 :
case V_82 :
if ( V_22 < 0 )
return - V_94 ;
return F_85 ( V_43 , V_22 , V_70 ) ;
}
return - V_98 ;
}
static int F_96 ( struct V_43 * V_43 , struct V_99 * V_5 )
{
struct V_4 * V_4 = F_2 ( V_43 ) ;
int V_11 ;
if ( F_26 ( V_4 ) ) {
V_11 = F_97 ( V_4 ) ;
if ( V_11 )
return 0 ;
if ( ! F_26 ( V_4 ) )
return - V_100 ;
}
V_11 = F_98 ( V_4 ) ;
if ( V_11 )
return V_11 ;
F_99 ( V_43 ) ;
V_5 -> V_101 = & V_102 ;
return 0 ;
}
static int F_100 ( struct V_4 * V_4 , struct V_43 * V_103 )
{
int V_39 = F_101 ( V_4 , V_103 ) ;
struct V_30 * V_104 ;
if ( ! V_39 && F_26 ( V_4 ) ) {
V_39 = F_97 ( V_4 ) ;
if ( V_39 )
return - V_105 ;
if ( ! F_102 ( V_4 ) )
return - V_100 ;
}
V_104 = F_103 ( F_104 ( V_103 ) ) ;
if ( F_26 ( F_105 ( V_104 ) ) &&
! F_106 ( F_105 ( V_104 ) , V_4 ) ) {
F_37 ( V_104 ) ;
return - V_106 ;
}
F_37 ( V_104 ) ;
return V_39 ;
}
int F_107 ( struct V_9 * V_10 , int V_107 )
{
struct V_7 * V_8 = F_3 ( V_10 -> V_4 ) ;
struct V_108 * V_109 ;
int V_110 = 0 , V_111 = V_10 -> V_93 , V_112 = V_107 ;
T_4 * V_113 ;
V_109 = F_108 ( V_10 -> V_92 ) ;
V_113 = F_109 ( V_109 ) + V_111 ;
for (; V_107 > 0 ; V_107 -- , V_113 ++ , V_10 -> V_93 ++ ) {
T_3 V_78 = F_110 ( * V_113 ) ;
if ( V_78 == V_81 )
continue;
V_10 -> V_27 = V_81 ;
F_111 ( V_10 ) ;
F_112 ( V_8 , V_78 ) ;
if ( V_10 -> V_93 == 0 && F_113 ( V_10 -> V_92 ) )
F_63 ( V_10 -> V_4 , V_114 ) ;
V_110 ++ ;
}
if ( V_110 ) {
T_2 V_115 ;
V_115 = F_114 ( F_115 ( V_10 -> V_92 ) ,
V_10 -> V_4 ) + V_111 ;
F_116 ( V_10 , V_115 , 0 , V_112 ) ;
F_117 ( V_8 , V_10 -> V_4 , V_110 ) ;
}
V_10 -> V_93 = V_111 ;
F_30 ( V_8 , V_28 ) ;
F_118 ( V_10 -> V_4 , V_10 -> V_116 ,
V_10 -> V_93 , V_110 ) ;
return V_110 ;
}
void F_119 ( struct V_9 * V_10 )
{
F_107 ( V_10 , V_117 ) ;
}
static int F_120 ( struct V_4 * V_4 , T_5 V_118 ,
bool V_119 )
{
unsigned V_22 = V_118 & ( V_24 - 1 ) ;
T_2 V_13 = V_118 >> V_21 ;
struct V_68 * V_16 = V_4 -> V_17 ;
struct V_3 * V_3 ;
if ( ! V_22 && ! V_119 )
return 0 ;
if ( V_119 ) {
V_3 = F_121 ( V_16 , V_13 ) ;
if ( V_3 && F_18 ( V_3 ) )
goto V_120;
F_50 ( V_3 , 1 ) ;
return 0 ;
}
V_3 = F_122 ( V_4 , V_13 , true ) ;
if ( F_123 ( V_3 ) )
return F_124 ( V_3 ) == - V_91 ? 0 : F_124 ( V_3 ) ;
V_120:
F_25 ( V_3 , V_25 , true ) ;
F_125 ( V_3 , V_22 , V_24 - V_22 ) ;
if ( ! V_119 || ! F_26 ( V_4 ) ||
! F_27 ( V_4 -> V_26 ) )
F_22 ( V_3 ) ;
F_50 ( V_3 , 1 ) ;
return 0 ;
}
int F_126 ( struct V_4 * V_4 , T_5 V_118 , bool V_121 )
{
struct V_7 * V_8 = F_3 ( V_4 ) ;
unsigned int V_122 = V_4 -> V_12 -> V_123 ;
struct V_9 V_10 ;
T_2 V_124 ;
int V_107 = 0 , V_11 = 0 ;
struct V_3 * V_125 ;
bool V_126 = false ;
F_127 ( V_4 , V_118 ) ;
V_124 = ( T_2 ) F_128 ( V_118 + V_122 - 1 ) ;
if ( V_124 >= V_8 -> V_127 )
goto V_128;
if ( V_121 )
F_7 ( V_8 ) ;
V_125 = F_129 ( V_8 , V_4 -> V_50 ) ;
if ( F_123 ( V_125 ) ) {
V_11 = F_124 ( V_125 ) ;
goto V_14;
}
if ( F_6 ( V_4 ) ) {
F_130 ( V_4 , V_125 , V_118 ) ;
F_50 ( V_125 , 1 ) ;
V_126 = true ;
goto V_14;
}
F_8 ( & V_10 , V_4 , V_125 , NULL , 0 ) ;
V_11 = F_88 ( & V_10 , V_124 , V_129 ) ;
if ( V_11 ) {
if ( V_11 == - V_91 )
goto V_130;
goto V_14;
}
V_107 = F_90 ( V_10 . V_92 , V_4 ) ;
V_107 -= V_10 . V_93 ;
F_5 ( V_8 , V_107 < 0 ) ;
if ( V_10 . V_93 || F_113 ( V_10 . V_92 ) ) {
F_107 ( & V_10 , V_107 ) ;
V_124 += V_107 ;
}
F_11 ( & V_10 ) ;
V_130:
V_11 = F_131 ( V_4 , V_124 ) ;
V_14:
if ( V_121 )
F_10 ( V_8 ) ;
V_128:
if ( ! V_11 )
V_11 = F_120 ( V_4 , V_118 , V_126 ) ;
F_132 ( V_4 , V_11 ) ;
return V_11 ;
}
int F_133 ( struct V_4 * V_4 )
{
int V_11 ;
if ( ! ( F_27 ( V_4 -> V_26 ) || F_134 ( V_4 -> V_26 ) ||
F_135 ( V_4 -> V_26 ) ) )
return 0 ;
F_136 ( V_4 ) ;
#ifdef F_137
if ( F_138 ( F_3 ( V_4 ) , V_131 ) ) {
F_139 ( V_131 ) ;
return - V_67 ;
}
#endif
if ( ! F_140 ( V_4 ) ) {
V_11 = F_98 ( V_4 ) ;
if ( V_11 )
return V_11 ;
}
V_11 = F_126 ( V_4 , F_17 ( V_4 ) , true ) ;
if ( V_11 )
return V_11 ;
V_4 -> V_132 = V_4 -> V_133 = F_141 ( V_4 ) ;
F_74 ( V_4 , false ) ;
return 0 ;
}
int F_142 ( const struct V_134 * V_134 , struct V_135 * V_136 ,
T_6 V_137 , unsigned int V_138 )
{
struct V_4 * V_4 = F_105 ( V_134 -> V_30 ) ;
F_143 ( V_4 , V_136 ) ;
V_136 -> V_139 <<= 3 ;
return 0 ;
}
static void F_144 ( struct V_4 * V_4 , const struct V_140 * V_141 )
{
unsigned int V_142 = V_141 -> V_142 ;
if ( V_142 & V_143 )
V_4 -> V_144 = V_141 -> V_145 ;
if ( V_142 & V_146 )
V_4 -> V_147 = V_141 -> V_148 ;
if ( V_142 & V_149 )
V_4 -> V_150 = F_145 ( V_141 -> V_151 ,
V_4 -> V_12 -> V_152 ) ;
if ( V_142 & V_153 )
V_4 -> V_132 = F_145 ( V_141 -> V_154 ,
V_4 -> V_12 -> V_152 ) ;
if ( V_142 & V_155 )
V_4 -> V_133 = F_145 ( V_141 -> V_156 ,
V_4 -> V_12 -> V_152 ) ;
if ( V_142 & V_157 ) {
T_7 V_158 = V_141 -> V_159 ;
if ( ! F_146 ( V_4 -> V_147 ) && ! F_147 ( V_160 ) )
V_158 &= ~ V_161 ;
F_148 ( V_4 , V_158 ) ;
}
}
int F_149 ( struct V_30 * V_30 , struct V_140 * V_141 )
{
struct V_4 * V_4 = F_105 ( V_30 ) ;
int V_11 ;
bool V_162 = false ;
V_11 = F_150 ( V_30 , V_141 ) ;
if ( V_11 )
return V_11 ;
if ( V_141 -> V_142 & V_163 ) {
if ( F_26 ( V_4 ) &&
F_97 ( V_4 ) )
return - V_105 ;
if ( V_141 -> V_164 <= F_17 ( V_4 ) ) {
F_151 ( V_4 , V_141 -> V_164 ) ;
V_11 = F_133 ( V_4 ) ;
if ( V_11 )
return V_11 ;
} else {
F_151 ( V_4 , V_141 -> V_164 ) ;
if ( ! F_140 ( V_4 ) ) {
V_11 = F_98 ( V_4 ) ;
if ( V_11 )
return V_11 ;
}
V_4 -> V_132 = V_4 -> V_133 = F_141 ( V_4 ) ;
}
V_162 = true ;
}
F_144 ( V_4 , V_141 ) ;
if ( V_141 -> V_142 & V_157 ) {
V_11 = F_152 ( V_4 , F_153 ( V_4 ) ) ;
if ( V_11 || F_67 ( V_4 , V_165 ) ) {
V_4 -> V_26 = F_43 ( V_4 ) -> V_166 ;
F_63 ( V_4 , V_165 ) ;
}
}
F_74 ( V_4 , V_162 ) ;
F_12 ( F_3 ( V_4 ) , true ) ;
return V_11 ;
}
static int F_154 ( struct V_4 * V_4 , T_2 V_13 ,
V_20 V_44 , V_20 V_112 )
{
struct V_7 * V_8 = F_3 ( V_4 ) ;
struct V_3 * V_3 ;
if ( ! V_112 )
return 0 ;
F_12 ( V_8 , true ) ;
F_7 ( V_8 ) ;
V_3 = F_155 ( V_4 , NULL , V_13 , false ) ;
F_10 ( V_8 ) ;
if ( F_123 ( V_3 ) )
return F_124 ( V_3 ) ;
F_25 ( V_3 , V_25 , true ) ;
F_125 ( V_3 , V_44 , V_112 ) ;
F_22 ( V_3 ) ;
F_50 ( V_3 , 1 ) ;
return 0 ;
}
int F_156 ( struct V_4 * V_4 , T_2 V_167 , T_2 V_168 )
{
int V_11 ;
while ( V_167 < V_168 ) {
struct V_9 V_10 ;
T_2 V_85 , V_107 ;
F_8 ( & V_10 , V_4 , NULL , NULL , 0 ) ;
V_11 = F_88 ( & V_10 , V_167 , V_90 ) ;
if ( V_11 ) {
if ( V_11 == - V_91 ) {
V_167 ++ ;
continue;
}
return V_11 ;
}
V_85 = F_90 ( V_10 . V_92 , V_4 ) ;
V_107 = F_157 ( V_85 - V_10 . V_93 , V_168 - V_167 ) ;
F_5 ( F_3 ( V_4 ) , V_107 == 0 || V_107 > V_85 ) ;
F_107 ( & V_10 , V_107 ) ;
F_11 ( & V_10 ) ;
V_167 += V_107 ;
}
return 0 ;
}
static int F_158 ( struct V_4 * V_4 , V_20 V_22 , V_20 V_112 )
{
T_2 V_167 , V_168 ;
V_20 V_169 , V_170 ;
int V_39 ;
V_39 = F_98 ( V_4 ) ;
if ( V_39 )
return V_39 ;
V_167 = ( ( unsigned long long ) V_22 ) >> V_21 ;
V_168 = ( ( unsigned long long ) V_22 + V_112 ) >> V_21 ;
V_169 = V_22 & ( V_24 - 1 ) ;
V_170 = ( V_22 + V_112 ) & ( V_24 - 1 ) ;
if ( V_167 == V_168 ) {
V_39 = F_154 ( V_4 , V_167 , V_169 ,
V_170 - V_169 ) ;
if ( V_39 )
return V_39 ;
} else {
if ( V_169 ) {
V_39 = F_154 ( V_4 , V_167 ++ , V_169 ,
V_24 - V_169 ) ;
if ( V_39 )
return V_39 ;
}
if ( V_170 ) {
V_39 = F_154 ( V_4 , V_168 , 0 , V_170 ) ;
if ( V_39 )
return V_39 ;
}
if ( V_167 < V_168 ) {
struct V_68 * V_16 = V_4 -> V_17 ;
V_20 V_171 , V_172 ;
struct V_7 * V_8 = F_3 ( V_4 ) ;
F_12 ( V_8 , true ) ;
V_171 = ( V_20 ) V_167 << V_21 ;
V_172 = ( V_20 ) V_168 << V_21 ;
F_159 ( V_16 , V_171 ,
V_172 - 1 ) ;
F_7 ( V_8 ) ;
V_39 = F_156 ( V_4 , V_167 , V_168 ) ;
F_10 ( V_8 ) ;
}
}
return V_39 ;
}
static int F_160 ( struct V_4 * V_4 , T_3 * V_78 ,
int * V_173 , T_2 V_174 , T_2 V_112 )
{
struct V_7 * V_8 = F_3 ( V_4 ) ;
struct V_9 V_10 ;
int V_39 , V_175 , V_38 ;
V_176:
F_8 ( & V_10 , V_4 , NULL , NULL , 0 ) ;
V_39 = F_88 ( & V_10 , V_174 , V_129 ) ;
if ( V_39 && V_39 != - V_91 ) {
return V_39 ;
} else if ( V_39 == - V_91 ) {
if ( V_10 . V_177 == 0 )
return - V_91 ;
V_175 = F_157 ( ( T_2 ) V_117 - V_10 . V_93 , V_112 ) ;
V_78 += V_175 ;
V_173 += V_175 ;
goto V_178;
}
V_175 = F_157 ( ( T_2 ) F_90 ( V_10 . V_92 , V_4 ) -
V_10 . V_93 , V_112 ) ;
for ( V_38 = 0 ; V_38 < V_175 ; V_38 ++ , V_78 ++ , V_173 ++ , V_10 . V_93 ++ ) {
* V_78 = F_91 ( V_10 . V_92 , V_10 . V_93 ) ;
if ( ! F_161 ( V_8 , * V_78 ) ) {
if ( F_44 ( V_8 , V_179 ) ) {
F_11 ( & V_10 ) ;
return - V_180 ;
}
F_162 ( & V_10 , V_81 ) ;
* V_173 = 1 ;
}
}
F_11 ( & V_10 ) ;
V_178:
V_112 -= V_175 ;
V_174 += V_175 ;
if ( V_112 )
goto V_176;
return 0 ;
}
static int F_163 ( struct V_4 * V_4 , T_3 * V_78 ,
int * V_173 , T_2 V_174 , int V_112 )
{
struct V_7 * V_8 = F_3 ( V_4 ) ;
struct V_9 V_10 ;
int V_39 , V_38 ;
for ( V_38 = 0 ; V_38 < V_112 ; V_38 ++ , V_173 ++ , V_78 ++ ) {
if ( * V_173 == 0 )
continue;
F_8 ( & V_10 , V_4 , NULL , NULL , 0 ) ;
V_39 = F_88 ( & V_10 , V_174 + V_38 , V_129 ) ;
if ( V_39 ) {
F_117 ( V_8 , V_4 , 1 ) ;
F_112 ( V_8 , * V_78 ) ;
} else {
F_162 ( & V_10 , * V_78 ) ;
}
F_11 ( & V_10 ) ;
}
return 0 ;
}
static int F_164 ( struct V_4 * V_181 , struct V_4 * V_182 ,
T_3 * V_78 , int * V_173 ,
T_2 V_183 , T_2 V_184 , T_2 V_112 , bool V_185 )
{
struct V_7 * V_8 = F_3 ( V_181 ) ;
T_2 V_38 = 0 ;
int V_39 ;
while ( V_38 < V_112 ) {
if ( V_78 [ V_38 ] == V_81 && ! V_185 ) {
V_38 ++ ;
continue;
}
if ( V_173 [ V_38 ] || V_78 [ V_38 ] == V_81 ) {
struct V_9 V_10 ;
struct V_186 V_187 ;
T_8 V_188 ;
T_2 V_189 ;
F_8 ( & V_10 , V_182 , NULL , NULL , 0 ) ;
V_39 = F_88 ( & V_10 , V_184 + V_38 , V_190 ) ;
if ( V_39 )
return V_39 ;
F_165 ( V_8 , V_10 . V_116 , & V_187 ) ;
V_189 = F_157 ( ( T_2 )
F_90 ( V_10 . V_92 , V_182 ) -
V_10 . V_93 , V_112 - V_38 ) ;
do {
V_10 . V_27 = F_91 ( V_10 . V_92 ,
V_10 . V_93 ) ;
F_107 ( & V_10 , 1 ) ;
if ( V_173 [ V_38 ] ) {
F_166 ( V_181 ,
1 , false ) ;
F_166 ( V_182 ,
1 , true ) ;
F_167 ( V_8 , & V_10 , V_10 . V_27 ,
V_78 [ V_38 ] , V_187 . V_191 , true , false ) ;
V_173 [ V_38 ] = 0 ;
}
V_10 . V_93 ++ ;
V_38 ++ ;
V_188 = ( V_184 + V_38 ) << V_21 ;
if ( V_182 -> V_192 < V_188 )
F_168 ( V_182 , V_188 ) ;
} while ( -- V_189 && ( V_173 [ V_38 ] || V_78 [ V_38 ] == V_81 ) );
F_11 ( & V_10 ) ;
} else {
struct V_3 * V_193 , * V_194 ;
V_193 = F_122 ( V_181 , V_183 + V_38 , true ) ;
if ( F_123 ( V_193 ) )
return F_124 ( V_193 ) ;
V_194 = F_155 ( V_182 , NULL , V_184 + V_38 ,
true ) ;
if ( F_123 ( V_194 ) ) {
F_50 ( V_193 , 1 ) ;
return F_124 ( V_194 ) ;
}
F_169 ( V_193 , V_194 ) ;
F_22 ( V_194 ) ;
F_50 ( V_194 , 1 ) ;
F_50 ( V_193 , 1 ) ;
V_39 = F_156 ( V_181 , V_183 + V_38 , V_183 + V_38 + 1 ) ;
if ( V_39 )
return V_39 ;
V_38 ++ ;
}
}
return 0 ;
}
static int F_170 ( struct V_4 * V_181 ,
struct V_4 * V_182 , T_2 V_183 , T_2 V_184 ,
T_2 V_112 , bool V_185 )
{
T_3 * V_195 ;
int * V_173 ;
T_2 V_196 ;
int V_39 ;
while ( V_112 ) {
V_196 = F_157 ( ( T_2 ) 4 * V_117 , V_112 ) ;
V_195 = F_171 ( sizeof( T_3 ) * V_196 , V_197 ) ;
if ( ! V_195 )
return - V_198 ;
V_173 = F_171 ( sizeof( int ) * V_196 , V_197 ) ;
if ( ! V_173 ) {
F_172 ( V_195 ) ;
return - V_198 ;
}
V_39 = F_160 ( V_181 , V_195 ,
V_173 , V_183 , V_196 ) ;
if ( V_39 )
goto V_199;
V_39 = F_164 ( V_181 , V_182 , V_195 ,
V_173 , V_183 , V_184 , V_196 , V_185 ) ;
if ( V_39 )
goto V_199;
V_183 += V_196 ;
V_184 += V_196 ;
V_112 -= V_196 ;
F_172 ( V_195 ) ;
F_172 ( V_173 ) ;
}
return 0 ;
V_199:
F_163 ( V_181 , V_195 , V_173 , V_183 , V_112 ) ;
F_172 ( V_195 ) ;
F_172 ( V_173 ) ;
return V_39 ;
}
static int F_173 ( struct V_4 * V_4 , T_2 V_44 , T_2 V_45 )
{
struct V_7 * V_8 = F_3 ( V_4 ) ;
T_2 V_200 = ( F_17 ( V_4 ) + V_24 - 1 ) / V_24 ;
int V_39 ;
F_12 ( V_8 , true ) ;
F_7 ( V_8 ) ;
F_174 ( V_4 ) ;
V_39 = F_170 ( V_4 , V_4 , V_45 , V_44 , V_200 - V_45 , true ) ;
F_10 ( V_8 ) ;
return V_39 ;
}
static int F_175 ( struct V_4 * V_4 , V_20 V_22 , V_20 V_112 )
{
T_2 V_167 , V_168 ;
V_20 V_188 ;
int V_39 ;
if ( V_22 + V_112 >= F_17 ( V_4 ) )
return - V_98 ;
if ( V_22 & ( V_201 - 1 ) || V_112 & ( V_201 - 1 ) )
return - V_98 ;
V_39 = F_98 ( V_4 ) ;
if ( V_39 )
return V_39 ;
V_167 = V_22 >> V_21 ;
V_168 = ( V_22 + V_112 ) >> V_21 ;
V_39 = F_62 ( V_4 -> V_17 , V_22 , V_202 ) ;
if ( V_39 )
return V_39 ;
F_176 ( V_4 , V_22 ) ;
V_39 = F_173 ( V_4 , V_167 , V_168 ) ;
if ( V_39 )
return V_39 ;
F_62 ( V_4 -> V_17 , V_22 , V_202 ) ;
F_176 ( V_4 , V_22 ) ;
V_188 = F_17 ( V_4 ) - V_112 ;
F_176 ( V_4 , V_188 ) ;
V_39 = F_126 ( V_4 , V_188 , true ) ;
if ( ! V_39 )
F_168 ( V_4 , V_188 ) ;
return V_39 ;
}
static int F_177 ( struct V_9 * V_10 , T_2 V_44 ,
T_2 V_45 )
{
struct V_7 * V_8 = F_3 ( V_10 -> V_4 ) ;
T_2 V_13 = V_44 ;
unsigned int V_93 = V_10 -> V_93 ;
T_9 V_107 = 0 ;
int V_39 ;
for (; V_13 < V_45 ; V_13 ++ , V_10 -> V_93 ++ ) {
if ( F_91 ( V_10 -> V_92 , V_10 -> V_93 ) == V_81 )
V_107 ++ ;
}
V_10 -> V_93 = V_93 ;
V_39 = F_178 ( V_10 , V_107 ) ;
if ( V_39 )
return V_39 ;
V_10 -> V_93 = V_93 ;
for ( V_13 = V_44 ; V_13 < V_45 ; V_13 ++ , V_10 -> V_93 ++ ) {
V_10 -> V_27 =
F_91 ( V_10 -> V_92 , V_10 -> V_93 ) ;
if ( V_10 -> V_27 == V_81 ) {
V_39 = - V_203 ;
break;
}
if ( V_10 -> V_27 != V_80 ) {
F_112 ( V_8 , V_10 -> V_27 ) ;
V_10 -> V_27 = V_80 ;
F_111 ( V_10 ) ;
}
}
F_116 ( V_10 , V_44 , 0 , V_13 - V_44 ) ;
return V_39 ;
}
static int F_179 ( struct V_4 * V_4 , V_20 V_22 , V_20 V_112 ,
int V_158 )
{
struct V_7 * V_8 = F_3 ( V_4 ) ;
struct V_68 * V_16 = V_4 -> V_17 ;
T_2 V_13 , V_167 , V_168 ;
V_20 V_188 = F_17 ( V_4 ) ;
V_20 V_169 , V_170 ;
int V_39 = 0 ;
V_39 = F_180 ( V_4 , ( V_112 + V_22 ) ) ;
if ( V_39 )
return V_39 ;
V_39 = F_98 ( V_4 ) ;
if ( V_39 )
return V_39 ;
V_39 = F_62 ( V_16 , V_22 , V_22 + V_112 - 1 ) ;
if ( V_39 )
return V_39 ;
F_181 ( V_4 , V_22 , V_22 + V_112 - 1 ) ;
V_167 = ( ( unsigned long long ) V_22 ) >> V_21 ;
V_168 = ( ( unsigned long long ) V_22 + V_112 ) >> V_21 ;
V_169 = V_22 & ( V_24 - 1 ) ;
V_170 = ( V_22 + V_112 ) & ( V_24 - 1 ) ;
if ( V_167 == V_168 ) {
V_39 = F_154 ( V_4 , V_167 , V_169 ,
V_170 - V_169 ) ;
if ( V_39 )
return V_39 ;
V_188 = F_182 ( V_20 , V_188 , V_22 + V_112 ) ;
} else {
if ( V_169 ) {
V_39 = F_154 ( V_4 , V_167 ++ , V_169 ,
V_24 - V_169 ) ;
if ( V_39 )
return V_39 ;
V_188 = F_182 ( V_20 , V_188 ,
( V_20 ) V_167 << V_21 ) ;
}
for ( V_13 = V_167 ; V_13 < V_168 ; ) {
struct V_9 V_10 ;
unsigned int V_85 ;
T_2 V_45 ;
F_7 ( V_8 ) ;
F_8 ( & V_10 , V_4 , NULL , NULL , 0 ) ;
V_39 = F_88 ( & V_10 , V_13 , V_190 ) ;
if ( V_39 ) {
F_10 ( V_8 ) ;
goto V_14;
}
V_85 = F_90 ( V_10 . V_92 , V_4 ) ;
V_45 = F_157 ( V_168 , V_85 - V_10 . V_93 + V_13 ) ;
V_39 = F_177 ( & V_10 , V_13 , V_45 ) ;
F_11 ( & V_10 ) ;
F_10 ( V_8 ) ;
F_12 ( V_8 , V_10 . V_15 ) ;
if ( V_39 )
goto V_14;
V_13 = V_45 ;
V_188 = F_182 ( V_20 , V_188 ,
( V_20 ) V_13 << V_21 ) ;
}
if ( V_170 ) {
V_39 = F_154 ( V_4 , V_168 , 0 , V_170 ) ;
if ( V_39 )
goto V_14;
V_188 = F_182 ( V_20 , V_188 , V_22 + V_112 ) ;
}
}
V_14:
if ( ! ( V_158 & V_204 ) && F_17 ( V_4 ) < V_188 )
F_168 ( V_4 , V_188 ) ;
return V_39 ;
}
static int F_183 ( struct V_4 * V_4 , V_20 V_22 , V_20 V_112 )
{
struct V_7 * V_8 = F_3 ( V_4 ) ;
T_2 V_205 , V_167 , V_168 , V_206 , V_207 ;
V_20 V_188 ;
int V_39 = 0 ;
V_188 = F_17 ( V_4 ) + V_112 ;
V_39 = F_180 ( V_4 , V_188 ) ;
if ( V_39 )
return V_39 ;
if ( V_22 >= F_17 ( V_4 ) )
return - V_98 ;
if ( V_22 & ( V_201 - 1 ) || V_112 & ( V_201 - 1 ) )
return - V_98 ;
V_39 = F_98 ( V_4 ) ;
if ( V_39 )
return V_39 ;
F_12 ( V_8 , true ) ;
V_39 = F_126 ( V_4 , F_17 ( V_4 ) , true ) ;
if ( V_39 )
return V_39 ;
V_39 = F_62 ( V_4 -> V_17 , V_22 , V_202 ) ;
if ( V_39 )
return V_39 ;
F_176 ( V_4 , V_22 ) ;
V_167 = V_22 >> V_21 ;
V_168 = ( V_22 + V_112 ) >> V_21 ;
V_206 = V_168 - V_167 ;
V_207 = ( F_17 ( V_4 ) + V_24 - 1 ) / V_24 ;
while ( ! V_39 && V_207 > V_167 ) {
V_205 = V_207 - V_167 ;
if ( V_205 > V_206 )
V_205 = V_206 ;
V_207 -= V_205 ;
F_7 ( V_8 ) ;
F_174 ( V_4 ) ;
V_39 = F_170 ( V_4 , V_4 , V_207 ,
V_207 + V_206 , V_205 , false ) ;
F_10 ( V_8 ) ;
}
F_62 ( V_4 -> V_17 , V_22 , V_202 ) ;
F_176 ( V_4 , V_22 ) ;
if ( ! V_39 )
F_168 ( V_4 , V_188 ) ;
return V_39 ;
}
static int F_184 ( struct V_4 * V_4 , V_20 V_22 ,
V_20 V_112 , int V_158 )
{
struct V_7 * V_8 = F_3 ( V_4 ) ;
struct V_208 V_209 = { . V_210 = NULL } ;
T_2 V_168 ;
V_20 V_188 = F_17 ( V_4 ) ;
V_20 V_170 ;
int V_11 ;
V_11 = F_180 ( V_4 , ( V_112 + V_22 ) ) ;
if ( V_11 )
return V_11 ;
V_11 = F_98 ( V_4 ) ;
if ( V_11 )
return V_11 ;
F_12 ( V_8 , true ) ;
V_168 = ( ( unsigned long long ) V_22 + V_112 ) >> V_21 ;
V_170 = ( V_22 + V_112 ) & ( V_24 - 1 ) ;
V_209 . V_211 = ( ( unsigned long long ) V_22 ) >> V_21 ;
V_209 . V_212 = V_168 - V_209 . V_211 ;
if ( V_170 )
V_209 . V_212 ++ ;
V_11 = V_208 ( V_4 , & V_209 , 1 , V_213 ) ;
if ( V_11 ) {
T_2 V_214 ;
if ( ! V_209 . V_212 )
return V_11 ;
V_214 = V_209 . V_211 + V_209 . V_212 - 1 ;
V_188 = ( V_214 == V_168 ) ? V_22 + V_112 :
( V_20 ) ( V_214 + 1 ) << V_21 ;
} else {
V_188 = ( ( V_20 ) V_168 << V_21 ) + V_170 ;
}
if ( ! ( V_158 & V_204 ) && F_17 ( V_4 ) < V_188 )
F_168 ( V_4 , V_188 ) ;
return V_11 ;
}
static long F_185 ( struct V_43 * V_43 , int V_158 ,
V_20 V_22 , V_20 V_112 )
{
struct V_4 * V_4 = F_2 ( V_43 ) ;
long V_39 = 0 ;
if ( ! F_27 ( V_4 -> V_26 ) )
return - V_98 ;
if ( F_26 ( V_4 ) &&
( V_158 & ( V_215 | V_216 ) ) )
return - V_217 ;
if ( V_158 & ~ ( V_204 | V_218 |
V_215 | V_219 |
V_216 ) )
return - V_217 ;
F_86 ( V_4 ) ;
if ( V_158 & V_218 ) {
if ( V_22 >= V_4 -> V_192 )
goto V_14;
V_39 = F_158 ( V_4 , V_22 , V_112 ) ;
} else if ( V_158 & V_215 ) {
V_39 = F_175 ( V_4 , V_22 , V_112 ) ;
} else if ( V_158 & V_219 ) {
V_39 = F_179 ( V_4 , V_22 , V_112 , V_158 ) ;
} else if ( V_158 & V_216 ) {
V_39 = F_183 ( V_4 , V_22 , V_112 ) ;
} else {
V_39 = F_184 ( V_4 , V_22 , V_112 , V_158 ) ;
}
if ( ! V_39 ) {
V_4 -> V_132 = V_4 -> V_133 = F_141 ( V_4 ) ;
F_74 ( V_4 , false ) ;
if ( V_158 & V_204 )
F_186 ( V_4 ) ;
F_30 ( F_3 ( V_4 ) , V_28 ) ;
}
V_14:
F_92 ( V_4 ) ;
F_187 ( V_4 , V_158 , V_22 , V_112 , V_39 ) ;
return V_39 ;
}
static int F_188 ( struct V_4 * V_4 , struct V_43 * V_103 )
{
if ( ! ( V_103 -> V_220 & V_221 ) ||
F_189 ( & V_4 -> V_222 ) != 1 )
return 0 ;
if ( F_190 ( V_4 ) )
F_191 ( V_4 ) ;
if ( F_192 ( V_4 ) ) {
F_63 ( V_4 , V_223 ) ;
F_193 ( V_4 ) ;
F_61 ( V_4 , V_224 ) ;
F_194 ( V_4 -> V_17 ) ;
F_63 ( V_4 , V_224 ) ;
}
return 0 ;
}
static inline T_10 F_195 ( T_7 V_158 , T_10 V_138 )
{
if ( F_134 ( V_158 ) )
return V_138 ;
else if ( F_27 ( V_158 ) )
return V_138 & V_225 ;
else
return V_138 & V_226 ;
}
static int F_196 ( struct V_43 * V_103 , unsigned long V_227 )
{
struct V_4 * V_4 = F_2 ( V_103 ) ;
struct V_40 * V_41 = F_43 ( V_4 ) ;
unsigned int V_138 = V_41 -> V_228 & V_229 ;
return F_197 ( V_138 , ( int V_230 * ) V_227 ) ;
}
static int F_198 ( struct V_43 * V_103 , unsigned long V_227 )
{
struct V_4 * V_4 = F_2 ( V_103 ) ;
struct V_40 * V_41 = F_43 ( V_4 ) ;
unsigned int V_138 ;
unsigned int V_231 ;
int V_39 ;
if ( ! F_199 ( V_4 ) )
return - V_105 ;
if ( F_200 ( V_138 , ( int V_230 * ) V_227 ) )
return - V_18 ;
V_39 = F_201 ( V_103 ) ;
if ( V_39 )
return V_39 ;
F_86 ( V_4 ) ;
V_138 = F_195 ( V_4 -> V_26 , V_138 ) ;
V_231 = V_41 -> V_228 ;
if ( ( V_138 ^ V_231 ) & ( V_232 | V_233 ) ) {
if ( ! F_147 ( V_234 ) ) {
F_92 ( V_4 ) ;
V_39 = - V_106 ;
goto V_14;
}
}
V_138 = V_138 & V_235 ;
V_138 |= V_231 & ~ V_235 ;
V_41 -> V_228 = V_138 ;
V_4 -> V_133 = F_141 ( V_4 ) ;
F_202 ( V_4 ) ;
F_92 ( V_4 ) ;
V_14:
F_203 ( V_103 ) ;
return V_39 ;
}
static int F_204 ( struct V_43 * V_103 , unsigned long V_227 )
{
struct V_4 * V_4 = F_2 ( V_103 ) ;
return F_197 ( V_4 -> V_236 , ( int V_230 * ) V_227 ) ;
}
static int F_205 ( struct V_43 * V_103 )
{
struct V_4 * V_4 = F_2 ( V_103 ) ;
int V_39 ;
if ( ! F_199 ( V_4 ) )
return - V_105 ;
if ( ! F_27 ( V_4 -> V_26 ) )
return - V_98 ;
V_39 = F_201 ( V_103 ) ;
if ( V_39 )
return V_39 ;
F_86 ( V_4 ) ;
if ( F_190 ( V_4 ) )
goto V_14;
V_39 = F_98 ( V_4 ) ;
if ( V_39 )
goto V_14;
F_61 ( V_4 , V_237 ) ;
F_61 ( V_4 , V_238 ) ;
F_30 ( F_3 ( V_4 ) , V_28 ) ;
if ( ! F_59 ( V_4 ) )
goto V_239;
F_206 ( F_3 ( V_4 ) -> V_240 , V_241 ,
L_1 ,
V_4 -> V_50 , F_59 ( V_4 ) ) ;
V_39 = F_62 ( V_4 -> V_17 , 0 , V_202 ) ;
if ( V_39 ) {
F_63 ( V_4 , V_237 ) ;
goto V_14;
}
V_239:
F_207 ( V_4 ) ;
F_208 ( V_4 ) ;
V_14:
F_92 ( V_4 ) ;
F_203 ( V_103 ) ;
return V_39 ;
}
static int F_209 ( struct V_43 * V_103 )
{
struct V_4 * V_4 = F_2 ( V_103 ) ;
int V_39 ;
if ( ! F_199 ( V_4 ) )
return - V_105 ;
V_39 = F_201 ( V_103 ) ;
if ( V_39 )
return V_39 ;
F_86 ( V_4 ) ;
if ( F_192 ( V_4 ) )
goto V_242;
if ( F_190 ( V_4 ) ) {
V_39 = F_210 ( V_4 ) ;
if ( V_39 )
goto V_242;
V_39 = F_56 ( V_103 , 0 , V_202 , 0 , true ) ;
if ( ! V_39 ) {
F_63 ( V_4 , V_237 ) ;
F_211 ( V_4 ) ;
}
} else {
V_39 = F_56 ( V_103 , 0 , V_202 , 0 , true ) ;
}
V_242:
F_92 ( V_4 ) ;
F_203 ( V_103 ) ;
return V_39 ;
}
static int F_212 ( struct V_43 * V_103 )
{
struct V_4 * V_4 = F_2 ( V_103 ) ;
int V_39 ;
if ( ! F_199 ( V_4 ) )
return - V_105 ;
if ( ! F_27 ( V_4 -> V_26 ) )
return - V_98 ;
V_39 = F_201 ( V_103 ) ;
if ( V_39 )
return V_39 ;
F_86 ( V_4 ) ;
if ( F_192 ( V_4 ) )
goto V_14;
V_39 = F_98 ( V_4 ) ;
if ( V_39 )
goto V_14;
F_213 ( V_4 ) ;
F_214 ( V_4 ) ;
F_61 ( V_4 , V_223 ) ;
F_30 ( F_3 ( V_4 ) , V_28 ) ;
V_14:
F_92 ( V_4 ) ;
F_203 ( V_103 ) ;
return V_39 ;
}
static int F_215 ( struct V_43 * V_103 )
{
struct V_4 * V_4 = F_2 ( V_103 ) ;
int V_39 ;
if ( ! F_199 ( V_4 ) )
return - V_105 ;
V_39 = F_201 ( V_103 ) ;
if ( V_39 )
return V_39 ;
F_86 ( V_4 ) ;
if ( ! F_192 ( V_4 ) )
goto V_14;
if ( ! F_216 ( V_4 ) ) {
V_39 = F_120 ( V_4 , 0 , true ) ;
goto V_14;
}
V_39 = F_158 ( V_4 , 0 , V_201 ) ;
V_14:
F_92 ( V_4 ) ;
F_203 ( V_103 ) ;
return V_39 ;
}
static int F_217 ( struct V_43 * V_103 )
{
struct V_4 * V_4 = F_2 ( V_103 ) ;
int V_39 ;
if ( ! F_199 ( V_4 ) )
return - V_105 ;
V_39 = F_201 ( V_103 ) ;
if ( V_39 )
return V_39 ;
F_86 ( V_4 ) ;
if ( F_190 ( V_4 ) )
F_191 ( V_4 ) ;
if ( F_192 ( V_4 ) ) {
F_63 ( V_4 , V_223 ) ;
F_193 ( V_4 ) ;
V_39 = F_56 ( V_103 , 0 , V_202 , 0 , true ) ;
}
F_92 ( V_4 ) ;
F_203 ( V_103 ) ;
F_30 ( F_3 ( V_4 ) , V_28 ) ;
return V_39 ;
}
static int F_218 ( struct V_43 * V_103 , unsigned long V_227 )
{
struct V_4 * V_4 = F_2 ( V_103 ) ;
struct V_7 * V_8 = F_3 ( V_4 ) ;
struct V_243 * V_240 = V_8 -> V_240 ;
T_10 V_244 ;
int V_39 ;
if ( ! F_147 ( V_245 ) )
return - V_106 ;
if ( F_200 ( V_244 , ( T_10 V_230 * ) V_227 ) )
return - V_18 ;
V_39 = F_201 ( V_103 ) ;
if ( V_39 )
return V_39 ;
switch ( V_244 ) {
case V_246 :
V_240 = F_219 ( V_240 -> V_247 ) ;
if ( V_240 && ! F_123 ( V_240 ) ) {
F_220 ( V_8 , false ) ;
F_221 ( V_240 -> V_247 , V_240 ) ;
}
break;
case V_248 :
F_71 ( V_240 , 1 ) ;
F_220 ( V_8 , false ) ;
break;
case V_249 :
F_220 ( V_8 , false ) ;
break;
case V_250 :
F_222 ( V_8 , V_251 , V_56 ) ;
F_220 ( V_8 , false ) ;
break;
default:
V_39 = - V_98 ;
goto V_14;
}
F_30 ( V_8 , V_28 ) ;
V_14:
F_203 ( V_103 ) ;
return V_39 ;
}
static int F_223 ( struct V_43 * V_103 , unsigned long V_227 )
{
struct V_4 * V_4 = F_2 ( V_103 ) ;
struct V_243 * V_240 = V_4 -> V_12 ;
struct V_252 * V_253 = F_224 ( V_240 -> V_247 ) ;
struct V_254 V_255 ;
int V_39 ;
if ( ! F_147 ( V_245 ) )
return - V_106 ;
if ( ! F_225 ( V_253 ) )
return - V_217 ;
if ( F_226 ( & V_255 , (struct V_254 V_230 * ) V_227 ,
sizeof( V_255 ) ) )
return - V_18 ;
V_39 = F_201 ( V_103 ) ;
if ( V_39 )
return V_39 ;
V_255 . V_256 = F_227 ( ( unsigned int ) V_255 . V_256 ,
V_253 -> V_257 . V_258 ) ;
V_39 = F_228 ( F_229 ( V_240 ) , & V_255 ) ;
F_203 ( V_103 ) ;
if ( V_39 < 0 )
return V_39 ;
if ( F_230 ( (struct V_254 V_230 * ) V_227 , & V_255 ,
sizeof( V_255 ) ) )
return - V_18 ;
F_30 ( F_3 ( V_4 ) , V_28 ) ;
return 0 ;
}
static bool F_231 ( T_11 V_259 [ 16 ] )
{
int V_38 ;
for ( V_38 = 0 ; V_38 < 16 ; V_38 ++ )
if ( V_259 [ V_38 ] )
return true ;
return false ;
}
static int F_232 ( struct V_43 * V_103 , unsigned long V_227 )
{
struct V_4 * V_4 = F_2 ( V_103 ) ;
F_30 ( F_3 ( V_4 ) , V_28 ) ;
return F_233 ( V_103 , ( const void V_230 * ) V_227 ) ;
}
static int F_234 ( struct V_43 * V_103 , unsigned long V_227 )
{
return F_235 ( V_103 , ( void V_230 * ) V_227 ) ;
}
static int F_236 ( struct V_43 * V_103 , unsigned long V_227 )
{
struct V_4 * V_4 = F_2 ( V_103 ) ;
struct V_7 * V_8 = F_3 ( V_4 ) ;
int V_11 ;
if ( ! F_237 ( V_4 -> V_12 ) )
return - V_217 ;
if ( F_231 ( V_8 -> V_260 -> V_261 ) )
goto V_262;
V_11 = F_201 ( V_103 ) ;
if ( V_11 )
return V_11 ;
F_238 ( V_8 -> V_260 -> V_261 ) ;
V_11 = F_239 ( V_8 , false ) ;
if ( V_11 ) {
memset ( V_8 -> V_260 -> V_261 , 0 , 16 ) ;
F_203 ( V_103 ) ;
return V_11 ;
}
F_203 ( V_103 ) ;
V_262:
if ( F_230 ( ( T_11 V_230 * ) V_227 , V_8 -> V_260 -> V_261 ,
16 ) )
return - V_18 ;
return 0 ;
}
static int F_240 ( struct V_43 * V_103 , unsigned long V_227 )
{
struct V_4 * V_4 = F_2 ( V_103 ) ;
struct V_7 * V_8 = F_3 ( V_4 ) ;
T_10 V_263 ;
int V_39 ;
if ( ! F_147 ( V_245 ) )
return - V_106 ;
if ( F_200 ( V_263 , ( T_10 V_230 * ) V_227 ) )
return - V_18 ;
if ( F_57 ( V_8 -> V_240 ) )
return - V_264 ;
V_39 = F_201 ( V_103 ) ;
if ( V_39 )
return V_39 ;
if ( ! V_263 ) {
if ( ! F_241 ( & V_8 -> V_265 ) ) {
V_39 = - V_266 ;
goto V_14;
}
} else {
F_242 ( & V_8 -> V_265 ) ;
}
V_39 = F_243 ( V_8 , V_263 , true , V_267 ) ;
V_14:
F_203 ( V_103 ) ;
return V_39 ;
}
static int F_244 ( struct V_43 * V_103 , unsigned long V_227 )
{
struct V_4 * V_4 = F_2 ( V_103 ) ;
struct V_7 * V_8 = F_3 ( V_4 ) ;
int V_39 ;
if ( ! F_147 ( V_245 ) )
return - V_106 ;
if ( F_57 ( V_8 -> V_240 ) )
return - V_264 ;
V_39 = F_201 ( V_103 ) ;
if ( V_39 )
return V_39 ;
V_39 = F_71 ( V_8 -> V_240 , 1 ) ;
F_203 ( V_103 ) ;
return V_39 ;
}
static int F_245 ( struct V_7 * V_8 ,
struct V_43 * V_103 ,
struct V_268 * V_255 )
{
struct V_4 * V_4 = F_2 ( V_103 ) ;
struct V_208 V_209 = { . V_210 = NULL } ;
struct V_269 V_270 = { 0 , 0 , 0 } ;
T_2 V_167 , V_168 ;
unsigned int V_271 = V_8 -> V_272 ;
unsigned int V_273 = 0 , V_274 ;
T_3 V_172 = 0 ;
bool V_275 = false ;
int V_11 ;
if ( F_246 ( V_4 , NULL ) )
return - V_98 ;
V_167 = V_255 -> V_44 >> V_21 ;
V_168 = ( V_255 -> V_44 + V_255 -> V_112 ) >> V_21 ;
F_12 ( V_8 , true ) ;
F_86 ( V_4 ) ;
V_11 = F_62 ( V_4 -> V_17 , V_255 -> V_44 ,
V_255 -> V_44 + V_255 -> V_112 - 1 ) ;
if ( V_11 )
goto V_14;
if ( F_247 ( V_4 , V_167 , & V_270 ) ) {
if ( V_270 . V_115 + V_270 . V_112 >= V_168 )
goto V_14;
}
V_209 . V_211 = V_167 ;
while ( V_209 . V_211 < V_168 ) {
V_209 . V_212 = V_168 - V_209 . V_211 ;
V_11 = V_208 ( V_4 , & V_209 , 0 , V_276 ) ;
if ( V_11 )
goto V_14;
if ( ! ( V_209 . V_277 & V_278 ) ) {
V_209 . V_211 ++ ;
continue;
}
if ( V_172 && V_172 != V_209 . V_279 ) {
V_275 = true ;
break;
}
V_172 = V_209 . V_279 + V_209 . V_212 ;
V_209 . V_211 += V_209 . V_212 ;
}
if ( ! V_275 )
goto V_14;
V_209 . V_211 = V_167 ;
V_209 . V_212 = V_168 - V_167 ;
V_274 = ( V_209 . V_212 + F_248 ( V_8 ) - 1 ) / F_248 ( V_8 ) ;
if ( F_249 ( V_8 , 0 , V_274 ) ) {
V_11 = - V_280 ;
goto V_14;
}
while ( V_209 . V_211 < V_168 ) {
T_2 V_207 ;
int V_281 = 0 ;
V_282:
V_209 . V_212 = V_168 - V_209 . V_211 ;
V_11 = V_208 ( V_4 , & V_209 , 0 , V_276 ) ;
if ( V_11 )
goto V_283;
if ( ! ( V_209 . V_277 & V_278 ) ) {
V_209 . V_211 ++ ;
continue;
}
F_61 ( V_4 , V_284 ) ;
V_207 = V_209 . V_211 ;
while ( V_207 < V_209 . V_211 + V_209 . V_212 && V_281 < V_271 ) {
struct V_3 * V_3 ;
V_3 = F_122 ( V_4 , V_207 , true ) ;
if ( F_123 ( V_3 ) ) {
V_11 = F_124 ( V_3 ) ;
goto V_283;
}
F_22 ( V_3 ) ;
F_50 ( V_3 , 1 ) ;
V_207 ++ ;
V_281 ++ ;
V_273 ++ ;
}
V_209 . V_211 = V_207 ;
if ( V_207 < V_168 && V_281 < V_271 )
goto V_282;
F_63 ( V_4 , V_284 ) ;
V_11 = F_194 ( V_4 -> V_17 ) ;
if ( V_11 )
goto V_14;
}
V_283:
F_63 ( V_4 , V_284 ) ;
V_14:
F_92 ( V_4 ) ;
if ( ! V_11 )
V_255 -> V_112 = ( T_5 ) V_273 << V_21 ;
return V_11 ;
}
static int F_250 ( struct V_43 * V_103 , unsigned long V_227 )
{
struct V_4 * V_4 = F_2 ( V_103 ) ;
struct V_7 * V_8 = F_3 ( V_4 ) ;
struct V_268 V_255 ;
int V_11 ;
if ( ! F_147 ( V_245 ) )
return - V_106 ;
if ( ! F_27 ( V_4 -> V_26 ) || F_190 ( V_4 ) )
return - V_98 ;
if ( F_57 ( V_8 -> V_240 ) )
return - V_264 ;
if ( F_226 ( & V_255 , (struct V_268 V_230 * ) V_227 ,
sizeof( V_255 ) ) )
return - V_18 ;
if ( V_255 . V_44 & ( V_201 - 1 ) || V_255 . V_112 & ( V_201 - 1 ) )
return - V_98 ;
if ( F_15 ( ( V_255 . V_44 + V_255 . V_112 ) >> V_21 >
V_8 -> V_127 ) )
return - V_98 ;
V_11 = F_201 ( V_103 ) ;
if ( V_11 )
return V_11 ;
V_11 = F_245 ( V_8 , V_103 , & V_255 ) ;
F_203 ( V_103 ) ;
F_30 ( V_8 , V_28 ) ;
if ( V_11 < 0 )
return V_11 ;
if ( F_230 ( (struct V_268 V_230 * ) V_227 , & V_255 ,
sizeof( V_255 ) ) )
return - V_18 ;
return 0 ;
}
static int F_251 ( struct V_43 * V_285 , V_20 V_286 ,
struct V_43 * V_287 , V_20 V_288 , T_8 V_112 )
{
struct V_4 * V_183 = F_2 ( V_285 ) ;
struct V_4 * V_184 = F_2 ( V_287 ) ;
struct V_7 * V_8 = F_3 ( V_183 ) ;
T_8 V_196 = V_112 , V_289 = 0 ;
T_8 V_290 ;
int V_39 ;
if ( V_285 -> V_291 . V_292 != V_287 -> V_291 . V_292 ||
V_183 -> V_12 != V_184 -> V_12 )
return - V_293 ;
if ( F_15 ( F_57 ( V_183 -> V_12 ) ) )
return - V_264 ;
if ( ! F_27 ( V_183 -> V_26 ) || ! F_27 ( V_184 -> V_26 ) )
return - V_98 ;
if ( F_26 ( V_183 ) || F_26 ( V_184 ) )
return - V_217 ;
if ( V_183 == V_184 ) {
if ( V_286 == V_288 )
return 0 ;
if ( V_288 > V_286 && V_288 < V_286 + V_112 )
return - V_98 ;
}
F_86 ( V_183 ) ;
if ( V_183 != V_184 ) {
if ( ! F_252 ( V_184 ) ) {
V_39 = - V_266 ;
goto V_14;
}
}
V_39 = - V_98 ;
if ( V_286 + V_112 > V_183 -> V_192 || V_286 + V_112 < V_286 )
goto V_294;
if ( V_112 == 0 )
V_196 = V_112 = V_183 -> V_192 - V_286 ;
if ( V_286 + V_112 == V_183 -> V_192 )
V_112 = F_253 ( V_183 -> V_192 , V_201 ) - V_286 ;
if ( V_112 == 0 ) {
V_39 = 0 ;
goto V_294;
}
V_290 = V_184 -> V_192 ;
if ( V_288 + V_196 > V_184 -> V_192 )
V_289 = V_288 + V_196 ;
if ( ! F_254 ( V_286 , V_201 ) ||
! F_254 ( V_286 + V_112 , V_201 ) ||
! F_254 ( V_288 , V_201 ) )
goto V_294;
V_39 = F_98 ( V_183 ) ;
if ( V_39 )
goto V_294;
V_39 = F_98 ( V_184 ) ;
if ( V_39 )
goto V_294;
V_39 = F_62 ( V_183 -> V_17 ,
V_286 , V_286 + V_112 ) ;
if ( V_39 )
goto V_294;
V_39 = F_62 ( V_184 -> V_17 ,
V_288 , V_288 + V_112 ) ;
if ( V_39 )
goto V_294;
F_12 ( V_8 , true ) ;
F_7 ( V_8 ) ;
V_39 = F_170 ( V_183 , V_184 , V_286 >> V_295 ,
V_288 >> V_295 ,
V_112 >> V_295 , false ) ;
if ( ! V_39 ) {
if ( V_289 )
F_168 ( V_184 , V_289 ) ;
else if ( V_290 != V_184 -> V_192 )
F_168 ( V_184 , V_290 ) ;
}
F_10 ( V_8 ) ;
V_294:
if ( V_183 != V_184 )
F_92 ( V_184 ) ;
V_14:
F_92 ( V_183 ) ;
return V_39 ;
}
static int F_255 ( struct V_43 * V_103 , unsigned long V_227 )
{
struct V_296 V_255 ;
struct V_297 V_184 ;
int V_11 ;
if ( ! ( V_103 -> V_220 & V_298 ) ||
! ( V_103 -> V_220 & V_221 ) )
return - V_299 ;
if ( F_226 ( & V_255 , (struct V_296 V_230 * ) V_227 ,
sizeof( V_255 ) ) )
return - V_18 ;
V_184 = F_256 ( V_255 . V_300 ) ;
if ( ! V_184 . V_43 )
return - V_299 ;
if ( ! ( V_184 . V_43 -> V_220 & V_221 ) ) {
V_11 = - V_299 ;
goto V_242;
}
V_11 = F_201 ( V_103 ) ;
if ( V_11 )
goto V_242;
V_11 = F_251 ( V_103 , V_255 . V_286 , V_184 . V_43 ,
V_255 . V_288 , V_255 . V_112 ) ;
F_203 ( V_103 ) ;
if ( V_11 )
goto V_242;
if ( F_230 ( (struct V_296 V_230 * ) V_227 ,
& V_255 , sizeof( V_255 ) ) )
V_11 = - V_18 ;
V_242:
F_257 ( V_184 ) ;
return V_11 ;
}
static int F_258 ( struct V_43 * V_103 , unsigned long V_227 )
{
struct V_4 * V_4 = F_2 ( V_103 ) ;
struct V_7 * V_8 = F_3 ( V_4 ) ;
struct V_301 * V_302 = F_259 ( V_8 ) ;
unsigned int V_303 = 0 , V_304 = 0 ;
unsigned int V_305 = 0 , V_306 = 0 ;
struct V_307 V_255 ;
int V_39 ;
if ( ! F_147 ( V_245 ) )
return - V_106 ;
if ( F_57 ( V_8 -> V_240 ) )
return - V_264 ;
if ( F_226 ( & V_255 , (struct V_307 V_230 * ) V_227 ,
sizeof( V_255 ) ) )
return - V_18 ;
if ( V_8 -> V_308 <= 1 || V_8 -> V_308 - 1 <= V_255 . V_309 ||
V_8 -> V_310 != 1 ) {
F_206 ( V_8 -> V_240 , V_241 ,
L_2 ,
V_255 . V_309 , V_8 -> V_308 ,
V_8 -> V_310 ) ;
return - V_98 ;
}
V_39 = F_201 ( V_103 ) ;
if ( V_39 )
return V_39 ;
if ( V_255 . V_309 != 0 )
V_305 = F_260 ( V_8 , F_261 ( V_255 . V_309 ) . V_311 ) ;
V_306 = F_260 ( V_8 , F_261 ( V_255 . V_309 ) . V_312 ) ;
V_303 = V_302 -> V_313 [ V_314 ] ;
if ( V_303 < V_305 || V_303 >= V_306 )
V_303 = V_305 ;
V_304 = F_157 ( V_303 + V_255 . V_315 , V_306 ) ;
while ( V_303 < V_304 ) {
if ( ! F_241 ( & V_8 -> V_265 ) ) {
V_39 = - V_266 ;
goto V_14;
}
V_302 -> V_313 [ V_316 ] = V_304 + 1 ;
V_302 -> V_313 [ V_317 ] = V_304 + 1 ;
V_302 -> V_313 [ V_318 ] = V_304 + 1 ;
V_39 = F_243 ( V_8 , true , true , V_303 ) ;
if ( V_39 == - V_280 )
V_39 = 0 ;
else if ( V_39 < 0 )
break;
V_303 ++ ;
}
V_14:
F_203 ( V_103 ) ;
return V_39 ;
}
long F_262 ( struct V_43 * V_103 , unsigned int V_319 , unsigned long V_227 )
{
switch ( V_319 ) {
case V_320 :
return F_196 ( V_103 , V_227 ) ;
case V_321 :
return F_198 ( V_103 , V_227 ) ;
case V_322 :
return F_204 ( V_103 , V_227 ) ;
case V_323 :
return F_205 ( V_103 ) ;
case V_324 :
return F_209 ( V_103 ) ;
case V_325 :
return F_212 ( V_103 ) ;
case V_326 :
return F_215 ( V_103 ) ;
case V_327 :
return F_217 ( V_103 ) ;
case V_328 :
return F_218 ( V_103 , V_227 ) ;
case V_329 :
return F_223 ( V_103 , V_227 ) ;
case V_330 :
return F_232 ( V_103 , V_227 ) ;
case V_331 :
return F_234 ( V_103 , V_227 ) ;
case V_332 :
return F_236 ( V_103 , V_227 ) ;
case V_333 :
return F_240 ( V_103 , V_227 ) ;
case V_334 :
return F_244 ( V_103 , V_227 ) ;
case V_335 :
return F_250 ( V_103 , V_227 ) ;
case V_336 :
return F_255 ( V_103 , V_227 ) ;
case V_337 :
return F_258 ( V_103 , V_227 ) ;
default:
return - V_338 ;
}
}
static T_12 F_263 ( struct V_339 * V_340 , struct V_341 * V_118 )
{
struct V_43 * V_43 = V_340 -> V_342 ;
struct V_4 * V_4 = F_2 ( V_43 ) ;
struct V_343 V_344 ;
T_12 V_39 ;
if ( F_26 ( V_4 ) &&
! F_102 ( V_4 ) &&
F_97 ( V_4 ) )
return - V_105 ;
F_86 ( V_4 ) ;
V_39 = F_264 ( V_340 , V_118 ) ;
if ( V_39 > 0 ) {
int V_11 ;
if ( F_265 ( V_118 , F_266 ( V_118 ) ) )
F_61 ( V_4 , V_345 ) ;
V_11 = F_267 ( V_340 , V_118 ) ;
if ( V_11 ) {
F_92 ( V_4 ) ;
return V_11 ;
}
F_268 ( & V_344 ) ;
V_39 = F_269 ( V_340 , V_118 ) ;
F_270 ( & V_344 ) ;
F_63 ( V_4 , V_345 ) ;
}
F_92 ( V_4 ) ;
if ( V_39 > 0 )
V_39 = F_271 ( V_340 , V_39 ) ;
return V_39 ;
}
long F_272 ( struct V_43 * V_43 , unsigned int V_319 , unsigned long V_227 )
{
switch ( V_319 ) {
case V_346 :
V_319 = V_320 ;
break;
case V_347 :
V_319 = V_321 ;
break;
case V_348 :
V_319 = V_322 ;
break;
case V_323 :
case V_324 :
case V_325 :
case V_326 :
case V_327 :
case V_328 :
case V_330 :
case V_332 :
case V_331 :
case V_333 :
case V_334 :
case V_335 :
case V_336 :
case V_337 :
break;
default:
return - V_349 ;
}
return F_262 ( V_43 , V_319 , ( unsigned long ) F_273 ( V_227 ) ) ;
}
