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
static int F_40 ( struct V_2 * V_3 , unsigned int V_17 )
{
struct V_1 * V_6 = F_1 ( V_3 ) ;
return F_41 ( V_6 -> V_74 , V_17 ) ;
}
static int F_42 ( struct V_4 * V_5 , unsigned V_16 )
{
struct V_1 * V_6 = F_3 ( V_5 ) ;
unsigned long V_60 ;
if ( ! F_25 ( V_6 ) )
F_43 ( V_5 -> V_75 ) ;
F_31 ( & V_6 -> V_62 , V_60 ) ;
F_24 ( V_6 , V_16 ) ;
V_6 -> V_57 |= F_6 ( V_16 ) ;
F_32 ( & V_6 -> V_62 , V_60 ) ;
return 0 ;
}
static void F_44 ( struct V_4 * V_5 , unsigned V_16 )
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
F_45 ( V_5 -> V_75 ) ;
}
static T_3 F_46 ( int V_74 , void * V_76 )
{
void T_1 * V_77 = NULL ;
T_2 V_78 ;
unsigned int V_79 ;
struct V_1 * V_6 = V_76 ;
unsigned long V_80 ;
unsigned long V_81 ;
V_77 = V_6 -> V_10 + V_6 -> V_12 -> V_66 ;
if ( F_47 ( ! V_77 ) )
goto exit;
F_43 ( V_6 -> V_5 . V_75 ) ;
while ( 1 ) {
T_2 V_82 , V_48 = 0 ;
T_2 V_83 ;
F_31 ( & V_6 -> V_62 , V_81 ) ;
V_83 = F_36 ( V_6 ) ;
V_82 = V_78 = F_5 ( V_77 ) & V_83 ;
if ( V_6 -> V_48 )
V_48 = V_6 -> V_48 & V_83 ;
F_38 ( V_6 , V_82 & ~ V_48 ) ;
F_34 ( V_6 , V_82 & ~ V_48 ) ;
F_37 ( V_6 , V_82 & ~ V_48 ) ;
F_32 ( & V_6 -> V_62 , V_81 ) ;
if ( ! V_78 )
break;
while ( V_78 ) {
V_79 = F_48 ( V_78 ) ;
V_78 &= ~ ( F_6 ( V_79 ) ) ;
F_31 ( & V_6 -> V_62 , V_81 ) ;
if ( V_6 -> V_50 & ( F_6 ( V_79 ) ) )
F_22 ( V_6 , V_79 ) ;
F_32 ( & V_6 -> V_62 , V_81 ) ;
F_31 ( & V_6 -> V_84 , V_80 ) ;
F_49 ( F_50 ( V_6 -> V_5 . V_85 ,
V_79 ) ) ;
F_32 ( & V_6 -> V_84 ,
V_80 ) ;
}
}
exit:
F_45 ( V_6 -> V_5 . V_75 ) ;
return V_86 ;
}
static unsigned int F_51 ( struct V_2 * V_3 )
{
struct V_1 * V_6 = F_1 ( V_3 ) ;
unsigned long V_60 ;
unsigned V_16 = V_3 -> V_61 ;
F_31 ( & V_6 -> V_62 , V_60 ) ;
if ( ! F_27 ( V_6 -> V_57 , V_16 ) )
F_4 ( V_6 , V_16 , 1 ) ;
else if ( ! F_28 ( V_6 , V_16 ) )
goto V_87;
F_24 ( V_6 , V_16 ) ;
V_6 -> V_58 |= F_6 ( V_16 ) ;
F_32 ( & V_6 -> V_62 , V_60 ) ;
F_52 ( V_3 ) ;
return 0 ;
V_87:
F_32 ( & V_6 -> V_62 , V_60 ) ;
return - V_51 ;
}
static void F_53 ( struct V_2 * V_3 )
{
struct V_1 * V_6 = F_1 ( V_3 ) ;
unsigned long V_60 ;
unsigned V_16 = V_3 -> V_61 ;
F_31 ( & V_6 -> V_62 , V_60 ) ;
V_6 -> V_58 &= ~ ( F_6 ( V_16 ) ) ;
F_39 ( V_6 , V_16 , 0 ) ;
F_35 ( V_6 , V_16 ) ;
F_23 ( V_6 , V_16 , V_88 ) ;
if ( ! F_27 ( V_6 -> V_57 , V_16 ) )
F_19 ( V_6 , V_16 ) ;
F_26 ( V_6 , V_16 ) ;
F_32 ( & V_6 -> V_62 , V_60 ) ;
}
static void F_54 ( struct V_2 * V_89 )
{
struct V_1 * V_6 = F_1 ( V_89 ) ;
if ( ! F_25 ( V_6 ) )
F_43 ( V_6 -> V_5 . V_75 ) ;
}
static void F_55 ( struct V_2 * V_89 )
{
struct V_1 * V_6 = F_1 ( V_89 ) ;
if ( ! F_25 ( V_6 ) )
F_45 ( V_6 -> V_5 . V_75 ) ;
}
static void F_56 ( struct V_2 * V_3 )
{
struct V_1 * V_6 = F_1 ( V_3 ) ;
unsigned V_16 = V_3 -> V_61 ;
F_35 ( V_6 , V_16 ) ;
}
static void F_57 ( struct V_2 * V_3 )
{
struct V_1 * V_6 = F_1 ( V_3 ) ;
unsigned V_16 = V_3 -> V_61 ;
unsigned long V_60 ;
F_31 ( & V_6 -> V_62 , V_60 ) ;
F_39 ( V_6 , V_16 , 0 ) ;
F_23 ( V_6 , V_16 , V_88 ) ;
F_32 ( & V_6 -> V_62 , V_60 ) ;
}
static void F_52 ( struct V_2 * V_3 )
{
struct V_1 * V_6 = F_1 ( V_3 ) ;
unsigned V_16 = V_3 -> V_61 ;
T_2 V_33 = F_58 ( V_3 ) ;
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
static int F_59 ( struct V_90 * V_91 )
{
struct V_92 * V_93 = F_60 ( V_91 ) ;
struct V_1 * V_6 = F_61 ( V_93 ) ;
void T_1 * V_94 = V_6 -> V_10 +
V_95 / V_6 -> V_96 ;
unsigned long V_60 ;
F_31 ( & V_6 -> V_62 , V_60 ) ;
F_7 ( 0xffff & ~ V_6 -> V_14 . V_44 , V_94 ) ;
F_32 ( & V_6 -> V_62 , V_60 ) ;
return 0 ;
}
static int F_62 ( struct V_90 * V_91 )
{
struct V_92 * V_93 = F_60 ( V_91 ) ;
struct V_1 * V_6 = F_61 ( V_93 ) ;
void T_1 * V_94 = V_6 -> V_10 +
V_95 / V_6 -> V_96 ;
unsigned long V_60 ;
F_31 ( & V_6 -> V_62 , V_60 ) ;
F_7 ( V_6 -> V_14 . V_44 , V_94 ) ;
F_32 ( & V_6 -> V_62 , V_60 ) ;
return 0 ;
}
static inline void F_63 ( struct V_1 * V_6 )
{
F_64 ( & V_97 , V_6 ) ;
if ( F_65 ( & V_98 ) == 0 )
( void ) F_66 ( & V_97 ) ;
}
static int F_67 ( struct V_4 * V_5 , unsigned V_16 )
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
static int F_68 ( struct V_4 * V_5 , unsigned V_16 )
{
struct V_1 * V_6 ;
unsigned long V_60 ;
V_6 = F_3 ( V_5 ) ;
F_31 ( & V_6 -> V_62 , V_60 ) ;
F_4 ( V_6 , V_16 , 1 ) ;
F_32 ( & V_6 -> V_62 , V_60 ) ;
return 0 ;
}
static int F_69 ( struct V_4 * V_5 , unsigned V_16 )
{
struct V_1 * V_6 ;
V_6 = F_3 ( V_5 ) ;
if ( F_28 ( V_6 , V_16 ) )
return F_10 ( V_6 , V_16 ) ;
else
return F_11 ( V_6 , V_16 ) ;
}
static int F_70 ( struct V_4 * V_5 , unsigned V_16 , int V_100 )
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
static int F_71 ( struct V_4 * V_5 , unsigned V_16 ,
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
static int F_72 ( struct V_4 * V_5 , unsigned V_16 ,
unsigned long V_101 )
{
T_2 V_29 ;
if ( F_73 ( V_101 ) != V_102 )
return - V_103 ;
V_29 = F_74 ( V_101 ) ;
return F_71 ( V_5 , V_16 , V_29 ) ;
}
static void F_75 ( struct V_4 * V_5 , unsigned V_16 , int V_100 )
{
struct V_1 * V_6 ;
unsigned long V_60 ;
V_6 = F_3 ( V_5 ) ;
F_31 ( & V_6 -> V_62 , V_60 ) ;
V_6 -> V_18 ( V_6 , V_16 , V_100 ) ;
F_32 ( & V_6 -> V_62 , V_60 ) ;
}
static void T_4 F_76 ( struct V_1 * V_6 )
{
static bool V_104 ;
T_2 V_105 ;
if ( V_104 || V_6 -> V_12 -> V_106 == V_107 )
return;
V_105 = F_77 ( V_6 -> V_10 + V_6 -> V_12 -> V_106 ) ;
F_78 ( L_1 ,
( V_105 >> 4 ) & 0x0f , V_105 & 0x0f ) ;
V_104 = true ;
}
static void F_79 ( struct V_1 * V_6 )
{
void T_1 * V_10 = V_6 -> V_10 ;
T_2 V_11 = 0xffffffff ;
if ( V_6 -> V_68 == 16 )
V_11 = 0xffff ;
if ( V_6 -> V_108 ) {
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
static int F_80 ( struct V_1 * V_6 , struct V_109 * V_110 )
{
static int V_7 ;
int V_111 = 0 ;
int V_112 ;
V_6 -> V_5 . V_113 = F_42 ;
V_6 -> V_5 . free = F_44 ;
V_6 -> V_5 . V_114 = F_67 ;
V_6 -> V_5 . V_115 = F_68 ;
V_6 -> V_5 . V_116 = F_69 ;
V_6 -> V_5 . V_117 = F_70 ;
V_6 -> V_5 . V_118 = F_72 ;
V_6 -> V_5 . V_24 = F_75 ;
if ( V_6 -> V_108 ) {
V_6 -> V_5 . V_119 = L_2 ;
if ( V_6 -> V_12 -> V_43 )
V_6 -> V_5 . V_75 = & V_97 . V_91 ;
V_6 -> V_5 . V_10 = F_81 ( 0 ) ;
} else {
V_6 -> V_5 . V_119 = L_3 ;
V_6 -> V_5 . V_10 = V_7 ;
}
V_6 -> V_5 . V_120 = V_6 -> V_68 ;
V_112 = F_82 ( & V_6 -> V_5 , V_6 ) ;
if ( V_112 ) {
F_83 ( V_6 -> V_5 . V_75 ,
L_4 , V_112 ) ;
return V_112 ;
}
if ( ! V_6 -> V_108 )
V_7 += V_6 -> V_68 ;
#ifdef F_84
V_111 = F_85 ( - 1 , 0 , V_6 -> V_68 , 0 ) ;
if ( V_111 < 0 ) {
F_83 ( V_6 -> V_5 . V_75 , L_5 ) ;
return - V_121 ;
}
#endif
if ( V_6 -> V_108 ) {
V_110 -> V_122 = V_123 . V_122 ;
if ( ! V_6 -> V_12 -> V_43 )
V_110 -> V_124 = NULL ;
}
V_112 = F_86 ( & V_6 -> V_5 , V_110 ,
V_111 , V_125 ,
V_88 ) ;
if ( V_112 ) {
F_83 ( V_6 -> V_5 . V_75 ,
L_6 , V_112 ) ;
F_87 ( & V_6 -> V_5 ) ;
return - V_121 ;
}
F_88 ( & V_6 -> V_5 , V_110 , V_6 -> V_74 , NULL ) ;
V_112 = F_89 ( V_6 -> V_5 . V_75 , V_6 -> V_74 ,
F_46 ,
0 , F_90 ( V_6 -> V_5 . V_75 ) , V_6 ) ;
if ( V_112 )
F_87 ( & V_6 -> V_5 ) ;
return V_112 ;
}
static int F_91 ( struct V_92 * V_93 )
{
struct V_90 * V_91 = & V_93 -> V_91 ;
struct V_126 * V_127 = V_91 -> V_128 ;
const struct V_129 * V_130 ;
const struct V_131 * V_132 ;
struct V_133 * V_134 ;
struct V_1 * V_6 ;
struct V_109 * V_110 ;
int V_112 ;
V_130 = F_92 ( F_93 ( V_135 ) , V_91 ) ;
V_132 = V_130 ? V_130 -> V_89 : F_94 ( V_91 ) ;
if ( ! V_132 )
return - V_51 ;
V_6 = F_95 ( V_91 , sizeof( struct V_1 ) , V_136 ) ;
if ( ! V_6 ) {
F_83 ( V_91 , L_7 ) ;
return - V_137 ;
}
V_110 = F_95 ( V_91 , sizeof( * V_110 ) , V_136 ) ;
if ( ! V_110 )
return - V_137 ;
V_110 -> V_138 = F_51 ,
V_110 -> V_139 = F_53 ,
V_110 -> V_122 = F_56 ,
V_110 -> V_140 = F_57 ,
V_110 -> V_141 = F_52 ,
V_110 -> V_142 = F_30 ,
V_110 -> V_124 = F_40 ,
V_110 -> V_143 = F_54 ,
V_110 -> V_144 = F_55 ,
V_110 -> V_145 = F_90 ( & V_93 -> V_91 ) ;
V_110 -> V_60 = V_146 ;
V_6 -> V_74 = F_96 ( V_93 , 0 ) ;
if ( V_6 -> V_74 <= 0 ) {
if ( ! V_6 -> V_74 )
V_6 -> V_74 = - V_147 ;
if ( V_6 -> V_74 != - V_148 )
F_83 ( V_91 ,
L_8 , V_6 -> V_74 ) ;
return V_6 -> V_74 ;
}
V_6 -> V_5 . V_75 = V_91 ;
V_6 -> V_5 . V_149 = V_150 ;
V_6 -> V_31 = V_132 -> V_31 ;
V_6 -> V_96 = V_132 -> V_151 ;
V_6 -> V_68 = V_132 -> V_152 ;
V_6 -> V_108 = V_132 -> V_108 ;
V_6 -> V_42 = V_132 -> V_42 ;
V_6 -> V_12 = V_132 -> V_12 ;
#ifdef F_97
V_6 -> V_5 . V_128 = F_98 ( V_127 ) ;
#endif
if ( V_127 ) {
if ( ! F_99 ( V_127 , L_9 ) )
V_6 -> V_153 = true ;
} else {
V_6 -> V_153 = V_132 -> V_153 ;
if ( V_6 -> V_153 )
V_6 -> V_154 =
V_132 -> V_154 ;
}
if ( V_6 -> V_12 -> V_18 && V_6 -> V_12 -> V_20 )
V_6 -> V_18 = F_8 ;
else
V_6 -> V_18 = F_9 ;
F_100 ( & V_6 -> V_62 ) ;
F_100 ( & V_6 -> V_84 ) ;
V_134 = F_101 ( V_93 , V_155 , 0 ) ;
V_6 -> V_10 = F_102 ( V_91 , V_134 ) ;
if ( F_103 ( V_6 -> V_10 ) ) {
return F_104 ( V_6 -> V_10 ) ;
}
if ( V_6 -> V_31 ) {
V_6 -> V_27 = F_105 ( V_91 , L_10 ) ;
if ( F_103 ( V_6 -> V_27 ) ) {
F_83 ( V_91 ,
L_11 ) ;
V_6 -> V_31 = false ;
} else {
F_106 ( V_6 -> V_27 ) ;
}
}
F_64 ( V_93 , V_6 ) ;
F_107 ( V_91 ) ;
F_108 ( V_91 ) ;
F_43 ( V_91 ) ;
if ( V_6 -> V_108 )
F_63 ( V_6 ) ;
F_79 ( V_6 ) ;
V_112 = F_80 ( V_6 , V_110 ) ;
if ( V_112 ) {
F_109 ( V_91 ) ;
F_110 ( V_91 ) ;
return V_112 ;
}
F_76 ( V_6 ) ;
F_45 ( V_91 ) ;
F_111 ( & V_6 -> V_127 , & V_156 ) ;
return 0 ;
}
static int F_112 ( struct V_92 * V_93 )
{
struct V_1 * V_6 = F_61 ( V_93 ) ;
F_113 ( & V_6 -> V_127 ) ;
F_87 ( & V_6 -> V_5 ) ;
F_110 ( & V_93 -> V_91 ) ;
if ( V_6 -> V_31 )
F_114 ( V_6 -> V_27 ) ;
return 0 ;
}
static int F_115 ( struct V_90 * V_91 )
{
struct V_92 * V_93 = F_60 ( V_91 ) ;
struct V_1 * V_6 = F_61 ( V_93 ) ;
T_2 V_157 = 0 , V_158 = 0 ;
unsigned long V_60 ;
T_2 V_159 , V_160 ;
F_31 ( & V_6 -> V_62 , V_60 ) ;
V_159 = V_6 -> V_14 . V_34 & V_6 -> V_14 . V_44 ;
if ( V_159 )
F_7 ( V_159 | V_6 -> V_14 . V_40 ,
V_6 -> V_10 + V_6 -> V_12 -> V_40 ) ;
V_160 = V_6 -> V_14 . V_36 & V_6 -> V_14 . V_44 ;
if ( V_160 )
F_7 ( V_160 | V_6 -> V_14 . V_38 ,
V_6 -> V_10 + V_6 -> V_12 -> V_38 ) ;
if ( ! V_6 -> V_47 )
goto V_161;
if ( V_6 -> V_162 != V_163 ) {
V_6 -> V_162 = 0 ;
goto V_161;
}
V_6 -> V_164 = F_5 ( V_6 -> V_10 +
V_6 -> V_12 -> V_22 ) ;
V_157 = V_6 -> V_14 . V_40 ;
V_158 = V_6 -> V_14 . V_38 ;
V_157 &= ~ V_6 -> V_47 ;
V_158 &= ~ V_6 -> V_47 ;
F_7 ( V_157 , V_6 -> V_10 + V_6 -> V_12 -> V_40 ) ;
F_7 ( V_158 , V_6 -> V_10 + V_6 -> V_12 -> V_38 ) ;
V_6 -> V_165 = true ;
V_161:
if ( V_6 -> V_154 )
V_6 -> V_166 =
V_6 -> V_154 ( V_91 ) ;
F_15 ( V_6 ) ;
F_32 ( & V_6 -> V_62 , V_60 ) ;
return 0 ;
}
static int F_116 ( struct V_90 * V_91 )
{
struct V_92 * V_93 = F_60 ( V_91 ) ;
struct V_1 * V_6 = F_61 ( V_93 ) ;
T_2 V_11 = 0 , V_167 , V_168 , V_169 ;
unsigned long V_60 ;
int V_170 ;
F_31 ( & V_6 -> V_62 , V_60 ) ;
if ( V_6 -> V_153 && ! V_6 -> V_171 ) {
F_117 ( V_6 ) ;
if ( V_6 -> V_154 )
V_6 -> V_166 =
V_6 -> V_154 ( V_91 ) ;
}
F_13 ( V_6 ) ;
F_7 ( V_6 -> V_14 . V_40 ,
V_6 -> V_10 + V_6 -> V_12 -> V_40 ) ;
F_7 ( V_6 -> V_14 . V_38 ,
V_6 -> V_10 + V_6 -> V_12 -> V_38 ) ;
if ( V_6 -> V_153 ) {
if ( ! V_6 -> V_154 ) {
F_118 ( V_6 ) ;
} else {
V_170 = V_6 -> V_154 ( V_91 ) ;
if ( V_170 != V_6 -> V_166 ) {
F_118 ( V_6 ) ;
} else {
F_32 ( & V_6 -> V_62 , V_60 ) ;
return 0 ;
}
}
}
if ( ! V_6 -> V_165 ) {
F_32 ( & V_6 -> V_62 , V_60 ) ;
return 0 ;
}
V_11 = F_5 ( V_6 -> V_10 + V_6 -> V_12 -> V_22 ) ;
V_11 ^= V_6 -> V_164 ;
V_11 &= V_6 -> V_47 ;
V_168 = V_11 & V_6 -> V_14 . V_40 ;
V_168 &= V_6 -> V_164 ;
V_169 = V_11 & V_6 -> V_14 . V_38 ;
V_169 &= ~ ( V_6 -> V_164 ) ;
V_167 = V_11 & ( ~ ( V_6 -> V_14 . V_40 ) &
~ ( V_6 -> V_14 . V_38 ) ) ;
V_167 |= V_168 | V_169 ;
if ( V_167 ) {
T_2 V_172 , V_173 ;
V_172 = F_5 ( V_6 -> V_10 + V_6 -> V_12 -> V_34 ) ;
V_173 = F_5 ( V_6 -> V_10 + V_6 -> V_12 -> V_36 ) ;
if ( ! V_6 -> V_12 -> V_174 ) {
F_7 ( V_172 | V_167 , V_6 -> V_10 +
V_6 -> V_12 -> V_34 ) ;
F_7 ( V_173 | V_167 , V_6 -> V_10 +
V_6 -> V_12 -> V_36 ) ;
}
if ( V_6 -> V_12 -> V_174 ) {
F_7 ( V_172 | V_11 , V_6 -> V_10 +
V_6 -> V_12 -> V_34 ) ;
F_7 ( V_173 | V_11 , V_6 -> V_10 +
V_6 -> V_12 -> V_36 ) ;
}
F_7 ( V_172 , V_6 -> V_10 + V_6 -> V_12 -> V_34 ) ;
F_7 ( V_173 , V_6 -> V_10 + V_6 -> V_12 -> V_36 ) ;
}
V_6 -> V_165 = false ;
F_32 ( & V_6 -> V_62 , V_60 ) ;
return 0 ;
}
void F_119 ( int V_175 )
{
struct V_1 * V_6 ;
F_120 (bank, &omap_gpio_list, node) {
if ( ! F_25 ( V_6 ) || ! V_6 -> V_153 )
continue;
V_6 -> V_162 = V_175 ;
F_121 ( V_6 -> V_5 . V_75 ) ;
}
}
void F_122 ( void )
{
struct V_1 * V_6 ;
F_120 (bank, &omap_gpio_list, node) {
if ( ! F_25 ( V_6 ) || ! V_6 -> V_153 )
continue;
F_43 ( V_6 -> V_5 . V_75 ) ;
}
}
static void F_117 ( struct V_1 * V_176 )
{
struct V_177 * V_12 = V_176 -> V_12 ;
void T_1 * V_10 = V_176 -> V_10 ;
V_176 -> V_14 . V_55 = F_5 ( V_10 + V_12 -> V_55 ) ;
V_176 -> V_14 . V_15 = F_5 ( V_10 + V_12 -> V_13 ) ;
V_176 -> V_14 . V_44 = F_5 ( V_10 + V_12 -> V_43 ) ;
V_176 -> V_14 . V_34 = F_5 ( V_10 + V_12 -> V_34 ) ;
V_176 -> V_14 . V_36 = F_5 ( V_10 + V_12 -> V_36 ) ;
V_176 -> V_14 . V_38 = F_5 ( V_10 + V_12 -> V_38 ) ;
V_176 -> V_14 . V_40 = F_5 ( V_10 + V_12 -> V_40 ) ;
V_176 -> V_14 . V_72 = F_5 ( V_10 + V_12 -> V_69 ) ;
V_176 -> V_14 . V_178 = F_5 ( V_10 + V_12 -> V_178 ) ;
if ( V_12 -> V_18 && V_176 -> V_12 -> V_20 )
V_176 -> V_14 . V_19 = F_5 ( V_10 + V_12 -> V_18 ) ;
else
V_176 -> V_14 . V_19 = F_5 ( V_10 + V_12 -> V_19 ) ;
V_176 -> V_171 = true ;
}
static void F_118 ( struct V_1 * V_6 )
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
F_7 ( V_6 -> V_14 . V_178 ,
V_6 -> V_10 + V_6 -> V_12 -> V_178 ) ;
}
static inline void F_117 ( struct V_1 * V_176 ) {}
static int T_4 F_123 ( void )
{
return F_65 ( & V_179 ) ;
}
static void T_5 F_124 ( void )
{
F_125 ( & V_179 ) ;
}
