static int
F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * * V_6 ,
const T_1 * V_7 ,
int V_8 , int V_9 ,
int V_10 , unsigned int V_11 ,
int V_12 )
{
struct V_13 * V_14 ;
struct V_15 * V_16 ;
int V_17 ;
int V_18 ;
int V_19 = V_8 * V_10 / 8 ;
struct V_5 * V_20 ;
int V_21 ;
void * V_22 ;
V_18 = V_12 ;
V_21 = F_2 ( V_2 , sizeof( * V_16 ) + V_9 * V_18 ,
& V_20 ) ;
V_22 = F_3 ( V_2 , V_20 , 0 ) ;
V_16 = V_22 ;
V_16 -> V_23 = V_9 * V_18 ;
V_16 -> V_24 = 0 ;
V_16 -> V_25 = 0 ;
F_4 ( V_2 , V_20 , V_22 ) ;
{
void * V_26 , * V_27 ;
int V_28 ;
int V_29 ;
int V_30 ;
if ( V_12 == V_19 && V_18 == V_12 ) {
V_28 = V_19 * V_9 ;
V_29 = 0 ;
V_27 = ( void * ) V_7 ;
while ( V_28 > 0 ) {
V_22 = F_3 ( V_2 , V_20 , V_29 << V_31 ) ;
if ( V_29 == 0 ) {
V_16 = V_22 ;
V_26 = V_16 -> V_7 ;
V_30 = V_32 - F_5 ( struct V_15 , V_7 ) ;
} else {
V_26 = V_22 ;
V_30 = V_32 ;
}
V_30 = F_6 ( V_30 , V_28 ) ;
memcpy ( V_26 , V_27 , V_30 ) ;
F_4 ( V_2 , V_20 , V_22 ) ;
V_27 += V_30 ;
V_28 -= V_30 ;
V_29 ++ ;
}
} else {
unsigned V_33 , V_34 , V_35 ;
for ( V_17 = 0 ; V_17 < V_9 ; ++ V_17 ) {
V_27 = ( void * ) V_7 + V_17 * V_12 ;
V_28 = V_19 ;
V_35 = F_5 ( struct V_15 , V_7 ) + V_17 * V_18 ;
while ( V_28 > 0 ) {
V_33 = V_35 & V_36 ;
V_34 = F_7 ( V_35 ) ;
V_30 = F_6 ( ( int ) ( V_32 - V_34 ) , V_28 ) ;
V_22 = F_3 ( V_2 , V_20 , V_33 ) ;
V_26 = V_22 + V_34 ;
memcpy ( V_26 , V_27 , V_30 ) ;
F_4 ( V_2 , V_20 , V_22 ) ;
V_28 -= V_30 ;
V_27 += V_30 ;
V_35 += V_30 ;
}
}
}
}
F_8 ( V_20 ) ;
V_21 = F_2 ( V_2 , sizeof( * V_14 ) , V_6 ) ;
V_22 = F_3 ( V_2 , * V_6 , 0 ) ;
V_14 = V_22 ;
V_14 -> V_37 . V_38 = 0 ;
V_14 -> V_37 . type = V_39 ;
V_14 -> V_37 . V_40 = 0 ;
V_14 -> V_37 . V_8 = V_8 ;
V_14 -> V_37 . V_9 = V_9 ;
switch ( V_10 ) {
case 1 :
V_14 -> V_41 . V_42 . V_43 = V_44 ;
break;
case 24 :
V_14 -> V_41 . V_42 . V_43 = V_45 ;
break;
case 32 :
V_14 -> V_41 . V_42 . V_43 = V_46 ;
break;
default:
F_9 ( L_1 ) ;
return - V_47 ;
}
V_14 -> V_41 . V_42 . V_40 = V_48 ;
V_14 -> V_41 . V_42 . V_49 = V_8 ;
V_14 -> V_41 . V_42 . V_50 = V_9 ;
V_14 -> V_41 . V_42 . V_12 = V_18 ;
V_14 -> V_41 . V_42 . V_51 = 0 ;
V_14 -> V_41 . V_42 . V_7 = F_10 ( V_2 , V_20 , 0 ) ;
F_11 ( V_2 , V_4 , V_20 ) ;
F_12 ( V_20 ) ;
F_13 ( & V_20 ) ;
F_4 ( V_2 , * V_6 , V_22 ) ;
return 0 ;
}
int F_14 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * * V_6 ,
const T_1 * V_7 ,
int V_49 , int V_50 , int V_8 , int V_9 ,
int V_10 , int V_12 )
{
V_7 += V_50 * V_12 + V_49 * ( V_10 / 8 ) ;
return F_1 ( V_2 , V_4 , V_6 , V_7 ,
V_8 , V_9 , V_10 , 0 , V_12 ) ;
}
