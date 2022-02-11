int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = V_4 -> V_6 ;
struct V_5 * V_7 = V_4 -> V_7 ;
struct V_5 * V_8 = V_4 -> V_8 ;
struct V_5 * V_9 = V_4 -> V_9 ;
struct V_10 * log ;
int V_11 = 0 ;
F_3 ( L_1 , V_2 ) ;
if ( ( log = V_4 -> log ) )
F_4 ( log , 2 ) ;
F_5 ( V_7 , 0 ) ;
F_6 ( V_7 ) ;
V_4 -> V_7 = NULL ;
V_9 = V_4 -> V_9 ;
if ( V_9 ) {
F_5 ( V_9 , 0 ) ;
F_6 ( V_9 ) ;
V_4 -> V_9 = NULL ;
}
V_8 = V_4 -> V_8 ;
F_5 ( V_8 , 0 ) ;
F_6 ( V_8 ) ;
V_4 -> V_8 = NULL ;
F_7 ( V_6 , 0 ) ;
F_6 ( V_6 ) ;
V_4 -> V_7 = NULL ;
F_8 ( V_4 -> V_12 -> V_13 ) ;
if ( log ) {
F_9 ( V_2 , V_14 ) ;
V_11 = F_10 ( V_2 ) ;
}
F_3 ( L_2 , V_11 ) ;
return V_11 ;
}
int F_11 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_10 * log = V_4 -> log ;
if ( ! log )
return 0 ;
F_4 ( log , 2 ) ;
F_12 ( V_4 -> V_6 ) ;
F_13 ( V_4 -> V_7 ) ;
F_8 ( V_4 -> V_12 -> V_13 ) ;
F_9 ( V_2 , V_14 ) ;
return F_10 ( V_2 ) ;
}
