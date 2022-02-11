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
if ( V_1 > 255 )
return - V_36 ;
V_21 -> V_35 = V_1 ;
return V_25 ;
}
static T_2 F_34 ( struct V_13 * V_14 , struct V_15 * V_16 ,
char * V_17 )
{
struct V_20 * V_21 = F_13 ( V_14 ) ;
return sprintf ( V_17 , L_2 , V_21 -> V_37 ) ;
}
static T_2 F_35 ( struct V_13 * V_14 , struct V_15 * V_16 ,
char * V_17 )
{
int V_38 = F_12 ( V_16 ) -> V_19 ;
struct V_20 * V_21 = F_13 ( V_14 ) ;
return sprintf ( V_17 , L_2 , ( V_21 -> V_37 >> V_38 ) & 1 ) ;
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
F_22 ( V_27 , V_39 , V_21 -> V_12 ) ;
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
F_22 ( V_27 , V_39 , V_21 -> V_12 ) ;
F_24 ( & V_21 -> V_29 ) ;
return V_25 ;
}
static int F_40 ( struct V_26 * V_27 )
{
int V_40 , V_41 , V_28 ;
int V_42 = V_27 -> V_43 ;
unsigned short V_44 [ 2 ] ;
struct V_20 * V_21 = F_19 ( V_27 ) ;
struct V_45 * V_46 = V_27 -> V_46 ;
V_41 = F_41 ( V_46 ) ;
if ( V_47 [ 0 ] == V_41 && V_47 [ 1 ] == V_42 ) {
for ( V_40 = 2 ; V_40 <= 3 ; V_40 ++ ) {
if ( V_47 [ V_40 ] < 0x48 ||
V_47 [ V_40 ] > 0x4f ) {
F_42 ( & V_27 -> V_14 ,
L_3 ,
V_47 [ V_40 ] ) ;
V_28 = - V_48 ;
goto V_49;
}
}
F_22 ( V_27 , V_50 ,
( V_47 [ 2 ] & 0x07 ) |
( ( V_47 [ 3 ] & 0x07 ) << 4 ) ) ;
V_44 [ 0 ] = V_47 [ 2 ] ;
V_44 [ 1 ] = V_47 [ 3 ] ;
} else {
int V_1 = F_26 ( V_27 , V_50 ) ;
V_44 [ 0 ] = 0x48 + ( V_1 & 0x07 ) ;
V_44 [ 1 ] = 0x48 + ( ( V_1 >> 4 ) & 0x07 ) ;
}
if ( V_44 [ 0 ] == V_44 [ 1 ] ) {
F_42 ( & V_27 -> V_14 ,
L_4 ,
V_44 [ 0 ] ) ;
V_28 = - V_48 ;
goto V_49;
}
V_21 -> V_51 [ 0 ] = F_43 ( V_46 , V_44 [ 0 ] ) ;
if ( ! V_21 -> V_51 [ 0 ] ) {
F_42 ( & V_27 -> V_14 ,
L_5 ,
1 , V_44 [ 0 ] ) ;
V_28 = - V_52 ;
goto V_49;
}
V_21 -> V_51 [ 1 ] = F_43 ( V_46 , V_44 [ 1 ] ) ;
if ( ! V_21 -> V_51 [ 1 ] ) {
F_42 ( & V_27 -> V_14 ,
L_5 ,
2 , V_44 [ 1 ] ) ;
V_28 = - V_52 ;
goto V_53;
}
return 0 ;
V_53:
F_44 ( V_21 -> V_51 [ 0 ] ) ;
V_49:
return V_28 ;
}
static int F_45 ( struct V_26 * V_27 ,
struct V_54 * V_55 )
{
struct V_45 * V_46 = V_27 -> V_46 ;
int V_56 , V_57 ;
if ( ! F_46 ( V_46 , V_58 ) ) {
F_47 ( L_6 ) ;
return - V_48 ;
}
V_56 = F_48 ( V_27 , V_59 ) ;
V_57 = F_48 ( V_27 , V_60 ) ;
if ( ( ! ( V_56 & 0x07 ) ) &&
( ( ( ! ( V_56 & 0x80 ) ) && ( V_57 != 0x94 ) ) ||
( ( V_56 & 0x80 ) && ( V_57 != 0x06 ) ) ) ) {
F_47 ( L_7 , V_57 ) ;
return - V_48 ;
}
F_49 ( V_27 , V_59 ,
( F_48 ( V_27 , V_59 ) & 0x78 )
| 0x80 ) ;
V_56 = F_48 ( V_27 , V_61 ) ;
V_57 = F_48 ( V_27 , V_60 ) ;
if ( V_56 != 0x31 || V_57 != 0x06 )
return - V_48 ;
F_50 ( V_55 -> type , L_8 , V_62 ) ;
return 0 ;
}
static int F_51 ( struct V_26 * V_27 ,
const struct V_63 * V_41 )
{
int V_28 ;
struct V_20 * V_21 ;
V_21 = F_52 ( & V_27 -> V_14 , sizeof( struct V_20 ) ,
V_64 ) ;
if ( ! V_21 )
return - V_52 ;
F_53 ( V_27 , V_21 ) ;
F_54 ( & V_21 -> V_65 ) ;
F_54 ( & V_21 -> V_29 ) ;
V_28 = F_40 ( V_27 ) ;
if ( V_28 )
return V_28 ;
F_55 ( V_27 ) ;
V_21 -> V_24 [ 0 ] = F_26 ( V_27 , F_23 ( 0 ) ) ;
V_21 -> V_24 [ 1 ] = F_26 ( V_27 , F_23 ( 1 ) ) ;
V_21 -> V_24 [ 2 ] = F_26 ( V_27 , F_23 ( 2 ) ) ;
V_28 = F_56 ( & V_27 -> V_14 . V_66 , & V_67 ) ;
if ( V_28 )
goto V_68;
V_21 -> V_69 = F_57 ( & V_27 -> V_14 ) ;
if ( F_58 ( V_21 -> V_69 ) ) {
V_28 = F_59 ( V_21 -> V_69 ) ;
goto V_70;
}
return 0 ;
V_70:
F_60 ( & V_27 -> V_14 . V_66 , & V_67 ) ;
V_68:
F_44 ( V_21 -> V_51 [ 1 ] ) ;
F_44 ( V_21 -> V_51 [ 0 ] ) ;
return V_28 ;
}
static int F_61 ( struct V_26 * V_27 )
{
struct V_20 * V_21 = F_19 ( V_27 ) ;
F_62 ( V_21 -> V_69 ) ;
F_60 ( & V_27 -> V_14 . V_66 , & V_67 ) ;
F_44 ( V_21 -> V_51 [ 1 ] ) ;
F_44 ( V_21 -> V_51 [ 0 ] ) ;
return 0 ;
}
static int F_26 ( struct V_26 * V_27 , T_4 V_5 )
{
struct V_20 * V_21 = F_19 ( V_27 ) ;
struct V_26 * V_71 ;
int V_72 , V_73 ;
F_21 ( & V_21 -> V_65 ) ;
V_73 = ( V_5 >> 8 ) & 0x0f ;
if ( V_73 > 2 )
F_49 ( V_27 , V_59 , V_73 ) ;
if ( V_73 == 0 || V_73 > 2 ) {
V_72 = F_48 ( V_27 , V_5 & 0xff ) ;
} else {
V_71 = V_21 -> V_51 [ V_73 - 1 ] ;
switch ( V_5 & 0xff ) {
case 0x50 :
V_72 = F_63 ( V_71 , 0 ) ;
break;
case 0x52 :
V_72 = F_48 ( V_71 , 1 ) ;
break;
case 0x53 :
V_72 = F_63 ( V_71 , 2 ) ;
break;
case 0x55 :
default:
V_72 = F_63 ( V_71 , 3 ) ;
break;
}
}
if ( V_73 > 2 )
F_49 ( V_27 , V_59 , 0 ) ;
F_24 ( & V_21 -> V_65 ) ;
return V_72 ;
}
static void F_22 ( struct V_26 * V_27 , T_4 V_5 , T_4 V_74 )
{
struct V_20 * V_21 = F_19 ( V_27 ) ;
struct V_26 * V_71 ;
int V_73 ;
F_21 ( & V_21 -> V_65 ) ;
V_73 = ( V_5 >> 8 ) & 0x0f ;
if ( V_73 > 2 )
F_49 ( V_27 , V_59 , V_73 ) ;
if ( V_73 == 0 || V_73 > 2 ) {
F_49 ( V_27 , V_5 & 0xff , V_74 & 0xff ) ;
} else {
V_71 = V_21 -> V_51 [ V_73 - 1 ] ;
switch ( V_5 & 0xff ) {
case 0x52 :
F_49 ( V_71 , 1 , V_74 & 0xff ) ;
break;
case 0x53 :
F_64 ( V_71 , 2 , V_74 ) ;
break;
case 0x55 :
F_64 ( V_71 , 3 , V_74 ) ;
break;
}
}
if ( V_73 > 2 )
F_49 ( V_27 , V_59 , 0 ) ;
F_24 ( & V_21 -> V_65 ) ;
}
static void F_55 ( struct V_26 * V_27 )
{
struct V_20 * V_21 = F_19 ( V_27 ) ;
V_21 -> V_35 = F_65 () ;
F_22 ( V_27 , V_75 ,
( F_26 ( V_27 , V_75 ) & 0xf7 ) | 0x01 ) ;
}
static struct V_20 * F_13 ( struct V_13 * V_14 )
{
struct V_26 * V_27 = F_18 ( V_14 ) ;
struct V_20 * V_21 = F_19 ( V_27 ) ;
int V_40 ;
F_21 ( & V_21 -> V_29 ) ;
if ( F_66 ( V_76 , V_21 -> V_77 + V_78 + V_78 / 2 )
|| ! V_21 -> V_79 ) {
F_67 ( & V_27 -> V_14 , L_9 ) ;
for ( V_40 = 0 ; V_40 < 7 ; V_40 ++ ) {
V_21 -> V_80 [ V_40 ] = F_26 ( V_27 ,
F_68 ( V_40 ) ) ;
V_21 -> V_81 [ V_40 ] = F_26 ( V_27 ,
F_69 ( V_40 ) ) ;
V_21 -> V_82 [ V_40 ] = F_26 ( V_27 ,
F_70 ( V_40 ) ) ;
}
for ( V_40 = 0 ; V_40 < 3 ; V_40 ++ ) {
V_21 -> V_22 [ V_40 ] = F_26 ( V_27 ,
F_71 ( V_40 ) ) ;
V_21 -> V_24 [ V_40 ] = F_26 ( V_27 ,
F_23 ( V_40 ) ) ;
}
for ( V_40 = 1 ; V_40 <= 4 ; V_40 ++ ) {
V_21 -> V_7 [ V_40 - 1 ] = F_26 ( V_27 ,
F_72 ( V_40 ) ) ;
V_21 -> V_83 [ V_40 - 1 ] = F_26 ( V_27 ,
F_73 ( V_40 ) ) ;
V_21 -> V_84 [ V_40 - 1 ] = F_26 ( V_27 ,
F_74 ( V_40 ) ) ;
}
V_40 = F_26 ( V_27 , V_31 ) ;
V_21 -> V_34 = V_40 & 0x0f ;
V_21 -> V_34 |= ( F_26 ( V_27 ,
V_85 ) & 0x01 ) << 4 ;
V_21 -> V_23 [ 0 ] = ( V_40 >> 4 ) & 0x03 ;
V_21 -> V_23 [ 1 ] = ( V_40 >> 6 ) & 0x03 ;
V_21 -> V_23 [ 2 ] = ( F_26 ( V_27 ,
V_32 ) >> 6 ) & 0x03 ;
V_21 -> V_12 = F_26 ( V_27 , V_39 ) ;
V_21 -> V_37 = F_26 ( V_27 , V_86 ) +
( F_26 ( V_27 , V_87 ) << 8 ) ;
V_21 -> V_77 = V_76 ;
V_21 -> V_79 = 1 ;
F_67 ( & V_27 -> V_14 , L_10 ) ;
}
F_24 ( & V_21 -> V_29 ) ;
return V_21 ;
}
