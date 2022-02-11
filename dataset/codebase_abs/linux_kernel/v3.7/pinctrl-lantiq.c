static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
return V_4 -> V_5 ;
}
static const char * F_3 ( struct V_1 * V_2 ,
unsigned V_6 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( V_6 >= V_4 -> V_5 )
return NULL ;
return V_4 -> V_7 [ V_6 ] . V_8 ;
}
static int F_4 ( struct V_1 * V_2 ,
unsigned V_6 ,
const unsigned * * V_9 ,
unsigned * V_10 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( V_6 >= V_4 -> V_5 )
return - V_11 ;
* V_9 = V_4 -> V_7 [ V_6 ] . V_9 ;
* V_10 = V_4 -> V_7 [ V_6 ] . V_12 ;
return 0 ;
}
void F_5 ( struct V_1 * V_13 ,
struct V_14 * V_15 , unsigned V_16 )
{
int V_17 ;
for ( V_17 = 0 ; V_17 < V_16 ; V_17 ++ )
if ( V_15 [ V_17 ] . type == V_18 )
F_6 ( V_15 [ V_17 ] . V_19 . V_20 . V_20 ) ;
F_6 ( V_15 ) ;
}
static void F_7 ( struct V_1 * V_13 ,
struct V_21 * V_22 ,
unsigned V_23 )
{
F_8 ( V_22 , L_1 , F_9 ( V_13 -> V_24 ) ) ;
}
static int F_10 ( struct V_1 * V_13 ,
struct V_25 * V_26 ,
struct V_14 * * V_15 )
{
struct V_3 * V_4 = F_2 ( V_13 ) ;
unsigned long V_20 [ 3 ] ;
unsigned V_27 = 0 ;
struct V_28 * V_29 ;
const char * V_30 , * V_31 ;
const char * V_32 ;
int V_33 , V_17 ;
V_33 = F_11 ( V_26 , L_2 , & V_32 ) ;
if ( ! V_33 ) {
F_12 (np, L_3 , prop, group) {
( * V_15 ) -> type = V_34 ;
( * V_15 ) -> V_8 = V_32 ;
( * V_15 ) -> V_19 . V_35 . V_30 = V_30 ;
( * V_15 ) -> V_19 . V_35 . V_32 = V_32 ;
( * V_15 ) ++ ;
}
if ( F_13 ( V_26 , L_4 , NULL ) )
F_14 ( V_13 -> V_24 ,
L_5 ,
V_26 -> V_8 ) ;
return 0 ;
}
for ( V_17 = 0 ; V_17 < V_4 -> V_36 ; V_17 ++ ) {
T_1 V_37 ;
int V_33 = F_15 ( V_26 ,
V_4 -> V_38 [ V_17 ] . V_28 , & V_37 ) ;
if ( ! V_33 )
V_20 [ V_27 ++ ] =
F_16 ( V_4 -> V_38 [ V_17 ] . V_39 ,
V_37 ) ;
}
if ( ! V_27 )
return - V_11 ;
F_12 (np, L_4 , prop, pin) {
( * V_15 ) -> V_19 . V_20 . V_20 = F_17 ( V_20 ,
V_27 * sizeof( unsigned long ) ,
V_40 ) ;
( * V_15 ) -> type = V_18 ;
( * V_15 ) -> V_8 = V_31 ;
( * V_15 ) -> V_19 . V_20 . V_41 = V_31 ;
( * V_15 ) -> V_19 . V_20 . V_27 = V_27 ;
( * V_15 ) ++ ;
}
return 0 ;
}
static int F_18 ( struct V_25 * V_26 )
{
int V_33 ;
V_33 = F_19 ( V_26 , L_3 ) ;
if ( V_33 < 0 )
V_33 = F_19 ( V_26 , L_4 ) ;
return V_33 ;
}
int F_20 ( struct V_1 * V_13 ,
struct V_25 * V_42 ,
struct V_14 * * V_15 ,
unsigned * V_16 )
{
struct V_14 * V_43 ;
struct V_25 * V_26 ;
int V_33 ;
* V_16 = 0 ;
F_21 ( V_42 , V_26 )
* V_16 += F_18 ( V_26 ) ;
* V_15 = F_22 ( * V_16 * sizeof( struct V_14 ) , V_40 ) ;
if ( ! * V_15 )
return - V_44 ;
V_43 = * V_15 ;
F_21 (np_config, np) {
V_33 = F_10 ( V_13 , V_26 , & V_43 ) ;
if ( V_33 < 0 ) {
F_5 ( V_13 , * V_15 , * V_16 ) ;
return V_33 ;
}
}
return 0 ;
}
static int F_23 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
return V_4 -> V_45 ;
}
static const char * F_24 ( struct V_1 * V_2 ,
unsigned V_6 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( V_6 >= V_4 -> V_45 )
return NULL ;
return V_4 -> V_46 [ V_6 ] . V_8 ;
}
static int F_25 ( struct V_1 * V_2 ,
unsigned V_47 ,
const char * const * * V_48 ,
unsigned * const V_49 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
* V_48 = V_4 -> V_46 [ V_47 ] . V_48 ;
* V_49 = V_4 -> V_46 [ V_47 ] . V_49 ;
return 0 ;
}
static int F_26 ( const struct V_50 * V_51 , unsigned V_35 )
{
int V_17 ;
for ( V_17 = 0 ; V_17 < V_52 ; V_17 ++ ) {
if ( V_51 -> V_47 [ V_17 ] == V_35 )
break;
}
if ( V_17 >= V_52 )
return - V_11 ;
return V_17 ;
}
static int F_27 ( const struct V_3 * V_4 , int V_31 )
{
int V_17 ;
for ( V_17 = 0 ; V_17 < V_4 -> V_53 ; V_17 ++ ) {
if ( V_4 -> V_51 [ V_17 ] . V_31 == V_31 )
return V_17 ;
}
return - 1 ;
}
static int F_28 ( const struct V_54 * V_55 ,
const struct V_3 * V_4 ,
unsigned V_35 )
{
int V_17 , V_31 , V_33 = 0 ;
for ( V_17 = 0 ; V_17 < V_55 -> V_12 ; V_17 ++ ) {
V_31 = F_27 ( V_4 , V_55 -> V_9 [ V_17 ] ) ;
if ( V_31 < 0 ) {
F_14 ( V_4 -> V_24 , L_6 ,
V_55 -> V_9 [ V_17 ] ) ;
return - V_11 ;
}
V_33 = F_26 ( & V_4 -> V_51 [ V_31 ] , V_35 ) ;
if ( V_33 < 0 ) {
F_14 ( V_4 -> V_24 , L_7 ,
V_35 , V_31 ) ;
break;
}
}
return V_33 ;
}
static int F_29 ( struct V_1 * V_2 ,
unsigned V_47 ,
unsigned V_30 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
const struct V_54 * V_56 = & V_4 -> V_7 [ V_30 ] ;
int V_17 , V_31 , V_57 , V_33 ;
if ( ! V_56 -> V_12 ||
( F_28 ( V_56 , V_4 , V_56 -> V_35 ) < 0 ) ) {
F_14 ( V_4 -> V_24 , L_8 ,
V_4 -> V_7 [ V_30 ] . V_8 ) ;
return - V_11 ;
}
for ( V_17 = 0 ; V_17 < V_56 -> V_12 ; V_17 ++ ) {
V_31 = F_27 ( V_4 , V_56 -> V_9 [ V_17 ] ) ;
if ( V_31 < 0 ) {
F_14 ( V_4 -> V_24 , L_6 ,
V_56 -> V_9 [ V_17 ] ) ;
return - V_11 ;
}
V_57 = F_26 ( & V_4 -> V_51 [ V_31 ] , V_56 -> V_35 ) ;
V_33 = V_4 -> V_58 ( V_2 , V_31 , V_57 ) ;
if ( V_33 ) {
F_14 ( V_4 -> V_24 ,
L_9 ,
V_57 , V_31 ) ;
return V_33 ;
}
}
return 0 ;
}
static void F_30 ( struct V_1 * V_2 ,
unsigned V_47 ,
unsigned V_30 )
{
}
static int F_31 ( struct V_1 * V_2 ,
struct V_59 * V_60 ,
unsigned V_31 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_51 = F_27 ( V_4 , V_31 + ( V_60 -> V_61 * 32 ) ) ;
int V_57 ;
if ( V_51 < 0 ) {
F_14 ( V_4 -> V_24 , L_6 , V_31 ) ;
return - V_11 ;
}
V_57 = F_26 ( & V_4 -> V_51 [ V_51 ] , 0 ) ;
if ( V_57 < 0 ) {
F_14 ( V_4 -> V_24 , L_10 , V_51 ) ;
return - V_11 ;
}
return V_4 -> V_58 ( V_2 , V_51 , V_57 ) ;
}
int F_32 ( struct V_62 * V_63 ,
struct V_3 * V_4 )
{
struct V_64 * V_65 ;
if ( ! V_4 )
return - V_11 ;
V_65 = V_4 -> V_65 ;
V_65 -> V_66 = & V_67 ;
V_65 -> V_68 = & V_69 ;
V_4 -> V_24 = & V_63 -> V_24 ;
V_4 -> V_70 = F_33 ( V_65 , & V_63 -> V_24 , V_4 ) ;
if ( ! V_4 -> V_70 ) {
F_14 ( & V_63 -> V_24 , L_11 ) ;
return - V_11 ;
}
F_34 ( V_63 , V_4 ) ;
return 0 ;
}
