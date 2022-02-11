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
static int F_8 ( struct V_19 * V_20 )
{
F_4 () ;
V_7 = V_21 ;
F_1 ( V_22 / V_23 ) ;
return 0 ;
}
static int F_9 ( struct V_19 * V_20 )
{
F_4 () ;
V_7 = V_24 ;
return 0 ;
}
static int F_10 ( struct V_19 * V_20 )
{
V_7 = V_25 ;
F_6 () ;
return 0 ;
}
static T_2 F_11 ( int V_26 , void * V_27 )
{
struct V_19 * V_28 = & V_29 ;
V_28 -> V_30 ( V_28 ) ;
return V_31 ;
}
void T_3 F_12 ( void )
{
struct V_19 * V_28 = & V_29 ;
struct V_32 * V_33 , * V_34 = NULL ;
T_1 V_8 ;
int V_35 , V_36 = 0 ;
F_13 (np, NULL, L_1 ) {
V_35 = F_14 ( V_33 , L_2 , & V_8 ) ;
if ( ! V_35 ) {
if ( V_8 & ( 1 << F_15 () ) ) {
V_36 = 1 ;
break;
}
} else if ( ! V_34 )
V_34 = V_33 ;
}
if ( ! V_36 ) {
if ( V_34 )
V_33 = F_16 ( V_34 ) ;
else {
F_17 ( L_3 ) ;
return;
}
}
V_3 = F_18 ( V_33 , 0 ) ;
if ( ! V_3 ) {
F_17 ( L_4 , V_33 ) ;
goto V_37;
}
F_17 ( L_5 , V_33 , V_3 ) ;
V_28 -> V_26 = F_19 ( V_33 , 0 ) ;
if ( V_28 -> V_26 == V_38 ) {
F_17 ( L_6 , V_33 ) ;
F_20 ( V_3 ) ;
goto V_37;
}
V_35 = F_14 ( V_33 , L_7 , & V_8 ) ;
if ( ! V_35 ) {
V_9 = V_8 ;
F_5 ( V_9 , V_10 ) ;
}
F_17 ( L_8 , V_33 , V_28 -> V_26 ) ;
F_21 ( V_28 , V_39 / V_40 , 5 ) ;
V_28 -> V_41 = F_22 ( 0x7fffffff , V_28 ) ;
V_28 -> V_42 = 0x7fffffff ;
V_28 -> V_43 = F_22 ( 250 , V_28 ) ;
V_28 -> V_44 = 250 ;
V_28 -> V_45 = F_23 ( F_24 () ) ;
F_25 ( V_28 ) ;
F_26 ( V_28 -> V_26 , & V_46 ) ;
V_37:
F_27 ( V_33 ) ;
return;
}
