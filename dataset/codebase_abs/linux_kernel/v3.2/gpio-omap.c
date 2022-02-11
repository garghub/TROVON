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
static inline void F_9 ( void T_1 * V_6 , T_2 V_5 , T_2 V_16 , bool V_17 )
{
int V_7 = F_2 ( V_6 + V_5 ) ;
if ( V_17 )
V_7 |= V_16 ;
else
V_7 &= ~ V_16 ;
F_3 ( V_7 , V_6 + V_5 ) ;
}
static void F_10 ( struct V_1 * V_2 , unsigned V_3 ,
unsigned V_18 )
{
void T_1 * V_5 ;
T_2 V_19 ;
T_2 V_7 ;
if ( ! V_2 -> V_20 )
return;
if ( V_18 < 32 )
V_18 = 0x01 ;
else if ( V_18 > 7936 )
V_18 = 0xff ;
else
V_18 = ( V_18 / 0x1f ) - 1 ;
V_7 = F_5 ( V_2 , V_3 ) ;
V_5 = V_2 -> V_6 + V_2 -> V_8 -> V_18 ;
F_3 ( V_18 , V_5 ) ;
V_5 = V_2 -> V_6 + V_2 -> V_8 -> V_21 ;
V_19 = F_2 ( V_5 ) ;
if ( V_18 ) {
V_19 |= V_7 ;
F_11 ( V_2 -> V_22 ) ;
} else {
V_19 &= ~ V_7 ;
F_12 ( V_2 -> V_22 ) ;
}
V_2 -> V_23 = V_19 ;
F_3 ( V_19 , V_5 ) ;
}
static inline void F_13 ( struct V_1 * V_2 , int V_3 ,
int V_24 )
{
void T_1 * V_6 = V_2 -> V_6 ;
T_2 V_14 = 1 << V_3 ;
if ( F_14 () ) {
F_9 ( V_6 , V_25 , V_14 ,
V_24 & V_26 ) ;
F_9 ( V_6 , V_27 , V_14 ,
V_24 & V_28 ) ;
F_9 ( V_6 , V_29 , V_14 ,
V_24 & V_30 ) ;
F_9 ( V_6 , V_31 , V_14 ,
V_24 & V_32 ) ;
} else {
F_9 ( V_6 , V_33 , V_14 ,
V_24 & V_26 ) ;
F_9 ( V_6 , V_34 , V_14 ,
V_24 & V_28 ) ;
F_9 ( V_6 , V_35 , V_14 ,
V_24 & V_30 ) ;
F_9 ( V_6 , V_36 , V_14 ,
V_24 & V_32 ) ;
}
if ( F_15 ( ! ( V_2 -> V_37 & V_14 ) ) ) {
if ( F_14 () ) {
F_9 ( V_6 , V_38 , V_14 ,
V_24 != 0 ) ;
} else {
if ( V_24 & V_39 )
F_3 ( 1 << V_3 , V_2 -> V_6
+ V_40 ) ;
else
F_3 ( 1 << V_3 , V_2 -> V_6
+ V_41 ) ;
}
}
if ( F_16 () || F_14 () ||
( V_2 -> V_37 & V_14 ) ) {
if ( V_24 & V_39 )
V_2 -> V_42 |= V_14 ;
else
V_2 -> V_42 &= ~ V_14 ;
}
if ( F_14 () ) {
V_2 -> V_43 =
F_2 ( V_2 -> V_6 + V_25 ) |
F_2 ( V_2 -> V_6 + V_27 ) ;
} else {
V_2 -> V_43 =
F_2 ( V_2 -> V_6 + V_33 ) |
F_2 ( V_2 -> V_6 + V_34 ) ;
}
}
static void F_17 ( struct V_1 * V_2 , int V_3 )
{
void T_1 * V_5 = V_2 -> V_6 ;
T_2 V_7 = 0 ;
switch ( V_2 -> V_44 ) {
case V_45 :
V_5 += V_46 / V_2 -> V_47 ;
break;
#ifdef F_18
case V_48 :
V_5 += V_49 ;
break;
#endif
#if F_19 ( V_50 ) || F_19 ( V_51 )
case V_52 :
V_5 += V_53 ;
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
static int F_20 ( struct V_1 * V_2 , int V_3 , int V_24 )
{
void T_1 * V_5 = V_2 -> V_6 ;
T_2 V_7 = 0 ;
switch ( V_2 -> V_44 ) {
#ifdef F_21
case V_45 :
V_5 += V_46 / V_2 -> V_47 ;
V_7 = F_2 ( V_5 ) ;
if ( ( V_24 & V_54 ) == V_39 )
V_2 -> V_55 |= 1 << V_3 ;
if ( V_24 & V_30 )
V_7 |= 1 << V_3 ;
else if ( V_24 & V_32 )
V_7 &= ~ ( 1 << V_3 ) ;
else
goto V_56;
break;
#endif
#ifdef F_18
case V_48 :
V_5 += V_49 ;
V_7 = F_2 ( V_5 ) ;
if ( ( V_24 & V_54 ) == V_39 )
V_2 -> V_55 |= 1 << V_3 ;
if ( V_24 & V_30 )
V_7 |= 1 << V_3 ;
else if ( V_24 & V_32 )
V_7 &= ~ ( 1 << V_3 ) ;
else
goto V_56;
break;
#endif
#ifdef F_22
case V_57 :
if ( V_3 & 0x08 )
V_5 += V_58 ;
else
V_5 += V_59 ;
V_3 &= 0x07 ;
V_7 = F_2 ( V_5 ) ;
V_7 &= ~ ( 3 << ( V_3 << 1 ) ) ;
if ( V_24 & V_30 )
V_7 |= 2 << ( V_3 << 1 ) ;
if ( V_24 & V_32 )
V_7 |= 1 << ( V_3 << 1 ) ;
if ( V_24 )
F_3 ( 1 << V_3 , V_2 -> V_6 + V_60 ) ;
else
F_3 ( 1 << V_3 , V_2 -> V_6 + V_61 ) ;
break;
#endif
#if F_19 ( V_50 ) || F_19 ( V_51 )
case V_52 :
V_5 += V_53 ;
V_7 = F_2 ( V_5 ) ;
if ( ( V_24 & V_54 ) == V_39 )
V_2 -> V_55 |= 1 << V_3 ;
if ( V_24 & V_30 )
V_7 |= 1 << V_3 ;
else if ( V_24 & V_32 )
V_7 &= ~ ( 1 << V_3 ) ;
else
goto V_56;
break;
#endif
#ifdef F_23
case V_62 :
case V_63 :
F_13 ( V_2 , V_3 , V_24 ) ;
return 0 ;
#endif
default:
goto V_56;
}
F_3 ( V_7 , V_5 ) ;
return 0 ;
V_56:
return - V_64 ;
}
static int F_24 ( struct V_65 * V_66 , unsigned type )
{
struct V_1 * V_2 ;
unsigned V_3 ;
int V_67 ;
unsigned long V_68 ;
if ( ! F_25 () && V_66 -> V_69 > V_70 )
V_3 = F_26 ( V_66 -> V_69 - V_70 ) ;
else
V_3 = V_66 -> V_69 - V_71 ;
if ( type & ~ V_54 )
return - V_64 ;
if ( ! F_25 ()
&& ( type & ( V_26 | V_28 ) ) )
return - V_64 ;
V_2 = F_27 ( V_66 ) ;
F_28 ( & V_2 -> V_72 , V_68 ) ;
V_67 = F_20 ( V_2 , F_29 ( V_2 , V_3 ) , type ) ;
F_30 ( & V_2 -> V_72 , V_68 ) ;
if ( type & ( V_26 | V_28 ) )
F_31 ( V_66 -> V_69 , V_73 ) ;
else if ( type & ( V_32 | V_30 ) )
F_31 ( V_66 -> V_69 , V_74 ) ;
return V_67 ;
}
static void F_32 ( struct V_1 * V_2 , int V_75 )
{
void T_1 * V_5 = V_2 -> V_6 ;
V_5 += V_2 -> V_8 -> V_76 ;
F_3 ( V_75 , V_5 ) ;
if ( V_2 -> V_8 -> V_77 ) {
V_5 = V_2 -> V_6 + V_2 -> V_8 -> V_77 ;
F_3 ( V_75 , V_5 ) ;
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
T_2 V_16 = ( 1 << V_2 -> V_78 ) - 1 ;
V_5 += V_2 -> V_8 -> V_79 ;
V_7 = F_2 ( V_5 ) ;
if ( V_2 -> V_8 -> V_80 )
V_7 = ~ V_7 ;
V_7 &= V_16 ;
return V_7 ;
}
static void F_35 ( struct V_1 * V_2 , int V_75 )
{
void T_1 * V_5 = V_2 -> V_6 ;
T_2 V_7 ;
if ( V_2 -> V_8 -> V_81 ) {
V_5 += V_2 -> V_8 -> V_81 ;
V_7 = V_75 ;
} else {
V_5 += V_2 -> V_8 -> V_79 ;
V_7 = F_2 ( V_5 ) ;
if ( V_2 -> V_8 -> V_80 )
V_7 &= ~ V_75 ;
else
V_7 |= V_75 ;
}
F_3 ( V_7 , V_5 ) ;
}
static void F_36 ( struct V_1 * V_2 , int V_75 )
{
void T_1 * V_5 = V_2 -> V_6 ;
T_2 V_7 ;
if ( V_2 -> V_8 -> V_82 ) {
V_5 += V_2 -> V_8 -> V_82 ;
V_7 = V_75 ;
} else {
V_5 += V_2 -> V_8 -> V_79 ;
V_7 = F_2 ( V_5 ) ;
if ( V_2 -> V_8 -> V_80 )
V_7 |= V_75 ;
else
V_7 &= ~ V_75 ;
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
unsigned long V_68 ;
if ( V_2 -> V_37 & V_14 ) {
F_39 ( V_2 -> V_83 ,
L_1 , V_3 ) ;
return - V_64 ;
}
F_28 ( & V_2 -> V_72 , V_68 ) ;
if ( V_10 )
V_2 -> V_84 |= V_14 ;
else
V_2 -> V_84 &= ~ V_14 ;
F_30 ( & V_2 -> V_72 , V_68 ) ;
return 0 ;
}
static void F_40 ( struct V_1 * V_2 , int V_3 )
{
F_1 ( V_2 , F_29 ( V_2 , V_3 ) , 1 ) ;
F_37 ( V_2 , V_3 , 0 ) ;
F_33 ( V_2 , V_3 ) ;
F_20 ( V_2 , F_29 ( V_2 , V_3 ) , V_85 ) ;
}
static int F_41 ( struct V_65 * V_66 , unsigned int V_10 )
{
unsigned int V_3 = V_66 -> V_69 - V_71 ;
struct V_1 * V_2 ;
int V_67 ;
V_2 = F_27 ( V_66 ) ;
V_67 = F_38 ( V_2 , V_3 , V_10 ) ;
return V_67 ;
}
static int F_42 ( struct V_86 * V_87 , unsigned V_88 )
{
struct V_1 * V_2 = F_43 ( V_87 , struct V_1 , V_87 ) ;
unsigned long V_68 ;
F_28 ( & V_2 -> V_72 , V_68 ) ;
F_20 ( V_2 , V_88 , V_85 ) ;
#ifdef F_18
if ( V_2 -> V_44 == V_48 ) {
void T_1 * V_5 ;
V_5 = V_2 -> V_6 + V_89 ;
F_3 ( F_2 ( V_5 ) | ( 1 << V_88 ) , V_5 ) ;
}
#endif
if ( ! F_44 () ) {
if ( ! V_2 -> V_90 ) {
void T_1 * V_5 = V_2 -> V_6 ;
T_2 V_91 ;
if ( F_45 () || F_16 () )
V_5 += V_92 ;
else if ( F_14 () )
V_5 += V_93 ;
V_91 = F_2 ( V_5 ) ;
V_91 &= 0xFFFFFFFE ;
F_3 ( V_91 , V_5 ) ;
}
V_2 -> V_90 |= 1 << V_88 ;
}
F_30 ( & V_2 -> V_72 , V_68 ) ;
return 0 ;
}
static void F_46 ( struct V_86 * V_87 , unsigned V_88 )
{
struct V_1 * V_2 = F_43 ( V_87 , struct V_1 , V_87 ) ;
unsigned long V_68 ;
F_28 ( & V_2 -> V_72 , V_68 ) ;
#ifdef F_22
if ( V_2 -> V_44 == V_57 ) {
void T_1 * V_5 = V_2 -> V_6 + V_61 ;
F_3 ( 1 << V_88 , V_5 ) ;
}
#endif
#if F_19 ( V_94 ) || F_19 ( V_95 )
if ( V_2 -> V_44 == V_62 ) {
void T_1 * V_5 = V_2 -> V_6 + V_41 ;
F_3 ( 1 << V_88 , V_5 ) ;
}
#endif
#ifdef F_47
if ( V_2 -> V_44 == V_63 ) {
void T_1 * V_5 = V_2 -> V_6 + V_38 ;
F_3 ( 1 << V_88 , V_5 ) ;
}
#endif
if ( ! F_44 () ) {
V_2 -> V_90 &= ~ ( 1 << V_88 ) ;
if ( ! V_2 -> V_90 ) {
void T_1 * V_5 = V_2 -> V_6 ;
T_2 V_91 ;
if ( F_45 () || F_16 () )
V_5 += V_92 ;
else if ( F_14 () )
V_5 += V_93 ;
V_91 = F_2 ( V_5 ) ;
V_91 |= 1 ;
F_3 ( V_91 , V_5 ) ;
}
}
F_40 ( V_2 , V_2 -> V_87 . V_6 + V_88 ) ;
F_30 ( & V_2 -> V_72 , V_68 ) ;
}
static void F_48 ( unsigned int V_69 , struct V_96 * V_97 )
{
void T_1 * V_98 = NULL ;
T_2 V_99 ;
unsigned int V_100 , V_101 ;
struct V_1 * V_2 ;
T_2 V_102 = 0 ;
int V_103 = 0 ;
struct V_104 * V_87 = F_49 ( V_97 ) ;
F_50 ( V_87 , V_97 ) ;
V_2 = F_51 ( V_69 ) ;
V_98 = V_2 -> V_6 + V_2 -> V_8 -> V_76 ;
if ( F_52 ( ! V_98 ) )
goto exit;
while( 1 ) {
T_2 V_105 , V_43 = 0 ;
T_2 V_106 ;
V_106 = F_34 ( V_2 ) ;
V_105 = V_99 = F_2 ( V_98 ) & V_106 ;
if ( F_53 () && ( V_2 -> V_44 == V_45 ) )
V_99 &= 0x0000ffff ;
if ( F_25 () ) {
V_43 = V_2 -> V_43 & V_106 ;
}
F_36 ( V_2 , V_105 & ~ V_43 ) ;
F_32 ( V_2 , V_105 & ~ V_43 ) ;
F_35 ( V_2 , V_105 & ~ V_43 ) ;
if ( ! V_43 && ! V_103 ) {
V_103 = 1 ;
F_54 ( V_87 , V_97 ) ;
}
V_99 |= V_102 ;
V_102 = 0 ;
if ( ! V_99 )
break;
V_100 = V_2 -> V_107 ;
for (; V_99 != 0 ; V_99 >>= 1 , V_100 ++ ) {
V_101 = F_29 ( V_2 , F_55 ( V_100 ) ) ;
if ( ! ( V_99 & 1 ) )
continue;
#ifdef F_21
if ( V_2 -> V_55 & ( 1 << V_101 ) )
F_17 ( V_2 , V_101 ) ;
#endif
F_56 ( V_100 ) ;
}
}
exit:
if ( ! V_103 )
F_54 ( V_87 , V_97 ) ;
}
static void F_57 ( struct V_65 * V_66 )
{
unsigned int V_3 = V_66 -> V_69 - V_71 ;
struct V_1 * V_2 = F_27 ( V_66 ) ;
unsigned long V_68 ;
F_28 ( & V_2 -> V_72 , V_68 ) ;
F_40 ( V_2 , V_3 ) ;
F_30 ( & V_2 -> V_72 , V_68 ) ;
}
static void F_58 ( struct V_65 * V_66 )
{
unsigned int V_3 = V_66 -> V_69 - V_71 ;
struct V_1 * V_2 = F_27 ( V_66 ) ;
F_33 ( V_2 , V_3 ) ;
}
static void F_59 ( struct V_65 * V_66 )
{
unsigned int V_3 = V_66 -> V_69 - V_71 ;
struct V_1 * V_2 = F_27 ( V_66 ) ;
unsigned long V_68 ;
F_28 ( & V_2 -> V_72 , V_68 ) ;
F_37 ( V_2 , V_3 , 0 ) ;
F_20 ( V_2 , F_29 ( V_2 , V_3 ) , V_85 ) ;
F_30 ( & V_2 -> V_72 , V_68 ) ;
}
static void F_60 ( struct V_65 * V_66 )
{
unsigned int V_3 = V_66 -> V_69 - V_71 ;
struct V_1 * V_2 = F_27 ( V_66 ) ;
unsigned int V_108 = F_5 ( V_2 , V_3 ) ;
T_2 V_24 = F_61 ( V_66 ) ;
unsigned long V_68 ;
F_28 ( & V_2 -> V_72 , V_68 ) ;
if ( V_24 )
F_20 ( V_2 , F_29 ( V_2 , V_3 ) , V_24 ) ;
if ( V_2 -> V_43 & V_108 ) {
F_37 ( V_2 , V_3 , 0 ) ;
F_33 ( V_2 , V_3 ) ;
}
F_37 ( V_2 , V_3 , 1 ) ;
F_30 ( & V_2 -> V_72 , V_68 ) ;
}
static int F_62 ( struct V_109 * V_83 )
{
struct V_110 * V_111 = F_63 ( V_83 ) ;
struct V_1 * V_2 = F_64 ( V_111 ) ;
void T_1 * V_112 = V_2 -> V_6 +
V_113 / V_2 -> V_47 ;
unsigned long V_68 ;
F_28 ( & V_2 -> V_72 , V_68 ) ;
V_2 -> V_114 = F_2 ( V_112 ) ;
F_3 ( 0xffff & ~ V_2 -> V_84 , V_112 ) ;
F_30 ( & V_2 -> V_72 , V_68 ) ;
return 0 ;
}
static int F_65 ( struct V_109 * V_83 )
{
struct V_110 * V_111 = F_63 ( V_83 ) ;
struct V_1 * V_2 = F_64 ( V_111 ) ;
void T_1 * V_112 = V_2 -> V_6 +
V_113 / V_2 -> V_47 ;
unsigned long V_68 ;
F_28 ( & V_2 -> V_72 , V_68 ) ;
F_3 ( V_2 -> V_114 , V_112 ) ;
F_30 ( & V_2 -> V_72 , V_68 ) ;
return 0 ;
}
static inline void F_66 ( void )
{
struct V_1 * V_2 = & V_1 [ 0 ] ;
F_67 ( & V_115 , V_2 ) ;
if ( F_68 ( & V_116 ) == 0 )
( void ) F_69 ( & V_115 ) ;
}
static inline void F_66 ( void ) {}
static inline void F_66 ( void ) {}
static int F_70 ( struct V_86 * V_87 , unsigned V_88 )
{
struct V_1 * V_2 ;
unsigned long V_68 ;
V_2 = F_43 ( V_87 , struct V_1 , V_87 ) ;
F_28 ( & V_2 -> V_72 , V_68 ) ;
F_1 ( V_2 , V_88 , 1 ) ;
F_30 ( & V_2 -> V_72 , V_68 ) ;
return 0 ;
}
static int F_71 ( struct V_1 * V_2 , int V_16 )
{
void T_1 * V_5 = V_2 -> V_6 + V_2 -> V_8 -> V_9 ;
return F_2 ( V_5 ) & V_16 ;
}
static int F_72 ( struct V_86 * V_87 , unsigned V_88 )
{
struct V_1 * V_2 ;
void T_1 * V_5 ;
int V_3 ;
T_2 V_16 ;
V_3 = V_87 -> V_6 + V_88 ;
V_2 = F_43 ( V_87 , struct V_1 , V_87 ) ;
V_5 = V_2 -> V_6 ;
V_16 = F_5 ( V_2 , V_3 ) ;
if ( F_71 ( V_2 , V_16 ) )
return F_7 ( V_2 , V_3 ) ;
else
return F_8 ( V_2 , V_3 ) ;
}
static int F_73 ( struct V_86 * V_87 , unsigned V_88 , int V_117 )
{
struct V_1 * V_2 ;
unsigned long V_68 ;
V_2 = F_43 ( V_87 , struct V_1 , V_87 ) ;
F_28 ( & V_2 -> V_72 , V_68 ) ;
V_2 -> V_11 ( V_2 , V_88 , V_117 ) ;
F_1 ( V_2 , V_88 , 0 ) ;
F_30 ( & V_2 -> V_72 , V_68 ) ;
return 0 ;
}
static int F_74 ( struct V_86 * V_87 , unsigned V_88 ,
unsigned V_18 )
{
struct V_1 * V_2 ;
unsigned long V_68 ;
V_2 = F_43 ( V_87 , struct V_1 , V_87 ) ;
if ( ! V_2 -> V_22 ) {
V_2 -> V_22 = F_75 ( V_2 -> V_83 , L_2 ) ;
if ( F_76 ( V_2 -> V_22 ) )
F_39 ( V_2 -> V_83 , L_3 ) ;
}
F_28 ( & V_2 -> V_72 , V_68 ) ;
F_10 ( V_2 , V_88 , V_18 ) ;
F_30 ( & V_2 -> V_72 , V_68 ) ;
return 0 ;
}
static void F_77 ( struct V_86 * V_87 , unsigned V_88 , int V_117 )
{
struct V_1 * V_2 ;
unsigned long V_68 ;
V_2 = F_43 ( V_87 , struct V_1 , V_87 ) ;
F_28 ( & V_2 -> V_72 , V_68 ) ;
V_2 -> V_11 ( V_2 , V_88 , V_117 ) ;
F_30 ( & V_2 -> V_72 , V_68 ) ;
}
static int F_78 ( struct V_86 * V_87 , unsigned V_88 )
{
struct V_1 * V_2 ;
V_2 = F_43 ( V_87 , struct V_1 , V_87 ) ;
return V_2 -> V_107 + V_88 ;
}
static void T_3 F_79 ( struct V_1 * V_2 )
{
static bool V_118 ;
T_2 V_119 ;
if ( V_118 || V_2 -> V_8 -> V_120 == V_121 )
return;
V_119 = F_80 ( V_2 -> V_6 + V_2 -> V_8 -> V_120 ) ;
F_81 ( L_4 ,
( V_119 >> 4 ) & 0x0f , V_119 & 0x0f ) ;
V_118 = true ;
}
static inline int F_82 ( struct V_110 * V_111 )
{
V_1 = F_83 ( V_122 * sizeof( struct V_1 ) ,
V_123 ) ;
if ( ! V_1 ) {
F_39 ( & V_111 -> V_83 , L_5 ) ;
return - V_124 ;
}
return 0 ;
}
static void F_84 ( struct V_1 * V_2 , int V_125 )
{
if ( F_25 () ) {
if ( F_14 () ) {
F_3 ( 0xffffffff , V_2 -> V_6 +
V_126 ) ;
F_3 ( 0x00000000 , V_2 -> V_6 +
V_127 ) ;
F_3 ( 0 , V_2 -> V_6 + V_93 ) ;
} else if ( F_16 () ) {
F_3 ( 0x00000000 , V_2 -> V_6 +
V_128 ) ;
F_3 ( 0xffffffff , V_2 -> V_6 +
V_129 ) ;
F_3 ( 0x00000000 , V_2 -> V_6 +
V_130 ) ;
F_3 ( 0 , V_2 -> V_6 + V_92 ) ;
} else if ( F_45 () ) {
static const T_2 V_37 [] = {
0xe203ffc0 , 0x08700040
} ;
if ( V_125 < F_85 ( V_37 ) )
V_2 -> V_37 = V_37 [ V_125 ] ;
}
} else if ( F_44 () ) {
if ( F_86 ( V_2 ) )
F_87 ( 0xffff , V_2 -> V_6 +
V_113 / V_2 -> V_47 ) ;
if ( F_53 () && V_2 -> V_44 == V_48 ) {
F_87 ( 0xffff , V_2 -> V_6
+ V_131 ) ;
F_87 ( 0x0000 , V_2 -> V_6
+ V_132 ) ;
}
if ( F_88 () && V_2 -> V_44 == V_57 ) {
F_87 ( 0x0000 , V_2 -> V_6
+ V_133 ) ;
F_87 ( 0xffff , V_2 -> V_6
+ V_134 ) ;
F_87 ( 0x0014 , V_2 -> V_6
+ V_135 ) ;
F_89 ( F_90 ( V_136 ) | 0x04 ,
V_136 ) ;
}
if ( F_91 () && V_2 -> V_44 == V_52 ) {
F_3 ( 0xffffffff , V_2 -> V_6
+ V_137 ) ;
F_3 ( 0x00000000 , V_2 -> V_6
+ V_138 ) ;
}
}
}
static T_3 void
F_92 ( struct V_1 * V_2 , unsigned int V_139 ,
unsigned int V_140 )
{
struct V_141 * V_142 ;
struct V_143 * V_144 ;
V_142 = F_93 ( L_6 , 1 , V_139 , V_2 -> V_6 ,
V_145 ) ;
if ( ! V_142 ) {
F_39 ( V_2 -> V_83 , L_7 ) ;
return;
}
V_144 = V_142 -> V_146 ;
V_144 -> V_87 . V_108 = V_147 ;
V_144 -> V_87 . V_148 = V_149 ;
V_144 -> V_87 . V_150 = F_24 ;
if ( F_88 () )
V_144 -> V_87 . V_151 = F_41 ,
V_144 -> V_8 . V_16 = V_152 / V_2 -> V_47 ;
F_94 ( V_142 , F_95 ( V_140 ) , V_153 ,
V_154 | V_155 , 0 ) ;
}
static void T_4 F_96 ( struct V_1 * V_2 )
{
int V_156 ;
static int V_3 ;
V_2 -> V_90 = 0 ;
V_2 -> V_87 . V_157 = F_42 ;
V_2 -> V_87 . free = F_46 ;
V_2 -> V_87 . V_158 = F_70 ;
V_2 -> V_87 . V_159 = F_72 ;
V_2 -> V_87 . V_160 = F_73 ;
V_2 -> V_87 . V_161 = F_74 ;
V_2 -> V_87 . V_17 = F_77 ;
V_2 -> V_87 . V_162 = F_78 ;
if ( F_86 ( V_2 ) ) {
V_2 -> V_87 . V_163 = L_8 ;
#ifdef F_22
V_2 -> V_87 . V_83 = & V_115 . V_83 ;
#endif
V_2 -> V_87 . V_6 = F_26 ( 0 ) ;
} else {
V_2 -> V_87 . V_163 = L_9 ;
V_2 -> V_87 . V_6 = V_3 ;
V_3 += V_2 -> V_78 ;
}
V_2 -> V_87 . V_164 = V_2 -> V_78 ;
F_97 ( & V_2 -> V_87 ) ;
for ( V_156 = V_2 -> V_107 ;
V_156 < V_2 -> V_107 + V_2 -> V_78 ; V_156 ++ ) {
F_98 ( V_156 , & V_165 ) ;
F_99 ( V_156 , V_2 ) ;
if ( F_86 ( V_2 ) ) {
F_92 ( V_2 , V_156 , V_2 -> V_78 ) ;
} else {
F_100 ( V_156 , & V_166 ) ;
F_101 ( V_156 , V_145 ) ;
F_102 ( V_156 , V_167 ) ;
}
}
F_103 ( V_2 -> V_69 , F_48 ) ;
F_104 ( V_2 -> V_69 , V_2 ) ;
}
static int T_4 F_105 ( struct V_110 * V_111 )
{
static int V_168 ;
struct V_169 * V_170 ;
struct V_171 * V_172 ;
int V_125 ;
struct V_1 * V_2 ;
if ( ! V_111 -> V_83 . V_173 )
return - V_64 ;
V_170 = V_111 -> V_83 . V_173 ;
if ( ! V_168 ) {
int V_174 ;
V_174 = F_82 ( V_111 ) ;
if ( V_174 )
return V_174 ;
}
V_125 = V_111 -> V_125 ;
V_2 = & V_1 [ V_125 ] ;
V_172 = F_106 ( V_111 , V_175 , 0 ) ;
if ( F_107 ( ! V_172 ) ) {
F_39 ( & V_111 -> V_83 , L_10 , V_125 ) ;
return - V_176 ;
}
V_2 -> V_69 = V_172 -> V_177 ;
V_2 -> V_107 = V_170 -> V_107 ;
V_2 -> V_44 = V_170 -> V_178 ;
V_2 -> V_83 = & V_111 -> V_83 ;
V_2 -> V_20 = V_170 -> V_20 ;
V_2 -> V_47 = V_170 -> V_179 ;
V_2 -> V_78 = V_170 -> V_180 ;
V_2 -> V_8 = V_170 -> V_8 ;
if ( V_2 -> V_8 -> V_11 && V_2 -> V_8 -> V_12 )
V_2 -> V_11 = F_4 ;
else
V_2 -> V_11 = F_6 ;
F_108 ( & V_2 -> V_72 ) ;
V_172 = F_106 ( V_111 , V_181 , 0 ) ;
if ( F_107 ( ! V_172 ) ) {
F_39 ( & V_111 -> V_83 , L_11 , V_125 ) ;
return - V_176 ;
}
V_2 -> V_6 = F_109 ( V_172 -> V_177 , F_110 ( V_172 ) ) ;
if ( ! V_2 -> V_6 ) {
F_39 ( & V_111 -> V_83 , L_12 , V_125 ) ;
return - V_124 ;
}
F_111 ( V_2 -> V_83 ) ;
F_112 ( V_2 -> V_83 ) ;
F_84 ( V_2 , V_125 ) ;
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
for ( V_182 = 0 ; V_182 < V_122 ; V_182 ++ ) {
struct V_1 * V_2 = & V_1 [ V_182 ] ;
void T_1 * V_183 ;
void T_1 * V_184 ;
void T_1 * V_185 ;
unsigned long V_68 ;
switch ( V_2 -> V_44 ) {
#ifdef F_22
case V_57 :
V_183 = V_2 -> V_6 + V_186 ;
V_184 = V_2 -> V_6 + V_61 ;
V_185 = V_2 -> V_6 + V_60 ;
break;
#endif
#if F_19 ( V_94 ) || F_19 ( V_95 )
case V_62 :
V_183 = V_2 -> V_6 + V_187 ;
V_184 = V_2 -> V_6 + V_41 ;
V_185 = V_2 -> V_6 + V_40 ;
break;
#endif
#ifdef F_47
case V_63 :
V_183 = V_2 -> V_6 + V_38 ;
V_184 = V_2 -> V_6 + V_38 ;
V_185 = V_2 -> V_6 + V_38 ;
break;
#endif
default:
continue;
}
F_28 ( & V_2 -> V_72 , V_68 ) ;
V_2 -> V_114 = F_2 ( V_183 ) ;
F_3 ( 0xffffffff , V_184 ) ;
F_3 ( V_2 -> V_84 , V_185 ) ;
F_30 ( & V_2 -> V_72 , V_68 ) ;
}
return 0 ;
}
static void F_114 ( void )
{
int V_182 ;
if ( ! F_25 () && ! F_88 () )
return;
for ( V_182 = 0 ; V_182 < V_122 ; V_182 ++ ) {
struct V_1 * V_2 = & V_1 [ V_182 ] ;
void T_1 * V_184 ;
void T_1 * V_185 ;
unsigned long V_68 ;
switch ( V_2 -> V_44 ) {
#ifdef F_22
case V_57 :
V_184 = V_2 -> V_6 + V_61 ;
V_185 = V_2 -> V_6 + V_60 ;
break;
#endif
#if F_19 ( V_94 ) || F_19 ( V_95 )
case V_62 :
V_184 = V_2 -> V_6 + V_41 ;
V_185 = V_2 -> V_6 + V_40 ;
break;
#endif
#ifdef F_47
case V_63 :
V_184 = V_2 -> V_6 + V_38 ;
V_185 = V_2 -> V_6 + V_38 ;
break;
#endif
default:
continue;
}
F_28 ( & V_2 -> V_72 , V_68 ) ;
F_3 ( 0xffffffff , V_184 ) ;
F_3 ( V_2 -> V_114 , V_185 ) ;
F_30 ( & V_2 -> V_72 , V_68 ) ;
}
}
void F_115 ( int V_188 )
{
int V_182 , V_189 = 0 ;
int V_190 = 0 ;
if ( F_16 () )
V_190 = 1 ;
for ( V_182 = V_190 ; V_182 < V_122 ; V_182 ++ ) {
struct V_1 * V_2 = & V_1 [ V_182 ] ;
T_2 V_191 = 0 , V_192 = 0 ;
int V_156 ;
for ( V_156 = 0 ; V_156 < F_116 ( V_2 -> V_23 ) ; V_156 ++ )
F_12 ( V_2 -> V_22 ) ;
if ( ! V_188 )
continue;
if ( ! ( V_2 -> V_42 ) )
continue;
if ( F_45 () || F_16 () ) {
V_2 -> V_193 = F_2 ( V_2 -> V_6 +
V_194 ) ;
V_191 = F_2 ( V_2 -> V_6 +
V_36 ) ;
V_192 = F_2 ( V_2 -> V_6 +
V_35 ) ;
}
if ( F_14 () ) {
V_2 -> V_193 = F_2 ( V_2 -> V_6 +
V_195 ) ;
V_191 = F_2 ( V_2 -> V_6 +
V_31 ) ;
V_192 = F_2 ( V_2 -> V_6 +
V_29 ) ;
}
V_2 -> V_196 = V_191 ;
V_2 -> V_197 = V_192 ;
V_191 &= ~ V_2 -> V_42 ;
V_192 &= ~ V_2 -> V_42 ;
if ( F_45 () || F_16 () ) {
F_3 ( V_191 , V_2 -> V_6 +
V_36 ) ;
F_3 ( V_192 , V_2 -> V_6 +
V_35 ) ;
}
if ( F_14 () ) {
F_3 ( V_191 , V_2 -> V_6 + V_31 ) ;
F_3 ( V_192 , V_2 -> V_6 + V_29 ) ;
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
for ( V_182 = V_190 ; V_182 < V_122 ; V_182 ++ ) {
struct V_1 * V_2 = & V_1 [ V_182 ] ;
T_2 V_7 = 0 , V_199 , V_200 , V_201 ;
int V_156 ;
for ( V_156 = 0 ; V_156 < F_116 ( V_2 -> V_23 ) ; V_156 ++ )
F_11 ( V_2 -> V_22 ) ;
if ( ! V_198 )
continue;
if ( ! ( V_2 -> V_42 ) )
continue;
if ( F_45 () || F_16 () ) {
F_3 ( V_2 -> V_196 ,
V_2 -> V_6 + V_36 ) ;
F_3 ( V_2 -> V_197 ,
V_2 -> V_6 + V_35 ) ;
V_7 = F_2 ( V_2 -> V_6 + V_194 ) ;
}
if ( F_14 () ) {
F_3 ( V_2 -> V_196 ,
V_2 -> V_6 + V_31 ) ;
F_3 ( V_2 -> V_197 ,
V_2 -> V_6 + V_29 ) ;
V_7 = F_2 ( V_2 -> V_6 + V_195 ) ;
}
V_7 ^= V_2 -> V_193 ;
V_7 &= V_2 -> V_42 ;
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
V_33 ) ;
V_203 = F_2 ( V_2 -> V_6 +
V_34 ) ;
F_3 ( V_202 | V_199 , V_2 -> V_6 +
V_33 ) ;
F_3 ( V_203 | V_199 , V_2 -> V_6 +
V_34 ) ;
F_3 ( V_202 , V_2 -> V_6 +
V_33 ) ;
F_3 ( V_203 , V_2 -> V_6 +
V_34 ) ;
}
if ( F_14 () ) {
V_202 = F_2 ( V_2 -> V_6 +
V_25 ) ;
V_203 = F_2 ( V_2 -> V_6 +
V_27 ) ;
F_3 ( V_202 | V_7 , V_2 -> V_6 +
V_25 ) ;
F_3 ( V_203 | V_7 , V_2 -> V_6 +
V_27 ) ;
F_3 ( V_202 , V_2 -> V_6 +
V_25 ) ;
F_3 ( V_203 , V_2 -> V_6 +
V_27 ) ;
}
}
}
}
void F_118 ( void )
{
int V_182 ;
for ( V_182 = 1 ; V_182 < V_122 ; V_182 ++ ) {
struct V_1 * V_2 = & V_1 [ V_182 ] ;
V_204 [ V_182 ] . V_205 =
F_2 ( V_2 -> V_6 + V_128 ) ;
V_204 [ V_182 ] . V_206 =
F_2 ( V_2 -> V_6 + V_207 ) ;
V_204 [ V_182 ] . V_208 =
F_2 ( V_2 -> V_6 + V_187 ) ;
V_204 [ V_182 ] . V_91 =
F_2 ( V_2 -> V_6 + V_92 ) ;
V_204 [ V_182 ] . V_209 =
F_2 ( V_2 -> V_6 + V_210 ) ;
V_204 [ V_182 ] . V_211 =
F_2 ( V_2 -> V_6 + V_33 ) ;
V_204 [ V_182 ] . V_212 =
F_2 ( V_2 -> V_6 + V_34 ) ;
V_204 [ V_182 ] . V_213 =
F_2 ( V_2 -> V_6 + V_35 ) ;
V_204 [ V_182 ] . V_214 =
F_2 ( V_2 -> V_6 + V_36 ) ;
V_204 [ V_182 ] . V_13 =
F_2 ( V_2 -> V_6 + V_215 ) ;
}
}
void F_119 ( void )
{
int V_182 ;
for ( V_182 = 1 ; V_182 < V_122 ; V_182 ++ ) {
struct V_1 * V_2 = & V_1 [ V_182 ] ;
F_3 ( V_204 [ V_182 ] . V_205 ,
V_2 -> V_6 + V_128 ) ;
F_3 ( V_204 [ V_182 ] . V_206 ,
V_2 -> V_6 + V_207 ) ;
F_3 ( V_204 [ V_182 ] . V_208 ,
V_2 -> V_6 + V_187 ) ;
F_3 ( V_204 [ V_182 ] . V_91 ,
V_2 -> V_6 + V_92 ) ;
F_3 ( V_204 [ V_182 ] . V_209 ,
V_2 -> V_6 + V_210 ) ;
F_3 ( V_204 [ V_182 ] . V_211 ,
V_2 -> V_6 + V_33 ) ;
F_3 ( V_204 [ V_182 ] . V_212 ,
V_2 -> V_6 + V_34 ) ;
F_3 ( V_204 [ V_182 ] . V_213 ,
V_2 -> V_6 + V_35 ) ;
F_3 ( V_204 [ V_182 ] . V_214 ,
V_2 -> V_6 + V_36 ) ;
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
