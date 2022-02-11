void F_1 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 V_5 ;
bool V_6 ;
T_1 V_7 ;
T_2 V_8 , V_9 , V_10 ;
int V_11 ;
enum V_12 type ;
struct V_13 * V_14 = V_2 -> V_13 + V_3 ;
if ( ! V_14 -> V_15 )
return;
if ( V_14 -> V_15 & V_16 )
return;
if ( V_14 -> V_15 & V_17 )
return;
F_2 ( V_2 -> V_18 , & V_5 , V_14 ) ;
V_8 = V_5 . V_19 | ( V_14 -> V_15 & V_20 ) ;
if ( V_14 -> V_15 & V_21 )
V_10 = ( T_2 ) V_22 ;
else
V_10 = ( T_2 ) V_23 ;
V_11 = F_3 ( V_2 , V_3 , & type ) ;
if ( ! V_11 )
return;
if ( type != V_24 ) {
if ( ! ( V_14 -> V_15 & V_25 ) )
return;
V_8 |= V_26 ;
}
V_6 = ( V_14 -> V_15 & V_27 ) && ! V_2 -> V_28 ;
if ( V_6 ) {
F_4 ( V_2 , V_29 , & V_7 ) ;
F_5 ( V_2 , V_29 ,
V_7 & ~ V_30 ) ;
}
F_6 ( V_2 , V_11 , V_8 ) ;
F_7 ( V_2 , V_11 , & V_9 ) ;
if ( ( V_8 ^ V_9 ) & V_10 ) {
F_8 ( & V_2 -> V_2 , L_1 ,
V_3 , V_8 , V_9 ) ;
}
if ( V_14 -> V_15 & V_27 ) {
V_8 = V_5 . V_19 >> 16 >> 16 ;
F_6 ( V_2 , V_11 + 4 , V_8 ) ;
F_7 ( V_2 , V_11 + 4 , & V_9 ) ;
if ( V_9 != V_8 ) {
F_8 ( & V_2 -> V_2 , L_2 ,
V_3 , V_8 , V_9 ) ;
}
}
if ( V_6 )
F_5 ( V_2 , V_29 , V_7 ) ;
}
int F_9 ( struct V_1 * V_2 , int V_13 )
{
struct V_13 * V_14 = & V_2 -> V_13 [ V_13 ] ;
struct V_13 * V_31 , * V_32 ;
if ( V_14 -> V_15 & V_16 ) {
F_10 ( & V_2 -> V_2 , L_3 ,
V_13 , V_14 ) ;
return - V_33 ;
}
V_31 = F_11 ( V_2 , V_14 ) ;
if ( ! V_31 ) {
F_10 ( & V_2 -> V_2 , L_4 ,
V_13 , V_14 ) ;
V_14 -> V_15 |= V_16 ;
return - V_33 ;
}
V_32 = F_12 ( V_31 , V_14 ) ;
if ( V_32 ) {
F_10 ( & V_2 -> V_2 , L_5 ,
V_13 , V_14 , V_32 -> V_34 , V_32 ) ;
V_14 -> V_15 |= V_16 ;
return - V_35 ;
}
return 0 ;
}
void F_13 ( struct V_1 * V_2 )
{
F_10 ( & V_2 -> V_2 , L_6 ) ;
F_6 ( V_2 , V_36 , 0x0000fff0 ) ;
F_6 ( V_2 , V_37 , 0 ) ;
F_6 ( V_2 , V_38 , 0x0000fff0 ) ;
F_6 ( V_2 , V_39 , 0xffffffff ) ;
}
T_3 __weak F_14 ( struct V_1 * V_2 , int V_40 )
{
return 0 ;
}
static int F_15 ( struct V_13 * V_14 , struct V_1 * V_2 ,
int V_3 , T_3 V_41 )
{
struct V_13 * V_31 , * V_32 ;
T_3 V_42 , V_19 , V_43 ;
V_42 = F_14 ( V_2 , V_3 ) ;
if ( ! V_42 )
return - V_44 ;
V_19 = V_14 -> V_19 ;
V_43 = V_14 -> V_43 ;
V_14 -> V_19 = V_42 ;
V_14 -> V_43 = V_14 -> V_19 + V_41 - 1 ;
V_31 = F_11 ( V_2 , V_14 ) ;
if ( ! V_31 ) {
if ( V_14 -> V_15 & V_21 )
V_31 = & V_45 ;
else
V_31 = & V_46 ;
}
F_10 ( & V_2 -> V_2 , L_7 ,
V_3 , V_14 ) ;
V_32 = F_12 ( V_31 , V_14 ) ;
if ( V_32 ) {
F_10 ( & V_2 -> V_2 , L_8 ,
V_3 , V_14 , V_32 -> V_34 , V_32 ) ;
V_14 -> V_19 = V_19 ;
V_14 -> V_43 = V_43 ;
return - V_35 ;
}
return 0 ;
}
static int F_16 ( struct V_47 * V_18 , struct V_1 * V_2 ,
int V_3 , T_3 V_41 , T_3 V_48 )
{
struct V_13 * V_14 = V_2 -> V_13 + V_3 ;
T_3 V_49 ;
int V_50 ;
V_49 = ( V_14 -> V_15 & V_21 ) ? V_51 : V_52 ;
V_50 = F_17 ( V_18 , V_14 , V_41 , V_48 , V_49 ,
V_53 | V_27 ,
V_54 , V_2 ) ;
if ( V_50 == 0 )
return 0 ;
if ( ( V_14 -> V_15 & ( V_53 | V_27 ) ) ==
( V_53 | V_27 ) ) {
V_50 = F_17 ( V_18 , V_14 , V_41 , V_48 , V_49 ,
V_53 ,
V_54 , V_2 ) ;
if ( V_50 == 0 )
return 0 ;
}
if ( V_14 -> V_15 & ( V_53 | V_27 ) )
V_50 = F_17 ( V_18 , V_14 , V_41 , V_48 , V_49 , 0 ,
V_54 , V_2 ) ;
return V_50 ;
}
static int F_18 ( struct V_1 * V_2 , int V_3 ,
T_3 V_41 , T_3 V_55 )
{
struct V_47 * V_18 ;
int V_50 ;
V_18 = V_2 -> V_18 ;
while ( ( V_50 = F_16 ( V_18 , V_2 , V_3 , V_41 , V_55 ) ) ) {
if ( ! V_18 -> V_56 || ! V_18 -> V_57 -> V_58 )
break;
V_18 = V_18 -> V_56 ;
}
return V_50 ;
}
int F_19 ( struct V_1 * V_2 , int V_3 )
{
struct V_13 * V_14 = V_2 -> V_13 + V_3 ;
T_3 V_48 , V_41 ;
int V_50 ;
V_14 -> V_15 |= V_16 ;
V_48 = F_20 ( V_2 , V_14 ) ;
if ( ! V_48 ) {
F_10 ( & V_2 -> V_2 , L_9 ,
V_3 , V_14 ) ;
return - V_33 ;
}
V_41 = F_21 ( V_14 ) ;
V_50 = F_18 ( V_2 , V_3 , V_41 , V_48 ) ;
if ( V_50 < 0 ) {
F_10 ( & V_2 -> V_2 , L_10 , V_3 , V_14 ) ;
V_50 = F_15 ( V_14 , V_2 , V_3 , V_41 ) ;
}
if ( V_50 < 0 ) {
F_10 ( & V_2 -> V_2 , L_11 , V_3 ,
V_14 ) ;
return V_50 ;
}
V_14 -> V_15 &= ~ V_16 ;
V_14 -> V_15 &= ~ V_59 ;
F_10 ( & V_2 -> V_2 , L_12 , V_3 , V_14 ) ;
if ( V_3 < V_60 )
F_1 ( V_2 , V_3 ) ;
return 0 ;
}
int F_22 ( struct V_1 * V_2 , int V_3 , T_3 V_61 ,
T_3 V_55 )
{
struct V_13 * V_14 = V_2 -> V_13 + V_3 ;
unsigned long V_15 ;
T_3 V_62 ;
int V_50 ;
V_15 = V_14 -> V_15 ;
V_14 -> V_15 |= V_16 ;
if ( ! V_14 -> V_56 ) {
F_10 ( & V_2 -> V_2 , L_13 ,
V_3 , V_14 ) ;
return - V_33 ;
}
V_62 = F_21 ( V_14 ) + V_61 ;
V_50 = F_18 ( V_2 , V_3 , V_62 , V_55 ) ;
if ( V_50 ) {
V_14 -> V_15 = V_15 ;
F_10 ( & V_2 -> V_2 , L_14 ,
V_3 , V_14 , ( unsigned long long ) V_61 ) ;
return V_50 ;
}
V_14 -> V_15 &= ~ V_16 ;
V_14 -> V_15 &= ~ V_59 ;
F_10 ( & V_2 -> V_2 , L_15 ,
V_3 , V_14 , ( unsigned long long ) V_61 ) ;
if ( V_3 < V_60 )
F_1 ( V_2 , V_3 ) ;
return 0 ;
}
int F_23 ( struct V_1 * V_2 , int V_10 )
{
T_1 V_7 , V_63 ;
int V_64 ;
struct V_13 * V_65 ;
F_4 ( V_2 , V_29 , & V_7 ) ;
V_63 = V_7 ;
for ( V_64 = 0 ; V_64 < V_66 ; V_64 ++ ) {
if ( ! ( V_10 & ( 1 << V_64 ) ) )
continue;
V_65 = & V_2 -> V_13 [ V_64 ] ;
if ( ! ( V_65 -> V_15 & ( V_21 | V_67 ) ) )
continue;
if ( ( V_64 == V_68 ) &&
( ! ( V_65 -> V_15 & V_25 ) ) )
continue;
if ( V_65 -> V_15 & V_16 ) {
F_8 ( & V_2 -> V_2 , L_16 ,
V_64 , V_65 ) ;
return - V_33 ;
}
if ( ! V_65 -> V_56 ) {
F_8 ( & V_2 -> V_2 , L_17 ,
V_64 , V_65 ) ;
return - V_33 ;
}
if ( V_65 -> V_15 & V_21 )
V_7 |= V_69 ;
if ( V_65 -> V_15 & V_67 )
V_7 |= V_30 ;
}
if ( V_7 != V_63 ) {
F_10 ( & V_2 -> V_2 , L_18 ,
V_63 , V_7 ) ;
F_5 ( V_2 , V_29 , V_7 ) ;
}
return 0 ;
}
