static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_5 = F_2 ( V_2 -> V_6 ) ;
char * V_7 ;
unsigned int V_8 ;
unsigned int V_9 ;
int V_10 ;
int V_11 ;
V_4 -> V_12 = F_3 ( V_13 ) ;
if ( ! V_4 -> V_12 )
return V_14 ;
V_7 = F_4 ( V_4 -> V_12 ) ;
V_11 = V_4 -> V_15 << V_16 ;
V_9 = V_17 ;
V_10 = F_5 ( V_5 ) -> V_18 ;
V_8 = 0 ;
if ( F_6 ( V_5 , V_19 ) >= 0 ) {
while ( V_8 < V_9 ) {
int V_20 ;
int V_21 ;
V_21 = V_10 - ( V_11 % V_10 ) ;
V_21 = F_7 (unsigned int, to_read, count - already_read) ;
if ( F_8 ( F_5 ( V_5 ) ,
F_9 ( V_5 ) -> V_22 ,
V_11 , V_21 ,
V_7 + V_8 ,
& V_20 ) != 0 ) {
V_20 = 0 ;
}
V_11 += V_20 ;
V_8 += V_20 ;
if ( V_20 < V_21 ) {
break;
}
}
F_10 ( V_5 ) ;
}
if ( V_8 < V_17 )
memset ( V_7 + V_8 , 0 , V_17 - V_8 ) ;
F_11 ( V_4 -> V_12 ) ;
F_12 ( V_4 -> V_12 ) ;
F_13 ( V_23 ) ;
F_14 ( V_2 -> V_24 , V_23 ) ;
return V_25 ;
}
int F_15 ( struct V_26 * V_26 , struct V_1 * V_27 )
{
struct V_5 * V_5 = F_2 ( V_26 ) ;
F_16 ( 1 , L_1 ) ;
if ( ! F_17 ( F_5 ( V_5 ) ) )
return - V_28 ;
if ( V_27 -> V_29 & V_30 )
return - V_31 ;
if ( F_18 ( V_27 ) + V_27 -> V_32
> ( 1U << ( 32 - V_16 ) ) )
return - V_33 ;
V_27 -> V_34 = & V_35 ;
F_19 ( V_26 ) ;
return 0 ;
}
