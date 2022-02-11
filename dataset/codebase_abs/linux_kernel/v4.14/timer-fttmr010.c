static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_4 ) ;
}
static unsigned long F_3 ( void )
{
return F_4 ( V_5 -> V_6 + V_7 ) ;
}
static unsigned long F_5 ( void )
{
return ~ F_4 ( V_5 -> V_6 + V_7 ) ;
}
static T_1 T_2 F_6 ( void )
{
return F_3 () ;
}
static T_1 T_2 F_7 ( void )
{
return F_5 () ;
}
static int F_8 ( unsigned long V_8 ,
struct V_2 * V_3 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
T_3 V_9 ;
V_9 = F_4 ( V_1 -> V_6 + V_10 ) ;
V_9 &= ~ V_1 -> V_11 ;
F_9 ( V_9 , V_1 -> V_6 + V_10 ) ;
V_9 = F_4 ( V_1 -> V_6 + V_12 ) ;
if ( V_1 -> V_13 )
V_9 -= V_8 ;
else
V_9 += V_8 ;
F_9 ( V_9 , V_1 -> V_6 + V_14 ) ;
V_9 = F_4 ( V_1 -> V_6 + V_10 ) ;
V_9 |= V_1 -> V_11 ;
F_9 ( V_9 , V_1 -> V_6 + V_10 ) ;
return 0 ;
}
static int F_10 ( struct V_2 * V_3 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
T_3 V_9 ;
V_9 = F_4 ( V_1 -> V_6 + V_10 ) ;
V_9 &= ~ V_1 -> V_11 ;
F_9 ( V_9 , V_1 -> V_6 + V_10 ) ;
return 0 ;
}
static int F_11 ( struct V_2 * V_3 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
T_3 V_9 ;
V_9 = F_4 ( V_1 -> V_6 + V_10 ) ;
V_9 &= ~ V_1 -> V_11 ;
F_9 ( V_9 , V_1 -> V_6 + V_10 ) ;
F_9 ( 0 , V_1 -> V_6 + V_12 ) ;
if ( V_1 -> V_13 )
F_9 ( ~ 0 , V_1 -> V_6 + V_15 ) ;
else
F_9 ( 0 , V_1 -> V_6 + V_15 ) ;
V_9 = F_4 ( V_1 -> V_6 + V_16 ) ;
V_9 &= ~ ( V_17 | V_18 ) ;
V_9 |= V_19 ;
F_9 ( V_9 , V_1 -> V_6 + V_16 ) ;
return 0 ;
}
static int F_12 ( struct V_2 * V_3 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
T_3 V_20 = F_13 ( V_1 -> V_21 , V_22 ) ;
T_3 V_9 ;
V_9 = F_4 ( V_1 -> V_6 + V_10 ) ;
V_9 &= ~ V_1 -> V_11 ;
F_9 ( V_9 , V_1 -> V_6 + V_10 ) ;
if ( V_1 -> V_13 ) {
F_9 ( V_20 , V_1 -> V_6 + V_15 ) ;
F_9 ( 0 , V_1 -> V_6 + V_14 ) ;
} else {
V_9 = 0xffffffff - ( V_20 - 1 ) ;
F_9 ( V_9 , V_1 -> V_6 + V_12 ) ;
F_9 ( V_9 , V_1 -> V_6 + V_15 ) ;
V_9 = F_4 ( V_1 -> V_6 + V_16 ) ;
V_9 &= ~ ( V_19 | V_18 ) ;
V_9 |= V_17 ;
F_9 ( V_9 , V_1 -> V_6 + V_16 ) ;
}
V_9 = F_4 ( V_1 -> V_6 + V_10 ) ;
V_9 |= V_1 -> V_11 ;
F_9 ( V_9 , V_1 -> V_6 + V_10 ) ;
return 0 ;
}
static T_4 F_14 ( int V_23 , void * V_24 )
{
struct V_2 * V_3 = V_24 ;
V_3 -> V_25 ( V_3 ) ;
return V_26 ;
}
static int T_5 F_15 ( struct V_27 * V_28 , bool V_29 )
{
struct V_1 * V_1 ;
int V_23 ;
struct V_30 * V_30 ;
int V_31 ;
T_3 V_32 ;
V_30 = F_16 ( V_28 , L_1 ) ;
if ( F_17 ( V_30 ) ) {
F_18 ( L_2 ) ;
return F_19 ( V_30 ) ;
}
V_31 = F_20 ( V_30 ) ;
if ( V_31 ) {
F_18 ( L_3 ) ;
return V_31 ;
}
V_1 = F_21 ( sizeof( * V_1 ) , V_33 ) ;
if ( ! V_1 ) {
V_31 = - V_34 ;
goto V_35;
}
V_1 -> V_21 = F_22 ( V_30 ) ;
V_1 -> V_6 = F_23 ( V_28 , 0 ) ;
if ( ! V_1 -> V_6 ) {
F_18 ( L_4 ) ;
V_31 = - V_36 ;
goto V_37;
}
V_23 = F_24 ( V_28 , 0 ) ;
if ( V_23 <= 0 ) {
F_18 ( L_5 ) ;
V_31 = - V_38 ;
goto V_39;
}
if ( V_29 ) {
V_1 -> V_11 = V_40 |
V_41 ;
V_1 -> V_13 = true ;
} else {
V_1 -> V_11 = V_42 | V_43 ;
}
F_9 ( V_44 , V_1 -> V_6 + V_16 ) ;
F_9 ( 0 , V_1 -> V_6 + V_45 ) ;
if ( V_29 )
V_32 = V_46 ;
else {
V_32 = V_47 ;
if ( ! V_1 -> V_13 )
V_32 |= V_48 | V_49 ;
}
F_9 ( V_32 , V_1 -> V_6 + V_10 ) ;
V_5 = V_1 ;
F_9 ( 0 , V_1 -> V_6 + V_7 ) ;
F_9 ( 0 , V_1 -> V_6 + V_50 ) ;
F_9 ( 0 , V_1 -> V_6 + V_51 ) ;
if ( V_1 -> V_13 ) {
F_9 ( ~ 0 , V_1 -> V_6 + V_52 ) ;
F_25 ( V_1 -> V_6 + V_7 ,
L_6 ,
V_1 -> V_21 ,
300 , 32 , V_53 ) ;
F_26 ( F_7 , 32 ,
V_1 -> V_21 ) ;
} else {
F_9 ( 0 , V_1 -> V_6 + V_52 ) ;
F_25 ( V_1 -> V_6 + V_7 ,
L_6 ,
V_1 -> V_21 ,
300 , 32 , V_54 ) ;
F_26 ( F_6 , 32 ,
V_1 -> V_21 ) ;
}
F_9 ( 0 , V_1 -> V_6 + V_12 ) ;
F_9 ( 0 , V_1 -> V_6 + V_15 ) ;
F_9 ( 0 , V_1 -> V_6 + V_14 ) ;
F_9 ( 0 , V_1 -> V_6 + V_55 ) ;
V_31 = F_27 ( V_23 , F_14 , V_56 ,
L_7 , & V_1 -> V_4 ) ;
if ( V_31 ) {
F_18 ( L_8 ) ;
goto V_39;
}
V_1 -> V_4 . V_57 = L_7 ;
V_1 -> V_4 . V_58 = 300 ;
V_1 -> V_4 . V_59 = V_60 |
V_61 ;
V_1 -> V_4 . V_62 = F_8 ;
V_1 -> V_4 . V_63 = F_10 ;
V_1 -> V_4 . V_64 = F_12 ;
V_1 -> V_4 . V_65 = F_11 ;
V_1 -> V_4 . V_66 = F_10 ;
V_1 -> V_4 . V_67 = F_28 ( 0 ) ;
V_1 -> V_4 . V_23 = V_23 ;
F_29 ( & V_1 -> V_4 ,
V_1 -> V_21 ,
1 , 0xffffffff ) ;
#ifdef F_30
if ( V_1 -> V_13 )
V_1 -> V_68 . V_69 =
F_5 ;
else
V_1 -> V_68 . V_69 =
F_3 ;
V_1 -> V_68 . V_70 = V_1 -> V_21 ;
F_31 ( & V_1 -> V_68 ) ;
#endif
return 0 ;
V_39:
F_32 ( V_1 -> V_6 ) ;
V_37:
F_33 ( V_1 ) ;
V_35:
F_34 ( V_30 ) ;
return V_31 ;
}
static T_5 int F_35 ( struct V_27 * V_28 )
{
return F_15 ( V_28 , true ) ;
}
static T_5 int F_36 ( struct V_27 * V_28 )
{
return F_15 ( V_28 , false ) ;
}
