static void F_1 ( struct V_1 * V_2 , int V_3 , T_1 V_4 )
{
F_2 ( V_4 , V_2 -> V_5 + V_3 ) ;
}
static T_1 F_3 ( struct V_1 * V_2 , int V_3 )
{
return F_4 ( V_2 -> V_5 + V_3 ) ;
}
static int F_5 ( struct V_1 * V_2 , T_1 V_6 , T_1 V_4 )
{
int V_7 = 256 ;
while ( V_7 -- ) {
if ( ( V_6 & F_3 ( V_2 , V_8 ) ) == V_4 )
return 0 ;
F_6 ( 20 ) ;
}
F_7 ( V_2 -> V_9 , L_1 ) ;
return - V_10 ;
}
static int F_8 ( struct V_11 * V_12 )
{
struct V_1 * V_2 = F_9 ( V_12 ) ;
F_10 ( V_2 -> V_9 ) ;
return 0 ;
}
static int F_11 ( struct V_11 * V_12 )
{
struct V_1 * V_2 = F_9 ( V_12 ) ;
F_12 ( V_2 -> V_9 ) ;
return 0 ;
}
static void F_13 ( struct V_1 * V_2 ,
struct V_13 * V_14 ,
struct V_15 * V_7 )
{
struct V_16 * V_17 = V_14 -> V_17 ;
struct V_18 * V_9 = V_2 -> V_9 ;
T_1 V_19 ;
T_1 V_20 , V_21 ;
T_1 V_22 , V_23 , V_24 , V_25 ;
V_19 = V_7 ? V_7 -> V_26 : 0 ;
if ( ! V_19 )
V_19 = V_17 -> V_27 ;
V_24 = ~ 0 ;
V_23 = 0 ;
V_20 = 0 ;
for ( V_21 = 0x00 ; V_21 <= 0x3F ; V_21 ++ ) {
V_22 = F_14 ( V_2 -> V_28 ) ;
if ( V_21 & ( 1 << 5 ) )
V_22 /= 128 ;
else
V_22 /= 16 ;
V_22 /= ( ( ( V_21 & 0x1F ) + 1 ) * 2 ) ;
V_25 = abs ( V_19 - V_22 ) ;
if ( V_25 < V_24 ) {
V_24 = V_25 ;
V_20 = V_21 ;
V_23 = V_22 ;
}
}
if ( V_17 -> V_29 & V_30 )
V_20 |= 1 << 7 ;
if ( V_17 -> V_29 & V_31 )
V_20 |= 1 << 6 ;
F_15 ( V_9 , L_2 , V_19 , V_23 ) ;
F_1 ( V_2 , V_32 , V_20 ) ;
F_1 ( V_2 , V_8 , 0x0 ) ;
F_1 ( V_2 , V_33 , 0x1 ) ;
}
static int F_16 ( struct V_11 * V_12 ,
struct V_13 * V_14 )
{
struct V_1 * V_2 = F_9 ( V_12 ) ;
struct V_15 * V_7 ;
T_1 V_34 ;
T_1 V_35 ;
int V_36 , V_37 ;
F_15 ( V_2 -> V_9 , L_3 , V_38 ) ;
V_36 = 0 ;
F_17 (t, &msg->transfers, transfer_list) {
F_13 ( V_2 , V_14 , V_7 ) ;
for ( V_37 = 0 ; V_37 < V_7 -> V_39 ; V_37 ++ ) {
V_36 = F_5 ( V_2 , 0x1 , 0 ) ;
if ( V_36 < 0 )
break;
V_34 = 0 ;
if ( V_7 -> V_40 )
V_34 = ( T_1 ) ( ( V_41 * ) V_7 -> V_40 ) [ V_37 ] ;
F_1 ( V_2 , V_42 , V_34 ) ;
V_36 = F_5 ( V_2 , 0x4 , 0x4 ) ;
if ( V_36 < 0 )
break;
V_35 = F_3 ( V_2 , V_43 ) ;
if ( V_7 -> V_44 )
( ( V_41 * ) V_7 -> V_44 ) [ V_37 ] = ( V_41 ) V_35 ;
}
V_14 -> V_45 += V_7 -> V_39 ;
}
V_14 -> V_46 = V_36 ;
F_18 ( V_12 ) ;
return V_36 ;
}
static int F_19 ( struct V_16 * V_17 )
{
struct V_1 * V_2 = F_9 ( V_17 -> V_12 ) ;
struct V_18 * V_9 = V_2 -> V_9 ;
if ( 8 != V_17 -> V_47 ) {
F_7 ( V_9 , L_4 ) ;
return - V_48 ;
}
F_15 ( V_9 , L_5 , V_17 -> V_49 ) ;
return 0 ;
}
static void F_20 ( struct V_16 * V_17 )
{
struct V_1 * V_2 = F_9 ( V_17 -> V_12 ) ;
struct V_18 * V_9 = V_2 -> V_9 ;
F_15 ( V_9 , L_6 , V_17 -> V_49 ) ;
}
static int T_2 F_21 ( struct V_50 * V_51 )
{
struct V_52 * V_53 ;
struct V_11 * V_12 ;
struct V_1 * V_2 ;
struct V_28 * V_28 ;
int V_36 ;
V_53 = F_22 ( V_51 , V_54 , 0 ) ;
if ( ! V_53 ) {
F_7 ( & V_51 -> V_9 , L_7 ) ;
return - V_55 ;
}
V_12 = F_23 ( & V_51 -> V_9 , sizeof( * V_2 ) ) ;
if ( ! V_12 ) {
F_7 ( & V_51 -> V_9 , L_8 ) ;
return - V_56 ;
}
V_28 = F_24 ( NULL , L_9 ) ;
if ( ! V_28 ) {
F_7 ( & V_51 -> V_9 , L_10 ) ;
V_36 = - V_55 ;
goto V_57;
}
V_2 = F_9 ( V_12 ) ;
F_25 ( & V_51 -> V_9 , V_2 ) ;
V_2 -> V_12 = V_12 ;
V_2 -> V_9 = & V_51 -> V_9 ;
V_2 -> V_28 = V_28 ;
V_2 -> V_5 = F_26 ( V_2 -> V_9 ,
V_53 -> V_58 , F_27 ( V_53 ) ) ;
if ( ! V_2 -> V_5 ) {
F_7 ( & V_51 -> V_9 , L_11 ) ;
V_36 = - V_56 ;
goto V_59;
}
V_12 -> V_60 = 1 ;
V_12 -> V_61 = V_51 -> V_62 ;
V_12 -> V_63 = F_19 ;
V_12 -> V_64 = F_20 ;
V_12 -> V_65 = V_31 | V_30 ;
V_12 -> V_66 = F_8 ;
V_12 -> V_67 = F_16 ;
V_12 -> V_68 = F_11 ;
V_36 = F_28 ( V_12 ) ;
if ( V_36 < 0 ) {
F_7 ( & V_51 -> V_9 , L_12 ) ;
goto V_69;
}
F_29 ( & V_51 -> V_9 ) ;
F_30 ( & V_51 -> V_9 , L_13 ) ;
return 0 ;
V_69:
F_31 ( V_2 -> V_9 , V_2 -> V_5 ) ;
V_59:
F_32 ( V_28 ) ;
V_57:
F_33 ( V_12 ) ;
return V_36 ;
}
static int T_3 F_34 ( struct V_50 * V_51 )
{
struct V_1 * V_2 = F_35 ( & V_51 -> V_9 ) ;
F_36 ( & V_51 -> V_9 ) ;
F_32 ( V_2 -> V_28 ) ;
F_37 ( V_2 -> V_12 ) ;
F_31 ( V_2 -> V_9 , V_2 -> V_5 ) ;
return 0 ;
}
