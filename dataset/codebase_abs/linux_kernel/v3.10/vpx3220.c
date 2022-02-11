static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static inline struct V_2 * F_3 ( struct V_4 * V_5 )
{
return & F_2 ( V_5 -> V_6 , struct V_1 , V_7 ) -> V_3 ;
}
static inline int F_4 ( struct V_2 * V_3 , T_1 V_8 , T_1 V_9 )
{
struct V_10 * V_11 = F_5 ( V_3 ) ;
struct V_1 * V_12 = F_6 ( V_11 ) ;
V_12 -> V_8 [ V_8 ] = V_9 ;
return F_7 ( V_11 , V_8 , V_9 ) ;
}
static inline int F_8 ( struct V_2 * V_3 , T_1 V_8 )
{
struct V_10 * V_11 = F_5 ( V_3 ) ;
return F_9 ( V_11 , V_8 ) ;
}
static int F_10 ( struct V_2 * V_3 )
{
unsigned char V_13 ;
unsigned int V_14 ;
for ( V_14 = 0 ; V_14 < V_15 ; V_14 ++ ) {
V_13 = F_8 ( V_3 , 0x29 ) ;
if ( ! ( V_13 & 4 ) )
return 0 ;
F_11 ( 10 ) ;
if ( F_12 () )
F_13 () ;
}
return - 1 ;
}
static int F_14 ( struct V_2 * V_3 , T_1 V_16 , T_2 V_17 )
{
struct V_10 * V_11 = F_5 ( V_3 ) ;
if ( F_15 ( V_11 , 0x27 , F_16 ( V_16 ) ) == - 1 ) {
F_17 ( 1 , V_18 , V_3 , L_1 , V_19 ) ;
return - 1 ;
}
if ( F_10 ( V_3 ) < 0 )
return - 1 ;
if ( F_15 ( V_11 , 0x28 , F_16 ( V_17 ) ) == - 1 ) {
F_17 ( 1 , V_18 , V_3 , L_1 , V_19 ) ;
return - 1 ;
}
return 0 ;
}
static T_2 F_18 ( struct V_2 * V_3 , T_2 V_16 )
{
struct V_10 * V_11 = F_5 ( V_3 ) ;
T_3 V_17 ;
if ( F_15 ( V_11 , 0x26 , F_16 ( V_16 ) ) == - 1 ) {
F_17 ( 1 , V_18 , V_3 , L_1 , V_19 ) ;
return - 1 ;
}
if ( F_10 ( V_3 ) < 0 )
return - 1 ;
V_17 = F_19 ( V_11 , 0x28 ) ;
if ( V_17 == - 1 ) {
F_17 ( 1 , V_18 , V_3 , L_1 , V_19 ) ;
return - 1 ;
}
return F_16 ( V_17 ) ;
}
static int F_20 ( struct V_2 * V_3 , const T_1 * V_17 , unsigned int V_20 )
{
T_1 V_8 ;
int V_21 = - 1 ;
while ( V_20 >= 2 ) {
V_8 = * V_17 ++ ;
V_21 = F_4 ( V_3 , V_8 , * V_17 ++ ) ;
if ( V_21 < 0 )
break;
V_20 -= 2 ;
}
return V_21 ;
}
static int F_21 ( struct V_2 * V_3 ,
const T_2 * V_17 , unsigned int V_20 )
{
T_1 V_8 ;
int V_21 = 0 ;
while ( V_20 > 1 ) {
V_8 = * V_17 ++ ;
V_21 |= F_14 ( V_3 , V_8 , * V_17 ++ ) ;
V_20 -= 2 ;
}
return V_21 ;
}
static int F_22 ( struct V_2 * V_3 , T_4 V_22 )
{
struct V_1 * V_12 = F_1 ( V_3 ) ;
F_20 ( V_3 , V_23 , sizeof( V_23 ) ) ;
F_21 ( V_3 , V_24 , sizeof( V_24 ) >> 1 ) ;
if ( V_12 -> V_25 & V_26 )
F_21 ( V_3 , V_27 , sizeof( V_27 ) >> 1 ) ;
else if ( V_12 -> V_25 & V_28 )
F_21 ( V_3 , V_29 , sizeof( V_29 ) >> 1 ) ;
else if ( V_12 -> V_25 & V_30 )
F_21 ( V_3 , V_31 , sizeof( V_31 ) >> 1 ) ;
else
F_21 ( V_3 , V_29 , sizeof( V_29 ) >> 1 ) ;
return 0 ;
}
static int F_23 ( struct V_2 * V_3 , T_4 * V_32 , T_5 * V_33 )
{
int V_34 = V_35 , V_13 ;
T_5 V_36 = 0 ;
V_13 = F_18 ( V_3 , 0x0f3 ) ;
F_17 ( 1 , V_18 , V_3 , L_2 , V_13 ) ;
if ( V_13 < 0 )
return V_13 ;
if ( ( V_13 & 0x20 ) == 0 ) {
V_34 = 0 ;
switch ( V_13 & 0x18 ) {
case 0x00 :
case 0x10 :
case 0x14 :
case 0x18 :
V_36 = V_28 ;
break;
case 0x08 :
V_36 = V_30 ;
break;
case 0x04 :
case 0x0c :
case 0x1c :
V_36 = V_26 ;
break;
}
}
if ( V_33 )
* V_33 = V_36 ;
if ( V_32 )
* V_32 = V_34 ;
return 0 ;
}
static int F_24 ( struct V_2 * V_3 , T_5 * V_36 )
{
F_17 ( 1 , V_18 , V_3 , L_3 ) ;
return F_23 ( V_3 , NULL , V_36 ) ;
}
static int F_25 ( struct V_2 * V_3 , T_4 * V_13 )
{
F_17 ( 1 , V_18 , V_3 , L_4 ) ;
return F_23 ( V_3 , V_13 , NULL ) ;
}
static int F_26 ( struct V_2 * V_3 , T_5 V_36 )
{
struct V_1 * V_12 = F_1 ( V_3 ) ;
int V_37 ;
V_37 = F_18 ( V_3 , 0xf2 ) ;
F_17 ( 1 , V_18 , V_3 , L_5 , ( unsigned long long ) V_36 ) ;
if ( V_36 & V_26 ) {
F_21 ( V_3 , V_27 , sizeof( V_27 ) >> 1 ) ;
F_17 ( 1 , V_18 , V_3 , L_6 ) ;
} else if ( V_36 & V_28 ) {
F_21 ( V_3 , V_29 , sizeof( V_29 ) >> 1 ) ;
F_17 ( 1 , V_18 , V_3 , L_7 ) ;
} else if ( V_36 & V_30 ) {
F_21 ( V_3 , V_31 , sizeof( V_31 ) >> 1 ) ;
F_17 ( 1 , V_18 , V_3 , L_8 ) ;
} else {
return - V_38 ;
}
V_12 -> V_25 = V_36 ;
F_14 ( V_3 , 0xf2 , V_37 | 0x0010 ) ;
F_11 ( 10 ) ;
return 0 ;
}
static int F_27 ( struct V_2 * V_3 ,
T_4 V_39 , T_4 V_40 , T_4 V_41 )
{
int V_17 ;
const int V_42 [ 3 ] [ 2 ] = {
{ 0x0c , 0 } ,
{ 0x0d , 0 } ,
{ 0x0e , 1 }
} ;
if ( V_39 > 2 )
return - V_38 ;
F_17 ( 1 , V_18 , V_3 , L_9 , V_43 [ V_39 ] ) ;
F_4 ( V_3 , 0x33 , V_42 [ V_39 ] [ 0 ] ) ;
V_17 = F_18 ( V_3 , 0xf2 ) & ~ ( 0x0020 ) ;
if ( V_17 < 0 )
return V_17 ;
F_14 ( V_3 , 0xf2 ,
V_17 | ( V_42 [ V_39 ] [ 1 ] << 5 ) | 0x0010 ) ;
F_11 ( 10 ) ;
return 0 ;
}
static int F_28 ( struct V_2 * V_3 , int V_44 )
{
F_17 ( 1 , V_18 , V_3 , L_10 , V_44 ? L_11 : L_12 ) ;
F_4 ( V_3 , 0xf2 , ( V_44 ? 0x1b : 0x00 ) ) ;
return 0 ;
}
static int F_29 ( struct V_4 * V_5 )
{
struct V_2 * V_3 = F_3 ( V_5 ) ;
switch ( V_5 -> V_45 ) {
case V_46 :
F_4 ( V_3 , 0xe6 , V_5 -> V_22 ) ;
return 0 ;
case V_47 :
F_4 ( V_3 , 0xe7 , V_5 -> V_22 + 192 ) ;
return 0 ;
case V_48 :
F_14 ( V_3 , 0xa0 , V_5 -> V_22 ) ;
return 0 ;
case V_49 :
F_14 ( V_3 , 0x1c , V_5 -> V_22 ) ;
return 0 ;
}
return - V_38 ;
}
static int F_30 ( struct V_2 * V_3 , struct V_50 * V_51 )
{
struct V_1 * V_12 = F_1 ( V_3 ) ;
struct V_10 * V_11 = F_5 ( V_3 ) ;
return F_31 ( V_11 , V_51 , V_12 -> V_52 , 0 ) ;
}
static int F_32 ( struct V_10 * V_11 ,
const struct V_53 * V_45 )
{
struct V_1 * V_12 ;
struct V_2 * V_3 ;
const char * V_54 = NULL ;
T_1 V_55 ;
T_2 V_56 ;
if ( ! F_33 ( V_11 -> V_57 ,
V_58 | V_59 ) )
return - V_60 ;
V_12 = F_34 ( sizeof( struct V_1 ) , V_61 ) ;
if ( V_12 == NULL )
return - V_62 ;
V_3 = & V_12 -> V_3 ;
F_35 ( V_3 , V_11 , & V_63 ) ;
V_12 -> V_25 = V_28 ;
V_12 -> V_39 = 0 ;
V_12 -> V_44 = 1 ;
F_36 ( & V_12 -> V_7 , 4 ) ;
F_37 ( & V_12 -> V_7 , & V_64 ,
V_46 , - 128 , 127 , 1 , 0 ) ;
F_37 ( & V_12 -> V_7 , & V_64 ,
V_47 , 0 , 63 , 1 , 32 ) ;
F_37 ( & V_12 -> V_7 , & V_64 ,
V_48 , 0 , 4095 , 1 , 2048 ) ;
F_37 ( & V_12 -> V_7 , & V_64 ,
V_49 , - 512 , 511 , 1 , 0 ) ;
V_3 -> V_65 = & V_12 -> V_7 ;
if ( V_12 -> V_7 . error ) {
int V_66 = V_12 -> V_7 . error ;
F_38 ( & V_12 -> V_7 ) ;
F_39 ( V_12 ) ;
return V_66 ;
}
F_40 ( & V_12 -> V_7 ) ;
V_55 = F_9 ( V_11 , 0x00 ) ;
V_56 = ( F_9 ( V_11 , 0x02 ) << 8 ) +
F_9 ( V_11 , 0x01 ) ;
V_12 -> V_52 = V_67 ;
if ( V_55 == 0xec ) {
switch ( V_56 ) {
case 0x4680 :
V_54 = L_13 ;
break;
case 0x4260 :
V_54 = L_14 ;
V_12 -> V_52 = V_68 ;
break;
case 0x4280 :
V_54 = L_15 ;
V_12 -> V_52 = V_69 ;
break;
}
}
if ( V_54 )
F_41 ( V_3 , L_16 , V_54 ,
V_11 -> V_70 << 1 , V_11 -> V_57 -> V_54 ) ;
else
F_41 ( V_3 , L_17 ,
V_55 , V_56 , V_11 -> V_70 << 1 , V_11 -> V_57 -> V_54 ) ;
F_20 ( V_3 , V_23 , sizeof( V_23 ) ) ;
F_21 ( V_3 , V_24 , sizeof( V_24 ) >> 1 ) ;
F_21 ( V_3 , V_29 , sizeof( V_29 ) >> 1 ) ;
return 0 ;
}
static int F_42 ( struct V_10 * V_11 )
{
struct V_2 * V_3 = F_6 ( V_11 ) ;
struct V_1 * V_12 = F_1 ( V_3 ) ;
F_43 ( V_3 ) ;
F_38 ( & V_12 -> V_7 ) ;
F_39 ( V_12 ) ;
return 0 ;
}
