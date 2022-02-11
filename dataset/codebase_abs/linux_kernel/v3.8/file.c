static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_5 = V_4 -> V_5 ;
struct V_6 * V_6 = V_2 -> V_7 -> V_8 . V_9 -> V_10 ;
struct V_11 * V_12 = F_2 ( V_6 -> V_13 ) ;
T_1 V_14 ;
struct V_15 V_16 ;
int V_17 ;
F_3 ( V_12 ) ;
F_4 ( V_6 -> V_13 ) ;
F_5 ( V_12 , V_18 ) ;
F_6 ( & V_16 , V_6 , NULL , NULL , 0 ) ;
V_17 = F_7 ( & V_16 , V_5 -> V_19 , 0 ) ;
if ( V_17 ) {
F_8 ( V_12 , V_18 ) ;
goto V_20;
}
V_14 = V_16 . V_21 ;
if ( V_14 == V_22 ) {
V_17 = F_9 ( & V_16 ) ;
if ( V_17 ) {
F_10 ( & V_16 ) ;
F_8 ( V_12 , V_18 ) ;
goto V_20;
}
}
F_10 ( & V_16 ) ;
F_8 ( V_12 , V_18 ) ;
F_11 ( V_5 ) ;
if ( V_5 -> V_23 != V_6 -> V_24 ||
F_12 ( V_5 ) >= F_13 ( V_6 ) ||
! F_14 ( V_5 ) ) {
F_15 ( V_5 ) ;
V_17 = - V_25 ;
goto V_20;
}
if ( F_16 ( V_5 ) )
goto V_20;
F_17 ( V_5 ) ;
if ( ( ( V_5 -> V_19 + 1 ) << V_26 ) > F_13 ( V_6 ) ) {
unsigned V_27 ;
V_27 = F_13 ( V_6 ) & ~ V_28 ;
F_18 ( V_5 , V_27 , V_29 ) ;
}
F_19 ( V_5 ) ;
F_20 ( V_5 ) ;
F_21 ( V_2 -> V_7 ) ;
V_20:
F_22 ( V_6 -> V_13 ) ;
return F_23 ( V_17 ) ;
}
static int F_24 ( struct V_11 * V_12 , struct V_6 * V_6 )
{
struct V_9 * V_9 ;
T_2 V_30 ;
V_6 = F_25 ( V_6 ) ;
V_9 = F_26 ( V_6 ) ;
if ( ! V_9 ) {
F_27 ( V_6 ) ;
return 0 ;
}
V_30 = V_9 -> V_31 -> V_10 -> V_32 ;
F_28 ( V_9 ) ;
F_27 ( V_6 ) ;
return ! F_29 ( V_12 , V_30 ) ;
}
int F_30 ( struct V_33 * V_33 , T_3 V_34 , T_3 V_35 , int V_36 )
{
struct V_6 * V_6 = V_33 -> V_37 -> V_38 ;
struct V_11 * V_12 = F_2 ( V_6 -> V_13 ) ;
unsigned long long V_39 ;
int V_40 = 0 ;
bool V_41 = false ;
struct V_42 V_43 = {
. V_44 = V_45 ,
. V_46 = V_47 ,
. V_48 = 0 ,
} ;
if ( V_6 -> V_13 -> V_49 & V_50 )
return 0 ;
V_40 = F_31 ( V_6 -> V_24 , V_34 , V_35 ) ;
if ( V_40 )
return V_40 ;
F_3 ( V_12 ) ;
F_32 ( & V_6 -> V_51 ) ;
if ( V_36 && ! ( V_6 -> V_52 & V_53 ) )
goto V_20;
F_32 ( & V_12 -> V_54 ) ;
V_39 = F_33 ( F_34 ( V_12 ) -> V_55 ) ;
F_35 ( & V_12 -> V_54 ) ;
if ( F_36 ( V_6 ) -> V_56 != V_39 &&
! ( V_6 -> V_52 & V_57 ) )
goto V_20;
F_36 ( V_6 ) -> V_56 -- ;
if ( ! F_37 ( V_6 -> V_58 ) || V_6 -> V_59 != 1 )
V_41 = true ;
if ( F_38 ( F_36 ( V_6 ) , V_60 ) )
V_41 = true ;
if ( ! F_39 ( V_12 ) )
V_41 = true ;
if ( F_24 ( V_12 , V_6 ) )
V_41 = true ;
if ( V_41 ) {
V_40 = F_40 ( V_6 -> V_13 , 1 ) ;
F_41 ( F_36 ( V_6 ) , V_60 ) ;
} else {
while ( ! F_42 ( V_12 , V_6 -> V_32 , & V_43 ) ) {
V_40 = F_43 ( V_6 , NULL ) ;
if ( V_40 )
goto V_20;
}
F_44 ( V_12 -> V_61 -> V_24 ,
0 , V_47 ) ;
}
V_20:
F_35 ( & V_6 -> V_51 ) ;
return V_40 ;
}
static int F_45 ( struct V_33 * V_33 , struct V_1 * V_2 )
{
F_46 ( V_33 ) ;
V_2 -> V_62 = & V_63 ;
return 0 ;
}
static int F_47 ( struct V_15 * V_16 , int V_64 )
{
int V_65 = 0 , V_66 = V_16 -> V_67 ;
struct V_11 * V_12 = F_2 ( V_16 -> V_6 -> V_13 ) ;
struct V_68 * V_69 ;
T_4 * V_70 ;
V_69 = F_48 ( V_16 -> V_71 ) ;
V_70 = F_49 ( V_69 ) + V_66 ;
for ( ; V_64 > 0 ; V_64 -- , V_70 ++ , V_16 -> V_67 ++ ) {
T_1 V_72 = F_50 ( * V_70 ) ;
if ( V_72 == V_22 )
continue;
F_51 ( V_22 , V_16 ) ;
F_52 ( V_12 , V_72 ) ;
F_53 ( V_12 , V_16 -> V_6 , 1 ) ;
V_65 ++ ;
}
if ( V_65 ) {
F_19 ( V_16 -> V_71 ) ;
F_54 ( V_16 ) ;
}
V_16 -> V_67 = V_66 ;
return V_65 ;
}
void F_55 ( struct V_15 * V_16 )
{
F_47 ( V_16 , V_73 ) ;
}
static void F_56 ( struct V_6 * V_6 , T_5 V_74 )
{
unsigned V_27 = V_74 & ( V_29 - 1 ) ;
struct V_5 * V_5 ;
if ( ! V_27 )
return;
V_5 = F_57 ( V_6 , V_74 >> V_26 ) ;
if ( F_58 ( V_5 ) )
return;
F_11 ( V_5 ) ;
F_17 ( V_5 ) ;
F_59 ( V_5 , V_27 , V_29 - V_27 ) ;
F_19 ( V_5 ) ;
F_60 ( V_5 , 1 ) ;
}
static int F_61 ( struct V_6 * V_6 , T_5 V_74 )
{
struct V_11 * V_12 = F_2 ( V_6 -> V_13 ) ;
unsigned int V_75 = V_6 -> V_13 -> V_76 ;
struct V_15 V_16 ;
T_6 V_77 ;
int V_64 = 0 ;
int V_17 ;
V_77 = ( T_6 )
( ( V_74 + V_75 - 1 ) >> ( V_12 -> V_78 ) ) ;
F_5 ( V_12 , V_79 ) ;
F_6 ( & V_16 , V_6 , NULL , NULL , 0 ) ;
V_17 = F_7 ( & V_16 , V_77 , V_80 ) ;
if ( V_17 ) {
if ( V_17 == - V_81 )
goto V_82;
F_8 ( V_12 , V_79 ) ;
return V_17 ;
}
if ( F_62 ( V_16 . V_71 ) )
V_64 = V_83 ;
else
V_64 = V_73 ;
V_64 -= V_16 . V_67 ;
F_63 ( V_64 < 0 ) ;
if ( V_16 . V_67 || F_62 ( V_16 . V_71 ) ) {
F_47 ( & V_16 , V_64 ) ;
V_77 += V_64 ;
}
F_10 ( & V_16 ) ;
V_82:
V_17 = F_64 ( V_6 , V_77 ) ;
F_8 ( V_12 , V_79 ) ;
F_56 ( V_6 , V_74 ) ;
return V_17 ;
}
void F_65 ( struct V_6 * V_6 )
{
if ( ! ( F_37 ( V_6 -> V_58 ) || F_66 ( V_6 -> V_58 ) ||
F_67 ( V_6 -> V_58 ) ) )
return;
if ( ! F_61 ( V_6 , F_13 ( V_6 ) ) ) {
V_6 -> V_84 = V_6 -> V_85 = V_86 ;
F_68 ( V_6 ) ;
}
F_3 ( F_2 ( V_6 -> V_13 ) ) ;
}
static int F_69 ( struct V_87 * V_88 ,
struct V_9 * V_9 , struct V_89 * V_90 )
{
struct V_6 * V_6 = V_9 -> V_10 ;
F_70 ( V_6 , V_90 ) ;
V_90 -> V_91 <<= 3 ;
return 0 ;
}
static void F_71 ( struct V_6 * V_6 , const struct V_92 * V_93 )
{
struct V_94 * V_95 = F_36 ( V_6 ) ;
unsigned int V_96 = V_93 -> V_96 ;
if ( V_96 & V_97 )
V_6 -> V_98 = V_93 -> V_99 ;
if ( V_96 & V_100 )
V_6 -> V_101 = V_93 -> V_102 ;
if ( V_96 & V_103 )
V_6 -> V_104 = F_72 ( V_93 -> V_105 ,
V_6 -> V_13 -> V_106 ) ;
if ( V_96 & V_107 )
V_6 -> V_84 = F_72 ( V_93 -> V_108 ,
V_6 -> V_13 -> V_106 ) ;
if ( V_96 & V_109 )
V_6 -> V_85 = F_72 ( V_93 -> V_110 ,
V_6 -> V_13 -> V_106 ) ;
if ( V_96 & V_111 ) {
T_7 V_112 = V_93 -> V_113 ;
if ( ! F_73 ( V_6 -> V_101 ) && ! F_74 ( V_114 ) )
V_112 &= ~ V_115 ;
F_75 ( V_95 , V_112 ) ;
}
}
int F_76 ( struct V_9 * V_9 , struct V_92 * V_93 )
{
struct V_6 * V_6 = V_9 -> V_10 ;
struct V_94 * V_95 = F_36 ( V_6 ) ;
int V_17 ;
V_17 = F_77 ( V_6 , V_93 ) ;
if ( V_17 )
return V_17 ;
if ( ( V_93 -> V_96 & V_116 ) &&
V_93 -> V_117 != F_13 ( V_6 ) ) {
F_78 ( V_6 , V_93 -> V_117 ) ;
F_65 ( V_6 ) ;
}
F_71 ( V_6 , V_93 ) ;
if ( V_93 -> V_96 & V_111 ) {
V_17 = F_79 ( V_6 ) ;
if ( V_17 || F_38 ( V_95 , V_118 ) ) {
V_6 -> V_58 = V_95 -> V_119 ;
F_41 ( V_95 , V_118 ) ;
}
}
F_68 ( V_6 ) ;
return V_17 ;
}
static void F_80 ( struct V_6 * V_6 , T_6 V_19 ,
T_3 V_34 , T_3 V_120 )
{
struct V_5 * V_5 ;
if ( ! V_120 )
return;
V_5 = F_81 ( V_6 , V_19 , false ) ;
if ( ! F_58 ( V_5 ) ) {
F_17 ( V_5 ) ;
F_59 ( V_5 , V_34 , V_120 ) ;
F_19 ( V_5 ) ;
F_60 ( V_5 , 1 ) ;
}
}
int F_82 ( struct V_6 * V_6 , T_6 V_121 , T_6 V_122 )
{
T_6 V_19 ;
int V_17 ;
for ( V_19 = V_121 ; V_19 < V_122 ; V_19 ++ ) {
struct V_15 V_16 ;
struct V_11 * V_12 = F_2 ( V_6 -> V_13 ) ;
F_3 ( V_12 ) ;
F_5 ( V_12 , V_79 ) ;
F_6 ( & V_16 , V_6 , NULL , NULL , 0 ) ;
V_17 = F_7 ( & V_16 , V_19 , V_80 ) ;
if ( V_17 ) {
F_8 ( V_12 , V_79 ) ;
if ( V_17 == - V_81 )
continue;
return V_17 ;
}
if ( V_16 . V_21 != V_22 )
F_47 ( & V_16 , 1 ) ;
F_10 ( & V_16 ) ;
F_8 ( V_12 , V_79 ) ;
}
return 0 ;
}
static int F_83 ( struct V_6 * V_6 , T_3 V_27 , T_3 V_120 , int V_112 )
{
T_6 V_121 , V_122 ;
T_3 V_123 , V_124 ;
int V_40 = 0 ;
V_121 = ( ( unsigned long long ) V_27 ) >> V_26 ;
V_122 = ( ( unsigned long long ) V_27 + V_120 ) >> V_26 ;
V_123 = V_27 & ( V_29 - 1 ) ;
V_124 = ( V_27 + V_120 ) & ( V_29 - 1 ) ;
if ( V_121 == V_122 ) {
F_80 ( V_6 , V_121 , V_123 ,
V_124 - V_123 ) ;
} else {
if ( V_123 )
F_80 ( V_6 , V_121 ++ , V_123 ,
V_29 - V_123 ) ;
if ( V_124 )
F_80 ( V_6 , V_122 , 0 , V_124 ) ;
if ( V_121 < V_122 ) {
struct V_125 * V_23 = V_6 -> V_24 ;
T_3 V_126 , V_127 ;
V_126 = V_121 << V_26 ;
V_127 = V_122 << V_26 ;
F_84 ( V_23 , V_126 ,
V_127 - 1 ) ;
V_40 = F_82 ( V_6 , V_121 , V_122 ) ;
}
}
if ( ! ( V_112 & V_128 ) &&
F_13 ( V_6 ) <= ( V_27 + V_120 ) ) {
F_85 ( V_6 , V_27 ) ;
F_68 ( V_6 ) ;
}
return V_40 ;
}
static int F_86 ( struct V_6 * V_6 , T_3 V_27 ,
T_3 V_120 , int V_112 )
{
struct V_11 * V_12 = F_2 ( V_6 -> V_13 ) ;
T_6 V_19 , V_121 , V_122 ;
T_3 V_129 = F_13 ( V_6 ) ;
T_3 V_123 , V_124 ;
int V_40 = 0 ;
V_40 = F_87 ( V_6 , ( V_120 + V_27 ) ) ;
if ( V_40 )
return V_40 ;
V_121 = ( ( unsigned long long ) V_27 ) >> V_26 ;
V_122 = ( ( unsigned long long ) V_27 + V_120 ) >> V_26 ;
V_123 = V_27 & ( V_29 - 1 ) ;
V_124 = ( V_27 + V_120 ) & ( V_29 - 1 ) ;
for ( V_19 = V_121 ; V_19 <= V_122 ; V_19 ++ ) {
struct V_15 V_16 ;
F_5 ( V_12 , V_18 ) ;
F_6 ( & V_16 , V_6 , NULL , NULL , 0 ) ;
V_40 = F_7 ( & V_16 , V_19 , 0 ) ;
if ( V_40 ) {
F_8 ( V_12 , V_18 ) ;
break;
}
if ( V_16 . V_21 == V_22 ) {
V_40 = F_9 ( & V_16 ) ;
if ( V_40 ) {
F_10 ( & V_16 ) ;
F_8 ( V_12 , V_18 ) ;
break;
}
}
F_10 ( & V_16 ) ;
F_8 ( V_12 , V_18 ) ;
if ( V_121 == V_122 )
V_129 = V_27 + V_120 ;
else if ( V_19 == V_121 && V_123 )
V_129 = ( V_19 + 1 ) << V_26 ;
else if ( V_19 == V_122 )
V_129 = ( V_19 << V_26 ) + V_124 ;
else
V_129 += V_29 ;
}
if ( ! ( V_112 & V_128 ) &&
F_13 ( V_6 ) < V_129 ) {
F_85 ( V_6 , V_129 ) ;
F_68 ( V_6 ) ;
}
return V_40 ;
}
static long F_88 ( struct V_33 * V_33 , int V_112 ,
T_3 V_27 , T_3 V_120 )
{
struct V_6 * V_6 = V_33 -> V_8 . V_9 -> V_10 ;
long V_40 ;
if ( V_112 & ~ ( V_128 | V_130 ) )
return - V_131 ;
if ( V_112 & V_130 )
V_40 = F_83 ( V_6 , V_27 , V_120 , V_112 ) ;
else
V_40 = F_86 ( V_6 , V_27 , V_120 , V_112 ) ;
if ( ! V_40 ) {
V_6 -> V_84 = V_6 -> V_85 = V_86 ;
F_68 ( V_6 ) ;
}
return V_40 ;
}
static inline T_8 F_89 ( T_7 V_112 , T_8 V_132 )
{
if ( F_66 ( V_112 ) )
return V_132 ;
else if ( F_37 ( V_112 ) )
return V_132 & V_133 ;
else
return V_132 & V_134 ;
}
long F_90 ( struct V_33 * V_135 , unsigned int V_136 , unsigned long V_137 )
{
struct V_6 * V_6 = V_135 -> V_138 -> V_10 ;
struct V_94 * V_95 = F_36 ( V_6 ) ;
unsigned int V_132 ;
int V_40 ;
switch ( V_136 ) {
case V_139 :
V_132 = V_95 -> V_140 & V_141 ;
return F_91 ( V_132 , ( int V_142 * ) V_137 ) ;
case V_143 :
{
unsigned int V_144 ;
V_40 = F_92 ( V_135 -> V_8 . V_88 ) ;
if ( V_40 )
return V_40 ;
if ( ! F_93 ( V_6 ) ) {
V_40 = - V_145 ;
goto V_20;
}
if ( F_94 ( V_132 , ( int V_142 * ) V_137 ) ) {
V_40 = - V_25 ;
goto V_20;
}
V_132 = F_89 ( V_6 -> V_58 , V_132 ) ;
F_32 ( & V_6 -> V_51 ) ;
V_144 = V_95 -> V_140 ;
if ( ( V_132 ^ V_144 ) & ( V_146 | V_147 ) ) {
if ( ! F_74 ( V_148 ) ) {
F_35 ( & V_6 -> V_51 ) ;
V_40 = - V_149 ;
goto V_20;
}
}
V_132 = V_132 & V_150 ;
V_132 |= V_144 & ~ V_150 ;
V_95 -> V_140 = V_132 ;
F_35 ( & V_6 -> V_51 ) ;
F_95 ( V_6 ) ;
V_6 -> V_85 = V_86 ;
F_68 ( V_6 ) ;
V_20:
F_96 ( V_135 -> V_8 . V_88 ) ;
return V_40 ;
}
default:
return - V_151 ;
}
}
