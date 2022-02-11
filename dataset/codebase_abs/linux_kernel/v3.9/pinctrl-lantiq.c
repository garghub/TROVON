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
static void F_10 ( struct V_1 * V_13 ,
struct V_25 * V_26 ,
struct V_14 * * V_15 )
{
struct V_3 * V_4 = F_2 ( V_13 ) ;
struct V_27 * V_9 = F_11 ( V_26 , L_2 , NULL ) ;
struct V_27 * V_28 = F_11 ( V_26 , L_3 , NULL ) ;
unsigned long V_20 [ 3 ] ;
unsigned V_29 = 0 ;
struct V_27 * V_30 ;
const char * V_31 , * V_32 ;
const char * V_33 ;
int V_34 , V_17 ;
if ( ! V_9 && ! V_28 ) {
F_12 ( V_13 -> V_24 , L_4 ,
V_26 -> V_8 ) ;
return;
}
if ( V_9 && V_28 ) {
F_12 ( V_13 -> V_24 , L_5 ,
V_26 -> V_8 ) ;
return;
}
V_34 = F_13 ( V_26 , L_6 , & V_33 ) ;
if ( V_28 && ! V_34 ) {
F_14 (np, L_3 , prop, group) {
( * V_15 ) -> type = V_35 ;
( * V_15 ) -> V_8 = V_33 ;
( * V_15 ) -> V_19 . V_36 . V_31 = V_31 ;
( * V_15 ) -> V_19 . V_36 . V_33 = V_33 ;
( * V_15 ) ++ ;
}
}
for ( V_17 = 0 ; V_17 < V_4 -> V_37 ; V_17 ++ ) {
T_1 V_38 ;
int V_34 = F_15 ( V_26 ,
V_4 -> V_39 [ V_17 ] . V_27 , & V_38 ) ;
if ( ! V_34 )
V_20 [ V_29 ++ ] =
F_16 ( V_4 -> V_39 [ V_17 ] . V_40 ,
V_38 ) ;
}
if ( ! V_29 )
return;
F_14 (np, L_2 , prop, pin) {
( * V_15 ) -> V_19 . V_20 . V_20 = F_17 ( V_20 ,
V_29 * sizeof( unsigned long ) ,
V_41 ) ;
( * V_15 ) -> type = V_18 ;
( * V_15 ) -> V_8 = V_32 ;
( * V_15 ) -> V_19 . V_20 . V_42 = V_32 ;
( * V_15 ) -> V_19 . V_20 . V_29 = V_29 ;
( * V_15 ) ++ ;
}
F_14 (np, L_3 , prop, group) {
( * V_15 ) -> V_19 . V_20 . V_20 = F_17 ( V_20 ,
V_29 * sizeof( unsigned long ) ,
V_41 ) ;
( * V_15 ) -> type = V_43 ;
( * V_15 ) -> V_8 = V_31 ;
( * V_15 ) -> V_19 . V_20 . V_42 = V_31 ;
( * V_15 ) -> V_19 . V_20 . V_29 = V_29 ;
( * V_15 ) ++ ;
}
}
static int F_18 ( struct V_25 * V_26 )
{
int V_34 ;
V_34 = F_19 ( V_26 , L_3 ) ;
if ( V_34 < 0 )
V_34 = F_19 ( V_26 , L_2 ) ;
return V_34 ;
}
static int F_20 ( struct V_1 * V_13 ,
struct V_25 * V_44 ,
struct V_14 * * V_15 ,
unsigned * V_16 )
{
struct V_14 * V_45 ;
struct V_25 * V_26 ;
int V_46 = 0 ;
F_21 (np_config, np)
V_46 += F_18 ( V_26 ) ;
* V_15 = F_22 ( V_46 * sizeof( struct V_14 ) * 2 , V_41 ) ;
if ( ! * V_15 )
return - V_47 ;
V_45 = * V_15 ;
F_21 (np_config, np)
F_10 ( V_13 , V_26 , & V_45 ) ;
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
const char * const * * V_28 ,
unsigned * const V_51 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
* V_28 = V_4 -> V_49 [ V_50 ] . V_28 ;
* V_51 = V_4 -> V_49 [ V_50 ] . V_51 ;
return 0 ;
}
static int F_26 ( const struct V_52 * V_53 , unsigned V_36 )
{
int V_17 ;
for ( V_17 = 0 ; V_17 < V_54 ; V_17 ++ ) {
if ( V_53 -> V_50 [ V_17 ] == V_36 )
break;
}
if ( V_17 >= V_54 )
return - V_11 ;
return V_17 ;
}
static int F_27 ( const struct V_3 * V_4 , int V_32 )
{
int V_17 ;
for ( V_17 = 0 ; V_17 < V_4 -> V_55 ; V_17 ++ ) {
if ( V_4 -> V_53 [ V_17 ] . V_32 == V_32 )
return V_17 ;
}
return - 1 ;
}
static int F_28 ( const struct V_56 * V_57 ,
const struct V_3 * V_4 ,
unsigned V_36 )
{
int V_17 , V_32 , V_34 = 0 ;
for ( V_17 = 0 ; V_17 < V_57 -> V_12 ; V_17 ++ ) {
V_32 = F_27 ( V_4 , V_57 -> V_9 [ V_17 ] ) ;
if ( V_32 < 0 ) {
F_12 ( V_4 -> V_24 , L_7 ,
V_57 -> V_9 [ V_17 ] ) ;
return - V_11 ;
}
V_34 = F_26 ( & V_4 -> V_53 [ V_32 ] , V_36 ) ;
if ( V_34 < 0 ) {
F_12 ( V_4 -> V_24 , L_8 ,
V_36 , V_32 ) ;
break;
}
}
return V_34 ;
}
static int F_29 ( struct V_1 * V_2 ,
unsigned V_50 ,
unsigned V_31 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
const struct V_56 * V_58 = & V_4 -> V_7 [ V_31 ] ;
int V_17 , V_32 , V_59 , V_34 ;
if ( ! V_58 -> V_12 ||
( F_28 ( V_58 , V_4 , V_58 -> V_36 ) < 0 ) ) {
F_12 ( V_4 -> V_24 , L_9 ,
V_4 -> V_7 [ V_31 ] . V_8 ) ;
return - V_11 ;
}
for ( V_17 = 0 ; V_17 < V_58 -> V_12 ; V_17 ++ ) {
V_32 = F_27 ( V_4 , V_58 -> V_9 [ V_17 ] ) ;
if ( V_32 < 0 ) {
F_12 ( V_4 -> V_24 , L_7 ,
V_58 -> V_9 [ V_17 ] ) ;
return - V_11 ;
}
V_59 = F_26 ( & V_4 -> V_53 [ V_32 ] , V_58 -> V_36 ) ;
V_34 = V_4 -> V_60 ( V_2 , V_32 , V_59 ) ;
if ( V_34 ) {
F_12 ( V_4 -> V_24 ,
L_10 ,
V_59 , V_32 ) ;
return V_34 ;
}
}
return 0 ;
}
static int F_30 ( struct V_1 * V_2 ,
struct V_61 * V_62 ,
unsigned V_32 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_53 = F_27 ( V_4 , V_32 ) ;
int V_59 ;
if ( V_53 < 0 ) {
F_12 ( V_4 -> V_24 , L_7 , V_32 ) ;
return - V_11 ;
}
V_59 = F_26 ( & V_4 -> V_53 [ V_53 ] , 0 ) ;
if ( V_59 < 0 ) {
F_12 ( V_4 -> V_24 , L_11 , V_53 ) ;
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
V_4 -> V_24 = & V_64 -> V_24 ;
V_4 -> V_71 = F_32 ( V_66 , & V_64 -> V_24 , V_4 ) ;
if ( ! V_4 -> V_71 ) {
F_12 ( & V_64 -> V_24 , L_12 ) ;
return - V_11 ;
}
F_33 ( V_64 , V_4 ) ;
return 0 ;
}
