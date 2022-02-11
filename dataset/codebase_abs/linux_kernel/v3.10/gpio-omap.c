static int F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
return V_2 -> V_4 . V_5 + V_3 ;
}
static int F_2 ( struct V_6 * V_4 , unsigned V_7 )
{
struct V_1 * V_2 = F_3 ( V_4 , struct V_1 , V_4 ) ;
return F_4 ( V_2 -> V_8 , V_7 ) ;
}
static void F_5 ( struct V_1 * V_2 , int V_9 , int V_10 )
{
void T_1 * V_11 = V_2 -> V_5 ;
T_2 V_12 ;
V_11 += V_2 -> V_13 -> V_14 ;
V_12 = F_6 ( V_11 ) ;
if ( V_10 )
V_12 |= 1 << V_9 ;
else
V_12 &= ~ ( 1 << V_9 ) ;
F_7 ( V_12 , V_11 ) ;
V_2 -> V_15 . V_16 = V_12 ;
}
static void F_8 ( struct V_1 * V_2 , int V_9 , int V_17 )
{
void T_1 * V_11 = V_2 -> V_5 ;
T_2 V_12 = F_9 ( V_2 , V_9 ) ;
if ( V_17 ) {
V_11 += V_2 -> V_13 -> V_18 ;
V_2 -> V_15 . V_19 |= V_12 ;
} else {
V_11 += V_2 -> V_13 -> V_20 ;
V_2 -> V_15 . V_19 &= ~ V_12 ;
}
F_7 ( V_12 , V_11 ) ;
}
static void F_10 ( struct V_1 * V_2 , int V_9 , int V_17 )
{
void T_1 * V_11 = V_2 -> V_5 + V_2 -> V_13 -> V_19 ;
T_2 V_21 = F_9 ( V_2 , V_9 ) ;
T_2 V_12 ;
V_12 = F_6 ( V_11 ) ;
if ( V_17 )
V_12 |= V_21 ;
else
V_12 &= ~ V_21 ;
F_7 ( V_12 , V_11 ) ;
V_2 -> V_15 . V_19 = V_12 ;
}
static int F_11 ( struct V_1 * V_2 , int V_7 )
{
void T_1 * V_11 = V_2 -> V_5 + V_2 -> V_13 -> V_22 ;
return ( F_6 ( V_11 ) & ( 1 << V_7 ) ) != 0 ;
}
static int F_12 ( struct V_1 * V_2 , int V_7 )
{
void T_1 * V_11 = V_2 -> V_5 + V_2 -> V_13 -> V_19 ;
return ( F_6 ( V_11 ) & ( 1 << V_7 ) ) != 0 ;
}
static inline void F_13 ( void T_1 * V_5 , T_2 V_11 , T_2 V_23 , bool V_24 )
{
int V_12 = F_6 ( V_5 + V_11 ) ;
if ( V_24 )
V_12 |= V_23 ;
else
V_12 &= ~ V_23 ;
F_7 ( V_12 , V_5 + V_11 ) ;
}
static inline void F_14 ( struct V_1 * V_2 )
{
if ( V_2 -> V_25 && ! V_2 -> V_26 ) {
F_15 ( V_2 -> V_27 ) ;
V_2 -> V_26 = true ;
F_7 ( V_2 -> V_25 ,
V_2 -> V_5 + V_2 -> V_13 -> V_28 ) ;
}
}
static inline void F_16 ( struct V_1 * V_2 )
{
if ( V_2 -> V_25 && V_2 -> V_26 ) {
F_7 ( 0 , V_2 -> V_5 + V_2 -> V_13 -> V_28 ) ;
F_17 ( V_2 -> V_27 ) ;
V_2 -> V_26 = false ;
}
}
static void F_18 ( struct V_1 * V_2 , unsigned V_9 ,
unsigned V_29 )
{
void T_1 * V_11 ;
T_2 V_30 ;
T_2 V_12 ;
if ( ! V_2 -> V_31 )
return;
if ( V_29 < 32 )
V_29 = 0x01 ;
else if ( V_29 > 7936 )
V_29 = 0xff ;
else
V_29 = ( V_29 / 0x1f ) - 1 ;
V_12 = F_9 ( V_2 , V_9 ) ;
F_15 ( V_2 -> V_27 ) ;
V_11 = V_2 -> V_5 + V_2 -> V_13 -> V_29 ;
F_7 ( V_29 , V_11 ) ;
V_11 = V_2 -> V_5 + V_2 -> V_13 -> V_28 ;
V_30 = F_6 ( V_11 ) ;
if ( V_29 )
V_30 |= V_12 ;
else
V_30 &= ~ V_12 ;
V_2 -> V_25 = V_30 ;
F_7 ( V_30 , V_11 ) ;
F_17 ( V_2 -> V_27 ) ;
F_14 ( V_2 ) ;
if ( V_2 -> V_25 ) {
V_2 -> V_15 . V_29 = V_29 ;
V_2 -> V_15 . V_28 = V_30 ;
}
}
static void F_19 ( struct V_1 * V_2 , unsigned V_9 )
{
T_2 V_21 = F_9 ( V_2 , V_9 ) ;
if ( ! V_2 -> V_31 )
return;
if ( ! ( V_2 -> V_25 & V_21 ) )
return;
V_2 -> V_25 &= ~ V_21 ;
V_2 -> V_15 . V_28 &= ~ V_21 ;
F_7 ( V_2 -> V_15 . V_28 ,
V_2 -> V_5 + V_2 -> V_13 -> V_28 ) ;
if ( ! V_2 -> V_25 ) {
V_2 -> V_15 . V_29 = 0 ;
F_7 ( V_2 -> V_15 . V_29 , V_2 -> V_5 +
V_2 -> V_13 -> V_29 ) ;
F_17 ( V_2 -> V_27 ) ;
V_2 -> V_26 = false ;
}
}
static inline void F_20 ( struct V_1 * V_2 , int V_9 ,
unsigned V_32 )
{
void T_1 * V_5 = V_2 -> V_5 ;
T_2 V_21 = 1 << V_9 ;
F_13 ( V_5 , V_2 -> V_13 -> V_33 , V_21 ,
V_32 & V_34 ) ;
F_13 ( V_5 , V_2 -> V_13 -> V_35 , V_21 ,
V_32 & V_36 ) ;
F_13 ( V_5 , V_2 -> V_13 -> V_37 , V_21 ,
V_32 & V_38 ) ;
F_13 ( V_5 , V_2 -> V_13 -> V_39 , V_21 ,
V_32 & V_40 ) ;
V_2 -> V_15 . V_33 =
F_6 ( V_2 -> V_5 + V_2 -> V_13 -> V_33 ) ;
V_2 -> V_15 . V_35 =
F_6 ( V_2 -> V_5 + V_2 -> V_13 -> V_35 ) ;
V_2 -> V_15 . V_37 =
F_6 ( V_2 -> V_5 + V_2 -> V_13 -> V_37 ) ;
V_2 -> V_15 . V_39 =
F_6 ( V_2 -> V_5 + V_2 -> V_13 -> V_39 ) ;
if ( F_21 ( ! ( V_2 -> V_41 & V_21 ) ) ) {
F_13 ( V_5 , V_2 -> V_13 -> V_42 , V_21 , V_32 != 0 ) ;
V_2 -> V_15 . V_43 =
F_6 ( V_2 -> V_5 + V_2 -> V_13 -> V_42 ) ;
}
if ( ! V_2 -> V_13 -> V_44 ) {
if ( V_2 -> V_41 ) {
if ( ! ( V_2 -> V_41 & V_21 ) )
goto exit;
}
if ( V_32 & V_45 )
V_2 -> V_46 |= V_21 ;
else
V_2 -> V_46 &= ~ V_21 ;
}
exit:
V_2 -> V_47 =
F_6 ( V_2 -> V_5 + V_2 -> V_13 -> V_33 ) |
F_6 ( V_2 -> V_5 + V_2 -> V_13 -> V_35 ) ;
}
static void F_22 ( struct V_1 * V_2 , int V_9 )
{
void T_1 * V_11 = V_2 -> V_5 ;
T_2 V_12 = 0 ;
if ( ! V_2 -> V_13 -> V_44 )
return;
V_11 += V_2 -> V_13 -> V_44 ;
V_12 = F_6 ( V_11 ) ;
if ( ( V_12 >> V_9 ) & 1 )
V_12 &= ~ ( 1 << V_9 ) ;
else
V_12 |= 1 << V_9 ;
F_7 ( V_12 , V_11 ) ;
}
static void F_22 ( struct V_1 * V_2 , int V_9 ) {}
static int F_23 ( struct V_1 * V_2 , int V_9 ,
unsigned V_32 )
{
void T_1 * V_11 = V_2 -> V_5 ;
void T_1 * V_5 = V_2 -> V_5 ;
T_2 V_12 = 0 ;
if ( V_2 -> V_13 -> V_33 && V_2 -> V_13 -> V_42 ) {
F_20 ( V_2 , V_9 , V_32 ) ;
} else if ( V_2 -> V_13 -> V_44 ) {
V_11 += V_2 -> V_13 -> V_44 ;
V_12 = F_6 ( V_11 ) ;
if ( ( V_32 & V_48 ) == V_45 )
V_2 -> V_49 |= 1 << V_9 ;
if ( V_32 & V_38 )
V_12 |= 1 << V_9 ;
else if ( V_32 & V_40 )
V_12 &= ~ ( 1 << V_9 ) ;
else
return - V_50 ;
F_7 ( V_12 , V_11 ) ;
} else if ( V_2 -> V_13 -> V_51 ) {
if ( V_9 & 0x08 )
V_11 += V_2 -> V_13 -> V_52 ;
else
V_11 += V_2 -> V_13 -> V_51 ;
V_9 &= 0x07 ;
V_12 = F_6 ( V_11 ) ;
V_12 &= ~ ( 3 << ( V_9 << 1 ) ) ;
if ( V_32 & V_38 )
V_12 |= 2 << ( V_9 << 1 ) ;
if ( V_32 & V_40 )
V_12 |= 1 << ( V_9 << 1 ) ;
F_13 ( V_5 , V_2 -> V_13 -> V_42 , 1 << V_9 , V_32 ) ;
V_2 -> V_15 . V_43 =
F_6 ( V_2 -> V_5 + V_2 -> V_13 -> V_42 ) ;
F_7 ( V_12 , V_11 ) ;
}
return 0 ;
}
static int F_24 ( struct V_53 * V_54 , unsigned type )
{
struct V_1 * V_2 = F_25 ( V_54 ) ;
unsigned V_9 = 0 ;
int V_55 ;
unsigned long V_56 ;
if ( F_26 ( ! V_2 -> V_57 ) )
return - V_50 ;
#ifdef F_27
if ( V_54 -> V_58 > V_59 )
V_9 = F_28 ( V_54 -> V_58 - V_59 ) ;
#endif
if ( ! V_9 )
V_9 = F_1 ( V_2 , V_54 -> V_60 ) ;
if ( type & ~ V_48 )
return - V_50 ;
if ( ! V_2 -> V_13 -> V_33 &&
( type & ( V_34 | V_36 ) ) )
return - V_50 ;
F_29 ( & V_2 -> V_61 , V_56 ) ;
V_55 = F_23 ( V_2 , F_30 ( V_2 , V_9 ) , type ) ;
F_31 ( & V_2 -> V_61 , V_56 ) ;
if ( type & ( V_34 | V_36 ) )
F_32 ( V_54 -> V_58 , V_62 ) ;
else if ( type & ( V_40 | V_38 ) )
F_32 ( V_54 -> V_58 , V_63 ) ;
return V_55 ;
}
static void F_33 ( struct V_1 * V_2 , int V_64 )
{
void T_1 * V_11 = V_2 -> V_5 ;
V_11 += V_2 -> V_13 -> V_65 ;
F_7 ( V_64 , V_11 ) ;
if ( V_2 -> V_13 -> V_66 ) {
V_11 = V_2 -> V_5 + V_2 -> V_13 -> V_66 ;
F_7 ( V_64 , V_11 ) ;
}
F_6 ( V_11 ) ;
}
static inline void F_34 ( struct V_1 * V_2 , int V_9 )
{
F_33 ( V_2 , F_9 ( V_2 , V_9 ) ) ;
}
static T_2 F_35 ( struct V_1 * V_2 )
{
void T_1 * V_11 = V_2 -> V_5 ;
T_2 V_12 ;
T_2 V_23 = ( 1 << V_2 -> V_67 ) - 1 ;
V_11 += V_2 -> V_13 -> V_68 ;
V_12 = F_6 ( V_11 ) ;
if ( V_2 -> V_13 -> V_69 )
V_12 = ~ V_12 ;
V_12 &= V_23 ;
return V_12 ;
}
static void F_36 ( struct V_1 * V_2 , int V_64 )
{
void T_1 * V_11 = V_2 -> V_5 ;
T_2 V_12 ;
if ( V_2 -> V_13 -> V_70 ) {
V_11 += V_2 -> V_13 -> V_70 ;
V_12 = V_64 ;
V_2 -> V_15 . V_71 |= V_64 ;
} else {
V_11 += V_2 -> V_13 -> V_68 ;
V_12 = F_6 ( V_11 ) ;
if ( V_2 -> V_13 -> V_69 )
V_12 &= ~ V_64 ;
else
V_12 |= V_64 ;
V_2 -> V_15 . V_71 = V_12 ;
}
F_7 ( V_12 , V_11 ) ;
}
static void F_37 ( struct V_1 * V_2 , int V_64 )
{
void T_1 * V_11 = V_2 -> V_5 ;
T_2 V_12 ;
if ( V_2 -> V_13 -> V_72 ) {
V_11 += V_2 -> V_13 -> V_72 ;
V_12 = V_64 ;
V_2 -> V_15 . V_71 &= ~ V_64 ;
} else {
V_11 += V_2 -> V_13 -> V_68 ;
V_12 = F_6 ( V_11 ) ;
if ( V_2 -> V_13 -> V_69 )
V_12 |= V_64 ;
else
V_12 &= ~ V_64 ;
V_2 -> V_15 . V_71 = V_12 ;
}
F_7 ( V_12 , V_11 ) ;
}
static inline void F_38 ( struct V_1 * V_2 , int V_9 , int V_17 )
{
if ( V_17 )
F_36 ( V_2 , F_9 ( V_2 , V_9 ) ) ;
else
F_37 ( V_2 , F_9 ( V_2 , V_9 ) ) ;
}
static int F_39 ( struct V_1 * V_2 , int V_9 , int V_17 )
{
T_2 V_21 = F_9 ( V_2 , V_9 ) ;
unsigned long V_56 ;
if ( V_2 -> V_41 & V_21 ) {
F_40 ( V_2 -> V_73 ,
L_1 , V_9 ) ;
return - V_50 ;
}
F_29 ( & V_2 -> V_61 , V_56 ) ;
if ( V_17 )
V_2 -> V_15 . V_43 |= V_21 ;
else
V_2 -> V_15 . V_43 &= ~ V_21 ;
F_7 ( V_2 -> V_15 . V_43 , V_2 -> V_5 + V_2 -> V_13 -> V_42 ) ;
F_31 ( & V_2 -> V_61 , V_56 ) ;
return 0 ;
}
static void F_41 ( struct V_1 * V_2 , int V_9 )
{
F_5 ( V_2 , F_30 ( V_2 , V_9 ) , 1 ) ;
F_38 ( V_2 , V_9 , 0 ) ;
F_34 ( V_2 , V_9 ) ;
F_23 ( V_2 , F_30 ( V_2 , V_9 ) , V_74 ) ;
F_19 ( V_2 , V_9 ) ;
}
static int F_42 ( struct V_53 * V_54 , unsigned int V_17 )
{
struct V_1 * V_2 = F_25 ( V_54 ) ;
unsigned int V_9 = F_1 ( V_2 , V_54 -> V_60 ) ;
return F_39 ( V_2 , V_9 , V_17 ) ;
}
static int F_43 ( struct V_6 * V_4 , unsigned V_7 )
{
struct V_1 * V_2 = F_3 ( V_4 , struct V_1 , V_4 ) ;
unsigned long V_56 ;
if ( ! V_2 -> V_57 )
F_44 ( V_2 -> V_73 ) ;
F_29 ( & V_2 -> V_61 , V_56 ) ;
F_23 ( V_2 , V_7 , V_74 ) ;
if ( V_2 -> V_13 -> V_75 ) {
void T_1 * V_11 = V_2 -> V_5 + V_2 -> V_13 -> V_75 ;
F_7 ( F_6 ( V_11 ) | ( 1 << V_7 ) , V_11 ) ;
}
if ( V_2 -> V_13 -> V_76 && ! V_2 -> V_57 ) {
void T_1 * V_11 = V_2 -> V_5 + V_2 -> V_13 -> V_76 ;
T_2 V_76 ;
V_76 = F_6 ( V_11 ) ;
V_76 &= ~ V_77 ;
F_7 ( V_76 , V_11 ) ;
V_2 -> V_15 . V_76 = V_76 ;
}
V_2 -> V_57 |= 1 << V_7 ;
F_31 ( & V_2 -> V_61 , V_56 ) ;
return 0 ;
}
static void F_45 ( struct V_6 * V_4 , unsigned V_7 )
{
struct V_1 * V_2 = F_3 ( V_4 , struct V_1 , V_4 ) ;
void T_1 * V_5 = V_2 -> V_5 ;
unsigned long V_56 ;
F_29 ( & V_2 -> V_61 , V_56 ) ;
if ( V_2 -> V_13 -> V_42 ) {
F_13 ( V_5 , V_2 -> V_13 -> V_42 , 1 << V_7 , 0 ) ;
V_2 -> V_15 . V_43 =
F_6 ( V_2 -> V_5 + V_2 -> V_13 -> V_42 ) ;
}
V_2 -> V_57 &= ~ ( 1 << V_7 ) ;
if ( V_2 -> V_13 -> V_76 && ! V_2 -> V_57 ) {
void T_1 * V_11 = V_2 -> V_5 + V_2 -> V_13 -> V_76 ;
T_2 V_76 ;
V_76 = F_6 ( V_11 ) ;
V_76 |= V_77 ;
F_7 ( V_76 , V_11 ) ;
V_2 -> V_15 . V_76 = V_76 ;
}
F_41 ( V_2 , V_2 -> V_4 . V_5 + V_7 ) ;
F_31 ( & V_2 -> V_61 , V_56 ) ;
if ( ! V_2 -> V_57 )
F_46 ( V_2 -> V_73 ) ;
}
static void F_47 ( unsigned int V_58 , struct V_78 * V_79 )
{
void T_1 * V_80 = NULL ;
T_2 V_81 ;
unsigned int V_82 ;
struct V_1 * V_2 ;
int V_83 = 0 ;
struct V_84 * V_4 = F_48 ( V_79 ) ;
F_49 ( V_4 , V_79 ) ;
V_2 = F_50 ( V_58 ) ;
V_80 = V_2 -> V_5 + V_2 -> V_13 -> V_65 ;
F_44 ( V_2 -> V_73 ) ;
if ( F_26 ( ! V_80 ) )
goto exit;
while ( 1 ) {
T_2 V_85 , V_47 = 0 ;
T_2 V_86 ;
V_86 = F_35 ( V_2 ) ;
V_85 = V_81 = F_6 ( V_80 ) & V_86 ;
if ( V_2 -> V_47 )
V_47 = V_2 -> V_47 & V_86 ;
F_37 ( V_2 , V_85 & ~ V_47 ) ;
F_33 ( V_2 , V_85 & ~ V_47 ) ;
F_36 ( V_2 , V_85 & ~ V_47 ) ;
if ( ! V_47 && ! V_83 ) {
V_83 = 1 ;
F_51 ( V_4 , V_79 ) ;
}
if ( ! V_81 )
break;
while ( V_81 ) {
V_82 = F_52 ( V_81 ) ;
V_81 &= ~ ( 1 << V_82 ) ;
if ( V_2 -> V_49 & ( 1 << V_82 ) )
F_22 ( V_2 , V_82 ) ;
F_53 ( F_4 ( V_2 -> V_8 , V_82 ) ) ;
}
}
exit:
if ( ! V_83 )
F_51 ( V_4 , V_79 ) ;
F_46 ( V_2 -> V_73 ) ;
}
static void F_54 ( struct V_53 * V_54 )
{
struct V_1 * V_2 = F_25 ( V_54 ) ;
unsigned int V_9 = F_1 ( V_2 , V_54 -> V_60 ) ;
unsigned long V_56 ;
F_29 ( & V_2 -> V_61 , V_56 ) ;
F_41 ( V_2 , V_9 ) ;
F_31 ( & V_2 -> V_61 , V_56 ) ;
}
static void F_55 ( struct V_53 * V_54 )
{
struct V_1 * V_2 = F_25 ( V_54 ) ;
unsigned int V_9 = F_1 ( V_2 , V_54 -> V_60 ) ;
F_34 ( V_2 , V_9 ) ;
}
static void F_56 ( struct V_53 * V_54 )
{
struct V_1 * V_2 = F_25 ( V_54 ) ;
unsigned int V_9 = F_1 ( V_2 , V_54 -> V_60 ) ;
unsigned long V_56 ;
F_29 ( & V_2 -> V_61 , V_56 ) ;
F_38 ( V_2 , V_9 , 0 ) ;
F_23 ( V_2 , F_30 ( V_2 , V_9 ) , V_74 ) ;
F_31 ( & V_2 -> V_61 , V_56 ) ;
}
static void F_57 ( struct V_53 * V_54 )
{
struct V_1 * V_2 = F_25 ( V_54 ) ;
unsigned int V_9 = F_1 ( V_2 , V_54 -> V_60 ) ;
unsigned int V_87 = F_9 ( V_2 , V_9 ) ;
T_2 V_32 = F_58 ( V_54 ) ;
unsigned long V_56 ;
F_29 ( & V_2 -> V_61 , V_56 ) ;
if ( V_32 )
F_23 ( V_2 , F_30 ( V_2 , V_9 ) , V_32 ) ;
if ( V_2 -> V_47 & V_87 ) {
F_38 ( V_2 , V_9 , 0 ) ;
F_34 ( V_2 , V_9 ) ;
}
F_38 ( V_2 , V_9 , 1 ) ;
F_31 ( & V_2 -> V_61 , V_56 ) ;
}
static int F_59 ( struct V_88 * V_73 )
{
struct V_89 * V_90 = F_60 ( V_73 ) ;
struct V_1 * V_2 = F_61 ( V_90 ) ;
void T_1 * V_91 = V_2 -> V_5 +
V_92 / V_2 -> V_93 ;
unsigned long V_56 ;
F_29 ( & V_2 -> V_61 , V_56 ) ;
F_7 ( 0xffff & ~ V_2 -> V_15 . V_43 , V_91 ) ;
F_31 ( & V_2 -> V_61 , V_56 ) ;
return 0 ;
}
static int F_62 ( struct V_88 * V_73 )
{
struct V_89 * V_90 = F_60 ( V_73 ) ;
struct V_1 * V_2 = F_61 ( V_90 ) ;
void T_1 * V_91 = V_2 -> V_5 +
V_92 / V_2 -> V_93 ;
unsigned long V_56 ;
F_29 ( & V_2 -> V_61 , V_56 ) ;
F_7 ( V_2 -> V_15 . V_43 , V_91 ) ;
F_31 ( & V_2 -> V_61 , V_56 ) ;
return 0 ;
}
static inline void F_63 ( struct V_1 * V_2 )
{
F_64 ( & V_94 , V_2 ) ;
if ( F_65 ( & V_95 ) == 0 )
( void ) F_66 ( & V_94 ) ;
}
static int F_67 ( struct V_6 * V_4 , unsigned V_7 )
{
struct V_1 * V_2 ;
unsigned long V_56 ;
V_2 = F_3 ( V_4 , struct V_1 , V_4 ) ;
F_29 ( & V_2 -> V_61 , V_56 ) ;
F_5 ( V_2 , V_7 , 1 ) ;
F_31 ( & V_2 -> V_61 , V_56 ) ;
return 0 ;
}
static int F_68 ( struct V_1 * V_2 , int V_23 )
{
void T_1 * V_11 = V_2 -> V_5 + V_2 -> V_13 -> V_14 ;
return F_6 ( V_11 ) & V_23 ;
}
static int F_69 ( struct V_6 * V_4 , unsigned V_7 )
{
struct V_1 * V_2 ;
T_2 V_23 ;
V_2 = F_3 ( V_4 , struct V_1 , V_4 ) ;
V_23 = ( 1 << V_7 ) ;
if ( F_68 ( V_2 , V_23 ) )
return F_11 ( V_2 , V_7 ) ;
else
return F_12 ( V_2 , V_7 ) ;
}
static int F_70 ( struct V_6 * V_4 , unsigned V_7 , int V_96 )
{
struct V_1 * V_2 ;
unsigned long V_56 ;
V_2 = F_3 ( V_4 , struct V_1 , V_4 ) ;
F_29 ( & V_2 -> V_61 , V_56 ) ;
V_2 -> V_18 ( V_2 , V_7 , V_96 ) ;
F_5 ( V_2 , V_7 , 0 ) ;
F_31 ( & V_2 -> V_61 , V_56 ) ;
return 0 ;
}
static int F_71 ( struct V_6 * V_4 , unsigned V_7 ,
unsigned V_29 )
{
struct V_1 * V_2 ;
unsigned long V_56 ;
V_2 = F_3 ( V_4 , struct V_1 , V_4 ) ;
F_29 ( & V_2 -> V_61 , V_56 ) ;
F_18 ( V_2 , V_7 , V_29 ) ;
F_31 ( & V_2 -> V_61 , V_56 ) ;
return 0 ;
}
static void F_72 ( struct V_6 * V_4 , unsigned V_7 , int V_96 )
{
struct V_1 * V_2 ;
unsigned long V_56 ;
V_2 = F_3 ( V_4 , struct V_1 , V_4 ) ;
F_29 ( & V_2 -> V_61 , V_56 ) ;
V_2 -> V_18 ( V_2 , V_7 , V_96 ) ;
F_31 ( & V_2 -> V_61 , V_56 ) ;
}
static void T_3 F_73 ( struct V_1 * V_2 )
{
static bool V_97 ;
T_2 V_98 ;
if ( V_97 || V_2 -> V_13 -> V_99 == V_100 )
return;
V_98 = F_74 ( V_2 -> V_5 + V_2 -> V_13 -> V_99 ) ;
F_75 ( L_2 ,
( V_98 >> 4 ) & 0x0f , V_98 & 0x0f ) ;
V_97 = true ;
}
static void F_76 ( struct V_1 * V_2 )
{
void T_1 * V_5 = V_2 -> V_5 ;
T_2 V_12 = 0xffffffff ;
if ( V_2 -> V_67 == 16 )
V_12 = 0xffff ;
if ( V_2 -> V_101 ) {
F_7 ( V_12 , V_2 -> V_5 + V_2 -> V_13 -> V_68 ) ;
return;
}
F_13 ( V_5 , V_2 -> V_13 -> V_68 , V_12 , V_2 -> V_13 -> V_69 ) ;
F_13 ( V_5 , V_2 -> V_13 -> V_65 , V_12 , ! V_2 -> V_13 -> V_69 ) ;
if ( V_2 -> V_13 -> V_28 )
F_7 ( 0 , V_5 + V_2 -> V_13 -> V_28 ) ;
V_2 -> V_15 . V_16 = F_6 ( V_2 -> V_5 + V_2 -> V_13 -> V_14 ) ;
if ( V_2 -> V_13 -> V_76 )
F_7 ( 0 , V_5 + V_2 -> V_13 -> V_76 ) ;
V_2 -> V_27 = F_77 ( V_2 -> V_73 , L_3 ) ;
if ( F_78 ( V_2 -> V_27 ) )
F_40 ( V_2 -> V_73 , L_4 ) ;
}
static void
F_79 ( struct V_1 * V_2 , unsigned int V_102 ,
unsigned int V_103 )
{
struct V_104 * V_105 ;
struct V_106 * V_107 ;
V_105 = F_80 ( L_5 , 1 , V_102 , V_2 -> V_5 ,
V_108 ) ;
if ( ! V_105 ) {
F_40 ( V_2 -> V_73 , L_6 ) ;
return;
}
V_107 = V_105 -> V_109 ;
V_107 -> V_4 . V_87 = V_110 ;
V_107 -> V_4 . V_111 = V_112 ;
V_107 -> V_4 . V_113 = F_24 ;
if ( V_2 -> V_13 -> V_42 )
V_107 -> V_4 . V_114 = F_42 ,
V_107 -> V_13 . V_23 = V_115 / V_2 -> V_93 ;
F_81 ( V_105 , F_82 ( V_103 ) , V_116 ,
V_117 | V_118 , 0 ) ;
}
static void F_83 ( struct V_1 * V_2 )
{
int V_119 ;
static int V_9 ;
V_2 -> V_4 . V_120 = F_43 ;
V_2 -> V_4 . free = F_45 ;
V_2 -> V_4 . V_121 = F_67 ;
V_2 -> V_4 . V_122 = F_69 ;
V_2 -> V_4 . V_123 = F_70 ;
V_2 -> V_4 . V_124 = F_71 ;
V_2 -> V_4 . V_24 = F_72 ;
V_2 -> V_4 . V_125 = F_2 ;
if ( V_2 -> V_101 ) {
V_2 -> V_4 . V_126 = L_7 ;
if ( V_2 -> V_13 -> V_42 )
V_2 -> V_4 . V_73 = & V_94 . V_73 ;
V_2 -> V_4 . V_5 = F_28 ( 0 ) ;
} else {
V_2 -> V_4 . V_126 = L_8 ;
V_2 -> V_4 . V_5 = V_9 ;
V_9 += V_2 -> V_67 ;
}
V_2 -> V_4 . V_127 = V_2 -> V_67 ;
F_84 ( & V_2 -> V_4 ) ;
for ( V_119 = 0 ; V_119 < V_2 -> V_67 ; V_119 ++ ) {
int V_58 = F_85 ( V_2 -> V_8 , V_119 ) ;
F_86 ( V_58 , & V_128 ) ;
F_87 ( V_58 , V_2 ) ;
if ( V_2 -> V_101 ) {
F_79 ( V_2 , V_58 , V_2 -> V_67 ) ;
} else {
F_88 ( V_58 , & V_129 ,
V_108 ) ;
F_89 ( V_58 , V_130 ) ;
}
}
F_90 ( V_2 -> V_58 , F_47 ) ;
F_91 ( V_2 -> V_58 , V_2 ) ;
}
static int F_92 ( struct V_89 * V_90 )
{
struct V_88 * V_73 = & V_90 -> V_73 ;
struct V_131 * V_132 = V_73 -> V_133 ;
const struct V_134 * V_135 ;
const struct V_136 * V_137 ;
struct V_138 * V_139 ;
struct V_1 * V_2 ;
#ifdef F_27
int V_140 ;
#endif
V_135 = F_93 ( F_94 ( V_141 ) , V_73 ) ;
V_137 = V_135 ? V_135 -> V_142 : V_73 -> V_143 ;
if ( ! V_137 )
return - V_50 ;
V_2 = F_95 ( V_73 , sizeof( struct V_1 ) , V_144 ) ;
if ( ! V_2 ) {
F_40 ( V_73 , L_9 ) ;
return - V_145 ;
}
V_139 = F_96 ( V_90 , V_146 , 0 ) ;
if ( F_97 ( ! V_139 ) ) {
F_40 ( V_73 , L_10 ) ;
return - V_147 ;
}
V_2 -> V_58 = V_139 -> V_148 ;
V_2 -> V_73 = V_73 ;
V_2 -> V_31 = V_137 -> V_31 ;
V_2 -> V_93 = V_137 -> V_149 ;
V_2 -> V_67 = V_137 -> V_150 ;
V_2 -> V_101 = V_137 -> V_101 ;
V_2 -> V_41 = V_137 -> V_41 ;
V_2 -> V_13 = V_137 -> V_13 ;
#ifdef F_98
V_2 -> V_4 . V_133 = F_99 ( V_132 ) ;
#endif
if ( V_132 ) {
if ( ! F_100 ( V_132 , L_11 ) )
V_2 -> V_151 = true ;
} else {
V_2 -> V_151 = V_137 -> V_151 ;
if ( V_2 -> V_151 )
V_2 -> V_152 =
V_137 -> V_152 ;
}
#ifdef F_27
V_140 = F_101 ( - 1 , 0 , V_2 -> V_67 , 0 ) ;
if ( V_140 < 0 ) {
F_40 ( V_73 , L_12 ) ;
return - V_147 ;
}
V_2 -> V_8 = F_102 ( V_132 , V_2 -> V_67 , V_140 ,
0 , & V_153 , NULL ) ;
#else
V_2 -> V_8 = F_103 ( V_132 , V_2 -> V_67 ,
& V_153 , NULL ) ;
#endif
if ( ! V_2 -> V_8 ) {
F_40 ( V_73 , L_13 ) ;
return - V_147 ;
}
if ( V_2 -> V_13 -> V_18 && V_2 -> V_13 -> V_20 )
V_2 -> V_18 = F_8 ;
else
V_2 -> V_18 = F_10 ;
F_104 ( & V_2 -> V_61 ) ;
V_139 = F_96 ( V_90 , V_154 , 0 ) ;
if ( F_97 ( ! V_139 ) ) {
F_40 ( V_73 , L_14 ) ;
F_105 ( V_2 -> V_8 ) ;
return - V_147 ;
}
if ( ! F_106 ( V_73 , V_139 -> V_148 , F_107 ( V_139 ) ,
V_90 -> V_155 ) ) {
F_40 ( V_73 , L_15 ) ;
F_105 ( V_2 -> V_8 ) ;
return - V_156 ;
}
V_2 -> V_5 = F_108 ( V_73 , V_139 -> V_148 , F_107 ( V_139 ) ) ;
if ( ! V_2 -> V_5 ) {
F_40 ( V_73 , L_16 ) ;
F_105 ( V_2 -> V_8 ) ;
return - V_145 ;
}
F_64 ( V_90 , V_2 ) ;
F_109 ( V_2 -> V_73 ) ;
F_110 ( V_2 -> V_73 ) ;
F_44 ( V_2 -> V_73 ) ;
if ( V_2 -> V_101 )
F_63 ( V_2 ) ;
F_76 ( V_2 ) ;
F_83 ( V_2 ) ;
F_73 ( V_2 ) ;
F_46 ( V_2 -> V_73 ) ;
F_111 ( & V_2 -> V_132 , & V_157 ) ;
return 0 ;
}
static int F_112 ( struct V_88 * V_73 )
{
struct V_89 * V_90 = F_60 ( V_73 ) ;
struct V_1 * V_2 = F_61 ( V_90 ) ;
T_2 V_158 = 0 , V_159 = 0 ;
unsigned long V_56 ;
T_2 V_160 , V_161 ;
F_29 ( & V_2 -> V_61 , V_56 ) ;
V_160 = V_2 -> V_15 . V_33 & V_2 -> V_15 . V_43 ;
if ( V_160 )
F_7 ( V_160 | V_2 -> V_15 . V_39 ,
V_2 -> V_5 + V_2 -> V_13 -> V_39 ) ;
V_161 = V_2 -> V_15 . V_35 & V_2 -> V_15 . V_43 ;
if ( V_161 )
F_7 ( V_161 | V_2 -> V_15 . V_37 ,
V_2 -> V_5 + V_2 -> V_13 -> V_37 ) ;
if ( ! V_2 -> V_46 )
goto V_162;
if ( V_2 -> V_163 != V_164 ) {
V_2 -> V_163 = 0 ;
goto V_162;
}
V_2 -> V_165 = F_6 ( V_2 -> V_5 +
V_2 -> V_13 -> V_22 ) ;
V_158 = V_2 -> V_15 . V_39 ;
V_159 = V_2 -> V_15 . V_37 ;
V_158 &= ~ V_2 -> V_46 ;
V_159 &= ~ V_2 -> V_46 ;
F_7 ( V_158 , V_2 -> V_5 + V_2 -> V_13 -> V_39 ) ;
F_7 ( V_159 , V_2 -> V_5 + V_2 -> V_13 -> V_37 ) ;
V_2 -> V_166 = true ;
V_162:
if ( V_2 -> V_152 )
V_2 -> V_167 =
V_2 -> V_152 ( V_2 -> V_73 ) ;
F_16 ( V_2 ) ;
F_31 ( & V_2 -> V_61 , V_56 ) ;
return 0 ;
}
static int F_113 ( struct V_88 * V_73 )
{
struct V_89 * V_90 = F_60 ( V_73 ) ;
struct V_1 * V_2 = F_61 ( V_90 ) ;
T_2 V_12 = 0 , V_168 , V_169 , V_170 ;
unsigned long V_56 ;
int V_171 ;
F_29 ( & V_2 -> V_61 , V_56 ) ;
if ( V_2 -> V_151 && ! V_2 -> V_172 ) {
F_114 ( V_2 ) ;
if ( V_2 -> V_152 )
V_2 -> V_167 =
V_2 -> V_152 ( V_2 -> V_73 ) ;
}
F_14 ( V_2 ) ;
F_7 ( V_2 -> V_15 . V_39 ,
V_2 -> V_5 + V_2 -> V_13 -> V_39 ) ;
F_7 ( V_2 -> V_15 . V_37 ,
V_2 -> V_5 + V_2 -> V_13 -> V_37 ) ;
if ( V_2 -> V_151 ) {
if ( ! V_2 -> V_152 ) {
F_115 ( V_2 ) ;
} else {
V_171 = V_2 -> V_152 ( V_2 -> V_73 ) ;
if ( V_171 != V_2 -> V_167 ) {
F_115 ( V_2 ) ;
} else {
F_31 ( & V_2 -> V_61 , V_56 ) ;
return 0 ;
}
}
}
if ( ! V_2 -> V_166 ) {
F_31 ( & V_2 -> V_61 , V_56 ) ;
return 0 ;
}
V_12 = F_6 ( V_2 -> V_5 + V_2 -> V_13 -> V_22 ) ;
V_12 ^= V_2 -> V_165 ;
V_12 &= V_2 -> V_46 ;
V_169 = V_12 & V_2 -> V_15 . V_39 ;
V_169 &= V_2 -> V_165 ;
V_170 = V_12 & V_2 -> V_15 . V_37 ;
V_170 &= ~ ( V_2 -> V_165 ) ;
V_168 = V_12 & ( ~ ( V_2 -> V_15 . V_39 ) &
~ ( V_2 -> V_15 . V_37 ) ) ;
V_168 |= V_169 | V_170 ;
if ( V_168 ) {
T_2 V_173 , V_174 ;
V_173 = F_6 ( V_2 -> V_5 + V_2 -> V_13 -> V_33 ) ;
V_174 = F_6 ( V_2 -> V_5 + V_2 -> V_13 -> V_35 ) ;
if ( ! V_2 -> V_13 -> V_175 ) {
F_7 ( V_173 | V_168 , V_2 -> V_5 +
V_2 -> V_13 -> V_33 ) ;
F_7 ( V_174 | V_168 , V_2 -> V_5 +
V_2 -> V_13 -> V_35 ) ;
}
if ( V_2 -> V_13 -> V_175 ) {
F_7 ( V_173 | V_12 , V_2 -> V_5 +
V_2 -> V_13 -> V_33 ) ;
F_7 ( V_174 | V_12 , V_2 -> V_5 +
V_2 -> V_13 -> V_35 ) ;
}
F_7 ( V_173 , V_2 -> V_5 + V_2 -> V_13 -> V_33 ) ;
F_7 ( V_174 , V_2 -> V_5 + V_2 -> V_13 -> V_35 ) ;
}
V_2 -> V_166 = false ;
F_31 ( & V_2 -> V_61 , V_56 ) ;
return 0 ;
}
void F_116 ( int V_176 )
{
struct V_1 * V_2 ;
F_117 (bank, &omap_gpio_list, node) {
if ( ! V_2 -> V_57 || ! V_2 -> V_151 )
continue;
V_2 -> V_163 = V_176 ;
F_118 ( V_2 -> V_73 ) ;
}
}
void F_119 ( void )
{
struct V_1 * V_2 ;
F_117 (bank, &omap_gpio_list, node) {
if ( ! V_2 -> V_57 || ! V_2 -> V_151 )
continue;
F_44 ( V_2 -> V_73 ) ;
}
}
static void F_114 ( struct V_1 * V_177 )
{
struct V_178 * V_13 = V_177 -> V_13 ;
void T_1 * V_5 = V_177 -> V_5 ;
V_177 -> V_15 . V_76 = F_6 ( V_5 + V_13 -> V_76 ) ;
V_177 -> V_15 . V_16 = F_6 ( V_5 + V_13 -> V_14 ) ;
V_177 -> V_15 . V_43 = F_6 ( V_5 + V_13 -> V_42 ) ;
V_177 -> V_15 . V_33 = F_6 ( V_5 + V_13 -> V_33 ) ;
V_177 -> V_15 . V_35 = F_6 ( V_5 + V_13 -> V_35 ) ;
V_177 -> V_15 . V_37 = F_6 ( V_5 + V_13 -> V_37 ) ;
V_177 -> V_15 . V_39 = F_6 ( V_5 + V_13 -> V_39 ) ;
V_177 -> V_15 . V_71 = F_6 ( V_5 + V_13 -> V_68 ) ;
V_177 -> V_15 . V_179 = F_6 ( V_5 + V_13 -> V_179 ) ;
if ( V_13 -> V_18 && V_177 -> V_13 -> V_20 )
V_177 -> V_15 . V_19 = F_6 ( V_5 + V_13 -> V_18 ) ;
else
V_177 -> V_15 . V_19 = F_6 ( V_5 + V_13 -> V_19 ) ;
V_177 -> V_172 = true ;
}
static void F_115 ( struct V_1 * V_2 )
{
F_7 ( V_2 -> V_15 . V_43 ,
V_2 -> V_5 + V_2 -> V_13 -> V_42 ) ;
F_7 ( V_2 -> V_15 . V_76 , V_2 -> V_5 + V_2 -> V_13 -> V_76 ) ;
F_7 ( V_2 -> V_15 . V_33 ,
V_2 -> V_5 + V_2 -> V_13 -> V_33 ) ;
F_7 ( V_2 -> V_15 . V_35 ,
V_2 -> V_5 + V_2 -> V_13 -> V_35 ) ;
F_7 ( V_2 -> V_15 . V_37 ,
V_2 -> V_5 + V_2 -> V_13 -> V_37 ) ;
F_7 ( V_2 -> V_15 . V_39 ,
V_2 -> V_5 + V_2 -> V_13 -> V_39 ) ;
if ( V_2 -> V_13 -> V_18 && V_2 -> V_13 -> V_20 )
F_7 ( V_2 -> V_15 . V_19 ,
V_2 -> V_5 + V_2 -> V_13 -> V_18 ) ;
else
F_7 ( V_2 -> V_15 . V_19 ,
V_2 -> V_5 + V_2 -> V_13 -> V_19 ) ;
F_7 ( V_2 -> V_15 . V_16 , V_2 -> V_5 + V_2 -> V_13 -> V_14 ) ;
if ( V_2 -> V_25 ) {
F_7 ( V_2 -> V_15 . V_29 , V_2 -> V_5 +
V_2 -> V_13 -> V_29 ) ;
F_7 ( V_2 -> V_15 . V_28 ,
V_2 -> V_5 + V_2 -> V_13 -> V_28 ) ;
}
F_7 ( V_2 -> V_15 . V_71 ,
V_2 -> V_5 + V_2 -> V_13 -> V_68 ) ;
F_7 ( V_2 -> V_15 . V_179 ,
V_2 -> V_5 + V_2 -> V_13 -> V_179 ) ;
}
static void F_114 ( struct V_1 * V_177 ) {}
static int T_3 F_120 ( void )
{
return F_65 ( & V_180 ) ;
}
