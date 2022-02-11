static int F_1 ( void * V_1 ,
unsigned int V_2 , const T_1 V_3 [] , T_2 V_4 )
{
T_1 * V_5 ;
int V_6 ;
V_5 = F_2 ( 2 + V_4 , V_7 | V_8 ) ;
if ( ! V_5 )
return - V_9 ;
F_3 ( V_2 , V_5 ) ;
memcpy ( V_5 + 2 , V_3 , V_4 ) ;
V_6 = F_4 ( V_1 , V_5 , V_4 + 2 ) ;
F_5 ( V_5 ) ;
return V_6 ;
}
static int F_6 ( void * V_1 ,
unsigned int V_2 , T_1 V_3 [] , T_2 V_4 )
{
struct V_10 * V_11 = V_1 ;
struct V_12 V_13 [ 2 ] ;
T_1 V_5 [ 2 ] ;
int V_6 ;
F_3 ( V_2 , V_5 ) ;
V_13 [ 0 ] . V_2 = V_11 -> V_2 ;
V_13 [ 0 ] . V_4 = sizeof( V_5 ) ;
V_13 [ 0 ] . V_5 = V_5 ;
V_13 [ 0 ] . V_14 = 0 ;
V_13 [ 1 ] . V_2 = V_11 -> V_2 ;
V_13 [ 1 ] . V_4 = V_4 ;
V_13 [ 1 ] . V_5 = V_3 ;
V_13 [ 1 ] . V_14 = V_15 ;
V_6 = F_7 ( V_11 -> V_16 , V_13 , F_8 ( V_13 ) ) ;
if ( V_6 < 0 )
return V_6 ;
else if ( V_6 != F_8 ( V_13 ) )
return - V_17 ;
return 0 ;
}
struct V_18 * F_9 ( struct V_10 * V_11 ,
const struct V_19 * V_20 , const char * V_21 )
{
struct V_18 * V_18 ;
V_18 = F_10 ( & V_11 -> V_22 , V_20 , V_21 ) ;
if ( F_11 ( V_18 ) )
return V_18 ;
V_18 -> V_1 = V_11 ;
V_18 -> V_23 = F_1 ;
V_18 -> V_24 = F_6 ;
return V_18 ;
}
