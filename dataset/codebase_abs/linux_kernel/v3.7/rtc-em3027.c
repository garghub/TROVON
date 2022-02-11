static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
unsigned char V_7 = V_8 ;
unsigned char V_9 [ 7 ] ;
struct V_10 V_11 [] = {
{
. V_7 = V_6 -> V_7 ,
. V_12 = 1 ,
. V_9 = & V_7
} ,
{
. V_7 = V_6 -> V_7 ,
. V_13 = V_14 ,
. V_12 = 7 ,
. V_9 = V_9
} ,
} ;
if ( ( F_3 ( V_6 -> V_15 , & V_11 [ 0 ] , 2 ) ) != 2 ) {
F_4 ( & V_6 -> V_2 , L_1 , V_16 ) ;
return - V_17 ;
}
V_4 -> V_18 = F_5 ( V_9 [ 0 ] ) ;
V_4 -> V_19 = F_5 ( V_9 [ 1 ] ) ;
V_4 -> V_20 = F_5 ( V_9 [ 2 ] ) ;
V_4 -> V_21 = F_5 ( V_9 [ 3 ] ) ;
V_4 -> V_22 = F_5 ( V_9 [ 4 ] ) ;
V_4 -> V_23 = F_5 ( V_9 [ 5 ] ) ;
V_4 -> V_24 = F_5 ( V_9 [ 6 ] ) + 100 ;
return 0 ;
}
static int F_6 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
unsigned char V_9 [ 8 ] ;
struct V_10 V_25 = {
. V_7 = V_6 -> V_7 ,
. V_12 = 8 ,
. V_9 = V_9 ,
} ;
V_9 [ 0 ] = V_8 ;
V_9 [ 1 ] = F_7 ( V_4 -> V_18 ) ;
V_9 [ 2 ] = F_7 ( V_4 -> V_19 ) ;
V_9 [ 3 ] = F_7 ( V_4 -> V_20 ) ;
V_9 [ 4 ] = F_7 ( V_4 -> V_21 ) ;
V_9 [ 5 ] = F_7 ( V_4 -> V_22 ) ;
V_9 [ 6 ] = F_7 ( V_4 -> V_23 ) ;
V_9 [ 7 ] = F_7 ( V_4 -> V_24 % 100 ) ;
if ( ( F_3 ( V_6 -> V_15 , & V_25 , 1 ) ) != 1 ) {
F_4 ( & V_6 -> V_2 , L_2 , V_16 ) ;
return - V_17 ;
}
return 0 ;
}
static int F_8 ( struct V_5 * V_6 ,
const struct V_26 * V_27 )
{
struct V_28 * V_29 ;
if ( ! F_9 ( V_6 -> V_15 , V_30 ) )
return - V_31 ;
V_29 = F_10 ( V_32 . V_33 . V_34 , & V_6 -> V_2 ,
& V_35 , V_36 ) ;
if ( F_11 ( V_29 ) )
return F_12 ( V_29 ) ;
F_13 ( V_6 , V_29 ) ;
return 0 ;
}
static int F_14 ( struct V_5 * V_6 )
{
struct V_28 * V_29 = F_15 ( V_6 ) ;
if ( V_29 )
F_16 ( V_29 ) ;
return 0 ;
}
