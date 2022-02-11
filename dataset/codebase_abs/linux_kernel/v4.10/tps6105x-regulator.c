static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = F_2 ( & V_2 -> V_4 ) ;
struct V_5 * V_6 = V_3 -> V_6 ;
struct V_7 V_8 = { } ;
int V_9 ;
if ( V_6 -> V_10 != V_11 ) {
F_3 ( & V_2 -> V_4 ,
L_1 ) ;
return 0 ;
}
V_8 . V_4 = & V_3 -> V_12 -> V_4 ;
V_8 . V_13 = V_6 -> V_14 ;
V_8 . V_15 = V_3 ;
V_8 . V_16 = V_3 -> V_16 ;
V_3 -> V_17 = F_4 ( & V_2 -> V_4 ,
& V_18 ,
& V_8 ) ;
if ( F_5 ( V_3 -> V_17 ) ) {
V_9 = F_6 ( V_3 -> V_17 ) ;
F_7 ( & V_3 -> V_12 -> V_4 ,
L_2 ) ;
return V_9 ;
}
F_8 ( V_2 , V_3 ) ;
return 0 ;
}
static T_1 int F_9 ( void )
{
return F_10 ( & V_19 ) ;
}
static T_2 void F_11 ( void )
{
F_12 ( & V_19 ) ;
}
