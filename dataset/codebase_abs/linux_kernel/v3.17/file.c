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
V_13 = F_6 ( V_6 , V_14 + 1 , V_5 ) ;
if ( V_13 )
goto V_15;
F_7 ( V_9 ) ;
F_8 ( & V_12 , V_6 , NULL , NULL , 0 ) ;
V_13 = F_9 ( & V_12 , V_5 -> V_16 ) ;
F_10 ( V_9 ) ;
if ( V_13 )
goto V_15;
F_11 ( V_2 -> V_7 ) ;
F_12 ( V_5 ) ;
if ( F_13 ( V_5 -> V_17 != V_6 -> V_18 ||
F_14 ( V_5 ) > F_15 ( V_6 ) ||
! F_16 ( V_5 ) ) ) {
F_17 ( V_5 ) ;
V_13 = - V_19 ;
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
F_24 ( V_6 -> V_10 ) ;
return F_25 ( V_13 ) ;
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
struct V_8 * V_9 = F_3 ( V_6 -> V_10 ) ;
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
struct V_8 * V_9 = F_3 ( V_6 -> V_10 ) ;
int V_42 = 0 ;
bool V_29 = false ;
struct V_43 V_44 = {
. V_45 = V_46 ,
. V_47 = V_48 ,
. V_49 = 0 ,
} ;
if ( F_13 ( F_42 ( V_6 -> V_10 ) ) )
return 0 ;
F_43 ( V_6 ) ;
if ( V_37 )
F_44 ( V_41 , V_50 ) ;
V_42 = F_45 ( V_6 -> V_18 , V_35 , V_36 ) ;
if ( V_37 )
F_46 ( V_41 , V_50 ) ;
if ( V_42 ) {
F_47 ( V_6 , V_29 , V_37 , V_42 ) ;
return V_42 ;
}
if ( ! F_48 ( V_41 , V_51 ) &&
! F_49 ( V_9 , V_6 -> V_52 , V_53 ) ) {
if ( F_48 ( V_41 , V_54 ) ||
F_49 ( V_9 , V_6 -> V_52 , V_55 ) )
goto V_56;
goto V_15;
}
F_4 ( V_9 ) ;
F_50 ( & V_41 -> V_57 ) ;
V_29 = F_33 ( V_6 ) ;
F_51 ( & V_41 -> V_57 ) ;
if ( V_29 ) {
T_1 V_26 ;
V_42 = F_52 ( V_6 -> V_10 , 1 ) ;
F_53 ( & V_41 -> V_57 ) ;
F_38 ( V_6 ) -> V_33 = 0 ;
if ( F_35 ( V_6 ) && V_6 -> V_31 == 1 &&
F_26 ( V_6 , & V_26 ) ) {
F_38 ( V_6 ) -> V_32 = V_26 ;
F_54 ( V_6 ) ;
F_55 ( & V_41 -> V_57 ) ;
F_56 ( V_6 ) ;
V_42 = F_57 ( V_6 , NULL ) ;
if ( V_42 )
goto V_15;
} else {
F_55 ( & V_41 -> V_57 ) ;
}
} else {
while ( ! F_58 ( V_9 , V_6 -> V_52 , & V_44 ) ) {
if ( F_59 ( V_9 , V_6 -> V_52 ) )
goto V_15;
F_56 ( V_6 ) ;
V_42 = F_57 ( V_6 , NULL ) ;
if ( V_42 )
goto V_15;
}
V_42 = F_60 ( V_9 , V_6 -> V_52 ) ;
if ( V_42 )
goto V_15;
F_61 ( V_9 , V_6 -> V_52 , V_53 ) ;
F_46 ( V_41 , V_51 ) ;
V_56:
F_61 ( V_9 , V_6 -> V_52 , V_55 ) ;
F_46 ( V_41 , V_54 ) ;
V_42 = F_62 ( F_3 ( V_6 -> V_10 ) ) ;
}
V_15:
F_47 ( V_6 , V_29 , V_37 , V_42 ) ;
return V_42 ;
}
static T_3 F_63 ( struct V_58 * V_17 ,
T_3 V_59 , int V_60 )
{
struct V_61 V_62 ;
int V_63 ;
if ( V_60 != V_64 )
return 0 ;
F_64 ( & V_62 , 0 ) ;
V_63 = F_65 ( & V_62 , V_17 , & V_59 ,
V_65 , 1 ) ;
V_59 = V_63 ? V_62 . V_66 [ 0 ] -> V_16 : V_48 ;
F_66 ( & V_62 ) ;
return V_59 ;
}
static bool F_67 ( T_4 V_67 , T_3 V_68 , T_3 V_59 ,
int V_60 )
{
switch ( V_60 ) {
case V_64 :
if ( ( V_67 == V_69 && V_68 == V_59 ) ||
( V_67 != V_69 && V_67 != V_70 ) )
return true ;
break;
case V_71 :
if ( V_67 == V_70 )
return true ;
break;
}
return false ;
}
static T_2 F_68 ( struct V_34 * V_34 , T_2 V_22 , int V_60 )
{
struct V_6 * V_6 = V_34 -> V_38 -> V_39 ;
T_2 V_72 = V_6 -> V_10 -> V_73 ;
struct V_11 V_12 ;
T_3 V_59 , V_74 , V_68 ;
T_2 V_75 = V_22 ;
T_2 V_76 ;
int V_13 = 0 ;
F_69 ( & V_6 -> V_77 ) ;
V_76 = F_15 ( V_6 ) ;
if ( V_22 >= V_76 )
goto V_78;
if ( F_70 ( V_6 ) ) {
if ( V_60 == V_71 )
V_75 = V_76 ;
goto V_79;
}
V_59 = ( T_3 ) ( V_22 >> V_21 ) ;
V_68 = F_63 ( V_6 -> V_18 , V_59 , V_60 ) ;
for (; V_75 < V_76 ; V_75 = V_59 << V_21 ) {
F_8 ( & V_12 , V_6 , NULL , NULL , 0 ) ;
V_13 = F_71 ( & V_12 , V_59 , V_80 ) ;
if ( V_13 && V_13 != - V_81 ) {
goto V_78;
} else if ( V_13 == - V_81 ) {
if ( V_60 == V_64 ) {
V_59 = F_72 ( V_59 ,
F_38 ( V_6 ) ) ;
continue;
} else {
goto V_79;
}
}
V_74 = F_73 ( V_12 . V_82 , F_38 ( V_6 ) ) ;
for (; V_12 . V_83 < V_74 ;
V_12 . V_83 ++ , V_59 ++ ,
V_75 = V_59 << V_21 ) {
T_4 V_67 ;
V_67 = F_74 ( V_12 . V_82 , V_12 . V_83 ) ;
if ( F_67 ( V_67 , V_68 , V_59 , V_60 ) ) {
F_75 ( & V_12 ) ;
goto V_79;
}
}
F_75 ( & V_12 ) ;
}
if ( V_60 == V_64 )
goto V_78;
V_79:
if ( V_60 == V_71 && V_75 > V_76 )
V_75 = V_76 ;
F_76 ( & V_6 -> V_77 ) ;
return F_77 ( V_34 , V_75 , V_72 ) ;
V_78:
F_76 ( & V_6 -> V_77 ) ;
return - V_84 ;
}
static T_2 F_78 ( struct V_34 * V_34 , T_2 V_22 , int V_60 )
{
struct V_6 * V_6 = V_34 -> V_38 -> V_39 ;
T_2 V_72 = V_6 -> V_10 -> V_73 ;
switch ( V_60 ) {
case V_85 :
case V_86 :
case V_87 :
return F_79 ( V_34 , V_22 , V_60 ,
V_72 , F_15 ( V_6 ) ) ;
case V_64 :
case V_71 :
return F_68 ( V_34 , V_22 , V_60 ) ;
}
return - V_88 ;
}
static int F_80 ( struct V_34 * V_34 , struct V_1 * V_2 )
{
F_81 ( V_34 ) ;
V_2 -> V_89 = & V_90 ;
return 0 ;
}
int F_82 ( struct V_11 * V_12 , int V_91 )
{
int V_92 = 0 , V_93 = V_12 -> V_83 ;
struct V_8 * V_9 = F_3 ( V_12 -> V_6 -> V_10 ) ;
struct V_94 * V_95 ;
T_5 * V_96 ;
V_95 = F_83 ( V_12 -> V_82 ) ;
V_96 = F_84 ( V_95 ) + V_93 ;
for (; V_91 > 0 ; V_91 -- , V_96 ++ , V_12 -> V_83 ++ ) {
T_4 V_67 = F_85 ( * V_96 ) ;
if ( V_67 == V_70 )
continue;
F_86 ( V_70 , V_12 ) ;
F_87 ( V_9 , V_67 ) ;
V_92 ++ ;
}
if ( V_92 ) {
F_88 ( V_9 , V_12 -> V_6 , V_92 ) ;
F_20 ( V_12 -> V_82 ) ;
F_89 ( V_12 ) ;
}
V_12 -> V_83 = V_93 ;
F_90 ( V_12 -> V_6 , V_12 -> V_97 ,
V_12 -> V_83 , V_92 ) ;
return V_92 ;
}
void F_91 ( struct V_11 * V_12 )
{
F_82 ( V_12 , V_98 ) ;
}
static void F_92 ( struct V_6 * V_6 , T_6 V_99 )
{
unsigned V_22 = V_99 & ( V_24 - 1 ) ;
struct V_5 * V_5 ;
if ( F_70 ( V_6 ) )
return F_93 ( V_6 , V_99 ) ;
if ( ! V_22 )
return;
V_5 = F_94 ( V_6 , V_99 >> V_21 , false ) ;
if ( F_95 ( V_5 ) )
return;
F_12 ( V_5 ) ;
if ( F_13 ( ! F_16 ( V_5 ) ||
V_5 -> V_17 != V_6 -> V_18 ) )
goto V_15;
F_23 ( V_5 , V_25 ) ;
F_96 ( V_5 , V_22 , V_24 - V_22 ) ;
F_20 ( V_5 ) ;
V_15:
F_97 ( V_5 , 1 ) ;
}
int F_98 ( struct V_6 * V_6 , T_6 V_99 , bool V_100 )
{
struct V_8 * V_9 = F_3 ( V_6 -> V_10 ) ;
unsigned int V_101 = V_6 -> V_10 -> V_102 ;
struct V_11 V_12 ;
T_3 V_103 ;
int V_91 = 0 , V_13 = 0 ;
F_99 ( V_6 , V_99 ) ;
if ( F_70 ( V_6 ) )
goto V_104;
V_103 = ( T_3 )
( ( V_99 + V_101 - 1 ) >> ( V_9 -> V_105 ) ) ;
if ( V_100 )
F_7 ( V_9 ) ;
F_8 ( & V_12 , V_6 , NULL , NULL , 0 ) ;
V_13 = F_71 ( & V_12 , V_103 , V_106 ) ;
if ( V_13 ) {
if ( V_13 == - V_81 )
goto V_107;
if ( V_100 )
F_10 ( V_9 ) ;
F_100 ( V_6 , V_13 ) ;
return V_13 ;
}
V_91 = F_73 ( V_12 . V_82 , F_38 ( V_6 ) ) ;
V_91 -= V_12 . V_83 ;
F_101 ( V_91 < 0 ) ;
if ( V_12 . V_83 || F_102 ( V_12 . V_82 ) ) {
F_82 ( & V_12 , V_91 ) ;
V_103 += V_91 ;
}
F_75 ( & V_12 ) ;
V_107:
V_13 = F_103 ( V_6 , V_103 ) ;
if ( V_100 )
F_10 ( V_9 ) ;
V_104:
F_92 ( V_6 , V_99 ) ;
F_100 ( V_6 , V_13 ) ;
return V_13 ;
}
void F_104 ( struct V_6 * V_6 )
{
if ( ! ( F_34 ( V_6 -> V_30 ) || F_105 ( V_6 -> V_30 ) ||
F_106 ( V_6 -> V_30 ) ) )
return;
F_107 ( V_6 ) ;
if ( ! F_98 ( V_6 , F_15 ( V_6 ) , true ) ) {
V_6 -> V_108 = V_6 -> V_109 = V_110 ;
F_108 ( V_6 ) ;
}
}
int F_109 ( struct V_111 * V_112 ,
struct V_27 * V_27 , struct V_113 * V_114 )
{
struct V_6 * V_6 = V_27 -> V_115 ;
F_110 ( V_6 , V_114 ) ;
V_114 -> V_116 <<= 3 ;
return 0 ;
}
static void F_111 ( struct V_6 * V_6 , const struct V_117 * V_118 )
{
struct V_40 * V_41 = F_38 ( V_6 ) ;
unsigned int V_119 = V_118 -> V_119 ;
if ( V_119 & V_120 )
V_6 -> V_121 = V_118 -> V_122 ;
if ( V_119 & V_123 )
V_6 -> V_124 = V_118 -> V_125 ;
if ( V_119 & V_126 )
V_6 -> V_127 = F_112 ( V_118 -> V_128 ,
V_6 -> V_10 -> V_129 ) ;
if ( V_119 & V_130 )
V_6 -> V_108 = F_112 ( V_118 -> V_131 ,
V_6 -> V_10 -> V_129 ) ;
if ( V_119 & V_132 )
V_6 -> V_109 = F_112 ( V_118 -> V_133 ,
V_6 -> V_10 -> V_129 ) ;
if ( V_119 & V_134 ) {
T_7 V_135 = V_118 -> V_136 ;
if ( ! F_113 ( V_6 -> V_124 ) && ! F_114 ( V_137 ) )
V_135 &= ~ V_138 ;
F_115 ( V_41 , V_135 ) ;
}
}
int F_116 ( struct V_27 * V_27 , struct V_117 * V_118 )
{
struct V_6 * V_6 = V_27 -> V_115 ;
struct V_40 * V_41 = F_38 ( V_6 ) ;
int V_13 ;
V_13 = F_117 ( V_6 , V_118 ) ;
if ( V_13 )
return V_13 ;
if ( ( V_118 -> V_119 & V_139 ) &&
V_118 -> V_140 != F_15 ( V_6 ) ) {
V_13 = F_6 ( V_6 , V_118 -> V_140 , NULL ) ;
if ( V_13 )
return V_13 ;
F_118 ( V_6 , V_118 -> V_140 ) ;
F_104 ( V_6 ) ;
F_4 ( F_3 ( V_6 -> V_10 ) ) ;
}
F_111 ( V_6 , V_118 ) ;
if ( V_118 -> V_119 & V_134 ) {
V_13 = F_119 ( V_6 , F_120 ( V_6 ) ) ;
if ( V_13 || F_48 ( V_41 , V_141 ) ) {
V_6 -> V_30 = V_41 -> V_142 ;
F_46 ( V_41 , V_141 ) ;
}
}
F_108 ( V_6 ) ;
return V_13 ;
}
static void F_121 ( struct V_6 * V_6 , T_3 V_16 ,
T_2 V_35 , T_2 V_143 )
{
struct V_8 * V_9 = F_3 ( V_6 -> V_10 ) ;
struct V_5 * V_5 ;
if ( ! V_143 )
return;
F_4 ( V_9 ) ;
F_7 ( V_9 ) ;
V_5 = F_122 ( V_6 , NULL , V_16 , false ) ;
F_10 ( V_9 ) ;
if ( ! F_95 ( V_5 ) ) {
F_23 ( V_5 , V_25 ) ;
F_96 ( V_5 , V_35 , V_143 ) ;
F_20 ( V_5 ) ;
F_97 ( V_5 , 1 ) ;
}
}
int F_123 ( struct V_6 * V_6 , T_3 V_144 , T_3 V_145 )
{
T_3 V_16 ;
int V_13 ;
for ( V_16 = V_144 ; V_16 < V_145 ; V_16 ++ ) {
struct V_11 V_12 ;
F_8 ( & V_12 , V_6 , NULL , NULL , 0 ) ;
V_13 = F_71 ( & V_12 , V_16 , V_106 ) ;
if ( V_13 ) {
if ( V_13 == - V_81 )
continue;
return V_13 ;
}
if ( V_12 . V_146 != V_70 )
F_82 ( & V_12 , 1 ) ;
F_75 ( & V_12 ) ;
}
return 0 ;
}
static int F_124 ( struct V_6 * V_6 , T_2 V_22 , T_2 V_143 )
{
T_3 V_144 , V_145 ;
T_2 V_147 , V_148 ;
int V_42 = 0 ;
V_42 = F_6 ( V_6 , V_14 + 1 , NULL ) ;
if ( V_42 )
return V_42 ;
V_144 = ( ( unsigned long long ) V_22 ) >> V_21 ;
V_145 = ( ( unsigned long long ) V_22 + V_143 ) >> V_21 ;
V_147 = V_22 & ( V_24 - 1 ) ;
V_148 = ( V_22 + V_143 ) & ( V_24 - 1 ) ;
if ( V_144 == V_145 ) {
F_121 ( V_6 , V_144 , V_147 ,
V_148 - V_147 ) ;
} else {
if ( V_147 )
F_121 ( V_6 , V_144 ++ , V_147 ,
V_24 - V_147 ) ;
if ( V_148 )
F_121 ( V_6 , V_145 , 0 , V_148 ) ;
if ( V_144 < V_145 ) {
struct V_58 * V_17 = V_6 -> V_18 ;
T_2 V_149 , V_150 ;
struct V_8 * V_9 = F_3 ( V_6 -> V_10 ) ;
F_4 ( V_9 ) ;
V_149 = V_144 << V_21 ;
V_150 = V_145 << V_21 ;
F_125 ( V_17 , V_149 ,
V_150 - 1 ) ;
F_7 ( V_9 ) ;
V_42 = F_123 ( V_6 , V_144 , V_145 ) ;
F_10 ( V_9 ) ;
}
}
return V_42 ;
}
static int F_126 ( struct V_6 * V_6 , T_2 V_22 ,
T_2 V_143 , int V_135 )
{
struct V_8 * V_9 = F_3 ( V_6 -> V_10 ) ;
T_3 V_16 , V_144 , V_145 ;
T_2 V_151 = F_15 ( V_6 ) ;
T_2 V_147 , V_148 ;
int V_42 = 0 ;
F_4 ( V_9 ) ;
V_42 = F_127 ( V_6 , ( V_143 + V_22 ) ) ;
if ( V_42 )
return V_42 ;
V_42 = F_6 ( V_6 , V_22 + V_143 , NULL ) ;
if ( V_42 )
return V_42 ;
V_144 = ( ( unsigned long long ) V_22 ) >> V_21 ;
V_145 = ( ( unsigned long long ) V_22 + V_143 ) >> V_21 ;
V_147 = V_22 & ( V_24 - 1 ) ;
V_148 = ( V_22 + V_143 ) & ( V_24 - 1 ) ;
F_7 ( V_9 ) ;
for ( V_16 = V_144 ; V_16 <= V_145 ; V_16 ++ ) {
struct V_11 V_12 ;
if ( V_16 == V_145 && ! V_148 )
goto V_152;
F_8 ( & V_12 , V_6 , NULL , NULL , 0 ) ;
V_42 = F_9 ( & V_12 , V_16 ) ;
if ( V_42 )
break;
V_152:
if ( V_144 == V_145 )
V_151 = V_22 + V_143 ;
else if ( V_16 == V_144 && V_147 )
V_151 = ( V_16 + 1 ) << V_21 ;
else if ( V_16 == V_145 )
V_151 = ( V_16 << V_21 ) + V_148 ;
else
V_151 += V_24 ;
}
if ( ! ( V_135 & V_153 ) &&
F_15 ( V_6 ) < V_151 ) {
F_128 ( V_6 , V_151 ) ;
F_108 ( V_6 ) ;
F_129 ( V_6 ) ;
}
F_10 ( V_9 ) ;
return V_42 ;
}
static long F_130 ( struct V_34 * V_34 , int V_135 ,
T_2 V_22 , T_2 V_143 )
{
struct V_6 * V_6 = F_2 ( V_34 ) ;
long V_42 ;
if ( V_135 & ~ ( V_153 | V_154 ) )
return - V_155 ;
F_69 ( & V_6 -> V_77 ) ;
if ( V_135 & V_154 )
V_42 = F_124 ( V_6 , V_22 , V_143 ) ;
else
V_42 = F_126 ( V_6 , V_22 , V_143 , V_135 ) ;
if ( ! V_42 ) {
V_6 -> V_108 = V_6 -> V_109 = V_110 ;
F_108 ( V_6 ) ;
}
F_76 ( & V_6 -> V_77 ) ;
F_131 ( V_6 , V_135 , V_22 , V_143 , V_42 ) ;
return V_42 ;
}
static inline T_8 F_132 ( T_7 V_135 , T_8 V_156 )
{
if ( F_105 ( V_135 ) )
return V_156 ;
else if ( F_34 ( V_135 ) )
return V_156 & V_157 ;
else
return V_156 & V_158 ;
}
long F_133 ( struct V_34 * V_159 , unsigned int V_160 , unsigned long V_161 )
{
struct V_6 * V_6 = F_2 ( V_159 ) ;
struct V_40 * V_41 = F_38 ( V_6 ) ;
unsigned int V_156 ;
int V_42 ;
switch ( V_160 ) {
case V_162 :
V_156 = V_41 -> V_163 & V_164 ;
return F_134 ( V_156 , ( int V_165 * ) V_161 ) ;
case V_166 :
{
unsigned int V_167 ;
V_42 = F_135 ( V_159 ) ;
if ( V_42 )
return V_42 ;
if ( ! F_136 ( V_6 ) ) {
V_42 = - V_168 ;
goto V_15;
}
if ( F_137 ( V_156 , ( int V_165 * ) V_161 ) ) {
V_42 = - V_19 ;
goto V_15;
}
V_156 = F_132 ( V_6 -> V_30 , V_156 ) ;
F_69 ( & V_6 -> V_77 ) ;
V_167 = V_41 -> V_163 ;
if ( ( V_156 ^ V_167 ) & ( V_169 | V_170 ) ) {
if ( ! F_114 ( V_171 ) ) {
F_76 ( & V_6 -> V_77 ) ;
V_42 = - V_172 ;
goto V_15;
}
}
V_156 = V_156 & V_173 ;
V_156 |= V_167 & ~ V_173 ;
V_41 -> V_163 = V_156 ;
F_76 ( & V_6 -> V_77 ) ;
F_138 ( V_6 ) ;
V_6 -> V_109 = V_110 ;
F_108 ( V_6 ) ;
V_15:
F_139 ( V_159 ) ;
return V_42 ;
}
default:
return - V_174 ;
}
}
long F_140 ( struct V_34 * V_34 , unsigned int V_160 , unsigned long V_161 )
{
switch ( V_160 ) {
case V_175 :
V_160 = V_162 ;
break;
case V_176 :
V_160 = V_166 ;
break;
default:
return - V_177 ;
}
return F_133 ( V_34 , V_160 , ( unsigned long ) F_141 ( V_161 ) ) ;
}
