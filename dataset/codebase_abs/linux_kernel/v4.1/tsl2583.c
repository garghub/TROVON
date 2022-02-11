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
F_4 ( & V_9 -> V_16 ,
L_1 ,
V_10 ) ;
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
T_4 V_22 ;
T_3 V_23 ;
T_1 V_24 [ 5 ] ;
struct V_25 * V_26 ;
struct V_1 * V_2 = F_7 ( V_18 ) ;
int V_13 , V_14 ;
T_3 V_27 = 0 ;
T_3 V_28 = 0 ;
if ( F_8 ( & V_2 -> V_29 ) == 0 ) {
F_9 ( & V_2 -> V_9 -> V_16 , L_2 ) ;
return V_2 -> V_30 . V_21 ;
}
if ( V_2 -> V_31 != V_32 ) {
F_4 ( & V_2 -> V_9 -> V_16 , L_3 ) ;
V_14 = - V_33 ;
goto V_34;
}
V_14 = F_2 ( V_2 -> V_9 , ( V_15 ) , & V_24 [ 0 ] , 1 ) ;
if ( V_14 < 0 ) {
F_4 ( & V_2 -> V_9 -> V_16 , L_4 ) ;
goto V_34;
}
if ( ! ( V_24 [ 0 ] & V_35 ) ) {
F_4 ( & V_2 -> V_9 -> V_16 , L_5 ) ;
V_14 = V_2 -> V_30 . V_21 ;
goto V_34;
}
for ( V_13 = 0 ; V_13 < 4 ; V_13 ++ ) {
int V_10 = V_15 | ( V_36 + V_13 ) ;
V_14 = F_2 ( V_2 -> V_9 , V_10 , & V_24 [ V_13 ] , 1 ) ;
if ( V_14 < 0 ) {
F_4 ( & V_2 -> V_9 -> V_16 ,
L_6 ,
V_10 ) ;
goto V_34;
}
}
V_14 = F_3 ( V_2 -> V_9 ,
( V_15 | V_37 |
V_38 ) ) ;
if ( V_14 < 0 ) {
F_4 ( & V_2 -> V_9 -> V_16 ,
L_7 ,
V_14 ) ;
goto V_34;
}
V_19 = F_10 ( ( const V_39 * ) & V_24 [ 0 ] ) ;
V_20 = F_10 ( ( const V_39 * ) & V_24 [ 2 ] ) ;
V_2 -> V_30 . V_40 = V_19 ;
V_2 -> V_30 . V_41 = V_20 ;
if ( ( V_19 >= V_2 -> V_42 ) || ( V_20 >= V_2 -> V_42 ) )
goto V_43;
if ( V_19 == 0 ) {
V_14 = V_2 -> V_30 . V_21 = 0 ;
goto V_34;
}
V_23 = ( V_20 << 15 ) / V_19 ;
for ( V_26 = (struct V_25 * ) V_44 ;
V_26 -> V_23 != 0 && V_26 -> V_23 < V_23 ; V_26 ++ )
;
if ( V_26 -> V_23 == 0 ) {
V_21 = 0 ;
} else {
V_27 = ( ( V_19 * V_26 -> V_19 ) +
( V_45 [ V_2 -> V_3 . V_5 ] . V_19 >> 1 ) )
/ V_45 [ V_2 -> V_3 . V_5 ] . V_19 ;
V_28 = ( ( V_20 * V_26 -> V_20 ) +
( V_45 [ V_2 -> V_3 . V_5 ] . V_20 >> 1 ) )
/ V_45 [ V_2 -> V_3 . V_5 ] . V_20 ;
V_21 = V_27 - V_28 ;
}
if ( V_28 > V_27 ) {
F_11 ( & V_2 -> V_9 -> V_16 , L_8 ) ;
V_14 = V_2 -> V_30 . V_21 = 0 ;
goto V_34;
}
if ( V_2 -> V_46 == 0 )
V_21 = 0 ;
else
V_21 = ( V_21 + ( V_2 -> V_46 >> 1 ) ) /
V_2 -> V_46 ;
V_22 = V_21 ;
V_22 = V_22 * V_2 -> V_3 . V_6 ;
V_22 >>= 13 ;
V_21 = V_22 ;
V_21 = ( V_21 + 500 ) / 1000 ;
if ( V_21 > V_47 ) {
V_43:
V_21 = V_47 ;
}
V_2 -> V_30 . V_21 = V_21 ;
V_14 = V_21 ;
V_34:
F_12 ( & V_2 -> V_29 ) ;
return V_14 ;
}
static int F_13 ( struct V_17 * V_18 )
{
struct V_1 * V_2 = F_7 ( V_18 ) ;
T_1 V_48 ;
unsigned int V_49 ;
int V_14 ;
int V_50 ;
V_14 = F_3 ( V_2 -> V_9 ,
( V_15 | V_51 ) ) ;
if ( V_14 < 0 ) {
F_4 ( & V_2 -> V_9 -> V_16 ,
L_9 ,
V_14 ) ;
return V_14 ;
}
V_48 = F_5 ( V_2 -> V_9 ) ;
if ( ( V_48 & ( V_52 | V_53 ) )
!= ( V_52 | V_53 ) ) {
F_4 ( & V_2 -> V_9 -> V_16 ,
L_10 ) ;
return - 1 ;
}
V_14 = F_3 ( V_2 -> V_9 ,
( V_15 | V_51 ) ) ;
if ( V_14 < 0 ) {
F_4 ( & V_2 -> V_9 -> V_16 ,
L_11 ,
V_14 ) ;
return V_14 ;
}
V_48 = F_5 ( V_2 -> V_9 ) ;
if ( ( V_48 & V_54 ) != V_54 ) {
F_4 ( & V_2 -> V_9 -> V_16 ,
L_12 ) ;
return - V_55 ;
}
V_50 = F_6 ( V_18 ) ;
if ( V_50 < 0 ) {
F_4 ( & V_2 -> V_9 -> V_16 , L_13 ) ;
return V_50 ;
}
V_49 = ( unsigned int ) ( ( ( V_2 -> V_3 . V_7 )
* V_2 -> V_3 . V_6 ) / V_50 ) ;
if ( ( V_49 < 250 ) || ( V_49 > 4000 ) ) {
F_4 ( & V_2 -> V_9 -> V_16 ,
L_14 ,
V_49 ) ;
return - V_55 ;
}
V_2 -> V_3 . V_6 = ( int ) V_49 ;
return ( int ) V_49 ;
}
static int F_14 ( struct V_17 * V_18 )
{
int V_13 ;
int V_14 ;
T_1 * V_56 ;
T_1 V_57 ;
int V_58 ;
int V_4 ;
struct V_1 * V_2 = F_7 ( V_18 ) ;
if ( V_2 -> V_31 == V_32 ) {
F_9 ( & V_2 -> V_9 -> V_16 , L_15 ) ;
return - V_59 ;
}
V_58 = ( V_2 -> V_3 . V_4 * 100 + 135 ) / 270 ;
if ( V_58 == 0 )
V_58 = 1 ;
V_4 = ( V_58 * 27 + 5 ) / 10 ;
V_2 -> V_60 [ V_61 ] = 256 - V_58 ;
V_2 -> V_60 [ V_62 ] = V_2 -> V_3 . V_5 ;
V_2 -> V_42 = V_58 * 922 ;
V_2 -> V_46 = ( V_4 + 25 ) / 50 ;
V_57 = V_53 ;
V_14 = F_15 ( V_2 -> V_9 ,
V_15 | V_51 , V_57 ) ;
if ( V_14 < 0 ) {
F_4 ( & V_2 -> V_9 -> V_16 , L_16 ) ;
return V_14 ;
}
for ( V_13 = 0 , V_56 = V_2 -> V_60 ; V_13 < V_63 ; V_13 ++ ) {
V_14 = F_15 ( V_2 -> V_9 ,
V_15 + V_13 ,
* V_56 ++ ) ;
if ( V_14 < 0 ) {
F_4 ( & V_2 -> V_9 -> V_16 ,
L_17 , V_13 ) ;
return V_14 ;
}
}
F_16 ( 3000 , 3500 ) ;
V_57 = V_53 | V_52 ;
V_14 = F_15 ( V_2 -> V_9 ,
V_15 | V_51 ,
V_57 ) ;
if ( V_14 < 0 ) {
F_4 ( & V_2 -> V_9 -> V_16 , L_18 ) ;
return V_14 ;
}
V_2 -> V_31 = V_32 ;
return V_14 ;
}
static int F_17 ( struct V_17 * V_18 )
{
struct V_1 * V_2 = F_7 ( V_18 ) ;
V_2 -> V_31 = V_64 ;
return F_15 ( V_2 -> V_9 ,
V_15 | V_51 ,
0x00 ) ;
}
static T_5 F_18 ( struct V_65 * V_16 ,
struct V_66 * V_67 , char * V_24 )
{
struct V_17 * V_18 = F_19 ( V_16 ) ;
struct V_1 * V_2 = F_7 ( V_18 ) ;
return sprintf ( V_24 , L_19 , V_2 -> V_31 ) ;
}
static T_5 F_20 ( struct V_65 * V_16 ,
struct V_66 * V_67 , const char * V_24 , T_6 V_12 )
{
struct V_17 * V_18 = F_19 ( V_16 ) ;
int V_68 ;
if ( F_21 ( V_24 , 0 , & V_68 ) )
return - V_59 ;
if ( V_68 == 0 )
F_17 ( V_18 ) ;
else
F_14 ( V_18 ) ;
return V_12 ;
}
static T_5 F_22 ( struct V_65 * V_16 ,
struct V_66 * V_67 , char * V_24 )
{
struct V_17 * V_18 = F_19 ( V_16 ) ;
struct V_1 * V_2 = F_7 ( V_18 ) ;
char V_69 [ 4 ] = { 0 } ;
switch ( V_2 -> V_3 . V_5 ) {
case 0 :
strcpy ( V_69 , L_20 ) ;
break;
case 1 :
strcpy ( V_69 , L_21 ) ;
break;
case 2 :
strcpy ( V_69 , L_22 ) ;
break;
case 3 :
strcpy ( V_69 , L_23 ) ;
break;
}
return sprintf ( V_24 , L_24 , V_69 ) ;
}
static T_5 F_23 ( struct V_65 * V_16 ,
struct V_66 * V_67 , const char * V_24 , T_6 V_12 )
{
struct V_17 * V_18 = F_19 ( V_16 ) ;
struct V_1 * V_2 = F_7 ( V_18 ) ;
int V_68 ;
if ( F_21 ( V_24 , 0 , & V_68 ) )
return - V_59 ;
switch ( V_68 ) {
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
F_4 ( V_16 , L_25 ) ;
return - 1 ;
}
return V_12 ;
}
static T_5 F_24 ( struct V_65 * V_16 ,
struct V_66 * V_67 , char * V_24 )
{
return sprintf ( V_24 , L_24 , L_26 ) ;
}
static T_5 F_25 ( struct V_65 * V_16 ,
struct V_66 * V_67 , char * V_24 )
{
struct V_17 * V_18 = F_19 ( V_16 ) ;
struct V_1 * V_2 = F_7 ( V_18 ) ;
return sprintf ( V_24 , L_19 , V_2 -> V_3 . V_4 ) ;
}
static T_5 F_26 ( struct V_65 * V_16 ,
struct V_66 * V_67 , const char * V_24 , T_6 V_12 )
{
struct V_17 * V_18 = F_19 ( V_16 ) ;
struct V_1 * V_2 = F_7 ( V_18 ) ;
int V_68 ;
if ( F_21 ( V_24 , 0 , & V_68 ) )
return - V_59 ;
if ( ( V_68 < 50 ) || ( V_68 > 650 ) )
return - V_59 ;
if ( V_68 % 50 )
return - V_59 ;
V_2 -> V_3 . V_4 = V_68 ;
return V_12 ;
}
static T_5 F_27 ( struct V_65 * V_16 ,
struct V_66 * V_67 , char * V_24 )
{
return sprintf ( V_24 , L_24 ,
L_27 ) ;
}
static T_5 F_28 ( struct V_65 * V_16 ,
struct V_66 * V_67 , char * V_24 )
{
struct V_17 * V_18 = F_19 ( V_16 ) ;
struct V_1 * V_2 = F_7 ( V_18 ) ;
return sprintf ( V_24 , L_19 , V_2 -> V_3 . V_6 ) ;
}
static T_5 F_29 ( struct V_65 * V_16 ,
struct V_66 * V_67 , const char * V_24 , T_6 V_12 )
{
struct V_17 * V_18 = F_19 ( V_16 ) ;
struct V_1 * V_2 = F_7 ( V_18 ) ;
int V_68 ;
if ( F_21 ( V_24 , 0 , & V_68 ) )
return - V_59 ;
if ( V_68 )
V_2 -> V_3 . V_6 = V_68 ;
return V_12 ;
}
static T_5 F_30 ( struct V_65 * V_16 ,
struct V_66 * V_67 , char * V_24 )
{
struct V_17 * V_18 = F_19 ( V_16 ) ;
struct V_1 * V_2 = F_7 ( V_18 ) ;
return sprintf ( V_24 , L_19 , V_2 -> V_3 . V_7 ) ;
}
static T_5 F_31 ( struct V_65 * V_16 ,
struct V_66 * V_67 , const char * V_24 , T_6 V_12 )
{
struct V_17 * V_18 = F_19 ( V_16 ) ;
struct V_1 * V_2 = F_7 ( V_18 ) ;
int V_68 ;
if ( F_21 ( V_24 , 0 , & V_68 ) )
return - V_59 ;
if ( V_68 )
V_2 -> V_3 . V_7 = V_68 ;
return V_12 ;
}
static T_5 F_32 ( struct V_65 * V_16 , struct V_66 * V_67 ,
char * V_24 )
{
int V_14 ;
V_14 = F_6 ( F_19 ( V_16 ) ) ;
if ( V_14 < 0 )
return V_14 ;
return sprintf ( V_24 , L_19 , V_14 ) ;
}
static T_5 F_33 ( struct V_65 * V_16 ,
struct V_66 * V_67 , const char * V_24 , T_6 V_12 )
{
struct V_17 * V_18 = F_19 ( V_16 ) ;
int V_68 ;
if ( F_21 ( V_24 , 0 , & V_68 ) )
return - V_59 ;
if ( V_68 == 1 )
F_13 ( V_18 ) ;
return V_12 ;
}
static T_5 F_34 ( struct V_65 * V_16 ,
struct V_66 * V_67 , char * V_24 )
{
int V_13 ;
int V_70 = 0 ;
for ( V_13 = 0 ; V_13 < F_35 ( V_44 ) ; V_13 ++ ) {
V_70 += sprintf ( V_24 + V_70 , L_28 ,
V_44 [ V_13 ] . V_23 ,
V_44 [ V_13 ] . V_19 ,
V_44 [ V_13 ] . V_20 ) ;
if ( V_44 [ V_13 ] . V_23 == 0 ) {
V_70 -- ;
break;
}
}
V_70 += sprintf ( V_24 + V_70 , L_29 ) ;
return V_70 ;
}
static T_5 F_36 ( struct V_65 * V_16 ,
struct V_66 * V_67 , const char * V_24 , T_6 V_12 )
{
struct V_17 * V_18 = F_19 ( V_16 ) ;
struct V_1 * V_2 = F_7 ( V_18 ) ;
int V_68 [ F_35 ( V_44 ) * 3 + 1 ] ;
int V_71 ;
F_37 ( V_24 , F_35 ( V_68 ) , V_68 ) ;
V_71 = V_68 [ 0 ] ;
if ( ( V_71 % 3 ) || V_71 < 6 || V_71 > ( ( F_35 ( V_44 ) - 1 ) * 3 ) ) {
F_9 ( V_16 , L_30 , V_71 ) ;
return - V_59 ;
}
if ( ( V_68 [ ( V_71 - 2 ) ] | V_68 [ ( V_71 - 1 ) ] | V_68 [ V_71 ] ) != 0 ) {
F_9 ( V_16 , L_31 , V_71 ) ;
return - V_59 ;
}
if ( V_2 -> V_31 == V_32 )
F_17 ( V_18 ) ;
memset ( V_44 , 0 , sizeof( V_44 ) ) ;
memcpy ( V_44 , & V_68 [ 1 ] , ( V_68 [ 0 ] * 4 ) ) ;
F_14 ( V_18 ) ;
return V_12 ;
}
static int F_38 ( unsigned char * V_72 )
{
return ( ( V_72 [ V_73 ] & 0xf0 ) == 0x90 ) ;
}
static int F_39 ( struct V_8 * V_74 ,
const struct V_75 * V_76 )
{
int V_13 , V_14 ;
unsigned char V_24 [ V_77 ] ;
struct V_1 * V_2 ;
struct V_17 * V_18 ;
if ( ! F_40 ( V_74 -> V_78 ,
V_79 ) ) {
F_4 ( & V_74 -> V_16 , L_32 ) ;
return - V_80 ;
}
V_18 = F_41 ( & V_74 -> V_16 , sizeof( * V_2 ) ) ;
if ( ! V_18 )
return - V_81 ;
V_2 = F_7 ( V_18 ) ;
V_2 -> V_9 = V_74 ;
F_42 ( V_74 , V_18 ) ;
F_43 ( & V_2 -> V_29 ) ;
V_2 -> V_31 = V_82 ;
memcpy ( V_2 -> V_60 , V_60 , sizeof( V_2 -> V_60 ) ) ;
for ( V_13 = 0 ; V_13 < V_77 ; V_13 ++ ) {
V_14 = F_3 ( V_74 ,
( V_15 | ( V_51 + V_13 ) ) ) ;
if ( V_14 < 0 ) {
F_4 ( & V_74 -> V_16 ,
L_33 ,
V_14 ) ;
return V_14 ;
}
V_14 = F_5 ( V_74 ) ;
if ( V_14 < 0 ) {
F_4 ( & V_74 -> V_16 ,
L_34 ,
V_14 ) ;
return V_14 ;
}
V_24 [ V_13 ] = V_14 ;
}
if ( ! F_38 ( V_24 ) ) {
F_9 ( & V_74 -> V_16 ,
L_35 ) ;
return - V_59 ;
}
V_14 = F_3 ( V_74 , ( V_15 | V_51 ) ) ;
if ( V_14 < 0 ) {
F_4 ( & V_74 -> V_16 ,
L_36 ,
V_14 ) ;
return V_14 ;
}
V_18 -> V_83 = & V_84 ;
V_18 -> V_16 . V_85 = & V_74 -> V_16 ;
V_18 -> V_86 = V_87 ;
V_18 -> V_88 = V_2 -> V_9 -> V_88 ;
V_14 = F_44 ( V_18 ) ;
if ( V_14 ) {
F_4 ( & V_74 -> V_16 , L_37 ) ;
return V_14 ;
}
F_1 ( V_2 ) ;
F_14 ( V_18 ) ;
F_9 ( & V_74 -> V_16 , L_38 ) ;
return 0 ;
}
static int F_45 ( struct V_65 * V_16 )
{
struct V_17 * V_18 = F_46 ( F_47 ( V_16 ) ) ;
struct V_1 * V_2 = F_7 ( V_18 ) ;
int V_14 = 0 ;
F_48 ( & V_2 -> V_29 ) ;
if ( V_2 -> V_31 == V_32 ) {
V_14 = F_17 ( V_18 ) ;
V_2 -> V_31 = V_64 ;
}
F_12 ( & V_2 -> V_29 ) ;
return V_14 ;
}
static int F_49 ( struct V_65 * V_16 )
{
struct V_17 * V_18 = F_46 ( F_47 ( V_16 ) ) ;
struct V_1 * V_2 = F_7 ( V_18 ) ;
int V_14 = 0 ;
F_48 ( & V_2 -> V_29 ) ;
if ( V_2 -> V_31 == V_64 )
V_14 = F_14 ( V_18 ) ;
F_12 ( & V_2 -> V_29 ) ;
return V_14 ;
}
static int F_50 ( struct V_8 * V_9 )
{
F_51 ( F_46 ( V_9 ) ) ;
return 0 ;
}
