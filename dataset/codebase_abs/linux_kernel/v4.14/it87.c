static inline int F_1 ( int V_1 , int V_2 )
{
F_2 ( V_2 , V_1 ) ;
return F_3 ( V_1 + 1 ) ;
}
static inline void F_4 ( int V_1 , int V_2 , int V_3 )
{
F_2 ( V_2 , V_1 ) ;
F_2 ( V_3 , V_1 + 1 ) ;
}
static int F_5 ( int V_1 , int V_2 )
{
int V_3 ;
F_2 ( V_2 ++ , V_1 ) ;
V_3 = F_3 ( V_1 + 1 ) << 8 ;
F_2 ( V_2 , V_1 ) ;
V_3 |= F_3 ( V_1 + 1 ) ;
return V_3 ;
}
static inline void F_6 ( int V_1 , int V_4 )
{
F_2 ( V_5 , V_1 ) ;
F_2 ( V_4 , V_1 + 1 ) ;
}
static inline int F_7 ( int V_1 )
{
if ( ! F_8 ( V_1 , 2 , V_6 ) )
return - V_7 ;
F_2 ( 0x87 , V_1 ) ;
F_2 ( 0x01 , V_1 ) ;
F_2 ( 0x55 , V_1 ) ;
F_2 ( V_1 == V_8 ? 0xaa : 0x55 , V_1 ) ;
return 0 ;
}
static inline void F_9 ( int V_1 )
{
F_2 ( 0x02 , V_1 ) ;
F_2 ( 0x02 , V_1 + 1 ) ;
F_10 ( V_1 , 2 ) ;
}
static int F_11 ( const struct V_9 * V_10 , int V_11 )
{
int V_12 ;
if ( F_12 ( V_10 ) )
V_12 = 120 ;
else if ( F_13 ( V_10 ) )
V_12 = 109 ;
else
V_12 = 160 ;
if ( V_10 -> V_13 & F_14 ( V_11 ) )
V_12 <<= 1 ;
return V_12 ;
}
static T_1 F_15 ( const struct V_9 * V_10 , int V_11 , long V_3 )
{
V_3 = F_16 ( V_3 * 10 , F_11 ( V_10 , V_11 ) ) ;
return F_17 ( V_3 , 0 , 255 ) ;
}
static int F_18 ( const struct V_9 * V_10 , int V_11 , int V_3 )
{
return F_16 ( V_3 * F_11 ( V_10 , V_11 ) , 10 ) ;
}
static inline T_1 F_19 ( long V_14 , int div )
{
if ( V_14 == 0 )
return 255 ;
V_14 = F_17 ( V_14 , 1 , 1000000 ) ;
return F_17 ( ( 1350000 + V_14 * div / 2 ) / ( V_14 * div ) , 1 , 254 ) ;
}
static inline T_2 F_20 ( long V_14 )
{
if ( V_14 == 0 )
return 0xffff ;
return F_17 ( ( 1350000 + V_14 ) / ( V_14 * 2 ) , 1 , 0xfffe ) ;
}
static T_1 F_21 ( const struct V_9 * V_10 , long V_3 )
{
if ( F_22 ( V_10 ) )
return V_3 ;
else
return V_3 >> 1 ;
}
static int F_23 ( const struct V_9 * V_10 , T_1 V_2 )
{
if ( F_22 ( V_10 ) )
return V_2 ;
else
return ( V_2 & 0x7f ) << 1 ;
}
static int F_24 ( int V_3 )
{
int V_15 = 0 ;
while ( V_15 < 7 && ( V_3 >>= 1 ) )
V_15 ++ ;
return V_15 ;
}
static int F_25 ( struct V_9 * V_10 , T_1 V_2 )
{
F_26 ( V_2 , V_10 -> V_16 + V_17 ) ;
return F_27 ( V_10 -> V_16 + V_18 ) ;
}
static void F_28 ( struct V_9 * V_10 , T_1 V_2 , T_1 V_19 )
{
F_26 ( V_2 , V_10 -> V_16 + V_17 ) ;
F_26 ( V_19 , V_10 -> V_16 + V_18 ) ;
}
static void F_29 ( struct V_9 * V_10 , int V_11 )
{
V_10 -> V_20 [ V_11 ] = F_25 ( V_10 , V_21 [ V_11 ] ) ;
if ( F_22 ( V_10 ) ) {
V_10 -> V_22 [ V_11 ] = V_10 -> V_20 [ V_11 ] & 0x03 ;
V_10 -> V_23 [ V_11 ] = F_25 ( V_10 ,
V_24 [ V_11 ] ) ;
} else {
if ( V_10 -> V_20 [ V_11 ] & 0x80 )
V_10 -> V_22 [ V_11 ] = V_10 -> V_20 [ V_11 ] & 0x03 ;
else
V_10 -> V_23 [ V_11 ] = V_10 -> V_20 [ V_11 ] & 0x7f ;
}
if ( F_30 ( V_10 ) ) {
int V_25 ;
for ( V_25 = 0 ; V_25 < 5 ; V_25 ++ )
V_10 -> V_26 [ V_11 ] [ V_25 ] = F_25 ( V_10 ,
F_31 ( V_11 , V_25 ) ) ;
for ( V_25 = 0 ; V_25 < 3 ; V_25 ++ )
V_10 -> V_27 [ V_11 ] [ V_25 ] = F_25 ( V_10 ,
F_32 ( V_11 , V_25 ) ) ;
} else if ( F_22 ( V_10 ) ) {
int V_25 ;
V_10 -> V_26 [ V_11 ] [ 0 ] =
F_25 ( V_10 , F_31 ( V_11 , 5 ) ) ;
for ( V_25 = 0 ; V_25 < 3 ; V_25 ++ )
V_10 -> V_26 [ V_11 ] [ V_25 + 1 ] =
F_25 ( V_10 ,
F_31 ( V_11 , V_25 ) ) ;
V_10 -> V_27 [ V_11 ] [ 0 ] =
F_25 ( V_10 , F_31 ( V_11 , 3 ) ) ;
V_10 -> V_27 [ V_11 ] [ 1 ] =
F_25 ( V_10 , F_31 ( V_11 , 4 ) ) ;
}
}
static struct V_9 * F_33 ( struct V_28 * V_29 )
{
struct V_9 * V_10 = F_34 ( V_29 ) ;
int V_25 ;
F_35 ( & V_10 -> V_30 ) ;
if ( F_36 ( V_31 , V_10 -> V_32 + V_33 + V_33 / 2 ) ||
! V_10 -> V_34 ) {
if ( V_35 ) {
F_28 ( V_10 , V_36 ,
F_25 ( V_10 , V_36 ) | 0x40 ) ;
}
for ( V_25 = 0 ; V_25 < V_37 ; V_25 ++ ) {
if ( ! ( V_10 -> V_38 & F_14 ( V_25 ) ) )
continue;
V_10 -> V_39 [ V_25 ] [ 0 ] =
F_25 ( V_10 , V_40 [ V_25 ] ) ;
if ( V_25 >= V_41 )
continue;
V_10 -> V_39 [ V_25 ] [ 1 ] =
F_25 ( V_10 , F_37 ( V_25 ) ) ;
V_10 -> V_39 [ V_25 ] [ 2 ] =
F_25 ( V_10 , F_38 ( V_25 ) ) ;
}
for ( V_25 = 0 ; V_25 < V_42 ; V_25 ++ ) {
if ( ! ( V_10 -> V_43 & F_14 ( V_25 ) ) )
continue;
V_10 -> V_44 [ V_25 ] [ 1 ] =
F_25 ( V_10 , V_45 [ V_25 ] ) ;
V_10 -> V_44 [ V_25 ] [ 0 ] = F_25 ( V_10 ,
V_46 [ V_25 ] ) ;
if ( F_39 ( V_10 ) ) {
V_10 -> V_44 [ V_25 ] [ 0 ] |= F_25 ( V_10 ,
V_47 [ V_25 ] ) << 8 ;
V_10 -> V_44 [ V_25 ] [ 1 ] |= F_25 ( V_10 ,
V_48 [ V_25 ] ) << 8 ;
}
}
for ( V_25 = 0 ; V_25 < V_49 ; V_25 ++ ) {
if ( ! ( V_10 -> V_50 & F_14 ( V_25 ) ) )
continue;
V_10 -> V_51 [ V_25 ] [ 0 ] =
F_25 ( V_10 , F_40 ( V_25 ) ) ;
if ( F_41 ( V_10 ) && V_25 < V_52 )
V_10 -> V_51 [ V_25 ] [ 3 ] =
F_25 ( V_10 ,
V_53 [ V_25 ] ) ;
if ( V_25 >= V_54 )
continue;
V_10 -> V_51 [ V_25 ] [ 1 ] =
F_25 ( V_10 , F_42 ( V_25 ) ) ;
V_10 -> V_51 [ V_25 ] [ 2 ] =
F_25 ( V_10 , F_43 ( V_25 ) ) ;
}
if ( ( V_10 -> V_43 & 0x07 ) && ! F_39 ( V_10 ) ) {
V_25 = F_25 ( V_10 , V_55 ) ;
V_10 -> V_56 [ 0 ] = V_25 & 0x07 ;
V_10 -> V_56 [ 1 ] = ( V_25 >> 3 ) & 0x07 ;
V_10 -> V_56 [ 2 ] = ( V_25 & 0x40 ) ? 3 : 1 ;
}
V_10 -> V_57 =
F_25 ( V_10 , V_58 ) |
( F_25 ( V_10 , V_59 ) << 8 ) |
( F_25 ( V_10 , V_60 ) << 16 ) ;
V_10 -> V_61 = F_25 ( V_10 , V_62 ) ;
V_10 -> V_63 = F_25 ( V_10 ,
V_64 ) ;
V_10 -> V_65 = F_25 ( V_10 , V_66 ) ;
for ( V_25 = 0 ; V_25 < V_67 ; V_25 ++ ) {
if ( ! ( V_10 -> V_68 & F_14 ( V_25 ) ) )
continue;
F_29 ( V_10 , V_25 ) ;
}
V_10 -> V_69 = F_25 ( V_10 , V_70 ) ;
V_10 -> V_71 = F_25 ( V_10 , V_72 ) ;
if ( V_10 -> type == V_73 || V_10 -> type == V_74 ) {
V_10 -> V_75 = F_25 ( V_10 , V_76 ) ;
V_10 -> V_75 &= 0x3f ;
}
V_10 -> V_32 = V_31 ;
V_10 -> V_34 = 1 ;
}
F_44 ( & V_10 -> V_30 ) ;
return V_10 ;
}
static T_3 F_45 ( struct V_28 * V_29 , struct V_77 * V_78 ,
char * V_79 )
{
struct V_80 * V_81 = F_46 ( V_78 ) ;
struct V_9 * V_10 = F_33 ( V_29 ) ;
int V_82 = V_81 -> V_82 ;
int V_11 = V_81 -> V_11 ;
return sprintf ( V_79 , L_1 , F_18 ( V_10 , V_11 , V_10 -> V_39 [ V_11 ] [ V_82 ] ) ) ;
}
static T_3 F_47 ( struct V_28 * V_29 , struct V_77 * V_78 ,
const char * V_79 , T_4 V_83 )
{
struct V_80 * V_81 = F_46 ( V_78 ) ;
struct V_9 * V_10 = F_34 ( V_29 ) ;
int V_82 = V_81 -> V_82 ;
int V_11 = V_81 -> V_11 ;
unsigned long V_3 ;
if ( F_48 ( V_79 , 10 , & V_3 ) < 0 )
return - V_84 ;
F_35 ( & V_10 -> V_30 ) ;
V_10 -> V_39 [ V_11 ] [ V_82 ] = F_15 ( V_10 , V_11 , V_3 ) ;
F_28 ( V_10 ,
V_82 == 1 ? F_37 ( V_11 )
: F_38 ( V_11 ) ,
V_10 -> V_39 [ V_11 ] [ V_82 ] ) ;
F_44 ( & V_10 -> V_30 ) ;
return V_83 ;
}
static T_3 F_49 ( struct V_28 * V_29 , struct V_77 * V_78 ,
char * V_79 )
{
struct V_80 * V_81 = F_46 ( V_78 ) ;
int V_11 = V_81 -> V_11 ;
int V_82 = V_81 -> V_82 ;
struct V_9 * V_10 = F_33 ( V_29 ) ;
return sprintf ( V_79 , L_1 , F_50 ( V_10 -> V_51 [ V_11 ] [ V_82 ] ) ) ;
}
static T_3 F_51 ( struct V_28 * V_29 , struct V_77 * V_78 ,
const char * V_79 , T_4 V_83 )
{
struct V_80 * V_81 = F_46 ( V_78 ) ;
int V_11 = V_81 -> V_11 ;
int V_82 = V_81 -> V_82 ;
struct V_9 * V_10 = F_34 ( V_29 ) ;
long V_3 ;
T_1 V_2 , V_85 ;
if ( F_52 ( V_79 , 10 , & V_3 ) < 0 )
return - V_84 ;
F_35 ( & V_10 -> V_30 ) ;
switch ( V_82 ) {
default:
case 1 :
V_2 = F_42 ( V_11 ) ;
break;
case 2 :
V_2 = F_43 ( V_11 ) ;
break;
case 3 :
V_85 = F_25 ( V_10 , V_62 ) ;
if ( ! ( V_85 & 0x80 ) ) {
V_85 |= 0x80 ;
F_28 ( V_10 , V_62 , V_85 ) ;
}
V_10 -> V_34 = 0 ;
V_2 = V_53 [ V_11 ] ;
break;
}
V_10 -> V_51 [ V_11 ] [ V_82 ] = F_53 ( V_3 ) ;
F_28 ( V_10 , V_2 , V_10 -> V_51 [ V_11 ] [ V_82 ] ) ;
F_44 ( & V_10 -> V_30 ) ;
return V_83 ;
}
static T_3 F_54 ( struct V_28 * V_29 , struct V_77 * V_78 ,
char * V_79 )
{
struct V_86 * V_87 = F_55 ( V_78 ) ;
int V_11 = V_87 -> V_82 ;
struct V_9 * V_10 = F_33 ( V_29 ) ;
T_1 V_2 = V_10 -> V_69 ;
T_1 V_71 = V_10 -> V_71 ;
if ( ( F_56 ( V_10 , V_11 ) && ( V_2 >> 6 == V_11 + 1 ) ) ||
( F_57 ( V_10 , V_11 ) && ( V_71 & 0x80 ) ) )
return sprintf ( V_79 , L_2 ) ;
if ( V_2 & ( 1 << V_11 ) )
return sprintf ( V_79 , L_3 ) ;
if ( V_2 & ( 8 << V_11 ) )
return sprintf ( V_79 , L_4 ) ;
return sprintf ( V_79 , L_5 ) ;
}
static T_3 F_58 ( struct V_28 * V_29 , struct V_77 * V_78 ,
const char * V_79 , T_4 V_83 )
{
struct V_86 * V_87 = F_55 ( V_78 ) ;
int V_11 = V_87 -> V_82 ;
struct V_9 * V_10 = F_34 ( V_29 ) ;
long V_3 ;
T_1 V_2 , V_71 ;
if ( F_52 ( V_79 , 10 , & V_3 ) < 0 )
return - V_84 ;
V_2 = F_25 ( V_10 , V_70 ) ;
V_2 &= ~ ( 1 << V_11 ) ;
V_2 &= ~ ( 8 << V_11 ) ;
if ( F_56 ( V_10 , V_11 ) && ( V_2 >> 6 == V_11 + 1 || V_3 == 6 ) )
V_2 &= 0x3f ;
V_71 = F_25 ( V_10 , V_72 ) ;
if ( F_57 ( V_10 , V_11 ) && ( ( V_71 & 0x80 ) || V_3 == 6 ) )
V_71 &= 0x7f ;
if ( V_3 == 2 ) {
F_59 ( V_29 ,
L_6 ) ;
V_3 = 4 ;
}
if ( V_3 == 3 )
V_2 |= 1 << V_11 ;
else if ( V_3 == 4 )
V_2 |= 8 << V_11 ;
else if ( F_56 ( V_10 , V_11 ) && V_3 == 6 )
V_2 |= ( V_11 + 1 ) << 6 ;
else if ( F_57 ( V_10 , V_11 ) && V_3 == 6 )
V_71 |= 0x80 ;
else if ( V_3 != 0 )
return - V_84 ;
F_35 ( & V_10 -> V_30 ) ;
V_10 -> V_69 = V_2 ;
V_10 -> V_71 = V_71 ;
F_28 ( V_10 , V_70 , V_10 -> V_69 ) ;
if ( F_57 ( V_10 , V_11 ) )
F_28 ( V_10 , V_72 , V_10 -> V_71 ) ;
V_10 -> V_34 = 0 ;
F_44 ( & V_10 -> V_30 ) ;
return V_83 ;
}
static int F_60 ( const struct V_9 * V_10 , int V_11 )
{
if ( V_10 -> type != V_88 && V_11 < 3 && ! ( V_10 -> V_63 & F_14 ( V_11 ) ) )
return 0 ;
if ( V_10 -> V_20 [ V_11 ] & 0x80 )
return 2 ;
if ( ( V_10 -> type == V_88 || V_11 >= 3 ) &&
V_10 -> V_23 [ V_11 ] == F_21 ( V_10 , 0xff ) )
return 0 ;
return 1 ;
}
static T_3 F_61 ( struct V_28 * V_29 , struct V_77 * V_78 ,
char * V_79 )
{
struct V_80 * V_81 = F_46 ( V_78 ) ;
int V_11 = V_81 -> V_11 ;
int V_82 = V_81 -> V_82 ;
int V_89 ;
struct V_9 * V_10 = F_33 ( V_29 ) ;
V_89 = F_39 ( V_10 ) ?
F_62 ( V_10 -> V_44 [ V_11 ] [ V_82 ] ) :
F_63 ( V_10 -> V_44 [ V_11 ] [ V_82 ] ,
F_64 ( V_10 -> V_56 [ V_11 ] ) ) ;
return sprintf ( V_79 , L_1 , V_89 ) ;
}
static T_3 F_65 ( struct V_28 * V_29 , struct V_77 * V_78 ,
char * V_79 )
{
struct V_86 * V_87 = F_55 ( V_78 ) ;
struct V_9 * V_10 = F_33 ( V_29 ) ;
int V_11 = V_87 -> V_82 ;
return sprintf ( V_79 , L_7 , F_64 ( V_10 -> V_56 [ V_11 ] ) ) ;
}
static T_3 F_66 ( struct V_28 * V_29 ,
struct V_77 * V_78 , char * V_79 )
{
struct V_86 * V_87 = F_55 ( V_78 ) ;
struct V_9 * V_10 = F_33 ( V_29 ) ;
int V_11 = V_87 -> V_82 ;
return sprintf ( V_79 , L_1 , F_60 ( V_10 , V_11 ) ) ;
}
static T_3 F_67 ( struct V_28 * V_29 , struct V_77 * V_78 ,
char * V_79 )
{
struct V_86 * V_87 = F_55 ( V_78 ) ;
struct V_9 * V_10 = F_33 ( V_29 ) ;
int V_11 = V_87 -> V_82 ;
return sprintf ( V_79 , L_1 ,
F_23 ( V_10 , V_10 -> V_23 [ V_11 ] ) ) ;
}
static T_3 F_68 ( struct V_28 * V_29 , struct V_77 * V_78 ,
char * V_79 )
{
struct V_86 * V_87 = F_55 ( V_78 ) ;
struct V_9 * V_10 = F_33 ( V_29 ) ;
int V_11 = V_87 -> V_82 ;
unsigned int V_90 ;
int V_82 ;
if ( F_69 ( V_10 ) && V_11 == 1 )
V_82 = ( V_10 -> V_71 >> 4 ) & 0x07 ;
else
V_82 = ( V_10 -> V_65 >> 4 ) & 0x07 ;
V_90 = V_91 [ V_82 ] / ( F_22 ( V_10 ) ? 256 : 128 ) ;
return sprintf ( V_79 , L_8 , V_90 ) ;
}
static T_3 F_70 ( struct V_28 * V_29 , struct V_77 * V_78 ,
const char * V_79 , T_4 V_83 )
{
struct V_80 * V_81 = F_46 ( V_78 ) ;
int V_11 = V_81 -> V_11 ;
int V_82 = V_81 -> V_82 ;
struct V_9 * V_10 = F_34 ( V_29 ) ;
long V_3 ;
T_1 V_2 ;
if ( F_52 ( V_79 , 10 , & V_3 ) < 0 )
return - V_84 ;
F_35 ( & V_10 -> V_30 ) ;
if ( F_39 ( V_10 ) ) {
V_10 -> V_44 [ V_11 ] [ V_82 ] = F_20 ( V_3 ) ;
F_28 ( V_10 , V_45 [ V_11 ] ,
V_10 -> V_44 [ V_11 ] [ V_82 ] & 0xff ) ;
F_28 ( V_10 , V_48 [ V_11 ] ,
V_10 -> V_44 [ V_11 ] [ V_82 ] >> 8 ) ;
} else {
V_2 = F_25 ( V_10 , V_55 ) ;
switch ( V_11 ) {
case 0 :
V_10 -> V_56 [ V_11 ] = V_2 & 0x07 ;
break;
case 1 :
V_10 -> V_56 [ V_11 ] = ( V_2 >> 3 ) & 0x07 ;
break;
case 2 :
V_10 -> V_56 [ V_11 ] = ( V_2 & 0x40 ) ? 3 : 1 ;
break;
}
V_10 -> V_44 [ V_11 ] [ V_82 ] =
F_19 ( V_3 , F_64 ( V_10 -> V_56 [ V_11 ] ) ) ;
F_28 ( V_10 , V_45 [ V_11 ] ,
V_10 -> V_44 [ V_11 ] [ V_82 ] ) ;
}
F_44 ( & V_10 -> V_30 ) ;
return V_83 ;
}
static T_3 F_71 ( struct V_28 * V_29 , struct V_77 * V_78 ,
const char * V_79 , T_4 V_83 )
{
struct V_86 * V_87 = F_55 ( V_78 ) ;
struct V_9 * V_10 = F_34 ( V_29 ) ;
int V_11 = V_87 -> V_82 ;
unsigned long V_3 ;
int V_92 ;
T_1 V_93 ;
if ( F_48 ( V_79 , 10 , & V_3 ) < 0 )
return - V_84 ;
F_35 ( & V_10 -> V_30 ) ;
V_93 = F_25 ( V_10 , V_55 ) ;
V_92 = F_63 ( V_10 -> V_44 [ V_11 ] [ 1 ] , F_64 ( V_10 -> V_56 [ V_11 ] ) ) ;
switch ( V_11 ) {
case 0 :
case 1 :
V_10 -> V_56 [ V_11 ] = F_24 ( V_3 ) ;
break;
case 2 :
if ( V_3 < 8 )
V_10 -> V_56 [ V_11 ] = 1 ;
else
V_10 -> V_56 [ V_11 ] = 3 ;
}
V_3 = V_93 & 0x80 ;
V_3 |= ( V_10 -> V_56 [ 0 ] & 0x07 ) ;
V_3 |= ( V_10 -> V_56 [ 1 ] & 0x07 ) << 3 ;
if ( V_10 -> V_56 [ 2 ] == 3 )
V_3 |= 0x1 << 6 ;
F_28 ( V_10 , V_55 , V_3 ) ;
V_10 -> V_44 [ V_11 ] [ 1 ] = F_19 ( V_92 , F_64 ( V_10 -> V_56 [ V_11 ] ) ) ;
F_28 ( V_10 , V_45 [ V_11 ] , V_10 -> V_44 [ V_11 ] [ 1 ] ) ;
F_44 ( & V_10 -> V_30 ) ;
return V_83 ;
}
static int F_72 ( struct V_28 * V_29 , int V_11 )
{
const struct V_9 * V_10 = F_34 ( V_29 ) ;
int V_25 , V_94 = 0 ;
if ( F_30 ( V_10 ) ) {
for ( V_25 = 0 ; V_25 < 3 ; V_25 ++ ) {
if ( V_10 -> V_26 [ V_11 ] [ V_25 ] > V_10 -> V_26 [ V_11 ] [ V_25 + 1 ] )
V_94 = - V_84 ;
}
for ( V_25 = 0 ; V_25 < 2 ; V_25 ++ ) {
if ( V_10 -> V_27 [ V_11 ] [ V_25 ] > V_10 -> V_27 [ V_11 ] [ V_25 + 1 ] )
V_94 = - V_84 ;
}
} else if ( F_22 ( V_10 ) ) {
for ( V_25 = 1 ; V_25 < 3 ; V_25 ++ ) {
if ( V_10 -> V_26 [ V_11 ] [ V_25 ] > V_10 -> V_26 [ V_11 ] [ V_25 + 1 ] )
V_94 = - V_84 ;
}
}
if ( V_94 ) {
F_73 ( V_29 ,
L_9 ) ;
F_73 ( V_29 , L_10 ) ;
}
return V_94 ;
}
static T_3 F_74 ( struct V_28 * V_29 , struct V_77 * V_78 ,
const char * V_79 , T_4 V_83 )
{
struct V_86 * V_87 = F_55 ( V_78 ) ;
struct V_9 * V_10 = F_34 ( V_29 ) ;
int V_11 = V_87 -> V_82 ;
long V_3 ;
if ( F_52 ( V_79 , 10 , & V_3 ) < 0 || V_3 < 0 || V_3 > 2 )
return - V_84 ;
if ( V_3 == 2 ) {
if ( F_72 ( V_29 , V_11 ) < 0 )
return - V_84 ;
}
F_35 ( & V_10 -> V_30 ) ;
if ( V_3 == 0 ) {
if ( V_11 < 3 && V_10 -> type != V_88 ) {
int V_95 ;
V_95 = F_25 ( V_10 , V_66 ) ;
F_28 ( V_10 , V_66 , V_95 | F_14 ( V_11 ) ) ;
V_10 -> V_63 &= ~ F_14 ( V_11 ) ;
F_28 ( V_10 , V_64 ,
V_10 -> V_63 ) ;
} else {
T_1 V_96 ;
V_10 -> V_23 [ V_11 ] = F_21 ( V_10 , 0xff ) ;
F_28 ( V_10 , V_24 [ V_11 ] ,
V_10 -> V_23 [ V_11 ] ) ;
if ( F_22 ( V_10 ) ) {
V_96 = ( V_10 -> V_20 [ V_11 ] & 0x7c ) |
V_10 -> V_22 [ V_11 ] ;
} else {
V_96 = V_10 -> V_23 [ V_11 ] ;
}
V_10 -> V_20 [ V_11 ] = V_96 ;
F_28 ( V_10 , V_21 [ V_11 ] , V_96 ) ;
}
} else {
T_1 V_96 ;
if ( F_22 ( V_10 ) ) {
V_96 = ( V_10 -> V_20 [ V_11 ] & 0x7c ) |
V_10 -> V_22 [ V_11 ] ;
if ( V_3 != 1 )
V_96 |= 0x80 ;
} else {
V_96 = ( V_3 == 1 ? V_10 -> V_23 [ V_11 ] : 0x80 ) ;
}
V_10 -> V_20 [ V_11 ] = V_96 ;
F_28 ( V_10 , V_21 [ V_11 ] , V_96 ) ;
if ( V_10 -> type != V_88 && V_11 < 3 ) {
V_10 -> V_63 |= F_14 ( V_11 ) ;
F_28 ( V_10 , V_64 ,
V_10 -> V_63 ) ;
}
}
F_44 ( & V_10 -> V_30 ) ;
return V_83 ;
}
static T_3 F_75 ( struct V_28 * V_29 , struct V_77 * V_78 ,
const char * V_79 , T_4 V_83 )
{
struct V_86 * V_87 = F_55 ( V_78 ) ;
struct V_9 * V_10 = F_34 ( V_29 ) ;
int V_11 = V_87 -> V_82 ;
long V_3 ;
if ( F_52 ( V_79 , 10 , & V_3 ) < 0 || V_3 < 0 || V_3 > 255 )
return - V_84 ;
F_35 ( & V_10 -> V_30 ) ;
F_29 ( V_10 , V_11 ) ;
if ( F_22 ( V_10 ) ) {
if ( V_10 -> V_20 [ V_11 ] & 0x80 ) {
F_44 ( & V_10 -> V_30 ) ;
return - V_7 ;
}
V_10 -> V_23 [ V_11 ] = F_21 ( V_10 , V_3 ) ;
F_28 ( V_10 , V_24 [ V_11 ] ,
V_10 -> V_23 [ V_11 ] ) ;
} else {
V_10 -> V_23 [ V_11 ] = F_21 ( V_10 , V_3 ) ;
if ( ! ( V_10 -> V_20 [ V_11 ] & 0x80 ) ) {
V_10 -> V_20 [ V_11 ] = V_10 -> V_23 [ V_11 ] ;
F_28 ( V_10 , V_21 [ V_11 ] ,
V_10 -> V_20 [ V_11 ] ) ;
}
}
F_44 ( & V_10 -> V_30 ) ;
return V_83 ;
}
static T_3 F_76 ( struct V_28 * V_29 , struct V_77 * V_78 ,
const char * V_79 , T_4 V_83 )
{
struct V_86 * V_87 = F_55 ( V_78 ) ;
struct V_9 * V_10 = F_34 ( V_29 ) ;
int V_11 = V_87 -> V_82 ;
unsigned long V_3 ;
int V_25 ;
if ( F_48 ( V_79 , 10 , & V_3 ) < 0 )
return - V_84 ;
V_3 = F_17 ( V_3 , 0 , 1000000 ) ;
V_3 *= F_22 ( V_10 ) ? 256 : 128 ;
for ( V_25 = 0 ; V_25 < 7 ; V_25 ++ ) {
if ( V_3 > ( V_91 [ V_25 ] + V_91 [ V_25 + 1 ] ) / 2 )
break;
}
F_35 ( & V_10 -> V_30 ) ;
if ( V_11 == 0 ) {
V_10 -> V_65 = F_25 ( V_10 , V_66 ) & 0x8f ;
V_10 -> V_65 |= V_25 << 4 ;
F_28 ( V_10 , V_66 , V_10 -> V_65 ) ;
} else {
V_10 -> V_71 = F_25 ( V_10 , V_72 ) & 0x8f ;
V_10 -> V_71 |= V_25 << 4 ;
F_28 ( V_10 , V_72 , V_10 -> V_71 ) ;
}
F_44 ( & V_10 -> V_30 ) ;
return V_83 ;
}
static T_3 F_77 ( struct V_28 * V_29 ,
struct V_77 * V_78 , char * V_79 )
{
struct V_86 * V_87 = F_55 ( V_78 ) ;
struct V_9 * V_10 = F_33 ( V_29 ) ;
int V_11 = V_87 -> V_82 ;
int V_97 ;
V_97 = V_10 -> V_22 [ V_11 ] ;
if ( V_97 >= 3 )
V_97 = 0 ;
if ( V_11 >= 3 )
V_97 += 3 ;
return sprintf ( V_79 , L_1 , ( int ) F_14 ( V_97 ) ) ;
}
static T_3 F_78 ( struct V_28 * V_29 ,
struct V_77 * V_78 , const char * V_79 ,
T_4 V_83 )
{
struct V_86 * V_87 = F_55 ( V_78 ) ;
struct V_9 * V_10 = F_34 ( V_29 ) ;
int V_11 = V_87 -> V_82 ;
long V_3 ;
T_1 V_2 ;
if ( F_52 ( V_79 , 10 , & V_3 ) < 0 )
return - V_84 ;
if ( V_11 >= 3 )
V_3 -= 3 ;
switch ( V_3 ) {
case F_14 ( 0 ) :
V_2 = 0x00 ;
break;
case F_14 ( 1 ) :
V_2 = 0x01 ;
break;
case F_14 ( 2 ) :
V_2 = 0x02 ;
break;
default:
return - V_84 ;
}
F_35 ( & V_10 -> V_30 ) ;
F_29 ( V_10 , V_11 ) ;
V_10 -> V_22 [ V_11 ] = V_2 ;
if ( V_10 -> V_20 [ V_11 ] & 0x80 ) {
V_10 -> V_20 [ V_11 ] = ( V_10 -> V_20 [ V_11 ] & 0xfc ) |
V_10 -> V_22 [ V_11 ] ;
F_28 ( V_10 , V_21 [ V_11 ] , V_10 -> V_20 [ V_11 ] ) ;
}
F_44 ( & V_10 -> V_30 ) ;
return V_83 ;
}
static T_3 F_79 ( struct V_28 * V_29 , struct V_77 * V_78 ,
char * V_79 )
{
struct V_9 * V_10 = F_33 ( V_29 ) ;
struct V_80 * V_87 =
F_46 ( V_78 ) ;
int V_11 = V_87 -> V_11 ;
int V_98 = V_87 -> V_82 ;
return sprintf ( V_79 , L_1 ,
F_23 ( V_10 , V_10 -> V_27 [ V_11 ] [ V_98 ] ) ) ;
}
static T_3 F_80 ( struct V_28 * V_29 , struct V_77 * V_78 ,
const char * V_79 , T_4 V_83 )
{
struct V_9 * V_10 = F_34 ( V_29 ) ;
struct V_80 * V_87 =
F_46 ( V_78 ) ;
int V_11 = V_87 -> V_11 ;
int V_98 = V_87 -> V_82 ;
int V_99 ;
long V_3 ;
if ( F_52 ( V_79 , 10 , & V_3 ) < 0 || V_3 < 0 || V_3 > 255 )
return - V_84 ;
F_35 ( & V_10 -> V_30 ) ;
V_10 -> V_27 [ V_11 ] [ V_98 ] = F_21 ( V_10 , V_3 ) ;
if ( F_22 ( V_10 ) )
V_99 = F_31 ( V_11 , 3 ) ;
else
V_99 = F_32 ( V_11 , V_98 ) ;
F_28 ( V_10 , V_99 , V_10 -> V_27 [ V_11 ] [ V_98 ] ) ;
F_44 ( & V_10 -> V_30 ) ;
return V_83 ;
}
static T_3 F_81 ( struct V_28 * V_29 ,
struct V_77 * V_78 , char * V_79 )
{
struct V_9 * V_10 = F_33 ( V_29 ) ;
struct V_86 * V_87 = F_55 ( V_78 ) ;
int V_11 = V_87 -> V_82 ;
return sprintf ( V_79 , L_1 , V_10 -> V_27 [ V_11 ] [ 1 ] & 0x7f ) ;
}
static T_3 F_82 ( struct V_28 * V_29 ,
struct V_77 * V_78 ,
const char * V_79 , T_4 V_83 )
{
struct V_9 * V_10 = F_34 ( V_29 ) ;
struct V_86 * V_87 = F_55 ( V_78 ) ;
int V_11 = V_87 -> V_82 ;
unsigned long V_3 ;
if ( F_48 ( V_79 , 10 , & V_3 ) < 0 || V_3 > 127 )
return - V_84 ;
F_35 ( & V_10 -> V_30 ) ;
V_10 -> V_27 [ V_11 ] [ 1 ] = ( V_10 -> V_27 [ V_11 ] [ 1 ] & 0x80 ) | V_3 ;
F_28 ( V_10 , F_31 ( V_11 , 4 ) ,
V_10 -> V_27 [ V_11 ] [ 1 ] ) ;
F_44 ( & V_10 -> V_30 ) ;
return V_83 ;
}
static T_3 F_83 ( struct V_28 * V_29 , struct V_77 * V_78 ,
char * V_79 )
{
struct V_9 * V_10 = F_33 ( V_29 ) ;
struct V_80 * V_87 =
F_46 ( V_78 ) ;
int V_11 = V_87 -> V_11 ;
int V_98 = V_87 -> V_82 ;
int V_2 ;
if ( F_30 ( V_10 ) || V_98 )
V_2 = V_10 -> V_26 [ V_11 ] [ V_98 ] ;
else
V_2 = V_10 -> V_26 [ V_11 ] [ 1 ] - ( V_10 -> V_26 [ V_11 ] [ 0 ] & 0x1f ) ;
return sprintf ( V_79 , L_1 , F_50 ( V_2 ) ) ;
}
static T_3 F_84 ( struct V_28 * V_29 , struct V_77 * V_78 ,
const char * V_79 , T_4 V_83 )
{
struct V_9 * V_10 = F_34 ( V_29 ) ;
struct V_80 * V_87 =
F_46 ( V_78 ) ;
int V_11 = V_87 -> V_11 ;
int V_98 = V_87 -> V_82 ;
long V_3 ;
int V_2 ;
if ( F_52 ( V_79 , 10 , & V_3 ) < 0 || V_3 < - 128000 || V_3 > 127000 )
return - V_84 ;
F_35 ( & V_10 -> V_30 ) ;
if ( F_22 ( V_10 ) && ! V_98 ) {
V_2 = V_10 -> V_26 [ V_11 ] [ 1 ] - F_53 ( V_3 ) ;
V_2 = F_17 ( V_2 , 0 , 0x1f ) | ( V_10 -> V_26 [ V_11 ] [ 0 ] & 0xe0 ) ;
V_10 -> V_26 [ V_11 ] [ 0 ] = V_2 ;
F_28 ( V_10 , F_31 ( V_11 , 5 ) , V_2 ) ;
} else {
V_2 = F_53 ( V_3 ) ;
V_10 -> V_26 [ V_11 ] [ V_98 ] = V_2 ;
if ( F_22 ( V_10 ) )
V_98 -- ;
F_28 ( V_10 , F_31 ( V_11 , V_98 ) , V_2 ) ;
}
F_44 ( & V_10 -> V_30 ) ;
return V_83 ;
}
static T_3 F_85 ( struct V_28 * V_29 , struct V_77 * V_78 ,
char * V_79 )
{
struct V_9 * V_10 = F_33 ( V_29 ) ;
return sprintf ( V_79 , L_8 , V_10 -> V_57 ) ;
}
static T_3 F_86 ( struct V_28 * V_29 , struct V_77 * V_78 ,
char * V_79 )
{
struct V_9 * V_10 = F_33 ( V_29 ) ;
int V_100 = F_55 ( V_78 ) -> V_82 ;
return sprintf ( V_79 , L_8 , ( V_10 -> V_57 >> V_100 ) & 1 ) ;
}
static T_3 F_87 ( struct V_28 * V_29 ,
struct V_77 * V_78 , const char * V_79 ,
T_4 V_83 )
{
struct V_9 * V_10 = F_34 ( V_29 ) ;
int V_101 ;
long V_3 ;
if ( F_52 ( V_79 , 10 , & V_3 ) < 0 || V_3 != 0 )
return - V_84 ;
F_35 ( & V_10 -> V_30 ) ;
V_101 = F_25 ( V_10 , V_36 ) ;
if ( V_101 < 0 ) {
V_83 = V_101 ;
} else {
V_101 |= F_14 ( 5 ) ;
F_28 ( V_10 , V_36 , V_101 ) ;
V_10 -> V_34 = 0 ;
}
F_44 ( & V_10 -> V_30 ) ;
return V_83 ;
}
static T_3 F_88 ( struct V_28 * V_29 , struct V_77 * V_78 ,
char * V_79 )
{
struct V_9 * V_10 = F_33 ( V_29 ) ;
int V_100 = F_55 ( V_78 ) -> V_82 ;
return sprintf ( V_79 , L_8 , ( V_10 -> V_61 >> V_100 ) & 1 ) ;
}
static T_3 F_89 ( struct V_28 * V_29 , struct V_77 * V_78 ,
const char * V_79 , T_4 V_83 )
{
int V_100 = F_55 ( V_78 ) -> V_82 ;
struct V_9 * V_10 = F_34 ( V_29 ) ;
long V_3 ;
if ( F_52 ( V_79 , 10 , & V_3 ) < 0 || ( V_3 != 0 && V_3 != 1 ) )
return - V_84 ;
F_35 ( & V_10 -> V_30 ) ;
V_10 -> V_61 = F_25 ( V_10 , V_62 ) ;
if ( V_3 )
V_10 -> V_61 |= F_14 ( V_100 ) ;
else
V_10 -> V_61 &= ~ F_14 ( V_100 ) ;
F_28 ( V_10 , V_62 , V_10 -> V_61 ) ;
F_44 ( & V_10 -> V_30 ) ;
return V_83 ;
}
static T_3 F_90 ( struct V_28 * V_29 , struct V_77 * V_78 ,
char * V_79 )
{
struct V_9 * V_10 = F_34 ( V_29 ) ;
return sprintf ( V_79 , L_8 , V_10 -> V_102 ) ;
}
static T_3 F_91 ( struct V_28 * V_29 , struct V_77 * V_78 ,
const char * V_79 , T_4 V_83 )
{
struct V_9 * V_10 = F_34 ( V_29 ) ;
unsigned long V_3 ;
if ( F_48 ( V_79 , 10 , & V_3 ) < 0 )
return - V_84 ;
V_10 -> V_102 = V_3 ;
return V_83 ;
}
static T_3 F_92 ( struct V_28 * V_29 ,
struct V_77 * V_78 , char * V_79 )
{
struct V_9 * V_10 = F_33 ( V_29 ) ;
return sprintf ( V_79 , L_11 , ( long ) F_93 ( V_10 -> V_75 , V_10 -> V_102 ) ) ;
}
static T_3 F_94 ( struct V_28 * V_29 , struct V_77 * V_78 ,
char * V_79 )
{
static const char * const V_103 [] = {
L_12 ,
L_13 ,
L_14 ,
L_15 ,
} ;
static const char * const V_104 [] = {
L_16 ,
L_17 ,
L_14 ,
L_16 ,
} ;
struct V_9 * V_10 = F_34 ( V_29 ) ;
int V_11 = F_55 ( V_78 ) -> V_82 ;
const char * V_105 ;
if ( F_95 ( V_10 ) && V_11 == 0 )
V_105 = V_103 [ 0 ] ;
else if ( F_12 ( V_10 ) || F_13 ( V_10 ) )
V_105 = V_104 [ V_11 ] ;
else
V_105 = V_103 [ V_11 ] ;
return sprintf ( V_79 , L_18 , V_105 ) ;
}
static T_5 F_96 ( struct V_106 * V_107 ,
struct V_108 * V_78 , int V_82 )
{
struct V_28 * V_29 = F_97 ( V_107 , struct V_28 , V_107 ) ;
struct V_9 * V_10 = F_34 ( V_29 ) ;
int V_25 = V_82 / 5 ;
int V_109 = V_82 % 5 ;
if ( V_82 >= 40 ) {
V_25 = V_82 - 40 + 8 ;
V_109 = 0 ;
}
if ( ! ( V_10 -> V_38 & F_14 ( V_25 ) ) )
return 0 ;
if ( V_109 == 4 && ! V_10 -> V_110 )
return 0 ;
return V_78 -> V_111 ;
}
static T_5 F_98 ( struct V_106 * V_107 ,
struct V_108 * V_78 , int V_82 )
{
struct V_28 * V_29 = F_97 ( V_107 , struct V_28 , V_107 ) ;
struct V_9 * V_10 = F_34 ( V_29 ) ;
int V_25 = V_82 / 7 ;
int V_109 = V_82 % 7 ;
if ( V_82 >= 21 ) {
V_25 = V_82 - 21 + 3 ;
V_109 = 0 ;
}
if ( ! ( V_10 -> V_50 & F_14 ( V_25 ) ) )
return 0 ;
if ( V_109 == 5 && ! F_41 ( V_10 ) )
return 0 ;
if ( V_109 == 6 && ! V_10 -> V_110 )
return 0 ;
return V_78 -> V_111 ;
}
static T_5 F_99 ( struct V_106 * V_107 ,
struct V_108 * V_78 , int V_82 )
{
struct V_28 * V_29 = F_97 ( V_107 , struct V_28 , V_107 ) ;
struct V_9 * V_10 = F_34 ( V_29 ) ;
if ( ( V_82 == 2 || V_82 == 3 ) && ! V_10 -> V_112 )
return 0 ;
if ( V_82 > 3 && ! ( V_10 -> V_113 & F_14 ( V_82 - 4 ) ) )
return 0 ;
return V_78 -> V_111 ;
}
static T_5 F_100 ( struct V_106 * V_107 ,
struct V_108 * V_78 , int V_82 )
{
struct V_28 * V_29 = F_97 ( V_107 , struct V_28 , V_107 ) ;
struct V_9 * V_10 = F_34 ( V_29 ) ;
int V_25 = V_82 / 5 ;
int V_109 = V_82 % 5 ;
if ( V_82 >= 15 ) {
V_25 = ( V_82 - 15 ) / 4 + 3 ;
V_109 = ( V_82 - 15 ) % 4 ;
}
if ( ! ( V_10 -> V_43 & F_14 ( V_25 ) ) )
return 0 ;
if ( V_109 == 3 ) {
if ( ! V_10 -> V_110 )
return 0 ;
if ( V_25 == F_101 ( V_10 -> V_43 ) )
return V_78 -> V_111 | V_114 ;
}
if ( V_109 == 4 && F_39 ( V_10 ) )
return 0 ;
return V_78 -> V_111 ;
}
static T_5 F_102 ( struct V_106 * V_107 ,
struct V_108 * V_78 , int V_82 )
{
struct V_28 * V_29 = F_97 ( V_107 , struct V_28 , V_107 ) ;
struct V_9 * V_10 = F_34 ( V_29 ) ;
int V_25 = V_82 / 4 ;
int V_109 = V_82 % 4 ;
if ( ! ( V_10 -> V_68 & F_14 ( V_25 ) ) )
return 0 ;
if ( V_109 == 3 && ( F_30 ( V_10 ) || F_22 ( V_10 ) ) )
return V_78 -> V_111 | V_114 ;
if ( F_69 ( V_10 ) && V_25 == 1 && V_109 == 2 )
return V_78 -> V_111 | V_114 ;
return V_78 -> V_111 ;
}
static T_5 F_103 ( struct V_106 * V_107 ,
struct V_108 * V_78 , int V_82 )
{
struct V_28 * V_29 = F_97 ( V_107 , struct V_28 , V_107 ) ;
struct V_9 * V_10 = F_34 ( V_29 ) ;
int V_25 = V_82 / 11 ;
int V_109 = V_82 % 11 ;
if ( V_82 >= 33 ) {
V_25 = ( V_82 - 33 ) / 6 + 3 ;
V_109 = ( V_82 - 33 ) % 6 + 4 ;
}
if ( ! ( V_10 -> V_68 & F_14 ( V_25 ) ) )
return 0 ;
if ( F_22 ( V_10 ) ) {
if ( V_109 < 4 )
return 0 ;
if ( V_109 == 8 )
return 0 ;
}
if ( F_30 ( V_10 ) ) {
if ( V_109 >= 9 )
return 0 ;
}
return V_78 -> V_111 ;
}
static int T_6 F_104 ( int V_115 , unsigned short * V_116 ,
struct V_117 * V_118 )
{
int V_94 ;
T_2 V_119 ;
const char * V_120 , * V_121 ;
const struct V_122 * V_101 ;
V_94 = F_7 ( V_115 ) ;
if ( V_94 )
return V_94 ;
V_94 = - V_123 ;
V_119 = V_124 ? V_124 : F_5 ( V_115 , V_125 ) ;
switch ( V_119 ) {
case V_126 :
V_118 -> type = V_127 ;
break;
case V_128 :
V_118 -> type = V_73 ;
break;
case V_129 :
case V_130 :
V_118 -> type = V_74 ;
break;
case V_131 :
V_118 -> type = V_132 ;
break;
case V_133 :
V_118 -> type = V_134 ;
break;
case V_135 :
V_118 -> type = V_136 ;
break;
case V_137 :
V_118 -> type = V_138 ;
break;
case V_139 :
V_118 -> type = V_140 ;
break;
case V_141 :
V_118 -> type = V_142 ;
break;
case V_143 :
V_118 -> type = V_144 ;
break;
case V_145 :
V_118 -> type = V_146 ;
break;
case V_147 :
V_118 -> type = V_148 ;
break;
case V_149 :
V_118 -> type = V_150 ;
break;
case V_151 :
V_118 -> type = V_152 ;
break;
case V_153 :
V_118 -> type = V_154 ;
break;
case V_155 :
V_118 -> type = V_156 ;
break;
case V_157 :
case V_158 :
V_118 -> type = V_88 ;
break;
case V_159 :
V_118 -> type = V_160 ;
break;
case V_161 :
V_118 -> type = V_162 ;
break;
case V_163 :
V_118 -> type = V_164 ;
break;
case 0xffff :
goto exit;
default:
F_105 ( L_19 , V_119 ) ;
goto exit;
}
F_6 ( V_115 , V_165 ) ;
if ( ! ( F_1 ( V_115 , V_166 ) & 0x01 ) ) {
F_106 ( L_20 ) ;
goto exit;
}
* V_116 = F_5 ( V_115 , V_167 ) & ~ ( V_168 - 1 ) ;
if ( * V_116 == 0 ) {
F_106 ( L_21 ) ;
goto exit;
}
V_94 = 0 ;
V_118 -> V_115 = V_115 ;
V_118 -> V_169 = F_1 ( V_115 , V_170 ) & 0x0f ;
F_106 ( L_22 , V_119 ,
V_122 [ V_118 -> type ] . V_171 ,
* V_116 , V_118 -> V_169 ) ;
V_101 = & V_122 [ V_118 -> type ] ;
if ( F_107 ( V_101 ) )
V_118 -> V_172 |= F_14 ( 1 ) ;
V_118 -> V_172 |= F_14 ( 2 ) ;
if ( F_108 ( V_101 ) )
V_118 -> V_172 |= F_14 ( 3 ) ;
else
V_118 -> V_173 |= F_14 ( 9 ) ;
if ( ! F_109 ( V_101 ) )
V_118 -> V_174 |= F_14 ( 3 ) | F_14 ( 4 ) | F_14 ( 5 ) ;
else if ( ! F_110 ( V_101 ) )
V_118 -> V_174 |= F_14 ( 5 ) ;
if ( ! V_112 ( V_101 ) )
V_118 -> V_175 = 1 ;
if ( V_118 -> type == V_127 ) {
F_6 ( V_115 , 5 ) ;
V_118 -> V_176 = F_1 ( V_115 ,
V_177 ) & 0x3f ;
} else if ( V_118 -> type == V_152 ) {
int V_178 , V_179 , V_180 , V_181 , V_182 ;
F_6 ( V_115 , V_183 ) ;
V_178 = F_1 ( V_115 , V_184 ) ;
V_179 = F_1 ( V_115 , V_185 ) ;
V_180 = F_1 ( V_115 , V_186 ) ;
V_181 = F_1 ( V_115 , V_187 ) ;
V_182 = F_1 ( V_115 , V_188 ) ;
if ( ( V_179 & F_14 ( 0 ) ) || ! ( V_181 & F_14 ( 2 ) ) )
V_118 -> V_189 |= F_14 ( 2 ) ;
if ( ( V_178 & F_14 ( 4 ) ) ||
( ! ( V_180 & F_14 ( 1 ) ) && ( V_182 & F_14 ( 0 ) ) ) )
V_118 -> V_174 |= F_14 ( 2 ) ;
if ( V_179 & F_14 ( 7 ) )
V_118 -> V_189 |= F_14 ( 1 ) ;
if ( V_179 & F_14 ( 3 ) )
V_118 -> V_174 |= F_14 ( 1 ) ;
if ( ( V_179 & F_14 ( 0 ) ) || ( V_181 & F_14 ( 2 ) ) )
V_118 -> V_173 |= F_14 ( 5 ) ;
if ( V_179 & F_14 ( 1 ) )
V_118 -> V_173 |= F_14 ( 6 ) ;
if ( V_179 & F_14 ( 2 ) ) {
if ( ! ( V_181 & F_14 ( 1 ) ) ) {
V_181 |= F_14 ( 1 ) ;
F_4 ( V_115 , V_187 ,
V_181 ) ;
V_118 -> V_190 = true ;
F_111 ( L_23 ) ;
}
F_111 ( L_24 ) ;
F_111 ( L_25 ) ;
}
if ( V_181 & F_14 ( 0 ) )
V_118 -> V_172 |= F_14 ( 0 ) ;
if ( V_181 & F_14 ( 1 ) )
V_118 -> V_172 |= F_14 ( 1 ) ;
V_118 -> V_176 = F_1 ( V_115 ,
V_177 ) & 0x3f ;
} else if ( V_118 -> type == V_88 ) {
int V_179 , V_191 ;
F_6 ( V_115 , V_183 ) ;
V_179 = F_1 ( V_115 , V_185 ) ;
if ( V_179 & F_14 ( 6 ) )
V_118 -> V_174 |= F_14 ( 2 ) ;
if ( V_179 & F_14 ( 7 ) )
V_118 -> V_189 |= F_14 ( 2 ) ;
V_191 = F_1 ( V_115 , V_192 ) ;
if ( V_191 & F_14 ( 1 ) )
V_118 -> V_174 |= F_14 ( 1 ) ;
if ( V_191 & F_14 ( 2 ) )
V_118 -> V_189 |= F_14 ( 1 ) ;
V_118 -> V_173 |= F_14 ( 5 ) ;
V_118 -> V_173 |= F_14 ( 6 ) ;
V_118 -> V_176 = F_1 ( V_115 ,
V_177 ) & 0x3f ;
} else if ( V_118 -> type == V_160 || V_118 -> type == V_164 ) {
int V_2 ;
F_6 ( V_115 , V_183 ) ;
V_2 = F_1 ( V_115 , V_184 ) ;
if ( V_2 & F_14 ( 6 ) )
V_118 -> V_174 |= F_14 ( 4 ) ;
V_2 = F_1 ( V_115 , V_193 ) ;
if ( ! ( V_2 & F_14 ( 5 ) ) )
V_118 -> V_189 |= F_14 ( 3 ) ;
if ( ! ( V_2 & F_14 ( 4 ) ) )
V_118 -> V_189 |= F_14 ( 4 ) ;
V_2 = F_1 ( V_115 , V_185 ) ;
if ( V_2 & F_14 ( 6 ) )
V_118 -> V_174 |= F_14 ( 2 ) ;
if ( V_2 & F_14 ( 7 ) )
V_118 -> V_189 |= F_14 ( 2 ) ;
V_2 = F_1 ( V_115 , V_194 ) ;
if ( V_2 & F_14 ( 2 ) )
V_118 -> V_174 |= F_14 ( 3 ) ;
V_2 = F_1 ( V_115 , V_192 ) ;
if ( V_2 & F_14 ( 1 ) )
V_118 -> V_174 |= F_14 ( 1 ) ;
if ( V_2 & F_14 ( 2 ) )
V_118 -> V_189 |= F_14 ( 1 ) ;
if ( ! ( V_2 & F_14 ( 7 ) ) ) {
V_118 -> V_174 |= F_14 ( 5 ) ;
V_118 -> V_189 |= F_14 ( 5 ) ;
}
V_2 = F_1 ( V_115 , V_187 ) ;
if ( V_2 & F_14 ( 0 ) )
V_118 -> V_172 |= F_14 ( 0 ) ;
else
V_118 -> V_173 |= F_14 ( 9 ) ;
V_118 -> V_176 = F_1 ( V_115 ,
V_177 ) & 0x3f ;
} else if ( V_118 -> type == V_162 ) {
int V_2 ;
F_6 ( V_115 , V_183 ) ;
V_2 = F_1 ( V_115 , V_184 ) ;
if ( V_2 & F_14 ( 6 ) )
V_118 -> V_189 |= F_14 ( 3 ) ;
if ( V_2 & F_14 ( 5 ) )
V_118 -> V_174 |= F_14 ( 3 ) ;
V_2 = F_1 ( V_115 , V_185 ) ;
if ( V_2 & F_14 ( 6 ) )
V_118 -> V_174 |= F_14 ( 2 ) ;
if ( V_2 & F_14 ( 7 ) )
V_118 -> V_189 |= F_14 ( 2 ) ;
if ( V_2 & F_14 ( 3 ) )
V_118 -> V_174 |= F_14 ( 4 ) ;
if ( V_2 & F_14 ( 1 ) )
V_118 -> V_189 |= F_14 ( 4 ) ;
V_2 = F_1 ( V_115 , V_192 ) ;
if ( V_2 & F_14 ( 1 ) )
V_118 -> V_174 |= F_14 ( 1 ) ;
if ( V_2 & F_14 ( 2 ) )
V_118 -> V_189 |= F_14 ( 1 ) ;
V_2 = F_1 ( V_115 , V_187 ) ;
if ( ! ( V_2 & F_14 ( 0 ) ) )
V_118 -> V_173 |= F_14 ( 9 ) ;
V_118 -> V_176 = F_1 ( V_115 ,
V_177 ) & 0x3f ;
} else {
int V_2 ;
bool V_195 ;
F_6 ( V_115 , V_183 ) ;
if ( F_112 ( V_101 ) ) {
V_2 = F_1 ( V_115 , V_193 ) ;
switch ( V_118 -> type ) {
case V_132 :
if ( V_2 & F_14 ( 5 ) )
V_118 -> V_189 |= F_14 ( 3 ) ;
if ( V_2 & F_14 ( 4 ) )
V_118 -> V_189 |= F_14 ( 4 ) ;
break;
case V_134 :
case V_136 :
case V_138 :
if ( ! ( V_2 & F_14 ( 5 ) ) )
V_118 -> V_189 |= F_14 ( 3 ) ;
if ( ! ( V_2 & F_14 ( 4 ) ) )
V_118 -> V_189 |= F_14 ( 4 ) ;
break;
default:
break;
}
}
V_2 = F_1 ( V_115 , V_185 ) ;
if ( ! V_118 -> V_175 ) {
if ( V_2 & 0x0f ) {
F_106 ( L_26 ) ;
V_118 -> V_175 = 1 ;
}
}
if ( V_2 & F_14 ( 6 ) )
V_118 -> V_174 |= F_14 ( 2 ) ;
if ( V_2 & F_14 ( 7 ) )
V_118 -> V_189 |= F_14 ( 2 ) ;
V_2 = F_1 ( V_115 , V_192 ) ;
if ( V_2 & F_14 ( 1 ) )
V_118 -> V_174 |= F_14 ( 1 ) ;
if ( V_2 & F_14 ( 2 ) )
V_118 -> V_189 |= F_14 ( 1 ) ;
if ( ( V_118 -> type == V_132 || V_118 -> type == V_134 ) &&
! ( V_118 -> V_175 ) )
V_118 -> V_196 = F_1 ( V_115 ,
V_197 ) ;
V_2 = F_1 ( V_115 , V_187 ) ;
V_195 = V_118 -> type == V_150 && ( V_2 & F_14 ( 2 ) ) ;
if ( ( V_118 -> type == V_134 || V_195 ) && ! ( V_2 & F_14 ( 1 ) ) ) {
V_2 |= F_14 ( 1 ) ;
F_4 ( V_115 , V_187 , V_2 ) ;
V_118 -> V_190 = true ;
F_111 ( L_27 ) ;
}
if ( V_2 & F_14 ( 0 ) )
V_118 -> V_172 |= F_14 ( 0 ) ;
if ( V_2 & F_14 ( 1 ) )
V_118 -> V_172 |= F_14 ( 1 ) ;
if ( V_195 ) {
V_118 -> V_173 |= F_14 ( 5 ) | F_14 ( 6 ) ;
V_118 -> V_198 |= F_14 ( 2 ) ;
}
V_118 -> V_176 = F_1 ( V_115 ,
V_177 ) & 0x3f ;
}
if ( V_118 -> V_176 )
F_106 ( L_28 ) ;
V_120 = F_113 ( V_199 ) ;
V_121 = F_113 ( V_200 ) ;
if ( V_120 && V_121 ) {
if ( strcmp ( V_120 , L_29 ) == 0 &&
strcmp ( V_121 , L_30 ) == 0 ) {
F_106 ( L_31 ) ;
V_118 -> V_174 = F_14 ( 1 ) ;
}
}
exit:
F_9 ( V_115 ) ;
return V_94 ;
}
static void F_114 ( struct V_9 * V_10 )
{
int V_25 , V_2 ;
for ( V_25 = 0 ; V_25 < V_41 ; V_25 ++ ) {
V_2 = F_25 ( V_10 , F_37 ( V_25 ) ) ;
if ( V_2 == 0xff )
F_28 ( V_10 , F_37 ( V_25 ) , 0 ) ;
}
for ( V_25 = 0 ; V_25 < V_54 ; V_25 ++ ) {
V_2 = F_25 ( V_10 , F_43 ( V_25 ) ) ;
if ( V_2 == 0xff )
F_28 ( V_10 , F_43 ( V_25 ) , 127 ) ;
}
}
static void F_115 ( struct V_9 * V_10 )
{
int V_2 ;
V_2 = F_25 ( V_10 , V_201 ) ;
if ( ( V_2 & 0xff ) == 0 ) {
F_28 ( V_10 , V_201 , 0xff ) ;
}
}
static void F_116 ( struct V_202 * V_203 )
{
struct V_117 * V_118 = F_117 ( & V_203 -> V_29 ) ;
struct V_9 * V_10 = F_118 ( V_203 ) ;
T_1 V_204 , V_63 ;
V_204 = 0x70 & ~ ( V_118 -> V_189 << 4 ) ;
V_63 = F_25 ( V_10 , V_64 ) ;
if ( ( V_63 & V_204 ) == 0 ) {
V_63 |= V_204 ;
F_28 ( V_10 , V_64 ,
V_63 ) ;
}
}
static void F_119 ( struct V_202 * V_203 )
{
struct V_9 * V_10 = F_118 ( V_203 ) ;
int V_2 ;
if ( ! F_120 ( V_10 ) )
return;
V_2 = F_25 ( V_10 , V_205 ) ;
if ( ~ V_2 & 0x07 & V_10 -> V_43 ) {
F_121 ( & V_203 -> V_29 ,
L_32 ) ;
F_28 ( V_10 , V_205 ,
V_2 | 0x07 ) ;
}
}
static void F_122 ( struct V_9 * V_10 )
{
F_28 ( V_10 , V_36 ,
( F_25 ( V_10 , V_36 ) & 0x3e )
| ( V_35 ? 0x41 : 0x01 ) ) ;
}
static void F_123 ( struct V_202 * V_203 )
{
struct V_117 * V_118 = F_117 ( & V_203 -> V_29 ) ;
struct V_9 * V_10 = F_118 ( V_203 ) ;
int V_95 , V_25 ;
for ( V_25 = 0 ; V_25 < V_206 ; V_25 ++ ) {
V_10 -> V_22 [ V_25 ] = V_25 ;
V_10 -> V_23 [ V_25 ] = 0x7f ;
V_10 -> V_27 [ V_25 ] [ 3 ] = 0x7f ;
}
F_114 ( V_10 ) ;
F_115 ( V_10 ) ;
F_116 ( V_203 ) ;
V_10 -> V_63 = F_25 ( V_10 , V_64 ) ;
V_10 -> V_43 = ( V_10 -> V_63 >> 4 ) & 0x07 ;
F_119 ( V_203 ) ;
if ( F_112 ( V_10 ) ) {
V_95 = F_25 ( V_10 , V_205 ) ;
if ( V_95 & F_14 ( 4 ) )
V_10 -> V_43 |= F_14 ( 3 ) ;
if ( V_95 & F_14 ( 5 ) )
V_10 -> V_43 |= F_14 ( 4 ) ;
if ( F_124 ( V_10 ) && ( V_95 & F_14 ( 2 ) ) )
V_10 -> V_43 |= F_14 ( 5 ) ;
}
V_10 -> V_43 &= ~ V_118 -> V_189 ;
if ( F_110 ( V_10 ) ) {
V_95 = F_25 ( V_10 , V_55 ) ;
if ( ( V_95 & 0xc0 ) == 0xc0 )
V_118 -> V_174 |= F_14 ( 4 ) ;
if ( ! ( V_95 & F_14 ( 3 ) ) )
V_118 -> V_174 |= F_14 ( 5 ) ;
}
F_122 ( V_10 ) ;
}
static int F_125 ( struct V_28 * V_29 )
{
struct V_9 * V_10 = F_34 ( V_29 ) ;
int V_95 = F_25 ( V_10 , V_66 ) ;
if ( ( V_95 & 0x87 ) == 0 ) {
if ( V_207 ) {
int V_25 ;
T_1 V_208 [ 3 ] ;
for ( V_25 = 0 ; V_25 < F_126 ( V_208 ) ; V_25 ++ )
V_208 [ V_25 ] = F_25 ( V_10 ,
V_21 [ V_25 ] ) ;
if ( ! ( ( V_208 [ 0 ] | V_208 [ 1 ] | V_208 [ 2 ] ) & 0x80 ) ) {
F_127 ( V_29 ,
L_33 ) ;
F_28 ( V_10 , V_66 ,
V_95 | 0x87 ) ;
for ( V_25 = 0 ; V_25 < 3 ; V_25 ++ )
F_28 ( V_10 ,
V_21 [ V_25 ] ,
0x7f & ~ V_208 [ V_25 ] ) ;
return 1 ;
}
F_127 ( V_29 ,
L_34 ) ;
}
return 0 ;
} else if ( V_207 ) {
F_127 ( V_29 ,
L_35 ) ;
}
return 1 ;
}
static int F_128 ( struct V_202 * V_203 )
{
struct V_9 * V_10 ;
struct V_209 * V_210 ;
struct V_28 * V_29 = & V_203 -> V_29 ;
struct V_117 * V_118 = F_117 ( V_29 ) ;
int V_211 ;
struct V_28 * V_212 ;
V_210 = F_129 ( V_203 , V_213 , 0 ) ;
if ( ! F_130 ( & V_203 -> V_29 , V_210 -> V_214 , V_215 ,
V_6 ) ) {
F_73 ( V_29 , L_36 ,
( unsigned long ) V_210 -> V_214 ,
( unsigned long ) ( V_210 -> V_214 + V_215 - 1 ) ) ;
return - V_7 ;
}
V_10 = F_131 ( & V_203 -> V_29 , sizeof( struct V_9 ) , V_216 ) ;
if ( ! V_10 )
return - V_217 ;
V_10 -> V_16 = V_210 -> V_214 ;
V_10 -> V_115 = V_118 -> V_115 ;
V_10 -> type = V_118 -> type ;
V_10 -> V_218 = V_122 [ V_118 -> type ] . V_218 ;
V_10 -> V_219 = V_122 [ V_118 -> type ] . V_219 ;
V_10 -> V_220 = V_122 [ V_118 -> type ] . V_220 ;
switch ( V_10 -> type ) {
case V_127 :
if ( V_118 -> V_169 >= 0x03 ) {
V_10 -> V_218 &= ~ V_221 ;
V_10 -> V_218 |= V_222 | V_223 ;
}
break;
case V_73 :
if ( V_118 -> V_169 >= 0x08 ) {
V_10 -> V_218 &= ~ V_221 ;
V_10 -> V_218 |= V_222 | V_223 |
V_224 ;
}
break;
default:
break;
}
if ( ( F_25 ( V_10 , V_36 ) & 0x80 ) ||
F_25 ( V_10 , V_225 ) != 0x90 )
return - V_123 ;
F_132 ( V_203 , V_10 ) ;
F_133 ( & V_10 -> V_30 ) ;
V_211 = F_125 ( V_29 ) ;
if ( ! V_211 )
F_127 ( V_29 ,
L_37 ) ;
if ( F_12 ( V_10 ) ) {
if ( V_118 -> V_172 & F_14 ( 0 ) )
V_10 -> V_13 |= F_14 ( 3 ) ;
if ( V_118 -> V_172 & F_14 ( 1 ) )
V_10 -> V_13 |= F_14 ( 7 ) ;
if ( V_118 -> V_172 & F_14 ( 2 ) )
V_10 -> V_13 |= F_14 ( 8 ) ;
if ( V_118 -> V_172 & F_14 ( 3 ) )
V_10 -> V_13 |= F_14 ( 9 ) ;
} else if ( V_118 -> type == V_148 || V_118 -> type == V_150 ||
V_118 -> type == V_152 ) {
if ( V_118 -> V_172 & F_14 ( 0 ) )
V_10 -> V_13 |= F_14 ( 3 ) ;
if ( V_118 -> V_172 & F_14 ( 1 ) )
V_10 -> V_13 |= F_14 ( 7 ) ;
}
V_10 -> V_50 = 0x07 ;
if ( V_118 -> V_198 & F_14 ( 2 ) ) {
if ( V_118 -> type == V_150 &&
! ( F_25 ( V_10 , V_72 ) & 0x80 ) )
V_10 -> V_50 &= ~ F_14 ( 2 ) ;
}
V_10 -> V_113 = V_118 -> V_172 ;
V_10 -> V_190 = V_118 -> V_190 ;
V_10 -> V_38 = 0x3ff & ~ V_118 -> V_173 ;
if ( F_134 ( V_10 ) ) {
T_1 V_2 = F_25 ( V_10 , V_226 ) ;
if ( ( V_2 & 0x03 ) >= 0x02 )
V_10 -> V_50 |= F_14 ( 3 ) ;
if ( ( ( V_2 >> 2 ) & 0x03 ) >= 0x02 )
V_10 -> V_50 |= F_14 ( 4 ) ;
if ( ( ( V_2 >> 4 ) & 0x03 ) >= 0x02 )
V_10 -> V_50 |= F_14 ( 5 ) ;
if ( ( V_2 & 0x03 ) == 0x01 )
V_10 -> V_38 |= F_14 ( 10 ) ;
if ( ( ( V_2 >> 2 ) & 0x03 ) == 0x01 )
V_10 -> V_38 |= F_14 ( 11 ) ;
if ( ( ( V_2 >> 4 ) & 0x03 ) == 0x01 )
V_10 -> V_38 |= F_14 ( 12 ) ;
}
V_10 -> V_110 = ! ! V_118 -> V_176 ;
F_123 ( V_203 ) ;
if ( ! V_118 -> V_175 ) {
V_10 -> V_112 = true ;
V_10 -> V_102 = F_135 () ;
V_10 -> V_75 = V_118 -> V_196 ;
}
V_10 -> V_227 [ 0 ] = & V_228 ;
V_10 -> V_227 [ 1 ] = & V_229 ;
V_10 -> V_227 [ 2 ] = & V_230 ;
V_10 -> V_227 [ 3 ] = & V_231 ;
if ( V_211 ) {
V_10 -> V_68 = F_14 ( F_126 ( V_21 ) ) - 1 ;
V_10 -> V_68 &= ~ V_118 -> V_174 ;
V_10 -> V_227 [ 4 ] = & V_232 ;
if ( F_30 ( V_10 ) || F_22 ( V_10 ) )
V_10 -> V_227 [ 5 ] = & V_233 ;
}
V_212 = F_136 ( V_29 ,
V_122 [ V_118 -> type ] . V_234 ,
V_10 , V_10 -> V_227 ) ;
return F_137 ( V_212 ) ;
}
static void T_7 F_138 ( struct V_202 * V_203 )
{
struct V_9 * V_10 = F_34 ( & V_203 -> V_29 ) ;
int V_94 ;
int V_181 ;
if ( ! V_10 -> V_190 )
return;
V_94 = F_7 ( V_10 -> V_115 ) ;
if ( V_94 ) {
F_59 ( & V_203 -> V_29 ,
L_38 ,
V_94 ) ;
return;
}
F_6 ( V_10 -> V_115 , V_183 ) ;
V_181 = F_1 ( V_10 -> V_115 , V_187 ) ;
if ( ! ( V_181 & F_14 ( 1 ) ) ) {
F_121 ( & V_203 -> V_29 ,
L_39 ) ;
V_181 |= F_14 ( 1 ) ;
F_4 ( V_10 -> V_115 , V_187 ,
V_181 ) ;
}
F_9 ( V_10 -> V_115 ) ;
}
static int T_7 F_139 ( struct V_28 * V_29 )
{
struct V_202 * V_203 = F_140 ( V_29 ) ;
struct V_9 * V_10 = F_34 ( V_29 ) ;
F_138 ( V_203 ) ;
F_35 ( & V_10 -> V_30 ) ;
F_125 ( V_29 ) ;
F_114 ( V_10 ) ;
F_115 ( V_10 ) ;
F_116 ( V_203 ) ;
F_119 ( V_203 ) ;
F_122 ( V_10 ) ;
V_10 -> V_34 = 0 ;
F_44 ( & V_10 -> V_30 ) ;
F_33 ( V_29 ) ;
return 0 ;
}
static int T_6 F_141 ( int V_82 , unsigned short V_116 ,
const struct V_117 * V_118 )
{
struct V_202 * V_203 ;
struct V_209 V_210 = {
. V_214 = V_116 + V_235 ,
. V_236 = V_116 + V_235 + V_215 - 1 ,
. V_234 = V_6 ,
. V_237 = V_213 ,
} ;
int V_94 ;
V_94 = F_142 ( & V_210 ) ;
if ( V_94 )
return V_94 ;
V_203 = F_143 ( V_6 , V_116 ) ;
if ( ! V_203 )
return - V_217 ;
V_94 = F_144 ( V_203 , & V_210 , 1 ) ;
if ( V_94 ) {
F_145 ( L_40 , V_94 ) ;
goto V_238;
}
V_94 = F_146 ( V_203 , V_118 ,
sizeof( struct V_117 ) ) ;
if ( V_94 ) {
F_145 ( L_41 ) ;
goto V_238;
}
V_94 = F_147 ( V_203 ) ;
if ( V_94 ) {
F_145 ( L_42 , V_94 ) ;
goto V_238;
}
V_239 [ V_82 ] = V_203 ;
return 0 ;
V_238:
F_148 ( V_203 ) ;
return V_94 ;
}
static int T_6 F_149 ( void )
{
int V_115 [ 2 ] = { V_240 , V_8 } ;
struct V_117 V_118 ;
unsigned short V_241 [ 2 ] ;
bool V_242 = false ;
int V_25 , V_94 ;
V_94 = F_150 ( & V_243 ) ;
if ( V_94 )
return V_94 ;
for ( V_25 = 0 ; V_25 < F_126 ( V_115 ) ; V_25 ++ ) {
memset ( & V_118 , 0 , sizeof( struct V_117 ) ) ;
V_241 [ V_25 ] = 0 ;
V_94 = F_104 ( V_115 [ V_25 ] , & V_241 [ V_25 ] , & V_118 ) ;
if ( V_94 || V_241 [ V_25 ] == 0 )
continue;
if ( V_25 && V_241 [ V_25 ] == V_241 [ 0 ] )
break;
V_94 = F_141 ( V_25 , V_241 [ V_25 ] , & V_118 ) ;
if ( V_94 )
goto V_244;
V_242 = true ;
if ( V_118 . type == V_127 )
break;
}
if ( ! V_242 ) {
V_94 = - V_123 ;
goto V_245;
}
return 0 ;
V_244:
F_151 ( V_239 [ 0 ] ) ;
V_245:
F_152 ( & V_243 ) ;
return V_94 ;
}
static void T_8 F_153 ( void )
{
F_151 ( V_239 [ 1 ] ) ;
F_151 ( V_239 [ 0 ] ) ;
F_152 ( & V_243 ) ;
}
