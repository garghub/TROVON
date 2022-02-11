static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_5 = F_2 ( V_2 ) ;
unsigned char V_6 [ 13 ] = { V_7 } ;
struct V_8 V_9 [] = {
{
. V_10 = V_2 -> V_10 ,
. V_11 = 1 ,
. V_6 = V_6
} ,
{
. V_10 = V_2 -> V_10 ,
. V_12 = V_13 ,
. V_11 = 13 ,
. V_6 = V_6
} ,
} ;
if ( ( F_3 ( V_2 -> V_14 , V_9 , 2 ) ) != 2 ) {
F_4 ( & V_2 -> V_15 , L_1 , V_16 ) ;
return - V_17 ;
}
V_4 -> V_18 = F_5 ( V_6 [ V_19 ] & 0x7F ) ;
V_4 -> V_20 = F_5 ( V_6 [ V_21 ] & 0x7F ) ;
V_4 -> V_22 = F_5 ( V_6 [ V_23 ] & 0x3F ) ;
V_4 -> V_24 = F_5 ( V_6 [ V_25 ] & 0x3F ) ;
V_4 -> V_26 = V_6 [ V_27 ] & 0x07 ;
V_4 -> V_28 = F_5 ( V_6 [ V_29 ] & 0x1F ) - 1 ;
V_4 -> V_30 = F_5 ( V_6 [ V_31 ] ) ;
if ( V_4 -> V_30 < 70 )
V_4 -> V_30 += 100 ;
V_5 -> V_32 = ( V_6 [ V_29 ] & V_33 ) ?
( V_4 -> V_30 >= 100 ) : ( V_4 -> V_30 < 100 ) ;
if ( F_6 ( V_4 ) < 0 )
F_4 ( & V_2 -> V_15 , L_2 ) ;
return 0 ;
}
static int F_7 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
int V_34 = 0 , V_35 = 0 ;
unsigned char V_6 [ 11 ] ;
V_6 [ V_7 ] = 0 ;
V_6 [ V_36 ] = 5 ;
V_6 [ V_19 ] = F_8 ( V_4 -> V_18 ) & 0x7F ;
V_6 [ V_21 ] = F_8 ( V_4 -> V_20 ) ;
V_6 [ V_23 ] = F_8 ( V_4 -> V_22 ) ;
V_6 [ V_25 ] = F_8 ( V_4 -> V_24 ) ;
V_6 [ V_27 ] = V_4 -> V_26 & 0x07 ;
V_6 [ V_29 ] = F_8 ( V_4 -> V_28 + 1 ) ;
V_6 [ V_31 ] = F_8 ( V_4 -> V_30 % 100 ) ;
for ( V_34 = 0 ; V_34 < sizeof( V_6 ) ; V_34 ++ ) {
unsigned char V_37 [ 2 ] = { V_34 , V_6 [ V_34 ] } ;
V_35 = F_9 ( V_2 , V_37 , sizeof( V_37 ) ) ;
if ( V_35 != sizeof( V_37 ) ) {
F_4 ( & V_2 -> V_15 , L_3 ,
V_16 , V_35 , V_37 [ 0 ] , V_37 [ 1 ] ) ;
return - V_17 ;
}
}
return 0 ;
}
static int F_10 ( struct V_38 * V_15 , struct V_3 * V_4 )
{
return F_1 ( F_11 ( V_15 ) , V_4 ) ;
}
static int F_12 ( struct V_38 * V_15 , struct V_3 * V_4 )
{
return F_7 ( F_11 ( V_15 ) , V_4 ) ;
}
static int F_13 ( struct V_1 * V_2 ,
const struct V_39 * V_40 )
{
struct V_5 * V_5 ;
F_14 ( & V_2 -> V_15 , L_4 , V_16 ) ;
if ( ! F_15 ( V_2 -> V_14 , V_41 ) )
return - V_42 ;
V_5 = F_16 ( & V_2 -> V_15 , sizeof( struct V_5 ) ,
V_43 ) ;
if ( ! V_5 )
return - V_44 ;
F_17 ( & V_2 -> V_15 , L_5 V_45 L_6 ) ;
F_18 ( V_2 , V_5 ) ;
V_5 -> V_46 = F_19 ( & V_2 -> V_15 ,
V_47 . V_48 . V_49 ,
& V_50 , V_51 ) ;
return F_20 ( V_5 -> V_46 ) ;
}
