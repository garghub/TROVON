void F_1 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 V_5 ;
T_1 V_6 , V_7 , V_8 ;
int V_9 ;
enum V_10 type ;
struct V_11 * V_12 = V_2 -> V_11 + V_3 ;
if ( ! V_12 -> V_13 )
return;
if ( V_12 -> V_13 & V_14 )
return;
F_2 ( V_2 , & V_5 , V_12 ) ;
V_6 = V_5 . V_15 | ( V_12 -> V_13 & V_16 ) ;
if ( V_12 -> V_13 & V_17 )
V_8 = ( T_1 ) V_18 ;
else
V_8 = ( T_1 ) V_19 ;
V_9 = F_3 ( V_2 , V_3 , & type ) ;
if ( ! V_9 )
return;
if ( type != V_20 ) {
if ( ! ( V_12 -> V_13 & V_21 ) )
return;
V_6 |= V_22 ;
}
F_4 ( V_2 , V_9 , V_6 ) ;
F_5 ( V_2 , V_9 , & V_7 ) ;
if ( ( V_6 ^ V_7 ) & V_8 ) {
F_6 ( & V_2 -> V_2 , L_1 ,
V_3 , V_6 , V_7 ) ;
}
if ( V_12 -> V_13 & V_23 ) {
V_6 = V_5 . V_15 >> 16 >> 16 ;
F_4 ( V_2 , V_9 + 4 , V_6 ) ;
F_5 ( V_2 , V_9 + 4 , & V_7 ) ;
if ( V_7 != V_6 ) {
F_6 ( & V_2 -> V_2 , L_2
L_3 , V_3 , V_6 , V_7 ) ;
}
}
V_12 -> V_13 &= ~ V_24 ;
F_7 ( & V_2 -> V_2 , L_4 ,
V_3 , V_12 , ( unsigned long long ) V_5 . V_15 ,
( unsigned long long ) V_5 . V_25 ) ;
}
int F_8 ( struct V_1 * V_2 , int V_11 )
{
struct V_11 * V_12 = & V_2 -> V_11 [ V_11 ] ;
struct V_11 * V_26 , * V_27 ;
V_26 = F_9 ( V_2 , V_12 ) ;
if ( ! V_26 ) {
F_7 ( & V_2 -> V_2 , L_5 ,
V_12 ) ;
return - V_28 ;
}
V_27 = F_10 ( V_26 , V_12 ) ;
if ( V_27 ) {
F_7 ( & V_2 -> V_2 ,
L_6 ,
V_12 , V_27 -> V_29 , V_27 ) ;
return - V_30 ;
}
return 0 ;
}
void F_11 ( struct V_1 * V_2 )
{
F_7 ( & V_2 -> V_2 , L_7 ) ;
F_4 ( V_2 , V_31 , 0x0000fff0 ) ;
F_4 ( V_2 , V_32 , 0 ) ;
F_4 ( V_2 , V_33 , 0x0000fff0 ) ;
F_4 ( V_2 , V_34 , 0xffffffff ) ;
}
static int F_12 ( struct V_35 * V_36 , struct V_1 * V_2 ,
int V_3 , T_2 V_37 , T_2 V_38 )
{
struct V_11 * V_12 = V_2 -> V_11 + V_3 ;
T_2 V_39 ;
int V_40 ;
V_39 = ( V_12 -> V_13 & V_17 ) ? V_41 : V_42 ;
V_40 = F_13 ( V_36 , V_12 , V_37 , V_38 , V_39 ,
V_43 ,
V_44 , V_2 ) ;
if ( V_40 < 0 && ( V_12 -> V_13 & V_43 ) ) {
V_40 = F_13 ( V_36 , V_12 , V_37 , V_38 , V_39 , 0 ,
V_44 , V_2 ) ;
}
return V_40 ;
}
static int F_14 ( struct V_11 * V_12 , struct V_1 * V_2 ,
int V_3 , T_2 V_37 )
{
struct V_11 * V_26 , * V_27 ;
T_2 V_15 , V_25 ;
int V_40 = 0 ;
if ( V_12 -> V_13 & V_17 )
V_26 = & V_45 ;
else
V_26 = & V_46 ;
V_15 = V_12 -> V_15 ;
V_25 = V_12 -> V_25 ;
V_12 -> V_15 = V_2 -> V_47 [ V_3 ] ;
V_12 -> V_25 = V_12 -> V_15 + V_37 - 1 ;
F_7 ( & V_2 -> V_2 , L_8 ,
V_3 , V_12 ) ;
V_27 = F_10 ( V_26 , V_12 ) ;
if ( V_27 ) {
F_7 ( & V_2 -> V_2 ,
L_9 , V_3 ,
V_12 , V_27 -> V_29 , V_27 ) ;
V_12 -> V_15 = V_15 ;
V_12 -> V_25 = V_25 ;
V_40 = 1 ;
}
return V_40 ;
}
static int F_15 ( struct V_1 * V_2 , int V_3 , int V_37 , T_2 V_48 )
{
struct V_11 * V_12 = V_2 -> V_11 + V_3 ;
struct V_35 * V_36 ;
int V_40 ;
char * type ;
V_36 = V_2 -> V_36 ;
while ( ( V_40 = F_12 ( V_36 , V_2 , V_3 , V_37 , V_48 ) ) ) {
if ( ! V_36 -> V_49 || ! V_36 -> V_50 -> V_51 )
break;
V_36 = V_36 -> V_49 ;
}
if ( V_40 ) {
if ( V_12 -> V_13 & V_52 )
if ( V_12 -> V_13 & V_43 )
type = L_10 ;
else
type = L_11 ;
else if ( V_12 -> V_13 & V_17 )
type = L_12 ;
else
type = L_13 ;
F_7 ( & V_2 -> V_2 ,
L_14 ,
V_3 , type , ( unsigned long long ) F_16 ( V_12 ) ) ;
}
return V_40 ;
}
int F_17 ( struct V_1 * V_2 , int V_3 , T_2 V_53 ,
T_2 V_48 )
{
struct V_11 * V_12 = V_2 -> V_11 + V_3 ;
T_2 V_54 ;
int V_40 ;
if ( ! V_12 -> V_49 ) {
F_7 ( & V_2 -> V_2 , L_15
L_16 , V_3 , V_12 ) ;
return - V_28 ;
}
V_54 = F_16 ( V_12 ) + V_53 + V_48 ;
V_40 = F_15 ( V_2 , V_3 , V_54 , V_48 ) ;
if ( ! V_40 ) {
V_12 -> V_13 &= ~ V_55 ;
F_7 ( & V_2 -> V_2 , L_17 , V_3 , V_12 ) ;
if ( V_3 < V_56 )
F_1 ( V_2 , V_3 ) ;
}
return V_40 ;
}
int F_18 ( struct V_1 * V_2 , int V_3 )
{
struct V_11 * V_12 = V_2 -> V_11 + V_3 ;
T_2 V_38 , V_37 ;
struct V_35 * V_36 ;
int V_40 ;
V_38 = F_19 ( V_2 , V_12 ) ;
if ( ! V_38 ) {
F_7 ( & V_2 -> V_2 , L_18
L_19 , V_3 , V_12 ) ;
return - V_28 ;
}
V_36 = V_2 -> V_36 ;
V_37 = F_16 ( V_12 ) ;
V_40 = F_15 ( V_2 , V_3 , V_37 , V_38 ) ;
if ( V_40 < 0 && V_2 -> V_47 [ V_3 ] )
V_40 = F_14 ( V_12 , V_2 , V_3 , V_37 ) ;
if ( ! V_40 ) {
V_12 -> V_13 &= ~ V_55 ;
F_7 ( & V_2 -> V_2 , L_17 , V_3 , V_12 ) ;
if ( V_3 < V_56 )
F_1 ( V_2 , V_3 ) ;
}
return V_40 ;
}
void F_20 ( struct V_1 * V_2 , struct V_57 * V_58 )
{
int V_59 ;
for ( V_59 = 0 ; V_59 < V_60 ; V_59 ++ ) {
struct V_11 * V_61 ;
struct V_57 * V_62 , * V_63 ;
T_2 V_64 ;
V_61 = & V_2 -> V_11 [ V_59 ] ;
if ( V_61 -> V_13 & V_14 )
continue;
if ( ! ( V_61 -> V_13 ) || V_61 -> V_49 )
continue;
V_64 = F_19 ( V_2 , V_61 ) ;
if ( ! V_64 ) {
F_21 ( & V_2 -> V_2 , L_20 ,
V_59 , V_61 ) ;
continue;
}
for ( V_62 = V_58 ; ; V_62 = V_62 -> V_65 ) {
T_2 V_38 = 0 ;
struct V_57 * V_66 = V_62 -> V_65 ;
if ( V_66 )
V_38 = F_19 ( V_66 -> V_2 , V_66 -> V_12 ) ;
if ( V_64 > V_38 ) {
V_63 = F_22 ( sizeof( * V_63 ) , V_67 ) ;
if ( ! V_63 )
F_23 ( L_21
L_22 ) ;
V_63 -> V_65 = V_66 ;
V_63 -> V_12 = V_61 ;
V_63 -> V_2 = V_2 ;
V_62 -> V_65 = V_63 ;
break;
}
}
}
}
int F_24 ( struct V_1 * V_2 , int V_8 )
{
T_3 V_68 , V_69 ;
int V_59 ;
struct V_11 * V_61 ;
F_25 ( V_2 , V_70 , & V_68 ) ;
V_69 = V_68 ;
for ( V_59 = 0 ; V_59 < V_60 ; V_59 ++ ) {
if ( ! ( V_8 & ( 1 << V_59 ) ) )
continue;
V_61 = & V_2 -> V_11 [ V_59 ] ;
if ( ! ( V_61 -> V_13 & ( V_17 | V_52 ) ) )
continue;
if ( ( V_59 == V_71 ) &&
( ! ( V_61 -> V_13 & V_21 ) ) )
continue;
if ( ! V_61 -> V_49 ) {
F_6 ( & V_2 -> V_2 , L_23
L_24 , V_61 ) ;
return - V_28 ;
}
if ( V_61 -> V_13 & V_17 )
V_68 |= V_72 ;
if ( V_61 -> V_13 & V_52 )
V_68 |= V_73 ;
}
if ( V_68 != V_69 ) {
F_7 ( & V_2 -> V_2 , L_25 ,
V_69 , V_68 ) ;
F_26 ( V_2 , V_70 , V_68 ) ;
}
return 0 ;
}
