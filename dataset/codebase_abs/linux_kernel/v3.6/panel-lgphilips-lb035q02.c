static int F_1 ( struct V_1 * V_2 )
{
int V_3 ;
if ( V_2 -> V_4 == V_5 )
return 0 ;
V_3 = F_2 ( V_2 ) ;
if ( V_3 )
goto V_6;
if ( V_2 -> V_7 ) {
V_3 = V_2 -> V_7 ( V_2 ) ;
if ( V_3 )
goto V_8;
}
return 0 ;
V_8:
F_3 ( V_2 ) ;
V_6:
return V_3 ;
}
static void F_4 ( struct V_1 * V_2 )
{
if ( V_2 -> V_4 != V_5 )
return;
if ( V_2 -> V_9 )
V_2 -> V_9 ( V_2 ) ;
F_3 ( V_2 ) ;
}
static int F_5 ( struct V_1 * V_2 )
{
struct V_10 * V_11 ;
int V_3 ;
V_2 -> V_12 . V_13 = V_14 ;
V_11 = F_6 ( sizeof( * V_11 ) , V_15 ) ;
if ( ! V_11 ) {
V_3 = - V_16 ;
goto V_17;
}
F_7 ( & V_11 -> V_18 ) ;
F_8 ( & V_2 -> V_19 , V_11 ) ;
return 0 ;
V_17:
return V_3 ;
}
static void F_9 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = F_10 ( & V_2 -> V_19 ) ;
F_11 ( V_11 ) ;
}
static int F_12 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = F_10 ( & V_2 -> V_19 ) ;
int V_3 ;
F_13 ( & V_11 -> V_18 ) ;
V_3 = F_1 ( V_2 ) ;
if ( V_3 )
goto V_17;
V_2 -> V_4 = V_5 ;
F_14 ( & V_11 -> V_18 ) ;
return 0 ;
V_17:
F_14 ( & V_11 -> V_18 ) ;
return V_3 ;
}
static void F_15 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = F_10 ( & V_2 -> V_19 ) ;
F_13 ( & V_11 -> V_18 ) ;
F_4 ( V_2 ) ;
V_2 -> V_4 = V_20 ;
F_14 ( & V_11 -> V_18 ) ;
}
static int F_16 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = F_10 ( & V_2 -> V_19 ) ;
F_13 ( & V_11 -> V_18 ) ;
F_4 ( V_2 ) ;
V_2 -> V_4 = V_21 ;
F_14 ( & V_11 -> V_18 ) ;
return 0 ;
}
static int F_17 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = F_10 ( & V_2 -> V_19 ) ;
int V_3 ;
F_13 ( & V_11 -> V_18 ) ;
V_3 = F_1 ( V_2 ) ;
if ( V_3 )
goto V_17;
V_2 -> V_4 = V_5 ;
F_14 ( & V_11 -> V_18 ) ;
return 0 ;
V_17:
F_14 ( & V_11 -> V_18 ) ;
return V_3 ;
}
static int F_18 ( struct V_22 * V_23 , T_1 V_24 , T_2 V_25 )
{
struct V_26 V_27 ;
struct V_28 V_29 = {
. V_30 = 3 ,
. V_31 = 1 ,
} ;
struct V_28 V_32 = {
. V_30 = 3 ,
} ;
T_1 V_33 [ 16 ] ;
F_19 ( & V_27 ) ;
V_33 [ 0 ] = 0x70 ;
V_33 [ 1 ] = 0x00 ;
V_33 [ 2 ] = V_24 & 0x7f ;
V_29 . V_34 = V_33 ;
F_20 ( & V_29 , & V_27 ) ;
V_33 [ 4 ] = 0x72 ;
V_33 [ 5 ] = V_25 >> 8 ;
V_33 [ 6 ] = V_25 ;
V_32 . V_34 = V_33 + 4 ;
F_20 ( & V_32 , & V_27 ) ;
return F_21 ( V_23 , & V_27 ) ;
}
static void F_22 ( struct V_22 * V_23 )
{
F_18 ( V_23 , 0x01 , 0x6300 ) ;
F_18 ( V_23 , 0x02 , 0x0200 ) ;
F_18 ( V_23 , 0x03 , 0x0177 ) ;
F_18 ( V_23 , 0x04 , 0x04c7 ) ;
F_18 ( V_23 , 0x05 , 0xffc0 ) ;
F_18 ( V_23 , 0x06 , 0xe806 ) ;
F_18 ( V_23 , 0x0a , 0x4008 ) ;
F_18 ( V_23 , 0x0b , 0x0000 ) ;
F_18 ( V_23 , 0x0d , 0x0030 ) ;
F_18 ( V_23 , 0x0e , 0x2800 ) ;
F_18 ( V_23 , 0x0f , 0x0000 ) ;
F_18 ( V_23 , 0x16 , 0x9f80 ) ;
F_18 ( V_23 , 0x17 , 0x0a0f ) ;
F_18 ( V_23 , 0x1e , 0x00c1 ) ;
F_18 ( V_23 , 0x30 , 0x0300 ) ;
F_18 ( V_23 , 0x31 , 0x0007 ) ;
F_18 ( V_23 , 0x32 , 0x0000 ) ;
F_18 ( V_23 , 0x33 , 0x0000 ) ;
F_18 ( V_23 , 0x34 , 0x0707 ) ;
F_18 ( V_23 , 0x35 , 0x0004 ) ;
F_18 ( V_23 , 0x36 , 0x0302 ) ;
F_18 ( V_23 , 0x37 , 0x0202 ) ;
F_18 ( V_23 , 0x3a , 0x0a0d ) ;
F_18 ( V_23 , 0x3b , 0x0806 ) ;
}
static int T_3 F_23 ( struct V_22 * V_23 )
{
F_22 ( V_23 ) ;
return F_24 ( & V_35 ) ;
}
static int T_4 F_25 ( struct V_22 * V_23 )
{
F_26 ( & V_35 ) ;
return 0 ;
}
