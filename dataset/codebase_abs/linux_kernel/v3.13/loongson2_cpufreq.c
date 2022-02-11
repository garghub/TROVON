static int F_1 ( struct V_1 * V_2 ,
unsigned long V_3 , void * V_4 )
{
if ( V_3 == V_5 )
V_6 . V_7 = V_8 ;
return 0 ;
}
static unsigned int F_2 ( unsigned int V_9 )
{
return F_3 ( V_10 ) ;
}
static int F_4 ( struct V_11 * V_12 ,
unsigned int V_13 )
{
unsigned int V_9 = V_12 -> V_9 ;
T_1 V_14 ;
unsigned int V_15 ;
V_14 = V_16 -> V_14 ;
F_5 ( V_16 , F_6 ( V_9 ) ) ;
V_15 =
( ( V_17 / 1000 ) *
V_18 [ V_13 ] . V_19 ) / 8 ;
F_5 ( V_16 , & V_14 ) ;
F_7 ( V_10 , V_15 ) ;
return 0 ;
}
static int F_8 ( struct V_11 * V_12 )
{
int V_20 ;
unsigned long V_21 ;
int V_22 ;
V_10 = F_9 ( NULL , L_1 ) ;
if ( F_10 ( V_10 ) ) {
F_11 ( V_23 L_2 ) ;
return F_12 ( V_10 ) ;
}
V_21 = V_17 / 1000 ;
if ( ! V_21 ) {
F_13 ( V_10 ) ;
return - V_24 ;
}
for ( V_20 = 2 ;
( V_18 [ V_20 ] . V_25 != V_26 ) ;
V_20 ++ )
V_18 [ V_20 ] . V_25 = ( V_21 * V_20 ) / 8 ;
V_22 = F_7 ( V_10 , V_21 ) ;
if ( V_22 ) {
F_13 ( V_10 ) ;
return V_22 ;
}
return F_14 ( V_12 , & V_18 [ 0 ] , 0 ) ;
}
static int F_15 ( struct V_11 * V_12 )
{
F_16 ( V_12 -> V_9 ) ;
F_13 ( V_10 ) ;
return 0 ;
}
static void F_17 ( void )
{
unsigned long V_27 ;
T_2 V_28 ;
F_18 ( & V_29 , V_27 ) ;
V_28 = V_30 ;
V_30 &= ~ 0x7 ;
V_30 = V_28 ;
F_19 ( & V_29 , V_27 ) ;
F_20 () ;
}
static int T_3 F_21 ( void )
{
int V_22 ;
V_22 = F_22 ( & V_31 ) ;
if ( V_22 )
return V_22 ;
F_23 ( L_3 ) ;
F_24 ( & V_32 ,
V_33 ) ;
V_22 = F_25 ( & V_34 ) ;
if ( ! V_22 && ! V_35 ) {
V_36 = V_37 ;
V_37 = F_17 ;
}
return V_22 ;
}
static void T_4 F_26 ( void )
{
if ( ! V_35 && V_36 )
V_37 = V_36 ;
F_27 ( & V_34 ) ;
F_28 ( & V_32 ,
V_33 ) ;
F_29 ( & V_31 ) ;
}
