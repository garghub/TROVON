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
V_2 -> V_57 -> V_58 , V_2 ) ) {
F_15 ( V_10 L_3 , V_2 -> V_54 -> V_53 ) ;
F_29 ( & V_2 -> V_52 ) ;
return - V_59 ;
}
V_2 -> V_53 = V_2 -> V_54 -> V_53 ;
}
V_2 -> V_60 ++ ;
F_29 ( & V_2 -> V_52 ) ;
return 0 ;
}
static void F_30 ( struct V_1 * V_2 )
{
F_27 ( & V_2 -> V_52 ) ;
if ( V_2 -> V_60 > 0 )
V_2 -> V_60 -- ;
if ( V_2 -> V_60 == 0 && V_2 -> V_53 >= 0 ) {
F_31 ( V_2 -> V_53 , V_2 ) ;
V_2 -> V_53 = - 1 ;
}
F_29 ( & V_2 -> V_52 ) ;
}
static void F_32 ( struct V_1 * V_2 , struct V_37 * V_38 , int V_61 )
{
V_38 -> V_62 ++ ;
V_38 -> V_62 %= V_38 -> V_63 ;
F_11 ( V_2 , V_61 , V_38 -> V_64 + V_38 -> V_62 * V_38 -> V_65 ) ;
}
static void
F_33 ( struct V_1 * V_2 , struct V_37 * V_38 ,
struct V_39 * V_40 )
{
F_11 ( V_2 , V_66 , V_38 -> V_64 ) ;
F_11 ( V_2 , V_67 , V_38 -> V_64 + V_38 -> V_68 - ( 1 << V_38 -> V_46 ) ) ;
F_11 ( V_2 , V_69 , V_38 -> V_64 ) ;
F_34 ( V_2 , V_38 ) ;
F_7 ( V_2 , V_23 ,
V_70 | V_71 ) ;
F_9 ( V_2 , V_72 , 0x0 ) ;
}
static void
F_35 ( struct V_1 * V_2 , struct V_37 * V_38 ,
struct V_39 * V_40 )
{
F_11 ( V_2 , V_73 , V_38 -> V_64 ) ;
F_11 ( V_2 , V_74 , V_38 -> V_64 + V_38 -> V_68 ) ;
F_11 ( V_2 , V_75 , V_38 -> V_64 ) ;
F_36 ( V_2 , V_38 ) ;
F_7 ( V_2 , V_22 ,
V_76 | V_77 ) ;
}
static void
F_37 ( struct V_1 * V_2 )
{
F_9 ( V_2 , V_72 ,
V_78 | V_79 ) ;
F_7 ( V_2 , V_23 , 0 ) ;
}
static void
F_38 ( struct V_1 * V_2 )
{
F_7 ( V_2 , V_22 , 0 ) ;
}
static int
F_39 ( struct V_39 * V_40 , int V_80 )
{
struct V_1 * V_2 = F_40 ( V_40 ) ;
struct V_37 * V_38 = V_40 -> V_42 -> V_81 ;
int V_82 = 0 ;
if ( F_41 ( ! V_38 ) )
return - V_83 ;
F_42 ( & V_2 -> V_84 ) ;
switch ( V_80 ) {
case V_85 :
V_38 -> V_86 = 0 ;
case V_87 :
if ( ! V_38 -> V_88 ) {
F_33 ( V_2 , V_38 , V_40 ) ;
V_38 -> V_88 = 1 ;
}
break;
case V_89 :
V_38 -> V_86 = 1 ;
case V_90 :
if ( V_38 -> V_88 ) {
F_37 ( V_2 ) ;
V_38 -> V_88 = 0 ;
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
F_44 ( struct V_39 * V_40 , int V_80 )
{
struct V_1 * V_2 = F_40 ( V_40 ) ;
struct V_37 * V_38 = V_40 -> V_42 -> V_81 ;
int V_82 = 0 ;
if ( F_41 ( ! V_38 ) )
return - V_83 ;
F_42 ( & V_2 -> V_84 ) ;
switch ( V_80 ) {
case V_87 :
case V_85 :
if ( ! V_38 -> V_88 ) {
F_35 ( V_2 , V_38 , V_40 ) ;
V_38 -> V_88 = 1 ;
}
break;
case V_90 :
case V_89 :
if ( V_38 -> V_88 ) {
F_38 ( V_2 ) ;
V_38 -> V_88 = 0 ;
}
break;
default:
V_82 = - V_91 ;
break;
}
F_43 ( & V_2 -> V_84 ) ;
return V_82 ;
}
static int F_45 ( struct V_39 * V_40 )
{
struct V_1 * V_2 = F_40 ( V_40 ) ;
struct V_41 * V_42 = V_40 -> V_42 ;
struct V_37 * V_38 = V_42 -> V_81 ;
if ( F_41 ( ! V_38 ) )
return - V_83 ;
V_38 -> V_68 = F_46 ( V_42 , V_40 -> V_42 -> V_9 ) ;
V_38 -> V_65 = F_46 ( V_42 , V_40 -> V_42 -> V_65 ) ;
V_38 -> V_63 = V_40 -> V_42 -> V_63 ;
V_38 -> V_62 = 0 ;
F_47 ( & V_2 -> V_84 ) ;
V_38 -> V_88 = 0 ;
F_24 ( V_2 , V_38 , V_40 ) ;
F_48 ( & V_2 -> V_84 ) ;
return 0 ;
}
static T_4
F_49 ( struct V_39 * V_40 )
{
struct V_1 * V_2 = F_40 ( V_40 ) ;
struct V_37 * V_38 = V_40 -> V_42 -> V_81 ;
unsigned long V_92 ;
if ( F_41 ( ! V_38 ) )
return 0 ;
V_92 = F_5 ( V_2 , V_69 ) - ( unsigned long ) V_38 -> V_64 ;
V_92 %= V_38 -> V_68 ;
return F_50 ( V_40 -> V_42 , V_92 ) ;
}
static T_4
F_51 ( struct V_39 * V_40 )
{
struct V_1 * V_2 = F_40 ( V_40 ) ;
struct V_37 * V_38 = V_40 -> V_42 -> V_81 ;
unsigned long V_92 ;
if ( F_41 ( ! V_38 ) )
return 0 ;
V_92 = F_5 ( V_2 , V_75 ) - ( unsigned long ) V_38 -> V_64 ;
V_92 %= V_38 -> V_68 ;
return F_50 ( V_40 -> V_42 , V_92 ) ;
}
static int
F_52 ( struct V_39 * V_40 ,
int V_93 ,
T_4 V_94 ,
T_4 V_95 )
{
struct V_41 * V_42 = V_40 -> V_42 ;
struct V_37 * V_38 = V_42 -> V_81 ;
V_95 = F_46 ( V_42 , V_95 ) ;
V_94 = F_46 ( V_42 , V_94 ) ;
F_53 ( V_38 -> V_96 + V_94 , 0 , V_95 ) ;
return 0 ;
}
static int
F_54 ( struct V_39 * V_40 ,
int V_93 ,
T_4 V_94 ,
void T_5 * V_6 ,
T_4 V_95 )
{
struct V_41 * V_42 = V_40 -> V_42 ;
struct V_37 * V_38 = V_42 -> V_81 ;
V_95 = F_46 ( V_42 , V_95 ) ;
V_94 = F_46 ( V_42 , V_94 ) ;
if ( F_55 ( V_38 -> V_96 + V_94 , V_6 , V_95 ) )
return - V_97 ;
return 0 ;
}
static int
F_56 ( struct V_39 * V_40 ,
int V_93 ,
T_4 V_94 ,
void T_5 * V_98 ,
T_4 V_95 )
{
struct V_41 * V_42 = V_40 -> V_42 ;
struct V_37 * V_38 = V_42 -> V_81 ;
V_95 = F_46 ( V_42 , V_95 ) ;
V_94 = F_46 ( V_42 , V_94 ) ;
if ( F_57 ( V_98 , V_38 -> V_96 + V_94 , V_95 ) )
return - V_97 ;
return 0 ;
}
static void
F_58 ( struct V_1 * V_2 )
{
struct V_37 * V_38 ;
V_38 = & V_2 -> V_99 [ V_18 ] ;
if ( V_38 -> V_88 && V_38 -> V_40 ) {
F_43 ( & V_2 -> V_84 ) ;
F_59 ( V_38 -> V_40 ) ;
F_42 ( & V_2 -> V_84 ) ;
F_34 ( V_2 , V_38 ) ;
}
}
static void
F_60 ( struct V_1 * V_2 )
{
struct V_37 * V_38 ;
V_38 = & V_2 -> V_99 [ V_21 ] ;
if ( V_38 -> V_88 && V_38 -> V_40 ) {
F_43 ( & V_2 -> V_84 ) ;
F_59 ( V_38 -> V_40 ) ;
F_42 ( & V_2 -> V_84 ) ;
F_36 ( V_2 , V_38 ) ;
}
}
static int F_61 ( struct V_39 * V_40 ,
struct V_100 * V_101 )
{
V_40 -> V_42 -> V_102 = F_62 ( V_101 ) ;
return 0 ;
}
static void F_63 ( struct V_1 * V_2 , struct V_37 * V_38 ,
struct V_39 * V_40 ,
struct V_103 * V_104 )
{
struct V_41 * V_42 = V_40 -> V_42 ;
V_38 -> V_88 = 0 ;
V_42 -> V_105 = * V_104 ;
V_42 -> V_105 . V_106 = V_38 -> V_107 ;
V_42 -> V_105 . V_108 = V_38 -> V_107 / 2 ;
V_42 -> V_109 = ( void V_110 * ) V_38 -> V_96 ;
V_42 -> V_111 = V_38 -> V_112 ;
V_42 -> V_102 = V_38 -> V_107 ;
V_42 -> V_81 = V_38 ;
V_38 -> V_40 = V_40 ;
F_64 ( V_42 , 0 , V_113 ,
& V_114 ) ;
}
static int
F_65 ( struct V_39 * V_40 )
{
struct V_1 * V_2 = F_40 ( V_40 ) ;
if ( F_26 ( V_2 ) < 0 )
return - V_59 ;
F_63 ( V_2 , & V_2 -> V_99 [ V_18 ] ,
V_40 , & V_115 ) ;
return 0 ;
}
static int
F_66 ( struct V_39 * V_40 )
{
struct V_1 * V_2 = F_40 ( V_40 ) ;
if ( F_26 ( V_2 ) < 0 )
return - V_59 ;
F_63 ( V_2 , & V_2 -> V_99 [ V_21 ] ,
V_40 , & V_116 ) ;
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
F_69 ( struct V_1 * V_2 , int V_117 )
{
struct V_118 * V_119 ;
int V_35 , V_82 ;
for ( V_35 = 0 ; V_35 < 2 ; V_35 ++ ) {
struct V_37 * V_38 = & V_2 -> V_99 [ V_35 ] ;
V_38 -> V_96 = V_2 -> V_11 + ( V_38 -> V_64 - V_2 -> V_8 ) ;
V_38 -> V_112 = V_2 -> V_120 + ( V_38 -> V_64 - V_2 -> V_8 ) ;
}
V_82 = F_70 ( V_2 -> V_57 , V_2 -> V_57 -> V_58 , V_117 ,
1 , 1 , & V_119 ) ;
if ( V_82 < 0 )
return V_82 ;
F_71 ( V_119 , V_18 , & V_121 ) ;
F_71 ( V_119 , V_21 , & V_122 ) ;
V_119 -> V_81 = V_2 ;
V_119 -> V_123 = 0 ;
V_2 -> V_119 = V_119 ;
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
if ( V_2 -> V_124 ++ > 1000 ) {
if ( V_2 -> V_99 [ V_18 ] . V_88 )
F_37 ( V_2 ) ;
if ( V_2 -> V_99 [ V_21 ] . V_88 )
F_38 ( V_2 ) ;
V_2 -> V_124 = 0 ;
return V_125 ;
}
return V_126 ;
}
static T_7
F_74 ( int V_53 , void * V_127 )
{
struct V_1 * V_2 = V_127 ;
T_2 V_128 ;
T_1 V_129 ;
V_128 = F_3 ( V_2 , V_130 ) ;
if ( V_128 == 0 )
return F_73 ( V_2 ) ;
V_2 -> V_124 = 0 ;
F_42 ( & V_2 -> V_84 ) ;
if ( V_128 & V_131 ) {
V_128 &= ~ V_131 ;
F_75 ( V_2 , V_131 ) ;
F_58 ( V_2 ) ;
}
if ( V_128 & V_132 ) {
V_128 &= ~ V_132 ;
F_75 ( V_2 , V_132 ) ;
F_60 ( V_2 ) ;
}
if ( V_128 & V_133 ) {
V_128 &= ~ V_133 ;
F_75 ( V_2 , V_133 ) ;
F_20 ( L_4 ) ;
F_9 ( V_2 , V_130 , 0x8000 ) ;
V_129 = F_1 ( V_2 , 0x400 ) ;
F_7 ( V_2 , 0x400 , V_129 | 2 ) ;
}
if ( V_128 & V_134 ) {
V_128 &= ~ V_134 ;
F_75 ( V_2 , V_134 ) ;
F_20 ( L_5 ) ;
V_129 = F_1 ( V_2 , 0x400 ) ;
F_7 ( V_2 , 0x400 , V_129 & ~ 2 ) ;
}
if ( V_128 ) {
F_20 ( L_6 ,
V_128 ) ;
F_75 ( V_2 , V_128 ) ;
}
F_43 ( & V_2 -> V_84 ) ;
return V_125 ;
}
static T_7
F_76 ( int V_53 , void * V_127 )
{
struct V_1 * V_2 = V_127 ;
T_3 V_128 ;
T_1 V_129 ;
V_128 = F_5 ( V_2 , V_130 ) ;
if ( V_128 == 0 )
return F_73 ( V_2 ) ;
V_2 -> V_124 = 0 ;
F_42 ( & V_2 -> V_84 ) ;
if ( V_128 & V_135 ) {
V_128 &= ~ V_135 ;
F_77 ( V_2 , V_135 ) ;
F_58 ( V_2 ) ;
}
if ( V_128 & V_136 ) {
V_128 &= ~ V_136 ;
F_77 ( V_2 , V_136 ) ;
F_60 ( V_2 ) ;
}
if ( V_128 & V_137 ) {
V_128 &= ~ V_137 ;
F_77 ( V_2 , V_137 ) ;
F_20 ( L_4 ) ;
V_129 = F_1 ( V_2 , 0x400 ) ;
F_7 ( V_2 , 0x400 , V_129 | 2 ) ;
}
if ( V_128 & V_138 ) {
V_128 &= ~ V_138 ;
F_77 ( V_2 , V_138 ) ;
F_20 ( L_5 ) ;
V_129 = F_1 ( V_2 , 0x400 ) ;
F_7 ( V_2 , 0x400 , V_129 & ~ 2 ) ;
}
if ( V_128 ) {
F_20 ( L_6 ,
V_128 ) ;
F_77 ( V_2 , V_128 ) ;
}
F_43 ( & V_2 -> V_84 ) ;
return V_125 ;
}
static int
F_78 ( struct V_1 * V_2 )
{
int V_139 = 10 ;
T_3 V_140 ;
T_2 V_141 ;
V_140 = V_2 -> V_142 ;
V_141 = V_2 -> V_143 ;
while ( V_139 -- > 0 ) {
if ( ( F_3 ( V_2 , V_140 ) & V_141 ) == 0 )
return 1 ;
F_79 ( 100 ) ;
}
return 0 ;
}
static int F_80 ( unsigned short V_61 )
{
int V_35 ;
for ( V_35 = 0 ; V_35 < F_22 ( V_144 ) ; V_35 ++ )
if ( V_144 [ V_35 ] . V_61 == V_61 )
return V_35 ;
return - 1 ;
}
static unsigned short
F_81 ( struct V_145 * V_146 , unsigned short V_61 )
{
struct V_1 * V_2 = V_146 -> V_81 ;
int V_147 = F_80 ( V_61 ) ;
if ( V_147 < 0 )
return 0 ;
return V_2 -> V_148 [ V_147 ] ;
}
static void
F_82 ( struct V_145 * V_146 ,
unsigned short V_61 , unsigned short V_5 )
{
struct V_1 * V_2 = V_146 -> V_81 ;
int V_149 = 2 ;
int V_147 = F_80 ( V_61 ) ;
T_3 V_32 ;
if ( V_147 < 0 )
return;
V_32 = V_2 -> V_150 ;
F_78 ( V_2 ) ;
while ( V_149 -- > 0 ) {
F_9 ( V_2 , V_32 + V_61 , V_5 ) ;
F_83 ( 1 ) ;
if ( F_78 ( V_2 ) ) {
V_2 -> V_148 [ V_147 ] = V_5 ;
return;
}
}
F_20 ( L_7 ) ;
}
static void
F_84 ( struct V_145 * V_146 )
{
struct V_1 * V_2 = V_146 -> V_81 ;
F_7 ( V_2 , 0x6c0 , 1 ) ;
if ( ! V_2 -> V_151 ) {
F_7 ( V_2 , 0x6cc , 0x87 ) ;
}
if ( ! V_2 -> V_152 ) {
F_7 ( V_2 , 0x6cc , 0x80 ) ;
F_7 ( V_2 , 0x6cc , 0x0 ) ;
}
if ( ! V_2 -> V_153 ) {
int V_35 ;
for ( V_35 = 0 ; V_35 < F_22 ( V_144 ) ; V_35 ++ ) {
F_82 ( V_146 , V_144 [ V_35 ] . V_61 ,
V_144 [ V_35 ] . V_154 ) ;
}
}
}
static int T_6
F_85 ( struct V_1 * V_2 )
{
struct V_155 * V_156 ;
struct V_157 V_146 ;
int V_82 ;
static struct V_158 V_159 = {
. V_160 = F_84 ,
. V_161 = F_82 ,
. V_162 = F_81 ,
} ;
V_2 -> V_148 = F_86 ( F_22 ( V_144 ) ,
sizeof( short ) , V_163 ) ;
if ( ! V_2 -> V_148 )
return - V_164 ;
if ( ( V_82 = V_155 ( V_2 -> V_57 , 0 , & V_159 , NULL , & V_156 ) ) < 0 )
return V_82 ;
memset ( & V_146 , 0 , sizeof( V_146 ) ) ;
V_146 . V_165 = V_166 ;
V_146 . V_81 = V_2 ;
V_146 . V_167 = V_168 ;
V_156 -> V_169 = 1 ;
V_82 = F_87 ( V_156 , & V_146 , & V_2 -> V_146 ) ;
if ( V_82 < 0 )
return V_82 ;
if ( ! ( V_2 -> V_146 -> V_170 & ( 0xf0000000 ) ) ) {
sprintf ( V_2 -> V_57 -> V_171 , L_8 , V_2 -> V_57 -> V_58 ) ;
}
return 0 ;
}
static int T_6
F_88 ( struct V_1 * V_2 )
{
void T_8 * V_172 ;
unsigned long V_173 = V_2 -> V_174 - 0x1400 ;
T_3 V_175 ;
V_172 = F_89 ( V_2 -> V_120 + V_2 -> V_174 - 0x400 , 16 ) ;
if ( V_172 == NULL ) {
F_15 ( V_10 L_9 ) ;
return - V_59 ;
}
V_175 = F_6 ( V_172 ) ;
if ( ( V_175 & V_176 ) == V_177 ) {
T_3 V_178 = F_6 ( V_172 + 4 ) ;
if ( V_178 == 0xffffffff ||
V_178 < V_2 -> V_9 ||
V_178 > V_2 -> V_174 ) {
F_15 ( V_10 L_10 , V_178 ) ;
F_90 ( V_172 ) ;
return - V_179 ;
} else {
V_173 = V_178 ;
F_91 ( V_180 L_11 ,
V_178 ) ;
}
}
F_90 ( V_172 ) ;
V_2 -> V_174 = V_173 ;
return 0 ;
}
static int F_92 ( struct V_181 * V_54 , T_9 V_182 )
{
struct V_183 * V_57 = F_93 ( V_54 ) ;
struct V_1 * V_2 = V_57 -> V_81 ;
F_94 ( V_57 , V_184 ) ;
F_95 ( V_2 -> V_119 ) ;
F_96 ( V_2 -> V_146 ) ;
V_2 -> V_29 = 0 ;
F_97 ( V_54 ) ;
F_98 ( V_54 ) ;
F_99 ( V_54 , F_100 ( V_54 , V_182 ) ) ;
return 0 ;
}
static int F_101 ( struct V_181 * V_54 )
{
struct V_183 * V_57 = F_93 ( V_54 ) ;
struct V_1 * V_2 = V_57 -> V_81 ;
int V_35 ;
V_2 -> V_153 = 1 ;
F_99 ( V_54 , V_185 ) ;
F_102 ( V_54 ) ;
if ( F_103 ( V_54 ) < 0 ) {
F_91 ( V_10 L_12
L_13 ) ;
F_104 ( V_57 ) ;
return - V_186 ;
}
F_105 ( V_54 ) ;
F_72 ( V_2 ) ;
F_106 ( V_2 -> V_146 ) ;
for ( V_35 = 0 ; V_35 < 2 ; V_35 ++ ) {
struct V_37 * V_38 = & V_2 -> V_99 [ V_35 ] ;
if ( V_38 -> V_40 && V_38 -> V_86 ) {
F_47 ( & V_2 -> V_84 ) ;
F_24 ( V_2 , V_38 , V_38 -> V_40 ) ;
F_48 ( & V_2 -> V_84 ) ;
}
}
F_94 ( V_57 , V_187 ) ;
V_2 -> V_153 = 0 ;
return 0 ;
}
static int F_107 ( struct V_1 * V_2 )
{
if ( V_2 -> V_99 [ V_18 ] . V_88 )
F_37 ( V_2 ) ;
if ( V_2 -> V_99 [ V_21 ] . V_88 )
F_38 ( V_2 ) ;
if ( V_2 -> V_53 >= 0 )
F_31 ( V_2 -> V_53 , V_2 ) ;
if ( V_2 -> V_4 )
F_90 ( V_2 -> V_4 ) ;
if ( V_2 -> V_11 )
F_90 ( V_2 -> V_11 ) ;
F_108 ( V_2 -> V_188 ) ;
F_108 ( V_2 -> V_189 ) ;
F_97 ( V_2 -> V_54 ) ;
F_109 ( V_2 -> V_148 ) ;
F_109 ( V_2 ) ;
return 0 ;
}
static int F_110 ( struct V_190 * V_117 )
{
struct V_1 * V_2 = V_117 -> V_191 ;
return F_107 ( V_2 ) ;
}
static int T_6
F_111 ( struct V_183 * V_57 , struct V_181 * V_54 ,
struct V_1 * * V_192 )
{
struct V_1 * V_2 ;
int V_82 , V_193 ;
static struct V_194 V_159 = {
. V_195 = F_110 ,
} ;
T_3 V_24 ;
* V_192 = NULL ;
if ( ( V_82 = F_103 ( V_54 ) ) < 0 )
return V_82 ;
V_2 = F_112 ( sizeof( * V_2 ) , V_163 ) ;
if ( V_2 == NULL ) {
F_97 ( V_54 ) ;
return - V_164 ;
}
V_2 -> V_57 = V_57 ;
V_2 -> V_54 = V_54 ;
V_2 -> V_28 = V_28 ;
F_113 ( & V_2 -> V_84 ) ;
V_2 -> V_53 = - 1 ;
F_114 ( & V_2 -> V_52 ) ;
V_2 -> V_99 [ V_18 ] . V_107 = V_196 * 1024 ;
V_2 -> V_99 [ V_21 ] . V_107 = V_197 * 1024 ;
V_2 -> V_120 = F_115 ( V_54 , 0 ) ;
V_2 -> V_198 = F_115 ( V_54 , 1 ) ;
V_2 -> V_188 = F_116 ( V_2 -> V_198 , V_199 ,
V_57 -> V_58 ) ;
if ( V_2 -> V_188 == NULL ) {
F_15 ( V_10 L_14 ,
V_2 -> V_198 , V_199 ) ;
V_82 = - V_59 ;
goto V_200;
}
V_2 -> V_4 = F_89 ( V_2 -> V_198 , V_199 ) ;
if ( V_2 -> V_4 == NULL ) {
F_15 ( V_10 L_15 , V_2 -> V_198 ) ;
V_82 = - V_164 ;
goto V_200;
}
if ( ! strcmp ( V_57 -> V_58 , L_16 ) ) {
V_193 = F_3 ( V_2 , V_201 ) ;
if ( ( V_193 & V_202 ) != V_203 ) {
if ( ! V_204 ) {
F_91 ( V_10 L_17 ) ;
F_91 ( V_10 L_18
L_19 ) ;
F_91 ( V_10 L_20 ) ;
F_91 ( V_10 L_21
L_22 ) ;
V_82 = - V_83 ;
goto V_200;
}
}
V_2 -> V_174 = 2560 * 1024 ;
V_2 -> V_55 = F_74 ;
V_2 -> V_142 = V_205 ;
V_2 -> V_143 = V_206 ;
} else {
if ( F_1 ( V_2 , 0xa0b ) != 0 )
V_2 -> V_174 = 6144 * 1024 ;
else
V_2 -> V_174 = 4096 * 1024 ;
V_2 -> V_55 = F_76 ;
V_2 -> V_142 = V_207 ;
V_2 -> V_143 = V_208 ;
}
V_2 -> V_9 = V_2 -> V_99 [ V_18 ] . V_107 +
V_2 -> V_99 [ V_21 ] . V_107 ;
if ( V_2 -> V_28 )
V_2 -> V_9 += V_31 * 4 ;
else
V_2 -> V_9 += V_209 + V_210 ;
if ( V_211 >= V_2 -> V_9 && V_211 < V_2 -> V_174 )
V_2 -> V_174 = V_211 ;
else {
if ( ( V_82 = F_88 ( V_2 ) ) < 0 )
goto V_200;
}
V_2 -> V_8 = V_2 -> V_174 - V_2 -> V_9 ;
V_2 -> V_120 += V_2 -> V_8 ;
F_91 ( V_180 L_23 ,
V_2 -> V_8 , V_2 -> V_174 ) ;
V_2 -> V_189 = F_116 ( V_2 -> V_120 ,
V_2 -> V_9 ,
V_57 -> V_58 ) ;
if ( V_2 -> V_189 == NULL ) {
F_15 ( V_10 L_24 ,
V_2 -> V_120 , V_2 -> V_9 ) ;
V_82 = - V_59 ;
goto V_200;
}
V_2 -> V_11 = F_89 ( V_2 -> V_120 , V_2 -> V_9 ) ;
if ( V_2 -> V_11 == NULL ) {
V_82 = - V_164 ;
F_15 ( V_10 L_25 , V_2 -> V_120 ) ;
goto V_200;
}
V_24 = V_2 -> V_8 ;
V_2 -> V_99 [ V_18 ] . V_64 = V_24 ;
V_24 += V_2 -> V_99 [ V_18 ] . V_107 ;
V_2 -> V_99 [ V_21 ] . V_64 = V_24 ;
V_24 += V_2 -> V_99 [ V_21 ] . V_107 ;
if ( V_2 -> V_28 ) {
V_2 -> V_30 = V_24 ;
} else {
V_2 -> V_16 [ V_18 ] = V_24 ;
V_24 += V_209 ;
V_2 -> V_16 [ V_21 ] = V_24 ;
}
V_2 -> V_150 = V_212 ;
V_2 -> V_29 = 0 ;
F_72 ( V_2 ) ;
if ( ( V_82 = F_117 ( V_57 , V_213 , V_2 , & V_159 ) ) < 0 )
goto V_200;
F_118 ( V_57 , & V_54 -> V_214 ) ;
* V_192 = V_2 ;
return 0 ;
V_200:
F_107 ( V_2 ) ;
return V_82 ;
}
static int T_6 F_119 ( struct V_181 * V_54 ,
const struct V_215 * V_216 )
{
struct V_183 * V_57 ;
struct V_1 * V_2 ;
int V_82 ;
const struct V_217 * V_218 ;
V_218 = F_120 ( V_54 , V_219 ) ;
if ( V_218 ) {
F_121 ( V_180 L_26 , V_218 -> V_220 ) ;
switch ( V_218 -> V_154 ) {
case V_221 :
F_91 ( V_180 L_27
L_28 ) ;
return - V_179 ;
case V_222 :
V_152 = 1 ;
case V_223 :
V_151 = 1 ;
break;
}
}
V_82 = F_122 ( V_224 , V_170 , V_225 , 0 , & V_57 ) ;
if ( V_82 < 0 )
return V_82 ;
switch ( V_54 -> V_117 ) {
case V_226 :
strcpy ( V_57 -> V_58 , L_16 ) ;
break;
case V_227 :
strcpy ( V_57 -> V_58 , L_29 ) ;
break;
case V_228 :
strcpy ( V_57 -> V_58 , L_30 ) ;
break;
default:
F_15 ( V_10 L_31 , V_54 -> V_117 ) ;
F_123 ( V_57 ) ;
return - V_91 ;
}
if ( V_229 )
V_211 = 0x25a800 ;
if ( V_196 < 4 )
V_196 = 4 ;
if ( V_196 > 128 )
V_196 = 128 ;
if ( V_197 < 4 )
V_197 = 4 ;
if ( V_197 > 128 )
V_197 = 128 ;
if ( ( V_82 = F_111 ( V_57 , V_54 , & V_2 ) ) < 0 ) {
F_123 ( V_57 ) ;
return V_82 ;
}
V_57 -> V_81 = V_2 ;
if ( V_151 ) {
F_121 ( V_180 L_32 ) ;
V_2 -> V_151 = 1 ;
}
if ( V_152 ) {
F_121 ( V_180 L_33 ) ;
V_2 -> V_152 = 1 ;
}
if ( ( V_82 = F_69 ( V_2 , 0 ) ) < 0 ||
( V_82 = F_85 ( V_2 ) ) < 0 ) {
F_123 ( V_57 ) ;
return V_82 ;
}
sprintf ( V_57 -> V_230 , L_34 , V_57 -> V_58 ) ;
sprintf ( V_57 -> V_231 , L_35 ,
V_57 -> V_230 ,
V_2 -> V_120 , V_2 -> V_198 , V_2 -> V_53 ) ;
if ( ( V_82 = F_124 ( V_57 ) ) < 0 ) {
F_123 ( V_57 ) ;
return V_82 ;
}
F_125 ( V_54 , V_57 ) ;
return 0 ;
}
static void T_10 F_126 ( struct V_181 * V_54 )
{
F_123 ( F_93 ( V_54 ) ) ;
F_125 ( V_54 , NULL ) ;
}
static int T_11 F_127 ( void )
{
return F_128 ( & V_58 ) ;
}
static void T_12 F_129 ( void )
{
F_130 ( & V_58 ) ;
}
