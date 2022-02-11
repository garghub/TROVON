static inline T_1 F_1 ( unsigned long V_1 )
{
if ( ! V_1 )
return 0xffff ;
return F_2 ( 5400000 / V_1 , 1 , 0xfffe ) ;
}
static int F_3 ( long V_2 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < 15 ; ++ V_3 ) {
if ( V_2 <= ( V_4 [ V_3 ] + V_4 [ V_3 + 1 ] ) / 2 )
break;
}
return V_3 ;
}
static int F_4 ( const int * V_5 , unsigned long V_6 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < 7 ; ++ V_3 )
if ( V_6 <= ( V_5 [ V_3 ] + V_5 [ V_3 + 1 ] ) / 2 )
break;
return V_3 ;
}
static int F_5 ( const int * V_5 , T_2 V_7 )
{
return V_5 [ V_7 & 0x07 ] ;
}
static int F_6 ( int V_8 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 <= 7 ; ++ V_3 )
if ( V_8 == V_9 [ V_3 ] )
break;
if ( V_3 > 7 )
V_3 = 3 ;
return V_3 << 5 ;
}
static int F_7 ( struct V_10 * V_11 , T_2 V_7 )
{
int V_12 ;
switch ( V_7 ) {
case F_8 ( 0 ) :
case F_8 ( 1 ) :
case F_8 ( 2 ) :
case F_8 ( 3 ) :
case F_9 ( 0 ) :
case F_9 ( 1 ) :
case F_9 ( 2 ) :
case F_9 ( 3 ) :
case V_13 :
V_12 = F_10 ( V_11 , V_7 ) & 0xff ;
V_12 |= F_10 ( V_11 , V_7 + 1 ) << 8 ;
break;
default:
V_12 = F_10 ( V_11 , V_7 ) ;
break;
}
return V_12 ;
}
static void F_11 ( struct V_10 * V_11 , T_2 V_7 , int V_14 )
{
switch ( V_7 ) {
case F_8 ( 0 ) :
case F_8 ( 1 ) :
case F_8 ( 2 ) :
case F_8 ( 3 ) :
case F_9 ( 0 ) :
case F_9 ( 1 ) :
case F_9 ( 2 ) :
case F_9 ( 3 ) :
F_12 ( V_11 , V_7 , V_14 & 0xff ) ;
F_12 ( V_11 , V_7 + 1 , V_14 >> 8 ) ;
break;
default:
F_12 ( V_11 , V_7 , V_14 ) ;
break;
}
}
static struct V_15 * F_13 ( struct V_16 * V_17 )
{
struct V_15 * V_18 = F_14 ( V_17 ) ;
struct V_10 * V_11 = V_18 -> V_11 ;
int V_3 ;
F_15 ( & V_18 -> V_19 ) ;
if ( ! V_18 -> V_20 ||
F_16 ( V_21 , V_18 -> V_22 + V_23 ) ) {
F_17 ( & V_11 -> V_17 , L_1 ) ;
if ( V_18 -> type == V_24 || V_18 -> type == V_25 ||
V_18 -> type == V_26 ) {
int V_27 = F_7 ( V_11 ,
V_28 ) ;
int V_29 = F_7 ( V_11 ,
V_30 ) ;
int V_1 = ( V_27 << 8 ) + V_29 ;
for ( V_3 = 0 ; V_3 <= 4 ; V_3 ++ )
V_18 -> V_31 [ V_3 ] =
( ( V_1 >> ( V_3 * 2 ) ) & 0x03 ) << 2 ;
for ( V_3 = 0 ; V_3 <= 2 ; V_3 ++ )
V_18 -> V_32 [ V_3 ] =
( V_1 >> ( ( V_3 + 4 ) * 2 ) ) & 0x0c ;
}
V_18 -> V_33 = F_7 ( V_11 , V_34 ) ;
for ( V_3 = 0 ; V_3 <= 3 ; ++ V_3 ) {
V_18 -> V_35 [ V_3 ] =
F_7 ( V_11 , F_18 ( V_3 ) ) ;
V_18 -> V_36 [ V_3 ] =
F_7 ( V_11 , F_8 ( V_3 ) ) ;
}
if ( ! V_18 -> V_37 )
V_18 -> V_35 [ 4 ] = F_7 ( V_11 , F_18 ( 4 ) ) ;
if ( V_18 -> type == V_26 )
V_18 -> V_38 = F_7 ( V_11 , V_39 ) ;
for ( V_3 = 0 ; V_3 <= 2 ; ++ V_3 ) {
V_18 -> V_40 [ V_3 ] =
F_7 ( V_11 , F_19 ( V_3 ) ) ;
V_18 -> V_41 [ V_3 ] =
F_7 ( V_11 , F_20 ( V_3 ) ) ;
if ( F_21 ( V_18 ) )
V_18 -> V_40 [ V_3 ] -= 64 ;
}
V_18 -> V_42 = F_7 ( V_11 , V_13 ) ;
if ( V_18 -> type == V_43 ) {
for ( V_3 = 5 ; V_3 <= 7 ; ++ V_3 ) {
V_18 -> V_35 [ V_3 ] = F_7 ( V_11 ,
F_22 ( V_3 ) ) ;
}
V_18 -> V_42 |= F_7 ( V_11 ,
V_44 ) << 16 ;
} else if ( V_18 -> type == V_45 || V_18 -> type == V_46 ||
V_18 -> type == V_47 ) {
int V_27 = F_7 ( V_11 ,
V_48 ) ;
int V_29 = F_7 ( V_11 ,
V_49 ) ;
int V_50 = F_7 ( V_11 ,
V_51 ) ;
int V_52 = F_7 ( V_11 ,
V_53 ) ;
V_18 -> V_31 [ 0 ] = V_50 & 0x0f ;
V_18 -> V_31 [ 1 ] = V_52 & 0x0f ;
V_18 -> V_31 [ 2 ] = V_52 >> 4 ;
V_18 -> V_31 [ 3 ] = V_50 >> 4 ;
V_18 -> V_31 [ 4 ] = V_29 >> 4 ;
V_18 -> V_32 [ 0 ] = V_27 & 0x0f ;
V_18 -> V_32 [ 1 ] = V_29 & 0x0f ;
V_18 -> V_32 [ 2 ] = V_27 >> 4 ;
}
V_18 -> V_22 = V_21 ;
}
if ( ! V_18 -> V_20 ||
F_16 ( V_21 , V_18 -> V_54 + V_55 ) ) {
F_17 ( & V_11 -> V_17 , L_2 ) ;
for ( V_3 = 0 ; V_3 <= 3 ; ++ V_3 ) {
V_18 -> V_56 [ V_3 ] =
F_7 ( V_11 , F_23 ( V_3 ) ) ;
V_18 -> V_57 [ V_3 ] =
F_7 ( V_11 , F_24 ( V_3 ) ) ;
V_18 -> V_58 [ V_3 ] =
F_7 ( V_11 , F_9 ( V_3 ) ) ;
}
if ( ! V_18 -> V_37 ) {
V_18 -> V_56 [ 4 ] = F_7 ( V_11 ,
F_23 ( 4 ) ) ;
V_18 -> V_57 [ 4 ] = F_7 ( V_11 ,
F_24 ( 4 ) ) ;
}
if ( V_18 -> type == V_43 ) {
for ( V_3 = 5 ; V_3 <= 7 ; ++ V_3 ) {
V_18 -> V_56 [ V_3 ] = F_7 ( V_11 ,
F_25 ( V_3 ) ) ;
V_18 -> V_57 [ V_3 ] = F_7 ( V_11 ,
F_26 ( V_3 ) ) ;
}
}
for ( V_3 = 0 ; V_3 <= 2 ; ++ V_3 ) {
int V_1 ;
V_18 -> V_59 [ V_3 ] =
F_7 ( V_11 , F_27 ( V_3 ) ) ;
V_18 -> V_60 [ V_3 ] =
F_7 ( V_11 , F_28 ( V_3 ) ) ;
V_18 -> V_61 [ V_3 ] . V_62 =
F_7 ( V_11 , F_29 ( V_3 ) ) ;
V_1 = F_7 ( V_11 , F_30 ( V_3 ) ) ;
V_18 -> V_63 [ V_3 ] = V_1 & 0x07 ;
V_18 -> V_8 [ V_3 ] . V_2 = V_1 >> 4 ;
V_18 -> V_61 [ V_3 ] . V_64 =
F_7 ( V_11 , F_31 ( V_3 ) ) ;
V_18 -> V_8 [ V_3 ] . V_65 =
F_7 ( V_11 , F_32 ( V_3 ) ) ;
V_18 -> V_8 [ V_3 ] . V_66 =
F_7 ( V_11 , F_33 ( V_3 ) ) ;
if ( F_21 ( V_18 ) ) {
V_18 -> V_59 [ V_3 ] -= 64 ;
V_18 -> V_60 [ V_3 ] -= 64 ;
V_18 -> V_8 [ V_3 ] . V_65 -= 64 ;
V_18 -> V_8 [ V_3 ] . V_66 -= 64 ;
}
}
if ( V_18 -> type != V_47 ) {
V_3 = F_7 ( V_11 , V_67 ) ;
V_18 -> V_61 [ 0 ] . V_68 = ( V_3 & 0x20 ) != 0 ;
V_18 -> V_61 [ 1 ] . V_68 = ( V_3 & 0x40 ) != 0 ;
V_18 -> V_61 [ 2 ] . V_68 = ( V_3 & 0x80 ) != 0 ;
V_3 = F_7 ( V_11 , V_69 ) ;
V_18 -> V_8 [ 0 ] . V_70 = V_3 >> 4 ;
V_18 -> V_8 [ 1 ] . V_70 = V_3 & 0x0f ;
V_3 = F_7 ( V_11 , V_71 ) ;
V_18 -> V_8 [ 2 ] . V_70 = V_3 >> 4 ;
}
V_18 -> V_54 = V_21 ;
}
V_18 -> V_20 = 1 ;
F_34 ( & V_18 -> V_19 ) ;
return V_18 ;
}
static T_3 F_35 ( struct V_16 * V_17 , struct V_72 * V_73 ,
char * V_74 )
{
int V_75 = F_36 ( V_73 ) -> V_76 ;
struct V_15 * V_18 = F_13 ( V_17 ) ;
return sprintf ( V_74 , L_3 , F_37 ( V_18 -> V_36 [ V_75 ] ) ) ;
}
static T_3 F_38 ( struct V_16 * V_17 , struct V_72 * V_73 ,
char * V_74 )
{
int V_75 = F_36 ( V_73 ) -> V_76 ;
struct V_15 * V_18 = F_13 ( V_17 ) ;
return sprintf ( V_74 , L_3 , F_37 ( V_18 -> V_58 [ V_75 ] ) ) ;
}
static T_3 F_39 ( struct V_16 * V_17 , struct V_72 * V_73 ,
const char * V_74 , T_4 V_77 )
{
int V_75 = F_36 ( V_73 ) -> V_76 ;
struct V_15 * V_18 = F_14 ( V_17 ) ;
struct V_10 * V_11 = V_18 -> V_11 ;
unsigned long V_1 ;
int V_78 ;
V_78 = F_40 ( V_74 , 10 , & V_1 ) ;
if ( V_78 )
return V_78 ;
F_15 ( & V_18 -> V_19 ) ;
V_18 -> V_58 [ V_75 ] = F_1 ( V_1 ) ;
F_11 ( V_11 , F_9 ( V_75 ) , V_18 -> V_58 [ V_75 ] ) ;
F_34 ( & V_18 -> V_19 ) ;
return V_77 ;
}
static T_3 F_41 ( struct V_16 * V_17 , struct V_72 * V_73 ,
char * V_74 )
{
struct V_15 * V_18 = F_13 ( V_17 ) ;
int V_33 ;
if ( V_18 -> V_37 ) {
V_33 = F_42 ( V_18 -> V_33 & 0x3f , V_18 -> V_79 ) ;
} else {
V_33 = F_42 ( V_18 -> V_33 & 0x1f , V_18 -> V_79 ) ;
}
return sprintf ( V_74 , L_3 , V_33 ) ;
}
static T_3 F_43 ( struct V_16 * V_17 , struct V_72 * V_73 ,
char * V_74 )
{
struct V_15 * V_18 = F_14 ( V_17 ) ;
return sprintf ( V_74 , L_4 , ( long ) V_18 -> V_79 ) ;
}
static T_3 F_44 ( struct V_16 * V_17 , struct V_72 * V_73 ,
const char * V_74 , T_4 V_77 )
{
struct V_15 * V_18 = F_14 ( V_17 ) ;
unsigned long V_1 ;
int V_78 ;
V_78 = F_40 ( V_74 , 10 , & V_1 ) ;
if ( V_78 )
return V_78 ;
if ( V_1 > 255 )
return - V_80 ;
V_18 -> V_79 = V_1 ;
return V_77 ;
}
static T_3 F_45 ( struct V_16 * V_17 , struct V_72
* V_73 , char * V_74 )
{
struct V_15 * V_18 = F_13 ( V_17 ) ;
return sprintf ( V_74 , L_5 , V_18 -> V_42 ) ;
}
static T_3 F_46 ( struct V_16 * V_17 , struct V_72 * V_73 ,
char * V_74 )
{
int V_75 = F_36 ( V_73 ) -> V_76 ;
struct V_15 * V_18 = F_13 ( V_17 ) ;
return sprintf ( V_74 , L_5 , ( V_18 -> V_42 >> V_75 ) & 1 ) ;
}
static T_3 F_47 ( struct V_16 * V_17 , struct V_72 * V_73 ,
char * V_74 )
{
int V_75 = F_36 ( V_73 ) -> V_76 ;
struct V_15 * V_18 = F_13 ( V_17 ) ;
return sprintf ( V_74 , L_3 , F_48 ( V_18 -> V_41 [ V_75 ] ) ) ;
}
static T_3 F_49 ( struct V_16 * V_17 , struct V_72 * V_73 ,
const char * V_74 , T_4 V_77 )
{
int V_75 = F_36 ( V_73 ) -> V_76 ;
struct V_15 * V_18 = F_14 ( V_17 ) ;
struct V_10 * V_11 = V_18 -> V_11 ;
unsigned long V_1 ;
int V_78 ;
V_78 = F_40 ( V_74 , 10 , & V_1 ) ;
if ( V_78 )
return V_78 ;
F_15 ( & V_18 -> V_19 ) ;
V_18 -> V_41 [ V_75 ] = F_50 ( V_1 ) ;
F_11 ( V_11 , F_20 ( V_75 ) , V_18 -> V_41 [ V_75 ] ) ;
F_34 ( & V_18 -> V_19 ) ;
return V_77 ;
}
static T_3 F_51 ( struct V_16 * V_17 , struct V_72
* V_73 , char * V_74 )
{
int V_75 = F_36 ( V_73 ) -> V_76 ;
struct V_15 * V_18 = F_13 ( V_17 ) ;
int V_81 , V_82 ;
V_81 = F_52 ( V_18 -> V_61 [ V_75 ] . V_62 ) ;
switch ( V_81 ) {
case - 1 :
V_82 = 0 ;
break;
case 0 :
case - 2 :
V_82 = 1 ;
break;
default:
V_82 = 2 ;
}
return sprintf ( V_74 , L_3 , V_82 ) ;
}
static T_3 F_53 ( struct V_16 * V_17 , struct V_72
* V_73 , const char * V_74 , T_4 V_77 )
{
int V_75 = F_36 ( V_73 ) -> V_76 ;
struct V_15 * V_18 = F_14 ( V_17 ) ;
struct V_10 * V_11 = V_18 -> V_11 ;
T_2 V_62 ;
unsigned long V_1 ;
int V_78 ;
V_78 = F_40 ( V_74 , 10 , & V_1 ) ;
if ( V_78 )
return V_78 ;
switch ( V_1 ) {
case 0 :
V_62 = 3 ;
break;
case 1 :
V_62 = 7 ;
break;
case 2 :
V_62 = 6 ;
break;
default:
return - V_80 ;
}
F_15 ( & V_18 -> V_19 ) ;
V_18 -> V_61 [ V_75 ] . V_62 = F_7 ( V_11 ,
F_29 ( V_75 ) ) ;
V_18 -> V_61 [ V_75 ] . V_62 = ( V_18 -> V_61 [ V_75 ] . V_62 & ~ 0xe0 )
| ( V_62 << 5 ) ;
F_11 ( V_11 , F_29 ( V_75 ) ,
V_18 -> V_61 [ V_75 ] . V_62 ) ;
F_34 ( & V_18 -> V_19 ) ;
return V_77 ;
}
static T_3 F_54 ( struct V_16 * V_17 ,
struct V_72 * V_73 , char * V_74 )
{
int V_75 = F_36 ( V_73 ) -> V_76 ;
struct V_15 * V_18 = F_13 ( V_17 ) ;
int V_6 ;
if ( F_55 ( V_18 ) )
V_6 = 22500 ;
else
V_6 = F_5 ( V_18 -> V_83 , V_18 -> V_63 [ V_75 ] ) ;
return sprintf ( V_74 , L_3 , V_6 ) ;
}
static T_3 F_56 ( struct V_16 * V_17 ,
struct V_72 * V_73 , const char * V_74 , T_4 V_77 )
{
int V_75 = F_36 ( V_73 ) -> V_76 ;
struct V_15 * V_18 = F_14 ( V_17 ) ;
struct V_10 * V_11 = V_18 -> V_11 ;
unsigned long V_1 ;
int V_78 ;
V_78 = F_40 ( V_74 , 10 , & V_1 ) ;
if ( V_78 )
return V_78 ;
F_15 ( & V_18 -> V_19 ) ;
if ( V_18 -> type == V_26 && V_1 >= 11300 ) {
V_18 -> V_38 &= ~ V_84 ;
F_11 ( V_11 , V_39 , V_18 -> V_38 ) ;
} else {
V_18 -> V_63 [ V_75 ] = F_4 ( V_18 -> V_83 , V_1 ) ;
F_11 ( V_11 , F_30 ( V_75 ) ,
( V_18 -> V_8 [ V_75 ] . V_2 << 4 )
| V_18 -> V_63 [ V_75 ] ) ;
if ( V_18 -> type == V_26 ) {
V_18 -> V_38 |= V_84 ;
F_11 ( V_11 , V_39 , V_18 -> V_38 ) ;
}
}
F_34 ( & V_18 -> V_19 ) ;
return V_77 ;
}
static T_3 F_57 ( struct V_16 * V_17 , struct V_72 * V_73 ,
char * V_74 )
{
int V_75 = F_36 ( V_73 ) -> V_76 ;
struct V_15 * V_18 = F_13 ( V_17 ) ;
return sprintf ( V_74 , L_3 , F_58 ( V_75 , V_18 -> V_35 [ V_75 ] ,
V_18 -> V_31 [ V_75 ] ) ) ;
}
static T_3 F_59 ( struct V_16 * V_17 , struct V_72 * V_73 ,
char * V_74 )
{
int V_75 = F_36 ( V_73 ) -> V_76 ;
struct V_15 * V_18 = F_13 ( V_17 ) ;
return sprintf ( V_74 , L_3 , F_60 ( V_75 , V_18 -> V_56 [ V_75 ] ) ) ;
}
static T_3 F_61 ( struct V_16 * V_17 , struct V_72 * V_73 ,
const char * V_74 , T_4 V_77 )
{
int V_75 = F_36 ( V_73 ) -> V_76 ;
struct V_15 * V_18 = F_14 ( V_17 ) ;
struct V_10 * V_11 = V_18 -> V_11 ;
long V_1 ;
int V_78 ;
V_78 = F_62 ( V_74 , 10 , & V_1 ) ;
if ( V_78 )
return V_78 ;
F_15 ( & V_18 -> V_19 ) ;
V_18 -> V_56 [ V_75 ] = F_63 ( V_75 , V_1 ) ;
F_11 ( V_11 , F_23 ( V_75 ) , V_18 -> V_56 [ V_75 ] ) ;
F_34 ( & V_18 -> V_19 ) ;
return V_77 ;
}
static T_3 F_64 ( struct V_16 * V_17 , struct V_72 * V_73 ,
char * V_74 )
{
int V_75 = F_36 ( V_73 ) -> V_76 ;
struct V_15 * V_18 = F_13 ( V_17 ) ;
return sprintf ( V_74 , L_3 , F_60 ( V_75 , V_18 -> V_57 [ V_75 ] ) ) ;
}
static T_3 F_65 ( struct V_16 * V_17 , struct V_72 * V_73 ,
const char * V_74 , T_4 V_77 )
{
int V_75 = F_36 ( V_73 ) -> V_76 ;
struct V_15 * V_18 = F_14 ( V_17 ) ;
struct V_10 * V_11 = V_18 -> V_11 ;
long V_1 ;
int V_78 ;
V_78 = F_62 ( V_74 , 10 , & V_1 ) ;
if ( V_78 )
return V_78 ;
F_15 ( & V_18 -> V_19 ) ;
V_18 -> V_57 [ V_75 ] = F_63 ( V_75 , V_1 ) ;
F_11 ( V_11 , F_24 ( V_75 ) , V_18 -> V_57 [ V_75 ] ) ;
F_34 ( & V_18 -> V_19 ) ;
return V_77 ;
}
static T_3 F_66 ( struct V_16 * V_17 , struct V_72 * V_73 ,
char * V_74 )
{
int V_75 = F_36 ( V_73 ) -> V_76 ;
struct V_15 * V_18 = F_13 ( V_17 ) ;
return sprintf ( V_74 , L_3 , F_67 ( V_18 -> V_40 [ V_75 ] ,
V_18 -> V_32 [ V_75 ] ) ) ;
}
static T_3 F_68 ( struct V_16 * V_17 , struct V_72 * V_73 ,
char * V_74 )
{
int V_75 = F_36 ( V_73 ) -> V_76 ;
struct V_15 * V_18 = F_13 ( V_17 ) ;
return sprintf ( V_74 , L_3 , F_69 ( V_18 -> V_59 [ V_75 ] ) ) ;
}
static T_3 F_70 ( struct V_16 * V_17 , struct V_72 * V_73 ,
const char * V_74 , T_4 V_77 )
{
int V_75 = F_36 ( V_73 ) -> V_76 ;
struct V_15 * V_18 = F_14 ( V_17 ) ;
struct V_10 * V_11 = V_18 -> V_11 ;
long V_1 ;
int V_78 ;
V_78 = F_62 ( V_74 , 10 , & V_1 ) ;
if ( V_78 )
return V_78 ;
if ( F_21 ( V_18 ) )
V_1 += 64 ;
F_15 ( & V_18 -> V_19 ) ;
V_18 -> V_59 [ V_75 ] = F_71 ( V_1 ) ;
F_11 ( V_11 , F_27 ( V_75 ) , V_18 -> V_59 [ V_75 ] ) ;
F_34 ( & V_18 -> V_19 ) ;
return V_77 ;
}
static T_3 F_72 ( struct V_16 * V_17 , struct V_72 * V_73 ,
char * V_74 )
{
int V_75 = F_36 ( V_73 ) -> V_76 ;
struct V_15 * V_18 = F_13 ( V_17 ) ;
return sprintf ( V_74 , L_3 , F_69 ( V_18 -> V_60 [ V_75 ] ) ) ;
}
static T_3 F_73 ( struct V_16 * V_17 , struct V_72 * V_73 ,
const char * V_74 , T_4 V_77 )
{
int V_75 = F_36 ( V_73 ) -> V_76 ;
struct V_15 * V_18 = F_14 ( V_17 ) ;
struct V_10 * V_11 = V_18 -> V_11 ;
long V_1 ;
int V_78 ;
V_78 = F_62 ( V_74 , 10 , & V_1 ) ;
if ( V_78 )
return V_78 ;
if ( F_21 ( V_18 ) )
V_1 += 64 ;
F_15 ( & V_18 -> V_19 ) ;
V_18 -> V_60 [ V_75 ] = F_71 ( V_1 ) ;
F_11 ( V_11 , F_28 ( V_75 ) , V_18 -> V_60 [ V_75 ] ) ;
F_34 ( & V_18 -> V_19 ) ;
return V_77 ;
}
static T_3 F_74 ( struct V_16 * V_17 ,
struct V_72 * V_73 , char * V_74 )
{
int V_75 = F_36 ( V_73 ) -> V_76 ;
struct V_15 * V_18 = F_13 ( V_17 ) ;
return sprintf ( V_74 , L_3 , F_52 ( V_18 -> V_61 [ V_75 ] . V_62 ) ) ;
}
static T_3 F_75 ( struct V_16 * V_17 ,
struct V_72 * V_73 , const char * V_74 , T_4 V_77 )
{
int V_75 = F_36 ( V_73 ) -> V_76 ;
struct V_15 * V_18 = F_14 ( V_17 ) ;
struct V_10 * V_11 = V_18 -> V_11 ;
long V_1 ;
int V_78 ;
V_78 = F_62 ( V_74 , 10 , & V_1 ) ;
if ( V_78 )
return V_78 ;
F_15 ( & V_18 -> V_19 ) ;
V_18 -> V_61 [ V_75 ] . V_62 = ( V_18 -> V_61 [ V_75 ] . V_62 & ( ~ 0xe0 ) )
| F_6 ( V_1 ) ;
F_11 ( V_11 , F_29 ( V_75 ) ,
V_18 -> V_61 [ V_75 ] . V_62 ) ;
F_34 ( & V_18 -> V_19 ) ;
return V_77 ;
}
static T_3 F_76 ( struct V_16 * V_17 ,
struct V_72 * V_73 , char * V_74 )
{
int V_75 = F_36 ( V_73 ) -> V_76 ;
struct V_15 * V_18 = F_13 ( V_17 ) ;
return sprintf ( V_74 , L_3 , F_48 ( V_18 -> V_61 [ V_75 ] . V_64 ) ) ;
}
static T_3 F_77 ( struct V_16 * V_17 ,
struct V_72 * V_73 , const char * V_74 , T_4 V_77 )
{
int V_75 = F_36 ( V_73 ) -> V_76 ;
struct V_15 * V_18 = F_14 ( V_17 ) ;
struct V_10 * V_11 = V_18 -> V_11 ;
unsigned long V_1 ;
int V_78 ;
V_78 = F_40 ( V_74 , 10 , & V_1 ) ;
if ( V_78 )
return V_78 ;
F_15 ( & V_18 -> V_19 ) ;
V_18 -> V_61 [ V_75 ] . V_64 = F_50 ( V_1 ) ;
F_11 ( V_11 , F_31 ( V_75 ) ,
V_18 -> V_61 [ V_75 ] . V_64 ) ;
F_34 ( & V_18 -> V_19 ) ;
return V_77 ;
}
static T_3 F_78 ( struct V_16 * V_17 ,
struct V_72 * V_73 , char * V_74 )
{
int V_75 = F_36 ( V_73 ) -> V_76 ;
struct V_15 * V_18 = F_13 ( V_17 ) ;
return sprintf ( V_74 , L_3 , V_18 -> V_61 [ V_75 ] . V_68 ) ;
}
static T_3 F_79 ( struct V_16 * V_17 ,
struct V_72 * V_73 , const char * V_74 , T_4 V_77 )
{
int V_75 = F_36 ( V_73 ) -> V_76 ;
struct V_15 * V_18 = F_14 ( V_17 ) ;
struct V_10 * V_11 = V_18 -> V_11 ;
T_2 V_85 ;
long V_1 ;
int V_78 ;
V_78 = F_62 ( V_74 , 10 , & V_1 ) ;
if ( V_78 )
return V_78 ;
F_15 ( & V_18 -> V_19 ) ;
V_18 -> V_61 [ V_75 ] . V_68 = V_1 ;
V_85 = F_7 ( V_11 , V_67 ) ;
V_85 &= ~ ( 0x20 << V_75 ) ;
if ( V_18 -> V_61 [ V_75 ] . V_68 )
V_85 |= 0x20 << V_75 ;
F_11 ( V_11 , V_67 , V_85 ) ;
F_34 ( & V_18 -> V_19 ) ;
return V_77 ;
}
static T_3 F_80 ( struct V_16 * V_17 ,
struct V_72 * V_73 , char * V_74 )
{
int V_75 = F_36 ( V_73 ) -> V_76 ;
struct V_15 * V_18 = F_13 ( V_17 ) ;
return sprintf ( V_74 , L_3 , F_69 ( V_18 -> V_8 [ V_75 ] . V_65 ) -
F_81 ( V_18 -> V_8 [ V_75 ] . V_70 ) ) ;
}
static T_3 F_82 ( struct V_16 * V_17 ,
struct V_72 * V_73 , const char * V_74 , T_4 V_77 )
{
int V_75 = F_36 ( V_73 ) -> V_76 ;
struct V_15 * V_18 = F_14 ( V_17 ) ;
struct V_10 * V_11 = V_18 -> V_11 ;
int V_86 ;
long V_1 ;
int V_78 ;
V_78 = F_62 ( V_74 , 10 , & V_1 ) ;
if ( V_78 )
return V_78 ;
F_15 ( & V_18 -> V_19 ) ;
V_86 = F_69 ( V_18 -> V_8 [ V_75 ] . V_65 ) ;
V_18 -> V_8 [ V_75 ] . V_70 = F_83 ( V_86 - V_1 ) ;
if ( V_75 == 0 || V_75 == 1 ) {
F_11 ( V_11 , V_69 ,
( V_18 -> V_8 [ 0 ] . V_70 << 4 )
| V_18 -> V_8 [ 1 ] . V_70 ) ;
} else {
F_11 ( V_11 , V_71 ,
( V_18 -> V_8 [ 2 ] . V_70 << 4 ) ) ;
}
F_34 ( & V_18 -> V_19 ) ;
return V_77 ;
}
static T_3 F_84 ( struct V_16 * V_17 ,
struct V_72 * V_73 , char * V_74 )
{
int V_75 = F_36 ( V_73 ) -> V_76 ;
struct V_15 * V_18 = F_13 ( V_17 ) ;
return sprintf ( V_74 , L_3 , F_69 ( V_18 -> V_8 [ V_75 ] . V_65 ) ) ;
}
static T_3 F_85 ( struct V_16 * V_17 ,
struct V_72 * V_73 , const char * V_74 , T_4 V_77 )
{
int V_75 = F_36 ( V_73 ) -> V_76 ;
struct V_15 * V_18 = F_14 ( V_17 ) ;
struct V_10 * V_11 = V_18 -> V_11 ;
long V_1 ;
int V_78 ;
V_78 = F_62 ( V_74 , 10 , & V_1 ) ;
if ( V_78 )
return V_78 ;
F_15 ( & V_18 -> V_19 ) ;
V_18 -> V_8 [ V_75 ] . V_65 = F_71 ( V_1 ) ;
F_11 ( V_11 , F_32 ( V_75 ) ,
V_18 -> V_8 [ V_75 ] . V_65 ) ;
V_18 -> V_8 [ V_75 ] . V_2 = F_3 (
F_69 ( V_18 -> V_8 [ V_75 ] . V_87 ) -
F_69 ( V_18 -> V_8 [ V_75 ] . V_65 ) ) ;
F_11 ( V_11 , F_30 ( V_75 ) ,
( ( V_18 -> V_8 [ V_75 ] . V_2 & 0x0f ) << 4 )
| ( V_18 -> V_63 [ V_75 ] & 0x07 ) ) ;
F_34 ( & V_18 -> V_19 ) ;
return V_77 ;
}
static T_3 F_86 ( struct V_16 * V_17 ,
struct V_72 * V_73 , char * V_74 )
{
int V_75 = F_36 ( V_73 ) -> V_76 ;
struct V_15 * V_18 = F_13 ( V_17 ) ;
return sprintf ( V_74 , L_3 , F_69 ( V_18 -> V_8 [ V_75 ] . V_65 ) +
F_87 ( V_18 -> V_8 [ V_75 ] . V_2 ) ) ;
}
static T_3 F_88 ( struct V_16 * V_17 ,
struct V_72 * V_73 , const char * V_74 , T_4 V_77 )
{
int V_75 = F_36 ( V_73 ) -> V_76 ;
struct V_15 * V_18 = F_14 ( V_17 ) ;
struct V_10 * V_11 = V_18 -> V_11 ;
int V_86 ;
long V_1 ;
int V_78 ;
V_78 = F_62 ( V_74 , 10 , & V_1 ) ;
if ( V_78 )
return V_78 ;
F_15 ( & V_18 -> V_19 ) ;
V_86 = F_69 ( V_18 -> V_8 [ V_75 ] . V_65 ) ;
V_18 -> V_8 [ V_75 ] . V_87 = F_71 ( V_1 ) ;
V_18 -> V_8 [ V_75 ] . V_2 = F_3 (
V_1 - V_86 ) ;
F_11 ( V_11 , F_30 ( V_75 ) ,
( ( V_18 -> V_8 [ V_75 ] . V_2 & 0x0f ) << 4 )
| ( V_18 -> V_63 [ V_75 ] & 0x07 ) ) ;
F_34 ( & V_18 -> V_19 ) ;
return V_77 ;
}
static T_3 F_89 ( struct V_16 * V_17 ,
struct V_72 * V_73 , char * V_74 )
{
int V_75 = F_36 ( V_73 ) -> V_76 ;
struct V_15 * V_18 = F_13 ( V_17 ) ;
return sprintf ( V_74 , L_3 , F_69 ( V_18 -> V_8 [ V_75 ] . V_66 ) ) ;
}
static T_3 F_90 ( struct V_16 * V_17 ,
struct V_72 * V_73 , const char * V_74 , T_4 V_77 )
{
int V_75 = F_36 ( V_73 ) -> V_76 ;
struct V_15 * V_18 = F_14 ( V_17 ) ;
struct V_10 * V_11 = V_18 -> V_11 ;
long V_1 ;
int V_78 ;
V_78 = F_62 ( V_74 , 10 , & V_1 ) ;
if ( V_78 )
return V_78 ;
F_15 ( & V_18 -> V_19 ) ;
V_18 -> V_8 [ V_75 ] . V_66 = F_71 ( V_1 ) ;
F_11 ( V_11 , F_33 ( V_75 ) ,
V_18 -> V_8 [ V_75 ] . V_66 ) ;
F_34 ( & V_18 -> V_19 ) ;
return V_77 ;
}
static void F_91 ( struct V_10 * V_11 )
{
int V_14 ;
V_14 = F_7 ( V_11 , V_88 ) ;
if ( ! ( V_14 & 0x01 ) ) {
F_92 ( & V_11 -> V_17 , L_6 ) ;
F_11 ( V_11 , V_88 , V_14 | 0x01 ) ;
}
if ( V_14 & 0x02 )
F_93 ( & V_11 -> V_17 , L_7 ) ;
if ( ! ( V_14 & 0x04 ) )
F_93 ( & V_11 -> V_17 , L_8 ) ;
}
static int F_94 ( struct V_10 * V_11 )
{
int V_3 ;
T_2 V_89 , V_36 ;
for ( V_3 = 0 ; V_3 < 8 ; V_3 ++ ) {
V_89 = F_10 ( V_11 , 0x20 + V_3 ) ;
V_36 = F_10 ( V_11 , 0x28 + V_3 ) ;
if ( V_89 != 0x00 || V_36 != 0xff )
return 0 ;
}
return 1 ;
}
static int F_95 ( struct V_10 * V_11 , struct V_90 * V_91 )
{
struct V_92 * V_93 = V_11 -> V_93 ;
int V_94 = V_11 -> V_95 ;
const char * V_96 = NULL ;
int V_97 , V_98 ;
if ( ! F_96 ( V_93 , V_99 ) ) {
return - V_100 ;
}
V_97 = F_7 ( V_11 , V_101 ) ;
V_98 = F_7 ( V_11 , V_102 ) ;
F_17 ( & V_93 -> V_17 ,
L_9 ,
V_94 , V_97 , V_98 ) ;
if ( V_97 == V_103 ) {
switch ( V_98 ) {
case V_104 :
V_96 = L_10 ;
break;
case V_105 :
V_96 = L_11 ;
break;
case V_106 :
case V_107 :
if ( F_94 ( V_11 ) ) {
F_17 ( & V_93 -> V_17 ,
L_12 ) ;
return - V_100 ;
}
V_96 = L_13 ;
break;
}
} else if ( V_97 == V_108 ) {
switch ( V_98 ) {
case V_109 :
V_96 = L_14 ;
break;
case V_110 :
case V_111 :
V_96 = L_15 ;
break;
case V_112 :
case V_113 :
V_96 = L_16 ;
break;
}
} else if ( V_97 == V_114 ) {
switch ( V_98 ) {
case V_115 :
case V_116 :
V_96 = L_17 ;
break;
case V_117 :
V_96 = L_18 ;
break;
case V_118 :
case V_119 :
V_96 = L_19 ;
break;
case V_120 :
V_96 = L_20 ;
break;
}
}
if ( ! V_96 )
return - V_100 ;
F_97 ( V_91 -> type , V_96 , V_121 ) ;
return 0 ;
}
static int F_98 ( struct V_10 * V_11 , const struct V_122 * V_123 )
{
struct V_16 * V_17 = & V_11 -> V_17 ;
struct V_16 * V_124 ;
struct V_15 * V_18 ;
int V_125 = 0 ;
V_18 = F_99 ( V_17 , sizeof( struct V_15 ) , V_126 ) ;
if ( ! V_18 )
return - V_127 ;
V_18 -> V_11 = V_11 ;
V_18 -> type = V_123 -> V_128 ;
F_100 ( & V_18 -> V_19 ) ;
switch ( V_18 -> type ) {
case V_24 :
case V_25 :
case V_26 :
case V_43 :
case V_45 :
case V_46 :
case V_47 :
V_18 -> V_83 = V_129 ;
break;
default:
V_18 -> V_83 = V_130 ;
}
V_18 -> V_79 = F_101 () ;
F_91 ( V_11 ) ;
V_18 -> V_131 [ V_125 ++ ] = & V_132 ;
if ( V_18 -> type != V_47 ) {
V_18 -> V_131 [ V_125 ++ ] = & V_133 ;
V_18 -> V_131 [ V_125 ++ ] = & V_134 ;
}
if ( V_18 -> type == V_25 || V_18 -> type == V_26 ) {
T_2 V_33 = F_7 ( V_11 , V_34 ) ;
if ( V_33 & 0x80 )
V_18 -> V_37 = true ;
}
if ( ! V_18 -> V_37 )
V_18 -> V_131 [ V_125 ++ ] = & V_135 ;
if ( V_18 -> type == V_43 )
V_18 -> V_131 [ V_125 ++ ] = & V_136 ;
V_124 = F_102 ( V_17 , V_11 -> V_137 ,
V_18 , V_18 -> V_131 ) ;
return F_103 ( V_124 ) ;
}
