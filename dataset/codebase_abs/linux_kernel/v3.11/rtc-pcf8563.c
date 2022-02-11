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
if ( V_6 [ V_18 ] & V_19 ) {
V_5 -> V_20 = 1 ;
F_5 ( & V_2 -> V_15 ,
L_2 ) ;
}
F_6 ( & V_2 -> V_15 ,
L_3
L_4 ,
V_16 ,
V_6 [ 0 ] , V_6 [ 1 ] , V_6 [ 2 ] , V_6 [ 3 ] ,
V_6 [ 4 ] , V_6 [ 5 ] , V_6 [ 6 ] , V_6 [ 7 ] ,
V_6 [ 8 ] ) ;
V_4 -> V_21 = F_7 ( V_6 [ V_18 ] & 0x7F ) ;
V_4 -> V_22 = F_7 ( V_6 [ V_23 ] & 0x7F ) ;
V_4 -> V_24 = F_7 ( V_6 [ V_25 ] & 0x3F ) ;
V_4 -> V_26 = F_7 ( V_6 [ V_27 ] & 0x3F ) ;
V_4 -> V_28 = V_6 [ V_29 ] & 0x07 ;
V_4 -> V_30 = F_7 ( V_6 [ V_31 ] & 0x1F ) - 1 ;
V_4 -> V_32 = F_7 ( V_6 [ V_33 ] ) ;
if ( V_4 -> V_32 < 70 )
V_4 -> V_32 += 100 ;
V_5 -> V_34 = ( V_6 [ V_31 ] & V_35 ) ?
( V_4 -> V_32 >= 100 ) : ( V_4 -> V_32 < 100 ) ;
F_6 ( & V_2 -> V_15 , L_5
L_6 ,
V_16 ,
V_4 -> V_21 , V_4 -> V_22 , V_4 -> V_24 ,
V_4 -> V_26 , V_4 -> V_30 , V_4 -> V_32 , V_4 -> V_28 ) ;
if ( F_8 ( V_4 ) < 0 )
F_4 ( & V_2 -> V_15 , L_7 ) ;
return 0 ;
}
static int F_9 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_5 = F_2 ( V_2 ) ;
int V_36 , V_37 ;
unsigned char V_6 [ 9 ] ;
F_6 ( & V_2 -> V_15 , L_8
L_6 ,
V_16 ,
V_4 -> V_21 , V_4 -> V_22 , V_4 -> V_24 ,
V_4 -> V_26 , V_4 -> V_30 , V_4 -> V_32 , V_4 -> V_28 ) ;
V_6 [ V_18 ] = F_10 ( V_4 -> V_21 ) ;
V_6 [ V_23 ] = F_10 ( V_4 -> V_22 ) ;
V_6 [ V_25 ] = F_10 ( V_4 -> V_24 ) ;
V_6 [ V_27 ] = F_10 ( V_4 -> V_26 ) ;
V_6 [ V_31 ] = F_10 ( V_4 -> V_30 + 1 ) ;
V_6 [ V_33 ] = F_10 ( V_4 -> V_32 % 100 ) ;
if ( V_5 -> V_34 ? ( V_4 -> V_32 >= 100 ) : ( V_4 -> V_32 < 100 ) )
V_6 [ V_31 ] |= V_35 ;
V_6 [ V_29 ] = V_4 -> V_28 & 0x07 ;
for ( V_36 = 0 ; V_36 < 7 ; V_36 ++ ) {
unsigned char V_38 [ 2 ] = { V_18 + V_36 ,
V_6 [ V_18 + V_36 ] } ;
V_37 = F_11 ( V_2 , V_38 , sizeof( V_38 ) ) ;
if ( V_37 != sizeof( V_38 ) ) {
F_4 ( & V_2 -> V_15 ,
L_9 ,
V_16 , V_37 , V_38 [ 0 ] , V_38 [ 1 ] ) ;
return - V_17 ;
}
}
return 0 ;
}
static int F_12 ( struct V_39 * V_15 , unsigned int V_40 , unsigned long V_41 )
{
struct V_5 * V_5 = F_2 ( F_13 ( V_15 ) ) ;
struct V_3 V_4 ;
switch ( V_40 ) {
case V_42 :
if ( V_5 -> V_20 )
F_5 ( V_15 , L_2 ) ;
if ( F_14 ( ( void V_43 * ) V_41 , & V_5 -> V_20 ,
sizeof( int ) ) )
return - V_44 ;
return 0 ;
case V_45 :
if ( F_1 ( F_13 ( V_15 ) , & V_4 ) )
F_9 ( F_13 ( V_15 ) , & V_4 ) ;
V_5 -> V_20 = 0 ;
return 0 ;
default:
return - V_46 ;
}
}
static int F_15 ( struct V_39 * V_15 , struct V_3 * V_4 )
{
return F_1 ( F_13 ( V_15 ) , V_4 ) ;
}
static int F_16 ( struct V_39 * V_15 , struct V_3 * V_4 )
{
return F_9 ( F_13 ( V_15 ) , V_4 ) ;
}
static int F_17 ( struct V_1 * V_2 ,
const struct V_47 * V_48 )
{
struct V_5 * V_5 ;
F_6 ( & V_2 -> V_15 , L_10 , V_16 ) ;
if ( ! F_18 ( V_2 -> V_14 , V_49 ) )
return - V_50 ;
V_5 = F_19 ( & V_2 -> V_15 , sizeof( struct V_5 ) ,
V_51 ) ;
if ( ! V_5 )
return - V_52 ;
F_5 ( & V_2 -> V_15 , L_11 V_53 L_12 ) ;
F_20 ( V_2 , V_5 ) ;
V_5 -> V_54 = F_21 ( & V_2 -> V_15 ,
V_55 . V_56 . V_57 ,
& V_58 , V_59 ) ;
return F_22 ( V_5 -> V_54 ) ;
}
