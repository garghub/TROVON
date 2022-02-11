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
static void F_24 ( struct V_1 * V_2 , unsigned V_7 )
{
if ( V_2 -> V_13 -> V_53 ) {
void T_1 * V_11 = V_2 -> V_5 + V_2 -> V_13 -> V_53 ;
F_7 ( F_6 ( V_11 ) | ( 1 << V_7 ) , V_11 ) ;
}
if ( V_2 -> V_13 -> V_54 && ! F_25 ( V_2 ) ) {
void T_1 * V_11 = V_2 -> V_5 + V_2 -> V_13 -> V_54 ;
T_2 V_54 ;
V_54 = F_6 ( V_11 ) ;
V_54 &= ~ V_55 ;
F_7 ( V_54 , V_11 ) ;
V_2 -> V_15 . V_54 = V_54 ;
}
}
static void F_26 ( struct V_1 * V_2 , unsigned V_7 )
{
void T_1 * V_5 = V_2 -> V_5 ;
if ( V_2 -> V_13 -> V_42 &&
! F_27 ( V_2 -> V_56 , V_7 ) &&
! F_27 ( V_2 -> V_57 , V_7 ) ) {
F_13 ( V_5 , V_2 -> V_13 -> V_42 , 1 << V_7 , 0 ) ;
V_2 -> V_15 . V_43 =
F_6 ( V_2 -> V_5 + V_2 -> V_13 -> V_42 ) ;
}
if ( V_2 -> V_13 -> V_54 && ! F_25 ( V_2 ) ) {
void T_1 * V_11 = V_2 -> V_5 + V_2 -> V_13 -> V_54 ;
T_2 V_54 ;
V_54 = F_6 ( V_11 ) ;
V_54 |= V_55 ;
F_7 ( V_54 , V_11 ) ;
V_2 -> V_15 . V_54 = V_54 ;
}
}
static int F_28 ( struct V_1 * V_2 , int V_23 )
{
void T_1 * V_11 = V_2 -> V_5 + V_2 -> V_13 -> V_14 ;
return F_6 ( V_11 ) & V_23 ;
}
static int F_29 ( struct V_58 * V_59 , unsigned type )
{
struct V_1 * V_2 = F_30 ( V_59 ) ;
unsigned V_9 = 0 ;
int V_60 ;
unsigned long V_61 ;
unsigned V_7 ;
if ( ! F_25 ( V_2 ) )
F_31 ( V_2 -> V_62 ) ;
#ifdef F_32
if ( V_59 -> V_63 > V_64 )
V_9 = F_33 ( V_59 -> V_63 - V_64 ) ;
#endif
if ( ! V_9 )
V_9 = F_1 ( V_2 , V_59 -> V_65 ) ;
if ( type & ~ V_48 )
return - V_50 ;
if ( ! V_2 -> V_13 -> V_33 &&
( type & ( V_34 | V_36 ) ) )
return - V_50 ;
F_34 ( & V_2 -> V_66 , V_61 ) ;
V_7 = F_35 ( V_2 , V_9 ) ;
V_60 = F_23 ( V_2 , V_7 , type ) ;
if ( ! F_27 ( V_2 -> V_56 , V_7 ) ) {
F_24 ( V_2 , V_7 ) ;
F_5 ( V_2 , V_7 , 1 ) ;
} else if ( ! F_28 ( V_2 , 1 << V_7 ) ) {
F_36 ( & V_2 -> V_66 , V_61 ) ;
return - V_50 ;
}
V_2 -> V_57 |= 1 << F_35 ( V_2 , V_9 ) ;
F_36 ( & V_2 -> V_66 , V_61 ) ;
if ( type & ( V_34 | V_36 ) )
F_37 ( V_59 -> V_63 , V_67 ) ;
else if ( type & ( V_40 | V_38 ) )
F_37 ( V_59 -> V_63 , V_68 ) ;
return V_60 ;
}
static void F_38 ( struct V_1 * V_2 , int V_69 )
{
void T_1 * V_11 = V_2 -> V_5 ;
V_11 += V_2 -> V_13 -> V_70 ;
F_7 ( V_69 , V_11 ) ;
if ( V_2 -> V_13 -> V_71 ) {
V_11 = V_2 -> V_5 + V_2 -> V_13 -> V_71 ;
F_7 ( V_69 , V_11 ) ;
}
F_6 ( V_11 ) ;
}
static inline void F_39 ( struct V_1 * V_2 , int V_9 )
{
F_38 ( V_2 , F_9 ( V_2 , V_9 ) ) ;
}
static T_2 F_40 ( struct V_1 * V_2 )
{
void T_1 * V_11 = V_2 -> V_5 ;
T_2 V_12 ;
T_2 V_23 = ( 1 << V_2 -> V_72 ) - 1 ;
V_11 += V_2 -> V_13 -> V_73 ;
V_12 = F_6 ( V_11 ) ;
if ( V_2 -> V_13 -> V_74 )
V_12 = ~ V_12 ;
V_12 &= V_23 ;
return V_12 ;
}
static void F_41 ( struct V_1 * V_2 , int V_69 )
{
void T_1 * V_11 = V_2 -> V_5 ;
T_2 V_12 ;
if ( V_2 -> V_13 -> V_75 ) {
V_11 += V_2 -> V_13 -> V_75 ;
V_12 = V_69 ;
V_2 -> V_15 . V_76 |= V_69 ;
} else {
V_11 += V_2 -> V_13 -> V_73 ;
V_12 = F_6 ( V_11 ) ;
if ( V_2 -> V_13 -> V_74 )
V_12 &= ~ V_69 ;
else
V_12 |= V_69 ;
V_2 -> V_15 . V_76 = V_12 ;
}
F_7 ( V_12 , V_11 ) ;
}
static void F_42 ( struct V_1 * V_2 , int V_69 )
{
void T_1 * V_11 = V_2 -> V_5 ;
T_2 V_12 ;
if ( V_2 -> V_13 -> V_77 ) {
V_11 += V_2 -> V_13 -> V_77 ;
V_12 = V_69 ;
V_2 -> V_15 . V_76 &= ~ V_69 ;
} else {
V_11 += V_2 -> V_13 -> V_73 ;
V_12 = F_6 ( V_11 ) ;
if ( V_2 -> V_13 -> V_74 )
V_12 |= V_69 ;
else
V_12 &= ~ V_69 ;
V_2 -> V_15 . V_76 = V_12 ;
}
F_7 ( V_12 , V_11 ) ;
}
static inline void F_43 ( struct V_1 * V_2 , int V_9 , int V_17 )
{
if ( V_17 )
F_41 ( V_2 , F_9 ( V_2 , V_9 ) ) ;
else
F_42 ( V_2 , F_9 ( V_2 , V_9 ) ) ;
}
static int F_44 ( struct V_1 * V_2 , int V_9 , int V_17 )
{
T_2 V_21 = F_9 ( V_2 , V_9 ) ;
unsigned long V_61 ;
if ( V_2 -> V_41 & V_21 ) {
F_45 ( V_2 -> V_62 ,
L_1 , V_9 ) ;
return - V_50 ;
}
F_34 ( & V_2 -> V_66 , V_61 ) ;
if ( V_17 )
V_2 -> V_15 . V_43 |= V_21 ;
else
V_2 -> V_15 . V_43 &= ~ V_21 ;
F_7 ( V_2 -> V_15 . V_43 , V_2 -> V_5 + V_2 -> V_13 -> V_42 ) ;
F_36 ( & V_2 -> V_66 , V_61 ) ;
return 0 ;
}
static void F_46 ( struct V_1 * V_2 , int V_9 )
{
F_5 ( V_2 , F_35 ( V_2 , V_9 ) , 1 ) ;
F_43 ( V_2 , V_9 , 0 ) ;
F_39 ( V_2 , V_9 ) ;
F_23 ( V_2 , F_35 ( V_2 , V_9 ) , V_78 ) ;
F_19 ( V_2 , V_9 ) ;
}
static int F_47 ( struct V_58 * V_59 , unsigned int V_17 )
{
struct V_1 * V_2 = F_30 ( V_59 ) ;
unsigned int V_9 = F_1 ( V_2 , V_59 -> V_65 ) ;
return F_44 ( V_2 , V_9 , V_17 ) ;
}
static int F_48 ( struct V_6 * V_4 , unsigned V_7 )
{
struct V_1 * V_2 = F_3 ( V_4 , struct V_1 , V_4 ) ;
unsigned long V_61 ;
if ( ! F_25 ( V_2 ) )
F_31 ( V_2 -> V_62 ) ;
F_34 ( & V_2 -> V_66 , V_61 ) ;
if ( ! F_27 ( V_2 -> V_57 , V_7 ) ) {
F_23 ( V_2 , V_7 , V_78 ) ;
F_24 ( V_2 , V_7 ) ;
}
V_2 -> V_56 |= 1 << V_7 ;
F_36 ( & V_2 -> V_66 , V_61 ) ;
return 0 ;
}
static void F_49 ( struct V_6 * V_4 , unsigned V_7 )
{
struct V_1 * V_2 = F_3 ( V_4 , struct V_1 , V_4 ) ;
unsigned long V_61 ;
F_34 ( & V_2 -> V_66 , V_61 ) ;
V_2 -> V_56 &= ~ ( 1 << V_7 ) ;
F_26 ( V_2 , V_7 ) ;
F_46 ( V_2 , V_2 -> V_4 . V_5 + V_7 ) ;
F_36 ( & V_2 -> V_66 , V_61 ) ;
if ( ! F_25 ( V_2 ) )
F_50 ( V_2 -> V_62 ) ;
}
static void F_51 ( unsigned int V_63 , struct V_79 * V_80 )
{
void T_1 * V_81 = NULL ;
T_2 V_82 ;
unsigned int V_83 ;
struct V_1 * V_2 ;
int V_84 = 0 ;
struct V_85 * V_4 = F_52 ( V_80 ) ;
F_53 ( V_4 , V_80 ) ;
V_2 = F_54 ( V_63 ) ;
V_81 = V_2 -> V_5 + V_2 -> V_13 -> V_70 ;
F_31 ( V_2 -> V_62 ) ;
if ( F_55 ( ! V_81 ) )
goto exit;
while ( 1 ) {
T_2 V_86 , V_47 = 0 ;
T_2 V_87 ;
V_87 = F_40 ( V_2 ) ;
V_86 = V_82 = F_6 ( V_81 ) & V_87 ;
if ( V_2 -> V_47 )
V_47 = V_2 -> V_47 & V_87 ;
F_42 ( V_2 , V_86 & ~ V_47 ) ;
F_38 ( V_2 , V_86 & ~ V_47 ) ;
F_41 ( V_2 , V_86 & ~ V_47 ) ;
if ( ! V_47 && ! V_84 ) {
V_84 = 1 ;
F_56 ( V_4 , V_80 ) ;
}
if ( ! V_82 )
break;
while ( V_82 ) {
V_83 = F_57 ( V_82 ) ;
V_82 &= ~ ( 1 << V_83 ) ;
if ( V_2 -> V_49 & ( 1 << V_83 ) )
F_22 ( V_2 , V_83 ) ;
F_58 ( F_4 ( V_2 -> V_8 , V_83 ) ) ;
}
}
exit:
if ( ! V_84 )
F_56 ( V_4 , V_80 ) ;
F_50 ( V_2 -> V_62 ) ;
}
static void F_59 ( struct V_58 * V_59 )
{
struct V_1 * V_2 = F_30 ( V_59 ) ;
unsigned int V_9 = F_1 ( V_2 , V_59 -> V_65 ) ;
unsigned long V_61 ;
unsigned V_7 = F_35 ( V_2 , V_9 ) ;
F_34 ( & V_2 -> V_66 , V_61 ) ;
V_2 -> V_57 &= ~ ( 1 << V_7 ) ;
F_26 ( V_2 , V_7 ) ;
F_46 ( V_2 , V_9 ) ;
F_36 ( & V_2 -> V_66 , V_61 ) ;
if ( ! F_25 ( V_2 ) )
F_50 ( V_2 -> V_62 ) ;
}
static void F_60 ( struct V_58 * V_59 )
{
struct V_1 * V_2 = F_30 ( V_59 ) ;
unsigned int V_9 = F_1 ( V_2 , V_59 -> V_65 ) ;
F_39 ( V_2 , V_9 ) ;
}
static void F_61 ( struct V_58 * V_59 )
{
struct V_1 * V_2 = F_30 ( V_59 ) ;
unsigned int V_9 = F_1 ( V_2 , V_59 -> V_65 ) ;
unsigned long V_61 ;
F_34 ( & V_2 -> V_66 , V_61 ) ;
F_43 ( V_2 , V_9 , 0 ) ;
F_23 ( V_2 , F_35 ( V_2 , V_9 ) , V_78 ) ;
F_36 ( & V_2 -> V_66 , V_61 ) ;
}
static void F_62 ( struct V_58 * V_59 )
{
struct V_1 * V_2 = F_30 ( V_59 ) ;
unsigned int V_9 = F_1 ( V_2 , V_59 -> V_65 ) ;
unsigned int V_88 = F_9 ( V_2 , V_9 ) ;
T_2 V_32 = F_63 ( V_59 ) ;
unsigned long V_61 ;
F_34 ( & V_2 -> V_66 , V_61 ) ;
if ( V_32 )
F_23 ( V_2 , F_35 ( V_2 , V_9 ) , V_32 ) ;
if ( V_2 -> V_47 & V_88 ) {
F_43 ( V_2 , V_9 , 0 ) ;
F_39 ( V_2 , V_9 ) ;
}
F_43 ( V_2 , V_9 , 1 ) ;
F_36 ( & V_2 -> V_66 , V_61 ) ;
}
static int F_64 ( struct V_89 * V_62 )
{
struct V_90 * V_91 = F_65 ( V_62 ) ;
struct V_1 * V_2 = F_66 ( V_91 ) ;
void T_1 * V_92 = V_2 -> V_5 +
V_93 / V_2 -> V_94 ;
unsigned long V_61 ;
F_34 ( & V_2 -> V_66 , V_61 ) ;
F_7 ( 0xffff & ~ V_2 -> V_15 . V_43 , V_92 ) ;
F_36 ( & V_2 -> V_66 , V_61 ) ;
return 0 ;
}
static int F_67 ( struct V_89 * V_62 )
{
struct V_90 * V_91 = F_65 ( V_62 ) ;
struct V_1 * V_2 = F_66 ( V_91 ) ;
void T_1 * V_92 = V_2 -> V_5 +
V_93 / V_2 -> V_94 ;
unsigned long V_61 ;
F_34 ( & V_2 -> V_66 , V_61 ) ;
F_7 ( V_2 -> V_15 . V_43 , V_92 ) ;
F_36 ( & V_2 -> V_66 , V_61 ) ;
return 0 ;
}
static inline void F_68 ( struct V_1 * V_2 )
{
F_69 ( & V_95 , V_2 ) ;
if ( F_70 ( & V_96 ) == 0 )
( void ) F_71 ( & V_95 ) ;
}
static int F_72 ( struct V_6 * V_4 , unsigned V_7 )
{
struct V_1 * V_2 ;
unsigned long V_61 ;
V_2 = F_3 ( V_4 , struct V_1 , V_4 ) ;
F_34 ( & V_2 -> V_66 , V_61 ) ;
F_5 ( V_2 , V_7 , 1 ) ;
F_36 ( & V_2 -> V_66 , V_61 ) ;
return 0 ;
}
static int F_73 ( struct V_6 * V_4 , unsigned V_7 )
{
struct V_1 * V_2 ;
T_2 V_23 ;
V_2 = F_3 ( V_4 , struct V_1 , V_4 ) ;
V_23 = ( 1 << V_7 ) ;
if ( F_28 ( V_2 , V_23 ) )
return F_11 ( V_2 , V_7 ) ;
else
return F_12 ( V_2 , V_7 ) ;
}
static int F_74 ( struct V_6 * V_4 , unsigned V_7 , int V_97 )
{
struct V_1 * V_2 ;
unsigned long V_61 ;
int V_60 = 0 ;
V_2 = F_3 ( V_4 , struct V_1 , V_4 ) ;
F_34 ( & V_2 -> V_66 , V_61 ) ;
if ( F_27 ( V_2 -> V_57 , V_7 ) ) {
V_60 = - V_50 ;
goto exit;
}
V_2 -> V_18 ( V_2 , V_7 , V_97 ) ;
F_5 ( V_2 , V_7 , 0 ) ;
exit:
F_36 ( & V_2 -> V_66 , V_61 ) ;
return V_60 ;
}
static int F_75 ( struct V_6 * V_4 , unsigned V_7 ,
unsigned V_29 )
{
struct V_1 * V_2 ;
unsigned long V_61 ;
V_2 = F_3 ( V_4 , struct V_1 , V_4 ) ;
F_34 ( & V_2 -> V_66 , V_61 ) ;
F_18 ( V_2 , V_7 , V_29 ) ;
F_36 ( & V_2 -> V_66 , V_61 ) ;
return 0 ;
}
static void F_76 ( struct V_6 * V_4 , unsigned V_7 , int V_97 )
{
struct V_1 * V_2 ;
unsigned long V_61 ;
V_2 = F_3 ( V_4 , struct V_1 , V_4 ) ;
F_34 ( & V_2 -> V_66 , V_61 ) ;
V_2 -> V_18 ( V_2 , V_7 , V_97 ) ;
F_36 ( & V_2 -> V_66 , V_61 ) ;
}
static void T_3 F_77 ( struct V_1 * V_2 )
{
static bool V_98 ;
T_2 V_99 ;
if ( V_98 || V_2 -> V_13 -> V_100 == V_101 )
return;
V_99 = F_78 ( V_2 -> V_5 + V_2 -> V_13 -> V_100 ) ;
F_79 ( L_2 ,
( V_99 >> 4 ) & 0x0f , V_99 & 0x0f ) ;
V_98 = true ;
}
static void F_80 ( struct V_1 * V_2 )
{
void T_1 * V_5 = V_2 -> V_5 ;
T_2 V_12 = 0xffffffff ;
if ( V_2 -> V_72 == 16 )
V_12 = 0xffff ;
if ( V_2 -> V_102 ) {
F_7 ( V_12 , V_2 -> V_5 + V_2 -> V_13 -> V_73 ) ;
return;
}
F_13 ( V_5 , V_2 -> V_13 -> V_73 , V_12 , V_2 -> V_13 -> V_74 ) ;
F_13 ( V_5 , V_2 -> V_13 -> V_70 , V_12 , ! V_2 -> V_13 -> V_74 ) ;
if ( V_2 -> V_13 -> V_28 )
F_7 ( 0 , V_5 + V_2 -> V_13 -> V_28 ) ;
V_2 -> V_15 . V_16 = F_6 ( V_2 -> V_5 + V_2 -> V_13 -> V_14 ) ;
if ( V_2 -> V_13 -> V_54 )
F_7 ( 0 , V_5 + V_2 -> V_13 -> V_54 ) ;
V_2 -> V_27 = F_81 ( V_2 -> V_62 , L_3 ) ;
if ( F_82 ( V_2 -> V_27 ) )
F_45 ( V_2 -> V_62 , L_4 ) ;
}
static void
F_83 ( struct V_1 * V_2 , unsigned int V_103 ,
unsigned int V_104 )
{
struct V_105 * V_106 ;
struct V_107 * V_108 ;
V_106 = F_84 ( L_5 , 1 , V_103 , V_2 -> V_5 ,
V_109 ) ;
if ( ! V_106 ) {
F_45 ( V_2 -> V_62 , L_6 ) ;
return;
}
V_108 = V_106 -> V_110 ;
V_108 -> V_4 . V_88 = V_111 ;
V_108 -> V_4 . V_112 = V_113 ;
V_108 -> V_4 . V_114 = F_29 ;
if ( V_2 -> V_13 -> V_42 )
V_108 -> V_4 . V_115 = F_47 ;
V_108 -> V_13 . V_23 = V_116 / V_2 -> V_94 ;
F_85 ( V_106 , F_86 ( V_104 ) , V_117 ,
V_118 | V_119 , 0 ) ;
}
static void F_87 ( struct V_1 * V_2 )
{
int V_120 ;
static int V_9 ;
V_2 -> V_4 . V_121 = F_48 ;
V_2 -> V_4 . free = F_49 ;
V_2 -> V_4 . V_122 = F_72 ;
V_2 -> V_4 . V_123 = F_73 ;
V_2 -> V_4 . V_124 = F_74 ;
V_2 -> V_4 . V_125 = F_75 ;
V_2 -> V_4 . V_24 = F_76 ;
V_2 -> V_4 . V_126 = F_2 ;
if ( V_2 -> V_102 ) {
V_2 -> V_4 . V_127 = L_7 ;
if ( V_2 -> V_13 -> V_42 )
V_2 -> V_4 . V_62 = & V_95 . V_62 ;
V_2 -> V_4 . V_5 = F_33 ( 0 ) ;
} else {
V_2 -> V_4 . V_127 = L_8 ;
V_2 -> V_4 . V_5 = V_9 ;
V_9 += V_2 -> V_72 ;
}
V_2 -> V_4 . V_128 = V_2 -> V_72 ;
F_88 ( & V_2 -> V_4 ) ;
for ( V_120 = 0 ; V_120 < V_2 -> V_72 ; V_120 ++ ) {
int V_63 = F_89 ( V_2 -> V_8 , V_120 ) ;
F_90 ( V_63 , & V_129 ) ;
F_91 ( V_63 , V_2 ) ;
if ( V_2 -> V_102 ) {
F_83 ( V_2 , V_63 , V_2 -> V_72 ) ;
} else {
F_92 ( V_63 , & V_130 ,
V_109 ) ;
F_93 ( V_63 , V_131 ) ;
}
}
F_94 ( V_2 -> V_63 , F_51 ) ;
F_95 ( V_2 -> V_63 , V_2 ) ;
}
static int F_96 ( struct V_90 * V_91 )
{
struct V_89 * V_62 = & V_91 -> V_62 ;
struct V_132 * V_133 = V_62 -> V_134 ;
const struct V_135 * V_136 ;
const struct V_137 * V_138 ;
struct V_139 * V_140 ;
struct V_1 * V_2 ;
#ifdef F_32
int V_141 ;
#endif
V_136 = F_97 ( F_98 ( V_142 ) , V_62 ) ;
V_138 = V_136 ? V_136 -> V_143 : F_99 ( V_62 ) ;
if ( ! V_138 )
return - V_50 ;
V_2 = F_100 ( V_62 , sizeof( struct V_1 ) , V_144 ) ;
if ( ! V_2 ) {
F_45 ( V_62 , L_9 ) ;
return - V_145 ;
}
V_140 = F_101 ( V_91 , V_146 , 0 ) ;
if ( F_102 ( ! V_140 ) ) {
F_45 ( V_62 , L_10 ) ;
return - V_147 ;
}
V_2 -> V_63 = V_140 -> V_148 ;
V_2 -> V_62 = V_62 ;
V_2 -> V_31 = V_138 -> V_31 ;
V_2 -> V_94 = V_138 -> V_149 ;
V_2 -> V_72 = V_138 -> V_150 ;
V_2 -> V_102 = V_138 -> V_102 ;
V_2 -> V_41 = V_138 -> V_41 ;
V_2 -> V_13 = V_138 -> V_13 ;
#ifdef F_103
V_2 -> V_4 . V_134 = F_104 ( V_133 ) ;
#endif
if ( V_133 ) {
if ( ! F_105 ( V_133 , L_11 ) )
V_2 -> V_151 = true ;
} else {
V_2 -> V_151 = V_138 -> V_151 ;
if ( V_2 -> V_151 )
V_2 -> V_152 =
V_138 -> V_152 ;
}
#ifdef F_32
V_141 = F_106 ( - 1 , 0 , V_2 -> V_72 , 0 ) ;
if ( V_141 < 0 ) {
F_45 ( V_62 , L_12 ) ;
return - V_147 ;
}
V_2 -> V_8 = F_107 ( V_133 , V_2 -> V_72 , V_141 ,
0 , & V_153 , NULL ) ;
#else
V_2 -> V_8 = F_108 ( V_133 , V_2 -> V_72 ,
& V_153 , NULL ) ;
#endif
if ( ! V_2 -> V_8 ) {
F_45 ( V_62 , L_13 ) ;
return - V_147 ;
}
if ( V_2 -> V_13 -> V_18 && V_2 -> V_13 -> V_20 )
V_2 -> V_18 = F_8 ;
else
V_2 -> V_18 = F_10 ;
F_109 ( & V_2 -> V_66 ) ;
V_140 = F_101 ( V_91 , V_154 , 0 ) ;
if ( F_102 ( ! V_140 ) ) {
F_45 ( V_62 , L_14 ) ;
F_110 ( V_2 -> V_8 ) ;
return - V_147 ;
}
if ( ! F_111 ( V_62 , V_140 -> V_148 , F_112 ( V_140 ) ,
V_91 -> V_155 ) ) {
F_45 ( V_62 , L_15 ) ;
F_110 ( V_2 -> V_8 ) ;
return - V_156 ;
}
V_2 -> V_5 = F_113 ( V_62 , V_140 -> V_148 , F_112 ( V_140 ) ) ;
if ( ! V_2 -> V_5 ) {
F_45 ( V_62 , L_16 ) ;
F_110 ( V_2 -> V_8 ) ;
return - V_145 ;
}
F_69 ( V_91 , V_2 ) ;
F_114 ( V_2 -> V_62 ) ;
F_115 ( V_2 -> V_62 ) ;
F_31 ( V_2 -> V_62 ) ;
if ( V_2 -> V_102 )
F_68 ( V_2 ) ;
F_80 ( V_2 ) ;
F_87 ( V_2 ) ;
F_77 ( V_2 ) ;
F_50 ( V_2 -> V_62 ) ;
F_116 ( & V_2 -> V_133 , & V_157 ) ;
return 0 ;
}
static int F_117 ( struct V_89 * V_62 )
{
struct V_90 * V_91 = F_65 ( V_62 ) ;
struct V_1 * V_2 = F_66 ( V_91 ) ;
T_2 V_158 = 0 , V_159 = 0 ;
unsigned long V_61 ;
T_2 V_160 , V_161 ;
F_34 ( & V_2 -> V_66 , V_61 ) ;
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
V_2 -> V_152 ( V_2 -> V_62 ) ;
F_16 ( V_2 ) ;
F_36 ( & V_2 -> V_66 , V_61 ) ;
return 0 ;
}
static int F_118 ( struct V_89 * V_62 )
{
struct V_90 * V_91 = F_65 ( V_62 ) ;
struct V_1 * V_2 = F_66 ( V_91 ) ;
T_2 V_12 = 0 , V_168 , V_169 , V_170 ;
unsigned long V_61 ;
int V_171 ;
F_34 ( & V_2 -> V_66 , V_61 ) ;
if ( V_2 -> V_151 && ! V_2 -> V_172 ) {
F_119 ( V_2 ) ;
if ( V_2 -> V_152 )
V_2 -> V_167 =
V_2 -> V_152 ( V_2 -> V_62 ) ;
}
F_14 ( V_2 ) ;
F_7 ( V_2 -> V_15 . V_39 ,
V_2 -> V_5 + V_2 -> V_13 -> V_39 ) ;
F_7 ( V_2 -> V_15 . V_37 ,
V_2 -> V_5 + V_2 -> V_13 -> V_37 ) ;
if ( V_2 -> V_151 ) {
if ( ! V_2 -> V_152 ) {
F_120 ( V_2 ) ;
} else {
V_171 = V_2 -> V_152 ( V_2 -> V_62 ) ;
if ( V_171 != V_2 -> V_167 ) {
F_120 ( V_2 ) ;
} else {
F_36 ( & V_2 -> V_66 , V_61 ) ;
return 0 ;
}
}
}
if ( ! V_2 -> V_166 ) {
F_36 ( & V_2 -> V_66 , V_61 ) ;
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
F_36 ( & V_2 -> V_66 , V_61 ) ;
return 0 ;
}
void F_121 ( int V_176 )
{
struct V_1 * V_2 ;
F_122 (bank, &omap_gpio_list, node) {
if ( ! F_25 ( V_2 ) || ! V_2 -> V_151 )
continue;
V_2 -> V_163 = V_176 ;
F_123 ( V_2 -> V_62 ) ;
}
}
void F_124 ( void )
{
struct V_1 * V_2 ;
F_122 (bank, &omap_gpio_list, node) {
if ( ! F_25 ( V_2 ) || ! V_2 -> V_151 )
continue;
F_31 ( V_2 -> V_62 ) ;
}
}
static void F_119 ( struct V_1 * V_177 )
{
struct V_178 * V_13 = V_177 -> V_13 ;
void T_1 * V_5 = V_177 -> V_5 ;
V_177 -> V_15 . V_54 = F_6 ( V_5 + V_13 -> V_54 ) ;
V_177 -> V_15 . V_16 = F_6 ( V_5 + V_13 -> V_14 ) ;
V_177 -> V_15 . V_43 = F_6 ( V_5 + V_13 -> V_42 ) ;
V_177 -> V_15 . V_33 = F_6 ( V_5 + V_13 -> V_33 ) ;
V_177 -> V_15 . V_35 = F_6 ( V_5 + V_13 -> V_35 ) ;
V_177 -> V_15 . V_37 = F_6 ( V_5 + V_13 -> V_37 ) ;
V_177 -> V_15 . V_39 = F_6 ( V_5 + V_13 -> V_39 ) ;
V_177 -> V_15 . V_76 = F_6 ( V_5 + V_13 -> V_73 ) ;
V_177 -> V_15 . V_179 = F_6 ( V_5 + V_13 -> V_179 ) ;
if ( V_13 -> V_18 && V_177 -> V_13 -> V_20 )
V_177 -> V_15 . V_19 = F_6 ( V_5 + V_13 -> V_18 ) ;
else
V_177 -> V_15 . V_19 = F_6 ( V_5 + V_13 -> V_19 ) ;
V_177 -> V_172 = true ;
}
static void F_120 ( struct V_1 * V_2 )
{
F_7 ( V_2 -> V_15 . V_43 ,
V_2 -> V_5 + V_2 -> V_13 -> V_42 ) ;
F_7 ( V_2 -> V_15 . V_54 , V_2 -> V_5 + V_2 -> V_13 -> V_54 ) ;
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
F_7 ( V_2 -> V_15 . V_76 ,
V_2 -> V_5 + V_2 -> V_13 -> V_73 ) ;
F_7 ( V_2 -> V_15 . V_179 ,
V_2 -> V_5 + V_2 -> V_13 -> V_179 ) ;
}
static inline void F_119 ( struct V_1 * V_177 ) {}
static int T_3 F_125 ( void )
{
return F_70 ( & V_180 ) ;
}
