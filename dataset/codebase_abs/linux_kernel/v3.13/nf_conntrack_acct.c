unsigned int
F_1 ( struct V_1 * V_2 , const struct V_3 * V_4 , int V_5 )
{
struct V_6 * V_7 ;
struct V_8 * V_9 ;
V_7 = F_2 ( V_4 ) ;
if ( ! V_7 )
return 0 ;
V_9 = V_7 -> V_9 ;
return F_3 ( V_2 , L_1 ,
( unsigned long long ) F_4 ( & V_9 [ V_5 ] . V_10 ) ,
( unsigned long long ) F_4 ( & V_9 [ V_5 ] . V_11 ) ) ;
}
static int F_5 ( struct V_12 * V_12 )
{
struct V_13 * V_14 ;
V_14 = F_6 ( V_15 , sizeof( V_15 ) ,
V_16 ) ;
if ( ! V_14 )
goto V_17;
V_14 [ 0 ] . V_18 = & V_12 -> V_4 . V_19 ;
if ( V_12 -> V_20 != & V_21 )
V_14 [ 0 ] . V_22 = NULL ;
V_12 -> V_4 . V_23 = F_7 ( V_12 , L_2 ,
V_14 ) ;
if ( ! V_12 -> V_4 . V_23 ) {
F_8 ( V_24 L_3 ) ;
goto V_25;
}
return 0 ;
V_25:
F_9 ( V_14 ) ;
V_17:
return - V_26 ;
}
static void F_10 ( struct V_12 * V_12 )
{
struct V_13 * V_14 ;
V_14 = V_12 -> V_4 . V_23 -> V_27 ;
F_11 ( V_12 -> V_4 . V_23 ) ;
F_9 ( V_14 ) ;
}
static int F_5 ( struct V_12 * V_12 )
{
return 0 ;
}
static void F_10 ( struct V_12 * V_12 )
{
}
int F_12 ( struct V_12 * V_12 )
{
V_12 -> V_4 . V_19 = V_28 ;
return F_5 ( V_12 ) ;
}
void F_13 ( struct V_12 * V_12 )
{
F_10 ( V_12 ) ;
}
int F_14 ( void )
{
int V_29 = F_15 ( & V_30 ) ;
if ( V_29 < 0 )
F_16 ( L_4 ) ;
return V_29 ;
}
void F_17 ( void )
{
F_18 ( & V_30 ) ;
}
