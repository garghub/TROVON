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
static int F_3 ( struct V_14 * V_15 ,
struct V_16 * V_17 )
{
int V_18 ;
T_1 V_19 [ V_20 / 2 ] ;
V_18 = F_4 ( V_15 -> V_21 , V_22 ,
V_19 , V_20 ) ;
if ( V_18 < 0 ) {
F_5 ( & V_15 -> V_23 -> V_2 ,
L_1 ) ;
return V_18 ;
}
V_17 -> V_24 = ( V_25 ) F_6 ( V_19 [ 0 ] ) ;
V_17 -> V_26 = ( V_27 ) F_6 ( V_19 [ 1 ] ) ;
V_17 -> V_28 = ( V_27 ) F_6 ( V_19 [ 2 ] ) ;
return 0 ;
}
static int F_7 ( struct V_14 * V_15 ,
struct V_29 * V_17 )
{
int V_18 ;
T_1 V_19 [ V_30 / 2 ] ;
V_18 = F_4 ( V_15 -> V_21 , V_31 ,
V_19 , V_30 ) ;
if ( V_18 < 0 ) {
F_5 ( & V_15 -> V_23 -> V_2 ,
L_2 ) ;
return V_18 ;
}
V_17 -> V_32 = ( V_25 ) F_6 ( V_19 [ 0 ] ) ;
V_17 -> V_33 = ( V_27 ) F_6 ( V_19 [ 1 ] ) ;
V_17 -> V_34 = ( V_27 ) F_6 ( V_19 [ 2 ] ) ;
V_17 -> V_35 = ( V_27 ) F_6 ( V_19 [ 3 ] ) ;
V_17 -> V_36 = ( V_27 ) F_6 ( V_19 [ 4 ] ) ;
V_17 -> V_37 = ( V_27 ) F_6 ( V_19 [ 5 ] ) ;
V_17 -> V_38 = ( V_27 ) F_6 ( V_19 [ 6 ] ) ;
V_17 -> V_39 = ( V_27 ) F_6 ( V_19 [ 7 ] ) ;
V_17 -> V_40 = ( V_27 ) F_6 ( V_19 [ 8 ] ) ;
return 0 ;
}
static T_2 F_8 ( struct V_14 * V_15 ,
struct V_16 * V_17 ,
T_2 V_41 )
{
T_2 V_42 , V_43 , V_44 ;
V_42 = ( ( ( V_41 >> 3 ) - ( ( T_2 ) V_17 -> V_24 << 1 ) ) *
( ( T_2 ) V_17 -> V_26 ) ) >> 11 ;
V_43 = ( ( ( ( ( V_41 >> 4 ) - ( ( T_2 ) V_17 -> V_24 ) ) *
( ( V_41 >> 4 ) - ( ( T_2 ) V_17 -> V_24 ) ) ) >> 12 ) *
( ( T_2 ) V_17 -> V_28 ) ) >> 14 ;
V_15 -> V_45 = V_42 + V_43 ;
V_44 = ( V_15 -> V_45 * 5 + 128 ) >> 8 ;
return V_44 ;
}
static T_3 F_9 ( struct V_14 * V_15 ,
struct V_29 * V_17 ,
T_2 V_46 )
{
T_4 V_42 , V_43 , V_47 ;
V_42 = ( ( T_4 ) V_15 -> V_45 ) - 128000 ;
V_43 = V_42 * V_42 * ( T_4 ) V_17 -> V_37 ;
V_43 = V_43 + ( ( V_42 * ( T_4 ) V_17 -> V_36 ) << 17 ) ;
V_43 = V_43 + ( ( ( T_4 ) V_17 -> V_35 ) << 35 ) ;
V_42 = ( ( V_42 * V_42 * ( T_4 ) V_17 -> V_34 ) >> 8 ) +
( ( V_42 * ( T_4 ) V_17 -> V_33 ) << 12 ) ;
V_42 = ( ( ( ( ( T_4 ) 1 ) << 47 ) + V_42 ) ) * ( ( T_4 ) V_17 -> V_32 ) >> 33 ;
if ( V_42 == 0 )
return 0 ;
V_47 = ( ( ( ( T_4 ) 1048576 - V_46 ) << 31 ) - V_43 ) * 3125 ;
V_47 = F_10 ( V_47 , V_42 ) ;
V_42 = ( ( ( T_4 ) V_17 -> V_40 ) * ( V_47 >> 13 ) * ( V_47 >> 13 ) ) >> 25 ;
V_43 = ( ( ( T_4 ) V_17 -> V_39 ) * V_47 ) >> 19 ;
V_47 = ( ( V_47 + V_42 + V_43 ) >> 8 ) + ( ( ( T_4 ) V_17 -> V_38 ) << 4 ) ;
return ( T_3 ) V_47 ;
}
static int F_11 ( struct V_14 * V_15 ,
int * V_48 )
{
int V_18 ;
T_5 V_49 = 0 ;
T_2 V_41 , V_50 ;
struct V_16 V_17 ;
V_18 = F_3 ( V_15 , & V_17 ) ;
if ( V_18 < 0 )
return V_18 ;
V_18 = F_4 ( V_15 -> V_21 , V_9 ,
( V_51 * ) & V_49 , 3 ) ;
if ( V_18 < 0 ) {
F_5 ( & V_15 -> V_23 -> V_2 , L_3 ) ;
return V_18 ;
}
V_41 = F_12 ( V_49 ) >> 12 ;
V_50 = F_8 ( V_15 , & V_17 , V_41 ) ;
if ( V_48 ) {
* V_48 = V_50 * 10 ;
return V_52 ;
}
return 0 ;
}
static int F_13 ( struct V_14 * V_15 ,
int * V_48 , int * V_53 )
{
int V_18 ;
T_5 V_49 = 0 ;
T_2 V_46 ;
T_3 V_54 ;
struct V_29 V_17 ;
V_18 = F_7 ( V_15 , & V_17 ) ;
if ( V_18 < 0 )
return V_18 ;
V_18 = F_11 ( V_15 , NULL ) ;
if ( V_18 < 0 )
return V_18 ;
V_18 = F_4 ( V_15 -> V_21 , V_12 ,
( V_51 * ) & V_49 , 3 ) ;
if ( V_18 < 0 ) {
F_5 ( & V_15 -> V_23 -> V_2 , L_4 ) ;
return V_18 ;
}
V_46 = F_12 ( V_49 ) >> 12 ;
V_54 = F_9 ( V_15 , & V_17 , V_46 ) ;
* V_48 = V_54 ;
* V_53 = 256000 ;
return V_55 ;
}
static int F_14 ( struct V_56 * V_57 ,
struct V_58 const * V_59 ,
int * V_48 , int * V_53 , long V_60 )
{
int V_18 ;
struct V_14 * V_15 = F_15 ( V_57 ) ;
F_16 ( & V_15 -> V_61 ) ;
switch ( V_60 ) {
case V_62 :
switch ( V_59 -> type ) {
case V_63 :
V_18 = F_13 ( V_15 , V_48 , V_53 ) ;
break;
case V_64 :
V_18 = F_11 ( V_15 , V_48 ) ;
break;
default:
V_18 = - V_65 ;
break;
}
break;
default:
V_18 = - V_65 ;
break;
}
F_17 ( & V_15 -> V_61 ) ;
return V_18 ;
}
static int F_18 ( struct V_14 * V_15 )
{
int V_18 ;
V_18 = F_19 ( V_15 -> V_21 , V_5 ,
V_66 |
V_67 |
V_68 ,
V_69 |
V_70 |
V_71 ) ;
if ( V_18 < 0 ) {
F_5 ( & V_15 -> V_23 -> V_2 ,
L_5 ) ;
return V_18 ;
}
V_18 = F_19 ( V_15 -> V_21 , V_4 ,
V_72 ,
V_73 ) ;
if ( V_18 < 0 ) {
F_5 ( & V_15 -> V_23 -> V_2 ,
L_5 ) ;
return V_18 ;
}
return V_18 ;
}
static int F_20 ( struct V_74 * V_23 ,
const struct V_75 * V_76 )
{
int V_18 ;
struct V_56 * V_57 ;
struct V_14 * V_15 ;
unsigned int V_77 ;
V_57 = F_21 ( & V_23 -> V_2 , sizeof( * V_15 ) ) ;
if ( ! V_57 )
return - V_78 ;
F_22 ( V_23 , V_57 ) ;
V_15 = F_15 ( V_57 ) ;
F_23 ( & V_15 -> V_61 ) ;
V_15 -> V_23 = V_23 ;
V_57 -> V_2 . V_79 = & V_23 -> V_2 ;
V_57 -> V_80 = V_76 -> V_80 ;
V_57 -> V_81 = V_82 ;
V_57 -> V_83 = F_24 ( V_82 ) ;
V_57 -> V_84 = & V_85 ;
V_57 -> V_86 = V_87 ;
V_15 -> V_21 = F_25 ( V_23 , & V_88 ) ;
if ( F_26 ( V_15 -> V_21 ) ) {
F_5 ( & V_23 -> V_2 , L_6 ) ;
return F_27 ( V_15 -> V_21 ) ;
}
V_18 = F_28 ( V_15 -> V_21 , V_89 , & V_77 ) ;
if ( V_18 < 0 )
return V_18 ;
if ( V_77 != V_90 ) {
F_5 ( & V_23 -> V_2 , L_7 ,
V_90 , V_77 ) ;
return - V_65 ;
}
V_18 = F_18 ( V_15 ) ;
if ( V_18 < 0 )
return V_18 ;
return F_29 ( & V_23 -> V_2 , V_57 ) ;
}
