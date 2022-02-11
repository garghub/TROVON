static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static inline struct V_4 * F_3 ( struct V_5 * V_6 )
{
return F_2 ( V_6 , struct V_4 , V_6 ) ;
}
static int F_4 ( struct V_7 * V_8 )
{
unsigned int V_9 ;
V_9 = F_5 ( V_8 -> V_10 + V_11 ) ;
return V_9 & V_12 ;
}
static void F_6 ( struct V_1 * V_13 ,
struct V_4 * V_14 )
{
struct V_15 * V_16 = V_13 -> V_17 ;
struct V_7 * V_18 = V_13 -> V_18 ;
struct V_19 * V_20 = & V_14 -> V_21 [ 0 ] ;
T_1 V_9 ;
V_13 -> V_22 = V_14 ;
while ( F_4 ( V_18 ) )
F_7 () ;
F_8 ( & V_16 -> V_23 -> V_24 ,
L_1
L_2 ,
V_18 -> V_25 , V_20 -> V_26 , V_20 -> V_27 , V_20 -> V_20 , V_20 -> V_28 ,
V_14 -> V_29 ) ;
F_9 ( V_20 -> V_26 , V_18 -> V_10 + V_30 ) ;
F_9 ( V_20 -> V_27 , V_18 -> V_10 + V_31 ) ;
F_9 ( V_20 -> V_20 , V_18 -> V_10 + V_32 ) ;
F_9 ( V_20 -> V_28 , V_18 -> V_10 + V_33 ) ;
F_9 ( V_14 -> V_29 , V_18 -> V_10 + V_11 ) ;
while ( F_5 ( V_16 -> V_10 + V_34 ) & ( 1 << V_18 -> V_25 ) )
F_7 () ;
V_9 = F_5 ( V_18 -> V_10 + V_11 ) ;
while ( ( V_9 & V_12 ) || ( V_9 & V_35 ) )
V_9 = F_5 ( V_18 -> V_10 + V_11 ) ;
F_9 ( V_9 | V_35 , V_18 -> V_10 + V_11 ) ;
}
static void F_10 ( struct V_7 * V_8 )
{
T_1 V_9 ;
int V_36 ;
V_9 = F_5 ( V_8 -> V_10 + V_11 ) ;
V_9 |= V_37 ;
F_9 ( V_9 , V_8 -> V_10 + V_11 ) ;
for ( V_36 = 1000 ; V_36 ; V_36 -- ) {
if ( ! F_4 ( V_8 ) )
break;
F_11 ( 1 ) ;
}
if ( F_4 ( V_8 ) )
F_12 ( L_3 , V_8 -> V_25 ) ;
}
static void F_13 ( struct V_7 * V_8 )
{
T_1 V_9 ;
V_9 = F_5 ( V_8 -> V_10 + V_11 ) ;
V_9 &= ~ V_37 ;
F_9 ( V_9 , V_8 -> V_10 + V_11 ) ;
}
static void F_14 ( struct V_15 * V_16 ,
struct V_7 * V_8 )
{
T_1 V_9 = F_5 ( V_8 -> V_10 + V_11 ) ;
V_9 &= ~ ( V_35 | V_38 |
V_39 ) ;
F_9 ( V_9 , V_8 -> V_10 + V_11 ) ;
F_9 ( 1 << V_8 -> V_25 , V_16 -> V_10 + V_40 ) ;
F_9 ( 1 << V_8 -> V_25 , V_16 -> V_10 + V_41 ) ;
}
static inline T_1 F_15 ( T_1 V_28 )
{
T_1 V_42 = V_28 & V_43 ;
switch ( V_28 >> V_44 ) {
case V_45 :
break;
case V_46 :
V_42 *= 2 ;
break;
case V_47 :
V_42 *= 4 ;
break;
}
return V_42 ;
}
static T_1 F_16 ( struct V_1 * V_13 )
{
struct V_7 * V_8 ;
struct V_4 * V_14 ;
unsigned long V_48 ;
T_2 V_42 = 0 ;
F_17 ( & V_13 -> V_49 , V_48 ) ;
V_8 = V_13 -> V_18 ;
V_14 = V_13 -> V_22 ;
if ( V_8 && V_14 ) {
T_1 V_50 = F_5 ( V_8 -> V_10 + V_32 ) & ~ V_51 ;
V_42 = F_15 ( F_5 ( V_8 -> V_10 + V_33 ) ) ;
if ( V_50 ) {
struct V_19 * V_21 = V_14 -> V_21 ;
T_3 V_52 = V_14 -> V_52 ;
int V_53 ;
F_18 ( V_50 < V_52 || V_50 >= V_52 +
sizeof( struct V_19 ) * V_54 ) ;
V_53 = ( V_50 - V_52 ) / sizeof( struct V_19 ) ;
for (; V_53 < V_54 ; V_53 ++ ) {
V_42 += F_15 ( V_21 [ V_53 ] . V_28 ) ;
if ( ! V_21 [ V_53 ] . V_20 )
break;
}
}
}
if ( ! F_19 ( & V_13 -> V_55 ) ) {
struct V_4 * V_56 ;
F_20 (txdi, &plchan->pend_list, node) {
V_42 += V_56 -> V_57 ;
}
}
F_21 ( & V_13 -> V_49 , V_48 ) ;
return V_42 ;
}
static struct V_7 *
F_22 ( struct V_15 * V_16 ,
struct V_1 * V_58 )
{
struct V_7 * V_8 = NULL ;
unsigned long V_48 ;
int V_59 ;
for ( V_59 = 0 ; V_59 < V_16 -> V_60 -> V_61 ; V_59 ++ ) {
V_8 = & V_16 -> V_62 [ V_59 ] ;
F_17 ( & V_8 -> V_49 , V_48 ) ;
if ( ! V_8 -> V_63 ) {
V_8 -> V_63 = V_58 ;
V_8 -> signal = - 1 ;
F_21 ( & V_8 -> V_49 , V_48 ) ;
break;
}
F_21 ( & V_8 -> V_49 , V_48 ) ;
}
if ( V_59 == V_16 -> V_60 -> V_61 ) {
return NULL ;
}
return V_8 ;
}
static inline void F_23 ( struct V_15 * V_16 ,
struct V_7 * V_8 )
{
unsigned long V_48 ;
F_17 ( & V_8 -> V_49 , V_48 ) ;
F_14 ( V_16 , V_8 ) ;
V_8 -> V_63 = NULL ;
F_21 ( & V_8 -> V_49 , V_48 ) ;
}
static inline unsigned int F_24 ( unsigned int V_64 )
{
switch ( V_64 ) {
case V_45 :
return 1 ;
case V_46 :
return 2 ;
case V_47 :
return 4 ;
default:
break;
}
F_25 () ;
return 0 ;
}
static inline T_1 F_26 ( T_1 V_28 , T_4 V_65 , T_4 V_66 ,
T_2 V_67 )
{
T_1 V_68 = V_28 ;
V_68 &= ~ V_69 ;
V_68 &= ~ V_70 ;
V_68 &= ~ V_43 ;
switch ( V_65 ) {
case 1 :
V_68 |= V_45 << V_44 ;
break;
case 2 :
V_68 |= V_46 << V_44 ;
break;
case 4 :
V_68 |= V_47 << V_44 ;
break;
default:
F_25 () ;
break;
}
switch ( V_66 ) {
case 1 :
V_68 |= V_45 << V_71 ;
break;
case 2 :
V_68 |= V_46 << V_71 ;
break;
case 4 :
V_68 |= V_47 << V_71 ;
break;
default:
F_25 () ;
break;
}
V_68 |= V_67 << V_72 ;
return V_68 ;
}
static void F_27 ( struct V_73 * V_74 ,
struct V_75 * * V_76 , struct V_75 * * V_77 , T_1 V_28 )
{
if ( ! ( V_28 & V_78 ) ) {
* V_76 = & V_74 -> V_79 ;
* V_77 = & V_74 -> V_80 ;
} else if ( ! ( V_28 & V_81 ) ) {
* V_76 = & V_74 -> V_80 ;
* V_77 = & V_74 -> V_79 ;
} else {
if ( V_74 -> V_80 . V_82 == 4 ) {
* V_76 = & V_74 -> V_80 ;
* V_77 = & V_74 -> V_79 ;
} else if ( V_74 -> V_79 . V_82 == 4 ) {
* V_76 = & V_74 -> V_79 ;
* V_77 = & V_74 -> V_80 ;
} else if ( V_74 -> V_80 . V_82 == 2 ) {
* V_76 = & V_74 -> V_80 ;
* V_77 = & V_74 -> V_79 ;
} else if ( V_74 -> V_79 . V_82 == 2 ) {
* V_76 = & V_74 -> V_79 ;
* V_77 = & V_74 -> V_80 ;
} else {
* V_76 = & V_74 -> V_80 ;
* V_77 = & V_74 -> V_79 ;
}
}
}
static void F_28 ( struct V_73 * V_74 ,
int V_83 , int V_57 , T_1 V_28 )
{
struct V_19 * V_21 = V_74 -> V_14 -> V_21 ;
T_3 V_52 = V_74 -> V_14 -> V_52 ;
F_18 ( V_83 >= V_54 ) ;
V_21 [ V_83 ] . V_28 = V_28 ;
V_21 [ V_83 ] . V_26 = V_74 -> V_79 . V_84 ;
V_21 [ V_83 ] . V_27 = V_74 -> V_80 . V_84 ;
V_21 [ V_83 ] . V_20 = V_52 + ( V_83 + 1 ) * sizeof( struct V_19 ) ;
if ( V_74 -> V_16 -> V_85 & V_86 )
V_21 [ V_83 ] . V_20 |= V_51 ;
if ( V_28 & V_81 )
V_74 -> V_79 . V_84 += V_57 ;
if ( V_28 & V_78 )
V_74 -> V_80 . V_84 += V_57 ;
F_18 ( V_74 -> V_87 < V_57 ) ;
V_74 -> V_87 -= V_57 ;
}
static inline T_2 F_29 ( T_1 V_84 , T_2 V_57 )
{
T_2 V_88 = V_89 -
( V_84 & ( V_89 - 1 ) ) ;
return F_30 ( V_88 , V_57 ) ;
}
static int F_31 ( struct V_15 * V_16 ,
struct V_4 * V_14 )
{
struct V_75 * V_76 , * V_77 ;
struct V_73 V_74 ;
int V_83 = 0 ;
T_1 V_28 ;
T_2 V_90 ;
T_2 V_91 = 0 ;
struct V_19 * V_21 ;
V_14 -> V_21 = F_32 ( V_16 -> V_92 , V_93 ,
& V_14 -> V_52 ) ;
if ( ! V_14 -> V_21 ) {
F_33 ( & V_16 -> V_23 -> V_24 , L_4 , V_94 ) ;
return 0 ;
}
V_16 -> V_95 ++ ;
V_28 = V_14 -> V_28 ;
V_74 . V_14 = V_14 ;
V_74 . V_16 = V_16 ;
V_74 . V_79 . V_84 = V_14 -> V_96 ;
V_74 . V_80 . V_84 = V_14 -> V_97 ;
V_74 . V_79 . V_98 =
F_24 ( ( V_28 & V_70 ) >>
V_44 ) ;
V_74 . V_80 . V_98 =
F_24 ( ( V_28 & V_69 ) >>
V_71 ) ;
V_74 . V_79 . V_82 = V_74 . V_79 . V_98 ;
V_74 . V_80 . V_82 = V_74 . V_80 . V_98 ;
F_8 ( & V_16 -> V_23 -> V_24 ,
L_5 ,
V_94 , V_74 . V_79 . V_82 , V_74 . V_80 . V_82 ) ;
V_90 = F_30 ( V_74 . V_79 . V_82 , V_74 . V_80 . V_82 ) *
V_43 ;
F_8 ( & V_16 -> V_23 -> V_24 ,
L_6 ,
V_94 , V_90 ) ;
V_74 . V_87 = V_14 -> V_57 ;
F_8 ( & V_16 -> V_23 -> V_24 ,
L_7 ,
V_94 , V_74 . V_87 ) ;
F_27 ( & V_74 , & V_76 , & V_77 , V_28 ) ;
if ( V_14 -> V_57 < V_76 -> V_82 ) {
while ( V_74 . V_87 ) {
F_8 ( & V_16 -> V_23 -> V_24 ,
L_8
L_9 ,
V_94 , V_74 . V_87 ) ;
V_28 = F_26 ( V_28 , 1 , 1 , 1 ) ;
F_28 ( & V_74 , V_83 ++ , 1 , V_28 ) ;
V_91 ++ ;
}
} else {
while ( ( V_76 -> V_84 ) % ( V_76 -> V_82 ) ) {
F_8 ( & V_16 -> V_23 -> V_24 ,
L_10
L_11 ,
V_94 , V_74 . V_87 ) ;
V_28 = F_26 ( V_28 , 1 , 1 , 1 ) ;
F_28 ( & V_74 , V_83 ++ , 1 , V_28 ) ;
V_91 ++ ;
}
if ( V_77 -> V_84 % V_77 -> V_82 ) {
F_34 ( & V_16 -> V_23 -> V_24 ,
L_12 ,
V_94 ) ;
V_77 -> V_82 = 1 ;
}
while ( V_74 . V_87 > ( V_76 -> V_82 - 1 ) ) {
T_2 V_99 , V_100 , V_67 , V_101 ;
V_100 = F_30 ( V_74 . V_87 , V_90 ) ;
if ( V_28 & V_81 )
V_74 . V_79 . V_102 =
F_29 ( V_74 . V_79 . V_84 ,
V_100 ) ;
else
V_74 . V_79 . V_102 = V_100 ;
if ( V_28 & V_78 )
V_74 . V_80 . V_102 =
F_29 ( V_74 . V_80 . V_84 ,
V_100 ) ;
else
V_74 . V_80 . V_102 = V_100 ;
V_99 = F_30 ( V_74 . V_79 . V_102 ,
V_74 . V_80 . V_102 ) ;
F_18 ( V_99 > V_74 . V_87 ) ;
if ( V_99 <= 0 ) {
F_33 ( & V_16 -> V_23 -> V_24 ,
L_13 ,
V_94 , V_99 ) ;
return 0 ;
}
if ( V_99 == V_100 ) {
V_99 = ( V_99 / V_76 -> V_82 ) *
V_76 -> V_82 ;
V_101 = 0 ;
} else {
V_101 = V_99 % V_76 -> V_82 ;
V_99 -= V_101 ;
}
if ( V_99 ) {
V_67 = V_99 / F_30 ( V_76 -> V_82 ,
V_77 -> V_82 ) ;
V_99 = V_67 * F_30 ( V_76 -> V_82 ,
V_77 -> V_82 ) ;
if ( V_100 != V_99 ) {
F_8 ( & V_16 -> V_23 -> V_24 ,
L_14 ,
V_94 , V_100 , V_99 , V_14 -> V_57 ) ;
}
V_28 = F_26 ( V_28 ,
V_74 . V_79 . V_82 ,
V_74 . V_80 . V_82 ,
V_67 ) ;
F_8 ( & V_16 -> V_23 -> V_24 ,
L_15 ,
V_94 , V_99 , V_74 . V_87 ) ;
F_28 ( & V_74 , V_83 ++ ,
V_99 , V_28 ) ;
V_91 += V_99 ;
}
if ( V_101 ) {
int V_103 ;
for ( V_103 = 0 ; ( V_103 < V_76 -> V_82 )
&& ( V_74 . V_87 ) ; V_103 ++ ) {
V_28 = F_26 ( V_28 , 1 , 1 , 1 ) ;
F_8 ( & V_16 -> V_23 -> V_24 ,
L_16 ,
V_94 , V_74 . V_87 ) ;
F_28 ( & V_74 ,
V_83 ++ , 1 , V_28 ) ;
V_91 ++ ;
}
}
}
while ( V_74 . V_87 ) {
V_28 = F_26 ( V_28 , 1 , 1 , 1 ) ;
F_8 ( & V_16 -> V_23 -> V_24 ,
L_17 ,
V_94 , V_74 . V_87 ) ;
F_28 ( & V_74 , V_83 ++ , 1 , V_28 ) ;
V_91 ++ ;
}
}
if ( V_91 != V_14 -> V_57 ) {
F_33 ( & V_16 -> V_23 -> V_24 ,
L_18 ,
V_94 , V_91 , V_14 -> V_57 ) ;
return 0 ;
}
if ( V_83 >= V_54 ) {
F_33 ( & V_16 -> V_23 -> V_24 ,
L_19 ,
V_94 , ( T_1 ) V_54 ) ;
return 0 ;
}
V_21 = V_14 -> V_21 ;
V_21 [ V_83 - 1 ] . V_20 = 0 ;
V_21 [ V_83 - 1 ] . V_28 |= V_104 ;
#ifdef F_35
{
int V_59 ;
for ( V_59 = 0 ; V_59 < V_83 ; V_59 ++ ) {
F_8 ( & V_16 -> V_23 -> V_24 ,
L_20 ,
V_59 ,
& V_21 [ V_59 ] ,
V_21 [ V_59 ] . V_26 ,
V_21 [ V_59 ] . V_27 ,
V_21 [ V_59 ] . V_28 ,
V_21 [ V_59 ] . V_20
) ;
}
}
#endif
return V_83 ;
}
static void F_36 ( struct V_15 * V_16 ,
struct V_4 * V_14 )
{
F_37 ( V_16 -> V_92 , V_14 -> V_21 , V_14 -> V_52 ) ;
V_16 -> V_95 -- ;
F_38 ( V_14 ) ;
}
static void F_39 ( struct V_15 * V_16 ,
struct V_1 * V_13 )
{
struct V_4 * V_56 = NULL ;
struct V_4 * V_105 ;
if ( ! F_19 ( & V_13 -> V_55 ) ) {
F_40 (txdi,
next, &plchan->pend_list, node) {
F_41 ( & V_56 -> V_106 ) ;
F_36 ( V_16 , V_56 ) ;
}
}
}
static int F_42 ( struct V_2 * V_3 )
{
return 0 ;
}
static void F_43 ( struct V_2 * V_3 )
{
}
static int F_44 ( struct V_1 * V_13 ,
struct V_4 * V_14 )
{
struct V_15 * V_16 = V_13 -> V_17 ;
struct V_7 * V_8 ;
int V_107 ;
if ( V_13 -> V_18 )
return 0 ;
V_8 = F_22 ( V_16 , V_13 ) ;
if ( ! V_8 ) {
F_34 ( & V_16 -> V_23 -> V_24 , L_21 , V_13 -> V_108 ) ;
return - V_109 ;
}
if ( V_13 -> V_110 &&
V_8 -> signal < 0 &&
V_16 -> V_111 -> V_112 ) {
V_107 = V_16 -> V_111 -> V_112 ( V_13 ) ;
if ( V_107 < 0 ) {
F_34 ( & V_16 -> V_23 -> V_24 ,
L_22 ,
V_8 -> V_25 , V_13 -> V_108 ) ;
F_23 ( V_16 , V_8 ) ;
return - V_109 ;
}
V_8 -> signal = V_107 ;
if ( V_14 -> V_113 == V_114 )
V_14 -> V_29 |= V_8 -> signal << V_115 ;
else if ( V_14 -> V_113 == V_116 )
V_14 -> V_29 |= V_8 -> signal << V_117 ;
}
F_34 ( & V_16 -> V_23 -> V_24 , L_23 ,
V_8 -> V_25 ,
V_8 -> signal ,
V_13 -> V_108 ) ;
V_13 -> V_118 ++ ;
V_13 -> V_18 = V_8 ;
return 0 ;
}
static void F_45 ( struct V_1 * V_13 )
{
struct V_15 * V_16 = V_13 -> V_17 ;
if ( ( V_13 -> V_18 -> signal >= 0 ) && V_16 -> V_111 -> V_119 ) {
V_16 -> V_111 -> V_119 ( V_13 ) ;
V_13 -> V_18 -> signal = - 1 ;
}
F_23 ( V_16 , V_13 -> V_18 ) ;
V_13 -> V_18 = NULL ;
}
static T_5 F_46 ( struct V_5 * V_6 )
{
struct V_1 * V_13 = F_1 ( V_6 -> V_3 ) ;
struct V_4 * V_14 = F_3 ( V_6 ) ;
unsigned long V_48 ;
F_17 ( & V_13 -> V_49 , V_48 ) ;
V_13 -> V_3 . V_120 += 1 ;
if ( V_13 -> V_3 . V_120 < 0 )
V_13 -> V_3 . V_120 = 1 ;
V_6 -> V_120 = V_13 -> V_3 . V_120 ;
F_47 ( & V_14 -> V_106 , & V_13 -> V_55 ) ;
if ( ! V_13 -> V_110 && ! V_13 -> V_18 ) {
V_13 -> V_121 = V_122 ;
V_13 -> V_123 = V_14 ;
} else {
V_13 -> V_118 -- ;
}
F_21 ( & V_13 -> V_49 , V_48 ) ;
return V_6 -> V_120 ;
}
static struct V_5 * F_48 (
struct V_2 * V_3 , unsigned long V_48 )
{
struct V_5 * V_124 = NULL ;
return V_124 ;
}
static enum V_125
F_49 ( struct V_2 * V_3 ,
T_5 V_120 ,
struct V_126 * V_127 )
{
struct V_1 * V_13 = F_1 ( V_3 ) ;
T_5 V_128 ;
T_5 V_129 ;
enum V_125 V_107 ;
T_1 V_130 = 0 ;
V_128 = V_13 -> V_3 . V_120 ;
V_129 = V_13 -> V_131 ;
V_107 = F_50 ( V_120 , V_129 , V_128 ) ;
if ( V_107 == V_132 ) {
F_51 ( V_127 , V_129 , V_128 , 0 ) ;
return V_107 ;
}
V_128 = V_13 -> V_3 . V_120 ;
V_129 = V_13 -> V_131 ;
V_130 = F_16 ( V_13 ) ;
F_51 ( V_127 , V_129 , V_128 ,
V_130 ) ;
if ( V_13 -> V_121 == V_133 )
return V_134 ;
return V_135 ;
}
static int F_52 ( struct V_2 * V_3 ,
struct V_136 * V_137 )
{
struct V_1 * V_13 = F_1 ( V_3 ) ;
struct V_15 * V_16 = V_13 -> V_17 ;
struct V_138 * V_139 = V_13 -> V_139 ;
enum V_140 V_141 ;
T_3 V_84 ;
T_1 V_142 ;
T_1 V_28 = 0 ;
int V_59 ;
if ( ! V_13 -> V_110 )
return - V_143 ;
V_13 -> V_144 = V_137 -> V_113 ;
if ( V_137 -> V_113 == V_114 ) {
V_84 = V_137 -> V_97 ;
V_141 = V_137 -> V_145 ;
V_142 = V_137 -> V_146 ;
} else if ( V_137 -> V_113 == V_116 ) {
V_84 = V_137 -> V_96 ;
V_141 = V_137 -> V_147 ;
V_142 = V_137 -> V_148 ;
} else {
F_33 ( & V_16 -> V_23 -> V_24 ,
L_24 ) ;
return - V_143 ;
}
switch ( V_141 ) {
case V_149 :
V_28 |= ( V_45 << V_44 ) |
( V_45 << V_71 ) ;
break;
case V_150 :
V_28 |= ( V_46 << V_44 ) |
( V_46 << V_71 ) ;
break;
case V_151 :
V_28 |= ( V_47 << V_44 ) |
( V_47 << V_71 ) ;
break;
default:
F_33 ( & V_16 -> V_23 -> V_24 ,
L_25 ) ;
return - V_143 ;
}
if ( V_13 -> V_139 -> V_152 || V_142 == 0 ) {
V_28 |= ( V_153 << V_154 ) |
( V_153 << V_155 ) ;
} else {
for ( V_59 = 0 ; V_59 < F_53 ( V_156 ) ; V_59 ++ )
if ( V_156 [ V_59 ] . V_157 <= V_142 )
break;
V_28 |= V_156 [ V_59 ] . V_158 ;
}
V_13 -> V_159 = V_84 ;
V_139 -> V_28 = V_28 ;
F_34 ( & V_16 -> V_23 -> V_24 ,
L_26
L_27 ,
F_54 ( V_3 ) , V_13 -> V_108 ,
( V_137 -> V_113 == V_116 ) ? L_28 : L_29 ,
V_141 ,
V_142 ,
V_28 ) ;
return 0 ;
}
static void F_55 ( struct V_2 * V_3 )
{
struct V_1 * V_13 = F_1 ( V_3 ) ;
unsigned long V_48 ;
F_17 ( & V_13 -> V_49 , V_48 ) ;
if ( V_13 -> V_22 || V_13 -> V_121 == V_122 ) {
F_21 ( & V_13 -> V_49 , V_48 ) ;
return;
}
if ( ! F_19 ( & V_13 -> V_55 ) ) {
struct V_4 * V_105 ;
V_105 = F_56 ( & V_13 -> V_55 ,
struct V_4 ,
V_106 ) ;
F_41 ( & V_105 -> V_106 ) ;
V_13 -> V_121 = V_160 ;
F_6 ( V_13 , V_105 ) ;
}
F_21 ( & V_13 -> V_49 , V_48 ) ;
}
static int F_57 ( struct V_1 * V_13 ,
struct V_4 * V_14 )
{
struct V_15 * V_16 = V_13 -> V_17 ;
unsigned long V_48 ;
int V_83 , V_107 ;
V_83 = F_31 ( V_16 , V_14 ) ;
if ( ! V_83 ) {
F_38 ( V_14 ) ;
return - V_143 ;
}
F_17 ( & V_13 -> V_49 , V_48 ) ;
V_107 = F_44 ( V_13 , V_14 ) ;
if ( V_107 ) {
if ( V_13 -> V_110 ) {
F_39 ( V_16 , V_13 ) ;
F_36 ( V_16 , V_14 ) ;
F_21 ( & V_13 -> V_49 , V_48 ) ;
return - V_109 ;
}
} else
if ( V_13 -> V_121 == V_161 )
V_13 -> V_121 = V_133 ;
F_21 ( & V_13 -> V_49 , V_48 ) ;
return 0 ;
}
static T_1 F_58 ( struct V_15 * V_16 , T_4 V_26 , T_4 V_27 )
{
T_1 V_28 = 0 ;
if ( ! ( V_27 & V_162 ) || ( ( V_27 & V_86 ) && ( V_26 & V_162 ) ) )
V_28 |= V_163 ;
if ( ! ( V_26 & V_162 ) || ( ( V_26 & V_86 ) && ! ( V_27 & V_86 ) ) )
V_28 |= V_164 ;
return V_28 ;
}
static struct V_4 * F_59 ( struct V_1 * V_13 ,
unsigned long V_48 )
{
struct V_4 * V_14 = F_60 ( sizeof( struct V_4 ) , V_93 ) ;
if ( V_14 ) {
F_61 ( & V_14 -> V_6 , & V_13 -> V_3 ) ;
V_14 -> V_6 . V_48 = V_48 ;
V_14 -> V_6 . V_165 = F_46 ;
F_62 ( & V_14 -> V_106 ) ;
V_14 -> V_29 = V_38 |
V_39 ;
}
return V_14 ;
}
static struct V_5 * F_63 (
struct V_2 * V_3 , T_3 V_166 , T_3 V_26 ,
T_2 V_57 , unsigned long V_48 )
{
struct V_1 * V_13 = F_1 ( V_3 ) ;
struct V_15 * V_16 = V_13 -> V_17 ;
struct V_4 * V_14 ;
int V_107 ;
V_14 = F_59 ( V_13 , V_48 ) ;
if ( ! V_14 ) {
F_33 ( & V_16 -> V_23 -> V_24 ,
L_30 , V_94 ) ;
return NULL ;
}
V_14 -> V_113 = V_167 ;
V_14 -> V_96 = V_26 ;
V_14 -> V_97 = V_166 ;
V_14 -> V_57 = V_57 ;
V_14 -> V_29 |= V_168 << V_169 ;
V_14 -> V_28 = V_16 -> V_111 -> V_170 . V_28 &
~ ( V_163 | V_164 ) ;
V_14 -> V_28 |= V_81 | V_78 ;
if ( V_16 -> V_60 -> V_171 )
V_14 -> V_28 |= F_58 ( V_16 ,
V_16 -> V_172 , V_16 -> V_172 ) ;
V_107 = F_57 ( V_13 , V_14 ) ;
if ( V_107 )
return NULL ;
return & V_14 -> V_6 ;
}
static struct V_5 * F_64 (
struct V_2 * V_3 , struct V_173 * V_174 ,
unsigned int V_175 , enum V_176 V_113 ,
unsigned long V_48 )
{
struct V_1 * V_13 = F_1 ( V_3 ) ;
struct V_15 * V_16 = V_13 -> V_17 ;
struct V_4 * V_14 ;
T_4 V_177 , V_178 ;
int V_107 ;
if ( V_175 != 1 ) {
F_33 ( & V_16 -> V_23 -> V_24 , L_31 ,
V_94 ) ;
F_25 () ;
}
F_34 ( & V_16 -> V_23 -> V_24 , L_32 ,
V_94 , V_174 -> V_179 , V_13 -> V_108 ) ;
V_14 = F_59 ( V_13 , V_48 ) ;
if ( ! V_14 ) {
F_33 ( & V_16 -> V_23 -> V_24 , L_33 , V_94 ) ;
return NULL ;
}
if ( V_113 != V_13 -> V_144 )
F_33 ( & V_16 -> V_23 -> V_24 , L_34
L_35 ,
V_94 ) ;
V_14 -> V_113 = V_113 ;
V_14 -> V_57 = V_174 -> V_179 ;
V_14 -> V_28 = V_13 -> V_139 -> V_28 &
~ ( V_164 | V_163 |
V_81 | V_78 |
V_180 ) ;
V_14 -> V_28 |= V_181 ;
if ( V_113 == V_114 ) {
V_14 -> V_29 |= V_182 << V_169 ;
V_14 -> V_28 |= V_81 ;
V_14 -> V_96 = V_174 -> V_183 ;
if ( V_13 -> V_159 )
V_14 -> V_97 = V_13 -> V_159 ;
else
V_14 -> V_97 = V_13 -> V_139 -> V_84 ;
V_177 = V_16 -> V_172 ;
V_178 = V_13 -> V_139 -> V_184 ;
} else if ( V_113 == V_116 ) {
V_14 -> V_29 |= V_185 << V_169 ;
V_14 -> V_28 |= V_78 ;
if ( V_13 -> V_159 )
V_14 -> V_96 = V_13 -> V_159 ;
else
V_14 -> V_96 = V_13 -> V_139 -> V_84 ;
V_14 -> V_97 = V_174 -> V_183 ;
V_177 = V_13 -> V_139 -> V_184 ;
V_178 = V_16 -> V_172 ;
} else {
F_33 ( & V_16 -> V_23 -> V_24 ,
L_36 , V_94 ) ;
return NULL ;
}
V_14 -> V_28 |= F_58 ( V_16 , V_177 , V_178 ) ;
V_107 = F_57 ( V_13 , V_14 ) ;
if ( V_107 )
return NULL ;
return & V_14 -> V_6 ;
}
static int F_65 ( struct V_2 * V_3 , enum V_186 V_187 ,
unsigned long V_188 )
{
struct V_1 * V_13 = F_1 ( V_3 ) ;
struct V_15 * V_16 = V_13 -> V_17 ;
unsigned long V_48 ;
int V_107 = 0 ;
if ( V_187 == V_189 ) {
return F_52 ( V_3 ,
(struct V_136 * ) V_188 ) ;
}
F_17 ( & V_13 -> V_49 , V_48 ) ;
if ( ! V_13 -> V_18 && ! V_13 -> V_22 ) {
F_21 ( & V_13 -> V_49 , V_48 ) ;
return 0 ;
}
switch ( V_187 ) {
case V_190 :
V_13 -> V_121 = V_161 ;
if ( V_13 -> V_18 ) {
F_14 ( V_16 , V_13 -> V_18 ) ;
F_45 ( V_13 ) ;
}
if ( V_13 -> V_22 ) {
F_36 ( V_16 , V_13 -> V_22 ) ;
V_13 -> V_22 = NULL ;
}
F_39 ( V_16 , V_13 ) ;
break;
case V_191 :
F_10 ( V_13 -> V_18 ) ;
V_13 -> V_121 = V_133 ;
break;
case V_192 :
F_13 ( V_13 -> V_18 ) ;
V_13 -> V_121 = V_160 ;
break;
default:
V_107 = - V_193 ;
break;
}
F_21 ( & V_13 -> V_49 , V_48 ) ;
return V_107 ;
}
bool F_66 ( struct V_2 * V_3 , void * V_194 )
{
struct V_1 * V_13 = F_1 ( V_3 ) ;
char * V_108 = V_194 ;
if ( ! strcmp ( V_13 -> V_108 , V_108 ) )
return true ;
return false ;
}
static void F_67 ( struct V_15 * V_16 )
{
T_1 V_9 ;
V_9 = F_5 ( V_16 -> V_10 + V_195 ) ;
V_9 &= ~ ( V_196 | V_197 | V_35 ) ;
V_9 |= V_35 ;
F_9 ( V_9 , V_16 -> V_10 + V_195 ) ;
}
static void F_68 ( struct V_4 * V_14 )
{
struct V_198 * V_24 = V_14 -> V_6 . V_3 -> V_198 -> V_24 ;
if ( ! ( V_14 -> V_6 . V_48 & V_199 ) ) {
if ( V_14 -> V_6 . V_48 & V_200 )
F_69 ( V_24 , V_14 -> V_96 , V_14 -> V_57 ,
V_114 ) ;
else
F_70 ( V_24 , V_14 -> V_96 , V_14 -> V_57 ,
V_114 ) ;
}
if ( ! ( V_14 -> V_6 . V_48 & V_201 ) ) {
if ( V_14 -> V_6 . V_48 & V_202 )
F_69 ( V_24 , V_14 -> V_97 , V_14 -> V_57 ,
V_116 ) ;
else
F_70 ( V_24 , V_14 -> V_97 , V_14 -> V_57 ,
V_116 ) ;
}
}
static void F_71 ( unsigned long V_203 )
{
struct V_1 * V_13 = (struct V_1 * ) V_203 ;
struct V_15 * V_16 = V_13 -> V_17 ;
struct V_4 * V_14 ;
unsigned long V_48 ;
F_17 ( & V_13 -> V_49 , V_48 ) ;
V_14 = V_13 -> V_22 ;
V_13 -> V_22 = NULL ;
if ( V_14 ) {
V_13 -> V_131 = V_14 -> V_6 . V_120 ;
}
if ( ! F_19 ( & V_13 -> V_55 ) ) {
struct V_4 * V_105 ;
V_105 = F_56 ( & V_13 -> V_55 ,
struct V_4 ,
V_106 ) ;
F_41 ( & V_105 -> V_106 ) ;
F_6 ( V_13 , V_105 ) ;
} else if ( V_13 -> V_118 ) {
} else {
struct V_1 * V_123 = NULL ;
F_45 ( V_13 ) ;
V_13 -> V_121 = V_161 ;
F_20 (waiting, &pl08x->memcpy.channels,
chan.device_node) {
if ( V_123 -> V_121 == V_122 &&
V_123 -> V_123 != NULL ) {
int V_107 ;
V_107 = F_44 ( V_123 ,
V_123 -> V_123 ) ;
F_18 ( V_107 ) ;
V_123 -> V_118 -- ;
V_123 -> V_121 = V_160 ;
V_123 -> V_123 = NULL ;
F_55 ( & V_123 -> V_3 ) ;
break;
}
}
}
F_21 ( & V_13 -> V_49 , V_48 ) ;
if ( V_14 ) {
T_6 V_204 = V_14 -> V_6 . V_204 ;
void * V_205 = V_14 -> V_6 . V_205 ;
if ( ! V_13 -> V_110 )
F_68 ( V_14 ) ;
F_17 ( & V_13 -> V_49 , V_48 ) ;
F_36 ( V_16 , V_14 ) ;
F_21 ( & V_13 -> V_49 , V_48 ) ;
if ( V_204 )
V_204 ( V_205 ) ;
}
}
static T_7 F_72 ( int V_206 , void * V_24 )
{
struct V_15 * V_16 = V_24 ;
T_1 V_207 = 0 ;
T_1 V_9 ;
int V_59 ;
V_9 = F_5 ( V_16 -> V_10 + V_208 ) ;
if ( V_9 ) {
F_33 ( & V_16 -> V_23 -> V_24 ,
L_37 ,
V_94 , V_9 ) ;
F_9 ( 0x000000FF , V_16 -> V_10 + V_40 ) ;
}
V_9 = F_5 ( V_16 -> V_10 + V_209 ) ;
for ( V_59 = 0 ; V_59 < V_16 -> V_60 -> V_61 ; V_59 ++ ) {
if ( ( 1 << V_59 ) & V_9 ) {
struct V_7 * V_18 = & V_16 -> V_62 [ V_59 ] ;
struct V_1 * V_13 = V_18 -> V_63 ;
F_73 ( & V_13 -> V_210 ) ;
V_207 |= ( 1 << V_59 ) ;
}
}
F_9 ( V_207 , V_16 -> V_10 + V_41 ) ;
return V_207 ? V_211 : V_212 ;
}
static int F_74 ( struct V_15 * V_16 ,
struct V_213 * V_214 ,
unsigned int V_61 ,
bool V_110 )
{
struct V_1 * V_3 ;
int V_59 ;
F_62 ( & V_214 -> V_61 ) ;
for ( V_59 = 0 ; V_59 < V_61 ; V_59 ++ ) {
V_3 = F_60 ( sizeof( struct V_1 ) , V_215 ) ;
if ( ! V_3 ) {
F_33 ( & V_16 -> V_23 -> V_24 ,
L_38 , V_94 ) ;
return - V_216 ;
}
V_3 -> V_17 = V_16 ;
V_3 -> V_121 = V_161 ;
if ( V_110 ) {
V_3 -> V_110 = true ;
V_3 -> V_108 = V_16 -> V_111 -> V_217 [ V_59 ] . V_218 ;
V_3 -> V_139 = & V_16 -> V_111 -> V_217 [ V_59 ] ;
} else {
V_3 -> V_139 = & V_16 -> V_111 -> V_170 ;
V_3 -> V_108 = F_75 ( V_215 , L_39 , V_59 ) ;
if ( ! V_3 -> V_108 ) {
F_38 ( V_3 ) ;
return - V_216 ;
}
}
if ( V_3 -> V_139 -> V_219 ) {
F_33 ( & V_16 -> V_23 -> V_24 ,
L_40 ,
V_3 -> V_108 ) ;
F_38 ( V_3 ) ;
continue;
}
F_76 ( & V_16 -> V_23 -> V_24 ,
L_41 ,
V_3 -> V_108 ) ;
V_3 -> V_3 . V_198 = V_214 ;
V_3 -> V_3 . V_120 = 0 ;
V_3 -> V_131 = 0 ;
F_77 ( & V_3 -> V_49 ) ;
F_62 ( & V_3 -> V_55 ) ;
F_78 ( & V_3 -> V_210 , F_71 ,
( unsigned long ) V_3 ) ;
F_47 ( & V_3 -> V_3 . V_220 , & V_214 -> V_61 ) ;
}
F_76 ( & V_16 -> V_23 -> V_24 , L_42 ,
V_59 , V_110 ? L_43 : L_44 ) ;
return V_59 ;
}
static void F_79 ( struct V_213 * V_214 )
{
struct V_1 * V_3 = NULL ;
struct V_1 * V_105 ;
F_40 (chan,
next, &dmadev->channels, chan.device_node) {
F_41 ( & V_3 -> V_3 . V_220 ) ;
F_38 ( V_3 ) ;
}
}
static const char * F_80 ( enum V_221 V_121 )
{
switch ( V_121 ) {
case V_161 :
return L_45 ;
case V_160 :
return L_46 ;
case V_133 :
return L_47 ;
case V_122 :
return L_48 ;
default:
break;
}
return L_49 ;
}
static int F_81 ( struct V_222 * V_223 , void * V_203 )
{
struct V_15 * V_16 = V_223 -> V_224 ;
struct V_1 * V_3 ;
struct V_7 * V_8 ;
unsigned long V_48 ;
int V_59 ;
F_82 ( V_223 , L_50 ) ;
F_82 ( V_223 , L_51 ) ;
F_82 ( V_223 , L_52 ) ;
for ( V_59 = 0 ; V_59 < V_16 -> V_60 -> V_61 ; V_59 ++ ) {
struct V_1 * V_58 ;
V_8 = & V_16 -> V_62 [ V_59 ] ;
F_17 ( & V_8 -> V_49 , V_48 ) ;
V_58 = V_8 -> V_63 ;
F_82 ( V_223 , L_53 ,
V_8 -> V_25 , V_58 ? V_58 -> V_108 : L_54 ) ;
F_21 ( & V_8 -> V_49 , V_48 ) ;
}
F_82 ( V_223 , L_55 ) ;
F_82 ( V_223 , L_56 ) ;
F_82 ( V_223 , L_57 ) ;
F_20 (chan, &pl08x->memcpy.channels, chan.device_node) {
F_82 ( V_223 , L_58 , V_3 -> V_108 ,
F_80 ( V_3 -> V_121 ) ) ;
}
F_82 ( V_223 , L_59 ) ;
F_82 ( V_223 , L_56 ) ;
F_82 ( V_223 , L_57 ) ;
F_20 (chan, &pl08x->slave.channels, chan.device_node) {
F_82 ( V_223 , L_58 , V_3 -> V_108 ,
F_80 ( V_3 -> V_121 ) ) ;
}
return 0 ;
}
static int F_83 ( struct V_225 * V_225 , struct V_226 * V_226 )
{
return F_84 ( V_226 , F_81 , V_225 -> V_227 ) ;
}
static void F_85 ( struct V_15 * V_16 )
{
( void ) F_86 ( F_87 ( & V_16 -> V_23 -> V_24 ) , V_228 | V_229 ,
NULL , V_16 ,
& V_230 ) ;
}
static inline void F_85 ( struct V_15 * V_16 )
{
}
static int F_88 ( struct V_231 * V_23 , const struct V_232 * V_25 )
{
struct V_15 * V_16 ;
const struct V_233 * V_60 = V_25 -> V_203 ;
int V_107 = 0 ;
int V_59 ;
V_107 = F_89 ( V_23 , NULL ) ;
if ( V_107 )
return V_107 ;
V_16 = F_60 ( sizeof( struct V_15 ) , V_215 ) ;
if ( ! V_16 ) {
V_107 = - V_216 ;
goto V_234;
}
F_90 ( V_235 , V_16 -> memcpy . V_236 ) ;
V_16 -> memcpy . V_24 = & V_23 -> V_24 ;
V_16 -> memcpy . V_237 = F_42 ;
V_16 -> memcpy . V_238 = F_43 ;
V_16 -> memcpy . V_239 = F_63 ;
V_16 -> memcpy . V_240 = F_48 ;
V_16 -> memcpy . V_241 = F_49 ;
V_16 -> memcpy . V_242 = F_55 ;
V_16 -> memcpy . V_243 = F_65 ;
F_90 ( V_244 , V_16 -> V_110 . V_236 ) ;
V_16 -> V_110 . V_24 = & V_23 -> V_24 ;
V_16 -> V_110 . V_237 = F_42 ;
V_16 -> V_110 . V_238 = F_43 ;
V_16 -> V_110 . V_240 = F_48 ;
V_16 -> V_110 . V_241 = F_49 ;
V_16 -> V_110 . V_242 = F_55 ;
V_16 -> V_110 . V_245 = F_64 ;
V_16 -> V_110 . V_243 = F_65 ;
V_16 -> V_111 = F_91 ( & V_23 -> V_24 ) ;
if ( ! V_16 -> V_111 ) {
F_33 ( & V_23 -> V_24 , L_60 ) ;
goto V_246;
}
V_16 -> V_23 = V_23 ;
V_16 -> V_60 = V_60 ;
V_16 -> V_85 = V_162 ;
V_16 -> V_172 = V_162 ;
if ( V_16 -> V_60 -> V_171 ) {
V_16 -> V_85 = V_16 -> V_111 -> V_85 ;
V_16 -> V_172 = V_16 -> V_111 -> V_172 ;
}
V_16 -> V_92 = F_92 ( V_247 , & V_16 -> V_23 -> V_24 ,
V_248 , V_249 , 0 ) ;
if ( ! V_16 -> V_92 ) {
V_107 = - V_216 ;
goto V_250;
}
F_77 ( & V_16 -> V_49 ) ;
V_16 -> V_10 = F_93 ( V_23 -> V_251 . V_252 , F_94 ( & V_23 -> V_251 ) ) ;
if ( ! V_16 -> V_10 ) {
V_107 = - V_216 ;
goto V_253;
}
F_67 ( V_16 ) ;
F_9 ( 0x000000FF , V_16 -> V_10 + V_40 ) ;
F_9 ( 0x000000FF , V_16 -> V_10 + V_41 ) ;
V_107 = F_95 ( V_23 -> V_206 [ 0 ] , F_72 , V_254 ,
V_247 , V_16 ) ;
if ( V_107 ) {
F_33 ( & V_23 -> V_24 , L_61 ,
V_94 , V_23 -> V_206 [ 0 ] ) ;
goto V_255;
}
V_16 -> V_62 = F_96 ( ( V_60 -> V_61 * sizeof( struct V_7 ) ) ,
V_215 ) ;
if ( ! V_16 -> V_62 ) {
F_33 ( & V_23 -> V_24 , L_62
L_63 ,
V_94 ) ;
goto V_256;
}
for ( V_59 = 0 ; V_59 < V_60 -> V_61 ; V_59 ++ ) {
struct V_7 * V_8 = & V_16 -> V_62 [ V_59 ] ;
V_8 -> V_25 = V_59 ;
V_8 -> V_10 = V_16 -> V_10 + F_97 ( V_59 ) ;
F_77 ( & V_8 -> V_49 ) ;
V_8 -> V_63 = NULL ;
V_8 -> signal = - 1 ;
F_76 ( & V_23 -> V_24 ,
L_64 , V_59 ,
F_4 ( V_8 ) ? L_65 : L_66 ) ;
}
V_107 = F_74 ( V_16 , & V_16 -> memcpy ,
V_16 -> V_60 -> V_61 , false ) ;
if ( V_107 <= 0 ) {
F_98 ( & V_16 -> V_23 -> V_24 ,
L_67 ,
V_94 , V_107 ) ;
goto V_257;
}
V_16 -> memcpy . V_258 = V_107 ;
V_107 = F_74 ( V_16 , & V_16 -> V_110 ,
V_16 -> V_111 -> V_259 ,
true ) ;
if ( V_107 <= 0 ) {
F_98 ( & V_16 -> V_23 -> V_24 ,
L_68 ,
V_94 , V_107 ) ;
goto V_260;
}
V_16 -> V_110 . V_258 = V_107 ;
V_107 = F_99 ( & V_16 -> memcpy ) ;
if ( V_107 ) {
F_98 ( & V_16 -> V_23 -> V_24 ,
L_69 ,
V_94 , V_107 ) ;
goto V_261;
}
V_107 = F_99 ( & V_16 -> V_110 ) ;
if ( V_107 ) {
F_98 ( & V_16 -> V_23 -> V_24 ,
L_70 ,
V_94 , V_107 ) ;
goto V_262;
}
F_100 ( V_23 , V_16 ) ;
F_85 ( V_16 ) ;
F_76 ( & V_16 -> V_23 -> V_24 , L_71 ,
F_101 ( V_23 ) , F_102 ( V_23 ) ,
( unsigned long long ) V_23 -> V_251 . V_252 , V_23 -> V_206 [ 0 ] ) ;
return 0 ;
V_262:
F_103 ( & V_16 -> memcpy ) ;
V_261:
F_79 ( & V_16 -> V_110 ) ;
V_260:
F_79 ( & V_16 -> memcpy ) ;
V_257:
F_38 ( V_16 -> V_62 ) ;
V_256:
F_104 ( V_23 -> V_206 [ 0 ] , V_16 ) ;
V_255:
F_105 ( V_16 -> V_10 ) ;
V_253:
F_106 ( V_16 -> V_92 ) ;
V_250:
V_246:
F_38 ( V_16 ) ;
V_234:
F_107 ( V_23 ) ;
return V_107 ;
}
static int T_8 F_108 ( void )
{
int V_124 ;
V_124 = F_109 ( & V_263 ) ;
if ( V_124 )
F_110 (KERN_WARNING DRIVER_NAME
L_72 ,
retval) ;
return V_124 ;
}
