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
static int F_13 ( struct V_1 * V_2 ,
struct V_33 * V_34 )
{
F_14 ( L_1 , V_35 ) ;
return 0 ;
}
static int F_15 ( struct V_1 * V_2 ,
struct V_33 * V_34 )
{
F_14 ( L_1 , V_35 ) ;
return 0 ;
}
static int F_16 ( struct V_1 * V_2 ,
struct V_36 * V_37 )
{
struct V_3 * V_11 = V_2 -> V_5 ;
struct V_38 * V_39 = & V_2 -> V_40 ;
T_1 V_41 [ 10 ] ;
T_3 V_42 = V_37 -> V_43 * 1000 ;
int V_44 = F_17 ( V_11 -> V_7 -> V_45 -> V_46 . V_47 ) ;
F_14 ( L_2 , V_35 ) ;
V_41 [ 4 ] = V_42 & 0xff ;
V_41 [ 5 ] = ( V_42 >> 8 ) & 0xff ;
V_41 [ 6 ] = ( V_42 >> 16 ) & 0xff ;
V_41 [ 7 ] = ( V_42 >> 24 ) & 0xff ;
if ( V_39 -> V_48 == V_49 && V_39 -> V_50 == V_51 )
V_39 -> V_48 = V_52 ;
switch ( V_39 -> V_48 ) {
case V_49 :
if ( V_39 -> V_50 != V_53 ) {
F_14 ( L_3 ,
V_35 , V_39 -> V_50 ) ;
return - V_54 ;
}
V_39 -> V_55 = V_56 ;
break;
case V_57 :
F_14 ( L_4 , V_35 ) ;
break;
case V_52 :
F_14 ( L_5 , V_35 ) ;
break;
default:
F_14 ( L_6 ,
V_35 , V_39 -> V_48 ) ;
return - V_54 ;
}
V_41 [ 0 ] = V_39 -> V_58 & 0xff ;
V_41 [ 1 ] = ( V_39 -> V_58 >> 8 ) & 0xff ;
V_41 [ 2 ] = ( V_39 -> V_58 >> 16 ) & 0xff ;
V_41 [ 3 ] = ( V_39 -> V_58 >> 24 ) & 0xff ;
switch ( V_39 -> V_50 ) {
case V_53 :
if ( V_44 == V_59 )
if ( F_1 ( V_2 ) )
F_18 ( V_11 -> V_7 ) ;
switch ( V_39 -> V_55 ) {
case V_60 :
V_41 [ 9 ] = 0 ; break;
case V_61 :
V_41 [ 9 ] = 1 ; break;
case V_62 :
V_41 [ 9 ] = 2 ; break;
case V_63 :
V_41 [ 9 ] = 3 ; break;
case V_64 :
V_41 [ 9 ] = 4 ; break;
case V_56 :
V_41 [ 9 ] = 5 ; break;
default:
V_41 [ 9 ] = 5 ; break;
}
if ( V_39 -> V_48 == V_52 )
V_41 [ 8 ] = V_65 ;
else
V_41 [ 8 ] = V_66 ;
break;
case V_51 :
V_41 [ 8 ] = V_67 ;
switch ( V_39 -> V_55 ) {
case V_61 :
V_41 [ 9 ] = 0 ; break;
case V_62 :
V_41 [ 9 ] = 1 ; break;
case V_68 :
V_41 [ 9 ] = 2 ; break;
case V_63 :
V_41 [ 9 ] = 3 ; break;
case V_69 :
V_41 [ 9 ] = 4 ; break;
default:
V_41 [ 9 ] = 0 ; break;
}
break;
case V_70 :
V_41 [ 8 ] = V_71 ;
V_41 [ 9 ] = 0 ;
break;
default:
F_14 ( L_3 ,
V_35 , V_39 -> V_50 ) ;
return - V_54 ;
}
if ( V_44 == V_59 )
F_3 ( V_2 , 0 ) ;
F_4 ( V_11 -> V_7 , V_72 , 0 , 0 , V_41 , 10 ) ;
V_11 -> V_17 = 0 ;
V_11 -> V_15 = V_14 ;
V_11 -> V_20 = 200 ;
return 0 ;
}
static int F_19 ( struct V_1 * V_2 ,
struct V_73 * V_74 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_14 ( L_7 , V_35 ) ;
if ( F_4 ( V_4 -> V_7 , V_75 , V_74 -> V_76 [ 0 ] , 0 ,
V_74 -> V_76 , V_74 -> V_77 ) ) {
return - V_78 ;
}
return 0 ;
}
static int F_20 ( struct V_1 * V_2 ,
T_5 V_79 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_41 ;
F_14 ( L_7 , V_35 ) ;
V_41 = ( V_79 == V_80 ) ? 0x00 : 0x01 ;
if ( F_4 ( V_4 -> V_7 , V_75 , V_41 , 0 ,
& V_41 , 0 ) ) {
return - V_78 ;
}
return 0 ;
}
static int F_21 ( struct V_1 * V_2 , T_6 V_81 )
{
struct V_3 * V_11 = V_2 -> V_5 ;
if ( F_4 ( V_11 -> V_7 , V_82 ,
( V_81 == V_83 ) , 0 , NULL , 0 ) ) {
return - V_78 ;
}
return 0 ;
}
static int F_22 ( struct V_1 * V_2 , T_7 V_84 )
{
struct V_3 * V_11 = V_2 -> V_5 ;
if ( F_4 ( V_11 -> V_7 , V_85 ,
V_84 == V_86 , 0 , NULL , 0 ) ) {
return - V_78 ;
}
return 0 ;
}
static int F_23 ( struct V_1 * V_2 , long V_87 )
{
struct V_3 * V_11 = V_2 -> V_5 ;
return F_4 ( V_11 -> V_7 , V_88 , V_87 , 0 , NULL , 0 ) ;
}
static int F_24 ( struct V_1 * V_2 , unsigned long V_89 )
{
struct V_3 * V_11 = V_2 -> V_5 ;
T_1 V_41 = V_89 & 0x7f ;
if ( F_4 ( V_11 -> V_7 , V_90 , V_41 , 0 ,
NULL , 0 ) ) {
return - V_78 ;
}
if ( F_4 ( V_11 -> V_7 , V_85 , ! ! ( V_89 & 0x80 ) ,
0 , NULL , 0 ) ) {
return - V_78 ;
}
return 0 ;
}
static void F_25 ( struct V_1 * V_2 )
{
struct V_3 * V_11 = V_2 -> V_5 ;
F_26 ( V_11 ) ;
}
struct V_1 * F_27 ( struct V_91 * V_7 )
{
struct V_3 * V_92 = F_28 ( sizeof( struct V_3 ) , V_93 ) ;
if ( V_92 == NULL )
goto error;
V_92 -> V_7 = V_7 ;
memcpy ( & V_92 -> V_2 . V_94 , & V_95 , sizeof( struct V_96 ) ) ;
V_92 -> V_2 . V_5 = V_92 ;
goto V_97;
error:
return NULL ;
V_97:
return & V_92 -> V_2 ;
}
