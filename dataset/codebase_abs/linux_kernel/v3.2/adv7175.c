static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static inline int F_3 ( struct V_2 * V_3 , T_1 V_4 , T_1 V_5 )
{
struct V_6 * V_7 = F_4 ( V_3 ) ;
return F_5 ( V_7 , V_4 , V_5 ) ;
}
static inline int F_6 ( struct V_2 * V_3 , T_1 V_4 )
{
struct V_6 * V_7 = F_4 ( V_3 ) ;
return F_7 ( V_7 , V_4 ) ;
}
static int F_8 ( struct V_2 * V_3 ,
const T_1 * V_8 , unsigned int V_9 )
{
struct V_6 * V_7 = F_4 ( V_3 ) ;
int V_10 = - 1 ;
T_1 V_4 ;
if ( F_9 ( V_7 -> V_11 , V_12 ) ) {
T_1 V_13 [ 32 ] ;
int V_14 ;
while ( V_9 >= 2 ) {
V_14 = 0 ;
V_13 [ V_14 ++ ] = V_4 = V_8 [ 0 ] ;
do {
V_13 [ V_14 ++ ] = V_8 [ 1 ] ;
V_4 ++ ;
V_9 -= 2 ;
V_8 += 2 ;
} while ( V_9 >= 2 && V_8 [ 0 ] == V_4 && V_14 < 32 );
V_10 = F_10 ( V_7 , V_13 , V_14 ) ;
if ( V_10 < 0 )
break;
}
} else {
while ( V_9 >= 2 ) {
V_4 = * V_8 ++ ;
V_10 = F_3 ( V_3 , V_4 , * V_8 ++ ) ;
if ( V_10 < 0 )
break;
V_9 -= 2 ;
}
}
return V_10 ;
}
static void F_11 ( struct V_2 * V_3 , int V_15 )
{
if ( V_15 )
F_3 ( V_3 , 0x02 , 0x00 ) ;
else
F_3 ( V_3 , 0x02 , 0x55 ) ;
F_3 ( V_3 , 0x03 , 0x55 ) ;
F_3 ( V_3 , 0x04 , 0x55 ) ;
F_3 ( V_3 , 0x05 , 0x25 ) ;
}
static int F_12 ( struct V_2 * V_3 , T_2 V_16 )
{
F_8 ( V_3 , V_17 , sizeof( V_17 ) ) ;
F_3 ( V_3 , 0x07 , V_18 | V_19 ) ;
F_3 ( V_3 , 0x07 , V_18 ) ;
return 0 ;
}
static int F_13 ( struct V_2 * V_3 , T_3 V_20 )
{
struct V_1 * V_21 = F_1 ( V_3 ) ;
if ( V_20 & V_22 ) {
F_8 ( V_3 , V_23 , sizeof( V_23 ) ) ;
if ( V_21 -> V_24 == 0 )
F_3 ( V_3 , 0x0d , 0x4f ) ;
F_3 ( V_3 , 0x07 , V_18 | V_19 ) ;
F_3 ( V_3 , 0x07 , V_18 ) ;
} else if ( V_20 & V_25 ) {
F_8 ( V_3 , V_26 , sizeof( V_26 ) ) ;
if ( V_21 -> V_24 == 0 )
F_3 ( V_3 , 0x0d , 0x4f ) ;
F_3 ( V_3 , 0x07 , V_18 | V_19 ) ;
F_3 ( V_3 , 0x07 , V_18 ) ;
} else if ( V_20 & V_27 ) {
F_8 ( V_3 , V_26 , sizeof( V_26 ) ) ;
if ( V_21 -> V_24 == 0 )
F_3 ( V_3 , 0x0d , 0x49 ) ;
F_3 ( V_3 , 0x07 , V_18 | V_19 ) ;
F_3 ( V_3 , 0x07 , V_18 ) ;
} else {
F_14 ( 1 , V_28 , V_3 , L_1 ,
( unsigned long long ) V_20 ) ;
return - V_29 ;
}
F_14 ( 1 , V_28 , V_3 , L_2 , ( unsigned long long ) V_20 ) ;
V_21 -> V_30 = V_20 ;
return 0 ;
}
static int F_15 ( struct V_2 * V_3 ,
T_2 V_24 , T_2 V_31 , T_2 V_32 )
{
struct V_1 * V_21 = F_1 ( V_3 ) ;
switch ( V_24 ) {
case 0 :
F_3 ( V_3 , 0x01 , 0x00 ) ;
if ( V_21 -> V_30 & V_22 )
F_11 ( V_3 , 1 ) ;
F_3 ( V_3 , 0x0c , V_33 ) ;
if ( V_21 -> V_30 & V_27 )
F_3 ( V_3 , 0x0d , 0x49 ) ;
else
F_3 ( V_3 , 0x0d , 0x4f ) ;
F_3 ( V_3 , 0x07 , V_18 | V_19 ) ;
F_3 ( V_3 , 0x07 , V_18 ) ;
break;
case 1 :
F_3 ( V_3 , 0x01 , 0x00 ) ;
if ( V_21 -> V_30 & V_22 )
F_11 ( V_3 , 0 ) ;
F_3 ( V_3 , 0x0c , V_34 ) ;
F_3 ( V_3 , 0x0d , 0x49 ) ;
F_3 ( V_3 , 0x07 , V_18 | V_19 ) ;
F_3 ( V_3 , 0x07 , V_18 ) ;
break;
case 2 :
F_3 ( V_3 , 0x01 , 0x80 ) ;
if ( V_21 -> V_30 & V_22 )
F_11 ( V_3 , 0 ) ;
F_3 ( V_3 , 0x0d , 0x49 ) ;
F_3 ( V_3 , 0x07 , V_18 | V_19 ) ;
F_3 ( V_3 , 0x07 , V_18 ) ;
break;
default:
F_14 ( 1 , V_28 , V_3 , L_3 , V_24 ) ;
return - V_29 ;
}
F_14 ( 1 , V_28 , V_3 , L_4 , V_35 [ V_24 ] ) ;
V_21 -> V_24 = V_24 ;
return 0 ;
}
static int F_16 ( struct V_2 * V_3 , unsigned int V_36 ,
enum V_37 * V_38 )
{
if ( V_36 >= F_17 ( V_39 ) )
return - V_29 ;
* V_38 = V_39 [ V_36 ] ;
return 0 ;
}
static int F_18 ( struct V_2 * V_3 ,
struct V_40 * V_41 )
{
T_1 V_16 = F_6 ( V_3 , 0x7 ) ;
if ( ( V_16 & 0x40 ) == ( 1 << 6 ) )
V_41 -> V_38 = V_42 ;
else
V_41 -> V_38 = V_43 ;
V_41 -> V_44 = V_45 ;
V_41 -> V_46 = 0 ;
V_41 -> V_47 = 0 ;
V_41 -> V_48 = V_49 ;
return 0 ;
}
static int F_19 ( struct V_2 * V_3 ,
struct V_40 * V_41 )
{
T_1 V_16 = F_6 ( V_3 , 0x7 ) ;
int V_10 ;
switch ( V_41 -> V_38 ) {
case V_43 :
V_16 &= ~ 0x40 ;
break;
case V_42 :
V_16 |= 0x40 ;
break;
default:
F_14 ( 1 , V_28 , V_3 ,
L_5 , V_41 -> V_38 ) ;
return - V_29 ;
}
V_10 = F_3 ( V_3 , 0x7 , V_16 ) ;
return V_10 ;
}
static int F_20 ( struct V_2 * V_3 , struct V_50 * V_51 )
{
struct V_6 * V_7 = F_4 ( V_3 ) ;
return F_21 ( V_7 , V_51 , V_52 , 0 ) ;
}
static int F_22 ( struct V_2 * V_3 , int V_53 )
{
if ( V_53 )
F_3 ( V_3 , 0x01 , 0x00 ) ;
else
F_3 ( V_3 , 0x01 , 0x78 ) ;
return 0 ;
}
static int F_23 ( struct V_6 * V_7 ,
const struct V_54 * V_55 )
{
int V_56 ;
struct V_1 * V_21 ;
struct V_2 * V_3 ;
if ( ! F_9 ( V_7 -> V_11 , V_57 ) )
return - V_58 ;
F_24 ( V_7 , L_6 ,
V_7 -> V_59 << 1 , V_7 -> V_11 -> V_60 ) ;
V_21 = F_25 ( sizeof( struct V_1 ) , V_61 ) ;
if ( V_21 == NULL )
return - V_62 ;
V_3 = & V_21 -> V_3 ;
F_26 ( V_3 , V_7 , & V_63 ) ;
V_21 -> V_30 = V_22 ;
V_21 -> V_24 = 0 ;
V_56 = F_8 ( V_3 , V_17 , sizeof( V_17 ) ) ;
if ( V_56 >= 0 ) {
V_56 = F_3 ( V_3 , 0x07 , V_18 | V_19 ) ;
V_56 = F_3 ( V_3 , 0x07 , V_18 ) ;
V_56 = F_6 ( V_3 , 0x12 ) ;
F_14 ( 1 , V_28 , V_3 , L_7 , V_56 & 1 ) ;
}
if ( V_56 < 0 )
F_14 ( 1 , V_28 , V_3 , L_8 , V_56 ) ;
return 0 ;
}
static int F_27 ( struct V_6 * V_7 )
{
struct V_2 * V_3 = F_28 ( V_7 ) ;
F_29 ( V_3 ) ;
F_30 ( F_1 ( V_3 ) ) ;
return 0 ;
}
static T_4 int F_31 ( void )
{
return F_32 ( & V_64 ) ;
}
static T_5 void F_33 ( void )
{
F_34 ( & V_64 ) ;
}
