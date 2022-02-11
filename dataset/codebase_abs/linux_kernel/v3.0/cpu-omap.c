static int F_1 ( struct V_1 * V_2 )
{
if ( V_3 )
return F_2 ( V_2 , V_3 ) ;
if ( V_2 -> V_4 )
return - V_5 ;
F_3 ( V_2 , V_2 -> V_6 . V_7 ,
V_2 -> V_6 . V_8 ) ;
V_2 -> V_9 = F_4 ( V_10 , V_2 -> V_9 * 1000 ) / 1000 ;
V_2 -> V_11 = F_4 ( V_10 , V_2 -> V_11 * 1000 ) / 1000 ;
F_3 ( V_2 , V_2 -> V_6 . V_7 ,
V_2 -> V_6 . V_8 ) ;
return 0 ;
}
static unsigned int F_5 ( unsigned int V_4 )
{
unsigned long V_12 ;
if ( V_4 )
return 0 ;
V_12 = F_6 ( V_10 ) / 1000 ;
return V_12 ;
}
static int F_7 ( struct V_1 * V_2 ,
unsigned int V_13 ,
unsigned int V_14 )
{
struct V_15 V_16 ;
int V_17 = 0 ;
if ( V_13 < V_2 -> V_9 )
V_13 = V_2 -> V_9 ;
if ( V_13 > V_2 -> V_11 )
V_13 = V_2 -> V_11 ;
V_16 . V_18 = F_5 ( 0 ) ;
V_16 . V_19 = F_4 ( V_10 , V_13 * 1000 ) / 1000 ;
V_16 . V_4 = 0 ;
if ( V_16 . V_18 == V_16 . V_19 )
return V_17 ;
F_8 ( & V_16 , V_20 ) ;
#ifdef F_9
F_10 ( V_21 L_1 ,
V_16 . V_18 , V_16 . V_19 ) ;
#endif
V_17 = F_11 ( V_10 , V_16 . V_19 * 1000 ) ;
F_8 ( & V_16 , V_22 ) ;
return V_17 ;
}
static int T_1 F_12 ( struct V_1 * V_2 )
{
int V_23 = 0 ;
V_10 = F_13 ( NULL , V_24 ) ;
if ( F_14 ( V_10 ) )
return F_15 ( V_10 ) ;
if ( V_2 -> V_4 != 0 )
return - V_5 ;
V_2 -> V_25 = V_2 -> V_9 = V_2 -> V_11 = F_5 ( 0 ) ;
F_16 ( & V_3 ) ;
if ( V_3 ) {
V_23 = F_17 ( V_2 , V_3 ) ;
if ( ! V_23 )
F_18 ( V_3 ,
V_2 -> V_4 ) ;
} else {
V_2 -> V_6 . V_7 = F_4 ( V_10 , 0 ) / 1000 ;
V_2 -> V_6 . V_8 = F_4 ( V_10 ,
V_26 ) / 1000 ;
}
V_2 -> V_6 . V_27 = 300 * 1000 ;
return 0 ;
}
static int F_19 ( struct V_1 * V_2 )
{
F_20 ( & V_3 ) ;
F_21 ( V_10 ) ;
return 0 ;
}
static int T_2 F_22 ( void )
{
return F_23 ( & V_28 ) ;
}
