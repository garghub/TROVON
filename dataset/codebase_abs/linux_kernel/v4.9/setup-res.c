void F_1 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 V_5 ;
bool V_6 ;
T_1 V_7 ;
T_2 V_8 , V_9 , V_10 ;
int V_11 ;
enum V_12 type ;
struct V_13 * V_14 = V_2 -> V_13 + V_3 ;
if ( V_2 -> V_15 ) {
F_2 ( & V_2 -> V_2 , L_1 , V_3 ) ;
return;
}
if ( ! V_14 -> V_16 )
return;
if ( V_14 -> V_16 & V_17 )
return;
if ( V_14 -> V_16 & V_18 )
return;
F_3 ( V_2 -> V_19 , & V_5 , V_14 ) ;
V_8 = V_5 . V_20 | ( V_14 -> V_16 & V_21 ) ;
if ( V_14 -> V_16 & V_22 )
V_10 = ( T_2 ) V_23 ;
else
V_10 = ( T_2 ) V_24 ;
V_11 = F_4 ( V_2 , V_3 , & type ) ;
if ( ! V_11 )
return;
if ( type != V_25 ) {
if ( ! ( V_14 -> V_16 & V_26 ) )
return;
V_8 |= V_27 ;
}
V_6 = ( V_14 -> V_16 & V_28 ) && ! V_2 -> V_29 ;
if ( V_6 ) {
F_5 ( V_2 , V_30 , & V_7 ) ;
F_6 ( V_2 , V_30 ,
V_7 & ~ V_31 ) ;
}
F_7 ( V_2 , V_11 , V_8 ) ;
F_8 ( V_2 , V_11 , & V_9 ) ;
if ( ( V_8 ^ V_9 ) & V_10 ) {
F_9 ( & V_2 -> V_2 , L_2 ,
V_3 , V_8 , V_9 ) ;
}
if ( V_14 -> V_16 & V_28 ) {
V_8 = V_5 . V_20 >> 16 >> 16 ;
F_7 ( V_2 , V_11 + 4 , V_8 ) ;
F_8 ( V_2 , V_11 + 4 , & V_9 ) ;
if ( V_9 != V_8 ) {
F_9 ( & V_2 -> V_2 , L_3 ,
V_3 , V_8 , V_9 ) ;
}
}
if ( V_6 )
F_6 ( V_2 , V_30 , V_7 ) ;
}
int F_10 ( struct V_1 * V_2 , int V_13 )
{
struct V_13 * V_14 = & V_2 -> V_13 [ V_13 ] ;
struct V_13 * V_32 , * V_33 ;
if ( V_14 -> V_16 & V_17 ) {
F_11 ( & V_2 -> V_2 , L_4 ,
V_13 , V_14 ) ;
return - V_34 ;
}
if ( V_14 -> V_16 & V_35 )
return 0 ;
V_32 = F_12 ( V_2 , V_14 ) ;
if ( ! V_32 ) {
F_11 ( & V_2 -> V_2 , L_5 ,
V_13 , V_14 ) ;
V_14 -> V_16 |= V_17 ;
return - V_34 ;
}
V_33 = F_13 ( V_32 , V_14 ) ;
if ( V_33 ) {
F_11 ( & V_2 -> V_2 , L_6 ,
V_13 , V_14 , V_33 -> V_36 , V_33 ) ;
V_14 -> V_16 |= V_17 ;
return - V_37 ;
}
return 0 ;
}
void F_14 ( struct V_1 * V_2 )
{
F_11 ( & V_2 -> V_2 , L_7 ) ;
F_7 ( V_2 , V_38 , 0x0000fff0 ) ;
F_7 ( V_2 , V_39 , 0 ) ;
F_7 ( V_2 , V_40 , 0x0000fff0 ) ;
F_7 ( V_2 , V_41 , 0xffffffff ) ;
}
T_3 __weak F_15 ( struct V_1 * V_2 , int V_42 )
{
return 0 ;
}
static int F_16 ( struct V_13 * V_14 , struct V_1 * V_2 ,
int V_3 , T_3 V_43 )
{
struct V_13 * V_32 , * V_33 ;
T_3 V_44 , V_20 , V_45 ;
V_44 = F_15 ( V_2 , V_3 ) ;
if ( ! V_44 )
return - V_46 ;
V_20 = V_14 -> V_20 ;
V_45 = V_14 -> V_45 ;
V_14 -> V_20 = V_44 ;
V_14 -> V_45 = V_14 -> V_20 + V_43 - 1 ;
V_14 -> V_16 &= ~ V_17 ;
V_32 = F_12 ( V_2 , V_14 ) ;
if ( ! V_32 ) {
if ( V_14 -> V_16 & V_22 )
V_32 = & V_47 ;
else
V_32 = & V_48 ;
}
F_11 ( & V_2 -> V_2 , L_8 ,
V_3 , V_14 ) ;
V_33 = F_13 ( V_32 , V_14 ) ;
if ( V_33 ) {
F_11 ( & V_2 -> V_2 , L_9 ,
V_3 , V_14 , V_33 -> V_36 , V_33 ) ;
V_14 -> V_20 = V_20 ;
V_14 -> V_45 = V_45 ;
V_14 -> V_16 |= V_17 ;
return - V_37 ;
}
return 0 ;
}
static int F_17 ( struct V_49 * V_19 , struct V_1 * V_2 ,
int V_3 , T_3 V_43 , T_3 V_50 )
{
struct V_13 * V_14 = V_2 -> V_13 + V_3 ;
T_3 V_51 ;
int V_52 ;
V_51 = ( V_14 -> V_16 & V_22 ) ? V_53 : V_54 ;
V_52 = F_18 ( V_19 , V_14 , V_43 , V_50 , V_51 ,
V_55 | V_28 ,
V_56 , V_2 ) ;
if ( V_52 == 0 )
return 0 ;
if ( ( V_14 -> V_16 & ( V_55 | V_28 ) ) ==
( V_55 | V_28 ) ) {
V_52 = F_18 ( V_19 , V_14 , V_43 , V_50 , V_51 ,
V_55 ,
V_56 , V_2 ) ;
if ( V_52 == 0 )
return 0 ;
}
if ( V_14 -> V_16 & ( V_55 | V_28 ) )
V_52 = F_18 ( V_19 , V_14 , V_43 , V_50 , V_51 , 0 ,
V_56 , V_2 ) ;
return V_52 ;
}
static int F_19 ( struct V_1 * V_2 , int V_3 ,
T_3 V_43 , T_3 V_57 )
{
struct V_49 * V_19 ;
int V_52 ;
V_19 = V_2 -> V_19 ;
while ( ( V_52 = F_17 ( V_19 , V_2 , V_3 , V_43 , V_57 ) ) ) {
if ( ! V_19 -> V_58 || ! V_19 -> V_59 -> V_60 )
break;
V_19 = V_19 -> V_58 ;
}
return V_52 ;
}
int F_20 ( struct V_1 * V_2 , int V_3 )
{
struct V_13 * V_14 = V_2 -> V_13 + V_3 ;
T_3 V_50 , V_43 ;
int V_52 ;
if ( V_14 -> V_16 & V_18 )
return 0 ;
V_14 -> V_16 |= V_17 ;
V_50 = F_21 ( V_2 , V_14 ) ;
if ( ! V_50 ) {
F_11 ( & V_2 -> V_2 , L_10 ,
V_3 , V_14 ) ;
return - V_34 ;
}
V_43 = F_22 ( V_14 ) ;
V_52 = F_19 ( V_2 , V_3 , V_43 , V_50 ) ;
if ( V_52 < 0 ) {
F_11 ( & V_2 -> V_2 , L_11 , V_3 , V_14 ) ;
V_52 = F_16 ( V_14 , V_2 , V_3 , V_43 ) ;
}
if ( V_52 < 0 ) {
F_11 ( & V_2 -> V_2 , L_12 , V_3 ,
V_14 ) ;
return V_52 ;
}
V_14 -> V_16 &= ~ V_17 ;
V_14 -> V_16 &= ~ V_61 ;
F_11 ( & V_2 -> V_2 , L_13 , V_3 , V_14 ) ;
if ( V_3 < V_62 )
F_1 ( V_2 , V_3 ) ;
return 0 ;
}
int F_23 ( struct V_1 * V_2 , int V_3 , T_3 V_63 ,
T_3 V_57 )
{
struct V_13 * V_14 = V_2 -> V_13 + V_3 ;
unsigned long V_16 ;
T_3 V_64 ;
int V_52 ;
if ( V_14 -> V_16 & V_18 )
return 0 ;
V_16 = V_14 -> V_16 ;
V_14 -> V_16 |= V_17 ;
if ( ! V_14 -> V_58 ) {
F_11 ( & V_2 -> V_2 , L_14 ,
V_3 , V_14 ) ;
return - V_34 ;
}
V_64 = F_22 ( V_14 ) + V_63 ;
V_52 = F_19 ( V_2 , V_3 , V_64 , V_57 ) ;
if ( V_52 ) {
V_14 -> V_16 = V_16 ;
F_11 ( & V_2 -> V_2 , L_15 ,
V_3 , V_14 , ( unsigned long long ) V_63 ) ;
return V_52 ;
}
V_14 -> V_16 &= ~ V_17 ;
V_14 -> V_16 &= ~ V_61 ;
F_11 ( & V_2 -> V_2 , L_16 ,
V_3 , V_14 , ( unsigned long long ) V_63 ) ;
if ( V_3 < V_62 )
F_1 ( V_2 , V_3 ) ;
return 0 ;
}
int F_24 ( struct V_1 * V_2 , int V_10 )
{
T_1 V_7 , V_65 ;
int V_66 ;
struct V_13 * V_67 ;
F_5 ( V_2 , V_30 , & V_7 ) ;
V_65 = V_7 ;
for ( V_66 = 0 ; V_66 < V_68 ; V_66 ++ ) {
if ( ! ( V_10 & ( 1 << V_66 ) ) )
continue;
V_67 = & V_2 -> V_13 [ V_66 ] ;
if ( ! ( V_67 -> V_16 & ( V_22 | V_69 ) ) )
continue;
if ( ( V_66 == V_70 ) &&
( ! ( V_67 -> V_16 & V_26 ) ) )
continue;
if ( V_67 -> V_16 & V_17 ) {
F_9 ( & V_2 -> V_2 , L_17 ,
V_66 , V_67 ) ;
return - V_34 ;
}
if ( ! V_67 -> V_58 ) {
F_9 ( & V_2 -> V_2 , L_18 ,
V_66 , V_67 ) ;
return - V_34 ;
}
if ( V_67 -> V_16 & V_22 )
V_7 |= V_71 ;
if ( V_67 -> V_16 & V_69 )
V_7 |= V_31 ;
}
if ( V_7 != V_65 ) {
F_11 ( & V_2 -> V_2 , L_19 ,
V_65 , V_7 ) ;
F_6 ( V_2 , V_30 , V_7 ) ;
}
return 0 ;
}
