static inline int F_1 ( int V_1 , int V_2 )
{
F_2 ( V_2 , V_1 ) ;
return F_3 ( V_1 + 1 ) ;
}
static int F_4 ( int V_1 , int V_2 )
{
int V_3 ;
V_3 = F_1 ( V_1 , V_2 ) << 8 ;
V_3 |= F_1 ( V_1 , V_2 + 1 ) ;
return V_3 ;
}
static inline int F_5 ( int V_1 )
{
if ( ! F_6 ( V_1 , 2 , V_4 ) ) {
F_7 ( L_1 , V_1 ) ;
return - V_5 ;
}
F_2 ( V_6 , V_1 ) ;
F_2 ( V_6 , V_1 ) ;
return 0 ;
}
static inline void F_8 ( int V_1 , int V_7 )
{
F_2 ( V_8 , V_1 ) ;
F_2 ( V_7 , V_1 + 1 ) ;
}
static inline void F_9 ( int V_1 )
{
F_2 ( V_9 , V_1 ) ;
F_10 ( V_1 , 2 ) ;
}
static inline int F_11 ( T_1 V_2 )
{
return V_2 ? ( 1500000 / V_2 ) : 0 ;
}
static inline T_1 F_12 ( int V_10 )
{
return V_10 ? ( 1500000 / V_10 ) : 0 ;
}
static T_2 F_13 ( struct V_11 * V_12 , T_2 V_2 )
{
T_2 V_3 ;
F_2 ( V_2 , V_12 -> V_13 + V_14 ) ;
V_3 = F_3 ( V_12 -> V_13 + V_15 ) ;
return V_3 ;
}
static T_1 F_14 ( struct V_11 * V_12 , T_2 V_2 )
{
T_1 V_3 ;
V_3 = F_13 ( V_12 , V_2 ) << 8 ;
V_3 |= F_13 ( V_12 , V_2 + 1 ) ;
return V_3 ;
}
static void F_15 ( struct V_11 * V_12 , T_2 V_2 , T_2 V_3 )
{
F_2 ( V_2 , V_12 -> V_13 + V_14 ) ;
F_2 ( V_3 , V_12 -> V_13 + V_15 ) ;
}
static void F_16 ( struct V_11 * V_12 , T_2 V_2 , T_1 V_3 )
{
F_15 ( V_12 , V_2 , V_3 >> 8 ) ;
F_15 ( V_12 , V_2 + 1 , V_3 & 0xff ) ;
}
static T_1 F_17 ( struct V_11 * V_12 , int V_16 )
{
if ( V_12 -> type == V_17 )
return F_14 ( V_12 , F_18 ( V_16 ) ) ;
else
return F_13 ( V_12 , F_18 ( V_16 ) ) ;
}
static struct V_11 * F_19 ( struct V_18 * V_19 )
{
struct V_11 * V_12 = F_20 ( V_19 ) ;
int V_20 = V_21 [ V_12 -> type ] ;
int V_22 = V_23 [ V_12 -> type ] ;
int V_16 , V_2 , V_24 ;
F_21 ( & V_12 -> V_25 ) ;
if ( F_22 ( V_26 , V_12 -> V_27 + 60 * V_28 ) ||
! V_12 -> V_29 ) {
if ( V_30 [ V_12 -> type ] ) {
if ( V_12 -> type == V_31 ) {
V_12 -> V_32 =
F_13 ( V_12 ,
V_33 ) ;
V_12 -> V_34 =
F_13 ( V_12 ,
V_35 ) ;
} else {
V_12 -> V_32 =
F_13 ( V_12 ,
V_36 ) ;
V_12 -> V_34 =
F_13 ( V_12 ,
V_37 ) ;
}
}
for ( V_16 = V_12 -> V_38 ; V_16 < V_22 + V_12 -> V_38 ;
V_16 ++ ) {
V_12 -> V_39 [ V_16 ] = F_13 ( V_12 ,
F_23 ( V_16 ) ) ;
V_12 -> V_40 [ V_16 ] = F_13 ( V_12 ,
F_24 ( V_16 ) ) ;
}
if ( V_12 -> type != V_41 ) {
V_12 -> V_42 [ 0 ] = F_13 ( V_12 ,
F_25 ( 0 ) ) ;
V_12 -> V_42 [ 1 ] = F_13 ( V_12 ,
F_25 ( 1 ) ) ;
}
if ( ( V_12 -> type != V_17 ) && ( V_12 -> type != V_41 ) ) {
V_2 = F_13 ( V_12 , V_43 ) ;
V_12 -> V_44 [ 1 ] = ( V_2 & 0x02 ) ? 2 : 4 ;
V_12 -> V_44 [ 2 ] = ( V_2 & 0x04 ) ? 2 : 4 ;
V_12 -> V_44 [ 3 ] = ( V_2 & 0x08 ) ? 2 : 4 ;
}
if ( V_45 [ V_12 -> type ] )
V_12 -> V_46 = F_13 ( V_12 ,
V_47 ) ;
if ( V_48 [ V_12 -> type ] )
V_12 -> V_49 = F_13 ( V_12 ,
V_50 ) ;
V_12 -> V_51 = F_13 ( V_12 ,
V_52 ) ;
V_12 -> V_53 [ 0 ] =
F_13 ( V_12 , F_26 ( 0 ) ) ;
V_12 -> V_53 [ 1 ] =
F_13 ( V_12 , F_26 ( 1 ) ) ;
for ( V_16 = 0 ; V_16 < V_20 ; V_16 ++ ) {
V_12 -> V_54 [ V_16 ] =
F_13 ( V_12 ,
F_27 ( V_16 ) ) ;
switch ( V_12 -> type ) {
default:
for ( V_24 = 0 ; V_24 < 5 ; V_24 ++ ) {
V_12 -> V_55 [ V_16 ] [ V_24 ] =
F_13 ( V_12 ,
F_28
( V_16 , V_24 ) ) ;
}
for ( V_24 = 0 ; V_24 < 4 ; V_24 ++ ) {
V_12 -> V_56 [ V_16 ] [ V_24 ] =
F_13 ( V_12 ,
F_29
( V_16 , V_24 ) ) ;
}
break;
case V_57 :
case V_58 :
V_12 -> V_55 [ V_16 ] [ 0 ] =
F_13 ( V_12 ,
F_28 ( V_16 , 0 ) ) ;
case V_59 :
V_12 -> V_55 [ V_16 ] [ 1 ] =
F_13 ( V_12 ,
F_28
( V_16 , 1 ) ) ;
V_12 -> V_55 [ V_16 ] [ 4 ] =
F_13 ( V_12 ,
F_28
( V_16 , 4 ) ) ;
V_12 -> V_56 [ V_16 ] [ 0 ] =
F_13 ( V_12 ,
F_29
( V_16 , 0 ) ) ;
V_12 -> V_56 [ V_16 ] [ 3 ] =
F_13 ( V_12 ,
F_29
( V_16 , 3 ) ) ;
break;
}
}
V_12 -> V_27 = V_26 ;
}
if ( F_22 ( V_26 , V_12 -> V_60 + V_28 ) || ! V_12 -> V_29 ) {
V_12 -> V_61 = F_13 ( V_12 ,
V_62 ) ;
V_12 -> V_63 = F_13 ( V_12 ,
V_64 ) ;
for ( V_16 = V_12 -> V_38 ; V_16 < V_22 + V_12 -> V_38 ;
V_16 ++ )
V_12 -> V_65 [ V_16 ] = F_17 ( V_12 , V_16 ) ;
V_12 -> V_66 = F_13 ( V_12 ,
V_67 ) ;
for ( V_16 = 0 ; V_16 < V_20 ; V_16 ++ ) {
V_12 -> V_10 [ V_16 ] = F_14 ( V_12 ,
F_30 ( V_16 ) ) ;
V_12 -> V_68 [ V_16 ] =
F_14 ( V_12 , F_31 ( V_16 ) ) ;
V_12 -> V_69 [ V_16 ] =
F_14 ( V_12 ,
F_32 ( V_16 ) ) ;
V_12 -> V_70 [ V_16 ] =
F_13 ( V_12 , F_33 ( V_16 ) ) ;
}
if ( V_12 -> type == V_71 ) {
V_12 -> V_10 [ 2 ] = F_14 ( V_12 ,
F_30 ( 2 ) ) ;
V_12 -> V_70 [ 2 ] = F_13 ( V_12 ,
F_33 ( 2 ) ) ;
}
if ( V_12 -> type == V_41 )
V_12 -> V_10 [ 3 ] = F_14 ( V_12 ,
F_30 ( 3 ) ) ;
if ( V_30 [ V_12 -> type ] ) {
if ( V_12 -> type == V_31 )
V_12 -> V_72 = F_13 ( V_12 ,
V_73 ) ;
else
V_12 -> V_72 = F_13 ( V_12 ,
V_74 ) ;
}
for ( V_16 = 0 ; V_16 < V_75 ; V_16 ++ )
if ( V_76 [ V_12 -> type ] [ V_16 ] )
V_12 -> V_77 [ V_16 ] = F_13 ( V_12 ,
F_34 ( V_16 ) ) ;
V_12 -> V_60 = V_26 ;
V_12 -> V_29 = 1 ;
}
F_35 ( & V_12 -> V_25 ) ;
return V_12 ;
}
static T_3 F_36 ( struct V_18 * V_19 , struct V_78 * V_79 ,
char * V_80 )
{
struct V_11 * V_12 = F_19 ( V_19 ) ;
int V_16 = F_37 ( V_79 ) -> V_81 ;
int V_82 = F_11 ( V_12 -> V_10 [ V_16 ] ) ;
if ( V_82 == V_83 )
V_82 = 0 ;
return sprintf ( V_80 , L_2 , V_82 ) ;
}
static T_3 F_38 ( struct V_18 * V_19 ,
struct V_78 * V_79 , char * V_80 )
{
struct V_11 * V_12 = F_19 ( V_19 ) ;
int V_16 = F_37 ( V_79 ) -> V_81 ;
int V_82 = F_11 ( V_12 -> V_69 [ V_16 ] ) ;
return sprintf ( V_80 , L_2 , V_82 ) ;
}
static T_3 F_39 ( struct V_18 * V_19 ,
struct V_78 * V_79 ,
const char * V_80 , T_4 V_84 )
{
struct V_11 * V_12 = F_20 ( V_19 ) ;
int V_85 , V_16 = F_37 ( V_79 ) -> V_81 ;
long V_3 ;
V_85 = F_40 ( V_80 , 10 , & V_3 ) ;
if ( V_85 )
return V_85 ;
V_3 = F_41 ( V_3 , 23 , 1500000 ) ;
V_3 = F_12 ( V_3 ) ;
F_21 ( & V_12 -> V_25 ) ;
F_16 ( V_12 , F_32 ( V_16 ) , V_3 ) ;
V_12 -> V_69 [ V_16 ] = V_3 ;
F_35 ( & V_12 -> V_25 ) ;
return V_84 ;
}
static T_3 F_42 ( struct V_18 * V_19 , struct V_78
* V_79 , char * V_80 )
{
struct V_11 * V_12 = F_19 ( V_19 ) ;
int V_16 = F_37 ( V_79 ) -> V_81 ;
if ( V_12 -> V_46 & ( 1 << V_16 ) )
return sprintf ( V_80 , L_3 ) ;
else
return sprintf ( V_80 , L_4 ) ;
}
static T_3 F_43 ( struct V_18 * V_19 , struct V_78
* V_79 , const char * V_80 , T_4 V_84 )
{
struct V_11 * V_12 = F_20 ( V_19 ) ;
int V_85 , V_16 = F_37 ( V_79 ) -> V_81 ;
unsigned long V_3 ;
V_85 = F_44 ( V_80 , 10 , & V_3 ) ;
if ( V_85 )
return V_85 ;
F_21 ( & V_12 -> V_25 ) ;
V_12 -> V_46 = F_13 ( V_12 , V_47 ) ;
if ( V_3 )
V_12 -> V_46 |= 1 << V_16 ;
else
V_12 -> V_46 &= ~ ( 1 << V_16 ) ;
F_15 ( V_12 , V_47 , V_12 -> V_46 ) ;
F_35 ( & V_12 -> V_25 ) ;
return V_84 ;
}
static T_3 F_45 ( struct V_18 * V_19 , struct V_78
* V_79 , char * V_80 )
{
struct V_11 * V_12 = F_19 ( V_19 ) ;
int V_16 = F_37 ( V_79 ) -> V_81 ;
if ( V_12 -> V_66 & ( 1 << V_16 ) )
return sprintf ( V_80 , L_3 ) ;
else
return sprintf ( V_80 , L_4 ) ;
}
static T_3 F_46 ( struct V_18 * V_19 , struct V_78 * V_79 ,
char * V_80 )
{
struct V_11 * V_12 = F_19 ( V_19 ) ;
int V_16 = F_37 ( V_79 ) -> V_81 ;
return sprintf ( V_80 , L_2 , V_12 -> V_77 [ V_16 ] * 8 ) ;
}
static T_3 F_47 ( struct V_18 * V_19 , struct V_78
* V_79 , char * V_80 )
{
struct V_11 * V_12 = F_19 ( V_19 ) ;
return sprintf ( V_80 , L_2 , V_12 -> V_32 * 8 ) ;
}
static T_3 F_48 ( struct V_18 * V_19 , struct V_78
* V_79 , const char * V_80 , T_4 V_84 )
{
struct V_11 * V_12 = F_20 ( V_19 ) ;
int V_85 ;
long V_3 ;
V_85 = F_40 ( V_80 , 10 , & V_3 ) ;
if ( V_85 )
return V_85 ;
V_3 /= 8 ;
V_3 = F_41 ( V_3 , 0 , 255 ) ;
F_21 ( & V_12 -> V_25 ) ;
if ( V_12 -> type == V_31 )
F_15 ( V_12 , V_33 , V_3 ) ;
else
F_15 ( V_12 , V_36 , V_3 ) ;
V_12 -> V_32 = V_3 ;
F_35 ( & V_12 -> V_25 ) ;
return V_84 ;
}
static T_3 F_49 ( struct V_18 * V_19 , struct V_78
* V_79 , char * V_80 )
{
struct V_11 * V_12 = F_19 ( V_19 ) ;
int V_16 = F_37 ( V_79 ) -> V_81 ;
if ( V_12 -> V_34 & ( 1 << V_16 ) )
return sprintf ( V_80 , L_3 ) ;
else
return sprintf ( V_80 , L_4 ) ;
}
static T_3 F_50 ( struct V_18 * V_19 , struct V_78
* V_79 , const char * V_80 , T_4 V_84 )
{
struct V_11 * V_12 = F_20 ( V_19 ) ;
int V_85 , V_16 = F_37 ( V_79 ) -> V_81 ;
unsigned long V_3 ;
V_85 = F_44 ( V_80 , 10 , & V_3 ) ;
if ( V_85 )
return V_85 ;
F_21 ( & V_12 -> V_25 ) ;
if ( V_12 -> type == V_31 )
V_12 -> V_34 = F_13 ( V_12 , V_35 ) ;
else
V_12 -> V_34 = F_13 ( V_12 , V_37 ) ;
if ( V_3 )
V_12 -> V_34 |= 1 << V_16 ;
else
V_12 -> V_34 &= ~ ( 1 << V_16 ) ;
if ( V_12 -> type == V_31 )
F_15 ( V_12 , V_35 , V_12 -> V_34 ) ;
else
F_15 ( V_12 , V_37 , V_12 -> V_34 ) ;
F_35 ( & V_12 -> V_25 ) ;
return V_84 ;
}
static T_3 F_51 ( struct V_18 * V_19 , struct V_78
* V_79 , char * V_80 )
{
struct V_11 * V_12 = F_19 ( V_19 ) ;
int V_16 = F_37 ( V_79 ) -> V_81 ;
if ( V_12 -> V_72 & ( 1 << V_16 ) )
return sprintf ( V_80 , L_3 ) ;
else
return sprintf ( V_80 , L_4 ) ;
}
static T_3 F_52 ( struct V_18 * V_19 , struct V_78 * V_79 ,
char * V_80 )
{
struct V_11 * V_12 = F_19 ( V_19 ) ;
int V_16 = F_37 ( V_79 ) -> V_81 ;
int V_86 , V_65 ;
if ( V_12 -> type == V_17 ) {
if ( V_12 -> V_87 & 1 ) {
V_86 = V_12 -> V_65 [ V_16 ] & 0x0001 ;
V_65 = ( V_12 -> V_65 [ V_16 ] >> 5 ) & 0x7ff ;
} else {
V_86 = V_12 -> V_65 [ V_16 ] & 0x8000 ;
V_65 = ( V_12 -> V_65 [ V_16 ] >> 5 ) & 0x3ff ;
}
V_65 *= 125 ;
if ( V_86 )
V_65 -= 128000 ;
} else
V_65 = V_12 -> V_65 [ V_16 ] * 1000 ;
return sprintf ( V_80 , L_2 , V_65 ) ;
}
static T_3 F_53 ( struct V_18 * V_19 , struct V_78
* V_79 , char * V_80 )
{
struct V_11 * V_12 = F_19 ( V_19 ) ;
int V_16 = F_37 ( V_79 ) -> V_81 ;
return sprintf ( V_80 , L_2 , V_12 -> V_40 [ V_16 ] * 1000 ) ;
}
static T_3 F_54 ( struct V_18 * V_19 , struct V_78
* V_79 , const char * V_80 , T_4 V_84 )
{
struct V_11 * V_12 = F_20 ( V_19 ) ;
int V_85 , V_16 = F_37 ( V_79 ) -> V_81 ;
long V_3 ;
V_85 = F_40 ( V_80 , 10 , & V_3 ) ;
if ( V_85 )
return V_85 ;
V_3 /= 1000 ;
V_3 = F_41 ( V_3 , 0 , 255 ) ;
F_21 ( & V_12 -> V_25 ) ;
F_15 ( V_12 , F_24 ( V_16 ) , V_3 ) ;
V_12 -> V_40 [ V_16 ] = V_3 ;
F_35 ( & V_12 -> V_25 ) ;
return V_84 ;
}
static T_3 F_55 ( struct V_18 * V_19 , struct V_78
* V_79 , char * V_80 )
{
struct V_11 * V_12 = F_19 ( V_19 ) ;
int V_16 = F_37 ( V_79 ) -> V_81 ;
int V_88 ;
F_21 ( & V_12 -> V_25 ) ;
if ( V_16 & 1 )
V_88 = V_12 -> V_42 [ V_16 / 2 ] >> 4 ;
else
V_88 = V_12 -> V_42 [ V_16 / 2 ] & 0x0f ;
V_88 = ( V_12 -> V_40 [ V_16 ] - V_88 ) * 1000 ;
F_35 ( & V_12 -> V_25 ) ;
return sprintf ( V_80 , L_2 , V_88 ) ;
}
static T_3 F_56 ( struct V_18 * V_19 , struct V_78
* V_79 , const char * V_80 , T_4 V_84 )
{
struct V_11 * V_12 = F_20 ( V_19 ) ;
int V_85 , V_16 = F_37 ( V_79 ) -> V_81 ;
T_3 V_89 = V_84 ;
T_2 V_2 ;
long V_3 ;
V_85 = F_40 ( V_80 , 10 , & V_3 ) ;
if ( V_85 )
return V_85 ;
V_3 /= 1000 ;
F_21 ( & V_12 -> V_25 ) ;
V_12 -> V_40 [ V_16 ] = F_13 ( V_12 , F_24 ( V_16 ) ) ;
V_3 = F_41 ( V_3 , V_12 -> V_40 [ V_16 ] - 15 , V_12 -> V_40 [ V_16 ] ) ;
V_3 = V_12 -> V_40 [ V_16 ] - V_3 ;
V_2 = F_13 ( V_12 , F_25 ( V_16 / 2 ) ) ;
if ( V_16 & 1 )
V_2 = ( V_2 & 0x0f ) | ( V_3 << 4 ) ;
else
V_2 = ( V_2 & 0xf0 ) | V_3 ;
F_15 ( V_12 , F_25 ( V_16 / 2 ) , V_2 ) ;
V_12 -> V_42 [ V_16 / 2 ] = V_2 ;
F_35 ( & V_12 -> V_25 ) ;
return V_89 ;
}
static T_3 F_57 ( struct V_18 * V_19 , struct V_78
* V_79 , char * V_80 )
{
struct V_11 * V_12 = F_19 ( V_19 ) ;
int V_16 = F_37 ( V_79 ) -> V_81 ;
return sprintf ( V_80 , L_2 , V_12 -> V_39 [ V_16 ] * 1000 ) ;
}
static T_3 F_58 ( struct V_18 * V_19 , struct V_78
* V_79 , const char * V_80 , T_4 V_84 )
{
struct V_11 * V_12 = F_20 ( V_19 ) ;
int V_85 , V_16 = F_37 ( V_79 ) -> V_81 ;
long V_3 ;
V_85 = F_40 ( V_80 , 10 , & V_3 ) ;
if ( V_85 )
return V_85 ;
V_3 /= 1000 ;
V_3 = F_41 ( V_3 , 0 , 255 ) ;
F_21 ( & V_12 -> V_25 ) ;
F_15 ( V_12 , F_23 ( V_16 ) , V_3 ) ;
V_12 -> V_39 [ V_16 ] = V_3 ;
F_35 ( & V_12 -> V_25 ) ;
return V_84 ;
}
static T_3 F_59 ( struct V_18 * V_19 , struct V_78
* V_79 , char * V_80 )
{
struct V_11 * V_12 = F_19 ( V_19 ) ;
int V_16 = F_37 ( V_79 ) -> V_81 ;
int V_90 ;
F_21 ( & V_12 -> V_25 ) ;
if ( V_16 & 1 )
V_90 = V_12 -> V_42 [ V_16 / 2 ] >> 4 ;
else
V_90 = V_12 -> V_42 [ V_16 / 2 ] & 0x0f ;
V_90 = ( V_12 -> V_39 [ V_16 ] - V_90 ) * 1000 ;
F_35 ( & V_12 -> V_25 ) ;
return sprintf ( V_80 , L_2 , V_90 ) ;
}
static T_3 F_60 ( struct V_18 * V_19 , struct V_78
* V_79 , char * V_80 )
{
struct V_11 * V_12 = F_19 ( V_19 ) ;
int V_16 = F_37 ( V_79 ) -> V_81 ;
return sprintf ( V_80 , L_2 , V_12 -> V_44 [ V_16 ] ) ;
}
static T_3 F_61 ( struct V_18 * V_19 , struct V_78
* V_79 , char * V_80 )
{
struct V_11 * V_12 = F_19 ( V_19 ) ;
int V_16 = F_37 ( V_79 ) -> V_81 ;
if ( V_12 -> V_49 & ( 1 << V_16 ) )
return sprintf ( V_80 , L_3 ) ;
else
return sprintf ( V_80 , L_4 ) ;
}
static T_3 F_62 ( struct V_18 * V_19 , struct V_78
* V_79 , const char * V_80 , T_4 V_84 )
{
struct V_11 * V_12 = F_20 ( V_19 ) ;
int V_85 , V_16 = F_37 ( V_79 ) -> V_81 ;
unsigned long V_3 ;
V_85 = F_44 ( V_80 , 10 , & V_3 ) ;
if ( V_85 )
return V_85 ;
F_21 ( & V_12 -> V_25 ) ;
V_12 -> V_49 = F_13 ( V_12 , V_50 ) ;
if ( V_3 )
V_12 -> V_49 |= 1 << V_16 ;
else
V_12 -> V_49 &= ~ ( 1 << V_16 ) ;
F_15 ( V_12 , V_50 , V_12 -> V_49 ) ;
F_35 ( & V_12 -> V_25 ) ;
return V_84 ;
}
static T_3 F_63 ( struct V_18 * V_19 , struct V_78
* V_79 , char * V_80 )
{
struct V_11 * V_12 = F_19 ( V_19 ) ;
int V_16 = F_37 ( V_79 ) -> V_81 ;
if ( V_12 -> V_61 & ( 1 << V_16 ) )
return sprintf ( V_80 , L_3 ) ;
else
return sprintf ( V_80 , L_4 ) ;
}
static T_3 F_64 ( struct V_18 * V_19 , struct V_78
* V_79 , char * V_80 )
{
struct V_11 * V_12 = F_19 ( V_19 ) ;
int V_16 = F_37 ( V_79 ) -> V_81 ;
if ( V_12 -> V_63 & ( 1 << V_16 ) )
return sprintf ( V_80 , L_3 ) ;
else
return sprintf ( V_80 , L_4 ) ;
}
static T_3 F_65 ( struct V_18 * V_19 ,
struct V_78 * V_79 , char * V_80 )
{
struct V_11 * V_12 = F_19 ( V_19 ) ;
int V_3 , V_16 = F_37 ( V_79 ) -> V_81 ;
F_21 ( & V_12 -> V_25 ) ;
if ( V_12 -> V_51 & ( 1 << ( 2 * V_16 ) ) )
V_3 = V_12 -> V_70 [ V_16 ] ;
else {
V_3 = 255 * F_11 ( V_12 -> V_68 [ V_16 ] )
/ F_11 ( V_12 -> V_69 [ V_16 ] ) ;
}
F_35 ( & V_12 -> V_25 ) ;
return sprintf ( V_80 , L_2 , V_3 ) ;
}
static T_3 F_66 ( struct V_18 * V_19 ,
struct V_78 * V_79 , const char * V_80 ,
T_4 V_84 )
{
struct V_11 * V_12 = F_20 ( V_19 ) ;
int V_85 , V_16 = F_37 ( V_79 ) -> V_81 ;
long V_3 ;
V_85 = F_40 ( V_80 , 10 , & V_3 ) ;
if ( V_85 )
return V_85 ;
V_3 = F_41 ( V_3 , 0 , 255 ) ;
F_21 ( & V_12 -> V_25 ) ;
V_12 -> V_51 = F_13 ( V_12 , V_52 ) ;
if ( ( V_12 -> type == V_41 && ( ( V_12 -> V_51 >> 2 * V_16 ) & 3 ) != 2 ) ||
( V_12 -> type != V_41 && ! ( ( V_12 -> V_51 >> 2 * V_16 ) & 2 ) ) ) {
V_84 = - V_91 ;
goto V_92;
}
if ( V_12 -> V_51 & ( 1 << ( 2 * V_16 ) ) ) {
F_15 ( V_12 , F_33 ( V_16 ) , V_3 ) ;
V_12 -> V_70 [ V_16 ] = V_3 ;
} else {
int V_93 , V_94 ;
V_94 = F_14 ( V_12 ,
F_32 ( V_16 ) ) ;
V_93 = F_12 ( V_3 * F_11 ( V_94 ) / 255 ) ;
F_16 ( V_12 , F_31 ( V_16 ) , V_93 ) ;
V_12 -> V_68 [ V_16 ] = V_93 ;
V_12 -> V_69 [ V_16 ] = V_94 ;
}
V_92:
F_35 ( & V_12 -> V_25 ) ;
return V_84 ;
}
static T_3 F_67 ( struct V_18 * V_19 ,
struct V_78 * V_79 , char * V_80 )
{
struct V_11 * V_12 = F_19 ( V_19 ) ;
int V_3 , V_16 = F_37 ( V_79 ) -> V_81 ;
V_3 = V_12 -> V_70 [ V_16 ] ;
return sprintf ( V_80 , L_2 , V_3 ) ;
}
static T_3 F_68 ( struct V_18 * V_19 ,
struct V_78 * V_79 ,
const char * V_80 , T_4 V_84 )
{
struct V_11 * V_12 = F_20 ( V_19 ) ;
int V_85 , V_16 = F_37 ( V_79 ) -> V_81 ;
long V_3 ;
V_85 = F_40 ( V_80 , 10 , & V_3 ) ;
if ( V_85 )
return V_85 ;
V_3 = F_41 ( V_3 , 0 , 255 ) ;
F_21 ( & V_12 -> V_25 ) ;
F_15 ( V_12 , F_33 ( V_16 ) , V_3 ) ;
V_12 -> V_70 [ V_16 ] = V_3 ;
F_35 ( & V_12 -> V_25 ) ;
return V_84 ;
}
static T_3 F_69 ( struct V_18 * V_19 ,
struct V_78 * V_79 , char * V_80 )
{
int V_95 = 0 ;
struct V_11 * V_12 = F_19 ( V_19 ) ;
int V_16 = F_37 ( V_79 ) -> V_81 ;
switch ( ( V_12 -> V_51 >> 2 * V_16 ) & 3 ) {
case 0 :
case 1 :
V_95 = 2 ;
break;
case 2 :
V_95 = 1 ;
break;
case 3 :
if ( V_12 -> type == V_41 )
V_95 = 3 ;
else
V_95 = 1 ;
break;
}
return sprintf ( V_80 , L_2 , V_95 ) ;
}
static T_3 F_70 ( struct V_18 * V_19 , struct V_78
* V_79 , const char * V_80 , T_4 V_84 )
{
struct V_11 * V_12 = F_20 ( V_19 ) ;
int V_85 , V_16 = F_37 ( V_79 ) -> V_81 ;
long V_3 ;
V_85 = F_40 ( V_80 , 10 , & V_3 ) ;
if ( V_85 )
return V_85 ;
if ( V_12 -> type == V_41 && V_16 == 2 && V_3 != 2 )
return - V_96 ;
F_21 ( & V_12 -> V_25 ) ;
V_12 -> V_51 = F_13 ( V_12 , V_52 ) ;
if ( V_12 -> type == V_41 && ( ( V_12 -> V_51 >> 2 * V_16 ) & 1 ) ) {
switch ( V_3 ) {
case 2 :
V_12 -> V_51 &= ~ ( 2 << ( 2 * V_16 ) ) ;
break;
case 3 :
V_12 -> V_51 |= 2 << ( 2 * V_16 ) ;
break;
default:
V_84 = - V_96 ;
goto V_92;
}
} else {
switch ( V_3 ) {
case 1 :
if ( V_12 -> type == V_17 &&
( ( V_12 -> V_51 >> ( 2 * V_16 ) ) & 1 ) ) {
V_84 = - V_96 ;
goto V_92;
}
V_12 -> V_51 |= 2 << ( 2 * V_16 ) ;
break;
case 2 :
V_12 -> V_51 &= ~ ( 2 << ( 2 * V_16 ) ) ;
break;
default:
V_84 = - V_96 ;
goto V_92;
}
}
F_15 ( V_12 , V_52 , V_12 -> V_51 ) ;
V_92:
F_35 ( & V_12 -> V_25 ) ;
return V_84 ;
}
static T_3 F_71 ( struct V_18 * V_19 ,
struct V_78 * V_79 ,
char * V_80 )
{
int V_95 ;
struct V_11 * V_12 = F_19 ( V_19 ) ;
int V_70 = F_37 ( V_79 ) -> V_81 ;
int V_24 = F_37 ( V_79 ) -> V_16 ;
F_21 ( & V_12 -> V_25 ) ;
if ( V_12 -> V_51 & ( 1 << ( 2 * V_70 ) ) ) {
V_95 = V_12 -> V_55 [ V_70 ] [ V_24 ] ;
} else {
V_95 = 32 * 255 / ( 32 + V_12 -> V_55 [ V_70 ] [ V_24 ] ) ;
}
F_35 ( & V_12 -> V_25 ) ;
return sprintf ( V_80 , L_2 , V_95 ) ;
}
static T_3 F_72 ( struct V_18 * V_19 ,
struct V_78 * V_79 ,
const char * V_80 , T_4 V_84 )
{
struct V_11 * V_12 = F_20 ( V_19 ) ;
int V_85 , V_70 = F_37 ( V_79 ) -> V_81 ;
int V_24 = F_37 ( V_79 ) -> V_16 ;
long V_3 ;
V_85 = F_40 ( V_80 , 10 , & V_3 ) ;
if ( V_85 )
return V_85 ;
V_3 = F_41 ( V_3 , 0 , 255 ) ;
F_21 ( & V_12 -> V_25 ) ;
V_12 -> V_51 = F_13 ( V_12 , V_52 ) ;
if ( V_12 -> V_51 & ( 1 << ( 2 * V_70 ) ) ) {
} else {
if ( V_3 < 29 )
V_3 = 255 ;
else
V_3 = ( 255 - V_3 ) * 32 / V_3 ;
}
F_15 ( V_12 , F_28 ( V_70 , V_24 ) , V_3 ) ;
V_12 -> V_55 [ V_70 ] [ V_24 ] = V_3 ;
F_35 ( & V_12 -> V_25 ) ;
return V_84 ;
}
static T_3 F_73 ( struct V_18 * V_19 ,
struct V_78 * V_79 ,
char * V_80 )
{
int V_95 = 0 ;
struct V_11 * V_12 = F_19 ( V_19 ) ;
int V_16 = F_37 ( V_79 ) -> V_81 ;
int V_24 = F_37 ( V_79 ) -> V_16 ;
F_21 ( & V_12 -> V_25 ) ;
if ( V_16 & 1 )
V_95 = V_12 -> V_53 [ V_16 / 2 ] >> 4 ;
else
V_95 = V_12 -> V_53 [ V_16 / 2 ] & 0x0f ;
V_95 = 1000 * ( V_12 -> V_56 [ V_16 ] [ V_24 ] - V_95 ) ;
F_35 ( & V_12 -> V_25 ) ;
return sprintf ( V_80 , L_2 , V_95 ) ;
}
static T_3 F_74 ( struct V_18 * V_19 ,
struct V_78 * V_79 ,
const char * V_80 , T_4 V_84 )
{
struct V_11 * V_12 = F_20 ( V_19 ) ;
int V_85 , V_16 = F_37 ( V_79 ) -> V_81 ;
int V_24 = F_37 ( V_79 ) -> V_16 ;
T_2 V_2 ;
long V_3 ;
V_85 = F_40 ( V_80 , 10 , & V_3 ) ;
if ( V_85 )
return V_85 ;
V_3 /= 1000 ;
F_21 ( & V_12 -> V_25 ) ;
V_12 -> V_56 [ V_16 ] [ V_24 ] =
F_13 ( V_12 , F_29 ( V_16 , V_24 ) ) ;
V_3 = F_41 ( V_3 , V_12 -> V_56 [ V_16 ] [ V_24 ] - 15 ,
V_12 -> V_56 [ V_16 ] [ V_24 ] ) ;
V_3 = V_12 -> V_56 [ V_16 ] [ V_24 ] - V_3 ;
V_2 = F_13 ( V_12 , F_26 ( V_16 / 2 ) ) ;
if ( V_16 & 1 )
V_2 = ( V_2 & 0x0f ) | ( V_3 << 4 ) ;
else
V_2 = ( V_2 & 0xf0 ) | V_3 ;
F_15 ( V_12 , F_26 ( V_16 / 2 ) , V_2 ) ;
V_12 -> V_53 [ V_16 / 2 ] = V_2 ;
F_35 ( & V_12 -> V_25 ) ;
return V_84 ;
}
static T_3 F_75 ( struct V_18 * V_19 ,
struct V_78 * V_79 , char * V_80 )
{
int V_95 ;
struct V_11 * V_12 = F_19 ( V_19 ) ;
int V_16 = F_37 ( V_79 ) -> V_81 ;
V_95 = ( V_12 -> V_54 [ V_16 ] >> 4 ) & 1 ;
return sprintf ( V_80 , L_2 , V_95 ) ;
}
static T_3 F_76 ( struct V_18 * V_19 ,
struct V_78 * V_79 ,
const char * V_80 , T_4 V_84 )
{
struct V_11 * V_12 = F_20 ( V_19 ) ;
int V_85 , V_16 = F_37 ( V_79 ) -> V_81 ;
unsigned long V_3 ;
V_85 = F_44 ( V_80 , 10 , & V_3 ) ;
if ( V_85 )
return V_85 ;
F_21 ( & V_12 -> V_25 ) ;
V_12 -> V_54 [ V_16 ] =
F_13 ( V_12 , F_27 ( V_16 ) ) ;
if ( V_3 )
V_3 = V_12 -> V_54 [ V_16 ] | ( 1 << 4 ) ;
else
V_3 = V_12 -> V_54 [ V_16 ] & ( ~ ( 1 << 4 ) ) ;
F_15 ( V_12 , F_27 ( V_16 ) , V_3 ) ;
V_12 -> V_54 [ V_16 ] = V_3 ;
F_35 ( & V_12 -> V_25 ) ;
return V_84 ;
}
static T_3 F_77 ( struct V_18 * V_19 ,
struct V_78 * V_79 ,
char * V_80 )
{
int V_95 ;
struct V_11 * V_12 = F_19 ( V_19 ) ;
int V_16 = F_37 ( V_79 ) -> V_81 ;
V_95 = 1 << ( ( V_12 -> V_54 [ V_16 ] & 3 ) -
V_12 -> V_38 ) ;
return sprintf ( V_80 , L_2 , V_95 ) ;
}
static T_3 F_78 ( struct V_18 * V_19 ,
struct V_78 * V_79 ,
const char * V_80 , T_4 V_84 )
{
struct V_11 * V_12 = F_20 ( V_19 ) ;
int V_85 , V_16 = F_37 ( V_79 ) -> V_81 ;
long V_3 ;
V_85 = F_40 ( V_80 , 10 , & V_3 ) ;
if ( V_85 )
return V_85 ;
switch ( V_3 ) {
case 1 :
V_3 = 0 ;
break;
case 2 :
V_3 = 1 ;
break;
case 4 :
V_3 = 2 ;
break;
default:
return - V_96 ;
}
V_3 += V_12 -> V_38 ;
F_21 ( & V_12 -> V_25 ) ;
V_12 -> V_54 [ V_16 ] =
F_13 ( V_12 , F_27 ( V_16 ) ) ;
V_3 = ( V_12 -> V_54 [ V_16 ] & 0xfc ) | V_3 ;
F_15 ( V_12 , F_27 ( V_16 ) , V_3 ) ;
V_12 -> V_54 [ V_16 ] = V_3 ;
F_35 ( & V_12 -> V_25 ) ;
return V_84 ;
}
static T_3 F_79 ( struct V_18 * V_19 ,
struct V_78 * V_79 ,
char * V_80 )
{
int V_95 ;
struct V_11 * V_12 = F_19 ( V_19 ) ;
int V_70 = F_37 ( V_79 ) -> V_81 ;
int V_24 = F_37 ( V_79 ) -> V_16 ;
V_95 = V_12 -> V_56 [ V_70 ] [ V_24 ] ;
return sprintf ( V_80 , L_2 , 1000 * V_95 ) ;
}
static T_3 F_80 ( struct V_18 * V_19 ,
struct V_78 * V_79 ,
const char * V_80 , T_4 V_84 )
{
struct V_11 * V_12 = F_20 ( V_19 ) ;
int V_85 , V_70 = F_37 ( V_79 ) -> V_81 ;
int V_24 = F_37 ( V_79 ) -> V_16 ;
long V_3 ;
V_85 = F_40 ( V_80 , 10 , & V_3 ) ;
if ( V_85 )
return V_85 ;
V_3 /= 1000 ;
if ( V_12 -> V_97 )
V_3 = F_41 ( V_3 , - 128 , 127 ) ;
else
V_3 = F_41 ( V_3 , 0 , 127 ) ;
F_21 ( & V_12 -> V_25 ) ;
F_15 ( V_12 , F_29 ( V_70 , V_24 ) , V_3 ) ;
V_12 -> V_56 [ V_70 ] [ V_24 ] = V_3 ;
F_35 ( & V_12 -> V_25 ) ;
return V_84 ;
}
static T_3 F_81 ( struct V_18 * V_19 , struct V_78 * V_79 ,
char * V_80 )
{
struct V_11 * V_12 = F_20 ( V_19 ) ;
return sprintf ( V_80 , L_5 , V_98 [ V_12 -> type ] ) ;
}
static int F_82 ( struct V_99 * V_100 ,
struct V_101 * V_102 , int V_84 )
{
int V_85 , V_103 ;
for ( V_103 = 0 ; V_103 < V_84 ; V_103 ++ ) {
V_85 = F_83 ( & V_100 -> V_19 , & V_102 [ V_103 ] . V_104 ) ;
if ( V_85 )
return V_85 ;
}
return 0 ;
}
static void F_84 ( struct V_99 * V_100 ,
struct V_101 * V_102 , int V_84 )
{
int V_103 ;
for ( V_103 = 0 ; V_103 < V_84 ; V_103 ++ )
F_85 ( & V_100 -> V_19 , & V_102 [ V_103 ] . V_104 ) ;
}
static int F_86 (
struct V_99 * V_100 , int V_105 )
{
struct V_11 * V_12 = F_87 ( V_100 ) ;
int V_85 ;
V_85 = 0 ;
switch ( V_12 -> type ) {
case V_17 :
if ( ( ( V_12 -> V_51 >> ( V_105 * 2 ) ) & 3 ) == 3 )
V_85 = 1 ;
break;
case V_59 :
if ( ( ( V_12 -> V_51 >> ( V_105 * 2 ) ) & 1 ) != 1 )
V_85 = 1 ;
break;
case V_41 :
if ( V_105 == 2 )
V_85 = V_12 -> V_51 & 0x20 ;
break;
default:
break;
}
if ( V_85 ) {
F_88 ( & V_100 -> V_19 ,
L_6
L_7 ,
( V_12 -> V_51 >> ( V_105 * 2 ) ) & 3 , V_105 + 1 ) ;
return 0 ;
}
V_85 = F_82 ( V_100 , & V_106 [ V_105 ] [ 0 ] ,
F_89 ( V_106 [ 0 ] ) ) ;
if ( V_85 )
return V_85 ;
if ( V_45 [ V_12 -> type ] ) {
V_85 = F_82 ( V_100 ,
& V_107 [ V_105 ] ,
1 ) ;
if ( V_85 )
return V_85 ;
}
F_90 ( & V_100 -> V_19 , L_8 , V_105 + 1 ,
( V_12 -> V_51 & ( 1 << ( 2 * V_105 ) ) ) ? L_9 : L_10 ) ;
switch ( V_12 -> type ) {
case V_57 :
case V_71 :
case V_58 :
case V_108 :
case V_109 :
case V_110 :
case V_111 :
V_12 -> V_54 [ V_105 ] =
F_13 ( V_12 , F_27 ( V_105 ) ) ;
if ( ( V_12 -> V_54 [ V_105 ] & 0x80 ) ||
( V_12 -> V_54 [ V_105 ] & 3 ) == 0 ) {
F_91 ( & V_100 -> V_19 ,
L_11
L_12
L_13 , V_105 + 1 ) ;
return 0 ;
}
break;
default:
break;
}
switch ( V_12 -> type ) {
case V_59 :
V_85 = F_82 ( V_100 ,
& V_112 [ V_105 ] [ 0 ] ,
F_89 ( V_112 [ 0 ] ) ) ;
break;
case V_57 :
case V_58 :
V_85 = F_82 ( V_100 ,
& V_113 [ V_105 ] [ 0 ] ,
F_89 ( V_113 [ 0 ] ) ) ;
break;
case V_41 :
V_85 = F_82 ( V_100 ,
& V_114 [ V_105 ] [ 0 ] ,
F_89 ( V_114 [ 0 ] ) ) ;
break;
default:
V_85 = F_82 ( V_100 ,
& V_115 [ V_105 ] [ 0 ] ,
F_89 ( V_115 [ 0 ] ) ) ;
}
return V_85 ;
}
static int F_92 ( struct V_99 * V_100 )
{
struct V_11 * V_12 ;
struct V_116 * V_117 = F_93 ( & V_100 -> V_19 ) ;
int V_20 = V_21 [ V_117 -> type ] ;
int V_22 = V_23 [ V_117 -> type ] ;
int V_85 , V_103 ;
int V_118 ;
T_2 V_119 , V_2 ;
V_12 = F_94 ( & V_100 -> V_19 , sizeof( struct V_11 ) ,
V_120 ) ;
if ( ! V_12 )
return - V_121 ;
V_12 -> V_13 = F_95 ( V_100 , V_122 , 0 ) -> V_123 ;
V_12 -> type = V_117 -> type ;
V_12 -> V_38 =
( V_12 -> type == V_17 || V_12 -> type == V_41 ||
V_12 -> type == V_31 ) ? 0 : 1 ;
F_96 ( & V_12 -> V_25 ) ;
F_97 ( V_100 , V_12 ) ;
V_119 = F_13 ( V_12 , V_124 ) ;
if ( V_119 & 0x04 ) {
F_91 ( & V_100 -> V_19 , L_14 ) ;
return - V_125 ;
}
if ( ! ( V_119 & 0x03 ) ) {
F_91 ( & V_100 -> V_19 , L_15 ) ;
return - V_125 ;
}
V_85 = F_83 ( & V_100 -> V_19 , & V_126 ) ;
if ( V_85 )
goto V_127;
if ( V_119 & 0x01 ) {
switch ( V_12 -> type ) {
case V_17 :
V_12 -> V_87 =
F_13 ( V_12 , V_128 ) ;
if ( V_12 -> V_87 & 0x10 )
V_85 = F_82 ( V_100 ,
V_129 ,
F_89 ( V_129 ) ) ;
else
V_85 = F_82 ( V_100 ,
V_130 ,
F_89 ( V_130 ) ) ;
break;
case V_41 :
V_85 = F_82 ( V_100 ,
V_129 ,
F_89 ( V_129 ) ) ;
break;
case V_31 :
V_85 = F_82 ( V_100 ,
V_130 ,
F_89 ( V_130 ) ) ;
break;
default:
V_85 = F_82 ( V_100 ,
& V_131 [ 0 ] [ 0 ] ,
F_89 ( V_131 [ 0 ] ) * V_22 ) ;
}
if ( V_85 )
goto V_127;
if ( V_48 [ V_12 -> type ] ) {
if ( V_12 -> type == V_31 ) {
V_118 = F_89 ( V_132 [ 0 ] ) ;
V_85 = F_82 ( V_100 ,
& V_132 [ 0 ] [ 0 ] ,
V_118 * V_22 ) ;
} else {
V_118 = F_89 ( V_133 [ 0 ] ) ;
V_85 = F_82 ( V_100 ,
& V_133 [ 0 ] [ 0 ] ,
V_118 * V_22 ) ;
}
if ( V_85 )
goto V_127;
}
for ( V_103 = 0 ; V_103 < V_75 ; V_103 ++ ) {
if ( V_76 [ V_12 -> type ] [ V_103 ] ) {
V_85 = F_83 ( & V_100 -> V_19 ,
& V_134 [ V_103 ] . V_104 ) ;
if ( V_85 )
goto V_127;
}
}
if ( V_30 [ V_12 -> type ] ) {
V_85 = F_82 ( V_100 ,
V_135 ,
F_89 ( V_135 ) ) ;
if ( V_85 )
goto V_127;
}
}
if ( V_119 & 0x02 ) {
switch ( V_12 -> type ) {
case V_57 :
case V_71 :
case V_58 :
case V_108 :
V_12 -> V_97 = 1 ;
case V_109 :
case V_110 :
case V_111 :
V_2 = F_13 ( V_12 , V_136 ) ;
if ( V_2 & V_137 )
V_12 -> V_97 = 1 ;
V_2 &= ~ V_138 ;
F_15 ( V_12 , V_136 , V_2 ) ;
break;
default:
break;
}
V_12 -> V_51 =
F_13 ( V_12 , V_52 ) ;
for ( V_103 = 0 ; V_103 < V_20 ; V_103 ++ ) {
V_85 = F_86 ( V_100 , V_103 ) ;
if ( V_85 )
goto V_127;
}
switch ( V_12 -> type ) {
case V_71 :
V_85 = F_82 ( V_100 ,
V_139 ,
F_89 ( V_139 ) ) ;
break;
case V_41 :
V_85 = F_82 ( V_100 ,
V_140 ,
F_89 ( V_140 ) ) ;
break;
default:
break;
}
if ( V_85 )
goto V_127;
}
V_12 -> V_141 = F_98 ( & V_100 -> V_19 ) ;
if ( F_99 ( V_12 -> V_141 ) ) {
V_85 = F_100 ( V_12 -> V_141 ) ;
V_12 -> V_141 = NULL ;
goto V_127;
}
return 0 ;
V_127:
F_101 ( V_100 ) ;
return V_85 ;
}
static int F_101 ( struct V_99 * V_100 )
{
struct V_11 * V_12 = F_87 ( V_100 ) ;
int V_20 = V_21 [ V_12 -> type ] ;
int V_22 = V_23 [ V_12 -> type ] ;
int V_103 ;
T_2 V_119 = F_13 ( V_12 , V_124 ) ;
if ( V_12 -> V_141 )
F_102 ( V_12 -> V_141 ) ;
F_85 ( & V_100 -> V_19 , & V_126 ) ;
if ( V_119 & 0x01 ) {
switch ( V_12 -> type ) {
case V_17 :
if ( V_12 -> V_87 & 0x10 )
F_84 ( V_100 ,
V_129 ,
F_89 ( V_129 ) ) ;
else
F_84 ( V_100 ,
V_130 ,
F_89 ( V_130 ) ) ;
break;
case V_41 :
F_84 ( V_100 ,
V_129 ,
F_89 ( V_129 ) ) ;
break;
case V_31 :
F_84 ( V_100 ,
V_130 ,
F_89 ( V_130 ) ) ;
break;
default:
F_84 ( V_100 ,
& V_131 [ 0 ] [ 0 ] ,
F_89 ( V_131 [ 0 ] ) * V_22 ) ;
}
if ( V_48 [ V_12 -> type ] ) {
if ( V_12 -> type == V_31 )
F_84 ( V_100 ,
& V_132 [ 0 ] [ 0 ] ,
F_89 ( V_132 [ 0 ] )
* V_22 ) ;
else
F_84 ( V_100 ,
& V_133 [ 0 ] [ 0 ] ,
F_89 ( V_133 [ 0 ] )
* V_22 ) ;
}
for ( V_103 = 0 ; V_103 < V_75 ; V_103 ++ ) {
if ( V_76 [ V_12 -> type ] [ V_103 ] ) {
F_85 ( & V_100 -> V_19 ,
& V_134 [ V_103 ] . V_104 ) ;
}
}
if ( V_30 [ V_12 -> type ] ) {
F_84 ( V_100 ,
V_135 ,
F_89 ( V_135 ) ) ;
}
}
if ( V_119 & 0x02 ) {
F_84 ( V_100 , & V_106 [ 0 ] [ 0 ] ,
F_89 ( V_106 [ 0 ] ) * V_20 ) ;
if ( V_45 [ V_12 -> type ] ) {
F_84 ( V_100 ,
V_107 , V_20 ) ;
}
switch ( V_12 -> type ) {
case V_71 :
F_84 ( V_100 ,
& V_115 [ 0 ] [ 0 ] ,
F_89 ( V_115 [ 0 ] ) * V_20 ) ;
F_84 ( V_100 ,
V_139 ,
F_89 ( V_139 ) ) ;
break;
case V_59 :
F_84 ( V_100 ,
& V_112 [ 0 ] [ 0 ] ,
F_89 ( V_112 [ 0 ] ) *
V_20 ) ;
break;
case V_57 :
case V_58 :
F_84 ( V_100 ,
& V_113 [ 0 ] [ 0 ] ,
F_89 ( V_113 [ 0 ] ) * V_20 ) ;
break;
case V_41 :
F_84 ( V_100 ,
V_140 ,
F_89 ( V_140 ) ) ;
F_84 ( V_100 ,
& V_114 [ 0 ] [ 0 ] ,
F_89 ( V_114 [ 0 ] ) * V_20 ) ;
break;
default:
F_84 ( V_100 ,
& V_115 [ 0 ] [ 0 ] ,
F_89 ( V_115 [ 0 ] ) * V_20 ) ;
}
}
return 0 ;
}
static int T_5 F_103 ( int V_142 , struct V_116 * V_117 )
{
T_1 V_143 ;
unsigned short V_144 ;
int V_85 = F_5 ( V_142 ) ;
if ( V_85 )
return V_85 ;
V_143 = F_4 ( V_142 , V_145 ) ;
if ( V_143 != V_146 ) {
F_104 ( L_16 ) ;
V_85 = - V_125 ;
goto exit;
}
V_143 = V_147 ? V_147 : F_4 ( V_142 , V_148 ) ;
switch ( V_143 ) {
case V_149 :
V_117 -> type = V_57 ;
break;
case V_150 :
V_117 -> type = V_71 ;
break;
case V_151 :
V_117 -> type = V_17 ;
break;
case V_152 :
V_117 -> type = V_59 ;
break;
case V_153 :
V_117 -> type = V_154 ;
break;
case V_155 :
V_117 -> type = V_58 ;
break;
case V_156 :
V_117 -> type = V_108 ;
break;
case V_157 :
V_117 -> type = V_158 ;
break;
case V_159 :
V_117 -> type = V_109 ;
break;
case V_160 :
V_117 -> type = V_110 ;
break;
case V_161 :
V_117 -> type = V_111 ;
break;
case V_162 :
V_117 -> type = V_41 ;
break;
case V_163 :
V_117 -> type = V_164 ;
break;
case V_165 :
V_117 -> type = V_166 ;
break;
case V_167 :
V_117 -> type = V_31 ;
break;
default:
F_105 ( L_17 ,
( unsigned int ) V_143 ) ;
V_85 = - V_125 ;
goto exit;
}
if ( V_117 -> type == V_17 )
F_8 ( V_142 , V_168 ) ;
else
F_8 ( V_142 , V_169 ) ;
if ( ! ( F_1 ( V_142 , V_170 ) & 0x01 ) ) {
F_106 ( L_18 ) ;
V_85 = - V_125 ;
goto exit;
}
V_144 = F_4 ( V_142 , V_171 ) ;
if ( V_144 == 0 ) {
F_106 ( L_19 ) ;
V_85 = - V_125 ;
goto exit;
}
V_144 &= ~ ( V_172 - 1 ) ;
V_85 = V_144 ;
F_105 ( L_20 ,
V_98 [ V_117 -> type ] , ( unsigned int ) V_144 ,
( int ) F_1 ( V_142 , V_173 ) ) ;
exit:
F_9 ( V_142 ) ;
return V_85 ;
}
static int T_5 F_107 ( int V_144 ,
const struct V_116 * V_117 )
{
struct V_174 V_175 = {
. V_123 = V_144 ,
. V_176 = V_144 + V_172 - 1 ,
. V_177 = V_122 ,
} ;
int V_85 ;
V_178 = F_108 ( V_4 , V_144 ) ;
if ( ! V_178 )
return - V_121 ;
V_175 . V_179 = V_178 -> V_179 ;
V_85 = F_109 ( & V_175 ) ;
if ( V_85 )
goto V_180;
V_85 = F_110 ( V_178 , & V_175 , 1 ) ;
if ( V_85 ) {
F_7 ( L_21 ) ;
goto V_180;
}
V_85 = F_111 ( V_178 , V_117 ,
sizeof( struct V_116 ) ) ;
if ( V_85 ) {
F_7 ( L_22 ) ;
goto V_180;
}
V_85 = F_112 ( V_178 ) ;
if ( V_85 ) {
F_7 ( L_23 ) ;
goto V_180;
}
return 0 ;
V_180:
F_113 ( V_178 ) ;
return V_85 ;
}
static int T_5 F_114 ( void )
{
int V_85 ;
int V_144 ;
struct V_116 V_117 ;
memset ( & V_117 , 0 , sizeof( V_117 ) ) ;
V_144 = F_103 ( 0x2e , & V_117 ) ;
if ( V_144 < 0 )
V_144 = F_103 ( 0x4e , & V_117 ) ;
if ( V_144 < 0 )
return V_144 ;
V_85 = F_115 ( & V_181 ) ;
if ( V_85 )
return V_85 ;
V_85 = F_107 ( V_144 , & V_117 ) ;
if ( V_85 )
goto V_182;
return 0 ;
V_182:
F_116 ( & V_181 ) ;
return V_85 ;
}
static void T_6 F_117 ( void )
{
F_118 ( V_178 ) ;
F_116 ( & V_181 ) ;
}
