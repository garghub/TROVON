static int F_1 ( struct V_1 * V_2 ,
unsigned long V_3 , void * V_4 )
{
if ( V_3 == V_5 )
V_6 . V_7 = V_8 ;
return 0 ;
}
static int F_2 ( struct V_9 * V_10 ,
unsigned int V_11 )
{
unsigned int V_12 ;
V_12 =
( ( V_13 / 1000 ) *
V_14 [ V_11 ] . V_15 ) / 8 ;
F_3 ( V_10 -> V_16 , V_12 * 1000 ) ;
return 0 ;
}
static int F_4 ( struct V_9 * V_10 )
{
struct V_16 * V_17 ;
int V_18 ;
unsigned long V_19 ;
int V_20 ;
V_17 = F_5 ( NULL , L_1 ) ;
if ( F_6 ( V_17 ) ) {
F_7 ( L_2 ) ;
return F_8 ( V_17 ) ;
}
V_19 = V_13 / 1000 ;
if ( ! V_19 ) {
F_9 ( V_17 ) ;
return - V_21 ;
}
for ( V_18 = 2 ;
( V_14 [ V_18 ] . V_22 != V_23 ) ;
V_18 ++ )
V_14 [ V_18 ] . V_22 = ( V_19 * V_18 ) / 8 ;
V_20 = F_3 ( V_17 , V_19 * 1000 ) ;
if ( V_20 ) {
F_9 ( V_17 ) ;
return V_20 ;
}
V_10 -> V_16 = V_17 ;
return F_10 ( V_10 , & V_14 [ 0 ] , 0 ) ;
}
static int F_11 ( struct V_9 * V_10 )
{
F_9 ( V_10 -> V_16 ) ;
return 0 ;
}
static void F_12 ( void )
{
unsigned long V_24 ;
T_1 V_25 ;
F_13 ( & V_26 , V_24 ) ;
V_25 = F_14 ( 0 ) ;
F_14 ( 0 ) &= ~ 0x7 ;
F_14 ( 0 ) = V_25 ;
F_15 ( & V_26 , V_24 ) ;
F_16 () ;
}
static int T_2 F_17 ( void )
{
int V_20 ;
V_20 = F_18 ( & V_27 ) ;
if ( V_20 )
return V_20 ;
F_19 ( L_3 ) ;
F_20 ( & V_28 ,
V_29 ) ;
V_20 = F_21 ( & V_30 ) ;
if ( ! V_20 && ! V_31 ) {
V_32 = V_33 ;
V_33 = F_12 ;
}
return V_20 ;
}
static void T_3 F_22 ( void )
{
if ( ! V_31 && V_32 )
V_33 = V_32 ;
F_23 ( & V_30 ) ;
F_24 ( & V_28 ,
V_29 ) ;
F_25 ( & V_27 ) ;
}
