void F_1 ( void )
{
F_2 ( F_3 ( V_1 ) & 0x7fff , V_1 ) ;
}
void F_4 ( void )
{
F_2 ( 0xe310 , V_1 ) ;
}
static int F_5 ( struct V_2 * V_3 )
{
F_6 ( & V_4 ) ;
F_2 ( V_5 , V_6 ) ;
F_2 ( 0 , V_7 ) ;
F_4 () ;
F_7 ( & V_4 ) ;
return 0 ;
}
static int F_8 ( struct V_2 * V_3 )
{
if ( F_9 ( V_3 ) || F_10 ( V_3 ) ) {
F_6 ( & V_4 ) ;
F_1 () ;
F_7 ( & V_4 ) ;
}
return 0 ;
}
static T_1 F_11 ( int V_8 , void * V_9 )
{
T_2 V_10 ;
F_12 ( F_13 ( V_11 ) , & V_10 , & V_12 ) ;
F_2 ( F_3 ( V_1 ) | 0x4000 , V_1 ) ;
V_13 . V_14 ( & V_13 ) ;
return V_15 ;
}
void T_3 F_14 ( void )
{
T_2 V_10 ;
struct V_2 * V_16 = & V_13 ;
unsigned int V_17 = F_15 () ;
V_16 -> V_18 = F_16 ( V_17 ) ;
F_17 ( V_16 , V_19 ) ;
V_16 -> V_20 = F_18 ( 0xffff , V_16 ) ;
V_16 -> V_21 = 0xffff ;
V_16 -> V_22 = F_18 ( 0xf , V_16 ) ;
V_16 -> V_23 = 0xf ;
F_19 ( F_13 ( V_24 ) , 0 , 0x100 ) ;
F_19 ( F_13 ( V_25 ) , 0 , 0x50000 ) ;
F_12 ( F_13 ( V_11 ) , & V_10 , & V_12 ) ;
F_20 ( V_16 ) ;
F_21 ( V_26 , & V_27 ) ;
}
static T_4 F_22 ( struct V_28 * V_29 )
{
unsigned long V_30 ;
int V_31 ;
T_2 V_32 ;
static int V_33 ;
static T_2 V_34 ;
F_23 ( & V_4 , V_30 ) ;
V_32 = V_35 ;
V_31 = F_3 ( V_7 ) ;
if ( V_31 < V_33 && V_32 == V_34 )
V_31 = V_33 ;
V_33 = V_31 ;
V_34 = V_32 ;
F_24 ( & V_4 , V_30 ) ;
return ( T_4 ) ( V_32 * V_5 ) + V_31 ;
}
int T_3 F_25 ( void )
{
if ( F_26 () > 1 )
return 0 ;
return F_27 ( & V_36 , V_19 ) ;
}
