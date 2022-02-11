static int F_1 ( struct V_1 * V_2 , int V_3 )
{
char * V_4 [ 5 ] ;
int V_5 ;
F_2 ( & V_2 -> V_6 ) ;
V_4 [ 0 ] = F_3 ( V_7 , L_1 , V_2 -> type ) ;
V_4 [ 1 ] = F_3 ( V_7 , L_2 , V_2 -> V_8 ) ;
V_4 [ 2 ] = F_3 ( V_7 , L_3 , V_3 ) ;
V_4 [ 3 ] = F_3 ( V_7 , L_4 , V_2 -> V_9 ) ;
V_4 [ 4 ] = NULL ;
F_4 ( & V_2 -> V_10 . V_11 , V_12 , V_4 ) ;
for ( V_5 = 0 ; V_5 < 4 ; ++ V_5 )
F_5 ( V_4 [ V_5 ] ) ;
F_6 ( & V_2 -> V_6 ) ;
return 0 ;
}
int F_7 ( void )
{
return F_8 ( & V_13 ) ;
}
void F_9 ( void )
{
F_10 ( & V_13 ) ;
}
