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
static void F_9 ( struct V_1 * V_2 , int V_12 )
{
F_5 ( V_2 , V_13 , ( 1 << 6 ) , ( V_12 ) << 6 ) ;
}
static void F_10 ( struct V_1 * V_2 ,
struct V_14 * V_15 ,
struct V_16 * V_8 )
{
struct V_17 * V_18 = V_15 -> V_18 ;
struct V_19 * V_10 = V_2 -> V_10 ;
T_1 V_20 , V_21 ;
T_1 V_22 , V_23 , V_24 , V_25 ;
V_24 = ~ 0 ;
V_23 = 0 ;
V_20 = 0 ;
for ( V_21 = 0x00 ; V_21 <= 0x3F ; V_21 ++ ) {
V_22 = F_11 ( V_2 -> V_26 ) ;
if ( V_21 & ( 1 << 5 ) )
V_22 /= 128 ;
else
V_22 /= 16 ;
V_22 /= ( ( ( V_21 & 0x1F ) + 1 ) * 2 ) ;
V_25 = abs ( V_8 -> V_27 - V_22 ) ;
if ( V_25 < V_24 ) {
V_24 = V_25 ;
V_20 = V_21 ;
V_23 = V_22 ;
}
}
if ( V_18 -> V_28 & V_29 )
V_20 |= 1 << 7 ;
if ( V_18 -> V_28 & V_30 )
V_20 |= 1 << 6 ;
F_12 ( V_10 , L_2 , V_8 -> V_27 , V_23 ) ;
F_1 ( V_2 , V_31 , V_20 ) ;
F_1 ( V_2 , V_9 , 0x0 ) ;
F_1 ( V_2 , V_13 , 0x21 ) ;
}
static int F_13 ( struct V_32 * V_33 ,
struct V_14 * V_15 )
{
struct V_1 * V_2 = F_14 ( V_33 ) ;
struct V_16 * V_8 ;
T_1 V_34 ;
T_1 V_35 ;
int V_36 , V_37 ;
unsigned int V_38 ;
const int V_39 = 50 ;
F_12 ( V_2 -> V_10 , L_3 , V_40 ) ;
V_38 = 1 ;
V_36 = 0 ;
F_15 (t, &msg->transfers, transfer_list) {
if ( V_38 ) {
F_10 ( V_2 , V_15 , V_8 ) ;
F_16 ( V_2 ) ;
F_17 ( V_39 ) ;
}
V_38 = V_8 -> V_38 ;
for ( V_37 = 0 ; V_37 < V_8 -> V_41 ; V_37 ++ ) {
V_36 = F_6 ( V_2 , 0x1 , 0 ) ;
if ( V_36 < 0 )
break;
V_34 = 0 ;
if ( V_8 -> V_42 )
V_34 = ( T_1 ) ( ( V_43 * ) V_8 -> V_42 ) [ V_37 ] ;
F_1 ( V_2 , V_44 , V_34 ) ;
V_36 = F_6 ( V_2 , 0x4 , 0x4 ) ;
if ( V_36 < 0 )
break;
V_35 = F_3 ( V_2 , V_45 ) ;
if ( V_8 -> V_46 )
( ( V_43 * ) V_8 -> V_46 ) [ V_37 ] = ( V_43 ) V_35 ;
}
V_15 -> V_47 += V_8 -> V_41 ;
if ( V_8 -> V_48 )
F_7 ( V_8 -> V_48 ) ;
if ( V_38 ) {
F_17 ( V_39 ) ;
F_18 ( V_2 ) ;
F_17 ( V_39 ) ;
}
}
V_15 -> V_49 = V_36 ;
if ( ! V_38 ) {
F_17 ( V_39 ) ;
F_18 ( V_2 ) ;
}
F_19 ( V_33 ) ;
return V_36 ;
}
static int F_20 ( struct V_50 * V_51 )
{
struct V_52 * V_53 ;
struct V_32 * V_33 ;
struct V_1 * V_2 ;
struct V_26 * V_26 ;
int V_36 ;
V_53 = F_21 ( V_51 , V_54 , 0 ) ;
if ( ! V_53 ) {
F_8 ( & V_51 -> V_10 , L_4 ) ;
return - V_55 ;
}
V_33 = F_22 ( & V_51 -> V_10 , sizeof( * V_2 ) ) ;
if ( ! V_33 ) {
F_8 ( & V_51 -> V_10 , L_5 ) ;
return - V_56 ;
}
V_26 = F_23 ( & V_51 -> V_10 , NULL ) ;
if ( F_24 ( V_26 ) ) {
F_8 ( & V_51 -> V_10 , L_6 ) ;
V_36 = - V_55 ;
goto V_57;
}
V_2 = F_14 ( V_33 ) ;
F_25 ( V_51 , V_2 ) ;
V_2 -> V_33 = V_33 ;
V_2 -> V_10 = & V_51 -> V_10 ;
V_2 -> V_26 = V_26 ;
V_2 -> V_5 = F_26 ( V_2 -> V_10 ,
V_53 -> V_58 , F_27 ( V_53 ) ) ;
if ( ! V_2 -> V_5 ) {
F_8 ( & V_51 -> V_10 , L_7 ) ;
V_36 = - V_56 ;
goto V_59;
}
F_28 ( & V_51 -> V_10 ) ;
V_33 -> V_60 = V_51 -> V_61 ;
V_33 -> V_62 = V_30 | V_29 ;
V_33 -> V_10 . V_63 = V_51 -> V_10 . V_63 ;
V_33 -> V_64 = true ;
V_33 -> V_65 = F_13 ;
V_33 -> V_66 = F_29 ( 8 ) ;
V_36 = F_30 ( & V_51 -> V_10 , V_33 ) ;
if ( V_36 < 0 ) {
F_8 ( & V_51 -> V_10 , L_8 ) ;
goto V_67;
}
return 0 ;
V_67:
F_31 ( & V_51 -> V_10 ) ;
V_59:
F_32 ( V_26 ) ;
V_57:
F_33 ( V_33 ) ;
return V_36 ;
}
static int F_34 ( struct V_50 * V_51 )
{
struct V_1 * V_2 = F_35 ( V_51 ) ;
F_31 ( & V_51 -> V_10 ) ;
F_32 ( V_2 -> V_26 ) ;
return 0 ;
}
