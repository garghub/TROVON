enum V_1 F_1 ( T_1 V_2 ,
struct V_3 * V_4 ,
const struct V_5 * V_6 )
{
V_4 -> V_7 = 0 ;
return V_8 ;
}
enum V_1 F_2 ( T_1 V_2 ,
struct V_3 * V_4 ,
const struct V_5 * V_6 )
{
V_4 -> V_7 = - 1 ;
return V_8 ;
}
enum V_1 F_3 ( T_1 V_2 ,
struct V_3 * V_4 ,
const struct V_5 * V_6 )
{
int V_9 = V_2 & 0xff ;
V_4 -> V_7 = V_9 ;
return V_8 ;
}
enum V_1 F_4 ( T_1 V_2 ,
struct V_3 * V_4 ,
const struct V_5 * V_6 )
{
int V_9 = V_2 & 0xff ;
V_4 -> V_7 = V_9 << 2 ;
return V_8 ;
}
enum V_1 F_5 ( T_1 V_2 ,
struct V_3 * V_4 ,
const struct V_5 * V_6 )
{
int V_9 = ( ( V_2 & 0xf00 ) >> 4 ) + ( V_2 & 0xf ) ;
V_4 -> V_7 = V_9 ;
return V_8 ;
}
enum V_1 F_6 ( T_1 V_2 ,
struct V_3 * V_4 ,
const struct V_5 * V_6 )
{
int V_9 = V_2 & 0xfff ;
V_4 -> V_7 = V_9 ;
return V_8 ;
}
enum V_1 F_7 ( T_1 V_2 ,
struct V_3 * V_4 ,
const struct V_5 * V_6 )
{
unsigned int V_10 = V_2 & 0xffff ;
int V_11 = V_2 & ( 1 << 24 ) ;
V_4 -> V_7 = ( F_8 ( V_10 ) - ( ! V_11 ? 1 : 0 ) ) * 4 ;
return V_8 ;
}
