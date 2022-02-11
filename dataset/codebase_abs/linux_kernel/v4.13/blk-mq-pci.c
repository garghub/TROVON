int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
const struct V_5 * V_6 ;
unsigned int V_7 , V_8 ;
for ( V_7 = 0 ; V_7 < V_2 -> V_9 ; V_7 ++ ) {
V_6 = F_2 ( V_4 , V_7 ) ;
if ( ! V_6 )
goto V_10;
F_3 (cpu, mask)
V_2 -> V_11 [ V_8 ] = V_7 ;
}
return 0 ;
V_10:
F_4 ( V_2 -> V_9 > 1 ) ;
F_5 (cpu)
V_2 -> V_11 [ V_8 ] = 0 ;
return 0 ;
}
