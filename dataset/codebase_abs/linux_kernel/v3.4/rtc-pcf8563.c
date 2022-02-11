static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_5 = F_2 ( V_2 ) ;
unsigned char V_6 [ 13 ] = { V_7 } ;
struct V_8 V_9 [] = {
{ V_2 -> V_10 , 0 , 1 , V_6 } ,
{ V_2 -> V_10 , V_11 , 13 , V_6 } ,
} ;
if ( ( F_3 ( V_2 -> V_12 , V_9 , 2 ) ) != 2 ) {
F_4 ( & V_2 -> V_13 , L_1 , V_14 ) ;
return - V_15 ;
}
if ( V_6 [ V_16 ] & V_17 )
F_5 ( & V_2 -> V_13 ,
L_2 ) ;
F_6 ( & V_2 -> V_13 ,
L_3
L_4 ,
V_14 ,
V_6 [ 0 ] , V_6 [ 1 ] , V_6 [ 2 ] , V_6 [ 3 ] ,
V_6 [ 4 ] , V_6 [ 5 ] , V_6 [ 6 ] , V_6 [ 7 ] ,
V_6 [ 8 ] ) ;
V_4 -> V_18 = F_7 ( V_6 [ V_16 ] & 0x7F ) ;
V_4 -> V_19 = F_7 ( V_6 [ V_20 ] & 0x7F ) ;
V_4 -> V_21 = F_7 ( V_6 [ V_22 ] & 0x3F ) ;
V_4 -> V_23 = F_7 ( V_6 [ V_24 ] & 0x3F ) ;
V_4 -> V_25 = V_6 [ V_26 ] & 0x07 ;
V_4 -> V_27 = F_7 ( V_6 [ V_28 ] & 0x1F ) - 1 ;
V_4 -> V_29 = F_7 ( V_6 [ V_30 ] ) ;
if ( V_4 -> V_29 < 70 )
V_4 -> V_29 += 100 ;
V_5 -> V_31 = ( V_6 [ V_28 ] & V_32 ) ?
( V_4 -> V_29 >= 100 ) : ( V_4 -> V_29 < 100 ) ;
F_6 ( & V_2 -> V_13 , L_5
L_6 ,
V_14 ,
V_4 -> V_18 , V_4 -> V_19 , V_4 -> V_21 ,
V_4 -> V_23 , V_4 -> V_27 , V_4 -> V_29 , V_4 -> V_25 ) ;
if ( F_8 ( V_4 ) < 0 )
F_4 ( & V_2 -> V_13 , L_7 ) ;
return 0 ;
}
static int F_9 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_5 = F_2 ( V_2 ) ;
int V_33 , V_34 ;
unsigned char V_6 [ 9 ] ;
F_6 ( & V_2 -> V_13 , L_8
L_6 ,
V_14 ,
V_4 -> V_18 , V_4 -> V_19 , V_4 -> V_21 ,
V_4 -> V_23 , V_4 -> V_27 , V_4 -> V_29 , V_4 -> V_25 ) ;
V_6 [ V_16 ] = F_10 ( V_4 -> V_18 ) ;
V_6 [ V_20 ] = F_10 ( V_4 -> V_19 ) ;
V_6 [ V_22 ] = F_10 ( V_4 -> V_21 ) ;
V_6 [ V_24 ] = F_10 ( V_4 -> V_23 ) ;
V_6 [ V_28 ] = F_10 ( V_4 -> V_27 + 1 ) ;
V_6 [ V_30 ] = F_10 ( V_4 -> V_29 % 100 ) ;
if ( V_5 -> V_31 ? ( V_4 -> V_29 >= 100 ) : ( V_4 -> V_29 < 100 ) )
V_6 [ V_28 ] |= V_32 ;
V_6 [ V_26 ] = V_4 -> V_25 & 0x07 ;
for ( V_33 = 0 ; V_33 < 7 ; V_33 ++ ) {
unsigned char V_35 [ 2 ] = { V_16 + V_33 ,
V_6 [ V_16 + V_33 ] } ;
V_34 = F_11 ( V_2 , V_35 , sizeof( V_35 ) ) ;
if ( V_34 != sizeof( V_35 ) ) {
F_4 ( & V_2 -> V_13 ,
L_9 ,
V_14 , V_34 , V_35 [ 0 ] , V_35 [ 1 ] ) ;
return - V_15 ;
}
} ;
return 0 ;
}
static int F_12 ( struct V_36 * V_13 , struct V_3 * V_4 )
{
return F_1 ( F_13 ( V_13 ) , V_4 ) ;
}
static int F_14 ( struct V_36 * V_13 , struct V_3 * V_4 )
{
return F_9 ( F_13 ( V_13 ) , V_4 ) ;
}
static int F_15 ( struct V_1 * V_2 ,
const struct V_37 * V_38 )
{
struct V_5 * V_5 ;
int V_34 = 0 ;
F_6 ( & V_2 -> V_13 , L_10 , V_14 ) ;
if ( ! F_16 ( V_2 -> V_12 , V_39 ) )
return - V_40 ;
V_5 = F_17 ( sizeof( struct V_5 ) , V_41 ) ;
if ( ! V_5 )
return - V_42 ;
F_5 ( & V_2 -> V_13 , L_11 V_43 L_12 ) ;
F_18 ( V_2 , V_5 ) ;
V_5 -> V_44 = F_19 ( V_45 . V_46 . V_47 ,
& V_2 -> V_13 , & V_48 , V_49 ) ;
if ( F_20 ( V_5 -> V_44 ) ) {
V_34 = F_21 ( V_5 -> V_44 ) ;
goto V_50;
}
return 0 ;
V_50:
F_22 ( V_5 ) ;
return V_34 ;
}
static int F_23 ( struct V_1 * V_2 )
{
struct V_5 * V_5 = F_2 ( V_2 ) ;
if ( V_5 -> V_44 )
F_24 ( V_5 -> V_44 ) ;
F_22 ( V_5 ) ;
return 0 ;
}
