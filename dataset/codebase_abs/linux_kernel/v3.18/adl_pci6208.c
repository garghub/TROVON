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
unsigned int V_14 = F_4 ( V_6 -> V_15 ) ;
unsigned int V_16 = V_4 -> V_17 [ V_14 ] ;
int V_18 ;
int V_19 ;
for ( V_19 = 0 ; V_19 < V_6 -> V_20 ; V_19 ++ ) {
V_16 = V_13 [ V_19 ] ;
V_18 = F_5 ( V_2 , V_4 , V_6 , F_1 , 0 ) ;
if ( V_18 )
return V_18 ;
F_6 ( F_7 ( V_4 , V_16 ) ,
V_2 -> V_9 + F_8 ( V_14 ) ) ;
V_4 -> V_17 [ V_14 ] = V_16 ;
}
return V_6 -> V_20 ;
}
static int F_9 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned int * V_13 )
{
unsigned int V_16 ;
V_16 = F_2 ( V_2 -> V_9 + V_21 ) ;
V_16 = ( V_16 & V_22 ) >> V_23 ;
V_13 [ 1 ] = V_16 ;
return V_6 -> V_20 ;
}
static int F_10 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned int * V_13 )
{
if ( F_11 ( V_4 , V_13 ) )
F_6 ( V_4 -> V_24 , V_2 -> V_9 + V_21 ) ;
V_13 [ 1 ] = V_4 -> V_24 ;
return V_6 -> V_20 ;
}
static int F_12 ( struct V_1 * V_2 ,
unsigned long V_7 )
{
struct V_25 * V_26 = F_13 ( V_2 ) ;
const struct V_27 * V_28 = NULL ;
struct V_3 * V_4 ;
unsigned int V_16 ;
int V_18 ;
if ( V_7 < F_14 ( V_29 ) )
V_28 = & V_29 [ V_7 ] ;
if ( ! V_28 )
return - V_30 ;
V_2 -> V_31 = V_28 ;
V_2 -> V_32 = V_28 -> V_33 ;
V_18 = F_15 ( V_2 ) ;
if ( V_18 )
return V_18 ;
V_2 -> V_9 = F_16 ( V_26 , 2 ) ;
V_18 = F_17 ( V_2 , 3 ) ;
if ( V_18 )
return V_18 ;
V_4 = & V_2 -> V_34 [ 0 ] ;
V_4 -> type = V_35 ;
V_4 -> V_36 = V_37 ;
V_4 -> V_38 = V_28 -> V_39 ;
V_4 -> V_40 = 0xffff ;
V_4 -> V_41 = & V_42 ;
V_4 -> V_43 = F_3 ;
V_4 -> V_44 = V_45 ;
V_18 = F_18 ( V_4 ) ;
if ( V_18 )
return V_18 ;
V_4 = & V_2 -> V_34 [ 1 ] ;
V_4 -> type = V_46 ;
V_4 -> V_36 = V_47 ;
V_4 -> V_38 = 4 ;
V_4 -> V_40 = 1 ;
V_4 -> V_41 = & V_48 ;
V_4 -> V_49 = F_9 ;
V_4 = & V_2 -> V_34 [ 2 ] ;
V_4 -> type = V_50 ;
V_4 -> V_36 = V_37 ;
V_4 -> V_38 = 4 ;
V_4 -> V_40 = 1 ;
V_4 -> V_41 = & V_48 ;
V_4 -> V_49 = F_10 ;
V_16 = F_2 ( V_2 -> V_9 + V_21 ) ;
V_16 = ( V_16 & V_51 ) >> V_52 ;
V_4 -> V_24 = V_16 ;
return 0 ;
}
static int F_19 ( struct V_25 * V_2 ,
const struct V_53 * V_54 )
{
return F_20 ( V_2 , & V_55 ,
V_54 -> V_56 ) ;
}
