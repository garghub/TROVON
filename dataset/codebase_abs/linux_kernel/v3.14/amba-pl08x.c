static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_4 . V_3 ) ;
}
static inline struct V_5 * F_3 ( struct V_6 * V_7 )
{
return F_2 ( V_7 , struct V_5 , V_8 . V_7 ) ;
}
static int F_4 ( struct V_1 * V_9 )
{
const struct V_10 * V_11 = V_9 -> V_12 -> V_11 ;
int V_13 ;
if ( V_9 -> V_14 ++ == 0 && V_11 -> V_15 ) {
V_13 = V_11 -> V_15 ( V_9 -> V_16 ) ;
if ( V_13 < 0 ) {
V_9 -> V_14 = 0 ;
return V_13 ;
}
V_9 -> signal = V_13 ;
}
return 0 ;
}
static void F_5 ( struct V_1 * V_9 )
{
const struct V_10 * V_11 = V_9 -> V_12 -> V_11 ;
if ( V_9 -> signal >= 0 ) {
F_6 ( V_9 -> V_14 == 0 ) ;
if ( -- V_9 -> V_14 == 0 && V_11 -> V_17 ) {
V_11 -> V_17 ( V_9 -> V_16 , V_9 -> signal ) ;
V_9 -> signal = - 1 ;
}
}
}
static int F_7 ( struct V_18 * V_19 )
{
unsigned int V_20 ;
V_20 = F_8 ( V_19 -> V_21 ) ;
return V_20 & V_22 ;
}
static void F_9 ( struct V_23 * V_24 ,
struct V_18 * V_25 , const T_1 * V_26 , T_1 V_27 )
{
if ( V_24 -> V_8 -> V_28 )
F_10 ( & V_24 -> V_29 -> V_30 ,
L_1
L_2 ,
V_25 -> V_31 , V_26 [ V_32 ] , V_26 [ V_33 ] ,
V_26 [ V_34 ] , V_26 [ V_35 ] ,
V_26 [ V_36 ] , V_27 ) ;
else
F_10 ( & V_24 -> V_29 -> V_30 ,
L_1
L_3 ,
V_25 -> V_31 , V_26 [ V_32 ] , V_26 [ V_33 ] ,
V_26 [ V_34 ] , V_26 [ V_35 ] , V_27 ) ;
F_11 ( V_26 [ V_32 ] , V_25 -> V_37 + V_38 ) ;
F_11 ( V_26 [ V_33 ] , V_25 -> V_37 + V_39 ) ;
F_11 ( V_26 [ V_34 ] , V_25 -> V_37 + V_40 ) ;
F_11 ( V_26 [ V_35 ] , V_25 -> V_37 + V_41 ) ;
if ( V_24 -> V_8 -> V_28 )
F_11 ( V_26 [ V_36 ] ,
V_25 -> V_37 + V_42 ) ;
F_12 ( V_27 , V_25 -> V_21 ) ;
}
static void F_13 ( struct V_1 * V_9 )
{
struct V_23 * V_24 = V_9 -> V_12 ;
struct V_18 * V_25 = V_9 -> V_25 ;
struct V_43 * V_8 = F_14 ( & V_9 -> V_4 ) ;
struct V_5 * V_44 = F_3 ( & V_8 -> V_7 ) ;
T_1 V_20 ;
F_15 ( & V_44 -> V_8 . V_45 ) ;
V_9 -> V_46 = V_44 ;
while ( F_7 ( V_25 ) )
F_16 () ;
F_9 ( V_24 , V_25 , & V_44 -> V_47 [ 0 ] , V_44 -> V_27 ) ;
while ( F_8 ( V_24 -> V_37 + V_48 ) & ( 1 << V_25 -> V_31 ) )
F_16 () ;
V_20 = F_8 ( V_25 -> V_21 ) ;
while ( ( V_20 & V_22 ) || ( V_20 & V_49 ) )
V_20 = F_8 ( V_25 -> V_21 ) ;
F_12 ( V_20 | V_49 , V_25 -> V_21 ) ;
}
static void F_17 ( struct V_18 * V_19 )
{
T_1 V_20 ;
int V_50 ;
V_20 = F_8 ( V_19 -> V_21 ) ;
V_20 |= V_51 ;
F_12 ( V_20 , V_19 -> V_21 ) ;
for ( V_50 = 1000 ; V_50 ; V_50 -- ) {
if ( ! F_7 ( V_19 ) )
break;
F_18 ( 1 ) ;
}
if ( F_7 ( V_19 ) )
F_19 ( L_4 , V_19 -> V_31 ) ;
}
static void F_20 ( struct V_18 * V_19 )
{
T_1 V_20 ;
V_20 = F_8 ( V_19 -> V_21 ) ;
V_20 &= ~ V_51 ;
F_12 ( V_20 , V_19 -> V_21 ) ;
}
static void F_21 ( struct V_23 * V_24 ,
struct V_18 * V_19 )
{
T_1 V_20 = F_8 ( V_19 -> V_21 ) ;
V_20 &= ~ ( V_49 | V_52 |
V_53 ) ;
F_12 ( V_20 , V_19 -> V_21 ) ;
F_12 ( 1 << V_19 -> V_31 , V_24 -> V_37 + V_54 ) ;
F_12 ( 1 << V_19 -> V_31 , V_24 -> V_37 + V_55 ) ;
}
static inline T_1 F_22 ( T_1 V_56 )
{
T_1 V_57 = V_56 & V_58 ;
V_56 &= V_59 ;
switch ( V_56 >> V_60 ) {
case V_61 :
break;
case V_62 :
V_57 *= 2 ;
break;
case V_63 :
V_57 *= 4 ;
break;
}
return V_57 ;
}
static inline T_1 F_23 ( T_1 V_56 , T_1 V_64 )
{
T_1 V_57 = V_64 & V_65 ;
V_56 &= V_59 ;
switch ( V_56 >> V_60 ) {
case V_61 :
break;
case V_62 :
V_57 *= 2 ;
break;
case V_63 :
V_57 *= 4 ;
break;
}
return V_57 ;
}
static T_1 F_24 ( struct V_1 * V_9 )
{
struct V_23 * V_24 = V_9 -> V_12 ;
const T_1 * V_47 , * V_66 ;
struct V_18 * V_19 ;
T_2 V_67 ;
struct V_5 * V_44 ;
T_1 V_68 ;
T_3 V_57 ;
T_1 V_69 ;
V_19 = V_9 -> V_25 ;
V_44 = V_9 -> V_46 ;
if ( ! V_19 || ! V_44 )
return 0 ;
V_69 = F_8 ( V_19 -> V_37 + V_40 ) & ~ V_70 ;
if ( V_24 -> V_8 -> V_28 )
V_57 = F_23 (
F_8 ( V_19 -> V_37 + V_41 ) ,
F_8 ( V_19 -> V_37 + V_42 ) ) ;
else
V_57 = F_22 ( F_8 ( V_19 -> V_37 + V_41 ) ) ;
if ( ! V_69 )
return V_57 ;
V_47 = V_44 -> V_47 ;
V_67 = V_44 -> V_67 ;
V_68 = V_24 -> V_71 * V_72 ;
F_25 ( V_69 < V_67 || V_69 >= V_67 +
sizeof( T_1 ) * V_68 ) ;
V_47 += ( V_69 - V_67 ) / sizeof( T_1 ) ;
V_66 = V_47 + V_68 ;
for (; V_47 < V_66 ; V_47 += V_24 -> V_71 ) {
if ( V_24 -> V_8 -> V_28 )
V_57 += F_23 (
V_47 [ V_35 ] ,
V_47 [ V_36 ] ) ;
else
V_57 += F_22 ( V_47 [ V_35 ] ) ;
if ( V_47 [ V_34 ] <= V_69 )
break;
}
return V_57 ;
}
static struct V_18 *
F_26 ( struct V_23 * V_24 ,
struct V_1 * V_73 )
{
struct V_18 * V_19 = NULL ;
unsigned long V_74 ;
int V_75 ;
for ( V_75 = 0 ; V_75 < V_24 -> V_8 -> V_76 ; V_75 ++ ) {
V_19 = & V_24 -> V_77 [ V_75 ] ;
F_27 ( & V_19 -> V_78 , V_74 ) ;
if ( ! V_19 -> V_79 && ! V_19 -> V_80 ) {
V_19 -> V_80 = V_73 ;
F_28 ( & V_19 -> V_78 , V_74 ) ;
break;
}
F_28 ( & V_19 -> V_78 , V_74 ) ;
}
if ( V_75 == V_24 -> V_8 -> V_76 ) {
return NULL ;
}
return V_19 ;
}
static inline void F_29 ( struct V_23 * V_24 ,
struct V_18 * V_19 )
{
V_19 -> V_80 = NULL ;
}
static void F_30 ( struct V_1 * V_9 )
{
struct V_23 * V_24 = V_9 -> V_12 ;
struct V_18 * V_19 ;
V_19 = F_26 ( V_24 , V_9 ) ;
if ( ! V_19 ) {
F_31 ( & V_24 -> V_29 -> V_30 , L_5 , V_9 -> V_81 ) ;
V_9 -> V_82 = V_83 ;
return;
}
F_31 ( & V_24 -> V_29 -> V_30 , L_6 ,
V_19 -> V_31 , V_9 -> V_81 ) ;
V_9 -> V_25 = V_19 ;
V_9 -> V_82 = V_84 ;
F_13 ( V_9 ) ;
}
static void F_32 ( struct V_18 * V_19 ,
struct V_1 * V_9 )
{
struct V_23 * V_24 = V_9 -> V_12 ;
F_31 ( & V_24 -> V_29 -> V_30 , L_7 ,
V_19 -> V_31 , V_9 -> V_81 ) ;
V_19 -> V_80 = V_9 ;
V_9 -> V_25 = V_19 ;
V_9 -> V_82 = V_84 ;
F_13 ( V_9 ) ;
}
static void F_33 ( struct V_1 * V_9 )
{
struct V_23 * V_24 = V_9 -> V_12 ;
struct V_1 * V_85 , * V_86 ;
V_87:
V_86 = NULL ;
F_34 (p, &pl08x->memcpy.channels, vc.chan.device_node)
if ( V_85 -> V_82 == V_83 ) {
V_86 = V_85 ;
break;
}
if ( ! V_86 ) {
F_34 (p, &pl08x->slave.channels, vc.chan.device_node)
if ( V_85 -> V_82 == V_83 ) {
V_86 = V_85 ;
break;
}
}
F_21 ( V_24 , V_9 -> V_25 ) ;
if ( V_86 ) {
bool V_88 ;
F_35 ( & V_86 -> V_4 . V_78 ) ;
V_88 = V_86 -> V_82 == V_83 ;
if ( V_88 )
F_32 ( V_9 -> V_25 , V_86 ) ;
F_36 ( & V_86 -> V_4 . V_78 ) ;
if ( ! V_88 )
goto V_87;
} else {
F_29 ( V_24 , V_9 -> V_25 ) ;
}
V_9 -> V_25 = NULL ;
V_9 -> V_82 = V_89 ;
}
static inline unsigned int F_37 ( unsigned int V_90 )
{
switch ( V_90 ) {
case V_61 :
return 1 ;
case V_62 :
return 2 ;
case V_63 :
return 4 ;
default:
break;
}
F_38 () ;
return 0 ;
}
static inline T_1 F_39 ( T_1 V_56 , T_4 V_91 , T_4 V_92 ,
T_3 V_93 )
{
T_1 V_94 = V_56 ;
V_94 &= ~ V_95 ;
V_94 &= ~ V_59 ;
V_94 &= ~ V_58 ;
switch ( V_91 ) {
case 1 :
V_94 |= V_61 << V_60 ;
break;
case 2 :
V_94 |= V_62 << V_60 ;
break;
case 4 :
V_94 |= V_63 << V_60 ;
break;
default:
F_38 () ;
break;
}
switch ( V_92 ) {
case 1 :
V_94 |= V_61 << V_96 ;
break;
case 2 :
V_94 |= V_62 << V_96 ;
break;
case 4 :
V_94 |= V_63 << V_96 ;
break;
default:
F_38 () ;
break;
}
V_93 &= V_58 ;
V_94 |= V_93 << V_97 ;
return V_94 ;
}
static void F_40 ( struct V_98 * V_99 ,
struct V_100 * * V_101 , struct V_100 * * V_102 , T_1 V_56 )
{
if ( ! ( V_56 & V_103 ) ) {
* V_101 = & V_99 -> V_104 ;
* V_102 = & V_99 -> V_105 ;
} else if ( ! ( V_56 & V_106 ) ) {
* V_101 = & V_99 -> V_105 ;
* V_102 = & V_99 -> V_104 ;
} else {
if ( V_99 -> V_104 . V_107 >= V_99 -> V_105 . V_107 ) {
* V_101 = & V_99 -> V_104 ;
* V_102 = & V_99 -> V_105 ;
} else {
* V_101 = & V_99 -> V_105 ;
* V_102 = & V_99 -> V_104 ;
}
}
}
static void F_41 ( struct V_23 * V_24 ,
struct V_98 * V_99 ,
int V_108 , int V_109 , T_1 V_56 , T_1 V_110 )
{
T_1 V_111 = V_108 * V_24 -> V_71 ;
T_1 * V_47 = V_99 -> V_44 -> V_47 + V_111 ;
T_2 V_67 = V_99 -> V_44 -> V_67 ;
F_25 ( V_108 >= V_72 ) ;
V_111 += V_24 -> V_71 ;
V_47 [ V_32 ] = V_99 -> V_105 . V_112 ;
V_47 [ V_33 ] = V_99 -> V_104 . V_112 ;
V_47 [ V_34 ] = ( V_67 + sizeof( T_1 ) * V_111 ) ;
V_47 [ V_34 ] |= V_99 -> V_113 ;
V_47 [ V_35 ] = V_56 ;
if ( V_24 -> V_8 -> V_28 )
V_47 [ V_36 ] = V_110 ;
if ( V_56 & V_106 )
V_99 -> V_105 . V_112 += V_109 ;
if ( V_56 & V_103 )
V_99 -> V_104 . V_112 += V_109 ;
F_25 ( V_99 -> V_114 < V_109 ) ;
V_99 -> V_114 -= V_109 ;
}
static inline void F_42 ( struct V_23 * V_24 ,
struct V_98 * V_99 , T_1 * V_56 , T_1 V_109 ,
int V_108 , T_3 * V_115 )
{
* V_56 = F_39 ( * V_56 , 1 , 1 , V_109 ) ;
F_41 ( V_24 , V_99 , V_108 , V_109 , * V_56 , V_109 ) ;
( * V_115 ) += V_109 ;
}
static void F_43 ( struct V_23 * V_24 ,
const T_1 * V_47 , int V_108 )
{
int V_75 ;
if ( V_24 -> V_8 -> V_28 ) {
F_10 ( & V_24 -> V_29 -> V_30 ,
L_8 ,
L_9 , L_10 , L_11 , L_12 , L_13 , L_14 , L_15 ) ;
for ( V_75 = 0 ; V_75 < V_108 ; V_75 ++ ) {
F_10 ( & V_24 -> V_29 -> V_30 ,
L_16 ,
V_75 , V_47 , V_47 [ V_32 ] ,
V_47 [ V_33 ] , V_47 [ V_34 ] ,
V_47 [ V_35 ] ,
V_47 [ V_36 ] ) ;
V_47 += V_24 -> V_71 ;
}
} else {
F_10 ( & V_24 -> V_29 -> V_30 ,
L_17 ,
L_9 , L_10 , L_11 , L_12 , L_13 , L_14 ) ;
for ( V_75 = 0 ; V_75 < V_108 ; V_75 ++ ) {
F_10 ( & V_24 -> V_29 -> V_30 ,
L_18 ,
V_75 , V_47 , V_47 [ V_32 ] ,
V_47 [ V_33 ] , V_47 [ V_34 ] ,
V_47 [ V_35 ] ) ;
V_47 += V_24 -> V_71 ;
}
}
}
static inline void F_43 ( struct V_23 * V_24 ,
const T_1 * V_47 , int V_108 ) {}
static int F_44 ( struct V_23 * V_24 ,
struct V_5 * V_44 )
{
struct V_100 * V_101 , * V_102 ;
struct V_98 V_99 ;
int V_108 = 0 ;
T_1 V_56 , V_116 = 0 ;
T_3 V_117 , V_115 ;
T_1 * V_47 , * V_118 ;
struct V_119 * V_120 ;
V_44 -> V_47 = F_45 ( V_24 -> V_121 , V_122 , & V_44 -> V_67 ) ;
if ( ! V_44 -> V_47 ) {
F_46 ( & V_24 -> V_29 -> V_30 , L_19 , V_123 ) ;
return 0 ;
}
V_99 . V_44 = V_44 ;
V_99 . V_113 = ( V_24 -> V_124 & V_125 ) ? V_70 : 0 ;
V_56 = V_44 -> V_56 ;
V_99 . V_105 . V_126 =
F_37 ( ( V_56 & V_59 ) >>
V_60 ) ;
V_99 . V_104 . V_126 =
F_37 ( ( V_56 & V_95 ) >>
V_96 ) ;
F_34 (dsg, &txd->dsg_list, node) {
V_115 = 0 ;
V_56 = V_44 -> V_56 ;
V_99 . V_105 . V_112 = V_120 -> V_127 ;
V_99 . V_104 . V_112 = V_120 -> V_128 ;
V_99 . V_114 = V_120 -> V_109 ;
V_99 . V_105 . V_107 = V_99 . V_105 . V_126 ;
V_99 . V_104 . V_107 = V_99 . V_104 . V_126 ;
F_40 ( & V_99 , & V_101 , & V_102 , V_56 ) ;
F_10 ( & V_24 -> V_29 -> V_30 ,
L_20 ,
( V_129 ) V_99 . V_105 . V_112 ,
V_56 & V_106 ? L_21 : L_10 ,
V_99 . V_105 . V_107 ,
( V_129 ) V_99 . V_104 . V_112 ,
V_56 & V_103 ? L_21 : L_10 ,
V_99 . V_104 . V_107 ,
V_99 . V_114 ) ;
F_10 ( & V_24 -> V_29 -> V_30 , L_22 ,
V_101 == & V_99 . V_105 ? L_23 : L_24 ,
V_102 == & V_99 . V_105 ? L_23 : L_24 ) ;
if ( ! V_99 . V_114 ) {
T_1 V_130 = ( V_44 -> V_27 & V_131 ) >>
V_132 ;
if ( ! ( ( V_130 >= V_133 ) &&
( V_130 <= V_134 ) ) ) {
F_46 ( & V_24 -> V_29 -> V_30 , L_25 ,
V_123 ) ;
return 0 ;
}
if ( ! F_47 ( & V_99 . V_105 ) ||
! F_47 ( & V_99 . V_104 ) ) {
F_46 ( & V_24 -> V_29 -> V_30 ,
L_26
L_27 ,
V_123 ) ;
return 0 ;
}
V_56 = F_39 ( V_56 , V_99 . V_105 . V_107 ,
V_99 . V_104 . V_107 , 0 ) ;
F_41 ( V_24 , & V_99 , V_108 ++ ,
0 , V_56 , 0 ) ;
break;
}
if ( V_99 . V_114 < V_101 -> V_107 )
V_116 = V_99 . V_114 ;
else if ( ! F_47 ( V_101 ) ) {
V_116 = V_101 -> V_107 -
( V_101 -> V_112 & ( V_101 -> V_107 - 1 ) ) ;
if ( ( V_99 . V_114 - V_116 ) < V_101 -> V_107 )
V_116 = V_99 . V_114 ;
}
if ( V_116 ) {
F_10 ( & V_24 -> V_29 -> V_30 ,
L_28 ,
V_123 , V_99 . V_114 ) ;
F_42 ( V_24 , & V_99 , & V_56 , V_116 ,
V_108 ++ , & V_115 ) ;
}
if ( V_99 . V_114 ) {
if ( ! F_47 ( V_102 ) ) {
F_31 ( & V_24 -> V_29 -> V_30 ,
L_29 ,
V_123 ) ;
V_102 -> V_107 = 1 ;
}
V_117 = V_99 . V_105 . V_107 *
V_24 -> V_8 -> V_135 ;
F_10 ( & V_24 -> V_29 -> V_30 ,
L_30 ,
V_123 , V_117 ) ;
while ( V_99 . V_114 > ( V_101 -> V_107 - 1 ) ) {
T_3 V_136 , V_93 , V_137 ;
V_136 = F_48 ( V_99 . V_114 , V_117 ) ;
V_137 = F_49 ( V_101 -> V_107 , V_102 -> V_107 ) ;
V_136 = ( V_136 / V_137 ) * V_137 ;
V_93 = V_136 / V_99 . V_105 . V_107 ;
F_10 ( & V_24 -> V_29 -> V_30 ,
L_31
L_32 ,
V_123 , V_136 , V_99 . V_114 ) ;
V_56 = F_39 ( V_56 , V_99 . V_105 . V_107 ,
V_99 . V_104 . V_107 , V_93 ) ;
F_41 ( V_24 , & V_99 , V_108 ++ ,
V_136 , V_56 , V_93 ) ;
V_115 += V_136 ;
}
if ( V_99 . V_114 ) {
F_10 ( & V_24 -> V_29 -> V_30 ,
L_33 ,
V_123 , V_99 . V_114 ) ;
F_42 ( V_24 , & V_99 , & V_56 ,
V_99 . V_114 , V_108 ++ , & V_115 ) ;
}
}
if ( V_115 != V_120 -> V_109 ) {
F_46 ( & V_24 -> V_29 -> V_30 ,
L_34 ,
V_123 , V_115 , V_120 -> V_109 ) ;
return 0 ;
}
if ( V_108 >= V_72 ) {
F_46 ( & V_24 -> V_29 -> V_30 ,
L_35 ,
V_123 , V_72 ) ;
return 0 ;
}
}
V_47 = V_44 -> V_47 ;
V_118 = V_47 + ( V_108 - 1 ) * V_24 -> V_71 ;
if ( V_44 -> V_138 ) {
V_118 [ V_34 ] = V_44 -> V_67 | V_99 . V_113 ;
} else {
V_118 [ V_34 ] = 0 ;
V_118 [ V_35 ] |= V_139 ;
}
F_43 ( V_24 , V_47 , V_108 ) ;
return V_108 ;
}
static void F_50 ( struct V_23 * V_24 ,
struct V_5 * V_44 )
{
struct V_119 * V_120 , * V_140 ;
if ( V_44 -> V_47 )
F_51 ( V_24 -> V_121 , V_44 -> V_47 , V_44 -> V_67 ) ;
F_52 (dsg, _dsg, &txd->dsg_list, node) {
F_15 ( & V_120 -> V_45 ) ;
F_53 ( V_120 ) ;
}
F_53 ( V_44 ) ;
}
static void F_54 ( struct V_43 * V_8 )
{
struct V_5 * V_44 = F_3 ( & V_8 -> V_7 ) ;
struct V_1 * V_9 = F_1 ( V_8 -> V_7 . V_3 ) ;
F_55 ( & V_8 -> V_7 ) ;
if ( ! V_44 -> V_141 )
F_5 ( V_9 ) ;
F_50 ( V_9 -> V_12 , V_44 ) ;
}
static void F_56 ( struct V_23 * V_24 ,
struct V_1 * V_9 )
{
F_57 ( V_142 ) ;
F_58 ( & V_9 -> V_4 , & V_142 ) ;
F_59 ( & V_9 -> V_4 , & V_142 ) ;
}
static int F_60 ( struct V_2 * V_3 )
{
return 0 ;
}
static void F_61 ( struct V_2 * V_3 )
{
F_62 ( F_63 ( V_3 ) ) ;
}
static struct V_6 * F_64 (
struct V_2 * V_3 , unsigned long V_74 )
{
struct V_6 * V_143 = NULL ;
return V_143 ;
}
static enum V_144 F_65 ( struct V_2 * V_3 ,
T_5 V_145 , struct V_146 * V_147 )
{
struct V_1 * V_9 = F_1 ( V_3 ) ;
struct V_43 * V_8 ;
unsigned long V_74 ;
enum V_144 V_13 ;
T_3 V_57 = 0 ;
V_13 = F_66 ( V_3 , V_145 , V_147 ) ;
if ( V_13 == V_148 )
return V_13 ;
if ( ! V_147 ) {
if ( V_9 -> V_82 == V_149 )
V_13 = V_150 ;
return V_13 ;
}
F_27 ( & V_9 -> V_4 . V_78 , V_74 ) ;
V_13 = F_66 ( V_3 , V_145 , V_147 ) ;
if ( V_13 != V_148 ) {
V_8 = F_67 ( & V_9 -> V_4 , V_145 ) ;
if ( V_8 ) {
struct V_5 * V_44 = F_3 ( & V_8 -> V_7 ) ;
struct V_119 * V_120 ;
F_34 (dsg, &txd->dsg_list, node)
V_57 += V_120 -> V_109 ;
} else {
V_57 = F_24 ( V_9 ) ;
}
}
F_28 ( & V_9 -> V_4 . V_78 , V_74 ) ;
F_68 ( V_147 , V_57 ) ;
if ( V_9 -> V_82 == V_149 && V_13 == V_151 )
V_13 = V_150 ;
return V_13 ;
}
static T_1 F_69 ( T_4 V_152 , T_4 V_153 )
{
T_1 V_56 = 0 ;
if ( ! ( V_153 & V_154 ) || ( ( V_153 & V_125 ) && ( V_152 & V_154 ) ) )
V_56 |= V_155 ;
if ( ! ( V_152 & V_154 ) || ( ( V_152 & V_125 ) && ! ( V_153 & V_125 ) ) )
V_56 |= V_156 ;
return V_56 ;
}
static T_1 F_70 ( T_1 V_56 )
{
V_56 &= ~ ( V_156 | V_155 |
V_106 | V_103 |
V_157 ) ;
return V_56 | V_158 ;
}
static T_1 F_71 ( enum V_159 V_137 )
{
switch ( V_137 ) {
case V_160 :
return V_61 ;
case V_161 :
return V_62 ;
case V_162 :
return V_63 ;
default:
return ~ 0 ;
}
}
static T_1 F_72 ( T_1 V_163 )
{
int V_75 ;
for ( V_75 = 0 ; V_75 < F_73 ( V_164 ) ; V_75 ++ )
if ( V_164 [ V_75 ] . V_165 <= V_163 )
break;
return V_164 [ V_75 ] . V_166 ;
}
static T_1 F_74 ( struct V_1 * V_9 ,
enum V_159 V_167 , T_1 V_163 )
{
T_1 V_137 , V_168 , V_56 = 0 ;
V_137 = F_71 ( V_167 ) ;
if ( V_137 == ~ 0 )
return ~ 0 ;
V_56 |= V_137 << V_60 ;
V_56 |= V_137 << V_96 ;
if ( V_9 -> V_16 -> V_169 )
V_163 = 1 ;
V_168 = F_72 ( V_163 ) ;
V_56 |= V_168 << V_170 ;
V_56 |= V_168 << V_171 ;
return F_70 ( V_56 ) ;
}
static int F_75 ( struct V_2 * V_3 ,
struct V_172 * V_173 )
{
struct V_1 * V_9 = F_1 ( V_3 ) ;
struct V_23 * V_24 = V_9 -> V_12 ;
if ( ! V_9 -> V_174 )
return - V_175 ;
if ( V_173 -> V_176 == V_177 ||
V_173 -> V_178 == V_177 )
return - V_175 ;
if ( V_173 -> V_179 && V_24 -> V_8 -> V_28 ) {
F_46 ( & V_24 -> V_29 -> V_30 ,
L_36 ,
V_123 ) ;
return - V_175 ;
}
V_9 -> V_180 = * V_173 ;
return 0 ;
}
static void F_76 ( struct V_2 * V_3 )
{
struct V_1 * V_9 = F_1 ( V_3 ) ;
unsigned long V_74 ;
F_27 ( & V_9 -> V_4 . V_78 , V_74 ) ;
if ( F_77 ( & V_9 -> V_4 ) ) {
if ( ! V_9 -> V_25 && V_9 -> V_82 != V_83 )
F_30 ( V_9 ) ;
}
F_28 ( & V_9 -> V_4 . V_78 , V_74 ) ;
}
static struct V_5 * F_78 ( struct V_1 * V_9 )
{
struct V_5 * V_44 = F_79 ( sizeof( * V_44 ) , V_122 ) ;
if ( V_44 ) {
F_80 ( & V_44 -> V_181 ) ;
V_44 -> V_27 = V_52 |
V_53 ;
}
return V_44 ;
}
static struct V_6 * F_81 (
struct V_2 * V_3 , T_2 V_182 , T_2 V_152 ,
T_3 V_109 , unsigned long V_74 )
{
struct V_1 * V_9 = F_1 ( V_3 ) ;
struct V_23 * V_24 = V_9 -> V_12 ;
struct V_5 * V_44 ;
struct V_119 * V_120 ;
int V_13 ;
V_44 = F_78 ( V_9 ) ;
if ( ! V_44 ) {
F_46 ( & V_24 -> V_29 -> V_30 ,
L_37 , V_123 ) ;
return NULL ;
}
V_120 = F_79 ( sizeof( struct V_119 ) , V_122 ) ;
if ( ! V_120 ) {
F_50 ( V_24 , V_44 ) ;
F_46 ( & V_24 -> V_29 -> V_30 , L_38 ,
V_123 ) ;
return NULL ;
}
F_82 ( & V_120 -> V_45 , & V_44 -> V_181 ) ;
V_120 -> V_127 = V_152 ;
V_120 -> V_128 = V_182 ;
V_120 -> V_109 = V_109 ;
V_44 -> V_27 |= V_183 << V_132 ;
V_44 -> V_56 = V_24 -> V_11 -> V_184 . V_185 &
~ ( V_155 | V_156 ) ;
V_44 -> V_56 |= V_106 | V_103 ;
if ( V_24 -> V_8 -> V_186 )
V_44 -> V_56 |= F_69 ( V_24 -> V_187 ,
V_24 -> V_187 ) ;
V_13 = F_44 ( V_9 -> V_12 , V_44 ) ;
if ( ! V_13 ) {
F_50 ( V_24 , V_44 ) ;
return NULL ;
}
return F_83 ( & V_9 -> V_4 , & V_44 -> V_8 , V_74 ) ;
}
static struct V_5 * F_84 (
struct V_2 * V_3 ,
enum V_188 V_189 ,
T_2 * V_190 )
{
struct V_1 * V_9 = F_1 ( V_3 ) ;
struct V_23 * V_24 = V_9 -> V_12 ;
struct V_5 * V_44 ;
enum V_159 V_167 ;
int V_13 , V_191 ;
T_4 V_192 , V_193 ;
T_1 V_163 , V_56 ;
V_44 = F_78 ( V_9 ) ;
if ( ! V_44 ) {
F_46 ( & V_24 -> V_29 -> V_30 , L_39 , V_123 ) ;
return NULL ;
}
if ( V_189 == V_194 ) {
V_56 = V_106 ;
* V_190 = V_9 -> V_180 . V_128 ;
V_167 = V_9 -> V_180 . V_178 ;
V_163 = V_9 -> V_180 . V_195 ;
V_192 = V_24 -> V_187 ;
V_193 = V_9 -> V_16 -> V_196 ;
} else if ( V_189 == V_197 ) {
V_56 = V_103 ;
* V_190 = V_9 -> V_180 . V_127 ;
V_167 = V_9 -> V_180 . V_176 ;
V_163 = V_9 -> V_180 . V_198 ;
V_192 = V_9 -> V_16 -> V_196 ;
V_193 = V_24 -> V_187 ;
} else {
F_50 ( V_24 , V_44 ) ;
F_46 ( & V_24 -> V_29 -> V_30 ,
L_40 , V_123 ) ;
return NULL ;
}
V_56 |= F_74 ( V_9 , V_167 , V_163 ) ;
if ( V_56 == ~ 0 ) {
F_50 ( V_24 , V_44 ) ;
F_46 ( & V_24 -> V_29 -> V_30 ,
L_41 ) ;
return NULL ;
}
V_44 -> V_56 = V_56 | F_69 ( V_192 , V_193 ) ;
if ( V_9 -> V_180 . V_179 )
V_191 = ( V_189 == V_194 ) ? V_199 :
V_200 ;
else
V_191 = ( V_189 == V_194 ) ? V_201 :
V_202 ;
V_44 -> V_27 |= V_191 << V_132 ;
V_13 = F_4 ( V_9 ) ;
if ( V_13 < 0 ) {
F_50 ( V_24 , V_44 ) ;
F_31 ( & V_24 -> V_29 -> V_30 ,
L_42 ,
V_9 -> V_81 ) ;
return NULL ;
}
F_31 ( & V_24 -> V_29 -> V_30 , L_43 ,
V_9 -> signal , V_9 -> V_81 ) ;
if ( V_189 == V_194 )
V_44 -> V_27 |= V_9 -> signal << V_203 ;
else
V_44 -> V_27 |= V_9 -> signal << V_204 ;
return V_44 ;
}
static int F_85 ( struct V_5 * V_44 ,
enum V_188 V_189 ,
T_2 V_190 ,
T_2 V_205 ,
unsigned int V_109 )
{
struct V_119 * V_120 ;
V_120 = F_79 ( sizeof( struct V_119 ) , V_122 ) ;
if ( ! V_120 )
return - V_206 ;
F_82 ( & V_120 -> V_45 , & V_44 -> V_181 ) ;
V_120 -> V_109 = V_109 ;
if ( V_189 == V_194 ) {
V_120 -> V_127 = V_205 ;
V_120 -> V_128 = V_190 ;
} else {
V_120 -> V_127 = V_190 ;
V_120 -> V_128 = V_205 ;
}
return 0 ;
}
static struct V_6 * F_86 (
struct V_2 * V_3 , struct V_207 * V_208 ,
unsigned int V_209 , enum V_188 V_189 ,
unsigned long V_74 , void * V_210 )
{
struct V_1 * V_9 = F_1 ( V_3 ) ;
struct V_23 * V_24 = V_9 -> V_12 ;
struct V_5 * V_44 ;
struct V_207 * V_211 ;
int V_13 , V_191 ;
T_2 V_190 ;
F_31 ( & V_24 -> V_29 -> V_30 , L_44 ,
V_123 , F_87 ( V_208 ) , V_9 -> V_81 ) ;
V_44 = F_84 ( V_3 , V_189 , & V_190 ) ;
if ( ! V_44 )
return NULL ;
F_88 (sgl, sg, sg_len, tmp) {
V_13 = F_85 ( V_44 , V_189 , V_190 ,
F_89 ( V_211 ) ,
F_87 ( V_211 ) ) ;
if ( V_13 ) {
F_5 ( V_9 ) ;
F_50 ( V_24 , V_44 ) ;
F_46 ( & V_24 -> V_29 -> V_30 , L_45 ,
V_123 ) ;
return NULL ;
}
}
V_13 = F_44 ( V_9 -> V_12 , V_44 ) ;
if ( ! V_13 ) {
F_5 ( V_9 ) ;
F_50 ( V_24 , V_44 ) ;
return NULL ;
}
return F_83 ( & V_9 -> V_4 , & V_44 -> V_8 , V_74 ) ;
}
static struct V_6 * F_90 (
struct V_2 * V_3 , T_2 V_205 , T_3 V_212 ,
T_3 V_213 , enum V_188 V_189 ,
unsigned long V_74 , void * V_210 )
{
struct V_1 * V_9 = F_1 ( V_3 ) ;
struct V_23 * V_24 = V_9 -> V_12 ;
struct V_5 * V_44 ;
int V_13 , V_191 ;
T_2 V_190 ;
F_31 ( & V_24 -> V_29 -> V_30 ,
L_46 ,
V_123 , V_213 , V_212 ,
V_189 == V_194 ? L_47 : L_48 ,
V_9 -> V_81 ) ;
V_44 = F_84 ( V_3 , V_189 , & V_190 ) ;
if ( ! V_44 )
return NULL ;
V_44 -> V_138 = true ;
V_44 -> V_56 |= V_139 ;
for ( V_191 = 0 ; V_191 < V_212 ; V_191 += V_213 ) {
V_13 = F_85 ( V_44 , V_189 , V_190 ,
V_205 + V_191 , V_213 ) ;
if ( V_13 ) {
F_5 ( V_9 ) ;
F_50 ( V_24 , V_44 ) ;
return NULL ;
}
}
V_13 = F_44 ( V_9 -> V_12 , V_44 ) ;
if ( ! V_13 ) {
F_5 ( V_9 ) ;
F_50 ( V_24 , V_44 ) ;
return NULL ;
}
return F_83 ( & V_9 -> V_4 , & V_44 -> V_8 , V_74 ) ;
}
static int F_91 ( struct V_2 * V_3 , enum V_214 V_215 ,
unsigned long V_216 )
{
struct V_1 * V_9 = F_1 ( V_3 ) ;
struct V_23 * V_24 = V_9 -> V_12 ;
unsigned long V_74 ;
int V_13 = 0 ;
if ( V_215 == V_217 ) {
return F_75 ( V_3 ,
(struct V_172 * ) V_216 ) ;
}
F_27 ( & V_9 -> V_4 . V_78 , V_74 ) ;
if ( ! V_9 -> V_25 && ! V_9 -> V_46 ) {
F_28 ( & V_9 -> V_4 . V_78 , V_74 ) ;
return 0 ;
}
switch ( V_215 ) {
case V_218 :
V_9 -> V_82 = V_89 ;
if ( V_9 -> V_25 ) {
F_33 ( V_9 ) ;
}
if ( V_9 -> V_46 ) {
F_54 ( & V_9 -> V_46 -> V_8 ) ;
V_9 -> V_46 = NULL ;
}
F_56 ( V_24 , V_9 ) ;
break;
case V_219 :
F_17 ( V_9 -> V_25 ) ;
V_9 -> V_82 = V_149 ;
break;
case V_220 :
F_20 ( V_9 -> V_25 ) ;
V_9 -> V_82 = V_84 ;
break;
default:
V_13 = - V_221 ;
break;
}
F_28 ( & V_9 -> V_4 . V_78 , V_74 ) ;
return V_13 ;
}
bool F_92 ( struct V_2 * V_3 , void * V_222 )
{
struct V_1 * V_9 ;
char * V_81 = V_222 ;
if ( V_3 -> V_223 -> V_30 -> V_224 != & V_225 . V_226 )
return false ;
V_9 = F_1 ( V_3 ) ;
if ( ! strcmp ( V_9 -> V_81 , V_81 ) )
return true ;
return false ;
}
static void F_93 ( struct V_23 * V_24 )
{
if ( V_24 -> V_8 -> V_227 )
return;
F_12 ( V_49 , V_24 -> V_37 + V_228 ) ;
}
static T_6 F_94 ( int V_229 , void * V_30 )
{
struct V_23 * V_24 = V_30 ;
T_1 V_230 = 0 , V_231 , V_232 , V_75 ;
V_231 = F_8 ( V_24 -> V_37 + V_233 ) ;
if ( V_231 ) {
F_46 ( & V_24 -> V_29 -> V_30 , L_49 ,
V_123 , V_231 ) ;
F_12 ( V_231 , V_24 -> V_37 + V_54 ) ;
}
V_232 = F_8 ( V_24 -> V_37 + V_234 ) ;
if ( V_232 )
F_12 ( V_232 , V_24 -> V_37 + V_55 ) ;
if ( ! V_231 && ! V_232 )
return V_235 ;
for ( V_75 = 0 ; V_75 < V_24 -> V_8 -> V_76 ; V_75 ++ ) {
if ( ( ( 1 << V_75 ) & V_231 ) || ( ( 1 << V_75 ) & V_232 ) ) {
struct V_18 * V_25 = & V_24 -> V_77 [ V_75 ] ;
struct V_1 * V_9 = V_25 -> V_80 ;
struct V_5 * V_7 ;
if ( ! V_9 ) {
F_46 ( & V_24 -> V_29 -> V_30 ,
L_50 ,
V_123 , V_75 ) ;
continue;
}
F_35 ( & V_9 -> V_4 . V_78 ) ;
V_7 = V_9 -> V_46 ;
if ( V_7 && V_7 -> V_138 ) {
F_95 ( & V_7 -> V_8 ) ;
} else if ( V_7 ) {
V_9 -> V_46 = NULL ;
F_5 ( V_9 ) ;
V_7 -> V_141 = true ;
F_96 ( & V_7 -> V_8 ) ;
if ( F_14 ( & V_9 -> V_4 ) )
F_13 ( V_9 ) ;
else
F_33 ( V_9 ) ;
}
F_36 ( & V_9 -> V_4 . V_78 ) ;
V_230 |= ( 1 << V_75 ) ;
}
}
return V_230 ? V_236 : V_235 ;
}
static void F_97 ( struct V_1 * V_3 )
{
V_3 -> V_174 = true ;
V_3 -> V_81 = V_3 -> V_16 -> V_237 ;
V_3 -> V_180 . V_127 = V_3 -> V_16 -> V_112 ;
V_3 -> V_180 . V_128 = V_3 -> V_16 -> V_112 ;
}
static int F_98 ( struct V_23 * V_24 ,
struct V_238 * V_239 , unsigned int V_76 , bool V_174 )
{
struct V_1 * V_3 ;
int V_75 ;
F_80 ( & V_239 -> V_76 ) ;
for ( V_75 = 0 ; V_75 < V_76 ; V_75 ++ ) {
V_3 = F_79 ( sizeof( * V_3 ) , V_240 ) ;
if ( ! V_3 ) {
F_46 ( & V_24 -> V_29 -> V_30 ,
L_51 , V_123 ) ;
return - V_206 ;
}
V_3 -> V_12 = V_24 ;
V_3 -> V_82 = V_89 ;
V_3 -> signal = - 1 ;
if ( V_174 ) {
V_3 -> V_16 = & V_24 -> V_11 -> V_241 [ V_75 ] ;
F_97 ( V_3 ) ;
} else {
V_3 -> V_16 = & V_24 -> V_11 -> V_184 ;
V_3 -> V_81 = F_99 ( V_240 , L_52 , V_75 ) ;
if ( ! V_3 -> V_81 ) {
F_53 ( V_3 ) ;
return - V_206 ;
}
}
F_31 ( & V_24 -> V_29 -> V_30 ,
L_53 ,
V_3 -> V_81 ) ;
V_3 -> V_4 . V_242 = F_54 ;
F_100 ( & V_3 -> V_4 , V_239 ) ;
}
F_101 ( & V_24 -> V_29 -> V_30 , L_54 ,
V_75 , V_174 ? L_55 : L_56 ) ;
return V_75 ;
}
static void F_102 ( struct V_238 * V_239 )
{
struct V_1 * V_3 = NULL ;
struct V_1 * V_86 ;
F_52 (chan,
next, &dmadev->channels, vc.chan.device_node) {
F_15 ( & V_3 -> V_4 . V_3 . V_243 ) ;
F_53 ( V_3 ) ;
}
}
static const char * F_103 ( enum V_244 V_82 )
{
switch ( V_82 ) {
case V_89 :
return L_57 ;
case V_84 :
return L_58 ;
case V_149 :
return L_59 ;
case V_83 :
return L_60 ;
default:
break;
}
return L_61 ;
}
static int F_104 ( struct V_245 * V_246 , void * V_247 )
{
struct V_23 * V_24 = V_246 -> V_248 ;
struct V_1 * V_3 ;
struct V_18 * V_19 ;
unsigned long V_74 ;
int V_75 ;
F_105 ( V_246 , L_62 ) ;
F_105 ( V_246 , L_63 ) ;
F_105 ( V_246 , L_64 ) ;
for ( V_75 = 0 ; V_75 < V_24 -> V_8 -> V_76 ; V_75 ++ ) {
struct V_1 * V_73 ;
V_19 = & V_24 -> V_77 [ V_75 ] ;
F_27 ( & V_19 -> V_78 , V_74 ) ;
V_73 = V_19 -> V_80 ;
F_105 ( V_246 , L_65 ,
V_19 -> V_31 ,
V_73 ? V_73 -> V_81 : L_66 ,
V_19 -> V_79 ? L_67 : L_10 ) ;
F_28 ( & V_19 -> V_78 , V_74 ) ;
}
F_105 ( V_246 , L_68 ) ;
F_105 ( V_246 , L_69 ) ;
F_105 ( V_246 , L_70 ) ;
F_34 (chan, &pl08x->memcpy.channels, vc.chan.device_node) {
F_105 ( V_246 , L_71 , V_3 -> V_81 ,
F_103 ( V_3 -> V_82 ) ) ;
}
F_105 ( V_246 , L_72 ) ;
F_105 ( V_246 , L_69 ) ;
F_105 ( V_246 , L_70 ) ;
F_34 (chan, &pl08x->slave.channels, vc.chan.device_node) {
F_105 ( V_246 , L_71 , V_3 -> V_81 ,
F_103 ( V_3 -> V_82 ) ) ;
}
return 0 ;
}
static int F_106 ( struct V_249 * V_249 , struct V_250 * V_250 )
{
return F_107 ( V_250 , F_104 , V_249 -> V_251 ) ;
}
static void F_108 ( struct V_23 * V_24 )
{
( void ) F_109 ( F_110 ( & V_24 -> V_29 -> V_30 ) ,
V_252 | V_253 , NULL , V_24 ,
& V_254 ) ;
}
static inline void F_108 ( struct V_23 * V_24 )
{
}
static int F_111 ( struct V_255 * V_29 , const struct V_256 * V_31 )
{
struct V_23 * V_24 ;
const struct V_257 * V_8 = V_31 -> V_247 ;
T_1 V_258 ;
int V_13 = 0 ;
int V_75 ;
V_13 = F_112 ( V_29 , NULL ) ;
if ( V_13 )
return V_13 ;
V_13 = F_113 ( & V_29 -> V_30 , F_114 ( 32 ) ) ;
if ( V_13 )
goto V_259;
V_24 = F_79 ( sizeof( * V_24 ) , V_240 ) ;
if ( ! V_24 ) {
V_13 = - V_206 ;
goto V_259;
}
F_115 ( V_260 , V_24 -> memcpy . V_261 ) ;
V_24 -> memcpy . V_30 = & V_29 -> V_30 ;
V_24 -> memcpy . V_262 = F_60 ;
V_24 -> memcpy . V_263 = F_61 ;
V_24 -> memcpy . V_264 = F_81 ;
V_24 -> memcpy . V_265 = F_64 ;
V_24 -> memcpy . V_266 = F_65 ;
V_24 -> memcpy . V_267 = F_76 ;
V_24 -> memcpy . V_268 = F_91 ;
F_115 ( V_269 , V_24 -> V_174 . V_261 ) ;
F_115 ( V_270 , V_24 -> V_174 . V_261 ) ;
V_24 -> V_174 . V_30 = & V_29 -> V_30 ;
V_24 -> V_174 . V_262 = F_60 ;
V_24 -> V_174 . V_263 = F_61 ;
V_24 -> V_174 . V_265 = F_64 ;
V_24 -> V_174 . V_266 = F_65 ;
V_24 -> V_174 . V_267 = F_76 ;
V_24 -> V_174 . V_271 = F_86 ;
V_24 -> V_174 . V_272 = F_90 ;
V_24 -> V_174 . V_268 = F_91 ;
V_24 -> V_11 = F_116 ( & V_29 -> V_30 ) ;
if ( ! V_24 -> V_11 ) {
F_46 ( & V_29 -> V_30 , L_73 ) ;
V_13 = - V_175 ;
goto V_273;
}
V_24 -> V_29 = V_29 ;
V_24 -> V_8 = V_8 ;
V_24 -> V_124 = V_154 ;
V_24 -> V_187 = V_154 ;
if ( V_24 -> V_8 -> V_186 ) {
V_24 -> V_124 = V_24 -> V_11 -> V_124 ;
V_24 -> V_187 = V_24 -> V_11 -> V_187 ;
}
if ( V_8 -> V_28 )
V_24 -> V_71 = V_274 ;
else
V_24 -> V_71 = V_275 ;
V_258 = V_72 * V_24 -> V_71 * sizeof( T_1 ) ;
V_24 -> V_121 = F_117 ( V_276 , & V_24 -> V_29 -> V_30 ,
V_258 , V_277 , 0 ) ;
if ( ! V_24 -> V_121 ) {
V_13 = - V_206 ;
goto V_278;
}
V_24 -> V_37 = F_118 ( V_29 -> V_279 . V_280 , F_119 ( & V_29 -> V_279 ) ) ;
if ( ! V_24 -> V_37 ) {
V_13 = - V_206 ;
goto V_281;
}
F_93 ( V_24 ) ;
F_12 ( 0x000000FF , V_24 -> V_37 + V_54 ) ;
F_12 ( 0x000000FF , V_24 -> V_37 + V_55 ) ;
V_13 = F_120 ( V_29 -> V_229 [ 0 ] , F_94 , 0 , V_276 , V_24 ) ;
if ( V_13 ) {
F_46 ( & V_29 -> V_30 , L_74 ,
V_123 , V_29 -> V_229 [ 0 ] ) ;
goto V_282;
}
V_24 -> V_77 = F_79 ( ( V_8 -> V_76 * sizeof( * V_24 -> V_77 ) ) ,
V_240 ) ;
if ( ! V_24 -> V_77 ) {
F_46 ( & V_29 -> V_30 , L_75
L_76 ,
V_123 ) ;
V_13 = - V_206 ;
goto V_283;
}
for ( V_75 = 0 ; V_75 < V_8 -> V_76 ; V_75 ++ ) {
struct V_18 * V_19 = & V_24 -> V_77 [ V_75 ] ;
V_19 -> V_31 = V_75 ;
V_19 -> V_37 = V_24 -> V_37 + F_121 ( V_75 ) ;
V_19 -> V_21 = V_19 -> V_37 + V_8 -> V_284 ;
F_122 ( & V_19 -> V_78 ) ;
if ( V_8 -> V_227 ) {
T_1 V_20 ;
V_20 = F_8 ( V_19 -> V_21 ) ;
if ( V_20 & ( V_285 | V_286 ) ) {
F_101 ( & V_29 -> V_30 , L_77 , V_75 ) ;
V_19 -> V_79 = true ;
}
}
F_31 ( & V_29 -> V_30 , L_78 ,
V_75 , F_7 ( V_19 ) ? L_79 : L_80 ) ;
}
V_13 = F_98 ( V_24 , & V_24 -> memcpy ,
V_24 -> V_8 -> V_76 , false ) ;
if ( V_13 <= 0 ) {
F_123 ( & V_24 -> V_29 -> V_30 ,
L_81 ,
V_123 , V_13 ) ;
goto V_287;
}
V_24 -> memcpy . V_288 = V_13 ;
V_13 = F_98 ( V_24 , & V_24 -> V_174 ,
V_24 -> V_11 -> V_289 , true ) ;
if ( V_13 < 0 ) {
F_123 ( & V_24 -> V_29 -> V_30 ,
L_82 ,
V_123 , V_13 ) ;
goto V_290;
}
V_24 -> V_174 . V_288 = V_13 ;
V_13 = F_124 ( & V_24 -> memcpy ) ;
if ( V_13 ) {
F_123 ( & V_24 -> V_29 -> V_30 ,
L_83 ,
V_123 , V_13 ) ;
goto V_291;
}
V_13 = F_124 ( & V_24 -> V_174 ) ;
if ( V_13 ) {
F_123 ( & V_24 -> V_29 -> V_30 ,
L_84 ,
V_123 , V_13 ) ;
goto V_292;
}
F_125 ( V_29 , V_24 ) ;
F_108 ( V_24 ) ;
F_101 ( & V_24 -> V_29 -> V_30 , L_85 ,
F_126 ( V_29 ) , V_24 -> V_8 -> V_28 ? L_86 : L_10 , F_127 ( V_29 ) ,
( unsigned long long ) V_29 -> V_279 . V_280 , V_29 -> V_229 [ 0 ] ) ;
return 0 ;
V_292:
F_128 ( & V_24 -> memcpy ) ;
V_291:
F_102 ( & V_24 -> V_174 ) ;
V_290:
F_102 ( & V_24 -> memcpy ) ;
V_287:
F_53 ( V_24 -> V_77 ) ;
V_283:
F_129 ( V_29 -> V_229 [ 0 ] , V_24 ) ;
V_282:
F_130 ( V_24 -> V_37 ) ;
V_281:
F_131 ( V_24 -> V_121 ) ;
V_278:
V_273:
F_53 ( V_24 ) ;
V_259:
F_132 ( V_29 ) ;
return V_13 ;
}
static int T_7 F_133 ( void )
{
int V_143 ;
V_143 = F_134 ( & V_225 ) ;
if ( V_143 )
F_135 (KERN_WARNING DRIVER_NAME
L_87 ,
retval) ;
return V_143 ;
}
