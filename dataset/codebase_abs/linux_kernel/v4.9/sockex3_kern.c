static inline void F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
switch ( V_3 ) {
case V_4 :
case V_5 :
F_2 ( V_2 , & V_6 , V_7 ) ;
break;
case V_8 :
case V_9 :
F_2 ( V_2 , & V_6 , V_10 ) ;
break;
case V_11 :
F_2 ( V_2 , & V_6 , V_12 ) ;
break;
case V_13 :
F_2 ( V_2 , & V_6 , V_14 ) ;
break;
}
}
static inline int F_3 ( struct V_1 * V_15 , T_2 V_16 )
{
return F_4 ( V_15 , V_16 + F_5 ( struct V_17 , V_18 ) )
& ( V_19 | V_20 ) ;
}
static inline T_3 F_6 ( struct V_1 * V_15 , T_2 V_21 )
{
T_2 V_22 = F_7 ( V_15 , V_21 ) ;
T_2 V_23 = F_7 ( V_15 , V_21 + 4 ) ;
T_2 V_24 = F_7 ( V_15 , V_21 + 8 ) ;
T_2 V_25 = F_7 ( V_15 , V_21 + 12 ) ;
return ( T_3 ) ( V_22 ^ V_23 ^ V_24 ^ V_25 ) ;
}
static struct V_26 * F_8 ( void )
{
T_1 V_27 = F_9 () ;
return F_10 ( & V_28 , & V_27 ) ;
}
static void F_11 ( struct V_1 * V_2 , struct V_26 * V_29 )
{
struct V_30 V_27 = V_29 -> V_31 ;
struct V_32 * V_33 ;
V_33 = F_10 ( & V_34 , & V_27 ) ;
if ( V_33 ) {
F_12 ( & V_33 -> V_35 , 1 ) ;
F_12 ( & V_33 -> V_36 , V_2 -> V_37 ) ;
} else {
struct V_32 V_38 = { 1 , V_2 -> V_37 } ;
F_13 ( & V_34 , & V_27 , & V_38 , V_39 ) ;
}
}
static T_4 void F_14 ( struct V_1 * V_2 ,
struct V_26 * V_29 , T_3 V_40 )
{
T_3 V_16 = V_2 -> V_41 [ 0 ] ;
int V_42 ;
switch ( V_40 ) {
case V_43 : {
struct V_44 {
T_5 V_45 ;
T_5 V_3 ;
};
T_3 V_46 = F_4 ( V_2 ,
V_16 + F_5 ( struct V_44 , V_45 ) ) ;
T_3 V_47 = F_4 ( V_2 ,
V_16 + F_5 ( struct V_44 , V_3 ) ) ;
if ( V_46 & ( V_48 | V_49 ) )
break;
V_16 += 4 ;
if ( V_46 & V_50 )
V_16 += 4 ;
if ( V_46 & V_51 )
V_16 += 4 ;
if ( V_46 & V_52 )
V_16 += 4 ;
V_2 -> V_41 [ 0 ] = V_16 ;
F_1 ( V_2 , V_47 ) ;
break;
}
case V_53 :
F_1 ( V_2 , V_11 ) ;
break;
case V_54 :
F_1 ( V_2 , V_13 ) ;
break;
case V_55 :
case V_56 :
V_29 -> V_31 . V_57 = F_7 ( V_2 , V_16 ) ;
case V_58 :
V_29 -> V_31 . V_40 = V_40 ;
F_11 ( V_2 , V_29 ) ;
break;
default:
break;
}
}
T_6 (V_12)( struct V_1 * V_2 )
{
struct V_26 * V_29 = F_8 () ;
T_3 V_16 , V_59 , V_40 ;
if ( ! V_29 )
return 0 ;
V_16 = V_2 -> V_41 [ 0 ] ;
if ( F_15 ( F_3 ( V_2 , V_16 ) ) )
return 0 ;
V_40 = F_16 ( V_2 , V_16 + F_5 ( struct V_17 , V_60 ) ) ;
if ( V_40 != V_43 ) {
V_29 -> V_31 . V_61 = F_7 ( V_2 , V_16 + F_5 ( struct V_17 , V_62 ) ) ;
V_29 -> V_31 . V_63 = F_7 ( V_2 , V_16 + F_5 ( struct V_17 , V_64 ) ) ;
}
V_59 = F_16 ( V_2 , V_16 + 0 ) ;
V_16 += ( V_59 & 0xF ) << 2 ;
V_2 -> V_41 [ 0 ] = V_16 ;
F_14 ( V_2 , V_29 , V_40 ) ;
return 0 ;
}
T_6 (V_14)( struct V_1 * V_2 )
{
struct V_26 * V_29 = F_8 () ;
T_3 V_16 , V_40 ;
if ( ! V_29 )
return 0 ;
V_16 = V_2 -> V_41 [ 0 ] ;
V_40 = F_16 ( V_2 ,
V_16 + F_5 ( struct V_65 , V_66 ) ) ;
V_29 -> V_31 . V_61 = F_6 ( V_2 ,
V_16 + F_5 ( struct V_65 , V_62 ) ) ;
V_29 -> V_31 . V_63 = F_6 ( V_2 ,
V_16 + F_5 ( struct V_65 , V_64 ) ) ;
V_16 += sizeof( struct V_65 ) ;
V_2 -> V_41 [ 0 ] = V_16 ;
F_14 ( V_2 , V_29 , V_40 ) ;
return 0 ;
}
T_6 (V_7)( struct V_1 * V_2 )
{
T_3 V_16 , V_3 ;
V_16 = V_2 -> V_41 [ 0 ] ;
V_3 = F_4 ( V_2 , V_16 + F_5 ( struct V_67 ,
V_68 ) ) ;
V_16 += sizeof( struct V_67 ) ;
V_2 -> V_41 [ 0 ] = V_16 ;
F_1 ( V_2 , V_3 ) ;
return 0 ;
}
T_6 (V_10)( struct V_1 * V_2 )
{
T_3 V_16 , V_69 ;
V_16 = V_2 -> V_41 [ 0 ] ;
V_69 = F_7 ( V_2 , V_16 ) ;
V_16 += sizeof( struct V_70 ) ;
V_2 -> V_41 [ 0 ] = V_16 ;
if ( V_69 & V_71 ) {
T_7 V_59 = F_16 ( V_2 , V_16 ) ;
if ( ( V_59 & 0xF0 ) == 4 )
F_1 ( V_2 , V_11 ) ;
else
F_1 ( V_2 , V_13 ) ;
} else {
F_1 ( V_2 , V_8 ) ;
}
return 0 ;
}
int F_17 ( struct V_1 * V_2 )
{
T_3 V_16 = V_72 ;
T_3 V_3 = F_4 ( V_2 , 12 ) ;
V_2 -> V_41 [ 0 ] = V_16 ;
F_1 ( V_2 , V_3 ) ;
return 0 ;
}
