static inline T_1 F_1 ( unsigned long V_1 )
{
if ( ! V_1 )
return 0xffff ;
return F_2 ( 5400000 / V_1 , 1 , 0xfffe ) ;
}
static int F_3 ( long V_2 )
{
return F_4 ( V_2 , V_3 , F_5 ( V_3 ) ) ;
}
static int F_6 ( const int * V_4 ,
unsigned int V_5 , unsigned long V_6 )
{
return F_4 ( V_6 , V_4 , V_5 ) ;
}
static int F_7 ( const int * V_4 , T_2 V_7 )
{
return V_4 [ V_7 & 0x07 ] ;
}
static int F_8 ( int V_8 )
{
int V_9 ;
for ( V_9 = 0 ; V_9 <= 7 ; ++ V_9 )
if ( V_8 == V_10 [ V_9 ] )
break;
if ( V_9 > 7 )
V_9 = 3 ;
return V_9 << 5 ;
}
static int F_9 ( struct V_11 * V_12 , T_2 V_7 )
{
int V_13 ;
switch ( V_7 ) {
case F_10 ( 0 ) :
case F_10 ( 1 ) :
case F_10 ( 2 ) :
case F_10 ( 3 ) :
case F_11 ( 0 ) :
case F_11 ( 1 ) :
case F_11 ( 2 ) :
case F_11 ( 3 ) :
case V_14 :
V_13 = F_12 ( V_12 , V_7 ) & 0xff ;
V_13 |= F_12 ( V_12 , V_7 + 1 ) << 8 ;
break;
default:
V_13 = F_12 ( V_12 , V_7 ) ;
break;
}
return V_13 ;
}
static void F_13 ( struct V_11 * V_12 , T_2 V_7 , int V_15 )
{
switch ( V_7 ) {
case F_10 ( 0 ) :
case F_10 ( 1 ) :
case F_10 ( 2 ) :
case F_10 ( 3 ) :
case F_11 ( 0 ) :
case F_11 ( 1 ) :
case F_11 ( 2 ) :
case F_11 ( 3 ) :
F_14 ( V_12 , V_7 , V_15 & 0xff ) ;
F_14 ( V_12 , V_7 + 1 , V_15 >> 8 ) ;
break;
default:
F_14 ( V_12 , V_7 , V_15 ) ;
break;
}
}
static struct V_16 * F_15 ( struct V_17 * V_18 )
{
struct V_16 * V_19 = F_16 ( V_18 ) ;
struct V_11 * V_12 = V_19 -> V_12 ;
int V_9 ;
F_17 ( & V_19 -> V_20 ) ;
if ( ! V_19 -> V_21 ||
F_18 ( V_22 , V_19 -> V_23 + V_24 ) ) {
F_19 ( & V_12 -> V_18 , L_1 ) ;
if ( V_19 -> type == V_25 || V_19 -> type == V_26 ||
V_19 -> type == V_27 ) {
int V_28 = F_9 ( V_12 ,
V_29 ) ;
int V_30 = F_9 ( V_12 ,
V_31 ) ;
int V_1 = ( V_28 << 8 ) + V_30 ;
for ( V_9 = 0 ; V_9 <= 4 ; V_9 ++ )
V_19 -> V_32 [ V_9 ] =
( ( V_1 >> ( V_9 * 2 ) ) & 0x03 ) << 2 ;
for ( V_9 = 0 ; V_9 <= 2 ; V_9 ++ )
V_19 -> V_33 [ V_9 ] =
( V_1 >> ( ( V_9 + 4 ) * 2 ) ) & 0x0c ;
}
V_19 -> V_34 = F_9 ( V_12 , V_35 ) ;
for ( V_9 = 0 ; V_9 <= 3 ; ++ V_9 ) {
V_19 -> V_36 [ V_9 ] =
F_9 ( V_12 , F_20 ( V_9 ) ) ;
V_19 -> V_37 [ V_9 ] =
F_9 ( V_12 , F_10 ( V_9 ) ) ;
}
if ( ! V_19 -> V_38 )
V_19 -> V_36 [ 4 ] = F_9 ( V_12 , F_20 ( 4 ) ) ;
if ( V_19 -> type == V_27 )
V_19 -> V_39 = F_9 ( V_12 , V_40 ) ;
for ( V_9 = 0 ; V_9 <= 2 ; ++ V_9 ) {
V_19 -> V_41 [ V_9 ] =
F_9 ( V_12 , F_21 ( V_9 ) ) ;
V_19 -> V_42 [ V_9 ] =
F_9 ( V_12 , F_22 ( V_9 ) ) ;
if ( F_23 ( V_19 ) )
V_19 -> V_41 [ V_9 ] -= 64 ;
}
V_19 -> V_43 = F_9 ( V_12 , V_14 ) ;
if ( V_19 -> type == V_44 ) {
for ( V_9 = 5 ; V_9 <= 7 ; ++ V_9 ) {
V_19 -> V_36 [ V_9 ] = F_9 ( V_12 ,
F_24 ( V_9 ) ) ;
}
V_19 -> V_43 |= F_9 ( V_12 ,
V_45 ) << 16 ;
} else if ( V_19 -> type == V_46 || V_19 -> type == V_47 ||
V_19 -> type == V_48 ) {
int V_28 = F_9 ( V_12 ,
V_49 ) ;
int V_30 = F_9 ( V_12 ,
V_50 ) ;
int V_51 = F_9 ( V_12 ,
V_52 ) ;
int V_53 = F_9 ( V_12 ,
V_54 ) ;
V_19 -> V_32 [ 0 ] = V_51 & 0x0f ;
V_19 -> V_32 [ 1 ] = V_53 & 0x0f ;
V_19 -> V_32 [ 2 ] = V_53 >> 4 ;
V_19 -> V_32 [ 3 ] = V_51 >> 4 ;
V_19 -> V_32 [ 4 ] = V_30 >> 4 ;
V_19 -> V_33 [ 0 ] = V_28 & 0x0f ;
V_19 -> V_33 [ 1 ] = V_30 & 0x0f ;
V_19 -> V_33 [ 2 ] = V_28 >> 4 ;
}
V_19 -> V_23 = V_22 ;
}
if ( ! V_19 -> V_21 ||
F_18 ( V_22 , V_19 -> V_55 + V_56 ) ) {
F_19 ( & V_12 -> V_18 , L_2 ) ;
for ( V_9 = 0 ; V_9 <= 3 ; ++ V_9 ) {
V_19 -> V_57 [ V_9 ] =
F_9 ( V_12 , F_25 ( V_9 ) ) ;
V_19 -> V_58 [ V_9 ] =
F_9 ( V_12 , F_26 ( V_9 ) ) ;
V_19 -> V_59 [ V_9 ] =
F_9 ( V_12 , F_11 ( V_9 ) ) ;
}
if ( ! V_19 -> V_38 ) {
V_19 -> V_57 [ 4 ] = F_9 ( V_12 ,
F_25 ( 4 ) ) ;
V_19 -> V_58 [ 4 ] = F_9 ( V_12 ,
F_26 ( 4 ) ) ;
}
if ( V_19 -> type == V_44 ) {
for ( V_9 = 5 ; V_9 <= 7 ; ++ V_9 ) {
V_19 -> V_57 [ V_9 ] = F_9 ( V_12 ,
F_27 ( V_9 ) ) ;
V_19 -> V_58 [ V_9 ] = F_9 ( V_12 ,
F_28 ( V_9 ) ) ;
}
}
for ( V_9 = 0 ; V_9 <= 2 ; ++ V_9 ) {
int V_1 ;
V_19 -> V_60 [ V_9 ] =
F_9 ( V_12 , F_29 ( V_9 ) ) ;
V_19 -> V_61 [ V_9 ] =
F_9 ( V_12 , F_30 ( V_9 ) ) ;
V_19 -> V_62 [ V_9 ] . V_63 =
F_9 ( V_12 , F_31 ( V_9 ) ) ;
V_1 = F_9 ( V_12 , F_32 ( V_9 ) ) ;
V_19 -> V_64 [ V_9 ] = V_1 & 0x07 ;
V_19 -> V_8 [ V_9 ] . V_2 = V_1 >> 4 ;
V_19 -> V_62 [ V_9 ] . V_65 =
F_9 ( V_12 , F_33 ( V_9 ) ) ;
V_19 -> V_8 [ V_9 ] . V_66 =
F_9 ( V_12 , F_34 ( V_9 ) ) ;
V_19 -> V_8 [ V_9 ] . V_67 =
F_9 ( V_12 , F_35 ( V_9 ) ) ;
if ( F_23 ( V_19 ) ) {
V_19 -> V_60 [ V_9 ] -= 64 ;
V_19 -> V_61 [ V_9 ] -= 64 ;
V_19 -> V_8 [ V_9 ] . V_66 -= 64 ;
V_19 -> V_8 [ V_9 ] . V_67 -= 64 ;
}
}
if ( V_19 -> type != V_48 ) {
V_9 = F_9 ( V_12 , V_68 ) ;
V_19 -> V_62 [ 0 ] . V_69 = ( V_9 & 0x20 ) != 0 ;
V_19 -> V_62 [ 1 ] . V_69 = ( V_9 & 0x40 ) != 0 ;
V_19 -> V_62 [ 2 ] . V_69 = ( V_9 & 0x80 ) != 0 ;
V_9 = F_9 ( V_12 , V_70 ) ;
V_19 -> V_8 [ 0 ] . V_71 = V_9 >> 4 ;
V_19 -> V_8 [ 1 ] . V_71 = V_9 & 0x0f ;
V_9 = F_9 ( V_12 , V_72 ) ;
V_19 -> V_8 [ 2 ] . V_71 = V_9 >> 4 ;
}
V_19 -> V_55 = V_22 ;
}
V_19 -> V_21 = 1 ;
F_36 ( & V_19 -> V_20 ) ;
return V_19 ;
}
static T_3 F_37 ( struct V_17 * V_18 , struct V_73 * V_74 ,
char * V_75 )
{
int V_76 = F_38 ( V_74 ) -> V_77 ;
struct V_16 * V_19 = F_15 ( V_18 ) ;
return sprintf ( V_75 , L_3 , F_39 ( V_19 -> V_37 [ V_76 ] ) ) ;
}
static T_3 F_40 ( struct V_17 * V_18 , struct V_73 * V_74 ,
char * V_75 )
{
int V_76 = F_38 ( V_74 ) -> V_77 ;
struct V_16 * V_19 = F_15 ( V_18 ) ;
return sprintf ( V_75 , L_3 , F_39 ( V_19 -> V_59 [ V_76 ] ) ) ;
}
static T_3 F_41 ( struct V_17 * V_18 , struct V_73 * V_74 ,
const char * V_75 , T_4 V_78 )
{
int V_76 = F_38 ( V_74 ) -> V_77 ;
struct V_16 * V_19 = F_16 ( V_18 ) ;
struct V_11 * V_12 = V_19 -> V_12 ;
unsigned long V_1 ;
int V_79 ;
V_79 = F_42 ( V_75 , 10 , & V_1 ) ;
if ( V_79 )
return V_79 ;
F_17 ( & V_19 -> V_20 ) ;
V_19 -> V_59 [ V_76 ] = F_1 ( V_1 ) ;
F_13 ( V_12 , F_11 ( V_76 ) , V_19 -> V_59 [ V_76 ] ) ;
F_36 ( & V_19 -> V_20 ) ;
return V_78 ;
}
static T_3 F_43 ( struct V_17 * V_18 , struct V_73 * V_74 ,
char * V_75 )
{
struct V_16 * V_19 = F_15 ( V_18 ) ;
int V_34 ;
if ( V_19 -> V_38 ) {
V_34 = F_44 ( V_19 -> V_34 & 0x3f , V_19 -> V_80 ) ;
} else {
V_34 = F_44 ( V_19 -> V_34 & 0x1f , V_19 -> V_80 ) ;
}
return sprintf ( V_75 , L_3 , V_34 ) ;
}
static T_3 F_45 ( struct V_17 * V_18 , struct V_73 * V_74 ,
char * V_75 )
{
struct V_16 * V_19 = F_16 ( V_18 ) ;
return sprintf ( V_75 , L_4 , ( long ) V_19 -> V_80 ) ;
}
static T_3 F_46 ( struct V_17 * V_18 , struct V_73 * V_74 ,
const char * V_75 , T_4 V_78 )
{
struct V_16 * V_19 = F_16 ( V_18 ) ;
unsigned long V_1 ;
int V_79 ;
V_79 = F_42 ( V_75 , 10 , & V_1 ) ;
if ( V_79 )
return V_79 ;
if ( V_1 > 255 )
return - V_81 ;
V_19 -> V_80 = V_1 ;
return V_78 ;
}
static T_3 F_47 ( struct V_17 * V_18 , struct V_73
* V_74 , char * V_75 )
{
struct V_16 * V_19 = F_15 ( V_18 ) ;
return sprintf ( V_75 , L_5 , V_19 -> V_43 ) ;
}
static T_3 F_48 ( struct V_17 * V_18 , struct V_73 * V_74 ,
char * V_75 )
{
int V_76 = F_38 ( V_74 ) -> V_77 ;
struct V_16 * V_19 = F_15 ( V_18 ) ;
return sprintf ( V_75 , L_5 , ( V_19 -> V_43 >> V_76 ) & 1 ) ;
}
static T_3 F_49 ( struct V_17 * V_18 , struct V_73 * V_74 ,
char * V_75 )
{
int V_76 = F_38 ( V_74 ) -> V_77 ;
struct V_16 * V_19 = F_15 ( V_18 ) ;
return sprintf ( V_75 , L_3 , F_50 ( V_19 -> V_42 [ V_76 ] ) ) ;
}
static T_3 F_51 ( struct V_17 * V_18 , struct V_73 * V_74 ,
const char * V_75 , T_4 V_78 )
{
int V_76 = F_38 ( V_74 ) -> V_77 ;
struct V_16 * V_19 = F_16 ( V_18 ) ;
struct V_11 * V_12 = V_19 -> V_12 ;
unsigned long V_1 ;
int V_79 ;
V_79 = F_42 ( V_75 , 10 , & V_1 ) ;
if ( V_79 )
return V_79 ;
F_17 ( & V_19 -> V_20 ) ;
V_19 -> V_42 [ V_76 ] = F_52 ( V_1 ) ;
F_13 ( V_12 , F_22 ( V_76 ) , V_19 -> V_42 [ V_76 ] ) ;
F_36 ( & V_19 -> V_20 ) ;
return V_78 ;
}
static T_3 F_53 ( struct V_17 * V_18 , struct V_73
* V_74 , char * V_75 )
{
int V_76 = F_38 ( V_74 ) -> V_77 ;
struct V_16 * V_19 = F_15 ( V_18 ) ;
int V_82 , V_83 ;
V_82 = F_54 ( V_19 -> V_62 [ V_76 ] . V_63 ) ;
switch ( V_82 ) {
case - 1 :
V_83 = 0 ;
break;
case 0 :
case - 2 :
V_83 = 1 ;
break;
default:
V_83 = 2 ;
}
return sprintf ( V_75 , L_3 , V_83 ) ;
}
static T_3 F_55 ( struct V_17 * V_18 , struct V_73
* V_74 , const char * V_75 , T_4 V_78 )
{
int V_76 = F_38 ( V_74 ) -> V_77 ;
struct V_16 * V_19 = F_16 ( V_18 ) ;
struct V_11 * V_12 = V_19 -> V_12 ;
T_2 V_63 ;
unsigned long V_1 ;
int V_79 ;
V_79 = F_42 ( V_75 , 10 , & V_1 ) ;
if ( V_79 )
return V_79 ;
switch ( V_1 ) {
case 0 :
V_63 = 3 ;
break;
case 1 :
V_63 = 7 ;
break;
case 2 :
V_63 = 6 ;
break;
default:
return - V_81 ;
}
F_17 ( & V_19 -> V_20 ) ;
V_19 -> V_62 [ V_76 ] . V_63 = F_9 ( V_12 ,
F_31 ( V_76 ) ) ;
V_19 -> V_62 [ V_76 ] . V_63 = ( V_19 -> V_62 [ V_76 ] . V_63 & ~ 0xe0 )
| ( V_63 << 5 ) ;
F_13 ( V_12 , F_31 ( V_76 ) ,
V_19 -> V_62 [ V_76 ] . V_63 ) ;
F_36 ( & V_19 -> V_20 ) ;
return V_78 ;
}
static T_3 F_56 ( struct V_17 * V_18 ,
struct V_73 * V_74 , char * V_75 )
{
int V_76 = F_38 ( V_74 ) -> V_77 ;
struct V_16 * V_19 = F_15 ( V_18 ) ;
int V_6 ;
if ( F_57 ( V_19 ) )
V_6 = 22500 ;
else
V_6 = F_7 ( V_19 -> V_84 , V_19 -> V_64 [ V_76 ] ) ;
return sprintf ( V_75 , L_3 , V_6 ) ;
}
static T_3 F_58 ( struct V_17 * V_18 ,
struct V_73 * V_74 , const char * V_75 , T_4 V_78 )
{
int V_76 = F_38 ( V_74 ) -> V_77 ;
struct V_16 * V_19 = F_16 ( V_18 ) ;
struct V_11 * V_12 = V_19 -> V_12 ;
unsigned long V_1 ;
int V_79 ;
V_79 = F_42 ( V_75 , 10 , & V_1 ) ;
if ( V_79 )
return V_79 ;
F_17 ( & V_19 -> V_20 ) ;
if ( V_19 -> type == V_27 && V_1 >= 11300 ) {
V_19 -> V_39 &= ~ V_85 ;
F_13 ( V_12 , V_40 , V_19 -> V_39 ) ;
} else {
V_19 -> V_64 [ V_76 ] = F_6 ( V_19 -> V_84 ,
V_86 , V_1 ) ;
F_13 ( V_12 , F_32 ( V_76 ) ,
( V_19 -> V_8 [ V_76 ] . V_2 << 4 )
| V_19 -> V_64 [ V_76 ] ) ;
if ( V_19 -> type == V_27 ) {
V_19 -> V_39 |= V_85 ;
F_13 ( V_12 , V_40 , V_19 -> V_39 ) ;
}
}
F_36 ( & V_19 -> V_20 ) ;
return V_78 ;
}
static T_3 F_59 ( struct V_17 * V_18 , struct V_73 * V_74 ,
char * V_75 )
{
int V_76 = F_38 ( V_74 ) -> V_77 ;
struct V_16 * V_19 = F_15 ( V_18 ) ;
return sprintf ( V_75 , L_3 , F_60 ( V_76 , V_19 -> V_36 [ V_76 ] ,
V_19 -> V_32 [ V_76 ] ) ) ;
}
static T_3 F_61 ( struct V_17 * V_18 , struct V_73 * V_74 ,
char * V_75 )
{
int V_76 = F_38 ( V_74 ) -> V_77 ;
struct V_16 * V_19 = F_15 ( V_18 ) ;
return sprintf ( V_75 , L_3 , F_62 ( V_76 , V_19 -> V_57 [ V_76 ] ) ) ;
}
static T_3 F_63 ( struct V_17 * V_18 , struct V_73 * V_74 ,
const char * V_75 , T_4 V_78 )
{
int V_76 = F_38 ( V_74 ) -> V_77 ;
struct V_16 * V_19 = F_16 ( V_18 ) ;
struct V_11 * V_12 = V_19 -> V_12 ;
long V_1 ;
int V_79 ;
V_79 = F_64 ( V_75 , 10 , & V_1 ) ;
if ( V_79 )
return V_79 ;
F_17 ( & V_19 -> V_20 ) ;
V_19 -> V_57 [ V_76 ] = F_65 ( V_76 , V_1 ) ;
F_13 ( V_12 , F_25 ( V_76 ) , V_19 -> V_57 [ V_76 ] ) ;
F_36 ( & V_19 -> V_20 ) ;
return V_78 ;
}
static T_3 F_66 ( struct V_17 * V_18 , struct V_73 * V_74 ,
char * V_75 )
{
int V_76 = F_38 ( V_74 ) -> V_77 ;
struct V_16 * V_19 = F_15 ( V_18 ) ;
return sprintf ( V_75 , L_3 , F_62 ( V_76 , V_19 -> V_58 [ V_76 ] ) ) ;
}
static T_3 F_67 ( struct V_17 * V_18 , struct V_73 * V_74 ,
const char * V_75 , T_4 V_78 )
{
int V_76 = F_38 ( V_74 ) -> V_77 ;
struct V_16 * V_19 = F_16 ( V_18 ) ;
struct V_11 * V_12 = V_19 -> V_12 ;
long V_1 ;
int V_79 ;
V_79 = F_64 ( V_75 , 10 , & V_1 ) ;
if ( V_79 )
return V_79 ;
F_17 ( & V_19 -> V_20 ) ;
V_19 -> V_58 [ V_76 ] = F_65 ( V_76 , V_1 ) ;
F_13 ( V_12 , F_26 ( V_76 ) , V_19 -> V_58 [ V_76 ] ) ;
F_36 ( & V_19 -> V_20 ) ;
return V_78 ;
}
static T_3 F_68 ( struct V_17 * V_18 , struct V_73 * V_74 ,
char * V_75 )
{
int V_76 = F_38 ( V_74 ) -> V_77 ;
struct V_16 * V_19 = F_15 ( V_18 ) ;
return sprintf ( V_75 , L_3 , F_69 ( V_19 -> V_41 [ V_76 ] ,
V_19 -> V_33 [ V_76 ] ) ) ;
}
static T_3 F_70 ( struct V_17 * V_18 , struct V_73 * V_74 ,
char * V_75 )
{
int V_76 = F_38 ( V_74 ) -> V_77 ;
struct V_16 * V_19 = F_15 ( V_18 ) ;
return sprintf ( V_75 , L_3 , F_71 ( V_19 -> V_60 [ V_76 ] ) ) ;
}
static T_3 F_72 ( struct V_17 * V_18 , struct V_73 * V_74 ,
const char * V_75 , T_4 V_78 )
{
int V_76 = F_38 ( V_74 ) -> V_77 ;
struct V_16 * V_19 = F_16 ( V_18 ) ;
struct V_11 * V_12 = V_19 -> V_12 ;
long V_1 ;
int V_79 ;
V_79 = F_64 ( V_75 , 10 , & V_1 ) ;
if ( V_79 )
return V_79 ;
if ( F_23 ( V_19 ) )
V_1 += 64 ;
F_17 ( & V_19 -> V_20 ) ;
V_19 -> V_60 [ V_76 ] = F_73 ( V_1 ) ;
F_13 ( V_12 , F_29 ( V_76 ) , V_19 -> V_60 [ V_76 ] ) ;
F_36 ( & V_19 -> V_20 ) ;
return V_78 ;
}
static T_3 F_74 ( struct V_17 * V_18 , struct V_73 * V_74 ,
char * V_75 )
{
int V_76 = F_38 ( V_74 ) -> V_77 ;
struct V_16 * V_19 = F_15 ( V_18 ) ;
return sprintf ( V_75 , L_3 , F_71 ( V_19 -> V_61 [ V_76 ] ) ) ;
}
static T_3 F_75 ( struct V_17 * V_18 , struct V_73 * V_74 ,
const char * V_75 , T_4 V_78 )
{
int V_76 = F_38 ( V_74 ) -> V_77 ;
struct V_16 * V_19 = F_16 ( V_18 ) ;
struct V_11 * V_12 = V_19 -> V_12 ;
long V_1 ;
int V_79 ;
V_79 = F_64 ( V_75 , 10 , & V_1 ) ;
if ( V_79 )
return V_79 ;
if ( F_23 ( V_19 ) )
V_1 += 64 ;
F_17 ( & V_19 -> V_20 ) ;
V_19 -> V_61 [ V_76 ] = F_73 ( V_1 ) ;
F_13 ( V_12 , F_30 ( V_76 ) , V_19 -> V_61 [ V_76 ] ) ;
F_36 ( & V_19 -> V_20 ) ;
return V_78 ;
}
static T_3 F_76 ( struct V_17 * V_18 ,
struct V_73 * V_74 , char * V_75 )
{
int V_76 = F_38 ( V_74 ) -> V_77 ;
struct V_16 * V_19 = F_15 ( V_18 ) ;
return sprintf ( V_75 , L_3 , F_54 ( V_19 -> V_62 [ V_76 ] . V_63 ) ) ;
}
static T_3 F_77 ( struct V_17 * V_18 ,
struct V_73 * V_74 , const char * V_75 , T_4 V_78 )
{
int V_76 = F_38 ( V_74 ) -> V_77 ;
struct V_16 * V_19 = F_16 ( V_18 ) ;
struct V_11 * V_12 = V_19 -> V_12 ;
long V_1 ;
int V_79 ;
V_79 = F_64 ( V_75 , 10 , & V_1 ) ;
if ( V_79 )
return V_79 ;
F_17 ( & V_19 -> V_20 ) ;
V_19 -> V_62 [ V_76 ] . V_63 = ( V_19 -> V_62 [ V_76 ] . V_63 & ( ~ 0xe0 ) )
| F_8 ( V_1 ) ;
F_13 ( V_12 , F_31 ( V_76 ) ,
V_19 -> V_62 [ V_76 ] . V_63 ) ;
F_36 ( & V_19 -> V_20 ) ;
return V_78 ;
}
static T_3 F_78 ( struct V_17 * V_18 ,
struct V_73 * V_74 , char * V_75 )
{
int V_76 = F_38 ( V_74 ) -> V_77 ;
struct V_16 * V_19 = F_15 ( V_18 ) ;
return sprintf ( V_75 , L_3 , F_50 ( V_19 -> V_62 [ V_76 ] . V_65 ) ) ;
}
static T_3 F_79 ( struct V_17 * V_18 ,
struct V_73 * V_74 , const char * V_75 , T_4 V_78 )
{
int V_76 = F_38 ( V_74 ) -> V_77 ;
struct V_16 * V_19 = F_16 ( V_18 ) ;
struct V_11 * V_12 = V_19 -> V_12 ;
unsigned long V_1 ;
int V_79 ;
V_79 = F_42 ( V_75 , 10 , & V_1 ) ;
if ( V_79 )
return V_79 ;
F_17 ( & V_19 -> V_20 ) ;
V_19 -> V_62 [ V_76 ] . V_65 = F_52 ( V_1 ) ;
F_13 ( V_12 , F_33 ( V_76 ) ,
V_19 -> V_62 [ V_76 ] . V_65 ) ;
F_36 ( & V_19 -> V_20 ) ;
return V_78 ;
}
static T_3 F_80 ( struct V_17 * V_18 ,
struct V_73 * V_74 , char * V_75 )
{
int V_76 = F_38 ( V_74 ) -> V_77 ;
struct V_16 * V_19 = F_15 ( V_18 ) ;
return sprintf ( V_75 , L_3 , V_19 -> V_62 [ V_76 ] . V_69 ) ;
}
static T_3 F_81 ( struct V_17 * V_18 ,
struct V_73 * V_74 , const char * V_75 , T_4 V_78 )
{
int V_76 = F_38 ( V_74 ) -> V_77 ;
struct V_16 * V_19 = F_16 ( V_18 ) ;
struct V_11 * V_12 = V_19 -> V_12 ;
T_2 V_87 ;
long V_1 ;
int V_79 ;
V_79 = F_64 ( V_75 , 10 , & V_1 ) ;
if ( V_79 )
return V_79 ;
F_17 ( & V_19 -> V_20 ) ;
V_19 -> V_62 [ V_76 ] . V_69 = V_1 ;
V_87 = F_9 ( V_12 , V_68 ) ;
V_87 &= ~ ( 0x20 << V_76 ) ;
if ( V_19 -> V_62 [ V_76 ] . V_69 )
V_87 |= 0x20 << V_76 ;
F_13 ( V_12 , V_68 , V_87 ) ;
F_36 ( & V_19 -> V_20 ) ;
return V_78 ;
}
static T_3 F_82 ( struct V_17 * V_18 ,
struct V_73 * V_74 , char * V_75 )
{
int V_76 = F_38 ( V_74 ) -> V_77 ;
struct V_16 * V_19 = F_15 ( V_18 ) ;
return sprintf ( V_75 , L_3 , F_71 ( V_19 -> V_8 [ V_76 ] . V_66 ) -
F_83 ( V_19 -> V_8 [ V_76 ] . V_71 ) ) ;
}
static T_3 F_84 ( struct V_17 * V_18 ,
struct V_73 * V_74 , const char * V_75 , T_4 V_78 )
{
int V_76 = F_38 ( V_74 ) -> V_77 ;
struct V_16 * V_19 = F_16 ( V_18 ) ;
struct V_11 * V_12 = V_19 -> V_12 ;
int V_88 ;
long V_1 ;
int V_79 ;
V_79 = F_64 ( V_75 , 10 , & V_1 ) ;
if ( V_79 )
return V_79 ;
F_17 ( & V_19 -> V_20 ) ;
V_88 = F_71 ( V_19 -> V_8 [ V_76 ] . V_66 ) ;
V_19 -> V_8 [ V_76 ] . V_71 = F_85 ( V_88 - V_1 ) ;
if ( V_76 == 0 || V_76 == 1 ) {
F_13 ( V_12 , V_70 ,
( V_19 -> V_8 [ 0 ] . V_71 << 4 )
| V_19 -> V_8 [ 1 ] . V_71 ) ;
} else {
F_13 ( V_12 , V_72 ,
( V_19 -> V_8 [ 2 ] . V_71 << 4 ) ) ;
}
F_36 ( & V_19 -> V_20 ) ;
return V_78 ;
}
static T_3 F_86 ( struct V_17 * V_18 ,
struct V_73 * V_74 , char * V_75 )
{
int V_76 = F_38 ( V_74 ) -> V_77 ;
struct V_16 * V_19 = F_15 ( V_18 ) ;
return sprintf ( V_75 , L_3 , F_71 ( V_19 -> V_8 [ V_76 ] . V_66 ) ) ;
}
static T_3 F_87 ( struct V_17 * V_18 ,
struct V_73 * V_74 , const char * V_75 , T_4 V_78 )
{
int V_76 = F_38 ( V_74 ) -> V_77 ;
struct V_16 * V_19 = F_16 ( V_18 ) ;
struct V_11 * V_12 = V_19 -> V_12 ;
long V_1 ;
int V_79 ;
V_79 = F_64 ( V_75 , 10 , & V_1 ) ;
if ( V_79 )
return V_79 ;
F_17 ( & V_19 -> V_20 ) ;
V_19 -> V_8 [ V_76 ] . V_66 = F_73 ( V_1 ) ;
F_13 ( V_12 , F_34 ( V_76 ) ,
V_19 -> V_8 [ V_76 ] . V_66 ) ;
V_19 -> V_8 [ V_76 ] . V_2 = F_3 (
F_71 ( V_19 -> V_8 [ V_76 ] . V_89 ) -
F_71 ( V_19 -> V_8 [ V_76 ] . V_66 ) ) ;
F_13 ( V_12 , F_32 ( V_76 ) ,
( ( V_19 -> V_8 [ V_76 ] . V_2 & 0x0f ) << 4 )
| ( V_19 -> V_64 [ V_76 ] & 0x07 ) ) ;
F_36 ( & V_19 -> V_20 ) ;
return V_78 ;
}
static T_3 F_88 ( struct V_17 * V_18 ,
struct V_73 * V_74 , char * V_75 )
{
int V_76 = F_38 ( V_74 ) -> V_77 ;
struct V_16 * V_19 = F_15 ( V_18 ) ;
return sprintf ( V_75 , L_3 , F_71 ( V_19 -> V_8 [ V_76 ] . V_66 ) +
F_89 ( V_19 -> V_8 [ V_76 ] . V_2 ) ) ;
}
static T_3 F_90 ( struct V_17 * V_18 ,
struct V_73 * V_74 , const char * V_75 , T_4 V_78 )
{
int V_76 = F_38 ( V_74 ) -> V_77 ;
struct V_16 * V_19 = F_16 ( V_18 ) ;
struct V_11 * V_12 = V_19 -> V_12 ;
int V_88 ;
long V_1 ;
int V_79 ;
V_79 = F_64 ( V_75 , 10 , & V_1 ) ;
if ( V_79 )
return V_79 ;
F_17 ( & V_19 -> V_20 ) ;
V_88 = F_71 ( V_19 -> V_8 [ V_76 ] . V_66 ) ;
V_19 -> V_8 [ V_76 ] . V_89 = F_73 ( V_1 ) ;
V_19 -> V_8 [ V_76 ] . V_2 = F_3 (
V_1 - V_88 ) ;
F_13 ( V_12 , F_32 ( V_76 ) ,
( ( V_19 -> V_8 [ V_76 ] . V_2 & 0x0f ) << 4 )
| ( V_19 -> V_64 [ V_76 ] & 0x07 ) ) ;
F_36 ( & V_19 -> V_20 ) ;
return V_78 ;
}
static T_3 F_91 ( struct V_17 * V_18 ,
struct V_73 * V_74 , char * V_75 )
{
int V_76 = F_38 ( V_74 ) -> V_77 ;
struct V_16 * V_19 = F_15 ( V_18 ) ;
return sprintf ( V_75 , L_3 , F_71 ( V_19 -> V_8 [ V_76 ] . V_67 ) ) ;
}
static T_3 F_92 ( struct V_17 * V_18 ,
struct V_73 * V_74 , const char * V_75 , T_4 V_78 )
{
int V_76 = F_38 ( V_74 ) -> V_77 ;
struct V_16 * V_19 = F_16 ( V_18 ) ;
struct V_11 * V_12 = V_19 -> V_12 ;
long V_1 ;
int V_79 ;
V_79 = F_64 ( V_75 , 10 , & V_1 ) ;
if ( V_79 )
return V_79 ;
F_17 ( & V_19 -> V_20 ) ;
V_19 -> V_8 [ V_76 ] . V_67 = F_73 ( V_1 ) ;
F_13 ( V_12 , F_35 ( V_76 ) ,
V_19 -> V_8 [ V_76 ] . V_67 ) ;
F_36 ( & V_19 -> V_20 ) ;
return V_78 ;
}
static void F_93 ( struct V_11 * V_12 )
{
int V_15 ;
V_15 = F_9 ( V_12 , V_90 ) ;
if ( ! ( V_15 & 0x01 ) ) {
F_94 ( & V_12 -> V_18 , L_6 ) ;
F_13 ( V_12 , V_90 , V_15 | 0x01 ) ;
}
if ( V_15 & 0x02 )
F_95 ( & V_12 -> V_18 , L_7 ) ;
if ( ! ( V_15 & 0x04 ) )
F_95 ( & V_12 -> V_18 , L_8 ) ;
}
static int F_96 ( struct V_11 * V_12 )
{
int V_9 ;
T_2 V_91 , V_37 ;
for ( V_9 = 0 ; V_9 < 8 ; V_9 ++ ) {
V_91 = F_12 ( V_12 , 0x20 + V_9 ) ;
V_37 = F_12 ( V_12 , 0x28 + V_9 ) ;
if ( V_91 != 0x00 || V_37 != 0xff )
return 0 ;
}
return 1 ;
}
static int F_97 ( struct V_11 * V_12 , struct V_92 * V_93 )
{
struct V_94 * V_95 = V_12 -> V_95 ;
int V_96 = V_12 -> V_97 ;
const char * V_98 = NULL ;
int V_99 , V_100 ;
if ( ! F_98 ( V_95 , V_101 ) ) {
return - V_102 ;
}
V_99 = F_9 ( V_12 , V_103 ) ;
V_100 = F_9 ( V_12 , V_104 ) ;
F_19 ( & V_95 -> V_18 ,
L_9 ,
V_96 , V_99 , V_100 ) ;
if ( V_99 == V_105 ) {
switch ( V_100 ) {
case V_106 :
V_98 = L_10 ;
break;
case V_107 :
V_98 = L_11 ;
break;
case V_108 :
case V_109 :
if ( F_96 ( V_12 ) ) {
F_19 ( & V_95 -> V_18 ,
L_12 ) ;
return - V_102 ;
}
V_98 = L_13 ;
break;
}
} else if ( V_99 == V_110 ) {
switch ( V_100 ) {
case V_111 :
V_98 = L_14 ;
break;
case V_112 :
case V_113 :
V_98 = L_15 ;
break;
case V_114 :
case V_115 :
V_98 = L_16 ;
break;
}
} else if ( V_99 == V_116 ) {
switch ( V_100 ) {
case V_117 :
case V_118 :
V_98 = L_17 ;
break;
case V_119 :
V_98 = L_18 ;
break;
case V_120 :
case V_121 :
V_98 = L_19 ;
break;
case V_122 :
V_98 = L_20 ;
break;
}
}
if ( ! V_98 )
return - V_102 ;
F_99 ( V_93 -> type , V_98 , V_123 ) ;
return 0 ;
}
static int F_100 ( struct V_11 * V_12 , const struct V_124 * V_125 )
{
struct V_17 * V_18 = & V_12 -> V_18 ;
struct V_17 * V_126 ;
struct V_16 * V_19 ;
int V_127 = 0 ;
V_19 = F_101 ( V_18 , sizeof( struct V_16 ) , V_128 ) ;
if ( ! V_19 )
return - V_129 ;
V_19 -> V_12 = V_12 ;
V_19 -> type = V_125 -> V_130 ;
F_102 ( & V_19 -> V_20 ) ;
switch ( V_19 -> type ) {
case V_25 :
case V_26 :
case V_27 :
case V_44 :
case V_46 :
case V_47 :
case V_48 :
V_19 -> V_84 = V_131 ;
break;
default:
V_19 -> V_84 = V_132 ;
}
V_19 -> V_80 = F_103 () ;
F_93 ( V_12 ) ;
V_19 -> V_133 [ V_127 ++ ] = & V_134 ;
if ( V_19 -> type != V_48 ) {
V_19 -> V_133 [ V_127 ++ ] = & V_135 ;
V_19 -> V_133 [ V_127 ++ ] = & V_136 ;
}
if ( V_19 -> type == V_26 || V_19 -> type == V_27 ) {
T_2 V_34 = F_9 ( V_12 , V_35 ) ;
if ( V_34 & 0x80 )
V_19 -> V_38 = true ;
}
if ( ! V_19 -> V_38 )
V_19 -> V_133 [ V_127 ++ ] = & V_137 ;
if ( V_19 -> type == V_44 )
V_19 -> V_133 [ V_127 ++ ] = & V_138 ;
V_126 = F_104 ( V_18 , V_12 -> V_139 ,
V_19 , V_19 -> V_133 ) ;
return F_105 ( V_126 ) ;
}
