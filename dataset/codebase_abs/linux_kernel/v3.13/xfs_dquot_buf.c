int
F_1 (
struct V_1 * V_2 ,
unsigned int V_3 )
{
unsigned int V_4 ;
ASSERT ( V_3 > 0 ) ;
V_4 = F_2 ( V_3 ) ;
F_3 ( V_4 , sizeof( V_5 ) ) ;
return V_4 ;
}
int
F_4 (
struct V_1 * V_2 ,
T_1 * V_6 ,
T_2 V_7 ,
T_3 type ,
T_3 V_8 ,
char * V_9 )
{
V_5 * V_10 = ( V_5 * ) V_6 ;
int V_11 = 0 ;
if ( V_6 -> V_12 != F_5 ( V_13 ) ) {
if ( V_8 & V_14 )
F_6 ( V_2 ,
L_1 ,
V_9 , V_7 , F_7 ( V_6 -> V_12 ) , V_13 ) ;
V_11 ++ ;
}
if ( V_6 -> V_15 != V_16 ) {
if ( V_8 & V_14 )
F_6 ( V_2 ,
L_2 ,
V_9 , V_7 , V_6 -> V_15 , V_16 ) ;
V_11 ++ ;
}
if ( V_6 -> V_17 != V_18 &&
V_6 -> V_17 != V_19 &&
V_6 -> V_17 != V_20 ) {
if ( V_8 & V_14 )
F_6 ( V_2 ,
L_3 ,
V_9 , V_7 , V_6 -> V_17 ) ;
V_11 ++ ;
}
if ( V_7 != - 1 && V_7 != F_8 ( V_6 -> V_21 ) ) {
if ( V_8 & V_14 )
F_6 ( V_2 ,
L_4
L_5 ,
V_9 , V_6 , V_7 , F_8 ( V_6 -> V_21 ) ) ;
V_11 ++ ;
}
if ( ! V_11 && V_6 -> V_21 ) {
if ( V_6 -> V_22 &&
F_9 ( V_6 -> V_23 ) >
F_9 ( V_6 -> V_22 ) ) {
if ( ! V_6 -> V_24 ) {
if ( V_8 & V_14 )
F_6 ( V_2 ,
L_6 ,
V_9 , ( int ) F_8 ( V_6 -> V_21 ) , V_6 ) ;
V_11 ++ ;
}
}
if ( V_6 -> V_25 &&
F_9 ( V_6 -> V_26 ) >
F_9 ( V_6 -> V_25 ) ) {
if ( ! V_6 -> V_27 ) {
if ( V_8 & V_14 )
F_6 ( V_2 ,
L_7 ,
V_9 , ( int ) F_8 ( V_6 -> V_21 ) , V_6 ) ;
V_11 ++ ;
}
}
if ( V_6 -> V_28 &&
F_9 ( V_6 -> V_29 ) >
F_9 ( V_6 -> V_28 ) ) {
if ( ! V_6 -> V_30 ) {
if ( V_8 & V_14 )
F_6 ( V_2 ,
L_8 ,
V_9 , ( int ) F_8 ( V_6 -> V_21 ) , V_6 ) ;
V_11 ++ ;
}
}
}
if ( ! V_11 || ! ( V_8 & V_31 ) )
return V_11 ;
if ( V_8 & V_14 )
F_10 ( V_2 , L_9 , V_7 ) ;
ASSERT ( V_7 != - 1 ) ;
ASSERT ( V_8 & V_31 ) ;
memset ( V_10 , 0 , sizeof( V_5 ) ) ;
V_10 -> V_32 . V_12 = F_5 ( V_13 ) ;
V_10 -> V_32 . V_15 = V_16 ;
V_10 -> V_32 . V_17 = type ;
V_10 -> V_32 . V_21 = F_11 ( V_7 ) ;
if ( F_12 ( & V_2 -> V_33 ) ) {
F_13 ( & V_10 -> V_34 , & V_2 -> V_33 . V_35 ) ;
F_14 ( ( char * ) V_10 , sizeof( struct V_36 ) ,
V_37 ) ;
}
return V_11 ;
}
STATIC bool
F_15 (
struct V_1 * V_2 ,
struct V_38 * V_39 )
{
struct V_36 * V_10 = (struct V_36 * ) V_39 -> V_40 ;
int V_4 ;
int V_41 ;
if ( ! F_12 ( & V_2 -> V_33 ) )
return true ;
if ( V_2 -> V_42 )
V_4 = V_2 -> V_42 -> V_43 ;
else
V_4 = F_1 ( V_2 ,
F_16 ( V_2 , V_39 -> V_44 ) ) ;
for ( V_41 = 0 ; V_41 < V_4 ; V_41 ++ , V_10 ++ ) {
if ( ! F_17 ( ( char * ) V_10 , sizeof( struct V_36 ) ,
V_37 ) )
return false ;
if ( ! F_18 ( & V_10 -> V_34 , & V_2 -> V_33 . V_35 ) )
return false ;
}
return true ;
}
STATIC bool
F_19 (
struct V_1 * V_2 ,
struct V_38 * V_39 )
{
struct V_36 * V_10 = (struct V_36 * ) V_39 -> V_40 ;
T_2 V_7 = 0 ;
int V_4 ;
int V_41 ;
if ( V_2 -> V_42 )
V_4 = V_2 -> V_42 -> V_43 ;
else
V_4 = F_1 ( V_2 , V_39 -> V_44 ) ;
for ( V_41 = 0 ; V_41 < V_4 ; V_41 ++ ) {
struct V_45 * V_6 ;
int error ;
V_6 = & V_10 [ V_41 ] . V_32 ;
if ( V_41 == 0 )
V_7 = F_8 ( V_6 -> V_21 ) ;
error = F_4 ( V_2 , V_6 , V_7 + V_41 , 0 , V_14 ,
L_10 ) ;
if ( error )
return false ;
}
return true ;
}
static void
F_20 (
struct V_38 * V_39 )
{
struct V_1 * V_2 = V_39 -> V_46 -> V_47 ;
if ( ! F_15 ( V_2 , V_39 ) || ! F_19 ( V_2 , V_39 ) ) {
F_21 ( V_48 , V_49 , V_2 , V_39 -> V_40 ) ;
F_22 ( V_39 , V_50 ) ;
}
}
static void
F_23 (
struct V_38 * V_39 )
{
struct V_1 * V_2 = V_39 -> V_46 -> V_47 ;
if ( ! F_19 ( V_2 , V_39 ) ) {
F_21 ( V_48 , V_49 , V_2 , V_39 -> V_40 ) ;
F_22 ( V_39 , V_50 ) ;
return;
}
}
