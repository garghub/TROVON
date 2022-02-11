static inline T_1 F_1 ( unsigned long V_1 )
{
return F_2 ( V_2 . V_3 + V_1 ) ;
}
static inline void F_3 ( T_1 V_4 , unsigned long V_1 )
{
F_4 ( V_4 , V_2 . V_3 + V_1 ) ;
}
static inline void F_5 ( void )
{
F_6 () ;
}
static int F_7 ( T_2 V_5 , int V_6 )
{
T_1 V_7 ;
T_1 V_8 ;
V_7 = F_1 ( V_9 ) ;
V_8 = V_7 & ~ ( V_10 ) ;
V_7 |= V_6 ;
F_3 ( V_8 , V_9 ) ;
F_5 () ;
F_3 ( 0 , V_11 ) ;
F_3 ( 0 , V_12 ) ;
F_3 ( V_5 & 0xffffffff , V_13 ) ;
F_3 ( V_5 >> 32 , V_14 ) ;
F_5 () ;
F_3 ( V_7 , V_9 ) ;
return 0 ;
}
static void F_8 ( void )
{
T_1 V_7 ;
V_7 = F_1 ( V_9 ) ;
V_7 &= ~ ( V_10 ) ;
F_3 ( V_7 , V_9 ) ;
}
static T_3 F_9 ( int V_15 , void * V_16 )
{
struct V_17 * V_18 = V_16 ;
V_18 -> V_19 ( V_18 ) ;
return V_20 ;
}
static int F_10 ( unsigned long V_21 ,
struct V_17 * V_18 )
{
return F_7 ( V_21 , V_22 ) ;
}
static int F_11 ( struct V_17 * V_18 )
{
F_8 () ;
return 0 ;
}
static int F_12 ( struct V_17 * V_18 )
{
F_7 ( V_2 . V_23 , V_24 ) ;
return 0 ;
}
static int T_4 F_13 ( struct V_25 * V_26 )
{
struct V_17 * V_27 = & V_2 . V_27 ;
unsigned long V_28 ;
struct V_29 * V_29 ;
int V_15 , error ;
V_15 = F_14 ( V_26 , 0 ) ;
if ( ! V_15 ) {
F_15 ( L_1 , V_30 ) ;
return - V_31 ;
}
V_2 . V_3 = F_16 ( V_26 , 0 ) ;
if ( ! V_2 . V_3 ) {
F_15 ( L_2 , V_30 ) ;
return - V_32 ;
}
V_29 = F_17 ( V_26 , 0 ) ;
if ( F_18 ( V_29 ) ) {
F_15 ( L_3 , V_30 ) ;
F_19 ( V_2 . V_3 ) ;
return F_20 ( V_29 ) ;
}
error = F_21 ( V_29 ) ;
if ( error ) {
F_15 ( L_4 , V_30 ) ;
goto V_33;
}
V_28 = F_22 ( V_29 ) ;
F_3 ( 0 , V_9 ) ;
F_5 () ;
F_3 ( 0 , V_34 ) ;
F_3 ( V_35 , V_34 ) ;
F_3 ( 0 , V_11 ) ;
F_3 ( 0 , V_12 ) ;
V_2 . V_23 = F_23 ( V_28 , V_36 ) ;
F_3 ( V_37 , V_38 ) ;
error = F_24 ( V_15 , F_9 , V_39 ,
V_40 , V_27 ) ;
if ( error ) {
F_15 ( L_5 , V_30 ) ;
goto V_33;
}
V_27 -> V_41 = V_42 | V_43 ;
V_27 -> V_44 = F_10 ;
V_27 -> V_45 = F_11 ;
V_27 -> V_46 = F_12 ;
V_27 -> V_47 = F_11 ;
V_27 -> V_48 = V_49 ;
V_27 -> V_50 = V_51 ;
V_27 -> V_52 = V_40 ;
V_27 -> V_15 = V_15 ;
F_25 ( V_27 , V_28 , 1 , V_53 ) ;
F_26 ( L_6 , V_28 ) ;
return 0 ;
V_33:
F_27 ( V_29 ) ;
F_19 ( V_2 . V_3 ) ;
return error ;
}
