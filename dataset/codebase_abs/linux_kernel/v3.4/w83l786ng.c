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
static T_2
F_8 ( struct V_8 * V_9 , struct V_10 * V_11 ,
const char * V_12 , T_3 V_13 )
{
int V_14 = F_9 ( V_11 ) -> V_15 ;
struct V_4 * V_5 = F_10 ( V_9 ) ;
struct V_16 * V_17 = F_11 ( V_5 ) ;
unsigned long V_2 ;
int V_18 ;
V_18 = F_12 ( V_12 , 10 , & V_2 ) ;
if ( V_18 )
return V_18 ;
F_13 ( & V_17 -> V_19 ) ;
V_17 -> V_20 [ V_14 ] = F_1 ( V_2 , F_14 ( V_17 -> V_21 [ V_14 ] ) ) ;
F_6 ( V_5 , F_15 ( V_14 ) ,
V_17 -> V_20 [ V_14 ] ) ;
F_16 ( & V_17 -> V_19 ) ;
return V_13 ;
}
static T_2
F_17 ( struct V_8 * V_9 , struct V_10 * V_11 ,
char * V_12 )
{
int V_14 = F_9 ( V_11 ) -> V_15 ;
struct V_16 * V_17 = F_18 ( V_9 ) ;
return sprintf ( V_12 , L_1 , F_14 ( V_17 -> V_21 [ V_14 ] ) ) ;
}
static T_2
F_19 ( struct V_8 * V_9 , struct V_10 * V_11 ,
const char * V_12 , T_3 V_13 )
{
int V_14 = F_9 ( V_11 ) -> V_15 ;
struct V_4 * V_5 = F_10 ( V_9 ) ;
struct V_16 * V_17 = F_11 ( V_5 ) ;
unsigned long V_22 ;
T_1 V_23 ;
T_1 V_24 ;
T_1 V_25 = 0 ;
T_1 V_26 = 0 ;
unsigned long V_2 ;
int V_18 ;
V_18 = F_12 ( V_12 , 10 , & V_2 ) ;
if ( V_18 )
return V_18 ;
F_13 ( & V_17 -> V_19 ) ;
V_22 = F_20 ( V_17 -> V_20 [ V_14 ] , F_14 ( V_17 -> V_21 [ V_14 ] ) ) ;
V_17 -> V_21 [ V_14 ] = F_3 ( V_2 ) ;
switch ( V_14 ) {
case 0 :
V_25 = 0xf8 ;
V_26 = 0 ;
break;
case 1 :
V_25 = 0x8f ;
V_26 = 4 ;
break;
}
V_24 = F_4 ( V_5 , V_27 )
& V_25 ;
V_23 = ( V_17 -> V_21 [ V_14 ] << V_26 ) & ~ V_25 ;
F_6 ( V_5 , V_27 ,
V_24 | V_23 ) ;
V_17 -> V_20 [ V_14 ] = F_1 ( V_22 , F_14 ( V_17 -> V_21 [ V_14 ] ) ) ;
F_6 ( V_5 , F_15 ( V_14 ) ,
V_17 -> V_20 [ V_14 ] ) ;
F_16 ( & V_17 -> V_19 ) ;
return V_13 ;
}
static T_2
F_21 ( struct V_8 * V_9 , struct V_10 * V_11 , char * V_12 )
{
struct V_28 * V_29 =
F_22 ( V_11 ) ;
int V_14 = V_29 -> V_14 ;
int V_15 = V_29 -> V_15 ;
struct V_16 * V_17 = F_18 ( V_9 ) ;
return sprintf ( V_12 , L_2 , F_23 ( V_17 -> V_30 [ V_14 ] [ V_15 ] ) ) ;
}
static T_2
F_24 ( struct V_8 * V_9 , struct V_10 * V_11 ,
const char * V_12 , T_3 V_13 )
{
struct V_28 * V_29 =
F_22 ( V_11 ) ;
int V_14 = V_29 -> V_14 ;
int V_15 = V_29 -> V_15 ;
struct V_4 * V_5 = F_10 ( V_9 ) ;
struct V_16 * V_17 = F_11 ( V_5 ) ;
long V_2 ;
int V_18 ;
V_18 = F_25 ( V_12 , 10 , & V_2 ) ;
if ( V_18 )
return V_18 ;
F_13 ( & V_17 -> V_19 ) ;
V_17 -> V_30 [ V_14 ] [ V_15 ] = F_26 ( V_2 ) ;
F_6 ( V_5 , V_31 [ V_14 ] [ V_15 ] ,
V_17 -> V_30 [ V_14 ] [ V_15 ] ) ;
F_16 ( & V_17 -> V_19 ) ;
return V_13 ;
}
static T_2
F_27 ( struct V_8 * V_9 , struct V_10 * V_11 ,
const char * V_12 , T_3 V_13 )
{
int V_14 = F_9 ( V_11 ) -> V_15 ;
struct V_4 * V_5 = F_10 ( V_9 ) ;
struct V_16 * V_17 = F_11 ( V_5 ) ;
T_1 V_6 ;
unsigned long V_2 ;
int V_18 ;
V_18 = F_12 ( V_12 , 10 , & V_2 ) ;
if ( V_18 )
return V_18 ;
if ( V_2 > 1 )
return - V_32 ;
F_13 ( & V_17 -> V_19 ) ;
V_17 -> V_33 [ V_14 ] = V_2 ;
V_6 = F_4 ( V_5 , V_34 ) ;
V_6 &= ~ ( 1 << V_35 [ V_14 ] ) ;
if ( ! V_2 )
V_6 |= 1 << V_35 [ V_14 ] ;
F_6 ( V_5 , V_34 , V_6 ) ;
F_16 ( & V_17 -> V_19 ) ;
return V_13 ;
}
static T_2
F_28 ( struct V_8 * V_9 , struct V_10 * V_11 ,
const char * V_12 , T_3 V_13 )
{
int V_14 = F_9 ( V_11 ) -> V_15 ;
struct V_4 * V_5 = F_10 ( V_9 ) ;
struct V_16 * V_17 = F_11 ( V_5 ) ;
unsigned long V_2 ;
int V_18 ;
V_18 = F_12 ( V_12 , 10 , & V_2 ) ;
if ( V_18 )
return V_18 ;
V_2 = F_2 ( V_2 , 0 , 255 ) ;
F_13 ( & V_17 -> V_19 ) ;
V_17 -> V_36 [ V_14 ] = V_2 ;
F_6 ( V_5 , V_37 [ V_14 ] , V_2 ) ;
F_16 ( & V_17 -> V_19 ) ;
return V_13 ;
}
static T_2
F_29 ( struct V_8 * V_9 , struct V_10 * V_11 ,
const char * V_12 , T_3 V_13 )
{
int V_14 = F_9 ( V_11 ) -> V_15 ;
struct V_4 * V_5 = F_10 ( V_9 ) ;
struct V_16 * V_17 = F_11 ( V_5 ) ;
T_1 V_6 ;
unsigned long V_2 ;
int V_18 ;
V_18 = F_12 ( V_12 , 10 , & V_2 ) ;
if ( V_18 )
return V_18 ;
if ( ! V_2 || V_2 > 2 )
return - V_32 ;
F_13 ( & V_17 -> V_19 ) ;
V_6 = F_4 ( V_5 , V_34 ) ;
V_17 -> V_38 [ V_14 ] = V_2 ;
V_6 &= ~ ( 0x02 << V_39 [ V_14 ] ) ;
V_6 |= ( V_2 - 1 ) << V_39 [ V_14 ] ;
F_6 ( V_5 , V_34 , V_6 ) ;
F_16 ( & V_17 -> V_19 ) ;
return V_13 ;
}
static T_2
F_30 ( struct V_8 * V_9 , struct V_10 * V_11 , char * V_12 )
{
int V_14 = F_9 ( V_11 ) -> V_15 ;
struct V_16 * V_17 = F_18 ( V_9 ) ;
return sprintf ( V_12 , L_3 , ( long ) V_17 -> V_40 [ V_14 ] ) ;
}
static T_2
F_31 ( struct V_8 * V_9 , struct V_10 * V_11 ,
const char * V_12 , T_3 V_13 )
{
int V_14 = F_9 ( V_11 ) -> V_15 ;
struct V_4 * V_5 = F_10 ( V_9 ) ;
struct V_16 * V_17 = F_11 ( V_5 ) ;
T_1 V_41 , V_42 ;
unsigned long V_2 ;
int V_18 ;
V_18 = F_12 ( V_12 , 10 , & V_2 ) ;
if ( V_18 )
return V_18 ;
F_13 ( & V_17 -> V_19 ) ;
V_42 = F_4 ( V_5 ,
V_43 ) & ( ( V_14 == 1 ) ? 0x0f : 0xf0 ) ;
V_41 = F_2 ( V_2 , 0 , 15 ) ;
V_41 &= 0x0f ;
V_17 -> V_40 [ V_14 ] = V_41 ;
if ( V_14 == 1 )
V_41 <<= 4 ;
F_6 ( V_5 , V_43 ,
V_42 | V_41 ) ;
F_16 ( & V_17 -> V_19 ) ;
return V_13 ;
}
static int
F_32 ( struct V_4 * V_5 , struct V_44 * V_45 )
{
struct V_46 * V_47 = V_5 -> V_47 ;
T_4 V_48 ;
T_1 V_49 ;
if ( ! F_33 ( V_47 , V_50 ) )
return - V_51 ;
if ( ( F_4 ( V_5 , V_52 ) & 0x80 ) ) {
F_34 ( & V_47 -> V_9 , L_4 ,
V_5 -> V_53 ) ;
return - V_51 ;
}
V_48 = ( F_4 ( V_5 , V_54 ) << 8 ) +
F_4 ( V_5 , V_55 ) ;
V_49 = F_4 ( V_5 , V_56 ) ;
if ( V_48 != 0x5CA3 ||
V_49 != 0x80 ) {
F_34 ( & V_47 -> V_9 ,
L_5 ,
V_48 , V_49 ) ;
return - V_51 ;
}
F_35 ( V_45 -> type , L_6 , V_57 ) ;
return 0 ;
}
static int
F_36 ( struct V_4 * V_5 , const struct V_58 * V_59 )
{
struct V_8 * V_9 = & V_5 -> V_9 ;
struct V_16 * V_17 ;
int V_3 , V_18 = 0 ;
T_1 V_60 ;
V_17 = F_37 ( sizeof( struct V_16 ) , V_61 ) ;
if ( ! V_17 ) {
V_18 = - V_62 ;
goto exit;
}
F_38 ( V_5 , V_17 ) ;
F_39 ( & V_17 -> V_19 ) ;
F_40 ( V_5 ) ;
for ( V_3 = 0 ; V_3 < 2 ; V_3 ++ ) {
V_17 -> V_20 [ V_3 ] = F_4 ( V_5 ,
F_15 ( V_3 ) ) ;
}
V_60 = F_4 ( V_5 , V_27 ) ;
V_17 -> V_21 [ 0 ] = V_60 & 0x07 ;
V_17 -> V_21 [ 1 ] = ( V_60 >> 4 ) & 0x07 ;
V_18 = F_41 ( & V_5 -> V_9 . V_63 , & V_64 ) ;
if ( V_18 )
goto V_65;
V_17 -> V_66 = F_42 ( V_9 ) ;
if ( F_43 ( V_17 -> V_66 ) ) {
V_18 = F_44 ( V_17 -> V_66 ) ;
goto V_65;
}
return 0 ;
V_65:
F_45 ( & V_5 -> V_9 . V_63 , & V_64 ) ;
F_46 ( V_17 ) ;
exit:
return V_18 ;
}
static int
F_47 ( struct V_4 * V_5 )
{
struct V_16 * V_17 = F_11 ( V_5 ) ;
F_48 ( V_17 -> V_66 ) ;
F_45 ( & V_5 -> V_9 . V_63 , & V_64 ) ;
F_46 ( V_17 ) ;
return 0 ;
}
static void
F_40 ( struct V_4 * V_5 )
{
T_1 V_67 ;
if ( V_68 )
F_6 ( V_5 , V_52 , 0x80 ) ;
V_67 = F_4 ( V_5 , V_52 ) ;
if ( ! ( V_67 & 0x01 ) )
F_6 ( V_5 , V_52 , V_67 | 0x01 ) ;
}
static struct V_16 * F_18 ( struct V_8 * V_9 )
{
struct V_4 * V_5 = F_10 ( V_9 ) ;
struct V_16 * V_17 = F_11 ( V_5 ) ;
int V_3 , V_69 ;
T_1 V_60 , V_70 ;
F_13 ( & V_17 -> V_19 ) ;
if ( F_49 ( V_71 , V_17 -> V_72 + V_73 + V_73 / 2 )
|| ! V_17 -> V_74 ) {
F_34 ( & V_5 -> V_9 , L_7 ) ;
for ( V_3 = 0 ; V_3 < 3 ; V_3 ++ ) {
V_17 -> V_75 [ V_3 ] = F_4 ( V_5 ,
F_50 ( V_3 ) ) ;
V_17 -> V_76 [ V_3 ] = F_4 ( V_5 ,
F_51 ( V_3 ) ) ;
V_17 -> V_77 [ V_3 ] = F_4 ( V_5 ,
F_52 ( V_3 ) ) ;
}
for ( V_3 = 0 ; V_3 < 2 ; V_3 ++ ) {
V_17 -> V_78 [ V_3 ] = F_4 ( V_5 ,
F_53 ( V_3 ) ) ;
V_17 -> V_20 [ V_3 ] = F_4 ( V_5 ,
F_15 ( V_3 ) ) ;
}
V_60 = F_4 ( V_5 , V_27 ) ;
V_17 -> V_21 [ 0 ] = V_60 & 0x07 ;
V_17 -> V_21 [ 1 ] = ( V_60 >> 4 ) & 0x07 ;
V_70 = F_4 ( V_5 , V_34 ) ;
for ( V_3 = 0 ; V_3 < 2 ; V_3 ++ ) {
V_17 -> V_33 [ V_3 ] =
( ( V_70 >> V_35 [ V_3 ] ) & 1 )
? 0 : 1 ;
V_17 -> V_38 [ V_3 ] =
( ( V_70 >> V_39 [ V_3 ] ) & 2 ) + 1 ;
V_17 -> V_36 [ V_3 ] = F_4 ( V_5 ,
V_37 [ V_3 ] ) ;
}
for ( V_3 = 0 ; V_3 < 2 ; V_3 ++ ) {
for ( V_69 = 0 ; V_69 < 3 ; V_69 ++ ) {
V_17 -> V_30 [ V_3 ] [ V_69 ] = F_4 ( V_5 ,
V_31 [ V_3 ] [ V_69 ] ) ;
}
}
V_60 = F_4 ( V_5 , V_43 ) ;
V_17 -> V_40 [ 0 ] = V_60 & 0x0f ;
V_17 -> V_40 [ 1 ] = ( V_60 >> 4 ) & 0x0f ;
V_17 -> V_72 = V_71 ;
V_17 -> V_74 = 1 ;
}
F_16 ( & V_17 -> V_19 ) ;
return V_17 ;
}
