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
F_4 ( V_17 , 0x00b5 , V_19 ) ;
F_4 ( V_17 , 0x00b6 , V_20 ) ;
F_4 ( V_17 , 0x00b7 , V_21 ) ;
return 0 ;
}
static int F_5 ( struct V_12 * V_13 ,
enum V_26 V_27 )
{
struct V_16 * V_17 = V_13 -> V_18 ;
int V_6 ;
F_2 ( L_8 , V_9 , V_27 ) ;
switch ( V_27 ) {
case V_28 :
F_2 ( L_9 , V_9 ) ;
for ( V_6 = 0 ; V_6 < F_6 ( V_29 ) ; V_6 ++ )
F_4 ( V_17 ,
V_29 [ V_6 ] . V_30 ,
V_29 [ V_6 ] . V_11 ) ;
F_3 ( V_13 , V_17 -> V_31 . V_32 ) ;
break;
case V_33 :
F_2 ( L_10 , V_9 ) ;
for ( V_6 = 0 ; V_6 < F_6 ( V_34 ) ; V_6 ++ )
F_4 ( V_17 ,
V_34 [ V_6 ] . V_30 ,
V_34 [ V_6 ] . V_11 ) ;
F_3 ( V_13 , V_17 -> V_31 . V_35 ) ;
break;
case V_36 :
if ( V_37 ) {
F_2 ( L_11 , V_9 ) ;
for ( V_6 = 0 ; V_6 < F_6 ( V_38 ) ; V_6 ++ )
F_4 ( V_17 ,
V_38 [ V_6 ] . V_30 ,
V_38 [ V_6 ] . V_11 ) ;
F_3 ( V_13 , V_17 -> V_31 . V_35 ) ;
F_7 ( 100 ) ;
F_4 ( V_17 , 0x821a , 0x00 ) ;
} else {
F_2 ( L_12 , V_9 ) ;
for ( V_6 = 0 ; V_6 < F_6 ( V_39 ) ; V_6 ++ )
F_4 ( V_17 ,
V_39 [ V_6 ] . V_30 ,
V_39 [ V_6 ] . V_11 ) ;
F_3 ( V_13 , V_17 -> V_31 . V_35 ) ;
}
break;
default:
F_2 ( L_13 , V_9 ) ;
return - V_8 ;
}
V_17 -> V_40 = V_27 ;
return 0 ;
}
static int F_8 ( struct V_12 * V_13 )
{
struct V_41 * V_42 = & V_13 -> V_43 ;
struct V_16 * V_17 = V_13 -> V_18 ;
int V_7 = - V_8 ;
F_2 ( L_14 , V_9 , V_42 -> V_44 ) ;
if ( ( V_17 -> V_45 == V_42 -> V_44 ) &&
( V_17 -> V_40 == V_42 -> V_46 ) )
return 0 ;
if ( V_13 -> V_47 . V_48 . V_49 ) {
if ( V_13 -> V_47 . V_50 )
V_13 -> V_47 . V_50 ( V_13 , 1 ) ;
V_7 = V_13 -> V_47 . V_48 . V_49 ( V_13 ) ;
if ( V_13 -> V_47 . V_50 )
V_13 -> V_47 . V_50 ( V_13 , 0 ) ;
}
if ( V_7 < 0 )
return V_7 ;
if ( V_37 ) {
F_2 ( L_15 ,
V_9 ) ;
F_7 ( 250 ) ;
} else
F_7 ( 100 ) ;
F_5 ( V_13 , V_42 -> V_46 ) ;
V_17 -> V_45 = V_42 -> V_44 ;
return 0 ;
}
static int F_9 ( struct V_12 * V_13 , enum V_51 * V_52 )
{
struct V_16 * V_17 = V_13 -> V_18 ;
T_2 V_30 ;
T_3 V_53 = 0 ;
* V_52 = 0 ;
if ( V_17 -> V_40 == V_28 ) {
F_2 ( L_16 , V_9 ) ;
V_30 = F_10 ( V_17 , 0x0088 ) ;
if ( ( V_30 & 0x03 ) == 0x03 )
* V_52 |= V_54 | V_55 | V_56 ;
} else {
F_2 ( L_17 , V_9 ) ;
V_30 = F_10 ( V_17 , 0x0541 ) ;
if ( V_30 & 0x80 )
* V_52 |= V_56 ;
if ( V_30 & 0x20 )
* V_52 |= V_54 | V_55 ;
}
switch ( V_17 -> V_31 . V_57 ) {
case V_58 :
F_2 ( L_18 , V_9 ) ;
if ( * V_52 & V_56 )
* V_52 |= V_59 | V_60 ;
break;
case V_61 :
F_2 ( L_19 , V_9 ) ;
if ( V_13 -> V_47 . V_48 . V_62 ) {
if ( V_13 -> V_47 . V_50 )
V_13 -> V_47 . V_50 ( V_13 , 1 ) ;
V_13 -> V_47 . V_48 . V_62 ( V_13 , & V_53 ) ;
if ( V_13 -> V_47 . V_50 )
V_13 -> V_47 . V_50 ( V_13 , 0 ) ;
}
if ( V_53 )
* V_52 |= V_59 | V_60 ;
break;
}
V_17 -> V_51 = * V_52 ;
if ( * V_52 & V_54 )
F_11 ( V_17 , - 1 ) ;
else
F_11 ( V_17 , 0 ) ;
F_2 ( L_20 , V_9 , * V_52 ) ;
return 0 ;
}
static int F_12 ( struct V_16 * V_17 , const T_1 * V_5 )
{
struct V_63 * V_64 = V_17 -> V_31 . V_65 ;
int V_66 ;
T_1 V_67 ;
if ( ! V_64 )
return 0 ;
if ( 0 == ( V_17 -> V_51 & V_54 ) )
return F_11 ( V_17 , 0 ) ;
else if ( V_17 -> V_40 == V_36 )
V_67 = V_64 -> V_68 ;
else if ( V_17 -> V_40 == V_33 )
V_67 = V_64 -> V_69 ;
else
V_67 = V_64 -> V_70 ;
if ( * V_5 >= V_67 )
V_66 = 2 ;
else
V_66 = 1 ;
if ( ( V_17 -> V_71 ) &&
( ( ( V_67 < * V_5 ) ? ( * V_5 - V_67 ) : ( V_67 - * V_5 ) ) <= 10 ) )
return 0 ;
return F_11 ( V_17 , V_66 ) ;
}
static int F_13 ( struct V_12 * V_13 , T_1 * V_5 )
{
struct V_16 * V_17 = V_13 -> V_18 ;
int V_7 = - V_8 ;
F_2 ( L_1 , V_9 ) ;
if ( V_17 -> V_40 == V_36 )
V_7 = F_1 ( V_72 ,
F_6 ( V_72 ) ,
F_10 ( V_17 , 0x0522 ) ,
V_5 ) ;
else if ( V_17 -> V_40 == V_33 )
V_7 = F_1 ( V_73 ,
F_6 ( V_73 ) ,
F_10 ( V_17 , 0x0522 ) ,
V_5 ) ;
else
V_7 = F_1 ( V_74 ,
F_6 ( V_74 ) ,
F_10 ( V_17 , 0x0311 ) ,
V_5 ) ;
if ( V_17 -> V_31 . V_65 )
F_12 ( V_17 , V_5 ) ;
return V_7 ;
}
static int F_14 ( struct V_12 * V_13 ,
T_1 * V_75 )
{
T_1 V_5 ;
T_3 V_76 ;
int V_7 = F_13 ( V_13 , & V_5 ) ;
* V_75 = 0 ;
if ( 0 == V_7 ) {
V_76 = ( V_5 * ( ( 1 << 24 ) / 10 ) ) ;
if ( V_76 >= 8960 * 0x10000 )
* V_75 = 0xffff ;
else
* V_75 = V_76 / 8960 ;
}
return V_7 ;
}
static int F_15 ( struct V_12 * V_13 , T_3 * V_77 )
{
struct V_16 * V_17 = V_13 -> V_18 ;
if ( V_17 -> V_40 == V_28 )
* V_77 = F_10 ( V_17 , 0x0087 ) ;
else
* V_77 = F_10 ( V_17 , 0x0543 ) ;
return 0 ;
}
static int F_16 ( struct V_12 * V_13 , T_3 * V_78 )
{
return F_15 ( V_13 , V_78 ) ;
}
static int F_17 ( struct V_12 * V_13 ,
struct V_41 * V_42 )
{
struct V_16 * V_17 = V_13 -> V_18 ;
V_42 -> V_44 = V_17 -> V_45 ;
V_42 -> V_46 = V_17 -> V_40 ;
return 0 ;
}
static int F_18 ( struct V_12 * V_13 ,
struct V_79 * V_80 )
{
V_80 -> V_81 = 1000 ;
return 0 ;
}
static void F_19 ( struct V_12 * V_13 )
{
struct V_16 * V_17 = V_13 -> V_18 ;
F_20 ( V_17 ) ;
}
struct V_12 * F_21 ( const struct V_82 * V_31 ,
struct V_83 * V_84 )
{
struct V_16 * V_17 = NULL ;
int V_85 ;
V_85 = F_22 ( & V_17 , V_84 , V_31 -> V_86 ) ;
switch ( V_85 ) {
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
V_17 -> V_31 = * V_31 ;
V_17 -> V_84 = V_84 ;
V_17 -> V_87 = V_88 ;
memcpy ( & V_17 -> V_89 . V_47 , & V_90 ,
sizeof( struct V_91 ) ) ;
V_17 -> V_89 . V_18 = V_17 ;
V_17 -> V_89 . V_47 . V_92 . V_50 = V_93 ;
if ( F_23 ( & V_17 -> V_89 ) != 0 ) {
F_24 ( V_94 L_24 ,
V_9 ) ;
goto error;
}
F_25 ( & V_17 -> V_89 , 1 ) ;
return & V_17 -> V_89 ;
error:
F_20 ( V_17 ) ;
return NULL ;
}
