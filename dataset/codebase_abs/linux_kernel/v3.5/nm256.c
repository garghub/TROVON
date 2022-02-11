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
F_15 ( V_10 L_1 ,
V_3 , V_7 ) ;
return;
}
#endif
F_16 ( V_2 -> V_11 + V_3 , V_6 , V_7 ) ;
}
static T_2
F_17 ( int V_12 )
{
T_2 V_3 = 0 ;
while ( V_12 -- > 0 )
V_3 += V_13 [ V_12 ] ;
return V_3 ;
}
static void
F_18 ( struct V_1 * V_2 , int V_14 , T_3 V_15 , int V_12 )
{
T_3 V_16 = V_2 -> V_16 [ V_14 ] ;
T_2 V_3 = F_17 ( V_12 ) ;
T_2 V_7 = V_13 [ V_12 ] ;
F_13 ( V_2 , V_17 + V_3 , V_16 , V_7 ) ;
F_11 ( V_2 , V_15 , V_16 ) ;
if ( V_14 == V_18 )
V_7 -- ;
F_11 ( V_2 , V_15 + 4 , V_16 + V_7 ) ;
}
static void
F_19 ( struct V_1 * V_2 , int V_14 , int V_19 )
{
T_3 V_20 = ( V_14 == V_21 ?
V_22 : V_23 ) ;
T_3 V_24 = V_25 ;
V_24 += ( V_14 == V_21 ?
V_26 : V_27 ) ;
if ( F_1 ( V_2 , V_20 ) & 1 ) {
F_20 ( L_2 ) ;
return;
}
V_19 &= 7 ;
if ( V_14 == V_21 )
V_19 += 8 ;
if ( ! V_2 -> V_28 ) {
F_18 ( V_2 , V_14 , V_24 , V_19 ) ;
return;
}
if ( ! V_2 -> V_29 ) {
F_13 ( V_2 , V_17 , V_2 -> V_30 ,
V_31 * 4 ) ;
V_2 -> V_29 = 1 ;
} else {
T_3 V_32 = V_2 -> V_30 ;
T_3 V_3 = F_17 ( V_19 ) ;
T_3 V_33 = V_3 + V_13 [ V_19 ] ;
F_11 ( V_2 , V_24 , V_32 + V_3 ) ;
if ( V_14 == V_18 )
V_33 -- ;
F_11 ( V_2 , V_24 + 4 , V_32 + V_33 ) ;
}
}
static int
F_21 ( unsigned int V_34 )
{
unsigned int V_35 ;
for ( V_35 = 0 ; V_35 < F_22 ( V_36 ) ; V_35 ++ ) {
if ( V_34 == V_36 [ V_35 ] )
return V_35 ;
}
F_23 () ;
return 0 ;
}
static void
F_24 ( struct V_1 * V_2 , struct V_37 * V_38 ,
struct V_39 * V_40 )
{
struct V_41 * V_42 = V_40 -> V_42 ;
int V_43 = F_21 ( V_42 -> V_34 ) ;
unsigned char V_44 = ( V_43 << 4 ) & V_45 ;
V_38 -> V_46 = 0 ;
if ( F_25 ( V_42 -> V_47 ) == 16 ) {
V_44 |= V_48 ;
V_38 -> V_46 ++ ;
}
if ( V_42 -> V_49 > 1 ) {
V_44 |= V_50 ;
V_38 -> V_46 ++ ;
}
V_42 -> V_34 = V_36 [ V_43 ] ;
switch ( V_40 -> V_14 ) {
case V_18 :
F_19 ( V_2 , 0 , V_43 ) ;
F_7 ( V_2 ,
V_27 + V_51 ,
V_44 ) ;
break;
case V_21 :
F_19 ( V_2 , 1 , V_43 ) ;
F_7 ( V_2 ,
V_26 + V_51 ,
V_44 ) ;
break;
}
}
static int F_26 ( struct V_1 * V_2 )
{
F_27 ( & V_2 -> V_52 ) ;
if ( V_2 -> V_53 < 0 ) {
if ( F_28 ( V_2 -> V_54 -> V_53 , V_2 -> V_55 , V_56 ,
V_57 , V_2 ) ) {
F_15 ( V_10 L_3 , V_2 -> V_54 -> V_53 ) ;
F_29 ( & V_2 -> V_52 ) ;
return - V_58 ;
}
V_2 -> V_53 = V_2 -> V_54 -> V_53 ;
}
V_2 -> V_59 ++ ;
F_29 ( & V_2 -> V_52 ) ;
return 0 ;
}
static void F_30 ( struct V_1 * V_2 )
{
F_27 ( & V_2 -> V_52 ) ;
if ( V_2 -> V_59 > 0 )
V_2 -> V_59 -- ;
if ( V_2 -> V_59 == 0 && V_2 -> V_53 >= 0 ) {
F_31 ( V_2 -> V_53 , V_2 ) ;
V_2 -> V_53 = - 1 ;
}
F_29 ( & V_2 -> V_52 ) ;
}
static void F_32 ( struct V_1 * V_2 , struct V_37 * V_38 , int V_60 )
{
V_38 -> V_61 ++ ;
V_38 -> V_61 %= V_38 -> V_62 ;
F_11 ( V_2 , V_60 , V_38 -> V_63 + V_38 -> V_61 * V_38 -> V_64 ) ;
}
static void
F_33 ( struct V_1 * V_2 , struct V_37 * V_38 ,
struct V_39 * V_40 )
{
F_11 ( V_2 , V_65 , V_38 -> V_63 ) ;
F_11 ( V_2 , V_66 , V_38 -> V_63 + V_38 -> V_67 - ( 1 << V_38 -> V_46 ) ) ;
F_11 ( V_2 , V_68 , V_38 -> V_63 ) ;
F_34 ( V_2 , V_38 ) ;
F_7 ( V_2 , V_23 ,
V_69 | V_70 ) ;
F_9 ( V_2 , V_71 , 0x0 ) ;
}
static void
F_35 ( struct V_1 * V_2 , struct V_37 * V_38 ,
struct V_39 * V_40 )
{
F_11 ( V_2 , V_72 , V_38 -> V_63 ) ;
F_11 ( V_2 , V_73 , V_38 -> V_63 + V_38 -> V_67 ) ;
F_11 ( V_2 , V_74 , V_38 -> V_63 ) ;
F_36 ( V_2 , V_38 ) ;
F_7 ( V_2 , V_22 ,
V_75 | V_76 ) ;
}
static void
F_37 ( struct V_1 * V_2 )
{
F_9 ( V_2 , V_71 ,
V_77 | V_78 ) ;
F_7 ( V_2 , V_23 , 0 ) ;
}
static void
F_38 ( struct V_1 * V_2 )
{
F_7 ( V_2 , V_22 , 0 ) ;
}
static int
F_39 ( struct V_39 * V_40 , int V_79 )
{
struct V_1 * V_2 = F_40 ( V_40 ) ;
struct V_37 * V_38 = V_40 -> V_42 -> V_80 ;
int V_81 = 0 ;
if ( F_41 ( ! V_38 ) )
return - V_82 ;
F_42 ( & V_2 -> V_83 ) ;
switch ( V_79 ) {
case V_84 :
V_38 -> V_85 = 0 ;
case V_86 :
if ( ! V_38 -> V_87 ) {
F_33 ( V_2 , V_38 , V_40 ) ;
V_38 -> V_87 = 1 ;
}
break;
case V_88 :
V_38 -> V_85 = 1 ;
case V_89 :
if ( V_38 -> V_87 ) {
F_37 ( V_2 ) ;
V_38 -> V_87 = 0 ;
}
break;
default:
V_81 = - V_90 ;
break;
}
F_43 ( & V_2 -> V_83 ) ;
return V_81 ;
}
static int
F_44 ( struct V_39 * V_40 , int V_79 )
{
struct V_1 * V_2 = F_40 ( V_40 ) ;
struct V_37 * V_38 = V_40 -> V_42 -> V_80 ;
int V_81 = 0 ;
if ( F_41 ( ! V_38 ) )
return - V_82 ;
F_42 ( & V_2 -> V_83 ) ;
switch ( V_79 ) {
case V_86 :
case V_84 :
if ( ! V_38 -> V_87 ) {
F_35 ( V_2 , V_38 , V_40 ) ;
V_38 -> V_87 = 1 ;
}
break;
case V_89 :
case V_88 :
if ( V_38 -> V_87 ) {
F_38 ( V_2 ) ;
V_38 -> V_87 = 0 ;
}
break;
default:
V_81 = - V_90 ;
break;
}
F_43 ( & V_2 -> V_83 ) ;
return V_81 ;
}
static int F_45 ( struct V_39 * V_40 )
{
struct V_1 * V_2 = F_40 ( V_40 ) ;
struct V_41 * V_42 = V_40 -> V_42 ;
struct V_37 * V_38 = V_42 -> V_80 ;
if ( F_41 ( ! V_38 ) )
return - V_82 ;
V_38 -> V_67 = F_46 ( V_42 , V_40 -> V_42 -> V_9 ) ;
V_38 -> V_64 = F_46 ( V_42 , V_40 -> V_42 -> V_64 ) ;
V_38 -> V_62 = V_40 -> V_42 -> V_62 ;
V_38 -> V_61 = 0 ;
F_47 ( & V_2 -> V_83 ) ;
V_38 -> V_87 = 0 ;
F_24 ( V_2 , V_38 , V_40 ) ;
F_48 ( & V_2 -> V_83 ) ;
return 0 ;
}
static T_4
F_49 ( struct V_39 * V_40 )
{
struct V_1 * V_2 = F_40 ( V_40 ) ;
struct V_37 * V_38 = V_40 -> V_42 -> V_80 ;
unsigned long V_91 ;
if ( F_41 ( ! V_38 ) )
return 0 ;
V_91 = F_5 ( V_2 , V_68 ) - ( unsigned long ) V_38 -> V_63 ;
V_91 %= V_38 -> V_67 ;
return F_50 ( V_40 -> V_42 , V_91 ) ;
}
static T_4
F_51 ( struct V_39 * V_40 )
{
struct V_1 * V_2 = F_40 ( V_40 ) ;
struct V_37 * V_38 = V_40 -> V_42 -> V_80 ;
unsigned long V_91 ;
if ( F_41 ( ! V_38 ) )
return 0 ;
V_91 = F_5 ( V_2 , V_74 ) - ( unsigned long ) V_38 -> V_63 ;
V_91 %= V_38 -> V_67 ;
return F_50 ( V_40 -> V_42 , V_91 ) ;
}
static int
F_52 ( struct V_39 * V_40 ,
int V_92 ,
T_4 V_93 ,
T_4 V_94 )
{
struct V_41 * V_42 = V_40 -> V_42 ;
struct V_37 * V_38 = V_42 -> V_80 ;
V_94 = F_46 ( V_42 , V_94 ) ;
V_93 = F_46 ( V_42 , V_93 ) ;
F_53 ( V_38 -> V_95 + V_93 , 0 , V_94 ) ;
return 0 ;
}
static int
F_54 ( struct V_39 * V_40 ,
int V_92 ,
T_4 V_93 ,
void T_5 * V_6 ,
T_4 V_94 )
{
struct V_41 * V_42 = V_40 -> V_42 ;
struct V_37 * V_38 = V_42 -> V_80 ;
V_94 = F_46 ( V_42 , V_94 ) ;
V_93 = F_46 ( V_42 , V_93 ) ;
if ( F_55 ( V_38 -> V_95 + V_93 , V_6 , V_94 ) )
return - V_96 ;
return 0 ;
}
static int
F_56 ( struct V_39 * V_40 ,
int V_92 ,
T_4 V_93 ,
void T_5 * V_97 ,
T_4 V_94 )
{
struct V_41 * V_42 = V_40 -> V_42 ;
struct V_37 * V_38 = V_42 -> V_80 ;
V_94 = F_46 ( V_42 , V_94 ) ;
V_93 = F_46 ( V_42 , V_93 ) ;
if ( F_57 ( V_97 , V_38 -> V_95 + V_93 , V_94 ) )
return - V_96 ;
return 0 ;
}
static void
F_58 ( struct V_1 * V_2 )
{
struct V_37 * V_38 ;
V_38 = & V_2 -> V_98 [ V_18 ] ;
if ( V_38 -> V_87 && V_38 -> V_40 ) {
F_43 ( & V_2 -> V_83 ) ;
F_59 ( V_38 -> V_40 ) ;
F_42 ( & V_2 -> V_83 ) ;
F_34 ( V_2 , V_38 ) ;
}
}
static void
F_60 ( struct V_1 * V_2 )
{
struct V_37 * V_38 ;
V_38 = & V_2 -> V_98 [ V_21 ] ;
if ( V_38 -> V_87 && V_38 -> V_40 ) {
F_43 ( & V_2 -> V_83 ) ;
F_59 ( V_38 -> V_40 ) ;
F_42 ( & V_2 -> V_83 ) ;
F_36 ( V_2 , V_38 ) ;
}
}
static int F_61 ( struct V_39 * V_40 ,
struct V_99 * V_100 )
{
V_40 -> V_42 -> V_101 = F_62 ( V_100 ) ;
return 0 ;
}
static void F_63 ( struct V_1 * V_2 , struct V_37 * V_38 ,
struct V_39 * V_40 ,
struct V_102 * V_103 )
{
struct V_41 * V_42 = V_40 -> V_42 ;
V_38 -> V_87 = 0 ;
V_42 -> V_104 = * V_103 ;
V_42 -> V_104 . V_105 = V_38 -> V_106 ;
V_42 -> V_104 . V_107 = V_38 -> V_106 / 2 ;
V_42 -> V_108 = ( void V_109 * ) V_38 -> V_95 ;
V_42 -> V_110 = V_38 -> V_111 ;
V_42 -> V_101 = V_38 -> V_106 ;
V_42 -> V_80 = V_38 ;
V_38 -> V_40 = V_40 ;
F_64 ( V_42 , 0 , V_112 ,
& V_113 ) ;
}
static int
F_65 ( struct V_39 * V_40 )
{
struct V_1 * V_2 = F_40 ( V_40 ) ;
if ( F_26 ( V_2 ) < 0 )
return - V_58 ;
F_63 ( V_2 , & V_2 -> V_98 [ V_18 ] ,
V_40 , & V_114 ) ;
return 0 ;
}
static int
F_66 ( struct V_39 * V_40 )
{
struct V_1 * V_2 = F_40 ( V_40 ) ;
if ( F_26 ( V_2 ) < 0 )
return - V_58 ;
F_63 ( V_2 , & V_2 -> V_98 [ V_21 ] ,
V_40 , & V_115 ) ;
return 0 ;
}
static int
F_67 ( struct V_39 * V_40 )
{
struct V_1 * V_2 = F_40 ( V_40 ) ;
F_30 ( V_2 ) ;
return 0 ;
}
static int
F_68 ( struct V_39 * V_40 )
{
struct V_1 * V_2 = F_40 ( V_40 ) ;
F_30 ( V_2 ) ;
return 0 ;
}
static int T_6
F_69 ( struct V_1 * V_2 , int V_116 )
{
struct V_117 * V_118 ;
int V_35 , V_81 ;
for ( V_35 = 0 ; V_35 < 2 ; V_35 ++ ) {
struct V_37 * V_38 = & V_2 -> V_98 [ V_35 ] ;
V_38 -> V_95 = V_2 -> V_11 + ( V_38 -> V_63 - V_2 -> V_8 ) ;
V_38 -> V_111 = V_2 -> V_119 + ( V_38 -> V_63 - V_2 -> V_8 ) ;
}
V_81 = F_70 ( V_2 -> V_120 , V_2 -> V_120 -> V_121 , V_116 ,
1 , 1 , & V_118 ) ;
if ( V_81 < 0 )
return V_81 ;
F_71 ( V_118 , V_18 , & V_122 ) ;
F_71 ( V_118 , V_21 , & V_123 ) ;
V_118 -> V_80 = V_2 ;
V_118 -> V_124 = 0 ;
V_2 -> V_118 = V_118 ;
return 0 ;
}
static void
F_72 ( struct V_1 * V_2 )
{
F_7 ( V_2 , 0x0 , 0x11 ) ;
F_9 ( V_2 , 0x214 , 0 ) ;
}
static T_7
F_73 ( struct V_1 * V_2 )
{
if ( V_2 -> V_125 ++ > 1000 ) {
if ( V_2 -> V_98 [ V_18 ] . V_87 )
F_37 ( V_2 ) ;
if ( V_2 -> V_98 [ V_21 ] . V_87 )
F_38 ( V_2 ) ;
V_2 -> V_125 = 0 ;
return V_126 ;
}
return V_127 ;
}
static T_7
F_74 ( int V_53 , void * V_128 )
{
struct V_1 * V_2 = V_128 ;
T_2 V_129 ;
T_1 V_130 ;
V_129 = F_3 ( V_2 , V_131 ) ;
if ( V_129 == 0 )
return F_73 ( V_2 ) ;
V_2 -> V_125 = 0 ;
F_42 ( & V_2 -> V_83 ) ;
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
F_20 ( L_4 ) ;
F_9 ( V_2 , V_131 , 0x8000 ) ;
V_130 = F_1 ( V_2 , 0x400 ) ;
F_7 ( V_2 , 0x400 , V_130 | 2 ) ;
}
if ( V_129 & V_135 ) {
V_129 &= ~ V_135 ;
F_75 ( V_2 , V_135 ) ;
F_20 ( L_5 ) ;
V_130 = F_1 ( V_2 , 0x400 ) ;
F_7 ( V_2 , 0x400 , V_130 & ~ 2 ) ;
}
if ( V_129 ) {
F_20 ( L_6 ,
V_129 ) ;
F_75 ( V_2 , V_129 ) ;
}
F_43 ( & V_2 -> V_83 ) ;
return V_126 ;
}
static T_7
F_76 ( int V_53 , void * V_128 )
{
struct V_1 * V_2 = V_128 ;
T_3 V_129 ;
T_1 V_130 ;
V_129 = F_5 ( V_2 , V_131 ) ;
if ( V_129 == 0 )
return F_73 ( V_2 ) ;
V_2 -> V_125 = 0 ;
F_42 ( & V_2 -> V_83 ) ;
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
F_20 ( L_4 ) ;
V_130 = F_1 ( V_2 , 0x400 ) ;
F_7 ( V_2 , 0x400 , V_130 | 2 ) ;
}
if ( V_129 & V_139 ) {
V_129 &= ~ V_139 ;
F_77 ( V_2 , V_139 ) ;
F_20 ( L_5 ) ;
V_130 = F_1 ( V_2 , 0x400 ) ;
F_7 ( V_2 , 0x400 , V_130 & ~ 2 ) ;
}
if ( V_129 ) {
F_20 ( L_6 ,
V_129 ) ;
F_77 ( V_2 , V_129 ) ;
}
F_43 ( & V_2 -> V_83 ) ;
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
static int F_80 ( unsigned short V_60 )
{
int V_35 ;
for ( V_35 = 0 ; V_35 < F_22 ( V_145 ) ; V_35 ++ )
if ( V_145 [ V_35 ] . V_60 == V_60 )
return V_35 ;
return - 1 ;
}
static unsigned short
F_81 ( struct V_146 * V_147 , unsigned short V_60 )
{
struct V_1 * V_2 = V_147 -> V_80 ;
int V_148 = F_80 ( V_60 ) ;
if ( V_148 < 0 )
return 0 ;
return V_2 -> V_149 [ V_148 ] ;
}
static void
F_82 ( struct V_146 * V_147 ,
unsigned short V_60 , unsigned short V_5 )
{
struct V_1 * V_2 = V_147 -> V_80 ;
int V_150 = 2 ;
int V_148 = F_80 ( V_60 ) ;
T_3 V_32 ;
if ( V_148 < 0 )
return;
V_32 = V_2 -> V_151 ;
F_78 ( V_2 ) ;
while ( V_150 -- > 0 ) {
F_9 ( V_2 , V_32 + V_60 , V_5 ) ;
F_83 ( 1 ) ;
if ( F_78 ( V_2 ) ) {
V_2 -> V_149 [ V_148 ] = V_5 ;
return;
}
}
F_20 ( L_7 ) ;
}
static void
F_84 ( struct V_146 * V_147 )
{
struct V_1 * V_2 = V_147 -> V_80 ;
F_7 ( V_2 , 0x6c0 , 1 ) ;
if ( ! V_2 -> V_152 ) {
F_7 ( V_2 , 0x6cc , 0x87 ) ;
}
if ( ! V_2 -> V_153 ) {
F_7 ( V_2 , 0x6cc , 0x80 ) ;
F_7 ( V_2 , 0x6cc , 0x0 ) ;
}
if ( ! V_2 -> V_154 ) {
int V_35 ;
for ( V_35 = 0 ; V_35 < F_22 ( V_145 ) ; V_35 ++ ) {
F_82 ( V_147 , V_145 [ V_35 ] . V_60 ,
V_145 [ V_35 ] . V_155 ) ;
}
}
}
static int T_6
F_85 ( struct V_1 * V_2 )
{
struct V_156 * V_157 ;
struct V_158 V_147 ;
int V_81 ;
static struct V_159 V_160 = {
. V_161 = F_84 ,
. V_162 = F_82 ,
. V_163 = F_81 ,
} ;
V_2 -> V_149 = F_86 ( F_22 ( V_145 ) ,
sizeof( short ) , V_164 ) ;
if ( ! V_2 -> V_149 )
return - V_165 ;
if ( ( V_81 = V_156 ( V_2 -> V_120 , 0 , & V_160 , NULL , & V_157 ) ) < 0 )
return V_81 ;
memset ( & V_147 , 0 , sizeof( V_147 ) ) ;
V_147 . V_166 = V_167 ;
V_147 . V_80 = V_2 ;
V_147 . V_168 = V_169 ;
V_157 -> V_170 = 1 ;
V_81 = F_87 ( V_157 , & V_147 , & V_2 -> V_147 ) ;
if ( V_81 < 0 )
return V_81 ;
if ( ! ( V_2 -> V_147 -> V_171 & ( 0xf0000000 ) ) ) {
sprintf ( V_2 -> V_120 -> V_172 , L_8 , V_2 -> V_120 -> V_121 ) ;
}
return 0 ;
}
static int T_6
F_88 ( struct V_1 * V_2 )
{
void T_8 * V_173 ;
unsigned long V_174 = V_2 -> V_175 - 0x1400 ;
T_3 V_176 ;
V_173 = F_89 ( V_2 -> V_119 + V_2 -> V_175 - 0x400 , 16 ) ;
if ( V_173 == NULL ) {
F_15 ( V_10 L_9 ) ;
return - V_58 ;
}
V_176 = F_6 ( V_173 ) ;
if ( ( V_176 & V_177 ) == V_178 ) {
T_3 V_179 = F_6 ( V_173 + 4 ) ;
if ( V_179 == 0xffffffff ||
V_179 < V_2 -> V_9 ||
V_179 > V_2 -> V_175 ) {
F_15 ( V_10 L_10 , V_179 ) ;
F_90 ( V_173 ) ;
return - V_180 ;
} else {
V_174 = V_179 ;
F_91 ( V_181 L_11 ,
V_179 ) ;
}
}
F_90 ( V_173 ) ;
V_2 -> V_175 = V_174 ;
return 0 ;
}
static int F_92 ( struct V_182 * V_54 , T_9 V_183 )
{
struct V_184 * V_120 = F_93 ( V_54 ) ;
struct V_1 * V_2 = V_120 -> V_80 ;
F_94 ( V_120 , V_185 ) ;
F_95 ( V_2 -> V_118 ) ;
F_96 ( V_2 -> V_147 ) ;
V_2 -> V_29 = 0 ;
F_97 ( V_54 ) ;
F_98 ( V_54 ) ;
F_99 ( V_54 , F_100 ( V_54 , V_183 ) ) ;
return 0 ;
}
static int F_101 ( struct V_182 * V_54 )
{
struct V_184 * V_120 = F_93 ( V_54 ) ;
struct V_1 * V_2 = V_120 -> V_80 ;
int V_35 ;
V_2 -> V_154 = 1 ;
F_99 ( V_54 , V_186 ) ;
F_102 ( V_54 ) ;
if ( F_103 ( V_54 ) < 0 ) {
F_91 ( V_10 L_12
L_13 ) ;
F_104 ( V_120 ) ;
return - V_187 ;
}
F_105 ( V_54 ) ;
F_72 ( V_2 ) ;
F_106 ( V_2 -> V_147 ) ;
for ( V_35 = 0 ; V_35 < 2 ; V_35 ++ ) {
struct V_37 * V_38 = & V_2 -> V_98 [ V_35 ] ;
if ( V_38 -> V_40 && V_38 -> V_85 ) {
F_47 ( & V_2 -> V_83 ) ;
F_24 ( V_2 , V_38 , V_38 -> V_40 ) ;
F_48 ( & V_2 -> V_83 ) ;
}
}
F_94 ( V_120 , V_188 ) ;
V_2 -> V_154 = 0 ;
return 0 ;
}
static int F_107 ( struct V_1 * V_2 )
{
if ( V_2 -> V_98 [ V_18 ] . V_87 )
F_37 ( V_2 ) ;
if ( V_2 -> V_98 [ V_21 ] . V_87 )
F_38 ( V_2 ) ;
if ( V_2 -> V_53 >= 0 )
F_31 ( V_2 -> V_53 , V_2 ) ;
if ( V_2 -> V_4 )
F_90 ( V_2 -> V_4 ) ;
if ( V_2 -> V_11 )
F_90 ( V_2 -> V_11 ) ;
F_108 ( V_2 -> V_189 ) ;
F_108 ( V_2 -> V_190 ) ;
F_97 ( V_2 -> V_54 ) ;
F_109 ( V_2 -> V_149 ) ;
F_109 ( V_2 ) ;
return 0 ;
}
static int F_110 ( struct V_191 * V_116 )
{
struct V_1 * V_2 = V_116 -> V_192 ;
return F_107 ( V_2 ) ;
}
static int T_6
F_111 ( struct V_184 * V_120 , struct V_182 * V_54 ,
struct V_1 * * V_193 )
{
struct V_1 * V_2 ;
int V_81 , V_194 ;
static struct V_195 V_160 = {
. V_196 = F_110 ,
} ;
T_3 V_24 ;
* V_193 = NULL ;
if ( ( V_81 = F_103 ( V_54 ) ) < 0 )
return V_81 ;
V_2 = F_112 ( sizeof( * V_2 ) , V_164 ) ;
if ( V_2 == NULL ) {
F_97 ( V_54 ) ;
return - V_165 ;
}
V_2 -> V_120 = V_120 ;
V_2 -> V_54 = V_54 ;
V_2 -> V_28 = V_28 ;
F_113 ( & V_2 -> V_83 ) ;
V_2 -> V_53 = - 1 ;
F_114 ( & V_2 -> V_52 ) ;
V_2 -> V_98 [ V_18 ] . V_106 = V_197 * 1024 ;
V_2 -> V_98 [ V_21 ] . V_106 = V_198 * 1024 ;
V_2 -> V_119 = F_115 ( V_54 , 0 ) ;
V_2 -> V_199 = F_115 ( V_54 , 1 ) ;
V_2 -> V_189 = F_116 ( V_2 -> V_199 , V_200 ,
V_120 -> V_121 ) ;
if ( V_2 -> V_189 == NULL ) {
F_15 ( V_10 L_14 ,
V_2 -> V_199 , V_200 ) ;
V_81 = - V_58 ;
goto V_201;
}
V_2 -> V_4 = F_89 ( V_2 -> V_199 , V_200 ) ;
if ( V_2 -> V_4 == NULL ) {
F_15 ( V_10 L_15 , V_2 -> V_199 ) ;
V_81 = - V_165 ;
goto V_201;
}
if ( ! strcmp ( V_120 -> V_121 , L_16 ) ) {
V_194 = F_3 ( V_2 , V_202 ) ;
if ( ( V_194 & V_203 ) != V_204 ) {
if ( ! V_205 ) {
F_91 ( V_10 L_17 ) ;
F_91 ( V_10 L_18
L_19 ) ;
F_91 ( V_10 L_20 ) ;
F_91 ( V_10 L_21
L_22 ) ;
V_81 = - V_82 ;
goto V_201;
}
}
V_2 -> V_175 = 2560 * 1024 ;
V_2 -> V_55 = F_74 ;
V_2 -> V_143 = V_206 ;
V_2 -> V_144 = V_207 ;
} else {
if ( F_1 ( V_2 , 0xa0b ) != 0 )
V_2 -> V_175 = 6144 * 1024 ;
else
V_2 -> V_175 = 4096 * 1024 ;
V_2 -> V_55 = F_76 ;
V_2 -> V_143 = V_208 ;
V_2 -> V_144 = V_209 ;
}
V_2 -> V_9 = V_2 -> V_98 [ V_18 ] . V_106 +
V_2 -> V_98 [ V_21 ] . V_106 ;
if ( V_2 -> V_28 )
V_2 -> V_9 += V_31 * 4 ;
else
V_2 -> V_9 += V_210 + V_211 ;
if ( V_212 >= V_2 -> V_9 && V_212 < V_2 -> V_175 )
V_2 -> V_175 = V_212 ;
else {
if ( ( V_81 = F_88 ( V_2 ) ) < 0 )
goto V_201;
}
V_2 -> V_8 = V_2 -> V_175 - V_2 -> V_9 ;
V_2 -> V_119 += V_2 -> V_8 ;
F_91 ( V_181 L_23 ,
V_2 -> V_8 , V_2 -> V_175 ) ;
V_2 -> V_190 = F_116 ( V_2 -> V_119 ,
V_2 -> V_9 ,
V_120 -> V_121 ) ;
if ( V_2 -> V_190 == NULL ) {
F_15 ( V_10 L_24 ,
V_2 -> V_119 , V_2 -> V_9 ) ;
V_81 = - V_58 ;
goto V_201;
}
V_2 -> V_11 = F_89 ( V_2 -> V_119 , V_2 -> V_9 ) ;
if ( V_2 -> V_11 == NULL ) {
V_81 = - V_165 ;
F_15 ( V_10 L_25 , V_2 -> V_119 ) ;
goto V_201;
}
V_24 = V_2 -> V_8 ;
V_2 -> V_98 [ V_18 ] . V_63 = V_24 ;
V_24 += V_2 -> V_98 [ V_18 ] . V_106 ;
V_2 -> V_98 [ V_21 ] . V_63 = V_24 ;
V_24 += V_2 -> V_98 [ V_21 ] . V_106 ;
if ( V_2 -> V_28 ) {
V_2 -> V_30 = V_24 ;
} else {
V_2 -> V_16 [ V_18 ] = V_24 ;
V_24 += V_210 ;
V_2 -> V_16 [ V_21 ] = V_24 ;
}
V_2 -> V_151 = V_213 ;
V_2 -> V_29 = 0 ;
F_72 ( V_2 ) ;
if ( ( V_81 = F_117 ( V_120 , V_214 , V_2 , & V_160 ) ) < 0 )
goto V_201;
F_118 ( V_120 , & V_54 -> V_215 ) ;
* V_193 = V_2 ;
return 0 ;
V_201:
F_107 ( V_2 ) ;
return V_81 ;
}
static int T_6 F_119 ( struct V_182 * V_54 ,
const struct V_216 * V_217 )
{
struct V_184 * V_120 ;
struct V_1 * V_2 ;
int V_81 ;
const struct V_218 * V_219 ;
V_219 = F_120 ( V_54 , V_220 ) ;
if ( V_219 ) {
F_121 ( V_181 L_26 , V_219 -> V_221 ) ;
switch ( V_219 -> V_155 ) {
case V_222 :
F_91 ( V_181 L_27
L_28 ) ;
return - V_180 ;
case V_223 :
V_153 = 1 ;
case V_224 :
V_152 = 1 ;
break;
}
}
V_81 = F_122 ( V_225 , V_171 , V_226 , 0 , & V_120 ) ;
if ( V_81 < 0 )
return V_81 ;
switch ( V_54 -> V_116 ) {
case V_227 :
strcpy ( V_120 -> V_121 , L_16 ) ;
break;
case V_228 :
strcpy ( V_120 -> V_121 , L_29 ) ;
break;
case V_229 :
strcpy ( V_120 -> V_121 , L_30 ) ;
break;
default:
F_15 ( V_10 L_31 , V_54 -> V_116 ) ;
F_123 ( V_120 ) ;
return - V_90 ;
}
if ( V_230 )
V_212 = 0x25a800 ;
if ( V_197 < 4 )
V_197 = 4 ;
if ( V_197 > 128 )
V_197 = 128 ;
if ( V_198 < 4 )
V_198 = 4 ;
if ( V_198 > 128 )
V_198 = 128 ;
if ( ( V_81 = F_111 ( V_120 , V_54 , & V_2 ) ) < 0 ) {
F_123 ( V_120 ) ;
return V_81 ;
}
V_120 -> V_80 = V_2 ;
if ( V_152 ) {
F_121 ( V_181 L_32 ) ;
V_2 -> V_152 = 1 ;
}
if ( V_153 ) {
F_121 ( V_181 L_33 ) ;
V_2 -> V_153 = 1 ;
}
if ( ( V_81 = F_69 ( V_2 , 0 ) ) < 0 ||
( V_81 = F_85 ( V_2 ) ) < 0 ) {
F_123 ( V_120 ) ;
return V_81 ;
}
sprintf ( V_120 -> V_231 , L_34 , V_120 -> V_121 ) ;
sprintf ( V_120 -> V_232 , L_35 ,
V_120 -> V_231 ,
V_2 -> V_119 , V_2 -> V_199 , V_2 -> V_53 ) ;
if ( ( V_81 = F_124 ( V_120 ) ) < 0 ) {
F_123 ( V_120 ) ;
return V_81 ;
}
F_125 ( V_54 , V_120 ) ;
return 0 ;
}
static void T_10 F_126 ( struct V_182 * V_54 )
{
F_123 ( F_93 ( V_54 ) ) ;
F_125 ( V_54 , NULL ) ;
}
