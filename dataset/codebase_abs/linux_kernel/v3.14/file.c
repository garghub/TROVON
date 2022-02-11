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
F_22 ( V_5 ) ;
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
struct V_8 * V_9 = F_3 ( V_6 -> V_10 ) ;
int V_34 = 0 ;
bool V_35 = false ;
struct V_36 V_37 = {
. V_38 = V_39 ,
. V_40 = V_41 ,
. V_42 = 0 ,
} ;
if ( F_12 ( F_33 ( V_6 -> V_10 ) ) )
return 0 ;
F_34 ( V_6 ) ;
V_34 = F_35 ( V_6 -> V_17 , V_29 , V_30 ) ;
if ( V_34 ) {
F_36 ( V_6 , V_35 , V_31 , V_34 ) ;
return V_34 ;
}
F_4 ( V_9 ) ;
F_37 ( & V_6 -> V_43 ) ;
if ( ! F_38 ( V_6 -> V_44 ) || V_6 -> V_45 != 1 )
V_35 = true ;
else if ( F_39 ( V_6 ) )
V_35 = true ;
else if ( ! F_40 ( V_9 ) )
V_35 = true ;
else if ( ! F_41 ( V_9 , F_42 ( V_6 ) -> V_46 ) )
V_35 = true ;
else if ( F_42 ( V_6 ) -> V_47 == F_43 ( F_44 ( V_9 ) ) )
V_35 = true ;
if ( V_35 ) {
T_1 V_25 ;
F_42 ( V_6 ) -> V_47 = 0 ;
V_34 = F_45 ( V_6 -> V_10 , 1 ) ;
if ( F_39 ( V_6 ) && V_6 -> V_45 == 1 &&
F_25 ( V_6 , & V_25 ) ) {
F_42 ( V_6 ) -> V_46 = V_25 ;
F_46 ( V_6 ) ;
F_47 ( V_6 ) ;
V_34 = F_48 ( V_6 , NULL ) ;
if ( V_34 )
goto V_15;
}
} else {
while ( ! F_49 ( V_9 , V_6 -> V_48 , & V_37 ) ) {
F_47 ( V_6 ) ;
V_34 = F_48 ( V_6 , NULL ) ;
if ( V_34 )
goto V_15;
}
V_34 = F_50 ( V_9 , V_6 -> V_48 ) ;
if ( V_34 )
goto V_15;
V_34 = F_51 ( V_6 -> V_10 -> V_49 , V_50 , NULL ) ;
}
V_15:
F_52 ( & V_6 -> V_43 ) ;
F_36 ( V_6 , V_35 , V_31 , V_34 ) ;
return V_34 ;
}
static int F_53 ( struct V_28 * V_28 , struct V_1 * V_2 )
{
F_54 ( V_28 ) ;
V_2 -> V_51 = & V_52 ;
return 0 ;
}
int F_55 ( struct V_11 * V_12 , int V_53 )
{
int V_54 = 0 , V_55 = V_12 -> V_56 ;
struct V_8 * V_9 = F_3 ( V_12 -> V_6 -> V_10 ) ;
struct V_57 * V_58 ;
T_3 * V_59 ;
V_58 = F_56 ( V_12 -> V_60 ) ;
V_59 = F_57 ( V_58 ) + V_55 ;
for (; V_53 > 0 ; V_53 -- , V_59 ++ , V_12 -> V_56 ++ ) {
T_4 V_61 = F_58 ( * V_59 ) ;
if ( V_61 == V_62 )
continue;
F_59 ( V_62 , V_12 ) ;
F_60 ( V_9 , V_61 ) ;
V_54 ++ ;
}
if ( V_54 ) {
F_61 ( V_9 , V_12 -> V_6 , V_54 ) ;
F_19 ( V_12 -> V_60 ) ;
F_62 ( V_12 ) ;
}
V_12 -> V_56 = V_55 ;
F_63 ( V_12 -> V_6 , V_12 -> V_63 ,
V_12 -> V_56 , V_54 ) ;
return V_54 ;
}
void F_64 ( struct V_11 * V_12 )
{
F_55 ( V_12 , V_64 ) ;
}
static void F_65 ( struct V_6 * V_6 , T_5 V_65 )
{
unsigned V_21 = V_65 & ( V_23 - 1 ) ;
struct V_5 * V_5 ;
if ( ! V_21 )
return;
V_5 = F_66 ( V_6 , V_65 >> V_20 , false ) ;
if ( F_67 ( V_5 ) )
return;
F_11 ( V_5 ) ;
if ( F_12 ( V_5 -> V_16 != V_6 -> V_17 ) ) {
F_68 ( V_5 , 1 ) ;
return;
}
F_22 ( V_5 ) ;
F_69 ( V_5 , V_21 , V_23 - V_21 ) ;
F_19 ( V_5 ) ;
F_68 ( V_5 , 1 ) ;
}
int F_70 ( struct V_6 * V_6 , T_5 V_65 )
{
struct V_8 * V_9 = F_3 ( V_6 -> V_10 ) ;
unsigned int V_66 = V_6 -> V_10 -> V_67 ;
struct V_11 V_12 ;
T_6 V_68 ;
int V_53 = 0 , V_13 = 0 ;
F_71 ( V_6 , V_65 ) ;
if ( F_72 ( V_6 ) )
goto V_69;
V_68 = ( T_6 )
( ( V_65 + V_66 - 1 ) >> ( V_9 -> V_70 ) ) ;
F_6 ( V_9 ) ;
F_7 ( & V_12 , V_6 , NULL , NULL , 0 ) ;
V_13 = F_73 ( & V_12 , V_68 , V_71 ) ;
if ( V_13 ) {
if ( V_13 == - V_72 )
goto V_73;
F_9 ( V_9 ) ;
F_74 ( V_6 , V_13 ) ;
return V_13 ;
}
if ( F_75 ( V_12 . V_60 ) )
V_53 = F_76 ( F_42 ( V_6 ) ) ;
else
V_53 = V_64 ;
V_53 -= V_12 . V_56 ;
F_77 ( V_53 < 0 ) ;
if ( V_12 . V_56 || F_75 ( V_12 . V_60 ) ) {
F_55 ( & V_12 , V_53 ) ;
V_68 += V_53 ;
}
F_78 ( & V_12 ) ;
V_73:
V_13 = F_79 ( V_6 , V_68 ) ;
F_9 ( V_9 ) ;
V_69:
F_65 ( V_6 , V_65 ) ;
F_74 ( V_6 , V_13 ) ;
return V_13 ;
}
void F_80 ( struct V_6 * V_6 )
{
if ( ! ( F_38 ( V_6 -> V_44 ) || F_81 ( V_6 -> V_44 ) ||
F_82 ( V_6 -> V_44 ) ) )
return;
F_83 ( V_6 ) ;
if ( ! F_70 ( V_6 , F_14 ( V_6 ) ) ) {
V_6 -> V_74 = V_6 -> V_75 = V_76 ;
F_84 ( V_6 ) ;
}
}
int F_85 ( struct V_77 * V_78 ,
struct V_26 * V_26 , struct V_79 * V_80 )
{
struct V_6 * V_6 = V_26 -> V_81 ;
F_86 ( V_6 , V_80 ) ;
V_80 -> V_82 <<= 3 ;
return 0 ;
}
static void F_87 ( struct V_6 * V_6 , const struct V_83 * V_84 )
{
struct V_85 * V_86 = F_42 ( V_6 ) ;
unsigned int V_87 = V_84 -> V_87 ;
if ( V_87 & V_88 )
V_6 -> V_89 = V_84 -> V_90 ;
if ( V_87 & V_91 )
V_6 -> V_92 = V_84 -> V_93 ;
if ( V_87 & V_94 )
V_6 -> V_95 = F_88 ( V_84 -> V_96 ,
V_6 -> V_10 -> V_97 ) ;
if ( V_87 & V_98 )
V_6 -> V_74 = F_88 ( V_84 -> V_99 ,
V_6 -> V_10 -> V_97 ) ;
if ( V_87 & V_100 )
V_6 -> V_75 = F_88 ( V_84 -> V_101 ,
V_6 -> V_10 -> V_97 ) ;
if ( V_87 & V_102 ) {
T_7 V_103 = V_84 -> V_104 ;
if ( ! F_89 ( V_6 -> V_92 ) && ! F_90 ( V_105 ) )
V_103 &= ~ V_106 ;
F_91 ( V_86 , V_103 ) ;
}
}
int F_92 ( struct V_26 * V_26 , struct V_83 * V_84 )
{
struct V_6 * V_6 = V_26 -> V_81 ;
struct V_85 * V_86 = F_42 ( V_6 ) ;
int V_13 ;
V_13 = F_93 ( V_6 , V_84 ) ;
if ( V_13 )
return V_13 ;
if ( ( V_84 -> V_87 & V_107 ) &&
V_84 -> V_108 != F_14 ( V_6 ) ) {
V_13 = F_94 ( V_6 , V_84 -> V_108 ) ;
if ( V_13 )
return V_13 ;
F_95 ( V_6 , V_84 -> V_108 ) ;
F_80 ( V_6 ) ;
F_4 ( F_3 ( V_6 -> V_10 ) ) ;
}
F_87 ( V_6 , V_84 ) ;
if ( V_84 -> V_87 & V_102 ) {
V_13 = F_96 ( V_6 , F_97 ( V_6 ) ) ;
if ( V_13 || F_98 ( V_86 , V_109 ) ) {
V_6 -> V_44 = V_86 -> V_110 ;
F_99 ( V_86 , V_109 ) ;
}
}
F_84 ( V_6 ) ;
return V_13 ;
}
static void F_100 ( struct V_6 * V_6 , T_6 V_14 ,
T_2 V_29 , T_2 V_111 )
{
struct V_8 * V_9 = F_3 ( V_6 -> V_10 ) ;
struct V_5 * V_5 ;
if ( ! V_111 )
return;
F_4 ( V_9 ) ;
F_6 ( V_9 ) ;
V_5 = F_101 ( V_6 , NULL , V_14 , false ) ;
F_9 ( V_9 ) ;
if ( ! F_67 ( V_5 ) ) {
F_22 ( V_5 ) ;
F_69 ( V_5 , V_29 , V_111 ) ;
F_19 ( V_5 ) ;
F_68 ( V_5 , 1 ) ;
}
}
int F_102 ( struct V_6 * V_6 , T_6 V_112 , T_6 V_113 )
{
T_6 V_14 ;
int V_13 ;
for ( V_14 = V_112 ; V_14 < V_113 ; V_14 ++ ) {
struct V_11 V_12 ;
F_7 ( & V_12 , V_6 , NULL , NULL , 0 ) ;
V_13 = F_73 ( & V_12 , V_14 , V_71 ) ;
if ( V_13 ) {
if ( V_13 == - V_72 )
continue;
return V_13 ;
}
if ( V_12 . V_114 != V_62 )
F_55 ( & V_12 , 1 ) ;
F_78 ( & V_12 ) ;
}
return 0 ;
}
static int F_103 ( struct V_6 * V_6 , T_2 V_21 , T_2 V_111 )
{
T_6 V_112 , V_113 ;
T_2 V_115 , V_116 ;
int V_34 = 0 ;
V_34 = F_94 ( V_6 , V_117 + 1 ) ;
if ( V_34 )
return V_34 ;
V_112 = ( ( unsigned long long ) V_21 ) >> V_20 ;
V_113 = ( ( unsigned long long ) V_21 + V_111 ) >> V_20 ;
V_115 = V_21 & ( V_23 - 1 ) ;
V_116 = ( V_21 + V_111 ) & ( V_23 - 1 ) ;
if ( V_112 == V_113 ) {
F_100 ( V_6 , V_112 , V_115 ,
V_116 - V_115 ) ;
} else {
if ( V_115 )
F_100 ( V_6 , V_112 ++ , V_115 ,
V_23 - V_115 ) ;
if ( V_116 )
F_100 ( V_6 , V_113 , 0 , V_116 ) ;
if ( V_112 < V_113 ) {
struct V_118 * V_16 = V_6 -> V_17 ;
T_2 V_119 , V_120 ;
struct V_8 * V_9 = F_3 ( V_6 -> V_10 ) ;
F_4 ( V_9 ) ;
V_119 = V_112 << V_20 ;
V_120 = V_113 << V_20 ;
F_104 ( V_16 , V_119 ,
V_120 - 1 ) ;
F_6 ( V_9 ) ;
V_34 = F_102 ( V_6 , V_112 , V_113 ) ;
F_9 ( V_9 ) ;
}
}
return V_34 ;
}
static int F_105 ( struct V_6 * V_6 , T_2 V_21 ,
T_2 V_111 , int V_103 )
{
struct V_8 * V_9 = F_3 ( V_6 -> V_10 ) ;
T_6 V_14 , V_112 , V_113 ;
T_2 V_121 = F_14 ( V_6 ) ;
T_2 V_115 , V_116 ;
int V_34 = 0 ;
V_34 = F_106 ( V_6 , ( V_111 + V_21 ) ) ;
if ( V_34 )
return V_34 ;
V_34 = F_94 ( V_6 , V_21 + V_111 ) ;
if ( V_34 )
return V_34 ;
V_112 = ( ( unsigned long long ) V_21 ) >> V_20 ;
V_113 = ( ( unsigned long long ) V_21 + V_111 ) >> V_20 ;
V_115 = V_21 & ( V_23 - 1 ) ;
V_116 = ( V_21 + V_111 ) & ( V_23 - 1 ) ;
for ( V_14 = V_112 ; V_14 <= V_113 ; V_14 ++ ) {
struct V_11 V_12 ;
F_6 ( V_9 ) ;
F_7 ( & V_12 , V_6 , NULL , NULL , 0 ) ;
V_34 = F_8 ( & V_12 , V_14 ) ;
F_9 ( V_9 ) ;
if ( V_34 )
break;
if ( V_112 == V_113 )
V_121 = V_21 + V_111 ;
else if ( V_14 == V_112 && V_115 )
V_121 = ( V_14 + 1 ) << V_20 ;
else if ( V_14 == V_113 )
V_121 = ( V_14 << V_20 ) + V_116 ;
else
V_121 += V_23 ;
}
if ( ! ( V_103 & V_122 ) &&
F_14 ( V_6 ) < V_121 ) {
F_107 ( V_6 , V_121 ) ;
F_84 ( V_6 ) ;
}
return V_34 ;
}
static long F_108 ( struct V_28 * V_28 , int V_103 ,
T_2 V_21 , T_2 V_111 )
{
struct V_6 * V_6 = F_2 ( V_28 ) ;
long V_34 ;
if ( V_103 & ~ ( V_122 | V_123 ) )
return - V_124 ;
if ( V_103 & V_123 )
V_34 = F_103 ( V_6 , V_21 , V_111 ) ;
else
V_34 = F_105 ( V_6 , V_21 , V_111 , V_103 ) ;
if ( ! V_34 ) {
V_6 -> V_74 = V_6 -> V_75 = V_76 ;
F_84 ( V_6 ) ;
}
F_109 ( V_6 , V_103 , V_21 , V_111 , V_34 ) ;
return V_34 ;
}
static inline T_8 F_110 ( T_7 V_103 , T_8 V_125 )
{
if ( F_81 ( V_103 ) )
return V_125 ;
else if ( F_38 ( V_103 ) )
return V_125 & V_126 ;
else
return V_125 & V_127 ;
}
long F_111 ( struct V_28 * V_128 , unsigned int V_129 , unsigned long V_130 )
{
struct V_6 * V_6 = F_2 ( V_128 ) ;
struct V_85 * V_86 = F_42 ( V_6 ) ;
unsigned int V_125 ;
int V_34 ;
switch ( V_129 ) {
case V_131 :
V_125 = V_86 -> V_132 & V_133 ;
return F_112 ( V_125 , ( int V_134 * ) V_130 ) ;
case V_135 :
{
unsigned int V_136 ;
V_34 = F_113 ( V_128 ) ;
if ( V_34 )
return V_34 ;
if ( ! F_114 ( V_6 ) ) {
V_34 = - V_137 ;
goto V_15;
}
if ( F_115 ( V_125 , ( int V_134 * ) V_130 ) ) {
V_34 = - V_18 ;
goto V_15;
}
V_125 = F_110 ( V_6 -> V_44 , V_125 ) ;
F_37 ( & V_6 -> V_43 ) ;
V_136 = V_86 -> V_132 ;
if ( ( V_125 ^ V_136 ) & ( V_138 | V_139 ) ) {
if ( ! F_90 ( V_140 ) ) {
F_52 ( & V_6 -> V_43 ) ;
V_34 = - V_141 ;
goto V_15;
}
}
V_125 = V_125 & V_142 ;
V_125 |= V_136 & ~ V_142 ;
V_86 -> V_132 = V_125 ;
F_52 ( & V_6 -> V_43 ) ;
F_116 ( V_6 ) ;
V_6 -> V_75 = V_76 ;
F_84 ( V_6 ) ;
V_15:
F_117 ( V_128 ) ;
return V_34 ;
}
default:
return - V_143 ;
}
}
long F_118 ( struct V_28 * V_28 , unsigned int V_129 , unsigned long V_130 )
{
switch ( V_129 ) {
case V_144 :
V_129 = V_131 ;
break;
case V_145 :
V_129 = V_135 ;
break;
default:
return - V_146 ;
}
return F_111 ( V_28 , V_129 , ( unsigned long ) F_119 ( V_130 ) ) ;
}
