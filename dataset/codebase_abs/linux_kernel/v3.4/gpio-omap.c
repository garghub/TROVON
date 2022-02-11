static int F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
return V_3 - V_2 -> V_4 + V_2 -> V_5 . V_6 ;
}
static void F_2 ( struct V_1 * V_2 , int V_7 , int V_8 )
{
void T_1 * V_9 = V_2 -> V_6 ;
T_2 V_10 ;
V_9 += V_2 -> V_11 -> V_12 ;
V_10 = F_3 ( V_9 ) ;
if ( V_8 )
V_10 |= 1 << V_7 ;
else
V_10 &= ~ ( 1 << V_7 ) ;
F_4 ( V_10 , V_9 ) ;
V_2 -> V_13 . V_14 = V_10 ;
}
static void F_5 ( struct V_1 * V_2 , int V_7 , int V_15 )
{
void T_1 * V_9 = V_2 -> V_6 ;
T_2 V_10 = F_6 ( V_2 , V_7 ) ;
if ( V_15 ) {
V_9 += V_2 -> V_11 -> V_16 ;
V_2 -> V_13 . V_17 |= V_10 ;
} else {
V_9 += V_2 -> V_11 -> V_18 ;
V_2 -> V_13 . V_17 &= ~ V_10 ;
}
F_4 ( V_10 , V_9 ) ;
}
static void F_7 ( struct V_1 * V_2 , int V_7 , int V_15 )
{
void T_1 * V_9 = V_2 -> V_6 + V_2 -> V_11 -> V_17 ;
T_2 V_19 = F_6 ( V_2 , V_7 ) ;
T_2 V_10 ;
V_10 = F_3 ( V_9 ) ;
if ( V_15 )
V_10 |= V_19 ;
else
V_10 &= ~ V_19 ;
F_4 ( V_10 , V_9 ) ;
V_2 -> V_13 . V_17 = V_10 ;
}
static int F_8 ( struct V_1 * V_2 , int V_20 )
{
void T_1 * V_9 = V_2 -> V_6 + V_2 -> V_11 -> V_21 ;
return ( F_3 ( V_9 ) & ( 1 << V_20 ) ) != 0 ;
}
static int F_9 ( struct V_1 * V_2 , int V_20 )
{
void T_1 * V_9 = V_2 -> V_6 + V_2 -> V_11 -> V_17 ;
return ( F_3 ( V_9 ) & ( 1 << V_20 ) ) != 0 ;
}
static inline void F_10 ( void T_1 * V_6 , T_2 V_9 , T_2 V_22 , bool V_23 )
{
int V_10 = F_3 ( V_6 + V_9 ) ;
if ( V_23 )
V_10 |= V_22 ;
else
V_10 &= ~ V_22 ;
F_4 ( V_10 , V_6 + V_9 ) ;
}
static inline void F_11 ( struct V_1 * V_2 )
{
if ( V_2 -> V_24 && ! V_2 -> V_25 ) {
F_12 ( V_2 -> V_26 ) ;
V_2 -> V_25 = true ;
}
}
static inline void F_13 ( struct V_1 * V_2 )
{
if ( V_2 -> V_24 && V_2 -> V_25 ) {
F_14 ( V_2 -> V_26 ) ;
V_2 -> V_25 = false ;
}
}
static void F_15 ( struct V_1 * V_2 , unsigned V_7 ,
unsigned V_27 )
{
void T_1 * V_9 ;
T_2 V_28 ;
T_2 V_10 ;
if ( ! V_2 -> V_29 )
return;
if ( V_27 < 32 )
V_27 = 0x01 ;
else if ( V_27 > 7936 )
V_27 = 0xff ;
else
V_27 = ( V_27 / 0x1f ) - 1 ;
V_10 = F_6 ( V_2 , V_7 ) ;
F_12 ( V_2 -> V_26 ) ;
V_9 = V_2 -> V_6 + V_2 -> V_11 -> V_27 ;
F_4 ( V_27 , V_9 ) ;
V_9 = V_2 -> V_6 + V_2 -> V_11 -> V_30 ;
V_28 = F_3 ( V_9 ) ;
if ( V_27 )
V_28 |= V_10 ;
else
V_28 &= ~ V_10 ;
V_2 -> V_24 = V_28 ;
F_4 ( V_28 , V_9 ) ;
F_14 ( V_2 -> V_26 ) ;
F_11 ( V_2 ) ;
if ( V_2 -> V_24 ) {
V_2 -> V_13 . V_27 = V_27 ;
V_2 -> V_13 . V_30 = V_28 ;
}
}
static inline void F_16 ( struct V_1 * V_2 , int V_7 ,
unsigned V_31 )
{
void T_1 * V_6 = V_2 -> V_6 ;
T_2 V_19 = 1 << V_7 ;
F_10 ( V_6 , V_2 -> V_11 -> V_32 , V_19 ,
V_31 & V_33 ) ;
F_10 ( V_6 , V_2 -> V_11 -> V_34 , V_19 ,
V_31 & V_35 ) ;
F_10 ( V_6 , V_2 -> V_11 -> V_36 , V_19 ,
V_31 & V_37 ) ;
F_10 ( V_6 , V_2 -> V_11 -> V_38 , V_19 ,
V_31 & V_39 ) ;
V_2 -> V_13 . V_32 =
F_3 ( V_2 -> V_6 + V_2 -> V_11 -> V_32 ) ;
V_2 -> V_13 . V_34 =
F_3 ( V_2 -> V_6 + V_2 -> V_11 -> V_34 ) ;
V_2 -> V_13 . V_36 =
F_3 ( V_2 -> V_6 + V_2 -> V_11 -> V_36 ) ;
V_2 -> V_13 . V_38 =
F_3 ( V_2 -> V_6 + V_2 -> V_11 -> V_38 ) ;
if ( F_17 ( ! ( V_2 -> V_40 & V_19 ) ) ) {
F_10 ( V_6 , V_2 -> V_11 -> V_41 , V_19 , V_31 != 0 ) ;
V_2 -> V_13 . V_42 =
F_3 ( V_2 -> V_6 + V_2 -> V_11 -> V_41 ) ;
}
if ( ! V_2 -> V_11 -> V_43 ) {
if ( V_2 -> V_40 ) {
if ( ! ( V_2 -> V_40 & V_19 ) )
goto exit;
}
if ( V_31 & V_44 )
V_2 -> V_45 |= V_19 ;
else
V_2 -> V_45 &= ~ V_19 ;
}
exit:
V_2 -> V_46 =
F_3 ( V_2 -> V_6 + V_2 -> V_11 -> V_32 ) |
F_3 ( V_2 -> V_6 + V_2 -> V_11 -> V_34 ) ;
}
static void F_18 ( struct V_1 * V_2 , int V_7 )
{
void T_1 * V_9 = V_2 -> V_6 ;
T_2 V_10 = 0 ;
if ( ! V_2 -> V_11 -> V_43 )
return;
V_9 += V_2 -> V_11 -> V_43 ;
V_10 = F_3 ( V_9 ) ;
if ( ( V_10 >> V_7 ) & 1 )
V_10 &= ~ ( 1 << V_7 ) ;
else
V_10 |= 1 << V_7 ;
F_4 ( V_10 , V_9 ) ;
}
static void F_18 ( struct V_1 * V_2 , int V_7 ) {}
static int F_19 ( struct V_1 * V_2 , int V_7 ,
unsigned V_31 )
{
void T_1 * V_9 = V_2 -> V_6 ;
void T_1 * V_6 = V_2 -> V_6 ;
T_2 V_10 = 0 ;
if ( V_2 -> V_11 -> V_32 && V_2 -> V_11 -> V_41 ) {
F_16 ( V_2 , V_7 , V_31 ) ;
} else if ( V_2 -> V_11 -> V_43 ) {
V_9 += V_2 -> V_11 -> V_43 ;
V_10 = F_3 ( V_9 ) ;
if ( ( V_31 & V_47 ) == V_44 )
V_2 -> V_48 |= 1 << V_7 ;
if ( V_31 & V_37 )
V_10 |= 1 << V_7 ;
else if ( V_31 & V_39 )
V_10 &= ~ ( 1 << V_7 ) ;
else
return - V_49 ;
F_4 ( V_10 , V_9 ) ;
} else if ( V_2 -> V_11 -> V_50 ) {
if ( V_7 & 0x08 )
V_9 += V_2 -> V_11 -> V_51 ;
else
V_9 += V_2 -> V_11 -> V_50 ;
V_7 &= 0x07 ;
V_10 = F_3 ( V_9 ) ;
V_10 &= ~ ( 3 << ( V_7 << 1 ) ) ;
if ( V_31 & V_37 )
V_10 |= 2 << ( V_7 << 1 ) ;
if ( V_31 & V_39 )
V_10 |= 1 << ( V_7 << 1 ) ;
F_10 ( V_6 , V_2 -> V_11 -> V_41 , 1 << V_7 , V_31 ) ;
V_2 -> V_13 . V_42 =
F_3 ( V_2 -> V_6 + V_2 -> V_11 -> V_41 ) ;
F_4 ( V_10 , V_9 ) ;
}
return 0 ;
}
static int F_20 ( struct V_52 * V_53 , unsigned type )
{
struct V_1 * V_2 = F_21 ( V_53 ) ;
unsigned V_7 ;
int V_54 ;
unsigned long V_55 ;
if ( ! F_22 () && V_53 -> V_56 > V_57 )
V_7 = F_23 ( V_53 -> V_56 - V_57 ) ;
else
V_7 = F_1 ( V_2 , V_53 -> V_56 ) ;
if ( type & ~ V_47 )
return - V_49 ;
if ( ! V_2 -> V_11 -> V_32 &&
( type & ( V_33 | V_35 ) ) )
return - V_49 ;
F_24 ( & V_2 -> V_58 , V_55 ) ;
V_54 = F_19 ( V_2 , F_25 ( V_2 , V_7 ) , type ) ;
F_26 ( & V_2 -> V_58 , V_55 ) ;
if ( type & ( V_33 | V_35 ) )
F_27 ( V_53 -> V_56 , V_59 ) ;
else if ( type & ( V_39 | V_37 ) )
F_27 ( V_53 -> V_56 , V_60 ) ;
return V_54 ;
}
static void F_28 ( struct V_1 * V_2 , int V_61 )
{
void T_1 * V_9 = V_2 -> V_6 ;
V_9 += V_2 -> V_11 -> V_62 ;
F_4 ( V_61 , V_9 ) ;
if ( V_2 -> V_11 -> V_63 ) {
V_9 = V_2 -> V_6 + V_2 -> V_11 -> V_63 ;
F_4 ( V_61 , V_9 ) ;
}
F_3 ( V_9 ) ;
}
static inline void F_29 ( struct V_1 * V_2 , int V_7 )
{
F_28 ( V_2 , F_6 ( V_2 , V_7 ) ) ;
}
static T_2 F_30 ( struct V_1 * V_2 )
{
void T_1 * V_9 = V_2 -> V_6 ;
T_2 V_10 ;
T_2 V_22 = ( 1 << V_2 -> V_64 ) - 1 ;
V_9 += V_2 -> V_11 -> V_65 ;
V_10 = F_3 ( V_9 ) ;
if ( V_2 -> V_11 -> V_66 )
V_10 = ~ V_10 ;
V_10 &= V_22 ;
return V_10 ;
}
static void F_31 ( struct V_1 * V_2 , int V_61 )
{
void T_1 * V_9 = V_2 -> V_6 ;
T_2 V_10 ;
if ( V_2 -> V_11 -> V_67 ) {
V_9 += V_2 -> V_11 -> V_67 ;
V_10 = V_61 ;
V_2 -> V_13 . V_68 |= V_61 ;
} else {
V_9 += V_2 -> V_11 -> V_65 ;
V_10 = F_3 ( V_9 ) ;
if ( V_2 -> V_11 -> V_66 )
V_10 &= ~ V_61 ;
else
V_10 |= V_61 ;
V_2 -> V_13 . V_68 = V_10 ;
}
F_4 ( V_10 , V_9 ) ;
}
static void F_32 ( struct V_1 * V_2 , int V_61 )
{
void T_1 * V_9 = V_2 -> V_6 ;
T_2 V_10 ;
if ( V_2 -> V_11 -> V_69 ) {
V_9 += V_2 -> V_11 -> V_69 ;
V_10 = V_61 ;
V_2 -> V_13 . V_68 &= ~ V_61 ;
} else {
V_9 += V_2 -> V_11 -> V_65 ;
V_10 = F_3 ( V_9 ) ;
if ( V_2 -> V_11 -> V_66 )
V_10 |= V_61 ;
else
V_10 &= ~ V_61 ;
V_2 -> V_13 . V_68 = V_10 ;
}
F_4 ( V_10 , V_9 ) ;
}
static inline void F_33 ( struct V_1 * V_2 , int V_7 , int V_15 )
{
if ( V_15 )
F_31 ( V_2 , F_6 ( V_2 , V_7 ) ) ;
else
F_32 ( V_2 , F_6 ( V_2 , V_7 ) ) ;
}
static int F_34 ( struct V_1 * V_2 , int V_7 , int V_15 )
{
T_2 V_19 = F_6 ( V_2 , V_7 ) ;
unsigned long V_55 ;
if ( V_2 -> V_40 & V_19 ) {
F_35 ( V_2 -> V_70 ,
L_1 , V_7 ) ;
return - V_49 ;
}
F_24 ( & V_2 -> V_58 , V_55 ) ;
if ( V_15 )
V_2 -> V_71 |= V_19 ;
else
V_2 -> V_71 &= ~ V_19 ;
F_4 ( V_2 -> V_71 , V_2 -> V_6 + V_2 -> V_11 -> V_41 ) ;
F_26 ( & V_2 -> V_58 , V_55 ) ;
return 0 ;
}
static void F_36 ( struct V_1 * V_2 , int V_7 )
{
F_2 ( V_2 , F_25 ( V_2 , V_7 ) , 1 ) ;
F_33 ( V_2 , V_7 , 0 ) ;
F_29 ( V_2 , V_7 ) ;
F_19 ( V_2 , F_25 ( V_2 , V_7 ) , V_72 ) ;
}
static int F_37 ( struct V_52 * V_53 , unsigned int V_15 )
{
struct V_1 * V_2 = F_21 ( V_53 ) ;
unsigned int V_7 = F_1 ( V_2 , V_53 -> V_56 ) ;
return F_34 ( V_2 , V_7 , V_15 ) ;
}
static int F_38 ( struct V_73 * V_5 , unsigned V_20 )
{
struct V_1 * V_2 = F_39 ( V_5 , struct V_1 , V_5 ) ;
unsigned long V_55 ;
if ( ! V_2 -> V_74 )
F_40 ( V_2 -> V_70 ) ;
F_24 ( & V_2 -> V_58 , V_55 ) ;
F_19 ( V_2 , V_20 , V_72 ) ;
if ( V_2 -> V_11 -> V_75 ) {
void T_1 * V_9 = V_2 -> V_6 + V_2 -> V_11 -> V_75 ;
F_4 ( F_3 ( V_9 ) | ( 1 << V_20 ) , V_9 ) ;
}
if ( V_2 -> V_11 -> V_76 && ! V_2 -> V_74 ) {
void T_1 * V_9 = V_2 -> V_6 + V_2 -> V_11 -> V_76 ;
T_2 V_76 ;
V_76 = F_3 ( V_9 ) ;
V_76 &= ~ V_77 ;
F_4 ( V_76 , V_9 ) ;
V_2 -> V_13 . V_76 = V_76 ;
}
V_2 -> V_74 |= 1 << V_20 ;
F_26 ( & V_2 -> V_58 , V_55 ) ;
return 0 ;
}
static void F_41 ( struct V_73 * V_5 , unsigned V_20 )
{
struct V_1 * V_2 = F_39 ( V_5 , struct V_1 , V_5 ) ;
void T_1 * V_6 = V_2 -> V_6 ;
unsigned long V_55 ;
F_24 ( & V_2 -> V_58 , V_55 ) ;
if ( V_2 -> V_11 -> V_41 ) {
F_10 ( V_6 , V_2 -> V_11 -> V_41 , 1 << V_20 , 0 ) ;
V_2 -> V_13 . V_42 =
F_3 ( V_2 -> V_6 + V_2 -> V_11 -> V_41 ) ;
}
V_2 -> V_74 &= ~ ( 1 << V_20 ) ;
if ( V_2 -> V_11 -> V_76 && ! V_2 -> V_74 ) {
void T_1 * V_9 = V_2 -> V_6 + V_2 -> V_11 -> V_76 ;
T_2 V_76 ;
V_76 = F_3 ( V_9 ) ;
V_76 |= V_77 ;
F_4 ( V_76 , V_9 ) ;
V_2 -> V_13 . V_76 = V_76 ;
}
F_36 ( V_2 , V_2 -> V_5 . V_6 + V_20 ) ;
F_26 ( & V_2 -> V_58 , V_55 ) ;
if ( ! V_2 -> V_74 )
F_42 ( V_2 -> V_70 ) ;
}
static void F_43 ( unsigned int V_56 , struct V_78 * V_79 )
{
void T_1 * V_80 = NULL ;
T_2 V_81 ;
unsigned int V_3 , V_82 ;
struct V_1 * V_2 ;
T_2 V_83 = 0 ;
int V_84 = 0 ;
struct V_85 * V_5 = F_44 ( V_79 ) ;
F_45 ( V_5 , V_79 ) ;
V_2 = F_46 ( V_56 ) ;
V_80 = V_2 -> V_6 + V_2 -> V_11 -> V_62 ;
F_40 ( V_2 -> V_70 ) ;
if ( F_47 ( ! V_80 ) )
goto exit;
while( 1 ) {
T_2 V_86 , V_46 = 0 ;
T_2 V_87 ;
V_87 = F_30 ( V_2 ) ;
V_86 = V_81 = F_3 ( V_80 ) & V_87 ;
if ( V_2 -> V_46 )
V_46 = V_2 -> V_46 & V_87 ;
F_32 ( V_2 , V_86 & ~ V_46 ) ;
F_28 ( V_2 , V_86 & ~ V_46 ) ;
F_31 ( V_2 , V_86 & ~ V_46 ) ;
if ( ! V_46 && ! V_84 ) {
V_84 = 1 ;
F_48 ( V_5 , V_79 ) ;
}
V_81 |= V_83 ;
V_83 = 0 ;
if ( ! V_81 )
break;
V_3 = V_2 -> V_4 ;
for (; V_81 != 0 ; V_81 >>= 1 , V_3 ++ ) {
int V_7 = F_1 ( V_2 , V_3 ) ;
if ( ! ( V_81 & 1 ) )
continue;
V_82 = F_25 ( V_2 , V_7 ) ;
if ( V_2 -> V_48 & ( 1 << V_82 ) )
F_18 ( V_2 , V_82 ) ;
F_49 ( V_3 ) ;
}
}
exit:
if ( ! V_84 )
F_48 ( V_5 , V_79 ) ;
F_42 ( V_2 -> V_70 ) ;
}
static void F_50 ( struct V_52 * V_53 )
{
struct V_1 * V_2 = F_21 ( V_53 ) ;
unsigned int V_7 = F_1 ( V_2 , V_53 -> V_56 ) ;
unsigned long V_55 ;
F_24 ( & V_2 -> V_58 , V_55 ) ;
F_36 ( V_2 , V_7 ) ;
F_26 ( & V_2 -> V_58 , V_55 ) ;
}
static void F_51 ( struct V_52 * V_53 )
{
struct V_1 * V_2 = F_21 ( V_53 ) ;
unsigned int V_7 = F_1 ( V_2 , V_53 -> V_56 ) ;
F_29 ( V_2 , V_7 ) ;
}
static void F_52 ( struct V_52 * V_53 )
{
struct V_1 * V_2 = F_21 ( V_53 ) ;
unsigned int V_7 = F_1 ( V_2 , V_53 -> V_56 ) ;
unsigned long V_55 ;
F_24 ( & V_2 -> V_58 , V_55 ) ;
F_33 ( V_2 , V_7 , 0 ) ;
F_19 ( V_2 , F_25 ( V_2 , V_7 ) , V_72 ) ;
F_26 ( & V_2 -> V_58 , V_55 ) ;
}
static void F_53 ( struct V_52 * V_53 )
{
struct V_1 * V_2 = F_21 ( V_53 ) ;
unsigned int V_7 = F_1 ( V_2 , V_53 -> V_56 ) ;
unsigned int V_88 = F_6 ( V_2 , V_7 ) ;
T_2 V_31 = F_54 ( V_53 ) ;
unsigned long V_55 ;
F_24 ( & V_2 -> V_58 , V_55 ) ;
if ( V_31 )
F_19 ( V_2 , F_25 ( V_2 , V_7 ) , V_31 ) ;
if ( V_2 -> V_46 & V_88 ) {
F_33 ( V_2 , V_7 , 0 ) ;
F_29 ( V_2 , V_7 ) ;
}
F_33 ( V_2 , V_7 , 1 ) ;
F_26 ( & V_2 -> V_58 , V_55 ) ;
}
static int F_55 ( struct V_89 * V_70 )
{
struct V_90 * V_91 = F_56 ( V_70 ) ;
struct V_1 * V_2 = F_57 ( V_91 ) ;
void T_1 * V_92 = V_2 -> V_6 +
V_93 / V_2 -> V_94 ;
unsigned long V_55 ;
F_24 ( & V_2 -> V_58 , V_55 ) ;
V_2 -> V_95 = F_3 ( V_92 ) ;
F_4 ( 0xffff & ~ V_2 -> V_71 , V_92 ) ;
F_26 ( & V_2 -> V_58 , V_55 ) ;
return 0 ;
}
static int F_58 ( struct V_89 * V_70 )
{
struct V_90 * V_91 = F_56 ( V_70 ) ;
struct V_1 * V_2 = F_57 ( V_91 ) ;
void T_1 * V_92 = V_2 -> V_6 +
V_93 / V_2 -> V_94 ;
unsigned long V_55 ;
F_24 ( & V_2 -> V_58 , V_55 ) ;
F_4 ( V_2 -> V_95 , V_92 ) ;
F_26 ( & V_2 -> V_58 , V_55 ) ;
return 0 ;
}
static inline void F_59 ( struct V_1 * V_2 )
{
F_60 ( & V_96 , V_2 ) ;
if ( F_61 ( & V_97 ) == 0 )
( void ) F_62 ( & V_96 ) ;
}
static int F_63 ( struct V_73 * V_5 , unsigned V_20 )
{
struct V_1 * V_2 ;
unsigned long V_55 ;
V_2 = F_39 ( V_5 , struct V_1 , V_5 ) ;
F_24 ( & V_2 -> V_58 , V_55 ) ;
F_2 ( V_2 , V_20 , 1 ) ;
F_26 ( & V_2 -> V_58 , V_55 ) ;
return 0 ;
}
static int F_64 ( struct V_1 * V_2 , int V_22 )
{
void T_1 * V_9 = V_2 -> V_6 + V_2 -> V_11 -> V_12 ;
return F_3 ( V_9 ) & V_22 ;
}
static int F_65 ( struct V_73 * V_5 , unsigned V_20 )
{
struct V_1 * V_2 ;
T_2 V_22 ;
V_2 = F_39 ( V_5 , struct V_1 , V_5 ) ;
V_22 = ( 1 << V_20 ) ;
if ( F_64 ( V_2 , V_22 ) )
return F_8 ( V_2 , V_20 ) ;
else
return F_9 ( V_2 , V_20 ) ;
}
static int F_66 ( struct V_73 * V_5 , unsigned V_20 , int V_98 )
{
struct V_1 * V_2 ;
unsigned long V_55 ;
V_2 = F_39 ( V_5 , struct V_1 , V_5 ) ;
F_24 ( & V_2 -> V_58 , V_55 ) ;
V_2 -> V_16 ( V_2 , V_20 , V_98 ) ;
F_2 ( V_2 , V_20 , 0 ) ;
F_26 ( & V_2 -> V_58 , V_55 ) ;
return 0 ;
}
static int F_67 ( struct V_73 * V_5 , unsigned V_20 ,
unsigned V_27 )
{
struct V_1 * V_2 ;
unsigned long V_55 ;
V_2 = F_39 ( V_5 , struct V_1 , V_5 ) ;
if ( ! V_2 -> V_26 ) {
V_2 -> V_26 = F_68 ( V_2 -> V_70 , L_2 ) ;
if ( F_69 ( V_2 -> V_26 ) )
F_35 ( V_2 -> V_70 , L_3 ) ;
}
F_24 ( & V_2 -> V_58 , V_55 ) ;
F_15 ( V_2 , V_20 , V_27 ) ;
F_26 ( & V_2 -> V_58 , V_55 ) ;
return 0 ;
}
static void F_70 ( struct V_73 * V_5 , unsigned V_20 , int V_98 )
{
struct V_1 * V_2 ;
unsigned long V_55 ;
V_2 = F_39 ( V_5 , struct V_1 , V_5 ) ;
F_24 ( & V_2 -> V_58 , V_55 ) ;
V_2 -> V_16 ( V_2 , V_20 , V_98 ) ;
F_26 ( & V_2 -> V_58 , V_55 ) ;
}
static int F_71 ( struct V_73 * V_5 , unsigned V_20 )
{
struct V_1 * V_2 ;
V_2 = F_39 ( V_5 , struct V_1 , V_5 ) ;
return V_2 -> V_4 + V_20 ;
}
static void T_3 F_72 ( struct V_1 * V_2 )
{
static bool V_99 ;
T_2 V_100 ;
if ( V_99 || V_2 -> V_11 -> V_101 == V_102 )
return;
V_100 = F_73 ( V_2 -> V_6 + V_2 -> V_11 -> V_101 ) ;
F_74 ( L_4 ,
( V_100 >> 4 ) & 0x0f , V_100 & 0x0f ) ;
V_99 = true ;
}
static void F_75 ( struct V_1 * V_2 )
{
void T_1 * V_6 = V_2 -> V_6 ;
T_2 V_10 = 0xffffffff ;
if ( V_2 -> V_64 == 16 )
V_10 = 0xffff ;
if ( V_2 -> V_103 ) {
F_4 ( V_10 , V_2 -> V_6 + V_2 -> V_11 -> V_65 ) ;
return;
}
F_10 ( V_6 , V_2 -> V_11 -> V_65 , V_10 , V_2 -> V_11 -> V_66 ) ;
F_10 ( V_6 , V_2 -> V_11 -> V_62 , V_10 , ! V_2 -> V_11 -> V_66 ) ;
if ( V_2 -> V_11 -> V_30 )
F_4 ( 0 , V_6 + V_2 -> V_11 -> V_30 ) ;
V_2 -> V_13 . V_14 = F_3 ( V_2 -> V_6 + V_2 -> V_11 -> V_12 ) ;
if ( V_2 -> V_11 -> V_76 )
F_4 ( 0 , V_6 + V_2 -> V_11 -> V_76 ) ;
}
static T_4 void
F_76 ( struct V_1 * V_2 , unsigned int V_104 ,
unsigned int V_105 )
{
struct V_106 * V_107 ;
struct V_108 * V_109 ;
V_107 = F_77 ( L_5 , 1 , V_104 , V_2 -> V_6 ,
V_110 ) ;
if ( ! V_107 ) {
F_35 ( V_2 -> V_70 , L_6 ) ;
return;
}
V_109 = V_107 -> V_111 ;
V_109 -> V_5 . V_88 = V_112 ;
V_109 -> V_5 . V_113 = V_114 ;
V_109 -> V_5 . V_115 = F_20 ;
if ( V_2 -> V_11 -> V_41 )
V_109 -> V_5 . V_116 = F_37 ,
V_109 -> V_11 . V_22 = V_117 / V_2 -> V_94 ;
F_78 ( V_107 , F_79 ( V_105 ) , V_118 ,
V_119 | V_120 , 0 ) ;
}
static void T_4 F_80 ( struct V_1 * V_2 )
{
int V_121 ;
static int V_7 ;
V_2 -> V_5 . V_122 = F_38 ;
V_2 -> V_5 . free = F_41 ;
V_2 -> V_5 . V_123 = F_63 ;
V_2 -> V_5 . V_124 = F_65 ;
V_2 -> V_5 . V_125 = F_66 ;
V_2 -> V_5 . V_126 = F_67 ;
V_2 -> V_5 . V_23 = F_70 ;
V_2 -> V_5 . V_127 = F_71 ;
if ( V_2 -> V_103 ) {
V_2 -> V_5 . V_128 = L_7 ;
if ( V_2 -> V_11 -> V_41 )
V_2 -> V_5 . V_70 = & V_96 . V_70 ;
V_2 -> V_5 . V_6 = F_23 ( 0 ) ;
} else {
V_2 -> V_5 . V_128 = L_8 ;
V_2 -> V_5 . V_6 = V_7 ;
V_7 += V_2 -> V_64 ;
}
V_2 -> V_5 . V_129 = V_2 -> V_64 ;
F_81 ( & V_2 -> V_5 ) ;
for ( V_121 = V_2 -> V_4 ; V_121 < V_2 -> V_4 + V_2 -> V_64 ; V_121 ++ ) {
F_82 ( V_121 , & V_130 ) ;
F_83 ( V_121 , V_2 ) ;
if ( V_2 -> V_103 ) {
F_76 ( V_2 , V_121 , V_2 -> V_64 ) ;
} else {
F_84 ( V_121 , & V_131 ) ;
F_85 ( V_121 , V_110 ) ;
F_86 ( V_121 , V_132 ) ;
}
}
F_87 ( V_2 -> V_56 , F_43 ) ;
F_88 ( V_2 -> V_56 , V_2 ) ;
}
static int T_4 F_89 ( struct V_90 * V_91 )
{
struct V_89 * V_70 = & V_91 -> V_70 ;
struct V_133 * V_134 = V_70 -> V_135 ;
const struct V_136 * V_137 ;
struct V_138 * V_139 ;
struct V_140 * V_141 ;
struct V_1 * V_2 ;
int V_142 = 0 ;
V_137 = F_90 ( F_91 ( V_143 ) , V_70 ) ;
V_139 = V_137 ? V_137 -> V_144 : V_70 -> V_145 ;
if ( ! V_139 )
return - V_49 ;
V_2 = F_92 ( & V_91 -> V_70 , sizeof( struct V_1 ) , V_146 ) ;
if ( ! V_2 ) {
F_35 ( V_70 , L_9 ) ;
return - V_147 ;
}
V_141 = F_93 ( V_91 , V_148 , 0 ) ;
if ( F_94 ( ! V_141 ) ) {
F_35 ( V_70 , L_10 ) ;
return - V_149 ;
}
V_2 -> V_56 = V_141 -> V_150 ;
V_2 -> V_70 = V_70 ;
V_2 -> V_29 = V_139 -> V_29 ;
V_2 -> V_94 = V_139 -> V_151 ;
V_2 -> V_64 = V_139 -> V_152 ;
V_2 -> V_103 = V_139 -> V_103 ;
V_2 -> V_40 = V_139 -> V_40 ;
V_2 -> V_153 = V_139 -> V_153 ;
V_2 -> V_154 = V_139 -> V_154 ;
V_2 -> V_11 = V_139 -> V_11 ;
#ifdef F_95
V_2 -> V_5 . V_135 = F_96 ( V_134 ) ;
#endif
V_2 -> V_4 = F_97 ( - 1 , 0 , V_2 -> V_64 , 0 ) ;
if ( V_2 -> V_4 < 0 ) {
F_35 ( V_70 , L_11 ) ;
return - V_149 ;
}
V_2 -> V_155 = F_98 ( V_134 , V_2 -> V_64 , V_2 -> V_4 ,
0 , & V_156 , NULL ) ;
if ( V_2 -> V_11 -> V_16 && V_2 -> V_11 -> V_18 )
V_2 -> V_16 = F_5 ;
else
V_2 -> V_16 = F_7 ;
F_99 ( & V_2 -> V_58 ) ;
V_141 = F_93 ( V_91 , V_157 , 0 ) ;
if ( F_94 ( ! V_141 ) ) {
F_35 ( V_70 , L_12 ) ;
return - V_149 ;
}
if ( ! F_100 ( V_70 , V_141 -> V_150 , F_101 ( V_141 ) ,
V_91 -> V_158 ) ) {
F_35 ( V_70 , L_13 ) ;
return - V_159 ;
}
V_2 -> V_6 = F_102 ( V_70 , V_141 -> V_150 , F_101 ( V_141 ) ) ;
if ( ! V_2 -> V_6 ) {
F_35 ( V_70 , L_14 ) ;
return - V_147 ;
}
F_60 ( V_91 , V_2 ) ;
F_103 ( V_2 -> V_70 ) ;
F_104 ( V_2 -> V_70 ) ;
F_40 ( V_2 -> V_70 ) ;
if ( V_2 -> V_103 )
F_59 ( V_2 ) ;
F_75 ( V_2 ) ;
F_80 ( V_2 ) ;
F_72 ( V_2 ) ;
F_42 ( V_2 -> V_70 ) ;
F_105 ( & V_2 -> V_134 , & V_160 ) ;
return V_142 ;
}
static int F_106 ( struct V_89 * V_70 )
{
struct V_90 * V_91 = F_56 ( V_70 ) ;
struct V_1 * V_2 = F_57 ( V_91 ) ;
void T_1 * V_6 = V_2 -> V_6 ;
void T_1 * V_161 ;
unsigned long V_55 ;
if ( ! V_2 -> V_74 || ! V_2 -> V_153 )
return 0 ;
if ( ! V_2 -> V_11 -> V_41 || ! V_2 -> V_71 )
return 0 ;
V_161 = V_2 -> V_6 + V_2 -> V_11 -> V_41 ;
F_24 ( & V_2 -> V_58 , V_55 ) ;
V_2 -> V_95 = F_3 ( V_161 ) ;
F_10 ( V_6 , V_2 -> V_11 -> V_41 , 0xffffffff , 0 ) ;
F_10 ( V_6 , V_2 -> V_11 -> V_41 , V_2 -> V_71 , 1 ) ;
F_26 ( & V_2 -> V_58 , V_55 ) ;
return 0 ;
}
static int F_107 ( struct V_89 * V_70 )
{
struct V_90 * V_91 = F_56 ( V_70 ) ;
struct V_1 * V_2 = F_57 ( V_91 ) ;
void T_1 * V_6 = V_2 -> V_6 ;
unsigned long V_55 ;
if ( ! V_2 -> V_74 || ! V_2 -> V_153 )
return 0 ;
if ( ! V_2 -> V_11 -> V_41 || ! V_2 -> V_95 )
return 0 ;
F_24 ( & V_2 -> V_58 , V_55 ) ;
F_10 ( V_6 , V_2 -> V_11 -> V_41 , 0xffffffff , 0 ) ;
F_10 ( V_6 , V_2 -> V_11 -> V_41 , V_2 -> V_95 , 1 ) ;
F_26 ( & V_2 -> V_58 , V_55 ) ;
return 0 ;
}
static int F_108 ( struct V_89 * V_70 )
{
struct V_90 * V_91 = F_56 ( V_70 ) ;
struct V_1 * V_2 = F_57 ( V_91 ) ;
T_2 V_162 = 0 , V_163 = 0 ;
unsigned long V_55 ;
T_2 V_164 , V_165 ;
F_24 ( & V_2 -> V_58 , V_55 ) ;
V_164 = V_2 -> V_13 . V_32 & V_2 -> V_13 . V_42 ;
if ( V_164 )
F_4 ( V_164 | V_2 -> V_13 . V_38 ,
V_2 -> V_6 + V_2 -> V_11 -> V_38 ) ;
V_165 = V_2 -> V_13 . V_34 & V_2 -> V_13 . V_42 ;
if ( V_165 )
F_4 ( V_165 | V_2 -> V_13 . V_36 ,
V_2 -> V_6 + V_2 -> V_11 -> V_36 ) ;
if ( V_2 -> V_166 != V_167 ) {
V_2 -> V_166 = 0 ;
goto V_168;
}
V_2 -> V_169 = F_3 ( V_2 -> V_6 +
V_2 -> V_11 -> V_21 ) ;
V_162 = F_3 ( V_2 -> V_6 + V_2 -> V_11 -> V_38 ) ;
V_163 = F_3 ( V_2 -> V_6 + V_2 -> V_11 -> V_36 ) ;
V_2 -> V_170 = V_162 ;
V_2 -> V_171 = V_163 ;
V_162 &= ~ V_2 -> V_45 ;
V_163 &= ~ V_2 -> V_45 ;
F_4 ( V_162 , V_2 -> V_6 + V_2 -> V_11 -> V_38 ) ;
F_4 ( V_163 , V_2 -> V_6 + V_2 -> V_11 -> V_36 ) ;
V_2 -> V_172 = true ;
V_168:
if ( V_2 -> V_154 )
V_2 -> V_173 =
V_2 -> V_154 ( V_2 -> V_70 ) ;
F_13 ( V_2 ) ;
F_26 ( & V_2 -> V_58 , V_55 ) ;
return 0 ;
}
static int F_109 ( struct V_89 * V_70 )
{
struct V_90 * V_91 = F_56 ( V_70 ) ;
struct V_1 * V_2 = F_57 ( V_91 ) ;
int V_174 ;
T_2 V_10 = 0 , V_175 , V_176 , V_177 ;
unsigned long V_55 ;
F_24 ( & V_2 -> V_58 , V_55 ) ;
F_11 ( V_2 ) ;
F_4 ( V_2 -> V_13 . V_38 ,
V_2 -> V_6 + V_2 -> V_11 -> V_38 ) ;
F_4 ( V_2 -> V_13 . V_36 ,
V_2 -> V_6 + V_2 -> V_11 -> V_36 ) ;
if ( ! V_2 -> V_172 ) {
F_26 ( & V_2 -> V_58 , V_55 ) ;
return 0 ;
}
if ( V_2 -> V_154 ) {
V_174 =
V_2 -> V_154 ( V_2 -> V_70 ) ;
if ( V_174 != V_2 -> V_173 ||
! V_174 ) {
F_110 ( V_2 ) ;
} else {
F_26 ( & V_2 -> V_58 , V_55 ) ;
return 0 ;
}
}
F_4 ( V_2 -> V_170 ,
V_2 -> V_6 + V_2 -> V_11 -> V_38 ) ;
F_4 ( V_2 -> V_171 ,
V_2 -> V_6 + V_2 -> V_11 -> V_36 ) ;
V_10 = F_3 ( V_2 -> V_6 + V_2 -> V_11 -> V_21 ) ;
V_10 ^= V_2 -> V_169 ;
V_10 &= V_2 -> V_45 ;
V_176 = V_10 & V_2 -> V_170 ;
V_176 &= V_2 -> V_169 ;
V_177 = V_10 & V_2 -> V_171 ;
V_177 &= ~ ( V_2 -> V_169 ) ;
V_175 = V_10 & ( ~ ( V_2 -> V_170 ) & ~ ( V_2 -> V_171 ) ) ;
V_175 |= V_176 | V_177 ;
if ( V_175 ) {
T_2 V_178 , V_179 ;
V_178 = F_3 ( V_2 -> V_6 + V_2 -> V_11 -> V_32 ) ;
V_179 = F_3 ( V_2 -> V_6 + V_2 -> V_11 -> V_34 ) ;
if ( F_111 () || F_112 () ) {
F_4 ( V_178 | V_175 , V_2 -> V_6 +
V_2 -> V_11 -> V_32 ) ;
F_4 ( V_179 | V_175 , V_2 -> V_6 +
V_2 -> V_11 -> V_34 ) ;
}
if ( F_113 () ) {
F_4 ( V_178 | V_10 , V_2 -> V_6 +
V_2 -> V_11 -> V_32 ) ;
F_4 ( V_179 | V_10 , V_2 -> V_6 +
V_2 -> V_11 -> V_34 ) ;
}
F_4 ( V_178 , V_2 -> V_6 + V_2 -> V_11 -> V_32 ) ;
F_4 ( V_179 , V_2 -> V_6 + V_2 -> V_11 -> V_34 ) ;
}
V_2 -> V_172 = false ;
F_26 ( & V_2 -> V_58 , V_55 ) ;
return 0 ;
}
void F_114 ( int V_180 )
{
struct V_1 * V_2 ;
F_115 (bank, &omap_gpio_list, node) {
if ( ! V_2 -> V_74 || ! V_2 -> V_153 )
continue;
V_2 -> V_166 = V_180 ;
F_116 ( V_2 -> V_70 ) ;
}
}
void F_117 ( void )
{
struct V_1 * V_2 ;
F_115 (bank, &omap_gpio_list, node) {
if ( ! V_2 -> V_74 || ! V_2 -> V_153 )
continue;
F_40 ( V_2 -> V_70 ) ;
}
}
static void F_110 ( struct V_1 * V_2 )
{
F_4 ( V_2 -> V_13 . V_42 ,
V_2 -> V_6 + V_2 -> V_11 -> V_41 ) ;
F_4 ( V_2 -> V_13 . V_76 , V_2 -> V_6 + V_2 -> V_11 -> V_76 ) ;
F_4 ( V_2 -> V_13 . V_32 ,
V_2 -> V_6 + V_2 -> V_11 -> V_32 ) ;
F_4 ( V_2 -> V_13 . V_34 ,
V_2 -> V_6 + V_2 -> V_11 -> V_34 ) ;
F_4 ( V_2 -> V_13 . V_36 ,
V_2 -> V_6 + V_2 -> V_11 -> V_36 ) ;
F_4 ( V_2 -> V_13 . V_38 ,
V_2 -> V_6 + V_2 -> V_11 -> V_38 ) ;
if ( V_2 -> V_11 -> V_16 && V_2 -> V_11 -> V_18 )
F_4 ( V_2 -> V_13 . V_17 ,
V_2 -> V_6 + V_2 -> V_11 -> V_16 ) ;
else
F_4 ( V_2 -> V_13 . V_17 ,
V_2 -> V_6 + V_2 -> V_11 -> V_17 ) ;
F_4 ( V_2 -> V_13 . V_14 , V_2 -> V_6 + V_2 -> V_11 -> V_12 ) ;
if ( V_2 -> V_24 ) {
F_4 ( V_2 -> V_13 . V_27 , V_2 -> V_6 +
V_2 -> V_11 -> V_27 ) ;
F_4 ( V_2 -> V_13 . V_30 ,
V_2 -> V_6 + V_2 -> V_11 -> V_30 ) ;
}
F_4 ( V_2 -> V_13 . V_68 ,
V_2 -> V_6 + V_2 -> V_11 -> V_65 ) ;
F_4 ( V_2 -> V_13 . V_181 ,
V_2 -> V_6 + V_2 -> V_11 -> V_181 ) ;
}
static int T_3 F_118 ( void )
{
return F_61 ( & V_182 ) ;
}
