static int F_1 ( struct V_1 * V_2 ,
unsigned int V_3 )
{
return F_2 ( V_4 , V_5 [ V_3 ] . V_6 * 1000 ) ;
}
static int F_3 ( struct V_1 * V_2 )
{
V_2 -> V_7 = V_4 ;
return F_4 ( V_2 , V_5 , 20 * 1000 ) ;
}
static int F_5 ( struct V_8 * V_9 )
{
int V_10 = 0 ;
V_5 = F_6 ( & V_9 -> V_11 ) ;
if ( ! V_5 ) {
F_7 ( L_1 ) ;
return - V_12 ;
}
V_4 = F_8 ( & V_9 -> V_11 , L_2 ) ;
if ( F_9 ( V_4 ) ) {
F_7 ( L_3 ) ;
return F_10 ( V_4 ) ;
}
F_11 ( L_4 ) ;
while ( V_5 [ V_10 ] . V_6 != V_13 ) {
F_11 ( L_5 , V_5 [ V_10 ] . V_6 / 1000 ) ;
V_10 ++ ;
}
return F_12 ( & V_14 ) ;
}
static int T_1 F_13 ( void )
{
return F_14 ( & V_15 ) ;
}
