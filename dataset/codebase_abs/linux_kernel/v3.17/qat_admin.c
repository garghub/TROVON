static int F_1 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_6 V_7 ;
struct V_8 V_9 ;
int V_10 ;
memset ( & V_7 , 0 , sizeof( struct V_6 ) ) ;
V_7 . V_11 = V_3 ;
for ( V_10 = 0 ; V_10 < V_5 -> V_12 ( V_5 ) ; V_10 ++ ) {
memset ( & V_9 , 0 , sizeof( struct V_8 ) ) ;
if ( F_2 ( V_2 , V_10 , & V_7 , & V_9 ) ||
V_9 . V_13 . V_14 )
return - V_15 ;
}
return 0 ;
}
static int F_3 ( struct V_1 * V_2 )
{
return F_1 ( V_2 , V_16 ) ;
}
static int F_4 ( struct V_1 * V_2 ,
enum V_17 V_18 )
{
int V_19 ;
switch ( V_18 ) {
case V_20 :
V_19 = F_3 ( V_2 ) ;
break;
case V_21 :
case V_22 :
case V_23 :
default:
V_19 = 0 ;
}
return V_19 ;
}
int F_5 ( void )
{
memset ( & V_24 , 0 , sizeof( struct V_25 ) ) ;
V_24 . V_26 = F_4 ;
V_24 . V_27 = L_1 ;
V_24 . V_28 = 1 ;
return F_6 ( & V_24 ) ;
}
int F_7 ( void )
{
return F_8 ( & V_24 ) ;
}
