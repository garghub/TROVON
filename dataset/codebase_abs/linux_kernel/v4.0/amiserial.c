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
unsigned char V_31 , V_32 ;
struct V_33 * V_34 ;
int V_35 = 0 ;
V_34 = & V_2 -> V_34 ;
V_29 = V_36 ;
V_30 = V_20 . V_30 ;
F_7 () ;
V_20 . V_23 = V_37 ;
F_7 () ;
if( ( V_30 & 0x1ff ) == 0 )
V_29 |= V_38 ;
if( V_30 & V_39 )
V_29 |= V_40 ;
V_31 = V_30 & 0xff ;
V_34 -> V_41 ++ ;
#ifdef F_11
F_3 ( L_5 , V_31 , V_29 ) ;
#endif
V_32 = V_42 ;
if ( V_29 & ( V_38 | V_43 |
V_44 | V_40 ) ) {
if ( V_29 & V_38 ) {
V_29 &= ~ ( V_44 | V_43 ) ;
V_34 -> V_45 ++ ;
} else if ( V_29 & V_43 )
V_34 -> V_46 ++ ;
else if ( V_29 & V_44 )
V_34 -> V_47 ++ ;
if ( V_29 & V_40 )
V_34 -> V_48 ++ ;
if ( V_29 & V_2 -> V_49 )
goto V_50;
V_29 &= V_2 -> V_51 ;
if ( V_29 & ( V_38 ) ) {
#ifdef F_11
F_3 ( L_6 ) ;
#endif
V_32 = V_52 ;
if ( V_2 -> V_53 . V_17 & V_54 )
F_12 ( V_2 -> V_53 . V_15 ) ;
} else if ( V_29 & V_43 )
V_32 = V_55 ;
else if ( V_29 & V_44 )
V_32 = V_56 ;
if ( V_29 & V_40 ) {
V_35 = 1 ;
}
}
F_13 ( & V_2 -> V_53 , V_31 , V_32 ) ;
if ( V_35 == 1 )
F_13 ( & V_2 -> V_53 , 0 , V_57 ) ;
F_14 ( & V_2 -> V_53 ) ;
V_50:
return;
}
static void F_15 ( struct V_1 * V_2 )
{
V_20 . V_23 = V_22 ;
F_7 () ;
if ( V_2 -> V_58 ) {
V_20 . V_59 = V_2 -> V_58 | 0x100 ;
F_7 () ;
V_2 -> V_34 . V_60 ++ ;
V_2 -> V_58 = 0 ;
return;
}
if ( V_2 -> V_24 . V_25 == V_2 -> V_24 . V_26
|| V_2 -> V_53 . V_15 -> V_61
|| V_2 -> V_53 . V_15 -> V_62 ) {
V_2 -> V_18 &= ~ V_19 ;
V_20 . V_21 = V_22 ;
F_7 () ;
return;
}
V_20 . V_59 = V_2 -> V_24 . V_27 [ V_2 -> V_24 . V_26 ++ ] | 0x100 ;
F_7 () ;
V_2 -> V_24 . V_26 = V_2 -> V_24 . V_26 & ( V_63 - 1 ) ;
V_2 -> V_34 . V_60 ++ ;
if ( F_16 ( V_2 -> V_24 . V_25 ,
V_2 -> V_24 . V_26 ,
V_63 ) < V_64 )
F_17 ( V_2 -> V_53 . V_15 ) ;
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
struct V_65 * V_66 = & V_2 -> V_53 ;
unsigned char V_29 = V_10 . V_11 & ( V_67 | V_68 | V_69 ) ;
unsigned char V_70 ;
struct V_33 * V_34 ;
V_70 = V_29 ^ V_71 ;
V_71 = V_29 ;
if ( V_70 ) {
V_34 = & V_2 -> V_34 ;
if ( V_70 & V_69 )
V_34 -> V_72 ++ ;
if ( V_70 & V_67 ) {
V_34 -> V_73 ++ ;
}
if ( V_70 & V_68 )
V_34 -> V_74 ++ ;
F_19 ( & V_66 -> V_75 ) ;
}
if ( ( V_66 -> V_17 & V_76 ) && ( V_70 & V_67 ) ) {
#if ( F_20 ( V_77 ) || F_20 ( F_11 ) )
F_3 ( L_8 , V_2 -> line ,
( ! ( V_29 & V_67 ) ) ? L_9 : L_10 ) ;
#endif
if ( ! ( V_29 & V_67 ) )
F_19 ( & V_66 -> V_78 ) ;
else {
#ifdef V_77
F_3 ( L_11 ) ;
#endif
if ( V_66 -> V_15 )
F_21 ( V_66 -> V_15 ) ;
}
}
if ( F_22 ( V_66 ) ) {
if ( V_66 -> V_15 -> V_62 ) {
if ( ! ( V_29 & V_68 ) ) {
#if ( F_20 ( F_11 ) || F_20 ( V_79 ) )
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
#if ( F_20 ( F_11 ) || F_20 ( V_79 ) )
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
static T_2 F_23 ( int V_80 , void * V_81 )
{
struct V_1 * V_2 = V_81 ;
if( V_2 -> V_18 & V_82 )
F_18 ( V_2 ) ;
return V_83 ;
}
static T_2 F_24 ( int V_80 , void * V_84 )
{
struct V_1 * V_2 = V_84 ;
#ifdef F_11
F_3 ( L_14 ) ;
#endif
if ( ! V_2 -> V_53 . V_15 )
return V_85 ;
F_10 ( V_2 ) ;
#ifdef F_11
F_3 ( L_15 ) ;
#endif
return V_83 ;
}
static T_2 F_25 ( int V_80 , void * V_84 )
{
struct V_1 * V_2 = V_84 ;
if ( V_20 . V_30 & V_86 ) {
#ifdef F_11
F_3 ( L_16 ) ;
#endif
if ( ! V_2 -> V_53 . V_15 )
return V_85 ;
F_15 ( V_2 ) ;
#ifdef F_11
F_3 ( L_15 ) ;
#endif
}
return V_83 ;
}
static int F_26 ( struct V_14 * V_15 , struct V_1 * V_2 )
{
struct V_65 * V_66 = & V_2 -> V_53 ;
unsigned long V_17 ;
int V_87 = 0 ;
unsigned long V_88 ;
V_88 = F_27 ( V_89 ) ;
if ( ! V_88 )
return - V_90 ;
F_6 ( V_17 ) ;
if ( V_66 -> V_17 & V_91 ) {
F_28 ( V_88 ) ;
goto V_92;
}
if ( V_2 -> V_24 . V_27 )
F_28 ( V_88 ) ;
else
V_2 -> V_24 . V_27 = ( unsigned char * ) V_88 ;
#ifdef V_77
F_3 ( L_17 , V_2 -> line ) ;
#endif
V_20 . V_23 = V_37 ;
F_7 () ;
V_87 = F_29 ( V_93 , F_23 , 0 , L_18 , V_2 ) ;
if ( V_87 ) {
if ( F_30 () ) {
F_31 ( V_94 , & V_15 -> V_17 ) ;
V_87 = 0 ;
}
goto V_92;
}
V_20 . V_21 = V_28 | V_37 | V_22 ;
F_7 () ;
V_2 -> V_18 = V_82 ;
V_71 = V_10 . V_11 & ( V_67 | V_68 | V_69 ) ;
V_2 -> V_95 = 0 ;
if ( F_32 ( V_15 ) )
V_2 -> V_95 = V_13 | V_12 ;
F_4 ( V_2 -> V_95 ) ;
F_33 ( V_94 , & V_15 -> V_17 ) ;
V_2 -> V_24 . V_25 = V_2 -> V_24 . V_26 = 0 ;
if ( ( V_66 -> V_17 & V_96 ) == V_97 )
V_15 -> V_98 = 57600 ;
if ( ( V_66 -> V_17 & V_96 ) == V_99 )
V_15 -> V_98 = 115200 ;
if ( ( V_66 -> V_17 & V_96 ) == V_100 )
V_15 -> V_98 = 230400 ;
if ( ( V_66 -> V_17 & V_96 ) == V_101 )
V_15 -> V_98 = 460800 ;
F_34 ( V_15 , V_2 , NULL ) ;
V_66 -> V_17 |= V_91 ;
F_8 ( V_17 ) ;
return 0 ;
V_92:
F_8 ( V_17 ) ;
return V_87 ;
}
static void F_35 ( struct V_14 * V_15 , struct V_1 * V_2 )
{
unsigned long V_17 ;
struct V_1 * V_102 ;
if ( ! ( V_2 -> V_53 . V_17 & V_91 ) )
return;
V_102 = V_2 ;
#ifdef V_77
F_3 ( L_19 , V_2 -> line ) ;
#endif
F_6 ( V_17 ) ;
F_19 ( & V_2 -> V_53 . V_75 ) ;
F_36 ( V_93 , V_2 ) ;
if ( V_2 -> V_24 . V_27 ) {
F_28 ( ( unsigned long ) V_2 -> V_24 . V_27 ) ;
V_2 -> V_24 . V_27 = NULL ;
}
V_2 -> V_18 = 0 ;
V_20 . V_21 = V_37 | V_22 ;
F_7 () ;
V_20 . V_103 = V_104 ;
F_7 () ;
if ( V_15 -> V_105 . V_106 & V_107 )
V_2 -> V_95 &= ~ ( V_13 | V_12 ) ;
F_4 ( V_2 -> V_95 ) ;
F_31 ( V_94 , & V_15 -> V_17 ) ;
V_2 -> V_53 . V_17 &= ~ V_91 ;
F_8 ( V_17 ) ;
}
static void F_34 ( struct V_14 * V_15 , struct V_1 * V_2 ,
struct V_108 * V_109 )
{
struct V_65 * V_66 = & V_2 -> V_53 ;
int V_110 = 0 , V_111 , V_112 ;
unsigned V_113 , V_114 = 0 ;
int V_9 ;
unsigned long V_17 ;
V_113 = V_15 -> V_105 . V_106 ;
V_114 = 3 ; V_9 = 10 ;
if ( V_113 & V_115 ) {
V_114 |= 0x04 ;
V_9 ++ ;
}
if ( V_113 & V_116 ) {
V_114 |= V_117 ;
V_9 ++ ;
}
if ( ! ( V_113 & V_118 ) )
V_114 |= V_119 ;
#ifdef F_37
if ( V_113 & F_37 )
V_114 |= V_120 ;
#endif
V_112 = F_38 ( V_15 ) ;
if ( ! V_112 )
V_112 = 9600 ;
V_111 = V_2 -> V_111 ;
if ( V_112 == 38400 && ( V_66 -> V_17 & V_96 ) == V_121 )
V_110 = V_2 -> V_122 ;
else {
if ( V_112 == 134 )
V_110 = ( 2 * V_111 / 269 ) ;
else if ( V_112 )
V_110 = V_111 / V_112 ;
}
if ( ! V_110 && V_109 ) {
V_15 -> V_105 . V_106 &= ~ V_123 ;
V_15 -> V_105 . V_106 |= ( V_109 -> V_106 & V_123 ) ;
V_112 = F_38 ( V_15 ) ;
if ( ! V_112 )
V_112 = 9600 ;
if ( V_112 == 38400 &&
( V_66 -> V_17 & V_96 ) == V_121 )
V_110 = V_2 -> V_122 ;
else {
if ( V_112 == 134 )
V_110 = ( 2 * V_111 / 269 ) ;
else if ( V_112 )
V_110 = V_111 / V_112 ;
}
}
if ( ! V_110 )
V_110 = V_111 / 9600 ;
V_2 -> V_110 = V_110 ;
V_2 -> V_124 = ( ( V_2 -> V_125 * V_126 * V_9 * V_110 ) / V_111 ) ;
V_2 -> V_124 += V_126 / 50 ;
V_2 -> V_18 &= ~ V_82 ;
if ( V_66 -> V_17 & V_127 )
V_2 -> V_18 |= V_82 ;
if ( V_113 & V_128 ) {
V_66 -> V_17 |= V_129 ;
V_2 -> V_18 |= V_82 ;
} else
V_66 -> V_17 &= ~ V_129 ;
if ( V_113 & V_130 )
V_66 -> V_17 &= ~ V_76 ;
else {
V_66 -> V_17 |= V_76 ;
V_2 -> V_18 |= V_82 ;
}
V_2 -> V_51 = V_40 | V_36 ;
if ( F_39 ( V_15 ) )
V_2 -> V_51 |= V_44 | V_43 ;
if ( F_40 ( V_15 ) || F_41 ( V_15 ) )
V_2 -> V_51 |= V_38 ;
V_2 -> V_49 = 0 ;
if ( F_42 ( V_15 ) )
V_2 -> V_49 |= V_43 | V_44 ;
if ( F_43 ( V_15 ) ) {
V_2 -> V_49 |= V_38 ;
if ( F_42 ( V_15 ) )
V_2 -> V_49 |= V_40 ;
}
if ( ( V_113 & V_131 ) == 0 )
V_2 -> V_49 |= V_36 ;
F_6 ( V_17 ) ;
{
short V_132 ;
V_132 = V_110 - 1 ;
if( V_114 & V_117 )
V_132 |= ( V_133 ) ;
V_20 . V_132 = V_132 ;
F_7 () ;
}
F_8 ( V_17 ) ;
}
static int F_44 ( struct V_14 * V_15 , unsigned char V_31 )
{
struct V_1 * V_2 ;
unsigned long V_17 ;
V_2 = V_15 -> V_16 ;
if ( F_1 ( V_2 , V_15 -> V_3 , L_20 ) )
return 0 ;
if ( ! V_2 -> V_24 . V_27 )
return 0 ;
F_6 ( V_17 ) ;
if ( F_45 ( V_2 -> V_24 . V_25 ,
V_2 -> V_24 . V_26 ,
V_63 ) == 0 ) {
F_8 ( V_17 ) ;
return 0 ;
}
V_2 -> V_24 . V_27 [ V_2 -> V_24 . V_25 ++ ] = V_31 ;
V_2 -> V_24 . V_25 &= V_63 - 1 ;
F_8 ( V_17 ) ;
return 1 ;
}
static void F_46 ( struct V_14 * V_15 )
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
static int F_47 ( struct V_14 * V_15 , const unsigned char * V_27 , int V_134 )
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
V_135 = F_48 ( V_2 -> V_24 . V_25 ,
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
F_49 () ;
V_20 . V_21 = V_28 | V_22 ;
F_7 () ;
V_20 . V_23 = V_28 | V_22 ;
F_7 () ;
F_8 ( V_17 ) ;
}
return V_136 ;
}
static int F_50 ( struct V_14 * V_15 )
{
struct V_1 * V_2 = V_15 -> V_16 ;
if ( F_1 ( V_2 , V_15 -> V_3 , L_23 ) )
return 0 ;
return F_45 ( V_2 -> V_24 . V_25 , V_2 -> V_24 . V_26 , V_63 ) ;
}
static int F_51 ( struct V_14 * V_15 )
{
struct V_1 * V_2 = V_15 -> V_16 ;
if ( F_1 ( V_2 , V_15 -> V_3 , L_24 ) )
return 0 ;
return F_16 ( V_2 -> V_24 . V_25 , V_2 -> V_24 . V_26 , V_63 ) ;
}
static void F_52 ( struct V_14 * V_15 )
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
static void F_53 ( struct V_14 * V_15 , char V_31 )
{
struct V_1 * V_2 = V_15 -> V_16 ;
unsigned long V_17 ;
if ( F_1 ( V_2 , V_15 -> V_3 , L_26 ) )
return;
V_2 -> V_58 = V_31 ;
if ( V_31 ) {
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
static void F_54 ( struct V_14 * V_15 )
{
struct V_1 * V_2 = V_15 -> V_16 ;
unsigned long V_17 ;
#ifdef F_55
char V_27 [ 64 ] ;
F_3 ( L_27 , F_56 ( V_15 , V_27 ) ,
V_15 -> V_138 . V_139 ( V_15 ) ) ;
#endif
if ( F_1 ( V_2 , V_15 -> V_3 , L_28 ) )
return;
if ( F_57 ( V_15 ) )
F_53 ( V_15 , F_58 ( V_15 ) ) ;
if ( V_15 -> V_105 . V_106 & V_128 )
V_2 -> V_95 &= ~ V_12 ;
F_6 ( V_17 ) ;
F_4 ( V_2 -> V_95 ) ;
F_8 ( V_17 ) ;
}
static void F_59 ( struct V_14 * V_15 )
{
struct V_1 * V_2 = V_15 -> V_16 ;
unsigned long V_17 ;
#ifdef F_55
char V_27 [ 64 ] ;
F_3 ( L_29 , F_56 ( V_15 , V_27 ) ,
V_15 -> V_138 . V_139 ( V_15 ) ) ;
#endif
if ( F_1 ( V_2 , V_15 -> V_3 , L_30 ) )
return;
if ( F_57 ( V_15 ) ) {
if ( V_2 -> V_58 )
V_2 -> V_58 = 0 ;
else
F_53 ( V_15 , F_60 ( V_15 ) ) ;
}
if ( V_15 -> V_105 . V_106 & V_128 )
V_2 -> V_95 |= V_12 ;
F_6 ( V_17 ) ;
F_4 ( V_2 -> V_95 ) ;
F_8 ( V_17 ) ;
}
static int F_61 ( struct V_14 * V_15 , struct V_1 * V_102 ,
struct V_140 T_3 * V_141 )
{
struct V_140 V_142 ;
if ( ! V_141 )
return - V_143 ;
memset ( & V_142 , 0 , sizeof( V_142 ) ) ;
F_62 ( V_15 ) ;
V_142 . line = V_15 -> V_144 ;
V_142 . V_66 = V_102 -> V_66 ;
V_142 . V_17 = V_102 -> V_53 . V_17 ;
V_142 . V_125 = V_102 -> V_125 ;
V_142 . V_111 = V_102 -> V_111 ;
V_142 . V_145 = V_102 -> V_53 . V_145 ;
V_142 . V_146 = V_102 -> V_53 . V_146 ;
V_142 . V_122 = V_102 -> V_122 ;
F_63 ( V_15 ) ;
if ( F_64 ( V_141 , & V_142 , sizeof( * V_141 ) ) )
return - V_143 ;
return 0 ;
}
static int F_65 ( struct V_14 * V_15 , struct V_1 * V_102 ,
struct V_140 T_3 * V_147 )
{
struct V_65 * V_66 = & V_102 -> V_53 ;
struct V_140 V_148 ;
bool V_149 ;
int V_87 = 0 ;
if ( F_66 ( & V_148 , V_147 , sizeof( V_148 ) ) )
return - V_143 ;
F_62 ( V_15 ) ;
V_149 = ( ( V_148 . V_17 ^ V_66 -> V_17 ) & V_96 ) ||
V_148 . V_122 != V_102 -> V_122 ;
if ( V_148 . V_80 || V_148 . V_66 != V_102 -> V_66 ||
V_148 . V_125 != V_102 -> V_125 ) {
F_63 ( V_15 ) ;
return - V_150 ;
}
if ( ! F_30 () ) {
if ( ( V_148 . V_111 != V_102 -> V_111 ) ||
( V_148 . V_145 != V_66 -> V_145 ) ||
( V_148 . V_125 != V_102 -> V_125 ) ||
( ( V_148 . V_17 & ~ V_151 ) !=
( V_66 -> V_17 & ~ V_151 ) ) ) {
F_63 ( V_15 ) ;
return - V_152 ;
}
V_66 -> V_17 = ( ( V_66 -> V_17 & ~ V_151 ) |
( V_148 . V_17 & V_151 ) ) ;
V_102 -> V_122 = V_148 . V_122 ;
goto V_153;
}
if ( V_148 . V_111 < 9600 ) {
F_63 ( V_15 ) ;
return - V_150 ;
}
V_102 -> V_111 = V_148 . V_111 ;
V_66 -> V_17 = ( ( V_66 -> V_17 & ~ V_154 ) |
( V_148 . V_17 & V_154 ) ) ;
V_102 -> V_122 = V_148 . V_122 ;
V_66 -> V_145 = V_148 . V_145 * V_126 / 100 ;
V_66 -> V_146 = V_148 . V_146 * V_126 / 100 ;
V_66 -> V_155 = ( V_66 -> V_17 & V_156 ) ? 1 : 0 ;
V_153:
if ( V_66 -> V_17 & V_91 ) {
if ( V_149 ) {
if ( ( V_66 -> V_17 & V_96 ) == V_97 )
V_15 -> V_98 = 57600 ;
if ( ( V_66 -> V_17 & V_96 ) == V_99 )
V_15 -> V_98 = 115200 ;
if ( ( V_66 -> V_17 & V_96 ) == V_100 )
V_15 -> V_98 = 230400 ;
if ( ( V_66 -> V_17 & V_96 ) == V_101 )
V_15 -> V_98 = 460800 ;
F_34 ( V_15 , V_102 , NULL ) ;
}
} else
V_87 = F_26 ( V_15 , V_102 ) ;
F_63 ( V_15 ) ;
return V_87 ;
}
static int F_67 ( struct V_1 * V_2 , unsigned int T_3 * V_157 )
{
unsigned char V_29 ;
unsigned int V_158 ;
unsigned long V_17 ;
F_6 ( V_17 ) ;
V_29 = V_20 . V_30 ;
F_7 () ;
F_8 ( V_17 ) ;
V_158 = ( ( V_29 & V_159 ) ? V_160 : 0 ) ;
if ( F_64 ( V_157 , & V_158 , sizeof( int ) ) )
return - V_143 ;
return 0 ;
}
static int F_68 ( struct V_14 * V_15 )
{
struct V_1 * V_2 = V_15 -> V_16 ;
unsigned char V_161 , V_29 ;
unsigned long V_17 ;
if ( F_1 ( V_2 , V_15 -> V_3 , L_31 ) )
return - V_162 ;
if ( V_15 -> V_17 & ( 1 << V_94 ) )
return - V_163 ;
V_161 = V_2 -> V_95 ;
F_6 ( V_17 ) ;
V_29 = V_10 . V_11 ;
F_8 ( V_17 ) ;
return ( ( V_161 & V_12 ) ? V_164 : 0 )
| ( ( V_161 & V_13 ) ? V_165 : 0 )
| ( ! ( V_29 & V_67 ) ? V_166 : 0 )
| ( ! ( V_29 & V_69 ) ? V_167 : 0 )
| ( ! ( V_29 & V_68 ) ? V_168 : 0 ) ;
}
static int F_69 ( struct V_14 * V_15 , unsigned int V_169 ,
unsigned int V_170 )
{
struct V_1 * V_2 = V_15 -> V_16 ;
unsigned long V_17 ;
if ( F_1 ( V_2 , V_15 -> V_3 , L_31 ) )
return - V_162 ;
if ( V_15 -> V_17 & ( 1 << V_94 ) )
return - V_163 ;
F_6 ( V_17 ) ;
if ( V_169 & V_164 )
V_2 -> V_95 |= V_12 ;
if ( V_169 & V_165 )
V_2 -> V_95 |= V_13 ;
if ( V_170 & V_164 )
V_2 -> V_95 &= ~ V_12 ;
if ( V_170 & V_165 )
V_2 -> V_95 &= ~ V_13 ;
F_4 ( V_2 -> V_95 ) ;
F_8 ( V_17 ) ;
return 0 ;
}
static int F_70 ( struct V_14 * V_15 , int V_171 )
{
struct V_1 * V_2 = V_15 -> V_16 ;
unsigned long V_17 ;
if ( F_1 ( V_2 , V_15 -> V_3 , L_32 ) )
return - V_150 ;
F_6 ( V_17 ) ;
if ( V_171 == - 1 )
V_20 . V_103 = V_172 | V_104 ;
else
V_20 . V_103 = V_104 ;
F_7 () ;
F_8 ( V_17 ) ;
return 0 ;
}
static int F_71 ( struct V_14 * V_15 ,
struct V_173 * V_34 )
{
struct V_1 * V_2 = V_15 -> V_16 ;
struct V_33 V_174 ;
unsigned long V_17 ;
F_6 ( V_17 ) ;
V_174 = V_2 -> V_34 ;
F_8 ( V_17 ) ;
V_34 -> V_74 = V_174 . V_74 ;
V_34 -> V_72 = V_174 . V_72 ;
V_34 -> V_175 = V_174 . V_175 ;
V_34 -> V_73 = V_174 . V_73 ;
V_34 -> V_41 = V_174 . V_41 ;
V_34 -> V_60 = V_174 . V_60 ;
V_34 -> V_47 = V_174 . V_47 ;
V_34 -> V_48 = V_174 . V_48 ;
V_34 -> V_46 = V_174 . V_46 ;
V_34 -> V_45 = V_174 . V_45 ;
V_34 -> V_176 = V_174 . V_176 ;
return 0 ;
}
static int F_72 ( struct V_14 * V_15 ,
unsigned int V_177 , unsigned long V_178 )
{
struct V_1 * V_2 = V_15 -> V_16 ;
struct V_33 V_179 , V_174 ;
void T_3 * V_180 = ( void T_3 * ) V_178 ;
unsigned long V_17 ;
F_73 ( V_181 ) ;
int V_136 ;
if ( F_1 ( V_2 , V_15 -> V_3 , L_31 ) )
return - V_162 ;
if ( ( V_177 != V_182 ) && ( V_177 != V_183 ) &&
( V_177 != V_184 ) && ( V_177 != V_185 ) &&
( V_177 != V_186 ) && ( V_177 != V_187 ) ) {
if ( V_15 -> V_17 & ( 1 << V_94 ) )
return - V_163 ;
}
switch ( V_177 ) {
case V_182 :
return F_61 ( V_15 , V_2 , V_180 ) ;
case V_183 :
return F_65 ( V_15 , V_2 , V_180 ) ;
case V_184 :
return 0 ;
case V_188 :
return F_67 ( V_2 , V_180 ) ;
case V_185 :
if ( F_64 ( V_180 ,
V_2 , sizeof( struct V_1 ) ) )
return - V_143 ;
return 0 ;
case V_186 :
F_6 ( V_17 ) ;
V_179 = V_2 -> V_34 ;
F_8 ( V_17 ) ;
while ( 1 ) {
F_74 ( & V_2 -> V_53 . V_75 ,
& V_181 , V_189 ) ;
F_6 ( V_17 ) ;
V_174 = V_2 -> V_34 ;
F_8 ( V_17 ) ;
if ( V_174 . V_175 == V_179 . V_175 && V_174 . V_72 == V_179 . V_72 &&
V_174 . V_73 == V_179 . V_73 && V_174 . V_74 == V_179 . V_74 ) {
V_136 = - V_163 ;
break;
}
if ( ( ( V_178 & V_190 ) && ( V_174 . V_175 != V_179 . V_175 ) ) ||
( ( V_178 & V_167 ) && ( V_174 . V_72 != V_179 . V_72 ) ) ||
( ( V_178 & V_191 ) && ( V_174 . V_73 != V_179 . V_73 ) ) ||
( ( V_178 & V_168 ) && ( V_174 . V_74 != V_179 . V_74 ) ) ) {
V_136 = 0 ;
break;
}
F_75 () ;
if ( F_76 ( V_192 ) ) {
V_136 = - V_193 ;
break;
}
V_179 = V_174 ;
}
F_77 ( & V_2 -> V_53 . V_75 , & V_181 ) ;
return V_136 ;
case V_194 :
case V_195 :
F_3 ( L_33 ) ;
return 0 ;
default:
return - V_196 ;
}
return 0 ;
}
static void F_78 ( struct V_14 * V_15 , struct V_108 * V_109 )
{
struct V_1 * V_2 = V_15 -> V_16 ;
unsigned long V_17 ;
unsigned int V_113 = V_15 -> V_105 . V_106 ;
F_34 ( V_15 , V_2 , V_109 ) ;
if ( ( V_109 -> V_106 & V_123 ) &&
! ( V_113 & V_123 ) ) {
V_2 -> V_95 &= ~ ( V_13 | V_12 ) ;
F_6 ( V_17 ) ;
F_4 ( V_2 -> V_95 ) ;
F_8 ( V_17 ) ;
}
if ( ! ( V_109 -> V_106 & V_123 ) &&
( V_113 & V_123 ) ) {
V_2 -> V_95 |= V_13 ;
if ( ! ( V_15 -> V_105 . V_106 & V_128 ) ||
! F_79 ( V_197 , & V_15 -> V_17 ) ) {
V_2 -> V_95 |= V_12 ;
}
F_6 ( V_17 ) ;
F_4 ( V_2 -> V_95 ) ;
F_8 ( V_17 ) ;
}
if ( ( V_109 -> V_106 & V_128 ) &&
! ( V_15 -> V_105 . V_106 & V_128 ) ) {
V_15 -> V_62 = 0 ;
F_9 ( V_15 ) ;
}
#if 0
if (!(old_termios->c_cflag & CLOCAL) &&
(tty->termios.c_cflag & CLOCAL))
wake_up_interruptible(&info->open_wait);
#endif
}
static void F_80 ( struct V_14 * V_15 , struct V_198 * V_199 )
{
struct V_1 * V_102 = V_15 -> V_16 ;
struct V_65 * V_66 = & V_102 -> V_53 ;
if ( F_1 ( V_102 , V_15 -> V_3 , L_34 ) )
return;
if ( F_81 ( V_66 , V_15 , V_199 ) == 0 )
return;
V_102 -> V_51 &= ~ V_36 ;
if ( V_66 -> V_17 & V_91 ) {
V_20 . V_21 = V_37 ;
F_7 () ;
V_20 . V_23 = V_37 ;
F_7 () ;
F_82 ( V_15 , V_102 -> V_124 ) ;
}
F_35 ( V_15 , V_102 ) ;
F_52 ( V_15 ) ;
F_83 ( V_15 ) ;
V_66 -> V_15 = NULL ;
F_84 ( V_66 , V_15 ) ;
}
static void F_82 ( struct V_14 * V_15 , int V_124 )
{
struct V_1 * V_2 = V_15 -> V_16 ;
unsigned long V_200 , V_201 ;
int V_202 ;
if ( F_1 ( V_2 , V_15 -> V_3 , L_35 ) )
return;
if ( V_2 -> V_125 == 0 )
return;
V_200 = V_203 ;
V_201 = ( V_2 -> V_124 - V_126 / 50 ) / V_2 -> V_125 ;
V_201 = V_201 / 5 ;
if ( V_201 == 0 )
V_201 = 1 ;
if ( V_124 )
V_201 = F_85 (unsigned long, char_time, timeout) ;
if ( ! V_124 || V_124 > 2 * V_2 -> V_124 )
V_124 = 2 * V_2 -> V_124 ;
#ifdef F_86
F_3 ( L_36 , V_124 , V_201 ) ;
F_3 ( L_37 , V_203 ) ;
#endif
while( ! ( ( V_202 = V_20 . V_30 ) & V_159 ) ) {
#ifdef F_86
F_3 ( L_38 , V_202 , V_203 ) ;
#endif
F_87 ( F_88 ( V_201 ) ) ;
if ( F_76 ( V_192 ) )
break;
if ( V_124 && F_89 ( V_203 , V_200 + V_124 ) )
break;
}
F_90 ( V_204 ) ;
#ifdef F_86
F_3 ( L_39 , V_202 , V_203 ) ;
#endif
}
static void F_91 ( struct V_14 * V_15 )
{
struct V_1 * V_2 = V_15 -> V_16 ;
if ( F_1 ( V_2 , V_15 -> V_3 , L_40 ) )
return;
F_52 ( V_15 ) ;
F_35 ( V_15 , V_2 ) ;
V_2 -> V_53 . V_134 = 0 ;
V_2 -> V_53 . V_17 &= ~ V_205 ;
V_2 -> V_53 . V_15 = NULL ;
F_19 ( & V_2 -> V_53 . V_78 ) ;
}
static int F_92 ( struct V_14 * V_15 , struct V_198 * V_199 )
{
struct V_1 * V_2 = V_206 + V_15 -> V_144 ;
struct V_65 * V_66 = & V_2 -> V_53 ;
int V_87 ;
V_66 -> V_134 ++ ;
V_66 -> V_15 = V_15 ;
V_15 -> V_16 = V_2 ;
V_15 -> V_66 = V_66 ;
if ( F_1 ( V_2 , V_15 -> V_3 , L_41 ) )
return - V_162 ;
V_66 -> V_155 = ( V_66 -> V_17 & V_156 ) ? 1 : 0 ;
V_87 = F_26 ( V_15 , V_2 ) ;
if ( V_87 ) {
return V_87 ;
}
return F_93 ( V_66 , V_15 , V_199 ) ;
}
static inline void F_94 ( struct V_207 * V_208 , int line ,
struct V_1 * V_102 )
{
char V_209 [ 30 ] , V_161 , V_29 ;
unsigned long V_17 ;
F_95 ( V_208 , L_42 , line ) ;
F_6 ( V_17 ) ;
V_29 = V_10 . V_11 ;
V_161 = ( V_102 -> V_53 . V_17 & V_91 ) ? V_102 -> V_95 : V_29 ;
F_8 ( V_17 ) ;
V_209 [ 0 ] = 0 ;
V_209 [ 1 ] = 0 ;
if( ! ( V_161 & V_12 ) )
strcat ( V_209 , L_43 ) ;
if( ! ( V_29 & V_68 ) )
strcat ( V_209 , L_44 ) ;
if( ! ( V_161 & V_13 ) )
strcat ( V_209 , L_45 ) ;
if( ! ( V_29 & V_69 ) )
strcat ( V_209 , L_46 ) ;
if( ! ( V_29 & V_67 ) )
strcat ( V_209 , L_47 ) ;
if ( V_102 -> V_110 )
F_95 ( V_208 , L_48 , V_102 -> V_111 / V_102 -> V_110 ) ;
F_95 ( V_208 , L_49 , V_102 -> V_34 . V_60 , V_102 -> V_34 . V_41 ) ;
if ( V_102 -> V_34 . V_47 )
F_95 ( V_208 , L_50 , V_102 -> V_34 . V_47 ) ;
if ( V_102 -> V_34 . V_46 )
F_95 ( V_208 , L_51 , V_102 -> V_34 . V_46 ) ;
if ( V_102 -> V_34 . V_45 )
F_95 ( V_208 , L_52 , V_102 -> V_34 . V_45 ) ;
if ( V_102 -> V_34 . V_48 )
F_95 ( V_208 , L_53 , V_102 -> V_34 . V_48 ) ;
F_95 ( V_208 , L_54 , V_209 + 1 ) ;
}
static int F_96 ( struct V_207 * V_208 , void * V_210 )
{
F_95 ( V_208 , L_55 , V_211 ) ;
F_94 ( V_208 , 0 , & V_206 [ 0 ] ) ;
return 0 ;
}
static int F_97 ( struct V_212 * V_212 , struct V_198 * V_198 )
{
return F_98 ( V_198 , F_96 , NULL ) ;
}
static void F_99 ( void )
{
F_3 ( V_213 L_56 , V_214 , V_211 ) ;
}
static int F_100 ( struct V_65 * V_66 )
{
return ! ( V_10 . V_11 & V_67 ) ;
}
static void F_101 ( struct V_65 * V_66 , int raise )
{
struct V_1 * V_2 = F_102 ( V_66 , struct V_1 ,
V_53 ) ;
unsigned long V_17 ;
if ( raise )
V_2 -> V_95 |= V_13 | V_12 ;
else
V_2 -> V_95 &= ~ ( V_13 | V_12 ) ;
F_6 ( V_17 ) ;
F_4 ( V_2 -> V_95 ) ;
F_8 ( V_17 ) ;
}
static int T_4 F_103 ( struct V_215 * V_216 )
{
unsigned long V_17 ;
struct V_1 * V_102 ;
int error ;
V_217 = F_104 ( V_218 ) ;
if ( ! V_217 )
return - V_90 ;
F_99 () ;
V_217 -> V_219 = L_57 ;
V_217 -> V_3 = L_58 ;
V_217 -> V_220 = V_221 ;
V_217 -> V_222 = 64 ;
V_217 -> type = V_223 ;
V_217 -> V_224 = V_225 ;
V_217 -> V_226 = V_227 ;
V_217 -> V_226 . V_106 =
V_228 | V_229 | V_131 | V_107 | V_130 ;
V_217 -> V_17 = V_230 ;
F_105 ( V_217 , & V_231 ) ;
V_102 = V_206 ;
V_102 -> V_66 = ( int ) & V_20 . V_30 ;
V_102 -> V_122 = 0 ;
V_102 -> V_34 . V_74 = V_102 -> V_34 . V_72 =
V_102 -> V_34 . V_175 = V_102 -> V_34 . V_73 = 0 ;
V_102 -> V_34 . V_41 = V_102 -> V_34 . V_60 = 0 ;
V_102 -> V_34 . V_47 = V_102 -> V_34 . V_46 = 0 ;
V_102 -> V_34 . V_48 = V_102 -> V_34 . V_45 = 0 ;
F_106 ( & V_102 -> V_53 ) ;
V_102 -> V_53 . V_232 = & V_233 ;
F_107 ( & V_102 -> V_53 , V_217 , 0 ) ;
error = F_108 ( V_217 ) ;
if ( error )
goto V_234;
F_3 ( V_213 L_59 ) ;
V_102 -> V_111 = V_235 ;
V_102 -> V_125 = 1 ;
error = F_29 ( V_236 , F_25 , 0 , L_60 , V_102 ) ;
if ( error )
goto V_237;
error = F_29 ( V_238 , F_24 , 0 ,
L_61 , V_102 ) ;
if ( error )
goto V_239;
F_6 ( V_17 ) ;
V_20 . V_21 = V_37 | V_22 ;
F_7 () ;
V_20 . V_23 = V_37 | V_22 ;
F_7 () ;
F_8 ( V_17 ) ;
V_10 . V_240 |= ( V_13 | V_12 ) ;
V_10 . V_240 &= ~ ( V_67 | V_68 | V_69 ) ;
F_109 ( V_216 , V_102 ) ;
return 0 ;
V_239:
F_36 ( V_236 , V_102 ) ;
V_237:
F_110 ( V_217 ) ;
V_234:
F_111 ( & V_102 -> V_53 ) ;
F_112 ( V_217 ) ;
return error ;
}
static int T_5 F_113 ( struct V_215 * V_216 )
{
int error ;
struct V_1 * V_102 = F_114 ( V_216 ) ;
if ( ( error = F_110 ( V_217 ) ) )
F_3 ( L_62 ,
error ) ;
F_112 ( V_217 ) ;
F_111 ( & V_102 -> V_53 ) ;
F_36 ( V_236 , V_102 ) ;
F_36 ( V_238 , V_102 ) ;
return error ;
}
static void F_115 ( char V_135 )
{
V_20 . V_59 = ( unsigned char ) V_135 | 0x100 ;
while ( ! ( V_20 . V_30 & 0x2000 ) )
F_116 () ;
}
static void F_117 ( struct V_241 * V_242 , const char * V_243 ,
unsigned V_134 )
{
unsigned short V_21 = V_20 . V_137 ;
V_20 . V_21 = V_22 ;
while ( V_134 -- ) {
if ( * V_243 == '\n' )
F_115 ( '\r' ) ;
F_115 ( * V_243 ++ ) ;
}
V_20 . V_21 = V_28 | ( V_21 & V_22 ) ;
}
static struct V_244 * F_118 ( struct V_241 * V_135 , int * V_144 )
{
* V_144 = 0 ;
return V_217 ;
}
static int T_4 F_119 ( void )
{
if ( ! V_245 )
return - V_162 ;
F_120 ( & V_246 ) ;
return 0 ;
}
