static inline unsigned long F_1 ( T_1 V_1 )
{
if ( ( V_1 >= 0xfff ) || ( V_1 == 0 ) )
return 0 ;
return ( 1350000UL / V_1 ) ;
}
static inline T_1 F_2 ( long V_2 )
{
if ( V_2 <= 0 )
return 0x0fff ;
return F_3 ( ( 1350000 + ( V_2 >> 1 ) ) / V_2 , 1 , 0xffe ) ;
}
static inline unsigned long F_4 ( T_2 V_3 )
{
return ( V_3 * 100 ) ;
}
static inline T_2 F_5 ( unsigned long V_1 )
{
return F_3 ( ( V_1 + 50 ) / 100 , 0 , 0xff ) ;
}
static inline long F_6 ( T_3 V_3 )
{
return ( V_3 * 1000 ) ;
}
static inline T_3 F_7 ( long V_1 , T_3 V_4 , T_3 V_5 )
{
return F_3 ( ( V_1 + ( V_1 < 0 ? - 500 : 500 ) ) / 1000 , V_4 , V_5 ) ;
}
static void F_8 ( struct V_6 * V_7 )
{
struct V_8 * V_9 = F_9 ( V_7 , struct V_8 , V_6 ) ;
F_10 ( V_9 ) ;
}
static T_4
F_11 ( struct V_10 * V_11 , struct V_12 * V_13 , char * V_14 )
{
struct V_8 * V_9 = F_12 ( V_11 ) ;
return sprintf ( V_14 , L_1 , V_9 -> V_15 ) ;
}
static T_4
F_13 ( struct V_10 * V_11 , struct V_12 * V_13 , char * V_14 )
{
struct V_8 * V_9 = F_14 ( V_11 ) ;
struct V_16 * V_17 =
F_15 ( V_13 ) ;
int V_18 = V_17 -> V_18 ;
return sprintf ( V_14 , L_1 , F_16 ( V_9 -> V_19 [ V_18 ] , V_9 -> V_15 ) ) ;
}
static T_4
F_17 ( struct V_10 * V_11 , struct V_12 * V_13 ,
const char * V_14 , T_5 V_20 )
{
struct V_8 * V_9 = F_12 ( V_11 ) ;
V_9 -> V_15 = F_18 ( V_14 , NULL , 10 ) ;
return V_20 ;
}
static T_4
F_19 ( struct V_10 * V_11 , struct V_12 * V_13 , char * V_14 )
{
struct V_8 * V_9 = F_14 ( V_11 ) ;
struct V_16 * V_17 =
F_15 ( V_13 ) ;
int V_21 = V_17 -> V_21 ;
int V_18 = V_17 -> V_18 >> 3 ;
int V_22 = V_17 -> V_18 & 0x07 ;
T_2 V_1 ;
if ( V_23 == V_21 ) {
V_1 = ( V_9 -> V_24 [ V_18 ] >> ( V_22 ) ) & 1 ;
} else {
V_1 = ( V_9 -> V_25 [ V_18 ] >> ( V_22 ) ) & 1 ;
}
return sprintf ( V_14 , L_2 , V_1 ) ;
}
static T_4
F_20 ( struct V_10 * V_11 , struct V_12 * V_13 ,
const char * V_14 , T_5 V_20 )
{
struct V_26 * V_27 = F_21 ( V_11 ) ;
struct V_8 * V_9 = F_22 ( V_27 ) ;
struct V_16 * V_17 =
F_15 ( V_13 ) ;
int V_18 = V_17 -> V_18 >> 3 ;
int V_28 = V_17 -> V_18 & 0x07 ;
T_2 V_29 = 1 << V_28 ;
T_2 V_1 ;
V_1 = F_18 ( V_14 , NULL , 10 ) ;
if ( V_1 != 0 && V_1 != 1 )
return - V_30 ;
F_23 ( & V_9 -> V_31 ) ;
V_9 -> V_25 [ V_18 ] = F_24 ( V_27 , F_25 ( V_18 ) ) ;
V_9 -> V_25 [ V_18 ] &= ~ V_29 ;
V_9 -> V_25 [ V_18 ] |= V_1 << V_28 ;
F_26 ( V_27 , F_25 ( V_18 ) , V_9 -> V_25 [ V_18 ] ) ;
F_27 ( & V_9 -> V_31 ) ;
return V_20 ;
}
static T_4
F_28 ( struct V_10 * V_11 , struct V_12 * V_13 , char * V_14 )
{
struct V_8 * V_9 = F_14 ( V_11 ) ;
return sprintf ( V_14 , L_2 , ( V_9 -> V_32 >> 1 ) & 0x01 ) ;
}
static T_4
F_29 ( struct V_10 * V_11 , struct V_12 * V_13 ,
const char * V_14 , T_5 V_20 )
{
struct V_26 * V_27 = F_21 ( V_11 ) ;
struct V_8 * V_9 = F_22 ( V_27 ) ;
T_2 V_1 = F_18 ( V_14 , NULL , 10 ) ;
if ( V_1 != 0 && V_1 != 1 )
return - V_30 ;
F_23 ( & V_9 -> V_31 ) ;
V_9 -> V_32 = F_24 ( V_27 , V_33 )
& 0xfd ;
V_9 -> V_32 |= V_1 << 1 ;
F_26 ( V_27 , V_33 , V_9 -> V_32 ) ;
F_27 ( & V_9 -> V_31 ) ;
return V_20 ;
}
static T_4
F_30 ( struct V_10 * V_11 ,
struct V_12 * V_13 , const char * V_14 ,
T_5 V_20 )
{
struct V_26 * V_27 = F_21 ( V_11 ) ;
struct V_8 * V_9 = F_22 ( V_27 ) ;
T_2 V_1 ;
F_31 ( V_11 , L_3
L_4 ) ;
F_23 ( & V_9 -> V_31 ) ;
V_1 = F_24 ( V_27 , V_34 ) ;
V_1 |= 0x80 ;
F_26 ( V_27 , V_34 , V_1 ) ;
F_27 ( & V_9 -> V_31 ) ;
return V_20 ;
}
static T_4
F_32 ( struct V_10 * V_11 ,
struct V_12 * V_13 , const char * V_14 ,
T_5 V_20 )
{
struct V_26 * V_27 = F_21 ( V_11 ) ;
struct V_8 * V_9 = F_22 ( V_27 ) ;
unsigned long V_1 ;
T_2 V_3 ;
if ( F_33 ( V_14 , 10 , & V_1 ) || V_1 != 0 )
return - V_30 ;
F_23 ( & V_9 -> V_31 ) ;
V_3 = F_24 ( V_27 , V_34 ) ;
F_26 ( V_27 , V_34 , V_3 | 0x80 ) ;
V_9 -> V_35 = 0 ;
F_27 ( & V_9 -> V_31 ) ;
return V_20 ;
}
static T_4
F_34 ( struct V_10 * V_11 , struct V_12 * V_13 , char * V_14 )
{
struct V_16 * V_17 =
F_15 ( V_13 ) ;
int V_21 = V_17 -> V_21 ;
int V_18 = V_17 -> V_18 ;
struct V_8 * V_9 = F_14 ( V_11 ) ;
T_1 V_1 ;
if ( V_36 == V_21 ) {
V_1 = V_9 -> V_37 [ V_18 ] & 0x0fff ;
} else {
V_1 = V_9 -> V_38 [ V_18 ] & 0x0fff ;
}
return sprintf ( V_14 , L_5 , F_1 ( V_1 ) ) ;
}
static T_4
F_35 ( struct V_10 * V_11 , struct V_12 * V_13 ,
const char * V_14 , T_5 V_20 )
{
struct V_16 * V_17 =
F_15 ( V_13 ) ;
int V_18 = V_17 -> V_18 ;
struct V_26 * V_27 = F_21 ( V_11 ) ;
struct V_8 * V_9 = F_22 ( V_27 ) ;
T_1 V_1 = F_2 ( F_18 ( V_14 , NULL , 10 ) ) ;
F_23 ( & V_9 -> V_31 ) ;
V_9 -> V_38 [ V_18 ] = V_1 ;
F_26 ( V_27 , F_36 ( V_18 ) ,
( V_1 >> 8 ) & 0xff ) ;
F_26 ( V_27 , F_36 ( V_18 ) + 1 , V_1 & 0xff ) ;
F_27 ( & V_9 -> V_31 ) ;
return V_20 ;
}
static T_4
F_37 ( struct V_10 * V_11 , struct V_12 * V_13 , char * V_14 )
{
struct V_16 * V_17 =
F_15 ( V_13 ) ;
struct V_8 * V_9 = F_14 ( V_11 ) ;
T_1 V_1 ;
int V_21 = V_17 -> V_21 ;
int V_18 = V_17 -> V_18 ;
if ( V_39 == V_21 )
V_1 = F_4 ( V_9 -> V_40 [ V_18 ] ) ;
else
V_1 = ( V_9 -> V_41 [ V_18 ] [ V_21 ] & 0x3f ) << 2 ;
return sprintf ( V_14 , L_1 , V_1 ) ;
}
static T_4
F_38 ( struct V_10 * V_11 , struct V_12 * V_13 ,
const char * V_14 , T_5 V_20 )
{
struct V_26 * V_27 = F_21 ( V_11 ) ;
struct V_8 * V_9 = F_22 ( V_27 ) ;
struct V_16 * V_17 =
F_15 ( V_13 ) ;
int V_21 = V_17 -> V_21 ;
int V_18 = V_17 -> V_18 ;
T_2 V_1 ;
F_23 ( & V_9 -> V_31 ) ;
if ( V_39 == V_21 ) {
V_1 = F_5 ( F_18 ( V_14 , NULL , 10 ) ) ;
V_9 -> V_40 [ V_18 ] = V_1 ;
F_26 ( V_27 , F_39 ( V_18 ) ,
V_1 ) ;
} else {
V_1 = F_3 ( F_18 ( V_14 , NULL , 10 ) , 0 , 0xff )
>> 2 ;
V_9 -> V_41 [ V_18 ] [ V_21 ] =
F_24 ( V_27 , F_40 ( V_18 , V_21 ) ) & 0xc0 ;
V_9 -> V_41 [ V_18 ] [ V_21 ] |= V_1 ;
F_26 ( V_27 , F_40 ( V_18 , V_21 ) ,
V_9 -> V_41 [ V_18 ] [ V_21 ] ) ;
}
F_27 ( & V_9 -> V_31 ) ;
return V_20 ;
}
static T_4
F_41 ( struct V_10 * V_11 , struct V_12 * V_13 , char * V_14 )
{
struct V_16 * V_17 =
F_15 ( V_13 ) ;
int V_21 = V_17 -> V_21 ;
int V_18 = V_17 -> V_18 ;
struct V_8 * V_9 = F_14 ( V_11 ) ;
long V_42 = F_6 ( V_9 -> V_42 [ V_18 ] [ V_21 ] ) ;
if ( V_43 == V_21 && V_18 < 4 ) {
int V_44 = ( ( V_9 -> V_45 >> ( V_18 * 2 ) ) & 0x03 ) * 250 ;
V_42 += V_42 > 0 ? V_44 : - V_44 ;
}
return sprintf ( V_14 , L_6 , V_42 ) ;
}
static T_4
F_42 ( struct V_10 * V_11 , struct V_12 * V_13 ,
const char * V_14 , T_5 V_20 )
{
struct V_16 * V_17 =
F_15 ( V_13 ) ;
int V_21 = V_17 -> V_21 ;
int V_18 = V_17 -> V_18 ;
struct V_26 * V_27 = F_21 ( V_11 ) ;
struct V_8 * V_9 = F_22 ( V_27 ) ;
long V_46 = F_43 ( V_14 , NULL , 10 ) ;
F_23 ( & V_9 -> V_31 ) ;
V_9 -> V_42 [ V_18 ] [ V_21 ] = F_7 ( V_46 , - 128 , 127 ) ;
F_26 ( V_27 , V_47 [ V_18 ] [ V_21 ] ,
V_9 -> V_42 [ V_18 ] [ V_21 ] ) ;
F_27 ( & V_9 -> V_31 ) ;
return V_20 ;
}
static T_4
F_44 ( struct V_10 * V_11 , struct V_12 * V_13 , char * V_14 )
{
struct V_8 * V_9 = F_14 ( V_11 ) ;
struct V_16 * V_17 =
F_15 ( V_13 ) ;
int V_18 = V_17 -> V_18 ;
T_2 V_48 = ( V_18 < 4 ) ? 0x03 : 0x01 ;
T_2 V_28 = ( V_18 < 4 ) ? ( 2 * V_18 ) : ( V_18 - 4 ) ;
T_2 V_46 ;
V_18 = ( V_18 < 4 ) ? 0 : 1 ;
V_46 = ( V_9 -> V_49 [ V_18 ] >> V_28 ) & V_48 ;
if ( V_46 == 1 ) {
V_46 = V_18 == 0 ? 3 : 4 ;
} else {
V_46 = V_50 [ V_46 ] ;
}
return sprintf ( V_14 , L_1 , V_46 ) ;
}
static T_4
F_45 ( struct V_10 * V_11 , struct V_12 * V_13 ,
const char * V_14 , T_5 V_20 )
{
struct V_26 * V_27 = F_21 ( V_11 ) ;
struct V_8 * V_9 = F_22 ( V_27 ) ;
struct V_16 * V_17 =
F_15 ( V_13 ) ;
int V_18 = V_17 -> V_18 ;
T_2 V_48 = ( V_18 < 4 ) ? 0x03 : 0x01 ;
T_2 V_28 = ( V_18 < 4 ) ? ( 2 * V_18 ) : ( V_18 - 4 ) ;
T_2 V_1 = F_18 ( V_14 , NULL , 10 ) ;
if ( ( V_1 == 6 ) && ( V_18 < 4 ) ) {
V_1 -= 3 ;
} else if ( ( V_1 == 3 && V_18 < 4 )
|| ( V_1 == 4 && V_18 >= 4 ) ) {
V_1 = ! ! V_1 ;
} else {
return - V_30 ;
}
V_18 = ( V_18 < 4 ) ? 0 : 1 ;
F_23 ( & V_9 -> V_31 ) ;
V_9 -> V_49 [ V_18 ] =
F_24 ( V_27 , V_51 [ V_18 ] ) ;
V_9 -> V_49 [ V_18 ] &= ~ ( V_48 << V_28 ) ;
V_9 -> V_49 [ V_18 ] |= V_1 << V_28 ;
F_26 ( V_27 , V_51 [ V_18 ] ,
V_9 -> V_49 [ V_18 ] ) ;
F_27 ( & V_9 -> V_31 ) ;
return V_20 ;
}
static T_4
F_46 ( struct V_10 * V_11 , struct V_12 * V_13 , char * V_14 )
{
struct V_16 * V_17 =
F_15 ( V_13 ) ;
int V_21 = V_17 -> V_21 ;
struct V_8 * V_9 = F_14 ( V_11 ) ;
T_6 V_1 = 0 ;
if ( V_52 == V_21 ) {
V_1 = ( V_9 -> V_53 & 0x3f ) << 2 ;
} else if ( V_54 == V_21 ) {
V_1 = F_4 ( V_9 -> V_55 ) ;
} else if ( V_56 == V_21 ) {
V_1 = F_4 ( V_9 -> V_57 ) ;
} else if ( V_58 == V_21 ) {
V_1 = F_6 ( V_9 -> V_59 & 0x7f ) ;
}
return sprintf ( V_14 , L_1 , V_1 ) ;
}
static T_4
F_47 ( struct V_10 * V_11 , struct V_12 * V_13 ,
const char * V_14 , T_5 V_20 )
{
struct V_16 * V_17 =
F_15 ( V_13 ) ;
int V_21 = V_17 -> V_21 ;
struct V_26 * V_27 = F_21 ( V_11 ) ;
struct V_8 * V_9 = F_22 ( V_27 ) ;
F_23 ( & V_9 -> V_31 ) ;
if ( V_52 == V_21 ) {
V_9 -> V_53 =
F_24 ( V_27 , V_60 ) & 0xc0 ;
V_9 -> V_53 |= F_3 ( F_18 ( V_14 , NULL ,
10 ) ,
0 , 0xff ) >> 2 ;
F_26 ( V_27 , V_60 ,
V_9 -> V_53 ) ;
} else if ( V_54 == V_21 ) {
V_9 -> V_55 = F_5 ( F_18 ( V_14 , NULL , 10 ) ) ;
V_9 -> V_55 += V_9 -> V_55 == 0 ? 1 : 0 ;
F_26 ( V_27 , V_61 ,
V_9 -> V_55 ) ;
} else if ( V_56 == V_21 ) {
V_9 -> V_57 = F_5 ( F_18 ( V_14 , NULL , 10 ) ) ;
V_9 -> V_57 += V_9 -> V_57 == 0 ? 1 : 0 ;
F_26 ( V_27 , V_62 ,
V_9 -> V_57 ) ;
} else {
V_9 -> V_59 =
F_24 ( V_27 , V_63 ) & 0x80 ;
V_9 -> V_59 |= F_7 ( F_43 ( V_14 , NULL , 10 ) ,
0 , 0x7f ) ;
F_26 ( V_27 , V_63 ,
V_9 -> V_59 ) ;
}
F_27 ( & V_9 -> V_31 ) ;
return V_20 ;
}
static T_4
F_48 ( struct V_10 * V_11 , struct V_12 * V_13 , char * V_14 )
{
struct V_16 * V_17 =
F_15 ( V_13 ) ;
int V_21 = V_17 -> V_21 ;
int V_18 = V_17 -> V_18 ;
struct V_8 * V_9 = F_14 ( V_11 ) ;
T_6 V_1 ;
if ( V_64 == V_21 ) {
V_1 = V_9 -> V_65 [ V_18 ] ;
} else if ( V_66 == V_21 ) {
V_1 = ( ( V_9 -> V_67 >> V_18 ) & 0x01 ) + 2 ;
} else if ( V_68 == V_21 ) {
V_1 = F_6 ( V_9 -> V_69 [ V_18 ] & 0x7f ) ;
} else {
V_1 = V_9 -> V_70 [ V_18 >> 1 ] >> ( ( V_18 & 0x01 ) ? 4 : 0 ) ;
V_1 = F_6 ( V_1 & 0x0f ) ;
}
return sprintf ( V_14 , L_1 , V_1 ) ;
}
static T_4
F_49 ( struct V_10 * V_11 , struct V_12 * V_13 ,
const char * V_14 , T_5 V_20 )
{
struct V_16 * V_17 =
F_15 ( V_13 ) ;
int V_21 = V_17 -> V_21 ;
int V_18 = V_17 -> V_18 ;
struct V_26 * V_27 = F_21 ( V_11 ) ;
struct V_8 * V_9 = F_22 ( V_27 ) ;
T_6 V_1 ;
F_23 ( & V_9 -> V_31 ) ;
if ( V_64 == V_21 ) {
V_1 = F_18 ( V_14 , NULL , 10 ) & 0xff ;
F_26 ( V_27 , F_50 ( V_18 ) , V_1 ) ;
V_9 -> V_65 [ V_18 ] = V_1 ;
} else if ( V_66 == V_21 ) {
V_1 = F_18 ( V_14 , NULL , 10 ) ;
if ( 2 == V_1 || 3 == V_1 ) {
V_9 -> V_67 =
F_24 ( V_27 , V_71 ) ;
if ( V_1 - 2 )
V_9 -> V_67 |= 1 << V_18 ;
else
V_9 -> V_67 &= ~ ( 1 << V_18 ) ;
F_26 ( V_27 , V_71 ,
V_9 -> V_67 ) ;
} else {
F_27 ( & V_9 -> V_31 ) ;
return - V_30 ;
}
} else if ( V_68 == V_21 ) {
V_9 -> V_69 [ V_18 ] =
F_24 ( V_27 , F_51 ( V_18 ) ) ;
V_1 = F_7 ( F_43 ( V_14 , NULL , 10 ) , 0 , 0x7f ) ;
V_9 -> V_69 [ V_18 ] &= 0x80 ;
V_9 -> V_69 [ V_18 ] |= V_1 ;
F_26 ( V_27 , F_51 ( V_18 ) ,
V_9 -> V_69 [ V_18 ] ) ;
} else {
int V_72 = V_18 >> 1 ;
T_2 V_28 = ( V_18 & 0x01 ) ? 4 : 0 ;
V_9 -> V_70 [ V_72 ] =
F_24 ( V_27 , F_52 ( V_72 ) ) ;
V_1 = F_7 ( F_43 ( V_14 , NULL , 10 ) , 0 , 0x0f ) ;
V_9 -> V_70 [ V_72 ] &= ~ ( 0x0f << V_28 ) ;
V_9 -> V_70 [ V_72 ] |= V_1 << V_28 ;
F_26 ( V_27 , F_52 ( V_72 ) ,
V_9 -> V_70 [ V_72 ] ) ;
}
F_27 ( & V_9 -> V_31 ) ;
return V_20 ;
}
static T_4
F_53 ( struct V_10 * V_11 , struct V_12 * V_13 , char * V_14 )
{
struct V_16 * V_17 =
F_15 ( V_13 ) ;
int V_21 = V_17 -> V_21 ;
int V_18 = V_17 -> V_18 ;
struct V_8 * V_9 = F_14 ( V_11 ) ;
return sprintf ( V_14 , L_1 , ( V_9 -> V_73 [ V_18 ] [ V_21 ] & 0x3f ) << 2 ) ;
}
static T_4
F_54 ( struct V_10 * V_11 , struct V_12 * V_13 ,
const char * V_14 , T_5 V_20 )
{
struct V_26 * V_27 = F_21 ( V_11 ) ;
struct V_8 * V_9 = F_22 ( V_27 ) ;
struct V_16 * V_17 =
F_15 ( V_13 ) ;
int V_21 = V_17 -> V_21 ;
int V_18 = V_17 -> V_18 ;
T_2 V_1 = F_3 ( F_18 ( V_14 , NULL , 10 ) , 0 , 0xff ) >> 2 ;
F_23 ( & V_9 -> V_31 ) ;
V_9 -> V_73 [ V_18 ] [ V_21 ] =
F_24 ( V_27 , F_55 ( V_18 , V_21 ) ) & 0xc0 ;
V_9 -> V_73 [ V_18 ] [ V_21 ] |= V_1 ;
F_26 ( V_27 , F_55 ( V_18 , V_21 ) ,
V_9 -> V_73 [ V_18 ] [ V_21 ] ) ;
F_27 ( & V_9 -> V_31 ) ;
return V_20 ;
}
static T_4
F_56 ( struct V_10 * V_11 , struct V_12 * V_13 , char * V_14 )
{
struct V_16 * V_17 =
F_15 ( V_13 ) ;
int V_21 = V_17 -> V_21 ;
int V_18 = V_17 -> V_18 ;
struct V_8 * V_9 = F_14 ( V_11 ) ;
return sprintf ( V_14 , L_6 ,
F_6 ( V_9 -> V_74 [ V_18 ] [ V_21 ] & 0x7f ) ) ;
}
static T_4
F_57 ( struct V_10 * V_11 , struct V_12 * V_13 ,
const char * V_14 , T_5 V_20 )
{
struct V_26 * V_27 = F_21 ( V_11 ) ;
struct V_8 * V_9 = F_22 ( V_27 ) ;
struct V_16 * V_17 =
F_15 ( V_13 ) ;
int V_21 = V_17 -> V_21 ;
int V_18 = V_17 -> V_18 ;
T_2 V_1 = F_7 ( F_43 ( V_14 , NULL , 10 ) , 0 , 0x7f ) ;
F_23 ( & V_9 -> V_31 ) ;
V_9 -> V_74 [ V_18 ] [ V_21 ] =
F_24 ( V_27 , F_58 ( V_18 , V_21 ) ) & 0x80 ;
V_9 -> V_74 [ V_18 ] [ V_21 ] |= V_1 ;
F_26 ( V_27 , F_58 ( V_18 , V_21 ) ,
V_9 -> V_74 [ V_18 ] [ V_21 ] ) ;
F_27 ( & V_9 -> V_31 ) ;
return V_20 ;
}
static T_4
F_59 ( struct V_10 * V_11 , struct V_12 * V_13 , char * V_14 )
{
struct V_16 * V_17 =
F_15 ( V_13 ) ;
int V_21 = V_17 -> V_21 ;
int V_18 = V_17 -> V_18 ;
struct V_8 * V_9 = F_14 ( V_11 ) ;
T_1 V_1 = V_9 -> V_75 [ V_18 ] [ V_21 ] ;
if ( V_18 < 3 ) {
V_1 <<= 2 ;
V_1 += ( V_9 -> V_76 [ V_21 ] >> ( V_18 * 2 ) ) & 0x3 ;
}
V_1 = V_1 * V_77 [ V_18 ] + V_78 [ V_18 ] ;
return sprintf ( V_14 , L_1 , V_1 ) ;
}
static T_4
F_60 ( struct V_10 * V_11 , struct V_12 * V_13 ,
const char * V_14 , T_5 V_20 )
{
struct V_16 * V_17 =
F_15 ( V_13 ) ;
int V_21 = V_17 -> V_21 ;
int V_18 = V_17 -> V_18 ;
struct V_26 * V_27 = F_21 ( V_11 ) ;
struct V_8 * V_9 = F_22 ( V_27 ) ;
T_6 V_1 ;
V_1 =
( F_18 ( V_14 , NULL , 10 ) +
V_77 [ V_18 ] / 2 ) / V_77 [ V_18 ] ;
F_23 ( & V_9 -> V_31 ) ;
if ( V_18 > 2 ) {
if ( 1 == V_21 || 2 == V_21 ) {
V_1 -= V_78 [ V_18 ] / V_77 [ V_18 ] ;
}
V_1 = F_3 ( V_1 , 0 , 255 ) ;
} else {
V_1 = F_3 ( V_1 , 0 , 0x3FF ) ;
V_9 -> V_76 [ V_21 ] =
F_24 ( V_27 , V_79 [ V_21 ] ) ;
V_9 -> V_76 [ V_21 ] &= ~ ( 0x03 << ( 2 * V_18 ) ) ;
V_9 -> V_76 [ V_21 ] |= ( V_1 & 0x03 ) << ( 2 * V_18 ) ;
F_26 ( V_27 , V_79 [ V_21 ] ,
V_9 -> V_76 [ V_21 ] ) ;
V_1 >>= 2 ;
}
V_9 -> V_75 [ V_18 ] [ V_21 ] = V_1 ;
F_26 ( V_27 , V_80 [ V_18 ] [ V_21 ] ,
V_9 -> V_75 [ V_18 ] [ V_21 ] ) ;
F_27 ( & V_9 -> V_31 ) ;
return V_20 ;
}
static void F_61 ( struct V_26 * V_27 )
{
if ( V_81 ) {
F_26 ( V_27 , V_82 , 0x80 ) ;
}
F_26 ( V_27 , V_82 ,
F_24 ( V_27 , V_82 ) | 0x01 ) ;
}
static int F_62 ( struct V_8 * V_9 , int V_83 )
{
int V_84 , V_85 ;
V_85 = F_63 ( V_83 , 60 ) ;
if ( V_85 > 255 )
return - V_30 ;
F_23 ( & V_9 -> V_86 ) ;
if ( ! V_9 -> V_27 ) {
V_84 = - V_87 ;
goto V_88;
}
V_9 -> V_89 = V_85 ;
F_26 ( V_9 -> V_27 , V_90 ,
V_9 -> V_89 ) ;
V_84 = V_85 * 60 ;
V_88:
F_27 ( & V_9 -> V_86 ) ;
return V_84 ;
}
static int F_64 ( struct V_8 * V_9 )
{
int V_83 ;
F_23 ( & V_9 -> V_86 ) ;
V_83 = V_9 -> V_89 * 60 ;
F_27 ( & V_9 -> V_86 ) ;
return V_83 ;
}
static int F_65 ( struct V_8 * V_9 )
{
int V_84 = 0 ;
F_23 ( & V_9 -> V_86 ) ;
if ( ! V_9 -> V_27 ) {
V_84 = - V_87 ;
goto V_88;
}
F_26 ( V_9 -> V_27 , V_90 ,
V_9 -> V_89 ) ;
V_88:
F_27 ( & V_9 -> V_86 ) ;
return V_84 ;
}
static int F_66 ( struct V_8 * V_9 )
{
int V_84 = 0 ;
F_23 ( & V_9 -> V_86 ) ;
if ( ! V_9 -> V_27 ) {
V_84 = - V_87 ;
goto V_88;
}
F_26 ( V_9 -> V_27 , V_90 ,
V_9 -> V_89 ) ;
F_26 ( V_9 -> V_27 , V_91 , 0x55 ) ;
V_88:
F_27 ( & V_9 -> V_86 ) ;
return V_84 ;
}
static int F_67 ( struct V_8 * V_9 )
{
int V_84 = 0 ;
F_23 ( & V_9 -> V_86 ) ;
if ( ! V_9 -> V_27 ) {
V_84 = - V_87 ;
goto V_88;
}
F_26 ( V_9 -> V_27 , V_91 , 0xAA ) ;
V_88:
F_27 ( & V_9 -> V_86 ) ;
return V_84 ;
}
static int F_68 ( struct V_92 * V_92 , struct V_93 * V_94 )
{
struct V_8 * V_95 , * V_9 = NULL ;
int V_96 ;
if ( ! F_69 ( & V_97 ) )
return - V_98 ;
F_70 (pos, &watchdog_data_list, list) {
if ( V_95 -> V_99 . V_100 == F_71 ( V_92 ) ) {
V_9 = V_95 ;
break;
}
}
V_96 = F_72 ( 0 , & V_9 -> V_96 ) ;
if ( ! V_96 )
F_73 ( & V_9 -> V_6 ) ;
F_27 ( & V_97 ) ;
if ( V_96 )
return - V_101 ;
F_66 ( V_9 ) ;
V_94 -> V_102 = V_9 ;
return F_74 ( V_92 , V_94 ) ;
}
static int F_75 ( struct V_92 * V_92 , struct V_93 * V_94 )
{
struct V_8 * V_9 = V_94 -> V_102 ;
if ( V_9 -> V_103 ) {
F_67 ( V_9 ) ;
V_9 -> V_103 = 0 ;
} else {
F_65 ( V_9 ) ;
F_76 ( & V_9 -> V_27 -> V_11 ,
L_7 ) ;
}
F_77 ( 0 , & V_9 -> V_96 ) ;
F_23 ( & V_97 ) ;
F_78 ( & V_9 -> V_6 , F_8 ) ;
F_27 ( & V_97 ) ;
return 0 ;
}
static T_4 F_79 ( struct V_93 * V_94 , const char T_7 * V_14 ,
T_5 V_20 , T_8 * V_104 )
{
T_4 V_84 ;
struct V_8 * V_9 = V_94 -> V_102 ;
if ( V_20 ) {
if ( ! V_105 ) {
T_5 V_72 ;
V_9 -> V_103 = 0 ;
for ( V_72 = 0 ; V_72 != V_20 ; V_72 ++ ) {
char V_106 ;
if ( F_80 ( V_106 , V_14 + V_72 ) )
return - V_107 ;
if ( V_106 == 'V' )
V_9 -> V_103 = 1 ;
}
}
V_84 = F_65 ( V_9 ) ;
if ( V_84 < 0 )
return V_84 ;
}
return V_20 ;
}
static long F_81 ( struct V_93 * V_94 , unsigned int V_108 ,
unsigned long V_109 )
{
struct V_110 V_111 = {
. V_112 = V_113 |
V_114 |
V_115 ,
. V_116 = L_8
} ;
int V_1 , V_84 = 0 ;
struct V_8 * V_9 = V_94 -> V_102 ;
switch ( V_108 ) {
case V_117 :
if ( ! V_105 )
V_111 . V_112 |= V_118 ;
if ( F_82 ( ( void T_7 * ) V_109 , & V_111 , sizeof( V_111 ) ) )
V_84 = - V_107 ;
break;
case V_119 :
V_1 = V_9 -> V_120 ? V_115 : 0 ;
V_84 = F_83 ( V_1 , ( int T_7 * ) V_109 ) ;
break;
case V_121 :
V_84 = F_83 ( 0 , ( int T_7 * ) V_109 ) ;
break;
case V_122 :
V_84 = F_65 ( V_9 ) ;
break;
case V_123 :
V_1 = F_64 ( V_9 ) ;
V_84 = F_83 ( V_1 , ( int T_7 * ) V_109 ) ;
break;
case V_124 :
if ( F_80 ( V_1 , ( int T_7 * ) V_109 ) ) {
V_84 = - V_107 ;
break;
}
V_84 = F_62 ( V_9 , V_1 ) ;
if ( V_84 > 0 )
V_84 = F_83 ( V_84 , ( int T_7 * ) V_109 ) ;
break;
case V_125 :
if ( F_80 ( V_1 , ( int T_7 * ) V_109 ) ) {
V_84 = - V_107 ;
break;
}
if ( V_1 & V_126 )
V_84 = F_67 ( V_9 ) ;
else if ( V_1 & V_127 )
V_84 = F_66 ( V_9 ) ;
else
V_84 = - V_30 ;
break;
default:
V_84 = - V_128 ;
}
return V_84 ;
}
static int F_84 ( struct V_129 * V_130 , unsigned long V_131 ,
void * V_132 )
{
struct V_8 * V_9 = NULL ;
if ( V_131 == V_133 || V_131 == V_134 ) {
F_23 ( & V_97 ) ;
F_70 (data, &watchdog_data_list, list) {
if ( V_9 -> V_99 . V_100 )
F_67 ( V_9 ) ;
}
F_27 ( & V_97 ) ;
}
return V_135 ;
}
static int F_85 ( struct V_26 * V_27 )
{
struct V_8 * V_9 = F_22 ( V_27 ) ;
struct V_10 * V_11 = & V_27 -> V_11 ;
int V_72 , V_46 ;
if ( V_9 -> V_99 . V_100 ) {
F_86 ( & V_9 -> V_99 ) ;
if ( V_9 -> V_96 ) {
F_31 ( & V_27 -> V_11 ,
L_9
L_10 ) ;
F_67 ( V_9 ) ;
}
F_23 ( & V_97 ) ;
F_87 ( & V_9 -> V_136 ) ;
F_27 ( & V_97 ) ;
F_23 ( & V_9 -> V_86 ) ;
V_9 -> V_27 = NULL ;
F_27 ( & V_9 -> V_86 ) ;
}
V_46 = F_24 ( V_27 , V_82 ) ;
F_26 ( V_27 , V_82 , V_46 & ~ 0x04 ) ;
F_88 ( & V_137 ) ;
F_89 ( V_9 -> V_138 ) ;
for ( V_72 = 0 ; V_72 < F_90 ( V_139 ) ; V_72 ++ )
F_91 ( V_11 ,
& V_139 [ V_72 ] . V_140 ) ;
for ( V_72 = 0 ; V_72 < F_90 ( V_141 ) ; V_72 ++ )
F_91 ( V_11 , & V_141 [ V_72 ] . V_140 ) ;
for ( V_72 = 0 ; V_72 < F_90 ( V_142 ) ; V_72 ++ )
F_91 ( V_11 , & V_142 [ V_72 ] . V_140 ) ;
F_91 ( V_11 , & V_143 ) ;
for ( V_72 = 0 ; V_72 < F_90 ( V_144 ) ; V_72 ++ )
F_91 ( V_11 , & V_144 [ V_72 ] . V_140 ) ;
for ( V_72 = 0 ; V_72 < F_90 ( V_145 ) ; V_72 ++ )
F_91 ( V_11 , & V_145 [ V_72 ] . V_140 ) ;
for ( V_72 = 0 ; V_72 < F_90 ( V_146 ) ; V_72 ++ )
F_91 ( V_11 , & V_146 [ V_72 ] . V_140 ) ;
if ( V_9 -> V_147 [ 0 ] != NULL )
F_92 ( V_9 -> V_147 [ 0 ] ) ;
if ( V_9 -> V_147 [ 1 ] != NULL )
F_92 ( V_9 -> V_147 [ 1 ] ) ;
F_23 ( & V_97 ) ;
F_78 ( & V_9 -> V_6 , F_8 ) ;
F_27 ( & V_97 ) ;
return 0 ;
}
static int
F_93 ( struct V_26 * V_27 )
{
int V_72 , V_148 , V_149 ;
int V_150 = V_27 -> V_151 ;
T_2 V_46 ;
struct V_152 * V_153 = V_27 -> V_153 ;
struct V_8 * V_9 = F_22 ( V_27 ) ;
V_148 = F_94 ( V_153 ) ;
if ( V_154 [ 0 ] == V_148 && V_154 [ 1 ] == V_150 ) {
for ( V_72 = 2 ; V_72 <= 3 ; V_72 ++ ) {
if ( V_154 [ V_72 ] < 0x48
|| V_154 [ V_72 ] > 0x4f ) {
F_95 ( & V_27 -> V_11 ,
L_11
L_12 ,
V_154 [ V_72 ] ) ;
V_149 = - V_30 ;
goto V_155;
}
}
F_26 ( V_27 , V_156 ,
( V_154 [ 2 ] & 0x07 ) |
( ( V_154 [ 3 ] & 0x07 ) << 4 ) ) ;
}
V_46 = F_24 ( V_27 , V_156 ) ;
if ( ! ( V_46 & 0x08 ) ) {
V_9 -> V_147 [ 0 ] = F_96 ( V_153 , 0x48 + ( V_46 & 0x7 ) ) ;
}
if ( ! ( V_46 & 0x80 ) ) {
if ( ( V_9 -> V_147 [ 0 ] != NULL )
&& ( ( V_46 & 0x7 ) == ( ( V_46 >> 4 ) & 0x7 ) ) ) {
F_95 ( & V_27 -> V_11 ,
L_13
L_14 , V_9 -> V_147 [ 0 ] -> V_151 ) ;
V_149 = - V_87 ;
goto V_157;
}
V_9 -> V_147 [ 1 ] = F_96 ( V_153 ,
0x48 + ( ( V_46 >> 4 ) & 0x7 ) ) ;
}
return 0 ;
V_157:
if ( V_9 -> V_147 [ 0 ] != NULL )
F_92 ( V_9 -> V_147 [ 0 ] ) ;
V_155:
return V_149 ;
}
static int F_97 ( struct V_26 * V_27 ,
struct V_158 * V_159 )
{
T_2 V_46 , V_160 , V_161 ;
struct V_152 * V_153 = V_27 -> V_153 ;
unsigned short V_150 = V_27 -> V_151 ;
if ( ! F_98 ( V_153 , V_162 ) ) {
return - V_87 ;
}
V_160 = F_99 ( V_27 , V_163 ) ;
V_46 = V_160 & 0x80 ? 0x5c : 0xa3 ;
if ( V_46 != F_99 ( V_27 , V_164 ) ) {
F_100 ( L_15 ) ;
return - V_87 ;
}
if ( ( V_160 & 0x07 ) == 0
&& F_99 ( V_27 , V_165 ) !=
( V_150 << 1 ) ) {
F_100 ( L_16 ) ;
return - V_87 ;
}
V_161 = F_99 ( V_27 , V_166 ) ;
if ( V_161 != 0x7b )
return - V_87 ;
F_101 ( V_159 -> type , L_17 , V_167 ) ;
return 0 ;
}
static int F_102 ( struct V_26 * V_27 ,
const struct V_168 * V_148 )
{
struct V_10 * V_11 = & V_27 -> V_11 ;
const int V_169 [] = { V_170 , 212 , 213 , 214 , 215 } ;
struct V_8 * V_9 ;
int V_72 , V_46 , V_1 , V_149 ;
int V_171 = F_90 ( V_144 ) / 7 ;
int V_172 = F_90 ( V_145 ) / 5 ;
int V_173 = F_90 ( V_146 ) / 6 ;
V_9 = F_103 ( sizeof( struct V_8 ) , V_174 ) ;
if ( ! V_9 ) {
V_149 = - V_175 ;
goto exit;
}
F_104 ( V_27 , V_9 ) ;
V_9 -> V_160 = F_99 ( V_27 , V_163 ) ;
F_105 ( & V_9 -> V_31 ) ;
F_105 ( & V_9 -> V_86 ) ;
F_106 ( & V_9 -> V_136 ) ;
F_107 ( & V_9 -> V_6 ) ;
V_9 -> V_27 = V_27 ;
V_149 = F_93 ( V_27 ) ;
if ( V_149 )
goto V_176;
F_61 ( V_27 ) ;
V_9 -> V_177 = 0x1f ;
V_9 -> V_178 = 0x07 ;
V_46 = F_24 ( V_27 , V_179 ) ;
V_1 = F_24 ( V_27 , V_180 ) ;
if ( V_46 & 0x80 ) {
V_9 -> V_181 |= 0x2 ;
} else {
V_9 -> V_178 |= 0x18 ;
if ( V_1 & 0x01 ) {
V_9 -> V_177 |= 0x20 ;
V_9 -> V_178 |= 0x20 ;
}
if ( V_1 & 0x02 ) {
V_9 -> V_177 |= 0x40 ;
V_9 -> V_178 |= 0x40 ;
}
if ( ! ( V_46 & 0x40 ) && ( V_1 & 0x04 ) ) {
V_9 -> V_177 |= 0x80 ;
V_9 -> V_178 |= 0x80 ;
}
}
if ( ! ( V_46 & 0x29 ) )
V_9 -> V_181 |= 0x1 ;
if ( 0x08 == ( V_46 & 0x0c ) ) {
if ( V_1 & 0x08 )
V_9 -> V_177 |= 0x100 ;
if ( V_1 & 0x10 )
V_9 -> V_177 |= 0x200 ;
}
if ( 0x20 == ( V_46 & 0x30 ) ) {
if ( V_1 & 0x20 )
V_9 -> V_177 |= 0x400 ;
if ( V_1 & 0x40 )
V_9 -> V_177 |= 0x800 ;
}
if ( ( V_46 & 0x01 ) && ( V_1 & 0x04 ) ) {
V_9 -> V_177 |= 0x80 ;
V_9 -> V_178 |= 0x80 ;
}
V_46 = F_24 ( V_27 , V_182 ) ;
if ( ( V_46 & 0x01 ) && ( V_1 & 0x08 ) ) {
V_9 -> V_177 |= 0x100 ;
}
if ( ( V_46 & 0x02 ) && ( V_1 & 0x10 ) ) {
V_9 -> V_177 |= 0x200 ;
}
if ( ( V_46 & 0x04 ) && ( V_1 & 0x20 ) ) {
V_9 -> V_177 |= 0x400 ;
}
if ( ( V_46 & 0x08 ) && ( V_1 & 0x40 ) ) {
V_9 -> V_177 |= 0x800 ;
}
V_46 = F_24 ( V_27 , V_51 [ 0 ] ) ;
if ( V_46 & 0x01 )
V_9 -> V_183 |= 0x01 ;
if ( V_46 & 0x04 )
V_9 -> V_183 |= 0x02 ;
if ( V_46 & 0x10 )
V_9 -> V_183 |= 0x04 ;
if ( V_46 & 0x40 )
V_9 -> V_183 |= 0x08 ;
V_46 = F_24 ( V_27 , V_51 [ 1 ] ) ;
if ( V_46 & 0x01 )
V_9 -> V_183 |= 0x10 ;
if ( V_46 & 0x02 )
V_9 -> V_183 |= 0x20 ;
for ( V_72 = 0 ; V_72 < F_90 ( V_139 ) ; V_72 ++ ) {
V_149 = F_108 ( V_11 ,
& V_139 [ V_72 ] . V_140 ) ;
if ( V_149 )
goto V_184;
}
for ( V_72 = 0 ; V_72 < F_90 ( V_142 ) ; V_72 ++ ) {
if ( ! ( V_9 -> V_181 & ( 1 << V_72 ) ) )
continue;
V_149 = F_108 ( V_11 , & V_142 [ V_72 ] . V_140 ) ;
if ( V_149 )
goto V_184;
}
if ( V_9 -> V_181 ) {
V_9 -> V_15 = F_109 () ;
V_149 = F_108 ( V_11 , & V_143 ) ;
if ( V_149 )
goto V_184;
}
for ( V_72 = 0 ; V_72 < F_90 ( V_141 ) ; V_72 ++ ) {
V_149 = F_108 ( V_11 , & V_141 [ V_72 ] . V_140 ) ;
if ( V_149 )
goto V_184;
}
for ( V_72 = 0 ; V_72 < 6 ; V_72 ++ ) {
int V_185 ;
if ( ! ( V_9 -> V_183 & ( 1 << V_72 ) ) )
continue;
for ( V_185 = 0 ; V_185 < V_173 ; V_185 ++ ) {
V_149 = F_108 ( V_11 ,
& V_146 [ ( V_72 ) * V_173
+ V_185 ] . V_140 ) ;
if ( V_149 )
goto V_184;
}
}
for ( V_72 = 5 ; V_72 < 12 ; V_72 ++ ) {
int V_185 ;
if ( ! ( V_9 -> V_177 & ( 1 << V_72 ) ) )
continue;
for ( V_185 = 0 ; V_185 < V_171 ; V_185 ++ ) {
V_149 = F_108 ( V_11 ,
& V_144 [ ( V_72 - 5 ) * V_171
+ V_185 ] . V_140 ) ;
if ( V_149 )
goto V_184;
}
}
for ( V_72 = 3 ; V_72 < 8 ; V_72 ++ ) {
int V_185 ;
if ( ! ( V_9 -> V_178 & ( 1 << V_72 ) ) )
continue;
for ( V_185 = 0 ; V_185 < V_172 ; V_185 ++ ) {
V_149 = F_108 ( V_11 ,
& V_145 [ ( V_72 - 3 ) * V_172
+ V_185 ] . V_140 ) ;
if ( V_149 )
goto V_184;
}
}
V_9 -> V_138 = F_110 ( V_11 ) ;
if ( F_111 ( V_9 -> V_138 ) ) {
V_149 = F_112 ( V_9 -> V_138 ) ;
goto V_184;
}
V_149 = F_113 ( & V_137 ) ;
if ( V_149 != 0 ) {
F_95 ( & V_27 -> V_11 ,
L_18 , V_149 ) ;
goto V_186;
}
V_46 = F_24 ( V_27 , V_82 ) ;
F_26 ( V_27 , V_82 , V_46 | 0x04 ) ;
V_9 -> V_89 = V_83 ;
V_9 -> V_120 =
F_24 ( V_9 -> V_27 , V_187 ) & 0x01 ;
F_67 ( V_9 ) ;
F_23 ( & V_97 ) ;
for ( V_72 = 0 ; V_72 < F_90 ( V_169 ) ; V_72 ++ ) {
snprintf ( V_9 -> V_188 , sizeof( V_9 -> V_188 ) ,
L_19 , ( V_72 == 0 ) ? '\0' : ( '0' + V_72 ) ) ;
V_9 -> V_99 . V_189 = V_9 -> V_188 ;
V_9 -> V_99 . V_190 = & V_191 ;
V_9 -> V_99 . V_100 = V_169 [ V_72 ] ;
V_149 = F_114 ( & V_9 -> V_99 ) ;
if ( V_149 == - V_101 )
continue;
if ( V_149 ) {
V_9 -> V_99 . V_100 = 0 ;
F_95 ( & V_27 -> V_11 ,
L_20 , V_149 ) ;
break;
}
F_115 ( & V_9 -> V_136 , & V_192 ) ;
F_116 ( & V_27 -> V_11 ,
L_21 ,
V_169 [ V_72 ] ) ;
break;
}
if ( V_72 == F_90 ( V_169 ) ) {
V_9 -> V_99 . V_100 = 0 ;
F_31 ( & V_27 -> V_11 , L_22
L_23 ) ;
}
F_27 ( & V_97 ) ;
return 0 ;
V_186:
F_89 ( V_9 -> V_138 ) ;
V_184:
for ( V_72 = 0 ; V_72 < F_90 ( V_139 ) ; V_72 ++ )
F_91 ( V_11 , & V_139 [ V_72 ] . V_140 ) ;
for ( V_72 = 0 ; V_72 < F_90 ( V_141 ) ; V_72 ++ )
F_91 ( V_11 , & V_141 [ V_72 ] . V_140 ) ;
for ( V_72 = 0 ; V_72 < F_90 ( V_142 ) ; V_72 ++ )
F_91 ( V_11 , & V_142 [ V_72 ] . V_140 ) ;
for ( V_72 = 0 ; V_72 < F_90 ( V_144 ) ; V_72 ++ )
F_91 ( V_11 , & V_144 [ V_72 ] . V_140 ) ;
for ( V_72 = 0 ; V_72 < F_90 ( V_145 ) ; V_72 ++ )
F_91 ( V_11 , & V_145 [ V_72 ] . V_140 ) ;
for ( V_72 = 0 ; V_72 < F_90 ( V_146 ) ; V_72 ++ )
F_91 ( V_11 , & V_146 [ V_72 ] . V_140 ) ;
if ( V_9 -> V_147 [ 0 ] != NULL )
F_92 ( V_9 -> V_147 [ 0 ] ) ;
if ( V_9 -> V_147 [ 1 ] != NULL )
F_92 ( V_9 -> V_147 [ 1 ] ) ;
V_176:
F_10 ( V_9 ) ;
exit:
return V_149 ;
}
static void F_117 ( struct V_10 * V_11 )
{
struct V_26 * V_27 = F_21 ( V_11 ) ;
struct V_8 * V_9 = F_22 ( V_27 ) ;
int V_72 , V_185 ;
if ( ! ( F_118 ( V_193 , V_9 -> V_194 + V_195 * 300 )
|| ! V_9 -> V_35 ) )
return;
for ( V_72 = 1 ; V_72 < 3 ; V_72 ++ ) {
for ( V_185 = 0 ; V_185 < F_90 ( V_9 -> V_75 ) ; V_185 ++ ) {
V_9 -> V_75 [ V_185 ] [ V_72 ] =
F_24 ( V_27 , V_80 [ V_185 ] [ V_72 ] ) ;
}
V_9 -> V_76 [ V_72 ] =
F_24 ( V_27 , V_79 [ V_72 ] ) ;
}
for ( V_72 = 0 ; V_72 < F_90 ( V_9 -> V_38 ) ; V_72 ++ ) {
if ( ! ( V_9 -> V_177 & ( 1 << V_72 ) ) ) {
continue;
}
V_9 -> V_38 [ V_72 ] =
F_24 ( V_27 , F_36 ( V_72 ) ) << 8 ;
V_9 -> V_38 [ V_72 ] |=
F_24 ( V_27 , F_36 ( V_72 ) + 1 ) ;
}
for ( V_72 = 0 ; V_72 < F_90 ( V_9 -> V_65 ) ; V_72 ++ ) {
if ( ! ( V_9 -> V_183 & ( 1 << V_72 ) ) )
continue;
V_9 -> V_65 [ V_72 ] =
F_24 ( V_27 , F_50 ( V_72 ) ) ;
for ( V_185 = 1 ; V_185 < 5 ; V_185 ++ ) {
V_9 -> V_42 [ V_72 ] [ V_185 ] =
F_24 ( V_27 , V_47 [ V_72 ] [ V_185 ] ) ;
}
V_9 -> V_69 [ V_72 ] =
F_24 ( V_27 , F_51 ( V_72 ) ) ;
for ( V_185 = 0 ; V_185 < 7 ; V_185 ++ ) {
V_9 -> V_73 [ V_72 ] [ V_185 ] =
F_24 ( V_27 , F_55 ( V_72 , V_185 ) ) ;
V_9 -> V_74 [ V_72 ] [ V_185 ] =
F_24 ( V_27 ,
F_58 ( V_72 , V_185 ) ) ;
}
}
for ( V_72 = 0 ; V_72 < F_90 ( V_9 -> V_49 ) ; V_72 ++ )
V_9 -> V_49 [ V_72 ] =
F_24 ( V_27 , V_51 [ V_72 ] ) ;
for ( V_72 = 0 ; V_72 < F_90 ( V_9 -> V_70 ) ; V_72 ++ ) {
V_9 -> V_70 [ V_72 ] =
F_24 ( V_27 , F_52 ( V_72 ) ) ;
}
for ( V_72 = 0 ; V_72 < F_90 ( V_9 -> V_41 ) ; V_72 ++ ) {
if ( ! ( V_9 -> V_178 & ( 1 << V_72 ) ) )
continue;
V_9 -> V_41 [ V_72 ] [ V_196 ] =
F_24 ( V_27 , F_40 ( V_72 , V_196 ) ) ;
V_9 -> V_41 [ V_72 ] [ V_197 ] =
F_24 ( V_27 , F_40 ( V_72 , V_197 ) ) ;
V_9 -> V_40 [ V_72 ] =
F_24 ( V_27 , F_39 ( V_72 ) ) ;
}
V_9 -> V_53 = F_24 ( V_27 , V_60 ) ;
V_9 -> V_67 = F_24 ( V_27 , V_71 ) ;
V_9 -> V_55 = F_24 ( V_27 , V_61 ) ;
V_9 -> V_57 = F_24 ( V_27 , V_62 ) ;
V_9 -> V_59 =
F_24 ( V_27 , V_63 ) ;
V_9 -> V_32 = F_24 ( V_27 , V_33 ) ;
for ( V_72 = 0 ; V_72 < F_90 ( V_9 -> V_25 ) ; V_72 ++ ) {
V_9 -> V_25 [ V_72 ] = F_24 ( V_27 , F_25 ( V_72 ) ) ;
}
V_9 -> V_194 = V_193 ;
}
static struct V_8 * F_14 ( struct V_10 * V_11 )
{
struct V_26 * V_27 = F_21 ( V_11 ) ;
struct V_8 * V_9 = F_22 ( V_27 ) ;
int V_72 ;
F_23 ( & V_9 -> V_31 ) ;
if ( ! ( F_118 ( V_193 , V_9 -> V_198 + V_195 * 2 )
|| ! V_9 -> V_35 ) )
goto V_199;
for ( V_72 = 0 ; V_72 < F_90 ( V_9 -> V_75 ) ; V_72 ++ )
V_9 -> V_75 [ V_72 ] [ V_200 ] =
F_24 ( V_27 , V_80 [ V_72 ] [ V_200 ] ) ;
V_9 -> V_76 [ V_200 ] =
F_24 ( V_27 , V_79 [ V_200 ] ) ;
for ( V_72 = 0 ; V_72 < F_90 ( V_9 -> V_37 ) ; V_72 ++ ) {
if ( ! ( V_9 -> V_177 & ( 1 << V_72 ) ) ) {
continue;
}
V_9 -> V_37 [ V_72 ] =
F_24 ( V_27 , F_119 ( V_72 ) ) << 8 ;
V_9 -> V_37 [ V_72 ] |=
F_24 ( V_27 , F_119 ( V_72 ) + 1 ) ;
}
for ( V_72 = 0 ; V_72 < F_90 ( V_9 -> V_42 ) ; V_72 ++ ) {
if ( ! ( V_9 -> V_183 & ( 1 << V_72 ) ) )
continue;
V_9 -> V_42 [ V_72 ] [ V_43 ] =
F_24 ( V_27 , V_47 [ V_72 ] [ V_43 ] ) ;
}
V_9 -> V_45 =
F_24 ( V_27 , V_201 ) ;
for ( V_72 = 0 ; V_72 < F_90 ( V_9 -> V_41 ) ; V_72 ++ ) {
if ( V_9 -> V_178 & ( 1 << V_72 ) )
V_9 -> V_41 [ V_72 ] [ V_202 ] =
F_24 ( V_27 ,
F_40 ( V_72 , V_202 ) ) ;
}
for ( V_72 = 0 ; V_72 < F_90 ( V_9 -> V_24 ) ; V_72 ++ )
V_9 -> V_24 [ V_72 ] =
F_24 ( V_27 , F_120 ( V_72 ) ) ;
if ( V_9 -> V_181 & 0x01 )
V_9 -> V_19 [ 0 ] = F_24 ( V_27 , V_203 ) ;
if ( V_9 -> V_181 & 0x02 )
V_9 -> V_19 [ 1 ] = F_24 ( V_27 , V_204 ) ;
F_117 ( V_11 ) ;
V_9 -> V_198 = V_193 ;
V_9 -> V_35 = 1 ;
V_199:
F_27 ( & V_9 -> V_31 ) ;
return V_9 ;
}
static T_2 F_24 ( struct V_26 * V_27 , T_1 V_3 )
{
struct V_8 * V_9 = F_22 ( V_27 ) ;
T_2 V_205 = 0xff ;
T_2 V_206 = V_3 >> 8 ;
V_206 |= V_9 -> V_160 & 0xfc ;
if ( V_9 -> V_160 != V_206 ) {
if ( F_121
( V_27 , V_163 , V_206 ) >= 0 )
V_9 -> V_160 = V_206 ;
else {
F_95 ( & V_27 -> V_11 ,
L_24
L_25 ,
V_206 , V_9 -> V_160 , V_3 ) ;
V_205 = 0x0 ;
goto V_199;
}
}
V_205 = F_99 ( V_27 , V_3 & 0xff ) ;
V_199:
return V_205 ;
}
static int F_26 ( struct V_26 * V_27 , T_1 V_3 , T_2 V_207 )
{
struct V_8 * V_9 = F_22 ( V_27 ) ;
int V_205 ;
T_2 V_206 = V_3 >> 8 ;
V_206 |= V_9 -> V_160 & 0xfc ;
if ( V_9 -> V_160 != V_206 ) {
if ( ( V_205 = F_121
( V_27 , V_163 , V_206 ) ) >= 0 )
V_9 -> V_160 = V_206 ;
else {
F_95 ( & V_27 -> V_11 ,
L_24
L_26 ,
V_206 , V_9 -> V_160 , V_3 ) ;
goto V_199;
}
}
V_205 = F_121 ( V_27 , V_3 & 0xff , V_207 ) ;
V_199:
return V_205 ;
}
static int T_9 F_122 ( void )
{
return F_123 ( & V_208 ) ;
}
static void T_10 F_124 ( void )
{
F_125 ( & V_208 ) ;
}
