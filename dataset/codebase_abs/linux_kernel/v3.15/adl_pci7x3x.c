static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned int * V_7 )
{
unsigned long V_8 = ( unsigned long ) V_4 -> V_9 ;
if ( F_2 ( V_4 , V_7 ) )
F_3 ( V_4 -> V_10 , V_2 -> V_11 + V_8 ) ;
V_7 [ 1 ] = V_4 -> V_10 ;
return V_6 -> V_12 ;
}
static int F_4 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned int * V_7 )
{
unsigned long V_8 = ( unsigned long ) V_4 -> V_9 ;
V_7 [ 1 ] = F_5 ( V_2 -> V_11 + V_8 ) ;
return V_6 -> V_12 ;
}
static int F_6 ( struct V_1 * V_2 ,
unsigned long V_13 )
{
struct V_14 * V_15 = F_7 ( V_2 ) ;
const struct V_16 * V_17 = NULL ;
struct V_3 * V_4 ;
int V_18 ;
int V_19 ;
int V_20 ;
if ( V_13 < F_8 ( V_21 ) )
V_17 = & V_21 [ V_13 ] ;
if ( ! V_17 )
return - V_22 ;
V_2 -> V_23 = V_17 ;
V_2 -> V_24 = V_17 -> V_25 ;
V_20 = F_9 ( V_2 ) ;
if ( V_20 )
return V_20 ;
V_2 -> V_11 = F_10 ( V_15 , 2 ) ;
V_20 = F_11 ( V_2 , V_17 -> V_26 ) ;
if ( V_20 )
return V_20 ;
V_18 = 0 ;
if ( V_17 -> V_27 ) {
V_19 = F_12 ( V_17 -> V_27 , 32 ) ;
V_4 = & V_2 -> V_28 [ V_18 ] ;
V_4 -> type = V_29 ;
V_4 -> V_30 = V_31 ;
V_4 -> V_32 = V_19 ;
V_4 -> V_33 = 1 ;
V_4 -> V_34 = F_4 ;
V_4 -> V_35 = & V_36 ;
V_4 -> V_9 = ( void * ) V_37 ;
V_18 ++ ;
V_19 = V_17 -> V_27 - V_19 ;
if ( V_19 ) {
V_4 = & V_2 -> V_28 [ V_18 ] ;
V_4 -> type = V_29 ;
V_4 -> V_30 = V_31 ;
V_4 -> V_32 = V_19 ;
V_4 -> V_33 = 1 ;
V_4 -> V_34 = F_4 ;
V_4 -> V_35 = & V_36 ;
V_4 -> V_9 = ( void * ) V_38 ;
V_18 ++ ;
}
}
if ( V_17 -> V_39 ) {
V_19 = F_12 ( V_17 -> V_39 , 32 ) ;
V_4 = & V_2 -> V_28 [ V_18 ] ;
V_4 -> type = V_40 ;
V_4 -> V_30 = V_41 ;
V_4 -> V_32 = V_19 ;
V_4 -> V_33 = 1 ;
V_4 -> V_34 = F_1 ;
V_4 -> V_35 = & V_36 ;
V_4 -> V_9 = ( void * ) V_37 ;
V_18 ++ ;
V_19 = V_17 -> V_39 - V_19 ;
if ( V_19 ) {
V_4 = & V_2 -> V_28 [ V_18 ] ;
V_4 -> type = V_40 ;
V_4 -> V_30 = V_41 ;
V_4 -> V_32 = V_19 ;
V_4 -> V_33 = 1 ;
V_4 -> V_34 = F_1 ;
V_4 -> V_35 = & V_36 ;
V_4 -> V_9 = ( void * ) V_38 ;
V_18 ++ ;
}
}
return 0 ;
}
static int F_13 ( struct V_14 * V_2 ,
const struct V_42 * V_43 )
{
return F_14 ( V_2 , & V_44 ,
V_43 -> V_45 ) ;
}
