static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned long V_7 )
{
unsigned int V_8 ;
V_8 = F_2 ( V_2 -> V_9 + V_10 ) ;
if ( ( V_8 & V_11 ) == 0 )
return 0 ;
return - V_12 ;
}
static int F_3 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned int * V_13 )
{
struct V_14 * V_15 = V_2 -> V_16 ;
unsigned int V_17 = F_4 ( V_6 -> V_18 ) ;
unsigned int V_19 = V_15 -> V_20 [ V_17 ] ;
int V_21 ;
int V_22 ;
for ( V_22 = 0 ; V_22 < V_6 -> V_23 ; V_22 ++ ) {
V_19 = V_13 [ V_22 ] ;
V_21 = F_5 ( V_2 , V_4 , V_6 , F_1 , 0 ) ;
if ( V_21 )
return V_21 ;
F_6 ( F_7 ( V_4 , V_19 ) ,
V_2 -> V_9 + F_8 ( V_17 ) ) ;
}
V_15 -> V_20 [ V_17 ] = V_19 ;
return V_6 -> V_23 ;
}
static int F_9 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned int * V_13 )
{
struct V_14 * V_15 = V_2 -> V_16 ;
unsigned int V_17 = F_4 ( V_6 -> V_18 ) ;
int V_22 ;
for ( V_22 = 0 ; V_22 < V_6 -> V_23 ; V_22 ++ )
V_13 [ V_22 ] = V_15 -> V_20 [ V_17 ] ;
return V_6 -> V_23 ;
}
static int F_10 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned int * V_13 )
{
unsigned int V_19 ;
V_19 = F_2 ( V_2 -> V_9 + V_24 ) ;
V_19 = ( V_19 & V_25 ) >> V_26 ;
V_13 [ 1 ] = V_19 ;
return V_6 -> V_23 ;
}
static int F_11 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned int * V_13 )
{
if ( F_12 ( V_4 , V_13 ) )
F_6 ( V_4 -> V_27 , V_2 -> V_9 + V_24 ) ;
V_13 [ 1 ] = V_4 -> V_27 ;
return V_6 -> V_23 ;
}
static int F_13 ( struct V_1 * V_2 ,
unsigned long V_7 )
{
struct V_28 * V_29 = F_14 ( V_2 ) ;
const struct V_30 * V_31 = NULL ;
struct V_14 * V_15 ;
struct V_3 * V_4 ;
unsigned int V_19 ;
int V_21 ;
if ( V_7 < F_15 ( V_32 ) )
V_31 = & V_32 [ V_7 ] ;
if ( ! V_31 )
return - V_33 ;
V_2 -> V_34 = V_31 ;
V_2 -> V_35 = V_31 -> V_36 ;
V_15 = F_16 ( V_2 , sizeof( * V_15 ) ) ;
if ( ! V_15 )
return - V_37 ;
V_21 = F_17 ( V_2 ) ;
if ( V_21 )
return V_21 ;
V_2 -> V_9 = F_18 ( V_29 , 2 ) ;
V_21 = F_19 ( V_2 , 3 ) ;
if ( V_21 )
return V_21 ;
V_4 = & V_2 -> V_38 [ 0 ] ;
V_4 -> type = V_39 ;
V_4 -> V_40 = V_41 ;
V_4 -> V_42 = V_31 -> V_43 ;
V_4 -> V_44 = 0xffff ;
V_4 -> V_45 = & V_46 ;
V_4 -> V_47 = F_3 ;
V_4 -> V_48 = F_9 ;
V_4 = & V_2 -> V_38 [ 1 ] ;
V_4 -> type = V_49 ;
V_4 -> V_40 = V_50 ;
V_4 -> V_42 = 4 ;
V_4 -> V_44 = 1 ;
V_4 -> V_45 = & V_51 ;
V_4 -> V_52 = F_10 ;
V_4 = & V_2 -> V_38 [ 2 ] ;
V_4 -> type = V_53 ;
V_4 -> V_40 = V_41 ;
V_4 -> V_42 = 4 ;
V_4 -> V_44 = 1 ;
V_4 -> V_45 = & V_51 ;
V_4 -> V_52 = F_11 ;
V_19 = F_2 ( V_2 -> V_9 + V_24 ) ;
V_19 = ( V_19 & V_54 ) >> V_55 ;
V_4 -> V_27 = V_19 ;
return 0 ;
}
static int F_20 ( struct V_28 * V_2 ,
const struct V_56 * V_57 )
{
return F_21 ( V_2 , & V_58 ,
V_57 -> V_59 ) ;
}
