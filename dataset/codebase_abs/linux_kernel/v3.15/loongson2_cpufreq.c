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
unsigned int V_12 = V_10 -> V_12 ;
T_1 V_13 ;
unsigned int V_14 ;
V_13 = V_15 -> V_13 ;
F_3 ( V_15 , F_4 ( V_12 ) ) ;
V_14 =
( ( V_16 / 1000 ) *
V_17 [ V_11 ] . V_18 ) / 8 ;
F_3 ( V_15 , & V_13 ) ;
F_5 ( V_10 -> V_19 , V_14 * 1000 ) ;
return 0 ;
}
static int F_6 ( struct V_9 * V_10 )
{
struct V_19 * V_20 ;
int V_21 ;
unsigned long V_22 ;
int V_23 ;
V_20 = F_7 ( NULL , L_1 ) ;
if ( F_8 ( V_20 ) ) {
F_9 ( V_24 L_2 ) ;
return F_10 ( V_20 ) ;
}
V_22 = V_16 / 1000 ;
if ( ! V_22 ) {
F_11 ( V_20 ) ;
return - V_25 ;
}
for ( V_21 = 2 ;
( V_17 [ V_21 ] . V_26 != V_27 ) ;
V_21 ++ )
V_17 [ V_21 ] . V_26 = ( V_22 * V_21 ) / 8 ;
V_23 = F_5 ( V_20 , V_22 * 1000 ) ;
if ( V_23 ) {
F_11 ( V_20 ) ;
return V_23 ;
}
V_10 -> V_19 = V_20 ;
return F_12 ( V_10 , & V_17 [ 0 ] , 0 ) ;
}
static int F_13 ( struct V_9 * V_10 )
{
F_11 ( V_10 -> V_19 ) ;
return 0 ;
}
static void F_14 ( void )
{
unsigned long V_28 ;
T_2 V_29 ;
F_15 ( & V_30 , V_28 ) ;
V_29 = V_31 ;
V_31 &= ~ 0x7 ;
V_31 = V_29 ;
F_16 ( & V_30 , V_28 ) ;
F_17 () ;
}
static int T_3 F_18 ( void )
{
int V_23 ;
V_23 = F_19 ( & V_32 ) ;
if ( V_23 )
return V_23 ;
F_20 ( L_3 ) ;
F_21 ( & V_33 ,
V_34 ) ;
V_23 = F_22 ( & V_35 ) ;
if ( ! V_23 && ! V_36 ) {
V_37 = V_38 ;
V_38 = F_14 ;
}
return V_23 ;
}
static void T_4 F_23 ( void )
{
if ( ! V_36 && V_37 )
V_38 = V_37 ;
F_24 ( & V_35 ) ;
F_25 ( & V_33 ,
V_34 ) ;
F_26 ( & V_32 ) ;
}
