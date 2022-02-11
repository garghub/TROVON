static inline int F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
if ( V_2 -> V_4 != V_3 ) {
if ( F_2 ( V_2 -> V_5 ,
V_6 ,
V_3 ) < 0 )
return - 1 ;
V_2 -> V_4 = V_3 ;
}
return 0 ;
}
static inline int F_3 ( struct V_1 * V_2 , T_1 V_7 )
{
if ( F_4 ( V_2 -> V_5 , V_7 ) < 0 )
return - 1 ;
V_2 -> V_4 = V_8 ;
return 0 ;
}
static inline int F_5 ( struct V_1 * V_2 ,
T_1 V_7 , T_1 V_9 )
{
if ( F_2 ( V_2 -> V_5 , V_7 , V_9 ) < 0 )
return - 1 ;
V_2 -> V_4 = ( V_7 != V_10 ) ?
V_8 : V_11 ;
return 0 ;
}
static int F_6 ( struct V_1 * V_2 )
{
int V_12 = - 1 ;
int V_13 = 0 ;
if ( ! F_1 ( V_2 , V_8 ) ) {
do {
V_12 = F_7 ( V_2 -> V_5 ) ;
} while ( ( V_12 >= 0 ) && ( V_12 & V_14 ) &&
( ++ V_13 < V_15 ) );
}
if ( V_13 >= V_15 )
F_8 ( V_16 L_1 ,
V_17 , V_2 -> V_18 ) ;
return V_12 ;
}
static int F_9 ( struct V_1 * V_2 , T_1 V_18 )
{
if ( F_2 ( V_2 -> V_5 , V_19 ,
V_20 [ V_18 ] ) < 0 )
return - 1 ;
V_2 -> V_4 = V_21 ;
V_2 -> V_18 = - 1 ;
if ( F_7 ( V_2 -> V_5 ) == V_22 [ V_18 ] ) {
V_2 -> V_18 = V_18 ;
return 0 ;
}
return - 1 ;
}
static T_1 F_10 ( void * V_23 , T_1 V_24 )
{
struct V_25 * V_26 = V_23 ;
struct V_1 * V_2 = V_26 -> V_2 ;
int V_27 = - 1 ;
F_11 ( & V_2 -> V_28 ) ;
F_6 ( V_2 ) ;
if ( V_2 -> V_29 > 1 )
F_9 ( V_2 , V_26 -> V_18 ) ;
if ( ! F_5 ( V_2 , V_30 ,
V_24 ? 0xFF : 0 ) )
V_27 = F_6 ( V_2 ) ;
F_12 ( & V_2 -> V_28 ) ;
return ( V_27 & V_31 ) ? 1 : 0 ;
}
static T_1 F_13 ( void * V_23 , T_1 V_32 )
{
struct V_25 * V_26 = V_23 ;
struct V_1 * V_2 = V_26 -> V_2 ;
int V_27 = ( 3 << 5 ) ;
F_11 ( & V_2 -> V_28 ) ;
F_6 ( V_2 ) ;
if ( V_2 -> V_29 > 1 )
F_9 ( V_2 , V_26 -> V_18 ) ;
if ( ! F_5 ( V_2 , V_33 ,
V_32 ? 0xFF : 0 ) )
V_27 = F_6 ( V_2 ) ;
F_12 ( & V_2 -> V_28 ) ;
return ( V_27 >> 5 ) ;
}
static void F_14 ( void * V_23 , T_1 V_9 )
{
struct V_25 * V_26 = V_23 ;
struct V_1 * V_2 = V_26 -> V_2 ;
F_11 ( & V_2 -> V_28 ) ;
F_6 ( V_2 ) ;
if ( V_2 -> V_29 > 1 )
F_9 ( V_2 , V_26 -> V_18 ) ;
F_5 ( V_2 , V_34 , V_9 ) ;
F_12 ( & V_2 -> V_28 ) ;
}
static T_1 F_15 ( void * V_23 )
{
struct V_25 * V_26 = V_23 ;
struct V_1 * V_2 = V_26 -> V_2 ;
int V_35 ;
F_11 ( & V_2 -> V_28 ) ;
F_6 ( V_2 ) ;
if ( V_2 -> V_29 > 1 )
F_9 ( V_2 , V_26 -> V_18 ) ;
F_3 ( V_2 , V_36 ) ;
F_6 ( V_2 ) ;
F_1 ( V_2 , V_37 ) ;
V_35 = F_7 ( V_2 -> V_5 ) ;
F_12 ( & V_2 -> V_28 ) ;
return V_35 ;
}
static T_1 F_16 ( void * V_23 )
{
struct V_25 * V_26 = V_23 ;
struct V_1 * V_2 = V_26 -> V_2 ;
int V_38 ;
T_1 V_39 = 1 ;
F_11 ( & V_2 -> V_28 ) ;
F_6 ( V_2 ) ;
if ( V_2 -> V_29 > 1 )
F_9 ( V_2 , V_26 -> V_18 ) ;
V_38 = F_3 ( V_2 , V_40 ) ;
if ( V_38 >= 0 ) {
V_38 = F_6 ( V_2 ) ;
V_39 = ! ( V_38 & V_41 ) ;
if ( V_38 & V_42 )
F_5 ( V_2 , V_10 ,
0xF0 ) ;
}
F_12 ( & V_2 -> V_28 ) ;
return V_39 ;
}
static int F_17 ( struct V_43 * V_5 ,
const struct V_44 * V_45 )
{
struct V_1 * V_23 ;
int V_38 = - V_46 ;
int V_47 ;
int V_48 ;
if ( ! F_18 ( V_5 -> V_49 ,
V_50 |
V_51 ) )
return - V_46 ;
if ( ! ( V_23 = F_19 ( sizeof( struct V_1 ) , V_52 ) ) ) {
V_38 = - V_53 ;
goto exit;
}
V_23 -> V_5 = V_5 ;
F_20 ( V_5 , V_23 ) ;
if ( F_3 ( V_23 , V_54 ) < 0 ) {
F_21 ( & V_5 -> V_55 , L_2 ) ;
goto V_56;
}
F_22 ( 525 ) ;
V_47 = F_7 ( V_5 ) ;
if ( V_47 != ( V_57 | V_42 ) ) {
F_21 ( & V_5 -> V_55 , L_3
L_4 , V_47 ) ;
goto V_56;
}
V_23 -> V_29 = 1 ;
if ( F_9 ( V_23 , 7 ) == 0 )
V_23 -> V_29 = 8 ;
F_5 ( V_23 , V_10 , 0xF0 ) ;
F_23 ( & V_23 -> V_28 ) ;
for ( V_48 = 0 ; V_48 < V_23 -> V_29 ; V_48 ++ ) {
V_23 -> V_58 [ V_48 ] . V_2 = V_23 ;
V_23 -> V_58 [ V_48 ] . V_18 = V_48 ;
V_23 -> V_58 [ V_48 ] . V_59 . V_23 = & V_23 -> V_58 [ V_48 ] ;
V_23 -> V_58 [ V_48 ] . V_59 . V_60 = F_15 ;
V_23 -> V_58 [ V_48 ] . V_59 . V_61 = F_14 ;
V_23 -> V_58 [ V_48 ] . V_59 . V_62 = F_10 ;
V_23 -> V_58 [ V_48 ] . V_59 . V_63 = F_13 ;
V_23 -> V_58 [ V_48 ] . V_59 . V_64 = F_16 ;
V_38 = F_24 ( & V_23 -> V_58 [ V_48 ] . V_59 ) ;
if ( V_38 ) {
V_23 -> V_58 [ V_48 ] . V_2 = NULL ;
goto V_65;
}
}
return 0 ;
V_65:
for ( V_48 = 0 ; V_48 < V_23 -> V_29 ; V_48 ++ ) {
if ( V_23 -> V_58 [ V_48 ] . V_2 != NULL )
F_25 ( & V_23 -> V_58 [ V_48 ] . V_59 ) ;
}
V_56:
F_26 ( V_23 ) ;
exit:
return V_38 ;
}
static int F_27 ( struct V_43 * V_5 )
{
struct V_1 * V_23 = F_28 ( V_5 ) ;
int V_48 ;
for ( V_48 = 0 ; V_48 < V_23 -> V_29 ; V_48 ++ ) {
if ( V_23 -> V_58 [ V_48 ] . V_2 != NULL )
F_25 ( & V_23 -> V_58 [ V_48 ] . V_59 ) ;
}
F_26 ( V_23 ) ;
return 0 ;
}
static int T_2 F_29 ( void )
{
return F_30 ( & V_66 ) ;
}
static void T_3 F_31 ( void )
{
F_32 ( & V_66 ) ;
}
