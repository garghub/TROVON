int
F_1 (
unsigned int V_1 )
{
ASSERT ( V_1 > 0 ) ;
return F_2 ( V_1 ) / sizeof( V_2 ) ;
}
int
F_3 (
struct V_3 * V_4 ,
T_1 * V_5 ,
T_2 V_6 ,
T_3 type ,
T_3 V_7 ,
const char * V_8 )
{
V_2 * V_9 = ( V_2 * ) V_5 ;
int V_10 = 0 ;
if ( V_5 -> V_11 != F_4 ( V_12 ) ) {
if ( V_7 & V_13 )
F_5 ( V_4 ,
L_1 ,
V_8 , V_6 , F_6 ( V_5 -> V_11 ) , V_12 ) ;
V_10 ++ ;
}
if ( V_5 -> V_14 != V_15 ) {
if ( V_7 & V_13 )
F_5 ( V_4 ,
L_2 ,
V_8 , V_6 , V_5 -> V_14 , V_15 ) ;
V_10 ++ ;
}
if ( V_5 -> V_16 != V_17 &&
V_5 -> V_16 != V_18 &&
V_5 -> V_16 != V_19 ) {
if ( V_7 & V_13 )
F_5 ( V_4 ,
L_3 ,
V_8 , V_6 , V_5 -> V_16 ) ;
V_10 ++ ;
}
if ( V_6 != - 1 && V_6 != F_7 ( V_5 -> V_20 ) ) {
if ( V_7 & V_13 )
F_5 ( V_4 ,
L_4
L_5 ,
V_8 , V_5 , V_6 , F_7 ( V_5 -> V_20 ) ) ;
V_10 ++ ;
}
if ( ! V_10 && V_5 -> V_20 ) {
if ( V_5 -> V_21 &&
F_8 ( V_5 -> V_22 ) >
F_8 ( V_5 -> V_21 ) ) {
if ( ! V_5 -> V_23 ) {
if ( V_7 & V_13 )
F_5 ( V_4 ,
L_6 ,
V_8 , ( int ) F_7 ( V_5 -> V_20 ) , V_5 ) ;
V_10 ++ ;
}
}
if ( V_5 -> V_24 &&
F_8 ( V_5 -> V_25 ) >
F_8 ( V_5 -> V_24 ) ) {
if ( ! V_5 -> V_26 ) {
if ( V_7 & V_13 )
F_5 ( V_4 ,
L_7 ,
V_8 , ( int ) F_7 ( V_5 -> V_20 ) , V_5 ) ;
V_10 ++ ;
}
}
if ( V_5 -> V_27 &&
F_8 ( V_5 -> V_28 ) >
F_8 ( V_5 -> V_27 ) ) {
if ( ! V_5 -> V_29 ) {
if ( V_7 & V_13 )
F_5 ( V_4 ,
L_8 ,
V_8 , ( int ) F_7 ( V_5 -> V_20 ) , V_5 ) ;
V_10 ++ ;
}
}
}
if ( ! V_10 || ! ( V_7 & V_30 ) )
return V_10 ;
if ( V_7 & V_13 )
F_9 ( V_4 , L_9 , V_6 ) ;
ASSERT ( V_6 != - 1 ) ;
ASSERT ( V_7 & V_30 ) ;
memset ( V_9 , 0 , sizeof( V_2 ) ) ;
V_9 -> V_31 . V_11 = F_4 ( V_12 ) ;
V_9 -> V_31 . V_14 = V_15 ;
V_9 -> V_31 . V_16 = type ;
V_9 -> V_31 . V_20 = F_10 ( V_6 ) ;
if ( F_11 ( & V_4 -> V_32 ) ) {
F_12 ( & V_9 -> V_33 , & V_4 -> V_32 . V_34 ) ;
F_13 ( ( char * ) V_9 , sizeof( struct V_35 ) ,
V_36 ) ;
}
return V_10 ;
}
STATIC bool
F_14 (
struct V_3 * V_4 ,
struct V_37 * V_38 )
{
struct V_35 * V_9 = (struct V_35 * ) V_38 -> V_39 ;
int V_40 ;
int V_41 ;
if ( ! F_11 ( & V_4 -> V_32 ) )
return true ;
if ( V_4 -> V_42 )
V_40 = V_4 -> V_42 -> V_43 ;
else
V_40 = F_1 ( V_38 -> V_44 ) ;
for ( V_41 = 0 ; V_41 < V_40 ; V_41 ++ , V_9 ++ ) {
if ( ! F_15 ( ( char * ) V_9 , sizeof( struct V_35 ) ,
V_36 ) )
return false ;
if ( ! F_16 ( & V_9 -> V_33 , & V_4 -> V_32 . V_34 ) )
return false ;
}
return true ;
}
STATIC bool
F_17 (
struct V_3 * V_4 ,
struct V_37 * V_38 ,
int V_45 )
{
struct V_35 * V_9 = (struct V_35 * ) V_38 -> V_39 ;
T_2 V_6 = 0 ;
int V_40 ;
int V_41 ;
if ( V_4 -> V_42 )
V_40 = V_4 -> V_42 -> V_43 ;
else
V_40 = F_1 ( V_38 -> V_44 ) ;
for ( V_41 = 0 ; V_41 < V_40 ; V_41 ++ ) {
struct V_46 * V_5 ;
int error ;
V_5 = & V_9 [ V_41 ] . V_31 ;
if ( V_41 == 0 )
V_6 = F_7 ( V_5 -> V_20 ) ;
error = F_3 ( V_4 , V_5 , V_6 + V_41 , 0 , V_45 , V_47 ) ;
if ( error )
return false ;
}
return true ;
}
static void
F_18 (
struct V_37 * V_38 )
{
struct V_3 * V_4 = V_38 -> V_48 -> V_49 ;
if ( ! F_14 ( V_4 , V_38 ) )
F_19 ( V_38 , - V_50 ) ;
else if ( ! F_17 ( V_4 , V_38 , V_13 ) )
F_19 ( V_38 , - V_51 ) ;
if ( V_38 -> V_52 )
F_20 ( V_38 ) ;
}
static void
F_21 (
struct V_37 * V_38 )
{
struct V_3 * V_4 = V_38 -> V_48 -> V_49 ;
if ( ! F_14 ( V_4 , V_38 ) ||
! F_17 ( V_4 , V_38 , 0 ) ) {
F_19 ( V_38 , - V_53 ) ;
V_38 -> V_54 &= ~ V_55 ;
}
}
static void
F_22 (
struct V_37 * V_38 )
{
struct V_3 * V_4 = V_38 -> V_48 -> V_49 ;
if ( ! F_17 ( V_4 , V_38 , V_13 ) ) {
F_19 ( V_38 , - V_51 ) ;
F_20 ( V_38 ) ;
return;
}
}
