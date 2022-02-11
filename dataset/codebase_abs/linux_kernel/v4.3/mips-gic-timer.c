static int F_1 ( unsigned long V_1 , struct V_2 * V_3 )
{
T_1 V_4 ;
int V_5 ;
V_4 = F_2 () ;
V_4 += ( T_1 ) V_1 ;
F_3 ( V_4 , F_4 ( V_3 -> V_6 ) ) ;
V_5 = ( ( int ) ( F_2 () - V_4 ) >= 0 ) ? - V_7 : 0 ;
return V_5 ;
}
static T_2 F_5 ( int V_8 , void * V_9 )
{
struct V_2 * V_10 = V_9 ;
F_6 ( F_7 () ) ;
V_10 -> V_11 ( V_10 ) ;
return V_12 ;
}
static void F_8 ( struct V_2 * V_10 )
{
unsigned int V_13 = F_9 () ;
V_10 -> V_14 = L_1 ;
V_10 -> V_15 = V_16 |
V_17 ;
V_10 -> V_18 = 350 ;
V_10 -> V_8 = V_19 ;
V_10 -> V_6 = F_10 ( V_13 ) ;
V_10 -> V_20 = F_1 ;
F_11 ( V_10 , V_21 , 0x300 , 0x7fffffff ) ;
F_12 ( V_19 , V_22 ) ;
}
static void F_13 ( struct V_2 * V_10 )
{
F_14 ( V_19 ) ;
}
static void F_15 ( void * V_23 )
{
unsigned long V_24 = ( unsigned long ) V_23 ;
F_16 ( F_17 ( & V_25 ) , V_24 ) ;
}
static int F_18 ( struct V_26 * V_27 , unsigned long V_28 ,
void * V_23 )
{
switch ( V_28 & ~ V_29 ) {
case V_30 :
F_8 ( F_17 ( & V_25 ) ) ;
break;
case V_31 :
F_13 ( F_17 ( & V_25 ) ) ;
break;
}
return V_32 ;
}
static int F_19 ( struct V_26 * V_27 , unsigned long V_28 ,
void * V_23 )
{
struct V_33 * V_34 = V_23 ;
if ( V_28 == V_35 )
F_20 ( F_15 , ( void * ) V_34 -> V_36 , 1 ) ;
return V_32 ;
}
static int F_21 ( void )
{
int V_37 ;
if ( ! V_38 || ! V_21 )
return - V_39 ;
V_37 = F_22 ( V_19 , & V_40 ) ;
if ( V_37 < 0 )
return V_37 ;
V_37 = F_23 ( & V_41 ) ;
if ( V_37 < 0 )
F_24 ( L_2 ) ;
F_8 ( F_17 ( & V_25 ) ) ;
return 0 ;
}
static T_3 F_25 ( struct V_42 * V_43 )
{
return F_2 () ;
}
static void T_4 F_26 ( void )
{
int V_37 ;
V_44 . V_45 = F_27 ( F_28 () ) ;
V_44 . V_18 = 200 + V_21 / 10000000 ;
V_37 = F_29 ( & V_44 , V_21 ) ;
if ( V_37 < 0 )
F_24 ( L_3 ) ;
}
void T_4 F_30 ( unsigned int V_46 )
{
V_21 = V_46 ;
V_19 = V_47 +
F_31 ( V_48 ) ;
F_26 () ;
F_21 () ;
F_32 () ;
}
static void T_4 F_33 ( struct V_49 * V_50 )
{
struct V_51 * V_51 ;
int V_37 ;
if ( F_34 ( ! V_52 || ! V_50 -> V_53 ||
! F_35 ( V_50 -> V_53 , L_4 ) ) )
return;
V_51 = F_36 ( V_50 , 0 ) ;
if ( ! F_37 ( V_51 ) ) {
if ( F_38 ( V_51 ) < 0 ) {
F_39 ( L_5 ) ;
F_40 ( V_51 ) ;
return;
}
V_21 = F_41 ( V_51 ) ;
} else if ( F_42 ( V_50 , L_6 ,
& V_21 ) ) {
F_39 ( L_7 ) ;
return;
}
V_19 = F_43 ( V_50 , 0 ) ;
if ( ! V_19 ) {
F_39 ( L_8 ) ;
return;
}
F_26 () ;
V_37 = F_21 () ;
if ( ! V_37 && ! F_37 ( V_51 ) ) {
if ( F_44 ( V_51 , & V_54 ) < 0 )
F_24 ( L_9 ) ;
}
F_32 () ;
}
