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
if ( V_22 < 2 || V_22 > 4 ) {
F_3 ( 1 , L_6 ,
V_22 , V_21 ) ;
}
V_21 |= ( V_22 & 1 ) << 6 ;
* V_3 = V_21 ;
* V_4 = V_21 ;
if ( ! strcmp ( V_2 -> V_30 , V_31 ) ) {
* V_3 |= V_22 << 8 ;
* V_4 |= V_22 << 8 ;
}
return 1 ;
}
static int F_12 ( struct V_1 * V_2 )
{
static T_1 V_3 , V_4 ;
int V_32 ;
F_3 ( 3 , L_7 , V_19 ) ;
V_32 = V_2 -> V_33 ( V_2 , & V_3 , & V_4 ) ;
if ( V_32 < 0 ) {
F_3 ( 2 , L_8 ) ;
return V_32 ;
}
if ( V_32 ) {
F_3 ( 1 , L_9 , V_19 , V_3 ) ;
F_13 ( V_2 -> V_32 , V_3 , 0 ) ;
}
return 0 ;
}
static void F_14 ( struct V_34 * V_35 )
{
int V_32 ;
struct V_1 * V_2 = F_15 ( V_35 , struct V_1 , V_35 . V_35 ) ;
V_32 = F_12 ( V_2 ) ;
if ( V_32 == - V_36 ) {
F_16 ( V_2 -> V_32 ) ;
V_2 -> V_32 = NULL ;
return;
}
F_17 ( & V_2 -> V_35 , F_18 ( V_2 -> V_37 ) ) ;
}
static int F_19 ( struct V_38 * V_39 , const struct V_40 * V_41 )
{
char * V_30 = NULL ;
const char * V_42 = NULL ;
T_2 V_43 = V_44 ;
struct V_1 * V_2 ;
struct V_45 * V_32 = NULL ;
struct V_46 * V_47 = V_39 -> V_29 ;
unsigned short V_25 = V_39 -> V_25 ;
int V_48 ;
V_2 = F_20 ( & V_39 -> V_11 , sizeof( * V_2 ) , V_49 ) ;
if ( ! V_2 )
return - V_50 ;
V_2 -> V_14 = V_39 ;
V_2 -> V_37 = V_51 ;
F_21 ( V_39 , V_2 ) ;
switch( V_25 ) {
case 0x64 :
V_42 = L_10 ;
V_2 -> V_33 = F_7 ;
V_43 = V_52 ;
V_30 = V_53 ;
break;
case 0x18 :
case 0x1f :
case 0x1a :
V_42 = L_11 ;
V_2 -> V_33 = F_4 ;
V_43 = V_54 ;
V_30 = V_55 ;
break;
case 0x30 :
V_42 = L_12 ;
V_2 -> V_33 = F_9 ;
V_43 = V_52 ;
V_30 = V_53 ;
break;
case 0x6b :
V_42 = L_13 ;
V_2 -> V_33 = F_8 ;
V_43 = V_54 ;
V_30 = V_56 ;
break;
case 0x40 :
V_42 = L_14 ;
V_2 -> V_33 = F_10 ;
V_43 = V_52 ;
V_30 = V_57 ;
break;
case 0x41 :
V_42 = L_15 ;
V_2 -> V_33 = F_10 ;
V_43 = V_52 ;
V_30 = V_31 ;
break;
case 0x71 :
V_42 = L_16 ;
V_2 -> V_33 = F_5 ;
V_43 = V_54 ;
V_30 = V_55 ;
break;
}
if ( V_39 -> V_11 . V_58 ) {
const struct V_59 * V_60 =
V_39 -> V_11 . V_58 ;
V_30 = V_60 -> V_30 ;
V_32 = V_60 -> V_45 ;
V_42 = V_60 -> V_42 ;
if ( V_60 -> type )
V_43 = V_60 -> type ;
if ( V_60 -> V_37 )
V_2 -> V_37 = V_60 -> V_37 ;
switch ( V_60 -> V_61 ) {
case V_62 :
V_2 -> V_33 = V_60 -> V_33 ;
break;
case V_63 :
V_2 -> V_33 = F_7 ;
break;
case V_64 :
V_2 -> V_33 = F_4 ;
break;
case V_65 :
V_2 -> V_33 = F_9 ;
break;
case V_66 :
V_2 -> V_33 = F_8 ;
break;
case V_67 :
V_2 -> V_33 = F_5 ;
break;
case V_68 :
V_2 -> V_33 = F_10 ;
break;
}
}
if ( ! V_32 ) {
V_32 = F_22 () ;
if ( ! V_32 )
return - V_50 ;
}
V_2 -> V_32 = V_32 ;
if ( ! V_42 || ! V_2 -> V_33 || ! V_43 || ! V_30 ) {
F_3 ( 1 , L_17 ,
V_25 ) ;
V_48 = - V_36 ;
goto V_69;
}
snprintf ( V_2 -> V_42 , sizeof( V_2 -> V_42 ) , L_18 , V_42 ) ;
V_2 -> V_30 = V_30 ;
snprintf ( V_2 -> V_70 , sizeof( V_2 -> V_70 ) , L_19 ,
F_23 ( & V_47 -> V_11 ) ,
F_23 ( & V_39 -> V_11 ) ) ;
V_32 -> V_71 . V_72 = V_73 ;
V_32 -> V_74 = V_2 -> V_70 ;
V_32 -> V_75 = V_2 -> V_42 ;
V_32 -> V_76 = V_2 -> V_30 ;
F_24 ( V_32 , V_43 ) ;
F_25 ( V_32 , V_43 ) ;
if ( ! V_32 -> V_77 )
V_32 -> V_77 = V_78 ;
V_48 = F_26 ( V_32 ) ;
if ( V_48 )
goto V_69;
F_27 ( V_78 L_20 ,
V_2 -> V_42 , V_2 -> V_70 , V_47 -> V_42 ) ;
F_28 ( & V_2 -> V_35 , F_14 ) ;
F_17 ( & V_2 -> V_35 , 0 ) ;
return 0 ;
V_69:
F_29 ( V_32 ) ;
return V_48 ;
}
static int F_30 ( struct V_38 * V_39 )
{
struct V_1 * V_2 = F_31 ( V_39 ) ;
F_32 ( & V_2 -> V_35 ) ;
if ( V_2 -> V_32 )
F_16 ( V_2 -> V_32 ) ;
return 0 ;
}
