static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static int F_3 ( struct V_1 * V_4 , unsigned V_5 , unsigned V_6 )
{
unsigned V_7 ;
int V_8 ;
switch ( V_5 ) {
case V_9 :
V_7 = 1 ;
V_6 /= 10 ;
break;
case V_10 :
V_7 = 0 ;
break;
default:
V_7 = 2 ;
break;
}
V_4 -> V_11 [ 0 ] = 0x04 + V_7 ;
V_4 -> V_11 [ 1 ] = V_6 >> 8 ;
V_4 -> V_11 [ 2 ] = V_6 & 0xff ;
V_8 = F_4 ( V_4 -> V_12 , F_5 ( V_4 -> V_12 , 0 ) ,
V_13 ,
V_14 | V_15 | V_16 ,
0x0300 + V_4 -> V_11 [ 0 ] , 2 ,
V_4 -> V_11 , 3 , V_17 ) ;
if ( V_8 < 0 ) {
F_6 ( V_4 -> V_3 . V_18 , L_1 , V_19 , V_8 ) ;
return V_8 ;
}
V_4 -> V_20 = ( V_5 == V_9 ) ? V_6 * 10 : V_6 ;
return 0 ;
}
static void F_7 ( struct V_21 * V_22 )
{
struct V_1 * V_4 = F_1 ( F_8 ( V_22 ) ) ;
F_9 ( & V_22 -> V_18 , L_2 ) ;
F_10 ( & V_4 -> V_23 ) ;
F_11 ( V_22 , NULL ) ;
F_12 ( & V_4 -> V_24 ) ;
F_13 ( & V_4 -> V_3 ) ;
F_14 ( & V_4 -> V_23 ) ;
F_15 ( & V_4 -> V_3 ) ;
}
static int F_16 ( struct V_25 * V_25 , void * V_26 ,
struct V_27 * V_28 )
{
struct V_1 * V_4 = F_17 ( V_25 ) ;
F_18 ( V_28 -> V_29 , L_3 , sizeof( V_28 -> V_29 ) ) ;
F_18 ( V_28 -> V_30 , L_4 , sizeof( V_28 -> V_30 ) ) ;
F_19 ( V_4 -> V_12 , V_28 -> V_31 , sizeof( V_28 -> V_31 ) ) ;
V_28 -> V_32 = V_33 | V_34 ;
V_28 -> V_35 = V_28 -> V_32 | V_36 ;
return 0 ;
}
static int F_20 ( struct V_25 * V_25 , void * V_26 ,
struct V_37 * V_5 )
{
if ( V_5 -> V_38 != 0 )
return - V_39 ;
if ( V_5 -> V_40 >= F_21 ( V_41 ) )
return - V_39 ;
* V_5 = V_41 [ V_5 -> V_40 ] ;
return 0 ;
}
static int F_22 ( struct V_25 * V_25 , void * V_26 ,
struct V_42 * V_28 )
{
struct V_1 * V_4 = F_17 ( V_25 ) ;
int V_8 ;
if ( V_28 -> V_40 > 0 )
return - V_39 ;
F_18 ( V_28 -> V_43 , L_5 , sizeof( V_28 -> V_43 ) ) ;
V_28 -> V_44 = V_45 | V_46 |
V_47 ;
V_28 -> V_48 = V_49 * 16 ;
V_28 -> V_50 = V_51 * 16 ;
V_28 -> V_52 = V_53 | V_54 ;
V_28 -> V_55 = ( V_4 -> V_20 < V_56 ) ?
V_57 : V_58 ;
memset ( V_4 -> V_11 , 1 , V_59 ) ;
V_8 = F_4 ( V_4 -> V_12 , F_23 ( V_4 -> V_12 , 0 ) ,
1 , 0xa1 , 0x030d , 2 , V_4 -> V_11 , V_59 , V_17 ) ;
if ( V_8 < 0 ) {
F_6 ( V_4 -> V_3 . V_18 , L_1 , V_19 , V_8 ) ;
return V_8 ;
}
V_28 -> signal = ( ( V_4 -> V_11 [ 1 ] & 0xf ) << 8 | V_4 -> V_11 [ 2 ] ) << 4 ;
return 0 ;
}
static int F_24 ( struct V_25 * V_25 , void * V_26 ,
const struct V_42 * V_28 )
{
return V_28 -> V_40 ? - V_39 : 0 ;
}
static int F_25 ( struct V_25 * V_25 , void * V_26 ,
const struct V_60 * V_61 )
{
struct V_1 * V_4 = F_17 ( V_25 ) ;
T_1 V_6 = V_61 -> V_62 ;
unsigned V_5 ;
if ( V_61 -> V_38 != 0 || V_61 -> type != V_63 )
return - V_39 ;
if ( V_61 -> V_62 >= ( V_56 + V_64 ) * 8 )
V_5 = V_9 ;
else if ( V_61 -> V_62 <= ( V_65 + V_66 ) * 8 )
V_5 = V_10 ;
else
V_5 = V_67 ;
V_6 = F_26 ( T_1 , V_61 -> V_62 , V_41 [ V_5 ] . V_48 , V_41 [ V_5 ] . V_50 ) ;
return F_3 ( V_4 , V_5 , V_6 / 16 ) ;
}
static int F_27 ( struct V_25 * V_25 , void * V_26 ,
struct V_60 * V_61 )
{
struct V_1 * V_4 = F_17 ( V_25 ) ;
if ( V_61 -> V_38 != 0 )
return - V_39 ;
V_61 -> type = V_63 ;
V_61 -> V_62 = V_4 -> V_20 * 16 ;
return 0 ;
}
static int F_28 ( struct V_21 * V_22 ,
const struct V_68 * V_69 )
{
struct V_1 * V_4 ;
int V_70 = 0 ;
V_4 = F_29 ( & V_22 -> V_18 , sizeof( struct V_1 ) , V_71 ) ;
if ( V_4 )
V_4 -> V_11 = F_30 ( & V_22 -> V_18 , V_59 , V_71 ) ;
if ( ! V_4 || ! V_4 -> V_11 )
return - V_72 ;
V_4 -> V_12 = F_31 ( V_22 ) ;
V_4 -> V_22 = V_22 ;
F_32 ( 20 ) ;
V_70 = F_4 ( V_4 -> V_12 ,
F_23 ( V_4 -> V_12 , 0 ) ,
V_73 ,
V_14 | V_15 | V_74 ,
1 , 2 ,
V_4 -> V_11 , 3 , 500 ) ;
if ( V_70 != 3 ||
( F_33 ( & V_4 -> V_11 [ 1 ] ) & 0xfff ) == 0x0242 ) {
F_9 ( & V_22 -> V_18 , L_6 ) ;
return - V_75 ;
}
F_9 ( & V_22 -> V_18 , L_7 ,
V_69 -> V_76 , V_69 -> V_77 ) ;
V_70 = F_34 ( & V_22 -> V_18 , & V_4 -> V_3 ) ;
if ( V_70 < 0 ) {
F_35 ( & V_22 -> V_18 , L_8 ) ;
return V_70 ;
}
F_36 ( & V_4 -> V_23 ) ;
F_18 ( V_4 -> V_24 . V_43 , V_4 -> V_3 . V_43 ,
sizeof( V_4 -> V_24 . V_43 ) ) ;
V_4 -> V_24 . V_3 = & V_4 -> V_3 ;
V_4 -> V_24 . V_78 = & V_79 ;
V_4 -> V_24 . V_80 = & V_81 ;
V_4 -> V_24 . V_23 = & V_4 -> V_23 ;
V_4 -> V_24 . V_82 = V_83 ;
F_11 ( V_22 , & V_4 -> V_3 ) ;
F_37 ( & V_4 -> V_24 , V_4 ) ;
F_38 ( V_84 , & V_4 -> V_24 . V_85 ) ;
F_3 ( V_4 , V_9 , 95160 ) ;
V_70 = F_39 ( & V_4 -> V_24 , V_86 , - 1 ) ;
if ( V_70 == 0 ) {
F_9 ( & V_22 -> V_18 , L_9 ,
F_40 ( & V_4 -> V_24 ) ) ;
return 0 ;
}
F_35 ( & V_22 -> V_18 , L_10 ) ;
F_41 ( & V_4 -> V_3 ) ;
return V_70 ;
}
