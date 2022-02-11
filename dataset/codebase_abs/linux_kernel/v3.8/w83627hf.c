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
static int F_17 ( struct V_17 * V_18 )
{
struct V_19 * V_20 = F_18 ( V_18 ) ;
F_19 ( & V_20 -> V_21 ) ;
V_20 -> V_22 = F_20 ( V_20 , V_23 ) ;
V_20 -> V_24 = F_20 ( V_20 , V_25 ) ;
F_21 ( & V_20 -> V_21 ) ;
return 0 ;
}
static int F_22 ( struct V_17 * V_18 )
{
struct V_19 * V_20 = F_23 ( V_18 ) ;
int V_16 , V_26 = ( V_20 -> type == V_27 ) ? 2 : 3 ;
F_19 ( & V_20 -> V_21 ) ;
for ( V_16 = 0 ; V_16 <= 8 ; V_16 ++ ) {
if ( ( ( V_20 -> type == V_27 ) && ( V_16 == 1 ) ) ||
( ( V_20 -> type != V_28 && V_20 -> type != V_27 )
&& ( V_16 == 5 || V_16 == 6 ) ) )
continue;
F_24 ( V_20 , F_25 ( V_16 ) ,
V_20 -> V_29 [ V_16 ] ) ;
F_24 ( V_20 , F_26 ( V_16 ) ,
V_20 -> V_30 [ V_16 ] ) ;
}
for ( V_16 = 0 ; V_16 <= 2 ; V_16 ++ )
F_24 ( V_20 , F_27 ( V_16 ) ,
V_20 -> V_31 [ V_16 ] ) ;
for ( V_16 = 0 ; V_16 < V_26 ; V_16 ++ ) {
F_24 ( V_20 , V_32 [ V_16 ] ,
V_20 -> V_33 [ V_16 ] ) ;
F_24 ( V_20 , V_34 [ V_16 ] ,
V_20 -> V_35 [ V_16 ] ) ;
}
if ( V_20 -> type == V_36 || V_20 -> type == V_37 ||
V_20 -> type == V_38 )
F_24 ( V_20 , V_39 ,
V_20 -> V_40 ) ;
F_24 ( V_20 , V_23 , V_20 -> V_22 ) ;
F_24 ( V_20 , V_25 , V_20 -> V_24 ) ;
V_20 -> V_41 = 0 ;
F_21 ( & V_20 -> V_21 ) ;
return 0 ;
}
static T_2
F_28 ( struct V_17 * V_18 , struct V_42 * V_43 , char * V_44 )
{
int V_45 = F_29 ( V_43 ) -> V_46 ;
struct V_19 * V_20 = F_18 ( V_18 ) ;
return sprintf ( V_44 , L_1 , ( long ) F_30 ( V_20 -> V_47 [ V_45 ] ) ) ;
}
static T_2
F_31 ( struct V_17 * V_18 , struct V_42 * V_43 , char * V_44 )
{
int V_45 = F_29 ( V_43 ) -> V_46 ;
struct V_19 * V_20 = F_18 ( V_18 ) ;
return sprintf ( V_44 , L_1 , ( long ) F_30 ( V_20 -> V_30 [ V_45 ] ) ) ;
}
static T_2
F_32 ( struct V_17 * V_18 , struct V_42 * V_43 , char * V_44 )
{
int V_45 = F_29 ( V_43 ) -> V_46 ;
struct V_19 * V_20 = F_18 ( V_18 ) ;
return sprintf ( V_44 , L_1 , ( long ) F_30 ( V_20 -> V_29 [ V_45 ] ) ) ;
}
static T_2
F_33 ( struct V_17 * V_18 , struct V_42 * V_43 ,
const char * V_44 , T_3 V_48 )
{
int V_45 = F_29 ( V_43 ) -> V_46 ;
struct V_19 * V_20 = F_23 ( V_18 ) ;
long V_4 ;
int V_49 ;
V_49 = F_34 ( V_44 , 10 , & V_4 ) ;
if ( V_49 )
return V_49 ;
F_19 ( & V_20 -> V_21 ) ;
V_20 -> V_30 [ V_45 ] = F_35 ( V_4 ) ;
F_24 ( V_20 , F_26 ( V_45 ) , V_20 -> V_30 [ V_45 ] ) ;
F_21 ( & V_20 -> V_21 ) ;
return V_48 ;
}
static T_2
F_36 ( struct V_17 * V_18 , struct V_42 * V_43 ,
const char * V_44 , T_3 V_48 )
{
int V_45 = F_29 ( V_43 ) -> V_46 ;
struct V_19 * V_20 = F_23 ( V_18 ) ;
long V_4 ;
int V_49 ;
V_49 = F_34 ( V_44 , 10 , & V_4 ) ;
if ( V_49 )
return V_49 ;
F_19 ( & V_20 -> V_21 ) ;
V_20 -> V_29 [ V_45 ] = F_35 ( V_4 ) ;
F_24 ( V_20 , F_25 ( V_45 ) , V_20 -> V_29 [ V_45 ] ) ;
F_21 ( & V_20 -> V_21 ) ;
return V_48 ;
}
static T_2 F_37 ( struct V_19 * V_20 , char * V_44 , T_1 V_3 )
{
long V_50 ;
if ( ( V_20 -> V_40 & 0x01 ) &&
( V_36 == V_20 -> type || V_37 == V_20 -> type
|| V_38 == V_20 -> type ) )
V_50 = ( long ) ( ( V_3 * 488 + 70000 + 50 ) / 100 ) ;
else
V_50 = ( long ) F_30 ( V_3 ) ;
return sprintf ( V_44 , L_1 , V_50 ) ;
}
static T_2 F_38 ( struct V_17 * V_18 , struct V_42 * V_51 , char * V_44 )
{
struct V_19 * V_20 = F_18 ( V_18 ) ;
return F_37 ( V_20 , V_44 , V_20 -> V_47 [ 0 ] ) ;
}
static T_2 F_39 ( struct V_17 * V_18 , struct V_42 * V_51 , char * V_44 )
{
struct V_19 * V_20 = F_18 ( V_18 ) ;
return F_37 ( V_20 , V_44 , V_20 -> V_30 [ 0 ] ) ;
}
static T_2 F_40 ( struct V_17 * V_18 , struct V_42 * V_51 , char * V_44 )
{
struct V_19 * V_20 = F_18 ( V_18 ) ;
return F_37 ( V_20 , V_44 , V_20 -> V_29 [ 0 ] ) ;
}
static T_2 F_41 ( struct V_17 * V_18 , struct V_42 * V_51 ,
const char * V_44 , T_3 V_48 )
{
struct V_19 * V_20 = F_23 ( V_18 ) ;
unsigned long V_4 ;
int V_49 ;
V_49 = F_42 ( V_44 , 10 , & V_4 ) ;
if ( V_49 )
return V_49 ;
F_19 ( & V_20 -> V_21 ) ;
if ( ( V_20 -> V_40 & 0x01 ) &&
( V_36 == V_20 -> type || V_37 == V_20 -> type
|| V_38 == V_20 -> type ) )
V_20 -> V_30 [ 0 ] =
F_9 ( ( ( V_4 * 100 ) - 70000 + 244 ) / 488 , 0 ,
255 ) ;
else
V_20 -> V_30 [ 0 ] = F_35 ( V_4 ) ;
F_24 ( V_20 , F_26 ( 0 ) , V_20 -> V_30 [ 0 ] ) ;
F_21 ( & V_20 -> V_21 ) ;
return V_48 ;
}
static T_2 F_43 ( struct V_17 * V_18 , struct V_42 * V_51 ,
const char * V_44 , T_3 V_48 )
{
struct V_19 * V_20 = F_23 ( V_18 ) ;
unsigned long V_4 ;
int V_49 ;
V_49 = F_42 ( V_44 , 10 , & V_4 ) ;
if ( V_49 )
return V_49 ;
F_19 ( & V_20 -> V_21 ) ;
if ( ( V_20 -> V_40 & 0x01 ) &&
( V_36 == V_20 -> type || V_37 == V_20 -> type
|| V_38 == V_20 -> type ) )
V_20 -> V_29 [ 0 ] =
F_9 ( ( ( V_4 * 100 ) - 70000 + 244 ) / 488 , 0 ,
255 ) ;
else
V_20 -> V_29 [ 0 ] = F_35 ( V_4 ) ;
F_24 ( V_20 , F_25 ( 0 ) , V_20 -> V_29 [ 0 ] ) ;
F_21 ( & V_20 -> V_21 ) ;
return V_48 ;
}
static T_2
F_44 ( struct V_17 * V_18 , struct V_42 * V_43 , char * V_44 )
{
int V_45 = F_29 ( V_43 ) -> V_46 ;
struct V_19 * V_20 = F_18 ( V_18 ) ;
return sprintf ( V_44 , L_1 , F_45 ( V_20 -> V_52 [ V_45 ] ,
( long ) F_46 ( V_20 -> V_53 [ V_45 ] ) ) ) ;
}
static T_2
F_47 ( struct V_17 * V_18 , struct V_42 * V_43 , char * V_44 )
{
int V_45 = F_29 ( V_43 ) -> V_46 ;
struct V_19 * V_20 = F_18 ( V_18 ) ;
return sprintf ( V_44 , L_1 , F_45 ( V_20 -> V_31 [ V_45 ] ,
( long ) F_46 ( V_20 -> V_53 [ V_45 ] ) ) ) ;
}
static T_2
F_48 ( struct V_17 * V_18 , struct V_42 * V_43 ,
const char * V_44 , T_3 V_48 )
{
int V_45 = F_29 ( V_43 ) -> V_46 ;
struct V_19 * V_20 = F_23 ( V_18 ) ;
unsigned long V_4 ;
int V_49 ;
V_49 = F_42 ( V_44 , 10 , & V_4 ) ;
if ( V_49 )
return V_49 ;
F_19 ( & V_20 -> V_21 ) ;
V_20 -> V_31 [ V_45 ] = F_8 ( V_4 , F_46 ( V_20 -> V_53 [ V_45 ] ) ) ;
F_24 ( V_20 , F_27 ( V_45 ) ,
V_20 -> V_31 [ V_45 ] ) ;
F_21 ( & V_20 -> V_21 ) ;
return V_48 ;
}
static T_2
F_49 ( struct V_17 * V_18 , struct V_42 * V_43 , char * V_44 )
{
int V_45 = F_29 ( V_43 ) -> V_46 ;
struct V_19 * V_20 = F_18 ( V_18 ) ;
T_4 V_54 = V_20 -> V_9 [ V_45 ] ;
return sprintf ( V_44 , L_1 , ( V_45 ) ? ( long ) F_50 ( V_54 )
: ( long ) F_11 ( V_54 ) ) ;
}
static T_2
F_51 ( struct V_17 * V_18 , struct V_42 * V_43 ,
char * V_44 )
{
int V_45 = F_29 ( V_43 ) -> V_46 ;
struct V_19 * V_20 = F_18 ( V_18 ) ;
T_4 V_54 = V_20 -> V_33 [ V_45 ] ;
return sprintf ( V_44 , L_1 , ( V_45 ) ? ( long ) F_50 ( V_54 )
: ( long ) F_11 ( V_54 ) ) ;
}
static T_2
F_52 ( struct V_17 * V_18 , struct V_42 * V_43 ,
char * V_44 )
{
int V_45 = F_29 ( V_43 ) -> V_46 ;
struct V_19 * V_20 = F_18 ( V_18 ) ;
T_4 V_54 = V_20 -> V_35 [ V_45 ] ;
return sprintf ( V_44 , L_1 , ( V_45 ) ? ( long ) F_50 ( V_54 )
: ( long ) F_11 ( V_54 ) ) ;
}
static T_2
F_53 ( struct V_17 * V_18 , struct V_42 * V_43 ,
const char * V_44 , T_3 V_48 )
{
int V_45 = F_29 ( V_43 ) -> V_46 ;
struct V_19 * V_20 = F_23 ( V_18 ) ;
T_4 V_54 ;
long V_4 ;
int V_49 ;
V_49 = F_34 ( V_44 , 10 , & V_4 ) ;
if ( V_49 )
return V_49 ;
V_54 = ( V_45 ) ? F_54 ( V_4 ) : F_10 ( V_4 ) ;
F_19 ( & V_20 -> V_21 ) ;
V_20 -> V_33 [ V_45 ] = V_54 ;
F_24 ( V_20 , V_32 [ V_45 ] , V_54 ) ;
F_21 ( & V_20 -> V_21 ) ;
return V_48 ;
}
static T_2
F_55 ( struct V_17 * V_18 , struct V_42 * V_43 ,
const char * V_44 , T_3 V_48 )
{
int V_45 = F_29 ( V_43 ) -> V_46 ;
struct V_19 * V_20 = F_23 ( V_18 ) ;
T_4 V_54 ;
long V_4 ;
int V_49 ;
V_49 = F_34 ( V_44 , 10 , & V_4 ) ;
if ( V_49 )
return V_49 ;
V_54 = ( V_45 ) ? F_54 ( V_4 ) : F_10 ( V_4 ) ;
F_19 ( & V_20 -> V_21 ) ;
V_20 -> V_35 [ V_45 ] = V_54 ;
F_24 ( V_20 , V_34 [ V_45 ] , V_54 ) ;
F_21 ( & V_20 -> V_21 ) ;
return V_48 ;
}
static T_2
F_56 ( struct V_17 * V_18 , struct V_42 * V_51 , char * V_44 )
{
struct V_19 * V_20 = F_18 ( V_18 ) ;
return sprintf ( V_44 , L_1 , ( long ) F_57 ( V_20 -> V_55 , V_20 -> V_56 ) ) ;
}
static T_2
F_58 ( struct V_17 * V_18 , struct V_42 * V_51 , char * V_44 )
{
struct V_19 * V_20 = F_23 ( V_18 ) ;
return sprintf ( V_44 , L_1 , ( long ) V_20 -> V_56 ) ;
}
static T_2
F_59 ( struct V_17 * V_18 , struct V_42 * V_51 , const char * V_44 , T_3 V_48 )
{
struct V_19 * V_20 = F_23 ( V_18 ) ;
unsigned long V_4 ;
int V_49 ;
V_49 = F_42 ( V_44 , 10 , & V_4 ) ;
if ( V_49 )
return V_49 ;
V_20 -> V_56 = V_4 ;
return V_48 ;
}
static T_2
F_60 ( struct V_17 * V_18 , struct V_42 * V_51 , char * V_44 )
{
struct V_19 * V_20 = F_18 ( V_18 ) ;
return sprintf ( V_44 , L_1 , ( long ) V_20 -> V_57 ) ;
}
static T_2
F_61 ( struct V_17 * V_18 , struct V_42 * V_51 , char * V_44 )
{
struct V_19 * V_20 = F_18 ( V_18 ) ;
int V_58 = F_29 ( V_51 ) -> V_46 ;
return sprintf ( V_44 , L_2 , ( V_20 -> V_57 >> V_58 ) & 1 ) ;
}
static T_2
F_62 ( struct V_17 * V_18 , struct V_42 * V_51 , char * V_44 )
{
struct V_19 * V_20 = F_18 ( V_18 ) ;
return sprintf ( V_44 , L_1 ,
( long ) F_63 ( V_20 -> V_59 ) ) ;
}
static T_2
F_64 ( struct V_17 * V_18 , struct V_42 * V_51 ,
const char * V_44 , T_3 V_48 )
{
struct V_19 * V_20 = F_23 ( V_18 ) ;
unsigned long V_4 ;
int V_49 ;
V_49 = F_42 ( V_44 , 10 , & V_4 ) ;
if ( V_49 )
return V_49 ;
F_19 ( & V_20 -> V_21 ) ;
V_20 -> V_59 = ( V_20 -> V_59 & 0x8000 )
| F_65 ( V_4 ) ;
F_24 ( V_20 , V_60 ,
V_20 -> V_59 & 0xff ) ;
F_24 ( V_20 , V_61 ,
( ( V_20 -> V_59 ) >> 16 ) & 0xff ) ;
F_24 ( V_20 , V_62 ,
( V_20 -> V_59 >> 8 ) & 0xff ) ;
F_21 ( & V_20 -> V_21 ) ;
return V_48 ;
}
static T_2
F_66 ( struct V_17 * V_18 , struct V_42 * V_51 , char * V_44 )
{
struct V_19 * V_20 = F_18 ( V_18 ) ;
int V_58 = F_29 ( V_51 ) -> V_46 ;
return sprintf ( V_44 , L_2 , ( V_20 -> V_59 >> V_58 ) & 1 ) ;
}
static T_2
F_67 ( struct V_17 * V_18 , struct V_42 * V_51 ,
const char * V_44 , T_3 V_48 )
{
struct V_19 * V_20 = F_23 ( V_18 ) ;
int V_58 = F_29 ( V_51 ) -> V_46 ;
T_1 V_3 ;
unsigned long V_63 ;
int V_49 ;
V_49 = F_42 ( V_44 , 10 , & V_63 ) ;
if ( V_49 )
return V_49 ;
if ( V_63 & ~ 1 )
return - V_64 ;
F_19 ( & V_20 -> V_21 ) ;
if ( V_63 )
V_20 -> V_59 |= ( 1 << V_58 ) ;
else
V_20 -> V_59 &= ~ ( 1 << V_58 ) ;
if ( V_58 < 8 ) {
V_3 = F_20 ( V_20 , V_60 ) ;
if ( V_63 )
V_3 |= ( 1 << V_58 ) ;
else
V_3 &= ~ ( 1 << V_58 ) ;
F_24 ( V_20 , V_60 , V_3 ) ;
} else if ( V_58 < 16 ) {
V_3 = F_20 ( V_20 , V_62 ) ;
if ( V_63 )
V_3 |= ( 1 << ( V_58 - 8 ) ) ;
else
V_3 &= ~ ( 1 << ( V_58 - 8 ) ) ;
F_24 ( V_20 , V_62 , V_3 ) ;
} else {
V_3 = F_20 ( V_20 , V_61 ) ;
if ( V_63 )
V_3 |= ( 1 << ( V_58 - 16 ) ) ;
else
V_3 &= ~ ( 1 << ( V_58 - 16 ) ) ;
F_24 ( V_20 , V_61 , V_3 ) ;
}
F_21 ( & V_20 -> V_21 ) ;
return V_48 ;
}
static T_2
F_68 ( struct V_17 * V_18 , struct V_42 * V_43 , char * V_44 )
{
int V_45 = F_29 ( V_43 ) -> V_46 ;
struct V_19 * V_20 = F_18 ( V_18 ) ;
return sprintf ( V_44 , L_1 ,
( long ) F_46 ( V_20 -> V_53 [ V_45 ] ) ) ;
}
static T_2
F_69 ( struct V_17 * V_18 , struct V_42 * V_43 ,
const char * V_44 , T_3 V_48 )
{
int V_45 = F_29 ( V_43 ) -> V_46 ;
struct V_19 * V_20 = F_23 ( V_18 ) ;
unsigned long V_65 ;
T_1 V_3 ;
unsigned long V_4 ;
int V_49 ;
V_49 = F_42 ( V_44 , 10 , & V_4 ) ;
if ( V_49 )
return V_49 ;
F_19 ( & V_20 -> V_21 ) ;
V_65 = F_45 ( V_20 -> V_31 [ V_45 ] ,
F_46 ( V_20 -> V_53 [ V_45 ] ) ) ;
V_20 -> V_53 [ V_45 ] = F_16 ( V_4 ) ;
V_3 = ( F_20 ( V_20 , V_45 == 2 ? V_66 : V_67 )
& ( V_45 == 0 ? 0xcf : 0x3f ) )
| ( ( V_20 -> V_53 [ V_45 ] & 0x03 ) << ( V_45 == 0 ? 4 : 6 ) ) ;
F_24 ( V_20 , V_45 == 2 ? V_66 : V_67 , V_3 ) ;
V_3 = ( F_20 ( V_20 , V_68 )
& ~ ( 1 << ( 5 + V_45 ) ) )
| ( ( V_20 -> V_53 [ V_45 ] & 0x04 ) << ( 3 + V_45 ) ) ;
F_24 ( V_20 , V_68 , V_3 ) ;
V_20 -> V_31 [ V_45 ] = F_8 ( V_65 , F_46 ( V_20 -> V_53 [ V_45 ] ) ) ;
F_24 ( V_20 , F_27 ( V_45 ) , V_20 -> V_31 [ V_45 ] ) ;
F_21 ( & V_20 -> V_21 ) ;
return V_48 ;
}
static T_2
F_70 ( struct V_17 * V_18 , struct V_42 * V_43 , char * V_44 )
{
int V_45 = F_29 ( V_43 ) -> V_46 ;
struct V_19 * V_20 = F_18 ( V_18 ) ;
return sprintf ( V_44 , L_1 , ( long ) V_20 -> V_69 [ V_45 ] ) ;
}
static T_2
F_71 ( struct V_17 * V_18 , struct V_42 * V_43 ,
const char * V_44 , T_3 V_48 )
{
int V_45 = F_29 ( V_43 ) -> V_46 ;
struct V_19 * V_20 = F_23 ( V_18 ) ;
unsigned long V_4 ;
int V_49 ;
V_49 = F_42 ( V_44 , 10 , & V_4 ) ;
if ( V_49 )
return V_49 ;
F_19 ( & V_20 -> V_21 ) ;
if ( V_20 -> type == V_36 ) {
V_20 -> V_69 [ V_45 ] = F_72 ( V_4 ) & 0xf0 ;
F_24 ( V_20 ,
F_73 ( V_20 -> type , V_45 ) ,
V_20 -> V_69 [ V_45 ] |
( F_20 ( V_20 ,
F_73 ( V_20 -> type , V_45 ) ) & 0x0f ) ) ;
} else {
V_20 -> V_69 [ V_45 ] = F_72 ( V_4 ) ;
F_24 ( V_20 ,
F_73 ( V_20 -> type , V_45 ) ,
V_20 -> V_69 [ V_45 ] ) ;
}
F_21 ( & V_20 -> V_21 ) ;
return V_48 ;
}
static T_2
F_74 ( struct V_17 * V_18 , struct V_42 * V_43 , char * V_44 )
{
int V_45 = F_29 ( V_43 ) -> V_46 ;
struct V_19 * V_20 = F_18 ( V_18 ) ;
return sprintf ( V_44 , L_3 , V_20 -> V_70 [ V_45 ] ) ;
}
static T_2
F_75 ( struct V_17 * V_18 , struct V_42 * V_43 ,
const char * V_44 , T_3 V_48 )
{
int V_45 = F_29 ( V_43 ) -> V_46 ;
struct V_19 * V_20 = F_23 ( V_18 ) ;
T_1 V_3 ;
unsigned long V_4 ;
int V_49 ;
V_49 = F_42 ( V_44 , 10 , & V_4 ) ;
if ( V_49 )
return V_49 ;
if ( ! V_4 || V_4 > 3 )
return - V_64 ;
F_19 ( & V_20 -> V_21 ) ;
V_20 -> V_70 [ V_45 ] = V_4 ;
V_3 = F_20 ( V_20 , V_71 [ V_45 ] ) ;
V_3 &= ~ ( 0x03 << V_72 [ V_45 ] ) ;
V_3 |= ( V_4 - 1 ) << V_72 [ V_45 ] ;
F_24 ( V_20 , V_71 [ V_45 ] , V_3 ) ;
F_21 ( & V_20 -> V_21 ) ;
return V_48 ;
}
static T_2
F_76 ( struct V_17 * V_18 , struct V_42 * V_43 , char * V_44 )
{
int V_45 = F_29 ( V_43 ) -> V_46 ;
struct V_19 * V_20 = F_18 ( V_18 ) ;
if ( V_20 -> type == V_28 )
return sprintf ( V_44 , L_1 ,
F_12 ( V_20 -> V_73 [ V_45 ] ) ) ;
else
return sprintf ( V_44 , L_1 ,
F_14 ( V_20 -> V_73 [ V_45 ] ) ) ;
}
static T_2
F_77 ( struct V_17 * V_18 , struct V_42 * V_43 ,
const char * V_44 , T_3 V_48 )
{
int V_45 = F_29 ( V_43 ) -> V_46 ;
struct V_19 * V_20 = F_23 ( V_18 ) ;
static const T_1 V_74 [] = { 0xF8 , 0x8F } ;
unsigned long V_4 ;
int V_49 ;
V_49 = F_42 ( V_44 , 10 , & V_4 ) ;
if ( V_49 )
return V_49 ;
F_19 ( & V_20 -> V_21 ) ;
if ( V_20 -> type == V_28 ) {
V_20 -> V_73 [ V_45 ] = F_13 ( V_4 ) ;
F_24 ( V_20 , V_75 ,
( V_20 -> V_73 [ V_45 ] << ( V_45 * 4 ) ) |
( F_20 ( V_20 ,
V_75 ) & V_74 [ V_45 ] ) ) ;
} else {
V_20 -> V_73 [ V_45 ] = F_15 ( V_4 ) ;
F_24 ( V_20 , V_76 [ V_45 ] ,
V_20 -> V_73 [ V_45 ] ) ;
}
F_21 ( & V_20 -> V_21 ) ;
return V_48 ;
}
static T_2
F_78 ( struct V_17 * V_18 , struct V_42 * V_43 ,
char * V_44 )
{
int V_45 = F_29 ( V_43 ) -> V_46 ;
struct V_19 * V_20 = F_18 ( V_18 ) ;
return sprintf ( V_44 , L_1 , ( long ) V_20 -> V_77 [ V_45 ] ) ;
}
static T_2
F_79 ( struct V_17 * V_18 , struct V_42 * V_43 ,
const char * V_44 , T_3 V_48 )
{
int V_45 = F_29 ( V_43 ) -> V_46 ;
struct V_19 * V_20 = F_23 ( V_18 ) ;
unsigned long V_4 ;
T_5 V_54 ;
int V_49 ;
V_49 = F_42 ( V_44 , 10 , & V_4 ) ;
if ( V_49 )
return V_49 ;
F_19 ( & V_20 -> V_21 ) ;
switch ( V_4 ) {
case 1 :
V_54 = F_20 ( V_20 , V_23 ) ;
F_24 ( V_20 , V_23 ,
V_54 | V_78 [ V_45 ] ) ;
V_54 = F_20 ( V_20 , V_25 ) ;
F_24 ( V_20 , V_25 ,
V_54 | V_79 [ V_45 ] ) ;
V_20 -> V_77 [ V_45 ] = V_4 ;
break;
case 2 :
V_54 = F_20 ( V_20 , V_23 ) ;
F_24 ( V_20 , V_23 ,
V_54 | V_78 [ V_45 ] ) ;
V_54 = F_20 ( V_20 , V_25 ) ;
F_24 ( V_20 , V_25 ,
V_54 & ~ V_79 [ V_45 ] ) ;
V_20 -> V_77 [ V_45 ] = V_4 ;
break;
case V_80 :
F_80 ( V_18 , L_4
L_5 , V_80 ) ;
case 4 :
V_54 = F_20 ( V_20 , V_23 ) ;
F_24 ( V_20 , V_23 ,
V_54 & ~ V_78 [ V_45 ] ) ;
V_20 -> V_77 [ V_45 ] = V_4 ;
break;
default:
F_81 ( V_18 ,
L_6 ,
( long ) V_4 ) ;
break;
}
F_21 ( & V_20 -> V_21 ) ;
return V_48 ;
}
static T_2
F_82 ( struct V_17 * V_18 , struct V_42 * V_43 , char * V_44 )
{
struct V_19 * V_20 = F_23 ( V_18 ) ;
return sprintf ( V_44 , L_7 , V_20 -> V_81 ) ;
}
static int T_6 F_83 ( int V_5 , unsigned short * V_82 ,
struct V_1 * V_83 )
{
int V_49 = - V_84 ;
T_4 V_4 ;
static T_7 char * const V_85 [] = {
L_8 ,
L_9 ,
L_10 ,
L_11 ,
L_12 ,
} ;
V_83 -> V_5 = V_5 ;
F_6 ( V_83 ) ;
V_4 = V_86 ? V_86 : F_3 ( V_83 , V_87 ) ;
switch ( V_4 ) {
case V_88 :
V_83 -> type = V_28 ;
break;
case V_89 :
V_83 -> type = V_36 ;
break;
case V_90 :
V_83 -> type = V_27 ;
break;
case V_91 :
V_83 -> type = V_37 ;
break;
case V_92 :
V_83 -> type = V_38 ;
break;
case 0xff :
goto exit;
default:
F_84 ( V_93 L_13 , V_4 ) ;
goto exit;
}
F_5 ( V_83 , V_94 ) ;
V_4 = ( F_3 ( V_83 , V_95 ) << 8 ) |
F_3 ( V_83 , V_95 + 1 ) ;
* V_82 = V_4 & V_96 ;
if ( * V_82 == 0 ) {
F_85 ( L_14 ) ;
goto exit;
}
V_4 = F_3 ( V_83 , V_97 ) ;
if ( ! ( V_4 & 0x01 ) ) {
F_85 ( L_15 ) ;
F_1 ( V_83 , V_97 , V_4 | 0x01 ) ;
}
V_49 = 0 ;
F_86 ( V_93 L_16 ,
V_85 [ V_83 -> type ] , * V_82 ) ;
exit:
F_7 ( V_83 ) ;
return V_49 ;
}
static int F_87 ( struct V_98 * V_99 )
{
struct V_17 * V_18 = & V_99 -> V_18 ;
struct V_1 * V_83 = V_18 -> V_100 ;
struct V_19 * V_20 ;
struct V_101 * V_102 ;
int V_49 , V_16 ;
static const char * V_85 [] = {
L_17 ,
L_18 ,
L_19 ,
L_20 ,
L_21 ,
} ;
V_102 = F_88 ( V_99 , V_103 , 0 ) ;
if ( ! F_89 ( V_18 , V_102 -> V_104 , V_105 , V_93 ) ) {
F_81 ( V_18 , L_22 ,
( unsigned long ) V_102 -> V_104 ,
( unsigned long ) ( V_102 -> V_104 + V_105 - 1 ) ) ;
return - V_106 ;
}
V_20 = F_90 ( V_18 , sizeof( struct V_19 ) , V_107 ) ;
if ( ! V_20 )
return - V_108 ;
V_20 -> V_82 = V_102 -> V_104 ;
V_20 -> type = V_83 -> type ;
V_20 -> V_81 = V_85 [ V_83 -> type ] ;
F_91 ( & V_20 -> V_109 ) ;
F_91 ( & V_20 -> V_21 ) ;
F_92 ( V_99 , V_20 ) ;
F_93 ( V_99 ) ;
for ( V_16 = 0 ; V_16 <= 2 ; V_16 ++ )
V_20 -> V_31 [ V_16 ] = F_20 (
V_20 , F_27 ( V_16 ) ) ;
F_94 ( V_20 ) ;
V_49 = F_95 ( & V_18 -> V_110 , & V_111 ) ;
if ( V_49 )
return V_49 ;
if ( V_20 -> type == V_28 || V_20 -> type == V_27 )
if ( ( V_49 = F_96 ( V_18 ,
& V_112 . V_113 ) )
|| ( V_49 = F_96 ( V_18 ,
& V_114 . V_113 ) )
|| ( V_49 = F_96 ( V_18 ,
& V_115 . V_113 ) )
|| ( V_49 = F_96 ( V_18 ,
& V_116 . V_113 ) )
|| ( V_49 = F_96 ( V_18 ,
& V_117 . V_113 ) )
|| ( V_49 = F_96 ( V_18 ,
& V_118 . V_113 ) )
|| ( V_49 = F_96 ( V_18 ,
& V_119 . V_113 ) )
|| ( V_49 = F_96 ( V_18 ,
& V_120 . V_113 ) )
|| ( V_49 = F_96 ( V_18 ,
& V_121 . V_113 ) )
|| ( V_49 = F_96 ( V_18 ,
& V_122 . V_113 ) )
|| ( V_49 = F_96 ( V_18 ,
& V_123 . V_113 ) )
|| ( V_49 = F_96 ( V_18 ,
& V_124 . V_113 ) ) )
goto error;
if ( V_20 -> type != V_27 )
if ( ( V_49 = F_96 ( V_18 ,
& V_125 . V_113 ) )
|| ( V_49 = F_96 ( V_18 ,
& V_126 . V_113 ) )
|| ( V_49 = F_96 ( V_18 ,
& V_127 . V_113 ) )
|| ( V_49 = F_96 ( V_18 ,
& V_128 . V_113 ) )
|| ( V_49 = F_96 ( V_18 ,
& V_129 . V_113 ) )
|| ( V_49 = F_96 ( V_18 ,
& V_130 . V_113 ) )
|| ( V_49 = F_96 ( V_18 ,
& V_131 . V_113 ) )
|| ( V_49 = F_96 ( V_18 ,
& V_132 . V_113 ) )
|| ( V_49 = F_96 ( V_18 ,
& V_133 . V_113 ) )
|| ( V_49 = F_96 ( V_18 ,
& V_134 . V_113 ) )
|| ( V_49 = F_96 ( V_18 ,
& V_135 . V_113 ) )
|| ( V_49 = F_96 ( V_18 ,
& V_136 . V_113 ) )
|| ( V_49 = F_96 ( V_18 ,
& V_137 . V_113 ) )
|| ( V_49 = F_96 ( V_18 ,
& V_138 . V_113 ) )
|| ( V_49 = F_96 ( V_18 ,
& V_139 . V_113 ) )
|| ( V_49 = F_96 ( V_18 ,
& V_140 . V_113 ) ) )
goto error;
if ( V_20 -> type != V_27 && V_20 -> V_55 != 0xff ) {
V_20 -> V_56 = F_97 () ;
if ( ( V_49 = F_96 ( V_18 , & V_141 ) )
|| ( V_49 = F_96 ( V_18 , & V_142 ) ) )
goto error;
}
if ( V_20 -> type == V_36 || V_20 -> type == V_37
|| V_20 -> type == V_38 ) {
V_49 = F_96 ( V_18 , & V_143 . V_113 ) ;
if ( V_49 )
goto error;
}
if ( V_20 -> type == V_37 || V_20 -> type == V_38 )
if ( ( V_49 = F_96 ( V_18 ,
& V_123 . V_113 ) )
|| ( V_49 = F_96 ( V_18 ,
& V_124 . V_113 ) )
|| ( V_49 = F_96 ( V_18 ,
& V_144 . V_113 ) ) )
goto error;
if ( V_20 -> type != V_28 )
if ( ( V_49 = F_96 ( V_18 ,
& V_145 . V_113 ) )
|| ( V_49 = F_96 ( V_18 ,
& V_146 . V_113 ) ) )
goto error;
if ( V_20 -> type == V_36 || V_20 -> type == V_37
|| V_20 -> type == V_38 ) {
V_49 = F_96 ( V_18 ,
& V_147 . V_113 ) ;
if ( V_49 )
goto error;
}
V_20 -> V_148 = F_98 ( V_18 ) ;
if ( F_99 ( V_20 -> V_148 ) ) {
V_49 = F_100 ( V_20 -> V_148 ) ;
goto error;
}
return 0 ;
error:
F_101 ( & V_18 -> V_110 , & V_111 ) ;
F_101 ( & V_18 -> V_110 , & V_149 ) ;
return V_49 ;
}
static int F_102 ( struct V_98 * V_99 )
{
struct V_19 * V_20 = F_103 ( V_99 ) ;
F_104 ( V_20 -> V_148 ) ;
F_101 ( & V_99 -> V_18 . V_110 , & V_111 ) ;
F_101 ( & V_99 -> V_18 . V_110 , & V_149 ) ;
return 0 ;
}
static inline void F_105 ( struct V_19 * V_20 , T_4 V_3 )
{
if ( ( V_3 & 0x00f0 ) == 0x50 ) {
F_106 ( V_150 , V_20 -> V_82 + V_151 ) ;
F_106 ( V_3 >> 8 , V_20 -> V_82 + V_152 ) ;
}
}
static inline void F_107 ( struct V_19 * V_20 , T_4 V_3 )
{
if ( V_3 & 0xff00 ) {
F_106 ( V_150 , V_20 -> V_82 + V_151 ) ;
F_106 ( 0 , V_20 -> V_82 + V_152 ) ;
}
}
static int F_20 ( struct V_19 * V_20 , T_4 V_3 )
{
int V_102 , V_153 ;
F_19 ( & V_20 -> V_109 ) ;
V_153 = ( ( ( V_3 & 0xff00 ) == 0x100 )
|| ( ( V_3 & 0xff00 ) == 0x200 ) )
&& ( ( ( V_3 & 0x00ff ) == 0x50 )
|| ( ( V_3 & 0x00ff ) == 0x53 )
|| ( ( V_3 & 0x00ff ) == 0x55 ) ) ;
F_105 ( V_20 , V_3 ) ;
F_106 ( V_3 & 0xff , V_20 -> V_82 + V_151 ) ;
V_102 = F_108 ( V_20 -> V_82 + V_152 ) ;
if ( V_153 ) {
F_106 ( ( V_3 & 0xff ) + 1 ,
V_20 -> V_82 + V_151 ) ;
V_102 =
( V_102 << 8 ) + F_108 ( V_20 -> V_82 +
V_152 ) ;
}
F_107 ( V_20 , V_3 ) ;
F_21 ( & V_20 -> V_109 ) ;
return V_102 ;
}
static int F_109 ( struct V_98 * V_99 )
{
struct V_1 * V_83 = V_99 -> V_18 . V_100 ;
int V_102 = 0xff , V_154 ;
F_6 ( V_83 ) ;
F_5 ( V_83 , V_155 ) ;
if ( ! ( F_3 ( V_83 , V_156 ) & ( 1 << 3 ) ) ) {
F_110 ( & V_99 -> V_18 , L_23 ) ;
goto exit;
}
V_154 = F_3 ( V_83 , V_157 ) & 0x3f ;
if ( ( V_154 & 0x1f ) != 0x1f ) {
F_110 ( & V_99 -> V_18 , L_24
L_25 ) ;
goto exit;
}
F_111 ( & V_99 -> V_18 , L_26 ) ;
V_102 = F_3 ( V_83 , V_158 ) & V_154 ;
exit:
F_7 ( V_83 ) ;
return V_102 ;
}
static int F_112 ( struct V_98 * V_99 )
{
struct V_1 * V_83 = V_99 -> V_18 . V_100 ;
int V_102 = 0xff ;
F_6 ( V_83 ) ;
F_5 ( V_83 , V_94 ) ;
if ( ! ( F_3 ( V_83 , V_159 ) & ( 1 << 2 ) ) ) {
F_110 ( & V_99 -> V_18 , L_27 ) ;
goto exit;
}
if ( ! ( F_3 ( V_83 , V_160 ) & ( 1 << 4 ) ) ) {
F_110 ( & V_99 -> V_18 , L_28
L_29 ) ;
goto exit;
}
V_102 = F_3 ( V_83 , V_161 ) & 0x3f ;
exit:
F_7 ( V_83 ) ;
return V_102 ;
}
static int F_24 ( struct V_19 * V_20 , T_4 V_3 , T_4 V_162 )
{
int V_153 ;
F_19 ( & V_20 -> V_109 ) ;
V_153 = ( ( ( V_3 & 0xff00 ) == 0x100 )
|| ( ( V_3 & 0xff00 ) == 0x200 ) )
&& ( ( ( V_3 & 0x00ff ) == 0x53 )
|| ( ( V_3 & 0x00ff ) == 0x55 ) ) ;
F_105 ( V_20 , V_3 ) ;
F_106 ( V_3 & 0xff , V_20 -> V_82 + V_151 ) ;
if ( V_153 ) {
F_106 ( V_162 >> 8 ,
V_20 -> V_82 + V_152 ) ;
F_106 ( ( V_3 & 0xff ) + 1 ,
V_20 -> V_82 + V_151 ) ;
}
F_106 ( V_162 & 0xff ,
V_20 -> V_82 + V_152 ) ;
F_107 ( V_20 , V_3 ) ;
F_21 ( & V_20 -> V_109 ) ;
return 0 ;
}
static void F_93 ( struct V_98 * V_99 )
{
struct V_19 * V_20 = F_103 ( V_99 ) ;
int V_16 ;
enum V_163 type = V_20 -> type ;
T_1 V_54 ;
if ( type == V_28 ) {
F_24 ( V_20 , V_164 , 0x89 ) ;
F_24 ( V_20 , V_165 , V_166 ) ;
}
if ( type == V_28 || type == V_37 ) {
int V_167 = F_20 ( V_20 , V_67 ) ;
int V_168 = F_20 ( V_20 , V_169 ) ;
V_20 -> V_55 = ( V_167 & 0x0f ) | ( ( V_168 & 0x01 ) << 4 ) ;
} else if ( type == V_36 ) {
V_20 -> V_55 = F_109 ( V_99 ) ;
} else if ( type == V_38 ) {
V_20 -> V_55 = F_112 ( V_99 ) ;
}
if ( type == V_36 || type == V_37 || type == V_38 ) {
V_20 -> V_40 =
F_20 ( V_20 , V_39 ) ;
}
V_54 = F_20 ( V_20 , V_23 ) ;
for ( V_16 = 1 ; V_16 <= 3 ; V_16 ++ ) {
if ( ! ( V_54 & V_78 [ V_16 - 1 ] ) ) {
V_20 -> V_77 [ V_16 - 1 ] = 4 ;
} else {
if ( F_20
( V_20 ,
V_25 ) & V_79 [ V_16 - 1 ] )
V_20 -> V_77 [ V_16 - 1 ] = 1 ;
else
V_20 -> V_77 [ V_16 - 1 ] = 2 ;
}
if ( ( type == V_27 ) && ( V_16 == 2 ) )
break;
}
if( V_170 ) {
V_54 = F_20 ( V_20 , V_171 ) ;
if ( V_54 & 0x01 ) {
F_80 ( & V_99 -> V_18 , L_30
L_31 ) ;
F_24 ( V_20 , V_171 ,
V_54 & 0xfe ) ;
}
if ( type != V_27 ) {
V_54 = F_20 ( V_20 ,
V_172 ) ;
if ( V_54 & 0x01 ) {
F_80 ( & V_99 -> V_18 , L_32
L_33 ) ;
F_24 ( V_20 ,
V_172 , V_54 & 0xfe ) ;
}
}
}
F_24 ( V_20 , V_173 ,
( F_20 ( V_20 ,
V_173 ) & 0xf7 )
| 0x01 ) ;
V_54 = F_20 ( V_20 , V_68 ) ;
if ( ! ( V_54 & 0x01 ) )
F_24 ( V_20 , V_68 , V_54 | 0x01 ) ;
}
static void F_94 ( struct V_19 * V_20 )
{
int V_3 ;
V_3 = F_20 ( V_20 , V_67 ) ;
V_20 -> V_53 [ 0 ] = ( V_3 >> 4 ) & 0x03 ;
V_20 -> V_53 [ 1 ] = ( V_3 >> 6 ) & 0x03 ;
if ( V_20 -> type != V_27 ) {
V_20 -> V_53 [ 2 ] = ( F_20 ( V_20 ,
V_66 ) >> 6 ) & 0x03 ;
}
V_3 = F_20 ( V_20 , V_68 ) ;
V_20 -> V_53 [ 0 ] |= ( V_3 >> 3 ) & 0x04 ;
V_20 -> V_53 [ 1 ] |= ( V_3 >> 4 ) & 0x04 ;
if ( V_20 -> type != V_27 )
V_20 -> V_53 [ 2 ] |= ( V_3 >> 5 ) & 0x04 ;
}
static struct V_19 * F_18 ( struct V_17 * V_18 )
{
struct V_19 * V_20 = F_23 ( V_18 ) ;
int V_16 , V_26 = ( V_20 -> type == V_27 ) ? 2 : 3 ;
int V_174 = ( V_20 -> type == V_27 ) ? 2 : 3 ;
F_19 ( & V_20 -> V_21 ) ;
if ( F_113 ( V_175 , V_20 -> V_176 + V_177 + V_177 / 2 )
|| ! V_20 -> V_41 ) {
for ( V_16 = 0 ; V_16 <= 8 ; V_16 ++ ) {
if ( ( ( V_20 -> type == V_27 ) && ( V_16 == 1 ) ) ||
( ( V_20 -> type != V_28 && V_20 -> type != V_27 )
&& ( V_16 == 5 || V_16 == 6 ) ) )
continue;
V_20 -> V_47 [ V_16 ] =
F_20 ( V_20 , F_114 ( V_16 ) ) ;
V_20 -> V_30 [ V_16 ] =
F_20 ( V_20 ,
F_26 ( V_16 ) ) ;
V_20 -> V_29 [ V_16 ] =
F_20 ( V_20 ,
F_25 ( V_16 ) ) ;
}
for ( V_16 = 0 ; V_16 <= 2 ; V_16 ++ ) {
V_20 -> V_52 [ V_16 ] =
F_20 ( V_20 , F_115 ( V_16 ) ) ;
V_20 -> V_31 [ V_16 ] =
F_20 ( V_20 ,
F_27 ( V_16 ) ) ;
}
for ( V_16 = 0 ; V_16 <= 2 ; V_16 ++ ) {
T_1 V_54 = F_20 ( V_20 ,
F_73 ( V_20 -> type , V_16 ) ) ;
if ( V_20 -> type == V_36 )
V_54 &= 0xf0 ;
V_20 -> V_69 [ V_16 ] = V_54 ;
if ( V_16 == 1 &&
( V_20 -> type == V_28 || V_20 -> type == V_27 ) )
break;
}
if ( V_20 -> type == V_28 ) {
T_1 V_54 = F_20 ( V_20 ,
V_75 ) ;
V_20 -> V_73 [ 0 ] = V_54 & 0x07 ;
V_20 -> V_73 [ 1 ] = ( V_54 >> 4 ) & 0x07 ;
} else if ( V_20 -> type != V_36 ) {
for ( V_16 = 1 ; V_16 <= 3 ; V_16 ++ ) {
V_20 -> V_73 [ V_16 - 1 ] =
F_20 ( V_20 ,
V_76 [ V_16 - 1 ] ) ;
if ( V_16 == 2 && ( V_20 -> type == V_27 ) )
break;
}
}
if ( V_20 -> type != V_28 ) {
for ( V_16 = 0 ; V_16 < V_174 ; V_16 ++ ) {
T_1 V_54 = F_20 ( V_20 ,
V_71 [ V_16 ] ) ;
V_20 -> V_70 [ V_16 ] =
( ( V_54 >> V_72 [ V_16 ] )
& 0x03 ) + 1 ;
}
}
for ( V_16 = 0 ; V_16 < V_26 ; V_16 ++ ) {
V_20 -> V_9 [ V_16 ] = F_20 (
V_20 , V_178 [ V_16 ] ) ;
V_20 -> V_33 [ V_16 ] = F_20 (
V_20 , V_32 [ V_16 ] ) ;
V_20 -> V_35 [ V_16 ] = F_20 (
V_20 , V_34 [ V_16 ] ) ;
}
F_94 ( V_20 ) ;
V_20 -> V_57 =
F_20 ( V_20 , V_179 ) |
( F_20 ( V_20 , V_180 ) << 8 ) |
( F_20 ( V_20 , V_181 ) << 16 ) ;
V_16 = F_20 ( V_20 , V_62 ) ;
V_20 -> V_59 = ( V_16 << 8 ) |
F_20 ( V_20 , V_60 ) |
F_20 ( V_20 , V_61 ) << 16 ;
V_20 -> V_176 = V_175 ;
V_20 -> V_41 = 1 ;
}
F_21 ( & V_20 -> V_21 ) ;
return V_20 ;
}
static int T_6 F_116 ( unsigned short V_182 ,
const struct V_1 * V_83 )
{
struct V_101 V_102 = {
. V_104 = V_182 + V_183 ,
. V_184 = V_182 + V_183 + V_105 - 1 ,
. V_81 = V_93 ,
. V_185 = V_103 ,
} ;
int V_49 ;
V_49 = F_117 ( & V_102 ) ;
if ( V_49 )
goto exit;
V_99 = F_118 ( V_93 , V_182 ) ;
if ( ! V_99 ) {
V_49 = - V_108 ;
F_119 ( L_34 ) ;
goto exit;
}
V_49 = F_120 ( V_99 , & V_102 , 1 ) ;
if ( V_49 ) {
F_119 ( L_35 , V_49 ) ;
goto V_186;
}
V_49 = F_121 ( V_99 , V_83 ,
sizeof( struct V_1 ) ) ;
if ( V_49 ) {
F_119 ( L_36 ) ;
goto V_186;
}
V_49 = F_122 ( V_99 ) ;
if ( V_49 ) {
F_119 ( L_37 , V_49 ) ;
goto V_186;
}
return 0 ;
V_186:
F_123 ( V_99 ) ;
exit:
return V_49 ;
}
static int T_6 F_124 ( void )
{
int V_49 ;
unsigned short V_182 ;
struct V_1 V_83 ;
if ( F_83 ( 0x2e , & V_182 , & V_83 )
&& F_83 ( 0x4e , & V_182 , & V_83 ) )
return - V_84 ;
V_49 = F_125 ( & V_187 ) ;
if ( V_49 )
goto exit;
V_49 = F_116 ( V_182 , & V_83 ) ;
if ( V_49 )
goto V_188;
return 0 ;
V_188:
F_126 ( & V_187 ) ;
exit:
return V_49 ;
}
static void T_8 F_127 ( void )
{
F_128 ( V_99 ) ;
F_126 ( & V_187 ) ;
}
