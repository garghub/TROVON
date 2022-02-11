static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned int * V_7 )
{
unsigned long V_8 = ( unsigned long ) V_4 -> V_9 ;
if ( F_2 ( V_4 , V_7 ) ) {
unsigned int V_10 = V_4 -> V_11 ;
if ( V_4 -> V_12 == 16 ) {
V_10 |= V_10 << 16 ;
}
F_3 ( V_10 , V_2 -> V_13 + V_8 ) ;
}
V_7 [ 1 ] = V_4 -> V_11 ;
return V_6 -> V_14 ;
}
static int F_4 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned int * V_7 )
{
unsigned long V_8 = ( unsigned long ) V_4 -> V_9 ;
V_7 [ 1 ] = F_5 ( V_2 -> V_13 + V_8 ) ;
return V_6 -> V_14 ;
}
static int F_6 ( struct V_1 * V_2 ,
unsigned long V_15 )
{
struct V_16 * V_17 = F_7 ( V_2 ) ;
const struct V_18 * V_19 = NULL ;
struct V_3 * V_4 ;
int V_20 ;
int V_21 ;
int V_22 ;
if ( V_15 < F_8 ( V_23 ) )
V_19 = & V_23 [ V_15 ] ;
if ( ! V_19 )
return - V_24 ;
V_2 -> V_25 = V_19 ;
V_2 -> V_26 = V_19 -> V_27 ;
V_22 = F_9 ( V_2 ) ;
if ( V_22 )
return V_22 ;
V_2 -> V_13 = F_10 ( V_17 , 2 ) ;
V_22 = F_11 ( V_2 , V_19 -> V_28 ) ;
if ( V_22 )
return V_22 ;
V_20 = 0 ;
if ( V_19 -> V_29 ) {
V_21 = F_12 ( V_19 -> V_29 , 32 ) ;
V_4 = & V_2 -> V_30 [ V_20 ] ;
V_4 -> type = V_31 ;
V_4 -> V_32 = V_33 ;
V_4 -> V_12 = V_21 ;
V_4 -> V_34 = 1 ;
V_4 -> V_35 = F_4 ;
V_4 -> V_36 = & V_37 ;
V_4 -> V_9 = ( void * ) V_38 ;
V_20 ++ ;
V_21 = V_19 -> V_29 - V_21 ;
if ( V_21 ) {
V_4 = & V_2 -> V_30 [ V_20 ] ;
V_4 -> type = V_31 ;
V_4 -> V_32 = V_33 ;
V_4 -> V_12 = V_21 ;
V_4 -> V_34 = 1 ;
V_4 -> V_35 = F_4 ;
V_4 -> V_36 = & V_37 ;
V_4 -> V_9 = ( void * ) V_39 ;
V_20 ++ ;
}
}
if ( V_19 -> V_40 ) {
V_21 = F_12 ( V_19 -> V_40 , 32 ) ;
V_4 = & V_2 -> V_30 [ V_20 ] ;
V_4 -> type = V_41 ;
V_4 -> V_32 = V_42 ;
V_4 -> V_12 = V_21 ;
V_4 -> V_34 = 1 ;
V_4 -> V_35 = F_1 ;
V_4 -> V_36 = & V_37 ;
V_4 -> V_9 = ( void * ) V_38 ;
V_20 ++ ;
V_21 = V_19 -> V_40 - V_21 ;
if ( V_21 ) {
V_4 = & V_2 -> V_30 [ V_20 ] ;
V_4 -> type = V_41 ;
V_4 -> V_32 = V_42 ;
V_4 -> V_12 = V_21 ;
V_4 -> V_34 = 1 ;
V_4 -> V_35 = F_1 ;
V_4 -> V_36 = & V_37 ;
V_4 -> V_9 = ( void * ) V_39 ;
V_20 ++ ;
}
}
return 0 ;
}
static int F_13 ( struct V_16 * V_2 ,
const struct V_43 * V_44 )
{
return F_14 ( V_2 , & V_45 ,
V_44 -> V_46 ) ;
}
