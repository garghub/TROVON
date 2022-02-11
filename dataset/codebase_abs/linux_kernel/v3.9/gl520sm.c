static T_1 F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
return sprintf ( V_5 , L_1 , F_3 ( V_7 -> V_8 , V_7 -> V_9 ) ) ;
}
static T_1 F_4 ( struct V_1 * V_2 , struct V_3 * V_4 ,
char * V_5 )
{
int V_10 = F_5 ( V_4 ) -> V_11 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
T_2 V_12 = V_7 -> V_13 [ V_10 ] ;
if ( V_10 == 0 )
return sprintf ( V_5 , L_2 , F_6 ( V_12 ) ) ;
else
return sprintf ( V_5 , L_2 , F_7 ( V_12 ) ) ;
}
static T_1 F_8 ( struct V_1 * V_2 , struct V_3 * V_4 ,
char * V_5 )
{
int V_10 = F_5 ( V_4 ) -> V_11 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
T_2 V_12 = V_7 -> V_14 [ V_10 ] ;
if ( V_10 == 0 )
return sprintf ( V_5 , L_2 , F_6 ( V_12 ) ) ;
else
return sprintf ( V_5 , L_2 , F_7 ( V_12 ) ) ;
}
static T_1 F_9 ( struct V_1 * V_2 , struct V_3 * V_4 ,
char * V_5 )
{
int V_10 = F_5 ( V_4 ) -> V_11 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
T_2 V_12 = V_7 -> V_15 [ V_10 ] ;
if ( V_10 == 0 )
return sprintf ( V_5 , L_2 , F_6 ( V_12 ) ) ;
else
return sprintf ( V_5 , L_2 , F_7 ( V_12 ) ) ;
}
static T_1 F_10 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const char * V_5 , T_3 V_16 )
{
struct V_17 * V_18 = F_11 ( V_2 ) ;
struct V_6 * V_7 = F_12 ( V_18 ) ;
int V_10 = F_5 ( V_4 ) -> V_11 ;
T_2 V_12 ;
long V_19 ;
int V_20 ;
V_20 = F_13 ( V_5 , 10 , & V_19 ) ;
if ( V_20 )
return V_20 ;
F_14 ( & V_7 -> V_21 ) ;
if ( V_10 == 0 )
V_12 = F_15 ( V_19 ) ;
else
V_12 = F_16 ( V_19 ) ;
V_7 -> V_14 [ V_10 ] = V_12 ;
if ( V_10 < 4 )
F_17 ( V_18 , V_22 [ V_10 ] ,
( F_18 ( V_18 , V_22 [ V_10 ] )
& ~ 0xff ) | V_12 ) ;
else
F_17 ( V_18 , V_22 [ V_10 ] , V_12 ) ;
F_19 ( & V_7 -> V_21 ) ;
return V_16 ;
}
static T_1 F_20 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const char * V_5 , T_3 V_16 )
{
struct V_17 * V_18 = F_11 ( V_2 ) ;
struct V_6 * V_7 = F_12 ( V_18 ) ;
int V_10 = F_5 ( V_4 ) -> V_11 ;
T_2 V_12 ;
long V_19 ;
int V_20 ;
V_20 = F_13 ( V_5 , 10 , & V_19 ) ;
if ( V_20 )
return V_20 ;
if ( V_10 == 0 )
V_12 = F_15 ( V_19 ) ;
else
V_12 = F_16 ( V_19 ) ;
F_14 ( & V_7 -> V_21 ) ;
V_7 -> V_15 [ V_10 ] = V_12 ;
if ( V_10 < 4 )
F_17 ( V_18 , V_23 [ V_10 ] ,
( F_18 ( V_18 , V_23 [ V_10 ] )
& ~ 0xff00 ) | ( V_12 << 8 ) ) ;
else
F_17 ( V_18 , V_23 [ V_10 ] , V_12 ) ;
F_19 ( & V_7 -> V_21 ) ;
return V_16 ;
}
static T_1 F_21 ( struct V_1 * V_2 , struct V_3 * V_4 ,
char * V_5 )
{
int V_10 = F_5 ( V_4 ) -> V_11 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
return sprintf ( V_5 , L_2 , F_22 ( V_7 -> V_24 [ V_10 ] ,
V_7 -> V_25 [ V_10 ] ) ) ;
}
static T_1 F_23 ( struct V_1 * V_2 , struct V_3 * V_4 ,
char * V_5 )
{
int V_10 = F_5 ( V_4 ) -> V_11 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
return sprintf ( V_5 , L_2 , F_22 ( V_7 -> V_26 [ V_10 ] ,
V_7 -> V_25 [ V_10 ] ) ) ;
}
static T_1 F_24 ( struct V_1 * V_2 , struct V_3 * V_4 ,
char * V_5 )
{
int V_10 = F_5 ( V_4 ) -> V_11 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
return sprintf ( V_5 , L_2 , F_25 ( V_7 -> V_25 [ V_10 ] ) ) ;
}
static T_1 F_26 ( struct V_1 * V_2 , struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
return sprintf ( V_5 , L_2 , V_7 -> V_27 ) ;
}
static T_1 F_27 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const char * V_5 , T_3 V_16 )
{
struct V_17 * V_18 = F_11 ( V_2 ) ;
struct V_6 * V_7 = F_12 ( V_18 ) ;
int V_10 = F_5 ( V_4 ) -> V_11 ;
T_2 V_12 ;
unsigned long V_19 ;
int V_20 ;
V_20 = F_28 ( V_5 , 10 , & V_19 ) ;
if ( V_20 )
return V_20 ;
F_14 ( & V_7 -> V_21 ) ;
V_12 = F_29 ( V_19 , V_7 -> V_25 [ V_10 ] ) ;
V_7 -> V_26 [ V_10 ] = V_12 ;
if ( V_10 == 0 )
F_17 ( V_18 , V_28 ,
( F_18 ( V_18 , V_28 )
& ~ 0xff00 ) | ( V_12 << 8 ) ) ;
else
F_17 ( V_18 , V_28 ,
( F_18 ( V_18 , V_28 )
& ~ 0xff ) | V_12 ) ;
V_7 -> V_29 = F_18 ( V_18 , V_30 ) ;
if ( V_7 -> V_26 [ V_10 ] == 0 )
V_7 -> V_31 &= ( V_10 == 0 ) ? ~ 0x20 : ~ 0x40 ;
else
V_7 -> V_31 |= ( V_10 == 0 ) ? 0x20 : 0x40 ;
V_7 -> V_29 &= V_7 -> V_31 ;
F_17 ( V_18 , V_30 , V_7 -> V_29 ) ;
F_19 ( & V_7 -> V_21 ) ;
return V_16 ;
}
static T_1 F_30 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const char * V_5 , T_3 V_16 )
{
struct V_17 * V_18 = F_11 ( V_2 ) ;
struct V_6 * V_7 = F_12 ( V_18 ) ;
int V_10 = F_5 ( V_4 ) -> V_11 ;
T_2 V_12 ;
unsigned long V_19 ;
int V_20 ;
V_20 = F_28 ( V_5 , 10 , & V_19 ) ;
if ( V_20 )
return V_20 ;
switch ( V_19 ) {
case 1 :
V_12 = 0 ;
break;
case 2 :
V_12 = 1 ;
break;
case 4 :
V_12 = 2 ;
break;
case 8 :
V_12 = 3 ;
break;
default:
F_31 ( & V_18 -> V_2 ,
L_3 , V_19 ) ;
return - V_32 ;
}
F_14 ( & V_7 -> V_21 ) ;
V_7 -> V_25 [ V_10 ] = V_12 ;
if ( V_10 == 0 )
F_17 ( V_18 , V_33 ,
( F_18 ( V_18 , V_33 )
& ~ 0xc0 ) | ( V_12 << 6 ) ) ;
else
F_17 ( V_18 , V_33 ,
( F_18 ( V_18 , V_33 )
& ~ 0x30 ) | ( V_12 << 4 ) ) ;
F_19 ( & V_7 -> V_21 ) ;
return V_16 ;
}
static T_1 F_32 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const char * V_5 , T_3 V_16 )
{
struct V_17 * V_18 = F_11 ( V_2 ) ;
struct V_6 * V_7 = F_12 ( V_18 ) ;
T_2 V_12 ;
unsigned long V_19 ;
int V_20 ;
V_20 = F_28 ( V_5 , 10 , & V_19 ) ;
if ( V_20 )
return V_20 ;
V_12 = ( V_19 ? 1 : 0 ) ;
F_14 ( & V_7 -> V_21 ) ;
V_7 -> V_27 = V_12 ;
F_17 ( V_18 , V_34 ,
( F_18 ( V_18 , V_34 )
& ~ 0x0c ) | ( V_12 << 2 ) ) ;
F_19 ( & V_7 -> V_21 ) ;
return V_16 ;
}
static T_1 F_33 ( struct V_1 * V_2 , struct V_3 * V_4 ,
char * V_5 )
{
int V_10 = F_5 ( V_4 ) -> V_11 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
return sprintf ( V_5 , L_2 , F_34 ( V_7 -> V_35 [ V_10 ] ) ) ;
}
static T_1 F_35 ( struct V_1 * V_2 , struct V_3 * V_4 ,
char * V_5 )
{
int V_10 = F_5 ( V_4 ) -> V_11 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
return sprintf ( V_5 , L_2 , F_34 ( V_7 -> V_36 [ V_10 ] ) ) ;
}
static T_1 F_36 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
int V_10 = F_5 ( V_4 ) -> V_11 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
return sprintf ( V_5 , L_2 , F_34 ( V_7 -> V_37 [ V_10 ] ) ) ;
}
static T_1 F_37 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const char * V_5 , T_3 V_16 )
{
struct V_17 * V_18 = F_11 ( V_2 ) ;
struct V_6 * V_7 = F_12 ( V_18 ) ;
int V_10 = F_5 ( V_4 ) -> V_11 ;
long V_19 ;
int V_20 ;
V_20 = F_13 ( V_5 , 10 , & V_19 ) ;
if ( V_20 )
return V_20 ;
F_14 ( & V_7 -> V_21 ) ;
V_7 -> V_36 [ V_10 ] = F_38 ( V_19 ) ;
F_17 ( V_18 , V_38 [ V_10 ] , V_7 -> V_36 [ V_10 ] ) ;
F_19 ( & V_7 -> V_21 ) ;
return V_16 ;
}
static T_1 F_39 ( struct V_1 * V_2 , struct V_3
* V_4 , const char * V_5 , T_3 V_16 )
{
struct V_17 * V_18 = F_11 ( V_2 ) ;
struct V_6 * V_7 = F_12 ( V_18 ) ;
int V_10 = F_5 ( V_4 ) -> V_11 ;
long V_19 ;
int V_20 ;
V_20 = F_13 ( V_5 , 10 , & V_19 ) ;
if ( V_20 )
return V_20 ;
F_14 ( & V_7 -> V_21 ) ;
V_7 -> V_37 [ V_10 ] = F_38 ( V_19 ) ;
F_17 ( V_18 , V_39 [ V_10 ] ,
V_7 -> V_37 [ V_10 ] ) ;
F_19 ( & V_7 -> V_21 ) ;
return V_16 ;
}
static T_1 F_40 ( struct V_1 * V_2 , struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
return sprintf ( V_5 , L_2 , V_7 -> V_40 ) ;
}
static T_1 F_41 ( struct V_1 * V_2 , struct V_3
* V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
return sprintf ( V_5 , L_2 , V_7 -> V_41 ) ;
}
static T_1 F_42 ( struct V_1 * V_2 , struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
return sprintf ( V_5 , L_2 , V_7 -> V_29 ) ;
}
static T_1 F_43 ( struct V_1 * V_2 , struct V_3
* V_4 , const char * V_5 , T_3 V_16 )
{
struct V_17 * V_18 = F_11 ( V_2 ) ;
struct V_6 * V_7 = F_12 ( V_18 ) ;
T_2 V_12 ;
unsigned long V_19 ;
int V_20 ;
V_20 = F_28 ( V_5 , 10 , & V_19 ) ;
if ( V_20 )
return V_20 ;
V_12 = ( V_19 ? 0 : 1 ) ;
F_14 ( & V_7 -> V_21 ) ;
V_7 -> V_41 = ! V_12 ;
F_17 ( V_18 , V_42 ,
( F_18 ( V_18 , V_42 )
& ~ 0x04 ) | ( V_12 << 2 ) ) ;
F_19 ( & V_7 -> V_21 ) ;
return V_16 ;
}
static T_1 F_44 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const char * V_5 , T_3 V_16 )
{
struct V_17 * V_18 = F_11 ( V_2 ) ;
struct V_6 * V_7 = F_12 ( V_18 ) ;
unsigned long V_12 ;
int V_20 ;
V_20 = F_28 ( V_5 , 10 , & V_12 ) ;
if ( V_20 )
return V_20 ;
F_14 ( & V_7 -> V_21 ) ;
V_12 &= V_7 -> V_31 ;
V_7 -> V_29 = V_12 ;
F_17 ( V_18 , V_30 , V_12 ) ;
F_19 ( & V_7 -> V_21 ) ;
return V_16 ;
}
static T_1 F_45 ( struct V_1 * V_2 , struct V_3 * V_4 ,
char * V_5 )
{
int V_43 = F_5 ( V_4 ) -> V_11 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
return sprintf ( V_5 , L_2 , ( V_7 -> V_40 >> V_43 ) & 1 ) ;
}
static T_1 F_46 ( struct V_1 * V_2 , struct V_3 * V_4 ,
char * V_5 )
{
int V_44 = F_5 ( V_4 ) -> V_11 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
return sprintf ( V_5 , L_2 , ( V_7 -> V_29 >> V_44 ) & 1 ) ;
}
static T_1 F_47 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const char * V_5 , T_3 V_16 )
{
struct V_17 * V_18 = F_11 ( V_2 ) ;
struct V_6 * V_7 = F_12 ( V_18 ) ;
int V_44 = F_5 ( V_4 ) -> V_11 ;
unsigned long V_45 ;
int V_20 ;
V_20 = F_28 ( V_5 , 10 , & V_45 ) ;
if ( V_20 )
return V_20 ;
if ( V_45 & ~ 1 )
return - V_32 ;
F_14 ( & V_7 -> V_21 ) ;
V_7 -> V_29 = F_18 ( V_18 , V_30 ) ;
if ( V_45 )
V_7 -> V_29 |= ( 1 << V_44 ) ;
else
V_7 -> V_29 &= ~ ( 1 << V_44 ) ;
F_17 ( V_18 , V_30 , V_7 -> V_29 ) ;
F_19 ( & V_7 -> V_21 ) ;
return V_16 ;
}
static int F_48 ( struct V_17 * V_18 , struct V_46 * V_47 )
{
struct V_48 * V_49 = V_18 -> V_49 ;
if ( ! F_49 ( V_49 , V_50 |
V_51 ) )
return - V_52 ;
if ( ( F_18 ( V_18 , V_53 ) != 0x20 ) ||
( ( F_18 ( V_18 , V_54 ) & 0x7f ) != 0x00 ) ||
( ( F_18 ( V_18 , V_55 ) & 0x80 ) != 0x00 ) ) {
F_50 ( & V_18 -> V_2 , L_4 ) ;
return - V_52 ;
}
F_51 ( V_47 -> type , L_5 , V_56 ) ;
return 0 ;
}
static int F_52 ( struct V_17 * V_18 ,
const struct V_57 * V_58 )
{
struct V_6 * V_7 ;
int V_20 ;
V_7 = F_53 ( & V_18 -> V_2 , sizeof( struct V_6 ) ,
V_59 ) ;
if ( ! V_7 )
return - V_60 ;
F_54 ( V_18 , V_7 ) ;
F_55 ( & V_7 -> V_21 ) ;
F_56 ( V_18 ) ;
V_20 = F_57 ( & V_18 -> V_2 . V_61 , & V_62 ) ;
if ( V_20 )
return V_20 ;
if ( V_7 -> V_63 )
V_20 = F_57 ( & V_18 -> V_2 . V_61 , & V_64 ) ;
else
V_20 = F_57 ( & V_18 -> V_2 . V_61 , & V_65 ) ;
if ( V_20 )
goto V_66;
V_7 -> V_67 = F_58 ( & V_18 -> V_2 ) ;
if ( F_59 ( V_7 -> V_67 ) ) {
V_20 = F_60 ( V_7 -> V_67 ) ;
goto V_66;
}
return 0 ;
V_66:
F_61 ( & V_18 -> V_2 . V_61 , & V_62 ) ;
F_61 ( & V_18 -> V_2 . V_61 , & V_65 ) ;
F_61 ( & V_18 -> V_2 . V_61 , & V_64 ) ;
return V_20 ;
}
static void F_56 ( struct V_17 * V_18 )
{
struct V_6 * V_7 = F_12 ( V_18 ) ;
T_2 V_68 , V_69 ;
V_69 = V_68 = F_18 ( V_18 , V_55 ) ;
V_7 -> V_31 = 0xff ;
V_7 -> V_9 = F_62 () ;
if ( V_70 == 1 )
V_69 &= ~ 0x10 ;
else if ( V_70 == 2 )
V_69 |= 0x10 ;
V_7 -> V_63 = ! ( V_69 & 0x10 ) ;
if ( ! ( V_69 & 0x20 ) )
V_69 &= 0xf7 ;
V_69 |= 0x40 ;
if ( V_69 != V_68 )
F_17 ( V_18 , V_55 , V_69 ) ;
F_2 ( & ( V_18 -> V_2 ) ) ;
if ( V_7 -> V_26 [ 0 ] == 0 )
V_7 -> V_31 &= ~ 0x20 ;
if ( V_7 -> V_26 [ 1 ] == 0 )
V_7 -> V_31 &= ~ 0x40 ;
V_7 -> V_29 &= V_7 -> V_31 ;
F_17 ( V_18 , V_30 , V_7 -> V_29 ) ;
}
static int F_63 ( struct V_17 * V_18 )
{
struct V_6 * V_7 = F_12 ( V_18 ) ;
F_64 ( V_7 -> V_67 ) ;
F_61 ( & V_18 -> V_2 . V_61 , & V_62 ) ;
F_61 ( & V_18 -> V_2 . V_61 , & V_65 ) ;
F_61 ( & V_18 -> V_2 . V_61 , & V_64 ) ;
return 0 ;
}
static int F_18 ( struct V_17 * V_18 , T_2 V_71 )
{
if ( ( V_71 >= 0x07 ) && ( V_71 <= 0x0c ) )
return F_65 ( V_18 , V_71 ) ;
else
return F_66 ( V_18 , V_71 ) ;
}
static int F_17 ( struct V_17 * V_18 , T_2 V_71 , T_4 V_72 )
{
if ( ( V_71 >= 0x07 ) && ( V_71 <= 0x0c ) )
return F_67 ( V_18 , V_71 , V_72 ) ;
else
return F_68 ( V_18 , V_71 , V_72 ) ;
}
static struct V_6 * F_2 ( struct V_1 * V_2 )
{
struct V_17 * V_18 = F_11 ( V_2 ) ;
struct V_6 * V_7 = F_12 ( V_18 ) ;
int V_73 , V_74 ;
F_14 ( & V_7 -> V_21 ) ;
if ( F_69 ( V_75 , V_7 -> V_76 + 2 * V_77 ) || ! V_7 -> V_78 ) {
F_50 ( & V_18 -> V_2 , L_6 ) ;
V_7 -> V_40 = F_18 ( V_18 , V_79 ) ;
V_7 -> V_29 = F_18 ( V_18 , V_30 ) ;
V_7 -> V_8 = F_18 ( V_18 ,
V_80 ) & 0x1f ;
for ( V_74 = 0 ; V_74 < 4 ; V_74 ++ ) {
V_7 -> V_13 [ V_74 ] = F_18 ( V_18 ,
V_81 [ V_74 ] ) ;
V_73 = F_18 ( V_18 , V_82 [ V_74 ] ) ;
V_7 -> V_14 [ V_74 ] = V_73 & 0xff ;
V_7 -> V_15 [ V_74 ] = ( V_73 >> 8 ) & 0xff ;
}
V_73 = F_18 ( V_18 , V_83 ) ;
V_7 -> V_24 [ 0 ] = ( V_73 >> 8 ) & 0xff ;
V_7 -> V_24 [ 1 ] = V_73 & 0xff ;
V_73 = F_18 ( V_18 , V_28 ) ;
V_7 -> V_26 [ 0 ] = ( V_73 >> 8 ) & 0xff ;
V_7 -> V_26 [ 1 ] = V_73 & 0xff ;
V_7 -> V_35 [ 0 ] = F_18 ( V_18 ,
V_84 [ 0 ] ) ;
V_7 -> V_36 [ 0 ] = F_18 ( V_18 ,
V_38 [ 0 ] ) ;
V_7 -> V_37 [ 0 ] = F_18 ( V_18 ,
V_39 [ 0 ] ) ;
V_73 = F_18 ( V_18 , V_33 ) ;
V_7 -> V_25 [ 0 ] = ( V_73 >> 6 ) & 0x03 ;
V_7 -> V_25 [ 1 ] = ( V_73 >> 4 ) & 0x03 ;
V_7 -> V_27 = ( V_73 >> 2 ) & 0x01 ;
V_7 -> V_40 &= V_7 -> V_31 ;
V_73 = F_18 ( V_18 , V_55 ) ;
V_7 -> V_41 = ! ( ( V_73 >> 2 ) & 1 ) ;
if ( V_7 -> V_63 ) {
V_7 -> V_35 [ 1 ] = F_18 ( V_18 ,
V_84 [ 1 ] ) ;
V_7 -> V_36 [ 1 ] = F_18 ( V_18 ,
V_38 [ 1 ] ) ;
V_7 -> V_37 [ 1 ] = F_18 ( V_18 ,
V_39 [ 1 ] ) ;
} else {
V_7 -> V_13 [ 4 ] = F_18 ( V_18 ,
V_81 [ 4 ] ) ;
V_7 -> V_14 [ 4 ] = F_18 ( V_18 ,
V_22 [ 4 ] ) ;
V_7 -> V_15 [ 4 ] = F_18 ( V_18 ,
V_23 [ 4 ] ) ;
}
V_7 -> V_76 = V_75 ;
V_7 -> V_78 = 1 ;
}
F_19 ( & V_7 -> V_21 ) ;
return V_7 ;
}
