static inline int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
T_1 V_5 [ 2 ] ;
V_5 [ 0 ] = V_3 | 0x80 ;
V_5 [ 1 ] = V_4 ;
return F_2 ( V_2 , V_5 , sizeof( V_5 ) ) ;
}
static int F_3 ( struct V_6 * V_7 , struct V_8 * V_9 )
{
struct V_1 * V_2 = F_4 ( V_7 ) ;
T_1 V_5 [ 9 ] = { 0x80 } ;
T_1 * const V_4 = & V_5 [ 1 ] ;
F_5 ( V_7 , L_1
L_2 ,
L_3 , V_9 -> V_10 , V_9 -> V_11 ,
V_9 -> V_12 , V_9 -> V_13 ,
V_9 -> V_14 , V_9 -> V_15 , V_9 -> V_16 ) ;
if ( V_9 -> V_15 < 100 ) {
F_6 ( & V_2 -> V_7 , L_4 ) ;
return - V_17 ;
}
V_4 [ V_18 ] = 0 ;
V_4 [ V_19 ] = F_7 ( V_9 -> V_10 ) ;
V_4 [ V_20 ] = F_7 ( V_9 -> V_11 ) ;
V_4 [ V_21 ] = F_7 ( V_9 -> V_12 ) |
( ( V_9 -> V_15 / 100 - 1 ) << 6 ) ;
V_4 [ V_22 ] = F_7 ( V_9 -> V_13 ) ;
V_4 [ V_23 ] = F_7 ( V_9 -> V_16 + 1 ) ;
V_4 [ V_24 ] = F_7 ( V_9 -> V_14 + 1 ) ;
V_4 [ V_25 ] = F_7 ( V_9 -> V_15 % 100 ) ;
return F_2 ( V_2 , V_5 , sizeof( V_5 ) ) ;
}
static int F_8 ( struct V_6 * V_7 , struct V_8 * V_9 )
{
struct V_1 * V_2 = F_4 ( V_7 ) ;
const T_1 V_26 = 0 ;
T_1 V_5 [ 8 ] ;
int V_27 ;
int V_28 ;
int V_29 = 0 ;
V_28 = F_9 ( V_2 , V_30 ) ;
if ( V_28 < 0 )
return V_28 ;
if ( V_28 & V_31 ) {
F_5 ( & V_2 -> V_7 , L_5 ) ;
F_1 ( V_2 , V_30 ,
V_28 & ~ V_31 ) ;
}
V_28 = F_9 ( V_2 , V_32 ) ;
if ( V_28 < 0 )
return V_28 ;
if ( V_28 & V_33 ) {
V_29 = - V_17 ;
F_6 ( & V_2 -> V_7 , L_6 ) ;
F_1 ( V_2 , V_32 , V_28 & ~ V_33 ) ;
V_28 = F_9 ( V_2 , V_32 ) ;
if ( V_28 < 0 )
return V_28 ;
else if ( V_28 & V_33 ) {
T_1 V_34 = V_5 [ V_19 ] | V_35 ;
F_6 ( & V_2 -> V_7 ,
L_7 ) ;
F_1 ( V_2 , V_19 , V_34 ) ;
V_34 &= ~ V_35 ;
F_1 ( V_2 , V_19 , V_34 ) ;
}
}
if ( V_28 & V_36 )
F_6 ( & V_2 -> V_7 , L_8 ) ;
V_28 = F_10 ( V_2 , & V_26 , 1 , V_5 , sizeof( V_5 ) ) ;
if ( V_28 < 0 )
return V_28 ;
V_9 -> V_10 = F_11 ( V_5 [ V_19 ] ) ;
V_9 -> V_11 = F_11 ( V_5 [ V_20 ] ) ;
V_9 -> V_12 = F_11 ( V_5 [ V_21 ] & 0x3f ) ;
V_9 -> V_13 = F_11 ( V_5 [ V_22 ] ) ;
V_9 -> V_14 = F_11 ( V_5 [ V_24 ] ) - 1 ;
V_9 -> V_16 = F_11 ( V_5 [ V_23 ] & 0x0f ) - 1 ;
V_27 = ( V_5 [ V_21 ] >> 6 ) + 1 ;
V_9 -> V_15 = F_11 ( V_5 [ V_25 ] ) + V_27 * 100 ;
F_5 ( V_7 , L_1
L_2 ,
L_9 , V_9 -> V_10 , V_9 -> V_11 ,
V_9 -> V_12 , V_9 -> V_13 ,
V_9 -> V_14 , V_9 -> V_15 , V_9 -> V_16 ) ;
return V_29 < 0 ? V_29 : F_12 ( V_9 ) ;
}
static int T_2 F_13 ( struct V_1 * V_2 )
{
struct V_37 * V_38 ;
int V_39 ;
V_2 -> V_40 = 8 ;
F_14 ( V_2 ) ;
V_39 = F_9 ( V_2 , V_23 ) ;
if ( V_39 < 0 || ( V_39 & 0xf8 ) != 0 ) {
F_15 ( & V_2 -> V_7 , L_10 , V_39 ) ;
return - V_41 ;
}
V_38 = F_16 ( V_42 . V_43 . V_44 ,
& V_2 -> V_7 , & V_45 , V_46 ) ;
if ( F_17 ( V_38 ) )
return F_18 ( V_38 ) ;
F_19 ( & V_2 -> V_7 , V_38 ) ;
return 0 ;
}
static int T_3 F_20 ( struct V_1 * V_2 )
{
struct V_37 * V_38 = F_21 ( V_2 ) ;
if ( V_38 )
F_22 ( V_38 ) ;
return 0 ;
}
static T_4 int F_23 ( void )
{
return F_24 ( & V_42 ) ;
}
static T_5 void F_25 ( void )
{
F_26 ( & V_42 ) ;
}
