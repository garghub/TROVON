static int T_1 F_1 ( void )
{
int V_1 ;
V_1 = F_2 ( & V_2 ) ;
if ( V_1 < 0 )
return V_1 ;
V_1 = F_2 ( & V_3 ) ;
if ( V_1 < 0 ) {
F_3 ( & V_2 ) ;
return V_1 ;
}
return 0 ;
}
static void T_2 F_4 ( void )
{
F_3 ( & V_3 ) ;
F_3 ( & V_2 ) ;
}
static int F_5 ( struct V_4 * V_5 )
{
struct V_6 * V_7 = & V_5 -> V_7 ;
F_6 ( V_5 , TRUE , TRUE ) ;
V_7 -> V_8 . V_9 &= V_10 | V_11 | V_12 | V_13 | V_14 ;
if ( V_5 -> V_15 -> type == V_16 )
V_7 -> V_8 . V_9 &= ~ V_12 ;
V_7 -> V_17 . V_9 = 0x7f ;
F_7 ( V_7 ) ;
return 0 ;
}
static int F_8 ( struct V_4 * V_5 )
{
F_6 ( V_5 , FALSE , FALSE ) ;
return 0 ;
}
static int F_9 ( struct V_4 * V_5 , unsigned V_18 )
{
int V_1 = 0 ;
int V_19 = 0 ;
F_10 ( 4 , L_1 , V_20 ,
V_18 , V_5 -> V_18 ) ;
for ( V_19 = 0 ; V_19 < V_21 ; V_19 ++ ) {
if ( V_18 == V_22 [ V_19 ] ) {
V_5 -> V_18 = V_18 ;
break;
}
F_6 ( V_5 , TRUE , FALSE ) ;
F_11 ( V_23 ) ;
F_6 ( V_5 , TRUE , TRUE ) ;
F_11 ( V_23 ) ;
}
if ( V_19 >= V_21 ) {
F_12 ( V_5 ) ;
V_1 = - V_24 ;
}
return V_1 ;
}
static int F_12 ( struct V_4 * V_5 )
{
F_6 ( V_5 , FALSE , TRUE ) ;
F_11 ( V_23 ) ;
F_6 ( V_5 , TRUE , TRUE ) ;
V_5 -> V_18 = 9600 ;
return 0 ;
}
