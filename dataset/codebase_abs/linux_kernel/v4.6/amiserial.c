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
if ( F_37 ( V_15 ) )
V_2 -> V_95 &= ~ ( V_13 | V_12 ) ;
F_4 ( V_2 -> V_95 ) ;
F_31 ( V_94 , & V_15 -> V_17 ) ;
V_2 -> V_53 . V_17 &= ~ V_91 ;
F_8 ( V_17 ) ;
}
static void F_34 ( struct V_14 * V_15 , struct V_1 * V_2 ,
struct V_105 * V_106 )
{
struct V_65 * V_66 = & V_2 -> V_53 ;
int V_107 = 0 , V_108 , V_109 ;
unsigned V_110 , V_111 = 0 ;
int V_9 ;
unsigned long V_17 ;
V_110 = V_15 -> V_112 . V_113 ;
V_111 = 3 ; V_9 = 10 ;
if ( V_110 & V_114 ) {
V_111 |= 0x04 ;
V_9 ++ ;
}
if ( V_110 & V_115 ) {
V_111 |= V_116 ;
V_9 ++ ;
}
if ( ! ( V_110 & V_117 ) )
V_111 |= V_118 ;
#ifdef F_38
if ( V_110 & F_38 )
V_111 |= V_119 ;
#endif
V_109 = F_39 ( V_15 ) ;
if ( ! V_109 )
V_109 = 9600 ;
V_108 = V_2 -> V_108 ;
if ( V_109 == 38400 && ( V_66 -> V_17 & V_96 ) == V_120 )
V_107 = V_2 -> V_121 ;
else {
if ( V_109 == 134 )
V_107 = ( 2 * V_108 / 269 ) ;
else if ( V_109 )
V_107 = V_108 / V_109 ;
}
if ( ! V_107 && V_106 ) {
V_15 -> V_112 . V_113 &= ~ V_122 ;
V_15 -> V_112 . V_113 |= ( V_106 -> V_113 & V_122 ) ;
V_109 = F_39 ( V_15 ) ;
if ( ! V_109 )
V_109 = 9600 ;
if ( V_109 == 38400 &&
( V_66 -> V_17 & V_96 ) == V_120 )
V_107 = V_2 -> V_121 ;
else {
if ( V_109 == 134 )
V_107 = ( 2 * V_108 / 269 ) ;
else if ( V_109 )
V_107 = V_108 / V_109 ;
}
}
if ( ! V_107 )
V_107 = V_108 / 9600 ;
V_2 -> V_107 = V_107 ;
V_2 -> V_123 = ( ( V_2 -> V_124 * V_125 * V_9 * V_107 ) / V_108 ) ;
V_2 -> V_123 += V_125 / 50 ;
V_2 -> V_18 &= ~ V_82 ;
if ( V_66 -> V_17 & V_126 )
V_2 -> V_18 |= V_82 ;
if ( V_110 & V_127 ) {
V_66 -> V_17 |= V_128 ;
V_2 -> V_18 |= V_82 ;
} else
V_66 -> V_17 &= ~ V_128 ;
if ( V_110 & V_129 )
V_66 -> V_17 &= ~ V_76 ;
else {
V_66 -> V_17 |= V_76 ;
V_2 -> V_18 |= V_82 ;
}
V_2 -> V_51 = V_40 | V_36 ;
if ( F_40 ( V_15 ) )
V_2 -> V_51 |= V_44 | V_43 ;
if ( F_41 ( V_15 ) || F_42 ( V_15 ) )
V_2 -> V_51 |= V_38 ;
V_2 -> V_49 = 0 ;
if ( F_43 ( V_15 ) )
V_2 -> V_49 |= V_43 | V_44 ;
if ( F_44 ( V_15 ) ) {
V_2 -> V_49 |= V_38 ;
if ( F_43 ( V_15 ) )
V_2 -> V_49 |= V_40 ;
}
if ( ( V_110 & V_130 ) == 0 )
V_2 -> V_49 |= V_36 ;
F_6 ( V_17 ) ;
{
short V_131 ;
V_131 = V_107 - 1 ;
if( V_111 & V_116 )
V_131 |= ( V_132 ) ;
V_20 . V_131 = V_131 ;
F_7 () ;
}
F_8 ( V_17 ) ;
}
static int F_45 ( struct V_14 * V_15 , unsigned char V_31 )
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
V_2 -> V_24 . V_27 [ V_2 -> V_24 . V_25 ++ ] = V_31 ;
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
static int F_48 ( struct V_14 * V_15 , const unsigned char * V_27 , int V_133 )
{
int V_134 , V_135 = 0 ;
struct V_1 * V_2 = V_15 -> V_16 ;
unsigned long V_17 ;
if ( F_1 ( V_2 , V_15 -> V_3 , L_22 ) )
return 0 ;
if ( ! V_2 -> V_24 . V_27 )
return 0 ;
F_6 ( V_17 ) ;
while ( 1 ) {
V_134 = F_49 ( V_2 -> V_24 . V_25 ,
V_2 -> V_24 . V_26 ,
V_63 ) ;
if ( V_133 < V_134 )
V_134 = V_133 ;
if ( V_134 <= 0 ) {
break;
}
memcpy ( V_2 -> V_24 . V_27 + V_2 -> V_24 . V_25 , V_27 , V_134 ) ;
V_2 -> V_24 . V_25 = ( ( V_2 -> V_24 . V_25 + V_134 ) &
( V_63 - 1 ) ) ;
V_27 += V_134 ;
V_133 -= V_134 ;
V_135 += V_134 ;
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
return V_135 ;
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
static void F_54 ( struct V_14 * V_15 , char V_31 )
{
struct V_1 * V_2 = V_15 -> V_16 ;
unsigned long V_17 ;
if ( F_1 ( V_2 , V_15 -> V_3 , L_26 ) )
return;
V_2 -> V_58 = V_31 ;
if ( V_31 ) {
F_6 ( V_17 ) ;
if( ! ( V_20 . V_136 & V_22 ) ) {
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
F_3 ( L_27 , F_57 ( V_15 ) ) ;
#endif
if ( F_1 ( V_2 , V_15 -> V_3 , L_28 ) )
return;
if ( F_58 ( V_15 ) )
F_54 ( V_15 , F_59 ( V_15 ) ) ;
if ( F_60 ( V_15 ) )
V_2 -> V_95 &= ~ V_12 ;
F_6 ( V_17 ) ;
F_4 ( V_2 -> V_95 ) ;
F_8 ( V_17 ) ;
}
static void F_61 ( struct V_14 * V_15 )
{
struct V_1 * V_2 = V_15 -> V_16 ;
unsigned long V_17 ;
#ifdef F_56
F_3 ( L_29 , F_57 ( V_15 ) ) ;
#endif
if ( F_1 ( V_2 , V_15 -> V_3 , L_30 ) )
return;
if ( F_58 ( V_15 ) ) {
if ( V_2 -> V_58 )
V_2 -> V_58 = 0 ;
else
F_54 ( V_15 , F_62 ( V_15 ) ) ;
}
if ( F_60 ( V_15 ) )
V_2 -> V_95 |= V_12 ;
F_6 ( V_17 ) ;
F_4 ( V_2 -> V_95 ) ;
F_8 ( V_17 ) ;
}
static int F_63 ( struct V_14 * V_15 , struct V_1 * V_102 ,
struct V_137 T_3 * V_138 )
{
struct V_137 V_139 ;
if ( ! V_138 )
return - V_140 ;
memset ( & V_139 , 0 , sizeof( V_139 ) ) ;
F_64 ( V_15 ) ;
V_139 . line = V_15 -> V_141 ;
V_139 . V_66 = V_102 -> V_66 ;
V_139 . V_17 = V_102 -> V_53 . V_17 ;
V_139 . V_124 = V_102 -> V_124 ;
V_139 . V_108 = V_102 -> V_108 ;
V_139 . V_142 = V_102 -> V_53 . V_142 ;
V_139 . V_143 = V_102 -> V_53 . V_143 ;
V_139 . V_121 = V_102 -> V_121 ;
F_65 ( V_15 ) ;
if ( F_66 ( V_138 , & V_139 , sizeof( * V_138 ) ) )
return - V_140 ;
return 0 ;
}
static int F_67 ( struct V_14 * V_15 , struct V_1 * V_102 ,
struct V_137 T_3 * V_144 )
{
struct V_65 * V_66 = & V_102 -> V_53 ;
struct V_137 V_145 ;
bool V_146 ;
int V_87 = 0 ;
if ( F_68 ( & V_145 , V_144 , sizeof( V_145 ) ) )
return - V_140 ;
F_64 ( V_15 ) ;
V_146 = ( ( V_145 . V_17 ^ V_66 -> V_17 ) & V_96 ) ||
V_145 . V_121 != V_102 -> V_121 ;
if ( V_145 . V_80 || V_145 . V_66 != V_102 -> V_66 ||
V_145 . V_124 != V_102 -> V_124 ) {
F_65 ( V_15 ) ;
return - V_147 ;
}
if ( ! F_30 () ) {
if ( ( V_145 . V_108 != V_102 -> V_108 ) ||
( V_145 . V_142 != V_66 -> V_142 ) ||
( V_145 . V_124 != V_102 -> V_124 ) ||
( ( V_145 . V_17 & ~ V_148 ) !=
( V_66 -> V_17 & ~ V_148 ) ) ) {
F_65 ( V_15 ) ;
return - V_149 ;
}
V_66 -> V_17 = ( ( V_66 -> V_17 & ~ V_148 ) |
( V_145 . V_17 & V_148 ) ) ;
V_102 -> V_121 = V_145 . V_121 ;
goto V_150;
}
if ( V_145 . V_108 < 9600 ) {
F_65 ( V_15 ) ;
return - V_147 ;
}
V_102 -> V_108 = V_145 . V_108 ;
V_66 -> V_17 = ( ( V_66 -> V_17 & ~ V_151 ) |
( V_145 . V_17 & V_151 ) ) ;
V_102 -> V_121 = V_145 . V_121 ;
V_66 -> V_142 = V_145 . V_142 * V_125 / 100 ;
V_66 -> V_143 = V_145 . V_143 * V_125 / 100 ;
V_66 -> V_152 = ( V_66 -> V_17 & V_153 ) ? 1 : 0 ;
V_150:
if ( V_66 -> V_17 & V_91 ) {
if ( V_146 ) {
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
F_65 ( V_15 ) ;
return V_87 ;
}
static int F_69 ( struct V_1 * V_2 , unsigned int T_3 * V_154 )
{
unsigned char V_29 ;
unsigned int V_155 ;
unsigned long V_17 ;
F_6 ( V_17 ) ;
V_29 = V_20 . V_30 ;
F_7 () ;
F_8 ( V_17 ) ;
V_155 = ( ( V_29 & V_156 ) ? V_157 : 0 ) ;
if ( F_66 ( V_154 , & V_155 , sizeof( int ) ) )
return - V_140 ;
return 0 ;
}
static int F_70 ( struct V_14 * V_15 )
{
struct V_1 * V_2 = V_15 -> V_16 ;
unsigned char V_158 , V_29 ;
unsigned long V_17 ;
if ( F_1 ( V_2 , V_15 -> V_3 , L_31 ) )
return - V_159 ;
if ( V_15 -> V_17 & ( 1 << V_94 ) )
return - V_160 ;
V_158 = V_2 -> V_95 ;
F_6 ( V_17 ) ;
V_29 = V_10 . V_11 ;
F_8 ( V_17 ) ;
return ( ( V_158 & V_12 ) ? V_161 : 0 )
| ( ( V_158 & V_13 ) ? V_162 : 0 )
| ( ! ( V_29 & V_67 ) ? V_163 : 0 )
| ( ! ( V_29 & V_69 ) ? V_164 : 0 )
| ( ! ( V_29 & V_68 ) ? V_165 : 0 ) ;
}
static int F_71 ( struct V_14 * V_15 , unsigned int V_166 ,
unsigned int V_167 )
{
struct V_1 * V_2 = V_15 -> V_16 ;
unsigned long V_17 ;
if ( F_1 ( V_2 , V_15 -> V_3 , L_31 ) )
return - V_159 ;
if ( V_15 -> V_17 & ( 1 << V_94 ) )
return - V_160 ;
F_6 ( V_17 ) ;
if ( V_166 & V_161 )
V_2 -> V_95 |= V_12 ;
if ( V_166 & V_162 )
V_2 -> V_95 |= V_13 ;
if ( V_167 & V_161 )
V_2 -> V_95 &= ~ V_12 ;
if ( V_167 & V_162 )
V_2 -> V_95 &= ~ V_13 ;
F_4 ( V_2 -> V_95 ) ;
F_8 ( V_17 ) ;
return 0 ;
}
static int F_72 ( struct V_14 * V_15 , int V_168 )
{
struct V_1 * V_2 = V_15 -> V_16 ;
unsigned long V_17 ;
if ( F_1 ( V_2 , V_15 -> V_3 , L_32 ) )
return - V_147 ;
F_6 ( V_17 ) ;
if ( V_168 == - 1 )
V_20 . V_103 = V_169 | V_104 ;
else
V_20 . V_103 = V_104 ;
F_7 () ;
F_8 ( V_17 ) ;
return 0 ;
}
static int F_73 ( struct V_14 * V_15 ,
struct V_170 * V_34 )
{
struct V_1 * V_2 = V_15 -> V_16 ;
struct V_33 V_171 ;
unsigned long V_17 ;
F_6 ( V_17 ) ;
V_171 = V_2 -> V_34 ;
F_8 ( V_17 ) ;
V_34 -> V_74 = V_171 . V_74 ;
V_34 -> V_72 = V_171 . V_72 ;
V_34 -> V_172 = V_171 . V_172 ;
V_34 -> V_73 = V_171 . V_73 ;
V_34 -> V_41 = V_171 . V_41 ;
V_34 -> V_60 = V_171 . V_60 ;
V_34 -> V_47 = V_171 . V_47 ;
V_34 -> V_48 = V_171 . V_48 ;
V_34 -> V_46 = V_171 . V_46 ;
V_34 -> V_45 = V_171 . V_45 ;
V_34 -> V_173 = V_171 . V_173 ;
return 0 ;
}
static int F_74 ( struct V_14 * V_15 ,
unsigned int V_174 , unsigned long V_175 )
{
struct V_1 * V_2 = V_15 -> V_16 ;
struct V_33 V_176 , V_171 ;
void T_3 * V_177 = ( void T_3 * ) V_175 ;
unsigned long V_17 ;
F_75 ( V_178 ) ;
int V_135 ;
if ( F_1 ( V_2 , V_15 -> V_3 , L_31 ) )
return - V_159 ;
if ( ( V_174 != V_179 ) && ( V_174 != V_180 ) &&
( V_174 != V_181 ) && ( V_174 != V_182 ) &&
( V_174 != V_183 ) && ( V_174 != V_184 ) ) {
if ( V_15 -> V_17 & ( 1 << V_94 ) )
return - V_160 ;
}
switch ( V_174 ) {
case V_179 :
return F_63 ( V_15 , V_2 , V_177 ) ;
case V_180 :
return F_67 ( V_15 , V_2 , V_177 ) ;
case V_181 :
return 0 ;
case V_185 :
return F_69 ( V_2 , V_177 ) ;
case V_182 :
if ( F_66 ( V_177 ,
V_2 , sizeof( struct V_1 ) ) )
return - V_140 ;
return 0 ;
case V_183 :
F_6 ( V_17 ) ;
V_176 = V_2 -> V_34 ;
F_8 ( V_17 ) ;
while ( 1 ) {
F_76 ( & V_2 -> V_53 . V_75 ,
& V_178 , V_186 ) ;
F_6 ( V_17 ) ;
V_171 = V_2 -> V_34 ;
F_8 ( V_17 ) ;
if ( V_171 . V_172 == V_176 . V_172 && V_171 . V_72 == V_176 . V_72 &&
V_171 . V_73 == V_176 . V_73 && V_171 . V_74 == V_176 . V_74 ) {
V_135 = - V_160 ;
break;
}
if ( ( ( V_175 & V_187 ) && ( V_171 . V_172 != V_176 . V_172 ) ) ||
( ( V_175 & V_164 ) && ( V_171 . V_72 != V_176 . V_72 ) ) ||
( ( V_175 & V_188 ) && ( V_171 . V_73 != V_176 . V_73 ) ) ||
( ( V_175 & V_165 ) && ( V_171 . V_74 != V_176 . V_74 ) ) ) {
V_135 = 0 ;
break;
}
F_77 () ;
if ( F_78 ( V_189 ) ) {
V_135 = - V_190 ;
break;
}
V_176 = V_171 ;
}
F_79 ( & V_2 -> V_53 . V_75 , & V_178 ) ;
return V_135 ;
case V_191 :
case V_192 :
F_3 ( L_33 ) ;
return 0 ;
default:
return - V_193 ;
}
return 0 ;
}
static void F_80 ( struct V_14 * V_15 , struct V_105 * V_106 )
{
struct V_1 * V_2 = V_15 -> V_16 ;
unsigned long V_17 ;
unsigned int V_110 = V_15 -> V_112 . V_113 ;
F_34 ( V_15 , V_2 , V_106 ) ;
if ( ( V_106 -> V_113 & V_122 ) && ! ( V_110 & V_122 ) ) {
V_2 -> V_95 &= ~ ( V_13 | V_12 ) ;
F_6 ( V_17 ) ;
F_4 ( V_2 -> V_95 ) ;
F_8 ( V_17 ) ;
}
if ( ! ( V_106 -> V_113 & V_122 ) && ( V_110 & V_122 ) ) {
V_2 -> V_95 |= V_13 ;
if ( ! F_60 ( V_15 ) || ! F_81 ( V_194 , & V_15 -> V_17 ) )
V_2 -> V_95 |= V_12 ;
F_6 ( V_17 ) ;
F_4 ( V_2 -> V_95 ) ;
F_8 ( V_17 ) ;
}
if ( ( V_106 -> V_113 & V_127 ) && ! F_60 ( V_15 ) ) {
V_15 -> V_62 = 0 ;
F_9 ( V_15 ) ;
}
#if 0
if (!(old_termios->c_cflag & CLOCAL) && C_CLOCAL(tty))
wake_up_interruptible(&info->open_wait);
#endif
}
static void F_82 ( struct V_14 * V_15 , struct V_195 * V_196 )
{
struct V_1 * V_102 = V_15 -> V_16 ;
struct V_65 * V_66 = & V_102 -> V_53 ;
if ( F_1 ( V_102 , V_15 -> V_3 , L_34 ) )
return;
if ( F_83 ( V_66 , V_15 , V_196 ) == 0 )
return;
V_102 -> V_51 &= ~ V_36 ;
if ( V_66 -> V_17 & V_91 ) {
V_20 . V_21 = V_37 ;
F_7 () ;
V_20 . V_23 = V_37 ;
F_7 () ;
F_84 ( V_15 , V_102 -> V_123 ) ;
}
F_35 ( V_15 , V_102 ) ;
F_53 ( V_15 ) ;
F_85 ( V_15 ) ;
V_66 -> V_15 = NULL ;
F_86 ( V_66 , V_15 ) ;
}
static void F_84 ( struct V_14 * V_15 , int V_123 )
{
struct V_1 * V_2 = V_15 -> V_16 ;
unsigned long V_197 , V_198 ;
int V_199 ;
if ( F_1 ( V_2 , V_15 -> V_3 , L_35 ) )
return;
if ( V_2 -> V_124 == 0 )
return;
V_197 = V_200 ;
V_198 = ( V_2 -> V_123 - V_125 / 50 ) / V_2 -> V_124 ;
V_198 = V_198 / 5 ;
if ( V_198 == 0 )
V_198 = 1 ;
if ( V_123 )
V_198 = F_87 (unsigned long, char_time, timeout) ;
if ( ! V_123 || V_123 > 2 * V_2 -> V_123 )
V_123 = 2 * V_2 -> V_123 ;
#ifdef F_88
F_3 ( L_36 , V_123 , V_198 ) ;
F_3 ( L_37 , V_200 ) ;
#endif
while( ! ( ( V_199 = V_20 . V_30 ) & V_156 ) ) {
#ifdef F_88
F_3 ( L_38 , V_199 , V_200 ) ;
#endif
F_89 ( F_90 ( V_198 ) ) ;
if ( F_78 ( V_189 ) )
break;
if ( V_123 && F_91 ( V_200 , V_197 + V_123 ) )
break;
}
F_92 ( V_201 ) ;
#ifdef F_88
F_3 ( L_39 , V_199 , V_200 ) ;
#endif
}
static void F_93 ( struct V_14 * V_15 )
{
struct V_1 * V_2 = V_15 -> V_16 ;
if ( F_1 ( V_2 , V_15 -> V_3 , L_40 ) )
return;
F_53 ( V_15 ) ;
F_35 ( V_15 , V_2 ) ;
V_2 -> V_53 . V_133 = 0 ;
V_2 -> V_53 . V_17 &= ~ V_202 ;
V_2 -> V_53 . V_15 = NULL ;
F_19 ( & V_2 -> V_53 . V_78 ) ;
}
static int F_94 ( struct V_14 * V_15 , struct V_195 * V_196 )
{
struct V_1 * V_2 = V_203 + V_15 -> V_141 ;
struct V_65 * V_66 = & V_2 -> V_53 ;
int V_87 ;
V_66 -> V_133 ++ ;
V_66 -> V_15 = V_15 ;
V_15 -> V_16 = V_2 ;
V_15 -> V_66 = V_66 ;
if ( F_1 ( V_2 , V_15 -> V_3 , L_41 ) )
return - V_159 ;
V_66 -> V_152 = ( V_66 -> V_17 & V_153 ) ? 1 : 0 ;
V_87 = F_26 ( V_15 , V_2 ) ;
if ( V_87 ) {
return V_87 ;
}
return F_95 ( V_66 , V_15 , V_196 ) ;
}
static inline void F_96 ( struct V_204 * V_205 , int line ,
struct V_1 * V_102 )
{
char V_206 [ 30 ] , V_158 , V_29 ;
unsigned long V_17 ;
F_97 ( V_205 , L_42 , line ) ;
F_6 ( V_17 ) ;
V_29 = V_10 . V_11 ;
V_158 = ( V_102 -> V_53 . V_17 & V_91 ) ? V_102 -> V_95 : V_29 ;
F_8 ( V_17 ) ;
V_206 [ 0 ] = 0 ;
V_206 [ 1 ] = 0 ;
if( ! ( V_158 & V_12 ) )
strcat ( V_206 , L_43 ) ;
if( ! ( V_29 & V_68 ) )
strcat ( V_206 , L_44 ) ;
if( ! ( V_158 & V_13 ) )
strcat ( V_206 , L_45 ) ;
if( ! ( V_29 & V_69 ) )
strcat ( V_206 , L_46 ) ;
if( ! ( V_29 & V_67 ) )
strcat ( V_206 , L_47 ) ;
if ( V_102 -> V_107 )
F_97 ( V_205 , L_48 , V_102 -> V_108 / V_102 -> V_107 ) ;
F_97 ( V_205 , L_49 , V_102 -> V_34 . V_60 , V_102 -> V_34 . V_41 ) ;
if ( V_102 -> V_34 . V_47 )
F_97 ( V_205 , L_50 , V_102 -> V_34 . V_47 ) ;
if ( V_102 -> V_34 . V_46 )
F_97 ( V_205 , L_51 , V_102 -> V_34 . V_46 ) ;
if ( V_102 -> V_34 . V_45 )
F_97 ( V_205 , L_52 , V_102 -> V_34 . V_45 ) ;
if ( V_102 -> V_34 . V_48 )
F_97 ( V_205 , L_53 , V_102 -> V_34 . V_48 ) ;
F_97 ( V_205 , L_54 , V_206 + 1 ) ;
}
static int F_98 ( struct V_204 * V_205 , void * V_207 )
{
F_97 ( V_205 , L_55 , V_208 ) ;
F_96 ( V_205 , 0 , & V_203 [ 0 ] ) ;
return 0 ;
}
static int F_99 ( struct V_209 * V_209 , struct V_195 * V_195 )
{
return F_100 ( V_195 , F_98 , NULL ) ;
}
static void F_101 ( void )
{
F_3 ( V_210 L_56 , V_211 , V_208 ) ;
}
static int F_102 ( struct V_65 * V_66 )
{
return ! ( V_10 . V_11 & V_67 ) ;
}
static void F_103 ( struct V_65 * V_66 , int raise )
{
struct V_1 * V_2 = F_104 ( V_66 , struct V_1 ,
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
static int T_4 F_105 ( struct V_212 * V_213 )
{
unsigned long V_17 ;
struct V_1 * V_102 ;
int error ;
V_214 = F_106 ( V_215 ) ;
if ( ! V_214 )
return - V_90 ;
F_101 () ;
V_214 -> V_216 = L_57 ;
V_214 -> V_3 = L_58 ;
V_214 -> V_217 = V_218 ;
V_214 -> V_219 = 64 ;
V_214 -> type = V_220 ;
V_214 -> V_221 = V_222 ;
V_214 -> V_223 = V_224 ;
V_214 -> V_223 . V_113 =
V_225 | V_226 | V_130 | V_227 | V_129 ;
V_214 -> V_17 = V_228 ;
F_107 ( V_214 , & V_229 ) ;
V_102 = V_203 ;
V_102 -> V_66 = ( int ) & V_20 . V_30 ;
V_102 -> V_121 = 0 ;
V_102 -> V_34 . V_74 = V_102 -> V_34 . V_72 =
V_102 -> V_34 . V_172 = V_102 -> V_34 . V_73 = 0 ;
V_102 -> V_34 . V_41 = V_102 -> V_34 . V_60 = 0 ;
V_102 -> V_34 . V_47 = V_102 -> V_34 . V_46 = 0 ;
V_102 -> V_34 . V_48 = V_102 -> V_34 . V_45 = 0 ;
F_108 ( & V_102 -> V_53 ) ;
V_102 -> V_53 . V_230 = & V_231 ;
F_109 ( & V_102 -> V_53 , V_214 , 0 ) ;
error = F_110 ( V_214 ) ;
if ( error )
goto V_232;
F_3 ( V_210 L_59 ) ;
V_102 -> V_108 = V_233 ;
V_102 -> V_124 = 1 ;
error = F_29 ( V_234 , F_25 , 0 , L_60 , V_102 ) ;
if ( error )
goto V_235;
error = F_29 ( V_236 , F_24 , 0 ,
L_61 , V_102 ) ;
if ( error )
goto V_237;
F_6 ( V_17 ) ;
V_20 . V_21 = V_37 | V_22 ;
F_7 () ;
V_20 . V_23 = V_37 | V_22 ;
F_7 () ;
F_8 ( V_17 ) ;
V_10 . V_238 |= ( V_13 | V_12 ) ;
V_10 . V_238 &= ~ ( V_67 | V_68 | V_69 ) ;
F_111 ( V_213 , V_102 ) ;
return 0 ;
V_237:
F_36 ( V_234 , V_102 ) ;
V_235:
F_112 ( V_214 ) ;
V_232:
F_113 ( & V_102 -> V_53 ) ;
F_114 ( V_214 ) ;
return error ;
}
static int T_5 F_115 ( struct V_212 * V_213 )
{
int error ;
struct V_1 * V_102 = F_116 ( V_213 ) ;
error = F_112 ( V_214 ) ;
if ( error )
F_3 ( L_62 ,
error ) ;
F_114 ( V_214 ) ;
F_113 ( & V_102 -> V_53 ) ;
F_36 ( V_234 , V_102 ) ;
F_36 ( V_236 , V_102 ) ;
return error ;
}
static void F_117 ( char V_134 )
{
V_20 . V_59 = ( unsigned char ) V_134 | 0x100 ;
while ( ! ( V_20 . V_30 & 0x2000 ) )
F_118 () ;
}
static void F_119 ( struct V_239 * V_240 , const char * V_241 ,
unsigned V_133 )
{
unsigned short V_21 = V_20 . V_136 ;
V_20 . V_21 = V_22 ;
while ( V_133 -- ) {
if ( * V_241 == '\n' )
F_117 ( '\r' ) ;
F_117 ( * V_241 ++ ) ;
}
V_20 . V_21 = V_28 | ( V_21 & V_22 ) ;
}
static struct V_242 * F_120 ( struct V_239 * V_134 , int * V_141 )
{
* V_141 = 0 ;
return V_214 ;
}
static int T_4 F_121 ( void )
{
if ( ! V_243 )
return - V_159 ;
F_122 ( & V_244 ) ;
return 0 ;
}
