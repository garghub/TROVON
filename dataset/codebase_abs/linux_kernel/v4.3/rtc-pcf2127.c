static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_5 = F_2 ( V_2 ) ;
unsigned char V_6 [ 10 ] = { V_7 } ;
if ( F_3 ( V_2 , V_6 , 1 ) != 1 ||
F_4 ( V_2 , V_6 , sizeof( V_6 ) ) != sizeof( V_6 ) ) {
F_5 ( & V_2 -> V_8 , L_1 , V_9 ) ;
return - V_10 ;
}
if ( V_6 [ V_11 ] & 0x04 ) {
V_5 -> V_12 = 1 ;
F_6 ( & V_2 -> V_8 ,
L_2 ) ;
}
if ( V_6 [ V_13 ] & V_14 ) {
V_5 -> V_15 = 1 ;
F_7 ( & V_2 -> V_8 ,
L_3 ) ;
return - V_16 ;
}
F_8 ( & V_2 -> V_8 ,
L_4
L_5
L_6 ,
V_9 ,
V_6 [ 0 ] , V_6 [ 1 ] , V_6 [ 2 ] ,
V_6 [ 3 ] , V_6 [ 4 ] , V_6 [ 5 ] ,
V_6 [ 6 ] , V_6 [ 7 ] , V_6 [ 8 ] , V_6 [ 9 ] ) ;
V_4 -> V_17 = F_9 ( V_6 [ V_13 ] & 0x7F ) ;
V_4 -> V_18 = F_9 ( V_6 [ V_19 ] & 0x7F ) ;
V_4 -> V_20 = F_9 ( V_6 [ V_21 ] & 0x3F ) ;
V_4 -> V_22 = F_9 ( V_6 [ V_23 ] & 0x3F ) ;
V_4 -> V_24 = V_6 [ V_25 ] & 0x07 ;
V_4 -> V_26 = F_9 ( V_6 [ V_27 ] & 0x1F ) - 1 ;
V_4 -> V_28 = F_9 ( V_6 [ V_29 ] ) ;
if ( V_4 -> V_28 < 70 )
V_4 -> V_28 += 100 ;
F_8 ( & V_2 -> V_8 , L_7
L_8 ,
V_9 ,
V_4 -> V_17 , V_4 -> V_18 , V_4 -> V_20 ,
V_4 -> V_22 , V_4 -> V_26 , V_4 -> V_28 , V_4 -> V_24 ) ;
return F_10 ( V_4 ) ;
}
static int F_11 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_5 = F_2 ( V_2 ) ;
unsigned char V_6 [ 8 ] ;
int V_30 = 0 , V_31 ;
F_8 ( & V_2 -> V_8 , L_9
L_8 ,
V_9 ,
V_4 -> V_17 , V_4 -> V_18 , V_4 -> V_20 ,
V_4 -> V_22 , V_4 -> V_26 , V_4 -> V_28 , V_4 -> V_24 ) ;
V_6 [ V_30 ++ ] = V_13 ;
V_6 [ V_30 ++ ] = F_12 ( V_4 -> V_17 ) ;
V_6 [ V_30 ++ ] = F_12 ( V_4 -> V_18 ) ;
V_6 [ V_30 ++ ] = F_12 ( V_4 -> V_20 ) ;
V_6 [ V_30 ++ ] = F_12 ( V_4 -> V_22 ) ;
V_6 [ V_30 ++ ] = V_4 -> V_24 & 0x07 ;
V_6 [ V_30 ++ ] = F_12 ( V_4 -> V_26 + 1 ) ;
V_6 [ V_30 ++ ] = F_12 ( V_4 -> V_28 % 100 ) ;
V_31 = F_3 ( V_2 , V_6 , V_30 ) ;
if ( V_31 != V_30 ) {
F_5 ( & V_2 -> V_8 ,
L_10 , V_9 , V_31 ) ;
return - V_10 ;
}
V_5 -> V_15 = 0 ;
return 0 ;
}
static int F_13 ( struct V_32 * V_8 ,
unsigned int V_33 , unsigned long V_34 )
{
struct V_5 * V_5 = F_2 ( F_14 ( V_8 ) ) ;
switch ( V_33 ) {
case V_35 :
if ( V_5 -> V_12 )
F_6 ( V_8 , L_11 ) ;
if ( V_5 -> V_15 )
F_6 ( V_8 , L_3 ) ;
if ( F_15 ( ( void V_36 * ) V_34 , & V_5 -> V_12 ,
sizeof( int ) ) )
return - V_37 ;
return 0 ;
default:
return - V_38 ;
}
}
static int F_16 ( struct V_32 * V_8 , struct V_3 * V_4 )
{
return F_1 ( F_14 ( V_8 ) , V_4 ) ;
}
static int F_17 ( struct V_32 * V_8 , struct V_3 * V_4 )
{
return F_11 ( F_14 ( V_8 ) , V_4 ) ;
}
static int F_18 ( struct V_1 * V_2 ,
const struct V_39 * V_40 )
{
struct V_5 * V_5 ;
F_8 ( & V_2 -> V_8 , L_12 , V_9 ) ;
if ( ! F_19 ( V_2 -> V_41 , V_42 ) )
return - V_43 ;
V_5 = F_20 ( & V_2 -> V_8 , sizeof( struct V_5 ) ,
V_44 ) ;
if ( ! V_5 )
return - V_45 ;
F_6 ( & V_2 -> V_8 , L_13 V_46 L_14 ) ;
F_21 ( V_2 , V_5 ) ;
V_5 -> V_47 = F_22 ( & V_2 -> V_8 ,
V_48 . V_49 . V_50 ,
& V_51 , V_52 ) ;
return F_23 ( V_5 -> V_47 ) ;
}
