static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
unsigned char V_5 )
{
unsigned char V_6 [ 2 ] = { 0 , V_5 } ;
unsigned char V_7 [ 8 ] ;
int V_8 ;
struct V_9 V_10 [] = {
{ V_2 -> V_11 , 0 , 2 , V_6 } ,
{ V_2 -> V_11 , V_12 , 8 , V_7 } ,
} ;
if ( F_2 ( V_2 -> V_13 , & V_10 [ 0 ] , 2 ) != 2 ) {
F_3 ( & V_2 -> V_14 , L_1 , V_15 ) ;
return - V_16 ;
}
F_4 ( & V_2 -> V_14 ,
L_2
L_3 ,
V_15 ,
V_7 [ 0 ] , V_7 [ 1 ] , V_7 [ 2 ] , V_7 [ 3 ] ,
V_7 [ 4 ] , V_7 [ 5 ] , V_7 [ 6 ] , V_7 [ 7 ] ) ;
if ( V_5 < V_17 )
for ( V_8 = 0 ; V_8 <= 4 ; V_8 ++ )
V_7 [ V_8 ] &= 0x7F ;
V_4 -> V_18 = F_5 ( V_7 [ V_19 ] ) ;
V_4 -> V_20 = F_5 ( V_7 [ V_21 ] ) ;
V_4 -> V_22 = F_5 ( V_7 [ V_23 ] & 0x3F ) ;
V_4 -> V_24 = F_5 ( V_7 [ V_25 ] ) ;
V_4 -> V_26 = F_5 ( V_7 [ V_27 ] ) - 1 ;
V_4 -> V_28 = F_5 ( V_7 [ V_29 ] )
+ ( F_5 ( V_7 [ V_30 ] ) * 100 ) - 1900 ;
V_4 -> V_31 = V_7 [ V_32 ] ;
F_4 ( & V_2 -> V_14 , L_4
L_5 ,
V_15 ,
V_4 -> V_18 , V_4 -> V_20 , V_4 -> V_22 ,
V_4 -> V_24 , V_4 -> V_26 , V_4 -> V_28 , V_4 -> V_31 ) ;
return 0 ;
}
static int F_6 ( struct V_1 * V_2 , unsigned char * V_33 )
{
static unsigned char V_34 [ 2 ] = { 0 , V_35 } ;
struct V_9 V_10 [] = {
{ V_2 -> V_11 , 0 , 2 , V_34 } ,
{ V_2 -> V_11 , V_12 , 1 , V_33 } ,
} ;
if ( F_2 ( V_2 -> V_13 , & V_10 [ 0 ] , 2 ) != 2 ) {
F_3 ( & V_2 -> V_14 , L_1 , V_15 ) ;
return - V_16 ;
}
return 0 ;
}
static int F_7 ( struct V_1 * V_2 , struct V_3 * V_4 ,
T_1 V_5 , unsigned char V_36 )
{
int V_8 , V_37 ;
unsigned char V_38 [ 10 ] = { 0 , V_5 } ;
unsigned char * V_7 = V_38 + 2 ;
static const unsigned char V_39 [ 3 ] = { 0 , V_35 ,
V_40 } ;
static const unsigned char V_41 [ 3 ] = { 0 , V_35 ,
V_40 | V_42 } ;
static const unsigned char V_43 [ 3 ] = { 0 , V_35 , 0 } ;
F_4 ( & V_2 -> V_14 ,
L_6 ,
V_15 , V_4 -> V_18 , V_4 -> V_20 , V_4 -> V_22 , V_4 -> V_24 ,
V_4 -> V_26 , V_4 -> V_28 , V_4 -> V_31 ) ;
V_7 [ V_19 ] = F_8 ( V_4 -> V_18 ) ;
V_7 [ V_21 ] = F_8 ( V_4 -> V_20 ) ;
V_7 [ V_23 ] = F_8 ( V_4 -> V_22 ) | V_44 ;
V_7 [ V_25 ] = F_8 ( V_4 -> V_24 ) ;
V_7 [ V_27 ] = F_8 ( V_4 -> V_26 + 1 ) ;
V_7 [ V_29 ] = F_8 ( V_4 -> V_28 % 100 ) ;
V_7 [ V_32 ] = V_4 -> V_31 & 0x07 ;
V_7 [ V_30 ] = F_8 ( ( V_4 -> V_28 + 1900 ) / 100 ) ;
if ( V_5 < V_17 )
for ( V_8 = 0 ; V_8 <= 4 ; V_8 ++ )
V_7 [ V_8 ] |= 0x80 ;
if ( ( V_37 = F_9 ( V_2 , V_39 , 3 ) ) != 3 ) {
F_3 ( & V_2 -> V_14 , L_7 , V_15 , V_37 ) ;
return - V_16 ;
}
if ( ( V_37 = F_9 ( V_2 , V_41 , 3 ) ) != 3 ) {
F_3 ( & V_2 -> V_14 , L_8 , V_15 , V_37 ) ;
return - V_16 ;
}
V_37 = F_9 ( V_2 , V_38 , sizeof( V_38 ) ) ;
if ( V_37 != sizeof( V_38 ) ) {
F_3 ( & V_2 -> V_14 ,
L_9 ,
V_15 ,
V_37 , V_38 [ 1 ] , V_38 [ 2 ] ) ;
return - V_16 ;
}
if ( V_5 < V_17 ) {
unsigned char V_45 [ 3 ] = { 0 , V_46 , 0 } ;
F_10 ( 10 ) ;
V_37 = F_9 ( V_2 , V_41 , 3 ) ;
if ( V_37 != 3 ) {
F_3 ( & V_2 -> V_14 ,
L_10 ,
V_15 ,
V_37 ) ;
return - V_16 ;
}
if ( V_36 )
V_45 [ 2 ] = V_47 ;
V_37 = F_9 ( V_2 , V_45 , 3 ) ;
if ( V_37 != 3 ) {
F_3 ( & V_2 -> V_14 ,
L_11 ,
V_15 ,
V_37 ) ;
return - V_16 ;
}
F_10 ( 10 ) ;
}
if ( ( V_37 = F_9 ( V_2 , V_43 , 3 ) ) != 3 ) {
F_3 ( & V_2 -> V_14 , L_12 , V_15 , V_37 ) ;
return - V_16 ;
}
return 0 ;
}
static int F_11 ( struct V_1 * V_2 )
{
int V_48 ;
struct V_3 V_4 ;
memset ( & V_4 , 0 , sizeof( V_4 ) ) ;
V_48 = F_7 ( V_2 , & V_4 , V_17 , 0 ) ;
if ( V_48 < 0 )
F_3 ( & V_2 -> V_14 , L_13 ) ;
return V_48 ;
}
static int F_12 ( struct V_1 * V_2 , int * V_49 )
{
unsigned char V_50 ;
static unsigned char V_51 [ 2 ] = { 0 , V_52 } ;
struct V_9 V_10 [] = {
{ V_2 -> V_11 , 0 , 2 , V_51 } ,
{ V_2 -> V_11 , V_12 , 1 , & V_50 } ,
} ;
if ( F_2 ( V_2 -> V_13 , & V_10 [ 0 ] , 2 ) != 2 ) {
F_3 ( & V_2 -> V_14 , L_1 , V_15 ) ;
return - V_16 ;
}
F_4 ( & V_2 -> V_14 , L_14 , V_15 , V_50 ) ;
* V_49 = 0 ;
if ( V_50 & V_53 )
* V_49 += 20 ;
if ( V_50 & V_54 )
* V_49 += 10 ;
if ( V_50 & V_55 )
* V_49 = - * V_49 ;
return 0 ;
}
static int F_13 ( struct V_1 * V_2 , int * V_49 )
{
T_2 V_56 ;
static unsigned char V_57 [ 2 ] = { 0 , V_58 } ;
struct V_9 V_10 [] = {
{ V_2 -> V_11 , 0 , 2 , V_57 } ,
{ V_2 -> V_11 , V_12 , 1 , & V_56 } ,
} ;
if ( F_2 ( V_2 -> V_13 , & V_10 [ 0 ] , 2 ) != 2 ) {
F_3 ( & V_2 -> V_14 , L_1 , V_15 ) ;
return - V_16 ;
}
F_4 ( & V_2 -> V_14 , L_15 , V_15 , V_56 ) ;
if ( V_56 & 0x20 )
V_56 |= 0xC0 ;
F_4 ( & V_2 -> V_14 , L_16 , V_15 , V_56 , V_56 ) ;
* V_49 = ( V_56 * 250 ) + 11000 ;
F_4 ( & V_2 -> V_14 , L_17 , V_15 , * V_49 ) ;
return 0 ;
}
static int F_14 ( struct V_1 * V_2 )
{
int V_8 , V_37 ;
static const unsigned char V_59 [] = {
V_35 , 0x18 ,
V_52 , 0xF8 ,
V_58 , 0xC0 ,
V_46 , 0x18 ,
V_60 , 0xFF ,
} ;
static const struct V_61 V_62 [] = {
{ V_63 , 0xFF , 19 , 20 } ,
{ V_64 , 0xFF , 0 , 6 } ,
{ V_65 , 0xFF , 0 , 99 } ,
{ V_66 , 0xFF , 0 , 12 } ,
{ V_67 , 0xFF , 0 , 31 } ,
{ V_68 , 0x7F , 0 , 23 } ,
{ V_69 , 0xFF , 0 , 59 } ,
{ V_70 , 0xFF , 0 , 59 } ,
{ V_71 , 0xFF , 19 , 20 } ,
{ V_72 , 0xFF , 19 , 20 } ,
} ;
for ( V_8 = 0 ; V_8 < F_15 ( V_59 ) ; V_8 += 2 ) {
unsigned char V_7 ;
unsigned char V_11 [ 2 ] = { 0 , V_59 [ V_8 ] } ;
struct V_9 V_10 [ 2 ] = {
{ V_2 -> V_11 , 0 , 2 , V_11 } ,
{ V_2 -> V_11 , V_12 , 1 , & V_7 } ,
} ;
if ( ( V_37 = F_2 ( V_2 -> V_13 , V_10 , 2 ) ) != 2 ) {
F_3 ( & V_2 -> V_14 ,
L_18 ,
V_15 , V_59 [ V_8 ] ) ;
return - V_16 ;
}
if ( ( V_7 & V_59 [ V_8 + 1 ] ) != 0 ) {
F_3 ( & V_2 -> V_14 ,
L_19 ,
V_15 , V_59 [ V_8 ] , V_8 , V_7 ) ;
return - V_73 ;
}
}
for ( V_8 = 0 ; V_8 < F_15 ( V_62 ) ; V_8 ++ ) {
unsigned char V_74 , V_75 ;
unsigned char V_11 [ 2 ] = { 0 , V_62 [ V_8 ] . V_74 } ;
struct V_9 V_10 [ 2 ] = {
{ V_2 -> V_11 , 0 , 2 , V_11 } ,
{ V_2 -> V_11 , V_12 , 1 , & V_74 } ,
} ;
if ( ( V_37 = F_2 ( V_2 -> V_13 , V_10 , 2 ) ) != 2 ) {
F_3 ( & V_2 -> V_14 ,
L_18 ,
V_15 , V_62 [ V_8 ] . V_74 ) ;
return - V_16 ;
}
V_75 = F_5 ( V_74 & V_62 [ V_8 ] . V_76 ) ;
if ( V_75 > V_62 [ V_8 ] . V_77 ||
V_75 < V_62 [ V_8 ] . V_78 ) {
F_4 ( & V_2 -> V_14 ,
L_20 ,
V_15 , V_62 [ V_8 ] . V_74 ,
V_8 , V_75 ) ;
return - V_73 ;
}
}
return 0 ;
}
static int F_16 ( struct V_79 * V_14 , struct V_80 * V_81 )
{
int V_48 ;
unsigned char V_82 , V_83 ;
static unsigned char V_84 [ 2 ] = { 0 , V_46 } ;
struct V_1 * V_2 = F_17 ( V_14 ) ;
struct V_9 V_10 [] = {
{ V_2 -> V_11 , 0 , 2 , V_84 } ,
{ V_2 -> V_11 , V_12 , 1 , & V_82 } ,
} ;
if ( F_2 ( V_2 -> V_13 , & V_10 [ 0 ] , 2 ) != 2 ) {
F_3 ( & V_2 -> V_14 , L_1 , V_15 ) ;
return - V_16 ;
}
V_48 = F_6 ( V_2 , & V_83 ) ;
if ( V_48 == 0 ) {
V_81 -> V_85 = ( V_83 & V_86 ) ? 1 : 0 ;
V_81 -> V_87 = ( V_82 & V_47 ) ? 1 : 0 ;
V_48 = F_1 ( V_2 , & V_81 -> time , V_88 ) ;
}
return V_48 ;
}
static int F_18 ( struct V_79 * V_14 , struct V_80 * V_81 )
{
return F_7 ( F_17 ( V_14 ) ,
& V_81 -> time , V_88 , V_81 -> V_87 ) ;
}
static int F_19 ( struct V_79 * V_14 , struct V_3 * V_4 )
{
return F_1 ( F_17 ( V_14 ) ,
V_4 , V_17 ) ;
}
static int F_20 ( struct V_79 * V_14 , struct V_3 * V_4 )
{
return F_7 ( F_17 ( V_14 ) ,
V_4 , V_17 , 0 ) ;
}
static int F_21 ( struct V_79 * V_14 , struct V_89 * V_90 )
{
int V_48 , V_91 , V_92 ;
if ( ( V_48 = F_12 ( F_17 ( V_14 ) , & V_91 ) ) == 0 )
F_22 ( V_90 , L_21 , V_91 ) ;
if ( ( V_48 = F_13 ( F_17 ( V_14 ) , & V_92 ) ) == 0 )
F_22 ( V_90 , L_22 ,
V_92 / 1000 , V_92 % 1000 ) ;
return 0 ;
}
static T_3 F_23 ( struct V_79 * V_14 ,
struct V_93 * V_94 , char * V_7 )
{
int V_48 , V_92 ;
V_48 = F_13 ( F_17 ( V_14 ) , & V_92 ) ;
if ( V_48 )
return V_48 ;
return sprintf ( V_7 , L_23 , V_92 / 1000 , V_92 % 1000 ) ;
}
static T_3 F_24 ( struct V_79 * V_14 ,
struct V_93 * V_94 , char * V_7 )
{
int V_48 , V_91 ;
V_48 = F_12 ( F_17 ( V_14 ) , & V_91 ) ;
if ( V_48 )
return V_48 ;
return sprintf ( V_7 , L_24 , V_91 ) ;
}
static int F_25 ( struct V_79 * V_14 )
{
int V_48 ;
V_48 = F_26 ( V_14 , & V_95 ) ;
if ( V_48 )
return V_48 ;
V_48 = F_26 ( V_14 , & V_96 ) ;
if ( V_48 )
F_27 ( V_14 , & V_95 ) ;
return V_48 ;
}
static void F_28 ( struct V_79 * V_14 )
{
F_27 ( V_14 , & V_95 ) ;
F_27 ( V_14 , & V_96 ) ;
}
static int F_29 ( struct V_1 * V_2 ,
const struct V_97 * V_98 )
{
int V_48 = 0 ;
unsigned char V_33 ;
struct V_99 * V_100 ;
F_4 ( & V_2 -> V_14 , L_25 , V_15 ) ;
if ( ! F_30 ( V_2 -> V_13 , V_101 ) )
return - V_73 ;
if ( F_14 ( V_2 ) < 0 )
return - V_73 ;
F_31 ( & V_2 -> V_14 , L_26 V_102 L_27 ) ;
V_100 = F_32 ( V_103 . V_104 . V_105 , & V_2 -> V_14 ,
& V_106 , V_107 ) ;
if ( F_33 ( V_100 ) )
return F_34 ( V_100 ) ;
F_35 ( V_2 , V_100 ) ;
if ( ( V_48 = F_6 ( V_2 , & V_33 ) ) == 0 ) {
if ( V_33 & V_108 ) {
F_3 ( & V_2 -> V_14 ,
L_28
L_29 ) ;
F_36 ( 50 ) ;
F_11 ( V_2 ) ;
}
}
else
F_3 ( & V_2 -> V_14 , L_30 ) ;
V_48 = F_25 ( & V_2 -> V_14 ) ;
if ( V_48 )
goto V_109;
return 0 ;
V_109:
F_37 ( V_100 ) ;
return V_48 ;
}
static int F_38 ( struct V_1 * V_2 )
{
struct V_99 * V_100 = F_39 ( V_2 ) ;
F_37 ( V_100 ) ;
F_28 ( & V_2 -> V_14 ) ;
return 0 ;
}
static int T_4 F_40 ( void )
{
return F_41 ( & V_103 ) ;
}
static void T_5 F_42 ( void )
{
F_43 ( & V_103 ) ;
}
