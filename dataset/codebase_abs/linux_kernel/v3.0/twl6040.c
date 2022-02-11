static inline unsigned int F_1 ( struct V_1 * V_2 ,
unsigned int V_3 )
{
T_1 * V_4 = V_2 -> V_5 ;
if ( V_3 >= V_6 )
return - V_7 ;
return V_4 [ V_3 ] ;
}
static inline void F_2 ( struct V_1 * V_2 ,
T_1 V_3 , T_1 V_8 )
{
T_1 * V_4 = V_2 -> V_5 ;
if ( V_3 >= V_6 )
return;
V_4 [ V_3 ] = V_8 ;
}
static int F_3 ( struct V_1 * V_2 ,
unsigned int V_3 )
{
T_1 V_8 ;
if ( V_3 >= V_6 )
return - V_7 ;
F_4 ( V_9 , & V_8 , V_3 ) ;
F_2 ( V_2 , V_3 , V_8 ) ;
return V_8 ;
}
static int F_5 ( struct V_1 * V_2 ,
unsigned int V_3 , unsigned int V_8 )
{
if ( V_3 >= V_6 )
return - V_7 ;
F_2 ( V_2 , V_3 , V_8 ) ;
return F_6 ( V_9 , V_8 , V_3 ) ;
}
static void F_7 ( struct V_1 * V_2 )
{
T_1 * V_4 = V_2 -> V_5 ;
int V_3 , V_10 ;
F_5 ( V_2 , V_11 , V_4 [ V_11 ] ) ;
for ( V_10 = 0 ; V_10 < V_12 ; V_10 ++ ) {
V_3 = V_13 [ V_10 ] ;
switch ( V_3 ) {
case V_14 :
case V_15 :
case V_16 :
continue;
default:
break;
}
F_5 ( V_2 , V_3 , V_4 [ V_3 ] ) ;
}
}
static void F_8 ( struct V_1 * V_2 )
{
T_1 * V_4 = V_2 -> V_5 ;
int V_3 , V_10 ;
for ( V_10 = 0 ; V_10 < V_17 ; V_10 ++ ) {
V_3 = V_18 [ V_10 ] ;
F_5 ( V_2 , V_3 , V_4 [ V_3 ] ) ;
}
}
static inline int F_9 ( struct V_1 * V_2 ,
unsigned int V_19 , unsigned int V_20 )
{
struct V_21 * V_22 = F_10 ( V_2 ) ;
struct V_23 * V_24 = & V_22 -> V_24 ;
int V_25 = 0 , V_26 = 0 ;
T_1 V_3 , V_27 ;
V_19 = ( V_19 > 0xF ) ? 0xF : V_19 ;
V_3 = F_1 ( V_2 , V_28 ) ;
V_27 = ( ~ V_3 & V_29 ) ;
if ( V_24 -> V_30 == V_31 ) {
if ( V_27 < V_24 -> V_32 ) {
V_27 += V_19 ;
V_3 &= ~ V_29 ;
F_5 ( V_2 , V_28 ,
( V_3 | ( ~ V_27 & V_29 ) ) ) ;
} else {
V_25 = 1 ;
}
} else if ( V_24 -> V_30 == V_33 ) {
if ( V_27 > 0x0 ) {
V_27 -= V_19 ;
V_3 &= ~ V_29 ;
F_5 ( V_2 , V_28 , V_3 |
( ~ V_27 & V_29 ) ) ;
} else {
V_25 = 1 ;
}
}
V_20 = ( V_20 > 0xF ) ? 0xF : V_20 ;
V_3 = F_1 ( V_2 , V_28 ) ;
V_27 = ( ~ V_3 & V_34 ) >> V_35 ;
if ( V_24 -> V_30 == V_31 ) {
if ( V_27 < V_24 -> V_36 ) {
V_27 += V_20 ;
V_3 &= ~ V_34 ;
F_5 ( V_2 , V_28 ,
( V_3 | ( ~ V_27 << V_35 ) ) ) ;
} else {
V_26 = 1 ;
}
} else if ( V_24 -> V_30 == V_33 ) {
if ( V_27 > 0x0 ) {
V_27 -= V_20 ;
V_3 &= ~ V_34 ;
F_5 ( V_2 , V_28 ,
V_3 | ( ~ V_27 << V_35 ) ) ;
} else {
V_26 = 1 ;
}
}
return V_25 & V_26 ;
}
static inline int F_11 ( struct V_1 * V_2 ,
unsigned int V_19 , unsigned int V_20 )
{
struct V_21 * V_22 = F_10 ( V_2 ) ;
struct V_23 * V_37 = & V_22 -> V_37 ;
int V_25 = 0 , V_26 = 0 ;
T_2 V_3 , V_27 ;
V_19 = ( V_19 > 0x1D ) ? 0x1D : V_19 ;
V_3 = F_1 ( V_2 , V_38 ) ;
V_3 = 0x1D - V_3 ;
V_27 = ( V_3 & V_39 ) ;
if ( V_37 -> V_30 == V_31 ) {
if ( V_27 < V_37 -> V_32 ) {
V_27 += V_19 ;
V_3 &= ~ V_39 ;
F_5 ( V_2 , V_38 ,
V_3 | ( 0x1D - V_27 ) ) ;
} else {
V_25 = 1 ;
}
} else if ( V_37 -> V_30 == V_33 ) {
if ( V_27 > 0 ) {
V_27 -= V_19 ;
V_3 &= ~ V_39 ;
F_5 ( V_2 , V_38 ,
V_3 | ( 0x1D - V_27 ) ) ;
} else {
V_25 = 1 ;
}
}
V_20 = ( V_20 > 0x1D ) ? 0x1D : V_20 ;
V_3 = F_1 ( V_2 , V_40 ) ;
V_3 = 0x1D - V_3 ;
V_27 = ( V_3 & V_39 ) ;
if ( V_37 -> V_30 == V_31 ) {
if ( V_27 < V_37 -> V_36 ) {
V_27 += V_20 ;
V_3 &= ~ V_39 ;
F_5 ( V_2 , V_40 ,
V_3 | ( 0x1D - V_27 ) ) ;
} else {
V_26 = 1 ;
}
} else if ( V_37 -> V_30 == V_33 ) {
if ( V_27 > 0 ) {
V_27 -= V_20 ;
V_3 &= ~ V_39 ;
F_5 ( V_2 , V_40 ,
V_3 | ( 0x1D - V_27 ) ) ;
}
}
return V_25 & V_26 ;
}
static void F_12 ( struct V_41 * V_42 )
{
struct V_21 * V_22 =
F_13 ( V_42 , struct V_21 , V_43 . V_42 ) ;
struct V_1 * V_2 = V_22 -> V_2 ;
struct V_23 * V_24 = & V_22 -> V_24 ;
unsigned int V_44 = V_24 -> V_45 ;
int V_10 , V_46 ;
if ( V_24 -> V_30 == V_47 )
return;
for ( V_10 = 0 ; V_10 <= 16 ; V_10 ++ ) {
V_46 = 1 ;
if ( V_24 -> V_30 != V_47 )
V_46 = F_9 ( V_2 ,
V_24 -> V_19 ,
V_24 -> V_20 ) ;
if ( V_46 )
break;
if ( V_10 >= 8 )
F_14 ( F_15 ( V_44 +
( V_44 >> 1 ) ) ) ;
else
F_14 ( F_15 ( V_44 ) ) ;
}
if ( V_24 -> V_30 == V_33 ) {
V_24 -> V_48 = 0 ;
F_16 ( & V_24 -> V_49 ) ;
} else {
V_24 -> V_48 = 1 ;
}
V_24 -> V_30 = V_47 ;
}
static void F_17 ( struct V_41 * V_42 )
{
struct V_21 * V_22 =
F_13 ( V_42 , struct V_21 , V_50 . V_42 ) ;
struct V_1 * V_2 = V_22 -> V_2 ;
struct V_23 * V_37 = & V_22 -> V_37 ;
unsigned int V_44 = V_37 -> V_45 ;
int V_10 , V_51 ;
if ( V_37 -> V_30 == V_47 )
return;
for ( V_10 = 0 ; V_10 <= 32 ; V_10 ++ ) {
V_51 = 1 ;
if ( V_37 -> V_30 != V_47 )
V_51 = F_11 ( V_2 ,
V_37 -> V_19 ,
V_37 -> V_20 ) ;
if ( V_51 )
break;
if ( V_10 >= 16 )
F_14 ( F_15 ( V_44 +
( V_44 >> 1 ) ) ) ;
else
F_14 ( F_15 ( V_44 ) ) ;
}
if ( V_37 -> V_30 == V_33 ) {
V_37 -> V_48 = 0 ;
F_16 ( & V_37 -> V_49 ) ;
} else
V_37 -> V_48 = 1 ;
V_37 -> V_30 = V_47 ;
}
static int F_18 ( struct V_52 * V_53 ,
struct V_54 * V_55 , int V_56 )
{
struct V_1 * V_2 = V_53 -> V_2 ;
struct V_21 * V_22 = F_10 ( V_2 ) ;
struct V_23 * V_57 ;
struct V_58 * V_42 ;
struct V_59 * V_60 ;
switch ( V_53 -> V_61 ) {
case 2 :
case 3 :
V_57 = & V_22 -> V_24 ;
V_42 = & V_22 -> V_43 ;
V_60 = V_22 -> V_62 ;
V_57 -> V_45 = 5 ;
break;
case 4 :
V_57 = & V_22 -> V_37 ;
V_42 = & V_22 -> V_50 ;
V_60 = V_22 -> V_63 ;
V_57 -> V_45 = 5 ;
if ( F_19 ( V_56 ) )
V_22 -> V_64 ++ ;
else
V_22 -> V_64 -- ;
break;
default:
return - 1 ;
}
switch ( V_56 ) {
case V_65 :
if ( V_57 -> V_48 )
break;
V_57 -> V_19 = V_57 -> V_32 ;
V_57 -> V_20 = V_57 -> V_36 ;
if ( ! F_20 ( V_42 ) ) {
V_57 -> V_30 = V_31 ;
F_21 ( V_60 , V_42 ,
F_15 ( 1 ) ) ;
}
break;
case V_66 :
if ( ! V_57 -> V_48 )
break;
if ( ! F_20 ( V_42 ) ) {
V_57 -> V_19 = 1 ;
V_57 -> V_20 = 1 ;
V_57 -> V_30 = V_33 ;
F_22 ( V_57 -> V_49 ) ;
F_21 ( V_60 , V_42 ,
F_15 ( 1 ) ) ;
F_23 ( & V_57 -> V_49 ,
F_15 ( 2000 ) ) ;
}
break;
}
return 0 ;
}
static void F_24 ( struct V_1 * V_2 )
{
T_1 V_67 , V_68 , V_69 , V_70 ;
V_67 = F_1 ( V_2 , V_71 ) ;
V_68 = F_1 ( V_2 , V_72 ) ;
V_69 = F_1 ( V_2 , V_73 ) ;
V_70 = F_1 ( V_2 , V_11 ) ;
V_68 |= V_74 ;
F_5 ( V_2 , V_72 , V_68 ) ;
F_25 ( 10 ) ;
V_68 |= V_75 ;
F_5 ( V_2 , V_72 , V_68 ) ;
F_26 ( 10 ) ;
V_68 |= V_76 ;
F_5 ( V_2 , V_72 , V_68 ) ;
F_26 ( 244 ) ;
V_67 |= V_77 | V_78 ;
F_5 ( V_2 , V_71 , V_67 ) ;
F_26 ( 488 ) ;
V_68 |= V_79 ;
F_5 ( V_2 , V_72 , V_68 ) ;
F_26 ( 244 ) ;
V_69 |= V_80 ;
F_5 ( V_2 , V_73 , V_69 ) ;
V_70 |= V_81 ;
F_5 ( V_2 , V_11 , V_70 ) ;
F_27 ( 5 ) ;
V_70 &= ~ V_81 ;
F_5 ( V_2 , V_11 , V_70 ) ;
V_68 &= ~ V_75 ;
F_5 ( V_2 , V_72 , V_68 ) ;
}
static void F_28 ( struct V_1 * V_2 )
{
T_1 V_67 , V_68 , V_69 , V_70 ;
V_67 = F_1 ( V_2 , V_71 ) ;
V_68 = F_1 ( V_2 , V_72 ) ;
V_69 = F_1 ( V_2 , V_73 ) ;
V_70 = F_1 ( V_2 , V_11 ) ;
V_68 |= V_75 ;
F_5 ( V_2 , V_72 , V_68 ) ;
F_26 ( 10 ) ;
V_69 &= ~ V_80 ;
F_5 ( V_2 , V_73 , V_69 ) ;
V_68 &= ~ V_79 ;
F_5 ( V_2 , V_72 , V_68 ) ;
F_26 ( 244 ) ;
V_67 &= ~ ( V_77 | V_78 ) ;
F_5 ( V_2 , V_71 , V_67 ) ;
F_26 ( 488 ) ;
V_68 &= ~ V_76 ;
F_5 ( V_2 , V_72 , V_68 ) ;
F_26 ( 244 ) ;
V_68 &= ~ V_75 ;
F_5 ( V_2 , V_72 , V_68 ) ;
V_68 &= ~ V_74 ;
F_5 ( V_2 , V_72 , V_68 ) ;
F_25 ( 10 ) ;
}
static int F_29 ( struct V_1 * V_2 , int V_82 )
{
int V_83 , V_84 ;
int V_85 = V_86 | V_87 ;
V_83 = F_1 ( V_2 , V_88 ) ;
V_84 = F_1 ( V_2 , V_89 ) ;
if ( V_82 ) {
V_83 &= ~ V_85 ;
V_84 &= ~ V_85 ;
} else {
V_83 |= V_85 ;
V_84 |= V_85 ;
}
F_5 ( V_2 , V_88 , V_83 ) ;
F_5 ( V_2 , V_89 , V_84 ) ;
return 0 ;
}
static int F_30 ( struct V_52 * V_53 ,
struct V_54 * V_55 , int V_56 )
{
F_25 ( 1 ) ;
return 0 ;
}
static int F_31 ( struct V_52 * V_53 ,
struct V_54 * V_55 , int V_56 )
{
struct V_1 * V_2 = V_53 -> V_2 ;
struct V_21 * V_22 = F_10 ( V_2 ) ;
if ( F_19 ( V_56 ) )
V_22 -> V_64 ++ ;
else
V_22 -> V_64 -- ;
F_25 ( 1 ) ;
return 0 ;
}
static void F_32 ( struct V_1 * V_2 ,
struct V_90 * V_91 , int V_92 )
{
struct V_21 * V_22 = F_10 ( V_2 ) ;
int V_93 ;
F_33 ( & V_22 -> V_94 ) ;
V_93 = F_3 ( V_2 , V_16 ) ;
if ( V_93 & V_95 )
F_34 ( V_91 , V_92 , V_92 ) ;
else
F_34 ( V_91 , 0 , V_92 ) ;
F_35 ( & V_22 -> V_94 ) ;
}
void F_36 ( struct V_1 * V_2 ,
struct V_90 * V_91 , int V_92 )
{
struct V_21 * V_22 = F_10 ( V_2 ) ;
struct V_96 * V_97 = & V_22 -> V_97 ;
V_97 -> V_91 = V_91 ;
V_97 -> V_92 = V_92 ;
F_32 ( V_2 , V_97 -> V_91 , V_97 -> V_92 ) ;
}
static void F_37 ( struct V_41 * V_42 )
{
struct V_21 * V_22 = F_13 ( V_42 ,
struct V_21 , V_58 . V_42 ) ;
struct V_1 * V_2 = V_22 -> V_2 ;
struct V_96 * V_97 = & V_22 -> V_97 ;
F_32 ( V_2 , V_97 -> V_91 , V_97 -> V_92 ) ;
}
static T_3 F_38 ( int V_98 , void * V_99 )
{
struct V_1 * V_2 = V_99 ;
struct V_21 * V_22 = F_10 ( V_2 ) ;
T_1 V_100 ;
F_4 ( V_9 , & V_100 , V_101 ) ;
if ( V_100 & V_102 )
F_39 ( V_2 -> V_103 , L_1 ) ;
if ( ( V_100 & V_104 ) || ( V_100 & V_105 ) )
F_21 ( V_22 -> V_106 , & V_22 -> V_58 ,
F_15 ( 200 ) ) ;
if ( V_100 & V_107 )
F_40 ( V_2 -> V_103 , L_2 ) ;
if ( V_100 & V_108 )
F_39 ( V_2 -> V_103 , L_3 ) ;
if ( V_100 & V_109 )
F_39 ( V_2 -> V_103 , L_4 ) ;
if ( V_100 & V_110 )
F_16 ( & V_22 -> V_111 ) ;
return V_112 ;
}
static int F_41 ( struct V_54 * V_55 ,
struct V_113 * V_114 )
{
struct V_1 * V_2 = F_42 ( V_55 ) ;
struct V_21 * V_115 = F_10 ( V_2 ) ;
struct V_23 * V_57 = NULL ;
struct V_116 * V_117 =
(struct V_116 * ) V_55 -> V_118 ;
int V_119 ;
unsigned int V_3 = V_117 -> V_3 ;
switch ( V_3 ) {
case V_28 :
V_57 = & V_115 -> V_24 ;
break;
default:
break;
}
if ( V_57 ) {
V_57 -> V_32 = V_114 -> V_8 . integer . V_8 [ 0 ] ;
V_57 -> V_36 = V_114 -> V_8 . integer . V_8 [ 1 ] ;
if ( ! V_57 -> V_48 )
return 1 ;
}
V_119 = F_43 ( V_55 , V_114 ) ;
if ( V_119 < 0 )
return V_119 ;
return 1 ;
}
static int F_44 ( struct V_54 * V_55 ,
struct V_113 * V_114 )
{
struct V_1 * V_2 = F_42 ( V_55 ) ;
struct V_21 * V_115 = F_10 ( V_2 ) ;
struct V_23 * V_57 = & V_115 -> V_24 ;
struct V_116 * V_117 =
(struct V_116 * ) V_55 -> V_118 ;
unsigned int V_3 = V_117 -> V_3 ;
switch ( V_3 ) {
case V_28 :
V_57 = & V_115 -> V_24 ;
V_114 -> V_8 . integer . V_8 [ 0 ] = V_57 -> V_32 ;
V_114 -> V_8 . integer . V_8 [ 1 ] = V_57 -> V_36 ;
return 0 ;
default:
break;
}
return F_45 ( V_55 , V_114 ) ;
}
static int F_46 ( struct V_54 * V_55 ,
struct V_113 * V_114 )
{
struct V_1 * V_2 = F_42 ( V_55 ) ;
struct V_21 * V_115 = F_10 ( V_2 ) ;
struct V_23 * V_57 = NULL ;
struct V_116 * V_117 =
(struct V_116 * ) V_55 -> V_118 ;
int V_119 ;
unsigned int V_3 = V_117 -> V_3 ;
switch ( V_3 ) {
case V_38 :
case V_40 :
V_57 = & V_115 -> V_37 ;
break;
default:
break;
}
if ( V_57 ) {
V_57 -> V_32 = V_114 -> V_8 . integer . V_8 [ 0 ] ;
V_57 -> V_36 = V_114 -> V_8 . integer . V_8 [ 1 ] ;
if ( ! V_57 -> V_48 )
return 1 ;
}
V_119 = F_47 ( V_55 , V_114 ) ;
if ( V_119 < 0 )
return V_119 ;
return 1 ;
}
static int F_48 ( struct V_54 * V_55 ,
struct V_113 * V_114 )
{
struct V_1 * V_2 = F_42 ( V_55 ) ;
struct V_21 * V_115 = F_10 ( V_2 ) ;
struct V_23 * V_57 = & V_115 -> V_37 ;
struct V_116 * V_117 =
(struct V_116 * ) V_55 -> V_118 ;
unsigned int V_3 = V_117 -> V_3 ;
switch ( V_3 ) {
case V_38 :
case V_40 :
V_57 = & V_115 -> V_37 ;
V_114 -> V_8 . integer . V_8 [ 0 ] = V_57 -> V_32 ;
V_114 -> V_8 . integer . V_8 [ 1 ] = V_57 -> V_36 ;
return 0 ;
default:
break;
}
return F_49 ( V_55 , V_114 ) ;
}
static int F_50 ( struct V_1 * V_2 )
{
struct V_120 * V_121 = & V_2 -> V_121 ;
F_51 ( V_121 , V_122 ,
F_52 ( V_122 ) ) ;
F_53 ( V_121 , V_123 , F_52 ( V_123 ) ) ;
F_54 ( V_121 ) ;
return 0 ;
}
static int F_55 ( struct V_1 * V_2 ,
int V_124 )
{
struct V_21 * V_22 = F_10 ( V_2 ) ;
int V_125 ;
T_1 V_100 ;
V_125 = F_23 ( & V_22 -> V_111 ,
F_15 ( 144 ) ) ;
if ( ! V_125 ) {
F_4 ( V_9 , & V_100 ,
V_101 ) ;
if ( ! ( V_100 & V_110 ) ) {
F_56 ( V_2 -> V_103 , L_5 ) ;
return - V_126 ;
}
}
V_22 -> V_127 = 1 ;
return 0 ;
}
static int F_57 ( struct V_1 * V_2 ,
enum V_128 V_129 )
{
struct V_21 * V_22 = F_10 ( V_2 ) ;
int V_130 = V_22 -> V_130 ;
int V_124 = V_22 -> V_124 ;
int V_119 ;
switch ( V_129 ) {
case V_131 :
break;
case V_132 :
break;
case V_133 :
if ( V_22 -> V_127 )
break;
if ( F_58 ( V_130 ) ) {
F_59 ( V_130 , 1 ) ;
V_119 = F_55 ( V_2 , V_124 ) ;
if ( V_119 )
return V_119 ;
F_3 ( V_2 , V_71 ) ;
F_3 ( V_2 , V_72 ) ;
F_3 ( V_2 , V_73 ) ;
} else {
F_24 ( V_2 ) ;
V_22 -> V_127 = 1 ;
}
F_8 ( V_2 ) ;
F_5 ( V_2 , V_134 , 0x02 ) ;
F_5 ( V_2 , V_28 , 0xFF ) ;
F_5 ( V_2 , V_135 , 0x1E ) ;
F_5 ( V_2 , V_38 , 0x1D ) ;
F_5 ( V_2 , V_40 , 0x1D ) ;
break;
case V_136 :
if ( ! V_22 -> V_127 )
break;
if ( F_58 ( V_130 ) ) {
F_59 ( V_130 , 0 ) ;
F_26 ( 500 ) ;
F_3 ( V_2 , V_71 ) ;
F_3 ( V_2 , V_72 ) ;
F_2 ( V_2 , V_73 ,
0x00 ) ;
} else {
F_28 ( V_2 ) ;
}
V_22 -> V_127 = 0 ;
break;
}
V_2 -> V_121 . V_137 = V_129 ;
return 0 ;
}
static int F_60 ( struct V_138 * V_139 ,
struct V_140 * V_141 )
{
struct V_142 * V_143 = V_139 -> V_144 ;
struct V_1 * V_2 = V_143 -> V_2 ;
struct V_21 * V_22 = F_10 ( V_2 ) ;
F_61 ( V_139 -> V_145 , 0 ,
V_146 ,
V_22 -> V_147 ) ;
return 0 ;
}
static int F_62 ( struct V_138 * V_139 ,
struct V_148 * V_149 ,
struct V_140 * V_141 )
{
struct V_142 * V_143 = V_139 -> V_144 ;
struct V_1 * V_2 = V_143 -> V_2 ;
struct V_21 * V_22 = F_10 ( V_2 ) ;
T_1 V_69 ;
int V_150 ;
if ( V_22 -> V_151 == V_152 )
return 0 ;
V_69 = F_1 ( V_2 , V_73 ) ;
V_150 = F_63 ( V_149 ) ;
switch ( V_150 ) {
case 11250 :
case 22500 :
case 44100 :
case 88200 :
V_69 |= V_153 ;
V_22 -> V_154 = 17640000 ;
break;
case 8000 :
case 16000 :
case 32000 :
case 48000 :
case 96000 :
V_69 &= ~ V_153 ;
V_22 -> V_154 = 19200000 ;
break;
default:
F_56 ( V_2 -> V_103 , L_6 , V_150 ) ;
return - V_155 ;
}
F_5 ( V_2 , V_73 , V_69 ) ;
return 0 ;
}
static int F_64 ( struct V_138 * V_139 ,
struct V_140 * V_141 )
{
struct V_142 * V_143 = V_139 -> V_144 ;
struct V_1 * V_2 = V_143 -> V_2 ;
struct V_21 * V_22 = F_10 ( V_2 ) ;
if ( ! V_22 -> V_154 ) {
F_56 ( V_2 -> V_103 ,
L_7 ) ;
return - V_155 ;
}
if ( ( V_22 -> V_154 == 17640000 ) &&
V_139 -> V_156 == V_157 ) {
F_56 ( V_2 -> V_103 ,
L_8 ,
V_22 -> V_154 ) ;
return - V_155 ;
}
if ( ( V_22 -> V_154 == 17640000 ) && V_22 -> V_64 ) {
F_56 ( V_2 -> V_103 ,
L_9 ,
V_22 -> V_154 ) ;
return - V_158 ;
}
return 0 ;
}
static int F_65 ( struct V_140 * V_159 ,
int V_160 , unsigned int V_161 , int V_162 )
{
struct V_1 * V_2 = V_159 -> V_2 ;
struct V_21 * V_22 = F_10 ( V_2 ) ;
T_1 V_163 , V_69 ;
V_163 = F_1 ( V_2 , V_164 ) ;
V_69 = F_1 ( V_2 , V_73 ) ;
switch ( V_160 ) {
case V_165 :
switch ( V_161 ) {
case 32768 :
F_29 ( V_2 , 0 ) ;
V_69 |= V_80 ;
F_5 ( V_2 , V_73 , V_69 ) ;
F_27 ( 5 ) ;
V_69 &= ~ V_166 ;
F_5 ( V_2 , V_73 , V_69 ) ;
V_163 &= ~ V_167 ;
F_5 ( V_2 , V_164 , V_163 ) ;
break;
default:
F_56 ( V_2 -> V_103 , L_10 , V_161 ) ;
return - V_155 ;
}
switch ( V_22 -> V_154 ) {
case 17640000 :
V_69 |= V_153 ;
break;
case 19200000 :
V_69 &= ~ V_153 ;
break;
default:
V_69 &= ~ V_153 ;
V_22 -> V_154 = 19200000 ;
break;
}
F_5 ( V_2 , V_73 , V_69 ) ;
V_22 -> V_151 = V_168 ;
V_22 -> V_147 = & V_169 ;
break;
case V_170 :
V_163 &= ~ V_171 ;
switch ( V_161 ) {
case 12000000 :
V_163 |= V_172 |
V_173 |
V_167 ;
break;
case 19200000 :
V_163 |= V_174 |
V_175 |
V_176 ;
break;
case 26000000 :
V_163 |= V_177 |
V_173 |
V_167 ;
break;
case 38400000 :
V_163 |= V_178 |
V_175 |
V_176 ;
break;
default:
F_56 ( V_2 -> V_103 , L_10 , V_161 ) ;
return - V_155 ;
}
F_29 ( V_2 , 1 ) ;
F_5 ( V_2 , V_164 , V_163 ) ;
F_26 ( 500 ) ;
V_69 |= V_166 ;
F_5 ( V_2 , V_73 , V_69 ) ;
V_69 &= ~ V_80 ;
F_5 ( V_2 , V_73 , V_69 ) ;
V_22 -> V_151 = V_152 ;
V_22 -> V_154 = 19200000 ;
V_22 -> V_147 = & V_179 ;
break;
default:
F_56 ( V_2 -> V_103 , L_11 , V_160 ) ;
return - V_155 ;
}
return 0 ;
}
static int F_66 ( struct V_1 * V_2 , T_4 V_180 )
{
F_57 ( V_2 , V_136 ) ;
return 0 ;
}
static int F_67 ( struct V_1 * V_2 )
{
F_57 ( V_2 , V_133 ) ;
F_57 ( V_2 , V_2 -> V_121 . V_181 ) ;
return 0 ;
}
static int F_68 ( struct V_1 * V_2 )
{
struct V_182 * V_183 = V_2 -> V_103 -> V_184 ;
struct V_21 * V_22 ;
int V_130 , V_124 ;
int V_119 = 0 ;
T_1 V_185 , V_186 = V_187 ;
V_22 = F_69 ( sizeof( struct V_21 ) , V_188 ) ;
if ( V_22 == NULL )
return - V_189 ;
F_70 ( V_2 , V_22 ) ;
V_22 -> V_2 = V_2 ;
F_4 ( V_9 , & V_185 , V_15 ) ;
if ( V_183 && ( V_185 > 0 ) )
V_130 = V_183 -> V_190 ;
else
V_130 = - V_155 ;
if ( V_183 )
V_124 = V_183 -> V_191 ;
else
V_124 = 0 ;
V_22 -> V_130 = V_130 ;
V_22 -> V_124 = V_124 ;
V_22 -> V_106 = F_71 ( L_12 ) ;
if ( ! V_22 -> V_106 ) {
V_119 = - V_189 ;
goto V_192;
}
F_72 ( & V_22 -> V_58 , F_37 ) ;
F_73 ( & V_22 -> V_94 ) ;
F_74 ( & V_22 -> V_111 ) ;
F_74 ( & V_22 -> V_24 . V_49 ) ;
F_74 ( & V_22 -> V_37 . V_49 ) ;
if ( F_58 ( V_130 ) ) {
V_119 = F_75 ( V_130 , L_13 ) ;
if ( V_119 )
goto V_193;
V_119 = F_76 ( V_130 , 0 ) ;
if ( V_119 )
goto V_194;
V_22 -> V_127 = 0 ;
V_186 &= ~ ( V_195 | V_196 ) ;
F_3 ( V_2 , V_101 ) ;
}
F_5 ( V_2 , V_197 , V_186 ) ;
if ( V_124 ) {
V_119 = F_77 ( V_124 , NULL ,
F_38 ,
V_198 | V_199 ,
L_14 , V_2 ) ;
if ( V_119 )
goto V_194;
}
F_7 ( V_2 ) ;
V_22 -> V_63 = F_71 ( L_15 ) ;
if ( V_22 -> V_63 == NULL ) {
V_119 = - V_189 ;
goto V_200;
}
V_22 -> V_62 = F_71 ( L_16 ) ;
if ( V_22 -> V_62 == NULL ) {
V_119 = - V_189 ;
goto V_201;
}
F_72 ( & V_22 -> V_43 , F_12 ) ;
F_72 ( & V_22 -> V_50 , F_17 ) ;
V_119 = F_57 ( V_2 , V_133 ) ;
if ( V_119 )
goto V_202;
F_78 ( V_2 , V_203 ,
F_52 ( V_203 ) ) ;
F_50 ( V_2 ) ;
return 0 ;
V_202:
F_79 ( V_22 -> V_62 ) ;
V_201:
F_79 ( V_22 -> V_63 ) ;
V_200:
if ( V_124 )
F_80 ( V_124 , V_2 ) ;
V_194:
if ( F_58 ( V_130 ) )
F_81 ( V_130 ) ;
V_193:
F_79 ( V_22 -> V_106 ) ;
V_192:
F_82 ( V_22 ) ;
return V_119 ;
}
static int F_83 ( struct V_1 * V_2 )
{
struct V_21 * V_22 = F_10 ( V_2 ) ;
int V_130 = V_22 -> V_130 ;
int V_124 = V_22 -> V_124 ;
F_57 ( V_2 , V_136 ) ;
if ( F_58 ( V_130 ) )
F_81 ( V_130 ) ;
if ( V_124 )
F_80 ( V_124 , V_2 ) ;
F_79 ( V_22 -> V_106 ) ;
F_79 ( V_22 -> V_63 ) ;
F_79 ( V_22 -> V_62 ) ;
F_82 ( V_22 ) ;
return 0 ;
}
static int T_5 F_84 ( struct V_204 * V_205 )
{
return F_85 ( & V_205 -> V_103 ,
& V_206 , & V_207 , 1 ) ;
}
static int T_6 F_86 ( struct V_204 * V_205 )
{
F_87 ( & V_205 -> V_103 ) ;
return 0 ;
}
static int T_7 F_88 ( void )
{
return F_89 ( & V_208 ) ;
}
static void T_8 F_90 ( void )
{
F_91 ( & V_208 ) ;
}
