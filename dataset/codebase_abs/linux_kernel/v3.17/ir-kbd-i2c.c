static int F_1 ( struct V_1 * V_2 , enum V_3 * V_4 ,
T_1 * V_5 , T_2 * V_6 , int V_7 , int V_8 )
{
unsigned char V_9 [ 6 ] ;
int V_10 , V_11 , V_12 , V_13 , V_14 , V_15 ;
if ( V_7 != F_2 ( V_2 -> V_16 , V_9 , V_7 ) )
return - V_17 ;
V_10 = ( V_9 [ V_8 ] >> 7 ) & 1 ;
V_11 = ( V_9 [ V_8 ] >> 6 ) & 1 ;
V_12 = ( V_9 [ V_8 ] >> 5 ) & 1 ;
V_13 = V_9 [ V_8 ] & 0x1f ;
V_14 = ( V_9 [ V_8 + 1 ] >> 2 ) & 0x3f ;
if ( ! V_10 )
return 0 ;
V_15 = ( V_10 << 12 ) | ( V_12 << 11 ) | ( V_13 << 6 ) | V_14 ;
if ( ( V_15 & 0x1fff ) == 0x1fff )
return 0 ;
if ( ! V_11 )
V_14 += 64 ;
F_3 ( 1 , L_1 ,
V_10 , V_11 , V_12 , V_13 , V_14 ) ;
* V_4 = V_18 ;
* V_5 = F_4 ( V_13 , V_14 ) ;
* V_6 = V_12 ;
return 1 ;
}
static int F_5 ( struct V_1 * V_2 , enum V_3 * V_4 ,
T_1 * V_5 , T_2 * V_12 )
{
return F_1 ( V_2 , V_4 , V_5 , V_12 , 3 , 0 ) ;
}
static int F_6 ( struct V_1 * V_2 , enum V_3 * V_4 ,
T_1 * V_5 , T_2 * V_12 )
{
int V_19 ;
unsigned char V_9 [ 1 ] = { 0 } ;
V_19 = F_7 ( V_2 -> V_16 , V_9 , 1 ) ;
if ( V_19 != 1 )
return ( V_19 < 0 ) ? V_19 : - V_20 ;
return F_1 ( V_2 , V_4 , V_5 , V_12 , 6 , 3 ) ;
}
static int F_8 ( struct V_1 * V_2 , enum V_3 * V_4 ,
T_1 * V_5 , T_2 * V_12 )
{
unsigned char V_21 ;
if ( 1 != F_2 ( V_2 -> V_16 , & V_21 , 1 ) ) {
F_3 ( 1 , L_2 ) ;
return - V_17 ;
}
* V_4 = V_22 ;
* V_5 = V_21 ;
* V_12 = 0 ;
return 1 ;
}
static int F_9 ( struct V_1 * V_2 , enum V_3 * V_4 ,
T_1 * V_5 , T_2 * V_12 )
{
unsigned char V_9 [ 4 ] ;
if ( 4 != F_2 ( V_2 -> V_16 , V_9 , 4 ) ) {
F_3 ( 1 , L_2 ) ;
return - V_17 ;
}
if( V_9 [ 0 ] != 0 || V_9 [ 1 ] != 0 || V_9 [ 2 ] != 0 || V_9 [ 3 ] != 0 )
F_3 ( 2 , L_3 , V_23 ,
V_9 [ 0 ] , V_9 [ 1 ] , V_9 [ 2 ] , V_9 [ 3 ] ) ;
if( V_9 [ 0 ] != 0x1 || V_9 [ 1 ] != 0xfe )
return 0 ;
* V_4 = V_24 ;
* V_5 = V_9 [ 2 ] ;
* V_12 = 0 ;
return 1 ;
}
static int F_10 ( struct V_1 * V_2 , enum V_3 * V_4 ,
T_1 * V_5 , T_2 * V_12 )
{
unsigned char V_21 ;
if ( 1 != F_2 ( V_2 -> V_16 , & V_21 , 1 ) ) {
F_3 ( 1 , L_2 ) ;
return - V_17 ;
}
F_3 ( 2 , L_4 , V_21 ) ;
if ( V_21 == 0xff )
return 0 ;
if ( V_21 == 0xfe )
return 1 ;
* V_4 = V_24 ;
* V_5 = V_21 ;
* V_12 = 0 ;
return 1 ;
}
static int F_11 ( struct V_1 * V_2 , enum V_3 * V_4 ,
T_1 * V_5 , T_2 * V_12 )
{
unsigned char V_25 , V_26 , V_27 ;
struct V_28 V_29 [] = { { . V_30 = V_2 -> V_16 -> V_30 , . V_31 = 0 ,
. V_9 = & V_25 , . V_32 = 1 } ,
{ . V_30 = V_2 -> V_16 -> V_30 , . V_31 = V_33 ,
. V_9 = & V_26 , . V_32 = 1 } } ;
V_25 = 0x0d ;
if ( 2 != F_12 ( V_2 -> V_16 -> V_34 , V_29 , 2 ) ) {
F_3 ( 1 , L_2 ) ;
return - V_17 ;
}
if ( V_26 == 0xff )
return 0 ;
V_25 = 0x0b ;
V_29 [ 1 ] . V_9 = & V_27 ;
if ( 2 != F_12 ( V_2 -> V_16 -> V_34 , V_29 , 2 ) ) {
F_3 ( 1 , L_2 ) ;
return - V_17 ;
}
if ( V_27 == 0xff )
return 0 ;
F_3 ( 1 , L_5 , V_26 , V_27 ) ;
if ( V_27 < 2 || V_27 > 4 ) {
F_3 ( 1 , L_6 ,
V_27 , V_26 ) ;
}
V_26 |= ( V_27 & 1 ) << 6 ;
* V_4 = V_24 ;
* V_5 = V_26 ;
if ( V_2 -> V_16 -> V_30 == 0x41 )
* V_5 |= V_27 << 8 ;
* V_12 = 0 ;
return 1 ;
}
static int F_13 ( struct V_1 * V_2 )
{
enum V_3 V_4 ;
T_1 V_5 ;
T_2 V_12 ;
int V_35 ;
F_3 ( 3 , L_7 , V_23 ) ;
V_35 = V_2 -> V_36 ( V_2 , & V_4 , & V_5 , & V_12 ) ;
if ( V_35 < 0 ) {
F_3 ( 2 , L_8 ) ;
return V_35 ;
}
if ( V_35 ) {
F_3 ( 1 , L_9 ,
V_23 , V_4 , V_5 ) ;
F_14 ( V_2 -> V_35 , V_4 , V_5 , V_12 ) ;
}
return 0 ;
}
static void F_15 ( struct V_37 * V_38 )
{
int V_35 ;
struct V_1 * V_2 = F_16 ( V_38 , struct V_1 , V_38 . V_38 ) ;
V_35 = F_13 ( V_2 ) ;
if ( V_35 == - V_39 ) {
F_17 ( V_2 -> V_35 ) ;
V_2 -> V_35 = NULL ;
return;
}
F_18 ( & V_2 -> V_38 , F_19 ( V_2 -> V_40 ) ) ;
}
static int F_20 ( struct V_41 * V_42 , const struct V_43 * V_44 )
{
char * V_45 = NULL ;
const char * V_46 = NULL ;
T_3 V_3 = V_47 ;
struct V_1 * V_2 ;
struct V_48 * V_35 = NULL ;
struct V_49 * V_50 = V_42 -> V_34 ;
unsigned short V_30 = V_42 -> V_30 ;
int V_51 ;
V_2 = F_21 ( & V_42 -> V_13 , sizeof( * V_2 ) , V_52 ) ;
if ( ! V_2 )
return - V_53 ;
V_2 -> V_16 = V_42 ;
V_2 -> V_40 = V_54 ;
F_22 ( V_42 , V_2 ) ;
switch( V_30 ) {
case 0x64 :
V_46 = L_10 ;
V_2 -> V_36 = F_8 ;
V_3 = V_55 ;
V_45 = V_56 ;
break;
case 0x18 :
case 0x1f :
case 0x1a :
V_46 = L_11 ;
V_2 -> V_36 = F_5 ;
V_3 = V_57 ;
V_45 = V_58 ;
break;
case 0x30 :
V_46 = L_12 ;
V_2 -> V_36 = F_10 ;
V_3 = V_55 ;
V_45 = V_56 ;
break;
case 0x6b :
V_46 = L_13 ;
V_2 -> V_36 = F_9 ;
V_3 = V_47 ;
V_45 = V_59 ;
break;
case 0x40 :
V_46 = L_14 ;
V_2 -> V_36 = F_11 ;
V_3 = V_55 ;
V_45 = V_60 ;
break;
case 0x41 :
V_46 = L_15 ;
V_2 -> V_36 = F_11 ;
V_3 = V_55 ;
V_45 = V_61 ;
break;
case 0x71 :
V_46 = L_16 ;
V_2 -> V_36 = F_6 ;
V_3 = V_57 ;
V_45 = V_58 ;
break;
}
if ( V_42 -> V_13 . V_62 ) {
const struct V_63 * V_64 =
V_42 -> V_13 . V_62 ;
V_45 = V_64 -> V_45 ;
V_35 = V_64 -> V_48 ;
V_46 = V_64 -> V_46 ;
if ( V_64 -> type )
V_3 = V_64 -> type ;
if ( V_64 -> V_40 )
V_2 -> V_40 = V_64 -> V_40 ;
switch ( V_64 -> V_65 ) {
case V_66 :
V_2 -> V_36 = V_64 -> V_36 ;
break;
case V_67 :
V_2 -> V_36 = F_8 ;
break;
case V_68 :
V_2 -> V_36 = F_5 ;
break;
case V_69 :
V_2 -> V_36 = F_10 ;
break;
case V_70 :
V_2 -> V_36 = F_9 ;
break;
case V_71 :
V_2 -> V_36 = F_6 ;
break;
case V_72 :
V_2 -> V_36 = F_11 ;
break;
}
}
if ( ! V_35 ) {
V_35 = F_23 () ;
if ( ! V_35 )
return - V_53 ;
}
V_2 -> V_35 = V_35 ;
if ( ! V_46 || ! V_2 -> V_36 || ! V_3 || ! V_45 ) {
F_3 ( 1 , L_17 ,
V_30 ) ;
V_51 = - V_39 ;
goto V_73;
}
snprintf ( V_2 -> V_46 , sizeof( V_2 -> V_46 ) , L_18 , V_46 ) ;
V_2 -> V_45 = V_45 ;
snprintf ( V_2 -> V_74 , sizeof( V_2 -> V_74 ) , L_19 ,
F_24 ( & V_50 -> V_13 ) ,
F_24 ( & V_42 -> V_13 ) ) ;
V_35 -> V_75 . V_76 = V_77 ;
V_35 -> V_78 = V_2 -> V_74 ;
V_35 -> V_79 = V_2 -> V_46 ;
V_35 -> V_80 = V_2 -> V_45 ;
V_35 -> V_81 = V_3 ;
V_35 -> V_82 = V_3 ;
if ( ! V_35 -> V_83 )
V_35 -> V_83 = V_84 ;
V_51 = F_25 ( V_35 ) ;
if ( V_51 )
goto V_73;
F_26 ( V_84 L_20 ,
V_2 -> V_46 , V_2 -> V_74 , V_50 -> V_46 ) ;
F_27 ( & V_2 -> V_38 , F_15 ) ;
F_18 ( & V_2 -> V_38 , 0 ) ;
return 0 ;
V_73:
F_28 ( V_35 ) ;
return V_51 ;
}
static int F_29 ( struct V_41 * V_42 )
{
struct V_1 * V_2 = F_30 ( V_42 ) ;
F_31 ( & V_2 -> V_38 ) ;
if ( V_2 -> V_35 )
F_17 ( V_2 -> V_35 ) ;
return 0 ;
}
