static int F_1 ( struct V_1 * V_2 ,
struct V_3 const * V_4 ,
int * V_5 ,
int * V_6 ,
long V_7 )
{
int V_8 ;
struct V_9 * V_10 = F_2 ( V_2 ) ;
F_3 ( & V_10 -> V_11 ) ;
V_8 = F_4 ( V_10 -> V_12 , V_10 -> V_13 , 2 ) ;
if ( V_8 )
goto V_14;
* V_5 = ( ( ( V_15 ) ( V_10 -> V_13 [ 0 ] ) ) << 4 ) | ( ( V_10 -> V_13 [ 1 ] & 0xF0 ) >> 4 ) ;
V_14:
F_5 ( & V_10 -> V_11 ) ;
return V_16 ;
}
static int T_1 F_6 ( struct V_17 * V_18 )
{
struct V_1 * V_2 ;
struct V_9 * V_10 ;
int V_8 = 0 ;
V_2 = F_7 ( sizeof( * V_10 ) ) ;
if ( V_2 == NULL ) {
V_8 = - V_19 ;
goto V_14;
}
V_10 = F_2 ( V_2 ) ;
F_8 ( V_18 , V_2 ) ;
F_9 ( & V_10 -> V_11 ) ;
V_10 -> V_12 = V_18 ;
V_2 -> V_20 . V_21 = & V_18 -> V_20 ;
V_2 -> V_22 = & V_23 ;
V_2 -> V_24 = V_25 ;
V_2 -> V_26 = & V_27 ;
V_2 -> V_28 = 1 ;
V_2 -> V_29 = F_10 ( V_18 ) -> V_29 ;
V_8 = F_11 ( V_2 ) ;
if ( V_8 )
goto V_30;
V_18 -> V_31 = 830000 ;
V_18 -> V_32 = V_33 ;
F_12 ( V_18 ) ;
return 0 ;
V_30:
F_13 ( V_2 ) ;
V_14:
return V_8 ;
}
static int T_2 F_14 ( struct V_17 * V_18 )
{
F_15 ( F_16 ( V_18 ) ) ;
F_13 ( F_16 ( V_18 ) ) ;
return 0 ;
}
static T_3 int F_17 ( void )
{
return F_18 ( & V_34 ) ;
}
static T_4 void F_19 ( void )
{
F_20 ( & V_34 ) ;
}
