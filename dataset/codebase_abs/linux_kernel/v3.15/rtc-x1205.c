static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
unsigned char V_5 )
{
unsigned char V_6 [ 2 ] = { 0 , V_5 } ;
unsigned char V_7 [ 8 ] ;
int V_8 ;
struct V_9 V_10 [] = {
{
. V_11 = V_2 -> V_11 ,
. V_12 = 2 ,
. V_7 = V_6
} ,
{
. V_11 = V_2 -> V_11 ,
. V_13 = V_14 ,
. V_12 = 8 ,
. V_7 = V_7
} ,
} ;
if ( F_2 ( V_2 -> V_15 , & V_10 [ 0 ] , 2 ) != 2 ) {
F_3 ( & V_2 -> V_16 , L_1 , V_17 ) ;
return - V_18 ;
}
F_4 ( & V_2 -> V_16 ,
L_2
L_3 ,
V_17 ,
V_7 [ 0 ] , V_7 [ 1 ] , V_7 [ 2 ] , V_7 [ 3 ] ,
V_7 [ 4 ] , V_7 [ 5 ] , V_7 [ 6 ] , V_7 [ 7 ] ) ;
if ( V_5 < V_19 )
for ( V_8 = 0 ; V_8 <= 4 ; V_8 ++ )
V_7 [ V_8 ] &= 0x7F ;
V_4 -> V_20 = F_5 ( V_7 [ V_21 ] ) ;
V_4 -> V_22 = F_5 ( V_7 [ V_23 ] ) ;
V_4 -> V_24 = F_5 ( V_7 [ V_25 ] & 0x3F ) ;
V_4 -> V_26 = F_5 ( V_7 [ V_27 ] ) ;
V_4 -> V_28 = F_5 ( V_7 [ V_29 ] ) - 1 ;
V_4 -> V_30 = F_5 ( V_7 [ V_31 ] )
+ ( F_5 ( V_7 [ V_32 ] ) * 100 ) - 1900 ;
V_4 -> V_33 = V_7 [ V_34 ] ;
F_4 ( & V_2 -> V_16 , L_4
L_5 ,
V_17 ,
V_4 -> V_20 , V_4 -> V_22 , V_4 -> V_24 ,
V_4 -> V_26 , V_4 -> V_28 , V_4 -> V_30 , V_4 -> V_33 ) ;
return 0 ;
}
static int F_6 ( struct V_1 * V_2 , unsigned char * V_35 )
{
static unsigned char V_36 [ 2 ] = { 0 , V_37 } ;
struct V_9 V_10 [] = {
{
. V_11 = V_2 -> V_11 ,
. V_12 = 2 ,
. V_7 = V_36
} ,
{
. V_11 = V_2 -> V_11 ,
. V_13 = V_14 ,
. V_12 = 1 ,
. V_7 = V_35
} ,
} ;
if ( F_2 ( V_2 -> V_15 , & V_10 [ 0 ] , 2 ) != 2 ) {
F_3 ( & V_2 -> V_16 , L_1 , V_17 ) ;
return - V_18 ;
}
return 0 ;
}
static int F_7 ( struct V_1 * V_2 , struct V_3 * V_4 ,
T_1 V_5 , unsigned char V_38 )
{
int V_8 , V_39 ;
unsigned char V_40 [ 10 ] = { 0 , V_5 } ;
unsigned char * V_7 = V_40 + 2 ;
static const unsigned char V_41 [ 3 ] = { 0 , V_37 ,
V_42 } ;
static const unsigned char V_43 [ 3 ] = { 0 , V_37 ,
V_42 | V_44 } ;
static const unsigned char V_45 [ 3 ] = { 0 , V_37 , 0 } ;
F_4 ( & V_2 -> V_16 ,
L_6 ,
V_17 , V_4 -> V_20 , V_4 -> V_22 , V_4 -> V_24 , V_4 -> V_26 ,
V_4 -> V_28 , V_4 -> V_30 , V_4 -> V_33 ) ;
V_7 [ V_21 ] = F_8 ( V_4 -> V_20 ) ;
V_7 [ V_23 ] = F_8 ( V_4 -> V_22 ) ;
V_7 [ V_25 ] = F_8 ( V_4 -> V_24 ) | V_46 ;
V_7 [ V_27 ] = F_8 ( V_4 -> V_26 ) ;
V_7 [ V_29 ] = F_8 ( V_4 -> V_28 + 1 ) ;
V_7 [ V_31 ] = F_8 ( V_4 -> V_30 % 100 ) ;
V_7 [ V_34 ] = V_4 -> V_33 & 0x07 ;
V_7 [ V_32 ] = F_8 ( ( V_4 -> V_30 + 1900 ) / 100 ) ;
if ( V_5 < V_19 )
for ( V_8 = 0 ; V_8 <= 4 ; V_8 ++ )
V_7 [ V_8 ] |= 0x80 ;
V_39 = F_9 ( V_2 , V_41 , 3 ) ;
if ( V_39 != 3 ) {
F_3 ( & V_2 -> V_16 , L_7 , V_17 , V_39 ) ;
return - V_18 ;
}
V_39 = F_9 ( V_2 , V_43 , 3 ) ;
if ( V_39 != 3 ) {
F_3 ( & V_2 -> V_16 , L_8 , V_17 , V_39 ) ;
return - V_18 ;
}
V_39 = F_9 ( V_2 , V_40 , sizeof( V_40 ) ) ;
if ( V_39 != sizeof( V_40 ) ) {
F_3 ( & V_2 -> V_16 ,
L_9 ,
V_17 ,
V_39 , V_40 [ 1 ] , V_40 [ 2 ] ) ;
return - V_18 ;
}
if ( V_5 < V_19 ) {
unsigned char V_47 [ 3 ] = { 0 , V_48 , 0 } ;
F_10 ( 10 ) ;
V_39 = F_9 ( V_2 , V_43 , 3 ) ;
if ( V_39 != 3 ) {
F_3 ( & V_2 -> V_16 ,
L_10 ,
V_17 ,
V_39 ) ;
return - V_18 ;
}
if ( V_38 )
V_47 [ 2 ] = V_49 ;
V_39 = F_9 ( V_2 , V_47 , 3 ) ;
if ( V_39 != 3 ) {
F_3 ( & V_2 -> V_16 ,
L_11 ,
V_17 ,
V_39 ) ;
return - V_18 ;
}
F_10 ( 10 ) ;
}
V_39 = F_9 ( V_2 , V_45 , 3 ) ;
if ( V_39 != 3 ) {
F_3 ( & V_2 -> V_16 , L_12 , V_17 , V_39 ) ;
return - V_18 ;
}
return 0 ;
}
static int F_11 ( struct V_1 * V_2 )
{
int V_50 ;
struct V_3 V_4 ;
memset ( & V_4 , 0 , sizeof( V_4 ) ) ;
V_50 = F_7 ( V_2 , & V_4 , V_19 , 0 ) ;
if ( V_50 < 0 )
F_3 ( & V_2 -> V_16 , L_13 ) ;
return V_50 ;
}
static int F_12 ( struct V_1 * V_2 , int * V_51 )
{
unsigned char V_52 ;
static unsigned char V_53 [ 2 ] = { 0 , V_54 } ;
struct V_9 V_10 [] = {
{
. V_11 = V_2 -> V_11 ,
. V_12 = 2 ,
. V_7 = V_53
} ,
{
. V_11 = V_2 -> V_11 ,
. V_13 = V_14 ,
. V_12 = 1 ,
. V_7 = & V_52
} ,
} ;
if ( F_2 ( V_2 -> V_15 , & V_10 [ 0 ] , 2 ) != 2 ) {
F_3 ( & V_2 -> V_16 , L_1 , V_17 ) ;
return - V_18 ;
}
F_4 ( & V_2 -> V_16 , L_14 , V_17 , V_52 ) ;
* V_51 = 0 ;
if ( V_52 & V_55 )
* V_51 += 20 ;
if ( V_52 & V_56 )
* V_51 += 10 ;
if ( V_52 & V_57 )
* V_51 = - * V_51 ;
return 0 ;
}
static int F_13 ( struct V_1 * V_2 , int * V_51 )
{
T_2 V_58 ;
static unsigned char V_59 [ 2 ] = { 0 , V_60 } ;
struct V_9 V_10 [] = {
{
. V_11 = V_2 -> V_11 ,
. V_12 = 2 ,
. V_7 = V_59
} ,
{
. V_11 = V_2 -> V_11 ,
. V_13 = V_14 ,
. V_12 = 1 ,
. V_7 = & V_58
} ,
} ;
if ( F_2 ( V_2 -> V_15 , & V_10 [ 0 ] , 2 ) != 2 ) {
F_3 ( & V_2 -> V_16 , L_1 , V_17 ) ;
return - V_18 ;
}
F_4 ( & V_2 -> V_16 , L_15 , V_17 , V_58 ) ;
if ( V_58 & 0x20 )
V_58 |= 0xC0 ;
F_4 ( & V_2 -> V_16 , L_16 , V_17 , V_58 , V_58 ) ;
* V_51 = ( V_58 * 250 ) + 11000 ;
F_4 ( & V_2 -> V_16 , L_17 , V_17 , * V_51 ) ;
return 0 ;
}
static int F_14 ( struct V_1 * V_2 )
{
int V_8 , V_39 ;
static const unsigned char V_61 [] = {
V_37 , 0x18 ,
V_54 , 0xF8 ,
V_60 , 0xC0 ,
V_48 , 0x18 ,
V_62 , 0xFF ,
} ;
static const struct V_63 V_64 [] = {
{ V_65 , 0xFF , 19 , 20 } ,
{ V_66 , 0xFF , 0 , 6 } ,
{ V_67 , 0xFF , 0 , 99 } ,
{ V_68 , 0xFF , 0 , 12 } ,
{ V_69 , 0xFF , 0 , 31 } ,
{ V_70 , 0x7F , 0 , 23 } ,
{ V_71 , 0xFF , 0 , 59 } ,
{ V_72 , 0xFF , 0 , 59 } ,
{ V_73 , 0xFF , 19 , 20 } ,
{ V_74 , 0xFF , 19 , 20 } ,
} ;
for ( V_8 = 0 ; V_8 < F_15 ( V_61 ) ; V_8 += 2 ) {
unsigned char V_7 ;
unsigned char V_11 [ 2 ] = { 0 , V_61 [ V_8 ] } ;
struct V_9 V_10 [ 2 ] = {
{
. V_11 = V_2 -> V_11 ,
. V_12 = 2 ,
. V_7 = V_11
} ,
{
. V_11 = V_2 -> V_11 ,
. V_13 = V_14 ,
. V_12 = 1 ,
. V_7 = & V_7
} ,
} ;
V_39 = F_2 ( V_2 -> V_15 , V_10 , 2 ) ;
if ( V_39 != 2 ) {
F_3 ( & V_2 -> V_16 ,
L_18 ,
V_17 , V_61 [ V_8 ] ) ;
return - V_18 ;
}
if ( ( V_7 & V_61 [ V_8 + 1 ] ) != 0 ) {
F_3 ( & V_2 -> V_16 ,
L_19 ,
V_17 , V_61 [ V_8 ] , V_8 , V_7 ) ;
return - V_75 ;
}
}
for ( V_8 = 0 ; V_8 < F_15 ( V_64 ) ; V_8 ++ ) {
unsigned char V_76 , V_77 ;
unsigned char V_11 [ 2 ] = { 0 , V_64 [ V_8 ] . V_76 } ;
struct V_9 V_10 [ 2 ] = {
{
. V_11 = V_2 -> V_11 ,
. V_12 = 2 ,
. V_7 = V_11
} ,
{
. V_11 = V_2 -> V_11 ,
. V_13 = V_14 ,
. V_12 = 1 ,
. V_7 = & V_76
} ,
} ;
V_39 = F_2 ( V_2 -> V_15 , V_10 , 2 ) ;
if ( V_39 != 2 ) {
F_3 ( & V_2 -> V_16 ,
L_18 ,
V_17 , V_64 [ V_8 ] . V_76 ) ;
return - V_18 ;
}
V_77 = F_5 ( V_76 & V_64 [ V_8 ] . V_78 ) ;
if ( V_77 > V_64 [ V_8 ] . V_79 ||
V_77 < V_64 [ V_8 ] . V_80 ) {
F_4 ( & V_2 -> V_16 ,
L_20 ,
V_17 , V_64 [ V_8 ] . V_76 ,
V_8 , V_77 ) ;
return - V_75 ;
}
}
return 0 ;
}
static int F_16 ( struct V_81 * V_16 , struct V_82 * V_83 )
{
int V_50 ;
unsigned char V_84 , V_85 ;
static unsigned char V_86 [ 2 ] = { 0 , V_48 } ;
struct V_1 * V_2 = F_17 ( V_16 ) ;
struct V_9 V_10 [] = {
{
. V_11 = V_2 -> V_11 ,
. V_12 = 2 ,
. V_7 = V_86
} ,
{
. V_11 = V_2 -> V_11 ,
. V_13 = V_14 ,
. V_12 = 1 ,
. V_7 = & V_84
} ,
} ;
if ( F_2 ( V_2 -> V_15 , & V_10 [ 0 ] , 2 ) != 2 ) {
F_3 ( & V_2 -> V_16 , L_1 , V_17 ) ;
return - V_18 ;
}
V_50 = F_6 ( V_2 , & V_85 ) ;
if ( V_50 == 0 ) {
V_83 -> V_87 = ( V_85 & V_88 ) ? 1 : 0 ;
V_83 -> V_89 = ( V_84 & V_49 ) ? 1 : 0 ;
V_50 = F_1 ( V_2 , & V_83 -> time , V_90 ) ;
}
return V_50 ;
}
static int F_18 ( struct V_81 * V_16 , struct V_82 * V_83 )
{
return F_7 ( F_17 ( V_16 ) ,
& V_83 -> time , V_90 , V_83 -> V_89 ) ;
}
static int F_19 ( struct V_81 * V_16 , struct V_3 * V_4 )
{
return F_1 ( F_17 ( V_16 ) ,
V_4 , V_19 ) ;
}
static int F_20 ( struct V_81 * V_16 , struct V_3 * V_4 )
{
return F_7 ( F_17 ( V_16 ) ,
V_4 , V_19 , 0 ) ;
}
static int F_21 ( struct V_81 * V_16 , struct V_91 * V_92 )
{
int V_50 , V_93 , V_94 ;
V_50 = F_12 ( F_17 ( V_16 ) , & V_93 ) ;
if ( ! V_50 )
F_22 ( V_92 , L_21 , V_93 ) ;
V_50 = F_13 ( F_17 ( V_16 ) , & V_94 ) ;
if ( ! V_50 )
F_22 ( V_92 , L_22 ,
V_94 / 1000 , V_94 % 1000 ) ;
return 0 ;
}
static T_3 F_23 ( struct V_81 * V_16 ,
struct V_95 * V_96 , char * V_7 )
{
int V_50 , V_94 ;
V_50 = F_13 ( F_17 ( V_16 ) , & V_94 ) ;
if ( V_50 )
return V_50 ;
return sprintf ( V_7 , L_23 , V_94 / 1000 , V_94 % 1000 ) ;
}
static T_3 F_24 ( struct V_81 * V_16 ,
struct V_95 * V_96 , char * V_7 )
{
int V_50 , V_93 ;
V_50 = F_12 ( F_17 ( V_16 ) , & V_93 ) ;
if ( V_50 )
return V_50 ;
return sprintf ( V_7 , L_24 , V_93 ) ;
}
static int F_25 ( struct V_81 * V_16 )
{
int V_50 ;
V_50 = F_26 ( V_16 , & V_97 ) ;
if ( V_50 )
return V_50 ;
V_50 = F_26 ( V_16 , & V_98 ) ;
if ( V_50 )
F_27 ( V_16 , & V_97 ) ;
return V_50 ;
}
static void F_28 ( struct V_81 * V_16 )
{
F_27 ( V_16 , & V_97 ) ;
F_27 ( V_16 , & V_98 ) ;
}
static int F_29 ( struct V_1 * V_2 ,
const struct V_99 * V_100 )
{
int V_50 = 0 ;
unsigned char V_35 ;
struct V_101 * V_102 ;
F_4 ( & V_2 -> V_16 , L_25 , V_17 ) ;
if ( ! F_30 ( V_2 -> V_15 , V_103 ) )
return - V_75 ;
if ( F_14 ( V_2 ) < 0 )
return - V_75 ;
F_31 ( & V_2 -> V_16 , L_26 V_104 L_27 ) ;
V_102 = F_32 ( & V_2 -> V_16 , V_105 . V_106 . V_107 ,
& V_108 , V_109 ) ;
if ( F_33 ( V_102 ) )
return F_34 ( V_102 ) ;
F_35 ( V_2 , V_102 ) ;
V_50 = F_6 ( V_2 , & V_35 ) ;
if ( ! V_50 ) {
if ( V_35 & V_110 ) {
F_3 ( & V_2 -> V_16 ,
L_28
L_29 ) ;
F_36 ( 50 ) ;
F_11 ( V_2 ) ;
}
} else {
F_3 ( & V_2 -> V_16 , L_30 ) ;
}
V_50 = F_25 ( & V_2 -> V_16 ) ;
if ( V_50 )
F_3 ( & V_2 -> V_16 , L_31 ) ;
return 0 ;
}
static int F_37 ( struct V_1 * V_2 )
{
F_28 ( & V_2 -> V_16 ) ;
return 0 ;
}
