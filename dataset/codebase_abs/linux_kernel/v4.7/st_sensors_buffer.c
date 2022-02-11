int F_1 ( struct V_1 * V_2 , T_1 * V_3 )
{
int V_4 , V_5 ;
int V_6 = 0 ;
struct V_7 * V_8 = F_2 ( V_2 ) ;
unsigned int V_9 = V_8 -> V_9 ;
for ( V_4 = 0 ; V_4 < V_9 ; V_4 ++ ) {
unsigned int V_10 ;
if ( F_3 ( V_4 , V_2 -> V_11 ) ) {
V_10 = V_2 -> V_12 [ V_4 ] . V_13 . V_14 >> 3 ;
V_5 = V_8 -> V_15 -> V_16 ( & V_8 -> V_17 ,
V_8 -> V_18 , V_2 -> V_12 [ V_4 ] . V_19 ,
V_10 ,
V_3 + V_6 , V_8 -> V_20 ) ;
if ( V_5 < V_10 )
return - V_21 ;
V_6 += V_5 ;
}
}
return V_6 ;
}
T_2 F_4 ( int V_22 , void * V_23 )
{
int V_5 ;
struct V_24 * V_25 = V_23 ;
struct V_1 * V_2 = V_25 -> V_2 ;
struct V_7 * V_8 = F_2 ( V_2 ) ;
T_3 V_26 ;
if ( V_8 -> V_27 )
V_26 = V_8 -> V_28 ;
else
V_26 = F_5 () ;
V_5 = F_1 ( V_2 , V_8 -> V_29 ) ;
if ( V_5 < 0 )
goto V_30;
F_6 ( V_2 , V_8 -> V_29 ,
V_26 ) ;
V_30:
F_7 ( V_2 -> V_31 ) ;
return V_32 ;
}
