static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 ) -> V_4 ;
}
static inline int F_3 ( struct V_1 * V_4 ,
struct V_5 * V_6 )
{
T_1 V_7 , V_8 ;
int V_9 ;
if ( V_6 -> V_10 [ 0 ] == V_6 -> V_10 [ 1 ] &&
V_6 -> V_11 [ 0 ] == V_6 -> V_11 [ 1 ] )
return 0 ;
V_9 = F_4 ( V_4 , V_6 -> V_10 [ 0 ] , & V_7 ) ;
if ( V_9 )
return V_9 ;
V_9 = F_4 ( V_4 , V_6 -> V_10 [ 1 ] , & V_8 ) ;
if ( V_9 )
return V_9 ;
if ( ! ( V_8 & ( 1 << V_6 -> V_11 [ 1 ] ) ) )
return 0 ;
if ( ! ( V_7 & ( 1 << V_6 -> V_11 [ 0 ] ) ) ) {
V_9 = F_5 ( V_4 , V_6 -> V_10 [ 0 ] ,
1 << V_6 -> V_11 [ 0 ] ) ;
if ( V_9 )
return V_9 ;
}
return F_6 ( V_4 , V_6 -> V_10 [ 1 ] ,
1 << V_6 -> V_11 [ 1 ] ) ;
}
static int F_7 ( struct V_12 * V_13 ,
int V_14 , struct V_15 * V_16 )
{
struct V_1 * V_4 = V_13 -> V_17 . V_4 ;
struct V_18 * V_19 = V_16 -> V_20 ;
T_1 V_21 ;
if ( V_19 == NULL )
return 0 ;
if ( ! ( V_19 -> V_22 & V_23 ) )
return 0 ;
switch ( V_14 ) {
case V_24 :
V_21 = V_25 ;
break;
case V_26 :
V_21 = V_27 ;
break;
default:
F_8 ( & V_13 -> V_17 , L_1 ) ;
return - V_28 ;
}
return F_9 ( V_4 , V_21 ,
V_19 -> V_22 & V_29 ) ;
}
static inline struct V_5 * F_10 ( int V_14 )
{
struct V_5 * V_6 ;
int V_30 ;
for ( V_30 = 0 ; V_30 < F_11 ( V_5 ) ; V_30 ++ ) {
V_6 = & V_5 [ V_30 ] ;
if ( V_6 -> V_31 . V_14 == V_14 )
return V_6 ;
}
return NULL ;
}
static struct V_32 * F_12 (
struct V_12 * V_13 ,
struct V_33 * * V_34 )
{
const unsigned int V_35 = F_11 ( V_36 ) ;
struct V_37 * V_38 = V_13 -> V_17 . V_4 -> V_39 ;
struct V_37 * V_40 ;
const char * V_41 = NULL ;
unsigned int V_30 ;
struct V_32 * V_42 ;
int V_43 ;
V_40 = F_13 ( V_38 , L_2 ) ;
if ( ! V_40 ) {
F_14 ( & V_13 -> V_17 , L_3 ) ;
return NULL ;
}
V_43 = V_33 ( & V_13 -> V_17 , V_40 , V_36 , V_35 ) ;
if ( V_43 < 0 ) {
F_14 ( & V_13 -> V_17 , L_4 , V_43 ) ;
F_15 ( V_40 ) ;
return NULL ;
}
F_15 ( V_40 ) ;
V_42 = F_16 ( & V_13 -> V_17 , sizeof( * V_42 ) , V_44 ) ;
if ( ! V_42 ) {
F_14 ( & V_13 -> V_17 , L_5 ) ;
return NULL ;
}
for ( V_30 = 0 ; V_30 < V_35 ; V_30 ++ ) {
int V_14 ;
if ( ! V_36 [ V_30 ] . V_45 )
continue;
V_42 -> V_46 [ V_30 ] = V_36 [ V_30 ] . V_45 ;
V_14 = ( int ) V_36 [ V_30 ] . V_20 ;
if ( V_14 == V_47 )
V_41 = V_42 -> V_46 [ V_30 ] -> V_48 . V_49 ;
if ( ( V_14 == V_50 ) || ( V_14 == V_51 ) )
V_42 -> V_46 [ V_30 ] -> V_52 = V_41 ;
}
* V_34 = V_36 ;
return V_42 ;
}
static struct V_32 * F_12 (
struct V_12 * V_13 ,
struct V_33 * * V_34 )
{
* V_34 = NULL ;
return NULL ;
}
static int F_17 ( struct V_12 * V_13 )
{
struct V_5 * V_6 = NULL ;
struct V_53 V_54 = { } ;
struct V_2 * * V_3 ;
struct V_15 * V_55 ;
struct V_32 * V_42 ;
struct V_33 * V_34 = NULL ;
int V_14 ;
int V_43 ;
F_18 ( & V_13 -> V_17 , L_6 ) ;
V_42 = F_19 ( V_13 -> V_17 . V_4 ) ;
if ( ( ! V_42 ) && ( V_13 -> V_17 . V_4 -> V_39 ) )
V_42 = F_12 ( V_13 ,
& V_34 ) ;
if ( ! V_42 ) {
F_14 ( & V_13 -> V_17 , L_7 ) ;
return - V_56 ;
}
V_3 = F_16 ( & V_13 -> V_17 , V_57 *
sizeof( * V_3 ) , V_44 ) ;
if ( ! V_3 ) {
F_14 ( & V_13 -> V_17 , L_8 ) ;
return - V_58 ;
}
for ( V_14 = 0 ; V_14 < V_57 ; ++ V_14 ) {
V_55 = V_42 -> V_46 [ V_14 ] ;
V_6 = F_10 ( V_14 ) ;
if ( ! V_6 ) {
F_14 ( & V_13 -> V_17 , L_9 ) ;
V_43 = - V_28 ;
goto V_59;
}
V_43 = F_3 ( V_13 -> V_17 . V_4 , V_6 ) ;
if ( V_43 ) {
F_14 ( & V_13 -> V_17 ,
L_10 , V_14 , V_43 ) ;
goto V_59;
}
V_54 . V_17 = V_13 -> V_17 . V_4 ;
V_54 . V_45 = V_55 ;
V_54 . V_20 = V_6 ;
if ( V_34 )
V_54 . V_39 = V_34 [ V_14 ] . V_39 ;
V_3 [ V_14 ] = F_20 ( & V_6 -> V_31 , & V_54 ) ;
if ( F_21 ( V_3 [ V_14 ] ) ) {
F_14 ( & V_13 -> V_17 , L_11 ,
V_6 -> V_31 . V_49 ) ;
V_43 = F_22 ( V_3 [ V_14 ] ) ;
goto V_59;
}
if ( V_55 ) {
V_43 = F_7 ( V_13 , V_14 ,
V_55 ) ;
if ( V_43 < 0 ) {
F_14 ( & V_13 -> V_17 ,
L_12 , V_43 ) ;
F_23 ( V_3 [ V_14 ] ) ;
goto V_59;
}
}
}
F_24 ( V_13 , V_3 ) ;
return 0 ;
V_59:
while ( -- V_14 >= 0 )
F_23 ( V_3 [ V_14 ] ) ;
return V_43 ;
}
static int F_25 ( struct V_12 * V_13 )
{
struct V_2 * * V_3 = F_26 ( V_13 ) ;
int V_14 = V_57 ;
while ( -- V_14 >= 0 )
F_23 ( V_3 [ V_14 ] ) ;
return 0 ;
}
static int T_2 F_27 ( void )
{
return F_28 ( & V_60 ) ;
}
static void T_3 F_29 ( void )
{
F_30 ( & V_60 ) ;
}
