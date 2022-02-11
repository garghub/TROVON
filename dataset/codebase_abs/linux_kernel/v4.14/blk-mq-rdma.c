int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , int V_5 )
{
const struct V_6 * V_7 ;
unsigned int V_8 , V_9 ;
for ( V_8 = 0 ; V_8 < V_2 -> V_10 ; V_8 ++ ) {
V_7 = F_2 ( V_4 , V_5 + V_8 ) ;
if ( ! V_7 )
goto V_11;
F_3 (cpu, mask)
V_2 -> V_12 [ V_9 ] = V_8 ;
}
return 0 ;
V_11:
return F_4 ( V_2 ) ;
}
