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
long V_3 = F_31 ( V_46 , NULL , 10 ) ;
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
case V_59 :
V_52 = F_34 ( V_11 , V_7 -> V_23 [ V_11 ] ) ;
break;
case V_60 :
V_52 = F_34 ( V_11 , V_7 -> V_25 [ V_11 ] ) ;
break;
case V_61 :
V_52 = F_34 ( V_11 , V_7 -> V_27 [ V_11 ] ) ;
break;
case V_62 :
V_52 = ( V_7 -> V_41 >> V_63 [ V_11 ] ) & 1 ;
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
long V_3 = F_31 ( V_46 , NULL , 10 ) ;
F_12 ( & V_7 -> V_12 ) ;
switch ( V_50 ) {
case V_60 :
V_7 -> V_25 [ V_11 ] = F_36 ( V_11 , V_3 ) ;
F_9 ( V_7 , V_26 [ V_11 ] ,
V_7 -> V_25 [ V_11 ] ) ;
break;
case V_61 :
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
case V_64 :
V_52 = F_38 ( V_7 -> V_29 [ V_11 ] , V_7 -> V_33 [ V_11 ] ) ;
break;
case V_65 :
V_52 = F_38 ( V_7 -> V_30 [ V_11 ] , V_7 -> V_33 [ V_11 ] ) ;
break;
case V_66 :
V_52 = F_39 ( V_7 -> V_33 [ V_11 ] ) ;
break;
case V_67 :
V_52 = ( V_7 -> V_41 >> V_68 [ V_11 ] ) & 1 ;
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
long V_3 = F_31 ( V_46 , NULL , 10 ) ;
int V_2 ;
F_12 ( & V_7 -> V_12 ) ;
V_2 = F_8 ( V_7 , V_32 ) ;
V_7 -> V_33 [ 0 ] = ( V_2 >> 4 ) & 3 ;
V_7 -> V_33 [ 1 ] = ( V_2 >> 6 ) & 3 ;
V_7 -> V_34 = V_2 & 0xf ;
switch ( V_50 ) {
case V_65 :
V_7 -> V_30 [ V_11 ] = F_41 ( V_3 , V_7 -> V_33 [ V_11 ] ) ;
F_9 ( V_7 , F_21 ( V_11 ) ,
V_7 -> V_30 [ V_11 ] ) ;
break;
case V_66 :
switch ( V_3 ) {
case 1 : V_7 -> V_33 [ V_11 ] = 0 ; break;
case 2 : V_7 -> V_33 [ V_11 ] = 1 ; break;
case 4 : V_7 -> V_33 [ V_11 ] = 2 ; break;
case 8 : V_7 -> V_33 [ V_11 ] = 3 ; break;
default:
V_58 = - V_69 ;
F_42 ( V_10 , L_3
L_4
L_5 , V_3 ) ;
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
static T_2 F_43 ( struct V_9 * V_10 , struct V_44 * V_45 ,
char * V_46 )
{
struct V_6 * V_7 = F_10 ( V_10 ) ;
struct V_47 * V_48 =
F_27 ( V_45 ) ;
int V_11 = V_48 -> V_49 ;
int V_50 = V_48 -> V_51 ;
int V_52 ;
switch ( V_50 ) {
case V_70 :
V_52 = V_7 -> V_31 [ V_11 ] ;
break;
case V_71 :
V_52 = ( ( V_7 -> V_36 [ V_11 ] >> 3 ) & 1 ) ? 2 : 0 ;
break;
case V_72 :
V_52 = 90000 >> ( V_7 -> V_37 & 7 ) ;
break;
case V_73 :
V_52 = ( V_7 -> V_36 [ V_11 ] & 7 ) + 1 ;
break;
default:
V_52 = 0 ;
F_29 ( V_10 , L_1 , V_50 ) ;
}
return sprintf ( V_46 , L_2 , V_52 ) ;
}
static T_2 F_44 ( struct V_9 * V_10 , struct V_44 * V_45 ,
const char * V_46 , T_3 V_58 )
{
struct V_6 * V_7 = F_11 ( V_10 ) ;
struct V_47 * V_48 =
F_27 ( V_45 ) ;
int V_11 = V_48 -> V_49 ;
int V_50 = V_48 -> V_51 ;
long V_3 = F_31 ( V_46 , NULL , 10 ) ;
int V_74 , V_2 ;
F_12 ( & V_7 -> V_12 ) ;
switch ( V_50 ) {
case V_71 :
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
if ( ( V_7 -> V_36 [ V_11 ^ 1 ] & 1 ) == 0 ) {
V_7 -> V_34 &= 0xe ;
}
break;
case 2 :
V_7 -> V_36 [ V_11 ] |= 8 ;
V_7 -> V_34 |= 1 ;
break;
default:
V_58 = - V_69 ;
F_42 ( V_10 , L_6
L_7 , V_3 ) ;
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
case V_72 :
V_3 = 135000 / F_45 ( V_3 , 135000 >> 7 , 135000 ) ;
V_74 = 0 ;
for ( V_3 >>= 1 ; V_3 > 0 ; V_3 >>= 1 ) {
V_74 ++ ;
}
V_2 = F_8 ( V_7 , V_38 ) ;
V_7 -> V_37 = ( V_2 & 0xf8 ) | V_74 ;
F_9 ( V_7 , V_38 , V_7 -> V_37 ) ;
break;
case V_73 :
if ( ( V_3 < 1 ) || ( V_3 > 7 ) ) {
V_58 = - V_69 ;
F_42 ( V_10 , L_8
L_9 , V_3 ) ;
goto EXIT;
}
if ( ! F_19 ( V_3 - 1 , V_7 -> V_20 ) ) {
V_58 = - V_69 ;
F_42 ( V_10 , L_10 ,
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
static T_2 F_46 ( struct V_9 * V_10 ,
struct V_44 * V_45 ,
char * V_46 )
{
struct V_6 * V_7 = F_10 ( V_10 ) ;
struct V_47 * V_48 =
F_27 ( V_45 ) ;
int V_11 = V_48 -> V_49 ;
int V_75 = V_48 -> V_51 ;
return sprintf ( V_46 , L_2 , F_34 ( V_7 -> V_36 [ V_11 ] & 7 ,
V_7 -> V_40 [ V_75 ] ) ) ;
}
static T_2 F_47 ( struct V_9 * V_10 ,
struct V_44 * V_45 ,
const char * V_46 , T_3 V_58 )
{
struct V_6 * V_7 = F_11 ( V_10 ) ;
struct V_47 * V_48 =
F_27 ( V_45 ) ;
int V_11 = V_48 -> V_49 ;
int V_75 = V_48 -> V_51 ;
long V_3 = F_31 ( V_46 , NULL , 10 ) ;
int V_2 ;
F_12 ( & V_7 -> V_12 ) ;
V_2 = F_8 ( V_7 , V_35 ) ;
V_7 -> V_36 [ 0 ] = V_2 & 0xf ;
V_7 -> V_36 [ 1 ] = ( V_2 >> 4 ) & 0xf ;
V_7 -> V_40 [ V_75 ] = F_36 ( V_7 -> V_36 [ V_11 ] & 7 , V_3 ) ;
F_9 ( V_7 , F_24 ( V_75 ) ,
V_7 -> V_40 [ V_75 ] ) ;
F_25 ( & V_7 -> V_12 ) ;
return V_58 ;
}
static T_2 F_48 ( struct V_9 * V_10 ,
struct V_44 * V_45 ,
char * V_46 )
{
struct V_6 * V_7 = F_10 ( V_10 ) ;
struct V_47 * V_48 =
F_27 ( V_45 ) ;
int V_11 = V_48 -> V_49 ;
int V_75 = V_48 -> V_51 ;
return sprintf ( V_46 , L_2 , V_7 -> V_39 [ V_11 ] [ V_75 ] ) ;
}
static T_2 F_49 ( struct V_9 * V_10 ,
struct V_44 * V_45 ,
const char * V_46 , T_3 V_58 )
{
struct V_6 * V_7 = F_11 ( V_10 ) ;
struct V_47 * V_48 =
F_27 ( V_45 ) ;
int V_11 = V_48 -> V_49 ;
int V_75 = V_48 -> V_51 ;
long V_3 = F_31 ( V_46 , NULL , 10 ) ;
if ( ( V_3 < 0 ) || ( V_3 > 255 ) ) {
F_50 ( V_10 , L_11
L_12 , V_3 ) ;
return - V_69 ;
}
F_12 ( & V_7 -> V_12 ) ;
V_7 -> V_39 [ V_11 ] [ V_75 ] = V_3 ;
F_9 ( V_7 , F_23 ( V_11 , V_75 ) ,
V_7 -> V_39 [ V_11 ] [ V_75 ] ) ;
F_25 ( & V_7 -> V_12 ) ;
return V_58 ;
}
static T_2 F_51 ( struct V_9 * V_10 , struct V_44 * V_45 ,
char * V_46 )
{
struct V_6 * V_7 = F_11 ( V_10 ) ;
return sprintf ( V_46 , L_2 , V_7 -> V_76 ) ;
}
static T_2 F_52 ( struct V_9 * V_10 , struct V_44 * V_45 ,
const char * V_46 , T_3 V_58 )
{
struct V_6 * V_7 = F_11 ( V_10 ) ;
long V_3 = F_31 ( V_46 , NULL , 10 ) ;
V_7 -> V_76 = V_3 ;
return V_58 ;
}
static T_2 F_53 ( struct V_9 * V_10 , struct V_44 * V_45 ,
char * V_46 )
{
struct V_6 * V_7 = F_11 ( V_10 ) ;
return sprintf ( V_46 , L_2 , F_54 ( V_7 -> V_17 , V_7 -> V_76 ) ) ;
}
static T_2 F_55 ( struct V_9 * V_10 ,
struct V_44 * V_45 , char * V_46 )
{
struct V_6 * V_7 = F_11 ( V_10 ) ;
return sprintf ( V_46 , L_13 , V_7 -> V_77 ) ;
}
static T_2 F_56 ( struct V_9 * V_10 ,
struct V_44 * V_45 , char * V_46 )
{
struct V_6 * V_7 = F_10 ( V_10 ) ;
return sprintf ( V_46 , L_2 , V_7 -> V_41 ) ;
}
static void T_4 F_57 ( struct V_6 * V_7 )
{
V_7 -> V_76 = F_58 () ;
V_7 -> V_20 = F_8 ( V_7 , V_78 ) ;
if ( V_20 > - 1 ) {
V_7 -> V_20 = ( V_7 -> V_20 & 0x83 ) |
( V_20 << 2 ) ;
F_9 ( V_7 , V_78 , V_7 -> V_20 ) ;
}
if ( V_79 == 0 ) {
F_9 ( V_7 , V_80 , 0 ) ;
F_9 ( V_7 , V_81 , 0 ) ;
}
V_7 -> V_39 [ 0 ] [ 3 ] = 255 ;
V_7 -> V_39 [ 1 ] [ 3 ] = 255 ;
}
static void F_59 ( struct V_82 * V_83 )
{
struct V_9 * V_10 = & V_83 -> V_10 ;
int V_84 ;
for ( V_84 = 0 ; V_84 < F_14 ( V_85 ) ; V_84 ++ ) {
F_60 ( V_10 ,
& V_85 [ V_84 ] . V_86 ) ;
F_60 ( V_10 ,
& V_87 [ V_84 ] . V_86 ) ;
F_60 ( V_10 ,
& V_88 [ V_84 ] . V_86 ) ;
F_60 ( V_10 ,
& V_89 [ V_84 ] . V_86 ) ;
}
for ( V_84 = 0 ; V_84 < F_14 ( V_90 ) ; V_84 ++ ) {
F_60 ( V_10 ,
& V_90 [ V_84 ] . V_86 ) ;
F_60 ( V_10 ,
& V_91 [ V_84 ] . V_86 ) ;
F_60 ( V_10 ,
& V_92 [ V_84 ] . V_86 ) ;
F_60 ( V_10 ,
& V_93 [ V_84 ] . V_86 ) ;
}
for ( V_84 = 0 ; V_84 < F_14 ( V_94 ) ; V_84 ++ ) {
F_60 ( V_10 ,
& V_94 [ V_84 ] . V_86 ) ;
}
for ( V_84 = 0 ; V_84 < F_14 ( V_95 ) ; V_84 ++ ) {
F_60 ( V_10 , & V_95 [ V_84 ] ) ;
}
}
static int T_4 F_61 ( struct V_82 * V_83 )
{
struct V_9 * V_10 = & V_83 -> V_10 ;
struct V_6 * V_7 ;
struct V_96 * V_52 ;
int V_84 , V_97 ;
if ( ! ( V_7 = F_62 ( sizeof( struct V_6 ) , V_98 ) ) ) {
V_97 = - V_99 ;
F_50 ( V_10 , L_14 ) ;
goto EXIT;
}
V_52 = F_63 ( V_83 , V_100 , 0 ) ;
if ( ! F_64 ( V_52 -> V_101 , F_65 ( V_52 ) , V_102 ) ) {
V_97 = - V_103 ;
F_50 ( V_10 , L_15 ,
( unsigned long ) V_52 -> V_101 , ( unsigned long ) V_52 -> V_104 ) ;
goto V_105;
}
V_7 -> V_8 = V_52 -> V_101 ;
V_7 -> V_77 = V_102 ;
F_66 ( & V_7 -> V_12 ) ;
F_67 ( V_83 , V_7 ) ;
F_57 ( V_7 ) ;
for ( V_84 = 0 ; V_84 < F_14 ( V_85 ) ; V_84 ++ ) {
if ( F_15 ( V_84 , V_7 -> V_20 ) ) {
if ( ( V_97 = F_68 ( V_10 ,
& V_85 [ V_84 ] . V_86 ) ) ||
( V_97 = F_68 ( V_10 ,
& V_87 [ V_84 ] . V_86 ) ) ||
( V_97 = F_68 ( V_10 ,
& V_88 [ V_84 ] . V_86 ) ) ||
( V_97 = F_68 ( V_10 ,
& V_89 [ V_84 ] . V_86 ) ) ) {
goto V_106;
}
}
}
for ( V_84 = 0 ; V_84 < F_14 ( V_90 ) ; V_84 ++ ) {
if ( F_19 ( V_84 , V_7 -> V_20 ) ) {
if ( ( V_97 = F_68 ( V_10 ,
& V_90 [ V_84 ] . V_86 ) ) ||
( V_97 = F_68 ( V_10 ,
& V_91 [ V_84 ] . V_86 ) ) ||
( V_97 = F_68 ( V_10 ,
& V_92 [ V_84 ] . V_86 ) ) ||
( V_97 = F_68 ( V_10 ,
& V_93 [ V_84 ] . V_86 ) ) ) {
goto V_106;
}
}
}
for ( V_84 = 0 ; V_84 < F_14 ( V_94 ) ; V_84 ++ ) {
V_97 = F_68 ( V_10 ,
& V_94 [ V_84 ] . V_86 ) ;
if ( V_97 ) {
goto V_106;
}
}
for ( V_84 = 0 ; V_84 < F_14 ( V_95 ) ; V_84 ++ ) {
V_97 = F_68 ( V_10 ,
& V_95 [ V_84 ] ) ;
if ( V_97 ) {
goto V_106;
}
}
V_7 -> V_107 = F_69 ( V_10 ) ;
if ( F_70 ( V_7 -> V_107 ) ) {
V_97 = F_71 ( V_7 -> V_107 ) ;
F_50 ( V_10 , L_16 , V_97 ) ;
goto V_108;
}
return 0 ;
V_106:
F_50 ( V_10 , L_17 , V_97 ) ;
V_108:
F_59 ( V_83 ) ;
F_72 ( V_52 -> V_101 , F_65 ( V_52 ) ) ;
V_105:
F_67 ( V_83 , NULL ) ;
F_73 ( V_7 ) ;
EXIT:
return V_97 ;
}
static int T_5 F_74 ( struct V_82 * V_83 )
{
struct V_6 * V_7 = F_75 ( V_83 ) ;
struct V_96 * V_52 ;
F_76 ( V_7 -> V_107 ) ;
F_59 ( V_83 ) ;
F_67 ( V_83 , NULL ) ;
F_73 ( V_7 ) ;
V_52 = F_63 ( V_83 , V_100 , 0 ) ;
F_72 ( V_52 -> V_101 , F_65 ( V_52 ) ) ;
return 0 ;
}
static int T_6 F_77 ( unsigned short V_109 )
{
struct V_96 V_52 = {
. V_101 = V_109 ,
. V_104 = V_109 + 0x7f ,
. V_110 = V_100 ,
} ;
int V_97 ;
V_83 = F_78 ( V_102 , V_109 ) ;
if ( ! V_83 ) {
V_97 = - V_99 ;
F_79 ( L_18 , V_97 ) ;
goto EXIT;
}
V_52 . V_77 = V_83 -> V_77 ;
V_97 = F_80 ( & V_52 ) ;
if ( V_97 )
goto V_111;
V_97 = F_81 ( V_83 , & V_52 , 1 ) ;
if ( V_97 ) {
F_79 ( L_19 , V_97 ) ;
goto V_111;
}
V_97 = F_82 ( V_83 ) ;
if ( V_97 ) {
F_79 ( L_20 , V_97 ) ;
goto V_111;
}
return 0 ;
V_111:
F_83 ( V_83 ) ;
EXIT:
return V_97 ;
}
static int T_6 F_84 ( int V_1 , unsigned short * V_109 )
{
int V_97 = - V_112 ;
int V_113 ;
F_6 ( V_1 ) ;
V_113 = V_114 ? V_114 : F_3 ( V_1 , V_115 ) ;
if ( V_113 != V_116 ) {
goto EXIT;
}
F_5 ( V_1 , V_117 ) ;
if ( ( F_3 ( V_1 , V_118 ) & 1 ) == 0 ) {
F_85 ( L_21 ) ;
goto EXIT;
}
* V_109 = ( ( F_3 ( V_1 , V_119 ) << 8 ) |
( F_3 ( V_1 , V_119 + 1 ) ) ) & 0xff00 ;
if ( * V_109 == 0 ) {
F_85 ( L_22 ) ;
goto EXIT;
}
V_97 = 0 ;
F_86 ( L_23 ,
* V_109 , F_3 ( V_1 , V_120 ) ) ;
EXIT:
F_7 ( V_1 ) ;
return V_97 ;
}
static int T_6 F_87 ( void )
{
int V_97 ;
unsigned short V_109 = 0 ;
if ( ( V_97 = F_84 ( V_121 , & V_109 ) ) &&
( V_97 = F_84 ( V_122 , & V_109 ) ) ) {
goto EXIT;
}
if ( ( V_20 < - 1 ) || ( V_20 > 31 ) ) {
V_97 = - V_69 ;
F_85 ( L_24
L_25 , V_20 ) ;
goto EXIT;
}
if ( ( V_79 < - 1 ) || ( V_79 > 0 ) ) {
V_97 = - V_69 ;
F_85 ( L_26
L_27 , V_79 ) ;
goto EXIT;
}
V_97 = F_88 ( & V_123 ) ;
if ( V_97 ) {
goto EXIT;
}
V_97 = F_77 ( V_109 ) ;
if ( V_97 ) {
goto V_124;
}
return 0 ;
V_124:
F_89 ( & V_123 ) ;
EXIT:
return V_97 ;
}
static void T_7 F_90 ( void )
{
F_91 ( V_83 ) ;
F_89 ( & V_123 ) ;
}
