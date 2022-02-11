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
V_10 -> V_23 [ V_11 ] = F_21 ( V_10 , 0xff ) ;
F_28 ( V_10 , V_24 [ V_11 ] ,
V_10 -> V_23 [ V_11 ] ) ;
V_10 -> V_20 [ V_11 ] = F_22 ( V_10 ) ?
V_10 -> V_22 [ V_11 ] :
V_10 -> V_23 [ V_11 ] ;
F_28 ( V_10 , V_21 [ V_11 ] ,
V_10 -> V_20 [ V_11 ] ) ;
}
} else {
if ( V_3 == 1 )
V_10 -> V_20 [ V_11 ] = F_22 ( V_10 ) ?
V_10 -> V_22 [ V_11 ] :
V_10 -> V_23 [ V_11 ] ;
else
V_10 -> V_20 [ V_11 ] = 0x80 | V_10 -> V_22 [ V_11 ] ;
F_28 ( V_10 , V_21 [ V_11 ] , V_10 -> V_20 [ V_11 ] ) ;
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
int V_96 ;
V_96 = V_10 -> V_22 [ V_11 ] ;
if ( V_96 >= 3 )
V_96 = 0 ;
if ( V_11 >= 3 )
V_96 += 3 ;
return sprintf ( V_79 , L_1 , ( int ) F_14 ( V_96 ) ) ;
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
V_10 -> V_22 [ V_11 ] = V_2 ;
if ( V_10 -> V_20 [ V_11 ] & 0x80 ) {
V_10 -> V_20 [ V_11 ] = 0x80 | V_10 -> V_22 [ V_11 ] ;
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
int V_97 = V_87 -> V_82 ;
return sprintf ( V_79 , L_1 ,
F_23 ( V_10 , V_10 -> V_27 [ V_11 ] [ V_97 ] ) ) ;
}
static T_3 F_80 ( struct V_28 * V_29 , struct V_77 * V_78 ,
const char * V_79 , T_4 V_83 )
{
struct V_9 * V_10 = F_34 ( V_29 ) ;
struct V_80 * V_87 =
F_46 ( V_78 ) ;
int V_11 = V_87 -> V_11 ;
int V_97 = V_87 -> V_82 ;
int V_98 ;
long V_3 ;
if ( F_52 ( V_79 , 10 , & V_3 ) < 0 || V_3 < 0 || V_3 > 255 )
return - V_84 ;
F_35 ( & V_10 -> V_30 ) ;
V_10 -> V_27 [ V_11 ] [ V_97 ] = F_21 ( V_10 , V_3 ) ;
if ( F_22 ( V_10 ) )
V_98 = F_31 ( V_11 , 3 ) ;
else
V_98 = F_32 ( V_11 , V_97 ) ;
F_28 ( V_10 , V_98 , V_10 -> V_27 [ V_11 ] [ V_97 ] ) ;
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
int V_97 = V_87 -> V_82 ;
int V_2 ;
if ( F_30 ( V_10 ) || V_97 )
V_2 = V_10 -> V_26 [ V_11 ] [ V_97 ] ;
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
int V_97 = V_87 -> V_82 ;
long V_3 ;
int V_2 ;
if ( F_52 ( V_79 , 10 , & V_3 ) < 0 || V_3 < - 128000 || V_3 > 127000 )
return - V_84 ;
F_35 ( & V_10 -> V_30 ) ;
if ( F_22 ( V_10 ) && ! V_97 ) {
V_2 = V_10 -> V_26 [ V_11 ] [ 1 ] - F_53 ( V_3 ) ;
V_2 = F_17 ( V_2 , 0 , 0x1f ) | ( V_10 -> V_26 [ V_11 ] [ 0 ] & 0xe0 ) ;
V_10 -> V_26 [ V_11 ] [ 0 ] = V_2 ;
F_28 ( V_10 , F_31 ( V_11 , 5 ) , V_2 ) ;
} else {
V_2 = F_53 ( V_3 ) ;
V_10 -> V_26 [ V_11 ] [ V_97 ] = V_2 ;
if ( F_22 ( V_10 ) )
V_97 -- ;
F_28 ( V_10 , F_31 ( V_11 , V_97 ) , V_2 ) ;
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
int V_99 = F_55 ( V_78 ) -> V_82 ;
return sprintf ( V_79 , L_8 , ( V_10 -> V_57 >> V_99 ) & 1 ) ;
}
static T_3 F_87 ( struct V_28 * V_29 ,
struct V_77 * V_78 , const char * V_79 ,
T_4 V_83 )
{
struct V_9 * V_10 = F_34 ( V_29 ) ;
int V_100 ;
long V_3 ;
if ( F_52 ( V_79 , 10 , & V_3 ) < 0 || V_3 != 0 )
return - V_84 ;
F_35 ( & V_10 -> V_30 ) ;
V_100 = F_25 ( V_10 , V_36 ) ;
if ( V_100 < 0 ) {
V_83 = V_100 ;
} else {
V_100 |= F_14 ( 5 ) ;
F_28 ( V_10 , V_36 , V_100 ) ;
V_10 -> V_34 = 0 ;
}
F_44 ( & V_10 -> V_30 ) ;
return V_83 ;
}
static T_3 F_88 ( struct V_28 * V_29 , struct V_77 * V_78 ,
char * V_79 )
{
struct V_9 * V_10 = F_33 ( V_29 ) ;
int V_99 = F_55 ( V_78 ) -> V_82 ;
return sprintf ( V_79 , L_8 , ( V_10 -> V_61 >> V_99 ) & 1 ) ;
}
static T_3 F_89 ( struct V_28 * V_29 , struct V_77 * V_78 ,
const char * V_79 , T_4 V_83 )
{
int V_99 = F_55 ( V_78 ) -> V_82 ;
struct V_9 * V_10 = F_34 ( V_29 ) ;
long V_3 ;
if ( F_52 ( V_79 , 10 , & V_3 ) < 0 || ( V_3 != 0 && V_3 != 1 ) )
return - V_84 ;
F_35 ( & V_10 -> V_30 ) ;
V_10 -> V_61 = F_25 ( V_10 , V_62 ) ;
if ( V_3 )
V_10 -> V_61 |= F_14 ( V_99 ) ;
else
V_10 -> V_61 &= ~ F_14 ( V_99 ) ;
F_28 ( V_10 , V_62 , V_10 -> V_61 ) ;
F_44 ( & V_10 -> V_30 ) ;
return V_83 ;
}
static T_3 F_90 ( struct V_28 * V_29 , struct V_77 * V_78 ,
char * V_79 )
{
struct V_9 * V_10 = F_34 ( V_29 ) ;
return sprintf ( V_79 , L_8 , V_10 -> V_101 ) ;
}
static T_3 F_91 ( struct V_28 * V_29 , struct V_77 * V_78 ,
const char * V_79 , T_4 V_83 )
{
struct V_9 * V_10 = F_34 ( V_29 ) ;
unsigned long V_3 ;
if ( F_48 ( V_79 , 10 , & V_3 ) < 0 )
return - V_84 ;
V_10 -> V_101 = V_3 ;
return V_83 ;
}
static T_3 F_92 ( struct V_28 * V_29 , struct V_77 * V_78 ,
char * V_79 )
{
struct V_9 * V_10 = F_33 ( V_29 ) ;
return sprintf ( V_79 , L_11 , ( long ) F_93 ( V_10 -> V_75 , V_10 -> V_101 ) ) ;
}
static T_3 F_94 ( struct V_28 * V_29 , struct V_77 * V_78 ,
char * V_79 )
{
static const char * const V_102 [] = {
L_12 ,
L_13 ,
L_14 ,
} ;
static const char * const V_103 [] = {
L_15 ,
L_16 ,
L_14 ,
} ;
struct V_9 * V_10 = F_34 ( V_29 ) ;
int V_11 = F_55 ( V_78 ) -> V_82 ;
const char * V_104 ;
if ( F_12 ( V_10 ) || F_13 ( V_10 ) )
V_104 = V_103 [ V_11 ] ;
else
V_104 = V_102 [ V_11 ] ;
return sprintf ( V_79 , L_17 , V_104 ) ;
}
static T_5 F_95 ( struct V_105 * V_106 ,
struct V_107 * V_78 , int V_82 )
{
struct V_28 * V_29 = F_96 ( V_106 , struct V_28 , V_106 ) ;
struct V_9 * V_10 = F_34 ( V_29 ) ;
int V_25 = V_82 / 5 ;
int V_108 = V_82 % 5 ;
if ( V_82 >= 40 ) {
V_25 = V_82 - 40 + 8 ;
V_108 = 0 ;
}
if ( ! ( V_10 -> V_38 & F_14 ( V_25 ) ) )
return 0 ;
if ( V_108 == 4 && ! V_10 -> V_109 )
return 0 ;
return V_78 -> V_110 ;
}
static T_5 F_97 ( struct V_105 * V_106 ,
struct V_107 * V_78 , int V_82 )
{
struct V_28 * V_29 = F_96 ( V_106 , struct V_28 , V_106 ) ;
struct V_9 * V_10 = F_34 ( V_29 ) ;
int V_25 = V_82 / 7 ;
int V_108 = V_82 % 7 ;
if ( V_82 >= 21 ) {
V_25 = V_82 - 21 + 3 ;
V_108 = 0 ;
}
if ( ! ( V_10 -> V_50 & F_14 ( V_25 ) ) )
return 0 ;
if ( V_108 == 5 && ! F_41 ( V_10 ) )
return 0 ;
if ( V_108 == 6 && ! V_10 -> V_109 )
return 0 ;
return V_78 -> V_110 ;
}
static T_5 F_98 ( struct V_105 * V_106 ,
struct V_107 * V_78 , int V_82 )
{
struct V_28 * V_29 = F_96 ( V_106 , struct V_28 , V_106 ) ;
struct V_9 * V_10 = F_34 ( V_29 ) ;
if ( ( V_82 == 2 || V_82 == 3 ) && ! V_10 -> V_111 )
return 0 ;
if ( V_82 > 3 && ! ( V_10 -> V_112 & F_14 ( V_82 - 4 ) ) )
return 0 ;
return V_78 -> V_110 ;
}
static T_5 F_99 ( struct V_105 * V_106 ,
struct V_107 * V_78 , int V_82 )
{
struct V_28 * V_29 = F_96 ( V_106 , struct V_28 , V_106 ) ;
struct V_9 * V_10 = F_34 ( V_29 ) ;
int V_25 = V_82 / 5 ;
int V_108 = V_82 % 5 ;
if ( V_82 >= 15 ) {
V_25 = ( V_82 - 15 ) / 4 + 3 ;
V_108 = ( V_82 - 15 ) % 4 ;
}
if ( ! ( V_10 -> V_43 & F_14 ( V_25 ) ) )
return 0 ;
if ( V_108 == 3 ) {
if ( ! V_10 -> V_109 )
return 0 ;
if ( V_25 == F_100 ( V_10 -> V_43 ) )
return V_78 -> V_110 | V_113 ;
}
if ( V_108 == 4 && F_39 ( V_10 ) )
return 0 ;
return V_78 -> V_110 ;
}
static T_5 F_101 ( struct V_105 * V_106 ,
struct V_107 * V_78 , int V_82 )
{
struct V_28 * V_29 = F_96 ( V_106 , struct V_28 , V_106 ) ;
struct V_9 * V_10 = F_34 ( V_29 ) ;
int V_25 = V_82 / 4 ;
int V_108 = V_82 % 4 ;
if ( ! ( V_10 -> V_68 & F_14 ( V_25 ) ) )
return 0 ;
if ( V_108 == 3 && ( F_30 ( V_10 ) || F_22 ( V_10 ) ) )
return V_78 -> V_110 | V_113 ;
if ( F_69 ( V_10 ) && V_25 == 1 && V_108 == 2 )
return V_78 -> V_110 | V_113 ;
return V_78 -> V_110 ;
}
static T_5 F_102 ( struct V_105 * V_106 ,
struct V_107 * V_78 , int V_82 )
{
struct V_28 * V_29 = F_96 ( V_106 , struct V_28 , V_106 ) ;
struct V_9 * V_10 = F_34 ( V_29 ) ;
int V_25 = V_82 / 11 ;
int V_108 = V_82 % 11 ;
if ( V_82 >= 33 ) {
V_25 = ( V_82 - 33 ) / 6 + 3 ;
V_108 = ( V_82 - 33 ) % 6 + 4 ;
}
if ( ! ( V_10 -> V_68 & F_14 ( V_25 ) ) )
return 0 ;
if ( F_22 ( V_10 ) ) {
if ( V_108 < 4 )
return 0 ;
if ( V_108 == 8 )
return 0 ;
}
if ( F_30 ( V_10 ) ) {
if ( V_108 >= 9 )
return 0 ;
}
return V_78 -> V_110 ;
}
static int T_6 F_103 ( int V_114 , unsigned short * V_115 ,
struct V_116 * V_117 )
{
int V_94 ;
T_2 V_118 ;
const char * V_119 , * V_120 ;
const struct V_121 * V_100 ;
V_94 = F_7 ( V_114 ) ;
if ( V_94 )
return V_94 ;
V_94 = - V_122 ;
V_118 = V_123 ? V_123 : F_5 ( V_114 , V_124 ) ;
switch ( V_118 ) {
case V_125 :
V_117 -> type = V_126 ;
break;
case V_127 :
V_117 -> type = V_73 ;
break;
case V_128 :
case V_129 :
V_117 -> type = V_74 ;
break;
case V_130 :
V_117 -> type = V_131 ;
break;
case V_132 :
V_117 -> type = V_133 ;
break;
case V_134 :
V_117 -> type = V_135 ;
break;
case V_136 :
V_117 -> type = V_137 ;
break;
case V_138 :
V_117 -> type = V_139 ;
break;
case V_140 :
V_117 -> type = V_141 ;
break;
case V_142 :
V_117 -> type = V_143 ;
break;
case V_144 :
V_117 -> type = V_145 ;
break;
case V_146 :
V_117 -> type = V_147 ;
break;
case V_148 :
V_117 -> type = V_149 ;
break;
case V_150 :
V_117 -> type = V_151 ;
break;
case V_152 :
V_117 -> type = V_153 ;
break;
case V_154 :
case V_155 :
V_117 -> type = V_88 ;
break;
case V_156 :
V_117 -> type = V_157 ;
break;
case V_158 :
V_117 -> type = V_159 ;
break;
case 0xffff :
goto exit;
default:
F_104 ( L_18 , V_118 ) ;
goto exit;
}
F_6 ( V_114 , V_160 ) ;
if ( ! ( F_1 ( V_114 , V_161 ) & 0x01 ) ) {
F_105 ( L_19 ) ;
goto exit;
}
* V_115 = F_5 ( V_114 , V_162 ) & ~ ( V_163 - 1 ) ;
if ( * V_115 == 0 ) {
F_105 ( L_20 ) ;
goto exit;
}
V_94 = 0 ;
V_117 -> V_164 = F_1 ( V_114 , V_165 ) & 0x0f ;
F_105 ( L_21 , V_118 ,
V_121 [ V_117 -> type ] . V_166 ,
* V_115 , V_117 -> V_164 ) ;
V_100 = & V_121 [ V_117 -> type ] ;
if ( F_106 ( V_100 ) )
V_117 -> V_167 |= F_14 ( 1 ) ;
V_117 -> V_167 |= F_14 ( 2 ) ;
if ( F_107 ( V_100 ) )
V_117 -> V_167 |= F_14 ( 3 ) ;
else
V_117 -> V_168 |= F_14 ( 9 ) ;
if ( ! F_108 ( V_100 ) )
V_117 -> V_169 |= F_14 ( 3 ) | F_14 ( 4 ) | F_14 ( 5 ) ;
if ( ! V_111 ( V_100 ) )
V_117 -> V_170 = 1 ;
if ( V_117 -> type == V_126 ) {
F_6 ( V_114 , 5 ) ;
V_117 -> V_171 = F_1 ( V_114 ,
V_172 ) & 0x3f ;
} else if ( V_117 -> type == V_149 ) {
int V_173 , V_174 , V_175 , V_176 , V_177 ;
F_6 ( V_114 , V_178 ) ;
V_173 = F_1 ( V_114 , V_179 ) ;
V_174 = F_1 ( V_114 , V_180 ) ;
V_175 = F_1 ( V_114 , V_181 ) ;
V_176 = F_1 ( V_114 , V_182 ) ;
V_177 = F_1 ( V_114 , V_183 ) ;
if ( ( V_174 & F_14 ( 0 ) ) || ! ( V_176 & F_14 ( 2 ) ) )
V_117 -> V_184 |= F_14 ( 2 ) ;
if ( ( V_173 & F_14 ( 4 ) ) ||
( ! ( V_175 & F_14 ( 1 ) ) && ( V_177 & F_14 ( 0 ) ) ) )
V_117 -> V_169 |= F_14 ( 2 ) ;
if ( V_174 & F_14 ( 7 ) )
V_117 -> V_184 |= F_14 ( 1 ) ;
if ( V_174 & F_14 ( 3 ) )
V_117 -> V_169 |= F_14 ( 1 ) ;
if ( ( V_174 & F_14 ( 0 ) ) || ( V_176 & F_14 ( 2 ) ) )
V_117 -> V_168 |= F_14 ( 5 ) ;
if ( V_174 & F_14 ( 1 ) )
V_117 -> V_168 |= F_14 ( 6 ) ;
if ( V_174 & F_14 ( 2 ) ) {
if ( ! ( V_176 & F_14 ( 1 ) ) ) {
V_176 |= F_14 ( 1 ) ;
F_4 ( V_114 , V_182 ,
V_176 ) ;
F_109 ( L_22 ) ;
}
F_109 ( L_23 ) ;
F_109 ( L_24 ) ;
}
if ( V_176 & F_14 ( 0 ) )
V_117 -> V_167 |= F_14 ( 0 ) ;
if ( V_176 & F_14 ( 1 ) )
V_117 -> V_167 |= F_14 ( 1 ) ;
V_117 -> V_171 = F_1 ( V_114 ,
V_172 ) & 0x3f ;
} else if ( V_117 -> type == V_88 ) {
int V_174 , V_185 ;
F_6 ( V_114 , V_178 ) ;
V_174 = F_1 ( V_114 , V_180 ) ;
if ( V_174 & F_14 ( 6 ) )
V_117 -> V_169 |= F_14 ( 2 ) ;
if ( V_174 & F_14 ( 7 ) )
V_117 -> V_184 |= F_14 ( 2 ) ;
V_185 = F_1 ( V_114 , V_186 ) ;
if ( V_185 & F_14 ( 1 ) )
V_117 -> V_169 |= F_14 ( 1 ) ;
if ( V_185 & F_14 ( 2 ) )
V_117 -> V_184 |= F_14 ( 1 ) ;
V_117 -> V_168 |= F_14 ( 5 ) ;
V_117 -> V_168 |= F_14 ( 6 ) ;
V_117 -> V_171 = F_1 ( V_114 ,
V_172 ) & 0x3f ;
} else if ( V_117 -> type == V_157 || V_117 -> type == V_159 ) {
int V_2 ;
F_6 ( V_114 , V_178 ) ;
V_2 = F_1 ( V_114 , V_179 ) ;
if ( V_2 & F_14 ( 6 ) )
V_117 -> V_169 |= F_14 ( 4 ) ;
V_2 = F_1 ( V_114 , V_187 ) ;
if ( ! ( V_2 & F_14 ( 5 ) ) )
V_117 -> V_184 |= F_14 ( 3 ) ;
if ( ! ( V_2 & F_14 ( 4 ) ) )
V_117 -> V_184 |= F_14 ( 4 ) ;
V_2 = F_1 ( V_114 , V_180 ) ;
if ( V_2 & F_14 ( 6 ) )
V_117 -> V_169 |= F_14 ( 2 ) ;
if ( V_2 & F_14 ( 7 ) )
V_117 -> V_184 |= F_14 ( 2 ) ;
V_2 = F_1 ( V_114 , V_188 ) ;
if ( ! ( V_2 & F_14 ( 2 ) ) )
V_117 -> V_169 |= F_14 ( 3 ) ;
V_2 = F_1 ( V_114 , V_186 ) ;
if ( V_2 & F_14 ( 1 ) )
V_117 -> V_169 |= F_14 ( 1 ) ;
if ( V_2 & F_14 ( 2 ) )
V_117 -> V_184 |= F_14 ( 1 ) ;
if ( ! ( V_2 & F_14 ( 7 ) ) ) {
V_117 -> V_169 |= F_14 ( 5 ) ;
V_117 -> V_184 |= F_14 ( 5 ) ;
}
V_117 -> V_171 = F_1 ( V_114 ,
V_172 ) & 0x3f ;
} else {
int V_2 ;
bool V_189 ;
F_6 ( V_114 , V_178 ) ;
if ( F_110 ( V_100 ) ) {
V_2 = F_1 ( V_114 , V_187 ) ;
switch ( V_117 -> type ) {
case V_131 :
if ( V_2 & F_14 ( 5 ) )
V_117 -> V_184 |= F_14 ( 3 ) ;
if ( V_2 & F_14 ( 4 ) )
V_117 -> V_184 |= F_14 ( 4 ) ;
break;
case V_133 :
case V_135 :
case V_137 :
if ( ! ( V_2 & F_14 ( 5 ) ) )
V_117 -> V_184 |= F_14 ( 3 ) ;
if ( ! ( V_2 & F_14 ( 4 ) ) )
V_117 -> V_184 |= F_14 ( 4 ) ;
break;
default:
break;
}
}
V_2 = F_1 ( V_114 , V_180 ) ;
if ( ! V_117 -> V_170 ) {
if ( V_2 & 0x0f ) {
F_105 ( L_25 ) ;
V_117 -> V_170 = 1 ;
}
}
if ( V_2 & F_14 ( 6 ) )
V_117 -> V_169 |= F_14 ( 2 ) ;
if ( V_2 & F_14 ( 7 ) )
V_117 -> V_184 |= F_14 ( 2 ) ;
V_2 = F_1 ( V_114 , V_186 ) ;
if ( V_2 & F_14 ( 1 ) )
V_117 -> V_169 |= F_14 ( 1 ) ;
if ( V_2 & F_14 ( 2 ) )
V_117 -> V_184 |= F_14 ( 1 ) ;
if ( ( V_117 -> type == V_131 || V_117 -> type == V_133 ) &&
! ( V_117 -> V_170 ) )
V_117 -> V_190 = F_1 ( V_114 ,
V_191 ) ;
V_2 = F_1 ( V_114 , V_182 ) ;
V_189 = V_117 -> type == V_147 && ( V_2 & F_14 ( 2 ) ) ;
if ( ( V_117 -> type == V_133 || V_189 ) && ! ( V_2 & F_14 ( 1 ) ) ) {
V_2 |= F_14 ( 1 ) ;
F_4 ( V_114 , V_182 , V_2 ) ;
F_109 ( L_26 ) ;
}
if ( V_2 & F_14 ( 0 ) )
V_117 -> V_167 |= F_14 ( 0 ) ;
if ( V_2 & F_14 ( 1 ) )
V_117 -> V_167 |= F_14 ( 1 ) ;
if ( V_189 ) {
V_117 -> V_168 |= F_14 ( 5 ) | F_14 ( 6 ) ;
V_117 -> V_192 |= F_14 ( 2 ) ;
}
V_117 -> V_171 = F_1 ( V_114 ,
V_172 ) & 0x3f ;
}
if ( V_117 -> V_171 )
F_105 ( L_27 ) ;
V_119 = F_111 ( V_193 ) ;
V_120 = F_111 ( V_194 ) ;
if ( V_119 && V_120 ) {
if ( strcmp ( V_119 , L_28 ) == 0 &&
strcmp ( V_120 , L_29 ) == 0 ) {
F_105 ( L_30 ) ;
V_117 -> V_169 = F_14 ( 1 ) ;
}
}
exit:
F_9 ( V_114 ) ;
return V_94 ;
}
static void F_112 ( struct V_195 * V_196 )
{
struct V_116 * V_117 = F_113 ( & V_196 -> V_29 ) ;
struct V_9 * V_10 = F_114 ( V_196 ) ;
int V_95 , V_25 ;
T_1 V_197 ;
for ( V_25 = 0 ; V_25 < V_198 ; V_25 ++ ) {
V_10 -> V_22 [ V_25 ] = V_25 ;
V_10 -> V_23 [ V_25 ] = 0x7f ;
V_10 -> V_27 [ V_25 ] [ 3 ] = 0x7f ;
}
for ( V_25 = 0 ; V_25 < V_41 ; V_25 ++ ) {
V_95 = F_25 ( V_10 , F_37 ( V_25 ) ) ;
if ( V_95 == 0xff )
F_28 ( V_10 , F_37 ( V_25 ) , 0 ) ;
}
for ( V_25 = 0 ; V_25 < V_54 ; V_25 ++ ) {
V_95 = F_25 ( V_10 , F_43 ( V_25 ) ) ;
if ( V_95 == 0xff )
F_28 ( V_10 , F_43 ( V_25 ) , 127 ) ;
}
V_95 = F_25 ( V_10 , V_199 ) ;
if ( ( V_95 & 0xff ) == 0 ) {
F_28 ( V_10 , V_199 , 0xff ) ;
}
V_197 = 0x70 & ~ ( V_117 -> V_184 << 4 ) ;
V_10 -> V_63 = F_25 ( V_10 , V_64 ) ;
if ( ( V_10 -> V_63 & V_197 ) == 0 ) {
V_10 -> V_63 |= V_197 ;
F_28 ( V_10 , V_64 ,
V_10 -> V_63 ) ;
}
V_10 -> V_43 = ( V_10 -> V_63 >> 4 ) & 0x07 ;
V_95 = F_25 ( V_10 , V_200 ) ;
if ( F_115 ( V_10 ) ) {
if ( ~ V_95 & 0x07 & V_10 -> V_43 ) {
F_116 ( & V_196 -> V_29 ,
L_31 ) ;
F_28 ( V_10 , V_200 ,
V_95 | 0x07 ) ;
}
}
if ( F_110 ( V_10 ) ) {
if ( V_95 & F_14 ( 4 ) )
V_10 -> V_43 |= F_14 ( 3 ) ;
if ( V_95 & F_14 ( 5 ) )
V_10 -> V_43 |= F_14 ( 4 ) ;
if ( F_117 ( V_10 ) && ( V_95 & F_14 ( 2 ) ) )
V_10 -> V_43 |= F_14 ( 5 ) ;
}
V_10 -> V_43 &= ~ V_117 -> V_184 ;
if ( F_108 ( V_10 ) ) {
V_95 = F_25 ( V_10 , V_55 ) ;
if ( ( V_95 & 0xc0 ) == 0xc0 )
V_117 -> V_169 |= F_14 ( 4 ) ;
if ( ! ( V_95 & F_14 ( 3 ) ) )
V_117 -> V_169 |= F_14 ( 5 ) ;
}
F_28 ( V_10 , V_36 ,
( F_25 ( V_10 , V_36 ) & 0x3e )
| ( V_35 ? 0x41 : 0x01 ) ) ;
}
static int F_118 ( struct V_28 * V_29 )
{
struct V_9 * V_10 = F_34 ( V_29 ) ;
int V_95 = F_25 ( V_10 , V_66 ) ;
if ( ( V_95 & 0x87 ) == 0 ) {
if ( V_201 ) {
int V_25 ;
T_1 V_202 [ 3 ] ;
for ( V_25 = 0 ; V_25 < F_119 ( V_202 ) ; V_25 ++ )
V_202 [ V_25 ] = F_25 ( V_10 ,
V_21 [ V_25 ] ) ;
if ( ! ( ( V_202 [ 0 ] | V_202 [ 1 ] | V_202 [ 2 ] ) & 0x80 ) ) {
F_120 ( V_29 ,
L_32 ) ;
F_28 ( V_10 , V_66 ,
V_95 | 0x87 ) ;
for ( V_25 = 0 ; V_25 < 3 ; V_25 ++ )
F_28 ( V_10 ,
V_21 [ V_25 ] ,
0x7f & ~ V_202 [ V_25 ] ) ;
return 1 ;
}
F_120 ( V_29 ,
L_33 ) ;
}
F_120 ( V_29 ,
L_34 ) ;
return 0 ;
} else if ( V_201 ) {
F_120 ( V_29 ,
L_35 ) ;
}
return 1 ;
}
static int F_121 ( struct V_195 * V_196 )
{
struct V_9 * V_10 ;
struct V_203 * V_204 ;
struct V_28 * V_29 = & V_196 -> V_29 ;
struct V_116 * V_117 = F_113 ( V_29 ) ;
int V_205 ;
struct V_28 * V_206 ;
V_204 = F_122 ( V_196 , V_207 , 0 ) ;
if ( ! F_123 ( & V_196 -> V_29 , V_204 -> V_208 , V_209 ,
V_6 ) ) {
F_73 ( V_29 , L_36 ,
( unsigned long ) V_204 -> V_208 ,
( unsigned long ) ( V_204 -> V_208 + V_209 - 1 ) ) ;
return - V_7 ;
}
V_10 = F_124 ( & V_196 -> V_29 , sizeof( struct V_9 ) , V_210 ) ;
if ( ! V_10 )
return - V_211 ;
V_10 -> V_16 = V_204 -> V_208 ;
V_10 -> type = V_117 -> type ;
V_10 -> V_212 = V_121 [ V_117 -> type ] . V_212 ;
V_10 -> V_213 = V_121 [ V_117 -> type ] . V_213 ;
V_10 -> V_214 = V_121 [ V_117 -> type ] . V_214 ;
switch ( V_10 -> type ) {
case V_126 :
if ( V_117 -> V_164 >= 0x03 ) {
V_10 -> V_212 &= ~ V_215 ;
V_10 -> V_212 |= V_216 | V_217 ;
}
break;
case V_73 :
if ( V_117 -> V_164 >= 0x08 ) {
V_10 -> V_212 &= ~ V_215 ;
V_10 -> V_212 |= V_216 | V_217 |
V_218 ;
}
break;
default:
break;
}
if ( ( F_25 ( V_10 , V_36 ) & 0x80 ) ||
F_25 ( V_10 , V_219 ) != 0x90 )
return - V_122 ;
F_125 ( V_196 , V_10 ) ;
F_126 ( & V_10 -> V_30 ) ;
V_205 = F_118 ( V_29 ) ;
if ( F_12 ( V_10 ) ) {
if ( V_117 -> V_167 & F_14 ( 0 ) )
V_10 -> V_13 |= F_14 ( 3 ) ;
if ( V_117 -> V_167 & F_14 ( 1 ) )
V_10 -> V_13 |= F_14 ( 7 ) ;
if ( V_117 -> V_167 & F_14 ( 2 ) )
V_10 -> V_13 |= F_14 ( 8 ) ;
if ( V_117 -> V_167 & F_14 ( 3 ) )
V_10 -> V_13 |= F_14 ( 9 ) ;
} else if ( V_117 -> type == V_145 || V_117 -> type == V_147 ||
V_117 -> type == V_149 ) {
if ( V_117 -> V_167 & F_14 ( 0 ) )
V_10 -> V_13 |= F_14 ( 3 ) ;
if ( V_117 -> V_167 & F_14 ( 1 ) )
V_10 -> V_13 |= F_14 ( 7 ) ;
}
V_10 -> V_50 = 0x07 ;
if ( V_117 -> V_192 & F_14 ( 2 ) ) {
if ( V_117 -> type == V_147 &&
! ( F_25 ( V_10 , V_72 ) & 0x80 ) )
V_10 -> V_50 &= ~ F_14 ( 2 ) ;
}
V_10 -> V_112 = V_117 -> V_167 ;
V_10 -> V_38 = 0x3ff & ~ V_117 -> V_168 ;
if ( F_127 ( V_10 ) ) {
T_1 V_2 = F_25 ( V_10 , V_220 ) ;
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
V_10 -> V_109 = ! ! V_117 -> V_171 ;
F_112 ( V_196 ) ;
if ( ! V_117 -> V_170 ) {
V_10 -> V_111 = true ;
V_10 -> V_101 = F_128 () ;
V_10 -> V_75 = V_117 -> V_190 ;
}
V_10 -> V_221 [ 0 ] = & V_222 ;
V_10 -> V_221 [ 1 ] = & V_223 ;
V_10 -> V_221 [ 2 ] = & V_224 ;
V_10 -> V_221 [ 3 ] = & V_225 ;
if ( V_205 ) {
V_10 -> V_68 = F_14 ( F_119 ( V_21 ) ) - 1 ;
V_10 -> V_68 &= ~ V_117 -> V_169 ;
V_10 -> V_221 [ 4 ] = & V_226 ;
if ( F_30 ( V_10 ) || F_22 ( V_10 ) )
V_10 -> V_221 [ 5 ] = & V_227 ;
}
V_206 = F_129 ( V_29 ,
V_121 [ V_117 -> type ] . V_228 ,
V_10 , V_10 -> V_221 ) ;
return F_130 ( V_206 ) ;
}
static int T_6 F_131 ( int V_82 , unsigned short V_115 ,
const struct V_116 * V_117 )
{
struct V_195 * V_196 ;
struct V_203 V_204 = {
. V_208 = V_115 + V_229 ,
. V_230 = V_115 + V_229 + V_209 - 1 ,
. V_228 = V_6 ,
. V_231 = V_207 ,
} ;
int V_94 ;
V_94 = F_132 ( & V_204 ) ;
if ( V_94 )
return V_94 ;
V_196 = F_133 ( V_6 , V_115 ) ;
if ( ! V_196 )
return - V_211 ;
V_94 = F_134 ( V_196 , & V_204 , 1 ) ;
if ( V_94 ) {
F_135 ( L_37 , V_94 ) ;
goto V_232;
}
V_94 = F_136 ( V_196 , V_117 ,
sizeof( struct V_116 ) ) ;
if ( V_94 ) {
F_135 ( L_38 ) ;
goto V_232;
}
V_94 = F_137 ( V_196 ) ;
if ( V_94 ) {
F_135 ( L_39 , V_94 ) ;
goto V_232;
}
V_233 [ V_82 ] = V_196 ;
return 0 ;
V_232:
F_138 ( V_196 ) ;
return V_94 ;
}
static int T_6 F_139 ( void )
{
int V_114 [ 2 ] = { V_234 , V_8 } ;
struct V_116 V_117 ;
unsigned short V_235 ;
bool V_236 = false ;
int V_25 , V_94 ;
V_94 = F_140 ( & V_237 ) ;
if ( V_94 )
return V_94 ;
for ( V_25 = 0 ; V_25 < F_119 ( V_114 ) ; V_25 ++ ) {
memset ( & V_117 , 0 , sizeof( struct V_116 ) ) ;
V_235 = 0 ;
V_94 = F_103 ( V_114 [ V_25 ] , & V_235 , & V_117 ) ;
if ( V_94 || V_235 == 0 )
continue;
V_94 = F_131 ( V_25 , V_235 , & V_117 ) ;
if ( V_94 )
goto V_238;
V_236 = true ;
}
if ( ! V_236 ) {
V_94 = - V_122 ;
goto V_239;
}
return 0 ;
V_238:
F_141 ( V_233 [ 0 ] ) ;
V_239:
F_142 ( & V_237 ) ;
return V_94 ;
}
static void T_7 F_143 ( void )
{
F_141 ( V_233 [ 1 ] ) ;
F_141 ( V_233 [ 0 ] ) ;
F_142 ( & V_237 ) ;
}
