static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
int V_11 = F_2 ( V_6 -> V_12 ) ;
unsigned long V_13 = 1 << ( 16 - 1 ) ;
unsigned long V_14 = 0 ;
unsigned short V_15 ;
int V_16 ;
for ( V_16 = 0 ; V_16 < V_6 -> V_17 ; V_16 ++ ) {
V_14 = V_7 [ V_16 ] ^ V_13 ;
do {
V_15 = F_3 ( V_2 -> V_18 + V_19 ) ;
} while ( V_15 & V_20 );
F_4 ( V_14 , V_2 -> V_18 + F_5 ( V_11 ) ) ;
}
V_9 -> V_21 [ V_11 ] = V_14 ;
return V_6 -> V_17 ;
}
static int F_6 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
int V_11 = F_2 ( V_6 -> V_12 ) ;
int V_16 ;
for ( V_16 = 0 ; V_16 < V_6 -> V_17 ; V_16 ++ )
V_7 [ V_16 ] = V_9 -> V_21 [ V_11 ] ;
return V_6 -> V_17 ;
}
static int F_7 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned int * V_7 )
{
unsigned int V_22 ;
V_22 = F_3 ( V_2 -> V_18 + V_23 ) ;
V_22 = ( V_22 & V_24 ) >> V_25 ;
V_7 [ 1 ] = V_22 ;
return V_6 -> V_17 ;
}
static int F_8 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned int * V_7 )
{
unsigned int V_26 = V_7 [ 0 ] ;
unsigned int V_27 = V_7 [ 1 ] ;
if ( V_26 ) {
V_4 -> V_28 &= ~ V_26 ;
V_4 -> V_28 |= ( V_27 & V_26 ) ;
F_4 ( V_4 -> V_28 , V_2 -> V_18 + V_23 ) ;
}
V_7 [ 1 ] = V_4 -> V_28 ;
return V_6 -> V_17 ;
}
static int F_9 ( struct V_1 * V_2 ,
unsigned long V_29 )
{
struct V_30 * V_31 = F_10 ( V_2 ) ;
const struct V_32 * V_33 = NULL ;
struct V_8 * V_9 ;
struct V_3 * V_4 ;
unsigned int V_22 ;
int V_34 ;
if ( V_29 < F_11 ( V_35 ) )
V_33 = & V_35 [ V_29 ] ;
if ( ! V_33 )
return - V_36 ;
V_2 -> V_37 = V_33 ;
V_2 -> V_38 = V_33 -> V_39 ;
V_9 = F_12 ( sizeof( * V_9 ) , V_40 ) ;
if ( ! V_9 )
return - V_41 ;
V_2 -> V_10 = V_9 ;
V_34 = F_13 ( V_2 ) ;
if ( V_34 )
return V_34 ;
V_2 -> V_18 = F_14 ( V_31 , 2 ) ;
V_34 = F_15 ( V_2 , 3 ) ;
if ( V_34 )
return V_34 ;
V_4 = & V_2 -> V_42 [ 0 ] ;
V_4 -> type = V_43 ;
V_4 -> V_44 = V_45 ;
V_4 -> V_46 = V_33 -> V_47 ;
V_4 -> V_48 = 0xffff ;
V_4 -> V_49 = & V_50 ;
V_4 -> V_51 = F_1 ;
V_4 -> V_52 = F_6 ;
V_4 = & V_2 -> V_42 [ 1 ] ;
V_4 -> type = V_53 ;
V_4 -> V_44 = V_54 ;
V_4 -> V_46 = 4 ;
V_4 -> V_48 = 1 ;
V_4 -> V_49 = & V_55 ;
V_4 -> V_56 = F_7 ;
V_4 = & V_2 -> V_42 [ 2 ] ;
V_4 -> type = V_57 ;
V_4 -> V_44 = V_45 ;
V_4 -> V_46 = 4 ;
V_4 -> V_48 = 1 ;
V_4 -> V_49 = & V_55 ;
V_4 -> V_56 = F_8 ;
V_22 = F_3 ( V_2 -> V_18 + V_23 ) ;
V_22 = ( V_22 & V_58 ) >> V_59 ;
V_4 -> V_28 = V_22 ;
V_4 -> V_60 = 0x0f ;
F_16 ( V_2 -> V_61 , L_1 ,
V_2 -> V_62 -> V_63 , V_2 -> V_38 , V_2 -> V_18 ) ;
return 0 ;
}
static int F_17 ( struct V_30 * V_2 ,
const struct V_64 * V_65 )
{
return F_18 ( V_2 , & V_66 ,
V_65 -> V_67 ) ;
}
