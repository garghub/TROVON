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
if ( V_6 [ V_16 ] & V_17 ) {
V_5 -> V_18 = 1 ;
F_5 ( & V_2 -> V_13 ,
L_2 ) ;
}
F_6 ( & V_2 -> V_13 ,
L_3
L_4 ,
V_14 ,
V_6 [ 0 ] , V_6 [ 1 ] , V_6 [ 2 ] , V_6 [ 3 ] ,
V_6 [ 4 ] , V_6 [ 5 ] , V_6 [ 6 ] , V_6 [ 7 ] ,
V_6 [ 8 ] ) ;
V_4 -> V_19 = F_7 ( V_6 [ V_16 ] & 0x7F ) ;
V_4 -> V_20 = F_7 ( V_6 [ V_21 ] & 0x7F ) ;
V_4 -> V_22 = F_7 ( V_6 [ V_23 ] & 0x3F ) ;
V_4 -> V_24 = F_7 ( V_6 [ V_25 ] & 0x3F ) ;
V_4 -> V_26 = V_6 [ V_27 ] & 0x07 ;
V_4 -> V_28 = F_7 ( V_6 [ V_29 ] & 0x1F ) - 1 ;
V_4 -> V_30 = F_7 ( V_6 [ V_31 ] ) ;
if ( V_4 -> V_30 < 70 )
V_4 -> V_30 += 100 ;
V_5 -> V_32 = ( V_6 [ V_29 ] & V_33 ) ?
( V_4 -> V_30 >= 100 ) : ( V_4 -> V_30 < 100 ) ;
F_6 ( & V_2 -> V_13 , L_5
L_6 ,
V_14 ,
V_4 -> V_19 , V_4 -> V_20 , V_4 -> V_22 ,
V_4 -> V_24 , V_4 -> V_28 , V_4 -> V_30 , V_4 -> V_26 ) ;
if ( F_8 ( V_4 ) < 0 )
F_4 ( & V_2 -> V_13 , L_7 ) ;
return 0 ;
}
static int F_9 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_5 = F_2 ( V_2 ) ;
int V_34 , V_35 ;
unsigned char V_6 [ 9 ] ;
F_6 ( & V_2 -> V_13 , L_8
L_6 ,
V_14 ,
V_4 -> V_19 , V_4 -> V_20 , V_4 -> V_22 ,
V_4 -> V_24 , V_4 -> V_28 , V_4 -> V_30 , V_4 -> V_26 ) ;
V_6 [ V_16 ] = F_10 ( V_4 -> V_19 ) ;
V_6 [ V_21 ] = F_10 ( V_4 -> V_20 ) ;
V_6 [ V_23 ] = F_10 ( V_4 -> V_22 ) ;
V_6 [ V_25 ] = F_10 ( V_4 -> V_24 ) ;
V_6 [ V_29 ] = F_10 ( V_4 -> V_28 + 1 ) ;
V_6 [ V_31 ] = F_10 ( V_4 -> V_30 % 100 ) ;
if ( V_5 -> V_32 ? ( V_4 -> V_30 >= 100 ) : ( V_4 -> V_30 < 100 ) )
V_6 [ V_29 ] |= V_33 ;
V_6 [ V_27 ] = V_4 -> V_26 & 0x07 ;
for ( V_34 = 0 ; V_34 < 7 ; V_34 ++ ) {
unsigned char V_36 [ 2 ] = { V_16 + V_34 ,
V_6 [ V_16 + V_34 ] } ;
V_35 = F_11 ( V_2 , V_36 , sizeof( V_36 ) ) ;
if ( V_35 != sizeof( V_36 ) ) {
F_4 ( & V_2 -> V_13 ,
L_9 ,
V_14 , V_35 , V_36 [ 0 ] , V_36 [ 1 ] ) ;
return - V_15 ;
}
} ;
return 0 ;
}
static int F_12 ( struct V_37 * V_13 , unsigned int V_38 , unsigned long V_39 )
{
struct V_5 * V_5 = F_2 ( F_13 ( V_13 ) ) ;
struct V_3 V_4 ;
switch ( V_38 ) {
case V_40 :
if ( V_5 -> V_18 )
F_5 ( V_13 , L_2 ) ;
if ( F_14 ( ( void V_41 * ) V_39 , & V_5 -> V_18 ,
sizeof( int ) ) )
return - V_42 ;
return 0 ;
case V_43 :
if ( F_1 ( F_13 ( V_13 ) , & V_4 ) )
F_9 ( F_13 ( V_13 ) , & V_4 ) ;
V_5 -> V_18 = 0 ;
return 0 ;
default:
return - V_44 ;
}
}
static int F_15 ( struct V_37 * V_13 , struct V_3 * V_4 )
{
return F_1 ( F_13 ( V_13 ) , V_4 ) ;
}
static int F_16 ( struct V_37 * V_13 , struct V_3 * V_4 )
{
return F_9 ( F_13 ( V_13 ) , V_4 ) ;
}
static int F_17 ( struct V_1 * V_2 ,
const struct V_45 * V_46 )
{
struct V_5 * V_5 ;
int V_35 = 0 ;
F_6 ( & V_2 -> V_13 , L_10 , V_14 ) ;
if ( ! F_18 ( V_2 -> V_12 , V_47 ) )
return - V_48 ;
V_5 = F_19 ( sizeof( struct V_5 ) , V_49 ) ;
if ( ! V_5 )
return - V_50 ;
F_5 ( & V_2 -> V_13 , L_11 V_51 L_12 ) ;
F_20 ( V_2 , V_5 ) ;
V_5 -> V_52 = F_21 ( V_53 . V_54 . V_55 ,
& V_2 -> V_13 , & V_56 , V_57 ) ;
if ( F_22 ( V_5 -> V_52 ) ) {
V_35 = F_23 ( V_5 -> V_52 ) ;
goto V_58;
}
return 0 ;
V_58:
F_24 ( V_5 ) ;
return V_35 ;
}
static int F_25 ( struct V_1 * V_2 )
{
struct V_5 * V_5 = F_2 ( V_2 ) ;
if ( V_5 -> V_52 )
F_26 ( V_5 -> V_52 ) ;
F_24 ( V_5 ) ;
return 0 ;
}
