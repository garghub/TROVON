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
long V_7 = F_14 ( V_13 , NULL , 10 ) ? 1 : 0 ;
F_15 ( & V_17 -> V_23 ) ;
V_17 -> V_20 &= ~ ( 0xff << ( V_22 * 8 ) ) ;
V_17 -> V_20 |= F_1 ( V_2 , V_24 [ V_22 ] )
<< ( V_22 * 8 ) ;
V_17 -> V_20 &= ~ ( 1 << V_18 ) ;
V_17 -> V_20 |= V_7 << V_18 ;
F_3 ( V_2 , V_24 [ V_22 ] ,
( V_17 -> V_20 >> ( V_22 * 8 ) ) & 0xff ) ;
F_16 ( & V_17 -> V_23 ) ;
return V_21 ;
}
static T_2 F_17 ( struct V_9 * V_10 , struct V_11 * V_12 ,
char * V_13 )
{
struct V_14 * V_15 =
F_9 ( V_12 ) ;
struct V_16 * V_17 = F_10 ( V_10 ) ;
int V_18 = V_15 -> V_19 ;
return sprintf ( V_13 , L_1 , ( V_17 -> V_25 >> V_18 ) & 1 ) ;
}
static T_2 F_18 ( struct V_9 * V_10 , struct V_11 * V_12 ,
const char * V_13 , T_3 V_21 )
{
struct V_14 * V_15 = F_9 ( V_12 ) ;
struct V_1 * V_2 = F_12 ( V_10 ) ;
struct V_16 * V_17 = F_13 ( V_2 ) ;
unsigned long V_7 = F_19 ( V_13 , NULL , 10 ) ;
int V_6 = V_15 -> V_19 ;
F_15 ( & V_17 -> V_23 ) ;
V_17 -> V_26 [ V_6 ] = F_5 ( V_7 , F_20 ( V_17 -> V_27 [ V_6 ] ) ) ;
F_3 ( V_2 , V_28 [ V_6 ] , V_17 -> V_26 [ V_6 ] ) ;
F_16 ( & V_17 -> V_23 ) ;
return V_21 ;
}
static T_2 F_21 ( struct V_9 * V_10 , struct V_11 * V_12 ,
char * V_13 )
{
struct V_14 * V_15 = F_9 ( V_12 ) ;
int V_6 = V_15 -> V_19 ;
struct V_16 * V_17 = F_10 ( V_10 ) ;
return sprintf ( V_13 , L_2 , F_20 ( V_17 -> V_27 [ V_6 ] ) ) ;
}
static T_2 F_22 ( struct V_9 * V_10 , struct V_11 * V_12 ,
const char * V_13 , T_3 V_21 )
{
struct V_14 * V_15 = F_9 ( V_12 ) ;
struct V_1 * V_2 = F_12 ( V_10 ) ;
struct V_16 * V_17 = F_13 ( V_2 ) ;
int V_6 = V_15 -> V_19 ;
unsigned long V_29 ;
T_1 V_30 ;
T_1 V_31 ;
T_1 V_32 ;
int V_33 = 0 ;
T_1 V_34 = 0 ;
T_1 V_35 = 0 ;
V_29 = F_23 ( V_17 -> V_26 [ V_6 ] , F_20 ( V_17 -> V_27 [ V_6 ] ) ) ;
F_15 ( & V_17 -> V_23 ) ;
V_17 -> V_27 [ V_6 ] = F_7 ( V_6 , F_19 ( V_13 , NULL , 10 ) ) ;
switch ( V_6 ) {
case 0 :
V_33 = 0 ;
V_34 = 0xcf ;
V_35 = 4 ;
break;
case 1 :
V_33 = 0 ;
V_34 = 0x3f ;
V_35 = 6 ;
break;
case 2 :
V_33 = 1 ;
V_34 = 0x3f ;
V_35 = 6 ;
break;
case 3 :
V_33 = 2 ;
V_34 = 0xf8 ;
V_35 = 0 ;
break;
case 4 :
V_33 = 2 ;
V_34 = 0x8f ;
V_35 = 4 ;
break;
#ifdef F_24
default:
F_25 ( V_10 , L_3 , V_6 ) ;
V_21 = - V_36 ;
goto V_37;
#endif
}
V_31 = F_1 ( V_2 , V_38 [ V_33 ] )
& V_34 ;
V_30 = ( V_17 -> V_27 [ V_6 ] << V_35 ) & ~ V_34 ;
F_3 ( V_2 , V_38 [ V_33 ] ,
V_31 | V_30 ) ;
if ( V_6 < 3 ) {
V_34 = ~ ( 1 << ( V_6 + 5 ) ) ;
V_32 = F_1 ( V_2 , V_39 )
& V_34 ;
V_30 = ( V_17 -> V_27 [ V_6 ] << ( 3 + V_6 ) ) & ~ V_34 ;
F_3 ( V_2 , V_39 ,
V_32 | V_30 ) ;
}
V_17 -> V_26 [ V_6 ] = F_5 ( V_29 , F_20 ( V_17 -> V_27 [ V_6 ] ) ) ;
F_3 ( V_2 , V_28 [ V_6 ] , V_17 -> V_26 [ V_6 ] ) ;
#ifdef F_24
V_37:
#endif
F_16 ( & V_17 -> V_23 ) ;
return V_21 ;
}
static T_2 F_26 ( struct V_9 * V_10 , struct V_11 * V_12 ,
char * V_13 )
{
struct V_14 * V_15 = F_9 ( V_12 ) ;
int V_6 = V_15 -> V_19 ;
struct V_16 * V_17 = F_10 ( V_10 ) ;
return sprintf ( V_13 , L_2 , V_17 -> V_40 [ V_6 ] ) ;
}
static T_2 F_27 ( struct V_9 * V_10 , struct V_11 * V_12 ,
const char * V_13 , T_3 V_21 )
{
struct V_14 * V_15 = F_9 ( V_12 ) ;
struct V_1 * V_2 = F_12 ( V_10 ) ;
struct V_16 * V_17 = F_13 ( V_2 ) ;
int V_6 = V_15 -> V_19 ;
unsigned long V_7 ;
if ( F_28 ( V_13 , 10 , & V_7 ) )
return - V_36 ;
F_15 ( & V_17 -> V_23 ) ;
V_17 -> V_40 [ V_6 ] = F_6 ( V_7 , 0 , 255 ) ;
F_3 ( V_2 , V_41 [ V_6 ] , V_17 -> V_40 [ V_6 ] ) ;
F_16 ( & V_17 -> V_23 ) ;
return V_21 ;
}
static T_2 F_29 ( struct V_9 * V_10 , struct V_11 * V_12 ,
char * V_13 )
{
struct V_14 * V_15 = F_9 ( V_12 ) ;
int V_6 = V_15 -> V_19 ;
struct V_16 * V_17 = F_10 ( V_10 ) ;
return sprintf ( V_13 , L_2 , V_17 -> V_42 [ V_6 ] + 1 ) ;
}
static T_2 F_30 ( struct V_9 * V_10 ,
struct V_11 * V_12 , const char * V_13 , T_3 V_21 )
{
struct V_14 * V_15 = F_9 ( V_12 ) ;
struct V_1 * V_2 = F_12 ( V_10 ) ;
struct V_16 * V_17 = F_13 ( V_2 ) ;
int V_6 = V_15 -> V_19 ;
unsigned long V_7 ;
T_1 V_43 ;
T_1 V_44 = 0 ;
T_1 V_45 = 0 ;
T_1 V_34 = 0 ;
int V_46 = F_28 ( V_13 , 10 , & V_7 ) ;
if ( V_46 || V_7 < 1 || V_7 > 3 )
return - V_36 ;
F_15 ( & V_17 -> V_23 ) ;
V_17 -> V_42 [ V_6 ] = V_7 - 1 ;
switch ( V_6 ) {
case 0 :
V_44 = 0 ;
V_45 = 2 ;
V_34 = 0xf3 ;
break;
case 1 :
V_44 = 0 ;
V_45 = 4 ;
V_34 = 0xcf ;
break;
case 2 :
V_44 = 1 ;
V_45 = 2 ;
V_34 = 0xf3 ;
break;
}
V_43 = F_1 ( V_2 , V_47 [ V_44 ] ) ;
V_43 = ( V_43 & V_34 ) |
V_17 -> V_42 [ V_6 ] << V_45 ;
F_3 ( V_2 , V_47 [ V_44 ] , V_43 ) ;
F_16 ( & V_17 -> V_23 ) ;
return V_21 ;
}
static T_2 F_31 ( struct V_9 * V_10 ,
struct V_11 * V_12 , char * V_13 )
{
struct V_14 * V_15 = F_9 ( V_12 ) ;
struct V_16 * V_17 = F_10 ( V_10 ) ;
int V_6 = V_15 -> V_19 ;
return sprintf ( V_13 , L_1 , F_32 ( V_17 -> V_48 [ V_6 ] ) ) ;
}
static T_2 F_33 ( struct V_9 * V_10 ,
struct V_11 * V_12 , const char * V_13 , T_3 V_21 )
{
struct V_14 * V_15 = F_9 ( V_12 ) ;
struct V_1 * V_2 = F_12 ( V_10 ) ;
struct V_16 * V_17 = F_13 ( V_2 ) ;
int V_6 = V_15 -> V_19 ;
unsigned long V_7 ;
T_1 V_49 ;
if ( F_28 ( V_13 , 10 , & V_7 ) )
return - V_36 ;
F_15 ( & V_17 -> V_23 ) ;
V_17 -> V_48 [ V_6 ] = F_34 ( V_7 ) ;
V_49 = F_1 ( V_2 ,
V_50 [ V_6 ] ) & 0x80 ;
F_3 ( V_2 , V_50 [ V_6 ] ,
V_17 -> V_48 [ V_6 ] | V_49 ) ;
F_16 ( & V_17 -> V_23 ) ;
return V_21 ;
}
static T_2 F_35 ( struct V_9 * V_10 ,
struct V_11 * V_12 , char * V_13 )
{
struct V_14 * V_15 = F_9 ( V_12 ) ;
struct V_16 * V_17 = F_10 ( V_10 ) ;
int V_6 = V_15 -> V_19 ;
return sprintf ( V_13 , L_1 , F_32 ( V_17 -> V_51 [ V_6 ] ) ) ;
}
static T_2 F_36 ( struct V_9 * V_10 ,
struct V_11 * V_12 , const char * V_13 , T_3 V_21 )
{
struct V_14 * V_15 = F_9 ( V_12 ) ;
struct V_1 * V_2 = F_12 ( V_10 ) ;
struct V_16 * V_17 = F_13 ( V_2 ) ;
int V_6 = V_15 -> V_19 ;
unsigned long V_7 ;
T_1 V_49 ;
T_1 V_44 = 0 ;
T_1 V_45 = 0 ;
T_1 V_34 = 0 ;
if ( F_28 ( V_13 , 10 , & V_7 ) )
return - V_36 ;
switch ( V_6 ) {
case 0 :
V_44 = 0 ;
V_45 = 0 ;
V_34 = 0xf0 ;
break;
case 1 :
V_44 = 0 ;
V_45 = 4 ;
V_34 = 0x0f ;
break;
case 2 :
V_44 = 1 ;
V_45 = 0 ;
V_34 = 0xf0 ;
break;
}
F_15 ( & V_17 -> V_23 ) ;
V_17 -> V_51 [ V_6 ] = F_37 ( V_7 ) ;
V_49 = F_1 ( V_2 ,
V_52 [ V_44 ] ) & V_34 ;
F_3 ( V_2 , V_52 [ V_44 ] ,
( V_17 -> V_51 [ V_6 ] << V_45 ) | V_49 ) ;
F_16 ( & V_17 -> V_23 ) ;
return V_21 ;
}
static T_2 F_38 ( struct V_9 * V_10 , struct V_11 * V_53 ,
char * V_13 )
{
struct V_14 * V_12 = F_9 ( V_53 ) ;
struct V_16 * V_17 = F_10 ( V_10 ) ;
return sprintf ( V_13 , L_1 , F_32 ( V_17 -> V_54 [ V_12 -> V_19 ] ) ) ;
}
static T_2 F_39 ( struct V_9 * V_10 , struct V_11 * V_53 ,
const char * V_13 , T_3 V_21 )
{
struct V_14 * V_12 = F_9 ( V_53 ) ;
struct V_1 * V_2 = F_12 ( V_10 ) ;
struct V_16 * V_17 = F_13 ( V_2 ) ;
long V_7 = F_14 ( V_13 , NULL , 10 ) ;
int V_6 = V_12 -> V_19 ;
F_15 ( & V_17 -> V_23 ) ;
V_17 -> V_54 [ V_6 ] = F_40 ( V_7 ) ;
F_3 ( V_2 , V_55 [ V_6 ] , V_17 -> V_54 [ V_6 ] ) ;
F_16 ( & V_17 -> V_23 ) ;
return V_21 ;
}
static T_2 F_41 ( struct V_9 * V_10 , struct V_11 * V_53 ,
char * V_13 )
{
struct V_56 * V_12 = F_42 ( V_53 ) ;
struct V_16 * V_17 = F_10 ( V_10 ) ;
int V_6 = V_12 -> V_6 ;
int V_19 = V_12 -> V_19 ;
return sprintf ( V_13 , L_1 , F_43 ( V_17 -> V_57 [ V_6 ] [ V_19 ] ) ) ;
}
static T_2 F_44 ( struct V_9 * V_10 ,
struct V_11 * V_53 ,
const char * V_13 , T_3 V_21 )
{
struct V_56 * V_12 = F_42 ( V_53 ) ;
struct V_1 * V_2 = F_12 ( V_10 ) ;
struct V_16 * V_17 = F_13 ( V_2 ) ;
long V_7 = F_14 ( V_13 , NULL , 10 ) ;
int V_6 = V_12 -> V_6 ;
int V_19 = V_12 -> V_19 ;
F_15 ( & V_17 -> V_23 ) ;
V_17 -> V_57 [ V_6 ] [ V_19 ] = F_45 ( V_7 ) ;
F_3 ( V_2 , V_58 [ V_6 ] [ V_19 * 2 ] ,
V_17 -> V_57 [ V_6 ] [ V_19 ] >> 8 ) ;
F_3 ( V_2 , V_58 [ V_6 ] [ V_19 * 2 + 1 ] ,
V_17 -> V_57 [ V_6 ] [ V_19 ] & 0x80 ) ;
F_16 ( & V_17 -> V_23 ) ;
return V_21 ;
}
static T_2 F_46 ( struct V_9 * V_10 ,
struct V_11 * V_12 , char * V_13 )
{
struct V_16 * V_17 = F_10 ( V_10 ) ;
return sprintf ( V_13 , L_2 , V_17 -> V_25 ) ;
}
static T_2 F_47 ( struct V_9 * V_10 ,
struct V_11 * V_12 , char * V_13 )
{
struct V_16 * V_17 = F_10 ( V_10 ) ;
return sprintf ( V_13 , L_1 , V_17 -> V_59 ) ;
}
static T_2 F_48 ( struct V_9 * V_10 ,
struct V_11 * V_12 , char * V_13 )
{
struct V_16 * V_17 = F_10 ( V_10 ) ;
return sprintf ( V_13 , L_1 , F_49 ( V_17 -> V_20 ) ) ;
}
static T_2 F_50 ( struct V_9 * V_10 ,
struct V_11 * V_12 ,
const char * V_13 , T_3 V_21 )
{
struct V_1 * V_2 = F_12 ( V_10 ) ;
struct V_16 * V_17 = F_13 ( V_2 ) ;
long V_7 = F_14 ( V_13 , NULL , 10 ) ;
int V_8 ;
F_15 ( & V_17 -> V_23 ) ;
V_17 -> V_20 = F_51 ( V_7 ) & ~ V_60 ;
V_17 -> V_20 |= ( V_17 -> V_59 << V_61 ) ;
V_7 = V_17 -> V_20 ;
for ( V_8 = 0 ; V_8 < 3 ; V_8 ++ ) {
F_3 ( V_2 , V_24 [ V_8 ] , ( V_7 & 0xff ) ) ;
V_7 >>= 8 ;
}
F_16 ( & V_17 -> V_23 ) ;
return V_21 ;
}
static T_2 F_52 ( struct V_9 * V_10 ,
struct V_11 * V_12 ,
const char * V_13 , T_3 V_21 )
{
struct V_1 * V_2 = F_12 ( V_10 ) ;
struct V_16 * V_17 = F_13 ( V_2 ) ;
long V_7 = F_14 ( V_13 , NULL , 10 ) ;
F_15 ( & V_17 -> V_23 ) ;
V_17 -> V_59 = V_7 ? 1 : 0 ;
V_17 -> V_20 &= ~ V_60 ;
V_17 -> V_20 |= ( V_17 -> V_59 << V_61 ) ;
V_7 = ( V_17 -> V_20 >> 8 ) & 0xff ;
F_3 ( V_2 , V_24 [ 1 ] , V_7 ) ;
F_16 ( & V_17 -> V_23 ) ;
return V_21 ;
}
static T_2 F_53 ( struct V_9 * V_10 ,
struct V_11 * V_12 , char * V_13 )
{
struct V_16 * V_17 = F_10 ( V_10 ) ;
return sprintf ( V_13 , L_1 , F_54 ( V_17 -> V_62 , V_17 -> V_63 ) ) ;
}
static T_2 F_55 ( struct V_9 * V_10 ,
struct V_11 * V_12 , char * V_13 )
{
struct V_16 * V_17 = F_56 ( V_10 ) ;
return sprintf ( V_13 , L_1 , V_17 -> V_63 ) ;
}
static T_2 F_57 ( struct V_9 * V_10 ,
struct V_11 * V_12 ,
const char * V_13 , T_3 V_21 )
{
struct V_16 * V_17 = F_56 ( V_10 ) ;
V_17 -> V_63 = F_19 ( V_13 , NULL , 10 ) ;
return V_21 ;
}
static int F_58 ( struct V_1 * V_2 )
{
struct V_64 * V_65 = V_2 -> V_65 ;
struct V_16 * V_17 = F_13 ( V_2 ) ;
int V_66 = V_2 -> V_67 ;
int V_8 , V_68 , V_69 ;
T_1 V_7 ;
V_68 = F_59 ( V_65 ) ;
if ( V_70 [ 0 ] == V_68 && V_70 [ 1 ] == V_66 ) {
for ( V_8 = 2 ; V_8 <= 3 ; V_8 ++ ) {
if ( V_70 [ V_8 ] < 0x48 ||
V_70 [ V_8 ] > 0x4f ) {
F_60 ( & V_2 -> V_10 ,
L_4
L_5 ,
V_70 [ V_8 ] ) ;
V_69 = - V_71 ;
goto V_72;
}
}
F_3 ( V_2 , V_73 ,
( V_70 [ 2 ] & 0x07 ) |
( ( V_70 [ 3 ] & 0x07 ) << 4 ) ) ;
}
V_7 = F_1 ( V_2 , V_73 ) ;
if ( ! ( V_7 & 0x08 ) ) {
V_17 -> V_74 [ 0 ] = F_61 ( V_65 , 0x48 + ( V_7 & 0x7 ) ) ;
}
if ( ! ( V_7 & 0x80 ) ) {
if ( ( V_17 -> V_74 [ 0 ] != NULL ) &&
( ( V_7 & 0x7 ) == ( ( V_7 >> 4 ) & 0x7 ) ) ) {
F_60 ( & V_2 -> V_10 ,
L_6
L_7 ,
V_17 -> V_74 [ 0 ] -> V_67 ) ;
V_69 = - V_71 ;
goto V_75;
}
V_17 -> V_74 [ 1 ] = F_61 ( V_65 ,
0x48 + ( ( V_7 >> 4 ) & 0x7 ) ) ;
}
return 0 ;
V_75:
if ( V_17 -> V_74 [ 0 ] != NULL )
F_62 ( V_17 -> V_74 [ 0 ] ) ;
V_72:
return V_69 ;
}
static int F_63 ( struct V_1 * V_2 ,
struct V_76 * V_77 )
{
struct V_64 * V_65 = V_2 -> V_65 ;
int V_78 , V_79 ;
unsigned short V_66 = V_2 -> V_67 ;
if ( ! F_64 ( V_65 , V_80 ) ) {
return - V_71 ;
}
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
if ( F_1 ( V_2 , V_84 ) != V_66 )
return - V_71 ;
V_78 = F_1 ( V_2 , V_82 ) & 0x78 ;
F_3 ( V_2 , V_82 , V_78 | 0x80 ) ;
V_78 = F_1 ( V_2 , V_85 ) ;
V_79 = F_1 ( V_2 , V_83 ) ;
if ( V_78 != 0x71 || V_79 != 0x5c )
return - V_71 ;
F_65 ( V_77 -> type , L_8 , V_86 ) ;
return 0 ;
}
static int F_66 ( struct V_1 * V_2 ,
const struct V_87 * V_68 )
{
struct V_16 * V_17 ;
struct V_9 * V_10 = & V_2 -> V_10 ;
int V_8 , V_69 ;
T_1 V_88 ;
#ifdef F_24
int V_78 ;
V_78 = F_1 ( V_2 , V_89 ) ;
F_67 ( V_10 , L_9 ,
( V_78 >> 5 ) & 0x07 , ( V_78 >> 1 ) & 0x0f , V_78 ) ;
#endif
V_17 = F_68 ( sizeof( struct V_16 ) , V_90 ) ;
if ( ! V_17 ) {
V_69 = - V_91 ;
goto V_92;
}
F_69 ( V_2 , V_17 ) ;
F_70 ( & V_17 -> V_23 ) ;
V_69 = F_58 ( V_2 ) ;
if ( V_69 )
goto V_93;
F_71 ( V_2 ) ;
for ( V_8 = 0 ; V_8 < V_94 ; V_8 ++ ) {
V_17 -> V_26 [ V_8 ] = F_1 ( V_2 , V_28 [ V_8 ] ) ;
}
if ( ( V_69 = F_72 ( & V_2 -> V_10 . V_95 , & V_96 ) ) )
goto V_97;
V_88 = F_1 ( V_2 , V_98 ) & 0x10 ;
if ( V_88 ) {
V_69 = F_72 ( & V_2 -> V_10 . V_95 ,
& V_99 ) ;
if ( V_69 )
goto V_100;
}
V_17 -> V_101 = F_73 ( V_10 ) ;
if ( F_74 ( V_17 -> V_101 ) ) {
V_69 = F_75 ( V_17 -> V_101 ) ;
goto V_102;
}
return 0 ;
V_102:
if ( V_88 )
F_76 ( & V_2 -> V_10 . V_95 , & V_99 ) ;
V_100:
F_76 ( & V_2 -> V_10 . V_95 , & V_96 ) ;
V_97:
if ( V_17 -> V_74 [ 0 ] != NULL )
F_62 ( V_17 -> V_74 [ 0 ] ) ;
if ( V_17 -> V_74 [ 1 ] != NULL )
F_62 ( V_17 -> V_74 [ 1 ] ) ;
V_93:
F_77 ( V_17 ) ;
V_92:
return V_69 ;
}
static int F_78 ( struct V_1 * V_2 )
{
struct V_16 * V_17 = F_13 ( V_2 ) ;
F_79 ( V_17 -> V_101 ) ;
F_76 ( & V_2 -> V_10 . V_95 , & V_96 ) ;
if ( V_17 -> V_74 [ 0 ] != NULL )
F_62 ( V_17 -> V_74 [ 0 ] ) ;
if ( V_17 -> V_74 [ 1 ] != NULL )
F_62 ( V_17 -> V_74 [ 1 ] ) ;
F_77 ( V_17 ) ;
return 0 ;
}
static void F_71 ( struct V_1 * V_2 )
{
struct V_16 * V_17 = F_13 ( V_2 ) ;
T_1 V_103 ;
T_1 V_104 ;
if ( V_105 || V_106 ) {
V_104 = F_1 ( V_2 , V_107 ) ;
if ( V_105 ) {
F_3 ( V_2 , V_81 , 0x80 ) ;
}
F_3 ( V_2 , V_107 , V_104 | 0x80 ) ;
V_103 = F_1 ( V_2 , V_24 [ 1 ] ) ;
F_3 ( V_2 , V_24 [ 1 ] , V_103 & 0xef ) ;
if ( V_106 ) {
V_103 = F_1 ( V_2 , V_108 ) ;
if ( V_103 & 1 ) {
F_3 ( V_2 , V_108 ,
V_103 & 0xfe ) ;
}
V_103 = F_1 ( V_2 , V_109 ) ;
if ( V_103 & 1 ) {
F_3 ( V_2 , V_109 ,
V_103 & 0xfe ) ;
}
V_103 = F_1 ( V_2 , V_81 ) & 0xf7 ;
F_3 ( V_2 , V_81 , V_103 | 0x01 ) ;
}
}
V_17 -> V_63 = F_80 () ;
}
static struct V_16 * F_10 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = F_12 ( V_10 ) ;
struct V_16 * V_17 = F_13 ( V_2 ) ;
int V_8 , V_110 ;
T_1 V_111 [ 3 ] ;
T_1 V_32 ;
F_15 ( & V_17 -> V_23 ) ;
if ( F_81 ( V_112 , V_17 -> V_113 + ( V_114 * 3 ) )
|| ! V_17 -> V_115 ) {
F_67 ( V_10 , L_10 ) ;
for ( V_8 = 0 ; V_8 < V_116 ; V_8 ++ ) {
V_17 -> V_117 [ V_8 ] = F_1 ( V_2 ,
V_118 [ V_8 ] ) ;
V_17 -> V_119 [ V_8 ] = F_1 ( V_2 ,
V_120 [ V_8 ] ) ;
V_17 -> V_121 [ V_8 ] = F_1 ( V_2 ,
V_122 [ V_8 ] ) ;
}
for ( V_8 = 0 ; V_8 < V_94 ; V_8 ++ ) {
V_17 -> V_123 [ V_8 ] = F_1 ( V_2 ,
V_124 [ V_8 ] ) ;
V_17 -> V_26 [ V_8 ] = F_1 ( V_2 ,
V_28 [ V_8 ] ) ;
}
for ( V_8 = 0 ; V_8 < 3 ; V_8 ++ ) {
V_111 [ V_8 ] = F_1 ( V_2 ,
V_38 [ V_8 ] ) ;
}
V_17 -> V_27 [ 0 ] = ( V_111 [ 0 ] >> 4 ) & 0x03 ;
V_17 -> V_27 [ 1 ] = ( V_111 [ 0 ] >> 6 ) & 0x03 ;
V_17 -> V_27 [ 2 ] = ( V_111 [ 1 ] >> 6 ) & 0x03 ;
V_17 -> V_27 [ 3 ] = V_111 [ 2 ] & 0x07 ;
V_17 -> V_27 [ 4 ] = ( V_111 [ 2 ] >> 4 ) & 0x07 ;
V_32 = F_1 ( V_2 , V_39 ) ;
for ( V_8 = 0 ; V_8 < 3 ; V_8 ++ )
V_17 -> V_27 [ V_8 ] |= ( V_32 >> ( 3 + V_8 ) ) & 0x04 ;
for ( V_8 = 0 ; V_8 < V_125 ; V_8 ++ ) {
V_17 -> V_40 [ V_8 ] = F_1 ( V_2 ,
V_41 [ V_8 ] ) ;
}
for ( V_8 = 0 ; V_8 < 2 ; V_8 ++ ) {
V_111 [ V_8 ] = F_1 ( V_2 ,
V_47 [ V_8 ] ) ;
}
V_17 -> V_42 [ 0 ] = ( V_111 [ 0 ] >> 2 ) & 0x03 ;
V_17 -> V_42 [ 1 ] = ( V_111 [ 0 ] >> 4 ) & 0x03 ;
V_17 -> V_42 [ 2 ] = ( V_111 [ 1 ] >> 2 ) & 0x03 ;
for ( V_8 = 0 ; V_8 < 3 ; V_8 ++ ) {
V_17 -> V_48 [ V_8 ] = F_1 ( V_2 ,
V_50 [ V_8 ] ) & 0x7f ;
}
for ( V_8 = 0 ; V_8 < 2 ; V_8 ++ ) {
V_111 [ V_8 ] = F_1 ( V_2 ,
V_52 [ V_8 ] ) ;
}
V_17 -> V_51 [ 0 ] = V_111 [ 0 ] & 0x0f ;
V_17 -> V_51 [ 1 ] = ( V_111 [ 0 ] >> 4 ) & 0x0f ;
V_17 -> V_51 [ 2 ] = V_111 [ 1 ] & 0x0f ;
for ( V_8 = 0 ; V_8 < 3 ; V_8 ++ ) {
V_17 -> V_54 [ V_8 ] = F_1 ( V_2 ,
V_55 [ V_8 ] ) ;
}
for ( V_8 = 0 ; V_8 < 2 ; V_8 ++ ) {
for ( V_110 = 0 ; V_110 < 3 ; V_110 ++ ) {
V_17 -> V_57 [ V_8 ] [ V_110 ] =
( F_1 ( V_2 ,
V_58 [ V_8 ] [ V_110 * 2 ] ) << 8 ) |
F_1 ( V_2 ,
V_58 [ V_8 ] [ V_110 * 2 + 1 ] ) ;
}
}
V_17 -> V_25 =
F_1 ( V_2 , V_126 ) +
( F_1 ( V_2 , V_127 ) << 8 ) +
( F_1 ( V_2 , V_128 ) << 16 ) ;
V_17 -> V_20 =
F_1 ( V_2 , V_24 [ 0 ] ) +
( F_1 ( V_2 , V_24 [ 1 ] ) << 8 ) +
( F_1 ( V_2 , V_24 [ 2 ] ) << 16 ) ;
V_17 -> V_59 =
( V_17 -> V_20 >> V_61 ) & 0x01 ;
V_8 = F_1 ( V_2 , V_129 ) ;
V_17 -> V_62 = V_8 & 0x0f ;
V_17 -> V_62 |= ( F_1 ( V_2 , V_89 ) & 0x01 )
<< 4 ;
V_17 -> V_113 = V_112 ;
V_17 -> V_115 = 1 ;
}
F_16 ( & V_17 -> V_23 ) ;
#ifdef F_24
F_82 ( V_17 , V_10 ) ;
#endif
return V_17 ;
}
static void F_82 ( struct V_16 * V_17 , struct V_9 * V_10 )
{
int V_8 = 0 , V_110 = 0 ;
F_67 ( V_10 , L_11 ) ;
F_67 ( V_10 , L_12 , V_116 ) ;
for ( V_8 = 0 ; V_8 < V_116 ; V_8 ++ ) {
F_67 ( V_10 , L_13 , V_8 , V_17 -> V_117 [ V_8 ] ) ;
F_67 ( V_10 , L_14 , V_8 , V_17 -> V_121 [ V_8 ] ) ;
F_67 ( V_10 , L_15 , V_8 , V_17 -> V_119 [ V_8 ] ) ;
}
F_67 ( V_10 , L_16 , V_94 ) ;
for ( V_8 = 0 ; V_8 < V_94 ; V_8 ++ ) {
F_67 ( V_10 , L_17 , V_8 , V_17 -> V_123 [ V_8 ] ) ;
F_67 ( V_10 , L_18 , V_8 , V_17 -> V_26 [ V_8 ] ) ;
F_67 ( V_10 , L_19 , V_8 , V_17 -> V_27 [ V_8 ] ) ;
}
F_67 ( V_10 , L_20 , V_130 ) ;
for ( V_8 = 0 ; V_8 < 3 ; V_8 ++ ) {
F_67 ( V_10 , L_21 , V_8 , ( T_1 ) V_17 -> V_54 [ V_8 ] ) ;
}
for ( V_8 = 0 ; V_8 < 2 ; V_8 ++ ) {
for ( V_110 = 0 ; V_110 < 3 ; V_110 ++ ) {
F_67 ( V_10 , L_22 , V_8 , V_110 ,
( V_131 ) V_17 -> V_57 [ V_8 ] [ V_110 ] ) ;
}
}
F_67 ( V_10 , L_23 ) ;
F_67 ( V_10 , L_24 , V_17 -> V_25 ) ;
F_67 ( V_10 , L_25 , V_17 -> V_20 ) ;
F_67 ( V_10 , L_26 , V_17 -> V_59 ) ;
F_67 ( V_10 , L_27 , V_17 -> V_62 ) ;
F_67 ( V_10 , L_28 , V_17 -> V_63 ) ;
F_67 ( V_10 , L_29 ) ;
F_67 ( V_10 , L_30 ) ;
}
static int T_4 F_83 ( void )
{
return F_84 ( & V_132 ) ;
}
static void T_5 F_85 ( void )
{
F_86 ( & V_132 ) ;
}
