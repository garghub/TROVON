int T_1 F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * * V_6 )
{
const char * V_7 ;
struct V_3 * V_8 ;
int V_9 , V_10 ;
V_8 = NULL ;
V_9 = 0 ;
while ( ( V_8 = F_2 ( V_4 , V_8 ) ) )
V_9 ++ ;
if ( V_9 == 0 )
return 0 ;
* V_6 = F_3 ( V_9 * sizeof( * * V_6 ) , V_11 ) ;
if ( ! * V_6 )
return - V_12 ;
V_8 = NULL ;
V_10 = 0 ;
while ( ( V_8 = F_2 ( V_4 , V_8 ) ) ) {
const T_2 * V_13 ;
int V_14 ;
V_13 = F_4 ( V_8 , L_1 , & V_14 ) ;
if ( ! V_13 ) {
V_9 -- ;
continue;
}
( * V_6 ) [ V_10 ] . V_15 = F_5 ( V_13 [ 0 ] ) ;
( * V_6 ) [ V_10 ] . V_16 = F_5 ( V_13 [ 1 ] ) ;
V_7 = F_4 ( V_8 , L_2 , & V_14 ) ;
if ( ! V_7 )
V_7 = F_4 ( V_8 , L_3 , & V_14 ) ;
( * V_6 ) [ V_10 ] . V_17 = ( char * ) V_7 ;
if ( F_4 ( V_8 , L_4 , & V_14 ) )
( * V_6 ) [ V_10 ] . V_18 = V_19 ;
V_10 ++ ;
}
if ( ! V_10 ) {
F_6 ( V_8 ) ;
F_7 ( V_2 , L_5 , V_4 -> V_20 ) ;
F_8 ( * V_6 ) ;
* V_6 = NULL ;
return - V_21 ;
}
return V_9 ;
}
