static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
unsigned char V_7 = V_8 ;
unsigned char V_9 [ 7 ] ;
struct V_10 V_11 [] = {
{ V_6 -> V_7 , 0 , 1 , & V_7 } ,
{ V_6 -> V_7 , V_12 , 7 , V_9 } ,
} ;
if ( ( F_3 ( V_6 -> V_13 , & V_11 [ 0 ] , 2 ) ) != 2 ) {
F_4 ( & V_6 -> V_2 , L_1 , V_14 ) ;
return - V_15 ;
}
V_4 -> V_16 = F_5 ( V_9 [ 0 ] ) ;
V_4 -> V_17 = F_5 ( V_9 [ 1 ] ) ;
V_4 -> V_18 = F_5 ( V_9 [ 2 ] ) ;
V_4 -> V_19 = F_5 ( V_9 [ 3 ] ) ;
V_4 -> V_20 = F_5 ( V_9 [ 4 ] ) ;
V_4 -> V_21 = F_5 ( V_9 [ 5 ] ) ;
V_4 -> V_22 = F_5 ( V_9 [ 6 ] ) + 100 ;
return 0 ;
}
static int F_6 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
unsigned char V_9 [ 8 ] ;
struct V_10 V_23 = {
V_6 -> V_7 , 0 , 8 , V_9 ,
} ;
V_9 [ 0 ] = V_8 ;
V_9 [ 1 ] = F_7 ( V_4 -> V_16 ) ;
V_9 [ 2 ] = F_7 ( V_4 -> V_17 ) ;
V_9 [ 3 ] = F_7 ( V_4 -> V_18 ) ;
V_9 [ 4 ] = F_7 ( V_4 -> V_19 ) ;
V_9 [ 5 ] = F_7 ( V_4 -> V_20 ) ;
V_9 [ 6 ] = F_7 ( V_4 -> V_21 ) ;
V_9 [ 7 ] = F_7 ( V_4 -> V_22 % 100 ) ;
if ( ( F_3 ( V_6 -> V_13 , & V_23 , 1 ) ) != 1 ) {
F_4 ( & V_6 -> V_2 , L_2 , V_14 ) ;
return - V_15 ;
}
return 0 ;
}
static int F_8 ( struct V_5 * V_6 ,
const struct V_24 * V_25 )
{
struct V_26 * V_27 ;
if ( ! F_9 ( V_6 -> V_13 , V_28 ) )
return - V_29 ;
V_27 = F_10 ( V_30 . V_31 . V_32 , & V_6 -> V_2 ,
& V_33 , V_34 ) ;
if ( F_11 ( V_27 ) )
return F_12 ( V_27 ) ;
F_13 ( V_6 , V_27 ) ;
return 0 ;
}
static int F_14 ( struct V_5 * V_6 )
{
struct V_26 * V_27 = F_15 ( V_6 ) ;
if ( V_27 )
F_16 ( V_27 ) ;
return 0 ;
}
