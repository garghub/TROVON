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
static void F_10 ( struct V_1 * V_2 )
{
int V_29 ;
int V_30 ;
struct V_14 * V_15 = V_2 -> V_31 . V_15 ;
unsigned char V_32 , V_33 ;
struct V_34 * V_35 ;
int V_36 = 0 ;
V_35 = & V_2 -> V_35 ;
V_29 = V_37 ;
V_30 = V_20 . V_30 ;
F_7 () ;
V_20 . V_23 = V_38 ;
F_7 () ;
if( ( V_30 & 0x1ff ) == 0 )
V_29 |= V_39 ;
if( V_30 & V_40 )
V_29 |= V_41 ;
V_32 = V_30 & 0xff ;
V_35 -> V_42 ++ ;
#ifdef F_11
F_3 ( L_5 , V_32 , V_29 ) ;
#endif
V_33 = V_43 ;
if ( V_29 & ( V_39 | V_44 |
V_45 | V_41 ) ) {
if ( V_29 & V_39 ) {
V_29 &= ~ ( V_45 | V_44 ) ;
V_35 -> V_46 ++ ;
} else if ( V_29 & V_44 )
V_35 -> V_47 ++ ;
else if ( V_29 & V_45 )
V_35 -> V_48 ++ ;
if ( V_29 & V_41 )
V_35 -> V_49 ++ ;
if ( V_29 & V_2 -> V_50 )
goto V_51;
V_29 &= V_2 -> V_52 ;
if ( V_29 & ( V_39 ) ) {
#ifdef F_11
F_3 ( L_6 ) ;
#endif
V_33 = V_53 ;
if ( V_2 -> V_31 . V_17 & V_54 )
F_12 ( V_15 ) ;
} else if ( V_29 & V_44 )
V_33 = V_55 ;
else if ( V_29 & V_45 )
V_33 = V_56 ;
if ( V_29 & V_41 ) {
V_36 = 1 ;
}
}
F_13 ( V_15 , V_32 , V_33 ) ;
if ( V_36 == 1 )
F_13 ( V_15 , 0 , V_57 ) ;
F_14 ( V_15 ) ;
V_51:
return;
}
static void F_15 ( struct V_1 * V_2 )
{
V_20 . V_23 = V_22 ;
F_7 () ;
if ( V_2 -> V_58 ) {
V_20 . V_59 = V_2 -> V_58 | 0x100 ;
F_7 () ;
V_2 -> V_35 . V_60 ++ ;
V_2 -> V_58 = 0 ;
return;
}
if ( V_2 -> V_24 . V_25 == V_2 -> V_24 . V_26
|| V_2 -> V_31 . V_15 -> V_61
|| V_2 -> V_31 . V_15 -> V_62 ) {
V_2 -> V_18 &= ~ V_19 ;
V_20 . V_21 = V_22 ;
F_7 () ;
return;
}
V_20 . V_59 = V_2 -> V_24 . V_27 [ V_2 -> V_24 . V_26 ++ ] | 0x100 ;
F_7 () ;
V_2 -> V_24 . V_26 = V_2 -> V_24 . V_26 & ( V_63 - 1 ) ;
V_2 -> V_35 . V_60 ++ ;
if ( F_16 ( V_2 -> V_24 . V_25 ,
V_2 -> V_24 . V_26 ,
V_63 ) < V_64 )
F_17 ( V_2 -> V_31 . V_15 ) ;
#ifdef F_11
F_3 ( L_7 ) ;
#endif
if ( V_2 -> V_24 . V_25 == V_2 -> V_24 . V_26 ) {
V_20 . V_21 = V_22 ;
F_7 () ;
V_2 -> V_18 &= ~ V_19 ;
}
}
static void F_18 ( struct V_1 * V_2 )
{
struct V_65 * V_66 = & V_2 -> V_31 ;
unsigned char V_29 = V_10 . V_11 & ( V_67 | V_68 | V_69 ) ;
unsigned char V_70 ;
struct V_34 * V_35 ;
V_70 = V_29 ^ V_71 ;
V_71 = V_29 ;
if ( V_70 ) {
V_35 = & V_2 -> V_35 ;
if ( V_70 & V_69 )
V_35 -> V_72 ++ ;
if ( V_70 & V_67 ) {
V_35 -> V_73 ++ ;
#ifdef F_19
if ( ( V_66 -> V_17 & V_74 ) &&
! ( V_29 & V_67 ) )
F_20 () ;
#endif
}
if ( V_70 & V_68 )
V_35 -> V_75 ++ ;
F_21 ( & V_66 -> V_76 ) ;
}
if ( ( V_66 -> V_17 & V_77 ) && ( V_70 & V_67 ) ) {
#if ( F_22 ( V_78 ) || F_22 ( F_11 ) )
F_3 ( L_8 , V_2 -> line ,
( ! ( V_29 & V_67 ) ) ? L_9 : L_10 ) ;
#endif
if ( ! ( V_29 & V_67 ) )
F_21 ( & V_66 -> V_79 ) ;
else {
#ifdef V_78
F_3 ( L_11 ) ;
#endif
if ( V_66 -> V_15 )
F_23 ( V_66 -> V_15 ) ;
}
}
if ( V_66 -> V_17 & V_80 ) {
if ( V_66 -> V_15 -> V_62 ) {
if ( ! ( V_29 & V_68 ) ) {
#if ( F_22 ( F_11 ) || F_22 ( V_81 ) )
F_3 ( L_12 ) ;
#endif
V_66 -> V_15 -> V_62 = 0 ;
V_2 -> V_18 |= V_19 ;
V_20 . V_21 = V_28 | V_22 ;
F_7 () ;
V_20 . V_23 = V_28 | V_22 ;
F_7 () ;
F_17 ( V_66 -> V_15 ) ;
return;
}
} else {
if ( ( V_29 & V_68 ) ) {
#if ( F_22 ( F_11 ) || F_22 ( V_81 ) )
F_3 ( L_13 ) ;
#endif
V_66 -> V_15 -> V_62 = 1 ;
V_2 -> V_18 &= ~ V_19 ;
V_20 . V_21 = V_22 ;
F_7 () ;
V_20 . V_23 = V_22 ;
F_7 () ;
}
}
}
}
static T_2 F_24 ( int V_82 , void * V_83 )
{
struct V_1 * V_2 = V_83 ;
if( V_2 -> V_18 & V_84 )
F_18 ( V_2 ) ;
return V_85 ;
}
static T_2 F_25 ( int V_82 , void * V_86 )
{
struct V_1 * V_2 = V_86 ;
#ifdef F_11
F_3 ( L_14 ) ;
#endif
if ( ! V_2 -> V_31 . V_15 )
return V_87 ;
F_10 ( V_2 ) ;
#ifdef F_11
F_3 ( L_15 ) ;
#endif
return V_85 ;
}
static T_2 F_26 ( int V_82 , void * V_86 )
{
struct V_1 * V_2 = V_86 ;
if ( V_20 . V_30 & V_88 ) {
#ifdef F_11
F_3 ( L_16 ) ;
#endif
if ( ! V_2 -> V_31 . V_15 )
return V_87 ;
F_15 ( V_2 ) ;
#ifdef F_11
F_3 ( L_15 ) ;
#endif
}
return V_85 ;
}
static int F_27 ( struct V_14 * V_15 , struct V_1 * V_2 )
{
struct V_65 * V_66 = & V_2 -> V_31 ;
unsigned long V_17 ;
int V_89 = 0 ;
unsigned long V_90 ;
V_90 = F_28 ( V_91 ) ;
if ( ! V_90 )
return - V_92 ;
F_6 ( V_17 ) ;
if ( V_66 -> V_17 & V_93 ) {
F_29 ( V_90 ) ;
goto V_94;
}
if ( V_2 -> V_24 . V_27 )
F_29 ( V_90 ) ;
else
V_2 -> V_24 . V_27 = ( unsigned char * ) V_90 ;
#ifdef V_78
F_3 ( L_17 , V_2 -> line ) ;
#endif
V_20 . V_23 = V_38 ;
F_7 () ;
V_89 = F_30 ( V_95 , F_24 , 0 , L_18 , V_2 ) ;
if ( V_89 ) {
if ( F_31 () ) {
F_32 ( V_96 , & V_15 -> V_17 ) ;
V_89 = 0 ;
}
goto V_94;
}
V_20 . V_21 = V_28 | V_38 | V_22 ;
F_7 () ;
V_2 -> V_18 = V_84 ;
V_71 = V_10 . V_11 & ( V_67 | V_68 | V_69 ) ;
V_2 -> V_97 = 0 ;
if ( F_33 ( V_15 ) )
V_2 -> V_97 = V_13 | V_12 ;
F_4 ( V_2 -> V_97 ) ;
F_34 ( V_96 , & V_15 -> V_17 ) ;
V_2 -> V_24 . V_25 = V_2 -> V_24 . V_26 = 0 ;
if ( ( V_66 -> V_17 & V_98 ) == V_99 )
V_15 -> V_100 = 57600 ;
if ( ( V_66 -> V_17 & V_98 ) == V_101 )
V_15 -> V_100 = 115200 ;
if ( ( V_66 -> V_17 & V_98 ) == V_102 )
V_15 -> V_100 = 230400 ;
if ( ( V_66 -> V_17 & V_98 ) == V_103 )
V_15 -> V_100 = 460800 ;
F_35 ( V_15 , V_2 , NULL ) ;
V_66 -> V_17 |= V_93 ;
F_8 ( V_17 ) ;
return 0 ;
V_94:
F_8 ( V_17 ) ;
return V_89 ;
}
static void F_36 ( struct V_14 * V_15 , struct V_1 * V_2 )
{
unsigned long V_17 ;
struct V_1 * V_104 ;
if ( ! ( V_2 -> V_31 . V_17 & V_93 ) )
return;
V_104 = V_2 ;
#ifdef V_78
F_3 ( L_19 , V_2 -> line ) ;
#endif
F_6 ( V_17 ) ;
F_21 ( & V_2 -> V_31 . V_76 ) ;
F_37 ( V_95 , V_2 ) ;
if ( V_2 -> V_24 . V_27 ) {
F_29 ( ( unsigned long ) V_2 -> V_24 . V_27 ) ;
V_2 -> V_24 . V_27 = NULL ;
}
V_2 -> V_18 = 0 ;
V_20 . V_21 = V_38 | V_22 ;
F_7 () ;
V_20 . V_105 = V_106 ;
F_7 () ;
if ( V_15 -> V_107 -> V_108 & V_109 )
V_2 -> V_97 &= ~ ( V_13 | V_12 ) ;
F_4 ( V_2 -> V_97 ) ;
F_32 ( V_96 , & V_15 -> V_17 ) ;
V_2 -> V_31 . V_17 &= ~ V_93 ;
F_8 ( V_17 ) ;
}
static void F_35 ( struct V_14 * V_15 , struct V_1 * V_2 ,
struct V_110 * V_111 )
{
struct V_65 * V_66 = & V_2 -> V_31 ;
int V_112 = 0 , V_113 , V_114 ;
unsigned V_115 , V_116 = 0 ;
int V_9 ;
unsigned long V_17 ;
V_115 = V_15 -> V_107 -> V_108 ;
V_116 = 3 ; V_9 = 10 ;
if ( V_115 & V_117 ) {
V_116 |= 0x04 ;
V_9 ++ ;
}
if ( V_115 & V_118 ) {
V_116 |= V_119 ;
V_9 ++ ;
}
if ( ! ( V_115 & V_120 ) )
V_116 |= V_121 ;
#ifdef F_38
if ( V_115 & F_38 )
V_116 |= V_122 ;
#endif
V_114 = F_39 ( V_15 ) ;
if ( ! V_114 )
V_114 = 9600 ;
V_113 = V_2 -> V_113 ;
if ( V_114 == 38400 && ( V_66 -> V_17 & V_98 ) == V_123 )
V_112 = V_2 -> V_124 ;
else {
if ( V_114 == 134 )
V_112 = ( 2 * V_113 / 269 ) ;
else if ( V_114 )
V_112 = V_113 / V_114 ;
}
if ( ! V_112 && V_111 ) {
V_15 -> V_107 -> V_108 &= ~ V_125 ;
V_15 -> V_107 -> V_108 |= ( V_111 -> V_108 & V_125 ) ;
V_114 = F_39 ( V_15 ) ;
if ( ! V_114 )
V_114 = 9600 ;
if ( V_114 == 38400 &&
( V_66 -> V_17 & V_98 ) == V_123 )
V_112 = V_2 -> V_124 ;
else {
if ( V_114 == 134 )
V_112 = ( 2 * V_113 / 269 ) ;
else if ( V_114 )
V_112 = V_113 / V_114 ;
}
}
if ( ! V_112 )
V_112 = V_113 / 9600 ;
V_2 -> V_112 = V_112 ;
V_2 -> V_126 = ( ( V_2 -> V_127 * V_128 * V_9 * V_112 ) / V_113 ) ;
V_2 -> V_126 += V_128 / 50 ;
V_2 -> V_18 &= ~ V_84 ;
if ( V_66 -> V_17 & V_74 )
V_2 -> V_18 |= V_84 ;
if ( V_115 & V_129 ) {
V_66 -> V_17 |= V_80 ;
V_2 -> V_18 |= V_84 ;
} else
V_66 -> V_17 &= ~ V_80 ;
if ( V_115 & V_130 )
V_66 -> V_17 &= ~ V_77 ;
else {
V_66 -> V_17 |= V_77 ;
V_2 -> V_18 |= V_84 ;
}
V_2 -> V_52 = V_41 | V_37 ;
if ( F_40 ( V_15 ) )
V_2 -> V_52 |= V_45 | V_44 ;
if ( F_41 ( V_15 ) || F_42 ( V_15 ) )
V_2 -> V_52 |= V_39 ;
V_2 -> V_50 = 0 ;
if ( F_43 ( V_15 ) )
V_2 -> V_50 |= V_44 | V_45 ;
if ( F_44 ( V_15 ) ) {
V_2 -> V_50 |= V_39 ;
if ( F_43 ( V_15 ) )
V_2 -> V_50 |= V_41 ;
}
if ( ( V_115 & V_131 ) == 0 )
V_2 -> V_50 |= V_37 ;
F_6 ( V_17 ) ;
{
short V_132 ;
V_132 = V_112 - 1 ;
if( V_116 & V_119 )
V_132 |= ( V_133 ) ;
V_20 . V_132 = V_132 ;
F_7 () ;
}
F_8 ( V_17 ) ;
}
static int F_45 ( struct V_14 * V_15 , unsigned char V_32 )
{
struct V_1 * V_2 ;
unsigned long V_17 ;
V_2 = V_15 -> V_16 ;
if ( F_1 ( V_2 , V_15 -> V_3 , L_20 ) )
return 0 ;
if ( ! V_2 -> V_24 . V_27 )
return 0 ;
F_6 ( V_17 ) ;
if ( F_46 ( V_2 -> V_24 . V_25 ,
V_2 -> V_24 . V_26 ,
V_63 ) == 0 ) {
F_8 ( V_17 ) ;
return 0 ;
}
V_2 -> V_24 . V_27 [ V_2 -> V_24 . V_25 ++ ] = V_32 ;
V_2 -> V_24 . V_25 &= V_63 - 1 ;
F_8 ( V_17 ) ;
return 1 ;
}
static void F_47 ( struct V_14 * V_15 )
{
struct V_1 * V_2 = V_15 -> V_16 ;
unsigned long V_17 ;
if ( F_1 ( V_2 , V_15 -> V_3 , L_21 ) )
return;
if ( V_2 -> V_24 . V_25 == V_2 -> V_24 . V_26
|| V_15 -> V_61
|| V_15 -> V_62
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
static int F_48 ( struct V_14 * V_15 , const unsigned char * V_27 , int V_134 )
{
int V_135 , V_136 = 0 ;
struct V_1 * V_2 = V_15 -> V_16 ;
unsigned long V_17 ;
if ( F_1 ( V_2 , V_15 -> V_3 , L_22 ) )
return 0 ;
if ( ! V_2 -> V_24 . V_27 )
return 0 ;
F_6 ( V_17 ) ;
while ( 1 ) {
V_135 = F_49 ( V_2 -> V_24 . V_25 ,
V_2 -> V_24 . V_26 ,
V_63 ) ;
if ( V_134 < V_135 )
V_135 = V_134 ;
if ( V_135 <= 0 ) {
break;
}
memcpy ( V_2 -> V_24 . V_27 + V_2 -> V_24 . V_25 , V_27 , V_135 ) ;
V_2 -> V_24 . V_25 = ( ( V_2 -> V_24 . V_25 + V_135 ) &
( V_63 - 1 ) ) ;
V_27 += V_135 ;
V_134 -= V_135 ;
V_136 += V_135 ;
}
F_8 ( V_17 ) ;
if ( V_2 -> V_24 . V_25 != V_2 -> V_24 . V_26
&& ! V_15 -> V_61
&& ! V_15 -> V_62
&& ! ( V_2 -> V_18 & V_19 ) ) {
V_2 -> V_18 |= V_19 ;
F_50 () ;
V_20 . V_21 = V_28 | V_22 ;
F_7 () ;
V_20 . V_23 = V_28 | V_22 ;
F_7 () ;
F_8 ( V_17 ) ;
}
return V_136 ;
}
static int F_51 ( struct V_14 * V_15 )
{
struct V_1 * V_2 = V_15 -> V_16 ;
if ( F_1 ( V_2 , V_15 -> V_3 , L_23 ) )
return 0 ;
return F_46 ( V_2 -> V_24 . V_25 , V_2 -> V_24 . V_26 , V_63 ) ;
}
static int F_52 ( struct V_14 * V_15 )
{
struct V_1 * V_2 = V_15 -> V_16 ;
if ( F_1 ( V_2 , V_15 -> V_3 , L_24 ) )
return 0 ;
return F_16 ( V_2 -> V_24 . V_25 , V_2 -> V_24 . V_26 , V_63 ) ;
}
static void F_53 ( struct V_14 * V_15 )
{
struct V_1 * V_2 = V_15 -> V_16 ;
unsigned long V_17 ;
if ( F_1 ( V_2 , V_15 -> V_3 , L_25 ) )
return;
F_6 ( V_17 ) ;
V_2 -> V_24 . V_25 = V_2 -> V_24 . V_26 = 0 ;
F_8 ( V_17 ) ;
F_17 ( V_15 ) ;
}
static void F_54 ( struct V_14 * V_15 , char V_32 )
{
struct V_1 * V_2 = V_15 -> V_16 ;
unsigned long V_17 ;
if ( F_1 ( V_2 , V_15 -> V_3 , L_26 ) )
return;
V_2 -> V_58 = V_32 ;
if ( V_32 ) {
F_6 ( V_17 ) ;
if( ! ( V_20 . V_137 & V_22 ) ) {
V_20 . V_21 = V_28 | V_22 ;
F_7 () ;
V_20 . V_23 = V_28 | V_22 ;
F_7 () ;
}
F_8 ( V_17 ) ;
V_2 -> V_18 |= V_19 ;
}
}
static void F_55 ( struct V_14 * V_15 )
{
struct V_1 * V_2 = V_15 -> V_16 ;
unsigned long V_17 ;
#ifdef F_56
char V_27 [ 64 ] ;
F_3 ( L_27 , F_57 ( V_15 , V_27 ) ,
V_15 -> V_138 . V_139 ( V_15 ) ) ;
#endif
if ( F_1 ( V_2 , V_15 -> V_3 , L_28 ) )
return;
if ( F_58 ( V_15 ) )
F_54 ( V_15 , F_59 ( V_15 ) ) ;
if ( V_15 -> V_107 -> V_108 & V_129 )
V_2 -> V_97 &= ~ V_12 ;
F_6 ( V_17 ) ;
F_4 ( V_2 -> V_97 ) ;
F_8 ( V_17 ) ;
}
static void F_60 ( struct V_14 * V_15 )
{
struct V_1 * V_2 = V_15 -> V_16 ;
unsigned long V_17 ;
#ifdef F_56
char V_27 [ 64 ] ;
F_3 ( L_29 , F_57 ( V_15 , V_27 ) ,
V_15 -> V_138 . V_139 ( V_15 ) ) ;
#endif
if ( F_1 ( V_2 , V_15 -> V_3 , L_30 ) )
return;
if ( F_58 ( V_15 ) ) {
if ( V_2 -> V_58 )
V_2 -> V_58 = 0 ;
else
F_54 ( V_15 , F_61 ( V_15 ) ) ;
}
if ( V_15 -> V_107 -> V_108 & V_129 )
V_2 -> V_97 |= V_12 ;
F_6 ( V_17 ) ;
F_4 ( V_2 -> V_97 ) ;
F_8 ( V_17 ) ;
}
static int F_62 ( struct V_14 * V_15 , struct V_1 * V_104 ,
struct V_140 T_3 * V_141 )
{
struct V_140 V_142 ;
if ( ! V_141 )
return - V_143 ;
memset ( & V_142 , 0 , sizeof( V_142 ) ) ;
F_63 () ;
V_142 . line = V_15 -> V_144 ;
V_142 . V_66 = V_104 -> V_66 ;
V_142 . V_17 = V_104 -> V_31 . V_17 ;
V_142 . V_127 = V_104 -> V_127 ;
V_142 . V_113 = V_104 -> V_113 ;
V_142 . V_145 = V_104 -> V_31 . V_145 ;
V_142 . V_146 = V_104 -> V_31 . V_146 ;
V_142 . V_124 = V_104 -> V_124 ;
F_64 () ;
if ( F_65 ( V_141 , & V_142 , sizeof( * V_141 ) ) )
return - V_143 ;
return 0 ;
}
static int F_66 ( struct V_14 * V_15 , struct V_1 * V_104 ,
struct V_140 T_3 * V_147 )
{
struct V_65 * V_66 = & V_104 -> V_31 ;
struct V_140 V_148 ;
bool V_149 ;
int V_89 = 0 ;
if ( F_67 ( & V_148 , V_147 , sizeof( V_148 ) ) )
return - V_143 ;
F_63 () ;
V_149 = ( ( V_148 . V_17 ^ V_66 -> V_17 ) & V_98 ) ||
V_148 . V_124 != V_104 -> V_124 ;
if ( V_148 . V_82 || V_148 . V_66 != V_104 -> V_66 ||
V_148 . V_127 != V_104 -> V_127 ) {
F_64 () ;
return - V_150 ;
}
if ( ! F_31 () ) {
if ( ( V_148 . V_113 != V_104 -> V_113 ) ||
( V_148 . V_145 != V_66 -> V_145 ) ||
( V_148 . V_127 != V_104 -> V_127 ) ||
( ( V_148 . V_17 & ~ V_151 ) !=
( V_66 -> V_17 & ~ V_151 ) ) ) {
F_64 () ;
return - V_152 ;
}
V_66 -> V_17 = ( ( V_66 -> V_17 & ~ V_151 ) |
( V_148 . V_17 & V_151 ) ) ;
V_104 -> V_124 = V_148 . V_124 ;
goto V_153;
}
if ( V_148 . V_113 < 9600 ) {
F_64 () ;
return - V_150 ;
}
V_104 -> V_113 = V_148 . V_113 ;
V_66 -> V_17 = ( ( V_66 -> V_17 & ~ V_154 ) |
( V_148 . V_17 & V_154 ) ) ;
V_104 -> V_124 = V_148 . V_124 ;
V_66 -> V_145 = V_148 . V_145 * V_128 / 100 ;
V_66 -> V_146 = V_148 . V_146 * V_128 / 100 ;
V_15 -> V_155 = ( V_66 -> V_17 & V_156 ) ? 1 : 0 ;
V_153:
if ( V_66 -> V_17 & V_93 ) {
if ( V_149 ) {
if ( ( V_66 -> V_17 & V_98 ) == V_99 )
V_15 -> V_100 = 57600 ;
if ( ( V_66 -> V_17 & V_98 ) == V_101 )
V_15 -> V_100 = 115200 ;
if ( ( V_66 -> V_17 & V_98 ) == V_102 )
V_15 -> V_100 = 230400 ;
if ( ( V_66 -> V_17 & V_98 ) == V_103 )
V_15 -> V_100 = 460800 ;
F_35 ( V_15 , V_104 , NULL ) ;
}
} else
V_89 = F_27 ( V_15 , V_104 ) ;
F_64 () ;
return V_89 ;
}
static int F_68 ( struct V_1 * V_2 , unsigned int T_3 * V_157 )
{
unsigned char V_29 ;
unsigned int V_158 ;
unsigned long V_17 ;
F_6 ( V_17 ) ;
V_29 = V_20 . V_30 ;
F_7 () ;
F_8 ( V_17 ) ;
V_158 = ( ( V_29 & V_159 ) ? V_160 : 0 ) ;
if ( F_65 ( V_157 , & V_158 , sizeof( int ) ) )
return - V_143 ;
return 0 ;
}
static int F_69 ( struct V_14 * V_15 )
{
struct V_1 * V_2 = V_15 -> V_16 ;
unsigned char V_161 , V_29 ;
unsigned long V_17 ;
if ( F_1 ( V_2 , V_15 -> V_3 , L_31 ) )
return - V_162 ;
if ( V_15 -> V_17 & ( 1 << V_96 ) )
return - V_163 ;
V_161 = V_2 -> V_97 ;
F_6 ( V_17 ) ;
V_29 = V_10 . V_11 ;
F_8 ( V_17 ) ;
return ( ( V_161 & V_12 ) ? V_164 : 0 )
| ( ( V_161 & V_13 ) ? V_165 : 0 )
| ( ! ( V_29 & V_67 ) ? V_166 : 0 )
| ( ! ( V_29 & V_69 ) ? V_167 : 0 )
| ( ! ( V_29 & V_68 ) ? V_168 : 0 ) ;
}
static int F_70 ( struct V_14 * V_15 , unsigned int V_169 ,
unsigned int V_170 )
{
struct V_1 * V_2 = V_15 -> V_16 ;
unsigned long V_17 ;
if ( F_1 ( V_2 , V_15 -> V_3 , L_31 ) )
return - V_162 ;
if ( V_15 -> V_17 & ( 1 << V_96 ) )
return - V_163 ;
F_6 ( V_17 ) ;
if ( V_169 & V_164 )
V_2 -> V_97 |= V_12 ;
if ( V_169 & V_165 )
V_2 -> V_97 |= V_13 ;
if ( V_170 & V_164 )
V_2 -> V_97 &= ~ V_12 ;
if ( V_170 & V_165 )
V_2 -> V_97 &= ~ V_13 ;
F_4 ( V_2 -> V_97 ) ;
F_8 ( V_17 ) ;
return 0 ;
}
static int F_71 ( struct V_14 * V_15 , int V_171 )
{
struct V_1 * V_2 = V_15 -> V_16 ;
unsigned long V_17 ;
if ( F_1 ( V_2 , V_15 -> V_3 , L_32 ) )
return - V_150 ;
F_6 ( V_17 ) ;
if ( V_171 == - 1 )
V_20 . V_105 = V_172 | V_106 ;
else
V_20 . V_105 = V_106 ;
F_7 () ;
F_8 ( V_17 ) ;
return 0 ;
}
static int F_72 ( struct V_14 * V_15 ,
struct V_173 * V_35 )
{
struct V_1 * V_2 = V_15 -> V_16 ;
struct V_34 V_174 ;
unsigned long V_17 ;
F_6 ( V_17 ) ;
V_174 = V_2 -> V_35 ;
F_8 ( V_17 ) ;
V_35 -> V_75 = V_174 . V_75 ;
V_35 -> V_72 = V_174 . V_72 ;
V_35 -> V_175 = V_174 . V_175 ;
V_35 -> V_73 = V_174 . V_73 ;
V_35 -> V_42 = V_174 . V_42 ;
V_35 -> V_60 = V_174 . V_60 ;
V_35 -> V_48 = V_174 . V_48 ;
V_35 -> V_49 = V_174 . V_49 ;
V_35 -> V_47 = V_174 . V_47 ;
V_35 -> V_46 = V_174 . V_46 ;
V_35 -> V_176 = V_174 . V_176 ;
return 0 ;
}
static int F_73 ( struct V_14 * V_15 ,
unsigned int V_177 , unsigned long V_178 )
{
struct V_1 * V_2 = V_15 -> V_16 ;
struct V_34 V_179 , V_174 ;
void T_3 * V_180 = ( void T_3 * ) V_178 ;
unsigned long V_17 ;
if ( F_1 ( V_2 , V_15 -> V_3 , L_31 ) )
return - V_162 ;
if ( ( V_177 != V_181 ) && ( V_177 != V_182 ) &&
( V_177 != V_183 ) && ( V_177 != V_184 ) &&
( V_177 != V_185 ) && ( V_177 != V_186 ) ) {
if ( V_15 -> V_17 & ( 1 << V_96 ) )
return - V_163 ;
}
switch ( V_177 ) {
case V_181 :
return F_62 ( V_15 , V_2 , V_180 ) ;
case V_182 :
return F_66 ( V_15 , V_2 , V_180 ) ;
case V_183 :
return 0 ;
case V_187 :
return F_68 ( V_2 , V_180 ) ;
case V_184 :
if ( F_65 ( V_180 ,
V_2 , sizeof( struct V_1 ) ) )
return - V_143 ;
return 0 ;
case V_185 :
F_6 ( V_17 ) ;
V_179 = V_2 -> V_35 ;
F_8 ( V_17 ) ;
while ( 1 ) {
F_74 ( & V_2 -> V_31 . V_76 ) ;
if ( F_75 ( V_188 ) )
return - V_189 ;
F_6 ( V_17 ) ;
V_174 = V_2 -> V_35 ;
F_8 ( V_17 ) ;
if ( V_174 . V_175 == V_179 . V_175 && V_174 . V_72 == V_179 . V_72 &&
V_174 . V_73 == V_179 . V_73 && V_174 . V_75 == V_179 . V_75 )
return - V_163 ;
if ( ( ( V_178 & V_190 ) && ( V_174 . V_175 != V_179 . V_175 ) ) ||
( ( V_178 & V_167 ) && ( V_174 . V_72 != V_179 . V_72 ) ) ||
( ( V_178 & V_191 ) && ( V_174 . V_73 != V_179 . V_73 ) ) ||
( ( V_178 & V_168 ) && ( V_174 . V_75 != V_179 . V_75 ) ) ) {
return 0 ;
}
V_179 = V_174 ;
}
case V_192 :
case V_193 :
F_3 ( L_33 ) ;
return 0 ;
default:
return - V_194 ;
}
return 0 ;
}
static void F_76 ( struct V_14 * V_15 , struct V_110 * V_111 )
{
struct V_1 * V_2 = V_15 -> V_16 ;
unsigned long V_17 ;
unsigned int V_115 = V_15 -> V_107 -> V_108 ;
F_35 ( V_15 , V_2 , V_111 ) ;
if ( ( V_111 -> V_108 & V_125 ) &&
! ( V_115 & V_125 ) ) {
V_2 -> V_97 &= ~ ( V_13 | V_12 ) ;
F_6 ( V_17 ) ;
F_4 ( V_2 -> V_97 ) ;
F_8 ( V_17 ) ;
}
if ( ! ( V_111 -> V_108 & V_125 ) &&
( V_115 & V_125 ) ) {
V_2 -> V_97 |= V_13 ;
if ( ! ( V_15 -> V_107 -> V_108 & V_129 ) ||
! F_77 ( V_195 , & V_15 -> V_17 ) ) {
V_2 -> V_97 |= V_12 ;
}
F_6 ( V_17 ) ;
F_4 ( V_2 -> V_97 ) ;
F_8 ( V_17 ) ;
}
if ( ( V_111 -> V_108 & V_129 ) &&
! ( V_15 -> V_107 -> V_108 & V_129 ) ) {
V_15 -> V_62 = 0 ;
F_9 ( V_15 ) ;
}
#if 0
if (!(old_termios->c_cflag & CLOCAL) &&
(tty->termios->c_cflag & CLOCAL))
wake_up_interruptible(&info->open_wait);
#endif
}
static void F_78 ( struct V_14 * V_15 , struct V_196 * V_197 )
{
struct V_1 * V_104 = V_15 -> V_16 ;
struct V_65 * V_66 = & V_104 -> V_31 ;
if ( F_1 ( V_104 , V_15 -> V_3 , L_34 ) )
return;
if ( F_79 ( V_66 , V_15 , V_197 ) == 0 )
return;
V_104 -> V_52 &= ~ V_37 ;
if ( V_66 -> V_17 & V_93 ) {
V_20 . V_21 = V_38 ;
F_7 () ;
V_20 . V_23 = V_38 ;
F_7 () ;
F_80 ( V_15 , V_104 -> V_126 ) ;
}
F_36 ( V_15 , V_104 ) ;
F_53 ( V_15 ) ;
F_81 ( V_15 ) ;
V_66 -> V_15 = NULL ;
F_82 ( V_66 , V_15 ) ;
}
static void F_80 ( struct V_14 * V_15 , int V_126 )
{
struct V_1 * V_2 = V_15 -> V_16 ;
unsigned long V_198 , V_199 ;
int V_200 ;
if ( F_1 ( V_2 , V_15 -> V_3 , L_35 ) )
return;
if ( V_2 -> V_127 == 0 )
return;
V_198 = V_201 ;
V_199 = ( V_2 -> V_126 - V_128 / 50 ) / V_2 -> V_127 ;
V_199 = V_199 / 5 ;
if ( V_199 == 0 )
V_199 = 1 ;
if ( V_126 )
V_199 = F_83 (unsigned long, char_time, timeout) ;
if ( ! V_126 || V_126 > 2 * V_2 -> V_126 )
V_126 = 2 * V_2 -> V_126 ;
#ifdef F_84
F_3 ( L_36 , V_126 , V_199 ) ;
F_3 ( L_37 , V_201 ) ;
#endif
while( ! ( ( V_200 = V_20 . V_30 ) & V_159 ) ) {
#ifdef F_84
F_3 ( L_38 , V_200 , V_201 ) ;
#endif
F_85 ( F_86 ( V_199 ) ) ;
if ( F_75 ( V_188 ) )
break;
if ( V_126 && F_87 ( V_201 , V_198 + V_126 ) )
break;
}
F_88 ( V_202 ) ;
#ifdef F_84
F_3 ( L_39 , V_200 , V_201 ) ;
#endif
}
static void F_89 ( struct V_14 * V_15 )
{
struct V_1 * V_2 = V_15 -> V_16 ;
if ( F_1 ( V_2 , V_15 -> V_3 , L_40 ) )
return;
F_53 ( V_15 ) ;
F_36 ( V_15 , V_2 ) ;
V_2 -> V_31 . V_134 = 0 ;
V_2 -> V_31 . V_17 &= ~ V_203 ;
V_2 -> V_31 . V_15 = NULL ;
F_21 ( & V_2 -> V_31 . V_79 ) ;
}
static int F_90 ( struct V_14 * V_15 , struct V_196 * V_197 )
{
struct V_1 * V_2 = V_204 + V_15 -> V_144 ;
struct V_65 * V_66 = & V_2 -> V_31 ;
int V_89 ;
V_66 -> V_134 ++ ;
V_66 -> V_15 = V_15 ;
V_15 -> V_16 = V_2 ;
V_15 -> V_66 = V_66 ;
if ( F_1 ( V_2 , V_15 -> V_3 , L_41 ) )
return - V_162 ;
V_15 -> V_155 = ( V_66 -> V_17 & V_156 ) ? 1 : 0 ;
V_89 = F_27 ( V_15 , V_2 ) ;
if ( V_89 ) {
return V_89 ;
}
return F_91 ( V_66 , V_15 , V_197 ) ;
}
static inline void F_92 ( struct V_205 * V_206 , int line ,
struct V_1 * V_104 )
{
char V_207 [ 30 ] , V_161 , V_29 ;
unsigned long V_17 ;
F_93 ( V_206 , L_42 , line ) ;
F_6 ( V_17 ) ;
V_29 = V_10 . V_11 ;
V_161 = ( V_104 -> V_31 . V_17 & V_93 ) ? V_104 -> V_97 : V_29 ;
F_8 ( V_17 ) ;
V_207 [ 0 ] = 0 ;
V_207 [ 1 ] = 0 ;
if( ! ( V_161 & V_12 ) )
strcat ( V_207 , L_43 ) ;
if( ! ( V_29 & V_68 ) )
strcat ( V_207 , L_44 ) ;
if( ! ( V_161 & V_13 ) )
strcat ( V_207 , L_45 ) ;
if( ! ( V_29 & V_69 ) )
strcat ( V_207 , L_46 ) ;
if( ! ( V_29 & V_67 ) )
strcat ( V_207 , L_47 ) ;
if ( V_104 -> V_112 )
F_93 ( V_206 , L_48 , V_104 -> V_113 / V_104 -> V_112 ) ;
F_93 ( V_206 , L_49 , V_104 -> V_35 . V_60 , V_104 -> V_35 . V_42 ) ;
if ( V_104 -> V_35 . V_48 )
F_93 ( V_206 , L_50 , V_104 -> V_35 . V_48 ) ;
if ( V_104 -> V_35 . V_47 )
F_93 ( V_206 , L_51 , V_104 -> V_35 . V_47 ) ;
if ( V_104 -> V_35 . V_46 )
F_93 ( V_206 , L_52 , V_104 -> V_35 . V_46 ) ;
if ( V_104 -> V_35 . V_49 )
F_93 ( V_206 , L_53 , V_104 -> V_35 . V_49 ) ;
F_93 ( V_206 , L_54 , V_207 + 1 ) ;
}
static int F_94 ( struct V_205 * V_206 , void * V_208 )
{
F_93 ( V_206 , L_55 , V_209 ) ;
F_92 ( V_206 , 0 , & V_204 [ 0 ] ) ;
return 0 ;
}
static int F_95 ( struct V_210 * V_210 , struct V_196 * V_196 )
{
return F_96 ( V_196 , F_94 , NULL ) ;
}
static void F_97 ( void )
{
F_3 ( V_211 L_56 , V_212 , V_209 ) ;
}
static int F_98 ( struct V_65 * V_66 )
{
return ! ( V_10 . V_11 & V_67 ) ;
}
static void F_99 ( struct V_65 * V_66 , int raise )
{
struct V_1 * V_2 = F_100 ( V_66 , struct V_1 ,
V_31 ) ;
unsigned long V_17 ;
if ( raise )
V_2 -> V_97 |= V_13 | V_12 ;
else
V_2 -> V_97 &= ~ ( V_13 | V_12 ) ;
F_6 ( V_17 ) ;
F_4 ( V_2 -> V_97 ) ;
F_8 ( V_17 ) ;
}
static int T_4 F_101 ( struct V_213 * V_214 )
{
unsigned long V_17 ;
struct V_1 * V_104 ;
int error ;
V_215 = F_102 ( V_216 ) ;
if ( ! V_215 )
return - V_92 ;
F_97 () ;
V_215 -> V_217 = L_57 ;
V_215 -> V_3 = L_58 ;
V_215 -> V_218 = V_219 ;
V_215 -> V_220 = 64 ;
V_215 -> type = V_221 ;
V_215 -> V_222 = V_223 ;
V_215 -> V_224 = V_225 ;
V_215 -> V_224 . V_108 =
V_226 | V_227 | V_131 | V_109 | V_130 ;
V_215 -> V_17 = V_228 ;
F_103 ( V_215 , & V_229 ) ;
error = F_104 ( V_215 ) ;
if ( error )
goto V_230;
V_104 = V_204 ;
V_104 -> V_66 = ( int ) & V_20 . V_30 ;
V_104 -> V_124 = 0 ;
V_104 -> V_35 . V_75 = V_104 -> V_35 . V_72 =
V_104 -> V_35 . V_175 = V_104 -> V_35 . V_73 = 0 ;
V_104 -> V_35 . V_42 = V_104 -> V_35 . V_60 = 0 ;
V_104 -> V_35 . V_48 = V_104 -> V_35 . V_47 = 0 ;
V_104 -> V_35 . V_49 = V_104 -> V_35 . V_46 = 0 ;
F_105 ( & V_104 -> V_31 ) ;
V_104 -> V_31 . V_231 = & V_232 ;
F_3 ( V_211 L_59 ) ;
V_104 -> V_113 = V_233 ;
V_104 -> V_127 = 1 ;
error = F_30 ( V_234 , F_26 , 0 , L_60 , V_104 ) ;
if ( error )
goto V_235;
error = F_30 ( V_236 , F_25 , 0 ,
L_61 , V_104 ) ;
if ( error )
goto V_237;
F_6 ( V_17 ) ;
V_20 . V_21 = V_38 | V_22 ;
F_7 () ;
V_20 . V_23 = V_38 | V_22 ;
F_7 () ;
F_8 ( V_17 ) ;
V_10 . V_238 |= ( V_13 | V_12 ) ;
V_10 . V_238 &= ~ ( V_67 | V_68 | V_69 ) ;
F_106 ( V_214 , V_104 ) ;
return 0 ;
V_237:
F_37 ( V_234 , V_104 ) ;
V_235:
F_107 ( V_215 ) ;
V_230:
F_108 ( V_215 ) ;
return error ;
}
static int T_5 F_109 ( struct V_213 * V_214 )
{
int error ;
struct V_1 * V_104 = F_110 ( V_214 ) ;
if ( ( error = F_107 ( V_215 ) ) )
F_3 ( L_62 ,
error ) ;
F_108 ( V_215 ) ;
F_37 ( V_234 , V_104 ) ;
F_37 ( V_236 , V_104 ) ;
F_106 ( V_214 , NULL ) ;
return error ;
}
static int T_4 F_111 ( void )
{
return F_112 ( & V_239 , F_101 ) ;
}
static void T_5 F_113 ( void )
{
F_114 ( & V_239 ) ;
}
static void F_115 ( char V_135 )
{
V_20 . V_59 = ( unsigned char ) V_135 | 0x100 ;
while ( ! ( V_20 . V_30 & 0x2000 ) )
F_116 () ;
}
static void F_117 ( struct V_240 * V_241 , const char * V_242 ,
unsigned V_134 )
{
unsigned short V_21 = V_20 . V_137 ;
V_20 . V_21 = V_22 ;
while ( V_134 -- ) {
if ( * V_242 == '\n' )
F_115 ( '\r' ) ;
F_115 ( * V_242 ++ ) ;
}
V_20 . V_21 = V_28 | ( V_21 & V_22 ) ;
}
static struct V_243 * F_118 ( struct V_240 * V_135 , int * V_144 )
{
* V_144 = 0 ;
return V_215 ;
}
static int T_4 F_119 ( void )
{
F_120 ( & V_244 ) ;
return 0 ;
}
