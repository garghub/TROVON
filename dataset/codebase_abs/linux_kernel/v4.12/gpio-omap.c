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
static int F_17 ( struct V_1 * V_6 , unsigned V_16 ,
unsigned V_29 )
{
void T_1 * V_9 ;
T_2 V_30 ;
T_2 V_11 ;
bool V_17 = ! ! V_29 ;
if ( ! V_6 -> V_31 )
return - V_32 ;
if ( V_17 ) {
V_29 = F_18 ( V_29 , 31 ) - 1 ;
if ( ( V_29 & V_33 ) != V_29 )
return - V_34 ;
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
return 0 ;
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
unsigned V_35 )
{
void T_1 * V_10 = V_6 -> V_10 ;
T_2 V_21 = F_6 ( V_7 ) ;
F_12 ( V_10 , V_6 -> V_12 -> V_36 , V_21 ,
V_35 & V_37 ) ;
F_12 ( V_10 , V_6 -> V_12 -> V_38 , V_21 ,
V_35 & V_39 ) ;
F_12 ( V_10 , V_6 -> V_12 -> V_40 , V_21 ,
V_35 & V_41 ) ;
F_12 ( V_10 , V_6 -> V_12 -> V_42 , V_21 ,
V_35 & V_43 ) ;
V_6 -> V_14 . V_36 =
F_5 ( V_6 -> V_10 + V_6 -> V_12 -> V_36 ) ;
V_6 -> V_14 . V_38 =
F_5 ( V_6 -> V_10 + V_6 -> V_12 -> V_38 ) ;
V_6 -> V_14 . V_40 =
F_5 ( V_6 -> V_10 + V_6 -> V_12 -> V_40 ) ;
V_6 -> V_14 . V_42 =
F_5 ( V_6 -> V_10 + V_6 -> V_12 -> V_42 ) ;
if ( F_21 ( ! ( V_6 -> V_44 & V_21 ) ) ) {
F_12 ( V_10 , V_6 -> V_12 -> V_45 , V_21 , V_35 != 0 ) ;
V_6 -> V_14 . V_46 =
F_5 ( V_6 -> V_10 + V_6 -> V_12 -> V_45 ) ;
}
if ( ! V_6 -> V_12 -> V_47 ) {
if ( V_6 -> V_44 ) {
if ( ! ( V_6 -> V_44 & V_21 ) )
goto exit;
}
if ( V_35 & V_48 )
V_6 -> V_49 |= V_21 ;
else
V_6 -> V_49 &= ~ V_21 ;
}
exit:
V_6 -> V_50 =
F_5 ( V_6 -> V_10 + V_6 -> V_12 -> V_36 ) |
F_5 ( V_6 -> V_10 + V_6 -> V_12 -> V_38 ) ;
}
static void F_22 ( struct V_1 * V_6 , int V_7 )
{
void T_1 * V_9 = V_6 -> V_10 ;
T_2 V_11 = 0 ;
if ( ! V_6 -> V_12 -> V_47 )
return;
V_9 += V_6 -> V_12 -> V_47 ;
V_11 = F_5 ( V_9 ) ;
if ( ( V_11 >> V_7 ) & 1 )
V_11 &= ~ ( F_6 ( V_7 ) ) ;
else
V_11 |= F_6 ( V_7 ) ;
F_7 ( V_11 , V_9 ) ;
}
static void F_22 ( struct V_1 * V_6 , int V_7 ) {}
static int F_23 ( struct V_1 * V_6 , int V_7 ,
unsigned V_35 )
{
void T_1 * V_9 = V_6 -> V_10 ;
void T_1 * V_10 = V_6 -> V_10 ;
T_2 V_11 = 0 ;
if ( V_6 -> V_12 -> V_36 && V_6 -> V_12 -> V_45 ) {
F_20 ( V_6 , V_7 , V_35 ) ;
} else if ( V_6 -> V_12 -> V_47 ) {
V_9 += V_6 -> V_12 -> V_47 ;
V_11 = F_5 ( V_9 ) ;
if ( ( V_35 & V_51 ) == V_48 )
V_6 -> V_52 |= F_6 ( V_7 ) ;
if ( V_35 & V_41 )
V_11 |= F_6 ( V_7 ) ;
else if ( V_35 & V_43 )
V_11 &= ~ ( F_6 ( V_7 ) ) ;
else
return - V_34 ;
F_7 ( V_11 , V_9 ) ;
} else if ( V_6 -> V_12 -> V_53 ) {
if ( V_7 & 0x08 )
V_9 += V_6 -> V_12 -> V_54 ;
else
V_9 += V_6 -> V_12 -> V_53 ;
V_7 &= 0x07 ;
V_11 = F_5 ( V_9 ) ;
V_11 &= ~ ( 3 << ( V_7 << 1 ) ) ;
if ( V_35 & V_41 )
V_11 |= 2 << ( V_7 << 1 ) ;
if ( V_35 & V_43 )
V_11 |= F_6 ( V_7 << 1 ) ;
F_12 ( V_10 , V_6 -> V_12 -> V_45 , F_6 ( V_7 ) , V_35 ) ;
V_6 -> V_14 . V_46 =
F_5 ( V_6 -> V_10 + V_6 -> V_12 -> V_45 ) ;
F_7 ( V_11 , V_9 ) ;
}
return 0 ;
}
static void F_24 ( struct V_1 * V_6 , unsigned V_16 )
{
if ( V_6 -> V_12 -> V_55 ) {
void T_1 * V_9 = V_6 -> V_10 + V_6 -> V_12 -> V_55 ;
F_7 ( F_5 ( V_9 ) | ( F_6 ( V_16 ) ) , V_9 ) ;
}
if ( V_6 -> V_12 -> V_56 && ! F_25 ( V_6 ) ) {
void T_1 * V_9 = V_6 -> V_10 + V_6 -> V_12 -> V_56 ;
T_2 V_56 ;
V_56 = F_5 ( V_9 ) ;
V_56 &= ~ V_57 ;
F_7 ( V_56 , V_9 ) ;
V_6 -> V_14 . V_56 = V_56 ;
}
}
static void F_26 ( struct V_1 * V_6 , unsigned V_16 )
{
void T_1 * V_10 = V_6 -> V_10 ;
if ( V_6 -> V_12 -> V_45 &&
! F_27 ( V_6 -> V_58 , V_16 ) &&
! F_27 ( V_6 -> V_59 , V_16 ) ) {
F_12 ( V_10 , V_6 -> V_12 -> V_45 , F_6 ( V_16 ) , 0 ) ;
V_6 -> V_14 . V_46 =
F_5 ( V_6 -> V_10 + V_6 -> V_12 -> V_45 ) ;
}
if ( V_6 -> V_12 -> V_56 && ! F_25 ( V_6 ) ) {
void T_1 * V_9 = V_6 -> V_10 + V_6 -> V_12 -> V_56 ;
T_2 V_56 ;
V_56 = F_5 ( V_9 ) ;
V_56 |= V_57 ;
F_7 ( V_56 , V_9 ) ;
V_6 -> V_14 . V_56 = V_56 ;
}
}
static int F_28 ( struct V_1 * V_6 , unsigned V_16 )
{
void T_1 * V_9 = V_6 -> V_10 + V_6 -> V_12 -> V_13 ;
return F_5 ( V_9 ) & F_6 ( V_16 ) ;
}
static void F_29 ( struct V_1 * V_6 , unsigned V_16 )
{
if ( ! F_27 ( V_6 -> V_58 , V_16 ) ) {
F_24 ( V_6 , V_16 ) ;
F_4 ( V_6 , V_16 , 1 ) ;
}
V_6 -> V_59 |= F_6 ( V_16 ) ;
}
static int F_30 ( struct V_2 * V_3 , unsigned type )
{
struct V_1 * V_6 = F_1 ( V_3 ) ;
int V_60 ;
unsigned long V_61 ;
unsigned V_16 = V_3 -> V_62 ;
if ( type & ~ V_51 )
return - V_34 ;
if ( ! V_6 -> V_12 -> V_36 &&
( type & ( V_37 | V_39 ) ) )
return - V_34 ;
F_31 ( & V_6 -> V_63 , V_61 ) ;
V_60 = F_23 ( V_6 , V_16 , type ) ;
if ( V_60 ) {
F_32 ( & V_6 -> V_63 , V_61 ) ;
goto error;
}
F_29 ( V_6 , V_16 ) ;
if ( ! F_28 ( V_6 , V_16 ) ) {
F_32 ( & V_6 -> V_63 , V_61 ) ;
V_60 = - V_34 ;
goto error;
}
F_32 ( & V_6 -> V_63 , V_61 ) ;
if ( type & ( V_37 | V_39 ) )
F_33 ( V_3 , V_64 ) ;
else if ( type & ( V_43 | V_41 ) )
F_33 ( V_3 , V_65 ) ;
return 0 ;
error:
return V_60 ;
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
static int F_40 ( struct V_2 * V_3 , unsigned int V_17 )
{
struct V_1 * V_6 = F_1 ( V_3 ) ;
return F_41 ( V_6 -> V_75 , V_17 ) ;
}
static int F_42 ( struct V_4 * V_5 , unsigned V_16 )
{
struct V_1 * V_6 = F_3 ( V_5 ) ;
unsigned long V_61 ;
if ( ! F_25 ( V_6 ) )
F_43 ( V_5 -> V_76 ) ;
F_31 ( & V_6 -> V_63 , V_61 ) ;
F_24 ( V_6 , V_16 ) ;
V_6 -> V_58 |= F_6 ( V_16 ) ;
F_32 ( & V_6 -> V_63 , V_61 ) ;
return 0 ;
}
static void F_44 ( struct V_4 * V_5 , unsigned V_16 )
{
struct V_1 * V_6 = F_3 ( V_5 ) ;
unsigned long V_61 ;
F_31 ( & V_6 -> V_63 , V_61 ) ;
V_6 -> V_58 &= ~ ( F_6 ( V_16 ) ) ;
if ( ! F_27 ( V_6 -> V_59 , V_16 ) ) {
F_4 ( V_6 , V_16 , 1 ) ;
F_19 ( V_6 , V_16 ) ;
}
F_26 ( V_6 , V_16 ) ;
F_32 ( & V_6 -> V_63 , V_61 ) ;
if ( ! F_25 ( V_6 ) )
F_45 ( V_5 -> V_76 ) ;
}
static T_3 F_46 ( int V_75 , void * V_77 )
{
void T_1 * V_78 = NULL ;
T_2 V_79 ;
unsigned int V_80 ;
struct V_1 * V_6 = V_77 ;
unsigned long V_81 ;
unsigned long V_82 ;
V_78 = V_6 -> V_10 + V_6 -> V_12 -> V_67 ;
if ( F_47 ( ! V_78 ) )
goto exit;
F_43 ( V_6 -> V_5 . V_76 ) ;
while ( 1 ) {
T_2 V_83 , V_50 = 0 ;
T_2 V_84 ;
F_31 ( & V_6 -> V_63 , V_82 ) ;
V_84 = F_36 ( V_6 ) ;
V_83 = V_79 = F_5 ( V_78 ) & V_84 ;
if ( V_6 -> V_50 )
V_50 = V_6 -> V_50 & V_84 ;
F_38 ( V_6 , V_83 & ~ V_50 ) ;
F_34 ( V_6 , V_83 & ~ V_50 ) ;
F_37 ( V_6 , V_83 & ~ V_50 ) ;
F_32 ( & V_6 -> V_63 , V_82 ) ;
if ( ! V_79 )
break;
while ( V_79 ) {
V_80 = F_48 ( V_79 ) ;
V_79 &= ~ ( F_6 ( V_80 ) ) ;
F_31 ( & V_6 -> V_63 , V_82 ) ;
if ( V_6 -> V_52 & ( F_6 ( V_80 ) ) )
F_22 ( V_6 , V_80 ) ;
F_32 ( & V_6 -> V_63 , V_82 ) ;
F_31 ( & V_6 -> V_85 , V_81 ) ;
F_49 ( F_50 ( V_6 -> V_5 . V_86 ,
V_80 ) ) ;
F_32 ( & V_6 -> V_85 ,
V_81 ) ;
}
}
exit:
F_45 ( V_6 -> V_5 . V_76 ) ;
return V_87 ;
}
static unsigned int F_51 ( struct V_2 * V_3 )
{
struct V_1 * V_6 = F_1 ( V_3 ) ;
unsigned long V_61 ;
unsigned V_16 = V_3 -> V_62 ;
F_31 ( & V_6 -> V_63 , V_61 ) ;
if ( ! F_27 ( V_6 -> V_58 , V_16 ) )
F_4 ( V_6 , V_16 , 1 ) ;
else if ( ! F_28 ( V_6 , V_16 ) )
goto V_88;
F_24 ( V_6 , V_16 ) ;
V_6 -> V_59 |= F_6 ( V_16 ) ;
F_32 ( & V_6 -> V_63 , V_61 ) ;
F_52 ( V_3 ) ;
return 0 ;
V_88:
F_32 ( & V_6 -> V_63 , V_61 ) ;
return - V_34 ;
}
static void F_53 ( struct V_2 * V_3 )
{
struct V_1 * V_6 = F_1 ( V_3 ) ;
unsigned long V_61 ;
unsigned V_16 = V_3 -> V_62 ;
F_31 ( & V_6 -> V_63 , V_61 ) ;
V_6 -> V_59 &= ~ ( F_6 ( V_16 ) ) ;
F_39 ( V_6 , V_16 , 0 ) ;
F_35 ( V_6 , V_16 ) ;
F_23 ( V_6 , V_16 , V_89 ) ;
if ( ! F_27 ( V_6 -> V_58 , V_16 ) )
F_19 ( V_6 , V_16 ) ;
F_26 ( V_6 , V_16 ) ;
F_32 ( & V_6 -> V_63 , V_61 ) ;
}
static void F_54 ( struct V_2 * V_90 )
{
struct V_1 * V_6 = F_1 ( V_90 ) ;
if ( ! F_25 ( V_6 ) )
F_43 ( V_6 -> V_5 . V_76 ) ;
}
static void F_55 ( struct V_2 * V_90 )
{
struct V_1 * V_6 = F_1 ( V_90 ) ;
if ( ! F_25 ( V_6 ) )
F_45 ( V_6 -> V_5 . V_76 ) ;
}
static void F_56 ( struct V_2 * V_3 )
{
struct V_1 * V_6 = F_1 ( V_3 ) ;
unsigned V_16 = V_3 -> V_62 ;
F_35 ( V_6 , V_16 ) ;
}
static void F_57 ( struct V_2 * V_3 )
{
struct V_1 * V_6 = F_1 ( V_3 ) ;
unsigned V_16 = V_3 -> V_62 ;
unsigned long V_61 ;
F_31 ( & V_6 -> V_63 , V_61 ) ;
F_39 ( V_6 , V_16 , 0 ) ;
F_23 ( V_6 , V_16 , V_89 ) ;
F_32 ( & V_6 -> V_63 , V_61 ) ;
}
static void F_52 ( struct V_2 * V_3 )
{
struct V_1 * V_6 = F_1 ( V_3 ) ;
unsigned V_16 = V_3 -> V_62 ;
T_2 V_35 = F_58 ( V_3 ) ;
unsigned long V_61 ;
F_31 ( & V_6 -> V_63 , V_61 ) ;
if ( V_35 )
F_23 ( V_6 , V_16 , V_35 ) ;
if ( V_6 -> V_50 & F_6 ( V_16 ) ) {
F_39 ( V_6 , V_16 , 0 ) ;
F_35 ( V_6 , V_16 ) ;
}
F_39 ( V_6 , V_16 , 1 ) ;
F_32 ( & V_6 -> V_63 , V_61 ) ;
}
static int F_59 ( struct V_91 * V_92 )
{
struct V_93 * V_94 = F_60 ( V_92 ) ;
struct V_1 * V_6 = F_61 ( V_94 ) ;
void T_1 * V_95 = V_6 -> V_10 +
V_96 / V_6 -> V_97 ;
unsigned long V_61 ;
F_31 ( & V_6 -> V_63 , V_61 ) ;
F_7 ( 0xffff & ~ V_6 -> V_14 . V_46 , V_95 ) ;
F_32 ( & V_6 -> V_63 , V_61 ) ;
return 0 ;
}
static int F_62 ( struct V_91 * V_92 )
{
struct V_93 * V_94 = F_60 ( V_92 ) ;
struct V_1 * V_6 = F_61 ( V_94 ) ;
void T_1 * V_95 = V_6 -> V_10 +
V_96 / V_6 -> V_97 ;
unsigned long V_61 ;
F_31 ( & V_6 -> V_63 , V_61 ) ;
F_7 ( V_6 -> V_14 . V_46 , V_95 ) ;
F_32 ( & V_6 -> V_63 , V_61 ) ;
return 0 ;
}
static inline void F_63 ( struct V_1 * V_6 )
{
F_64 ( & V_98 , V_6 ) ;
if ( F_65 ( & V_99 ) == 0 )
( void ) F_66 ( & V_98 ) ;
}
static int F_67 ( struct V_4 * V_5 , unsigned V_16 )
{
struct V_1 * V_6 ;
unsigned long V_61 ;
void T_1 * V_9 ;
int V_100 ;
V_6 = F_3 ( V_5 ) ;
V_9 = V_6 -> V_10 + V_6 -> V_12 -> V_13 ;
F_31 ( & V_6 -> V_63 , V_61 ) ;
V_100 = ! ! ( F_5 ( V_9 ) & F_6 ( V_16 ) ) ;
F_32 ( & V_6 -> V_63 , V_61 ) ;
return V_100 ;
}
static int F_68 ( struct V_4 * V_5 , unsigned V_16 )
{
struct V_1 * V_6 ;
unsigned long V_61 ;
V_6 = F_3 ( V_5 ) ;
F_31 ( & V_6 -> V_63 , V_61 ) ;
F_4 ( V_6 , V_16 , 1 ) ;
F_32 ( & V_6 -> V_63 , V_61 ) ;
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
static int F_70 ( struct V_4 * V_5 , unsigned V_16 , int V_101 )
{
struct V_1 * V_6 ;
unsigned long V_61 ;
V_6 = F_3 ( V_5 ) ;
F_31 ( & V_6 -> V_63 , V_61 ) ;
V_6 -> V_18 ( V_6 , V_16 , V_101 ) ;
F_4 ( V_6 , V_16 , 0 ) ;
F_32 ( & V_6 -> V_63 , V_61 ) ;
return 0 ;
}
static int F_71 ( struct V_4 * V_5 , unsigned V_16 ,
unsigned V_29 )
{
struct V_1 * V_6 ;
unsigned long V_61 ;
int V_102 ;
V_6 = F_3 ( V_5 ) ;
F_31 ( & V_6 -> V_63 , V_61 ) ;
V_102 = F_17 ( V_6 , V_16 , V_29 ) ;
F_32 ( & V_6 -> V_63 , V_61 ) ;
if ( V_102 )
F_72 ( V_5 -> V_76 ,
L_1 ,
V_16 , V_29 , V_102 ) ;
return V_102 ;
}
static int F_73 ( struct V_4 * V_5 , unsigned V_16 ,
unsigned long V_103 )
{
T_2 V_29 ;
if ( F_74 ( V_103 ) != V_104 )
return - V_32 ;
V_29 = F_75 ( V_103 ) ;
return F_71 ( V_5 , V_16 , V_29 ) ;
}
static void F_76 ( struct V_4 * V_5 , unsigned V_16 , int V_101 )
{
struct V_1 * V_6 ;
unsigned long V_61 ;
V_6 = F_3 ( V_5 ) ;
F_31 ( & V_6 -> V_63 , V_61 ) ;
V_6 -> V_18 ( V_6 , V_16 , V_101 ) ;
F_32 ( & V_6 -> V_63 , V_61 ) ;
}
static void T_4 F_77 ( struct V_1 * V_6 )
{
static bool V_105 ;
T_2 V_106 ;
if ( V_105 || V_6 -> V_12 -> V_107 == V_108 )
return;
V_106 = F_78 ( V_6 -> V_10 + V_6 -> V_12 -> V_107 ) ;
F_79 ( L_2 ,
( V_106 >> 4 ) & 0x0f , V_106 & 0x0f ) ;
V_105 = true ;
}
static void F_80 ( struct V_1 * V_6 )
{
void T_1 * V_10 = V_6 -> V_10 ;
T_2 V_11 = 0xffffffff ;
if ( V_6 -> V_69 == 16 )
V_11 = 0xffff ;
if ( V_6 -> V_109 ) {
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
if ( V_6 -> V_12 -> V_56 )
F_7 ( 0 , V_10 + V_6 -> V_12 -> V_56 ) ;
}
static int F_81 ( struct V_1 * V_6 , struct V_110 * V_111 )
{
static int V_7 ;
int V_112 = 0 ;
int V_102 ;
V_6 -> V_5 . V_113 = F_42 ;
V_6 -> V_5 . free = F_44 ;
V_6 -> V_5 . V_114 = F_67 ;
V_6 -> V_5 . V_115 = F_68 ;
V_6 -> V_5 . V_116 = F_69 ;
V_6 -> V_5 . V_117 = F_70 ;
V_6 -> V_5 . V_118 = F_73 ;
V_6 -> V_5 . V_24 = F_76 ;
if ( V_6 -> V_109 ) {
V_6 -> V_5 . V_119 = L_3 ;
if ( V_6 -> V_12 -> V_45 )
V_6 -> V_5 . V_76 = & V_98 . V_92 ;
V_6 -> V_5 . V_10 = F_82 ( 0 ) ;
} else {
V_6 -> V_5 . V_119 = L_4 ;
V_6 -> V_5 . V_10 = V_7 ;
}
V_6 -> V_5 . V_120 = V_6 -> V_69 ;
V_102 = F_83 ( & V_6 -> V_5 , V_6 ) ;
if ( V_102 ) {
F_84 ( V_6 -> V_5 . V_76 ,
L_5 , V_102 ) ;
return V_102 ;
}
if ( ! V_6 -> V_109 )
V_7 += V_6 -> V_69 ;
#ifdef F_85
V_112 = F_86 ( V_6 -> V_5 . V_76 ,
- 1 , 0 , V_6 -> V_69 , 0 ) ;
if ( V_112 < 0 ) {
F_84 ( V_6 -> V_5 . V_76 , L_6 ) ;
return - V_121 ;
}
#endif
if ( V_6 -> V_109 ) {
V_111 -> V_122 = V_123 . V_122 ;
if ( ! V_6 -> V_12 -> V_45 )
V_111 -> V_124 = NULL ;
}
V_102 = F_87 ( & V_6 -> V_5 , V_111 ,
V_112 , V_125 ,
V_89 ) ;
if ( V_102 ) {
F_84 ( V_6 -> V_5 . V_76 ,
L_7 , V_102 ) ;
F_88 ( & V_6 -> V_5 ) ;
return - V_121 ;
}
F_89 ( & V_6 -> V_5 , V_111 , V_6 -> V_75 , NULL ) ;
V_102 = F_90 ( V_6 -> V_5 . V_76 , V_6 -> V_75 ,
F_46 ,
0 , F_91 ( V_6 -> V_5 . V_76 ) , V_6 ) ;
if ( V_102 )
F_88 ( & V_6 -> V_5 ) ;
return V_102 ;
}
static int F_92 ( struct V_93 * V_94 )
{
struct V_91 * V_92 = & V_94 -> V_92 ;
struct V_126 * V_127 = V_92 -> V_128 ;
const struct V_129 * V_130 ;
const struct V_131 * V_132 ;
struct V_133 * V_134 ;
struct V_1 * V_6 ;
struct V_110 * V_111 ;
int V_102 ;
V_130 = F_93 ( F_94 ( V_135 ) , V_92 ) ;
V_132 = V_130 ? V_130 -> V_90 : F_95 ( V_92 ) ;
if ( ! V_132 )
return - V_34 ;
V_6 = F_96 ( V_92 , sizeof( struct V_1 ) , V_136 ) ;
if ( ! V_6 ) {
F_84 ( V_92 , L_8 ) ;
return - V_137 ;
}
V_111 = F_96 ( V_92 , sizeof( * V_111 ) , V_136 ) ;
if ( ! V_111 )
return - V_137 ;
V_111 -> V_138 = F_51 ,
V_111 -> V_139 = F_53 ,
V_111 -> V_122 = F_56 ,
V_111 -> V_140 = F_57 ,
V_111 -> V_141 = F_52 ,
V_111 -> V_142 = F_30 ,
V_111 -> V_124 = F_40 ,
V_111 -> V_143 = F_54 ,
V_111 -> V_144 = F_55 ,
V_111 -> V_145 = F_91 ( & V_94 -> V_92 ) ;
V_111 -> V_61 = V_146 ;
V_6 -> V_75 = F_97 ( V_94 , 0 ) ;
if ( V_6 -> V_75 <= 0 ) {
if ( ! V_6 -> V_75 )
V_6 -> V_75 = - V_147 ;
if ( V_6 -> V_75 != - V_148 )
F_84 ( V_92 ,
L_9 , V_6 -> V_75 ) ;
return V_6 -> V_75 ;
}
V_6 -> V_5 . V_76 = V_92 ;
V_6 -> V_5 . V_149 = V_150 ;
V_6 -> V_31 = V_132 -> V_31 ;
V_6 -> V_97 = V_132 -> V_151 ;
V_6 -> V_69 = V_132 -> V_152 ;
V_6 -> V_109 = V_132 -> V_109 ;
V_6 -> V_44 = V_132 -> V_44 ;
V_6 -> V_12 = V_132 -> V_12 ;
#ifdef F_98
V_6 -> V_5 . V_128 = F_99 ( V_127 ) ;
#endif
if ( V_127 ) {
if ( ! F_100 ( V_127 , L_10 ) )
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
F_101 ( & V_6 -> V_63 ) ;
F_101 ( & V_6 -> V_85 ) ;
V_134 = F_102 ( V_94 , V_155 , 0 ) ;
V_6 -> V_10 = F_103 ( V_92 , V_134 ) ;
if ( F_104 ( V_6 -> V_10 ) ) {
return F_105 ( V_6 -> V_10 ) ;
}
if ( V_6 -> V_31 ) {
V_6 -> V_27 = F_106 ( V_92 , L_11 ) ;
if ( F_104 ( V_6 -> V_27 ) ) {
F_84 ( V_92 ,
L_12 ) ;
V_6 -> V_31 = false ;
} else {
F_107 ( V_6 -> V_27 ) ;
}
}
F_64 ( V_94 , V_6 ) ;
F_108 ( V_92 ) ;
F_109 ( V_92 ) ;
F_43 ( V_92 ) ;
if ( V_6 -> V_109 )
F_63 ( V_6 ) ;
F_80 ( V_6 ) ;
V_102 = F_81 ( V_6 , V_111 ) ;
if ( V_102 ) {
F_110 ( V_92 ) ;
F_111 ( V_92 ) ;
return V_102 ;
}
F_77 ( V_6 ) ;
F_45 ( V_92 ) ;
F_112 ( & V_6 -> V_127 , & V_156 ) ;
return 0 ;
}
static int F_113 ( struct V_93 * V_94 )
{
struct V_1 * V_6 = F_61 ( V_94 ) ;
F_114 ( & V_6 -> V_127 ) ;
F_88 ( & V_6 -> V_5 ) ;
F_111 ( & V_94 -> V_92 ) ;
if ( V_6 -> V_31 )
F_115 ( V_6 -> V_27 ) ;
return 0 ;
}
static int F_116 ( struct V_91 * V_92 )
{
struct V_93 * V_94 = F_60 ( V_92 ) ;
struct V_1 * V_6 = F_61 ( V_94 ) ;
T_2 V_157 = 0 , V_158 = 0 ;
unsigned long V_61 ;
T_2 V_159 , V_160 ;
F_31 ( & V_6 -> V_63 , V_61 ) ;
V_159 = V_6 -> V_14 . V_36 & V_6 -> V_14 . V_46 ;
if ( V_159 )
F_7 ( V_159 | V_6 -> V_14 . V_42 ,
V_6 -> V_10 + V_6 -> V_12 -> V_42 ) ;
V_160 = V_6 -> V_14 . V_38 & V_6 -> V_14 . V_46 ;
if ( V_160 )
F_7 ( V_160 | V_6 -> V_14 . V_40 ,
V_6 -> V_10 + V_6 -> V_12 -> V_40 ) ;
if ( ! V_6 -> V_49 )
goto V_161;
if ( V_6 -> V_162 != V_163 ) {
V_6 -> V_162 = 0 ;
goto V_161;
}
V_6 -> V_164 = F_5 ( V_6 -> V_10 +
V_6 -> V_12 -> V_22 ) ;
V_157 = V_6 -> V_14 . V_42 ;
V_158 = V_6 -> V_14 . V_40 ;
V_157 &= ~ V_6 -> V_49 ;
V_158 &= ~ V_6 -> V_49 ;
F_7 ( V_157 , V_6 -> V_10 + V_6 -> V_12 -> V_42 ) ;
F_7 ( V_158 , V_6 -> V_10 + V_6 -> V_12 -> V_40 ) ;
V_6 -> V_165 = true ;
V_161:
if ( V_6 -> V_154 )
V_6 -> V_166 =
V_6 -> V_154 ( V_92 ) ;
F_15 ( V_6 ) ;
F_32 ( & V_6 -> V_63 , V_61 ) ;
return 0 ;
}
static int F_117 ( struct V_91 * V_92 )
{
struct V_93 * V_94 = F_60 ( V_92 ) ;
struct V_1 * V_6 = F_61 ( V_94 ) ;
T_2 V_11 = 0 , V_167 , V_168 , V_169 ;
unsigned long V_61 ;
int V_170 ;
F_31 ( & V_6 -> V_63 , V_61 ) ;
if ( V_6 -> V_153 && ! V_6 -> V_171 ) {
F_118 ( V_6 ) ;
if ( V_6 -> V_154 )
V_6 -> V_166 =
V_6 -> V_154 ( V_92 ) ;
}
F_13 ( V_6 ) ;
F_7 ( V_6 -> V_14 . V_42 ,
V_6 -> V_10 + V_6 -> V_12 -> V_42 ) ;
F_7 ( V_6 -> V_14 . V_40 ,
V_6 -> V_10 + V_6 -> V_12 -> V_40 ) ;
if ( V_6 -> V_153 ) {
if ( ! V_6 -> V_154 ) {
F_119 ( V_6 ) ;
} else {
V_170 = V_6 -> V_154 ( V_92 ) ;
if ( V_170 != V_6 -> V_166 ) {
F_119 ( V_6 ) ;
} else {
F_32 ( & V_6 -> V_63 , V_61 ) ;
return 0 ;
}
}
}
if ( ! V_6 -> V_165 ) {
F_32 ( & V_6 -> V_63 , V_61 ) ;
return 0 ;
}
V_11 = F_5 ( V_6 -> V_10 + V_6 -> V_12 -> V_22 ) ;
V_11 ^= V_6 -> V_164 ;
V_11 &= V_6 -> V_49 ;
V_168 = V_11 & V_6 -> V_14 . V_42 ;
V_168 &= V_6 -> V_164 ;
V_169 = V_11 & V_6 -> V_14 . V_40 ;
V_169 &= ~ ( V_6 -> V_164 ) ;
V_167 = V_11 & ( ~ ( V_6 -> V_14 . V_42 ) &
~ ( V_6 -> V_14 . V_40 ) ) ;
V_167 |= V_168 | V_169 ;
if ( V_167 ) {
T_2 V_172 , V_173 ;
V_172 = F_5 ( V_6 -> V_10 + V_6 -> V_12 -> V_36 ) ;
V_173 = F_5 ( V_6 -> V_10 + V_6 -> V_12 -> V_38 ) ;
if ( ! V_6 -> V_12 -> V_174 ) {
F_7 ( V_172 | V_167 , V_6 -> V_10 +
V_6 -> V_12 -> V_36 ) ;
F_7 ( V_173 | V_167 , V_6 -> V_10 +
V_6 -> V_12 -> V_38 ) ;
}
if ( V_6 -> V_12 -> V_174 ) {
F_7 ( V_172 | V_11 , V_6 -> V_10 +
V_6 -> V_12 -> V_36 ) ;
F_7 ( V_173 | V_11 , V_6 -> V_10 +
V_6 -> V_12 -> V_38 ) ;
}
F_7 ( V_172 , V_6 -> V_10 + V_6 -> V_12 -> V_36 ) ;
F_7 ( V_173 , V_6 -> V_10 + V_6 -> V_12 -> V_38 ) ;
}
V_6 -> V_165 = false ;
F_32 ( & V_6 -> V_63 , V_61 ) ;
return 0 ;
}
void F_120 ( int V_175 )
{
struct V_1 * V_6 ;
F_121 (bank, &omap_gpio_list, node) {
if ( ! F_25 ( V_6 ) || ! V_6 -> V_153 )
continue;
V_6 -> V_162 = V_175 ;
F_122 ( V_6 -> V_5 . V_76 ) ;
}
}
void F_123 ( void )
{
struct V_1 * V_6 ;
F_121 (bank, &omap_gpio_list, node) {
if ( ! F_25 ( V_6 ) || ! V_6 -> V_153 )
continue;
F_43 ( V_6 -> V_5 . V_76 ) ;
}
}
static void F_118 ( struct V_1 * V_176 )
{
struct V_177 * V_12 = V_176 -> V_12 ;
void T_1 * V_10 = V_176 -> V_10 ;
V_176 -> V_14 . V_56 = F_5 ( V_10 + V_12 -> V_56 ) ;
V_176 -> V_14 . V_15 = F_5 ( V_10 + V_12 -> V_13 ) ;
V_176 -> V_14 . V_46 = F_5 ( V_10 + V_12 -> V_45 ) ;
V_176 -> V_14 . V_36 = F_5 ( V_10 + V_12 -> V_36 ) ;
V_176 -> V_14 . V_38 = F_5 ( V_10 + V_12 -> V_38 ) ;
V_176 -> V_14 . V_40 = F_5 ( V_10 + V_12 -> V_40 ) ;
V_176 -> V_14 . V_42 = F_5 ( V_10 + V_12 -> V_42 ) ;
V_176 -> V_14 . V_73 = F_5 ( V_10 + V_12 -> V_70 ) ;
V_176 -> V_14 . V_178 = F_5 ( V_10 + V_12 -> V_178 ) ;
if ( V_12 -> V_18 && V_176 -> V_12 -> V_20 )
V_176 -> V_14 . V_19 = F_5 ( V_10 + V_12 -> V_18 ) ;
else
V_176 -> V_14 . V_19 = F_5 ( V_10 + V_12 -> V_19 ) ;
V_176 -> V_171 = true ;
}
static void F_119 ( struct V_1 * V_6 )
{
F_7 ( V_6 -> V_14 . V_46 ,
V_6 -> V_10 + V_6 -> V_12 -> V_45 ) ;
F_7 ( V_6 -> V_14 . V_56 , V_6 -> V_10 + V_6 -> V_12 -> V_56 ) ;
F_7 ( V_6 -> V_14 . V_36 ,
V_6 -> V_10 + V_6 -> V_12 -> V_36 ) ;
F_7 ( V_6 -> V_14 . V_38 ,
V_6 -> V_10 + V_6 -> V_12 -> V_38 ) ;
F_7 ( V_6 -> V_14 . V_40 ,
V_6 -> V_10 + V_6 -> V_12 -> V_40 ) ;
F_7 ( V_6 -> V_14 . V_42 ,
V_6 -> V_10 + V_6 -> V_12 -> V_42 ) ;
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
F_7 ( V_6 -> V_14 . V_178 ,
V_6 -> V_10 + V_6 -> V_12 -> V_178 ) ;
}
static inline void F_118 ( struct V_1 * V_176 ) {}
static int T_4 F_124 ( void )
{
return F_65 ( & V_179 ) ;
}
static void T_5 F_125 ( void )
{
F_126 ( & V_179 ) ;
}
