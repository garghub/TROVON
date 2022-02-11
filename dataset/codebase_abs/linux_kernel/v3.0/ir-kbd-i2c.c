static int F_1 ( struct V_1 * V_2 , T_1 * V_3 , T_1 * V_4 ,
int V_5 , int V_6 )
{
unsigned char V_7 [ 6 ] ;
int V_8 , V_9 , V_10 , V_11 , V_12 , V_13 ;
if ( V_5 != F_2 ( V_2 -> V_14 , V_7 , V_5 ) )
return - V_15 ;
V_8 = ( V_7 [ V_6 ] >> 7 ) & 1 ;
V_9 = ( V_7 [ V_6 ] >> 6 ) & 1 ;
V_10 = ( V_7 [ V_6 ] >> 5 ) & 1 ;
V_11 = V_7 [ V_6 ] & 0x1f ;
V_12 = ( V_7 [ V_6 + 1 ] >> 2 ) & 0x3f ;
if ( ! V_8 )
return 0 ;
V_13 = ( V_8 << 12 ) | ( V_10 << 11 ) | ( V_11 << 6 ) | V_12 ;
if ( ( V_13 & 0x1fff ) == 0x1fff )
return 0 ;
if ( ! V_9 )
V_12 += 64 ;
F_3 ( 1 , L_1 ,
V_8 , V_9 , V_10 , V_11 , V_12 ) ;
* V_3 = ( V_11 << 8 ) | V_12 ;
* V_4 = V_13 ;
return 1 ;
}
static int F_4 ( struct V_1 * V_2 , T_1 * V_3 , T_1 * V_4 )
{
return F_1 ( V_2 , V_3 , V_4 , 3 , 0 ) ;
}
static int F_5 ( struct V_1 * V_2 , T_1 * V_3 , T_1 * V_4 )
{
int V_16 ;
unsigned char V_7 [ 1 ] = { 0 } ;
V_16 = F_6 ( V_2 -> V_14 , V_7 , 1 ) ;
if ( V_16 != 1 )
return ( V_16 < 0 ) ? V_16 : - V_17 ;
return F_1 ( V_2 , V_3 , V_4 , 6 , 3 ) ;
}
static int F_7 ( struct V_1 * V_2 , T_1 * V_3 , T_1 * V_4 )
{
unsigned char V_18 ;
if ( 1 != F_2 ( V_2 -> V_14 , & V_18 , 1 ) ) {
F_3 ( 1 , L_2 ) ;
return - V_15 ;
}
* V_3 = V_18 ;
* V_4 = V_18 ;
return 1 ;
}
static int F_8 ( struct V_1 * V_2 , T_1 * V_3 , T_1 * V_4 )
{
unsigned char V_7 [ 4 ] ;
if ( 4 != F_2 ( V_2 -> V_14 , V_7 , 4 ) ) {
F_3 ( 1 , L_2 ) ;
return - V_15 ;
}
if( V_7 [ 0 ] != 0 || V_7 [ 1 ] != 0 || V_7 [ 2 ] != 0 || V_7 [ 3 ] != 0 )
F_3 ( 2 , L_3 , V_19 ,
V_7 [ 0 ] , V_7 [ 1 ] , V_7 [ 2 ] , V_7 [ 3 ] ) ;
if( V_7 [ 0 ] != 0x1 || V_7 [ 1 ] != 0xfe )
return 0 ;
* V_3 = V_7 [ 2 ] ;
* V_4 = ( V_7 [ 2 ] << 8 ) | V_7 [ 3 ] ;
return 1 ;
}
static int F_9 ( struct V_1 * V_2 , T_1 * V_3 , T_1 * V_4 )
{
unsigned char V_18 ;
if ( 1 != F_2 ( V_2 -> V_14 , & V_18 , 1 ) ) {
F_3 ( 1 , L_2 ) ;
return - V_15 ;
}
F_3 ( 2 , L_4 , V_18 ) ;
if ( V_18 == 0xff )
return 0 ;
if ( V_18 == 0xfe )
return 1 ;
* V_3 = V_18 ;
* V_4 = V_18 ;
return 1 ;
}
static int F_10 ( struct V_1 * V_2 ,
T_1 * V_3 , T_1 * V_4 )
{
unsigned char V_20 , V_21 , V_22 ;
struct V_23 V_24 [] = { { . V_25 = V_2 -> V_14 -> V_25 , . V_26 = 0 ,
. V_7 = & V_20 , . V_27 = 1 } ,
{ . V_25 = V_2 -> V_14 -> V_25 , . V_26 = V_28 ,
. V_7 = & V_21 , . V_27 = 1 } } ;
V_20 = 0x0d ;
if ( 2 != F_11 ( V_2 -> V_14 -> V_29 , V_24 , 2 ) ) {
F_3 ( 1 , L_2 ) ;
return - V_15 ;
}
if ( V_21 == 0xff )
return 0 ;
V_20 = 0x0b ;
V_24 [ 1 ] . V_7 = & V_22 ;
if ( 2 != F_11 ( V_2 -> V_14 -> V_29 , V_24 , 2 ) ) {
F_3 ( 1 , L_2 ) ;
return - V_15 ;
}
if ( V_22 == 0xff )
return 0 ;
F_3 ( 1 , L_5 , V_21 , V_22 ) ;
if ( V_22 < 2 || V_22 > 3 ) {
F_3 ( 1 , L_6 ,
V_22 , V_21 ) ;
}
V_21 |= ( V_22 & 1 ) << 6 ;
* V_3 = V_21 ;
* V_4 = V_21 ;
return 1 ;
}
static void F_12 ( struct V_1 * V_2 )
{
static T_1 V_3 , V_4 ;
int V_30 ;
F_3 ( 3 , L_7 , V_19 ) ;
V_30 = V_2 -> V_31 ( V_2 , & V_3 , & V_4 ) ;
if ( V_30 < 0 ) {
F_3 ( 2 , L_8 ) ;
return;
}
if ( V_30 ) {
F_3 ( 1 , L_9 , V_19 , V_3 ) ;
F_13 ( V_2 -> V_30 , V_3 , 0 ) ;
}
}
static void F_14 ( struct V_32 * V_33 )
{
struct V_1 * V_2 = F_15 ( V_33 , struct V_1 , V_33 . V_33 ) ;
F_12 ( V_2 ) ;
F_16 ( & V_2 -> V_33 , F_17 ( V_2 -> V_34 ) ) ;
}
static int F_18 ( struct V_35 * V_36 , const struct V_37 * V_38 )
{
char * V_39 = NULL ;
const char * V_40 = NULL ;
T_2 V_41 = V_42 ;
struct V_1 * V_2 ;
struct V_43 * V_30 = NULL ;
struct V_44 * V_45 = V_36 -> V_29 ;
unsigned short V_25 = V_36 -> V_25 ;
int V_46 ;
V_2 = F_19 ( sizeof( struct V_1 ) , V_47 ) ;
if ( ! V_2 )
return - V_48 ;
V_2 -> V_14 = V_36 ;
V_2 -> V_34 = V_49 ;
F_20 ( V_36 , V_2 ) ;
switch( V_25 ) {
case 0x64 :
V_40 = L_10 ;
V_2 -> V_31 = F_7 ;
V_41 = V_50 ;
V_39 = V_51 ;
break;
case 0x18 :
case 0x1f :
case 0x1a :
V_40 = L_11 ;
V_2 -> V_31 = F_4 ;
V_41 = V_52 ;
V_39 = V_53 ;
break;
case 0x30 :
V_40 = L_12 ;
V_2 -> V_31 = F_9 ;
V_41 = V_50 ;
V_39 = V_51 ;
break;
case 0x6b :
V_40 = L_13 ;
V_2 -> V_31 = F_8 ;
V_41 = V_52 ;
V_39 = V_54 ;
break;
case 0x40 :
V_40 = L_14 ;
V_2 -> V_31 = F_10 ;
V_41 = V_50 ;
V_39 = V_55 ;
break;
case 0x71 :
V_40 = L_15 ;
V_2 -> V_31 = F_5 ;
V_41 = V_52 ;
V_39 = V_53 ;
break;
}
if ( V_36 -> V_11 . V_56 ) {
const struct V_57 * V_58 =
V_36 -> V_11 . V_56 ;
V_39 = V_58 -> V_39 ;
V_30 = V_58 -> V_43 ;
V_40 = V_58 -> V_40 ;
if ( V_58 -> type )
V_41 = V_58 -> type ;
if ( V_58 -> V_34 )
V_2 -> V_34 = V_58 -> V_34 ;
switch ( V_58 -> V_59 ) {
case V_60 :
V_2 -> V_31 = V_58 -> V_31 ;
break;
case V_61 :
V_2 -> V_31 = F_7 ;
break;
case V_62 :
V_2 -> V_31 = F_4 ;
break;
case V_63 :
V_2 -> V_31 = F_9 ;
break;
case V_64 :
V_2 -> V_31 = F_8 ;
break;
case V_65 :
V_2 -> V_31 = F_5 ;
break;
case V_66 :
V_2 -> V_31 = F_10 ;
break;
}
}
if ( ! V_30 ) {
V_30 = F_21 () ;
if ( ! V_30 ) {
V_46 = - V_48 ;
goto V_67;
}
}
V_2 -> V_30 = V_30 ;
if ( ! V_40 || ! V_2 -> V_31 || ! V_41 || ! V_39 ) {
F_3 ( 1 , L_16 ,
V_25 ) ;
V_46 = - V_68 ;
goto V_67;
}
snprintf ( V_2 -> V_40 , sizeof( V_2 -> V_40 ) , L_17 , V_40 ) ;
V_2 -> V_39 = V_39 ;
snprintf ( V_2 -> V_69 , sizeof( V_2 -> V_69 ) , L_18 ,
F_22 ( & V_45 -> V_11 ) ,
F_22 ( & V_36 -> V_11 ) ) ;
V_30 -> V_70 . V_71 = V_72 ;
V_30 -> V_73 = V_2 -> V_69 ;
V_30 -> V_74 = V_2 -> V_40 ;
V_30 -> V_75 = V_2 -> V_39 ;
V_30 -> V_76 = V_41 ;
if ( ! V_30 -> V_77 )
V_30 -> V_77 = V_78 ;
V_46 = F_23 ( V_30 ) ;
if ( V_46 )
goto V_67;
F_24 ( V_78 L_19 ,
V_2 -> V_40 , V_2 -> V_69 , V_45 -> V_40 ) ;
F_25 ( & V_2 -> V_33 , F_14 ) ;
F_16 ( & V_2 -> V_33 , 0 ) ;
return 0 ;
V_67:
F_26 ( V_30 ) ;
F_27 ( V_2 ) ;
return V_46 ;
}
static int F_28 ( struct V_35 * V_36 )
{
struct V_1 * V_2 = F_29 ( V_36 ) ;
F_30 ( & V_2 -> V_33 ) ;
F_31 ( V_2 -> V_30 ) ;
F_27 ( V_2 ) ;
return 0 ;
}
static int T_3 F_32 ( void )
{
return F_33 ( & V_79 ) ;
}
static void T_4 F_34 ( void )
{
F_35 ( & V_79 ) ;
}
