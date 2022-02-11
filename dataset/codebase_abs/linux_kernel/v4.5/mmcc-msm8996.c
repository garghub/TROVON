static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_3 ;
struct V_4 * V_5 = & V_2 -> V_5 ;
int V_6 ;
struct V_7 * V_7 ;
V_7 = F_2 ( V_2 , & V_8 ) ;
if ( F_3 ( V_7 ) )
return F_4 ( V_7 ) ;
F_5 ( V_7 , 0x50d8 , F_6 ( 31 ) , 0 ) ;
F_5 ( V_7 , 0x5054 , F_6 ( 15 ) , 0 ) ;
for ( V_6 = 0 ; V_6 < F_7 ( V_9 ) ; V_6 ++ ) {
V_3 = F_8 ( V_5 , V_9 [ V_6 ] ) ;
if ( F_3 ( V_3 ) )
return F_4 ( V_3 ) ;
}
return F_9 ( V_2 , & V_8 , V_7 ) ;
}
