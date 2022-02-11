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
static inline T_2 F_5 ( int V_1 )
{
int V_2 = F_2 ( V_1 , - 128000 , 127000 ) ;
return V_2 < 0 ? ( V_2 - 500 ) / 1000 : ( V_2 + 500 ) / 1000 ;
}
static inline int F_6 ( T_2 V_1 )
{
return V_1 * 1000 ;
}
static T_3 F_7 ( struct V_4 * V_5 , struct V_6 * V_7 ,
char * V_8 )
{
struct V_9 * V_10 = F_8 ( V_7 ) ;
struct V_11 * V_12 = F_9 ( V_5 ) ;
return sprintf ( V_8 , L_1 , F_10 ( V_12 -> V_13 [ V_10 -> V_14 ] ) ) ;
}
static T_3 F_11 ( struct V_4 * V_5 , struct V_6 * V_7 ,
char * V_8 )
{
struct V_9 * V_10 = F_8 ( V_7 ) ;
struct V_11 * V_12 = F_9 ( V_5 ) ;
return sprintf ( V_8 , L_1 , F_10 ( V_12 -> V_15 [ V_10 -> V_14 ] ) ) ;
}
static T_3 F_12 ( struct V_4 * V_5 , struct V_6 * V_7 ,
char * V_8 )
{
struct V_9 * V_10 = F_8 ( V_7 ) ;
struct V_11 * V_12 = F_9 ( V_5 ) ;
return sprintf ( V_8 , L_1 , F_10 ( V_12 -> V_16 [ V_10 -> V_14 ] ) ) ;
}
static T_3 F_13 ( struct V_4 * V_5 , struct V_6 * V_7 ,
const char * V_8 , T_4 V_17 )
{
struct V_9 * V_10 = F_8 ( V_7 ) ;
struct V_11 * V_12 = F_14 ( V_5 ) ;
unsigned long V_1 = F_15 ( V_8 , NULL , 10 ) ;
int V_18 = V_10 -> V_14 ;
F_16 ( & V_12 -> V_19 ) ;
V_12 -> V_15 [ V_18 ] = F_1 ( V_1 ) ;
F_17 ( V_12 , F_18 ( V_18 ) , V_12 -> V_15 [ V_18 ] ) ;
F_19 ( & V_12 -> V_19 ) ;
return V_17 ;
}
static T_3 F_20 ( struct V_4 * V_5 , struct V_6 * V_7 ,
const char * V_8 , T_4 V_17 )
{
struct V_9 * V_10 = F_8 ( V_7 ) ;
struct V_11 * V_12 = F_14 ( V_5 ) ;
unsigned long V_1 = F_15 ( V_8 , NULL , 10 ) ;
int V_18 = V_10 -> V_14 ;
F_16 ( & V_12 -> V_19 ) ;
V_12 -> V_16 [ V_18 ] = F_1 ( V_1 ) ;
F_17 ( V_12 , F_21 ( V_18 ) , V_12 -> V_16 [ V_18 ] ) ;
F_19 ( & V_12 -> V_19 ) ;
return V_17 ;
}
static T_3 F_22 ( struct V_4 * V_5 , struct V_6 * V_7 ,
char * V_8 )
{
struct V_11 * V_12 = F_9 ( V_5 ) ;
return sprintf ( V_8 , L_1 , F_6 ( V_12 -> V_20 ) ) ;
}
static T_3 F_23 ( struct V_4 * V_5 , struct V_6 * V_7 ,
char * V_8 )
{
struct V_11 * V_12 = F_9 ( V_5 ) ;
return sprintf ( V_8 , L_1 , F_6 ( V_12 -> V_21 ) ) ;
}
static T_3 F_24 ( struct V_4 * V_5 , struct V_6 * V_7 ,
const char * V_8 , T_4 V_17 )
{
struct V_11 * V_12 = F_14 ( V_5 ) ;
long V_1 = F_25 ( V_8 , NULL , 10 ) ;
F_16 ( & V_12 -> V_19 ) ;
V_12 -> V_21 = F_5 ( V_1 ) ;
F_17 ( V_12 , V_22 , V_12 -> V_21 ) ;
F_19 ( & V_12 -> V_19 ) ;
return V_17 ;
}
static T_3 F_26 ( struct V_4 * V_5 , struct V_6 * V_7 ,
char * V_8 )
{
struct V_11 * V_12 = F_9 ( V_5 ) ;
return sprintf ( V_8 , L_1 , F_6 ( V_12 -> V_23 ) ) ;
}
static T_3 F_27 ( struct V_4 * V_5 , struct V_6 * V_7 ,
const char * V_8 , T_4 V_17 )
{
struct V_11 * V_12 = F_14 ( V_5 ) ;
long V_1 = F_25 ( V_8 , NULL , 10 ) ;
F_16 ( & V_12 -> V_19 ) ;
V_12 -> V_23 = F_5 ( V_1 ) ;
F_17 ( V_12 , V_24 , V_12 -> V_23 ) ;
F_19 ( & V_12 -> V_19 ) ;
return V_17 ;
}
static T_3 F_28 ( struct V_4 * V_5 , struct V_6 * V_7 ,
char * V_8 )
{
struct V_9 * V_10 = F_8 ( V_7 ) ;
struct V_11 * V_12 = F_9 ( V_5 ) ;
int V_18 = V_10 -> V_14 ;
return sprintf ( V_8 , L_1 , F_4 ( V_12 -> V_25 [ V_18 ] ,
F_29 ( V_12 -> V_26 [ V_18 ] ) ) ) ;
}
static T_3 F_30 ( struct V_4 * V_5 , struct V_6 * V_7 ,
char * V_8 )
{
struct V_9 * V_10 = F_8 ( V_7 ) ;
struct V_11 * V_12 = F_9 ( V_5 ) ;
int V_18 = V_10 -> V_14 ;
return sprintf ( V_8 , L_1 , F_4 ( V_12 -> V_27 [ V_18 ] ,
F_29 ( V_12 -> V_26 [ V_18 ] ) ) ) ;
}
static T_3 F_31 ( struct V_4 * V_5 , struct V_6 * V_7 ,
const char * V_8 , T_4 V_17 )
{
struct V_9 * V_10 = F_8 ( V_7 ) ;
struct V_11 * V_12 = F_14 ( V_5 ) ;
int V_18 = V_10 -> V_14 ;
unsigned long V_1 = F_15 ( V_8 , NULL , 10 ) ;
F_16 ( & V_12 -> V_19 ) ;
V_12 -> V_27 [ V_18 ] = F_3 ( V_1 , F_29 ( V_12 -> V_26 [ V_18 ] ) ) ;
F_17 ( V_12 , F_32 ( V_18 ) , V_12 -> V_27 [ V_18 ] ) ;
F_19 ( & V_12 -> V_19 ) ;
return V_17 ;
}
static T_3 F_33 ( struct V_4 * V_5 , struct V_6 * V_7 ,
char * V_8 )
{
struct V_9 * V_10 = F_8 ( V_7 ) ;
struct V_11 * V_12 = F_9 ( V_5 ) ;
return sprintf ( V_8 , L_1 , F_29 ( V_12 -> V_26 [ V_10 -> V_14 ] ) ) ;
}
static T_3 F_34 ( struct V_4 * V_5 , struct V_6 * V_7 ,
const char * V_8 , T_4 V_17 )
{
struct V_9 * V_10 = F_8 ( V_7 ) ;
struct V_11 * V_12 = F_14 ( V_5 ) ;
int V_18 = V_10 -> V_14 ;
unsigned long V_1 = F_15 ( V_8 , NULL , 10 ) ;
unsigned long V_28 ;
T_1 V_29 ;
F_16 ( & V_12 -> V_19 ) ;
V_28 = F_4 ( V_12 -> V_27 [ V_18 ] ,
F_29 ( V_12 -> V_26 [ V_18 ] ) ) ;
switch ( V_1 ) {
case 1 : V_12 -> V_26 [ V_18 ] = 0 ; break;
case 2 : V_12 -> V_26 [ V_18 ] = 1 ; break;
case 4 : V_12 -> V_26 [ V_18 ] = 2 ; break;
case 8 : V_12 -> V_26 [ V_18 ] = 3 ; break;
default:
F_35 ( V_5 , L_2
L_3 , V_1 ) ;
F_19 ( & V_12 -> V_19 ) ;
return - V_30 ;
}
V_29 = F_36 ( V_12 , V_31 ) ;
switch ( V_18 ) {
case 0 :
V_29 = ( V_29 & 0xcf ) | ( V_12 -> V_26 [ V_18 ] << 4 ) ;
break;
case 1 :
V_29 = ( V_29 & 0x3f ) | ( V_12 -> V_26 [ V_18 ] << 6 ) ;
break;
}
F_17 ( V_12 , V_31 , V_29 ) ;
V_12 -> V_27 [ V_18 ] =
F_3 ( V_28 , F_29 ( V_12 -> V_26 [ V_18 ] ) ) ;
F_17 ( V_12 , F_32 ( V_18 ) , V_12 -> V_27 [ V_18 ] ) ;
F_19 ( & V_12 -> V_19 ) ;
return V_17 ;
}
static T_3 F_37 ( struct V_4 * V_5 , struct V_6 * V_7 ,
char * V_8 )
{
struct V_11 * V_12 = F_9 ( V_5 ) ;
return sprintf ( V_8 , L_1 , F_38 ( V_12 -> V_32 , 82 ) ) ;
}
static T_3 F_39 ( struct V_4 * V_5 , struct V_6 * V_7 ,
char * V_8 )
{
struct V_11 * V_12 = F_9 ( V_5 ) ;
return sprintf ( V_8 , L_4 , V_12 -> V_33 ) ;
}
static T_3 F_40 ( struct V_4 * V_5 , struct V_6 * V_7 ,
char * V_8 )
{
struct V_11 * V_12 = F_9 ( V_5 ) ;
int V_18 = F_8 ( V_7 ) -> V_14 ;
return sprintf ( V_8 , L_4 , ( V_12 -> V_33 >> V_18 ) & 1 ) ;
}
static T_3 F_41 ( struct V_4 * V_5 , struct V_6
* V_34 , char * V_8 )
{
struct V_11 * V_12 = F_14 ( V_5 ) ;
return sprintf ( V_8 , L_5 , V_12 -> V_35 ) ;
}
static struct V_11 * F_42 ( void )
{
return V_36 ? F_43 ( V_36 ) : NULL ;
}
static int F_44 ( struct V_37 * V_38 , T_1 V_39 )
{
struct V_11 * V_40 ;
int V_41 ;
if ( ! V_36 )
return 0 ;
V_40 = F_43 ( V_36 ) ;
if ( F_36 ( V_40 , V_42 ) != V_38 -> V_43 )
return 0 ;
if ( ( F_36 ( V_40 , V_44 ) & 0xfe ) != ( V_39 & 0xfe ) )
return 0 ;
for ( V_41 = 0x2b ; V_41 <= 0x3d ; V_41 ++ ) {
if ( F_36 ( V_40 , V_41 ) !=
F_45 ( V_38 , V_41 ) )
return 0 ;
}
if ( F_36 ( V_40 , V_45 ) !=
F_45 ( V_38 , V_45 ) )
return 0 ;
for ( V_41 = 0x43 ; V_41 <= 0x46 ; V_41 ++ ) {
if ( F_36 ( V_40 , V_41 ) !=
F_45 ( V_38 , V_41 ) )
return 0 ;
}
return 1 ;
}
static int F_44 ( struct V_37 * V_38 , T_1 V_39 )
{
return 0 ;
}
static struct V_11 * F_42 ( void )
{
return NULL ;
}
static int F_46 ( struct V_37 * V_38 ,
struct V_46 * V_47 )
{
int V_41 ;
struct V_11 * V_40 = F_42 () ;
const char * V_48 ;
struct V_49 * V_50 = V_38 -> V_50 ;
int V_51 = V_38 -> V_43 ;
if ( ! F_47 ( V_50 , V_52 ) )
return - V_53 ;
if ( V_40 )
F_16 ( & V_40 -> V_19 ) ;
if ( ( F_45 ( V_38 , V_45 ) & 0x80 )
|| F_45 ( V_38 , V_42 ) != V_51 )
goto V_54;
V_41 = F_45 ( V_38 , 0x4f ) ;
if ( V_41 == 0xa3 || V_41 == 0x5c )
goto V_54;
V_41 = F_45 ( V_38 , V_44 ) ;
if ( V_41 == 0x00 || V_41 == 0x20
|| V_41 == 0x40 )
V_48 = L_6 ;
else if ( ( V_41 & 0xfe ) == 0xc0 )
V_48 = L_7 ;
else
goto V_54;
if ( F_44 ( V_38 , V_41 ) ) {
F_48 ( & V_50 -> V_5 , L_8
L_9 , V_51 ) ;
goto V_54;
}
if ( V_40 )
F_19 ( & V_40 -> V_19 ) ;
F_49 ( V_47 -> type , V_48 , V_55 ) ;
return 0 ;
V_54:
if ( V_40 )
F_19 ( & V_40 -> V_19 ) ;
return - V_53 ;
}
static int F_50 ( struct V_37 * V_38 ,
const struct V_56 * V_57 )
{
struct V_11 * V_12 ;
int V_58 ;
V_12 = F_51 ( sizeof( struct V_11 ) , V_59 ) ;
if ( ! V_12 )
return - V_60 ;
F_52 ( V_38 , V_12 ) ;
V_12 -> V_38 = V_38 ;
V_12 -> type = V_57 -> V_61 ;
F_53 ( V_12 ) ;
V_58 = F_54 ( & V_38 -> V_5 . V_62 , & V_63 ) ;
if ( V_58 )
goto V_64;
V_12 -> V_65 = F_55 ( & V_38 -> V_5 ) ;
if ( F_56 ( V_12 -> V_65 ) ) {
V_58 = F_57 ( V_12 -> V_65 ) ;
goto V_66;
}
return 0 ;
V_66:
F_58 ( & V_38 -> V_5 . V_62 , & V_63 ) ;
V_64:
F_59 ( V_12 ) ;
return V_58 ;
}
static int F_60 ( struct V_37 * V_38 )
{
struct V_11 * V_12 = F_61 ( V_38 ) ;
F_62 ( V_12 -> V_65 ) ;
F_58 ( & V_38 -> V_5 . V_62 , & V_63 ) ;
F_59 ( V_12 ) ;
return 0 ;
}
static int F_36 ( struct V_11 * V_12 , T_1 V_29 )
{
struct V_37 * V_38 = V_12 -> V_38 ;
#ifdef F_63
if ( ! V_38 ) {
int V_67 ;
F_16 ( & V_12 -> V_68 ) ;
F_64 ( V_29 , V_12 -> V_69 + V_70 ) ;
V_67 = F_65 ( V_12 -> V_69 + V_71 ) ;
F_19 ( & V_12 -> V_68 ) ;
return V_67 ;
} else
#endif
return F_45 ( V_38 , V_29 ) ;
}
static int F_17 ( struct V_11 * V_12 , T_1 V_29 , T_1 V_72 )
{
struct V_37 * V_38 = V_12 -> V_38 ;
#ifdef F_63
if ( ! V_38 ) {
F_16 ( & V_12 -> V_68 ) ;
F_64 ( V_29 , V_12 -> V_69 + V_70 ) ;
F_64 ( V_72 , V_12 -> V_69 + V_71 ) ;
F_19 ( & V_12 -> V_68 ) ;
return 0 ;
} else
#endif
return F_66 ( V_38 , V_29 , V_72 ) ;
}
static void F_53 ( struct V_11 * V_12 )
{
T_1 V_73 ;
int V_41 ;
V_73 = F_36 ( V_12 , V_45 ) ;
if ( ( V_73 & 0x09 ) != 0x01 )
F_17 ( V_12 , V_45 ,
( V_73 & 0xf7 ) | 0x01 ) ;
for ( V_41 = 0 ; V_41 < 3 ; V_41 ++ ) {
V_12 -> V_27 [ V_41 ] = F_36 ( V_12 ,
F_32 ( V_41 ) ) ;
}
F_67 ( & V_12 -> V_19 ) ;
}
static struct V_11 * F_9 ( struct V_4 * V_5 )
{
struct V_11 * V_12 = F_14 ( V_5 ) ;
int V_41 ;
F_16 ( & V_12 -> V_19 ) ;
if ( F_68 ( V_74 , V_12 -> V_75 + V_76 + V_76 / 2 )
|| ! V_12 -> V_77 ) {
F_48 ( V_5 , L_10 ) ;
for ( V_41 = 0 ; V_41 <= 6 ; V_41 ++ ) {
V_12 -> V_13 [ V_41 ] =
F_36 ( V_12 , F_69 ( V_41 ) ) ;
V_12 -> V_15 [ V_41 ] =
F_36 ( V_12 , F_18 ( V_41 ) ) ;
V_12 -> V_16 [ V_41 ] =
F_36 ( V_12 , F_21 ( V_41 ) ) ;
}
for ( V_41 = 0 ; V_41 < 3 ; V_41 ++ ) {
V_12 -> V_25 [ V_41 ] =
F_36 ( V_12 , F_70 ( V_41 ) ) ;
V_12 -> V_27 [ V_41 ] =
F_36 ( V_12 , F_32 ( V_41 ) ) ;
}
V_12 -> V_20 = F_36 ( V_12 , V_78 ) ;
V_12 -> V_21 =
F_36 ( V_12 , V_22 ) ;
V_12 -> V_23 =
F_36 ( V_12 , V_24 ) ;
V_41 = F_36 ( V_12 , V_31 ) ;
V_12 -> V_32 = V_41 & 0x0f ;
if ( V_12 -> type == V_79 )
V_12 -> V_32 |=
( F_36 ( V_12 , V_44 ) &
0x01 ) << 4 ;
else
V_12 -> V_32 |= 0x10 ;
V_12 -> V_26 [ 0 ] = ( V_41 >> 4 ) & 0x03 ;
V_12 -> V_26 [ 1 ] = V_41 >> 6 ;
V_12 -> V_33 = F_36 ( V_12 , V_80 ) +
( F_36 ( V_12 , V_81 ) << 8 ) ;
V_12 -> V_75 = V_74 ;
V_12 -> V_77 = 1 ;
V_12 -> V_26 [ 2 ] = 1 ;
}
F_19 ( & V_12 -> V_19 ) ;
return V_12 ;
}
static int T_5 F_71 ( struct V_82 * V_36 )
{
int V_58 ;
struct V_11 * V_12 ;
struct V_83 * V_67 ;
V_67 = F_72 ( V_36 , V_84 , 0 ) ;
if ( ! F_73 ( V_67 -> V_85 + V_70 , 2 , L_6 ) ) {
V_58 = - V_86 ;
goto exit;
}
V_12 = F_51 ( sizeof( struct V_11 ) , V_59 ) ;
if ( ! V_12 ) {
V_58 = - V_60 ;
goto V_87;
}
F_67 ( & V_12 -> V_68 ) ;
V_12 -> V_69 = V_67 -> V_85 ;
F_74 ( V_36 , V_12 ) ;
if ( F_36 ( V_12 , V_44 ) & 0x80 ) {
V_12 -> type = V_79 ;
V_12 -> V_35 = L_7 ;
} else {
V_12 -> type = V_88 ;
V_12 -> V_35 = L_6 ;
}
F_53 ( V_12 ) ;
if ( ( V_58 = F_54 ( & V_36 -> V_5 . V_62 , & V_63 ) )
|| ( V_58 = F_75 ( & V_36 -> V_5 , & V_89 ) ) )
goto V_90;
V_12 -> V_65 = F_55 ( & V_36 -> V_5 ) ;
if ( F_56 ( V_12 -> V_65 ) ) {
V_58 = F_57 ( V_12 -> V_65 ) ;
goto V_90;
}
return 0 ;
V_90:
F_58 ( & V_36 -> V_5 . V_62 , & V_63 ) ;
F_76 ( & V_36 -> V_5 , & V_89 ) ;
F_59 ( V_12 ) ;
V_87:
F_77 ( V_67 -> V_85 + V_70 , 2 ) ;
exit:
return V_58 ;
}
static int T_6 F_78 ( struct V_82 * V_36 )
{
struct V_11 * V_12 = F_43 ( V_36 ) ;
struct V_83 * V_67 ;
F_62 ( V_12 -> V_65 ) ;
F_58 ( & V_36 -> V_5 . V_62 , & V_63 ) ;
F_76 ( & V_36 -> V_5 , & V_89 ) ;
F_59 ( V_12 ) ;
V_67 = F_72 ( V_36 , V_84 , 0 ) ;
F_77 ( V_67 -> V_85 + V_70 , 2 ) ;
return 0 ;
}
static int T_7 F_79 ( unsigned short V_51 )
{
int V_1 , V_91 , V_92 = 0 ;
int V_93 ;
for ( V_93 = V_51 ; V_93 < V_51 + V_94 ; V_93 ++ ) {
if ( ! F_73 ( V_93 , 1 , L_6 ) ) {
F_80 ( L_11 , V_93 ) ;
goto V_95;
}
}
#define F_81
V_1 = F_65 ( V_51 + 1 ) ;
if ( F_65 ( V_51 + 2 ) != V_1
|| F_65 ( V_51 + 3 ) != V_1
|| F_65 ( V_51 + 7 ) != V_1 )
goto V_95;
#undef F_81
V_91 = F_65 ( V_51 + V_70 ) ;
if ( V_91 & 0x80 )
goto V_95;
V_1 = ~ V_91 & 0x7f ;
F_64 ( V_1 , V_51 + V_70 ) ;
if ( F_65 ( V_51 + V_70 ) != ( V_1 | 0x80 ) ) {
F_64 ( V_91 , V_51 + V_70 ) ;
goto V_95;
}
F_64 ( V_45 , V_51 + V_70 ) ;
V_1 = F_65 ( V_51 + V_71 ) ;
if ( V_1 & 0x80 )
goto V_95;
F_64 ( V_42 , V_51 + V_70 ) ;
V_1 = F_65 ( V_51 + V_71 ) ;
if ( V_1 < 0x03 || V_1 > 0x77 )
goto V_95;
if ( F_65 ( V_51 + V_70 ) & 0x80 )
goto V_95;
F_64 ( 0x4f , V_51 + V_70 ) ;
V_1 = F_65 ( V_51 + V_71 ) ;
if ( V_1 == 0xa3 || V_1 == 0x5c )
goto V_95;
F_64 ( 0x58 , V_51 + V_70 ) ;
V_1 = F_65 ( V_51 + V_71 ) ;
if ( V_1 == 0x90 )
goto V_95;
F_64 ( V_44 , V_51 + V_70 ) ;
V_1 = F_65 ( V_51 + V_71 ) ;
if ( V_1 == 0x00 || V_1 == 0x20
|| V_1 == 0x40
|| ( V_1 & 0xfe ) == 0xc0 )
V_92 = 1 ;
if ( V_92 )
F_82 ( L_12 ,
V_1 & 0x80 ? L_13 : L_14 , ( int ) V_51 ) ;
V_95:
for ( V_93 -- ; V_93 >= V_51 ; V_93 -- )
F_77 ( V_93 , 1 ) ;
return V_92 ;
}
static int T_7 F_83 ( unsigned short V_51 )
{
struct V_83 V_67 = {
. V_85 = V_51 ,
. V_96 = V_51 + V_94 - 1 ,
. V_35 = L_6 ,
. V_97 = V_84 ,
} ;
int V_58 ;
V_36 = F_84 ( L_6 , V_51 ) ;
if ( ! V_36 ) {
V_58 = - V_60 ;
F_85 ( L_15 ) ;
goto exit;
}
V_58 = F_86 ( V_36 , & V_67 , 1 ) ;
if ( V_58 ) {
F_85 ( L_16 , V_58 ) ;
goto V_98;
}
V_58 = F_87 ( V_36 ) ;
if ( V_58 ) {
F_85 ( L_17 , V_58 ) ;
goto V_98;
}
return 0 ;
V_98:
F_88 ( V_36 ) ;
exit:
V_36 = NULL ;
return V_58 ;
}
static int T_7 F_89 ( void )
{
int V_67 ;
if ( F_79 ( V_99 ) ) {
V_67 = F_90 ( & V_100 ) ;
if ( V_67 )
goto exit;
V_67 = F_83 ( V_99 ) ;
if ( V_67 )
goto V_101;
}
return 0 ;
V_101:
F_91 ( & V_100 ) ;
exit:
return V_67 ;
}
static void F_92 ( void )
{
if ( V_36 ) {
F_93 ( V_36 ) ;
F_91 ( & V_100 ) ;
}
}
static int T_7 F_89 ( void )
{
return 0 ;
}
static void F_92 ( void )
{
}
static int T_7 F_94 ( void )
{
int V_67 ;
V_67 = F_89 () ;
if ( V_67 )
goto exit;
V_67 = F_95 ( & V_102 ) ;
if ( V_67 )
goto V_103;
return 0 ;
V_103:
F_92 () ;
exit:
return V_67 ;
}
static void T_8 F_96 ( void )
{
F_92 () ;
F_97 ( & V_102 ) ;
}
