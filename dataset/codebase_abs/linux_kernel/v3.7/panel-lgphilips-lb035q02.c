static int F_1 ( struct V_1 * V_2 )
{
int V_3 ;
if ( V_2 -> V_4 == V_5 )
return 0 ;
F_2 ( V_2 , & V_2 -> V_6 . V_7 ) ;
F_3 ( V_2 , V_2 -> V_8 . V_9 . V_10 ) ;
V_3 = F_4 ( V_2 ) ;
if ( V_3 )
goto V_11;
if ( V_2 -> V_12 ) {
V_3 = V_2 -> V_12 ( V_2 ) ;
if ( V_3 )
goto V_13;
}
return 0 ;
V_13:
F_5 ( V_2 ) ;
V_11:
return V_3 ;
}
static void F_6 ( struct V_1 * V_2 )
{
if ( V_2 -> V_4 != V_5 )
return;
if ( V_2 -> V_14 )
V_2 -> V_14 ( V_2 ) ;
F_5 ( V_2 ) ;
}
static int F_7 ( struct V_1 * V_2 )
{
struct V_15 * V_16 ;
int V_3 ;
V_2 -> V_6 . V_7 = V_17 ;
V_16 = F_8 ( sizeof( * V_16 ) , V_18 ) ;
if ( ! V_16 ) {
V_3 = - V_19 ;
goto V_20;
}
F_9 ( & V_16 -> V_21 ) ;
F_10 ( & V_2 -> V_22 , V_16 ) ;
return 0 ;
V_20:
return V_3 ;
}
static void F_11 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = F_12 ( & V_2 -> V_22 ) ;
F_13 ( V_16 ) ;
}
static int F_14 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = F_12 ( & V_2 -> V_22 ) ;
int V_3 ;
F_15 ( & V_16 -> V_21 ) ;
V_3 = F_1 ( V_2 ) ;
if ( V_3 )
goto V_20;
V_2 -> V_4 = V_5 ;
F_16 ( & V_16 -> V_21 ) ;
return 0 ;
V_20:
F_16 ( & V_16 -> V_21 ) ;
return V_3 ;
}
static void F_17 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = F_12 ( & V_2 -> V_22 ) ;
F_15 ( & V_16 -> V_21 ) ;
F_6 ( V_2 ) ;
V_2 -> V_4 = V_23 ;
F_16 ( & V_16 -> V_21 ) ;
}
static int F_18 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = F_12 ( & V_2 -> V_22 ) ;
F_15 ( & V_16 -> V_21 ) ;
F_6 ( V_2 ) ;
V_2 -> V_4 = V_24 ;
F_16 ( & V_16 -> V_21 ) ;
return 0 ;
}
static int F_19 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = F_12 ( & V_2 -> V_22 ) ;
int V_3 ;
F_15 ( & V_16 -> V_21 ) ;
V_3 = F_1 ( V_2 ) ;
if ( V_3 )
goto V_20;
V_2 -> V_4 = V_5 ;
F_16 ( & V_16 -> V_21 ) ;
return 0 ;
V_20:
F_16 ( & V_16 -> V_21 ) ;
return V_3 ;
}
static int F_20 ( struct V_25 * V_26 , T_1 V_27 , T_2 V_28 )
{
struct V_29 V_30 ;
struct V_31 V_32 = {
. V_33 = 3 ,
. V_34 = 1 ,
} ;
struct V_31 V_35 = {
. V_33 = 3 ,
} ;
T_1 V_36 [ 16 ] ;
F_21 ( & V_30 ) ;
V_36 [ 0 ] = 0x70 ;
V_36 [ 1 ] = 0x00 ;
V_36 [ 2 ] = V_27 & 0x7f ;
V_32 . V_37 = V_36 ;
F_22 ( & V_32 , & V_30 ) ;
V_36 [ 4 ] = 0x72 ;
V_36 [ 5 ] = V_28 >> 8 ;
V_36 [ 6 ] = V_28 ;
V_35 . V_37 = V_36 + 4 ;
F_22 ( & V_35 , & V_30 ) ;
return F_23 ( V_26 , & V_30 ) ;
}
static void F_24 ( struct V_25 * V_26 )
{
F_20 ( V_26 , 0x01 , 0x6300 ) ;
F_20 ( V_26 , 0x02 , 0x0200 ) ;
F_20 ( V_26 , 0x03 , 0x0177 ) ;
F_20 ( V_26 , 0x04 , 0x04c7 ) ;
F_20 ( V_26 , 0x05 , 0xffc0 ) ;
F_20 ( V_26 , 0x06 , 0xe806 ) ;
F_20 ( V_26 , 0x0a , 0x4008 ) ;
F_20 ( V_26 , 0x0b , 0x0000 ) ;
F_20 ( V_26 , 0x0d , 0x0030 ) ;
F_20 ( V_26 , 0x0e , 0x2800 ) ;
F_20 ( V_26 , 0x0f , 0x0000 ) ;
F_20 ( V_26 , 0x16 , 0x9f80 ) ;
F_20 ( V_26 , 0x17 , 0x0a0f ) ;
F_20 ( V_26 , 0x1e , 0x00c1 ) ;
F_20 ( V_26 , 0x30 , 0x0300 ) ;
F_20 ( V_26 , 0x31 , 0x0007 ) ;
F_20 ( V_26 , 0x32 , 0x0000 ) ;
F_20 ( V_26 , 0x33 , 0x0000 ) ;
F_20 ( V_26 , 0x34 , 0x0707 ) ;
F_20 ( V_26 , 0x35 , 0x0004 ) ;
F_20 ( V_26 , 0x36 , 0x0302 ) ;
F_20 ( V_26 , 0x37 , 0x0202 ) ;
F_20 ( V_26 , 0x3a , 0x0a0d ) ;
F_20 ( V_26 , 0x3b , 0x0806 ) ;
}
static int T_3 F_25 ( struct V_25 * V_26 )
{
F_24 ( V_26 ) ;
return F_26 ( & V_38 ) ;
}
static int T_4 F_27 ( struct V_25 * V_26 )
{
F_28 ( & V_38 ) ;
return 0 ;
}
