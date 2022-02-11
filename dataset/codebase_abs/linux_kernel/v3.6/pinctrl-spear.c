static inline T_1 F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
return F_2 ( V_2 -> V_4 + V_3 ) ;
}
static inline void F_3 ( struct V_1 * V_2 , T_1 V_5 , T_1 V_3 )
{
F_4 ( V_5 , V_2 -> V_4 + V_3 ) ;
}
static int F_5 ( struct V_1 * V_2 , int V_6 )
{
struct V_7 * V_8 = NULL ;
int V_9 ;
T_1 V_5 ;
if ( ! V_2 -> V_10 -> V_11 || ! V_2 -> V_10 -> V_12 )
return - V_13 ;
for ( V_9 = 0 ; V_9 < V_2 -> V_10 -> V_12 ; V_9 ++ ) {
if ( V_2 -> V_10 -> V_11 [ V_9 ] -> V_6 == ( 1 << V_6 ) ) {
V_8 = V_2 -> V_10 -> V_11 [ V_9 ] ;
break;
}
}
if ( ! V_8 )
return - V_13 ;
V_5 = F_1 ( V_2 , V_8 -> V_3 ) ;
V_5 &= ~ V_8 -> V_14 ;
V_5 |= V_8 -> V_5 ;
F_3 ( V_2 , V_5 , V_8 -> V_3 ) ;
V_2 -> V_10 -> V_6 = V_8 -> V_6 ;
F_6 ( V_2 -> V_15 , L_1 ,
V_8 -> V_16 ? V_8 -> V_16 : L_2 ,
V_8 -> V_3 ) ;
return 0 ;
}
void T_2 F_7 ( struct V_17 * V_10 , T_3 V_3 )
{
struct V_18 * V_19 ;
struct V_20 * V_21 ;
int V_9 , V_22 , V_23 ;
for ( V_23 = 0 ; V_23 < V_10 -> V_24 ; V_23 ++ ) {
V_19 = V_10 -> V_25 [ V_23 ] ;
for ( V_9 = 0 ; V_9 < V_19 -> V_26 ; V_9 ++ ) {
V_21 = & V_19 -> V_27 [ V_9 ] ;
for ( V_22 = 0 ; V_22 < V_21 -> V_28 ; V_22 ++ )
if ( V_21 -> V_29 [ V_22 ] . V_3 == 0xFFFF )
V_21 -> V_29 [ V_22 ] . V_3 = V_3 ;
}
}
}
static int F_8 ( struct V_30 * V_31 )
{
struct V_1 * V_2 = F_9 ( V_31 ) ;
return V_2 -> V_10 -> V_24 ;
}
static const char * F_10 ( struct V_30 * V_31 ,
unsigned V_23 )
{
struct V_1 * V_2 = F_9 ( V_31 ) ;
return V_2 -> V_10 -> V_25 [ V_23 ] -> V_16 ;
}
static int F_11 ( struct V_30 * V_31 ,
unsigned V_23 , const unsigned * * V_32 , unsigned * V_33 )
{
struct V_1 * V_2 = F_9 ( V_31 ) ;
* V_32 = V_2 -> V_10 -> V_25 [ V_23 ] -> V_32 ;
* V_33 = V_2 -> V_10 -> V_25 [ V_23 ] -> V_34 ;
return 0 ;
}
static void F_12 ( struct V_30 * V_31 ,
struct V_35 * V_36 , unsigned V_37 )
{
F_13 ( V_36 , L_3 V_38 ) ;
}
int F_14 ( struct V_30 * V_31 ,
struct V_39 * V_40 ,
struct V_41 * * V_42 , unsigned * V_43 )
{
struct V_1 * V_2 = F_9 ( V_31 ) ;
struct V_39 * V_44 ;
struct V_45 * V_46 ;
const char * V_47 , * V_23 ;
int V_48 , V_49 = 0 , V_50 = 0 ;
F_15 (np_config, np) {
V_48 = F_16 ( V_44 , L_4 , & V_47 ) ;
if ( V_48 < 0 )
return V_48 ;
V_48 = F_17 ( V_44 , L_5 ) ;
if ( V_48 < 0 )
return V_48 ;
V_50 += V_48 ;
}
if ( ! V_50 ) {
F_18 ( V_2 -> V_15 , L_6 ) ;
return - V_51 ;
}
* V_42 = F_19 ( sizeof( * * V_42 ) * V_50 , V_52 ) ;
if ( ! * V_42 )
return - V_53 ;
F_15 (np_config, np) {
F_16 ( V_44 , L_4 , & V_47 ) ;
F_20 (np, L_5 , prop, group) {
( * V_42 ) [ V_49 ] . type = V_54 ;
( * V_42 ) [ V_49 ] . V_55 . V_56 . V_23 = V_23 ;
( * V_42 ) [ V_49 ] . V_55 . V_56 . V_47 = V_47 ;
V_49 ++ ;
}
}
* V_43 = V_50 ;
return 0 ;
}
void F_21 ( struct V_30 * V_31 ,
struct V_41 * V_42 , unsigned V_43 )
{
F_22 ( V_42 ) ;
}
static int F_23 ( struct V_30 * V_31 )
{
struct V_1 * V_2 = F_9 ( V_31 ) ;
return V_2 -> V_10 -> V_57 ;
}
static const char * F_24 ( struct V_30 * V_31 ,
unsigned V_47 )
{
struct V_1 * V_2 = F_9 ( V_31 ) ;
return V_2 -> V_10 -> V_58 [ V_47 ] -> V_16 ;
}
static int F_25 ( struct V_30 * V_31 ,
unsigned V_47 , const char * const * * V_25 ,
unsigned * const V_24 )
{
struct V_1 * V_2 = F_9 ( V_31 ) ;
* V_25 = V_2 -> V_10 -> V_58 [ V_47 ] -> V_25 ;
* V_24 = V_2 -> V_10 -> V_58 [ V_47 ] -> V_24 ;
return 0 ;
}
static int F_26 ( struct V_30 * V_31 ,
unsigned V_47 , unsigned V_23 , bool V_59 )
{
struct V_1 * V_2 = F_9 ( V_31 ) ;
const struct V_18 * V_19 ;
const struct V_20 * V_21 ;
struct V_60 * V_61 ;
T_1 V_5 , V_62 ;
int V_9 , V_22 ;
bool V_63 = false ;
V_19 = V_2 -> V_10 -> V_25 [ V_23 ] ;
for ( V_9 = 0 ; V_9 < V_19 -> V_26 ; V_9 ++ ) {
V_21 = & V_19 -> V_27 [ V_9 ] ;
if ( V_2 -> V_10 -> V_64 ) {
if ( ! ( V_2 -> V_10 -> V_6 & V_21 -> V_65 ) )
continue;
}
V_63 = true ;
for ( V_22 = 0 ; V_22 < V_21 -> V_28 ; V_22 ++ ) {
V_61 = & V_21 -> V_29 [ V_22 ] ;
V_5 = F_1 ( V_2 , V_61 -> V_3 ) ;
V_5 &= ~ V_61 -> V_14 ;
if ( V_59 )
V_62 = V_61 -> V_5 ;
else
V_62 = ~ V_61 -> V_5 ;
V_5 |= V_62 ;
F_3 ( V_2 , V_5 , V_61 -> V_3 ) ;
}
}
if ( ! V_63 ) {
F_18 ( V_2 -> V_15 , L_7 ,
V_19 -> V_16 ) ;
return - V_51 ;
}
return 0 ;
}
static int F_27 ( struct V_30 * V_31 , unsigned V_47 ,
unsigned V_23 )
{
return F_26 ( V_31 , V_47 , V_23 , true ) ;
}
static void F_28 ( struct V_30 * V_31 ,
unsigned V_47 , unsigned V_23 )
{
F_26 ( V_31 , V_47 , V_23 , false ) ;
}
int T_2 F_29 ( struct V_66 * V_67 ,
struct V_17 * V_10 )
{
struct V_39 * V_44 = V_67 -> V_15 . V_68 ;
struct V_69 * V_70 ;
struct V_1 * V_2 ;
if ( ! V_10 )
return - V_51 ;
V_70 = F_30 ( V_67 , V_71 , 0 ) ;
if ( ! V_70 )
return - V_13 ;
V_2 = F_31 ( & V_67 -> V_15 , sizeof( * V_2 ) , V_52 ) ;
if ( ! V_2 ) {
F_18 ( & V_67 -> V_15 , L_8 ) ;
return - V_53 ;
}
V_2 -> V_4 = F_32 ( & V_67 -> V_15 , V_70 -> V_72 , F_33 ( V_70 ) ) ;
if ( ! V_2 -> V_4 ) {
F_18 ( & V_67 -> V_15 , L_9 ) ;
return - V_51 ;
}
V_2 -> V_15 = & V_67 -> V_15 ;
V_2 -> V_10 = V_10 ;
if ( V_10 -> V_64 ) {
int V_6 = 0 ;
if ( F_34 ( V_44 , L_10 , & V_6 ) ) {
F_18 ( & V_67 -> V_15 , L_11 ) ;
return - V_13 ;
}
if ( F_5 ( V_2 , V_6 ) ) {
F_18 ( & V_67 -> V_15 , L_12 ,
V_6 ) ;
return - V_13 ;
}
}
F_35 ( V_67 , V_2 ) ;
V_73 . V_32 = V_10 -> V_32 ;
V_73 . V_34 = V_10 -> V_34 ;
V_2 -> V_74 = F_36 ( & V_73 , & V_67 -> V_15 , V_2 ) ;
if ( ! V_2 -> V_74 ) {
F_18 ( & V_67 -> V_15 , L_13 ) ;
return - V_51 ;
}
return 0 ;
}
int T_4 F_37 ( struct V_66 * V_67 )
{
struct V_1 * V_2 = F_38 ( V_67 ) ;
F_39 ( V_2 -> V_74 ) ;
return 0 ;
}
