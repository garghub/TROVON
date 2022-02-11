static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
V_4 = F_2 ( sizeof( struct V_3 ) , V_5 ) ;
if ( ! V_4 )
return - V_6 ;
F_3 ( V_2 , V_4 ) ;
return 0 ;
}
static int F_4 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
V_4 = F_5 ( V_2 ) ;
F_6 ( V_4 ) ;
return 0 ;
}
static int F_7 ( struct V_7 * V_8 , struct V_1 * V_2 )
{
struct V_9 * V_10 = V_2 -> V_10 ;
struct V_1 * V_11 ;
int V_12 = 0 ;
V_11 = V_10 -> V_2 [ 1 ] ;
F_8 ( & V_11 -> V_2 , V_8 ) ;
V_12 = F_9 ( V_2 -> V_13 , V_5 ) ;
if ( V_12 )
F_10 ( & V_2 -> V_14 ,
L_1 ,
V_15 , V_12 ) ;
return V_12 ;
}
static void F_11 ( struct V_1 * V_2 )
{
F_12 ( V_2 -> V_13 ) ;
}
static void F_13 ( struct V_16 * V_16 )
{
struct V_1 * V_2 = V_16 -> V_17 ;
unsigned char * V_18 = V_16 -> V_19 ;
struct V_20 * V_21 = (struct V_20 * ) & V_18 [ 0 ] ;
int V_22 = V_16 -> V_22 ;
int V_12 ;
if ( V_22 ) {
F_14 ( & V_2 -> V_14 , L_2 ,
V_15 , V_22 ) ;
return;
}
if ( V_16 -> V_23 && V_21 -> V_24 ) {
F_15 ( & V_2 -> V_2 , V_18 + V_25 ,
V_21 -> V_24 ) ;
F_16 ( & V_2 -> V_2 ) ;
}
V_12 = F_9 ( V_16 , V_26 ) ;
if ( V_12 )
F_10 ( & V_2 -> V_14 ,
L_3 ,
V_15 , V_12 ) ;
}
static int F_17 ( struct V_7 * V_8 , struct V_1 * V_2 ,
const unsigned char * V_27 , int V_28 )
{
struct V_9 * V_10 = V_2 -> V_10 ;
struct V_1 * V_11 = V_10 -> V_2 [ 1 ] ;
struct V_3 * V_4 = F_5 ( V_2 ) ;
struct V_20 * V_21 = (struct V_20 * )
V_11 -> V_29 -> V_19 ;
int V_12 ;
if ( V_28 == 0 ) {
F_14 ( & V_2 -> V_14 , L_4 , V_15 ) ;
return 0 ;
}
if ( ! F_18 ( 0 , & V_2 -> V_30 ) ) {
F_14 ( & V_2 -> V_14 , L_5 , V_15 ) ;
return 0 ;
}
V_28 = ( V_28 > V_31 ) ? V_31 : V_28 ;
memcpy ( V_11 -> V_29 -> V_19 + V_25 ,
V_27 , V_28 ) ;
F_19 ( & V_2 -> V_14 , V_15 , V_28 ,
V_11 -> V_29 -> V_19 ) ;
V_21 -> V_32 = V_4 -> V_33 ++ ;
V_21 -> V_24 = V_28 ;
V_21 -> V_34 = 0x03 ;
V_21 -> V_35 = 0x00 ;
V_11 -> V_29 -> V_36 = 64 ;
V_12 = F_9 ( V_11 -> V_29 , V_26 ) ;
if ( V_12 ) {
F_20 ( 0 , & V_11 -> V_30 ) ;
F_21 ( V_2 ,
L_6 ,
V_15 , V_12 ) ;
} else
V_12 = V_28 ;
return V_12 ;
}
static int F_22 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_37 ;
struct V_9 * V_10 = V_2 -> V_10 ;
struct V_1 * V_11 = V_10 -> V_2 [ 1 ] ;
int V_38 = 0 ;
if ( F_23 ( 0 , & V_11 -> V_30 ) )
V_38 = V_11 -> V_39 - V_40 ;
F_14 ( & V_2 -> V_14 , L_7 , V_15 , V_38 ) ;
return V_38 ;
}
static void F_24 ( struct V_16 * V_16 )
{
struct V_1 * V_2 = V_16 -> V_17 ;
int V_22 = V_16 -> V_22 ;
F_20 ( 0 , & V_2 -> V_30 ) ;
if ( V_22 ) {
F_14 ( & V_2 -> V_14 , L_8 ,
V_15 , V_22 ) ;
return;
}
F_25 ( V_2 ) ;
}
static void F_26 ( struct V_9 * V_10 )
{
struct V_1 * V_11 = V_10 -> V_2 [ 1 ] ;
F_12 ( V_11 -> V_29 ) ;
}
