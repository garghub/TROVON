static unsigned int F_1 ( unsigned int V_1 )
{
T_1 V_2 ;
V_2 = F_2 ( V_3 , V_4 , V_5 ) ;
return V_2 . V_6 ? 200000 : 6000 ;
}
static void F_3 ( struct V_7 * V_8 ,
unsigned int V_9 )
{
struct V_10 V_11 ;
T_1 V_2 ;
V_2 = F_2 ( V_3 , V_4 , V_5 ) ;
V_11 . V_12 = F_1 ( V_8 -> V_1 ) ;
V_11 . V_13 = V_14 [ V_9 ] . V_15 ;
F_4 ( V_8 , & V_11 , V_16 ) ;
F_5 () ;
if ( V_14 [ V_9 ] . V_15 == 200000 )
V_2 . V_6 = 1 ;
else
V_2 . V_6 = 0 ;
F_6 ( V_3 , V_4 , V_5 , V_2 ) ;
F_7 () ;
F_4 ( V_8 , & V_11 , V_17 ) ;
}
static int F_8 ( struct V_7 * V_8 )
{
return F_9 ( V_8 , & V_14 [ 0 ] ) ;
}
static int F_10 ( struct V_7 * V_8 ,
unsigned int V_18 , unsigned int V_19 )
{
unsigned int V_20 = 0 ;
if ( F_11
( V_8 , V_14 , V_18 , V_19 , & V_20 ) )
return - V_21 ;
F_3 ( V_8 , V_20 ) ;
return 0 ;
}
static int F_12 ( struct V_7 * V_8 )
{
int V_22 ;
V_8 -> V_23 . V_24 = 1000000 ;
V_8 -> V_25 = F_1 ( 0 ) ;
V_22 = F_13 ( V_8 , V_14 ) ;
if ( V_22 )
return ( V_22 ) ;
F_14 ( V_14 , V_8 -> V_1 ) ;
return 0 ;
}
static int F_15 ( struct V_7 * V_8 )
{
F_16 ( V_8 -> V_1 ) ;
return 0 ;
}
static int T_2 F_17 ( void )
{
int V_26 ;
V_26 = F_18 ( & V_27 ) ;
F_19 ( & V_28 ,
V_29 ) ;
return V_26 ;
}
static int
F_20 ( struct V_30 * V_31 , unsigned long V_32 ,
void * V_33 )
{
int V_34 ;
struct V_10 * V_11 = V_33 ;
if ( V_32 == V_16 ) {
T_3 V_35 =
F_2 ( V_36 , V_37 , V_38 ) ;
V_35 . V_39 = ( V_11 -> V_13 == 200000 ? 0 : 1 ) ;
if ( V_11 -> V_13 == 200000 )
for ( V_34 = 0 ; V_34 < 50000 ; V_34 ++ ) ;
F_6 ( V_36 , V_37 , V_38 , V_35 ) ;
}
return 0 ;
}
