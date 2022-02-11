unsigned int
F_1 ( struct V_1 * V_2 , const struct V_3 * V_4 , int V_5 )
{
struct V_6 * V_7 ;
V_7 = F_2 ( V_4 ) ;
if ( ! V_7 )
return 0 ;
return F_3 ( V_2 , L_1 ,
( unsigned long long ) F_4 ( & V_7 [ V_5 ] . V_8 ) ,
( unsigned long long ) F_4 ( & V_7 [ V_5 ] . V_9 ) ) ;
}
static int F_5 ( struct V_10 * V_10 )
{
struct V_11 * V_12 ;
V_12 = F_6 ( V_13 , sizeof( V_13 ) ,
V_14 ) ;
if ( ! V_12 )
goto V_15;
V_12 [ 0 ] . V_16 = & V_10 -> V_4 . V_17 ;
if ( V_10 -> V_18 != & V_19 )
V_12 [ 0 ] . V_20 = NULL ;
V_10 -> V_4 . V_21 = F_7 ( V_10 , L_2 ,
V_12 ) ;
if ( ! V_10 -> V_4 . V_21 ) {
F_8 ( V_22 L_3 ) ;
goto V_23;
}
return 0 ;
V_23:
F_9 ( V_12 ) ;
V_15:
return - V_24 ;
}
static void F_10 ( struct V_10 * V_10 )
{
struct V_11 * V_12 ;
V_12 = V_10 -> V_4 . V_21 -> V_25 ;
F_11 ( V_10 -> V_4 . V_21 ) ;
F_9 ( V_12 ) ;
}
static int F_5 ( struct V_10 * V_10 )
{
return 0 ;
}
static void F_10 ( struct V_10 * V_10 )
{
}
int F_12 ( struct V_10 * V_10 )
{
V_10 -> V_4 . V_17 = V_26 ;
return F_5 ( V_10 ) ;
}
void F_13 ( struct V_10 * V_10 )
{
F_10 ( V_10 ) ;
}
int F_14 ( void )
{
int V_27 = F_15 ( & V_28 ) ;
if ( V_27 < 0 )
F_16 ( L_4 ) ;
return V_27 ;
}
void F_17 ( void )
{
F_18 ( & V_28 ) ;
}
