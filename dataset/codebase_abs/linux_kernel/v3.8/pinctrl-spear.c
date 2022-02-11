static void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , T_1 V_5 , bool V_6 )
{
struct V_3 * V_7 ;
T_2 V_8 , V_9 , V_10 ;
for ( V_10 = 0 ; V_10 < V_5 ; V_10 ++ ) {
V_7 = & V_4 [ V_10 ] ;
V_8 = F_2 ( V_2 , V_7 -> V_11 ) ;
V_8 &= ~ V_7 -> V_12 ;
if ( V_6 )
V_9 = V_7 -> V_8 ;
else
V_9 = ~ V_7 -> V_8 ;
V_8 |= V_7 -> V_12 & V_9 ;
F_3 ( V_2 , V_8 , V_7 -> V_11 ) ;
}
}
static int F_4 ( struct V_1 * V_2 , int V_13 )
{
struct V_14 * V_15 = NULL ;
int V_16 ;
T_2 V_8 ;
if ( ! V_2 -> V_17 -> V_18 || ! V_2 -> V_17 -> V_19 )
return - V_20 ;
for ( V_16 = 0 ; V_16 < V_2 -> V_17 -> V_19 ; V_16 ++ ) {
if ( V_2 -> V_17 -> V_18 [ V_16 ] -> V_13 == ( 1 << V_13 ) ) {
V_15 = V_2 -> V_17 -> V_18 [ V_16 ] ;
break;
}
}
if ( ! V_15 )
return - V_20 ;
V_8 = F_2 ( V_2 , V_15 -> V_11 ) ;
V_8 &= ~ V_15 -> V_12 ;
V_8 |= V_15 -> V_8 ;
F_3 ( V_2 , V_8 , V_15 -> V_11 ) ;
V_2 -> V_17 -> V_13 = V_15 -> V_13 ;
F_5 ( V_2 -> V_21 , L_1 ,
V_15 -> V_22 ? V_15 -> V_22 : L_2 ,
V_15 -> V_11 ) ;
return 0 ;
}
void F_6 ( struct V_23 * V_24 ,
unsigned V_5 , T_3 V_11 )
{
int V_16 , V_10 ;
for ( V_16 = 0 ; V_16 < V_5 ; V_16 ++ )
for ( V_10 = 0 ; V_10 < V_24 [ V_16 ] . V_25 ; V_10 ++ )
V_24 [ V_16 ] . V_4 [ V_10 ] . V_11 = V_11 ;
}
void F_7 ( struct V_26 * V_17 , T_3 V_11 )
{
struct V_27 * V_28 ;
struct V_29 * V_30 ;
int V_16 , V_10 , V_31 ;
for ( V_31 = 0 ; V_31 < V_17 -> V_32 ; V_31 ++ ) {
V_28 = V_17 -> V_33 [ V_31 ] ;
for ( V_16 = 0 ; V_16 < V_28 -> V_34 ; V_16 ++ ) {
V_30 = & V_28 -> V_35 [ V_16 ] ;
for ( V_10 = 0 ; V_10 < V_30 -> V_25 ; V_10 ++ )
if ( V_30 -> V_4 [ V_10 ] . V_11 == 0xFFFF )
V_30 -> V_4 [ V_10 ] . V_11 = V_11 ;
}
}
}
static int F_8 ( struct V_36 * V_37 )
{
struct V_1 * V_2 = F_9 ( V_37 ) ;
return V_2 -> V_17 -> V_32 ;
}
static const char * F_10 ( struct V_36 * V_37 ,
unsigned V_31 )
{
struct V_1 * V_2 = F_9 ( V_37 ) ;
return V_2 -> V_17 -> V_33 [ V_31 ] -> V_22 ;
}
static int F_11 ( struct V_36 * V_37 ,
unsigned V_31 , const unsigned * * V_38 , unsigned * V_39 )
{
struct V_1 * V_2 = F_9 ( V_37 ) ;
* V_38 = V_2 -> V_17 -> V_33 [ V_31 ] -> V_38 ;
* V_39 = V_2 -> V_17 -> V_33 [ V_31 ] -> V_40 ;
return 0 ;
}
static void F_12 ( struct V_36 * V_37 ,
struct V_41 * V_42 , unsigned V_43 )
{
F_13 ( V_42 , L_3 V_44 ) ;
}
static int F_14 ( struct V_36 * V_37 ,
struct V_45 * V_46 ,
struct V_47 * * V_48 ,
unsigned * V_49 )
{
struct V_1 * V_2 = F_9 ( V_37 ) ;
struct V_45 * V_50 ;
struct V_51 * V_52 ;
const char * V_53 , * V_31 ;
int V_54 , V_55 = 0 , V_5 = 0 ;
F_15 (np_config, np) {
V_54 = F_16 ( V_50 , L_4 , & V_53 ) ;
if ( V_54 < 0 )
return V_54 ;
V_54 = F_17 ( V_50 , L_5 ) ;
if ( V_54 < 0 )
return V_54 ;
V_5 += V_54 ;
}
if ( ! V_5 ) {
F_18 ( V_2 -> V_21 , L_6 ) ;
return - V_56 ;
}
* V_48 = F_19 ( sizeof( * * V_48 ) * V_5 , V_57 ) ;
if ( ! * V_48 )
return - V_58 ;
F_15 (np_config, np) {
F_16 ( V_50 , L_4 , & V_53 ) ;
F_20 (np, L_5 , prop, group) {
( * V_48 ) [ V_55 ] . type = V_59 ;
( * V_48 ) [ V_55 ] . V_60 . V_61 . V_31 = V_31 ;
( * V_48 ) [ V_55 ] . V_60 . V_61 . V_53 = V_53 ;
V_55 ++ ;
}
}
* V_49 = V_5 ;
return 0 ;
}
static void F_21 ( struct V_36 * V_37 ,
struct V_47 * V_48 ,
unsigned V_49 )
{
F_22 ( V_48 ) ;
}
static int F_23 ( struct V_36 * V_37 )
{
struct V_1 * V_2 = F_9 ( V_37 ) ;
return V_2 -> V_17 -> V_62 ;
}
static const char * F_24 ( struct V_36 * V_37 ,
unsigned V_53 )
{
struct V_1 * V_2 = F_9 ( V_37 ) ;
return V_2 -> V_17 -> V_63 [ V_53 ] -> V_22 ;
}
static int F_25 ( struct V_36 * V_37 ,
unsigned V_53 , const char * const * * V_33 ,
unsigned * const V_32 )
{
struct V_1 * V_2 = F_9 ( V_37 ) ;
* V_33 = V_2 -> V_17 -> V_63 [ V_53 ] -> V_33 ;
* V_32 = V_2 -> V_17 -> V_63 [ V_53 ] -> V_32 ;
return 0 ;
}
static int F_26 ( struct V_36 * V_37 ,
unsigned V_53 , unsigned V_31 , bool V_6 )
{
struct V_1 * V_2 = F_9 ( V_37 ) ;
const struct V_27 * V_28 ;
const struct V_29 * V_30 ;
int V_16 ;
bool V_64 = false ;
V_28 = V_2 -> V_17 -> V_33 [ V_31 ] ;
for ( V_16 = 0 ; V_16 < V_28 -> V_34 ; V_16 ++ ) {
V_30 = & V_28 -> V_35 [ V_16 ] ;
if ( V_2 -> V_17 -> V_65 ) {
if ( ! ( V_2 -> V_17 -> V_13 & V_30 -> V_66 ) )
continue;
}
V_64 = true ;
F_1 ( V_2 , V_30 -> V_4 , V_30 -> V_25 ,
V_6 ) ;
}
if ( ! V_64 ) {
F_18 ( V_2 -> V_21 , L_7 ,
V_28 -> V_22 ) ;
return - V_56 ;
}
return 0 ;
}
static int F_27 ( struct V_36 * V_37 , unsigned V_53 ,
unsigned V_31 )
{
return F_26 ( V_37 , V_53 , V_31 , true ) ;
}
static void F_28 ( struct V_36 * V_37 ,
unsigned V_53 , unsigned V_31 )
{
F_26 ( V_37 , V_53 , V_31 , false ) ;
}
static struct V_23 * F_29 ( struct V_1 * V_2 ,
unsigned V_67 )
{
struct V_23 * V_24 ;
int V_16 , V_10 ;
if ( ! V_2 -> V_17 -> V_68 )
return NULL ;
for ( V_16 = 0 ; V_16 < V_2 -> V_17 -> V_69 ; V_16 ++ ) {
V_24 = & V_2 -> V_17 -> V_68 [ V_16 ] ;
for ( V_10 = 0 ; V_10 < V_24 -> V_40 ; V_10 ++ ) {
if ( V_24 -> V_38 [ V_10 ] == V_67 )
return V_24 ;
}
}
return NULL ;
}
static int F_30 ( struct V_36 * V_37 ,
struct V_70 * V_71 , unsigned V_43 , bool V_6 )
{
struct V_1 * V_2 = F_9 ( V_37 ) ;
struct V_26 * V_17 = V_2 -> V_17 ;
struct V_23 * V_24 ;
V_24 = F_29 ( V_2 , V_43 ) ;
if ( V_24 )
F_1 ( V_2 , V_24 -> V_4 ,
V_24 -> V_25 , V_6 ) ;
if ( V_17 -> F_30 )
V_17 -> F_30 ( V_2 , V_43 , V_6 ) ;
return 0 ;
}
static int F_31 ( struct V_36 * V_37 ,
struct V_70 * V_71 , unsigned V_43 )
{
return F_30 ( V_37 , V_71 , V_43 , true ) ;
}
static void F_32 ( struct V_36 * V_37 ,
struct V_70 * V_71 , unsigned V_43 )
{
F_30 ( V_37 , V_71 , V_43 , false ) ;
}
int F_33 ( struct V_72 * V_73 ,
struct V_26 * V_17 )
{
struct V_45 * V_50 = V_73 -> V_21 . V_74 ;
struct V_75 * V_76 ;
struct V_1 * V_2 ;
if ( ! V_17 )
return - V_56 ;
V_76 = F_34 ( V_73 , V_77 , 0 ) ;
if ( ! V_76 )
return - V_20 ;
V_2 = F_35 ( & V_73 -> V_21 , sizeof( * V_2 ) , V_57 ) ;
if ( ! V_2 ) {
F_18 ( & V_73 -> V_21 , L_8 ) ;
return - V_58 ;
}
V_2 -> V_78 = F_36 ( & V_73 -> V_21 , V_76 -> V_79 , F_37 ( V_76 ) ) ;
if ( ! V_2 -> V_78 ) {
F_18 ( & V_73 -> V_21 , L_9 ) ;
return - V_56 ;
}
V_2 -> V_21 = & V_73 -> V_21 ;
V_2 -> V_17 = V_17 ;
if ( V_17 -> V_65 ) {
int V_13 = 0 ;
if ( F_38 ( V_50 , L_10 , & V_13 ) ) {
F_18 ( & V_73 -> V_21 , L_11 ) ;
return - V_20 ;
}
if ( F_4 ( V_2 , V_13 ) ) {
F_18 ( & V_73 -> V_21 , L_12 ,
V_13 ) ;
return - V_20 ;
}
}
F_39 ( V_73 , V_2 ) ;
V_80 . V_38 = V_17 -> V_38 ;
V_80 . V_40 = V_17 -> V_40 ;
V_2 -> V_81 = F_40 ( & V_80 , & V_73 -> V_21 , V_2 ) ;
if ( ! V_2 -> V_81 ) {
F_18 ( & V_73 -> V_21 , L_13 ) ;
return - V_56 ;
}
return 0 ;
}
int F_41 ( struct V_72 * V_73 )
{
struct V_1 * V_2 = F_42 ( V_73 ) ;
F_43 ( V_2 -> V_81 ) ;
return 0 ;
}
