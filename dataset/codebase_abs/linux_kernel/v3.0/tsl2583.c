static void F_1 ( struct V_1 * V_2 )
{
V_2 -> V_3 . V_4 = 100 ;
V_2 -> V_3 . V_5 = 0 ;
V_2 -> V_3 . V_6 = 1000 ;
V_2 -> V_3 . V_7 = 130 ;
}
static int
F_2 ( struct V_8 * V_9 , T_1 V_10 , T_1 * V_11 , unsigned int V_12 )
{
int V_13 ;
int V_14 ;
for ( V_14 = 0 ; V_14 < V_12 ; V_14 ++ ) {
V_13 = F_3 ( V_9 , ( V_15 | V_10 ) ) ;
if ( V_13 < 0 ) {
F_4 ( & V_9 -> V_16 , L_1
L_2 , V_10 ) ;
return V_13 ;
}
* V_11 = F_5 ( V_9 ) ;
V_11 ++ ;
V_10 ++ ;
}
return 0 ;
}
static int F_6 ( struct V_8 * V_9 )
{
T_2 V_17 , V_18 ;
T_3 V_19 ;
T_3 V_20 ;
T_1 V_21 [ 5 ] ;
struct V_22 * V_23 ;
struct V_1 * V_2 = F_7 ( V_9 ) ;
int V_14 , V_13 ;
T_3 V_24 = 0 ;
T_3 V_25 = 0 ;
if ( F_8 ( & V_2 -> V_26 ) == 0 ) {
F_9 ( & V_9 -> V_16 , L_3 ) ;
return V_2 -> V_27 . V_19 ;
}
if ( V_2 -> V_28 != V_29 ) {
F_4 ( & V_9 -> V_16 , L_4 ) ;
V_13 = - V_30 ;
goto V_31;
}
V_13 = F_2 ( V_9 , ( V_15 ) , & V_21 [ 0 ] , 1 ) ;
if ( V_13 < 0 ) {
F_4 ( & V_9 -> V_16 , L_5 ) ;
goto V_31;
}
if ( ! ( V_21 [ 0 ] & V_32 ) ) {
F_4 ( & V_9 -> V_16 , L_6 ) ;
V_13 = V_2 -> V_27 . V_19 ;
goto V_31;
}
for ( V_14 = 0 ; V_14 < 4 ; V_14 ++ ) {
int V_10 = V_15 | ( V_33 + V_14 ) ;
V_13 = F_2 ( V_9 , V_10 , & V_21 [ V_14 ] , 1 ) ;
if ( V_13 < 0 ) {
F_4 ( & V_9 -> V_16 , L_7
L_2 , V_10 ) ;
goto V_31;
}
}
V_13 = F_3 ( V_9 ,
( V_15 | V_34 | V_35 ) ) ;
if ( V_13 < 0 ) {
F_4 ( & V_9 -> V_16 ,
L_8 ,
V_13 ) ;
goto V_31;
}
V_17 = F_10 ( ( const V_36 * ) & V_21 [ 0 ] ) ;
V_18 = F_10 ( ( const V_36 * ) & V_21 [ 2 ] ) ;
V_2 -> V_27 . V_37 = V_17 ;
V_2 -> V_27 . V_38 = V_18 ;
if ( ( V_17 >= V_2 -> V_39 ) || ( V_18 >= V_2 -> V_39 ) )
goto V_40;
if ( V_17 == 0 ) {
V_13 = V_2 -> V_27 . V_19 = 0 ;
goto V_31;
}
V_20 = ( V_18 << 15 ) / V_17 ;
for ( V_23 = (struct V_22 * ) V_41 ;
V_23 -> V_20 != 0 && V_23 -> V_20 < V_20 ; V_23 ++ )
;
if ( V_23 -> V_20 == 0 ) {
V_19 = 0 ;
} else {
V_24 = ( ( V_17 * V_23 -> V_17 ) +
( V_42 [ V_2 -> V_3 . V_5 ] . V_17 >> 1 ) )
/ V_42 [ V_2 -> V_3 . V_5 ] . V_17 ;
V_25 = ( ( V_18 * V_23 -> V_18 ) +
( V_42 [ V_2 -> V_3 . V_5 ] . V_18 >> 1 ) )
/ V_42 [ V_2 -> V_3 . V_5 ] . V_18 ;
V_19 = V_24 - V_25 ;
}
if ( V_25 > V_24 ) {
F_11 ( & V_9 -> V_16 , L_9 ) ;
V_13 = V_2 -> V_27 . V_19 = 0 ;
goto V_31;
}
if ( V_2 -> V_43 == 0 )
V_19 = 0 ;
else
V_19 = ( V_19 + ( V_2 -> V_43 >> 1 ) ) /
V_2 -> V_43 ;
V_19 >>= 13 ;
V_19 = ( V_19 * V_2 -> V_3 . V_6 + 500 ) / 1000 ;
if ( V_19 > V_44 ) {
V_40:
V_19 = V_44 ;
}
V_2 -> V_27 . V_19 = V_19 ;
V_13 = V_19 ;
V_31:
F_12 ( & V_2 -> V_26 ) ;
return V_13 ;
}
int F_13 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = F_7 ( V_9 ) ;
T_1 V_45 ;
unsigned int V_46 ;
int V_13 ;
int V_47 ;
V_13 = F_3 ( V_9 , ( V_15 | V_48 ) ) ;
if ( V_13 < 0 ) {
F_4 ( & V_9 -> V_16 ,
L_10 ,
V_13 ) ;
return V_13 ;
}
V_45 = F_5 ( V_9 ) ;
if ( ( V_45 & ( V_49 | V_50 ) )
!= ( V_49 | V_50 ) ) {
F_4 ( & V_9 -> V_16 ,
L_11 ) ;
return - 1 ;
}
V_13 = F_3 ( V_9 , ( V_15 | V_48 ) ) ;
if ( V_13 < 0 ) {
F_4 ( & V_9 -> V_16 ,
L_12 ,
V_13 ) ;
return V_13 ;
}
V_45 = F_5 ( V_9 ) ;
if ( ( V_45 & V_51 ) != V_51 ) {
F_4 ( & V_9 -> V_16 ,
L_13 ) ;
return - V_52 ;
}
V_47 = F_6 ( V_9 ) ;
if ( V_47 < 0 ) {
F_4 ( & V_9 -> V_16 , L_14 ) ;
return V_47 ;
}
V_46 = ( unsigned int ) ( ( ( V_2 -> V_3 . V_7 )
* V_2 -> V_3 . V_6 ) / V_47 ) ;
if ( ( V_46 < 250 ) || ( V_46 > 4000 ) ) {
F_4 ( & V_9 -> V_16 ,
L_15 ,
V_46 ) ;
return - V_52 ;
}
V_2 -> V_3 . V_6 = ( int ) V_46 ;
return ( int ) V_46 ;
}
static int F_14 ( struct V_8 * V_9 )
{
int V_14 ;
int V_13 = 0 ;
T_1 * V_53 ;
T_1 V_54 ;
int V_55 ;
int V_4 ;
struct V_1 * V_2 = F_7 ( V_9 ) ;
if ( V_2 -> V_28 == V_29 ) {
F_9 ( & V_9 -> V_16 , L_16 ) ;
return - V_56 ;
}
V_55 = ( V_2 -> V_3 . V_4 * 100 + 135 ) / 270 ;
if ( V_55 == 0 )
V_55 = 1 ;
V_4 = ( V_55 * 27 + 5 ) / 10 ;
V_2 -> V_57 [ V_58 ] = 256 - V_55 ;
V_2 -> V_57 [ V_59 ] = V_2 -> V_3 . V_5 ;
V_2 -> V_39 = V_55 * 922 ;
V_2 -> V_43 = ( V_4 + 25 ) / 50 ;
V_54 = V_50 ;
V_13 = F_15 ( V_9 ,
V_15 | V_48 , V_54 ) ;
if ( V_13 < 0 ) {
F_4 ( & V_9 -> V_16 , L_17 ) ;
return - 1 ;
}
for ( V_14 = 0 , V_53 = V_2 -> V_57 ; V_14 < V_60 ; V_14 ++ ) {
V_13 = F_15 ( V_9 , V_15 + V_14 ,
* V_53 ++ ) ;
if ( V_13 < 0 ) {
F_4 ( & V_9 -> V_16 ,
L_18 , V_14 ) ;
return - 1 ;
}
}
F_16 ( 3 ) ;
V_54 = V_50 | V_49 ;
V_13 = F_15 ( V_9 , V_15 | V_48 ,
V_54 ) ;
if ( V_13 < 0 ) {
F_4 ( & V_9 -> V_16 , L_19 ) ;
return - 1 ;
}
V_2 -> V_28 = V_29 ;
return V_13 ;
}
static int F_17 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = F_7 ( V_9 ) ;
int V_13 ;
V_2 -> V_28 = V_61 ;
V_13 = F_15 ( V_9 , V_15 | V_48 ,
0x00 ) ;
return V_13 ;
}
static T_4 F_18 ( struct V_62 * V_16 ,
struct V_63 * V_64 , char * V_21 )
{
struct V_65 * V_66 = F_19 ( V_16 ) ;
struct V_1 * V_2 = V_66 -> V_67 ;
return sprintf ( V_21 , L_20 , V_2 -> V_9 -> V_68 ) ;
}
static T_4 F_20 ( struct V_62 * V_16 ,
struct V_63 * V_64 , char * V_21 )
{
struct V_65 * V_66 = F_19 ( V_16 ) ;
struct V_1 * V_2 = V_66 -> V_67 ;
return sprintf ( V_21 , L_21 , V_2 -> V_28 ) ;
}
static T_4 F_21 ( struct V_62 * V_16 ,
struct V_63 * V_64 , const char * V_21 , T_5 V_12 )
{
struct V_65 * V_66 = F_19 ( V_16 ) ;
struct V_1 * V_2 = V_66 -> V_67 ;
unsigned long V_69 ;
if ( F_22 ( V_21 , 0 , & V_69 ) )
return - V_56 ;
if ( V_69 == 0 )
F_17 ( V_2 -> V_9 ) ;
else
F_14 ( V_2 -> V_9 ) ;
return V_12 ;
}
static T_4 F_23 ( struct V_62 * V_16 ,
struct V_63 * V_64 , char * V_21 )
{
struct V_65 * V_66 = F_19 ( V_16 ) ;
struct V_1 * V_2 = V_66 -> V_67 ;
char V_70 [ 4 ] = { 0 } ;
switch ( V_2 -> V_3 . V_5 ) {
case 0 :
strcpy ( V_70 , L_22 ) ;
break;
case 1 :
strcpy ( V_70 , L_23 ) ;
break;
case 2 :
strcpy ( V_70 , L_24 ) ;
break;
case 3 :
strcpy ( V_70 , L_25 ) ;
break;
}
return sprintf ( V_21 , L_20 , V_70 ) ;
}
static T_4 F_24 ( struct V_62 * V_16 ,
struct V_63 * V_64 , const char * V_21 , T_5 V_12 )
{
struct V_65 * V_66 = F_19 ( V_16 ) ;
struct V_1 * V_2 = V_66 -> V_67 ;
unsigned long V_69 ;
if ( F_22 ( V_21 , 0 , & V_69 ) )
return - V_56 ;
switch ( V_69 ) {
case 1 :
V_2 -> V_3 . V_5 = 0 ;
break;
case 8 :
V_2 -> V_3 . V_5 = 1 ;
break;
case 16 :
V_2 -> V_3 . V_5 = 2 ;
break;
case 111 :
V_2 -> V_3 . V_5 = 3 ;
break;
default:
F_4 ( V_16 , L_26 ) ;
return - 1 ;
}
return V_12 ;
}
static T_4 F_25 ( struct V_62 * V_16 ,
struct V_63 * V_64 , char * V_21 )
{
return sprintf ( V_21 , L_20 , L_27 ) ;
}
static T_4 F_26 ( struct V_62 * V_16 ,
struct V_63 * V_64 , char * V_21 )
{
struct V_65 * V_66 = F_19 ( V_16 ) ;
struct V_1 * V_2 = V_66 -> V_67 ;
return sprintf ( V_21 , L_21 , V_2 -> V_3 . V_4 ) ;
}
static T_4 F_27 ( struct V_62 * V_16 ,
struct V_63 * V_64 , const char * V_21 , T_5 V_12 )
{
struct V_65 * V_66 = F_19 ( V_16 ) ;
struct V_1 * V_2 = V_66 -> V_67 ;
unsigned long V_69 ;
if ( F_22 ( V_21 , 0 , & V_69 ) )
return - V_56 ;
if ( ( V_69 < 50 ) || ( V_69 > 650 ) )
return - V_56 ;
if ( V_69 % 50 )
return - V_56 ;
V_2 -> V_3 . V_4 = V_69 ;
return V_12 ;
}
static T_4 F_28 ( struct V_62 * V_16 ,
struct V_63 * V_64 , char * V_21 )
{
return sprintf ( V_21 , L_20 ,
L_28 ) ;
}
static T_4 F_29 ( struct V_62 * V_16 ,
struct V_63 * V_64 , char * V_21 )
{
struct V_65 * V_66 = F_19 ( V_16 ) ;
struct V_1 * V_2 = V_66 -> V_67 ;
return sprintf ( V_21 , L_21 , V_2 -> V_3 . V_6 ) ;
}
static T_4 F_30 ( struct V_62 * V_16 ,
struct V_63 * V_64 , const char * V_21 , T_5 V_12 )
{
struct V_65 * V_66 = F_19 ( V_16 ) ;
struct V_1 * V_2 = V_66 -> V_67 ;
unsigned long V_69 ;
if ( F_22 ( V_21 , 0 , & V_69 ) )
return - V_56 ;
if ( V_69 )
V_2 -> V_3 . V_6 = V_69 ;
return V_12 ;
}
static T_4 F_31 ( struct V_62 * V_16 ,
struct V_63 * V_64 , char * V_21 )
{
struct V_65 * V_66 = F_19 ( V_16 ) ;
struct V_1 * V_2 = V_66 -> V_67 ;
return sprintf ( V_21 , L_21 , V_2 -> V_3 . V_7 ) ;
}
static T_4 F_32 ( struct V_62 * V_16 ,
struct V_63 * V_64 , const char * V_21 , T_5 V_12 )
{
struct V_65 * V_66 = F_19 ( V_16 ) ;
struct V_1 * V_2 = V_66 -> V_67 ;
unsigned long V_69 ;
if ( F_22 ( V_21 , 0 , & V_69 ) )
return - V_56 ;
if ( V_69 )
V_2 -> V_3 . V_7 = V_69 ;
return V_12 ;
}
static T_4 F_33 ( struct V_62 * V_16 , struct V_63 * V_64 ,
char * V_21 )
{
struct V_65 * V_66 = F_19 ( V_16 ) ;
struct V_1 * V_2 = V_66 -> V_67 ;
int V_19 ;
V_19 = F_6 ( V_2 -> V_9 ) ;
return sprintf ( V_21 , L_21 , V_19 ) ;
}
static T_4 F_34 ( struct V_62 * V_16 ,
struct V_63 * V_64 , const char * V_21 , T_5 V_12 )
{
struct V_65 * V_66 = F_19 ( V_16 ) ;
struct V_1 * V_2 = V_66 -> V_67 ;
unsigned long V_69 ;
if ( F_22 ( V_21 , 0 , & V_69 ) )
return - V_56 ;
if ( V_69 == 1 )
F_13 ( V_2 -> V_9 ) ;
return V_12 ;
}
static T_4 F_35 ( struct V_62 * V_16 ,
struct V_63 * V_64 , char * V_21 )
{
int V_14 ;
int V_71 = 0 ;
for ( V_14 = 0 ; V_14 < F_36 ( V_41 ) ; V_14 ++ ) {
V_71 += sprintf ( V_21 + V_71 , L_29 ,
V_41 [ V_14 ] . V_20 ,
V_41 [ V_14 ] . V_17 ,
V_41 [ V_14 ] . V_18 ) ;
if ( V_41 [ V_14 ] . V_20 == 0 ) {
V_71 -- ;
break;
}
}
V_71 += sprintf ( V_21 + V_71 , L_30 ) ;
return V_71 ;
}
static T_4 F_37 ( struct V_62 * V_16 ,
struct V_63 * V_64 , const char * V_21 , T_5 V_12 )
{
struct V_65 * V_66 = F_19 ( V_16 ) ;
struct V_1 * V_2 = V_66 -> V_67 ;
int V_69 [ F_36 ( V_41 ) ] ;
int V_72 ;
F_38 ( V_21 , F_36 ( V_69 ) , V_69 ) ;
V_72 = V_69 [ 0 ] ;
if ( ( V_72 % 3 ) || V_72 < 6 || V_72 > ( ( F_36 ( V_41 ) - 1 ) * 3 ) ) {
F_9 ( V_16 , L_31 , V_72 ) ;
return - V_56 ;
}
if ( ( V_69 [ ( V_72 - 2 ) ] | V_69 [ ( V_72 - 1 ) ] | V_69 [ V_72 ] ) != 0 ) {
F_9 ( V_16 , L_32 , V_72 ) ;
return - V_56 ;
}
if ( V_2 -> V_28 == V_29 )
F_17 ( V_2 -> V_9 ) ;
memset ( V_41 , 0 , sizeof( V_41 ) ) ;
memcpy ( V_41 , & V_69 [ 1 ] , ( V_69 [ 0 ] * 4 ) ) ;
F_14 ( V_2 -> V_9 ) ;
return V_12 ;
}
static int F_39 ( unsigned char * V_73 )
{
return ( ( V_73 [ V_74 ] & 0xf0 ) == 0x90 ) ;
}
static int T_6 F_40 ( struct V_8 * V_75 ,
const struct V_76 * V_77 )
{
int V_14 , V_13 = 0 ;
unsigned char V_21 [ V_78 ] ;
static struct V_1 * V_2 ;
if ( ! F_41 ( V_75 -> V_79 ,
V_80 ) ) {
F_4 ( & V_75 -> V_16 ,
L_33
L_34 ) ;
return - V_81 ;
}
V_2 = F_42 ( sizeof( struct V_1 ) , V_82 ) ;
if ( ! V_2 )
return - V_83 ;
V_2 -> V_9 = V_75 ;
F_43 ( V_75 , V_2 ) ;
F_44 ( & V_2 -> V_26 ) ;
V_2 -> V_28 = V_84 ;
memcpy ( V_2 -> V_57 , V_57 , sizeof( V_2 -> V_57 ) ) ;
for ( V_14 = 0 ; V_14 < V_78 ; V_14 ++ ) {
V_13 = F_3 ( V_75 ,
( V_15 | ( V_48 + V_14 ) ) ) ;
if ( V_13 < 0 ) {
F_4 ( & V_75 -> V_16 , L_35
L_36 , V_13 ) ;
goto V_85;
}
V_13 = F_5 ( V_75 ) ;
if ( V_13 < 0 ) {
F_4 ( & V_75 -> V_16 , L_37
L_36 , V_13 ) ;
goto V_85;
}
V_21 [ V_14 ] = V_13 ;
}
if ( ! F_39 ( V_21 ) ) {
F_9 ( & V_75 -> V_16 , L_38
L_39 ) ;
goto V_85;
}
V_13 = F_3 ( V_75 , ( V_15 | V_48 ) ) ;
if ( V_13 < 0 ) {
F_4 ( & V_75 -> V_16 , L_40
L_41 , V_13 ) ;
goto V_85;
}
V_2 -> V_65 = F_45 ( 0 ) ;
if ( ! V_2 -> V_65 ) {
V_13 = - V_83 ;
F_4 ( & V_75 -> V_16 , L_42 ) ;
goto V_85;
}
V_2 -> V_65 -> V_86 = & V_87 ;
V_2 -> V_65 -> V_16 . V_88 = & V_75 -> V_16 ;
V_2 -> V_65 -> V_67 = ( void * ) ( V_2 ) ;
V_2 -> V_65 -> V_89 = V_90 ;
V_13 = F_46 ( V_2 -> V_65 ) ;
if ( V_13 ) {
F_4 ( & V_75 -> V_16 , L_43 ) ;
goto V_85;
}
F_1 ( V_2 ) ;
F_14 ( V_75 ) ;
F_9 ( & V_75 -> V_16 , L_44 ) ;
return 0 ;
V_85:
F_47 ( V_2 ) ;
return V_13 ;
}
static int F_48 ( struct V_8 * V_9 , T_7 V_91 )
{
struct V_1 * V_2 = F_7 ( V_9 ) ;
int V_13 = 0 ;
F_49 ( & V_2 -> V_26 ) ;
if ( V_2 -> V_28 == V_29 ) {
V_13 = F_17 ( V_9 ) ;
V_2 -> V_28 = V_61 ;
}
F_12 ( & V_2 -> V_26 ) ;
return V_13 ;
}
static int F_50 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = F_7 ( V_9 ) ;
int V_13 = 0 ;
F_49 ( & V_2 -> V_26 ) ;
if ( V_2 -> V_28 == V_61 )
V_13 = F_14 ( V_9 ) ;
F_12 ( & V_2 -> V_26 ) ;
return V_13 ;
}
static int T_8 F_51 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = F_7 ( V_9 ) ;
F_52 ( V_2 -> V_65 ) ;
F_47 ( V_2 ) ;
return 0 ;
}
static int T_9 F_53 ( void )
{
return F_54 ( & V_92 ) ;
}
static void T_10 F_55 ( void )
{
F_56 ( & V_92 ) ;
}
