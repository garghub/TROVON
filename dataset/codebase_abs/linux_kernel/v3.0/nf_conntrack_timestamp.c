static int F_1 ( struct V_1 * V_1 )
{
struct V_2 * V_3 ;
V_3 = F_2 ( V_4 , sizeof( V_4 ) ,
V_5 ) ;
if ( ! V_3 )
goto V_6;
V_3 [ 0 ] . V_7 = & V_1 -> V_8 . V_9 ;
V_1 -> V_8 . V_10 = F_3 ( V_1 ,
V_11 , V_3 ) ;
if ( ! V_1 -> V_8 . V_10 ) {
F_4 ( V_12 L_1 ) ;
goto V_13;
}
return 0 ;
V_13:
F_5 ( V_3 ) ;
V_6:
return - V_14 ;
}
static void F_6 ( struct V_1 * V_1 )
{
struct V_2 * V_3 ;
V_3 = V_1 -> V_8 . V_10 -> V_15 ;
F_7 ( V_1 -> V_8 . V_10 ) ;
F_5 ( V_3 ) ;
}
static int F_1 ( struct V_1 * V_1 )
{
return 0 ;
}
static void F_6 ( struct V_1 * V_1 )
{
}
int F_8 ( struct V_1 * V_1 )
{
int V_16 ;
V_1 -> V_8 . V_9 = V_17 ;
if ( F_9 ( V_1 , & V_18 ) ) {
V_16 = F_10 ( & V_19 ) ;
if ( V_16 < 0 ) {
F_4 ( V_12 L_2
L_3 ) ;
goto V_20;
}
}
V_16 = F_1 ( V_1 ) ;
if ( V_16 < 0 )
goto V_21;
return 0 ;
V_21:
if ( F_9 ( V_1 , & V_18 ) )
F_11 ( & V_19 ) ;
V_20:
return V_16 ;
}
void F_12 ( struct V_1 * V_1 )
{
F_6 ( V_1 ) ;
if ( F_9 ( V_1 , & V_18 ) )
F_11 ( & V_19 ) ;
}
