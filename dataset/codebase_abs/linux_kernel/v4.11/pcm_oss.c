static inline T_1 F_1 ( void )
{
T_1 V_1 = F_2 () ;
F_3 ( F_4 () ) ;
return V_1 ;
}
static inline void F_5 ( T_1 V_1 )
{
F_3 ( V_1 ) ;
}
static int F_6 ( struct V_2 * V_3 , unsigned int V_4 , int V_5 )
{
int V_6 = 0 ;
if ( V_3 -> V_4 < V_4 ) {
V_3 -> V_4 = V_4 ;
V_3 -> V_5 = V_5 ;
V_6 = 1 ;
} else if ( V_3 -> V_4 == V_4 && ! V_3 -> V_5 && V_5 ) {
V_3 -> V_5 = 1 ;
V_6 = 1 ;
}
if ( V_3 -> integer ) {
if ( V_3 -> V_5 ) {
V_3 -> V_4 ++ ;
V_3 -> V_5 = 0 ;
}
}
if ( F_7 ( V_3 ) ) {
F_8 ( V_3 ) ;
return - V_7 ;
}
return V_6 ;
}
static int F_9 ( struct V_2 * V_3 , unsigned int V_8 , int V_9 )
{
int V_6 = 0 ;
if ( V_3 -> V_8 > V_8 ) {
V_3 -> V_8 = V_8 ;
V_3 -> V_9 = V_9 ;
V_6 = 1 ;
} else if ( V_3 -> V_8 == V_8 && ! V_3 -> V_9 && V_9 ) {
V_3 -> V_9 = 1 ;
V_6 = 1 ;
}
if ( V_3 -> integer ) {
if ( V_3 -> V_9 ) {
V_3 -> V_8 -- ;
V_3 -> V_9 = 0 ;
}
}
if ( F_7 ( V_3 ) ) {
F_8 ( V_3 ) ;
return - V_7 ;
}
return V_6 ;
}
static int F_10 ( struct V_2 * V_3 , unsigned int V_10 )
{
struct V_2 V_11 ;
V_11 . V_12 = 0 ;
V_11 . V_4 = V_11 . V_8 = V_10 ;
V_11 . V_5 = V_11 . V_9 = 0 ;
V_11 . integer = 1 ;
return F_11 ( V_3 , & V_11 ) ;
}
static unsigned int
F_12 ( const struct V_13 * V_14 ,
T_2 V_15 , int * V_16 )
{
if ( F_13 ( V_15 ) ) {
if ( V_16 )
* V_16 = 0 ;
return F_14 ( F_15 ( V_14 , V_15 ) ) ;
}
if ( F_16 ( V_15 ) ) {
const struct V_2 * V_3 = F_17 ( V_14 , V_15 ) ;
if ( V_16 )
* V_16 = V_3 -> V_5 ;
return F_18 ( V_3 ) ;
}
return - V_7 ;
}
static unsigned int
F_19 ( const struct V_13 * V_14 ,
T_2 V_15 , int * V_16 )
{
if ( F_13 ( V_15 ) ) {
if ( V_16 )
* V_16 = 0 ;
return F_20 ( F_15 ( V_14 , V_15 ) ) ;
}
if ( F_16 ( V_15 ) ) {
const struct V_2 * V_3 = F_17 ( V_14 , V_15 ) ;
if ( V_16 )
* V_16 = - ( int ) V_3 -> V_9 ;
return F_21 ( V_3 ) ;
}
return - V_7 ;
}
static int F_22 ( struct V_13 * V_14 ,
T_2 V_15 ,
const struct V_17 * V_10 )
{
int V_6 ;
V_6 = F_23 ( F_24 ( V_14 , V_15 ) , V_10 ) ;
if ( V_6 ) {
V_14 -> V_18 |= 1 << V_15 ;
V_14 -> V_19 |= 1 << V_15 ;
}
return V_6 ;
}
static int F_25 ( struct V_20 * V_21 ,
struct V_13 * V_14 ,
T_2 V_15 ,
const struct V_17 * V_10 )
{
int V_6 = F_22 ( V_14 , V_15 , V_10 ) ;
if ( V_6 < 0 )
return V_6 ;
if ( V_14 -> V_19 ) {
int V_22 = F_26 ( V_21 , V_14 ) ;
if ( V_22 < 0 )
return V_22 ;
}
return 0 ;
}
static int F_27 ( struct V_13 * V_14 ,
T_2 V_15 , unsigned int V_10 ,
int V_16 )
{
int V_6 ;
int V_23 = 0 ;
if ( V_16 ) {
if ( V_16 > 0 ) {
V_23 = 1 ;
} else if ( V_16 < 0 ) {
if ( V_10 > 0 ) {
V_23 = 1 ;
V_10 -- ;
}
}
}
if ( F_13 ( V_15 ) )
V_6 = F_28 ( F_24 ( V_14 , V_15 ) ,
V_10 + ! ! V_23 ) ;
else if ( F_16 ( V_15 ) )
V_6 = F_6 ( F_29 ( V_14 , V_15 ) ,
V_10 , V_23 ) ;
else
return - V_7 ;
if ( V_6 ) {
V_14 -> V_18 |= 1 << V_15 ;
V_14 -> V_19 |= 1 << V_15 ;
}
return V_6 ;
}
static int F_30 ( struct V_20 * V_21 ,
struct V_13 * V_14 ,
T_2 V_15 , unsigned int V_10 ,
int * V_16 )
{
int V_6 = F_27 ( V_14 , V_15 , V_10 , V_16 ? * V_16 : 0 ) ;
if ( V_6 < 0 )
return V_6 ;
if ( V_14 -> V_19 ) {
int V_22 = F_26 ( V_21 , V_14 ) ;
if ( V_22 < 0 )
return V_22 ;
}
return F_12 ( V_14 , V_15 , V_16 ) ;
}
static int F_31 ( struct V_13 * V_14 ,
T_2 V_15 , unsigned int V_10 ,
int V_16 )
{
int V_6 ;
int V_23 = 0 ;
if ( V_16 ) {
if ( V_16 < 0 ) {
V_23 = 1 ;
} else if ( V_16 > 0 ) {
V_23 = 1 ;
V_10 ++ ;
}
}
if ( F_13 ( V_15 ) ) {
if ( V_10 == 0 && V_23 ) {
F_32 ( F_24 ( V_14 , V_15 ) ) ;
V_6 = - V_7 ;
} else
V_6 = F_33 ( F_24 ( V_14 , V_15 ) ,
V_10 - ! ! V_23 ) ;
} else if ( F_16 ( V_15 ) )
V_6 = F_9 ( F_29 ( V_14 , V_15 ) ,
V_10 , V_23 ) ;
else
return - V_7 ;
if ( V_6 ) {
V_14 -> V_18 |= 1 << V_15 ;
V_14 -> V_19 |= 1 << V_15 ;
}
return V_6 ;
}
static int F_34 ( struct V_20 * V_21 ,
struct V_13 * V_14 ,
T_2 V_15 , unsigned int V_10 ,
int * V_16 )
{
int V_6 = F_31 ( V_14 , V_15 , V_10 , V_16 ? * V_16 : 0 ) ;
if ( V_6 < 0 )
return V_6 ;
if ( V_14 -> V_19 ) {
int V_22 = F_26 ( V_21 , V_14 ) ;
if ( V_22 < 0 )
return V_22 ;
}
return F_19 ( V_14 , V_15 , V_16 ) ;
}
static int F_35 ( int V_24 , int V_25 ,
int V_26 , int V_27 ,
int * V_28 , int * V_29 )
{
V_25 = V_25 < 0 ? - 1 : ( V_25 > 0 ? 1 : 0 ) ;
V_27 = V_27 < 0 ? - 1 : ( V_27 > 0 ? 1 : 0 ) ;
* V_28 = V_24 - V_26 ;
* V_29 = V_25 - V_27 ;
if ( * V_29 == - 2 ) {
( * V_28 ) -- ;
} else if ( * V_29 == 2 ) {
( * V_28 ) ++ ;
}
return 0 ;
}
static int F_36 ( unsigned int V_24 , int V_25 ,
unsigned int V_26 , int V_27 )
{
if ( V_25 < 0 ) {
V_24 -- ;
V_25 = 1 ;
} else if ( V_25 > 0 )
V_25 = 1 ;
if ( V_27 < 0 ) {
V_26 -- ;
V_27 = 1 ;
} else if ( V_27 > 0 )
V_27 = 1 ;
return V_24 < V_26 || ( V_24 == V_26 && V_25 < V_27 ) ;
}
static int F_37 ( int V_4 , int V_30 ,
int V_31 , int V_32 ,
int V_8 , int V_33 )
{
int V_34 , V_35 ;
int V_36 , V_37 ;
F_35 ( V_31 , V_32 , V_4 , V_30 , & V_34 , & V_35 ) ;
F_35 ( V_8 , V_33 , V_31 , V_32 , & V_36 , & V_37 ) ;
return F_36 ( V_34 , V_35 , V_36 , V_37 ) ;
}
static int F_38 ( struct V_20 * V_21 ,
struct V_13 * V_14 ,
T_2 V_15 , unsigned int V_31 ,
int * V_16 )
{
struct V_13 * V_38 = NULL ;
int V_39 ;
unsigned int V_40 ;
int V_41 = 0 ;
int V_4 , V_8 ;
int V_30 , V_33 ;
int V_42 = V_16 ? * V_16 : 0 ;
if ( V_31 > V_43 )
V_31 = V_43 ;
V_4 = V_8 = V_31 ;
V_30 = V_33 = V_42 ;
if ( V_33 > 0 )
V_33 = 0 ;
else if ( V_33 == 0 )
V_33 = - 1 ;
else {
V_33 = 1 ;
V_8 -- ;
}
V_38 = F_39 ( sizeof( * V_38 ) , V_44 ) ;
if ( V_38 == NULL )
return - V_45 ;
* V_38 = * V_14 ;
V_40 = V_4 ;
V_4 = F_30 ( V_21 , V_14 , V_15 , V_4 , & V_30 ) ;
if ( V_4 >= 0 ) {
struct V_13 * V_46 ;
if ( V_8 < 0 )
goto V_47;
if ( ( unsigned int ) V_4 == V_40 && V_30 == V_42 )
goto V_47;
V_46 = F_39 ( sizeof( * V_46 ) , V_44 ) ;
if ( V_46 == NULL ) {
F_40 ( V_38 ) ;
return - V_45 ;
}
* V_46 = * V_38 ;
V_8 = F_34 ( V_21 , V_46 , V_15 , V_8 , & V_33 ) ;
if ( V_8 < 0 ) {
F_40 ( V_46 ) ;
goto V_47;
}
if ( F_37 ( V_8 , V_33 , V_31 , V_42 , V_4 , V_30 ) ) {
* V_14 = * V_46 ;
V_41 = 1 ;
}
F_40 ( V_46 ) ;
} else {
* V_14 = * V_38 ;
V_8 = F_34 ( V_21 , V_14 , V_15 , V_8 , & V_33 ) ;
if ( V_8 < 0 ) {
F_40 ( V_38 ) ;
return V_8 ;
}
V_41 = 1 ;
}
V_47:
F_40 ( V_38 ) ;
if ( V_41 )
V_39 = F_41 ( V_21 , V_14 , V_15 , V_16 ) ;
else
V_39 = F_42 ( V_21 , V_14 , V_15 , V_16 ) ;
F_43 ( V_39 < 0 ) ;
return V_39 ;
}
static int F_44 ( struct V_13 * V_14 ,
T_2 V_15 , unsigned int V_10 ,
int V_16 )
{
int V_6 ;
if ( F_13 ( V_15 ) ) {
struct V_17 * V_48 = F_24 ( V_14 , V_15 ) ;
if ( V_10 == 0 && V_16 < 0 ) {
V_6 = - V_7 ;
F_32 ( V_48 ) ;
} else {
if ( V_16 > 0 )
V_10 ++ ;
else if ( V_16 < 0 )
V_10 -- ;
V_6 = F_45 ( F_24 ( V_14 , V_15 ) , V_10 ) ;
}
} else if ( F_16 ( V_15 ) ) {
struct V_2 * V_3 = F_29 ( V_14 , V_15 ) ;
if ( V_10 == 0 && V_16 < 0 ) {
V_6 = - V_7 ;
F_8 ( V_3 ) ;
} else if ( V_16 == 0 )
V_6 = F_10 ( V_3 , V_10 ) ;
else {
struct V_2 V_11 ;
V_11 . V_5 = 1 ;
V_11 . V_9 = 1 ;
V_11 . V_12 = 0 ;
V_11 . integer = 0 ;
if ( V_16 < 0 ) {
V_11 . V_4 = V_10 - 1 ;
V_11 . V_8 = V_10 ;
} else {
V_11 . V_4 = V_10 ;
V_11 . V_8 = V_10 + 1 ;
}
V_6 = F_11 ( V_3 , & V_11 ) ;
}
} else
return - V_7 ;
if ( V_6 ) {
V_14 -> V_18 |= 1 << V_15 ;
V_14 -> V_19 |= 1 << V_15 ;
}
return V_6 ;
}
static int F_46 ( struct V_20 * V_21 ,
struct V_13 * V_14 ,
T_2 V_15 , unsigned int V_10 ,
int V_16 )
{
int V_6 = F_44 ( V_14 , V_15 , V_10 , V_16 ) ;
if ( V_6 < 0 )
return V_6 ;
if ( V_14 -> V_19 ) {
int V_22 = F_26 ( V_21 , V_14 ) ;
if ( V_22 < 0 )
return V_22 ;
}
return F_47 ( V_14 , V_15 , NULL ) ;
}
static int F_48 ( struct V_13 * V_14 ,
T_2 V_15 )
{
int V_6 ;
V_6 = F_49 ( F_29 ( V_14 , V_15 ) ) ;
if ( V_6 ) {
V_14 -> V_18 |= 1 << V_15 ;
V_14 -> V_19 |= 1 << V_15 ;
}
return V_6 ;
}
static int F_50 ( struct V_20 * V_49 )
{
struct V_50 * V_51 = V_49 -> V_51 ;
struct V_52 * V_53 , * V_54 ;
V_53 = V_51 -> V_55 . V_56 ;
while ( V_53 ) {
V_54 = V_53 -> V_54 ;
F_51 ( V_53 ) ;
V_53 = V_54 ;
}
V_51 -> V_55 . V_56 = V_51 -> V_55 . V_57 = NULL ;
return 0 ;
}
static int F_52 ( struct V_52 * V_53 )
{
struct V_50 * V_51 = V_53 -> V_58 -> V_51 ;
V_53 -> V_54 = V_51 -> V_55 . V_56 ;
V_53 -> V_59 = NULL ;
if ( V_51 -> V_55 . V_56 ) {
V_51 -> V_55 . V_56 -> V_59 = V_53 ;
V_51 -> V_55 . V_56 = V_53 ;
} else {
V_51 -> V_55 . V_57 =
V_51 -> V_55 . V_56 = V_53 ;
}
return 0 ;
}
int F_53 ( struct V_52 * V_53 )
{
struct V_50 * V_51 = V_53 -> V_58 -> V_51 ;
V_53 -> V_54 = NULL ;
V_53 -> V_59 = V_51 -> V_55 . V_57 ;
if ( V_51 -> V_55 . V_57 ) {
V_51 -> V_55 . V_57 -> V_54 = V_53 ;
V_51 -> V_55 . V_57 = V_53 ;
} else {
V_51 -> V_55 . V_57 =
V_51 -> V_55 . V_56 = V_53 ;
}
return 0 ;
}
static long F_54 ( struct V_20 * V_49 , long V_60 )
{
struct V_50 * V_51 = V_49 -> V_51 ;
long V_61 = F_55 ( V_49 ) ;
long V_62 = F_56 ( V_51 , V_60 ) ;
if ( V_61 == V_51 -> V_55 . V_63 )
return V_62 ;
#if V_64 >= 64
return V_51 -> V_55 . V_63 * V_62 / V_61 ;
#else
{
T_3 V_65 = ( T_3 ) V_51 -> V_55 . V_63 * ( T_3 ) V_62 ;
return F_57 ( V_65 , V_61 ) ;
}
#endif
}
static long F_58 ( struct V_20 * V_49 , long V_62 )
{
struct V_50 * V_51 = V_49 -> V_51 ;
long V_61 = F_55 ( V_49 ) ;
if ( V_61 == V_51 -> V_55 . V_63 )
return F_59 ( V_51 , V_62 ) ;
return F_59 ( V_51 , ( V_61 * V_62 ) / V_51 -> V_55 . V_63 ) ;
}
static inline
T_4 F_60 ( struct V_50 * V_51 )
{
return V_51 -> V_66 ;
}
static T_5 F_61 ( int V_67 )
{
switch ( V_67 ) {
case V_68 : return V_69 ;
case V_70 : return V_71 ;
case V_72 : return V_73 ;
case V_74 : return V_75 ;
case V_76 : return V_77 ;
case V_78 : return V_79 ;
case V_80 : return V_81 ;
case V_82 : return V_83 ;
case V_84 : return V_85 ;
case V_86 : return V_87 ;
case V_88 : return V_89 ;
case V_90 : return V_91 ;
case V_92 : return V_93 ;
case V_94 : return V_95 ;
case V_96 : return V_97 ;
case V_98 : return V_99 ;
case V_100 : return V_101 ;
default: return V_75 ;
}
}
static int F_62 ( T_5 V_67 )
{
switch ( V_67 ) {
case V_69 : return V_68 ;
case V_71 : return V_70 ;
case V_73 : return V_72 ;
case V_75 : return V_74 ;
case V_77 : return V_76 ;
case V_79 : return V_78 ;
case V_81 : return V_80 ;
case V_83 : return V_82 ;
case V_85 : return V_84 ;
case V_87 : return V_86 ;
case V_89 : return V_88 ;
case V_91 : return V_90 ;
case V_93 : return V_92 ;
case V_95 : return V_94 ;
case V_97 : return V_96 ;
case V_99 : return V_98 ;
case V_101 : return V_100 ;
default: return - V_7 ;
}
}
static int F_63 ( struct V_20 * V_49 ,
struct V_13 * V_102 ,
struct V_13 * V_103 )
{
T_6 V_104 ;
T_6 V_105 , V_106 , V_107 ;
T_6 V_108 , V_109 ;
struct V_50 * V_51 = V_49 -> V_51 ;
T_6 V_110 ;
V_110 = F_64 ( F_65 ( V_102 ) ) *
F_66 ( V_102 ) / 8 ;
V_105 = F_67 ( V_49 ,
F_19 ( V_103 , V_111 , NULL ) ) * V_110 ;
V_105 = F_68 ( V_105 ) ;
if ( F_69 ( & V_49 -> V_112 ) ) {
if ( V_105 > V_51 -> V_55 . V_113 )
V_105 = V_51 -> V_55 . V_113 ;
}
if ( V_49 -> V_55 . V_114 . V_115 > 16 )
V_106 = V_49 -> V_55 . V_114 . V_115 ;
else if ( V_51 -> V_55 . V_116 ) {
V_106 = 1 << V_51 -> V_55 . V_116 ;
if ( V_106 > V_105 / 2 )
V_106 = V_105 / 2 ;
} else {
int V_117 ;
T_6 V_118 = F_70 ( V_102 ) * F_64 ( F_65 ( V_102 ) ) * F_66 ( V_102 ) / 8 ;
V_106 = V_105 ;
do {
V_106 /= 2 ;
} while ( V_106 > V_118 );
if ( V_51 -> V_55 . V_119 == 0 ) {
V_117 = 4 ;
if ( V_106 / V_117 > 4096 )
V_117 *= 2 ;
if ( V_106 / V_117 < 4096 )
V_117 = 1 ;
} else
V_117 = V_51 -> V_55 . V_119 ;
V_106 /= V_117 ;
if ( V_106 < 16 )
V_106 = 16 ;
}
V_108 = F_67 ( V_49 ,
F_12 ( V_103 , V_120 , NULL ) ) ;
V_108 *= V_110 ;
V_108 = F_71 ( V_108 ) ;
if ( V_106 < V_108 )
V_106 = V_108 ;
V_109 = F_67 ( V_49 ,
F_19 ( V_103 , V_120 , NULL ) ) ;
V_109 *= V_110 ;
V_109 = F_68 ( V_109 ) ;
if ( V_106 > V_109 )
V_106 = V_109 ;
V_107 = V_105 / V_106 ;
if ( V_49 -> V_55 . V_114 . V_121 > 1 )
V_107 = V_49 -> V_55 . V_114 . V_121 ;
V_104 = F_19 ( V_103 , V_122 , NULL ) ;
if ( V_51 -> V_55 . V_123 && V_104 > V_51 -> V_55 . V_123 )
V_104 = V_51 -> V_55 . V_123 ;
if ( V_107 > V_104 )
V_107 = V_104 ;
V_104 = F_12 ( V_103 , V_122 , NULL ) ;
if ( V_104 < 2 )
V_104 = 2 ;
if ( V_107 < V_104 )
V_107 = V_104 ;
while ( V_106 * V_107 > V_105 )
V_106 /= 2 ;
if ( V_106 < 16 )
return - V_7 ;
V_51 -> V_55 . V_124 = V_106 ;
V_51 -> V_55 . V_125 = 1 ;
V_51 -> V_55 . V_121 = V_107 ;
return 0 ;
}
static int F_72 ( struct V_20 * V_49 ,
struct V_13 * V_14 , unsigned int V_126 )
{
struct V_2 * V_127 ;
struct V_13 * V_38 ;
unsigned int V_128 , V_59 ;
V_38 = F_39 ( sizeof( * V_38 ) , V_44 ) ;
if ( V_38 == NULL )
return - V_45 ;
* V_38 = * V_14 ;
V_127 = F_29 ( V_38 , V_129 ) ;
V_128 = V_126 ;
for (; ; ) {
if ( V_127 -> V_8 < V_128 || ( V_127 -> V_8 == V_128 && V_127 -> V_9 ) )
break;
if ( V_127 -> V_4 < V_128 || ( V_127 -> V_4 == V_128 && ! V_127 -> V_5 ) ) {
int V_130 ;
V_130 = F_46 ( V_49 , V_14 ,
V_129 ,
V_128 , 0 ) ;
if ( V_130 == ( int ) V_128 ) {
F_40 ( V_38 ) ;
return V_128 ;
}
* V_14 = * V_38 ;
}
V_59 = V_128 ;
V_128 += V_126 ;
if ( V_128 <= V_59 )
break;
}
F_40 ( V_38 ) ;
return F_38 ( V_49 , V_14 , V_129 , V_126 , NULL ) ;
}
static int F_73 ( struct V_20 * V_49 ,
bool V_131 )
{
struct V_50 * V_51 = V_49 -> V_51 ;
struct V_13 * V_14 , * V_132 ;
struct V_133 * V_134 ;
T_7 V_105 , V_106 ;
T_6 V_110 ;
int V_22 ;
int V_135 ;
T_5 V_67 , V_136 ;
int V_137 ;
struct V_17 V_138 ;
struct V_17 V_139 ;
if ( V_131 ) {
if ( ! ( F_74 ( & V_51 -> V_55 . V_140 ) ) )
return - V_141 ;
} else if ( F_75 ( & V_51 -> V_55 . V_140 ) )
return - V_142 ;
V_134 = F_76 ( sizeof( * V_134 ) , V_44 ) ;
V_14 = F_39 ( sizeof( * V_14 ) , V_44 ) ;
V_132 = F_39 ( sizeof( * V_132 ) , V_44 ) ;
if ( ! V_134 || ! V_14 || ! V_132 ) {
V_22 = - V_45 ;
goto V_143;
}
if ( F_69 ( & V_49 -> V_112 ) )
V_135 = 1 ;
else
V_135 = V_49 -> V_55 . V_114 . V_135 ;
F_77 ( V_132 ) ;
F_48 ( V_132 , V_122 ) ;
F_27 ( V_132 , V_122 , 2 , 0 ) ;
F_32 ( & V_139 ) ;
if ( F_69 ( & V_49 -> V_112 ) )
F_78 ( & V_139 , ( V_144 int ) V_145 ) ;
else {
F_78 ( & V_139 , ( V_144 int ) V_146 ) ;
if ( ! V_135 )
F_78 ( & V_139 , ( V_144 int ) V_147 ) ;
}
V_22 = F_25 ( V_49 , V_132 , V_148 , & V_139 ) ;
if ( V_22 < 0 ) {
F_79 ( V_49 -> V_21 , L_1 ) ;
V_22 = - V_7 ;
goto V_143;
}
F_72 ( V_49 , V_132 , V_51 -> V_55 . V_128 ) ;
F_38 ( V_49 , V_132 , V_149 , V_51 -> V_55 . V_150 , NULL ) ;
V_67 = F_61 ( V_51 -> V_55 . V_67 ) ;
V_138 = * F_24 ( V_132 , V_151 ) ;
if ( V_135 )
V_136 = V_67 ;
else
V_136 = F_80 ( V_67 , & V_138 ) ;
if ( ( V_144 int ) V_136 < 0 ||
! F_81 ( & V_138 , ( V_144 int ) V_136 ) ) {
for ( V_136 = ( V_144 T_5 ) 0 ;
( V_144 int ) V_136 <= ( V_144 int ) V_152 ;
V_136 = ( V_144 T_5 ) ( ( V_144 int ) V_136 + 1 ) ) {
if ( F_81 ( & V_138 , ( V_144 int ) V_136 ) &&
F_62 ( V_136 ) >= 0 )
break;
}
if ( ( V_144 int ) V_136 > ( V_144 int ) V_152 ) {
F_79 ( V_49 -> V_21 , L_2 ) ;
V_22 = - V_7 ;
goto V_143;
}
}
V_22 = F_44 ( V_132 , V_151 , ( V_144 int ) V_136 , 0 ) ;
if ( V_22 < 0 )
goto V_143;
if ( V_135 ) {
memcpy ( V_14 , V_132 , sizeof( * V_14 ) ) ;
} else {
F_77 ( V_14 ) ;
F_44 ( V_14 , V_148 ,
( V_144 int ) V_146 , 0 ) ;
F_44 ( V_14 , V_151 ,
( V_144 int ) F_61 ( V_51 -> V_55 . V_67 ) , 0 ) ;
F_44 ( V_14 , V_149 ,
V_51 -> V_55 . V_150 , 0 ) ;
F_44 ( V_14 , V_129 ,
V_51 -> V_55 . V_128 , 0 ) ;
F_82 ( L_3 ,
F_83 ( V_14 ) , F_65 ( V_14 ) ,
F_66 ( V_14 ) , F_70 ( V_14 ) ) ;
}
F_82 ( L_4 ,
F_83 ( V_132 ) , F_65 ( V_132 ) ,
F_66 ( V_132 ) , F_70 ( V_132 ) ) ;
V_110 = F_64 ( F_65 ( V_14 ) ) *
F_66 ( V_14 ) / 8 ;
#ifdef F_84
F_50 ( V_49 ) ;
if ( ! V_135 ) {
F_50 ( V_49 ) ;
if ( ( V_22 = F_85 ( V_49 ,
V_14 ,
V_132 ) ) < 0 ) {
F_79 ( V_49 -> V_21 ,
L_5 , V_22 ) ;
F_50 ( V_49 ) ;
goto V_143;
}
if ( V_51 -> V_55 . V_56 ) {
struct V_52 * V_53 ;
if ( ( V_22 = F_86 ( V_49 , V_132 , & V_53 ) ) < 0 ) {
F_79 ( V_49 -> V_21 ,
L_6 , V_22 ) ;
F_50 ( V_49 ) ;
goto V_143;
}
if ( V_49 -> V_153 == V_154 ) {
V_22 = F_53 ( V_53 ) ;
} else {
V_22 = F_52 ( V_53 ) ;
}
if ( V_22 < 0 ) {
F_50 ( V_49 ) ;
goto V_143;
}
}
}
#endif
V_22 = F_63 ( V_49 , V_14 , V_132 ) ;
if ( V_22 < 0 )
goto V_143;
V_137 = F_87 ( V_49 , V_51 -> V_55 . V_124 / V_110 ) ;
V_22 = F_38 ( V_49 , V_132 , V_120 , V_137 , NULL ) ;
if ( V_22 < 0 )
goto V_143;
V_22 = F_38 ( V_49 , V_132 , V_122 ,
V_51 -> V_55 . V_121 , NULL ) ;
if ( V_22 < 0 )
goto V_143;
F_88 ( V_49 , V_155 , NULL ) ;
if ( ( V_22 = F_88 ( V_49 , V_156 , V_132 ) ) < 0 ) {
F_79 ( V_49 -> V_21 , L_7 , V_22 ) ;
goto V_143;
}
if ( V_51 -> V_55 . V_157 ) {
V_134 -> V_158 = 1 ;
} else {
V_134 -> V_158 = V_51 -> V_159 ;
}
if ( F_69 ( & V_49 -> V_112 ) ||
V_49 -> V_153 == V_160 )
V_134 -> V_161 = V_51 -> V_159 ;
else
V_134 -> V_161 = V_51 -> V_61 ;
V_134 -> V_162 = V_163 ;
V_134 -> V_164 = 1 ;
V_134 -> V_165 = V_49 -> V_153 == V_154 ?
1 : V_51 -> V_115 ;
if ( F_69 ( & V_49 -> V_112 ) ||
V_49 -> V_55 . V_114 . V_166 ) {
V_134 -> V_167 = 0 ;
V_134 -> V_168 = 0 ;
} else {
T_4 V_60 ;
V_60 = V_51 -> V_115 + 16 ;
if ( V_60 > V_51 -> V_61 )
V_60 = V_51 -> V_61 ;
V_134 -> V_167 = V_60 ;
V_134 -> V_168 = V_60 ;
}
if ( ( V_22 = F_88 ( V_49 , V_169 , V_134 ) ) < 0 ) {
F_79 ( V_49 -> V_21 , L_8 , V_22 ) ;
goto V_143;
}
V_51 -> V_55 . V_121 = F_89 ( V_132 ) ;
V_106 = F_67 ( V_49 , F_90 ( V_132 ) ) ;
if ( V_106 < 0 ) {
V_22 = - V_7 ;
goto V_143;
}
#ifdef F_84
if ( V_51 -> V_55 . V_56 ) {
V_22 = F_91 ( V_49 , V_106 ) ;
if ( V_22 < 0 )
goto V_143;
}
#endif
V_106 *= V_110 ;
V_105 = V_106 * V_51 -> V_55 . V_121 ;
if ( V_105 < 0 ) {
V_22 = - V_7 ;
goto V_143;
}
V_51 -> V_55 . V_124 = V_106 ;
V_51 -> V_55 . V_63 = V_105 ;
F_82 ( L_9 ,
V_51 -> V_55 . V_124 ,
V_51 -> V_55 . V_63 ) ;
F_82 ( L_10 ,
F_90 ( V_132 ) ,
F_92 ( V_132 ) ) ;
V_51 -> V_55 . V_67 = F_62 ( F_65 ( V_14 ) ) ;
V_51 -> V_55 . V_150 = F_66 ( V_14 ) ;
V_51 -> V_55 . V_128 = F_70 ( V_14 ) ;
F_93 ( V_51 -> V_55 . V_170 ) ;
V_51 -> V_55 . V_170 = F_94 ( V_51 -> V_55 . V_124 ) ;
if ( ! V_51 -> V_55 . V_170 ) {
V_22 = - V_45 ;
goto V_143;
}
V_51 -> V_55 . V_14 = 0 ;
V_51 -> V_55 . V_171 = 1 ;
V_51 -> V_55 . V_172 = 0 ;
if ( V_51 -> V_173 )
F_95 ( V_51 -> V_67 , V_51 -> V_173 , F_96 ( V_51 , V_51 -> V_174 ) ) ;
V_51 -> V_55 . V_125 = F_58 ( V_49 , V_106 ) ;
V_22 = 0 ;
V_143:
F_40 ( V_134 ) ;
F_40 ( V_14 ) ;
F_40 ( V_132 ) ;
F_97 ( & V_51 -> V_55 . V_140 ) ;
return V_22 ;
}
static int F_98 ( struct V_175 * V_176 , struct V_20 * * V_177 )
{
int V_178 , V_22 ;
struct V_20 * V_179 = NULL , * V_49 ;
for ( V_178 = 0 ; V_178 < 2 ; V_178 ++ ) {
V_49 = V_176 -> V_180 [ V_178 ] ;
if ( V_49 == NULL )
continue;
if ( V_179 == NULL )
V_179 = V_49 ;
if ( V_49 -> V_51 -> V_55 . V_14 ) {
V_22 = F_73 ( V_49 , false ) ;
if ( V_22 < 0 )
return V_22 ;
}
}
if ( ! V_179 )
return - V_181 ;
if ( V_177 )
* V_177 = V_179 ;
return 0 ;
}
static int F_99 ( struct V_20 * V_49 )
{
int V_22 ;
struct V_50 * V_51 = V_49 -> V_51 ;
V_22 = F_88 ( V_49 , V_182 , NULL ) ;
if ( V_22 < 0 ) {
F_79 ( V_49 -> V_21 ,
L_11 ) ;
return V_22 ;
}
V_51 -> V_55 . V_171 = 0 ;
V_51 -> V_55 . V_183 = 0 ;
V_51 -> V_55 . V_184 = 0 ;
V_51 -> V_55 . V_172 = 0 ;
return 0 ;
}
static int F_100 ( struct V_20 * V_49 )
{
struct V_50 * V_51 ;
int V_22 ;
if ( V_49 == NULL )
return 0 ;
V_51 = V_49 -> V_51 ;
if ( V_51 -> V_55 . V_14 ) {
V_22 = F_73 ( V_49 , false ) ;
if ( V_22 < 0 )
return V_22 ;
}
if ( V_51 -> V_55 . V_171 ) {
V_22 = F_99 ( V_49 ) ;
if ( V_22 < 0 )
return V_22 ;
}
return 0 ;
}
static int F_101 ( struct V_20 * V_49 , T_8 * V_185 )
{
struct V_50 * V_51 ;
T_4 V_60 ;
int V_22 = 0 ;
while ( 1 ) {
V_22 = F_88 ( V_49 , V_186 , V_185 ) ;
if ( V_22 < 0 )
break;
V_51 = V_49 -> V_51 ;
if ( * V_185 <= ( T_8 ) V_51 -> V_61 )
break;
V_60 = ( * V_185 - V_51 -> V_61 ) + V_51 -> V_115 - 1 ;
V_60 /= V_51 -> V_115 ;
V_60 *= V_51 -> V_115 ;
V_22 = F_88 ( V_49 , V_187 , & V_60 ) ;
if ( V_22 < 0 )
break;
}
return V_22 ;
}
T_8 F_102 ( struct V_20 * V_49 , const char * V_188 , T_4 V_60 , int V_189 )
{
struct V_50 * V_51 = V_49 -> V_51 ;
int V_130 ;
while ( 1 ) {
if ( V_51 -> V_190 -> V_191 == V_192 ||
V_51 -> V_190 -> V_191 == V_193 ) {
#ifdef F_103
F_79 ( V_49 -> V_21 ,
L_12 ,
V_51 -> V_190 -> V_191 == V_192 ?
L_13 : L_14 ) ;
#endif
V_130 = F_99 ( V_49 ) ;
if ( V_130 < 0 )
break;
}
if ( V_189 ) {
T_1 V_1 ;
V_1 = F_1 () ;
V_130 = F_104 ( V_49 , ( void V_144 V_194 * ) V_188 , V_60 ) ;
F_5 ( V_1 ) ;
} else {
V_130 = F_104 ( V_49 , ( void V_144 V_194 * ) V_188 , V_60 ) ;
}
if ( V_130 != - V_195 && V_130 != - V_196 )
break;
if ( V_51 -> V_190 -> V_191 == V_197 )
return - V_141 ;
}
return V_130 ;
}
T_8 F_105 ( struct V_20 * V_49 , char * V_188 , T_4 V_60 , int V_189 )
{
struct V_50 * V_51 = V_49 -> V_51 ;
T_8 V_185 ;
int V_130 ;
while ( 1 ) {
if ( V_51 -> V_190 -> V_191 == V_192 ||
V_51 -> V_190 -> V_191 == V_193 ) {
#ifdef F_103
F_79 ( V_49 -> V_21 ,
L_15 ,
V_51 -> V_190 -> V_191 == V_192 ?
L_13 : L_14 ) ;
#endif
V_130 = F_88 ( V_49 , V_198 , NULL ) ;
if ( V_130 < 0 )
break;
} else if ( V_51 -> V_190 -> V_191 == V_199 ) {
V_130 = F_99 ( V_49 ) ;
if ( V_130 < 0 )
break;
}
V_130 = F_101 ( V_49 , & V_185 ) ;
if ( V_130 < 0 )
break;
if ( V_189 ) {
T_1 V_1 ;
V_1 = F_1 () ;
V_130 = F_106 ( V_49 , ( void V_144 V_194 * ) V_188 , V_60 ) ;
F_5 ( V_1 ) ;
} else {
V_130 = F_106 ( V_49 , ( void V_144 V_194 * ) V_188 , V_60 ) ;
}
if ( V_130 == - V_195 ) {
if ( V_51 -> V_190 -> V_191 == V_200 ) {
V_130 = F_88 ( V_49 , V_155 , NULL ) ;
if ( V_130 < 0 )
break;
}
continue;
}
if ( V_130 != - V_196 )
break;
}
return V_130 ;
}
T_8 F_107 ( struct V_20 * V_49 , void * * V_201 , T_4 V_60 , int V_189 )
{
struct V_50 * V_51 = V_49 -> V_51 ;
int V_130 ;
while ( 1 ) {
if ( V_51 -> V_190 -> V_191 == V_192 ||
V_51 -> V_190 -> V_191 == V_193 ) {
#ifdef F_103
F_79 ( V_49 -> V_21 ,
L_16 ,
V_51 -> V_190 -> V_191 == V_192 ?
L_13 : L_14 ) ;
#endif
V_130 = F_99 ( V_49 ) ;
if ( V_130 < 0 )
break;
}
if ( V_189 ) {
T_1 V_1 ;
V_1 = F_1 () ;
V_130 = F_108 ( V_49 , ( void V_194 * * ) V_201 , V_60 ) ;
F_5 ( V_1 ) ;
} else {
V_130 = F_108 ( V_49 , ( void V_194 * * ) V_201 , V_60 ) ;
}
if ( V_130 != - V_195 && V_130 != - V_196 )
break;
if ( V_51 -> V_190 -> V_191 == V_197 )
return - V_141 ;
}
return V_130 ;
}
T_8 F_109 ( struct V_20 * V_49 , void * * V_201 , T_4 V_60 , int V_189 )
{
struct V_50 * V_51 = V_49 -> V_51 ;
int V_130 ;
while ( 1 ) {
if ( V_51 -> V_190 -> V_191 == V_192 ||
V_51 -> V_190 -> V_191 == V_193 ) {
#ifdef F_103
F_79 ( V_49 -> V_21 ,
L_17 ,
V_51 -> V_190 -> V_191 == V_192 ?
L_13 : L_14 ) ;
#endif
V_130 = F_88 ( V_49 , V_198 , NULL ) ;
if ( V_130 < 0 )
break;
} else if ( V_51 -> V_190 -> V_191 == V_199 ) {
V_130 = F_99 ( V_49 ) ;
if ( V_130 < 0 )
break;
}
if ( V_189 ) {
T_1 V_1 ;
V_1 = F_1 () ;
V_130 = F_110 ( V_49 , ( void V_194 * * ) V_201 , V_60 ) ;
F_5 ( V_1 ) ;
} else {
V_130 = F_110 ( V_49 , ( void V_194 * * ) V_201 , V_60 ) ;
}
if ( V_130 != - V_195 && V_130 != - V_196 )
break;
}
return V_130 ;
}
static T_7 F_111 ( struct V_20 * V_49 , const char * V_202 , T_6 V_62 , int V_189 )
{
struct V_50 * V_51 = V_49 -> V_51 ;
T_8 V_60 , V_203 ;
#ifdef F_84
if ( V_51 -> V_55 . V_56 ) {
struct V_204 * V_150 ;
T_6 V_205 = ( V_51 -> V_55 . V_56 -> V_206 * V_51 -> V_55 . V_56 -> V_207 . V_150 ) / 8 ;
if ( ! V_189 ) {
if ( F_112 ( V_51 -> V_55 . V_170 , ( const char V_144 V_194 * ) V_202 , V_62 ) )
return - V_208 ;
V_202 = V_51 -> V_55 . V_170 ;
}
V_60 = V_62 / V_205 ;
V_203 = F_113 ( V_49 , ( char * ) V_202 , V_60 , & V_150 ) ;
if ( V_203 < 0 )
return V_203 ;
V_203 = F_114 ( V_49 , V_150 , V_203 ) ;
if ( V_203 <= 0 )
return V_203 ;
V_62 = V_203 * V_205 ;
} else
#endif
{
V_60 = F_59 ( V_51 , V_62 ) ;
V_203 = F_102 ( V_49 , V_202 , V_60 , V_189 ) ;
if ( V_203 <= 0 )
return V_203 ;
V_62 = F_56 ( V_51 , V_203 ) ;
}
return V_62 ;
}
static T_7 F_115 ( struct V_20 * V_49 , const char V_194 * V_202 , T_6 V_62 )
{
T_6 V_209 = 0 ;
T_7 V_210 ;
struct V_50 * V_51 = V_49 -> V_51 ;
if ( F_69 ( & V_49 -> V_112 ) )
return - V_211 ;
if ( ( V_210 = F_100 ( V_49 ) ) < 0 )
return V_210 ;
F_116 ( & V_51 -> V_55 . V_140 ) ;
while ( V_62 > 0 ) {
if ( V_62 < V_51 -> V_55 . V_124 || V_51 -> V_55 . V_172 > 0 ) {
V_210 = V_62 ;
if ( V_210 + V_51 -> V_55 . V_172 > V_51 -> V_55 . V_124 )
V_210 = V_51 -> V_55 . V_124 - V_51 -> V_55 . V_172 ;
if ( V_210 > 0 ) {
if ( F_112 ( V_51 -> V_55 . V_170 + V_51 -> V_55 . V_172 , V_202 , V_210 ) ) {
V_210 = - V_208 ;
goto V_22;
}
}
V_51 -> V_55 . V_172 += V_210 ;
V_202 += V_210 ;
V_62 -= V_210 ;
V_209 += V_210 ;
if ( V_49 -> V_55 . V_114 . V_212 ||
V_51 -> V_55 . V_172 == V_51 -> V_55 . V_124 ) {
V_210 = F_111 ( V_49 , V_51 -> V_55 . V_170 + V_51 -> V_55 . V_184 ,
V_51 -> V_55 . V_172 - V_51 -> V_55 . V_184 , 1 ) ;
if ( V_210 <= 0 )
goto V_22;
V_51 -> V_55 . V_62 += V_210 ;
V_51 -> V_55 . V_184 += V_210 ;
V_51 -> V_55 . V_184 %= V_51 -> V_55 . V_124 ;
if ( V_51 -> V_55 . V_184 == 0 ||
V_51 -> V_55 . V_184 == V_51 -> V_55 . V_172 )
V_51 -> V_55 . V_172 = 0 ;
else if ( ( V_49 -> V_213 & V_214 ) != 0 ) {
V_210 = - V_141 ;
goto V_22;
}
}
} else {
V_210 = F_111 ( V_49 ,
( const char V_144 * ) V_202 ,
V_51 -> V_55 . V_124 , 0 ) ;
if ( V_210 <= 0 )
goto V_22;
V_51 -> V_55 . V_62 += V_210 ;
V_202 += V_210 ;
V_62 -= V_210 ;
V_209 += V_210 ;
if ( ( V_49 -> V_213 & V_214 ) != 0 &&
V_210 != V_51 -> V_55 . V_124 )
break;
}
}
F_97 ( & V_51 -> V_55 . V_140 ) ;
return V_209 ;
V_22:
F_97 ( & V_51 -> V_55 . V_140 ) ;
return V_209 > 0 ? ( T_8 ) V_209 : V_210 ;
}
static T_7 F_117 ( struct V_20 * V_49 , char * V_202 , T_6 V_62 , int V_189 )
{
struct V_50 * V_51 = V_49 -> V_51 ;
T_8 V_60 , V_203 ;
#ifdef F_84
char V_194 * V_215 = ( char V_144 V_194 * ) V_202 ;
if ( V_51 -> V_55 . V_56 ) {
struct V_204 * V_150 ;
T_6 V_205 = ( V_51 -> V_55 . V_57 -> V_216 * V_51 -> V_55 . V_57 -> V_217 . V_150 ) / 8 ;
if ( ! V_189 )
V_202 = V_51 -> V_55 . V_170 ;
V_60 = V_62 / V_205 ;
V_203 = F_113 ( V_49 , V_202 , V_60 , & V_150 ) ;
if ( V_203 < 0 )
return V_203 ;
V_203 = F_118 ( V_49 , V_150 , V_203 ) ;
if ( V_203 <= 0 )
return V_203 ;
V_62 = V_203 * V_205 ;
if ( ! V_189 && F_119 ( V_215 , V_202 , V_62 ) )
return - V_208 ;
} else
#endif
{
V_60 = F_59 ( V_51 , V_62 ) ;
V_203 = F_105 ( V_49 , V_202 , V_60 , V_189 ) ;
if ( V_203 <= 0 )
return V_203 ;
V_62 = F_56 ( V_51 , V_203 ) ;
}
return V_62 ;
}
static T_7 F_120 ( struct V_20 * V_49 , char V_194 * V_202 , T_6 V_62 )
{
T_6 V_209 = 0 ;
T_7 V_210 ;
struct V_50 * V_51 = V_49 -> V_51 ;
if ( F_69 ( & V_49 -> V_112 ) )
return - V_211 ;
if ( ( V_210 = F_100 ( V_49 ) ) < 0 )
return V_210 ;
F_116 ( & V_51 -> V_55 . V_140 ) ;
while ( V_62 > 0 ) {
if ( V_62 < V_51 -> V_55 . V_124 || V_51 -> V_55 . V_172 > 0 ) {
if ( V_51 -> V_55 . V_172 == 0 ) {
V_210 = F_117 ( V_49 , V_51 -> V_55 . V_170 , V_51 -> V_55 . V_124 , 1 ) ;
if ( V_210 <= 0 )
goto V_22;
V_51 -> V_55 . V_62 += V_210 ;
V_51 -> V_55 . V_184 = V_210 ;
V_51 -> V_55 . V_172 = V_210 ;
}
V_210 = V_62 ;
if ( ( T_6 ) V_210 > V_51 -> V_55 . V_172 )
V_210 = V_51 -> V_55 . V_172 ;
if ( F_119 ( V_202 , V_51 -> V_55 . V_170 + ( V_51 -> V_55 . V_184 - V_51 -> V_55 . V_172 ) , V_210 ) ) {
V_210 = - V_208 ;
goto V_22;
}
V_202 += V_210 ;
V_62 -= V_210 ;
V_209 += V_210 ;
V_51 -> V_55 . V_172 -= V_210 ;
} else {
V_210 = F_117 ( V_49 , ( char V_144 * ) V_202 ,
V_51 -> V_55 . V_124 , 0 ) ;
if ( V_210 <= 0 )
goto V_22;
V_51 -> V_55 . V_62 += V_210 ;
V_202 += V_210 ;
V_62 -= V_210 ;
V_209 += V_210 ;
}
}
F_97 ( & V_51 -> V_55 . V_140 ) ;
return V_209 ;
V_22:
F_97 ( & V_51 -> V_55 . V_140 ) ;
return V_209 > 0 ? ( T_8 ) V_209 : V_210 ;
}
static int F_121 ( struct V_175 * V_176 )
{
struct V_20 * V_49 ;
struct V_50 * V_51 ;
int V_3 ;
for ( V_3 = 0 ; V_3 < 2 ; V_3 ++ ) {
V_49 = V_176 -> V_180 [ V_3 ] ;
if ( ! V_49 )
continue;
V_51 = V_49 -> V_51 ;
F_88 ( V_49 , V_155 , NULL ) ;
V_51 -> V_55 . V_171 = 1 ;
V_51 -> V_55 . V_172 = 0 ;
V_51 -> V_55 . V_183 = 0 ;
V_51 -> V_55 . V_184 = 0 ;
}
return 0 ;
}
static int F_122 ( struct V_175 * V_176 )
{
struct V_20 * V_49 ;
int V_22 ;
V_49 = V_176 -> V_180 [ V_154 ] ;
if ( V_49 != NULL ) {
if ( ( V_22 = F_100 ( V_49 ) ) < 0 )
return V_22 ;
F_88 ( V_49 , V_218 , NULL ) ;
}
return 0 ;
}
static int F_123 ( struct V_20 * V_49 , T_6 V_219 )
{
struct V_50 * V_51 ;
T_7 V_220 = 0 ;
T_9 V_191 ;
long V_221 ;
T_10 V_222 ;
V_51 = V_49 -> V_51 ;
F_124 ( & V_222 , V_223 ) ;
F_125 ( & V_51 -> V_224 , & V_222 ) ;
#ifdef F_103
F_79 ( V_49 -> V_21 , L_18 , V_219 ) ;
#endif
while ( 1 ) {
V_220 = F_111 ( V_49 , V_51 -> V_55 . V_170 , V_219 , 1 ) ;
if ( V_220 > 0 ) {
V_51 -> V_55 . V_172 = 0 ;
V_220 = 0 ;
break;
}
if ( V_220 != 0 && V_220 != - V_141 )
break;
V_220 = 0 ;
F_126 ( V_225 ) ;
F_127 ( V_49 ) ;
V_191 = V_51 -> V_190 -> V_191 ;
F_128 ( V_49 ) ;
if ( V_191 != V_226 ) {
F_126 ( V_227 ) ;
break;
}
V_221 = F_129 ( 10 * V_228 ) ;
if ( F_130 ( V_223 ) ) {
V_220 = - V_229 ;
break;
}
if ( V_221 == 0 ) {
F_131 ( V_49 -> V_21 ,
L_19 ) ;
V_220 = - V_181 ;
break;
}
}
F_132 ( & V_51 -> V_224 , & V_222 ) ;
return V_220 ;
}
static int F_133 ( struct V_175 * V_176 )
{
int V_22 = 0 ;
unsigned int V_230 ;
struct V_20 * V_49 ;
struct V_50 * V_51 ;
T_5 V_67 ;
unsigned long V_231 ;
T_6 V_219 ;
V_49 = V_176 -> V_180 [ V_154 ] ;
if ( V_49 != NULL ) {
V_51 = V_49 -> V_51 ;
if ( F_69 ( & V_49 -> V_112 ) )
goto V_232;
if ( ( V_22 = F_100 ( V_49 ) ) < 0 )
return V_22 ;
V_67 = F_61 ( V_51 -> V_55 . V_67 ) ;
V_231 = F_64 ( V_67 ) ;
F_116 ( & V_51 -> V_55 . V_140 ) ;
if ( V_51 -> V_55 . V_172 > 0 ) {
#ifdef F_103
F_79 ( V_49 -> V_21 , L_20 ) ;
#endif
V_219 = ( 8 * ( V_51 -> V_55 . V_124 - V_51 -> V_55 . V_172 ) + 7 ) / V_231 ;
F_95 ( V_67 ,
V_51 -> V_55 . V_170 + V_51 -> V_55 . V_172 ,
V_219 ) ;
V_22 = F_123 ( V_49 , V_51 -> V_55 . V_124 ) ;
if ( V_22 < 0 ) {
F_97 ( & V_51 -> V_55 . V_140 ) ;
return V_22 ;
}
} else if ( V_51 -> V_55 . V_184 > 0 ) {
#ifdef F_103
F_79 ( V_49 -> V_21 , L_21 ) ;
#endif
V_219 = V_51 -> V_55 . V_124 - V_51 -> V_55 . V_184 ;
F_95 ( V_67 ,
V_51 -> V_55 . V_170 ,
V_219 * 8 / V_231 ) ;
V_22 = F_123 ( V_49 , V_219 ) ;
if ( V_22 < 0 ) {
F_97 ( & V_51 -> V_55 . V_140 ) ;
return V_22 ;
}
}
V_219 = V_51 -> V_233 -> V_234 % V_51 -> V_115 ;
if ( V_219 > 0 ) {
V_219 = V_51 -> V_115 - V_219 ;
if ( V_51 -> V_235 == V_146 ) {
V_219 = ( V_51 -> V_236 * V_219 ) / 8 ;
while ( V_219 > 0 ) {
T_1 V_1 ;
T_6 V_237 = V_219 < V_51 -> V_55 . V_124 ? V_219 : V_51 -> V_55 . V_124 ;
V_219 -= V_237 ;
V_237 *= 8 ;
V_237 /= V_51 -> V_238 ;
F_95 ( V_51 -> V_67 ,
V_51 -> V_55 . V_170 ,
V_237 ) ;
V_237 /= V_51 -> V_150 ;
V_1 = F_1 () ;
F_104 ( V_49 , ( void V_144 V_194 * ) V_51 -> V_55 . V_170 , V_237 ) ;
F_5 ( V_1 ) ;
}
} else if ( V_51 -> V_235 == V_147 ) {
void V_194 * V_239 [ V_51 -> V_150 ] ;
memset ( V_239 , 0 , V_51 -> V_150 * sizeof( void * ) ) ;
F_108 ( V_49 , V_239 , V_219 ) ;
}
}
F_97 ( & V_51 -> V_55 . V_140 ) ;
V_232:
V_230 = V_49 -> V_213 ;
V_49 -> V_213 &= ~ V_214 ;
V_22 = F_88 ( V_49 , V_198 , NULL ) ;
V_49 -> V_213 = V_230 ;
if ( V_22 < 0 )
return V_22 ;
V_51 -> V_55 . V_171 = 1 ;
}
V_49 = V_176 -> V_180 [ V_160 ] ;
if ( V_49 != NULL ) {
if ( ( V_22 = F_100 ( V_49 ) ) < 0 )
return V_22 ;
V_51 = V_49 -> V_51 ;
V_22 = F_88 ( V_49 , V_155 , NULL ) ;
if ( V_22 < 0 )
return V_22 ;
V_51 -> V_55 . V_172 = 0 ;
V_51 -> V_55 . V_171 = 1 ;
}
return 0 ;
}
static int F_134 ( struct V_175 * V_176 , int V_128 )
{
int V_178 ;
for ( V_178 = 1 ; V_178 >= 0 ; -- V_178 ) {
struct V_20 * V_49 = V_176 -> V_180 [ V_178 ] ;
struct V_50 * V_51 ;
if ( V_49 == NULL )
continue;
V_51 = V_49 -> V_51 ;
if ( V_128 < 1000 )
V_128 = 1000 ;
else if ( V_128 > 192000 )
V_128 = 192000 ;
if ( V_51 -> V_55 . V_128 != V_128 ) {
V_51 -> V_55 . V_14 = 1 ;
V_51 -> V_55 . V_128 = V_128 ;
}
}
return F_135 ( V_176 ) ;
}
static int F_135 ( struct V_175 * V_176 )
{
struct V_20 * V_49 ;
int V_22 ;
if ( ( V_22 = F_98 ( V_176 , & V_49 ) ) < 0 )
return V_22 ;
return V_49 -> V_51 -> V_55 . V_128 ;
}
static int F_136 ( struct V_175 * V_176 , unsigned int V_150 )
{
int V_178 ;
if ( V_150 < 1 )
V_150 = 1 ;
if ( V_150 > 128 )
return - V_7 ;
for ( V_178 = 1 ; V_178 >= 0 ; -- V_178 ) {
struct V_20 * V_49 = V_176 -> V_180 [ V_178 ] ;
struct V_50 * V_51 ;
if ( V_49 == NULL )
continue;
V_51 = V_49 -> V_51 ;
if ( V_51 -> V_55 . V_150 != V_150 ) {
V_51 -> V_55 . V_14 = 1 ;
V_51 -> V_55 . V_150 = V_150 ;
}
}
return F_137 ( V_176 ) ;
}
static int F_137 ( struct V_175 * V_176 )
{
struct V_20 * V_49 ;
int V_22 ;
if ( ( V_22 = F_98 ( V_176 , & V_49 ) ) < 0 )
return V_22 ;
return V_49 -> V_51 -> V_55 . V_150 ;
}
static int F_138 ( struct V_175 * V_176 )
{
struct V_20 * V_49 ;
int V_22 ;
if ( ( V_22 = F_98 ( V_176 , & V_49 ) ) < 0 )
return V_22 ;
return V_49 -> V_51 -> V_55 . V_124 ;
}
static int F_139 ( struct V_175 * V_176 )
{
struct V_20 * V_49 ;
int V_22 ;
int V_135 ;
struct V_13 * V_14 ;
unsigned int V_240 = 0 ;
struct V_17 V_241 ;
int V_242 ;
if ( ( V_22 = F_98 ( V_176 , & V_49 ) ) < 0 )
return V_22 ;
if ( F_69 ( & V_49 -> V_112 ) )
V_135 = 1 ;
else
V_135 = V_49 -> V_55 . V_114 . V_135 ;
if ( ! V_135 )
return V_68 | V_74 |
V_76 | V_78 |
V_80 | V_82 |
V_84 |
V_88 | V_90 |
V_92 | V_94 |
V_96 ;
V_14 = F_39 ( sizeof( * V_14 ) , V_44 ) ;
if ( ! V_14 )
return - V_45 ;
F_77 ( V_14 ) ;
V_22 = F_26 ( V_49 , V_14 ) ;
V_241 = * F_24 ( V_14 , V_151 ) ;
F_40 ( V_14 ) ;
if ( V_22 < 0 )
return V_22 ;
for ( V_242 = 0 ; V_242 < 32 ; ++ V_242 ) {
if ( F_81 ( & V_241 , V_242 ) ) {
int V_243 = F_62 ( V_242 ) ;
if ( V_243 >= 0 )
V_240 |= V_243 ;
}
}
return V_240 ;
}
static int F_140 ( struct V_175 * V_176 , int V_67 )
{
int V_240 , V_178 ;
if ( V_67 != V_244 ) {
V_240 = F_139 ( V_176 ) ;
if ( V_240 < 0 )
return V_240 ;
if ( ! ( V_240 & V_67 ) )
V_67 = V_74 ;
for ( V_178 = 1 ; V_178 >= 0 ; -- V_178 ) {
struct V_20 * V_49 = V_176 -> V_180 [ V_178 ] ;
struct V_50 * V_51 ;
if ( V_49 == NULL )
continue;
V_51 = V_49 -> V_51 ;
if ( V_51 -> V_55 . V_67 != V_67 ) {
V_51 -> V_55 . V_14 = 1 ;
V_51 -> V_55 . V_67 = V_67 ;
}
}
}
return F_141 ( V_176 ) ;
}
static int F_141 ( struct V_175 * V_176 )
{
struct V_20 * V_49 ;
int V_22 ;
if ( ( V_22 = F_98 ( V_176 , & V_49 ) ) < 0 )
return V_22 ;
return V_49 -> V_51 -> V_55 . V_67 ;
}
static int F_142 ( struct V_20 * V_49 , int V_245 )
{
struct V_50 * V_51 ;
if ( V_49 == NULL )
return 0 ;
V_51 = V_49 -> V_51 ;
if ( V_245 == 0 ) {
V_245 = V_51 -> V_55 . V_119 ;
if ( V_245 == 0 )
V_245 = 1 ;
return V_245 ;
}
if ( V_51 -> V_55 . V_119 || V_51 -> V_55 . V_116 )
return - V_7 ;
if ( V_245 != 1 && V_245 != 2 && V_245 != 4 &&
V_245 != 8 && V_245 != 16 )
return - V_7 ;
V_51 -> V_55 . V_119 = V_245 ;
V_51 -> V_55 . V_14 = 1 ;
return V_245 ;
}
static int F_143 ( struct V_175 * V_176 , int V_245 )
{
int V_22 = - V_7 , V_178 ;
for ( V_178 = 1 ; V_178 >= 0 ; -- V_178 ) {
struct V_20 * V_49 = V_176 -> V_180 [ V_178 ] ;
if ( V_49 == NULL )
continue;
if ( ( V_22 = F_142 ( V_49 , V_245 ) ) < 0 )
return V_22 ;
}
return V_22 ;
}
static int F_144 ( struct V_20 * V_49 , unsigned int V_10 )
{
struct V_50 * V_51 ;
if ( V_49 == NULL )
return 0 ;
V_51 = V_49 -> V_51 ;
if ( V_51 -> V_55 . V_119 || V_51 -> V_55 . V_116 )
return - V_7 ;
V_51 -> V_55 . V_116 = V_10 & 0xffff ;
V_51 -> V_55 . V_123 = ( V_10 >> 16 ) & 0xffff ;
if ( V_51 -> V_55 . V_116 < 4 )
V_51 -> V_55 . V_116 = 4 ;
if ( V_51 -> V_55 . V_123 < 2 )
V_51 -> V_55 . V_123 = 2 ;
V_51 -> V_55 . V_14 = 1 ;
return 0 ;
}
static int F_145 ( struct V_175 * V_176 , unsigned int V_10 )
{
int V_22 = - V_7 , V_178 ;
for ( V_178 = 1 ; V_178 >= 0 ; -- V_178 ) {
struct V_20 * V_49 = V_176 -> V_180 [ V_178 ] ;
if ( V_49 == NULL )
continue;
if ( ( V_22 = F_144 ( V_49 , V_10 ) ) < 0 )
return V_22 ;
}
return V_22 ;
}
static int F_146 ( struct V_246 * V_246 )
{
F_147 ( & V_246 -> V_247 ) ;
V_246 -> V_213 |= V_214 ;
F_148 ( & V_246 -> V_247 ) ;
return 0 ;
}
static int F_149 ( struct V_20 * V_49 , int V_221 )
{
if ( V_49 == NULL ) {
V_221 &= ~ V_248 ;
return V_221 ;
}
#ifdef F_150
if ( V_49 -> V_153 == V_154 )
if ( V_49 -> V_249 -> V_250 > 1 )
V_221 |= F_150 ;
#endif
#if F_151 ( V_251 ) && 0
{
struct V_50 * V_51 = V_49 -> V_51 ;
if ( V_51 -> V_252 & ( V_253 | V_254 ) )
V_221 &= ~ V_251 ;
}
#endif
return V_221 ;
}
static int F_152 ( struct V_175 * V_176 )
{
int V_220 , V_178 ;
V_220 = V_255 | V_256 | V_248 | V_251 ;
for ( V_178 = 0 ; V_178 < 2 ; V_178 ++ ) {
struct V_20 * V_49 = V_176 -> V_180 [ V_178 ] ;
V_220 = F_149 ( V_49 , V_220 ) ;
}
V_220 |= 0x0001 ;
return V_220 ;
}
static void F_153 ( struct V_20 * V_49 ,
T_4 V_257 )
{
struct V_50 * V_51 = V_49 -> V_51 ;
T_4 V_234 ;
V_234 = V_257 + V_51 -> V_61 ;
V_234 %= V_51 -> V_159 ;
V_51 -> V_233 -> V_234 = V_234 ;
}
static int F_154 ( struct V_175 * V_176 , int V_157 )
{
struct V_50 * V_51 ;
struct V_20 * V_258 = NULL , * V_259 = NULL ;
int V_22 , V_260 ;
#ifdef F_103
F_79 ( V_49 -> V_21 , L_22 , V_157 ) ;
#endif
V_258 = V_176 -> V_180 [ V_154 ] ;
V_259 = V_176 -> V_180 [ V_160 ] ;
if ( V_258 ) {
if ( ( V_22 = F_100 ( V_258 ) ) < 0 )
return V_22 ;
}
if ( V_259 ) {
if ( ( V_22 = F_100 ( V_259 ) ) < 0 )
return V_22 ;
}
if ( V_258 ) {
V_51 = V_258 -> V_51 ;
if ( V_157 & V_261 ) {
if ( V_51 -> V_55 . V_157 )
goto V_262;
if ( F_69 ( & V_258 -> V_112 ) )
F_153 ( V_258 ,
F_60 ( V_51 ) ) ;
V_51 -> V_55 . V_157 = 1 ;
V_51 -> V_158 = 1 ;
V_260 = V_218 ;
} else {
if ( ! V_51 -> V_55 . V_157 )
goto V_262;
V_51 -> V_55 . V_157 = 0 ;
V_51 -> V_158 = V_51 -> V_159 ;
V_260 = V_155 ;
V_51 -> V_55 . V_171 = 1 ;
}
V_22 = F_88 ( V_258 , V_260 , NULL ) ;
if ( V_22 < 0 )
return V_22 ;
}
V_262:
if ( V_259 ) {
V_51 = V_259 -> V_51 ;
if ( V_157 & V_263 ) {
if ( V_51 -> V_55 . V_157 )
goto V_264;
V_51 -> V_55 . V_157 = 1 ;
V_51 -> V_158 = 1 ;
V_260 = V_218 ;
} else {
if ( ! V_51 -> V_55 . V_157 )
goto V_264;
V_51 -> V_55 . V_157 = 0 ;
V_51 -> V_158 = V_51 -> V_159 ;
V_260 = V_155 ;
V_51 -> V_55 . V_171 = 1 ;
}
V_22 = F_88 ( V_259 , V_260 , NULL ) ;
if ( V_22 < 0 )
return V_22 ;
}
V_264:
return 0 ;
}
static int F_155 ( struct V_175 * V_176 )
{
struct V_20 * V_258 = NULL , * V_259 = NULL ;
int V_220 = 0 ;
V_258 = V_176 -> V_180 [ V_154 ] ;
V_259 = V_176 -> V_180 [ V_160 ] ;
if ( V_258 && V_258 -> V_51 && V_258 -> V_51 -> V_55 . V_157 )
V_220 |= V_261 ;
if ( V_259 && V_259 -> V_51 && V_259 -> V_51 -> V_55 . V_157 )
V_220 |= V_263 ;
return V_220 ;
}
static int F_156 ( struct V_175 * V_176 )
{
struct V_20 * V_49 ;
struct V_50 * V_51 ;
T_8 V_185 ;
int V_22 ;
V_49 = V_176 -> V_180 [ V_154 ] ;
if ( V_49 == NULL )
return - V_7 ;
if ( ( V_22 = F_100 ( V_49 ) ) < 0 )
return V_22 ;
V_51 = V_49 -> V_51 ;
if ( V_51 -> V_55 . V_14 || V_51 -> V_55 . V_171 )
return 0 ;
V_22 = F_88 ( V_49 , V_186 , & V_185 ) ;
if ( V_22 == - V_195 )
V_185 = 0 ;
else if ( V_22 < 0 )
return V_22 ;
return F_54 ( V_49 , V_185 ) ;
}
static int F_157 ( struct V_175 * V_176 , int V_153 , struct V_265 V_194 * V_266 )
{
struct V_20 * V_49 ;
struct V_50 * V_51 ;
T_8 V_185 ;
int V_267 ;
struct V_265 V_252 ;
int V_22 ;
if ( V_266 == NULL )
return - V_208 ;
V_49 = V_176 -> V_180 [ V_153 ] ;
if ( V_49 == NULL )
return - V_7 ;
if ( ( V_22 = F_100 ( V_49 ) ) < 0 )
return V_22 ;
V_51 = V_49 -> V_51 ;
if ( V_51 -> V_55 . V_14 || V_51 -> V_55 . V_171 ) {
memset ( & V_252 , 0 , sizeof( V_252 ) ) ;
if ( F_119 ( V_266 , & V_252 , sizeof( V_252 ) ) )
return - V_208 ;
return 0 ;
}
if ( V_153 == V_154 ) {
V_22 = F_88 ( V_49 , V_186 , & V_185 ) ;
if ( V_22 == - V_195 || V_22 == - V_196 || ( ! V_22 && V_185 < 0 ) ) {
V_22 = 0 ;
V_185 = 0 ;
V_267 = 0 ;
} else {
V_267 = V_51 -> V_55 . V_172 ;
}
} else {
V_22 = F_101 ( V_49 , & V_185 ) ;
V_267 = - V_51 -> V_55 . V_172 ;
}
if ( V_22 < 0 )
return V_22 ;
V_252 . V_188 = F_54 ( V_49 , V_51 -> V_190 -> V_257 % V_51 -> V_61 ) ;
if ( F_69 ( & V_49 -> V_112 ) ) {
T_8 V_137 ;
V_185 = F_60 ( V_51 ) ;
V_137 = V_185 - V_51 -> V_55 . V_183 ;
if ( V_137 < 0 )
V_137 += V_51 -> V_159 ;
V_252 . V_268 = V_137 / V_51 -> V_115 ;
V_51 -> V_55 . V_183 = V_185 ;
if ( V_49 -> V_153 == V_154 )
F_153 ( V_49 , V_185 ) ;
V_252 . V_62 = F_54 ( V_49 , V_51 -> V_190 -> V_257 ) & V_43 ;
} else {
V_185 = F_54 ( V_49 , V_185 ) ;
if ( V_153 == V_154 ) {
if ( V_49 -> V_55 . V_114 . V_269 )
V_252 . V_268 = ( V_51 -> V_55 . V_63 - V_185 - V_267 ) / V_51 -> V_55 . V_124 ;
else
V_252 . V_268 = ( V_185 + V_267 ) / V_51 -> V_55 . V_124 ;
V_252 . V_62 = ( V_51 -> V_55 . V_62 - V_185 ) & V_43 ;
} else {
V_185 += V_267 ;
V_252 . V_268 = V_185 / V_51 -> V_55 . V_124 ;
V_252 . V_62 = ( V_51 -> V_55 . V_62 + V_185 ) & V_43 ;
}
}
if ( F_119 ( V_266 , & V_252 , sizeof( V_252 ) ) )
return - V_208 ;
return 0 ;
}
static int F_158 ( struct V_175 * V_176 , int V_153 , struct V_270 V_194 * V_266 )
{
struct V_20 * V_49 ;
struct V_50 * V_51 ;
T_8 V_271 ;
int V_267 ;
struct V_270 V_252 ;
int V_22 ;
if ( V_266 == NULL )
return - V_208 ;
V_49 = V_176 -> V_180 [ V_153 ] ;
if ( V_49 == NULL )
return - V_7 ;
V_51 = V_49 -> V_51 ;
if ( V_51 -> V_55 . V_14 &&
( V_22 = F_73 ( V_49 , false ) ) < 0 )
return V_22 ;
V_252 . V_272 = V_51 -> V_55 . V_124 ;
V_252 . V_273 = V_51 -> V_121 ;
if ( V_51 -> V_55 . V_171 ) {
if ( V_153 == V_154 ) {
V_252 . V_62 = V_51 -> V_55 . V_124 * V_51 -> V_55 . V_121 ;
V_252 . V_274 = V_51 -> V_55 . V_121 ;
} else {
V_252 . V_62 = 0 ;
V_252 . V_274 = 0 ;
}
} else {
if ( V_153 == V_154 ) {
V_22 = F_88 ( V_49 , V_186 , & V_271 ) ;
if ( V_22 == - V_195 || V_22 == - V_196 || ( ! V_22 && V_271 < 0 ) ) {
V_271 = V_51 -> V_61 ;
V_22 = 0 ;
V_267 = 0 ;
} else {
V_271 = V_51 -> V_61 - V_271 ;
V_267 = - V_51 -> V_55 . V_172 ;
}
} else {
V_22 = F_101 ( V_49 , & V_271 ) ;
V_267 = V_51 -> V_55 . V_172 ;
}
if ( V_22 < 0 )
return V_22 ;
V_252 . V_62 = F_54 ( V_49 , V_271 ) + V_267 ;
V_252 . V_274 = V_252 . V_62 / V_51 -> V_55 . V_124 ;
}
#ifdef F_103
F_79 ( V_49 -> V_21 ,
L_23 ,
V_252 . V_62 , V_252 . V_274 , V_252 . V_273 , V_252 . V_272 ) ;
#endif
if ( F_119 ( V_266 , & V_252 , sizeof( V_252 ) ) )
return - V_208 ;
return 0 ;
}
static int F_159 ( struct V_175 * V_176 , int V_153 , struct V_275 V_194 * V_266 )
{
return - V_7 ;
}
static const char * F_160 ( const char * V_276 )
{
const char * V_188 , * V_277 = NULL ;
for ( V_188 = V_276 ; * V_188 ; V_188 ++ ) {
if ( * V_188 == '/' )
V_277 = V_188 + 1 ;
}
return V_277 ;
}
static void F_161 ( struct V_278 * V_21 , int V_153 ,
const char * V_279 ,
struct V_280 * V_281 )
{
struct V_280 * V_114 ;
F_116 ( & V_21 -> V_180 [ V_153 ] . V_55 . V_282 ) ;
do {
for ( V_114 = V_21 -> V_180 [ V_153 ] . V_55 . V_283 ; V_114 ;
V_114 = V_114 -> V_54 ) {
if ( ! strcmp ( V_114 -> V_279 , V_279 ) )
goto V_284;
}
} while ( ( V_279 = F_160 ( V_279 ) ) != NULL );
V_284:
if ( V_114 )
* V_281 = * V_114 ;
F_97 ( & V_21 -> V_180 [ V_153 ] . V_55 . V_282 ) ;
}
static void F_162 ( struct V_20 * V_49 )
{
struct V_50 * V_51 ;
V_51 = V_49 -> V_51 ;
F_93 ( V_51 -> V_55 . V_170 ) ;
V_51 -> V_55 . V_170 = NULL ;
#ifdef F_84
F_50 ( V_49 ) ;
#endif
V_49 -> V_55 . V_55 = 0 ;
}
static void F_163 ( struct V_20 * V_49 ,
struct V_280 * V_114 ,
int V_285 )
{
struct V_50 * V_51 ;
V_49 -> V_55 . V_55 = 1 ;
V_49 -> V_55 . V_114 = * V_114 ;
if ( V_114 -> V_286 )
V_49 -> V_213 |= V_214 ;
else if ( V_114 -> V_287 )
V_49 -> V_213 &= ~ V_214 ;
V_51 = V_49 -> V_51 ;
V_51 -> V_55 . V_14 = 1 ;
V_51 -> V_55 . V_157 = 1 ;
V_51 -> V_55 . V_128 = 8000 ;
F_164 ( & V_51 -> V_55 . V_140 ) ;
switch ( F_165 ( V_285 ) ) {
case V_288 :
V_51 -> V_55 . V_67 = V_74 ;
break;
case V_289 :
V_51 -> V_55 . V_67 = V_76 ;
break;
default:
V_51 -> V_55 . V_67 = V_68 ;
}
V_51 -> V_55 . V_150 = 1 ;
V_51 -> V_55 . V_116 = 0 ;
V_51 -> V_55 . V_123 = 0 ;
V_51 -> V_55 . V_119 = 0 ;
V_49 -> V_290 = F_162 ;
}
static int F_166 ( struct V_175 * V_176 )
{
int V_291 ;
if ( ! V_176 )
return 0 ;
for ( V_291 = 0 ; V_291 < 2 ; ++ V_291 ) {
struct V_20 * V_49 = V_176 -> V_180 [ V_291 ] ;
if ( V_49 )
F_167 ( V_49 ) ;
}
F_40 ( V_176 ) ;
return 0 ;
}
static int F_168 ( struct V_246 * V_246 ,
struct V_278 * V_21 ,
struct V_175 * * V_292 ,
int V_285 ,
struct V_280 * V_114 )
{
int V_178 , V_22 ;
struct V_175 * V_176 ;
struct V_20 * V_49 ;
T_11 V_293 = V_246 -> V_293 ;
if ( V_292 )
* V_292 = NULL ;
V_176 = F_76 ( sizeof( * V_176 ) , V_44 ) ;
if ( V_176 == NULL )
return - V_45 ;
if ( ( V_293 & ( V_294 | V_295 ) ) == ( V_294 | V_295 ) &&
( V_21 -> V_296 & V_297 ) )
V_293 = V_294 ;
V_246 -> V_213 &= ~ V_298 ;
for ( V_178 = 0 ; V_178 < 2 ; V_178 ++ ) {
if ( V_114 [ V_178 ] . V_299 )
continue;
if ( ! V_21 -> V_180 [ V_178 ] . V_250 )
continue;
if ( V_178 == V_154 ) {
if ( ! ( V_293 & V_294 ) )
continue;
} else {
if ( ! ( V_293 & V_295 ) )
continue;
}
V_22 = F_169 ( V_21 , V_178 , V_246 , & V_49 ) ;
if ( V_22 < 0 ) {
F_166 ( V_176 ) ;
return V_22 ;
}
V_176 -> V_180 [ V_178 ] = V_49 ;
V_49 -> V_246 = V_176 ;
F_163 ( V_49 , & V_114 [ V_178 ] , V_285 ) ;
}
if ( ! V_176 -> V_180 [ 0 ] && ! V_176 -> V_180 [ 1 ] ) {
F_166 ( V_176 ) ;
return - V_7 ;
}
V_246 -> V_300 = V_176 ;
if ( V_292 )
* V_292 = V_176 ;
return 0 ;
}
static int F_170 ( struct V_301 * V_302 , char * V_303 , T_6 V_219 )
{
unsigned int V_178 ;
if ( F_43 ( ! V_302 || ! V_303 || V_219 < 2 ) )
return - V_7 ;
for ( V_178 = 0 ; V_178 < sizeof( V_302 -> V_304 ) && V_178 + 1 < V_219 ; V_178 ++ )
V_303 [ V_178 ] = V_302 -> V_304 [ V_178 ] ;
V_303 [ V_178 ] = '\0' ;
return 0 ;
}
static int F_171 ( struct V_305 * V_305 , struct V_246 * V_246 )
{
int V_22 ;
char V_279 [ 32 ] ;
struct V_278 * V_21 ;
struct V_175 * V_176 ;
struct V_280 V_114 [ 2 ] ;
int V_286 ;
T_10 V_222 ;
V_22 = F_172 ( V_305 , V_246 ) ;
if ( V_22 < 0 )
return V_22 ;
V_21 = F_173 ( F_174 ( V_305 ) ,
V_306 ) ;
if ( V_21 == NULL ) {
V_22 = - V_307 ;
goto V_308;
}
V_22 = F_175 ( V_21 -> V_309 , V_246 ) ;
if ( V_22 < 0 )
goto V_308;
if ( ! F_176 ( V_21 -> V_309 -> V_310 ) ) {
V_22 = - V_208 ;
goto V_311;
}
if ( F_170 ( V_223 , V_279 , sizeof( V_279 ) ) < 0 ) {
V_22 = - V_208 ;
goto V_312;
}
memset ( V_114 , 0 , sizeof( V_114 ) ) ;
if ( V_246 -> V_293 & V_294 )
F_161 ( V_21 , V_154 ,
V_279 , & V_114 [ 0 ] ) ;
if ( V_246 -> V_293 & V_295 )
F_161 ( V_21 , V_160 ,
V_279 , & V_114 [ 1 ] ) ;
V_286 = ! ! ( V_246 -> V_213 & V_214 ) ;
if ( ! V_286 )
V_286 = V_313 ;
F_124 ( & V_222 , V_223 ) ;
F_125 ( & V_21 -> V_314 , & V_222 ) ;
F_116 ( & V_21 -> V_315 ) ;
while ( 1 ) {
V_22 = F_168 ( V_246 , V_21 , & V_176 ,
F_174 ( V_305 ) , V_114 ) ;
if ( V_22 >= 0 )
break;
if ( V_22 == - V_141 ) {
if ( V_286 ) {
V_22 = - V_316 ;
break;
}
} else
break;
F_126 ( V_225 ) ;
F_97 ( & V_21 -> V_315 ) ;
F_177 () ;
F_116 ( & V_21 -> V_315 ) ;
if ( V_21 -> V_309 -> V_317 ) {
V_22 = - V_307 ;
break;
}
if ( F_130 ( V_223 ) ) {
V_22 = - V_229 ;
break;
}
}
F_132 ( & V_21 -> V_314 , & V_222 ) ;
F_97 ( & V_21 -> V_315 ) ;
if ( V_22 < 0 )
goto V_312;
F_178 ( V_21 -> V_309 ) ;
return V_22 ;
V_312:
F_179 ( V_21 -> V_309 -> V_310 ) ;
V_311:
F_180 ( V_21 -> V_309 , V_246 ) ;
V_308:
if ( V_21 )
F_178 ( V_21 -> V_309 ) ;
return V_22 ;
}
static int F_181 ( struct V_305 * V_305 , struct V_246 * V_246 )
{
struct V_278 * V_21 ;
struct V_20 * V_49 ;
struct V_175 * V_176 ;
V_176 = V_246 -> V_300 ;
V_49 = V_176 -> V_180 [ V_154 ] ;
if ( V_49 == NULL )
V_49 = V_176 -> V_180 [ V_160 ] ;
if ( F_43 ( ! V_49 ) )
return - V_211 ;
V_21 = V_49 -> V_21 ;
if ( ! V_21 -> V_309 -> V_317 )
F_133 ( V_176 ) ;
F_116 ( & V_21 -> V_315 ) ;
F_166 ( V_176 ) ;
F_97 ( & V_21 -> V_315 ) ;
F_182 ( & V_21 -> V_314 ) ;
F_179 ( V_21 -> V_309 -> V_310 ) ;
F_180 ( V_21 -> V_309 , V_246 ) ;
return 0 ;
}
static long F_183 ( struct V_246 * V_246 , unsigned int V_260 , unsigned long V_318 )
{
struct V_175 * V_176 ;
int V_194 * V_319 = ( int V_194 * ) V_318 ;
int V_221 ;
V_176 = V_246 -> V_300 ;
if ( V_260 == V_320 )
return F_184 ( V_321 , V_319 ) ;
if ( V_260 == V_322 )
return F_184 ( 1 , V_319 ) ;
#if F_185 ( V_323 )
if ( ( ( V_260 >> 8 ) & 0xff ) == 'M' ) {
struct V_20 * V_49 ;
int V_178 ;
for ( V_178 = 0 ; V_178 < 2 ; ++ V_178 ) {
V_49 = V_176 -> V_180 [ V_178 ] ;
if ( V_49 != NULL )
break;
}
if ( F_43 ( V_178 >= 2 ) )
return - V_211 ;
return F_186 ( V_49 -> V_21 -> V_309 , V_260 , V_318 ) ;
}
#endif
if ( ( ( V_260 >> 8 ) & 0xff ) != 'P' )
return - V_7 ;
#ifdef F_103
F_187 ( L_24 , V_260 ) ;
#endif
switch ( V_260 ) {
case V_324 :
return F_121 ( V_176 ) ;
case V_325 :
return F_133 ( V_176 ) ;
case V_326 :
if ( F_188 ( V_221 , V_319 ) )
return - V_208 ;
if ( ( V_221 = F_134 ( V_176 , V_221 ) ) < 0 )
return V_221 ;
return F_184 ( V_221 , V_319 ) ;
case V_327 :
V_221 = F_135 ( V_176 ) ;
if ( V_221 < 0 )
return V_221 ;
return F_184 ( V_221 , V_319 ) ;
case V_328 :
if ( F_188 ( V_221 , V_319 ) )
return - V_208 ;
V_221 = V_221 > 0 ? 2 : 1 ;
if ( ( V_221 = F_136 ( V_176 , V_221 ) ) < 0 )
return V_221 ;
return F_184 ( -- V_221 , V_319 ) ;
case V_329 :
V_221 = F_138 ( V_176 ) ;
if ( V_221 < 0 )
return V_221 ;
return F_184 ( V_221 , V_319 ) ;
case V_330 :
if ( F_188 ( V_221 , V_319 ) )
return - V_208 ;
V_221 = F_140 ( V_176 , V_221 ) ;
if ( V_221 < 0 )
return V_221 ;
return F_184 ( V_221 , V_319 ) ;
case V_331 :
V_221 = F_141 ( V_176 ) ;
if ( V_221 < 0 )
return V_221 ;
return F_184 ( V_221 , V_319 ) ;
case V_332 :
if ( F_188 ( V_221 , V_319 ) )
return - V_208 ;
V_221 = F_136 ( V_176 , V_221 ) ;
if ( V_221 < 0 )
return V_221 ;
return F_184 ( V_221 , V_319 ) ;
case V_333 :
V_221 = F_137 ( V_176 ) ;
if ( V_221 < 0 )
return V_221 ;
return F_184 ( V_221 , V_319 ) ;
case V_334 :
case V_335 :
return - V_181 ;
case V_336 :
return F_122 ( V_176 ) ;
case V_337 :
if ( F_188 ( V_221 , V_319 ) )
return - V_208 ;
V_221 = F_143 ( V_176 , V_221 ) ;
if ( V_221 < 0 )
return V_221 ;
return F_184 ( V_221 , V_319 ) ;
case V_338 :
if ( F_188 ( V_221 , V_319 ) )
return - V_208 ;
return F_145 ( V_176 , V_221 ) ;
case V_339 :
V_221 = F_139 ( V_176 ) ;
if ( V_221 < 0 )
return V_221 ;
return F_184 ( V_221 , V_319 ) ;
case V_340 :
case V_341 :
return F_158 ( V_176 ,
V_260 == V_341 ?
V_160 : V_154 ,
(struct V_270 V_194 * ) V_318 ) ;
case V_342 :
return F_146 ( V_246 ) ;
case V_343 :
V_221 = F_152 ( V_176 ) ;
if ( V_221 < 0 )
return V_221 ;
return F_184 ( V_221 , V_319 ) ;
case V_344 :
V_221 = F_155 ( V_176 ) ;
if ( V_221 < 0 )
return V_221 ;
return F_184 ( V_221 , V_319 ) ;
case V_345 :
if ( F_188 ( V_221 , V_319 ) )
return - V_208 ;
return F_154 ( V_176 , V_221 ) ;
case V_346 :
case V_347 :
return F_157 ( V_176 ,
V_260 == V_346 ?
V_160 : V_154 ,
(struct V_265 V_194 * ) V_318 ) ;
case V_348 :
case V_349 :
return F_159 ( V_176 ,
V_260 == V_348 ?
V_160 : V_154 ,
(struct V_275 V_194 * ) V_318 ) ;
case V_350 :
return 0 ;
case V_351 :
if ( F_152 ( V_176 ) & V_248 )
return 0 ;
return - V_181 ;
case V_352 :
V_221 = F_156 ( V_176 ) ;
if ( V_221 < 0 ) {
F_184 ( 0 , V_319 ) ;
return V_221 ;
}
return F_184 ( V_221 , V_319 ) ;
case V_353 :
return 0 ;
default:
F_187 ( L_25 , V_260 ) ;
}
return - V_7 ;
}
static long F_189 ( struct V_246 * V_246 , unsigned int V_260 ,
unsigned long V_318 )
{
return F_183 ( V_246 , V_260 , ( unsigned long ) F_190 ( V_318 ) ) ;
}
static T_7 F_191 ( struct V_246 * V_246 , char V_194 * V_202 , T_6 V_354 , T_12 * V_355 )
{
struct V_175 * V_176 ;
struct V_20 * V_49 ;
V_176 = V_246 -> V_300 ;
V_49 = V_176 -> V_180 [ V_160 ] ;
if ( V_49 == NULL )
return - V_211 ;
V_49 -> V_213 = V_246 -> V_213 & V_214 ;
#ifndef F_103
return F_120 ( V_49 , V_202 , V_354 ) ;
#else
{
T_7 V_221 = F_120 ( V_49 , V_202 , V_354 ) ;
F_79 ( V_49 -> V_21 ,
L_26 ,
( long ) V_354 , ( long ) V_221 ) ;
return V_221 ;
}
#endif
}
static T_7 F_192 ( struct V_246 * V_246 , const char V_194 * V_202 , T_6 V_354 , T_12 * V_355 )
{
struct V_175 * V_176 ;
struct V_20 * V_49 ;
long V_220 ;
V_176 = V_246 -> V_300 ;
V_49 = V_176 -> V_180 [ V_154 ] ;
if ( V_49 == NULL )
return - V_211 ;
V_49 -> V_213 = V_246 -> V_213 & V_214 ;
V_220 = F_115 ( V_49 , V_202 , V_354 ) ;
#ifdef F_103
F_79 ( V_49 -> V_21 , L_27 ,
( long ) V_354 , ( long ) V_220 ) ;
#endif
return V_220 ;
}
static int F_193 ( struct V_20 * V_49 )
{
struct V_50 * V_51 = V_49 -> V_51 ;
if ( F_69 ( & V_49 -> V_112 ) )
return V_51 -> V_55 . V_183 !=
F_60 ( V_51 ) ;
else
return F_194 ( V_51 ) >=
V_51 -> V_55 . V_125 ;
}
static int F_195 ( struct V_20 * V_49 )
{
struct V_50 * V_51 = V_49 -> V_51 ;
if ( F_69 ( & V_49 -> V_112 ) )
return V_51 -> V_55 . V_183 !=
F_60 ( V_51 ) ;
else
return F_196 ( V_51 ) >=
V_51 -> V_55 . V_125 ;
}
static unsigned int F_197 ( struct V_246 * V_246 , T_13 * V_222 )
{
struct V_175 * V_176 ;
unsigned int V_139 ;
struct V_20 * V_258 = NULL , * V_259 = NULL ;
V_176 = V_246 -> V_300 ;
V_258 = V_176 -> V_180 [ V_154 ] ;
V_259 = V_176 -> V_180 [ V_160 ] ;
V_139 = 0 ;
if ( V_258 != NULL ) {
struct V_50 * V_51 = V_258 -> V_51 ;
F_198 ( V_246 , & V_51 -> V_224 , V_222 ) ;
F_127 ( V_258 ) ;
if ( V_51 -> V_190 -> V_191 != V_200 &&
( V_51 -> V_190 -> V_191 != V_226 ||
F_193 ( V_258 ) ) )
V_139 |= V_356 | V_357 ;
F_128 ( V_258 ) ;
}
if ( V_259 != NULL ) {
struct V_50 * V_51 = V_259 -> V_51 ;
T_9 V_358 ;
F_198 ( V_246 , & V_51 -> V_224 , V_222 ) ;
F_127 ( V_259 ) ;
if ( ( V_358 = V_51 -> V_190 -> V_191 ) != V_226 ||
F_195 ( V_259 ) )
V_139 |= V_359 | V_360 ;
F_128 ( V_259 ) ;
if ( V_358 != V_226 && V_51 -> V_55 . V_157 ) {
struct V_175 V_361 ;
memset ( & V_361 , 0 , sizeof( V_361 ) ) ;
V_361 . V_180 [ V_160 ] = V_176 -> V_180 [ V_160 ] ;
V_51 -> V_55 . V_157 = 0 ;
F_154 ( & V_361 , V_263 ) ;
}
}
return V_139 ;
}
static int F_199 ( struct V_246 * V_246 , struct V_362 * V_363 )
{
struct V_175 * V_176 ;
struct V_20 * V_49 = NULL ;
struct V_50 * V_51 ;
int V_22 ;
#ifdef F_103
F_187 ( L_28 ) ;
#endif
V_176 = V_246 -> V_300 ;
switch ( ( V_363 -> V_364 & ( V_365 | V_366 ) ) ) {
case V_365 | V_366 :
V_49 = V_176 -> V_180 [ V_154 ] ;
if ( V_49 )
break;
case V_365 :
V_49 = V_176 -> V_180 [ V_160 ] ;
break;
case V_366 :
V_49 = V_176 -> V_180 [ V_154 ] ;
break;
default:
return - V_7 ;
}
V_363 -> V_364 |= V_365 ;
if ( V_49 == NULL )
return - V_211 ;
V_51 = V_49 -> V_51 ;
if ( ! ( V_51 -> V_252 & V_367 ) )
return - V_181 ;
if ( V_51 -> V_252 & V_368 )
V_51 -> V_235 = V_145 ;
else
return - V_181 ;
if ( V_51 -> V_55 . V_14 ) {
V_22 = F_73 ( V_49 , true ) ;
if ( V_22 < 0 )
return V_22 ;
}
#ifdef F_84
if ( V_51 -> V_55 . V_56 != NULL )
return - V_181 ;
#endif
if ( V_363 -> V_369 != 0 )
return - V_7 ;
V_22 = F_200 ( V_49 , V_246 , V_363 ) ;
if ( V_22 < 0 )
return V_22 ;
V_51 -> V_55 . V_113 = V_363 -> V_370 - V_363 -> V_371 ;
V_51 -> V_167 = 0 ;
V_51 -> V_168 = 0 ;
#ifdef F_103
F_187 ( L_29 ,
V_51 -> V_55 . V_113 ) ;
#endif
V_51 -> V_161 = V_51 -> V_159 ;
return 0 ;
}
static void F_201 ( struct V_372 * V_373 ,
struct V_374 * V_170 )
{
struct V_375 * V_249 = V_373 -> V_300 ;
struct V_280 * V_114 = V_249 -> V_55 . V_283 ;
F_116 ( & V_249 -> V_55 . V_282 ) ;
while ( V_114 ) {
F_202 ( V_170 , L_30 ,
V_114 -> V_279 ,
V_114 -> V_121 ,
V_114 -> V_115 ,
V_114 -> V_299 ? L_31 : L_32 ,
V_114 -> V_135 ? L_33 : L_32 ,
V_114 -> V_287 ? L_34 : L_32 ,
V_114 -> V_286 ? L_35 : L_32 ,
V_114 -> V_212 ? L_36 : L_32 ,
V_114 -> V_166 ? L_37 : L_32 ) ;
V_114 = V_114 -> V_54 ;
}
F_97 ( & V_249 -> V_55 . V_282 ) ;
}
static void F_203 ( struct V_375 * V_249 )
{
struct V_280 * V_114 , * V_376 ;
for ( V_114 = V_249 -> V_55 . V_283 , V_249 -> V_55 . V_283 = NULL ;
V_114 ; V_114 = V_376 ) {
V_376 = V_114 -> V_54 ;
F_40 ( V_114 -> V_279 ) ;
F_40 ( V_114 ) ;
}
V_249 -> V_55 . V_283 = NULL ;
}
static void F_204 ( struct V_372 * V_373 ,
struct V_374 * V_170 )
{
struct V_375 * V_249 = V_373 -> V_300 ;
char line [ 128 ] , V_377 [ 32 ] , V_279 [ 32 ] ;
const char * V_188 ;
int V_378 ;
struct V_280 * V_114 , * V_379 , V_380 ;
while ( ! F_205 ( V_170 , line , sizeof( line ) ) ) {
F_116 ( & V_249 -> V_55 . V_282 ) ;
memset ( & V_380 , 0 , sizeof( V_380 ) ) ;
V_188 = F_206 ( V_279 , line , sizeof( V_279 ) ) ;
if ( ! strcmp ( V_279 , L_38 ) || ! strcmp ( V_279 , L_39 ) ) {
F_203 ( V_249 ) ;
F_97 ( & V_249 -> V_55 . V_282 ) ;
continue;
}
for ( V_114 = V_249 -> V_55 . V_283 ; V_114 ; V_114 = V_114 -> V_54 ) {
if ( ! strcmp ( V_114 -> V_279 , V_279 ) ) {
V_380 = * V_114 ;
break;
}
}
V_188 = F_206 ( V_377 , V_188 , sizeof( V_377 ) ) ;
V_380 . V_121 = F_207 ( V_377 , NULL , 10 ) ;
V_188 = F_206 ( V_377 , V_188 , sizeof( V_377 ) ) ;
V_380 . V_115 = F_207 ( V_377 , NULL , 10 ) ;
for ( V_378 = 31 ; V_378 >= 0 ; V_378 -- )
if ( V_380 . V_115 & ( 1 << V_378 ) )
break;
for ( V_378 -- ; V_378 >= 0 ; V_378 -- )
V_380 . V_115 &= ~ ( 1 << V_378 ) ;
do {
V_188 = F_206 ( V_377 , V_188 , sizeof( V_377 ) ) ;
if ( ! strcmp ( V_377 , L_40 ) ) {
V_380 . V_299 = 1 ;
} else if ( ! strcmp ( V_377 , L_41 ) ) {
V_380 . V_135 = 1 ;
} else if ( ! strcmp ( V_377 , L_42 ) ) {
V_380 . V_287 = 1 ;
} else if ( ! strcmp ( V_377 , L_43 ) ) {
V_380 . V_286 = 1 ;
} else if ( ! strcmp ( V_377 , L_44 ) ) {
V_380 . V_212 = 1 ;
} else if ( ! strcmp ( V_377 , L_45 ) ) {
V_380 . V_166 = 1 ;
} else if ( ! strcmp ( V_377 , L_46 ) ) {
V_380 . V_269 = 1 ;
}
} while ( * V_377 );
if ( V_114 == NULL ) {
V_114 = F_39 ( sizeof( * V_114 ) , V_44 ) ;
if ( ! V_114 ) {
V_170 -> error = - V_45 ;
F_97 ( & V_249 -> V_55 . V_282 ) ;
return;
}
if ( V_249 -> V_55 . V_283 == NULL )
V_249 -> V_55 . V_283 = V_114 ;
else {
for ( V_379 = V_249 -> V_55 . V_283 ;
V_379 -> V_54 ; V_379 = V_379 -> V_54 ) ;
V_379 -> V_54 = V_114 ;
}
V_380 . V_279 = F_208 ( V_279 , V_44 ) ;
if ( ! V_380 . V_279 ) {
F_40 ( V_114 ) ;
V_170 -> error = - V_45 ;
F_97 ( & V_249 -> V_55 . V_282 ) ;
return;
}
}
* V_114 = V_380 ;
F_97 ( & V_249 -> V_55 . V_282 ) ;
}
}
static void F_209 ( struct V_278 * V_21 )
{
int V_153 ;
for ( V_153 = 0 ; V_153 < 2 ; ++ V_153 ) {
struct V_372 * V_373 ;
struct V_375 * V_249 = & V_21 -> V_180 [ V_153 ] ;
if ( V_249 -> V_250 == 0 )
continue;
if ( ( V_373 = F_210 ( V_21 -> V_309 , L_47 , V_249 -> V_381 ) ) != NULL ) {
V_373 -> V_382 = V_383 ;
V_373 -> V_384 = V_385 | V_386 | V_387 ;
V_373 -> V_28 . V_388 . V_389 = F_201 ;
V_373 -> V_28 . V_388 . V_390 = F_204 ;
V_373 -> V_300 = V_249 ;
if ( F_211 ( V_373 ) < 0 ) {
F_212 ( V_373 ) ;
V_373 = NULL ;
}
}
V_249 -> V_55 . V_391 = V_373 ;
}
}
static void F_213 ( struct V_278 * V_21 )
{
int V_153 ;
for ( V_153 = 0 ; V_153 < 2 ; ++ V_153 ) {
struct V_375 * V_249 = & V_21 -> V_180 [ V_153 ] ;
F_212 ( V_249 -> V_55 . V_391 ) ;
V_249 -> V_55 . V_391 = NULL ;
F_203 ( V_249 ) ;
}
}
static void F_214 ( struct V_278 * V_21 , int V_392 )
{
if ( F_215 ( V_306 ,
V_21 -> V_309 , V_392 , & V_393 ,
V_21 ) < 0 ) {
F_131 ( V_21 , L_48 ,
V_21 -> V_309 -> V_394 , V_21 -> V_395 ) ;
}
}
static int F_216 ( struct V_278 * V_21 )
{
V_21 -> V_55 . V_396 = 0 ;
if ( V_397 [ V_21 -> V_309 -> V_394 ] == ( int ) V_21 -> V_395 ) {
char V_303 [ 128 ] ;
int V_398 ;
F_214 ( V_21 , 0 ) ;
V_398 = ( V_21 -> V_180 [ V_154 ] . V_250 > 0 &&
V_21 -> V_180 [ V_160 ] . V_250 &&
! ( V_21 -> V_296 & V_297 ) ) ;
sprintf ( V_303 , L_49 , V_21 -> V_303 , V_398 ? L_50 : L_32 ) ;
#ifdef F_217
F_218 ( F_217 ,
V_21 -> V_309 -> V_394 ,
V_303 ) ;
#endif
V_21 -> V_55 . V_396 ++ ;
V_21 -> V_55 . V_399 |= 1 ;
}
if ( V_400 [ V_21 -> V_309 -> V_394 ] == ( int ) V_21 -> V_395 ) {
F_214 ( V_21 , 1 ) ;
V_21 -> V_55 . V_396 ++ ;
V_21 -> V_55 . V_399 |= 2 ;
}
if ( V_21 -> V_55 . V_396 )
F_209 ( V_21 ) ;
return 0 ;
}
static int F_219 ( struct V_278 * V_21 )
{
if ( V_21 -> V_55 . V_396 ) {
if ( V_21 -> V_55 . V_399 & 1 ) {
V_21 -> V_55 . V_399 &= ~ 1 ;
F_220 ( V_306 ,
V_21 -> V_309 , 0 ) ;
}
if ( V_21 -> V_55 . V_399 & 2 ) {
V_21 -> V_55 . V_399 &= ~ 2 ;
F_220 ( V_306 ,
V_21 -> V_309 , 1 ) ;
}
if ( V_397 [ V_21 -> V_309 -> V_394 ] == ( int ) V_21 -> V_395 ) {
#ifdef F_217
F_221 ( F_217 , V_21 -> V_309 -> V_394 ) ;
#endif
}
V_21 -> V_55 . V_396 = 0 ;
}
return 0 ;
}
static int F_222 ( struct V_278 * V_21 )
{
F_219 ( V_21 ) ;
F_213 ( V_21 ) ;
return 0 ;
}
static int T_14 F_223 ( void )
{
int V_3 ;
int V_22 ;
for ( V_3 = 0 ; V_3 < V_401 ; V_3 ++ ) {
if ( V_397 [ V_3 ] < 0 || V_397 [ V_3 ] >= V_402 ) {
F_224 ( L_51 ,
V_3 , V_397 [ V_3 ] ) ;
V_397 [ V_3 ] = 0 ;
}
if ( V_400 [ V_3 ] < 0 || V_400 [ V_3 ] >= V_402 ) {
F_224 ( L_52 ,
V_3 , V_400 [ V_3 ] ) ;
V_400 [ V_3 ] = 1 ;
}
}
if ( ( V_22 = F_225 ( & V_403 , 0 ) ) < 0 )
return V_22 ;
return 0 ;
}
static void T_15 F_226 ( void )
{
F_225 ( & V_403 , 1 ) ;
}
