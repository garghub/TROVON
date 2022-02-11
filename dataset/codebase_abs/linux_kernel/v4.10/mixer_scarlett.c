static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
V_4 -> type = V_8 ;
V_4 -> V_9 = V_6 -> V_10 ;
V_4 -> V_11 . integer . V_12 = 0 ;
V_4 -> V_11 . integer . V_13 = 1 ;
return 0 ;
}
static int F_2 ( struct V_1 * V_2 ,
struct V_14 * V_15 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
int V_16 , V_17 , V_18 ;
for ( V_16 = 0 ; V_16 < V_6 -> V_10 ; V_16 ++ ) {
V_17 = F_3 ( V_6 , V_16 , V_16 , & V_18 ) ;
if ( V_17 < 0 )
return V_17 ;
V_18 = ! V_18 ;
V_15 -> V_11 . integer . V_11 [ V_16 ] = V_18 ;
}
return 0 ;
}
static int F_4 ( struct V_1 * V_2 ,
struct V_14 * V_15 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
int V_16 , V_19 = 0 ;
int V_17 , V_20 , V_18 ;
for ( V_16 = 0 ; V_16 < V_6 -> V_10 ; V_16 ++ ) {
V_17 = F_3 ( V_6 , V_16 , V_16 , & V_20 ) ;
if ( V_17 < 0 )
return V_17 ;
V_18 = V_15 -> V_11 . integer . V_11 [ V_16 ] ;
V_18 = ! V_18 ;
if ( V_20 != V_18 ) {
V_17 = F_5 ( V_6 , V_16 , V_16 , V_18 ) ;
if ( V_17 < 0 )
return V_17 ;
V_19 = 1 ;
}
}
return V_19 ;
}
static int F_6 ( struct V_21 * V_22 )
{
struct V_5 * V_6 =
F_7 ( V_22 , struct V_5 , V_23 ) ;
int V_16 ;
for ( V_16 = 0 ; V_16 < V_6 -> V_10 ; V_16 ++ )
if ( V_6 -> V_24 & ( 1 << V_16 ) )
F_5 ( V_6 , V_16 , V_16 ,
V_6 -> V_25 [ V_16 ] ) ;
return 0 ;
}
static int F_8 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
V_4 -> type = V_26 ;
V_4 -> V_9 = V_6 -> V_10 ;
V_4 -> V_11 . integer . V_12 = 0 ;
V_4 -> V_11 . integer . V_13 = ( int ) V_2 -> V_27 +
V_28 ;
V_4 -> V_11 . integer . V_29 = 1 ;
return 0 ;
}
static int F_9 ( struct V_1 * V_2 ,
struct V_14 * V_15 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
int V_16 , V_17 , V_18 ;
for ( V_16 = 0 ; V_16 < V_6 -> V_10 ; V_16 ++ ) {
V_17 = F_3 ( V_6 , V_16 , V_16 , & V_18 ) ;
if ( V_17 < 0 )
return V_17 ;
V_18 = F_10 ( V_18 / 256 , - 128 , ( int ) V_2 -> V_27 ) +
V_28 ;
V_15 -> V_11 . integer . V_11 [ V_16 ] = V_18 ;
}
return 0 ;
}
static int F_11 ( struct V_1 * V_2 ,
struct V_14 * V_15 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
int V_16 , V_19 = 0 ;
int V_17 , V_20 , V_18 ;
for ( V_16 = 0 ; V_16 < V_6 -> V_10 ; V_16 ++ ) {
V_17 = F_3 ( V_6 , V_16 , V_16 , & V_20 ) ;
if ( V_17 < 0 )
return V_17 ;
V_18 = V_15 -> V_11 . integer . V_11 [ V_16 ] -
V_28 ;
V_18 = V_18 * 256 ;
if ( V_20 != V_18 ) {
V_17 = F_5 ( V_6 , V_16 , V_16 , V_18 ) ;
if ( V_17 < 0 )
return V_17 ;
V_19 = 1 ;
}
}
return V_19 ;
}
static void F_12 ( int V_16 , char * V_30 , int V_31 [] )
{
if ( V_16 > V_31 [ V_32 ] )
sprintf ( V_30 , L_1 ,
'A' + ( V_16 - V_31 [ V_32 ] - 1 ) ) ;
else if ( V_16 > V_31 [ V_33 ] )
sprintf ( V_30 , L_2 , V_16 - V_31 [ V_33 ] ) ;
else if ( V_16 > V_31 [ V_34 ] )
sprintf ( V_30 , L_3 , V_16 - V_31 [ V_34 ] ) ;
else if ( V_16 > V_31 [ V_35 ] )
sprintf ( V_30 , L_4 , V_16 - V_31 [ V_35 ] ) ;
else if ( V_16 > V_31 [ V_36 ] )
sprintf ( V_30 , L_5 , V_16 - V_31 [ V_36 ] ) ;
else
sprintf ( V_30 , L_6 ) ;
}
static int F_13 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_37 * V_38 = V_6 -> V_7 ;
unsigned int V_39 = V_38 -> V_40 ;
V_4 -> type = V_41 ;
V_4 -> V_9 = V_6 -> V_10 ;
V_4 -> V_11 . V_42 . V_39 = V_39 ;
if ( V_4 -> V_11 . V_42 . V_43 >= V_39 )
V_4 -> V_11 . V_42 . V_43 = V_39 - 1 ;
F_12 ( V_4 -> V_11 . V_42 . V_43 ,
V_4 -> V_11 . V_42 . V_44 ,
V_38 -> V_31 ) ;
return 0 ;
}
static int F_14 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_37 * V_38 = V_6 -> V_7 ;
return F_15 ( V_4 , V_6 -> V_10 , V_38 -> V_40 ,
( const char * const * ) V_38 -> V_45 ) ;
}
static int F_16 ( struct V_1 * V_2 ,
struct V_14 * V_15 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_37 * V_38 = V_6 -> V_7 ;
int V_17 , V_18 ;
V_17 = F_3 ( V_6 , 0 , 0 , & V_18 ) ;
if ( V_17 < 0 )
return V_17 ;
V_18 = F_10 ( V_18 - V_38 -> V_46 , 0 , V_38 -> V_40 - 1 ) ;
V_15 -> V_11 . V_42 . V_43 [ 0 ] = V_18 ;
return 0 ;
}
static int F_17 ( struct V_1 * V_2 ,
struct V_14 * V_15 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_37 * V_38 = V_6 -> V_7 ;
int V_17 , V_20 , V_18 ;
V_17 = F_3 ( V_6 , 0 , 0 , & V_20 ) ;
if ( V_17 < 0 )
return V_17 ;
V_18 = V_15 -> V_11 . integer . V_11 [ 0 ] ;
V_18 = V_18 + V_38 -> V_46 ;
if ( V_18 != V_20 ) {
F_5 ( V_6 , 0 , 0 , V_18 ) ;
return 1 ;
}
return 0 ;
}
static int F_18 ( struct V_21 * V_22 )
{
struct V_5 * V_6 =
F_7 ( V_22 , struct V_5 , V_23 ) ;
if ( V_6 -> V_24 )
F_5 ( V_6 , 0 , 0 , * V_6 -> V_25 ) ;
return 0 ;
}
static int F_19 ( struct V_1 * V_2 ,
struct V_14 * V_15 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_47 * V_48 = V_6 -> V_23 . V_49 -> V_48 ;
unsigned char V_50 [ 2 * V_51 ] = { 0 , } ;
int V_52 = ( V_6 -> V_53 << 8 ) | V_6 -> V_54 ;
int V_55 = F_20 ( V_48 ) | ( V_6 -> V_23 . V_56 << 8 ) ;
int V_17 ;
V_17 = F_21 ( V_48 -> V_57 ,
F_22 ( V_48 -> V_57 , 0 ) ,
V_58 ,
V_59 | V_60 |
V_61 , V_52 , V_55 , V_50 , V_6 -> V_10 ) ;
if ( V_17 < 0 )
return V_17 ;
V_15 -> V_11 . V_42 . V_43 [ 0 ] = F_10 ( ( int ) V_50 [ 0 ] , 0 , 1 ) ;
return 0 ;
}
static int F_23 ( struct V_62 * V_49 ,
const struct V_63 * V_64 ,
T_1 V_65 ,
int V_66 , int V_67 , int V_68 ,
int V_69 , int V_10 , const char * V_44 ,
const struct V_37 * V_38 ,
struct V_5 * * V_70
)
{
struct V_1 * V_2 ;
struct V_5 * V_6 ;
int V_17 ;
V_6 = F_24 ( sizeof( * V_6 ) , V_71 ) ;
if ( ! V_6 )
return - V_72 ;
V_6 -> V_23 . V_49 = V_49 ;
V_6 -> V_23 . V_65 = V_65 ;
V_6 -> V_53 = V_67 ;
V_6 -> V_54 = V_68 ;
V_6 -> V_23 . V_56 = V_66 ;
V_6 -> V_69 = V_69 ;
V_6 -> V_10 = V_10 ;
V_6 -> V_7 = ( void * ) V_38 ;
V_2 = F_25 ( V_64 , V_6 ) ;
if ( ! V_2 ) {
F_26 ( V_6 ) ;
return - V_72 ;
}
V_2 -> V_73 = V_74 ;
F_27 ( V_2 -> V_56 . V_44 , V_44 , sizeof( V_2 -> V_56 . V_44 ) ) ;
V_17 = F_28 ( & V_6 -> V_23 , V_2 ) ;
if ( V_17 < 0 )
return V_17 ;
if ( V_70 )
* V_70 = V_6 ;
return 0 ;
}
static int F_29 ( struct V_62 * V_49 ,
int V_66 , const char * V_44 ,
const struct V_75 * V_76 )
{
int V_17 ;
char V_77 [ V_78 ] ;
struct V_5 * V_6 ;
snprintf ( V_77 , sizeof( V_77 ) , L_7 ,
V_66 + 1 , V_44 ) ;
V_17 = F_23 ( V_49 , & V_79 ,
F_6 , 0x0a , 0x01 ,
2 * V_66 + 1 , V_80 , 2 , V_77 , NULL , & V_6 ) ;
if ( V_17 < 0 )
return V_17 ;
snprintf ( V_77 , sizeof( V_77 ) , L_8 ,
V_66 + 1 , V_44 ) ;
V_17 = F_23 ( V_49 , & V_81 ,
F_6 , 0x0a , 0x02 ,
2 * V_66 + 1 , V_80 , 2 , V_77 , NULL , & V_6 ) ;
if ( V_17 < 0 )
return V_17 ;
snprintf ( V_77 , sizeof( V_77 ) , L_9 ,
V_66 + 1 , V_44 ) ;
V_17 = F_23 ( V_49 , & V_82 ,
F_18 , 0x33 , 0x00 ,
2 * V_66 , V_80 , 1 , V_77 , & V_76 -> V_83 ,
& V_6 ) ;
if ( V_17 < 0 )
return V_17 ;
snprintf ( V_77 , sizeof( V_77 ) , L_10 ,
V_66 + 1 , V_44 ) ;
V_17 = F_23 ( V_49 , & V_82 ,
F_18 , 0x33 , 0x00 ,
2 * V_66 + 1 , V_80 , 1 , V_77 , & V_76 -> V_83 ,
& V_6 ) ;
if ( V_17 < 0 )
return V_17 ;
return 0 ;
}
static int F_30 ( struct V_62 * V_49 ,
struct V_75 * V_76 )
{
int V_16 , V_17 ;
char V_77 [ V_78 ] ;
const struct V_84 * V_85 ;
struct V_5 * V_6 ;
V_17 = F_23 ( V_49 , & V_79 ,
F_6 , 0x0a , 0x01 , 0 ,
V_80 , 1 , L_11 , NULL ,
& V_6 ) ;
if ( V_17 < 0 )
return V_17 ;
V_17 = F_23 ( V_49 , & V_81 ,
F_6 , 0x0a , 0x02 , 0 ,
V_80 , 1 , L_12 , NULL ,
& V_6 ) ;
if ( V_17 < 0 )
return V_17 ;
for ( V_16 = 0 ; V_16 < V_76 -> V_86 ; V_16 ++ ) {
V_85 = & V_76 -> V_87 [ V_16 ] ;
switch ( V_85 -> type ) {
case V_88 :
V_17 = F_29 ( V_49 , V_85 -> V_68 , V_85 -> V_44 , V_76 ) ;
if ( V_17 < 0 )
return V_17 ;
break;
case V_89 :
sprintf ( V_77 , L_13 , V_85 -> V_68 ) ;
V_17 = F_23 ( V_49 , & V_90 ,
F_18 , 0x01 ,
0x09 , V_85 -> V_68 , V_80 , 1 , V_77 ,
& V_91 , & V_6 ) ;
if ( V_17 < 0 )
return V_17 ;
break;
case V_92 :
sprintf ( V_77 , L_14 , V_85 -> V_68 ) ;
V_17 = F_23 ( V_49 , & V_90 ,
F_18 , 0x01 ,
0x0b , V_85 -> V_68 , V_80 , 1 , V_77 ,
& V_93 , & V_6 ) ;
if ( V_17 < 0 )
return V_17 ;
break;
}
}
return 0 ;
}
int F_31 ( struct V_62 * V_49 )
{
int V_17 , V_16 , V_94 ;
char V_77 [ V_78 ] ;
struct V_75 * V_76 ;
struct V_5 * V_6 ;
static char V_95 [ 4 ] = { '\x80' , '\xbb' , '\x00' , '\x00' } ;
if ( ! V_49 -> V_96 )
return 0 ;
switch ( V_49 -> V_48 -> V_97 ) {
case F_32 ( 0x1235 , 0x8012 ) :
V_76 = & V_98 ;
break;
case F_32 ( 0x1235 , 0x8002 ) :
V_76 = & V_99 ;
break;
case F_32 ( 0x1235 , 0x8004 ) :
V_76 = & V_100 ;
break;
case F_32 ( 0x1235 , 0x8014 ) :
V_76 = & V_101 ;
break;
case F_32 ( 0x1235 , 0x800c ) :
V_76 = & V_102 ;
break;
default:
return - V_103 ;
}
V_17 = F_30 ( V_49 , V_76 ) ;
if ( V_17 < 0 )
return V_17 ;
for ( V_16 = 0 ; V_16 < V_76 -> V_104 ; V_16 ++ ) {
snprintf ( V_77 , sizeof( V_77 ) , L_15 ,
V_16 + 1 ) ;
V_17 = F_23 ( V_49 , & V_82 ,
F_18 , 0x32 ,
0x06 , V_16 , V_80 , 1 , V_77 ,
& V_76 -> V_105 , & V_6 ) ;
if ( V_17 < 0 )
return V_17 ;
for ( V_94 = 0 ; V_94 < V_76 -> V_106 ; V_94 ++ ) {
sprintf ( V_77 , L_16 , V_16 + 1 ,
V_94 + 'A' ) ;
V_17 = F_23 ( V_49 , & V_107 ,
F_6 , 0x3c , 0x00 ,
( V_16 << 3 ) + ( V_94 & 0x07 ) , V_80 ,
1 , V_77 , NULL , & V_6 ) ;
if ( V_17 < 0 )
return V_17 ;
}
}
for ( V_16 = 0 ; V_16 < V_76 -> V_108 ; V_16 ++ ) {
snprintf ( V_77 , sizeof( V_77 ) , L_17 ,
V_16 + 1 ) ;
V_17 = F_23 ( V_49 , & V_82 ,
F_18 , 0x34 ,
0x00 , V_16 , V_80 , 1 , V_77 ,
& V_76 -> V_83 , & V_6 ) ;
if ( V_17 < 0 )
return V_17 ;
}
V_17 = F_23 ( V_49 , & V_90 ,
F_18 , 0x28 , 0x01 , 0 ,
V_109 , 1 , L_18 ,
& V_110 , & V_6 ) ;
if ( V_17 < 0 )
return V_17 ;
V_17 = F_23 ( V_49 , & V_111 , NULL , 0x3c , 0x00 , 2 ,
V_109 , 1 , L_19 ,
& V_112 , & V_6 ) ;
if ( V_17 < 0 )
return V_17 ;
V_17 = F_21 ( V_49 -> V_48 -> V_57 ,
F_33 ( V_49 -> V_48 -> V_57 , 0 ) , V_113 ,
V_59 | V_60 |
V_114 , 0x0100 , F_20 ( V_49 -> V_48 ) |
( 0x29 << 8 ) , V_95 , 4 ) ;
if ( V_17 < 0 )
return V_17 ;
return V_17 ;
}
