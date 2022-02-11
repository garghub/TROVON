static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_5 = V_4 -> V_5 ;
struct V_6 * V_6 = F_2 ( V_2 -> V_7 ) ;
struct V_8 * V_9 = F_3 ( V_6 -> V_10 ) ;
T_1 V_11 ;
struct V_12 V_13 ;
int V_14 ;
F_4 ( V_9 ) ;
F_5 ( V_6 -> V_10 ) ;
F_6 ( V_9 , V_15 ) ;
F_7 ( & V_13 , V_6 , NULL , NULL , 0 ) ;
V_14 = F_8 ( & V_13 , V_5 -> V_16 , 0 ) ;
if ( V_14 ) {
F_9 ( V_9 , V_15 ) ;
goto V_17;
}
V_11 = V_13 . V_18 ;
if ( V_11 == V_19 ) {
V_14 = F_10 ( & V_13 ) ;
if ( V_14 ) {
F_11 ( & V_13 ) ;
F_9 ( V_9 , V_15 ) ;
goto V_17;
}
}
F_11 ( & V_13 ) ;
F_9 ( V_9 , V_15 ) ;
F_12 ( V_5 ) ;
if ( V_5 -> V_20 != V_6 -> V_21 ||
F_13 ( V_5 ) >= F_14 ( V_6 ) ||
! F_15 ( V_5 ) ) {
F_16 ( V_5 ) ;
V_14 = - V_22 ;
goto V_17;
}
if ( F_17 ( V_5 ) )
goto V_17;
F_18 ( V_5 ) ;
if ( ( ( V_5 -> V_16 + 1 ) << V_23 ) > F_14 ( V_6 ) ) {
unsigned V_24 ;
V_24 = F_14 ( V_6 ) & ~ V_25 ;
F_19 ( V_5 , V_24 , V_26 ) ;
}
F_20 ( V_5 ) ;
F_21 ( V_5 ) ;
F_22 ( V_2 -> V_7 ) ;
V_17:
F_23 ( V_6 -> V_10 ) ;
return F_24 ( V_14 ) ;
}
static int F_25 ( struct V_8 * V_9 , struct V_6 * V_6 )
{
struct V_27 * V_27 ;
T_2 V_28 ;
V_6 = F_26 ( V_6 ) ;
V_27 = F_27 ( V_6 ) ;
if ( ! V_27 ) {
F_28 ( V_6 ) ;
return 0 ;
}
V_28 = V_27 -> V_29 -> V_30 -> V_31 ;
F_29 ( V_27 ) ;
F_28 ( V_6 ) ;
return ! F_30 ( V_9 , V_28 ) ;
}
int F_31 ( struct V_32 * V_32 , T_3 V_33 , T_3 V_34 , int V_35 )
{
struct V_6 * V_6 = V_32 -> V_36 -> V_37 ;
struct V_8 * V_9 = F_3 ( V_6 -> V_10 ) ;
unsigned long long V_38 ;
int V_39 = 0 ;
bool V_40 = false ;
struct V_41 V_42 = {
. V_43 = V_44 ,
. V_45 = V_46 ,
. V_47 = 0 ,
} ;
if ( V_6 -> V_10 -> V_48 & V_49 )
return 0 ;
V_39 = F_32 ( V_6 -> V_21 , V_33 , V_34 ) ;
if ( V_39 )
return V_39 ;
F_4 ( V_9 ) ;
F_33 ( & V_6 -> V_50 ) ;
if ( V_35 && ! ( V_6 -> V_51 & V_52 ) )
goto V_17;
F_33 ( & V_9 -> V_53 ) ;
V_38 = F_34 ( F_35 ( V_9 ) -> V_54 ) ;
F_36 ( & V_9 -> V_53 ) ;
if ( F_37 ( V_6 ) -> V_55 != V_38 &&
! ( V_6 -> V_51 & V_56 ) )
goto V_17;
F_37 ( V_6 ) -> V_55 -- ;
if ( ! F_38 ( V_6 -> V_57 ) || V_6 -> V_58 != 1 )
V_40 = true ;
else if ( F_39 ( F_37 ( V_6 ) , V_59 ) )
V_40 = true ;
else if ( ! F_40 ( V_9 ) )
V_40 = true ;
else if ( F_25 ( V_9 , V_6 ) )
V_40 = true ;
if ( V_40 ) {
V_39 = F_41 ( V_6 -> V_10 , 1 ) ;
F_42 ( F_37 ( V_6 ) , V_59 ) ;
} else {
while ( ! F_43 ( V_9 , V_6 -> V_31 , & V_42 ) ) {
V_39 = F_44 ( V_6 , NULL ) ;
if ( V_39 )
goto V_17;
}
F_45 ( V_9 -> V_60 -> V_21 ,
0 , V_46 ) ;
}
V_17:
F_36 ( & V_6 -> V_50 ) ;
return V_39 ;
}
static int F_46 ( struct V_32 * V_32 , struct V_1 * V_2 )
{
F_47 ( V_32 ) ;
V_2 -> V_61 = & V_62 ;
return 0 ;
}
static int F_48 ( struct V_12 * V_13 , int V_63 )
{
int V_64 = 0 , V_65 = V_13 -> V_66 ;
struct V_8 * V_9 = F_3 ( V_13 -> V_6 -> V_10 ) ;
struct V_67 * V_68 ;
T_4 * V_69 ;
V_68 = F_49 ( V_13 -> V_70 ) ;
V_69 = F_50 ( V_68 ) + V_65 ;
for ( ; V_63 > 0 ; V_63 -- , V_69 ++ , V_13 -> V_66 ++ ) {
T_1 V_71 = F_51 ( * V_69 ) ;
if ( V_71 == V_19 )
continue;
F_52 ( V_19 , V_13 ) ;
F_53 ( V_9 , V_71 ) ;
F_54 ( V_9 , V_13 -> V_6 , 1 ) ;
V_64 ++ ;
}
if ( V_64 ) {
F_20 ( V_13 -> V_70 ) ;
F_55 ( V_13 ) ;
}
V_13 -> V_66 = V_65 ;
return V_64 ;
}
void F_56 ( struct V_12 * V_13 )
{
F_48 ( V_13 , V_72 ) ;
}
static void F_57 ( struct V_6 * V_6 , T_5 V_73 )
{
unsigned V_24 = V_73 & ( V_26 - 1 ) ;
struct V_5 * V_5 ;
if ( ! V_24 )
return;
V_5 = F_58 ( V_6 , V_73 >> V_23 ) ;
if ( F_59 ( V_5 ) )
return;
F_12 ( V_5 ) ;
F_18 ( V_5 ) ;
F_60 ( V_5 , V_24 , V_26 - V_24 ) ;
F_20 ( V_5 ) ;
F_61 ( V_5 , 1 ) ;
}
static int F_62 ( struct V_6 * V_6 , T_5 V_73 )
{
struct V_8 * V_9 = F_3 ( V_6 -> V_10 ) ;
unsigned int V_74 = V_6 -> V_10 -> V_75 ;
struct V_12 V_13 ;
T_6 V_76 ;
int V_63 = 0 ;
int V_14 ;
V_76 = ( T_6 )
( ( V_73 + V_74 - 1 ) >> ( V_9 -> V_77 ) ) ;
F_6 ( V_9 , V_78 ) ;
F_7 ( & V_13 , V_6 , NULL , NULL , 0 ) ;
V_14 = F_8 ( & V_13 , V_76 , V_79 ) ;
if ( V_14 ) {
if ( V_14 == - V_80 )
goto V_81;
F_9 ( V_9 , V_78 ) ;
return V_14 ;
}
if ( F_63 ( V_13 . V_70 ) )
V_63 = V_82 ;
else
V_63 = V_72 ;
V_63 -= V_13 . V_66 ;
F_64 ( V_63 < 0 ) ;
if ( V_13 . V_66 || F_63 ( V_13 . V_70 ) ) {
F_48 ( & V_13 , V_63 ) ;
V_76 += V_63 ;
}
F_11 ( & V_13 ) ;
V_81:
V_14 = F_65 ( V_6 , V_76 ) ;
F_9 ( V_9 , V_78 ) ;
F_57 ( V_6 , V_73 ) ;
return V_14 ;
}
void F_66 ( struct V_6 * V_6 )
{
if ( ! ( F_38 ( V_6 -> V_57 ) || F_67 ( V_6 -> V_57 ) ||
F_68 ( V_6 -> V_57 ) ) )
return;
if ( ! F_62 ( V_6 , F_14 ( V_6 ) ) ) {
V_6 -> V_83 = V_6 -> V_84 = V_85 ;
F_69 ( V_6 ) ;
}
}
static int F_70 ( struct V_86 * V_87 ,
struct V_27 * V_27 , struct V_88 * V_89 )
{
struct V_6 * V_6 = V_27 -> V_30 ;
F_71 ( V_6 , V_89 ) ;
V_89 -> V_90 <<= 3 ;
return 0 ;
}
static void F_72 ( struct V_6 * V_6 , const struct V_91 * V_92 )
{
struct V_93 * V_94 = F_37 ( V_6 ) ;
unsigned int V_95 = V_92 -> V_95 ;
if ( V_95 & V_96 )
V_6 -> V_97 = V_92 -> V_98 ;
if ( V_95 & V_99 )
V_6 -> V_100 = V_92 -> V_101 ;
if ( V_95 & V_102 )
V_6 -> V_103 = F_73 ( V_92 -> V_104 ,
V_6 -> V_10 -> V_105 ) ;
if ( V_95 & V_106 )
V_6 -> V_83 = F_73 ( V_92 -> V_107 ,
V_6 -> V_10 -> V_105 ) ;
if ( V_95 & V_108 )
V_6 -> V_84 = F_73 ( V_92 -> V_109 ,
V_6 -> V_10 -> V_105 ) ;
if ( V_95 & V_110 ) {
T_7 V_111 = V_92 -> V_112 ;
if ( ! F_74 ( V_6 -> V_100 ) && ! F_75 ( V_113 ) )
V_111 &= ~ V_114 ;
F_76 ( V_94 , V_111 ) ;
}
}
int F_77 ( struct V_27 * V_27 , struct V_91 * V_92 )
{
struct V_6 * V_6 = V_27 -> V_30 ;
struct V_93 * V_94 = F_37 ( V_6 ) ;
int V_14 ;
V_14 = F_78 ( V_6 , V_92 ) ;
if ( V_14 )
return V_14 ;
if ( ( V_92 -> V_95 & V_115 ) &&
V_92 -> V_116 != F_14 ( V_6 ) ) {
F_79 ( V_6 , V_92 -> V_116 ) ;
F_66 ( V_6 ) ;
F_4 ( F_3 ( V_6 -> V_10 ) ) ;
}
F_72 ( V_6 , V_92 ) ;
if ( V_92 -> V_95 & V_110 ) {
V_14 = F_80 ( V_6 ) ;
if ( V_14 || F_39 ( V_94 , V_117 ) ) {
V_6 -> V_57 = V_94 -> V_118 ;
F_42 ( V_94 , V_117 ) ;
}
}
F_69 ( V_6 ) ;
return V_14 ;
}
static void F_81 ( struct V_6 * V_6 , T_6 V_16 ,
T_3 V_33 , T_3 V_119 )
{
struct V_8 * V_9 = F_3 ( V_6 -> V_10 ) ;
struct V_5 * V_5 ;
if ( ! V_119 )
return;
F_4 ( V_9 ) ;
F_6 ( V_9 , V_15 ) ;
V_5 = F_82 ( V_6 , V_16 , false ) ;
F_9 ( V_9 , V_15 ) ;
if ( ! F_59 ( V_5 ) ) {
F_18 ( V_5 ) ;
F_60 ( V_5 , V_33 , V_119 ) ;
F_20 ( V_5 ) ;
F_61 ( V_5 , 1 ) ;
}
}
int F_83 ( struct V_6 * V_6 , T_6 V_120 , T_6 V_121 )
{
T_6 V_16 ;
int V_14 ;
for ( V_16 = V_120 ; V_16 < V_121 ; V_16 ++ ) {
struct V_12 V_13 ;
struct V_8 * V_9 = F_3 ( V_6 -> V_10 ) ;
F_4 ( V_9 ) ;
F_6 ( V_9 , V_78 ) ;
F_7 ( & V_13 , V_6 , NULL , NULL , 0 ) ;
V_14 = F_8 ( & V_13 , V_16 , V_79 ) ;
if ( V_14 ) {
F_9 ( V_9 , V_78 ) ;
if ( V_14 == - V_80 )
continue;
return V_14 ;
}
if ( V_13 . V_18 != V_19 )
F_48 ( & V_13 , 1 ) ;
F_11 ( & V_13 ) ;
F_9 ( V_9 , V_78 ) ;
}
return 0 ;
}
static int F_84 ( struct V_6 * V_6 , T_3 V_24 , T_3 V_119 , int V_111 )
{
T_6 V_120 , V_121 ;
T_3 V_122 , V_123 ;
int V_39 = 0 ;
V_120 = ( ( unsigned long long ) V_24 ) >> V_23 ;
V_121 = ( ( unsigned long long ) V_24 + V_119 ) >> V_23 ;
V_122 = V_24 & ( V_26 - 1 ) ;
V_123 = ( V_24 + V_119 ) & ( V_26 - 1 ) ;
if ( V_120 == V_121 ) {
F_81 ( V_6 , V_120 , V_122 ,
V_123 - V_122 ) ;
} else {
if ( V_122 )
F_81 ( V_6 , V_120 ++ , V_122 ,
V_26 - V_122 ) ;
if ( V_123 )
F_81 ( V_6 , V_121 , 0 , V_123 ) ;
if ( V_120 < V_121 ) {
struct V_124 * V_20 = V_6 -> V_21 ;
T_3 V_125 , V_126 ;
V_125 = V_120 << V_23 ;
V_126 = V_121 << V_23 ;
F_85 ( V_20 , V_125 ,
V_126 - 1 ) ;
V_39 = F_83 ( V_6 , V_120 , V_121 ) ;
}
}
if ( ! ( V_111 & V_127 ) &&
F_14 ( V_6 ) <= ( V_24 + V_119 ) ) {
F_86 ( V_6 , V_24 ) ;
F_69 ( V_6 ) ;
}
return V_39 ;
}
static int F_87 ( struct V_6 * V_6 , T_3 V_24 ,
T_3 V_119 , int V_111 )
{
struct V_8 * V_9 = F_3 ( V_6 -> V_10 ) ;
T_6 V_16 , V_120 , V_121 ;
T_3 V_128 = F_14 ( V_6 ) ;
T_3 V_122 , V_123 ;
int V_39 = 0 ;
V_39 = F_88 ( V_6 , ( V_119 + V_24 ) ) ;
if ( V_39 )
return V_39 ;
V_120 = ( ( unsigned long long ) V_24 ) >> V_23 ;
V_121 = ( ( unsigned long long ) V_24 + V_119 ) >> V_23 ;
V_122 = V_24 & ( V_26 - 1 ) ;
V_123 = ( V_24 + V_119 ) & ( V_26 - 1 ) ;
for ( V_16 = V_120 ; V_16 <= V_121 ; V_16 ++ ) {
struct V_12 V_13 ;
F_6 ( V_9 , V_15 ) ;
F_7 ( & V_13 , V_6 , NULL , NULL , 0 ) ;
V_39 = F_8 ( & V_13 , V_16 , 0 ) ;
if ( V_39 ) {
F_9 ( V_9 , V_15 ) ;
break;
}
if ( V_13 . V_18 == V_19 ) {
V_39 = F_10 ( & V_13 ) ;
if ( V_39 ) {
F_11 ( & V_13 ) ;
F_9 ( V_9 , V_15 ) ;
break;
}
}
F_11 ( & V_13 ) ;
F_9 ( V_9 , V_15 ) ;
if ( V_120 == V_121 )
V_128 = V_24 + V_119 ;
else if ( V_16 == V_120 && V_122 )
V_128 = ( V_16 + 1 ) << V_23 ;
else if ( V_16 == V_121 )
V_128 = ( V_16 << V_23 ) + V_123 ;
else
V_128 += V_26 ;
}
if ( ! ( V_111 & V_127 ) &&
F_14 ( V_6 ) < V_128 ) {
F_86 ( V_6 , V_128 ) ;
F_69 ( V_6 ) ;
}
return V_39 ;
}
static long F_89 ( struct V_32 * V_32 , int V_111 ,
T_3 V_24 , T_3 V_119 )
{
struct V_6 * V_6 = F_2 ( V_32 ) ;
long V_39 ;
if ( V_111 & ~ ( V_127 | V_129 ) )
return - V_130 ;
if ( V_111 & V_129 )
V_39 = F_84 ( V_6 , V_24 , V_119 , V_111 ) ;
else
V_39 = F_87 ( V_6 , V_24 , V_119 , V_111 ) ;
if ( ! V_39 ) {
V_6 -> V_83 = V_6 -> V_84 = V_85 ;
F_69 ( V_6 ) ;
}
return V_39 ;
}
static inline T_8 F_90 ( T_7 V_111 , T_8 V_131 )
{
if ( F_67 ( V_111 ) )
return V_131 ;
else if ( F_38 ( V_111 ) )
return V_131 & V_132 ;
else
return V_131 & V_133 ;
}
long F_91 ( struct V_32 * V_134 , unsigned int V_135 , unsigned long V_136 )
{
struct V_6 * V_6 = F_2 ( V_134 ) ;
struct V_93 * V_94 = F_37 ( V_6 ) ;
unsigned int V_131 ;
int V_39 ;
switch ( V_135 ) {
case V_137 :
V_131 = V_94 -> V_138 & V_139 ;
return F_92 ( V_131 , ( int V_140 * ) V_136 ) ;
case V_141 :
{
unsigned int V_142 ;
V_39 = F_93 ( V_134 -> V_143 . V_87 ) ;
if ( V_39 )
return V_39 ;
if ( ! F_94 ( V_6 ) ) {
V_39 = - V_144 ;
goto V_17;
}
if ( F_95 ( V_131 , ( int V_140 * ) V_136 ) ) {
V_39 = - V_22 ;
goto V_17;
}
V_131 = F_90 ( V_6 -> V_57 , V_131 ) ;
F_33 ( & V_6 -> V_50 ) ;
V_142 = V_94 -> V_138 ;
if ( ( V_131 ^ V_142 ) & ( V_145 | V_146 ) ) {
if ( ! F_75 ( V_147 ) ) {
F_36 ( & V_6 -> V_50 ) ;
V_39 = - V_148 ;
goto V_17;
}
}
V_131 = V_131 & V_149 ;
V_131 |= V_142 & ~ V_149 ;
V_94 -> V_138 = V_131 ;
F_36 ( & V_6 -> V_50 ) ;
F_96 ( V_6 ) ;
V_6 -> V_84 = V_85 ;
F_69 ( V_6 ) ;
V_17:
F_97 ( V_134 -> V_143 . V_87 ) ;
return V_39 ;
}
default:
return - V_150 ;
}
}
long F_98 ( struct V_32 * V_32 , unsigned int V_135 , unsigned long V_136 )
{
switch ( V_135 ) {
case V_151 :
V_135 = V_152 ;
break;
case V_153 :
V_135 = V_154 ;
break;
default:
return - V_155 ;
}
return F_91 ( V_32 , V_135 , ( unsigned long ) F_99 ( V_136 ) ) ;
}
