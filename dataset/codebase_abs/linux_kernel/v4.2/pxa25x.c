static void F_1 ( unsigned long * V_1 )
{
F_2 ( V_2 ) ;
}
static void F_3 ( unsigned long * V_1 )
{
F_4 ( V_2 ) ;
}
static void F_5 ( T_1 V_3 )
{
V_4 = V_5 | V_6 | V_7 | V_8 ;
switch ( V_3 ) {
case V_9 :
F_6 ( V_10 , V_11 ) ;
break;
}
}
static int F_7 ( void )
{
V_12 = F_8 ( V_13 ) ;
return 0 ;
}
static void F_9 ( void )
{
V_12 = 0 ;
}
static void T_2 F_10 ( void )
{
V_14 = & V_15 ;
}
static inline void F_10 ( void ) {}
static int F_11 ( struct V_16 * V_17 , unsigned int V_18 )
{
int V_19 = F_12 ( V_17 -> V_20 ) ;
T_3 V_21 = 0 ;
if ( V_19 >= 0 && V_19 < 85 )
return F_13 ( V_19 , V_18 ) ;
if ( V_17 -> V_20 == V_22 ) {
V_21 = V_23 ;
goto V_24;
}
return - V_25 ;
V_24:
if ( V_18 )
V_26 |= V_21 ;
else
V_26 &= ~ V_21 ;
return 0 ;
}
void T_2 F_14 ( void )
{
F_15 ( 32 , F_11 ) ;
}
void T_2 F_16 ( void )
{
F_15 ( 32 , F_11 ) ;
}
void T_2 F_17 ( void )
{
F_18 () ;
F_19 ( F_20 ( V_27 ) ) ;
F_21 ( 1 ) ;
}
static int T_2 F_22 ( void )
{
int V_28 = 0 ;
if ( F_23 () ) {
V_29 = V_4 ;
if ( ( V_28 = F_24 ( V_30 , 16 ) ) )
return V_28 ;
F_10 () ;
F_25 ( & V_31 ) ;
F_25 ( & V_32 ) ;
F_26 ( & V_33 , & V_34 ) ;
V_28 = F_27 ( V_35 ,
F_28 ( V_35 ) ) ;
if ( V_28 )
return V_28 ;
}
return V_28 ;
}
