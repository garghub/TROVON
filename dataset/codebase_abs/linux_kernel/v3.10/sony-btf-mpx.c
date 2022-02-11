static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static int F_3 ( struct V_4 * V_5 , int V_6 , int V_7 , int V_8 )
{
T_1 V_9 [ 5 ] ;
struct V_10 V_11 ;
V_9 [ 0 ] = V_6 ;
V_9 [ 1 ] = V_7 >> 8 ;
V_9 [ 2 ] = V_7 & 0xff ;
V_9 [ 3 ] = V_8 >> 8 ;
V_9 [ 4 ] = V_8 & 0xff ;
V_11 . V_7 = V_5 -> V_7 ;
V_11 . V_12 = 0 ;
V_11 . V_13 = 5 ;
V_11 . V_14 = V_9 ;
F_4 ( V_5 -> V_15 , & V_11 , 1 ) ;
return 0 ;
}
static int F_5 ( struct V_1 * V_16 )
{
struct V_4 * V_5 = F_6 ( & V_16 -> V_3 ) ;
T_2 V_17 = 0 ;
T_1 V_9 [ 3 ] ;
struct V_10 V_11 ;
int V_18 = V_16 -> V_19 ;
V_9 [ 0 ] = 0x00 ;
V_9 [ 1 ] = 0x80 ;
V_9 [ 2 ] = 0x00 ;
V_11 . V_7 = V_5 -> V_7 ;
V_11 . V_12 = 0 ;
V_11 . V_13 = 3 ;
V_11 . V_14 = V_9 ;
F_4 ( V_5 -> V_15 , & V_11 , 1 ) ;
V_9 [ 1 ] = 0x00 ;
F_4 ( V_5 -> V_15 , & V_11 , 1 ) ;
if ( V_16 -> V_20 != V_21 )
V_18 ++ ;
if ( V_22 [ V_18 ] . V_23 != V_24 ) {
switch ( V_16 -> V_20 ) {
case V_21 :
switch ( V_22 [ V_18 ] . V_23 ) {
case V_25 :
V_17 = V_22 [ V_18 ] . V_17 ;
break;
case V_26 :
V_17 = 0x0000 ;
break;
case V_27 :
V_17 = 0x0200 ;
break;
default:
break;
}
break;
case V_28 :
V_17 = V_22 [ V_18 ] . V_17 ;
break;
case V_29 :
V_17 = 0x0300 ;
break;
case V_30 :
V_17 = 0x0400 ;
break;
}
V_17 |= V_22 [ V_18 ] . V_17 & 0x00ff ;
} else
V_17 = V_22 [ V_18 ] . V_17 ;
F_3 ( V_5 , 0x10 , 0x0030 , V_22 [ V_18 ] . V_31 ) ;
F_3 ( V_5 , 0x12 , 0x0008 , V_17 ) ;
F_3 ( V_5 , 0x12 , 0x0013 , V_22 [ V_18 ] . V_32 ) ;
F_3 ( V_5 , 0x12 , 0x000e ,
V_22 [ V_18 ] . V_33 ) ;
F_3 ( V_5 , 0x12 , 0x0010 ,
V_22 [ V_18 ] . V_34 ) ;
F_3 ( V_5 , 0x12 , 0x000d ,
V_22 [ V_18 ] . V_35 ) ;
F_3 ( V_5 , 0x10 , 0x0020 , V_22 [ V_18 ] . system ) ;
F_3 ( V_5 , 0x12 , 0x0000 , V_22 [ V_18 ] . V_36 ) ;
if ( V_22 [ V_18 ] . V_23 == V_25 )
F_3 ( V_5 , 0x10 , 0x0022 ,
V_16 -> V_20 == V_21 ? 0x07f0 : 0x0190 ) ;
#ifdef F_7
{
T_1 V_37 [ 3 ] , V_38 [ 2 ] ;
struct V_10 V_39 [ 2 ] ;
F_8 ( V_5 ,
L_1 ,
V_22 [ V_18 ] . V_31 ,
V_17 ,
V_22 [ V_18 ] . V_32 ,
V_22 [ V_18 ] . V_33 ,
V_22 [ V_18 ] . V_34 ,
V_22 [ V_18 ] . V_35 ,
V_22 [ V_18 ] . system ,
V_22 [ V_18 ] . V_36 ) ;
V_37 [ 0 ] = 0x11 ;
V_37 [ 1 ] = 0x00 ;
V_37 [ 2 ] = 0x7e ;
V_39 [ 0 ] . V_7 = V_5 -> V_7 ;
V_39 [ 0 ] . V_12 = 0 ;
V_39 [ 0 ] . V_13 = 3 ;
V_39 [ 0 ] . V_14 = V_37 ;
V_39 [ 1 ] . V_7 = V_5 -> V_7 ;
V_39 [ 1 ] . V_12 = V_40 ;
V_39 [ 1 ] . V_13 = 2 ;
V_39 [ 1 ] . V_14 = V_38 ;
F_4 ( V_5 -> V_15 , V_39 , 2 ) ;
F_8 ( V_5 , L_2 ,
V_38 [ 0 ] , V_38 [ 1 ] ) ;
V_37 [ 0 ] = 0x11 ;
V_37 [ 1 ] = 0x02 ;
V_37 [ 2 ] = 0x00 ;
F_4 ( V_5 -> V_15 , V_39 , 2 ) ;
F_8 ( V_5 , L_3 ,
V_38 [ 0 ] , V_38 [ 1 ] ) ;
}
#endif
return 0 ;
}
static int F_9 ( struct V_2 * V_3 , T_3 V_41 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
int V_42 = 0 ;
if ( V_41 & V_43 )
V_42 = 1 ;
else if ( V_41 & V_44 )
V_42 = 4 ;
else if ( V_41 & V_45 )
V_42 = 6 ;
else if ( V_41 & V_46 )
V_42 = 11 ;
if ( V_42 != V_16 -> V_19 ) {
V_16 -> V_19 = V_42 ;
F_5 ( V_16 ) ;
}
return 0 ;
}
static int F_10 ( struct V_2 * V_3 , struct V_47 * V_48 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
V_48 -> V_49 = V_50 |
V_51 | V_52 |
V_53 ;
V_48 -> V_54 = V_55 |
V_56 | V_57 |
V_58 ;
V_48 -> V_20 = V_16 -> V_20 ;
return 0 ;
}
static int F_11 ( struct V_2 * V_3 , const struct V_47 * V_48 )
{
struct V_1 * V_16 = F_1 ( V_3 ) ;
if ( V_48 -> type != V_59 )
return - V_60 ;
if ( V_48 -> V_20 != V_16 -> V_20 ) {
V_16 -> V_20 = V_48 -> V_20 ;
F_5 ( V_16 ) ;
}
return 0 ;
}
static int F_12 ( struct V_4 * V_5 ,
const struct V_61 * V_62 )
{
struct V_1 * V_16 ;
struct V_2 * V_3 ;
if ( ! F_13 ( V_5 -> V_15 , V_63 ) )
return - V_64 ;
F_14 ( V_5 , L_4 ,
V_5 -> V_7 << 1 , V_5 -> V_15 -> V_65 ) ;
V_16 = F_15 ( sizeof( struct V_1 ) , V_66 ) ;
if ( V_16 == NULL )
return - V_67 ;
V_3 = & V_16 -> V_3 ;
F_16 ( V_3 , V_5 , & V_68 ) ;
V_16 -> V_19 = 0 ;
V_16 -> V_20 = V_28 ;
return 0 ;
}
static int F_17 ( struct V_4 * V_5 )
{
struct V_2 * V_3 = F_18 ( V_5 ) ;
F_19 ( V_3 ) ;
F_20 ( F_1 ( V_3 ) ) ;
return 0 ;
}
