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
T_2 V_79 , V_80 , V_50 ;
unsigned int V_81 ;
struct V_1 * V_6 = V_77 ;
unsigned long V_82 ;
unsigned long V_83 ;
V_78 = V_6 -> V_10 + V_6 -> V_12 -> V_67 ;
if ( F_47 ( ! V_78 ) )
goto exit;
F_43 ( V_6 -> V_5 . V_76 ) ;
while ( 1 ) {
F_31 ( & V_6 -> V_63 , V_83 ) ;
V_79 = F_36 ( V_6 ) ;
V_80 = F_5 ( V_78 ) & V_79 ;
if ( V_6 -> V_50 )
V_50 = V_6 -> V_50 & V_79 ;
else
V_50 = 0 ;
if ( V_80 & ~ V_50 )
F_34 ( V_6 , V_80 & ~ V_50 ) ;
F_32 ( & V_6 -> V_63 , V_83 ) ;
if ( ! V_80 )
break;
while ( V_80 ) {
V_81 = F_48 ( V_80 ) ;
V_80 &= ~ ( F_6 ( V_81 ) ) ;
F_31 ( & V_6 -> V_63 , V_83 ) ;
if ( V_6 -> V_52 & ( F_6 ( V_81 ) ) )
F_22 ( V_6 , V_81 ) ;
F_32 ( & V_6 -> V_63 , V_83 ) ;
F_31 ( & V_6 -> V_84 , V_82 ) ;
F_49 ( F_50 ( V_6 -> V_5 . V_85 ,
V_81 ) ) ;
F_32 ( & V_6 -> V_84 ,
V_82 ) ;
}
}
exit:
F_45 ( V_6 -> V_5 . V_76 ) ;
return V_86 ;
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
goto V_87;
F_24 ( V_6 , V_16 ) ;
V_6 -> V_59 |= F_6 ( V_16 ) ;
F_32 ( & V_6 -> V_63 , V_61 ) ;
F_52 ( V_3 ) ;
return 0 ;
V_87:
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
F_23 ( V_6 , V_16 , V_88 ) ;
if ( ! F_27 ( V_6 -> V_58 , V_16 ) )
F_19 ( V_6 , V_16 ) ;
F_26 ( V_6 , V_16 ) ;
F_32 ( & V_6 -> V_63 , V_61 ) ;
}
static void F_54 ( struct V_2 * V_89 )
{
struct V_1 * V_6 = F_1 ( V_89 ) ;
if ( ! F_25 ( V_6 ) )
F_43 ( V_6 -> V_5 . V_76 ) ;
}
static void F_55 ( struct V_2 * V_89 )
{
struct V_1 * V_6 = F_1 ( V_89 ) ;
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
F_23 ( V_6 , V_16 , V_88 ) ;
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
static int F_59 ( struct V_90 * V_91 )
{
struct V_92 * V_93 = F_60 ( V_91 ) ;
struct V_1 * V_6 = F_61 ( V_93 ) ;
void T_1 * V_94 = V_6 -> V_10 +
V_95 / V_6 -> V_96 ;
unsigned long V_61 ;
F_31 ( & V_6 -> V_63 , V_61 ) ;
F_7 ( 0xffff & ~ V_6 -> V_14 . V_46 , V_94 ) ;
F_32 ( & V_6 -> V_63 , V_61 ) ;
return 0 ;
}
static int F_62 ( struct V_90 * V_91 )
{
struct V_92 * V_93 = F_60 ( V_91 ) ;
struct V_1 * V_6 = F_61 ( V_93 ) ;
void T_1 * V_94 = V_6 -> V_10 +
V_95 / V_6 -> V_96 ;
unsigned long V_61 ;
F_31 ( & V_6 -> V_63 , V_61 ) ;
F_7 ( V_6 -> V_14 . V_46 , V_94 ) ;
F_32 ( & V_6 -> V_63 , V_61 ) ;
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
unsigned long V_61 ;
void T_1 * V_9 ;
int V_99 ;
V_6 = F_3 ( V_5 ) ;
V_9 = V_6 -> V_10 + V_6 -> V_12 -> V_13 ;
F_31 ( & V_6 -> V_63 , V_61 ) ;
V_99 = ! ! ( F_5 ( V_9 ) & F_6 ( V_16 ) ) ;
F_32 ( & V_6 -> V_63 , V_61 ) ;
return V_99 ;
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
static int F_70 ( struct V_4 * V_5 , unsigned V_16 , int V_100 )
{
struct V_1 * V_6 ;
unsigned long V_61 ;
V_6 = F_3 ( V_5 ) ;
F_31 ( & V_6 -> V_63 , V_61 ) ;
V_6 -> V_18 ( V_6 , V_16 , V_100 ) ;
F_4 ( V_6 , V_16 , 0 ) ;
F_32 ( & V_6 -> V_63 , V_61 ) ;
return 0 ;
}
static int F_71 ( struct V_4 * V_5 , unsigned V_16 ,
unsigned V_29 )
{
struct V_1 * V_6 ;
unsigned long V_61 ;
int V_101 ;
V_6 = F_3 ( V_5 ) ;
F_31 ( & V_6 -> V_63 , V_61 ) ;
V_101 = F_17 ( V_6 , V_16 , V_29 ) ;
F_32 ( & V_6 -> V_63 , V_61 ) ;
if ( V_101 )
F_72 ( V_5 -> V_76 ,
L_1 ,
V_16 , V_29 , V_101 ) ;
return V_101 ;
}
static int F_73 ( struct V_4 * V_5 , unsigned V_16 ,
unsigned long V_102 )
{
T_2 V_29 ;
if ( F_74 ( V_102 ) != V_103 )
return - V_32 ;
V_29 = F_75 ( V_102 ) ;
return F_71 ( V_5 , V_16 , V_29 ) ;
}
static void F_76 ( struct V_4 * V_5 , unsigned V_16 , int V_100 )
{
struct V_1 * V_6 ;
unsigned long V_61 ;
V_6 = F_3 ( V_5 ) ;
F_31 ( & V_6 -> V_63 , V_61 ) ;
V_6 -> V_18 ( V_6 , V_16 , V_100 ) ;
F_32 ( & V_6 -> V_63 , V_61 ) ;
}
static void F_77 ( struct V_1 * V_6 )
{
static bool V_104 ;
T_2 V_105 ;
if ( V_104 || V_6 -> V_12 -> V_106 == V_107 )
return;
V_105 = F_78 ( V_6 -> V_10 + V_6 -> V_12 -> V_106 ) ;
F_79 ( L_2 ,
( V_105 >> 4 ) & 0x0f , V_105 & 0x0f ) ;
V_104 = true ;
}
static void F_80 ( struct V_1 * V_6 )
{
void T_1 * V_10 = V_6 -> V_10 ;
T_2 V_11 = 0xffffffff ;
if ( V_6 -> V_69 == 16 )
V_11 = 0xffff ;
if ( V_6 -> V_108 ) {
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
static int F_81 ( struct V_1 * V_6 , struct V_109 * V_110 )
{
static int V_7 ;
int V_111 = 0 ;
int V_101 ;
V_6 -> V_5 . V_112 = F_42 ;
V_6 -> V_5 . free = F_44 ;
V_6 -> V_5 . V_113 = F_67 ;
V_6 -> V_5 . V_114 = F_68 ;
V_6 -> V_5 . V_115 = F_69 ;
V_6 -> V_5 . V_116 = F_70 ;
V_6 -> V_5 . V_117 = F_73 ;
V_6 -> V_5 . V_24 = F_76 ;
if ( V_6 -> V_108 ) {
V_6 -> V_5 . V_118 = L_3 ;
if ( V_6 -> V_12 -> V_45 )
V_6 -> V_5 . V_76 = & V_97 . V_91 ;
V_6 -> V_5 . V_10 = F_82 ( 0 ) ;
} else {
V_6 -> V_5 . V_118 = L_4 ;
V_6 -> V_5 . V_10 = V_7 ;
}
V_6 -> V_5 . V_119 = V_6 -> V_69 ;
V_101 = F_83 ( & V_6 -> V_5 , V_6 ) ;
if ( V_101 ) {
F_84 ( V_6 -> V_5 . V_76 ,
L_5 , V_101 ) ;
return V_101 ;
}
if ( ! V_6 -> V_108 )
V_7 += V_6 -> V_69 ;
#ifdef F_85
V_111 = F_86 ( V_6 -> V_5 . V_76 ,
- 1 , 0 , V_6 -> V_69 , 0 ) ;
if ( V_111 < 0 ) {
F_84 ( V_6 -> V_5 . V_76 , L_6 ) ;
return - V_120 ;
}
#endif
if ( V_6 -> V_108 ) {
V_110 -> V_121 = V_122 . V_121 ;
if ( ! V_6 -> V_12 -> V_45 )
V_110 -> V_123 = NULL ;
}
V_101 = F_87 ( & V_6 -> V_5 , V_110 ,
V_111 , V_124 ,
V_88 ) ;
if ( V_101 ) {
F_84 ( V_6 -> V_5 . V_76 ,
L_7 , V_101 ) ;
F_88 ( & V_6 -> V_5 ) ;
return - V_120 ;
}
F_89 ( & V_6 -> V_5 , V_110 , V_6 -> V_75 , NULL ) ;
V_101 = F_90 ( V_6 -> V_5 . V_76 , V_6 -> V_75 ,
F_46 ,
0 , F_91 ( V_6 -> V_5 . V_76 ) , V_6 ) ;
if ( V_101 )
F_88 ( & V_6 -> V_5 ) ;
return V_101 ;
}
static int F_92 ( struct V_92 * V_93 )
{
struct V_90 * V_91 = & V_93 -> V_91 ;
struct V_125 * V_126 = V_91 -> V_127 ;
const struct V_128 * V_129 ;
const struct V_130 * V_131 ;
struct V_132 * V_133 ;
struct V_1 * V_6 ;
struct V_109 * V_110 ;
int V_101 ;
V_129 = F_93 ( F_94 ( V_134 ) , V_91 ) ;
V_131 = V_129 ? V_129 -> V_89 : F_95 ( V_91 ) ;
if ( ! V_131 )
return - V_34 ;
V_6 = F_96 ( V_91 , sizeof( struct V_1 ) , V_135 ) ;
if ( ! V_6 ) {
F_84 ( V_91 , L_8 ) ;
return - V_136 ;
}
V_110 = F_96 ( V_91 , sizeof( * V_110 ) , V_135 ) ;
if ( ! V_110 )
return - V_136 ;
V_110 -> V_137 = F_51 ,
V_110 -> V_138 = F_53 ,
V_110 -> V_121 = F_56 ,
V_110 -> V_139 = F_57 ,
V_110 -> V_140 = F_52 ,
V_110 -> V_141 = F_30 ,
V_110 -> V_123 = F_40 ,
V_110 -> V_142 = F_54 ,
V_110 -> V_143 = F_55 ,
V_110 -> V_144 = F_91 ( & V_93 -> V_91 ) ;
V_110 -> V_61 = V_145 ;
V_6 -> V_75 = F_97 ( V_93 , 0 ) ;
if ( V_6 -> V_75 <= 0 ) {
if ( ! V_6 -> V_75 )
V_6 -> V_75 = - V_146 ;
if ( V_6 -> V_75 != - V_147 )
F_84 ( V_91 ,
L_9 , V_6 -> V_75 ) ;
return V_6 -> V_75 ;
}
V_6 -> V_5 . V_76 = V_91 ;
V_6 -> V_5 . V_148 = V_149 ;
V_6 -> V_31 = V_131 -> V_31 ;
V_6 -> V_96 = V_131 -> V_150 ;
V_6 -> V_69 = V_131 -> V_151 ;
V_6 -> V_108 = V_131 -> V_108 ;
V_6 -> V_44 = V_131 -> V_44 ;
V_6 -> V_12 = V_131 -> V_12 ;
#ifdef F_98
V_6 -> V_5 . V_127 = F_99 ( V_126 ) ;
#endif
if ( V_126 ) {
if ( ! F_100 ( V_126 , L_10 ) )
V_6 -> V_152 = true ;
} else {
V_6 -> V_152 = V_131 -> V_152 ;
if ( V_6 -> V_152 )
V_6 -> V_153 =
V_131 -> V_153 ;
}
if ( V_6 -> V_12 -> V_18 && V_6 -> V_12 -> V_20 )
V_6 -> V_18 = F_8 ;
else
V_6 -> V_18 = F_9 ;
F_101 ( & V_6 -> V_63 ) ;
F_101 ( & V_6 -> V_84 ) ;
V_133 = F_102 ( V_93 , V_154 , 0 ) ;
V_6 -> V_10 = F_103 ( V_91 , V_133 ) ;
if ( F_104 ( V_6 -> V_10 ) ) {
return F_105 ( V_6 -> V_10 ) ;
}
if ( V_6 -> V_31 ) {
V_6 -> V_27 = F_106 ( V_91 , L_11 ) ;
if ( F_104 ( V_6 -> V_27 ) ) {
F_84 ( V_91 ,
L_12 ) ;
V_6 -> V_31 = false ;
} else {
F_107 ( V_6 -> V_27 ) ;
}
}
F_64 ( V_93 , V_6 ) ;
F_108 ( V_91 ) ;
F_109 ( V_91 ) ;
F_43 ( V_91 ) ;
if ( V_6 -> V_108 )
F_63 ( V_6 ) ;
F_80 ( V_6 ) ;
V_101 = F_81 ( V_6 , V_110 ) ;
if ( V_101 ) {
F_110 ( V_91 ) ;
F_111 ( V_91 ) ;
if ( V_6 -> V_31 )
F_112 ( V_6 -> V_27 ) ;
return V_101 ;
}
F_77 ( V_6 ) ;
F_45 ( V_91 ) ;
F_113 ( & V_6 -> V_126 , & V_155 ) ;
return 0 ;
}
static int F_114 ( struct V_92 * V_93 )
{
struct V_1 * V_6 = F_61 ( V_93 ) ;
F_115 ( & V_6 -> V_126 ) ;
F_88 ( & V_6 -> V_5 ) ;
F_111 ( & V_93 -> V_91 ) ;
if ( V_6 -> V_31 )
F_112 ( V_6 -> V_27 ) ;
return 0 ;
}
static int F_116 ( struct V_90 * V_91 )
{
struct V_92 * V_93 = F_60 ( V_91 ) ;
struct V_1 * V_6 = F_61 ( V_93 ) ;
T_2 V_156 = 0 , V_157 = 0 ;
unsigned long V_61 ;
T_2 V_158 , V_159 ;
F_31 ( & V_6 -> V_63 , V_61 ) ;
V_158 = V_6 -> V_14 . V_36 & V_6 -> V_14 . V_46 ;
if ( V_158 )
F_7 ( V_158 | V_6 -> V_14 . V_42 ,
V_6 -> V_10 + V_6 -> V_12 -> V_42 ) ;
V_159 = V_6 -> V_14 . V_38 & V_6 -> V_14 . V_46 ;
if ( V_159 )
F_7 ( V_159 | V_6 -> V_14 . V_40 ,
V_6 -> V_10 + V_6 -> V_12 -> V_40 ) ;
if ( ! V_6 -> V_49 )
goto V_160;
if ( V_6 -> V_161 != V_162 ) {
V_6 -> V_161 = 0 ;
goto V_160;
}
V_6 -> V_163 = F_5 ( V_6 -> V_10 +
V_6 -> V_12 -> V_22 ) ;
V_156 = V_6 -> V_14 . V_42 ;
V_157 = V_6 -> V_14 . V_40 ;
V_156 &= ~ V_6 -> V_49 ;
V_157 &= ~ V_6 -> V_49 ;
F_7 ( V_156 , V_6 -> V_10 + V_6 -> V_12 -> V_42 ) ;
F_7 ( V_157 , V_6 -> V_10 + V_6 -> V_12 -> V_40 ) ;
V_6 -> V_164 = true ;
V_160:
if ( V_6 -> V_153 )
V_6 -> V_165 =
V_6 -> V_153 ( V_91 ) ;
F_15 ( V_6 ) ;
F_32 ( & V_6 -> V_63 , V_61 ) ;
return 0 ;
}
static int F_117 ( struct V_90 * V_91 )
{
struct V_92 * V_93 = F_60 ( V_91 ) ;
struct V_1 * V_6 = F_61 ( V_93 ) ;
T_2 V_11 = 0 , V_166 , V_167 , V_168 ;
unsigned long V_61 ;
int V_169 ;
F_31 ( & V_6 -> V_63 , V_61 ) ;
if ( V_6 -> V_152 && ! V_6 -> V_170 ) {
F_118 ( V_6 ) ;
if ( V_6 -> V_153 )
V_6 -> V_165 =
V_6 -> V_153 ( V_91 ) ;
}
F_13 ( V_6 ) ;
F_7 ( V_6 -> V_14 . V_42 ,
V_6 -> V_10 + V_6 -> V_12 -> V_42 ) ;
F_7 ( V_6 -> V_14 . V_40 ,
V_6 -> V_10 + V_6 -> V_12 -> V_40 ) ;
if ( V_6 -> V_152 ) {
if ( ! V_6 -> V_153 ) {
F_119 ( V_6 ) ;
} else {
V_169 = V_6 -> V_153 ( V_91 ) ;
if ( V_169 != V_6 -> V_165 ) {
F_119 ( V_6 ) ;
} else {
F_32 ( & V_6 -> V_63 , V_61 ) ;
return 0 ;
}
}
}
if ( ! V_6 -> V_164 ) {
F_32 ( & V_6 -> V_63 , V_61 ) ;
return 0 ;
}
V_11 = F_5 ( V_6 -> V_10 + V_6 -> V_12 -> V_22 ) ;
V_11 ^= V_6 -> V_163 ;
V_11 &= V_6 -> V_49 ;
V_167 = V_11 & V_6 -> V_14 . V_42 ;
V_167 &= V_6 -> V_163 ;
V_168 = V_11 & V_6 -> V_14 . V_40 ;
V_168 &= ~ ( V_6 -> V_163 ) ;
V_166 = V_11 & ( ~ ( V_6 -> V_14 . V_42 ) &
~ ( V_6 -> V_14 . V_40 ) ) ;
V_166 |= V_167 | V_168 ;
if ( V_166 ) {
T_2 V_171 , V_172 ;
V_171 = F_5 ( V_6 -> V_10 + V_6 -> V_12 -> V_36 ) ;
V_172 = F_5 ( V_6 -> V_10 + V_6 -> V_12 -> V_38 ) ;
if ( ! V_6 -> V_12 -> V_173 ) {
F_7 ( V_171 | V_166 , V_6 -> V_10 +
V_6 -> V_12 -> V_36 ) ;
F_7 ( V_172 | V_166 , V_6 -> V_10 +
V_6 -> V_12 -> V_38 ) ;
}
if ( V_6 -> V_12 -> V_173 ) {
F_7 ( V_171 | V_11 , V_6 -> V_10 +
V_6 -> V_12 -> V_36 ) ;
F_7 ( V_172 | V_11 , V_6 -> V_10 +
V_6 -> V_12 -> V_38 ) ;
}
F_7 ( V_171 , V_6 -> V_10 + V_6 -> V_12 -> V_36 ) ;
F_7 ( V_172 , V_6 -> V_10 + V_6 -> V_12 -> V_38 ) ;
}
V_6 -> V_164 = false ;
F_32 ( & V_6 -> V_63 , V_61 ) ;
return 0 ;
}
void F_120 ( int V_174 )
{
struct V_1 * V_6 ;
F_121 (bank, &omap_gpio_list, node) {
if ( ! F_25 ( V_6 ) || ! V_6 -> V_152 )
continue;
V_6 -> V_161 = V_174 ;
F_122 ( V_6 -> V_5 . V_76 ) ;
}
}
void F_123 ( void )
{
struct V_1 * V_6 ;
F_121 (bank, &omap_gpio_list, node) {
if ( ! F_25 ( V_6 ) || ! V_6 -> V_152 )
continue;
F_43 ( V_6 -> V_5 . V_76 ) ;
}
}
static void F_118 ( struct V_1 * V_175 )
{
struct V_176 * V_12 = V_175 -> V_12 ;
void T_1 * V_10 = V_175 -> V_10 ;
V_175 -> V_14 . V_56 = F_5 ( V_10 + V_12 -> V_56 ) ;
V_175 -> V_14 . V_15 = F_5 ( V_10 + V_12 -> V_13 ) ;
V_175 -> V_14 . V_46 = F_5 ( V_10 + V_12 -> V_45 ) ;
V_175 -> V_14 . V_36 = F_5 ( V_10 + V_12 -> V_36 ) ;
V_175 -> V_14 . V_38 = F_5 ( V_10 + V_12 -> V_38 ) ;
V_175 -> V_14 . V_40 = F_5 ( V_10 + V_12 -> V_40 ) ;
V_175 -> V_14 . V_42 = F_5 ( V_10 + V_12 -> V_42 ) ;
V_175 -> V_14 . V_73 = F_5 ( V_10 + V_12 -> V_70 ) ;
V_175 -> V_14 . V_177 = F_5 ( V_10 + V_12 -> V_177 ) ;
if ( V_12 -> V_18 && V_175 -> V_12 -> V_20 )
V_175 -> V_14 . V_19 = F_5 ( V_10 + V_12 -> V_18 ) ;
else
V_175 -> V_14 . V_19 = F_5 ( V_10 + V_12 -> V_19 ) ;
V_175 -> V_170 = true ;
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
F_7 ( V_6 -> V_14 . V_177 ,
V_6 -> V_10 + V_6 -> V_12 -> V_177 ) ;
}
static inline void F_118 ( struct V_1 * V_175 ) {}
static int T_4 F_124 ( void )
{
return F_65 ( & V_178 ) ;
}
static void T_5 F_125 ( void )
{
F_126 ( & V_178 ) ;
}
