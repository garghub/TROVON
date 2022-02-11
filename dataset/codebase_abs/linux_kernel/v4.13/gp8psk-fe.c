static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_6 ;
V_4 -> V_7 -> V_8 ( V_4 -> V_9 , V_10 , 0 , 0 , & V_6 , 1 ) ;
return V_6 & V_11 ;
}
static int F_2 ( struct V_1 * V_2 , int V_12 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
return V_4 -> V_7 -> V_13 ( V_4 -> V_9 , V_14 , V_12 , 0 , NULL , 0 ) ;
}
static int F_3 ( struct V_3 * V_4 )
{
T_1 V_15 [ 6 ] ;
if ( F_4 ( V_16 , V_4 -> V_17 ) ) {
V_4 -> V_7 -> V_8 ( V_4 -> V_9 , V_18 , 0 , 0 , & V_4 -> V_19 , 1 ) ;
V_4 -> V_7 -> V_8 ( V_4 -> V_9 , V_20 , 0 , 0 , V_15 , 6 ) ;
V_4 -> V_21 = ( V_15 [ 1 ] ) << 8 | V_15 [ 0 ] ;
V_4 -> V_17 = V_16 + ( V_4 -> V_22 * V_23 ) / 1000 ;
}
return 0 ;
}
static int F_5 ( struct V_1 * V_2 ,
enum V_24 * V_6 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_3 ( V_4 ) ;
if ( V_4 -> V_19 )
* V_6 = V_25 | V_26 | V_27 | V_28 | V_29 ;
else
* V_6 = 0 ;
if ( * V_6 & V_25 )
V_4 -> V_22 = 1000 ;
else
V_4 -> V_22 = 100 ;
return 0 ;
}
static int F_6 ( struct V_1 * V_2 , T_2 * V_30 )
{
( void ) V_2 ;
* V_30 = 0 ;
return 0 ;
}
static int F_7 ( struct V_1 * V_2 , T_2 * V_31 )
{
( void ) V_2 ;
* V_31 = 0 ;
return 0 ;
}
static int F_8 ( struct V_1 * V_2 , T_3 * V_21 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_3 ( V_4 ) ;
* V_21 = V_4 -> V_21 ;
return 0 ;
}
static int F_9 ( struct V_1 * V_2 , T_3 * V_32 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_3 ( V_4 ) ;
if ( V_4 -> V_21 > 0xf00 )
* V_32 = 0xffff ;
else
* V_32 = ( V_4 -> V_21 << 4 ) + V_4 -> V_21 ;
return 0 ;
}
static int F_10 ( struct V_1 * V_2 , struct V_33 * V_34 )
{
V_34 -> V_35 = 800 ;
return 0 ;
}
static int F_11 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_36 * V_37 = & V_2 -> V_38 ;
T_1 V_39 [ 10 ] ;
T_2 V_40 = V_37 -> V_41 * 1000 ;
F_12 ( L_1 , V_42 ) ;
V_39 [ 4 ] = V_40 & 0xff ;
V_39 [ 5 ] = ( V_40 >> 8 ) & 0xff ;
V_39 [ 6 ] = ( V_40 >> 16 ) & 0xff ;
V_39 [ 7 ] = ( V_40 >> 24 ) & 0xff ;
if ( V_37 -> V_43 == V_44 && V_37 -> V_45 == V_46 )
V_37 -> V_43 = V_47 ;
switch ( V_37 -> V_43 ) {
case V_44 :
if ( V_37 -> V_45 != V_48 ) {
F_12 ( L_2 ,
V_42 , V_37 -> V_45 ) ;
return - V_49 ;
}
V_37 -> V_50 = V_51 ;
break;
case V_52 :
F_12 ( L_3 , V_42 ) ;
break;
case V_47 :
F_12 ( L_4 , V_42 ) ;
break;
default:
F_12 ( L_5 ,
V_42 , V_37 -> V_43 ) ;
return - V_49 ;
}
V_39 [ 0 ] = V_37 -> V_53 & 0xff ;
V_39 [ 1 ] = ( V_37 -> V_53 >> 8 ) & 0xff ;
V_39 [ 2 ] = ( V_37 -> V_53 >> 16 ) & 0xff ;
V_39 [ 3 ] = ( V_37 -> V_53 >> 24 ) & 0xff ;
switch ( V_37 -> V_45 ) {
case V_48 :
if ( V_4 -> V_54 )
if ( F_1 ( V_2 ) )
V_4 -> V_7 -> V_55 ( V_4 -> V_9 ) ;
switch ( V_37 -> V_50 ) {
case V_56 :
V_39 [ 9 ] = 0 ; break;
case V_57 :
V_39 [ 9 ] = 1 ; break;
case V_58 :
V_39 [ 9 ] = 2 ; break;
case V_59 :
V_39 [ 9 ] = 3 ; break;
case V_60 :
V_39 [ 9 ] = 4 ; break;
case V_51 :
V_39 [ 9 ] = 5 ; break;
default:
V_39 [ 9 ] = 5 ; break;
}
if ( V_37 -> V_43 == V_47 )
V_39 [ 8 ] = V_61 ;
else
V_39 [ 8 ] = V_62 ;
break;
case V_46 :
V_39 [ 8 ] = V_63 ;
switch ( V_37 -> V_50 ) {
case V_57 :
V_39 [ 9 ] = 0 ; break;
case V_58 :
V_39 [ 9 ] = 1 ; break;
case V_64 :
V_39 [ 9 ] = 2 ; break;
case V_59 :
V_39 [ 9 ] = 3 ; break;
case V_65 :
V_39 [ 9 ] = 4 ; break;
default:
V_39 [ 9 ] = 0 ; break;
}
break;
case V_66 :
V_39 [ 8 ] = V_67 ;
V_39 [ 9 ] = 0 ;
break;
default:
F_12 ( L_2 ,
V_42 , V_37 -> V_45 ) ;
return - V_49 ;
}
if ( V_4 -> V_54 )
F_2 ( V_2 , 0 ) ;
V_4 -> V_7 -> V_13 ( V_4 -> V_9 , V_68 , 0 , 0 , V_39 , 10 ) ;
V_4 -> V_19 = 0 ;
V_4 -> V_17 = V_16 ;
V_4 -> V_22 = 200 ;
return 0 ;
}
static int F_13 ( struct V_1 * V_2 ,
struct V_69 * V_70 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_12 ( L_6 , V_42 ) ;
if ( V_4 -> V_7 -> V_13 ( V_4 -> V_9 , V_71 , V_70 -> V_72 [ 0 ] , 0 ,
V_70 -> V_72 , V_70 -> V_73 ) ) {
return - V_74 ;
}
return 0 ;
}
static int F_14 ( struct V_1 * V_2 ,
enum V_75 V_76 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_39 ;
F_12 ( L_6 , V_42 ) ;
V_39 = ( V_76 == V_77 ) ? 0x00 : 0x01 ;
if ( V_4 -> V_7 -> V_13 ( V_4 -> V_9 , V_71 , V_39 , 0 ,
& V_39 , 0 ) ) {
return - V_74 ;
}
return 0 ;
}
static int F_15 ( struct V_1 * V_2 ,
enum V_78 V_79 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( V_4 -> V_7 -> V_13 ( V_4 -> V_9 , V_80 ,
( V_79 == V_81 ) , 0 , NULL , 0 ) ) {
return - V_74 ;
}
return 0 ;
}
static int F_16 ( struct V_1 * V_2 ,
enum V_82 V_83 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( V_4 -> V_7 -> V_13 ( V_4 -> V_9 , V_84 ,
V_83 == V_85 , 0 , NULL , 0 ) ) {
return - V_74 ;
}
return 0 ;
}
static int F_17 ( struct V_1 * V_2 , long V_86 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
return V_4 -> V_7 -> V_13 ( V_4 -> V_9 , V_87 , V_86 , 0 , NULL , 0 ) ;
}
static int F_18 ( struct V_1 * V_2 , unsigned long V_88 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_39 = V_88 & 0x7f ;
if ( V_4 -> V_7 -> V_13 ( V_4 -> V_9 , V_89 , V_39 , 0 , NULL , 0 ) )
return - V_74 ;
if ( V_4 -> V_7 -> V_13 ( V_4 -> V_9 , V_84 , ! ! ( V_88 & 0x80 ) ,
0 , NULL , 0 ) )
return - V_74 ;
return 0 ;
}
static void F_19 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_20 ( V_4 ) ;
}
struct V_1 * F_21 ( const struct V_90 * V_7 ,
void * V_9 , bool V_54 )
{
struct V_3 * V_4 ;
if ( ! V_7 || ! V_7 -> V_8 || ! V_7 -> V_13 || ! V_7 -> V_55 ) {
F_22 ( L_7 ) ;
return NULL ;
}
V_4 = F_23 ( sizeof( struct V_3 ) , V_91 ) ;
if ( ! V_4 )
return NULL ;
memcpy ( & V_4 -> V_2 . V_7 , & V_90 , sizeof( struct V_92 ) ) ;
V_4 -> V_2 . V_5 = V_4 ;
V_4 -> V_7 = V_7 ;
V_4 -> V_9 = V_9 ;
V_4 -> V_54 = V_54 ;
F_24 ( L_8 , V_54 ? L_9 : L_10 ) ;
return & V_4 -> V_2 ;
}
