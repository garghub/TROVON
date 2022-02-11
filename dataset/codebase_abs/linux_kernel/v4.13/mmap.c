static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = F_2 ( V_2 -> V_4 -> V_5 ) ;
char * V_6 ;
unsigned int V_7 ;
unsigned int V_8 ;
int V_9 ;
int V_10 ;
V_2 -> V_11 = F_3 ( V_12 ) ;
if ( ! V_2 -> V_11 )
return V_13 ;
V_6 = F_4 ( V_2 -> V_11 ) ;
V_10 = V_2 -> V_14 << V_15 ;
V_8 = V_16 ;
V_9 = F_5 ( V_3 ) -> V_17 ;
V_7 = 0 ;
if ( F_6 ( V_3 , V_18 ) >= 0 ) {
while ( V_7 < V_8 ) {
int V_19 ;
int V_20 ;
V_20 = V_9 - ( V_10 % V_9 ) ;
V_20 = F_7 (unsigned int, to_read, count - already_read) ;
if ( F_8 ( F_5 ( V_3 ) ,
F_9 ( V_3 ) -> V_21 ,
V_10 , V_20 ,
V_6 + V_7 ,
& V_19 ) != 0 ) {
V_19 = 0 ;
}
V_10 += V_19 ;
V_7 += V_19 ;
if ( V_19 < V_20 ) {
break;
}
}
F_10 ( V_3 ) ;
}
if ( V_7 < V_16 )
memset ( V_6 + V_7 , 0 , V_16 - V_7 ) ;
F_11 ( V_2 -> V_11 ) ;
F_12 ( V_2 -> V_11 ) ;
F_13 ( V_22 ) ;
F_14 ( V_2 -> V_4 -> V_23 , V_22 ) ;
return V_24 ;
}
int F_15 ( struct V_25 * V_25 , struct V_26 * V_4 )
{
struct V_3 * V_3 = F_2 ( V_25 ) ;
F_16 ( 1 , L_1 ) ;
if ( ! F_17 ( F_5 ( V_3 ) ) )
return - V_27 ;
if ( V_4 -> V_28 & V_29 )
return - V_30 ;
if ( F_18 ( V_4 ) + V_4 -> V_31
> ( 1U << ( 32 - V_15 ) ) )
return - V_32 ;
V_4 -> V_33 = & V_34 ;
F_19 ( V_25 ) ;
return 0 ;
}
