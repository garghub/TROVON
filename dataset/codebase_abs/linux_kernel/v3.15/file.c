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
static int F_56 ( struct V_28 * V_28 , struct V_1 * V_2 )
{
F_57 ( V_28 ) ;
V_2 -> V_51 = & V_52 ;
return 0 ;
}
int F_58 ( struct V_11 * V_12 , int V_53 )
{
int V_54 = 0 , V_55 = V_12 -> V_56 ;
struct V_8 * V_9 = F_3 ( V_12 -> V_6 -> V_10 ) ;
struct V_57 * V_58 ;
T_3 * V_59 ;
V_58 = F_59 ( V_12 -> V_60 ) ;
V_59 = F_60 ( V_58 ) + V_55 ;
for (; V_53 > 0 ; V_53 -- , V_59 ++ , V_12 -> V_56 ++ ) {
T_4 V_61 = F_61 ( * V_59 ) ;
if ( V_61 == V_62 )
continue;
F_62 ( V_62 , V_12 ) ;
F_63 ( V_9 , V_61 ) ;
V_54 ++ ;
}
if ( V_54 ) {
F_64 ( V_9 , V_12 -> V_6 , V_54 ) ;
F_19 ( V_12 -> V_60 ) ;
F_65 ( V_12 ) ;
}
V_12 -> V_56 = V_55 ;
F_66 ( V_12 -> V_6 , V_12 -> V_63 ,
V_12 -> V_56 , V_54 ) ;
return V_54 ;
}
void F_67 ( struct V_11 * V_12 )
{
F_58 ( V_12 , V_64 ) ;
}
static void F_68 ( struct V_6 * V_6 , T_5 V_65 )
{
unsigned V_21 = V_65 & ( V_23 - 1 ) ;
struct V_5 * V_5 ;
if ( ! V_21 )
return;
V_5 = F_69 ( V_6 , V_65 >> V_20 , false ) ;
if ( F_70 ( V_5 ) )
return;
F_11 ( V_5 ) ;
if ( F_12 ( V_5 -> V_16 != V_6 -> V_17 ) ) {
F_71 ( V_5 , 1 ) ;
return;
}
F_22 ( V_5 , V_24 ) ;
F_72 ( V_5 , V_21 , V_23 - V_21 ) ;
F_19 ( V_5 ) ;
F_71 ( V_5 , 1 ) ;
}
int F_73 ( struct V_6 * V_6 , T_5 V_65 )
{
struct V_8 * V_9 = F_3 ( V_6 -> V_10 ) ;
unsigned int V_66 = V_6 -> V_10 -> V_67 ;
struct V_11 V_12 ;
T_6 V_68 ;
int V_53 = 0 , V_13 = 0 ;
F_74 ( V_6 , V_65 ) ;
if ( F_75 ( V_6 ) )
goto V_69;
V_68 = ( T_6 )
( ( V_65 + V_66 - 1 ) >> ( V_9 -> V_70 ) ) ;
F_6 ( V_9 ) ;
F_7 ( & V_12 , V_6 , NULL , NULL , 0 ) ;
V_13 = F_76 ( & V_12 , V_68 , V_71 ) ;
if ( V_13 ) {
if ( V_13 == - V_72 )
goto V_73;
F_9 ( V_9 ) ;
F_77 ( V_6 , V_13 ) ;
return V_13 ;
}
if ( F_78 ( V_12 . V_60 ) )
V_53 = F_79 ( F_33 ( V_6 ) ) ;
else
V_53 = V_64 ;
V_53 -= V_12 . V_56 ;
F_80 ( V_53 < 0 ) ;
if ( V_12 . V_56 || F_78 ( V_12 . V_60 ) ) {
F_58 ( & V_12 , V_53 ) ;
V_68 += V_53 ;
}
F_81 ( & V_12 ) ;
V_73:
V_13 = F_82 ( V_6 , V_68 ) ;
F_9 ( V_9 ) ;
V_69:
F_68 ( V_6 , V_65 ) ;
F_77 ( V_6 , V_13 ) ;
return V_13 ;
}
void F_83 ( struct V_6 * V_6 )
{
if ( ! ( F_39 ( V_6 -> V_46 ) || F_84 ( V_6 -> V_46 ) ||
F_85 ( V_6 -> V_46 ) ) )
return;
F_86 ( V_6 ) ;
if ( ! F_73 ( V_6 , F_14 ( V_6 ) ) ) {
V_6 -> V_74 = V_6 -> V_75 = V_76 ;
F_87 ( V_6 ) ;
}
}
int F_88 ( struct V_77 * V_78 ,
struct V_26 * V_26 , struct V_79 * V_80 )
{
struct V_6 * V_6 = V_26 -> V_81 ;
F_89 ( V_6 , V_80 ) ;
V_80 -> V_82 <<= 3 ;
return 0 ;
}
static void F_90 ( struct V_6 * V_6 , const struct V_83 * V_84 )
{
struct V_34 * V_35 = F_33 ( V_6 ) ;
unsigned int V_85 = V_84 -> V_85 ;
if ( V_85 & V_86 )
V_6 -> V_87 = V_84 -> V_88 ;
if ( V_85 & V_89 )
V_6 -> V_90 = V_84 -> V_91 ;
if ( V_85 & V_92 )
V_6 -> V_93 = F_91 ( V_84 -> V_94 ,
V_6 -> V_10 -> V_95 ) ;
if ( V_85 & V_96 )
V_6 -> V_74 = F_91 ( V_84 -> V_97 ,
V_6 -> V_10 -> V_95 ) ;
if ( V_85 & V_98 )
V_6 -> V_75 = F_91 ( V_84 -> V_99 ,
V_6 -> V_10 -> V_95 ) ;
if ( V_85 & V_100 ) {
T_7 V_101 = V_84 -> V_102 ;
if ( ! F_92 ( V_6 -> V_90 ) && ! F_93 ( V_103 ) )
V_101 &= ~ V_104 ;
F_94 ( V_35 , V_101 ) ;
}
}
int F_95 ( struct V_26 * V_26 , struct V_83 * V_84 )
{
struct V_6 * V_6 = V_26 -> V_81 ;
struct V_34 * V_35 = F_33 ( V_6 ) ;
int V_13 ;
V_13 = F_96 ( V_6 , V_84 ) ;
if ( V_13 )
return V_13 ;
if ( ( V_84 -> V_85 & V_105 ) &&
V_84 -> V_106 != F_14 ( V_6 ) ) {
V_13 = F_97 ( V_6 , V_84 -> V_106 ) ;
if ( V_13 )
return V_13 ;
F_98 ( V_6 , V_84 -> V_106 ) ;
F_83 ( V_6 ) ;
F_4 ( F_3 ( V_6 -> V_10 ) ) ;
}
F_90 ( V_6 , V_84 ) ;
if ( V_84 -> V_85 & V_100 ) {
V_13 = F_99 ( V_6 , F_100 ( V_6 ) ) ;
if ( V_13 || F_101 ( V_35 , V_107 ) ) {
V_6 -> V_46 = V_35 -> V_108 ;
F_102 ( V_35 , V_107 ) ;
}
}
F_87 ( V_6 ) ;
return V_13 ;
}
static void F_103 ( struct V_6 * V_6 , T_6 V_14 ,
T_2 V_29 , T_2 V_109 )
{
struct V_8 * V_9 = F_3 ( V_6 -> V_10 ) ;
struct V_5 * V_5 ;
if ( ! V_109 )
return;
F_4 ( V_9 ) ;
F_6 ( V_9 ) ;
V_5 = F_104 ( V_6 , NULL , V_14 , false ) ;
F_9 ( V_9 ) ;
if ( ! F_70 ( V_5 ) ) {
F_22 ( V_5 , V_24 ) ;
F_72 ( V_5 , V_29 , V_109 ) ;
F_19 ( V_5 ) ;
F_71 ( V_5 , 1 ) ;
}
}
int F_105 ( struct V_6 * V_6 , T_6 V_110 , T_6 V_111 )
{
T_6 V_14 ;
int V_13 ;
for ( V_14 = V_110 ; V_14 < V_111 ; V_14 ++ ) {
struct V_11 V_12 ;
F_7 ( & V_12 , V_6 , NULL , NULL , 0 ) ;
V_13 = F_76 ( & V_12 , V_14 , V_71 ) ;
if ( V_13 ) {
if ( V_13 == - V_72 )
continue;
return V_13 ;
}
if ( V_12 . V_112 != V_62 )
F_58 ( & V_12 , 1 ) ;
F_81 ( & V_12 ) ;
}
return 0 ;
}
static int F_106 ( struct V_6 * V_6 , T_2 V_21 , T_2 V_109 )
{
T_6 V_110 , V_111 ;
T_2 V_113 , V_114 ;
int V_36 = 0 ;
V_36 = F_97 ( V_6 , V_115 + 1 ) ;
if ( V_36 )
return V_36 ;
V_110 = ( ( unsigned long long ) V_21 ) >> V_20 ;
V_111 = ( ( unsigned long long ) V_21 + V_109 ) >> V_20 ;
V_113 = V_21 & ( V_23 - 1 ) ;
V_114 = ( V_21 + V_109 ) & ( V_23 - 1 ) ;
if ( V_110 == V_111 ) {
F_103 ( V_6 , V_110 , V_113 ,
V_114 - V_113 ) ;
} else {
if ( V_113 )
F_103 ( V_6 , V_110 ++ , V_113 ,
V_23 - V_113 ) ;
if ( V_114 )
F_103 ( V_6 , V_111 , 0 , V_114 ) ;
if ( V_110 < V_111 ) {
struct V_116 * V_16 = V_6 -> V_17 ;
T_2 V_117 , V_118 ;
struct V_8 * V_9 = F_3 ( V_6 -> V_10 ) ;
F_4 ( V_9 ) ;
V_117 = V_110 << V_20 ;
V_118 = V_111 << V_20 ;
F_107 ( V_16 , V_117 ,
V_118 - 1 ) ;
F_6 ( V_9 ) ;
V_36 = F_105 ( V_6 , V_110 , V_111 ) ;
F_9 ( V_9 ) ;
}
}
return V_36 ;
}
static int F_108 ( struct V_6 * V_6 , T_2 V_21 ,
T_2 V_109 , int V_101 )
{
struct V_8 * V_9 = F_3 ( V_6 -> V_10 ) ;
T_6 V_14 , V_110 , V_111 ;
T_2 V_119 = F_14 ( V_6 ) ;
T_2 V_113 , V_114 ;
int V_36 = 0 ;
V_36 = F_109 ( V_6 , ( V_109 + V_21 ) ) ;
if ( V_36 )
return V_36 ;
V_36 = F_97 ( V_6 , V_21 + V_109 ) ;
if ( V_36 )
return V_36 ;
V_110 = ( ( unsigned long long ) V_21 ) >> V_20 ;
V_111 = ( ( unsigned long long ) V_21 + V_109 ) >> V_20 ;
V_113 = V_21 & ( V_23 - 1 ) ;
V_114 = ( V_21 + V_109 ) & ( V_23 - 1 ) ;
for ( V_14 = V_110 ; V_14 <= V_111 ; V_14 ++ ) {
struct V_11 V_12 ;
F_6 ( V_9 ) ;
F_7 ( & V_12 , V_6 , NULL , NULL , 0 ) ;
V_36 = F_8 ( & V_12 , V_14 ) ;
F_9 ( V_9 ) ;
if ( V_36 )
break;
if ( V_110 == V_111 )
V_119 = V_21 + V_109 ;
else if ( V_14 == V_110 && V_113 )
V_119 = ( V_14 + 1 ) << V_20 ;
else if ( V_14 == V_111 )
V_119 = ( V_14 << V_20 ) + V_114 ;
else
V_119 += V_23 ;
}
if ( ! ( V_101 & V_120 ) &&
F_14 ( V_6 ) < V_119 ) {
F_110 ( V_6 , V_119 ) ;
F_87 ( V_6 ) ;
}
return V_36 ;
}
static long F_111 ( struct V_28 * V_28 , int V_101 ,
T_2 V_21 , T_2 V_109 )
{
struct V_6 * V_6 = F_2 ( V_28 ) ;
long V_36 ;
if ( V_101 & ~ ( V_120 | V_121 ) )
return - V_122 ;
F_112 ( & V_6 -> V_123 ) ;
if ( V_101 & V_121 )
V_36 = F_106 ( V_6 , V_21 , V_109 ) ;
else
V_36 = F_108 ( V_6 , V_21 , V_109 , V_101 ) ;
if ( ! V_36 ) {
V_6 -> V_74 = V_6 -> V_75 = V_76 ;
F_87 ( V_6 ) ;
}
F_113 ( & V_6 -> V_123 ) ;
F_114 ( V_6 , V_101 , V_21 , V_109 , V_36 ) ;
return V_36 ;
}
static inline T_8 F_115 ( T_7 V_101 , T_8 V_124 )
{
if ( F_84 ( V_101 ) )
return V_124 ;
else if ( F_39 ( V_101 ) )
return V_124 & V_125 ;
else
return V_124 & V_126 ;
}
long F_116 ( struct V_28 * V_127 , unsigned int V_128 , unsigned long V_129 )
{
struct V_6 * V_6 = F_2 ( V_127 ) ;
struct V_34 * V_35 = F_33 ( V_6 ) ;
unsigned int V_124 ;
int V_36 ;
switch ( V_128 ) {
case V_130 :
V_124 = V_35 -> V_131 & V_132 ;
return F_117 ( V_124 , ( int V_133 * ) V_129 ) ;
case V_134 :
{
unsigned int V_135 ;
V_36 = F_118 ( V_127 ) ;
if ( V_36 )
return V_36 ;
if ( ! F_119 ( V_6 ) ) {
V_36 = - V_136 ;
goto V_15;
}
if ( F_120 ( V_124 , ( int V_133 * ) V_129 ) ) {
V_36 = - V_18 ;
goto V_15;
}
V_124 = F_115 ( V_6 -> V_46 , V_124 ) ;
F_112 ( & V_6 -> V_123 ) ;
V_135 = V_35 -> V_131 ;
if ( ( V_124 ^ V_135 ) & ( V_137 | V_138 ) ) {
if ( ! F_93 ( V_139 ) ) {
F_113 ( & V_6 -> V_123 ) ;
V_36 = - V_140 ;
goto V_15;
}
}
V_124 = V_124 & V_141 ;
V_124 |= V_135 & ~ V_141 ;
V_35 -> V_131 = V_124 ;
F_113 ( & V_6 -> V_123 ) ;
F_121 ( V_6 ) ;
V_6 -> V_75 = V_76 ;
F_87 ( V_6 ) ;
V_15:
F_122 ( V_127 ) ;
return V_36 ;
}
default:
return - V_142 ;
}
}
long F_123 ( struct V_28 * V_28 , unsigned int V_128 , unsigned long V_129 )
{
switch ( V_128 ) {
case V_143 :
V_128 = V_130 ;
break;
case V_144 :
V_128 = V_134 ;
break;
default:
return - V_145 ;
}
return F_116 ( V_28 , V_128 , ( unsigned long ) F_124 ( V_129 ) ) ;
}
