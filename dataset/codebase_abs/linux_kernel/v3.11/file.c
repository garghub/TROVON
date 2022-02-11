static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_5 = V_4 -> V_5 ;
struct V_6 * V_6 = F_2 ( V_2 -> V_7 ) ;
struct V_8 * V_9 = F_3 ( V_6 -> V_10 ) ;
T_1 V_11 ;
struct V_12 V_13 ;
int V_14 , V_15 ;
F_4 ( V_9 ) ;
F_5 ( V_6 -> V_10 ) ;
V_15 = F_6 ( V_9 ) ;
F_7 ( & V_13 , V_6 , NULL , NULL , 0 ) ;
V_14 = F_8 ( & V_13 , V_5 -> V_16 , V_17 ) ;
if ( V_14 ) {
F_9 ( V_9 , V_15 ) ;
goto V_18;
}
V_11 = V_13 . V_19 ;
if ( V_11 == V_20 ) {
V_14 = F_10 ( & V_13 ) ;
if ( V_14 ) {
F_11 ( & V_13 ) ;
F_9 ( V_9 , V_15 ) ;
goto V_18;
}
}
F_11 ( & V_13 ) ;
F_9 ( V_9 , V_15 ) ;
F_12 ( V_2 -> V_7 ) ;
F_13 ( V_5 ) ;
if ( V_5 -> V_21 != V_6 -> V_22 ||
F_14 ( V_5 ) > F_15 ( V_6 ) ||
! F_16 ( V_5 ) ) {
F_17 ( V_5 ) ;
V_14 = - V_23 ;
goto V_18;
}
if ( F_18 ( V_5 ) )
goto V_24;
if ( ( ( V_5 -> V_16 + 1 ) << V_25 ) > F_15 ( V_6 ) ) {
unsigned V_26 ;
V_26 = F_15 ( V_6 ) & ~ V_27 ;
F_19 ( V_5 , V_26 , V_28 ) ;
}
F_20 ( V_5 ) ;
F_21 ( V_5 ) ;
V_24:
F_22 ( V_5 ) ;
V_18:
F_23 ( V_6 -> V_10 ) ;
return F_24 ( V_14 ) ;
}
static int F_25 ( struct V_6 * V_6 , T_2 * V_29 )
{
struct V_30 * V_30 ;
V_6 = F_26 ( V_6 ) ;
V_30 = F_27 ( V_6 ) ;
F_28 ( V_6 ) ;
if ( ! V_30 )
return 0 ;
V_6 = F_26 ( V_30 -> V_31 -> V_32 ) ;
F_29 ( V_30 ) ;
* V_29 = V_6 -> V_33 ;
F_28 ( V_6 ) ;
return 1 ;
}
int F_30 ( struct V_34 * V_34 , T_3 V_35 , T_3 V_36 , int V_37 )
{
struct V_6 * V_6 = V_34 -> V_38 -> V_39 ;
struct V_8 * V_9 = F_3 ( V_6 -> V_10 ) ;
int V_40 = 0 ;
bool V_41 = false ;
struct V_42 V_43 = {
. V_44 = V_45 ,
. V_46 = V_47 ,
. V_48 = 0 ,
} ;
if ( F_31 ( V_6 -> V_10 ) )
return 0 ;
F_32 ( V_6 ) ;
V_40 = F_33 ( V_6 -> V_22 , V_35 , V_36 ) ;
if ( V_40 ) {
F_34 ( V_6 , V_41 , V_37 , V_40 ) ;
return V_40 ;
}
F_4 ( V_9 ) ;
F_35 ( & V_6 -> V_49 ) ;
if ( V_37 && ! ( V_6 -> V_50 & V_51 ) )
goto V_18;
if ( ! F_36 ( V_6 -> V_52 ) || V_6 -> V_53 != 1 )
V_41 = true ;
else if ( F_37 ( V_6 ) )
V_41 = true ;
else if ( ! F_38 ( V_9 ) )
V_41 = true ;
else if ( ! F_39 ( V_9 , F_40 ( V_6 ) -> V_54 ) )
V_41 = true ;
if ( V_41 ) {
T_2 V_29 ;
V_40 = F_41 ( V_6 -> V_10 , 1 ) ;
if ( F_37 ( V_6 ) && V_6 -> V_53 == 1 &&
F_25 ( V_6 , & V_29 ) ) {
F_40 ( V_6 ) -> V_54 = V_29 ;
F_42 ( V_6 ) ;
F_43 ( V_6 ) ;
V_40 = F_44 ( V_6 , NULL ) ;
if ( V_40 )
goto V_18;
}
} else {
while ( ! F_45 ( V_9 , V_6 -> V_33 , & V_43 ) ) {
F_43 ( V_6 ) ;
V_40 = F_44 ( V_6 , NULL ) ;
if ( V_40 )
goto V_18;
}
F_46 ( V_9 -> V_55 -> V_22 ,
0 , V_47 ) ;
V_40 = F_47 ( V_6 -> V_10 -> V_56 , V_57 , NULL ) ;
}
V_18:
F_48 ( & V_6 -> V_49 ) ;
F_34 ( V_6 , V_41 , V_37 , V_40 ) ;
return V_40 ;
}
static int F_49 ( struct V_34 * V_34 , struct V_1 * V_2 )
{
F_50 ( V_34 ) ;
V_2 -> V_58 = & V_59 ;
return 0 ;
}
int F_51 ( struct V_12 * V_13 , int V_60 )
{
int V_61 = 0 , V_62 = V_13 -> V_63 ;
struct V_8 * V_9 = F_3 ( V_13 -> V_6 -> V_10 ) ;
struct V_64 * V_65 ;
T_4 * V_66 ;
V_65 = F_52 ( V_13 -> V_67 ) ;
V_66 = F_53 ( V_65 ) + V_62 ;
for ( ; V_60 > 0 ; V_60 -- , V_66 ++ , V_13 -> V_63 ++ ) {
T_1 V_68 = F_54 ( * V_66 ) ;
if ( V_68 == V_20 )
continue;
F_55 ( V_20 , V_13 ) ;
F_56 ( V_9 , V_68 ) ;
V_61 ++ ;
}
if ( V_61 ) {
F_57 ( V_9 , V_13 -> V_6 , V_61 ) ;
F_20 ( V_13 -> V_67 ) ;
F_58 ( V_13 ) ;
}
V_13 -> V_63 = V_62 ;
F_59 ( V_13 -> V_6 , V_13 -> V_69 ,
V_13 -> V_63 , V_61 ) ;
return V_61 ;
}
void F_60 ( struct V_12 * V_13 )
{
F_51 ( V_13 , V_70 ) ;
}
static void F_61 ( struct V_6 * V_6 , T_5 V_71 )
{
unsigned V_26 = V_71 & ( V_28 - 1 ) ;
struct V_5 * V_5 ;
if ( ! V_26 )
return;
V_5 = F_62 ( V_6 , V_71 >> V_25 , false ) ;
if ( F_63 ( V_5 ) )
return;
F_13 ( V_5 ) ;
if ( V_5 -> V_21 != V_6 -> V_22 ) {
F_64 ( V_5 , 1 ) ;
return;
}
F_22 ( V_5 ) ;
F_65 ( V_5 , V_26 , V_28 - V_26 ) ;
F_20 ( V_5 ) ;
F_64 ( V_5 , 1 ) ;
}
static int F_66 ( struct V_6 * V_6 , T_5 V_71 )
{
struct V_8 * V_9 = F_3 ( V_6 -> V_10 ) ;
unsigned int V_72 = V_6 -> V_10 -> V_73 ;
struct V_12 V_13 ;
T_6 V_74 ;
int V_60 = 0 , V_15 = - 1 ;
int V_14 ;
F_67 ( V_6 , V_71 ) ;
V_74 = ( T_6 )
( ( V_71 + V_72 - 1 ) >> ( V_9 -> V_75 ) ) ;
V_15 = F_6 ( V_9 ) ;
F_7 ( & V_13 , V_6 , NULL , NULL , 0 ) ;
V_14 = F_8 ( & V_13 , V_74 , V_76 ) ;
if ( V_14 ) {
if ( V_14 == - V_77 )
goto V_78;
F_9 ( V_9 , V_15 ) ;
F_68 ( V_6 , V_14 ) ;
return V_14 ;
}
if ( F_69 ( V_13 . V_67 ) )
V_60 = V_79 ;
else
V_60 = V_70 ;
V_60 -= V_13 . V_63 ;
F_70 ( V_60 < 0 ) ;
if ( V_13 . V_63 || F_69 ( V_13 . V_67 ) ) {
F_51 ( & V_13 , V_60 ) ;
V_74 += V_60 ;
}
F_11 ( & V_13 ) ;
V_78:
V_14 = F_71 ( V_6 , V_74 ) ;
F_9 ( V_9 , V_15 ) ;
F_61 ( V_6 , V_71 ) ;
F_68 ( V_6 , V_14 ) ;
return V_14 ;
}
void F_72 ( struct V_6 * V_6 )
{
if ( ! ( F_36 ( V_6 -> V_52 ) || F_73 ( V_6 -> V_52 ) ||
F_74 ( V_6 -> V_52 ) ) )
return;
F_75 ( V_6 ) ;
if ( ! F_66 ( V_6 , F_15 ( V_6 ) ) ) {
V_6 -> V_80 = V_6 -> V_81 = V_82 ;
F_76 ( V_6 ) ;
}
}
int F_77 ( struct V_83 * V_84 ,
struct V_30 * V_30 , struct V_85 * V_86 )
{
struct V_6 * V_6 = V_30 -> V_32 ;
F_78 ( V_6 , V_86 ) ;
V_86 -> V_87 <<= 3 ;
return 0 ;
}
static void F_79 ( struct V_6 * V_6 , const struct V_88 * V_89 )
{
struct V_90 * V_91 = F_40 ( V_6 ) ;
unsigned int V_92 = V_89 -> V_92 ;
if ( V_92 & V_93 )
V_6 -> V_94 = V_89 -> V_95 ;
if ( V_92 & V_96 )
V_6 -> V_97 = V_89 -> V_98 ;
if ( V_92 & V_99 )
V_6 -> V_100 = F_80 ( V_89 -> V_101 ,
V_6 -> V_10 -> V_102 ) ;
if ( V_92 & V_103 )
V_6 -> V_80 = F_80 ( V_89 -> V_104 ,
V_6 -> V_10 -> V_102 ) ;
if ( V_92 & V_105 )
V_6 -> V_81 = F_80 ( V_89 -> V_106 ,
V_6 -> V_10 -> V_102 ) ;
if ( V_92 & V_107 ) {
T_7 V_108 = V_89 -> V_109 ;
if ( ! F_81 ( V_6 -> V_97 ) && ! F_82 ( V_110 ) )
V_108 &= ~ V_111 ;
F_83 ( V_91 , V_108 ) ;
}
}
int F_84 ( struct V_30 * V_30 , struct V_88 * V_89 )
{
struct V_6 * V_6 = V_30 -> V_32 ;
struct V_90 * V_91 = F_40 ( V_6 ) ;
int V_14 ;
V_14 = F_85 ( V_6 , V_89 ) ;
if ( V_14 )
return V_14 ;
if ( ( V_89 -> V_92 & V_112 ) &&
V_89 -> V_113 != F_15 ( V_6 ) ) {
F_86 ( V_6 , V_89 -> V_113 ) ;
F_72 ( V_6 ) ;
F_4 ( F_3 ( V_6 -> V_10 ) ) ;
}
F_79 ( V_6 , V_89 ) ;
if ( V_89 -> V_92 & V_107 ) {
V_14 = F_87 ( V_6 ) ;
if ( V_14 || F_88 ( V_91 , V_114 ) ) {
V_6 -> V_52 = V_91 -> V_115 ;
F_89 ( V_91 , V_114 ) ;
}
}
F_76 ( V_6 ) ;
return V_14 ;
}
static void F_90 ( struct V_6 * V_6 , T_6 V_16 ,
T_3 V_35 , T_3 V_116 )
{
struct V_8 * V_9 = F_3 ( V_6 -> V_10 ) ;
struct V_5 * V_5 ;
int V_15 ;
if ( ! V_116 )
return;
F_4 ( V_9 ) ;
V_15 = F_6 ( V_9 ) ;
V_5 = F_91 ( V_6 , NULL , V_16 , false ) ;
F_9 ( V_9 , V_15 ) ;
if ( ! F_63 ( V_5 ) ) {
F_22 ( V_5 ) ;
F_65 ( V_5 , V_35 , V_116 ) ;
F_20 ( V_5 ) ;
F_64 ( V_5 , 1 ) ;
}
}
int F_92 ( struct V_6 * V_6 , T_6 V_117 , T_6 V_118 )
{
T_6 V_16 ;
int V_14 ;
for ( V_16 = V_117 ; V_16 < V_118 ; V_16 ++ ) {
struct V_12 V_13 ;
F_7 ( & V_13 , V_6 , NULL , NULL , 0 ) ;
V_14 = F_8 ( & V_13 , V_16 , V_76 ) ;
if ( V_14 ) {
if ( V_14 == - V_77 )
continue;
return V_14 ;
}
if ( V_13 . V_19 != V_20 )
F_51 ( & V_13 , 1 ) ;
F_11 ( & V_13 ) ;
}
return 0 ;
}
static int F_93 ( struct V_6 * V_6 , T_3 V_26 , T_3 V_116 , int V_108 )
{
T_6 V_117 , V_118 ;
T_3 V_119 , V_120 ;
int V_40 = 0 ;
V_117 = ( ( unsigned long long ) V_26 ) >> V_25 ;
V_118 = ( ( unsigned long long ) V_26 + V_116 ) >> V_25 ;
V_119 = V_26 & ( V_28 - 1 ) ;
V_120 = ( V_26 + V_116 ) & ( V_28 - 1 ) ;
if ( V_117 == V_118 ) {
F_90 ( V_6 , V_117 , V_119 ,
V_120 - V_119 ) ;
} else {
if ( V_119 )
F_90 ( V_6 , V_117 ++ , V_119 ,
V_28 - V_119 ) ;
if ( V_120 )
F_90 ( V_6 , V_118 , 0 , V_120 ) ;
if ( V_117 < V_118 ) {
struct V_121 * V_21 = V_6 -> V_22 ;
T_3 V_122 , V_123 ;
struct V_8 * V_9 = F_3 ( V_6 -> V_10 ) ;
int V_15 ;
F_4 ( V_9 ) ;
V_122 = V_117 << V_25 ;
V_123 = V_118 << V_25 ;
F_94 ( V_21 , V_122 ,
V_123 - 1 ) ;
V_15 = F_6 ( V_9 ) ;
V_40 = F_92 ( V_6 , V_117 , V_118 ) ;
F_9 ( V_9 , V_15 ) ;
}
}
if ( ! ( V_108 & V_124 ) &&
F_15 ( V_6 ) <= ( V_26 + V_116 ) ) {
F_95 ( V_6 , V_26 ) ;
F_76 ( V_6 ) ;
}
return V_40 ;
}
static int F_96 ( struct V_6 * V_6 , T_3 V_26 ,
T_3 V_116 , int V_108 )
{
struct V_8 * V_9 = F_3 ( V_6 -> V_10 ) ;
T_6 V_16 , V_117 , V_118 ;
T_3 V_125 = F_15 ( V_6 ) ;
T_3 V_119 , V_120 ;
int V_40 = 0 ;
V_40 = F_97 ( V_6 , ( V_116 + V_26 ) ) ;
if ( V_40 )
return V_40 ;
V_117 = ( ( unsigned long long ) V_26 ) >> V_25 ;
V_118 = ( ( unsigned long long ) V_26 + V_116 ) >> V_25 ;
V_119 = V_26 & ( V_28 - 1 ) ;
V_120 = ( V_26 + V_116 ) & ( V_28 - 1 ) ;
for ( V_16 = V_117 ; V_16 <= V_118 ; V_16 ++ ) {
struct V_12 V_13 ;
int V_15 ;
V_15 = F_6 ( V_9 ) ;
F_7 ( & V_13 , V_6 , NULL , NULL , 0 ) ;
V_40 = F_8 ( & V_13 , V_16 , V_17 ) ;
if ( V_40 ) {
F_9 ( V_9 , V_15 ) ;
break;
}
if ( V_13 . V_19 == V_20 ) {
V_40 = F_10 ( & V_13 ) ;
if ( V_40 ) {
F_11 ( & V_13 ) ;
F_9 ( V_9 , V_15 ) ;
break;
}
}
F_11 ( & V_13 ) ;
F_9 ( V_9 , V_15 ) ;
if ( V_117 == V_118 )
V_125 = V_26 + V_116 ;
else if ( V_16 == V_117 && V_119 )
V_125 = ( V_16 + 1 ) << V_25 ;
else if ( V_16 == V_118 )
V_125 = ( V_16 << V_25 ) + V_120 ;
else
V_125 += V_28 ;
}
if ( ! ( V_108 & V_124 ) &&
F_15 ( V_6 ) < V_125 ) {
F_95 ( V_6 , V_125 ) ;
F_76 ( V_6 ) ;
}
return V_40 ;
}
static long F_98 ( struct V_34 * V_34 , int V_108 ,
T_3 V_26 , T_3 V_116 )
{
struct V_6 * V_6 = F_2 ( V_34 ) ;
long V_40 ;
if ( V_108 & ~ ( V_124 | V_126 ) )
return - V_127 ;
if ( V_108 & V_126 )
V_40 = F_93 ( V_6 , V_26 , V_116 , V_108 ) ;
else
V_40 = F_96 ( V_6 , V_26 , V_116 , V_108 ) ;
if ( ! V_40 ) {
V_6 -> V_80 = V_6 -> V_81 = V_82 ;
F_76 ( V_6 ) ;
}
F_99 ( V_6 , V_108 , V_26 , V_116 , V_40 ) ;
return V_40 ;
}
static inline T_8 F_100 ( T_7 V_108 , T_8 V_128 )
{
if ( F_73 ( V_108 ) )
return V_128 ;
else if ( F_36 ( V_108 ) )
return V_128 & V_129 ;
else
return V_128 & V_130 ;
}
long F_101 ( struct V_34 * V_131 , unsigned int V_132 , unsigned long V_133 )
{
struct V_6 * V_6 = F_2 ( V_131 ) ;
struct V_90 * V_91 = F_40 ( V_6 ) ;
unsigned int V_128 ;
int V_40 ;
switch ( V_132 ) {
case V_134 :
V_128 = V_91 -> V_135 & V_136 ;
return F_102 ( V_128 , ( int V_137 * ) V_133 ) ;
case V_138 :
{
unsigned int V_139 ;
V_40 = F_103 ( V_131 ) ;
if ( V_40 )
return V_40 ;
if ( ! F_104 ( V_6 ) ) {
V_40 = - V_140 ;
goto V_18;
}
if ( F_105 ( V_128 , ( int V_137 * ) V_133 ) ) {
V_40 = - V_23 ;
goto V_18;
}
V_128 = F_100 ( V_6 -> V_52 , V_128 ) ;
F_35 ( & V_6 -> V_49 ) ;
V_139 = V_91 -> V_135 ;
if ( ( V_128 ^ V_139 ) & ( V_141 | V_142 ) ) {
if ( ! F_82 ( V_143 ) ) {
F_48 ( & V_6 -> V_49 ) ;
V_40 = - V_144 ;
goto V_18;
}
}
V_128 = V_128 & V_145 ;
V_128 |= V_139 & ~ V_145 ;
V_91 -> V_135 = V_128 ;
F_48 ( & V_6 -> V_49 ) ;
F_106 ( V_6 ) ;
V_6 -> V_81 = V_82 ;
F_76 ( V_6 ) ;
V_18:
F_107 ( V_131 ) ;
return V_40 ;
}
default:
return - V_146 ;
}
}
long F_108 ( struct V_34 * V_34 , unsigned int V_132 , unsigned long V_133 )
{
switch ( V_132 ) {
case V_147 :
V_132 = V_134 ;
break;
case V_148 :
V_132 = V_138 ;
break;
default:
return - V_149 ;
}
return F_101 ( V_34 , V_132 , ( unsigned long ) F_109 ( V_133 ) ) ;
}
