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
V_105 = 1 << F_68 ( V_105 ) ;
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
V_108 = 1 << ( F_68 ( V_108 - 1 ) + 1 ) ;
if ( V_106 < V_108 )
V_106 = V_108 ;
V_109 = F_67 ( V_49 ,
F_19 ( V_103 , V_120 , NULL ) ) ;
V_109 *= V_110 ;
V_109 = 1 << F_68 ( V_109 ) ;
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
static int F_71 ( struct V_20 * V_49 ,
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
static int F_72 ( struct V_20 * V_49 )
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
if ( F_73 ( & V_51 -> V_55 . V_139 ) )
return - V_140 ;
V_133 = F_39 ( sizeof( * V_133 ) , V_44 ) ;
V_14 = F_39 ( sizeof( * V_14 ) , V_44 ) ;
V_131 = F_39 ( sizeof( * V_131 ) , V_44 ) ;
if ( ! V_133 || ! V_14 || ! V_131 ) {
F_74 ( L_1 ) ;
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
F_74 ( L_2 ) ;
V_22 = - V_7 ;
goto V_141;
}
F_71 ( V_49 , V_131 , V_51 -> V_55 . V_128 ) ;
F_38 ( V_49 , V_131 , V_147 , V_51 -> V_55 . V_148 , NULL ) ;
V_67 = F_61 ( V_51 -> V_55 . V_67 ) ;
V_137 = * F_24 ( V_131 , V_149 ) ;
if ( V_134 )
V_135 = V_67 ;
else
V_135 = F_77 ( V_67 , & V_137 ) ;
if ( ( V_142 int ) V_135 < 0 ||
! F_78 ( & V_137 , ( V_142 int ) V_135 ) ) {
for ( V_135 = ( V_142 T_5 ) 0 ;
( V_142 int ) V_135 <= ( V_142 int ) V_150 ;
V_135 = ( V_142 T_5 ) ( ( V_142 int ) V_135 + 1 ) ) {
if ( F_78 ( & V_137 , ( V_142 int ) V_135 ) &&
F_62 ( V_135 ) >= 0 )
break;
}
if ( ( V_142 int ) V_135 > ( V_142 int ) V_150 ) {
F_74 ( L_3 ) ;
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
F_79 ( L_4 ,
F_80 ( V_14 ) , F_65 ( V_14 ) ,
F_66 ( V_14 ) , F_70 ( V_14 ) ) ;
}
F_79 ( L_5 ,
F_80 ( V_131 ) , F_65 ( V_131 ) ,
F_66 ( V_131 ) , F_70 ( V_131 ) ) ;
V_110 = F_64 ( F_65 ( V_14 ) ) *
F_66 ( V_14 ) / 8 ;
#ifdef F_81
F_50 ( V_49 ) ;
if ( ! V_134 ) {
F_50 ( V_49 ) ;
if ( ( V_22 = F_82 ( V_49 ,
V_14 ,
V_131 ) ) < 0 ) {
F_74 ( L_6 , V_22 ) ;
F_50 ( V_49 ) ;
goto V_141;
}
if ( V_51 -> V_55 . V_56 ) {
struct V_52 * V_53 ;
if ( ( V_22 = F_83 ( V_49 , V_131 , & V_53 ) ) < 0 ) {
F_74 ( L_7 , V_22 ) ;
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
V_136 = F_84 ( V_49 , V_51 -> V_55 . V_124 / V_110 ) ;
V_22 = F_38 ( V_49 , V_131 , V_120 , V_136 , NULL ) ;
if ( V_22 < 0 )
goto V_141;
V_22 = F_38 ( V_49 , V_131 , V_122 ,
V_51 -> V_55 . V_121 , NULL ) ;
if ( V_22 < 0 )
goto V_141;
F_85 ( V_49 , V_153 , NULL ) ;
if ( ( V_22 = F_85 ( V_49 , V_154 , V_131 ) ) < 0 ) {
F_74 ( L_8 , V_22 ) ;
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
if ( ( V_22 = F_85 ( V_49 , V_167 , V_133 ) ) < 0 ) {
F_74 ( L_9 , V_22 ) ;
goto V_141;
}
V_51 -> V_55 . V_121 = F_86 ( V_131 ) ;
V_106 = F_67 ( V_49 , F_87 ( V_131 ) ) ;
if ( V_106 < 0 ) {
V_22 = - V_7 ;
goto V_141;
}
#ifdef F_81
if ( V_51 -> V_55 . V_56 ) {
V_22 = F_88 ( V_49 , V_106 ) ;
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
F_79 ( L_10 ,
V_51 -> V_55 . V_124 ,
V_51 -> V_55 . V_63 ) ;
F_79 ( L_11 ,
F_87 ( V_131 ) ,
F_89 ( V_131 ) ) ;
V_51 -> V_55 . V_67 = F_62 ( F_65 ( V_14 ) ) ;
V_51 -> V_55 . V_148 = F_66 ( V_14 ) ;
V_51 -> V_55 . V_128 = F_70 ( V_14 ) ;
F_90 ( V_51 -> V_55 . V_168 ) ;
V_51 -> V_55 . V_168 = F_91 ( V_51 -> V_55 . V_124 ) ;
if ( ! V_51 -> V_55 . V_168 ) {
V_22 = - V_45 ;
goto V_141;
}
V_51 -> V_55 . V_14 = 0 ;
V_51 -> V_55 . V_169 = 1 ;
V_51 -> V_55 . V_170 = 0 ;
if ( V_51 -> V_171 )
F_92 ( V_51 -> V_67 , V_51 -> V_171 , F_93 ( V_51 , V_51 -> V_172 ) ) ;
V_51 -> V_55 . V_125 = F_58 ( V_49 , V_106 ) ;
V_22 = 0 ;
V_141:
F_40 ( V_133 ) ;
F_40 ( V_14 ) ;
F_40 ( V_131 ) ;
F_94 ( & V_51 -> V_55 . V_139 ) ;
return V_22 ;
}
static int F_95 ( struct V_173 * V_174 , struct V_20 * * V_175 )
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
V_22 = F_72 ( V_49 ) ;
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
static int F_96 ( struct V_20 * V_49 )
{
int V_22 ;
struct V_50 * V_51 = V_49 -> V_51 ;
V_22 = F_85 ( V_49 , V_180 , NULL ) ;
if ( V_22 < 0 ) {
F_74 ( L_12 ) ;
return V_22 ;
}
V_51 -> V_55 . V_169 = 0 ;
V_51 -> V_55 . V_181 = 0 ;
V_51 -> V_55 . V_182 = 0 ;
V_51 -> V_55 . V_170 = 0 ;
return 0 ;
}
static int F_97 ( struct V_20 * V_49 )
{
struct V_50 * V_51 ;
int V_22 ;
if ( V_49 == NULL )
return 0 ;
V_51 = V_49 -> V_51 ;
if ( V_51 -> V_55 . V_14 ) {
V_22 = F_72 ( V_49 ) ;
if ( V_22 < 0 )
return V_22 ;
}
if ( V_51 -> V_55 . V_169 ) {
V_22 = F_96 ( V_49 ) ;
if ( V_22 < 0 )
return V_22 ;
}
return 0 ;
}
static int F_98 ( struct V_20 * V_49 , T_8 * V_183 )
{
struct V_50 * V_51 ;
T_4 V_60 ;
int V_22 = 0 ;
while ( 1 ) {
V_22 = F_85 ( V_49 , V_184 , V_183 ) ;
if ( V_22 < 0 )
break;
V_51 = V_49 -> V_51 ;
if ( * V_183 <= ( T_8 ) V_51 -> V_61 )
break;
V_60 = ( * V_183 - V_51 -> V_61 ) + V_51 -> V_115 - 1 ;
V_60 /= V_51 -> V_115 ;
V_60 *= V_51 -> V_115 ;
V_22 = F_85 ( V_49 , V_185 , & V_60 ) ;
if ( V_22 < 0 )
break;
}
return V_22 ;
}
T_8 F_99 ( struct V_20 * V_49 , const char * V_186 , T_4 V_60 , int V_187 )
{
struct V_50 * V_51 = V_49 -> V_51 ;
int V_130 ;
while ( 1 ) {
if ( V_51 -> V_188 -> V_189 == V_190 ||
V_51 -> V_188 -> V_189 == V_191 ) {
#ifdef F_100
if ( V_51 -> V_188 -> V_189 == V_190 )
F_101 ( V_192 L_13
L_14 ) ;
else
F_101 ( V_192 L_13
L_15 ) ;
#endif
V_130 = F_96 ( V_49 ) ;
if ( V_130 < 0 )
break;
}
if ( V_187 ) {
T_1 V_1 ;
V_1 = F_1 () ;
V_130 = F_102 ( V_49 , ( void V_142 V_193 * ) V_186 , V_60 ) ;
F_5 ( V_1 ) ;
} else {
V_130 = F_102 ( V_49 , ( void V_142 V_193 * ) V_186 , V_60 ) ;
}
if ( V_130 != - V_194 && V_130 != - V_195 )
break;
if ( V_51 -> V_188 -> V_189 == V_196 )
return - V_197 ;
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
#ifdef F_100
if ( V_51 -> V_188 -> V_189 == V_190 )
F_101 ( V_192 L_16
L_14 ) ;
else
F_101 ( V_192 L_16
L_15 ) ;
#endif
V_130 = F_85 ( V_49 , V_198 , NULL ) ;
if ( V_130 < 0 )
break;
} else if ( V_51 -> V_188 -> V_189 == V_199 ) {
V_130 = F_96 ( V_49 ) ;
if ( V_130 < 0 )
break;
}
V_130 = F_98 ( V_49 , & V_183 ) ;
if ( V_130 < 0 )
break;
if ( V_187 ) {
T_1 V_1 ;
V_1 = F_1 () ;
V_130 = F_104 ( V_49 , ( void V_142 V_193 * ) V_186 , V_60 ) ;
F_5 ( V_1 ) ;
} else {
V_130 = F_104 ( V_49 , ( void V_142 V_193 * ) V_186 , V_60 ) ;
}
if ( V_130 == - V_194 ) {
if ( V_51 -> V_188 -> V_189 == V_200 ) {
V_130 = F_85 ( V_49 , V_153 , NULL ) ;
if ( V_130 < 0 )
break;
}
continue;
}
if ( V_130 != - V_195 )
break;
}
return V_130 ;
}
T_8 F_105 ( struct V_20 * V_49 , void * * V_201 , T_4 V_60 , int V_187 )
{
struct V_50 * V_51 = V_49 -> V_51 ;
int V_130 ;
while ( 1 ) {
if ( V_51 -> V_188 -> V_189 == V_190 ||
V_51 -> V_188 -> V_189 == V_191 ) {
#ifdef F_100
if ( V_51 -> V_188 -> V_189 == V_190 )
F_101 ( V_192 L_17
L_14 ) ;
else
F_101 ( V_192 L_17
L_15 ) ;
#endif
V_130 = F_96 ( V_49 ) ;
if ( V_130 < 0 )
break;
}
if ( V_187 ) {
T_1 V_1 ;
V_1 = F_1 () ;
V_130 = F_106 ( V_49 , ( void V_193 * * ) V_201 , V_60 ) ;
F_5 ( V_1 ) ;
} else {
V_130 = F_106 ( V_49 , ( void V_193 * * ) V_201 , V_60 ) ;
}
if ( V_130 != - V_194 && V_130 != - V_195 )
break;
if ( V_51 -> V_188 -> V_189 == V_196 )
return - V_197 ;
}
return V_130 ;
}
T_8 F_107 ( struct V_20 * V_49 , void * * V_201 , T_4 V_60 , int V_187 )
{
struct V_50 * V_51 = V_49 -> V_51 ;
int V_130 ;
while ( 1 ) {
if ( V_51 -> V_188 -> V_189 == V_190 ||
V_51 -> V_188 -> V_189 == V_191 ) {
#ifdef F_100
if ( V_51 -> V_188 -> V_189 == V_190 )
F_101 ( V_192 L_18
L_14 ) ;
else
F_101 ( V_192 L_18
L_15 ) ;
#endif
V_130 = F_85 ( V_49 , V_198 , NULL ) ;
if ( V_130 < 0 )
break;
} else if ( V_51 -> V_188 -> V_189 == V_199 ) {
V_130 = F_96 ( V_49 ) ;
if ( V_130 < 0 )
break;
}
if ( V_187 ) {
T_1 V_1 ;
V_1 = F_1 () ;
V_130 = F_108 ( V_49 , ( void V_193 * * ) V_201 , V_60 ) ;
F_5 ( V_1 ) ;
} else {
V_130 = F_108 ( V_49 , ( void V_193 * * ) V_201 , V_60 ) ;
}
if ( V_130 != - V_194 && V_130 != - V_195 )
break;
}
return V_130 ;
}
static T_7 F_109 ( struct V_20 * V_49 , const char * V_202 , T_6 V_62 , int V_187 )
{
struct V_50 * V_51 = V_49 -> V_51 ;
T_8 V_60 , V_203 ;
#ifdef F_81
if ( V_51 -> V_55 . V_56 ) {
struct V_204 * V_148 ;
T_6 V_205 = ( V_51 -> V_55 . V_56 -> V_206 * V_51 -> V_55 . V_56 -> V_207 . V_148 ) / 8 ;
if ( ! V_187 ) {
if ( F_110 ( V_51 -> V_55 . V_168 , ( const char V_142 V_193 * ) V_202 , V_62 ) )
return - V_208 ;
V_202 = V_51 -> V_55 . V_168 ;
}
V_60 = V_62 / V_205 ;
V_203 = F_111 ( V_49 , ( char * ) V_202 , V_60 , & V_148 ) ;
if ( V_203 < 0 )
return V_203 ;
V_203 = F_112 ( V_49 , V_148 , V_203 ) ;
if ( V_203 <= 0 )
return V_203 ;
V_62 = V_203 * V_205 ;
} else
#endif
{
V_60 = F_59 ( V_51 , V_62 ) ;
V_203 = F_99 ( V_49 , V_202 , V_60 , V_187 ) ;
if ( V_203 <= 0 )
return V_203 ;
V_62 = F_56 ( V_51 , V_203 ) ;
}
return V_62 ;
}
static T_7 F_113 ( struct V_20 * V_49 , const char V_193 * V_202 , T_6 V_62 )
{
T_6 V_209 = 0 ;
T_7 V_210 ;
struct V_50 * V_51 = V_49 -> V_51 ;
if ( F_69 ( & V_49 -> V_112 ) )
return - V_211 ;
if ( ( V_210 = F_97 ( V_49 ) ) < 0 )
return V_210 ;
F_114 ( & V_51 -> V_55 . V_139 ) ;
while ( V_62 > 0 ) {
if ( V_62 < V_51 -> V_55 . V_124 || V_51 -> V_55 . V_170 > 0 ) {
V_210 = V_62 ;
if ( V_210 + V_51 -> V_55 . V_170 > V_51 -> V_55 . V_124 )
V_210 = V_51 -> V_55 . V_124 - V_51 -> V_55 . V_170 ;
if ( V_210 > 0 ) {
if ( F_110 ( V_51 -> V_55 . V_168 + V_51 -> V_55 . V_170 , V_202 , V_210 ) ) {
V_210 = - V_208 ;
goto V_22;
}
}
V_51 -> V_55 . V_170 += V_210 ;
V_202 += V_210 ;
V_62 -= V_210 ;
V_209 += V_210 ;
if ( V_49 -> V_55 . V_114 . V_212 ||
V_51 -> V_55 . V_170 == V_51 -> V_55 . V_124 ) {
V_210 = F_109 ( V_49 , V_51 -> V_55 . V_168 + V_51 -> V_55 . V_182 ,
V_51 -> V_55 . V_170 - V_51 -> V_55 . V_182 , 1 ) ;
if ( V_210 <= 0 )
goto V_22;
V_51 -> V_55 . V_62 += V_210 ;
V_51 -> V_55 . V_182 += V_210 ;
V_51 -> V_55 . V_182 %= V_51 -> V_55 . V_124 ;
if ( V_51 -> V_55 . V_182 == 0 ||
V_51 -> V_55 . V_182 == V_51 -> V_55 . V_170 )
V_51 -> V_55 . V_170 = 0 ;
else if ( ( V_49 -> V_213 & V_214 ) != 0 ) {
V_210 = - V_197 ;
goto V_22;
}
}
} else {
V_210 = F_109 ( V_49 ,
( const char V_142 * ) V_202 ,
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
F_94 ( & V_51 -> V_55 . V_139 ) ;
return V_209 ;
V_22:
F_94 ( & V_51 -> V_55 . V_139 ) ;
return V_209 > 0 ? ( T_8 ) V_209 : V_210 ;
}
static T_7 F_115 ( struct V_20 * V_49 , char * V_202 , T_6 V_62 , int V_187 )
{
struct V_50 * V_51 = V_49 -> V_51 ;
T_8 V_60 , V_203 ;
#ifdef F_81
char V_193 * V_215 = ( char V_142 V_193 * ) V_202 ;
if ( V_51 -> V_55 . V_56 ) {
struct V_204 * V_148 ;
T_6 V_205 = ( V_51 -> V_55 . V_57 -> V_216 * V_51 -> V_55 . V_57 -> V_217 . V_148 ) / 8 ;
if ( ! V_187 )
V_202 = V_51 -> V_55 . V_168 ;
V_60 = V_62 / V_205 ;
V_203 = F_111 ( V_49 , V_202 , V_60 , & V_148 ) ;
if ( V_203 < 0 )
return V_203 ;
V_203 = F_116 ( V_49 , V_148 , V_203 ) ;
if ( V_203 <= 0 )
return V_203 ;
V_62 = V_203 * V_205 ;
if ( ! V_187 && F_117 ( V_215 , V_202 , V_62 ) )
return - V_208 ;
} else
#endif
{
V_60 = F_59 ( V_51 , V_62 ) ;
V_203 = F_103 ( V_49 , V_202 , V_60 , V_187 ) ;
if ( V_203 <= 0 )
return V_203 ;
V_62 = F_56 ( V_51 , V_203 ) ;
}
return V_62 ;
}
static T_7 F_118 ( struct V_20 * V_49 , char V_193 * V_202 , T_6 V_62 )
{
T_6 V_209 = 0 ;
T_7 V_210 ;
struct V_50 * V_51 = V_49 -> V_51 ;
if ( F_69 ( & V_49 -> V_112 ) )
return - V_211 ;
if ( ( V_210 = F_97 ( V_49 ) ) < 0 )
return V_210 ;
F_114 ( & V_51 -> V_55 . V_139 ) ;
while ( V_62 > 0 ) {
if ( V_62 < V_51 -> V_55 . V_124 || V_51 -> V_55 . V_170 > 0 ) {
if ( V_51 -> V_55 . V_170 == 0 ) {
V_210 = F_115 ( V_49 , V_51 -> V_55 . V_168 , V_51 -> V_55 . V_124 , 1 ) ;
if ( V_210 <= 0 )
goto V_22;
V_51 -> V_55 . V_62 += V_210 ;
V_51 -> V_55 . V_182 = V_210 ;
V_51 -> V_55 . V_170 = V_210 ;
}
V_210 = V_62 ;
if ( ( T_6 ) V_210 > V_51 -> V_55 . V_170 )
V_210 = V_51 -> V_55 . V_170 ;
if ( F_117 ( V_202 , V_51 -> V_55 . V_168 + ( V_51 -> V_55 . V_182 - V_51 -> V_55 . V_170 ) , V_210 ) ) {
V_210 = - V_208 ;
goto V_22;
}
V_202 += V_210 ;
V_62 -= V_210 ;
V_209 += V_210 ;
V_51 -> V_55 . V_170 -= V_210 ;
} else {
V_210 = F_115 ( V_49 , ( char V_142 * ) V_202 ,
V_51 -> V_55 . V_124 , 0 ) ;
if ( V_210 <= 0 )
goto V_22;
V_51 -> V_55 . V_62 += V_210 ;
V_202 += V_210 ;
V_62 -= V_210 ;
V_209 += V_210 ;
}
}
F_94 ( & V_51 -> V_55 . V_139 ) ;
return V_209 ;
V_22:
F_94 ( & V_51 -> V_55 . V_139 ) ;
return V_209 > 0 ? ( T_8 ) V_209 : V_210 ;
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
F_85 ( V_49 , V_153 , NULL ) ;
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
if ( ( V_22 = F_97 ( V_49 ) ) < 0 )
return V_22 ;
F_85 ( V_49 , V_218 , NULL ) ;
}
return 0 ;
}
static int F_121 ( struct V_20 * V_49 , T_6 V_219 )
{
struct V_50 * V_51 ;
T_7 V_220 = 0 ;
T_9 V_189 ;
long V_221 ;
T_10 V_222 ;
V_51 = V_49 -> V_51 ;
F_122 ( & V_222 , V_223 ) ;
F_123 ( & V_51 -> V_224 , & V_222 ) ;
#ifdef F_100
F_101 ( V_192 L_19 , V_219 ) ;
#endif
while ( 1 ) {
V_220 = F_109 ( V_49 , V_51 -> V_55 . V_168 , V_219 , 1 ) ;
if ( V_220 > 0 ) {
V_51 -> V_55 . V_170 = 0 ;
V_220 = 0 ;
break;
}
if ( V_220 != 0 && V_220 != - V_197 )
break;
V_220 = 0 ;
F_124 ( V_225 ) ;
F_125 ( V_49 ) ;
V_189 = V_51 -> V_188 -> V_189 ;
F_126 ( V_49 ) ;
if ( V_189 != V_226 ) {
F_124 ( V_227 ) ;
break;
}
V_221 = F_127 ( 10 * V_228 ) ;
if ( F_128 ( V_223 ) ) {
V_220 = - V_229 ;
break;
}
if ( V_221 == 0 ) {
F_129 ( V_230 L_20 ) ;
V_220 = - V_179 ;
break;
}
}
F_130 ( & V_51 -> V_224 , & V_222 ) ;
return V_220 ;
}
static int F_131 ( struct V_173 * V_174 )
{
int V_22 = 0 ;
unsigned int V_231 ;
struct V_20 * V_49 ;
struct V_50 * V_51 ;
T_5 V_67 ;
unsigned long V_232 ;
T_6 V_219 ;
V_49 = V_174 -> V_178 [ V_152 ] ;
if ( V_49 != NULL ) {
V_51 = V_49 -> V_51 ;
if ( F_69 ( & V_49 -> V_112 ) )
goto V_233;
if ( ( V_22 = F_97 ( V_49 ) ) < 0 )
return V_22 ;
V_67 = F_61 ( V_51 -> V_55 . V_67 ) ;
V_232 = F_64 ( V_67 ) ;
F_114 ( & V_51 -> V_55 . V_139 ) ;
if ( V_51 -> V_55 . V_170 > 0 ) {
#ifdef F_100
F_101 ( V_192 L_21 ) ;
#endif
V_219 = ( 8 * ( V_51 -> V_55 . V_124 - V_51 -> V_55 . V_170 ) + 7 ) / V_232 ;
F_92 ( V_67 ,
V_51 -> V_55 . V_168 + V_51 -> V_55 . V_170 ,
V_219 ) ;
V_22 = F_121 ( V_49 , V_51 -> V_55 . V_124 ) ;
if ( V_22 < 0 ) {
F_94 ( & V_51 -> V_55 . V_139 ) ;
return V_22 ;
}
} else if ( V_51 -> V_55 . V_182 > 0 ) {
#ifdef F_100
F_101 ( V_192 L_22 ) ;
#endif
V_219 = V_51 -> V_55 . V_124 - V_51 -> V_55 . V_182 ;
F_92 ( V_67 ,
V_51 -> V_55 . V_168 ,
V_219 * 8 / V_232 ) ;
V_22 = F_121 ( V_49 , V_219 ) ;
if ( V_22 < 0 ) {
F_94 ( & V_51 -> V_55 . V_139 ) ;
return V_22 ;
}
}
V_219 = V_51 -> V_234 -> V_235 % V_51 -> V_115 ;
if ( V_219 > 0 ) {
V_219 = V_51 -> V_115 - V_219 ;
if ( V_51 -> V_236 == V_144 ) {
V_219 = ( V_51 -> V_237 * V_219 ) / 8 ;
while ( V_219 > 0 ) {
T_1 V_1 ;
T_6 V_238 = V_219 < V_51 -> V_55 . V_124 ? V_219 : V_51 -> V_55 . V_124 ;
V_219 -= V_238 ;
V_238 *= 8 ;
V_238 /= V_51 -> V_239 ;
F_92 ( V_51 -> V_67 ,
V_51 -> V_55 . V_168 ,
V_238 ) ;
V_238 /= V_51 -> V_148 ;
V_1 = F_1 () ;
F_102 ( V_49 , ( void V_142 V_193 * ) V_51 -> V_55 . V_168 , V_238 ) ;
F_5 ( V_1 ) ;
}
} else if ( V_51 -> V_236 == V_145 ) {
void V_193 * V_240 [ V_51 -> V_148 ] ;
memset ( V_240 , 0 , V_51 -> V_148 * sizeof( void * ) ) ;
F_106 ( V_49 , V_240 , V_219 ) ;
}
}
F_94 ( & V_51 -> V_55 . V_139 ) ;
V_233:
V_231 = V_49 -> V_213 ;
V_49 -> V_213 &= ~ V_214 ;
V_22 = F_85 ( V_49 , V_198 , NULL ) ;
V_49 -> V_213 = V_231 ;
if ( V_22 < 0 )
return V_22 ;
V_51 -> V_55 . V_169 = 1 ;
}
V_49 = V_174 -> V_178 [ V_158 ] ;
if ( V_49 != NULL ) {
if ( ( V_22 = F_97 ( V_49 ) ) < 0 )
return V_22 ;
V_51 = V_49 -> V_51 ;
V_22 = F_85 ( V_49 , V_153 , NULL ) ;
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
if ( ( V_22 = F_95 ( V_174 , & V_49 ) ) < 0 )
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
if ( ( V_22 = F_95 ( V_174 , & V_49 ) ) < 0 )
return V_22 ;
return V_49 -> V_51 -> V_55 . V_148 ;
}
static int F_136 ( struct V_173 * V_174 )
{
struct V_20 * V_49 ;
int V_22 ;
if ( ( V_22 = F_95 ( V_174 , & V_49 ) ) < 0 )
return V_22 ;
return V_49 -> V_51 -> V_55 . V_124 ;
}
static int F_137 ( struct V_173 * V_174 )
{
struct V_20 * V_49 ;
int V_22 ;
int V_134 ;
struct V_13 * V_14 ;
unsigned int V_241 = 0 ;
struct V_17 V_242 ;
int V_243 ;
if ( ( V_22 = F_95 ( V_174 , & V_49 ) ) < 0 )
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
V_242 = * F_24 ( V_14 , V_149 ) ;
F_40 ( V_14 ) ;
if ( V_22 < 0 )
return V_22 ;
for ( V_243 = 0 ; V_243 < 32 ; ++ V_243 ) {
if ( F_78 ( & V_242 , V_243 ) ) {
int V_244 = F_62 ( V_243 ) ;
if ( V_244 >= 0 )
V_241 |= V_244 ;
}
}
return V_241 ;
}
static int F_138 ( struct V_173 * V_174 , int V_67 )
{
int V_241 , V_176 ;
if ( V_67 != V_245 ) {
V_241 = F_137 ( V_174 ) ;
if ( V_241 < 0 )
return V_241 ;
if ( ! ( V_241 & V_67 ) )
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
if ( ( V_22 = F_95 ( V_174 , & V_49 ) ) < 0 )
return V_22 ;
return V_49 -> V_51 -> V_55 . V_67 ;
}
static int F_140 ( struct V_20 * V_49 , int V_246 )
{
struct V_50 * V_51 ;
if ( V_49 == NULL )
return 0 ;
V_51 = V_49 -> V_51 ;
if ( V_246 == 0 ) {
V_246 = V_51 -> V_55 . V_119 ;
if ( V_246 == 0 )
V_246 = 1 ;
return V_246 ;
}
if ( V_51 -> V_55 . V_119 || V_51 -> V_55 . V_116 )
return - V_7 ;
if ( V_246 != 1 && V_246 != 2 && V_246 != 4 &&
V_246 != 8 && V_246 != 16 )
return - V_7 ;
V_51 -> V_55 . V_119 = V_246 ;
V_51 -> V_55 . V_14 = 1 ;
return V_246 ;
}
static int F_141 ( struct V_173 * V_174 , int V_246 )
{
int V_22 = - V_7 , V_176 ;
for ( V_176 = 1 ; V_176 >= 0 ; -- V_176 ) {
struct V_20 * V_49 = V_174 -> V_178 [ V_176 ] ;
if ( V_49 == NULL )
continue;
if ( ( V_22 = F_140 ( V_49 , V_246 ) ) < 0 )
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
static int F_144 ( struct V_247 * V_247 )
{
F_145 ( & V_247 -> V_248 ) ;
V_247 -> V_213 |= V_214 ;
F_146 ( & V_247 -> V_248 ) ;
return 0 ;
}
static int F_147 ( struct V_20 * V_49 , int V_221 )
{
if ( V_49 == NULL ) {
V_221 &= ~ V_249 ;
return V_221 ;
}
#ifdef F_148
if ( V_49 -> V_151 == V_152 )
if ( V_49 -> V_250 -> V_251 > 1 )
V_221 |= F_148 ;
#endif
#if F_149 ( V_252 ) && 0
{
struct V_50 * V_51 = V_49 -> V_51 ;
if ( V_51 -> V_253 & ( V_254 | V_255 ) )
V_221 &= ~ V_252 ;
}
#endif
return V_221 ;
}
static int F_150 ( struct V_173 * V_174 )
{
int V_220 , V_176 ;
V_220 = V_256 | V_257 | V_249 | V_252 ;
for ( V_176 = 0 ; V_176 < 2 ; V_176 ++ ) {
struct V_20 * V_49 = V_174 -> V_178 [ V_176 ] ;
V_220 = F_147 ( V_49 , V_220 ) ;
}
V_220 |= 0x0001 ;
return V_220 ;
}
static void F_151 ( struct V_20 * V_49 ,
T_4 V_258 )
{
struct V_50 * V_51 = V_49 -> V_51 ;
T_4 V_235 ;
V_235 = V_258 + V_51 -> V_61 ;
V_235 %= V_51 -> V_157 ;
V_51 -> V_234 -> V_235 = V_235 ;
}
static int F_152 ( struct V_173 * V_174 , int V_155 )
{
struct V_50 * V_51 ;
struct V_20 * V_259 = NULL , * V_260 = NULL ;
int V_22 , V_261 ;
#ifdef F_100
F_101 ( V_192 L_23 , V_155 ) ;
#endif
V_259 = V_174 -> V_178 [ V_152 ] ;
V_260 = V_174 -> V_178 [ V_158 ] ;
if ( V_259 ) {
if ( ( V_22 = F_97 ( V_259 ) ) < 0 )
return V_22 ;
}
if ( V_260 ) {
if ( ( V_22 = F_97 ( V_260 ) ) < 0 )
return V_22 ;
}
if ( V_259 ) {
V_51 = V_259 -> V_51 ;
if ( V_155 & V_262 ) {
if ( V_51 -> V_55 . V_155 )
goto V_263;
if ( F_69 ( & V_259 -> V_112 ) )
F_151 ( V_259 ,
F_60 ( V_51 ) ) ;
V_51 -> V_55 . V_155 = 1 ;
V_51 -> V_156 = 1 ;
V_261 = V_218 ;
} else {
if ( ! V_51 -> V_55 . V_155 )
goto V_263;
V_51 -> V_55 . V_155 = 0 ;
V_51 -> V_156 = V_51 -> V_157 ;
V_261 = V_153 ;
V_51 -> V_55 . V_169 = 1 ;
}
V_22 = F_85 ( V_259 , V_261 , NULL ) ;
if ( V_22 < 0 )
return V_22 ;
}
V_263:
if ( V_260 ) {
V_51 = V_260 -> V_51 ;
if ( V_155 & V_264 ) {
if ( V_51 -> V_55 . V_155 )
goto V_265;
V_51 -> V_55 . V_155 = 1 ;
V_51 -> V_156 = 1 ;
V_261 = V_218 ;
} else {
if ( ! V_51 -> V_55 . V_155 )
goto V_265;
V_51 -> V_55 . V_155 = 0 ;
V_51 -> V_156 = V_51 -> V_157 ;
V_261 = V_153 ;
V_51 -> V_55 . V_169 = 1 ;
}
V_22 = F_85 ( V_260 , V_261 , NULL ) ;
if ( V_22 < 0 )
return V_22 ;
}
V_265:
return 0 ;
}
static int F_153 ( struct V_173 * V_174 )
{
struct V_20 * V_259 = NULL , * V_260 = NULL ;
int V_220 = 0 ;
V_259 = V_174 -> V_178 [ V_152 ] ;
V_260 = V_174 -> V_178 [ V_158 ] ;
if ( V_259 && V_259 -> V_51 && V_259 -> V_51 -> V_55 . V_155 )
V_220 |= V_262 ;
if ( V_260 && V_260 -> V_51 && V_260 -> V_51 -> V_55 . V_155 )
V_220 |= V_264 ;
return V_220 ;
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
if ( ( V_22 = F_97 ( V_49 ) ) < 0 )
return V_22 ;
V_51 = V_49 -> V_51 ;
if ( V_51 -> V_55 . V_14 || V_51 -> V_55 . V_169 )
return 0 ;
V_22 = F_85 ( V_49 , V_184 , & V_183 ) ;
if ( V_22 == - V_194 )
V_183 = 0 ;
else if ( V_22 < 0 )
return V_22 ;
return F_54 ( V_49 , V_183 ) ;
}
static int F_155 ( struct V_173 * V_174 , int V_151 , struct V_266 V_193 * V_267 )
{
struct V_20 * V_49 ;
struct V_50 * V_51 ;
T_8 V_183 ;
int V_268 ;
struct V_266 V_253 ;
int V_22 ;
if ( V_267 == NULL )
return - V_208 ;
V_49 = V_174 -> V_178 [ V_151 ] ;
if ( V_49 == NULL )
return - V_7 ;
if ( ( V_22 = F_97 ( V_49 ) ) < 0 )
return V_22 ;
V_51 = V_49 -> V_51 ;
if ( V_51 -> V_55 . V_14 || V_51 -> V_55 . V_169 ) {
memset ( & V_253 , 0 , sizeof( V_253 ) ) ;
if ( F_117 ( V_267 , & V_253 , sizeof( V_253 ) ) )
return - V_208 ;
return 0 ;
}
if ( V_151 == V_152 ) {
V_22 = F_85 ( V_49 , V_184 , & V_183 ) ;
if ( V_22 == - V_194 || V_22 == - V_195 || ( ! V_22 && V_183 < 0 ) ) {
V_22 = 0 ;
V_183 = 0 ;
V_268 = 0 ;
} else {
V_268 = V_51 -> V_55 . V_170 ;
}
} else {
V_22 = F_98 ( V_49 , & V_183 ) ;
V_268 = - V_51 -> V_55 . V_170 ;
}
if ( V_22 < 0 )
return V_22 ;
V_253 . V_186 = F_54 ( V_49 , V_51 -> V_188 -> V_258 % V_51 -> V_61 ) ;
if ( F_69 ( & V_49 -> V_112 ) ) {
T_8 V_136 ;
V_183 = F_60 ( V_51 ) ;
V_136 = V_183 - V_51 -> V_55 . V_181 ;
if ( V_136 < 0 )
V_136 += V_51 -> V_157 ;
V_253 . V_269 = V_136 / V_51 -> V_115 ;
V_51 -> V_55 . V_181 = V_183 ;
if ( V_49 -> V_151 == V_152 )
F_151 ( V_49 , V_183 ) ;
V_253 . V_62 = F_54 ( V_49 , V_51 -> V_188 -> V_258 ) & V_43 ;
} else {
V_183 = F_54 ( V_49 , V_183 ) ;
if ( V_151 == V_152 ) {
if ( V_49 -> V_55 . V_114 . V_270 )
V_253 . V_269 = ( V_51 -> V_55 . V_63 - V_183 - V_268 ) / V_51 -> V_55 . V_124 ;
else
V_253 . V_269 = ( V_183 + V_268 ) / V_51 -> V_55 . V_124 ;
V_253 . V_62 = ( V_51 -> V_55 . V_62 - V_183 ) & V_43 ;
} else {
V_183 += V_268 ;
V_253 . V_269 = V_183 / V_51 -> V_55 . V_124 ;
V_253 . V_62 = ( V_51 -> V_55 . V_62 + V_183 ) & V_43 ;
}
}
if ( F_117 ( V_267 , & V_253 , sizeof( V_253 ) ) )
return - V_208 ;
return 0 ;
}
static int F_156 ( struct V_173 * V_174 , int V_151 , struct V_271 V_193 * V_267 )
{
struct V_20 * V_49 ;
struct V_50 * V_51 ;
T_8 V_272 ;
int V_268 ;
struct V_271 V_253 ;
int V_22 ;
if ( V_267 == NULL )
return - V_208 ;
V_49 = V_174 -> V_178 [ V_151 ] ;
if ( V_49 == NULL )
return - V_7 ;
V_51 = V_49 -> V_51 ;
if ( V_51 -> V_55 . V_14 &&
( V_22 = F_72 ( V_49 ) ) < 0 )
return V_22 ;
V_253 . V_273 = V_51 -> V_55 . V_124 ;
V_253 . V_274 = V_51 -> V_121 ;
if ( V_51 -> V_55 . V_169 ) {
if ( V_151 == V_152 ) {
V_253 . V_62 = V_51 -> V_55 . V_124 * V_51 -> V_55 . V_121 ;
V_253 . V_275 = V_51 -> V_55 . V_121 ;
} else {
V_253 . V_62 = 0 ;
V_253 . V_275 = 0 ;
}
} else {
if ( V_151 == V_152 ) {
V_22 = F_85 ( V_49 , V_184 , & V_272 ) ;
if ( V_22 == - V_194 || V_22 == - V_195 || ( ! V_22 && V_272 < 0 ) ) {
V_272 = V_51 -> V_61 ;
V_22 = 0 ;
V_268 = 0 ;
} else {
V_272 = V_51 -> V_61 - V_272 ;
V_268 = - V_51 -> V_55 . V_170 ;
}
} else {
V_22 = F_98 ( V_49 , & V_272 ) ;
V_268 = V_51 -> V_55 . V_170 ;
}
if ( V_22 < 0 )
return V_22 ;
V_253 . V_62 = F_54 ( V_49 , V_272 ) + V_268 ;
V_253 . V_275 = V_253 . V_62 / V_51 -> V_55 . V_124 ;
}
#ifdef F_100
F_101 ( V_192 L_24
L_25 ,
V_253 . V_62 , V_253 . V_275 , V_253 . V_274 , V_253 . V_273 ) ;
#endif
if ( F_117 ( V_267 , & V_253 , sizeof( V_253 ) ) )
return - V_208 ;
return 0 ;
}
static int F_157 ( struct V_173 * V_174 , int V_151 , struct V_276 V_193 * V_267 )
{
return - V_7 ;
}
static const char * F_158 ( const char * V_277 )
{
const char * V_186 , * V_278 = NULL ;
for ( V_186 = V_277 ; * V_186 ; V_186 ++ ) {
if ( * V_186 == '/' )
V_278 = V_186 + 1 ;
}
return V_278 ;
}
static void F_159 ( struct V_279 * V_21 , int V_151 ,
const char * V_280 ,
struct V_281 * V_282 )
{
struct V_281 * V_114 ;
F_114 ( & V_21 -> V_178 [ V_151 ] . V_55 . V_283 ) ;
do {
for ( V_114 = V_21 -> V_178 [ V_151 ] . V_55 . V_284 ; V_114 ;
V_114 = V_114 -> V_54 ) {
if ( ! strcmp ( V_114 -> V_280 , V_280 ) )
goto V_285;
}
} while ( ( V_280 = F_158 ( V_280 ) ) != NULL );
V_285:
if ( V_114 )
* V_282 = * V_114 ;
F_94 ( & V_21 -> V_178 [ V_151 ] . V_55 . V_283 ) ;
}
static void F_160 ( struct V_20 * V_49 )
{
struct V_50 * V_51 ;
V_51 = V_49 -> V_51 ;
F_90 ( V_51 -> V_55 . V_168 ) ;
V_51 -> V_55 . V_168 = NULL ;
#ifdef F_81
F_50 ( V_49 ) ;
#endif
V_49 -> V_55 . V_55 = 0 ;
}
static void F_161 ( struct V_20 * V_49 ,
struct V_281 * V_114 ,
int V_286 )
{
struct V_50 * V_51 ;
V_49 -> V_55 . V_55 = 1 ;
V_49 -> V_55 . V_114 = * V_114 ;
if ( V_114 -> V_287 )
V_49 -> V_213 |= V_214 ;
else if ( V_114 -> V_288 )
V_49 -> V_213 &= ~ V_214 ;
V_51 = V_49 -> V_51 ;
V_51 -> V_55 . V_14 = 1 ;
V_51 -> V_55 . V_155 = 1 ;
V_51 -> V_55 . V_128 = 8000 ;
F_162 ( & V_51 -> V_55 . V_139 ) ;
switch ( F_163 ( V_286 ) ) {
case V_289 :
V_51 -> V_55 . V_67 = V_74 ;
break;
case V_290 :
V_51 -> V_55 . V_67 = V_76 ;
break;
default:
V_51 -> V_55 . V_67 = V_68 ;
}
V_51 -> V_55 . V_148 = 1 ;
V_51 -> V_55 . V_116 = 0 ;
V_51 -> V_55 . V_123 = 0 ;
V_51 -> V_55 . V_119 = 0 ;
V_49 -> V_291 = F_160 ;
}
static int F_164 ( struct V_173 * V_174 )
{
int V_292 ;
if ( ! V_174 )
return 0 ;
for ( V_292 = 0 ; V_292 < 2 ; ++ V_292 ) {
struct V_20 * V_49 = V_174 -> V_178 [ V_292 ] ;
if ( V_49 )
F_165 ( V_49 ) ;
}
F_40 ( V_174 ) ;
return 0 ;
}
static int F_166 ( struct V_247 * V_247 ,
struct V_279 * V_21 ,
struct V_173 * * V_293 ,
int V_286 ,
struct V_281 * V_114 )
{
int V_176 , V_22 ;
struct V_173 * V_174 ;
struct V_20 * V_49 ;
T_11 V_294 = V_247 -> V_294 ;
if ( V_293 )
* V_293 = NULL ;
V_174 = F_167 ( sizeof( * V_174 ) , V_44 ) ;
if ( V_174 == NULL )
return - V_45 ;
if ( ( V_294 & ( V_295 | V_296 ) ) == ( V_295 | V_296 ) &&
( V_21 -> V_297 & V_298 ) )
V_294 = V_295 ;
V_247 -> V_213 &= ~ V_299 ;
for ( V_176 = 0 ; V_176 < 2 ; V_176 ++ ) {
if ( V_114 [ V_176 ] . V_300 )
continue;
if ( ! V_21 -> V_178 [ V_176 ] . V_251 )
continue;
if ( V_176 == V_152 ) {
if ( ! ( V_294 & V_295 ) )
continue;
} else {
if ( ! ( V_294 & V_296 ) )
continue;
}
V_22 = F_168 ( V_21 , V_176 , V_247 , & V_49 ) ;
if ( V_22 < 0 ) {
F_164 ( V_174 ) ;
return V_22 ;
}
V_174 -> V_178 [ V_176 ] = V_49 ;
V_49 -> V_247 = V_174 ;
F_161 ( V_49 , & V_114 [ V_176 ] , V_286 ) ;
}
if ( ! V_174 -> V_178 [ 0 ] && ! V_174 -> V_178 [ 1 ] ) {
F_164 ( V_174 ) ;
return - V_7 ;
}
V_247 -> V_301 = V_174 ;
if ( V_293 )
* V_293 = V_174 ;
return 0 ;
}
static int F_169 ( struct V_302 * V_303 , char * V_304 , T_6 V_219 )
{
unsigned int V_176 ;
if ( F_43 ( ! V_303 || ! V_304 || V_219 < 2 ) )
return - V_7 ;
for ( V_176 = 0 ; V_176 < sizeof( V_303 -> V_305 ) && V_176 + 1 < V_219 ; V_176 ++ )
V_304 [ V_176 ] = V_303 -> V_305 [ V_176 ] ;
V_304 [ V_176 ] = '\0' ;
return 0 ;
}
static int F_170 ( struct V_306 * V_306 , struct V_247 * V_247 )
{
int V_22 ;
char V_280 [ 32 ] ;
struct V_279 * V_21 ;
struct V_173 * V_174 ;
struct V_281 V_114 [ 2 ] ;
int V_287 ;
T_10 V_222 ;
V_22 = F_171 ( V_306 , V_247 ) ;
if ( V_22 < 0 )
return V_22 ;
V_21 = F_172 ( F_173 ( V_306 ) ,
V_307 ) ;
if ( V_21 == NULL ) {
V_22 = - V_308 ;
goto V_309;
}
V_22 = F_174 ( V_21 -> V_310 , V_247 ) ;
if ( V_22 < 0 )
goto V_309;
if ( ! F_175 ( V_21 -> V_310 -> V_311 ) ) {
V_22 = - V_208 ;
goto V_312;
}
if ( F_169 ( V_223 , V_280 , sizeof( V_280 ) ) < 0 ) {
V_22 = - V_208 ;
goto V_313;
}
memset ( V_114 , 0 , sizeof( V_114 ) ) ;
if ( V_247 -> V_294 & V_295 )
F_159 ( V_21 , V_152 ,
V_280 , & V_114 [ 0 ] ) ;
if ( V_247 -> V_294 & V_296 )
F_159 ( V_21 , V_158 ,
V_280 , & V_114 [ 1 ] ) ;
V_287 = ! ! ( V_247 -> V_213 & V_214 ) ;
if ( ! V_287 )
V_287 = V_314 ;
F_122 ( & V_222 , V_223 ) ;
F_123 ( & V_21 -> V_315 , & V_222 ) ;
F_114 ( & V_21 -> V_316 ) ;
while ( 1 ) {
V_22 = F_166 ( V_247 , V_21 , & V_174 ,
F_173 ( V_306 ) , V_114 ) ;
if ( V_22 >= 0 )
break;
if ( V_22 == - V_197 ) {
if ( V_287 ) {
V_22 = - V_317 ;
break;
}
} else
break;
F_124 ( V_225 ) ;
F_94 ( & V_21 -> V_316 ) ;
F_176 () ;
F_114 ( & V_21 -> V_316 ) ;
if ( V_21 -> V_310 -> V_318 ) {
V_22 = - V_308 ;
break;
}
if ( F_128 ( V_223 ) ) {
V_22 = - V_229 ;
break;
}
}
F_130 ( & V_21 -> V_315 , & V_222 ) ;
F_94 ( & V_21 -> V_316 ) ;
if ( V_22 < 0 )
goto V_313;
F_177 ( V_21 -> V_310 ) ;
return V_22 ;
V_313:
F_178 ( V_21 -> V_310 -> V_311 ) ;
V_312:
F_179 ( V_21 -> V_310 , V_247 ) ;
V_309:
if ( V_21 )
F_177 ( V_21 -> V_310 ) ;
return V_22 ;
}
static int F_180 ( struct V_306 * V_306 , struct V_247 * V_247 )
{
struct V_279 * V_21 ;
struct V_20 * V_49 ;
struct V_173 * V_174 ;
V_174 = V_247 -> V_301 ;
V_49 = V_174 -> V_178 [ V_152 ] ;
if ( V_49 == NULL )
V_49 = V_174 -> V_178 [ V_158 ] ;
if ( F_43 ( ! V_49 ) )
return - V_211 ;
V_21 = V_49 -> V_21 ;
if ( ! V_21 -> V_310 -> V_318 )
F_131 ( V_174 ) ;
F_114 ( & V_21 -> V_316 ) ;
F_164 ( V_174 ) ;
F_94 ( & V_21 -> V_316 ) ;
F_181 ( & V_21 -> V_315 ) ;
F_178 ( V_21 -> V_310 -> V_311 ) ;
F_179 ( V_21 -> V_310 , V_247 ) ;
return 0 ;
}
static long F_182 ( struct V_247 * V_247 , unsigned int V_261 , unsigned long V_319 )
{
struct V_173 * V_174 ;
int V_193 * V_320 = ( int V_193 * ) V_319 ;
int V_221 ;
V_174 = V_247 -> V_301 ;
if ( V_261 == V_321 )
return F_183 ( V_322 , V_320 ) ;
if ( V_261 == V_323 )
return F_183 ( 1 , V_320 ) ;
#if F_149 ( V_324 ) || ( F_149 ( V_325 ) && F_149 ( V_326 ) )
if ( ( ( V_261 >> 8 ) & 0xff ) == 'M' ) {
struct V_20 * V_49 ;
int V_176 ;
for ( V_176 = 0 ; V_176 < 2 ; ++ V_176 ) {
V_49 = V_174 -> V_178 [ V_176 ] ;
if ( V_49 != NULL )
break;
}
if ( F_43 ( V_176 >= 2 ) )
return - V_211 ;
return F_184 ( V_49 -> V_21 -> V_310 , V_261 , V_319 ) ;
}
#endif
if ( ( ( V_261 >> 8 ) & 0xff ) != 'P' )
return - V_7 ;
#ifdef F_100
F_101 ( V_192 L_26 , V_261 ) ;
#endif
switch ( V_261 ) {
case V_327 :
return F_119 ( V_174 ) ;
case V_328 :
return F_131 ( V_174 ) ;
case V_329 :
if ( F_185 ( V_221 , V_320 ) )
return - V_208 ;
if ( ( V_221 = F_132 ( V_174 , V_221 ) ) < 0 )
return V_221 ;
return F_183 ( V_221 , V_320 ) ;
case V_330 :
V_221 = F_133 ( V_174 ) ;
if ( V_221 < 0 )
return V_221 ;
return F_183 ( V_221 , V_320 ) ;
case V_331 :
if ( F_185 ( V_221 , V_320 ) )
return - V_208 ;
V_221 = V_221 > 0 ? 2 : 1 ;
if ( ( V_221 = F_134 ( V_174 , V_221 ) ) < 0 )
return V_221 ;
return F_183 ( -- V_221 , V_320 ) ;
case V_332 :
V_221 = F_136 ( V_174 ) ;
if ( V_221 < 0 )
return V_221 ;
return F_183 ( V_221 , V_320 ) ;
case V_333 :
if ( F_185 ( V_221 , V_320 ) )
return - V_208 ;
V_221 = F_138 ( V_174 , V_221 ) ;
if ( V_221 < 0 )
return V_221 ;
return F_183 ( V_221 , V_320 ) ;
case V_334 :
V_221 = F_139 ( V_174 ) ;
if ( V_221 < 0 )
return V_221 ;
return F_183 ( V_221 , V_320 ) ;
case V_335 :
if ( F_185 ( V_221 , V_320 ) )
return - V_208 ;
V_221 = F_134 ( V_174 , V_221 ) ;
if ( V_221 < 0 )
return V_221 ;
return F_183 ( V_221 , V_320 ) ;
case V_336 :
V_221 = F_135 ( V_174 ) ;
if ( V_221 < 0 )
return V_221 ;
return F_183 ( V_221 , V_320 ) ;
case V_337 :
case V_338 :
return - V_179 ;
case V_339 :
return F_120 ( V_174 ) ;
case V_340 :
if ( F_185 ( V_221 , V_320 ) )
return - V_208 ;
V_221 = F_141 ( V_174 , V_221 ) ;
if ( V_221 < 0 )
return V_221 ;
return F_183 ( V_221 , V_320 ) ;
case V_341 :
if ( F_185 ( V_221 , V_320 ) )
return - V_208 ;
return F_143 ( V_174 , V_221 ) ;
case V_342 :
V_221 = F_137 ( V_174 ) ;
if ( V_221 < 0 )
return V_221 ;
return F_183 ( V_221 , V_320 ) ;
case V_343 :
case V_344 :
return F_156 ( V_174 ,
V_261 == V_344 ?
V_158 : V_152 ,
(struct V_271 V_193 * ) V_319 ) ;
case V_345 :
return F_144 ( V_247 ) ;
case V_346 :
V_221 = F_150 ( V_174 ) ;
if ( V_221 < 0 )
return V_221 ;
return F_183 ( V_221 , V_320 ) ;
case V_347 :
V_221 = F_153 ( V_174 ) ;
if ( V_221 < 0 )
return V_221 ;
return F_183 ( V_221 , V_320 ) ;
case V_348 :
if ( F_185 ( V_221 , V_320 ) )
return - V_208 ;
return F_152 ( V_174 , V_221 ) ;
case V_349 :
case V_350 :
return F_155 ( V_174 ,
V_261 == V_349 ?
V_158 : V_152 ,
(struct V_266 V_193 * ) V_319 ) ;
case V_351 :
case V_352 :
return F_157 ( V_174 ,
V_261 == V_351 ?
V_158 : V_152 ,
(struct V_276 V_193 * ) V_319 ) ;
case V_353 :
return 0 ;
case V_354 :
if ( F_150 ( V_174 ) & V_249 )
return 0 ;
return - V_179 ;
case V_355 :
V_221 = F_154 ( V_174 ) ;
if ( V_221 < 0 ) {
F_183 ( 0 , V_320 ) ;
return V_221 ;
}
return F_183 ( V_221 , V_320 ) ;
case V_356 :
return 0 ;
default:
F_74 ( L_27 , V_261 ) ;
}
return - V_7 ;
}
static T_7 F_186 ( struct V_247 * V_247 , char V_193 * V_202 , T_6 V_357 , T_12 * V_358 )
{
struct V_173 * V_174 ;
struct V_20 * V_49 ;
V_174 = V_247 -> V_301 ;
V_49 = V_174 -> V_178 [ V_158 ] ;
if ( V_49 == NULL )
return - V_211 ;
V_49 -> V_213 = V_247 -> V_213 & V_214 ;
#ifndef F_100
return F_118 ( V_49 , V_202 , V_357 ) ;
#else
{
T_7 V_221 = F_118 ( V_49 , V_202 , V_357 ) ;
F_101 ( V_192 L_28
L_29 , ( long ) V_357 , ( long ) V_221 ) ;
return V_221 ;
}
#endif
}
static T_7 F_187 ( struct V_247 * V_247 , const char V_193 * V_202 , T_6 V_357 , T_12 * V_358 )
{
struct V_173 * V_174 ;
struct V_20 * V_49 ;
long V_220 ;
V_174 = V_247 -> V_301 ;
V_49 = V_174 -> V_178 [ V_152 ] ;
if ( V_49 == NULL )
return - V_211 ;
V_49 -> V_213 = V_247 -> V_213 & V_214 ;
V_220 = F_113 ( V_49 , V_202 , V_357 ) ;
#ifdef F_100
F_101 ( V_192 L_30 ,
( long ) V_357 , ( long ) V_220 ) ;
#endif
return V_220 ;
}
static int F_188 ( struct V_20 * V_49 )
{
struct V_50 * V_51 = V_49 -> V_51 ;
if ( F_69 ( & V_49 -> V_112 ) )
return V_51 -> V_55 . V_181 !=
F_60 ( V_51 ) ;
else
return F_189 ( V_51 ) >=
V_51 -> V_55 . V_125 ;
}
static int F_190 ( struct V_20 * V_49 )
{
struct V_50 * V_51 = V_49 -> V_51 ;
if ( F_69 ( & V_49 -> V_112 ) )
return V_51 -> V_55 . V_181 !=
F_60 ( V_51 ) ;
else
return F_191 ( V_51 ) >=
V_51 -> V_55 . V_125 ;
}
static unsigned int F_192 ( struct V_247 * V_247 , T_13 * V_222 )
{
struct V_173 * V_174 ;
unsigned int V_138 ;
struct V_20 * V_259 = NULL , * V_260 = NULL ;
V_174 = V_247 -> V_301 ;
V_259 = V_174 -> V_178 [ V_152 ] ;
V_260 = V_174 -> V_178 [ V_158 ] ;
V_138 = 0 ;
if ( V_259 != NULL ) {
struct V_50 * V_51 = V_259 -> V_51 ;
F_193 ( V_247 , & V_51 -> V_224 , V_222 ) ;
F_125 ( V_259 ) ;
if ( V_51 -> V_188 -> V_189 != V_200 &&
( V_51 -> V_188 -> V_189 != V_226 ||
F_188 ( V_259 ) ) )
V_138 |= V_359 | V_360 ;
F_126 ( V_259 ) ;
}
if ( V_260 != NULL ) {
struct V_50 * V_51 = V_260 -> V_51 ;
T_9 V_361 ;
F_193 ( V_247 , & V_51 -> V_224 , V_222 ) ;
F_125 ( V_260 ) ;
if ( ( V_361 = V_51 -> V_188 -> V_189 ) != V_226 ||
F_190 ( V_260 ) )
V_138 |= V_362 | V_363 ;
F_126 ( V_260 ) ;
if ( V_361 != V_226 && V_51 -> V_55 . V_155 ) {
struct V_173 V_364 ;
memset ( & V_364 , 0 , sizeof( V_364 ) ) ;
V_364 . V_178 [ V_158 ] = V_174 -> V_178 [ V_158 ] ;
V_51 -> V_55 . V_155 = 0 ;
F_152 ( & V_364 , V_264 ) ;
}
}
return V_138 ;
}
static int F_194 ( struct V_247 * V_247 , struct V_365 * V_366 )
{
struct V_173 * V_174 ;
struct V_20 * V_49 = NULL ;
struct V_50 * V_51 ;
int V_22 ;
#ifdef F_100
F_101 ( V_192 L_31 ) ;
#endif
V_174 = V_247 -> V_301 ;
switch ( ( V_366 -> V_367 & ( V_368 | V_369 ) ) ) {
case V_368 | V_369 :
V_49 = V_174 -> V_178 [ V_152 ] ;
if ( V_49 )
break;
case V_368 :
V_49 = V_174 -> V_178 [ V_158 ] ;
break;
case V_369 :
V_49 = V_174 -> V_178 [ V_152 ] ;
break;
default:
return - V_7 ;
}
V_366 -> V_367 |= V_368 ;
if ( V_49 == NULL )
return - V_211 ;
V_51 = V_49 -> V_51 ;
if ( ! ( V_51 -> V_253 & V_370 ) )
return - V_179 ;
if ( V_51 -> V_253 & V_371 )
V_51 -> V_236 = V_143 ;
else
return - V_179 ;
if ( V_51 -> V_55 . V_14 ) {
if ( ( V_22 = F_72 ( V_49 ) ) < 0 )
return V_22 ;
}
#ifdef F_81
if ( V_51 -> V_55 . V_56 != NULL )
return - V_179 ;
#endif
if ( V_366 -> V_372 != 0 )
return - V_7 ;
V_22 = F_195 ( V_49 , V_247 , V_366 ) ;
if ( V_22 < 0 )
return V_22 ;
V_51 -> V_55 . V_113 = V_366 -> V_373 - V_366 -> V_374 ;
V_51 -> V_165 = 0 ;
V_51 -> V_166 = 0 ;
#ifdef F_100
F_101 ( V_192 L_32 ,
V_51 -> V_55 . V_113 ) ;
#endif
V_51 -> V_159 = V_51 -> V_157 ;
return 0 ;
}
static void F_196 ( struct V_375 * V_376 ,
struct V_377 * V_168 )
{
struct V_378 * V_250 = V_376 -> V_301 ;
struct V_281 * V_114 = V_250 -> V_55 . V_284 ;
F_114 ( & V_250 -> V_55 . V_283 ) ;
while ( V_114 ) {
F_197 ( V_168 , L_33 ,
V_114 -> V_280 ,
V_114 -> V_121 ,
V_114 -> V_115 ,
V_114 -> V_300 ? L_34 : L_35 ,
V_114 -> V_134 ? L_36 : L_35 ,
V_114 -> V_288 ? L_37 : L_35 ,
V_114 -> V_287 ? L_38 : L_35 ,
V_114 -> V_212 ? L_39 : L_35 ,
V_114 -> V_164 ? L_40 : L_35 ) ;
V_114 = V_114 -> V_54 ;
}
F_94 ( & V_250 -> V_55 . V_283 ) ;
}
static void F_198 ( struct V_378 * V_250 )
{
struct V_281 * V_114 , * V_379 ;
for ( V_114 = V_250 -> V_55 . V_284 , V_250 -> V_55 . V_284 = NULL ;
V_114 ; V_114 = V_379 ) {
V_379 = V_114 -> V_54 ;
F_40 ( V_114 -> V_280 ) ;
F_40 ( V_114 ) ;
}
V_250 -> V_55 . V_284 = NULL ;
}
static void F_199 ( struct V_375 * V_376 ,
struct V_377 * V_168 )
{
struct V_378 * V_250 = V_376 -> V_301 ;
char line [ 128 ] , V_380 [ 32 ] , V_280 [ 32 ] ;
const char * V_186 ;
int V_381 ;
struct V_281 * V_114 , * V_382 , V_383 ;
while ( ! F_200 ( V_168 , line , sizeof( line ) ) ) {
F_114 ( & V_250 -> V_55 . V_283 ) ;
memset ( & V_383 , 0 , sizeof( V_383 ) ) ;
V_186 = F_201 ( V_280 , line , sizeof( V_280 ) ) ;
if ( ! strcmp ( V_280 , L_41 ) || ! strcmp ( V_280 , L_42 ) ) {
F_198 ( V_250 ) ;
F_94 ( & V_250 -> V_55 . V_283 ) ;
continue;
}
for ( V_114 = V_250 -> V_55 . V_284 ; V_114 ; V_114 = V_114 -> V_54 ) {
if ( ! strcmp ( V_114 -> V_280 , V_280 ) ) {
V_383 = * V_114 ;
break;
}
}
V_186 = F_201 ( V_380 , V_186 , sizeof( V_380 ) ) ;
V_383 . V_121 = F_202 ( V_380 , NULL , 10 ) ;
V_186 = F_201 ( V_380 , V_186 , sizeof( V_380 ) ) ;
V_383 . V_115 = F_202 ( V_380 , NULL , 10 ) ;
for ( V_381 = 31 ; V_381 >= 0 ; V_381 -- )
if ( V_383 . V_115 & ( 1 << V_381 ) )
break;
for ( V_381 -- ; V_381 >= 0 ; V_381 -- )
V_383 . V_115 &= ~ ( 1 << V_381 ) ;
do {
V_186 = F_201 ( V_380 , V_186 , sizeof( V_380 ) ) ;
if ( ! strcmp ( V_380 , L_43 ) ) {
V_383 . V_300 = 1 ;
} else if ( ! strcmp ( V_380 , L_44 ) ) {
V_383 . V_134 = 1 ;
} else if ( ! strcmp ( V_380 , L_45 ) ) {
V_383 . V_288 = 1 ;
} else if ( ! strcmp ( V_380 , L_46 ) ) {
V_383 . V_287 = 1 ;
} else if ( ! strcmp ( V_380 , L_47 ) ) {
V_383 . V_212 = 1 ;
} else if ( ! strcmp ( V_380 , L_48 ) ) {
V_383 . V_164 = 1 ;
} else if ( ! strcmp ( V_380 , L_49 ) ) {
V_383 . V_270 = 1 ;
}
} while ( * V_380 );
if ( V_114 == NULL ) {
V_114 = F_39 ( sizeof( * V_114 ) , V_44 ) ;
if ( ! V_114 ) {
V_168 -> error = - V_45 ;
F_94 ( & V_250 -> V_55 . V_283 ) ;
return;
}
if ( V_250 -> V_55 . V_284 == NULL )
V_250 -> V_55 . V_284 = V_114 ;
else {
for ( V_382 = V_250 -> V_55 . V_284 ;
V_382 -> V_54 ; V_382 = V_382 -> V_54 ) ;
V_382 -> V_54 = V_114 ;
}
V_383 . V_280 = F_203 ( V_280 , V_44 ) ;
if ( ! V_383 . V_280 ) {
F_40 ( V_114 ) ;
V_168 -> error = - V_45 ;
F_94 ( & V_250 -> V_55 . V_283 ) ;
return;
}
}
* V_114 = V_383 ;
F_94 ( & V_250 -> V_55 . V_283 ) ;
}
}
static void F_204 ( struct V_279 * V_21 )
{
int V_151 ;
for ( V_151 = 0 ; V_151 < 2 ; ++ V_151 ) {
struct V_375 * V_376 ;
struct V_378 * V_250 = & V_21 -> V_178 [ V_151 ] ;
if ( V_250 -> V_251 == 0 )
continue;
if ( ( V_376 = F_205 ( V_21 -> V_310 , L_50 , V_250 -> V_384 ) ) != NULL ) {
V_376 -> V_385 = V_386 ;
V_376 -> V_387 = V_388 | V_389 | V_390 ;
V_376 -> V_28 . V_391 . V_392 = F_196 ;
V_376 -> V_28 . V_391 . V_393 = F_199 ;
V_376 -> V_301 = V_250 ;
if ( F_206 ( V_376 ) < 0 ) {
F_207 ( V_376 ) ;
V_376 = NULL ;
}
}
V_250 -> V_55 . V_394 = V_376 ;
}
}
static void F_208 ( struct V_279 * V_21 )
{
int V_151 ;
for ( V_151 = 0 ; V_151 < 2 ; ++ V_151 ) {
struct V_378 * V_250 = & V_21 -> V_178 [ V_151 ] ;
F_207 ( V_250 -> V_55 . V_394 ) ;
V_250 -> V_55 . V_394 = NULL ;
F_198 ( V_250 ) ;
}
}
static void F_209 ( struct V_279 * V_21 , int V_395 )
{
char V_304 [ 128 ] ;
sprintf ( V_304 , L_51 , V_21 -> V_310 -> V_396 , V_21 -> V_397 ) ;
if ( F_210 ( V_307 ,
V_21 -> V_310 , V_395 , & V_398 ,
V_21 , V_304 ) < 0 ) {
F_129 ( V_230 L_52 ,
V_21 -> V_310 -> V_396 , V_21 -> V_397 ) ;
}
}
static int F_211 ( struct V_279 * V_21 )
{
V_21 -> V_55 . V_399 = 0 ;
if ( V_400 [ V_21 -> V_310 -> V_396 ] == ( int ) V_21 -> V_397 ) {
char V_304 [ 128 ] ;
int V_401 ;
F_209 ( V_21 , 0 ) ;
V_401 = ( V_21 -> V_178 [ V_152 ] . V_251 > 0 &&
V_21 -> V_178 [ V_158 ] . V_251 &&
! ( V_21 -> V_297 & V_298 ) ) ;
sprintf ( V_304 , L_53 , V_21 -> V_304 , V_401 ? L_54 : L_35 ) ;
#ifdef F_212
F_213 ( F_212 ,
V_21 -> V_310 -> V_396 ,
V_304 ) ;
#endif
V_21 -> V_55 . V_399 ++ ;
V_21 -> V_55 . V_402 |= 1 ;
}
if ( V_403 [ V_21 -> V_310 -> V_396 ] == ( int ) V_21 -> V_397 ) {
F_209 ( V_21 , 1 ) ;
V_21 -> V_55 . V_399 ++ ;
V_21 -> V_55 . V_402 |= 2 ;
}
if ( V_21 -> V_55 . V_399 )
F_204 ( V_21 ) ;
return 0 ;
}
static int F_214 ( struct V_279 * V_21 )
{
if ( V_21 -> V_55 . V_399 ) {
if ( V_21 -> V_55 . V_402 & 1 ) {
V_21 -> V_55 . V_402 &= ~ 1 ;
F_215 ( V_307 ,
V_21 -> V_310 , 0 ) ;
}
if ( V_21 -> V_55 . V_402 & 2 ) {
V_21 -> V_55 . V_402 &= ~ 2 ;
F_215 ( V_307 ,
V_21 -> V_310 , 1 ) ;
}
if ( V_400 [ V_21 -> V_310 -> V_396 ] == ( int ) V_21 -> V_397 ) {
#ifdef F_212
F_216 ( F_212 , V_21 -> V_310 -> V_396 ) ;
#endif
}
V_21 -> V_55 . V_399 = 0 ;
}
return 0 ;
}
static int F_217 ( struct V_279 * V_21 )
{
F_214 ( V_21 ) ;
F_208 ( V_21 ) ;
return 0 ;
}
static int T_14 F_218 ( void )
{
int V_3 ;
int V_22 ;
for ( V_3 = 0 ; V_3 < V_404 ; V_3 ++ ) {
if ( V_400 [ V_3 ] < 0 || V_400 [ V_3 ] >= V_405 ) {
F_129 ( V_230 L_55 ,
V_3 , V_400 [ V_3 ] ) ;
V_400 [ V_3 ] = 0 ;
}
if ( V_403 [ V_3 ] < 0 || V_403 [ V_3 ] >= V_405 ) {
F_129 ( V_230 L_56 ,
V_3 , V_403 [ V_3 ] ) ;
V_403 [ V_3 ] = 1 ;
}
}
if ( ( V_22 = F_219 ( & V_406 , 0 ) ) < 0 )
return V_22 ;
return 0 ;
}
static void T_15 F_220 ( void )
{
F_219 ( & V_406 , 1 ) ;
}
