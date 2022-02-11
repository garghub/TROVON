static T_1 F_1 ( unsigned V_1 )
{
unsigned V_2 = F_2 ( V_1 , V_3 , V_4 ) ;
return ( V_2 + 8 ) / 16 ;
}
static unsigned F_3 ( T_1 V_5 )
{
return V_5 * 16 ;
}
static T_1 F_4 ( long V_6 , int div )
{
if ( V_6 == - 1 )
return 0 ;
if ( V_6 == 0 )
return 255 ;
V_6 = F_2 ( V_6 , 1 , 1000000 ) ;
return F_2 ( ( 1350000 + V_6 * div / 2 ) / ( V_6 * div ) , 1 , 254 ) ;
}
static int F_5 ( T_1 V_1 , int div )
{
return V_1 == 0 ? - 1 : V_1 == 255 ? 0 : 1350000 / ( V_1 * div ) ;
}
static T_1 F_6 ( long V_7 )
{
int V_8 = F_2 ( V_7 , V_9 , V_10 ) ;
V_8 += ( V_8 < 0 ? - 500 : 500 ) ;
return ( T_1 ) ( V_8 / 1000 ) ;
}
static int F_7 ( T_1 V_5 )
{
return ( V_11 ) V_5 * 1000 ;
}
static T_1 F_8 ( int V_12 )
{
V_12 = F_2 ( V_12 , 0 , 255 ) ;
return ( T_1 ) ( V_12 / 16 ) ;
}
static int F_9 ( T_1 V_5 )
{
return V_5 * 16 ;
}
static T_1 F_10 ( long V_1 )
{
return V_1 == 8 ? 3 : V_1 == 4 ? 2 : V_1 == 1 ? 0 : 1 ;
}
static T_2 F_11 ( struct V_13 * V_14 , struct V_15 * V_16 ,
char * V_17 )
{
int V_18 = F_12 ( V_16 ) -> V_19 ;
struct V_20 * V_21 = F_13 ( V_14 ) ;
return sprintf ( V_17 , L_1 , F_5 ( V_21 -> V_22 [ V_18 ] ,
F_14 ( V_21 -> V_23 [ V_18 ] ) ) ) ;
}
static T_2 F_15 ( struct V_13 * V_14 , struct V_15 * V_16 ,
char * V_17 )
{
int V_18 = F_12 ( V_16 ) -> V_19 ;
struct V_20 * V_21 = F_13 ( V_14 ) ;
return sprintf ( V_17 , L_1 , F_5 ( V_21 -> V_24 [ V_18 ] ,
F_14 ( V_21 -> V_23 [ V_18 ] ) ) ) ;
}
static T_2 F_16 ( struct V_13 * V_14 , struct V_15 * V_16 ,
char * V_17 )
{
int V_18 = F_12 ( V_16 ) -> V_19 ;
struct V_20 * V_21 = F_13 ( V_14 ) ;
return sprintf ( V_17 , L_1 , F_14 ( V_21 -> V_23 [ V_18 ] ) ) ;
}
static T_2 F_17 ( struct V_13 * V_14 , struct V_15 * V_16 ,
const char * V_17 , T_3 V_25 )
{
int V_18 = F_12 ( V_16 ) -> V_19 ;
struct V_26 * V_27 = F_18 ( V_14 ) ;
struct V_20 * V_21 = F_19 ( V_27 ) ;
unsigned long V_1 ;
int V_28 ;
V_28 = F_20 ( V_17 , 10 , & V_1 ) ;
if ( V_28 )
return V_28 ;
F_21 ( & V_21 -> V_29 ) ;
V_21 -> V_24 [ V_18 ] = F_4 ( V_1 , F_14 ( V_21 -> V_23 [ V_18 ] ) ) ;
F_22 ( V_27 , F_23 ( V_18 ) , V_21 -> V_24 [ V_18 ] ) ;
F_24 ( & V_21 -> V_29 ) ;
return V_25 ;
}
static T_2 F_25 ( struct V_13 * V_14 , struct V_15 * V_16 ,
const char * V_17 , T_3 V_25 )
{
int V_18 = F_12 ( V_16 ) -> V_19 ;
struct V_26 * V_27 = F_18 ( V_14 ) ;
struct V_20 * V_21 = F_19 ( V_27 ) ;
unsigned long V_30 ;
int V_5 ;
unsigned long V_1 ;
int V_28 ;
V_28 = F_20 ( V_17 , 10 , & V_1 ) ;
if ( V_28 )
return V_28 ;
F_21 ( & V_21 -> V_29 ) ;
V_30 = F_5 ( V_21 -> V_24 [ V_18 ] ,
F_14 ( V_21 -> V_23 [ V_18 ] ) ) ;
V_21 -> V_23 [ V_18 ] = F_10 ( V_1 ) ;
switch ( V_18 ) {
case 0 :
V_5 = F_26 ( V_27 , V_31 ) ;
V_5 = ( V_5 & 0xcf ) | ( V_21 -> V_23 [ 0 ] << 4 ) ;
F_22 ( V_27 , V_31 , V_5 ) ;
break;
case 1 :
V_5 = F_26 ( V_27 , V_31 ) ;
V_5 = ( V_5 & 0x3f ) | ( V_21 -> V_23 [ 1 ] << 6 ) ;
F_22 ( V_27 , V_31 , V_5 ) ;
break;
case 2 :
V_5 = F_26 ( V_27 , V_32 ) ;
V_5 = ( V_5 & 0x3f ) | ( V_21 -> V_23 [ 2 ] << 6 ) ;
F_22 ( V_27 , V_32 , V_5 ) ;
break;
}
V_21 -> V_24 [ V_18 ] =
F_4 ( V_30 , F_14 ( V_21 -> V_23 [ V_18 ] ) ) ;
F_22 ( V_27 , F_23 ( V_18 ) , V_21 -> V_24 [ V_18 ] ) ;
F_24 ( & V_21 -> V_29 ) ;
return V_25 ;
}
static int F_27 ( T_4 V_5 , char * V_17 , int V_18 )
{
int V_33 = 0 ;
switch ( V_18 ) {
case 1 : case 2 :
V_33 = sprintf ( V_17 , L_1 , F_28 ( V_5 ) ) ;
break;
case 0 : case 3 : default:
V_33 = sprintf ( V_17 , L_1 , F_7 ( V_5 ) ) ;
break;
}
return V_33 ;
}
static T_2 F_29 ( struct V_13 * V_14 , struct V_15 * V_16 ,
char * V_17 )
{
struct V_20 * V_21 = F_13 ( V_14 ) ;
return sprintf ( V_17 , L_1 , F_30 ( V_21 -> V_34 , V_21 -> V_35 ) ) ;
}
static T_2 F_31 ( struct V_13 * V_14 , struct V_15 * V_16 ,
char * V_17 )
{
struct V_20 * V_21 = F_32 ( V_14 ) ;
return sprintf ( V_17 , L_1 , V_21 -> V_35 ) ;
}
static T_2 F_33 ( struct V_13 * V_14 , struct V_15 * V_16 ,
const char * V_17 , T_3 V_25 )
{
struct V_20 * V_21 = F_32 ( V_14 ) ;
unsigned long V_1 ;
int V_28 ;
V_28 = F_20 ( V_17 , 10 , & V_1 ) ;
if ( V_28 )
return V_28 ;
V_21 -> V_35 = V_1 ;
return V_25 ;
}
static T_2 F_34 ( struct V_13 * V_14 , struct V_15 * V_16 ,
char * V_17 )
{
struct V_20 * V_21 = F_13 ( V_14 ) ;
return sprintf ( V_17 , L_2 , V_21 -> V_36 ) ;
}
static T_2 F_35 ( struct V_13 * V_14 , struct V_15 * V_16 ,
char * V_17 )
{
int V_37 = F_12 ( V_16 ) -> V_19 ;
struct V_20 * V_21 = F_13 ( V_14 ) ;
return sprintf ( V_17 , L_2 , ( V_21 -> V_36 >> V_37 ) & 1 ) ;
}
static T_2 F_36 ( struct V_13 * V_14 , struct V_15 * V_16 ,
char * V_17 )
{
struct V_20 * V_21 = F_13 ( V_14 ) ;
return sprintf ( V_17 , L_1 , F_9 ( V_21 -> V_12 & 0x0f ) ) ;
}
static T_2 F_37 ( struct V_13 * V_14 , struct V_15 * V_16 ,
const char * V_17 , T_3 V_25 )
{
struct V_26 * V_27 = F_18 ( V_14 ) ;
struct V_20 * V_21 = F_19 ( V_27 ) ;
unsigned long V_1 ;
int V_28 ;
V_28 = F_20 ( V_17 , 10 , & V_1 ) ;
if ( V_28 )
return V_28 ;
F_21 ( & V_21 -> V_29 ) ;
V_21 -> V_12 &= 0x80 ;
V_21 -> V_12 |= ( 0x0f & F_8 ( V_1 ) ) ;
F_22 ( V_27 , V_38 , V_21 -> V_12 ) ;
F_24 ( & V_21 -> V_29 ) ;
return V_25 ;
}
static T_2 F_38 ( struct V_13 * V_14 ,
struct V_15 * V_16 , char * V_17 )
{
struct V_20 * V_21 = F_13 ( V_14 ) ;
return sprintf ( V_17 , L_1 , ( V_21 -> V_12 & 0x80 ) ? 1 : 0 ) ;
}
static T_2 F_39 ( struct V_13 * V_14 ,
struct V_15 * V_16 , const char * V_17 , T_3 V_25 )
{
struct V_26 * V_27 = F_18 ( V_14 ) ;
struct V_20 * V_21 = F_19 ( V_27 ) ;
unsigned long V_1 ;
int V_28 ;
V_28 = F_20 ( V_17 , 10 , & V_1 ) ;
if ( V_28 )
return V_28 ;
F_21 ( & V_21 -> V_29 ) ;
V_21 -> V_12 &= 0x0f ;
V_21 -> V_12 |= ( V_1 ? 0x80 : 0x00 ) ;
F_22 ( V_27 , V_38 , V_21 -> V_12 ) ;
F_24 ( & V_21 -> V_29 ) ;
return V_25 ;
}
static int F_40 ( struct V_26 * V_27 )
{
int V_39 , V_40 , V_28 ;
int V_41 = V_27 -> V_42 ;
unsigned short V_43 [ 2 ] ;
struct V_20 * V_21 = F_19 ( V_27 ) ;
struct V_44 * V_45 = V_27 -> V_45 ;
V_40 = F_41 ( V_45 ) ;
if ( V_46 [ 0 ] == V_40 && V_46 [ 1 ] == V_41 ) {
for ( V_39 = 2 ; V_39 <= 3 ; V_39 ++ ) {
if ( V_46 [ V_39 ] < 0x48 ||
V_46 [ V_39 ] > 0x4f ) {
F_42 ( & V_27 -> V_14 , L_3
L_4 ,
V_46 [ V_39 ] ) ;
V_28 = - V_47 ;
goto V_48;
}
}
F_22 ( V_27 , V_49 ,
( V_46 [ 2 ] & 0x07 ) |
( ( V_46 [ 3 ] & 0x07 ) << 4 ) ) ;
V_43 [ 0 ] = V_46 [ 2 ] ;
V_43 [ 1 ] = V_46 [ 3 ] ;
} else {
int V_1 = F_26 ( V_27 , V_49 ) ;
V_43 [ 0 ] = 0x48 + ( V_1 & 0x07 ) ;
V_43 [ 1 ] = 0x48 + ( ( V_1 >> 4 ) & 0x07 ) ;
}
if ( V_43 [ 0 ] == V_43 [ 1 ] ) {
F_42 ( & V_27 -> V_14 , L_5
L_6 , V_43 [ 0 ] ) ;
V_28 = - V_47 ;
goto V_48;
}
V_21 -> V_50 [ 0 ] = F_43 ( V_45 , V_43 [ 0 ] ) ;
if ( ! V_21 -> V_50 [ 0 ] ) {
F_42 ( & V_27 -> V_14 , L_7
L_8 , 1 , V_43 [ 0 ] ) ;
V_28 = - V_51 ;
goto V_48;
}
V_21 -> V_50 [ 1 ] = F_43 ( V_45 , V_43 [ 1 ] ) ;
if ( ! V_21 -> V_50 [ 1 ] ) {
F_42 ( & V_27 -> V_14 , L_7
L_8 , 2 , V_43 [ 1 ] ) ;
V_28 = - V_51 ;
goto V_52;
}
return 0 ;
V_52:
F_44 ( V_21 -> V_50 [ 0 ] ) ;
V_48:
return V_28 ;
}
static int F_45 ( struct V_26 * V_27 ,
struct V_53 * V_54 )
{
struct V_44 * V_45 = V_27 -> V_45 ;
int V_55 , V_56 ;
if ( ! F_46 ( V_45 , V_57 ) ) {
F_47 ( L_9 ) ;
return - V_47 ;
}
V_55 = F_48 ( V_27 , V_58 ) ;
V_56 = F_48 ( V_27 , V_59 ) ;
if ( ( ! ( V_55 & 0x07 ) ) &&
( ( ( ! ( V_55 & 0x80 ) ) && ( V_56 != 0x94 ) ) ||
( ( V_55 & 0x80 ) && ( V_56 != 0x06 ) ) ) ) {
F_47 ( L_10 , V_56 ) ;
return - V_47 ;
}
F_49 ( V_27 , V_58 ,
( F_48 ( V_27 , V_58 ) & 0x78 )
| 0x80 ) ;
V_55 = F_48 ( V_27 , V_60 ) ;
V_56 = F_48 ( V_27 , V_59 ) ;
if ( V_55 != 0x31 || V_56 != 0x06 )
return - V_47 ;
F_50 ( V_54 -> type , L_11 , V_61 ) ;
return 0 ;
}
static int F_51 ( struct V_26 * V_27 ,
const struct V_62 * V_40 )
{
int V_28 ;
struct V_20 * V_21 ;
V_21 = F_52 ( sizeof( struct V_20 ) , V_63 ) ;
if ( ! V_21 ) {
F_47 ( L_12 ) ;
V_28 = - V_51 ;
goto V_64;
}
F_53 ( V_27 , V_21 ) ;
F_54 ( & V_21 -> V_65 ) ;
F_54 ( & V_21 -> V_29 ) ;
V_28 = F_40 ( V_27 ) ;
if ( V_28 )
goto V_66;
F_55 ( V_27 ) ;
V_21 -> V_24 [ 0 ] = F_26 ( V_27 , F_23 ( 0 ) ) ;
V_21 -> V_24 [ 1 ] = F_26 ( V_27 , F_23 ( 1 ) ) ;
V_21 -> V_24 [ 2 ] = F_26 ( V_27 , F_23 ( 2 ) ) ;
V_28 = F_56 ( & V_27 -> V_14 . V_67 , & V_68 ) ;
if ( V_28 )
goto V_69;
V_21 -> V_70 = F_57 ( & V_27 -> V_14 ) ;
if ( F_58 ( V_21 -> V_70 ) ) {
V_28 = F_59 ( V_21 -> V_70 ) ;
goto V_71;
}
return 0 ;
V_71:
F_60 ( & V_27 -> V_14 . V_67 , & V_68 ) ;
V_69:
F_44 ( V_21 -> V_50 [ 1 ] ) ;
F_44 ( V_21 -> V_50 [ 0 ] ) ;
V_66:
F_61 ( V_21 ) ;
V_64:
return V_28 ;
}
static int F_62 ( struct V_26 * V_27 )
{
struct V_20 * V_21 = F_19 ( V_27 ) ;
F_63 ( V_21 -> V_70 ) ;
F_60 ( & V_27 -> V_14 . V_67 , & V_68 ) ;
F_44 ( V_21 -> V_50 [ 1 ] ) ;
F_44 ( V_21 -> V_50 [ 0 ] ) ;
F_61 ( V_21 ) ;
return 0 ;
}
static int F_26 ( struct V_26 * V_27 , T_4 V_5 )
{
struct V_20 * V_21 = F_19 ( V_27 ) ;
struct V_26 * V_72 ;
int V_73 , V_74 ;
F_21 ( & V_21 -> V_65 ) ;
V_74 = ( V_5 >> 8 ) & 0x0f ;
if ( V_74 > 2 )
F_49 ( V_27 , V_58 , V_74 ) ;
if ( V_74 == 0 || V_74 > 2 ) {
V_73 = F_48 ( V_27 , V_5 & 0xff ) ;
} else {
V_72 = V_21 -> V_50 [ V_74 - 1 ] ;
switch ( V_5 & 0xff ) {
case 0x50 :
V_73 = F_64 ( V_72 , 0 ) ;
break;
case 0x52 :
V_73 = F_48 ( V_72 , 1 ) ;
break;
case 0x53 :
V_73 = F_64 ( V_72 , 2 ) ;
break;
case 0x55 :
default:
V_73 = F_64 ( V_72 , 3 ) ;
break;
}
}
if ( V_74 > 2 )
F_49 ( V_27 , V_58 , 0 ) ;
F_24 ( & V_21 -> V_65 ) ;
return V_73 ;
}
static void F_22 ( struct V_26 * V_27 , T_4 V_5 , T_4 V_75 )
{
struct V_20 * V_21 = F_19 ( V_27 ) ;
struct V_26 * V_72 ;
int V_74 ;
F_21 ( & V_21 -> V_65 ) ;
V_74 = ( V_5 >> 8 ) & 0x0f ;
if ( V_74 > 2 )
F_49 ( V_27 , V_58 , V_74 ) ;
if ( V_74 == 0 || V_74 > 2 ) {
F_49 ( V_27 , V_5 & 0xff , V_75 & 0xff ) ;
} else {
V_72 = V_21 -> V_50 [ V_74 - 1 ] ;
switch ( V_5 & 0xff ) {
case 0x52 :
F_49 ( V_72 , 1 , V_75 & 0xff ) ;
break;
case 0x53 :
F_65 ( V_72 , 2 , V_75 ) ;
break;
case 0x55 :
F_65 ( V_72 , 3 , V_75 ) ;
break;
}
}
if ( V_74 > 2 )
F_49 ( V_27 , V_58 , 0 ) ;
F_24 ( & V_21 -> V_65 ) ;
}
static void F_55 ( struct V_26 * V_27 )
{
struct V_20 * V_21 = F_19 ( V_27 ) ;
V_21 -> V_35 = F_66 () ;
F_22 ( V_27 , V_76 ,
( F_26 ( V_27 , V_76 ) & 0xf7 ) | 0x01 ) ;
}
static struct V_20 * F_13 ( struct V_13 * V_14 )
{
struct V_26 * V_27 = F_18 ( V_14 ) ;
struct V_20 * V_21 = F_19 ( V_27 ) ;
int V_39 ;
F_21 ( & V_21 -> V_29 ) ;
if ( F_67 ( V_77 , V_21 -> V_78 + V_79 + V_79 / 2 )
|| ! V_21 -> V_80 ) {
F_68 ( & V_27 -> V_14 , L_13 ) ;
for ( V_39 = 0 ; V_39 < 7 ; V_39 ++ ) {
V_21 -> V_81 [ V_39 ] = F_26 ( V_27 ,
F_69 ( V_39 ) ) ;
V_21 -> V_82 [ V_39 ] = F_26 ( V_27 ,
F_70 ( V_39 ) ) ;
V_21 -> V_83 [ V_39 ] = F_26 ( V_27 ,
F_71 ( V_39 ) ) ;
}
for ( V_39 = 0 ; V_39 < 3 ; V_39 ++ ) {
V_21 -> V_22 [ V_39 ] = F_26 ( V_27 ,
F_72 ( V_39 ) ) ;
V_21 -> V_24 [ V_39 ] = F_26 ( V_27 ,
F_23 ( V_39 ) ) ;
}
for ( V_39 = 1 ; V_39 <= 4 ; V_39 ++ ) {
V_21 -> V_7 [ V_39 - 1 ] = F_26 ( V_27 ,
F_73 ( V_39 ) ) ;
V_21 -> V_84 [ V_39 - 1 ] = F_26 ( V_27 ,
F_74 ( V_39 ) ) ;
V_21 -> V_85 [ V_39 - 1 ] = F_26 ( V_27 ,
F_75 ( V_39 ) ) ;
}
V_39 = F_26 ( V_27 , V_31 ) ;
V_21 -> V_34 = V_39 & 0x0f ;
V_21 -> V_34 |= ( F_26 ( V_27 ,
V_86 ) & 0x01 ) << 4 ;
V_21 -> V_23 [ 0 ] = ( V_39 >> 4 ) & 0x03 ;
V_21 -> V_23 [ 1 ] = ( V_39 >> 6 ) & 0x03 ;
V_21 -> V_23 [ 2 ] = ( F_26 ( V_27 ,
V_32 ) >> 6 ) & 0x03 ;
V_21 -> V_12 = F_26 ( V_27 , V_38 ) ;
V_21 -> V_36 = F_26 ( V_27 , V_87 ) +
( F_26 ( V_27 , V_88 ) << 8 ) ;
V_21 -> V_78 = V_77 ;
V_21 -> V_80 = 1 ;
F_68 ( & V_27 -> V_14 , L_14 ) ;
}
F_24 ( & V_21 -> V_29 ) ;
return V_21 ;
}
