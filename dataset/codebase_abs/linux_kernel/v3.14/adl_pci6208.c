static int F_1 ( struct V_1 * V_2 ,
unsigned int V_3 )
{
unsigned int V_4 ;
while ( V_3 -- ) {
V_4 = F_2 ( V_2 -> V_5 + V_6 ) ;
if ( ( V_4 & V_7 ) == 0 )
return 0 ;
F_3 ( 1 ) ;
}
return - V_8 ;
}
static int F_4 ( struct V_1 * V_2 ,
struct V_9 * V_10 ,
struct V_11 * V_12 ,
unsigned int * V_13 )
{
struct V_14 * V_15 = V_2 -> V_16 ;
unsigned int V_17 = F_5 ( V_12 -> V_18 ) ;
unsigned int V_19 = V_15 -> V_20 [ V_17 ] ;
int V_21 ;
int V_22 ;
for ( V_22 = 0 ; V_22 < V_12 -> V_23 ; V_22 ++ ) {
V_19 = V_13 [ V_22 ] ;
V_21 = F_1 ( V_2 , 10 ) ;
if ( V_21 )
return V_21 ;
F_6 ( F_7 ( V_10 , V_19 ) ,
V_2 -> V_5 + F_8 ( V_17 ) ) ;
}
V_15 -> V_20 [ V_17 ] = V_19 ;
return V_12 -> V_23 ;
}
static int F_9 ( struct V_1 * V_2 ,
struct V_9 * V_10 ,
struct V_11 * V_12 ,
unsigned int * V_13 )
{
struct V_14 * V_15 = V_2 -> V_16 ;
unsigned int V_17 = F_5 ( V_12 -> V_18 ) ;
int V_22 ;
for ( V_22 = 0 ; V_22 < V_12 -> V_23 ; V_22 ++ )
V_13 [ V_22 ] = V_15 -> V_20 [ V_17 ] ;
return V_12 -> V_23 ;
}
static int F_10 ( struct V_1 * V_2 ,
struct V_9 * V_10 ,
struct V_11 * V_12 ,
unsigned int * V_13 )
{
unsigned int V_19 ;
V_19 = F_2 ( V_2 -> V_5 + V_24 ) ;
V_19 = ( V_19 & V_25 ) >> V_26 ;
V_13 [ 1 ] = V_19 ;
return V_12 -> V_23 ;
}
static int F_11 ( struct V_1 * V_2 ,
struct V_9 * V_10 ,
struct V_11 * V_12 ,
unsigned int * V_13 )
{
if ( F_12 ( V_10 , V_13 ) )
F_6 ( V_10 -> V_27 , V_2 -> V_5 + V_24 ) ;
V_13 [ 1 ] = V_10 -> V_27 ;
return V_12 -> V_23 ;
}
static int F_13 ( struct V_1 * V_2 ,
unsigned long V_28 )
{
struct V_29 * V_30 = F_14 ( V_2 ) ;
const struct V_31 * V_32 = NULL ;
struct V_14 * V_15 ;
struct V_9 * V_10 ;
unsigned int V_19 ;
int V_21 ;
if ( V_28 < F_15 ( V_33 ) )
V_32 = & V_33 [ V_28 ] ;
if ( ! V_32 )
return - V_34 ;
V_2 -> V_35 = V_32 ;
V_2 -> V_36 = V_32 -> V_37 ;
V_15 = F_16 ( V_2 , sizeof( * V_15 ) ) ;
if ( ! V_15 )
return - V_38 ;
V_21 = F_17 ( V_2 ) ;
if ( V_21 )
return V_21 ;
V_2 -> V_5 = F_18 ( V_30 , 2 ) ;
V_21 = F_19 ( V_2 , 3 ) ;
if ( V_21 )
return V_21 ;
V_10 = & V_2 -> V_39 [ 0 ] ;
V_10 -> type = V_40 ;
V_10 -> V_41 = V_42 ;
V_10 -> V_43 = V_32 -> V_44 ;
V_10 -> V_45 = 0xffff ;
V_10 -> V_46 = & V_47 ;
V_10 -> V_48 = F_4 ;
V_10 -> V_49 = F_9 ;
V_10 = & V_2 -> V_39 [ 1 ] ;
V_10 -> type = V_50 ;
V_10 -> V_41 = V_51 ;
V_10 -> V_43 = 4 ;
V_10 -> V_45 = 1 ;
V_10 -> V_46 = & V_52 ;
V_10 -> V_53 = F_10 ;
V_10 = & V_2 -> V_39 [ 2 ] ;
V_10 -> type = V_54 ;
V_10 -> V_41 = V_42 ;
V_10 -> V_43 = 4 ;
V_10 -> V_45 = 1 ;
V_10 -> V_46 = & V_52 ;
V_10 -> V_53 = F_11 ;
V_19 = F_2 ( V_2 -> V_5 + V_24 ) ;
V_19 = ( V_19 & V_55 ) >> V_56 ;
V_10 -> V_27 = V_19 ;
return 0 ;
}
static int F_20 ( struct V_29 * V_2 ,
const struct V_57 * V_58 )
{
return F_21 ( V_2 , & V_59 ,
V_58 -> V_60 ) ;
}
