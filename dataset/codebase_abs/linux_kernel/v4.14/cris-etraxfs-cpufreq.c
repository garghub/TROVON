static unsigned int F_1 ( unsigned int V_1 )
{
T_1 V_2 ;
V_2 = F_2 ( V_3 , V_4 , V_5 ) ;
return V_2 . V_6 ? 200000 : 6000 ;
}
static int F_3 ( struct V_7 * V_8 , unsigned int V_9 )
{
T_1 V_2 ;
V_2 = F_2 ( V_3 , V_4 , V_5 ) ;
F_4 () ;
if ( V_10 [ V_9 ] . V_11 == 200000 )
V_2 . V_6 = 1 ;
else
V_2 . V_6 = 0 ;
F_5 ( V_3 , V_4 , V_5 , V_2 ) ;
F_6 () ;
return 0 ;
}
static int F_7 ( struct V_7 * V_8 )
{
return F_8 ( V_8 , V_10 , 1000000 ) ;
}
static int T_2 F_9 ( void )
{
int V_12 ;
V_12 = F_10 ( & V_13 ) ;
F_11 ( & V_14 ,
V_15 ) ;
return V_12 ;
}
static int
F_12 ( struct V_16 * V_17 , unsigned long V_18 ,
void * V_19 )
{
int V_20 ;
struct V_21 * V_22 = V_19 ;
if ( V_18 == V_23 ) {
T_3 V_24 =
F_2 ( V_25 , V_26 , V_27 ) ;
V_24 . V_28 = ( V_22 -> V_29 == 200000 ? 0 : 1 ) ;
if ( V_22 -> V_29 == 200000 )
for ( V_20 = 0 ; V_20 < 50000 ; V_20 ++ ) ;
F_5 ( V_25 , V_26 , V_27 , V_24 ) ;
}
return 0 ;
}
