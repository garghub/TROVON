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
F_4 ( 0x0 , V_2 -> V_8 + V_14 ) ;
F_6 ( V_2 -> V_8 + V_15 ) ;
return 0 ;
}
static int F_7 ( struct V_1 * V_2 ,
unsigned long V_16 )
{
struct V_17 * V_18 = F_8 ( V_2 ) ;
struct V_3 * V_4 ;
int V_19 ;
V_2 -> V_20 = V_2 -> V_21 -> V_22 ;
V_19 = F_9 ( V_18 , V_2 -> V_20 ) ;
if ( V_19 )
return V_19 ;
V_2 -> V_8 = F_10 ( V_18 , 1 ) ;
V_19 = F_11 ( V_2 , 3 ) ;
if ( V_19 )
return V_19 ;
V_4 = & V_2 -> V_23 [ 0 ] ;
V_4 -> type = V_24 ;
V_4 -> V_25 = V_26 ;
V_4 -> V_27 = 8 ;
V_4 -> V_28 = 1 ;
V_4 -> V_29 = & V_30 ;
V_4 -> V_31 = F_1 ;
V_4 = & V_2 -> V_23 [ 1 ] ;
V_4 -> type = V_32 ;
V_4 -> V_25 = V_33 ;
V_4 -> V_27 = 16 ;
V_4 -> V_28 = 1 ;
V_4 -> V_29 = & V_30 ;
V_4 -> V_31 = F_3 ;
V_4 = & V_2 -> V_23 [ 2 ] ;
V_19 = F_12 ( V_4 , V_2 -> V_8 + V_15 ) ;
if ( V_19 )
return V_19 ;
F_5 ( V_2 ) ;
return 0 ;
}
static void F_13 ( struct V_1 * V_2 )
{
struct V_17 * V_18 = F_8 ( V_2 ) ;
if ( V_2 -> V_8 )
F_5 ( V_2 ) ;
if ( V_2 -> V_23 )
F_14 ( & V_2 -> V_23 [ 2 ] ) ;
if ( V_18 ) {
if ( V_2 -> V_8 )
F_15 ( V_18 ) ;
}
}
static int F_16 ( struct V_17 * V_2 ,
const struct V_34 * V_35 )
{
return F_17 ( V_2 , & V_36 ) ;
}
