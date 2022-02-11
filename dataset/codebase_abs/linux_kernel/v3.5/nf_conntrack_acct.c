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
V_10 -> V_4 . V_18 = F_7 ( V_10 , L_2 ,
V_12 ) ;
if ( ! V_10 -> V_4 . V_18 ) {
F_8 ( V_19 L_3 ) ;
goto V_20;
}
return 0 ;
V_20:
F_9 ( V_12 ) ;
V_15:
return - V_21 ;
}
static void F_10 ( struct V_10 * V_10 )
{
struct V_11 * V_12 ;
V_12 = V_10 -> V_4 . V_18 -> V_22 ;
F_11 ( V_10 -> V_4 . V_18 ) ;
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
int V_23 ;
V_10 -> V_4 . V_17 = V_24 ;
if ( F_13 ( V_10 , & V_25 ) ) {
V_23 = F_14 ( & V_26 ) ;
if ( V_23 < 0 ) {
F_8 ( V_19 L_4 ) ;
goto V_27;
}
}
V_23 = F_5 ( V_10 ) ;
if ( V_23 < 0 )
goto V_28;
return 0 ;
V_28:
if ( F_13 ( V_10 , & V_25 ) )
F_15 ( & V_26 ) ;
V_27:
return V_23 ;
}
void F_16 ( struct V_10 * V_10 )
{
F_10 ( V_10 ) ;
if ( F_13 ( V_10 , & V_25 ) )
F_15 ( & V_26 ) ;
}
