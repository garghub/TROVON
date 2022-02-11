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
V_12 -> V_31 =
F_13 ( V_12 , V_32 ) ;
V_12 -> V_33 =
F_13 ( V_12 , V_34 ) ;
}
for ( V_16 = V_12 -> V_35 ; V_16 < V_22 + V_12 -> V_35 ;
V_16 ++ ) {
V_12 -> V_36 [ V_16 ] = F_13 ( V_12 ,
F_23 ( V_16 ) ) ;
V_12 -> V_37 [ V_16 ] = F_13 ( V_12 ,
F_24 ( V_16 ) ) ;
}
if ( V_12 -> type != V_38 ) {
V_12 -> V_39 [ 0 ] = F_13 ( V_12 ,
F_25 ( 0 ) ) ;
V_12 -> V_39 [ 1 ] = F_13 ( V_12 ,
F_25 ( 1 ) ) ;
}
if ( ( V_12 -> type != V_17 ) && ( V_12 -> type != V_38 ) ) {
V_2 = F_13 ( V_12 , V_40 ) ;
V_12 -> V_41 [ 1 ] = ( V_2 & 0x02 ) ? 2 : 4 ;
V_12 -> V_41 [ 2 ] = ( V_2 & 0x04 ) ? 2 : 4 ;
V_12 -> V_41 [ 3 ] = ( V_2 & 0x08 ) ? 2 : 4 ;
}
if ( V_42 [ V_12 -> type ] )
V_12 -> V_43 = F_13 ( V_12 ,
V_44 ) ;
if ( V_45 [ V_12 -> type ] )
V_12 -> V_46 = F_13 ( V_12 ,
V_47 ) ;
V_12 -> V_48 = F_13 ( V_12 ,
V_49 ) ;
V_12 -> V_50 [ 0 ] =
F_13 ( V_12 , F_26 ( 0 ) ) ;
V_12 -> V_50 [ 1 ] =
F_13 ( V_12 , F_26 ( 1 ) ) ;
for ( V_16 = 0 ; V_16 < V_20 ; V_16 ++ ) {
V_12 -> V_51 [ V_16 ] =
F_13 ( V_12 ,
F_27 ( V_16 ) ) ;
switch ( V_12 -> type ) {
default:
for ( V_24 = 0 ; V_24 < 5 ; V_24 ++ ) {
V_12 -> V_52 [ V_16 ] [ V_24 ] =
F_13 ( V_12 ,
F_28
( V_16 , V_24 ) ) ;
}
for ( V_24 = 0 ; V_24 < 4 ; V_24 ++ ) {
V_12 -> V_53 [ V_16 ] [ V_24 ] =
F_13 ( V_12 ,
F_29
( V_16 , V_24 ) ) ;
}
break;
case V_54 :
case V_55 :
V_12 -> V_52 [ V_16 ] [ 0 ] =
F_13 ( V_12 ,
F_28 ( V_16 , 0 ) ) ;
case V_56 :
V_12 -> V_52 [ V_16 ] [ 1 ] =
F_13 ( V_12 ,
F_28
( V_16 , 1 ) ) ;
V_12 -> V_52 [ V_16 ] [ 4 ] =
F_13 ( V_12 ,
F_28
( V_16 , 4 ) ) ;
V_12 -> V_53 [ V_16 ] [ 0 ] =
F_13 ( V_12 ,
F_29
( V_16 , 0 ) ) ;
V_12 -> V_53 [ V_16 ] [ 3 ] =
F_13 ( V_12 ,
F_29
( V_16 , 3 ) ) ;
break;
}
}
V_12 -> V_27 = V_26 ;
}
if ( F_22 ( V_26 , V_12 -> V_57 + V_28 ) || ! V_12 -> V_29 ) {
V_12 -> V_58 = F_13 ( V_12 ,
V_59 ) ;
V_12 -> V_60 = F_13 ( V_12 ,
V_61 ) ;
for ( V_16 = V_12 -> V_35 ; V_16 < V_22 + V_12 -> V_35 ;
V_16 ++ )
V_12 -> V_62 [ V_16 ] = F_17 ( V_12 , V_16 ) ;
V_12 -> V_63 = F_13 ( V_12 ,
V_64 ) ;
for ( V_16 = 0 ; V_16 < V_20 ; V_16 ++ ) {
V_12 -> V_10 [ V_16 ] = F_14 ( V_12 ,
F_30 ( V_16 ) ) ;
V_12 -> V_65 [ V_16 ] =
F_14 ( V_12 , F_31 ( V_16 ) ) ;
V_12 -> V_66 [ V_16 ] =
F_14 ( V_12 ,
F_32 ( V_16 ) ) ;
V_12 -> V_67 [ V_16 ] =
F_13 ( V_12 , F_33 ( V_16 ) ) ;
}
if ( V_12 -> type == V_68 ) {
V_12 -> V_10 [ 2 ] = F_14 ( V_12 ,
F_30 ( 2 ) ) ;
V_12 -> V_67 [ 2 ] = F_13 ( V_12 ,
F_33 ( 2 ) ) ;
}
if ( V_12 -> type == V_38 )
V_12 -> V_10 [ 3 ] = F_14 ( V_12 ,
F_30 ( 3 ) ) ;
if ( V_30 [ V_12 -> type ] )
V_12 -> V_69 = F_13 ( V_12 ,
V_70 ) ;
for ( V_16 = 0 ; V_16 < V_71 ; V_16 ++ )
if ( V_72 [ V_12 -> type ] [ V_16 ] )
V_12 -> V_73 [ V_16 ] = F_13 ( V_12 ,
F_34 ( V_16 ) ) ;
V_12 -> V_57 = V_26 ;
V_12 -> V_29 = 1 ;
}
F_35 ( & V_12 -> V_25 ) ;
return V_12 ;
}
static T_3 F_36 ( struct V_18 * V_19 , struct V_74 * V_75 ,
char * V_76 )
{
struct V_11 * V_12 = F_19 ( V_19 ) ;
int V_16 = F_37 ( V_75 ) -> V_77 ;
int V_78 = F_11 ( V_12 -> V_10 [ V_16 ] ) ;
if ( V_78 == V_79 )
V_78 = 0 ;
return sprintf ( V_76 , L_2 , V_78 ) ;
}
static T_3 F_38 ( struct V_18 * V_19 ,
struct V_74 * V_75 , char * V_76 )
{
struct V_11 * V_12 = F_19 ( V_19 ) ;
int V_16 = F_37 ( V_75 ) -> V_77 ;
int V_78 = F_11 ( V_12 -> V_66 [ V_16 ] ) ;
return sprintf ( V_76 , L_2 , V_78 ) ;
}
static T_3 F_39 ( struct V_18 * V_19 ,
struct V_74 * V_75 ,
const char * V_76 , T_4 V_80 )
{
struct V_11 * V_12 = F_20 ( V_19 ) ;
int V_81 , V_16 = F_37 ( V_75 ) -> V_77 ;
long V_3 ;
V_81 = F_40 ( V_76 , 10 , & V_3 ) ;
if ( V_81 )
return V_81 ;
V_3 = F_41 ( V_3 , 23 , 1500000 ) ;
V_3 = F_12 ( V_3 ) ;
F_21 ( & V_12 -> V_25 ) ;
F_16 ( V_12 , F_32 ( V_16 ) , V_3 ) ;
V_12 -> V_66 [ V_16 ] = V_3 ;
F_35 ( & V_12 -> V_25 ) ;
return V_80 ;
}
static T_3 F_42 ( struct V_18 * V_19 , struct V_74
* V_75 , char * V_76 )
{
struct V_11 * V_12 = F_19 ( V_19 ) ;
int V_16 = F_37 ( V_75 ) -> V_77 ;
if ( V_12 -> V_43 & ( 1 << V_16 ) )
return sprintf ( V_76 , L_3 ) ;
else
return sprintf ( V_76 , L_4 ) ;
}
static T_3 F_43 ( struct V_18 * V_19 , struct V_74
* V_75 , const char * V_76 , T_4 V_80 )
{
struct V_11 * V_12 = F_20 ( V_19 ) ;
int V_81 , V_16 = F_37 ( V_75 ) -> V_77 ;
unsigned long V_3 ;
V_81 = F_44 ( V_76 , 10 , & V_3 ) ;
if ( V_81 )
return V_81 ;
F_21 ( & V_12 -> V_25 ) ;
V_12 -> V_43 = F_13 ( V_12 , V_44 ) ;
if ( V_3 )
V_12 -> V_43 |= 1 << V_16 ;
else
V_12 -> V_43 &= ~ ( 1 << V_16 ) ;
F_15 ( V_12 , V_44 , V_12 -> V_43 ) ;
F_35 ( & V_12 -> V_25 ) ;
return V_80 ;
}
static T_3 F_45 ( struct V_18 * V_19 , struct V_74
* V_75 , char * V_76 )
{
struct V_11 * V_12 = F_19 ( V_19 ) ;
int V_16 = F_37 ( V_75 ) -> V_77 ;
if ( V_12 -> V_63 & ( 1 << V_16 ) )
return sprintf ( V_76 , L_3 ) ;
else
return sprintf ( V_76 , L_4 ) ;
}
static T_3 F_46 ( struct V_18 * V_19 , struct V_74 * V_75 ,
char * V_76 )
{
struct V_11 * V_12 = F_19 ( V_19 ) ;
int V_16 = F_37 ( V_75 ) -> V_77 ;
return sprintf ( V_76 , L_2 , V_12 -> V_73 [ V_16 ] * 8 ) ;
}
static T_3 F_47 ( struct V_18 * V_19 , struct V_74
* V_75 , char * V_76 )
{
struct V_11 * V_12 = F_19 ( V_19 ) ;
return sprintf ( V_76 , L_2 , V_12 -> V_31 * 8 ) ;
}
static T_3 F_48 ( struct V_18 * V_19 , struct V_74
* V_75 , const char * V_76 , T_4 V_80 )
{
struct V_11 * V_12 = F_20 ( V_19 ) ;
int V_81 ;
long V_3 ;
V_81 = F_40 ( V_76 , 10 , & V_3 ) ;
if ( V_81 )
return V_81 ;
V_3 /= 8 ;
V_3 = F_41 ( V_3 , 0 , 255 ) ;
F_21 ( & V_12 -> V_25 ) ;
F_15 ( V_12 , V_32 , V_3 ) ;
V_12 -> V_31 = V_3 ;
F_35 ( & V_12 -> V_25 ) ;
return V_80 ;
}
static T_3 F_49 ( struct V_18 * V_19 , struct V_74
* V_75 , char * V_76 )
{
struct V_11 * V_12 = F_19 ( V_19 ) ;
int V_16 = F_37 ( V_75 ) -> V_77 ;
if ( V_12 -> V_33 & ( 1 << V_16 ) )
return sprintf ( V_76 , L_3 ) ;
else
return sprintf ( V_76 , L_4 ) ;
}
static T_3 F_50 ( struct V_18 * V_19 , struct V_74
* V_75 , const char * V_76 , T_4 V_80 )
{
struct V_11 * V_12 = F_20 ( V_19 ) ;
int V_81 , V_16 = F_37 ( V_75 ) -> V_77 ;
unsigned long V_3 ;
V_81 = F_44 ( V_76 , 10 , & V_3 ) ;
if ( V_81 )
return V_81 ;
F_21 ( & V_12 -> V_25 ) ;
V_12 -> V_33 = F_13 ( V_12 , V_34 ) ;
if ( V_3 )
V_12 -> V_33 |= 1 << V_16 ;
else
V_12 -> V_33 &= ~ ( 1 << V_16 ) ;
F_15 ( V_12 , V_34 , V_12 -> V_33 ) ;
F_35 ( & V_12 -> V_25 ) ;
return V_80 ;
}
static T_3 F_51 ( struct V_18 * V_19 , struct V_74
* V_75 , char * V_76 )
{
struct V_11 * V_12 = F_19 ( V_19 ) ;
int V_16 = F_37 ( V_75 ) -> V_77 ;
if ( V_12 -> V_69 & ( 1 << V_16 ) )
return sprintf ( V_76 , L_3 ) ;
else
return sprintf ( V_76 , L_4 ) ;
}
static T_3 F_52 ( struct V_18 * V_19 , struct V_74 * V_75 ,
char * V_76 )
{
struct V_11 * V_12 = F_19 ( V_19 ) ;
int V_16 = F_37 ( V_75 ) -> V_77 ;
int V_82 , V_62 ;
if ( V_12 -> type == V_17 ) {
if ( V_12 -> V_83 & 1 ) {
V_82 = V_12 -> V_62 [ V_16 ] & 0x0001 ;
V_62 = ( V_12 -> V_62 [ V_16 ] >> 5 ) & 0x7ff ;
} else {
V_82 = V_12 -> V_62 [ V_16 ] & 0x8000 ;
V_62 = ( V_12 -> V_62 [ V_16 ] >> 5 ) & 0x3ff ;
}
V_62 *= 125 ;
if ( V_82 )
V_62 -= 128000 ;
} else
V_62 = V_12 -> V_62 [ V_16 ] * 1000 ;
return sprintf ( V_76 , L_2 , V_62 ) ;
}
static T_3 F_53 ( struct V_18 * V_19 , struct V_74
* V_75 , char * V_76 )
{
struct V_11 * V_12 = F_19 ( V_19 ) ;
int V_16 = F_37 ( V_75 ) -> V_77 ;
return sprintf ( V_76 , L_2 , V_12 -> V_37 [ V_16 ] * 1000 ) ;
}
static T_3 F_54 ( struct V_18 * V_19 , struct V_74
* V_75 , const char * V_76 , T_4 V_80 )
{
struct V_11 * V_12 = F_20 ( V_19 ) ;
int V_81 , V_16 = F_37 ( V_75 ) -> V_77 ;
long V_3 ;
V_81 = F_40 ( V_76 , 10 , & V_3 ) ;
if ( V_81 )
return V_81 ;
V_3 /= 1000 ;
V_3 = F_41 ( V_3 , 0 , 255 ) ;
F_21 ( & V_12 -> V_25 ) ;
F_15 ( V_12 , F_24 ( V_16 ) , V_3 ) ;
V_12 -> V_37 [ V_16 ] = V_3 ;
F_35 ( & V_12 -> V_25 ) ;
return V_80 ;
}
static T_3 F_55 ( struct V_18 * V_19 , struct V_74
* V_75 , char * V_76 )
{
struct V_11 * V_12 = F_19 ( V_19 ) ;
int V_16 = F_37 ( V_75 ) -> V_77 ;
int V_84 ;
F_21 ( & V_12 -> V_25 ) ;
if ( V_16 & 1 )
V_84 = V_12 -> V_39 [ V_16 / 2 ] >> 4 ;
else
V_84 = V_12 -> V_39 [ V_16 / 2 ] & 0x0f ;
V_84 = ( V_12 -> V_37 [ V_16 ] - V_84 ) * 1000 ;
F_35 ( & V_12 -> V_25 ) ;
return sprintf ( V_76 , L_2 , V_84 ) ;
}
static T_3 F_56 ( struct V_18 * V_19 , struct V_74
* V_75 , const char * V_76 , T_4 V_80 )
{
struct V_11 * V_12 = F_20 ( V_19 ) ;
int V_81 , V_16 = F_37 ( V_75 ) -> V_77 ;
T_3 V_85 = V_80 ;
T_2 V_2 ;
long V_3 ;
V_81 = F_40 ( V_76 , 10 , & V_3 ) ;
if ( V_81 )
return V_81 ;
V_3 /= 1000 ;
F_21 ( & V_12 -> V_25 ) ;
V_12 -> V_37 [ V_16 ] = F_13 ( V_12 , F_24 ( V_16 ) ) ;
V_3 = F_41 ( V_3 , V_12 -> V_37 [ V_16 ] - 15 ,
V_12 -> V_37 [ V_16 ] ) ;
V_3 = V_12 -> V_37 [ V_16 ] - V_3 ;
V_2 = F_13 ( V_12 , F_25 ( V_16 / 2 ) ) ;
if ( V_16 & 1 )
V_2 = ( V_2 & 0x0f ) | ( V_3 << 4 ) ;
else
V_2 = ( V_2 & 0xf0 ) | V_3 ;
F_15 ( V_12 , F_25 ( V_16 / 2 ) , V_2 ) ;
V_12 -> V_39 [ V_16 / 2 ] = V_2 ;
F_35 ( & V_12 -> V_25 ) ;
return V_85 ;
}
static T_3 F_57 ( struct V_18 * V_19 , struct V_74
* V_75 , char * V_76 )
{
struct V_11 * V_12 = F_19 ( V_19 ) ;
int V_16 = F_37 ( V_75 ) -> V_77 ;
return sprintf ( V_76 , L_2 , V_12 -> V_36 [ V_16 ] * 1000 ) ;
}
static T_3 F_58 ( struct V_18 * V_19 , struct V_74
* V_75 , const char * V_76 , T_4 V_80 )
{
struct V_11 * V_12 = F_20 ( V_19 ) ;
int V_81 , V_16 = F_37 ( V_75 ) -> V_77 ;
long V_3 ;
V_81 = F_40 ( V_76 , 10 , & V_3 ) ;
if ( V_81 )
return V_81 ;
V_3 /= 1000 ;
V_3 = F_41 ( V_3 , 0 , 255 ) ;
F_21 ( & V_12 -> V_25 ) ;
F_15 ( V_12 , F_23 ( V_16 ) , V_3 ) ;
V_12 -> V_36 [ V_16 ] = V_3 ;
F_35 ( & V_12 -> V_25 ) ;
return V_80 ;
}
static T_3 F_59 ( struct V_18 * V_19 , struct V_74
* V_75 , char * V_76 )
{
struct V_11 * V_12 = F_19 ( V_19 ) ;
int V_16 = F_37 ( V_75 ) -> V_77 ;
int V_86 ;
F_21 ( & V_12 -> V_25 ) ;
if ( V_16 & 1 )
V_86 = V_12 -> V_39 [ V_16 / 2 ] >> 4 ;
else
V_86 = V_12 -> V_39 [ V_16 / 2 ] & 0x0f ;
V_86 = ( V_12 -> V_36 [ V_16 ] - V_86 ) * 1000 ;
F_35 ( & V_12 -> V_25 ) ;
return sprintf ( V_76 , L_2 , V_86 ) ;
}
static T_3 F_60 ( struct V_18 * V_19 , struct V_74
* V_75 , char * V_76 )
{
struct V_11 * V_12 = F_19 ( V_19 ) ;
int V_16 = F_37 ( V_75 ) -> V_77 ;
return sprintf ( V_76 , L_2 , V_12 -> V_41 [ V_16 ] ) ;
}
static T_3 F_61 ( struct V_18 * V_19 , struct V_74
* V_75 , char * V_76 )
{
struct V_11 * V_12 = F_19 ( V_19 ) ;
int V_16 = F_37 ( V_75 ) -> V_77 ;
if ( V_12 -> V_46 & ( 1 << V_16 ) )
return sprintf ( V_76 , L_3 ) ;
else
return sprintf ( V_76 , L_4 ) ;
}
static T_3 F_62 ( struct V_18 * V_19 , struct V_74
* V_75 , const char * V_76 , T_4 V_80 )
{
struct V_11 * V_12 = F_20 ( V_19 ) ;
int V_81 , V_16 = F_37 ( V_75 ) -> V_77 ;
unsigned long V_3 ;
V_81 = F_44 ( V_76 , 10 , & V_3 ) ;
if ( V_81 )
return V_81 ;
F_21 ( & V_12 -> V_25 ) ;
V_12 -> V_46 = F_13 ( V_12 , V_47 ) ;
if ( V_3 )
V_12 -> V_46 |= 1 << V_16 ;
else
V_12 -> V_46 &= ~ ( 1 << V_16 ) ;
F_15 ( V_12 , V_47 , V_12 -> V_46 ) ;
F_35 ( & V_12 -> V_25 ) ;
return V_80 ;
}
static T_3 F_63 ( struct V_18 * V_19 , struct V_74
* V_75 , char * V_76 )
{
struct V_11 * V_12 = F_19 ( V_19 ) ;
int V_16 = F_37 ( V_75 ) -> V_77 ;
if ( V_12 -> V_58 & ( 1 << V_16 ) )
return sprintf ( V_76 , L_3 ) ;
else
return sprintf ( V_76 , L_4 ) ;
}
static T_3 F_64 ( struct V_18 * V_19 , struct V_74
* V_75 , char * V_76 )
{
struct V_11 * V_12 = F_19 ( V_19 ) ;
int V_16 = F_37 ( V_75 ) -> V_77 ;
if ( V_12 -> V_60 & ( 1 << V_16 ) )
return sprintf ( V_76 , L_3 ) ;
else
return sprintf ( V_76 , L_4 ) ;
}
static T_3 F_65 ( struct V_18 * V_19 ,
struct V_74 * V_75 , char * V_76 )
{
struct V_11 * V_12 = F_19 ( V_19 ) ;
int V_3 , V_16 = F_37 ( V_75 ) -> V_77 ;
F_21 ( & V_12 -> V_25 ) ;
if ( V_12 -> V_48 & ( 1 << ( 2 * V_16 ) ) )
V_3 = V_12 -> V_67 [ V_16 ] ;
else {
V_3 = 255 * F_11 ( V_12 -> V_65 [ V_16 ] )
/ F_11 ( V_12 -> V_66 [ V_16 ] ) ;
}
F_35 ( & V_12 -> V_25 ) ;
return sprintf ( V_76 , L_2 , V_3 ) ;
}
static T_3 F_66 ( struct V_18 * V_19 ,
struct V_74 * V_75 , const char * V_76 ,
T_4 V_80 )
{
struct V_11 * V_12 = F_20 ( V_19 ) ;
int V_81 , V_16 = F_37 ( V_75 ) -> V_77 ;
long V_3 ;
V_81 = F_40 ( V_76 , 10 , & V_3 ) ;
if ( V_81 )
return V_81 ;
V_3 = F_41 ( V_3 , 0 , 255 ) ;
F_21 ( & V_12 -> V_25 ) ;
V_12 -> V_48 = F_13 ( V_12 , V_49 ) ;
if ( ( V_12 -> type == V_38 && ( ( V_12 -> V_48 >> 2 * V_16 ) & 3 ) != 2 ) ||
( V_12 -> type != V_38 && ! ( ( V_12 -> V_48 >> 2 * V_16 ) & 2 ) ) ) {
V_80 = - V_87 ;
goto V_88;
}
if ( V_12 -> V_48 & ( 1 << ( 2 * V_16 ) ) ) {
F_15 ( V_12 , F_33 ( V_16 ) , V_3 ) ;
V_12 -> V_67 [ V_16 ] = V_3 ;
} else {
int V_89 , V_90 ;
V_90 = F_14 ( V_12 ,
F_32 ( V_16 ) ) ;
V_89 = F_12 ( V_3 * F_11 ( V_90 ) / 255 ) ;
F_16 ( V_12 , F_31 ( V_16 ) , V_89 ) ;
V_12 -> V_65 [ V_16 ] = V_89 ;
V_12 -> V_66 [ V_16 ] = V_90 ;
}
V_88:
F_35 ( & V_12 -> V_25 ) ;
return V_80 ;
}
static T_3 F_67 ( struct V_18 * V_19 ,
struct V_74 * V_75 , char * V_76 )
{
struct V_11 * V_12 = F_19 ( V_19 ) ;
int V_3 , V_16 = F_37 ( V_75 ) -> V_77 ;
V_3 = V_12 -> V_67 [ V_16 ] ;
return sprintf ( V_76 , L_2 , V_3 ) ;
}
static T_3 F_68 ( struct V_18 * V_19 ,
struct V_74 * V_75 ,
const char * V_76 , T_4 V_80 )
{
struct V_11 * V_12 = F_20 ( V_19 ) ;
int V_81 , V_16 = F_37 ( V_75 ) -> V_77 ;
long V_3 ;
V_81 = F_40 ( V_76 , 10 , & V_3 ) ;
if ( V_81 )
return V_81 ;
V_3 = F_41 ( V_3 , 0 , 255 ) ;
F_21 ( & V_12 -> V_25 ) ;
F_15 ( V_12 , F_33 ( V_16 ) , V_3 ) ;
V_12 -> V_67 [ V_16 ] = V_3 ;
F_35 ( & V_12 -> V_25 ) ;
return V_80 ;
}
static T_3 F_69 ( struct V_18 * V_19 ,
struct V_74 * V_75 , char * V_76 )
{
int V_91 = 0 ;
struct V_11 * V_12 = F_19 ( V_19 ) ;
int V_16 = F_37 ( V_75 ) -> V_77 ;
switch ( ( V_12 -> V_48 >> 2 * V_16 ) & 3 ) {
case 0 :
case 1 :
V_91 = 2 ;
break;
case 2 :
V_91 = 1 ;
break;
case 3 :
if ( V_12 -> type == V_38 )
V_91 = 3 ;
else
V_91 = 1 ;
break;
}
return sprintf ( V_76 , L_2 , V_91 ) ;
}
static T_3 F_70 ( struct V_18 * V_19 , struct V_74
* V_75 , const char * V_76 , T_4 V_80 )
{
struct V_11 * V_12 = F_20 ( V_19 ) ;
int V_81 , V_16 = F_37 ( V_75 ) -> V_77 ;
long V_3 ;
V_81 = F_40 ( V_76 , 10 , & V_3 ) ;
if ( V_81 )
return V_81 ;
if ( V_12 -> type == V_38 && V_16 == 2 && V_3 != 2 )
return - V_92 ;
F_21 ( & V_12 -> V_25 ) ;
V_12 -> V_48 = F_13 ( V_12 , V_49 ) ;
if ( V_12 -> type == V_38 && ( ( V_12 -> V_48 >> 2 * V_16 ) & 1 ) ) {
switch ( V_3 ) {
case 2 :
V_12 -> V_48 &= ~ ( 2 << ( 2 * V_16 ) ) ;
break;
case 3 :
V_12 -> V_48 |= 2 << ( 2 * V_16 ) ;
break;
default:
V_80 = - V_92 ;
goto V_88;
}
} else {
switch ( V_3 ) {
case 1 :
if ( V_12 -> type == V_17 &&
( ( V_12 -> V_48 >> ( 2 * V_16 ) ) & 1 ) ) {
V_80 = - V_92 ;
goto V_88;
}
V_12 -> V_48 |= 2 << ( 2 * V_16 ) ;
break;
case 2 :
V_12 -> V_48 &= ~ ( 2 << ( 2 * V_16 ) ) ;
break;
default:
V_80 = - V_92 ;
goto V_88;
}
}
F_15 ( V_12 , V_49 , V_12 -> V_48 ) ;
V_88:
F_35 ( & V_12 -> V_25 ) ;
return V_80 ;
}
static T_3 F_71 ( struct V_18 * V_19 ,
struct V_74 * V_75 ,
char * V_76 )
{
int V_91 ;
struct V_11 * V_12 = F_19 ( V_19 ) ;
int V_67 = F_37 ( V_75 ) -> V_77 ;
int V_24 = F_37 ( V_75 ) -> V_16 ;
F_21 ( & V_12 -> V_25 ) ;
if ( V_12 -> V_48 & ( 1 << ( 2 * V_67 ) ) ) {
V_91 = V_12 -> V_52 [ V_67 ] [ V_24 ] ;
} else {
V_91 = 32 * 255 / ( 32 + V_12 -> V_52 [ V_67 ] [ V_24 ] ) ;
}
F_35 ( & V_12 -> V_25 ) ;
return sprintf ( V_76 , L_2 , V_91 ) ;
}
static T_3 F_72 ( struct V_18 * V_19 ,
struct V_74 * V_75 ,
const char * V_76 , T_4 V_80 )
{
struct V_11 * V_12 = F_20 ( V_19 ) ;
int V_81 , V_67 = F_37 ( V_75 ) -> V_77 ;
int V_24 = F_37 ( V_75 ) -> V_16 ;
long V_3 ;
V_81 = F_40 ( V_76 , 10 , & V_3 ) ;
if ( V_81 )
return V_81 ;
V_3 = F_41 ( V_3 , 0 , 255 ) ;
F_21 ( & V_12 -> V_25 ) ;
V_12 -> V_48 = F_13 ( V_12 , V_49 ) ;
if ( V_12 -> V_48 & ( 1 << ( 2 * V_67 ) ) ) {
} else {
if ( V_3 < 29 )
V_3 = 255 ;
else
V_3 = ( 255 - V_3 ) * 32 / V_3 ;
}
F_15 ( V_12 , F_28 ( V_67 , V_24 ) , V_3 ) ;
V_12 -> V_52 [ V_67 ] [ V_24 ] = V_3 ;
F_35 ( & V_12 -> V_25 ) ;
return V_80 ;
}
static T_3 F_73 ( struct V_18 * V_19 ,
struct V_74 * V_75 ,
char * V_76 )
{
int V_91 = 0 ;
struct V_11 * V_12 = F_19 ( V_19 ) ;
int V_16 = F_37 ( V_75 ) -> V_77 ;
int V_24 = F_37 ( V_75 ) -> V_16 ;
F_21 ( & V_12 -> V_25 ) ;
if ( V_16 & 1 )
V_91 = V_12 -> V_50 [ V_16 / 2 ] >> 4 ;
else
V_91 = V_12 -> V_50 [ V_16 / 2 ] & 0x0f ;
V_91 = 1000 * ( V_12 -> V_53 [ V_16 ] [ V_24 ] - V_91 ) ;
F_35 ( & V_12 -> V_25 ) ;
return sprintf ( V_76 , L_2 , V_91 ) ;
}
static T_3 F_74 ( struct V_18 * V_19 ,
struct V_74 * V_75 ,
const char * V_76 , T_4 V_80 )
{
struct V_11 * V_12 = F_20 ( V_19 ) ;
int V_81 , V_16 = F_37 ( V_75 ) -> V_77 ;
int V_24 = F_37 ( V_75 ) -> V_16 ;
T_2 V_2 ;
long V_3 ;
V_81 = F_40 ( V_76 , 10 , & V_3 ) ;
if ( V_81 )
return V_81 ;
V_3 /= 1000 ;
F_21 ( & V_12 -> V_25 ) ;
V_12 -> V_53 [ V_16 ] [ V_24 ] =
F_13 ( V_12 , F_29 ( V_16 , V_24 ) ) ;
V_3 = F_41 ( V_3 , V_12 -> V_53 [ V_16 ] [ V_24 ] - 15 ,
V_12 -> V_53 [ V_16 ] [ V_24 ] ) ;
V_3 = V_12 -> V_53 [ V_16 ] [ V_24 ] - V_3 ;
V_2 = F_13 ( V_12 , F_26 ( V_16 / 2 ) ) ;
if ( V_16 & 1 )
V_2 = ( V_2 & 0x0f ) | ( V_3 << 4 ) ;
else
V_2 = ( V_2 & 0xf0 ) | V_3 ;
F_15 ( V_12 , F_26 ( V_16 / 2 ) , V_2 ) ;
V_12 -> V_50 [ V_16 / 2 ] = V_2 ;
F_35 ( & V_12 -> V_25 ) ;
return V_80 ;
}
static T_3 F_75 ( struct V_18 * V_19 ,
struct V_74 * V_75 , char * V_76 )
{
int V_91 ;
struct V_11 * V_12 = F_19 ( V_19 ) ;
int V_16 = F_37 ( V_75 ) -> V_77 ;
V_91 = ( V_12 -> V_51 [ V_16 ] >> 4 ) & 1 ;
return sprintf ( V_76 , L_2 , V_91 ) ;
}
static T_3 F_76 ( struct V_18 * V_19 ,
struct V_74 * V_75 ,
const char * V_76 , T_4 V_80 )
{
struct V_11 * V_12 = F_20 ( V_19 ) ;
int V_81 , V_16 = F_37 ( V_75 ) -> V_77 ;
unsigned long V_3 ;
V_81 = F_44 ( V_76 , 10 , & V_3 ) ;
if ( V_81 )
return V_81 ;
F_21 ( & V_12 -> V_25 ) ;
V_12 -> V_51 [ V_16 ] =
F_13 ( V_12 , F_27 ( V_16 ) ) ;
if ( V_3 )
V_3 = V_12 -> V_51 [ V_16 ] | ( 1 << 4 ) ;
else
V_3 = V_12 -> V_51 [ V_16 ] & ( ~ ( 1 << 4 ) ) ;
F_15 ( V_12 , F_27 ( V_16 ) , V_3 ) ;
V_12 -> V_51 [ V_16 ] = V_3 ;
F_35 ( & V_12 -> V_25 ) ;
return V_80 ;
}
static T_3 F_77 ( struct V_18 * V_19 ,
struct V_74 * V_75 ,
char * V_76 )
{
int V_91 ;
struct V_11 * V_12 = F_19 ( V_19 ) ;
int V_16 = F_37 ( V_75 ) -> V_77 ;
V_91 = 1 << ( ( V_12 -> V_51 [ V_16 ] & 3 ) -
V_12 -> V_35 ) ;
return sprintf ( V_76 , L_2 , V_91 ) ;
}
static T_3 F_78 ( struct V_18 * V_19 ,
struct V_74 * V_75 ,
const char * V_76 , T_4 V_80 )
{
struct V_11 * V_12 = F_20 ( V_19 ) ;
int V_81 , V_16 = F_37 ( V_75 ) -> V_77 ;
long V_3 ;
V_81 = F_40 ( V_76 , 10 , & V_3 ) ;
if ( V_81 )
return V_81 ;
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
return - V_92 ;
}
V_3 += V_12 -> V_35 ;
F_21 ( & V_12 -> V_25 ) ;
V_12 -> V_51 [ V_16 ] =
F_13 ( V_12 , F_27 ( V_16 ) ) ;
V_3 = ( V_12 -> V_51 [ V_16 ] & 0xfc ) | V_3 ;
F_15 ( V_12 , F_27 ( V_16 ) , V_3 ) ;
V_12 -> V_51 [ V_16 ] = V_3 ;
F_35 ( & V_12 -> V_25 ) ;
return V_80 ;
}
static T_3 F_79 ( struct V_18 * V_19 ,
struct V_74 * V_75 ,
char * V_76 )
{
int V_91 ;
struct V_11 * V_12 = F_19 ( V_19 ) ;
int V_67 = F_37 ( V_75 ) -> V_77 ;
int V_24 = F_37 ( V_75 ) -> V_16 ;
V_91 = V_12 -> V_53 [ V_67 ] [ V_24 ] ;
return sprintf ( V_76 , L_2 , 1000 * V_91 ) ;
}
static T_3 F_80 ( struct V_18 * V_19 ,
struct V_74 * V_75 ,
const char * V_76 , T_4 V_80 )
{
struct V_11 * V_12 = F_20 ( V_19 ) ;
int V_81 , V_67 = F_37 ( V_75 ) -> V_77 ;
int V_24 = F_37 ( V_75 ) -> V_16 ;
long V_3 ;
V_81 = F_40 ( V_76 , 10 , & V_3 ) ;
if ( V_81 )
return V_81 ;
V_3 /= 1000 ;
if ( V_12 -> V_93 )
V_3 = F_41 ( V_3 , - 128 , 127 ) ;
else
V_3 = F_41 ( V_3 , 0 , 127 ) ;
F_21 ( & V_12 -> V_25 ) ;
F_15 ( V_12 , F_29 ( V_67 , V_24 ) , V_3 ) ;
V_12 -> V_53 [ V_67 ] [ V_24 ] = V_3 ;
F_35 ( & V_12 -> V_25 ) ;
return V_80 ;
}
static T_3 F_81 ( struct V_18 * V_19 , struct V_74 * V_75 ,
char * V_76 )
{
struct V_11 * V_12 = F_20 ( V_19 ) ;
return sprintf ( V_76 , L_5 , V_94 [ V_12 -> type ] ) ;
}
static int F_82 ( struct V_95 * V_96 ,
struct V_97 * V_98 , int V_80 )
{
int V_81 , V_99 ;
for ( V_99 = 0 ; V_99 < V_80 ; V_99 ++ ) {
V_81 = F_83 ( & V_96 -> V_19 , & V_98 [ V_99 ] . V_100 ) ;
if ( V_81 )
return V_81 ;
}
return 0 ;
}
static void F_84 ( struct V_95 * V_96 ,
struct V_97 * V_98 , int V_80 )
{
int V_99 ;
for ( V_99 = 0 ; V_99 < V_80 ; V_99 ++ )
F_85 ( & V_96 -> V_19 , & V_98 [ V_99 ] . V_100 ) ;
}
static int F_86 (
struct V_95 * V_96 , int V_101 )
{
struct V_11 * V_12 = F_87 ( V_96 ) ;
int V_81 ;
V_81 = 0 ;
switch ( V_12 -> type ) {
case V_17 :
if ( ( ( V_12 -> V_48 >> ( V_101 * 2 ) ) & 3 ) == 3 )
V_81 = 1 ;
break;
case V_56 :
if ( ( ( V_12 -> V_48 >> ( V_101 * 2 ) ) & 1 ) != 1 )
V_81 = 1 ;
break;
case V_38 :
if ( V_101 == 2 )
V_81 = V_12 -> V_48 & 0x20 ;
break;
default:
break;
}
if ( V_81 ) {
F_88 ( & V_96 -> V_19 ,
L_6
L_7 ,
( V_12 -> V_48 >> ( V_101 * 2 ) ) & 3 , V_101 + 1 ) ;
return 0 ;
}
V_81 = F_82 ( V_96 , & V_102 [ V_101 ] [ 0 ] ,
F_89 ( V_102 [ 0 ] ) ) ;
if ( V_81 )
return V_81 ;
if ( V_42 [ V_12 -> type ] ) {
V_81 = F_82 ( V_96 ,
& V_103 [ V_101 ] ,
1 ) ;
if ( V_81 )
return V_81 ;
}
F_90 ( & V_96 -> V_19 , L_8 , V_101 + 1 ,
( V_12 -> V_48 & ( 1 << ( 2 * V_101 ) ) ) ? L_9 : L_10 ) ;
switch ( V_12 -> type ) {
case V_54 :
case V_68 :
case V_55 :
case V_104 :
case V_105 :
case V_106 :
case V_107 :
V_12 -> V_51 [ V_101 ] =
F_13 ( V_12 , F_27 ( V_101 ) ) ;
if ( ( V_12 -> V_51 [ V_101 ] & 0x80 ) ||
( V_12 -> V_51 [ V_101 ] & 3 ) == 0 ) {
F_91 ( & V_96 -> V_19 ,
L_11
L_12
L_13 , V_101 + 1 ) ;
return 0 ;
}
break;
default:
break;
}
switch ( V_12 -> type ) {
case V_56 :
V_81 = F_82 ( V_96 ,
& V_108 [ V_101 ] [ 0 ] ,
F_89 ( V_108 [ 0 ] ) ) ;
break;
case V_54 :
case V_55 :
V_81 = F_82 ( V_96 ,
& V_109 [ V_101 ] [ 0 ] ,
F_89 ( V_109 [ 0 ] ) ) ;
break;
case V_38 :
V_81 = F_82 ( V_96 ,
& V_110 [ V_101 ] [ 0 ] ,
F_89 ( V_110 [ 0 ] ) ) ;
break;
default:
V_81 = F_82 ( V_96 ,
& V_111 [ V_101 ] [ 0 ] ,
F_89 ( V_111 [ 0 ] ) ) ;
}
return V_81 ;
}
static int F_92 ( struct V_95 * V_96 )
{
struct V_11 * V_12 ;
struct V_112 * V_113 = V_96 -> V_19 . V_114 ;
int V_20 = V_21 [ V_113 -> type ] ;
int V_22 = V_23 [ V_113 -> type ] ;
int V_81 , V_99 ;
T_2 V_115 , V_2 ;
V_12 = F_93 ( & V_96 -> V_19 , sizeof( struct V_11 ) ,
V_116 ) ;
if ( ! V_12 )
return - V_117 ;
V_12 -> V_13 = F_94 ( V_96 , V_118 , 0 ) -> V_119 ;
V_12 -> type = V_113 -> type ;
V_12 -> V_35 =
( V_12 -> type == V_17 || V_12 -> type == V_38 ) ? 0 : 1 ;
F_95 ( & V_12 -> V_25 ) ;
F_96 ( V_96 , V_12 ) ;
V_115 = F_13 ( V_12 , V_120 ) ;
if ( V_115 & 0x04 ) {
F_91 ( & V_96 -> V_19 , L_14 ) ;
return - V_121 ;
}
if ( ! ( V_115 & 0x03 ) ) {
F_91 ( & V_96 -> V_19 , L_15 ) ;
return - V_121 ;
}
V_81 = F_83 ( & V_96 -> V_19 , & V_122 ) ;
if ( V_81 )
goto V_123;
if ( V_115 & 0x01 ) {
switch ( V_12 -> type ) {
case V_17 :
V_12 -> V_83 =
F_13 ( V_12 , V_124 ) ;
if ( V_12 -> V_83 & 0x10 )
V_81 = F_82 ( V_96 ,
V_125 ,
F_89 ( V_125 ) ) ;
else
V_81 = F_82 ( V_96 ,
V_126 ,
F_89 ( V_126 ) ) ;
break;
case V_38 :
V_81 = F_82 ( V_96 ,
V_125 ,
F_89 ( V_125 ) ) ;
break;
default:
V_81 = F_82 ( V_96 ,
& V_127 [ 0 ] [ 0 ] ,
F_89 ( V_127 [ 0 ] ) * V_22 ) ;
}
if ( V_81 )
goto V_123;
if ( V_45 [ V_12 -> type ] ) {
V_81 = F_82 ( V_96 ,
& V_128 [ 0 ] [ 0 ] ,
F_89 ( V_128 [ 0 ] )
* V_22 ) ;
if ( V_81 )
goto V_123;
}
for ( V_99 = 0 ; V_99 < V_71 ; V_99 ++ ) {
if ( V_72 [ V_12 -> type ] [ V_99 ] ) {
V_81 = F_83 ( & V_96 -> V_19 ,
& V_129 [ V_99 ] . V_100 ) ;
if ( V_81 )
goto V_123;
}
}
if ( V_30 [ V_12 -> type ] ) {
V_81 = F_82 ( V_96 ,
V_130 ,
F_89 ( V_130 ) ) ;
if ( V_81 )
goto V_123;
}
}
if ( V_115 & 0x02 ) {
switch ( V_12 -> type ) {
case V_54 :
case V_68 :
case V_55 :
case V_104 :
V_12 -> V_93 = 1 ;
case V_105 :
case V_106 :
case V_107 :
V_2 = F_13 ( V_12 , V_131 ) ;
if ( V_2 & V_132 )
V_12 -> V_93 = 1 ;
V_2 &= ~ V_133 ;
F_15 ( V_12 , V_131 , V_2 ) ;
break;
default:
break;
}
V_12 -> V_48 =
F_13 ( V_12 , V_49 ) ;
for ( V_99 = 0 ; V_99 < V_20 ; V_99 ++ ) {
V_81 = F_86 ( V_96 , V_99 ) ;
if ( V_81 )
goto V_123;
}
switch ( V_12 -> type ) {
case V_68 :
V_81 = F_82 ( V_96 ,
V_134 ,
F_89 ( V_134 ) ) ;
break;
case V_38 :
V_81 = F_82 ( V_96 ,
V_135 ,
F_89 ( V_135 ) ) ;
break;
default:
break;
}
if ( V_81 )
goto V_123;
}
V_12 -> V_136 = F_97 ( & V_96 -> V_19 ) ;
if ( F_98 ( V_12 -> V_136 ) ) {
V_81 = F_99 ( V_12 -> V_136 ) ;
V_12 -> V_136 = NULL ;
goto V_123;
}
return 0 ;
V_123:
F_100 ( V_96 ) ;
return V_81 ;
return V_81 ;
}
static int F_100 ( struct V_95 * V_96 )
{
struct V_11 * V_12 = F_87 ( V_96 ) ;
int V_20 = V_21 [ V_12 -> type ] ;
int V_22 = V_23 [ V_12 -> type ] ;
int V_99 ;
T_2 V_115 = F_13 ( V_12 , V_120 ) ;
if ( V_12 -> V_136 )
F_101 ( V_12 -> V_136 ) ;
F_85 ( & V_96 -> V_19 , & V_122 ) ;
if ( V_115 & 0x01 ) {
switch ( V_12 -> type ) {
case V_17 :
if ( V_12 -> V_83 & 0x10 )
F_84 ( V_96 ,
V_125 ,
F_89 ( V_125 ) ) ;
else
F_84 ( V_96 ,
V_126 ,
F_89 ( V_126 ) ) ;
break;
case V_38 :
F_84 ( V_96 ,
V_125 ,
F_89 ( V_125 ) ) ;
break;
default:
F_84 ( V_96 ,
& V_127 [ 0 ] [ 0 ] ,
F_89 ( V_127 [ 0 ] ) * V_22 ) ;
}
if ( V_45 [ V_12 -> type ] ) {
F_84 ( V_96 ,
& V_128 [ 0 ] [ 0 ] ,
F_89 ( V_128 [ 0 ] ) * V_22 ) ;
}
for ( V_99 = 0 ; V_99 < V_71 ; V_99 ++ ) {
if ( V_72 [ V_12 -> type ] [ V_99 ] ) {
F_85 ( & V_96 -> V_19 ,
& V_129 [ V_99 ] . V_100 ) ;
}
}
if ( V_30 [ V_12 -> type ] ) {
F_84 ( V_96 ,
V_130 ,
F_89 ( V_130 ) ) ;
}
}
if ( V_115 & 0x02 ) {
F_84 ( V_96 , & V_102 [ 0 ] [ 0 ] ,
F_89 ( V_102 [ 0 ] ) * V_20 ) ;
if ( V_42 [ V_12 -> type ] ) {
F_84 ( V_96 ,
V_103 , V_20 ) ;
}
switch ( V_12 -> type ) {
case V_68 :
F_84 ( V_96 ,
& V_111 [ 0 ] [ 0 ] ,
F_89 ( V_111 [ 0 ] ) * V_20 ) ;
F_84 ( V_96 ,
V_134 ,
F_89 ( V_134 ) ) ;
break;
case V_56 :
F_84 ( V_96 ,
& V_108 [ 0 ] [ 0 ] ,
F_89 ( V_108 [ 0 ] ) *
V_20 ) ;
break;
case V_54 :
case V_55 :
F_84 ( V_96 ,
& V_109 [ 0 ] [ 0 ] ,
F_89 ( V_109 [ 0 ] ) * V_20 ) ;
break;
case V_38 :
F_84 ( V_96 ,
V_135 ,
F_89 ( V_135 ) ) ;
F_84 ( V_96 ,
& V_110 [ 0 ] [ 0 ] ,
F_89 ( V_110 [ 0 ] ) * V_20 ) ;
break;
default:
F_84 ( V_96 ,
& V_111 [ 0 ] [ 0 ] ,
F_89 ( V_111 [ 0 ] ) * V_20 ) ;
}
}
return 0 ;
}
static int T_5 F_102 ( int V_137 , struct V_112 * V_113 )
{
T_1 V_138 ;
unsigned short V_139 ;
int V_81 = F_5 ( V_137 ) ;
if ( V_81 )
return V_81 ;
V_138 = F_4 ( V_137 , V_140 ) ;
if ( V_138 != V_141 ) {
F_103 ( L_16 ) ;
V_81 = - V_121 ;
goto exit;
}
V_138 = V_142 ? V_142 : F_4 ( V_137 , V_143 ) ;
switch ( V_138 ) {
case V_144 :
V_113 -> type = V_54 ;
break;
case V_145 :
V_113 -> type = V_68 ;
break;
case V_146 :
V_113 -> type = V_17 ;
break;
case V_147 :
V_113 -> type = V_56 ;
break;
case V_148 :
V_113 -> type = V_55 ;
break;
case V_149 :
V_113 -> type = V_104 ;
break;
case V_150 :
V_113 -> type = V_151 ;
break;
case V_152 :
V_113 -> type = V_105 ;
break;
case V_153 :
V_113 -> type = V_106 ;
break;
case V_154 :
V_113 -> type = V_107 ;
break;
case V_155 :
V_113 -> type = V_38 ;
break;
case V_156 :
V_113 -> type = V_157 ;
break;
default:
F_104 ( L_17 ,
( unsigned int ) V_138 ) ;
V_81 = - V_121 ;
goto exit;
}
if ( V_113 -> type == V_17 )
F_8 ( V_137 , V_158 ) ;
else
F_8 ( V_137 , V_159 ) ;
if ( ! ( F_1 ( V_137 , V_160 ) & 0x01 ) ) {
F_105 ( L_18 ) ;
V_81 = - V_121 ;
goto exit;
}
V_139 = F_4 ( V_137 , V_161 ) ;
if ( V_139 == 0 ) {
F_105 ( L_19 ) ;
V_81 = - V_121 ;
goto exit;
}
V_139 &= ~ ( V_162 - 1 ) ;
V_81 = V_139 ;
F_104 ( L_20 ,
V_94 [ V_113 -> type ] , ( unsigned int ) V_139 ,
( int ) F_1 ( V_137 , V_163 ) ) ;
exit:
F_9 ( V_137 ) ;
return V_81 ;
}
static int T_5 F_106 ( int V_139 ,
const struct V_112 * V_113 )
{
struct V_164 V_165 = {
. V_119 = V_139 ,
. V_166 = V_139 + V_162 - 1 ,
. V_167 = V_118 ,
} ;
int V_81 ;
V_168 = F_107 ( V_4 , V_139 ) ;
if ( ! V_168 )
return - V_117 ;
V_165 . V_169 = V_168 -> V_169 ;
V_81 = F_108 ( & V_165 ) ;
if ( V_81 )
goto V_170;
V_81 = F_109 ( V_168 , & V_165 , 1 ) ;
if ( V_81 ) {
F_7 ( L_21 ) ;
goto V_170;
}
V_81 = F_110 ( V_168 , V_113 ,
sizeof( struct V_112 ) ) ;
if ( V_81 ) {
F_7 ( L_22 ) ;
goto V_170;
}
V_81 = F_111 ( V_168 ) ;
if ( V_81 ) {
F_7 ( L_23 ) ;
goto V_170;
}
return 0 ;
V_170:
F_112 ( V_168 ) ;
return V_81 ;
}
static int T_5 F_113 ( void )
{
int V_81 ;
int V_139 ;
struct V_112 V_113 ;
memset ( & V_113 , 0 , sizeof( V_113 ) ) ;
V_139 = F_102 ( 0x2e , & V_113 ) ;
if ( V_139 < 0 )
V_139 = F_102 ( 0x4e , & V_113 ) ;
if ( V_139 < 0 )
return V_139 ;
V_81 = F_114 ( & V_171 ) ;
if ( V_81 )
return V_81 ;
V_81 = F_106 ( V_139 , & V_113 ) ;
if ( V_81 )
goto V_172;
return 0 ;
V_172:
F_115 ( & V_171 ) ;
return V_81 ;
}
static void T_6 F_116 ( void )
{
F_117 ( V_168 ) ;
F_115 ( & V_171 ) ;
}
