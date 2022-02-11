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
struct V_9 * V_9 = V_2 -> V_10 ;
T_1 V_8 ;
if ( V_3 >= V_6 )
return - V_7 ;
V_8 = F_4 ( V_9 , V_3 ) ;
F_2 ( V_2 , V_3 , V_8 ) ;
return V_8 ;
}
static int F_5 ( struct V_1 * V_2 ,
unsigned int V_3 , unsigned int V_8 )
{
struct V_9 * V_9 = V_2 -> V_10 ;
if ( V_3 >= V_6 )
return - V_7 ;
F_2 ( V_2 , V_3 , V_8 ) ;
return F_6 ( V_9 , V_3 , V_8 ) ;
}
static void F_7 ( struct V_1 * V_2 )
{
T_1 * V_4 = V_2 -> V_5 ;
int V_3 , V_11 ;
for ( V_11 = 0 ; V_11 < V_12 ; V_11 ++ ) {
V_3 = V_13 [ V_11 ] ;
switch ( V_3 ) {
case V_14 :
case V_15 :
case V_16 :
case V_17 :
case V_18 :
case V_19 :
case V_20 :
case V_21 :
case V_22 :
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
int V_3 , V_11 ;
for ( V_11 = 0 ; V_11 < V_23 ; V_11 ++ ) {
V_3 = V_24 [ V_11 ] ;
switch ( V_3 ) {
case V_25 :
case V_26 :
case V_27 :
case V_28 :
case V_29 :
case V_30 :
case V_31 :
continue;
default:
break;
}
F_5 ( V_2 , V_3 , V_4 [ V_3 ] ) ;
}
}
static inline int F_9 ( struct V_1 * V_2 ,
unsigned int V_32 , unsigned int V_33 )
{
struct V_34 * V_35 = F_10 ( V_2 ) ;
struct V_36 * V_37 = & V_35 -> V_37 ;
int V_38 = 0 , V_39 = 0 ;
T_1 V_3 , V_40 ;
V_32 = ( V_32 > 0xF ) ? 0xF : V_32 ;
V_3 = F_1 ( V_2 , V_41 ) ;
V_40 = ( ~ V_3 & V_42 ) ;
if ( V_37 -> V_43 == V_44 ) {
if ( V_40 < V_37 -> V_45 ) {
if ( V_40 + V_32 > V_37 -> V_45 )
V_40 = V_37 -> V_45 ;
else
V_40 += V_32 ;
V_3 &= ~ V_42 ;
F_5 ( V_2 , V_41 ,
( V_3 | ( ~ V_40 & V_42 ) ) ) ;
} else {
V_38 = 1 ;
}
} else if ( V_37 -> V_43 == V_46 ) {
if ( V_40 > 0x0 ) {
if ( ( int ) V_40 - ( int ) V_32 < 0 )
V_40 = 0 ;
else
V_40 -= V_32 ;
V_3 &= ~ V_42 ;
F_5 ( V_2 , V_41 , V_3 |
( ~ V_40 & V_42 ) ) ;
} else {
V_38 = 1 ;
}
}
V_33 = ( V_33 > 0xF ) ? 0xF : V_33 ;
V_3 = F_1 ( V_2 , V_41 ) ;
V_40 = ( ~ V_3 & V_47 ) >> V_48 ;
if ( V_37 -> V_43 == V_44 ) {
if ( V_40 < V_37 -> V_49 ) {
if ( V_40 + V_33 > V_37 -> V_49 )
V_40 = V_37 -> V_49 ;
else
V_40 += V_33 ;
V_3 &= ~ V_47 ;
F_5 ( V_2 , V_41 ,
( V_3 | ( ~ V_40 << V_48 ) ) ) ;
} else {
V_39 = 1 ;
}
} else if ( V_37 -> V_43 == V_46 ) {
if ( V_40 > 0x0 ) {
if ( ( int ) V_40 - ( int ) V_33 < 0 )
V_40 = 0 ;
else
V_40 -= V_33 ;
V_3 &= ~ V_47 ;
F_5 ( V_2 , V_41 ,
V_3 | ( ~ V_40 << V_48 ) ) ;
} else {
V_39 = 1 ;
}
}
return V_38 & V_39 ;
}
static inline int F_11 ( struct V_1 * V_2 ,
unsigned int V_32 , unsigned int V_33 )
{
struct V_34 * V_35 = F_10 ( V_2 ) ;
struct V_36 * V_50 = & V_35 -> V_50 ;
int V_38 = 0 , V_39 = 0 ;
T_2 V_3 , V_40 ;
V_32 = ( V_32 > 0x1D ) ? 0x1D : V_32 ;
V_3 = F_1 ( V_2 , V_51 ) ;
V_3 = 0x1D - V_3 ;
V_40 = ( V_3 & V_52 ) ;
if ( V_50 -> V_43 == V_44 ) {
if ( V_40 < V_50 -> V_45 ) {
if ( V_40 + V_32 > V_50 -> V_45 )
V_40 = V_50 -> V_45 ;
else
V_40 += V_32 ;
V_3 &= ~ V_52 ;
F_5 ( V_2 , V_51 ,
V_3 | ( 0x1D - V_40 ) ) ;
} else {
V_38 = 1 ;
}
} else if ( V_50 -> V_43 == V_46 ) {
if ( V_40 > 0 ) {
if ( ( int ) V_40 - ( int ) V_32 < 0 )
V_40 = 0 ;
else
V_40 -= V_32 ;
V_3 &= ~ V_52 ;
F_5 ( V_2 , V_51 ,
V_3 | ( 0x1D - V_40 ) ) ;
} else {
V_38 = 1 ;
}
}
V_33 = ( V_33 > 0x1D ) ? 0x1D : V_33 ;
V_3 = F_1 ( V_2 , V_53 ) ;
V_3 = 0x1D - V_3 ;
V_40 = ( V_3 & V_52 ) ;
if ( V_50 -> V_43 == V_44 ) {
if ( V_40 < V_50 -> V_49 ) {
if ( V_40 + V_33 > V_50 -> V_49 )
V_40 = V_50 -> V_49 ;
else
V_40 += V_33 ;
V_3 &= ~ V_52 ;
F_5 ( V_2 , V_53 ,
V_3 | ( 0x1D - V_40 ) ) ;
} else {
V_39 = 1 ;
}
} else if ( V_50 -> V_43 == V_46 ) {
if ( V_40 > 0 ) {
if ( ( int ) V_40 - ( int ) V_33 < 0 )
V_40 = 0 ;
else
V_40 -= V_33 ;
V_3 &= ~ V_52 ;
F_5 ( V_2 , V_53 ,
V_3 | ( 0x1D - V_40 ) ) ;
}
}
return V_38 & V_39 ;
}
static void F_12 ( struct V_54 * V_55 )
{
struct V_34 * V_35 =
F_13 ( V_55 , struct V_34 , V_56 . V_55 ) ;
struct V_1 * V_2 = V_35 -> V_2 ;
struct V_36 * V_37 = & V_35 -> V_37 ;
unsigned int V_57 = V_37 -> V_58 ;
int V_11 , V_59 ;
if ( V_37 -> V_43 == V_60 )
return;
for ( V_11 = 0 ; V_11 <= 16 ; V_11 ++ ) {
V_59 = F_9 ( V_2 ,
V_37 -> V_32 ,
V_37 -> V_33 ) ;
if ( V_59 )
break;
if ( V_11 >= 8 )
F_14 ( F_15 ( V_57 +
( V_57 >> 1 ) ) ) ;
else
F_14 ( F_15 ( V_57 ) ) ;
}
if ( V_37 -> V_43 == V_46 ) {
V_37 -> V_61 = 0 ;
F_16 ( & V_37 -> V_62 ) ;
} else {
V_37 -> V_61 = 1 ;
}
V_37 -> V_43 = V_60 ;
}
static void F_17 ( struct V_54 * V_55 )
{
struct V_34 * V_35 =
F_13 ( V_55 , struct V_34 , V_63 . V_55 ) ;
struct V_1 * V_2 = V_35 -> V_2 ;
struct V_36 * V_50 = & V_35 -> V_50 ;
unsigned int V_57 = V_50 -> V_58 ;
int V_11 , V_64 ;
if ( V_50 -> V_43 == V_60 )
return;
for ( V_11 = 0 ; V_11 <= 32 ; V_11 ++ ) {
V_64 = F_11 ( V_2 ,
V_50 -> V_32 ,
V_50 -> V_33 ) ;
if ( V_64 )
break;
if ( V_11 >= 16 )
F_14 ( F_15 ( V_57 +
( V_57 >> 1 ) ) ) ;
else
F_14 ( F_15 ( V_57 ) ) ;
}
if ( V_50 -> V_43 == V_46 ) {
V_50 -> V_61 = 0 ;
F_16 ( & V_50 -> V_62 ) ;
} else
V_50 -> V_61 = 1 ;
V_50 -> V_43 = V_60 ;
}
static int F_18 ( struct V_65 * V_66 ,
struct V_67 * V_68 , int V_69 )
{
struct V_1 * V_2 = V_66 -> V_2 ;
struct V_34 * V_35 = F_10 ( V_2 ) ;
struct V_36 * V_70 ;
struct V_71 * V_55 ;
struct V_72 * V_73 ;
switch ( V_66 -> V_74 ) {
case 2 :
case 3 :
V_70 = & V_35 -> V_37 ;
V_55 = & V_35 -> V_56 ;
V_73 = V_35 -> V_75 ;
V_70 -> V_32 = V_35 -> V_76 ;
V_70 -> V_33 = V_35 -> V_77 ;
V_70 -> V_58 = 5 ;
break;
case 4 :
V_70 = & V_35 -> V_50 ;
V_55 = & V_35 -> V_63 ;
V_73 = V_35 -> V_78 ;
V_70 -> V_32 = V_35 -> V_79 ;
V_70 -> V_33 = V_35 -> V_80 ;
V_70 -> V_58 = 5 ;
if ( F_19 ( V_69 ) )
V_35 -> V_81 ++ ;
else
V_35 -> V_81 -- ;
break;
default:
return - 1 ;
}
switch ( V_69 ) {
case V_82 :
if ( V_70 -> V_61 )
break;
V_70 -> V_32 = V_70 -> V_45 ;
V_70 -> V_33 = V_70 -> V_49 ;
if ( ! F_20 ( V_55 ) ) {
V_70 -> V_43 = V_44 ;
F_21 ( V_73 , V_55 ,
F_15 ( 1 ) ) ;
}
break;
case V_83 :
if ( ! V_70 -> V_61 )
break;
if ( ! F_20 ( V_55 ) ) {
V_70 -> V_43 = V_46 ;
F_22 ( V_70 -> V_62 ) ;
F_21 ( V_73 , V_55 ,
F_15 ( 1 ) ) ;
F_23 ( & V_70 -> V_62 ,
F_15 ( 2000 ) ) ;
}
break;
}
return 0 ;
}
static int F_24 ( struct V_1 * V_2 , int V_84 )
{
int V_85 , V_86 ;
int V_87 = V_88 | V_89 ;
V_85 = F_1 ( V_2 , V_90 ) ;
V_86 = F_1 ( V_2 , V_91 ) ;
if ( V_84 ) {
V_85 &= ~ V_87 ;
V_86 &= ~ V_87 ;
} else {
V_85 |= V_87 ;
V_86 |= V_87 ;
}
F_5 ( V_2 , V_90 , V_85 ) ;
F_5 ( V_2 , V_91 , V_86 ) ;
return 0 ;
}
static int F_25 ( struct V_65 * V_66 ,
struct V_67 * V_68 , int V_69 )
{
F_26 ( 1 ) ;
return 0 ;
}
static int F_27 ( struct V_65 * V_66 ,
struct V_67 * V_68 , int V_69 )
{
struct V_1 * V_2 = V_66 -> V_2 ;
struct V_34 * V_35 = F_10 ( V_2 ) ;
int V_92 = 0 ;
if ( F_19 ( V_69 ) ) {
V_35 -> V_81 ++ ;
if ( ! strcmp ( V_66 -> V_93 , L_1 ) ) {
V_35 -> V_94 = 1 ;
V_92 = F_24 ( V_2 , 1 ) ;
}
} else {
V_35 -> V_81 -- ;
if ( ! strcmp ( V_66 -> V_93 , L_1 ) ) {
V_35 -> V_94 = 0 ;
V_92 = F_24 ( V_2 , V_35 -> V_95 ) ;
}
}
F_26 ( 1 ) ;
return V_92 ;
}
static void F_28 ( struct V_1 * V_2 ,
struct V_96 * V_97 , int V_98 )
{
struct V_34 * V_35 = F_10 ( V_2 ) ;
int V_99 ;
F_29 ( & V_35 -> V_100 ) ;
V_99 = F_3 ( V_2 , V_22 ) ;
if ( V_99 & V_101 )
F_30 ( V_97 , V_98 , V_98 ) ;
else
F_30 ( V_97 , 0 , V_98 ) ;
F_31 ( & V_35 -> V_100 ) ;
}
void F_32 ( struct V_1 * V_2 ,
struct V_96 * V_97 , int V_98 )
{
struct V_34 * V_35 = F_10 ( V_2 ) ;
struct V_102 * V_103 = & V_35 -> V_103 ;
V_103 -> V_97 = V_97 ;
V_103 -> V_98 = V_98 ;
F_28 ( V_2 , V_103 -> V_97 , V_103 -> V_98 ) ;
}
static void F_33 ( struct V_54 * V_55 )
{
struct V_34 * V_35 = F_13 ( V_55 ,
struct V_34 , V_71 . V_55 ) ;
struct V_1 * V_2 = V_35 -> V_2 ;
struct V_102 * V_103 = & V_35 -> V_103 ;
F_28 ( V_2 , V_103 -> V_97 , V_103 -> V_98 ) ;
}
static T_3 F_34 ( int V_104 , void * V_105 )
{
struct V_1 * V_2 = V_105 ;
struct V_9 * V_9 = V_2 -> V_10 ;
struct V_34 * V_35 = F_10 ( V_2 ) ;
T_1 V_106 ;
V_106 = F_4 ( V_9 , V_16 ) ;
if ( ( V_106 & V_107 ) || ( V_106 & V_108 ) )
F_21 ( V_35 -> V_109 , & V_35 -> V_71 ,
F_15 ( 200 ) ) ;
return V_110 ;
}
static int F_35 ( struct V_67 * V_68 ,
struct V_111 * V_112 )
{
struct V_1 * V_2 = F_36 ( V_68 ) ;
struct V_34 * V_113 = F_10 ( V_2 ) ;
struct V_36 * V_70 = NULL ;
struct V_114 * V_115 =
(struct V_114 * ) V_68 -> V_116 ;
int V_92 ;
unsigned int V_3 = V_115 -> V_3 ;
switch ( V_3 ) {
case V_41 :
V_70 = & V_113 -> V_37 ;
break;
default:
break;
}
if ( V_70 ) {
V_70 -> V_45 = V_112 -> V_8 . integer . V_8 [ 0 ] ;
V_70 -> V_49 = V_112 -> V_8 . integer . V_8 [ 1 ] ;
if ( ! V_70 -> V_61 )
return 1 ;
}
V_92 = F_37 ( V_68 , V_112 ) ;
if ( V_92 < 0 )
return V_92 ;
return 1 ;
}
static int F_38 ( struct V_67 * V_68 ,
struct V_111 * V_112 )
{
struct V_1 * V_2 = F_36 ( V_68 ) ;
struct V_34 * V_113 = F_10 ( V_2 ) ;
struct V_36 * V_70 = & V_113 -> V_37 ;
struct V_114 * V_115 =
(struct V_114 * ) V_68 -> V_116 ;
unsigned int V_3 = V_115 -> V_3 ;
switch ( V_3 ) {
case V_41 :
V_70 = & V_113 -> V_37 ;
V_112 -> V_8 . integer . V_8 [ 0 ] = V_70 -> V_45 ;
V_112 -> V_8 . integer . V_8 [ 1 ] = V_70 -> V_49 ;
return 0 ;
default:
break;
}
return F_39 ( V_68 , V_112 ) ;
}
static int F_40 ( struct V_67 * V_68 ,
struct V_111 * V_112 )
{
struct V_1 * V_2 = F_36 ( V_68 ) ;
struct V_34 * V_113 = F_10 ( V_2 ) ;
struct V_36 * V_70 = NULL ;
struct V_114 * V_115 =
(struct V_114 * ) V_68 -> V_116 ;
int V_92 ;
unsigned int V_3 = V_115 -> V_3 ;
switch ( V_3 ) {
case V_51 :
case V_53 :
V_70 = & V_113 -> V_50 ;
break;
default:
break;
}
if ( V_70 ) {
V_70 -> V_45 = V_112 -> V_8 . integer . V_8 [ 0 ] ;
V_70 -> V_49 = V_112 -> V_8 . integer . V_8 [ 1 ] ;
if ( ! V_70 -> V_61 )
return 1 ;
}
V_92 = F_41 ( V_68 , V_112 ) ;
if ( V_92 < 0 )
return V_92 ;
return 1 ;
}
static int F_42 ( struct V_67 * V_68 ,
struct V_111 * V_112 )
{
struct V_1 * V_2 = F_36 ( V_68 ) ;
struct V_34 * V_113 = F_10 ( V_2 ) ;
struct V_36 * V_70 = & V_113 -> V_50 ;
struct V_114 * V_115 =
(struct V_114 * ) V_68 -> V_116 ;
unsigned int V_3 = V_115 -> V_3 ;
switch ( V_3 ) {
case V_51 :
case V_53 :
V_70 = & V_113 -> V_50 ;
V_112 -> V_8 . integer . V_8 [ 0 ] = V_70 -> V_45 ;
V_112 -> V_8 . integer . V_8 [ 1 ] = V_70 -> V_49 ;
return 0 ;
default:
break;
}
return F_43 ( V_68 , V_112 ) ;
}
static int F_44 ( struct V_67 * V_68 ,
struct V_111 * V_112 )
{
struct V_1 * V_2 = F_36 ( V_68 ) ;
struct V_34 * V_35 = F_10 ( V_2 ) ;
V_112 -> V_8 . V_117 . V_118 [ 0 ] = V_35 -> V_95 ;
return 0 ;
}
static int F_45 ( struct V_67 * V_68 ,
struct V_111 * V_112 )
{
struct V_1 * V_2 = F_36 ( V_68 ) ;
struct V_34 * V_35 = F_10 ( V_2 ) ;
int V_84 = V_112 -> V_8 . V_117 . V_118 [ 0 ] ;
int V_92 = 0 ;
if ( ! V_35 -> V_94 )
V_92 = F_24 ( V_2 , V_84 ) ;
if ( ! V_92 )
V_35 -> V_95 = V_84 ;
return V_92 ;
}
static int F_46 ( struct V_67 * V_68 ,
struct V_111 * V_112 )
{
struct V_1 * V_2 = F_36 ( V_68 ) ;
struct V_34 * V_35 = F_10 ( V_2 ) ;
V_112 -> V_8 . V_117 . V_118 [ 0 ] = V_35 -> V_119 ;
return 0 ;
}
static int F_47 ( struct V_67 * V_68 ,
struct V_111 * V_112 )
{
struct V_1 * V_2 = F_36 ( V_68 ) ;
struct V_34 * V_35 = F_10 ( V_2 ) ;
V_35 -> V_119 = V_112 -> V_8 . V_117 . V_118 [ 0 ] ;
return 0 ;
}
int F_48 ( struct V_1 * V_2 )
{
struct V_34 * V_35 = F_10 ( V_2 ) ;
return V_35 -> V_119 ;
}
static int F_49 ( struct V_1 * V_2 )
{
struct V_120 * V_121 = & V_2 -> V_121 ;
F_50 ( V_121 , V_122 ,
F_51 ( V_122 ) ) ;
F_52 ( V_121 , V_123 , F_51 ( V_123 ) ) ;
F_53 ( V_121 ) ;
return 0 ;
}
static int F_54 ( struct V_1 * V_2 ,
enum V_124 V_125 )
{
struct V_9 * V_9 = V_2 -> V_10 ;
struct V_34 * V_35 = F_10 ( V_2 ) ;
int V_92 ;
switch ( V_125 ) {
case V_126 :
break;
case V_127 :
break;
case V_128 :
if ( V_35 -> V_129 )
break;
V_92 = F_55 ( V_9 , 1 ) ;
if ( V_92 )
return V_92 ;
V_35 -> V_129 = 1 ;
F_8 ( V_2 ) ;
F_5 ( V_2 , V_20 , 0x02 ) ;
break;
case V_130 :
if ( ! V_35 -> V_129 )
break;
F_55 ( V_9 , 0 ) ;
V_35 -> V_129 = 0 ;
break;
}
V_2 -> V_121 . V_131 = V_125 ;
return 0 ;
}
static int F_56 ( struct V_132 * V_133 ,
struct V_134 * V_135 )
{
struct V_136 * V_137 = V_133 -> V_138 ;
struct V_1 * V_2 = V_137 -> V_2 ;
struct V_34 * V_35 = F_10 ( V_2 ) ;
F_57 ( V_133 -> V_139 , 0 ,
V_140 ,
& V_141 [ V_35 -> V_119 ] ) ;
return 0 ;
}
static int F_58 ( struct V_132 * V_133 ,
struct V_142 * V_143 ,
struct V_134 * V_135 )
{
struct V_136 * V_137 = V_133 -> V_138 ;
struct V_1 * V_2 = V_137 -> V_2 ;
struct V_34 * V_35 = F_10 ( V_2 ) ;
int V_144 ;
V_144 = F_59 ( V_143 ) ;
switch ( V_144 ) {
case 11250 :
case 22500 :
case 44100 :
case 88200 :
if ( F_60 ( V_35 -> V_145 == V_146 ) ) {
F_61 ( V_2 -> V_147 , L_2 ,
V_144 ) ;
return - V_148 ;
}
if ( V_133 -> V_149 == V_150 ) {
F_61 ( V_2 -> V_147 ,
L_3 ,
V_144 ) ;
return - V_148 ;
}
V_35 -> V_151 = 17640000 ;
break;
case 8000 :
case 16000 :
case 32000 :
case 48000 :
case 96000 :
V_35 -> V_151 = 19200000 ;
break;
default:
F_61 ( V_2 -> V_147 , L_4 , V_144 ) ;
return - V_148 ;
}
return 0 ;
}
static int F_62 ( struct V_132 * V_133 ,
struct V_134 * V_135 )
{
struct V_136 * V_137 = V_133 -> V_138 ;
struct V_1 * V_2 = V_137 -> V_2 ;
struct V_9 * V_9 = V_2 -> V_10 ;
struct V_34 * V_35 = F_10 ( V_2 ) ;
int V_92 ;
if ( ! V_35 -> V_151 ) {
F_61 ( V_2 -> V_147 ,
L_5 ) ;
return - V_148 ;
}
if ( ( V_35 -> V_151 == 17640000 ) && V_35 -> V_81 ) {
F_61 ( V_2 -> V_147 ,
L_6 ,
V_35 -> V_151 ) ;
return - V_152 ;
}
V_92 = F_63 ( V_9 , V_35 -> V_145 , V_35 -> V_153 , V_35 -> V_151 ) ;
if ( V_92 ) {
F_61 ( V_2 -> V_147 , L_7 , V_92 ) ;
return - V_152 ;
}
return 0 ;
}
static int F_64 ( struct V_134 * V_154 ,
int V_155 , unsigned int V_156 , int V_157 )
{
struct V_1 * V_2 = V_154 -> V_2 ;
struct V_34 * V_35 = F_10 ( V_2 ) ;
switch ( V_155 ) {
case V_158 :
case V_146 :
V_35 -> V_145 = V_155 ;
V_35 -> V_153 = V_156 ;
break;
default:
F_61 ( V_2 -> V_147 , L_8 , V_155 ) ;
return - V_148 ;
}
return 0 ;
}
static int F_65 ( struct V_1 * V_2 , T_4 V_159 )
{
F_54 ( V_2 , V_130 ) ;
return 0 ;
}
static int F_66 ( struct V_1 * V_2 )
{
F_54 ( V_2 , V_128 ) ;
F_54 ( V_2 , V_2 -> V_121 . V_160 ) ;
return 0 ;
}
static int F_67 ( struct V_1 * V_2 )
{
struct V_34 * V_35 ;
struct V_161 * V_162 = F_68 ( V_2 -> V_147 ) ;
struct V_163 * V_164 = F_13 ( V_2 -> V_147 ,
struct V_163 , V_147 ) ;
int V_92 = 0 ;
V_35 = F_69 ( sizeof( struct V_34 ) , V_165 ) ;
if ( V_35 == NULL )
return - V_166 ;
F_70 ( V_2 , V_35 ) ;
V_35 -> V_2 = V_2 ;
V_2 -> V_10 = F_71 ( V_2 -> V_147 -> V_167 ) ;
if ( V_162 && V_162 -> V_76 && V_162 -> V_77 ) {
V_35 -> V_76 = V_162 -> V_76 ;
V_35 -> V_77 = V_162 -> V_77 ;
} else {
V_35 -> V_76 = 1 ;
V_35 -> V_77 = 1 ;
}
if ( V_162 && V_162 -> V_79 && V_162 -> V_80 ) {
V_35 -> V_79 = V_162 -> V_79 ;
V_35 -> V_80 = V_162 -> V_80 ;
} else {
V_35 -> V_79 = 1 ;
V_35 -> V_80 = 1 ;
}
V_35 -> V_168 = F_72 ( V_164 , 0 ) ;
if ( V_35 -> V_168 < 0 ) {
F_61 ( V_2 -> V_147 , L_9 ) ;
V_92 = - V_148 ;
goto V_169;
}
V_35 -> V_109 = F_73 ( L_10 ) ;
if ( ! V_35 -> V_109 ) {
V_92 = - V_166 ;
goto V_169;
}
F_74 ( & V_35 -> V_71 , F_33 ) ;
F_75 ( & V_35 -> V_100 ) ;
F_76 ( & V_35 -> V_37 . V_62 ) ;
F_76 ( & V_35 -> V_50 . V_62 ) ;
V_35 -> V_78 = F_73 ( L_11 ) ;
if ( V_35 -> V_78 == NULL ) {
V_92 = - V_166 ;
goto V_170;
}
V_35 -> V_75 = F_73 ( L_12 ) ;
if ( V_35 -> V_75 == NULL ) {
V_92 = - V_166 ;
goto V_171;
}
F_74 ( & V_35 -> V_56 , F_12 ) ;
F_74 ( & V_35 -> V_63 , F_17 ) ;
V_92 = F_77 ( V_35 -> V_168 , NULL , F_34 ,
0 , L_13 , V_2 ) ;
if ( V_92 ) {
F_61 ( V_2 -> V_147 , L_14 , V_92 ) ;
goto V_172;
}
F_7 ( V_2 ) ;
V_92 = F_54 ( V_2 , V_128 ) ;
if ( V_92 )
goto V_173;
F_78 ( V_2 , V_174 ,
F_51 ( V_174 ) ) ;
F_49 ( V_2 ) ;
return 0 ;
V_173:
F_79 ( V_35 -> V_168 , V_2 ) ;
V_172:
F_80 ( V_35 -> V_75 ) ;
V_171:
F_80 ( V_35 -> V_78 ) ;
V_170:
F_80 ( V_35 -> V_109 ) ;
V_169:
F_81 ( V_35 ) ;
return V_92 ;
}
static int F_82 ( struct V_1 * V_2 )
{
struct V_34 * V_35 = F_10 ( V_2 ) ;
F_54 ( V_2 , V_130 ) ;
F_79 ( V_35 -> V_168 , V_2 ) ;
F_80 ( V_35 -> V_109 ) ;
F_80 ( V_35 -> V_78 ) ;
F_80 ( V_35 -> V_75 ) ;
F_81 ( V_35 ) ;
return 0 ;
}
static int T_5 F_83 ( struct V_163 * V_164 )
{
return F_84 ( & V_164 -> V_147 , & V_175 ,
V_176 , F_51 ( V_176 ) ) ;
}
static int T_6 F_85 ( struct V_163 * V_164 )
{
F_86 ( & V_164 -> V_147 ) ;
return 0 ;
}
static int T_7 F_87 ( void )
{
return F_88 ( & V_177 ) ;
}
static void T_8 F_89 ( void )
{
F_90 ( & V_177 ) ;
}
