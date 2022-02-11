T_1
int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
enum V_7 V_8 ,
enum V_7 V_9 )
{
int V_10 = 0 ;
F_2 () ;
V_4 = F_3 ( V_4 ) ;
if ( ! F_4 ( V_4 ) )
return - V_11 ;
F_5 ( V_2 , V_4 , & V_6 -> V_6 , V_8 , V_9 ) ;
if ( V_2 -> V_12 -> V_13 ) {
V_10 = V_2 -> V_12 -> V_13 ( & V_2 -> V_14 , & V_4 -> V_15 , & V_6 -> V_6 ,
V_8 , V_9 ) ;
} else if ( V_8 == V_16 &&
V_9 == V_17 ) {
V_10 = F_6 ( V_2 , V_4 , & V_6 -> V_6 ) ;
if ( V_10 == 0 )
V_6 -> V_18 = true ;
} else if ( V_8 == V_17 &&
V_9 == V_16 ) {
F_7 ( V_2 , V_4 , & V_6 -> V_6 ) ;
}
F_8 ( V_2 , V_10 ) ;
return V_10 ;
}
