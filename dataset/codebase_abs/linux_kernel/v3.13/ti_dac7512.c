static T_1 F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_5 , T_2 V_6 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
unsigned char V_9 [ 2 ] ;
unsigned long V_10 ;
int V_11 ;
V_11 = F_3 ( V_5 , 10 , & V_10 ) ;
if ( V_11 )
return V_11 ;
V_9 [ 0 ] = V_10 >> 8 ;
V_9 [ 1 ] = V_10 & 0xff ;
F_4 ( V_8 , V_9 , sizeof( V_9 ) ) ;
return V_6 ;
}
static int F_5 ( struct V_7 * V_8 )
{
int V_11 ;
V_8 -> V_12 = 8 ;
V_8 -> V_13 = V_14 ;
V_11 = F_6 ( V_8 ) ;
if ( V_11 < 0 )
return V_11 ;
return F_7 ( & V_8 -> V_2 . V_15 , & V_16 ) ;
}
static int F_8 ( struct V_7 * V_8 )
{
F_9 ( & V_8 -> V_2 . V_15 , & V_16 ) ;
return 0 ;
}
