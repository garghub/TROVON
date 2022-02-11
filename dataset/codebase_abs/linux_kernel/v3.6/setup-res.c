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
F_2 ( V_2 , & V_5 , V_14 ) ;
V_8 = V_5 . V_17 | ( V_14 -> V_15 & V_18 ) ;
if ( V_14 -> V_15 & V_19 )
V_10 = ( T_2 ) V_20 ;
else
V_10 = ( T_2 ) V_21 ;
V_11 = F_3 ( V_2 , V_3 , & type ) ;
if ( ! V_11 )
return;
if ( type != V_22 ) {
if ( ! ( V_14 -> V_15 & V_23 ) )
return;
V_8 |= V_24 ;
}
V_6 = ( V_14 -> V_15 & V_25 ) && ! V_2 -> V_26 ;
if ( V_6 ) {
F_4 ( V_2 , V_27 , & V_7 ) ;
F_5 ( V_2 , V_27 ,
V_7 & ~ V_28 ) ;
}
F_6 ( V_2 , V_11 , V_8 ) ;
F_7 ( V_2 , V_11 , & V_9 ) ;
if ( ( V_8 ^ V_9 ) & V_10 ) {
F_8 ( & V_2 -> V_2 , L_1 ,
V_3 , V_8 , V_9 ) ;
}
if ( V_14 -> V_15 & V_25 ) {
V_8 = V_5 . V_17 >> 16 >> 16 ;
F_6 ( V_2 , V_11 + 4 , V_8 ) ;
F_7 ( V_2 , V_11 + 4 , & V_9 ) ;
if ( V_9 != V_8 ) {
F_8 ( & V_2 -> V_2 , L_2
L_3 , V_3 , V_8 , V_9 ) ;
}
}
if ( V_6 )
F_5 ( V_2 , V_27 , V_7 ) ;
V_14 -> V_15 &= ~ V_29 ;
F_9 ( & V_2 -> V_2 , L_4 ,
V_3 , V_14 , ( unsigned long long ) V_5 . V_17 ,
( unsigned long long ) V_5 . V_30 ) ;
}
int F_10 ( struct V_1 * V_2 , int V_13 )
{
struct V_13 * V_14 = & V_2 -> V_13 [ V_13 ] ;
struct V_13 * V_31 , * V_32 ;
V_31 = F_11 ( V_2 , V_14 ) ;
if ( ! V_31 ) {
F_12 ( & V_2 -> V_2 , L_5 ,
V_14 ) ;
return - V_33 ;
}
V_32 = F_13 ( V_31 , V_14 ) ;
if ( V_32 ) {
F_12 ( & V_2 -> V_2 ,
L_6 ,
V_14 , V_32 -> V_34 , V_32 ) ;
return - V_35 ;
}
return 0 ;
}
void F_14 ( struct V_1 * V_2 )
{
F_12 ( & V_2 -> V_2 , L_7 ) ;
F_6 ( V_2 , V_36 , 0x0000fff0 ) ;
F_6 ( V_2 , V_37 , 0 ) ;
F_6 ( V_2 , V_38 , 0x0000fff0 ) ;
F_6 ( V_2 , V_39 , 0xffffffff ) ;
}
T_3 __weak F_15 ( struct V_1 * V_2 , int V_40 )
{
return 0 ;
}
static int F_16 ( struct V_13 * V_14 , struct V_1 * V_2 ,
int V_3 , T_3 V_41 )
{
struct V_13 * V_31 , * V_32 ;
T_3 V_42 , V_17 , V_30 ;
int V_43 = 0 ;
V_42 = F_15 ( V_2 , V_3 ) ;
if ( ! V_42 )
return 1 ;
V_17 = V_14 -> V_17 ;
V_30 = V_14 -> V_30 ;
V_14 -> V_17 = V_42 ;
V_14 -> V_30 = V_14 -> V_17 + V_41 - 1 ;
V_31 = F_11 ( V_2 , V_14 ) ;
if ( ! V_31 ) {
if ( V_14 -> V_15 & V_19 )
V_31 = & V_44 ;
else
V_31 = & V_45 ;
}
F_12 ( & V_2 -> V_2 , L_8 ,
V_3 , V_14 ) ;
V_32 = F_13 ( V_31 , V_14 ) ;
if ( V_32 ) {
F_12 ( & V_2 -> V_2 ,
L_9 , V_3 ,
V_14 , V_32 -> V_34 , V_32 ) ;
V_14 -> V_17 = V_17 ;
V_14 -> V_30 = V_30 ;
V_43 = 1 ;
}
return V_43 ;
}
static int F_17 ( struct V_46 * V_47 , struct V_1 * V_2 ,
int V_3 , T_3 V_41 , T_3 V_48 )
{
struct V_13 * V_14 = V_2 -> V_13 + V_3 ;
T_3 V_49 ;
int V_43 ;
V_49 = ( V_14 -> V_15 & V_19 ) ? V_50 : V_51 ;
V_43 = F_18 ( V_47 , V_14 , V_41 , V_48 , V_49 ,
V_52 ,
V_53 , V_2 ) ;
if ( V_43 < 0 && ( V_14 -> V_15 & V_52 ) ) {
V_43 = F_18 ( V_47 , V_14 , V_41 , V_48 , V_49 , 0 ,
V_53 , V_2 ) ;
}
return V_43 ;
}
static int F_19 ( struct V_1 * V_2 , int V_3 ,
T_3 V_41 , T_3 V_54 )
{
struct V_13 * V_14 = V_2 -> V_13 + V_3 ;
struct V_46 * V_47 ;
int V_43 ;
char * type ;
V_47 = V_2 -> V_47 ;
while ( ( V_43 = F_17 ( V_47 , V_2 , V_3 , V_41 , V_54 ) ) ) {
if ( ! V_47 -> V_55 || ! V_47 -> V_56 -> V_57 )
break;
V_47 = V_47 -> V_55 ;
}
if ( V_43 ) {
if ( V_14 -> V_15 & V_58 )
if ( V_14 -> V_15 & V_52 )
type = L_10 ;
else
type = L_11 ;
else if ( V_14 -> V_15 & V_19 )
type = L_12 ;
else
type = L_13 ;
F_12 ( & V_2 -> V_2 ,
L_14 ,
V_3 , type , ( unsigned long long ) F_20 ( V_14 ) ) ;
}
return V_43 ;
}
int F_21 ( struct V_1 * V_2 , int V_3 )
{
struct V_13 * V_14 = V_2 -> V_13 + V_3 ;
T_3 V_48 , V_41 ;
struct V_46 * V_47 ;
int V_43 ;
V_48 = F_22 ( V_2 , V_14 ) ;
if ( ! V_48 ) {
F_12 ( & V_2 -> V_2 , L_15
L_16 , V_3 , V_14 ) ;
return - V_33 ;
}
V_47 = V_2 -> V_47 ;
V_41 = F_20 ( V_14 ) ;
V_43 = F_19 ( V_2 , V_3 , V_41 , V_48 ) ;
if ( V_43 < 0 )
V_43 = F_16 ( V_14 , V_2 , V_3 , V_41 ) ;
if ( ! V_43 ) {
V_14 -> V_15 &= ~ V_59 ;
F_12 ( & V_2 -> V_2 , L_17 , V_3 , V_14 ) ;
if ( V_3 < V_60 )
F_1 ( V_2 , V_3 ) ;
}
return V_43 ;
}
int F_23 ( struct V_1 * V_2 , int V_3 , T_3 V_61 ,
T_3 V_54 )
{
struct V_13 * V_14 = V_2 -> V_13 + V_3 ;
T_3 V_62 ;
int V_43 ;
if ( ! V_14 -> V_55 ) {
F_12 ( & V_2 -> V_2 , L_18
L_19 , V_3 , V_14 ) ;
return - V_33 ;
}
V_62 = F_20 ( V_14 ) + V_61 ;
V_43 = F_19 ( V_2 , V_3 , V_62 , V_54 ) ;
if ( ! V_43 ) {
V_14 -> V_15 &= ~ V_59 ;
F_12 ( & V_2 -> V_2 , L_20 , V_3 , V_14 ) ;
if ( V_3 < V_60 )
F_1 ( V_2 , V_3 ) ;
}
return V_43 ;
}
int F_24 ( struct V_1 * V_2 , int V_10 )
{
T_1 V_7 , V_63 ;
int V_64 ;
struct V_13 * V_65 ;
F_4 ( V_2 , V_27 , & V_7 ) ;
V_63 = V_7 ;
for ( V_64 = 0 ; V_64 < V_66 ; V_64 ++ ) {
if ( ! ( V_10 & ( 1 << V_64 ) ) )
continue;
V_65 = & V_2 -> V_13 [ V_64 ] ;
if ( ! ( V_65 -> V_15 & ( V_19 | V_58 ) ) )
continue;
if ( ( V_64 == V_67 ) &&
( ! ( V_65 -> V_15 & V_23 ) ) )
continue;
if ( ! V_65 -> V_55 ) {
F_8 ( & V_2 -> V_2 , L_21
L_22 , V_65 ) ;
return - V_33 ;
}
if ( V_65 -> V_15 & V_19 )
V_7 |= V_68 ;
if ( V_65 -> V_15 & V_58 )
V_7 |= V_28 ;
}
if ( V_7 != V_63 ) {
F_12 ( & V_2 -> V_2 , L_23 ,
V_63 , V_7 ) ;
F_5 ( V_2 , V_27 , V_7 ) ;
}
return 0 ;
}
