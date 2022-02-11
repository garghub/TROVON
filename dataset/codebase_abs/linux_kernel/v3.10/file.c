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
F_12 ( V_5 ) ;
if ( V_5 -> V_21 != V_6 -> V_22 ||
F_13 ( V_5 ) >= F_14 ( V_6 ) ||
! F_15 ( V_5 ) ) {
F_16 ( V_5 ) ;
V_14 = - V_23 ;
goto V_18;
}
if ( F_17 ( V_5 ) )
goto V_18;
F_18 ( V_5 ) ;
if ( ( ( V_5 -> V_16 + 1 ) << V_24 ) > F_14 ( V_6 ) ) {
unsigned V_25 ;
V_25 = F_14 ( V_6 ) & ~ V_26 ;
F_19 ( V_5 , V_25 , V_27 ) ;
}
F_20 ( V_5 ) ;
F_21 ( V_5 ) ;
F_22 ( V_2 -> V_7 ) ;
V_18:
F_23 ( V_6 -> V_10 ) ;
return F_24 ( V_14 ) ;
}
int F_25 ( struct V_28 * V_28 , T_2 V_29 , T_2 V_30 , int V_31 )
{
struct V_6 * V_6 = V_28 -> V_32 -> V_33 ;
struct V_8 * V_9 = F_3 ( V_6 -> V_10 ) ;
int V_34 = 0 ;
bool V_35 = false ;
struct V_36 V_37 = {
. V_38 = V_39 ,
. V_40 = V_41 ,
. V_42 = 0 ,
} ;
if ( V_6 -> V_10 -> V_43 & V_44 )
return 0 ;
F_26 ( V_6 ) ;
V_34 = F_27 ( V_6 -> V_22 , V_29 , V_30 ) ;
if ( V_34 ) {
F_28 ( V_6 , V_35 , V_31 , V_34 ) ;
return V_34 ;
}
F_4 ( V_9 ) ;
F_29 ( & V_6 -> V_45 ) ;
if ( V_31 && ! ( V_6 -> V_46 & V_47 ) )
goto V_18;
if ( ! F_30 ( V_6 -> V_48 ) || V_6 -> V_49 != 1 )
V_35 = true ;
else if ( F_31 ( V_6 ) )
V_35 = true ;
else if ( ! F_32 ( V_9 ) )
V_35 = true ;
else if ( ! F_33 ( V_9 , F_34 ( V_6 ) -> V_50 ) )
V_35 = true ;
if ( V_35 ) {
V_34 = F_35 ( V_6 -> V_10 , 1 ) ;
} else {
while ( ! F_36 ( V_9 , V_6 -> V_51 , & V_37 ) ) {
V_34 = F_37 ( V_6 , NULL ) ;
if ( V_34 )
goto V_18;
}
F_38 ( V_9 -> V_52 -> V_22 ,
0 , V_41 ) ;
V_34 = F_39 ( V_6 -> V_10 -> V_53 , V_54 , NULL ) ;
}
V_18:
F_40 ( & V_6 -> V_45 ) ;
F_28 ( V_6 , V_35 , V_31 , V_34 ) ;
return V_34 ;
}
static int F_41 ( struct V_28 * V_28 , struct V_1 * V_2 )
{
F_42 ( V_28 ) ;
V_2 -> V_55 = & V_56 ;
return 0 ;
}
static int F_43 ( struct V_12 * V_13 , int V_57 )
{
int V_58 = 0 , V_59 = V_13 -> V_60 ;
struct V_8 * V_9 = F_3 ( V_13 -> V_6 -> V_10 ) ;
struct V_61 * V_62 ;
T_3 * V_63 ;
V_62 = F_44 ( V_13 -> V_64 ) ;
V_63 = F_45 ( V_62 ) + V_59 ;
for ( ; V_57 > 0 ; V_57 -- , V_63 ++ , V_13 -> V_60 ++ ) {
T_1 V_65 = F_46 ( * V_63 ) ;
if ( V_65 == V_20 )
continue;
F_47 ( V_20 , V_13 ) ;
F_48 ( V_9 , V_65 ) ;
F_49 ( V_9 , V_13 -> V_6 , 1 ) ;
V_58 ++ ;
}
if ( V_58 ) {
F_20 ( V_13 -> V_64 ) ;
F_50 ( V_13 ) ;
}
V_13 -> V_60 = V_59 ;
F_51 ( V_13 -> V_6 , V_13 -> V_66 ,
V_13 -> V_60 , V_58 ) ;
return V_58 ;
}
void F_52 ( struct V_12 * V_13 )
{
F_43 ( V_13 , V_67 ) ;
}
static void F_53 ( struct V_6 * V_6 , T_4 V_68 )
{
unsigned V_25 = V_68 & ( V_27 - 1 ) ;
struct V_5 * V_5 ;
if ( ! V_25 )
return;
V_5 = F_54 ( V_6 , V_68 >> V_24 , false ) ;
if ( F_55 ( V_5 ) )
return;
F_12 ( V_5 ) ;
if ( V_5 -> V_21 != V_6 -> V_22 ) {
F_56 ( V_5 , 1 ) ;
return;
}
F_18 ( V_5 ) ;
F_57 ( V_5 , V_25 , V_27 - V_25 ) ;
F_20 ( V_5 ) ;
F_56 ( V_5 , 1 ) ;
}
static int F_58 ( struct V_6 * V_6 , T_4 V_68 )
{
struct V_8 * V_9 = F_3 ( V_6 -> V_10 ) ;
unsigned int V_69 = V_6 -> V_10 -> V_70 ;
struct V_12 V_13 ;
T_5 V_71 ;
int V_57 = 0 , V_15 = - 1 ;
int V_14 ;
F_59 ( V_6 , V_68 ) ;
V_71 = ( T_5 )
( ( V_68 + V_69 - 1 ) >> ( V_9 -> V_72 ) ) ;
V_15 = F_6 ( V_9 ) ;
F_7 ( & V_13 , V_6 , NULL , NULL , 0 ) ;
V_14 = F_8 ( & V_13 , V_71 , V_73 ) ;
if ( V_14 ) {
if ( V_14 == - V_74 )
goto V_75;
F_9 ( V_9 , V_15 ) ;
F_60 ( V_6 , V_14 ) ;
return V_14 ;
}
if ( F_61 ( V_13 . V_64 ) )
V_57 = V_76 ;
else
V_57 = V_67 ;
V_57 -= V_13 . V_60 ;
F_62 ( V_57 < 0 ) ;
if ( V_13 . V_60 || F_61 ( V_13 . V_64 ) ) {
F_43 ( & V_13 , V_57 ) ;
V_71 += V_57 ;
}
F_11 ( & V_13 ) ;
V_75:
V_14 = F_63 ( V_6 , V_71 ) ;
F_9 ( V_9 , V_15 ) ;
F_53 ( V_6 , V_68 ) ;
F_60 ( V_6 , V_14 ) ;
return V_14 ;
}
void F_64 ( struct V_6 * V_6 )
{
if ( ! ( F_30 ( V_6 -> V_48 ) || F_65 ( V_6 -> V_48 ) ||
F_66 ( V_6 -> V_48 ) ) )
return;
F_67 ( V_6 ) ;
if ( ! F_58 ( V_6 , F_14 ( V_6 ) ) ) {
V_6 -> V_77 = V_6 -> V_78 = V_79 ;
F_68 ( V_6 ) ;
}
}
static int F_69 ( struct V_80 * V_81 ,
struct V_82 * V_82 , struct V_83 * V_84 )
{
struct V_6 * V_6 = V_82 -> V_85 ;
F_70 ( V_6 , V_84 ) ;
V_84 -> V_86 <<= 3 ;
return 0 ;
}
static void F_71 ( struct V_6 * V_6 , const struct V_87 * V_88 )
{
struct V_89 * V_90 = F_34 ( V_6 ) ;
unsigned int V_91 = V_88 -> V_91 ;
if ( V_91 & V_92 )
V_6 -> V_93 = V_88 -> V_94 ;
if ( V_91 & V_95 )
V_6 -> V_96 = V_88 -> V_97 ;
if ( V_91 & V_98 )
V_6 -> V_99 = F_72 ( V_88 -> V_100 ,
V_6 -> V_10 -> V_101 ) ;
if ( V_91 & V_102 )
V_6 -> V_77 = F_72 ( V_88 -> V_103 ,
V_6 -> V_10 -> V_101 ) ;
if ( V_91 & V_104 )
V_6 -> V_78 = F_72 ( V_88 -> V_105 ,
V_6 -> V_10 -> V_101 ) ;
if ( V_91 & V_106 ) {
T_6 V_107 = V_88 -> V_108 ;
if ( ! F_73 ( V_6 -> V_96 ) && ! F_74 ( V_109 ) )
V_107 &= ~ V_110 ;
F_75 ( V_90 , V_107 ) ;
}
}
int F_76 ( struct V_82 * V_82 , struct V_87 * V_88 )
{
struct V_6 * V_6 = V_82 -> V_85 ;
struct V_89 * V_90 = F_34 ( V_6 ) ;
int V_14 ;
V_14 = F_77 ( V_6 , V_88 ) ;
if ( V_14 )
return V_14 ;
if ( ( V_88 -> V_91 & V_111 ) &&
V_88 -> V_112 != F_14 ( V_6 ) ) {
F_78 ( V_6 , V_88 -> V_112 ) ;
F_64 ( V_6 ) ;
F_4 ( F_3 ( V_6 -> V_10 ) ) ;
}
F_71 ( V_6 , V_88 ) ;
if ( V_88 -> V_91 & V_106 ) {
V_14 = F_79 ( V_6 ) ;
if ( V_14 || F_80 ( V_90 , V_113 ) ) {
V_6 -> V_48 = V_90 -> V_114 ;
F_81 ( V_90 , V_113 ) ;
}
}
F_68 ( V_6 ) ;
return V_14 ;
}
static void F_82 ( struct V_6 * V_6 , T_5 V_16 ,
T_2 V_29 , T_2 V_115 )
{
struct V_8 * V_9 = F_3 ( V_6 -> V_10 ) ;
struct V_5 * V_5 ;
int V_15 ;
if ( ! V_115 )
return;
F_4 ( V_9 ) ;
V_15 = F_6 ( V_9 ) ;
V_5 = F_83 ( V_6 , V_16 , false ) ;
F_9 ( V_9 , V_15 ) ;
if ( ! F_55 ( V_5 ) ) {
F_18 ( V_5 ) ;
F_57 ( V_5 , V_29 , V_115 ) ;
F_20 ( V_5 ) ;
F_56 ( V_5 , 1 ) ;
}
}
int F_84 ( struct V_6 * V_6 , T_5 V_116 , T_5 V_117 )
{
T_5 V_16 ;
int V_14 ;
for ( V_16 = V_116 ; V_16 < V_117 ; V_16 ++ ) {
struct V_12 V_13 ;
F_7 ( & V_13 , V_6 , NULL , NULL , 0 ) ;
V_14 = F_8 ( & V_13 , V_16 , V_73 ) ;
if ( V_14 ) {
if ( V_14 == - V_74 )
continue;
return V_14 ;
}
if ( V_13 . V_19 != V_20 )
F_43 ( & V_13 , 1 ) ;
F_11 ( & V_13 ) ;
}
return 0 ;
}
static int F_85 ( struct V_6 * V_6 , T_2 V_25 , T_2 V_115 , int V_107 )
{
T_5 V_116 , V_117 ;
T_2 V_118 , V_119 ;
int V_34 = 0 ;
V_116 = ( ( unsigned long long ) V_25 ) >> V_24 ;
V_117 = ( ( unsigned long long ) V_25 + V_115 ) >> V_24 ;
V_118 = V_25 & ( V_27 - 1 ) ;
V_119 = ( V_25 + V_115 ) & ( V_27 - 1 ) ;
if ( V_116 == V_117 ) {
F_82 ( V_6 , V_116 , V_118 ,
V_119 - V_118 ) ;
} else {
if ( V_118 )
F_82 ( V_6 , V_116 ++ , V_118 ,
V_27 - V_118 ) ;
if ( V_119 )
F_82 ( V_6 , V_117 , 0 , V_119 ) ;
if ( V_116 < V_117 ) {
struct V_120 * V_21 = V_6 -> V_22 ;
T_2 V_121 , V_122 ;
struct V_8 * V_9 = F_3 ( V_6 -> V_10 ) ;
int V_15 ;
F_4 ( V_9 ) ;
V_121 = V_116 << V_24 ;
V_122 = V_117 << V_24 ;
F_86 ( V_21 , V_121 ,
V_122 - 1 ) ;
V_15 = F_6 ( V_9 ) ;
V_34 = F_84 ( V_6 , V_116 , V_117 ) ;
F_9 ( V_9 , V_15 ) ;
}
}
if ( ! ( V_107 & V_123 ) &&
F_14 ( V_6 ) <= ( V_25 + V_115 ) ) {
F_87 ( V_6 , V_25 ) ;
F_68 ( V_6 ) ;
}
return V_34 ;
}
static int F_88 ( struct V_6 * V_6 , T_2 V_25 ,
T_2 V_115 , int V_107 )
{
struct V_8 * V_9 = F_3 ( V_6 -> V_10 ) ;
T_5 V_16 , V_116 , V_117 ;
T_2 V_124 = F_14 ( V_6 ) ;
T_2 V_118 , V_119 ;
int V_34 = 0 ;
V_34 = F_89 ( V_6 , ( V_115 + V_25 ) ) ;
if ( V_34 )
return V_34 ;
V_116 = ( ( unsigned long long ) V_25 ) >> V_24 ;
V_117 = ( ( unsigned long long ) V_25 + V_115 ) >> V_24 ;
V_118 = V_25 & ( V_27 - 1 ) ;
V_119 = ( V_25 + V_115 ) & ( V_27 - 1 ) ;
for ( V_16 = V_116 ; V_16 <= V_117 ; V_16 ++ ) {
struct V_12 V_13 ;
int V_15 ;
V_15 = F_6 ( V_9 ) ;
F_7 ( & V_13 , V_6 , NULL , NULL , 0 ) ;
V_34 = F_8 ( & V_13 , V_16 , V_17 ) ;
if ( V_34 ) {
F_9 ( V_9 , V_15 ) ;
break;
}
if ( V_13 . V_19 == V_20 ) {
V_34 = F_10 ( & V_13 ) ;
if ( V_34 ) {
F_11 ( & V_13 ) ;
F_9 ( V_9 , V_15 ) ;
break;
}
}
F_11 ( & V_13 ) ;
F_9 ( V_9 , V_15 ) ;
if ( V_116 == V_117 )
V_124 = V_25 + V_115 ;
else if ( V_16 == V_116 && V_118 )
V_124 = ( V_16 + 1 ) << V_24 ;
else if ( V_16 == V_117 )
V_124 = ( V_16 << V_24 ) + V_119 ;
else
V_124 += V_27 ;
}
if ( ! ( V_107 & V_123 ) &&
F_14 ( V_6 ) < V_124 ) {
F_87 ( V_6 , V_124 ) ;
F_68 ( V_6 ) ;
}
return V_34 ;
}
static long F_90 ( struct V_28 * V_28 , int V_107 ,
T_2 V_25 , T_2 V_115 )
{
struct V_6 * V_6 = F_2 ( V_28 ) ;
long V_34 ;
if ( V_107 & ~ ( V_123 | V_125 ) )
return - V_126 ;
if ( V_107 & V_125 )
V_34 = F_85 ( V_6 , V_25 , V_115 , V_107 ) ;
else
V_34 = F_88 ( V_6 , V_25 , V_115 , V_107 ) ;
if ( ! V_34 ) {
V_6 -> V_77 = V_6 -> V_78 = V_79 ;
F_68 ( V_6 ) ;
}
F_91 ( V_6 , V_107 , V_25 , V_115 , V_34 ) ;
return V_34 ;
}
static inline T_7 F_92 ( T_6 V_107 , T_7 V_127 )
{
if ( F_65 ( V_107 ) )
return V_127 ;
else if ( F_30 ( V_107 ) )
return V_127 & V_128 ;
else
return V_127 & V_129 ;
}
long F_93 ( struct V_28 * V_130 , unsigned int V_131 , unsigned long V_132 )
{
struct V_6 * V_6 = F_2 ( V_130 ) ;
struct V_89 * V_90 = F_34 ( V_6 ) ;
unsigned int V_127 ;
int V_34 ;
switch ( V_131 ) {
case V_133 :
V_127 = V_90 -> V_134 & V_135 ;
return F_94 ( V_127 , ( int V_136 * ) V_132 ) ;
case V_137 :
{
unsigned int V_138 ;
V_34 = F_95 ( V_130 ) ;
if ( V_34 )
return V_34 ;
if ( ! F_96 ( V_6 ) ) {
V_34 = - V_139 ;
goto V_18;
}
if ( F_97 ( V_127 , ( int V_136 * ) V_132 ) ) {
V_34 = - V_23 ;
goto V_18;
}
V_127 = F_92 ( V_6 -> V_48 , V_127 ) ;
F_29 ( & V_6 -> V_45 ) ;
V_138 = V_90 -> V_134 ;
if ( ( V_127 ^ V_138 ) & ( V_140 | V_141 ) ) {
if ( ! F_74 ( V_142 ) ) {
F_40 ( & V_6 -> V_45 ) ;
V_34 = - V_143 ;
goto V_18;
}
}
V_127 = V_127 & V_144 ;
V_127 |= V_138 & ~ V_144 ;
V_90 -> V_134 = V_127 ;
F_40 ( & V_6 -> V_45 ) ;
F_98 ( V_6 ) ;
V_6 -> V_78 = V_79 ;
F_68 ( V_6 ) ;
V_18:
F_99 ( V_130 ) ;
return V_34 ;
}
default:
return - V_145 ;
}
}
long F_100 ( struct V_28 * V_28 , unsigned int V_131 , unsigned long V_132 )
{
switch ( V_131 ) {
case V_146 :
V_131 = V_147 ;
break;
case V_148 :
V_131 = V_149 ;
break;
default:
return - V_150 ;
}
return F_93 ( V_28 , V_131 , ( unsigned long ) F_101 ( V_132 ) ) ;
}
