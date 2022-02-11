static int F_1 ( struct V_1 * V_2 )
{
int V_3 ;
int V_4 ;
struct V_5 * V_6 = V_2 -> V_7 . V_8 ;
struct V_9 V_10 = { 0 } ;
if ( ! V_6 )
return - V_11 ;
V_4 = V_6 -> V_4 ;
V_3 = F_2 ( V_4 ) ;
if ( V_3 >= 0 ) {
int V_12 ;
V_10 . V_3 = V_3 ;
V_10 . V_13 = V_4 ;
V_10 . V_14 = 1 ;
V_12 = F_3 ( NULL , V_4 , & V_10 ) ;
if ( V_12 )
return V_12 ;
} else {
F_4 ( & V_2 -> V_7 , L_1 ,
V_4 ) ;
return - V_11 ;
}
return 0 ;
}
static int T_1 F_5 ( void )
{
if ( F_6 () == V_15 ) {
V_16 . V_7 . V_8 = & V_17 ;
return F_7 ( & V_16 ) ;
}
return - V_18 ;
}
