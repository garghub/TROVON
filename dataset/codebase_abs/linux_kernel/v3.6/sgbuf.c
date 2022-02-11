int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_1 V_6 ;
int V_7 ;
if ( ! V_4 )
return - V_8 ;
if ( V_2 -> V_9 )
F_2 ( V_2 -> V_9 ) ;
V_2 -> V_9 = NULL ;
V_6 . V_10 . type = V_11 ;
V_6 . V_10 . V_10 = V_4 -> V_10 ;
for ( V_7 = 0 ; V_7 < V_4 -> V_12 ; V_7 ++ ) {
if ( ! ( V_4 -> V_13 [ V_7 ] . V_14 & ~ V_15 ) )
continue;
V_6 . V_9 = V_4 -> V_13 [ V_7 ] . V_16 ;
V_6 . V_14 = V_4 -> V_13 [ V_7 ] . V_14 & V_15 ;
V_6 . V_17 = ( V_4 -> V_13 [ V_7 ] . V_14 & ~ V_15 ) << V_18 ;
F_3 ( & V_6 ) ;
}
F_4 ( V_4 -> V_13 ) ;
F_4 ( V_4 -> V_19 ) ;
F_4 ( V_4 ) ;
V_2 -> V_5 = NULL ;
return 0 ;
}
void * F_5 ( struct V_20 * V_20 ,
T_1 V_21 , struct V_1 * V_2 ,
T_1 * V_22 )
{
struct V_3 * V_4 ;
unsigned int V_7 , V_12 , V_23 , V_24 ;
struct V_1 V_6 ;
struct V_25 * V_13 ;
struct V_26 * * V_27 ;
V_2 -> V_9 = NULL ;
V_2 -> V_14 = 0 ;
V_2 -> V_5 = V_4 = F_6 ( sizeof( * V_4 ) , V_28 ) ;
if ( ! V_4 )
return NULL ;
V_4 -> V_10 = V_20 ;
V_12 = F_7 ( V_21 ) ;
V_4 -> V_29 = F_8 ( V_12 ) ;
V_13 = F_9 ( V_4 -> V_29 , sizeof( * V_13 ) , V_28 ) ;
if ( ! V_13 )
goto V_30;
V_4 -> V_13 = V_13 ;
V_27 = F_9 ( V_4 -> V_29 , sizeof( * V_27 ) , V_28 ) ;
if ( ! V_27 )
goto V_30;
V_4 -> V_19 = V_27 ;
V_24 = V_31 ;
while ( V_12 > 0 ) {
V_23 = V_12 ;
if ( V_23 > V_24 )
V_23 = V_24 ;
V_23 <<= V_18 ;
if ( F_10 ( V_11 , V_20 ,
V_23 , & V_6 ) < 0 ) {
if ( ! V_4 -> V_12 )
goto V_30;
if ( ! V_22 )
goto V_30;
V_21 = V_4 -> V_12 * V_32 ;
break;
}
V_23 = V_6 . V_17 >> V_18 ;
for ( V_7 = 0 ; V_7 < V_23 ; V_7 ++ ) {
V_13 -> V_16 = V_6 . V_9 ;
V_13 -> V_14 = V_6 . V_14 ;
if ( ! V_7 )
V_13 -> V_14 |= V_23 ;
V_13 ++ ;
* V_27 ++ = F_11 ( V_6 . V_9 ) ;
V_6 . V_9 += V_32 ;
V_6 . V_14 += V_32 ;
}
V_4 -> V_12 += V_23 ;
V_12 -= V_23 ;
if ( V_23 < V_24 )
V_24 = V_23 ;
}
V_4 -> V_21 = V_21 ;
V_2 -> V_9 = F_12 ( V_4 -> V_19 , V_4 -> V_12 , V_33 , V_34 ) ;
if ( ! V_2 -> V_9 )
goto V_30;
if ( V_22 )
* V_22 = V_4 -> V_21 ;
return V_2 -> V_9 ;
V_30:
F_1 ( V_2 ) ;
return NULL ;
}
