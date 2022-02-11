static bool F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
switch ( V_3 ) {
case V_4 :
case V_5 :
case V_6 :
return true ;
default:
return false ;
} ;
}
static bool F_2 ( struct V_1 * V_2 , unsigned int V_3 )
{
switch ( V_3 ) {
case V_7 :
case V_8 :
case V_9 :
case V_10 :
case V_11 :
case V_12 :
case V_13 :
return true ;
default:
return false ;
}
}
static T_1 F_3 ( struct V_14 * V_15 ,
T_1 V_16 )
{
int V_17 ;
T_1 V_18 , V_19 ;
T_2 V_20 [ V_21 / 2 ] ;
V_17 = F_4 ( V_15 -> V_22 , V_23 ,
V_20 , V_21 ) ;
if ( V_17 < 0 ) {
F_5 ( & V_15 -> V_24 -> V_2 ,
L_1 ) ;
return V_17 ;
}
V_18 = ( ( ( V_16 >> 3 ) - ( ( T_1 ) F_6 ( V_20 [ V_25 ] ) << 1 ) ) *
( ( T_1 ) ( V_26 ) F_6 ( V_20 [ V_27 ] ) ) ) >> 11 ;
V_19 = ( ( ( ( ( V_16 >> 4 ) - ( ( T_1 ) F_6 ( V_20 [ V_25 ] ) ) ) *
( ( V_16 >> 4 ) - ( ( T_1 ) F_6 ( V_20 [ V_25 ] ) ) ) ) >> 12 ) *
( ( T_1 ) ( V_26 ) F_6 ( V_20 [ V_28 ] ) ) ) >> 14 ;
return ( V_15 -> V_29 * 5 + 128 ) >> 8 ;
}
static T_3 F_7 ( struct V_14 * V_15 ,
T_1 V_30 )
{
int V_17 ;
T_4 V_18 , V_19 , V_31 ;
T_2 V_20 [ V_32 / 2 ] ;
V_17 = F_4 ( V_15 -> V_22 , V_33 ,
V_20 , V_32 ) ;
if ( V_17 < 0 ) {
F_5 ( & V_15 -> V_24 -> V_2 ,
L_2 ) ;
return V_17 ;
}
V_18 = ( ( T_4 ) V_15 -> V_29 ) - 128000 ;
V_19 = V_18 * V_18 * ( T_4 ) ( V_26 ) F_6 ( V_20 [ V_34 ] ) ;
V_19 += ( V_18 * ( T_4 ) ( V_26 ) F_6 ( V_20 [ V_35 ] ) ) << 17 ;
V_19 += ( ( T_4 ) ( V_26 ) F_6 ( V_20 [ V_36 ] ) ) << 35 ;
V_18 = ( ( V_18 * V_18 * ( T_4 ) ( V_26 ) F_6 ( V_20 [ V_37 ] ) ) >> 8 ) +
( ( V_18 * ( T_4 ) ( V_26 ) F_6 ( V_20 [ V_38 ] ) ) << 12 ) ;
V_18 = ( ( ( ( T_4 ) 1 ) << 47 ) + V_18 ) * ( ( T_4 ) F_6 ( V_20 [ V_39 ] ) ) >> 33 ;
if ( V_18 == 0 )
return 0 ;
V_31 = ( ( ( ( T_4 ) 1048576 - V_30 ) << 31 ) - V_19 ) * 3125 ;
V_31 = F_8 ( V_31 , V_18 ) ;
V_18 = ( ( ( T_4 ) ( V_26 ) F_6 ( V_20 [ V_40 ] ) ) * ( V_31 >> 13 ) * ( V_31 >> 13 ) ) >> 25 ;
V_19 = ( ( ( T_4 ) ( V_26 ) F_6 ( V_20 [ V_41 ] ) ) * V_31 ) >> 19 ;
V_31 = ( ( V_31 + V_18 + V_19 ) >> 8 ) + ( ( ( T_4 ) ( V_26 ) F_6 ( V_20 [ V_42 ] ) ) << 4 ) ;
return ( T_3 ) V_31 ;
}
static int F_9 ( struct V_14 * V_15 ,
int * V_43 )
{
int V_17 ;
T_5 V_44 = 0 ;
T_1 V_16 , V_45 ;
V_17 = F_4 ( V_15 -> V_22 , V_9 ,
( V_46 * ) & V_44 , 3 ) ;
if ( V_17 < 0 ) {
F_5 ( & V_15 -> V_24 -> V_2 , L_3 ) ;
return V_17 ;
}
V_16 = F_10 ( V_44 ) >> 12 ;
V_45 = F_3 ( V_15 , V_16 ) ;
if ( V_43 ) {
* V_43 = V_45 * 10 ;
return V_47 ;
}
return 0 ;
}
static int F_11 ( struct V_14 * V_15 ,
int * V_43 , int * V_48 )
{
int V_17 ;
T_5 V_44 = 0 ;
T_1 V_30 ;
T_3 V_49 ;
V_17 = F_9 ( V_15 , NULL ) ;
if ( V_17 < 0 )
return V_17 ;
V_17 = F_4 ( V_15 -> V_22 , V_12 ,
( V_46 * ) & V_44 , 3 ) ;
if ( V_17 < 0 ) {
F_5 ( & V_15 -> V_24 -> V_2 , L_4 ) ;
return V_17 ;
}
V_30 = F_10 ( V_44 ) >> 12 ;
V_49 = F_7 ( V_15 , V_30 ) ;
* V_43 = V_49 ;
* V_48 = 256000 ;
return V_50 ;
}
static int F_12 ( struct V_51 * V_52 ,
struct V_53 const * V_54 ,
int * V_43 , int * V_48 , long V_55 )
{
int V_17 ;
struct V_14 * V_15 = F_13 ( V_52 ) ;
F_14 ( & V_15 -> V_56 ) ;
switch ( V_55 ) {
case V_57 :
switch ( V_54 -> type ) {
case V_58 :
V_17 = F_11 ( V_15 , V_43 , V_48 ) ;
break;
case V_59 :
V_17 = F_9 ( V_15 , V_43 ) ;
break;
default:
V_17 = - V_60 ;
break;
}
break;
default:
V_17 = - V_60 ;
break;
}
F_15 ( & V_15 -> V_56 ) ;
return V_17 ;
}
static int F_16 ( struct V_14 * V_15 )
{
int V_17 ;
V_17 = F_17 ( V_15 -> V_22 , V_5 ,
V_61 |
V_62 |
V_63 ,
V_64 |
V_65 |
V_66 ) ;
if ( V_17 < 0 ) {
F_5 ( & V_15 -> V_24 -> V_2 ,
L_5 ) ;
return V_17 ;
}
V_17 = F_17 ( V_15 -> V_22 , V_4 ,
V_67 ,
V_68 ) ;
if ( V_17 < 0 ) {
F_5 ( & V_15 -> V_24 -> V_2 ,
L_6 ) ;
return V_17 ;
}
return V_17 ;
}
static int F_18 ( struct V_69 * V_24 ,
const struct V_70 * V_71 )
{
int V_17 ;
struct V_51 * V_52 ;
struct V_14 * V_15 ;
unsigned int V_72 ;
V_52 = F_19 ( & V_24 -> V_2 , sizeof( * V_15 ) ) ;
if ( ! V_52 )
return - V_73 ;
V_15 = F_13 ( V_52 ) ;
F_20 ( & V_15 -> V_56 ) ;
V_15 -> V_24 = V_24 ;
V_52 -> V_2 . V_74 = & V_24 -> V_2 ;
V_52 -> V_75 = V_71 -> V_75 ;
V_52 -> V_76 = V_77 ;
V_52 -> V_78 = F_21 ( V_77 ) ;
V_52 -> V_79 = & V_80 ;
V_52 -> V_81 = V_82 ;
V_15 -> V_22 = F_22 ( V_24 , & V_83 ) ;
if ( F_23 ( V_15 -> V_22 ) ) {
F_5 ( & V_24 -> V_2 , L_7 ) ;
return F_24 ( V_15 -> V_22 ) ;
}
V_17 = F_25 ( V_15 -> V_22 , V_84 , & V_72 ) ;
if ( V_17 < 0 )
return V_17 ;
if ( V_72 != V_85 ) {
F_5 ( & V_24 -> V_2 , L_8 ,
V_85 , V_72 ) ;
return - V_60 ;
}
V_17 = F_16 ( V_15 ) ;
if ( V_17 < 0 )
return V_17 ;
return F_26 ( & V_24 -> V_2 , V_52 ) ;
}
