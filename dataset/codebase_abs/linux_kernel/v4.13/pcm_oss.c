static int F_1 ( struct V_1 * V_2 , unsigned int V_3 , int V_4 )
{
int V_5 = 0 ;
if ( V_2 -> V_3 < V_3 ) {
V_2 -> V_3 = V_3 ;
V_2 -> V_4 = V_4 ;
V_5 = 1 ;
} else if ( V_2 -> V_3 == V_3 && ! V_2 -> V_4 && V_4 ) {
V_2 -> V_4 = 1 ;
V_5 = 1 ;
}
if ( V_2 -> integer ) {
if ( V_2 -> V_4 ) {
V_2 -> V_3 ++ ;
V_2 -> V_4 = 0 ;
}
}
if ( F_2 ( V_2 ) ) {
F_3 ( V_2 ) ;
return - V_6 ;
}
return V_5 ;
}
static int F_4 ( struct V_1 * V_2 , unsigned int V_7 , int V_8 )
{
int V_5 = 0 ;
if ( V_2 -> V_7 > V_7 ) {
V_2 -> V_7 = V_7 ;
V_2 -> V_8 = V_8 ;
V_5 = 1 ;
} else if ( V_2 -> V_7 == V_7 && ! V_2 -> V_8 && V_8 ) {
V_2 -> V_8 = 1 ;
V_5 = 1 ;
}
if ( V_2 -> integer ) {
if ( V_2 -> V_8 ) {
V_2 -> V_7 -- ;
V_2 -> V_8 = 0 ;
}
}
if ( F_2 ( V_2 ) ) {
F_3 ( V_2 ) ;
return - V_6 ;
}
return V_5 ;
}
static int F_5 ( struct V_1 * V_2 , unsigned int V_9 )
{
struct V_1 V_10 ;
V_10 . V_11 = 0 ;
V_10 . V_3 = V_10 . V_7 = V_9 ;
V_10 . V_4 = V_10 . V_8 = 0 ;
V_10 . integer = 1 ;
return F_6 ( V_2 , & V_10 ) ;
}
static unsigned int
F_7 ( const struct V_12 * V_13 ,
T_1 V_14 , int * V_15 )
{
if ( F_8 ( V_14 ) ) {
if ( V_15 )
* V_15 = 0 ;
return F_9 ( F_10 ( V_13 , V_14 ) ) ;
}
if ( F_11 ( V_14 ) ) {
const struct V_1 * V_2 = F_12 ( V_13 , V_14 ) ;
if ( V_15 )
* V_15 = V_2 -> V_4 ;
return F_13 ( V_2 ) ;
}
return - V_6 ;
}
static unsigned int
F_14 ( const struct V_12 * V_13 ,
T_1 V_14 , int * V_15 )
{
if ( F_8 ( V_14 ) ) {
if ( V_15 )
* V_15 = 0 ;
return F_15 ( F_10 ( V_13 , V_14 ) ) ;
}
if ( F_11 ( V_14 ) ) {
const struct V_1 * V_2 = F_12 ( V_13 , V_14 ) ;
if ( V_15 )
* V_15 = - ( int ) V_2 -> V_8 ;
return F_16 ( V_2 ) ;
}
return - V_6 ;
}
static int F_17 ( struct V_12 * V_13 ,
T_1 V_14 ,
const struct V_16 * V_9 )
{
int V_5 ;
V_5 = F_18 ( F_19 ( V_13 , V_14 ) , V_9 ) ;
if ( V_5 ) {
V_13 -> V_17 |= 1 << V_14 ;
V_13 -> V_18 |= 1 << V_14 ;
}
return V_5 ;
}
static int F_20 ( struct V_19 * V_20 ,
struct V_12 * V_13 ,
T_1 V_14 ,
const struct V_16 * V_9 )
{
int V_5 = F_17 ( V_13 , V_14 , V_9 ) ;
if ( V_5 < 0 )
return V_5 ;
if ( V_13 -> V_18 ) {
int V_21 = F_21 ( V_20 , V_13 ) ;
if ( V_21 < 0 )
return V_21 ;
}
return 0 ;
}
static int F_22 ( struct V_12 * V_13 ,
T_1 V_14 , unsigned int V_9 ,
int V_15 )
{
int V_5 ;
int V_22 = 0 ;
if ( V_15 ) {
if ( V_15 > 0 ) {
V_22 = 1 ;
} else if ( V_15 < 0 ) {
if ( V_9 > 0 ) {
V_22 = 1 ;
V_9 -- ;
}
}
}
if ( F_8 ( V_14 ) )
V_5 = F_23 ( F_19 ( V_13 , V_14 ) ,
V_9 + ! ! V_22 ) ;
else if ( F_11 ( V_14 ) )
V_5 = F_1 ( F_24 ( V_13 , V_14 ) ,
V_9 , V_22 ) ;
else
return - V_6 ;
if ( V_5 ) {
V_13 -> V_17 |= 1 << V_14 ;
V_13 -> V_18 |= 1 << V_14 ;
}
return V_5 ;
}
static int F_25 ( struct V_19 * V_20 ,
struct V_12 * V_13 ,
T_1 V_14 , unsigned int V_9 ,
int * V_15 )
{
int V_5 = F_22 ( V_13 , V_14 , V_9 , V_15 ? * V_15 : 0 ) ;
if ( V_5 < 0 )
return V_5 ;
if ( V_13 -> V_18 ) {
int V_21 = F_21 ( V_20 , V_13 ) ;
if ( V_21 < 0 )
return V_21 ;
}
return F_7 ( V_13 , V_14 , V_15 ) ;
}
static int F_26 ( struct V_12 * V_13 ,
T_1 V_14 , unsigned int V_9 ,
int V_15 )
{
int V_5 ;
int V_22 = 0 ;
if ( V_15 ) {
if ( V_15 < 0 ) {
V_22 = 1 ;
} else if ( V_15 > 0 ) {
V_22 = 1 ;
V_9 ++ ;
}
}
if ( F_8 ( V_14 ) ) {
if ( V_9 == 0 && V_22 ) {
F_27 ( F_19 ( V_13 , V_14 ) ) ;
V_5 = - V_6 ;
} else
V_5 = F_28 ( F_19 ( V_13 , V_14 ) ,
V_9 - ! ! V_22 ) ;
} else if ( F_11 ( V_14 ) )
V_5 = F_4 ( F_24 ( V_13 , V_14 ) ,
V_9 , V_22 ) ;
else
return - V_6 ;
if ( V_5 ) {
V_13 -> V_17 |= 1 << V_14 ;
V_13 -> V_18 |= 1 << V_14 ;
}
return V_5 ;
}
static int F_29 ( struct V_19 * V_20 ,
struct V_12 * V_13 ,
T_1 V_14 , unsigned int V_9 ,
int * V_15 )
{
int V_5 = F_26 ( V_13 , V_14 , V_9 , V_15 ? * V_15 : 0 ) ;
if ( V_5 < 0 )
return V_5 ;
if ( V_13 -> V_18 ) {
int V_21 = F_21 ( V_20 , V_13 ) ;
if ( V_21 < 0 )
return V_21 ;
}
return F_14 ( V_13 , V_14 , V_15 ) ;
}
static int F_30 ( int V_23 , int V_24 ,
int V_25 , int V_26 ,
int * V_27 , int * V_28 )
{
V_24 = V_24 < 0 ? - 1 : ( V_24 > 0 ? 1 : 0 ) ;
V_26 = V_26 < 0 ? - 1 : ( V_26 > 0 ? 1 : 0 ) ;
* V_27 = V_23 - V_25 ;
* V_28 = V_24 - V_26 ;
if ( * V_28 == - 2 ) {
( * V_27 ) -- ;
} else if ( * V_28 == 2 ) {
( * V_27 ) ++ ;
}
return 0 ;
}
static int F_31 ( unsigned int V_23 , int V_24 ,
unsigned int V_25 , int V_26 )
{
if ( V_24 < 0 ) {
V_23 -- ;
V_24 = 1 ;
} else if ( V_24 > 0 )
V_24 = 1 ;
if ( V_26 < 0 ) {
V_25 -- ;
V_26 = 1 ;
} else if ( V_26 > 0 )
V_26 = 1 ;
return V_23 < V_25 || ( V_23 == V_25 && V_24 < V_26 ) ;
}
static int F_32 ( int V_3 , int V_29 ,
int V_30 , int V_31 ,
int V_7 , int V_32 )
{
int V_33 , V_34 ;
int V_35 , V_36 ;
F_30 ( V_30 , V_31 , V_3 , V_29 , & V_33 , & V_34 ) ;
F_30 ( V_7 , V_32 , V_30 , V_31 , & V_35 , & V_36 ) ;
return F_31 ( V_33 , V_34 , V_35 , V_36 ) ;
}
static int F_33 ( struct V_19 * V_20 ,
struct V_12 * V_13 ,
T_1 V_14 , unsigned int V_30 ,
int * V_15 )
{
struct V_12 * V_37 = NULL ;
int V_38 ;
unsigned int V_39 ;
int V_40 = 0 ;
int V_3 , V_7 ;
int V_29 , V_32 ;
int V_41 = V_15 ? * V_15 : 0 ;
if ( V_30 > V_42 )
V_30 = V_42 ;
V_3 = V_7 = V_30 ;
V_29 = V_32 = V_41 ;
if ( V_32 > 0 )
V_32 = 0 ;
else if ( V_32 == 0 )
V_32 = - 1 ;
else {
V_32 = 1 ;
V_7 -- ;
}
V_37 = F_34 ( sizeof( * V_37 ) , V_43 ) ;
if ( V_37 == NULL )
return - V_44 ;
* V_37 = * V_13 ;
V_39 = V_3 ;
V_3 = F_25 ( V_20 , V_13 , V_14 , V_3 , & V_29 ) ;
if ( V_3 >= 0 ) {
struct V_12 * V_45 ;
if ( V_7 < 0 )
goto V_46;
if ( ( unsigned int ) V_3 == V_39 && V_29 == V_41 )
goto V_46;
V_45 = F_34 ( sizeof( * V_45 ) , V_43 ) ;
if ( V_45 == NULL ) {
F_35 ( V_37 ) ;
return - V_44 ;
}
* V_45 = * V_37 ;
V_7 = F_29 ( V_20 , V_45 , V_14 , V_7 , & V_32 ) ;
if ( V_7 < 0 ) {
F_35 ( V_45 ) ;
goto V_46;
}
if ( F_32 ( V_7 , V_32 , V_30 , V_41 , V_3 , V_29 ) ) {
* V_13 = * V_45 ;
V_40 = 1 ;
}
F_35 ( V_45 ) ;
} else {
* V_13 = * V_37 ;
V_7 = F_29 ( V_20 , V_13 , V_14 , V_7 , & V_32 ) ;
if ( V_7 < 0 ) {
F_35 ( V_37 ) ;
return V_7 ;
}
V_40 = 1 ;
}
V_46:
F_35 ( V_37 ) ;
if ( V_40 )
V_38 = F_36 ( V_20 , V_13 , V_14 , V_15 ) ;
else
V_38 = F_37 ( V_20 , V_13 , V_14 , V_15 ) ;
F_38 ( V_38 < 0 ) ;
return V_38 ;
}
static int F_39 ( struct V_12 * V_13 ,
T_1 V_14 , unsigned int V_9 ,
int V_15 )
{
int V_5 ;
if ( F_8 ( V_14 ) ) {
struct V_16 * V_47 = F_19 ( V_13 , V_14 ) ;
if ( V_9 == 0 && V_15 < 0 ) {
V_5 = - V_6 ;
F_27 ( V_47 ) ;
} else {
if ( V_15 > 0 )
V_9 ++ ;
else if ( V_15 < 0 )
V_9 -- ;
V_5 = F_40 ( F_19 ( V_13 , V_14 ) , V_9 ) ;
}
} else if ( F_11 ( V_14 ) ) {
struct V_1 * V_2 = F_24 ( V_13 , V_14 ) ;
if ( V_9 == 0 && V_15 < 0 ) {
V_5 = - V_6 ;
F_3 ( V_2 ) ;
} else if ( V_15 == 0 )
V_5 = F_5 ( V_2 , V_9 ) ;
else {
struct V_1 V_10 ;
V_10 . V_4 = 1 ;
V_10 . V_8 = 1 ;
V_10 . V_11 = 0 ;
V_10 . integer = 0 ;
if ( V_15 < 0 ) {
V_10 . V_3 = V_9 - 1 ;
V_10 . V_7 = V_9 ;
} else {
V_10 . V_3 = V_9 ;
V_10 . V_7 = V_9 + 1 ;
}
V_5 = F_6 ( V_2 , & V_10 ) ;
}
} else
return - V_6 ;
if ( V_5 ) {
V_13 -> V_17 |= 1 << V_14 ;
V_13 -> V_18 |= 1 << V_14 ;
}
return V_5 ;
}
static int F_41 ( struct V_19 * V_20 ,
struct V_12 * V_13 ,
T_1 V_14 , unsigned int V_9 ,
int V_15 )
{
int V_5 = F_39 ( V_13 , V_14 , V_9 , V_15 ) ;
if ( V_5 < 0 )
return V_5 ;
if ( V_13 -> V_18 ) {
int V_21 = F_21 ( V_20 , V_13 ) ;
if ( V_21 < 0 )
return V_21 ;
}
return F_42 ( V_13 , V_14 , NULL ) ;
}
static int F_43 ( struct V_12 * V_13 ,
T_1 V_14 )
{
int V_5 ;
V_5 = F_44 ( F_24 ( V_13 , V_14 ) ) ;
if ( V_5 ) {
V_13 -> V_17 |= 1 << V_14 ;
V_13 -> V_18 |= 1 << V_14 ;
}
return V_5 ;
}
static int F_45 ( struct V_19 * V_48 )
{
struct V_49 * V_50 = V_48 -> V_50 ;
struct V_51 * V_52 , * V_53 ;
V_52 = V_50 -> V_54 . V_55 ;
while ( V_52 ) {
V_53 = V_52 -> V_53 ;
F_46 ( V_52 ) ;
V_52 = V_53 ;
}
V_50 -> V_54 . V_55 = V_50 -> V_54 . V_56 = NULL ;
return 0 ;
}
static int F_47 ( struct V_51 * V_52 )
{
struct V_49 * V_50 = V_52 -> V_57 -> V_50 ;
V_52 -> V_53 = V_50 -> V_54 . V_55 ;
V_52 -> V_58 = NULL ;
if ( V_50 -> V_54 . V_55 ) {
V_50 -> V_54 . V_55 -> V_58 = V_52 ;
V_50 -> V_54 . V_55 = V_52 ;
} else {
V_50 -> V_54 . V_56 =
V_50 -> V_54 . V_55 = V_52 ;
}
return 0 ;
}
int F_48 ( struct V_51 * V_52 )
{
struct V_49 * V_50 = V_52 -> V_57 -> V_50 ;
V_52 -> V_53 = NULL ;
V_52 -> V_58 = V_50 -> V_54 . V_56 ;
if ( V_50 -> V_54 . V_56 ) {
V_50 -> V_54 . V_56 -> V_53 = V_52 ;
V_50 -> V_54 . V_56 = V_52 ;
} else {
V_50 -> V_54 . V_56 =
V_50 -> V_54 . V_55 = V_52 ;
}
return 0 ;
}
static long F_49 ( struct V_19 * V_48 , long V_59 )
{
struct V_49 * V_50 = V_48 -> V_50 ;
long V_60 = F_50 ( V_48 ) ;
long V_61 = F_51 ( V_50 , V_59 ) ;
if ( V_60 == V_50 -> V_54 . V_62 )
return V_61 ;
#if V_63 >= 64
return V_50 -> V_54 . V_62 * V_61 / V_60 ;
#else
{
T_2 V_64 = ( T_2 ) V_50 -> V_54 . V_62 * ( T_2 ) V_61 ;
return F_52 ( V_64 , V_60 ) ;
}
#endif
}
static long F_53 ( struct V_19 * V_48 , long V_61 )
{
struct V_49 * V_50 = V_48 -> V_50 ;
long V_60 = F_50 ( V_48 ) ;
if ( V_60 == V_50 -> V_54 . V_62 )
return F_54 ( V_50 , V_61 ) ;
return F_54 ( V_50 , ( V_60 * V_61 ) / V_50 -> V_54 . V_62 ) ;
}
static inline
T_3 F_55 ( struct V_49 * V_50 )
{
return V_50 -> V_65 ;
}
static T_4 F_56 ( int V_66 )
{
switch ( V_66 ) {
case V_67 : return V_68 ;
case V_69 : return V_70 ;
case V_71 : return V_72 ;
case V_73 : return V_74 ;
case V_75 : return V_76 ;
case V_77 : return V_78 ;
case V_79 : return V_80 ;
case V_81 : return V_82 ;
case V_83 : return V_84 ;
case V_85 : return V_86 ;
case V_87 : return V_88 ;
case V_89 : return V_90 ;
case V_91 : return V_92 ;
case V_93 : return V_94 ;
case V_95 : return V_96 ;
case V_97 : return V_98 ;
case V_99 : return V_100 ;
default: return V_74 ;
}
}
static int F_57 ( T_4 V_66 )
{
switch ( V_66 ) {
case V_68 : return V_67 ;
case V_70 : return V_69 ;
case V_72 : return V_71 ;
case V_74 : return V_73 ;
case V_76 : return V_75 ;
case V_78 : return V_77 ;
case V_80 : return V_79 ;
case V_82 : return V_81 ;
case V_84 : return V_83 ;
case V_86 : return V_85 ;
case V_88 : return V_87 ;
case V_90 : return V_89 ;
case V_92 : return V_91 ;
case V_94 : return V_93 ;
case V_96 : return V_95 ;
case V_98 : return V_97 ;
case V_100 : return V_99 ;
default: return - V_6 ;
}
}
static int F_58 ( struct V_19 * V_48 ,
struct V_12 * V_101 ,
struct V_12 * V_102 )
{
T_5 V_103 ;
T_5 V_104 , V_105 , V_106 ;
T_5 V_107 , V_108 ;
struct V_49 * V_50 = V_48 -> V_50 ;
T_5 V_109 ;
V_109 = F_59 ( F_60 ( V_101 ) ) *
F_61 ( V_101 ) / 8 ;
V_104 = F_62 ( V_48 ,
F_14 ( V_102 , V_110 , NULL ) ) * V_109 ;
V_104 = F_63 ( V_104 ) ;
if ( F_64 ( & V_48 -> V_111 ) ) {
if ( V_104 > V_50 -> V_54 . V_112 )
V_104 = V_50 -> V_54 . V_112 ;
}
if ( V_48 -> V_54 . V_113 . V_114 > 16 )
V_105 = V_48 -> V_54 . V_113 . V_114 ;
else if ( V_50 -> V_54 . V_115 ) {
V_105 = 1 << V_50 -> V_54 . V_115 ;
if ( V_105 > V_104 / 2 )
V_105 = V_104 / 2 ;
} else {
int V_116 ;
T_5 V_117 = F_65 ( V_101 ) * F_59 ( F_60 ( V_101 ) ) * F_61 ( V_101 ) / 8 ;
V_105 = V_104 ;
do {
V_105 /= 2 ;
} while ( V_105 > V_117 );
if ( V_50 -> V_54 . V_118 == 0 ) {
V_116 = 4 ;
if ( V_105 / V_116 > 4096 )
V_116 *= 2 ;
if ( V_105 / V_116 < 4096 )
V_116 = 1 ;
} else
V_116 = V_50 -> V_54 . V_118 ;
V_105 /= V_116 ;
if ( V_105 < 16 )
V_105 = 16 ;
}
V_107 = F_62 ( V_48 ,
F_7 ( V_102 , V_119 , NULL ) ) ;
V_107 *= V_109 ;
V_107 = F_66 ( V_107 ) ;
if ( V_105 < V_107 )
V_105 = V_107 ;
V_108 = F_62 ( V_48 ,
F_14 ( V_102 , V_119 , NULL ) ) ;
V_108 *= V_109 ;
V_108 = F_63 ( V_108 ) ;
if ( V_105 > V_108 )
V_105 = V_108 ;
V_106 = V_104 / V_105 ;
if ( V_48 -> V_54 . V_113 . V_120 > 1 )
V_106 = V_48 -> V_54 . V_113 . V_120 ;
V_103 = F_14 ( V_102 , V_121 , NULL ) ;
if ( V_50 -> V_54 . V_122 && V_103 > V_50 -> V_54 . V_122 )
V_103 = V_50 -> V_54 . V_122 ;
if ( V_106 > V_103 )
V_106 = V_103 ;
V_103 = F_7 ( V_102 , V_121 , NULL ) ;
if ( V_103 < 2 )
V_103 = 2 ;
if ( V_106 < V_103 )
V_106 = V_103 ;
while ( V_105 * V_106 > V_104 )
V_105 /= 2 ;
if ( V_105 < 16 )
return - V_6 ;
V_50 -> V_54 . V_123 = V_105 ;
V_50 -> V_54 . V_124 = 1 ;
V_50 -> V_54 . V_120 = V_106 ;
return 0 ;
}
static int F_67 ( struct V_19 * V_48 ,
struct V_12 * V_13 , unsigned int V_125 )
{
const struct V_1 * V_126 ;
struct V_12 * V_37 ;
unsigned int V_127 , V_58 ;
V_37 = F_34 ( sizeof( * V_37 ) , V_43 ) ;
if ( V_37 == NULL )
return - V_44 ;
* V_37 = * V_13 ;
V_126 = F_12 ( V_37 , V_128 ) ;
V_127 = V_125 ;
for (; ; ) {
if ( V_126 -> V_7 < V_127 || ( V_126 -> V_7 == V_127 && V_126 -> V_8 ) )
break;
if ( V_126 -> V_3 < V_127 || ( V_126 -> V_3 == V_127 && ! V_126 -> V_4 ) ) {
int V_129 ;
V_129 = F_41 ( V_48 , V_13 ,
V_128 ,
V_127 , 0 ) ;
if ( V_129 == ( int ) V_127 ) {
F_35 ( V_37 ) ;
return V_127 ;
}
* V_13 = * V_37 ;
}
V_58 = V_127 ;
V_127 += V_125 ;
if ( V_127 <= V_58 )
break;
}
F_35 ( V_37 ) ;
return F_33 ( V_48 , V_13 , V_128 , V_125 , NULL ) ;
}
static int F_68 ( struct V_19 * V_48 ,
bool V_130 )
{
struct V_49 * V_50 = V_48 -> V_50 ;
struct V_12 * V_13 , * V_131 ;
struct V_132 * V_133 ;
T_6 V_104 , V_105 ;
T_5 V_109 ;
int V_21 ;
int V_134 ;
T_4 V_66 , V_135 ;
int V_136 ;
const struct V_16 * V_137 ;
struct V_16 V_138 ;
if ( V_130 ) {
if ( ! ( F_69 ( & V_50 -> V_54 . V_139 ) ) )
return - V_140 ;
} else if ( F_70 ( & V_50 -> V_54 . V_139 ) )
return - V_141 ;
V_133 = F_71 ( sizeof( * V_133 ) , V_43 ) ;
V_13 = F_34 ( sizeof( * V_13 ) , V_43 ) ;
V_131 = F_34 ( sizeof( * V_131 ) , V_43 ) ;
if ( ! V_133 || ! V_13 || ! V_131 ) {
V_21 = - V_44 ;
goto V_142;
}
if ( F_64 ( & V_48 -> V_111 ) )
V_134 = 1 ;
else
V_134 = V_48 -> V_54 . V_113 . V_134 ;
F_72 ( V_131 ) ;
F_43 ( V_131 , V_121 ) ;
F_22 ( V_131 , V_121 , 2 , 0 ) ;
F_27 ( & V_138 ) ;
if ( F_64 ( & V_48 -> V_111 ) )
F_73 ( & V_138 , ( V_143 int ) V_144 ) ;
else {
F_73 ( & V_138 , ( V_143 int ) V_145 ) ;
if ( ! V_134 )
F_73 ( & V_138 , ( V_143 int ) V_146 ) ;
}
V_21 = F_20 ( V_48 , V_131 , V_147 , & V_138 ) ;
if ( V_21 < 0 ) {
F_74 ( V_48 -> V_20 , L_1 ) ;
V_21 = - V_6 ;
goto V_142;
}
F_67 ( V_48 , V_131 , V_50 -> V_54 . V_127 ) ;
F_33 ( V_48 , V_131 , V_148 , V_50 -> V_54 . V_149 , NULL ) ;
V_66 = F_56 ( V_50 -> V_54 . V_66 ) ;
V_137 = F_10 ( V_131 , V_150 ) ;
if ( V_134 )
V_135 = V_66 ;
else
V_135 = F_75 ( V_66 , V_137 ) ;
if ( ( V_143 int ) V_135 < 0 ||
! F_76 ( V_137 , ( V_143 int ) V_135 ) ) {
for ( V_135 = ( V_143 T_4 ) 0 ;
( V_143 int ) V_135 <= ( V_143 int ) V_151 ;
V_135 = ( V_143 T_4 ) ( ( V_143 int ) V_135 + 1 ) ) {
if ( F_76 ( V_137 , ( V_143 int ) V_135 ) &&
F_57 ( V_135 ) >= 0 )
break;
}
if ( ( V_143 int ) V_135 > ( V_143 int ) V_151 ) {
F_74 ( V_48 -> V_20 , L_2 ) ;
V_21 = - V_6 ;
goto V_142;
}
}
V_21 = F_39 ( V_131 , V_150 , ( V_143 int ) V_135 , 0 ) ;
if ( V_21 < 0 )
goto V_142;
if ( V_134 ) {
memcpy ( V_13 , V_131 , sizeof( * V_13 ) ) ;
} else {
F_72 ( V_13 ) ;
F_39 ( V_13 , V_147 ,
( V_143 int ) V_145 , 0 ) ;
F_39 ( V_13 , V_150 ,
( V_143 int ) F_56 ( V_50 -> V_54 . V_66 ) , 0 ) ;
F_39 ( V_13 , V_148 ,
V_50 -> V_54 . V_149 , 0 ) ;
F_39 ( V_13 , V_128 ,
V_50 -> V_54 . V_127 , 0 ) ;
F_77 ( L_3 ,
F_78 ( V_13 ) , F_60 ( V_13 ) ,
F_61 ( V_13 ) , F_65 ( V_13 ) ) ;
}
F_77 ( L_4 ,
F_78 ( V_131 ) , F_60 ( V_131 ) ,
F_61 ( V_131 ) , F_65 ( V_131 ) ) ;
V_109 = F_59 ( F_60 ( V_13 ) ) *
F_61 ( V_13 ) / 8 ;
#ifdef F_79
F_45 ( V_48 ) ;
if ( ! V_134 ) {
F_45 ( V_48 ) ;
if ( ( V_21 = F_80 ( V_48 ,
V_13 ,
V_131 ) ) < 0 ) {
F_74 ( V_48 -> V_20 ,
L_5 , V_21 ) ;
F_45 ( V_48 ) ;
goto V_142;
}
if ( V_50 -> V_54 . V_55 ) {
struct V_51 * V_52 ;
if ( ( V_21 = F_81 ( V_48 , V_131 , & V_52 ) ) < 0 ) {
F_74 ( V_48 -> V_20 ,
L_6 , V_21 ) ;
F_45 ( V_48 ) ;
goto V_142;
}
if ( V_48 -> V_152 == V_153 ) {
V_21 = F_48 ( V_52 ) ;
} else {
V_21 = F_47 ( V_52 ) ;
}
if ( V_21 < 0 ) {
F_45 ( V_48 ) ;
goto V_142;
}
}
}
#endif
V_21 = F_58 ( V_48 , V_13 , V_131 ) ;
if ( V_21 < 0 )
goto V_142;
V_136 = F_82 ( V_48 , V_50 -> V_54 . V_123 / V_109 ) ;
V_21 = F_33 ( V_48 , V_131 , V_119 , V_136 , NULL ) ;
if ( V_21 < 0 )
goto V_142;
V_21 = F_33 ( V_48 , V_131 , V_121 ,
V_50 -> V_54 . V_120 , NULL ) ;
if ( V_21 < 0 )
goto V_142;
F_83 ( V_48 , V_154 , NULL ) ;
if ( ( V_21 = F_83 ( V_48 , V_155 , V_131 ) ) < 0 ) {
F_74 ( V_48 -> V_20 , L_7 , V_21 ) ;
goto V_142;
}
if ( V_50 -> V_54 . V_156 ) {
V_133 -> V_157 = 1 ;
} else {
V_133 -> V_157 = V_50 -> V_158 ;
}
if ( F_64 ( & V_48 -> V_111 ) ||
V_48 -> V_152 == V_159 )
V_133 -> V_160 = V_50 -> V_158 ;
else
V_133 -> V_160 = V_50 -> V_60 ;
V_133 -> V_161 = V_162 ;
V_133 -> V_163 = 1 ;
V_133 -> V_164 = V_48 -> V_152 == V_153 ?
1 : V_50 -> V_114 ;
if ( F_64 ( & V_48 -> V_111 ) ||
V_48 -> V_54 . V_113 . V_165 ) {
V_133 -> V_166 = 0 ;
V_133 -> V_167 = 0 ;
} else {
T_3 V_59 ;
V_59 = V_50 -> V_114 + 16 ;
if ( V_59 > V_50 -> V_60 )
V_59 = V_50 -> V_60 ;
V_133 -> V_166 = V_59 ;
V_133 -> V_167 = V_59 ;
}
if ( ( V_21 = F_83 ( V_48 , V_168 , V_133 ) ) < 0 ) {
F_74 ( V_48 -> V_20 , L_8 , V_21 ) ;
goto V_142;
}
V_50 -> V_54 . V_120 = F_84 ( V_131 ) ;
V_105 = F_62 ( V_48 , F_85 ( V_131 ) ) ;
if ( V_105 < 0 ) {
V_21 = - V_6 ;
goto V_142;
}
#ifdef F_79
if ( V_50 -> V_54 . V_55 ) {
V_21 = F_86 ( V_48 , V_105 ) ;
if ( V_21 < 0 )
goto V_142;
}
#endif
V_105 *= V_109 ;
V_104 = V_105 * V_50 -> V_54 . V_120 ;
if ( V_104 < 0 ) {
V_21 = - V_6 ;
goto V_142;
}
V_50 -> V_54 . V_123 = V_105 ;
V_50 -> V_54 . V_62 = V_104 ;
F_77 ( L_9 ,
V_50 -> V_54 . V_123 ,
V_50 -> V_54 . V_62 ) ;
F_77 ( L_10 ,
F_85 ( V_131 ) ,
F_87 ( V_131 ) ) ;
V_50 -> V_54 . V_66 = F_57 ( F_60 ( V_13 ) ) ;
V_50 -> V_54 . V_149 = F_61 ( V_13 ) ;
V_50 -> V_54 . V_127 = F_65 ( V_13 ) ;
F_88 ( V_50 -> V_54 . V_169 ) ;
V_50 -> V_54 . V_169 = F_89 ( V_50 -> V_54 . V_123 ) ;
if ( ! V_50 -> V_54 . V_169 ) {
V_21 = - V_44 ;
goto V_142;
}
V_50 -> V_54 . V_13 = 0 ;
V_50 -> V_54 . V_170 = 1 ;
V_50 -> V_54 . V_171 = 0 ;
if ( V_50 -> V_172 )
F_90 ( V_50 -> V_66 , V_50 -> V_172 , F_91 ( V_50 , V_50 -> V_173 ) ) ;
V_50 -> V_54 . V_124 = F_53 ( V_48 , V_105 ) ;
V_21 = 0 ;
V_142:
F_35 ( V_133 ) ;
F_35 ( V_13 ) ;
F_35 ( V_131 ) ;
F_92 ( & V_50 -> V_54 . V_139 ) ;
return V_21 ;
}
static int F_93 ( struct V_174 * V_175 , struct V_19 * * V_176 )
{
int V_177 , V_21 ;
struct V_19 * V_178 = NULL , * V_48 ;
for ( V_177 = 0 ; V_177 < 2 ; V_177 ++ ) {
V_48 = V_175 -> V_179 [ V_177 ] ;
if ( V_48 == NULL )
continue;
if ( V_178 == NULL )
V_178 = V_48 ;
if ( V_48 -> V_50 -> V_54 . V_13 ) {
V_21 = F_68 ( V_48 , false ) ;
if ( V_21 < 0 )
return V_21 ;
}
}
if ( ! V_178 )
return - V_180 ;
if ( V_176 )
* V_176 = V_178 ;
return 0 ;
}
static int F_94 ( struct V_19 * V_48 )
{
int V_21 ;
struct V_49 * V_50 = V_48 -> V_50 ;
V_21 = F_83 ( V_48 , V_181 , NULL ) ;
if ( V_21 < 0 ) {
F_74 ( V_48 -> V_20 ,
L_11 ) ;
return V_21 ;
}
V_50 -> V_54 . V_170 = 0 ;
V_50 -> V_54 . V_182 = 0 ;
V_50 -> V_54 . V_183 = 0 ;
V_50 -> V_54 . V_171 = 0 ;
return 0 ;
}
static int F_95 ( struct V_19 * V_48 )
{
struct V_49 * V_50 ;
int V_21 ;
if ( V_48 == NULL )
return 0 ;
V_50 = V_48 -> V_50 ;
if ( V_50 -> V_54 . V_13 ) {
V_21 = F_68 ( V_48 , false ) ;
if ( V_21 < 0 )
return V_21 ;
}
if ( V_50 -> V_54 . V_170 ) {
V_21 = F_94 ( V_48 ) ;
if ( V_21 < 0 )
return V_21 ;
}
return 0 ;
}
static int F_96 ( struct V_19 * V_48 , T_7 * V_184 )
{
struct V_49 * V_50 ;
T_3 V_59 ;
int V_21 = 0 ;
while ( 1 ) {
V_21 = F_83 ( V_48 , V_185 , V_184 ) ;
if ( V_21 < 0 )
break;
V_50 = V_48 -> V_50 ;
if ( * V_184 <= ( T_7 ) V_50 -> V_60 )
break;
V_59 = ( * V_184 - V_50 -> V_60 ) + V_50 -> V_114 - 1 ;
V_59 /= V_50 -> V_114 ;
V_59 *= V_50 -> V_114 ;
V_21 = F_83 ( V_48 , V_186 , & V_59 ) ;
if ( V_21 < 0 )
break;
}
return V_21 ;
}
T_7 F_97 ( struct V_19 * V_48 , const char * V_187 , T_3 V_59 , int V_188 )
{
struct V_49 * V_50 = V_48 -> V_50 ;
int V_129 ;
while ( 1 ) {
if ( V_50 -> V_189 -> V_190 == V_191 ||
V_50 -> V_189 -> V_190 == V_192 ) {
#ifdef F_98
F_74 ( V_48 -> V_20 ,
L_12 ,
V_50 -> V_189 -> V_190 == V_191 ?
L_13 : L_14 ) ;
#endif
V_129 = F_94 ( V_48 ) ;
if ( V_129 < 0 )
break;
}
V_129 = F_99 ( V_48 , ( void * ) V_187 , true ,
V_59 , V_188 ) ;
if ( V_129 != - V_193 && V_129 != - V_194 )
break;
if ( V_50 -> V_189 -> V_190 == V_195 )
return - V_140 ;
}
return V_129 ;
}
T_7 F_100 ( struct V_19 * V_48 , char * V_187 , T_3 V_59 , int V_188 )
{
struct V_49 * V_50 = V_48 -> V_50 ;
T_7 V_184 ;
int V_129 ;
while ( 1 ) {
if ( V_50 -> V_189 -> V_190 == V_191 ||
V_50 -> V_189 -> V_190 == V_192 ) {
#ifdef F_98
F_74 ( V_48 -> V_20 ,
L_15 ,
V_50 -> V_189 -> V_190 == V_191 ?
L_13 : L_14 ) ;
#endif
V_129 = F_83 ( V_48 , V_196 , NULL ) ;
if ( V_129 < 0 )
break;
} else if ( V_50 -> V_189 -> V_190 == V_197 ) {
V_129 = F_94 ( V_48 ) ;
if ( V_129 < 0 )
break;
}
V_129 = F_96 ( V_48 , & V_184 ) ;
if ( V_129 < 0 )
break;
V_129 = F_99 ( V_48 , ( void * ) V_187 , true ,
V_59 , V_188 ) ;
if ( V_129 == - V_193 ) {
if ( V_50 -> V_189 -> V_190 == V_198 ) {
V_129 = F_83 ( V_48 , V_154 , NULL ) ;
if ( V_129 < 0 )
break;
}
continue;
}
if ( V_129 != - V_194 )
break;
}
return V_129 ;
}
T_7 F_101 ( struct V_19 * V_48 , void * * V_199 , T_3 V_59 )
{
struct V_49 * V_50 = V_48 -> V_50 ;
int V_129 ;
while ( 1 ) {
if ( V_50 -> V_189 -> V_190 == V_191 ||
V_50 -> V_189 -> V_190 == V_192 ) {
#ifdef F_98
F_74 ( V_48 -> V_20 ,
L_16 ,
V_50 -> V_189 -> V_190 == V_191 ?
L_13 : L_14 ) ;
#endif
V_129 = F_94 ( V_48 ) ;
if ( V_129 < 0 )
break;
}
V_129 = F_102 ( V_48 , V_199 , V_59 ) ;
if ( V_129 != - V_193 && V_129 != - V_194 )
break;
if ( V_50 -> V_189 -> V_190 == V_195 )
return - V_140 ;
}
return V_129 ;
}
T_7 F_103 ( struct V_19 * V_48 , void * * V_199 , T_3 V_59 )
{
struct V_49 * V_50 = V_48 -> V_50 ;
int V_129 ;
while ( 1 ) {
if ( V_50 -> V_189 -> V_190 == V_191 ||
V_50 -> V_189 -> V_190 == V_192 ) {
#ifdef F_98
F_74 ( V_48 -> V_20 ,
L_17 ,
V_50 -> V_189 -> V_190 == V_191 ?
L_13 : L_14 ) ;
#endif
V_129 = F_83 ( V_48 , V_196 , NULL ) ;
if ( V_129 < 0 )
break;
} else if ( V_50 -> V_189 -> V_190 == V_197 ) {
V_129 = F_94 ( V_48 ) ;
if ( V_129 < 0 )
break;
}
V_129 = F_104 ( V_48 , V_199 , V_59 ) ;
if ( V_129 != - V_193 && V_129 != - V_194 )
break;
}
return V_129 ;
}
static T_6 F_105 ( struct V_19 * V_48 , const char * V_200 , T_5 V_61 , int V_188 )
{
struct V_49 * V_50 = V_48 -> V_50 ;
T_7 V_59 , V_201 ;
#ifdef F_79
if ( V_50 -> V_54 . V_55 ) {
struct V_202 * V_149 ;
T_5 V_203 = ( V_50 -> V_54 . V_55 -> V_204 * V_50 -> V_54 . V_55 -> V_205 . V_149 ) / 8 ;
if ( ! V_188 ) {
if ( F_106 ( V_50 -> V_54 . V_169 , ( const char V_143 V_206 * ) V_200 , V_61 ) )
return - V_207 ;
V_200 = V_50 -> V_54 . V_169 ;
}
V_59 = V_61 / V_203 ;
V_201 = F_107 ( V_48 , ( char * ) V_200 , V_59 , & V_149 ) ;
if ( V_201 < 0 )
return V_201 ;
V_201 = F_108 ( V_48 , V_149 , V_201 ) ;
if ( V_201 <= 0 )
return V_201 ;
V_61 = V_201 * V_203 ;
} else
#endif
{
V_59 = F_54 ( V_50 , V_61 ) ;
V_201 = F_97 ( V_48 , V_200 , V_59 , V_188 ) ;
if ( V_201 <= 0 )
return V_201 ;
V_61 = F_51 ( V_50 , V_201 ) ;
}
return V_61 ;
}
static T_6 F_109 ( struct V_19 * V_48 , const char V_206 * V_200 , T_5 V_61 )
{
T_5 V_208 = 0 ;
T_6 V_209 ;
struct V_49 * V_50 = V_48 -> V_50 ;
if ( F_64 ( & V_48 -> V_111 ) )
return - V_210 ;
if ( ( V_209 = F_95 ( V_48 ) ) < 0 )
return V_209 ;
F_110 ( & V_50 -> V_54 . V_139 ) ;
while ( V_61 > 0 ) {
if ( V_61 < V_50 -> V_54 . V_123 || V_50 -> V_54 . V_171 > 0 ) {
V_209 = V_61 ;
if ( V_209 + V_50 -> V_54 . V_171 > V_50 -> V_54 . V_123 )
V_209 = V_50 -> V_54 . V_123 - V_50 -> V_54 . V_171 ;
if ( V_209 > 0 ) {
if ( F_106 ( V_50 -> V_54 . V_169 + V_50 -> V_54 . V_171 , V_200 , V_209 ) ) {
V_209 = - V_207 ;
goto V_21;
}
}
V_50 -> V_54 . V_171 += V_209 ;
V_200 += V_209 ;
V_61 -= V_209 ;
V_208 += V_209 ;
if ( V_48 -> V_54 . V_113 . V_211 ||
V_50 -> V_54 . V_171 == V_50 -> V_54 . V_123 ) {
V_209 = F_105 ( V_48 , V_50 -> V_54 . V_169 + V_50 -> V_54 . V_183 ,
V_50 -> V_54 . V_171 - V_50 -> V_54 . V_183 , 1 ) ;
if ( V_209 <= 0 )
goto V_21;
V_50 -> V_54 . V_61 += V_209 ;
V_50 -> V_54 . V_183 += V_209 ;
V_50 -> V_54 . V_183 %= V_50 -> V_54 . V_123 ;
if ( V_50 -> V_54 . V_183 == 0 ||
V_50 -> V_54 . V_183 == V_50 -> V_54 . V_171 )
V_50 -> V_54 . V_171 = 0 ;
else if ( ( V_48 -> V_212 & V_213 ) != 0 ) {
V_209 = - V_140 ;
goto V_21;
}
}
} else {
V_209 = F_105 ( V_48 ,
( const char V_143 * ) V_200 ,
V_50 -> V_54 . V_123 , 0 ) ;
if ( V_209 <= 0 )
goto V_21;
V_50 -> V_54 . V_61 += V_209 ;
V_200 += V_209 ;
V_61 -= V_209 ;
V_208 += V_209 ;
if ( ( V_48 -> V_212 & V_213 ) != 0 &&
V_209 != V_50 -> V_54 . V_123 )
break;
}
}
F_92 ( & V_50 -> V_54 . V_139 ) ;
return V_208 ;
V_21:
F_92 ( & V_50 -> V_54 . V_139 ) ;
return V_208 > 0 ? ( T_7 ) V_208 : V_209 ;
}
static T_6 F_111 ( struct V_19 * V_48 , char * V_200 , T_5 V_61 , int V_188 )
{
struct V_49 * V_50 = V_48 -> V_50 ;
T_7 V_59 , V_201 ;
#ifdef F_79
char V_206 * V_214 = ( char V_143 V_206 * ) V_200 ;
if ( V_50 -> V_54 . V_55 ) {
struct V_202 * V_149 ;
T_5 V_203 = ( V_50 -> V_54 . V_56 -> V_215 * V_50 -> V_54 . V_56 -> V_216 . V_149 ) / 8 ;
if ( ! V_188 )
V_200 = V_50 -> V_54 . V_169 ;
V_59 = V_61 / V_203 ;
V_201 = F_107 ( V_48 , V_200 , V_59 , & V_149 ) ;
if ( V_201 < 0 )
return V_201 ;
V_201 = F_112 ( V_48 , V_149 , V_201 ) ;
if ( V_201 <= 0 )
return V_201 ;
V_61 = V_201 * V_203 ;
if ( ! V_188 && F_113 ( V_214 , V_200 , V_61 ) )
return - V_207 ;
} else
#endif
{
V_59 = F_54 ( V_50 , V_61 ) ;
V_201 = F_100 ( V_48 , V_200 , V_59 , V_188 ) ;
if ( V_201 <= 0 )
return V_201 ;
V_61 = F_51 ( V_50 , V_201 ) ;
}
return V_61 ;
}
static T_6 F_114 ( struct V_19 * V_48 , char V_206 * V_200 , T_5 V_61 )
{
T_5 V_208 = 0 ;
T_6 V_209 ;
struct V_49 * V_50 = V_48 -> V_50 ;
if ( F_64 ( & V_48 -> V_111 ) )
return - V_210 ;
if ( ( V_209 = F_95 ( V_48 ) ) < 0 )
return V_209 ;
F_110 ( & V_50 -> V_54 . V_139 ) ;
while ( V_61 > 0 ) {
if ( V_61 < V_50 -> V_54 . V_123 || V_50 -> V_54 . V_171 > 0 ) {
if ( V_50 -> V_54 . V_171 == 0 ) {
V_209 = F_111 ( V_48 , V_50 -> V_54 . V_169 , V_50 -> V_54 . V_123 , 1 ) ;
if ( V_209 <= 0 )
goto V_21;
V_50 -> V_54 . V_61 += V_209 ;
V_50 -> V_54 . V_183 = V_209 ;
V_50 -> V_54 . V_171 = V_209 ;
}
V_209 = V_61 ;
if ( ( T_5 ) V_209 > V_50 -> V_54 . V_171 )
V_209 = V_50 -> V_54 . V_171 ;
if ( F_113 ( V_200 , V_50 -> V_54 . V_169 + ( V_50 -> V_54 . V_183 - V_50 -> V_54 . V_171 ) , V_209 ) ) {
V_209 = - V_207 ;
goto V_21;
}
V_200 += V_209 ;
V_61 -= V_209 ;
V_208 += V_209 ;
V_50 -> V_54 . V_171 -= V_209 ;
} else {
V_209 = F_111 ( V_48 , ( char V_143 * ) V_200 ,
V_50 -> V_54 . V_123 , 0 ) ;
if ( V_209 <= 0 )
goto V_21;
V_50 -> V_54 . V_61 += V_209 ;
V_200 += V_209 ;
V_61 -= V_209 ;
V_208 += V_209 ;
}
}
F_92 ( & V_50 -> V_54 . V_139 ) ;
return V_208 ;
V_21:
F_92 ( & V_50 -> V_54 . V_139 ) ;
return V_208 > 0 ? ( T_7 ) V_208 : V_209 ;
}
static int F_115 ( struct V_174 * V_175 )
{
struct V_19 * V_48 ;
struct V_49 * V_50 ;
int V_2 ;
for ( V_2 = 0 ; V_2 < 2 ; V_2 ++ ) {
V_48 = V_175 -> V_179 [ V_2 ] ;
if ( ! V_48 )
continue;
V_50 = V_48 -> V_50 ;
F_83 ( V_48 , V_154 , NULL ) ;
V_50 -> V_54 . V_170 = 1 ;
V_50 -> V_54 . V_171 = 0 ;
V_50 -> V_54 . V_182 = 0 ;
V_50 -> V_54 . V_183 = 0 ;
}
return 0 ;
}
static int F_116 ( struct V_174 * V_175 )
{
struct V_19 * V_48 ;
int V_21 ;
V_48 = V_175 -> V_179 [ V_153 ] ;
if ( V_48 != NULL ) {
if ( ( V_21 = F_95 ( V_48 ) ) < 0 )
return V_21 ;
F_83 ( V_48 , V_217 , NULL ) ;
}
return 0 ;
}
static int F_117 ( struct V_19 * V_48 , T_5 V_218 )
{
struct V_49 * V_50 ;
T_6 V_219 = 0 ;
T_8 V_190 ;
long V_220 ;
T_9 V_221 ;
V_50 = V_48 -> V_50 ;
F_118 ( & V_221 , V_222 ) ;
F_119 ( & V_50 -> V_223 , & V_221 ) ;
#ifdef F_98
F_74 ( V_48 -> V_20 , L_18 , V_218 ) ;
#endif
while ( 1 ) {
V_219 = F_105 ( V_48 , V_50 -> V_54 . V_169 , V_218 , 1 ) ;
if ( V_219 > 0 ) {
V_50 -> V_54 . V_171 = 0 ;
V_219 = 0 ;
break;
}
if ( V_219 != 0 && V_219 != - V_140 )
break;
V_219 = 0 ;
F_120 ( V_224 ) ;
F_121 ( V_48 ) ;
V_190 = V_50 -> V_189 -> V_190 ;
F_122 ( V_48 ) ;
if ( V_190 != V_225 ) {
F_120 ( V_226 ) ;
break;
}
V_220 = F_123 ( 10 * V_227 ) ;
if ( F_124 ( V_222 ) ) {
V_219 = - V_228 ;
break;
}
if ( V_220 == 0 ) {
F_125 ( V_48 -> V_20 ,
L_19 ) ;
V_219 = - V_180 ;
break;
}
}
F_126 ( & V_50 -> V_223 , & V_221 ) ;
return V_219 ;
}
static int F_127 ( struct V_174 * V_175 )
{
int V_21 = 0 ;
unsigned int V_229 ;
struct V_19 * V_48 ;
struct V_49 * V_50 ;
T_4 V_66 ;
unsigned long V_230 ;
T_5 V_218 ;
V_48 = V_175 -> V_179 [ V_153 ] ;
if ( V_48 != NULL ) {
V_50 = V_48 -> V_50 ;
if ( F_64 ( & V_48 -> V_111 ) )
goto V_231;
if ( ( V_21 = F_95 ( V_48 ) ) < 0 )
return V_21 ;
V_66 = F_56 ( V_50 -> V_54 . V_66 ) ;
V_230 = F_59 ( V_66 ) ;
F_110 ( & V_50 -> V_54 . V_139 ) ;
if ( V_50 -> V_54 . V_171 > 0 ) {
#ifdef F_98
F_74 ( V_48 -> V_20 , L_20 ) ;
#endif
V_218 = ( 8 * ( V_50 -> V_54 . V_123 - V_50 -> V_54 . V_171 ) + 7 ) / V_230 ;
F_90 ( V_66 ,
V_50 -> V_54 . V_169 + V_50 -> V_54 . V_171 ,
V_218 ) ;
V_21 = F_117 ( V_48 , V_50 -> V_54 . V_123 ) ;
if ( V_21 < 0 ) {
F_92 ( & V_50 -> V_54 . V_139 ) ;
return V_21 ;
}
} else if ( V_50 -> V_54 . V_183 > 0 ) {
#ifdef F_98
F_74 ( V_48 -> V_20 , L_21 ) ;
#endif
V_218 = V_50 -> V_54 . V_123 - V_50 -> V_54 . V_183 ;
F_90 ( V_66 ,
V_50 -> V_54 . V_169 ,
V_218 * 8 / V_230 ) ;
V_21 = F_117 ( V_48 , V_218 ) ;
if ( V_21 < 0 ) {
F_92 ( & V_50 -> V_54 . V_139 ) ;
return V_21 ;
}
}
V_218 = V_50 -> V_232 -> V_233 % V_50 -> V_114 ;
if ( V_218 > 0 ) {
V_218 = V_50 -> V_114 - V_218 ;
if ( V_50 -> V_234 == V_145 )
F_128 ( V_48 , NULL , V_218 ) ;
else if ( V_50 -> V_234 == V_146 )
F_129 ( V_48 , NULL , V_218 ) ;
}
F_92 ( & V_50 -> V_54 . V_139 ) ;
V_231:
V_229 = V_48 -> V_212 ;
V_48 -> V_212 &= ~ V_213 ;
V_21 = F_83 ( V_48 , V_196 , NULL ) ;
V_48 -> V_212 = V_229 ;
if ( V_21 < 0 )
return V_21 ;
V_50 -> V_54 . V_170 = 1 ;
}
V_48 = V_175 -> V_179 [ V_159 ] ;
if ( V_48 != NULL ) {
if ( ( V_21 = F_95 ( V_48 ) ) < 0 )
return V_21 ;
V_50 = V_48 -> V_50 ;
V_21 = F_83 ( V_48 , V_154 , NULL ) ;
if ( V_21 < 0 )
return V_21 ;
V_50 -> V_54 . V_171 = 0 ;
V_50 -> V_54 . V_170 = 1 ;
}
return 0 ;
}
static int F_130 ( struct V_174 * V_175 , int V_127 )
{
int V_177 ;
for ( V_177 = 1 ; V_177 >= 0 ; -- V_177 ) {
struct V_19 * V_48 = V_175 -> V_179 [ V_177 ] ;
struct V_49 * V_50 ;
if ( V_48 == NULL )
continue;
V_50 = V_48 -> V_50 ;
if ( V_127 < 1000 )
V_127 = 1000 ;
else if ( V_127 > 192000 )
V_127 = 192000 ;
if ( V_50 -> V_54 . V_127 != V_127 ) {
V_50 -> V_54 . V_13 = 1 ;
V_50 -> V_54 . V_127 = V_127 ;
}
}
return F_131 ( V_175 ) ;
}
static int F_131 ( struct V_174 * V_175 )
{
struct V_19 * V_48 ;
int V_21 ;
if ( ( V_21 = F_93 ( V_175 , & V_48 ) ) < 0 )
return V_21 ;
return V_48 -> V_50 -> V_54 . V_127 ;
}
static int F_132 ( struct V_174 * V_175 , unsigned int V_149 )
{
int V_177 ;
if ( V_149 < 1 )
V_149 = 1 ;
if ( V_149 > 128 )
return - V_6 ;
for ( V_177 = 1 ; V_177 >= 0 ; -- V_177 ) {
struct V_19 * V_48 = V_175 -> V_179 [ V_177 ] ;
struct V_49 * V_50 ;
if ( V_48 == NULL )
continue;
V_50 = V_48 -> V_50 ;
if ( V_50 -> V_54 . V_149 != V_149 ) {
V_50 -> V_54 . V_13 = 1 ;
V_50 -> V_54 . V_149 = V_149 ;
}
}
return F_133 ( V_175 ) ;
}
static int F_133 ( struct V_174 * V_175 )
{
struct V_19 * V_48 ;
int V_21 ;
if ( ( V_21 = F_93 ( V_175 , & V_48 ) ) < 0 )
return V_21 ;
return V_48 -> V_50 -> V_54 . V_149 ;
}
static int F_134 ( struct V_174 * V_175 )
{
struct V_19 * V_48 ;
int V_21 ;
if ( ( V_21 = F_93 ( V_175 , & V_48 ) ) < 0 )
return V_21 ;
return V_48 -> V_50 -> V_54 . V_123 ;
}
static int F_135 ( struct V_174 * V_175 )
{
struct V_19 * V_48 ;
int V_21 ;
int V_134 ;
struct V_12 * V_13 ;
unsigned int V_235 = 0 ;
const struct V_16 * V_236 ;
int V_237 ;
if ( ( V_21 = F_93 ( V_175 , & V_48 ) ) < 0 )
return V_21 ;
if ( F_64 ( & V_48 -> V_111 ) )
V_134 = 1 ;
else
V_134 = V_48 -> V_54 . V_113 . V_134 ;
if ( ! V_134 )
return V_67 | V_73 |
V_75 | V_77 |
V_79 | V_81 |
V_83 |
V_87 | V_89 |
V_91 | V_93 |
V_95 ;
V_13 = F_34 ( sizeof( * V_13 ) , V_43 ) ;
if ( ! V_13 )
return - V_44 ;
F_72 ( V_13 ) ;
V_21 = F_21 ( V_48 , V_13 ) ;
V_236 = F_10 ( V_13 , V_150 ) ;
F_35 ( V_13 ) ;
if ( V_21 < 0 )
return V_21 ;
for ( V_237 = 0 ; V_237 < 32 ; ++ V_237 ) {
if ( F_76 ( V_236 , V_237 ) ) {
int V_238 = F_57 ( V_237 ) ;
if ( V_238 >= 0 )
V_235 |= V_238 ;
}
}
return V_235 ;
}
static int F_136 ( struct V_174 * V_175 , int V_66 )
{
int V_235 , V_177 ;
if ( V_66 != V_239 ) {
V_235 = F_135 ( V_175 ) ;
if ( V_235 < 0 )
return V_235 ;
if ( ! ( V_235 & V_66 ) )
V_66 = V_73 ;
for ( V_177 = 1 ; V_177 >= 0 ; -- V_177 ) {
struct V_19 * V_48 = V_175 -> V_179 [ V_177 ] ;
struct V_49 * V_50 ;
if ( V_48 == NULL )
continue;
V_50 = V_48 -> V_50 ;
if ( V_50 -> V_54 . V_66 != V_66 ) {
V_50 -> V_54 . V_13 = 1 ;
V_50 -> V_54 . V_66 = V_66 ;
}
}
}
return F_137 ( V_175 ) ;
}
static int F_137 ( struct V_174 * V_175 )
{
struct V_19 * V_48 ;
int V_21 ;
if ( ( V_21 = F_93 ( V_175 , & V_48 ) ) < 0 )
return V_21 ;
return V_48 -> V_50 -> V_54 . V_66 ;
}
static int F_138 ( struct V_19 * V_48 , int V_240 )
{
struct V_49 * V_50 ;
if ( V_48 == NULL )
return 0 ;
V_50 = V_48 -> V_50 ;
if ( V_240 == 0 ) {
V_240 = V_50 -> V_54 . V_118 ;
if ( V_240 == 0 )
V_240 = 1 ;
return V_240 ;
}
if ( V_50 -> V_54 . V_118 || V_50 -> V_54 . V_115 )
return - V_6 ;
if ( V_240 != 1 && V_240 != 2 && V_240 != 4 &&
V_240 != 8 && V_240 != 16 )
return - V_6 ;
V_50 -> V_54 . V_118 = V_240 ;
V_50 -> V_54 . V_13 = 1 ;
return V_240 ;
}
static int F_139 ( struct V_174 * V_175 , int V_240 )
{
int V_21 = - V_6 , V_177 ;
for ( V_177 = 1 ; V_177 >= 0 ; -- V_177 ) {
struct V_19 * V_48 = V_175 -> V_179 [ V_177 ] ;
if ( V_48 == NULL )
continue;
if ( ( V_21 = F_138 ( V_48 , V_240 ) ) < 0 )
return V_21 ;
}
return V_21 ;
}
static int F_140 ( struct V_19 * V_48 , unsigned int V_9 )
{
struct V_49 * V_50 ;
if ( V_48 == NULL )
return 0 ;
V_50 = V_48 -> V_50 ;
if ( V_50 -> V_54 . V_118 || V_50 -> V_54 . V_115 )
return - V_6 ;
V_50 -> V_54 . V_115 = V_9 & 0xffff ;
V_50 -> V_54 . V_122 = ( V_9 >> 16 ) & 0xffff ;
if ( V_50 -> V_54 . V_115 < 4 )
V_50 -> V_54 . V_115 = 4 ;
if ( V_50 -> V_54 . V_122 < 2 )
V_50 -> V_54 . V_122 = 2 ;
V_50 -> V_54 . V_13 = 1 ;
return 0 ;
}
static int F_141 ( struct V_174 * V_175 , unsigned int V_9 )
{
int V_21 = - V_6 , V_177 ;
for ( V_177 = 1 ; V_177 >= 0 ; -- V_177 ) {
struct V_19 * V_48 = V_175 -> V_179 [ V_177 ] ;
if ( V_48 == NULL )
continue;
if ( ( V_21 = F_140 ( V_48 , V_9 ) ) < 0 )
return V_21 ;
}
return V_21 ;
}
static int F_142 ( struct V_241 * V_241 )
{
F_143 ( & V_241 -> V_242 ) ;
V_241 -> V_212 |= V_213 ;
F_144 ( & V_241 -> V_242 ) ;
return 0 ;
}
static int F_145 ( struct V_19 * V_48 , int V_220 )
{
if ( V_48 == NULL ) {
V_220 &= ~ V_243 ;
return V_220 ;
}
#ifdef F_146
if ( V_48 -> V_152 == V_153 )
if ( V_48 -> V_244 -> V_245 > 1 )
V_220 |= F_146 ;
#endif
#if F_147 ( V_246 ) && 0
{
struct V_49 * V_50 = V_48 -> V_50 ;
if ( V_50 -> V_247 & ( V_248 | V_249 ) )
V_220 &= ~ V_246 ;
}
#endif
return V_220 ;
}
static int F_148 ( struct V_174 * V_175 )
{
int V_219 , V_177 ;
V_219 = V_250 | V_251 | V_243 | V_246 ;
for ( V_177 = 0 ; V_177 < 2 ; V_177 ++ ) {
struct V_19 * V_48 = V_175 -> V_179 [ V_177 ] ;
V_219 = F_145 ( V_48 , V_219 ) ;
}
V_219 |= 0x0001 ;
return V_219 ;
}
static void F_149 ( struct V_19 * V_48 ,
T_3 V_252 )
{
struct V_49 * V_50 = V_48 -> V_50 ;
T_3 V_233 ;
V_233 = V_252 + V_50 -> V_60 ;
V_233 %= V_50 -> V_158 ;
V_50 -> V_232 -> V_233 = V_233 ;
}
static int F_150 ( struct V_174 * V_175 , int V_156 )
{
struct V_49 * V_50 ;
struct V_19 * V_253 = NULL , * V_254 = NULL ;
int V_21 , V_255 ;
#ifdef F_98
F_74 ( V_48 -> V_20 , L_22 , V_156 ) ;
#endif
V_253 = V_175 -> V_179 [ V_153 ] ;
V_254 = V_175 -> V_179 [ V_159 ] ;
if ( V_253 ) {
if ( ( V_21 = F_95 ( V_253 ) ) < 0 )
return V_21 ;
}
if ( V_254 ) {
if ( ( V_21 = F_95 ( V_254 ) ) < 0 )
return V_21 ;
}
if ( V_253 ) {
V_50 = V_253 -> V_50 ;
if ( V_156 & V_256 ) {
if ( V_50 -> V_54 . V_156 )
goto V_257;
if ( F_64 ( & V_253 -> V_111 ) )
F_149 ( V_253 ,
F_55 ( V_50 ) ) ;
V_50 -> V_54 . V_156 = 1 ;
V_50 -> V_157 = 1 ;
V_255 = V_217 ;
} else {
if ( ! V_50 -> V_54 . V_156 )
goto V_257;
V_50 -> V_54 . V_156 = 0 ;
V_50 -> V_157 = V_50 -> V_158 ;
V_255 = V_154 ;
V_50 -> V_54 . V_170 = 1 ;
}
V_21 = F_83 ( V_253 , V_255 , NULL ) ;
if ( V_21 < 0 )
return V_21 ;
}
V_257:
if ( V_254 ) {
V_50 = V_254 -> V_50 ;
if ( V_156 & V_258 ) {
if ( V_50 -> V_54 . V_156 )
goto V_259;
V_50 -> V_54 . V_156 = 1 ;
V_50 -> V_157 = 1 ;
V_255 = V_217 ;
} else {
if ( ! V_50 -> V_54 . V_156 )
goto V_259;
V_50 -> V_54 . V_156 = 0 ;
V_50 -> V_157 = V_50 -> V_158 ;
V_255 = V_154 ;
V_50 -> V_54 . V_170 = 1 ;
}
V_21 = F_83 ( V_254 , V_255 , NULL ) ;
if ( V_21 < 0 )
return V_21 ;
}
V_259:
return 0 ;
}
static int F_151 ( struct V_174 * V_175 )
{
struct V_19 * V_253 = NULL , * V_254 = NULL ;
int V_219 = 0 ;
V_253 = V_175 -> V_179 [ V_153 ] ;
V_254 = V_175 -> V_179 [ V_159 ] ;
if ( V_253 && V_253 -> V_50 && V_253 -> V_50 -> V_54 . V_156 )
V_219 |= V_256 ;
if ( V_254 && V_254 -> V_50 && V_254 -> V_50 -> V_54 . V_156 )
V_219 |= V_258 ;
return V_219 ;
}
static int F_152 ( struct V_174 * V_175 )
{
struct V_19 * V_48 ;
struct V_49 * V_50 ;
T_7 V_184 ;
int V_21 ;
V_48 = V_175 -> V_179 [ V_153 ] ;
if ( V_48 == NULL )
return - V_6 ;
if ( ( V_21 = F_95 ( V_48 ) ) < 0 )
return V_21 ;
V_50 = V_48 -> V_50 ;
if ( V_50 -> V_54 . V_13 || V_50 -> V_54 . V_170 )
return 0 ;
V_21 = F_83 ( V_48 , V_185 , & V_184 ) ;
if ( V_21 == - V_193 )
V_184 = 0 ;
else if ( V_21 < 0 )
return V_21 ;
return F_49 ( V_48 , V_184 ) ;
}
static int F_153 ( struct V_174 * V_175 , int V_152 , struct V_260 V_206 * V_261 )
{
struct V_19 * V_48 ;
struct V_49 * V_50 ;
T_7 V_184 ;
int V_262 ;
struct V_260 V_247 ;
int V_21 ;
if ( V_261 == NULL )
return - V_207 ;
V_48 = V_175 -> V_179 [ V_152 ] ;
if ( V_48 == NULL )
return - V_6 ;
if ( ( V_21 = F_95 ( V_48 ) ) < 0 )
return V_21 ;
V_50 = V_48 -> V_50 ;
if ( V_50 -> V_54 . V_13 || V_50 -> V_54 . V_170 ) {
memset ( & V_247 , 0 , sizeof( V_247 ) ) ;
if ( F_113 ( V_261 , & V_247 , sizeof( V_247 ) ) )
return - V_207 ;
return 0 ;
}
if ( V_152 == V_153 ) {
V_21 = F_83 ( V_48 , V_185 , & V_184 ) ;
if ( V_21 == - V_193 || V_21 == - V_194 || ( ! V_21 && V_184 < 0 ) ) {
V_21 = 0 ;
V_184 = 0 ;
V_262 = 0 ;
} else {
V_262 = V_50 -> V_54 . V_171 ;
}
} else {
V_21 = F_96 ( V_48 , & V_184 ) ;
V_262 = - V_50 -> V_54 . V_171 ;
}
if ( V_21 < 0 )
return V_21 ;
V_247 . V_187 = F_49 ( V_48 , V_50 -> V_189 -> V_252 % V_50 -> V_60 ) ;
if ( F_64 ( & V_48 -> V_111 ) ) {
T_7 V_136 ;
V_184 = F_55 ( V_50 ) ;
V_136 = V_184 - V_50 -> V_54 . V_182 ;
if ( V_136 < 0 )
V_136 += V_50 -> V_158 ;
V_247 . V_263 = V_136 / V_50 -> V_114 ;
V_50 -> V_54 . V_182 = V_184 ;
if ( V_48 -> V_152 == V_153 )
F_149 ( V_48 , V_184 ) ;
V_247 . V_61 = F_49 ( V_48 , V_50 -> V_189 -> V_252 ) & V_42 ;
} else {
V_184 = F_49 ( V_48 , V_184 ) ;
if ( V_152 == V_153 ) {
if ( V_48 -> V_54 . V_113 . V_264 )
V_247 . V_263 = ( V_50 -> V_54 . V_62 - V_184 - V_262 ) / V_50 -> V_54 . V_123 ;
else
V_247 . V_263 = ( V_184 + V_262 ) / V_50 -> V_54 . V_123 ;
V_247 . V_61 = ( V_50 -> V_54 . V_61 - V_184 ) & V_42 ;
} else {
V_184 += V_262 ;
V_247 . V_263 = V_184 / V_50 -> V_54 . V_123 ;
V_247 . V_61 = ( V_50 -> V_54 . V_61 + V_184 ) & V_42 ;
}
}
if ( F_113 ( V_261 , & V_247 , sizeof( V_247 ) ) )
return - V_207 ;
return 0 ;
}
static int F_154 ( struct V_174 * V_175 , int V_152 , struct V_265 V_206 * V_261 )
{
struct V_19 * V_48 ;
struct V_49 * V_50 ;
T_7 V_266 ;
int V_262 ;
struct V_265 V_247 ;
int V_21 ;
if ( V_261 == NULL )
return - V_207 ;
V_48 = V_175 -> V_179 [ V_152 ] ;
if ( V_48 == NULL )
return - V_6 ;
V_50 = V_48 -> V_50 ;
if ( V_50 -> V_54 . V_13 &&
( V_21 = F_68 ( V_48 , false ) ) < 0 )
return V_21 ;
V_247 . V_267 = V_50 -> V_54 . V_123 ;
V_247 . V_268 = V_50 -> V_120 ;
if ( V_50 -> V_54 . V_170 ) {
if ( V_152 == V_153 ) {
V_247 . V_61 = V_50 -> V_54 . V_123 * V_50 -> V_54 . V_120 ;
V_247 . V_269 = V_50 -> V_54 . V_120 ;
} else {
V_247 . V_61 = 0 ;
V_247 . V_269 = 0 ;
}
} else {
if ( V_152 == V_153 ) {
V_21 = F_83 ( V_48 , V_185 , & V_266 ) ;
if ( V_21 == - V_193 || V_21 == - V_194 || ( ! V_21 && V_266 < 0 ) ) {
V_266 = V_50 -> V_60 ;
V_21 = 0 ;
V_262 = 0 ;
} else {
V_266 = V_50 -> V_60 - V_266 ;
V_262 = - V_50 -> V_54 . V_171 ;
}
} else {
V_21 = F_96 ( V_48 , & V_266 ) ;
V_262 = V_50 -> V_54 . V_171 ;
}
if ( V_21 < 0 )
return V_21 ;
V_247 . V_61 = F_49 ( V_48 , V_266 ) + V_262 ;
V_247 . V_269 = V_247 . V_61 / V_50 -> V_54 . V_123 ;
}
#ifdef F_98
F_74 ( V_48 -> V_20 ,
L_23 ,
V_247 . V_61 , V_247 . V_269 , V_247 . V_268 , V_247 . V_267 ) ;
#endif
if ( F_113 ( V_261 , & V_247 , sizeof( V_247 ) ) )
return - V_207 ;
return 0 ;
}
static int F_155 ( struct V_174 * V_175 , int V_152 , struct V_270 V_206 * V_261 )
{
return - V_6 ;
}
static const char * F_156 ( const char * V_271 )
{
const char * V_187 , * V_272 = NULL ;
for ( V_187 = V_271 ; * V_187 ; V_187 ++ ) {
if ( * V_187 == '/' )
V_272 = V_187 + 1 ;
}
return V_272 ;
}
static void F_157 ( struct V_273 * V_20 , int V_152 ,
const char * V_274 ,
struct V_275 * V_276 )
{
struct V_275 * V_113 ;
F_110 ( & V_20 -> V_179 [ V_152 ] . V_54 . V_277 ) ;
do {
for ( V_113 = V_20 -> V_179 [ V_152 ] . V_54 . V_278 ; V_113 ;
V_113 = V_113 -> V_53 ) {
if ( ! strcmp ( V_113 -> V_274 , V_274 ) )
goto V_279;
}
} while ( ( V_274 = F_156 ( V_274 ) ) != NULL );
V_279:
if ( V_113 )
* V_276 = * V_113 ;
F_92 ( & V_20 -> V_179 [ V_152 ] . V_54 . V_277 ) ;
}
static void F_158 ( struct V_19 * V_48 )
{
struct V_49 * V_50 ;
V_50 = V_48 -> V_50 ;
F_88 ( V_50 -> V_54 . V_169 ) ;
V_50 -> V_54 . V_169 = NULL ;
#ifdef F_79
F_45 ( V_48 ) ;
#endif
V_48 -> V_54 . V_54 = 0 ;
}
static void F_159 ( struct V_19 * V_48 ,
struct V_275 * V_113 ,
int V_280 )
{
struct V_49 * V_50 ;
V_48 -> V_54 . V_54 = 1 ;
V_48 -> V_54 . V_113 = * V_113 ;
if ( V_113 -> V_281 )
V_48 -> V_212 |= V_213 ;
else if ( V_113 -> V_282 )
V_48 -> V_212 &= ~ V_213 ;
V_50 = V_48 -> V_50 ;
V_50 -> V_54 . V_13 = 1 ;
V_50 -> V_54 . V_156 = 1 ;
V_50 -> V_54 . V_127 = 8000 ;
F_160 ( & V_50 -> V_54 . V_139 ) ;
switch ( F_161 ( V_280 ) ) {
case V_283 :
V_50 -> V_54 . V_66 = V_73 ;
break;
case V_284 :
V_50 -> V_54 . V_66 = V_75 ;
break;
default:
V_50 -> V_54 . V_66 = V_67 ;
}
V_50 -> V_54 . V_149 = 1 ;
V_50 -> V_54 . V_115 = 0 ;
V_50 -> V_54 . V_122 = 0 ;
V_50 -> V_54 . V_118 = 0 ;
V_48 -> V_285 = F_158 ;
}
static int F_162 ( struct V_174 * V_175 )
{
int V_286 ;
if ( ! V_175 )
return 0 ;
for ( V_286 = 0 ; V_286 < 2 ; ++ V_286 ) {
struct V_19 * V_48 = V_175 -> V_179 [ V_286 ] ;
if ( V_48 )
F_163 ( V_48 ) ;
}
F_35 ( V_175 ) ;
return 0 ;
}
static int F_164 ( struct V_241 * V_241 ,
struct V_273 * V_20 ,
struct V_174 * * V_287 ,
int V_280 ,
struct V_275 * V_113 )
{
int V_177 , V_21 ;
struct V_174 * V_175 ;
struct V_19 * V_48 ;
T_10 V_288 = V_241 -> V_288 ;
if ( V_287 )
* V_287 = NULL ;
V_175 = F_71 ( sizeof( * V_175 ) , V_43 ) ;
if ( V_175 == NULL )
return - V_44 ;
if ( ( V_288 & ( V_289 | V_290 ) ) == ( V_289 | V_290 ) &&
( V_20 -> V_291 & V_292 ) )
V_288 = V_289 ;
V_241 -> V_212 &= ~ V_293 ;
for ( V_177 = 0 ; V_177 < 2 ; V_177 ++ ) {
if ( V_113 [ V_177 ] . V_294 )
continue;
if ( ! V_20 -> V_179 [ V_177 ] . V_245 )
continue;
if ( V_177 == V_153 ) {
if ( ! ( V_288 & V_289 ) )
continue;
} else {
if ( ! ( V_288 & V_290 ) )
continue;
}
V_21 = F_165 ( V_20 , V_177 , V_241 , & V_48 ) ;
if ( V_21 < 0 ) {
F_162 ( V_175 ) ;
return V_21 ;
}
V_175 -> V_179 [ V_177 ] = V_48 ;
V_48 -> V_241 = V_175 ;
F_159 ( V_48 , & V_113 [ V_177 ] , V_280 ) ;
}
if ( ! V_175 -> V_179 [ 0 ] && ! V_175 -> V_179 [ 1 ] ) {
F_162 ( V_175 ) ;
return - V_6 ;
}
V_241 -> V_295 = V_175 ;
if ( V_287 )
* V_287 = V_175 ;
return 0 ;
}
static int F_166 ( struct V_296 * V_297 , char * V_298 , T_5 V_218 )
{
unsigned int V_177 ;
if ( F_38 ( ! V_297 || ! V_298 || V_218 < 2 ) )
return - V_6 ;
for ( V_177 = 0 ; V_177 < sizeof( V_297 -> V_299 ) && V_177 + 1 < V_218 ; V_177 ++ )
V_298 [ V_177 ] = V_297 -> V_299 [ V_177 ] ;
V_298 [ V_177 ] = '\0' ;
return 0 ;
}
static int F_167 ( struct V_300 * V_300 , struct V_241 * V_241 )
{
int V_21 ;
char V_274 [ 32 ] ;
struct V_273 * V_20 ;
struct V_174 * V_175 ;
struct V_275 V_113 [ 2 ] ;
int V_281 ;
T_9 V_221 ;
V_21 = F_168 ( V_300 , V_241 ) ;
if ( V_21 < 0 )
return V_21 ;
V_20 = F_169 ( F_170 ( V_300 ) ,
V_301 ) ;
if ( V_20 == NULL ) {
V_21 = - V_302 ;
goto V_303;
}
V_21 = F_171 ( V_20 -> V_304 , V_241 ) ;
if ( V_21 < 0 )
goto V_303;
if ( ! F_172 ( V_20 -> V_304 -> V_305 ) ) {
V_21 = - V_207 ;
goto V_306;
}
if ( F_166 ( V_222 , V_274 , sizeof( V_274 ) ) < 0 ) {
V_21 = - V_207 ;
goto V_307;
}
memset ( V_113 , 0 , sizeof( V_113 ) ) ;
if ( V_241 -> V_288 & V_289 )
F_157 ( V_20 , V_153 ,
V_274 , & V_113 [ 0 ] ) ;
if ( V_241 -> V_288 & V_290 )
F_157 ( V_20 , V_159 ,
V_274 , & V_113 [ 1 ] ) ;
V_281 = ! ! ( V_241 -> V_212 & V_213 ) ;
if ( ! V_281 )
V_281 = V_308 ;
F_118 ( & V_221 , V_222 ) ;
F_119 ( & V_20 -> V_309 , & V_221 ) ;
F_110 ( & V_20 -> V_310 ) ;
while ( 1 ) {
V_21 = F_164 ( V_241 , V_20 , & V_175 ,
F_170 ( V_300 ) , V_113 ) ;
if ( V_21 >= 0 )
break;
if ( V_21 == - V_140 ) {
if ( V_281 ) {
V_21 = - V_311 ;
break;
}
} else
break;
F_120 ( V_224 ) ;
F_92 ( & V_20 -> V_310 ) ;
F_173 () ;
F_110 ( & V_20 -> V_310 ) ;
if ( V_20 -> V_304 -> V_312 ) {
V_21 = - V_302 ;
break;
}
if ( F_124 ( V_222 ) ) {
V_21 = - V_228 ;
break;
}
}
F_126 ( & V_20 -> V_309 , & V_221 ) ;
F_92 ( & V_20 -> V_310 ) ;
if ( V_21 < 0 )
goto V_307;
F_174 ( V_20 -> V_304 ) ;
return V_21 ;
V_307:
F_175 ( V_20 -> V_304 -> V_305 ) ;
V_306:
F_176 ( V_20 -> V_304 , V_241 ) ;
V_303:
if ( V_20 )
F_174 ( V_20 -> V_304 ) ;
return V_21 ;
}
static int F_177 ( struct V_300 * V_300 , struct V_241 * V_241 )
{
struct V_273 * V_20 ;
struct V_19 * V_48 ;
struct V_174 * V_175 ;
V_175 = V_241 -> V_295 ;
V_48 = V_175 -> V_179 [ V_153 ] ;
if ( V_48 == NULL )
V_48 = V_175 -> V_179 [ V_159 ] ;
if ( F_38 ( ! V_48 ) )
return - V_210 ;
V_20 = V_48 -> V_20 ;
if ( ! V_20 -> V_304 -> V_312 )
F_127 ( V_175 ) ;
F_110 ( & V_20 -> V_310 ) ;
F_162 ( V_175 ) ;
F_92 ( & V_20 -> V_310 ) ;
F_178 ( & V_20 -> V_309 ) ;
F_175 ( V_20 -> V_304 -> V_305 ) ;
F_176 ( V_20 -> V_304 , V_241 ) ;
return 0 ;
}
static long F_179 ( struct V_241 * V_241 , unsigned int V_255 , unsigned long V_313 )
{
struct V_174 * V_175 ;
int V_206 * V_314 = ( int V_206 * ) V_313 ;
int V_220 ;
V_175 = V_241 -> V_295 ;
if ( V_255 == V_315 )
return F_180 ( V_316 , V_314 ) ;
if ( V_255 == V_317 )
return F_180 ( 1 , V_314 ) ;
#if F_181 ( V_318 )
if ( ( ( V_255 >> 8 ) & 0xff ) == 'M' ) {
struct V_19 * V_48 ;
int V_177 ;
for ( V_177 = 0 ; V_177 < 2 ; ++ V_177 ) {
V_48 = V_175 -> V_179 [ V_177 ] ;
if ( V_48 != NULL )
break;
}
if ( F_38 ( V_177 >= 2 ) )
return - V_210 ;
return F_182 ( V_48 -> V_20 -> V_304 , V_255 , V_313 ) ;
}
#endif
if ( ( ( V_255 >> 8 ) & 0xff ) != 'P' )
return - V_6 ;
#ifdef F_98
F_183 ( L_24 , V_255 ) ;
#endif
switch ( V_255 ) {
case V_319 :
return F_115 ( V_175 ) ;
case V_320 :
return F_127 ( V_175 ) ;
case V_321 :
if ( F_184 ( V_220 , V_314 ) )
return - V_207 ;
if ( ( V_220 = F_130 ( V_175 , V_220 ) ) < 0 )
return V_220 ;
return F_180 ( V_220 , V_314 ) ;
case V_322 :
V_220 = F_131 ( V_175 ) ;
if ( V_220 < 0 )
return V_220 ;
return F_180 ( V_220 , V_314 ) ;
case V_323 :
if ( F_184 ( V_220 , V_314 ) )
return - V_207 ;
V_220 = V_220 > 0 ? 2 : 1 ;
if ( ( V_220 = F_132 ( V_175 , V_220 ) ) < 0 )
return V_220 ;
return F_180 ( -- V_220 , V_314 ) ;
case V_324 :
V_220 = F_134 ( V_175 ) ;
if ( V_220 < 0 )
return V_220 ;
return F_180 ( V_220 , V_314 ) ;
case V_325 :
if ( F_184 ( V_220 , V_314 ) )
return - V_207 ;
V_220 = F_136 ( V_175 , V_220 ) ;
if ( V_220 < 0 )
return V_220 ;
return F_180 ( V_220 , V_314 ) ;
case V_326 :
V_220 = F_137 ( V_175 ) ;
if ( V_220 < 0 )
return V_220 ;
return F_180 ( V_220 , V_314 ) ;
case V_327 :
if ( F_184 ( V_220 , V_314 ) )
return - V_207 ;
V_220 = F_132 ( V_175 , V_220 ) ;
if ( V_220 < 0 )
return V_220 ;
return F_180 ( V_220 , V_314 ) ;
case V_328 :
V_220 = F_133 ( V_175 ) ;
if ( V_220 < 0 )
return V_220 ;
return F_180 ( V_220 , V_314 ) ;
case V_329 :
case V_330 :
return - V_180 ;
case V_331 :
return F_116 ( V_175 ) ;
case V_332 :
if ( F_184 ( V_220 , V_314 ) )
return - V_207 ;
V_220 = F_139 ( V_175 , V_220 ) ;
if ( V_220 < 0 )
return V_220 ;
return F_180 ( V_220 , V_314 ) ;
case V_333 :
if ( F_184 ( V_220 , V_314 ) )
return - V_207 ;
return F_141 ( V_175 , V_220 ) ;
case V_334 :
V_220 = F_135 ( V_175 ) ;
if ( V_220 < 0 )
return V_220 ;
return F_180 ( V_220 , V_314 ) ;
case V_335 :
case V_336 :
return F_154 ( V_175 ,
V_255 == V_336 ?
V_159 : V_153 ,
(struct V_265 V_206 * ) V_313 ) ;
case V_337 :
return F_142 ( V_241 ) ;
case V_338 :
V_220 = F_148 ( V_175 ) ;
if ( V_220 < 0 )
return V_220 ;
return F_180 ( V_220 , V_314 ) ;
case V_339 :
V_220 = F_151 ( V_175 ) ;
if ( V_220 < 0 )
return V_220 ;
return F_180 ( V_220 , V_314 ) ;
case V_340 :
if ( F_184 ( V_220 , V_314 ) )
return - V_207 ;
return F_150 ( V_175 , V_220 ) ;
case V_341 :
case V_342 :
return F_153 ( V_175 ,
V_255 == V_341 ?
V_159 : V_153 ,
(struct V_260 V_206 * ) V_313 ) ;
case V_343 :
case V_344 :
return F_155 ( V_175 ,
V_255 == V_343 ?
V_159 : V_153 ,
(struct V_270 V_206 * ) V_313 ) ;
case V_345 :
return 0 ;
case V_346 :
if ( F_148 ( V_175 ) & V_243 )
return 0 ;
return - V_180 ;
case V_347 :
V_220 = F_152 ( V_175 ) ;
if ( V_220 < 0 ) {
F_180 ( 0 , V_314 ) ;
return V_220 ;
}
return F_180 ( V_220 , V_314 ) ;
case V_348 :
return 0 ;
default:
F_183 ( L_25 , V_255 ) ;
}
return - V_6 ;
}
static long F_185 ( struct V_241 * V_241 , unsigned int V_255 ,
unsigned long V_313 )
{
return F_179 ( V_241 , V_255 , ( unsigned long ) F_186 ( V_313 ) ) ;
}
static T_6 F_187 ( struct V_241 * V_241 , char V_206 * V_200 , T_5 V_349 , T_11 * V_350 )
{
struct V_174 * V_175 ;
struct V_19 * V_48 ;
V_175 = V_241 -> V_295 ;
V_48 = V_175 -> V_179 [ V_159 ] ;
if ( V_48 == NULL )
return - V_210 ;
V_48 -> V_212 = V_241 -> V_212 & V_213 ;
#ifndef F_98
return F_114 ( V_48 , V_200 , V_349 ) ;
#else
{
T_6 V_220 = F_114 ( V_48 , V_200 , V_349 ) ;
F_74 ( V_48 -> V_20 ,
L_26 ,
( long ) V_349 , ( long ) V_220 ) ;
return V_220 ;
}
#endif
}
static T_6 F_188 ( struct V_241 * V_241 , const char V_206 * V_200 , T_5 V_349 , T_11 * V_350 )
{
struct V_174 * V_175 ;
struct V_19 * V_48 ;
long V_219 ;
V_175 = V_241 -> V_295 ;
V_48 = V_175 -> V_179 [ V_153 ] ;
if ( V_48 == NULL )
return - V_210 ;
V_48 -> V_212 = V_241 -> V_212 & V_213 ;
V_219 = F_109 ( V_48 , V_200 , V_349 ) ;
#ifdef F_98
F_74 ( V_48 -> V_20 , L_27 ,
( long ) V_349 , ( long ) V_219 ) ;
#endif
return V_219 ;
}
static int F_189 ( struct V_19 * V_48 )
{
struct V_49 * V_50 = V_48 -> V_50 ;
if ( F_64 ( & V_48 -> V_111 ) )
return V_50 -> V_54 . V_182 !=
F_55 ( V_50 ) ;
else
return F_190 ( V_50 ) >=
V_50 -> V_54 . V_124 ;
}
static int F_191 ( struct V_19 * V_48 )
{
struct V_49 * V_50 = V_48 -> V_50 ;
if ( F_64 ( & V_48 -> V_111 ) )
return V_50 -> V_54 . V_182 !=
F_55 ( V_50 ) ;
else
return F_192 ( V_50 ) >=
V_50 -> V_54 . V_124 ;
}
static unsigned int F_193 ( struct V_241 * V_241 , T_12 * V_221 )
{
struct V_174 * V_175 ;
unsigned int V_138 ;
struct V_19 * V_253 = NULL , * V_254 = NULL ;
V_175 = V_241 -> V_295 ;
V_253 = V_175 -> V_179 [ V_153 ] ;
V_254 = V_175 -> V_179 [ V_159 ] ;
V_138 = 0 ;
if ( V_253 != NULL ) {
struct V_49 * V_50 = V_253 -> V_50 ;
F_194 ( V_241 , & V_50 -> V_223 , V_221 ) ;
F_121 ( V_253 ) ;
if ( V_50 -> V_189 -> V_190 != V_198 &&
( V_50 -> V_189 -> V_190 != V_225 ||
F_189 ( V_253 ) ) )
V_138 |= V_351 | V_352 ;
F_122 ( V_253 ) ;
}
if ( V_254 != NULL ) {
struct V_49 * V_50 = V_254 -> V_50 ;
T_8 V_353 ;
F_194 ( V_241 , & V_50 -> V_223 , V_221 ) ;
F_121 ( V_254 ) ;
if ( ( V_353 = V_50 -> V_189 -> V_190 ) != V_225 ||
F_191 ( V_254 ) )
V_138 |= V_354 | V_355 ;
F_122 ( V_254 ) ;
if ( V_353 != V_225 && V_50 -> V_54 . V_156 ) {
struct V_174 V_356 ;
memset ( & V_356 , 0 , sizeof( V_356 ) ) ;
V_356 . V_179 [ V_159 ] = V_175 -> V_179 [ V_159 ] ;
V_50 -> V_54 . V_156 = 0 ;
F_150 ( & V_356 , V_258 ) ;
}
}
return V_138 ;
}
static int F_195 ( struct V_241 * V_241 , struct V_357 * V_358 )
{
struct V_174 * V_175 ;
struct V_19 * V_48 = NULL ;
struct V_49 * V_50 ;
int V_21 ;
#ifdef F_98
F_183 ( L_28 ) ;
#endif
V_175 = V_241 -> V_295 ;
switch ( ( V_358 -> V_359 & ( V_360 | V_361 ) ) ) {
case V_360 | V_361 :
V_48 = V_175 -> V_179 [ V_153 ] ;
if ( V_48 )
break;
case V_360 :
V_48 = V_175 -> V_179 [ V_159 ] ;
break;
case V_361 :
V_48 = V_175 -> V_179 [ V_153 ] ;
break;
default:
return - V_6 ;
}
V_358 -> V_359 |= V_360 ;
if ( V_48 == NULL )
return - V_210 ;
V_50 = V_48 -> V_50 ;
if ( ! ( V_50 -> V_247 & V_362 ) )
return - V_180 ;
if ( V_50 -> V_247 & V_363 )
V_50 -> V_234 = V_144 ;
else
return - V_180 ;
if ( V_50 -> V_54 . V_13 ) {
V_21 = F_68 ( V_48 , true ) ;
if ( V_21 < 0 )
return V_21 ;
}
#ifdef F_79
if ( V_50 -> V_54 . V_55 != NULL )
return - V_180 ;
#endif
if ( V_358 -> V_364 != 0 )
return - V_6 ;
V_21 = F_196 ( V_48 , V_241 , V_358 ) ;
if ( V_21 < 0 )
return V_21 ;
V_50 -> V_54 . V_112 = V_358 -> V_365 - V_358 -> V_366 ;
V_50 -> V_166 = 0 ;
V_50 -> V_167 = 0 ;
#ifdef F_98
F_183 ( L_29 ,
V_50 -> V_54 . V_112 ) ;
#endif
V_50 -> V_160 = V_50 -> V_158 ;
return 0 ;
}
static void F_197 ( struct V_367 * V_368 ,
struct V_369 * V_169 )
{
struct V_370 * V_244 = V_368 -> V_295 ;
struct V_275 * V_113 = V_244 -> V_54 . V_278 ;
F_110 ( & V_244 -> V_54 . V_277 ) ;
while ( V_113 ) {
F_198 ( V_169 , L_30 ,
V_113 -> V_274 ,
V_113 -> V_120 ,
V_113 -> V_114 ,
V_113 -> V_294 ? L_31 : L_32 ,
V_113 -> V_134 ? L_33 : L_32 ,
V_113 -> V_282 ? L_34 : L_32 ,
V_113 -> V_281 ? L_35 : L_32 ,
V_113 -> V_211 ? L_36 : L_32 ,
V_113 -> V_165 ? L_37 : L_32 ) ;
V_113 = V_113 -> V_53 ;
}
F_92 ( & V_244 -> V_54 . V_277 ) ;
}
static void F_199 ( struct V_370 * V_244 )
{
struct V_275 * V_113 , * V_371 ;
for ( V_113 = V_244 -> V_54 . V_278 , V_244 -> V_54 . V_278 = NULL ;
V_113 ; V_113 = V_371 ) {
V_371 = V_113 -> V_53 ;
F_35 ( V_113 -> V_274 ) ;
F_35 ( V_113 ) ;
}
V_244 -> V_54 . V_278 = NULL ;
}
static void F_200 ( struct V_367 * V_368 ,
struct V_369 * V_169 )
{
struct V_370 * V_244 = V_368 -> V_295 ;
char line [ 128 ] , V_372 [ 32 ] , V_274 [ 32 ] ;
const char * V_187 ;
int V_373 ;
struct V_275 * V_113 , * V_374 , V_375 ;
while ( ! F_201 ( V_169 , line , sizeof( line ) ) ) {
F_110 ( & V_244 -> V_54 . V_277 ) ;
memset ( & V_375 , 0 , sizeof( V_375 ) ) ;
V_187 = F_202 ( V_274 , line , sizeof( V_274 ) ) ;
if ( ! strcmp ( V_274 , L_38 ) || ! strcmp ( V_274 , L_39 ) ) {
F_199 ( V_244 ) ;
F_92 ( & V_244 -> V_54 . V_277 ) ;
continue;
}
for ( V_113 = V_244 -> V_54 . V_278 ; V_113 ; V_113 = V_113 -> V_53 ) {
if ( ! strcmp ( V_113 -> V_274 , V_274 ) ) {
V_375 = * V_113 ;
break;
}
}
V_187 = F_202 ( V_372 , V_187 , sizeof( V_372 ) ) ;
V_375 . V_120 = F_203 ( V_372 , NULL , 10 ) ;
V_187 = F_202 ( V_372 , V_187 , sizeof( V_372 ) ) ;
V_375 . V_114 = F_203 ( V_372 , NULL , 10 ) ;
for ( V_373 = 31 ; V_373 >= 0 ; V_373 -- )
if ( V_375 . V_114 & ( 1 << V_373 ) )
break;
for ( V_373 -- ; V_373 >= 0 ; V_373 -- )
V_375 . V_114 &= ~ ( 1 << V_373 ) ;
do {
V_187 = F_202 ( V_372 , V_187 , sizeof( V_372 ) ) ;
if ( ! strcmp ( V_372 , L_40 ) ) {
V_375 . V_294 = 1 ;
} else if ( ! strcmp ( V_372 , L_41 ) ) {
V_375 . V_134 = 1 ;
} else if ( ! strcmp ( V_372 , L_42 ) ) {
V_375 . V_282 = 1 ;
} else if ( ! strcmp ( V_372 , L_43 ) ) {
V_375 . V_281 = 1 ;
} else if ( ! strcmp ( V_372 , L_44 ) ) {
V_375 . V_211 = 1 ;
} else if ( ! strcmp ( V_372 , L_45 ) ) {
V_375 . V_165 = 1 ;
} else if ( ! strcmp ( V_372 , L_46 ) ) {
V_375 . V_264 = 1 ;
}
} while ( * V_372 );
if ( V_113 == NULL ) {
V_113 = F_34 ( sizeof( * V_113 ) , V_43 ) ;
if ( ! V_113 ) {
V_169 -> error = - V_44 ;
F_92 ( & V_244 -> V_54 . V_277 ) ;
return;
}
if ( V_244 -> V_54 . V_278 == NULL )
V_244 -> V_54 . V_278 = V_113 ;
else {
for ( V_374 = V_244 -> V_54 . V_278 ;
V_374 -> V_53 ; V_374 = V_374 -> V_53 ) ;
V_374 -> V_53 = V_113 ;
}
V_375 . V_274 = F_204 ( V_274 , V_43 ) ;
if ( ! V_375 . V_274 ) {
F_35 ( V_113 ) ;
V_169 -> error = - V_44 ;
F_92 ( & V_244 -> V_54 . V_277 ) ;
return;
}
}
* V_113 = V_375 ;
F_92 ( & V_244 -> V_54 . V_277 ) ;
}
}
static void F_205 ( struct V_273 * V_20 )
{
int V_152 ;
for ( V_152 = 0 ; V_152 < 2 ; ++ V_152 ) {
struct V_367 * V_368 ;
struct V_370 * V_244 = & V_20 -> V_179 [ V_152 ] ;
if ( V_244 -> V_245 == 0 )
continue;
if ( ( V_368 = F_206 ( V_20 -> V_304 , L_47 , V_244 -> V_376 ) ) != NULL ) {
V_368 -> V_377 = V_378 ;
V_368 -> V_379 = V_380 | V_381 | V_382 ;
V_368 -> V_27 . V_383 . V_384 = F_197 ;
V_368 -> V_27 . V_383 . V_385 = F_200 ;
V_368 -> V_295 = V_244 ;
if ( F_207 ( V_368 ) < 0 ) {
F_208 ( V_368 ) ;
V_368 = NULL ;
}
}
V_244 -> V_54 . V_386 = V_368 ;
}
}
static void F_209 ( struct V_273 * V_20 )
{
int V_152 ;
for ( V_152 = 0 ; V_152 < 2 ; ++ V_152 ) {
struct V_370 * V_244 = & V_20 -> V_179 [ V_152 ] ;
F_208 ( V_244 -> V_54 . V_386 ) ;
V_244 -> V_54 . V_386 = NULL ;
F_199 ( V_244 ) ;
}
}
static void F_210 ( struct V_273 * V_20 , int V_387 )
{
if ( F_211 ( V_301 ,
V_20 -> V_304 , V_387 , & V_388 ,
V_20 ) < 0 ) {
F_125 ( V_20 , L_48 ,
V_20 -> V_304 -> V_389 , V_20 -> V_390 ) ;
}
}
static int F_212 ( struct V_273 * V_20 )
{
V_20 -> V_54 . V_391 = 0 ;
if ( V_392 [ V_20 -> V_304 -> V_389 ] == ( int ) V_20 -> V_390 ) {
char V_298 [ 128 ] ;
int V_393 ;
F_210 ( V_20 , 0 ) ;
V_393 = ( V_20 -> V_179 [ V_153 ] . V_245 > 0 &&
V_20 -> V_179 [ V_159 ] . V_245 &&
! ( V_20 -> V_291 & V_292 ) ) ;
sprintf ( V_298 , L_49 , V_20 -> V_298 , V_393 ? L_50 : L_32 ) ;
#ifdef F_213
F_214 ( F_213 ,
V_20 -> V_304 -> V_389 ,
V_298 ) ;
#endif
V_20 -> V_54 . V_391 ++ ;
V_20 -> V_54 . V_394 |= 1 ;
}
if ( V_395 [ V_20 -> V_304 -> V_389 ] == ( int ) V_20 -> V_390 ) {
F_210 ( V_20 , 1 ) ;
V_20 -> V_54 . V_391 ++ ;
V_20 -> V_54 . V_394 |= 2 ;
}
if ( V_20 -> V_54 . V_391 )
F_205 ( V_20 ) ;
return 0 ;
}
static int F_215 ( struct V_273 * V_20 )
{
if ( V_20 -> V_54 . V_391 ) {
if ( V_20 -> V_54 . V_394 & 1 ) {
V_20 -> V_54 . V_394 &= ~ 1 ;
F_216 ( V_301 ,
V_20 -> V_304 , 0 ) ;
}
if ( V_20 -> V_54 . V_394 & 2 ) {
V_20 -> V_54 . V_394 &= ~ 2 ;
F_216 ( V_301 ,
V_20 -> V_304 , 1 ) ;
}
if ( V_392 [ V_20 -> V_304 -> V_389 ] == ( int ) V_20 -> V_390 ) {
#ifdef F_213
F_217 ( F_213 , V_20 -> V_304 -> V_389 ) ;
#endif
}
V_20 -> V_54 . V_391 = 0 ;
}
return 0 ;
}
static int F_218 ( struct V_273 * V_20 )
{
F_215 ( V_20 ) ;
F_209 ( V_20 ) ;
return 0 ;
}
static int T_13 F_219 ( void )
{
int V_2 ;
int V_21 ;
for ( V_2 = 0 ; V_2 < V_396 ; V_2 ++ ) {
if ( V_392 [ V_2 ] < 0 || V_392 [ V_2 ] >= V_397 ) {
F_220 ( L_51 ,
V_2 , V_392 [ V_2 ] ) ;
V_392 [ V_2 ] = 0 ;
}
if ( V_395 [ V_2 ] < 0 || V_395 [ V_2 ] >= V_397 ) {
F_220 ( L_52 ,
V_2 , V_395 [ V_2 ] ) ;
V_395 [ V_2 ] = 1 ;
}
}
if ( ( V_21 = F_221 ( & V_398 , 0 ) ) < 0 )
return V_21 ;
return 0 ;
}
static void T_14 F_222 ( void )
{
F_221 ( & V_398 , 1 ) ;
}
