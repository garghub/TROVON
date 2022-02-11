static inline T_1 F_1 ( unsigned long V_1 )
{
unsigned long V_2 = F_2 ( V_1 , 0 , 4080 ) ;
return ( V_2 + 8 ) / 16 ;
}
static inline T_1 F_3 ( long V_3 , int div )
{
if ( V_3 <= 0 )
return 255 ;
if ( V_3 > 1350000 )
return 1 ;
return F_2 ( ( 1350000 + V_3 * div / 2 ) / ( V_3 * div ) , 1 , 254 ) ;
}
static inline int F_4 ( T_1 V_1 , int div )
{
return V_1 == 0 ? - 1 : V_1 == 255 ? 0 : 1350000 / ( V_1 * div ) ;
}
static inline T_2 F_5 ( long V_1 )
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
F_35 ( V_5 ,
L_2 ,
V_1 ) ;
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
return sprintf ( V_8 , L_3 , V_12 -> V_34 ) ;
}
static T_3 F_40 ( struct V_4 * V_5 , struct V_6 * V_7 ,
char * V_8 )
{
struct V_11 * V_12 = F_9 ( V_5 ) ;
int V_18 = F_8 ( V_7 ) -> V_14 ;
return sprintf ( V_8 , L_3 , ( V_12 -> V_34 >> V_18 ) & 1 ) ;
}
static struct V_11 * F_41 ( void )
{
return V_35 ? F_42 ( V_35 ) : NULL ;
}
static int F_43 ( struct V_36 * V_37 , T_1 V_38 )
{
struct V_11 * V_39 ;
int V_40 ;
if ( ! V_35 )
return 0 ;
V_39 = F_42 ( V_35 ) ;
if ( F_36 ( V_39 , V_41 ) != V_37 -> V_42 )
return 0 ;
if ( ( F_36 ( V_39 , V_43 ) & 0xfe ) != ( V_38 & 0xfe ) )
return 0 ;
for ( V_40 = 0x2b ; V_40 <= 0x3d ; V_40 ++ ) {
if ( F_36 ( V_39 , V_40 ) !=
F_44 ( V_37 , V_40 ) )
return 0 ;
}
if ( F_36 ( V_39 , V_44 ) !=
F_44 ( V_37 , V_44 ) )
return 0 ;
for ( V_40 = 0x43 ; V_40 <= 0x46 ; V_40 ++ ) {
if ( F_36 ( V_39 , V_40 ) !=
F_44 ( V_37 , V_40 ) )
return 0 ;
}
return 1 ;
}
static int F_43 ( struct V_36 * V_37 , T_1 V_38 )
{
return 0 ;
}
static struct V_11 * F_41 ( void )
{
return NULL ;
}
static int F_45 ( struct V_36 * V_37 ,
struct V_45 * V_46 )
{
int V_40 ;
struct V_11 * V_39 = F_41 () ;
const char * V_47 ;
struct V_48 * V_49 = V_37 -> V_49 ;
int V_50 = V_37 -> V_42 ;
if ( ! F_46 ( V_49 , V_51 ) )
return - V_52 ;
if ( V_39 )
F_16 ( & V_39 -> V_20 ) ;
if ( ( F_44 ( V_37 , V_44 ) & 0x80 )
|| F_44 ( V_37 , V_41 ) != V_50 )
goto V_53;
V_40 = F_44 ( V_37 , 0x4f ) ;
if ( V_40 == 0xa3 || V_40 == 0x5c )
goto V_53;
V_40 = F_44 ( V_37 , V_43 ) ;
if ( V_40 == 0x00 || V_40 == 0x20
|| V_40 == 0x40 )
V_47 = L_4 ;
else if ( ( V_40 & 0xfe ) == 0xc0 )
V_47 = L_5 ;
else
goto V_53;
if ( F_43 ( V_37 , V_40 ) ) {
F_47 ( & V_49 -> V_5 ,
L_6 ,
V_50 ) ;
goto V_53;
}
if ( V_39 )
F_19 ( & V_39 -> V_20 ) ;
F_48 ( V_46 -> type , V_47 , V_54 ) ;
return 0 ;
V_53:
if ( V_39 )
F_19 ( & V_39 -> V_20 ) ;
return - V_52 ;
}
static int F_49 ( struct V_36 * V_37 ,
const struct V_55 * V_56 )
{
struct V_4 * V_5 = & V_37 -> V_5 ;
struct V_4 * V_57 ;
struct V_11 * V_12 ;
V_12 = F_50 ( V_5 , sizeof( struct V_11 ) , V_58 ) ;
if ( ! V_12 )
return - V_59 ;
V_12 -> V_37 = V_37 ;
V_12 -> type = V_56 -> V_60 ;
F_51 ( V_12 ) ;
V_57 = F_52 ( V_5 , V_37 -> V_61 ,
V_12 , V_62 ) ;
return F_53 ( V_57 ) ;
}
static int F_36 ( struct V_11 * V_12 , T_1 V_30 )
{
struct V_36 * V_37 = V_12 -> V_37 ;
#ifdef F_54
if ( ! V_37 ) {
int V_63 ;
F_16 ( & V_12 -> V_64 ) ;
F_55 ( V_30 , V_12 -> V_65 + V_66 ) ;
V_63 = F_56 ( V_12 -> V_65 + V_67 ) ;
F_19 ( & V_12 -> V_64 ) ;
return V_63 ;
} else
#endif
return F_44 ( V_37 , V_30 ) ;
}
static int F_17 ( struct V_11 * V_12 , T_1 V_30 , T_1 V_68 )
{
struct V_36 * V_37 = V_12 -> V_37 ;
#ifdef F_54
if ( ! V_37 ) {
F_16 ( & V_12 -> V_64 ) ;
F_55 ( V_30 , V_12 -> V_65 + V_66 ) ;
F_55 ( V_68 , V_12 -> V_65 + V_67 ) ;
F_19 ( & V_12 -> V_64 ) ;
return 0 ;
} else
#endif
return F_57 ( V_37 , V_30 , V_68 ) ;
}
static void F_51 ( struct V_11 * V_12 )
{
T_1 V_69 ;
int V_40 ;
V_69 = F_36 ( V_12 , V_44 ) ;
if ( ( V_69 & 0x09 ) != 0x01 )
F_17 ( V_12 , V_44 ,
( V_69 & 0xf7 ) | 0x01 ) ;
for ( V_40 = 0 ; V_40 < 3 ; V_40 ++ ) {
V_12 -> V_28 [ V_40 ] = F_36 ( V_12 ,
F_32 ( V_40 ) ) ;
}
F_58 ( & V_12 -> V_20 ) ;
}
static struct V_11 * F_9 ( struct V_4 * V_5 )
{
struct V_11 * V_12 = F_14 ( V_5 ) ;
int V_40 ;
F_16 ( & V_12 -> V_20 ) ;
if ( F_59 ( V_70 , V_12 -> V_71 + V_72 + V_72 / 2 )
|| ! V_12 -> V_73 ) {
F_47 ( V_5 , L_7 ) ;
for ( V_40 = 0 ; V_40 <= 6 ; V_40 ++ ) {
V_12 -> V_13 [ V_40 ] =
F_36 ( V_12 , F_60 ( V_40 ) ) ;
V_12 -> V_15 [ V_40 ] =
F_36 ( V_12 , F_18 ( V_40 ) ) ;
V_12 -> V_16 [ V_40 ] =
F_36 ( V_12 , F_21 ( V_40 ) ) ;
}
for ( V_40 = 0 ; V_40 < 3 ; V_40 ++ ) {
V_12 -> V_26 [ V_40 ] =
F_36 ( V_12 , F_61 ( V_40 ) ) ;
V_12 -> V_28 [ V_40 ] =
F_36 ( V_12 , F_32 ( V_40 ) ) ;
}
V_12 -> V_21 = F_36 ( V_12 , V_74 ) ;
V_12 -> V_22 =
F_36 ( V_12 , V_23 ) ;
V_12 -> V_24 =
F_36 ( V_12 , V_25 ) ;
V_40 = F_36 ( V_12 , V_32 ) ;
V_12 -> V_33 = V_40 & 0x0f ;
if ( V_12 -> type == V_75 )
V_12 -> V_33 |=
( F_36 ( V_12 , V_43 ) &
0x01 ) << 4 ;
else
V_12 -> V_33 |= 0x10 ;
V_12 -> V_27 [ 0 ] = ( V_40 >> 4 ) & 0x03 ;
V_12 -> V_27 [ 1 ] = V_40 >> 6 ;
V_12 -> V_34 = F_36 ( V_12 , V_76 ) +
( F_36 ( V_12 , V_77 ) << 8 ) ;
V_12 -> V_71 = V_70 ;
V_12 -> V_73 = 1 ;
V_12 -> V_27 [ 2 ] = 1 ;
}
F_19 ( & V_12 -> V_20 ) ;
return V_12 ;
}
static int F_62 ( struct V_78 * V_35 )
{
struct V_4 * V_5 = & V_35 -> V_5 ;
struct V_4 * V_57 ;
struct V_11 * V_12 ;
struct V_79 * V_63 ;
V_63 = F_63 ( V_35 , V_80 , 0 ) ;
if ( ! F_64 ( V_5 , V_63 -> V_81 + V_66 ,
2 , L_4 ) )
return - V_82 ;
V_12 = F_50 ( V_5 , sizeof( struct V_11 ) , V_58 ) ;
if ( ! V_12 )
return - V_59 ;
F_58 ( & V_12 -> V_64 ) ;
V_12 -> V_65 = V_63 -> V_81 ;
F_65 ( V_35 , V_12 ) ;
if ( F_36 ( V_12 , V_43 ) & 0x80 ) {
V_12 -> type = V_75 ;
V_12 -> V_61 = L_5 ;
} else {
V_12 -> type = V_83 ;
V_12 -> V_61 = L_4 ;
}
F_51 ( V_12 ) ;
V_57 = F_52 ( V_5 , V_12 -> V_61 ,
V_12 , V_62 ) ;
return F_53 ( V_57 ) ;
}
static int T_5 F_66 ( unsigned short V_50 )
{
int V_1 , V_84 , V_85 = 0 ;
int V_86 ;
for ( V_86 = V_50 ; V_86 < V_50 + V_87 ; V_86 ++ ) {
if ( ! F_67 ( V_86 , 1 , L_4 ) ) {
F_68 ( L_8 , V_86 ) ;
goto V_88;
}
}
#define F_69
V_1 = F_56 ( V_50 + 1 ) ;
if ( F_56 ( V_50 + 2 ) != V_1
|| F_56 ( V_50 + 3 ) != V_1
|| F_56 ( V_50 + 7 ) != V_1 )
goto V_88;
#undef F_69
V_84 = F_56 ( V_50 + V_66 ) ;
if ( V_84 & 0x80 )
goto V_88;
V_1 = ~ V_84 & 0x7f ;
F_55 ( V_1 , V_50 + V_66 ) ;
if ( F_56 ( V_50 + V_66 ) != ( V_1 | 0x80 ) ) {
F_55 ( V_84 , V_50 + V_66 ) ;
goto V_88;
}
F_55 ( V_44 , V_50 + V_66 ) ;
V_1 = F_56 ( V_50 + V_67 ) ;
if ( V_1 & 0x80 )
goto V_88;
F_55 ( V_41 , V_50 + V_66 ) ;
V_1 = F_56 ( V_50 + V_67 ) ;
if ( V_1 < 0x03 || V_1 > 0x77 )
goto V_88;
if ( F_56 ( V_50 + V_66 ) & 0x80 )
goto V_88;
F_55 ( 0x4f , V_50 + V_66 ) ;
V_1 = F_56 ( V_50 + V_67 ) ;
if ( V_1 == 0xa3 || V_1 == 0x5c )
goto V_88;
F_55 ( 0x58 , V_50 + V_66 ) ;
V_1 = F_56 ( V_50 + V_67 ) ;
if ( V_1 == 0x90 )
goto V_88;
F_55 ( V_43 , V_50 + V_66 ) ;
V_1 = F_56 ( V_50 + V_67 ) ;
if ( V_1 == 0x00 || V_1 == 0x20
|| V_1 == 0x40
|| ( V_1 & 0xfe ) == 0xc0 )
V_85 = 1 ;
if ( V_85 )
F_70 ( L_9 ,
V_1 & 0x80 ? L_10 : L_11 , ( int ) V_50 ) ;
V_88:
for ( V_86 -- ; V_86 >= V_50 ; V_86 -- )
F_71 ( V_86 , 1 ) ;
return V_85 ;
}
static int T_5 F_72 ( unsigned short V_50 )
{
struct V_79 V_63 = {
. V_81 = V_50 ,
. V_89 = V_50 + V_87 - 1 ,
. V_61 = L_4 ,
. V_90 = V_80 ,
} ;
int V_19 ;
V_35 = F_73 ( L_4 , V_50 ) ;
if ( ! V_35 ) {
V_19 = - V_59 ;
F_74 ( L_12 ) ;
goto exit;
}
V_19 = F_75 ( V_35 , & V_63 , 1 ) ;
if ( V_19 ) {
F_74 ( L_13 , V_19 ) ;
goto V_91;
}
V_19 = F_76 ( V_35 ) ;
if ( V_19 ) {
F_74 ( L_14 , V_19 ) ;
goto V_91;
}
return 0 ;
V_91:
F_77 ( V_35 ) ;
exit:
V_35 = NULL ;
return V_19 ;
}
static int T_5 F_78 ( void )
{
int V_63 ;
if ( F_66 ( V_92 ) ) {
V_63 = F_79 ( & V_93 ) ;
if ( V_63 )
goto exit;
V_63 = F_72 ( V_92 ) ;
if ( V_63 )
goto V_94;
}
return 0 ;
V_94:
F_80 ( & V_93 ) ;
exit:
return V_63 ;
}
static void F_81 ( void )
{
if ( V_35 ) {
F_82 ( V_35 ) ;
F_80 ( & V_93 ) ;
}
}
static int T_5 F_78 ( void )
{
return 0 ;
}
static void F_81 ( void )
{
}
static int T_5 F_83 ( void )
{
int V_63 ;
V_63 = F_78 () ;
if ( V_63 )
goto exit;
V_63 = F_84 ( & V_95 ) ;
if ( V_63 )
goto V_96;
return 0 ;
V_96:
F_81 () ;
exit:
return V_63 ;
}
static void T_6 F_85 ( void )
{
F_81 () ;
F_86 ( & V_95 ) ;
}
