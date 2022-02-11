static inline T_1
F_1 ( long V_1 , int div )
{
if ( V_1 == 0 )
return 255 ;
V_1 = F_2 ( V_1 , 1 , 1000000 ) ;
return F_2 ( ( 1350000 + V_1 * div / 2 ) / ( V_1 * div ) , 1 , 254 ) ;
}
static inline T_1
F_3 ( long V_2 )
{
int V_3 ;
V_2 = F_2 ( V_2 , 1 , 128 ) >> 1 ;
for ( V_3 = 0 ; V_3 < 7 ; V_3 ++ ) {
if ( V_2 == 0 )
break;
V_2 >>= 1 ;
}
return ( T_1 ) V_3 ;
}
static T_1
F_4 ( struct V_4 * V_5 , T_1 V_6 )
{
return F_5 ( V_5 , V_6 ) ;
}
static int
F_6 ( struct V_4 * V_5 , T_1 V_6 , T_1 V_7 )
{
return F_7 ( V_5 , V_6 , V_7 ) ;
}
static struct V_8 * F_8 ( struct V_9 * V_10 )
{
struct V_8 * V_11 = F_9 ( V_10 ) ;
struct V_4 * V_5 = V_11 -> V_5 ;
int V_3 , V_12 ;
T_1 V_13 , V_14 ;
F_10 ( & V_11 -> V_15 ) ;
if ( F_11 ( V_16 , V_11 -> V_17 + V_18 + V_18 / 2 )
|| ! V_11 -> V_19 ) {
F_12 ( & V_5 -> V_10 , L_1 ) ;
for ( V_3 = 0 ; V_3 < 3 ; V_3 ++ ) {
V_11 -> V_20 [ V_3 ] = F_4 ( V_5 ,
F_13 ( V_3 ) ) ;
V_11 -> V_21 [ V_3 ] = F_4 ( V_5 ,
F_14 ( V_3 ) ) ;
V_11 -> V_22 [ V_3 ] = F_4 ( V_5 ,
F_15 ( V_3 ) ) ;
}
for ( V_3 = 0 ; V_3 < 2 ; V_3 ++ ) {
V_11 -> V_23 [ V_3 ] = F_4 ( V_5 ,
F_16 ( V_3 ) ) ;
V_11 -> V_24 [ V_3 ] = F_4 ( V_5 ,
F_17 ( V_3 ) ) ;
}
V_13 = F_4 ( V_5 , V_25 ) ;
V_11 -> V_26 [ 0 ] = V_13 & 0x07 ;
V_11 -> V_26 [ 1 ] = ( V_13 >> 4 ) & 0x07 ;
V_14 = F_4 ( V_5 , V_27 ) ;
for ( V_3 = 0 ; V_3 < 2 ; V_3 ++ ) {
V_11 -> V_28 [ V_3 ] =
( ( V_14 >> V_29 [ V_3 ] ) & 1 )
? 0 : 1 ;
V_11 -> V_30 [ V_3 ] =
( ( V_14 >> V_31 [ V_3 ] ) & 3 ) + 1 ;
V_11 -> V_32 [ V_3 ] =
( F_4 ( V_5 , V_33 [ V_3 ] )
& 0x0f ) * 0x11 ;
}
for ( V_3 = 0 ; V_3 < 2 ; V_3 ++ ) {
for ( V_12 = 0 ; V_12 < 3 ; V_12 ++ ) {
V_11 -> V_34 [ V_3 ] [ V_12 ] = F_4 ( V_5 ,
V_35 [ V_3 ] [ V_12 ] ) ;
}
}
V_13 = F_4 ( V_5 , V_36 ) ;
V_11 -> V_37 [ 0 ] = V_13 & 0x0f ;
V_11 -> V_37 [ 1 ] = ( V_13 >> 4 ) & 0x0f ;
V_11 -> V_17 = V_16 ;
V_11 -> V_19 = 1 ;
}
F_18 ( & V_11 -> V_15 ) ;
return V_11 ;
}
static T_2
F_19 ( struct V_9 * V_10 , struct V_38 * V_39 ,
const char * V_40 , T_3 V_41 )
{
int V_42 = F_20 ( V_39 ) -> V_43 ;
struct V_8 * V_11 = F_9 ( V_10 ) ;
struct V_4 * V_5 = V_11 -> V_5 ;
unsigned long V_2 ;
int V_44 ;
V_44 = F_21 ( V_40 , 10 , & V_2 ) ;
if ( V_44 )
return V_44 ;
F_10 ( & V_11 -> V_15 ) ;
V_11 -> V_24 [ V_42 ] = F_1 ( V_2 , F_22 ( V_11 -> V_26 [ V_42 ] ) ) ;
F_6 ( V_5 , F_17 ( V_42 ) ,
V_11 -> V_24 [ V_42 ] ) ;
F_18 ( & V_11 -> V_15 ) ;
return V_41 ;
}
static T_2
F_23 ( struct V_9 * V_10 , struct V_38 * V_39 ,
char * V_40 )
{
int V_42 = F_20 ( V_39 ) -> V_43 ;
struct V_8 * V_11 = F_8 ( V_10 ) ;
return sprintf ( V_40 , L_2 , F_22 ( V_11 -> V_26 [ V_42 ] ) ) ;
}
static T_2
F_24 ( struct V_9 * V_10 , struct V_38 * V_39 ,
const char * V_40 , T_3 V_41 )
{
int V_42 = F_20 ( V_39 ) -> V_43 ;
struct V_8 * V_11 = F_9 ( V_10 ) ;
struct V_4 * V_5 = V_11 -> V_5 ;
unsigned long V_45 ;
T_1 V_46 ;
T_1 V_47 ;
T_1 V_48 = 0 ;
T_1 V_49 = 0 ;
unsigned long V_2 ;
int V_44 ;
V_44 = F_21 ( V_40 , 10 , & V_2 ) ;
if ( V_44 )
return V_44 ;
F_10 ( & V_11 -> V_15 ) ;
V_45 = F_25 ( V_11 -> V_24 [ V_42 ] , F_22 ( V_11 -> V_26 [ V_42 ] ) ) ;
V_11 -> V_26 [ V_42 ] = F_3 ( V_2 ) ;
switch ( V_42 ) {
case 0 :
V_48 = 0xf8 ;
V_49 = 0 ;
break;
case 1 :
V_48 = 0x8f ;
V_49 = 4 ;
break;
}
V_47 = F_4 ( V_5 , V_25 )
& V_48 ;
V_46 = ( V_11 -> V_26 [ V_42 ] << V_49 ) & ~ V_48 ;
F_6 ( V_5 , V_25 ,
V_47 | V_46 ) ;
V_11 -> V_24 [ V_42 ] = F_1 ( V_45 , F_22 ( V_11 -> V_26 [ V_42 ] ) ) ;
F_6 ( V_5 , F_17 ( V_42 ) ,
V_11 -> V_24 [ V_42 ] ) ;
F_18 ( & V_11 -> V_15 ) ;
return V_41 ;
}
static T_2
F_26 ( struct V_9 * V_10 , struct V_38 * V_39 , char * V_40 )
{
struct V_50 * V_51 =
F_27 ( V_39 ) ;
int V_42 = V_51 -> V_42 ;
int V_43 = V_51 -> V_43 ;
struct V_8 * V_11 = F_8 ( V_10 ) ;
return sprintf ( V_40 , L_3 , F_28 ( V_11 -> V_34 [ V_42 ] [ V_43 ] ) ) ;
}
static T_2
F_29 ( struct V_9 * V_10 , struct V_38 * V_39 ,
const char * V_40 , T_3 V_41 )
{
struct V_50 * V_51 =
F_27 ( V_39 ) ;
int V_42 = V_51 -> V_42 ;
int V_43 = V_51 -> V_43 ;
struct V_8 * V_11 = F_9 ( V_10 ) ;
struct V_4 * V_5 = V_11 -> V_5 ;
long V_2 ;
int V_44 ;
V_44 = F_30 ( V_40 , 10 , & V_2 ) ;
if ( V_44 )
return V_44 ;
F_10 ( & V_11 -> V_15 ) ;
V_11 -> V_34 [ V_42 ] [ V_43 ] = F_31 ( V_2 ) ;
F_6 ( V_5 , V_35 [ V_42 ] [ V_43 ] ,
V_11 -> V_34 [ V_42 ] [ V_43 ] ) ;
F_18 ( & V_11 -> V_15 ) ;
return V_41 ;
}
static T_2
F_32 ( struct V_9 * V_10 , struct V_38 * V_39 ,
const char * V_40 , T_3 V_41 )
{
int V_42 = F_20 ( V_39 ) -> V_43 ;
struct V_8 * V_11 = F_9 ( V_10 ) ;
struct V_4 * V_5 = V_11 -> V_5 ;
T_1 V_6 ;
unsigned long V_2 ;
int V_44 ;
V_44 = F_21 ( V_40 , 10 , & V_2 ) ;
if ( V_44 )
return V_44 ;
if ( V_2 > 1 )
return - V_52 ;
F_10 ( & V_11 -> V_15 ) ;
V_11 -> V_28 [ V_42 ] = V_2 ;
V_6 = F_4 ( V_5 , V_27 ) ;
V_6 &= ~ ( 1 << V_29 [ V_42 ] ) ;
if ( ! V_2 )
V_6 |= 1 << V_29 [ V_42 ] ;
F_6 ( V_5 , V_27 , V_6 ) ;
F_18 ( & V_11 -> V_15 ) ;
return V_41 ;
}
static T_2
F_33 ( struct V_9 * V_10 , struct V_38 * V_39 ,
const char * V_40 , T_3 V_41 )
{
int V_42 = F_20 ( V_39 ) -> V_43 ;
struct V_8 * V_11 = F_9 ( V_10 ) ;
struct V_4 * V_5 = V_11 -> V_5 ;
unsigned long V_2 ;
int V_44 ;
V_44 = F_21 ( V_40 , 10 , & V_2 ) ;
if ( V_44 )
return V_44 ;
V_2 = F_2 ( V_2 , 0 , 255 ) ;
V_2 = F_34 ( V_2 , 0x11 ) ;
F_10 ( & V_11 -> V_15 ) ;
V_11 -> V_32 [ V_42 ] = V_2 * 0x11 ;
V_2 |= F_4 ( V_5 , V_33 [ V_42 ] ) & 0xf0 ;
F_6 ( V_5 , V_33 [ V_42 ] , V_2 ) ;
F_18 ( & V_11 -> V_15 ) ;
return V_41 ;
}
static T_2
F_35 ( struct V_9 * V_10 , struct V_38 * V_39 ,
const char * V_40 , T_3 V_41 )
{
int V_42 = F_20 ( V_39 ) -> V_43 ;
struct V_8 * V_11 = F_9 ( V_10 ) ;
struct V_4 * V_5 = V_11 -> V_5 ;
T_1 V_6 ;
unsigned long V_2 ;
int V_44 ;
V_44 = F_21 ( V_40 , 10 , & V_2 ) ;
if ( V_44 )
return V_44 ;
if ( ! V_2 || V_2 > 2 )
return - V_52 ;
F_10 ( & V_11 -> V_15 ) ;
V_6 = F_4 ( V_5 , V_27 ) ;
V_11 -> V_30 [ V_42 ] = V_2 ;
V_6 &= ~ ( 0x03 << V_31 [ V_42 ] ) ;
V_6 |= ( V_2 - 1 ) << V_31 [ V_42 ] ;
F_6 ( V_5 , V_27 , V_6 ) ;
F_18 ( & V_11 -> V_15 ) ;
return V_41 ;
}
static T_2
F_36 ( struct V_9 * V_10 , struct V_38 * V_39 , char * V_40 )
{
int V_42 = F_20 ( V_39 ) -> V_43 ;
struct V_8 * V_11 = F_8 ( V_10 ) ;
return sprintf ( V_40 , L_4 , ( long ) V_11 -> V_37 [ V_42 ] ) ;
}
static T_2
F_37 ( struct V_9 * V_10 , struct V_38 * V_39 ,
const char * V_40 , T_3 V_41 )
{
int V_42 = F_20 ( V_39 ) -> V_43 ;
struct V_8 * V_11 = F_9 ( V_10 ) ;
struct V_4 * V_5 = V_11 -> V_5 ;
T_1 V_53 , V_54 ;
unsigned long V_2 ;
int V_44 ;
V_44 = F_21 ( V_40 , 10 , & V_2 ) ;
if ( V_44 )
return V_44 ;
F_10 ( & V_11 -> V_15 ) ;
V_54 = F_4 ( V_5 ,
V_36 ) & ( ( V_42 == 1 ) ? 0x0f : 0xf0 ) ;
V_53 = F_2 ( V_2 , 0 , 15 ) ;
V_53 &= 0x0f ;
V_11 -> V_37 [ V_42 ] = V_53 ;
if ( V_42 == 1 )
V_53 <<= 4 ;
F_6 ( V_5 , V_36 ,
V_54 | V_53 ) ;
F_18 ( & V_11 -> V_15 ) ;
return V_41 ;
}
static int
F_38 ( struct V_4 * V_5 , struct V_55 * V_56 )
{
struct V_57 * V_58 = V_5 -> V_58 ;
T_4 V_59 ;
T_1 V_60 ;
if ( ! F_39 ( V_58 , V_61 ) )
return - V_62 ;
if ( ( F_4 ( V_5 , V_63 ) & 0x80 ) ) {
F_12 ( & V_58 -> V_10 , L_5 ,
V_5 -> V_64 ) ;
return - V_62 ;
}
V_59 = ( F_4 ( V_5 , V_65 ) << 8 ) +
F_4 ( V_5 , V_66 ) ;
V_60 = F_4 ( V_5 , V_67 ) ;
if ( V_59 != 0x5CA3 ||
V_60 != 0x80 ) {
F_12 ( & V_58 -> V_10 ,
L_6 ,
V_59 , V_60 ) ;
return - V_62 ;
}
F_40 ( V_56 -> type , L_7 , V_68 ) ;
return 0 ;
}
static void F_41 ( struct V_4 * V_5 )
{
T_1 V_69 ;
if ( V_70 )
F_6 ( V_5 , V_63 , 0x80 ) ;
V_69 = F_4 ( V_5 , V_63 ) ;
if ( ! ( V_69 & 0x01 ) )
F_6 ( V_5 , V_63 , V_69 | 0x01 ) ;
}
static int
F_42 ( struct V_4 * V_5 , const struct V_71 * V_72 )
{
struct V_9 * V_10 = & V_5 -> V_10 ;
struct V_8 * V_11 ;
struct V_9 * V_73 ;
int V_3 ;
T_1 V_13 ;
V_11 = F_43 ( V_10 , sizeof( struct V_8 ) , V_74 ) ;
if ( ! V_11 )
return - V_75 ;
V_11 -> V_5 = V_5 ;
F_44 ( & V_11 -> V_15 ) ;
F_41 ( V_5 ) ;
for ( V_3 = 0 ; V_3 < 2 ; V_3 ++ ) {
V_11 -> V_24 [ V_3 ] = F_4 ( V_5 ,
F_17 ( V_3 ) ) ;
}
V_13 = F_4 ( V_5 , V_25 ) ;
V_11 -> V_26 [ 0 ] = V_13 & 0x07 ;
V_11 -> V_26 [ 1 ] = ( V_13 >> 4 ) & 0x07 ;
V_73 = F_45 ( V_10 , V_5 -> V_76 ,
V_11 ,
V_77 ) ;
return F_46 ( V_73 ) ;
}
