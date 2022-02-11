static bool F_1 ( unsigned V_1 , unsigned V_2 , unsigned V_3 )
{
return V_1 - ( V_2 + 1 ) < ( V_3 - 1 ) - V_2 ;
}
void F_2 ( struct V_4 * V_5 )
{
memset ( V_5 , 0 , sizeof( * V_5 ) ) ;
F_3 ( & V_5 -> V_6 ) ;
}
int F_4 ( struct V_4 * V_5 , int V_7 , unsigned V_8 ,
int V_9 , int V_10 , T_1 V_11 )
{
int V_12 ;
if ( ! F_5 ( V_8 ) || V_7 < 0 )
return - V_13 ;
V_7 = F_6 ( V_7 , V_8 ) ;
V_12 = V_7 + V_8 * V_10 + V_8 * V_14 ;
V_5 -> V_15 = F_7 ( V_12 , V_11 ) ;
if ( ! V_5 -> V_15 )
return - V_16 ;
V_5 -> V_17 = 0 ;
V_5 -> V_18 = 0 ;
V_5 -> V_19 = 0 ;
V_5 -> V_7 = V_7 ;
V_5 -> V_20 = V_7 ;
V_5 -> V_8 = V_8 ;
V_5 -> V_9 = F_8 ( int , F_9 ( V_9 , V_8 ) , V_8 ) ;
V_5 -> V_21 = 0 ;
V_5 -> V_10 = V_10 ;
V_5 -> V_22 = V_7 + V_8 * V_10 ;
V_5 -> V_12 = V_12 ;
V_5 -> V_23 = 0 ;
return 0 ;
}
void F_10 ( struct V_4 * V_5 )
{
struct V_24 * V_6 , * V_25 ;
if ( ! V_5 -> V_15 )
return;
F_11 (pending, next, &fifo->pending, link)
F_12 ( & V_6 -> V_26 ) ;
F_13 ( V_5 -> V_15 ) ;
V_5 -> V_15 = NULL ;
}
void F_14 ( struct V_4 * V_5 )
{
struct V_24 * V_6 , * V_25 ;
if ( ! V_5 -> V_15 )
return;
F_11 (pending, next, &fifo->pending, link)
F_12 ( & V_6 -> V_26 ) ;
V_5 -> V_17 = 0 ;
V_5 -> V_18 = 0 ;
V_5 -> V_19 = 0 ;
V_5 -> V_20 = V_5 -> V_7 ;
V_5 -> V_21 = 0 ;
V_5 -> V_23 = 0 ;
}
int F_15 ( struct V_4 * V_5 , const void * V_27 , int V_28 )
{
int V_29 , V_30 ;
if ( ! V_5 -> V_15 )
return - V_31 ;
if ( V_5 -> V_23 )
return - V_32 ;
if ( V_28 > V_5 -> V_20 )
V_28 = V_5 -> V_20 ;
if ( V_28 <= 0 )
return 0 ;
V_29 = V_5 -> V_17 % V_5 -> V_12 ;
V_30 = F_16 ( V_28 , V_5 -> V_12 - V_29 ) ;
memcpy ( V_5 -> V_15 + V_29 , V_27 , V_30 ) ;
memcpy ( V_5 -> V_15 , V_27 + V_30 , V_28 - V_30 ) ;
if ( F_17 ( V_5 , F_1 ( V_5 -> V_19 , V_5 -> V_17 , V_5 -> V_17 + V_28 ) ||
V_5 -> V_20 < V_28 ,
L_1 ,
V_5 -> V_17 , V_5 -> V_18 , V_5 -> V_19 , V_28 , V_5 -> V_20 ) )
return - V_32 ;
V_5 -> V_17 += V_28 ;
V_5 -> V_20 -= V_28 ;
F_18 ( L_2 , V_5 -> V_17 , V_5 -> V_18 ,
V_5 -> V_19 , V_28 , V_5 -> V_20 ) ;
return V_28 ;
}
int F_19 ( struct V_4 * V_5 , struct V_24 * V_33 )
{
unsigned V_34 , V_28 , V_29 , V_30 , V_35 ;
if ( ! V_5 -> V_15 )
return - V_31 ;
if ( V_5 -> V_23 )
return - V_32 ;
V_33 -> V_34 = 0 ;
V_33 -> V_15 = NULL ;
V_33 -> V_18 = V_5 -> V_18 ;
V_34 = V_5 -> V_17 - V_5 -> V_18 ;
if ( ! V_34 )
return - V_36 ;
if ( V_5 -> V_21 == V_5 -> V_10 )
return - V_37 ;
V_28 = V_34 ;
V_29 = V_5 -> V_18 % V_5 -> V_12 ;
V_30 = V_5 -> V_12 - V_29 ;
V_35 = F_20 ( unsigned , V_30 , V_5 -> V_9 ) ;
if ( V_28 > V_35 ) {
V_28 = V_35 ;
V_5 -> V_18 += V_35 ;
} else if ( V_29 + V_28 > V_5 -> V_22 ) {
V_5 -> V_18 += V_30 ;
V_5 -> V_17 = V_5 -> V_18 ;
} else {
V_5 -> V_18 += F_6 ( V_28 , V_5 -> V_8 ) ;
V_5 -> V_17 = V_5 -> V_18 ;
}
F_18 ( L_3 , V_5 -> V_17 ,
V_5 -> V_18 , V_5 -> V_19 , V_28 , V_34 , V_5 -> V_20 ) ;
V_33 -> V_34 = V_28 ;
V_33 -> V_15 = V_5 -> V_15 + V_29 ;
V_33 -> V_25 = V_5 -> V_18 ;
F_21 ( & V_33 -> V_26 , & V_5 -> V_6 ) ;
++ V_5 -> V_21 ;
if ( F_17 ( V_5 , V_5 -> V_21 > V_5 -> V_10 ,
L_4 ,
V_5 -> V_21 , V_5 -> V_10 ) )
return - V_32 ;
if ( F_17 ( V_5 , V_5 -> V_18 & ( V_5 -> V_8 - 1 ) ,
L_5 ,
V_5 -> V_18 , V_5 -> V_8 ) )
return - V_32 ;
return V_34 - V_28 ;
}
int F_22 ( struct V_4 * V_5 , struct V_24 * V_38 )
{
struct V_24 * V_6 , * V_25 , * V_39 ;
if ( ! V_5 -> V_15 )
return - V_31 ;
if ( V_5 -> V_23 )
return - V_32 ;
if ( F_23 ( & V_5 -> V_6 ) && V_5 -> V_21 == 0 )
return - V_13 ;
if ( F_17 ( V_5 , F_23 ( & V_5 -> V_6 ) != ( V_5 -> V_21 == 0 ) ,
L_6 ,
V_5 -> V_21 ) )
return - V_32 ;
V_39 = V_38 -> V_15 ;
* V_39 = * V_38 ;
F_24 ( & V_38 -> V_26 , & V_39 -> V_26 ) ;
F_25 ( V_39 ) ;
F_11 (pending, next, &fifo->pending, link) {
if ( ! F_26 ( V_6 ) ) {
F_18 ( L_7 ,
V_6 -> V_18 , V_6 -> V_34 ) ;
break;
}
if ( F_17 ( V_5 , V_6 -> V_18 != V_5 -> V_19 ||
F_1 ( V_5 -> V_17 , V_5 -> V_19 , V_6 -> V_25 ) ,
L_8 ,
V_5 -> V_17 , V_5 -> V_18 , V_5 -> V_19 , V_6 -> V_18 ,
V_6 -> V_25 ) )
return - V_32 ;
F_12 ( & V_6 -> V_26 ) ;
V_5 -> V_19 = V_6 -> V_25 ;
V_5 -> V_20 += V_6 -> V_34 ;
-- V_5 -> V_21 ;
F_18 ( L_9 , V_5 -> V_17 ,
V_5 -> V_18 , V_5 -> V_19 , V_6 -> V_34 , V_5 -> V_20 ) ;
}
if ( F_17 ( V_5 , V_5 -> V_21 < 0 , L_10 , V_5 -> V_21 ) )
return - V_32 ;
if ( F_17 ( V_5 , V_5 -> V_20 > V_5 -> V_7 , L_11 ,
V_5 -> V_20 , V_5 -> V_7 ) )
return - V_32 ;
return 0 ;
}
