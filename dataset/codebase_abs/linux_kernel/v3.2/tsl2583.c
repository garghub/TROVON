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
int V_13 , V_14 ;
for ( V_13 = 0 ; V_13 < V_12 ; V_13 ++ ) {
V_14 = F_3 ( V_9 , ( V_15 | V_10 ) ) ;
if ( V_14 < 0 ) {
F_4 ( & V_9 -> V_16 , L_1
L_2 , V_10 ) ;
return V_14 ;
}
* V_11 = F_5 ( V_9 ) ;
V_11 ++ ;
V_10 ++ ;
}
return 0 ;
}
static int F_6 ( struct V_17 * V_18 )
{
T_2 V_19 , V_20 ;
T_3 V_21 ;
T_3 V_22 ;
T_1 V_23 [ 5 ] ;
struct V_24 * V_25 ;
struct V_1 * V_2 = F_7 ( V_18 ) ;
int V_13 , V_14 ;
T_3 V_26 = 0 ;
T_3 V_27 = 0 ;
if ( F_8 ( & V_2 -> V_28 ) == 0 ) {
F_9 ( & V_2 -> V_9 -> V_16 , L_3 ) ;
return V_2 -> V_29 . V_21 ;
}
if ( V_2 -> V_30 != V_31 ) {
F_4 ( & V_2 -> V_9 -> V_16 , L_4 ) ;
V_14 = - V_32 ;
goto V_33;
}
V_14 = F_2 ( V_2 -> V_9 , ( V_15 ) , & V_23 [ 0 ] , 1 ) ;
if ( V_14 < 0 ) {
F_4 ( & V_2 -> V_9 -> V_16 , L_5 ) ;
goto V_33;
}
if ( ! ( V_23 [ 0 ] & V_34 ) ) {
F_4 ( & V_2 -> V_9 -> V_16 , L_6 ) ;
V_14 = V_2 -> V_29 . V_21 ;
goto V_33;
}
for ( V_13 = 0 ; V_13 < 4 ; V_13 ++ ) {
int V_10 = V_15 | ( V_35 + V_13 ) ;
V_14 = F_2 ( V_2 -> V_9 , V_10 , & V_23 [ V_13 ] , 1 ) ;
if ( V_14 < 0 ) {
F_4 ( & V_2 -> V_9 -> V_16 , L_7
L_2 , V_10 ) ;
goto V_33;
}
}
V_14 = F_3 ( V_2 -> V_9 ,
( V_15 | V_36 |
V_37 ) ) ;
if ( V_14 < 0 ) {
F_4 ( & V_2 -> V_9 -> V_16 ,
L_8 ,
V_14 ) ;
goto V_33;
}
V_19 = F_10 ( ( const V_38 * ) & V_23 [ 0 ] ) ;
V_20 = F_10 ( ( const V_38 * ) & V_23 [ 2 ] ) ;
V_2 -> V_29 . V_39 = V_19 ;
V_2 -> V_29 . V_40 = V_20 ;
if ( ( V_19 >= V_2 -> V_41 ) || ( V_20 >= V_2 -> V_41 ) )
goto V_42;
if ( V_19 == 0 ) {
V_14 = V_2 -> V_29 . V_21 = 0 ;
goto V_33;
}
V_22 = ( V_20 << 15 ) / V_19 ;
for ( V_25 = (struct V_24 * ) V_43 ;
V_25 -> V_22 != 0 && V_25 -> V_22 < V_22 ; V_25 ++ )
;
if ( V_25 -> V_22 == 0 ) {
V_21 = 0 ;
} else {
V_26 = ( ( V_19 * V_25 -> V_19 ) +
( V_44 [ V_2 -> V_3 . V_5 ] . V_19 >> 1 ) )
/ V_44 [ V_2 -> V_3 . V_5 ] . V_19 ;
V_27 = ( ( V_20 * V_25 -> V_20 ) +
( V_44 [ V_2 -> V_3 . V_5 ] . V_20 >> 1 ) )
/ V_44 [ V_2 -> V_3 . V_5 ] . V_20 ;
V_21 = V_26 - V_27 ;
}
if ( V_27 > V_26 ) {
F_11 ( & V_2 -> V_9 -> V_16 , L_9 ) ;
V_14 = V_2 -> V_29 . V_21 = 0 ;
goto V_33;
}
if ( V_2 -> V_45 == 0 )
V_21 = 0 ;
else
V_21 = ( V_21 + ( V_2 -> V_45 >> 1 ) ) /
V_2 -> V_45 ;
V_21 >>= 13 ;
V_21 = ( V_21 * V_2 -> V_3 . V_6 + 500 ) / 1000 ;
if ( V_21 > V_46 ) {
V_42:
V_21 = V_46 ;
}
V_2 -> V_29 . V_21 = V_21 ;
V_14 = V_21 ;
V_33:
F_12 ( & V_2 -> V_28 ) ;
return V_14 ;
}
static int F_13 ( struct V_17 * V_18 )
{
struct V_1 * V_2 = F_7 ( V_18 ) ;
T_1 V_47 ;
unsigned int V_48 ;
int V_14 ;
int V_49 ;
V_14 = F_3 ( V_2 -> V_9 ,
( V_15 | V_50 ) ) ;
if ( V_14 < 0 ) {
F_4 ( & V_2 -> V_9 -> V_16 ,
L_10 ,
V_14 ) ;
return V_14 ;
}
V_47 = F_5 ( V_2 -> V_9 ) ;
if ( ( V_47 & ( V_51 | V_52 ) )
!= ( V_51 | V_52 ) ) {
F_4 ( & V_2 -> V_9 -> V_16 ,
L_11 ) ;
return - 1 ;
}
V_14 = F_3 ( V_2 -> V_9 ,
( V_15 | V_50 ) ) ;
if ( V_14 < 0 ) {
F_4 ( & V_2 -> V_9 -> V_16 ,
L_12 ,
V_14 ) ;
return V_14 ;
}
V_47 = F_5 ( V_2 -> V_9 ) ;
if ( ( V_47 & V_53 ) != V_53 ) {
F_4 ( & V_2 -> V_9 -> V_16 ,
L_13 ) ;
return - V_54 ;
}
V_49 = F_6 ( V_18 ) ;
if ( V_49 < 0 ) {
F_4 ( & V_2 -> V_9 -> V_16 , L_14 ) ;
return V_49 ;
}
V_48 = ( unsigned int ) ( ( ( V_2 -> V_3 . V_7 )
* V_2 -> V_3 . V_6 ) / V_49 ) ;
if ( ( V_48 < 250 ) || ( V_48 > 4000 ) ) {
F_4 ( & V_2 -> V_9 -> V_16 ,
L_15 ,
V_48 ) ;
return - V_54 ;
}
V_2 -> V_3 . V_6 = ( int ) V_48 ;
return ( int ) V_48 ;
}
static int F_14 ( struct V_17 * V_18 )
{
int V_13 ;
int V_14 ;
T_1 * V_55 ;
T_1 V_56 ;
int V_57 ;
int V_4 ;
struct V_1 * V_2 = F_7 ( V_18 ) ;
if ( V_2 -> V_30 == V_31 ) {
F_9 ( & V_2 -> V_9 -> V_16 , L_16 ) ;
return - V_58 ;
}
V_57 = ( V_2 -> V_3 . V_4 * 100 + 135 ) / 270 ;
if ( V_57 == 0 )
V_57 = 1 ;
V_4 = ( V_57 * 27 + 5 ) / 10 ;
V_2 -> V_59 [ V_60 ] = 256 - V_57 ;
V_2 -> V_59 [ V_61 ] = V_2 -> V_3 . V_5 ;
V_2 -> V_41 = V_57 * 922 ;
V_2 -> V_45 = ( V_4 + 25 ) / 50 ;
V_56 = V_52 ;
V_14 = F_15 ( V_2 -> V_9 ,
V_15 | V_50 , V_56 ) ;
if ( V_14 < 0 ) {
F_4 ( & V_2 -> V_9 -> V_16 , L_17 ) ;
return - 1 ;
}
for ( V_13 = 0 , V_55 = V_2 -> V_59 ; V_13 < V_62 ; V_13 ++ ) {
V_14 = F_15 ( V_2 -> V_9 ,
V_15 + V_13 ,
* V_55 ++ ) ;
if ( V_14 < 0 ) {
F_4 ( & V_2 -> V_9 -> V_16 ,
L_18 , V_13 ) ;
return - 1 ;
}
}
F_16 ( 3 ) ;
V_56 = V_52 | V_51 ;
V_14 = F_15 ( V_2 -> V_9 ,
V_15 | V_50 ,
V_56 ) ;
if ( V_14 < 0 ) {
F_4 ( & V_2 -> V_9 -> V_16 , L_19 ) ;
return - 1 ;
}
V_2 -> V_30 = V_31 ;
return V_14 ;
}
static int F_17 ( struct V_17 * V_18 )
{
struct V_1 * V_2 = F_7 ( V_18 ) ;
int V_14 ;
V_2 -> V_30 = V_63 ;
V_14 = F_15 ( V_2 -> V_9 ,
V_15 | V_50 ,
0x00 ) ;
return V_14 ;
}
static T_4 F_18 ( struct V_64 * V_16 ,
struct V_65 * V_66 , char * V_23 )
{
struct V_17 * V_18 = F_19 ( V_16 ) ;
struct V_1 * V_2 = F_7 ( V_18 ) ;
return sprintf ( V_23 , L_20 , V_2 -> V_30 ) ;
}
static T_4 F_20 ( struct V_64 * V_16 ,
struct V_65 * V_66 , const char * V_23 , T_5 V_12 )
{
struct V_17 * V_18 = F_19 ( V_16 ) ;
unsigned long V_67 ;
if ( F_21 ( V_23 , 0 , & V_67 ) )
return - V_58 ;
if ( V_67 == 0 )
F_17 ( V_18 ) ;
else
F_14 ( V_18 ) ;
return V_12 ;
}
static T_4 F_22 ( struct V_64 * V_16 ,
struct V_65 * V_66 , char * V_23 )
{
struct V_17 * V_18 = F_19 ( V_16 ) ;
struct V_1 * V_2 = F_7 ( V_18 ) ;
char V_68 [ 4 ] = { 0 } ;
switch ( V_2 -> V_3 . V_5 ) {
case 0 :
strcpy ( V_68 , L_21 ) ;
break;
case 1 :
strcpy ( V_68 , L_22 ) ;
break;
case 2 :
strcpy ( V_68 , L_23 ) ;
break;
case 3 :
strcpy ( V_68 , L_24 ) ;
break;
}
return sprintf ( V_23 , L_25 , V_68 ) ;
}
static T_4 F_23 ( struct V_64 * V_16 ,
struct V_65 * V_66 , const char * V_23 , T_5 V_12 )
{
struct V_17 * V_18 = F_19 ( V_16 ) ;
struct V_1 * V_2 = F_7 ( V_18 ) ;
unsigned long V_67 ;
if ( F_21 ( V_23 , 0 , & V_67 ) )
return - V_58 ;
switch ( V_67 ) {
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
static T_4 F_24 ( struct V_64 * V_16 ,
struct V_65 * V_66 , char * V_23 )
{
return sprintf ( V_23 , L_25 , L_27 ) ;
}
static T_4 F_25 ( struct V_64 * V_16 ,
struct V_65 * V_66 , char * V_23 )
{
struct V_17 * V_18 = F_19 ( V_16 ) ;
struct V_1 * V_2 = F_7 ( V_18 ) ;
return sprintf ( V_23 , L_20 , V_2 -> V_3 . V_4 ) ;
}
static T_4 F_26 ( struct V_64 * V_16 ,
struct V_65 * V_66 , const char * V_23 , T_5 V_12 )
{
struct V_17 * V_18 = F_19 ( V_16 ) ;
struct V_1 * V_2 = F_7 ( V_18 ) ;
unsigned long V_67 ;
if ( F_21 ( V_23 , 0 , & V_67 ) )
return - V_58 ;
if ( ( V_67 < 50 ) || ( V_67 > 650 ) )
return - V_58 ;
if ( V_67 % 50 )
return - V_58 ;
V_2 -> V_3 . V_4 = V_67 ;
return V_12 ;
}
static T_4 F_27 ( struct V_64 * V_16 ,
struct V_65 * V_66 , char * V_23 )
{
return sprintf ( V_23 , L_25 ,
L_28 ) ;
}
static T_4 F_28 ( struct V_64 * V_16 ,
struct V_65 * V_66 , char * V_23 )
{
struct V_17 * V_18 = F_19 ( V_16 ) ;
struct V_1 * V_2 = F_7 ( V_18 ) ;
return sprintf ( V_23 , L_20 , V_2 -> V_3 . V_6 ) ;
}
static T_4 F_29 ( struct V_64 * V_16 ,
struct V_65 * V_66 , const char * V_23 , T_5 V_12 )
{
struct V_17 * V_18 = F_19 ( V_16 ) ;
struct V_1 * V_2 = F_7 ( V_18 ) ;
unsigned long V_67 ;
if ( F_21 ( V_23 , 0 , & V_67 ) )
return - V_58 ;
if ( V_67 )
V_2 -> V_3 . V_6 = V_67 ;
return V_12 ;
}
static T_4 F_30 ( struct V_64 * V_16 ,
struct V_65 * V_66 , char * V_23 )
{
struct V_17 * V_18 = F_19 ( V_16 ) ;
struct V_1 * V_2 = F_7 ( V_18 ) ;
return sprintf ( V_23 , L_20 , V_2 -> V_3 . V_7 ) ;
}
static T_4 F_31 ( struct V_64 * V_16 ,
struct V_65 * V_66 , const char * V_23 , T_5 V_12 )
{
struct V_17 * V_18 = F_19 ( V_16 ) ;
struct V_1 * V_2 = F_7 ( V_18 ) ;
unsigned long V_67 ;
if ( F_21 ( V_23 , 0 , & V_67 ) )
return - V_58 ;
if ( V_67 )
V_2 -> V_3 . V_7 = V_67 ;
return V_12 ;
}
static T_4 F_32 ( struct V_64 * V_16 , struct V_65 * V_66 ,
char * V_23 )
{
int V_14 ;
V_14 = F_6 ( F_19 ( V_16 ) ) ;
if ( V_14 < 0 )
return V_14 ;
return sprintf ( V_23 , L_20 , V_14 ) ;
}
static T_4 F_33 ( struct V_64 * V_16 ,
struct V_65 * V_66 , const char * V_23 , T_5 V_12 )
{
struct V_17 * V_18 = F_19 ( V_16 ) ;
unsigned long V_67 ;
if ( F_21 ( V_23 , 0 , & V_67 ) )
return - V_58 ;
if ( V_67 == 1 )
F_13 ( V_18 ) ;
return V_12 ;
}
static T_4 F_34 ( struct V_64 * V_16 ,
struct V_65 * V_66 , char * V_23 )
{
int V_13 ;
int V_69 = 0 ;
for ( V_13 = 0 ; V_13 < F_35 ( V_43 ) ; V_13 ++ ) {
V_69 += sprintf ( V_23 + V_69 , L_29 ,
V_43 [ V_13 ] . V_22 ,
V_43 [ V_13 ] . V_19 ,
V_43 [ V_13 ] . V_20 ) ;
if ( V_43 [ V_13 ] . V_22 == 0 ) {
V_69 -- ;
break;
}
}
V_69 += sprintf ( V_23 + V_69 , L_30 ) ;
return V_69 ;
}
static T_4 F_36 ( struct V_64 * V_16 ,
struct V_65 * V_66 , const char * V_23 , T_5 V_12 )
{
struct V_17 * V_18 = F_19 ( V_16 ) ;
struct V_1 * V_2 = F_7 ( V_18 ) ;
int V_67 [ F_35 ( V_43 ) * 3 + 1 ] ;
int V_70 ;
F_37 ( V_23 , F_35 ( V_67 ) , V_67 ) ;
V_70 = V_67 [ 0 ] ;
if ( ( V_70 % 3 ) || V_70 < 6 || V_70 > ( ( F_35 ( V_43 ) - 1 ) * 3 ) ) {
F_9 ( V_16 , L_31 , V_70 ) ;
return - V_58 ;
}
if ( ( V_67 [ ( V_70 - 2 ) ] | V_67 [ ( V_70 - 1 ) ] | V_67 [ V_70 ] ) != 0 ) {
F_9 ( V_16 , L_32 , V_70 ) ;
return - V_58 ;
}
if ( V_2 -> V_30 == V_31 )
F_17 ( V_18 ) ;
memset ( V_43 , 0 , sizeof( V_43 ) ) ;
memcpy ( V_43 , & V_67 [ 1 ] , ( V_67 [ 0 ] * 4 ) ) ;
F_14 ( V_18 ) ;
return V_12 ;
}
static int F_38 ( unsigned char * V_71 )
{
return ( ( V_71 [ V_72 ] & 0xf0 ) == 0x90 ) ;
}
static int T_6 F_39 ( struct V_8 * V_73 ,
const struct V_74 * V_75 )
{
int V_13 , V_14 ;
unsigned char V_23 [ V_76 ] ;
struct V_1 * V_2 ;
struct V_17 * V_18 ;
if ( ! F_40 ( V_73 -> V_77 ,
V_78 ) ) {
F_4 ( & V_73 -> V_16 ,
L_33
L_34 ) ;
return - V_79 ;
}
V_18 = F_41 ( sizeof( * V_2 ) ) ;
if ( V_18 == NULL ) {
V_14 = - V_80 ;
F_4 ( & V_73 -> V_16 , L_35 ) ;
goto V_81;
}
V_2 = F_7 ( V_18 ) ;
V_2 -> V_9 = V_73 ;
F_42 ( V_73 , V_18 ) ;
F_43 ( & V_2 -> V_28 ) ;
V_2 -> V_30 = V_82 ;
memcpy ( V_2 -> V_59 , V_59 , sizeof( V_2 -> V_59 ) ) ;
for ( V_13 = 0 ; V_13 < V_76 ; V_13 ++ ) {
V_14 = F_3 ( V_73 ,
( V_15 | ( V_50 + V_13 ) ) ) ;
if ( V_14 < 0 ) {
F_4 ( & V_73 -> V_16 , L_36
L_37 , V_14 ) ;
goto V_83;
}
V_14 = F_5 ( V_73 ) ;
if ( V_14 < 0 ) {
F_4 ( & V_73 -> V_16 , L_38
L_37 , V_14 ) ;
goto V_83;
}
V_23 [ V_13 ] = V_14 ;
}
if ( ! F_38 ( V_23 ) ) {
F_9 ( & V_73 -> V_16 , L_39
L_40 ) ;
goto V_83;
}
V_14 = F_3 ( V_73 , ( V_15 | V_50 ) ) ;
if ( V_14 < 0 ) {
F_4 ( & V_73 -> V_16 , L_41
L_42 , V_14 ) ;
goto V_83;
}
V_18 -> V_84 = & V_85 ;
V_18 -> V_16 . V_86 = & V_73 -> V_16 ;
V_18 -> V_87 = V_88 ;
V_18 -> V_89 = V_2 -> V_9 -> V_89 ;
V_14 = F_44 ( V_18 ) ;
if ( V_14 ) {
F_4 ( & V_73 -> V_16 , L_43 ) ;
goto V_83;
}
F_1 ( V_2 ) ;
F_14 ( V_18 ) ;
F_9 ( & V_73 -> V_16 , L_44 ) ;
return 0 ;
V_81:
F_45 ( V_18 ) ;
V_83:
return V_14 ;
}
static int F_46 ( struct V_8 * V_9 , T_7 V_90 )
{
struct V_17 * V_18 = F_47 ( V_9 ) ;
struct V_1 * V_2 = F_7 ( V_18 ) ;
int V_14 = 0 ;
F_48 ( & V_2 -> V_28 ) ;
if ( V_2 -> V_30 == V_31 ) {
V_14 = F_17 ( V_18 ) ;
V_2 -> V_30 = V_63 ;
}
F_12 ( & V_2 -> V_28 ) ;
return V_14 ;
}
static int F_49 ( struct V_8 * V_9 )
{
struct V_17 * V_18 = F_47 ( V_9 ) ;
struct V_1 * V_2 = F_7 ( V_18 ) ;
int V_14 = 0 ;
F_48 ( & V_2 -> V_28 ) ;
if ( V_2 -> V_30 == V_63 )
V_14 = F_14 ( V_18 ) ;
F_12 ( & V_2 -> V_28 ) ;
return V_14 ;
}
static int T_8 F_50 ( struct V_8 * V_9 )
{
F_51 ( F_47 ( V_9 ) ) ;
F_45 ( F_47 ( V_9 ) ) ;
return 0 ;
}
static int T_9 F_52 ( void )
{
return F_53 ( & V_91 ) ;
}
static void T_10 F_54 ( void )
{
F_55 ( & V_91 ) ;
}
