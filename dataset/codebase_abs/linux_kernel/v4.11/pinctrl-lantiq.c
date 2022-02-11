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
static void F_5 ( struct V_1 * V_13 ,
struct V_14 * V_15 , unsigned V_16 )
{
int V_17 ;
for ( V_17 = 0 ; V_17 < V_16 ; V_17 ++ )
if ( V_15 [ V_17 ] . type == V_18 ||
V_15 [ V_17 ] . type == V_19 )
F_6 ( V_15 [ V_17 ] . V_20 . V_21 . V_21 ) ;
F_6 ( V_15 ) ;
}
static void F_7 ( struct V_1 * V_13 ,
struct V_22 * V_23 ,
unsigned V_24 )
{
F_8 ( V_23 , L_1 , F_9 ( V_13 -> V_25 ) ) ;
}
static void F_10 ( struct V_1 * V_13 ,
struct V_26 * V_27 ,
struct V_14 * * V_15 )
{
struct V_3 * V_4 = F_2 ( V_13 ) ;
struct V_28 * V_9 = F_11 ( V_27 , L_2 , NULL ) ;
struct V_28 * V_29 = F_11 ( V_27 , L_3 , NULL ) ;
unsigned long V_21 [ 3 ] ;
unsigned V_30 = 0 ;
struct V_28 * V_31 ;
const char * V_32 , * V_33 ;
const char * V_34 ;
int V_35 , V_17 ;
if ( ! V_9 && ! V_29 ) {
F_12 ( V_13 -> V_25 , L_4 ,
V_27 -> V_8 ) ;
return;
}
if ( V_9 && V_29 ) {
F_12 ( V_13 -> V_25 , L_5 ,
V_27 -> V_8 ) ;
return;
}
V_35 = F_13 ( V_27 , L_6 , & V_34 ) ;
if ( V_29 && ! V_35 ) {
F_14 (np, L_3 , prop, group) {
( * V_15 ) -> type = V_36 ;
( * V_15 ) -> V_8 = V_34 ;
( * V_15 ) -> V_20 . V_37 . V_32 = V_32 ;
( * V_15 ) -> V_20 . V_37 . V_34 = V_34 ;
( * V_15 ) ++ ;
}
}
for ( V_17 = 0 ; V_17 < V_4 -> V_38 ; V_17 ++ ) {
T_1 V_39 ;
int V_35 = F_15 ( V_27 ,
V_4 -> V_40 [ V_17 ] . V_28 , & V_39 ) ;
if ( ! V_35 )
V_21 [ V_30 ++ ] =
F_16 ( V_4 -> V_40 [ V_17 ] . V_41 ,
V_39 ) ;
}
if ( ! V_30 )
return;
F_14 (np, L_2 , prop, pin) {
( * V_15 ) -> V_20 . V_21 . V_21 = F_17 ( V_21 ,
V_30 * sizeof( unsigned long ) ,
V_42 ) ;
( * V_15 ) -> type = V_18 ;
( * V_15 ) -> V_8 = V_33 ;
( * V_15 ) -> V_20 . V_21 . V_43 = V_33 ;
( * V_15 ) -> V_20 . V_21 . V_30 = V_30 ;
( * V_15 ) ++ ;
}
F_14 (np, L_3 , prop, group) {
( * V_15 ) -> V_20 . V_21 . V_21 = F_17 ( V_21 ,
V_30 * sizeof( unsigned long ) ,
V_42 ) ;
( * V_15 ) -> type = V_19 ;
( * V_15 ) -> V_8 = V_32 ;
( * V_15 ) -> V_20 . V_21 . V_43 = V_32 ;
( * V_15 ) -> V_20 . V_21 . V_30 = V_30 ;
( * V_15 ) ++ ;
}
}
static int F_18 ( struct V_26 * V_27 )
{
int V_35 ;
V_35 = F_19 ( V_27 , L_3 ) ;
if ( V_35 < 0 )
V_35 = F_19 ( V_27 , L_2 ) ;
return V_35 ;
}
static int F_20 ( struct V_1 * V_13 ,
struct V_26 * V_44 ,
struct V_14 * * V_15 ,
unsigned * V_16 )
{
struct V_14 * V_45 ;
struct V_26 * V_27 ;
int V_46 = 0 ;
F_21 (np_config, np)
V_46 += F_18 ( V_27 ) ;
* V_15 = F_22 ( V_46 * sizeof( struct V_14 ) * 2 , V_42 ) ;
if ( ! * V_15 )
return - V_47 ;
V_45 = * V_15 ;
F_21 (np_config, np)
F_10 ( V_13 , V_27 , & V_45 ) ;
* V_16 = ( ( int ) ( V_45 - * V_15 ) ) ;
return 0 ;
}
static int F_23 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
return V_4 -> V_48 ;
}
static const char * F_24 ( struct V_1 * V_2 ,
unsigned V_6 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( V_6 >= V_4 -> V_48 )
return NULL ;
return V_4 -> V_49 [ V_6 ] . V_8 ;
}
static int F_25 ( struct V_1 * V_2 ,
unsigned V_50 ,
const char * const * * V_29 ,
unsigned * const V_51 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
* V_29 = V_4 -> V_49 [ V_50 ] . V_29 ;
* V_51 = V_4 -> V_49 [ V_50 ] . V_51 ;
return 0 ;
}
static int F_26 ( const struct V_52 * V_53 , unsigned V_37 )
{
int V_17 ;
for ( V_17 = 0 ; V_17 < V_54 ; V_17 ++ ) {
if ( V_53 -> V_50 [ V_17 ] == V_37 )
break;
}
if ( V_17 >= V_54 )
return - V_11 ;
return V_17 ;
}
static int F_27 ( const struct V_3 * V_4 , int V_33 )
{
int V_17 ;
for ( V_17 = 0 ; V_17 < V_4 -> V_55 ; V_17 ++ ) {
if ( V_4 -> V_53 [ V_17 ] . V_33 == V_33 )
return V_17 ;
}
return - 1 ;
}
static int F_28 ( const struct V_56 * V_57 ,
const struct V_3 * V_4 ,
unsigned V_37 )
{
int V_17 , V_33 , V_35 = 0 ;
for ( V_17 = 0 ; V_17 < V_57 -> V_12 ; V_17 ++ ) {
V_33 = F_27 ( V_4 , V_57 -> V_9 [ V_17 ] ) ;
if ( V_33 < 0 ) {
F_12 ( V_4 -> V_25 , L_7 ,
V_57 -> V_9 [ V_17 ] ) ;
return - V_11 ;
}
V_35 = F_26 ( & V_4 -> V_53 [ V_33 ] , V_37 ) ;
if ( V_35 < 0 ) {
F_12 ( V_4 -> V_25 , L_8 ,
V_37 , V_33 ) ;
break;
}
}
return V_35 ;
}
static int F_29 ( struct V_1 * V_2 ,
unsigned V_50 ,
unsigned V_32 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
const struct V_56 * V_58 = & V_4 -> V_7 [ V_32 ] ;
int V_17 , V_33 , V_59 , V_35 ;
if ( ! V_58 -> V_12 ||
( F_28 ( V_58 , V_4 , V_58 -> V_37 ) < 0 ) ) {
F_12 ( V_4 -> V_25 , L_9 ,
V_4 -> V_7 [ V_32 ] . V_8 ) ;
return - V_11 ;
}
for ( V_17 = 0 ; V_17 < V_58 -> V_12 ; V_17 ++ ) {
V_33 = F_27 ( V_4 , V_58 -> V_9 [ V_17 ] ) ;
if ( V_33 < 0 ) {
F_12 ( V_4 -> V_25 , L_7 ,
V_58 -> V_9 [ V_17 ] ) ;
return - V_11 ;
}
V_59 = F_26 ( & V_4 -> V_53 [ V_33 ] , V_58 -> V_37 ) ;
V_35 = V_4 -> V_60 ( V_2 , V_33 , V_59 ) ;
if ( V_35 ) {
F_12 ( V_4 -> V_25 ,
L_10 ,
V_59 , V_33 ) ;
return V_35 ;
}
}
return 0 ;
}
static int F_30 ( struct V_1 * V_2 ,
struct V_61 * V_62 ,
unsigned V_33 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_53 = F_27 ( V_4 , V_33 ) ;
int V_59 ;
if ( V_53 < 0 ) {
F_12 ( V_4 -> V_25 , L_7 , V_33 ) ;
return - V_11 ;
}
V_59 = F_26 ( & V_4 -> V_53 [ V_53 ] , 0 ) ;
if ( V_59 < 0 ) {
F_12 ( V_4 -> V_25 , L_11 , V_53 ) ;
return - V_11 ;
}
return V_4 -> V_60 ( V_2 , V_53 , V_59 ) ;
}
int F_31 ( struct V_63 * V_64 ,
struct V_3 * V_4 )
{
struct V_65 * V_66 ;
if ( ! V_4 )
return - V_11 ;
V_66 = V_4 -> V_66 ;
V_66 -> V_67 = & V_68 ;
V_66 -> V_69 = & V_70 ;
V_4 -> V_25 = & V_64 -> V_25 ;
V_4 -> V_71 = F_32 ( & V_64 -> V_25 , V_66 , V_4 ) ;
if ( F_33 ( V_4 -> V_71 ) ) {
F_12 ( & V_64 -> V_25 , L_12 ) ;
return F_34 ( V_4 -> V_71 ) ;
}
F_35 ( V_64 , V_4 ) ;
return 0 ;
}
