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
static const void * F_8 ( struct V_1 * V_2 ,
struct V_22 * V_23 )
{
const struct V_15 * V_16 ;
int V_24 ;
for ( V_24 = 0 ; V_24 < V_2 -> V_25 -> V_26 ; V_24 ++ ) {
V_16 = & V_27 [ V_24 ] ;
if ( V_16 -> V_28 == V_23 -> V_28 )
return V_16 ;
}
return NULL ;
}
static int F_9 ( struct V_1 * V_2 ,
unsigned long V_29 )
{
struct V_22 * V_23 = F_10 ( V_2 ) ;
const struct V_15 * V_16 ;
struct V_17 * V_18 ;
struct V_3 * V_4 ;
int V_30 ;
V_16 = F_8 ( V_2 , V_23 ) ;
if ( ! V_16 )
return - V_31 ;
V_2 -> V_32 = V_16 ;
V_2 -> V_33 = V_16 -> V_34 ;
V_18 = F_11 ( sizeof( * V_18 ) , V_35 ) ;
if ( ! V_18 )
return - V_36 ;
V_2 -> V_19 = V_18 ;
V_30 = F_12 ( V_23 , V_2 -> V_33 ) ;
if ( V_30 )
return V_30 ;
V_2 -> V_8 = F_13 ( V_23 , 1 ) ;
V_18 -> V_21 = F_13 ( V_23 , 2 ) ;
V_30 = F_14 ( V_2 , 3 ) ;
if ( V_30 )
return V_30 ;
V_4 = & V_2 -> V_37 [ 0 ] ;
if ( V_16 -> V_38 ) {
V_4 -> type = V_39 ;
V_4 -> V_40 = V_41 ;
V_4 -> V_42 = V_16 -> V_38 ;
V_4 -> V_43 = 1 ;
V_4 -> V_44 = & V_45 ;
V_4 -> V_46 = F_1 ;
} else {
V_4 -> type = V_47 ;
}
V_4 = & V_2 -> V_37 [ 1 ] ;
if ( V_16 -> V_48 ) {
V_4 -> type = V_49 ;
V_4 -> V_40 = V_50 ;
V_4 -> V_42 = V_16 -> V_48 ;
V_4 -> V_43 = 1 ;
V_4 -> V_44 = & V_45 ;
V_4 -> V_46 = F_3 ;
} else {
V_4 -> type = V_47 ;
}
V_4 = & V_2 -> V_37 [ 2 ] ;
if ( V_16 -> V_20 ) {
V_30 = F_15 ( V_4 , V_18 -> V_21 ) ;
if ( V_30 )
return V_30 ;
} else {
V_4 -> type = V_47 ;
}
F_5 ( V_2 ) ;
return 0 ;
}
static void F_16 ( struct V_1 * V_2 )
{
struct V_22 * V_23 = F_10 ( V_2 ) ;
if ( V_2 -> V_8 )
F_5 ( V_2 ) ;
if ( V_2 -> V_37 )
F_17 ( & V_2 -> V_37 [ 2 ] ) ;
if ( V_2 -> V_8 )
F_18 ( V_23 ) ;
}
static int F_19 ( struct V_22 * V_2 ,
const struct V_51 * V_52 )
{
return F_20 ( V_2 , & V_53 ) ;
}
