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
F_9 ( V_17 L_1 ,
V_18 , V_3 -> V_19 ) ;
return V_13 ;
}
static int F_10 ( struct V_2 * V_3 , T_1 V_19 )
{
if ( F_3 ( V_3 -> V_6 , V_20 ,
V_21 [ V_19 ] ) < 0 )
return - 1 ;
V_3 -> V_5 = V_22 ;
V_3 -> V_19 = - 1 ;
if ( F_8 ( V_3 -> V_6 ) == V_23 [ V_19 ] ) {
V_3 -> V_19 = V_19 ;
return 0 ;
}
return - 1 ;
}
static T_1 F_11 ( void * V_24 , T_1 V_25 )
{
struct V_26 * V_27 = V_24 ;
struct V_2 * V_3 = V_27 -> V_3 ;
int V_28 = - 1 ;
F_12 ( & V_3 -> V_29 ) ;
F_7 ( V_3 ) ;
if ( V_3 -> V_30 > 1 )
F_10 ( V_3 , V_27 -> V_19 ) ;
if ( ! F_6 ( V_3 , V_31 ,
V_25 ? 0xFF : 0 ) )
V_28 = F_7 ( V_3 ) ;
F_13 ( & V_3 -> V_29 ) ;
return ( V_28 & V_32 ) ? 1 : 0 ;
}
static T_1 F_14 ( void * V_24 , T_1 V_33 )
{
struct V_26 * V_27 = V_24 ;
struct V_2 * V_3 = V_27 -> V_3 ;
int V_28 = ( 3 << 5 ) ;
F_12 ( & V_3 -> V_29 ) ;
F_7 ( V_3 ) ;
if ( V_3 -> V_30 > 1 )
F_10 ( V_3 , V_27 -> V_19 ) ;
if ( ! F_6 ( V_3 , V_34 ,
V_33 ? 0xFF : 0 ) )
V_28 = F_7 ( V_3 ) ;
F_13 ( & V_3 -> V_29 ) ;
return ( V_28 >> 5 ) ;
}
static void F_15 ( void * V_24 , T_1 V_10 )
{
struct V_26 * V_27 = V_24 ;
struct V_2 * V_3 = V_27 -> V_3 ;
F_12 ( & V_3 -> V_29 ) ;
F_7 ( V_3 ) ;
if ( V_3 -> V_30 > 1 )
F_10 ( V_3 , V_27 -> V_19 ) ;
F_6 ( V_3 , V_35 , V_10 ) ;
F_13 ( & V_3 -> V_29 ) ;
}
static T_1 F_16 ( void * V_24 )
{
struct V_26 * V_27 = V_24 ;
struct V_2 * V_3 = V_27 -> V_3 ;
int V_36 ;
F_12 ( & V_3 -> V_29 ) ;
F_7 ( V_3 ) ;
if ( V_3 -> V_30 > 1 )
F_10 ( V_3 , V_27 -> V_19 ) ;
F_4 ( V_3 , V_37 ) ;
F_7 ( V_3 ) ;
F_2 ( V_3 , V_38 ) ;
V_36 = F_8 ( V_3 -> V_6 ) ;
F_13 ( & V_3 -> V_29 ) ;
return V_36 ;
}
static T_1 F_17 ( void * V_24 )
{
struct V_26 * V_27 = V_24 ;
struct V_2 * V_3 = V_27 -> V_3 ;
int V_39 ;
T_1 V_40 = 1 ;
F_12 ( & V_3 -> V_29 ) ;
F_7 ( V_3 ) ;
if ( V_3 -> V_30 > 1 )
F_10 ( V_3 , V_27 -> V_19 ) ;
V_39 = F_4 ( V_3 , V_41 ) ;
if ( V_39 >= 0 ) {
V_39 = F_7 ( V_3 ) ;
V_40 = ! ( V_39 & V_42 ) ;
if ( V_39 & V_43 )
F_6 ( V_3 , V_11 ,
F_1 ( 0x00 ) ) ;
}
F_13 ( & V_3 -> V_29 ) ;
return V_40 ;
}
static T_1 F_18 ( void * V_24 , int V_44 )
{
struct V_26 * V_27 = V_24 ;
struct V_2 * V_3 = V_27 -> V_3 ;
T_1 V_40 = 1 ;
if ( V_44 ) {
F_7 ( V_3 ) ;
V_40 = F_6 ( V_3 , V_11 ,
F_1 ( V_45 |
V_46 ) ) ;
F_7 ( V_3 ) ;
}
return V_40 ;
}
static int F_19 ( struct V_47 * V_6 ,
const struct V_48 * V_49 )
{
struct V_2 * V_24 ;
int V_39 = - V_50 ;
int V_51 ;
int V_52 ;
if ( ! F_20 ( V_6 -> V_53 ,
V_54 |
V_55 ) )
return - V_50 ;
if ( ! ( V_24 = F_21 ( sizeof( struct V_2 ) , V_56 ) ) ) {
V_39 = - V_57 ;
goto exit;
}
V_24 -> V_6 = V_6 ;
F_22 ( V_6 , V_24 ) ;
if ( F_4 ( V_24 , V_58 ) < 0 ) {
F_23 ( & V_6 -> V_59 , L_2 ) ;
goto V_60;
}
F_24 ( 525 ) ;
V_51 = F_8 ( V_6 ) ;
if ( V_51 != ( V_61 | V_43 ) ) {
F_23 ( & V_6 -> V_59 , L_3
L_4 , V_51 ) ;
goto V_60;
}
V_24 -> V_30 = 1 ;
if ( F_10 ( V_24 , 7 ) == 0 )
V_24 -> V_30 = 8 ;
F_6 ( V_24 , V_11 ,
F_1 ( 0x00 ) ) ;
F_25 ( & V_24 -> V_29 ) ;
for ( V_52 = 0 ; V_52 < V_24 -> V_30 ; V_52 ++ ) {
V_24 -> V_62 [ V_52 ] . V_3 = V_24 ;
V_24 -> V_62 [ V_52 ] . V_19 = V_52 ;
V_24 -> V_62 [ V_52 ] . V_63 . V_24 = & V_24 -> V_62 [ V_52 ] ;
V_24 -> V_62 [ V_52 ] . V_63 . V_64 = F_16 ;
V_24 -> V_62 [ V_52 ] . V_63 . V_65 = F_15 ;
V_24 -> V_62 [ V_52 ] . V_63 . V_66 = F_11 ;
V_24 -> V_62 [ V_52 ] . V_63 . V_67 = F_14 ;
V_24 -> V_62 [ V_52 ] . V_63 . V_68 = F_17 ;
V_24 -> V_62 [ V_52 ] . V_63 . V_69 = F_18 ;
V_39 = F_26 ( & V_24 -> V_62 [ V_52 ] . V_63 ) ;
if ( V_39 ) {
V_24 -> V_62 [ V_52 ] . V_3 = NULL ;
goto V_70;
}
}
return 0 ;
V_70:
for ( V_52 = 0 ; V_52 < V_24 -> V_30 ; V_52 ++ ) {
if ( V_24 -> V_62 [ V_52 ] . V_3 != NULL )
F_27 ( & V_24 -> V_62 [ V_52 ] . V_63 ) ;
}
V_60:
F_28 ( V_24 ) ;
exit:
return V_39 ;
}
static int F_29 ( struct V_47 * V_6 )
{
struct V_2 * V_24 = F_30 ( V_6 ) ;
int V_52 ;
for ( V_52 = 0 ; V_52 < V_24 -> V_30 ; V_52 ++ ) {
if ( V_24 -> V_62 [ V_52 ] . V_3 != NULL )
F_27 ( & V_24 -> V_62 [ V_52 ] . V_63 ) ;
}
F_28 ( V_24 ) ;
return 0 ;
}
