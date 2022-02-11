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
static int F_12 ( struct V_1 * V_2 )
{
static T_1 V_3 , V_4 ;
int V_30 ;
F_3 ( 3 , L_7 , V_19 ) ;
V_30 = V_2 -> V_31 ( V_2 , & V_3 , & V_4 ) ;
if ( V_30 < 0 ) {
F_3 ( 2 , L_8 ) ;
return V_30 ;
}
if ( V_30 ) {
F_3 ( 1 , L_9 , V_19 , V_3 ) ;
F_13 ( V_2 -> V_30 , V_3 , 0 ) ;
}
return 0 ;
}
static void F_14 ( struct V_32 * V_33 )
{
int V_30 ;
struct V_1 * V_2 = F_15 ( V_33 , struct V_1 , V_33 . V_33 ) ;
V_30 = F_12 ( V_2 ) ;
if ( V_30 == - V_34 ) {
F_16 ( V_2 -> V_30 ) ;
V_2 -> V_30 = NULL ;
return;
}
F_17 ( & V_2 -> V_33 , F_18 ( V_2 -> V_35 ) ) ;
}
static int F_19 ( struct V_36 * V_37 , const struct V_38 * V_39 )
{
char * V_40 = NULL ;
const char * V_41 = NULL ;
T_2 V_42 = V_43 ;
struct V_1 * V_2 ;
struct V_44 * V_30 = NULL ;
struct V_45 * V_46 = V_37 -> V_29 ;
unsigned short V_25 = V_37 -> V_25 ;
int V_47 ;
V_2 = F_20 ( sizeof( struct V_1 ) , V_48 ) ;
if ( ! V_2 )
return - V_49 ;
V_2 -> V_14 = V_37 ;
V_2 -> V_35 = V_50 ;
F_21 ( V_37 , V_2 ) ;
switch( V_25 ) {
case 0x64 :
V_41 = L_10 ;
V_2 -> V_31 = F_7 ;
V_42 = V_51 ;
V_40 = V_52 ;
break;
case 0x18 :
case 0x1f :
case 0x1a :
V_41 = L_11 ;
V_2 -> V_31 = F_4 ;
V_42 = V_53 ;
V_40 = V_54 ;
break;
case 0x30 :
V_41 = L_12 ;
V_2 -> V_31 = F_9 ;
V_42 = V_51 ;
V_40 = V_52 ;
break;
case 0x6b :
V_41 = L_13 ;
V_2 -> V_31 = F_8 ;
V_42 = V_53 ;
V_40 = V_55 ;
break;
case 0x40 :
V_41 = L_14 ;
V_2 -> V_31 = F_10 ;
V_42 = V_51 ;
V_40 = V_56 ;
break;
case 0x71 :
V_41 = L_15 ;
V_2 -> V_31 = F_5 ;
V_42 = V_53 ;
V_40 = V_54 ;
break;
}
if ( V_37 -> V_11 . V_57 ) {
const struct V_58 * V_59 =
V_37 -> V_11 . V_57 ;
V_40 = V_59 -> V_40 ;
V_30 = V_59 -> V_44 ;
V_41 = V_59 -> V_41 ;
if ( V_59 -> type )
V_42 = V_59 -> type ;
if ( V_59 -> V_35 )
V_2 -> V_35 = V_59 -> V_35 ;
switch ( V_59 -> V_60 ) {
case V_61 :
V_2 -> V_31 = V_59 -> V_31 ;
break;
case V_62 :
V_2 -> V_31 = F_7 ;
break;
case V_63 :
V_2 -> V_31 = F_4 ;
break;
case V_64 :
V_2 -> V_31 = F_9 ;
break;
case V_65 :
V_2 -> V_31 = F_8 ;
break;
case V_66 :
V_2 -> V_31 = F_5 ;
break;
case V_67 :
V_2 -> V_31 = F_10 ;
break;
}
}
if ( ! V_30 ) {
V_30 = F_22 () ;
if ( ! V_30 ) {
V_47 = - V_49 ;
goto V_68;
}
}
V_2 -> V_30 = V_30 ;
if ( ! V_41 || ! V_2 -> V_31 || ! V_42 || ! V_40 ) {
F_3 ( 1 , L_16 ,
V_25 ) ;
V_47 = - V_34 ;
goto V_68;
}
snprintf ( V_2 -> V_41 , sizeof( V_2 -> V_41 ) , L_17 , V_41 ) ;
V_2 -> V_40 = V_40 ;
snprintf ( V_2 -> V_69 , sizeof( V_2 -> V_69 ) , L_18 ,
F_23 ( & V_46 -> V_11 ) ,
F_23 ( & V_37 -> V_11 ) ) ;
V_30 -> V_70 . V_71 = V_72 ;
V_30 -> V_73 = V_2 -> V_69 ;
V_30 -> V_74 = V_2 -> V_41 ;
V_30 -> V_75 = V_2 -> V_40 ;
V_30 -> V_76 = V_42 ;
if ( ! V_30 -> V_77 )
V_30 -> V_77 = V_78 ;
V_47 = F_24 ( V_30 ) ;
if ( V_47 )
goto V_68;
F_25 ( V_78 L_19 ,
V_2 -> V_41 , V_2 -> V_69 , V_46 -> V_41 ) ;
F_26 ( & V_2 -> V_33 , F_14 ) ;
F_17 ( & V_2 -> V_33 , 0 ) ;
return 0 ;
V_68:
F_27 ( V_30 ) ;
F_28 ( V_2 ) ;
return V_47 ;
}
static int F_29 ( struct V_36 * V_37 )
{
struct V_1 * V_2 = F_30 ( V_37 ) ;
F_31 ( & V_2 -> V_33 ) ;
if ( V_2 -> V_30 )
F_16 ( V_2 -> V_30 ) ;
F_28 ( V_2 ) ;
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
