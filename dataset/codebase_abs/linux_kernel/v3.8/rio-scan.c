static T_1 F_1 ( struct V_1 * V_2 )
{
int V_3 ;
struct V_4 * V_5 = & V_2 -> V_6 ;
F_2 ( & V_5 -> V_7 ) ;
V_3 = F_3 ( V_5 -> V_8 , V_5 -> V_9 ) ;
if ( V_3 < V_5 -> V_9 ) {
F_4 ( V_3 , V_5 -> V_8 ) ;
V_3 += V_5 -> V_10 ;
} else
V_3 = V_11 ;
F_5 ( & V_5 -> V_7 ) ;
return ( T_1 ) V_3 ;
}
static int F_6 ( struct V_1 * V_2 , T_1 V_3 )
{
int V_12 ;
struct V_4 * V_5 = & V_2 -> V_6 ;
V_3 -= V_5 -> V_10 ;
F_2 ( & V_5 -> V_7 ) ;
V_12 = F_7 ( V_3 , V_5 -> V_8 ) ;
F_5 ( & V_5 -> V_7 ) ;
return V_12 ;
}
static void F_8 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_4 * V_5 = & V_2 -> V_6 ;
V_3 -= V_5 -> V_10 ;
F_2 ( & V_5 -> V_7 ) ;
F_9 ( V_3 , V_5 -> V_8 ) ;
F_5 ( & V_5 -> V_7 ) ;
}
static T_1 F_10 ( struct V_1 * V_2 )
{
int V_3 ;
struct V_4 * V_5 = & V_2 -> V_6 ;
F_2 ( & V_5 -> V_7 ) ;
V_3 = F_11 ( V_5 -> V_8 , V_5 -> V_9 ) ;
if ( V_3 >= V_5 -> V_9 )
V_3 = V_11 ;
else
V_3 += V_5 -> V_10 ;
F_5 ( & V_5 -> V_7 ) ;
return ( T_1 ) V_3 ;
}
static T_1 F_12 ( struct V_1 * V_2 , T_1 V_13 )
{
int V_3 ;
struct V_4 * V_5 = & V_2 -> V_6 ;
F_2 ( & V_5 -> V_7 ) ;
V_3 = F_13 ( V_5 -> V_8 , V_5 -> V_9 , V_13 ) ;
if ( V_3 >= V_5 -> V_9 )
V_3 = V_11 ;
else
V_3 += V_5 -> V_10 ;
F_5 ( & V_5 -> V_7 ) ;
return ( T_1 ) V_3 ;
}
static T_1 F_14 ( struct V_14 * V_15 , T_1 V_3 , T_2 V_16 )
{
T_3 V_17 ;
F_15 ( V_15 , V_3 , V_16 , V_18 , & V_17 ) ;
return F_16 ( V_15 -> V_19 , V_17 ) ;
}
static void F_17 ( struct V_14 * V_15 , T_1 V_3 , T_2 V_16 , T_1 V_20 )
{
F_18 ( V_15 , V_3 , V_16 , V_18 ,
F_19 ( V_15 -> V_19 , V_20 ) ) ;
}
static void F_20 ( struct V_14 * V_15 , T_1 V_20 )
{
F_21 ( V_15 , V_18 , F_19 ( V_15 -> V_19 ,
V_20 ) ) ;
}
static int F_22 ( struct V_1 * V_2 )
{
struct V_14 * V_15 = V_2 -> V_21 ;
struct V_22 * V_23 ;
T_3 V_17 ;
int V_24 = 0 ;
F_21 ( V_15 , V_25 ,
V_15 -> V_26 ) ;
F_23 ( V_15 , V_25 , & V_17 ) ;
if ( ( V_17 & 0xffff ) != 0xffff ) {
F_24 ( V_27
L_1 ,
V_17 ) ;
V_24 = - V_28 ;
}
F_25 (rdev, &net->devices, net_list) {
F_26 ( V_23 , V_25 ,
V_15 -> V_26 ) ;
F_27 ( V_23 , V_25 , & V_17 ) ;
if ( ( V_17 & 0xffff ) != 0xffff ) {
F_24 ( V_27
L_2 ,
V_23 -> V_29 , V_23 -> V_20 ) ;
V_24 = - V_28 ;
}
F_27 ( V_23 ,
V_23 -> V_30 + V_31 ,
& V_17 ) ;
V_17 |= V_32 | V_33 ;
F_26 ( V_23 ,
V_23 -> V_30 + V_31 ,
V_17 ) ;
}
return V_24 ;
}
static int F_28 ( struct V_14 * V_15 )
{
T_3 V_17 ;
F_21 ( V_15 , V_25 ,
V_15 -> V_26 ) ;
F_23 ( V_15 , V_25 , & V_17 ) ;
if ( ( V_17 & 0xffff ) != V_15 -> V_26 )
return - 1 ;
F_20 ( V_15 , V_15 -> V_26 ) ;
return 0 ;
}
static int F_29 ( struct V_14 * V_15 , int V_34 ,
int V_35 )
{
T_3 V_36 = V_37 | V_38 | V_39 | V_40 | V_41 | V_42 | V_43 ;
return ! ! ( ( V_34 | V_35 ) & V_36 ) ;
}
static void F_30 ( struct V_44 * V_45 )
{
struct V_22 * V_23 ;
V_23 = F_31 ( V_45 ) ;
F_32 ( V_23 ) ;
}
static int F_33 ( struct V_22 * V_23 )
{
if ( V_23 -> V_46 & V_47 )
return 1 ;
return 0 ;
}
static void F_34 ( struct V_22 * V_23 , int V_48 )
{
struct V_49 * V_50 = V_51 ;
struct V_49 * V_52 = V_53 ;
while ( V_50 < V_52 ) {
if ( ( V_50 -> V_29 == V_23 -> V_29 ) && ( V_50 -> V_20 == V_23 -> V_20 ) ) {
F_35 ( L_3 ,
F_36 ( V_23 ) ) ;
V_50 -> V_54 ( V_23 , V_48 ) ;
break;
}
V_50 ++ ;
}
if ( ( V_50 >= V_52 ) && ( V_23 -> V_46 & V_55 ) ) {
F_35 ( L_4 ,
F_36 ( V_23 ) ) ;
V_23 -> V_56 -> V_57 = V_58 ;
V_23 -> V_56 -> V_59 = V_60 ;
V_23 -> V_56 -> V_61 = V_62 ;
}
if ( ! V_23 -> V_56 -> V_57 || ! V_23 -> V_56 -> V_59 )
F_24 ( V_63 L_5 ,
F_36 ( V_23 ) ) ;
}
static int F_37 ( struct V_22 * V_23 )
{
int V_64 ;
V_64 = F_38 ( & V_23 -> V_45 ) ;
if ( V_64 )
return V_64 ;
F_2 ( & V_65 ) ;
F_39 ( & V_23 -> V_66 , & V_67 ) ;
F_5 ( & V_65 ) ;
F_40 ( V_23 ) ;
return 0 ;
}
inline int F_41 ( struct V_14 * V_15 ,
int V_68 , T_1 V_3 ,
T_2 V_16 , T_2 V_69 ) {
#ifdef F_42
T_3 V_70 ;
T_3 V_71 ;
F_35 ( L_6
L_7 , V_68 , V_3 , V_16 , V_69 ) ;
V_71 = F_43 ( V_15 , V_68 , V_3 , V_16 ) ;
if ( V_68 ) {
F_23 ( V_15 , V_71 +
F_44 ( 0 ) ,
& V_70 ) ;
} else {
if ( F_15 ( V_15 , V_3 , V_16 ,
V_71 + F_44 ( V_69 ) , & V_70 ) < 0 )
return - V_72 ;
}
if ( V_70 & V_73 ) {
V_70 = V_70 | V_74
| V_75 ;
} else {
V_70 = V_70 | V_76
| V_77 ;
}
if ( V_68 ) {
F_21 ( V_15 , V_71 +
F_44 ( 0 ) , V_70 ) ;
} else {
if ( F_18 ( V_15 , V_3 , V_16 ,
V_71 + F_44 ( V_69 ) , V_70 ) < 0 )
return - V_72 ;
}
#endif
return 0 ;
}
static struct V_22 * F_45 ( struct V_1 * V_2 ,
struct V_14 * V_15 , T_1 V_3 ,
T_2 V_16 , int V_48 )
{
int V_24 = 0 ;
struct V_22 * V_23 ;
struct V_78 * V_56 = NULL ;
int V_17 , V_79 ;
T_4 V_80 ;
T_3 V_81 = 0 ;
V_80 = sizeof( struct V_22 ) ;
if ( F_15 ( V_15 , V_3 , V_16 ,
V_82 , & V_17 ) )
return NULL ;
if ( V_17 & ( V_47 | V_83 ) ) {
F_15 ( V_15 , V_3 , V_16 ,
V_84 , & V_81 ) ;
if ( V_17 & V_47 ) {
V_80 += ( F_46 ( V_81 ) *
sizeof( V_56 -> V_85 [ 0 ] ) ) + sizeof( * V_56 ) ;
}
}
V_23 = F_47 ( V_80 , V_86 ) ;
if ( ! V_23 )
return NULL ;
V_23 -> V_2 = V_2 ;
V_23 -> V_46 = V_17 ;
V_23 -> V_81 = V_81 ;
F_15 ( V_15 , V_3 , V_16 , V_87 ,
& V_17 ) ;
V_23 -> V_20 = V_17 >> 16 ;
V_23 -> V_29 = V_17 & 0xffff ;
F_15 ( V_15 , V_3 , V_16 , V_88 ,
& V_23 -> V_89 ) ;
F_15 ( V_15 , V_3 , V_16 , V_90 ,
& V_17 ) ;
V_23 -> V_91 = V_17 >> 16 ;
V_23 -> V_92 = V_17 & 0xffff ;
F_15 ( V_15 , V_3 , V_16 , V_93 ,
& V_17 ) ;
V_23 -> V_94 = V_17 >> 16 ;
if ( V_23 -> V_46 & V_95 ) {
V_23 -> V_96 = V_17 & 0xffff ;
V_23 -> V_30 = F_43 ( V_15 , 0 , V_3 ,
V_16 ) ;
V_23 -> V_97 = F_48 ( V_15 , 0 , V_3 ,
V_16 , V_98 ) ;
}
F_15 ( V_15 , V_3 , V_16 , V_99 ,
& V_23 -> V_34 ) ;
F_15 ( V_15 , V_3 , V_16 , V_100 ,
& V_23 -> V_35 ) ;
if ( V_48 ) {
if ( V_101 >= 0x10000 ) {
F_49 ( L_8 ) ;
goto V_102;
}
F_18 ( V_15 , V_3 , V_16 ,
V_103 , V_101 ) ;
V_23 -> V_104 = V_101 ++ ;
} else {
F_15 ( V_15 , V_3 , V_16 ,
V_103 ,
& V_23 -> V_104 ) ;
}
if ( F_29 ( V_15 , V_23 -> V_34 , V_23 -> V_35 ) ) {
if ( V_48 ) {
F_17 ( V_15 , V_3 , V_16 , V_105 ) ;
V_23 -> V_3 = V_105 ;
V_105 = F_1 ( V_2 ) ;
} else
V_23 -> V_3 = F_14 ( V_15 , V_3 , V_16 ) ;
V_23 -> V_16 = 0xff ;
} else {
V_23 -> V_3 = V_3 ;
V_23 -> V_16 = V_16 ;
}
if ( F_33 ( V_23 ) ) {
V_56 = V_23 -> V_56 ;
V_56 -> V_106 = V_23 -> V_104 & V_107 ;
V_56 -> V_108 = 0 ;
V_56 -> V_109 = F_47 ( sizeof( T_2 ) *
F_50 ( V_15 -> V_19 ) ,
V_86 ) ;
if ( ! V_56 -> V_109 )
goto V_102;
for ( V_79 = 0 ; V_79 < F_50 ( V_15 -> V_19 ) ;
V_79 ++ )
V_56 -> V_109 [ V_79 ] = V_110 ;
F_51 ( & V_23 -> V_45 , L_9 , V_23 -> V_2 -> V_111 ,
V_56 -> V_106 ) ;
F_34 ( V_23 , V_48 ) ;
if ( V_48 && V_56 -> V_61 )
V_56 -> V_61 ( V_15 , V_3 , V_16 ,
V_112 ) ;
F_39 ( & V_56 -> V_113 , & V_2 -> V_114 ) ;
} else {
if ( V_48 )
F_41 ( V_15 , 0 , V_3 , V_16 , 0 ) ;
F_51 ( & V_23 -> V_45 , L_10 , V_23 -> V_2 -> V_111 ,
V_23 -> V_3 ) ;
}
V_23 -> V_45 . V_115 = & V_116 ;
V_23 -> V_45 . V_117 = & V_118 ;
F_52 ( & V_23 -> V_45 ) ;
V_23 -> V_45 . V_119 = F_30 ;
F_53 ( V_23 ) ;
V_23 -> V_120 = F_54 ( 32 ) ;
V_23 -> V_45 . V_120 = & V_23 -> V_120 ;
V_23 -> V_45 . V_121 = F_54 ( 32 ) ;
if ( V_23 -> V_35 & V_122 )
F_55 ( & V_23 -> V_123 [ V_124 ] ,
0 , 0xffff ) ;
V_24 = F_37 ( V_23 ) ;
if ( V_24 )
goto V_102;
return V_23 ;
V_102:
if ( V_56 )
F_32 ( V_56 -> V_109 ) ;
F_32 ( V_23 ) ;
return NULL ;
}
static int
F_56 ( struct V_14 * V_15 , T_1 V_3 , T_2 V_16 , int V_125 )
{
T_3 V_17 = 0 ;
T_3 V_71 ;
V_71 = F_57 ( V_15 , 0 , V_3 , V_16 , 0 ) ;
while ( V_71 ) {
F_15 ( V_15 , V_3 , V_16 ,
V_71 , & V_17 ) ;
V_17 = F_58 ( V_17 ) ;
if ( ( V_17 == V_126 ) ||
( V_17 == V_127 ) ||
( V_17 == V_128 ) )
break;
V_71 = F_57 ( V_15 , 0 , V_3 , V_16 ,
V_71 ) ;
}
if ( V_71 )
F_15 ( V_15 , V_3 , V_16 ,
V_71 +
F_59 ( V_125 ) ,
& V_17 ) ;
return V_17 & V_129 ;
}
static int
F_60 ( struct V_14 * V_15 , T_1 V_3 , T_2 V_16 , int V_130 )
{
T_3 V_17 ;
int V_131 = 0 ;
F_18 ( V_15 , V_3 , V_16 ,
V_25 , V_15 -> V_26 ) ;
F_15 ( V_15 , V_3 , V_16 ,
V_25 , & V_17 ) ;
while ( V_17 != V_15 -> V_26 ) {
if ( V_130 != 0 && V_131 == V_130 ) {
F_35 ( L_11 ,
V_3 , V_16 ) ;
return - V_28 ;
}
F_61 ( 1 ) ;
V_131 ++ ;
F_18 ( V_15 , V_3 ,
V_16 ,
V_25 ,
V_15 -> V_26 ) ;
F_15 ( V_15 , V_3 ,
V_16 ,
V_25 , & V_17 ) ;
}
return 0 ;
}
static int
F_62 ( struct V_14 * V_15 , T_1 V_3 , T_2 V_16 )
{
T_3 V_17 ;
F_18 ( V_15 , V_3 ,
V_16 ,
V_25 ,
V_15 -> V_26 ) ;
F_15 ( V_15 , V_3 , V_16 ,
V_25 , & V_17 ) ;
if ( ( V_17 & 0xffff ) != 0xffff ) {
F_35 ( L_12 ,
V_3 , V_16 ) ;
return - V_28 ;
}
return 0 ;
}
static int
F_63 ( struct V_22 * V_23 ,
T_1 V_8 , T_1 V_132 , T_2 V_133 , int V_7 )
{
int V_134 ;
if ( V_7 ) {
V_134 = F_60 ( V_23 -> V_2 -> V_21 , V_23 -> V_3 ,
V_23 -> V_16 , 1000 ) ;
if ( V_134 )
return V_134 ;
}
V_134 = V_23 -> V_56 -> V_57 ( V_23 -> V_2 -> V_21 , V_23 -> V_3 ,
V_23 -> V_16 , V_8 ,
V_132 , V_133 ) ;
if ( V_7 )
F_62 ( V_23 -> V_2 -> V_21 , V_23 -> V_3 ,
V_23 -> V_16 ) ;
return V_134 ;
}
static int
F_64 ( struct V_22 * V_23 , T_1 V_8 ,
T_1 V_132 , T_2 * V_133 , int V_7 )
{
int V_134 ;
if ( V_7 ) {
V_134 = F_60 ( V_23 -> V_2 -> V_21 , V_23 -> V_3 ,
V_23 -> V_16 , 1000 ) ;
if ( V_134 )
return V_134 ;
}
V_134 = V_23 -> V_56 -> V_59 ( V_23 -> V_2 -> V_21 , V_23 -> V_3 ,
V_23 -> V_16 , V_8 ,
V_132 , V_133 ) ;
if ( V_7 )
F_62 ( V_23 -> V_2 -> V_21 , V_23 -> V_3 ,
V_23 -> V_16 ) ;
return V_134 ;
}
static T_1 F_65 ( struct V_14 * V_15 , T_2 V_16 )
{
T_3 V_17 ;
F_15 ( V_15 , F_66 ( V_15 -> V_19 ) , V_16 ,
V_25 , & V_17 ) ;
return ( T_1 ) ( V_17 & 0xffff ) ;
}
static int F_67 ( struct V_1 * V_2 , struct V_14 * V_15 ,
T_2 V_16 , struct V_22 * V_135 , int V_136 )
{
struct V_22 * V_23 ;
T_3 V_70 ;
int V_137 ;
if ( F_68 ( V_15 ,
F_66 ( V_15 -> V_19 ) , V_16 ) ) {
F_35 ( L_13 ) ;
return - 1 ;
}
if ( F_65 ( V_15 , V_16 ) == V_15 -> V_26 ) {
F_35 ( L_14 ) ;
F_15 ( V_15 , F_66 ( V_15 -> V_19 ) ,
V_16 , V_103 , & V_70 ) ;
if ( V_70 ) {
V_23 = F_69 ( ( V_70 & 0xffff ) , NULL ) ;
if ( V_23 && V_135 && F_33 ( V_135 ) ) {
F_35 ( L_15 ,
F_36 ( V_23 ) ) ;
V_135 -> V_56 -> V_85 [ V_136 ] = V_23 ;
}
}
return 0 ;
}
F_18 ( V_15 , F_66 ( V_15 -> V_19 ) ,
V_16 ,
V_25 , V_15 -> V_26 ) ;
while ( ( V_137 = F_65 ( V_15 , V_16 ) )
< V_15 -> V_26 ) {
F_61 ( 1 ) ;
F_18 ( V_15 , F_66 ( V_15 -> V_19 ) ,
V_16 ,
V_25 ,
V_15 -> V_26 ) ;
}
if ( F_65 ( V_15 , V_16 ) > V_15 -> V_26 ) {
F_35 (
L_16 ) ;
return - 1 ;
}
V_23 = F_45 ( V_2 , V_15 , F_66 ( V_15 -> V_19 ) ,
V_16 , 1 ) ;
if ( V_23 ) {
F_39 ( & V_23 -> V_138 , & V_2 -> V_139 ) ;
V_23 -> V_135 = V_135 ;
if ( V_135 && F_33 ( V_135 ) )
V_135 -> V_56 -> V_85 [ V_136 ] = V_23 ;
} else
return - 1 ;
if ( F_33 ( V_23 ) ) {
int V_140 ;
int V_141 ;
int V_142 ;
T_1 V_3 ;
int V_69 ;
V_142 = F_70 ( V_23 -> V_81 ) ;
F_63 ( V_23 , V_112 ,
V_15 -> V_26 , V_142 , 0 ) ;
V_23 -> V_56 -> V_109 [ V_15 -> V_26 ] = V_142 ;
V_3 = F_10 ( V_2 ) ;
while ( V_3 != V_11 && V_3 < V_105 ) {
if ( V_3 != V_15 -> V_26 ) {
F_63 ( V_23 , V_112 ,
V_3 , V_142 , 0 ) ;
V_23 -> V_56 -> V_109 [ V_3 ] = V_142 ;
}
V_3 = F_12 ( V_2 , V_3 + 1 ) ;
}
F_35 (
L_17 ,
F_36 ( V_23 ) , V_23 -> V_29 , V_23 -> V_20 ,
F_46 ( V_23 -> V_81 ) ) ;
V_140 = V_105 ;
for ( V_69 = 0 ;
V_69 < F_46 ( V_23 -> V_81 ) ;
V_69 ++ ) {
if ( V_142 == V_69 ) {
F_41 ( V_15 , 0 ,
F_66 ( V_15 -> V_19 ) ,
V_16 , V_69 ) ;
V_23 -> V_56 -> V_108 |= ( 1 << V_69 ) ;
continue;
}
V_141 = V_105 ;
if ( F_56
( V_15 , F_66 ( V_15 -> V_19 ) , V_16 ,
V_69 ) ) {
F_35 (
L_18 ,
V_69 ) ;
F_41 ( V_15 , 0 ,
F_66 ( V_15 -> V_19 ) ,
V_16 , V_69 ) ;
V_23 -> V_56 -> V_108 |= ( 1 << V_69 ) ;
F_63 ( V_23 , V_112 ,
F_66 ( V_15 -> V_19 ) ,
V_69 , 0 ) ;
if ( F_67 ( V_2 , V_15 , V_16 + 1 ,
V_23 , V_69 ) < 0 )
return - 1 ;
V_3 = F_12 ( V_2 , V_141 + 1 ) ;
if ( V_3 != V_11 ) {
for ( V_3 = V_141 ;
V_3 < V_105 ; ) {
if ( V_3 != V_15 -> V_26 ) {
F_63 ( V_23 ,
V_112 ,
V_3 ,
V_69 ,
0 ) ;
V_23 -> V_56 ->
V_109 [ V_3 ] =
V_69 ;
}
V_3 = F_12 ( V_2 ,
V_3 + 1 ) ;
}
}
} else {
if ( V_23 -> V_97 )
F_71 ( V_23 , V_69 , 1 ) ;
V_23 -> V_56 -> V_108 &= ~ ( 1 << V_69 ) ;
}
}
if ( ( V_23 -> V_34 & V_143 ) &&
( V_23 -> V_97 ) ) {
F_26 ( V_23 ,
V_23 -> V_97 + V_144 ,
( V_15 -> V_26 << 16 ) |
( V_15 -> V_19 << 15 ) ) ;
}
F_72 ( V_23 ) ;
if ( V_105 == V_140 )
V_105 = F_1 ( V_2 ) ;
V_23 -> V_3 = V_140 ;
} else
F_35 ( L_19 ,
F_36 ( V_23 ) , V_23 -> V_29 , V_23 -> V_20 ) ;
return 0 ;
}
static int F_73 ( struct V_14 * V_15 )
{
T_3 V_70 ;
F_23 ( V_15 , V_15 -> V_30 + V_31 ,
& V_70 ) ;
return ( V_70 & V_32 ) ? 1 : 0 ;
}
static int
F_74 ( struct V_1 * V_2 , struct V_14 * V_15 , T_1 V_3 ,
T_2 V_16 , struct V_22 * V_135 , int V_136 )
{
T_2 V_69 , V_133 ;
struct V_22 * V_23 ;
T_1 V_145 ;
if ( ( V_23 = F_45 ( V_2 , V_15 , V_3 , V_16 , 0 ) ) ) {
F_39 ( & V_23 -> V_138 , & V_2 -> V_139 ) ;
V_23 -> V_135 = V_135 ;
if ( V_135 && F_33 ( V_135 ) )
V_135 -> V_56 -> V_85 [ V_136 ] = V_23 ;
} else
return - 1 ;
if ( F_33 ( V_23 ) ) {
V_23 -> V_3 = V_3 ;
F_35 (
L_17 ,
F_36 ( V_23 ) , V_23 -> V_29 , V_23 -> V_20 ,
F_46 ( V_23 -> V_81 ) ) ;
for ( V_69 = 0 ;
V_69 < F_46 ( V_23 -> V_81 ) ;
V_69 ++ ) {
if ( F_70 ( V_23 -> V_81 ) == V_69 )
continue;
if ( F_56
( V_15 , V_3 , V_16 , V_69 ) ) {
F_35 (
L_18 ,
V_69 ) ;
F_60 ( V_15 , V_3 , V_16 , 1000 ) ;
for ( V_145 = 0 ;
V_145 < F_66 ( V_15 -> V_19 ) ;
V_145 ++ ) {
F_64 ( V_23 ,
V_112 ,
V_145 ,
& V_133 , 0 ) ;
if ( V_133 == V_69 )
break;
}
if ( V_145 == F_66 ( V_15 -> V_19 ) )
continue;
F_62 ( V_15 , V_3 , V_16 ) ;
if ( F_74 ( V_2 , V_15 , V_145 ,
V_16 + 1 , V_23 , V_69 ) < 0 )
return - 1 ;
}
}
} else
F_35 ( L_19 ,
F_36 ( V_23 ) , V_23 -> V_29 , V_23 -> V_20 ) ;
return 0 ;
}
static int F_75 ( struct V_14 * V_15 )
{
T_3 V_17 = 0 ;
T_3 V_71 ;
int * V_146 = V_147 ;
do {
if ( ( V_71 =
F_48 ( V_15 , 1 , 0 , 0 , * V_146 ) ) )
break;
} while ( * ++ V_146 >= 0 );
if ( V_71 )
F_23 ( V_15 ,
V_71 +
F_59 ( V_15 -> V_148 ) ,
& V_17 ) ;
return V_17 & V_129 ;
}
static struct V_1 * F_76 ( struct V_14 * V_15 ,
int V_48 , T_1 V_10 )
{
struct V_1 * V_2 ;
V_2 = F_47 ( sizeof( struct V_1 ) , V_86 ) ;
if ( V_2 && V_48 ) {
V_2 -> V_6 . V_8 = F_77 (
F_78 ( F_50 ( V_15 -> V_19 ) ) ,
sizeof( long ) ,
V_86 ) ;
if ( V_2 -> V_6 . V_8 == NULL ) {
F_49 ( L_20 ) ;
F_32 ( V_2 ) ;
V_2 = NULL ;
} else {
V_2 -> V_6 . V_10 = V_10 ;
V_2 -> V_6 . V_9 =
F_50 ( V_15 -> V_19 ) ;
F_79 ( & V_2 -> V_6 . V_7 ) ;
}
}
if ( V_2 ) {
F_80 ( & V_2 -> V_113 ) ;
F_80 ( & V_2 -> V_139 ) ;
F_80 ( & V_2 -> V_114 ) ;
F_80 ( & V_2 -> V_149 ) ;
F_39 ( & V_15 -> V_150 , & V_2 -> V_149 ) ;
V_2 -> V_21 = V_15 ;
V_2 -> V_111 = V_15 -> V_111 ;
}
return V_2 ;
}
static void F_81 ( struct V_1 * V_2 )
{
struct V_22 * V_23 , * V_151 ;
struct V_78 * V_56 ;
T_2 V_125 ;
T_1 V_3 ;
F_25 (rdev, &net->devices, net_list) {
V_3 = V_23 -> V_3 ;
F_25 (rswitch, &net->switches, node) {
if ( F_33 ( V_23 ) && ( V_23 -> V_56 == V_56 ) )
continue;
if ( V_110 == V_56 -> V_109 [ V_3 ] ) {
V_151 = F_82 ( V_56 ) ;
if ( V_151 -> V_3 == V_3 )
continue;
V_125 = F_70 ( V_151 -> V_81 ) ;
if ( V_56 -> V_57 ) {
F_63 ( V_151 ,
V_112 , V_3 ,
V_125 , 0 ) ;
V_56 -> V_109 [ V_3 ] = V_125 ;
}
}
}
}
}
static void F_72 ( struct V_22 * V_23 )
{
if ( F_33 ( V_23 ) && ( V_23 -> V_97 ) &&
( V_23 -> V_56 -> V_152 ) ) {
V_23 -> V_56 -> V_152 ( V_23 ) ;
}
}
static void F_83 ( struct V_14 * V_15 , int V_153 )
{
if ( V_15 -> V_154 -> V_155 )
V_15 -> V_154 -> V_155 ( V_15 , V_153 ) ;
}
int F_84 ( struct V_14 * V_156 )
{
struct V_1 * V_2 = NULL ;
int V_134 = 0 ;
F_24 ( V_27 L_21 , V_156 -> V_111 ,
V_156 -> V_157 ) ;
if ( F_28 ( V_156 ) < 0 ) {
F_24 ( V_27
L_22 ,
V_156 -> V_111 ) ;
V_134 = - V_158 ;
goto V_159;
}
if ( F_75 ( V_156 ) ) {
V_2 = F_76 ( V_156 , 1 , 0 ) ;
if ( ! V_2 ) {
F_24 ( V_63 L_23 ) ;
V_134 = - V_160 ;
goto V_159;
}
F_6 ( V_2 , V_156 -> V_26 ) ;
F_41 ( V_156 , 1 , 0 , 0 , 0 ) ;
F_21 ( V_156 , V_103 ,
V_101 ++ ) ;
V_105 = F_1 ( V_2 ) ;
if ( F_67 ( V_2 , V_156 , 0 , NULL , 0 ) < 0 ) {
F_24 ( V_27
L_24 ,
V_156 -> V_111 ) ;
F_22 ( V_2 ) ;
V_134 = - V_158 ;
goto V_159;
}
F_8 ( V_2 , V_105 ) ;
F_81 ( V_2 ) ;
F_22 ( V_2 ) ;
F_83 ( V_156 , 1 ) ;
} else {
F_24 ( V_27 L_25 ,
V_156 -> V_111 ) ;
V_134 = - V_28 ;
}
V_159:
return V_134 ;
}
static void F_85 ( struct V_1 * V_2 )
{
struct V_78 * V_56 ;
struct V_22 * V_23 ;
int V_161 ;
T_2 V_125 ;
F_25 (rswitch, &net->switches, node) {
V_23 = F_82 ( V_56 ) ;
F_60 ( V_2 -> V_21 , V_23 -> V_3 ,
V_23 -> V_16 , 1000 ) ;
for ( V_161 = 0 ;
V_161 < F_50 ( V_2 -> V_21 -> V_19 ) ;
V_161 ++ ) {
if ( F_64 ( V_23 , V_112 ,
V_161 , & V_125 , 0 ) < 0 )
continue;
V_56 -> V_109 [ V_161 ] = V_125 ;
}
F_62 ( V_2 -> V_21 , V_23 -> V_3 , V_23 -> V_16 ) ;
}
}
int F_86 ( struct V_14 * V_156 )
{
struct V_1 * V_2 = NULL ;
unsigned long V_162 ;
F_24 ( V_27 L_26 , V_156 -> V_111 ,
V_156 -> V_157 ) ;
if ( F_75 ( V_156 ) ) {
F_35 ( L_27 ) ;
V_162 = V_163 + V_164 * V_165 ;
while ( F_87 ( V_163 , V_162 ) ) {
if ( F_73 ( V_156 ) )
goto V_166;
F_88 ( 10 ) ;
}
F_35 ( L_28 ,
V_156 -> V_111 , V_156 -> V_157 ) ;
goto V_167;
V_166:
F_35 ( L_29 ) ;
V_2 = F_76 ( V_156 , 0 , 0 ) ;
if ( ! V_2 ) {
F_24 ( V_63 L_30 ) ;
goto V_167;
}
F_23 ( V_156 , V_18 ,
& V_156 -> V_26 ) ;
V_156 -> V_26 = F_16 ( V_156 -> V_19 ,
V_156 -> V_26 ) ;
if ( F_74 ( V_2 , V_156 , F_66 ( V_156 -> V_19 ) ,
0 , NULL , 0 ) < 0 ) {
F_24 ( V_27
L_31 ,
V_156 -> V_111 ) ;
goto V_167;
}
F_85 ( V_2 ) ;
}
return 0 ;
V_167:
return - V_158 ;
}
