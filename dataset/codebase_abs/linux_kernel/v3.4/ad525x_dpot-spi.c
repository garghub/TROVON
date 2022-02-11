static int F_1 ( void * V_1 , T_1 V_2 )
{
T_1 V_3 = V_2 ;
return F_2 ( V_1 , & V_3 , 1 ) ;
}
static int F_3 ( void * V_1 , T_1 V_4 , T_1 V_2 )
{
T_1 V_3 [ 2 ] = { V_4 , V_2 } ;
return F_2 ( V_1 , V_3 , 2 ) ;
}
static int F_4 ( void * V_1 , T_1 V_4 , T_2 V_2 )
{
T_1 V_3 [ 3 ] = { V_4 , V_2 >> 8 , V_2 } ;
return F_2 ( V_1 , V_3 , 3 ) ;
}
static int F_5 ( void * V_1 )
{
int V_5 ;
T_1 V_3 ;
V_5 = F_6 ( V_1 , & V_3 , 1 ) ;
if ( V_5 < 0 )
return V_5 ;
return V_3 ;
}
static int F_7 ( void * V_1 , T_1 V_4 )
{
int V_5 ;
T_1 V_6 [ 2 ] ;
F_3 ( V_1 , V_4 , 0 ) ;
V_5 = F_6 ( V_1 , V_6 , 2 ) ;
if ( V_5 < 0 )
return V_5 ;
return ( V_6 [ 0 ] << 8 ) | V_6 [ 1 ] ;
}
static int F_8 ( void * V_1 , T_1 V_4 )
{
int V_5 ;
T_1 V_6 [ 3 ] ;
F_4 ( V_1 , V_4 , 0 ) ;
V_5 = F_6 ( V_1 , V_6 , 3 ) ;
if ( V_5 < 0 )
return V_5 ;
return ( V_6 [ 1 ] << 8 ) | V_6 [ 2 ] ;
}
static int T_3 F_9 ( struct V_7 * V_8 )
{
struct V_9 V_10 = {
. V_1 = V_8 ,
. V_11 = & V_11 ,
} ;
return F_10 ( & V_8 -> V_12 , & V_10 ,
F_11 ( V_8 ) -> V_13 ,
F_11 ( V_8 ) -> V_14 ) ;
}
static int T_4 F_12 ( struct V_7 * V_8 )
{
return F_13 ( & V_8 -> V_12 ) ;
}
