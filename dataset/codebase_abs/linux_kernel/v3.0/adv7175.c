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
static int F_16 ( struct V_2 * V_3 , struct V_36 * V_37 )
{
struct V_6 * V_7 = F_4 ( V_3 ) ;
return F_17 ( V_7 , V_37 , V_38 , 0 ) ;
}
static int F_18 ( struct V_2 * V_3 , int V_39 )
{
if ( V_39 )
F_3 ( V_3 , 0x01 , 0x00 ) ;
else
F_3 ( V_3 , 0x01 , 0x78 ) ;
return 0 ;
}
static int F_19 ( struct V_6 * V_7 ,
const struct V_40 * V_41 )
{
int V_42 ;
struct V_1 * V_21 ;
struct V_2 * V_3 ;
if ( ! F_9 ( V_7 -> V_11 , V_43 ) )
return - V_44 ;
F_20 ( V_7 , L_5 ,
V_7 -> V_45 << 1 , V_7 -> V_11 -> V_46 ) ;
V_21 = F_21 ( sizeof( struct V_1 ) , V_47 ) ;
if ( V_21 == NULL )
return - V_48 ;
V_3 = & V_21 -> V_3 ;
F_22 ( V_3 , V_7 , & V_49 ) ;
V_21 -> V_30 = V_22 ;
V_21 -> V_24 = 0 ;
V_42 = F_8 ( V_3 , V_17 , sizeof( V_17 ) ) ;
if ( V_42 >= 0 ) {
V_42 = F_3 ( V_3 , 0x07 , V_18 | V_19 ) ;
V_42 = F_3 ( V_3 , 0x07 , V_18 ) ;
V_42 = F_6 ( V_3 , 0x12 ) ;
F_14 ( 1 , V_28 , V_3 , L_6 , V_42 & 1 ) ;
}
if ( V_42 < 0 )
F_14 ( 1 , V_28 , V_3 , L_7 , V_42 ) ;
return 0 ;
}
static int F_23 ( struct V_6 * V_7 )
{
struct V_2 * V_3 = F_24 ( V_7 ) ;
F_25 ( V_3 ) ;
F_26 ( F_1 ( V_3 ) ) ;
return 0 ;
}
static T_4 int F_27 ( void )
{
return F_28 ( & V_50 ) ;
}
static T_5 void F_29 ( void )
{
F_30 ( & V_50 ) ;
}
