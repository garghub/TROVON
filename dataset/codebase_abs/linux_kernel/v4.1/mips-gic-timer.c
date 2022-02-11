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
static void F_5 ( enum V_8 V_9 ,
struct V_2 * V_3 )
{
}
static T_2 F_6 ( int V_10 , void * V_11 )
{
struct V_2 * V_12 = V_11 ;
F_7 ( F_8 () ) ;
V_12 -> V_13 ( V_12 ) ;
return V_14 ;
}
static void F_9 ( struct V_2 * V_12 )
{
unsigned int V_15 = F_10 () ;
V_12 -> V_16 = L_1 ;
V_12 -> V_17 = V_18 |
V_19 ;
V_12 -> V_20 = 350 ;
V_12 -> V_10 = V_21 ;
V_12 -> V_6 = F_11 ( V_15 ) ;
V_12 -> V_22 = F_1 ;
V_12 -> V_23 = F_5 ;
F_12 ( V_12 , V_24 , 0x300 , 0x7fffffff ) ;
F_13 ( V_21 , V_25 ) ;
}
static void F_14 ( struct V_2 * V_12 )
{
F_15 ( V_21 ) ;
}
static int F_16 ( struct V_26 * V_27 , unsigned long V_28 ,
void * V_29 )
{
switch ( V_28 & ~ V_30 ) {
case V_31 :
F_9 ( F_17 ( & V_32 ) ) ;
break;
case V_33 :
F_14 ( F_17 ( & V_32 ) ) ;
break;
}
return V_34 ;
}
static int F_18 ( void )
{
if ( ! V_35 || ! V_24 )
return - V_36 ;
F_19 ( V_21 , & V_37 ) ;
F_20 ( & V_38 ) ;
F_9 ( F_17 ( & V_32 ) ) ;
return 0 ;
}
static T_3 F_21 ( struct V_39 * V_40 )
{
return F_2 () ;
}
static void T_4 F_22 ( void )
{
V_41 . V_42 = F_23 ( F_24 () ) ;
V_41 . V_20 = 200 + V_24 / 10000000 ;
F_25 ( & V_41 , V_24 ) ;
F_18 () ;
F_26 () ;
}
void T_4 F_27 ( unsigned int V_43 )
{
V_24 = V_43 ;
V_21 = V_44 +
F_28 ( V_45 ) ;
F_22 () ;
}
static void T_4 F_29 ( struct V_46 * V_47 )
{
struct V_48 * V_48 ;
if ( F_30 ( ! V_49 || ! V_47 -> V_50 ||
! F_31 ( V_47 -> V_50 , L_2 ) ) )
return;
V_48 = F_32 ( V_47 , 0 ) ;
if ( ! F_33 ( V_48 ) ) {
V_24 = F_34 ( V_48 ) ;
F_35 ( V_48 ) ;
} else if ( F_36 ( V_47 , L_3 ,
& V_24 ) ) {
F_37 ( L_4 ) ;
return;
}
V_21 = F_38 ( V_47 , 0 ) ;
if ( ! V_21 ) {
F_37 ( L_5 ) ;
return;
}
F_22 () ;
}
