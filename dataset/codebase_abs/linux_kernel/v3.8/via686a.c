static inline T_1 F_1 ( long V_1 , int V_2 )
{
if ( V_2 <= 1 )
return ( T_1 )
F_2 ( ( V_1 * 21024 - 1205000 ) / 250000 , 0 , 255 ) ;
else if ( V_2 == 2 )
return ( T_1 )
F_2 ( ( V_1 * 15737 - 1205000 ) / 250000 , 0 , 255 ) ;
else if ( V_2 == 3 )
return ( T_1 )
F_2 ( ( V_1 * 10108 - 1205000 ) / 250000 , 0 , 255 ) ;
else
return ( T_1 )
F_2 ( ( V_1 * 41714 - 12050000 ) / 2500000 , 0 , 255 ) ;
}
static inline long F_3 ( T_1 V_1 , int V_2 )
{
if ( V_2 <= 1 )
return ( long ) ( ( 250000 * V_1 + 1330000 + 21024 / 2 ) / 21024 ) ;
else if ( V_2 == 2 )
return ( long ) ( ( 250000 * V_1 + 1330000 + 15737 / 2 ) / 15737 ) ;
else if ( V_2 == 3 )
return ( long ) ( ( 250000 * V_1 + 1330000 + 10108 / 2 ) / 10108 ) ;
else
return ( long ) ( ( 2500000 * V_1 + 13300000 + 41714 / 2 ) / 41714 ) ;
}
static inline T_1 F_4 ( long V_3 , int div )
{
if ( V_3 == 0 )
return 0 ;
V_3 = F_2 ( V_3 , 1 , 1000000 ) ;
return F_2 ( ( 1350000 + V_3 * div / 2 ) / ( V_3 * div ) , 1 , 255 ) ;
}
static inline T_1 F_5 ( long V_1 )
{
return V_4 [ V_1 <= - 50000 ? 0 : V_1 >= 110000 ? 160 :
( V_1 < 0 ? V_1 - 500 : V_1 + 500 ) / 1000 + 50 ] ;
}
static inline long F_6 ( T_2 V_1 )
{
T_2 V_5 = V_1 >> 2 ;
T_2 V_6 = V_1 & 3 ;
if ( V_6 == 0 || V_5 == 255 )
return F_7 ( V_5 ) ;
return ( V_7 [ V_5 ] * ( 4 - V_6 ) +
V_7 [ V_5 + 1 ] * V_6 ) * 25 ;
}
static inline int F_8 ( struct V_8 * V_9 , T_1 V_10 )
{
return F_9 ( V_9 -> V_11 + V_10 ) ;
}
static inline void F_10 ( struct V_8 * V_9 , T_1 V_10 ,
T_1 V_12 )
{
F_11 ( V_12 , V_9 -> V_11 + V_10 ) ;
}
static T_3 F_12 ( struct V_13 * V_14 , struct V_15 * V_16 ,
char * V_17 ) {
struct V_8 * V_9 = F_13 ( V_14 ) ;
struct V_18 * V_19 = F_14 ( V_16 ) ;
int V_20 = V_19 -> V_21 ;
return sprintf ( V_17 , L_1 , F_3 ( V_9 -> V_22 [ V_20 ] , V_20 ) ) ;
}
static T_3 F_15 ( struct V_13 * V_14 , struct V_15 * V_16 ,
char * V_17 ) {
struct V_8 * V_9 = F_13 ( V_14 ) ;
struct V_18 * V_19 = F_14 ( V_16 ) ;
int V_20 = V_19 -> V_21 ;
return sprintf ( V_17 , L_1 , F_3 ( V_9 -> V_23 [ V_20 ] , V_20 ) ) ;
}
static T_3 F_16 ( struct V_13 * V_14 , struct V_15 * V_16 ,
char * V_17 ) {
struct V_8 * V_9 = F_13 ( V_14 ) ;
struct V_18 * V_19 = F_14 ( V_16 ) ;
int V_20 = V_19 -> V_21 ;
return sprintf ( V_17 , L_1 , F_3 ( V_9 -> V_24 [ V_20 ] , V_20 ) ) ;
}
static T_3 F_17 ( struct V_13 * V_14 , struct V_15 * V_16 ,
const char * V_17 , T_4 V_25 ) {
struct V_8 * V_9 = F_18 ( V_14 ) ;
struct V_18 * V_19 = F_14 ( V_16 ) ;
int V_20 = V_19 -> V_21 ;
unsigned long V_1 ;
int V_26 ;
V_26 = F_19 ( V_17 , 10 , & V_1 ) ;
if ( V_26 )
return V_26 ;
F_20 ( & V_9 -> V_27 ) ;
V_9 -> V_23 [ V_20 ] = F_1 ( V_1 , V_20 ) ;
F_10 ( V_9 , F_21 ( V_20 ) ,
V_9 -> V_23 [ V_20 ] ) ;
F_22 ( & V_9 -> V_27 ) ;
return V_25 ;
}
static T_3 F_23 ( struct V_13 * V_14 , struct V_15 * V_16 ,
const char * V_17 , T_4 V_25 ) {
struct V_8 * V_9 = F_18 ( V_14 ) ;
struct V_18 * V_19 = F_14 ( V_16 ) ;
int V_20 = V_19 -> V_21 ;
unsigned long V_1 ;
int V_26 ;
V_26 = F_19 ( V_17 , 10 , & V_1 ) ;
if ( V_26 )
return V_26 ;
F_20 ( & V_9 -> V_27 ) ;
V_9 -> V_24 [ V_20 ] = F_1 ( V_1 , V_20 ) ;
F_10 ( V_9 , F_24 ( V_20 ) ,
V_9 -> V_24 [ V_20 ] ) ;
F_22 ( & V_9 -> V_27 ) ;
return V_25 ;
}
static T_3 F_25 ( struct V_13 * V_14 , struct V_15 * V_16 ,
char * V_17 ) {
struct V_8 * V_9 = F_13 ( V_14 ) ;
struct V_18 * V_19 = F_14 ( V_16 ) ;
int V_20 = V_19 -> V_21 ;
return sprintf ( V_17 , L_1 , F_6 ( V_9 -> V_28 [ V_20 ] ) ) ;
}
static T_3 F_26 ( struct V_13 * V_14 , struct V_15 * V_16 ,
char * V_17 ) {
struct V_8 * V_9 = F_13 ( V_14 ) ;
struct V_18 * V_19 = F_14 ( V_16 ) ;
int V_20 = V_19 -> V_21 ;
return sprintf ( V_17 , L_1 , F_7 ( V_9 -> V_29 [ V_20 ] ) ) ;
}
static T_3 F_27 ( struct V_13 * V_14 , struct V_15 * V_16 ,
char * V_17 ) {
struct V_8 * V_9 = F_13 ( V_14 ) ;
struct V_18 * V_19 = F_14 ( V_16 ) ;
int V_20 = V_19 -> V_21 ;
return sprintf ( V_17 , L_1 , F_7 ( V_9 -> V_30 [ V_20 ] ) ) ;
}
static T_3 F_28 ( struct V_13 * V_14 , struct V_15 * V_16 ,
const char * V_17 , T_4 V_25 ) {
struct V_8 * V_9 = F_18 ( V_14 ) ;
struct V_18 * V_19 = F_14 ( V_16 ) ;
int V_20 = V_19 -> V_21 ;
long V_1 ;
int V_26 ;
V_26 = F_29 ( V_17 , 10 , & V_1 ) ;
if ( V_26 )
return V_26 ;
F_20 ( & V_9 -> V_27 ) ;
V_9 -> V_29 [ V_20 ] = F_5 ( V_1 ) ;
F_10 ( V_9 , V_31 [ V_20 ] ,
V_9 -> V_29 [ V_20 ] ) ;
F_22 ( & V_9 -> V_27 ) ;
return V_25 ;
}
static T_3 F_30 ( struct V_13 * V_14 , struct V_15 * V_16 ,
const char * V_17 , T_4 V_25 ) {
struct V_8 * V_9 = F_18 ( V_14 ) ;
struct V_18 * V_19 = F_14 ( V_16 ) ;
int V_20 = V_19 -> V_21 ;
long V_1 ;
int V_26 ;
V_26 = F_29 ( V_17 , 10 , & V_1 ) ;
if ( V_26 )
return V_26 ;
F_20 ( & V_9 -> V_27 ) ;
V_9 -> V_30 [ V_20 ] = F_5 ( V_1 ) ;
F_10 ( V_9 , V_32 [ V_20 ] ,
V_9 -> V_30 [ V_20 ] ) ;
F_22 ( & V_9 -> V_27 ) ;
return V_25 ;
}
static T_3 F_31 ( struct V_13 * V_14 , struct V_15 * V_16 ,
char * V_17 ) {
struct V_8 * V_9 = F_13 ( V_14 ) ;
struct V_18 * V_19 = F_14 ( V_16 ) ;
int V_20 = V_19 -> V_21 ;
return sprintf ( V_17 , L_2 , F_32 ( V_9 -> V_33 [ V_20 ] ,
F_33 ( V_9 -> V_34 [ V_20 ] ) ) ) ;
}
static T_3 F_34 ( struct V_13 * V_14 , struct V_15 * V_16 ,
char * V_17 ) {
struct V_8 * V_9 = F_13 ( V_14 ) ;
struct V_18 * V_19 = F_14 ( V_16 ) ;
int V_20 = V_19 -> V_21 ;
return sprintf ( V_17 , L_2 ,
F_32 ( V_9 -> V_35 [ V_20 ] ,
F_33 ( V_9 -> V_34 [ V_20 ] ) ) ) ;
}
static T_3 F_35 ( struct V_13 * V_14 , struct V_15 * V_16 ,
char * V_17 ) {
struct V_8 * V_9 = F_13 ( V_14 ) ;
struct V_18 * V_19 = F_14 ( V_16 ) ;
int V_20 = V_19 -> V_21 ;
return sprintf ( V_17 , L_2 , F_33 ( V_9 -> V_34 [ V_20 ] ) ) ;
}
static T_3 F_36 ( struct V_13 * V_14 , struct V_15 * V_16 ,
const char * V_17 , T_4 V_25 ) {
struct V_8 * V_9 = F_18 ( V_14 ) ;
struct V_18 * V_19 = F_14 ( V_16 ) ;
int V_20 = V_19 -> V_21 ;
unsigned long V_1 ;
int V_26 ;
V_26 = F_19 ( V_17 , 10 , & V_1 ) ;
if ( V_26 )
return V_26 ;
F_20 ( & V_9 -> V_27 ) ;
V_9 -> V_35 [ V_20 ] = F_4 ( V_1 , F_33 ( V_9 -> V_34 [ V_20 ] ) ) ;
F_10 ( V_9 , F_37 ( V_20 + 1 ) , V_9 -> V_35 [ V_20 ] ) ;
F_22 ( & V_9 -> V_27 ) ;
return V_25 ;
}
static T_3 F_38 ( struct V_13 * V_14 , struct V_15 * V_16 ,
const char * V_17 , T_4 V_25 ) {
struct V_8 * V_9 = F_18 ( V_14 ) ;
struct V_18 * V_19 = F_14 ( V_16 ) ;
int V_20 = V_19 -> V_21 ;
int V_36 ;
unsigned long V_1 ;
int V_26 ;
V_26 = F_19 ( V_17 , 10 , & V_1 ) ;
if ( V_26 )
return V_26 ;
F_20 ( & V_9 -> V_27 ) ;
V_36 = F_8 ( V_9 , V_37 ) ;
V_9 -> V_34 [ V_20 ] = F_39 ( V_1 ) ;
V_36 = ( V_36 & 0x0f ) | ( V_9 -> V_34 [ 1 ] << 6 ) | ( V_9 -> V_34 [ 0 ] << 4 ) ;
F_10 ( V_9 , V_37 , V_36 ) ;
F_22 ( & V_9 -> V_27 ) ;
return V_25 ;
}
static T_3 F_40 ( struct V_13 * V_14 , struct V_15 * V_19 ,
char * V_17 )
{
struct V_8 * V_9 = F_13 ( V_14 ) ;
return sprintf ( V_17 , L_3 , V_9 -> V_38 ) ;
}
static T_3 F_41 ( struct V_13 * V_14 , struct V_15 * V_19 ,
char * V_17 )
{
int V_39 = F_14 ( V_19 ) -> V_21 ;
struct V_8 * V_9 = F_13 ( V_14 ) ;
return sprintf ( V_17 , L_3 , ( V_9 -> V_38 >> V_39 ) & 1 ) ;
}
static T_3 F_42 ( struct V_13 * V_14 , struct V_15
* V_40 , char * V_17 )
{
struct V_8 * V_9 = F_18 ( V_14 ) ;
return sprintf ( V_17 , L_4 , V_9 -> V_41 ) ;
}
static int F_43 ( struct V_42 * V_43 )
{
struct V_8 * V_9 ;
struct V_44 * V_45 ;
int V_26 ;
V_45 = F_44 ( V_43 , V_46 , 0 ) ;
if ( ! F_45 ( & V_43 -> V_14 , V_45 -> V_47 , V_48 ,
V_49 . V_50 . V_41 ) ) {
F_46 ( & V_43 -> V_14 , L_5 ,
( unsigned long ) V_45 -> V_47 , ( unsigned long ) V_45 -> V_51 ) ;
return - V_52 ;
}
V_9 = F_47 ( & V_43 -> V_14 , sizeof( struct V_8 ) ,
V_53 ) ;
if ( ! V_9 )
return - V_54 ;
F_48 ( V_43 , V_9 ) ;
V_9 -> V_11 = V_45 -> V_47 ;
V_9 -> V_41 = L_6 ;
F_49 ( & V_9 -> V_27 ) ;
F_50 ( V_9 ) ;
V_26 = F_51 ( & V_43 -> V_14 . V_55 , & V_56 ) ;
if ( V_26 )
return V_26 ;
V_9 -> V_57 = F_52 ( & V_43 -> V_14 ) ;
if ( F_53 ( V_9 -> V_57 ) ) {
V_26 = F_54 ( V_9 -> V_57 ) ;
goto V_58;
}
return 0 ;
V_58:
F_55 ( & V_43 -> V_14 . V_55 , & V_56 ) ;
return V_26 ;
}
static int F_56 ( struct V_42 * V_43 )
{
struct V_8 * V_9 = F_57 ( V_43 ) ;
F_58 ( V_9 -> V_57 ) ;
F_55 ( & V_43 -> V_14 . V_55 , & V_56 ) ;
return 0 ;
}
static void F_59 ( struct V_8 * V_9 )
{
int V_10 = F_8 ( V_9 , V_37 ) ;
V_9 -> V_34 [ 0 ] = ( V_10 >> 4 ) & 0x03 ;
V_9 -> V_34 [ 1 ] = V_10 >> 6 ;
}
static void F_50 ( struct V_8 * V_9 )
{
T_1 V_10 ;
V_10 = F_8 ( V_9 , V_59 ) ;
F_10 ( V_9 , V_59 , ( V_10 | 0x01 ) & 0x7F ) ;
V_10 = F_8 ( V_9 , V_60 ) ;
F_10 ( V_9 , V_60 ,
( V_10 & ~ V_61 )
| V_62 ) ;
F_59 ( V_9 ) ;
}
static struct V_8 * F_13 ( struct V_13 * V_14 )
{
struct V_8 * V_9 = F_18 ( V_14 ) ;
int V_63 ;
F_20 ( & V_9 -> V_27 ) ;
if ( F_60 ( V_64 , V_9 -> V_65 + V_66 + V_66 / 2 )
|| ! V_9 -> V_67 ) {
for ( V_63 = 0 ; V_63 <= 4 ; V_63 ++ ) {
V_9 -> V_22 [ V_63 ] =
F_8 ( V_9 , F_61 ( V_63 ) ) ;
V_9 -> V_23 [ V_63 ] = F_8 ( V_9 ,
F_21
( V_63 ) ) ;
V_9 -> V_24 [ V_63 ] =
F_8 ( V_9 , F_24 ( V_63 ) ) ;
}
for ( V_63 = 1 ; V_63 <= 2 ; V_63 ++ ) {
V_9 -> V_33 [ V_63 - 1 ] =
F_8 ( V_9 , F_62 ( V_63 ) ) ;
V_9 -> V_35 [ V_63 - 1 ] = F_8 ( V_9 ,
F_37 ( V_63 ) ) ;
}
for ( V_63 = 0 ; V_63 <= 2 ; V_63 ++ ) {
V_9 -> V_28 [ V_63 ] = F_8 ( V_9 ,
V_68 [ V_63 ] ) << 2 ;
V_9 -> V_29 [ V_63 ] =
F_8 ( V_9 ,
V_31 [ V_63 ] ) ;
V_9 -> V_30 [ V_63 ] =
F_8 ( V_9 ,
V_32 [ V_63 ] ) ;
}
V_9 -> V_28 [ 0 ] |= ( F_8 ( V_9 ,
V_69 )
& 0xc0 ) >> 6 ;
V_9 -> V_28 [ 1 ] |=
( F_8 ( V_9 , V_70 ) &
0x30 ) >> 4 ;
V_9 -> V_28 [ 2 ] |=
( F_8 ( V_9 , V_70 ) &
0xc0 ) >> 6 ;
F_59 ( V_9 ) ;
V_9 -> V_38 =
F_8 ( V_9 ,
V_71 ) |
( F_8 ( V_9 , V_72 ) << 8 ) ;
V_9 -> V_65 = V_64 ;
V_9 -> V_67 = 1 ;
}
F_22 ( & V_9 -> V_27 ) ;
return V_9 ;
}
static int F_63 ( unsigned short V_73 )
{
struct V_44 V_45 = {
. V_47 = V_73 ,
. V_51 = V_73 + V_48 - 1 ,
. V_41 = L_6 ,
. V_74 = V_46 ,
} ;
int V_26 ;
V_26 = F_64 ( & V_45 ) ;
if ( V_26 )
goto exit;
V_43 = F_65 ( L_6 , V_73 ) ;
if ( ! V_43 ) {
V_26 = - V_54 ;
F_66 ( L_7 ) ;
goto exit;
}
V_26 = F_67 ( V_43 , & V_45 , 1 ) ;
if ( V_26 ) {
F_66 ( L_8 , V_26 ) ;
goto V_75;
}
V_26 = F_68 ( V_43 ) ;
if ( V_26 ) {
F_66 ( L_9 , V_26 ) ;
goto V_75;
}
return 0 ;
V_75:
F_69 ( V_43 ) ;
exit:
return V_26 ;
}
static int F_70 ( struct V_76 * V_14 ,
const struct V_77 * V_78 )
{
T_2 V_73 , V_1 ;
if ( V_79 ) {
V_73 = V_79 & ~ ( V_48 - 1 ) ;
F_71 ( & V_14 -> V_14 , L_10 , V_73 ) ;
if ( V_80 !=
F_72 ( V_14 , V_81 , V_73 | 1 ) )
return - V_52 ;
}
if ( V_80 !=
F_73 ( V_14 , V_81 , & V_1 ) )
return - V_52 ;
V_73 = V_1 & ~ ( V_48 - 1 ) ;
if ( V_73 == 0 ) {
F_46 ( & V_14 -> V_14 , L_11
L_12 ) ;
return - V_52 ;
}
if ( V_80 !=
F_73 ( V_14 , V_82 , & V_1 ) )
return - V_52 ;
if ( ! ( V_1 & 0x0001 ) ) {
if ( ! V_79 ) {
F_71 ( & V_14 -> V_14 , L_13
L_14 , V_73 ) ;
return - V_52 ;
}
F_71 ( & V_14 -> V_14 , L_15 ) ;
if ( V_80 !=
F_72 ( V_14 , V_82 ,
V_1 | 0x0001 ) )
return - V_52 ;
}
if ( F_74 ( & V_49 ) )
goto exit;
if ( F_63 ( V_73 ) )
goto V_83;
V_84 = F_75 ( V_14 ) ;
return - V_52 ;
V_83:
F_76 ( & V_49 ) ;
exit:
return - V_52 ;
}
static int T_5 F_77 ( void )
{
return F_78 ( & V_85 ) ;
}
static void T_6 F_79 ( void )
{
F_80 ( & V_85 ) ;
if ( V_84 != NULL ) {
F_81 ( V_43 ) ;
F_76 ( & V_49 ) ;
F_82 ( V_84 ) ;
V_84 = NULL ;
}
}
