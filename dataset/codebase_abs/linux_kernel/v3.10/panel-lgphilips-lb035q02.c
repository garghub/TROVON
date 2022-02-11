static inline struct V_1
* F_1 ( const struct V_2 * V_3 )
{
return (struct V_1 * ) V_3 -> V_4 ;
}
static int F_2 ( struct V_2 * V_3 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
int V_6 , V_7 ;
if ( V_3 -> V_8 == V_9 )
return 0 ;
F_3 ( V_3 , & V_3 -> V_10 . V_11 ) ;
F_4 ( V_3 , V_3 -> V_12 . V_13 . V_14 ) ;
V_6 = F_5 ( V_3 ) ;
if ( V_6 )
goto V_15;
for ( V_7 = 0 ; V_7 < V_5 -> V_16 ; ++ V_7 ) {
F_6 ( V_5 -> V_17 [ V_7 ] ,
V_5 -> V_18 [ V_7 ] ? 0 : 1 ) ;
}
return 0 ;
V_15:
return V_6 ;
}
static void F_7 ( struct V_2 * V_3 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
int V_7 ;
if ( V_3 -> V_8 != V_9 )
return;
for ( V_7 = V_5 -> V_16 - 1 ; V_7 >= 0 ; -- V_7 ) {
F_6 ( V_5 -> V_17 [ V_7 ] ,
V_5 -> V_18 [ V_7 ] ? 1 : 0 ) ;
}
F_8 ( V_3 ) ;
}
static int F_9 ( struct V_2 * V_3 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
struct V_19 * V_20 ;
int V_6 , V_7 ;
if ( ! V_5 )
return - V_21 ;
V_3 -> V_10 . V_11 = V_22 ;
V_20 = F_10 ( & V_3 -> V_23 , sizeof( * V_20 ) , V_24 ) ;
if ( ! V_20 )
return - V_25 ;
for ( V_7 = 0 ; V_7 < V_5 -> V_16 ; ++ V_7 ) {
V_6 = F_11 ( & V_3 -> V_23 , V_5 -> V_17 [ V_7 ] ,
V_5 -> V_18 [ V_7 ] ?
V_26 : V_27 ,
L_1 ) ;
if ( V_6 )
return V_6 ;
}
F_12 ( & V_20 -> V_28 ) ;
F_13 ( & V_3 -> V_23 , V_20 ) ;
return 0 ;
}
static void F_14 ( struct V_2 * V_3 )
{
}
static int F_15 ( struct V_2 * V_3 )
{
struct V_19 * V_20 = F_16 ( & V_3 -> V_23 ) ;
int V_6 ;
F_17 ( & V_20 -> V_28 ) ;
V_6 = F_2 ( V_3 ) ;
if ( V_6 )
goto V_29;
V_3 -> V_8 = V_9 ;
F_18 ( & V_20 -> V_28 ) ;
return 0 ;
V_29:
F_18 ( & V_20 -> V_28 ) ;
return V_6 ;
}
static void F_19 ( struct V_2 * V_3 )
{
struct V_19 * V_20 = F_16 ( & V_3 -> V_23 ) ;
F_17 ( & V_20 -> V_28 ) ;
F_7 ( V_3 ) ;
V_3 -> V_8 = V_30 ;
F_18 ( & V_20 -> V_28 ) ;
}
static int F_20 ( struct V_31 * V_32 , T_1 V_33 , T_2 V_34 )
{
struct V_35 V_36 ;
struct V_37 V_38 = {
. V_39 = 3 ,
. V_40 = 1 ,
} ;
struct V_37 V_41 = {
. V_39 = 3 ,
} ;
T_1 V_42 [ 16 ] ;
F_21 ( & V_36 ) ;
V_42 [ 0 ] = 0x70 ;
V_42 [ 1 ] = 0x00 ;
V_42 [ 2 ] = V_33 & 0x7f ;
V_38 . V_43 = V_42 ;
F_22 ( & V_38 , & V_36 ) ;
V_42 [ 4 ] = 0x72 ;
V_42 [ 5 ] = V_34 >> 8 ;
V_42 [ 6 ] = V_34 ;
V_41 . V_43 = V_42 + 4 ;
F_22 ( & V_41 , & V_36 ) ;
return F_23 ( V_32 , & V_36 ) ;
}
static void F_24 ( struct V_31 * V_32 )
{
F_20 ( V_32 , 0x01 , 0x6300 ) ;
F_20 ( V_32 , 0x02 , 0x0200 ) ;
F_20 ( V_32 , 0x03 , 0x0177 ) ;
F_20 ( V_32 , 0x04 , 0x04c7 ) ;
F_20 ( V_32 , 0x05 , 0xffc0 ) ;
F_20 ( V_32 , 0x06 , 0xe806 ) ;
F_20 ( V_32 , 0x0a , 0x4008 ) ;
F_20 ( V_32 , 0x0b , 0x0000 ) ;
F_20 ( V_32 , 0x0d , 0x0030 ) ;
F_20 ( V_32 , 0x0e , 0x2800 ) ;
F_20 ( V_32 , 0x0f , 0x0000 ) ;
F_20 ( V_32 , 0x16 , 0x9f80 ) ;
F_20 ( V_32 , 0x17 , 0x0a0f ) ;
F_20 ( V_32 , 0x1e , 0x00c1 ) ;
F_20 ( V_32 , 0x30 , 0x0300 ) ;
F_20 ( V_32 , 0x31 , 0x0007 ) ;
F_20 ( V_32 , 0x32 , 0x0000 ) ;
F_20 ( V_32 , 0x33 , 0x0000 ) ;
F_20 ( V_32 , 0x34 , 0x0707 ) ;
F_20 ( V_32 , 0x35 , 0x0004 ) ;
F_20 ( V_32 , 0x36 , 0x0302 ) ;
F_20 ( V_32 , 0x37 , 0x0202 ) ;
F_20 ( V_32 , 0x3a , 0x0a0d ) ;
F_20 ( V_32 , 0x3b , 0x0806 ) ;
}
static int F_25 ( struct V_31 * V_32 )
{
F_24 ( V_32 ) ;
return F_26 ( & V_44 ) ;
}
static int F_27 ( struct V_31 * V_32 )
{
F_28 ( & V_44 ) ;
return 0 ;
}
