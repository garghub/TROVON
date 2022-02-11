static T_1 F_1 ( int V_1 , void * V_2 )
{
struct V_3 * V_4 = V_2 ;
unsigned long V_5 ;
V_5 = F_2 ( V_6 ) ;
if ( V_5 & V_7 ) {
V_5 |= V_8 ;
F_3 ( V_6 , V_5 ) ;
V_4 -> V_9 ( V_4 ) ;
return V_10 ;
}
return V_11 ;
}
static void F_4 ( void )
{
unsigned long V_5 ;
V_5 = F_2 ( V_6 ) ;
V_5 &= ~ V_12 ;
F_3 ( V_6 , V_5 ) ;
}
static void F_5 ( enum V_13 V_14 ,
struct V_3 * V_15 )
{
switch ( V_14 ) {
case V_16 :
case V_17 :
F_4 () ;
break;
default:
break;
}
}
static int F_6 ( unsigned long V_4 ,
struct V_3 * V_18 )
{
unsigned long V_5 ;
V_5 = F_2 ( V_6 ) ;
V_5 |= V_12 ;
V_5 &= ~ V_8 ;
F_3 ( V_19 , V_4 ) ;
F_3 ( V_6 , V_5 ) ;
return 0 ;
}
static void T_2 F_7 ( struct V_3 * V_15 )
{
F_4 () ;
V_15 -> V_20 = V_21 | V_22 ;
V_15 -> V_23 = L_1 ;
V_15 -> V_24 = 400 ;
V_15 -> V_25 = F_5 ;
V_15 -> V_26 = F_6 ;
V_15 -> V_1 = V_27 ;
V_15 -> V_28 = F_8 ( F_9 () ) ;
F_10 ( V_15 , V_29 ,
0xf , 0x7fffffff ) ;
F_11 ( V_15 -> V_1 , 0 ) ;
F_12 () ;
}
static void T_3 F_13 ( void )
{
if ( V_29 == 0 ) {
F_3 ( V_6 , 0 ) ;
V_29 = F_2 ( V_30 ) ;
if ( V_29 == 0 )
F_14 ( L_2
L_3 ) ;
}
V_31 = V_32 / V_29 ;
F_15 ( L_4 ,
V_29 / 1000000 , ( V_29 / 10000 ) % 100 ) ;
}
static T_4 F_16 ( struct V_33 * V_34 )
{
return F_17 () ;
}
int F_18 ( unsigned long * V_35 )
{
* V_35 = F_17 () ;
return 0 ;
}
unsigned long long T_5 F_19 ( void )
{
return F_20 () * V_31 ;
}
static int T_2 F_21 ( struct V_36 * V_37 ,
unsigned long V_38 , void * V_39 )
{
int V_40 = ( long ) V_39 ;
struct V_3 * V_15 = F_22 ( & V_41 , V_40 ) ;
switch( V_38 ) {
case V_42 :
case V_43 :
F_7 ( V_15 ) ;
break;
case V_44 :
case V_45 :
F_23 ( L_5 ,
V_15 -> V_1 , V_40 ) ;
F_24 ( V_15 -> V_1 ) ;
F_5 ( V_16 , V_15 ) ;
break;
}
return V_46 ;
}
int T_3 F_25 ( void )
{
struct V_47 * V_48 ;
int V_49 ;
T_6 V_50 ;
V_48 = F_26 ( NULL , V_51 ) ;
if ( ! V_48 ) {
F_27 ( L_6 ) ;
return - V_52 ;
}
if ( ! F_28 ( V_48 , L_7 , & V_50 ) )
V_29 = V_50 ;
F_13 () ;
V_27 = F_29 ( V_48 , 0 ) ;
F_15 ( L_8 , V_48 -> V_23 , V_27 ) ;
V_49 = F_30 ( V_27 , F_1 ,
V_48 -> V_23 , & V_41 ) ;
if ( V_49 ) {
F_27 ( L_9 ,
V_27 , V_49 ) ;
return V_49 ;
}
F_31 ( & V_53 , V_29 ) ;
V_54 = V_29 / V_55 ;
F_7 ( F_22 ( & V_41 , F_9 () ) ) ;
F_32 ( & V_56 ) ;
return 0 ;
}
