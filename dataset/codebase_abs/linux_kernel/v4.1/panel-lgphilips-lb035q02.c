static int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_2 V_4 )
{
struct V_5 V_6 ;
struct V_7 V_8 = {
. V_9 = 3 ,
. V_10 = 1 ,
} ;
struct V_7 V_11 = {
. V_9 = 3 ,
} ;
T_1 V_12 [ 16 ] ;
F_2 ( & V_6 ) ;
V_12 [ 0 ] = 0x70 ;
V_12 [ 1 ] = 0x00 ;
V_12 [ 2 ] = V_3 & 0x7f ;
V_8 . V_13 = V_12 ;
F_3 ( & V_8 , & V_6 ) ;
V_12 [ 4 ] = 0x72 ;
V_12 [ 5 ] = V_4 >> 8 ;
V_12 [ 6 ] = V_4 ;
V_11 . V_13 = V_12 + 4 ;
F_3 ( & V_11 , & V_6 ) ;
return F_4 ( V_2 , & V_6 ) ;
}
static void F_5 ( struct V_1 * V_2 )
{
F_1 ( V_2 , 0x01 , 0x6300 ) ;
F_1 ( V_2 , 0x02 , 0x0200 ) ;
F_1 ( V_2 , 0x03 , 0x0177 ) ;
F_1 ( V_2 , 0x04 , 0x04c7 ) ;
F_1 ( V_2 , 0x05 , 0xffc0 ) ;
F_1 ( V_2 , 0x06 , 0xe806 ) ;
F_1 ( V_2 , 0x0a , 0x4008 ) ;
F_1 ( V_2 , 0x0b , 0x0000 ) ;
F_1 ( V_2 , 0x0d , 0x0030 ) ;
F_1 ( V_2 , 0x0e , 0x2800 ) ;
F_1 ( V_2 , 0x0f , 0x0000 ) ;
F_1 ( V_2 , 0x16 , 0x9f80 ) ;
F_1 ( V_2 , 0x17 , 0x0a0f ) ;
F_1 ( V_2 , 0x1e , 0x00c1 ) ;
F_1 ( V_2 , 0x30 , 0x0300 ) ;
F_1 ( V_2 , 0x31 , 0x0007 ) ;
F_1 ( V_2 , 0x32 , 0x0000 ) ;
F_1 ( V_2 , 0x33 , 0x0000 ) ;
F_1 ( V_2 , 0x34 , 0x0707 ) ;
F_1 ( V_2 , 0x35 , 0x0004 ) ;
F_1 ( V_2 , 0x36 , 0x0302 ) ;
F_1 ( V_2 , 0x37 , 0x0202 ) ;
F_1 ( V_2 , 0x3a , 0x0a0d ) ;
F_1 ( V_2 , 0x3b , 0x0806 ) ;
}
static int F_6 ( struct V_14 * V_15 )
{
struct V_16 * V_17 = F_7 ( V_15 ) ;
struct V_14 * V_18 = V_17 -> V_18 ;
int V_19 ;
if ( F_8 ( V_15 ) )
return 0 ;
V_19 = V_18 -> V_20 . V_21 -> V_22 ( V_18 , V_15 ) ;
if ( V_19 )
return V_19 ;
F_5 ( V_17 -> V_2 ) ;
return 0 ;
}
static void F_9 ( struct V_14 * V_15 )
{
struct V_16 * V_17 = F_7 ( V_15 ) ;
struct V_14 * V_18 = V_17 -> V_18 ;
if ( ! F_8 ( V_15 ) )
return;
V_18 -> V_20 . V_21 -> V_23 ( V_18 , V_15 ) ;
}
static int F_10 ( struct V_14 * V_15 )
{
struct V_16 * V_17 = F_7 ( V_15 ) ;
struct V_14 * V_18 = V_17 -> V_18 ;
int V_19 ;
if ( ! F_8 ( V_15 ) )
return - V_24 ;
if ( F_11 ( V_15 ) )
return 0 ;
if ( V_17 -> V_25 )
V_18 -> V_20 . V_21 -> V_26 ( V_18 , V_17 -> V_25 ) ;
V_18 -> V_20 . V_21 -> V_27 ( V_18 , & V_17 -> V_28 ) ;
V_19 = V_18 -> V_20 . V_21 -> V_29 ( V_18 ) ;
if ( V_19 )
return V_19 ;
if ( V_17 -> V_30 )
F_12 ( V_17 -> V_30 , 1 ) ;
if ( F_13 ( V_17 -> V_31 ) )
F_14 ( V_17 -> V_31 , 1 ) ;
V_15 -> V_32 = V_33 ;
return 0 ;
}
static void F_15 ( struct V_14 * V_15 )
{
struct V_16 * V_17 = F_7 ( V_15 ) ;
struct V_14 * V_18 = V_17 -> V_18 ;
if ( ! F_11 ( V_15 ) )
return;
if ( V_17 -> V_30 )
F_12 ( V_17 -> V_30 , 0 ) ;
if ( F_13 ( V_17 -> V_31 ) )
F_14 ( V_17 -> V_31 , 0 ) ;
V_18 -> V_20 . V_21 -> V_34 ( V_18 ) ;
V_15 -> V_32 = V_35 ;
}
static void F_16 ( struct V_14 * V_15 ,
struct V_36 * V_37 )
{
struct V_16 * V_17 = F_7 ( V_15 ) ;
struct V_14 * V_18 = V_17 -> V_18 ;
V_17 -> V_28 = * V_37 ;
V_15 -> V_38 . V_37 = * V_37 ;
V_18 -> V_20 . V_21 -> V_27 ( V_18 , V_37 ) ;
}
static void F_17 ( struct V_14 * V_15 ,
struct V_36 * V_37 )
{
struct V_16 * V_17 = F_7 ( V_15 ) ;
* V_37 = V_17 -> V_28 ;
}
static int F_18 ( struct V_14 * V_15 ,
struct V_36 * V_37 )
{
struct V_16 * V_17 = F_7 ( V_15 ) ;
struct V_14 * V_18 = V_17 -> V_18 ;
return V_18 -> V_20 . V_21 -> V_39 ( V_18 , V_37 ) ;
}
static int F_19 ( struct V_1 * V_2 )
{
const struct V_40 * V_41 ;
struct V_16 * V_17 = F_20 ( & V_2 -> V_42 ) ;
struct V_14 * V_15 , * V_18 ;
int V_19 ;
V_41 = F_21 ( & V_2 -> V_42 ) ;
V_18 = F_22 ( V_41 -> V_43 ) ;
if ( V_18 == NULL ) {
F_23 ( & V_2 -> V_42 , L_1 ,
V_41 -> V_43 ) ;
return - V_44 ;
}
V_17 -> V_18 = V_18 ;
V_17 -> V_25 = V_41 -> V_25 ;
V_15 = & V_17 -> V_15 ;
V_15 -> V_45 = V_41 -> V_45 ;
V_19 = F_24 ( & V_2 -> V_42 , V_41 -> V_30 ,
V_46 , L_2 ) ;
if ( V_19 )
goto V_47;
V_17 -> V_30 = F_25 ( V_41 -> V_30 ) ;
V_17 -> V_31 = V_41 -> V_31 ;
return 0 ;
V_47:
F_26 ( V_17 -> V_18 ) ;
return V_19 ;
}
static int F_27 ( struct V_1 * V_2 )
{
struct V_48 * V_49 = V_2 -> V_42 . V_50 ;
struct V_16 * V_17 = F_20 ( & V_2 -> V_42 ) ;
struct V_14 * V_18 ;
struct V_51 * V_52 ;
V_52 = F_28 ( & V_2 -> V_42 , L_3 ) ;
if ( F_29 ( V_52 ) ) {
F_23 ( & V_2 -> V_42 , L_4 ) ;
return F_30 ( V_52 ) ;
} else {
F_31 ( V_52 , 0 ) ;
V_17 -> V_30 = V_52 ;
}
V_17 -> V_31 = - V_53 ;
V_18 = F_32 ( V_49 ) ;
if ( F_29 ( V_18 ) ) {
F_23 ( & V_2 -> V_42 , L_5 ) ;
return F_30 ( V_18 ) ;
}
V_17 -> V_18 = V_18 ;
return 0 ;
}
static int F_33 ( struct V_1 * V_2 )
{
struct V_16 * V_17 ;
struct V_14 * V_15 ;
int V_19 ;
V_17 = F_34 ( & V_2 -> V_42 , sizeof( * V_17 ) , V_54 ) ;
if ( V_17 == NULL )
return - V_55 ;
F_35 ( & V_2 -> V_42 , V_17 ) ;
V_17 -> V_2 = V_2 ;
if ( F_21 ( & V_2 -> V_42 ) ) {
V_19 = F_19 ( V_2 ) ;
if ( V_19 )
return V_19 ;
} else if ( V_2 -> V_42 . V_50 ) {
V_19 = F_27 ( V_2 ) ;
if ( V_19 )
return V_19 ;
} else {
return - V_24 ;
}
if ( F_13 ( V_17 -> V_31 ) ) {
V_19 = F_24 ( & V_2 -> V_42 , V_17 -> V_31 ,
V_46 , L_6 ) ;
if ( V_19 )
goto V_47;
}
V_17 -> V_28 = V_56 ;
V_15 = & V_17 -> V_15 ;
V_15 -> V_42 = & V_2 -> V_42 ;
V_15 -> V_57 = & V_58 ;
V_15 -> type = V_59 ;
V_15 -> V_60 = V_61 ;
V_15 -> V_38 . V_37 = V_17 -> V_28 ;
V_15 -> V_62 . V_21 . V_25 = V_17 -> V_25 ;
V_19 = F_36 ( V_15 ) ;
if ( V_19 ) {
F_23 ( & V_2 -> V_42 , L_7 ) ;
goto V_63;
}
return 0 ;
V_63:
V_47:
F_26 ( V_17 -> V_18 ) ;
return V_19 ;
}
static int F_37 ( struct V_1 * V_2 )
{
struct V_16 * V_17 = F_20 ( & V_2 -> V_42 ) ;
struct V_14 * V_15 = & V_17 -> V_15 ;
struct V_14 * V_18 = V_17 -> V_18 ;
F_38 ( V_15 ) ;
F_15 ( V_15 ) ;
F_9 ( V_15 ) ;
F_26 ( V_18 ) ;
return 0 ;
}
