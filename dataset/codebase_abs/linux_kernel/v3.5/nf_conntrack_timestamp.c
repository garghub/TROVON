static int F_1 ( struct V_1 * V_1 )
{
struct V_2 * V_3 ;
V_3 = F_2 ( V_4 , sizeof( V_4 ) ,
V_5 ) ;
if ( ! V_3 )
goto V_6;
V_3 [ 0 ] . V_7 = & V_1 -> V_8 . V_9 ;
V_1 -> V_8 . V_10 = F_3 ( V_1 , L_1 ,
V_3 ) ;
if ( ! V_1 -> V_8 . V_10 ) {
F_4 ( V_11 L_2 ) ;
goto V_12;
}
return 0 ;
V_12:
F_5 ( V_3 ) ;
V_6:
return - V_13 ;
}
static void F_6 ( struct V_1 * V_1 )
{
struct V_2 * V_3 ;
V_3 = V_1 -> V_8 . V_10 -> V_14 ;
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
int V_15 ;
V_1 -> V_8 . V_9 = V_16 ;
if ( F_9 ( V_1 , & V_17 ) ) {
V_15 = F_10 ( & V_18 ) ;
if ( V_15 < 0 ) {
F_4 ( V_11 L_3
L_4 ) ;
goto V_19;
}
}
V_15 = F_1 ( V_1 ) ;
if ( V_15 < 0 )
goto V_20;
return 0 ;
V_20:
if ( F_9 ( V_1 , & V_17 ) )
F_11 ( & V_18 ) ;
V_19:
return V_15 ;
}
void F_12 ( struct V_1 * V_1 )
{
F_6 ( V_1 ) ;
if ( F_9 ( V_1 , & V_17 ) )
F_11 ( & V_18 ) ;
}
