static inline void
F_1 ( struct V_1 * V_2 , int V_3 , int V_4 )
{
F_2 ( V_3 , V_2 -> V_5 ) ;
F_2 ( V_4 , V_2 -> V_5 + 1 ) ;
}
static inline int
F_3 ( struct V_1 * V_2 , int V_3 )
{
F_2 ( V_3 , V_2 -> V_5 ) ;
return F_4 ( V_2 -> V_5 + 1 ) ;
}
static inline void
F_5 ( struct V_1 * V_2 , int V_6 )
{
F_2 ( V_7 , V_2 -> V_5 ) ;
F_2 ( V_6 , V_2 -> V_5 + 1 ) ;
}
static inline void
F_6 ( struct V_1 * V_2 )
{
F_2 ( 0x87 , V_2 -> V_5 ) ;
F_2 ( 0x87 , V_2 -> V_5 ) ;
}
static inline void
F_7 ( struct V_1 * V_2 )
{
F_2 ( 0xAA , V_2 -> V_5 ) ;
}
static inline T_1 F_8 ( long V_8 , int div )
{
if ( V_8 == 0 )
return 255 ;
V_8 = F_9 ( V_8 , 1 , 1000000 ) ;
return F_9 ( ( 1350000 + V_8 * div / 2 ) / ( V_8 * div ) , 1 ,
254 ) ;
}
static T_1 F_10 ( long V_9 )
{
int V_10 = F_9 ( V_9 , V_11 , V_12 ) ;
V_10 += ( V_10 < 0 ? - 500 : 500 ) ;
return ( T_1 ) ( V_10 / 1000 ) ;
}
static int F_11 ( T_1 V_3 )
{
return ( V_13 ) V_3 * 1000 ;
}
static inline unsigned long F_12 ( T_1 V_3 )
{
unsigned long V_14 ;
V_14 = V_15 >> V_3 ;
return V_14 ;
}
static inline T_1 F_13 ( unsigned long V_4 )
{
T_1 V_16 ;
for ( V_16 = 0 ; V_16 < 4 ; V_16 ++ ) {
if ( V_4 > ( ( ( V_15 >> V_16 ) +
( V_15 >> ( V_16 + 1 ) ) ) / 2 ) )
break;
}
return V_16 ;
}
static inline unsigned long F_14 ( T_1 V_3 )
{
unsigned long clock = ( V_3 & 0x80 ) ? 180000UL : 24000000UL ;
V_3 &= 0x7f ;
if ( V_3 == 0 )
V_3 ++ ;
return clock / ( V_3 << 8 ) ;
}
static inline T_1 F_15 ( unsigned long V_4 )
{
if ( V_4 >= 93750 )
return 0x01 ;
if ( V_4 >= 720 )
return 24000000UL / ( V_4 << 8 ) ;
if ( V_4 < 6 )
return 0xFF ;
else
return 0x80 | ( 180000UL / ( V_4 << 8 ) ) ;
}
static inline T_1 F_16 ( long V_4 )
{
int V_16 ;
V_4 = F_9 ( V_4 , 1 , 128 ) >> 1 ;
for ( V_16 = 0 ; V_16 < 7 ; V_16 ++ ) {
if ( V_4 == 0 )
break;
V_4 >>= 1 ;
}
return ( T_1 ) V_16 ;
}
static T_2
F_17 ( struct V_17 * V_18 , struct V_19 * V_20 , char * V_21 )
{
int V_22 = F_18 ( V_20 ) -> V_23 ;
struct V_24 * V_25 = F_19 ( V_18 ) ;
return sprintf ( V_21 , L_1 , ( long ) F_20 ( V_25 -> V_26 [ V_22 ] ) ) ;
}
static T_2
F_21 ( struct V_17 * V_18 , struct V_19 * V_20 , char * V_21 )
{
int V_22 = F_18 ( V_20 ) -> V_23 ;
struct V_24 * V_25 = F_19 ( V_18 ) ;
return sprintf ( V_21 , L_1 , ( long ) F_20 ( V_25 -> V_27 [ V_22 ] ) ) ;
}
static T_2
F_22 ( struct V_17 * V_18 , struct V_19 * V_20 , char * V_21 )
{
int V_22 = F_18 ( V_20 ) -> V_23 ;
struct V_24 * V_25 = F_19 ( V_18 ) ;
return sprintf ( V_21 , L_1 , ( long ) F_20 ( V_25 -> V_28 [ V_22 ] ) ) ;
}
static T_2
F_23 ( struct V_17 * V_18 , struct V_19 * V_20 ,
const char * V_21 , T_3 V_29 )
{
int V_22 = F_18 ( V_20 ) -> V_23 ;
struct V_24 * V_25 = F_24 ( V_18 ) ;
long V_4 ;
int V_30 ;
V_30 = F_25 ( V_21 , 10 , & V_4 ) ;
if ( V_30 )
return V_30 ;
F_26 ( & V_25 -> V_31 ) ;
V_25 -> V_27 [ V_22 ] = F_27 ( V_4 ) ;
F_28 ( V_25 , F_29 ( V_22 ) , V_25 -> V_27 [ V_22 ] ) ;
F_30 ( & V_25 -> V_31 ) ;
return V_29 ;
}
static T_2
F_31 ( struct V_17 * V_18 , struct V_19 * V_20 ,
const char * V_21 , T_3 V_29 )
{
int V_22 = F_18 ( V_20 ) -> V_23 ;
struct V_24 * V_25 = F_24 ( V_18 ) ;
long V_4 ;
int V_30 ;
V_30 = F_25 ( V_21 , 10 , & V_4 ) ;
if ( V_30 )
return V_30 ;
F_26 ( & V_25 -> V_31 ) ;
V_25 -> V_28 [ V_22 ] = F_27 ( V_4 ) ;
F_28 ( V_25 , F_32 ( V_22 ) , V_25 -> V_28 [ V_22 ] ) ;
F_30 ( & V_25 -> V_31 ) ;
return V_29 ;
}
static T_2 F_33 ( struct V_24 * V_25 , char * V_21 , T_1 V_3 )
{
long V_32 ;
if ( ( V_25 -> V_33 & 0x01 ) &&
( V_34 == V_25 -> type || V_35 == V_25 -> type
|| V_36 == V_25 -> type ) )
V_32 = ( long ) ( ( V_3 * 488 + 70000 + 50 ) / 100 ) ;
else
V_32 = ( long ) F_20 ( V_3 ) ;
return sprintf ( V_21 , L_1 , V_32 ) ;
}
static T_2 F_34 ( struct V_17 * V_18 , struct V_19 * V_37 , char * V_21 )
{
struct V_24 * V_25 = F_19 ( V_18 ) ;
return F_33 ( V_25 , V_21 , V_25 -> V_26 [ 0 ] ) ;
}
static T_2 F_35 ( struct V_17 * V_18 , struct V_19 * V_37 , char * V_21 )
{
struct V_24 * V_25 = F_19 ( V_18 ) ;
return F_33 ( V_25 , V_21 , V_25 -> V_27 [ 0 ] ) ;
}
static T_2 F_36 ( struct V_17 * V_18 , struct V_19 * V_37 , char * V_21 )
{
struct V_24 * V_25 = F_19 ( V_18 ) ;
return F_33 ( V_25 , V_21 , V_25 -> V_28 [ 0 ] ) ;
}
static T_2 F_37 ( struct V_17 * V_18 , struct V_19 * V_37 ,
const char * V_21 , T_3 V_29 )
{
struct V_24 * V_25 = F_24 ( V_18 ) ;
unsigned long V_4 ;
int V_30 ;
V_30 = F_38 ( V_21 , 10 , & V_4 ) ;
if ( V_30 )
return V_30 ;
F_26 ( & V_25 -> V_31 ) ;
if ( ( V_25 -> V_33 & 0x01 ) &&
( V_34 == V_25 -> type || V_35 == V_25 -> type
|| V_36 == V_25 -> type ) )
V_25 -> V_27 [ 0 ] =
F_9 ( ( ( V_4 * 100 ) - 70000 + 244 ) / 488 , 0 ,
255 ) ;
else
V_25 -> V_27 [ 0 ] = F_27 ( V_4 ) ;
F_28 ( V_25 , F_29 ( 0 ) , V_25 -> V_27 [ 0 ] ) ;
F_30 ( & V_25 -> V_31 ) ;
return V_29 ;
}
static T_2 F_39 ( struct V_17 * V_18 , struct V_19 * V_37 ,
const char * V_21 , T_3 V_29 )
{
struct V_24 * V_25 = F_24 ( V_18 ) ;
unsigned long V_4 ;
int V_30 ;
V_30 = F_38 ( V_21 , 10 , & V_4 ) ;
if ( V_30 )
return V_30 ;
F_26 ( & V_25 -> V_31 ) ;
if ( ( V_25 -> V_33 & 0x01 ) &&
( V_34 == V_25 -> type || V_35 == V_25 -> type
|| V_36 == V_25 -> type ) )
V_25 -> V_28 [ 0 ] =
F_9 ( ( ( V_4 * 100 ) - 70000 + 244 ) / 488 , 0 ,
255 ) ;
else
V_25 -> V_28 [ 0 ] = F_27 ( V_4 ) ;
F_28 ( V_25 , F_32 ( 0 ) , V_25 -> V_28 [ 0 ] ) ;
F_30 ( & V_25 -> V_31 ) ;
return V_29 ;
}
static T_2
F_40 ( struct V_17 * V_18 , struct V_19 * V_20 , char * V_21 )
{
int V_22 = F_18 ( V_20 ) -> V_23 ;
struct V_24 * V_25 = F_19 ( V_18 ) ;
return sprintf ( V_21 , L_1 , F_41 ( V_25 -> V_38 [ V_22 ] ,
( long ) F_42 ( V_25 -> V_39 [ V_22 ] ) ) ) ;
}
static T_2
F_43 ( struct V_17 * V_18 , struct V_19 * V_20 , char * V_21 )
{
int V_22 = F_18 ( V_20 ) -> V_23 ;
struct V_24 * V_25 = F_19 ( V_18 ) ;
return sprintf ( V_21 , L_1 , F_41 ( V_25 -> V_40 [ V_22 ] ,
( long ) F_42 ( V_25 -> V_39 [ V_22 ] ) ) ) ;
}
static T_2
F_44 ( struct V_17 * V_18 , struct V_19 * V_20 ,
const char * V_21 , T_3 V_29 )
{
int V_22 = F_18 ( V_20 ) -> V_23 ;
struct V_24 * V_25 = F_24 ( V_18 ) ;
unsigned long V_4 ;
int V_30 ;
V_30 = F_38 ( V_21 , 10 , & V_4 ) ;
if ( V_30 )
return V_30 ;
F_26 ( & V_25 -> V_31 ) ;
V_25 -> V_40 [ V_22 ] = F_8 ( V_4 , F_42 ( V_25 -> V_39 [ V_22 ] ) ) ;
F_28 ( V_25 , F_45 ( V_22 ) ,
V_25 -> V_40 [ V_22 ] ) ;
F_30 ( & V_25 -> V_31 ) ;
return V_29 ;
}
static T_2
F_46 ( struct V_17 * V_18 , struct V_19 * V_20 , char * V_21 )
{
int V_22 = F_18 ( V_20 ) -> V_23 ;
struct V_24 * V_25 = F_19 ( V_18 ) ;
T_4 V_41 = V_25 -> V_9 [ V_22 ] ;
return sprintf ( V_21 , L_1 , ( V_22 ) ? ( long ) F_47 ( V_41 )
: ( long ) F_11 ( V_41 ) ) ;
}
static T_2
F_48 ( struct V_17 * V_18 , struct V_19 * V_20 ,
char * V_21 )
{
int V_22 = F_18 ( V_20 ) -> V_23 ;
struct V_24 * V_25 = F_19 ( V_18 ) ;
T_4 V_41 = V_25 -> V_42 [ V_22 ] ;
return sprintf ( V_21 , L_1 , ( V_22 ) ? ( long ) F_47 ( V_41 )
: ( long ) F_11 ( V_41 ) ) ;
}
static T_2
F_49 ( struct V_17 * V_18 , struct V_19 * V_20 ,
char * V_21 )
{
int V_22 = F_18 ( V_20 ) -> V_23 ;
struct V_24 * V_25 = F_19 ( V_18 ) ;
T_4 V_41 = V_25 -> V_43 [ V_22 ] ;
return sprintf ( V_21 , L_1 , ( V_22 ) ? ( long ) F_47 ( V_41 )
: ( long ) F_11 ( V_41 ) ) ;
}
static T_2
F_50 ( struct V_17 * V_18 , struct V_19 * V_20 ,
const char * V_21 , T_3 V_29 )
{
int V_22 = F_18 ( V_20 ) -> V_23 ;
struct V_24 * V_25 = F_24 ( V_18 ) ;
T_4 V_41 ;
long V_4 ;
int V_30 ;
V_30 = F_25 ( V_21 , 10 , & V_4 ) ;
if ( V_30 )
return V_30 ;
V_41 = ( V_22 ) ? F_51 ( V_4 ) : F_10 ( V_4 ) ;
F_26 ( & V_25 -> V_31 ) ;
V_25 -> V_42 [ V_22 ] = V_41 ;
F_28 ( V_25 , V_44 [ V_22 ] , V_41 ) ;
F_30 ( & V_25 -> V_31 ) ;
return V_29 ;
}
static T_2
F_52 ( struct V_17 * V_18 , struct V_19 * V_20 ,
const char * V_21 , T_3 V_29 )
{
int V_22 = F_18 ( V_20 ) -> V_23 ;
struct V_24 * V_25 = F_24 ( V_18 ) ;
T_4 V_41 ;
long V_4 ;
int V_30 ;
V_30 = F_25 ( V_21 , 10 , & V_4 ) ;
if ( V_30 )
return V_30 ;
V_41 = ( V_22 ) ? F_51 ( V_4 ) : F_10 ( V_4 ) ;
F_26 ( & V_25 -> V_31 ) ;
V_25 -> V_43 [ V_22 ] = V_41 ;
F_28 ( V_25 , V_45 [ V_22 ] , V_41 ) ;
F_30 ( & V_25 -> V_31 ) ;
return V_29 ;
}
static T_2
F_53 ( struct V_17 * V_18 , struct V_19 * V_37 , char * V_21 )
{
struct V_24 * V_25 = F_19 ( V_18 ) ;
return sprintf ( V_21 , L_1 , ( long ) F_54 ( V_25 -> V_46 , V_25 -> V_47 ) ) ;
}
static T_2
F_55 ( struct V_17 * V_18 , struct V_19 * V_37 , char * V_21 )
{
struct V_24 * V_25 = F_24 ( V_18 ) ;
return sprintf ( V_21 , L_1 , ( long ) V_25 -> V_47 ) ;
}
static T_2
F_56 ( struct V_17 * V_18 , struct V_19 * V_37 , const char * V_21 , T_3 V_29 )
{
struct V_24 * V_25 = F_24 ( V_18 ) ;
unsigned long V_4 ;
int V_30 ;
V_30 = F_38 ( V_21 , 10 , & V_4 ) ;
if ( V_30 )
return V_30 ;
V_25 -> V_47 = V_4 ;
return V_29 ;
}
static T_2
F_57 ( struct V_17 * V_18 , struct V_19 * V_37 , char * V_21 )
{
struct V_24 * V_25 = F_19 ( V_18 ) ;
return sprintf ( V_21 , L_1 , ( long ) V_25 -> V_48 ) ;
}
static T_2
F_58 ( struct V_17 * V_18 , struct V_19 * V_37 , char * V_21 )
{
struct V_24 * V_25 = F_19 ( V_18 ) ;
int V_49 = F_18 ( V_37 ) -> V_23 ;
return sprintf ( V_21 , L_2 , ( V_25 -> V_48 >> V_49 ) & 1 ) ;
}
static T_2
F_59 ( struct V_17 * V_18 , struct V_19 * V_37 , char * V_21 )
{
struct V_24 * V_25 = F_19 ( V_18 ) ;
return sprintf ( V_21 , L_1 ,
( long ) F_60 ( V_25 -> V_50 ) ) ;
}
static T_2
F_61 ( struct V_17 * V_18 , struct V_19 * V_37 ,
const char * V_21 , T_3 V_29 )
{
struct V_24 * V_25 = F_24 ( V_18 ) ;
unsigned long V_4 ;
int V_30 ;
V_30 = F_38 ( V_21 , 10 , & V_4 ) ;
if ( V_30 )
return V_30 ;
F_26 ( & V_25 -> V_31 ) ;
V_25 -> V_50 = ( V_25 -> V_50 & 0x8000 )
| F_62 ( V_4 ) ;
F_28 ( V_25 , V_51 ,
V_25 -> V_50 & 0xff ) ;
F_28 ( V_25 , V_52 ,
( ( V_25 -> V_50 ) >> 16 ) & 0xff ) ;
F_28 ( V_25 , V_53 ,
( V_25 -> V_50 >> 8 ) & 0xff ) ;
F_30 ( & V_25 -> V_31 ) ;
return V_29 ;
}
static T_2
F_63 ( struct V_17 * V_18 , struct V_19 * V_37 , char * V_21 )
{
struct V_24 * V_25 = F_19 ( V_18 ) ;
int V_49 = F_18 ( V_37 ) -> V_23 ;
return sprintf ( V_21 , L_2 , ( V_25 -> V_50 >> V_49 ) & 1 ) ;
}
static T_2
F_64 ( struct V_17 * V_18 , struct V_19 * V_37 ,
const char * V_21 , T_3 V_29 )
{
struct V_24 * V_25 = F_24 ( V_18 ) ;
int V_49 = F_18 ( V_37 ) -> V_23 ;
T_1 V_3 ;
unsigned long V_54 ;
int V_30 ;
V_30 = F_38 ( V_21 , 10 , & V_54 ) ;
if ( V_30 )
return V_30 ;
if ( V_54 & ~ 1 )
return - V_55 ;
F_26 ( & V_25 -> V_31 ) ;
if ( V_54 )
V_25 -> V_50 |= ( 1 << V_49 ) ;
else
V_25 -> V_50 &= ~ ( 1 << V_49 ) ;
if ( V_49 < 8 ) {
V_3 = F_65 ( V_25 , V_51 ) ;
if ( V_54 )
V_3 |= ( 1 << V_49 ) ;
else
V_3 &= ~ ( 1 << V_49 ) ;
F_28 ( V_25 , V_51 , V_3 ) ;
} else if ( V_49 < 16 ) {
V_3 = F_65 ( V_25 , V_53 ) ;
if ( V_54 )
V_3 |= ( 1 << ( V_49 - 8 ) ) ;
else
V_3 &= ~ ( 1 << ( V_49 - 8 ) ) ;
F_28 ( V_25 , V_53 , V_3 ) ;
} else {
V_3 = F_65 ( V_25 , V_52 ) ;
if ( V_54 )
V_3 |= ( 1 << ( V_49 - 16 ) ) ;
else
V_3 &= ~ ( 1 << ( V_49 - 16 ) ) ;
F_28 ( V_25 , V_52 , V_3 ) ;
}
F_30 ( & V_25 -> V_31 ) ;
return V_29 ;
}
static T_2
F_66 ( struct V_17 * V_18 , struct V_19 * V_20 , char * V_21 )
{
int V_22 = F_18 ( V_20 ) -> V_23 ;
struct V_24 * V_25 = F_19 ( V_18 ) ;
return sprintf ( V_21 , L_1 ,
( long ) F_42 ( V_25 -> V_39 [ V_22 ] ) ) ;
}
static T_2
F_67 ( struct V_17 * V_18 , struct V_19 * V_20 ,
const char * V_21 , T_3 V_29 )
{
int V_22 = F_18 ( V_20 ) -> V_23 ;
struct V_24 * V_25 = F_24 ( V_18 ) ;
unsigned long V_56 ;
T_1 V_3 ;
unsigned long V_4 ;
int V_30 ;
V_30 = F_38 ( V_21 , 10 , & V_4 ) ;
if ( V_30 )
return V_30 ;
F_26 ( & V_25 -> V_31 ) ;
V_56 = F_41 ( V_25 -> V_40 [ V_22 ] ,
F_42 ( V_25 -> V_39 [ V_22 ] ) ) ;
V_25 -> V_39 [ V_22 ] = F_16 ( V_4 ) ;
V_3 = ( F_65 ( V_25 , V_22 == 2 ? V_57 : V_58 )
& ( V_22 == 0 ? 0xcf : 0x3f ) )
| ( ( V_25 -> V_39 [ V_22 ] & 0x03 ) << ( V_22 == 0 ? 4 : 6 ) ) ;
F_28 ( V_25 , V_22 == 2 ? V_57 : V_58 , V_3 ) ;
V_3 = ( F_65 ( V_25 , V_59 )
& ~ ( 1 << ( 5 + V_22 ) ) )
| ( ( V_25 -> V_39 [ V_22 ] & 0x04 ) << ( 3 + V_22 ) ) ;
F_28 ( V_25 , V_59 , V_3 ) ;
V_25 -> V_40 [ V_22 ] = F_8 ( V_56 , F_42 ( V_25 -> V_39 [ V_22 ] ) ) ;
F_28 ( V_25 , F_45 ( V_22 ) , V_25 -> V_40 [ V_22 ] ) ;
F_30 ( & V_25 -> V_31 ) ;
return V_29 ;
}
static T_2
F_68 ( struct V_17 * V_18 , struct V_19 * V_20 , char * V_21 )
{
int V_22 = F_18 ( V_20 ) -> V_23 ;
struct V_24 * V_25 = F_19 ( V_18 ) ;
return sprintf ( V_21 , L_1 , ( long ) V_25 -> V_60 [ V_22 ] ) ;
}
static T_2
F_69 ( struct V_17 * V_18 , struct V_19 * V_20 ,
const char * V_21 , T_3 V_29 )
{
int V_22 = F_18 ( V_20 ) -> V_23 ;
struct V_24 * V_25 = F_24 ( V_18 ) ;
unsigned long V_4 ;
int V_30 ;
V_30 = F_38 ( V_21 , 10 , & V_4 ) ;
if ( V_30 )
return V_30 ;
F_26 ( & V_25 -> V_31 ) ;
if ( V_25 -> type == V_34 ) {
V_25 -> V_60 [ V_22 ] = F_70 ( V_4 ) & 0xf0 ;
F_28 ( V_25 ,
F_71 ( V_25 -> type , V_22 ) ,
V_25 -> V_60 [ V_22 ] |
( F_65 ( V_25 ,
F_71 ( V_25 -> type , V_22 ) ) & 0x0f ) ) ;
} else {
V_25 -> V_60 [ V_22 ] = F_70 ( V_4 ) ;
F_28 ( V_25 ,
F_71 ( V_25 -> type , V_22 ) ,
V_25 -> V_60 [ V_22 ] ) ;
}
F_30 ( & V_25 -> V_31 ) ;
return V_29 ;
}
static T_2
F_72 ( struct V_17 * V_18 , struct V_19 * V_20 , char * V_21 )
{
int V_22 = F_18 ( V_20 ) -> V_23 ;
struct V_24 * V_25 = F_19 ( V_18 ) ;
return sprintf ( V_21 , L_3 , V_25 -> V_61 [ V_22 ] ) ;
}
static T_2
F_73 ( struct V_17 * V_18 , struct V_19 * V_20 ,
const char * V_21 , T_3 V_29 )
{
int V_22 = F_18 ( V_20 ) -> V_23 ;
struct V_24 * V_25 = F_24 ( V_18 ) ;
T_1 V_3 ;
unsigned long V_4 ;
int V_30 ;
V_30 = F_38 ( V_21 , 10 , & V_4 ) ;
if ( V_30 )
return V_30 ;
if ( ! V_4 || V_4 > 3 )
return - V_55 ;
F_26 ( & V_25 -> V_31 ) ;
V_25 -> V_61 [ V_22 ] = V_4 ;
V_3 = F_65 ( V_25 , V_62 [ V_22 ] ) ;
V_3 &= ~ ( 0x03 << V_63 [ V_22 ] ) ;
V_3 |= ( V_4 - 1 ) << V_63 [ V_22 ] ;
F_28 ( V_25 , V_62 [ V_22 ] , V_3 ) ;
F_30 ( & V_25 -> V_31 ) ;
return V_29 ;
}
static T_2
F_74 ( struct V_17 * V_18 , struct V_19 * V_20 , char * V_21 )
{
int V_22 = F_18 ( V_20 ) -> V_23 ;
struct V_24 * V_25 = F_19 ( V_18 ) ;
if ( V_25 -> type == V_64 )
return sprintf ( V_21 , L_1 ,
F_12 ( V_25 -> V_65 [ V_22 ] ) ) ;
else
return sprintf ( V_21 , L_1 ,
F_14 ( V_25 -> V_65 [ V_22 ] ) ) ;
}
static T_2
F_75 ( struct V_17 * V_18 , struct V_19 * V_20 ,
const char * V_21 , T_3 V_29 )
{
int V_22 = F_18 ( V_20 ) -> V_23 ;
struct V_24 * V_25 = F_24 ( V_18 ) ;
static const T_1 V_66 [] = { 0xF8 , 0x8F } ;
unsigned long V_4 ;
int V_30 ;
V_30 = F_38 ( V_21 , 10 , & V_4 ) ;
if ( V_30 )
return V_30 ;
F_26 ( & V_25 -> V_31 ) ;
if ( V_25 -> type == V_64 ) {
V_25 -> V_65 [ V_22 ] = F_13 ( V_4 ) ;
F_28 ( V_25 , V_67 ,
( V_25 -> V_65 [ V_22 ] << ( V_22 * 4 ) ) |
( F_65 ( V_25 ,
V_67 ) & V_66 [ V_22 ] ) ) ;
} else {
V_25 -> V_65 [ V_22 ] = F_15 ( V_4 ) ;
F_28 ( V_25 , V_68 [ V_22 ] ,
V_25 -> V_65 [ V_22 ] ) ;
}
F_30 ( & V_25 -> V_31 ) ;
return V_29 ;
}
static T_2
F_76 ( struct V_17 * V_18 , struct V_19 * V_20 ,
char * V_21 )
{
int V_22 = F_18 ( V_20 ) -> V_23 ;
struct V_24 * V_25 = F_19 ( V_18 ) ;
return sprintf ( V_21 , L_1 , ( long ) V_25 -> V_69 [ V_22 ] ) ;
}
static T_2
F_77 ( struct V_17 * V_18 , struct V_19 * V_20 ,
const char * V_21 , T_3 V_29 )
{
int V_22 = F_18 ( V_20 ) -> V_23 ;
struct V_24 * V_25 = F_24 ( V_18 ) ;
unsigned long V_4 ;
T_5 V_41 ;
int V_30 ;
V_30 = F_38 ( V_21 , 10 , & V_4 ) ;
if ( V_30 )
return V_30 ;
F_26 ( & V_25 -> V_31 ) ;
switch ( V_4 ) {
case 1 :
V_41 = F_65 ( V_25 , V_70 ) ;
F_28 ( V_25 , V_70 ,
V_41 | V_71 [ V_22 ] ) ;
V_41 = F_65 ( V_25 , V_72 ) ;
F_28 ( V_25 , V_72 ,
V_41 | V_73 [ V_22 ] ) ;
V_25 -> V_69 [ V_22 ] = V_4 ;
break;
case 2 :
V_41 = F_65 ( V_25 , V_70 ) ;
F_28 ( V_25 , V_70 ,
V_41 | V_71 [ V_22 ] ) ;
V_41 = F_65 ( V_25 , V_72 ) ;
F_28 ( V_25 , V_72 ,
V_41 & ~ V_73 [ V_22 ] ) ;
V_25 -> V_69 [ V_22 ] = V_4 ;
break;
case V_74 :
F_78 ( V_18 , L_4
L_5 , V_74 ) ;
case 4 :
V_41 = F_65 ( V_25 , V_70 ) ;
F_28 ( V_25 , V_70 ,
V_41 & ~ V_71 [ V_22 ] ) ;
V_25 -> V_69 [ V_22 ] = V_4 ;
break;
default:
F_79 ( V_18 ,
L_6 ,
( long ) V_4 ) ;
break;
}
F_30 ( & V_25 -> V_31 ) ;
return V_29 ;
}
static T_2
F_80 ( struct V_17 * V_18 , struct V_19 * V_20 , char * V_21 )
{
struct V_24 * V_25 = F_24 ( V_18 ) ;
return sprintf ( V_21 , L_7 , V_25 -> V_75 ) ;
}
static int T_6 F_81 ( int V_5 , unsigned short * V_76 ,
struct V_1 * V_77 )
{
int V_30 = - V_78 ;
T_4 V_4 ;
static const T_7 char * V_79 [] = {
L_8 ,
L_9 ,
L_10 ,
L_11 ,
L_12 ,
} ;
V_77 -> V_5 = V_5 ;
F_6 ( V_77 ) ;
V_4 = V_80 ? V_80 : F_3 ( V_77 , V_81 ) ;
switch ( V_4 ) {
case V_82 :
V_77 -> type = V_64 ;
break;
case V_83 :
V_77 -> type = V_34 ;
break;
case V_84 :
V_77 -> type = V_85 ;
break;
case V_86 :
V_77 -> type = V_35 ;
break;
case V_87 :
V_77 -> type = V_36 ;
break;
case 0xff :
goto exit;
default:
F_82 ( V_88 L_13 , V_4 ) ;
goto exit;
}
F_5 ( V_77 , V_89 ) ;
V_4 = ( F_3 ( V_77 , V_90 ) << 8 ) |
F_3 ( V_77 , V_90 + 1 ) ;
* V_76 = V_4 & V_91 ;
if ( * V_76 == 0 ) {
F_83 ( L_14 ) ;
goto exit;
}
V_4 = F_3 ( V_77 , V_92 ) ;
if ( ! ( V_4 & 0x01 ) ) {
F_83 ( L_15 ) ;
F_1 ( V_77 , V_92 , V_4 | 0x01 ) ;
}
V_30 = 0 ;
F_84 ( V_88 L_16 ,
V_79 [ V_77 -> type ] , * V_76 ) ;
exit:
F_7 ( V_77 ) ;
return V_30 ;
}
static int T_8 F_85 ( struct V_93 * V_94 )
{
struct V_17 * V_18 = & V_94 -> V_18 ;
struct V_1 * V_77 = V_18 -> V_95 ;
struct V_24 * V_25 ;
struct V_96 * V_97 ;
int V_30 , V_16 ;
static const char * V_79 [] = {
L_17 ,
L_18 ,
L_19 ,
L_20 ,
L_21 ,
} ;
V_97 = F_86 ( V_94 , V_98 , 0 ) ;
if ( ! F_87 ( V_97 -> V_99 , V_100 , V_88 ) ) {
F_79 ( V_18 , L_22 ,
( unsigned long ) V_97 -> V_99 ,
( unsigned long ) ( V_97 -> V_99 + V_100 - 1 ) ) ;
V_30 = - V_101 ;
goto V_102;
}
V_25 = F_88 ( sizeof( struct V_24 ) , V_103 ) ;
if ( ! V_25 ) {
V_30 = - V_104 ;
goto V_105;
}
V_25 -> V_76 = V_97 -> V_99 ;
V_25 -> type = V_77 -> type ;
V_25 -> V_75 = V_79 [ V_77 -> type ] ;
F_89 ( & V_25 -> V_106 ) ;
F_89 ( & V_25 -> V_31 ) ;
F_90 ( V_94 , V_25 ) ;
F_91 ( V_94 ) ;
for ( V_16 = 0 ; V_16 <= 2 ; V_16 ++ )
V_25 -> V_40 [ V_16 ] = F_65 (
V_25 , F_45 ( V_16 ) ) ;
F_92 ( V_25 ) ;
V_30 = F_93 ( & V_18 -> V_107 , & V_108 ) ;
if ( V_30 )
goto V_109;
if ( V_25 -> type == V_64 || V_25 -> type == V_85 )
if ( ( V_30 = F_94 ( V_18 ,
& V_110 . V_111 ) )
|| ( V_30 = F_94 ( V_18 ,
& V_112 . V_111 ) )
|| ( V_30 = F_94 ( V_18 ,
& V_113 . V_111 ) )
|| ( V_30 = F_94 ( V_18 ,
& V_114 . V_111 ) )
|| ( V_30 = F_94 ( V_18 ,
& V_115 . V_111 ) )
|| ( V_30 = F_94 ( V_18 ,
& V_116 . V_111 ) )
|| ( V_30 = F_94 ( V_18 ,
& V_117 . V_111 ) )
|| ( V_30 = F_94 ( V_18 ,
& V_118 . V_111 ) )
|| ( V_30 = F_94 ( V_18 ,
& V_119 . V_111 ) )
|| ( V_30 = F_94 ( V_18 ,
& V_120 . V_111 ) )
|| ( V_30 = F_94 ( V_18 ,
& V_121 . V_111 ) )
|| ( V_30 = F_94 ( V_18 ,
& V_122 . V_111 ) ) )
goto V_123;
if ( V_25 -> type != V_85 )
if ( ( V_30 = F_94 ( V_18 ,
& V_124 . V_111 ) )
|| ( V_30 = F_94 ( V_18 ,
& V_125 . V_111 ) )
|| ( V_30 = F_94 ( V_18 ,
& V_126 . V_111 ) )
|| ( V_30 = F_94 ( V_18 ,
& V_127 . V_111 ) )
|| ( V_30 = F_94 ( V_18 ,
& V_128 . V_111 ) )
|| ( V_30 = F_94 ( V_18 ,
& V_129 . V_111 ) )
|| ( V_30 = F_94 ( V_18 ,
& V_130 . V_111 ) )
|| ( V_30 = F_94 ( V_18 ,
& V_131 . V_111 ) )
|| ( V_30 = F_94 ( V_18 ,
& V_132 . V_111 ) )
|| ( V_30 = F_94 ( V_18 ,
& V_133 . V_111 ) )
|| ( V_30 = F_94 ( V_18 ,
& V_134 . V_111 ) )
|| ( V_30 = F_94 ( V_18 ,
& V_135 . V_111 ) )
|| ( V_30 = F_94 ( V_18 ,
& V_136 . V_111 ) )
|| ( V_30 = F_94 ( V_18 ,
& V_137 . V_111 ) )
|| ( V_30 = F_94 ( V_18 ,
& V_138 . V_111 ) )
|| ( V_30 = F_94 ( V_18 ,
& V_139 . V_111 ) ) )
goto V_123;
if ( V_25 -> type != V_85 && V_25 -> V_46 != 0xff ) {
V_25 -> V_47 = F_95 () ;
if ( ( V_30 = F_94 ( V_18 , & V_140 ) )
|| ( V_30 = F_94 ( V_18 , & V_141 ) ) )
goto V_123;
}
if ( V_25 -> type == V_34 || V_25 -> type == V_35
|| V_25 -> type == V_36 ) {
V_30 = F_94 ( V_18 , & V_142 . V_111 ) ;
if ( V_30 )
goto V_123;
}
if ( V_25 -> type == V_35 || V_25 -> type == V_36 )
if ( ( V_30 = F_94 ( V_18 ,
& V_121 . V_111 ) )
|| ( V_30 = F_94 ( V_18 ,
& V_122 . V_111 ) )
|| ( V_30 = F_94 ( V_18 ,
& V_143 . V_111 ) ) )
goto V_123;
if ( V_25 -> type != V_64 )
if ( ( V_30 = F_94 ( V_18 ,
& V_144 . V_111 ) )
|| ( V_30 = F_94 ( V_18 ,
& V_145 . V_111 ) ) )
goto V_123;
if ( V_25 -> type == V_34 || V_25 -> type == V_35
|| V_25 -> type == V_36 ) {
V_30 = F_94 ( V_18 ,
& V_146 . V_111 ) ;
if ( V_30 )
goto V_123;
}
V_25 -> V_147 = F_96 ( V_18 ) ;
if ( F_97 ( V_25 -> V_147 ) ) {
V_30 = F_98 ( V_25 -> V_147 ) ;
goto V_123;
}
return 0 ;
V_123:
F_99 ( & V_18 -> V_107 , & V_108 ) ;
F_99 ( & V_18 -> V_107 , & V_148 ) ;
V_109:
F_90 ( V_94 , NULL ) ;
F_100 ( V_25 ) ;
V_105:
F_101 ( V_97 -> V_99 , V_100 ) ;
V_102:
return V_30 ;
}
static int T_9 F_102 ( struct V_93 * V_94 )
{
struct V_24 * V_25 = F_103 ( V_94 ) ;
struct V_96 * V_97 ;
F_104 ( V_25 -> V_147 ) ;
F_99 ( & V_94 -> V_18 . V_107 , & V_108 ) ;
F_99 ( & V_94 -> V_18 . V_107 , & V_148 ) ;
F_90 ( V_94 , NULL ) ;
F_100 ( V_25 ) ;
V_97 = F_86 ( V_94 , V_98 , 0 ) ;
F_101 ( V_97 -> V_99 , V_100 ) ;
return 0 ;
}
static inline void F_105 ( struct V_24 * V_25 , T_4 V_3 )
{
if ( ( V_3 & 0x00f0 ) == 0x50 ) {
F_106 ( V_149 , V_25 -> V_76 + V_150 ) ;
F_106 ( V_3 >> 8 , V_25 -> V_76 + V_151 ) ;
}
}
static inline void F_107 ( struct V_24 * V_25 , T_4 V_3 )
{
if ( V_3 & 0xff00 ) {
F_106 ( V_149 , V_25 -> V_76 + V_150 ) ;
F_106 ( 0 , V_25 -> V_76 + V_151 ) ;
}
}
static int F_65 ( struct V_24 * V_25 , T_4 V_3 )
{
int V_97 , V_152 ;
F_26 ( & V_25 -> V_106 ) ;
V_152 = ( ( ( V_3 & 0xff00 ) == 0x100 )
|| ( ( V_3 & 0xff00 ) == 0x200 ) )
&& ( ( ( V_3 & 0x00ff ) == 0x50 )
|| ( ( V_3 & 0x00ff ) == 0x53 )
|| ( ( V_3 & 0x00ff ) == 0x55 ) ) ;
F_105 ( V_25 , V_3 ) ;
F_106 ( V_3 & 0xff , V_25 -> V_76 + V_150 ) ;
V_97 = F_108 ( V_25 -> V_76 + V_151 ) ;
if ( V_152 ) {
F_106 ( ( V_3 & 0xff ) + 1 ,
V_25 -> V_76 + V_150 ) ;
V_97 =
( V_97 << 8 ) + F_108 ( V_25 -> V_76 +
V_151 ) ;
}
F_107 ( V_25 , V_3 ) ;
F_30 ( & V_25 -> V_106 ) ;
return V_97 ;
}
static int T_8 F_109 ( struct V_93 * V_94 )
{
struct V_1 * V_77 = V_94 -> V_18 . V_95 ;
int V_97 = 0xff , V_153 ;
F_6 ( V_77 ) ;
F_5 ( V_77 , V_154 ) ;
if ( ! ( F_3 ( V_77 , V_155 ) & ( 1 << 3 ) ) ) {
F_110 ( & V_94 -> V_18 , L_23 ) ;
goto exit;
}
V_153 = F_3 ( V_77 , V_156 ) & 0x3f ;
if ( ( V_153 & 0x1f ) != 0x1f ) {
F_110 ( & V_94 -> V_18 , L_24
L_25 ) ;
goto exit;
}
F_111 ( & V_94 -> V_18 , L_26 ) ;
V_97 = F_3 ( V_77 , V_157 ) & V_153 ;
exit:
F_7 ( V_77 ) ;
return V_97 ;
}
static int T_8 F_112 ( struct V_93 * V_94 )
{
struct V_1 * V_77 = V_94 -> V_18 . V_95 ;
int V_97 = 0xff ;
F_6 ( V_77 ) ;
F_5 ( V_77 , V_89 ) ;
if ( ! ( F_3 ( V_77 , V_158 ) & ( 1 << 2 ) ) ) {
F_110 ( & V_94 -> V_18 , L_27 ) ;
goto exit;
}
if ( ! ( F_3 ( V_77 , V_159 ) & ( 1 << 4 ) ) ) {
F_110 ( & V_94 -> V_18 , L_28
L_29 ) ;
goto exit;
}
V_97 = F_3 ( V_77 , V_160 ) & 0x3f ;
exit:
F_7 ( V_77 ) ;
return V_97 ;
}
static int F_28 ( struct V_24 * V_25 , T_4 V_3 , T_4 V_161 )
{
int V_152 ;
F_26 ( & V_25 -> V_106 ) ;
V_152 = ( ( ( V_3 & 0xff00 ) == 0x100 )
|| ( ( V_3 & 0xff00 ) == 0x200 ) )
&& ( ( ( V_3 & 0x00ff ) == 0x53 )
|| ( ( V_3 & 0x00ff ) == 0x55 ) ) ;
F_105 ( V_25 , V_3 ) ;
F_106 ( V_3 & 0xff , V_25 -> V_76 + V_150 ) ;
if ( V_152 ) {
F_106 ( V_161 >> 8 ,
V_25 -> V_76 + V_151 ) ;
F_106 ( ( V_3 & 0xff ) + 1 ,
V_25 -> V_76 + V_150 ) ;
}
F_106 ( V_161 & 0xff ,
V_25 -> V_76 + V_151 ) ;
F_107 ( V_25 , V_3 ) ;
F_30 ( & V_25 -> V_106 ) ;
return 0 ;
}
static void T_8 F_91 ( struct V_93 * V_94 )
{
struct V_24 * V_25 = F_103 ( V_94 ) ;
int V_16 ;
enum V_162 type = V_25 -> type ;
T_1 V_41 ;
F_28 ( V_25 , V_163 , 0x89 ) ;
F_28 ( V_25 , V_164 , V_165 ) ;
if ( type == V_64 || type == V_35 ) {
int V_166 = F_65 ( V_25 , V_58 ) ;
int V_167 = F_65 ( V_25 , V_168 ) ;
V_25 -> V_46 = ( V_166 & 0x0f ) | ( ( V_167 & 0x01 ) << 4 ) ;
} else if ( type == V_34 ) {
V_25 -> V_46 = F_109 ( V_94 ) ;
} else if ( type == V_36 ) {
V_25 -> V_46 = F_112 ( V_94 ) ;
}
if ( type == V_34 || type == V_35 || type == V_36 ) {
V_25 -> V_33 =
F_65 ( V_25 , V_169 ) ;
}
V_41 = F_65 ( V_25 , V_70 ) ;
for ( V_16 = 1 ; V_16 <= 3 ; V_16 ++ ) {
if ( ! ( V_41 & V_71 [ V_16 - 1 ] ) ) {
V_25 -> V_69 [ V_16 - 1 ] = 4 ;
} else {
if ( F_65
( V_25 ,
V_72 ) & V_73 [ V_16 - 1 ] )
V_25 -> V_69 [ V_16 - 1 ] = 1 ;
else
V_25 -> V_69 [ V_16 - 1 ] = 2 ;
}
if ( ( type == V_85 ) && ( V_16 == 2 ) )
break;
}
if( V_170 ) {
V_41 = F_65 ( V_25 , V_171 ) ;
if ( V_41 & 0x01 ) {
F_78 ( & V_94 -> V_18 , L_30
L_31 ) ;
F_28 ( V_25 , V_171 ,
V_41 & 0xfe ) ;
}
if ( type != V_85 ) {
V_41 = F_65 ( V_25 ,
V_172 ) ;
if ( V_41 & 0x01 ) {
F_78 ( & V_94 -> V_18 , L_32
L_33 ) ;
F_28 ( V_25 ,
V_172 , V_41 & 0xfe ) ;
}
}
}
F_28 ( V_25 , V_173 ,
( F_65 ( V_25 ,
V_173 ) & 0xf7 )
| 0x01 ) ;
V_41 = F_65 ( V_25 , V_59 ) ;
if ( ! ( V_41 & 0x01 ) )
F_28 ( V_25 , V_59 , V_41 | 0x01 ) ;
}
static void F_92 ( struct V_24 * V_25 )
{
int V_3 ;
V_3 = F_65 ( V_25 , V_58 ) ;
V_25 -> V_39 [ 0 ] = ( V_3 >> 4 ) & 0x03 ;
V_25 -> V_39 [ 1 ] = ( V_3 >> 6 ) & 0x03 ;
if ( V_25 -> type != V_85 ) {
V_25 -> V_39 [ 2 ] = ( F_65 ( V_25 ,
V_57 ) >> 6 ) & 0x03 ;
}
V_3 = F_65 ( V_25 , V_59 ) ;
V_25 -> V_39 [ 0 ] |= ( V_3 >> 3 ) & 0x04 ;
V_25 -> V_39 [ 1 ] |= ( V_3 >> 4 ) & 0x04 ;
if ( V_25 -> type != V_85 )
V_25 -> V_39 [ 2 ] |= ( V_3 >> 5 ) & 0x04 ;
}
static struct V_24 * F_19 ( struct V_17 * V_18 )
{
struct V_24 * V_25 = F_24 ( V_18 ) ;
int V_16 , V_174 = ( V_25 -> type == V_85 ) ? 2 : 3 ;
int V_175 = ( V_25 -> type == V_85 ) ? 2 : 3 ;
F_26 ( & V_25 -> V_31 ) ;
if ( F_113 ( V_176 , V_25 -> V_177 + V_178 + V_178 / 2 )
|| ! V_25 -> V_179 ) {
for ( V_16 = 0 ; V_16 <= 8 ; V_16 ++ ) {
if ( ( ( V_25 -> type == V_85 ) && ( V_16 == 1 ) ) ||
( ( V_25 -> type != V_64 && V_25 -> type != V_85 )
&& ( V_16 == 5 || V_16 == 6 ) ) )
continue;
V_25 -> V_26 [ V_16 ] =
F_65 ( V_25 , F_114 ( V_16 ) ) ;
V_25 -> V_27 [ V_16 ] =
F_65 ( V_25 ,
F_29 ( V_16 ) ) ;
V_25 -> V_28 [ V_16 ] =
F_65 ( V_25 ,
F_32 ( V_16 ) ) ;
}
for ( V_16 = 0 ; V_16 <= 2 ; V_16 ++ ) {
V_25 -> V_38 [ V_16 ] =
F_65 ( V_25 , F_115 ( V_16 ) ) ;
V_25 -> V_40 [ V_16 ] =
F_65 ( V_25 ,
F_45 ( V_16 ) ) ;
}
for ( V_16 = 0 ; V_16 <= 2 ; V_16 ++ ) {
T_1 V_41 = F_65 ( V_25 ,
F_71 ( V_25 -> type , V_16 ) ) ;
if ( V_25 -> type == V_34 )
V_41 &= 0xf0 ;
V_25 -> V_60 [ V_16 ] = V_41 ;
if ( V_16 == 1 &&
( V_25 -> type == V_64 || V_25 -> type == V_85 ) )
break;
}
if ( V_25 -> type == V_64 ) {
T_1 V_41 = F_65 ( V_25 ,
V_67 ) ;
V_25 -> V_65 [ 0 ] = V_41 & 0x07 ;
V_25 -> V_65 [ 1 ] = ( V_41 >> 4 ) & 0x07 ;
} else if ( V_25 -> type != V_34 ) {
for ( V_16 = 1 ; V_16 <= 3 ; V_16 ++ ) {
V_25 -> V_65 [ V_16 - 1 ] =
F_65 ( V_25 ,
V_68 [ V_16 - 1 ] ) ;
if ( V_16 == 2 && ( V_25 -> type == V_85 ) )
break;
}
}
if ( V_25 -> type != V_64 ) {
for ( V_16 = 0 ; V_16 < V_175 ; V_16 ++ ) {
T_1 V_41 = F_65 ( V_25 ,
V_62 [ V_16 ] ) ;
V_25 -> V_61 [ V_16 ] =
( ( V_41 >> V_63 [ V_16 ] )
& 0x03 ) + 1 ;
}
}
for ( V_16 = 0 ; V_16 < V_174 ; V_16 ++ ) {
V_25 -> V_9 [ V_16 ] = F_65 (
V_25 , V_180 [ V_16 ] ) ;
V_25 -> V_42 [ V_16 ] = F_65 (
V_25 , V_44 [ V_16 ] ) ;
V_25 -> V_43 [ V_16 ] = F_65 (
V_25 , V_45 [ V_16 ] ) ;
}
F_92 ( V_25 ) ;
V_25 -> V_48 =
F_65 ( V_25 , V_181 ) |
( F_65 ( V_25 , V_182 ) << 8 ) |
( F_65 ( V_25 , V_183 ) << 16 ) ;
V_16 = F_65 ( V_25 , V_53 ) ;
V_25 -> V_50 = ( V_16 << 8 ) |
F_65 ( V_25 , V_51 ) |
F_65 ( V_25 , V_52 ) << 16 ;
V_25 -> V_177 = V_176 ;
V_25 -> V_179 = 1 ;
}
F_30 ( & V_25 -> V_31 ) ;
return V_25 ;
}
static int T_6 F_116 ( unsigned short V_184 ,
const struct V_1 * V_77 )
{
struct V_96 V_97 = {
. V_99 = V_184 + V_185 ,
. V_186 = V_184 + V_185 + V_100 - 1 ,
. V_75 = V_88 ,
. V_187 = V_98 ,
} ;
int V_30 ;
V_30 = F_117 ( & V_97 ) ;
if ( V_30 )
goto exit;
V_94 = F_118 ( V_88 , V_184 ) ;
if ( ! V_94 ) {
V_30 = - V_104 ;
F_119 ( L_34 ) ;
goto exit;
}
V_30 = F_120 ( V_94 , & V_97 , 1 ) ;
if ( V_30 ) {
F_119 ( L_35 , V_30 ) ;
goto V_188;
}
V_30 = F_121 ( V_94 , V_77 ,
sizeof( struct V_1 ) ) ;
if ( V_30 ) {
F_119 ( L_36 ) ;
goto V_188;
}
V_30 = F_122 ( V_94 ) ;
if ( V_30 ) {
F_119 ( L_37 , V_30 ) ;
goto V_188;
}
return 0 ;
V_188:
F_123 ( V_94 ) ;
exit:
return V_30 ;
}
static int T_6 F_124 ( void )
{
int V_30 ;
unsigned short V_184 ;
struct V_1 V_77 ;
if ( F_81 ( 0x2e , & V_184 , & V_77 )
&& F_81 ( 0x4e , & V_184 , & V_77 ) )
return - V_78 ;
V_30 = F_125 ( & V_189 ) ;
if ( V_30 )
goto exit;
V_30 = F_116 ( V_184 , & V_77 ) ;
if ( V_30 )
goto V_190;
return 0 ;
V_190:
F_126 ( & V_189 ) ;
exit:
return V_30 ;
}
static void T_10 F_127 ( void )
{
F_128 ( V_94 ) ;
F_126 ( & V_189 ) ;
}
