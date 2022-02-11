static unsigned long T_1 F_1 ( unsigned long V_1 )
{
if ( F_2 ( F_3 ( V_1 ) ) )
return V_2 [ F_4 ( V_1 ) ] ( V_1 ) ;
return true ;
}
static void T_1 F_5 ( T_2 V_3 ,
struct V_4 * V_5 ,
struct V_6 * V_7 )
{
V_7 -> V_8 += 2 ;
V_5 -> V_9 ( V_3 , V_5 , V_7 ) ;
V_7 -> V_10 = F_6 ( V_7 -> V_10 ) ;
}
static void T_1 F_7 ( T_2 V_3 ,
struct V_4 * V_5 ,
struct V_6 * V_7 )
{
V_7 -> V_8 += 4 ;
V_5 -> V_9 ( V_3 , V_5 , V_7 ) ;
V_7 -> V_10 = F_6 ( V_7 -> V_10 ) ;
}
enum V_11 T_1
F_8 ( T_2 V_12 , struct V_4 * V_5 ,
bool V_13 , const union V_14 * V_15 )
{
V_5 -> V_16 = F_5 ;
V_5 -> V_17 = F_1 ;
return F_9 ( V_12 , V_5 , V_18 , true ,
V_13 , V_15 ) ;
}
enum V_11 T_1
F_10 ( T_2 V_12 , struct V_4 * V_5 ,
bool V_13 , const union V_14 * V_15 )
{
V_5 -> V_16 = F_7 ;
V_5 -> V_17 = F_1 ;
return F_9 ( V_12 , V_5 , V_19 , true ,
V_13 , V_15 ) ;
}
