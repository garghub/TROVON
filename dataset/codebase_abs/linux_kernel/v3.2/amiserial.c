static inline int F_1 ( struct V_1 * V_2 ,
char * V_3 , const char * V_4 )
{
#ifdef F_2
static const char * V_5 =
L_1 ;
static const char * V_6 =
L_2 ;
if ( ! V_2 ) {
F_3 ( V_6 , V_3 , V_4 ) ;
return 1 ;
}
if ( V_2 -> V_7 != V_8 ) {
F_3 ( V_5 , V_3 , V_4 ) ;
return 1 ;
}
#endif
return 0 ;
}
static T_1 void F_4 ( int V_9 )
{
V_10 . V_11 = ( ( V_9 & ( V_12 | V_13 ) ) ^ ( V_12 | V_13 ) ) | ( V_10 . V_11 & ~ ( V_12 | V_13 ) ) ;
}
static void F_5 ( struct V_14 * V_15 )
{
struct V_1 * V_2 = V_15 -> V_16 ;
unsigned long V_17 ;
if ( F_1 ( V_2 , V_15 -> V_3 , L_3 ) )
return;
F_6 ( V_17 ) ;
if ( V_2 -> V_18 & V_19 ) {
V_2 -> V_18 &= ~ V_19 ;
V_20 . V_21 = V_22 ;
F_7 () ;
V_20 . V_23 = V_22 ;
F_7 () ;
}
F_8 ( V_17 ) ;
}
static void F_9 ( struct V_14 * V_15 )
{
struct V_1 * V_2 = V_15 -> V_16 ;
unsigned long V_17 ;
if ( F_1 ( V_2 , V_15 -> V_3 , L_4 ) )
return;
F_6 ( V_17 ) ;
if ( V_2 -> V_24 . V_25 != V_2 -> V_24 . V_26
&& V_2 -> V_24 . V_27
&& ! ( V_2 -> V_18 & V_19 ) ) {
V_2 -> V_18 |= V_19 ;
V_20 . V_21 = V_28 | V_22 ;
F_7 () ;
V_20 . V_23 = V_28 | V_22 ;
F_7 () ;
}
F_8 ( V_17 ) ;
}
static void F_10 ( struct V_1 * V_2 ,
int V_29 )
{
V_2 -> V_29 |= 1 << V_29 ;
F_11 ( & V_2 -> V_30 ) ;
}
static void F_12 ( struct V_1 * V_2 )
{
int V_31 ;
int V_32 ;
struct V_14 * V_15 = V_2 -> V_15 ;
unsigned char V_33 , V_34 ;
struct V_35 * V_36 ;
int V_37 = 0 ;
V_36 = & V_2 -> V_38 -> V_36 ;
V_31 = V_39 ;
V_32 = V_20 . V_32 ;
F_7 () ;
V_20 . V_23 = V_40 ;
F_7 () ;
if( ( V_32 & 0x1ff ) == 0 )
V_31 |= V_41 ;
if( V_32 & V_42 )
V_31 |= V_43 ;
V_33 = V_32 & 0xff ;
V_36 -> V_44 ++ ;
#ifdef F_13
F_3 ( L_5 , V_33 , V_31 ) ;
#endif
V_34 = V_45 ;
if ( V_31 & ( V_41 | V_46 |
V_47 | V_43 ) ) {
if ( V_31 & V_41 ) {
V_31 &= ~ ( V_47 | V_46 ) ;
V_36 -> V_48 ++ ;
} else if ( V_31 & V_46 )
V_36 -> V_49 ++ ;
else if ( V_31 & V_47 )
V_36 -> V_50 ++ ;
if ( V_31 & V_43 )
V_36 -> V_51 ++ ;
if ( V_31 & V_2 -> V_52 )
goto V_53;
V_31 &= V_2 -> V_54 ;
if ( V_31 & ( V_41 ) ) {
#ifdef F_13
F_3 ( L_6 ) ;
#endif
V_34 = V_55 ;
if ( V_2 -> V_17 & V_56 )
F_14 ( V_15 ) ;
} else if ( V_31 & V_46 )
V_34 = V_57 ;
else if ( V_31 & V_47 )
V_34 = V_58 ;
if ( V_31 & V_43 ) {
V_37 = 1 ;
}
}
F_15 ( V_15 , V_33 , V_34 ) ;
if ( V_37 == 1 )
F_15 ( V_15 , 0 , V_59 ) ;
F_16 ( V_15 ) ;
V_53:
return;
}
static void F_17 ( struct V_1 * V_2 )
{
V_20 . V_23 = V_22 ;
F_7 () ;
if ( V_2 -> V_60 ) {
V_20 . V_61 = V_2 -> V_60 | 0x100 ;
F_7 () ;
V_2 -> V_38 -> V_36 . V_62 ++ ;
V_2 -> V_60 = 0 ;
return;
}
if ( V_2 -> V_24 . V_25 == V_2 -> V_24 . V_26
|| V_2 -> V_15 -> V_63
|| V_2 -> V_15 -> V_64 ) {
V_2 -> V_18 &= ~ V_19 ;
V_20 . V_21 = V_22 ;
F_7 () ;
return;
}
V_20 . V_61 = V_2 -> V_24 . V_27 [ V_2 -> V_24 . V_26 ++ ] | 0x100 ;
F_7 () ;
V_2 -> V_24 . V_26 = V_2 -> V_24 . V_26 & ( V_65 - 1 ) ;
V_2 -> V_38 -> V_36 . V_62 ++ ;
if ( F_18 ( V_2 -> V_24 . V_25 ,
V_2 -> V_24 . V_26 ,
V_65 ) < V_66 )
F_10 ( V_2 , V_67 ) ;
#ifdef F_13
F_3 ( L_7 ) ;
#endif
if ( V_2 -> V_24 . V_25 == V_2 -> V_24 . V_26 ) {
V_20 . V_21 = V_22 ;
F_7 () ;
V_2 -> V_18 &= ~ V_19 ;
}
}
static void F_19 ( struct V_1 * V_2 )
{
unsigned char V_31 = V_10 . V_11 & ( V_68 | V_69 | V_70 ) ;
unsigned char V_71 ;
struct V_35 * V_36 ;
V_71 = V_31 ^ V_72 ;
V_72 = V_31 ;
if ( V_71 ) {
V_36 = & V_2 -> V_38 -> V_36 ;
if ( V_71 & V_70 )
V_36 -> V_73 ++ ;
if ( V_71 & V_68 ) {
V_36 -> V_74 ++ ;
#ifdef F_20
if ( ( V_2 -> V_17 & V_75 ) &&
! ( V_31 & V_68 ) )
F_21 () ;
#endif
}
if ( V_71 & V_69 )
V_36 -> V_76 ++ ;
F_22 ( & V_2 -> V_77 ) ;
}
if ( ( V_2 -> V_17 & V_78 ) && ( V_71 & V_68 ) ) {
#if ( F_23 ( V_79 ) || F_23 ( F_13 ) )
F_3 ( L_8 , V_2 -> line ,
( ! ( V_31 & V_68 ) ) ? L_9 : L_10 ) ;
#endif
if ( ! ( V_31 & V_68 ) )
F_22 ( & V_2 -> V_80 ) ;
else {
#ifdef V_79
F_3 ( L_11 ) ;
#endif
if ( V_2 -> V_15 )
F_24 ( V_2 -> V_15 ) ;
}
}
if ( V_2 -> V_17 & V_81 ) {
if ( V_2 -> V_15 -> V_64 ) {
if ( ! ( V_31 & V_69 ) ) {
#if ( F_23 ( F_13 ) || F_23 ( V_82 ) )
F_3 ( L_12 ) ;
#endif
V_2 -> V_15 -> V_64 = 0 ;
V_2 -> V_18 |= V_19 ;
V_20 . V_21 = V_28 | V_22 ;
F_7 () ;
V_20 . V_23 = V_28 | V_22 ;
F_7 () ;
F_10 ( V_2 , V_67 ) ;
return;
}
} else {
if ( ( V_31 & V_69 ) ) {
#if ( F_23 ( F_13 ) || F_23 ( V_82 ) )
F_3 ( L_13 ) ;
#endif
V_2 -> V_15 -> V_64 = 1 ;
V_2 -> V_18 &= ~ V_19 ;
V_20 . V_21 = V_22 ;
F_7 () ;
V_20 . V_23 = V_22 ;
F_7 () ;
}
}
}
}
static T_2 F_25 ( int V_83 , void * V_84 )
{
struct V_1 * V_2 = V_85 ;
if( V_2 -> V_18 & V_86 )
F_19 ( V_2 ) ;
return V_87 ;
}
static T_2 F_26 ( int V_83 , void * V_88 )
{
struct V_1 * V_2 ;
#ifdef F_13
F_3 ( L_14 ) ;
#endif
V_2 = V_85 ;
if ( ! V_2 || ! V_2 -> V_15 )
return V_89 ;
F_12 ( V_2 ) ;
V_2 -> V_90 = V_91 ;
#ifdef F_13
F_3 ( L_15 ) ;
#endif
return V_87 ;
}
static T_2 F_27 ( int V_83 , void * V_88 )
{
struct V_1 * V_2 ;
if ( V_20 . V_32 & V_92 ) {
#ifdef F_13
F_3 ( L_16 ) ;
#endif
V_2 = V_85 ;
if ( ! V_2 || ! V_2 -> V_15 )
return V_89 ;
F_17 ( V_2 ) ;
V_2 -> V_90 = V_91 ;
#ifdef F_13
F_3 ( L_15 ) ;
#endif
}
return V_87 ;
}
static void F_28 ( unsigned long V_93 )
{
struct V_1 * V_2 = (struct V_1 * ) V_93 ;
struct V_14 * V_15 ;
V_15 = V_2 -> V_15 ;
if ( ! V_15 )
return;
if ( F_29 ( V_67 , & V_2 -> V_29 ) )
F_30 ( V_15 ) ;
}
static int F_31 ( struct V_1 * V_2 )
{
unsigned long V_17 ;
int V_94 = 0 ;
unsigned long V_95 ;
V_95 = F_32 ( V_96 ) ;
if ( ! V_95 )
return - V_97 ;
F_6 ( V_17 ) ;
if ( V_2 -> V_17 & V_98 ) {
F_33 ( V_95 ) ;
goto V_99;
}
if ( V_2 -> V_24 . V_27 )
F_33 ( V_95 ) ;
else
V_2 -> V_24 . V_27 = ( unsigned char * ) V_95 ;
#ifdef V_79
F_3 ( L_17 , V_2 -> line ) ;
#endif
V_20 . V_23 = V_40 ;
F_7 () ;
V_94 = F_34 ( V_100 , F_25 , 0 , L_18 , V_2 ) ;
if ( V_94 ) {
if ( F_35 () ) {
if ( V_2 -> V_15 )
F_36 ( V_101 ,
& V_2 -> V_15 -> V_17 ) ;
V_94 = 0 ;
}
goto V_99;
}
V_20 . V_21 = V_28 | V_40 | V_22 ;
F_7 () ;
V_2 -> V_18 = V_86 ;
V_72 = V_10 . V_11 & ( V_68 | V_69 | V_70 ) ;
V_85 = V_2 ;
V_2 -> V_102 = 0 ;
if ( V_2 -> V_15 -> V_103 -> V_104 & V_105 )
V_2 -> V_102 = V_13 | V_12 ;
F_4 ( V_2 -> V_102 ) ;
if ( V_2 -> V_15 )
F_37 ( V_101 , & V_2 -> V_15 -> V_17 ) ;
V_2 -> V_24 . V_25 = V_2 -> V_24 . V_26 = 0 ;
if ( V_2 -> V_15 ) {
if ( ( V_2 -> V_17 & V_106 ) == V_107 )
V_2 -> V_15 -> V_108 = 57600 ;
if ( ( V_2 -> V_17 & V_106 ) == V_109 )
V_2 -> V_15 -> V_108 = 115200 ;
if ( ( V_2 -> V_17 & V_106 ) == V_110 )
V_2 -> V_15 -> V_108 = 230400 ;
if ( ( V_2 -> V_17 & V_106 ) == V_111 )
V_2 -> V_15 -> V_108 = 460800 ;
}
F_38 ( V_2 , NULL ) ;
V_2 -> V_17 |= V_98 ;
F_8 ( V_17 ) ;
return 0 ;
V_99:
F_8 ( V_17 ) ;
return V_94 ;
}
static void F_39 ( struct V_1 * V_2 )
{
unsigned long V_17 ;
struct V_112 * V_38 ;
if ( ! ( V_2 -> V_17 & V_98 ) )
return;
V_38 = V_2 -> V_38 ;
#ifdef V_79
F_3 ( L_19 , V_2 -> line ) ;
#endif
F_6 ( V_17 ) ;
F_22 ( & V_2 -> V_77 ) ;
V_85 = NULL ;
F_40 ( V_100 , V_2 ) ;
if ( V_2 -> V_24 . V_27 ) {
F_33 ( ( unsigned long ) V_2 -> V_24 . V_27 ) ;
V_2 -> V_24 . V_27 = NULL ;
}
V_2 -> V_18 = 0 ;
V_20 . V_21 = V_40 | V_22 ;
F_7 () ;
V_20 . V_113 = V_114 ;
F_7 () ;
if ( ! V_2 -> V_15 || ( V_2 -> V_15 -> V_103 -> V_104 & V_115 ) )
V_2 -> V_102 &= ~ ( V_13 | V_12 ) ;
F_4 ( V_2 -> V_102 ) ;
if ( V_2 -> V_15 )
F_36 ( V_101 , & V_2 -> V_15 -> V_17 ) ;
V_2 -> V_17 &= ~ V_98 ;
F_8 ( V_17 ) ;
}
static void F_38 ( struct V_1 * V_2 ,
struct V_116 * V_117 )
{
int V_118 = 0 , V_119 , V_120 ;
unsigned V_121 , V_122 = 0 ;
int V_9 ;
unsigned long V_17 ;
if ( ! V_2 -> V_15 || ! V_2 -> V_15 -> V_103 )
return;
V_121 = V_2 -> V_15 -> V_103 -> V_104 ;
V_122 = 3 ; V_9 = 10 ;
if ( V_121 & V_123 ) {
V_122 |= 0x04 ;
V_9 ++ ;
}
if ( V_121 & V_124 ) {
V_122 |= V_125 ;
V_9 ++ ;
}
if ( ! ( V_121 & V_126 ) )
V_122 |= V_127 ;
#ifdef F_41
if ( V_121 & F_41 )
V_122 |= V_128 ;
#endif
V_120 = F_42 ( V_2 -> V_15 ) ;
if ( ! V_120 )
V_120 = 9600 ;
V_119 = V_2 -> V_38 -> V_119 ;
if ( V_120 == 38400 &&
( ( V_2 -> V_17 & V_106 ) == V_129 ) )
V_118 = V_2 -> V_38 -> V_130 ;
else {
if ( V_120 == 134 )
V_118 = ( 2 * V_119 / 269 ) ;
else if ( V_120 )
V_118 = V_119 / V_120 ;
}
if ( ! V_118 && V_117 ) {
V_2 -> V_15 -> V_103 -> V_104 &= ~ V_105 ;
V_2 -> V_15 -> V_103 -> V_104 |= ( V_117 -> V_104 & V_105 ) ;
V_120 = F_42 ( V_2 -> V_15 ) ;
if ( ! V_120 )
V_120 = 9600 ;
if ( V_120 == 38400 &&
( ( V_2 -> V_17 & V_106 ) == V_129 ) )
V_118 = V_2 -> V_38 -> V_130 ;
else {
if ( V_120 == 134 )
V_118 = ( 2 * V_119 / 269 ) ;
else if ( V_120 )
V_118 = V_119 / V_120 ;
}
}
if ( ! V_118 )
V_118 = V_119 / 9600 ;
V_2 -> V_118 = V_118 ;
V_2 -> V_131 = ( ( V_2 -> V_132 * V_133 * V_9 * V_118 ) / V_119 ) ;
V_2 -> V_131 += V_133 / 50 ;
V_2 -> V_18 &= ~ V_86 ;
if ( V_2 -> V_17 & V_75 )
V_2 -> V_18 |= V_86 ;
if ( V_121 & V_134 ) {
V_2 -> V_17 |= V_81 ;
V_2 -> V_18 |= V_86 ;
} else
V_2 -> V_17 &= ~ V_81 ;
if ( V_121 & V_135 )
V_2 -> V_17 &= ~ V_78 ;
else {
V_2 -> V_17 |= V_78 ;
V_2 -> V_18 |= V_86 ;
}
V_2 -> V_54 = V_43 | V_39 ;
if ( F_43 ( V_2 -> V_15 ) )
V_2 -> V_54 |= V_47 | V_46 ;
if ( F_44 ( V_2 -> V_15 ) || F_45 ( V_2 -> V_15 ) )
V_2 -> V_54 |= V_41 ;
V_2 -> V_52 = 0 ;
if ( F_46 ( V_2 -> V_15 ) )
V_2 -> V_52 |= V_46 | V_47 ;
if ( F_47 ( V_2 -> V_15 ) ) {
V_2 -> V_52 |= V_41 ;
if ( F_46 ( V_2 -> V_15 ) )
V_2 -> V_52 |= V_43 ;
}
if ( ( V_121 & V_136 ) == 0 )
V_2 -> V_52 |= V_39 ;
F_6 ( V_17 ) ;
{
short V_137 ;
V_137 = V_118 - 1 ;
if( V_122 & V_125 )
V_137 |= ( V_138 ) ;
V_20 . V_137 = V_137 ;
F_7 () ;
}
V_2 -> V_139 = V_122 ;
F_8 ( V_17 ) ;
}
static int F_48 ( struct V_14 * V_15 , unsigned char V_33 )
{
struct V_1 * V_2 ;
unsigned long V_17 ;
V_2 = V_15 -> V_16 ;
if ( F_1 ( V_2 , V_15 -> V_3 , L_20 ) )
return 0 ;
if ( ! V_2 -> V_24 . V_27 )
return 0 ;
F_6 ( V_17 ) ;
if ( F_49 ( V_2 -> V_24 . V_25 ,
V_2 -> V_24 . V_26 ,
V_65 ) == 0 ) {
F_8 ( V_17 ) ;
return 0 ;
}
V_2 -> V_24 . V_27 [ V_2 -> V_24 . V_25 ++ ] = V_33 ;
V_2 -> V_24 . V_25 &= V_65 - 1 ;
F_8 ( V_17 ) ;
return 1 ;
}
static void F_50 ( struct V_14 * V_15 )
{
struct V_1 * V_2 = V_15 -> V_16 ;
unsigned long V_17 ;
if ( F_1 ( V_2 , V_15 -> V_3 , L_21 ) )
return;
if ( V_2 -> V_24 . V_25 == V_2 -> V_24 . V_26
|| V_15 -> V_63
|| V_15 -> V_64
|| ! V_2 -> V_24 . V_27 )
return;
F_6 ( V_17 ) ;
V_2 -> V_18 |= V_19 ;
V_20 . V_21 = V_28 | V_22 ;
F_7 () ;
V_20 . V_23 = V_28 | V_22 ;
F_7 () ;
F_8 ( V_17 ) ;
}
static int F_51 ( struct V_14 * V_15 , const unsigned char * V_27 , int V_140 )
{
int V_141 , V_142 = 0 ;
struct V_1 * V_2 ;
unsigned long V_17 ;
V_2 = V_15 -> V_16 ;
if ( F_1 ( V_2 , V_15 -> V_3 , L_22 ) )
return 0 ;
if ( ! V_2 -> V_24 . V_27 )
return 0 ;
F_6 ( V_17 ) ;
while ( 1 ) {
V_141 = F_52 ( V_2 -> V_24 . V_25 ,
V_2 -> V_24 . V_26 ,
V_65 ) ;
if ( V_140 < V_141 )
V_141 = V_140 ;
if ( V_141 <= 0 ) {
break;
}
memcpy ( V_2 -> V_24 . V_27 + V_2 -> V_24 . V_25 , V_27 , V_141 ) ;
V_2 -> V_24 . V_25 = ( ( V_2 -> V_24 . V_25 + V_141 ) &
( V_65 - 1 ) ) ;
V_27 += V_141 ;
V_140 -= V_141 ;
V_142 += V_141 ;
}
F_8 ( V_17 ) ;
if ( V_2 -> V_24 . V_25 != V_2 -> V_24 . V_26
&& ! V_15 -> V_63
&& ! V_15 -> V_64
&& ! ( V_2 -> V_18 & V_19 ) ) {
V_2 -> V_18 |= V_19 ;
F_53 () ;
V_20 . V_21 = V_28 | V_22 ;
F_7 () ;
V_20 . V_23 = V_28 | V_22 ;
F_7 () ;
F_8 ( V_17 ) ;
}
return V_142 ;
}
static int F_54 ( struct V_14 * V_15 )
{
struct V_1 * V_2 = V_15 -> V_16 ;
if ( F_1 ( V_2 , V_15 -> V_3 , L_23 ) )
return 0 ;
return F_49 ( V_2 -> V_24 . V_25 , V_2 -> V_24 . V_26 , V_65 ) ;
}
static int F_55 ( struct V_14 * V_15 )
{
struct V_1 * V_2 = V_15 -> V_16 ;
if ( F_1 ( V_2 , V_15 -> V_3 , L_24 ) )
return 0 ;
return F_18 ( V_2 -> V_24 . V_25 , V_2 -> V_24 . V_26 , V_65 ) ;
}
static void F_56 ( struct V_14 * V_15 )
{
struct V_1 * V_2 = V_15 -> V_16 ;
unsigned long V_17 ;
if ( F_1 ( V_2 , V_15 -> V_3 , L_25 ) )
return;
F_6 ( V_17 ) ;
V_2 -> V_24 . V_25 = V_2 -> V_24 . V_26 = 0 ;
F_8 ( V_17 ) ;
F_30 ( V_15 ) ;
}
static void F_57 ( struct V_14 * V_15 , char V_33 )
{
struct V_1 * V_2 = V_15 -> V_16 ;
unsigned long V_17 ;
if ( F_1 ( V_2 , V_15 -> V_3 , L_26 ) )
return;
V_2 -> V_60 = V_33 ;
if ( V_33 ) {
F_6 ( V_17 ) ;
if( ! ( V_20 . V_143 & V_22 ) ) {
V_20 . V_21 = V_28 | V_22 ;
F_7 () ;
V_20 . V_23 = V_28 | V_22 ;
F_7 () ;
}
F_8 ( V_17 ) ;
V_2 -> V_18 |= V_19 ;
}
}
static void F_58 ( struct V_14 * V_15 )
{
struct V_1 * V_2 = V_15 -> V_16 ;
unsigned long V_17 ;
#ifdef F_59
char V_27 [ 64 ] ;
F_3 ( L_27 , F_60 ( V_15 , V_27 ) ,
V_15 -> V_144 . V_145 ( V_15 ) ) ;
#endif
if ( F_1 ( V_2 , V_15 -> V_3 , L_28 ) )
return;
if ( F_61 ( V_15 ) )
F_57 ( V_15 , F_62 ( V_15 ) ) ;
if ( V_15 -> V_103 -> V_104 & V_134 )
V_2 -> V_102 &= ~ V_12 ;
F_6 ( V_17 ) ;
F_4 ( V_2 -> V_102 ) ;
F_8 ( V_17 ) ;
}
static void F_63 ( struct V_14 * V_15 )
{
struct V_1 * V_2 = V_15 -> V_16 ;
unsigned long V_17 ;
#ifdef F_59
char V_27 [ 64 ] ;
F_3 ( L_29 , F_60 ( V_15 , V_27 ) ,
V_15 -> V_144 . V_145 ( V_15 ) ) ;
#endif
if ( F_1 ( V_2 , V_15 -> V_3 , L_30 ) )
return;
if ( F_61 ( V_15 ) ) {
if ( V_2 -> V_60 )
V_2 -> V_60 = 0 ;
else
F_57 ( V_15 , F_64 ( V_15 ) ) ;
}
if ( V_15 -> V_103 -> V_104 & V_134 )
V_2 -> V_102 |= V_12 ;
F_6 ( V_17 ) ;
F_4 ( V_2 -> V_102 ) ;
F_8 ( V_17 ) ;
}
static int F_65 ( struct V_1 * V_2 ,
struct V_146 T_3 * V_147 )
{
struct V_146 V_148 ;
struct V_112 * V_38 = V_2 -> V_38 ;
if ( ! V_147 )
return - V_149 ;
memset ( & V_148 , 0 , sizeof( V_148 ) ) ;
F_66 () ;
V_148 . type = V_38 -> type ;
V_148 . line = V_38 -> line ;
V_148 . V_150 = V_38 -> V_150 ;
V_148 . V_83 = V_38 -> V_83 ;
V_148 . V_17 = V_38 -> V_17 ;
V_148 . V_132 = V_38 -> V_132 ;
V_148 . V_119 = V_38 -> V_119 ;
V_148 . V_151 = V_38 -> V_151 ;
V_148 . V_152 = V_38 -> V_152 ;
V_148 . V_130 = V_38 -> V_130 ;
F_67 () ;
if ( F_68 ( V_147 , & V_148 , sizeof( * V_147 ) ) )
return - V_149 ;
return 0 ;
}
static int F_69 ( struct V_1 * V_2 ,
struct V_146 T_3 * V_153 )
{
struct V_146 V_154 ;
struct V_112 V_155 , * V_38 ;
unsigned int V_156 , V_157 ;
int V_94 = 0 ;
if ( F_70 ( & V_154 , V_153 , sizeof( V_154 ) ) )
return - V_149 ;
F_66 () ;
V_38 = V_2 -> V_38 ;
V_155 = * V_38 ;
V_156 = V_154 . V_83 != V_38 -> V_83 ;
V_157 = ( V_154 . V_150 != V_38 -> V_150 ) ;
if( V_156 || V_157 || ( V_154 . V_132 != V_38 -> V_132 ) ) {
F_67 () ;
return - V_158 ;
}
if ( ! F_35 () ) {
if ( ( V_154 . V_119 != V_38 -> V_119 ) ||
( V_154 . V_151 != V_38 -> V_151 ) ||
( V_154 . V_132 != V_38 -> V_132 ) ||
( ( V_154 . V_17 & ~ V_159 ) !=
( V_38 -> V_17 & ~ V_159 ) ) )
return - V_160 ;
V_38 -> V_17 = ( ( V_38 -> V_17 & ~ V_159 ) |
( V_154 . V_17 & V_159 ) ) ;
V_2 -> V_17 = ( ( V_2 -> V_17 & ~ V_159 ) |
( V_154 . V_17 & V_159 ) ) ;
V_38 -> V_130 = V_154 . V_130 ;
goto V_161;
}
if ( V_154 . V_119 < 9600 ) {
F_67 () ;
return - V_158 ;
}
V_38 -> V_119 = V_154 . V_119 ;
V_38 -> V_17 = ( ( V_38 -> V_17 & ~ V_162 ) |
( V_154 . V_17 & V_162 ) ) ;
V_2 -> V_17 = ( ( V_38 -> V_17 & ~ V_163 ) |
( V_2 -> V_17 & V_163 ) ) ;
V_38 -> V_130 = V_154 . V_130 ;
V_38 -> V_151 = V_154 . V_151 * V_133 / 100 ;
V_38 -> V_152 = V_154 . V_152 * V_133 / 100 ;
V_2 -> V_15 -> V_164 = ( V_2 -> V_17 & V_165 ) ? 1 : 0 ;
V_161:
if ( V_2 -> V_17 & V_98 ) {
if ( ( ( V_155 . V_17 & V_106 ) !=
( V_38 -> V_17 & V_106 ) ) ||
( V_155 . V_130 != V_38 -> V_130 ) ) {
if ( ( V_38 -> V_17 & V_106 ) == V_107 )
V_2 -> V_15 -> V_108 = 57600 ;
if ( ( V_38 -> V_17 & V_106 ) == V_109 )
V_2 -> V_15 -> V_108 = 115200 ;
if ( ( V_38 -> V_17 & V_106 ) == V_110 )
V_2 -> V_15 -> V_108 = 230400 ;
if ( ( V_38 -> V_17 & V_106 ) == V_111 )
V_2 -> V_15 -> V_108 = 460800 ;
F_38 ( V_2 , NULL ) ;
}
} else
V_94 = F_31 ( V_2 ) ;
F_67 () ;
return V_94 ;
}
static int F_71 ( struct V_1 * V_2 , unsigned int T_3 * V_166 )
{
unsigned char V_31 ;
unsigned int V_167 ;
unsigned long V_17 ;
F_6 ( V_17 ) ;
V_31 = V_20 . V_32 ;
F_7 () ;
F_8 ( V_17 ) ;
V_167 = ( ( V_31 & V_168 ) ? V_169 : 0 ) ;
if ( F_68 ( V_166 , & V_167 , sizeof( int ) ) )
return - V_149 ;
return 0 ;
}
static int F_72 ( struct V_14 * V_15 )
{
struct V_1 * V_2 = V_15 -> V_16 ;
unsigned char V_170 , V_31 ;
unsigned long V_17 ;
if ( F_1 ( V_2 , V_15 -> V_3 , L_31 ) )
return - V_171 ;
if ( V_15 -> V_17 & ( 1 << V_101 ) )
return - V_172 ;
V_170 = V_2 -> V_102 ;
F_6 ( V_17 ) ;
V_31 = V_10 . V_11 ;
F_8 ( V_17 ) ;
return ( ( V_170 & V_12 ) ? V_173 : 0 )
| ( ( V_170 & V_13 ) ? V_174 : 0 )
| ( ! ( V_31 & V_68 ) ? V_175 : 0 )
| ( ! ( V_31 & V_70 ) ? V_176 : 0 )
| ( ! ( V_31 & V_69 ) ? V_177 : 0 ) ;
}
static int F_73 ( struct V_14 * V_15 , unsigned int V_178 ,
unsigned int V_179 )
{
struct V_1 * V_2 = V_15 -> V_16 ;
unsigned long V_17 ;
if ( F_1 ( V_2 , V_15 -> V_3 , L_31 ) )
return - V_171 ;
if ( V_15 -> V_17 & ( 1 << V_101 ) )
return - V_172 ;
F_6 ( V_17 ) ;
if ( V_178 & V_173 )
V_2 -> V_102 |= V_12 ;
if ( V_178 & V_174 )
V_2 -> V_102 |= V_13 ;
if ( V_179 & V_173 )
V_2 -> V_102 &= ~ V_12 ;
if ( V_179 & V_174 )
V_2 -> V_102 &= ~ V_13 ;
F_4 ( V_2 -> V_102 ) ;
F_8 ( V_17 ) ;
return 0 ;
}
static int F_74 ( struct V_14 * V_15 , int V_180 )
{
struct V_1 * V_2 = V_15 -> V_16 ;
unsigned long V_17 ;
if ( F_1 ( V_2 , V_15 -> V_3 , L_32 ) )
return - V_158 ;
F_6 ( V_17 ) ;
if ( V_180 == - 1 )
V_20 . V_113 = V_181 | V_114 ;
else
V_20 . V_113 = V_114 ;
F_7 () ;
F_8 ( V_17 ) ;
return 0 ;
}
static int F_75 ( struct V_14 * V_15 ,
struct V_182 * V_36 )
{
struct V_1 * V_2 = V_15 -> V_16 ;
struct V_35 V_183 ;
unsigned long V_17 ;
F_6 ( V_17 ) ;
V_183 = V_2 -> V_38 -> V_36 ;
F_8 ( V_17 ) ;
V_36 -> V_76 = V_183 . V_76 ;
V_36 -> V_73 = V_183 . V_73 ;
V_36 -> V_184 = V_183 . V_184 ;
V_36 -> V_74 = V_183 . V_74 ;
V_36 -> V_44 = V_183 . V_44 ;
V_36 -> V_62 = V_183 . V_62 ;
V_36 -> V_50 = V_183 . V_50 ;
V_36 -> V_51 = V_183 . V_51 ;
V_36 -> V_49 = V_183 . V_49 ;
V_36 -> V_48 = V_183 . V_48 ;
V_36 -> V_185 = V_183 . V_185 ;
return 0 ;
}
static int F_76 ( struct V_14 * V_15 ,
unsigned int V_186 , unsigned long V_187 )
{
struct V_1 * V_2 = V_15 -> V_16 ;
struct V_35 V_188 , V_183 ;
void T_3 * V_189 = ( void T_3 * ) V_187 ;
unsigned long V_17 ;
if ( F_1 ( V_2 , V_15 -> V_3 , L_31 ) )
return - V_171 ;
if ( ( V_186 != V_190 ) && ( V_186 != V_191 ) &&
( V_186 != V_192 ) && ( V_186 != V_193 ) &&
( V_186 != V_194 ) && ( V_186 != V_195 ) ) {
if ( V_15 -> V_17 & ( 1 << V_101 ) )
return - V_172 ;
}
switch ( V_186 ) {
case V_190 :
return F_65 ( V_2 , V_189 ) ;
case V_191 :
return F_69 ( V_2 , V_189 ) ;
case V_192 :
return 0 ;
case V_196 :
return F_71 ( V_2 , V_189 ) ;
case V_193 :
if ( F_68 ( V_189 ,
V_2 , sizeof( struct V_1 ) ) )
return - V_149 ;
return 0 ;
case V_194 :
F_6 ( V_17 ) ;
V_188 = V_2 -> V_38 -> V_36 ;
F_8 ( V_17 ) ;
while ( 1 ) {
F_77 ( & V_2 -> V_77 ) ;
if ( F_78 ( V_197 ) )
return - V_198 ;
F_6 ( V_17 ) ;
V_183 = V_2 -> V_38 -> V_36 ;
F_8 ( V_17 ) ;
if ( V_183 . V_184 == V_188 . V_184 && V_183 . V_73 == V_188 . V_73 &&
V_183 . V_74 == V_188 . V_74 && V_183 . V_76 == V_188 . V_76 )
return - V_172 ;
if ( ( ( V_187 & V_199 ) && ( V_183 . V_184 != V_188 . V_184 ) ) ||
( ( V_187 & V_176 ) && ( V_183 . V_73 != V_188 . V_73 ) ) ||
( ( V_187 & V_200 ) && ( V_183 . V_74 != V_188 . V_74 ) ) ||
( ( V_187 & V_177 ) && ( V_183 . V_76 != V_188 . V_76 ) ) ) {
return 0 ;
}
V_188 = V_183 ;
}
case V_201 :
case V_202 :
F_3 ( L_33 ) ;
return 0 ;
default:
return - V_203 ;
}
return 0 ;
}
static void F_79 ( struct V_14 * V_15 , struct V_116 * V_117 )
{
struct V_1 * V_2 = V_15 -> V_16 ;
unsigned long V_17 ;
unsigned int V_121 = V_15 -> V_103 -> V_104 ;
F_38 ( V_2 , V_117 ) ;
if ( ( V_117 -> V_104 & V_105 ) &&
! ( V_121 & V_105 ) ) {
V_2 -> V_102 &= ~ ( V_13 | V_12 ) ;
F_6 ( V_17 ) ;
F_4 ( V_2 -> V_102 ) ;
F_8 ( V_17 ) ;
}
if ( ! ( V_117 -> V_104 & V_105 ) &&
( V_121 & V_105 ) ) {
V_2 -> V_102 |= V_13 ;
if ( ! ( V_15 -> V_103 -> V_104 & V_134 ) ||
! F_80 ( V_204 , & V_15 -> V_17 ) ) {
V_2 -> V_102 |= V_12 ;
}
F_6 ( V_17 ) ;
F_4 ( V_2 -> V_102 ) ;
F_8 ( V_17 ) ;
}
if ( ( V_117 -> V_104 & V_134 ) &&
! ( V_15 -> V_103 -> V_104 & V_134 ) ) {
V_15 -> V_64 = 0 ;
F_9 ( V_15 ) ;
}
#if 0
if (!(old_termios->c_cflag & CLOCAL) &&
(tty->termios->c_cflag & CLOCAL))
wake_up_interruptible(&info->open_wait);
#endif
}
static void F_81 ( struct V_14 * V_15 , struct V_205 * V_206 )
{
struct V_1 * V_2 = V_15 -> V_16 ;
struct V_112 * V_38 ;
unsigned long V_17 ;
if ( ! V_2 || F_1 ( V_2 , V_15 -> V_3 , L_34 ) )
return;
V_38 = V_2 -> V_38 ;
F_6 ( V_17 ) ;
if ( F_82 ( V_206 ) ) {
F_83 ( L_35 ) ;
F_8 ( V_17 ) ;
return;
}
#ifdef V_79
F_3 ( L_36 , V_2 -> line , V_38 -> V_140 ) ;
#endif
if ( ( V_15 -> V_140 == 1 ) && ( V_38 -> V_140 != 1 ) ) {
F_3 ( L_37
L_38 , V_38 -> V_140 ) ;
V_38 -> V_140 = 1 ;
}
if ( -- V_38 -> V_140 < 0 ) {
F_3 ( L_39 ,
V_2 -> line , V_38 -> V_140 ) ;
V_38 -> V_140 = 0 ;
}
if ( V_38 -> V_140 ) {
F_83 ( L_40 ) ;
F_8 ( V_17 ) ;
return;
}
V_2 -> V_17 |= V_207 ;
V_15 -> V_208 = 1 ;
if ( V_2 -> V_152 != V_209 )
F_84 ( V_15 , V_2 -> V_152 ) ;
V_2 -> V_54 &= ~ V_39 ;
if ( V_2 -> V_17 & V_98 ) {
V_20 . V_21 = V_40 ;
F_7 () ;
V_20 . V_23 = V_40 ;
F_7 () ;
F_85 ( V_15 , V_2 -> V_131 ) ;
}
F_39 ( V_2 ) ;
F_56 ( V_15 ) ;
F_86 ( V_15 ) ;
V_15 -> V_208 = 0 ;
V_2 -> V_29 = 0 ;
V_2 -> V_15 = NULL ;
if ( V_2 -> V_210 ) {
if ( V_2 -> V_151 ) {
F_87 ( F_88 ( V_2 -> V_151 ) ) ;
}
F_22 ( & V_2 -> V_80 ) ;
}
V_2 -> V_17 &= ~ ( V_211 | V_207 ) ;
F_22 ( & V_2 -> V_212 ) ;
F_8 ( V_17 ) ;
}
static void F_85 ( struct V_14 * V_15 , int V_131 )
{
struct V_1 * V_2 = V_15 -> V_16 ;
unsigned long V_213 , V_214 ;
int V_215 ;
if ( F_1 ( V_2 , V_15 -> V_3 , L_41 ) )
return;
if ( V_2 -> V_132 == 0 )
return;
V_213 = V_91 ;
V_214 = ( V_2 -> V_131 - V_133 / 50 ) / V_2 -> V_132 ;
V_214 = V_214 / 5 ;
if ( V_214 == 0 )
V_214 = 1 ;
if ( V_131 )
V_214 = F_89 (unsigned long, char_time, timeout) ;
if ( ! V_131 || V_131 > 2 * V_2 -> V_131 )
V_131 = 2 * V_2 -> V_131 ;
#ifdef F_90
F_3 ( L_42 , V_131 , V_214 ) ;
F_3 ( L_43 , V_91 ) ;
#endif
while( ! ( ( V_215 = V_20 . V_32 ) & V_168 ) ) {
#ifdef F_90
F_3 ( L_44 , V_215 , V_91 ) ;
#endif
F_87 ( F_88 ( V_214 ) ) ;
if ( F_78 ( V_197 ) )
break;
if ( V_131 && F_91 ( V_91 , V_213 + V_131 ) )
break;
}
F_92 ( V_216 ) ;
#ifdef F_90
F_3 ( L_45 , V_215 , V_91 ) ;
#endif
}
static void F_93 ( struct V_14 * V_15 )
{
struct V_1 * V_2 = V_15 -> V_16 ;
struct V_112 * V_38 = V_2 -> V_38 ;
if ( F_1 ( V_2 , V_15 -> V_3 , L_46 ) )
return;
V_38 = V_2 -> V_38 ;
F_56 ( V_15 ) ;
F_39 ( V_2 ) ;
V_2 -> V_29 = 0 ;
V_38 -> V_140 = 0 ;
V_2 -> V_17 &= ~ V_211 ;
V_2 -> V_15 = NULL ;
F_22 ( & V_2 -> V_80 ) ;
}
static int F_94 ( struct V_14 * V_15 , struct V_205 * V_206 ,
struct V_1 * V_2 )
{
#ifdef F_95
F_95 ( V_217 , V_197 ) ;
#else
struct V_218 V_217 = { V_197 , NULL } ;
#endif
struct V_112 * V_38 = V_2 -> V_38 ;
int V_94 ;
int V_219 = 0 , V_220 = 0 ;
unsigned long V_17 ;
if ( F_82 ( V_206 ) ||
( V_2 -> V_17 & V_207 ) ) {
if ( V_2 -> V_17 & V_207 )
F_77 ( & V_2 -> V_212 ) ;
#ifdef F_96
return ( ( V_2 -> V_17 & V_221 ) ?
- V_222 : - V_198 ) ;
#else
return - V_222 ;
#endif
}
if ( ( V_206 -> V_223 & V_224 ) ||
( V_15 -> V_17 & ( 1 << V_101 ) ) ) {
V_2 -> V_17 |= V_211 ;
return 0 ;
}
if ( V_15 -> V_103 -> V_104 & V_135 )
V_219 = 1 ;
V_94 = 0 ;
F_97 ( & V_2 -> V_80 , & V_217 ) ;
#ifdef V_79
F_3 ( L_47 ,
V_38 -> line , V_38 -> V_140 ) ;
#endif
F_6 ( V_17 ) ;
if ( ! F_82 ( V_206 ) ) {
V_220 = 1 ;
V_38 -> V_140 -- ;
}
F_8 ( V_17 ) ;
V_2 -> V_210 ++ ;
while ( 1 ) {
F_6 ( V_17 ) ;
if ( V_15 -> V_103 -> V_104 & V_105 )
F_4 ( V_13 | V_12 ) ;
F_8 ( V_17 ) ;
F_98 ( V_225 ) ;
if ( F_82 ( V_206 ) ||
! ( V_2 -> V_17 & V_98 ) ) {
#ifdef F_96
if ( V_2 -> V_17 & V_221 )
V_94 = - V_222 ;
else
V_94 = - V_198 ;
#else
V_94 = - V_222 ;
#endif
break;
}
if ( ! ( V_2 -> V_17 & V_207 ) &&
( V_219 || ( ! ( V_10 . V_11 & V_68 ) ) ) )
break;
if ( F_78 ( V_197 ) ) {
V_94 = - V_198 ;
break;
}
#ifdef V_79
F_3 ( L_48 ,
V_2 -> line , V_38 -> V_140 ) ;
#endif
F_67 () ;
F_99 () ;
F_66 () ;
}
F_92 ( V_216 ) ;
F_100 ( & V_2 -> V_80 , & V_217 ) ;
if ( V_220 )
V_38 -> V_140 ++ ;
V_2 -> V_210 -- ;
#ifdef V_79
F_3 ( L_49 ,
V_2 -> line , V_38 -> V_140 ) ;
#endif
if ( V_94 )
return V_94 ;
V_2 -> V_17 |= V_211 ;
return 0 ;
}
static int F_101 ( int line , struct V_1 * * V_226 )
{
struct V_1 * V_2 ;
struct V_112 * V_227 ;
V_227 = V_228 + line ;
V_227 -> V_140 ++ ;
if ( V_227 -> V_2 ) {
* V_226 = V_227 -> V_2 ;
return 0 ;
}
V_2 = F_102 ( sizeof( struct V_1 ) , V_96 ) ;
if ( ! V_2 ) {
V_227 -> V_140 -- ;
return - V_97 ;
}
#ifdef F_95
F_103 ( & V_2 -> V_80 ) ;
F_103 ( & V_2 -> V_212 ) ;
F_103 ( & V_2 -> V_77 ) ;
#endif
V_2 -> V_7 = V_8 ;
V_2 -> V_150 = V_227 -> V_150 ;
V_2 -> V_17 = V_227 -> V_17 ;
V_2 -> V_132 = V_227 -> V_132 ;
V_2 -> line = line ;
F_104 ( & V_2 -> V_30 , F_28 , ( unsigned long ) V_2 ) ;
V_2 -> V_38 = V_227 ;
if ( V_227 -> V_2 ) {
F_105 ( V_2 ) ;
* V_226 = V_227 -> V_2 ;
return 0 ;
}
* V_226 = V_227 -> V_2 = V_2 ;
return 0 ;
}
static int F_106 ( struct V_14 * V_15 , struct V_205 * V_206 )
{
struct V_1 * V_2 ;
int V_94 , line ;
line = V_15 -> V_229 ;
if ( ( line < 0 ) || ( line >= V_230 ) ) {
return - V_171 ;
}
V_94 = F_101 ( line , & V_2 ) ;
if ( V_94 ) {
return V_94 ;
}
V_15 -> V_16 = V_2 ;
V_2 -> V_15 = V_15 ;
if ( F_1 ( V_2 , V_15 -> V_3 , L_50 ) )
return - V_171 ;
#ifdef V_79
F_3 ( L_51 , V_15 -> V_3 , V_2 -> V_38 -> V_140 ) ;
#endif
V_2 -> V_15 -> V_164 = ( V_2 -> V_17 & V_165 ) ? 1 : 0 ;
if ( F_82 ( V_206 ) ||
( V_2 -> V_17 & V_207 ) ) {
if ( V_2 -> V_17 & V_207 )
F_77 ( & V_2 -> V_212 ) ;
#ifdef F_96
return ( ( V_2 -> V_17 & V_221 ) ?
- V_222 : - V_198 ) ;
#else
return - V_222 ;
#endif
}
V_94 = F_31 ( V_2 ) ;
if ( V_94 ) {
return V_94 ;
}
V_94 = F_94 ( V_15 , V_206 , V_2 ) ;
if ( V_94 ) {
#ifdef V_79
F_3 ( L_52 ,
V_94 ) ;
#endif
return V_94 ;
}
#ifdef V_79
F_3 ( L_53 , V_15 -> V_3 ) ;
#endif
return 0 ;
}
static inline void F_107 ( struct V_231 * V_232 , struct V_112 * V_38 )
{
struct V_1 * V_2 = V_38 -> V_2 , V_233 ;
char V_234 [ 30 ] , V_170 , V_31 ;
unsigned long V_17 ;
F_108 ( V_232 , L_54 , V_38 -> line ) ;
if ( ! V_2 ) {
V_2 = & V_233 ;
V_2 -> V_7 = V_8 ;
V_2 -> V_17 = V_38 -> V_17 ;
V_2 -> V_118 = 0 ;
V_2 -> V_15 = NULL ;
}
F_6 ( V_17 ) ;
V_31 = V_10 . V_11 ;
V_170 = V_2 ? V_2 -> V_102 : V_31 ;
F_8 ( V_17 ) ;
V_234 [ 0 ] = 0 ;
V_234 [ 1 ] = 0 ;
if( ! ( V_170 & V_12 ) )
strcat ( V_234 , L_55 ) ;
if( ! ( V_31 & V_69 ) )
strcat ( V_234 , L_56 ) ;
if( ! ( V_170 & V_13 ) )
strcat ( V_234 , L_57 ) ;
if( ! ( V_31 & V_70 ) )
strcat ( V_234 , L_58 ) ;
if( ! ( V_31 & V_68 ) )
strcat ( V_234 , L_59 ) ;
if ( V_2 -> V_118 ) {
F_108 ( V_232 , L_60 , V_38 -> V_119 / V_2 -> V_118 ) ;
}
F_108 ( V_232 , L_61 , V_38 -> V_36 . V_62 , V_38 -> V_36 . V_44 ) ;
if ( V_38 -> V_36 . V_50 )
F_108 ( V_232 , L_62 , V_38 -> V_36 . V_50 ) ;
if ( V_38 -> V_36 . V_49 )
F_108 ( V_232 , L_63 , V_38 -> V_36 . V_49 ) ;
if ( V_38 -> V_36 . V_48 )
F_108 ( V_232 , L_64 , V_38 -> V_36 . V_48 ) ;
if ( V_38 -> V_36 . V_51 )
F_108 ( V_232 , L_65 , V_38 -> V_36 . V_51 ) ;
F_108 ( V_232 , L_66 , V_234 + 1 ) ;
}
static int F_109 ( struct V_231 * V_232 , void * V_235 )
{
F_108 ( V_232 , L_67 , V_236 ) ;
F_107 ( V_232 , & V_228 [ 0 ] ) ;
return 0 ;
}
static int F_110 ( struct V_237 * V_237 , struct V_205 * V_205 )
{
return F_111 ( V_205 , F_109 , NULL ) ;
}
static void F_112 ( void )
{
F_3 ( V_238 L_68 , V_239 , V_236 ) ;
}
static int T_4 F_113 ( struct V_240 * V_241 )
{
unsigned long V_17 ;
struct V_112 * V_38 ;
int error ;
V_242 = F_114 ( 1 ) ;
if ( ! V_242 )
return - V_97 ;
V_85 = NULL ;
F_112 () ;
V_242 -> V_243 = V_244 ;
V_242 -> V_245 = L_69 ;
V_242 -> V_3 = L_70 ;
V_242 -> V_246 = V_247 ;
V_242 -> V_248 = 64 ;
V_242 -> type = V_249 ;
V_242 -> V_250 = V_251 ;
V_242 -> V_252 = V_253 ;
V_242 -> V_252 . V_104 =
V_254 | V_255 | V_136 | V_115 | V_135 ;
V_242 -> V_17 = V_256 ;
F_115 ( V_242 , & V_257 ) ;
error = F_116 ( V_242 ) ;
if ( error )
goto V_258;
V_38 = V_228 ;
V_38 -> V_7 = V_259 ;
V_38 -> V_150 = ( int ) & V_20 . V_32 ;
V_38 -> line = 0 ;
V_38 -> V_130 = 0 ;
V_38 -> V_151 = 5 * V_133 / 10 ;
V_38 -> V_152 = 30 * V_133 ;
V_38 -> V_36 . V_76 = V_38 -> V_36 . V_73 =
V_38 -> V_36 . V_184 = V_38 -> V_36 . V_74 = 0 ;
V_38 -> V_36 . V_44 = V_38 -> V_36 . V_62 = 0 ;
V_38 -> V_36 . V_50 = V_38 -> V_36 . V_49 = 0 ;
V_38 -> V_36 . V_51 = V_38 -> V_36 . V_48 = 0 ;
F_3 ( V_238 L_71 ,
V_38 -> line ) ;
V_38 -> V_119 = V_260 ;
V_38 -> V_132 = 1 ;
error = F_34 ( V_261 , F_27 , 0 , L_72 , V_38 ) ;
if ( error )
goto V_262;
error = F_34 ( V_263 , F_26 , 0 ,
L_73 , V_38 ) ;
if ( error )
goto V_264;
F_6 ( V_17 ) ;
V_20 . V_21 = V_40 | V_22 ;
F_7 () ;
V_20 . V_23 = V_40 | V_22 ;
F_7 () ;
F_8 ( V_17 ) ;
V_10 . V_265 |= ( V_13 | V_12 ) ;
V_10 . V_265 &= ~ ( V_68 | V_69 | V_70 ) ;
F_117 ( V_241 , V_38 ) ;
return 0 ;
V_264:
F_40 ( V_261 , V_38 ) ;
V_262:
F_118 ( V_242 ) ;
V_258:
F_119 ( V_242 ) ;
return error ;
}
static int T_5 F_120 ( struct V_240 * V_241 )
{
int error ;
struct V_112 * V_38 = F_121 ( V_241 ) ;
struct V_1 * V_2 = V_38 -> V_2 ;
F_122 ( & V_2 -> V_30 ) ;
if ( ( error = F_118 ( V_242 ) ) )
F_3 ( L_74 ,
error ) ;
F_119 ( V_242 ) ;
V_228 [ 0 ] . V_2 = NULL ;
F_105 ( V_2 ) ;
F_40 ( V_261 , V_228 ) ;
F_40 ( V_263 , V_228 ) ;
F_117 ( V_241 , NULL ) ;
return error ;
}
static int T_4 F_123 ( void )
{
return F_124 ( & V_266 , F_113 ) ;
}
static void T_5 F_125 ( void )
{
F_126 ( & V_266 ) ;
}
static void F_127 ( char V_141 )
{
V_20 . V_61 = ( unsigned char ) V_141 | 0x100 ;
while ( ! ( V_20 . V_32 & 0x2000 ) )
F_128 () ;
}
static void F_129 ( struct V_267 * V_268 , const char * V_269 ,
unsigned V_140 )
{
unsigned short V_21 = V_20 . V_143 ;
V_20 . V_21 = V_22 ;
while ( V_140 -- ) {
if ( * V_269 == '\n' )
F_127 ( '\r' ) ;
F_127 ( * V_269 ++ ) ;
}
V_20 . V_21 = V_28 | ( V_21 & V_22 ) ;
}
static struct V_270 * F_130 ( struct V_267 * V_141 , int * V_229 )
{
* V_229 = 0 ;
return V_242 ;
}
static int T_4 F_131 ( void )
{
F_132 ( & V_271 ) ;
return 0 ;
}
