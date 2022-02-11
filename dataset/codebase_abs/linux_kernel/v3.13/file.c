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
F_6 ( V_9 ) ;
F_7 ( & V_13 , V_6 , NULL , NULL , 0 ) ;
V_14 = F_8 ( & V_13 , V_5 -> V_15 , V_16 ) ;
if ( V_14 ) {
F_9 ( V_9 ) ;
goto V_17;
}
V_11 = V_13 . V_18 ;
if ( V_11 == V_19 ) {
V_14 = F_10 ( & V_13 ) ;
if ( V_14 ) {
F_11 ( & V_13 ) ;
F_9 ( V_9 ) ;
goto V_17;
}
}
F_11 ( & V_13 ) ;
F_9 ( V_9 ) ;
F_12 ( V_2 -> V_7 ) ;
F_13 ( V_5 ) ;
if ( V_5 -> V_20 != V_6 -> V_21 ||
F_14 ( V_5 ) > F_15 ( V_6 ) ||
! F_16 ( V_5 ) ) {
F_17 ( V_5 ) ;
V_14 = - V_22 ;
goto V_17;
}
if ( F_18 ( V_5 ) )
goto V_23;
if ( ( ( V_5 -> V_15 + 1 ) << V_24 ) > F_15 ( V_6 ) ) {
unsigned V_25 ;
V_25 = F_15 ( V_6 ) & ~ V_26 ;
F_19 ( V_5 , V_25 , V_27 ) ;
}
F_20 ( V_5 ) ;
F_21 ( V_5 ) ;
F_22 ( V_5 , V_28 ) ;
V_23:
F_23 ( V_5 ) ;
V_17:
F_24 ( V_6 -> V_10 ) ;
return F_25 ( V_14 ) ;
}
static int F_26 ( struct V_6 * V_6 , T_2 * V_29 )
{
struct V_30 * V_30 ;
V_6 = F_27 ( V_6 ) ;
V_30 = F_28 ( V_6 ) ;
F_29 ( V_6 ) ;
if ( ! V_30 )
return 0 ;
if ( F_30 ( V_6 , & V_30 -> V_31 ) ) {
F_31 ( V_30 ) ;
return 0 ;
}
* V_29 = F_32 ( V_30 ) ;
F_31 ( V_30 ) ;
return 1 ;
}
int F_33 ( struct V_32 * V_32 , T_3 V_33 , T_3 V_34 , int V_35 )
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
if ( F_34 ( V_6 -> V_10 ) )
return 0 ;
F_35 ( V_6 ) ;
V_38 = F_36 ( V_6 -> V_21 , V_33 , V_34 ) ;
if ( V_38 ) {
F_37 ( V_6 , V_39 , V_35 , V_38 ) ;
return V_38 ;
}
F_4 ( V_9 ) ;
F_38 ( & V_6 -> V_47 ) ;
if ( ! F_39 ( V_6 -> V_48 ) || V_6 -> V_49 != 1 )
V_39 = true ;
else if ( F_40 ( V_6 ) )
V_39 = true ;
else if ( ! F_41 ( V_9 ) )
V_39 = true ;
else if ( ! F_42 ( V_9 , F_43 ( V_6 ) -> V_50 ) )
V_39 = true ;
else if ( F_43 ( V_6 ) -> V_51 == F_44 ( F_45 ( V_9 ) ) )
V_39 = true ;
if ( V_39 ) {
T_2 V_29 ;
F_43 ( V_6 ) -> V_51 = 0 ;
V_38 = F_46 ( V_6 -> V_10 , 1 ) ;
if ( F_40 ( V_6 ) && V_6 -> V_49 == 1 &&
F_26 ( V_6 , & V_29 ) ) {
F_43 ( V_6 ) -> V_50 = V_29 ;
F_47 ( V_6 ) ;
F_48 ( V_6 ) ;
V_38 = F_49 ( V_6 , NULL ) ;
if ( V_38 )
goto V_17;
}
} else {
while ( ! F_50 ( V_9 , V_6 -> V_52 , & V_41 ) ) {
F_48 ( V_6 ) ;
V_38 = F_49 ( V_6 , NULL ) ;
if ( V_38 )
goto V_17;
}
V_38 = F_51 ( V_9 , V_6 -> V_52 ) ;
if ( V_38 )
goto V_17;
V_38 = F_52 ( V_6 -> V_10 -> V_53 , V_54 , NULL ) ;
}
V_17:
F_53 ( & V_6 -> V_47 ) ;
F_37 ( V_6 , V_39 , V_35 , V_38 ) ;
return V_38 ;
}
static int F_54 ( struct V_32 * V_32 , struct V_1 * V_2 )
{
F_55 ( V_32 ) ;
V_2 -> V_55 = & V_56 ;
return 0 ;
}
int F_56 ( struct V_12 * V_13 , int V_57 )
{
int V_58 = 0 , V_59 = V_13 -> V_60 ;
struct V_8 * V_9 = F_3 ( V_13 -> V_6 -> V_10 ) ;
struct V_61 * V_62 ;
T_4 * V_63 ;
V_62 = F_57 ( V_13 -> V_64 ) ;
V_63 = F_58 ( V_62 ) + V_59 ;
for ( ; V_57 > 0 ; V_57 -- , V_63 ++ , V_13 -> V_60 ++ ) {
T_1 V_65 = F_59 ( * V_63 ) ;
if ( V_65 == V_19 )
continue;
F_60 ( V_19 , V_13 ) ;
F_61 ( V_9 , V_65 ) ;
V_58 ++ ;
}
if ( V_58 ) {
F_62 ( V_9 , V_13 -> V_6 , V_58 ) ;
F_20 ( V_13 -> V_64 ) ;
F_63 ( V_13 ) ;
}
V_13 -> V_60 = V_59 ;
F_64 ( V_13 -> V_6 , V_13 -> V_66 ,
V_13 -> V_60 , V_58 ) ;
return V_58 ;
}
void F_65 ( struct V_12 * V_13 )
{
F_56 ( V_13 , V_67 ) ;
}
static void F_66 ( struct V_6 * V_6 , T_5 V_68 )
{
unsigned V_25 = V_68 & ( V_27 - 1 ) ;
struct V_5 * V_5 ;
if ( ! V_25 )
return;
V_5 = F_67 ( V_6 , V_68 >> V_24 , false ) ;
if ( F_68 ( V_5 ) )
return;
F_13 ( V_5 ) ;
if ( V_5 -> V_20 != V_6 -> V_21 ) {
F_69 ( V_5 , 1 ) ;
return;
}
F_23 ( V_5 ) ;
F_70 ( V_5 , V_25 , V_27 - V_25 ) ;
F_20 ( V_5 ) ;
F_69 ( V_5 , 1 ) ;
}
static int F_71 ( struct V_6 * V_6 , T_5 V_68 )
{
struct V_8 * V_9 = F_3 ( V_6 -> V_10 ) ;
unsigned int V_69 = V_6 -> V_10 -> V_70 ;
struct V_12 V_13 ;
T_6 V_71 ;
int V_57 = 0 ;
int V_14 ;
F_72 ( V_6 , V_68 ) ;
V_71 = ( T_6 )
( ( V_68 + V_69 - 1 ) >> ( V_9 -> V_72 ) ) ;
F_6 ( V_9 ) ;
F_7 ( & V_13 , V_6 , NULL , NULL , 0 ) ;
V_14 = F_8 ( & V_13 , V_71 , V_73 ) ;
if ( V_14 ) {
if ( V_14 == - V_74 )
goto V_75;
F_9 ( V_9 ) ;
F_73 ( V_6 , V_14 ) ;
return V_14 ;
}
if ( F_74 ( V_13 . V_64 ) )
V_57 = F_75 ( F_43 ( V_6 ) ) ;
else
V_57 = V_67 ;
V_57 -= V_13 . V_60 ;
F_76 ( V_57 < 0 ) ;
if ( V_13 . V_60 || F_74 ( V_13 . V_64 ) ) {
F_56 ( & V_13 , V_57 ) ;
V_71 += V_57 ;
}
F_11 ( & V_13 ) ;
V_75:
V_14 = F_77 ( V_6 , V_71 ) ;
F_9 ( V_9 ) ;
F_66 ( V_6 , V_68 ) ;
F_73 ( V_6 , V_14 ) ;
return V_14 ;
}
void F_78 ( struct V_6 * V_6 )
{
if ( ! ( F_39 ( V_6 -> V_48 ) || F_79 ( V_6 -> V_48 ) ||
F_80 ( V_6 -> V_48 ) ) )
return;
F_81 ( V_6 ) ;
if ( ! F_71 ( V_6 , F_15 ( V_6 ) ) ) {
V_6 -> V_76 = V_6 -> V_77 = V_78 ;
F_82 ( V_6 ) ;
}
}
int F_83 ( struct V_79 * V_80 ,
struct V_30 * V_30 , struct V_81 * V_82 )
{
struct V_6 * V_6 = V_30 -> V_83 ;
F_84 ( V_6 , V_82 ) ;
V_82 -> V_84 <<= 3 ;
return 0 ;
}
static void F_85 ( struct V_6 * V_6 , const struct V_85 * V_86 )
{
struct V_87 * V_88 = F_43 ( V_6 ) ;
unsigned int V_89 = V_86 -> V_89 ;
if ( V_89 & V_90 )
V_6 -> V_91 = V_86 -> V_92 ;
if ( V_89 & V_93 )
V_6 -> V_94 = V_86 -> V_95 ;
if ( V_89 & V_96 )
V_6 -> V_97 = F_86 ( V_86 -> V_98 ,
V_6 -> V_10 -> V_99 ) ;
if ( V_89 & V_100 )
V_6 -> V_76 = F_86 ( V_86 -> V_101 ,
V_6 -> V_10 -> V_99 ) ;
if ( V_89 & V_102 )
V_6 -> V_77 = F_86 ( V_86 -> V_103 ,
V_6 -> V_10 -> V_99 ) ;
if ( V_89 & V_104 ) {
T_7 V_105 = V_86 -> V_106 ;
if ( ! F_87 ( V_6 -> V_94 ) && ! F_88 ( V_107 ) )
V_105 &= ~ V_108 ;
F_89 ( V_88 , V_105 ) ;
}
}
int F_90 ( struct V_30 * V_30 , struct V_85 * V_86 )
{
struct V_6 * V_6 = V_30 -> V_83 ;
struct V_87 * V_88 = F_43 ( V_6 ) ;
int V_14 ;
V_14 = F_91 ( V_6 , V_86 ) ;
if ( V_14 )
return V_14 ;
if ( ( V_86 -> V_89 & V_109 ) &&
V_86 -> V_110 != F_15 ( V_6 ) ) {
F_92 ( V_6 , V_86 -> V_110 ) ;
F_78 ( V_6 ) ;
F_4 ( F_3 ( V_6 -> V_10 ) ) ;
}
F_85 ( V_6 , V_86 ) ;
if ( V_86 -> V_89 & V_104 ) {
V_14 = F_93 ( V_6 ) ;
if ( V_14 || F_94 ( V_88 , V_111 ) ) {
V_6 -> V_48 = V_88 -> V_112 ;
F_95 ( V_88 , V_111 ) ;
}
}
F_82 ( V_6 ) ;
return V_14 ;
}
static void F_96 ( struct V_6 * V_6 , T_6 V_15 ,
T_3 V_33 , T_3 V_113 )
{
struct V_8 * V_9 = F_3 ( V_6 -> V_10 ) ;
struct V_5 * V_5 ;
if ( ! V_113 )
return;
F_4 ( V_9 ) ;
F_6 ( V_9 ) ;
V_5 = F_97 ( V_6 , NULL , V_15 , false ) ;
F_9 ( V_9 ) ;
if ( ! F_68 ( V_5 ) ) {
F_23 ( V_5 ) ;
F_70 ( V_5 , V_33 , V_113 ) ;
F_20 ( V_5 ) ;
F_69 ( V_5 , 1 ) ;
}
}
int F_98 ( struct V_6 * V_6 , T_6 V_114 , T_6 V_115 )
{
T_6 V_15 ;
int V_14 ;
for ( V_15 = V_114 ; V_15 < V_115 ; V_15 ++ ) {
struct V_12 V_13 ;
F_7 ( & V_13 , V_6 , NULL , NULL , 0 ) ;
V_14 = F_8 ( & V_13 , V_15 , V_73 ) ;
if ( V_14 ) {
if ( V_14 == - V_74 )
continue;
return V_14 ;
}
if ( V_13 . V_18 != V_19 )
F_56 ( & V_13 , 1 ) ;
F_11 ( & V_13 ) ;
}
return 0 ;
}
static int F_99 ( struct V_6 * V_6 , T_3 V_25 , T_3 V_113 , int V_105 )
{
T_6 V_114 , V_115 ;
T_3 V_116 , V_117 ;
int V_38 = 0 ;
V_114 = ( ( unsigned long long ) V_25 ) >> V_24 ;
V_115 = ( ( unsigned long long ) V_25 + V_113 ) >> V_24 ;
V_116 = V_25 & ( V_27 - 1 ) ;
V_117 = ( V_25 + V_113 ) & ( V_27 - 1 ) ;
if ( V_114 == V_115 ) {
F_96 ( V_6 , V_114 , V_116 ,
V_117 - V_116 ) ;
} else {
if ( V_116 )
F_96 ( V_6 , V_114 ++ , V_116 ,
V_27 - V_116 ) ;
if ( V_117 )
F_96 ( V_6 , V_115 , 0 , V_117 ) ;
if ( V_114 < V_115 ) {
struct V_118 * V_20 = V_6 -> V_21 ;
T_3 V_119 , V_120 ;
struct V_8 * V_9 = F_3 ( V_6 -> V_10 ) ;
F_4 ( V_9 ) ;
V_119 = V_114 << V_24 ;
V_120 = V_115 << V_24 ;
F_100 ( V_20 , V_119 ,
V_120 - 1 ) ;
F_6 ( V_9 ) ;
V_38 = F_98 ( V_6 , V_114 , V_115 ) ;
F_9 ( V_9 ) ;
}
}
if ( ! ( V_105 & V_121 ) &&
F_15 ( V_6 ) <= ( V_25 + V_113 ) ) {
F_101 ( V_6 , V_25 ) ;
F_82 ( V_6 ) ;
}
return V_38 ;
}
static int F_102 ( struct V_6 * V_6 , T_3 V_25 ,
T_3 V_113 , int V_105 )
{
struct V_8 * V_9 = F_3 ( V_6 -> V_10 ) ;
T_6 V_15 , V_114 , V_115 ;
T_3 V_122 = F_15 ( V_6 ) ;
T_3 V_116 , V_117 ;
int V_38 = 0 ;
V_38 = F_103 ( V_6 , ( V_113 + V_25 ) ) ;
if ( V_38 )
return V_38 ;
V_114 = ( ( unsigned long long ) V_25 ) >> V_24 ;
V_115 = ( ( unsigned long long ) V_25 + V_113 ) >> V_24 ;
V_116 = V_25 & ( V_27 - 1 ) ;
V_117 = ( V_25 + V_113 ) & ( V_27 - 1 ) ;
for ( V_15 = V_114 ; V_15 <= V_115 ; V_15 ++ ) {
struct V_12 V_13 ;
F_6 ( V_9 ) ;
F_7 ( & V_13 , V_6 , NULL , NULL , 0 ) ;
V_38 = F_8 ( & V_13 , V_15 , V_16 ) ;
if ( V_38 ) {
F_9 ( V_9 ) ;
break;
}
if ( V_13 . V_18 == V_19 ) {
V_38 = F_10 ( & V_13 ) ;
if ( V_38 ) {
F_11 ( & V_13 ) ;
F_9 ( V_9 ) ;
break;
}
}
F_11 ( & V_13 ) ;
F_9 ( V_9 ) ;
if ( V_114 == V_115 )
V_122 = V_25 + V_113 ;
else if ( V_15 == V_114 && V_116 )
V_122 = ( V_15 + 1 ) << V_24 ;
else if ( V_15 == V_115 )
V_122 = ( V_15 << V_24 ) + V_117 ;
else
V_122 += V_27 ;
}
if ( ! ( V_105 & V_121 ) &&
F_15 ( V_6 ) < V_122 ) {
F_101 ( V_6 , V_122 ) ;
F_82 ( V_6 ) ;
}
return V_38 ;
}
static long F_104 ( struct V_32 * V_32 , int V_105 ,
T_3 V_25 , T_3 V_113 )
{
struct V_6 * V_6 = F_2 ( V_32 ) ;
long V_38 ;
if ( V_105 & ~ ( V_121 | V_123 ) )
return - V_124 ;
if ( V_105 & V_123 )
V_38 = F_99 ( V_6 , V_25 , V_113 , V_105 ) ;
else
V_38 = F_102 ( V_6 , V_25 , V_113 , V_105 ) ;
if ( ! V_38 ) {
V_6 -> V_76 = V_6 -> V_77 = V_78 ;
F_82 ( V_6 ) ;
}
F_105 ( V_6 , V_105 , V_25 , V_113 , V_38 ) ;
return V_38 ;
}
static inline T_8 F_106 ( T_7 V_105 , T_8 V_125 )
{
if ( F_79 ( V_105 ) )
return V_125 ;
else if ( F_39 ( V_105 ) )
return V_125 & V_126 ;
else
return V_125 & V_127 ;
}
long F_107 ( struct V_32 * V_128 , unsigned int V_129 , unsigned long V_130 )
{
struct V_6 * V_6 = F_2 ( V_128 ) ;
struct V_87 * V_88 = F_43 ( V_6 ) ;
unsigned int V_125 ;
int V_38 ;
switch ( V_129 ) {
case V_131 :
V_125 = V_88 -> V_132 & V_133 ;
return F_108 ( V_125 , ( int V_134 * ) V_130 ) ;
case V_135 :
{
unsigned int V_136 ;
V_38 = F_109 ( V_128 ) ;
if ( V_38 )
return V_38 ;
if ( ! F_110 ( V_6 ) ) {
V_38 = - V_137 ;
goto V_17;
}
if ( F_111 ( V_125 , ( int V_134 * ) V_130 ) ) {
V_38 = - V_22 ;
goto V_17;
}
V_125 = F_106 ( V_6 -> V_48 , V_125 ) ;
F_38 ( & V_6 -> V_47 ) ;
V_136 = V_88 -> V_132 ;
if ( ( V_125 ^ V_136 ) & ( V_138 | V_139 ) ) {
if ( ! F_88 ( V_140 ) ) {
F_53 ( & V_6 -> V_47 ) ;
V_38 = - V_141 ;
goto V_17;
}
}
V_125 = V_125 & V_142 ;
V_125 |= V_136 & ~ V_142 ;
V_88 -> V_132 = V_125 ;
F_53 ( & V_6 -> V_47 ) ;
F_112 ( V_6 ) ;
V_6 -> V_77 = V_78 ;
F_82 ( V_6 ) ;
V_17:
F_113 ( V_128 ) ;
return V_38 ;
}
default:
return - V_143 ;
}
}
long F_114 ( struct V_32 * V_32 , unsigned int V_129 , unsigned long V_130 )
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
return F_107 ( V_32 , V_129 , ( unsigned long ) F_115 ( V_130 ) ) ;
}
