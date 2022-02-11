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
F_7 ( & V_2 -> V_8 ,
L_3
L_4
L_5 ,
V_9 ,
V_6 [ 0 ] , V_6 [ 1 ] , V_6 [ 2 ] ,
V_6 [ 3 ] , V_6 [ 4 ] , V_6 [ 5 ] ,
V_6 [ 6 ] , V_6 [ 7 ] , V_6 [ 8 ] , V_6 [ 9 ] ) ;
V_4 -> V_13 = F_8 ( V_6 [ V_14 ] & 0x7F ) ;
V_4 -> V_15 = F_8 ( V_6 [ V_16 ] & 0x7F ) ;
V_4 -> V_17 = F_8 ( V_6 [ V_18 ] & 0x3F ) ;
V_4 -> V_19 = F_8 ( V_6 [ V_20 ] & 0x3F ) ;
V_4 -> V_21 = V_6 [ V_22 ] & 0x07 ;
V_4 -> V_23 = F_8 ( V_6 [ V_24 ] & 0x1F ) - 1 ;
V_4 -> V_25 = F_8 ( V_6 [ V_26 ] ) ;
if ( V_4 -> V_25 < 70 )
V_4 -> V_25 += 100 ;
F_7 ( & V_2 -> V_8 , L_6
L_7 ,
V_9 ,
V_4 -> V_13 , V_4 -> V_15 , V_4 -> V_17 ,
V_4 -> V_19 , V_4 -> V_23 , V_4 -> V_25 , V_4 -> V_21 ) ;
if ( F_9 ( V_4 ) < 0 )
F_5 ( & V_2 -> V_8 , L_8 ) ;
return 0 ;
}
static int F_10 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
unsigned char V_6 [ 8 ] ;
int V_27 = 0 , V_28 ;
F_7 ( & V_2 -> V_8 , L_9
L_7 ,
V_9 ,
V_4 -> V_13 , V_4 -> V_15 , V_4 -> V_17 ,
V_4 -> V_19 , V_4 -> V_23 , V_4 -> V_25 , V_4 -> V_21 ) ;
V_6 [ V_27 ++ ] = V_14 ;
V_6 [ V_27 ++ ] = F_11 ( V_4 -> V_13 ) ;
V_6 [ V_27 ++ ] = F_11 ( V_4 -> V_15 ) ;
V_6 [ V_27 ++ ] = F_11 ( V_4 -> V_17 ) ;
V_6 [ V_27 ++ ] = F_11 ( V_4 -> V_19 ) ;
V_6 [ V_27 ++ ] = V_4 -> V_21 & 0x07 ;
V_6 [ V_27 ++ ] = F_11 ( V_4 -> V_23 + 1 ) ;
V_6 [ V_27 ++ ] = F_11 ( V_4 -> V_25 % 100 ) ;
V_28 = F_3 ( V_2 , V_6 , V_27 ) ;
if ( V_28 != V_27 ) {
F_5 ( & V_2 -> V_8 ,
L_10 , V_9 , V_28 ) ;
return - V_10 ;
}
return 0 ;
}
static int F_12 ( struct V_29 * V_8 ,
unsigned int V_30 , unsigned long V_31 )
{
struct V_5 * V_5 = F_2 ( F_13 ( V_8 ) ) ;
switch ( V_30 ) {
case V_32 :
if ( V_5 -> V_12 )
F_6 ( V_8 , L_2 ) ;
if ( F_14 ( ( void V_33 * ) V_31 , & V_5 -> V_12 ,
sizeof( int ) ) )
return - V_34 ;
return 0 ;
default:
return - V_35 ;
}
}
static int F_15 ( struct V_29 * V_8 , struct V_3 * V_4 )
{
return F_1 ( F_13 ( V_8 ) , V_4 ) ;
}
static int F_16 ( struct V_29 * V_8 , struct V_3 * V_4 )
{
return F_10 ( F_13 ( V_8 ) , V_4 ) ;
}
static int F_17 ( struct V_1 * V_2 ,
const struct V_36 * V_37 )
{
struct V_5 * V_5 ;
F_7 ( & V_2 -> V_8 , L_11 , V_9 ) ;
if ( ! F_18 ( V_2 -> V_38 , V_39 ) )
return - V_40 ;
V_5 = F_19 ( & V_2 -> V_8 , sizeof( struct V_5 ) ,
V_41 ) ;
if ( ! V_5 )
return - V_42 ;
F_6 ( & V_2 -> V_8 , L_12 V_43 L_13 ) ;
F_20 ( V_2 , V_5 ) ;
V_5 -> V_44 = F_21 ( & V_2 -> V_8 ,
V_45 . V_46 . V_47 ,
& V_48 , V_49 ) ;
if ( F_22 ( V_5 -> V_44 ) )
return F_23 ( V_5 -> V_44 ) ;
return 0 ;
}
static int F_24 ( struct V_1 * V_2 )
{
return 0 ;
}
