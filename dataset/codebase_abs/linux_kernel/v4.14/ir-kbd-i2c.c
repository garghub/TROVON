static int F_1 ( struct V_1 * V_2 , enum V_3 * V_4 ,
T_1 * V_5 , T_2 * V_6 , int V_7 )
{
unsigned char V_8 [ 6 ] ;
int V_9 , V_10 , V_11 , V_12 , V_13 , V_14 , V_15 ;
if ( V_7 != F_2 ( V_2 -> V_16 , V_8 , V_7 ) )
return - V_17 ;
if ( V_8 [ 0 ] & 0x80 ) {
int V_18 = ( V_7 == 6 ) ? 3 : 0 ;
V_9 = ( V_8 [ V_18 ] >> 7 ) & 1 ;
V_10 = ( V_8 [ V_18 ] >> 6 ) & 1 ;
V_11 = ( V_8 [ V_18 ] >> 5 ) & 1 ;
V_12 = V_8 [ V_18 ] & 0x1f ;
V_13 = ( V_8 [ V_18 + 1 ] >> 2 ) & 0x3f ;
if ( ! V_9 )
return 0 ;
V_14 = ( V_9 << 12 ) | ( V_11 << 11 ) | ( V_12 << 6 ) | V_13 ;
if ( ( V_14 & 0x1fff ) == 0x1fff )
return 0 ;
if ( ! V_10 )
V_13 += 64 ;
F_3 ( 1 , L_1 ,
V_9 , V_10 , V_11 , V_12 , V_13 ) ;
* V_4 = V_19 ;
* V_5 = F_4 ( V_12 , V_13 ) ;
* V_6 = V_11 ;
return 1 ;
} else if ( V_7 == 6 && ( V_8 [ 0 ] & 0x40 ) ) {
V_13 = V_8 [ 4 ] ;
V_12 = V_8 [ 3 ] ;
V_15 = F_5 ( V_8 + 1 ) ;
if ( V_15 == 0x800f ) {
* V_6 = ( V_12 & 0x80 ) != 0 ;
* V_4 = V_20 ;
V_12 &= 0x7f ;
F_3 ( 1 , L_2 ,
* V_6 , V_15 , V_12 , V_13 ) ;
} else {
* V_6 = 0 ;
* V_4 = V_21 ;
F_3 ( 1 , L_3 ,
V_15 , V_12 , V_13 ) ;
}
* V_5 = F_6 ( V_15 , V_12 , V_13 ) ;
return 1 ;
}
return 0 ;
}
static int F_7 ( struct V_1 * V_2 , enum V_3 * V_4 ,
T_1 * V_5 , T_2 * V_11 )
{
return F_1 ( V_2 , V_4 , V_5 , V_11 , 3 ) ;
}
static int F_8 ( struct V_1 * V_2 , enum V_3 * V_4 ,
T_1 * V_5 , T_2 * V_11 )
{
int V_22 ;
unsigned char V_8 [ 1 ] = { 0 } ;
V_22 = F_9 ( V_2 -> V_16 , V_8 , 1 ) ;
if ( V_22 != 1 )
return ( V_22 < 0 ) ? V_22 : - V_23 ;
return F_1 ( V_2 , V_4 , V_5 , V_11 , 6 ) ;
}
static int F_10 ( struct V_1 * V_2 , enum V_3 * V_4 ,
T_1 * V_5 , T_2 * V_11 )
{
unsigned char V_24 ;
if ( 1 != F_2 ( V_2 -> V_16 , & V_24 , 1 ) ) {
F_3 ( 1 , L_4 ) ;
return - V_17 ;
}
* V_4 = V_25 ;
* V_5 = V_24 ;
* V_11 = 0 ;
return 1 ;
}
static int F_11 ( struct V_1 * V_2 , enum V_3 * V_4 ,
T_1 * V_5 , T_2 * V_11 )
{
unsigned char V_8 [ 4 ] ;
if ( 4 != F_2 ( V_2 -> V_16 , V_8 , 4 ) ) {
F_3 ( 1 , L_4 ) ;
return - V_17 ;
}
if( V_8 [ 0 ] != 0 || V_8 [ 1 ] != 0 || V_8 [ 2 ] != 0 || V_8 [ 3 ] != 0 )
F_3 ( 2 , L_5 , V_26 ,
V_8 [ 0 ] , V_8 [ 1 ] , V_8 [ 2 ] , V_8 [ 3 ] ) ;
if( V_8 [ 0 ] != 0x1 || V_8 [ 1 ] != 0xfe )
return 0 ;
* V_4 = V_27 ;
* V_5 = V_8 [ 2 ] ;
* V_11 = 0 ;
return 1 ;
}
static int F_12 ( struct V_1 * V_2 , enum V_3 * V_4 ,
T_1 * V_5 , T_2 * V_11 )
{
unsigned char V_24 ;
if ( 1 != F_2 ( V_2 -> V_16 , & V_24 , 1 ) ) {
F_3 ( 1 , L_4 ) ;
return - V_17 ;
}
F_3 ( 2 , L_6 , V_24 ) ;
if ( V_24 == 0xff )
return 0 ;
if ( V_24 == 0xfe )
return 1 ;
* V_4 = V_27 ;
* V_5 = V_24 ;
* V_11 = 0 ;
return 1 ;
}
static int F_13 ( struct V_1 * V_2 , enum V_3 * V_4 ,
T_1 * V_5 , T_2 * V_11 )
{
unsigned char V_28 , V_29 , V_30 ;
struct V_31 V_32 [] = { { . V_33 = V_2 -> V_16 -> V_33 , . V_34 = 0 ,
. V_8 = & V_28 , . V_35 = 1 } ,
{ . V_33 = V_2 -> V_16 -> V_33 , . V_34 = V_36 ,
. V_8 = & V_29 , . V_35 = 1 } } ;
V_28 = 0x0d ;
if ( 2 != F_14 ( V_2 -> V_16 -> V_37 , V_32 , 2 ) ) {
F_3 ( 1 , L_4 ) ;
return - V_17 ;
}
if ( V_29 == 0xff )
return 0 ;
V_28 = 0x0b ;
V_32 [ 1 ] . V_8 = & V_30 ;
if ( 2 != F_14 ( V_2 -> V_16 -> V_37 , V_32 , 2 ) ) {
F_3 ( 1 , L_4 ) ;
return - V_17 ;
}
if ( V_30 == 0xff )
return 0 ;
F_3 ( 1 , L_7 , V_29 , V_30 ) ;
if ( V_30 < 2 || V_30 > 4 ) {
F_3 ( 1 , L_8 ,
V_30 , V_29 ) ;
}
V_29 |= ( V_30 & 1 ) << 6 ;
* V_4 = V_27 ;
* V_5 = V_29 ;
if ( V_2 -> V_16 -> V_33 == 0x41 )
* V_5 |= V_30 << 8 ;
* V_11 = 0 ;
return 1 ;
}
static int F_15 ( struct V_1 * V_2 )
{
enum V_3 V_4 ;
T_1 V_5 ;
T_2 V_11 ;
int V_38 ;
F_3 ( 3 , L_9 , V_26 ) ;
V_38 = V_2 -> V_39 ( V_2 , & V_4 , & V_5 , & V_11 ) ;
if ( V_38 < 0 ) {
F_3 ( 2 , L_10 ) ;
return V_38 ;
}
if ( V_38 ) {
F_3 ( 1 , L_11 ,
V_26 , V_4 , V_5 ) ;
F_16 ( V_2 -> V_38 , V_4 , V_5 , V_11 ) ;
}
return 0 ;
}
static void F_17 ( struct V_40 * V_41 )
{
int V_38 ;
struct V_1 * V_2 = F_18 ( V_41 , struct V_1 , V_41 . V_41 ) ;
V_38 = F_15 ( V_2 ) ;
if ( V_38 == - V_42 ) {
F_19 ( V_2 -> V_38 ) ;
V_2 -> V_38 = NULL ;
return;
}
F_20 ( & V_2 -> V_41 , F_21 ( V_2 -> V_43 ) ) ;
}
static int F_22 ( struct V_44 * V_45 , const struct V_46 * V_47 )
{
char * V_48 = NULL ;
const char * V_49 = NULL ;
T_3 V_3 = V_50 ;
struct V_1 * V_2 ;
struct V_51 * V_38 = NULL ;
struct V_52 * V_53 = V_45 -> V_37 ;
unsigned short V_33 = V_45 -> V_33 ;
int V_54 ;
V_2 = F_23 ( & V_45 -> V_12 , sizeof( * V_2 ) , V_55 ) ;
if ( ! V_2 )
return - V_56 ;
V_2 -> V_16 = V_45 ;
V_2 -> V_43 = V_57 ;
F_24 ( V_45 , V_2 ) ;
switch( V_33 ) {
case 0x64 :
V_49 = L_12 ;
V_2 -> V_39 = F_10 ;
V_3 = V_58 ;
V_48 = V_59 ;
break;
case 0x18 :
case 0x1f :
case 0x1a :
V_49 = L_13 ;
V_2 -> V_39 = F_7 ;
V_3 = V_60 ;
V_48 = V_61 ;
break;
case 0x30 :
V_49 = L_14 ;
V_2 -> V_39 = F_12 ;
V_3 = V_58 ;
V_48 = V_59 ;
break;
case 0x6b :
V_49 = L_15 ;
V_2 -> V_39 = F_11 ;
V_3 = V_50 ;
V_48 = V_62 ;
break;
case 0x40 :
V_49 = L_16 ;
V_2 -> V_39 = F_13 ;
V_3 = V_58 ;
V_48 = V_63 ;
break;
case 0x41 :
V_49 = L_17 ;
V_2 -> V_39 = F_13 ;
V_3 = V_58 ;
V_48 = V_64 ;
break;
case 0x71 :
V_49 = L_18 ;
V_2 -> V_39 = F_8 ;
V_3 = V_60 | V_65 |
V_66 ;
V_48 = V_61 ;
break;
}
if ( V_45 -> V_12 . V_67 ) {
const struct V_68 * V_69 =
V_45 -> V_12 . V_67 ;
V_48 = V_69 -> V_48 ;
V_38 = V_69 -> V_51 ;
V_49 = V_69 -> V_49 ;
if ( V_69 -> type )
V_3 = V_69 -> type ;
if ( V_69 -> V_43 )
V_2 -> V_43 = V_69 -> V_43 ;
switch ( V_69 -> V_70 ) {
case V_71 :
V_2 -> V_39 = V_69 -> V_39 ;
break;
case V_72 :
V_2 -> V_39 = F_10 ;
break;
case V_73 :
V_2 -> V_39 = F_7 ;
break;
case V_74 :
V_2 -> V_39 = F_12 ;
break;
case V_75 :
V_2 -> V_39 = F_11 ;
break;
case V_76 :
V_2 -> V_39 = F_8 ;
break;
case V_77 :
V_2 -> V_39 = F_13 ;
break;
}
}
if ( ! V_38 ) {
V_38 = F_25 ( V_78 ) ;
if ( ! V_38 )
return - V_56 ;
}
V_2 -> V_38 = V_38 ;
if ( ! V_49 || ! V_2 -> V_39 || ! V_3 || ! V_48 ) {
F_3 ( 1 , L_19 ,
V_33 ) ;
V_54 = - V_42 ;
goto V_79;
}
snprintf ( V_2 -> V_49 , sizeof( V_2 -> V_49 ) , L_20 , V_49 ) ;
V_2 -> V_48 = V_48 ;
snprintf ( V_2 -> V_80 , sizeof( V_2 -> V_80 ) , L_21 ,
F_26 ( & V_53 -> V_12 ) ,
F_26 ( & V_45 -> V_12 ) ) ;
V_38 -> V_81 . V_82 = V_83 ;
V_38 -> V_84 = V_2 -> V_80 ;
V_38 -> V_85 = V_2 -> V_49 ;
V_38 -> V_86 = V_2 -> V_48 ;
V_38 -> V_87 = V_3 ;
V_38 -> V_88 = V_3 ;
if ( ! V_38 -> V_89 )
V_38 -> V_89 = V_90 ;
V_54 = F_27 ( V_38 ) ;
if ( V_54 )
goto V_79;
F_28 ( V_90 L_22 ,
V_2 -> V_49 , V_2 -> V_80 , V_53 -> V_49 ) ;
F_29 ( & V_2 -> V_41 , F_17 ) ;
F_20 ( & V_2 -> V_41 , 0 ) ;
return 0 ;
V_79:
F_30 ( V_38 ) ;
return V_54 ;
}
static int F_31 ( struct V_44 * V_45 )
{
struct V_1 * V_2 = F_32 ( V_45 ) ;
F_33 ( & V_2 -> V_41 ) ;
F_19 ( V_2 -> V_38 ) ;
return 0 ;
}
