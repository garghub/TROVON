static char * F_1 ( struct V_1 * V_2 , int V_3 ,
int V_4 )
{
return F_2 ( & V_2 -> V_5 , V_6 , V_3 ,
V_4 ) ;
}
void F_3 ( struct V_1 * V_2 )
{
const unsigned char * V_7 = V_2 -> V_5 . V_8 ;
switch ( V_7 [ 0 ] & 0xf0 ) {
case V_9 :
case V_10 :
case V_11 :
break;
default:
return;
}
switch ( V_7 [ 0 ] ) {
case V_9 | V_12 :
case V_9 | V_13 :
break;
case V_10 | V_12 :
case V_10 | V_13 :
break;
case V_11 | V_12 :
case V_11 | V_14 :
if ( memcmp ( V_7 + 1 , V_15 , sizeof( V_15 ) ) == 0 ) {
switch ( V_7 [ 5 ] ) {
case V_16 :
break;
case V_17 : {
short V_18 =
( ( int ) V_7 [ 7 ] << 12 ) | ( ( int ) V_7 [ 8 ]
<< 8 ) |
( ( int ) V_7 [ 9 ] << 4 ) | ( int ) V_7 [ 10 ] ;
if ( V_7 [ 6 ] == V_19 )
V_2 -> V_20 = V_18 ;
break;
}
case V_21 :
break;
case V_22 :
break;
case V_23 :
F_4 ( V_2 -> V_5 . V_24 ,
L_1 ,
V_7 [ 5 ] ) ;
break;
default:
F_4 ( V_2 -> V_5 . V_24 ,
L_2 ,
V_7 [ 5 ] ) ;
}
} else
if ( memcmp
( V_7 , V_25 ,
sizeof( V_25 ) ) == 0 ) {
V_2 -> V_26 =
V_7 [ 13 ] * 100 + V_7 [ 14 ] * 10 + V_7 [ 15 ] ;
V_2 -> V_27 =
( ( int ) V_7 [ 8 ] << 16 ) | ( ( int ) V_7 [ 9 ] << 8 ) | ( int )
V_7 [ 10 ] ;
F_5 ( V_2 ) ;
} else
F_4 ( V_2 -> V_5 . V_24 , L_3 ) ;
break;
case V_28 :
break;
default:
F_4 ( V_2 -> V_5 . V_24 , L_4 ,
V_7 [ 0 ] ) ;
}
}
void F_6 ( struct V_1 * V_2 , int V_29 ,
T_1 V_18 )
{
F_7 ( & V_2 -> V_5 , V_29 , V_18 ) ;
}
static int F_8 ( struct V_1 * V_2 , int V_18 ,
int V_3 )
{
char * V_30 ;
static const int V_4 = 5 ;
V_30 = F_1 ( V_2 , V_17 , V_4 ) ;
if ( ! V_30 )
return - V_31 ;
V_30 [ V_32 ] = V_3 ;
V_30 [ V_32 + 1 ] = ( V_18 >> 12 ) & 0x0f ;
V_30 [ V_32 + 2 ] = ( V_18 >> 8 ) & 0x0f ;
V_30 [ V_32 + 3 ] = ( V_18 >> 4 ) & 0x0f ;
V_30 [ V_32 + 4 ] = ( V_18 ) & 0x0f ;
F_9 ( & V_2 -> V_5 , V_30 , V_4 ) ;
F_10 ( V_30 ) ;
return 0 ;
}
static T_2 F_11 ( struct V_33 * V_34 ,
struct V_35 * V_36 , char * V_7 )
{
struct V_37 * V_38 = F_12 ( V_34 ) ;
struct V_1 * V_2 = F_13 ( V_38 ) ;
return sprintf ( V_7 , L_5 , V_2 -> V_39 ) ;
}
static T_2 F_14 ( struct V_33 * V_34 ,
struct V_35 * V_36 ,
char * V_7 )
{
struct V_37 * V_38 = F_12 ( V_34 ) ;
struct V_1 * V_2 = F_13 ( V_38 ) ;
return sprintf ( V_7 , L_6 , V_2 -> V_26 / 100 ,
V_2 -> V_26 % 100 ) ;
}
static T_2 F_15 ( struct V_33 * V_34 ,
struct V_35 * V_36 , char * V_7 )
{
struct V_37 * V_38 = F_12 ( V_34 ) ;
struct V_1 * V_2 = F_13 ( V_38 ) ;
return sprintf ( V_7 , L_5 , V_2 -> V_27 ) ;
}
static void F_16 ( struct V_1 * V_2 )
{
F_17 ( V_2 -> V_40 , V_41 ) ;
F_18 ( & V_2 -> V_42 , V_43 , V_44 ,
( unsigned long ) V_2 ) ;
}
static void V_44 ( unsigned long V_45 )
{
struct V_1 * V_2 = (struct V_1 * ) V_45 ;
struct V_46 * V_5 = & V_2 -> V_5 ;
F_17 ( V_2 -> V_40 , V_47 ) ;
F_19 ( V_5 ) ;
}
static void F_5 ( struct V_1 * V_2 )
{
F_17 ( V_2 -> V_40 , V_48 ) ;
F_20 ( & V_2 -> V_49 ) ;
}
static void F_21 ( struct V_50 * V_51 )
{
struct V_1 * V_2 =
F_22 ( V_51 , struct V_1 , V_49 ) ;
struct V_46 * V_5 = & V_2 -> V_5 ;
F_17 ( V_2 -> V_40 , V_52 ) ;
F_23 ( & V_2 -> V_5 , & V_2 -> V_39 ) ;
F_24 ( V_5 ) ;
}
static int F_25 ( struct V_53 * V_54 ,
struct V_55 * V_56 )
{
V_56 -> type = V_57 ;
V_56 -> V_58 = 1 ;
V_56 -> V_18 . integer . V_59 = 0 ;
V_56 -> V_18 . integer . V_60 = 65535 ;
return 0 ;
}
static int F_26 ( struct V_53 * V_54 ,
struct V_61 * V_62 )
{
struct V_63 * V_64 = F_27 ( V_54 ) ;
struct V_1 * V_2 = (struct V_1 * ) V_64 -> V_5 ;
V_62 -> V_18 . integer . V_18 [ 0 ] = V_2 -> V_20 ;
return 0 ;
}
static int F_28 ( struct V_53 * V_54 ,
struct V_61 * V_62 )
{
struct V_63 * V_64 = F_27 ( V_54 ) ;
struct V_1 * V_2 = (struct V_1 * ) V_64 -> V_5 ;
if ( V_62 -> V_18 . integer . V_18 [ 0 ] == V_2 -> V_20 )
return 0 ;
V_2 -> V_20 = V_62 -> V_18 . integer . V_18 [ 0 ] ;
F_8 ( V_2 , V_62 -> V_18 . integer . V_18 [ 0 ] ,
V_19 ) ;
return 1 ;
}
static void F_29 ( struct V_37 * V_38 )
{
struct V_1 * V_2 = F_13 ( V_38 ) ;
if ( V_2 == NULL )
return;
F_30 ( & V_2 -> V_5 ) ;
F_31 ( & V_2 -> V_42 ) ;
F_32 ( & V_2 -> V_49 ) ;
}
static int F_33 ( struct V_33 * V_34 )
{
int V_65 ;
F_34 ( F_35 ( V_34 , & V_66 ) ) ;
F_34 ( F_35 ( V_34 , & V_67 ) ) ;
F_34 ( F_35 ( V_34 , & V_68 ) ) ;
return 0 ;
}
static int F_36 ( struct V_37 * V_38 ,
struct V_1 * V_2 )
{
int V_65 ;
struct V_46 * V_5 = & V_2 -> V_5 ;
F_37 ( & V_2 -> V_42 ) ;
F_38 ( & V_2 -> V_49 , F_21 ) ;
if ( ( V_38 == NULL ) || ( V_2 == NULL ) )
return - V_69 ;
V_65 = F_33 ( & V_38 -> V_34 ) ;
if ( V_65 < 0 )
return V_65 ;
V_65 = F_39 ( V_5 ) ;
if ( V_65 < 0 )
return V_65 ;
V_65 = F_40 ( V_5 ) ;
if ( V_65 < 0 )
return V_65 ;
V_65 = F_41 ( V_5 , & V_70 ) ;
if ( V_65 < 0 )
return V_65 ;
V_65 = F_42 ( V_5 -> V_71 ,
F_43 ( & V_72 , V_5 -> V_64 ) ) ;
if ( V_65 < 0 )
return V_65 ;
if ( V_2 -> V_5 . V_73 -> V_74 & V_75 ) {
V_2 -> V_20 = V_76 ;
F_16 ( V_2 ) ;
}
return 0 ;
}
int F_44 ( struct V_37 * V_38 , struct V_1 * V_2 )
{
int V_65 = F_36 ( V_38 , V_2 ) ;
if ( V_65 < 0 )
F_29 ( V_38 ) ;
return V_65 ;
}
void F_45 ( struct V_37 * V_38 )
{
struct V_1 * V_2 ;
if ( V_38 == NULL )
return;
V_2 = F_13 ( V_38 ) ;
if ( V_2 != NULL ) {
struct V_63 * V_64 = V_2 -> V_5 . V_64 ;
struct V_33 * V_34 = & V_38 -> V_34 ;
if ( V_64 != NULL )
F_46 ( V_64 ) ;
if ( V_34 != NULL ) {
F_47 ( V_34 , & V_66 ) ;
F_47 ( V_34 , & V_67 ) ;
F_47 ( V_34 , & V_68 ) ;
}
}
F_29 ( V_38 ) ;
}
