static int F_1 ( void * V_1 , bool V_2 )
{
unsigned char V_3 ;
if ( V_2 )
V_3 = V_4 ;
else
V_3 = V_5 ;
return F_2 ( V_3 , NULL , 0 , NULL , 0 ) ;
}
static int T_1 F_3 ( struct V_6 * V_7 )
{
struct V_8 * V_9 ;
int V_10 ;
V_9 = F_4 ( V_7 -> V_11 , & V_7 -> V_12 , V_13 ,
& V_14 , NULL ) ;
if ( ! V_9 )
return - V_15 ;
V_10 = F_5 ( V_9 ) ;
if ( V_10 ) {
F_6 ( V_9 ) ;
return V_10 ;
}
F_7 ( V_7 , V_9 ) ;
return 0 ;
}
static int T_2 F_8 ( struct V_6 * V_7 )
{
struct V_8 * V_9 = F_9 ( V_7 ) ;
F_10 ( V_9 ) ;
F_6 ( V_9 ) ;
return 0 ;
}
