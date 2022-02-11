static int
F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 * V_4 ,
unsigned V_5 )
{
int V_6 ;
if ( ( V_3 > V_7 + 7 ) ||
( V_3 + V_5 > V_7 + 8 ) )
return - V_8 ;
V_6 = F_2 ( V_2 , V_3 , V_5 , V_4 ) ;
if ( V_6 < 0 )
return V_6 ;
if ( V_6 < V_5 )
return - V_9 ;
return 0 ;
}
static int
F_3 ( struct V_1 * V_2 , T_1 V_3 , T_1 const V_4 [] ,
unsigned V_5 )
{
if ( ( V_3 > V_7 + 7 ) ||
( V_3 + V_5 > V_7 + 8 ) )
return - V_8 ;
return F_4 ( V_2 , V_3 , V_5 , V_4 ) ;
}
static int
F_5 ( struct V_1 * V_2 , T_1 * V_4 )
{
int V_6 = F_1 ( V_2 , V_10 , V_4 , 1 ) ;
if ( V_6 < 0 )
return - V_9 ;
F_6 ( & V_2 -> V_11 , L_1 , V_4 [ 0 ] , V_4 [ 0 ] ) ;
return 0 ;
}
static int
F_7 ( struct V_1 * V_2 , T_1 V_12 )
{
T_1 V_4 [ 1 ] ;
int V_13 ;
V_4 [ 0 ] = V_12 ;
V_13 = F_3 ( V_2 , V_10 , V_4 , 1 ) ;
F_6 ( & V_2 -> V_11 , L_1 , V_4 [ 0 ] , V_4 [ 0 ] ) ;
if ( V_13 < 0 )
return - V_9 ;
return 0 ;
}
static int
F_8 ( struct V_1 * V_2 , struct V_14 * V_15 )
{
T_1 V_4 [ 1 ] ;
int V_6 ;
T_1 V_16 [ V_17 ] = { 0 , } ;
V_6 = F_5 ( V_2 , V_4 ) ;
if ( V_6 < 0 ) {
F_9 ( & V_2 -> V_11 , L_2 , V_18 ) ;
return - V_9 ;
}
V_6 = F_1 ( V_2 , V_19 , V_16 ,
V_17 ) ;
if ( V_6 < 0 ) {
F_9 ( & V_2 -> V_11 , L_3 ,
V_18 ) ;
return V_6 ;
}
V_15 -> V_20 = F_10 ( V_16 [ V_19 - V_19 ] ) ;
V_15 -> V_21 = F_10 ( V_16 [ V_22 - V_19 ] ) ;
{
const T_1 V_23 = V_16 [ V_24 - V_19 ] ;
if ( V_23 & V_25 ) {
V_15 -> V_26 = F_10 ( V_23 & 0x1f ) ;
if ( V_23 & V_27 )
V_15 -> V_26 += 12 ;
} else
V_15 -> V_26 = F_10 ( V_23 & 0x3f ) ;
}
V_15 -> V_28 = F_10 ( V_16 [ V_29 - V_19 ] ) ;
V_15 -> V_30 = F_10 ( V_16 [ V_31 - V_19 ] ) - 1 ;
V_15 -> V_32 = F_10 ( V_16 [ V_33 - V_19 ] ) + 100 ;
V_15 -> V_34 = F_10 ( V_16 [ V_35 - V_19 ] ) - 1 ;
return 0 ;
}
static int F_11 ( struct V_36 * V_11 , struct V_14 * V_15 )
{
return F_8 ( F_12 ( V_11 ) , V_15 ) ;
}
static int
F_13 ( struct V_1 * V_2 , struct V_37 * V_38 )
{
struct V_14 * const V_15 = & V_38 -> time ;
int V_6 ;
T_1 V_16 [ 8 ] ;
V_6 = F_5 ( V_2 , V_16 ) ;
if ( V_6 < 0 ) {
F_9 ( & V_2 -> V_11 , L_2 , V_18 ) ;
return - V_9 ;
}
V_6 = F_1 ( V_2 , V_39 , V_16 ,
V_40 ) ;
if ( V_6 < 0 ) {
F_9 ( & V_2 -> V_11 , L_4 ,
V_18 ) ;
return V_6 ;
}
V_15 -> V_20 = F_10 ( V_16 [ V_39 - V_39 ] & 0x7f ) ;
V_15 -> V_21 = F_10 ( V_16 [ V_41 - V_39 ] & 0x7f ) ;
V_15 -> V_26 = F_10 ( V_16 [ V_42 - V_39 ] & 0x3f ) ;
V_15 -> V_28 = F_10 ( V_16 [ V_43 - V_39 ] & 0x3f ) ;
V_15 -> V_30 = F_10 ( V_16 [ V_44 - V_39 ] & 0x1f ) - 1 ;
V_15 -> V_32 = F_10 ( V_16 [ V_45 - V_39 ] & 0x7f ) + 100 ;
V_15 -> V_34 = F_10 ( V_16 [ V_46 - V_39 ] & 0x07 ) - 1 ;
return 0 ;
}
static int
F_14 ( struct V_36 * V_11 , struct V_37 * V_38 )
{
return F_13 ( F_12 ( V_11 ) , V_38 ) ;
}
static int F_15 ( struct V_1 * V_2 ,
int V_47 )
{
int V_6 ;
T_1 V_4 [ 1 ] ;
V_6 = F_1 ( V_2 , V_48 , V_4 , 1 ) ;
if ( V_6 < 0 ) {
F_9 ( & V_2 -> V_11 , L_5 ) ;
return V_6 ;
}
if ( V_47 )
V_4 [ 0 ] |= V_49 ;
else
V_4 [ 0 ] &= ~ V_49 ;
V_6 = F_3 ( V_2 , V_48 , V_4 , 1 ) ;
if ( V_6 < 0 ) {
F_9 ( & V_2 -> V_11 , L_6 ) ;
return V_6 ;
}
return 0 ;
}
static int F_16 ( struct V_1 * V_2 ,
struct V_37 * V_38 )
{
struct V_14 * const V_15 = & V_38 -> time ;
int V_6 ;
T_1 V_16 [ 8 ] ;
if ( V_15 -> V_32 < 100 )
return - V_8 ;
V_6 = F_5 ( V_2 , V_16 ) ;
if ( V_6 < 0 ) {
F_9 ( & V_2 -> V_11 , L_2 , V_18 ) ;
return - V_9 ;
}
V_16 [ V_39 - V_39 ] = F_17 ( V_15 -> V_20 & 0x7f ) ;
V_16 [ V_41 - V_39 ] = F_17 ( V_15 -> V_21 & 0x7f ) ;
V_16 [ V_42 - V_39 ] = F_17 ( V_15 -> V_26 & 0x3f ) ;
V_16 [ V_43 - V_39 ] = F_17 ( V_15 -> V_28 & 0x3f ) ;
V_16 [ V_44 - V_39 ] = F_17 ( ( V_15 -> V_30 & 0x1f ) - 1 ) ;
V_16 [ V_46 - V_39 ] = F_17 ( ( V_15 -> V_34 & 7 ) - 1 ) ;
V_16 [ V_45 - V_39 ] = F_17 ( ( V_15 -> V_32 & 0x7f ) - 100 ) ;
V_6 = F_3 ( V_2 , V_39 , V_16 ,
V_40 ) ;
if ( V_6 < 0 )
return V_6 ;
if ( V_38 -> V_50 ) {
T_1 V_4 [ 1 ] ;
V_6 = F_1 ( V_2 , V_51 ,
V_4 , 1 ) ;
if ( V_6 < 0 ) {
F_9 ( & V_2 -> V_11 , L_7 ) ;
return V_6 ;
}
V_4 [ 0 ] &= ~ V_52 ;
V_6 = F_3 ( V_2 , V_51 ,
V_4 , 1 ) ;
if ( V_6 < 0 ) {
F_9 ( & V_2 -> V_11 , L_8 ) ;
return V_6 ;
}
V_6 = F_15 ( V_2 , 1 ) ;
if ( V_6 )
return V_6 ;
F_6 ( & V_2 -> V_11 , L_9 ) ;
} else {
V_6 = F_15 ( V_2 , 1 ) ;
if ( V_6 )
return V_6 ;
F_6 ( & V_2 -> V_11 , L_10 ) ;
}
return 0 ;
}
static int F_18 ( struct V_36 * V_11 , struct V_37 * V_38 )
{
return F_16 ( F_12 ( V_11 ) , V_38 ) ;
}
static int
F_19 ( struct V_1 * V_2 , struct V_14 const * V_15 )
{
T_1 V_16 [ 8 ] ;
int V_6 ;
if ( V_15 -> V_32 < 100 )
return - V_8 ;
V_16 [ V_19 - V_19 ] = F_17 ( V_15 -> V_20 ) ;
V_16 [ V_22 - V_19 ] = F_17 ( V_15 -> V_21 ) ;
V_16 [ V_24 - V_19 ] = F_17 ( V_15 -> V_26 ) ;
V_16 [ V_29 - V_19 ] = F_17 ( V_15 -> V_28 ) ;
V_16 [ V_31 - V_19 ] = F_17 ( V_15 -> V_30 + 1 ) ;
V_16 [ V_35 - V_19 ] = F_17 ( ( V_15 -> V_34 & 7 ) + 1 ) ;
V_16 [ V_33 - V_19 ] = F_17 ( V_15 -> V_32 - 100 ) ;
V_6 = F_3 ( V_2 , V_19 , V_16 ,
V_17 ) ;
if ( V_6 < 0 )
return V_6 ;
V_6 = F_5 ( V_2 , V_16 ) ;
if ( V_6 < 0 ) {
F_9 ( & V_2 -> V_11 , L_2 , V_18 ) ;
return V_6 ;
}
V_6 = F_7 ( V_2 , ( V_16 [ 0 ] & ~ V_53 ) ) ;
if ( V_6 < 0 ) {
F_9 ( & V_2 -> V_11 , L_2 , V_18 ) ;
return V_6 ;
}
return 0 ;
}
static int F_20 ( struct V_36 * V_11 , struct V_14 * V_15 )
{
return F_19 ( F_12 ( V_11 ) , V_15 ) ;
}
static int T_2
F_21 ( struct V_1 * V_2 , const struct V_54 * V_55 )
{
struct V_56 * V_57 ;
int V_58 = 0 ;
T_1 V_4 [ 1 ] ;
if ( ! F_22 ( V_2 -> V_59 , V_60 ) )
return - V_61 ;
V_57 = F_23 ( V_2 -> V_62 ,
& V_2 -> V_11 , & V_63 ,
V_64 ) ;
if ( F_24 ( V_57 ) )
return F_25 ( V_57 ) ;
F_26 ( V_2 , V_57 ) ;
V_58 = F_5 ( V_2 , V_4 ) ;
if ( V_58 < 0 ) {
F_9 ( & V_2 -> V_11 , L_11 ) ;
goto V_65;
}
return 0 ;
V_65:
F_27 ( V_57 ) ;
return V_58 ;
}
static int T_3 F_28 ( struct V_1 * V_2 )
{
struct V_56 * V_57 = F_29 ( V_2 ) ;
F_27 ( V_57 ) ;
return 0 ;
}
