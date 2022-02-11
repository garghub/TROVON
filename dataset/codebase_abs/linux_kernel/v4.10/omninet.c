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
static int F_9 ( struct V_13 * V_14 , struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
struct V_7 * V_15 ;
V_15 = V_2 -> V_8 [ 1 ] ;
F_10 ( & V_15 -> V_8 , V_14 ) ;
return F_11 ( V_14 , V_8 ) ;
}
static void F_12 ( struct V_16 * V_16 )
{
struct V_7 * V_8 = V_16 -> V_17 ;
const struct V_18 * V_19 = V_16 -> V_20 ;
const unsigned char * V_21 ;
T_1 V_22 ;
if ( V_16 -> V_23 <= V_24 || ! V_19 -> V_25 )
return;
V_21 = ( char * ) V_16 -> V_20 + V_24 ;
V_22 = F_13 ( T_1 , V_16 -> V_23 - V_24 ,
V_19 -> V_25 ) ;
F_14 ( & V_8 -> V_8 , V_21 , V_22 ) ;
F_15 ( & V_8 -> V_8 ) ;
}
static int F_16 ( struct V_13 * V_14 , struct V_7 * V_8 ,
const unsigned char * V_26 , int V_27 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
struct V_7 * V_15 = V_2 -> V_8 [ 1 ] ;
struct V_9 * V_10 = F_7 ( V_8 ) ;
struct V_18 * V_28 = (struct V_18 * )
V_15 -> V_29 -> V_20 ;
int V_30 ;
if ( V_27 == 0 ) {
F_17 ( & V_8 -> V_5 , L_2 , V_31 ) ;
return 0 ;
}
if ( ! F_18 ( 0 , & V_8 -> V_32 ) ) {
F_17 ( & V_8 -> V_5 , L_3 , V_31 ) ;
return 0 ;
}
V_27 = ( V_27 > V_33 ) ? V_33 : V_27 ;
memcpy ( V_15 -> V_29 -> V_20 + V_24 ,
V_26 , V_27 ) ;
F_19 ( & V_8 -> V_5 , V_31 , V_27 ,
V_15 -> V_29 -> V_20 ) ;
V_28 -> V_34 = V_10 -> V_35 ++ ;
V_28 -> V_25 = V_27 ;
V_28 -> V_36 = 0x03 ;
V_28 -> V_37 = 0x00 ;
V_15 -> V_29 -> V_38 = V_39 ;
V_30 = F_20 ( V_15 -> V_29 , V_40 ) ;
if ( V_30 ) {
F_21 ( 0 , & V_15 -> V_32 ) ;
F_22 ( V_8 ,
L_4 ,
V_31 , V_30 ) ;
} else
V_30 = V_27 ;
return V_30 ;
}
static int F_23 ( struct V_13 * V_14 )
{
struct V_7 * V_8 = V_14 -> V_41 ;
struct V_1 * V_2 = V_8 -> V_2 ;
struct V_7 * V_15 = V_2 -> V_8 [ 1 ] ;
int V_42 = 0 ;
if ( F_24 ( 0 , & V_15 -> V_32 ) )
V_42 = V_15 -> V_43 - V_24 ;
F_17 ( & V_8 -> V_5 , L_5 , V_31 , V_42 ) ;
return V_42 ;
}
static void F_25 ( struct V_16 * V_16 )
{
struct V_7 * V_8 = V_16 -> V_17 ;
int V_44 = V_16 -> V_44 ;
F_21 ( 0 , & V_8 -> V_32 ) ;
if ( V_44 ) {
F_17 ( & V_8 -> V_5 , L_6 ,
V_31 , V_44 ) ;
return;
}
F_26 ( V_8 ) ;
}
static void F_27 ( struct V_1 * V_2 )
{
struct V_7 * V_15 = V_2 -> V_8 [ 1 ] ;
F_28 ( V_15 -> V_29 ) ;
}
