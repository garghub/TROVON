int F_1 ( struct V_1 * V_2 )
{
T_1 V_3 ;
int V_4 ;
for ( V_3 = 0 ; V_3 < V_5 ; V_3 ++ ) {
F_2 ( V_2 , V_6 ,
V_7 ) ;
V_4 = F_3 ( V_2 , V_6 ,
V_7 ,
V_7 ,
V_8 ) ;
if ( V_4 >= 0 ) {
F_4 ( V_2 ,
L_1 ,
V_3 + 1 ) ;
return V_4 ;
}
}
return V_4 ;
}
void F_5 ( struct V_1 * V_2 )
{
F_6 ( V_2 , V_6 ,
V_7 ) ;
}
int F_7 ( struct V_1 * V_2 )
{
T_1 V_9 ;
T_1 V_10 ;
V_9 = F_8 ( V_2 , V_11 ) ;
V_10 = F_8 ( V_2 ,
V_12 ) ;
if ( V_9 < V_2 -> V_13 -> V_9 ||
V_10 < V_2 -> V_13 -> V_14 )
goto V_15;
F_9 ( V_2 , L_2 ,
V_9 , V_10 ) ;
return 0 ;
V_15:
F_10 ( V_2 , L_3
L_4 ,
V_9 , V_2 -> V_13 -> V_9 ,
V_10 , V_2 -> V_13 -> V_14 ) ;
return - V_16 ;
}
void F_11 ( const struct V_1 * V_2 , T_2 * V_17 )
{
const T_2 * V_18 = F_12 ( V_2 ,
V_19 ) ;
memcpy ( V_17 , V_18 , V_20 ) ;
}
