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
static int F_14 ( struct V_2 * V_3 ,
struct V_32 * V_33 ,
struct V_34 * V_35 )
{
if ( V_35 -> V_36 || V_35 -> V_37 >= F_15 ( V_38 ) )
return - V_25 ;
V_35 -> V_35 = V_38 [ V_35 -> V_37 ] ;
return 0 ;
}
static int F_16 ( struct V_2 * V_3 ,
struct V_32 * V_33 ,
struct V_39 * V_40 )
{
struct V_41 * V_42 = & V_40 -> V_40 ;
T_1 V_43 = F_6 ( V_3 , 0x7 ) ;
if ( V_40 -> V_36 )
return - V_25 ;
if ( ( V_43 & 0x40 ) == ( 1 << 6 ) )
V_42 -> V_35 = V_44 ;
else
V_42 -> V_35 = V_45 ;
V_42 -> V_46 = V_47 ;
V_42 -> V_48 = 0 ;
V_42 -> V_49 = 0 ;
V_42 -> V_50 = V_51 ;
return 0 ;
}
static int F_17 ( struct V_2 * V_3 ,
struct V_32 * V_33 ,
struct V_39 * V_40 )
{
struct V_41 * V_42 = & V_40 -> V_40 ;
T_1 V_43 = F_6 ( V_3 , 0x7 ) ;
if ( V_40 -> V_36 )
return - V_25 ;
switch ( V_42 -> V_35 ) {
case V_45 :
V_43 &= ~ 0x40 ;
break;
case V_44 :
V_43 |= 0x40 ;
break;
default:
F_12 ( 1 , V_17 , V_3 ,
L_9 , V_42 -> V_35 ) ;
return - V_25 ;
}
if ( V_40 -> V_52 == V_53 )
return F_3 ( V_3 , 0x7 , V_43 ) ;
return 0 ;
}
static int F_18 ( struct V_6 * V_7 ,
const struct V_54 * V_55 )
{
struct V_1 * V_8 ;
struct V_2 * V_3 ;
int V_56 ;
if ( ! F_9 ( V_7 -> V_12 , V_57 ) )
return - V_58 ;
F_19 ( V_7 , L_10 ,
V_7 -> V_59 << 1 , V_7 -> V_12 -> V_60 ) ;
V_8 = F_20 ( & V_7 -> V_61 , sizeof( * V_8 ) , V_62 ) ;
if ( V_8 == NULL )
return - V_63 ;
V_3 = & V_8 -> V_3 ;
F_21 ( V_3 , V_7 , & V_64 ) ;
V_8 -> V_26 = V_18 ;
V_8 -> V_20 = 0 ;
V_56 = F_8 ( V_3 , V_19 , sizeof( V_19 ) ) ;
if ( V_56 >= 0 ) {
V_56 = F_3 ( V_3 , 0x07 , V_21 | V_22 ) ;
V_56 = F_3 ( V_3 , 0x07 , V_21 ) ;
V_56 = F_6 ( V_3 , 0x12 ) ;
F_12 ( 1 , V_17 , V_3 , L_11 , V_56 & 1 ) ;
}
if ( V_56 < 0 )
F_12 ( 1 , V_17 , V_3 , L_12 , V_56 ) ;
return 0 ;
}
static int F_22 ( struct V_6 * V_7 )
{
struct V_2 * V_3 = F_23 ( V_7 ) ;
F_24 ( V_3 ) ;
return 0 ;
}
