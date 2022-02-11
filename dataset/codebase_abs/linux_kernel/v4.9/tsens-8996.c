static int F_1 ( struct V_1 * V_2 , int V_3 , int * V_4 )
{
struct V_5 * V_6 = & V_2 -> V_7 [ V_3 ] ;
T_1 V_8 ;
unsigned int V_9 ;
int V_10 = 0 , V_11 = 0 , V_12 = 0 , V_13 ;
V_9 = V_14 + V_6 -> V_15 * 4 ;
V_13 = F_2 ( V_2 -> V_16 , V_9 , & V_8 ) ;
if ( V_13 )
return V_13 ;
V_10 = V_8 & V_17 ;
if ( V_8 & V_18 )
goto V_19;
V_13 = F_2 ( V_2 -> V_16 , V_9 , & V_8 ) ;
if ( V_13 )
return V_13 ;
if ( V_8 & V_18 ) {
V_10 = V_8 & V_17 ;
goto V_19;
} else {
V_11 = V_8 & V_17 ;
}
V_13 = F_2 ( V_2 -> V_16 , V_9 , & V_8 ) ;
if ( V_13 )
return V_13 ;
if ( V_8 & V_18 ) {
V_10 = V_8 & V_17 ;
goto V_19;
} else {
V_12 = V_8 & V_17 ;
}
if ( V_10 == V_11 )
V_10 = V_11 ;
else if ( V_11 == V_12 )
V_10 = V_12 ;
V_19:
if ( V_10 & V_20 )
V_10 |= ~ V_20 ;
* V_4 = V_10 * 100 ;
return 0 ;
}
