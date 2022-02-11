int F_1 ( struct V_1 * V_1 , unsigned int V_2 )
{
int V_3 ;
int V_4 ;
int V_5 ;
int V_6 ;
int V_7 ;
if ( V_2 == 0 || V_2 > V_8 ) {
return - V_9 ;
} else if ( V_2 == 1 ) {
V_5 = V_10 ;
V_6 = V_11 ;
V_7 = 1 ;
} else {
V_5 = V_12 ;
V_6 = V_13 ;
V_7 = V_8 ;
}
V_3 = V_5 ;
V_4 = V_5 + V_6 ;
F_2 (entry_index, mlxsw_sp->kvdl.usage, size) {
int V_14 ;
for ( V_14 = 0 ; V_14 < V_7 ; V_14 ++ )
F_3 ( V_3 + V_14 , V_1 -> V_15 . V_16 ) ;
return V_3 ;
}
return - V_17 ;
}
void F_4 ( struct V_1 * V_1 , int V_3 )
{
int V_7 ;
int V_14 ;
if ( V_3 < V_12 )
V_7 = 1 ;
else
V_7 = V_8 ;
for ( V_14 = 0 ; V_14 < V_7 ; V_14 ++ )
F_5 ( V_3 + V_14 , V_1 -> V_15 . V_16 ) ;
}
