static int F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
int V_4 = F_2 ( V_2 , V_3 ) ;
if ( V_4 < 0 )
F_3 ( & V_2 -> V_5 , L_1 ) ;
return V_4 ;
}
static int F_4 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_6 )
{
int V_4 = F_5 ( V_2 , V_3 , V_6 ) ;
if ( V_4 < 0 )
F_3 ( & V_2 -> V_5 , L_2 ) ;
return V_4 ;
}
static int F_6 ( struct V_7 * V_8 , unsigned V_9 )
{
struct V_10 * V_5 = F_7 ( V_8 ) ;
unsigned V_11 = F_8 ( V_9 ) ;
unsigned V_12 = F_9 ( V_9 ) ;
int V_6 ;
F_10 ( & V_5 -> V_13 ) ;
if ( V_5 -> V_14 [ V_11 ] & V_12 )
V_6 = V_5 -> V_15 [ V_11 ] ;
else
V_6 = F_1 ( V_5 -> V_2 , V_16 + V_11 ) ;
F_11 ( & V_5 -> V_13 ) ;
return ! ! ( V_6 & V_12 ) ;
}
static void F_12 ( struct V_7 * V_8 ,
unsigned V_9 , int V_6 )
{
unsigned V_11 , V_12 ;
struct V_10 * V_5 = F_7 ( V_8 ) ;
V_11 = F_8 ( V_9 ) ;
V_12 = F_9 ( V_9 ) ;
F_10 ( & V_5 -> V_13 ) ;
if ( V_6 )
V_5 -> V_15 [ V_11 ] |= V_12 ;
else
V_5 -> V_15 [ V_11 ] &= ~ V_12 ;
F_4 ( V_5 -> V_2 , V_17 + V_11 ,
V_5 -> V_15 [ V_11 ] ) ;
F_11 ( & V_5 -> V_13 ) ;
}
static int F_13 ( struct V_7 * V_8 , unsigned V_9 )
{
int V_4 ;
unsigned V_11 ;
struct V_10 * V_5 = F_7 ( V_8 ) ;
V_11 = F_8 ( V_9 ) ;
F_10 ( & V_5 -> V_13 ) ;
V_5 -> V_14 [ V_11 ] &= ~ F_9 ( V_9 ) ;
V_4 = F_4 ( V_5 -> V_2 , V_18 + V_11 , V_5 -> V_14 [ V_11 ] ) ;
F_11 ( & V_5 -> V_13 ) ;
return V_4 ;
}
static int F_14 ( struct V_7 * V_8 ,
unsigned V_9 , int V_6 )
{
int V_4 ;
unsigned V_11 , V_12 ;
struct V_10 * V_5 = F_7 ( V_8 ) ;
V_11 = F_8 ( V_9 ) ;
V_12 = F_9 ( V_9 ) ;
F_10 ( & V_5 -> V_13 ) ;
V_5 -> V_14 [ V_11 ] |= V_12 ;
if ( V_6 )
V_5 -> V_15 [ V_11 ] |= V_12 ;
else
V_5 -> V_15 [ V_11 ] &= ~ V_12 ;
V_4 = F_4 ( V_5 -> V_2 , V_17 + V_11 ,
V_5 -> V_15 [ V_11 ] ) ;
V_4 |= F_4 ( V_5 -> V_2 , V_18 + V_11 ,
V_5 -> V_14 [ V_11 ] ) ;
F_11 ( & V_5 -> V_13 ) ;
return V_4 ;
}
static int F_15 ( struct V_7 * V_8 , unsigned V_9 )
{
struct V_10 * V_5 = F_7 ( V_8 ) ;
return V_5 -> V_19 + V_9 ;
}
static void F_16 ( struct V_20 * V_21 )
{
struct V_10 * V_5 = F_17 ( V_21 ) ;
F_10 ( & V_5 -> V_22 ) ;
}
static void F_18 ( struct V_20 * V_21 )
{
struct V_10 * V_5 = F_17 ( V_21 ) ;
int V_23 ;
for ( V_23 = 0 ; V_23 <= F_8 ( V_24 ) ; V_23 ++ )
if ( V_5 -> V_25 [ V_23 ] ^ V_5 -> V_26 [ V_23 ] ) {
V_5 -> V_25 [ V_23 ] = V_5 -> V_26 [ V_23 ] ;
F_4 ( V_5 -> V_2 , V_27 + V_23 ,
V_5 -> V_25 [ V_23 ] ) ;
}
F_11 ( & V_5 -> V_22 ) ;
}
static void F_19 ( struct V_20 * V_21 )
{
struct V_10 * V_5 = F_17 ( V_21 ) ;
unsigned V_28 = V_21 -> V_29 - V_5 -> V_19 ;
V_5 -> V_26 [ F_8 ( V_28 ) ] &= ~ F_9 ( V_28 ) ;
}
static void F_20 ( struct V_20 * V_21 )
{
struct V_10 * V_5 = F_17 ( V_21 ) ;
unsigned V_28 = V_21 -> V_29 - V_5 -> V_19 ;
V_5 -> V_26 [ F_8 ( V_28 ) ] |= F_9 ( V_28 ) ;
}
static int F_21 ( struct V_20 * V_21 , unsigned int type )
{
struct V_10 * V_5 = F_17 ( V_21 ) ;
T_2 V_28 = V_21 -> V_29 - V_5 -> V_19 ;
unsigned V_11 , V_12 ;
if ( ( type & V_30 ) ) {
F_3 ( & V_5 -> V_2 -> V_5 , L_3 ,
V_21 -> V_29 , type ) ;
return - V_31 ;
}
V_11 = F_8 ( V_28 ) ;
V_12 = F_9 ( V_28 ) ;
if ( type & V_32 )
V_5 -> V_33 [ V_11 ] |= V_12 ;
else if ( type & V_34 )
V_5 -> V_33 [ V_11 ] &= ~ V_12 ;
else
return - V_31 ;
F_13 ( & V_5 -> V_7 , V_28 ) ;
F_4 ( V_5 -> V_2 , V_35 + V_11 ,
V_5 -> V_33 [ V_11 ] ) ;
return 0 ;
}
static int F_22 ( struct V_1 * V_2 , T_1 * V_36 )
{
int V_4 = F_23 ( V_2 , V_37 , 3 , V_36 ) ;
if ( V_4 < 0 )
F_3 ( & V_2 -> V_5 , L_4 ) ;
return V_4 ;
}
static T_3 F_24 ( int V_29 , void * V_38 )
{
struct V_10 * V_5 = V_38 ;
unsigned V_39 , V_11 , V_12 , V_40 ;
int V_4 ;
V_39 = F_1 ( V_5 -> V_2 , V_41 ) ;
if ( V_39 & V_42 ) {
V_4 = F_22 ( V_5 -> V_2 , V_5 -> V_43 ) ;
if ( V_4 < 0 )
memset ( V_5 -> V_43 , 0 , F_25 ( V_5 -> V_43 ) ) ;
for ( V_11 = 0 , V_12 = 0 ; V_11 <= F_8 ( V_24 ) ;
V_11 ++ , V_12 = 0 ) {
V_40 = V_5 -> V_43 [ V_11 ] & V_5 -> V_26 [ V_11 ] ;
while ( V_40 ) {
if ( V_40 & ( 1 << V_12 ) ) {
F_26 ( V_5 -> V_19 +
( V_11 << 3 ) + V_12 ) ;
V_40 &= ~ ( 1 << V_12 ) ;
}
V_12 ++ ;
}
}
}
F_4 ( V_5 -> V_2 , V_41 , V_39 ) ;
return V_44 ;
}
static int F_27 ( struct V_10 * V_5 )
{
struct V_1 * V_2 = V_5 -> V_2 ;
struct V_45 * V_46 =
F_28 ( & V_2 -> V_5 ) ;
unsigned V_28 ;
int V_4 ;
F_4 ( V_2 , V_47 , V_48 ) ;
F_4 ( V_2 , V_41 , - 1 ) ;
F_22 ( V_2 , V_5 -> V_43 ) ;
V_5 -> V_19 = V_46 -> V_19 ;
F_29 ( & V_5 -> V_22 ) ;
for ( V_28 = 0 ; V_28 < V_5 -> V_7 . V_49 ; V_28 ++ ) {
int V_29 = V_28 + V_5 -> V_19 ;
F_30 ( V_29 , V_5 ) ;
F_31 ( V_29 , & V_50 ,
V_51 ) ;
F_32 ( V_29 , 1 ) ;
F_33 ( V_29 , V_52 , V_53 ) ;
}
V_4 = F_34 ( V_2 -> V_29 ,
NULL ,
F_24 ,
V_54 | V_55 ,
F_35 ( & V_2 -> V_5 ) , V_5 ) ;
if ( V_4 ) {
F_3 ( & V_2 -> V_5 , L_5 ,
V_2 -> V_29 ) ;
goto V_56;
}
V_5 -> V_7 . V_57 = F_15 ;
F_4 ( V_2 , V_47 ,
V_48 | V_58 | V_42 ) ;
return 0 ;
V_56:
V_5 -> V_19 = 0 ;
return V_4 ;
}
static void F_36 ( struct V_10 * V_5 )
{
if ( V_5 -> V_19 )
F_37 ( V_5 -> V_2 -> V_29 , V_5 ) ;
}
static int F_27 ( struct V_10 * V_5 )
{
struct V_1 * V_2 = V_5 -> V_2 ;
F_38 ( & V_2 -> V_5 , L_6 ) ;
return 0 ;
}
static void F_36 ( struct V_10 * V_5 )
{
}
static int F_39 ( struct V_1 * V_2 ,
const struct V_59 * V_60 )
{
struct V_45 * V_46 =
F_28 ( & V_2 -> V_5 ) ;
struct V_10 * V_5 ;
struct V_7 * V_61 ;
int V_4 , V_23 , V_62 ;
if ( ! V_46 ) {
F_3 ( & V_2 -> V_5 , L_7 ) ;
return - V_63 ;
}
if ( ! F_40 ( V_2 -> V_64 ,
V_65 ) ) {
F_3 ( & V_2 -> V_5 , L_8 ) ;
return - V_66 ;
}
V_5 = F_41 ( & V_2 -> V_5 , sizeof( * V_5 ) , V_67 ) ;
if ( ! V_5 )
return - V_68 ;
V_5 -> V_2 = V_2 ;
V_61 = & V_5 -> V_7 ;
V_61 -> V_69 = F_13 ;
V_61 -> V_70 = F_14 ;
V_61 -> V_71 = F_6 ;
V_61 -> V_72 = F_12 ;
V_61 -> V_73 = true ;
V_61 -> V_74 = V_46 -> V_75 ;
V_61 -> V_49 = V_24 ;
V_61 -> V_76 = V_2 -> V_77 ;
V_61 -> V_78 = V_79 ;
V_61 -> V_80 = V_46 -> V_80 ;
F_29 ( & V_5 -> V_13 ) ;
V_4 = F_1 ( V_5 -> V_2 , V_81 ) ;
if ( V_4 < 0 )
goto V_82;
V_62 = V_4 & V_83 ;
for ( V_23 = 0 , V_4 = 0 ; V_23 <= F_8 ( V_24 ) ; V_23 ++ ) {
V_5 -> V_15 [ V_23 ] = F_1 ( V_2 , V_17 + V_23 ) ;
V_5 -> V_14 [ V_23 ] = F_1 ( V_2 , V_18 + V_23 ) ;
V_4 |= F_4 ( V_2 , V_84 + V_23 , 0 ) ;
V_4 |= F_4 ( V_2 , V_85 + V_23 ,
( V_46 -> V_86 >> ( 8 * V_23 ) ) & 0xFF ) ;
V_4 |= F_4 ( V_2 , V_27 + V_23 , 0 ) ;
if ( V_4 )
goto V_82;
}
if ( V_46 -> V_19 ) {
if ( F_42 ( V_62 ) ) {
F_38 ( & V_2 -> V_5 , L_9 ) ;
} else {
V_4 = F_27 ( V_5 ) ;
if ( V_4 )
goto V_82;
}
}
V_4 = F_43 ( & V_5 -> V_7 , V_5 ) ;
if ( V_4 )
goto V_87;
F_44 ( & V_2 -> V_5 , L_10 ,
V_46 -> V_19 , V_62 ) ;
if ( V_46 -> V_88 ) {
V_4 = V_46 -> V_88 ( V_2 , V_61 -> V_74 , V_61 -> V_49 , V_46 -> V_89 ) ;
if ( V_4 < 0 )
F_38 ( & V_2 -> V_5 , L_11 , V_4 ) ;
}
F_45 ( V_2 , V_5 ) ;
return 0 ;
V_87:
F_36 ( V_5 ) ;
V_82:
return V_4 ;
}
static int F_46 ( struct V_1 * V_2 )
{
struct V_45 * V_46 =
F_28 ( & V_2 -> V_5 ) ;
struct V_10 * V_5 = F_47 ( V_2 ) ;
int V_4 ;
if ( V_46 -> V_90 ) {
V_4 = V_46 -> V_90 ( V_2 ,
V_5 -> V_7 . V_74 , V_5 -> V_7 . V_49 ,
V_46 -> V_89 ) ;
if ( V_4 < 0 ) {
F_3 ( & V_2 -> V_5 , L_12 , V_4 ) ;
return V_4 ;
}
}
if ( V_5 -> V_19 )
F_37 ( V_5 -> V_2 -> V_29 , V_5 ) ;
F_48 ( & V_5 -> V_7 ) ;
return 0 ;
}
