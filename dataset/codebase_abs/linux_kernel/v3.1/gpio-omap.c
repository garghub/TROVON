static void F_1 ( struct V_1 * V_2 , int V_3 , int V_4 )
{
void T_1 * V_5 = V_2 -> V_6 ;
T_2 V_7 ;
V_5 += V_2 -> V_8 -> V_9 ;
V_7 = F_2 ( V_5 ) ;
if ( V_4 )
V_7 |= 1 << V_3 ;
else
V_7 &= ~ ( 1 << V_3 ) ;
F_3 ( V_7 , V_5 ) ;
}
static void F_4 ( struct V_1 * V_2 , int V_3 , int V_10 )
{
void T_1 * V_5 = V_2 -> V_6 ;
T_2 V_7 = F_5 ( V_2 , V_3 ) ;
if ( V_10 )
V_5 += V_2 -> V_8 -> V_11 ;
else
V_5 += V_2 -> V_8 -> V_12 ;
F_3 ( V_7 , V_5 ) ;
}
static void F_6 ( struct V_1 * V_2 , int V_3 , int V_10 )
{
void T_1 * V_5 = V_2 -> V_6 + V_2 -> V_8 -> V_13 ;
T_2 V_14 = F_5 ( V_2 , V_3 ) ;
T_2 V_7 ;
V_7 = F_2 ( V_5 ) ;
if ( V_10 )
V_7 |= V_14 ;
else
V_7 &= ~ V_14 ;
F_3 ( V_7 , V_5 ) ;
}
static int F_7 ( struct V_1 * V_2 , int V_3 )
{
void T_1 * V_5 = V_2 -> V_6 + V_2 -> V_8 -> V_15 ;
return ( F_2 ( V_5 ) & F_5 ( V_2 , V_3 ) ) != 0 ;
}
static int F_8 ( struct V_1 * V_2 , int V_3 )
{
void T_1 * V_5 = V_2 -> V_6 + V_2 -> V_8 -> V_13 ;
return ( F_2 ( V_5 ) & F_5 ( V_2 , V_3 ) ) != 0 ;
}
static void F_9 ( struct V_1 * V_2 , unsigned V_3 ,
unsigned V_16 )
{
void T_1 * V_5 ;
T_2 V_17 ;
T_2 V_7 ;
if ( ! V_2 -> V_18 )
return;
if ( V_16 < 32 )
V_16 = 0x01 ;
else if ( V_16 > 7936 )
V_16 = 0xff ;
else
V_16 = ( V_16 / 0x1f ) - 1 ;
V_7 = F_5 ( V_2 , V_3 ) ;
V_5 = V_2 -> V_6 + V_2 -> V_8 -> V_16 ;
F_3 ( V_16 , V_5 ) ;
V_5 = V_2 -> V_6 + V_2 -> V_8 -> V_19 ;
V_17 = F_2 ( V_5 ) ;
if ( V_16 ) {
V_17 |= V_7 ;
F_10 ( V_2 -> V_20 ) ;
} else {
V_17 &= ~ V_7 ;
F_11 ( V_2 -> V_20 ) ;
}
V_2 -> V_21 = V_17 ;
F_3 ( V_17 , V_5 ) ;
}
static inline void F_12 ( struct V_1 * V_2 , int V_3 ,
int V_22 )
{
void T_1 * V_6 = V_2 -> V_6 ;
T_2 V_14 = 1 << V_3 ;
if ( F_13 () ) {
F_14 ( V_23 , V_14 ,
V_22 & V_24 ) ;
F_14 ( V_25 , V_14 ,
V_22 & V_26 ) ;
F_14 ( V_27 , V_14 ,
V_22 & V_28 ) ;
F_14 ( V_29 , V_14 ,
V_22 & V_30 ) ;
} else {
F_14 ( V_31 , V_14 ,
V_22 & V_24 ) ;
F_14 ( V_32 , V_14 ,
V_22 & V_26 ) ;
F_14 ( V_33 , V_14 ,
V_22 & V_28 ) ;
F_14 ( V_34 , V_14 ,
V_22 & V_30 ) ;
}
if ( F_15 ( ! ( V_2 -> V_35 & V_14 ) ) ) {
if ( F_13 () ) {
F_14 ( V_36 , V_14 ,
V_22 != 0 ) ;
} else {
if ( V_22 & V_37 )
F_3 ( 1 << V_3 , V_2 -> V_6
+ V_38 ) ;
else
F_3 ( 1 << V_3 , V_2 -> V_6
+ V_39 ) ;
}
}
if ( F_16 () || F_13 () ||
( V_2 -> V_35 & V_14 ) ) {
if ( V_22 & V_37 )
V_2 -> V_40 |= V_14 ;
else
V_2 -> V_40 &= ~ V_14 ;
}
if ( F_13 () ) {
V_2 -> V_41 =
F_2 ( V_2 -> V_6 + V_23 ) |
F_2 ( V_2 -> V_6 + V_25 ) ;
} else {
V_2 -> V_41 =
F_2 ( V_2 -> V_6 + V_31 ) |
F_2 ( V_2 -> V_6 + V_32 ) ;
}
}
static void F_17 ( struct V_1 * V_2 , int V_3 )
{
void T_1 * V_5 = V_2 -> V_6 ;
T_2 V_7 = 0 ;
switch ( V_2 -> V_42 ) {
case V_43 :
V_5 += V_44 / V_2 -> V_45 ;
break;
#ifdef F_18
case V_46 :
V_5 += V_47 ;
break;
#endif
#if F_19 ( V_48 ) || F_19 ( V_49 )
case V_50 :
V_5 += V_51 ;
break;
#endif
default:
return;
}
V_7 = F_2 ( V_5 ) ;
if ( ( V_7 >> V_3 ) & 1 )
V_7 &= ~ ( 1 << V_3 ) ;
else
V_7 |= 1 << V_3 ;
F_3 ( V_7 , V_5 ) ;
}
static int F_20 ( struct V_1 * V_2 , int V_3 , int V_22 )
{
void T_1 * V_5 = V_2 -> V_6 ;
T_2 V_7 = 0 ;
switch ( V_2 -> V_42 ) {
#ifdef F_21
case V_43 :
V_5 += V_44 / V_2 -> V_45 ;
V_7 = F_2 ( V_5 ) ;
if ( ( V_22 & V_52 ) == V_37 )
V_2 -> V_53 |= 1 << V_3 ;
if ( V_22 & V_28 )
V_7 |= 1 << V_3 ;
else if ( V_22 & V_30 )
V_7 &= ~ ( 1 << V_3 ) ;
else
goto V_54;
break;
#endif
#ifdef F_18
case V_46 :
V_5 += V_47 ;
V_7 = F_2 ( V_5 ) ;
if ( ( V_22 & V_52 ) == V_37 )
V_2 -> V_53 |= 1 << V_3 ;
if ( V_22 & V_28 )
V_7 |= 1 << V_3 ;
else if ( V_22 & V_30 )
V_7 &= ~ ( 1 << V_3 ) ;
else
goto V_54;
break;
#endif
#ifdef F_22
case V_55 :
if ( V_3 & 0x08 )
V_5 += V_56 ;
else
V_5 += V_57 ;
V_3 &= 0x07 ;
V_7 = F_2 ( V_5 ) ;
V_7 &= ~ ( 3 << ( V_3 << 1 ) ) ;
if ( V_22 & V_28 )
V_7 |= 2 << ( V_3 << 1 ) ;
if ( V_22 & V_30 )
V_7 |= 1 << ( V_3 << 1 ) ;
if ( V_22 )
F_3 ( 1 << V_3 , V_2 -> V_6 + V_58 ) ;
else
F_3 ( 1 << V_3 , V_2 -> V_6 + V_59 ) ;
break;
#endif
#if F_19 ( V_48 ) || F_19 ( V_49 )
case V_50 :
V_5 += V_51 ;
V_7 = F_2 ( V_5 ) ;
if ( ( V_22 & V_52 ) == V_37 )
V_2 -> V_53 |= 1 << V_3 ;
if ( V_22 & V_28 )
V_7 |= 1 << V_3 ;
else if ( V_22 & V_30 )
V_7 &= ~ ( 1 << V_3 ) ;
else
goto V_54;
break;
#endif
#ifdef F_23
case V_60 :
case V_61 :
F_12 ( V_2 , V_3 , V_22 ) ;
return 0 ;
#endif
default:
goto V_54;
}
F_3 ( V_7 , V_5 ) ;
return 0 ;
V_54:
return - V_62 ;
}
static int F_24 ( struct V_63 * V_64 , unsigned type )
{
struct V_1 * V_2 ;
unsigned V_3 ;
int V_65 ;
unsigned long V_66 ;
if ( ! F_25 () && V_64 -> V_67 > V_68 )
V_3 = F_26 ( V_64 -> V_67 - V_68 ) ;
else
V_3 = V_64 -> V_67 - V_69 ;
if ( type & ~ V_52 )
return - V_62 ;
if ( ! F_25 ()
&& ( type & ( V_24 | V_26 ) ) )
return - V_62 ;
V_2 = F_27 ( V_64 ) ;
F_28 ( & V_2 -> V_70 , V_66 ) ;
V_65 = F_20 ( V_2 , F_29 ( V_2 , V_3 ) , type ) ;
F_30 ( & V_2 -> V_70 , V_66 ) ;
if ( type & ( V_24 | V_26 ) )
F_31 ( V_64 -> V_67 , V_71 ) ;
else if ( type & ( V_30 | V_28 ) )
F_31 ( V_64 -> V_67 , V_72 ) ;
return V_65 ;
}
static void F_32 ( struct V_1 * V_2 , int V_73 )
{
void T_1 * V_5 = V_2 -> V_6 ;
V_5 += V_2 -> V_8 -> V_74 ;
F_3 ( V_73 , V_5 ) ;
if ( V_2 -> V_8 -> V_75 ) {
V_5 = V_2 -> V_6 + V_2 -> V_8 -> V_75 ;
F_3 ( V_73 , V_5 ) ;
}
F_2 ( V_5 ) ;
}
static inline void F_33 ( struct V_1 * V_2 , int V_3 )
{
F_32 ( V_2 , F_5 ( V_2 , V_3 ) ) ;
}
static T_2 F_34 ( struct V_1 * V_2 )
{
void T_1 * V_5 = V_2 -> V_6 ;
T_2 V_7 ;
T_2 V_76 = ( 1 << V_2 -> V_77 ) - 1 ;
V_5 += V_2 -> V_8 -> V_78 ;
V_7 = F_2 ( V_5 ) ;
if ( V_2 -> V_8 -> V_79 )
V_7 = ~ V_7 ;
V_7 &= V_76 ;
return V_7 ;
}
static void F_35 ( struct V_1 * V_2 , int V_73 )
{
void T_1 * V_5 = V_2 -> V_6 ;
T_2 V_7 ;
if ( V_2 -> V_8 -> V_80 ) {
V_5 += V_2 -> V_8 -> V_80 ;
V_7 = V_73 ;
} else {
V_5 += V_2 -> V_8 -> V_78 ;
V_7 = F_2 ( V_5 ) ;
if ( V_2 -> V_8 -> V_79 )
V_7 &= ~ V_73 ;
else
V_7 |= V_73 ;
}
F_3 ( V_7 , V_5 ) ;
}
static void F_36 ( struct V_1 * V_2 , int V_73 )
{
void T_1 * V_5 = V_2 -> V_6 ;
T_2 V_7 ;
if ( V_2 -> V_8 -> V_81 ) {
V_5 += V_2 -> V_8 -> V_81 ;
V_7 = V_73 ;
} else {
V_5 += V_2 -> V_8 -> V_78 ;
V_7 = F_2 ( V_5 ) ;
if ( V_2 -> V_8 -> V_79 )
V_7 |= V_73 ;
else
V_7 &= ~ V_73 ;
}
F_3 ( V_7 , V_5 ) ;
}
static inline void F_37 ( struct V_1 * V_2 , int V_3 , int V_10 )
{
F_35 ( V_2 , F_5 ( V_2 , V_3 ) ) ;
}
static int F_38 ( struct V_1 * V_2 , int V_3 , int V_10 )
{
T_2 V_14 = F_5 ( V_2 , V_3 ) ;
unsigned long V_66 ;
if ( V_2 -> V_35 & V_14 ) {
F_39 ( V_2 -> V_82 ,
L_1 , V_3 ) ;
return - V_62 ;
}
F_28 ( & V_2 -> V_70 , V_66 ) ;
if ( V_10 )
V_2 -> V_83 |= V_14 ;
else
V_2 -> V_83 &= ~ V_14 ;
F_30 ( & V_2 -> V_70 , V_66 ) ;
return 0 ;
}
static void F_40 ( struct V_1 * V_2 , int V_3 )
{
F_1 ( V_2 , F_29 ( V_2 , V_3 ) , 1 ) ;
F_37 ( V_2 , V_3 , 0 ) ;
F_33 ( V_2 , V_3 ) ;
F_20 ( V_2 , F_29 ( V_2 , V_3 ) , V_84 ) ;
}
static int F_41 ( struct V_63 * V_64 , unsigned int V_10 )
{
unsigned int V_3 = V_64 -> V_67 - V_69 ;
struct V_1 * V_2 ;
int V_65 ;
V_2 = F_27 ( V_64 ) ;
V_65 = F_38 ( V_2 , V_3 , V_10 ) ;
return V_65 ;
}
static int F_42 ( struct V_85 * V_86 , unsigned V_87 )
{
struct V_1 * V_2 = F_43 ( V_86 , struct V_1 , V_86 ) ;
unsigned long V_66 ;
F_28 ( & V_2 -> V_70 , V_66 ) ;
F_20 ( V_2 , V_87 , V_84 ) ;
#ifdef F_18
if ( V_2 -> V_42 == V_46 ) {
void T_1 * V_5 ;
V_5 = V_2 -> V_6 + V_88 ;
F_3 ( F_2 ( V_5 ) | ( 1 << V_87 ) , V_5 ) ;
}
#endif
if ( ! F_44 () ) {
if ( ! V_2 -> V_89 ) {
void T_1 * V_5 = V_2 -> V_6 ;
T_2 V_90 ;
if ( F_45 () || F_16 () )
V_5 += V_91 ;
else if ( F_13 () )
V_5 += V_92 ;
V_90 = F_2 ( V_5 ) ;
V_90 &= 0xFFFFFFFE ;
F_3 ( V_90 , V_5 ) ;
}
V_2 -> V_89 |= 1 << V_87 ;
}
F_30 ( & V_2 -> V_70 , V_66 ) ;
return 0 ;
}
static void F_46 ( struct V_85 * V_86 , unsigned V_87 )
{
struct V_1 * V_2 = F_43 ( V_86 , struct V_1 , V_86 ) ;
unsigned long V_66 ;
F_28 ( & V_2 -> V_70 , V_66 ) ;
#ifdef F_22
if ( V_2 -> V_42 == V_55 ) {
void T_1 * V_5 = V_2 -> V_6 + V_59 ;
F_3 ( 1 << V_87 , V_5 ) ;
}
#endif
#if F_19 ( V_93 ) || F_19 ( V_94 )
if ( V_2 -> V_42 == V_60 ) {
void T_1 * V_5 = V_2 -> V_6 + V_39 ;
F_3 ( 1 << V_87 , V_5 ) ;
}
#endif
#ifdef F_47
if ( V_2 -> V_42 == V_61 ) {
void T_1 * V_5 = V_2 -> V_6 + V_36 ;
F_3 ( 1 << V_87 , V_5 ) ;
}
#endif
if ( ! F_44 () ) {
V_2 -> V_89 &= ~ ( 1 << V_87 ) ;
if ( ! V_2 -> V_89 ) {
void T_1 * V_5 = V_2 -> V_6 ;
T_2 V_90 ;
if ( F_45 () || F_16 () )
V_5 += V_91 ;
else if ( F_13 () )
V_5 += V_92 ;
V_90 = F_2 ( V_5 ) ;
V_90 |= 1 ;
F_3 ( V_90 , V_5 ) ;
}
}
F_40 ( V_2 , V_2 -> V_86 . V_6 + V_87 ) ;
F_30 ( & V_2 -> V_70 , V_66 ) ;
}
static void F_48 ( unsigned int V_67 , struct V_95 * V_96 )
{
void T_1 * V_97 = NULL ;
T_2 V_98 ;
unsigned int V_99 , V_100 ;
struct V_1 * V_2 ;
T_2 V_101 = 0 ;
int V_102 = 0 ;
struct V_103 * V_86 = F_49 ( V_96 ) ;
F_50 ( V_86 , V_96 ) ;
V_2 = F_51 ( V_67 ) ;
V_97 = V_2 -> V_6 + V_2 -> V_8 -> V_74 ;
if ( F_52 ( ! V_97 ) )
goto exit;
while( 1 ) {
T_2 V_104 , V_41 = 0 ;
T_2 V_105 ;
V_105 = F_34 ( V_2 ) ;
V_104 = V_98 = F_2 ( V_97 ) & V_105 ;
if ( F_53 () && ( V_2 -> V_42 == V_43 ) )
V_98 &= 0x0000ffff ;
if ( F_25 () ) {
V_41 = V_2 -> V_41 & V_105 ;
}
F_36 ( V_2 , V_104 & ~ V_41 ) ;
F_32 ( V_2 , V_104 & ~ V_41 ) ;
F_35 ( V_2 , V_104 & ~ V_41 ) ;
if ( ! V_41 && ! V_102 ) {
V_102 = 1 ;
F_54 ( V_86 , V_96 ) ;
}
V_98 |= V_101 ;
V_101 = 0 ;
if ( ! V_98 )
break;
V_99 = V_2 -> V_106 ;
for (; V_98 != 0 ; V_98 >>= 1 , V_99 ++ ) {
V_100 = F_29 ( V_2 , F_55 ( V_99 ) ) ;
if ( ! ( V_98 & 1 ) )
continue;
#ifdef F_21
if ( V_2 -> V_53 & ( 1 << V_100 ) )
F_17 ( V_2 , V_100 ) ;
#endif
F_56 ( V_99 ) ;
}
}
exit:
if ( ! V_102 )
F_54 ( V_86 , V_96 ) ;
}
static void F_57 ( struct V_63 * V_64 )
{
unsigned int V_3 = V_64 -> V_67 - V_69 ;
struct V_1 * V_2 = F_27 ( V_64 ) ;
unsigned long V_66 ;
F_28 ( & V_2 -> V_70 , V_66 ) ;
F_40 ( V_2 , V_3 ) ;
F_30 ( & V_2 -> V_70 , V_66 ) ;
}
static void F_58 ( struct V_63 * V_64 )
{
unsigned int V_3 = V_64 -> V_67 - V_69 ;
struct V_1 * V_2 = F_27 ( V_64 ) ;
F_33 ( V_2 , V_3 ) ;
}
static void F_59 ( struct V_63 * V_64 )
{
unsigned int V_3 = V_64 -> V_67 - V_69 ;
struct V_1 * V_2 = F_27 ( V_64 ) ;
unsigned long V_66 ;
F_28 ( & V_2 -> V_70 , V_66 ) ;
F_37 ( V_2 , V_3 , 0 ) ;
F_20 ( V_2 , F_29 ( V_2 , V_3 ) , V_84 ) ;
F_30 ( & V_2 -> V_70 , V_66 ) ;
}
static void F_60 ( struct V_63 * V_64 )
{
unsigned int V_3 = V_64 -> V_67 - V_69 ;
struct V_1 * V_2 = F_27 ( V_64 ) ;
unsigned int V_107 = F_5 ( V_2 , V_3 ) ;
T_2 V_22 = F_61 ( V_64 ) ;
unsigned long V_66 ;
F_28 ( & V_2 -> V_70 , V_66 ) ;
if ( V_22 )
F_20 ( V_2 , F_29 ( V_2 , V_3 ) , V_22 ) ;
if ( V_2 -> V_41 & V_107 ) {
F_37 ( V_2 , V_3 , 0 ) ;
F_33 ( V_2 , V_3 ) ;
}
F_37 ( V_2 , V_3 , 1 ) ;
F_30 ( & V_2 -> V_70 , V_66 ) ;
}
static int F_62 ( struct V_108 * V_82 )
{
struct V_109 * V_110 = F_63 ( V_82 ) ;
struct V_1 * V_2 = F_64 ( V_110 ) ;
void T_1 * V_111 = V_2 -> V_6 +
V_112 / V_2 -> V_45 ;
unsigned long V_66 ;
F_28 ( & V_2 -> V_70 , V_66 ) ;
V_2 -> V_113 = F_2 ( V_111 ) ;
F_3 ( 0xffff & ~ V_2 -> V_83 , V_111 ) ;
F_30 ( & V_2 -> V_70 , V_66 ) ;
return 0 ;
}
static int F_65 ( struct V_108 * V_82 )
{
struct V_109 * V_110 = F_63 ( V_82 ) ;
struct V_1 * V_2 = F_64 ( V_110 ) ;
void T_1 * V_111 = V_2 -> V_6 +
V_112 / V_2 -> V_45 ;
unsigned long V_66 ;
F_28 ( & V_2 -> V_70 , V_66 ) ;
F_3 ( V_2 -> V_113 , V_111 ) ;
F_30 ( & V_2 -> V_70 , V_66 ) ;
return 0 ;
}
static inline void F_66 ( void )
{
struct V_1 * V_2 = & V_1 [ 0 ] ;
F_67 ( & V_114 , V_2 ) ;
if ( F_68 ( & V_115 ) == 0 )
( void ) F_69 ( & V_114 ) ;
}
static inline void F_66 ( void ) {}
static inline void F_66 ( void ) {}
static int F_70 ( struct V_85 * V_86 , unsigned V_87 )
{
struct V_1 * V_2 ;
unsigned long V_66 ;
V_2 = F_43 ( V_86 , struct V_1 , V_86 ) ;
F_28 ( & V_2 -> V_70 , V_66 ) ;
F_1 ( V_2 , V_87 , 1 ) ;
F_30 ( & V_2 -> V_70 , V_66 ) ;
return 0 ;
}
static int F_71 ( struct V_1 * V_2 , int V_76 )
{
void T_1 * V_5 = V_2 -> V_6 + V_2 -> V_8 -> V_9 ;
return F_2 ( V_5 ) & V_76 ;
}
static int F_72 ( struct V_85 * V_86 , unsigned V_87 )
{
struct V_1 * V_2 ;
void T_1 * V_5 ;
int V_3 ;
T_2 V_76 ;
V_3 = V_86 -> V_6 + V_87 ;
V_2 = F_43 ( V_86 , struct V_1 , V_86 ) ;
V_5 = V_2 -> V_6 ;
V_76 = F_5 ( V_2 , V_3 ) ;
if ( F_71 ( V_2 , V_76 ) )
return F_7 ( V_2 , V_3 ) ;
else
return F_8 ( V_2 , V_3 ) ;
}
static int F_73 ( struct V_85 * V_86 , unsigned V_87 , int V_116 )
{
struct V_1 * V_2 ;
unsigned long V_66 ;
V_2 = F_43 ( V_86 , struct V_1 , V_86 ) ;
F_28 ( & V_2 -> V_70 , V_66 ) ;
V_2 -> V_11 ( V_2 , V_87 , V_116 ) ;
F_1 ( V_2 , V_87 , 0 ) ;
F_30 ( & V_2 -> V_70 , V_66 ) ;
return 0 ;
}
static int F_74 ( struct V_85 * V_86 , unsigned V_87 ,
unsigned V_16 )
{
struct V_1 * V_2 ;
unsigned long V_66 ;
V_2 = F_43 ( V_86 , struct V_1 , V_86 ) ;
if ( ! V_2 -> V_20 ) {
V_2 -> V_20 = F_75 ( V_2 -> V_82 , L_2 ) ;
if ( F_76 ( V_2 -> V_20 ) )
F_39 ( V_2 -> V_82 , L_3 ) ;
}
F_28 ( & V_2 -> V_70 , V_66 ) ;
F_9 ( V_2 , V_87 , V_16 ) ;
F_30 ( & V_2 -> V_70 , V_66 ) ;
return 0 ;
}
static void F_77 ( struct V_85 * V_86 , unsigned V_87 , int V_116 )
{
struct V_1 * V_2 ;
unsigned long V_66 ;
V_2 = F_43 ( V_86 , struct V_1 , V_86 ) ;
F_28 ( & V_2 -> V_70 , V_66 ) ;
V_2 -> V_11 ( V_2 , V_87 , V_116 ) ;
F_30 ( & V_2 -> V_70 , V_66 ) ;
}
static int F_78 ( struct V_85 * V_86 , unsigned V_87 )
{
struct V_1 * V_2 ;
V_2 = F_43 ( V_86 , struct V_1 , V_86 ) ;
return V_2 -> V_106 + V_87 ;
}
static void T_3 F_79 ( struct V_1 * V_2 )
{
static bool V_117 ;
T_2 V_118 ;
if ( V_117 || V_2 -> V_8 -> V_119 == V_120 )
return;
V_118 = F_80 ( V_2 -> V_6 + V_2 -> V_8 -> V_119 ) ;
F_81 ( L_4 ,
( V_118 >> 4 ) & 0x0f , V_118 & 0x0f ) ;
V_117 = true ;
}
static inline int F_82 ( struct V_109 * V_110 )
{
V_1 = F_83 ( V_121 * sizeof( struct V_1 ) ,
V_122 ) ;
if ( ! V_1 ) {
F_39 ( & V_110 -> V_82 , L_5 ) ;
return - V_123 ;
}
return 0 ;
}
static void F_84 ( struct V_1 * V_2 , int V_124 )
{
if ( F_25 () ) {
if ( F_13 () ) {
F_3 ( 0xffffffff , V_2 -> V_6 +
V_125 ) ;
F_3 ( 0x00000000 , V_2 -> V_6 +
V_126 ) ;
F_3 ( 0 , V_2 -> V_6 + V_92 ) ;
} else if ( F_16 () ) {
F_3 ( 0x00000000 , V_2 -> V_6 +
V_127 ) ;
F_3 ( 0xffffffff , V_2 -> V_6 +
V_128 ) ;
F_3 ( 0x00000000 , V_2 -> V_6 +
V_129 ) ;
F_3 ( 0 , V_2 -> V_6 + V_91 ) ;
} else if ( F_45 () ) {
static const T_2 V_35 [] = {
0xe203ffc0 , 0x08700040
} ;
if ( V_124 < F_85 ( V_35 ) )
V_2 -> V_35 = V_35 [ V_124 ] ;
}
} else if ( F_44 () ) {
if ( F_86 ( V_2 ) )
F_87 ( 0xffff , V_2 -> V_6 +
V_112 / V_2 -> V_45 ) ;
if ( F_53 () && V_2 -> V_42 == V_46 ) {
F_87 ( 0xffff , V_2 -> V_6
+ V_130 ) ;
F_87 ( 0x0000 , V_2 -> V_6
+ V_131 ) ;
}
if ( F_88 () && V_2 -> V_42 == V_55 ) {
F_87 ( 0x0000 , V_2 -> V_6
+ V_132 ) ;
F_87 ( 0xffff , V_2 -> V_6
+ V_133 ) ;
F_87 ( 0x0014 , V_2 -> V_6
+ V_134 ) ;
F_89 ( F_90 ( V_135 ) | 0x04 ,
V_135 ) ;
}
if ( F_91 () && V_2 -> V_42 == V_50 ) {
F_3 ( 0xffffffff , V_2 -> V_6
+ V_136 ) ;
F_3 ( 0x00000000 , V_2 -> V_6
+ V_137 ) ;
}
}
}
static T_3 void
F_92 ( struct V_1 * V_2 , unsigned int V_138 ,
unsigned int V_139 )
{
struct V_140 * V_141 ;
struct V_142 * V_143 ;
V_141 = F_93 ( L_6 , 1 , V_138 , V_2 -> V_6 ,
V_144 ) ;
V_143 = V_141 -> V_145 ;
V_143 -> V_86 . V_107 = V_146 ;
V_143 -> V_86 . V_147 = V_148 ;
V_143 -> V_86 . V_149 = F_24 ;
if ( F_88 () )
V_143 -> V_86 . V_150 = F_41 ,
V_143 -> V_8 . V_76 = V_151 / V_2 -> V_45 ;
F_94 ( V_141 , F_95 ( V_139 ) , V_152 ,
V_153 | V_154 , 0 ) ;
}
static void T_4 F_96 ( struct V_1 * V_2 )
{
int V_155 ;
static int V_3 ;
V_2 -> V_89 = 0 ;
V_2 -> V_86 . V_156 = F_42 ;
V_2 -> V_86 . free = F_46 ;
V_2 -> V_86 . V_157 = F_70 ;
V_2 -> V_86 . V_158 = F_72 ;
V_2 -> V_86 . V_159 = F_73 ;
V_2 -> V_86 . V_160 = F_74 ;
V_2 -> V_86 . V_161 = F_77 ;
V_2 -> V_86 . V_162 = F_78 ;
if ( F_86 ( V_2 ) ) {
V_2 -> V_86 . V_163 = L_7 ;
#ifdef F_22
V_2 -> V_86 . V_82 = & V_114 . V_82 ;
#endif
V_2 -> V_86 . V_6 = F_26 ( 0 ) ;
} else {
V_2 -> V_86 . V_163 = L_8 ;
V_2 -> V_86 . V_6 = V_3 ;
V_3 += V_2 -> V_77 ;
}
V_2 -> V_86 . V_164 = V_2 -> V_77 ;
F_97 ( & V_2 -> V_86 ) ;
for ( V_155 = V_2 -> V_106 ;
V_155 < V_2 -> V_106 + V_2 -> V_77 ; V_155 ++ ) {
F_98 ( V_155 , & V_165 ) ;
F_99 ( V_155 , V_2 ) ;
if ( F_86 ( V_2 ) ) {
F_92 ( V_2 , V_155 , V_2 -> V_77 ) ;
} else {
F_100 ( V_155 , & V_166 ) ;
F_101 ( V_155 , V_144 ) ;
F_102 ( V_155 , V_167 ) ;
}
}
F_103 ( V_2 -> V_67 , F_48 ) ;
F_104 ( V_2 -> V_67 , V_2 ) ;
}
static int T_4 F_105 ( struct V_109 * V_110 )
{
static int V_168 ;
struct V_169 * V_170 ;
struct V_171 * V_172 ;
int V_124 ;
struct V_1 * V_2 ;
if ( ! V_110 -> V_82 . V_173 )
return - V_62 ;
V_170 = V_110 -> V_82 . V_173 ;
if ( ! V_168 ) {
int V_174 ;
V_174 = F_82 ( V_110 ) ;
if ( V_174 )
return V_174 ;
}
V_124 = V_110 -> V_124 ;
V_2 = & V_1 [ V_124 ] ;
V_172 = F_106 ( V_110 , V_175 , 0 ) ;
if ( F_107 ( ! V_172 ) ) {
F_39 ( & V_110 -> V_82 , L_9 , V_124 ) ;
return - V_176 ;
}
V_2 -> V_67 = V_172 -> V_177 ;
V_2 -> V_106 = V_170 -> V_106 ;
V_2 -> V_42 = V_170 -> V_178 ;
V_2 -> V_82 = & V_110 -> V_82 ;
V_2 -> V_18 = V_170 -> V_18 ;
V_2 -> V_45 = V_170 -> V_179 ;
V_2 -> V_77 = V_170 -> V_180 ;
V_2 -> V_8 = V_170 -> V_8 ;
if ( V_2 -> V_8 -> V_11 && V_2 -> V_8 -> V_12 )
V_2 -> V_11 = F_4 ;
else
V_2 -> V_11 = F_6 ;
F_108 ( & V_2 -> V_70 ) ;
V_172 = F_106 ( V_110 , V_181 , 0 ) ;
if ( F_107 ( ! V_172 ) ) {
F_39 ( & V_110 -> V_82 , L_10 , V_124 ) ;
return - V_176 ;
}
V_2 -> V_6 = F_109 ( V_172 -> V_177 , F_110 ( V_172 ) ) ;
if ( ! V_2 -> V_6 ) {
F_39 ( & V_110 -> V_82 , L_11 , V_124 ) ;
return - V_123 ;
}
F_111 ( V_2 -> V_82 ) ;
F_112 ( V_2 -> V_82 ) ;
F_84 ( V_2 , V_124 ) ;
F_96 ( V_2 ) ;
F_79 ( V_2 ) ;
if ( ! V_168 )
V_168 = 1 ;
return 0 ;
}
static int F_113 ( void )
{
int V_182 ;
if ( ! F_25 () && ! F_88 () )
return 0 ;
for ( V_182 = 0 ; V_182 < V_121 ; V_182 ++ ) {
struct V_1 * V_2 = & V_1 [ V_182 ] ;
void T_1 * V_183 ;
void T_1 * V_184 ;
void T_1 * V_185 ;
unsigned long V_66 ;
switch ( V_2 -> V_42 ) {
#ifdef F_22
case V_55 :
V_183 = V_2 -> V_6 + V_186 ;
V_184 = V_2 -> V_6 + V_59 ;
V_185 = V_2 -> V_6 + V_58 ;
break;
#endif
#if F_19 ( V_93 ) || F_19 ( V_94 )
case V_60 :
V_183 = V_2 -> V_6 + V_187 ;
V_184 = V_2 -> V_6 + V_39 ;
V_185 = V_2 -> V_6 + V_38 ;
break;
#endif
#ifdef F_47
case V_61 :
V_183 = V_2 -> V_6 + V_36 ;
V_184 = V_2 -> V_6 + V_36 ;
V_185 = V_2 -> V_6 + V_36 ;
break;
#endif
default:
continue;
}
F_28 ( & V_2 -> V_70 , V_66 ) ;
V_2 -> V_113 = F_2 ( V_183 ) ;
F_3 ( 0xffffffff , V_184 ) ;
F_3 ( V_2 -> V_83 , V_185 ) ;
F_30 ( & V_2 -> V_70 , V_66 ) ;
}
return 0 ;
}
static void F_114 ( void )
{
int V_182 ;
if ( ! F_25 () && ! F_88 () )
return;
for ( V_182 = 0 ; V_182 < V_121 ; V_182 ++ ) {
struct V_1 * V_2 = & V_1 [ V_182 ] ;
void T_1 * V_184 ;
void T_1 * V_185 ;
unsigned long V_66 ;
switch ( V_2 -> V_42 ) {
#ifdef F_22
case V_55 :
V_184 = V_2 -> V_6 + V_59 ;
V_185 = V_2 -> V_6 + V_58 ;
break;
#endif
#if F_19 ( V_93 ) || F_19 ( V_94 )
case V_60 :
V_184 = V_2 -> V_6 + V_39 ;
V_185 = V_2 -> V_6 + V_38 ;
break;
#endif
#ifdef F_47
case V_61 :
V_184 = V_2 -> V_6 + V_36 ;
V_185 = V_2 -> V_6 + V_36 ;
break;
#endif
default:
continue;
}
F_28 ( & V_2 -> V_70 , V_66 ) ;
F_3 ( 0xffffffff , V_184 ) ;
F_3 ( V_2 -> V_113 , V_185 ) ;
F_30 ( & V_2 -> V_70 , V_66 ) ;
}
}
void F_115 ( int V_188 )
{
int V_182 , V_189 = 0 ;
int V_190 = 0 ;
if ( F_16 () )
V_190 = 1 ;
for ( V_182 = V_190 ; V_182 < V_121 ; V_182 ++ ) {
struct V_1 * V_2 = & V_1 [ V_182 ] ;
T_2 V_191 = 0 , V_192 = 0 ;
int V_155 ;
for ( V_155 = 0 ; V_155 < F_116 ( V_2 -> V_21 ) ; V_155 ++ )
F_11 ( V_2 -> V_20 ) ;
if ( ! V_188 )
continue;
if ( ! ( V_2 -> V_40 ) )
continue;
if ( F_45 () || F_16 () ) {
V_2 -> V_193 = F_2 ( V_2 -> V_6 +
V_194 ) ;
V_191 = F_2 ( V_2 -> V_6 +
V_34 ) ;
V_192 = F_2 ( V_2 -> V_6 +
V_33 ) ;
}
if ( F_13 () ) {
V_2 -> V_193 = F_2 ( V_2 -> V_6 +
V_195 ) ;
V_191 = F_2 ( V_2 -> V_6 +
V_29 ) ;
V_192 = F_2 ( V_2 -> V_6 +
V_27 ) ;
}
V_2 -> V_196 = V_191 ;
V_2 -> V_197 = V_192 ;
V_191 &= ~ V_2 -> V_40 ;
V_192 &= ~ V_2 -> V_40 ;
if ( F_45 () || F_16 () ) {
F_3 ( V_191 , V_2 -> V_6 +
V_34 ) ;
F_3 ( V_192 , V_2 -> V_6 +
V_33 ) ;
}
if ( F_13 () ) {
F_3 ( V_191 , V_2 -> V_6 + V_29 ) ;
F_3 ( V_192 , V_2 -> V_6 + V_27 ) ;
}
V_189 ++ ;
}
if ( ! V_189 ) {
V_198 = 0 ;
return;
}
V_198 = 1 ;
}
void F_117 ( void )
{
int V_182 ;
int V_190 = 0 ;
if ( F_16 () )
V_190 = 1 ;
for ( V_182 = V_190 ; V_182 < V_121 ; V_182 ++ ) {
struct V_1 * V_2 = & V_1 [ V_182 ] ;
T_2 V_7 = 0 , V_199 , V_200 , V_201 ;
int V_155 ;
for ( V_155 = 0 ; V_155 < F_116 ( V_2 -> V_21 ) ; V_155 ++ )
F_10 ( V_2 -> V_20 ) ;
if ( ! V_198 )
continue;
if ( ! ( V_2 -> V_40 ) )
continue;
if ( F_45 () || F_16 () ) {
F_3 ( V_2 -> V_196 ,
V_2 -> V_6 + V_34 ) ;
F_3 ( V_2 -> V_197 ,
V_2 -> V_6 + V_33 ) ;
V_7 = F_2 ( V_2 -> V_6 + V_194 ) ;
}
if ( F_13 () ) {
F_3 ( V_2 -> V_196 ,
V_2 -> V_6 + V_29 ) ;
F_3 ( V_2 -> V_197 ,
V_2 -> V_6 + V_27 ) ;
V_7 = F_2 ( V_2 -> V_6 + V_195 ) ;
}
V_7 ^= V_2 -> V_193 ;
V_7 &= V_2 -> V_40 ;
V_200 = V_7 & V_2 -> V_196 ;
V_200 &= V_2 -> V_193 ;
V_201 = V_7 & V_2 -> V_197 ;
V_201 &= ~ ( V_2 -> V_193 ) ;
V_199 = V_7 & ( ~ ( V_2 -> V_196 ) &
~ ( V_2 -> V_197 ) ) ;
V_199 |= V_200 | V_201 ;
if ( V_199 ) {
T_2 V_202 , V_203 ;
if ( F_45 () || F_16 () ) {
V_202 = F_2 ( V_2 -> V_6 +
V_31 ) ;
V_203 = F_2 ( V_2 -> V_6 +
V_32 ) ;
F_3 ( V_202 | V_199 , V_2 -> V_6 +
V_31 ) ;
F_3 ( V_203 | V_199 , V_2 -> V_6 +
V_32 ) ;
F_3 ( V_202 , V_2 -> V_6 +
V_31 ) ;
F_3 ( V_203 , V_2 -> V_6 +
V_32 ) ;
}
if ( F_13 () ) {
V_202 = F_2 ( V_2 -> V_6 +
V_23 ) ;
V_203 = F_2 ( V_2 -> V_6 +
V_25 ) ;
F_3 ( V_202 | V_7 , V_2 -> V_6 +
V_23 ) ;
F_3 ( V_203 | V_7 , V_2 -> V_6 +
V_25 ) ;
F_3 ( V_202 , V_2 -> V_6 +
V_23 ) ;
F_3 ( V_203 , V_2 -> V_6 +
V_25 ) ;
}
}
}
}
void F_118 ( void )
{
int V_182 ;
for ( V_182 = 1 ; V_182 < V_121 ; V_182 ++ ) {
struct V_1 * V_2 = & V_1 [ V_182 ] ;
V_204 [ V_182 ] . V_205 =
F_2 ( V_2 -> V_6 + V_127 ) ;
V_204 [ V_182 ] . V_206 =
F_2 ( V_2 -> V_6 + V_207 ) ;
V_204 [ V_182 ] . V_208 =
F_2 ( V_2 -> V_6 + V_187 ) ;
V_204 [ V_182 ] . V_90 =
F_2 ( V_2 -> V_6 + V_91 ) ;
V_204 [ V_182 ] . V_209 =
F_2 ( V_2 -> V_6 + V_210 ) ;
V_204 [ V_182 ] . V_211 =
F_2 ( V_2 -> V_6 + V_31 ) ;
V_204 [ V_182 ] . V_212 =
F_2 ( V_2 -> V_6 + V_32 ) ;
V_204 [ V_182 ] . V_213 =
F_2 ( V_2 -> V_6 + V_33 ) ;
V_204 [ V_182 ] . V_214 =
F_2 ( V_2 -> V_6 + V_34 ) ;
V_204 [ V_182 ] . V_13 =
F_2 ( V_2 -> V_6 + V_215 ) ;
}
}
void F_119 ( void )
{
int V_182 ;
for ( V_182 = 1 ; V_182 < V_121 ; V_182 ++ ) {
struct V_1 * V_2 = & V_1 [ V_182 ] ;
F_3 ( V_204 [ V_182 ] . V_205 ,
V_2 -> V_6 + V_127 ) ;
F_3 ( V_204 [ V_182 ] . V_206 ,
V_2 -> V_6 + V_207 ) ;
F_3 ( V_204 [ V_182 ] . V_208 ,
V_2 -> V_6 + V_187 ) ;
F_3 ( V_204 [ V_182 ] . V_90 ,
V_2 -> V_6 + V_91 ) ;
F_3 ( V_204 [ V_182 ] . V_209 ,
V_2 -> V_6 + V_210 ) ;
F_3 ( V_204 [ V_182 ] . V_211 ,
V_2 -> V_6 + V_31 ) ;
F_3 ( V_204 [ V_182 ] . V_212 ,
V_2 -> V_6 + V_32 ) ;
F_3 ( V_204 [ V_182 ] . V_213 ,
V_2 -> V_6 + V_33 ) ;
F_3 ( V_204 [ V_182 ] . V_214 ,
V_2 -> V_6 + V_34 ) ;
F_3 ( V_204 [ V_182 ] . V_13 ,
V_2 -> V_6 + V_215 ) ;
}
}
static int T_3 F_120 ( void )
{
return F_68 ( & V_216 ) ;
}
static int T_3 F_121 ( void )
{
F_66 () ;
#if F_19 ( F_22 ) || F_19 ( F_23 )
if ( F_88 () || F_25 () )
F_122 ( & V_217 ) ;
#endif
return 0 ;
}
