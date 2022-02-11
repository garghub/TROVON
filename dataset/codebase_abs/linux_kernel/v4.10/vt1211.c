static inline void F_1 ( int V_1 , int V_2 , int V_3 )
{
F_2 ( V_2 , V_1 ) ;
F_2 ( V_3 , V_1 + 1 ) ;
}
static inline int F_3 ( int V_1 , int V_2 )
{
F_2 ( V_2 , V_1 ) ;
return F_4 ( V_1 + 1 ) ;
}
static inline void F_5 ( int V_1 , int V_4 )
{
F_2 ( V_5 , V_1 ) ;
F_2 ( V_4 , V_1 + 1 ) ;
}
static inline void F_6 ( int V_1 )
{
F_2 ( 0x87 , V_1 ) ;
F_2 ( 0x87 , V_1 ) ;
}
static inline void F_7 ( int V_1 )
{
F_2 ( 0xaa , V_1 ) ;
}
static inline T_1 F_8 ( struct V_6 * V_7 , T_1 V_2 )
{
return F_4 ( V_7 -> V_8 + V_2 ) ;
}
static inline void F_9 ( struct V_6 * V_7 , T_1 V_2 , T_1 V_3 )
{
F_2 ( V_3 , V_7 -> V_8 + V_2 ) ;
}
static struct V_6 * F_10 ( struct V_9 * V_10 )
{
struct V_6 * V_7 = F_11 ( V_10 ) ;
int V_11 , V_3 ;
F_12 ( & V_7 -> V_12 ) ;
if ( F_13 ( V_13 , V_7 -> V_14 + V_15 ) || ! V_7 -> V_16 ) {
V_7 -> V_17 = F_8 ( V_7 , V_18 ) & 0x1f ;
for ( V_11 = 0 ; V_11 < F_14 ( V_7 -> V_19 ) ; V_11 ++ ) {
if ( F_15 ( V_11 , V_7 -> V_20 ) ) {
V_7 -> V_19 [ V_11 ] = F_8 ( V_7 ,
F_16 ( V_11 ) ) ;
V_7 -> V_21 [ V_11 ] = F_8 ( V_7 ,
F_17 ( V_11 ) ) ;
V_7 -> V_22 [ V_11 ] = F_8 ( V_7 ,
F_18 ( V_11 ) ) ;
}
}
for ( V_11 = 0 ; V_11 < F_14 ( V_7 -> V_23 ) ; V_11 ++ ) {
if ( F_19 ( V_11 , V_7 -> V_20 ) ) {
V_7 -> V_23 [ V_11 ] = F_8 ( V_7 ,
V_24 [ V_11 ] ) ;
V_7 -> V_25 [ V_11 ] = F_8 ( V_7 ,
V_26 [ V_11 ] ) ;
V_7 -> V_27 [ V_11 ] = F_8 ( V_7 ,
V_28 [ V_11 ] ) ;
}
}
for ( V_11 = 0 ; V_11 < F_14 ( V_7 -> V_29 ) ; V_11 ++ ) {
V_7 -> V_29 [ V_11 ] = F_8 ( V_7 ,
F_20 ( V_11 ) ) ;
V_7 -> V_30 [ V_11 ] = F_8 ( V_7 ,
F_21 ( V_11 ) ) ;
V_7 -> V_31 [ V_11 ] = F_8 ( V_7 ,
F_22 ( V_11 ) ) ;
}
V_3 = F_8 ( V_7 , V_32 ) ;
V_7 -> V_33 [ 0 ] = ( V_3 >> 4 ) & 3 ;
V_7 -> V_33 [ 1 ] = ( V_3 >> 6 ) & 3 ;
V_7 -> V_34 = V_3 & 0xf ;
V_3 = F_8 ( V_7 , V_35 ) ;
V_7 -> V_36 [ 0 ] = V_3 & 0xf ;
V_7 -> V_36 [ 1 ] = ( V_3 >> 4 ) & 0xf ;
V_7 -> V_37 = F_8 ( V_7 , V_38 ) ;
V_7 -> V_39 [ 0 ] [ 1 ] = F_8 ( V_7 ,
F_23 ( 0 , 1 ) ) ;
V_7 -> V_39 [ 0 ] [ 2 ] = F_8 ( V_7 ,
F_23 ( 0 , 2 ) ) ;
V_7 -> V_39 [ 1 ] [ 1 ] = F_8 ( V_7 ,
F_23 ( 1 , 1 ) ) ;
V_7 -> V_39 [ 1 ] [ 2 ] = F_8 ( V_7 ,
F_23 ( 1 , 2 ) ) ;
for ( V_11 = 0 ; V_11 < F_14 ( V_7 -> V_40 ) ; V_11 ++ ) {
V_7 -> V_40 [ V_11 ] = F_8 ( V_7 ,
F_24 ( V_11 ) ) ;
}
V_7 -> V_41 = ( F_8 ( V_7 , V_42 ) << 8 ) |
F_8 ( V_7 , V_43 ) ;
V_7 -> V_14 = V_13 ;
V_7 -> V_16 = 1 ;
}
F_25 ( & V_7 -> V_12 ) ;
return V_7 ;
}
static T_2 F_26 ( struct V_9 * V_10 , struct V_44 * V_45 ,
char * V_46 )
{
struct V_6 * V_7 = F_10 ( V_10 ) ;
struct V_47 * V_48 =
F_27 ( V_45 ) ;
int V_11 = V_48 -> V_49 ;
int V_50 = V_48 -> V_51 ;
int V_52 ;
switch ( V_50 ) {
case V_53 :
V_52 = F_28 ( V_11 , V_7 -> V_19 [ V_11 ] ) ;
break;
case V_54 :
V_52 = F_28 ( V_11 , V_7 -> V_21 [ V_11 ] ) ;
break;
case V_55 :
V_52 = F_28 ( V_11 , V_7 -> V_22 [ V_11 ] ) ;
break;
case V_56 :
V_52 = ( V_7 -> V_41 >> V_57 [ V_11 ] ) & 1 ;
break;
default:
V_52 = 0 ;
F_29 ( V_10 , L_1 , V_50 ) ;
}
return sprintf ( V_46 , L_2 , V_52 ) ;
}
static T_2 F_30 ( struct V_9 * V_10 , struct V_44 * V_45 ,
const char * V_46 , T_3 V_58 )
{
struct V_6 * V_7 = F_11 ( V_10 ) ;
struct V_47 * V_48 =
F_27 ( V_45 ) ;
int V_11 = V_48 -> V_49 ;
int V_50 = V_48 -> V_51 ;
long V_3 ;
int V_59 ;
V_59 = F_31 ( V_46 , 10 , & V_3 ) ;
if ( V_59 )
return V_59 ;
F_12 ( & V_7 -> V_12 ) ;
switch ( V_50 ) {
case V_54 :
V_7 -> V_21 [ V_11 ] = F_32 ( V_11 , V_3 ) ;
F_9 ( V_7 , F_17 ( V_11 ) , V_7 -> V_21 [ V_11 ] ) ;
break;
case V_55 :
V_7 -> V_22 [ V_11 ] = F_32 ( V_11 , V_3 ) ;
F_9 ( V_7 , F_18 ( V_11 ) , V_7 -> V_22 [ V_11 ] ) ;
break;
default:
F_29 ( V_10 , L_1 , V_50 ) ;
}
F_25 ( & V_7 -> V_12 ) ;
return V_58 ;
}
static T_2 F_33 ( struct V_9 * V_10 , struct V_44 * V_45 ,
char * V_46 )
{
struct V_6 * V_7 = F_10 ( V_10 ) ;
struct V_47 * V_48 =
F_27 ( V_45 ) ;
int V_11 = V_48 -> V_49 ;
int V_50 = V_48 -> V_51 ;
int V_52 ;
switch ( V_50 ) {
case V_60 :
V_52 = F_34 ( V_11 , V_7 -> V_23 [ V_11 ] ) ;
break;
case V_61 :
V_52 = F_34 ( V_11 , V_7 -> V_25 [ V_11 ] ) ;
break;
case V_62 :
V_52 = F_34 ( V_11 , V_7 -> V_27 [ V_11 ] ) ;
break;
case V_63 :
V_52 = ( V_7 -> V_41 >> V_64 [ V_11 ] ) & 1 ;
break;
default:
V_52 = 0 ;
F_29 ( V_10 , L_1 , V_50 ) ;
}
return sprintf ( V_46 , L_2 , V_52 ) ;
}
static T_2 F_35 ( struct V_9 * V_10 , struct V_44 * V_45 ,
const char * V_46 , T_3 V_58 )
{
struct V_6 * V_7 = F_11 ( V_10 ) ;
struct V_47 * V_48 =
F_27 ( V_45 ) ;
int V_11 = V_48 -> V_49 ;
int V_50 = V_48 -> V_51 ;
long V_3 ;
int V_59 ;
V_59 = F_31 ( V_46 , 10 , & V_3 ) ;
if ( V_59 )
return V_59 ;
F_12 ( & V_7 -> V_12 ) ;
switch ( V_50 ) {
case V_61 :
V_7 -> V_25 [ V_11 ] = F_36 ( V_11 , V_3 ) ;
F_9 ( V_7 , V_26 [ V_11 ] ,
V_7 -> V_25 [ V_11 ] ) ;
break;
case V_62 :
V_7 -> V_27 [ V_11 ] = F_36 ( V_11 , V_3 ) ;
F_9 ( V_7 , V_28 [ V_11 ] ,
V_7 -> V_27 [ V_11 ] ) ;
break;
default:
F_29 ( V_10 , L_1 , V_50 ) ;
}
F_25 ( & V_7 -> V_12 ) ;
return V_58 ;
}
static T_2 F_37 ( struct V_9 * V_10 , struct V_44 * V_45 ,
char * V_46 )
{
struct V_6 * V_7 = F_10 ( V_10 ) ;
struct V_47 * V_48 =
F_27 ( V_45 ) ;
int V_11 = V_48 -> V_49 ;
int V_50 = V_48 -> V_51 ;
int V_52 ;
switch ( V_50 ) {
case V_65 :
V_52 = F_38 ( V_7 -> V_29 [ V_11 ] , V_7 -> V_33 [ V_11 ] ) ;
break;
case V_66 :
V_52 = F_38 ( V_7 -> V_30 [ V_11 ] , V_7 -> V_33 [ V_11 ] ) ;
break;
case V_67 :
V_52 = F_39 ( V_7 -> V_33 [ V_11 ] ) ;
break;
case V_68 :
V_52 = ( V_7 -> V_41 >> V_69 [ V_11 ] ) & 1 ;
break;
default:
V_52 = 0 ;
F_29 ( V_10 , L_1 , V_50 ) ;
}
return sprintf ( V_46 , L_2 , V_52 ) ;
}
static T_2 F_40 ( struct V_9 * V_10 , struct V_44 * V_45 ,
const char * V_46 , T_3 V_58 )
{
struct V_6 * V_7 = F_11 ( V_10 ) ;
struct V_47 * V_48 =
F_27 ( V_45 ) ;
int V_11 = V_48 -> V_49 ;
int V_50 = V_48 -> V_51 ;
int V_2 ;
unsigned long V_3 ;
int V_59 ;
V_59 = F_41 ( V_46 , 10 , & V_3 ) ;
if ( V_59 )
return V_59 ;
F_12 ( & V_7 -> V_12 ) ;
V_2 = F_8 ( V_7 , V_32 ) ;
V_7 -> V_33 [ 0 ] = ( V_2 >> 4 ) & 3 ;
V_7 -> V_33 [ 1 ] = ( V_2 >> 6 ) & 3 ;
V_7 -> V_34 = V_2 & 0xf ;
switch ( V_50 ) {
case V_66 :
V_7 -> V_30 [ V_11 ] = F_42 ( V_3 , V_7 -> V_33 [ V_11 ] ) ;
F_9 ( V_7 , F_21 ( V_11 ) ,
V_7 -> V_30 [ V_11 ] ) ;
break;
case V_67 :
switch ( V_3 ) {
case 1 :
V_7 -> V_33 [ V_11 ] = 0 ;
break;
case 2 :
V_7 -> V_33 [ V_11 ] = 1 ;
break;
case 4 :
V_7 -> V_33 [ V_11 ] = 2 ;
break;
case 8 :
V_7 -> V_33 [ V_11 ] = 3 ;
break;
default:
V_58 = - V_70 ;
F_43 ( V_10 ,
L_3 ,
V_3 ) ;
goto EXIT;
}
F_9 ( V_7 , V_32 ,
( ( V_7 -> V_33 [ 1 ] << 6 ) |
( V_7 -> V_33 [ 0 ] << 4 ) |
V_7 -> V_34 ) ) ;
break;
default:
F_29 ( V_10 , L_1 , V_50 ) ;
}
EXIT:
F_25 ( & V_7 -> V_12 ) ;
return V_58 ;
}
static T_2 F_44 ( struct V_9 * V_10 , struct V_44 * V_45 ,
char * V_46 )
{
struct V_6 * V_7 = F_10 ( V_10 ) ;
struct V_47 * V_48 =
F_27 ( V_45 ) ;
int V_11 = V_48 -> V_49 ;
int V_50 = V_48 -> V_51 ;
int V_52 ;
switch ( V_50 ) {
case V_71 :
V_52 = V_7 -> V_31 [ V_11 ] ;
break;
case V_72 :
V_52 = ( ( V_7 -> V_36 [ V_11 ] >> 3 ) & 1 ) ? 2 : 0 ;
break;
case V_73 :
V_52 = 90000 >> ( V_7 -> V_37 & 7 ) ;
break;
case V_74 :
V_52 = ( V_7 -> V_36 [ V_11 ] & 7 ) + 1 ;
break;
default:
V_52 = 0 ;
F_29 ( V_10 , L_1 , V_50 ) ;
}
return sprintf ( V_46 , L_2 , V_52 ) ;
}
static T_2 F_45 ( struct V_9 * V_10 , struct V_44 * V_45 ,
const char * V_46 , T_3 V_58 )
{
struct V_6 * V_7 = F_11 ( V_10 ) ;
struct V_47 * V_48 =
F_27 ( V_45 ) ;
int V_11 = V_48 -> V_49 ;
int V_50 = V_48 -> V_51 ;
int V_75 , V_2 ;
unsigned long V_3 ;
int V_59 ;
V_59 = F_41 ( V_46 , 10 , & V_3 ) ;
if ( V_59 )
return V_59 ;
F_12 ( & V_7 -> V_12 ) ;
switch ( V_50 ) {
case V_72 :
V_2 = F_8 ( V_7 , V_32 ) ;
V_7 -> V_33 [ 0 ] = ( V_2 >> 4 ) & 3 ;
V_7 -> V_33 [ 1 ] = ( V_2 >> 6 ) & 3 ;
V_7 -> V_34 = V_2 & 0xf ;
V_2 = F_8 ( V_7 , V_35 ) ;
V_7 -> V_36 [ 0 ] = V_2 & 0xf ;
V_7 -> V_36 [ 1 ] = ( V_2 >> 4 ) & 0xf ;
switch ( V_3 ) {
case 0 :
V_7 -> V_36 [ V_11 ] &= 7 ;
if ( ( V_7 -> V_36 [ V_11 ^ 1 ] & 1 ) == 0 )
V_7 -> V_34 &= 0xe ;
break;
case 2 :
V_7 -> V_36 [ V_11 ] |= 8 ;
V_7 -> V_34 |= 1 ;
break;
default:
V_58 = - V_70 ;
F_43 ( V_10 ,
L_4 ,
V_3 ) ;
goto EXIT;
}
F_9 ( V_7 , V_35 ,
( ( V_7 -> V_36 [ 1 ] << 4 ) |
V_7 -> V_36 [ 0 ] ) ) ;
F_9 ( V_7 , V_32 ,
( ( V_7 -> V_33 [ 1 ] << 6 ) |
( V_7 -> V_33 [ 0 ] << 4 ) |
V_7 -> V_34 ) ) ;
break;
case V_73 :
V_3 = 135000 / F_46 ( V_3 , 135000 >> 7 , 135000 ) ;
V_75 = 0 ;
for ( V_3 >>= 1 ; V_3 > 0 ; V_3 >>= 1 )
V_75 ++ ;
V_2 = F_8 ( V_7 , V_38 ) ;
V_7 -> V_37 = ( V_2 & 0xf8 ) | V_75 ;
F_9 ( V_7 , V_38 , V_7 -> V_37 ) ;
break;
case V_74 :
if ( V_3 < 1 || V_3 > 7 ) {
V_58 = - V_70 ;
F_43 ( V_10 ,
L_5 ,
V_3 ) ;
goto EXIT;
}
if ( ! F_19 ( V_3 - 1 , V_7 -> V_20 ) ) {
V_58 = - V_70 ;
F_43 ( V_10 , L_6 ,
V_3 ) ;
goto EXIT;
}
V_2 = F_8 ( V_7 , V_35 ) ;
V_7 -> V_36 [ 0 ] = V_2 & 0xf ;
V_7 -> V_36 [ 1 ] = ( V_2 >> 4 ) & 0xf ;
V_7 -> V_36 [ V_11 ] = ( V_7 -> V_36 [ V_11 ] & 8 ) | ( V_3 - 1 ) ;
F_9 ( V_7 , V_35 ,
( ( V_7 -> V_36 [ 1 ] << 4 ) | V_7 -> V_36 [ 0 ] ) ) ;
break;
default:
F_29 ( V_10 , L_1 , V_50 ) ;
}
EXIT:
F_25 ( & V_7 -> V_12 ) ;
return V_58 ;
}
static T_2 F_47 ( struct V_9 * V_10 ,
struct V_44 * V_45 ,
char * V_46 )
{
struct V_6 * V_7 = F_10 ( V_10 ) ;
struct V_47 * V_48 =
F_27 ( V_45 ) ;
int V_11 = V_48 -> V_49 ;
int V_76 = V_48 -> V_51 ;
return sprintf ( V_46 , L_2 , F_34 ( V_7 -> V_36 [ V_11 ] & 7 ,
V_7 -> V_40 [ V_76 ] ) ) ;
}
static T_2 F_48 ( struct V_9 * V_10 ,
struct V_44 * V_45 ,
const char * V_46 , T_3 V_58 )
{
struct V_6 * V_7 = F_11 ( V_10 ) ;
struct V_47 * V_48 =
F_27 ( V_45 ) ;
int V_11 = V_48 -> V_49 ;
int V_76 = V_48 -> V_51 ;
int V_2 ;
long V_3 ;
int V_59 ;
V_59 = F_31 ( V_46 , 10 , & V_3 ) ;
if ( V_59 )
return V_59 ;
F_12 ( & V_7 -> V_12 ) ;
V_2 = F_8 ( V_7 , V_35 ) ;
V_7 -> V_36 [ 0 ] = V_2 & 0xf ;
V_7 -> V_36 [ 1 ] = ( V_2 >> 4 ) & 0xf ;
V_7 -> V_40 [ V_76 ] = F_36 ( V_7 -> V_36 [ V_11 ] & 7 , V_3 ) ;
F_9 ( V_7 , F_24 ( V_76 ) ,
V_7 -> V_40 [ V_76 ] ) ;
F_25 ( & V_7 -> V_12 ) ;
return V_58 ;
}
static T_2 F_49 ( struct V_9 * V_10 ,
struct V_44 * V_45 ,
char * V_46 )
{
struct V_6 * V_7 = F_10 ( V_10 ) ;
struct V_47 * V_48 =
F_27 ( V_45 ) ;
int V_11 = V_48 -> V_49 ;
int V_76 = V_48 -> V_51 ;
return sprintf ( V_46 , L_2 , V_7 -> V_39 [ V_11 ] [ V_76 ] ) ;
}
static T_2 F_50 ( struct V_9 * V_10 ,
struct V_44 * V_45 ,
const char * V_46 , T_3 V_58 )
{
struct V_6 * V_7 = F_11 ( V_10 ) ;
struct V_47 * V_48 =
F_27 ( V_45 ) ;
int V_11 = V_48 -> V_49 ;
int V_76 = V_48 -> V_51 ;
unsigned long V_3 ;
int V_59 ;
V_59 = F_41 ( V_46 , 10 , & V_3 ) ;
if ( V_59 )
return V_59 ;
F_12 ( & V_7 -> V_12 ) ;
V_7 -> V_39 [ V_11 ] [ V_76 ] = F_46 ( V_3 , 0 , 255 ) ;
F_9 ( V_7 , F_23 ( V_11 , V_76 ) ,
V_7 -> V_39 [ V_11 ] [ V_76 ] ) ;
F_25 ( & V_7 -> V_12 ) ;
return V_58 ;
}
static T_2 F_51 ( struct V_9 * V_10 , struct V_44 * V_45 ,
char * V_46 )
{
struct V_6 * V_7 = F_11 ( V_10 ) ;
return sprintf ( V_46 , L_2 , V_7 -> V_77 ) ;
}
static T_2 F_52 ( struct V_9 * V_10 , struct V_44 * V_45 ,
const char * V_46 , T_3 V_58 )
{
struct V_6 * V_7 = F_11 ( V_10 ) ;
unsigned long V_3 ;
int V_59 ;
V_59 = F_41 ( V_46 , 10 , & V_3 ) ;
if ( V_59 )
return V_59 ;
if ( V_3 > 255 )
return - V_70 ;
V_7 -> V_77 = V_3 ;
return V_58 ;
}
static T_2 F_53 ( struct V_9 * V_10 , struct V_44 * V_45 ,
char * V_46 )
{
struct V_6 * V_7 = F_11 ( V_10 ) ;
return sprintf ( V_46 , L_2 , F_54 ( V_7 -> V_17 , V_7 -> V_77 ) ) ;
}
static T_2 F_55 ( struct V_9 * V_10 ,
struct V_44 * V_45 , char * V_46 )
{
struct V_6 * V_7 = F_11 ( V_10 ) ;
return sprintf ( V_46 , L_7 , V_7 -> V_78 ) ;
}
static T_2 F_56 ( struct V_9 * V_10 ,
struct V_44 * V_45 , char * V_46 )
{
struct V_6 * V_7 = F_10 ( V_10 ) ;
return sprintf ( V_46 , L_2 , V_7 -> V_41 ) ;
}
static void F_57 ( struct V_6 * V_7 )
{
V_7 -> V_77 = F_58 () ;
V_7 -> V_20 = F_8 ( V_7 , V_79 ) ;
if ( V_20 > - 1 ) {
V_7 -> V_20 = ( V_7 -> V_20 & 0x83 ) |
( V_20 << 2 ) ;
F_9 ( V_7 , V_79 , V_7 -> V_20 ) ;
}
if ( V_80 == 0 ) {
F_9 ( V_7 , V_81 , 0 ) ;
F_9 ( V_7 , V_82 , 0 ) ;
}
V_7 -> V_39 [ 0 ] [ 3 ] = 255 ;
V_7 -> V_39 [ 1 ] [ 3 ] = 255 ;
}
static void F_59 ( struct V_83 * V_84 )
{
struct V_9 * V_10 = & V_84 -> V_10 ;
int V_85 ;
for ( V_85 = 0 ; V_85 < F_14 ( V_86 ) ; V_85 ++ )
F_60 ( & V_10 -> V_87 , & V_86 [ V_85 ] ) ;
for ( V_85 = 0 ; V_85 < F_14 ( V_88 ) ; V_85 ++ )
F_60 ( & V_10 -> V_87 , & V_88 [ V_85 ] ) ;
for ( V_85 = 0 ; V_85 < F_14 ( V_89 ) ; V_85 ++ ) {
F_61 ( V_10 ,
& V_89 [ V_85 ] . V_90 ) ;
}
for ( V_85 = 0 ; V_85 < F_14 ( V_91 ) ; V_85 ++ )
F_61 ( V_10 , & V_91 [ V_85 ] ) ;
}
static int F_62 ( struct V_83 * V_84 )
{
struct V_9 * V_10 = & V_84 -> V_10 ;
struct V_6 * V_7 ;
struct V_92 * V_52 ;
int V_85 , V_59 ;
V_7 = F_63 ( V_10 , sizeof( struct V_6 ) , V_93 ) ;
if ( ! V_7 )
return - V_94 ;
V_52 = F_64 ( V_84 , V_95 , 0 ) ;
if ( ! F_65 ( V_10 , V_52 -> V_96 , F_66 ( V_52 ) ,
V_97 ) ) {
F_67 ( V_10 , L_8 ,
( unsigned long ) V_52 -> V_96 , ( unsigned long ) V_52 -> V_98 ) ;
return - V_99 ;
}
V_7 -> V_8 = V_52 -> V_96 ;
V_7 -> V_78 = V_97 ;
F_68 ( & V_7 -> V_12 ) ;
F_69 ( V_84 , V_7 ) ;
F_57 ( V_7 ) ;
for ( V_85 = 0 ; V_85 < F_14 ( V_86 ) ; V_85 ++ ) {
if ( F_15 ( V_85 , V_7 -> V_20 ) ) {
V_59 = F_70 ( & V_10 -> V_87 ,
& V_86 [ V_85 ] ) ;
if ( V_59 )
goto V_100;
}
}
for ( V_85 = 0 ; V_85 < F_14 ( V_88 ) ; V_85 ++ ) {
if ( F_19 ( V_85 , V_7 -> V_20 ) ) {
V_59 = F_70 ( & V_10 -> V_87 ,
& V_88 [ V_85 ] ) ;
if ( V_59 )
goto V_100;
}
}
for ( V_85 = 0 ; V_85 < F_14 ( V_89 ) ; V_85 ++ ) {
V_59 = F_71 ( V_10 ,
& V_89 [ V_85 ] . V_90 ) ;
if ( V_59 )
goto V_100;
}
for ( V_85 = 0 ; V_85 < F_14 ( V_91 ) ; V_85 ++ ) {
V_59 = F_71 ( V_10 ,
& V_91 [ V_85 ] ) ;
if ( V_59 )
goto V_100;
}
V_7 -> V_101 = F_72 ( V_10 ) ;
if ( F_73 ( V_7 -> V_101 ) ) {
V_59 = F_74 ( V_7 -> V_101 ) ;
F_67 ( V_10 , L_9 , V_59 ) ;
goto V_102;
}
return 0 ;
V_100:
F_67 ( V_10 , L_10 , V_59 ) ;
V_102:
F_59 ( V_84 ) ;
return V_59 ;
}
static int F_75 ( struct V_83 * V_84 )
{
struct V_6 * V_7 = F_76 ( V_84 ) ;
F_77 ( V_7 -> V_101 ) ;
F_59 ( V_84 ) ;
return 0 ;
}
static int T_4 F_78 ( unsigned short V_103 )
{
struct V_92 V_52 = {
. V_96 = V_103 ,
. V_98 = V_103 + 0x7f ,
. V_104 = V_95 ,
} ;
int V_59 ;
V_84 = F_79 ( V_97 , V_103 ) ;
if ( ! V_84 ) {
V_59 = - V_94 ;
F_80 ( L_11 , V_59 ) ;
goto EXIT;
}
V_52 . V_78 = V_84 -> V_78 ;
V_59 = F_81 ( & V_52 ) ;
if ( V_59 )
goto V_105;
V_59 = F_82 ( V_84 , & V_52 , 1 ) ;
if ( V_59 ) {
F_80 ( L_12 , V_59 ) ;
goto V_105;
}
V_59 = F_83 ( V_84 ) ;
if ( V_59 ) {
F_80 ( L_13 , V_59 ) ;
goto V_105;
}
return 0 ;
V_105:
F_84 ( V_84 ) ;
EXIT:
return V_59 ;
}
static int T_4 F_85 ( int V_1 , unsigned short * V_103 )
{
int V_59 = - V_106 ;
int V_107 ;
F_6 ( V_1 ) ;
V_107 = V_108 ? V_108 : F_3 ( V_1 , V_109 ) ;
if ( V_107 != V_110 )
goto EXIT;
F_5 ( V_1 , V_111 ) ;
if ( ( F_3 ( V_1 , V_112 ) & 1 ) == 0 ) {
F_86 ( L_14 ) ;
goto EXIT;
}
* V_103 = ( ( F_3 ( V_1 , V_113 ) << 8 ) |
( F_3 ( V_1 , V_113 + 1 ) ) ) & 0xff00 ;
if ( * V_103 == 0 ) {
F_86 ( L_15 ) ;
goto EXIT;
}
V_59 = 0 ;
F_87 ( L_16 ,
* V_103 , F_3 ( V_1 , V_114 ) ) ;
EXIT:
F_7 ( V_1 ) ;
return V_59 ;
}
static int T_4 F_88 ( void )
{
int V_59 ;
unsigned short V_103 = 0 ;
V_59 = F_85 ( V_115 , & V_103 ) ;
if ( V_59 ) {
V_59 = F_85 ( V_116 , & V_103 ) ;
if ( V_59 )
goto EXIT;
}
if ( ( V_20 < - 1 ) || ( V_20 > 31 ) ) {
V_59 = - V_70 ;
F_86 ( L_17 ,
V_20 ) ;
goto EXIT;
}
if ( ( V_80 < - 1 ) || ( V_80 > 0 ) ) {
V_59 = - V_70 ;
F_86 ( L_18 ,
V_80 ) ;
goto EXIT;
}
V_59 = F_89 ( & V_117 ) ;
if ( V_59 )
goto EXIT;
V_59 = F_78 ( V_103 ) ;
if ( V_59 )
goto V_118;
return 0 ;
V_118:
F_90 ( & V_117 ) ;
EXIT:
return V_59 ;
}
static void T_5 F_91 ( void )
{
F_92 ( V_84 ) ;
F_90 ( & V_117 ) ;
}
