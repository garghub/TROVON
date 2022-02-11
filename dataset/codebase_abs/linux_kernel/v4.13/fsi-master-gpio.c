static void F_1 ( struct V_1 * V_2 , int V_3 )
{
int V_4 ;
for ( V_4 = 0 ; V_4 < V_3 ; V_4 ++ ) {
F_2 ( V_5 ) ;
F_3 ( V_2 -> V_6 , 0 ) ;
F_2 ( V_5 ) ;
F_3 ( V_2 -> V_6 , 1 ) ;
}
}
static int F_4 ( struct V_1 * V_2 )
{
int V_7 ;
F_2 ( V_5 ) ;
V_7 = F_5 ( V_2 -> V_8 ) ;
return V_7 ? 1 : 0 ;
}
static void F_6 ( struct V_1 * V_2 , int V_9 )
{
F_3 ( V_2 -> V_8 , V_9 ) ;
}
static void F_7 ( struct V_1 * V_2 )
{
F_8 ( V_2 -> V_8 ) ;
F_3 ( V_2 -> V_10 , 0 ) ;
}
static void F_9 ( struct V_1 * V_2 , int V_9 )
{
F_3 ( V_2 -> V_10 , 1 ) ;
F_10 ( V_2 -> V_8 , V_9 ) ;
}
static void F_11 ( struct V_1 * V_2 , int V_3 )
{
F_9 ( V_2 , 1 ) ;
F_1 ( V_2 , V_3 ) ;
}
static void F_12 ( struct V_1 * V_2 , struct V_11 * V_12 ,
T_1 V_13 )
{
T_1 V_14 , V_15 ;
F_7 ( V_2 ) ;
for ( V_14 = 0 ; V_14 < V_13 ; V_14 ++ ) {
F_1 ( V_2 , 1 ) ;
V_15 = F_4 ( V_2 ) ;
V_12 -> V_12 <<= 1 ;
V_12 -> V_12 |= ~ V_15 & 0x1 ;
}
V_12 -> V_16 += V_13 ;
F_13 ( V_2 , V_13 , V_12 -> V_12 ) ;
}
static void F_14 ( struct V_1 * V_2 ,
const struct V_11 * V_17 )
{
T_1 V_14 ;
T_2 V_12 = ~ V_17 -> V_12 ;
T_2 V_18 = 0x1ULL << ( V_17 -> V_16 - 1 ) ;
T_2 V_19 = ~ 0 ;
int V_20 ;
F_15 ( V_2 , V_17 -> V_16 , V_17 -> V_12 ) ;
if ( ! V_17 -> V_16 ) {
F_16 ( V_2 -> V_21 , L_1 ) ;
return;
}
F_9 ( V_2 , 0 ) ;
F_6 ( V_2 , 0 ) ;
F_1 ( V_2 , 1 ) ;
for ( V_14 = 0 ; V_14 < V_17 -> V_16 ; V_14 ++ ) {
V_20 = ( V_12 & V_18 ) >> ( V_17 -> V_16 - 1 ) ;
if ( V_19 ^ V_20 ) {
F_6 ( V_2 , V_20 ) ;
V_19 = V_20 ;
}
F_1 ( V_2 , 1 ) ;
V_12 <<= 1 ;
}
}
static void F_17 ( struct V_11 * V_12 , T_2 V_22 , int V_16 )
{
V_12 -> V_12 <<= V_16 ;
V_12 -> V_12 |= V_22 & ( ( 1ull << V_16 ) - 1 ) ;
V_12 -> V_16 += V_16 ;
}
static void F_18 ( struct V_11 * V_12 )
{
T_1 V_23 ;
int V_24 ;
V_24 = V_12 -> V_16 & 0x3 ;
V_23 = F_19 ( 0 , 1 << V_24 | V_12 -> V_12 >> ( V_12 -> V_16 - V_24 ) , V_24 + 1 ) ;
V_23 = F_19 ( V_23 , V_12 -> V_12 , V_12 -> V_16 - V_24 ) ;
F_17 ( V_12 , V_23 , 4 ) ;
}
static void F_20 ( struct V_11 * V_17 ,
T_1 V_25 , T_3 V_26 , T_4 V_27 , const void * V_22 )
{
bool V_28 = ! ! V_22 ;
T_1 V_29 ;
int V_4 ;
V_17 -> V_16 = 0 ;
V_17 -> V_12 = 0 ;
F_17 ( V_17 , V_25 , 2 ) ;
F_17 ( V_17 , V_30 , 3 ) ;
F_17 ( V_17 , V_28 ? 0 : 1 , 1 ) ;
V_29 = V_27 > 1 ? 1 : 0 ;
V_26 &= ~ ( V_27 - 1 ) ;
if ( V_27 == 4 )
V_26 |= 1 ;
F_17 ( V_17 , V_26 & ( ( 1 << 21 ) - 1 ) , 21 ) ;
F_17 ( V_17 , V_29 , 1 ) ;
for ( V_4 = 0 ; V_28 && V_4 < V_27 ; V_4 ++ )
F_17 ( V_17 , ( ( T_1 * ) V_22 ) [ V_4 ] , 8 ) ;
F_18 ( V_17 ) ;
}
static void F_21 ( struct V_11 * V_17 , T_1 V_31 )
{
V_17 -> V_16 = 0 ;
V_17 -> V_12 = 0 ;
F_17 ( V_17 , V_31 , 2 ) ;
F_17 ( V_17 , V_32 , 3 ) ;
F_18 ( V_17 ) ;
}
static void F_22 ( struct V_1 * V_2 )
{
F_9 ( V_2 , 1 ) ;
F_1 ( V_2 , V_33 ) ;
}
static void F_23 ( struct V_11 * V_17 , T_1 V_31 )
{
V_17 -> V_16 = 0 ;
V_17 -> V_12 = 0 ;
F_17 ( V_17 , V_31 , 2 ) ;
F_17 ( V_17 , V_34 , 6 ) ;
F_18 ( V_17 ) ;
}
static void F_24 ( struct V_1 * V_2 , int error )
{
}
static int F_25 ( struct V_1 * V_2 ,
T_1 V_35 , struct V_11 * V_36 , T_1 * V_37 )
{
struct V_11 V_12 ;
T_1 V_25 , V_38 ;
T_3 V_23 ;
int V_4 ;
for ( V_4 = 0 ; V_4 < V_39 ; V_4 ++ ) {
V_12 . V_16 = 0 ;
V_12 . V_12 = 0 ;
F_12 ( V_2 , & V_12 , 1 ) ;
if ( V_12 . V_12 )
break;
}
if ( V_4 == V_39 ) {
F_26 ( V_2 -> V_21 ,
L_2 ) ;
F_24 ( V_2 , V_40 ) ;
return - V_41 ;
}
V_12 . V_16 = 0 ;
V_12 . V_12 = 0 ;
F_12 ( V_2 , & V_12 , 4 ) ;
V_25 = ( V_12 . V_12 >> V_42 ) & 0x3 ;
V_38 = V_12 . V_12 & 0x3 ;
if ( V_38 == V_43 && V_35 )
F_12 ( V_2 , & V_12 , V_35 * 8 ) ;
F_12 ( V_2 , & V_12 , V_44 ) ;
V_23 = F_19 ( 0 , 1 , 1 ) ;
V_23 = F_19 ( V_23 , V_12 . V_12 , V_12 . V_16 ) ;
if ( V_23 ) {
F_26 ( V_2 -> V_21 , L_3 ) ;
F_24 ( V_2 , V_45 ) ;
return - V_41 ;
}
if ( V_36 )
* V_36 = V_12 ;
if ( V_37 )
* V_37 = V_38 ;
return 0 ;
}
static int F_27 ( struct V_1 * V_2 , T_1 V_46 )
{
struct V_11 V_17 ;
T_1 V_38 ;
int V_47 ;
F_23 ( & V_17 , V_46 ) ;
F_14 ( V_2 , & V_17 ) ;
F_22 ( V_2 ) ;
V_47 = F_25 ( V_2 , 0 , NULL , & V_38 ) ;
if ( V_47 < 0 ) {
F_28 ( V_2 -> V_21 ,
L_4 ) ;
return - V_41 ;
} else if ( V_38 != V_43 ) {
F_28 ( V_2 -> V_21 , L_5 , V_38 ) ;
return - V_41 ;
}
return 0 ;
}
static int F_29 ( struct V_1 * V_2 ,
T_1 V_46 , T_1 V_27 , void * V_22 )
{
struct V_11 V_48 , V_17 ;
int V_49 = 0 , V_47 , V_4 ;
T_1 V_38 ;
T_1 * V_50 = V_22 ;
V_51:
V_47 = F_25 ( V_2 , V_27 , & V_48 , & V_38 ) ;
if ( V_47 )
return V_47 ;
switch ( V_38 ) {
case V_43 :
if ( V_27 && V_22 ) {
T_2 V_52 = V_48 . V_12 ;
V_52 >>= 4 ;
V_52 &= ( 1ull << ( V_27 * 8 ) ) - 1 ;
for ( V_4 = 0 ; V_4 < V_27 ; V_4 ++ ) {
V_50 [ V_27 - V_4 - 1 ] = V_52 ;
V_52 >>= 8 ;
}
}
break;
case V_53 :
F_11 ( V_2 , V_54 ) ;
if ( V_49 ++ < V_55 ) {
F_21 ( & V_17 , V_46 ) ;
F_14 ( V_2 , & V_17 ) ;
F_22 ( V_2 ) ;
goto V_51;
}
F_16 ( V_2 -> V_21 ,
L_6 ) ;
F_27 ( V_2 , V_46 ) ;
V_47 = - V_41 ;
break;
case V_56 :
case V_57 :
F_26 ( V_2 -> V_21 , L_7 ,
V_38 == V_56 ? 'A' : 'C' ,
( int ) V_48 . V_12 ) ;
F_24 ( V_2 , V_48 . V_12 ) ;
V_47 = - V_41 ;
break;
}
F_11 ( V_2 , V_58 ) ;
return V_47 ;
}
static int F_30 ( struct V_1 * V_2 , T_1 V_46 ,
struct V_11 * V_17 , T_4 V_59 , void * V_60 )
{
unsigned long V_61 ;
int V_47 ;
F_31 ( & V_2 -> V_62 , V_61 ) ;
F_14 ( V_2 , V_17 ) ;
F_22 ( V_2 ) ;
V_47 = F_29 ( V_2 , V_46 , V_59 , V_60 ) ;
F_32 ( & V_2 -> V_62 , V_61 ) ;
return V_47 ;
}
static int F_33 ( struct V_63 * V_64 , int V_65 ,
T_1 V_25 , T_3 V_26 , void * V_52 , T_4 V_27 )
{
struct V_1 * V_2 = F_34 ( V_64 ) ;
struct V_11 V_17 ;
if ( V_65 != 0 )
return - V_66 ;
F_20 ( & V_17 , V_25 , V_26 , V_27 , NULL ) ;
return F_30 ( V_2 , V_25 , & V_17 , V_27 , V_52 ) ;
}
static int F_35 ( struct V_63 * V_64 , int V_65 ,
T_1 V_25 , T_3 V_26 , const void * V_52 , T_4 V_27 )
{
struct V_1 * V_2 = F_34 ( V_64 ) ;
struct V_11 V_17 ;
if ( V_65 != 0 )
return - V_66 ;
F_20 ( & V_17 , V_25 , V_26 , V_27 , V_52 ) ;
return F_30 ( V_2 , V_25 , & V_17 , 0 , NULL ) ;
}
static int F_36 ( struct V_63 * V_64 ,
int V_65 , T_1 V_25 )
{
struct V_1 * V_2 = F_34 ( V_64 ) ;
struct V_11 V_17 ;
if ( V_65 != 0 )
return - V_66 ;
F_23 ( & V_17 , V_25 ) ;
return F_30 ( V_2 , V_25 , & V_17 , 0 , NULL ) ;
}
static int F_37 ( struct V_63 * V_64 , int V_65 )
{
struct V_1 * V_2 = F_34 ( V_64 ) ;
if ( V_65 != 0 )
return - V_66 ;
F_38 ( V_2 ) ;
F_9 ( V_2 , 1 ) ;
F_6 ( V_2 , 1 ) ;
F_1 ( V_2 , V_67 ) ;
F_6 ( V_2 , 0 ) ;
F_1 ( V_2 , V_68 ) ;
F_22 ( V_2 ) ;
F_6 ( V_2 , 1 ) ;
F_1 ( V_2 , V_69 ) ;
F_39 ( 200 ) ;
return 0 ;
}
static void F_40 ( struct V_1 * V_2 )
{
F_10 ( V_2 -> V_70 , 1 ) ;
F_10 ( V_2 -> V_10 , 1 ) ;
F_10 ( V_2 -> V_71 , 1 ) ;
F_10 ( V_2 -> V_6 , 1 ) ;
F_10 ( V_2 -> V_8 , 1 ) ;
F_11 ( V_2 , V_72 ) ;
}
static int F_41 ( struct V_63 * V_64 , int V_65 )
{
struct V_1 * V_2 = F_34 ( V_64 ) ;
if ( V_65 != 0 )
return - V_66 ;
F_3 ( V_2 -> V_71 , 1 ) ;
return 0 ;
}
static int F_42 ( struct V_73 * V_74 )
{
struct V_1 * V_2 ;
struct V_75 * V_76 ;
V_2 = F_43 ( & V_74 -> V_21 , sizeof( * V_2 ) , V_77 ) ;
if ( ! V_2 )
return - V_78 ;
V_2 -> V_21 = & V_74 -> V_21 ;
V_2 -> V_2 . V_21 . V_79 = V_2 -> V_21 ;
V_76 = F_44 ( & V_74 -> V_21 , L_8 , 0 ) ;
if ( F_45 ( V_76 ) ) {
F_28 ( & V_74 -> V_21 , L_9 ) ;
return F_46 ( V_76 ) ;
}
V_2 -> V_6 = V_76 ;
V_76 = F_44 ( & V_74 -> V_21 , L_10 , 0 ) ;
if ( F_45 ( V_76 ) ) {
F_28 ( & V_74 -> V_21 , L_11 ) ;
return F_46 ( V_76 ) ;
}
V_2 -> V_8 = V_76 ;
V_76 = F_47 ( & V_74 -> V_21 , L_12 , 0 ) ;
if ( F_45 ( V_76 ) ) {
F_28 ( & V_74 -> V_21 , L_13 ) ;
return F_46 ( V_76 ) ;
}
V_2 -> V_10 = V_76 ;
V_76 = F_47 ( & V_74 -> V_21 , L_14 , 0 ) ;
if ( F_45 ( V_76 ) ) {
F_28 ( & V_74 -> V_21 , L_15 ) ;
return F_46 ( V_76 ) ;
}
V_2 -> V_71 = V_76 ;
V_76 = F_47 ( & V_74 -> V_21 , L_16 , 0 ) ;
if ( F_45 ( V_76 ) ) {
F_28 ( & V_74 -> V_21 , L_17 ) ;
return F_46 ( V_76 ) ;
}
V_2 -> V_70 = V_76 ;
V_2 -> V_2 . V_80 = 1 ;
V_2 -> V_2 . V_61 = V_81 ;
V_2 -> V_2 . V_82 = F_33 ;
V_2 -> V_2 . V_28 = F_35 ;
V_2 -> V_2 . V_83 = F_36 ;
V_2 -> V_2 . V_84 = F_37 ;
V_2 -> V_2 . V_85 = F_41 ;
F_48 ( V_74 , V_2 ) ;
F_49 ( & V_2 -> V_62 ) ;
F_40 ( V_2 ) ;
return F_50 ( & V_2 -> V_2 ) ;
}
static int F_51 ( struct V_73 * V_74 )
{
struct V_1 * V_2 = F_52 ( V_74 ) ;
F_53 ( & V_74 -> V_21 , V_2 -> V_6 ) ;
F_53 ( & V_74 -> V_21 , V_2 -> V_8 ) ;
if ( V_2 -> V_10 )
F_53 ( & V_74 -> V_21 , V_2 -> V_10 ) ;
if ( V_2 -> V_71 )
F_53 ( & V_74 -> V_21 , V_2 -> V_71 ) ;
if ( V_2 -> V_70 )
F_53 ( & V_74 -> V_21 , V_2 -> V_70 ) ;
F_54 ( & V_2 -> V_2 ) ;
return 0 ;
}
