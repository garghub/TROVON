static int F_1 ( struct V_1 * V_2 , void * V_3 , T_1 V_4 , bool V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 , struct V_6 , V_8 ) ;
unsigned int V_9 = V_4 ;
while ( V_9 >= 8 ) {
* ( ( V_10 * ) V_3 ) = F_3 ( V_7 -> V_11 ) ;
V_9 -= 8 ;
V_3 += 8 ;
}
while ( V_9 > 0 ) {
* ( ( V_12 * ) V_3 ) = F_4 ( V_7 -> V_11 ) ;
V_9 -- ;
V_3 ++ ;
}
return V_4 ;
}
static int F_5 ( struct V_13 * V_14 ,
const struct V_15 * V_16 )
{
struct V_6 * V_2 ;
int V_17 ;
V_2 = F_6 ( & V_14 -> V_18 , sizeof( * V_2 ) , V_19 ) ;
if ( ! V_2 )
return - V_20 ;
V_2 -> V_11 = F_7 ( V_14 , 0 , 0 ) ;
if ( ! V_2 -> V_11 ) {
F_8 ( & V_14 -> V_18 , L_1 ) ;
return - V_20 ;
}
V_2 -> V_8 . V_21 = L_2 ;
V_2 -> V_8 . V_22 = F_1 ;
V_2 -> V_8 . V_23 = 1000 ;
F_9 ( V_14 , V_2 ) ;
V_17 = F_10 ( & V_2 -> V_8 ) ;
if ( V_17 ) {
F_8 ( & V_14 -> V_18 , L_3 ) ;
return V_17 ;
}
return 0 ;
}
void F_11 ( struct V_13 * V_14 )
{
struct V_6 * V_2 ;
V_2 = F_12 ( V_14 ) ;
F_13 ( & V_2 -> V_8 ) ;
}
