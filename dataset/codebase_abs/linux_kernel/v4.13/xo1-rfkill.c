static int F_1 ( void * V_1 , bool V_2 )
{
unsigned char V_3 ;
int V_4 ;
if ( V_2 == V_5 )
return 0 ;
if ( V_2 )
V_3 = V_6 ;
else
V_3 = V_7 ;
V_4 = F_2 ( V_3 , NULL , 0 , NULL , 0 ) ;
if ( V_4 == 0 )
V_5 = V_2 ;
return V_4 ;
}
static int F_3 ( struct V_8 * V_9 )
{
struct V_10 * V_11 ;
int V_4 ;
V_11 = F_4 ( V_9 -> V_12 , & V_9 -> V_13 , V_14 ,
& V_15 , NULL ) ;
if ( ! V_11 )
return - V_16 ;
V_4 = F_5 ( V_11 ) ;
if ( V_4 ) {
F_6 ( V_11 ) ;
return V_4 ;
}
F_7 ( V_9 , V_11 ) ;
return 0 ;
}
static int F_8 ( struct V_8 * V_9 )
{
struct V_10 * V_11 = F_9 ( V_9 ) ;
F_10 ( V_11 ) ;
F_6 ( V_11 ) ;
return 0 ;
}
