static inline int F_1 ( int V_1 )
{
return ( V_2 * 1000 + ( V_1 * 200000 / 255 ) ) ;
}
static inline long F_2 ( long V_3 )
{
return ( ( V_3 - V_2 * 1000 ) * 255 ) / 200000 ;
}
static long F_3 ( struct V_4 * V_5 ,
struct V_6 * V_7 )
{
long V_8 ;
F_4 ( & V_5 -> V_9 ) ;
F_5 ( 0x0 , V_5 -> V_10 + V_11 ) ;
F_5 ( 0x1 , V_5 -> V_10 + V_12 ) ;
F_5 ( 0x0 , V_5 -> V_10 + V_13 ) ;
F_5 ( ( V_7 -> V_14 << 12 ) , V_5 -> V_10 + V_15 ) ;
F_5 ( 0x1 , V_5 -> V_10 + V_13 ) ;
F_6 ( 3000 , 5000 ) ;
V_8 = F_7 ( V_5 -> V_10 + V_16 ) ;
V_8 = F_1 ( V_8 ) ;
F_8 ( & V_5 -> V_9 ) ;
return V_8 ;
}
static void F_9
( struct V_4 * V_5 )
{
struct V_6 * V_7 ;
F_4 ( & V_5 -> V_9 ) ;
V_7 = & V_5 -> V_17 [ V_5 -> V_18 ] ;
F_5 ( 0x0 , V_5 -> V_10 + V_15 ) ;
F_5 ( 0x0 , V_5 -> V_10 + V_19 ) ;
F_5 ( 0x0 , V_5 -> V_10 + V_13 ) ;
F_5 ( ( V_7 -> V_14 << 12 ) , V_5 -> V_10 + V_15 ) ;
F_5 ( F_2 ( V_7 -> V_20 ) | 0x0FFFFFF00 ,
V_5 -> V_10 + V_21 ) ;
F_5 ( F_2 ( V_22 ) , V_5 -> V_10 + V_23 ) ;
F_5 ( 0x1 , V_5 -> V_10 + V_19 ) ;
F_5 ( 0x1 , V_5 -> V_10 + V_13 ) ;
F_5 ( 0x0 , V_5 -> V_10 + V_12 ) ;
F_5 ( 0x1 , V_5 -> V_10 + V_11 ) ;
F_6 ( 3000 , 5000 ) ;
F_8 ( & V_5 -> V_9 ) ;
}
static void F_10 ( struct V_4 * V_5 )
{
F_4 ( & V_5 -> V_9 ) ;
F_5 ( 0x0 , V_5 -> V_10 + V_11 ) ;
F_5 ( 0x0 , V_5 -> V_10 + V_19 ) ;
F_5 ( 0x0 , V_5 -> V_10 + V_13 ) ;
F_8 ( & V_5 -> V_9 ) ;
}
static int F_11 ( void * V_24 , int * V_3 )
{
struct V_6 * V_7 = V_24 ;
struct V_4 * V_5 = V_7 -> V_25 ;
int V_26 = 0 , V_27 ;
long V_28 = 0 ;
* V_3 = F_3 ( V_5 , V_7 ) ;
V_7 -> V_29 = * V_3 ;
for ( V_27 = 0 ; V_27 < V_30 ; V_27 ++ ) {
if ( V_5 -> V_17 [ V_27 ] . V_29 >= V_28 ) {
V_28 = V_5 -> V_17 [ V_27 ] . V_29 ;
V_26 = V_27 ;
}
}
F_4 ( & V_5 -> V_9 ) ;
V_5 -> V_18 = V_26 ;
F_8 ( & V_5 -> V_9 ) ;
F_12 ( & V_5 -> V_31 -> V_32 , L_1 ,
V_7 -> V_14 , V_5 -> V_33 , * V_3 , V_7 -> V_20 ) ;
if ( V_5 -> V_33 ) {
F_9 ( V_5 ) ;
return 0 ;
}
if ( V_28 < V_7 -> V_20 ) {
V_5 -> V_33 = true ;
F_9 ( V_5 ) ;
F_13 ( V_5 -> V_34 ) ;
}
return 0 ;
}
static T_1 F_14 ( int V_34 , void * V_32 )
{
struct V_4 * V_5 = V_32 ;
F_15 ( V_34 ) ;
V_5 -> V_33 = false ;
return V_35 ;
}
static T_1 F_16 ( int V_34 , void * V_32 )
{
struct V_4 * V_5 = V_32 ;
struct V_6 * V_7 ;
int V_27 ;
F_4 ( & V_5 -> V_9 ) ;
V_7 = & V_5 -> V_17 [ V_5 -> V_18 ] ;
F_17 ( & V_5 -> V_31 -> V_32 , L_2 ,
V_7 -> V_20 / 1000 ) ;
F_8 ( & V_5 -> V_9 ) ;
for ( V_27 = 0 ; V_27 < V_30 ; V_27 ++ )
F_18 ( V_5 -> V_17 [ V_27 ] . V_36 ) ;
return V_37 ;
}
static int F_19 ( struct V_38 * V_31 ,
struct V_4 * V_5 ,
struct V_6 * V_7 ,
int V_39 )
{
int V_40 , V_27 ;
const struct V_41 * V_42 ;
V_7 -> V_14 = V_39 ;
V_7 -> V_25 = V_5 ;
V_7 -> V_36 = F_20 ( & V_31 -> V_32 , V_7 -> V_14 ,
V_7 , & V_43 ) ;
if ( F_21 ( V_7 -> V_36 ) ) {
V_40 = F_22 ( V_7 -> V_36 ) ;
F_23 ( & V_31 -> V_32 , L_3 ,
V_7 -> V_14 , V_40 ) ;
return V_40 ;
}
V_42 = F_24 ( V_7 -> V_36 ) ;
for ( V_27 = 0 ; V_27 < F_25 ( V_7 -> V_36 ) ; V_27 ++ ) {
if ( V_42 [ V_27 ] . type == V_44 ) {
V_7 -> V_20 = V_42 [ V_27 ] . V_45 ;
break;
}
}
return 0 ;
}
static void F_26 ( struct V_6 * V_7 ,
bool V_46 )
{
struct V_47 * V_36 = V_7 -> V_36 ;
V_36 -> V_48 -> V_49 ( V_36 ,
V_46 ? V_50 : V_51 ) ;
}
static int F_27 ( struct V_38 * V_31 )
{
struct V_4 * V_5 ;
struct V_52 * V_53 ;
int V_27 ;
int V_40 ;
V_5 = F_28 ( & V_31 -> V_32 , sizeof( * V_5 ) , V_54 ) ;
if ( ! V_5 )
return - V_55 ;
F_29 ( & V_5 -> V_9 ) ;
V_5 -> V_31 = V_31 ;
V_53 = F_30 ( V_31 , V_56 , 0 ) ;
V_5 -> V_10 = F_31 ( & V_31 -> V_32 , V_53 ) ;
if ( F_21 ( V_5 -> V_10 ) ) {
F_23 ( & V_31 -> V_32 , L_4 ) ;
return F_22 ( V_5 -> V_10 ) ;
}
V_5 -> V_34 = F_32 ( V_31 , 0 ) ;
if ( V_5 -> V_34 < 0 )
return V_5 -> V_34 ;
V_40 = F_33 ( & V_31 -> V_32 , V_5 -> V_34 ,
F_14 ,
F_16 ,
0 , L_5 , V_5 ) ;
if ( V_40 < 0 ) {
F_23 ( & V_31 -> V_32 , L_6 , V_40 ) ;
return V_40 ;
}
F_34 ( V_31 , V_5 ) ;
V_5 -> V_57 = F_35 ( & V_31 -> V_32 , L_7 ) ;
if ( F_21 ( V_5 -> V_57 ) ) {
V_40 = F_22 ( V_5 -> V_57 ) ;
if ( V_40 != - V_58 )
F_23 ( & V_31 -> V_32 ,
L_8 , V_40 ) ;
return V_40 ;
}
V_40 = F_36 ( V_5 -> V_57 ) ;
if ( V_40 ) {
F_23 ( & V_31 -> V_32 , L_9 , V_40 ) ;
return V_40 ;
}
for ( V_27 = 0 ; V_27 < V_30 ; ++ V_27 ) {
V_40 = F_19 ( V_31 , V_5 ,
& V_5 -> V_17 [ V_27 ] , V_27 ) ;
if ( V_40 ) {
F_23 ( & V_31 -> V_32 ,
L_10 , V_40 ) ;
goto V_59;
}
}
F_9 ( V_5 ) ;
V_5 -> V_33 = true ;
for ( V_27 = 0 ; V_27 < V_30 ; V_27 ++ )
F_26 ( & V_5 -> V_17 [ V_27 ] , true ) ;
return 0 ;
V_59:
F_37 ( V_5 -> V_57 ) ;
return V_40 ;
}
static int F_38 ( struct V_38 * V_31 )
{
struct V_4 * V_5 = F_39 ( V_31 ) ;
int V_27 ;
for ( V_27 = 0 ; V_27 < V_30 ; V_27 ++ ) {
struct V_6 * V_7 = & V_5 -> V_17 [ V_27 ] ;
F_26 ( V_7 , false ) ;
F_40 ( & V_31 -> V_32 , V_7 -> V_36 ) ;
}
F_10 ( V_5 ) ;
F_37 ( V_5 -> V_57 ) ;
return 0 ;
}
static int F_41 ( struct V_60 * V_32 )
{
struct V_4 * V_5 = F_42 ( V_32 ) ;
F_10 ( V_5 ) ;
V_5 -> V_33 = false ;
F_37 ( V_5 -> V_57 ) ;
return 0 ;
}
static int F_43 ( struct V_60 * V_32 )
{
struct V_4 * V_5 = F_42 ( V_32 ) ;
F_36 ( V_5 -> V_57 ) ;
V_5 -> V_33 = true ;
F_9 ( V_5 ) ;
return 0 ;
}
