static inline T_1 F_1 ( unsigned long V_1 )
{
unsigned long V_2 = F_2 ( V_1 , 0 , 4080 ) ;
return ( V_2 + 8 ) / 16 ;
}
static inline T_1 F_3 ( long V_3 , int div )
{
if ( V_3 <= 0 )
return 255 ;
return F_2 ( ( 1350000 + V_3 * div / 2 ) / ( V_3 * div ) , 1 , 254 ) ;
}
static inline int F_4 ( T_1 V_1 , int div )
{
return V_1 == 0 ? - 1 : V_1 == 255 ? 0 : 1350000 / ( V_1 * div ) ;
}
static inline int F_5 ( T_2 V_1 )
{
return V_1 * 830 + 52120 ;
}
static inline T_2 F_6 ( int V_1 )
{
int V_2 = F_2 ( V_1 , - 54120 , 157530 ) ;
return V_2 < 0 ? ( V_2 - 5212 - 415 ) / 830 : ( V_2 - 5212 + 415 ) / 830 ;
}
static inline T_1 F_7 ( int V_1 )
{
return V_1 == 8 ? 3 : V_1 == 4 ? 2 : V_1 == 1 ? 0 : 1 ;
}
static T_3 F_8 ( struct V_4 * V_5 , struct V_6 * V_7 ,
char * V_8 )
{
struct V_9 * V_10 = F_9 ( V_5 ) ;
struct V_11 * V_12 = F_10 ( V_7 ) ;
int V_13 = V_12 -> V_14 ;
return sprintf ( V_8 , L_1 , F_11 ( V_10 -> V_15 [ V_13 ] ) ) ;
}
static T_3 F_12 ( struct V_4 * V_5 , struct V_6 * V_7 ,
char * V_8 )
{
struct V_9 * V_10 = F_9 ( V_5 ) ;
struct V_11 * V_12 = F_10 ( V_7 ) ;
int V_13 = V_12 -> V_14 ;
return sprintf ( V_8 , L_1 , F_11 ( V_10 -> V_16 [ V_13 ] ) ) ;
}
static T_3 F_13 ( struct V_4 * V_5 , struct V_6 * V_7 ,
char * V_8 )
{
struct V_9 * V_10 = F_9 ( V_5 ) ;
struct V_11 * V_12 = F_10 ( V_7 ) ;
int V_13 = V_12 -> V_14 ;
return sprintf ( V_8 , L_1 , F_11 ( V_10 -> V_17 [ V_13 ] ) ) ;
}
static T_3 F_14 ( struct V_4 * V_5 , struct V_6 * V_7 ,
const char * V_8 , T_4 V_18 )
{
struct V_9 * V_10 = F_15 ( V_5 ) ;
struct V_11 * V_12 = F_10 ( V_7 ) ;
int V_13 = V_12 -> V_14 ;
unsigned long V_1 ;
int V_19 ;
V_19 = F_16 ( V_8 , 10 , & V_1 ) ;
if ( V_19 )
return V_19 ;
F_17 ( & V_10 -> V_20 ) ;
V_10 -> V_16 [ V_13 ] = F_1 ( V_1 ) ;
F_18 ( V_10 , F_19 ( V_13 ) , V_10 -> V_16 [ V_13 ] ) ;
F_20 ( & V_10 -> V_20 ) ;
return V_18 ;
}
static T_3 F_21 ( struct V_4 * V_5 , struct V_6 * V_7 ,
const char * V_8 , T_4 V_18 )
{
struct V_9 * V_10 = F_15 ( V_5 ) ;
struct V_11 * V_12 = F_10 ( V_7 ) ;
int V_13 = V_12 -> V_14 ;
unsigned long V_1 ;
int V_19 ;
V_19 = F_16 ( V_8 , 10 , & V_1 ) ;
if ( V_19 )
return V_19 ;
F_17 ( & V_10 -> V_20 ) ;
V_10 -> V_17 [ V_13 ] = F_1 ( V_1 ) ;
F_18 ( V_10 , F_22 ( V_13 ) , V_10 -> V_17 [ V_13 ] ) ;
F_20 ( & V_10 -> V_20 ) ;
return V_18 ;
}
static T_3 F_23 ( struct V_4 * V_5 , struct V_6 * V_12 ,
char * V_8 )
{
struct V_9 * V_10 = F_9 ( V_5 ) ;
return sprintf ( V_8 , L_1 , F_5 ( V_10 -> V_21 ) ) ;
}
static T_3 F_24 ( struct V_4 * V_5 , struct V_6 * V_12 ,
char * V_8 )
{
struct V_9 * V_10 = F_9 ( V_5 ) ;
return sprintf ( V_8 , L_1 , F_5 ( V_10 -> V_22 ) ) ;
}
static T_3 F_25 ( struct V_4 * V_5 , struct V_6 * V_12 ,
const char * V_8 , T_4 V_18 )
{
struct V_9 * V_10 = F_15 ( V_5 ) ;
long V_1 ;
int V_19 ;
V_19 = F_26 ( V_8 , 10 , & V_1 ) ;
if ( V_19 )
return V_19 ;
F_17 ( & V_10 -> V_20 ) ;
V_10 -> V_22 = F_6 ( V_1 ) ;
F_18 ( V_10 , V_23 , V_10 -> V_22 ) ;
F_20 ( & V_10 -> V_20 ) ;
return V_18 ;
}
static T_3 F_27 ( struct V_4 * V_5 , struct V_6 * V_12 ,
char * V_8 )
{
struct V_9 * V_10 = F_9 ( V_5 ) ;
return sprintf ( V_8 , L_1 , F_5 ( V_10 -> V_24 ) ) ;
}
static T_3 F_28 ( struct V_4 * V_5 , struct V_6 * V_12 ,
const char * V_8 , T_4 V_18 )
{
struct V_9 * V_10 = F_15 ( V_5 ) ;
long V_1 ;
int V_19 ;
V_19 = F_26 ( V_8 , 10 , & V_1 ) ;
if ( V_19 )
return V_19 ;
F_17 ( & V_10 -> V_20 ) ;
V_10 -> V_24 = F_6 ( V_1 ) ;
F_18 ( V_10 , V_25 , V_10 -> V_24 ) ;
F_20 ( & V_10 -> V_20 ) ;
return V_18 ;
}
static T_3 F_29 ( struct V_4 * V_5 , struct V_6 * V_7 ,
char * V_8 )
{
struct V_9 * V_10 = F_9 ( V_5 ) ;
struct V_11 * V_12 = F_10 ( V_7 ) ;
int V_13 = V_12 -> V_14 ;
return sprintf ( V_8 , L_1 , F_4 ( V_10 -> V_26 [ V_13 ] ,
F_30 ( V_10 -> V_27 [ V_13 ] ) ) ) ;
}
static T_3 F_31 ( struct V_4 * V_5 , struct V_6 * V_7 ,
char * V_8 )
{
struct V_9 * V_10 = F_9 ( V_5 ) ;
struct V_11 * V_12 = F_10 ( V_7 ) ;
int V_13 = V_12 -> V_14 ;
return sprintf ( V_8 , L_1 , F_4 ( V_10 -> V_28 [ V_13 ] ,
F_30 ( V_10 -> V_27 [ V_13 ] ) ) ) ;
}
static T_3 F_32 ( struct V_4 * V_5 , struct V_6 * V_7 ,
const char * V_8 , T_4 V_18 )
{
struct V_9 * V_10 = F_15 ( V_5 ) ;
struct V_11 * V_12 = F_10 ( V_7 ) ;
int V_13 = V_12 -> V_14 ;
unsigned long V_1 ;
int V_19 ;
V_19 = F_16 ( V_8 , 10 , & V_1 ) ;
if ( V_19 )
return V_19 ;
F_17 ( & V_10 -> V_20 ) ;
V_10 -> V_28 [ V_13 ] = F_3 ( V_1 , F_30 ( V_10 -> V_27 [ V_13 ] ) ) ;
F_18 ( V_10 , F_33 ( V_13 ) , V_10 -> V_28 [ V_13 ] ) ;
F_20 ( & V_10 -> V_20 ) ;
return V_18 ;
}
static T_3 F_34 ( struct V_4 * V_5 , struct V_6 * V_7 ,
char * V_8 )
{
struct V_9 * V_10 = F_9 ( V_5 ) ;
struct V_11 * V_12 = F_10 ( V_7 ) ;
int V_13 = V_12 -> V_14 ;
return sprintf ( V_8 , L_1 , F_30 ( V_10 -> V_27 [ V_13 ] ) ) ;
}
static T_3 F_35 ( struct V_4 * V_5 , struct V_6 * V_7 ,
const char * V_8 , T_4 V_18 )
{
struct V_9 * V_10 = F_15 ( V_5 ) ;
struct V_11 * V_12 = F_10 ( V_7 ) ;
int V_13 = V_12 -> V_14 ;
unsigned long V_29 ;
int V_30 ;
unsigned long V_1 ;
int V_19 ;
V_19 = F_16 ( V_8 , 10 , & V_1 ) ;
if ( V_19 )
return V_19 ;
F_17 ( & V_10 -> V_20 ) ;
V_29 = F_4 ( V_10 -> V_28 [ V_13 ] ,
F_30 ( V_10 -> V_27 [ V_13 ] ) ) ;
V_30 = F_36 ( V_10 , V_31 ) ;
switch ( V_1 ) {
case 1 :
V_10 -> V_27 [ V_13 ] = 0 ;
break;
case 2 :
V_10 -> V_27 [ V_13 ] = 1 ;
break;
case 4 :
V_10 -> V_27 [ V_13 ] = 2 ;
break;
case 8 :
V_10 -> V_27 [ V_13 ] = 3 ;
break;
default:
F_37 ( V_5 , L_2
L_3 , V_1 ) ;
F_20 ( & V_10 -> V_20 ) ;
return - V_32 ;
}
switch ( V_13 ) {
case 0 :
V_30 = ( V_30 & 0xcf ) | ( V_10 -> V_27 [ V_13 ] << 4 ) ;
break;
case 1 :
V_30 = ( V_30 & 0x3f ) | ( V_10 -> V_27 [ V_13 ] << 6 ) ;
break;
}
F_18 ( V_10 , V_31 , V_30 ) ;
V_10 -> V_28 [ V_13 ] =
F_3 ( V_29 , F_30 ( V_10 -> V_27 [ V_13 ] ) ) ;
F_18 ( V_10 , F_33 ( V_13 ) , V_10 -> V_28 [ V_13 ] ) ;
F_20 ( & V_10 -> V_20 ) ;
return V_18 ;
}
static T_3 F_38 ( struct V_4 * V_5 , struct V_6 * V_12 ,
char * V_8 )
{
struct V_9 * V_10 = F_9 ( V_5 ) ;
return sprintf ( V_8 , L_1 , V_10 -> V_33 ) ;
}
static T_3 F_39 ( struct V_4 * V_5 , struct V_6 * V_7 ,
char * V_8 )
{
struct V_9 * V_10 = F_9 ( V_5 ) ;
int V_13 = F_10 ( V_7 ) -> V_14 ;
return sprintf ( V_8 , L_4 , ( V_10 -> V_33 >> V_13 ) & 1 ) ;
}
static T_3 F_40 ( struct V_4 * V_5 , struct V_6 * V_12 ,
char * V_8 )
{
struct V_9 * V_10 = F_15 ( V_5 ) ;
return sprintf ( V_8 , L_5 , V_10 -> V_34 ) ;
}
static int T_5 F_41 ( struct V_35 * V_36 )
{
int V_19 = 0 ;
int V_37 ;
struct V_9 * V_10 ;
struct V_38 * V_39 ;
char V_1 ;
V_39 = F_42 ( V_36 , V_40 , 0 ) ;
if ( ! F_43 ( V_39 -> V_41 , V_42 ,
V_43 . V_44 . V_34 ) ) {
V_19 = - V_45 ;
goto exit;
}
V_10 = F_44 ( sizeof( struct V_9 ) , V_46 ) ;
if ( ! V_10 ) {
V_19 = - V_47 ;
goto V_48;
}
F_45 ( & V_10 -> V_49 ) ;
F_45 ( & V_10 -> V_20 ) ;
V_10 -> V_50 = V_39 -> V_41 ;
V_10 -> V_34 = L_6 ;
F_46 ( V_36 , V_10 ) ;
V_10 -> V_51 = V_52 -> V_51 ;
V_10 -> V_53 = 3 ;
if ( V_10 -> V_51 >= V_54 ) {
F_47 ( V_52 , V_55 , & V_1 ) ;
if ( ! ( V_1 & 0x80 ) )
V_10 -> V_53 = 4 ;
}
F_48 ( V_10 ) ;
for ( V_37 = 0 ; V_37 < 2 ; V_37 ++ ) {
V_10 -> V_28 [ V_37 ] = F_36 ( V_10 ,
F_33 ( V_37 ) ) ;
}
V_19 = F_49 ( & V_36 -> V_5 . V_56 , & V_57 ) ;
if ( V_19 )
goto V_58;
if ( V_10 -> V_53 == 4 ) {
V_19 = F_49 ( & V_36 -> V_5 . V_56 , & V_59 ) ;
if ( V_19 )
goto V_60;
} else {
V_19 = F_49 ( & V_36 -> V_5 . V_56 , & V_61 ) ;
if ( V_19 )
goto V_60;
}
V_10 -> V_62 = F_50 ( & V_36 -> V_5 ) ;
if ( F_51 ( V_10 -> V_62 ) ) {
V_19 = F_52 ( V_10 -> V_62 ) ;
goto V_60;
}
return 0 ;
V_60:
F_53 ( & V_36 -> V_5 . V_56 , & V_57 ) ;
F_53 ( & V_36 -> V_5 . V_56 , & V_59 ) ;
F_53 ( & V_36 -> V_5 . V_56 , & V_61 ) ;
V_58:
F_54 ( V_10 ) ;
V_48:
F_55 ( V_39 -> V_41 , V_42 ) ;
exit:
return V_19 ;
}
static int T_6 F_56 ( struct V_35 * V_36 )
{
struct V_9 * V_10 = F_57 ( V_36 ) ;
F_58 ( V_10 -> V_62 ) ;
F_53 ( & V_36 -> V_5 . V_56 , & V_57 ) ;
F_53 ( & V_36 -> V_5 . V_56 , & V_59 ) ;
F_53 ( & V_36 -> V_5 . V_56 , & V_61 ) ;
F_55 ( V_10 -> V_50 , V_42 ) ;
F_46 ( V_36 , NULL ) ;
F_54 ( V_10 ) ;
return 0 ;
}
static int F_36 ( struct V_9 * V_10 , T_1 V_30 )
{
int V_39 ;
F_17 ( & V_10 -> V_49 ) ;
F_59 ( V_30 , V_10 -> V_50 + V_63 ) ;
V_39 = F_60 ( V_10 -> V_50 + V_64 ) ;
F_20 ( & V_10 -> V_49 ) ;
return V_39 ;
}
static void F_18 ( struct V_9 * V_10 , T_1 V_30 , T_1 V_65 )
{
F_17 ( & V_10 -> V_49 ) ;
F_59 ( V_30 , V_10 -> V_50 + V_63 ) ;
F_59 ( V_65 , V_10 -> V_50 + V_64 ) ;
F_20 ( & V_10 -> V_49 ) ;
}
static void T_5 F_48 ( struct V_9 * V_10 )
{
T_1 V_66 = F_36 ( V_10 , V_67 ) ;
if ( ! ( V_66 & 0x01 ) )
F_18 ( V_10 , V_67 ,
( V_66 & 0xf7 ) | 0x01 ) ;
}
static struct V_9 * F_9 ( struct V_4 * V_5 )
{
struct V_9 * V_10 = F_15 ( V_5 ) ;
int V_37 ;
F_17 ( & V_10 -> V_20 ) ;
if ( F_61 ( V_68 , V_10 -> V_69 + V_70 + V_70 / 2 )
|| ! V_10 -> V_71 ) {
for ( V_37 = 0 ; V_37 <= V_10 -> V_53 ; V_37 ++ ) {
V_10 -> V_15 [ V_37 ] =
F_36 ( V_10 , F_62 ( V_37 ) ) ;
V_10 -> V_16 [ V_37 ] =
F_36 ( V_10 ,
F_19 ( V_37 ) ) ;
V_10 -> V_17 [ V_37 ] =
F_36 ( V_10 ,
F_22 ( V_37 ) ) ;
}
for ( V_37 = 0 ; V_37 < 2 ; V_37 ++ ) {
V_10 -> V_26 [ V_37 ] =
F_36 ( V_10 , F_63 ( V_37 ) ) ;
V_10 -> V_28 [ V_37 ] =
F_36 ( V_10 ,
F_33 ( V_37 ) ) ;
}
if ( V_10 -> V_53 == 3 ) {
V_10 -> V_21 =
F_36 ( V_10 , V_72 ) ;
V_10 -> V_22 =
F_36 ( V_10 , V_23 ) ;
V_10 -> V_24 =
F_36 ( V_10 , V_25 ) ;
}
V_37 = F_36 ( V_10 , V_31 ) ;
V_10 -> V_27 [ 0 ] = ( V_37 >> 4 ) & 0x03 ;
V_10 -> V_27 [ 1 ] = V_37 >> 6 ;
V_10 -> V_33 =
F_36 ( V_10 , V_73 ) |
( F_36 ( V_10 , V_74 ) << 8 ) ;
V_10 -> V_69 = V_68 ;
V_10 -> V_71 = 1 ;
}
F_20 ( & V_10 -> V_20 ) ;
return V_10 ;
}
static int T_5 F_64 ( unsigned short V_75 )
{
struct V_38 V_39 = {
. V_41 = V_75 ,
. V_76 = V_75 + V_42 - 1 ,
. V_34 = L_6 ,
. V_77 = V_40 ,
} ;
int V_19 ;
V_19 = F_65 ( & V_39 ) ;
if ( V_19 )
goto exit;
V_36 = F_66 ( L_6 , V_75 ) ;
if ( ! V_36 ) {
V_19 = - V_47 ;
F_67 ( L_7 ) ;
goto exit;
}
V_19 = F_68 ( V_36 , & V_39 , 1 ) ;
if ( V_19 ) {
F_67 ( L_8 , V_19 ) ;
goto V_78;
}
V_19 = F_69 ( V_36 ) ;
if ( V_19 ) {
F_67 ( L_9 , V_19 ) ;
goto V_78;
}
return 0 ;
V_78:
F_70 ( V_36 ) ;
exit:
return V_19 ;
}
static int T_5 F_71 ( struct V_79 * V_5 ,
const struct V_80 * V_81 )
{
T_7 V_75 ;
T_1 V_82 ;
int * V_37 ;
for ( V_37 = V_83 ; * V_37 != 0 ; V_37 ++ ) {
struct V_79 * V_84 ;
V_84 = F_72 ( V_85 , * V_37 , NULL ) ;
if ( V_84 ) {
F_37 ( & V_84 -> V_5 ,
L_10 ,
* V_37 ) ;
F_73 ( V_84 ) ;
return - V_86 ;
}
}
V_87 &= ~ ( V_42 - 1 ) ;
if ( V_87 ) {
F_74 ( & V_5 -> V_5 , L_11 , V_87 ) ;
F_75 ( V_5 , V_88 , V_87 ) ;
}
if ( V_89 !=
F_76 ( V_5 , V_88 , & V_75 ) ) {
F_37 ( & V_5 -> V_5 , L_12 ) ;
return - V_86 ;
}
V_75 &= ~ ( V_42 - 1 ) ;
if ( ! V_75 ) {
F_37 ( & V_5 -> V_5 ,
L_13 ) ;
return - V_86 ;
}
if ( V_87 && V_75 != V_87 ) {
F_37 ( & V_5 -> V_5 , L_14 ) ;
return - V_86 ;
}
if ( V_89 !=
F_47 ( V_5 , V_90 , & V_82 ) ) {
F_37 ( & V_5 -> V_5 , L_15 ) ;
return - V_86 ;
}
if ( ! ( V_82 & 0x80 ) ) {
if ( ( V_89 !=
F_77 ( V_5 , V_90 ,
V_82 | 0x80 ) )
|| ( V_89 !=
F_47 ( V_5 , V_90 , & V_82 ) )
|| ( ! ( V_82 & 0x80 ) ) ) {
F_37 ( & V_5 -> V_5 , L_16 ) ;
return - V_86 ;
}
}
if ( F_78 ( & V_43 ) ) {
F_79 ( & V_5 -> V_5 , L_17 ) ;
goto exit;
}
V_52 = F_80 ( V_5 ) ;
if ( F_64 ( V_75 ) )
goto V_91;
return - V_86 ;
V_91:
F_73 ( V_5 ) ;
F_81 ( & V_43 ) ;
exit:
return - V_86 ;
}
static int T_8 F_82 ( void )
{
return F_83 ( & V_92 ) ;
}
static void T_9 F_84 ( void )
{
F_85 ( & V_92 ) ;
if ( V_52 != NULL ) {
F_86 ( V_36 ) ;
F_81 ( & V_43 ) ;
F_73 ( V_52 ) ;
V_52 = NULL ;
}
}
