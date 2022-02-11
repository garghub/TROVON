static unsigned int F_1 ( unsigned int V_1 )
{
T_1 V_2 ;
V_2 = F_2 ( V_3 , V_4 , V_5 ) ;
return V_2 . V_6 ? 200000 : 6000 ;
}
static void F_3 ( unsigned int V_7 )
{
int V_8 = 0 ;
struct V_9 V_10 ;
T_1 V_2 ;
V_2 = F_2 ( V_3 , V_4 , V_5 ) ;
#ifdef F_4
F_5 (i)
#endif
{
V_10 . V_11 = F_1 ( V_8 ) ;
V_10 . V_12 = V_13 [ V_7 ] . V_14 ;
V_10 . V_1 = V_8 ;
}
F_6 ( & V_10 , V_15 ) ;
F_7 () ;
if ( V_13 [ V_7 ] . V_14 == 200000 )
V_2 . V_6 = 1 ;
else
V_2 . V_6 = 0 ;
F_8 ( V_3 , V_4 , V_5 , V_2 ) ;
F_9 () ;
F_6 ( & V_10 , V_16 ) ;
}
static int F_10 ( struct V_17 * V_18 )
{
return F_11 ( V_18 , & V_13 [ 0 ] ) ;
}
static int F_12 ( struct V_17 * V_18 ,
unsigned int V_19 ,
unsigned int V_20 )
{
unsigned int V_21 = 0 ;
if ( F_13 ( V_18 , V_13 ,
V_19 , V_20 , & V_21 ) )
return - V_22 ;
F_3 ( V_21 ) ;
return 0 ;
}
static int F_14 ( struct V_17 * V_18 )
{
int V_23 ;
V_18 -> V_24 . V_25 = 1000000 ;
V_18 -> V_26 = F_1 ( 0 ) ;
V_23 = F_15 ( V_18 , V_13 ) ;
if ( V_23 )
return ( V_23 ) ;
F_16 ( V_13 , V_18 -> V_1 ) ;
return 0 ;
}
static int F_17 ( struct V_17 * V_18 )
{
F_18 ( V_18 -> V_1 ) ;
return 0 ;
}
static int T_2 F_19 ( void )
{
int V_27 ;
V_27 = F_20 ( & V_28 ) ;
F_21 ( & V_29 ,
V_30 ) ;
return V_27 ;
}
static int
F_22 ( struct V_31 * V_32 , unsigned long V_33 ,
void * V_34 )
{
int V_8 ;
struct V_9 * V_10 = V_34 ;
if ( V_33 == V_15 ) {
T_3 V_35 =
F_2 ( V_36 , V_37 , V_38 ) ;
V_35 . V_39 = ( V_10 -> V_12 == 200000 ? 1560 : 46 ) ;
if ( V_10 -> V_12 == 200000 )
for ( V_8 = 0 ; V_8 < 50000 ; V_8 ++ ) ;
F_8 ( V_40 , V_41 , V_42 , V_43 ) ;
}
return 0 ;
}
