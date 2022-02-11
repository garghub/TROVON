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
static void F_8 ( unsigned int V_13 ,
struct V_2 * V_10 )
{
V_10 -> V_14 = L_1 ;
V_10 -> V_15 = V_16 |
V_17 ;
V_10 -> V_18 = 350 ;
V_10 -> V_8 = V_19 ;
V_10 -> V_6 = F_9 ( V_13 ) ;
V_10 -> V_20 = F_1 ;
F_10 ( V_10 , V_21 , 0x300 , 0x7fffffff ) ;
F_11 ( V_19 , V_22 ) ;
}
static void F_12 ( struct V_2 * V_10 )
{
F_13 ( V_19 ) ;
}
static void F_14 ( void * V_23 )
{
unsigned long V_24 = ( unsigned long ) V_23 ;
F_15 ( F_16 ( & V_25 ) , V_24 ) ;
}
static int F_17 ( unsigned int V_13 )
{
F_8 ( V_13 , F_16 ( & V_25 ) ) ;
return 0 ;
}
static int F_18 ( struct V_26 * V_27 , unsigned long V_28 ,
void * V_23 )
{
struct V_29 * V_30 = V_23 ;
if ( V_28 == V_31 )
F_19 ( F_14 , ( void * ) V_30 -> V_32 , 1 ) ;
return V_33 ;
}
static int F_20 ( unsigned int V_13 )
{
F_12 ( F_16 ( & V_25 ) ) ;
return 0 ;
}
static int F_21 ( void )
{
int V_34 ;
if ( ! V_21 )
return - V_35 ;
V_34 = F_22 ( V_19 , & V_36 ) ;
if ( V_34 < 0 ) {
F_23 ( L_2 ,
V_19 , V_34 ) ;
return V_34 ;
}
F_24 ( V_37 ,
L_3 ,
F_17 , F_20 ) ;
return 0 ;
}
static T_1 F_25 ( struct V_38 * V_39 )
{
return F_2 () ;
}
static int T_3 F_26 ( void )
{
int V_34 ;
V_40 . V_41 = F_27 ( F_28 () ) ;
V_40 . V_18 = 200 + V_21 / 10000000 ;
V_34 = F_29 ( & V_40 , V_21 ) ;
if ( V_34 < 0 )
F_30 ( L_4 ) ;
return V_34 ;
}
static int T_3 F_31 ( struct V_42 * V_43 )
{
struct V_44 * V_44 ;
int V_34 ;
if ( ! V_45 || ! V_43 -> V_46 ||
! F_32 ( V_43 -> V_46 , L_5 ) ) {
F_30 ( L_6 ) ;
return - V_35 ;
}
V_44 = F_33 ( V_43 , 0 ) ;
if ( ! F_34 ( V_44 ) ) {
if ( F_35 ( V_44 ) < 0 ) {
F_23 ( L_7 ) ;
F_36 ( V_44 ) ;
return F_37 ( V_44 ) ;
}
V_21 = F_38 ( V_44 ) ;
} else if ( F_39 ( V_43 , L_8 ,
& V_21 ) ) {
F_23 ( L_9 ) ;
return - V_47 ; ;
}
V_19 = F_40 ( V_43 , 0 ) ;
if ( ! V_19 ) {
F_23 ( L_10 ) ;
return - V_47 ; ;
}
V_34 = F_26 () ;
if ( V_34 )
return V_34 ;
V_34 = F_21 () ;
if ( ! V_34 && ! F_34 ( V_44 ) ) {
if ( F_41 ( V_44 , & V_48 ) < 0 )
F_30 ( L_11 ) ;
}
F_42 () ;
return 0 ;
}
