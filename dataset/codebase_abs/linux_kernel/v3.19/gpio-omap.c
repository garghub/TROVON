static int F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
return V_2 -> V_4 . V_5 + V_3 ;
}
static inline struct V_1 * F_2 ( struct V_6 * V_7 )
{
struct V_8 * V_4 = F_3 ( V_7 ) ;
return F_4 ( V_4 , struct V_1 , V_4 ) ;
}
static void F_5 ( struct V_1 * V_2 , int V_9 ,
int V_10 )
{
void T_1 * V_11 = V_2 -> V_5 ;
T_2 V_12 ;
V_11 += V_2 -> V_13 -> V_14 ;
V_12 = F_6 ( V_11 ) ;
if ( V_10 )
V_12 |= F_7 ( V_9 ) ;
else
V_12 &= ~ ( F_7 ( V_9 ) ) ;
F_8 ( V_12 , V_11 ) ;
V_2 -> V_15 . V_16 = V_12 ;
}
static void F_9 ( struct V_1 * V_2 , int V_9 ,
int V_17 )
{
void T_1 * V_11 = V_2 -> V_5 ;
T_2 V_12 = F_10 ( V_2 , V_9 ) ;
if ( V_17 ) {
V_11 += V_2 -> V_13 -> V_18 ;
V_2 -> V_15 . V_19 |= V_12 ;
} else {
V_11 += V_2 -> V_13 -> V_20 ;
V_2 -> V_15 . V_19 &= ~ V_12 ;
}
F_8 ( V_12 , V_11 ) ;
}
static void F_11 ( struct V_1 * V_2 , int V_9 ,
int V_17 )
{
void T_1 * V_11 = V_2 -> V_5 + V_2 -> V_13 -> V_19 ;
T_2 V_21 = F_10 ( V_2 , V_9 ) ;
T_2 V_12 ;
V_12 = F_6 ( V_11 ) ;
if ( V_17 )
V_12 |= V_21 ;
else
V_12 &= ~ V_21 ;
F_8 ( V_12 , V_11 ) ;
V_2 -> V_15 . V_19 = V_12 ;
}
static int F_12 ( struct V_1 * V_2 , int V_22 )
{
void T_1 * V_11 = V_2 -> V_5 + V_2 -> V_13 -> V_23 ;
return ( F_6 ( V_11 ) & ( F_7 ( V_22 ) ) ) != 0 ;
}
static int F_13 ( struct V_1 * V_2 , int V_22 )
{
void T_1 * V_11 = V_2 -> V_5 + V_2 -> V_13 -> V_19 ;
return ( F_6 ( V_11 ) & ( F_7 ( V_22 ) ) ) != 0 ;
}
static inline void F_14 ( void T_1 * V_5 , T_2 V_11 , T_2 V_24 , bool V_25 )
{
int V_12 = F_6 ( V_5 + V_11 ) ;
if ( V_25 )
V_12 |= V_24 ;
else
V_12 &= ~ V_24 ;
F_8 ( V_12 , V_5 + V_11 ) ;
}
static inline void F_15 ( struct V_1 * V_2 )
{
if ( V_2 -> V_26 && ! V_2 -> V_27 ) {
F_16 ( V_2 -> V_28 ) ;
V_2 -> V_27 = true ;
F_8 ( V_2 -> V_26 ,
V_2 -> V_5 + V_2 -> V_13 -> V_29 ) ;
}
}
static inline void F_17 ( struct V_1 * V_2 )
{
if ( V_2 -> V_26 && V_2 -> V_27 ) {
F_8 ( 0 , V_2 -> V_5 + V_2 -> V_13 -> V_29 ) ;
F_18 ( V_2 -> V_28 ) ;
V_2 -> V_27 = false ;
}
}
static void F_19 ( struct V_1 * V_2 , unsigned V_9 ,
unsigned V_30 )
{
void T_1 * V_11 ;
T_2 V_31 ;
T_2 V_12 ;
if ( ! V_2 -> V_32 )
return;
if ( V_30 < 32 )
V_30 = 0x01 ;
else if ( V_30 > 7936 )
V_30 = 0xff ;
else
V_30 = ( V_30 / 0x1f ) - 1 ;
V_12 = F_10 ( V_2 , V_9 ) ;
F_16 ( V_2 -> V_28 ) ;
V_11 = V_2 -> V_5 + V_2 -> V_13 -> V_30 ;
F_8 ( V_30 , V_11 ) ;
V_11 = V_2 -> V_5 + V_2 -> V_13 -> V_29 ;
V_31 = F_6 ( V_11 ) ;
if ( V_30 )
V_31 |= V_12 ;
else
V_31 &= ~ V_12 ;
V_2 -> V_26 = V_31 ;
F_8 ( V_31 , V_11 ) ;
F_18 ( V_2 -> V_28 ) ;
F_15 ( V_2 ) ;
if ( V_2 -> V_26 ) {
V_2 -> V_15 . V_30 = V_30 ;
V_2 -> V_15 . V_29 = V_31 ;
}
}
static void F_20 ( struct V_1 * V_2 , unsigned V_9 )
{
T_2 V_21 = F_10 ( V_2 , V_9 ) ;
if ( ! V_2 -> V_32 )
return;
if ( ! ( V_2 -> V_26 & V_21 ) )
return;
V_2 -> V_26 &= ~ V_21 ;
V_2 -> V_15 . V_29 &= ~ V_21 ;
F_8 ( V_2 -> V_15 . V_29 ,
V_2 -> V_5 + V_2 -> V_13 -> V_29 ) ;
if ( ! V_2 -> V_26 ) {
V_2 -> V_15 . V_30 = 0 ;
F_8 ( V_2 -> V_15 . V_30 , V_2 -> V_5 +
V_2 -> V_13 -> V_30 ) ;
F_18 ( V_2 -> V_28 ) ;
V_2 -> V_27 = false ;
}
}
static inline void F_21 ( struct V_1 * V_2 , int V_9 ,
unsigned V_33 )
{
void T_1 * V_5 = V_2 -> V_5 ;
T_2 V_21 = F_7 ( V_9 ) ;
F_14 ( V_5 , V_2 -> V_13 -> V_34 , V_21 ,
V_33 & V_35 ) ;
F_14 ( V_5 , V_2 -> V_13 -> V_36 , V_21 ,
V_33 & V_37 ) ;
F_14 ( V_5 , V_2 -> V_13 -> V_38 , V_21 ,
V_33 & V_39 ) ;
F_14 ( V_5 , V_2 -> V_13 -> V_40 , V_21 ,
V_33 & V_41 ) ;
V_2 -> V_15 . V_34 =
F_6 ( V_2 -> V_5 + V_2 -> V_13 -> V_34 ) ;
V_2 -> V_15 . V_36 =
F_6 ( V_2 -> V_5 + V_2 -> V_13 -> V_36 ) ;
V_2 -> V_15 . V_38 =
F_6 ( V_2 -> V_5 + V_2 -> V_13 -> V_38 ) ;
V_2 -> V_15 . V_40 =
F_6 ( V_2 -> V_5 + V_2 -> V_13 -> V_40 ) ;
if ( F_22 ( ! ( V_2 -> V_42 & V_21 ) ) ) {
F_14 ( V_5 , V_2 -> V_13 -> V_43 , V_21 , V_33 != 0 ) ;
V_2 -> V_15 . V_44 =
F_6 ( V_2 -> V_5 + V_2 -> V_13 -> V_43 ) ;
}
if ( ! V_2 -> V_13 -> V_45 ) {
if ( V_2 -> V_42 ) {
if ( ! ( V_2 -> V_42 & V_21 ) )
goto exit;
}
if ( V_33 & V_46 )
V_2 -> V_47 |= V_21 ;
else
V_2 -> V_47 &= ~ V_21 ;
}
exit:
V_2 -> V_48 =
F_6 ( V_2 -> V_5 + V_2 -> V_13 -> V_34 ) |
F_6 ( V_2 -> V_5 + V_2 -> V_13 -> V_36 ) ;
}
static void F_23 ( struct V_1 * V_2 , int V_9 )
{
void T_1 * V_11 = V_2 -> V_5 ;
T_2 V_12 = 0 ;
if ( ! V_2 -> V_13 -> V_45 )
return;
V_11 += V_2 -> V_13 -> V_45 ;
V_12 = F_6 ( V_11 ) ;
if ( ( V_12 >> V_9 ) & 1 )
V_12 &= ~ ( F_7 ( V_9 ) ) ;
else
V_12 |= F_7 ( V_9 ) ;
F_8 ( V_12 , V_11 ) ;
}
static void F_23 ( struct V_1 * V_2 , int V_9 ) {}
static int F_24 ( struct V_1 * V_2 , int V_9 ,
unsigned V_33 )
{
void T_1 * V_11 = V_2 -> V_5 ;
void T_1 * V_5 = V_2 -> V_5 ;
T_2 V_12 = 0 ;
if ( V_2 -> V_13 -> V_34 && V_2 -> V_13 -> V_43 ) {
F_21 ( V_2 , V_9 , V_33 ) ;
} else if ( V_2 -> V_13 -> V_45 ) {
V_11 += V_2 -> V_13 -> V_45 ;
V_12 = F_6 ( V_11 ) ;
if ( ( V_33 & V_49 ) == V_46 )
V_2 -> V_50 |= F_7 ( V_9 ) ;
if ( V_33 & V_39 )
V_12 |= F_7 ( V_9 ) ;
else if ( V_33 & V_41 )
V_12 &= ~ ( F_7 ( V_9 ) ) ;
else
return - V_51 ;
F_8 ( V_12 , V_11 ) ;
} else if ( V_2 -> V_13 -> V_52 ) {
if ( V_9 & 0x08 )
V_11 += V_2 -> V_13 -> V_53 ;
else
V_11 += V_2 -> V_13 -> V_52 ;
V_9 &= 0x07 ;
V_12 = F_6 ( V_11 ) ;
V_12 &= ~ ( 3 << ( V_9 << 1 ) ) ;
if ( V_33 & V_39 )
V_12 |= 2 << ( V_9 << 1 ) ;
if ( V_33 & V_41 )
V_12 |= F_7 ( V_9 << 1 ) ;
F_14 ( V_5 , V_2 -> V_13 -> V_43 , F_7 ( V_9 ) , V_33 ) ;
V_2 -> V_15 . V_44 =
F_6 ( V_2 -> V_5 + V_2 -> V_13 -> V_43 ) ;
F_8 ( V_12 , V_11 ) ;
}
return 0 ;
}
static void F_25 ( struct V_1 * V_2 , unsigned V_22 )
{
if ( V_2 -> V_13 -> V_54 ) {
void T_1 * V_11 = V_2 -> V_5 + V_2 -> V_13 -> V_54 ;
F_8 ( F_6 ( V_11 ) | ( F_7 ( V_22 ) ) , V_11 ) ;
}
if ( V_2 -> V_13 -> V_55 && ! F_26 ( V_2 ) ) {
void T_1 * V_11 = V_2 -> V_5 + V_2 -> V_13 -> V_55 ;
T_2 V_55 ;
V_55 = F_6 ( V_11 ) ;
V_55 &= ~ V_56 ;
F_8 ( V_55 , V_11 ) ;
V_2 -> V_15 . V_55 = V_55 ;
}
}
static void F_27 ( struct V_1 * V_2 , unsigned V_22 )
{
void T_1 * V_5 = V_2 -> V_5 ;
if ( V_2 -> V_13 -> V_43 &&
! F_28 ( V_2 -> V_57 , V_22 ) &&
! F_28 ( V_2 -> V_58 , V_22 ) ) {
F_14 ( V_5 , V_2 -> V_13 -> V_43 , F_7 ( V_22 ) , 0 ) ;
V_2 -> V_15 . V_44 =
F_6 ( V_2 -> V_5 + V_2 -> V_13 -> V_43 ) ;
}
if ( V_2 -> V_13 -> V_55 && ! F_26 ( V_2 ) ) {
void T_1 * V_11 = V_2 -> V_5 + V_2 -> V_13 -> V_55 ;
T_2 V_55 ;
V_55 = F_6 ( V_11 ) ;
V_55 |= V_56 ;
F_8 ( V_55 , V_11 ) ;
V_2 -> V_15 . V_55 = V_55 ;
}
}
static int F_29 ( struct V_1 * V_2 , int V_24 )
{
void T_1 * V_11 = V_2 -> V_5 + V_2 -> V_13 -> V_14 ;
return F_6 ( V_11 ) & V_24 ;
}
static void F_30 ( struct V_1 * V_2 , unsigned V_9 ,
unsigned V_22 )
{
if ( ! F_28 ( V_2 -> V_57 , V_22 ) ) {
F_25 ( V_2 , V_22 ) ;
F_5 ( V_2 , V_22 , 1 ) ;
}
V_2 -> V_58 |= F_7 ( F_31 ( V_2 , V_9 ) ) ;
}
static int F_32 ( struct V_6 * V_7 , unsigned type )
{
struct V_1 * V_2 = F_2 ( V_7 ) ;
unsigned V_9 = 0 ;
int V_59 ;
unsigned long V_60 ;
unsigned V_22 ;
if ( ! F_26 ( V_2 ) )
F_33 ( V_2 -> V_61 ) ;
#ifdef F_34
if ( V_7 -> V_62 > V_63 )
V_9 = F_35 ( V_7 -> V_62 - V_63 ) ;
#endif
if ( ! V_9 )
V_9 = F_1 ( V_2 , V_7 -> V_64 ) ;
if ( type & ~ V_49 )
return - V_51 ;
if ( ! V_2 -> V_13 -> V_34 &&
( type & ( V_35 | V_37 ) ) )
return - V_51 ;
F_36 ( & V_2 -> V_65 , V_60 ) ;
V_22 = F_31 ( V_2 , V_9 ) ;
V_59 = F_24 ( V_2 , V_22 , type ) ;
F_30 ( V_2 , V_9 , V_22 ) ;
if ( ! F_29 ( V_2 , F_7 ( V_22 ) ) ) {
F_37 ( & V_2 -> V_65 , V_60 ) ;
return - V_51 ;
}
F_37 ( & V_2 -> V_65 , V_60 ) ;
if ( type & ( V_35 | V_37 ) )
F_38 ( V_7 -> V_62 , V_66 ) ;
else if ( type & ( V_41 | V_39 ) )
F_38 ( V_7 -> V_62 , V_67 ) ;
return V_59 ;
}
static void F_39 ( struct V_1 * V_2 , int V_68 )
{
void T_1 * V_11 = V_2 -> V_5 ;
V_11 += V_2 -> V_13 -> V_69 ;
F_8 ( V_68 , V_11 ) ;
if ( V_2 -> V_13 -> V_70 ) {
V_11 = V_2 -> V_5 + V_2 -> V_13 -> V_70 ;
F_8 ( V_68 , V_11 ) ;
}
F_6 ( V_11 ) ;
}
static inline void F_40 ( struct V_1 * V_2 , int V_9 )
{
F_39 ( V_2 , F_10 ( V_2 , V_9 ) ) ;
}
static T_2 F_41 ( struct V_1 * V_2 )
{
void T_1 * V_11 = V_2 -> V_5 ;
T_2 V_12 ;
T_2 V_24 = ( F_7 ( V_2 -> V_71 ) ) - 1 ;
V_11 += V_2 -> V_13 -> V_72 ;
V_12 = F_6 ( V_11 ) ;
if ( V_2 -> V_13 -> V_73 )
V_12 = ~ V_12 ;
V_12 &= V_24 ;
return V_12 ;
}
static void F_42 ( struct V_1 * V_2 , int V_68 )
{
void T_1 * V_11 = V_2 -> V_5 ;
T_2 V_12 ;
if ( V_2 -> V_13 -> V_74 ) {
V_11 += V_2 -> V_13 -> V_74 ;
V_12 = V_68 ;
V_2 -> V_15 . V_75 |= V_68 ;
} else {
V_11 += V_2 -> V_13 -> V_72 ;
V_12 = F_6 ( V_11 ) ;
if ( V_2 -> V_13 -> V_73 )
V_12 &= ~ V_68 ;
else
V_12 |= V_68 ;
V_2 -> V_15 . V_75 = V_12 ;
}
F_8 ( V_12 , V_11 ) ;
}
static void F_43 ( struct V_1 * V_2 , int V_68 )
{
void T_1 * V_11 = V_2 -> V_5 ;
T_2 V_12 ;
if ( V_2 -> V_13 -> V_76 ) {
V_11 += V_2 -> V_13 -> V_76 ;
V_12 = V_68 ;
V_2 -> V_15 . V_75 &= ~ V_68 ;
} else {
V_11 += V_2 -> V_13 -> V_72 ;
V_12 = F_6 ( V_11 ) ;
if ( V_2 -> V_13 -> V_73 )
V_12 |= V_68 ;
else
V_12 &= ~ V_68 ;
V_2 -> V_15 . V_75 = V_12 ;
}
F_8 ( V_12 , V_11 ) ;
}
static inline void F_44 ( struct V_1 * V_2 , int V_9 ,
int V_17 )
{
if ( V_17 )
F_42 ( V_2 , F_10 ( V_2 , V_9 ) ) ;
else
F_43 ( V_2 , F_10 ( V_2 , V_9 ) ) ;
}
static int F_45 ( struct V_1 * V_2 , int V_9 , int V_17 )
{
T_2 V_21 = F_10 ( V_2 , V_9 ) ;
unsigned long V_60 ;
if ( V_2 -> V_42 & V_21 ) {
F_46 ( V_2 -> V_61 ,
L_1 , V_9 ) ;
return - V_51 ;
}
F_36 ( & V_2 -> V_65 , V_60 ) ;
if ( V_17 )
V_2 -> V_15 . V_44 |= V_21 ;
else
V_2 -> V_15 . V_44 &= ~ V_21 ;
F_8 ( V_2 -> V_15 . V_44 , V_2 -> V_5 + V_2 -> V_13 -> V_43 ) ;
F_37 ( & V_2 -> V_65 , V_60 ) ;
return 0 ;
}
static void F_47 ( struct V_1 * V_2 , int V_9 )
{
F_5 ( V_2 , F_31 ( V_2 , V_9 ) , 1 ) ;
F_44 ( V_2 , V_9 , 0 ) ;
F_40 ( V_2 , V_9 ) ;
F_24 ( V_2 , F_31 ( V_2 , V_9 ) , V_77 ) ;
F_20 ( V_2 , V_9 ) ;
}
static int F_48 ( struct V_6 * V_7 , unsigned int V_17 )
{
struct V_1 * V_2 = F_2 ( V_7 ) ;
unsigned int V_9 = F_1 ( V_2 , V_7 -> V_64 ) ;
return F_45 ( V_2 , V_9 , V_17 ) ;
}
static int F_49 ( struct V_8 * V_4 , unsigned V_22 )
{
struct V_1 * V_2 = F_4 ( V_4 , struct V_1 , V_4 ) ;
unsigned long V_60 ;
if ( ! F_26 ( V_2 ) )
F_33 ( V_2 -> V_61 ) ;
F_36 ( & V_2 -> V_65 , V_60 ) ;
if ( ! F_28 ( V_2 -> V_58 , V_22 ) ) {
F_24 ( V_2 , V_22 , V_77 ) ;
F_25 ( V_2 , V_22 ) ;
}
V_2 -> V_57 |= F_7 ( V_22 ) ;
F_37 ( & V_2 -> V_65 , V_60 ) ;
return 0 ;
}
static void F_50 ( struct V_8 * V_4 , unsigned V_22 )
{
struct V_1 * V_2 = F_4 ( V_4 , struct V_1 , V_4 ) ;
unsigned long V_60 ;
F_36 ( & V_2 -> V_65 , V_60 ) ;
V_2 -> V_57 &= ~ ( F_7 ( V_22 ) ) ;
F_27 ( V_2 , V_22 ) ;
F_47 ( V_2 , V_2 -> V_4 . V_5 + V_22 ) ;
F_37 ( & V_2 -> V_65 , V_60 ) ;
if ( ! F_26 ( V_2 ) )
F_51 ( V_2 -> V_61 ) ;
}
static void F_52 ( unsigned int V_62 , struct V_78 * V_79 )
{
void T_1 * V_80 = NULL ;
T_2 V_81 ;
unsigned int V_82 ;
struct V_1 * V_2 ;
int V_83 = 0 ;
struct V_84 * V_85 = F_53 ( V_79 ) ;
struct V_8 * V_4 = F_54 ( V_62 ) ;
F_55 ( V_85 , V_79 ) ;
V_2 = F_4 ( V_4 , struct V_1 , V_4 ) ;
V_80 = V_2 -> V_5 + V_2 -> V_13 -> V_69 ;
F_33 ( V_2 -> V_61 ) ;
if ( F_56 ( ! V_80 ) )
goto exit;
while ( 1 ) {
T_2 V_86 , V_48 = 0 ;
T_2 V_87 ;
V_87 = F_41 ( V_2 ) ;
V_86 = V_81 = F_6 ( V_80 ) & V_87 ;
if ( V_2 -> V_48 )
V_48 = V_2 -> V_48 & V_87 ;
F_43 ( V_2 , V_86 & ~ V_48 ) ;
F_39 ( V_2 , V_86 & ~ V_48 ) ;
F_42 ( V_2 , V_86 & ~ V_48 ) ;
if ( ! V_48 && ! V_83 ) {
V_83 = 1 ;
F_57 ( V_85 , V_79 ) ;
}
if ( ! V_81 )
break;
while ( V_81 ) {
V_82 = F_58 ( V_81 ) ;
V_81 &= ~ ( F_7 ( V_82 ) ) ;
if ( V_2 -> V_50 & ( F_7 ( V_82 ) ) )
F_23 ( V_2 , V_82 ) ;
F_59 ( F_60 ( V_2 -> V_4 . V_88 ,
V_82 ) ) ;
}
}
exit:
if ( ! V_83 )
F_57 ( V_85 , V_79 ) ;
F_51 ( V_2 -> V_61 ) ;
}
static unsigned int F_61 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_2 ( V_7 ) ;
unsigned int V_9 = F_1 ( V_2 , V_7 -> V_64 ) ;
unsigned long V_60 ;
unsigned V_22 = F_31 ( V_2 , V_9 ) ;
if ( ! F_26 ( V_2 ) )
F_33 ( V_2 -> V_61 ) ;
F_36 ( & V_2 -> V_65 , V_60 ) ;
F_30 ( V_2 , V_9 , V_22 ) ;
F_37 ( & V_2 -> V_65 , V_60 ) ;
F_62 ( V_7 ) ;
return 0 ;
}
static void F_63 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_2 ( V_7 ) ;
unsigned int V_9 = F_1 ( V_2 , V_7 -> V_64 ) ;
unsigned long V_60 ;
unsigned V_22 = F_31 ( V_2 , V_9 ) ;
F_36 ( & V_2 -> V_65 , V_60 ) ;
F_64 ( & V_2 -> V_4 , V_22 ) ;
V_2 -> V_58 &= ~ ( F_7 ( V_22 ) ) ;
F_27 ( V_2 , V_22 ) ;
F_47 ( V_2 , V_9 ) ;
F_37 ( & V_2 -> V_65 , V_60 ) ;
if ( ! F_26 ( V_2 ) )
F_51 ( V_2 -> V_61 ) ;
}
static void F_65 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_2 ( V_7 ) ;
unsigned int V_9 = F_1 ( V_2 , V_7 -> V_64 ) ;
F_40 ( V_2 , V_9 ) ;
}
static void F_66 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_2 ( V_7 ) ;
unsigned int V_9 = F_1 ( V_2 , V_7 -> V_64 ) ;
unsigned long V_60 ;
F_36 ( & V_2 -> V_65 , V_60 ) ;
F_44 ( V_2 , V_9 , 0 ) ;
F_24 ( V_2 , F_31 ( V_2 , V_9 ) , V_77 ) ;
F_37 ( & V_2 -> V_65 , V_60 ) ;
}
static void F_62 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_2 ( V_7 ) ;
unsigned int V_9 = F_1 ( V_2 , V_7 -> V_64 ) ;
unsigned int V_89 = F_10 ( V_2 , V_9 ) ;
T_2 V_33 = F_67 ( V_7 ) ;
unsigned long V_60 ;
F_36 ( & V_2 -> V_65 , V_60 ) ;
if ( V_33 )
F_24 ( V_2 , F_31 ( V_2 , V_9 ) , V_33 ) ;
if ( V_2 -> V_48 & V_89 ) {
F_44 ( V_2 , V_9 , 0 ) ;
F_40 ( V_2 , V_9 ) ;
}
F_44 ( V_2 , V_9 , 1 ) ;
F_37 ( & V_2 -> V_65 , V_60 ) ;
}
static int F_68 ( struct V_90 * V_61 )
{
struct V_91 * V_92 = F_69 ( V_61 ) ;
struct V_1 * V_2 = F_70 ( V_92 ) ;
void T_1 * V_93 = V_2 -> V_5 +
V_94 / V_2 -> V_95 ;
unsigned long V_60 ;
F_36 ( & V_2 -> V_65 , V_60 ) ;
F_8 ( 0xffff & ~ V_2 -> V_15 . V_44 , V_93 ) ;
F_37 ( & V_2 -> V_65 , V_60 ) ;
return 0 ;
}
static int F_71 ( struct V_90 * V_61 )
{
struct V_91 * V_92 = F_69 ( V_61 ) ;
struct V_1 * V_2 = F_70 ( V_92 ) ;
void T_1 * V_93 = V_2 -> V_5 +
V_94 / V_2 -> V_95 ;
unsigned long V_60 ;
F_36 ( & V_2 -> V_65 , V_60 ) ;
F_8 ( V_2 -> V_15 . V_44 , V_93 ) ;
F_37 ( & V_2 -> V_65 , V_60 ) ;
return 0 ;
}
static inline void F_72 ( struct V_1 * V_2 )
{
F_73 ( & V_96 , V_2 ) ;
if ( F_74 ( & V_97 ) == 0 )
( void ) F_75 ( & V_96 ) ;
}
static int F_76 ( struct V_8 * V_4 , unsigned V_22 )
{
struct V_1 * V_2 ;
unsigned long V_60 ;
void T_1 * V_11 ;
int V_98 ;
V_2 = F_4 ( V_4 , struct V_1 , V_4 ) ;
V_11 = V_2 -> V_5 + V_2 -> V_13 -> V_14 ;
F_36 ( & V_2 -> V_65 , V_60 ) ;
V_98 = ! ! ( F_6 ( V_11 ) & F_7 ( V_22 ) ) ;
F_37 ( & V_2 -> V_65 , V_60 ) ;
return V_98 ;
}
static int F_77 ( struct V_8 * V_4 , unsigned V_22 )
{
struct V_1 * V_2 ;
unsigned long V_60 ;
V_2 = F_4 ( V_4 , struct V_1 , V_4 ) ;
F_36 ( & V_2 -> V_65 , V_60 ) ;
F_5 ( V_2 , V_22 , 1 ) ;
F_37 ( & V_2 -> V_65 , V_60 ) ;
return 0 ;
}
static int F_78 ( struct V_8 * V_4 , unsigned V_22 )
{
struct V_1 * V_2 ;
T_2 V_24 ;
V_2 = F_4 ( V_4 , struct V_1 , V_4 ) ;
V_24 = ( F_7 ( V_22 ) ) ;
if ( F_29 ( V_2 , V_24 ) )
return F_12 ( V_2 , V_22 ) ;
else
return F_13 ( V_2 , V_22 ) ;
}
static int F_79 ( struct V_8 * V_4 , unsigned V_22 , int V_99 )
{
struct V_1 * V_2 ;
unsigned long V_60 ;
V_2 = F_4 ( V_4 , struct V_1 , V_4 ) ;
F_36 ( & V_2 -> V_65 , V_60 ) ;
V_2 -> V_18 ( V_2 , V_22 , V_99 ) ;
F_5 ( V_2 , V_22 , 0 ) ;
F_37 ( & V_2 -> V_65 , V_60 ) ;
return 0 ;
}
static int F_80 ( struct V_8 * V_4 , unsigned V_22 ,
unsigned V_30 )
{
struct V_1 * V_2 ;
unsigned long V_60 ;
V_2 = F_4 ( V_4 , struct V_1 , V_4 ) ;
F_36 ( & V_2 -> V_65 , V_60 ) ;
F_19 ( V_2 , V_22 , V_30 ) ;
F_37 ( & V_2 -> V_65 , V_60 ) ;
return 0 ;
}
static void F_81 ( struct V_8 * V_4 , unsigned V_22 , int V_99 )
{
struct V_1 * V_2 ;
unsigned long V_60 ;
V_2 = F_4 ( V_4 , struct V_1 , V_4 ) ;
F_36 ( & V_2 -> V_65 , V_60 ) ;
V_2 -> V_18 ( V_2 , V_22 , V_99 ) ;
F_37 ( & V_2 -> V_65 , V_60 ) ;
}
static void T_3 F_82 ( struct V_1 * V_2 )
{
static bool V_100 ;
T_2 V_101 ;
if ( V_100 || V_2 -> V_13 -> V_102 == V_103 )
return;
V_101 = F_83 ( V_2 -> V_5 + V_2 -> V_13 -> V_102 ) ;
F_84 ( L_2 ,
( V_101 >> 4 ) & 0x0f , V_101 & 0x0f ) ;
V_100 = true ;
}
static void F_85 ( struct V_1 * V_2 )
{
void T_1 * V_5 = V_2 -> V_5 ;
T_2 V_12 = 0xffffffff ;
if ( V_2 -> V_71 == 16 )
V_12 = 0xffff ;
if ( V_2 -> V_104 ) {
F_8 ( V_12 , V_2 -> V_5 + V_2 -> V_13 -> V_72 ) ;
return;
}
F_14 ( V_5 , V_2 -> V_13 -> V_72 , V_12 ,
V_2 -> V_13 -> V_73 ) ;
F_14 ( V_5 , V_2 -> V_13 -> V_69 , V_12 ,
! V_2 -> V_13 -> V_73 ) ;
if ( V_2 -> V_13 -> V_29 )
F_8 ( 0 , V_5 + V_2 -> V_13 -> V_29 ) ;
V_2 -> V_15 . V_16 = F_6 ( V_2 -> V_5 + V_2 -> V_13 -> V_14 ) ;
if ( V_2 -> V_13 -> V_55 )
F_8 ( 0 , V_5 + V_2 -> V_13 -> V_55 ) ;
V_2 -> V_28 = F_86 ( V_2 -> V_61 , L_3 ) ;
if ( F_87 ( V_2 -> V_28 ) )
F_46 ( V_2 -> V_61 , L_4 ) ;
}
static void
F_88 ( struct V_1 * V_2 , unsigned int V_105 ,
unsigned int V_106 )
{
struct V_107 * V_108 ;
struct V_109 * V_110 ;
V_108 = F_89 ( L_5 , 1 , V_105 , V_2 -> V_5 ,
V_111 ) ;
if ( ! V_108 ) {
F_46 ( V_2 -> V_61 , L_6 ) ;
return;
}
V_110 = V_108 -> V_112 ;
V_110 -> V_4 . V_89 = V_113 ;
V_110 -> V_4 . V_114 = V_115 ;
V_110 -> V_4 . V_116 = F_32 ;
if ( V_2 -> V_13 -> V_43 )
V_110 -> V_4 . V_117 = F_48 ;
V_110 -> V_13 . V_24 = V_118 / V_2 -> V_95 ;
F_90 ( V_108 , F_91 ( V_106 ) , V_119 ,
V_120 | V_121 , 0 ) ;
}
static int F_92 ( struct V_1 * V_2 , struct V_84 * V_122 )
{
int V_123 ;
static int V_9 ;
int V_124 = 0 ;
int V_125 ;
V_2 -> V_4 . V_126 = F_49 ;
V_2 -> V_4 . free = F_50 ;
V_2 -> V_4 . V_127 = F_76 ;
V_2 -> V_4 . V_128 = F_77 ;
V_2 -> V_4 . V_129 = F_78 ;
V_2 -> V_4 . V_130 = F_79 ;
V_2 -> V_4 . V_131 = F_80 ;
V_2 -> V_4 . V_25 = F_81 ;
if ( V_2 -> V_104 ) {
V_2 -> V_4 . V_132 = L_7 ;
if ( V_2 -> V_13 -> V_43 )
V_2 -> V_4 . V_61 = & V_96 . V_61 ;
V_2 -> V_4 . V_5 = F_35 ( 0 ) ;
} else {
V_2 -> V_4 . V_132 = L_8 ;
V_2 -> V_4 . V_5 = V_9 ;
V_9 += V_2 -> V_71 ;
}
V_2 -> V_4 . V_133 = V_2 -> V_71 ;
V_125 = F_93 ( & V_2 -> V_4 ) ;
if ( V_125 ) {
F_46 ( V_2 -> V_61 , L_9 , V_125 ) ;
return V_125 ;
}
#ifdef F_34
V_124 = F_94 ( - 1 , 0 , V_2 -> V_71 , 0 ) ;
if ( V_124 < 0 ) {
F_46 ( V_2 -> V_61 , L_10 ) ;
return - V_134 ;
}
#endif
V_125 = F_95 ( & V_2 -> V_4 , V_122 ,
V_124 , F_52 ,
V_77 ) ;
if ( V_125 ) {
F_46 ( V_2 -> V_61 , L_11 , V_125 ) ;
F_96 ( & V_2 -> V_4 ) ;
return - V_134 ;
}
F_97 ( & V_2 -> V_4 , V_122 ,
V_2 -> V_62 , F_52 ) ;
for ( V_123 = 0 ; V_123 < V_2 -> V_71 ; V_123 ++ ) {
int V_62 = F_60 ( V_2 -> V_4 . V_88 , V_123 ) ;
if ( V_2 -> V_104 ) {
F_88 ( V_2 , V_62 , V_2 -> V_71 ) ;
F_98 ( V_62 , NULL , NULL ) ;
F_99 ( V_62 , 0 ) ;
}
}
return 0 ;
}
static int F_100 ( struct V_91 * V_92 )
{
struct V_90 * V_61 = & V_92 -> V_61 ;
struct V_135 * V_136 = V_61 -> V_137 ;
const struct V_138 * V_139 ;
const struct V_140 * V_141 ;
struct V_142 * V_143 ;
struct V_1 * V_2 ;
struct V_84 * V_122 ;
int V_125 ;
V_139 = F_101 ( F_102 ( V_144 ) , V_61 ) ;
V_141 = V_139 ? V_139 -> V_145 : F_103 ( V_61 ) ;
if ( ! V_141 )
return - V_51 ;
V_2 = F_104 ( V_61 , sizeof( struct V_1 ) , V_146 ) ;
if ( ! V_2 ) {
F_46 ( V_61 , L_12 ) ;
return - V_147 ;
}
V_122 = F_104 ( V_61 , sizeof( * V_122 ) , V_146 ) ;
if ( ! V_122 )
return - V_147 ;
V_122 -> V_148 = F_61 ,
V_122 -> V_149 = F_63 ,
V_122 -> V_150 = F_65 ,
V_122 -> V_89 = F_66 ,
V_122 -> V_114 = F_62 ,
V_122 -> V_116 = F_32 ,
V_122 -> V_117 = F_48 ,
V_122 -> V_151 = F_105 ( & V_92 -> V_61 ) ;
V_143 = F_106 ( V_92 , V_152 , 0 ) ;
if ( F_107 ( ! V_143 ) ) {
F_46 ( V_61 , L_13 ) ;
return - V_134 ;
}
V_2 -> V_62 = V_143 -> V_153 ;
V_2 -> V_61 = V_61 ;
V_2 -> V_4 . V_61 = V_61 ;
V_2 -> V_32 = V_141 -> V_32 ;
V_2 -> V_95 = V_141 -> V_154 ;
V_2 -> V_71 = V_141 -> V_155 ;
V_2 -> V_104 = V_141 -> V_104 ;
V_2 -> V_42 = V_141 -> V_42 ;
V_2 -> V_13 = V_141 -> V_13 ;
#ifdef F_108
V_2 -> V_4 . V_137 = F_109 ( V_136 ) ;
#endif
if ( V_136 ) {
if ( ! F_110 ( V_136 , L_14 ) )
V_2 -> V_156 = true ;
} else {
V_2 -> V_156 = V_141 -> V_156 ;
if ( V_2 -> V_156 )
V_2 -> V_157 =
V_141 -> V_157 ;
}
if ( V_2 -> V_13 -> V_18 && V_2 -> V_13 -> V_20 )
V_2 -> V_18 = F_9 ;
else
V_2 -> V_18 = F_11 ;
F_111 ( & V_2 -> V_65 ) ;
V_143 = F_106 ( V_92 , V_158 , 0 ) ;
V_2 -> V_5 = F_112 ( V_61 , V_143 ) ;
if ( F_87 ( V_2 -> V_5 ) ) {
F_113 ( V_2 -> V_4 . V_88 ) ;
return F_114 ( V_2 -> V_5 ) ;
}
F_73 ( V_92 , V_2 ) ;
F_115 ( V_2 -> V_61 ) ;
F_116 ( V_2 -> V_61 ) ;
F_33 ( V_2 -> V_61 ) ;
if ( V_2 -> V_104 )
F_72 ( V_2 ) ;
F_85 ( V_2 ) ;
V_125 = F_92 ( V_2 , V_122 ) ;
if ( V_125 )
return V_125 ;
F_82 ( V_2 ) ;
F_51 ( V_2 -> V_61 ) ;
F_117 ( & V_2 -> V_136 , & V_159 ) ;
return 0 ;
}
static int F_118 ( struct V_90 * V_61 )
{
struct V_91 * V_92 = F_69 ( V_61 ) ;
struct V_1 * V_2 = F_70 ( V_92 ) ;
T_2 V_160 = 0 , V_161 = 0 ;
unsigned long V_60 ;
T_2 V_162 , V_163 ;
F_36 ( & V_2 -> V_65 , V_60 ) ;
V_162 = V_2 -> V_15 . V_34 & V_2 -> V_15 . V_44 ;
if ( V_162 )
F_8 ( V_162 | V_2 -> V_15 . V_40 ,
V_2 -> V_5 + V_2 -> V_13 -> V_40 ) ;
V_163 = V_2 -> V_15 . V_36 & V_2 -> V_15 . V_44 ;
if ( V_163 )
F_8 ( V_163 | V_2 -> V_15 . V_38 ,
V_2 -> V_5 + V_2 -> V_13 -> V_38 ) ;
if ( ! V_2 -> V_47 )
goto V_164;
if ( V_2 -> V_165 != V_166 ) {
V_2 -> V_165 = 0 ;
goto V_164;
}
V_2 -> V_167 = F_6 ( V_2 -> V_5 +
V_2 -> V_13 -> V_23 ) ;
V_160 = V_2 -> V_15 . V_40 ;
V_161 = V_2 -> V_15 . V_38 ;
V_160 &= ~ V_2 -> V_47 ;
V_161 &= ~ V_2 -> V_47 ;
F_8 ( V_160 , V_2 -> V_5 + V_2 -> V_13 -> V_40 ) ;
F_8 ( V_161 , V_2 -> V_5 + V_2 -> V_13 -> V_38 ) ;
V_2 -> V_168 = true ;
V_164:
if ( V_2 -> V_157 )
V_2 -> V_169 =
V_2 -> V_157 ( V_2 -> V_61 ) ;
F_17 ( V_2 ) ;
F_37 ( & V_2 -> V_65 , V_60 ) ;
return 0 ;
}
static int F_119 ( struct V_90 * V_61 )
{
struct V_91 * V_92 = F_69 ( V_61 ) ;
struct V_1 * V_2 = F_70 ( V_92 ) ;
T_2 V_12 = 0 , V_170 , V_171 , V_172 ;
unsigned long V_60 ;
int V_173 ;
F_36 ( & V_2 -> V_65 , V_60 ) ;
if ( V_2 -> V_156 && ! V_2 -> V_174 ) {
F_120 ( V_2 ) ;
if ( V_2 -> V_157 )
V_2 -> V_169 =
V_2 -> V_157 ( V_2 -> V_61 ) ;
}
F_15 ( V_2 ) ;
F_8 ( V_2 -> V_15 . V_40 ,
V_2 -> V_5 + V_2 -> V_13 -> V_40 ) ;
F_8 ( V_2 -> V_15 . V_38 ,
V_2 -> V_5 + V_2 -> V_13 -> V_38 ) ;
if ( V_2 -> V_156 ) {
if ( ! V_2 -> V_157 ) {
F_121 ( V_2 ) ;
} else {
V_173 = V_2 -> V_157 ( V_2 -> V_61 ) ;
if ( V_173 != V_2 -> V_169 ) {
F_121 ( V_2 ) ;
} else {
F_37 ( & V_2 -> V_65 , V_60 ) ;
return 0 ;
}
}
}
if ( ! V_2 -> V_168 ) {
F_37 ( & V_2 -> V_65 , V_60 ) ;
return 0 ;
}
V_12 = F_6 ( V_2 -> V_5 + V_2 -> V_13 -> V_23 ) ;
V_12 ^= V_2 -> V_167 ;
V_12 &= V_2 -> V_47 ;
V_171 = V_12 & V_2 -> V_15 . V_40 ;
V_171 &= V_2 -> V_167 ;
V_172 = V_12 & V_2 -> V_15 . V_38 ;
V_172 &= ~ ( V_2 -> V_167 ) ;
V_170 = V_12 & ( ~ ( V_2 -> V_15 . V_40 ) &
~ ( V_2 -> V_15 . V_38 ) ) ;
V_170 |= V_171 | V_172 ;
if ( V_170 ) {
T_2 V_175 , V_176 ;
V_175 = F_6 ( V_2 -> V_5 + V_2 -> V_13 -> V_34 ) ;
V_176 = F_6 ( V_2 -> V_5 + V_2 -> V_13 -> V_36 ) ;
if ( ! V_2 -> V_13 -> V_177 ) {
F_8 ( V_175 | V_170 , V_2 -> V_5 +
V_2 -> V_13 -> V_34 ) ;
F_8 ( V_176 | V_170 , V_2 -> V_5 +
V_2 -> V_13 -> V_36 ) ;
}
if ( V_2 -> V_13 -> V_177 ) {
F_8 ( V_175 | V_12 , V_2 -> V_5 +
V_2 -> V_13 -> V_34 ) ;
F_8 ( V_176 | V_12 , V_2 -> V_5 +
V_2 -> V_13 -> V_36 ) ;
}
F_8 ( V_175 , V_2 -> V_5 + V_2 -> V_13 -> V_34 ) ;
F_8 ( V_176 , V_2 -> V_5 + V_2 -> V_13 -> V_36 ) ;
}
V_2 -> V_168 = false ;
F_37 ( & V_2 -> V_65 , V_60 ) ;
return 0 ;
}
void F_122 ( int V_178 )
{
struct V_1 * V_2 ;
F_123 (bank, &omap_gpio_list, node) {
if ( ! F_26 ( V_2 ) || ! V_2 -> V_156 )
continue;
V_2 -> V_165 = V_178 ;
F_124 ( V_2 -> V_61 ) ;
}
}
void F_125 ( void )
{
struct V_1 * V_2 ;
F_123 (bank, &omap_gpio_list, node) {
if ( ! F_26 ( V_2 ) || ! V_2 -> V_156 )
continue;
F_33 ( V_2 -> V_61 ) ;
}
}
static void F_120 ( struct V_1 * V_179 )
{
struct V_180 * V_13 = V_179 -> V_13 ;
void T_1 * V_5 = V_179 -> V_5 ;
V_179 -> V_15 . V_55 = F_6 ( V_5 + V_13 -> V_55 ) ;
V_179 -> V_15 . V_16 = F_6 ( V_5 + V_13 -> V_14 ) ;
V_179 -> V_15 . V_44 = F_6 ( V_5 + V_13 -> V_43 ) ;
V_179 -> V_15 . V_34 = F_6 ( V_5 + V_13 -> V_34 ) ;
V_179 -> V_15 . V_36 = F_6 ( V_5 + V_13 -> V_36 ) ;
V_179 -> V_15 . V_38 = F_6 ( V_5 + V_13 -> V_38 ) ;
V_179 -> V_15 . V_40 = F_6 ( V_5 + V_13 -> V_40 ) ;
V_179 -> V_15 . V_75 = F_6 ( V_5 + V_13 -> V_72 ) ;
V_179 -> V_15 . V_181 = F_6 ( V_5 + V_13 -> V_181 ) ;
if ( V_13 -> V_18 && V_179 -> V_13 -> V_20 )
V_179 -> V_15 . V_19 = F_6 ( V_5 + V_13 -> V_18 ) ;
else
V_179 -> V_15 . V_19 = F_6 ( V_5 + V_13 -> V_19 ) ;
V_179 -> V_174 = true ;
}
static void F_121 ( struct V_1 * V_2 )
{
F_8 ( V_2 -> V_15 . V_44 ,
V_2 -> V_5 + V_2 -> V_13 -> V_43 ) ;
F_8 ( V_2 -> V_15 . V_55 , V_2 -> V_5 + V_2 -> V_13 -> V_55 ) ;
F_8 ( V_2 -> V_15 . V_34 ,
V_2 -> V_5 + V_2 -> V_13 -> V_34 ) ;
F_8 ( V_2 -> V_15 . V_36 ,
V_2 -> V_5 + V_2 -> V_13 -> V_36 ) ;
F_8 ( V_2 -> V_15 . V_38 ,
V_2 -> V_5 + V_2 -> V_13 -> V_38 ) ;
F_8 ( V_2 -> V_15 . V_40 ,
V_2 -> V_5 + V_2 -> V_13 -> V_40 ) ;
if ( V_2 -> V_13 -> V_18 && V_2 -> V_13 -> V_20 )
F_8 ( V_2 -> V_15 . V_19 ,
V_2 -> V_5 + V_2 -> V_13 -> V_18 ) ;
else
F_8 ( V_2 -> V_15 . V_19 ,
V_2 -> V_5 + V_2 -> V_13 -> V_19 ) ;
F_8 ( V_2 -> V_15 . V_16 , V_2 -> V_5 + V_2 -> V_13 -> V_14 ) ;
if ( V_2 -> V_26 ) {
F_8 ( V_2 -> V_15 . V_30 , V_2 -> V_5 +
V_2 -> V_13 -> V_30 ) ;
F_8 ( V_2 -> V_15 . V_29 ,
V_2 -> V_5 + V_2 -> V_13 -> V_29 ) ;
}
F_8 ( V_2 -> V_15 . V_75 ,
V_2 -> V_5 + V_2 -> V_13 -> V_72 ) ;
F_8 ( V_2 -> V_15 . V_181 ,
V_2 -> V_5 + V_2 -> V_13 -> V_181 ) ;
}
static inline void F_120 ( struct V_1 * V_179 ) {}
static int T_3 F_126 ( void )
{
return F_74 ( & V_182 ) ;
}
