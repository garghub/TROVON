int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
unsigned int V_5 , unsigned int V_6 ,
enum V_7 V_8 )
{
unsigned int V_9 , V_10 ;
unsigned int V_11 , V_12 , V_13 ;
void * V_14 ;
int V_15 ;
V_2 -> V_16 = F_2 ( V_5 * sizeof( * V_2 -> V_16 ) , V_17 ) ;
if ( ! V_2 -> V_16 ) {
V_15 = - V_18 ;
goto error;
}
V_6 = F_3 ( V_6 ) ;
V_9 = V_19 / V_6 ;
if ( F_4 ( ! V_9 ) ) {
V_15 = - V_20 ;
goto error;
}
V_10 = F_5 ( V_5 , V_9 ) ;
V_15 = F_6 ( & V_2 -> V_21 , F_7 ( V_4 ) -> V_22 ,
V_10 , V_8 ) ;
if ( V_15 < 0 )
goto V_23;
for ( V_11 = 0 ; V_11 < V_5 ; ++ V_11 ) {
V_12 = V_11 / V_9 ;
V_14 = F_8 ( V_2 -> V_21 . V_10 [ V_12 ] ) ;
V_13 = ( V_11 % V_9 ) * V_6 ;
V_2 -> V_16 [ V_11 ] . V_24 = V_14 + V_13 ;
V_2 -> V_16 [ V_11 ] . V_25 = V_12 * V_19 + V_13 ;
}
return 0 ;
V_23:
F_9 ( V_2 -> V_16 ) ;
error:
return V_15 ;
}
void F_10 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
F_11 ( & V_2 -> V_21 , F_7 ( V_4 ) -> V_22 ) ;
F_9 ( V_2 -> V_16 ) ;
}
