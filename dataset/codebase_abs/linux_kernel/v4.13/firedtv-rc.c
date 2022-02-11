int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 ;
int V_7 , V_8 ;
V_6 = F_2 () ;
if ( ! V_6 )
return - V_9 ;
V_2 -> V_10 = V_6 ;
V_6 -> V_11 = L_1 ;
V_6 -> V_4 . V_12 = V_4 ;
V_6 -> V_13 [ 0 ] = F_3 ( V_14 ) ;
V_6 -> V_15 = F_4 ( V_16 , sizeof( V_16 ) , V_17 ) ;
if ( ! V_6 -> V_15 ) {
V_8 = - V_9 ;
goto V_18;
}
V_6 -> V_19 = sizeof( V_16 [ 0 ] ) ;
V_6 -> V_20 = F_5 ( V_16 ) ;
for ( V_7 = 0 ; V_7 < F_5 ( V_16 ) ; V_7 ++ )
F_6 ( V_16 [ V_7 ] , V_6 -> V_21 ) ;
V_8 = F_7 ( V_6 ) ;
if ( V_8 )
goto V_22;
return 0 ;
V_22:
F_8 ( V_6 -> V_15 ) ;
V_18:
F_9 ( V_6 ) ;
return V_8 ;
}
void F_10 ( struct V_1 * V_2 )
{
F_11 ( & V_2 -> V_23 ) ;
F_8 ( V_2 -> V_10 -> V_15 ) ;
F_12 ( V_2 -> V_10 ) ;
}
void F_13 ( struct V_1 * V_2 , unsigned int V_24 )
{
struct V_5 * V_6 = V_2 -> V_10 ;
T_1 * V_15 = V_6 -> V_15 ;
if ( V_24 >= 0x0300 && V_24 <= 0x031f )
V_24 = V_15 [ V_24 - 0x0300 ] ;
else if ( V_24 >= 0x0340 && V_24 <= 0x0354 )
V_24 = V_15 [ V_24 - 0x0320 ] ;
else if ( V_24 >= 0x4501 && V_24 <= 0x451f )
V_24 = V_25 [ V_24 - 0x4501 ] ;
else if ( V_24 >= 0x4540 && V_24 <= 0x4542 )
V_24 = V_25 [ V_24 - 0x4521 ] ;
else {
F_14 ( V_2 -> V_3 ,
L_2 ,
V_24 ) ;
return;
}
F_15 ( V_6 , V_24 , 1 ) ;
F_16 ( V_6 ) ;
F_15 ( V_6 , V_24 , 0 ) ;
F_16 ( V_6 ) ;
}
