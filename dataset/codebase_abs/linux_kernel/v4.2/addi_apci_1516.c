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
const struct V_13 * V_14 = V_2 -> V_15 ;
struct V_16 * V_17 = V_2 -> V_18 ;
if ( ! V_14 -> V_19 )
return 0 ;
F_5 ( 0x0 , V_2 -> V_8 + V_12 ) ;
F_7 ( V_17 -> V_20 ) ;
return 0 ;
}
static int F_8 ( struct V_1 * V_2 ,
unsigned long V_21 )
{
struct V_22 * V_23 = F_9 ( V_2 ) ;
const struct V_13 * V_14 = NULL ;
struct V_16 * V_17 ;
struct V_3 * V_4 ;
int V_24 ;
if ( V_21 < F_10 ( V_25 ) )
V_14 = & V_25 [ V_21 ] ;
if ( ! V_14 )
return - V_26 ;
V_2 -> V_15 = V_14 ;
V_2 -> V_27 = V_14 -> V_28 ;
V_17 = F_11 ( V_2 , sizeof( * V_17 ) ) ;
if ( ! V_17 )
return - V_29 ;
V_24 = F_12 ( V_2 ) ;
if ( V_24 )
return V_24 ;
V_2 -> V_8 = F_13 ( V_23 , 1 ) ;
V_17 -> V_20 = F_13 ( V_23 , 2 ) ;
V_24 = F_14 ( V_2 , 3 ) ;
if ( V_24 )
return V_24 ;
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
if ( V_14 -> V_19 ) {
V_24 = F_15 ( V_4 , V_17 -> V_20 ) ;
if ( V_24 )
return V_24 ;
} else {
V_4 -> type = V_40 ;
}
F_6 ( V_2 ) ;
return 0 ;
}
static void F_16 ( struct V_1 * V_2 )
{
if ( V_2 -> V_8 )
F_6 ( V_2 ) ;
F_17 ( V_2 ) ;
}
static int F_18 ( struct V_22 * V_2 ,
const struct V_44 * V_45 )
{
return F_19 ( V_2 , & V_46 , V_45 -> V_47 ) ;
}
