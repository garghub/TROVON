static int F_1 ( struct V_1 * V_1 , int V_2 )
{
return F_2 ( V_3 , V_1 , V_2 ) ;
}
static int F_3 ( struct V_1 * V_1 , int V_2 )
{
return F_2 ( V_4 , V_1 , V_2 ) ;
}
static int F_4 ( void )
{
F_5 ( V_5 , F_6 ( V_5 ) ) ;
return 0 ;
}
static void F_7 ( void )
{
F_8 ( V_5 , F_6 ( V_5 ) ) ;
}
void T_1 F_9 ( void )
{
int V_6 ;
V_7 [ 4 ] = NULL ;
V_7 [ 6 ] = & V_8 . V_1 ;
V_9 [ 0 ] = & V_8 . V_1 ;
V_10 . V_11 . V_12 = V_13 ;
V_10 . V_11 . V_14 = 12 ;
V_10 . V_11 . V_15 = 1 ;
for ( V_6 = 0 ; V_6 < F_6 ( V_16 ) ; V_6 ++ )
F_10 ( V_16 [ V_6 ] , 1 ) ;
F_10 ( V_17 , F_6 ( V_17 ) ) ;
F_11 ( V_18 , F_6 ( V_18 ) ) ;
F_12 ( V_18 , F_6 ( V_18 ) ) ;
F_13 ( & V_19 ) ;
}
