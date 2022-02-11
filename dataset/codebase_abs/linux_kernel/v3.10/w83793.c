static inline unsigned long F_1 ( T_1 V_1 )
{
if ( ( V_1 >= 0xfff ) || ( V_1 == 0 ) )
return 0 ;
return 1350000UL / V_1 ;
}
static inline T_1 F_2 ( long V_2 )
{
if ( V_2 <= 0 )
return 0x0fff ;
return F_3 ( ( 1350000 + ( V_2 >> 1 ) ) / V_2 , 1 , 0xffe ) ;
}
static inline unsigned long F_4 ( T_2 V_3 )
{
return V_3 * 100 ;
}
static inline T_2 F_5 ( unsigned long V_1 )
{
return F_3 ( ( V_1 + 50 ) / 100 , 0 , 0xff ) ;
}
static inline long F_6 ( T_3 V_3 )
{
return V_3 * 1000 ;
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
unsigned long V_1 ;
int V_21 ;
V_21 = F_18 ( V_14 , 10 , & V_1 ) ;
if ( V_21 )
return V_21 ;
V_9 -> V_15 = V_1 ;
return V_20 ;
}
static T_4
F_19 ( struct V_10 * V_11 , struct V_12 * V_13 , char * V_14 )
{
struct V_8 * V_9 = F_14 ( V_11 ) ;
struct V_16 * V_17 =
F_15 ( V_13 ) ;
int V_22 = V_17 -> V_22 ;
int V_18 = V_17 -> V_18 >> 3 ;
int V_23 = V_17 -> V_18 & 0x07 ;
T_2 V_1 ;
if ( V_22 == V_24 ) {
V_1 = ( V_9 -> V_25 [ V_18 ] >> ( V_23 ) ) & 1 ;
} else {
V_1 = ( V_9 -> V_26 [ V_18 ] >> ( V_23 ) ) & 1 ;
}
return sprintf ( V_14 , L_2 , V_1 ) ;
}
static T_4
F_20 ( struct V_10 * V_11 , struct V_12 * V_13 ,
const char * V_14 , T_5 V_20 )
{
struct V_27 * V_28 = F_21 ( V_11 ) ;
struct V_8 * V_9 = F_22 ( V_28 ) ;
struct V_16 * V_17 =
F_15 ( V_13 ) ;
int V_18 = V_17 -> V_18 >> 3 ;
int V_29 = V_17 -> V_18 & 0x07 ;
T_2 V_30 = 1 << V_29 ;
unsigned long V_1 ;
int V_21 ;
V_21 = F_18 ( V_14 , 10 , & V_1 ) ;
if ( V_21 )
return V_21 ;
if ( V_1 > 1 )
return - V_31 ;
F_23 ( & V_9 -> V_32 ) ;
V_9 -> V_26 [ V_18 ] = F_24 ( V_28 , F_25 ( V_18 ) ) ;
V_9 -> V_26 [ V_18 ] &= ~ V_30 ;
V_9 -> V_26 [ V_18 ] |= V_1 << V_29 ;
F_26 ( V_28 , F_25 ( V_18 ) , V_9 -> V_26 [ V_18 ] ) ;
F_27 ( & V_9 -> V_32 ) ;
return V_20 ;
}
static T_4
F_28 ( struct V_10 * V_11 , struct V_12 * V_13 , char * V_14 )
{
struct V_8 * V_9 = F_14 ( V_11 ) ;
return sprintf ( V_14 , L_2 , ( V_9 -> V_33 >> 1 ) & 0x01 ) ;
}
static T_4
F_29 ( struct V_10 * V_11 , struct V_12 * V_13 ,
const char * V_14 , T_5 V_20 )
{
struct V_27 * V_28 = F_21 ( V_11 ) ;
struct V_8 * V_9 = F_22 ( V_28 ) ;
unsigned long V_1 ;
int V_21 ;
V_21 = F_18 ( V_14 , 10 , & V_1 ) ;
if ( V_21 )
return V_21 ;
if ( V_1 > 1 )
return - V_31 ;
F_23 ( & V_9 -> V_32 ) ;
V_9 -> V_33 = F_24 ( V_28 , V_34 )
& 0xfd ;
V_9 -> V_33 |= V_1 << 1 ;
F_26 ( V_28 , V_34 , V_9 -> V_33 ) ;
F_27 ( & V_9 -> V_32 ) ;
return V_20 ;
}
static T_4
F_30 ( struct V_10 * V_11 ,
struct V_12 * V_13 , const char * V_14 ,
T_5 V_20 )
{
struct V_27 * V_28 = F_21 ( V_11 ) ;
struct V_8 * V_9 = F_22 ( V_28 ) ;
unsigned long V_1 ;
T_2 V_3 ;
int V_21 ;
V_21 = F_18 ( V_14 , 10 , & V_1 ) ;
if ( V_21 )
return V_21 ;
if ( V_1 )
return - V_31 ;
F_23 ( & V_9 -> V_32 ) ;
V_3 = F_24 ( V_28 , V_35 ) ;
F_26 ( V_28 , V_35 , V_3 | 0x80 ) ;
V_9 -> V_36 = 0 ;
F_27 ( & V_9 -> V_32 ) ;
return V_20 ;
}
static T_4
F_31 ( struct V_10 * V_11 , struct V_12 * V_13 , char * V_14 )
{
struct V_16 * V_17 =
F_15 ( V_13 ) ;
int V_22 = V_17 -> V_22 ;
int V_18 = V_17 -> V_18 ;
struct V_8 * V_9 = F_14 ( V_11 ) ;
T_1 V_1 ;
if ( V_22 == V_37 )
V_1 = V_9 -> V_38 [ V_18 ] & 0x0fff ;
else
V_1 = V_9 -> V_39 [ V_18 ] & 0x0fff ;
return sprintf ( V_14 , L_3 , F_1 ( V_1 ) ) ;
}
static T_4
F_32 ( struct V_10 * V_11 , struct V_12 * V_13 ,
const char * V_14 , T_5 V_20 )
{
struct V_16 * V_17 =
F_15 ( V_13 ) ;
int V_18 = V_17 -> V_18 ;
struct V_27 * V_28 = F_21 ( V_11 ) ;
struct V_8 * V_9 = F_22 ( V_28 ) ;
unsigned long V_1 ;
int V_21 ;
V_21 = F_18 ( V_14 , 10 , & V_1 ) ;
if ( V_21 )
return V_21 ;
V_1 = F_2 ( V_1 ) ;
F_23 ( & V_9 -> V_32 ) ;
V_9 -> V_39 [ V_18 ] = V_1 ;
F_26 ( V_28 , F_33 ( V_18 ) ,
( V_1 >> 8 ) & 0xff ) ;
F_26 ( V_28 , F_33 ( V_18 ) + 1 , V_1 & 0xff ) ;
F_27 ( & V_9 -> V_32 ) ;
return V_20 ;
}
static T_4
F_34 ( struct V_10 * V_11 , struct V_12 * V_13 , char * V_14 )
{
struct V_16 * V_17 =
F_15 ( V_13 ) ;
struct V_8 * V_9 = F_14 ( V_11 ) ;
T_1 V_1 ;
int V_22 = V_17 -> V_22 ;
int V_18 = V_17 -> V_18 ;
if ( V_22 == V_40 )
V_1 = F_4 ( V_9 -> V_41 [ V_18 ] ) ;
else
V_1 = ( V_9 -> V_42 [ V_18 ] [ V_22 ] & 0x3f ) << 2 ;
return sprintf ( V_14 , L_1 , V_1 ) ;
}
static T_4
F_35 ( struct V_10 * V_11 , struct V_12 * V_13 ,
const char * V_14 , T_5 V_20 )
{
struct V_27 * V_28 = F_21 ( V_11 ) ;
struct V_8 * V_9 = F_22 ( V_28 ) ;
struct V_16 * V_17 =
F_15 ( V_13 ) ;
int V_22 = V_17 -> V_22 ;
int V_18 = V_17 -> V_18 ;
unsigned long V_1 ;
int V_21 ;
V_21 = F_18 ( V_14 , 10 , & V_1 ) ;
if ( V_21 )
return V_21 ;
F_23 ( & V_9 -> V_32 ) ;
if ( V_22 == V_40 ) {
V_1 = F_5 ( V_1 ) ;
V_9 -> V_41 [ V_18 ] = V_1 ;
F_26 ( V_28 , F_36 ( V_18 ) ,
V_1 ) ;
} else {
V_1 = F_3 ( V_1 , 0 , 0xff ) >> 2 ;
V_9 -> V_42 [ V_18 ] [ V_22 ] =
F_24 ( V_28 , F_37 ( V_18 , V_22 ) ) & 0xc0 ;
V_9 -> V_42 [ V_18 ] [ V_22 ] |= V_1 ;
F_26 ( V_28 , F_37 ( V_18 , V_22 ) ,
V_9 -> V_42 [ V_18 ] [ V_22 ] ) ;
}
F_27 ( & V_9 -> V_32 ) ;
return V_20 ;
}
static T_4
F_38 ( struct V_10 * V_11 , struct V_12 * V_13 , char * V_14 )
{
struct V_16 * V_17 =
F_15 ( V_13 ) ;
int V_22 = V_17 -> V_22 ;
int V_18 = V_17 -> V_18 ;
struct V_8 * V_9 = F_14 ( V_11 ) ;
long V_43 = F_6 ( V_9 -> V_43 [ V_18 ] [ V_22 ] ) ;
if ( V_22 == V_44 && V_18 < 4 ) {
int V_45 = ( ( V_9 -> V_46 >> ( V_18 * 2 ) ) & 0x03 ) * 250 ;
V_43 += V_43 > 0 ? V_45 : - V_45 ;
}
return sprintf ( V_14 , L_4 , V_43 ) ;
}
static T_4
F_39 ( struct V_10 * V_11 , struct V_12 * V_13 ,
const char * V_14 , T_5 V_20 )
{
struct V_16 * V_17 =
F_15 ( V_13 ) ;
int V_22 = V_17 -> V_22 ;
int V_18 = V_17 -> V_18 ;
struct V_27 * V_28 = F_21 ( V_11 ) ;
struct V_8 * V_9 = F_22 ( V_28 ) ;
long V_47 ;
int V_21 ;
V_21 = F_40 ( V_14 , 10 , & V_47 ) ;
if ( V_21 )
return V_21 ;
F_23 ( & V_9 -> V_32 ) ;
V_9 -> V_43 [ V_18 ] [ V_22 ] = F_7 ( V_47 , - 128 , 127 ) ;
F_26 ( V_28 , V_48 [ V_18 ] [ V_22 ] ,
V_9 -> V_43 [ V_18 ] [ V_22 ] ) ;
F_27 ( & V_9 -> V_32 ) ;
return V_20 ;
}
static T_4
F_41 ( struct V_10 * V_11 , struct V_12 * V_13 , char * V_14 )
{
struct V_8 * V_9 = F_14 ( V_11 ) ;
struct V_16 * V_17 =
F_15 ( V_13 ) ;
int V_18 = V_17 -> V_18 ;
T_2 V_49 = ( V_18 < 4 ) ? 0x03 : 0x01 ;
T_2 V_29 = ( V_18 < 4 ) ? ( 2 * V_18 ) : ( V_18 - 4 ) ;
T_2 V_47 ;
V_18 = ( V_18 < 4 ) ? 0 : 1 ;
V_47 = ( V_9 -> V_50 [ V_18 ] >> V_29 ) & V_49 ;
if ( V_47 == 1 )
V_47 = V_18 == 0 ? 3 : 4 ;
else
V_47 = V_51 [ V_47 ] ;
return sprintf ( V_14 , L_1 , V_47 ) ;
}
static T_4
F_42 ( struct V_10 * V_11 , struct V_12 * V_13 ,
const char * V_14 , T_5 V_20 )
{
struct V_27 * V_28 = F_21 ( V_11 ) ;
struct V_8 * V_9 = F_22 ( V_28 ) ;
struct V_16 * V_17 =
F_15 ( V_13 ) ;
int V_18 = V_17 -> V_18 ;
T_2 V_49 = ( V_18 < 4 ) ? 0x03 : 0x01 ;
T_2 V_29 = ( V_18 < 4 ) ? ( 2 * V_18 ) : ( V_18 - 4 ) ;
unsigned long V_1 ;
int V_21 ;
V_21 = F_18 ( V_14 , 10 , & V_1 ) ;
if ( V_21 )
return V_21 ;
if ( ( V_1 == 6 ) && ( V_18 < 4 ) ) {
V_1 -= 3 ;
} else if ( ( V_1 == 3 && V_18 < 4 )
|| ( V_1 == 4 && V_18 >= 4 ) ) {
V_1 = ! ! V_1 ;
} else {
return - V_31 ;
}
V_18 = ( V_18 < 4 ) ? 0 : 1 ;
F_23 ( & V_9 -> V_32 ) ;
V_9 -> V_50 [ V_18 ] =
F_24 ( V_28 , V_52 [ V_18 ] ) ;
V_9 -> V_50 [ V_18 ] &= ~ ( V_49 << V_29 ) ;
V_9 -> V_50 [ V_18 ] |= V_1 << V_29 ;
F_26 ( V_28 , V_52 [ V_18 ] ,
V_9 -> V_50 [ V_18 ] ) ;
F_27 ( & V_9 -> V_32 ) ;
return V_20 ;
}
static T_4
F_43 ( struct V_10 * V_11 , struct V_12 * V_13 , char * V_14 )
{
struct V_16 * V_17 =
F_15 ( V_13 ) ;
int V_22 = V_17 -> V_22 ;
struct V_8 * V_9 = F_14 ( V_11 ) ;
T_6 V_1 = 0 ;
if ( V_22 == V_53 )
V_1 = ( V_9 -> V_54 & 0x3f ) << 2 ;
else if ( V_22 == V_55 )
V_1 = F_4 ( V_9 -> V_56 ) ;
else if ( V_22 == V_57 )
V_1 = F_4 ( V_9 -> V_58 ) ;
else if ( V_22 == V_59 )
V_1 = F_6 ( V_9 -> V_60 & 0x7f ) ;
return sprintf ( V_14 , L_1 , V_1 ) ;
}
static T_4
F_44 ( struct V_10 * V_11 , struct V_12 * V_13 ,
const char * V_14 , T_5 V_20 )
{
struct V_16 * V_17 =
F_15 ( V_13 ) ;
int V_22 = V_17 -> V_22 ;
struct V_27 * V_28 = F_21 ( V_11 ) ;
struct V_8 * V_9 = F_22 ( V_28 ) ;
long V_1 ;
int V_21 ;
V_21 = F_40 ( V_14 , 10 , & V_1 ) ;
if ( V_21 )
return V_21 ;
F_23 ( & V_9 -> V_32 ) ;
if ( V_22 == V_53 ) {
V_9 -> V_54 =
F_24 ( V_28 , V_61 ) & 0xc0 ;
V_9 -> V_54 |= F_3 ( V_1 , 0 , 0xff ) >> 2 ;
F_26 ( V_28 , V_61 ,
V_9 -> V_54 ) ;
} else if ( V_22 == V_55 ) {
V_9 -> V_56 = F_5 ( V_1 ) ;
V_9 -> V_56 += V_9 -> V_56 == 0 ? 1 : 0 ;
F_26 ( V_28 , V_62 ,
V_9 -> V_56 ) ;
} else if ( V_22 == V_57 ) {
V_9 -> V_58 = F_5 ( V_1 ) ;
V_9 -> V_58 += V_9 -> V_58 == 0 ? 1 : 0 ;
F_26 ( V_28 , V_63 ,
V_9 -> V_58 ) ;
} else {
V_9 -> V_60 =
F_24 ( V_28 , V_64 ) & 0x80 ;
V_9 -> V_60 |= F_7 ( V_1 , 0 , 0x7f ) ;
F_26 ( V_28 , V_64 ,
V_9 -> V_60 ) ;
}
F_27 ( & V_9 -> V_32 ) ;
return V_20 ;
}
static T_4
F_45 ( struct V_10 * V_11 , struct V_12 * V_13 , char * V_14 )
{
struct V_16 * V_17 =
F_15 ( V_13 ) ;
int V_22 = V_17 -> V_22 ;
int V_18 = V_17 -> V_18 ;
struct V_8 * V_9 = F_14 ( V_11 ) ;
T_6 V_1 ;
if ( V_22 == V_65 ) {
V_1 = V_9 -> V_66 [ V_18 ] ;
} else if ( V_22 == V_67 ) {
V_1 = ( ( V_9 -> V_68 >> V_18 ) & 0x01 ) + 2 ;
} else if ( V_22 == V_69 ) {
V_1 = F_6 ( V_9 -> V_70 [ V_18 ] & 0x7f ) ;
} else {
V_1 = V_9 -> V_71 [ V_18 >> 1 ] >> ( ( V_18 & 0x01 ) ? 4 : 0 ) ;
V_1 = F_6 ( V_1 & 0x0f ) ;
}
return sprintf ( V_14 , L_1 , V_1 ) ;
}
static T_4
F_46 ( struct V_10 * V_11 , struct V_12 * V_13 ,
const char * V_14 , T_5 V_20 )
{
struct V_16 * V_17 =
F_15 ( V_13 ) ;
int V_22 = V_17 -> V_22 ;
int V_18 = V_17 -> V_18 ;
struct V_27 * V_28 = F_21 ( V_11 ) ;
struct V_8 * V_9 = F_22 ( V_28 ) ;
long V_1 ;
int V_21 ;
V_21 = F_40 ( V_14 , 10 , & V_1 ) ;
if ( V_21 )
return V_21 ;
F_23 ( & V_9 -> V_32 ) ;
if ( V_22 == V_65 ) {
V_1 = F_3 ( V_1 , 0 , 255 ) ;
F_26 ( V_28 , F_47 ( V_18 ) , V_1 ) ;
V_9 -> V_66 [ V_18 ] = V_1 ;
} else if ( V_22 == V_67 ) {
if ( V_1 == 2 || V_1 == 3 ) {
V_9 -> V_68 =
F_24 ( V_28 , V_72 ) ;
if ( V_1 - 2 )
V_9 -> V_68 |= 1 << V_18 ;
else
V_9 -> V_68 &= ~ ( 1 << V_18 ) ;
F_26 ( V_28 , V_72 ,
V_9 -> V_68 ) ;
} else {
F_27 ( & V_9 -> V_32 ) ;
return - V_31 ;
}
} else if ( V_22 == V_69 ) {
V_9 -> V_70 [ V_18 ] =
F_24 ( V_28 , F_48 ( V_18 ) ) ;
V_9 -> V_70 [ V_18 ] &= 0x80 ;
V_9 -> V_70 [ V_18 ] |= F_7 ( V_1 , 0 , 0x7f ) ;
F_26 ( V_28 , F_48 ( V_18 ) ,
V_9 -> V_70 [ V_18 ] ) ;
} else {
int V_73 = V_18 >> 1 ;
T_2 V_29 = ( V_18 & 0x01 ) ? 4 : 0 ;
V_9 -> V_71 [ V_73 ] =
F_24 ( V_28 , F_49 ( V_73 ) ) ;
V_9 -> V_71 [ V_73 ] &= ~ ( 0x0f << V_29 ) ;
V_9 -> V_71 [ V_73 ] |= F_7 ( V_1 , 0 , 0x0f ) << V_29 ;
F_26 ( V_28 , F_49 ( V_73 ) ,
V_9 -> V_71 [ V_73 ] ) ;
}
F_27 ( & V_9 -> V_32 ) ;
return V_20 ;
}
static T_4
F_50 ( struct V_10 * V_11 , struct V_12 * V_13 , char * V_14 )
{
struct V_16 * V_17 =
F_15 ( V_13 ) ;
int V_22 = V_17 -> V_22 ;
int V_18 = V_17 -> V_18 ;
struct V_8 * V_9 = F_14 ( V_11 ) ;
return sprintf ( V_14 , L_1 , ( V_9 -> V_74 [ V_18 ] [ V_22 ] & 0x3f ) << 2 ) ;
}
static T_4
F_51 ( struct V_10 * V_11 , struct V_12 * V_13 ,
const char * V_14 , T_5 V_20 )
{
struct V_27 * V_28 = F_21 ( V_11 ) ;
struct V_8 * V_9 = F_22 ( V_28 ) ;
struct V_16 * V_17 =
F_15 ( V_13 ) ;
int V_22 = V_17 -> V_22 ;
int V_18 = V_17 -> V_18 ;
unsigned long V_1 ;
int V_21 ;
V_21 = F_18 ( V_14 , 10 , & V_1 ) ;
if ( V_21 )
return V_21 ;
V_1 = F_3 ( V_1 , 0 , 0xff ) >> 2 ;
F_23 ( & V_9 -> V_32 ) ;
V_9 -> V_74 [ V_18 ] [ V_22 ] =
F_24 ( V_28 , F_52 ( V_18 , V_22 ) ) & 0xc0 ;
V_9 -> V_74 [ V_18 ] [ V_22 ] |= V_1 ;
F_26 ( V_28 , F_52 ( V_18 , V_22 ) ,
V_9 -> V_74 [ V_18 ] [ V_22 ] ) ;
F_27 ( & V_9 -> V_32 ) ;
return V_20 ;
}
static T_4
F_53 ( struct V_10 * V_11 , struct V_12 * V_13 , char * V_14 )
{
struct V_16 * V_17 =
F_15 ( V_13 ) ;
int V_22 = V_17 -> V_22 ;
int V_18 = V_17 -> V_18 ;
struct V_8 * V_9 = F_14 ( V_11 ) ;
return sprintf ( V_14 , L_4 ,
F_6 ( V_9 -> V_75 [ V_18 ] [ V_22 ] & 0x7f ) ) ;
}
static T_4
F_54 ( struct V_10 * V_11 , struct V_12 * V_13 ,
const char * V_14 , T_5 V_20 )
{
struct V_27 * V_28 = F_21 ( V_11 ) ;
struct V_8 * V_9 = F_22 ( V_28 ) ;
struct V_16 * V_17 =
F_15 ( V_13 ) ;
int V_22 = V_17 -> V_22 ;
int V_18 = V_17 -> V_18 ;
long V_1 ;
int V_21 ;
V_21 = F_40 ( V_14 , 10 , & V_1 ) ;
if ( V_21 )
return V_21 ;
V_1 = F_7 ( V_1 , 0 , 0x7f ) ;
F_23 ( & V_9 -> V_32 ) ;
V_9 -> V_75 [ V_18 ] [ V_22 ] =
F_24 ( V_28 , F_55 ( V_18 , V_22 ) ) & 0x80 ;
V_9 -> V_75 [ V_18 ] [ V_22 ] |= V_1 ;
F_26 ( V_28 , F_55 ( V_18 , V_22 ) ,
V_9 -> V_75 [ V_18 ] [ V_22 ] ) ;
F_27 ( & V_9 -> V_32 ) ;
return V_20 ;
}
static T_4
F_56 ( struct V_10 * V_11 , struct V_12 * V_13 , char * V_14 )
{
struct V_16 * V_17 =
F_15 ( V_13 ) ;
int V_22 = V_17 -> V_22 ;
int V_18 = V_17 -> V_18 ;
struct V_8 * V_9 = F_14 ( V_11 ) ;
T_1 V_1 = V_9 -> V_76 [ V_18 ] [ V_22 ] ;
if ( V_18 < 3 ) {
V_1 <<= 2 ;
V_1 += ( V_9 -> V_77 [ V_22 ] >> ( V_18 * 2 ) ) & 0x3 ;
}
V_1 = V_1 * V_78 [ V_18 ] + V_79 [ V_18 ] ;
return sprintf ( V_14 , L_1 , V_1 ) ;
}
static T_4
F_57 ( struct V_10 * V_11 , struct V_12 * V_13 ,
const char * V_14 , T_5 V_20 )
{
struct V_16 * V_17 =
F_15 ( V_13 ) ;
int V_22 = V_17 -> V_22 ;
int V_18 = V_17 -> V_18 ;
struct V_27 * V_28 = F_21 ( V_11 ) ;
struct V_8 * V_9 = F_22 ( V_28 ) ;
unsigned long V_1 ;
int V_21 ;
V_21 = F_18 ( V_14 , 10 , & V_1 ) ;
if ( V_21 )
return V_21 ;
V_1 = ( V_1 + V_78 [ V_18 ] / 2 ) / V_78 [ V_18 ] ;
F_23 ( & V_9 -> V_32 ) ;
if ( V_18 > 2 ) {
if ( V_22 == 1 || V_22 == 2 )
V_1 -= V_79 [ V_18 ] / V_78 [ V_18 ] ;
V_1 = F_3 ( V_1 , 0 , 255 ) ;
} else {
V_1 = F_3 ( V_1 , 0 , 0x3FF ) ;
V_9 -> V_77 [ V_22 ] =
F_24 ( V_28 , V_80 [ V_22 ] ) ;
V_9 -> V_77 [ V_22 ] &= ~ ( 0x03 << ( 2 * V_18 ) ) ;
V_9 -> V_77 [ V_22 ] |= ( V_1 & 0x03 ) << ( 2 * V_18 ) ;
F_26 ( V_28 , V_80 [ V_22 ] ,
V_9 -> V_77 [ V_22 ] ) ;
V_1 >>= 2 ;
}
V_9 -> V_76 [ V_18 ] [ V_22 ] = V_1 ;
F_26 ( V_28 , V_81 [ V_18 ] [ V_22 ] ,
V_9 -> V_76 [ V_18 ] [ V_22 ] ) ;
F_27 ( & V_9 -> V_32 ) ;
return V_20 ;
}
static void F_58 ( struct V_27 * V_28 )
{
if ( V_82 )
F_26 ( V_28 , V_83 , 0x80 ) ;
F_26 ( V_28 , V_83 ,
F_24 ( V_28 , V_83 ) | 0x01 ) ;
}
static int F_59 ( struct V_8 * V_9 , int V_84 )
{
int V_85 , V_86 ;
V_86 = F_60 ( V_84 , 60 ) ;
if ( V_86 > 255 )
return - V_31 ;
F_23 ( & V_9 -> V_87 ) ;
if ( ! V_9 -> V_28 ) {
V_85 = - V_88 ;
goto V_89;
}
V_9 -> V_90 = V_86 ;
F_26 ( V_9 -> V_28 , V_91 ,
V_9 -> V_90 ) ;
V_85 = V_86 * 60 ;
V_89:
F_27 ( & V_9 -> V_87 ) ;
return V_85 ;
}
static int F_61 ( struct V_8 * V_9 )
{
int V_84 ;
F_23 ( & V_9 -> V_87 ) ;
V_84 = V_9 -> V_90 * 60 ;
F_27 ( & V_9 -> V_87 ) ;
return V_84 ;
}
static int F_62 ( struct V_8 * V_9 )
{
int V_85 = 0 ;
F_23 ( & V_9 -> V_87 ) ;
if ( ! V_9 -> V_28 ) {
V_85 = - V_88 ;
goto V_89;
}
F_26 ( V_9 -> V_28 , V_91 ,
V_9 -> V_90 ) ;
V_89:
F_27 ( & V_9 -> V_87 ) ;
return V_85 ;
}
static int F_63 ( struct V_8 * V_9 )
{
int V_85 = 0 ;
F_23 ( & V_9 -> V_87 ) ;
if ( ! V_9 -> V_28 ) {
V_85 = - V_88 ;
goto V_89;
}
F_26 ( V_9 -> V_28 , V_91 ,
V_9 -> V_90 ) ;
F_26 ( V_9 -> V_28 , V_92 , 0x55 ) ;
V_89:
F_27 ( & V_9 -> V_87 ) ;
return V_85 ;
}
static int F_64 ( struct V_8 * V_9 )
{
int V_85 = 0 ;
F_23 ( & V_9 -> V_87 ) ;
if ( ! V_9 -> V_28 ) {
V_85 = - V_88 ;
goto V_89;
}
F_26 ( V_9 -> V_28 , V_92 , 0xAA ) ;
V_89:
F_27 ( & V_9 -> V_87 ) ;
return V_85 ;
}
static int F_65 ( struct V_93 * V_93 , struct V_94 * V_95 )
{
struct V_8 * V_96 , * V_9 = NULL ;
int V_97 ;
if ( ! F_66 ( & V_98 ) )
return - V_99 ;
F_67 (pos, &watchdog_data_list, list) {
if ( V_96 -> V_100 . V_101 == F_68 ( V_93 ) ) {
V_9 = V_96 ;
break;
}
}
V_97 = F_69 ( 0 , & V_9 -> V_97 ) ;
if ( ! V_97 )
F_70 ( & V_9 -> V_6 ) ;
F_27 ( & V_98 ) ;
if ( V_97 )
return - V_102 ;
F_63 ( V_9 ) ;
V_95 -> V_103 = V_9 ;
return F_71 ( V_93 , V_95 ) ;
}
static int F_72 ( struct V_93 * V_93 , struct V_94 * V_95 )
{
struct V_8 * V_9 = V_95 -> V_103 ;
if ( V_9 -> V_104 ) {
F_64 ( V_9 ) ;
V_9 -> V_104 = 0 ;
} else {
F_62 ( V_9 ) ;
F_73 ( & V_9 -> V_28 -> V_11 ,
L_5 ) ;
}
F_74 ( 0 , & V_9 -> V_97 ) ;
F_23 ( & V_98 ) ;
F_75 ( & V_9 -> V_6 , F_8 ) ;
F_27 ( & V_98 ) ;
return 0 ;
}
static T_4 F_76 ( struct V_94 * V_95 , const char T_7 * V_14 ,
T_5 V_20 , T_8 * V_105 )
{
T_4 V_85 ;
struct V_8 * V_9 = V_95 -> V_103 ;
if ( V_20 ) {
if ( ! V_106 ) {
T_5 V_73 ;
V_9 -> V_104 = 0 ;
for ( V_73 = 0 ; V_73 != V_20 ; V_73 ++ ) {
char V_107 ;
if ( F_77 ( V_107 , V_14 + V_73 ) )
return - V_108 ;
if ( V_107 == 'V' )
V_9 -> V_104 = 1 ;
}
}
V_85 = F_62 ( V_9 ) ;
if ( V_85 < 0 )
return V_85 ;
}
return V_20 ;
}
static long F_78 ( struct V_94 * V_95 , unsigned int V_109 ,
unsigned long V_110 )
{
struct V_111 V_112 = {
. V_113 = V_114 |
V_115 |
V_116 ,
. V_117 = L_6
} ;
int V_1 , V_85 = 0 ;
struct V_8 * V_9 = V_95 -> V_103 ;
switch ( V_109 ) {
case V_118 :
if ( ! V_106 )
V_112 . V_113 |= V_119 ;
if ( F_79 ( ( void T_7 * ) V_110 , & V_112 , sizeof( V_112 ) ) )
V_85 = - V_108 ;
break;
case V_120 :
V_1 = V_9 -> V_121 ? V_116 : 0 ;
V_85 = F_80 ( V_1 , ( int T_7 * ) V_110 ) ;
break;
case V_122 :
V_85 = F_80 ( 0 , ( int T_7 * ) V_110 ) ;
break;
case V_123 :
V_85 = F_62 ( V_9 ) ;
break;
case V_124 :
V_1 = F_61 ( V_9 ) ;
V_85 = F_80 ( V_1 , ( int T_7 * ) V_110 ) ;
break;
case V_125 :
if ( F_77 ( V_1 , ( int T_7 * ) V_110 ) ) {
V_85 = - V_108 ;
break;
}
V_85 = F_59 ( V_9 , V_1 ) ;
if ( V_85 > 0 )
V_85 = F_80 ( V_85 , ( int T_7 * ) V_110 ) ;
break;
case V_126 :
if ( F_77 ( V_1 , ( int T_7 * ) V_110 ) ) {
V_85 = - V_108 ;
break;
}
if ( V_1 & V_127 )
V_85 = F_64 ( V_9 ) ;
else if ( V_1 & V_128 )
V_85 = F_63 ( V_9 ) ;
else
V_85 = - V_31 ;
break;
default:
V_85 = - V_129 ;
}
return V_85 ;
}
static int F_81 ( struct V_130 * V_131 , unsigned long V_132 ,
void * V_133 )
{
struct V_8 * V_9 = NULL ;
if ( V_132 == V_134 || V_132 == V_135 ) {
F_23 ( & V_98 ) ;
F_67 (data, &watchdog_data_list, list) {
if ( V_9 -> V_100 . V_101 )
F_64 ( V_9 ) ;
}
F_27 ( & V_98 ) ;
}
return V_136 ;
}
static int F_82 ( struct V_27 * V_28 )
{
struct V_8 * V_9 = F_22 ( V_28 ) ;
struct V_10 * V_11 = & V_28 -> V_11 ;
int V_73 , V_47 ;
if ( V_9 -> V_100 . V_101 ) {
F_83 ( & V_9 -> V_100 ) ;
if ( V_9 -> V_97 ) {
F_84 ( & V_28 -> V_11 ,
L_7
L_8 ) ;
F_64 ( V_9 ) ;
}
F_23 ( & V_98 ) ;
F_85 ( & V_9 -> V_137 ) ;
F_27 ( & V_98 ) ;
F_23 ( & V_9 -> V_87 ) ;
V_9 -> V_28 = NULL ;
F_27 ( & V_9 -> V_87 ) ;
}
V_47 = F_24 ( V_28 , V_83 ) ;
F_26 ( V_28 , V_83 , V_47 & ~ 0x04 ) ;
F_86 ( & V_138 ) ;
F_87 ( V_9 -> V_139 ) ;
for ( V_73 = 0 ; V_73 < F_88 ( V_140 ) ; V_73 ++ )
F_89 ( V_11 ,
& V_140 [ V_73 ] . V_141 ) ;
for ( V_73 = 0 ; V_73 < F_88 ( V_142 ) ; V_73 ++ )
F_89 ( V_11 , & V_142 [ V_73 ] . V_141 ) ;
for ( V_73 = 0 ; V_73 < F_88 ( V_143 ) ; V_73 ++ )
F_89 ( V_11 , & V_143 [ V_73 ] . V_141 ) ;
F_89 ( V_11 , & V_144 ) ;
for ( V_73 = 0 ; V_73 < F_88 ( V_145 ) ; V_73 ++ )
F_89 ( V_11 , & V_145 [ V_73 ] . V_141 ) ;
for ( V_73 = 0 ; V_73 < F_88 ( V_146 ) ; V_73 ++ )
F_89 ( V_11 , & V_146 [ V_73 ] . V_141 ) ;
for ( V_73 = 0 ; V_73 < F_88 ( V_147 ) ; V_73 ++ )
F_89 ( V_11 , & V_147 [ V_73 ] . V_141 ) ;
if ( V_9 -> V_148 [ 0 ] != NULL )
F_90 ( V_9 -> V_148 [ 0 ] ) ;
if ( V_9 -> V_148 [ 1 ] != NULL )
F_90 ( V_9 -> V_148 [ 1 ] ) ;
F_23 ( & V_98 ) ;
F_75 ( & V_9 -> V_6 , F_8 ) ;
F_27 ( & V_98 ) ;
return 0 ;
}
static int
F_91 ( struct V_27 * V_28 )
{
int V_73 , V_149 , V_21 ;
int V_150 = V_28 -> V_151 ;
T_2 V_47 ;
struct V_152 * V_153 = V_28 -> V_153 ;
struct V_8 * V_9 = F_22 ( V_28 ) ;
V_149 = F_92 ( V_153 ) ;
if ( V_154 [ 0 ] == V_149 && V_154 [ 1 ] == V_150 ) {
for ( V_73 = 2 ; V_73 <= 3 ; V_73 ++ ) {
if ( V_154 [ V_73 ] < 0x48
|| V_154 [ V_73 ] > 0x4f ) {
F_93 ( & V_28 -> V_11 ,
L_9
L_10 ,
V_154 [ V_73 ] ) ;
V_21 = - V_31 ;
goto V_155;
}
}
F_26 ( V_28 , V_156 ,
( V_154 [ 2 ] & 0x07 ) |
( ( V_154 [ 3 ] & 0x07 ) << 4 ) ) ;
}
V_47 = F_24 ( V_28 , V_156 ) ;
if ( ! ( V_47 & 0x08 ) )
V_9 -> V_148 [ 0 ] = F_94 ( V_153 , 0x48 + ( V_47 & 0x7 ) ) ;
if ( ! ( V_47 & 0x80 ) ) {
if ( ( V_9 -> V_148 [ 0 ] != NULL )
&& ( ( V_47 & 0x7 ) == ( ( V_47 >> 4 ) & 0x7 ) ) ) {
F_93 ( & V_28 -> V_11 ,
L_11
L_12 , V_9 -> V_148 [ 0 ] -> V_151 ) ;
V_21 = - V_88 ;
goto V_157;
}
V_9 -> V_148 [ 1 ] = F_94 ( V_153 ,
0x48 + ( ( V_47 >> 4 ) & 0x7 ) ) ;
}
return 0 ;
V_157:
if ( V_9 -> V_148 [ 0 ] != NULL )
F_90 ( V_9 -> V_148 [ 0 ] ) ;
V_155:
return V_21 ;
}
static int F_95 ( struct V_27 * V_28 ,
struct V_158 * V_159 )
{
T_2 V_47 , V_160 , V_161 ;
struct V_152 * V_153 = V_28 -> V_153 ;
unsigned short V_150 = V_28 -> V_151 ;
if ( ! F_96 ( V_153 , V_162 ) )
return - V_88 ;
V_160 = F_97 ( V_28 , V_163 ) ;
V_47 = V_160 & 0x80 ? 0x5c : 0xa3 ;
if ( V_47 != F_97 ( V_28 , V_164 ) ) {
F_98 ( L_13 ) ;
return - V_88 ;
}
if ( ( V_160 & 0x07 ) == 0
&& F_97 ( V_28 , V_165 ) !=
( V_150 << 1 ) ) {
F_98 ( L_14 ) ;
return - V_88 ;
}
V_161 = F_97 ( V_28 , V_166 ) ;
if ( V_161 != 0x7b )
return - V_88 ;
F_99 ( V_159 -> type , L_15 , V_167 ) ;
return 0 ;
}
static int F_100 ( struct V_27 * V_28 ,
const struct V_168 * V_149 )
{
struct V_10 * V_11 = & V_28 -> V_11 ;
const int V_169 [] = { V_170 , 212 , 213 , 214 , 215 } ;
struct V_8 * V_9 ;
int V_73 , V_47 , V_1 , V_21 ;
int V_171 = F_88 ( V_145 ) / 7 ;
int V_172 = F_88 ( V_146 ) / 5 ;
int V_173 = F_88 ( V_147 ) / 6 ;
V_9 = F_101 ( sizeof( struct V_8 ) , V_174 ) ;
if ( ! V_9 ) {
V_21 = - V_175 ;
goto exit;
}
F_102 ( V_28 , V_9 ) ;
V_9 -> V_160 = F_97 ( V_28 , V_163 ) ;
F_103 ( & V_9 -> V_32 ) ;
F_103 ( & V_9 -> V_87 ) ;
F_104 ( & V_9 -> V_137 ) ;
F_105 ( & V_9 -> V_6 ) ;
V_9 -> V_28 = V_28 ;
V_21 = F_91 ( V_28 ) ;
if ( V_21 )
goto V_176;
F_58 ( V_28 ) ;
V_9 -> V_177 = 0x1f ;
V_9 -> V_178 = 0x07 ;
V_47 = F_24 ( V_28 , V_179 ) ;
V_1 = F_24 ( V_28 , V_180 ) ;
if ( V_47 & 0x80 ) {
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
if ( ! ( V_47 & 0x40 ) && ( V_1 & 0x04 ) ) {
V_9 -> V_177 |= 0x80 ;
V_9 -> V_178 |= 0x80 ;
}
}
if ( ! ( V_47 & 0x29 ) )
V_9 -> V_181 |= 0x1 ;
if ( 0x08 == ( V_47 & 0x0c ) ) {
if ( V_1 & 0x08 )
V_9 -> V_177 |= 0x100 ;
if ( V_1 & 0x10 )
V_9 -> V_177 |= 0x200 ;
}
if ( 0x20 == ( V_47 & 0x30 ) ) {
if ( V_1 & 0x20 )
V_9 -> V_177 |= 0x400 ;
if ( V_1 & 0x40 )
V_9 -> V_177 |= 0x800 ;
}
if ( ( V_47 & 0x01 ) && ( V_1 & 0x04 ) ) {
V_9 -> V_177 |= 0x80 ;
V_9 -> V_178 |= 0x80 ;
}
V_47 = F_24 ( V_28 , V_182 ) ;
if ( ( V_47 & 0x01 ) && ( V_1 & 0x08 ) ) {
V_9 -> V_177 |= 0x100 ;
}
if ( ( V_47 & 0x02 ) && ( V_1 & 0x10 ) ) {
V_9 -> V_177 |= 0x200 ;
}
if ( ( V_47 & 0x04 ) && ( V_1 & 0x20 ) ) {
V_9 -> V_177 |= 0x400 ;
}
if ( ( V_47 & 0x08 ) && ( V_1 & 0x40 ) ) {
V_9 -> V_177 |= 0x800 ;
}
V_47 = F_24 ( V_28 , V_52 [ 0 ] ) ;
if ( V_47 & 0x01 )
V_9 -> V_183 |= 0x01 ;
if ( V_47 & 0x04 )
V_9 -> V_183 |= 0x02 ;
if ( V_47 & 0x10 )
V_9 -> V_183 |= 0x04 ;
if ( V_47 & 0x40 )
V_9 -> V_183 |= 0x08 ;
V_47 = F_24 ( V_28 , V_52 [ 1 ] ) ;
if ( V_47 & 0x01 )
V_9 -> V_183 |= 0x10 ;
if ( V_47 & 0x02 )
V_9 -> V_183 |= 0x20 ;
for ( V_73 = 0 ; V_73 < F_88 ( V_140 ) ; V_73 ++ ) {
V_21 = F_106 ( V_11 ,
& V_140 [ V_73 ] . V_141 ) ;
if ( V_21 )
goto V_184;
}
for ( V_73 = 0 ; V_73 < F_88 ( V_143 ) ; V_73 ++ ) {
if ( ! ( V_9 -> V_181 & ( 1 << V_73 ) ) )
continue;
V_21 = F_106 ( V_11 , & V_143 [ V_73 ] . V_141 ) ;
if ( V_21 )
goto V_184;
}
if ( V_9 -> V_181 ) {
V_9 -> V_15 = F_107 () ;
V_21 = F_106 ( V_11 , & V_144 ) ;
if ( V_21 )
goto V_184;
}
for ( V_73 = 0 ; V_73 < F_88 ( V_142 ) ; V_73 ++ ) {
V_21 = F_106 ( V_11 , & V_142 [ V_73 ] . V_141 ) ;
if ( V_21 )
goto V_184;
}
for ( V_73 = 0 ; V_73 < 6 ; V_73 ++ ) {
int V_185 ;
if ( ! ( V_9 -> V_183 & ( 1 << V_73 ) ) )
continue;
for ( V_185 = 0 ; V_185 < V_173 ; V_185 ++ ) {
V_21 = F_106 ( V_11 ,
& V_147 [ ( V_73 ) * V_173
+ V_185 ] . V_141 ) ;
if ( V_21 )
goto V_184;
}
}
for ( V_73 = 5 ; V_73 < 12 ; V_73 ++ ) {
int V_185 ;
if ( ! ( V_9 -> V_177 & ( 1 << V_73 ) ) )
continue;
for ( V_185 = 0 ; V_185 < V_171 ; V_185 ++ ) {
V_21 = F_106 ( V_11 ,
& V_145 [ ( V_73 - 5 ) * V_171
+ V_185 ] . V_141 ) ;
if ( V_21 )
goto V_184;
}
}
for ( V_73 = 3 ; V_73 < 8 ; V_73 ++ ) {
int V_185 ;
if ( ! ( V_9 -> V_178 & ( 1 << V_73 ) ) )
continue;
for ( V_185 = 0 ; V_185 < V_172 ; V_185 ++ ) {
V_21 = F_106 ( V_11 ,
& V_146 [ ( V_73 - 3 ) * V_172
+ V_185 ] . V_141 ) ;
if ( V_21 )
goto V_184;
}
}
V_9 -> V_139 = F_108 ( V_11 ) ;
if ( F_109 ( V_9 -> V_139 ) ) {
V_21 = F_110 ( V_9 -> V_139 ) ;
goto V_184;
}
V_21 = F_111 ( & V_138 ) ;
if ( V_21 != 0 ) {
F_93 ( & V_28 -> V_11 ,
L_16 , V_21 ) ;
goto V_186;
}
V_47 = F_24 ( V_28 , V_83 ) ;
F_26 ( V_28 , V_83 , V_47 | 0x04 ) ;
V_9 -> V_90 = V_84 ;
V_9 -> V_121 =
F_24 ( V_9 -> V_28 , V_187 ) & 0x01 ;
F_64 ( V_9 ) ;
F_23 ( & V_98 ) ;
for ( V_73 = 0 ; V_73 < F_88 ( V_169 ) ; V_73 ++ ) {
snprintf ( V_9 -> V_188 , sizeof( V_9 -> V_188 ) ,
L_17 , ( V_73 == 0 ) ? '\0' : ( '0' + V_73 ) ) ;
V_9 -> V_100 . V_189 = V_9 -> V_188 ;
V_9 -> V_100 . V_190 = & V_191 ;
V_9 -> V_100 . V_101 = V_169 [ V_73 ] ;
V_21 = F_112 ( & V_9 -> V_100 ) ;
if ( V_21 == - V_102 )
continue;
if ( V_21 ) {
V_9 -> V_100 . V_101 = 0 ;
F_93 ( & V_28 -> V_11 ,
L_18 , V_21 ) ;
break;
}
F_113 ( & V_9 -> V_137 , & V_192 ) ;
F_114 ( & V_28 -> V_11 ,
L_19 ,
V_169 [ V_73 ] ) ;
break;
}
if ( V_73 == F_88 ( V_169 ) ) {
V_9 -> V_100 . V_101 = 0 ;
F_84 ( & V_28 -> V_11 ,
L_20 ) ;
}
F_27 ( & V_98 ) ;
return 0 ;
V_186:
F_87 ( V_9 -> V_139 ) ;
V_184:
for ( V_73 = 0 ; V_73 < F_88 ( V_140 ) ; V_73 ++ )
F_89 ( V_11 , & V_140 [ V_73 ] . V_141 ) ;
for ( V_73 = 0 ; V_73 < F_88 ( V_142 ) ; V_73 ++ )
F_89 ( V_11 , & V_142 [ V_73 ] . V_141 ) ;
for ( V_73 = 0 ; V_73 < F_88 ( V_143 ) ; V_73 ++ )
F_89 ( V_11 , & V_143 [ V_73 ] . V_141 ) ;
for ( V_73 = 0 ; V_73 < F_88 ( V_145 ) ; V_73 ++ )
F_89 ( V_11 , & V_145 [ V_73 ] . V_141 ) ;
for ( V_73 = 0 ; V_73 < F_88 ( V_146 ) ; V_73 ++ )
F_89 ( V_11 , & V_146 [ V_73 ] . V_141 ) ;
for ( V_73 = 0 ; V_73 < F_88 ( V_147 ) ; V_73 ++ )
F_89 ( V_11 , & V_147 [ V_73 ] . V_141 ) ;
if ( V_9 -> V_148 [ 0 ] != NULL )
F_90 ( V_9 -> V_148 [ 0 ] ) ;
if ( V_9 -> V_148 [ 1 ] != NULL )
F_90 ( V_9 -> V_148 [ 1 ] ) ;
V_176:
F_10 ( V_9 ) ;
exit:
return V_21 ;
}
static void F_115 ( struct V_10 * V_11 )
{
struct V_27 * V_28 = F_21 ( V_11 ) ;
struct V_8 * V_9 = F_22 ( V_28 ) ;
int V_73 , V_185 ;
if ( ! ( F_116 ( V_193 , V_9 -> V_194 + V_195 * 300 )
|| ! V_9 -> V_36 ) )
return;
for ( V_73 = 1 ; V_73 < 3 ; V_73 ++ ) {
for ( V_185 = 0 ; V_185 < F_88 ( V_9 -> V_76 ) ; V_185 ++ ) {
V_9 -> V_76 [ V_185 ] [ V_73 ] =
F_24 ( V_28 , V_81 [ V_185 ] [ V_73 ] ) ;
}
V_9 -> V_77 [ V_73 ] =
F_24 ( V_28 , V_80 [ V_73 ] ) ;
}
for ( V_73 = 0 ; V_73 < F_88 ( V_9 -> V_39 ) ; V_73 ++ ) {
if ( ! ( V_9 -> V_177 & ( 1 << V_73 ) ) )
continue;
V_9 -> V_39 [ V_73 ] =
F_24 ( V_28 , F_33 ( V_73 ) ) << 8 ;
V_9 -> V_39 [ V_73 ] |=
F_24 ( V_28 , F_33 ( V_73 ) + 1 ) ;
}
for ( V_73 = 0 ; V_73 < F_88 ( V_9 -> V_66 ) ; V_73 ++ ) {
if ( ! ( V_9 -> V_183 & ( 1 << V_73 ) ) )
continue;
V_9 -> V_66 [ V_73 ] =
F_24 ( V_28 , F_47 ( V_73 ) ) ;
for ( V_185 = 1 ; V_185 < 5 ; V_185 ++ ) {
V_9 -> V_43 [ V_73 ] [ V_185 ] =
F_24 ( V_28 , V_48 [ V_73 ] [ V_185 ] ) ;
}
V_9 -> V_70 [ V_73 ] =
F_24 ( V_28 , F_48 ( V_73 ) ) ;
for ( V_185 = 0 ; V_185 < 7 ; V_185 ++ ) {
V_9 -> V_74 [ V_73 ] [ V_185 ] =
F_24 ( V_28 , F_52 ( V_73 , V_185 ) ) ;
V_9 -> V_75 [ V_73 ] [ V_185 ] =
F_24 ( V_28 ,
F_55 ( V_73 , V_185 ) ) ;
}
}
for ( V_73 = 0 ; V_73 < F_88 ( V_9 -> V_50 ) ; V_73 ++ )
V_9 -> V_50 [ V_73 ] =
F_24 ( V_28 , V_52 [ V_73 ] ) ;
for ( V_73 = 0 ; V_73 < F_88 ( V_9 -> V_71 ) ; V_73 ++ ) {
V_9 -> V_71 [ V_73 ] =
F_24 ( V_28 , F_49 ( V_73 ) ) ;
}
for ( V_73 = 0 ; V_73 < F_88 ( V_9 -> V_42 ) ; V_73 ++ ) {
if ( ! ( V_9 -> V_178 & ( 1 << V_73 ) ) )
continue;
V_9 -> V_42 [ V_73 ] [ V_196 ] =
F_24 ( V_28 , F_37 ( V_73 , V_196 ) ) ;
V_9 -> V_42 [ V_73 ] [ V_197 ] =
F_24 ( V_28 , F_37 ( V_73 , V_197 ) ) ;
V_9 -> V_41 [ V_73 ] =
F_24 ( V_28 , F_36 ( V_73 ) ) ;
}
V_9 -> V_54 = F_24 ( V_28 , V_61 ) ;
V_9 -> V_68 = F_24 ( V_28 , V_72 ) ;
V_9 -> V_56 = F_24 ( V_28 , V_62 ) ;
V_9 -> V_58 = F_24 ( V_28 , V_63 ) ;
V_9 -> V_60 =
F_24 ( V_28 , V_64 ) ;
V_9 -> V_33 = F_24 ( V_28 , V_34 ) ;
for ( V_73 = 0 ; V_73 < F_88 ( V_9 -> V_26 ) ; V_73 ++ )
V_9 -> V_26 [ V_73 ] = F_24 ( V_28 , F_25 ( V_73 ) ) ;
V_9 -> V_194 = V_193 ;
}
static struct V_8 * F_14 ( struct V_10 * V_11 )
{
struct V_27 * V_28 = F_21 ( V_11 ) ;
struct V_8 * V_9 = F_22 ( V_28 ) ;
int V_73 ;
F_23 ( & V_9 -> V_32 ) ;
if ( ! ( F_116 ( V_193 , V_9 -> V_198 + V_195 * 2 )
|| ! V_9 -> V_36 ) )
goto V_199;
for ( V_73 = 0 ; V_73 < F_88 ( V_9 -> V_76 ) ; V_73 ++ )
V_9 -> V_76 [ V_73 ] [ V_200 ] =
F_24 ( V_28 , V_81 [ V_73 ] [ V_200 ] ) ;
V_9 -> V_77 [ V_200 ] =
F_24 ( V_28 , V_80 [ V_200 ] ) ;
for ( V_73 = 0 ; V_73 < F_88 ( V_9 -> V_38 ) ; V_73 ++ ) {
if ( ! ( V_9 -> V_177 & ( 1 << V_73 ) ) )
continue;
V_9 -> V_38 [ V_73 ] =
F_24 ( V_28 , F_117 ( V_73 ) ) << 8 ;
V_9 -> V_38 [ V_73 ] |=
F_24 ( V_28 , F_117 ( V_73 ) + 1 ) ;
}
for ( V_73 = 0 ; V_73 < F_88 ( V_9 -> V_43 ) ; V_73 ++ ) {
if ( ! ( V_9 -> V_183 & ( 1 << V_73 ) ) )
continue;
V_9 -> V_43 [ V_73 ] [ V_44 ] =
F_24 ( V_28 , V_48 [ V_73 ] [ V_44 ] ) ;
}
V_9 -> V_46 =
F_24 ( V_28 , V_201 ) ;
for ( V_73 = 0 ; V_73 < F_88 ( V_9 -> V_42 ) ; V_73 ++ ) {
if ( V_9 -> V_178 & ( 1 << V_73 ) )
V_9 -> V_42 [ V_73 ] [ V_202 ] =
F_24 ( V_28 ,
F_37 ( V_73 , V_202 ) ) ;
}
for ( V_73 = 0 ; V_73 < F_88 ( V_9 -> V_25 ) ; V_73 ++ )
V_9 -> V_25 [ V_73 ] =
F_24 ( V_28 , F_118 ( V_73 ) ) ;
if ( V_9 -> V_181 & 0x01 )
V_9 -> V_19 [ 0 ] = F_24 ( V_28 , V_203 ) ;
if ( V_9 -> V_181 & 0x02 )
V_9 -> V_19 [ 1 ] = F_24 ( V_28 , V_204 ) ;
F_115 ( V_11 ) ;
V_9 -> V_198 = V_193 ;
V_9 -> V_36 = 1 ;
V_199:
F_27 ( & V_9 -> V_32 ) ;
return V_9 ;
}
static T_2 F_24 ( struct V_27 * V_28 , T_1 V_3 )
{
struct V_8 * V_9 = F_22 ( V_28 ) ;
T_2 V_205 = 0xff ;
T_2 V_206 = V_3 >> 8 ;
V_206 |= V_9 -> V_160 & 0xfc ;
if ( V_9 -> V_160 != V_206 ) {
if ( F_119
( V_28 , V_163 , V_206 ) >= 0 )
V_9 -> V_160 = V_206 ;
else {
F_93 ( & V_28 -> V_11 ,
L_21
L_22 ,
V_206 , V_9 -> V_160 , V_3 ) ;
V_205 = 0x0 ;
goto V_199;
}
}
V_205 = F_97 ( V_28 , V_3 & 0xff ) ;
V_199:
return V_205 ;
}
static int F_26 ( struct V_27 * V_28 , T_1 V_3 , T_2 V_207 )
{
struct V_8 * V_9 = F_22 ( V_28 ) ;
int V_205 ;
T_2 V_206 = V_3 >> 8 ;
V_206 |= V_9 -> V_160 & 0xfc ;
if ( V_9 -> V_160 != V_206 ) {
V_205 = F_119 ( V_28 , V_163 ,
V_206 ) ;
if ( V_205 < 0 ) {
F_93 ( & V_28 -> V_11 ,
L_21
L_23 ,
V_206 , V_9 -> V_160 , V_3 ) ;
goto V_199;
}
V_9 -> V_160 = V_206 ;
}
V_205 = F_119 ( V_28 , V_3 & 0xff , V_207 ) ;
V_199:
return V_205 ;
}
