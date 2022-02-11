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
if ( F_20 ( V_66 ) && ( V_70 & V_67 ) ) {
#if ( F_21 ( V_76 ) || F_21 ( F_11 ) )
F_3 ( L_8 , V_2 -> line ,
( ! ( V_29 & V_67 ) ) ? L_9 : L_10 ) ;
#endif
if ( ! ( V_29 & V_67 ) )
F_19 ( & V_66 -> V_77 ) ;
else {
#ifdef V_76
F_3 ( L_11 ) ;
#endif
if ( V_66 -> V_15 )
F_22 ( V_66 -> V_15 ) ;
}
}
if ( F_23 ( V_66 ) ) {
if ( V_66 -> V_15 -> V_62 ) {
if ( ! ( V_29 & V_68 ) ) {
#if ( F_21 ( F_11 ) || F_21 ( V_78 ) )
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
#if ( F_21 ( F_11 ) || F_21 ( V_78 ) )
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
static T_2 F_24 ( int V_79 , void * V_80 )
{
struct V_1 * V_2 = V_80 ;
if( V_2 -> V_18 & V_81 )
F_18 ( V_2 ) ;
return V_82 ;
}
static T_2 F_25 ( int V_79 , void * V_83 )
{
struct V_1 * V_2 = V_83 ;
#ifdef F_11
F_3 ( L_14 ) ;
#endif
if ( ! V_2 -> V_53 . V_15 )
return V_84 ;
F_10 ( V_2 ) ;
#ifdef F_11
F_3 ( L_15 ) ;
#endif
return V_82 ;
}
static T_2 F_26 ( int V_79 , void * V_83 )
{
struct V_1 * V_2 = V_83 ;
if ( V_20 . V_30 & V_85 ) {
#ifdef F_11
F_3 ( L_16 ) ;
#endif
if ( ! V_2 -> V_53 . V_15 )
return V_84 ;
F_15 ( V_2 ) ;
#ifdef F_11
F_3 ( L_15 ) ;
#endif
}
return V_82 ;
}
static int F_27 ( struct V_14 * V_15 , struct V_1 * V_2 )
{
struct V_65 * V_66 = & V_2 -> V_53 ;
unsigned long V_17 ;
int V_86 = 0 ;
unsigned long V_87 ;
V_87 = F_28 ( V_88 ) ;
if ( ! V_87 )
return - V_89 ;
F_6 ( V_17 ) ;
if ( F_29 ( V_66 ) ) {
F_30 ( V_87 ) ;
goto V_90;
}
if ( V_2 -> V_24 . V_27 )
F_30 ( V_87 ) ;
else
V_2 -> V_24 . V_27 = ( unsigned char * ) V_87 ;
#ifdef V_76
F_3 ( L_17 , V_2 -> line ) ;
#endif
V_20 . V_23 = V_37 ;
F_7 () ;
V_86 = F_31 ( V_91 , F_24 , 0 , L_18 , V_2 ) ;
if ( V_86 ) {
if ( F_32 () ) {
F_33 ( V_92 , & V_15 -> V_17 ) ;
V_86 = 0 ;
}
goto V_90;
}
V_20 . V_21 = V_28 | V_37 | V_22 ;
F_7 () ;
V_2 -> V_18 = V_81 ;
V_71 = V_10 . V_11 & ( V_67 | V_68 | V_69 ) ;
V_2 -> V_93 = 0 ;
if ( F_34 ( V_15 ) )
V_2 -> V_93 = V_13 | V_12 ;
F_4 ( V_2 -> V_93 ) ;
F_35 ( V_92 , & V_15 -> V_17 ) ;
V_2 -> V_24 . V_25 = V_2 -> V_24 . V_26 = 0 ;
if ( ( V_66 -> V_17 & V_94 ) == V_95 )
V_15 -> V_96 = 57600 ;
if ( ( V_66 -> V_17 & V_94 ) == V_97 )
V_15 -> V_96 = 115200 ;
if ( ( V_66 -> V_17 & V_94 ) == V_98 )
V_15 -> V_96 = 230400 ;
if ( ( V_66 -> V_17 & V_94 ) == V_99 )
V_15 -> V_96 = 460800 ;
F_36 ( V_15 , V_2 , NULL ) ;
F_37 ( V_66 , 1 ) ;
F_8 ( V_17 ) ;
return 0 ;
V_90:
F_8 ( V_17 ) ;
return V_86 ;
}
static void F_38 ( struct V_14 * V_15 , struct V_1 * V_2 )
{
unsigned long V_17 ;
struct V_1 * V_100 ;
if ( ! F_29 ( & V_2 -> V_53 ) )
return;
V_100 = V_2 ;
#ifdef V_76
F_3 ( L_19 , V_2 -> line ) ;
#endif
F_6 ( V_17 ) ;
F_19 ( & V_2 -> V_53 . V_75 ) ;
F_39 ( V_91 , V_2 ) ;
if ( V_2 -> V_24 . V_27 ) {
F_30 ( ( unsigned long ) V_2 -> V_24 . V_27 ) ;
V_2 -> V_24 . V_27 = NULL ;
}
V_2 -> V_18 = 0 ;
V_20 . V_21 = V_37 | V_22 ;
F_7 () ;
V_20 . V_101 = V_102 ;
F_7 () ;
if ( F_40 ( V_15 ) )
V_2 -> V_93 &= ~ ( V_13 | V_12 ) ;
F_4 ( V_2 -> V_93 ) ;
F_33 ( V_92 , & V_15 -> V_17 ) ;
F_37 ( & V_2 -> V_53 , 0 ) ;
F_8 ( V_17 ) ;
}
static void F_36 ( struct V_14 * V_15 , struct V_1 * V_2 ,
struct V_103 * V_104 )
{
struct V_65 * V_66 = & V_2 -> V_53 ;
int V_105 = 0 , V_106 , V_107 ;
unsigned V_108 , V_109 = 0 ;
int V_9 ;
unsigned long V_17 ;
V_108 = V_15 -> V_110 . V_111 ;
V_109 = 3 ; V_9 = 10 ;
if ( V_108 & V_112 ) {
V_109 |= 0x04 ;
V_9 ++ ;
}
if ( V_108 & V_113 ) {
V_109 |= V_114 ;
V_9 ++ ;
}
if ( ! ( V_108 & V_115 ) )
V_109 |= V_116 ;
#ifdef F_41
if ( V_108 & F_41 )
V_109 |= V_117 ;
#endif
V_107 = F_42 ( V_15 ) ;
if ( ! V_107 )
V_107 = 9600 ;
V_106 = V_2 -> V_106 ;
if ( V_107 == 38400 && ( V_66 -> V_17 & V_94 ) == V_118 )
V_105 = V_2 -> V_119 ;
else {
if ( V_107 == 134 )
V_105 = ( 2 * V_106 / 269 ) ;
else if ( V_107 )
V_105 = V_106 / V_107 ;
}
if ( ! V_105 && V_104 ) {
V_15 -> V_110 . V_111 &= ~ V_120 ;
V_15 -> V_110 . V_111 |= ( V_104 -> V_111 & V_120 ) ;
V_107 = F_42 ( V_15 ) ;
if ( ! V_107 )
V_107 = 9600 ;
if ( V_107 == 38400 &&
( V_66 -> V_17 & V_94 ) == V_118 )
V_105 = V_2 -> V_119 ;
else {
if ( V_107 == 134 )
V_105 = ( 2 * V_106 / 269 ) ;
else if ( V_107 )
V_105 = V_106 / V_107 ;
}
}
if ( ! V_105 )
V_105 = V_106 / 9600 ;
V_2 -> V_105 = V_105 ;
V_2 -> V_121 = ( ( V_2 -> V_122 * V_123 * V_9 * V_105 ) / V_106 ) ;
V_2 -> V_121 += V_123 / 50 ;
V_2 -> V_18 &= ~ V_81 ;
if ( V_66 -> V_17 & V_124 )
V_2 -> V_18 |= V_81 ;
F_43 ( V_66 , V_108 & V_125 ) ;
if ( V_108 & V_125 )
V_2 -> V_18 |= V_81 ;
F_44 ( V_66 , ~ V_108 & V_126 ) ;
if ( ~ V_108 & V_126 )
V_2 -> V_18 |= V_81 ;
V_2 -> V_51 = V_40 | V_36 ;
if ( F_45 ( V_15 ) )
V_2 -> V_51 |= V_44 | V_43 ;
if ( F_46 ( V_15 ) || F_47 ( V_15 ) )
V_2 -> V_51 |= V_38 ;
V_2 -> V_49 = 0 ;
if ( F_48 ( V_15 ) )
V_2 -> V_49 |= V_43 | V_44 ;
if ( F_49 ( V_15 ) ) {
V_2 -> V_49 |= V_38 ;
if ( F_48 ( V_15 ) )
V_2 -> V_49 |= V_40 ;
}
if ( ( V_108 & V_127 ) == 0 )
V_2 -> V_49 |= V_36 ;
F_6 ( V_17 ) ;
{
short V_128 ;
V_128 = V_105 - 1 ;
if( V_109 & V_114 )
V_128 |= ( V_129 ) ;
V_20 . V_128 = V_128 ;
F_7 () ;
}
F_8 ( V_17 ) ;
}
static int F_50 ( struct V_14 * V_15 , unsigned char V_31 )
{
struct V_1 * V_2 ;
unsigned long V_17 ;
V_2 = V_15 -> V_16 ;
if ( F_1 ( V_2 , V_15 -> V_3 , L_20 ) )
return 0 ;
if ( ! V_2 -> V_24 . V_27 )
return 0 ;
F_6 ( V_17 ) ;
if ( F_51 ( V_2 -> V_24 . V_25 ,
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
static void F_52 ( struct V_14 * V_15 )
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
static int F_53 ( struct V_14 * V_15 , const unsigned char * V_27 , int V_130 )
{
int V_131 , V_132 = 0 ;
struct V_1 * V_2 = V_15 -> V_16 ;
unsigned long V_17 ;
if ( F_1 ( V_2 , V_15 -> V_3 , L_22 ) )
return 0 ;
if ( ! V_2 -> V_24 . V_27 )
return 0 ;
F_6 ( V_17 ) ;
while ( 1 ) {
V_131 = F_54 ( V_2 -> V_24 . V_25 ,
V_2 -> V_24 . V_26 ,
V_63 ) ;
if ( V_130 < V_131 )
V_131 = V_130 ;
if ( V_131 <= 0 ) {
break;
}
memcpy ( V_2 -> V_24 . V_27 + V_2 -> V_24 . V_25 , V_27 , V_131 ) ;
V_2 -> V_24 . V_25 = ( ( V_2 -> V_24 . V_25 + V_131 ) &
( V_63 - 1 ) ) ;
V_27 += V_131 ;
V_130 -= V_131 ;
V_132 += V_131 ;
}
F_8 ( V_17 ) ;
if ( V_2 -> V_24 . V_25 != V_2 -> V_24 . V_26
&& ! V_15 -> V_61
&& ! V_15 -> V_62
&& ! ( V_2 -> V_18 & V_19 ) ) {
V_2 -> V_18 |= V_19 ;
F_55 () ;
V_20 . V_21 = V_28 | V_22 ;
F_7 () ;
V_20 . V_23 = V_28 | V_22 ;
F_7 () ;
F_8 ( V_17 ) ;
}
return V_132 ;
}
static int F_56 ( struct V_14 * V_15 )
{
struct V_1 * V_2 = V_15 -> V_16 ;
if ( F_1 ( V_2 , V_15 -> V_3 , L_23 ) )
return 0 ;
return F_51 ( V_2 -> V_24 . V_25 , V_2 -> V_24 . V_26 , V_63 ) ;
}
static int F_57 ( struct V_14 * V_15 )
{
struct V_1 * V_2 = V_15 -> V_16 ;
if ( F_1 ( V_2 , V_15 -> V_3 , L_24 ) )
return 0 ;
return F_16 ( V_2 -> V_24 . V_25 , V_2 -> V_24 . V_26 , V_63 ) ;
}
static void F_58 ( struct V_14 * V_15 )
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
static void F_59 ( struct V_14 * V_15 , char V_31 )
{
struct V_1 * V_2 = V_15 -> V_16 ;
unsigned long V_17 ;
if ( F_1 ( V_2 , V_15 -> V_3 , L_26 ) )
return;
V_2 -> V_58 = V_31 ;
if ( V_31 ) {
F_6 ( V_17 ) ;
if( ! ( V_20 . V_133 & V_22 ) ) {
V_20 . V_21 = V_28 | V_22 ;
F_7 () ;
V_20 . V_23 = V_28 | V_22 ;
F_7 () ;
}
F_8 ( V_17 ) ;
V_2 -> V_18 |= V_19 ;
}
}
static void F_60 ( struct V_14 * V_15 )
{
struct V_1 * V_2 = V_15 -> V_16 ;
unsigned long V_17 ;
#ifdef F_61
F_3 ( L_27 , F_62 ( V_15 ) ) ;
#endif
if ( F_1 ( V_2 , V_15 -> V_3 , L_28 ) )
return;
if ( F_63 ( V_15 ) )
F_59 ( V_15 , F_64 ( V_15 ) ) ;
if ( F_65 ( V_15 ) )
V_2 -> V_93 &= ~ V_12 ;
F_6 ( V_17 ) ;
F_4 ( V_2 -> V_93 ) ;
F_8 ( V_17 ) ;
}
static void F_66 ( struct V_14 * V_15 )
{
struct V_1 * V_2 = V_15 -> V_16 ;
unsigned long V_17 ;
#ifdef F_61
F_3 ( L_29 , F_62 ( V_15 ) ) ;
#endif
if ( F_1 ( V_2 , V_15 -> V_3 , L_30 ) )
return;
if ( F_63 ( V_15 ) ) {
if ( V_2 -> V_58 )
V_2 -> V_58 = 0 ;
else
F_59 ( V_15 , F_67 ( V_15 ) ) ;
}
if ( F_65 ( V_15 ) )
V_2 -> V_93 |= V_12 ;
F_6 ( V_17 ) ;
F_4 ( V_2 -> V_93 ) ;
F_8 ( V_17 ) ;
}
static int F_68 ( struct V_14 * V_15 , struct V_1 * V_100 ,
struct V_134 T_3 * V_135 )
{
struct V_134 V_136 ;
memset ( & V_136 , 0 , sizeof( V_136 ) ) ;
F_69 ( V_15 ) ;
V_136 . line = V_15 -> V_137 ;
V_136 . V_66 = V_100 -> V_66 ;
V_136 . V_17 = V_100 -> V_53 . V_17 ;
V_136 . V_122 = V_100 -> V_122 ;
V_136 . V_106 = V_100 -> V_106 ;
V_136 . V_138 = V_100 -> V_53 . V_138 ;
V_136 . V_139 = V_100 -> V_53 . V_139 ;
V_136 . V_119 = V_100 -> V_119 ;
F_70 ( V_15 ) ;
if ( F_71 ( V_135 , & V_136 , sizeof( * V_135 ) ) )
return - V_140 ;
return 0 ;
}
static int F_72 ( struct V_14 * V_15 , struct V_1 * V_100 ,
struct V_134 T_3 * V_141 )
{
struct V_65 * V_66 = & V_100 -> V_53 ;
struct V_134 V_142 ;
bool V_143 ;
int V_86 = 0 ;
if ( F_73 ( & V_142 , V_141 , sizeof( V_142 ) ) )
return - V_140 ;
F_69 ( V_15 ) ;
V_143 = ( ( V_142 . V_17 ^ V_66 -> V_17 ) & V_94 ) ||
V_142 . V_119 != V_100 -> V_119 ;
if ( V_142 . V_79 || V_142 . V_66 != V_100 -> V_66 ||
V_142 . V_122 != V_100 -> V_122 ) {
F_70 ( V_15 ) ;
return - V_144 ;
}
if ( ! F_32 () ) {
if ( ( V_142 . V_106 != V_100 -> V_106 ) ||
( V_142 . V_138 != V_66 -> V_138 ) ||
( V_142 . V_122 != V_100 -> V_122 ) ||
( ( V_142 . V_17 & ~ V_145 ) !=
( V_66 -> V_17 & ~ V_145 ) ) ) {
F_70 ( V_15 ) ;
return - V_146 ;
}
V_66 -> V_17 = ( ( V_66 -> V_17 & ~ V_145 ) |
( V_142 . V_17 & V_145 ) ) ;
V_100 -> V_119 = V_142 . V_119 ;
goto V_147;
}
if ( V_142 . V_106 < 9600 ) {
F_70 ( V_15 ) ;
return - V_144 ;
}
V_100 -> V_106 = V_142 . V_106 ;
V_66 -> V_17 = ( ( V_66 -> V_17 & ~ V_148 ) |
( V_142 . V_17 & V_148 ) ) ;
V_100 -> V_119 = V_142 . V_119 ;
V_66 -> V_138 = V_142 . V_138 * V_123 / 100 ;
V_66 -> V_139 = V_142 . V_139 * V_123 / 100 ;
V_66 -> V_149 = ( V_66 -> V_17 & V_150 ) ? 1 : 0 ;
V_147:
if ( F_29 ( V_66 ) ) {
if ( V_143 ) {
if ( ( V_66 -> V_17 & V_94 ) == V_95 )
V_15 -> V_96 = 57600 ;
if ( ( V_66 -> V_17 & V_94 ) == V_97 )
V_15 -> V_96 = 115200 ;
if ( ( V_66 -> V_17 & V_94 ) == V_98 )
V_15 -> V_96 = 230400 ;
if ( ( V_66 -> V_17 & V_94 ) == V_99 )
V_15 -> V_96 = 460800 ;
F_36 ( V_15 , V_100 , NULL ) ;
}
} else
V_86 = F_27 ( V_15 , V_100 ) ;
F_70 ( V_15 ) ;
return V_86 ;
}
static int F_74 ( struct V_1 * V_2 , unsigned int T_3 * V_151 )
{
unsigned char V_29 ;
unsigned int V_152 ;
unsigned long V_17 ;
F_6 ( V_17 ) ;
V_29 = V_20 . V_30 ;
F_7 () ;
F_8 ( V_17 ) ;
V_152 = ( ( V_29 & V_153 ) ? V_154 : 0 ) ;
if ( F_71 ( V_151 , & V_152 , sizeof( int ) ) )
return - V_140 ;
return 0 ;
}
static int F_75 ( struct V_14 * V_15 )
{
struct V_1 * V_2 = V_15 -> V_16 ;
unsigned char V_155 , V_29 ;
unsigned long V_17 ;
if ( F_1 ( V_2 , V_15 -> V_3 , L_31 ) )
return - V_156 ;
if ( F_76 ( V_15 ) )
return - V_157 ;
V_155 = V_2 -> V_93 ;
F_6 ( V_17 ) ;
V_29 = V_10 . V_11 ;
F_8 ( V_17 ) ;
return ( ( V_155 & V_12 ) ? V_158 : 0 )
| ( ( V_155 & V_13 ) ? V_159 : 0 )
| ( ! ( V_29 & V_67 ) ? V_160 : 0 )
| ( ! ( V_29 & V_69 ) ? V_161 : 0 )
| ( ! ( V_29 & V_68 ) ? V_162 : 0 ) ;
}
static int F_77 ( struct V_14 * V_15 , unsigned int V_163 ,
unsigned int V_164 )
{
struct V_1 * V_2 = V_15 -> V_16 ;
unsigned long V_17 ;
if ( F_1 ( V_2 , V_15 -> V_3 , L_31 ) )
return - V_156 ;
if ( F_76 ( V_15 ) )
return - V_157 ;
F_6 ( V_17 ) ;
if ( V_163 & V_158 )
V_2 -> V_93 |= V_12 ;
if ( V_163 & V_159 )
V_2 -> V_93 |= V_13 ;
if ( V_164 & V_158 )
V_2 -> V_93 &= ~ V_12 ;
if ( V_164 & V_159 )
V_2 -> V_93 &= ~ V_13 ;
F_4 ( V_2 -> V_93 ) ;
F_8 ( V_17 ) ;
return 0 ;
}
static int F_78 ( struct V_14 * V_15 , int V_165 )
{
struct V_1 * V_2 = V_15 -> V_16 ;
unsigned long V_17 ;
if ( F_1 ( V_2 , V_15 -> V_3 , L_32 ) )
return - V_144 ;
F_6 ( V_17 ) ;
if ( V_165 == - 1 )
V_20 . V_101 = V_166 | V_102 ;
else
V_20 . V_101 = V_102 ;
F_7 () ;
F_8 ( V_17 ) ;
return 0 ;
}
static int F_79 ( struct V_14 * V_15 ,
struct V_167 * V_34 )
{
struct V_1 * V_2 = V_15 -> V_16 ;
struct V_33 V_168 ;
unsigned long V_17 ;
F_6 ( V_17 ) ;
V_168 = V_2 -> V_34 ;
F_8 ( V_17 ) ;
V_34 -> V_74 = V_168 . V_74 ;
V_34 -> V_72 = V_168 . V_72 ;
V_34 -> V_169 = V_168 . V_169 ;
V_34 -> V_73 = V_168 . V_73 ;
V_34 -> V_41 = V_168 . V_41 ;
V_34 -> V_60 = V_168 . V_60 ;
V_34 -> V_47 = V_168 . V_47 ;
V_34 -> V_48 = V_168 . V_48 ;
V_34 -> V_46 = V_168 . V_46 ;
V_34 -> V_45 = V_168 . V_45 ;
V_34 -> V_170 = V_168 . V_170 ;
return 0 ;
}
static int F_80 ( struct V_14 * V_15 ,
unsigned int V_171 , unsigned long V_172 )
{
struct V_1 * V_2 = V_15 -> V_16 ;
struct V_33 V_173 , V_168 ;
void T_3 * V_174 = ( void T_3 * ) V_172 ;
unsigned long V_17 ;
F_81 ( V_175 ) ;
int V_132 ;
if ( F_1 ( V_2 , V_15 -> V_3 , L_31 ) )
return - V_156 ;
if ( ( V_171 != V_176 ) && ( V_171 != V_177 ) &&
( V_171 != V_178 ) && ( V_171 != V_179 ) &&
( V_171 != V_180 ) && ( V_171 != V_181 ) ) {
if ( F_76 ( V_15 ) )
return - V_157 ;
}
switch ( V_171 ) {
case V_176 :
return F_68 ( V_15 , V_2 , V_174 ) ;
case V_177 :
return F_72 ( V_15 , V_2 , V_174 ) ;
case V_178 :
return 0 ;
case V_182 :
return F_74 ( V_2 , V_174 ) ;
case V_179 :
if ( F_71 ( V_174 ,
V_2 , sizeof( struct V_1 ) ) )
return - V_140 ;
return 0 ;
case V_180 :
F_6 ( V_17 ) ;
V_173 = V_2 -> V_34 ;
F_8 ( V_17 ) ;
while ( 1 ) {
F_82 ( & V_2 -> V_53 . V_75 ,
& V_175 , V_183 ) ;
F_6 ( V_17 ) ;
V_168 = V_2 -> V_34 ;
F_8 ( V_17 ) ;
if ( V_168 . V_169 == V_173 . V_169 && V_168 . V_72 == V_173 . V_72 &&
V_168 . V_73 == V_173 . V_73 && V_168 . V_74 == V_173 . V_74 ) {
V_132 = - V_157 ;
break;
}
if ( ( ( V_172 & V_184 ) && ( V_168 . V_169 != V_173 . V_169 ) ) ||
( ( V_172 & V_161 ) && ( V_168 . V_72 != V_173 . V_72 ) ) ||
( ( V_172 & V_185 ) && ( V_168 . V_73 != V_173 . V_73 ) ) ||
( ( V_172 & V_162 ) && ( V_168 . V_74 != V_173 . V_74 ) ) ) {
V_132 = 0 ;
break;
}
F_83 () ;
if ( F_84 ( V_186 ) ) {
V_132 = - V_187 ;
break;
}
V_173 = V_168 ;
}
F_85 ( & V_2 -> V_53 . V_75 , & V_175 ) ;
return V_132 ;
case V_188 :
case V_189 :
F_3 ( L_33 ) ;
return 0 ;
default:
return - V_190 ;
}
return 0 ;
}
static void F_86 ( struct V_14 * V_15 , struct V_103 * V_104 )
{
struct V_1 * V_2 = V_15 -> V_16 ;
unsigned long V_17 ;
unsigned int V_108 = V_15 -> V_110 . V_111 ;
F_36 ( V_15 , V_2 , V_104 ) ;
if ( ( V_104 -> V_111 & V_120 ) && ! ( V_108 & V_120 ) ) {
V_2 -> V_93 &= ~ ( V_13 | V_12 ) ;
F_6 ( V_17 ) ;
F_4 ( V_2 -> V_93 ) ;
F_8 ( V_17 ) ;
}
if ( ! ( V_104 -> V_111 & V_120 ) && ( V_108 & V_120 ) ) {
V_2 -> V_93 |= V_13 ;
if ( ! F_65 ( V_15 ) || ! F_87 ( V_15 ) )
V_2 -> V_93 |= V_12 ;
F_6 ( V_17 ) ;
F_4 ( V_2 -> V_93 ) ;
F_8 ( V_17 ) ;
}
if ( ( V_104 -> V_111 & V_125 ) && ! F_65 ( V_15 ) ) {
V_15 -> V_62 = 0 ;
F_9 ( V_15 ) ;
}
#if 0
if (!(old_termios->c_cflag & CLOCAL) && C_CLOCAL(tty))
wake_up_interruptible(&info->open_wait);
#endif
}
static void F_88 ( struct V_14 * V_15 , struct V_191 * V_192 )
{
struct V_1 * V_100 = V_15 -> V_16 ;
struct V_65 * V_66 = & V_100 -> V_53 ;
if ( F_1 ( V_100 , V_15 -> V_3 , L_34 ) )
return;
if ( F_89 ( V_66 , V_15 , V_192 ) == 0 )
return;
V_100 -> V_51 &= ~ V_36 ;
if ( F_29 ( V_66 ) ) {
V_20 . V_21 = V_37 ;
F_7 () ;
V_20 . V_23 = V_37 ;
F_7 () ;
F_90 ( V_15 , V_100 -> V_121 ) ;
}
F_38 ( V_15 , V_100 ) ;
F_58 ( V_15 ) ;
F_91 ( V_15 ) ;
V_66 -> V_15 = NULL ;
F_92 ( V_66 , V_15 ) ;
}
static void F_90 ( struct V_14 * V_15 , int V_121 )
{
struct V_1 * V_2 = V_15 -> V_16 ;
unsigned long V_193 , V_194 ;
int V_195 ;
if ( F_1 ( V_2 , V_15 -> V_3 , L_35 ) )
return;
if ( V_2 -> V_122 == 0 )
return;
V_193 = V_196 ;
V_194 = ( V_2 -> V_121 - V_123 / 50 ) / V_2 -> V_122 ;
V_194 = V_194 / 5 ;
if ( V_194 == 0 )
V_194 = 1 ;
if ( V_121 )
V_194 = F_93 (unsigned long, char_time, timeout) ;
if ( ! V_121 || V_121 > 2 * V_2 -> V_121 )
V_121 = 2 * V_2 -> V_121 ;
#ifdef F_94
F_3 ( L_36 , V_121 , V_194 ) ;
F_3 ( L_37 , V_196 ) ;
#endif
while( ! ( ( V_195 = V_20 . V_30 ) & V_153 ) ) {
#ifdef F_94
F_3 ( L_38 , V_195 , V_196 ) ;
#endif
F_95 ( F_96 ( V_194 ) ) ;
if ( F_84 ( V_186 ) )
break;
if ( V_121 && F_97 ( V_196 , V_193 + V_121 ) )
break;
}
F_98 ( V_197 ) ;
#ifdef F_94
F_3 ( L_39 , V_195 , V_196 ) ;
#endif
}
static void F_99 ( struct V_14 * V_15 )
{
struct V_1 * V_2 = V_15 -> V_16 ;
if ( F_1 ( V_2 , V_15 -> V_3 , L_40 ) )
return;
F_58 ( V_15 ) ;
F_38 ( V_15 , V_2 ) ;
V_2 -> V_53 . V_130 = 0 ;
F_100 ( & V_2 -> V_53 , 0 ) ;
V_2 -> V_53 . V_15 = NULL ;
F_19 ( & V_2 -> V_53 . V_77 ) ;
}
static int F_101 ( struct V_14 * V_15 , struct V_191 * V_192 )
{
struct V_1 * V_2 = V_198 + V_15 -> V_137 ;
struct V_65 * V_66 = & V_2 -> V_53 ;
int V_86 ;
V_66 -> V_130 ++ ;
V_66 -> V_15 = V_15 ;
V_15 -> V_16 = V_2 ;
V_15 -> V_66 = V_66 ;
if ( F_1 ( V_2 , V_15 -> V_3 , L_41 ) )
return - V_156 ;
V_66 -> V_149 = ( V_66 -> V_17 & V_150 ) ? 1 : 0 ;
V_86 = F_27 ( V_15 , V_2 ) ;
if ( V_86 ) {
return V_86 ;
}
return F_102 ( V_66 , V_15 , V_192 ) ;
}
static inline void F_103 ( struct V_199 * V_200 , int line ,
struct V_1 * V_100 )
{
char V_201 [ 30 ] , V_155 , V_29 ;
unsigned long V_17 ;
F_104 ( V_200 , L_42 , line ) ;
F_6 ( V_17 ) ;
V_29 = V_10 . V_11 ;
V_155 = F_29 ( & V_100 -> V_53 ) ? V_100 -> V_93 : V_29 ;
F_8 ( V_17 ) ;
V_201 [ 0 ] = 0 ;
V_201 [ 1 ] = 0 ;
if( ! ( V_155 & V_12 ) )
strcat ( V_201 , L_43 ) ;
if( ! ( V_29 & V_68 ) )
strcat ( V_201 , L_44 ) ;
if( ! ( V_155 & V_13 ) )
strcat ( V_201 , L_45 ) ;
if( ! ( V_29 & V_69 ) )
strcat ( V_201 , L_46 ) ;
if( ! ( V_29 & V_67 ) )
strcat ( V_201 , L_47 ) ;
if ( V_100 -> V_105 )
F_104 ( V_200 , L_48 , V_100 -> V_106 / V_100 -> V_105 ) ;
F_104 ( V_200 , L_49 , V_100 -> V_34 . V_60 , V_100 -> V_34 . V_41 ) ;
if ( V_100 -> V_34 . V_47 )
F_104 ( V_200 , L_50 , V_100 -> V_34 . V_47 ) ;
if ( V_100 -> V_34 . V_46 )
F_104 ( V_200 , L_51 , V_100 -> V_34 . V_46 ) ;
if ( V_100 -> V_34 . V_45 )
F_104 ( V_200 , L_52 , V_100 -> V_34 . V_45 ) ;
if ( V_100 -> V_34 . V_48 )
F_104 ( V_200 , L_53 , V_100 -> V_34 . V_48 ) ;
F_104 ( V_200 , L_54 , V_201 + 1 ) ;
}
static int F_105 ( struct V_199 * V_200 , void * V_202 )
{
F_104 ( V_200 , L_55 , V_203 ) ;
F_103 ( V_200 , 0 , & V_198 [ 0 ] ) ;
return 0 ;
}
static int F_106 ( struct V_204 * V_204 , struct V_191 * V_191 )
{
return F_107 ( V_191 , F_105 , NULL ) ;
}
static void F_108 ( void )
{
F_3 ( V_205 L_56 , V_206 , V_203 ) ;
}
static int F_109 ( struct V_65 * V_66 )
{
return ! ( V_10 . V_11 & V_67 ) ;
}
static void F_110 ( struct V_65 * V_66 , int raise )
{
struct V_1 * V_2 = F_111 ( V_66 , struct V_1 ,
V_53 ) ;
unsigned long V_17 ;
if ( raise )
V_2 -> V_93 |= V_13 | V_12 ;
else
V_2 -> V_93 &= ~ ( V_13 | V_12 ) ;
F_6 ( V_17 ) ;
F_4 ( V_2 -> V_93 ) ;
F_8 ( V_17 ) ;
}
static int T_4 F_112 ( struct V_207 * V_208 )
{
unsigned long V_17 ;
struct V_1 * V_100 ;
int error ;
V_209 = F_113 ( V_210 ) ;
if ( ! V_209 )
return - V_89 ;
F_108 () ;
V_209 -> V_211 = L_57 ;
V_209 -> V_3 = L_58 ;
V_209 -> V_212 = V_213 ;
V_209 -> V_214 = 64 ;
V_209 -> type = V_215 ;
V_209 -> V_216 = V_217 ;
V_209 -> V_218 = V_219 ;
V_209 -> V_218 . V_111 =
V_220 | V_221 | V_127 | V_222 | V_126 ;
V_209 -> V_17 = V_223 ;
F_114 ( V_209 , & V_224 ) ;
V_100 = V_198 ;
V_100 -> V_66 = ( int ) & V_20 . V_30 ;
V_100 -> V_119 = 0 ;
V_100 -> V_34 . V_74 = V_100 -> V_34 . V_72 =
V_100 -> V_34 . V_169 = V_100 -> V_34 . V_73 = 0 ;
V_100 -> V_34 . V_41 = V_100 -> V_34 . V_60 = 0 ;
V_100 -> V_34 . V_47 = V_100 -> V_34 . V_46 = 0 ;
V_100 -> V_34 . V_48 = V_100 -> V_34 . V_45 = 0 ;
F_115 ( & V_100 -> V_53 ) ;
V_100 -> V_53 . V_225 = & V_226 ;
F_116 ( & V_100 -> V_53 , V_209 , 0 ) ;
error = F_117 ( V_209 ) ;
if ( error )
goto V_227;
F_3 ( V_205 L_59 ) ;
V_100 -> V_106 = V_228 ;
V_100 -> V_122 = 1 ;
error = F_31 ( V_229 , F_26 , 0 , L_60 , V_100 ) ;
if ( error )
goto V_230;
error = F_31 ( V_231 , F_25 , 0 ,
L_61 , V_100 ) ;
if ( error )
goto V_232;
F_6 ( V_17 ) ;
V_20 . V_21 = V_37 | V_22 ;
F_7 () ;
V_20 . V_23 = V_37 | V_22 ;
F_7 () ;
F_8 ( V_17 ) ;
V_10 . V_233 |= ( V_13 | V_12 ) ;
V_10 . V_233 &= ~ ( V_67 | V_68 | V_69 ) ;
F_118 ( V_208 , V_100 ) ;
return 0 ;
V_232:
F_39 ( V_229 , V_100 ) ;
V_230:
F_119 ( V_209 ) ;
V_227:
F_120 ( & V_100 -> V_53 ) ;
F_121 ( V_209 ) ;
return error ;
}
static int T_5 F_122 ( struct V_207 * V_208 )
{
int error ;
struct V_1 * V_100 = F_123 ( V_208 ) ;
error = F_119 ( V_209 ) ;
if ( error )
F_3 ( L_62 ,
error ) ;
F_121 ( V_209 ) ;
F_120 ( & V_100 -> V_53 ) ;
F_39 ( V_229 , V_100 ) ;
F_39 ( V_231 , V_100 ) ;
return error ;
}
static void F_124 ( char V_131 )
{
V_20 . V_59 = ( unsigned char ) V_131 | 0x100 ;
while ( ! ( V_20 . V_30 & 0x2000 ) )
F_125 () ;
}
static void F_126 ( struct V_234 * V_235 , const char * V_236 ,
unsigned V_130 )
{
unsigned short V_21 = V_20 . V_133 ;
V_20 . V_21 = V_22 ;
while ( V_130 -- ) {
if ( * V_236 == '\n' )
F_124 ( '\r' ) ;
F_124 ( * V_236 ++ ) ;
}
V_20 . V_21 = V_28 | ( V_21 & V_22 ) ;
}
static struct V_237 * F_127 ( struct V_234 * V_131 , int * V_137 )
{
* V_137 = 0 ;
return V_209 ;
}
static int T_4 F_128 ( void )
{
if ( ! V_238 )
return - V_156 ;
F_129 ( & V_239 ) ;
return 0 ;
}
