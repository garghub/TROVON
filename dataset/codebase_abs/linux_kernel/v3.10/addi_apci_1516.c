static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned int * V_7 )
{
V_7 [ 1 ] = F_2 ( V_2 -> V_8 + V_9 ) ;
return V_6 -> V_10 ;
}
static int F_3 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned int * V_7 )
{
unsigned int V_11 = V_7 [ 0 ] ;
unsigned int V_12 = V_7 [ 1 ] ;
V_4 -> V_13 = F_2 ( V_2 -> V_8 + V_14 ) ;
if ( V_11 ) {
V_4 -> V_13 &= ~ V_11 ;
V_4 -> V_13 |= ( V_12 & V_11 ) ;
F_4 ( V_4 -> V_13 , V_2 -> V_8 + V_14 ) ;
}
V_7 [ 1 ] = V_4 -> V_13 ;
return V_6 -> V_10 ;
}
static int F_5 ( struct V_1 * V_2 )
{
const struct V_15 * V_16 = F_6 ( V_2 ) ;
struct V_17 * V_18 = V_2 -> V_19 ;
if ( ! V_16 -> V_20 )
return 0 ;
F_4 ( 0x0 , V_2 -> V_8 + V_14 ) ;
F_7 ( V_18 -> V_21 ) ;
return 0 ;
}
static int F_8 ( struct V_1 * V_2 ,
unsigned long V_22 )
{
struct V_23 * V_24 = F_9 ( V_2 ) ;
const struct V_15 * V_16 = NULL ;
struct V_17 * V_18 ;
struct V_3 * V_4 ;
int V_25 ;
if ( V_22 < F_10 ( V_26 ) )
V_16 = & V_26 [ V_22 ] ;
if ( ! V_16 )
return - V_27 ;
V_2 -> V_28 = V_16 ;
V_2 -> V_29 = V_16 -> V_30 ;
V_18 = F_11 ( sizeof( * V_18 ) , V_31 ) ;
if ( ! V_18 )
return - V_32 ;
V_2 -> V_19 = V_18 ;
V_25 = F_12 ( V_2 ) ;
if ( V_25 )
return V_25 ;
V_2 -> V_8 = F_13 ( V_24 , 1 ) ;
V_18 -> V_21 = F_13 ( V_24 , 2 ) ;
V_25 = F_14 ( V_2 , 3 ) ;
if ( V_25 )
return V_25 ;
V_4 = & V_2 -> V_33 [ 0 ] ;
if ( V_16 -> V_34 ) {
V_4 -> type = V_35 ;
V_4 -> V_36 = V_37 ;
V_4 -> V_38 = V_16 -> V_34 ;
V_4 -> V_39 = 1 ;
V_4 -> V_40 = & V_41 ;
V_4 -> V_42 = F_1 ;
} else {
V_4 -> type = V_43 ;
}
V_4 = & V_2 -> V_33 [ 1 ] ;
if ( V_16 -> V_44 ) {
V_4 -> type = V_45 ;
V_4 -> V_36 = V_46 ;
V_4 -> V_38 = V_16 -> V_44 ;
V_4 -> V_39 = 1 ;
V_4 -> V_40 = & V_41 ;
V_4 -> V_42 = F_3 ;
} else {
V_4 -> type = V_43 ;
}
V_4 = & V_2 -> V_33 [ 2 ] ;
if ( V_16 -> V_20 ) {
V_25 = F_15 ( V_4 , V_18 -> V_21 ) ;
if ( V_25 )
return V_25 ;
} else {
V_4 -> type = V_43 ;
}
F_5 ( V_2 ) ;
return 0 ;
}
static void F_16 ( struct V_1 * V_2 )
{
if ( V_2 -> V_8 )
F_5 ( V_2 ) ;
F_17 ( V_2 , 2 ) ;
F_18 ( V_2 ) ;
}
static int F_19 ( struct V_23 * V_2 ,
const struct V_47 * V_48 )
{
return F_20 ( V_2 , & V_49 , V_48 -> V_50 ) ;
}
