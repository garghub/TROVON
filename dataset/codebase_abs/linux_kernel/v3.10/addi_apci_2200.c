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
V_19 = F_9 ( V_2 ) ;
if ( V_19 )
return V_19 ;
V_2 -> V_8 = F_10 ( V_18 , 1 ) ;
V_19 = F_11 ( V_2 , 3 ) ;
if ( V_19 )
return V_19 ;
V_4 = & V_2 -> V_20 [ 0 ] ;
V_4 -> type = V_21 ;
V_4 -> V_22 = V_23 ;
V_4 -> V_24 = 8 ;
V_4 -> V_25 = 1 ;
V_4 -> V_26 = & V_27 ;
V_4 -> V_28 = F_1 ;
V_4 = & V_2 -> V_20 [ 1 ] ;
V_4 -> type = V_29 ;
V_4 -> V_22 = V_30 ;
V_4 -> V_24 = 16 ;
V_4 -> V_25 = 1 ;
V_4 -> V_26 = & V_27 ;
V_4 -> V_28 = F_3 ;
V_4 = & V_2 -> V_20 [ 2 ] ;
V_19 = F_12 ( V_4 , V_2 -> V_8 + V_15 ) ;
if ( V_19 )
return V_19 ;
F_5 ( V_2 ) ;
return 0 ;
}
static void F_13 ( struct V_1 * V_2 )
{
if ( V_2 -> V_8 )
F_5 ( V_2 ) ;
F_14 ( V_2 , 2 ) ;
F_15 ( V_2 ) ;
}
static int F_16 ( struct V_17 * V_2 ,
const struct V_31 * V_32 )
{
return F_17 ( V_2 , & V_33 , V_32 -> V_34 ) ;
}
