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
V_4 -> V_11 = F_2 ( V_2 -> V_8 + V_12 ) ;
if ( F_4 ( V_4 , V_7 ) )
F_5 ( V_4 -> V_11 , V_2 -> V_8 + V_12 ) ;
V_7 [ 1 ] = V_4 -> V_11 ;
return V_6 -> V_10 ;
}
static int F_6 ( struct V_1 * V_2 )
{
const struct V_13 * V_14 = F_7 ( V_2 ) ;
struct V_15 * V_16 = V_2 -> V_17 ;
if ( ! V_14 -> V_18 )
return 0 ;
F_5 ( 0x0 , V_2 -> V_8 + V_12 ) ;
F_8 ( V_16 -> V_19 ) ;
return 0 ;
}
static int F_9 ( struct V_1 * V_2 ,
unsigned long V_20 )
{
struct V_21 * V_22 = F_10 ( V_2 ) ;
const struct V_13 * V_14 = NULL ;
struct V_15 * V_16 ;
struct V_3 * V_4 ;
int V_23 ;
if ( V_20 < F_11 ( V_24 ) )
V_14 = & V_24 [ V_20 ] ;
if ( ! V_14 )
return - V_25 ;
V_2 -> V_26 = V_14 ;
V_2 -> V_27 = V_14 -> V_28 ;
V_16 = F_12 ( V_2 , sizeof( * V_16 ) ) ;
if ( ! V_16 )
return - V_29 ;
V_23 = F_13 ( V_2 ) ;
if ( V_23 )
return V_23 ;
V_2 -> V_8 = F_14 ( V_22 , 1 ) ;
V_16 -> V_19 = F_14 ( V_22 , 2 ) ;
V_23 = F_15 ( V_2 , 3 ) ;
if ( V_23 )
return V_23 ;
V_4 = & V_2 -> V_30 [ 0 ] ;
if ( V_14 -> V_31 ) {
V_4 -> type = V_32 ;
V_4 -> V_33 = V_34 ;
V_4 -> V_35 = V_14 -> V_31 ;
V_4 -> V_36 = 1 ;
V_4 -> V_37 = & V_38 ;
V_4 -> V_39 = F_1 ;
} else {
V_4 -> type = V_40 ;
}
V_4 = & V_2 -> V_30 [ 1 ] ;
if ( V_14 -> V_41 ) {
V_4 -> type = V_42 ;
V_4 -> V_33 = V_43 ;
V_4 -> V_35 = V_14 -> V_41 ;
V_4 -> V_36 = 1 ;
V_4 -> V_37 = & V_38 ;
V_4 -> V_39 = F_3 ;
} else {
V_4 -> type = V_40 ;
}
V_4 = & V_2 -> V_30 [ 2 ] ;
if ( V_14 -> V_18 ) {
V_23 = F_16 ( V_4 , V_16 -> V_19 ) ;
if ( V_23 )
return V_23 ;
} else {
V_4 -> type = V_40 ;
}
F_6 ( V_2 ) ;
return 0 ;
}
static void F_17 ( struct V_1 * V_2 )
{
if ( V_2 -> V_8 )
F_6 ( V_2 ) ;
F_18 ( V_2 ) ;
}
static int F_19 ( struct V_21 * V_2 ,
const struct V_44 * V_45 )
{
return F_20 ( V_2 , & V_46 , V_45 -> V_47 ) ;
}
