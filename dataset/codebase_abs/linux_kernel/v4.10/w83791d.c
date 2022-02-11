static inline int F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
return F_2 ( V_2 , V_3 ) ;
}
static inline int F_3 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
return F_4 ( V_2 , V_3 , V_4 ) ;
}
static T_1 F_5 ( long V_5 , int div )
{
if ( V_5 == 0 )
return 255 ;
V_5 = F_6 ( V_5 , 1 , 1000000 ) ;
return F_6 ( ( 1350000 + V_5 * div / 2 ) / ( V_5 * div ) , 1 , 254 ) ;
}
static T_1 F_7 ( int V_6 , long V_7 )
{
int V_8 ;
V_7 = F_6 ( V_7 , 1 , 128 ) >> 1 ;
for ( V_8 = 0 ; V_8 < 7 ; V_8 ++ ) {
if ( V_7 == 0 )
break;
V_7 >>= 1 ;
}
return ( T_1 ) V_8 ;
}
static T_2 F_8 ( struct V_9 * V_10 , struct V_11 * V_12 ,
char * V_13 )
{
struct V_14 * V_15 =
F_9 ( V_12 ) ;
struct V_16 * V_17 = F_10 ( V_10 ) ;
int V_18 = V_15 -> V_19 ;
return sprintf ( V_13 , L_1 , ( V_17 -> V_20 >> V_18 ) & 1 ) ;
}
static T_2 F_11 ( struct V_9 * V_10 , struct V_11 * V_12 ,
const char * V_13 , T_3 V_21 )
{
struct V_14 * V_15 =
F_9 ( V_12 ) ;
struct V_1 * V_2 = F_12 ( V_10 ) ;
struct V_16 * V_17 = F_13 ( V_2 ) ;
int V_18 = V_15 -> V_19 ;
int V_22 = V_18 / 8 ;
unsigned long V_7 ;
int V_23 ;
V_23 = F_14 ( V_13 , 10 , & V_7 ) ;
if ( V_23 )
return V_23 ;
V_7 = V_7 ? 1 : 0 ;
F_15 ( & V_17 -> V_24 ) ;
V_17 -> V_20 &= ~ ( 0xff << ( V_22 * 8 ) ) ;
V_17 -> V_20 |= F_1 ( V_2 , V_25 [ V_22 ] )
<< ( V_22 * 8 ) ;
V_17 -> V_20 &= ~ ( 1 << V_18 ) ;
V_17 -> V_20 |= V_7 << V_18 ;
F_3 ( V_2 , V_25 [ V_22 ] ,
( V_17 -> V_20 >> ( V_22 * 8 ) ) & 0xff ) ;
F_16 ( & V_17 -> V_24 ) ;
return V_21 ;
}
static T_2 F_17 ( struct V_9 * V_10 , struct V_11 * V_12 ,
char * V_13 )
{
struct V_14 * V_15 =
F_9 ( V_12 ) ;
struct V_16 * V_17 = F_10 ( V_10 ) ;
int V_18 = V_15 -> V_19 ;
return sprintf ( V_13 , L_1 , ( V_17 -> V_26 >> V_18 ) & 1 ) ;
}
static T_2 F_18 ( struct V_9 * V_10 , struct V_11 * V_12 ,
const char * V_13 , T_3 V_21 )
{
struct V_14 * V_15 = F_9 ( V_12 ) ;
struct V_1 * V_2 = F_12 ( V_10 ) ;
struct V_16 * V_17 = F_13 ( V_2 ) ;
int V_6 = V_15 -> V_19 ;
unsigned long V_7 ;
int V_23 ;
V_23 = F_14 ( V_13 , 10 , & V_7 ) ;
if ( V_23 )
return V_23 ;
F_15 ( & V_17 -> V_24 ) ;
V_17 -> V_27 [ V_6 ] = F_5 ( V_7 , F_19 ( V_17 -> V_28 [ V_6 ] ) ) ;
F_3 ( V_2 , V_29 [ V_6 ] , V_17 -> V_27 [ V_6 ] ) ;
F_16 ( & V_17 -> V_24 ) ;
return V_21 ;
}
static T_2 F_20 ( struct V_9 * V_10 , struct V_11 * V_12 ,
char * V_13 )
{
struct V_14 * V_15 = F_9 ( V_12 ) ;
int V_6 = V_15 -> V_19 ;
struct V_16 * V_17 = F_10 ( V_10 ) ;
return sprintf ( V_13 , L_2 , F_19 ( V_17 -> V_28 [ V_6 ] ) ) ;
}
static T_2 F_21 ( struct V_9 * V_10 , struct V_11 * V_12 ,
const char * V_13 , T_3 V_21 )
{
struct V_14 * V_15 = F_9 ( V_12 ) ;
struct V_1 * V_2 = F_12 ( V_10 ) ;
struct V_16 * V_17 = F_13 ( V_2 ) ;
int V_6 = V_15 -> V_19 ;
unsigned long V_30 ;
T_1 V_31 ;
T_1 V_32 ;
T_1 V_33 ;
int V_34 = 0 ;
T_1 V_35 = 0 ;
T_1 V_36 = 0 ;
unsigned long V_7 ;
int V_23 ;
V_23 = F_14 ( V_13 , 10 , & V_7 ) ;
if ( V_23 )
return V_23 ;
V_30 = F_22 ( V_17 -> V_27 [ V_6 ] , F_19 ( V_17 -> V_28 [ V_6 ] ) ) ;
F_15 ( & V_17 -> V_24 ) ;
V_17 -> V_28 [ V_6 ] = F_7 ( V_6 , V_7 ) ;
switch ( V_6 ) {
case 0 :
V_34 = 0 ;
V_35 = 0xcf ;
V_36 = 4 ;
break;
case 1 :
V_34 = 0 ;
V_35 = 0x3f ;
V_36 = 6 ;
break;
case 2 :
V_34 = 1 ;
V_35 = 0x3f ;
V_36 = 6 ;
break;
case 3 :
V_34 = 2 ;
V_35 = 0xf8 ;
V_36 = 0 ;
break;
case 4 :
V_34 = 2 ;
V_35 = 0x8f ;
V_36 = 4 ;
break;
#ifdef F_23
default:
F_24 ( V_10 , L_3 , V_6 ) ;
V_21 = - V_37 ;
goto V_38;
#endif
}
V_32 = F_1 ( V_2 , V_39 [ V_34 ] )
& V_35 ;
V_31 = ( V_17 -> V_28 [ V_6 ] << V_36 ) & ~ V_35 ;
F_3 ( V_2 , V_39 [ V_34 ] ,
V_32 | V_31 ) ;
if ( V_6 < 3 ) {
V_35 = ~ ( 1 << ( V_6 + 5 ) ) ;
V_33 = F_1 ( V_2 , V_40 )
& V_35 ;
V_31 = ( V_17 -> V_28 [ V_6 ] << ( 3 + V_6 ) ) & ~ V_35 ;
F_3 ( V_2 , V_40 ,
V_33 | V_31 ) ;
}
V_17 -> V_27 [ V_6 ] = F_5 ( V_30 , F_19 ( V_17 -> V_28 [ V_6 ] ) ) ;
F_3 ( V_2 , V_29 [ V_6 ] , V_17 -> V_27 [ V_6 ] ) ;
#ifdef F_23
V_38:
#endif
F_16 ( & V_17 -> V_24 ) ;
return V_21 ;
}
static T_2 F_25 ( struct V_9 * V_10 , struct V_11 * V_12 ,
char * V_13 )
{
struct V_14 * V_15 = F_9 ( V_12 ) ;
int V_6 = V_15 -> V_19 ;
struct V_16 * V_17 = F_10 ( V_10 ) ;
return sprintf ( V_13 , L_2 , V_17 -> V_41 [ V_6 ] ) ;
}
static T_2 F_26 ( struct V_9 * V_10 , struct V_11 * V_12 ,
const char * V_13 , T_3 V_21 )
{
struct V_14 * V_15 = F_9 ( V_12 ) ;
struct V_1 * V_2 = F_12 ( V_10 ) ;
struct V_16 * V_17 = F_13 ( V_2 ) ;
int V_6 = V_15 -> V_19 ;
unsigned long V_7 ;
if ( F_14 ( V_13 , 10 , & V_7 ) )
return - V_37 ;
F_15 ( & V_17 -> V_24 ) ;
V_17 -> V_41 [ V_6 ] = F_6 ( V_7 , 0 , 255 ) ;
F_3 ( V_2 , V_42 [ V_6 ] , V_17 -> V_41 [ V_6 ] ) ;
F_16 ( & V_17 -> V_24 ) ;
return V_21 ;
}
static T_2 F_27 ( struct V_9 * V_10 , struct V_11 * V_12 ,
char * V_13 )
{
struct V_14 * V_15 = F_9 ( V_12 ) ;
int V_6 = V_15 -> V_19 ;
struct V_16 * V_17 = F_10 ( V_10 ) ;
return sprintf ( V_13 , L_2 , V_17 -> V_43 [ V_6 ] + 1 ) ;
}
static T_2 F_28 ( struct V_9 * V_10 ,
struct V_11 * V_12 , const char * V_13 , T_3 V_21 )
{
struct V_14 * V_15 = F_9 ( V_12 ) ;
struct V_1 * V_2 = F_12 ( V_10 ) ;
struct V_16 * V_17 = F_13 ( V_2 ) ;
int V_6 = V_15 -> V_19 ;
unsigned long V_7 ;
T_1 V_44 ;
T_1 V_45 = 0 ;
T_1 V_46 = 0 ;
T_1 V_35 = 0 ;
int V_47 = F_14 ( V_13 , 10 , & V_7 ) ;
if ( V_47 || V_7 < 1 || V_7 > 3 )
return - V_37 ;
F_15 ( & V_17 -> V_24 ) ;
V_17 -> V_43 [ V_6 ] = V_7 - 1 ;
switch ( V_6 ) {
case 0 :
V_45 = 0 ;
V_46 = 2 ;
V_35 = 0xf3 ;
break;
case 1 :
V_45 = 0 ;
V_46 = 4 ;
V_35 = 0xcf ;
break;
case 2 :
V_45 = 1 ;
V_46 = 2 ;
V_35 = 0xf3 ;
break;
}
V_44 = F_1 ( V_2 , V_48 [ V_45 ] ) ;
V_44 = ( V_44 & V_35 ) |
V_17 -> V_43 [ V_6 ] << V_46 ;
F_3 ( V_2 , V_48 [ V_45 ] , V_44 ) ;
F_16 ( & V_17 -> V_24 ) ;
return V_21 ;
}
static T_2 F_29 ( struct V_9 * V_10 ,
struct V_11 * V_12 , char * V_13 )
{
struct V_14 * V_15 = F_9 ( V_12 ) ;
struct V_16 * V_17 = F_10 ( V_10 ) ;
int V_6 = V_15 -> V_19 ;
return sprintf ( V_13 , L_1 , F_30 ( V_17 -> V_49 [ V_6 ] ) ) ;
}
static T_2 F_31 ( struct V_9 * V_10 ,
struct V_11 * V_12 , const char * V_13 , T_3 V_21 )
{
struct V_14 * V_15 = F_9 ( V_12 ) ;
struct V_1 * V_2 = F_12 ( V_10 ) ;
struct V_16 * V_17 = F_13 ( V_2 ) ;
int V_6 = V_15 -> V_19 ;
long V_7 ;
T_1 V_50 ;
if ( F_32 ( V_13 , 10 , & V_7 ) )
return - V_37 ;
F_15 ( & V_17 -> V_24 ) ;
V_17 -> V_49 [ V_6 ] = F_33 ( V_7 ) ;
V_50 = F_1 ( V_2 ,
V_51 [ V_6 ] ) & 0x80 ;
F_3 ( V_2 , V_51 [ V_6 ] ,
V_17 -> V_49 [ V_6 ] | V_50 ) ;
F_16 ( & V_17 -> V_24 ) ;
return V_21 ;
}
static T_2 F_34 ( struct V_9 * V_10 ,
struct V_11 * V_12 , char * V_13 )
{
struct V_14 * V_15 = F_9 ( V_12 ) ;
struct V_16 * V_17 = F_10 ( V_10 ) ;
int V_6 = V_15 -> V_19 ;
return sprintf ( V_13 , L_1 , F_30 ( V_17 -> V_52 [ V_6 ] ) ) ;
}
static T_2 F_35 ( struct V_9 * V_10 ,
struct V_11 * V_12 , const char * V_13 , T_3 V_21 )
{
struct V_14 * V_15 = F_9 ( V_12 ) ;
struct V_1 * V_2 = F_12 ( V_10 ) ;
struct V_16 * V_17 = F_13 ( V_2 ) ;
int V_6 = V_15 -> V_19 ;
unsigned long V_7 ;
T_1 V_50 ;
T_1 V_45 = 0 ;
T_1 V_46 = 0 ;
T_1 V_35 = 0 ;
if ( F_14 ( V_13 , 10 , & V_7 ) )
return - V_37 ;
switch ( V_6 ) {
case 0 :
V_45 = 0 ;
V_46 = 0 ;
V_35 = 0xf0 ;
break;
case 1 :
V_45 = 0 ;
V_46 = 4 ;
V_35 = 0x0f ;
break;
case 2 :
V_45 = 1 ;
V_46 = 0 ;
V_35 = 0xf0 ;
break;
}
F_15 ( & V_17 -> V_24 ) ;
V_17 -> V_52 [ V_6 ] = F_36 ( V_7 ) ;
V_50 = F_1 ( V_2 ,
V_53 [ V_45 ] ) & V_35 ;
F_3 ( V_2 , V_53 [ V_45 ] ,
( V_17 -> V_52 [ V_6 ] << V_46 ) | V_50 ) ;
F_16 ( & V_17 -> V_24 ) ;
return V_21 ;
}
static T_2 F_37 ( struct V_9 * V_10 , struct V_11 * V_54 ,
char * V_13 )
{
struct V_14 * V_12 = F_9 ( V_54 ) ;
struct V_16 * V_17 = F_10 ( V_10 ) ;
return sprintf ( V_13 , L_1 , F_30 ( V_17 -> V_55 [ V_12 -> V_19 ] ) ) ;
}
static T_2 F_38 ( struct V_9 * V_10 , struct V_11 * V_54 ,
const char * V_13 , T_3 V_21 )
{
struct V_14 * V_12 = F_9 ( V_54 ) ;
struct V_1 * V_2 = F_12 ( V_10 ) ;
struct V_16 * V_17 = F_13 ( V_2 ) ;
int V_6 = V_12 -> V_19 ;
long V_7 ;
int V_23 ;
V_23 = F_32 ( V_13 , 10 , & V_7 ) ;
if ( V_23 )
return V_23 ;
F_15 ( & V_17 -> V_24 ) ;
V_17 -> V_55 [ V_6 ] = F_39 ( V_7 ) ;
F_3 ( V_2 , V_56 [ V_6 ] , V_17 -> V_55 [ V_6 ] ) ;
F_16 ( & V_17 -> V_24 ) ;
return V_21 ;
}
static T_2 F_40 ( struct V_9 * V_10 , struct V_11 * V_54 ,
char * V_13 )
{
struct V_57 * V_12 = F_41 ( V_54 ) ;
struct V_16 * V_17 = F_10 ( V_10 ) ;
int V_6 = V_12 -> V_6 ;
int V_19 = V_12 -> V_19 ;
return sprintf ( V_13 , L_1 , F_42 ( V_17 -> V_58 [ V_6 ] [ V_19 ] ) ) ;
}
static T_2 F_43 ( struct V_9 * V_10 ,
struct V_11 * V_54 ,
const char * V_13 , T_3 V_21 )
{
struct V_57 * V_12 = F_41 ( V_54 ) ;
struct V_1 * V_2 = F_12 ( V_10 ) ;
struct V_16 * V_17 = F_13 ( V_2 ) ;
long V_7 ;
int V_23 ;
int V_6 = V_12 -> V_6 ;
int V_19 = V_12 -> V_19 ;
V_23 = F_32 ( V_13 , 10 , & V_7 ) ;
if ( V_23 )
return V_23 ;
F_15 ( & V_17 -> V_24 ) ;
V_17 -> V_58 [ V_6 ] [ V_19 ] = F_44 ( V_7 ) ;
F_3 ( V_2 , V_59 [ V_6 ] [ V_19 * 2 ] ,
V_17 -> V_58 [ V_6 ] [ V_19 ] >> 8 ) ;
F_3 ( V_2 , V_59 [ V_6 ] [ V_19 * 2 + 1 ] ,
V_17 -> V_58 [ V_6 ] [ V_19 ] & 0x80 ) ;
F_16 ( & V_17 -> V_24 ) ;
return V_21 ;
}
static T_2 F_45 ( struct V_9 * V_10 ,
struct V_11 * V_12 , char * V_13 )
{
struct V_16 * V_17 = F_10 ( V_10 ) ;
return sprintf ( V_13 , L_2 , V_17 -> V_26 ) ;
}
static T_2 F_46 ( struct V_9 * V_10 ,
struct V_11 * V_12 , char * V_13 )
{
struct V_16 * V_17 = F_10 ( V_10 ) ;
return sprintf ( V_13 , L_1 , V_17 -> V_60 ) ;
}
static T_2 F_47 ( struct V_9 * V_10 ,
struct V_11 * V_12 , char * V_13 )
{
struct V_16 * V_17 = F_10 ( V_10 ) ;
return sprintf ( V_13 , L_1 , F_48 ( V_17 -> V_20 ) ) ;
}
static T_2 F_49 ( struct V_9 * V_10 ,
struct V_11 * V_12 ,
const char * V_13 , T_3 V_21 )
{
struct V_1 * V_2 = F_12 ( V_10 ) ;
struct V_16 * V_17 = F_13 ( V_2 ) ;
int V_8 ;
long V_7 ;
int V_23 ;
V_23 = F_32 ( V_13 , 10 , & V_7 ) ;
if ( V_23 )
return V_23 ;
F_15 ( & V_17 -> V_24 ) ;
V_17 -> V_20 = F_50 ( V_7 ) & ~ V_61 ;
V_17 -> V_20 |= ( V_17 -> V_60 << V_62 ) ;
V_7 = V_17 -> V_20 ;
for ( V_8 = 0 ; V_8 < 3 ; V_8 ++ ) {
F_3 ( V_2 , V_25 [ V_8 ] , ( V_7 & 0xff ) ) ;
V_7 >>= 8 ;
}
F_16 ( & V_17 -> V_24 ) ;
return V_21 ;
}
static T_2 F_51 ( struct V_9 * V_10 ,
struct V_11 * V_12 ,
const char * V_13 , T_3 V_21 )
{
struct V_1 * V_2 = F_12 ( V_10 ) ;
struct V_16 * V_17 = F_13 ( V_2 ) ;
long V_7 ;
int V_23 ;
V_23 = F_32 ( V_13 , 10 , & V_7 ) ;
if ( V_23 )
return V_23 ;
F_15 ( & V_17 -> V_24 ) ;
V_17 -> V_60 = V_7 ? 1 : 0 ;
V_17 -> V_20 &= ~ V_61 ;
V_17 -> V_20 |= ( V_17 -> V_60 << V_62 ) ;
V_7 = ( V_17 -> V_20 >> 8 ) & 0xff ;
F_3 ( V_2 , V_25 [ 1 ] , V_7 ) ;
F_16 ( & V_17 -> V_24 ) ;
return V_21 ;
}
static T_2 F_52 ( struct V_9 * V_10 ,
struct V_11 * V_12 , char * V_13 )
{
struct V_16 * V_17 = F_10 ( V_10 ) ;
return sprintf ( V_13 , L_1 , F_53 ( V_17 -> V_63 , V_17 -> V_64 ) ) ;
}
static T_2 F_54 ( struct V_9 * V_10 ,
struct V_11 * V_12 , char * V_13 )
{
struct V_16 * V_17 = F_55 ( V_10 ) ;
return sprintf ( V_13 , L_1 , V_17 -> V_64 ) ;
}
static T_2 F_56 ( struct V_9 * V_10 ,
struct V_11 * V_12 ,
const char * V_13 , T_3 V_21 )
{
struct V_16 * V_17 = F_55 ( V_10 ) ;
unsigned long V_7 ;
int V_23 ;
V_23 = F_14 ( V_13 , 10 , & V_7 ) ;
if ( V_23 )
return V_23 ;
if ( V_7 > 255 )
return - V_37 ;
V_17 -> V_64 = V_7 ;
return V_21 ;
}
static int F_57 ( struct V_1 * V_2 )
{
struct V_65 * V_66 = V_2 -> V_66 ;
struct V_16 * V_17 = F_13 ( V_2 ) ;
int V_67 = V_2 -> V_68 ;
int V_8 , V_69 , V_23 ;
T_1 V_7 ;
V_69 = F_58 ( V_66 ) ;
if ( V_70 [ 0 ] == V_69 && V_70 [ 1 ] == V_67 ) {
for ( V_8 = 2 ; V_8 <= 3 ; V_8 ++ ) {
if ( V_70 [ V_8 ] < 0x48 ||
V_70 [ V_8 ] > 0x4f ) {
F_59 ( & V_2 -> V_10 ,
L_4
L_5 ,
V_70 [ V_8 ] ) ;
V_23 = - V_71 ;
goto V_72;
}
}
F_3 ( V_2 , V_73 ,
( V_70 [ 2 ] & 0x07 ) |
( ( V_70 [ 3 ] & 0x07 ) << 4 ) ) ;
}
V_7 = F_1 ( V_2 , V_73 ) ;
if ( ! ( V_7 & 0x08 ) )
V_17 -> V_74 [ 0 ] = F_60 ( V_66 , 0x48 + ( V_7 & 0x7 ) ) ;
if ( ! ( V_7 & 0x80 ) ) {
if ( ( V_17 -> V_74 [ 0 ] != NULL ) &&
( ( V_7 & 0x7 ) == ( ( V_7 >> 4 ) & 0x7 ) ) ) {
F_59 ( & V_2 -> V_10 ,
L_6
L_7 ,
V_17 -> V_74 [ 0 ] -> V_68 ) ;
V_23 = - V_71 ;
goto V_75;
}
V_17 -> V_74 [ 1 ] = F_60 ( V_66 ,
0x48 + ( ( V_7 >> 4 ) & 0x7 ) ) ;
}
return 0 ;
V_75:
if ( V_17 -> V_74 [ 0 ] != NULL )
F_61 ( V_17 -> V_74 [ 0 ] ) ;
V_72:
return V_23 ;
}
static int F_62 ( struct V_1 * V_2 ,
struct V_76 * V_77 )
{
struct V_65 * V_66 = V_2 -> V_66 ;
int V_78 , V_79 ;
unsigned short V_67 = V_2 -> V_68 ;
if ( ! F_63 ( V_66 , V_80 ) )
return - V_71 ;
if ( F_1 ( V_2 , V_81 ) & 0x80 )
return - V_71 ;
V_78 = F_1 ( V_2 , V_82 ) ;
V_79 = F_1 ( V_2 , V_83 ) ;
if ( ! ( V_78 & 0x07 ) ) {
if ( ( ! ( V_78 & 0x80 ) && V_79 != 0xa3 ) ||
( ( V_78 & 0x80 ) && V_79 != 0x5c ) ) {
return - V_71 ;
}
}
if ( F_1 ( V_2 , V_84 ) != V_67 )
return - V_71 ;
V_78 = F_1 ( V_2 , V_82 ) & 0x78 ;
F_3 ( V_2 , V_82 , V_78 | 0x80 ) ;
V_78 = F_1 ( V_2 , V_85 ) ;
V_79 = F_1 ( V_2 , V_83 ) ;
if ( V_78 != 0x71 || V_79 != 0x5c )
return - V_71 ;
F_64 ( V_77 -> type , L_8 , V_86 ) ;
return 0 ;
}
static int F_65 ( struct V_1 * V_2 ,
const struct V_87 * V_69 )
{
struct V_16 * V_17 ;
struct V_9 * V_10 = & V_2 -> V_10 ;
int V_8 , V_23 ;
T_1 V_88 ;
#ifdef F_23
int V_78 ;
V_78 = F_1 ( V_2 , V_89 ) ;
F_66 ( V_10 , L_9 ,
( V_78 >> 5 ) & 0x07 , ( V_78 >> 1 ) & 0x0f , V_78 ) ;
#endif
V_17 = F_67 ( & V_2 -> V_10 , sizeof( struct V_16 ) ,
V_90 ) ;
if ( ! V_17 )
return - V_91 ;
F_68 ( V_2 , V_17 ) ;
F_69 ( & V_17 -> V_24 ) ;
V_23 = F_57 ( V_2 ) ;
if ( V_23 )
return V_23 ;
F_70 ( V_2 ) ;
for ( V_8 = 0 ; V_8 < V_92 ; V_8 ++ )
V_17 -> V_27 [ V_8 ] = F_1 ( V_2 , V_29 [ V_8 ] ) ;
V_23 = F_71 ( & V_2 -> V_10 . V_93 , & V_94 ) ;
if ( V_23 )
goto V_95;
V_88 = F_1 ( V_2 , V_96 ) & 0x10 ;
if ( V_88 ) {
V_23 = F_71 ( & V_2 -> V_10 . V_93 ,
& V_97 ) ;
if ( V_23 )
goto V_98;
}
V_17 -> V_99 = F_72 ( V_10 ) ;
if ( F_73 ( V_17 -> V_99 ) ) {
V_23 = F_74 ( V_17 -> V_99 ) ;
goto V_100;
}
return 0 ;
V_100:
if ( V_88 )
F_75 ( & V_2 -> V_10 . V_93 , & V_97 ) ;
V_98:
F_75 ( & V_2 -> V_10 . V_93 , & V_94 ) ;
V_95:
if ( V_17 -> V_74 [ 0 ] != NULL )
F_61 ( V_17 -> V_74 [ 0 ] ) ;
if ( V_17 -> V_74 [ 1 ] != NULL )
F_61 ( V_17 -> V_74 [ 1 ] ) ;
return V_23 ;
}
static int F_76 ( struct V_1 * V_2 )
{
struct V_16 * V_17 = F_13 ( V_2 ) ;
F_77 ( V_17 -> V_99 ) ;
F_75 ( & V_2 -> V_10 . V_93 , & V_94 ) ;
if ( V_17 -> V_74 [ 0 ] != NULL )
F_61 ( V_17 -> V_74 [ 0 ] ) ;
if ( V_17 -> V_74 [ 1 ] != NULL )
F_61 ( V_17 -> V_74 [ 1 ] ) ;
return 0 ;
}
static void F_70 ( struct V_1 * V_2 )
{
struct V_16 * V_17 = F_13 ( V_2 ) ;
T_1 V_101 ;
T_1 V_102 ;
if ( V_103 || V_104 ) {
V_102 = F_1 ( V_2 , V_105 ) ;
if ( V_103 ) {
F_3 ( V_2 , V_81 , 0x80 ) ;
}
F_3 ( V_2 , V_105 , V_102 | 0x80 ) ;
V_101 = F_1 ( V_2 , V_25 [ 1 ] ) ;
F_3 ( V_2 , V_25 [ 1 ] , V_101 & 0xef ) ;
if ( V_104 ) {
V_101 = F_1 ( V_2 , V_106 ) ;
if ( V_101 & 1 ) {
F_3 ( V_2 , V_106 ,
V_101 & 0xfe ) ;
}
V_101 = F_1 ( V_2 , V_107 ) ;
if ( V_101 & 1 ) {
F_3 ( V_2 , V_107 ,
V_101 & 0xfe ) ;
}
V_101 = F_1 ( V_2 , V_81 ) & 0xf7 ;
F_3 ( V_2 , V_81 , V_101 | 0x01 ) ;
}
}
V_17 -> V_64 = F_78 () ;
}
static struct V_16 * F_10 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = F_12 ( V_10 ) ;
struct V_16 * V_17 = F_13 ( V_2 ) ;
int V_8 , V_108 ;
T_1 V_109 [ 3 ] ;
T_1 V_33 ;
F_15 ( & V_17 -> V_24 ) ;
if ( F_79 ( V_110 , V_17 -> V_111 + ( V_112 * 3 ) )
|| ! V_17 -> V_113 ) {
F_66 ( V_10 , L_10 ) ;
for ( V_8 = 0 ; V_8 < V_114 ; V_8 ++ ) {
V_17 -> V_115 [ V_8 ] = F_1 ( V_2 ,
V_116 [ V_8 ] ) ;
V_17 -> V_117 [ V_8 ] = F_1 ( V_2 ,
V_118 [ V_8 ] ) ;
V_17 -> V_119 [ V_8 ] = F_1 ( V_2 ,
V_120 [ V_8 ] ) ;
}
for ( V_8 = 0 ; V_8 < V_92 ; V_8 ++ ) {
V_17 -> V_121 [ V_8 ] = F_1 ( V_2 ,
V_122 [ V_8 ] ) ;
V_17 -> V_27 [ V_8 ] = F_1 ( V_2 ,
V_29 [ V_8 ] ) ;
}
for ( V_8 = 0 ; V_8 < 3 ; V_8 ++ ) {
V_109 [ V_8 ] = F_1 ( V_2 ,
V_39 [ V_8 ] ) ;
}
V_17 -> V_28 [ 0 ] = ( V_109 [ 0 ] >> 4 ) & 0x03 ;
V_17 -> V_28 [ 1 ] = ( V_109 [ 0 ] >> 6 ) & 0x03 ;
V_17 -> V_28 [ 2 ] = ( V_109 [ 1 ] >> 6 ) & 0x03 ;
V_17 -> V_28 [ 3 ] = V_109 [ 2 ] & 0x07 ;
V_17 -> V_28 [ 4 ] = ( V_109 [ 2 ] >> 4 ) & 0x07 ;
V_33 = F_1 ( V_2 , V_40 ) ;
for ( V_8 = 0 ; V_8 < 3 ; V_8 ++ )
V_17 -> V_28 [ V_8 ] |= ( V_33 >> ( 3 + V_8 ) ) & 0x04 ;
for ( V_8 = 0 ; V_8 < V_123 ; V_8 ++ ) {
V_17 -> V_41 [ V_8 ] = F_1 ( V_2 ,
V_42 [ V_8 ] ) ;
}
for ( V_8 = 0 ; V_8 < 2 ; V_8 ++ ) {
V_109 [ V_8 ] = F_1 ( V_2 ,
V_48 [ V_8 ] ) ;
}
V_17 -> V_43 [ 0 ] = ( V_109 [ 0 ] >> 2 ) & 0x03 ;
V_17 -> V_43 [ 1 ] = ( V_109 [ 0 ] >> 4 ) & 0x03 ;
V_17 -> V_43 [ 2 ] = ( V_109 [ 1 ] >> 2 ) & 0x03 ;
for ( V_8 = 0 ; V_8 < 3 ; V_8 ++ ) {
V_17 -> V_49 [ V_8 ] = F_1 ( V_2 ,
V_51 [ V_8 ] ) & 0x7f ;
}
for ( V_8 = 0 ; V_8 < 2 ; V_8 ++ ) {
V_109 [ V_8 ] = F_1 ( V_2 ,
V_53 [ V_8 ] ) ;
}
V_17 -> V_52 [ 0 ] = V_109 [ 0 ] & 0x0f ;
V_17 -> V_52 [ 1 ] = ( V_109 [ 0 ] >> 4 ) & 0x0f ;
V_17 -> V_52 [ 2 ] = V_109 [ 1 ] & 0x0f ;
for ( V_8 = 0 ; V_8 < 3 ; V_8 ++ ) {
V_17 -> V_55 [ V_8 ] = F_1 ( V_2 ,
V_56 [ V_8 ] ) ;
}
for ( V_8 = 0 ; V_8 < 2 ; V_8 ++ ) {
for ( V_108 = 0 ; V_108 < 3 ; V_108 ++ ) {
V_17 -> V_58 [ V_8 ] [ V_108 ] =
( F_1 ( V_2 ,
V_59 [ V_8 ] [ V_108 * 2 ] ) << 8 ) |
F_1 ( V_2 ,
V_59 [ V_8 ] [ V_108 * 2 + 1 ] ) ;
}
}
V_17 -> V_26 =
F_1 ( V_2 , V_124 ) +
( F_1 ( V_2 , V_125 ) << 8 ) +
( F_1 ( V_2 , V_126 ) << 16 ) ;
V_17 -> V_20 =
F_1 ( V_2 , V_25 [ 0 ] ) +
( F_1 ( V_2 , V_25 [ 1 ] ) << 8 ) +
( F_1 ( V_2 , V_25 [ 2 ] ) << 16 ) ;
V_17 -> V_60 =
( V_17 -> V_20 >> V_62 ) & 0x01 ;
V_8 = F_1 ( V_2 , V_127 ) ;
V_17 -> V_63 = V_8 & 0x0f ;
V_17 -> V_63 |= ( F_1 ( V_2 , V_89 ) & 0x01 )
<< 4 ;
V_17 -> V_111 = V_110 ;
V_17 -> V_113 = 1 ;
}
F_16 ( & V_17 -> V_24 ) ;
#ifdef F_23
F_80 ( V_17 , V_10 ) ;
#endif
return V_17 ;
}
static void F_80 ( struct V_16 * V_17 , struct V_9 * V_10 )
{
int V_8 = 0 , V_108 = 0 ;
F_66 ( V_10 , L_11 ) ;
F_66 ( V_10 , L_12 , V_114 ) ;
for ( V_8 = 0 ; V_8 < V_114 ; V_8 ++ ) {
F_66 ( V_10 , L_13 , V_8 , V_17 -> V_115 [ V_8 ] ) ;
F_66 ( V_10 , L_14 , V_8 , V_17 -> V_119 [ V_8 ] ) ;
F_66 ( V_10 , L_15 , V_8 , V_17 -> V_117 [ V_8 ] ) ;
}
F_66 ( V_10 , L_16 , V_92 ) ;
for ( V_8 = 0 ; V_8 < V_92 ; V_8 ++ ) {
F_66 ( V_10 , L_17 , V_8 , V_17 -> V_121 [ V_8 ] ) ;
F_66 ( V_10 , L_18 , V_8 , V_17 -> V_27 [ V_8 ] ) ;
F_66 ( V_10 , L_19 , V_8 , V_17 -> V_28 [ V_8 ] ) ;
}
F_66 ( V_10 , L_20 , V_128 ) ;
for ( V_8 = 0 ; V_8 < 3 ; V_8 ++ )
F_66 ( V_10 , L_21 , V_8 , ( T_1 ) V_17 -> V_55 [ V_8 ] ) ;
for ( V_8 = 0 ; V_8 < 2 ; V_8 ++ ) {
for ( V_108 = 0 ; V_108 < 3 ; V_108 ++ ) {
F_66 ( V_10 , L_22 , V_8 , V_108 ,
( V_129 ) V_17 -> V_58 [ V_8 ] [ V_108 ] ) ;
}
}
F_66 ( V_10 , L_23 ) ;
F_66 ( V_10 , L_24 , V_17 -> V_26 ) ;
F_66 ( V_10 , L_25 , V_17 -> V_20 ) ;
F_66 ( V_10 , L_26 , V_17 -> V_60 ) ;
F_66 ( V_10 , L_27 , V_17 -> V_63 ) ;
F_66 ( V_10 , L_28 , V_17 -> V_64 ) ;
F_66 ( V_10 , L_29 ) ;
F_66 ( V_10 , L_30 ) ;
}
