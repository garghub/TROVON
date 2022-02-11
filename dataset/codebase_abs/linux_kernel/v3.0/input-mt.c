int F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
int V_4 ;
if ( ! V_3 )
return 0 ;
if ( V_2 -> V_5 )
return V_2 -> V_6 != V_3 ? - V_7 : 0 ;
V_2 -> V_5 = F_2 ( V_3 , sizeof( struct V_8 ) , V_9 ) ;
if ( ! V_2 -> V_5 )
return - V_10 ;
V_2 -> V_6 = V_3 ;
F_3 ( V_2 , V_11 , 0 , V_3 - 1 , 0 , 0 ) ;
F_3 ( V_2 , V_12 , 0 , V_13 , 0 , 0 ) ;
F_4 ( V_2 , 6 * V_3 ) ;
for ( V_4 = 0 ; V_4 < V_3 ; V_4 ++ )
F_5 ( & V_2 -> V_5 [ V_4 ] , V_12 , - 1 ) ;
return 0 ;
}
void F_6 ( struct V_1 * V_2 )
{
F_7 ( V_2 -> V_5 ) ;
V_2 -> V_5 = NULL ;
V_2 -> V_6 = 0 ;
V_2 -> V_14 = 0 ;
V_2 -> V_15 = 0 ;
}
void F_8 ( struct V_1 * V_2 ,
unsigned int V_16 , bool V_17 )
{
struct V_8 * V_5 ;
int V_18 ;
if ( ! V_2 -> V_5 || ! V_17 ) {
F_9 ( V_2 , V_19 , V_12 , - 1 ) ;
return;
}
V_5 = & V_2 -> V_5 [ V_2 -> V_14 ] ;
V_18 = F_10 ( V_5 , V_12 ) ;
if ( V_18 < 0 || F_10 ( V_5 , V_20 ) != V_16 )
V_18 = F_11 ( V_2 ) ;
F_9 ( V_2 , V_19 , V_12 , V_18 ) ;
F_9 ( V_2 , V_19 , V_20 , V_16 ) ;
}
void F_12 ( struct V_1 * V_2 , int V_21 )
{
F_9 ( V_2 , V_22 , V_23 , V_21 == 1 ) ;
F_9 ( V_2 , V_22 , V_24 , V_21 == 2 ) ;
F_9 ( V_2 , V_22 , V_25 , V_21 == 3 ) ;
F_9 ( V_2 , V_22 , V_26 , V_21 == 4 ) ;
}
void F_13 ( struct V_1 * V_2 , bool V_27 )
{
struct V_8 * V_28 = 0 ;
int V_29 = V_2 -> V_15 ;
int V_21 = 0 ;
int V_4 ;
for ( V_4 = 0 ; V_4 < V_2 -> V_6 ; ++ V_4 ) {
struct V_8 * V_30 = & V_2 -> V_5 [ V_4 ] ;
int V_18 = F_10 ( V_30 , V_12 ) ;
if ( V_18 < 0 )
continue;
if ( ( V_18 - V_29 ) & V_31 ) {
V_28 = V_30 ;
V_29 = V_18 ;
}
V_21 ++ ;
}
F_9 ( V_2 , V_22 , V_32 , V_21 > 0 ) ;
if ( V_27 )
F_12 ( V_2 , V_21 ) ;
if ( V_28 ) {
int V_33 = F_10 ( V_28 , V_34 ) ;
int V_35 = F_10 ( V_28 , V_36 ) ;
int V_37 = F_10 ( V_28 , V_38 ) ;
F_9 ( V_2 , V_19 , V_39 , V_33 ) ;
F_9 ( V_2 , V_19 , V_40 , V_35 ) ;
F_9 ( V_2 , V_19 , V_41 , V_37 ) ;
} else {
F_9 ( V_2 , V_19 , V_41 , 0 ) ;
}
}
