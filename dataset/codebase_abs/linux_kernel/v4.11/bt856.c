static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static inline int F_3 ( struct V_1 * V_4 , T_1 V_5 , T_1 V_6 )
{
struct V_7 * V_8 = F_4 ( & V_4 -> V_3 ) ;
V_4 -> V_5 [ V_5 - V_9 ] = V_6 ;
return F_5 ( V_8 , V_5 , V_6 ) ;
}
static inline int F_6 ( struct V_1 * V_4 , T_1 V_5 , T_1 V_10 , T_1 V_6 )
{
return F_3 ( V_4 , V_5 ,
( V_4 -> V_5 [ V_5 - V_9 ] & ~ ( 1 << V_10 ) ) |
( V_6 ? ( 1 << V_10 ) : 0 ) ) ;
}
static void F_7 ( struct V_1 * V_4 )
{
int V_11 ;
F_8 ( & V_4 -> V_3 , L_1 ) ;
for ( V_11 = 0 ; V_11 < V_12 ; V_11 += 2 )
F_9 ( V_13 L_2 , V_4 -> V_5 [ V_11 ] ) ;
F_9 ( V_13 L_3 ) ;
}
static int F_10 ( struct V_2 * V_3 , T_2 V_14 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
F_11 ( 1 , V_15 , V_3 , L_4 ) ;
F_3 ( V_4 , 0xdc , 0x18 ) ;
F_3 ( V_4 , 0xda , 0 ) ;
F_3 ( V_4 , 0xde , 0 ) ;
F_6 ( V_4 , 0xdc , 3 , 1 ) ;
F_6 ( V_4 , 0xdc , 4 , 1 ) ;
if ( V_4 -> V_16 & V_17 )
F_6 ( V_4 , 0xdc , 2 , 0 ) ;
else
F_6 ( V_4 , 0xdc , 2 , 1 ) ;
F_6 ( V_4 , 0xdc , 1 , 1 ) ;
F_6 ( V_4 , 0xde , 4 , 0 ) ;
F_6 ( V_4 , 0xde , 3 , 1 ) ;
if ( V_15 != 0 )
F_7 ( V_4 ) ;
return 0 ;
}
static int F_12 ( struct V_2 * V_3 , T_3 V_18 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
F_11 ( 1 , V_15 , V_3 , L_5 , ( unsigned long long ) V_18 ) ;
if ( V_18 & V_17 ) {
F_6 ( V_4 , 0xdc , 2 , 0 ) ;
} else if ( V_18 & V_19 ) {
F_6 ( V_4 , 0xdc , 2 , 1 ) ;
F_6 ( V_4 , 0xda , 0 , 0 ) ;
} else {
return - V_20 ;
}
V_4 -> V_16 = V_18 ;
if ( V_15 != 0 )
F_7 ( V_4 ) ;
return 0 ;
}
static int F_13 ( struct V_2 * V_3 ,
T_2 V_21 , T_2 V_22 , T_2 V_23 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
F_11 ( 1 , V_15 , V_3 , L_6 , V_21 ) ;
switch ( V_21 ) {
case 0 :
F_6 ( V_4 , 0xde , 4 , 0 ) ;
F_6 ( V_4 , 0xde , 3 , 1 ) ;
F_6 ( V_4 , 0xdc , 3 , 1 ) ;
F_6 ( V_4 , 0xdc , 6 , 0 ) ;
break;
case 1 :
F_6 ( V_4 , 0xde , 4 , 0 ) ;
F_6 ( V_4 , 0xde , 3 , 1 ) ;
F_6 ( V_4 , 0xdc , 3 , 1 ) ;
F_6 ( V_4 , 0xdc , 6 , 1 ) ;
break;
case 2 :
F_6 ( V_4 , 0xdc , 3 , 0 ) ;
F_6 ( V_4 , 0xde , 4 , 1 ) ;
break;
default:
return - V_20 ;
}
if ( V_15 != 0 )
F_7 ( V_4 ) ;
return 0 ;
}
static int F_14 ( struct V_7 * V_8 ,
const struct V_24 * V_25 )
{
struct V_1 * V_4 ;
struct V_2 * V_3 ;
if ( ! F_15 ( V_8 -> V_26 , V_27 ) )
return - V_28 ;
F_16 ( V_8 , L_7 ,
V_8 -> V_29 << 1 , V_8 -> V_26 -> V_30 ) ;
V_4 = F_17 ( & V_8 -> V_31 , sizeof( * V_4 ) , V_32 ) ;
if ( V_4 == NULL )
return - V_33 ;
V_3 = & V_4 -> V_3 ;
F_18 ( V_3 , V_8 , & V_34 ) ;
V_4 -> V_16 = V_17 ;
F_3 ( V_4 , 0xdc , 0x18 ) ;
F_3 ( V_4 , 0xda , 0 ) ;
F_3 ( V_4 , 0xde , 0 ) ;
F_6 ( V_4 , 0xdc , 3 , 1 ) ;
F_6 ( V_4 , 0xdc , 4 , 1 ) ;
if ( V_4 -> V_16 & V_17 )
F_6 ( V_4 , 0xdc , 2 , 0 ) ;
else
F_6 ( V_4 , 0xdc , 2 , 1 ) ;
F_6 ( V_4 , 0xdc , 1 , 1 ) ;
F_6 ( V_4 , 0xde , 4 , 0 ) ;
F_6 ( V_4 , 0xde , 3 , 1 ) ;
if ( V_15 != 0 )
F_7 ( V_4 ) ;
return 0 ;
}
static int F_19 ( struct V_7 * V_8 )
{
struct V_2 * V_3 = F_20 ( V_8 ) ;
F_21 ( V_3 ) ;
return 0 ;
}
