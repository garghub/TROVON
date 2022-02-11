static inline T_1 F_1 ( T_1 V_1 )
{
return V_1 | ( ( ~ V_1 & 0x0f ) << 4 ) ;
}
static inline int F_2 ( struct V_2 * V_3 , T_1 V_4 )
{
if ( V_3 -> V_5 != V_4 ) {
if ( F_3 ( V_3 -> V_6 ,
V_7 ,
V_4 ) < 0 )
return - 1 ;
V_3 -> V_5 = V_4 ;
}
return 0 ;
}
static inline int F_4 ( struct V_2 * V_3 , T_1 V_8 )
{
if ( F_5 ( V_3 -> V_6 , V_8 ) < 0 )
return - 1 ;
V_3 -> V_5 = V_9 ;
return 0 ;
}
static inline int F_6 ( struct V_2 * V_3 ,
T_1 V_8 , T_1 V_10 )
{
if ( F_3 ( V_3 -> V_6 , V_8 , V_10 ) < 0 )
return - 1 ;
V_3 -> V_5 = ( V_8 != V_11 ) ?
V_9 : V_12 ;
return 0 ;
}
static int F_7 ( struct V_2 * V_3 )
{
int V_13 = - 1 ;
int V_14 = 0 ;
if ( ! F_2 ( V_3 , V_9 ) ) {
do {
V_13 = F_8 ( V_3 -> V_6 ) ;
} while ( ( V_13 >= 0 ) && ( V_13 & V_15 ) &&
( ++ V_14 < V_16 ) );
}
if ( V_14 >= V_16 )
F_9 ( L_1 ,
V_17 , V_3 -> V_18 ) ;
return V_13 ;
}
static int F_10 ( struct V_2 * V_3 , T_1 V_18 )
{
if ( F_3 ( V_3 -> V_6 , V_19 ,
V_20 [ V_18 ] ) < 0 )
return - 1 ;
V_3 -> V_5 = V_21 ;
V_3 -> V_18 = - 1 ;
if ( F_8 ( V_3 -> V_6 ) == V_22 [ V_18 ] ) {
V_3 -> V_18 = V_18 ;
return 0 ;
}
return - 1 ;
}
static T_1 F_11 ( void * V_23 , T_1 V_24 )
{
struct V_25 * V_26 = V_23 ;
struct V_2 * V_3 = V_26 -> V_3 ;
int V_27 = - 1 ;
F_12 ( & V_3 -> V_28 ) ;
F_7 ( V_3 ) ;
if ( V_3 -> V_29 > 1 )
F_10 ( V_3 , V_26 -> V_18 ) ;
if ( ! F_6 ( V_3 , V_30 ,
V_24 ? 0xFF : 0 ) )
V_27 = F_7 ( V_3 ) ;
F_13 ( & V_3 -> V_28 ) ;
return ( V_27 & V_31 ) ? 1 : 0 ;
}
static T_1 F_14 ( void * V_23 , T_1 V_32 )
{
struct V_25 * V_26 = V_23 ;
struct V_2 * V_3 = V_26 -> V_3 ;
int V_27 = ( 3 << 5 ) ;
F_12 ( & V_3 -> V_28 ) ;
F_7 ( V_3 ) ;
if ( V_3 -> V_29 > 1 )
F_10 ( V_3 , V_26 -> V_18 ) ;
if ( ! F_6 ( V_3 , V_33 ,
V_32 ? 0xFF : 0 ) )
V_27 = F_7 ( V_3 ) ;
F_13 ( & V_3 -> V_28 ) ;
return ( V_27 >> 5 ) ;
}
static void F_15 ( void * V_23 , T_1 V_10 )
{
struct V_25 * V_26 = V_23 ;
struct V_2 * V_3 = V_26 -> V_3 ;
F_12 ( & V_3 -> V_28 ) ;
F_7 ( V_3 ) ;
if ( V_3 -> V_29 > 1 )
F_10 ( V_3 , V_26 -> V_18 ) ;
F_6 ( V_3 , V_34 , V_10 ) ;
F_13 ( & V_3 -> V_28 ) ;
}
static T_1 F_16 ( void * V_23 )
{
struct V_25 * V_26 = V_23 ;
struct V_2 * V_3 = V_26 -> V_3 ;
int V_35 ;
F_12 ( & V_3 -> V_28 ) ;
F_7 ( V_3 ) ;
if ( V_3 -> V_29 > 1 )
F_10 ( V_3 , V_26 -> V_18 ) ;
F_4 ( V_3 , V_36 ) ;
F_7 ( V_3 ) ;
F_2 ( V_3 , V_37 ) ;
V_35 = F_8 ( V_3 -> V_6 ) ;
F_13 ( & V_3 -> V_28 ) ;
return V_35 ;
}
static T_1 F_17 ( void * V_23 )
{
struct V_25 * V_26 = V_23 ;
struct V_2 * V_3 = V_26 -> V_3 ;
int V_38 ;
T_1 V_39 = 1 ;
F_12 ( & V_3 -> V_28 ) ;
F_7 ( V_3 ) ;
if ( V_3 -> V_29 > 1 )
F_10 ( V_3 , V_26 -> V_18 ) ;
V_38 = F_4 ( V_3 , V_40 ) ;
if ( V_38 >= 0 ) {
V_38 = F_7 ( V_3 ) ;
V_39 = ! ( V_38 & V_41 ) ;
if ( V_38 & V_42 )
F_6 ( V_3 , V_11 ,
F_1 ( 0x00 ) ) ;
}
F_13 ( & V_3 -> V_28 ) ;
return V_39 ;
}
static T_1 F_18 ( void * V_23 , int V_43 )
{
struct V_25 * V_26 = V_23 ;
struct V_2 * V_3 = V_26 -> V_3 ;
T_1 V_39 = 1 ;
if ( V_43 ) {
F_7 ( V_3 ) ;
V_39 = F_6 ( V_3 , V_11 ,
F_1 ( V_44 |
V_45 ) ) ;
F_7 ( V_3 ) ;
}
return V_39 ;
}
static int F_19 ( struct V_46 * V_6 ,
const struct V_47 * V_48 )
{
struct V_2 * V_23 ;
int V_38 = - V_49 ;
int V_50 ;
int V_51 ;
if ( ! F_20 ( V_6 -> V_52 ,
V_53 |
V_54 ) )
return - V_49 ;
if ( ! ( V_23 = F_21 ( sizeof( struct V_2 ) , V_55 ) ) ) {
V_38 = - V_56 ;
goto exit;
}
V_23 -> V_6 = V_6 ;
F_22 ( V_6 , V_23 ) ;
if ( F_4 ( V_23 , V_57 ) < 0 ) {
F_23 ( & V_6 -> V_58 , L_2 ) ;
goto V_59;
}
F_24 ( 525 ) ;
V_50 = F_8 ( V_6 ) ;
if ( V_50 != ( V_60 | V_42 ) ) {
F_23 ( & V_6 -> V_58 , L_3
L_4 , V_50 ) ;
goto V_59;
}
V_23 -> V_29 = 1 ;
if ( F_10 ( V_23 , 7 ) == 0 )
V_23 -> V_29 = 8 ;
F_6 ( V_23 , V_11 ,
F_1 ( 0x00 ) ) ;
F_25 ( & V_23 -> V_28 ) ;
for ( V_51 = 0 ; V_51 < V_23 -> V_29 ; V_51 ++ ) {
V_23 -> V_61 [ V_51 ] . V_3 = V_23 ;
V_23 -> V_61 [ V_51 ] . V_18 = V_51 ;
V_23 -> V_61 [ V_51 ] . V_62 . V_23 = & V_23 -> V_61 [ V_51 ] ;
V_23 -> V_61 [ V_51 ] . V_62 . V_63 = F_16 ;
V_23 -> V_61 [ V_51 ] . V_62 . V_64 = F_15 ;
V_23 -> V_61 [ V_51 ] . V_62 . V_65 = F_11 ;
V_23 -> V_61 [ V_51 ] . V_62 . V_66 = F_14 ;
V_23 -> V_61 [ V_51 ] . V_62 . V_67 = F_17 ;
V_23 -> V_61 [ V_51 ] . V_62 . V_68 = F_18 ;
V_38 = F_26 ( & V_23 -> V_61 [ V_51 ] . V_62 ) ;
if ( V_38 ) {
V_23 -> V_61 [ V_51 ] . V_3 = NULL ;
goto V_69;
}
}
return 0 ;
V_69:
for ( V_51 = 0 ; V_51 < V_23 -> V_29 ; V_51 ++ ) {
if ( V_23 -> V_61 [ V_51 ] . V_3 != NULL )
F_27 ( & V_23 -> V_61 [ V_51 ] . V_62 ) ;
}
V_59:
F_28 ( V_23 ) ;
exit:
return V_38 ;
}
static int F_29 ( struct V_46 * V_6 )
{
struct V_2 * V_23 = F_30 ( V_6 ) ;
int V_51 ;
for ( V_51 = 0 ; V_51 < V_23 -> V_29 ; V_51 ++ ) {
if ( V_23 -> V_61 [ V_51 ] . V_3 != NULL )
F_27 ( & V_23 -> V_61 [ V_51 ] . V_62 ) ;
}
F_28 ( V_23 ) ;
return 0 ;
}
