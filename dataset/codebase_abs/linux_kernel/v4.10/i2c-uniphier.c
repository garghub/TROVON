static T_1 F_1 ( int V_1 , void * V_2 )
{
struct V_3 * V_4 = V_2 ;
F_2 ( & V_4 -> V_5 ) ;
return V_6 ;
}
static int F_3 ( struct V_7 * V_8 , T_2 V_9 ,
T_2 * V_10 )
{
struct V_3 * V_4 = F_4 ( V_8 ) ;
unsigned long V_11 ;
T_2 V_12 ;
F_5 ( & V_4 -> V_5 ) ;
V_9 |= V_13 ;
F_6 ( & V_8 -> V_14 , L_1 , V_9 ) ;
F_7 ( V_9 , V_4 -> V_15 + V_16 ) ;
V_11 = F_8 ( & V_4 -> V_5 , V_8 -> V_17 ) ;
if ( F_9 ( ! V_11 ) ) {
F_10 ( & V_8 -> V_14 , L_2 ) ;
return - V_18 ;
}
V_12 = F_11 ( V_4 -> V_15 + V_19 ) ;
F_6 ( & V_8 -> V_14 , L_3 , V_12 ) ;
if ( V_10 )
* V_10 = V_12 ;
return 0 ;
}
static int F_12 ( struct V_7 * V_8 , T_2 V_9 )
{
T_2 V_12 ;
int V_20 ;
V_20 = F_3 ( V_8 , V_9 , & V_12 ) ;
if ( V_20 )
return V_20 ;
if ( F_9 ( V_12 & V_21 ) ) {
F_6 ( & V_8 -> V_14 , L_4 ) ;
return - V_22 ;
}
if ( F_9 ( V_12 & V_23 ) ) {
F_6 ( & V_8 -> V_14 , L_5 ) ;
return - V_24 ;
}
return 0 ;
}
static int F_13 ( struct V_7 * V_8 , T_3 V_25 , T_3 V_26 ,
const T_4 * V_27 )
{
int V_20 ;
F_6 ( & V_8 -> V_14 , L_6 ) ;
V_20 = F_12 ( V_8 , V_25 << 1 |
V_28 |
V_29 ) ;
if ( V_20 )
return V_20 ;
while ( V_26 -- ) {
V_20 = F_12 ( V_8 ,
V_29 | * V_27 ++ ) ;
if ( V_20 )
return V_20 ;
}
return 0 ;
}
static int F_14 ( struct V_7 * V_8 , T_3 V_25 , T_3 V_26 ,
T_4 * V_27 )
{
int V_20 ;
F_6 ( & V_8 -> V_14 , L_6 ) ;
V_20 = F_12 ( V_8 , V_25 << 1 |
V_28 |
V_29 |
V_30 ) ;
if ( V_20 )
return V_20 ;
while ( V_26 -- ) {
T_2 V_12 ;
V_20 = F_3 ( V_8 ,
V_26 ? 0 : V_29 ,
& V_12 ) ;
if ( V_20 )
return V_20 ;
* V_27 ++ = V_12 ;
}
return 0 ;
}
static int F_15 ( struct V_7 * V_8 )
{
F_6 ( & V_8 -> V_14 , L_7 ) ;
return F_12 ( V_8 , V_31 |
V_29 ) ;
}
static int F_16 ( struct V_7 * V_8 ,
struct V_32 * V_33 , bool V_34 )
{
bool V_35 = V_33 -> V_36 & V_37 ;
bool V_38 = false ;
int V_20 ;
F_6 ( & V_8 -> V_14 , L_8 ,
V_35 ? L_9 : L_10 , V_33 -> V_25 , V_33 -> V_26 , V_34 ) ;
if ( V_35 )
V_20 = F_14 ( V_8 , V_33 -> V_25 , V_33 -> V_26 , V_33 -> V_27 ) ;
else
V_20 = F_13 ( V_8 , V_33 -> V_25 , V_33 -> V_26 , V_33 -> V_27 ) ;
if ( V_20 == - V_22 )
return V_20 ;
if ( V_20 == - V_18 ) {
V_34 = false ;
V_38 = true ;
}
if ( V_34 ) {
int V_39 = F_15 ( V_8 ) ;
if ( V_39 ) {
V_38 = true ;
V_20 = V_20 ? : V_39 ;
}
}
if ( V_38 )
F_17 ( V_8 ) ;
return V_20 ;
}
static int F_18 ( struct V_7 * V_8 )
{
struct V_3 * V_4 = F_4 ( V_8 ) ;
if ( ! ( F_11 ( V_4 -> V_15 + V_19 ) &
V_40 ) ) {
if ( V_4 -> V_41 ++ > 3 ) {
F_17 ( V_8 ) ;
V_4 -> V_41 = 0 ;
}
return - V_22 ;
}
V_4 -> V_41 = 0 ;
return 0 ;
}
static int F_19 ( struct V_7 * V_8 ,
struct V_32 * V_42 , int V_43 )
{
struct V_32 * V_33 , * V_44 = V_42 + V_43 ;
int V_20 ;
V_20 = F_18 ( V_8 ) ;
if ( V_20 )
return V_20 ;
for ( V_33 = V_42 ; V_33 < V_44 ; V_33 ++ ) {
bool V_34 = ! ( V_33 + 1 < V_44 && V_33 [ 1 ] . V_36 & V_37 ) ;
if ( V_33 -> V_36 & V_45 )
V_34 = true ;
V_20 = F_16 ( V_8 , V_33 , V_34 ) ;
if ( V_20 )
return V_20 ;
}
return V_43 ;
}
static T_2 F_20 ( struct V_7 * V_8 )
{
return V_46 | V_47 ;
}
static void F_21 ( struct V_3 * V_4 , bool V_48 )
{
T_2 V_49 = V_50 ;
V_49 |= V_48 ? 0 : V_51 ;
F_7 ( V_49 , V_4 -> V_15 + V_52 ) ;
}
static int F_22 ( struct V_7 * V_8 )
{
struct V_3 * V_4 = F_4 ( V_8 ) ;
return ! ! ( F_11 ( V_4 -> V_15 + V_53 ) &
V_54 ) ;
}
static void F_23 ( struct V_7 * V_8 , int V_49 )
{
struct V_3 * V_4 = F_4 ( V_8 ) ;
F_7 ( V_49 ? V_50 : 0 ,
V_4 -> V_15 + V_52 ) ;
}
static int F_24 ( struct V_7 * V_8 )
{
struct V_3 * V_4 = F_4 ( V_8 ) ;
return ! ! ( F_11 ( V_4 -> V_15 + V_53 ) &
V_55 ) ;
}
static void F_25 ( struct V_7 * V_8 )
{
F_21 ( F_4 ( V_8 ) , false ) ;
}
static void F_26 ( struct V_3 * V_4 ,
T_2 V_56 , unsigned long V_57 )
{
F_21 ( V_4 , true ) ;
F_7 ( ( V_57 / V_56 / 2 << 16 ) | ( V_57 / V_56 ) ,
V_4 -> V_15 + V_58 ) ;
F_21 ( V_4 , false ) ;
}
static int F_27 ( struct V_59 * V_60 )
{
struct V_61 * V_14 = & V_60 -> V_14 ;
struct V_3 * V_4 ;
struct V_62 * V_63 ;
T_2 V_56 ;
unsigned long V_57 ;
int V_1 , V_20 ;
V_4 = F_28 ( V_14 , sizeof( * V_4 ) , V_64 ) ;
if ( ! V_4 )
return - V_65 ;
V_63 = F_29 ( V_60 , V_66 , 0 ) ;
V_4 -> V_15 = F_30 ( V_14 , V_63 ) ;
if ( F_31 ( V_4 -> V_15 ) )
return F_32 ( V_4 -> V_15 ) ;
V_1 = F_33 ( V_60 , 0 ) ;
if ( V_1 < 0 ) {
F_10 ( V_14 , L_11 ) ;
return V_1 ;
}
if ( F_34 ( V_14 -> V_67 , L_12 , & V_56 ) )
V_56 = V_68 ;
if ( ! V_56 || V_56 > V_69 ) {
F_10 ( V_14 , L_13 , V_56 ) ;
return - V_70 ;
}
V_4 -> V_71 = F_35 ( V_14 , NULL ) ;
if ( F_31 ( V_4 -> V_71 ) ) {
F_10 ( V_14 , L_14 ) ;
return F_32 ( V_4 -> V_71 ) ;
}
V_20 = F_36 ( V_4 -> V_71 ) ;
if ( V_20 )
return V_20 ;
V_57 = F_37 ( V_4 -> V_71 ) ;
if ( ! V_57 ) {
F_10 ( V_14 , L_15 ) ;
V_20 = - V_70 ;
goto V_72;
}
F_38 ( & V_4 -> V_5 ) ;
V_4 -> V_8 . V_73 = V_74 ;
V_4 -> V_8 . V_75 = & V_76 ;
V_4 -> V_8 . V_14 . V_77 = V_14 ;
V_4 -> V_8 . V_14 . V_67 = V_14 -> V_67 ;
F_39 ( V_4 -> V_8 . V_78 , L_16 , sizeof( V_4 -> V_8 . V_78 ) ) ;
V_4 -> V_8 . V_79 = & V_80 ;
F_40 ( & V_4 -> V_8 , V_4 ) ;
F_41 ( V_60 , V_4 ) ;
F_26 ( V_4 , V_56 , V_57 ) ;
V_20 = F_42 ( V_14 , V_1 , F_1 , 0 , V_60 -> V_78 ,
V_4 ) ;
if ( V_20 ) {
F_10 ( V_14 , L_17 , V_1 ) ;
goto V_72;
}
V_20 = F_43 ( & V_4 -> V_8 ) ;
V_72:
if ( V_20 )
F_44 ( V_4 -> V_71 ) ;
return V_20 ;
}
static int F_45 ( struct V_59 * V_60 )
{
struct V_3 * V_4 = F_46 ( V_60 ) ;
F_47 ( & V_4 -> V_8 ) ;
F_44 ( V_4 -> V_71 ) ;
return 0 ;
}
