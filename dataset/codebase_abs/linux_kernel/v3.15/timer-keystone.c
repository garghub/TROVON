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
static int F_7 ( T_2 V_5 , enum V_6 V_7 )
{
T_1 V_8 ;
T_1 V_9 ;
V_8 = F_1 ( V_10 ) ;
V_9 = V_8 & ~ ( V_11 ) ;
switch ( V_7 ) {
case V_12 :
V_8 |= V_13 ;
break;
case V_14 :
V_8 |= V_15 ;
break;
default:
return - 1 ;
}
F_3 ( V_9 , V_10 ) ;
F_5 () ;
F_3 ( 0 , V_16 ) ;
F_3 ( 0 , V_17 ) ;
F_3 ( V_5 & 0xffffffff , V_18 ) ;
F_3 ( V_5 >> 32 , V_19 ) ;
F_5 () ;
F_3 ( V_8 , V_10 ) ;
return 0 ;
}
static void F_8 ( void )
{
T_1 V_8 ;
V_8 = F_1 ( V_10 ) ;
V_8 &= ~ ( V_11 ) ;
F_3 ( V_8 , V_10 ) ;
}
static T_3 F_9 ( int V_20 , void * V_21 )
{
struct V_22 * V_23 = V_21 ;
V_23 -> V_24 ( V_23 ) ;
return V_25 ;
}
static int F_10 ( unsigned long V_26 ,
struct V_22 * V_23 )
{
return F_7 ( V_26 , V_23 -> V_7 ) ;
}
static void F_11 ( enum V_6 V_7 ,
struct V_22 * V_23 )
{
switch ( V_7 ) {
case V_14 :
F_7 ( V_2 . V_27 , V_14 ) ;
break;
case V_28 :
case V_29 :
case V_12 :
F_8 () ;
break;
default:
break;
}
}
static void T_4 F_12 ( struct V_30 * V_31 )
{
struct V_22 * V_32 = & V_2 . V_32 ;
unsigned long V_33 ;
struct V_34 * V_34 ;
int V_20 , error ;
V_20 = F_13 ( V_31 , 0 ) ;
if ( V_20 == V_35 ) {
F_14 ( L_1 , V_36 ) ;
return;
}
V_2 . V_3 = F_15 ( V_31 , 0 ) ;
if ( ! V_2 . V_3 ) {
F_14 ( L_2 , V_36 ) ;
return;
}
V_34 = F_16 ( V_31 , 0 ) ;
if ( F_17 ( V_34 ) ) {
F_14 ( L_3 , V_36 ) ;
F_18 ( V_2 . V_3 ) ;
return;
}
error = F_19 ( V_34 ) ;
if ( error ) {
F_14 ( L_4 , V_36 ) ;
goto V_37;
}
V_33 = F_20 ( V_34 ) ;
F_3 ( 0 , V_10 ) ;
F_5 () ;
F_3 ( 0 , V_38 ) ;
F_3 ( V_39 , V_38 ) ;
F_3 ( 0 , V_16 ) ;
F_3 ( 0 , V_17 ) ;
V_2 . V_27 = F_21 ( V_33 , V_40 ) ;
F_3 ( V_41 , V_42 ) ;
error = F_22 ( V_20 , F_9 , V_43 ,
V_44 , V_32 ) ;
if ( error ) {
F_14 ( L_5 , V_36 ) ;
goto V_37;
}
V_32 -> V_45 = V_46 | V_47 ;
V_32 -> V_48 = F_10 ;
V_32 -> V_49 = F_11 ;
V_32 -> V_50 = V_51 ;
V_32 -> V_52 = V_53 ;
V_32 -> V_54 = V_44 ;
V_32 -> V_20 = V_20 ;
F_23 ( V_32 , V_33 , 1 , V_55 ) ;
F_24 ( L_6 , V_33 ) ;
return;
V_37:
F_25 ( V_34 ) ;
F_18 ( V_2 . V_3 ) ;
}
