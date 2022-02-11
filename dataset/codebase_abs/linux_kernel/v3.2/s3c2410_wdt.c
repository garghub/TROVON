static int F_1 ( struct V_1 * V_2 )
{
F_2 ( & V_3 ) ;
F_3 ( V_4 , V_5 + V_6 ) ;
F_4 ( & V_3 ) ;
return 0 ;
}
static void F_5 ( void )
{
unsigned long V_7 ;
V_7 = F_6 ( V_5 + V_8 ) ;
V_7 &= ~ ( V_9 | V_10 ) ;
F_3 ( V_7 , V_5 + V_8 ) ;
}
static int F_7 ( struct V_1 * V_2 )
{
F_2 ( & V_3 ) ;
F_5 () ;
F_4 ( & V_3 ) ;
return 0 ;
}
static int F_8 ( struct V_1 * V_2 )
{
unsigned long V_7 ;
F_2 ( & V_3 ) ;
F_5 () ;
V_7 = F_6 ( V_5 + V_8 ) ;
V_7 |= V_9 | V_11 ;
if ( V_12 ) {
V_7 |= V_13 ;
V_7 &= ~ V_10 ;
} else {
V_7 &= ~ V_13 ;
V_7 |= V_10 ;
}
F_9 ( L_1 ,
V_14 , V_4 , V_7 ) ;
F_3 ( V_4 , V_5 + V_15 ) ;
F_3 ( V_4 , V_5 + V_6 ) ;
F_3 ( V_7 , V_5 + V_8 ) ;
F_4 ( & V_3 ) ;
return 0 ;
}
static inline int F_10 ( void )
{
return F_6 ( V_5 + V_8 ) & V_9 ;
}
static int F_11 ( struct V_1 * V_2 , unsigned V_16 )
{
unsigned long V_17 = F_12 ( V_18 ) ;
unsigned int V_19 ;
unsigned int V_20 = 1 ;
unsigned long V_7 ;
if ( V_16 < 1 )
return - V_21 ;
V_17 /= 128 ;
V_19 = V_16 * V_17 ;
F_9 ( L_2 ,
V_14 , V_19 , V_16 , V_17 ) ;
if ( V_19 >= 0x10000 ) {
for ( V_20 = 1 ; V_20 <= 0x100 ; V_20 ++ ) {
if ( ( V_19 / V_20 ) < 0x10000 )
break;
}
if ( ( V_19 / V_20 ) >= 0x10000 ) {
F_13 ( V_22 , L_3 , V_16 ) ;
return - V_21 ;
}
}
F_9 ( L_4 ,
V_14 , V_16 , V_20 , V_19 , V_19 / V_20 ) ;
V_19 /= V_20 ;
V_4 = V_19 ;
V_7 = F_6 ( V_5 + V_8 ) ;
V_7 &= ~ V_23 ;
V_7 |= F_14 ( V_20 - 1 ) ;
F_3 ( V_19 , V_5 + V_15 ) ;
F_3 ( V_7 , V_5 + V_8 ) ;
return 0 ;
}
static T_1 F_15 ( int V_24 , void * V_25 )
{
F_16 ( V_22 , L_5 ) ;
F_1 ( & V_26 ) ;
return V_27 ;
}
static int F_17 ( struct V_28 * V_29 ,
unsigned long V_30 , void * V_31 )
{
int V_32 ;
if ( ! F_10 () )
goto V_33;
if ( V_30 == V_34 ) {
F_1 ( & V_26 ) ;
} else if ( V_30 == V_35 ) {
F_7 ( & V_26 ) ;
V_32 = F_11 ( & V_26 , V_26 . V_16 ) ;
if ( V_32 >= 0 )
F_8 ( & V_26 ) ;
else
goto V_36;
}
V_33:
return 0 ;
V_36:
F_13 ( V_22 , L_6 ,
V_26 . V_16 ) ;
return V_32 ;
}
static inline int F_18 ( void )
{
return F_19 ( & V_37 ,
V_38 ) ;
}
static inline void F_20 ( void )
{
F_21 ( & V_37 ,
V_38 ) ;
}
static inline int F_18 ( void )
{
return 0 ;
}
static inline void F_20 ( void )
{
}
static int T_2 F_22 ( struct V_39 * V_40 )
{
struct V_41 * V_42 ;
unsigned int V_7 ;
int V_43 = 0 ;
int V_32 ;
int V_44 ;
F_9 ( L_7 , V_14 , V_40 ) ;
V_42 = & V_40 -> V_42 ;
V_22 = & V_40 -> V_42 ;
V_45 = F_23 ( V_40 , V_46 , 0 ) ;
if ( V_45 == NULL ) {
F_13 ( V_42 , L_8 ) ;
return - V_47 ;
}
V_44 = F_24 ( V_45 ) ;
if ( ! F_25 ( V_45 -> V_48 , V_44 , V_40 -> V_49 ) ) {
F_13 ( V_42 , L_9 ) ;
return - V_50 ;
}
V_5 = F_26 ( V_45 -> V_48 , V_44 ) ;
if ( V_5 == NULL ) {
F_13 ( V_42 , L_10 ) ;
V_32 = - V_21 ;
goto V_51;
}
F_9 ( L_11 , V_5 ) ;
V_52 = F_23 ( V_40 , V_53 , 0 ) ;
if ( V_52 == NULL ) {
F_13 ( V_42 , L_12 ) ;
V_32 = - V_47 ;
goto V_54;
}
V_32 = F_27 ( V_52 -> V_48 , F_15 , 0 , V_40 -> V_49 , V_40 ) ;
if ( V_32 != 0 ) {
F_13 ( V_42 , L_13 , V_32 ) ;
goto V_54;
}
V_18 = F_28 ( & V_40 -> V_42 , L_14 ) ;
if ( F_29 ( V_18 ) ) {
F_13 ( V_42 , L_15 ) ;
V_32 = F_30 ( V_18 ) ;
goto V_55;
}
F_31 ( V_18 ) ;
if ( F_18 () < 0 ) {
F_32 (KERN_ERR PFX L_16 ) ;
goto V_56;
}
if ( F_11 ( & V_26 , V_57 ) ) {
V_43 = F_11 ( & V_26 ,
V_58 ) ;
if ( V_43 == 0 )
F_16 ( V_42 ,
L_17 ,
V_58 ) ;
else
F_16 ( V_42 , L_18
L_19 ) ;
}
V_32 = F_33 ( & V_26 ) ;
if ( V_32 ) {
F_13 ( V_42 , L_20 , V_32 ) ;
goto V_59;
}
if ( V_60 && V_43 == 0 ) {
F_16 ( V_42 , L_21 ) ;
F_8 ( & V_26 ) ;
} else if ( ! V_60 ) {
F_7 ( & V_26 ) ;
}
V_7 = F_6 ( V_5 + V_8 ) ;
F_16 ( V_42 , L_22 ,
( V_7 & V_9 ) ? L_23 : L_24 ,
( V_7 & V_10 ) ? L_25 : L_26 ,
( V_7 & V_13 ) ? L_25 : L_26 ) ;
return 0 ;
V_59:
F_20 () ;
V_56:
F_34 ( V_18 ) ;
F_35 ( V_18 ) ;
V_55:
F_36 ( V_52 -> V_48 , V_40 ) ;
V_54:
F_37 ( V_5 ) ;
V_51:
F_38 ( V_45 -> V_48 , V_44 ) ;
V_45 = NULL ;
return V_32 ;
}
static int T_3 F_39 ( struct V_39 * V_42 )
{
F_40 ( & V_26 ) ;
F_20 () ;
F_34 ( V_18 ) ;
F_35 ( V_18 ) ;
V_18 = NULL ;
F_36 ( V_52 -> V_48 , V_42 ) ;
V_52 = NULL ;
F_37 ( V_5 ) ;
F_38 ( V_45 -> V_48 , F_24 ( V_45 ) ) ;
V_45 = NULL ;
return 0 ;
}
static void F_41 ( struct V_39 * V_42 )
{
F_7 ( & V_26 ) ;
}
static int F_42 ( struct V_39 * V_42 , T_4 V_61 )
{
V_62 = F_6 ( V_5 + V_8 ) ;
V_63 = F_6 ( V_5 + V_15 ) ;
F_7 ( & V_26 ) ;
return 0 ;
}
static int F_43 ( struct V_39 * V_42 )
{
F_3 ( V_63 , V_5 + V_15 ) ;
F_3 ( V_63 , V_5 + V_6 ) ;
F_3 ( V_62 , V_5 + V_8 ) ;
F_32 (KERN_INFO PFX L_27 ,
(wtcon_save & S3C2410_WTCON_ENABLE) ? L_25 : L_26 ) ;
return 0 ;
}
static int T_5 F_44 ( void )
{
F_32 ( V_64 ) ;
return F_45 ( & V_65 ) ;
}
static void T_6 F_46 ( void )
{
F_47 ( & V_65 ) ;
}
