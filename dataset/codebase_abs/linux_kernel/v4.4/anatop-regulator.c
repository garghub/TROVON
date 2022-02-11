static int F_1 ( struct V_1 * V_2 ,
unsigned int V_3 ,
unsigned int V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
T_1 V_7 ;
int V_8 = 0 ;
if ( V_6 -> V_9 && V_4 > V_3 ) {
F_3 ( V_6 -> V_10 , V_6 -> V_11 , & V_7 ) ;
V_7 = ( V_7 >> V_6 -> V_12 ) &
( ( 1 << V_6 -> V_9 ) - 1 ) ;
V_8 = ( V_4 - V_3 ) * ( V_13 <<
V_7 ) / V_14 + 1 ;
}
return V_8 ;
}
static int F_4 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_15 ;
V_15 = V_6 -> V_16 ? V_17 : V_6 -> V_15 ;
return F_5 ( V_2 , V_15 ) ;
}
static int F_6 ( struct V_1 * V_2 )
{
return F_5 ( V_2 , V_18 ) ;
}
static int F_7 ( struct V_1 * V_2 )
{
return F_8 ( V_2 ) != V_18 ;
}
static int F_9 ( struct V_1 * V_2 ,
unsigned V_19 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_8 ;
if ( V_6 -> V_16 || ! F_7 ( V_2 ) ) {
V_6 -> V_15 = V_19 ;
return 0 ;
}
V_8 = F_5 ( V_2 , V_19 ) ;
if ( ! V_8 )
V_6 -> V_15 = V_19 ;
return V_8 ;
}
static int F_10 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( V_6 -> V_16 || ! F_7 ( V_2 ) )
return V_6 -> V_15 ;
return F_8 ( V_2 ) ;
}
static int F_11 ( struct V_1 * V_2 , bool * V_20 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_15 ;
V_15 = F_8 ( V_2 ) ;
if ( V_15 == V_17 )
F_12 ( ! V_6 -> V_16 ) ;
else if ( V_15 != V_18 )
F_12 ( V_6 -> V_16 ) ;
* V_20 = V_6 -> V_16 ;
return 0 ;
}
static int F_13 ( struct V_1 * V_2 , bool V_20 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_15 ;
if ( V_20 == V_6 -> V_16 )
return 0 ;
V_15 = V_20 ? V_17 : V_6 -> V_15 ;
V_6 -> V_16 = V_20 ;
return F_5 ( V_2 , V_15 ) ;
}
static int F_14 ( struct V_21 * V_22 )
{
struct V_23 * V_24 = & V_22 -> V_24 ;
struct V_25 * V_26 = V_24 -> V_27 ;
struct V_25 * V_28 ;
struct V_29 * V_30 ;
struct V_1 * V_31 ;
struct V_5 * V_32 ;
struct V_33 * V_34 ;
struct V_35 V_36 = { } ;
int V_8 = 0 ;
T_1 V_7 ;
V_32 = F_15 ( V_24 , sizeof( * V_32 ) , V_37 ) ;
if ( ! V_32 )
return - V_38 ;
V_32 -> V_39 = F_16 ( V_26 , L_1 , NULL ) ;
V_30 = & V_32 -> V_30 ;
V_30 -> V_39 = V_32 -> V_39 ;
V_30 -> type = V_40 ;
V_30 -> V_41 = V_42 ;
V_34 = F_17 ( V_24 , V_26 , V_30 ) ;
V_34 -> V_43 = L_2 ;
V_32 -> V_34 = V_34 ;
V_28 = F_18 ( V_26 ) ;
if ( ! V_28 )
return - V_44 ;
V_32 -> V_10 = F_19 ( V_28 ) ;
F_20 ( V_28 ) ;
if ( F_21 ( V_32 -> V_10 ) )
return F_22 ( V_32 -> V_10 ) ;
V_8 = F_23 ( V_26 , L_3 ,
& V_32 -> V_45 ) ;
if ( V_8 ) {
F_24 ( V_24 , L_4 ) ;
return V_8 ;
}
V_8 = F_23 ( V_26 , L_5 ,
& V_32 -> V_46 ) ;
if ( V_8 ) {
F_24 ( V_24 , L_6 ) ;
return V_8 ;
}
V_8 = F_23 ( V_26 , L_7 ,
& V_32 -> V_47 ) ;
if ( V_8 ) {
F_24 ( V_24 , L_8 ) ;
return V_8 ;
}
V_8 = F_23 ( V_26 , L_9 ,
& V_32 -> V_48 ) ;
if ( V_8 ) {
F_24 ( V_24 , L_10 ) ;
return V_8 ;
}
V_8 = F_23 ( V_26 , L_11 ,
& V_32 -> V_49 ) ;
if ( V_8 ) {
F_24 ( V_24 , L_12 ) ;
return V_8 ;
}
V_8 = F_23 ( V_26 , L_13 ,
& V_32 -> V_50 ) ;
if ( V_8 ) {
F_24 ( V_24 , L_14 ) ;
return V_8 ;
}
F_23 ( V_26 , L_15 ,
& V_32 -> V_11 ) ;
F_23 ( V_26 , L_16 ,
& V_32 -> V_9 ) ;
F_23 ( V_26 , L_17 ,
& V_32 -> V_12 ) ;
V_30 -> V_51 = ( V_32 -> V_50 - V_32 -> V_49 ) / 25000 + 1
+ V_32 -> V_48 ;
V_30 -> V_52 = V_32 -> V_49 ;
V_30 -> V_53 = 25000 ;
V_30 -> V_54 = V_32 -> V_48 ;
V_30 -> V_55 = V_32 -> V_45 ;
V_30 -> V_56 = ( ( 1 << V_32 -> V_46 ) - 1 ) <<
V_32 -> V_47 ;
V_30 -> V_57 = 125000 ;
V_36 . V_24 = & V_22 -> V_24 ;
V_36 . V_58 = V_34 ;
V_36 . V_59 = V_32 ;
V_36 . V_27 = V_22 -> V_24 . V_27 ;
V_36 . V_60 = V_32 -> V_10 ;
if ( V_32 -> V_45 && V_32 -> V_9 ) {
V_30 -> V_61 = & V_62 ;
V_8 = F_3 ( V_36 . V_60 , V_30 -> V_55 , & V_7 ) ;
if ( V_8 ) {
F_24 ( V_24 , L_18 ) ;
return V_8 ;
}
V_32 -> V_15 = ( V_7 & V_30 -> V_56 ) >> V_32 -> V_47 ;
if ( V_32 -> V_15 == V_17 ) {
V_32 -> V_15 = 0 ;
V_32 -> V_16 = true ;
}
if ( ! V_32 -> V_15 && ! strcmp ( V_32 -> V_39 , L_19 ) )
V_32 -> V_15 = 22 ;
if ( ! V_32 -> V_15 ) {
F_24 ( & V_22 -> V_24 , L_20 ) ;
return - V_63 ;
}
} else {
V_30 -> V_61 = & V_64 ;
}
V_31 = F_25 ( V_24 , V_30 , & V_36 ) ;
if ( F_21 ( V_31 ) ) {
F_24 ( V_24 , L_21 ,
V_30 -> V_39 ) ;
return F_22 ( V_31 ) ;
}
F_26 ( V_22 , V_31 ) ;
return 0 ;
}
static int T_2 F_27 ( void )
{
return F_28 ( & V_65 ) ;
}
static void T_3 F_29 ( void )
{
F_30 ( & V_65 ) ;
}
