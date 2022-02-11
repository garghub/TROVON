static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static inline int F_3 ( struct V_2 * V_3 , T_1 V_4 , T_1 V_5 )
{
struct V_6 * V_7 = F_4 ( V_3 ) ;
struct V_1 * V_8 = F_1 ( V_3 ) ;
V_8 -> V_4 [ V_4 ] = V_5 ;
return F_5 ( V_7 , V_4 , V_5 ) ;
}
static inline int F_6 ( struct V_2 * V_3 , T_1 V_4 )
{
struct V_6 * V_7 = F_4 ( V_3 ) ;
return F_7 ( V_7 , V_4 ) ;
}
static int F_8 ( struct V_2 * V_3 ,
const T_1 * V_9 , unsigned int V_10 )
{
struct V_6 * V_7 = F_4 ( V_3 ) ;
struct V_1 * V_8 = F_1 ( V_3 ) ;
int V_11 = - 1 ;
T_1 V_4 ;
if ( F_9 ( V_7 -> V_12 , V_13 ) ) {
T_1 V_14 [ 32 ] ;
int V_15 ;
while ( V_10 >= 2 ) {
V_15 = 0 ;
V_14 [ V_15 ++ ] = V_4 = V_9 [ 0 ] ;
do {
V_14 [ V_15 ++ ] =
V_8 -> V_4 [ V_4 ++ ] = V_9 [ 1 ] ;
V_10 -= 2 ;
V_9 += 2 ;
} while ( V_10 >= 2 && V_9 [ 0 ] == V_4 && V_15 < 32 );
V_11 = F_10 ( V_7 , V_14 , V_15 ) ;
if ( V_11 < 0 )
break;
}
} else {
while ( V_10 >= 2 ) {
V_4 = * V_9 ++ ;
V_11 = F_3 ( V_3 , V_4 , * V_9 ++ ) ;
if ( V_11 < 0 )
break;
V_10 -= 2 ;
}
}
return V_11 ;
}
static int F_11 ( struct V_2 * V_3 , T_2 V_16 )
{
struct V_1 * V_8 = F_1 ( V_3 ) ;
F_12 ( 1 , V_17 , V_3 , L_1 , ( unsigned long long ) V_16 ) ;
if ( V_16 & V_18 ) {
F_8 ( V_3 , V_19 , sizeof( V_19 ) ) ;
if ( V_8 -> V_20 == 0 )
F_3 ( V_3 , 0x02 , 0x0e ) ;
F_3 ( V_3 , 0x07 , V_21 | V_22 ) ;
F_3 ( V_3 , 0x07 , V_21 ) ;
} else if ( V_16 & V_23 ) {
F_8 ( V_3 , V_24 , sizeof( V_24 ) ) ;
if ( V_8 -> V_20 == 0 )
F_3 ( V_3 , 0x02 , 0x0e ) ;
F_3 ( V_3 , 0x07 , V_21 | V_22 ) ;
F_3 ( V_3 , 0x07 , V_21 ) ;
} else {
F_12 ( 1 , V_17 , V_3 , L_2 ,
( unsigned long long ) V_16 ) ;
return - V_25 ;
}
F_12 ( 1 , V_17 , V_3 , L_3 , ( unsigned long long ) V_16 ) ;
V_8 -> V_26 = V_16 ;
return 0 ;
}
static int F_13 ( struct V_2 * V_3 ,
T_3 V_20 , T_3 V_27 , T_3 V_28 )
{
struct V_1 * V_8 = F_1 ( V_3 ) ;
F_12 ( 1 , V_17 , V_3 , L_4 ,
V_20 == 0 ? L_5 : L_6 ) ;
switch ( V_20 ) {
case 0 :
F_3 ( V_3 , 0x01 , 0x20 ) ;
F_3 ( V_3 , 0x08 , V_29 ) ;
F_3 ( V_3 , 0x02 , 0x0e ) ;
F_3 ( V_3 , 0x07 , V_21 | V_22 ) ;
F_3 ( V_3 , 0x07 , V_21 ) ;
break;
case 1 :
F_3 ( V_3 , 0x01 , 0x00 ) ;
F_3 ( V_3 , 0x08 , V_30 ) ;
F_3 ( V_3 , 0x02 , 0x08 ) ;
F_3 ( V_3 , 0x07 , V_21 | V_22 ) ;
F_3 ( V_3 , 0x07 , V_21 ) ;
break;
default:
F_12 ( 1 , V_17 , V_3 , L_7 , V_20 ) ;
return - V_25 ;
}
F_12 ( 1 , V_17 , V_3 , L_8 , V_31 [ V_20 ] ) ;
V_8 -> V_20 = V_20 ;
return 0 ;
}
static int F_14 ( struct V_2 * V_3 , unsigned int V_32 ,
enum V_33 * V_34 )
{
if ( V_32 >= F_15 ( V_35 ) )
return - V_25 ;
* V_34 = V_35 [ V_32 ] ;
return 0 ;
}
static int F_16 ( struct V_2 * V_3 ,
struct V_36 * V_37 )
{
T_1 V_38 = F_6 ( V_3 , 0x7 ) ;
if ( ( V_38 & 0x40 ) == ( 1 << 6 ) )
V_37 -> V_34 = V_39 ;
else
V_37 -> V_34 = V_40 ;
V_37 -> V_41 = V_42 ;
V_37 -> V_43 = 0 ;
V_37 -> V_44 = 0 ;
V_37 -> V_45 = V_46 ;
return 0 ;
}
static int F_17 ( struct V_2 * V_3 ,
struct V_36 * V_37 )
{
T_1 V_38 = F_6 ( V_3 , 0x7 ) ;
int V_11 ;
switch ( V_37 -> V_34 ) {
case V_40 :
V_38 &= ~ 0x40 ;
break;
case V_39 :
V_38 |= 0x40 ;
break;
default:
F_12 ( 1 , V_17 , V_3 ,
L_9 , V_37 -> V_34 ) ;
return - V_25 ;
}
V_11 = F_3 ( V_3 , 0x7 , V_38 ) ;
return V_11 ;
}
static int F_18 ( struct V_2 * V_3 , struct V_47 * V_48 )
{
struct V_6 * V_7 = F_4 ( V_3 ) ;
return F_19 ( V_7 , V_48 , V_49 , 0 ) ;
}
static int F_20 ( struct V_6 * V_7 ,
const struct V_50 * V_51 )
{
struct V_1 * V_8 ;
struct V_2 * V_3 ;
int V_52 ;
if ( ! F_9 ( V_7 -> V_12 , V_53 ) )
return - V_54 ;
F_21 ( V_7 , L_10 ,
V_7 -> V_55 << 1 , V_7 -> V_12 -> V_56 ) ;
V_8 = F_22 ( sizeof( struct V_1 ) , V_57 ) ;
if ( V_8 == NULL )
return - V_58 ;
V_3 = & V_8 -> V_3 ;
F_23 ( V_3 , V_7 , & V_59 ) ;
V_8 -> V_26 = V_18 ;
V_8 -> V_20 = 0 ;
V_52 = F_8 ( V_3 , V_19 , sizeof( V_19 ) ) ;
if ( V_52 >= 0 ) {
V_52 = F_3 ( V_3 , 0x07 , V_21 | V_22 ) ;
V_52 = F_3 ( V_3 , 0x07 , V_21 ) ;
V_52 = F_6 ( V_3 , 0x12 ) ;
F_12 ( 1 , V_17 , V_3 , L_11 , V_52 & 1 ) ;
}
if ( V_52 < 0 )
F_12 ( 1 , V_17 , V_3 , L_12 , V_52 ) ;
return 0 ;
}
static int F_24 ( struct V_6 * V_7 )
{
struct V_2 * V_3 = F_25 ( V_7 ) ;
F_26 ( V_3 ) ;
F_27 ( F_1 ( V_3 ) ) ;
return 0 ;
}
static T_4 int F_28 ( void )
{
return F_29 ( & V_60 ) ;
}
static T_5 void F_30 ( void )
{
F_31 ( & V_60 ) ;
}
