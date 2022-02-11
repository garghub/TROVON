static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
V_4 = F_2 ( sizeof( * V_4 ) , V_5 ) ;
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
V_11 = V_10 -> V_2 [ 1 ] ;
F_8 ( & V_11 -> V_2 , V_8 ) ;
return F_9 ( V_8 , V_2 ) ;
}
static void F_10 ( struct V_12 * V_12 )
{
struct V_1 * V_2 = V_12 -> V_13 ;
const struct V_14 * V_15 = V_12 -> V_16 ;
const unsigned char * V_17 ;
T_1 V_18 ;
if ( V_12 -> V_19 <= V_20 || ! V_15 -> V_21 )
return;
V_17 = ( char * ) V_12 -> V_16 + V_20 ;
V_18 = F_11 ( T_1 , V_12 -> V_19 - V_20 ,
V_15 -> V_21 ) ;
F_12 ( & V_2 -> V_2 , V_17 , V_18 ) ;
F_13 ( & V_2 -> V_2 ) ;
}
static int F_14 ( struct V_7 * V_8 , struct V_1 * V_2 ,
const unsigned char * V_22 , int V_23 )
{
struct V_9 * V_10 = V_2 -> V_10 ;
struct V_1 * V_11 = V_10 -> V_2 [ 1 ] ;
struct V_3 * V_4 = F_5 ( V_2 ) ;
struct V_14 * V_24 = (struct V_14 * )
V_11 -> V_25 -> V_16 ;
int V_26 ;
if ( V_23 == 0 ) {
F_15 ( & V_2 -> V_27 , L_1 , V_28 ) ;
return 0 ;
}
if ( ! F_16 ( 0 , & V_2 -> V_29 ) ) {
F_15 ( & V_2 -> V_27 , L_2 , V_28 ) ;
return 0 ;
}
V_23 = ( V_23 > V_30 ) ? V_30 : V_23 ;
memcpy ( V_11 -> V_25 -> V_16 + V_20 ,
V_22 , V_23 ) ;
F_17 ( & V_2 -> V_27 , V_28 , V_23 ,
V_11 -> V_25 -> V_16 ) ;
V_24 -> V_31 = V_4 -> V_32 ++ ;
V_24 -> V_21 = V_23 ;
V_24 -> V_33 = 0x03 ;
V_24 -> V_34 = 0x00 ;
V_11 -> V_25 -> V_35 = V_36 ;
V_26 = F_18 ( V_11 -> V_25 , V_37 ) ;
if ( V_26 ) {
F_19 ( 0 , & V_11 -> V_29 ) ;
F_20 ( V_2 ,
L_3 ,
V_28 , V_26 ) ;
} else
V_26 = V_23 ;
return V_26 ;
}
static int F_21 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_38 ;
struct V_9 * V_10 = V_2 -> V_10 ;
struct V_1 * V_11 = V_10 -> V_2 [ 1 ] ;
int V_39 = 0 ;
if ( F_22 ( 0 , & V_11 -> V_29 ) )
V_39 = V_11 -> V_40 - V_20 ;
F_15 ( & V_2 -> V_27 , L_4 , V_28 , V_39 ) ;
return V_39 ;
}
static void F_23 ( struct V_12 * V_12 )
{
struct V_1 * V_2 = V_12 -> V_13 ;
int V_41 = V_12 -> V_41 ;
F_19 ( 0 , & V_2 -> V_29 ) ;
if ( V_41 ) {
F_15 ( & V_2 -> V_27 , L_5 ,
V_28 , V_41 ) ;
return;
}
F_24 ( V_2 ) ;
}
static void F_25 ( struct V_9 * V_10 )
{
struct V_1 * V_11 = V_10 -> V_2 [ 1 ] ;
F_26 ( V_11 -> V_25 ) ;
}
