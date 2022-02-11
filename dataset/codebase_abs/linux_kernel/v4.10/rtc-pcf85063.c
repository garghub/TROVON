static int F_1 ( struct V_1 * V_2 , T_1 * V_3 )
{
T_2 V_4 ;
V_4 = F_2 ( V_2 , V_5 ) ;
if ( V_4 < 0 ) {
F_3 ( & V_2 -> V_6 , L_1 ) ;
return - V_7 ;
}
V_4 |= V_8 ;
V_4 = F_4 ( V_2 , V_5 , V_4 ) ;
if ( V_4 < 0 ) {
F_3 ( & V_2 -> V_6 , L_1 ) ;
return - V_7 ;
}
* V_3 = V_4 ;
return 0 ;
}
static int F_5 ( struct V_1 * V_2 , T_1 V_3 )
{
T_2 V_4 ;
V_3 &= V_8 ;
V_4 = F_4 ( V_2 , V_5 , V_3 ) ;
if ( V_4 < 0 ) {
F_3 ( & V_2 -> V_6 , L_2 ) ;
return - V_7 ;
}
return 0 ;
}
static int F_6 ( struct V_1 * V_2 , struct V_9 * V_10 )
{
int V_11 ;
T_1 V_12 [ 7 ] ;
V_11 = F_7 ( V_2 , V_13 ,
sizeof( V_12 ) , V_12 ) ;
if ( V_11 != sizeof( V_12 ) ) {
F_3 ( & V_2 -> V_6 , L_3 ) ;
return - V_7 ;
}
if ( V_12 [ 0 ] & V_14 ) {
F_8 ( & V_2 -> V_6 , L_4 ) ;
return - V_15 ;
}
V_10 -> V_16 = F_9 ( V_12 [ 0 ] & 0x7F ) ;
V_10 -> V_17 = F_9 ( V_12 [ 1 ] & 0x7F ) ;
V_10 -> V_18 = F_9 ( V_12 [ 2 ] & 0x3F ) ;
V_10 -> V_19 = F_9 ( V_12 [ 3 ] & 0x3F ) ;
V_10 -> V_20 = V_12 [ 4 ] & 0x07 ;
V_10 -> V_21 = F_9 ( V_12 [ 5 ] & 0x1F ) - 1 ;
V_10 -> V_22 = F_9 ( V_12 [ 6 ] ) ;
V_10 -> V_22 += 100 ;
return F_10 ( V_10 ) ;
}
static int F_11 ( struct V_1 * V_2 , struct V_9 * V_10 )
{
int V_11 ;
T_1 V_12 [ 7 ] ;
T_1 V_3 ;
if ( ( V_10 -> V_22 < 100 ) || ( V_10 -> V_22 > 199 ) )
return - V_15 ;
V_11 = F_1 ( V_2 , & V_3 ) ;
if ( V_11 != 0 )
return V_11 ;
V_12 [ 0 ] = F_12 ( V_10 -> V_16 ) & 0x7F ;
V_12 [ 1 ] = F_12 ( V_10 -> V_17 ) ;
V_12 [ 2 ] = F_12 ( V_10 -> V_18 ) ;
V_12 [ 3 ] = F_12 ( V_10 -> V_19 ) ;
V_12 [ 4 ] = V_10 -> V_20 & 0x07 ;
V_12 [ 5 ] = F_12 ( V_10 -> V_21 + 1 ) ;
V_12 [ 6 ] = F_12 ( V_10 -> V_22 - 100 ) ;
V_11 = F_13 ( V_2 , V_13 ,
sizeof( V_12 ) , V_12 ) ;
if ( V_11 < 0 ) {
F_3 ( & V_2 -> V_6 , L_5 ) ;
return V_11 ;
}
V_11 = F_5 ( V_2 , V_3 ) ;
if ( V_11 != 0 )
return V_11 ;
return 0 ;
}
static int F_14 ( struct V_23 * V_6 , struct V_9 * V_10 )
{
return F_6 ( F_15 ( V_6 ) , V_10 ) ;
}
static int F_16 ( struct V_23 * V_6 , struct V_9 * V_10 )
{
return F_11 ( F_15 ( V_6 ) , V_10 ) ;
}
static int F_17 ( struct V_1 * V_2 ,
const struct V_24 * V_25 )
{
struct V_26 * V_27 ;
int V_28 ;
F_18 ( & V_2 -> V_6 , L_6 , V_29 ) ;
if ( ! F_19 ( V_2 -> V_30 , V_31 ) )
return - V_32 ;
V_28 = F_2 ( V_2 , V_5 ) ;
if ( V_28 < 0 ) {
F_3 ( & V_2 -> V_6 , L_7 ) ;
return V_28 ;
}
V_27 = F_20 ( & V_2 -> V_6 ,
V_33 . V_34 . V_35 ,
& V_36 , V_37 ) ;
return F_21 ( V_27 ) ;
}
