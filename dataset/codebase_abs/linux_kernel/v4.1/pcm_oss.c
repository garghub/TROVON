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
static int F_73 ( struct V_20 * V_49 )
{
struct V_50 * V_51 = V_49 -> V_51 ;
struct V_13 * V_14 , * V_131 ;
struct V_132 * V_133 ;
T_7 V_105 , V_106 ;
T_6 V_110 ;
int V_22 ;
int V_134 ;
T_5 V_67 , V_135 ;
int V_136 ;
struct V_17 V_137 ;
struct V_17 V_138 ;
if ( F_74 ( & V_51 -> V_55 . V_139 ) )
return - V_140 ;
V_133 = F_39 ( sizeof( * V_133 ) , V_44 ) ;
V_14 = F_39 ( sizeof( * V_14 ) , V_44 ) ;
V_131 = F_39 ( sizeof( * V_131 ) , V_44 ) ;
if ( ! V_133 || ! V_14 || ! V_131 ) {
V_22 = - V_45 ;
goto V_141;
}
if ( F_69 ( & V_49 -> V_112 ) )
V_134 = 1 ;
else
V_134 = V_49 -> V_55 . V_114 . V_134 ;
F_75 ( V_131 ) ;
F_48 ( V_131 , V_122 ) ;
F_27 ( V_131 , V_122 , 2 , 0 ) ;
F_32 ( & V_138 ) ;
if ( F_69 ( & V_49 -> V_112 ) )
F_76 ( & V_138 , ( V_142 int ) V_143 ) ;
else {
F_76 ( & V_138 , ( V_142 int ) V_144 ) ;
if ( ! V_134 )
F_76 ( & V_138 , ( V_142 int ) V_145 ) ;
}
V_22 = F_25 ( V_49 , V_131 , V_146 , & V_138 ) ;
if ( V_22 < 0 ) {
F_77 ( V_49 -> V_21 , L_1 ) ;
V_22 = - V_7 ;
goto V_141;
}
F_72 ( V_49 , V_131 , V_51 -> V_55 . V_128 ) ;
F_38 ( V_49 , V_131 , V_147 , V_51 -> V_55 . V_148 , NULL ) ;
V_67 = F_61 ( V_51 -> V_55 . V_67 ) ;
V_137 = * F_24 ( V_131 , V_149 ) ;
if ( V_134 )
V_135 = V_67 ;
else
V_135 = F_78 ( V_67 , & V_137 ) ;
if ( ( V_142 int ) V_135 < 0 ||
! F_79 ( & V_137 , ( V_142 int ) V_135 ) ) {
for ( V_135 = ( V_142 T_5 ) 0 ;
( V_142 int ) V_135 <= ( V_142 int ) V_150 ;
V_135 = ( V_142 T_5 ) ( ( V_142 int ) V_135 + 1 ) ) {
if ( F_79 ( & V_137 , ( V_142 int ) V_135 ) &&
F_62 ( V_135 ) >= 0 )
break;
}
if ( ( V_142 int ) V_135 > ( V_142 int ) V_150 ) {
F_77 ( V_49 -> V_21 , L_2 ) ;
V_22 = - V_7 ;
goto V_141;
}
}
V_22 = F_44 ( V_131 , V_149 , ( V_142 int ) V_135 , 0 ) ;
if ( V_22 < 0 )
goto V_141;
if ( V_134 ) {
memcpy ( V_14 , V_131 , sizeof( * V_14 ) ) ;
} else {
F_75 ( V_14 ) ;
F_44 ( V_14 , V_146 ,
( V_142 int ) V_144 , 0 ) ;
F_44 ( V_14 , V_149 ,
( V_142 int ) F_61 ( V_51 -> V_55 . V_67 ) , 0 ) ;
F_44 ( V_14 , V_147 ,
V_51 -> V_55 . V_148 , 0 ) ;
F_44 ( V_14 , V_129 ,
V_51 -> V_55 . V_128 , 0 ) ;
F_80 ( L_3 ,
F_81 ( V_14 ) , F_65 ( V_14 ) ,
F_66 ( V_14 ) , F_70 ( V_14 ) ) ;
}
F_80 ( L_4 ,
F_81 ( V_131 ) , F_65 ( V_131 ) ,
F_66 ( V_131 ) , F_70 ( V_131 ) ) ;
V_110 = F_64 ( F_65 ( V_14 ) ) *
F_66 ( V_14 ) / 8 ;
#ifdef F_82
F_50 ( V_49 ) ;
if ( ! V_134 ) {
F_50 ( V_49 ) ;
if ( ( V_22 = F_83 ( V_49 ,
V_14 ,
V_131 ) ) < 0 ) {
F_77 ( V_49 -> V_21 ,
L_5 , V_22 ) ;
F_50 ( V_49 ) ;
goto V_141;
}
if ( V_51 -> V_55 . V_56 ) {
struct V_52 * V_53 ;
if ( ( V_22 = F_84 ( V_49 , V_131 , & V_53 ) ) < 0 ) {
F_77 ( V_49 -> V_21 ,
L_6 , V_22 ) ;
F_50 ( V_49 ) ;
goto V_141;
}
if ( V_49 -> V_151 == V_152 ) {
V_22 = F_53 ( V_53 ) ;
} else {
V_22 = F_52 ( V_53 ) ;
}
if ( V_22 < 0 ) {
F_50 ( V_49 ) ;
goto V_141;
}
}
}
#endif
V_22 = F_63 ( V_49 , V_14 , V_131 ) ;
if ( V_22 < 0 )
goto V_141;
V_136 = F_85 ( V_49 , V_51 -> V_55 . V_124 / V_110 ) ;
V_22 = F_38 ( V_49 , V_131 , V_120 , V_136 , NULL ) ;
if ( V_22 < 0 )
goto V_141;
V_22 = F_38 ( V_49 , V_131 , V_122 ,
V_51 -> V_55 . V_121 , NULL ) ;
if ( V_22 < 0 )
goto V_141;
F_86 ( V_49 , V_153 , NULL ) ;
if ( ( V_22 = F_86 ( V_49 , V_154 , V_131 ) ) < 0 ) {
F_77 ( V_49 -> V_21 , L_7 , V_22 ) ;
goto V_141;
}
memset ( V_133 , 0 , sizeof( * V_133 ) ) ;
if ( V_51 -> V_55 . V_155 ) {
V_133 -> V_156 = 1 ;
} else {
V_133 -> V_156 = V_51 -> V_157 ;
}
if ( F_69 ( & V_49 -> V_112 ) ||
V_49 -> V_151 == V_158 )
V_133 -> V_159 = V_51 -> V_157 ;
else
V_133 -> V_159 = V_51 -> V_61 ;
V_133 -> V_160 = V_161 ;
V_133 -> V_162 = 1 ;
V_133 -> V_163 = V_49 -> V_151 == V_152 ?
1 : V_51 -> V_115 ;
if ( F_69 ( & V_49 -> V_112 ) ||
V_49 -> V_55 . V_114 . V_164 ) {
V_133 -> V_165 = 0 ;
V_133 -> V_166 = 0 ;
} else {
T_4 V_60 ;
V_60 = V_51 -> V_115 + 16 ;
if ( V_60 > V_51 -> V_61 )
V_60 = V_51 -> V_61 ;
V_133 -> V_165 = V_60 ;
V_133 -> V_166 = V_60 ;
}
if ( ( V_22 = F_86 ( V_49 , V_167 , V_133 ) ) < 0 ) {
F_77 ( V_49 -> V_21 , L_8 , V_22 ) ;
goto V_141;
}
V_51 -> V_55 . V_121 = F_87 ( V_131 ) ;
V_106 = F_67 ( V_49 , F_88 ( V_131 ) ) ;
if ( V_106 < 0 ) {
V_22 = - V_7 ;
goto V_141;
}
#ifdef F_82
if ( V_51 -> V_55 . V_56 ) {
V_22 = F_89 ( V_49 , V_106 ) ;
if ( V_22 < 0 )
goto V_141;
}
#endif
V_106 *= V_110 ;
V_105 = V_106 * V_51 -> V_55 . V_121 ;
if ( V_105 < 0 ) {
V_22 = - V_7 ;
goto V_141;
}
V_51 -> V_55 . V_124 = V_106 ;
V_51 -> V_55 . V_63 = V_105 ;
F_80 ( L_9 ,
V_51 -> V_55 . V_124 ,
V_51 -> V_55 . V_63 ) ;
F_80 ( L_10 ,
F_88 ( V_131 ) ,
F_90 ( V_131 ) ) ;
V_51 -> V_55 . V_67 = F_62 ( F_65 ( V_14 ) ) ;
V_51 -> V_55 . V_148 = F_66 ( V_14 ) ;
V_51 -> V_55 . V_128 = F_70 ( V_14 ) ;
F_91 ( V_51 -> V_55 . V_168 ) ;
V_51 -> V_55 . V_168 = F_92 ( V_51 -> V_55 . V_124 ) ;
if ( ! V_51 -> V_55 . V_168 ) {
V_22 = - V_45 ;
goto V_141;
}
V_51 -> V_55 . V_14 = 0 ;
V_51 -> V_55 . V_169 = 1 ;
V_51 -> V_55 . V_170 = 0 ;
if ( V_51 -> V_171 )
F_93 ( V_51 -> V_67 , V_51 -> V_171 , F_94 ( V_51 , V_51 -> V_172 ) ) ;
V_51 -> V_55 . V_125 = F_58 ( V_49 , V_106 ) ;
V_22 = 0 ;
V_141:
F_40 ( V_133 ) ;
F_40 ( V_14 ) ;
F_40 ( V_131 ) ;
F_95 ( & V_51 -> V_55 . V_139 ) ;
return V_22 ;
}
static int F_96 ( struct V_173 * V_174 , struct V_20 * * V_175 )
{
int V_176 , V_22 ;
struct V_20 * V_177 = NULL , * V_49 ;
for ( V_176 = 0 ; V_176 < 2 ; V_176 ++ ) {
V_49 = V_174 -> V_178 [ V_176 ] ;
if ( V_49 == NULL )
continue;
if ( V_177 == NULL )
V_177 = V_49 ;
if ( V_49 -> V_51 -> V_55 . V_14 ) {
V_22 = F_73 ( V_49 ) ;
if ( V_22 < 0 )
return V_22 ;
}
}
if ( ! V_177 )
return - V_179 ;
if ( V_175 )
* V_175 = V_177 ;
return 0 ;
}
static int F_97 ( struct V_20 * V_49 )
{
int V_22 ;
struct V_50 * V_51 = V_49 -> V_51 ;
V_22 = F_86 ( V_49 , V_180 , NULL ) ;
if ( V_22 < 0 ) {
F_77 ( V_49 -> V_21 ,
L_11 ) ;
return V_22 ;
}
V_51 -> V_55 . V_169 = 0 ;
V_51 -> V_55 . V_181 = 0 ;
V_51 -> V_55 . V_182 = 0 ;
V_51 -> V_55 . V_170 = 0 ;
return 0 ;
}
static int F_98 ( struct V_20 * V_49 )
{
struct V_50 * V_51 ;
int V_22 ;
if ( V_49 == NULL )
return 0 ;
V_51 = V_49 -> V_51 ;
if ( V_51 -> V_55 . V_14 ) {
V_22 = F_73 ( V_49 ) ;
if ( V_22 < 0 )
return V_22 ;
}
if ( V_51 -> V_55 . V_169 ) {
V_22 = F_97 ( V_49 ) ;
if ( V_22 < 0 )
return V_22 ;
}
return 0 ;
}
static int F_99 ( struct V_20 * V_49 , T_8 * V_183 )
{
struct V_50 * V_51 ;
T_4 V_60 ;
int V_22 = 0 ;
while ( 1 ) {
V_22 = F_86 ( V_49 , V_184 , V_183 ) ;
if ( V_22 < 0 )
break;
V_51 = V_49 -> V_51 ;
if ( * V_183 <= ( T_8 ) V_51 -> V_61 )
break;
V_60 = ( * V_183 - V_51 -> V_61 ) + V_51 -> V_115 - 1 ;
V_60 /= V_51 -> V_115 ;
V_60 *= V_51 -> V_115 ;
V_22 = F_86 ( V_49 , V_185 , & V_60 ) ;
if ( V_22 < 0 )
break;
}
return V_22 ;
}
T_8 F_100 ( struct V_20 * V_49 , const char * V_186 , T_4 V_60 , int V_187 )
{
struct V_50 * V_51 = V_49 -> V_51 ;
int V_130 ;
while ( 1 ) {
if ( V_51 -> V_188 -> V_189 == V_190 ||
V_51 -> V_188 -> V_189 == V_191 ) {
#ifdef F_101
F_77 ( V_49 -> V_21 ,
L_12 ,
V_51 -> V_188 -> V_189 == V_190 ?
L_13 : L_14 ) ;
#endif
V_130 = F_97 ( V_49 ) ;
if ( V_130 < 0 )
break;
}
if ( V_187 ) {
T_1 V_1 ;
V_1 = F_1 () ;
V_130 = F_102 ( V_49 , ( void V_142 V_192 * ) V_186 , V_60 ) ;
F_5 ( V_1 ) ;
} else {
V_130 = F_102 ( V_49 , ( void V_142 V_192 * ) V_186 , V_60 ) ;
}
if ( V_130 != - V_193 && V_130 != - V_194 )
break;
if ( V_51 -> V_188 -> V_189 == V_195 )
return - V_196 ;
}
return V_130 ;
}
T_8 F_103 ( struct V_20 * V_49 , char * V_186 , T_4 V_60 , int V_187 )
{
struct V_50 * V_51 = V_49 -> V_51 ;
T_8 V_183 ;
int V_130 ;
while ( 1 ) {
if ( V_51 -> V_188 -> V_189 == V_190 ||
V_51 -> V_188 -> V_189 == V_191 ) {
#ifdef F_101
F_77 ( V_49 -> V_21 ,
L_15 ,
V_51 -> V_188 -> V_189 == V_190 ?
L_13 : L_14 ) ;
#endif
V_130 = F_86 ( V_49 , V_197 , NULL ) ;
if ( V_130 < 0 )
break;
} else if ( V_51 -> V_188 -> V_189 == V_198 ) {
V_130 = F_97 ( V_49 ) ;
if ( V_130 < 0 )
break;
}
V_130 = F_99 ( V_49 , & V_183 ) ;
if ( V_130 < 0 )
break;
if ( V_187 ) {
T_1 V_1 ;
V_1 = F_1 () ;
V_130 = F_104 ( V_49 , ( void V_142 V_192 * ) V_186 , V_60 ) ;
F_5 ( V_1 ) ;
} else {
V_130 = F_104 ( V_49 , ( void V_142 V_192 * ) V_186 , V_60 ) ;
}
if ( V_130 == - V_193 ) {
if ( V_51 -> V_188 -> V_189 == V_199 ) {
V_130 = F_86 ( V_49 , V_153 , NULL ) ;
if ( V_130 < 0 )
break;
}
continue;
}
if ( V_130 != - V_194 )
break;
}
return V_130 ;
}
T_8 F_105 ( struct V_20 * V_49 , void * * V_200 , T_4 V_60 , int V_187 )
{
struct V_50 * V_51 = V_49 -> V_51 ;
int V_130 ;
while ( 1 ) {
if ( V_51 -> V_188 -> V_189 == V_190 ||
V_51 -> V_188 -> V_189 == V_191 ) {
#ifdef F_101
F_77 ( V_49 -> V_21 ,
L_16 ,
V_51 -> V_188 -> V_189 == V_190 ?
L_13 : L_14 ) ;
#endif
V_130 = F_97 ( V_49 ) ;
if ( V_130 < 0 )
break;
}
if ( V_187 ) {
T_1 V_1 ;
V_1 = F_1 () ;
V_130 = F_106 ( V_49 , ( void V_192 * * ) V_200 , V_60 ) ;
F_5 ( V_1 ) ;
} else {
V_130 = F_106 ( V_49 , ( void V_192 * * ) V_200 , V_60 ) ;
}
if ( V_130 != - V_193 && V_130 != - V_194 )
break;
if ( V_51 -> V_188 -> V_189 == V_195 )
return - V_196 ;
}
return V_130 ;
}
T_8 F_107 ( struct V_20 * V_49 , void * * V_200 , T_4 V_60 , int V_187 )
{
struct V_50 * V_51 = V_49 -> V_51 ;
int V_130 ;
while ( 1 ) {
if ( V_51 -> V_188 -> V_189 == V_190 ||
V_51 -> V_188 -> V_189 == V_191 ) {
#ifdef F_101
F_77 ( V_49 -> V_21 ,
L_17 ,
V_51 -> V_188 -> V_189 == V_190 ?
L_13 : L_14 ) ;
#endif
V_130 = F_86 ( V_49 , V_197 , NULL ) ;
if ( V_130 < 0 )
break;
} else if ( V_51 -> V_188 -> V_189 == V_198 ) {
V_130 = F_97 ( V_49 ) ;
if ( V_130 < 0 )
break;
}
if ( V_187 ) {
T_1 V_1 ;
V_1 = F_1 () ;
V_130 = F_108 ( V_49 , ( void V_192 * * ) V_200 , V_60 ) ;
F_5 ( V_1 ) ;
} else {
V_130 = F_108 ( V_49 , ( void V_192 * * ) V_200 , V_60 ) ;
}
if ( V_130 != - V_193 && V_130 != - V_194 )
break;
}
return V_130 ;
}
static T_7 F_109 ( struct V_20 * V_49 , const char * V_201 , T_6 V_62 , int V_187 )
{
struct V_50 * V_51 = V_49 -> V_51 ;
T_8 V_60 , V_202 ;
#ifdef F_82
if ( V_51 -> V_55 . V_56 ) {
struct V_203 * V_148 ;
T_6 V_204 = ( V_51 -> V_55 . V_56 -> V_205 * V_51 -> V_55 . V_56 -> V_206 . V_148 ) / 8 ;
if ( ! V_187 ) {
if ( F_110 ( V_51 -> V_55 . V_168 , ( const char V_142 V_192 * ) V_201 , V_62 ) )
return - V_207 ;
V_201 = V_51 -> V_55 . V_168 ;
}
V_60 = V_62 / V_204 ;
V_202 = F_111 ( V_49 , ( char * ) V_201 , V_60 , & V_148 ) ;
if ( V_202 < 0 )
return V_202 ;
V_202 = F_112 ( V_49 , V_148 , V_202 ) ;
if ( V_202 <= 0 )
return V_202 ;
V_62 = V_202 * V_204 ;
} else
#endif
{
V_60 = F_59 ( V_51 , V_62 ) ;
V_202 = F_100 ( V_49 , V_201 , V_60 , V_187 ) ;
if ( V_202 <= 0 )
return V_202 ;
V_62 = F_56 ( V_51 , V_202 ) ;
}
return V_62 ;
}
static T_7 F_113 ( struct V_20 * V_49 , const char V_192 * V_201 , T_6 V_62 )
{
T_6 V_208 = 0 ;
T_7 V_209 ;
struct V_50 * V_51 = V_49 -> V_51 ;
if ( F_69 ( & V_49 -> V_112 ) )
return - V_210 ;
if ( ( V_209 = F_98 ( V_49 ) ) < 0 )
return V_209 ;
F_114 ( & V_51 -> V_55 . V_139 ) ;
while ( V_62 > 0 ) {
if ( V_62 < V_51 -> V_55 . V_124 || V_51 -> V_55 . V_170 > 0 ) {
V_209 = V_62 ;
if ( V_209 + V_51 -> V_55 . V_170 > V_51 -> V_55 . V_124 )
V_209 = V_51 -> V_55 . V_124 - V_51 -> V_55 . V_170 ;
if ( V_209 > 0 ) {
if ( F_110 ( V_51 -> V_55 . V_168 + V_51 -> V_55 . V_170 , V_201 , V_209 ) ) {
V_209 = - V_207 ;
goto V_22;
}
}
V_51 -> V_55 . V_170 += V_209 ;
V_201 += V_209 ;
V_62 -= V_209 ;
V_208 += V_209 ;
if ( V_49 -> V_55 . V_114 . V_211 ||
V_51 -> V_55 . V_170 == V_51 -> V_55 . V_124 ) {
V_209 = F_109 ( V_49 , V_51 -> V_55 . V_168 + V_51 -> V_55 . V_182 ,
V_51 -> V_55 . V_170 - V_51 -> V_55 . V_182 , 1 ) ;
if ( V_209 <= 0 )
goto V_22;
V_51 -> V_55 . V_62 += V_209 ;
V_51 -> V_55 . V_182 += V_209 ;
V_51 -> V_55 . V_182 %= V_51 -> V_55 . V_124 ;
if ( V_51 -> V_55 . V_182 == 0 ||
V_51 -> V_55 . V_182 == V_51 -> V_55 . V_170 )
V_51 -> V_55 . V_170 = 0 ;
else if ( ( V_49 -> V_212 & V_213 ) != 0 ) {
V_209 = - V_196 ;
goto V_22;
}
}
} else {
V_209 = F_109 ( V_49 ,
( const char V_142 * ) V_201 ,
V_51 -> V_55 . V_124 , 0 ) ;
if ( V_209 <= 0 )
goto V_22;
V_51 -> V_55 . V_62 += V_209 ;
V_201 += V_209 ;
V_62 -= V_209 ;
V_208 += V_209 ;
if ( ( V_49 -> V_212 & V_213 ) != 0 &&
V_209 != V_51 -> V_55 . V_124 )
break;
}
}
F_95 ( & V_51 -> V_55 . V_139 ) ;
return V_208 ;
V_22:
F_95 ( & V_51 -> V_55 . V_139 ) ;
return V_208 > 0 ? ( T_8 ) V_208 : V_209 ;
}
static T_7 F_115 ( struct V_20 * V_49 , char * V_201 , T_6 V_62 , int V_187 )
{
struct V_50 * V_51 = V_49 -> V_51 ;
T_8 V_60 , V_202 ;
#ifdef F_82
char V_192 * V_214 = ( char V_142 V_192 * ) V_201 ;
if ( V_51 -> V_55 . V_56 ) {
struct V_203 * V_148 ;
T_6 V_204 = ( V_51 -> V_55 . V_57 -> V_215 * V_51 -> V_55 . V_57 -> V_216 . V_148 ) / 8 ;
if ( ! V_187 )
V_201 = V_51 -> V_55 . V_168 ;
V_60 = V_62 / V_204 ;
V_202 = F_111 ( V_49 , V_201 , V_60 , & V_148 ) ;
if ( V_202 < 0 )
return V_202 ;
V_202 = F_116 ( V_49 , V_148 , V_202 ) ;
if ( V_202 <= 0 )
return V_202 ;
V_62 = V_202 * V_204 ;
if ( ! V_187 && F_117 ( V_214 , V_201 , V_62 ) )
return - V_207 ;
} else
#endif
{
V_60 = F_59 ( V_51 , V_62 ) ;
V_202 = F_103 ( V_49 , V_201 , V_60 , V_187 ) ;
if ( V_202 <= 0 )
return V_202 ;
V_62 = F_56 ( V_51 , V_202 ) ;
}
return V_62 ;
}
static T_7 F_118 ( struct V_20 * V_49 , char V_192 * V_201 , T_6 V_62 )
{
T_6 V_208 = 0 ;
T_7 V_209 ;
struct V_50 * V_51 = V_49 -> V_51 ;
if ( F_69 ( & V_49 -> V_112 ) )
return - V_210 ;
if ( ( V_209 = F_98 ( V_49 ) ) < 0 )
return V_209 ;
F_114 ( & V_51 -> V_55 . V_139 ) ;
while ( V_62 > 0 ) {
if ( V_62 < V_51 -> V_55 . V_124 || V_51 -> V_55 . V_170 > 0 ) {
if ( V_51 -> V_55 . V_170 == 0 ) {
V_209 = F_115 ( V_49 , V_51 -> V_55 . V_168 , V_51 -> V_55 . V_124 , 1 ) ;
if ( V_209 <= 0 )
goto V_22;
V_51 -> V_55 . V_62 += V_209 ;
V_51 -> V_55 . V_182 = V_209 ;
V_51 -> V_55 . V_170 = V_209 ;
}
V_209 = V_62 ;
if ( ( T_6 ) V_209 > V_51 -> V_55 . V_170 )
V_209 = V_51 -> V_55 . V_170 ;
if ( F_117 ( V_201 , V_51 -> V_55 . V_168 + ( V_51 -> V_55 . V_182 - V_51 -> V_55 . V_170 ) , V_209 ) ) {
V_209 = - V_207 ;
goto V_22;
}
V_201 += V_209 ;
V_62 -= V_209 ;
V_208 += V_209 ;
V_51 -> V_55 . V_170 -= V_209 ;
} else {
V_209 = F_115 ( V_49 , ( char V_142 * ) V_201 ,
V_51 -> V_55 . V_124 , 0 ) ;
if ( V_209 <= 0 )
goto V_22;
V_51 -> V_55 . V_62 += V_209 ;
V_201 += V_209 ;
V_62 -= V_209 ;
V_208 += V_209 ;
}
}
F_95 ( & V_51 -> V_55 . V_139 ) ;
return V_208 ;
V_22:
F_95 ( & V_51 -> V_55 . V_139 ) ;
return V_208 > 0 ? ( T_8 ) V_208 : V_209 ;
}
static int F_119 ( struct V_173 * V_174 )
{
struct V_20 * V_49 ;
struct V_50 * V_51 ;
int V_3 ;
for ( V_3 = 0 ; V_3 < 2 ; V_3 ++ ) {
V_49 = V_174 -> V_178 [ V_3 ] ;
if ( ! V_49 )
continue;
V_51 = V_49 -> V_51 ;
F_86 ( V_49 , V_153 , NULL ) ;
V_51 -> V_55 . V_169 = 1 ;
V_51 -> V_55 . V_170 = 0 ;
V_51 -> V_55 . V_181 = 0 ;
V_51 -> V_55 . V_182 = 0 ;
}
return 0 ;
}
static int F_120 ( struct V_173 * V_174 )
{
struct V_20 * V_49 ;
int V_22 ;
V_49 = V_174 -> V_178 [ V_152 ] ;
if ( V_49 != NULL ) {
if ( ( V_22 = F_98 ( V_49 ) ) < 0 )
return V_22 ;
F_86 ( V_49 , V_217 , NULL ) ;
}
return 0 ;
}
static int F_121 ( struct V_20 * V_49 , T_6 V_218 )
{
struct V_50 * V_51 ;
T_7 V_219 = 0 ;
T_9 V_189 ;
long V_220 ;
T_10 V_221 ;
V_51 = V_49 -> V_51 ;
F_122 ( & V_221 , V_222 ) ;
F_123 ( & V_51 -> V_223 , & V_221 ) ;
#ifdef F_101
F_77 ( V_49 -> V_21 , L_18 , V_218 ) ;
#endif
while ( 1 ) {
V_219 = F_109 ( V_49 , V_51 -> V_55 . V_168 , V_218 , 1 ) ;
if ( V_219 > 0 ) {
V_51 -> V_55 . V_170 = 0 ;
V_219 = 0 ;
break;
}
if ( V_219 != 0 && V_219 != - V_196 )
break;
V_219 = 0 ;
F_124 ( V_224 ) ;
F_125 ( V_49 ) ;
V_189 = V_51 -> V_188 -> V_189 ;
F_126 ( V_49 ) ;
if ( V_189 != V_225 ) {
F_124 ( V_226 ) ;
break;
}
V_220 = F_127 ( 10 * V_227 ) ;
if ( F_128 ( V_222 ) ) {
V_219 = - V_228 ;
break;
}
if ( V_220 == 0 ) {
F_129 ( V_49 -> V_21 ,
L_19 ) ;
V_219 = - V_179 ;
break;
}
}
F_130 ( & V_51 -> V_223 , & V_221 ) ;
return V_219 ;
}
static int F_131 ( struct V_173 * V_174 )
{
int V_22 = 0 ;
unsigned int V_229 ;
struct V_20 * V_49 ;
struct V_50 * V_51 ;
T_5 V_67 ;
unsigned long V_230 ;
T_6 V_218 ;
V_49 = V_174 -> V_178 [ V_152 ] ;
if ( V_49 != NULL ) {
V_51 = V_49 -> V_51 ;
if ( F_69 ( & V_49 -> V_112 ) )
goto V_231;
if ( ( V_22 = F_98 ( V_49 ) ) < 0 )
return V_22 ;
V_67 = F_61 ( V_51 -> V_55 . V_67 ) ;
V_230 = F_64 ( V_67 ) ;
F_114 ( & V_51 -> V_55 . V_139 ) ;
if ( V_51 -> V_55 . V_170 > 0 ) {
#ifdef F_101
F_77 ( V_49 -> V_21 , L_20 ) ;
#endif
V_218 = ( 8 * ( V_51 -> V_55 . V_124 - V_51 -> V_55 . V_170 ) + 7 ) / V_230 ;
F_93 ( V_67 ,
V_51 -> V_55 . V_168 + V_51 -> V_55 . V_170 ,
V_218 ) ;
V_22 = F_121 ( V_49 , V_51 -> V_55 . V_124 ) ;
if ( V_22 < 0 ) {
F_95 ( & V_51 -> V_55 . V_139 ) ;
return V_22 ;
}
} else if ( V_51 -> V_55 . V_182 > 0 ) {
#ifdef F_101
F_77 ( V_49 -> V_21 , L_21 ) ;
#endif
V_218 = V_51 -> V_55 . V_124 - V_51 -> V_55 . V_182 ;
F_93 ( V_67 ,
V_51 -> V_55 . V_168 ,
V_218 * 8 / V_230 ) ;
V_22 = F_121 ( V_49 , V_218 ) ;
if ( V_22 < 0 ) {
F_95 ( & V_51 -> V_55 . V_139 ) ;
return V_22 ;
}
}
V_218 = V_51 -> V_232 -> V_233 % V_51 -> V_115 ;
if ( V_218 > 0 ) {
V_218 = V_51 -> V_115 - V_218 ;
if ( V_51 -> V_234 == V_144 ) {
V_218 = ( V_51 -> V_235 * V_218 ) / 8 ;
while ( V_218 > 0 ) {
T_1 V_1 ;
T_6 V_236 = V_218 < V_51 -> V_55 . V_124 ? V_218 : V_51 -> V_55 . V_124 ;
V_218 -= V_236 ;
V_236 *= 8 ;
V_236 /= V_51 -> V_237 ;
F_93 ( V_51 -> V_67 ,
V_51 -> V_55 . V_168 ,
V_236 ) ;
V_236 /= V_51 -> V_148 ;
V_1 = F_1 () ;
F_102 ( V_49 , ( void V_142 V_192 * ) V_51 -> V_55 . V_168 , V_236 ) ;
F_5 ( V_1 ) ;
}
} else if ( V_51 -> V_234 == V_145 ) {
void V_192 * V_238 [ V_51 -> V_148 ] ;
memset ( V_238 , 0 , V_51 -> V_148 * sizeof( void * ) ) ;
F_106 ( V_49 , V_238 , V_218 ) ;
}
}
F_95 ( & V_51 -> V_55 . V_139 ) ;
V_231:
V_229 = V_49 -> V_212 ;
V_49 -> V_212 &= ~ V_213 ;
V_22 = F_86 ( V_49 , V_197 , NULL ) ;
V_49 -> V_212 = V_229 ;
if ( V_22 < 0 )
return V_22 ;
V_51 -> V_55 . V_169 = 1 ;
}
V_49 = V_174 -> V_178 [ V_158 ] ;
if ( V_49 != NULL ) {
if ( ( V_22 = F_98 ( V_49 ) ) < 0 )
return V_22 ;
V_51 = V_49 -> V_51 ;
V_22 = F_86 ( V_49 , V_153 , NULL ) ;
if ( V_22 < 0 )
return V_22 ;
V_51 -> V_55 . V_170 = 0 ;
V_51 -> V_55 . V_169 = 1 ;
}
return 0 ;
}
static int F_132 ( struct V_173 * V_174 , int V_128 )
{
int V_176 ;
for ( V_176 = 1 ; V_176 >= 0 ; -- V_176 ) {
struct V_20 * V_49 = V_174 -> V_178 [ V_176 ] ;
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
return F_133 ( V_174 ) ;
}
static int F_133 ( struct V_173 * V_174 )
{
struct V_20 * V_49 ;
int V_22 ;
if ( ( V_22 = F_96 ( V_174 , & V_49 ) ) < 0 )
return V_22 ;
return V_49 -> V_51 -> V_55 . V_128 ;
}
static int F_134 ( struct V_173 * V_174 , unsigned int V_148 )
{
int V_176 ;
if ( V_148 < 1 )
V_148 = 1 ;
if ( V_148 > 128 )
return - V_7 ;
for ( V_176 = 1 ; V_176 >= 0 ; -- V_176 ) {
struct V_20 * V_49 = V_174 -> V_178 [ V_176 ] ;
struct V_50 * V_51 ;
if ( V_49 == NULL )
continue;
V_51 = V_49 -> V_51 ;
if ( V_51 -> V_55 . V_148 != V_148 ) {
V_51 -> V_55 . V_14 = 1 ;
V_51 -> V_55 . V_148 = V_148 ;
}
}
return F_135 ( V_174 ) ;
}
static int F_135 ( struct V_173 * V_174 )
{
struct V_20 * V_49 ;
int V_22 ;
if ( ( V_22 = F_96 ( V_174 , & V_49 ) ) < 0 )
return V_22 ;
return V_49 -> V_51 -> V_55 . V_148 ;
}
static int F_136 ( struct V_173 * V_174 )
{
struct V_20 * V_49 ;
int V_22 ;
if ( ( V_22 = F_96 ( V_174 , & V_49 ) ) < 0 )
return V_22 ;
return V_49 -> V_51 -> V_55 . V_124 ;
}
static int F_137 ( struct V_173 * V_174 )
{
struct V_20 * V_49 ;
int V_22 ;
int V_134 ;
struct V_13 * V_14 ;
unsigned int V_239 = 0 ;
struct V_17 V_240 ;
int V_241 ;
if ( ( V_22 = F_96 ( V_174 , & V_49 ) ) < 0 )
return V_22 ;
if ( F_69 ( & V_49 -> V_112 ) )
V_134 = 1 ;
else
V_134 = V_49 -> V_55 . V_114 . V_134 ;
if ( ! V_134 )
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
F_75 ( V_14 ) ;
V_22 = F_26 ( V_49 , V_14 ) ;
V_240 = * F_24 ( V_14 , V_149 ) ;
F_40 ( V_14 ) ;
if ( V_22 < 0 )
return V_22 ;
for ( V_241 = 0 ; V_241 < 32 ; ++ V_241 ) {
if ( F_79 ( & V_240 , V_241 ) ) {
int V_242 = F_62 ( V_241 ) ;
if ( V_242 >= 0 )
V_239 |= V_242 ;
}
}
return V_239 ;
}
static int F_138 ( struct V_173 * V_174 , int V_67 )
{
int V_239 , V_176 ;
if ( V_67 != V_243 ) {
V_239 = F_137 ( V_174 ) ;
if ( V_239 < 0 )
return V_239 ;
if ( ! ( V_239 & V_67 ) )
V_67 = V_74 ;
for ( V_176 = 1 ; V_176 >= 0 ; -- V_176 ) {
struct V_20 * V_49 = V_174 -> V_178 [ V_176 ] ;
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
return F_139 ( V_174 ) ;
}
static int F_139 ( struct V_173 * V_174 )
{
struct V_20 * V_49 ;
int V_22 ;
if ( ( V_22 = F_96 ( V_174 , & V_49 ) ) < 0 )
return V_22 ;
return V_49 -> V_51 -> V_55 . V_67 ;
}
static int F_140 ( struct V_20 * V_49 , int V_244 )
{
struct V_50 * V_51 ;
if ( V_49 == NULL )
return 0 ;
V_51 = V_49 -> V_51 ;
if ( V_244 == 0 ) {
V_244 = V_51 -> V_55 . V_119 ;
if ( V_244 == 0 )
V_244 = 1 ;
return V_244 ;
}
if ( V_51 -> V_55 . V_119 || V_51 -> V_55 . V_116 )
return - V_7 ;
if ( V_244 != 1 && V_244 != 2 && V_244 != 4 &&
V_244 != 8 && V_244 != 16 )
return - V_7 ;
V_51 -> V_55 . V_119 = V_244 ;
V_51 -> V_55 . V_14 = 1 ;
return V_244 ;
}
static int F_141 ( struct V_173 * V_174 , int V_244 )
{
int V_22 = - V_7 , V_176 ;
for ( V_176 = 1 ; V_176 >= 0 ; -- V_176 ) {
struct V_20 * V_49 = V_174 -> V_178 [ V_176 ] ;
if ( V_49 == NULL )
continue;
if ( ( V_22 = F_140 ( V_49 , V_244 ) ) < 0 )
return V_22 ;
}
return V_22 ;
}
static int F_142 ( struct V_20 * V_49 , unsigned int V_10 )
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
static int F_143 ( struct V_173 * V_174 , unsigned int V_10 )
{
int V_22 = - V_7 , V_176 ;
for ( V_176 = 1 ; V_176 >= 0 ; -- V_176 ) {
struct V_20 * V_49 = V_174 -> V_178 [ V_176 ] ;
if ( V_49 == NULL )
continue;
if ( ( V_22 = F_142 ( V_49 , V_10 ) ) < 0 )
return V_22 ;
}
return V_22 ;
}
static int F_144 ( struct V_245 * V_245 )
{
F_145 ( & V_245 -> V_246 ) ;
V_245 -> V_212 |= V_213 ;
F_146 ( & V_245 -> V_246 ) ;
return 0 ;
}
static int F_147 ( struct V_20 * V_49 , int V_220 )
{
if ( V_49 == NULL ) {
V_220 &= ~ V_247 ;
return V_220 ;
}
#ifdef F_148
if ( V_49 -> V_151 == V_152 )
if ( V_49 -> V_248 -> V_249 > 1 )
V_220 |= F_148 ;
#endif
#if F_149 ( V_250 ) && 0
{
struct V_50 * V_51 = V_49 -> V_51 ;
if ( V_51 -> V_251 & ( V_252 | V_253 ) )
V_220 &= ~ V_250 ;
}
#endif
return V_220 ;
}
static int F_150 ( struct V_173 * V_174 )
{
int V_219 , V_176 ;
V_219 = V_254 | V_255 | V_247 | V_250 ;
for ( V_176 = 0 ; V_176 < 2 ; V_176 ++ ) {
struct V_20 * V_49 = V_174 -> V_178 [ V_176 ] ;
V_219 = F_147 ( V_49 , V_219 ) ;
}
V_219 |= 0x0001 ;
return V_219 ;
}
static void F_151 ( struct V_20 * V_49 ,
T_4 V_256 )
{
struct V_50 * V_51 = V_49 -> V_51 ;
T_4 V_233 ;
V_233 = V_256 + V_51 -> V_61 ;
V_233 %= V_51 -> V_157 ;
V_51 -> V_232 -> V_233 = V_233 ;
}
static int F_152 ( struct V_173 * V_174 , int V_155 )
{
struct V_50 * V_51 ;
struct V_20 * V_257 = NULL , * V_258 = NULL ;
int V_22 , V_259 ;
#ifdef F_101
F_77 ( V_49 -> V_21 , L_22 , V_155 ) ;
#endif
V_257 = V_174 -> V_178 [ V_152 ] ;
V_258 = V_174 -> V_178 [ V_158 ] ;
if ( V_257 ) {
if ( ( V_22 = F_98 ( V_257 ) ) < 0 )
return V_22 ;
}
if ( V_258 ) {
if ( ( V_22 = F_98 ( V_258 ) ) < 0 )
return V_22 ;
}
if ( V_257 ) {
V_51 = V_257 -> V_51 ;
if ( V_155 & V_260 ) {
if ( V_51 -> V_55 . V_155 )
goto V_261;
if ( F_69 ( & V_257 -> V_112 ) )
F_151 ( V_257 ,
F_60 ( V_51 ) ) ;
V_51 -> V_55 . V_155 = 1 ;
V_51 -> V_156 = 1 ;
V_259 = V_217 ;
} else {
if ( ! V_51 -> V_55 . V_155 )
goto V_261;
V_51 -> V_55 . V_155 = 0 ;
V_51 -> V_156 = V_51 -> V_157 ;
V_259 = V_153 ;
V_51 -> V_55 . V_169 = 1 ;
}
V_22 = F_86 ( V_257 , V_259 , NULL ) ;
if ( V_22 < 0 )
return V_22 ;
}
V_261:
if ( V_258 ) {
V_51 = V_258 -> V_51 ;
if ( V_155 & V_262 ) {
if ( V_51 -> V_55 . V_155 )
goto V_263;
V_51 -> V_55 . V_155 = 1 ;
V_51 -> V_156 = 1 ;
V_259 = V_217 ;
} else {
if ( ! V_51 -> V_55 . V_155 )
goto V_263;
V_51 -> V_55 . V_155 = 0 ;
V_51 -> V_156 = V_51 -> V_157 ;
V_259 = V_153 ;
V_51 -> V_55 . V_169 = 1 ;
}
V_22 = F_86 ( V_258 , V_259 , NULL ) ;
if ( V_22 < 0 )
return V_22 ;
}
V_263:
return 0 ;
}
static int F_153 ( struct V_173 * V_174 )
{
struct V_20 * V_257 = NULL , * V_258 = NULL ;
int V_219 = 0 ;
V_257 = V_174 -> V_178 [ V_152 ] ;
V_258 = V_174 -> V_178 [ V_158 ] ;
if ( V_257 && V_257 -> V_51 && V_257 -> V_51 -> V_55 . V_155 )
V_219 |= V_260 ;
if ( V_258 && V_258 -> V_51 && V_258 -> V_51 -> V_55 . V_155 )
V_219 |= V_262 ;
return V_219 ;
}
static int F_154 ( struct V_173 * V_174 )
{
struct V_20 * V_49 ;
struct V_50 * V_51 ;
T_8 V_183 ;
int V_22 ;
V_49 = V_174 -> V_178 [ V_152 ] ;
if ( V_49 == NULL )
return - V_7 ;
if ( ( V_22 = F_98 ( V_49 ) ) < 0 )
return V_22 ;
V_51 = V_49 -> V_51 ;
if ( V_51 -> V_55 . V_14 || V_51 -> V_55 . V_169 )
return 0 ;
V_22 = F_86 ( V_49 , V_184 , & V_183 ) ;
if ( V_22 == - V_193 )
V_183 = 0 ;
else if ( V_22 < 0 )
return V_22 ;
return F_54 ( V_49 , V_183 ) ;
}
static int F_155 ( struct V_173 * V_174 , int V_151 , struct V_264 V_192 * V_265 )
{
struct V_20 * V_49 ;
struct V_50 * V_51 ;
T_8 V_183 ;
int V_266 ;
struct V_264 V_251 ;
int V_22 ;
if ( V_265 == NULL )
return - V_207 ;
V_49 = V_174 -> V_178 [ V_151 ] ;
if ( V_49 == NULL )
return - V_7 ;
if ( ( V_22 = F_98 ( V_49 ) ) < 0 )
return V_22 ;
V_51 = V_49 -> V_51 ;
if ( V_51 -> V_55 . V_14 || V_51 -> V_55 . V_169 ) {
memset ( & V_251 , 0 , sizeof( V_251 ) ) ;
if ( F_117 ( V_265 , & V_251 , sizeof( V_251 ) ) )
return - V_207 ;
return 0 ;
}
if ( V_151 == V_152 ) {
V_22 = F_86 ( V_49 , V_184 , & V_183 ) ;
if ( V_22 == - V_193 || V_22 == - V_194 || ( ! V_22 && V_183 < 0 ) ) {
V_22 = 0 ;
V_183 = 0 ;
V_266 = 0 ;
} else {
V_266 = V_51 -> V_55 . V_170 ;
}
} else {
V_22 = F_99 ( V_49 , & V_183 ) ;
V_266 = - V_51 -> V_55 . V_170 ;
}
if ( V_22 < 0 )
return V_22 ;
V_251 . V_186 = F_54 ( V_49 , V_51 -> V_188 -> V_256 % V_51 -> V_61 ) ;
if ( F_69 ( & V_49 -> V_112 ) ) {
T_8 V_136 ;
V_183 = F_60 ( V_51 ) ;
V_136 = V_183 - V_51 -> V_55 . V_181 ;
if ( V_136 < 0 )
V_136 += V_51 -> V_157 ;
V_251 . V_267 = V_136 / V_51 -> V_115 ;
V_51 -> V_55 . V_181 = V_183 ;
if ( V_49 -> V_151 == V_152 )
F_151 ( V_49 , V_183 ) ;
V_251 . V_62 = F_54 ( V_49 , V_51 -> V_188 -> V_256 ) & V_43 ;
} else {
V_183 = F_54 ( V_49 , V_183 ) ;
if ( V_151 == V_152 ) {
if ( V_49 -> V_55 . V_114 . V_268 )
V_251 . V_267 = ( V_51 -> V_55 . V_63 - V_183 - V_266 ) / V_51 -> V_55 . V_124 ;
else
V_251 . V_267 = ( V_183 + V_266 ) / V_51 -> V_55 . V_124 ;
V_251 . V_62 = ( V_51 -> V_55 . V_62 - V_183 ) & V_43 ;
} else {
V_183 += V_266 ;
V_251 . V_267 = V_183 / V_51 -> V_55 . V_124 ;
V_251 . V_62 = ( V_51 -> V_55 . V_62 + V_183 ) & V_43 ;
}
}
if ( F_117 ( V_265 , & V_251 , sizeof( V_251 ) ) )
return - V_207 ;
return 0 ;
}
static int F_156 ( struct V_173 * V_174 , int V_151 , struct V_269 V_192 * V_265 )
{
struct V_20 * V_49 ;
struct V_50 * V_51 ;
T_8 V_270 ;
int V_266 ;
struct V_269 V_251 ;
int V_22 ;
if ( V_265 == NULL )
return - V_207 ;
V_49 = V_174 -> V_178 [ V_151 ] ;
if ( V_49 == NULL )
return - V_7 ;
V_51 = V_49 -> V_51 ;
if ( V_51 -> V_55 . V_14 &&
( V_22 = F_73 ( V_49 ) ) < 0 )
return V_22 ;
V_251 . V_271 = V_51 -> V_55 . V_124 ;
V_251 . V_272 = V_51 -> V_121 ;
if ( V_51 -> V_55 . V_169 ) {
if ( V_151 == V_152 ) {
V_251 . V_62 = V_51 -> V_55 . V_124 * V_51 -> V_55 . V_121 ;
V_251 . V_273 = V_51 -> V_55 . V_121 ;
} else {
V_251 . V_62 = 0 ;
V_251 . V_273 = 0 ;
}
} else {
if ( V_151 == V_152 ) {
V_22 = F_86 ( V_49 , V_184 , & V_270 ) ;
if ( V_22 == - V_193 || V_22 == - V_194 || ( ! V_22 && V_270 < 0 ) ) {
V_270 = V_51 -> V_61 ;
V_22 = 0 ;
V_266 = 0 ;
} else {
V_270 = V_51 -> V_61 - V_270 ;
V_266 = - V_51 -> V_55 . V_170 ;
}
} else {
V_22 = F_99 ( V_49 , & V_270 ) ;
V_266 = V_51 -> V_55 . V_170 ;
}
if ( V_22 < 0 )
return V_22 ;
V_251 . V_62 = F_54 ( V_49 , V_270 ) + V_266 ;
V_251 . V_273 = V_251 . V_62 / V_51 -> V_55 . V_124 ;
}
#ifdef F_101
F_77 ( V_49 -> V_21 ,
L_23 ,
V_251 . V_62 , V_251 . V_273 , V_251 . V_272 , V_251 . V_271 ) ;
#endif
if ( F_117 ( V_265 , & V_251 , sizeof( V_251 ) ) )
return - V_207 ;
return 0 ;
}
static int F_157 ( struct V_173 * V_174 , int V_151 , struct V_274 V_192 * V_265 )
{
return - V_7 ;
}
static const char * F_158 ( const char * V_275 )
{
const char * V_186 , * V_276 = NULL ;
for ( V_186 = V_275 ; * V_186 ; V_186 ++ ) {
if ( * V_186 == '/' )
V_276 = V_186 + 1 ;
}
return V_276 ;
}
static void F_159 ( struct V_277 * V_21 , int V_151 ,
const char * V_278 ,
struct V_279 * V_280 )
{
struct V_279 * V_114 ;
F_114 ( & V_21 -> V_178 [ V_151 ] . V_55 . V_281 ) ;
do {
for ( V_114 = V_21 -> V_178 [ V_151 ] . V_55 . V_282 ; V_114 ;
V_114 = V_114 -> V_54 ) {
if ( ! strcmp ( V_114 -> V_278 , V_278 ) )
goto V_283;
}
} while ( ( V_278 = F_158 ( V_278 ) ) != NULL );
V_283:
if ( V_114 )
* V_280 = * V_114 ;
F_95 ( & V_21 -> V_178 [ V_151 ] . V_55 . V_281 ) ;
}
static void F_160 ( struct V_20 * V_49 )
{
struct V_50 * V_51 ;
V_51 = V_49 -> V_51 ;
F_91 ( V_51 -> V_55 . V_168 ) ;
V_51 -> V_55 . V_168 = NULL ;
#ifdef F_82
F_50 ( V_49 ) ;
#endif
V_49 -> V_55 . V_55 = 0 ;
}
static void F_161 ( struct V_20 * V_49 ,
struct V_279 * V_114 ,
int V_284 )
{
struct V_50 * V_51 ;
V_49 -> V_55 . V_55 = 1 ;
V_49 -> V_55 . V_114 = * V_114 ;
if ( V_114 -> V_285 )
V_49 -> V_212 |= V_213 ;
else if ( V_114 -> V_286 )
V_49 -> V_212 &= ~ V_213 ;
V_51 = V_49 -> V_51 ;
V_51 -> V_55 . V_14 = 1 ;
V_51 -> V_55 . V_155 = 1 ;
V_51 -> V_55 . V_128 = 8000 ;
F_162 ( & V_51 -> V_55 . V_139 ) ;
switch ( F_163 ( V_284 ) ) {
case V_287 :
V_51 -> V_55 . V_67 = V_74 ;
break;
case V_288 :
V_51 -> V_55 . V_67 = V_76 ;
break;
default:
V_51 -> V_55 . V_67 = V_68 ;
}
V_51 -> V_55 . V_148 = 1 ;
V_51 -> V_55 . V_116 = 0 ;
V_51 -> V_55 . V_123 = 0 ;
V_51 -> V_55 . V_119 = 0 ;
V_49 -> V_289 = F_160 ;
}
static int F_164 ( struct V_173 * V_174 )
{
int V_290 ;
if ( ! V_174 )
return 0 ;
for ( V_290 = 0 ; V_290 < 2 ; ++ V_290 ) {
struct V_20 * V_49 = V_174 -> V_178 [ V_290 ] ;
if ( V_49 )
F_165 ( V_49 ) ;
}
F_40 ( V_174 ) ;
return 0 ;
}
static int F_166 ( struct V_245 * V_245 ,
struct V_277 * V_21 ,
struct V_173 * * V_291 ,
int V_284 ,
struct V_279 * V_114 )
{
int V_176 , V_22 ;
struct V_173 * V_174 ;
struct V_20 * V_49 ;
T_11 V_292 = V_245 -> V_292 ;
if ( V_291 )
* V_291 = NULL ;
V_174 = F_167 ( sizeof( * V_174 ) , V_44 ) ;
if ( V_174 == NULL )
return - V_45 ;
if ( ( V_292 & ( V_293 | V_294 ) ) == ( V_293 | V_294 ) &&
( V_21 -> V_295 & V_296 ) )
V_292 = V_293 ;
V_245 -> V_212 &= ~ V_297 ;
for ( V_176 = 0 ; V_176 < 2 ; V_176 ++ ) {
if ( V_114 [ V_176 ] . V_298 )
continue;
if ( ! V_21 -> V_178 [ V_176 ] . V_249 )
continue;
if ( V_176 == V_152 ) {
if ( ! ( V_292 & V_293 ) )
continue;
} else {
if ( ! ( V_292 & V_294 ) )
continue;
}
V_22 = F_168 ( V_21 , V_176 , V_245 , & V_49 ) ;
if ( V_22 < 0 ) {
F_164 ( V_174 ) ;
return V_22 ;
}
V_174 -> V_178 [ V_176 ] = V_49 ;
V_49 -> V_245 = V_174 ;
F_161 ( V_49 , & V_114 [ V_176 ] , V_284 ) ;
}
if ( ! V_174 -> V_178 [ 0 ] && ! V_174 -> V_178 [ 1 ] ) {
F_164 ( V_174 ) ;
return - V_7 ;
}
V_245 -> V_299 = V_174 ;
if ( V_291 )
* V_291 = V_174 ;
return 0 ;
}
static int F_169 ( struct V_300 * V_301 , char * V_302 , T_6 V_218 )
{
unsigned int V_176 ;
if ( F_43 ( ! V_301 || ! V_302 || V_218 < 2 ) )
return - V_7 ;
for ( V_176 = 0 ; V_176 < sizeof( V_301 -> V_303 ) && V_176 + 1 < V_218 ; V_176 ++ )
V_302 [ V_176 ] = V_301 -> V_303 [ V_176 ] ;
V_302 [ V_176 ] = '\0' ;
return 0 ;
}
static int F_170 ( struct V_304 * V_304 , struct V_245 * V_245 )
{
int V_22 ;
char V_278 [ 32 ] ;
struct V_277 * V_21 ;
struct V_173 * V_174 ;
struct V_279 V_114 [ 2 ] ;
int V_285 ;
T_10 V_221 ;
V_22 = F_171 ( V_304 , V_245 ) ;
if ( V_22 < 0 )
return V_22 ;
V_21 = F_172 ( F_173 ( V_304 ) ,
V_305 ) ;
if ( V_21 == NULL ) {
V_22 = - V_306 ;
goto V_307;
}
V_22 = F_174 ( V_21 -> V_308 , V_245 ) ;
if ( V_22 < 0 )
goto V_307;
if ( ! F_175 ( V_21 -> V_308 -> V_309 ) ) {
V_22 = - V_207 ;
goto V_310;
}
if ( F_169 ( V_222 , V_278 , sizeof( V_278 ) ) < 0 ) {
V_22 = - V_207 ;
goto V_311;
}
memset ( V_114 , 0 , sizeof( V_114 ) ) ;
if ( V_245 -> V_292 & V_293 )
F_159 ( V_21 , V_152 ,
V_278 , & V_114 [ 0 ] ) ;
if ( V_245 -> V_292 & V_294 )
F_159 ( V_21 , V_158 ,
V_278 , & V_114 [ 1 ] ) ;
V_285 = ! ! ( V_245 -> V_212 & V_213 ) ;
if ( ! V_285 )
V_285 = V_312 ;
F_122 ( & V_221 , V_222 ) ;
F_123 ( & V_21 -> V_313 , & V_221 ) ;
F_114 ( & V_21 -> V_314 ) ;
while ( 1 ) {
V_22 = F_166 ( V_245 , V_21 , & V_174 ,
F_173 ( V_304 ) , V_114 ) ;
if ( V_22 >= 0 )
break;
if ( V_22 == - V_196 ) {
if ( V_285 ) {
V_22 = - V_315 ;
break;
}
} else
break;
F_124 ( V_224 ) ;
F_95 ( & V_21 -> V_314 ) ;
F_176 () ;
F_114 ( & V_21 -> V_314 ) ;
if ( V_21 -> V_308 -> V_316 ) {
V_22 = - V_306 ;
break;
}
if ( F_128 ( V_222 ) ) {
V_22 = - V_228 ;
break;
}
}
F_130 ( & V_21 -> V_313 , & V_221 ) ;
F_95 ( & V_21 -> V_314 ) ;
if ( V_22 < 0 )
goto V_311;
F_177 ( V_21 -> V_308 ) ;
return V_22 ;
V_311:
F_178 ( V_21 -> V_308 -> V_309 ) ;
V_310:
F_179 ( V_21 -> V_308 , V_245 ) ;
V_307:
if ( V_21 )
F_177 ( V_21 -> V_308 ) ;
return V_22 ;
}
static int F_180 ( struct V_304 * V_304 , struct V_245 * V_245 )
{
struct V_277 * V_21 ;
struct V_20 * V_49 ;
struct V_173 * V_174 ;
V_174 = V_245 -> V_299 ;
V_49 = V_174 -> V_178 [ V_152 ] ;
if ( V_49 == NULL )
V_49 = V_174 -> V_178 [ V_158 ] ;
if ( F_43 ( ! V_49 ) )
return - V_210 ;
V_21 = V_49 -> V_21 ;
if ( ! V_21 -> V_308 -> V_316 )
F_131 ( V_174 ) ;
F_114 ( & V_21 -> V_314 ) ;
F_164 ( V_174 ) ;
F_95 ( & V_21 -> V_314 ) ;
F_181 ( & V_21 -> V_313 ) ;
F_178 ( V_21 -> V_308 -> V_309 ) ;
F_179 ( V_21 -> V_308 , V_245 ) ;
return 0 ;
}
static long F_182 ( struct V_245 * V_245 , unsigned int V_259 , unsigned long V_317 )
{
struct V_173 * V_174 ;
int V_192 * V_318 = ( int V_192 * ) V_317 ;
int V_220 ;
V_174 = V_245 -> V_299 ;
if ( V_259 == V_319 )
return F_183 ( V_320 , V_318 ) ;
if ( V_259 == V_321 )
return F_183 ( 1 , V_318 ) ;
#if F_149 ( V_322 ) || ( F_149 ( V_323 ) && F_149 ( V_324 ) )
if ( ( ( V_259 >> 8 ) & 0xff ) == 'M' ) {
struct V_20 * V_49 ;
int V_176 ;
for ( V_176 = 0 ; V_176 < 2 ; ++ V_176 ) {
V_49 = V_174 -> V_178 [ V_176 ] ;
if ( V_49 != NULL )
break;
}
if ( F_43 ( V_176 >= 2 ) )
return - V_210 ;
return F_184 ( V_49 -> V_21 -> V_308 , V_259 , V_317 ) ;
}
#endif
if ( ( ( V_259 >> 8 ) & 0xff ) != 'P' )
return - V_7 ;
#ifdef F_101
F_185 ( L_24 , V_259 ) ;
#endif
switch ( V_259 ) {
case V_325 :
return F_119 ( V_174 ) ;
case V_326 :
return F_131 ( V_174 ) ;
case V_327 :
if ( F_186 ( V_220 , V_318 ) )
return - V_207 ;
if ( ( V_220 = F_132 ( V_174 , V_220 ) ) < 0 )
return V_220 ;
return F_183 ( V_220 , V_318 ) ;
case V_328 :
V_220 = F_133 ( V_174 ) ;
if ( V_220 < 0 )
return V_220 ;
return F_183 ( V_220 , V_318 ) ;
case V_329 :
if ( F_186 ( V_220 , V_318 ) )
return - V_207 ;
V_220 = V_220 > 0 ? 2 : 1 ;
if ( ( V_220 = F_134 ( V_174 , V_220 ) ) < 0 )
return V_220 ;
return F_183 ( -- V_220 , V_318 ) ;
case V_330 :
V_220 = F_136 ( V_174 ) ;
if ( V_220 < 0 )
return V_220 ;
return F_183 ( V_220 , V_318 ) ;
case V_331 :
if ( F_186 ( V_220 , V_318 ) )
return - V_207 ;
V_220 = F_138 ( V_174 , V_220 ) ;
if ( V_220 < 0 )
return V_220 ;
return F_183 ( V_220 , V_318 ) ;
case V_332 :
V_220 = F_139 ( V_174 ) ;
if ( V_220 < 0 )
return V_220 ;
return F_183 ( V_220 , V_318 ) ;
case V_333 :
if ( F_186 ( V_220 , V_318 ) )
return - V_207 ;
V_220 = F_134 ( V_174 , V_220 ) ;
if ( V_220 < 0 )
return V_220 ;
return F_183 ( V_220 , V_318 ) ;
case V_334 :
V_220 = F_135 ( V_174 ) ;
if ( V_220 < 0 )
return V_220 ;
return F_183 ( V_220 , V_318 ) ;
case V_335 :
case V_336 :
return - V_179 ;
case V_337 :
return F_120 ( V_174 ) ;
case V_338 :
if ( F_186 ( V_220 , V_318 ) )
return - V_207 ;
V_220 = F_141 ( V_174 , V_220 ) ;
if ( V_220 < 0 )
return V_220 ;
return F_183 ( V_220 , V_318 ) ;
case V_339 :
if ( F_186 ( V_220 , V_318 ) )
return - V_207 ;
return F_143 ( V_174 , V_220 ) ;
case V_340 :
V_220 = F_137 ( V_174 ) ;
if ( V_220 < 0 )
return V_220 ;
return F_183 ( V_220 , V_318 ) ;
case V_341 :
case V_342 :
return F_156 ( V_174 ,
V_259 == V_342 ?
V_158 : V_152 ,
(struct V_269 V_192 * ) V_317 ) ;
case V_343 :
return F_144 ( V_245 ) ;
case V_344 :
V_220 = F_150 ( V_174 ) ;
if ( V_220 < 0 )
return V_220 ;
return F_183 ( V_220 , V_318 ) ;
case V_345 :
V_220 = F_153 ( V_174 ) ;
if ( V_220 < 0 )
return V_220 ;
return F_183 ( V_220 , V_318 ) ;
case V_346 :
if ( F_186 ( V_220 , V_318 ) )
return - V_207 ;
return F_152 ( V_174 , V_220 ) ;
case V_347 :
case V_348 :
return F_155 ( V_174 ,
V_259 == V_347 ?
V_158 : V_152 ,
(struct V_264 V_192 * ) V_317 ) ;
case V_349 :
case V_350 :
return F_157 ( V_174 ,
V_259 == V_349 ?
V_158 : V_152 ,
(struct V_274 V_192 * ) V_317 ) ;
case V_351 :
return 0 ;
case V_352 :
if ( F_150 ( V_174 ) & V_247 )
return 0 ;
return - V_179 ;
case V_353 :
V_220 = F_154 ( V_174 ) ;
if ( V_220 < 0 ) {
F_183 ( 0 , V_318 ) ;
return V_220 ;
}
return F_183 ( V_220 , V_318 ) ;
case V_354 :
return 0 ;
default:
F_185 ( L_25 , V_259 ) ;
}
return - V_7 ;
}
static T_7 F_187 ( struct V_245 * V_245 , char V_192 * V_201 , T_6 V_355 , T_12 * V_356 )
{
struct V_173 * V_174 ;
struct V_20 * V_49 ;
V_174 = V_245 -> V_299 ;
V_49 = V_174 -> V_178 [ V_158 ] ;
if ( V_49 == NULL )
return - V_210 ;
V_49 -> V_212 = V_245 -> V_212 & V_213 ;
#ifndef F_101
return F_118 ( V_49 , V_201 , V_355 ) ;
#else
{
T_7 V_220 = F_118 ( V_49 , V_201 , V_355 ) ;
F_77 ( V_49 -> V_21 ,
L_26 ,
( long ) V_355 , ( long ) V_220 ) ;
return V_220 ;
}
#endif
}
static T_7 F_188 ( struct V_245 * V_245 , const char V_192 * V_201 , T_6 V_355 , T_12 * V_356 )
{
struct V_173 * V_174 ;
struct V_20 * V_49 ;
long V_219 ;
V_174 = V_245 -> V_299 ;
V_49 = V_174 -> V_178 [ V_152 ] ;
if ( V_49 == NULL )
return - V_210 ;
V_49 -> V_212 = V_245 -> V_212 & V_213 ;
V_219 = F_113 ( V_49 , V_201 , V_355 ) ;
#ifdef F_101
F_77 ( V_49 -> V_21 , L_27 ,
( long ) V_355 , ( long ) V_219 ) ;
#endif
return V_219 ;
}
static int F_189 ( struct V_20 * V_49 )
{
struct V_50 * V_51 = V_49 -> V_51 ;
if ( F_69 ( & V_49 -> V_112 ) )
return V_51 -> V_55 . V_181 !=
F_60 ( V_51 ) ;
else
return F_190 ( V_51 ) >=
V_51 -> V_55 . V_125 ;
}
static int F_191 ( struct V_20 * V_49 )
{
struct V_50 * V_51 = V_49 -> V_51 ;
if ( F_69 ( & V_49 -> V_112 ) )
return V_51 -> V_55 . V_181 !=
F_60 ( V_51 ) ;
else
return F_192 ( V_51 ) >=
V_51 -> V_55 . V_125 ;
}
static unsigned int F_193 ( struct V_245 * V_245 , T_13 * V_221 )
{
struct V_173 * V_174 ;
unsigned int V_138 ;
struct V_20 * V_257 = NULL , * V_258 = NULL ;
V_174 = V_245 -> V_299 ;
V_257 = V_174 -> V_178 [ V_152 ] ;
V_258 = V_174 -> V_178 [ V_158 ] ;
V_138 = 0 ;
if ( V_257 != NULL ) {
struct V_50 * V_51 = V_257 -> V_51 ;
F_194 ( V_245 , & V_51 -> V_223 , V_221 ) ;
F_125 ( V_257 ) ;
if ( V_51 -> V_188 -> V_189 != V_199 &&
( V_51 -> V_188 -> V_189 != V_225 ||
F_189 ( V_257 ) ) )
V_138 |= V_357 | V_358 ;
F_126 ( V_257 ) ;
}
if ( V_258 != NULL ) {
struct V_50 * V_51 = V_258 -> V_51 ;
T_9 V_359 ;
F_194 ( V_245 , & V_51 -> V_223 , V_221 ) ;
F_125 ( V_258 ) ;
if ( ( V_359 = V_51 -> V_188 -> V_189 ) != V_225 ||
F_191 ( V_258 ) )
V_138 |= V_360 | V_361 ;
F_126 ( V_258 ) ;
if ( V_359 != V_225 && V_51 -> V_55 . V_155 ) {
struct V_173 V_362 ;
memset ( & V_362 , 0 , sizeof( V_362 ) ) ;
V_362 . V_178 [ V_158 ] = V_174 -> V_178 [ V_158 ] ;
V_51 -> V_55 . V_155 = 0 ;
F_152 ( & V_362 , V_262 ) ;
}
}
return V_138 ;
}
static int F_195 ( struct V_245 * V_245 , struct V_363 * V_364 )
{
struct V_173 * V_174 ;
struct V_20 * V_49 = NULL ;
struct V_50 * V_51 ;
int V_22 ;
#ifdef F_101
F_185 ( L_28 ) ;
#endif
V_174 = V_245 -> V_299 ;
switch ( ( V_364 -> V_365 & ( V_366 | V_367 ) ) ) {
case V_366 | V_367 :
V_49 = V_174 -> V_178 [ V_152 ] ;
if ( V_49 )
break;
case V_366 :
V_49 = V_174 -> V_178 [ V_158 ] ;
break;
case V_367 :
V_49 = V_174 -> V_178 [ V_152 ] ;
break;
default:
return - V_7 ;
}
V_364 -> V_365 |= V_366 ;
if ( V_49 == NULL )
return - V_210 ;
V_51 = V_49 -> V_51 ;
if ( ! ( V_51 -> V_251 & V_368 ) )
return - V_179 ;
if ( V_51 -> V_251 & V_369 )
V_51 -> V_234 = V_143 ;
else
return - V_179 ;
if ( V_51 -> V_55 . V_14 ) {
if ( ( V_22 = F_73 ( V_49 ) ) < 0 )
return V_22 ;
}
#ifdef F_82
if ( V_51 -> V_55 . V_56 != NULL )
return - V_179 ;
#endif
if ( V_364 -> V_370 != 0 )
return - V_7 ;
V_22 = F_196 ( V_49 , V_245 , V_364 ) ;
if ( V_22 < 0 )
return V_22 ;
V_51 -> V_55 . V_113 = V_364 -> V_371 - V_364 -> V_372 ;
V_51 -> V_165 = 0 ;
V_51 -> V_166 = 0 ;
#ifdef F_101
F_185 ( L_29 ,
V_51 -> V_55 . V_113 ) ;
#endif
V_51 -> V_159 = V_51 -> V_157 ;
return 0 ;
}
static void F_197 ( struct V_373 * V_374 ,
struct V_375 * V_168 )
{
struct V_376 * V_248 = V_374 -> V_299 ;
struct V_279 * V_114 = V_248 -> V_55 . V_282 ;
F_114 ( & V_248 -> V_55 . V_281 ) ;
while ( V_114 ) {
F_198 ( V_168 , L_30 ,
V_114 -> V_278 ,
V_114 -> V_121 ,
V_114 -> V_115 ,
V_114 -> V_298 ? L_31 : L_32 ,
V_114 -> V_134 ? L_33 : L_32 ,
V_114 -> V_286 ? L_34 : L_32 ,
V_114 -> V_285 ? L_35 : L_32 ,
V_114 -> V_211 ? L_36 : L_32 ,
V_114 -> V_164 ? L_37 : L_32 ) ;
V_114 = V_114 -> V_54 ;
}
F_95 ( & V_248 -> V_55 . V_281 ) ;
}
static void F_199 ( struct V_376 * V_248 )
{
struct V_279 * V_114 , * V_377 ;
for ( V_114 = V_248 -> V_55 . V_282 , V_248 -> V_55 . V_282 = NULL ;
V_114 ; V_114 = V_377 ) {
V_377 = V_114 -> V_54 ;
F_40 ( V_114 -> V_278 ) ;
F_40 ( V_114 ) ;
}
V_248 -> V_55 . V_282 = NULL ;
}
static void F_200 ( struct V_373 * V_374 ,
struct V_375 * V_168 )
{
struct V_376 * V_248 = V_374 -> V_299 ;
char line [ 128 ] , V_378 [ 32 ] , V_278 [ 32 ] ;
const char * V_186 ;
int V_379 ;
struct V_279 * V_114 , * V_380 , V_381 ;
while ( ! F_201 ( V_168 , line , sizeof( line ) ) ) {
F_114 ( & V_248 -> V_55 . V_281 ) ;
memset ( & V_381 , 0 , sizeof( V_381 ) ) ;
V_186 = F_202 ( V_278 , line , sizeof( V_278 ) ) ;
if ( ! strcmp ( V_278 , L_38 ) || ! strcmp ( V_278 , L_39 ) ) {
F_199 ( V_248 ) ;
F_95 ( & V_248 -> V_55 . V_281 ) ;
continue;
}
for ( V_114 = V_248 -> V_55 . V_282 ; V_114 ; V_114 = V_114 -> V_54 ) {
if ( ! strcmp ( V_114 -> V_278 , V_278 ) ) {
V_381 = * V_114 ;
break;
}
}
V_186 = F_202 ( V_378 , V_186 , sizeof( V_378 ) ) ;
V_381 . V_121 = F_203 ( V_378 , NULL , 10 ) ;
V_186 = F_202 ( V_378 , V_186 , sizeof( V_378 ) ) ;
V_381 . V_115 = F_203 ( V_378 , NULL , 10 ) ;
for ( V_379 = 31 ; V_379 >= 0 ; V_379 -- )
if ( V_381 . V_115 & ( 1 << V_379 ) )
break;
for ( V_379 -- ; V_379 >= 0 ; V_379 -- )
V_381 . V_115 &= ~ ( 1 << V_379 ) ;
do {
V_186 = F_202 ( V_378 , V_186 , sizeof( V_378 ) ) ;
if ( ! strcmp ( V_378 , L_40 ) ) {
V_381 . V_298 = 1 ;
} else if ( ! strcmp ( V_378 , L_41 ) ) {
V_381 . V_134 = 1 ;
} else if ( ! strcmp ( V_378 , L_42 ) ) {
V_381 . V_286 = 1 ;
} else if ( ! strcmp ( V_378 , L_43 ) ) {
V_381 . V_285 = 1 ;
} else if ( ! strcmp ( V_378 , L_44 ) ) {
V_381 . V_211 = 1 ;
} else if ( ! strcmp ( V_378 , L_45 ) ) {
V_381 . V_164 = 1 ;
} else if ( ! strcmp ( V_378 , L_46 ) ) {
V_381 . V_268 = 1 ;
}
} while ( * V_378 );
if ( V_114 == NULL ) {
V_114 = F_39 ( sizeof( * V_114 ) , V_44 ) ;
if ( ! V_114 ) {
V_168 -> error = - V_45 ;
F_95 ( & V_248 -> V_55 . V_281 ) ;
return;
}
if ( V_248 -> V_55 . V_282 == NULL )
V_248 -> V_55 . V_282 = V_114 ;
else {
for ( V_380 = V_248 -> V_55 . V_282 ;
V_380 -> V_54 ; V_380 = V_380 -> V_54 ) ;
V_380 -> V_54 = V_114 ;
}
V_381 . V_278 = F_204 ( V_278 , V_44 ) ;
if ( ! V_381 . V_278 ) {
F_40 ( V_114 ) ;
V_168 -> error = - V_45 ;
F_95 ( & V_248 -> V_55 . V_281 ) ;
return;
}
}
* V_114 = V_381 ;
F_95 ( & V_248 -> V_55 . V_281 ) ;
}
}
static void F_205 ( struct V_277 * V_21 )
{
int V_151 ;
for ( V_151 = 0 ; V_151 < 2 ; ++ V_151 ) {
struct V_373 * V_374 ;
struct V_376 * V_248 = & V_21 -> V_178 [ V_151 ] ;
if ( V_248 -> V_249 == 0 )
continue;
if ( ( V_374 = F_206 ( V_21 -> V_308 , L_47 , V_248 -> V_382 ) ) != NULL ) {
V_374 -> V_383 = V_384 ;
V_374 -> V_385 = V_386 | V_387 | V_388 ;
V_374 -> V_28 . V_389 . V_390 = F_197 ;
V_374 -> V_28 . V_389 . V_391 = F_200 ;
V_374 -> V_299 = V_248 ;
if ( F_207 ( V_374 ) < 0 ) {
F_208 ( V_374 ) ;
V_374 = NULL ;
}
}
V_248 -> V_55 . V_392 = V_374 ;
}
}
static void F_209 ( struct V_277 * V_21 )
{
int V_151 ;
for ( V_151 = 0 ; V_151 < 2 ; ++ V_151 ) {
struct V_376 * V_248 = & V_21 -> V_178 [ V_151 ] ;
F_208 ( V_248 -> V_55 . V_392 ) ;
V_248 -> V_55 . V_392 = NULL ;
F_199 ( V_248 ) ;
}
}
static void F_210 ( struct V_277 * V_21 , int V_393 )
{
if ( F_211 ( V_305 ,
V_21 -> V_308 , V_393 , & V_394 ,
V_21 ) < 0 ) {
F_129 ( V_21 , L_48 ,
V_21 -> V_308 -> V_395 , V_21 -> V_396 ) ;
}
}
static int F_212 ( struct V_277 * V_21 )
{
V_21 -> V_55 . V_397 = 0 ;
if ( V_398 [ V_21 -> V_308 -> V_395 ] == ( int ) V_21 -> V_396 ) {
char V_302 [ 128 ] ;
int V_399 ;
F_210 ( V_21 , 0 ) ;
V_399 = ( V_21 -> V_178 [ V_152 ] . V_249 > 0 &&
V_21 -> V_178 [ V_158 ] . V_249 &&
! ( V_21 -> V_295 & V_296 ) ) ;
sprintf ( V_302 , L_49 , V_21 -> V_302 , V_399 ? L_50 : L_32 ) ;
#ifdef F_213
F_214 ( F_213 ,
V_21 -> V_308 -> V_395 ,
V_302 ) ;
#endif
V_21 -> V_55 . V_397 ++ ;
V_21 -> V_55 . V_400 |= 1 ;
}
if ( V_401 [ V_21 -> V_308 -> V_395 ] == ( int ) V_21 -> V_396 ) {
F_210 ( V_21 , 1 ) ;
V_21 -> V_55 . V_397 ++ ;
V_21 -> V_55 . V_400 |= 2 ;
}
if ( V_21 -> V_55 . V_397 )
F_205 ( V_21 ) ;
return 0 ;
}
static int F_215 ( struct V_277 * V_21 )
{
if ( V_21 -> V_55 . V_397 ) {
if ( V_21 -> V_55 . V_400 & 1 ) {
V_21 -> V_55 . V_400 &= ~ 1 ;
F_216 ( V_305 ,
V_21 -> V_308 , 0 ) ;
}
if ( V_21 -> V_55 . V_400 & 2 ) {
V_21 -> V_55 . V_400 &= ~ 2 ;
F_216 ( V_305 ,
V_21 -> V_308 , 1 ) ;
}
if ( V_398 [ V_21 -> V_308 -> V_395 ] == ( int ) V_21 -> V_396 ) {
#ifdef F_213
F_217 ( F_213 , V_21 -> V_308 -> V_395 ) ;
#endif
}
V_21 -> V_55 . V_397 = 0 ;
}
return 0 ;
}
static int F_218 ( struct V_277 * V_21 )
{
F_215 ( V_21 ) ;
F_209 ( V_21 ) ;
return 0 ;
}
static int T_14 F_219 ( void )
{
int V_3 ;
int V_22 ;
for ( V_3 = 0 ; V_3 < V_402 ; V_3 ++ ) {
if ( V_398 [ V_3 ] < 0 || V_398 [ V_3 ] >= V_403 ) {
F_220 ( L_51 ,
V_3 , V_398 [ V_3 ] ) ;
V_398 [ V_3 ] = 0 ;
}
if ( V_401 [ V_3 ] < 0 || V_401 [ V_3 ] >= V_403 ) {
F_220 ( L_52 ,
V_3 , V_401 [ V_3 ] ) ;
V_401 [ V_3 ] = 1 ;
}
}
if ( ( V_22 = F_221 ( & V_404 , 0 ) ) < 0 )
return V_22 ;
return 0 ;
}
static void T_15 F_222 ( void )
{
F_221 ( & V_404 , 1 ) ;
}
