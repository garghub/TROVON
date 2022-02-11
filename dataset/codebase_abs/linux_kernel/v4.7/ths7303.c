static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static int F_3 ( struct V_2 * V_3 , T_1 V_4 )
{
struct V_5 * V_6 = F_4 ( V_3 ) ;
return F_5 ( V_6 , V_4 ) ;
}
static int F_6 ( struct V_2 * V_3 , T_1 V_4 , T_1 V_7 )
{
struct V_5 * V_6 = F_4 ( V_3 ) ;
int V_8 ;
int V_9 ;
for ( V_9 = 0 ; V_9 < 3 ; V_9 ++ ) {
V_8 = F_7 ( V_6 , V_4 , V_7 ) ;
if ( V_8 == 0 )
return 0 ;
}
return V_8 ;
}
static int F_8 ( struct V_2 * V_3 ,
enum V_10 V_11 )
{
struct V_5 * V_6 = F_4 ( V_3 ) ;
struct V_1 * V_12 = F_1 ( V_3 ) ;
const struct V_13 * V_14 = V_12 -> V_14 ;
T_1 V_7 , V_15 = 0 ;
int V_16 , V_17 = 0 ;
if ( ! V_6 )
return - V_18 ;
switch ( V_11 ) {
case V_19 :
V_15 = 0x3 ;
break;
case V_20 :
V_15 = 0x2 ;
break;
case V_21 :
V_15 = 0x1 ;
break;
case V_22 :
V_15 = 0x0 ;
break;
default:
V_17 = 1 ;
}
V_7 = ( V_15 << 6 ) | ( V_15 << 3 ) ;
if ( ! V_17 )
V_7 |= ( V_14 -> V_23 & 0x27 ) ;
V_16 = F_6 ( V_3 , V_24 , V_7 ) ;
if ( V_16 )
goto V_25;
V_7 = ( V_15 << 6 ) | ( V_15 << 3 ) ;
if ( ! V_17 )
V_7 |= ( V_14 -> V_26 & 0x27 ) ;
V_16 = F_6 ( V_3 , V_27 , V_7 ) ;
if ( V_16 )
goto V_25;
V_7 = ( V_15 << 6 ) | ( V_15 << 3 ) ;
if ( ! V_17 )
V_7 |= ( V_14 -> V_28 & 0x27 ) ;
V_16 = F_6 ( V_3 , V_29 , V_7 ) ;
if ( V_16 )
goto V_25;
return 0 ;
V_25:
F_9 ( L_1 ) ;
return V_16 ;
}
static int F_10 ( struct V_2 * V_3 , T_2 V_30 )
{
struct V_1 * V_12 = F_1 ( V_3 ) ;
if ( V_30 & ( V_31 & ~ V_32 ) ) {
V_12 -> V_33 = 1 ;
V_12 -> V_34 . V_35 = 0 ;
return F_8 ( V_3 , V_22 ) ;
}
return F_8 ( V_3 , V_36 ) ;
}
static int F_11 ( struct V_2 * V_3 )
{
struct V_1 * V_12 = F_1 ( V_3 ) ;
int V_37 ;
if ( ! V_12 -> V_38 ) {
F_6 ( V_3 , V_24 ,
( F_3 ( V_3 , V_24 ) & 0xf8 ) |
0x00 ) ;
F_6 ( V_3 , V_27 ,
( F_3 ( V_3 , V_27 ) & 0xf8 ) |
0x00 ) ;
F_6 ( V_3 , V_29 ,
( F_3 ( V_3 , V_29 ) & 0xf8 ) |
0x00 ) ;
return 0 ;
}
if ( V_12 -> V_34 . V_35 > 120000000 )
V_37 = F_8 ( V_3 , V_19 ) ;
else if ( V_12 -> V_34 . V_35 > 70000000 )
V_37 = F_8 ( V_3 , V_20 ) ;
else if ( V_12 -> V_34 . V_35 > 20000000 )
V_37 = F_8 ( V_3 , V_21 ) ;
else if ( V_12 -> V_33 )
V_37 = F_8 ( V_3 , V_22 ) ;
else
V_37 = F_8 ( V_3 , V_36 ) ;
return V_37 ;
}
static int F_12 ( struct V_2 * V_3 , int V_39 )
{
struct V_1 * V_12 = F_1 ( V_3 ) ;
V_12 -> V_38 = V_39 ;
return F_11 ( V_3 ) ;
}
static int F_13 ( struct V_2 * V_3 ,
struct V_40 * V_41 )
{
struct V_1 * V_12 = F_1 ( V_3 ) ;
if ( ! V_41 || V_41 -> type != V_42 )
return - V_18 ;
V_12 -> V_34 = V_41 -> V_34 ;
V_12 -> V_33 = 0 ;
return F_11 ( V_3 ) ;
}
static int F_14 ( struct V_2 * V_3 ,
struct V_43 * V_4 )
{
V_4 -> V_44 = 1 ;
V_4 -> V_7 = F_3 ( V_3 , V_4 -> V_4 ) ;
return 0 ;
}
static int F_15 ( struct V_2 * V_3 ,
const struct V_43 * V_4 )
{
F_6 ( V_3 , V_4 -> V_4 , V_4 -> V_7 ) ;
return 0 ;
}
static void F_16 ( struct V_2 * V_3 , T_1 V_4 )
{
T_1 V_7 = F_3 ( V_3 , V_4 ) ;
if ( ( V_7 & 0x7 ) == 0 ) {
F_17 ( V_3 , L_2 , V_4 ) ;
return;
}
F_17 ( V_3 , L_3 , V_4 ) ;
F_17 ( V_3 , L_4 , V_7 ) ;
F_17 ( V_3 , L_5 , V_45 [ ( V_7 >> 6 ) & 0x3 ] ) ;
F_17 ( V_3 , L_5 , V_46 [ ( V_7 >> 5 ) & 0x1 ] ) ;
F_17 ( V_3 , L_5 , V_47 [ ( V_7 >> 3 ) & 0x3 ] ) ;
F_17 ( V_3 , L_5 , V_48 [ ( V_7 >> 0 ) & 0x7 ] ) ;
}
static int F_18 ( struct V_2 * V_3 )
{
struct V_1 * V_12 = F_1 ( V_3 ) ;
F_17 ( V_3 , L_6 , V_12 -> V_38 ? L_7 : L_8 ) ;
if ( V_12 -> V_34 . V_35 ) {
struct V_49 * V_34 = & V_12 -> V_34 ;
T_3 V_50 , V_51 ;
V_50 = F_19 ( V_34 ) ;
V_51 = F_20 ( V_34 ) ;
F_17 ( V_3 ,
L_9 ,
V_34 -> V_52 , V_34 -> V_53 , V_34 -> V_54 ? L_10 : L_11 ,
( V_51 * V_50 ) > 0 ?
( int ) V_34 -> V_35 /
( V_51 * V_50 ) : 0 ,
V_50 , V_51 ,
( int ) V_34 -> V_35 , V_34 -> V_55 ) ;
} else {
F_17 ( V_3 , L_12 ) ;
}
F_16 ( V_3 , V_24 ) ;
F_16 ( V_3 , V_27 ) ;
F_16 ( V_3 , V_29 ) ;
return 0 ;
}
static int F_21 ( struct V_5 * V_6 ,
const struct V_56 * V_57 )
{
struct V_13 * V_14 = V_6 -> V_58 . V_59 ;
struct V_1 * V_12 ;
struct V_2 * V_3 ;
if ( V_14 == NULL ) {
F_22 ( & V_6 -> V_58 , L_13 ) ;
return - V_18 ;
}
if ( ! F_23 ( V_6 -> V_60 , V_61 ) )
return - V_62 ;
F_24 ( V_6 , L_14 ,
V_6 -> V_63 << 1 , V_6 -> V_60 -> V_64 ) ;
V_12 = F_25 ( & V_6 -> V_58 , sizeof( struct V_1 ) ,
V_65 ) ;
if ( ! V_12 )
return - V_66 ;
V_12 -> V_14 = V_14 ;
V_3 = & V_12 -> V_3 ;
F_26 ( V_3 , V_6 , & V_67 ) ;
if ( F_8 ( V_3 , V_22 ) < 0 ) {
F_27 ( V_6 , L_15 ) ;
return - V_18 ;
}
return 0 ;
}
static int F_28 ( struct V_5 * V_6 )
{
struct V_2 * V_3 = F_29 ( V_6 ) ;
F_30 ( V_3 ) ;
return 0 ;
}
