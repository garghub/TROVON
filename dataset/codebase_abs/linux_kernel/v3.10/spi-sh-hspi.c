static void F_1 ( struct V_1 * V_2 , int V_3 , T_1 V_4 )
{
F_2 ( V_4 , V_2 -> V_5 + V_3 ) ;
}
static T_1 F_3 ( struct V_1 * V_2 , int V_3 )
{
return F_4 ( V_2 -> V_5 + V_3 ) ;
}
static void F_5 ( struct V_1 * V_2 , int V_3 , T_1 V_6 , T_1 V_7 )
{
T_1 V_4 = F_3 ( V_2 , V_3 ) ;
V_4 &= ~ V_6 ;
V_4 |= V_7 & V_6 ;
F_1 ( V_2 , V_3 , V_4 ) ;
}
static int F_6 ( struct V_1 * V_2 , T_1 V_6 , T_1 V_4 )
{
int V_8 = 256 ;
while ( V_8 -- ) {
if ( ( V_6 & F_3 ( V_2 , V_9 ) ) == V_4 )
return 0 ;
F_7 ( 10 ) ;
}
F_8 ( V_2 -> V_10 , L_1 ) ;
return - V_11 ;
}
static int F_9 ( struct V_12 * V_13 )
{
struct V_1 * V_2 = F_10 ( V_13 ) ;
F_11 ( V_2 -> V_10 ) ;
return 0 ;
}
static int F_12 ( struct V_12 * V_13 )
{
struct V_1 * V_2 = F_10 ( V_13 ) ;
F_13 ( V_2 -> V_10 ) ;
return 0 ;
}
static void F_14 ( struct V_1 * V_2 , int V_14 )
{
F_5 ( V_2 , V_15 , ( 1 << 6 ) , ( V_14 ) << 6 ) ;
}
static void F_15 ( struct V_1 * V_2 ,
struct V_16 * V_17 ,
struct V_18 * V_8 )
{
struct V_19 * V_20 = V_17 -> V_20 ;
struct V_21 * V_10 = V_2 -> V_10 ;
T_1 V_22 ;
T_1 V_23 , V_24 ;
T_1 V_25 , V_26 , V_27 , V_28 ;
V_22 = V_8 ? V_8 -> V_29 : 0 ;
if ( ! V_22 )
V_22 = V_20 -> V_30 ;
V_27 = ~ 0 ;
V_26 = 0 ;
V_23 = 0 ;
for ( V_24 = 0x00 ; V_24 <= 0x3F ; V_24 ++ ) {
V_25 = F_16 ( V_2 -> V_31 ) ;
if ( V_24 & ( 1 << 5 ) )
V_25 /= 128 ;
else
V_25 /= 16 ;
V_25 /= ( ( ( V_24 & 0x1F ) + 1 ) * 2 ) ;
V_28 = abs ( V_22 - V_25 ) ;
if ( V_28 < V_27 ) {
V_27 = V_28 ;
V_23 = V_24 ;
V_26 = V_25 ;
}
}
if ( V_20 -> V_32 & V_33 )
V_23 |= 1 << 7 ;
if ( V_20 -> V_32 & V_34 )
V_23 |= 1 << 6 ;
F_17 ( V_10 , L_2 , V_22 , V_26 ) ;
F_1 ( V_2 , V_35 , V_23 ) ;
F_1 ( V_2 , V_9 , 0x0 ) ;
F_1 ( V_2 , V_15 , 0x21 ) ;
}
static int F_18 ( struct V_12 * V_13 ,
struct V_16 * V_17 )
{
struct V_1 * V_2 = F_10 ( V_13 ) ;
struct V_18 * V_8 ;
T_1 V_36 ;
T_1 V_37 ;
int V_38 , V_39 ;
unsigned int V_40 ;
const int V_41 = 50 ;
F_17 ( V_2 -> V_10 , L_3 , V_42 ) ;
V_40 = 1 ;
V_38 = 0 ;
F_19 (t, &msg->transfers, transfer_list) {
if ( V_40 ) {
F_15 ( V_2 , V_17 , V_8 ) ;
F_20 ( V_2 ) ;
F_21 ( V_41 ) ;
}
V_40 = V_8 -> V_40 ;
for ( V_39 = 0 ; V_39 < V_8 -> V_43 ; V_39 ++ ) {
V_38 = F_6 ( V_2 , 0x1 , 0 ) ;
if ( V_38 < 0 )
break;
V_36 = 0 ;
if ( V_8 -> V_44 )
V_36 = ( T_1 ) ( ( V_45 * ) V_8 -> V_44 ) [ V_39 ] ;
F_1 ( V_2 , V_46 , V_36 ) ;
V_38 = F_6 ( V_2 , 0x4 , 0x4 ) ;
if ( V_38 < 0 )
break;
V_37 = F_3 ( V_2 , V_47 ) ;
if ( V_8 -> V_48 )
( ( V_45 * ) V_8 -> V_48 ) [ V_39 ] = ( V_45 ) V_37 ;
}
V_17 -> V_49 += V_8 -> V_43 ;
if ( V_8 -> V_50 )
F_7 ( V_8 -> V_50 ) ;
if ( V_40 ) {
F_21 ( V_41 ) ;
F_22 ( V_2 ) ;
F_21 ( V_41 ) ;
}
}
V_17 -> V_51 = V_38 ;
if ( ! V_40 ) {
F_21 ( V_41 ) ;
F_22 ( V_2 ) ;
}
F_23 ( V_13 ) ;
return V_38 ;
}
static int F_24 ( struct V_19 * V_20 )
{
struct V_1 * V_2 = F_10 ( V_20 -> V_13 ) ;
struct V_21 * V_10 = V_2 -> V_10 ;
if ( 8 != V_20 -> V_52 ) {
F_8 ( V_10 , L_4 ) ;
return - V_53 ;
}
F_17 ( V_10 , L_5 , V_20 -> V_54 ) ;
return 0 ;
}
static void F_25 ( struct V_19 * V_20 )
{
struct V_1 * V_2 = F_10 ( V_20 -> V_13 ) ;
struct V_21 * V_10 = V_2 -> V_10 ;
F_17 ( V_10 , L_6 , V_20 -> V_54 ) ;
}
static int F_26 ( struct V_55 * V_56 )
{
struct V_57 * V_58 ;
struct V_12 * V_13 ;
struct V_1 * V_2 ;
struct V_31 * V_31 ;
int V_38 ;
V_58 = F_27 ( V_56 , V_59 , 0 ) ;
if ( ! V_58 ) {
F_8 ( & V_56 -> V_10 , L_7 ) ;
return - V_60 ;
}
V_13 = F_28 ( & V_56 -> V_10 , sizeof( * V_2 ) ) ;
if ( ! V_13 ) {
F_8 ( & V_56 -> V_10 , L_8 ) ;
return - V_61 ;
}
V_31 = F_29 ( NULL , L_9 ) ;
if ( F_30 ( V_31 ) ) {
F_8 ( & V_56 -> V_10 , L_10 ) ;
V_38 = - V_60 ;
goto V_62;
}
V_2 = F_10 ( V_13 ) ;
F_31 ( & V_56 -> V_10 , V_2 ) ;
V_2 -> V_13 = V_13 ;
V_2 -> V_10 = & V_56 -> V_10 ;
V_2 -> V_31 = V_31 ;
V_2 -> V_5 = F_32 ( V_2 -> V_10 ,
V_58 -> V_63 , F_33 ( V_58 ) ) ;
if ( ! V_2 -> V_5 ) {
F_8 ( & V_56 -> V_10 , L_11 ) ;
V_38 = - V_61 ;
goto V_64;
}
V_13 -> V_65 = 1 ;
V_13 -> V_66 = V_56 -> V_67 ;
V_13 -> V_68 = F_24 ;
V_13 -> V_69 = F_25 ;
V_13 -> V_70 = V_34 | V_33 ;
V_13 -> V_71 = F_9 ;
V_13 -> V_72 = F_18 ;
V_13 -> V_73 = F_12 ;
V_38 = F_34 ( V_13 ) ;
if ( V_38 < 0 ) {
F_8 ( & V_56 -> V_10 , L_12 ) ;
goto V_64;
}
F_35 ( & V_56 -> V_10 ) ;
F_36 ( & V_56 -> V_10 , L_13 ) ;
return 0 ;
V_64:
F_37 ( V_31 ) ;
V_62:
F_38 ( V_13 ) ;
return V_38 ;
}
static int F_39 ( struct V_55 * V_56 )
{
struct V_1 * V_2 = F_40 ( & V_56 -> V_10 ) ;
F_41 ( & V_56 -> V_10 ) ;
F_37 ( V_2 -> V_31 ) ;
F_42 ( V_2 -> V_13 ) ;
return 0 ;
}
