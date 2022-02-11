static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static inline int F_3 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = F_4 ( V_3 ) ;
return F_5 ( V_5 ) ;
}
static int F_6 ( struct V_2 * V_3 , T_1 V_6 , T_1 V_7 )
{
struct V_4 * V_5 = F_4 ( V_3 ) ;
struct V_1 * V_8 = F_1 ( V_3 ) ;
F_7 ( 1 , V_9 , V_3 , L_1 , V_6 , V_7 ) ;
V_8 -> V_6 [ V_6 ] = V_7 ;
return F_8 ( V_5 , V_6 , V_7 ) ;
}
static int F_9 ( struct V_2 * V_3 ,
const T_1 * V_10 , unsigned int V_11 )
{
struct V_4 * V_5 = F_4 ( V_3 ) ;
struct V_1 * V_8 = F_1 ( V_3 ) ;
int V_12 = - 1 ;
T_1 V_6 ;
if ( F_10 ( V_5 -> V_13 , V_14 ) ) {
T_1 V_15 [ 32 ] ;
int V_16 ;
while ( V_11 >= 2 ) {
V_16 = 0 ;
V_15 [ V_16 ++ ] = V_6 = V_10 [ 0 ] ;
do {
V_15 [ V_16 ++ ] =
V_8 -> V_6 [ V_6 ++ ] = V_10 [ 1 ] ;
V_11 -= 2 ;
V_10 += 2 ;
} while ( V_11 >= 2 && V_10 [ 0 ] == V_6 && V_16 < 32 );
V_12 = F_11 ( V_5 , V_15 , V_16 ) ;
if ( V_12 < 0 )
break;
}
} else {
while ( V_11 >= 2 ) {
V_6 = * V_10 ++ ;
V_12 = F_6 ( V_3 , V_6 , * V_10 ++ ) ;
if ( V_12 < 0 )
break;
V_11 -= 2 ;
}
}
return V_12 ;
}
static int F_12 ( struct V_2 * V_3 , T_2 V_17 )
{
struct V_1 * V_8 = F_1 ( V_3 ) ;
F_9 ( V_3 , V_18 , sizeof( V_18 ) ) ;
if ( V_8 -> V_19 & V_20 )
F_9 ( V_3 , V_21 , sizeof( V_21 ) ) ;
else
F_9 ( V_3 , V_22 , sizeof( V_22 ) ) ;
return 0 ;
}
static int F_13 ( struct V_2 * V_3 , T_3 V_23 )
{
struct V_1 * V_8 = F_1 ( V_3 ) ;
if ( V_23 & V_20 )
F_9 ( V_3 , V_21 , sizeof( V_21 ) ) ;
else if ( V_23 & V_24 )
F_9 ( V_3 , V_22 , sizeof( V_22 ) ) ;
else
return - V_25 ;
V_8 -> V_19 = V_23 ;
return 0 ;
}
static int F_14 ( struct V_2 * V_3 ,
T_2 V_26 , T_2 V_27 , T_2 V_28 )
{
struct V_1 * V_8 = F_1 ( V_3 ) ;
switch ( V_26 ) {
case 0 :
F_6 ( V_3 , 0x3a , 0x0f ) ;
F_6 ( V_3 , 0x61 , ( V_8 -> V_6 [ 0x61 ] & 0xf7 ) | 0x08 ) ;
F_6 ( V_3 , 0x6e , 0x01 ) ;
break;
case 1 :
F_6 ( V_3 , 0x3a , 0x0f ) ;
F_6 ( V_3 , 0x61 , ( V_8 -> V_6 [ 0x61 ] & 0xf7 ) | 0x00 ) ;
F_6 ( V_3 , 0x6e , 0x00 ) ;
break;
case 2 :
F_6 ( V_3 , 0x3a , 0x8f ) ;
F_6 ( V_3 , 0x61 , ( V_8 -> V_6 [ 0x61 ] & 0xf7 ) | 0x08 ) ;
F_6 ( V_3 , 0x6e , 0x01 ) ;
break;
default:
return - V_25 ;
}
return 0 ;
}
static int F_15 ( struct V_4 * V_5 ,
const struct V_29 * V_30 )
{
int V_31 ;
struct V_1 * V_8 ;
struct V_2 * V_3 ;
if ( ! F_10 ( V_5 -> V_13 , V_32 ) )
return - V_33 ;
F_16 ( V_5 , L_2 ,
V_5 -> V_34 << 1 , V_5 -> V_13 -> V_35 ) ;
V_8 = F_17 ( & V_5 -> V_36 , sizeof( * V_8 ) , V_37 ) ;
if ( V_8 == NULL )
return - V_38 ;
V_8 -> V_19 = V_20 ;
V_3 = & V_8 -> V_3 ;
F_18 ( V_3 , V_5 , & V_39 ) ;
V_31 = F_9 ( V_3 , V_18 , sizeof( V_18 ) ) ;
if ( V_31 >= 0 )
V_31 = F_9 ( V_3 , V_21 , sizeof( V_21 ) ) ;
if ( V_31 < 0 )
F_7 ( 1 , V_9 , V_3 , L_3 , V_31 ) ;
else
F_7 ( 1 , V_9 , V_3 , L_4 ,
F_3 ( V_3 ) >> 5 ) ;
return 0 ;
}
static int F_19 ( struct V_4 * V_5 )
{
struct V_2 * V_3 = F_20 ( V_5 ) ;
struct V_1 * V_8 = F_1 ( V_3 ) ;
F_21 ( V_3 ) ;
F_6 ( V_3 , 0x61 , ( V_8 -> V_6 [ 0x61 ] ) | 0x40 ) ;
return 0 ;
}
