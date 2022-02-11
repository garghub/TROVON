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
if ( F_29 ( V_6 , & V_30 -> V_31 ) ) {
F_30 ( V_30 ) ;
return 0 ;
}
* V_29 = F_31 ( V_30 ) ;
F_30 ( V_30 ) ;
return 1 ;
}
int F_32 ( struct V_32 * V_32 , T_3 V_33 , T_3 V_34 , int V_35 )
{
struct V_6 * V_6 = V_32 -> V_36 -> V_37 ;
struct V_8 * V_9 = F_3 ( V_6 -> V_10 ) ;
int V_38 = 0 ;
bool V_39 = false ;
struct V_40 V_41 = {
. V_42 = V_43 ,
. V_44 = V_45 ,
. V_46 = 0 ,
} ;
if ( F_33 ( V_6 -> V_10 ) )
return 0 ;
F_34 ( V_6 ) ;
V_38 = F_35 ( V_6 -> V_22 , V_33 , V_34 ) ;
if ( V_38 ) {
F_36 ( V_6 , V_39 , V_35 , V_38 ) ;
return V_38 ;
}
F_4 ( V_9 ) ;
F_37 ( & V_6 -> V_47 ) ;
if ( ! F_38 ( V_6 -> V_48 ) || V_6 -> V_49 != 1 )
V_39 = true ;
else if ( F_39 ( V_6 ) )
V_39 = true ;
else if ( ! F_40 ( V_9 ) )
V_39 = true ;
else if ( ! F_41 ( V_9 , F_42 ( V_6 ) -> V_50 ) )
V_39 = true ;
else if ( F_42 ( V_6 ) -> V_51 == F_43 ( F_44 ( V_9 ) ) )
V_39 = true ;
if ( V_39 ) {
T_2 V_29 ;
F_42 ( V_6 ) -> V_51 = 0 ;
V_38 = F_45 ( V_6 -> V_10 , 1 ) ;
if ( F_39 ( V_6 ) && V_6 -> V_49 == 1 &&
F_25 ( V_6 , & V_29 ) ) {
F_42 ( V_6 ) -> V_50 = V_29 ;
F_46 ( V_6 ) ;
F_47 ( V_6 ) ;
V_38 = F_48 ( V_6 , NULL ) ;
if ( V_38 )
goto V_18;
}
} else {
while ( ! F_49 ( V_9 , V_6 -> V_52 , & V_41 ) ) {
F_47 ( V_6 ) ;
V_38 = F_48 ( V_6 , NULL ) ;
if ( V_38 )
goto V_18;
}
F_50 ( V_9 -> V_53 -> V_22 ,
0 , V_45 ) ;
V_38 = F_51 ( V_6 -> V_10 -> V_54 , V_55 , NULL ) ;
}
V_18:
F_52 ( & V_6 -> V_47 ) ;
F_36 ( V_6 , V_39 , V_35 , V_38 ) ;
return V_38 ;
}
static int F_53 ( struct V_32 * V_32 , struct V_1 * V_2 )
{
F_54 ( V_32 ) ;
V_2 -> V_56 = & V_57 ;
return 0 ;
}
int F_55 ( struct V_12 * V_13 , int V_58 )
{
int V_59 = 0 , V_60 = V_13 -> V_61 ;
struct V_8 * V_9 = F_3 ( V_13 -> V_6 -> V_10 ) ;
struct V_62 * V_63 ;
T_4 * V_64 ;
V_63 = F_56 ( V_13 -> V_65 ) ;
V_64 = F_57 ( V_63 ) + V_60 ;
for ( ; V_58 > 0 ; V_58 -- , V_64 ++ , V_13 -> V_61 ++ ) {
T_1 V_66 = F_58 ( * V_64 ) ;
if ( V_66 == V_20 )
continue;
F_59 ( V_20 , V_13 ) ;
F_60 ( V_9 , V_66 ) ;
V_59 ++ ;
}
if ( V_59 ) {
F_61 ( V_9 , V_13 -> V_6 , V_59 ) ;
F_20 ( V_13 -> V_65 ) ;
F_62 ( V_13 ) ;
}
V_13 -> V_61 = V_60 ;
F_63 ( V_13 -> V_6 , V_13 -> V_67 ,
V_13 -> V_61 , V_59 ) ;
return V_59 ;
}
void F_64 ( struct V_12 * V_13 )
{
F_55 ( V_13 , V_68 ) ;
}
static void F_65 ( struct V_6 * V_6 , T_5 V_69 )
{
unsigned V_26 = V_69 & ( V_28 - 1 ) ;
struct V_5 * V_5 ;
if ( ! V_26 )
return;
V_5 = F_66 ( V_6 , V_69 >> V_25 , false ) ;
if ( F_67 ( V_5 ) )
return;
F_13 ( V_5 ) ;
if ( V_5 -> V_21 != V_6 -> V_22 ) {
F_68 ( V_5 , 1 ) ;
return;
}
F_22 ( V_5 ) ;
F_69 ( V_5 , V_26 , V_28 - V_26 ) ;
F_20 ( V_5 ) ;
F_68 ( V_5 , 1 ) ;
}
static int F_70 ( struct V_6 * V_6 , T_5 V_69 )
{
struct V_8 * V_9 = F_3 ( V_6 -> V_10 ) ;
unsigned int V_70 = V_6 -> V_10 -> V_71 ;
struct V_12 V_13 ;
T_6 V_72 ;
int V_58 = 0 , V_15 = - 1 ;
int V_14 ;
F_71 ( V_6 , V_69 ) ;
V_72 = ( T_6 )
( ( V_69 + V_70 - 1 ) >> ( V_9 -> V_73 ) ) ;
V_15 = F_6 ( V_9 ) ;
F_7 ( & V_13 , V_6 , NULL , NULL , 0 ) ;
V_14 = F_8 ( & V_13 , V_72 , V_74 ) ;
if ( V_14 ) {
if ( V_14 == - V_75 )
goto V_76;
F_9 ( V_9 , V_15 ) ;
F_72 ( V_6 , V_14 ) ;
return V_14 ;
}
if ( F_73 ( V_13 . V_65 ) )
V_58 = F_74 ( F_42 ( V_6 ) ) ;
else
V_58 = V_68 ;
V_58 -= V_13 . V_61 ;
F_75 ( V_58 < 0 ) ;
if ( V_13 . V_61 || F_73 ( V_13 . V_65 ) ) {
F_55 ( & V_13 , V_58 ) ;
V_72 += V_58 ;
}
F_11 ( & V_13 ) ;
V_76:
V_14 = F_76 ( V_6 , V_72 ) ;
F_9 ( V_9 , V_15 ) ;
F_65 ( V_6 , V_69 ) ;
F_72 ( V_6 , V_14 ) ;
return V_14 ;
}
void F_77 ( struct V_6 * V_6 )
{
if ( ! ( F_38 ( V_6 -> V_48 ) || F_78 ( V_6 -> V_48 ) ||
F_79 ( V_6 -> V_48 ) ) )
return;
F_80 ( V_6 ) ;
if ( ! F_70 ( V_6 , F_15 ( V_6 ) ) ) {
V_6 -> V_77 = V_6 -> V_78 = V_79 ;
F_81 ( V_6 ) ;
}
}
int F_82 ( struct V_80 * V_81 ,
struct V_30 * V_30 , struct V_82 * V_83 )
{
struct V_6 * V_6 = V_30 -> V_84 ;
F_83 ( V_6 , V_83 ) ;
V_83 -> V_85 <<= 3 ;
return 0 ;
}
static void F_84 ( struct V_6 * V_6 , const struct V_86 * V_87 )
{
struct V_88 * V_89 = F_42 ( V_6 ) ;
unsigned int V_90 = V_87 -> V_90 ;
if ( V_90 & V_91 )
V_6 -> V_92 = V_87 -> V_93 ;
if ( V_90 & V_94 )
V_6 -> V_95 = V_87 -> V_96 ;
if ( V_90 & V_97 )
V_6 -> V_98 = F_85 ( V_87 -> V_99 ,
V_6 -> V_10 -> V_100 ) ;
if ( V_90 & V_101 )
V_6 -> V_77 = F_85 ( V_87 -> V_102 ,
V_6 -> V_10 -> V_100 ) ;
if ( V_90 & V_103 )
V_6 -> V_78 = F_85 ( V_87 -> V_104 ,
V_6 -> V_10 -> V_100 ) ;
if ( V_90 & V_105 ) {
T_7 V_106 = V_87 -> V_107 ;
if ( ! F_86 ( V_6 -> V_95 ) && ! F_87 ( V_108 ) )
V_106 &= ~ V_109 ;
F_88 ( V_89 , V_106 ) ;
}
}
int F_89 ( struct V_30 * V_30 , struct V_86 * V_87 )
{
struct V_6 * V_6 = V_30 -> V_84 ;
struct V_88 * V_89 = F_42 ( V_6 ) ;
int V_14 ;
V_14 = F_90 ( V_6 , V_87 ) ;
if ( V_14 )
return V_14 ;
if ( ( V_87 -> V_90 & V_110 ) &&
V_87 -> V_111 != F_15 ( V_6 ) ) {
F_91 ( V_6 , V_87 -> V_111 ) ;
F_77 ( V_6 ) ;
F_4 ( F_3 ( V_6 -> V_10 ) ) ;
}
F_84 ( V_6 , V_87 ) ;
if ( V_87 -> V_90 & V_105 ) {
V_14 = F_92 ( V_6 ) ;
if ( V_14 || F_93 ( V_89 , V_112 ) ) {
V_6 -> V_48 = V_89 -> V_113 ;
F_94 ( V_89 , V_112 ) ;
}
}
F_81 ( V_6 ) ;
return V_14 ;
}
static void F_95 ( struct V_6 * V_6 , T_6 V_16 ,
T_3 V_33 , T_3 V_114 )
{
struct V_8 * V_9 = F_3 ( V_6 -> V_10 ) ;
struct V_5 * V_5 ;
int V_15 ;
if ( ! V_114 )
return;
F_4 ( V_9 ) ;
V_15 = F_6 ( V_9 ) ;
V_5 = F_96 ( V_6 , NULL , V_16 , false ) ;
F_9 ( V_9 , V_15 ) ;
if ( ! F_67 ( V_5 ) ) {
F_22 ( V_5 ) ;
F_69 ( V_5 , V_33 , V_114 ) ;
F_20 ( V_5 ) ;
F_68 ( V_5 , 1 ) ;
}
}
int F_97 ( struct V_6 * V_6 , T_6 V_115 , T_6 V_116 )
{
T_6 V_16 ;
int V_14 ;
for ( V_16 = V_115 ; V_16 < V_116 ; V_16 ++ ) {
struct V_12 V_13 ;
F_7 ( & V_13 , V_6 , NULL , NULL , 0 ) ;
V_14 = F_8 ( & V_13 , V_16 , V_74 ) ;
if ( V_14 ) {
if ( V_14 == - V_75 )
continue;
return V_14 ;
}
if ( V_13 . V_19 != V_20 )
F_55 ( & V_13 , 1 ) ;
F_11 ( & V_13 ) ;
}
return 0 ;
}
static int F_98 ( struct V_6 * V_6 , T_3 V_26 , T_3 V_114 , int V_106 )
{
T_6 V_115 , V_116 ;
T_3 V_117 , V_118 ;
int V_38 = 0 ;
V_115 = ( ( unsigned long long ) V_26 ) >> V_25 ;
V_116 = ( ( unsigned long long ) V_26 + V_114 ) >> V_25 ;
V_117 = V_26 & ( V_28 - 1 ) ;
V_118 = ( V_26 + V_114 ) & ( V_28 - 1 ) ;
if ( V_115 == V_116 ) {
F_95 ( V_6 , V_115 , V_117 ,
V_118 - V_117 ) ;
} else {
if ( V_117 )
F_95 ( V_6 , V_115 ++ , V_117 ,
V_28 - V_117 ) ;
if ( V_118 )
F_95 ( V_6 , V_116 , 0 , V_118 ) ;
if ( V_115 < V_116 ) {
struct V_119 * V_21 = V_6 -> V_22 ;
T_3 V_120 , V_121 ;
struct V_8 * V_9 = F_3 ( V_6 -> V_10 ) ;
int V_15 ;
F_4 ( V_9 ) ;
V_120 = V_115 << V_25 ;
V_121 = V_116 << V_25 ;
F_99 ( V_21 , V_120 ,
V_121 - 1 ) ;
V_15 = F_6 ( V_9 ) ;
V_38 = F_97 ( V_6 , V_115 , V_116 ) ;
F_9 ( V_9 , V_15 ) ;
}
}
if ( ! ( V_106 & V_122 ) &&
F_15 ( V_6 ) <= ( V_26 + V_114 ) ) {
F_100 ( V_6 , V_26 ) ;
F_81 ( V_6 ) ;
}
return V_38 ;
}
static int F_101 ( struct V_6 * V_6 , T_3 V_26 ,
T_3 V_114 , int V_106 )
{
struct V_8 * V_9 = F_3 ( V_6 -> V_10 ) ;
T_6 V_16 , V_115 , V_116 ;
T_3 V_123 = F_15 ( V_6 ) ;
T_3 V_117 , V_118 ;
int V_38 = 0 ;
V_38 = F_102 ( V_6 , ( V_114 + V_26 ) ) ;
if ( V_38 )
return V_38 ;
V_115 = ( ( unsigned long long ) V_26 ) >> V_25 ;
V_116 = ( ( unsigned long long ) V_26 + V_114 ) >> V_25 ;
V_117 = V_26 & ( V_28 - 1 ) ;
V_118 = ( V_26 + V_114 ) & ( V_28 - 1 ) ;
for ( V_16 = V_115 ; V_16 <= V_116 ; V_16 ++ ) {
struct V_12 V_13 ;
int V_15 ;
V_15 = F_6 ( V_9 ) ;
F_7 ( & V_13 , V_6 , NULL , NULL , 0 ) ;
V_38 = F_8 ( & V_13 , V_16 , V_17 ) ;
if ( V_38 ) {
F_9 ( V_9 , V_15 ) ;
break;
}
if ( V_13 . V_19 == V_20 ) {
V_38 = F_10 ( & V_13 ) ;
if ( V_38 ) {
F_11 ( & V_13 ) ;
F_9 ( V_9 , V_15 ) ;
break;
}
}
F_11 ( & V_13 ) ;
F_9 ( V_9 , V_15 ) ;
if ( V_115 == V_116 )
V_123 = V_26 + V_114 ;
else if ( V_16 == V_115 && V_117 )
V_123 = ( V_16 + 1 ) << V_25 ;
else if ( V_16 == V_116 )
V_123 = ( V_16 << V_25 ) + V_118 ;
else
V_123 += V_28 ;
}
if ( ! ( V_106 & V_122 ) &&
F_15 ( V_6 ) < V_123 ) {
F_100 ( V_6 , V_123 ) ;
F_81 ( V_6 ) ;
}
return V_38 ;
}
static long F_103 ( struct V_32 * V_32 , int V_106 ,
T_3 V_26 , T_3 V_114 )
{
struct V_6 * V_6 = F_2 ( V_32 ) ;
long V_38 ;
if ( V_106 & ~ ( V_122 | V_124 ) )
return - V_125 ;
if ( V_106 & V_124 )
V_38 = F_98 ( V_6 , V_26 , V_114 , V_106 ) ;
else
V_38 = F_101 ( V_6 , V_26 , V_114 , V_106 ) ;
if ( ! V_38 ) {
V_6 -> V_77 = V_6 -> V_78 = V_79 ;
F_81 ( V_6 ) ;
}
F_104 ( V_6 , V_106 , V_26 , V_114 , V_38 ) ;
return V_38 ;
}
static inline T_8 F_105 ( T_7 V_106 , T_8 V_126 )
{
if ( F_78 ( V_106 ) )
return V_126 ;
else if ( F_38 ( V_106 ) )
return V_126 & V_127 ;
else
return V_126 & V_128 ;
}
long F_106 ( struct V_32 * V_129 , unsigned int V_130 , unsigned long V_131 )
{
struct V_6 * V_6 = F_2 ( V_129 ) ;
struct V_88 * V_89 = F_42 ( V_6 ) ;
unsigned int V_126 ;
int V_38 ;
switch ( V_130 ) {
case V_132 :
V_126 = V_89 -> V_133 & V_134 ;
return F_107 ( V_126 , ( int V_135 * ) V_131 ) ;
case V_136 :
{
unsigned int V_137 ;
V_38 = F_108 ( V_129 ) ;
if ( V_38 )
return V_38 ;
if ( ! F_109 ( V_6 ) ) {
V_38 = - V_138 ;
goto V_18;
}
if ( F_110 ( V_126 , ( int V_135 * ) V_131 ) ) {
V_38 = - V_23 ;
goto V_18;
}
V_126 = F_105 ( V_6 -> V_48 , V_126 ) ;
F_37 ( & V_6 -> V_47 ) ;
V_137 = V_89 -> V_133 ;
if ( ( V_126 ^ V_137 ) & ( V_139 | V_140 ) ) {
if ( ! F_87 ( V_141 ) ) {
F_52 ( & V_6 -> V_47 ) ;
V_38 = - V_142 ;
goto V_18;
}
}
V_126 = V_126 & V_143 ;
V_126 |= V_137 & ~ V_143 ;
V_89 -> V_133 = V_126 ;
F_52 ( & V_6 -> V_47 ) ;
F_111 ( V_6 ) ;
V_6 -> V_78 = V_79 ;
F_81 ( V_6 ) ;
V_18:
F_112 ( V_129 ) ;
return V_38 ;
}
default:
return - V_144 ;
}
}
long F_113 ( struct V_32 * V_32 , unsigned int V_130 , unsigned long V_131 )
{
switch ( V_130 ) {
case V_145 :
V_130 = V_132 ;
break;
case V_146 :
V_130 = V_136 ;
break;
default:
return - V_147 ;
}
return F_106 ( V_32 , V_130 , ( unsigned long ) F_114 ( V_131 ) ) ;
}
