static void F_1 ( struct V_1 * V_2 ,
const T_1 * V_3 , int V_4 )
{
int V_5 ;
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_9 * V_10 = V_7 -> V_8 ;
for ( V_5 = 0 ; V_5 < V_4 ; V_5 ++ ) {
F_2 ( V_10 -> V_11 , V_12 |
V_13 |
( V_3 [ V_5 ] << V_14 ) ) ;
}
}
static void F_3 ( struct V_1 * V_2 , T_1 * V_3 , int V_4 )
{
int V_5 ;
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_9 * V_10 = V_7 -> V_8 ;
T_2 V_15 ;
V_15 = V_12 | V_16 ;
F_2 ( V_10 -> V_11 , V_15 ) ;
for ( V_5 = 0 ; V_5 < V_4 ; V_5 ++ ) {
V_3 [ V_5 ] = ( F_4 ( V_10 -> V_11 ) >>
V_14 ) & 0xff ;
}
}
static T_1 F_5 ( struct V_1 * V_2 )
{
T_1 V_17 ;
F_3 ( V_2 , & V_17 , sizeof( V_17 ) ) ;
return V_17 ;
}
static T_3 F_6 ( struct V_1 * V_2 )
{
T_3 V_18 ;
F_3 ( V_2 , ( T_1 * ) & V_18 , sizeof( V_18 ) ) ;
return V_18 ;
}
static int F_7 ( struct V_1 * V_2 , const T_4 * V_3 ,
int V_4 )
{
int V_5 ;
for ( V_5 = 0 ; V_5 < V_4 ; V_5 ++ ) {
if ( V_3 [ V_5 ] != F_5 ( V_2 ) )
return - V_19 ;
}
return 0 ;
}
static void F_8 ( struct V_1 * V_2 , int V_20 ,
unsigned int V_21 )
{
struct V_6 * V_6 = V_2 -> V_8 ;
struct V_9 * V_10 = V_6 -> V_8 ;
T_2 V_15 ;
if ( V_20 == V_22 )
return;
if ( V_21 & V_23 )
V_15 = V_24 ;
else
V_15 = V_25 ;
if ( V_21 & V_26 )
V_15 |= V_12 ;
V_15 |= ( V_20 & 0xff ) << V_14 ;
F_2 ( V_10 -> V_11 , V_15 ) ;
}
static int F_9 ( struct V_1 * V_2 )
{
struct V_6 * V_6 = V_2 -> V_8 ;
struct V_9 * V_10 = V_6 -> V_8 ;
if ( F_4 ( V_10 -> V_11 ) & V_27 )
return 0 ;
return 1 ;
}
static int T_5 F_10 ( struct V_28 * V_29 )
{
struct V_9 * V_10 ;
struct V_1 * V_2 ;
struct V_6 * V_6 ;
int V_30 ;
struct V_31 * V_32 = NULL ;
int V_33 = 0 ;
V_10 = F_11 ( sizeof( struct V_9 ) , V_34 ) ;
if ( ! V_10 ) {
F_12 ( V_35
L_1 ) ;
return - V_36 ;
}
V_10 -> V_11 = F_13 ( V_29 -> V_37 . V_38 , 0 ) ;
if ( V_10 -> V_11 == NULL ) {
F_12 ( V_35 L_2 ) ;
F_14 ( V_10 ) ;
return - V_39 ;
}
V_2 = & V_10 -> V_2 ;
V_6 = & V_10 -> V_6 ;
V_10 -> V_37 = & V_29 -> V_37 ;
V_6 -> V_8 = V_10 ;
V_2 -> V_8 = V_6 ;
V_2 -> V_40 = L_3 ;
V_2 -> V_41 = V_42 ;
V_2 -> V_37 . V_43 = & V_29 -> V_37 ;
V_6 -> V_44 = ( void * ) 0xdeadbeef ;
V_6 -> V_45 = ( void * ) 0xdeadbeef ;
V_6 -> V_46 = F_8 ;
V_6 -> V_47 = F_5 ;
V_6 -> V_48 = F_6 ;
V_6 -> V_49 = F_1 ;
V_6 -> V_50 = F_3 ;
V_6 -> V_51 = F_7 ;
V_6 -> V_52 = F_9 ;
V_6 -> V_53 . V_54 = V_55 ;
V_6 -> V_56 = 20 ;
F_15 ( & V_29 -> V_37 , V_10 ) ;
if ( F_16 ( V_2 , 1 , NULL ) ) {
V_30 = - V_57 ;
goto V_58;
}
if ( F_17 ( V_2 ) ) {
V_30 = - V_57 ;
goto V_58;
}
#ifdef F_18
V_33 = F_19 ( V_2 , V_59 ,
& V_32 , 0 ) ;
if ( V_33 < 0 ) {
V_30 = V_33 ;
goto V_60;
}
#endif
if ( V_33 == 0 ) {
V_33 = F_20 ( & V_29 -> V_37 ,
V_29 -> V_37 . V_38 ,
& V_32 ) ;
if ( V_33 < 0 ) {
V_30 = V_33 ;
goto V_60;
}
}
V_30 = F_21 ( V_2 , V_32 , V_33 ) ;
if ( ! V_30 )
return V_30 ;
V_60:
F_22 ( V_2 ) ;
V_58:
F_15 ( & V_29 -> V_37 , NULL ) ;
F_23 ( V_10 -> V_11 ) ;
F_14 ( V_10 ) ;
return V_30 ;
}
static int T_6 F_24 ( struct V_28 * V_29 )
{
struct V_9 * V_10 = F_25 ( & V_29 -> V_37 ) ;
struct V_1 * V_2 = & V_10 -> V_2 ;
F_22 ( V_2 ) ;
F_15 ( & V_29 -> V_37 , NULL ) ;
F_23 ( V_10 -> V_11 ) ;
F_14 ( V_10 ) ;
return 0 ;
}
static int T_7 F_26 ( void )
{
return F_27 ( & V_61 ) ;
}
static void T_8 F_28 ( void )
{
F_29 ( & V_61 ) ;
}
