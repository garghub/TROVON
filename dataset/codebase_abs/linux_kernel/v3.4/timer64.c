static void F_1 ( unsigned long V_1 )
{
T_1 V_2 = F_2 ( & V_3 -> V_2 ) & ~ V_4 ;
F_3 ( V_2 , & V_3 -> V_2 ) ;
F_3 ( V_1 - 1 , & V_3 -> V_5 ) ;
F_3 ( 0 , & V_3 -> V_6 ) ;
V_2 |= V_7 ;
F_3 ( V_2 , & V_3 -> V_2 ) ;
}
static void F_4 ( void )
{
T_1 V_8 ;
if ( V_9 >= 0 )
F_5 ( V_9 , V_10 ) ;
F_3 ( F_2 ( & V_3 -> V_2 ) & ~ V_4 , & V_3 -> V_2 ) ;
F_3 ( 0 , & V_3 -> V_5 ) ;
V_8 = F_2 ( & V_3 -> V_2 ) ;
F_3 ( V_8 & ~ ( V_11 | V_12 ) , & V_3 -> V_2 ) ;
V_8 = F_2 ( & V_3 -> V_13 ) & ~ V_14 ;
F_3 ( V_8 , & V_3 -> V_13 ) ;
F_3 ( V_8 | ( V_15 | V_16 ) , & V_3 -> V_13 ) ;
}
static void F_6 ( void )
{
F_3 ( F_2 ( & V_3 -> V_2 ) & ~ V_4 , & V_3 -> V_2 ) ;
F_3 ( 0 , & V_3 -> V_5 ) ;
if ( V_9 >= 0 )
F_5 ( V_9 , V_17 ) ;
}
static int F_7 ( unsigned long V_18 ,
struct V_19 * V_20 )
{
F_1 ( V_18 ) ;
return 0 ;
}
static void F_8 ( enum V_21 V_22 ,
struct V_19 * V_20 )
{
switch ( V_22 ) {
case V_23 :
F_4 () ;
V_7 = V_24 ;
F_1 ( V_25 / V_26 ) ;
break;
case V_27 :
F_4 () ;
V_7 = V_28 ;
break;
case V_29 :
case V_30 :
V_7 = V_31 ;
F_6 () ;
break;
case V_32 :
break;
}
}
static T_2 F_9 ( int V_33 , void * V_34 )
{
struct V_19 * V_35 = & V_36 ;
V_35 -> V_37 ( V_35 ) ;
return V_38 ;
}
void T_3 F_10 ( void )
{
struct V_19 * V_35 = & V_36 ;
struct V_39 * V_40 , * V_41 = NULL ;
T_1 V_8 ;
int V_42 , V_43 = 0 ;
F_11 (np, NULL, L_1 ) {
V_42 = F_12 ( V_40 , L_2 , & V_8 ) ;
if ( ! V_42 ) {
if ( V_8 & ( 1 << F_13 () ) ) {
V_43 = 1 ;
break;
}
} else if ( ! V_41 )
V_41 = V_40 ;
}
if ( ! V_43 ) {
if ( V_41 )
V_40 = F_14 ( V_41 ) ;
else {
F_15 ( L_3 ) ;
return;
}
}
V_3 = F_16 ( V_40 , 0 ) ;
if ( ! V_3 ) {
F_15 ( L_4 , V_40 -> V_44 ) ;
goto V_45;
}
F_15 ( L_5 , V_40 -> V_44 , V_3 ) ;
V_35 -> V_33 = F_17 ( V_40 , 0 ) ;
if ( V_35 -> V_33 == V_46 ) {
F_15 ( L_6 , V_40 -> V_44 ) ;
F_18 ( V_3 ) ;
goto V_45;
}
V_42 = F_12 ( V_40 , L_7 , & V_8 ) ;
if ( ! V_42 ) {
V_9 = V_8 ;
F_5 ( V_9 , V_10 ) ;
}
F_15 ( L_8 , V_40 -> V_44 , V_35 -> V_33 ) ;
F_19 ( V_35 , V_47 / V_48 , 5 ) ;
V_35 -> V_49 = F_20 ( 0x7fffffff , V_35 ) ;
V_35 -> V_50 = F_20 ( 250 , V_35 ) ;
V_35 -> V_51 = F_21 ( F_22 () ) ;
F_23 ( V_35 ) ;
F_24 ( V_35 -> V_33 , & V_52 ) ;
V_45:
F_25 ( V_40 ) ;
return;
}
