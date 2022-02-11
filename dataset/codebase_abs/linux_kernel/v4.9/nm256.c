static inline T_1
F_1 ( struct V_1 * V_2 , int V_3 )
{
return F_2 ( V_2 -> V_4 + V_3 ) ;
}
static inline T_2
F_3 ( struct V_1 * V_2 , int V_3 )
{
return F_4 ( V_2 -> V_4 + V_3 ) ;
}
static inline T_3
F_5 ( struct V_1 * V_2 , int V_3 )
{
return F_6 ( V_2 -> V_4 + V_3 ) ;
}
static inline void
F_7 ( struct V_1 * V_2 , int V_3 , T_1 V_5 )
{
F_8 ( V_5 , V_2 -> V_4 + V_3 ) ;
}
static inline void
F_9 ( struct V_1 * V_2 , int V_3 , T_2 V_5 )
{
F_10 ( V_5 , V_2 -> V_4 + V_3 ) ;
}
static inline void
F_11 ( struct V_1 * V_2 , int V_3 , T_3 V_5 )
{
F_12 ( V_5 , V_2 -> V_4 + V_3 ) ;
}
static inline void
F_13 ( struct V_1 * V_2 , void * V_6 , int V_3 , int V_7 )
{
V_3 -= V_2 -> V_8 ;
#ifdef F_14
if ( V_3 < 0 || V_3 >= V_2 -> V_9 ) {
F_15 ( V_2 -> V_10 -> V_11 ,
L_1 ,
V_3 , V_7 ) ;
return;
}
#endif
F_16 ( V_2 -> V_12 + V_3 , V_6 , V_7 ) ;
}
static T_2
F_17 ( int V_13 )
{
T_2 V_3 = 0 ;
while ( V_13 -- > 0 )
V_3 += V_14 [ V_13 ] ;
return V_3 ;
}
static void
F_18 ( struct V_1 * V_2 , int V_15 , T_3 V_16 , int V_13 )
{
T_3 V_17 = V_2 -> V_17 [ V_15 ] ;
T_2 V_3 = F_17 ( V_13 ) ;
T_2 V_7 = V_14 [ V_13 ] ;
F_13 ( V_2 , V_18 + V_3 , V_17 , V_7 ) ;
F_11 ( V_2 , V_16 , V_17 ) ;
if ( V_15 == V_19 )
V_7 -- ;
F_11 ( V_2 , V_16 + 4 , V_17 + V_7 ) ;
}
static void
F_19 ( struct V_1 * V_2 , int V_15 , int V_20 )
{
T_3 V_21 = ( V_15 == V_22 ?
V_23 : V_24 ) ;
T_3 V_25 = V_26 ;
V_25 += ( V_15 == V_22 ?
V_27 : V_28 ) ;
if ( F_1 ( V_2 , V_21 ) & 1 ) {
F_20 ( V_2 -> V_10 -> V_11 ,
L_2 ) ;
return;
}
V_20 &= 7 ;
if ( V_15 == V_22 )
V_20 += 8 ;
if ( ! V_2 -> V_29 ) {
F_18 ( V_2 , V_15 , V_25 , V_20 ) ;
return;
}
if ( ! V_2 -> V_30 ) {
F_13 ( V_2 , V_18 , V_2 -> V_31 ,
V_32 * 4 ) ;
V_2 -> V_30 = 1 ;
} else {
T_3 V_33 = V_2 -> V_31 ;
T_3 V_3 = F_17 ( V_20 ) ;
T_3 V_34 = V_3 + V_14 [ V_20 ] ;
F_11 ( V_2 , V_25 , V_33 + V_3 ) ;
if ( V_15 == V_19 )
V_34 -- ;
F_11 ( V_2 , V_25 + 4 , V_33 + V_34 ) ;
}
}
static int
F_21 ( unsigned int V_35 )
{
unsigned int V_36 ;
for ( V_36 = 0 ; V_36 < F_22 ( V_37 ) ; V_36 ++ ) {
if ( V_35 == V_37 [ V_36 ] )
return V_36 ;
}
F_23 () ;
return 0 ;
}
static void
F_24 ( struct V_1 * V_2 , struct V_38 * V_39 ,
struct V_40 * V_41 )
{
struct V_42 * V_43 = V_41 -> V_43 ;
int V_44 = F_21 ( V_43 -> V_35 ) ;
unsigned char V_45 = ( V_44 << 4 ) & V_46 ;
V_39 -> V_47 = 0 ;
if ( F_25 ( V_43 -> V_48 ) == 16 ) {
V_45 |= V_49 ;
V_39 -> V_47 ++ ;
}
if ( V_43 -> V_50 > 1 ) {
V_45 |= V_51 ;
V_39 -> V_47 ++ ;
}
V_43 -> V_35 = V_37 [ V_44 ] ;
switch ( V_41 -> V_15 ) {
case V_19 :
F_19 ( V_2 , 0 , V_44 ) ;
F_7 ( V_2 ,
V_28 + V_52 ,
V_45 ) ;
break;
case V_22 :
F_19 ( V_2 , 1 , V_44 ) ;
F_7 ( V_2 ,
V_27 + V_52 ,
V_45 ) ;
break;
}
}
static int F_26 ( struct V_1 * V_2 )
{
F_27 ( & V_2 -> V_53 ) ;
if ( V_2 -> V_54 < 0 ) {
if ( F_28 ( V_2 -> V_55 -> V_54 , V_2 -> V_56 , V_57 ,
V_58 , V_2 ) ) {
F_15 ( V_2 -> V_10 -> V_11 ,
L_3 , V_2 -> V_55 -> V_54 ) ;
F_29 ( & V_2 -> V_53 ) ;
return - V_59 ;
}
V_2 -> V_54 = V_2 -> V_55 -> V_54 ;
}
V_2 -> V_60 ++ ;
F_29 ( & V_2 -> V_53 ) ;
return 0 ;
}
static void F_30 ( struct V_1 * V_2 )
{
F_27 ( & V_2 -> V_53 ) ;
if ( V_2 -> V_60 > 0 )
V_2 -> V_60 -- ;
if ( V_2 -> V_60 == 0 && V_2 -> V_54 >= 0 ) {
F_31 ( V_2 -> V_54 , V_2 ) ;
V_2 -> V_54 = - 1 ;
}
F_29 ( & V_2 -> V_53 ) ;
}
static void F_32 ( struct V_1 * V_2 , struct V_38 * V_39 , int V_61 )
{
V_39 -> V_62 ++ ;
V_39 -> V_62 %= V_39 -> V_63 ;
F_11 ( V_2 , V_61 , V_39 -> V_64 + V_39 -> V_62 * V_39 -> V_65 ) ;
}
static void
F_33 ( struct V_1 * V_2 , struct V_38 * V_39 ,
struct V_40 * V_41 )
{
F_11 ( V_2 , V_66 , V_39 -> V_64 ) ;
F_11 ( V_2 , V_67 , V_39 -> V_64 + V_39 -> V_68 - ( 1 << V_39 -> V_47 ) ) ;
F_11 ( V_2 , V_69 , V_39 -> V_64 ) ;
F_34 ( V_2 , V_39 ) ;
F_7 ( V_2 , V_24 ,
V_70 | V_71 ) ;
F_9 ( V_2 , V_72 , 0x0 ) ;
}
static void
F_35 ( struct V_1 * V_2 , struct V_38 * V_39 ,
struct V_40 * V_41 )
{
F_11 ( V_2 , V_73 , V_39 -> V_64 ) ;
F_11 ( V_2 , V_74 , V_39 -> V_64 + V_39 -> V_68 ) ;
F_11 ( V_2 , V_75 , V_39 -> V_64 ) ;
F_36 ( V_2 , V_39 ) ;
F_7 ( V_2 , V_23 ,
V_76 | V_77 ) ;
}
static void
F_37 ( struct V_1 * V_2 )
{
F_9 ( V_2 , V_72 ,
V_78 | V_79 ) ;
F_7 ( V_2 , V_24 , 0 ) ;
}
static void
F_38 ( struct V_1 * V_2 )
{
F_7 ( V_2 , V_23 , 0 ) ;
}
static int
F_39 ( struct V_40 * V_41 , int V_80 )
{
struct V_1 * V_2 = F_40 ( V_41 ) ;
struct V_38 * V_39 = V_41 -> V_43 -> V_81 ;
int V_82 = 0 ;
if ( F_41 ( ! V_39 ) )
return - V_83 ;
F_42 ( & V_2 -> V_84 ) ;
switch ( V_80 ) {
case V_85 :
V_39 -> V_86 = 0 ;
case V_87 :
if ( ! V_39 -> V_88 ) {
F_33 ( V_2 , V_39 , V_41 ) ;
V_39 -> V_88 = 1 ;
}
break;
case V_89 :
V_39 -> V_86 = 1 ;
case V_90 :
if ( V_39 -> V_88 ) {
F_37 ( V_2 ) ;
V_39 -> V_88 = 0 ;
}
break;
default:
V_82 = - V_91 ;
break;
}
F_43 ( & V_2 -> V_84 ) ;
return V_82 ;
}
static int
F_44 ( struct V_40 * V_41 , int V_80 )
{
struct V_1 * V_2 = F_40 ( V_41 ) ;
struct V_38 * V_39 = V_41 -> V_43 -> V_81 ;
int V_82 = 0 ;
if ( F_41 ( ! V_39 ) )
return - V_83 ;
F_42 ( & V_2 -> V_84 ) ;
switch ( V_80 ) {
case V_87 :
case V_85 :
if ( ! V_39 -> V_88 ) {
F_35 ( V_2 , V_39 , V_41 ) ;
V_39 -> V_88 = 1 ;
}
break;
case V_90 :
case V_89 :
if ( V_39 -> V_88 ) {
F_38 ( V_2 ) ;
V_39 -> V_88 = 0 ;
}
break;
default:
V_82 = - V_91 ;
break;
}
F_43 ( & V_2 -> V_84 ) ;
return V_82 ;
}
static int F_45 ( struct V_40 * V_41 )
{
struct V_1 * V_2 = F_40 ( V_41 ) ;
struct V_42 * V_43 = V_41 -> V_43 ;
struct V_38 * V_39 = V_43 -> V_81 ;
if ( F_41 ( ! V_39 ) )
return - V_83 ;
V_39 -> V_68 = F_46 ( V_43 , V_41 -> V_43 -> V_9 ) ;
V_39 -> V_65 = F_46 ( V_43 , V_41 -> V_43 -> V_65 ) ;
V_39 -> V_63 = V_41 -> V_43 -> V_63 ;
V_39 -> V_62 = 0 ;
F_47 ( & V_2 -> V_84 ) ;
V_39 -> V_88 = 0 ;
F_24 ( V_2 , V_39 , V_41 ) ;
F_48 ( & V_2 -> V_84 ) ;
return 0 ;
}
static T_4
F_49 ( struct V_40 * V_41 )
{
struct V_1 * V_2 = F_40 ( V_41 ) ;
struct V_38 * V_39 = V_41 -> V_43 -> V_81 ;
unsigned long V_92 ;
if ( F_41 ( ! V_39 ) )
return 0 ;
V_92 = F_5 ( V_2 , V_69 ) - ( unsigned long ) V_39 -> V_64 ;
V_92 %= V_39 -> V_68 ;
return F_50 ( V_41 -> V_43 , V_92 ) ;
}
static T_4
F_51 ( struct V_40 * V_41 )
{
struct V_1 * V_2 = F_40 ( V_41 ) ;
struct V_38 * V_39 = V_41 -> V_43 -> V_81 ;
unsigned long V_92 ;
if ( F_41 ( ! V_39 ) )
return 0 ;
V_92 = F_5 ( V_2 , V_75 ) - ( unsigned long ) V_39 -> V_64 ;
V_92 %= V_39 -> V_68 ;
return F_50 ( V_41 -> V_43 , V_92 ) ;
}
static int
F_52 ( struct V_40 * V_41 ,
int V_93 ,
T_4 V_94 ,
T_4 V_95 )
{
struct V_42 * V_43 = V_41 -> V_43 ;
struct V_38 * V_39 = V_43 -> V_81 ;
V_95 = F_46 ( V_43 , V_95 ) ;
V_94 = F_46 ( V_43 , V_94 ) ;
F_53 ( V_39 -> V_96 + V_94 , 0 , V_95 ) ;
return 0 ;
}
static int
F_54 ( struct V_40 * V_41 ,
int V_93 ,
T_4 V_94 ,
void T_5 * V_6 ,
T_4 V_95 )
{
struct V_42 * V_43 = V_41 -> V_43 ;
struct V_38 * V_39 = V_43 -> V_81 ;
V_95 = F_46 ( V_43 , V_95 ) ;
V_94 = F_46 ( V_43 , V_94 ) ;
if ( F_55 ( V_39 -> V_96 + V_94 , V_6 , V_95 ) )
return - V_97 ;
return 0 ;
}
static int
F_56 ( struct V_40 * V_41 ,
int V_93 ,
T_4 V_94 ,
void T_5 * V_98 ,
T_4 V_95 )
{
struct V_42 * V_43 = V_41 -> V_43 ;
struct V_38 * V_39 = V_43 -> V_81 ;
V_95 = F_46 ( V_43 , V_95 ) ;
V_94 = F_46 ( V_43 , V_94 ) ;
if ( F_57 ( V_98 , V_39 -> V_96 + V_94 , V_95 ) )
return - V_97 ;
return 0 ;
}
static void
F_58 ( struct V_1 * V_2 )
{
struct V_38 * V_39 ;
V_39 = & V_2 -> V_99 [ V_19 ] ;
if ( V_39 -> V_88 && V_39 -> V_41 ) {
F_43 ( & V_2 -> V_84 ) ;
F_59 ( V_39 -> V_41 ) ;
F_42 ( & V_2 -> V_84 ) ;
F_34 ( V_2 , V_39 ) ;
}
}
static void
F_60 ( struct V_1 * V_2 )
{
struct V_38 * V_39 ;
V_39 = & V_2 -> V_99 [ V_22 ] ;
if ( V_39 -> V_88 && V_39 -> V_41 ) {
F_43 ( & V_2 -> V_84 ) ;
F_59 ( V_39 -> V_41 ) ;
F_42 ( & V_2 -> V_84 ) ;
F_36 ( V_2 , V_39 ) ;
}
}
static int F_61 ( struct V_40 * V_41 ,
struct V_100 * V_101 )
{
V_41 -> V_43 -> V_102 = F_62 ( V_101 ) ;
return 0 ;
}
static void F_63 ( struct V_1 * V_2 , struct V_38 * V_39 ,
struct V_40 * V_41 ,
struct V_103 * V_104 )
{
struct V_42 * V_43 = V_41 -> V_43 ;
V_39 -> V_88 = 0 ;
V_43 -> V_105 = * V_104 ;
V_43 -> V_105 . V_106 = V_39 -> V_107 ;
V_43 -> V_105 . V_108 = V_39 -> V_107 / 2 ;
V_43 -> V_109 = ( void V_110 * ) V_39 -> V_96 ;
V_43 -> V_111 = V_39 -> V_112 ;
V_43 -> V_102 = V_39 -> V_107 ;
V_43 -> V_81 = V_39 ;
V_39 -> V_41 = V_41 ;
F_64 ( V_43 , 0 , V_113 ,
& V_114 ) ;
}
static int
F_65 ( struct V_40 * V_41 )
{
struct V_1 * V_2 = F_40 ( V_41 ) ;
if ( F_26 ( V_2 ) < 0 )
return - V_59 ;
F_63 ( V_2 , & V_2 -> V_99 [ V_19 ] ,
V_41 , & V_115 ) ;
return 0 ;
}
static int
F_66 ( struct V_40 * V_41 )
{
struct V_1 * V_2 = F_40 ( V_41 ) ;
if ( F_26 ( V_2 ) < 0 )
return - V_59 ;
F_63 ( V_2 , & V_2 -> V_99 [ V_22 ] ,
V_41 , & V_116 ) ;
return 0 ;
}
static int
F_67 ( struct V_40 * V_41 )
{
struct V_1 * V_2 = F_40 ( V_41 ) ;
F_30 ( V_2 ) ;
return 0 ;
}
static int
F_68 ( struct V_40 * V_41 )
{
struct V_1 * V_2 = F_40 ( V_41 ) ;
F_30 ( V_2 ) ;
return 0 ;
}
static int
F_69 ( struct V_1 * V_2 , int V_117 )
{
struct V_118 * V_119 ;
int V_36 , V_82 ;
for ( V_36 = 0 ; V_36 < 2 ; V_36 ++ ) {
struct V_38 * V_39 = & V_2 -> V_99 [ V_36 ] ;
V_39 -> V_96 = V_2 -> V_12 + ( V_39 -> V_64 - V_2 -> V_8 ) ;
V_39 -> V_112 = V_2 -> V_120 + ( V_39 -> V_64 - V_2 -> V_8 ) ;
}
V_82 = F_70 ( V_2 -> V_10 , V_2 -> V_10 -> V_121 , V_117 ,
1 , 1 , & V_119 ) ;
if ( V_82 < 0 )
return V_82 ;
F_71 ( V_119 , V_19 , & V_122 ) ;
F_71 ( V_119 , V_22 , & V_123 ) ;
V_119 -> V_81 = V_2 ;
V_119 -> V_124 = 0 ;
V_2 -> V_119 = V_119 ;
return 0 ;
}
static void
F_72 ( struct V_1 * V_2 )
{
F_7 ( V_2 , 0x0 , 0x11 ) ;
F_9 ( V_2 , 0x214 , 0 ) ;
}
static T_6
F_73 ( struct V_1 * V_2 )
{
if ( V_2 -> V_125 ++ > 1000 ) {
if ( V_2 -> V_99 [ V_19 ] . V_88 )
F_37 ( V_2 ) ;
if ( V_2 -> V_99 [ V_22 ] . V_88 )
F_38 ( V_2 ) ;
V_2 -> V_125 = 0 ;
return V_126 ;
}
return V_127 ;
}
static T_6
F_74 ( int V_54 , void * V_128 )
{
struct V_1 * V_2 = V_128 ;
T_2 V_129 ;
T_1 V_130 ;
V_129 = F_3 ( V_2 , V_131 ) ;
if ( V_129 == 0 )
return F_73 ( V_2 ) ;
V_2 -> V_125 = 0 ;
F_42 ( & V_2 -> V_84 ) ;
if ( V_129 & V_132 ) {
V_129 &= ~ V_132 ;
F_75 ( V_2 , V_132 ) ;
F_58 ( V_2 ) ;
}
if ( V_129 & V_133 ) {
V_129 &= ~ V_133 ;
F_75 ( V_2 , V_133 ) ;
F_60 ( V_2 ) ;
}
if ( V_129 & V_134 ) {
V_129 &= ~ V_134 ;
F_75 ( V_2 , V_134 ) ;
F_20 ( V_2 -> V_10 -> V_11 , L_4 ) ;
F_9 ( V_2 , V_131 , 0x8000 ) ;
V_130 = F_1 ( V_2 , 0x400 ) ;
F_7 ( V_2 , 0x400 , V_130 | 2 ) ;
}
if ( V_129 & V_135 ) {
V_129 &= ~ V_135 ;
F_75 ( V_2 , V_135 ) ;
F_20 ( V_2 -> V_10 -> V_11 , L_5 ) ;
V_130 = F_1 ( V_2 , 0x400 ) ;
F_7 ( V_2 , 0x400 , V_130 & ~ 2 ) ;
}
if ( V_129 ) {
F_20 ( V_2 -> V_10 -> V_11 ,
L_6 ,
V_129 ) ;
F_75 ( V_2 , V_129 ) ;
}
F_43 ( & V_2 -> V_84 ) ;
return V_126 ;
}
static T_6
F_76 ( int V_54 , void * V_128 )
{
struct V_1 * V_2 = V_128 ;
T_3 V_129 ;
T_1 V_130 ;
V_129 = F_5 ( V_2 , V_131 ) ;
if ( V_129 == 0 )
return F_73 ( V_2 ) ;
V_2 -> V_125 = 0 ;
F_42 ( & V_2 -> V_84 ) ;
if ( V_129 & V_136 ) {
V_129 &= ~ V_136 ;
F_77 ( V_2 , V_136 ) ;
F_58 ( V_2 ) ;
}
if ( V_129 & V_137 ) {
V_129 &= ~ V_137 ;
F_77 ( V_2 , V_137 ) ;
F_60 ( V_2 ) ;
}
if ( V_129 & V_138 ) {
V_129 &= ~ V_138 ;
F_77 ( V_2 , V_138 ) ;
F_20 ( V_2 -> V_10 -> V_11 , L_4 ) ;
V_130 = F_1 ( V_2 , 0x400 ) ;
F_7 ( V_2 , 0x400 , V_130 | 2 ) ;
}
if ( V_129 & V_139 ) {
V_129 &= ~ V_139 ;
F_77 ( V_2 , V_139 ) ;
F_20 ( V_2 -> V_10 -> V_11 , L_5 ) ;
V_130 = F_1 ( V_2 , 0x400 ) ;
F_7 ( V_2 , 0x400 , V_130 & ~ 2 ) ;
}
if ( V_129 ) {
F_20 ( V_2 -> V_10 -> V_11 ,
L_6 ,
V_129 ) ;
F_77 ( V_2 , V_129 ) ;
}
F_43 ( & V_2 -> V_84 ) ;
return V_126 ;
}
static int
F_78 ( struct V_1 * V_2 )
{
int V_140 = 10 ;
T_3 V_141 ;
T_2 V_142 ;
V_141 = V_2 -> V_143 ;
V_142 = V_2 -> V_144 ;
while ( V_140 -- > 0 ) {
if ( ( F_3 ( V_2 , V_141 ) & V_142 ) == 0 )
return 1 ;
F_79 ( 100 ) ;
}
return 0 ;
}
static int F_80 ( unsigned short V_61 )
{
int V_36 ;
for ( V_36 = 0 ; V_36 < F_22 ( V_145 ) ; V_36 ++ )
if ( V_145 [ V_36 ] . V_61 == V_61 )
return V_36 ;
return - 1 ;
}
static unsigned short
F_81 ( struct V_146 * V_147 , unsigned short V_61 )
{
struct V_1 * V_2 = V_147 -> V_81 ;
int V_148 = F_80 ( V_61 ) ;
if ( V_148 < 0 )
return 0 ;
return V_2 -> V_149 [ V_148 ] ;
}
static void
F_82 ( struct V_146 * V_147 ,
unsigned short V_61 , unsigned short V_5 )
{
struct V_1 * V_2 = V_147 -> V_81 ;
int V_150 = 2 ;
int V_148 = F_80 ( V_61 ) ;
T_3 V_33 ;
if ( V_148 < 0 )
return;
V_33 = V_2 -> V_151 ;
F_78 ( V_2 ) ;
while ( V_150 -- > 0 ) {
F_9 ( V_2 , V_33 + V_61 , V_5 ) ;
F_83 ( 1 ) ;
if ( F_78 ( V_2 ) ) {
V_2 -> V_149 [ V_148 ] = V_5 ;
return;
}
}
F_20 ( V_2 -> V_10 -> V_11 , L_7 ) ;
}
static void
F_84 ( struct V_146 * V_147 )
{
struct V_1 * V_2 = V_147 -> V_81 ;
F_7 ( V_2 , 0x6c0 , 1 ) ;
if ( ! V_2 -> V_152 ) {
F_7 ( V_2 , 0x6cc , 0x87 ) ;
}
if ( ! V_2 -> V_153 ) {
F_7 ( V_2 , 0x6cc , 0x80 ) ;
F_7 ( V_2 , 0x6cc , 0x0 ) ;
}
if ( ! V_2 -> V_154 ) {
int V_36 ;
for ( V_36 = 0 ; V_36 < F_22 ( V_145 ) ; V_36 ++ ) {
F_82 ( V_147 , V_145 [ V_36 ] . V_61 ,
V_145 [ V_36 ] . V_155 ) ;
}
}
}
static int
F_85 ( struct V_1 * V_2 )
{
struct V_156 * V_157 ;
struct V_158 V_147 ;
int V_82 ;
static struct V_159 V_160 = {
. V_161 = F_84 ,
. V_162 = F_82 ,
. V_163 = F_81 ,
} ;
V_2 -> V_149 = F_86 ( F_22 ( V_145 ) ,
sizeof( short ) , V_164 ) ;
if ( ! V_2 -> V_149 )
return - V_165 ;
if ( ( V_82 = V_156 ( V_2 -> V_10 , 0 , & V_160 , NULL , & V_157 ) ) < 0 )
return V_82 ;
memset ( & V_147 , 0 , sizeof( V_147 ) ) ;
V_147 . V_166 = V_167 ;
V_147 . V_81 = V_2 ;
V_147 . V_168 = V_169 ;
V_157 -> V_170 = 1 ;
V_82 = F_87 ( V_157 , & V_147 , & V_2 -> V_147 ) ;
if ( V_82 < 0 )
return V_82 ;
if ( ! ( V_2 -> V_147 -> V_171 & ( 0xf0000000 ) ) ) {
sprintf ( V_2 -> V_10 -> V_172 , L_8 , V_2 -> V_10 -> V_121 ) ;
}
return 0 ;
}
static int
F_88 ( struct V_1 * V_2 )
{
void T_7 * V_173 ;
unsigned long V_174 = V_2 -> V_175 - 0x1400 ;
T_3 V_176 ;
V_173 = F_89 ( V_2 -> V_120 + V_2 -> V_175 - 0x400 , 16 ) ;
if ( V_173 == NULL ) {
F_15 ( V_2 -> V_10 -> V_11 ,
L_9 ) ;
return - V_59 ;
}
V_176 = F_6 ( V_173 ) ;
if ( ( V_176 & V_177 ) == V_178 ) {
T_3 V_179 = F_6 ( V_173 + 4 ) ;
if ( V_179 == 0xffffffff ||
V_179 < V_2 -> V_9 ||
V_179 > V_2 -> V_175 ) {
F_15 ( V_2 -> V_10 -> V_11 ,
L_10 , V_179 ) ;
F_90 ( V_173 ) ;
return - V_180 ;
} else {
V_174 = V_179 ;
F_91 ( V_2 -> V_10 -> V_11 ,
L_11 ,
V_179 ) ;
}
}
F_90 ( V_173 ) ;
V_2 -> V_175 = V_174 ;
return 0 ;
}
static int F_92 ( struct V_117 * V_11 )
{
struct V_181 * V_10 = F_93 ( V_11 ) ;
struct V_1 * V_2 = V_10 -> V_81 ;
F_94 ( V_10 , V_182 ) ;
F_95 ( V_2 -> V_119 ) ;
F_96 ( V_2 -> V_147 ) ;
V_2 -> V_30 = 0 ;
return 0 ;
}
static int F_97 ( struct V_117 * V_11 )
{
struct V_181 * V_10 = F_93 ( V_11 ) ;
struct V_1 * V_2 = V_10 -> V_81 ;
int V_36 ;
V_2 -> V_154 = 1 ;
F_72 ( V_2 ) ;
F_98 ( V_2 -> V_147 ) ;
for ( V_36 = 0 ; V_36 < 2 ; V_36 ++ ) {
struct V_38 * V_39 = & V_2 -> V_99 [ V_36 ] ;
if ( V_39 -> V_41 && V_39 -> V_86 ) {
F_47 ( & V_2 -> V_84 ) ;
F_24 ( V_2 , V_39 , V_39 -> V_41 ) ;
F_48 ( & V_2 -> V_84 ) ;
}
}
F_94 ( V_10 , V_183 ) ;
V_2 -> V_154 = 0 ;
return 0 ;
}
static int F_99 ( struct V_1 * V_2 )
{
if ( V_2 -> V_99 [ V_19 ] . V_88 )
F_37 ( V_2 ) ;
if ( V_2 -> V_99 [ V_22 ] . V_88 )
F_38 ( V_2 ) ;
if ( V_2 -> V_54 >= 0 )
F_31 ( V_2 -> V_54 , V_2 ) ;
F_90 ( V_2 -> V_4 ) ;
F_90 ( V_2 -> V_12 ) ;
F_100 ( V_2 -> V_184 ) ;
F_100 ( V_2 -> V_185 ) ;
F_101 ( V_2 -> V_55 ) ;
F_102 ( V_2 -> V_149 ) ;
F_102 ( V_2 ) ;
return 0 ;
}
static int F_103 ( struct V_186 * V_117 )
{
struct V_1 * V_2 = V_117 -> V_187 ;
return F_99 ( V_2 ) ;
}
static int
F_104 ( struct V_181 * V_10 , struct V_188 * V_55 ,
struct V_1 * * V_189 )
{
struct V_1 * V_2 ;
int V_82 , V_190 ;
static struct V_191 V_160 = {
. V_192 = F_103 ,
} ;
T_3 V_25 ;
* V_189 = NULL ;
if ( ( V_82 = F_105 ( V_55 ) ) < 0 )
return V_82 ;
V_2 = F_106 ( sizeof( * V_2 ) , V_164 ) ;
if ( V_2 == NULL ) {
F_101 ( V_55 ) ;
return - V_165 ;
}
V_2 -> V_10 = V_10 ;
V_2 -> V_55 = V_55 ;
V_2 -> V_29 = V_29 ;
F_107 ( & V_2 -> V_84 ) ;
V_2 -> V_54 = - 1 ;
F_108 ( & V_2 -> V_53 ) ;
V_2 -> V_99 [ V_19 ] . V_107 = V_193 * 1024 ;
V_2 -> V_99 [ V_22 ] . V_107 = V_194 * 1024 ;
V_2 -> V_120 = F_109 ( V_55 , 0 ) ;
V_2 -> V_195 = F_109 ( V_55 , 1 ) ;
V_2 -> V_184 = F_110 ( V_2 -> V_195 , V_196 ,
V_10 -> V_121 ) ;
if ( V_2 -> V_184 == NULL ) {
F_15 ( V_10 -> V_11 , L_12 ,
V_2 -> V_195 , V_196 ) ;
V_82 = - V_59 ;
goto V_197;
}
V_2 -> V_4 = F_89 ( V_2 -> V_195 , V_196 ) ;
if ( V_2 -> V_4 == NULL ) {
F_15 ( V_10 -> V_11 , L_13 ,
V_2 -> V_195 ) ;
V_82 = - V_165 ;
goto V_197;
}
if ( ! strcmp ( V_10 -> V_121 , L_14 ) ) {
V_190 = F_3 ( V_2 , V_198 ) ;
if ( ( V_190 & V_199 ) != V_200 ) {
if ( ! V_201 ) {
F_15 ( V_10 -> V_11 ,
L_15 ) ;
F_15 ( V_10 -> V_11 ,
L_16 ) ;
F_15 ( V_10 -> V_11 ,
L_17 ) ;
F_15 ( V_10 -> V_11 ,
L_18 ) ;
V_82 = - V_83 ;
goto V_197;
}
}
V_2 -> V_175 = 2560 * 1024 ;
V_2 -> V_56 = F_74 ;
V_2 -> V_143 = V_202 ;
V_2 -> V_144 = V_203 ;
} else {
if ( F_1 ( V_2 , 0xa0b ) != 0 )
V_2 -> V_175 = 6144 * 1024 ;
else
V_2 -> V_175 = 4096 * 1024 ;
V_2 -> V_56 = F_76 ;
V_2 -> V_143 = V_204 ;
V_2 -> V_144 = V_205 ;
}
V_2 -> V_9 = V_2 -> V_99 [ V_19 ] . V_107 +
V_2 -> V_99 [ V_22 ] . V_107 ;
if ( V_2 -> V_29 )
V_2 -> V_9 += V_32 * 4 ;
else
V_2 -> V_9 += V_206 + V_207 ;
if ( V_208 >= V_2 -> V_9 && V_208 < V_2 -> V_175 )
V_2 -> V_175 = V_208 ;
else {
if ( ( V_82 = F_88 ( V_2 ) ) < 0 )
goto V_197;
}
V_2 -> V_8 = V_2 -> V_175 - V_2 -> V_9 ;
V_2 -> V_120 += V_2 -> V_8 ;
F_91 ( V_10 -> V_11 , L_19 ,
V_2 -> V_8 , V_2 -> V_175 ) ;
V_2 -> V_185 = F_110 ( V_2 -> V_120 ,
V_2 -> V_9 ,
V_10 -> V_121 ) ;
if ( V_2 -> V_185 == NULL ) {
F_15 ( V_10 -> V_11 , L_20 ,
V_2 -> V_120 , V_2 -> V_9 ) ;
V_82 = - V_59 ;
goto V_197;
}
V_2 -> V_12 = F_89 ( V_2 -> V_120 , V_2 -> V_9 ) ;
if ( V_2 -> V_12 == NULL ) {
V_82 = - V_165 ;
F_15 ( V_10 -> V_11 , L_21 ,
V_2 -> V_120 ) ;
goto V_197;
}
V_25 = V_2 -> V_8 ;
V_2 -> V_99 [ V_19 ] . V_64 = V_25 ;
V_25 += V_2 -> V_99 [ V_19 ] . V_107 ;
V_2 -> V_99 [ V_22 ] . V_64 = V_25 ;
V_25 += V_2 -> V_99 [ V_22 ] . V_107 ;
if ( V_2 -> V_29 ) {
V_2 -> V_31 = V_25 ;
} else {
V_2 -> V_17 [ V_19 ] = V_25 ;
V_25 += V_206 ;
V_2 -> V_17 [ V_22 ] = V_25 ;
}
V_2 -> V_151 = V_209 ;
V_2 -> V_30 = 0 ;
F_72 ( V_2 ) ;
if ( ( V_82 = F_111 ( V_10 , V_210 , V_2 , & V_160 ) ) < 0 )
goto V_197;
* V_189 = V_2 ;
return 0 ;
V_197:
F_99 ( V_2 ) ;
return V_82 ;
}
static int F_112 ( struct V_188 * V_55 ,
const struct V_211 * V_212 )
{
struct V_181 * V_10 ;
struct V_1 * V_2 ;
int V_82 ;
const struct V_213 * V_214 ;
V_214 = F_113 ( V_55 , V_215 ) ;
if ( V_214 ) {
F_20 ( & V_55 -> V_11 , L_22 ,
F_114 ( V_214 ) ) ;
switch ( V_214 -> V_155 ) {
case V_216 :
F_91 ( & V_55 -> V_11 ,
L_23 ) ;
return - V_180 ;
case V_217 :
V_153 = 1 ;
case V_218 :
V_152 = 1 ;
break;
}
}
V_82 = F_115 ( & V_55 -> V_11 , V_219 , V_171 , V_220 , 0 , & V_10 ) ;
if ( V_82 < 0 )
return V_82 ;
switch ( V_55 -> V_117 ) {
case V_221 :
strcpy ( V_10 -> V_121 , L_14 ) ;
break;
case V_222 :
strcpy ( V_10 -> V_121 , L_24 ) ;
break;
case V_223 :
strcpy ( V_10 -> V_121 , L_25 ) ;
break;
default:
F_15 ( & V_55 -> V_11 , L_26 , V_55 -> V_117 ) ;
F_116 ( V_10 ) ;
return - V_91 ;
}
if ( V_224 )
V_208 = 0x25a800 ;
if ( V_193 < 4 )
V_193 = 4 ;
if ( V_193 > 128 )
V_193 = 128 ;
if ( V_194 < 4 )
V_194 = 4 ;
if ( V_194 > 128 )
V_194 = 128 ;
if ( ( V_82 = F_104 ( V_10 , V_55 , & V_2 ) ) < 0 ) {
F_116 ( V_10 ) ;
return V_82 ;
}
V_10 -> V_81 = V_2 ;
if ( V_152 ) {
F_20 ( & V_55 -> V_11 , L_27 ) ;
V_2 -> V_152 = 1 ;
}
if ( V_153 ) {
F_20 ( & V_55 -> V_11 , L_28 ) ;
V_2 -> V_153 = 1 ;
}
if ( ( V_82 = F_69 ( V_2 , 0 ) ) < 0 ||
( V_82 = F_85 ( V_2 ) ) < 0 ) {
F_116 ( V_10 ) ;
return V_82 ;
}
sprintf ( V_10 -> V_225 , L_29 , V_10 -> V_121 ) ;
sprintf ( V_10 -> V_226 , L_30 ,
V_10 -> V_225 ,
V_2 -> V_120 , V_2 -> V_195 , V_2 -> V_54 ) ;
if ( ( V_82 = F_117 ( V_10 ) ) < 0 ) {
F_116 ( V_10 ) ;
return V_82 ;
}
F_118 ( V_55 , V_10 ) ;
return 0 ;
}
static void F_119 ( struct V_188 * V_55 )
{
F_116 ( F_120 ( V_55 ) ) ;
}
