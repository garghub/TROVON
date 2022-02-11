static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_6 ;
F_2 ( V_4 -> V_7 , V_8 , 0 , 0 , & V_6 , 1 ) ;
return V_6 & V_9 ;
}
static int F_3 ( struct V_1 * V_2 , int V_10 )
{
struct V_3 * V_11 = V_2 -> V_5 ;
return F_4 ( V_11 -> V_7 , V_12 , V_10 , 0 , NULL , 0 ) ;
}
static int F_5 ( struct V_3 * V_4 )
{
T_1 V_13 [ 6 ] ;
if ( F_6 ( V_14 , V_4 -> V_15 ) ) {
F_2 ( V_4 -> V_7 , V_16 , 0 , 0 , & V_4 -> V_17 , 1 ) ;
F_2 ( V_4 -> V_7 , V_18 , 0 , 0 , V_13 , 6 ) ;
V_4 -> V_19 = ( V_13 [ 1 ] ) << 8 | V_13 [ 0 ] ;
V_4 -> V_15 = V_14 + ( V_4 -> V_20 * V_21 ) / 1000 ;
}
return 0 ;
}
static int F_7 ( struct V_1 * V_2 , T_2 * V_6 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_5 ( V_4 ) ;
if ( V_4 -> V_17 )
* V_6 = V_22 | V_23 | V_24 | V_25 | V_26 ;
else
* V_6 = 0 ;
if ( * V_6 & V_22 )
V_4 -> V_20 = 1000 ;
else
V_4 -> V_20 = 100 ;
return 0 ;
}
static int F_8 ( struct V_1 * V_2 , T_3 * V_27 )
{
( void ) V_2 ;
* V_27 = 0 ;
return 0 ;
}
static int F_9 ( struct V_1 * V_2 , T_3 * V_28 )
{
( void ) V_2 ;
* V_28 = 0 ;
return 0 ;
}
static int F_10 ( struct V_1 * V_2 , T_4 * V_19 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_5 ( V_4 ) ;
* V_19 = V_4 -> V_19 ;
return 0 ;
}
static int F_11 ( struct V_1 * V_2 , T_4 * V_29 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_5 ( V_4 ) ;
if ( V_4 -> V_19 > 0xf00 )
* V_29 = 0xffff ;
else
* V_29 = ( V_4 -> V_19 << 4 ) + V_4 -> V_19 ;
return 0 ;
}
static int F_12 ( struct V_1 * V_2 , struct V_30 * V_31 )
{
V_31 -> V_32 = 800 ;
return 0 ;
}
static int F_13 ( struct V_1 * V_2 )
{
struct V_3 * V_11 = V_2 -> V_5 ;
struct V_33 * V_34 = & V_2 -> V_35 ;
T_1 V_36 [ 10 ] ;
T_3 V_37 = V_34 -> V_38 * 1000 ;
int V_39 = F_14 ( V_11 -> V_7 -> V_40 -> V_41 . V_42 ) ;
F_15 ( L_1 , V_43 ) ;
V_36 [ 4 ] = V_37 & 0xff ;
V_36 [ 5 ] = ( V_37 >> 8 ) & 0xff ;
V_36 [ 6 ] = ( V_37 >> 16 ) & 0xff ;
V_36 [ 7 ] = ( V_37 >> 24 ) & 0xff ;
if ( V_34 -> V_44 == V_45 && V_34 -> V_46 == V_47 )
V_34 -> V_44 = V_48 ;
switch ( V_34 -> V_44 ) {
case V_45 :
if ( V_34 -> V_46 != V_49 ) {
F_15 ( L_2 ,
V_43 , V_34 -> V_46 ) ;
return - V_50 ;
}
V_34 -> V_51 = V_52 ;
break;
case V_53 :
F_15 ( L_3 , V_43 ) ;
break;
case V_48 :
F_15 ( L_4 , V_43 ) ;
break;
default:
F_15 ( L_5 ,
V_43 , V_34 -> V_44 ) ;
return - V_50 ;
}
V_36 [ 0 ] = V_34 -> V_54 & 0xff ;
V_36 [ 1 ] = ( V_34 -> V_54 >> 8 ) & 0xff ;
V_36 [ 2 ] = ( V_34 -> V_54 >> 16 ) & 0xff ;
V_36 [ 3 ] = ( V_34 -> V_54 >> 24 ) & 0xff ;
switch ( V_34 -> V_46 ) {
case V_49 :
if ( V_39 == V_55 )
if ( F_1 ( V_2 ) )
F_16 ( V_11 -> V_7 ) ;
switch ( V_34 -> V_51 ) {
case V_56 :
V_36 [ 9 ] = 0 ; break;
case V_57 :
V_36 [ 9 ] = 1 ; break;
case V_58 :
V_36 [ 9 ] = 2 ; break;
case V_59 :
V_36 [ 9 ] = 3 ; break;
case V_60 :
V_36 [ 9 ] = 4 ; break;
case V_52 :
V_36 [ 9 ] = 5 ; break;
default:
V_36 [ 9 ] = 5 ; break;
}
if ( V_34 -> V_44 == V_48 )
V_36 [ 8 ] = V_61 ;
else
V_36 [ 8 ] = V_62 ;
break;
case V_47 :
V_36 [ 8 ] = V_63 ;
switch ( V_34 -> V_51 ) {
case V_57 :
V_36 [ 9 ] = 0 ; break;
case V_58 :
V_36 [ 9 ] = 1 ; break;
case V_64 :
V_36 [ 9 ] = 2 ; break;
case V_59 :
V_36 [ 9 ] = 3 ; break;
case V_65 :
V_36 [ 9 ] = 4 ; break;
default:
V_36 [ 9 ] = 0 ; break;
}
break;
case V_66 :
V_36 [ 8 ] = V_67 ;
V_36 [ 9 ] = 0 ;
break;
default:
F_15 ( L_2 ,
V_43 , V_34 -> V_46 ) ;
return - V_50 ;
}
if ( V_39 == V_55 )
F_3 ( V_2 , 0 ) ;
F_4 ( V_11 -> V_7 , V_68 , 0 , 0 , V_36 , 10 ) ;
V_11 -> V_17 = 0 ;
V_11 -> V_15 = V_14 ;
V_11 -> V_20 = 200 ;
return 0 ;
}
static int F_17 ( struct V_1 * V_2 ,
struct V_69 * V_70 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_15 ( L_6 , V_43 ) ;
if ( F_4 ( V_4 -> V_7 , V_71 , V_70 -> V_72 [ 0 ] , 0 ,
V_70 -> V_72 , V_70 -> V_73 ) ) {
return - V_74 ;
}
return 0 ;
}
static int F_18 ( struct V_1 * V_2 ,
T_5 V_75 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_36 ;
F_15 ( L_6 , V_43 ) ;
V_36 = ( V_75 == V_76 ) ? 0x00 : 0x01 ;
if ( F_4 ( V_4 -> V_7 , V_71 , V_36 , 0 ,
& V_36 , 0 ) ) {
return - V_74 ;
}
return 0 ;
}
static int F_19 ( struct V_1 * V_2 , T_6 V_77 )
{
struct V_3 * V_11 = V_2 -> V_5 ;
if ( F_4 ( V_11 -> V_7 , V_78 ,
( V_77 == V_79 ) , 0 , NULL , 0 ) ) {
return - V_74 ;
}
return 0 ;
}
static int F_20 ( struct V_1 * V_2 , T_7 V_80 )
{
struct V_3 * V_11 = V_2 -> V_5 ;
if ( F_4 ( V_11 -> V_7 , V_81 ,
V_80 == V_82 , 0 , NULL , 0 ) ) {
return - V_74 ;
}
return 0 ;
}
static int F_21 ( struct V_1 * V_2 , long V_83 )
{
struct V_3 * V_11 = V_2 -> V_5 ;
return F_4 ( V_11 -> V_7 , V_84 , V_83 , 0 , NULL , 0 ) ;
}
static int F_22 ( struct V_1 * V_2 , unsigned long V_85 )
{
struct V_3 * V_11 = V_2 -> V_5 ;
T_1 V_36 = V_85 & 0x7f ;
if ( F_4 ( V_11 -> V_7 , V_86 , V_36 , 0 ,
NULL , 0 ) ) {
return - V_74 ;
}
if ( F_4 ( V_11 -> V_7 , V_81 , ! ! ( V_85 & 0x80 ) ,
0 , NULL , 0 ) ) {
return - V_74 ;
}
return 0 ;
}
static void F_23 ( struct V_1 * V_2 )
{
struct V_3 * V_11 = V_2 -> V_5 ;
F_24 ( V_11 ) ;
}
struct V_1 * F_25 ( struct V_87 * V_7 )
{
struct V_3 * V_88 = F_26 ( sizeof( struct V_3 ) , V_89 ) ;
if ( V_88 == NULL )
goto error;
V_88 -> V_7 = V_7 ;
memcpy ( & V_88 -> V_2 . V_90 , & V_91 , sizeof( struct V_92 ) ) ;
V_88 -> V_2 . V_5 = V_88 ;
goto V_93;
error:
return NULL ;
V_93:
return & V_88 -> V_2 ;
}
