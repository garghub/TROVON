static int F_1 ( struct V_1 * V_2 )
{
if ( V_2 -> V_3 < 2 ) {
F_2 ( & V_2 -> V_4 -> V_5 , L_1 ) ;
return - V_6 ;
}
return 0 ;
}
static int F_3 ( struct V_7 * V_8 )
{
struct V_9 * V_10 ;
V_10 = F_4 ( sizeof( * V_10 ) , V_11 ) ;
if ( ! V_10 )
return - V_12 ;
F_5 ( V_8 , V_10 ) ;
return 0 ;
}
static int F_6 ( struct V_7 * V_8 )
{
struct V_9 * V_10 ;
V_10 = F_7 ( V_8 ) ;
F_8 ( V_10 ) ;
return 0 ;
}
static void F_9 ( struct V_13 * V_13 )
{
struct V_7 * V_8 = V_13 -> V_14 ;
const struct V_15 * V_16 = V_13 -> V_17 ;
const unsigned char * V_18 ;
T_1 V_19 ;
if ( V_13 -> V_20 <= V_21 || ! V_16 -> V_22 )
return;
V_18 = ( char * ) V_13 -> V_17 + V_21 ;
V_19 = F_10 ( T_1 , V_13 -> V_20 - V_21 ,
V_16 -> V_22 ) ;
F_11 ( & V_8 -> V_8 , V_18 , V_19 ) ;
F_12 ( & V_8 -> V_8 ) ;
}
static int F_13 ( struct V_23 * V_24 , struct V_7 * V_8 ,
const unsigned char * V_25 , int V_26 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
struct V_7 * V_27 = V_2 -> V_8 [ 1 ] ;
struct V_9 * V_10 = F_7 ( V_8 ) ;
struct V_15 * V_28 = (struct V_15 * )
V_27 -> V_29 -> V_17 ;
int V_30 ;
if ( V_26 == 0 ) {
F_14 ( & V_8 -> V_5 , L_2 , V_31 ) ;
return 0 ;
}
if ( ! F_15 ( 0 , & V_8 -> V_32 ) ) {
F_14 ( & V_8 -> V_5 , L_3 , V_31 ) ;
return 0 ;
}
V_26 = ( V_26 > V_33 ) ? V_33 : V_26 ;
memcpy ( V_27 -> V_29 -> V_17 + V_21 ,
V_25 , V_26 ) ;
F_16 ( & V_8 -> V_5 , V_31 , V_26 ,
V_27 -> V_29 -> V_17 ) ;
V_28 -> V_34 = V_10 -> V_35 ++ ;
V_28 -> V_22 = V_26 ;
V_28 -> V_36 = 0x03 ;
V_28 -> V_37 = 0x00 ;
V_27 -> V_29 -> V_38 = V_39 ;
V_30 = F_17 ( V_27 -> V_29 , V_40 ) ;
if ( V_30 ) {
F_18 ( 0 , & V_27 -> V_32 ) ;
F_19 ( V_8 ,
L_4 ,
V_31 , V_30 ) ;
} else
V_30 = V_26 ;
return V_30 ;
}
static int F_20 ( struct V_23 * V_24 )
{
struct V_7 * V_8 = V_24 -> V_41 ;
struct V_1 * V_2 = V_8 -> V_2 ;
struct V_7 * V_27 = V_2 -> V_8 [ 1 ] ;
int V_42 = 0 ;
if ( F_21 ( 0 , & V_27 -> V_32 ) )
V_42 = V_27 -> V_43 - V_21 ;
F_14 ( & V_8 -> V_5 , L_5 , V_31 , V_42 ) ;
return V_42 ;
}
static void F_22 ( struct V_13 * V_13 )
{
struct V_7 * V_8 = V_13 -> V_14 ;
int V_44 = V_13 -> V_44 ;
F_18 ( 0 , & V_8 -> V_32 ) ;
if ( V_44 ) {
F_14 ( & V_8 -> V_5 , L_6 ,
V_31 , V_44 ) ;
return;
}
F_23 ( V_8 ) ;
}
static void F_24 ( struct V_1 * V_2 )
{
struct V_7 * V_27 = V_2 -> V_8 [ 1 ] ;
F_25 ( V_27 -> V_29 ) ;
}
