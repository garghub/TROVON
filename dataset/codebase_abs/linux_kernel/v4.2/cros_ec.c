int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
int V_5 = 0 ;
V_2 -> V_6 = sizeof( struct V_7 ) ;
V_2 -> V_8 = sizeof( struct V_9 ) ;
V_2 -> V_10 = 0 ;
V_2 -> V_11 = F_2 ( V_4 , V_2 -> V_12 , V_13 ) ;
if ( ! V_2 -> V_11 )
return - V_14 ;
V_2 -> V_15 = F_2 ( V_4 , V_2 -> V_16 , V_13 ) ;
if ( ! V_2 -> V_15 )
return - V_14 ;
F_3 ( & V_2 -> V_17 ) ;
F_4 ( V_2 ) ;
V_5 = F_5 ( V_2 -> V_4 , V_18 , & V_19 , 1 ,
NULL , V_2 -> V_20 , NULL ) ;
if ( V_5 ) {
F_6 ( V_4 ,
L_1 ,
V_5 ) ;
return V_5 ;
}
if ( V_2 -> V_10 ) {
V_5 = F_5 ( V_2 -> V_4 , V_18 ,
& V_21 , 1 , NULL , V_2 -> V_20 , NULL ) ;
if ( V_5 ) {
F_6 ( V_4 ,
L_2 ,
V_5 ) ;
return V_5 ;
}
}
if ( F_7 ( V_22 ) && V_4 -> V_23 ) {
V_5 = F_8 ( V_4 -> V_23 , NULL , NULL , V_4 ) ;
if ( V_5 ) {
F_9 ( V_4 ) ;
F_6 ( V_4 , L_3 ) ;
return V_5 ;
}
}
F_10 ( V_4 , L_4 ) ;
return 0 ;
}
int F_11 ( struct V_1 * V_2 )
{
F_9 ( V_2 -> V_4 ) ;
return 0 ;
}
int F_12 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
if ( F_13 ( V_4 ) )
V_2 -> V_24 = ! F_14 ( V_2 -> V_20 ) ;
F_15 ( V_2 -> V_20 ) ;
V_2 -> V_25 = V_2 -> V_24 ;
return 0 ;
}
int F_16 ( struct V_1 * V_2 )
{
F_17 ( V_2 -> V_20 ) ;
if ( V_2 -> V_24 ) {
F_18 ( V_2 -> V_20 ) ;
V_2 -> V_24 = 0 ;
}
return 0 ;
}
