static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_5 = V_2 -> V_6 ;
struct V_7 * V_7 = V_5 -> V_8 . V_7 ;
struct V_9 * V_9 = V_7 -> V_10 ;
char * V_11 ;
unsigned int V_12 ;
unsigned int V_13 ;
int V_14 ;
int V_15 ;
V_4 -> V_16 = F_2 ( V_17 ) ;
if ( ! V_4 -> V_16 )
return V_18 ;
V_11 = F_3 ( V_4 -> V_16 ) ;
V_15 = V_4 -> V_19 << V_20 ;
V_13 = V_21 ;
V_14 = F_4 ( V_9 ) -> V_22 ;
V_12 = 0 ;
if ( F_5 ( V_9 , V_23 ) >= 0 ) {
while ( V_12 < V_13 ) {
int V_24 ;
int V_25 ;
V_25 = V_14 - ( V_15 % V_14 ) ;
V_25 = F_6 (unsigned int, to_read, count - already_read) ;
if ( F_7 ( F_4 ( V_9 ) ,
F_8 ( V_9 ) -> V_26 ,
V_15 , V_25 ,
V_11 + V_12 ,
& V_24 ) != 0 ) {
V_24 = 0 ;
}
V_15 += V_24 ;
V_12 += V_24 ;
if ( V_24 < V_25 ) {
break;
}
}
F_9 ( V_9 ) ;
}
if ( V_12 < V_21 )
memset ( V_11 + V_12 , 0 , V_21 - V_12 ) ;
F_10 ( V_4 -> V_16 ) ;
F_11 ( V_4 -> V_16 ) ;
F_12 ( V_27 ) ;
F_13 ( V_2 -> V_28 , V_27 ) ;
return V_29 ;
}
int F_14 ( struct V_5 * V_5 , struct V_1 * V_30 )
{
struct V_9 * V_9 = F_15 ( V_5 ) ;
F_16 ( L_1 ) ;
if ( ! F_17 ( F_4 ( V_9 ) ) )
return - V_31 ;
if ( V_30 -> V_32 & V_33 )
return - V_34 ;
if ( F_18 ( V_30 ) + V_30 -> V_35
> ( 1U << ( 32 - V_20 ) ) )
return - V_36 ;
V_30 -> V_37 = & V_38 ;
F_19 ( V_5 ) ;
return 0 ;
}
