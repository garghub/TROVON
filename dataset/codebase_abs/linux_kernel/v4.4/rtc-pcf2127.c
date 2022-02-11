static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
unsigned char V_5 [ 10 ] = { V_6 } ;
if ( F_2 ( V_2 , V_5 , 1 ) != 1 ||
F_3 ( V_2 , V_5 , sizeof( V_5 ) ) != sizeof( V_5 ) ) {
F_4 ( & V_2 -> V_7 , L_1 , V_8 ) ;
return - V_9 ;
}
if ( V_5 [ V_10 ] & V_11 )
F_5 ( & V_2 -> V_7 ,
L_2 ) ;
if ( V_5 [ V_12 ] & V_13 ) {
F_6 ( & V_2 -> V_7 ,
L_3 ) ;
return - V_14 ;
}
F_7 ( & V_2 -> V_7 ,
L_4
L_5
L_6 ,
V_8 ,
V_5 [ 0 ] , V_5 [ 1 ] , V_5 [ 2 ] ,
V_5 [ 3 ] , V_5 [ 4 ] , V_5 [ 5 ] ,
V_5 [ 6 ] , V_5 [ 7 ] , V_5 [ 8 ] , V_5 [ 9 ] ) ;
V_4 -> V_15 = F_8 ( V_5 [ V_12 ] & 0x7F ) ;
V_4 -> V_16 = F_8 ( V_5 [ V_17 ] & 0x7F ) ;
V_4 -> V_18 = F_8 ( V_5 [ V_19 ] & 0x3F ) ;
V_4 -> V_20 = F_8 ( V_5 [ V_21 ] & 0x3F ) ;
V_4 -> V_22 = V_5 [ V_23 ] & 0x07 ;
V_4 -> V_24 = F_8 ( V_5 [ V_25 ] & 0x1F ) - 1 ;
V_4 -> V_26 = F_8 ( V_5 [ V_27 ] ) ;
if ( V_4 -> V_26 < 70 )
V_4 -> V_26 += 100 ;
F_7 ( & V_2 -> V_7 , L_7
L_8 ,
V_8 ,
V_4 -> V_15 , V_4 -> V_16 , V_4 -> V_18 ,
V_4 -> V_20 , V_4 -> V_24 , V_4 -> V_26 , V_4 -> V_22 ) ;
return F_9 ( V_4 ) ;
}
static int F_10 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
unsigned char V_5 [ 8 ] ;
int V_28 = 0 , V_29 ;
F_7 ( & V_2 -> V_7 , L_9
L_8 ,
V_8 ,
V_4 -> V_15 , V_4 -> V_16 , V_4 -> V_18 ,
V_4 -> V_20 , V_4 -> V_24 , V_4 -> V_26 , V_4 -> V_22 ) ;
V_5 [ V_28 ++ ] = V_12 ;
V_5 [ V_28 ++ ] = F_11 ( V_4 -> V_15 ) ;
V_5 [ V_28 ++ ] = F_11 ( V_4 -> V_16 ) ;
V_5 [ V_28 ++ ] = F_11 ( V_4 -> V_18 ) ;
V_5 [ V_28 ++ ] = F_11 ( V_4 -> V_20 ) ;
V_5 [ V_28 ++ ] = V_4 -> V_22 & 0x07 ;
V_5 [ V_28 ++ ] = F_11 ( V_4 -> V_24 + 1 ) ;
V_5 [ V_28 ++ ] = F_11 ( V_4 -> V_26 % 100 ) ;
V_29 = F_2 ( V_2 , V_5 , V_28 ) ;
if ( V_29 != V_28 ) {
F_4 ( & V_2 -> V_7 ,
L_10 , V_8 , V_29 ) ;
return - V_9 ;
}
return 0 ;
}
static int F_12 ( struct V_30 * V_7 ,
unsigned int V_31 , unsigned long V_32 )
{
struct V_1 * V_2 = F_13 ( V_7 ) ;
unsigned char V_5 = V_10 ;
int V_33 ;
int V_34 ;
switch ( V_31 ) {
case V_35 :
V_34 = F_2 ( V_2 , & V_5 , 1 ) ;
if ( ! V_34 )
V_34 = - V_9 ;
if ( V_34 < 0 )
return V_34 ;
V_34 = F_3 ( V_2 , & V_5 , 1 ) ;
if ( ! V_34 )
V_34 = - V_9 ;
if ( V_34 < 0 )
return V_34 ;
V_33 = V_5 & V_11 ? 1 : 0 ;
if ( F_14 ( ( void V_36 * ) V_32 , & V_33 , sizeof( int ) ) )
return - V_37 ;
return 0 ;
default:
return - V_38 ;
}
}
static int F_15 ( struct V_30 * V_7 , struct V_3 * V_4 )
{
return F_1 ( F_13 ( V_7 ) , V_4 ) ;
}
static int F_16 ( struct V_30 * V_7 , struct V_3 * V_4 )
{
return F_10 ( F_13 ( V_7 ) , V_4 ) ;
}
static int F_17 ( struct V_1 * V_2 ,
const struct V_39 * V_40 )
{
struct V_41 * V_41 ;
F_7 ( & V_2 -> V_7 , L_11 , V_8 ) ;
if ( ! F_18 ( V_2 -> V_42 , V_43 ) )
return - V_44 ;
V_41 = F_19 ( & V_2 -> V_7 , sizeof( struct V_41 ) ,
V_45 ) ;
if ( ! V_41 )
return - V_46 ;
F_20 ( V_2 , V_41 ) ;
V_41 -> V_47 = F_21 ( & V_2 -> V_7 ,
V_48 . V_49 . V_50 ,
& V_51 , V_52 ) ;
return F_22 ( V_41 -> V_47 ) ;
}
