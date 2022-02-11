static int F_1 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 ;
struct V_6 * V_7 ;
struct V_8 * V_9 ;
int V_10 ;
V_10 = F_2 ( V_2 -> V_2 -> V_11 , 0 , V_3 ,
& V_7 , & V_9 ) ;
if ( V_10 )
return V_10 ;
V_5 = F_3 ( V_2 -> V_2 , sizeof( * V_5 ) , V_12 ) ;
if ( ! V_5 )
return - V_13 ;
V_10 = F_4 ( V_2 , V_5 ,
& V_14 ,
V_15 , NULL ) ;
if ( V_10 )
return V_10 ;
V_5 -> V_16 = 0x1 ;
if ( V_7 ) {
V_9 = F_5 ( V_7 , V_17 ) ;
if ( F_6 ( V_9 ) )
return F_7 ( V_9 ) ;
}
if ( V_9 ) {
V_10 = F_8 ( V_5 , V_9 , NULL ) ;
if ( ! V_10 )
return 0 ;
if ( V_7 )
F_9 ( V_9 ) ;
}
F_10 ( V_5 ) ;
return V_10 ;
}
int F_11 ( struct V_1 * V_2 )
{
int V_3 , V_10 = 0 ;
for ( V_3 = 0 ; ! V_10 ; V_3 ++ )
V_10 = F_1 ( V_2 , V_3 ) ;
if ( V_10 == - V_18 && V_3 )
return 0 ;
return V_10 ;
}
