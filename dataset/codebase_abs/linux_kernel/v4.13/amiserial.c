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
struct V_1 * V_94 ;
if ( ! F_29 ( & V_2 -> V_53 ) )
return;
V_94 = V_2 ;
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
V_20 . V_95 = V_96 ;
F_7 () ;
if ( F_40 ( V_15 ) )
V_2 -> V_93 &= ~ ( V_13 | V_12 ) ;
F_4 ( V_2 -> V_93 ) ;
F_33 ( V_92 , & V_15 -> V_17 ) ;
F_37 ( & V_2 -> V_53 , 0 ) ;
F_8 ( V_17 ) ;
}
static void F_36 ( struct V_14 * V_15 , struct V_1 * V_2 ,
struct V_97 * V_98 )
{
struct V_65 * V_66 = & V_2 -> V_53 ;
int V_99 = 0 , V_100 , V_101 ;
unsigned V_102 , V_103 = 0 ;
int V_9 ;
unsigned long V_17 ;
V_102 = V_15 -> V_104 . V_105 ;
V_103 = 3 ; V_9 = 10 ;
if ( V_102 & V_106 ) {
V_103 |= 0x04 ;
V_9 ++ ;
}
if ( V_102 & V_107 ) {
V_103 |= V_108 ;
V_9 ++ ;
}
if ( ! ( V_102 & V_109 ) )
V_103 |= V_110 ;
#ifdef F_41
if ( V_102 & F_41 )
V_103 |= V_111 ;
#endif
V_101 = F_42 ( V_15 ) ;
if ( ! V_101 )
V_101 = 9600 ;
V_100 = V_2 -> V_100 ;
if ( V_101 == 38400 && ( V_66 -> V_17 & V_112 ) == V_113 )
V_99 = V_2 -> V_114 ;
else {
if ( V_101 == 134 )
V_99 = ( 2 * V_100 / 269 ) ;
else if ( V_101 )
V_99 = V_100 / V_101 ;
}
if ( ! V_99 && V_98 ) {
V_15 -> V_104 . V_105 &= ~ V_115 ;
V_15 -> V_104 . V_105 |= ( V_98 -> V_105 & V_115 ) ;
V_101 = F_42 ( V_15 ) ;
if ( ! V_101 )
V_101 = 9600 ;
if ( V_101 == 38400 &&
( V_66 -> V_17 & V_112 ) == V_113 )
V_99 = V_2 -> V_114 ;
else {
if ( V_101 == 134 )
V_99 = ( 2 * V_100 / 269 ) ;
else if ( V_101 )
V_99 = V_100 / V_101 ;
}
}
if ( ! V_99 )
V_99 = V_100 / 9600 ;
V_2 -> V_99 = V_99 ;
V_2 -> V_116 = ( ( V_2 -> V_117 * V_118 * V_9 * V_99 ) / V_100 ) ;
V_2 -> V_116 += V_118 / 50 ;
V_2 -> V_18 &= ~ V_81 ;
if ( V_66 -> V_17 & V_119 )
V_2 -> V_18 |= V_81 ;
F_43 ( V_66 , V_102 & V_120 ) ;
if ( V_102 & V_120 )
V_2 -> V_18 |= V_81 ;
F_44 ( V_66 , ~ V_102 & V_121 ) ;
if ( ~ V_102 & V_121 )
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
if ( ( V_102 & V_122 ) == 0 )
V_2 -> V_49 |= V_36 ;
F_6 ( V_17 ) ;
{
short V_123 ;
V_123 = V_99 - 1 ;
if( V_103 & V_108 )
V_123 |= ( V_124 ) ;
V_20 . V_123 = V_123 ;
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
static int F_53 ( struct V_14 * V_15 , const unsigned char * V_27 , int V_125 )
{
int V_126 , V_127 = 0 ;
struct V_1 * V_2 = V_15 -> V_16 ;
unsigned long V_17 ;
if ( F_1 ( V_2 , V_15 -> V_3 , L_22 ) )
return 0 ;
if ( ! V_2 -> V_24 . V_27 )
return 0 ;
F_6 ( V_17 ) ;
while ( 1 ) {
V_126 = F_54 ( V_2 -> V_24 . V_25 ,
V_2 -> V_24 . V_26 ,
V_63 ) ;
if ( V_125 < V_126 )
V_126 = V_125 ;
if ( V_126 <= 0 ) {
break;
}
memcpy ( V_2 -> V_24 . V_27 + V_2 -> V_24 . V_25 , V_27 , V_126 ) ;
V_2 -> V_24 . V_25 = ( ( V_2 -> V_24 . V_25 + V_126 ) &
( V_63 - 1 ) ) ;
V_27 += V_126 ;
V_125 -= V_126 ;
V_127 += V_126 ;
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
return V_127 ;
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
if( ! ( V_20 . V_128 & V_22 ) ) {
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
static int F_68 ( struct V_14 * V_15 , struct V_1 * V_94 ,
struct V_129 T_3 * V_130 )
{
struct V_129 V_131 ;
memset ( & V_131 , 0 , sizeof( V_131 ) ) ;
F_69 ( V_15 ) ;
V_131 . line = V_15 -> V_132 ;
V_131 . V_66 = V_94 -> V_66 ;
V_131 . V_17 = V_94 -> V_53 . V_17 ;
V_131 . V_117 = V_94 -> V_117 ;
V_131 . V_100 = V_94 -> V_100 ;
V_131 . V_133 = V_94 -> V_53 . V_133 ;
V_131 . V_134 = V_94 -> V_53 . V_134 ;
V_131 . V_114 = V_94 -> V_114 ;
F_70 ( V_15 ) ;
if ( F_71 ( V_130 , & V_131 , sizeof( * V_130 ) ) )
return - V_135 ;
return 0 ;
}
static int F_72 ( struct V_14 * V_15 , struct V_1 * V_94 ,
struct V_129 T_3 * V_136 )
{
struct V_65 * V_66 = & V_94 -> V_53 ;
struct V_129 V_137 ;
bool V_138 ;
int V_86 = 0 ;
if ( F_73 ( & V_137 , V_136 , sizeof( V_137 ) ) )
return - V_135 ;
F_69 ( V_15 ) ;
V_138 = ( ( V_137 . V_17 ^ V_66 -> V_17 ) & V_112 ) ||
V_137 . V_114 != V_94 -> V_114 ;
if ( V_137 . V_79 || V_137 . V_66 != V_94 -> V_66 ||
V_137 . V_117 != V_94 -> V_117 ) {
F_70 ( V_15 ) ;
return - V_139 ;
}
if ( ! F_32 () ) {
if ( ( V_137 . V_100 != V_94 -> V_100 ) ||
( V_137 . V_133 != V_66 -> V_133 ) ||
( V_137 . V_117 != V_94 -> V_117 ) ||
( ( V_137 . V_17 & ~ V_140 ) !=
( V_66 -> V_17 & ~ V_140 ) ) ) {
F_70 ( V_15 ) ;
return - V_141 ;
}
V_66 -> V_17 = ( ( V_66 -> V_17 & ~ V_140 ) |
( V_137 . V_17 & V_140 ) ) ;
V_94 -> V_114 = V_137 . V_114 ;
goto V_142;
}
if ( V_137 . V_100 < 9600 ) {
F_70 ( V_15 ) ;
return - V_139 ;
}
V_94 -> V_100 = V_137 . V_100 ;
V_66 -> V_17 = ( ( V_66 -> V_17 & ~ V_143 ) |
( V_137 . V_17 & V_143 ) ) ;
V_94 -> V_114 = V_137 . V_114 ;
V_66 -> V_133 = V_137 . V_133 * V_118 / 100 ;
V_66 -> V_134 = V_137 . V_134 * V_118 / 100 ;
V_66 -> V_144 = ( V_66 -> V_17 & V_145 ) ? 1 : 0 ;
V_142:
if ( F_29 ( V_66 ) ) {
if ( V_138 ) {
if ( V_137 . V_17 & V_112 )
F_74 ( V_15 -> V_146 , L_31 ) ;
F_36 ( V_15 , V_94 , NULL ) ;
}
} else
V_86 = F_27 ( V_15 , V_94 ) ;
F_70 ( V_15 ) ;
return V_86 ;
}
static int F_75 ( struct V_1 * V_2 , unsigned int T_3 * V_147 )
{
unsigned char V_29 ;
unsigned int V_148 ;
unsigned long V_17 ;
F_6 ( V_17 ) ;
V_29 = V_20 . V_30 ;
F_7 () ;
F_8 ( V_17 ) ;
V_148 = ( ( V_29 & V_149 ) ? V_150 : 0 ) ;
if ( F_71 ( V_147 , & V_148 , sizeof( int ) ) )
return - V_135 ;
return 0 ;
}
static int F_76 ( struct V_14 * V_15 )
{
struct V_1 * V_2 = V_15 -> V_16 ;
unsigned char V_151 , V_29 ;
unsigned long V_17 ;
if ( F_1 ( V_2 , V_15 -> V_3 , L_32 ) )
return - V_152 ;
if ( F_77 ( V_15 ) )
return - V_153 ;
V_151 = V_2 -> V_93 ;
F_6 ( V_17 ) ;
V_29 = V_10 . V_11 ;
F_8 ( V_17 ) ;
return ( ( V_151 & V_12 ) ? V_154 : 0 )
| ( ( V_151 & V_13 ) ? V_155 : 0 )
| ( ! ( V_29 & V_67 ) ? V_156 : 0 )
| ( ! ( V_29 & V_69 ) ? V_157 : 0 )
| ( ! ( V_29 & V_68 ) ? V_158 : 0 ) ;
}
static int F_78 ( struct V_14 * V_15 , unsigned int V_159 ,
unsigned int V_160 )
{
struct V_1 * V_2 = V_15 -> V_16 ;
unsigned long V_17 ;
if ( F_1 ( V_2 , V_15 -> V_3 , L_32 ) )
return - V_152 ;
if ( F_77 ( V_15 ) )
return - V_153 ;
F_6 ( V_17 ) ;
if ( V_159 & V_154 )
V_2 -> V_93 |= V_12 ;
if ( V_159 & V_155 )
V_2 -> V_93 |= V_13 ;
if ( V_160 & V_154 )
V_2 -> V_93 &= ~ V_12 ;
if ( V_160 & V_155 )
V_2 -> V_93 &= ~ V_13 ;
F_4 ( V_2 -> V_93 ) ;
F_8 ( V_17 ) ;
return 0 ;
}
static int F_79 ( struct V_14 * V_15 , int V_161 )
{
struct V_1 * V_2 = V_15 -> V_16 ;
unsigned long V_17 ;
if ( F_1 ( V_2 , V_15 -> V_3 , L_33 ) )
return - V_139 ;
F_6 ( V_17 ) ;
if ( V_161 == - 1 )
V_20 . V_95 = V_162 | V_96 ;
else
V_20 . V_95 = V_96 ;
F_7 () ;
F_8 ( V_17 ) ;
return 0 ;
}
static int F_80 ( struct V_14 * V_15 ,
struct V_163 * V_34 )
{
struct V_1 * V_2 = V_15 -> V_16 ;
struct V_33 V_164 ;
unsigned long V_17 ;
F_6 ( V_17 ) ;
V_164 = V_2 -> V_34 ;
F_8 ( V_17 ) ;
V_34 -> V_74 = V_164 . V_74 ;
V_34 -> V_72 = V_164 . V_72 ;
V_34 -> V_165 = V_164 . V_165 ;
V_34 -> V_73 = V_164 . V_73 ;
V_34 -> V_41 = V_164 . V_41 ;
V_34 -> V_60 = V_164 . V_60 ;
V_34 -> V_47 = V_164 . V_47 ;
V_34 -> V_48 = V_164 . V_48 ;
V_34 -> V_46 = V_164 . V_46 ;
V_34 -> V_45 = V_164 . V_45 ;
V_34 -> V_166 = V_164 . V_166 ;
return 0 ;
}
static int F_81 ( struct V_14 * V_15 ,
unsigned int V_167 , unsigned long V_168 )
{
struct V_1 * V_2 = V_15 -> V_16 ;
struct V_33 V_169 , V_164 ;
void T_3 * V_170 = ( void T_3 * ) V_168 ;
unsigned long V_17 ;
F_82 ( V_171 ) ;
int V_127 ;
if ( F_1 ( V_2 , V_15 -> V_3 , L_32 ) )
return - V_152 ;
if ( ( V_167 != V_172 ) && ( V_167 != V_173 ) &&
( V_167 != V_174 ) && ( V_167 != V_175 ) &&
( V_167 != V_176 ) && ( V_167 != V_177 ) ) {
if ( F_77 ( V_15 ) )
return - V_153 ;
}
switch ( V_167 ) {
case V_172 :
return F_68 ( V_15 , V_2 , V_170 ) ;
case V_173 :
return F_72 ( V_15 , V_2 , V_170 ) ;
case V_174 :
return 0 ;
case V_178 :
return F_75 ( V_2 , V_170 ) ;
case V_175 :
if ( F_71 ( V_170 ,
V_2 , sizeof( struct V_1 ) ) )
return - V_135 ;
return 0 ;
case V_176 :
F_6 ( V_17 ) ;
V_169 = V_2 -> V_34 ;
F_8 ( V_17 ) ;
while ( 1 ) {
F_83 ( & V_2 -> V_53 . V_75 ,
& V_171 , V_179 ) ;
F_6 ( V_17 ) ;
V_164 = V_2 -> V_34 ;
F_8 ( V_17 ) ;
if ( V_164 . V_165 == V_169 . V_165 && V_164 . V_72 == V_169 . V_72 &&
V_164 . V_73 == V_169 . V_73 && V_164 . V_74 == V_169 . V_74 ) {
V_127 = - V_153 ;
break;
}
if ( ( ( V_168 & V_180 ) && ( V_164 . V_165 != V_169 . V_165 ) ) ||
( ( V_168 & V_157 ) && ( V_164 . V_72 != V_169 . V_72 ) ) ||
( ( V_168 & V_181 ) && ( V_164 . V_73 != V_169 . V_73 ) ) ||
( ( V_168 & V_158 ) && ( V_164 . V_74 != V_169 . V_74 ) ) ) {
V_127 = 0 ;
break;
}
F_84 () ;
if ( F_85 ( V_182 ) ) {
V_127 = - V_183 ;
break;
}
V_169 = V_164 ;
}
F_86 ( & V_2 -> V_53 . V_75 , & V_171 ) ;
return V_127 ;
case V_184 :
case V_185 :
F_3 ( L_34 ) ;
return 0 ;
default:
return - V_186 ;
}
return 0 ;
}
static void F_87 ( struct V_14 * V_15 , struct V_97 * V_98 )
{
struct V_1 * V_2 = V_15 -> V_16 ;
unsigned long V_17 ;
unsigned int V_102 = V_15 -> V_104 . V_105 ;
F_36 ( V_15 , V_2 , V_98 ) ;
if ( ( V_98 -> V_105 & V_115 ) && ! ( V_102 & V_115 ) ) {
V_2 -> V_93 &= ~ ( V_13 | V_12 ) ;
F_6 ( V_17 ) ;
F_4 ( V_2 -> V_93 ) ;
F_8 ( V_17 ) ;
}
if ( ! ( V_98 -> V_105 & V_115 ) && ( V_102 & V_115 ) ) {
V_2 -> V_93 |= V_13 ;
if ( ! F_65 ( V_15 ) || ! F_88 ( V_15 ) )
V_2 -> V_93 |= V_12 ;
F_6 ( V_17 ) ;
F_4 ( V_2 -> V_93 ) ;
F_8 ( V_17 ) ;
}
if ( ( V_98 -> V_105 & V_120 ) && ! F_65 ( V_15 ) ) {
V_15 -> V_62 = 0 ;
F_9 ( V_15 ) ;
}
#if 0
if (!(old_termios->c_cflag & CLOCAL) && C_CLOCAL(tty))
wake_up_interruptible(&info->open_wait);
#endif
}
static void F_89 ( struct V_14 * V_15 , struct V_187 * V_188 )
{
struct V_1 * V_94 = V_15 -> V_16 ;
struct V_65 * V_66 = & V_94 -> V_53 ;
if ( F_1 ( V_94 , V_15 -> V_3 , L_35 ) )
return;
if ( F_90 ( V_66 , V_15 , V_188 ) == 0 )
return;
V_94 -> V_51 &= ~ V_36 ;
if ( F_29 ( V_66 ) ) {
V_20 . V_21 = V_37 ;
F_7 () ;
V_20 . V_23 = V_37 ;
F_7 () ;
F_91 ( V_15 , V_94 -> V_116 ) ;
}
F_38 ( V_15 , V_94 ) ;
F_58 ( V_15 ) ;
F_92 ( V_15 ) ;
V_66 -> V_15 = NULL ;
F_93 ( V_66 , V_15 ) ;
}
static void F_91 ( struct V_14 * V_15 , int V_116 )
{
struct V_1 * V_2 = V_15 -> V_16 ;
unsigned long V_189 , V_190 ;
int V_191 ;
if ( F_1 ( V_2 , V_15 -> V_3 , L_36 ) )
return;
if ( V_2 -> V_117 == 0 )
return;
V_189 = V_192 ;
V_190 = ( V_2 -> V_116 - V_118 / 50 ) / V_2 -> V_117 ;
V_190 = V_190 / 5 ;
if ( V_190 == 0 )
V_190 = 1 ;
if ( V_116 )
V_190 = F_94 (unsigned long, char_time, timeout) ;
if ( ! V_116 || V_116 > 2 * V_2 -> V_116 )
V_116 = 2 * V_2 -> V_116 ;
#ifdef F_95
F_3 ( L_37 , V_116 , V_190 ) ;
F_3 ( L_38 , V_192 ) ;
#endif
while( ! ( ( V_191 = V_20 . V_30 ) & V_149 ) ) {
#ifdef F_95
F_3 ( L_39 , V_191 , V_192 ) ;
#endif
F_96 ( F_97 ( V_190 ) ) ;
if ( F_85 ( V_182 ) )
break;
if ( V_116 && F_98 ( V_192 , V_189 + V_116 ) )
break;
}
F_99 ( V_193 ) ;
#ifdef F_95
F_3 ( L_40 , V_191 , V_192 ) ;
#endif
}
static void F_100 ( struct V_14 * V_15 )
{
struct V_1 * V_2 = V_15 -> V_16 ;
if ( F_1 ( V_2 , V_15 -> V_3 , L_41 ) )
return;
F_58 ( V_15 ) ;
F_38 ( V_15 , V_2 ) ;
V_2 -> V_53 . V_125 = 0 ;
F_101 ( & V_2 -> V_53 , 0 ) ;
V_2 -> V_53 . V_15 = NULL ;
F_19 ( & V_2 -> V_53 . V_77 ) ;
}
static int F_102 ( struct V_14 * V_15 , struct V_187 * V_188 )
{
struct V_1 * V_2 = V_194 + V_15 -> V_132 ;
struct V_65 * V_66 = & V_2 -> V_53 ;
int V_86 ;
V_66 -> V_125 ++ ;
V_66 -> V_15 = V_15 ;
V_15 -> V_16 = V_2 ;
V_15 -> V_66 = V_66 ;
if ( F_1 ( V_2 , V_15 -> V_3 , L_42 ) )
return - V_152 ;
V_66 -> V_144 = ( V_66 -> V_17 & V_145 ) ? 1 : 0 ;
V_86 = F_27 ( V_15 , V_2 ) ;
if ( V_86 ) {
return V_86 ;
}
return F_103 ( V_66 , V_15 , V_188 ) ;
}
static inline void F_104 ( struct V_195 * V_196 , int line ,
struct V_1 * V_94 )
{
char V_197 [ 30 ] , V_151 , V_29 ;
unsigned long V_17 ;
F_105 ( V_196 , L_43 , line ) ;
F_6 ( V_17 ) ;
V_29 = V_10 . V_11 ;
V_151 = F_29 ( & V_94 -> V_53 ) ? V_94 -> V_93 : V_29 ;
F_8 ( V_17 ) ;
V_197 [ 0 ] = 0 ;
V_197 [ 1 ] = 0 ;
if( ! ( V_151 & V_12 ) )
strcat ( V_197 , L_44 ) ;
if( ! ( V_29 & V_68 ) )
strcat ( V_197 , L_45 ) ;
if( ! ( V_151 & V_13 ) )
strcat ( V_197 , L_46 ) ;
if( ! ( V_29 & V_69 ) )
strcat ( V_197 , L_47 ) ;
if( ! ( V_29 & V_67 ) )
strcat ( V_197 , L_48 ) ;
if ( V_94 -> V_99 )
F_105 ( V_196 , L_49 , V_94 -> V_100 / V_94 -> V_99 ) ;
F_105 ( V_196 , L_50 , V_94 -> V_34 . V_60 , V_94 -> V_34 . V_41 ) ;
if ( V_94 -> V_34 . V_47 )
F_105 ( V_196 , L_51 , V_94 -> V_34 . V_47 ) ;
if ( V_94 -> V_34 . V_46 )
F_105 ( V_196 , L_52 , V_94 -> V_34 . V_46 ) ;
if ( V_94 -> V_34 . V_45 )
F_105 ( V_196 , L_53 , V_94 -> V_34 . V_45 ) ;
if ( V_94 -> V_34 . V_48 )
F_105 ( V_196 , L_54 , V_94 -> V_34 . V_48 ) ;
F_105 ( V_196 , L_55 , V_197 + 1 ) ;
}
static int F_106 ( struct V_195 * V_196 , void * V_198 )
{
F_105 ( V_196 , L_56 , V_199 ) ;
F_104 ( V_196 , 0 , & V_194 [ 0 ] ) ;
return 0 ;
}
static int F_107 ( struct V_200 * V_200 , struct V_187 * V_187 )
{
return F_108 ( V_187 , F_106 , NULL ) ;
}
static void F_109 ( void )
{
F_3 ( V_201 L_57 , V_202 , V_199 ) ;
}
static int F_110 ( struct V_65 * V_66 )
{
return ! ( V_10 . V_11 & V_67 ) ;
}
static void F_111 ( struct V_65 * V_66 , int raise )
{
struct V_1 * V_2 = F_112 ( V_66 , struct V_1 ,
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
static int T_4 F_113 ( struct V_203 * V_204 )
{
unsigned long V_17 ;
struct V_1 * V_94 ;
int error ;
V_205 = F_114 ( V_206 ) ;
if ( ! V_205 )
return - V_89 ;
F_109 () ;
V_205 -> V_207 = L_58 ;
V_205 -> V_3 = L_59 ;
V_205 -> V_208 = V_209 ;
V_205 -> V_210 = 64 ;
V_205 -> type = V_211 ;
V_205 -> V_212 = V_213 ;
V_205 -> V_214 = V_215 ;
V_205 -> V_214 . V_105 =
V_216 | V_217 | V_122 | V_218 | V_121 ;
V_205 -> V_17 = V_219 ;
F_115 ( V_205 , & V_220 ) ;
V_94 = V_194 ;
V_94 -> V_66 = ( int ) & V_20 . V_30 ;
V_94 -> V_114 = 0 ;
V_94 -> V_34 . V_74 = V_94 -> V_34 . V_72 =
V_94 -> V_34 . V_165 = V_94 -> V_34 . V_73 = 0 ;
V_94 -> V_34 . V_41 = V_94 -> V_34 . V_60 = 0 ;
V_94 -> V_34 . V_47 = V_94 -> V_34 . V_46 = 0 ;
V_94 -> V_34 . V_48 = V_94 -> V_34 . V_45 = 0 ;
F_116 ( & V_94 -> V_53 ) ;
V_94 -> V_53 . V_221 = & V_222 ;
F_117 ( & V_94 -> V_53 , V_205 , 0 ) ;
error = F_118 ( V_205 ) ;
if ( error )
goto V_223;
F_3 ( V_201 L_60 ) ;
V_94 -> V_100 = V_224 ;
V_94 -> V_117 = 1 ;
error = F_31 ( V_225 , F_26 , 0 , L_61 , V_94 ) ;
if ( error )
goto V_226;
error = F_31 ( V_227 , F_25 , 0 ,
L_62 , V_94 ) ;
if ( error )
goto V_228;
F_6 ( V_17 ) ;
V_20 . V_21 = V_37 | V_22 ;
F_7 () ;
V_20 . V_23 = V_37 | V_22 ;
F_7 () ;
F_8 ( V_17 ) ;
V_10 . V_229 |= ( V_13 | V_12 ) ;
V_10 . V_229 &= ~ ( V_67 | V_68 | V_69 ) ;
F_119 ( V_204 , V_94 ) ;
return 0 ;
V_228:
F_39 ( V_225 , V_94 ) ;
V_226:
F_120 ( V_205 ) ;
V_223:
F_121 ( & V_94 -> V_53 ) ;
F_122 ( V_205 ) ;
return error ;
}
static int T_5 F_123 ( struct V_203 * V_204 )
{
int error ;
struct V_1 * V_94 = F_124 ( V_204 ) ;
error = F_120 ( V_205 ) ;
if ( error )
F_3 ( L_63 ,
error ) ;
F_122 ( V_205 ) ;
F_121 ( & V_94 -> V_53 ) ;
F_39 ( V_225 , V_94 ) ;
F_39 ( V_227 , V_94 ) ;
return error ;
}
static void F_125 ( char V_126 )
{
V_20 . V_59 = ( unsigned char ) V_126 | 0x100 ;
while ( ! ( V_20 . V_30 & 0x2000 ) )
F_126 () ;
}
static void F_127 ( struct V_230 * V_231 , const char * V_232 ,
unsigned V_125 )
{
unsigned short V_21 = V_20 . V_128 ;
V_20 . V_21 = V_22 ;
while ( V_125 -- ) {
if ( * V_232 == '\n' )
F_125 ( '\r' ) ;
F_125 ( * V_232 ++ ) ;
}
V_20 . V_21 = V_28 | ( V_21 & V_22 ) ;
}
static struct V_233 * F_128 ( struct V_230 * V_126 , int * V_132 )
{
* V_132 = 0 ;
return V_205 ;
}
static int T_4 F_129 ( void )
{
if ( ! V_234 )
return - V_152 ;
F_130 ( & V_235 ) ;
return 0 ;
}
