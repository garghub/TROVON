static int F_1 ( struct V_1 * V_2 , int V_3 , int V_4 ,
T_1 * V_5 )
{
int V_6 , V_7 = - V_8 ;
F_2 ( L_1 , V_9 ) ;
for ( V_6 = 0 ; V_6 < V_3 ; V_6 ++ ) {
if ( V_4 < V_2 [ V_6 ] . V_10 ) {
* V_5 = V_2 [ V_6 ] . V_11 ;
V_7 = 0 ;
break;
}
}
F_2 ( L_2 , V_9 , * V_5 ) ;
return V_7 ;
}
static int F_3 ( struct V_12 * V_13 , enum V_14 V_15 )
{
struct V_16 * V_17 = V_13 -> V_18 ;
T_2 V_19 , V_20 , V_21 ;
char * V_22 ;
switch ( V_15 ) {
case V_23 :
V_22 = L_3 ;
V_19 = 0x00 ;
V_20 = 0x3d ;
V_21 = 0xa0 ;
break;
case V_24 :
V_22 = L_4 ;
V_19 = 0x00 ;
V_20 = 0x4b ;
V_21 = 0xd9 ;
break;
case V_25 :
V_22 = L_5 ;
V_19 = 0xfb ;
V_20 = 0x8e ;
V_21 = 0x39 ;
break;
default:
F_2 ( L_6 , V_9 ) ;
return - V_8 ;
}
F_2 ( L_7 , V_9 , V_22 ) ;
F_4 ( V_17 , 0x80b5 , V_19 ) ;
F_4 ( V_17 , 0x80b6 , V_20 ) ;
F_4 ( V_17 , 0x80b7 , V_21 ) ;
return 0 ;
}
static int F_5 ( struct V_12 * V_13 ,
T_3 V_26 )
{
struct V_16 * V_17 = V_13 -> V_18 ;
int V_6 ;
F_2 ( L_8 , V_9 , V_26 ) ;
switch ( V_26 ) {
case V_27 :
F_2 ( L_9 , V_9 ) ;
for ( V_6 = 0 ; V_6 < F_6 ( V_28 ) ; V_6 ++ )
F_4 ( V_17 ,
V_28 [ V_6 ] . V_29 ,
V_28 [ V_6 ] . V_11 ) ;
F_3 ( V_13 , V_17 -> V_30 -> V_31 ) ;
break;
case V_32 :
F_2 ( L_10 , V_9 ) ;
for ( V_6 = 0 ; V_6 < F_6 ( V_33 ) ; V_6 ++ )
F_4 ( V_17 ,
V_33 [ V_6 ] . V_29 ,
V_33 [ V_6 ] . V_11 ) ;
F_3 ( V_13 , V_17 -> V_30 -> V_34 ) ;
break;
case V_35 :
F_2 ( L_11 , V_9 ) ;
for ( V_6 = 0 ; V_6 < F_6 ( V_36 ) ; V_6 ++ )
F_4 ( V_17 ,
V_36 [ V_6 ] . V_29 ,
V_36 [ V_6 ] . V_11 ) ;
F_3 ( V_13 , V_17 -> V_30 -> V_34 ) ;
break;
default:
F_2 ( L_12 , V_9 ) ;
return - V_8 ;
}
V_17 -> V_37 = V_26 ;
return 0 ;
}
static int F_7 ( struct V_12 * V_13 )
{
struct V_38 * V_39 = & V_13 -> V_40 ;
struct V_16 * V_17 = V_13 -> V_18 ;
int V_7 = - V_8 ;
F_2 ( L_13 , V_9 , V_39 -> V_41 ) ;
if ( ( V_17 -> V_42 == V_39 -> V_41 ) &&
( V_17 -> V_37 == V_39 -> V_43 ) )
return 0 ;
if ( V_13 -> V_44 . V_45 . V_46 ) {
if ( V_13 -> V_44 . V_47 )
V_13 -> V_44 . V_47 ( V_13 , 1 ) ;
V_7 = V_13 -> V_44 . V_45 . V_46 ( V_13 ) ;
if ( V_13 -> V_44 . V_47 )
V_13 -> V_44 . V_47 ( V_13 , 0 ) ;
}
if ( V_7 < 0 )
return V_7 ;
F_8 ( 100 ) ;
F_5 ( V_13 , V_39 -> V_43 ) ;
V_17 -> V_42 = V_39 -> V_41 ;
return 0 ;
}
static int F_9 ( struct V_12 * V_13 , T_4 * V_48 )
{
struct V_16 * V_17 = V_13 -> V_18 ;
T_2 V_29 ;
T_5 V_49 = 0 ;
* V_48 = 0 ;
if ( V_17 -> V_37 == V_27 ) {
F_2 ( L_14 , V_9 ) ;
V_29 = F_10 ( V_17 , 0x4088 ) ;
if ( ( V_29 & 0x03 ) == 0x03 )
* V_48 |= V_50 | V_51 | V_52 ;
} else {
F_2 ( L_15 , V_9 ) ;
V_29 = F_10 ( V_17 , 0x4541 ) ;
if ( V_29 & 0x80 )
* V_48 |= V_52 ;
if ( V_29 & 0x20 )
* V_48 |= V_50 | V_51 ;
}
switch ( V_17 -> V_30 -> V_53 ) {
case V_54 :
F_2 ( L_16 , V_9 ) ;
if ( * V_48 & V_52 )
* V_48 |= V_55 | V_56 ;
break;
case V_57 :
F_2 ( L_17 , V_9 ) ;
if ( V_13 -> V_44 . V_45 . V_58 ) {
if ( V_13 -> V_44 . V_47 )
V_13 -> V_44 . V_47 ( V_13 , 1 ) ;
V_13 -> V_44 . V_45 . V_58 ( V_13 , & V_49 ) ;
if ( V_13 -> V_44 . V_47 )
V_13 -> V_44 . V_47 ( V_13 , 0 ) ;
}
if ( V_49 )
* V_48 |= V_55 | V_56 ;
break;
}
V_17 -> V_59 = * V_48 ;
if ( * V_48 & V_50 )
F_11 ( V_17 , - 1 ) ;
else
F_11 ( V_17 , 0 ) ;
F_2 ( L_18 , V_9 , * V_48 ) ;
return 0 ;
}
static int F_12 ( struct V_16 * V_17 , const T_1 * V_5 )
{
struct V_60 * V_61 = V_17 -> V_30 -> V_62 ;
int V_63 ;
T_1 V_64 ;
if ( ! V_61 )
return 0 ;
if ( 0 == ( V_17 -> V_59 & V_50 ) )
return F_11 ( V_17 , 0 ) ;
else if ( V_17 -> V_37 == V_35 )
V_64 = V_61 -> V_65 ;
else if ( V_17 -> V_37 == V_32 )
V_64 = V_61 -> V_66 ;
else
V_64 = V_61 -> V_67 ;
if ( * V_5 >= V_64 )
V_63 = 2 ;
else
V_63 = 1 ;
if ( ( V_17 -> V_68 ) &&
( ( ( V_64 < * V_5 ) ? ( * V_5 - V_64 ) : ( V_64 - * V_5 ) ) <= 10 ) )
return 0 ;
return F_11 ( V_17 , V_63 ) ;
}
static int F_13 ( struct V_12 * V_13 , T_1 * V_5 )
{
struct V_16 * V_17 = V_13 -> V_18 ;
int V_7 = - V_8 ;
F_2 ( L_1 , V_9 ) ;
if ( V_17 -> V_37 == V_35 )
V_7 = F_1 ( V_69 ,
F_6 ( V_69 ) ,
F_10 ( V_17 , 0x4522 ) ,
V_5 ) ;
else if ( V_17 -> V_37 == V_32 )
V_7 = F_1 ( V_70 ,
F_6 ( V_70 ) ,
F_10 ( V_17 , 0x4522 ) ,
V_5 ) ;
else
V_7 = F_1 ( V_71 ,
F_6 ( V_71 ) ,
F_10 ( V_17 , 0x4311 ) ,
V_5 ) ;
if ( V_17 -> V_30 -> V_62 )
F_12 ( V_17 , V_5 ) ;
return V_7 ;
}
static int F_14 ( struct V_12 * V_13 ,
T_1 * V_72 )
{
T_1 V_5 ;
T_5 V_73 ;
int V_7 = F_13 ( V_13 , & V_5 ) ;
* V_72 = 0 ;
if ( 0 == V_7 ) {
V_73 = ( V_5 * ( ( 1 << 24 ) / 10 ) ) ;
if ( V_73 >= 8960 * 0x10000 )
* V_72 = 0xffff ;
else
* V_72 = V_73 / 8960 ;
}
return V_7 ;
}
static int F_15 ( struct V_12 * V_13 , T_5 * V_74 )
{
struct V_16 * V_17 = V_13 -> V_18 ;
if ( V_17 -> V_37 == V_27 )
* V_74 = F_10 ( V_17 , 0x4087 ) ;
else
* V_74 = F_10 ( V_17 , 0x4543 ) ;
return 0 ;
}
static int F_16 ( struct V_12 * V_13 , T_5 * V_75 )
{
return F_15 ( V_13 , V_75 ) ;
}
static int F_17 ( struct V_12 * V_13 )
{
struct V_38 * V_39 = & V_13 -> V_40 ;
struct V_16 * V_17 = V_13 -> V_18 ;
V_39 -> V_41 = V_17 -> V_42 ;
V_39 -> V_43 = V_17 -> V_37 ;
return 0 ;
}
static int F_18 ( struct V_12 * V_13 ,
struct V_76 * V_77 )
{
V_77 -> V_78 = 1000 ;
return 0 ;
}
static void F_19 ( struct V_12 * V_13 )
{
struct V_16 * V_17 = V_13 -> V_18 ;
F_20 ( V_17 ) ;
}
struct V_12 * F_21 ( const struct V_79 * V_30 ,
struct V_80 * V_81 )
{
struct V_16 * V_17 = NULL ;
int V_82 ;
V_82 = F_22 ( & V_17 , V_81 , V_30 -> V_83 ) ;
switch ( V_82 ) {
case 0 :
F_2 ( L_19 , V_9 ) ;
break;
case 1 :
F_2 ( L_20 , V_9 ) ;
break;
default:
F_2 ( L_21 , V_9 ) ;
break;
}
V_17 -> V_30 = V_30 ;
V_17 -> V_81 = V_81 ;
V_17 -> V_84 = V_85 ;
memcpy ( & V_17 -> V_86 . V_44 , & V_87 ,
sizeof( struct V_88 ) ) ;
V_17 -> V_86 . V_18 = V_17 ;
V_17 -> V_86 . V_44 . V_89 . V_47 = V_90 ;
if ( F_23 ( & V_17 -> V_86 ) != 0 ) {
F_24 ( V_91 L_22 ,
V_9 ) ;
goto error;
}
F_25 ( & V_17 -> V_86 , 1 ) ;
return & V_17 -> V_86 ;
error:
F_20 ( V_17 ) ;
return NULL ;
}
