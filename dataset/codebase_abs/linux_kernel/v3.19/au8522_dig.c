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
if ( V_36 ) {
F_2 ( L_11 , V_9 ) ;
for ( V_6 = 0 ; V_6 < F_6 ( V_37 ) ; V_6 ++ )
F_4 ( V_17 ,
V_37 [ V_6 ] . V_29 ,
V_37 [ V_6 ] . V_11 ) ;
F_3 ( V_13 , V_17 -> V_30 -> V_34 ) ;
F_7 ( 100 ) ;
F_4 ( V_17 , 0x821a , 0x00 ) ;
} else {
F_2 ( L_12 , V_9 ) ;
for ( V_6 = 0 ; V_6 < F_6 ( V_38 ) ; V_6 ++ )
F_4 ( V_17 ,
V_38 [ V_6 ] . V_29 ,
V_38 [ V_6 ] . V_11 ) ;
F_3 ( V_13 , V_17 -> V_30 -> V_34 ) ;
}
break;
default:
F_2 ( L_13 , V_9 ) ;
return - V_8 ;
}
V_17 -> V_39 = V_26 ;
return 0 ;
}
static int F_8 ( struct V_12 * V_13 )
{
struct V_40 * V_41 = & V_13 -> V_42 ;
struct V_16 * V_17 = V_13 -> V_18 ;
int V_7 = - V_8 ;
F_2 ( L_14 , V_9 , V_41 -> V_43 ) ;
if ( ( V_17 -> V_44 == V_41 -> V_43 ) &&
( V_17 -> V_39 == V_41 -> V_45 ) )
return 0 ;
if ( V_13 -> V_46 . V_47 . V_48 ) {
if ( V_13 -> V_46 . V_49 )
V_13 -> V_46 . V_49 ( V_13 , 1 ) ;
V_7 = V_13 -> V_46 . V_47 . V_48 ( V_13 ) ;
if ( V_13 -> V_46 . V_49 )
V_13 -> V_46 . V_49 ( V_13 , 0 ) ;
}
if ( V_7 < 0 )
return V_7 ;
if ( V_36 ) {
F_2 ( L_15 ,
V_9 ) ;
F_7 ( 250 ) ;
} else
F_7 ( 100 ) ;
F_5 ( V_13 , V_41 -> V_45 ) ;
V_17 -> V_44 = V_41 -> V_43 ;
return 0 ;
}
static int F_9 ( struct V_12 * V_13 , T_4 * V_50 )
{
struct V_16 * V_17 = V_13 -> V_18 ;
T_2 V_29 ;
T_5 V_51 = 0 ;
* V_50 = 0 ;
if ( V_17 -> V_39 == V_27 ) {
F_2 ( L_16 , V_9 ) ;
V_29 = F_10 ( V_17 , 0x4088 ) ;
if ( ( V_29 & 0x03 ) == 0x03 )
* V_50 |= V_52 | V_53 | V_54 ;
} else {
F_2 ( L_17 , V_9 ) ;
V_29 = F_10 ( V_17 , 0x4541 ) ;
if ( V_29 & 0x80 )
* V_50 |= V_54 ;
if ( V_29 & 0x20 )
* V_50 |= V_52 | V_53 ;
}
switch ( V_17 -> V_30 -> V_55 ) {
case V_56 :
F_2 ( L_18 , V_9 ) ;
if ( * V_50 & V_54 )
* V_50 |= V_57 | V_58 ;
break;
case V_59 :
F_2 ( L_19 , V_9 ) ;
if ( V_13 -> V_46 . V_47 . V_60 ) {
if ( V_13 -> V_46 . V_49 )
V_13 -> V_46 . V_49 ( V_13 , 1 ) ;
V_13 -> V_46 . V_47 . V_60 ( V_13 , & V_51 ) ;
if ( V_13 -> V_46 . V_49 )
V_13 -> V_46 . V_49 ( V_13 , 0 ) ;
}
if ( V_51 )
* V_50 |= V_57 | V_58 ;
break;
}
V_17 -> V_61 = * V_50 ;
if ( * V_50 & V_52 )
F_11 ( V_17 , - 1 ) ;
else
F_11 ( V_17 , 0 ) ;
F_2 ( L_20 , V_9 , * V_50 ) ;
return 0 ;
}
static int F_12 ( struct V_16 * V_17 , const T_1 * V_5 )
{
struct V_62 * V_63 = V_17 -> V_30 -> V_64 ;
int V_65 ;
T_1 V_66 ;
if ( ! V_63 )
return 0 ;
if ( 0 == ( V_17 -> V_61 & V_52 ) )
return F_11 ( V_17 , 0 ) ;
else if ( V_17 -> V_39 == V_35 )
V_66 = V_63 -> V_67 ;
else if ( V_17 -> V_39 == V_32 )
V_66 = V_63 -> V_68 ;
else
V_66 = V_63 -> V_69 ;
if ( * V_5 >= V_66 )
V_65 = 2 ;
else
V_65 = 1 ;
if ( ( V_17 -> V_70 ) &&
( ( ( V_66 < * V_5 ) ? ( * V_5 - V_66 ) : ( V_66 - * V_5 ) ) <= 10 ) )
return 0 ;
return F_11 ( V_17 , V_65 ) ;
}
static int F_13 ( struct V_12 * V_13 , T_1 * V_5 )
{
struct V_16 * V_17 = V_13 -> V_18 ;
int V_7 = - V_8 ;
F_2 ( L_1 , V_9 ) ;
if ( V_17 -> V_39 == V_35 )
V_7 = F_1 ( V_71 ,
F_6 ( V_71 ) ,
F_10 ( V_17 , 0x4522 ) ,
V_5 ) ;
else if ( V_17 -> V_39 == V_32 )
V_7 = F_1 ( V_72 ,
F_6 ( V_72 ) ,
F_10 ( V_17 , 0x4522 ) ,
V_5 ) ;
else
V_7 = F_1 ( V_73 ,
F_6 ( V_73 ) ,
F_10 ( V_17 , 0x4311 ) ,
V_5 ) ;
if ( V_17 -> V_30 -> V_64 )
F_12 ( V_17 , V_5 ) ;
return V_7 ;
}
static int F_14 ( struct V_12 * V_13 ,
T_1 * V_74 )
{
T_1 V_5 ;
T_5 V_75 ;
int V_7 = F_13 ( V_13 , & V_5 ) ;
* V_74 = 0 ;
if ( 0 == V_7 ) {
V_75 = ( V_5 * ( ( 1 << 24 ) / 10 ) ) ;
if ( V_75 >= 8960 * 0x10000 )
* V_74 = 0xffff ;
else
* V_74 = V_75 / 8960 ;
}
return V_7 ;
}
static int F_15 ( struct V_12 * V_13 , T_5 * V_76 )
{
struct V_16 * V_17 = V_13 -> V_18 ;
if ( V_17 -> V_39 == V_27 )
* V_76 = F_10 ( V_17 , 0x4087 ) ;
else
* V_76 = F_10 ( V_17 , 0x4543 ) ;
return 0 ;
}
static int F_16 ( struct V_12 * V_13 , T_5 * V_77 )
{
return F_15 ( V_13 , V_77 ) ;
}
static int F_17 ( struct V_12 * V_13 )
{
struct V_40 * V_41 = & V_13 -> V_42 ;
struct V_16 * V_17 = V_13 -> V_18 ;
V_41 -> V_43 = V_17 -> V_44 ;
V_41 -> V_45 = V_17 -> V_39 ;
return 0 ;
}
static int F_18 ( struct V_12 * V_13 ,
struct V_78 * V_79 )
{
V_79 -> V_80 = 1000 ;
return 0 ;
}
static void F_19 ( struct V_12 * V_13 )
{
struct V_16 * V_17 = V_13 -> V_18 ;
F_20 ( V_17 ) ;
}
struct V_12 * F_21 ( const struct V_81 * V_30 ,
struct V_82 * V_83 )
{
struct V_16 * V_17 = NULL ;
int V_84 ;
V_84 = F_22 ( & V_17 , V_83 , V_30 -> V_85 ) ;
switch ( V_84 ) {
case 0 :
F_2 ( L_21 , V_9 ) ;
break;
case 1 :
F_2 ( L_22 , V_9 ) ;
break;
default:
F_2 ( L_23 , V_9 ) ;
break;
}
V_17 -> V_30 = V_30 ;
V_17 -> V_83 = V_83 ;
V_17 -> V_86 = V_87 ;
memcpy ( & V_17 -> V_88 . V_46 , & V_89 ,
sizeof( struct V_90 ) ) ;
V_17 -> V_88 . V_18 = V_17 ;
V_17 -> V_88 . V_46 . V_91 . V_49 = V_92 ;
if ( F_23 ( & V_17 -> V_88 ) != 0 ) {
F_24 ( V_93 L_24 ,
V_9 ) ;
goto error;
}
F_25 ( & V_17 -> V_88 , 1 ) ;
return & V_17 -> V_88 ;
error:
F_20 ( V_17 ) ;
return NULL ;
}
