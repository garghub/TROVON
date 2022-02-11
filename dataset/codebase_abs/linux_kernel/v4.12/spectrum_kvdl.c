int F_1 ( struct V_1 * V_1 , unsigned int V_2 ,
T_1 * V_3 )
{
int V_4 ;
int V_5 ;
int V_6 ;
int V_7 ;
int V_8 ;
if ( V_2 == 0 || V_2 > V_9 ) {
return - V_10 ;
} else if ( V_2 == 1 ) {
V_6 = V_11 ;
V_7 = V_12 ;
V_8 = 1 ;
} else {
V_6 = V_13 ;
V_7 = V_14 ;
V_8 = V_9 ;
}
V_4 = V_6 ;
V_5 = V_6 + V_7 ;
F_2 (entry_index, mlxsw_sp->kvdl.usage, size) {
int V_15 ;
for ( V_15 = 0 ; V_15 < V_8 ; V_15 ++ )
F_3 ( V_4 + V_15 , V_1 -> V_16 . V_17 ) ;
* V_3 = V_4 ;
return 0 ;
}
return - V_18 ;
}
void F_4 ( struct V_1 * V_1 , int V_4 )
{
int V_8 ;
int V_15 ;
if ( V_4 < V_13 )
V_8 = 1 ;
else
V_8 = V_9 ;
for ( V_15 = 0 ; V_15 < V_8 ; V_15 ++ )
F_5 ( V_4 + V_15 , V_1 -> V_16 . V_17 ) ;
}
