int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_2 V_4 )
{
int V_5 ;
T_2 V_6 [] = { ( V_3 >> 8 ) | 0x80 , V_3 & 0xff , V_4 } ;
struct V_7 V_8 = { . V_9 = V_2 -> V_10 -> V_11 ,
. V_12 = 0 , . V_6 = V_6 , . V_13 = 3 } ;
V_5 = F_2 ( V_2 -> V_14 , & V_8 , 1 ) ;
if ( V_5 != 1 )
F_3 ( L_1
L_2 , V_15 , V_3 , V_4 , V_5 ) ;
return ( V_5 != 1 ) ? - 1 : 0 ;
}
T_2 F_4 ( struct V_1 * V_2 , T_1 V_3 )
{
int V_5 ;
T_2 V_16 [] = { ( V_3 >> 8 ) | 0x40 , V_3 & 0xff } ;
T_2 V_17 [] = { 0 } ;
struct V_7 V_8 [] = {
{ . V_9 = V_2 -> V_10 -> V_11 , . V_12 = 0 ,
. V_6 = V_16 , . V_13 = 2 } ,
{ . V_9 = V_2 -> V_10 -> V_11 , . V_12 = V_18 ,
. V_6 = V_17 , . V_13 = 1 } } ;
V_5 = F_2 ( V_2 -> V_14 , V_8 , 2 ) ;
if ( V_5 != 2 )
F_3 ( V_19 L_3 ,
V_15 , V_5 ) ;
return V_17 [ 0 ] ;
}
static int F_5 ( struct V_20 * V_21 , int V_22 )
{
struct V_1 * V_2 = V_21 -> V_23 ;
F_6 ( L_4 , V_15 , V_22 ) ;
if ( V_2 -> V_24 == V_25 ) {
return 0 ;
}
if ( V_22 )
return F_1 ( V_2 , 0x106 , 1 ) ;
else
return F_1 ( V_2 , 0x106 , 0 ) ;
}
static int F_7 ( struct V_26 * V_27 , int V_28 , int V_29 ,
T_1 * V_30 )
{
int V_31 , V_5 = - V_32 ;
F_6 ( L_5 , V_15 ) ;
for ( V_31 = 0 ; V_31 < V_28 ; V_31 ++ ) {
if ( V_29 < V_27 [ V_31 ] . V_33 ) {
* V_30 = V_27 [ V_31 ] . V_4 ;
V_5 = 0 ;
break;
}
}
F_6 ( L_6 , V_15 , * V_30 ) ;
return V_5 ;
}
static int F_8 ( struct V_20 * V_21 , enum V_34 V_35 )
{
struct V_1 * V_2 = V_21 -> V_23 ;
T_2 V_36 , V_37 , V_38 ;
char * V_39 ;
switch ( V_35 ) {
case V_40 :
V_39 = L_7 ;
V_36 = 0x00 ;
V_37 = 0x3d ;
V_38 = 0xa0 ;
break;
case V_41 :
V_39 = L_8 ;
V_36 = 0x00 ;
V_37 = 0x4b ;
V_38 = 0xd9 ;
break;
case V_42 :
V_39 = L_9 ;
V_36 = 0xfb ;
V_37 = 0x8e ;
V_38 = 0x39 ;
break;
default:
F_6 ( L_10 , V_15 ) ;
return - V_32 ;
}
F_6 ( L_11 , V_15 , V_39 ) ;
F_1 ( V_2 , 0x80b5 , V_36 ) ;
F_1 ( V_2 , 0x80b6 , V_37 ) ;
F_1 ( V_2 , 0x80b7 , V_38 ) ;
return 0 ;
}
static int F_9 ( struct V_20 * V_21 ,
T_3 V_43 )
{
struct V_1 * V_2 = V_21 -> V_23 ;
int V_31 ;
F_6 ( L_12 , V_15 , V_43 ) ;
switch ( V_43 ) {
case V_44 :
F_6 ( L_13 , V_15 ) ;
for ( V_31 = 0 ; V_31 < F_10 ( V_45 ) ; V_31 ++ )
F_1 ( V_2 ,
V_45 [ V_31 ] . V_3 ,
V_45 [ V_31 ] . V_4 ) ;
F_8 ( V_21 , V_2 -> V_10 -> V_46 ) ;
break;
case V_47 :
F_6 ( L_14 , V_15 ) ;
for ( V_31 = 0 ; V_31 < F_10 ( V_48 ) ; V_31 ++ )
F_1 ( V_2 ,
V_48 [ V_31 ] . V_3 ,
V_48 [ V_31 ] . V_4 ) ;
F_8 ( V_21 , V_2 -> V_10 -> V_49 ) ;
break;
case V_50 :
F_6 ( L_15 , V_15 ) ;
for ( V_31 = 0 ; V_31 < F_10 ( V_51 ) ; V_31 ++ )
F_1 ( V_2 ,
V_51 [ V_31 ] . V_3 ,
V_51 [ V_31 ] . V_4 ) ;
F_8 ( V_21 , V_2 -> V_10 -> V_49 ) ;
break;
default:
F_6 ( L_16 , V_15 ) ;
return - V_32 ;
}
V_2 -> V_52 = V_43 ;
return 0 ;
}
static int F_11 ( struct V_20 * V_21 ,
struct V_53 * V_54 )
{
struct V_1 * V_2 = V_21 -> V_23 ;
int V_5 = - V_32 ;
F_6 ( L_17 , V_15 , V_54 -> V_55 ) ;
if ( ( V_2 -> V_56 == V_54 -> V_55 ) &&
( V_2 -> V_52 == V_54 -> V_57 . V_58 . V_59 ) )
return 0 ;
F_9 ( V_21 , V_54 -> V_57 . V_58 . V_59 ) ;
F_12 ( 100 ) ;
if ( V_21 -> V_60 . V_61 . V_62 ) {
if ( V_21 -> V_60 . V_63 )
V_21 -> V_60 . V_63 ( V_21 , 1 ) ;
V_5 = V_21 -> V_60 . V_61 . V_62 ( V_21 , V_54 ) ;
if ( V_21 -> V_60 . V_63 )
V_21 -> V_60 . V_63 ( V_21 , 0 ) ;
}
if ( V_5 < 0 )
return V_5 ;
V_2 -> V_56 = V_54 -> V_55 ;
return 0 ;
}
int F_13 ( struct V_20 * V_21 )
{
struct V_1 * V_2 = V_21 -> V_23 ;
F_6 ( L_5 , V_15 ) ;
V_2 -> V_24 = V_64 ;
V_2 -> V_56 = 0 ;
F_1 ( V_2 , 0xa4 , 1 << 5 ) ;
F_5 ( V_21 , 1 ) ;
return 0 ;
}
static int F_14 ( struct V_1 * V_2 , int V_65 )
{
struct V_66 * V_67 = V_2 -> V_10 -> V_68 ;
T_2 V_33 ;
if ( ! V_67 || ! V_67 -> V_69 ||
! V_67 -> V_70 || ! V_67 -> V_71 )
return 0 ;
V_33 = F_4 ( V_2 , 0x4000 |
( V_67 -> V_69 & ~ 0xc000 ) ) ;
if ( V_65 ) {
V_33 &= ~ ( ( V_67 -> V_70 >> 8 ) & 0xff ) ;
V_33 |= ( V_67 -> V_70 & 0xff ) ;
} else {
V_33 &= ~ ( ( V_67 -> V_71 >> 8 ) & 0xff ) ;
V_33 |= ( V_67 -> V_71 & 0xff ) ;
}
return F_1 ( V_2 , 0x8000 |
( V_67 -> V_69 & ~ 0xc000 ) , V_33 ) ;
}
static int F_15 ( struct V_1 * V_2 , int V_72 )
{
struct V_66 * V_67 = V_2 -> V_10 -> V_68 ;
int V_31 , V_5 = 0 ;
if ( ! V_67 || ! V_67 -> V_73 ||
! V_67 -> V_74 || ! V_67 -> V_75 )
return 0 ;
if ( V_72 < 0 ) {
if ( V_2 -> V_76 )
return 0 ;
else
V_72 *= - 1 ;
}
if ( V_2 -> V_76 != V_72 ) {
T_2 V_33 ;
F_6 ( L_18 , V_15 , V_72 ) ;
F_14 ( V_2 , 1 ) ;
V_33 = F_4 ( V_2 , 0x4000 |
( V_67 -> V_73 & ~ 0xc000 ) ) ;
for ( V_31 = 0 ; V_31 < V_67 -> V_74 ; V_31 ++ )
V_33 &= ~ V_67 -> V_75 [ V_31 ] ;
if ( V_72 < V_67 -> V_74 )
V_33 |= V_67 -> V_75 [ V_72 ] ;
else if ( V_67 -> V_74 )
V_33 |=
V_67 -> V_75 [ V_67 -> V_74 - 1 ] ;
V_5 = F_1 ( V_2 , 0x8000 |
( V_67 -> V_73 & ~ 0xc000 ) , V_33 ) ;
if ( V_5 < 0 )
return V_5 ;
V_2 -> V_76 = V_72 ;
if ( V_72 == 0 )
F_14 ( V_2 , 0 ) ;
}
return 0 ;
}
int F_16 ( struct V_20 * V_21 )
{
struct V_1 * V_2 = V_21 -> V_23 ;
F_6 ( L_5 , V_15 ) ;
if ( V_2 -> V_24 == V_25 ) {
return 0 ;
}
F_15 ( V_2 , 0 ) ;
F_1 ( V_2 , 0xa4 , 1 << 5 ) ;
V_2 -> V_56 = 0 ;
return 0 ;
}
static int F_17 ( struct V_20 * V_21 , T_4 * V_77 )
{
struct V_1 * V_2 = V_21 -> V_23 ;
T_2 V_3 ;
T_5 V_78 = 0 ;
* V_77 = 0 ;
if ( V_2 -> V_52 == V_44 ) {
F_6 ( L_19 , V_15 ) ;
V_3 = F_4 ( V_2 , 0x4088 ) ;
if ( ( V_3 & 0x03 ) == 0x03 )
* V_77 |= V_79 | V_80 | V_81 ;
} else {
F_6 ( L_20 , V_15 ) ;
V_3 = F_4 ( V_2 , 0x4541 ) ;
if ( V_3 & 0x80 )
* V_77 |= V_81 ;
if ( V_3 & 0x20 )
* V_77 |= V_79 | V_80 ;
}
switch ( V_2 -> V_10 -> V_82 ) {
case V_83 :
F_6 ( L_21 , V_15 ) ;
if ( * V_77 & V_81 )
* V_77 |= V_84 | V_85 ;
break;
case V_86 :
F_6 ( L_22 , V_15 ) ;
if ( V_21 -> V_60 . V_61 . V_87 ) {
if ( V_21 -> V_60 . V_63 )
V_21 -> V_60 . V_63 ( V_21 , 1 ) ;
V_21 -> V_60 . V_61 . V_87 ( V_21 , & V_78 ) ;
if ( V_21 -> V_60 . V_63 )
V_21 -> V_60 . V_63 ( V_21 , 0 ) ;
}
if ( V_78 )
* V_77 |= V_84 | V_85 ;
break;
}
V_2 -> V_88 = * V_77 ;
if ( * V_77 & V_79 )
F_15 ( V_2 , - 1 ) ;
else
F_15 ( V_2 , 0 ) ;
F_6 ( L_23 , V_15 , * V_77 ) ;
return 0 ;
}
static int F_18 ( struct V_1 * V_2 , const T_1 * V_30 )
{
struct V_66 * V_67 = V_2 -> V_10 -> V_68 ;
int V_72 ;
T_1 V_89 ;
if ( ! V_67 )
return 0 ;
if ( 0 == ( V_2 -> V_88 & V_79 ) )
return F_15 ( V_2 , 0 ) ;
else if ( V_2 -> V_52 == V_50 )
V_89 = V_67 -> V_90 ;
else if ( V_2 -> V_52 == V_47 )
V_89 = V_67 -> V_91 ;
else
V_89 = V_67 -> V_92 ;
if ( * V_30 >= V_89 )
V_72 = 2 ;
else
V_72 = 1 ;
if ( ( V_2 -> V_76 ) &&
( ( ( V_89 < * V_30 ) ? ( * V_30 - V_89 ) : ( V_89 - * V_30 ) ) <= 10 ) )
return 0 ;
return F_15 ( V_2 , V_72 ) ;
}
static int F_19 ( struct V_20 * V_21 , T_1 * V_30 )
{
struct V_1 * V_2 = V_21 -> V_23 ;
int V_5 = - V_32 ;
F_6 ( L_5 , V_15 ) ;
if ( V_2 -> V_52 == V_50 )
V_5 = F_7 ( V_93 ,
F_10 ( V_93 ) ,
F_4 ( V_2 , 0x4522 ) ,
V_30 ) ;
else if ( V_2 -> V_52 == V_47 )
V_5 = F_7 ( V_94 ,
F_10 ( V_94 ) ,
F_4 ( V_2 , 0x4522 ) ,
V_30 ) ;
else
V_5 = F_7 ( V_95 ,
F_10 ( V_95 ) ,
F_4 ( V_2 , 0x4311 ) ,
V_30 ) ;
if ( V_2 -> V_10 -> V_68 )
F_18 ( V_2 , V_30 ) ;
return V_5 ;
}
static int F_20 ( struct V_20 * V_21 ,
T_1 * V_96 )
{
return F_19 ( V_21 , V_96 ) ;
}
static int F_21 ( struct V_20 * V_21 , T_5 * V_97 )
{
struct V_1 * V_2 = V_21 -> V_23 ;
if ( V_2 -> V_52 == V_44 )
* V_97 = F_4 ( V_2 , 0x4087 ) ;
else
* V_97 = F_4 ( V_2 , 0x4543 ) ;
return 0 ;
}
static int F_22 ( struct V_20 * V_21 , T_5 * V_98 )
{
return F_21 ( V_21 , V_98 ) ;
}
static int F_23 ( struct V_20 * V_21 ,
struct V_53 * V_54 )
{
struct V_1 * V_2 = V_21 -> V_23 ;
V_54 -> V_55 = V_2 -> V_56 ;
V_54 -> V_57 . V_58 . V_59 = V_2 -> V_52 ;
return 0 ;
}
static int F_24 ( struct V_20 * V_21 ,
struct V_99 * V_100 )
{
V_100 -> V_101 = 1000 ;
return 0 ;
}
int F_25 ( struct V_1 * * V_2 , struct V_102 * V_14 ,
T_2 V_103 )
{
int V_5 ;
F_26 ( & V_104 ) ;
V_5 = F_27 ( struct V_1 , ( * V_2 ) ,
V_105 ,
V_14 , V_103 , L_24 ) ;
F_28 ( & V_104 ) ;
return V_5 ;
}
void F_29 ( struct V_1 * V_2 )
{
F_26 ( & V_104 ) ;
if ( V_2 != NULL )
F_30 ( V_2 ) ;
F_28 ( & V_104 ) ;
}
static void F_31 ( struct V_20 * V_21 )
{
struct V_1 * V_2 = V_21 -> V_23 ;
F_29 ( V_2 ) ;
}
struct V_20 * F_32 ( const struct V_106 * V_10 ,
struct V_102 * V_14 )
{
struct V_1 * V_2 = NULL ;
int V_107 ;
V_107 = F_25 ( & V_2 , V_14 , V_10 -> V_11 ) ;
switch ( V_107 ) {
case 0 :
F_6 ( L_25 , V_15 ) ;
break;
case 1 :
F_6 ( L_26 , V_15 ) ;
break;
default:
F_6 ( L_27 , V_15 ) ;
break;
}
V_2 -> V_10 = V_10 ;
V_2 -> V_14 = V_14 ;
V_2 -> V_24 = V_64 ;
memcpy ( & V_2 -> V_108 . V_60 , & V_109 ,
sizeof( struct V_110 ) ) ;
V_2 -> V_108 . V_23 = V_2 ;
if ( F_13 ( & V_2 -> V_108 ) != 0 ) {
F_3 ( V_19 L_28 ,
V_15 ) ;
goto error;
}
F_5 ( & V_2 -> V_108 , 1 ) ;
return & V_2 -> V_108 ;
error:
F_29 ( V_2 ) ;
return NULL ;
}
