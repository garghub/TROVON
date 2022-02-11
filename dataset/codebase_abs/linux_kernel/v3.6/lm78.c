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
int V_18 = V_10 -> V_14 ;
unsigned long V_1 ;
int V_19 ;
V_19 = F_15 ( V_8 , 10 , & V_1 ) ;
if ( V_19 )
return V_19 ;
F_16 ( & V_12 -> V_20 ) ;
V_12 -> V_15 [ V_18 ] = F_1 ( V_1 ) ;
F_17 ( V_12 , F_18 ( V_18 ) , V_12 -> V_15 [ V_18 ] ) ;
F_19 ( & V_12 -> V_20 ) ;
return V_17 ;
}
static T_3 F_20 ( struct V_4 * V_5 , struct V_6 * V_7 ,
const char * V_8 , T_4 V_17 )
{
struct V_9 * V_10 = F_8 ( V_7 ) ;
struct V_11 * V_12 = F_14 ( V_5 ) ;
int V_18 = V_10 -> V_14 ;
unsigned long V_1 ;
int V_19 ;
V_19 = F_15 ( V_8 , 10 , & V_1 ) ;
if ( V_19 )
return V_19 ;
F_16 ( & V_12 -> V_20 ) ;
V_12 -> V_16 [ V_18 ] = F_1 ( V_1 ) ;
F_17 ( V_12 , F_21 ( V_18 ) , V_12 -> V_16 [ V_18 ] ) ;
F_19 ( & V_12 -> V_20 ) ;
return V_17 ;
}
static T_3 F_22 ( struct V_4 * V_5 , struct V_6 * V_7 ,
char * V_8 )
{
struct V_11 * V_12 = F_9 ( V_5 ) ;
return sprintf ( V_8 , L_1 , F_6 ( V_12 -> V_21 ) ) ;
}
static T_3 F_23 ( struct V_4 * V_5 , struct V_6 * V_7 ,
char * V_8 )
{
struct V_11 * V_12 = F_9 ( V_5 ) ;
return sprintf ( V_8 , L_1 , F_6 ( V_12 -> V_22 ) ) ;
}
static T_3 F_24 ( struct V_4 * V_5 , struct V_6 * V_7 ,
const char * V_8 , T_4 V_17 )
{
struct V_11 * V_12 = F_14 ( V_5 ) ;
long V_1 ;
int V_19 ;
V_19 = F_25 ( V_8 , 10 , & V_1 ) ;
if ( V_19 )
return V_19 ;
F_16 ( & V_12 -> V_20 ) ;
V_12 -> V_22 = F_5 ( V_1 ) ;
F_17 ( V_12 , V_23 , V_12 -> V_22 ) ;
F_19 ( & V_12 -> V_20 ) ;
return V_17 ;
}
static T_3 F_26 ( struct V_4 * V_5 , struct V_6 * V_7 ,
char * V_8 )
{
struct V_11 * V_12 = F_9 ( V_5 ) ;
return sprintf ( V_8 , L_1 , F_6 ( V_12 -> V_24 ) ) ;
}
static T_3 F_27 ( struct V_4 * V_5 , struct V_6 * V_7 ,
const char * V_8 , T_4 V_17 )
{
struct V_11 * V_12 = F_14 ( V_5 ) ;
long V_1 ;
int V_19 ;
V_19 = F_25 ( V_8 , 10 , & V_1 ) ;
if ( V_19 )
return V_19 ;
F_16 ( & V_12 -> V_20 ) ;
V_12 -> V_24 = F_5 ( V_1 ) ;
F_17 ( V_12 , V_25 , V_12 -> V_24 ) ;
F_19 ( & V_12 -> V_20 ) ;
return V_17 ;
}
static T_3 F_28 ( struct V_4 * V_5 , struct V_6 * V_7 ,
char * V_8 )
{
struct V_9 * V_10 = F_8 ( V_7 ) ;
struct V_11 * V_12 = F_9 ( V_5 ) ;
int V_18 = V_10 -> V_14 ;
return sprintf ( V_8 , L_1 , F_4 ( V_12 -> V_26 [ V_18 ] ,
F_29 ( V_12 -> V_27 [ V_18 ] ) ) ) ;
}
static T_3 F_30 ( struct V_4 * V_5 , struct V_6 * V_7 ,
char * V_8 )
{
struct V_9 * V_10 = F_8 ( V_7 ) ;
struct V_11 * V_12 = F_9 ( V_5 ) ;
int V_18 = V_10 -> V_14 ;
return sprintf ( V_8 , L_1 , F_4 ( V_12 -> V_28 [ V_18 ] ,
F_29 ( V_12 -> V_27 [ V_18 ] ) ) ) ;
}
static T_3 F_31 ( struct V_4 * V_5 , struct V_6 * V_7 ,
const char * V_8 , T_4 V_17 )
{
struct V_9 * V_10 = F_8 ( V_7 ) ;
struct V_11 * V_12 = F_14 ( V_5 ) ;
int V_18 = V_10 -> V_14 ;
unsigned long V_1 ;
int V_19 ;
V_19 = F_15 ( V_8 , 10 , & V_1 ) ;
if ( V_19 )
return V_19 ;
F_16 ( & V_12 -> V_20 ) ;
V_12 -> V_28 [ V_18 ] = F_3 ( V_1 , F_29 ( V_12 -> V_27 [ V_18 ] ) ) ;
F_17 ( V_12 , F_32 ( V_18 ) , V_12 -> V_28 [ V_18 ] ) ;
F_19 ( & V_12 -> V_20 ) ;
return V_17 ;
}
static T_3 F_33 ( struct V_4 * V_5 , struct V_6 * V_7 ,
char * V_8 )
{
struct V_9 * V_10 = F_8 ( V_7 ) ;
struct V_11 * V_12 = F_9 ( V_5 ) ;
return sprintf ( V_8 , L_1 , F_29 ( V_12 -> V_27 [ V_10 -> V_14 ] ) ) ;
}
static T_3 F_34 ( struct V_4 * V_5 , struct V_6 * V_7 ,
const char * V_8 , T_4 V_17 )
{
struct V_9 * V_10 = F_8 ( V_7 ) ;
struct V_11 * V_12 = F_14 ( V_5 ) ;
int V_18 = V_10 -> V_14 ;
unsigned long V_29 ;
T_1 V_30 ;
unsigned long V_1 ;
int V_19 ;
V_19 = F_15 ( V_8 , 10 , & V_1 ) ;
if ( V_19 )
return V_19 ;
F_16 ( & V_12 -> V_20 ) ;
V_29 = F_4 ( V_12 -> V_28 [ V_18 ] ,
F_29 ( V_12 -> V_27 [ V_18 ] ) ) ;
switch ( V_1 ) {
case 1 :
V_12 -> V_27 [ V_18 ] = 0 ;
break;
case 2 :
V_12 -> V_27 [ V_18 ] = 1 ;
break;
case 4 :
V_12 -> V_27 [ V_18 ] = 2 ;
break;
case 8 :
V_12 -> V_27 [ V_18 ] = 3 ;
break;
default:
F_35 ( V_5 , L_2
L_3 , V_1 ) ;
F_19 ( & V_12 -> V_20 ) ;
return - V_31 ;
}
V_30 = F_36 ( V_12 , V_32 ) ;
switch ( V_18 ) {
case 0 :
V_30 = ( V_30 & 0xcf ) | ( V_12 -> V_27 [ V_18 ] << 4 ) ;
break;
case 1 :
V_30 = ( V_30 & 0x3f ) | ( V_12 -> V_27 [ V_18 ] << 6 ) ;
break;
}
F_17 ( V_12 , V_32 , V_30 ) ;
V_12 -> V_28 [ V_18 ] =
F_3 ( V_29 , F_29 ( V_12 -> V_27 [ V_18 ] ) ) ;
F_17 ( V_12 , F_32 ( V_18 ) , V_12 -> V_28 [ V_18 ] ) ;
F_19 ( & V_12 -> V_20 ) ;
return V_17 ;
}
static T_3 F_37 ( struct V_4 * V_5 , struct V_6 * V_7 ,
char * V_8 )
{
struct V_11 * V_12 = F_9 ( V_5 ) ;
return sprintf ( V_8 , L_1 , F_38 ( V_12 -> V_33 , 82 ) ) ;
}
static T_3 F_39 ( struct V_4 * V_5 , struct V_6 * V_7 ,
char * V_8 )
{
struct V_11 * V_12 = F_9 ( V_5 ) ;
return sprintf ( V_8 , L_4 , V_12 -> V_34 ) ;
}
static T_3 F_40 ( struct V_4 * V_5 , struct V_6 * V_7 ,
char * V_8 )
{
struct V_11 * V_12 = F_9 ( V_5 ) ;
int V_18 = F_8 ( V_7 ) -> V_14 ;
return sprintf ( V_8 , L_4 , ( V_12 -> V_34 >> V_18 ) & 1 ) ;
}
static T_3 F_41 ( struct V_4 * V_5 , struct V_6
* V_35 , char * V_8 )
{
struct V_11 * V_12 = F_14 ( V_5 ) ;
return sprintf ( V_8 , L_5 , V_12 -> V_36 ) ;
}
static struct V_11 * F_42 ( void )
{
return V_37 ? F_43 ( V_37 ) : NULL ;
}
static int F_44 ( struct V_38 * V_39 , T_1 V_40 )
{
struct V_11 * V_41 ;
int V_42 ;
if ( ! V_37 )
return 0 ;
V_41 = F_43 ( V_37 ) ;
if ( F_36 ( V_41 , V_43 ) != V_39 -> V_44 )
return 0 ;
if ( ( F_36 ( V_41 , V_45 ) & 0xfe ) != ( V_40 & 0xfe ) )
return 0 ;
for ( V_42 = 0x2b ; V_42 <= 0x3d ; V_42 ++ ) {
if ( F_36 ( V_41 , V_42 ) !=
F_45 ( V_39 , V_42 ) )
return 0 ;
}
if ( F_36 ( V_41 , V_46 ) !=
F_45 ( V_39 , V_46 ) )
return 0 ;
for ( V_42 = 0x43 ; V_42 <= 0x46 ; V_42 ++ ) {
if ( F_36 ( V_41 , V_42 ) !=
F_45 ( V_39 , V_42 ) )
return 0 ;
}
return 1 ;
}
static int F_44 ( struct V_38 * V_39 , T_1 V_40 )
{
return 0 ;
}
static struct V_11 * F_42 ( void )
{
return NULL ;
}
static int F_46 ( struct V_38 * V_39 ,
struct V_47 * V_48 )
{
int V_42 ;
struct V_11 * V_41 = F_42 () ;
const char * V_49 ;
struct V_50 * V_51 = V_39 -> V_51 ;
int V_52 = V_39 -> V_44 ;
if ( ! F_47 ( V_51 , V_53 ) )
return - V_54 ;
if ( V_41 )
F_16 ( & V_41 -> V_20 ) ;
if ( ( F_45 ( V_39 , V_46 ) & 0x80 )
|| F_45 ( V_39 , V_43 ) != V_52 )
goto V_55;
V_42 = F_45 ( V_39 , 0x4f ) ;
if ( V_42 == 0xa3 || V_42 == 0x5c )
goto V_55;
V_42 = F_45 ( V_39 , V_45 ) ;
if ( V_42 == 0x00 || V_42 == 0x20
|| V_42 == 0x40 )
V_49 = L_6 ;
else if ( ( V_42 & 0xfe ) == 0xc0 )
V_49 = L_7 ;
else
goto V_55;
if ( F_44 ( V_39 , V_42 ) ) {
F_48 ( & V_51 -> V_5 , L_8
L_9 , V_52 ) ;
goto V_55;
}
if ( V_41 )
F_19 ( & V_41 -> V_20 ) ;
F_49 ( V_48 -> type , V_49 , V_56 ) ;
return 0 ;
V_55:
if ( V_41 )
F_19 ( & V_41 -> V_20 ) ;
return - V_54 ;
}
static int F_50 ( struct V_38 * V_39 ,
const struct V_57 * V_58 )
{
struct V_11 * V_12 ;
int V_19 ;
V_12 = F_51 ( & V_39 -> V_5 , sizeof( struct V_11 ) , V_59 ) ;
if ( ! V_12 )
return - V_60 ;
F_52 ( V_39 , V_12 ) ;
V_12 -> V_39 = V_39 ;
V_12 -> type = V_58 -> V_61 ;
F_53 ( V_12 ) ;
V_19 = F_54 ( & V_39 -> V_5 . V_62 , & V_63 ) ;
if ( V_19 )
return V_19 ;
V_12 -> V_64 = F_55 ( & V_39 -> V_5 ) ;
if ( F_56 ( V_12 -> V_64 ) ) {
V_19 = F_57 ( V_12 -> V_64 ) ;
goto error;
}
return 0 ;
error:
F_58 ( & V_39 -> V_5 . V_62 , & V_63 ) ;
return V_19 ;
}
static int F_59 ( struct V_38 * V_39 )
{
struct V_11 * V_12 = F_60 ( V_39 ) ;
F_61 ( V_12 -> V_64 ) ;
F_58 ( & V_39 -> V_5 . V_62 , & V_63 ) ;
return 0 ;
}
static int F_36 ( struct V_11 * V_12 , T_1 V_30 )
{
struct V_38 * V_39 = V_12 -> V_39 ;
#ifdef F_62
if ( ! V_39 ) {
int V_65 ;
F_16 ( & V_12 -> V_66 ) ;
F_63 ( V_30 , V_12 -> V_67 + V_68 ) ;
V_65 = F_64 ( V_12 -> V_67 + V_69 ) ;
F_19 ( & V_12 -> V_66 ) ;
return V_65 ;
} else
#endif
return F_45 ( V_39 , V_30 ) ;
}
static int F_17 ( struct V_11 * V_12 , T_1 V_30 , T_1 V_70 )
{
struct V_38 * V_39 = V_12 -> V_39 ;
#ifdef F_62
if ( ! V_39 ) {
F_16 ( & V_12 -> V_66 ) ;
F_63 ( V_30 , V_12 -> V_67 + V_68 ) ;
F_63 ( V_70 , V_12 -> V_67 + V_69 ) ;
F_19 ( & V_12 -> V_66 ) ;
return 0 ;
} else
#endif
return F_65 ( V_39 , V_30 , V_70 ) ;
}
static void F_53 ( struct V_11 * V_12 )
{
T_1 V_71 ;
int V_42 ;
V_71 = F_36 ( V_12 , V_46 ) ;
if ( ( V_71 & 0x09 ) != 0x01 )
F_17 ( V_12 , V_46 ,
( V_71 & 0xf7 ) | 0x01 ) ;
for ( V_42 = 0 ; V_42 < 3 ; V_42 ++ ) {
V_12 -> V_28 [ V_42 ] = F_36 ( V_12 ,
F_32 ( V_42 ) ) ;
}
F_66 ( & V_12 -> V_20 ) ;
}
static struct V_11 * F_9 ( struct V_4 * V_5 )
{
struct V_11 * V_12 = F_14 ( V_5 ) ;
int V_42 ;
F_16 ( & V_12 -> V_20 ) ;
if ( F_67 ( V_72 , V_12 -> V_73 + V_74 + V_74 / 2 )
|| ! V_12 -> V_75 ) {
F_48 ( V_5 , L_10 ) ;
for ( V_42 = 0 ; V_42 <= 6 ; V_42 ++ ) {
V_12 -> V_13 [ V_42 ] =
F_36 ( V_12 , F_68 ( V_42 ) ) ;
V_12 -> V_15 [ V_42 ] =
F_36 ( V_12 , F_18 ( V_42 ) ) ;
V_12 -> V_16 [ V_42 ] =
F_36 ( V_12 , F_21 ( V_42 ) ) ;
}
for ( V_42 = 0 ; V_42 < 3 ; V_42 ++ ) {
V_12 -> V_26 [ V_42 ] =
F_36 ( V_12 , F_69 ( V_42 ) ) ;
V_12 -> V_28 [ V_42 ] =
F_36 ( V_12 , F_32 ( V_42 ) ) ;
}
V_12 -> V_21 = F_36 ( V_12 , V_76 ) ;
V_12 -> V_22 =
F_36 ( V_12 , V_23 ) ;
V_12 -> V_24 =
F_36 ( V_12 , V_25 ) ;
V_42 = F_36 ( V_12 , V_32 ) ;
V_12 -> V_33 = V_42 & 0x0f ;
if ( V_12 -> type == V_77 )
V_12 -> V_33 |=
( F_36 ( V_12 , V_45 ) &
0x01 ) << 4 ;
else
V_12 -> V_33 |= 0x10 ;
V_12 -> V_27 [ 0 ] = ( V_42 >> 4 ) & 0x03 ;
V_12 -> V_27 [ 1 ] = V_42 >> 6 ;
V_12 -> V_34 = F_36 ( V_12 , V_78 ) +
( F_36 ( V_12 , V_79 ) << 8 ) ;
V_12 -> V_73 = V_72 ;
V_12 -> V_75 = 1 ;
V_12 -> V_27 [ 2 ] = 1 ;
}
F_19 ( & V_12 -> V_20 ) ;
return V_12 ;
}
static int T_5 F_70 ( struct V_80 * V_37 )
{
int V_19 ;
struct V_11 * V_12 ;
struct V_81 * V_65 ;
V_65 = F_71 ( V_37 , V_82 , 0 ) ;
if ( ! F_72 ( & V_37 -> V_5 , V_65 -> V_83 + V_68 ,
2 , L_6 ) )
return - V_84 ;
V_12 = F_51 ( & V_37 -> V_5 , sizeof( struct V_11 ) , V_59 ) ;
if ( ! V_12 )
return - V_60 ;
F_66 ( & V_12 -> V_66 ) ;
V_12 -> V_67 = V_65 -> V_83 ;
F_73 ( V_37 , V_12 ) ;
if ( F_36 ( V_12 , V_45 ) & 0x80 ) {
V_12 -> type = V_77 ;
V_12 -> V_36 = L_7 ;
} else {
V_12 -> type = V_85 ;
V_12 -> V_36 = L_6 ;
}
F_53 ( V_12 ) ;
V_19 = F_54 ( & V_37 -> V_5 . V_62 , & V_63 ) ;
if ( V_19 )
goto V_86;
V_19 = F_74 ( & V_37 -> V_5 , & V_87 ) ;
if ( V_19 )
goto V_86;
V_12 -> V_64 = F_55 ( & V_37 -> V_5 ) ;
if ( F_56 ( V_12 -> V_64 ) ) {
V_19 = F_57 ( V_12 -> V_64 ) ;
goto V_86;
}
return 0 ;
V_86:
F_58 ( & V_37 -> V_5 . V_62 , & V_63 ) ;
F_75 ( & V_37 -> V_5 , & V_87 ) ;
return V_19 ;
}
static int T_6 F_76 ( struct V_80 * V_37 )
{
struct V_11 * V_12 = F_43 ( V_37 ) ;
F_61 ( V_12 -> V_64 ) ;
F_58 ( & V_37 -> V_5 . V_62 , & V_63 ) ;
F_75 ( & V_37 -> V_5 , & V_87 ) ;
return 0 ;
}
static int T_7 F_77 ( unsigned short V_52 )
{
int V_1 , V_88 , V_89 = 0 ;
int V_90 ;
for ( V_90 = V_52 ; V_90 < V_52 + V_91 ; V_90 ++ ) {
if ( ! F_78 ( V_90 , 1 , L_6 ) ) {
F_79 ( L_11 , V_90 ) ;
goto V_92;
}
}
#define F_80
V_1 = F_64 ( V_52 + 1 ) ;
if ( F_64 ( V_52 + 2 ) != V_1
|| F_64 ( V_52 + 3 ) != V_1
|| F_64 ( V_52 + 7 ) != V_1 )
goto V_92;
#undef F_80
V_88 = F_64 ( V_52 + V_68 ) ;
if ( V_88 & 0x80 )
goto V_92;
V_1 = ~ V_88 & 0x7f ;
F_63 ( V_1 , V_52 + V_68 ) ;
if ( F_64 ( V_52 + V_68 ) != ( V_1 | 0x80 ) ) {
F_63 ( V_88 , V_52 + V_68 ) ;
goto V_92;
}
F_63 ( V_46 , V_52 + V_68 ) ;
V_1 = F_64 ( V_52 + V_69 ) ;
if ( V_1 & 0x80 )
goto V_92;
F_63 ( V_43 , V_52 + V_68 ) ;
V_1 = F_64 ( V_52 + V_69 ) ;
if ( V_1 < 0x03 || V_1 > 0x77 )
goto V_92;
if ( F_64 ( V_52 + V_68 ) & 0x80 )
goto V_92;
F_63 ( 0x4f , V_52 + V_68 ) ;
V_1 = F_64 ( V_52 + V_69 ) ;
if ( V_1 == 0xa3 || V_1 == 0x5c )
goto V_92;
F_63 ( 0x58 , V_52 + V_68 ) ;
V_1 = F_64 ( V_52 + V_69 ) ;
if ( V_1 == 0x90 )
goto V_92;
F_63 ( V_45 , V_52 + V_68 ) ;
V_1 = F_64 ( V_52 + V_69 ) ;
if ( V_1 == 0x00 || V_1 == 0x20
|| V_1 == 0x40
|| ( V_1 & 0xfe ) == 0xc0 )
V_89 = 1 ;
if ( V_89 )
F_81 ( L_12 ,
V_1 & 0x80 ? L_13 : L_14 , ( int ) V_52 ) ;
V_92:
for ( V_90 -- ; V_90 >= V_52 ; V_90 -- )
F_82 ( V_90 , 1 ) ;
return V_89 ;
}
static int T_7 F_83 ( unsigned short V_52 )
{
struct V_81 V_65 = {
. V_83 = V_52 ,
. V_93 = V_52 + V_91 - 1 ,
. V_36 = L_6 ,
. V_94 = V_82 ,
} ;
int V_19 ;
V_37 = F_84 ( L_6 , V_52 ) ;
if ( ! V_37 ) {
V_19 = - V_60 ;
F_85 ( L_15 ) ;
goto exit;
}
V_19 = F_86 ( V_37 , & V_65 , 1 ) ;
if ( V_19 ) {
F_85 ( L_16 , V_19 ) ;
goto V_95;
}
V_19 = F_87 ( V_37 ) ;
if ( V_19 ) {
F_85 ( L_17 , V_19 ) ;
goto V_95;
}
return 0 ;
V_95:
F_88 ( V_37 ) ;
exit:
V_37 = NULL ;
return V_19 ;
}
static int T_7 F_89 ( void )
{
int V_65 ;
if ( F_77 ( V_96 ) ) {
V_65 = F_90 ( & V_97 ) ;
if ( V_65 )
goto exit;
V_65 = F_83 ( V_96 ) ;
if ( V_65 )
goto V_98;
}
return 0 ;
V_98:
F_91 ( & V_97 ) ;
exit:
return V_65 ;
}
static void F_92 ( void )
{
if ( V_37 ) {
F_93 ( V_37 ) ;
F_91 ( & V_97 ) ;
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
int V_65 ;
V_65 = F_89 () ;
if ( V_65 )
goto exit;
V_65 = F_95 ( & V_99 ) ;
if ( V_65 )
goto V_100;
return 0 ;
V_100:
F_92 () ;
exit:
return V_65 ;
}
static void T_8 F_96 ( void )
{
F_92 () ;
F_97 ( & V_99 ) ;
}
