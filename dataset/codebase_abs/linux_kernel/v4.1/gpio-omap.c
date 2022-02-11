static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = F_2 ( V_3 ) ;
return F_3 ( V_5 , struct V_1 , V_5 ) ;
}
static void F_4 ( struct V_1 * V_6 , int V_7 ,
int V_8 )
{
void T_1 * V_9 = V_6 -> V_10 ;
T_2 V_11 ;
V_9 += V_6 -> V_12 -> V_13 ;
V_11 = F_5 ( V_9 ) ;
if ( V_8 )
V_11 |= F_6 ( V_7 ) ;
else
V_11 &= ~ ( F_6 ( V_7 ) ) ;
F_7 ( V_11 , V_9 ) ;
V_6 -> V_14 . V_15 = V_11 ;
}
static void F_8 ( struct V_1 * V_6 , unsigned V_16 ,
int V_17 )
{
void T_1 * V_9 = V_6 -> V_10 ;
T_2 V_11 = F_6 ( V_16 ) ;
if ( V_17 ) {
V_9 += V_6 -> V_12 -> V_18 ;
V_6 -> V_14 . V_19 |= V_11 ;
} else {
V_9 += V_6 -> V_12 -> V_20 ;
V_6 -> V_14 . V_19 &= ~ V_11 ;
}
F_7 ( V_11 , V_9 ) ;
}
static void F_9 ( struct V_1 * V_6 , unsigned V_16 ,
int V_17 )
{
void T_1 * V_9 = V_6 -> V_10 + V_6 -> V_12 -> V_19 ;
T_2 V_21 = F_6 ( V_16 ) ;
T_2 V_11 ;
V_11 = F_5 ( V_9 ) ;
if ( V_17 )
V_11 |= V_21 ;
else
V_11 &= ~ V_21 ;
F_7 ( V_11 , V_9 ) ;
V_6 -> V_14 . V_19 = V_11 ;
}
static int F_10 ( struct V_1 * V_6 , int V_16 )
{
void T_1 * V_9 = V_6 -> V_10 + V_6 -> V_12 -> V_22 ;
return ( F_5 ( V_9 ) & ( F_6 ( V_16 ) ) ) != 0 ;
}
static int F_11 ( struct V_1 * V_6 , int V_16 )
{
void T_1 * V_9 = V_6 -> V_10 + V_6 -> V_12 -> V_19 ;
return ( F_5 ( V_9 ) & ( F_6 ( V_16 ) ) ) != 0 ;
}
static inline void F_12 ( void T_1 * V_10 , T_2 V_9 , T_2 V_23 , bool V_24 )
{
int V_11 = F_5 ( V_10 + V_9 ) ;
if ( V_24 )
V_11 |= V_23 ;
else
V_11 &= ~ V_23 ;
F_7 ( V_11 , V_10 + V_9 ) ;
}
static inline void F_13 ( struct V_1 * V_6 )
{
if ( V_6 -> V_25 && ! V_6 -> V_26 ) {
F_14 ( V_6 -> V_27 ) ;
V_6 -> V_26 = true ;
F_7 ( V_6 -> V_25 ,
V_6 -> V_10 + V_6 -> V_12 -> V_28 ) ;
}
}
static inline void F_15 ( struct V_1 * V_6 )
{
if ( V_6 -> V_25 && V_6 -> V_26 ) {
F_7 ( 0 , V_6 -> V_10 + V_6 -> V_12 -> V_28 ) ;
F_16 ( V_6 -> V_27 ) ;
V_6 -> V_26 = false ;
}
}
static void F_17 ( struct V_1 * V_6 , unsigned V_16 ,
unsigned V_29 )
{
void T_1 * V_9 ;
T_2 V_30 ;
T_2 V_11 ;
if ( ! V_6 -> V_31 )
return;
if ( V_29 < 32 )
V_29 = 0x01 ;
else if ( V_29 > 7936 )
V_29 = 0xff ;
else
V_29 = ( V_29 / 0x1f ) - 1 ;
V_11 = F_6 ( V_16 ) ;
F_14 ( V_6 -> V_27 ) ;
V_9 = V_6 -> V_10 + V_6 -> V_12 -> V_29 ;
F_7 ( V_29 , V_9 ) ;
V_9 = V_6 -> V_10 + V_6 -> V_12 -> V_28 ;
V_30 = F_5 ( V_9 ) ;
if ( V_29 )
V_30 |= V_11 ;
else
V_30 &= ~ V_11 ;
V_6 -> V_25 = V_30 ;
F_7 ( V_30 , V_9 ) ;
F_16 ( V_6 -> V_27 ) ;
F_13 ( V_6 ) ;
if ( V_6 -> V_25 ) {
V_6 -> V_14 . V_29 = V_29 ;
V_6 -> V_14 . V_28 = V_30 ;
}
}
static void F_18 ( struct V_1 * V_6 , unsigned V_16 )
{
T_2 V_21 = F_6 ( V_16 ) ;
if ( ! V_6 -> V_31 )
return;
if ( ! ( V_6 -> V_25 & V_21 ) )
return;
V_6 -> V_25 &= ~ V_21 ;
V_6 -> V_14 . V_28 &= ~ V_21 ;
F_7 ( V_6 -> V_14 . V_28 ,
V_6 -> V_10 + V_6 -> V_12 -> V_28 ) ;
if ( ! V_6 -> V_25 ) {
V_6 -> V_14 . V_29 = 0 ;
F_7 ( V_6 -> V_14 . V_29 , V_6 -> V_10 +
V_6 -> V_12 -> V_29 ) ;
F_16 ( V_6 -> V_27 ) ;
V_6 -> V_26 = false ;
}
}
static inline void F_19 ( struct V_1 * V_6 , int V_7 ,
unsigned V_32 )
{
void T_1 * V_10 = V_6 -> V_10 ;
T_2 V_21 = F_6 ( V_7 ) ;
F_12 ( V_10 , V_6 -> V_12 -> V_33 , V_21 ,
V_32 & V_34 ) ;
F_12 ( V_10 , V_6 -> V_12 -> V_35 , V_21 ,
V_32 & V_36 ) ;
F_12 ( V_10 , V_6 -> V_12 -> V_37 , V_21 ,
V_32 & V_38 ) ;
F_12 ( V_10 , V_6 -> V_12 -> V_39 , V_21 ,
V_32 & V_40 ) ;
V_6 -> V_14 . V_33 =
F_5 ( V_6 -> V_10 + V_6 -> V_12 -> V_33 ) ;
V_6 -> V_14 . V_35 =
F_5 ( V_6 -> V_10 + V_6 -> V_12 -> V_35 ) ;
V_6 -> V_14 . V_37 =
F_5 ( V_6 -> V_10 + V_6 -> V_12 -> V_37 ) ;
V_6 -> V_14 . V_39 =
F_5 ( V_6 -> V_10 + V_6 -> V_12 -> V_39 ) ;
if ( F_20 ( ! ( V_6 -> V_41 & V_21 ) ) ) {
F_12 ( V_10 , V_6 -> V_12 -> V_42 , V_21 , V_32 != 0 ) ;
V_6 -> V_14 . V_43 =
F_5 ( V_6 -> V_10 + V_6 -> V_12 -> V_42 ) ;
}
if ( ! V_6 -> V_12 -> V_44 ) {
if ( V_6 -> V_41 ) {
if ( ! ( V_6 -> V_41 & V_21 ) )
goto exit;
}
if ( V_32 & V_45 )
V_6 -> V_46 |= V_21 ;
else
V_6 -> V_46 &= ~ V_21 ;
}
exit:
V_6 -> V_47 =
F_5 ( V_6 -> V_10 + V_6 -> V_12 -> V_33 ) |
F_5 ( V_6 -> V_10 + V_6 -> V_12 -> V_35 ) ;
}
static void F_21 ( struct V_1 * V_6 , int V_7 )
{
void T_1 * V_9 = V_6 -> V_10 ;
T_2 V_11 = 0 ;
if ( ! V_6 -> V_12 -> V_44 )
return;
V_9 += V_6 -> V_12 -> V_44 ;
V_11 = F_5 ( V_9 ) ;
if ( ( V_11 >> V_7 ) & 1 )
V_11 &= ~ ( F_6 ( V_7 ) ) ;
else
V_11 |= F_6 ( V_7 ) ;
F_7 ( V_11 , V_9 ) ;
}
static void F_21 ( struct V_1 * V_6 , int V_7 ) {}
static int F_22 ( struct V_1 * V_6 , int V_7 ,
unsigned V_32 )
{
void T_1 * V_9 = V_6 -> V_10 ;
void T_1 * V_10 = V_6 -> V_10 ;
T_2 V_11 = 0 ;
if ( V_6 -> V_12 -> V_33 && V_6 -> V_12 -> V_42 ) {
F_19 ( V_6 , V_7 , V_32 ) ;
} else if ( V_6 -> V_12 -> V_44 ) {
V_9 += V_6 -> V_12 -> V_44 ;
V_11 = F_5 ( V_9 ) ;
if ( ( V_32 & V_48 ) == V_45 )
V_6 -> V_49 |= F_6 ( V_7 ) ;
if ( V_32 & V_38 )
V_11 |= F_6 ( V_7 ) ;
else if ( V_32 & V_40 )
V_11 &= ~ ( F_6 ( V_7 ) ) ;
else
return - V_50 ;
F_7 ( V_11 , V_9 ) ;
} else if ( V_6 -> V_12 -> V_51 ) {
if ( V_7 & 0x08 )
V_9 += V_6 -> V_12 -> V_52 ;
else
V_9 += V_6 -> V_12 -> V_51 ;
V_7 &= 0x07 ;
V_11 = F_5 ( V_9 ) ;
V_11 &= ~ ( 3 << ( V_7 << 1 ) ) ;
if ( V_32 & V_38 )
V_11 |= 2 << ( V_7 << 1 ) ;
if ( V_32 & V_40 )
V_11 |= F_6 ( V_7 << 1 ) ;
F_12 ( V_10 , V_6 -> V_12 -> V_42 , F_6 ( V_7 ) , V_32 ) ;
V_6 -> V_14 . V_43 =
F_5 ( V_6 -> V_10 + V_6 -> V_12 -> V_42 ) ;
F_7 ( V_11 , V_9 ) ;
}
return 0 ;
}
static void F_23 ( struct V_1 * V_6 , unsigned V_16 )
{
if ( V_6 -> V_12 -> V_53 ) {
void T_1 * V_9 = V_6 -> V_10 + V_6 -> V_12 -> V_53 ;
F_7 ( F_5 ( V_9 ) | ( F_6 ( V_16 ) ) , V_9 ) ;
}
if ( V_6 -> V_12 -> V_54 && ! F_24 ( V_6 ) ) {
void T_1 * V_9 = V_6 -> V_10 + V_6 -> V_12 -> V_54 ;
T_2 V_54 ;
V_54 = F_5 ( V_9 ) ;
V_54 &= ~ V_55 ;
F_7 ( V_54 , V_9 ) ;
V_6 -> V_14 . V_54 = V_54 ;
}
}
static void F_25 ( struct V_1 * V_6 , unsigned V_16 )
{
void T_1 * V_10 = V_6 -> V_10 ;
if ( V_6 -> V_12 -> V_42 &&
! F_26 ( V_6 -> V_56 , V_16 ) &&
! F_26 ( V_6 -> V_57 , V_16 ) ) {
F_12 ( V_10 , V_6 -> V_12 -> V_42 , F_6 ( V_16 ) , 0 ) ;
V_6 -> V_14 . V_43 =
F_5 ( V_6 -> V_10 + V_6 -> V_12 -> V_42 ) ;
}
if ( V_6 -> V_12 -> V_54 && ! F_24 ( V_6 ) ) {
void T_1 * V_9 = V_6 -> V_10 + V_6 -> V_12 -> V_54 ;
T_2 V_54 ;
V_54 = F_5 ( V_9 ) ;
V_54 |= V_55 ;
F_7 ( V_54 , V_9 ) ;
V_6 -> V_14 . V_54 = V_54 ;
}
}
static int F_27 ( struct V_1 * V_6 , unsigned V_16 )
{
void T_1 * V_9 = V_6 -> V_10 + V_6 -> V_12 -> V_13 ;
return F_5 ( V_9 ) & F_6 ( V_16 ) ;
}
static void F_28 ( struct V_1 * V_6 , unsigned V_16 )
{
if ( ! F_26 ( V_6 -> V_56 , V_16 ) ) {
F_23 ( V_6 , V_16 ) ;
F_4 ( V_6 , V_16 , 1 ) ;
}
V_6 -> V_57 |= F_6 ( V_16 ) ;
}
static int F_29 ( struct V_2 * V_3 , unsigned type )
{
struct V_1 * V_6 = F_1 ( V_3 ) ;
int V_58 ;
unsigned long V_59 ;
unsigned V_16 = V_3 -> V_60 ;
if ( ! F_24 ( V_6 ) )
F_30 ( V_6 -> V_61 ) ;
if ( type & ~ V_48 )
return - V_50 ;
if ( ! V_6 -> V_12 -> V_33 &&
( type & ( V_34 | V_36 ) ) )
return - V_50 ;
F_31 ( & V_6 -> V_62 , V_59 ) ;
V_58 = F_22 ( V_6 , V_16 , type ) ;
F_28 ( V_6 , V_16 ) ;
if ( ! F_27 ( V_6 , V_16 ) ) {
F_32 ( & V_6 -> V_62 , V_59 ) ;
return - V_50 ;
}
F_32 ( & V_6 -> V_62 , V_59 ) ;
if ( type & ( V_34 | V_36 ) )
F_33 ( V_3 -> V_63 , V_64 ) ;
else if ( type & ( V_40 | V_38 ) )
F_33 ( V_3 -> V_63 , V_65 ) ;
return V_58 ;
}
static void F_34 ( struct V_1 * V_6 , int V_66 )
{
void T_1 * V_9 = V_6 -> V_10 ;
V_9 += V_6 -> V_12 -> V_67 ;
F_7 ( V_66 , V_9 ) ;
if ( V_6 -> V_12 -> V_68 ) {
V_9 = V_6 -> V_10 + V_6 -> V_12 -> V_68 ;
F_7 ( V_66 , V_9 ) ;
}
F_5 ( V_9 ) ;
}
static inline void F_35 ( struct V_1 * V_6 ,
unsigned V_16 )
{
F_34 ( V_6 , F_6 ( V_16 ) ) ;
}
static T_2 F_36 ( struct V_1 * V_6 )
{
void T_1 * V_9 = V_6 -> V_10 ;
T_2 V_11 ;
T_2 V_23 = ( F_6 ( V_6 -> V_69 ) ) - 1 ;
V_9 += V_6 -> V_12 -> V_70 ;
V_11 = F_5 ( V_9 ) ;
if ( V_6 -> V_12 -> V_71 )
V_11 = ~ V_11 ;
V_11 &= V_23 ;
return V_11 ;
}
static void F_37 ( struct V_1 * V_6 , int V_66 )
{
void T_1 * V_9 = V_6 -> V_10 ;
T_2 V_11 ;
if ( V_6 -> V_12 -> V_72 ) {
V_9 += V_6 -> V_12 -> V_72 ;
V_11 = V_66 ;
V_6 -> V_14 . V_73 |= V_66 ;
} else {
V_9 += V_6 -> V_12 -> V_70 ;
V_11 = F_5 ( V_9 ) ;
if ( V_6 -> V_12 -> V_71 )
V_11 &= ~ V_66 ;
else
V_11 |= V_66 ;
V_6 -> V_14 . V_73 = V_11 ;
}
F_7 ( V_11 , V_9 ) ;
}
static void F_38 ( struct V_1 * V_6 , int V_66 )
{
void T_1 * V_9 = V_6 -> V_10 ;
T_2 V_11 ;
if ( V_6 -> V_12 -> V_74 ) {
V_9 += V_6 -> V_12 -> V_74 ;
V_11 = V_66 ;
V_6 -> V_14 . V_73 &= ~ V_66 ;
} else {
V_9 += V_6 -> V_12 -> V_70 ;
V_11 = F_5 ( V_9 ) ;
if ( V_6 -> V_12 -> V_71 )
V_11 |= V_66 ;
else
V_11 &= ~ V_66 ;
V_6 -> V_14 . V_73 = V_11 ;
}
F_7 ( V_11 , V_9 ) ;
}
static inline void F_39 ( struct V_1 * V_6 ,
unsigned V_16 , int V_17 )
{
if ( V_17 )
F_37 ( V_6 , F_6 ( V_16 ) ) ;
else
F_38 ( V_6 , F_6 ( V_16 ) ) ;
}
static int F_40 ( struct V_1 * V_6 , unsigned V_16 ,
int V_17 )
{
T_2 V_21 = F_6 ( V_16 ) ;
unsigned long V_59 ;
if ( V_6 -> V_41 & V_21 ) {
F_41 ( V_6 -> V_61 ,
L_1 ,
V_16 ) ;
return - V_50 ;
}
F_31 ( & V_6 -> V_62 , V_59 ) ;
if ( V_17 )
V_6 -> V_14 . V_43 |= V_21 ;
else
V_6 -> V_14 . V_43 &= ~ V_21 ;
F_7 ( V_6 -> V_14 . V_43 , V_6 -> V_10 + V_6 -> V_12 -> V_42 ) ;
F_32 ( & V_6 -> V_62 , V_59 ) ;
return 0 ;
}
static void F_42 ( struct V_1 * V_6 , unsigned V_16 )
{
F_4 ( V_6 , V_16 , 1 ) ;
F_39 ( V_6 , V_16 , 0 ) ;
F_35 ( V_6 , V_16 ) ;
F_22 ( V_6 , V_16 , V_75 ) ;
F_18 ( V_6 , V_16 ) ;
}
static int F_43 ( struct V_2 * V_3 , unsigned int V_17 )
{
struct V_1 * V_6 = F_1 ( V_3 ) ;
unsigned V_16 = V_3 -> V_60 ;
return F_40 ( V_6 , V_16 , V_17 ) ;
}
static int F_44 ( struct V_4 * V_5 , unsigned V_16 )
{
struct V_1 * V_6 = F_3 ( V_5 , struct V_1 , V_5 ) ;
unsigned long V_59 ;
if ( ! F_24 ( V_6 ) )
F_30 ( V_6 -> V_61 ) ;
F_31 ( & V_6 -> V_62 , V_59 ) ;
if ( ! F_26 ( V_6 -> V_57 , V_16 ) ) {
F_22 ( V_6 , V_16 , V_75 ) ;
F_23 ( V_6 , V_16 ) ;
}
V_6 -> V_56 |= F_6 ( V_16 ) ;
F_32 ( & V_6 -> V_62 , V_59 ) ;
return 0 ;
}
static void F_45 ( struct V_4 * V_5 , unsigned V_16 )
{
struct V_1 * V_6 = F_3 ( V_5 , struct V_1 , V_5 ) ;
unsigned long V_59 ;
F_31 ( & V_6 -> V_62 , V_59 ) ;
V_6 -> V_56 &= ~ ( F_6 ( V_16 ) ) ;
F_25 ( V_6 , V_16 ) ;
F_42 ( V_6 , V_16 ) ;
F_32 ( & V_6 -> V_62 , V_59 ) ;
if ( ! F_24 ( V_6 ) )
F_46 ( V_6 -> V_61 ) ;
}
static void F_47 ( unsigned int V_63 , struct V_76 * V_77 )
{
void T_1 * V_78 = NULL ;
T_2 V_79 ;
unsigned int V_80 ;
struct V_1 * V_6 ;
int V_81 = 0 ;
struct V_82 * V_83 = F_48 ( V_77 ) ;
struct V_4 * V_5 = F_49 ( V_63 ) ;
F_50 ( V_83 , V_77 ) ;
V_6 = F_3 ( V_5 , struct V_1 , V_5 ) ;
V_78 = V_6 -> V_10 + V_6 -> V_12 -> V_67 ;
F_30 ( V_6 -> V_61 ) ;
if ( F_51 ( ! V_78 ) )
goto exit;
while ( 1 ) {
T_2 V_84 , V_47 = 0 ;
T_2 V_85 ;
V_85 = F_36 ( V_6 ) ;
V_84 = V_79 = F_5 ( V_78 ) & V_85 ;
if ( V_6 -> V_47 )
V_47 = V_6 -> V_47 & V_85 ;
F_38 ( V_6 , V_84 & ~ V_47 ) ;
F_34 ( V_6 , V_84 & ~ V_47 ) ;
F_37 ( V_6 , V_84 & ~ V_47 ) ;
if ( ! V_47 && ! V_81 ) {
V_81 = 1 ;
F_52 ( V_83 , V_77 ) ;
}
if ( ! V_79 )
break;
while ( V_79 ) {
V_80 = F_53 ( V_79 ) ;
V_79 &= ~ ( F_6 ( V_80 ) ) ;
if ( V_6 -> V_49 & ( F_6 ( V_80 ) ) )
F_21 ( V_6 , V_80 ) ;
F_54 ( F_55 ( V_6 -> V_5 . V_86 ,
V_80 ) ) ;
}
}
exit:
if ( ! V_81 )
F_52 ( V_83 , V_77 ) ;
F_46 ( V_6 -> V_61 ) ;
}
static unsigned int F_56 ( struct V_2 * V_3 )
{
struct V_1 * V_6 = F_1 ( V_3 ) ;
unsigned long V_59 ;
unsigned V_16 = V_3 -> V_60 ;
if ( ! F_24 ( V_6 ) )
F_30 ( V_6 -> V_61 ) ;
F_31 ( & V_6 -> V_62 , V_59 ) ;
F_28 ( V_6 , V_16 ) ;
F_32 ( & V_6 -> V_62 , V_59 ) ;
F_57 ( V_3 ) ;
return 0 ;
}
static void F_58 ( struct V_2 * V_3 )
{
struct V_1 * V_6 = F_1 ( V_3 ) ;
unsigned long V_59 ;
unsigned V_16 = V_3 -> V_60 ;
F_31 ( & V_6 -> V_62 , V_59 ) ;
V_6 -> V_57 &= ~ ( F_6 ( V_16 ) ) ;
F_25 ( V_6 , V_16 ) ;
F_42 ( V_6 , V_16 ) ;
F_32 ( & V_6 -> V_62 , V_59 ) ;
if ( ! F_24 ( V_6 ) )
F_46 ( V_6 -> V_61 ) ;
}
static void F_59 ( struct V_2 * V_3 )
{
struct V_1 * V_6 = F_1 ( V_3 ) ;
unsigned V_16 = V_3 -> V_60 ;
F_35 ( V_6 , V_16 ) ;
}
static void F_60 ( struct V_2 * V_3 )
{
struct V_1 * V_6 = F_1 ( V_3 ) ;
unsigned V_16 = V_3 -> V_60 ;
unsigned long V_59 ;
F_31 ( & V_6 -> V_62 , V_59 ) ;
F_39 ( V_6 , V_16 , 0 ) ;
F_22 ( V_6 , V_16 , V_75 ) ;
F_32 ( & V_6 -> V_62 , V_59 ) ;
}
static void F_57 ( struct V_2 * V_3 )
{
struct V_1 * V_6 = F_1 ( V_3 ) ;
unsigned V_16 = V_3 -> V_60 ;
T_2 V_32 = F_61 ( V_3 ) ;
unsigned long V_59 ;
F_31 ( & V_6 -> V_62 , V_59 ) ;
if ( V_32 )
F_22 ( V_6 , V_16 , V_32 ) ;
if ( V_6 -> V_47 & F_6 ( V_16 ) ) {
F_39 ( V_6 , V_16 , 0 ) ;
F_35 ( V_6 , V_16 ) ;
}
F_39 ( V_6 , V_16 , 1 ) ;
F_32 ( & V_6 -> V_62 , V_59 ) ;
}
static int F_62 ( struct V_87 * V_61 )
{
struct V_88 * V_89 = F_63 ( V_61 ) ;
struct V_1 * V_6 = F_64 ( V_89 ) ;
void T_1 * V_90 = V_6 -> V_10 +
V_91 / V_6 -> V_92 ;
unsigned long V_59 ;
F_31 ( & V_6 -> V_62 , V_59 ) ;
F_7 ( 0xffff & ~ V_6 -> V_14 . V_43 , V_90 ) ;
F_32 ( & V_6 -> V_62 , V_59 ) ;
return 0 ;
}
static int F_65 ( struct V_87 * V_61 )
{
struct V_88 * V_89 = F_63 ( V_61 ) ;
struct V_1 * V_6 = F_64 ( V_89 ) ;
void T_1 * V_90 = V_6 -> V_10 +
V_91 / V_6 -> V_92 ;
unsigned long V_59 ;
F_31 ( & V_6 -> V_62 , V_59 ) ;
F_7 ( V_6 -> V_14 . V_43 , V_90 ) ;
F_32 ( & V_6 -> V_62 , V_59 ) ;
return 0 ;
}
static inline void F_66 ( struct V_1 * V_6 )
{
F_67 ( & V_93 , V_6 ) ;
if ( F_68 ( & V_94 ) == 0 )
( void ) F_69 ( & V_93 ) ;
}
static int F_70 ( struct V_4 * V_5 , unsigned V_16 )
{
struct V_1 * V_6 ;
unsigned long V_59 ;
void T_1 * V_9 ;
int V_95 ;
V_6 = F_3 ( V_5 , struct V_1 , V_5 ) ;
V_9 = V_6 -> V_10 + V_6 -> V_12 -> V_13 ;
F_31 ( & V_6 -> V_62 , V_59 ) ;
V_95 = ! ! ( F_5 ( V_9 ) & F_6 ( V_16 ) ) ;
F_32 ( & V_6 -> V_62 , V_59 ) ;
return V_95 ;
}
static int F_71 ( struct V_4 * V_5 , unsigned V_16 )
{
struct V_1 * V_6 ;
unsigned long V_59 ;
V_6 = F_3 ( V_5 , struct V_1 , V_5 ) ;
F_31 ( & V_6 -> V_62 , V_59 ) ;
F_4 ( V_6 , V_16 , 1 ) ;
F_32 ( & V_6 -> V_62 , V_59 ) ;
return 0 ;
}
static int F_72 ( struct V_4 * V_5 , unsigned V_16 )
{
struct V_1 * V_6 ;
V_6 = F_3 ( V_5 , struct V_1 , V_5 ) ;
if ( F_27 ( V_6 , V_16 ) )
return F_10 ( V_6 , V_16 ) ;
else
return F_11 ( V_6 , V_16 ) ;
}
static int F_73 ( struct V_4 * V_5 , unsigned V_16 , int V_96 )
{
struct V_1 * V_6 ;
unsigned long V_59 ;
V_6 = F_3 ( V_5 , struct V_1 , V_5 ) ;
F_31 ( & V_6 -> V_62 , V_59 ) ;
V_6 -> V_18 ( V_6 , V_16 , V_96 ) ;
F_4 ( V_6 , V_16 , 0 ) ;
F_32 ( & V_6 -> V_62 , V_59 ) ;
return 0 ;
}
static int F_74 ( struct V_4 * V_5 , unsigned V_16 ,
unsigned V_29 )
{
struct V_1 * V_6 ;
unsigned long V_59 ;
V_6 = F_3 ( V_5 , struct V_1 , V_5 ) ;
F_31 ( & V_6 -> V_62 , V_59 ) ;
F_17 ( V_6 , V_16 , V_29 ) ;
F_32 ( & V_6 -> V_62 , V_59 ) ;
return 0 ;
}
static void F_75 ( struct V_4 * V_5 , unsigned V_16 , int V_96 )
{
struct V_1 * V_6 ;
unsigned long V_59 ;
V_6 = F_3 ( V_5 , struct V_1 , V_5 ) ;
F_31 ( & V_6 -> V_62 , V_59 ) ;
V_6 -> V_18 ( V_6 , V_16 , V_96 ) ;
F_32 ( & V_6 -> V_62 , V_59 ) ;
}
static void T_3 F_76 ( struct V_1 * V_6 )
{
static bool V_97 ;
T_2 V_98 ;
if ( V_97 || V_6 -> V_12 -> V_99 == V_100 )
return;
V_98 = F_77 ( V_6 -> V_10 + V_6 -> V_12 -> V_99 ) ;
F_78 ( L_2 ,
( V_98 >> 4 ) & 0x0f , V_98 & 0x0f ) ;
V_97 = true ;
}
static void F_79 ( struct V_1 * V_6 )
{
void T_1 * V_10 = V_6 -> V_10 ;
T_2 V_11 = 0xffffffff ;
if ( V_6 -> V_69 == 16 )
V_11 = 0xffff ;
if ( V_6 -> V_101 ) {
F_7 ( V_11 , V_6 -> V_10 + V_6 -> V_12 -> V_70 ) ;
return;
}
F_12 ( V_10 , V_6 -> V_12 -> V_70 , V_11 ,
V_6 -> V_12 -> V_71 ) ;
F_12 ( V_10 , V_6 -> V_12 -> V_67 , V_11 ,
! V_6 -> V_12 -> V_71 ) ;
if ( V_6 -> V_12 -> V_28 )
F_7 ( 0 , V_10 + V_6 -> V_12 -> V_28 ) ;
V_6 -> V_14 . V_15 = F_5 ( V_6 -> V_10 + V_6 -> V_12 -> V_13 ) ;
if ( V_6 -> V_12 -> V_54 )
F_7 ( 0 , V_10 + V_6 -> V_12 -> V_54 ) ;
V_6 -> V_27 = F_80 ( V_6 -> V_61 , L_3 ) ;
if ( F_81 ( V_6 -> V_27 ) )
F_41 ( V_6 -> V_61 , L_4 ) ;
}
static int F_82 ( struct V_1 * V_6 , struct V_82 * V_102 )
{
static int V_7 ;
int V_103 = 0 ;
int V_104 ;
V_6 -> V_5 . V_105 = F_44 ;
V_6 -> V_5 . free = F_45 ;
V_6 -> V_5 . V_106 = F_70 ;
V_6 -> V_5 . V_107 = F_71 ;
V_6 -> V_5 . V_108 = F_72 ;
V_6 -> V_5 . V_109 = F_73 ;
V_6 -> V_5 . V_110 = F_74 ;
V_6 -> V_5 . V_24 = F_75 ;
if ( V_6 -> V_101 ) {
V_6 -> V_5 . V_111 = L_5 ;
if ( V_6 -> V_12 -> V_42 )
V_6 -> V_5 . V_61 = & V_93 . V_61 ;
V_6 -> V_5 . V_10 = F_83 ( 0 ) ;
} else {
V_6 -> V_5 . V_111 = L_6 ;
V_6 -> V_5 . V_10 = V_7 ;
V_7 += V_6 -> V_69 ;
}
V_6 -> V_5 . V_112 = V_6 -> V_69 ;
V_104 = F_84 ( & V_6 -> V_5 ) ;
if ( V_104 ) {
F_41 ( V_6 -> V_61 , L_7 , V_104 ) ;
return V_104 ;
}
#ifdef F_85
V_103 = F_86 ( - 1 , 0 , V_6 -> V_69 , 0 ) ;
if ( V_103 < 0 ) {
F_41 ( V_6 -> V_61 , L_8 ) ;
return - V_113 ;
}
#endif
if ( V_6 -> V_101 ) {
V_102 -> V_114 = V_115 . V_114 ;
V_102 -> V_116 = V_117 ;
V_102 -> V_118 = V_119 ;
if ( ! V_6 -> V_12 -> V_42 )
V_102 -> V_120 = NULL ;
}
V_104 = F_87 ( & V_6 -> V_5 , V_102 ,
V_103 , F_47 ,
V_75 ) ;
if ( V_104 ) {
F_41 ( V_6 -> V_61 , L_9 , V_104 ) ;
F_88 ( & V_6 -> V_5 ) ;
return - V_113 ;
}
F_89 ( & V_6 -> V_5 , V_102 ,
V_6 -> V_63 , F_47 ) ;
return 0 ;
}
static int F_90 ( struct V_88 * V_89 )
{
struct V_87 * V_61 = & V_89 -> V_61 ;
struct V_121 * V_122 = V_61 -> V_123 ;
const struct V_124 * V_125 ;
const struct V_126 * V_127 ;
struct V_128 * V_129 ;
struct V_1 * V_6 ;
struct V_82 * V_102 ;
int V_104 ;
V_125 = F_91 ( F_92 ( V_130 ) , V_61 ) ;
V_127 = V_125 ? V_125 -> V_131 : F_93 ( V_61 ) ;
if ( ! V_127 )
return - V_50 ;
V_6 = F_94 ( V_61 , sizeof( struct V_1 ) , V_132 ) ;
if ( ! V_6 ) {
F_41 ( V_61 , L_10 ) ;
return - V_133 ;
}
V_102 = F_94 ( V_61 , sizeof( * V_102 ) , V_132 ) ;
if ( ! V_102 )
return - V_133 ;
V_102 -> V_134 = F_56 ,
V_102 -> V_135 = F_58 ,
V_102 -> V_114 = F_59 ,
V_102 -> V_116 = F_60 ,
V_102 -> V_118 = F_57 ,
V_102 -> V_136 = F_29 ,
V_102 -> V_120 = F_43 ,
V_102 -> V_137 = F_95 ( & V_89 -> V_61 ) ;
V_129 = F_96 ( V_89 , V_138 , 0 ) ;
if ( F_97 ( ! V_129 ) ) {
F_41 ( V_61 , L_11 ) ;
return - V_113 ;
}
V_6 -> V_63 = V_129 -> V_139 ;
V_6 -> V_61 = V_61 ;
V_6 -> V_5 . V_61 = V_61 ;
V_6 -> V_31 = V_127 -> V_31 ;
V_6 -> V_92 = V_127 -> V_140 ;
V_6 -> V_69 = V_127 -> V_141 ;
V_6 -> V_101 = V_127 -> V_101 ;
V_6 -> V_41 = V_127 -> V_41 ;
V_6 -> V_12 = V_127 -> V_12 ;
#ifdef F_98
V_6 -> V_5 . V_123 = F_99 ( V_122 ) ;
#endif
if ( V_122 ) {
if ( ! F_100 ( V_122 , L_12 ) )
V_6 -> V_142 = true ;
} else {
V_6 -> V_142 = V_127 -> V_142 ;
if ( V_6 -> V_142 )
V_6 -> V_143 =
V_127 -> V_143 ;
}
if ( V_6 -> V_12 -> V_18 && V_6 -> V_12 -> V_20 )
V_6 -> V_18 = F_8 ;
else
V_6 -> V_18 = F_9 ;
F_101 ( & V_6 -> V_62 ) ;
V_129 = F_96 ( V_89 , V_144 , 0 ) ;
V_6 -> V_10 = F_102 ( V_61 , V_129 ) ;
if ( F_81 ( V_6 -> V_10 ) ) {
F_103 ( V_6 -> V_5 . V_86 ) ;
return F_104 ( V_6 -> V_10 ) ;
}
F_67 ( V_89 , V_6 ) ;
F_105 ( V_6 -> V_61 ) ;
F_106 ( V_6 -> V_61 ) ;
F_30 ( V_6 -> V_61 ) ;
if ( V_6 -> V_101 )
F_66 ( V_6 ) ;
F_79 ( V_6 ) ;
V_104 = F_82 ( V_6 , V_102 ) ;
if ( V_104 )
return V_104 ;
F_76 ( V_6 ) ;
F_46 ( V_6 -> V_61 ) ;
F_107 ( & V_6 -> V_122 , & V_145 ) ;
return 0 ;
}
static int F_108 ( struct V_87 * V_61 )
{
struct V_88 * V_89 = F_63 ( V_61 ) ;
struct V_1 * V_6 = F_64 ( V_89 ) ;
T_2 V_146 = 0 , V_147 = 0 ;
unsigned long V_59 ;
T_2 V_148 , V_149 ;
F_31 ( & V_6 -> V_62 , V_59 ) ;
V_148 = V_6 -> V_14 . V_33 & V_6 -> V_14 . V_43 ;
if ( V_148 )
F_7 ( V_148 | V_6 -> V_14 . V_39 ,
V_6 -> V_10 + V_6 -> V_12 -> V_39 ) ;
V_149 = V_6 -> V_14 . V_35 & V_6 -> V_14 . V_43 ;
if ( V_149 )
F_7 ( V_149 | V_6 -> V_14 . V_37 ,
V_6 -> V_10 + V_6 -> V_12 -> V_37 ) ;
if ( ! V_6 -> V_46 )
goto V_150;
if ( V_6 -> V_151 != V_152 ) {
V_6 -> V_151 = 0 ;
goto V_150;
}
V_6 -> V_153 = F_5 ( V_6 -> V_10 +
V_6 -> V_12 -> V_22 ) ;
V_146 = V_6 -> V_14 . V_39 ;
V_147 = V_6 -> V_14 . V_37 ;
V_146 &= ~ V_6 -> V_46 ;
V_147 &= ~ V_6 -> V_46 ;
F_7 ( V_146 , V_6 -> V_10 + V_6 -> V_12 -> V_39 ) ;
F_7 ( V_147 , V_6 -> V_10 + V_6 -> V_12 -> V_37 ) ;
V_6 -> V_154 = true ;
V_150:
if ( V_6 -> V_143 )
V_6 -> V_155 =
V_6 -> V_143 ( V_6 -> V_61 ) ;
F_15 ( V_6 ) ;
F_32 ( & V_6 -> V_62 , V_59 ) ;
return 0 ;
}
static int F_109 ( struct V_87 * V_61 )
{
struct V_88 * V_89 = F_63 ( V_61 ) ;
struct V_1 * V_6 = F_64 ( V_89 ) ;
T_2 V_11 = 0 , V_156 , V_157 , V_158 ;
unsigned long V_59 ;
int V_159 ;
F_31 ( & V_6 -> V_62 , V_59 ) ;
if ( V_6 -> V_142 && ! V_6 -> V_160 ) {
F_110 ( V_6 ) ;
if ( V_6 -> V_143 )
V_6 -> V_155 =
V_6 -> V_143 ( V_6 -> V_61 ) ;
}
F_13 ( V_6 ) ;
F_7 ( V_6 -> V_14 . V_39 ,
V_6 -> V_10 + V_6 -> V_12 -> V_39 ) ;
F_7 ( V_6 -> V_14 . V_37 ,
V_6 -> V_10 + V_6 -> V_12 -> V_37 ) ;
if ( V_6 -> V_142 ) {
if ( ! V_6 -> V_143 ) {
F_111 ( V_6 ) ;
} else {
V_159 = V_6 -> V_143 ( V_6 -> V_61 ) ;
if ( V_159 != V_6 -> V_155 ) {
F_111 ( V_6 ) ;
} else {
F_32 ( & V_6 -> V_62 , V_59 ) ;
return 0 ;
}
}
}
if ( ! V_6 -> V_154 ) {
F_32 ( & V_6 -> V_62 , V_59 ) ;
return 0 ;
}
V_11 = F_5 ( V_6 -> V_10 + V_6 -> V_12 -> V_22 ) ;
V_11 ^= V_6 -> V_153 ;
V_11 &= V_6 -> V_46 ;
V_157 = V_11 & V_6 -> V_14 . V_39 ;
V_157 &= V_6 -> V_153 ;
V_158 = V_11 & V_6 -> V_14 . V_37 ;
V_158 &= ~ ( V_6 -> V_153 ) ;
V_156 = V_11 & ( ~ ( V_6 -> V_14 . V_39 ) &
~ ( V_6 -> V_14 . V_37 ) ) ;
V_156 |= V_157 | V_158 ;
if ( V_156 ) {
T_2 V_161 , V_162 ;
V_161 = F_5 ( V_6 -> V_10 + V_6 -> V_12 -> V_33 ) ;
V_162 = F_5 ( V_6 -> V_10 + V_6 -> V_12 -> V_35 ) ;
if ( ! V_6 -> V_12 -> V_163 ) {
F_7 ( V_161 | V_156 , V_6 -> V_10 +
V_6 -> V_12 -> V_33 ) ;
F_7 ( V_162 | V_156 , V_6 -> V_10 +
V_6 -> V_12 -> V_35 ) ;
}
if ( V_6 -> V_12 -> V_163 ) {
F_7 ( V_161 | V_11 , V_6 -> V_10 +
V_6 -> V_12 -> V_33 ) ;
F_7 ( V_162 | V_11 , V_6 -> V_10 +
V_6 -> V_12 -> V_35 ) ;
}
F_7 ( V_161 , V_6 -> V_10 + V_6 -> V_12 -> V_33 ) ;
F_7 ( V_162 , V_6 -> V_10 + V_6 -> V_12 -> V_35 ) ;
}
V_6 -> V_154 = false ;
F_32 ( & V_6 -> V_62 , V_59 ) ;
return 0 ;
}
void F_112 ( int V_164 )
{
struct V_1 * V_6 ;
F_113 (bank, &omap_gpio_list, node) {
if ( ! F_24 ( V_6 ) || ! V_6 -> V_142 )
continue;
V_6 -> V_151 = V_164 ;
F_114 ( V_6 -> V_61 ) ;
}
}
void F_115 ( void )
{
struct V_1 * V_6 ;
F_113 (bank, &omap_gpio_list, node) {
if ( ! F_24 ( V_6 ) || ! V_6 -> V_142 )
continue;
F_30 ( V_6 -> V_61 ) ;
}
}
static void F_110 ( struct V_1 * V_165 )
{
struct V_166 * V_12 = V_165 -> V_12 ;
void T_1 * V_10 = V_165 -> V_10 ;
V_165 -> V_14 . V_54 = F_5 ( V_10 + V_12 -> V_54 ) ;
V_165 -> V_14 . V_15 = F_5 ( V_10 + V_12 -> V_13 ) ;
V_165 -> V_14 . V_43 = F_5 ( V_10 + V_12 -> V_42 ) ;
V_165 -> V_14 . V_33 = F_5 ( V_10 + V_12 -> V_33 ) ;
V_165 -> V_14 . V_35 = F_5 ( V_10 + V_12 -> V_35 ) ;
V_165 -> V_14 . V_37 = F_5 ( V_10 + V_12 -> V_37 ) ;
V_165 -> V_14 . V_39 = F_5 ( V_10 + V_12 -> V_39 ) ;
V_165 -> V_14 . V_73 = F_5 ( V_10 + V_12 -> V_70 ) ;
V_165 -> V_14 . V_167 = F_5 ( V_10 + V_12 -> V_167 ) ;
if ( V_12 -> V_18 && V_165 -> V_12 -> V_20 )
V_165 -> V_14 . V_19 = F_5 ( V_10 + V_12 -> V_18 ) ;
else
V_165 -> V_14 . V_19 = F_5 ( V_10 + V_12 -> V_19 ) ;
V_165 -> V_160 = true ;
}
static void F_111 ( struct V_1 * V_6 )
{
F_7 ( V_6 -> V_14 . V_43 ,
V_6 -> V_10 + V_6 -> V_12 -> V_42 ) ;
F_7 ( V_6 -> V_14 . V_54 , V_6 -> V_10 + V_6 -> V_12 -> V_54 ) ;
F_7 ( V_6 -> V_14 . V_33 ,
V_6 -> V_10 + V_6 -> V_12 -> V_33 ) ;
F_7 ( V_6 -> V_14 . V_35 ,
V_6 -> V_10 + V_6 -> V_12 -> V_35 ) ;
F_7 ( V_6 -> V_14 . V_37 ,
V_6 -> V_10 + V_6 -> V_12 -> V_37 ) ;
F_7 ( V_6 -> V_14 . V_39 ,
V_6 -> V_10 + V_6 -> V_12 -> V_39 ) ;
if ( V_6 -> V_12 -> V_18 && V_6 -> V_12 -> V_20 )
F_7 ( V_6 -> V_14 . V_19 ,
V_6 -> V_10 + V_6 -> V_12 -> V_18 ) ;
else
F_7 ( V_6 -> V_14 . V_19 ,
V_6 -> V_10 + V_6 -> V_12 -> V_19 ) ;
F_7 ( V_6 -> V_14 . V_15 , V_6 -> V_10 + V_6 -> V_12 -> V_13 ) ;
if ( V_6 -> V_25 ) {
F_7 ( V_6 -> V_14 . V_29 , V_6 -> V_10 +
V_6 -> V_12 -> V_29 ) ;
F_7 ( V_6 -> V_14 . V_28 ,
V_6 -> V_10 + V_6 -> V_12 -> V_28 ) ;
}
F_7 ( V_6 -> V_14 . V_73 ,
V_6 -> V_10 + V_6 -> V_12 -> V_70 ) ;
F_7 ( V_6 -> V_14 . V_167 ,
V_6 -> V_10 + V_6 -> V_12 -> V_167 ) ;
}
static inline void F_110 ( struct V_1 * V_165 ) {}
static int T_3 F_116 ( void )
{
return F_68 ( & V_168 ) ;
}
