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
static int F_7 ( struct V_1 * V_2 ,
enum V_22 * V_6 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_5 ( V_4 ) ;
if ( V_4 -> V_17 )
* V_6 = V_23 | V_24 | V_25 | V_26 | V_27 ;
else
* V_6 = 0 ;
if ( * V_6 & V_23 )
V_4 -> V_20 = 1000 ;
else
V_4 -> V_20 = 100 ;
return 0 ;
}
static int F_8 ( struct V_1 * V_2 , T_2 * V_28 )
{
( void ) V_2 ;
* V_28 = 0 ;
return 0 ;
}
static int F_9 ( struct V_1 * V_2 , T_2 * V_29 )
{
( void ) V_2 ;
* V_29 = 0 ;
return 0 ;
}
static int F_10 ( struct V_1 * V_2 , T_3 * V_19 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_5 ( V_4 ) ;
* V_19 = V_4 -> V_19 ;
return 0 ;
}
static int F_11 ( struct V_1 * V_2 , T_3 * V_30 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_5 ( V_4 ) ;
if ( V_4 -> V_19 > 0xf00 )
* V_30 = 0xffff ;
else
* V_30 = ( V_4 -> V_19 << 4 ) + V_4 -> V_19 ;
return 0 ;
}
static int F_12 ( struct V_1 * V_2 , struct V_31 * V_32 )
{
V_32 -> V_33 = 800 ;
return 0 ;
}
static int F_13 ( struct V_1 * V_2 )
{
struct V_3 * V_11 = V_2 -> V_5 ;
struct V_34 * V_35 = & V_2 -> V_36 ;
T_1 V_37 [ 10 ] ;
T_2 V_38 = V_35 -> V_39 * 1000 ;
int V_40 = F_14 ( V_11 -> V_7 -> V_41 -> V_42 . V_43 ) ;
F_15 ( L_1 , V_44 ) ;
V_37 [ 4 ] = V_38 & 0xff ;
V_37 [ 5 ] = ( V_38 >> 8 ) & 0xff ;
V_37 [ 6 ] = ( V_38 >> 16 ) & 0xff ;
V_37 [ 7 ] = ( V_38 >> 24 ) & 0xff ;
if ( V_35 -> V_45 == V_46 && V_35 -> V_47 == V_48 )
V_35 -> V_45 = V_49 ;
switch ( V_35 -> V_45 ) {
case V_46 :
if ( V_35 -> V_47 != V_50 ) {
F_15 ( L_2 ,
V_44 , V_35 -> V_47 ) ;
return - V_51 ;
}
V_35 -> V_52 = V_53 ;
break;
case V_54 :
F_15 ( L_3 , V_44 ) ;
break;
case V_49 :
F_15 ( L_4 , V_44 ) ;
break;
default:
F_15 ( L_5 ,
V_44 , V_35 -> V_45 ) ;
return - V_51 ;
}
V_37 [ 0 ] = V_35 -> V_55 & 0xff ;
V_37 [ 1 ] = ( V_35 -> V_55 >> 8 ) & 0xff ;
V_37 [ 2 ] = ( V_35 -> V_55 >> 16 ) & 0xff ;
V_37 [ 3 ] = ( V_35 -> V_55 >> 24 ) & 0xff ;
switch ( V_35 -> V_47 ) {
case V_50 :
if ( V_40 == V_56 )
if ( F_1 ( V_2 ) )
F_16 ( V_11 -> V_7 ) ;
switch ( V_35 -> V_52 ) {
case V_57 :
V_37 [ 9 ] = 0 ; break;
case V_58 :
V_37 [ 9 ] = 1 ; break;
case V_59 :
V_37 [ 9 ] = 2 ; break;
case V_60 :
V_37 [ 9 ] = 3 ; break;
case V_61 :
V_37 [ 9 ] = 4 ; break;
case V_53 :
V_37 [ 9 ] = 5 ; break;
default:
V_37 [ 9 ] = 5 ; break;
}
if ( V_35 -> V_45 == V_49 )
V_37 [ 8 ] = V_62 ;
else
V_37 [ 8 ] = V_63 ;
break;
case V_48 :
V_37 [ 8 ] = V_64 ;
switch ( V_35 -> V_52 ) {
case V_58 :
V_37 [ 9 ] = 0 ; break;
case V_59 :
V_37 [ 9 ] = 1 ; break;
case V_65 :
V_37 [ 9 ] = 2 ; break;
case V_60 :
V_37 [ 9 ] = 3 ; break;
case V_66 :
V_37 [ 9 ] = 4 ; break;
default:
V_37 [ 9 ] = 0 ; break;
}
break;
case V_67 :
V_37 [ 8 ] = V_68 ;
V_37 [ 9 ] = 0 ;
break;
default:
F_15 ( L_2 ,
V_44 , V_35 -> V_47 ) ;
return - V_51 ;
}
if ( V_40 == V_56 )
F_3 ( V_2 , 0 ) ;
F_4 ( V_11 -> V_7 , V_69 , 0 , 0 , V_37 , 10 ) ;
V_11 -> V_17 = 0 ;
V_11 -> V_15 = V_14 ;
V_11 -> V_20 = 200 ;
return 0 ;
}
static int F_17 ( struct V_1 * V_2 ,
struct V_70 * V_71 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_15 ( L_6 , V_44 ) ;
if ( F_4 ( V_4 -> V_7 , V_72 , V_71 -> V_73 [ 0 ] , 0 ,
V_71 -> V_73 , V_71 -> V_74 ) ) {
return - V_75 ;
}
return 0 ;
}
static int F_18 ( struct V_1 * V_2 ,
enum V_76 V_77 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_37 ;
F_15 ( L_6 , V_44 ) ;
V_37 = ( V_77 == V_78 ) ? 0x00 : 0x01 ;
if ( F_4 ( V_4 -> V_7 , V_72 , V_37 , 0 ,
& V_37 , 0 ) ) {
return - V_75 ;
}
return 0 ;
}
static int F_19 ( struct V_1 * V_2 ,
enum V_79 V_80 )
{
struct V_3 * V_11 = V_2 -> V_5 ;
if ( F_4 ( V_11 -> V_7 , V_81 ,
( V_80 == V_82 ) , 0 , NULL , 0 ) ) {
return - V_75 ;
}
return 0 ;
}
static int F_20 ( struct V_1 * V_2 ,
enum V_83 V_84 )
{
struct V_3 * V_11 = V_2 -> V_5 ;
if ( F_4 ( V_11 -> V_7 , V_85 ,
V_84 == V_86 , 0 , NULL , 0 ) ) {
return - V_75 ;
}
return 0 ;
}
static int F_21 ( struct V_1 * V_2 , long V_87 )
{
struct V_3 * V_11 = V_2 -> V_5 ;
return F_4 ( V_11 -> V_7 , V_88 , V_87 , 0 , NULL , 0 ) ;
}
static int F_22 ( struct V_1 * V_2 , unsigned long V_89 )
{
struct V_3 * V_11 = V_2 -> V_5 ;
T_1 V_37 = V_89 & 0x7f ;
if ( F_4 ( V_11 -> V_7 , V_90 , V_37 , 0 ,
NULL , 0 ) ) {
return - V_75 ;
}
if ( F_4 ( V_11 -> V_7 , V_85 , ! ! ( V_89 & 0x80 ) ,
0 , NULL , 0 ) ) {
return - V_75 ;
}
return 0 ;
}
static void F_23 ( struct V_1 * V_2 )
{
struct V_3 * V_11 = V_2 -> V_5 ;
F_24 ( V_11 ) ;
}
struct V_1 * F_25 ( struct V_91 * V_7 )
{
struct V_3 * V_92 = F_26 ( sizeof( struct V_3 ) , V_93 ) ;
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
