static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = F_2 ( V_3 ) ;
return F_3 ( V_5 ) ;
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
bool V_17 = ! ! V_29 ;
if ( ! V_6 -> V_31 )
return;
if ( V_17 ) {
V_29 = F_18 ( V_29 , 31 ) - 1 ;
V_29 &= V_32 ;
}
V_11 = F_6 ( V_16 ) ;
F_14 ( V_6 -> V_27 ) ;
V_9 = V_6 -> V_10 + V_6 -> V_12 -> V_29 ;
F_7 ( V_29 , V_9 ) ;
V_9 = V_6 -> V_10 + V_6 -> V_12 -> V_28 ;
V_30 = F_5 ( V_9 ) ;
if ( V_17 )
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
static void F_19 ( struct V_1 * V_6 , unsigned V_16 )
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
static inline void F_20 ( struct V_1 * V_6 , int V_7 ,
unsigned V_33 )
{
void T_1 * V_10 = V_6 -> V_10 ;
T_2 V_21 = F_6 ( V_7 ) ;
F_12 ( V_10 , V_6 -> V_12 -> V_34 , V_21 ,
V_33 & V_35 ) ;
F_12 ( V_10 , V_6 -> V_12 -> V_36 , V_21 ,
V_33 & V_37 ) ;
F_12 ( V_10 , V_6 -> V_12 -> V_38 , V_21 ,
V_33 & V_39 ) ;
F_12 ( V_10 , V_6 -> V_12 -> V_40 , V_21 ,
V_33 & V_41 ) ;
V_6 -> V_14 . V_34 =
F_5 ( V_6 -> V_10 + V_6 -> V_12 -> V_34 ) ;
V_6 -> V_14 . V_36 =
F_5 ( V_6 -> V_10 + V_6 -> V_12 -> V_36 ) ;
V_6 -> V_14 . V_38 =
F_5 ( V_6 -> V_10 + V_6 -> V_12 -> V_38 ) ;
V_6 -> V_14 . V_40 =
F_5 ( V_6 -> V_10 + V_6 -> V_12 -> V_40 ) ;
if ( F_21 ( ! ( V_6 -> V_42 & V_21 ) ) ) {
F_12 ( V_10 , V_6 -> V_12 -> V_43 , V_21 , V_33 != 0 ) ;
V_6 -> V_14 . V_44 =
F_5 ( V_6 -> V_10 + V_6 -> V_12 -> V_43 ) ;
}
if ( ! V_6 -> V_12 -> V_45 ) {
if ( V_6 -> V_42 ) {
if ( ! ( V_6 -> V_42 & V_21 ) )
goto exit;
}
if ( V_33 & V_46 )
V_6 -> V_47 |= V_21 ;
else
V_6 -> V_47 &= ~ V_21 ;
}
exit:
V_6 -> V_48 =
F_5 ( V_6 -> V_10 + V_6 -> V_12 -> V_34 ) |
F_5 ( V_6 -> V_10 + V_6 -> V_12 -> V_36 ) ;
}
static void F_22 ( struct V_1 * V_6 , int V_7 )
{
void T_1 * V_9 = V_6 -> V_10 ;
T_2 V_11 = 0 ;
if ( ! V_6 -> V_12 -> V_45 )
return;
V_9 += V_6 -> V_12 -> V_45 ;
V_11 = F_5 ( V_9 ) ;
if ( ( V_11 >> V_7 ) & 1 )
V_11 &= ~ ( F_6 ( V_7 ) ) ;
else
V_11 |= F_6 ( V_7 ) ;
F_7 ( V_11 , V_9 ) ;
}
static void F_22 ( struct V_1 * V_6 , int V_7 ) {}
static int F_23 ( struct V_1 * V_6 , int V_7 ,
unsigned V_33 )
{
void T_1 * V_9 = V_6 -> V_10 ;
void T_1 * V_10 = V_6 -> V_10 ;
T_2 V_11 = 0 ;
if ( V_6 -> V_12 -> V_34 && V_6 -> V_12 -> V_43 ) {
F_20 ( V_6 , V_7 , V_33 ) ;
} else if ( V_6 -> V_12 -> V_45 ) {
V_9 += V_6 -> V_12 -> V_45 ;
V_11 = F_5 ( V_9 ) ;
if ( ( V_33 & V_49 ) == V_46 )
V_6 -> V_50 |= F_6 ( V_7 ) ;
if ( V_33 & V_39 )
V_11 |= F_6 ( V_7 ) ;
else if ( V_33 & V_41 )
V_11 &= ~ ( F_6 ( V_7 ) ) ;
else
return - V_51 ;
F_7 ( V_11 , V_9 ) ;
} else if ( V_6 -> V_12 -> V_52 ) {
if ( V_7 & 0x08 )
V_9 += V_6 -> V_12 -> V_53 ;
else
V_9 += V_6 -> V_12 -> V_52 ;
V_7 &= 0x07 ;
V_11 = F_5 ( V_9 ) ;
V_11 &= ~ ( 3 << ( V_7 << 1 ) ) ;
if ( V_33 & V_39 )
V_11 |= 2 << ( V_7 << 1 ) ;
if ( V_33 & V_41 )
V_11 |= F_6 ( V_7 << 1 ) ;
F_12 ( V_10 , V_6 -> V_12 -> V_43 , F_6 ( V_7 ) , V_33 ) ;
V_6 -> V_14 . V_44 =
F_5 ( V_6 -> V_10 + V_6 -> V_12 -> V_43 ) ;
F_7 ( V_11 , V_9 ) ;
}
return 0 ;
}
static void F_24 ( struct V_1 * V_6 , unsigned V_16 )
{
if ( V_6 -> V_12 -> V_54 ) {
void T_1 * V_9 = V_6 -> V_10 + V_6 -> V_12 -> V_54 ;
F_7 ( F_5 ( V_9 ) | ( F_6 ( V_16 ) ) , V_9 ) ;
}
if ( V_6 -> V_12 -> V_55 && ! F_25 ( V_6 ) ) {
void T_1 * V_9 = V_6 -> V_10 + V_6 -> V_12 -> V_55 ;
T_2 V_55 ;
V_55 = F_5 ( V_9 ) ;
V_55 &= ~ V_56 ;
F_7 ( V_55 , V_9 ) ;
V_6 -> V_14 . V_55 = V_55 ;
}
}
static void F_26 ( struct V_1 * V_6 , unsigned V_16 )
{
void T_1 * V_10 = V_6 -> V_10 ;
if ( V_6 -> V_12 -> V_43 &&
! F_27 ( V_6 -> V_57 , V_16 ) &&
! F_27 ( V_6 -> V_58 , V_16 ) ) {
F_12 ( V_10 , V_6 -> V_12 -> V_43 , F_6 ( V_16 ) , 0 ) ;
V_6 -> V_14 . V_44 =
F_5 ( V_6 -> V_10 + V_6 -> V_12 -> V_43 ) ;
}
if ( V_6 -> V_12 -> V_55 && ! F_25 ( V_6 ) ) {
void T_1 * V_9 = V_6 -> V_10 + V_6 -> V_12 -> V_55 ;
T_2 V_55 ;
V_55 = F_5 ( V_9 ) ;
V_55 |= V_56 ;
F_7 ( V_55 , V_9 ) ;
V_6 -> V_14 . V_55 = V_55 ;
}
}
static int F_28 ( struct V_1 * V_6 , unsigned V_16 )
{
void T_1 * V_9 = V_6 -> V_10 + V_6 -> V_12 -> V_13 ;
return F_5 ( V_9 ) & F_6 ( V_16 ) ;
}
static void F_29 ( struct V_1 * V_6 , unsigned V_16 )
{
if ( ! F_27 ( V_6 -> V_57 , V_16 ) ) {
F_24 ( V_6 , V_16 ) ;
F_4 ( V_6 , V_16 , 1 ) ;
}
V_6 -> V_58 |= F_6 ( V_16 ) ;
}
static int F_30 ( struct V_2 * V_3 , unsigned type )
{
struct V_1 * V_6 = F_1 ( V_3 ) ;
int V_59 ;
unsigned long V_60 ;
unsigned V_16 = V_3 -> V_61 ;
if ( type & ~ V_49 )
return - V_51 ;
if ( ! V_6 -> V_12 -> V_34 &&
( type & ( V_35 | V_37 ) ) )
return - V_51 ;
F_31 ( & V_6 -> V_62 , V_60 ) ;
V_59 = F_23 ( V_6 , V_16 , type ) ;
if ( V_59 ) {
F_32 ( & V_6 -> V_62 , V_60 ) ;
goto error;
}
F_29 ( V_6 , V_16 ) ;
if ( ! F_28 ( V_6 , V_16 ) ) {
F_32 ( & V_6 -> V_62 , V_60 ) ;
V_59 = - V_51 ;
goto error;
}
F_32 ( & V_6 -> V_62 , V_60 ) ;
if ( type & ( V_35 | V_37 ) )
F_33 ( V_3 , V_63 ) ;
else if ( type & ( V_41 | V_39 ) )
F_33 ( V_3 , V_64 ) ;
return 0 ;
error:
return V_59 ;
}
static void F_34 ( struct V_1 * V_6 , int V_65 )
{
void T_1 * V_9 = V_6 -> V_10 ;
V_9 += V_6 -> V_12 -> V_66 ;
F_7 ( V_65 , V_9 ) ;
if ( V_6 -> V_12 -> V_67 ) {
V_9 = V_6 -> V_10 + V_6 -> V_12 -> V_67 ;
F_7 ( V_65 , V_9 ) ;
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
T_2 V_23 = ( F_6 ( V_6 -> V_68 ) ) - 1 ;
V_9 += V_6 -> V_12 -> V_69 ;
V_11 = F_5 ( V_9 ) ;
if ( V_6 -> V_12 -> V_70 )
V_11 = ~ V_11 ;
V_11 &= V_23 ;
return V_11 ;
}
static void F_37 ( struct V_1 * V_6 , int V_65 )
{
void T_1 * V_9 = V_6 -> V_10 ;
T_2 V_11 ;
if ( V_6 -> V_12 -> V_71 ) {
V_9 += V_6 -> V_12 -> V_71 ;
V_11 = V_65 ;
V_6 -> V_14 . V_72 |= V_65 ;
} else {
V_9 += V_6 -> V_12 -> V_69 ;
V_11 = F_5 ( V_9 ) ;
if ( V_6 -> V_12 -> V_70 )
V_11 &= ~ V_65 ;
else
V_11 |= V_65 ;
V_6 -> V_14 . V_72 = V_11 ;
}
F_7 ( V_11 , V_9 ) ;
}
static void F_38 ( struct V_1 * V_6 , int V_65 )
{
void T_1 * V_9 = V_6 -> V_10 ;
T_2 V_11 ;
if ( V_6 -> V_12 -> V_73 ) {
V_9 += V_6 -> V_12 -> V_73 ;
V_11 = V_65 ;
V_6 -> V_14 . V_72 &= ~ V_65 ;
} else {
V_9 += V_6 -> V_12 -> V_69 ;
V_11 = F_5 ( V_9 ) ;
if ( V_6 -> V_12 -> V_70 )
V_11 |= V_65 ;
else
V_11 &= ~ V_65 ;
V_6 -> V_14 . V_72 = V_11 ;
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
unsigned long V_60 ;
if ( V_6 -> V_42 & V_21 ) {
F_41 ( V_6 -> V_74 ,
L_1 ,
V_16 ) ;
return - V_51 ;
}
F_31 ( & V_6 -> V_62 , V_60 ) ;
if ( V_17 )
V_6 -> V_14 . V_44 |= V_21 ;
else
V_6 -> V_14 . V_44 &= ~ V_21 ;
F_7 ( V_6 -> V_14 . V_44 , V_6 -> V_10 + V_6 -> V_12 -> V_43 ) ;
F_32 ( & V_6 -> V_62 , V_60 ) ;
return 0 ;
}
static int F_42 ( struct V_2 * V_3 , unsigned int V_17 )
{
struct V_1 * V_6 = F_1 ( V_3 ) ;
unsigned V_16 = V_3 -> V_61 ;
int V_75 ;
V_75 = F_40 ( V_6 , V_16 , V_17 ) ;
if ( ! V_75 )
V_75 = F_43 ( V_6 -> V_76 , V_17 ) ;
return V_75 ;
}
static int F_44 ( struct V_4 * V_5 , unsigned V_16 )
{
struct V_1 * V_6 = F_3 ( V_5 ) ;
unsigned long V_60 ;
if ( ! F_25 ( V_6 ) )
F_45 ( V_6 -> V_74 ) ;
F_31 ( & V_6 -> V_62 , V_60 ) ;
F_24 ( V_6 , V_16 ) ;
V_6 -> V_57 |= F_6 ( V_16 ) ;
F_32 ( & V_6 -> V_62 , V_60 ) ;
return 0 ;
}
static void F_46 ( struct V_4 * V_5 , unsigned V_16 )
{
struct V_1 * V_6 = F_3 ( V_5 ) ;
unsigned long V_60 ;
F_31 ( & V_6 -> V_62 , V_60 ) ;
V_6 -> V_57 &= ~ ( F_6 ( V_16 ) ) ;
if ( ! F_27 ( V_6 -> V_58 , V_16 ) ) {
F_4 ( V_6 , V_16 , 1 ) ;
F_19 ( V_6 , V_16 ) ;
}
F_26 ( V_6 , V_16 ) ;
F_32 ( & V_6 -> V_62 , V_60 ) ;
if ( ! F_25 ( V_6 ) )
F_47 ( V_6 -> V_74 ) ;
}
static T_3 F_48 ( int V_76 , void * V_77 )
{
void T_1 * V_78 = NULL ;
T_2 V_79 ;
unsigned int V_80 ;
struct V_1 * V_6 = V_77 ;
unsigned long V_81 ;
unsigned long V_82 ;
V_78 = V_6 -> V_10 + V_6 -> V_12 -> V_66 ;
if ( F_49 ( ! V_78 ) )
goto exit;
F_45 ( V_6 -> V_74 ) ;
while ( 1 ) {
T_2 V_83 , V_48 = 0 ;
T_2 V_84 ;
F_31 ( & V_6 -> V_62 , V_82 ) ;
V_84 = F_36 ( V_6 ) ;
V_83 = V_79 = F_5 ( V_78 ) & V_84 ;
if ( V_6 -> V_48 )
V_48 = V_6 -> V_48 & V_84 ;
F_38 ( V_6 , V_83 & ~ V_48 ) ;
F_34 ( V_6 , V_83 & ~ V_48 ) ;
F_37 ( V_6 , V_83 & ~ V_48 ) ;
F_32 ( & V_6 -> V_62 , V_82 ) ;
if ( ! V_79 )
break;
while ( V_79 ) {
V_80 = F_50 ( V_79 ) ;
V_79 &= ~ ( F_6 ( V_80 ) ) ;
F_31 ( & V_6 -> V_62 , V_82 ) ;
if ( V_6 -> V_50 & ( F_6 ( V_80 ) ) )
F_22 ( V_6 , V_80 ) ;
F_32 ( & V_6 -> V_62 , V_82 ) ;
F_31 ( & V_6 -> V_85 , V_81 ) ;
F_51 ( F_52 ( V_6 -> V_5 . V_86 ,
V_80 ) ) ;
F_32 ( & V_6 -> V_85 ,
V_81 ) ;
}
}
exit:
F_47 ( V_6 -> V_74 ) ;
return V_87 ;
}
static unsigned int F_53 ( struct V_2 * V_3 )
{
struct V_1 * V_6 = F_1 ( V_3 ) ;
unsigned long V_60 ;
unsigned V_16 = V_3 -> V_61 ;
F_31 ( & V_6 -> V_62 , V_60 ) ;
if ( ! F_27 ( V_6 -> V_57 , V_16 ) )
F_4 ( V_6 , V_16 , 1 ) ;
else if ( ! F_28 ( V_6 , V_16 ) )
goto V_88;
F_24 ( V_6 , V_16 ) ;
V_6 -> V_58 |= F_6 ( V_16 ) ;
F_32 ( & V_6 -> V_62 , V_60 ) ;
F_54 ( V_3 ) ;
return 0 ;
V_88:
F_32 ( & V_6 -> V_62 , V_60 ) ;
return - V_51 ;
}
static void F_55 ( struct V_2 * V_3 )
{
struct V_1 * V_6 = F_1 ( V_3 ) ;
unsigned long V_60 ;
unsigned V_16 = V_3 -> V_61 ;
F_31 ( & V_6 -> V_62 , V_60 ) ;
V_6 -> V_58 &= ~ ( F_6 ( V_16 ) ) ;
F_39 ( V_6 , V_16 , 0 ) ;
F_35 ( V_6 , V_16 ) ;
F_23 ( V_6 , V_16 , V_89 ) ;
if ( ! F_27 ( V_6 -> V_57 , V_16 ) )
F_19 ( V_6 , V_16 ) ;
F_26 ( V_6 , V_16 ) ;
F_32 ( & V_6 -> V_62 , V_60 ) ;
}
static void F_56 ( struct V_2 * V_90 )
{
struct V_1 * V_6 = F_1 ( V_90 ) ;
if ( ! F_25 ( V_6 ) )
F_45 ( V_6 -> V_74 ) ;
}
static void F_57 ( struct V_2 * V_90 )
{
struct V_1 * V_6 = F_1 ( V_90 ) ;
if ( ! F_25 ( V_6 ) )
F_47 ( V_6 -> V_74 ) ;
}
static void F_58 ( struct V_2 * V_3 )
{
struct V_1 * V_6 = F_1 ( V_3 ) ;
unsigned V_16 = V_3 -> V_61 ;
F_35 ( V_6 , V_16 ) ;
}
static void F_59 ( struct V_2 * V_3 )
{
struct V_1 * V_6 = F_1 ( V_3 ) ;
unsigned V_16 = V_3 -> V_61 ;
unsigned long V_60 ;
F_31 ( & V_6 -> V_62 , V_60 ) ;
F_39 ( V_6 , V_16 , 0 ) ;
F_23 ( V_6 , V_16 , V_89 ) ;
F_32 ( & V_6 -> V_62 , V_60 ) ;
}
static void F_54 ( struct V_2 * V_3 )
{
struct V_1 * V_6 = F_1 ( V_3 ) ;
unsigned V_16 = V_3 -> V_61 ;
T_2 V_33 = F_60 ( V_3 ) ;
unsigned long V_60 ;
F_31 ( & V_6 -> V_62 , V_60 ) ;
if ( V_33 )
F_23 ( V_6 , V_16 , V_33 ) ;
if ( V_6 -> V_48 & F_6 ( V_16 ) ) {
F_39 ( V_6 , V_16 , 0 ) ;
F_35 ( V_6 , V_16 ) ;
}
F_39 ( V_6 , V_16 , 1 ) ;
F_32 ( & V_6 -> V_62 , V_60 ) ;
}
static int F_61 ( struct V_91 * V_74 )
{
struct V_92 * V_93 = F_62 ( V_74 ) ;
struct V_1 * V_6 = F_63 ( V_93 ) ;
void T_1 * V_94 = V_6 -> V_10 +
V_95 / V_6 -> V_96 ;
unsigned long V_60 ;
F_31 ( & V_6 -> V_62 , V_60 ) ;
F_7 ( 0xffff & ~ V_6 -> V_14 . V_44 , V_94 ) ;
F_32 ( & V_6 -> V_62 , V_60 ) ;
return 0 ;
}
static int F_64 ( struct V_91 * V_74 )
{
struct V_92 * V_93 = F_62 ( V_74 ) ;
struct V_1 * V_6 = F_63 ( V_93 ) ;
void T_1 * V_94 = V_6 -> V_10 +
V_95 / V_6 -> V_96 ;
unsigned long V_60 ;
F_31 ( & V_6 -> V_62 , V_60 ) ;
F_7 ( V_6 -> V_14 . V_44 , V_94 ) ;
F_32 ( & V_6 -> V_62 , V_60 ) ;
return 0 ;
}
static inline void F_65 ( struct V_1 * V_6 )
{
F_66 ( & V_97 , V_6 ) ;
if ( F_67 ( & V_98 ) == 0 )
( void ) F_68 ( & V_97 ) ;
}
static int F_69 ( struct V_4 * V_5 , unsigned V_16 )
{
struct V_1 * V_6 ;
unsigned long V_60 ;
void T_1 * V_9 ;
int V_99 ;
V_6 = F_3 ( V_5 ) ;
V_9 = V_6 -> V_10 + V_6 -> V_12 -> V_13 ;
F_31 ( & V_6 -> V_62 , V_60 ) ;
V_99 = ! ! ( F_5 ( V_9 ) & F_6 ( V_16 ) ) ;
F_32 ( & V_6 -> V_62 , V_60 ) ;
return V_99 ;
}
static int F_70 ( struct V_4 * V_5 , unsigned V_16 )
{
struct V_1 * V_6 ;
unsigned long V_60 ;
V_6 = F_3 ( V_5 ) ;
F_31 ( & V_6 -> V_62 , V_60 ) ;
F_4 ( V_6 , V_16 , 1 ) ;
F_32 ( & V_6 -> V_62 , V_60 ) ;
return 0 ;
}
static int F_71 ( struct V_4 * V_5 , unsigned V_16 )
{
struct V_1 * V_6 ;
V_6 = F_3 ( V_5 ) ;
if ( F_28 ( V_6 , V_16 ) )
return F_10 ( V_6 , V_16 ) ;
else
return F_11 ( V_6 , V_16 ) ;
}
static int F_72 ( struct V_4 * V_5 , unsigned V_16 , int V_100 )
{
struct V_1 * V_6 ;
unsigned long V_60 ;
V_6 = F_3 ( V_5 ) ;
F_31 ( & V_6 -> V_62 , V_60 ) ;
V_6 -> V_18 ( V_6 , V_16 , V_100 ) ;
F_4 ( V_6 , V_16 , 0 ) ;
F_32 ( & V_6 -> V_62 , V_60 ) ;
return 0 ;
}
static int F_73 ( struct V_4 * V_5 , unsigned V_16 ,
unsigned V_29 )
{
struct V_1 * V_6 ;
unsigned long V_60 ;
V_6 = F_3 ( V_5 ) ;
F_31 ( & V_6 -> V_62 , V_60 ) ;
F_17 ( V_6 , V_16 , V_29 ) ;
F_32 ( & V_6 -> V_62 , V_60 ) ;
return 0 ;
}
static void F_74 ( struct V_4 * V_5 , unsigned V_16 , int V_100 )
{
struct V_1 * V_6 ;
unsigned long V_60 ;
V_6 = F_3 ( V_5 ) ;
F_31 ( & V_6 -> V_62 , V_60 ) ;
V_6 -> V_18 ( V_6 , V_16 , V_100 ) ;
F_32 ( & V_6 -> V_62 , V_60 ) ;
}
static void T_4 F_75 ( struct V_1 * V_6 )
{
static bool V_101 ;
T_2 V_102 ;
if ( V_101 || V_6 -> V_12 -> V_103 == V_104 )
return;
V_102 = F_76 ( V_6 -> V_10 + V_6 -> V_12 -> V_103 ) ;
F_77 ( L_2 ,
( V_102 >> 4 ) & 0x0f , V_102 & 0x0f ) ;
V_101 = true ;
}
static void F_78 ( struct V_1 * V_6 )
{
void T_1 * V_10 = V_6 -> V_10 ;
T_2 V_11 = 0xffffffff ;
if ( V_6 -> V_68 == 16 )
V_11 = 0xffff ;
if ( V_6 -> V_105 ) {
F_7 ( V_11 , V_6 -> V_10 + V_6 -> V_12 -> V_69 ) ;
return;
}
F_12 ( V_10 , V_6 -> V_12 -> V_69 , V_11 ,
V_6 -> V_12 -> V_70 ) ;
F_12 ( V_10 , V_6 -> V_12 -> V_66 , V_11 ,
! V_6 -> V_12 -> V_70 ) ;
if ( V_6 -> V_12 -> V_28 )
F_7 ( 0 , V_10 + V_6 -> V_12 -> V_28 ) ;
V_6 -> V_14 . V_15 = F_5 ( V_6 -> V_10 + V_6 -> V_12 -> V_13 ) ;
if ( V_6 -> V_12 -> V_55 )
F_7 ( 0 , V_10 + V_6 -> V_12 -> V_55 ) ;
}
static int F_79 ( struct V_1 * V_6 , struct V_106 * V_107 )
{
static int V_7 ;
int V_108 = 0 ;
int V_75 ;
V_6 -> V_5 . V_109 = F_44 ;
V_6 -> V_5 . free = F_46 ;
V_6 -> V_5 . V_110 = F_69 ;
V_6 -> V_5 . V_111 = F_70 ;
V_6 -> V_5 . V_112 = F_71 ;
V_6 -> V_5 . V_113 = F_72 ;
V_6 -> V_5 . V_114 = F_73 ;
V_6 -> V_5 . V_24 = F_74 ;
if ( V_6 -> V_105 ) {
V_6 -> V_5 . V_115 = L_3 ;
if ( V_6 -> V_12 -> V_43 )
V_6 -> V_5 . V_116 = & V_97 . V_74 ;
V_6 -> V_5 . V_10 = F_80 ( 0 ) ;
} else {
V_6 -> V_5 . V_115 = L_4 ;
V_6 -> V_5 . V_10 = V_7 ;
}
V_6 -> V_5 . V_117 = V_6 -> V_68 ;
V_75 = F_81 ( & V_6 -> V_5 , V_6 ) ;
if ( V_75 ) {
F_41 ( V_6 -> V_74 , L_5 , V_75 ) ;
return V_75 ;
}
if ( ! V_6 -> V_105 )
V_7 += V_6 -> V_68 ;
#ifdef F_82
V_108 = F_83 ( - 1 , 0 , V_6 -> V_68 , 0 ) ;
if ( V_108 < 0 ) {
F_41 ( V_6 -> V_74 , L_6 ) ;
return - V_118 ;
}
#endif
if ( V_6 -> V_105 ) {
V_107 -> V_119 = V_120 . V_119 ;
if ( ! V_6 -> V_12 -> V_43 )
V_107 -> V_121 = NULL ;
}
V_75 = F_84 ( & V_6 -> V_5 , V_107 ,
V_108 , V_122 ,
V_89 ) ;
if ( V_75 ) {
F_41 ( V_6 -> V_74 , L_7 , V_75 ) ;
F_85 ( & V_6 -> V_5 ) ;
return - V_118 ;
}
F_86 ( & V_6 -> V_5 , V_107 , V_6 -> V_76 , NULL ) ;
V_75 = F_87 ( V_6 -> V_74 , V_6 -> V_76 , F_48 ,
0 , F_88 ( V_6 -> V_74 ) , V_6 ) ;
if ( V_75 )
F_85 ( & V_6 -> V_5 ) ;
return V_75 ;
}
static int F_89 ( struct V_92 * V_93 )
{
struct V_91 * V_74 = & V_93 -> V_74 ;
struct V_123 * V_124 = V_74 -> V_125 ;
const struct V_126 * V_127 ;
const struct V_128 * V_129 ;
struct V_130 * V_131 ;
struct V_1 * V_6 ;
struct V_106 * V_107 ;
int V_75 ;
V_127 = F_90 ( F_91 ( V_132 ) , V_74 ) ;
V_129 = V_127 ? V_127 -> V_90 : F_92 ( V_74 ) ;
if ( ! V_129 )
return - V_51 ;
V_6 = F_93 ( V_74 , sizeof( struct V_1 ) , V_133 ) ;
if ( ! V_6 ) {
F_41 ( V_74 , L_8 ) ;
return - V_134 ;
}
V_107 = F_93 ( V_74 , sizeof( * V_107 ) , V_133 ) ;
if ( ! V_107 )
return - V_134 ;
V_107 -> V_135 = F_53 ,
V_107 -> V_136 = F_55 ,
V_107 -> V_119 = F_58 ,
V_107 -> V_137 = F_59 ,
V_107 -> V_138 = F_54 ,
V_107 -> V_139 = F_30 ,
V_107 -> V_121 = F_42 ,
V_107 -> V_140 = F_56 ,
V_107 -> V_141 = F_57 ,
V_107 -> V_142 = F_88 ( & V_93 -> V_74 ) ;
V_6 -> V_76 = F_94 ( V_93 , 0 ) ;
if ( V_6 -> V_76 <= 0 ) {
if ( ! V_6 -> V_76 )
V_6 -> V_76 = - V_143 ;
if ( V_6 -> V_76 != - V_144 )
F_41 ( V_74 ,
L_9 , V_6 -> V_76 ) ;
return V_6 -> V_76 ;
}
V_6 -> V_74 = V_74 ;
V_6 -> V_5 . V_116 = V_74 ;
V_6 -> V_5 . V_145 = V_146 ;
V_6 -> V_31 = V_129 -> V_31 ;
V_6 -> V_96 = V_129 -> V_147 ;
V_6 -> V_68 = V_129 -> V_148 ;
V_6 -> V_105 = V_129 -> V_105 ;
V_6 -> V_42 = V_129 -> V_42 ;
V_6 -> V_12 = V_129 -> V_12 ;
#ifdef F_95
V_6 -> V_5 . V_125 = F_96 ( V_124 ) ;
#endif
if ( V_124 ) {
if ( ! F_97 ( V_124 , L_10 ) )
V_6 -> V_149 = true ;
} else {
V_6 -> V_149 = V_129 -> V_149 ;
if ( V_6 -> V_149 )
V_6 -> V_150 =
V_129 -> V_150 ;
}
if ( V_6 -> V_12 -> V_18 && V_6 -> V_12 -> V_20 )
V_6 -> V_18 = F_8 ;
else
V_6 -> V_18 = F_9 ;
F_98 ( & V_6 -> V_62 ) ;
F_98 ( & V_6 -> V_85 ) ;
V_131 = F_99 ( V_93 , V_151 , 0 ) ;
V_6 -> V_10 = F_100 ( V_74 , V_131 ) ;
if ( F_101 ( V_6 -> V_10 ) ) {
return F_102 ( V_6 -> V_10 ) ;
}
if ( V_6 -> V_31 ) {
V_6 -> V_27 = F_103 ( V_6 -> V_74 , L_11 ) ;
if ( F_101 ( V_6 -> V_27 ) ) {
F_41 ( V_6 -> V_74 ,
L_12 ) ;
V_6 -> V_31 = false ;
} else {
F_104 ( V_6 -> V_27 ) ;
}
}
F_66 ( V_93 , V_6 ) ;
F_105 ( V_6 -> V_74 ) ;
F_106 ( V_6 -> V_74 ) ;
F_45 ( V_6 -> V_74 ) ;
if ( V_6 -> V_105 )
F_65 ( V_6 ) ;
F_78 ( V_6 ) ;
V_75 = F_79 ( V_6 , V_107 ) ;
if ( V_75 ) {
F_107 ( V_6 -> V_74 ) ;
F_108 ( V_6 -> V_74 ) ;
return V_75 ;
}
F_75 ( V_6 ) ;
F_47 ( V_6 -> V_74 ) ;
F_109 ( & V_6 -> V_124 , & V_152 ) ;
return 0 ;
}
static int F_110 ( struct V_92 * V_93 )
{
struct V_1 * V_6 = F_63 ( V_93 ) ;
F_111 ( & V_6 -> V_124 ) ;
F_85 ( & V_6 -> V_5 ) ;
F_108 ( V_6 -> V_74 ) ;
if ( V_6 -> V_31 )
F_112 ( V_6 -> V_27 ) ;
return 0 ;
}
static int F_113 ( struct V_91 * V_74 )
{
struct V_92 * V_93 = F_62 ( V_74 ) ;
struct V_1 * V_6 = F_63 ( V_93 ) ;
T_2 V_153 = 0 , V_154 = 0 ;
unsigned long V_60 ;
T_2 V_155 , V_156 ;
F_31 ( & V_6 -> V_62 , V_60 ) ;
V_155 = V_6 -> V_14 . V_34 & V_6 -> V_14 . V_44 ;
if ( V_155 )
F_7 ( V_155 | V_6 -> V_14 . V_40 ,
V_6 -> V_10 + V_6 -> V_12 -> V_40 ) ;
V_156 = V_6 -> V_14 . V_36 & V_6 -> V_14 . V_44 ;
if ( V_156 )
F_7 ( V_156 | V_6 -> V_14 . V_38 ,
V_6 -> V_10 + V_6 -> V_12 -> V_38 ) ;
if ( ! V_6 -> V_47 )
goto V_157;
if ( V_6 -> V_158 != V_159 ) {
V_6 -> V_158 = 0 ;
goto V_157;
}
V_6 -> V_160 = F_5 ( V_6 -> V_10 +
V_6 -> V_12 -> V_22 ) ;
V_153 = V_6 -> V_14 . V_40 ;
V_154 = V_6 -> V_14 . V_38 ;
V_153 &= ~ V_6 -> V_47 ;
V_154 &= ~ V_6 -> V_47 ;
F_7 ( V_153 , V_6 -> V_10 + V_6 -> V_12 -> V_40 ) ;
F_7 ( V_154 , V_6 -> V_10 + V_6 -> V_12 -> V_38 ) ;
V_6 -> V_161 = true ;
V_157:
if ( V_6 -> V_150 )
V_6 -> V_162 =
V_6 -> V_150 ( V_6 -> V_74 ) ;
F_15 ( V_6 ) ;
F_32 ( & V_6 -> V_62 , V_60 ) ;
return 0 ;
}
static int F_114 ( struct V_91 * V_74 )
{
struct V_92 * V_93 = F_62 ( V_74 ) ;
struct V_1 * V_6 = F_63 ( V_93 ) ;
T_2 V_11 = 0 , V_163 , V_164 , V_165 ;
unsigned long V_60 ;
int V_166 ;
F_31 ( & V_6 -> V_62 , V_60 ) ;
if ( V_6 -> V_149 && ! V_6 -> V_167 ) {
F_115 ( V_6 ) ;
if ( V_6 -> V_150 )
V_6 -> V_162 =
V_6 -> V_150 ( V_6 -> V_74 ) ;
}
F_13 ( V_6 ) ;
F_7 ( V_6 -> V_14 . V_40 ,
V_6 -> V_10 + V_6 -> V_12 -> V_40 ) ;
F_7 ( V_6 -> V_14 . V_38 ,
V_6 -> V_10 + V_6 -> V_12 -> V_38 ) ;
if ( V_6 -> V_149 ) {
if ( ! V_6 -> V_150 ) {
F_116 ( V_6 ) ;
} else {
V_166 = V_6 -> V_150 ( V_6 -> V_74 ) ;
if ( V_166 != V_6 -> V_162 ) {
F_116 ( V_6 ) ;
} else {
F_32 ( & V_6 -> V_62 , V_60 ) ;
return 0 ;
}
}
}
if ( ! V_6 -> V_161 ) {
F_32 ( & V_6 -> V_62 , V_60 ) ;
return 0 ;
}
V_11 = F_5 ( V_6 -> V_10 + V_6 -> V_12 -> V_22 ) ;
V_11 ^= V_6 -> V_160 ;
V_11 &= V_6 -> V_47 ;
V_164 = V_11 & V_6 -> V_14 . V_40 ;
V_164 &= V_6 -> V_160 ;
V_165 = V_11 & V_6 -> V_14 . V_38 ;
V_165 &= ~ ( V_6 -> V_160 ) ;
V_163 = V_11 & ( ~ ( V_6 -> V_14 . V_40 ) &
~ ( V_6 -> V_14 . V_38 ) ) ;
V_163 |= V_164 | V_165 ;
if ( V_163 ) {
T_2 V_168 , V_169 ;
V_168 = F_5 ( V_6 -> V_10 + V_6 -> V_12 -> V_34 ) ;
V_169 = F_5 ( V_6 -> V_10 + V_6 -> V_12 -> V_36 ) ;
if ( ! V_6 -> V_12 -> V_170 ) {
F_7 ( V_168 | V_163 , V_6 -> V_10 +
V_6 -> V_12 -> V_34 ) ;
F_7 ( V_169 | V_163 , V_6 -> V_10 +
V_6 -> V_12 -> V_36 ) ;
}
if ( V_6 -> V_12 -> V_170 ) {
F_7 ( V_168 | V_11 , V_6 -> V_10 +
V_6 -> V_12 -> V_34 ) ;
F_7 ( V_169 | V_11 , V_6 -> V_10 +
V_6 -> V_12 -> V_36 ) ;
}
F_7 ( V_168 , V_6 -> V_10 + V_6 -> V_12 -> V_34 ) ;
F_7 ( V_169 , V_6 -> V_10 + V_6 -> V_12 -> V_36 ) ;
}
V_6 -> V_161 = false ;
F_32 ( & V_6 -> V_62 , V_60 ) ;
return 0 ;
}
void F_117 ( int V_171 )
{
struct V_1 * V_6 ;
F_118 (bank, &omap_gpio_list, node) {
if ( ! F_25 ( V_6 ) || ! V_6 -> V_149 )
continue;
V_6 -> V_158 = V_171 ;
F_119 ( V_6 -> V_74 ) ;
}
}
void F_120 ( void )
{
struct V_1 * V_6 ;
F_118 (bank, &omap_gpio_list, node) {
if ( ! F_25 ( V_6 ) || ! V_6 -> V_149 )
continue;
F_45 ( V_6 -> V_74 ) ;
}
}
static void F_115 ( struct V_1 * V_172 )
{
struct V_173 * V_12 = V_172 -> V_12 ;
void T_1 * V_10 = V_172 -> V_10 ;
V_172 -> V_14 . V_55 = F_5 ( V_10 + V_12 -> V_55 ) ;
V_172 -> V_14 . V_15 = F_5 ( V_10 + V_12 -> V_13 ) ;
V_172 -> V_14 . V_44 = F_5 ( V_10 + V_12 -> V_43 ) ;
V_172 -> V_14 . V_34 = F_5 ( V_10 + V_12 -> V_34 ) ;
V_172 -> V_14 . V_36 = F_5 ( V_10 + V_12 -> V_36 ) ;
V_172 -> V_14 . V_38 = F_5 ( V_10 + V_12 -> V_38 ) ;
V_172 -> V_14 . V_40 = F_5 ( V_10 + V_12 -> V_40 ) ;
V_172 -> V_14 . V_72 = F_5 ( V_10 + V_12 -> V_69 ) ;
V_172 -> V_14 . V_174 = F_5 ( V_10 + V_12 -> V_174 ) ;
if ( V_12 -> V_18 && V_172 -> V_12 -> V_20 )
V_172 -> V_14 . V_19 = F_5 ( V_10 + V_12 -> V_18 ) ;
else
V_172 -> V_14 . V_19 = F_5 ( V_10 + V_12 -> V_19 ) ;
V_172 -> V_167 = true ;
}
static void F_116 ( struct V_1 * V_6 )
{
F_7 ( V_6 -> V_14 . V_44 ,
V_6 -> V_10 + V_6 -> V_12 -> V_43 ) ;
F_7 ( V_6 -> V_14 . V_55 , V_6 -> V_10 + V_6 -> V_12 -> V_55 ) ;
F_7 ( V_6 -> V_14 . V_34 ,
V_6 -> V_10 + V_6 -> V_12 -> V_34 ) ;
F_7 ( V_6 -> V_14 . V_36 ,
V_6 -> V_10 + V_6 -> V_12 -> V_36 ) ;
F_7 ( V_6 -> V_14 . V_38 ,
V_6 -> V_10 + V_6 -> V_12 -> V_38 ) ;
F_7 ( V_6 -> V_14 . V_40 ,
V_6 -> V_10 + V_6 -> V_12 -> V_40 ) ;
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
F_7 ( V_6 -> V_14 . V_72 ,
V_6 -> V_10 + V_6 -> V_12 -> V_69 ) ;
F_7 ( V_6 -> V_14 . V_174 ,
V_6 -> V_10 + V_6 -> V_12 -> V_174 ) ;
}
static inline void F_115 ( struct V_1 * V_172 ) {}
static int T_4 F_121 ( void )
{
return F_67 ( & V_175 ) ;
}
static void T_5 F_122 ( void )
{
F_123 ( & V_175 ) ;
}
