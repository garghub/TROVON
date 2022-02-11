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
if ( type & ~ V_48 )
return - V_50 ;
if ( ! V_6 -> V_12 -> V_33 &&
( type & ( V_34 | V_36 ) ) )
return - V_50 ;
if ( ! F_24 ( V_6 ) )
F_30 ( V_6 -> V_61 ) ;
F_31 ( & V_6 -> V_62 , V_59 ) ;
V_58 = F_22 ( V_6 , V_16 , type ) ;
if ( V_58 ) {
F_32 ( & V_6 -> V_62 , V_59 ) ;
goto error;
}
F_28 ( V_6 , V_16 ) ;
if ( ! F_27 ( V_6 , V_16 ) ) {
F_32 ( & V_6 -> V_62 , V_59 ) ;
V_58 = - V_50 ;
goto error;
}
F_32 ( & V_6 -> V_62 , V_59 ) ;
if ( type & ( V_34 | V_36 ) )
F_33 ( V_3 -> V_63 , V_64 ) ;
else if ( type & ( V_40 | V_38 ) )
F_33 ( V_3 -> V_63 , V_65 ) ;
return 0 ;
error:
if ( ! F_24 ( V_6 ) )
F_34 ( V_6 -> V_61 ) ;
return V_58 ;
}
static void F_35 ( struct V_1 * V_6 , int V_66 )
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
static inline void F_36 ( struct V_1 * V_6 ,
unsigned V_16 )
{
F_35 ( V_6 , F_6 ( V_16 ) ) ;
}
static T_2 F_37 ( struct V_1 * V_6 )
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
static void F_38 ( struct V_1 * V_6 , int V_66 )
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
static void F_39 ( struct V_1 * V_6 , int V_66 )
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
static inline void F_40 ( struct V_1 * V_6 ,
unsigned V_16 , int V_17 )
{
if ( V_17 )
F_38 ( V_6 , F_6 ( V_16 ) ) ;
else
F_39 ( V_6 , F_6 ( V_16 ) ) ;
}
static int F_41 ( struct V_1 * V_6 , unsigned V_16 ,
int V_17 )
{
T_2 V_21 = F_6 ( V_16 ) ;
unsigned long V_59 ;
if ( V_6 -> V_41 & V_21 ) {
F_42 ( V_6 -> V_61 ,
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
static int F_43 ( struct V_2 * V_3 , unsigned int V_17 )
{
struct V_1 * V_6 = F_1 ( V_3 ) ;
unsigned V_16 = V_3 -> V_60 ;
return F_41 ( V_6 , V_16 , V_17 ) ;
}
static int F_44 ( struct V_4 * V_5 , unsigned V_16 )
{
struct V_1 * V_6 = F_3 ( V_5 , struct V_1 , V_5 ) ;
unsigned long V_59 ;
if ( ! F_24 ( V_6 ) )
F_30 ( V_6 -> V_61 ) ;
F_31 ( & V_6 -> V_62 , V_59 ) ;
F_23 ( V_6 , V_16 ) ;
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
if ( ! F_26 ( V_6 -> V_57 , V_16 ) ) {
F_4 ( V_6 , V_16 , 1 ) ;
F_18 ( V_6 , V_16 ) ;
}
F_25 ( V_6 , V_16 ) ;
F_32 ( & V_6 -> V_62 , V_59 ) ;
if ( ! F_24 ( V_6 ) )
F_34 ( V_6 -> V_61 ) ;
}
static void F_46 ( unsigned int V_63 , struct V_75 * V_76 )
{
void T_1 * V_77 = NULL ;
T_2 V_78 ;
unsigned int V_79 ;
struct V_1 * V_6 ;
int V_80 = 0 ;
struct V_81 * V_82 = F_47 ( V_76 ) ;
struct V_4 * V_5 = F_48 ( V_63 ) ;
F_49 ( V_82 , V_76 ) ;
V_6 = F_3 ( V_5 , struct V_1 , V_5 ) ;
V_77 = V_6 -> V_10 + V_6 -> V_12 -> V_67 ;
F_30 ( V_6 -> V_61 ) ;
if ( F_50 ( ! V_77 ) )
goto exit;
while ( 1 ) {
T_2 V_83 , V_47 = 0 ;
T_2 V_84 ;
V_84 = F_37 ( V_6 ) ;
V_83 = V_78 = F_5 ( V_77 ) & V_84 ;
if ( V_6 -> V_47 )
V_47 = V_6 -> V_47 & V_84 ;
F_39 ( V_6 , V_83 & ~ V_47 ) ;
F_35 ( V_6 , V_83 & ~ V_47 ) ;
F_38 ( V_6 , V_83 & ~ V_47 ) ;
if ( ! V_47 && ! V_80 ) {
V_80 = 1 ;
F_51 ( V_82 , V_76 ) ;
}
if ( ! V_78 )
break;
while ( V_78 ) {
V_79 = F_52 ( V_78 ) ;
V_78 &= ~ ( F_6 ( V_79 ) ) ;
if ( V_6 -> V_49 & ( F_6 ( V_79 ) ) )
F_21 ( V_6 , V_79 ) ;
F_53 ( F_54 ( V_6 -> V_5 . V_85 ,
V_79 ) ) ;
}
}
exit:
if ( ! V_80 )
F_51 ( V_82 , V_76 ) ;
F_34 ( V_6 -> V_61 ) ;
}
static unsigned int F_55 ( struct V_2 * V_3 )
{
struct V_1 * V_6 = F_1 ( V_3 ) ;
unsigned long V_59 ;
unsigned V_16 = V_3 -> V_60 ;
if ( ! F_24 ( V_6 ) )
F_30 ( V_6 -> V_61 ) ;
F_31 ( & V_6 -> V_62 , V_59 ) ;
if ( ! F_26 ( V_6 -> V_56 , V_16 ) )
F_4 ( V_6 , V_16 , 1 ) ;
else if ( ! F_27 ( V_6 , V_16 ) )
goto V_86;
F_23 ( V_6 , V_16 ) ;
V_6 -> V_57 |= F_6 ( V_16 ) ;
F_32 ( & V_6 -> V_62 , V_59 ) ;
F_56 ( V_3 ) ;
return 0 ;
V_86:
F_32 ( & V_6 -> V_62 , V_59 ) ;
if ( ! F_24 ( V_6 ) )
F_34 ( V_6 -> V_61 ) ;
return - V_50 ;
}
static void F_57 ( struct V_2 * V_3 )
{
struct V_1 * V_6 = F_1 ( V_3 ) ;
unsigned long V_59 ;
unsigned V_16 = V_3 -> V_60 ;
F_31 ( & V_6 -> V_62 , V_59 ) ;
V_6 -> V_57 &= ~ ( F_6 ( V_16 ) ) ;
F_40 ( V_6 , V_16 , 0 ) ;
F_36 ( V_6 , V_16 ) ;
F_22 ( V_6 , V_16 , V_87 ) ;
if ( ! F_26 ( V_6 -> V_56 , V_16 ) )
F_18 ( V_6 , V_16 ) ;
F_25 ( V_6 , V_16 ) ;
F_32 ( & V_6 -> V_62 , V_59 ) ;
if ( ! F_24 ( V_6 ) )
F_34 ( V_6 -> V_61 ) ;
}
static void F_58 ( struct V_2 * V_3 )
{
struct V_1 * V_6 = F_1 ( V_3 ) ;
unsigned V_16 = V_3 -> V_60 ;
F_36 ( V_6 , V_16 ) ;
}
static void F_59 ( struct V_2 * V_3 )
{
struct V_1 * V_6 = F_1 ( V_3 ) ;
unsigned V_16 = V_3 -> V_60 ;
unsigned long V_59 ;
F_31 ( & V_6 -> V_62 , V_59 ) ;
F_40 ( V_6 , V_16 , 0 ) ;
F_22 ( V_6 , V_16 , V_87 ) ;
F_32 ( & V_6 -> V_62 , V_59 ) ;
}
static void F_56 ( struct V_2 * V_3 )
{
struct V_1 * V_6 = F_1 ( V_3 ) ;
unsigned V_16 = V_3 -> V_60 ;
T_2 V_32 = F_60 ( V_3 ) ;
unsigned long V_59 ;
F_31 ( & V_6 -> V_62 , V_59 ) ;
if ( V_32 )
F_22 ( V_6 , V_16 , V_32 ) ;
if ( V_6 -> V_47 & F_6 ( V_16 ) ) {
F_40 ( V_6 , V_16 , 0 ) ;
F_36 ( V_6 , V_16 ) ;
}
F_40 ( V_6 , V_16 , 1 ) ;
F_32 ( & V_6 -> V_62 , V_59 ) ;
}
static int F_61 ( struct V_88 * V_61 )
{
struct V_89 * V_90 = F_62 ( V_61 ) ;
struct V_1 * V_6 = F_63 ( V_90 ) ;
void T_1 * V_91 = V_6 -> V_10 +
V_92 / V_6 -> V_93 ;
unsigned long V_59 ;
F_31 ( & V_6 -> V_62 , V_59 ) ;
F_7 ( 0xffff & ~ V_6 -> V_14 . V_43 , V_91 ) ;
F_32 ( & V_6 -> V_62 , V_59 ) ;
return 0 ;
}
static int F_64 ( struct V_88 * V_61 )
{
struct V_89 * V_90 = F_62 ( V_61 ) ;
struct V_1 * V_6 = F_63 ( V_90 ) ;
void T_1 * V_91 = V_6 -> V_10 +
V_92 / V_6 -> V_93 ;
unsigned long V_59 ;
F_31 ( & V_6 -> V_62 , V_59 ) ;
F_7 ( V_6 -> V_14 . V_43 , V_91 ) ;
F_32 ( & V_6 -> V_62 , V_59 ) ;
return 0 ;
}
static inline void F_65 ( struct V_1 * V_6 )
{
F_66 ( & V_94 , V_6 ) ;
if ( F_67 ( & V_95 ) == 0 )
( void ) F_68 ( & V_94 ) ;
}
static int F_69 ( struct V_4 * V_5 , unsigned V_16 )
{
struct V_1 * V_6 ;
unsigned long V_59 ;
void T_1 * V_9 ;
int V_96 ;
V_6 = F_3 ( V_5 , struct V_1 , V_5 ) ;
V_9 = V_6 -> V_10 + V_6 -> V_12 -> V_13 ;
F_31 ( & V_6 -> V_62 , V_59 ) ;
V_96 = ! ! ( F_5 ( V_9 ) & F_6 ( V_16 ) ) ;
F_32 ( & V_6 -> V_62 , V_59 ) ;
return V_96 ;
}
static int F_70 ( struct V_4 * V_5 , unsigned V_16 )
{
struct V_1 * V_6 ;
unsigned long V_59 ;
V_6 = F_3 ( V_5 , struct V_1 , V_5 ) ;
F_31 ( & V_6 -> V_62 , V_59 ) ;
F_4 ( V_6 , V_16 , 1 ) ;
F_32 ( & V_6 -> V_62 , V_59 ) ;
return 0 ;
}
static int F_71 ( struct V_4 * V_5 , unsigned V_16 )
{
struct V_1 * V_6 ;
V_6 = F_3 ( V_5 , struct V_1 , V_5 ) ;
if ( F_27 ( V_6 , V_16 ) )
return F_10 ( V_6 , V_16 ) ;
else
return F_11 ( V_6 , V_16 ) ;
}
static int F_72 ( struct V_4 * V_5 , unsigned V_16 , int V_97 )
{
struct V_1 * V_6 ;
unsigned long V_59 ;
V_6 = F_3 ( V_5 , struct V_1 , V_5 ) ;
F_31 ( & V_6 -> V_62 , V_59 ) ;
V_6 -> V_18 ( V_6 , V_16 , V_97 ) ;
F_4 ( V_6 , V_16 , 0 ) ;
F_32 ( & V_6 -> V_62 , V_59 ) ;
return 0 ;
}
static int F_73 ( struct V_4 * V_5 , unsigned V_16 ,
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
static void F_74 ( struct V_4 * V_5 , unsigned V_16 , int V_97 )
{
struct V_1 * V_6 ;
unsigned long V_59 ;
V_6 = F_3 ( V_5 , struct V_1 , V_5 ) ;
F_31 ( & V_6 -> V_62 , V_59 ) ;
V_6 -> V_18 ( V_6 , V_16 , V_97 ) ;
F_32 ( & V_6 -> V_62 , V_59 ) ;
}
static void T_3 F_75 ( struct V_1 * V_6 )
{
static bool V_98 ;
T_2 V_99 ;
if ( V_98 || V_6 -> V_12 -> V_100 == V_101 )
return;
V_99 = F_76 ( V_6 -> V_10 + V_6 -> V_12 -> V_100 ) ;
F_77 ( L_2 ,
( V_99 >> 4 ) & 0x0f , V_99 & 0x0f ) ;
V_98 = true ;
}
static void F_78 ( struct V_1 * V_6 )
{
void T_1 * V_10 = V_6 -> V_10 ;
T_2 V_11 = 0xffffffff ;
if ( V_6 -> V_69 == 16 )
V_11 = 0xffff ;
if ( V_6 -> V_102 ) {
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
V_6 -> V_27 = F_79 ( V_6 -> V_61 , L_3 ) ;
if ( F_80 ( V_6 -> V_27 ) )
F_42 ( V_6 -> V_61 , L_4 ) ;
}
static int F_81 ( struct V_1 * V_6 , struct V_81 * V_103 )
{
static int V_7 ;
int V_104 = 0 ;
int V_105 ;
V_6 -> V_5 . V_106 = F_44 ;
V_6 -> V_5 . free = F_45 ;
V_6 -> V_5 . V_107 = F_69 ;
V_6 -> V_5 . V_108 = F_70 ;
V_6 -> V_5 . V_109 = F_71 ;
V_6 -> V_5 . V_110 = F_72 ;
V_6 -> V_5 . V_111 = F_73 ;
V_6 -> V_5 . V_24 = F_74 ;
if ( V_6 -> V_102 ) {
V_6 -> V_5 . V_112 = L_5 ;
if ( V_6 -> V_12 -> V_42 )
V_6 -> V_5 . V_61 = & V_94 . V_61 ;
V_6 -> V_5 . V_10 = F_82 ( 0 ) ;
} else {
V_6 -> V_5 . V_112 = L_6 ;
V_6 -> V_5 . V_10 = V_7 ;
V_7 += V_6 -> V_69 ;
}
V_6 -> V_5 . V_113 = V_6 -> V_69 ;
V_105 = F_83 ( & V_6 -> V_5 ) ;
if ( V_105 ) {
F_42 ( V_6 -> V_61 , L_7 , V_105 ) ;
return V_105 ;
}
#ifdef F_84
V_104 = F_85 ( - 1 , 0 , V_6 -> V_69 , 0 ) ;
if ( V_104 < 0 ) {
F_42 ( V_6 -> V_61 , L_8 ) ;
return - V_114 ;
}
#endif
if ( V_6 -> V_102 ) {
V_103 -> V_115 = V_116 . V_115 ;
V_103 -> V_117 = V_118 ;
V_103 -> V_119 = V_120 ;
if ( ! V_6 -> V_12 -> V_42 )
V_103 -> V_121 = NULL ;
}
V_105 = F_86 ( & V_6 -> V_5 , V_103 ,
V_104 , F_46 ,
V_87 ) ;
if ( V_105 ) {
F_42 ( V_6 -> V_61 , L_9 , V_105 ) ;
F_87 ( & V_6 -> V_5 ) ;
return - V_114 ;
}
F_88 ( & V_6 -> V_5 , V_103 ,
V_6 -> V_63 , F_46 ) ;
return 0 ;
}
static int F_89 ( struct V_89 * V_90 )
{
struct V_88 * V_61 = & V_90 -> V_61 ;
struct V_122 * V_123 = V_61 -> V_124 ;
const struct V_125 * V_126 ;
const struct V_127 * V_128 ;
struct V_129 * V_130 ;
struct V_1 * V_6 ;
struct V_81 * V_103 ;
int V_105 ;
V_126 = F_90 ( F_91 ( V_131 ) , V_61 ) ;
V_128 = V_126 ? V_126 -> V_132 : F_92 ( V_61 ) ;
if ( ! V_128 )
return - V_50 ;
V_6 = F_93 ( V_61 , sizeof( struct V_1 ) , V_133 ) ;
if ( ! V_6 ) {
F_42 ( V_61 , L_10 ) ;
return - V_134 ;
}
V_103 = F_93 ( V_61 , sizeof( * V_103 ) , V_133 ) ;
if ( ! V_103 )
return - V_134 ;
V_103 -> V_135 = F_55 ,
V_103 -> V_136 = F_57 ,
V_103 -> V_115 = F_58 ,
V_103 -> V_117 = F_59 ,
V_103 -> V_119 = F_56 ,
V_103 -> V_137 = F_29 ,
V_103 -> V_121 = F_43 ,
V_103 -> V_138 = F_94 ( & V_90 -> V_61 ) ;
V_130 = F_95 ( V_90 , V_139 , 0 ) ;
if ( F_96 ( ! V_130 ) ) {
F_42 ( V_61 , L_11 ) ;
return - V_114 ;
}
V_6 -> V_63 = V_130 -> V_140 ;
V_6 -> V_61 = V_61 ;
V_6 -> V_5 . V_61 = V_61 ;
V_6 -> V_5 . V_141 = V_142 ;
V_6 -> V_31 = V_128 -> V_31 ;
V_6 -> V_93 = V_128 -> V_143 ;
V_6 -> V_69 = V_128 -> V_144 ;
V_6 -> V_102 = V_128 -> V_102 ;
V_6 -> V_41 = V_128 -> V_41 ;
V_6 -> V_12 = V_128 -> V_12 ;
#ifdef F_97
V_6 -> V_5 . V_124 = F_98 ( V_123 ) ;
#endif
if ( V_123 ) {
if ( ! F_99 ( V_123 , L_12 ) )
V_6 -> V_145 = true ;
} else {
V_6 -> V_145 = V_128 -> V_145 ;
if ( V_6 -> V_145 )
V_6 -> V_146 =
V_128 -> V_146 ;
}
if ( V_6 -> V_12 -> V_18 && V_6 -> V_12 -> V_20 )
V_6 -> V_18 = F_8 ;
else
V_6 -> V_18 = F_9 ;
F_100 ( & V_6 -> V_62 ) ;
V_130 = F_95 ( V_90 , V_147 , 0 ) ;
V_6 -> V_10 = F_101 ( V_61 , V_130 ) ;
if ( F_80 ( V_6 -> V_10 ) ) {
F_102 ( V_6 -> V_5 . V_85 ) ;
return F_103 ( V_6 -> V_10 ) ;
}
F_66 ( V_90 , V_6 ) ;
F_104 ( V_6 -> V_61 ) ;
F_105 ( V_6 -> V_61 ) ;
F_30 ( V_6 -> V_61 ) ;
if ( V_6 -> V_102 )
F_65 ( V_6 ) ;
F_78 ( V_6 ) ;
V_105 = F_81 ( V_6 , V_103 ) ;
if ( V_105 )
return V_105 ;
F_75 ( V_6 ) ;
F_34 ( V_6 -> V_61 ) ;
F_106 ( & V_6 -> V_123 , & V_148 ) ;
return 0 ;
}
static int F_107 ( struct V_89 * V_90 )
{
struct V_1 * V_6 = F_63 ( V_90 ) ;
F_108 ( & V_6 -> V_123 ) ;
F_87 ( & V_6 -> V_5 ) ;
F_109 ( V_6 -> V_61 ) ;
return 0 ;
}
static int F_110 ( struct V_88 * V_61 )
{
struct V_89 * V_90 = F_62 ( V_61 ) ;
struct V_1 * V_6 = F_63 ( V_90 ) ;
T_2 V_149 = 0 , V_150 = 0 ;
unsigned long V_59 ;
T_2 V_151 , V_152 ;
F_31 ( & V_6 -> V_62 , V_59 ) ;
V_151 = V_6 -> V_14 . V_33 & V_6 -> V_14 . V_43 ;
if ( V_151 )
F_7 ( V_151 | V_6 -> V_14 . V_39 ,
V_6 -> V_10 + V_6 -> V_12 -> V_39 ) ;
V_152 = V_6 -> V_14 . V_35 & V_6 -> V_14 . V_43 ;
if ( V_152 )
F_7 ( V_152 | V_6 -> V_14 . V_37 ,
V_6 -> V_10 + V_6 -> V_12 -> V_37 ) ;
if ( ! V_6 -> V_46 )
goto V_153;
if ( V_6 -> V_154 != V_155 ) {
V_6 -> V_154 = 0 ;
goto V_153;
}
V_6 -> V_156 = F_5 ( V_6 -> V_10 +
V_6 -> V_12 -> V_22 ) ;
V_149 = V_6 -> V_14 . V_39 ;
V_150 = V_6 -> V_14 . V_37 ;
V_149 &= ~ V_6 -> V_46 ;
V_150 &= ~ V_6 -> V_46 ;
F_7 ( V_149 , V_6 -> V_10 + V_6 -> V_12 -> V_39 ) ;
F_7 ( V_150 , V_6 -> V_10 + V_6 -> V_12 -> V_37 ) ;
V_6 -> V_157 = true ;
V_153:
if ( V_6 -> V_146 )
V_6 -> V_158 =
V_6 -> V_146 ( V_6 -> V_61 ) ;
F_15 ( V_6 ) ;
F_32 ( & V_6 -> V_62 , V_59 ) ;
return 0 ;
}
static int F_111 ( struct V_88 * V_61 )
{
struct V_89 * V_90 = F_62 ( V_61 ) ;
struct V_1 * V_6 = F_63 ( V_90 ) ;
T_2 V_11 = 0 , V_159 , V_160 , V_161 ;
unsigned long V_59 ;
int V_162 ;
F_31 ( & V_6 -> V_62 , V_59 ) ;
if ( V_6 -> V_145 && ! V_6 -> V_163 ) {
F_112 ( V_6 ) ;
if ( V_6 -> V_146 )
V_6 -> V_158 =
V_6 -> V_146 ( V_6 -> V_61 ) ;
}
F_13 ( V_6 ) ;
F_7 ( V_6 -> V_14 . V_39 ,
V_6 -> V_10 + V_6 -> V_12 -> V_39 ) ;
F_7 ( V_6 -> V_14 . V_37 ,
V_6 -> V_10 + V_6 -> V_12 -> V_37 ) ;
if ( V_6 -> V_145 ) {
if ( ! V_6 -> V_146 ) {
F_113 ( V_6 ) ;
} else {
V_162 = V_6 -> V_146 ( V_6 -> V_61 ) ;
if ( V_162 != V_6 -> V_158 ) {
F_113 ( V_6 ) ;
} else {
F_32 ( & V_6 -> V_62 , V_59 ) ;
return 0 ;
}
}
}
if ( ! V_6 -> V_157 ) {
F_32 ( & V_6 -> V_62 , V_59 ) ;
return 0 ;
}
V_11 = F_5 ( V_6 -> V_10 + V_6 -> V_12 -> V_22 ) ;
V_11 ^= V_6 -> V_156 ;
V_11 &= V_6 -> V_46 ;
V_160 = V_11 & V_6 -> V_14 . V_39 ;
V_160 &= V_6 -> V_156 ;
V_161 = V_11 & V_6 -> V_14 . V_37 ;
V_161 &= ~ ( V_6 -> V_156 ) ;
V_159 = V_11 & ( ~ ( V_6 -> V_14 . V_39 ) &
~ ( V_6 -> V_14 . V_37 ) ) ;
V_159 |= V_160 | V_161 ;
if ( V_159 ) {
T_2 V_164 , V_165 ;
V_164 = F_5 ( V_6 -> V_10 + V_6 -> V_12 -> V_33 ) ;
V_165 = F_5 ( V_6 -> V_10 + V_6 -> V_12 -> V_35 ) ;
if ( ! V_6 -> V_12 -> V_166 ) {
F_7 ( V_164 | V_159 , V_6 -> V_10 +
V_6 -> V_12 -> V_33 ) ;
F_7 ( V_165 | V_159 , V_6 -> V_10 +
V_6 -> V_12 -> V_35 ) ;
}
if ( V_6 -> V_12 -> V_166 ) {
F_7 ( V_164 | V_11 , V_6 -> V_10 +
V_6 -> V_12 -> V_33 ) ;
F_7 ( V_165 | V_11 , V_6 -> V_10 +
V_6 -> V_12 -> V_35 ) ;
}
F_7 ( V_164 , V_6 -> V_10 + V_6 -> V_12 -> V_33 ) ;
F_7 ( V_165 , V_6 -> V_10 + V_6 -> V_12 -> V_35 ) ;
}
V_6 -> V_157 = false ;
F_32 ( & V_6 -> V_62 , V_59 ) ;
return 0 ;
}
void F_114 ( int V_167 )
{
struct V_1 * V_6 ;
F_115 (bank, &omap_gpio_list, node) {
if ( ! F_24 ( V_6 ) || ! V_6 -> V_145 )
continue;
V_6 -> V_154 = V_167 ;
F_116 ( V_6 -> V_61 ) ;
}
}
void F_117 ( void )
{
struct V_1 * V_6 ;
F_115 (bank, &omap_gpio_list, node) {
if ( ! F_24 ( V_6 ) || ! V_6 -> V_145 )
continue;
F_30 ( V_6 -> V_61 ) ;
}
}
static void F_112 ( struct V_1 * V_168 )
{
struct V_169 * V_12 = V_168 -> V_12 ;
void T_1 * V_10 = V_168 -> V_10 ;
V_168 -> V_14 . V_54 = F_5 ( V_10 + V_12 -> V_54 ) ;
V_168 -> V_14 . V_15 = F_5 ( V_10 + V_12 -> V_13 ) ;
V_168 -> V_14 . V_43 = F_5 ( V_10 + V_12 -> V_42 ) ;
V_168 -> V_14 . V_33 = F_5 ( V_10 + V_12 -> V_33 ) ;
V_168 -> V_14 . V_35 = F_5 ( V_10 + V_12 -> V_35 ) ;
V_168 -> V_14 . V_37 = F_5 ( V_10 + V_12 -> V_37 ) ;
V_168 -> V_14 . V_39 = F_5 ( V_10 + V_12 -> V_39 ) ;
V_168 -> V_14 . V_73 = F_5 ( V_10 + V_12 -> V_70 ) ;
V_168 -> V_14 . V_170 = F_5 ( V_10 + V_12 -> V_170 ) ;
if ( V_12 -> V_18 && V_168 -> V_12 -> V_20 )
V_168 -> V_14 . V_19 = F_5 ( V_10 + V_12 -> V_18 ) ;
else
V_168 -> V_14 . V_19 = F_5 ( V_10 + V_12 -> V_19 ) ;
V_168 -> V_163 = true ;
}
static void F_113 ( struct V_1 * V_6 )
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
F_7 ( V_6 -> V_14 . V_170 ,
V_6 -> V_10 + V_6 -> V_12 -> V_170 ) ;
}
static inline void F_112 ( struct V_1 * V_168 ) {}
static int T_3 F_118 ( void )
{
return F_67 ( & V_171 ) ;
}
static void T_4 F_119 ( void )
{
F_120 ( & V_171 ) ;
}
