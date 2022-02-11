static int F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
if ( ( V_3 >= 0x07 ) && ( V_3 <= 0x0c ) )
return F_2 ( V_2 , V_3 ) ;
else
return F_3 ( V_2 , V_3 ) ;
}
static int F_4 ( struct V_1 * V_2 , T_1 V_3 , T_2 V_4 )
{
if ( ( V_3 >= 0x07 ) && ( V_3 <= 0x0c ) )
return F_5 ( V_2 , V_3 , V_4 ) ;
else
return F_6 ( V_2 , V_3 , V_4 ) ;
}
static struct V_5 * F_7 ( struct V_6 * V_7 )
{
struct V_5 * V_8 = F_8 ( V_7 ) ;
struct V_1 * V_2 = V_8 -> V_2 ;
int V_9 , V_10 ;
F_9 ( & V_8 -> V_11 ) ;
if ( F_10 ( V_12 , V_8 -> V_13 + 2 * V_14 ) || ! V_8 -> V_15 ) {
F_11 ( & V_2 -> V_7 , L_1 ) ;
V_8 -> V_16 = F_1 ( V_2 , V_17 ) ;
V_8 -> V_18 = F_1 ( V_2 , V_19 ) ;
V_8 -> V_20 = F_1 ( V_2 ,
V_21 ) & 0x1f ;
for ( V_10 = 0 ; V_10 < 4 ; V_10 ++ ) {
V_8 -> V_22 [ V_10 ] = F_1 ( V_2 ,
V_23 [ V_10 ] ) ;
V_9 = F_1 ( V_2 , V_24 [ V_10 ] ) ;
V_8 -> V_25 [ V_10 ] = V_9 & 0xff ;
V_8 -> V_26 [ V_10 ] = ( V_9 >> 8 ) & 0xff ;
}
V_9 = F_1 ( V_2 , V_27 ) ;
V_8 -> V_28 [ 0 ] = ( V_9 >> 8 ) & 0xff ;
V_8 -> V_28 [ 1 ] = V_9 & 0xff ;
V_9 = F_1 ( V_2 , V_29 ) ;
V_8 -> V_30 [ 0 ] = ( V_9 >> 8 ) & 0xff ;
V_8 -> V_30 [ 1 ] = V_9 & 0xff ;
V_8 -> V_31 [ 0 ] = F_1 ( V_2 ,
V_32 [ 0 ] ) ;
V_8 -> V_33 [ 0 ] = F_1 ( V_2 ,
V_34 [ 0 ] ) ;
V_8 -> V_35 [ 0 ] = F_1 ( V_2 ,
V_36 [ 0 ] ) ;
V_9 = F_1 ( V_2 , V_37 ) ;
V_8 -> V_38 [ 0 ] = ( V_9 >> 6 ) & 0x03 ;
V_8 -> V_38 [ 1 ] = ( V_9 >> 4 ) & 0x03 ;
V_8 -> V_39 = ( V_9 >> 2 ) & 0x01 ;
V_8 -> V_16 &= V_8 -> V_40 ;
V_9 = F_1 ( V_2 , V_41 ) ;
V_8 -> V_42 = ! ( ( V_9 >> 2 ) & 1 ) ;
if ( V_8 -> V_43 ) {
V_8 -> V_31 [ 1 ] = F_1 ( V_2 ,
V_32 [ 1 ] ) ;
V_8 -> V_33 [ 1 ] = F_1 ( V_2 ,
V_34 [ 1 ] ) ;
V_8 -> V_35 [ 1 ] = F_1 ( V_2 ,
V_36 [ 1 ] ) ;
} else {
V_8 -> V_22 [ 4 ] = F_1 ( V_2 ,
V_23 [ 4 ] ) ;
V_8 -> V_25 [ 4 ] = F_1 ( V_2 ,
V_44 [ 4 ] ) ;
V_8 -> V_26 [ 4 ] = F_1 ( V_2 ,
V_45 [ 4 ] ) ;
}
V_8 -> V_13 = V_12 ;
V_8 -> V_15 = 1 ;
}
F_12 ( & V_8 -> V_11 ) ;
return V_8 ;
}
static T_3 F_13 ( struct V_6 * V_7 , struct V_46 * V_47 ,
char * V_48 )
{
struct V_5 * V_8 = F_7 ( V_7 ) ;
return sprintf ( V_48 , L_2 , F_14 ( V_8 -> V_20 , V_8 -> V_49 ) ) ;
}
static T_3 F_15 ( struct V_6 * V_7 , struct V_46 * V_47 ,
char * V_48 )
{
int V_50 = F_16 ( V_47 ) -> V_51 ;
struct V_5 * V_8 = F_7 ( V_7 ) ;
T_1 V_52 = V_8 -> V_22 [ V_50 ] ;
if ( V_50 == 0 )
return sprintf ( V_48 , L_3 , F_17 ( V_52 ) ) ;
else
return sprintf ( V_48 , L_3 , F_18 ( V_52 ) ) ;
}
static T_3 F_19 ( struct V_6 * V_7 , struct V_46 * V_47 ,
char * V_48 )
{
int V_50 = F_16 ( V_47 ) -> V_51 ;
struct V_5 * V_8 = F_7 ( V_7 ) ;
T_1 V_52 = V_8 -> V_25 [ V_50 ] ;
if ( V_50 == 0 )
return sprintf ( V_48 , L_3 , F_17 ( V_52 ) ) ;
else
return sprintf ( V_48 , L_3 , F_18 ( V_52 ) ) ;
}
static T_3 F_20 ( struct V_6 * V_7 , struct V_46 * V_47 ,
char * V_48 )
{
int V_50 = F_16 ( V_47 ) -> V_51 ;
struct V_5 * V_8 = F_7 ( V_7 ) ;
T_1 V_52 = V_8 -> V_26 [ V_50 ] ;
if ( V_50 == 0 )
return sprintf ( V_48 , L_3 , F_17 ( V_52 ) ) ;
else
return sprintf ( V_48 , L_3 , F_18 ( V_52 ) ) ;
}
static T_3 F_21 ( struct V_6 * V_7 , struct V_46 * V_47 ,
const char * V_48 , T_4 V_53 )
{
struct V_5 * V_8 = F_8 ( V_7 ) ;
struct V_1 * V_2 = V_8 -> V_2 ;
int V_50 = F_16 ( V_47 ) -> V_51 ;
T_1 V_52 ;
long V_54 ;
int V_55 ;
V_55 = F_22 ( V_48 , 10 , & V_54 ) ;
if ( V_55 )
return V_55 ;
F_9 ( & V_8 -> V_11 ) ;
if ( V_50 == 0 )
V_52 = F_23 ( V_54 ) ;
else
V_52 = F_24 ( V_54 ) ;
V_8 -> V_25 [ V_50 ] = V_52 ;
if ( V_50 < 4 )
F_4 ( V_2 , V_44 [ V_50 ] ,
( F_1 ( V_2 , V_44 [ V_50 ] )
& ~ 0xff ) | V_52 ) ;
else
F_4 ( V_2 , V_44 [ V_50 ] , V_52 ) ;
F_12 ( & V_8 -> V_11 ) ;
return V_53 ;
}
static T_3 F_25 ( struct V_6 * V_7 , struct V_46 * V_47 ,
const char * V_48 , T_4 V_53 )
{
struct V_5 * V_8 = F_8 ( V_7 ) ;
struct V_1 * V_2 = V_8 -> V_2 ;
int V_50 = F_16 ( V_47 ) -> V_51 ;
T_1 V_52 ;
long V_54 ;
int V_55 ;
V_55 = F_22 ( V_48 , 10 , & V_54 ) ;
if ( V_55 )
return V_55 ;
if ( V_50 == 0 )
V_52 = F_23 ( V_54 ) ;
else
V_52 = F_24 ( V_54 ) ;
F_9 ( & V_8 -> V_11 ) ;
V_8 -> V_26 [ V_50 ] = V_52 ;
if ( V_50 < 4 )
F_4 ( V_2 , V_45 [ V_50 ] ,
( F_1 ( V_2 , V_45 [ V_50 ] )
& ~ 0xff00 ) | ( V_52 << 8 ) ) ;
else
F_4 ( V_2 , V_45 [ V_50 ] , V_52 ) ;
F_12 ( & V_8 -> V_11 ) ;
return V_53 ;
}
static T_3 F_26 ( struct V_6 * V_7 , struct V_46 * V_47 ,
char * V_48 )
{
int V_50 = F_16 ( V_47 ) -> V_51 ;
struct V_5 * V_8 = F_7 ( V_7 ) ;
return sprintf ( V_48 , L_3 , F_27 ( V_8 -> V_28 [ V_50 ] ,
V_8 -> V_38 [ V_50 ] ) ) ;
}
static T_3 F_28 ( struct V_6 * V_7 , struct V_46 * V_47 ,
char * V_48 )
{
int V_50 = F_16 ( V_47 ) -> V_51 ;
struct V_5 * V_8 = F_7 ( V_7 ) ;
return sprintf ( V_48 , L_3 , F_27 ( V_8 -> V_30 [ V_50 ] ,
V_8 -> V_38 [ V_50 ] ) ) ;
}
static T_3 F_29 ( struct V_6 * V_7 , struct V_46 * V_47 ,
char * V_48 )
{
int V_50 = F_16 ( V_47 ) -> V_51 ;
struct V_5 * V_8 = F_7 ( V_7 ) ;
return sprintf ( V_48 , L_3 , F_30 ( V_8 -> V_38 [ V_50 ] ) ) ;
}
static T_3 F_31 ( struct V_6 * V_7 , struct V_46 * V_47 ,
char * V_48 )
{
struct V_5 * V_8 = F_7 ( V_7 ) ;
return sprintf ( V_48 , L_3 , V_8 -> V_39 ) ;
}
static T_3 F_32 ( struct V_6 * V_7 , struct V_46 * V_47 ,
const char * V_48 , T_4 V_53 )
{
struct V_5 * V_8 = F_8 ( V_7 ) ;
struct V_1 * V_2 = V_8 -> V_2 ;
int V_50 = F_16 ( V_47 ) -> V_51 ;
T_1 V_52 ;
unsigned long V_54 ;
int V_55 ;
V_55 = F_33 ( V_48 , 10 , & V_54 ) ;
if ( V_55 )
return V_55 ;
F_9 ( & V_8 -> V_11 ) ;
V_52 = F_34 ( V_54 , V_8 -> V_38 [ V_50 ] ) ;
V_8 -> V_30 [ V_50 ] = V_52 ;
if ( V_50 == 0 )
F_4 ( V_2 , V_29 ,
( F_1 ( V_2 , V_29 )
& ~ 0xff00 ) | ( V_52 << 8 ) ) ;
else
F_4 ( V_2 , V_29 ,
( F_1 ( V_2 , V_29 )
& ~ 0xff ) | V_52 ) ;
V_8 -> V_18 = F_1 ( V_2 , V_19 ) ;
if ( V_8 -> V_30 [ V_50 ] == 0 )
V_8 -> V_40 &= ( V_50 == 0 ) ? ~ 0x20 : ~ 0x40 ;
else
V_8 -> V_40 |= ( V_50 == 0 ) ? 0x20 : 0x40 ;
V_8 -> V_18 &= V_8 -> V_40 ;
F_4 ( V_2 , V_19 , V_8 -> V_18 ) ;
F_12 ( & V_8 -> V_11 ) ;
return V_53 ;
}
static T_3 F_35 ( struct V_6 * V_7 , struct V_46 * V_47 ,
const char * V_48 , T_4 V_53 )
{
struct V_5 * V_8 = F_8 ( V_7 ) ;
struct V_1 * V_2 = V_8 -> V_2 ;
int V_50 = F_16 ( V_47 ) -> V_51 ;
T_1 V_52 ;
unsigned long V_54 ;
int V_55 ;
V_55 = F_33 ( V_48 , 10 , & V_54 ) ;
if ( V_55 )
return V_55 ;
switch ( V_54 ) {
case 1 :
V_52 = 0 ;
break;
case 2 :
V_52 = 1 ;
break;
case 4 :
V_52 = 2 ;
break;
case 8 :
V_52 = 3 ;
break;
default:
F_36 ( & V_2 -> V_7 ,
L_4 , V_54 ) ;
return - V_56 ;
}
F_9 ( & V_8 -> V_11 ) ;
V_8 -> V_38 [ V_50 ] = V_52 ;
if ( V_50 == 0 )
F_4 ( V_2 , V_37 ,
( F_1 ( V_2 , V_37 )
& ~ 0xc0 ) | ( V_52 << 6 ) ) ;
else
F_4 ( V_2 , V_37 ,
( F_1 ( V_2 , V_37 )
& ~ 0x30 ) | ( V_52 << 4 ) ) ;
F_12 ( & V_8 -> V_11 ) ;
return V_53 ;
}
static T_3 F_37 ( struct V_6 * V_7 , struct V_46 * V_47 ,
const char * V_48 , T_4 V_53 )
{
struct V_5 * V_8 = F_8 ( V_7 ) ;
struct V_1 * V_2 = V_8 -> V_2 ;
T_1 V_52 ;
unsigned long V_54 ;
int V_55 ;
V_55 = F_33 ( V_48 , 10 , & V_54 ) ;
if ( V_55 )
return V_55 ;
V_52 = ( V_54 ? 1 : 0 ) ;
F_9 ( & V_8 -> V_11 ) ;
V_8 -> V_39 = V_52 ;
F_4 ( V_2 , V_57 ,
( F_1 ( V_2 , V_57 )
& ~ 0x0c ) | ( V_52 << 2 ) ) ;
F_12 ( & V_8 -> V_11 ) ;
return V_53 ;
}
static T_3 F_38 ( struct V_6 * V_7 , struct V_46 * V_47 ,
char * V_48 )
{
int V_50 = F_16 ( V_47 ) -> V_51 ;
struct V_5 * V_8 = F_7 ( V_7 ) ;
return sprintf ( V_48 , L_3 , F_39 ( V_8 -> V_31 [ V_50 ] ) ) ;
}
static T_3 F_40 ( struct V_6 * V_7 , struct V_46 * V_47 ,
char * V_48 )
{
int V_50 = F_16 ( V_47 ) -> V_51 ;
struct V_5 * V_8 = F_7 ( V_7 ) ;
return sprintf ( V_48 , L_3 , F_39 ( V_8 -> V_33 [ V_50 ] ) ) ;
}
static T_3 F_41 ( struct V_6 * V_7 ,
struct V_46 * V_47 , char * V_48 )
{
int V_50 = F_16 ( V_47 ) -> V_51 ;
struct V_5 * V_8 = F_7 ( V_7 ) ;
return sprintf ( V_48 , L_3 , F_39 ( V_8 -> V_35 [ V_50 ] ) ) ;
}
static T_3 F_42 ( struct V_6 * V_7 , struct V_46 * V_47 ,
const char * V_48 , T_4 V_53 )
{
struct V_5 * V_8 = F_8 ( V_7 ) ;
struct V_1 * V_2 = V_8 -> V_2 ;
int V_50 = F_16 ( V_47 ) -> V_51 ;
long V_54 ;
int V_55 ;
V_55 = F_22 ( V_48 , 10 , & V_54 ) ;
if ( V_55 )
return V_55 ;
F_9 ( & V_8 -> V_11 ) ;
V_8 -> V_33 [ V_50 ] = F_43 ( V_54 ) ;
F_4 ( V_2 , V_34 [ V_50 ] , V_8 -> V_33 [ V_50 ] ) ;
F_12 ( & V_8 -> V_11 ) ;
return V_53 ;
}
static T_3 F_44 ( struct V_6 * V_7 , struct V_46
* V_47 , const char * V_48 , T_4 V_53 )
{
struct V_5 * V_8 = F_8 ( V_7 ) ;
struct V_1 * V_2 = V_8 -> V_2 ;
int V_50 = F_16 ( V_47 ) -> V_51 ;
long V_54 ;
int V_55 ;
V_55 = F_22 ( V_48 , 10 , & V_54 ) ;
if ( V_55 )
return V_55 ;
F_9 ( & V_8 -> V_11 ) ;
V_8 -> V_35 [ V_50 ] = F_43 ( V_54 ) ;
F_4 ( V_2 , V_36 [ V_50 ] ,
V_8 -> V_35 [ V_50 ] ) ;
F_12 ( & V_8 -> V_11 ) ;
return V_53 ;
}
static T_3 F_45 ( struct V_6 * V_7 , struct V_46 * V_47 ,
char * V_48 )
{
struct V_5 * V_8 = F_7 ( V_7 ) ;
return sprintf ( V_48 , L_3 , V_8 -> V_16 ) ;
}
static T_3 F_46 ( struct V_6 * V_7 , struct V_46
* V_47 , char * V_48 )
{
struct V_5 * V_8 = F_7 ( V_7 ) ;
return sprintf ( V_48 , L_3 , V_8 -> V_42 ) ;
}
static T_3 F_47 ( struct V_6 * V_7 , struct V_46 * V_47 ,
char * V_48 )
{
struct V_5 * V_8 = F_7 ( V_7 ) ;
return sprintf ( V_48 , L_3 , V_8 -> V_18 ) ;
}
static T_3 F_48 ( struct V_6 * V_7 , struct V_46
* V_47 , const char * V_48 , T_4 V_53 )
{
struct V_5 * V_8 = F_8 ( V_7 ) ;
struct V_1 * V_2 = V_8 -> V_2 ;
T_1 V_52 ;
unsigned long V_54 ;
int V_55 ;
V_55 = F_33 ( V_48 , 10 , & V_54 ) ;
if ( V_55 )
return V_55 ;
V_52 = ( V_54 ? 0 : 1 ) ;
F_9 ( & V_8 -> V_11 ) ;
V_8 -> V_42 = ! V_52 ;
F_4 ( V_2 , V_58 ,
( F_1 ( V_2 , V_58 )
& ~ 0x04 ) | ( V_52 << 2 ) ) ;
F_12 ( & V_8 -> V_11 ) ;
return V_53 ;
}
static T_3 F_49 ( struct V_6 * V_7 , struct V_46 * V_47 ,
const char * V_48 , T_4 V_53 )
{
struct V_5 * V_8 = F_8 ( V_7 ) ;
struct V_1 * V_2 = V_8 -> V_2 ;
unsigned long V_52 ;
int V_55 ;
V_55 = F_33 ( V_48 , 10 , & V_52 ) ;
if ( V_55 )
return V_55 ;
F_9 ( & V_8 -> V_11 ) ;
V_52 &= V_8 -> V_40 ;
V_8 -> V_18 = V_52 ;
F_4 ( V_2 , V_19 , V_52 ) ;
F_12 ( & V_8 -> V_11 ) ;
return V_53 ;
}
static T_3 F_50 ( struct V_6 * V_7 , struct V_46 * V_47 ,
char * V_48 )
{
int V_59 = F_16 ( V_47 ) -> V_51 ;
struct V_5 * V_8 = F_7 ( V_7 ) ;
return sprintf ( V_48 , L_3 , ( V_8 -> V_16 >> V_59 ) & 1 ) ;
}
static T_3 F_51 ( struct V_6 * V_7 , struct V_46 * V_47 ,
char * V_48 )
{
int V_60 = F_16 ( V_47 ) -> V_51 ;
struct V_5 * V_8 = F_7 ( V_7 ) ;
return sprintf ( V_48 , L_3 , ( V_8 -> V_18 >> V_60 ) & 1 ) ;
}
static T_3 F_52 ( struct V_6 * V_7 , struct V_46 * V_47 ,
const char * V_48 , T_4 V_53 )
{
struct V_5 * V_8 = F_8 ( V_7 ) ;
struct V_1 * V_2 = V_8 -> V_2 ;
int V_60 = F_16 ( V_47 ) -> V_51 ;
unsigned long V_61 ;
int V_55 ;
V_55 = F_33 ( V_48 , 10 , & V_61 ) ;
if ( V_55 )
return V_55 ;
if ( V_61 & ~ 1 )
return - V_56 ;
F_9 ( & V_8 -> V_11 ) ;
V_8 -> V_18 = F_1 ( V_2 , V_19 ) ;
if ( V_61 )
V_8 -> V_18 |= ( 1 << V_60 ) ;
else
V_8 -> V_18 &= ~ ( 1 << V_60 ) ;
F_4 ( V_2 , V_19 , V_8 -> V_18 ) ;
F_12 ( & V_8 -> V_11 ) ;
return V_53 ;
}
static int F_53 ( struct V_1 * V_2 , struct V_62 * V_63 )
{
struct V_64 * V_65 = V_2 -> V_65 ;
if ( ! F_54 ( V_65 , V_66 |
V_67 ) )
return - V_68 ;
if ( ( F_1 ( V_2 , V_69 ) != 0x20 ) ||
( ( F_1 ( V_2 , V_70 ) & 0x7f ) != 0x00 ) ||
( ( F_1 ( V_2 , V_41 ) & 0x80 ) != 0x00 ) ) {
F_11 ( & V_2 -> V_7 , L_5 ) ;
return - V_68 ;
}
F_55 ( V_63 -> type , L_6 , V_71 ) ;
return 0 ;
}
static void F_56 ( struct V_1 * V_2 )
{
struct V_5 * V_8 = F_57 ( V_2 ) ;
T_1 V_72 , V_73 ;
V_73 = V_72 = F_1 ( V_2 , V_41 ) ;
V_8 -> V_40 = 0xff ;
V_8 -> V_49 = F_58 () ;
if ( V_74 == 1 )
V_73 &= ~ 0x10 ;
else if ( V_74 == 2 )
V_73 |= 0x10 ;
V_8 -> V_43 = ! ( V_73 & 0x10 ) ;
if ( ! ( V_73 & 0x20 ) )
V_73 &= 0xf7 ;
V_73 |= 0x40 ;
if ( V_73 != V_72 )
F_4 ( V_2 , V_41 , V_73 ) ;
F_7 ( & ( V_2 -> V_7 ) ) ;
if ( V_8 -> V_30 [ 0 ] == 0 )
V_8 -> V_40 &= ~ 0x20 ;
if ( V_8 -> V_30 [ 1 ] == 0 )
V_8 -> V_40 &= ~ 0x40 ;
V_8 -> V_18 &= V_8 -> V_40 ;
F_4 ( V_2 , V_19 , V_8 -> V_18 ) ;
}
static int F_59 ( struct V_1 * V_2 ,
const struct V_75 * V_76 )
{
struct V_6 * V_7 = & V_2 -> V_7 ;
struct V_6 * V_77 ;
struct V_5 * V_8 ;
V_8 = F_60 ( V_7 , sizeof( struct V_5 ) , V_78 ) ;
if ( ! V_8 )
return - V_79 ;
F_61 ( V_2 , V_8 ) ;
F_62 ( & V_8 -> V_11 ) ;
V_8 -> V_2 = V_2 ;
F_56 ( V_2 ) ;
V_8 -> V_80 [ 0 ] = & V_81 ;
if ( V_8 -> V_43 )
V_8 -> V_80 [ 1 ] = & V_82 ;
else
V_8 -> V_80 [ 1 ] = & V_83 ;
V_77 = F_63 ( V_7 , V_2 -> V_84 ,
V_8 , V_8 -> V_80 ) ;
return F_64 ( V_77 ) ;
}
