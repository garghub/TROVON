static int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
int V_5 ;
T_1 V_6 [] = { V_3 , V_4 } ;
struct V_7 V_8 = {
. V_9 = V_2 -> V_10 -> V_11 , . V_12 = 0 ,
. V_6 = V_6 , . V_13 = 2 } ;
V_5 = F_2 ( V_2 -> V_14 , & V_8 , 1 ) ;
if ( F_3 ( V_5 != 1 ) ) {
F_4 ( V_15
L_1 ,
V_16 , V_3 , V_4 , V_5 ) ;
return - 1 ;
}
return 0 ;
}
static T_1 F_5 ( struct V_1 * V_2 , T_1 V_3 )
{
int V_5 ;
T_1 V_4 ;
struct V_7 V_8 [] = {
{ . V_9 = V_2 -> V_10 -> V_11 , . V_12 = 0 ,
. V_6 = & V_3 , . V_13 = 1 } ,
{ . V_9 = V_2 -> V_10 -> V_11 , . V_12 = V_17 ,
. V_6 = & V_4 , . V_13 = 1 } } ;
V_5 = F_2 ( V_2 -> V_14 , V_8 , 2 ) ;
if ( F_3 ( V_5 != 2 ) ) {
F_4 ( V_15 L_2 ,
V_16 , V_3 , V_5 ) ;
return 0 ;
}
return V_4 ;
}
static int F_6 ( struct V_1 * V_2 , int V_18 )
{
T_1 V_19 ;
V_19 = F_5 ( V_2 , 0x0C ) ;
switch ( V_18 ) {
case V_20 :
return - V_21 ;
case V_22 :
V_19 |= 0x01 ;
break;
case V_23 :
V_19 &= 0xfe ;
break;
default:
return - V_24 ;
}
return F_1 ( V_2 , 0x0C , V_19 ) ;
}
static int F_7 ( struct V_1 * V_2 ,
struct V_25 * V_26 )
{
T_1 V_19 ;
if ( ! ( F_5 ( V_2 , 0x0A ) & 0x20 ) )
return - V_27 ;
V_19 = F_5 ( V_2 , 0x01 ) ;
switch ( ( V_19 & 0x18 ) >> 3 ) {
case 0 :
V_26 -> V_28 = V_29 ;
break;
case 1 :
V_26 -> V_28 = V_30 ;
break;
case 2 :
V_26 -> V_28 = V_31 ;
break;
}
switch ( V_19 & 0x07 ) {
case 0 :
V_26 -> V_32 = V_33 ;
break;
case 1 :
V_26 -> V_32 = V_34 ;
break;
case 2 :
V_26 -> V_32 = V_35 ;
break;
case 3 :
V_26 -> V_32 = V_36 ;
break;
}
V_19 = F_5 ( V_2 , 0x02 ) ;
switch ( ( V_19 & 0x38 ) >> 3 ) {
case 0 :
V_26 -> V_37 = V_38 ;
break;
case 1 :
V_26 -> V_37 = V_39 ;
break;
case 2 :
V_26 -> V_37 = V_40 ;
break;
case 3 :
V_26 -> V_37 = V_41 ;
break;
case 4 :
V_26 -> V_37 = V_42 ;
break;
}
switch ( V_19 & 0x07 ) {
case 0 :
V_26 -> V_43 = V_38 ;
break;
case 1 :
V_26 -> V_43 = V_39 ;
break;
case 2 :
V_26 -> V_43 = V_40 ;
break;
case 3 :
V_26 -> V_43 = V_41 ;
break;
case 4 :
V_26 -> V_43 = V_42 ;
break;
}
V_19 = F_5 ( V_2 , 0x03 ) ;
switch ( ( V_19 & 0x0c ) >> 2 ) {
case 0 :
V_26 -> V_44 = V_45 ;
break;
case 1 :
V_26 -> V_44 = V_46 ;
break;
case 2 :
V_26 -> V_44 = V_47 ;
break;
case 3 :
V_26 -> V_44 = V_48 ;
break;
}
switch ( V_19 & 0x03 ) {
case 0 :
V_26 -> V_49 = V_50 ;
break;
case 1 :
V_26 -> V_49 = V_51 ;
break;
}
return 0 ;
}
static int F_8 ( struct V_52 * V_53 , int V_54 )
{
struct V_1 * V_2 = V_53 -> V_55 ;
T_1 V_19 ;
F_9 ( L_3 , V_16 , V_54 ) ;
V_19 = F_5 ( V_2 , 0x0D ) ;
if ( V_54 )
V_19 &= 0xfe ;
else
V_19 |= 0x01 ;
return F_1 ( V_2 , 0x0D , V_19 ) ;
}
static int F_10 ( struct V_52 * V_53 )
{
struct V_25 * V_26 = & V_53 -> V_56 ;
T_1 V_19 ;
struct V_1 * V_2 = V_53 -> V_55 ;
if ( V_53 -> V_57 . V_58 . V_59 ) {
V_53 -> V_57 . V_58 . V_59 ( V_53 ) ;
if ( V_53 -> V_57 . V_60 )
V_53 -> V_57 . V_60 ( V_53 , 0 ) ;
}
F_6 ( V_2 , V_26 -> V_18 ) ;
V_19 = F_5 ( V_2 , 0x0C ) & 0xcf ;
switch ( V_26 -> V_61 ) {
case 6000000 :
V_19 |= 0x20 ;
break;
case 7000000 :
V_19 |= 0x10 ;
break;
case 8000000 :
break;
default:
F_9 ( L_4 , V_16 ) ;
return - V_24 ;
}
F_1 ( V_2 , 0x0C , V_19 ) ;
V_26 -> V_43 = V_62 ;
if ( ( V_26 -> V_32 == V_63 ) ||
( V_26 -> V_28 == V_64 ) ||
( V_26 -> V_37 == V_62 ) ||
( V_26 -> V_43 == V_62 ) ||
( V_26 -> V_44 == V_65 ) ||
( V_26 -> V_49 == V_66 ) ) {
F_1 ( V_2 , 0x06 , 0x10 ) ;
F_1 ( V_2 , 0x07 , 0x9 ) ;
F_1 ( V_2 , 0x08 , 0xC1 ) ;
F_1 ( V_2 , 0x0B , F_5 ( V_2 , 0x0B )
& 0xfc ) ;
F_1 ( V_2 , 0x0C ,
( F_5 ( V_2 , 0x0C ) & 0xBF ) | 0x40 ) ;
F_1 ( V_2 , 0x00 , 0x01 ) ;
F_9 ( L_5 , V_16 ) ;
return 0 ;
}
switch ( V_26 -> V_28 ) {
case V_29 :
V_19 = 0x00 ;
break;
case V_30 :
V_19 = 0x08 ;
break;
case V_31 :
V_19 = 0x10 ;
break;
default:
F_9 ( L_6 , V_16 ) ;
return - V_24 ;
}
switch ( V_26 -> V_32 ) {
case V_33 :
break;
case V_34 :
V_19 |= 0x01 ;
break;
case V_35 :
V_19 |= 0x02 ;
break;
case V_36 :
V_19 |= 0x03 ;
break;
default:
F_9 ( L_7 , V_16 ) ;
return - V_24 ;
}
F_1 ( V_2 , 0x06 , V_19 ) ;
switch ( V_26 -> V_37 ) {
case V_67 :
case V_38 :
V_19 = 0x00 ;
break;
case V_39 :
V_19 = 0x08 ;
break;
case V_40 :
V_19 = 0x10 ;
break;
case V_41 :
V_19 = 0x18 ;
break;
case V_42 :
V_19 = 0x20 ;
break;
default:
F_9 ( L_8 , V_16 ) ;
return - V_24 ;
}
switch ( V_26 -> V_43 ) {
case V_67 :
case V_38 :
break;
case V_39 :
V_19 |= 0x01 ;
break;
case V_40 :
V_19 |= 0x02 ;
break;
case V_41 :
V_19 |= 0x03 ;
break;
case V_42 :
V_19 |= 0x04 ;
break;
default:
F_9 ( L_9 , V_16 ) ;
return - V_24 ;
}
F_1 ( V_2 , 0x07 , V_19 ) ;
switch ( V_26 -> V_44 ) {
case V_45 :
V_19 = 0x00 ;
break;
case V_46 :
V_19 = 0x04 ;
break;
case V_47 :
V_19 = 0x08 ;
break;
case V_48 :
V_19 = 0x0c ;
break;
default:
F_9 ( L_10 , V_16 ) ;
return - V_24 ;
}
switch ( V_26 -> V_49 ) {
case V_50 :
break;
case V_51 :
V_19 |= 0x1 ;
break;
default:
F_9 ( L_11 , V_16 ) ;
return - V_24 ;
}
F_1 ( V_2 , 0x08 , V_19 ) ;
F_1 ( V_2 , 0x0B ,
( F_5 ( V_2 , 0x0B ) & 0xfc ) | 0x02 ) ;
F_1 ( V_2 , 0x0C ,
( F_5 ( V_2 , 0x0C ) & 0xBF ) | 0x40 ) ;
F_1 ( V_2 , 0x00 , 0x01 ) ;
return 0 ;
}
static int F_11 ( struct V_52 * V_53 )
{
int V_68 ;
struct V_1 * V_2 = V_53 -> V_55 ;
F_1 ( V_2 , 0x00 , 0x02 ) ;
F_12 ( 10 ) ;
for ( V_68 = 0 ; V_68 < F_13 ( V_69 ) ; V_68 += 2 )
F_1 ( V_2 , V_69 [ V_68 ] , V_69 [ V_68 + 1 ] ) ;
F_1 ( V_2 , 0xf8 , ( V_2 -> V_10 -> V_70 << 1 )
& 0x02 ) ;
F_8 ( V_53 , 0 ) ;
return 0 ;
}
static int F_14 ( struct V_52 * V_53 , T_2 * V_71 )
{
struct V_1 * V_2 = V_53 -> V_55 ;
T_1 V_72 ;
T_1 V_73 ;
* V_71 = 0 ;
V_72 = F_5 ( V_2 , 0x0A ) ;
V_73 = F_5 ( V_2 , 0x23 ) ;
F_9 ( L_12
, V_16 , V_72 , V_73 ) ;
if ( V_72 & 0x10 ) {
* V_71 |= V_74 ;
* V_71 |= V_75 ;
* V_71 |= V_76 ;
}
if ( V_72 & 0x20 )
* V_71 |= V_77 ;
if ( V_73 < 0xf0 )
* V_71 |= V_78 ;
return 0 ;
}
static int F_15 ( struct V_52 * V_53 , T_3 * V_79 )
{
struct V_1 * V_2 = V_53 -> V_55 ;
if ( F_5 ( V_2 , 0xE4 ) & 0x02 ) {
* V_79 = ( F_5 ( V_2 , 0xDE ) & 0x7F ) << 7
| ( F_5 ( V_2 , 0xDF ) & 0x7F ) ;
} else {
* V_79 = ( F_5 ( V_2 , 0xDE ) & 0x7F ) << 7
| F_5 ( V_2 , 0xDF ) ;
}
return 0 ;
}
static int F_16 ( struct V_52 * V_53 ,
T_4 * V_80 )
{
struct V_1 * V_2 = V_53 -> V_55 ;
T_4 V_81 ;
V_81 = F_5 ( V_2 , 0x23 ) ;
* V_80 = ( V_81 << 8 ) | V_81 ;
return 0 ;
}
static int F_17 ( struct V_52 * V_53 , T_4 * V_82 )
{
struct V_1 * V_2 = V_53 -> V_55 ;
T_4 V_81 ;
if ( F_5 ( V_2 , 0xE4 ) & 0x02 ) {
V_81 = ( F_5 ( V_2 , 0xDE ) & 0x7F ) << 7
| ( F_5 ( V_2 , 0xDF ) & 0x7F ) ;
} else {
V_81 = ( F_5 ( V_2 , 0xDE ) & 0x7F ) << 8
| F_5 ( V_2 , 0xDF ) ;
}
* V_82 = ~ V_81 ;
return 0 ;
}
static int F_18 ( struct V_52 * V_53 , T_3 * V_83 )
{
struct V_1 * V_2 = V_53 -> V_55 ;
T_1 V_84 ;
V_84 = F_5 ( V_2 , 0xE3 ) ;
if ( V_2 -> V_85 < V_84 )
* V_83 = ( V_84 - V_2 -> V_85 ) ;
else
* V_83 = V_2 -> V_85 - V_84 ;
V_2 -> V_85 = V_84 ;
return 0 ;
}
static int F_19 ( struct V_52 * V_53 )
{
struct V_25 * V_86 = & V_53 -> V_56 ;
struct V_1 * V_2 = V_53 -> V_55 ;
T_1 V_87 = F_5 ( V_2 , 0x0C ) ;
V_86 -> V_18 = V_87 & 0x1 ? V_22 : V_23 ;
return F_7 ( V_2 , V_86 ) ;
}
static int F_20 ( struct V_52 * V_53 ,
struct V_88 * V_89 )
{
V_89 -> V_90 = 1000 ;
return 0 ;
}
static void F_21 ( struct V_52 * V_53 )
{
struct V_1 * V_2 = V_53 -> V_55 ;
F_22 ( V_2 ) ;
}
struct V_52 * F_23 ( const struct V_91 * V_10 ,
struct V_92 * V_14 )
{
struct V_1 * V_2 = NULL ;
V_2 = F_24 ( sizeof( struct V_1 ) , V_93 ) ;
if ( V_2 == NULL )
goto error;
V_2 -> V_10 = V_10 ;
V_2 -> V_14 = V_14 ;
if ( F_5 ( V_2 , 0x1f ) != 0x3 )
goto error;
memcpy ( & V_2 -> V_94 . V_57 , & V_95 ,
sizeof( struct V_96 ) ) ;
V_2 -> V_94 . V_55 = V_2 ;
return & V_2 -> V_94 ;
error:
F_22 ( V_2 ) ;
return NULL ;
}
