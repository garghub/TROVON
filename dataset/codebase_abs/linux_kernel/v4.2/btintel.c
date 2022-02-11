int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
struct V_5 * V_6 ;
V_6 = F_2 ( V_2 , V_7 , 0 , NULL ,
V_8 ) ;
if ( F_3 ( V_6 ) ) {
int V_9 = F_4 ( V_6 ) ;
F_5 ( L_1 ,
V_2 -> V_10 , V_9 ) ;
return V_9 ;
}
if ( V_6 -> V_11 != sizeof( * V_4 ) ) {
F_5 ( L_2 , V_2 -> V_10 ) ;
F_6 ( V_6 ) ;
return - V_12 ;
}
V_4 = (struct V_3 * ) V_6 -> V_13 ;
if ( ! F_7 ( & V_4 -> V_14 , V_15 ) ) {
F_5 ( L_3 ,
V_2 -> V_10 , & V_4 -> V_14 ) ;
F_8 ( V_16 , & V_2 -> V_17 ) ;
}
F_6 ( V_6 ) ;
return 0 ;
}
int F_9 ( struct V_1 * V_2 , const T_1 * V_14 )
{
struct V_5 * V_6 ;
int V_9 ;
V_6 = F_2 ( V_2 , 0xfc31 , 6 , V_14 , V_8 ) ;
if ( F_3 ( V_6 ) ) {
V_9 = F_4 ( V_6 ) ;
F_5 ( L_4 ,
V_2 -> V_10 , V_9 ) ;
return V_9 ;
}
F_6 ( V_6 ) ;
return 0 ;
}
