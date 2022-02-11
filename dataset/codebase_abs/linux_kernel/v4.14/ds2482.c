static inline T_1 F_1 ( T_1 V_1 )
{
if ( V_2 )
V_1 |= V_3 ;
return V_1 | ( ( ~ V_1 & 0x0f ) << 4 ) ;
}
static inline int F_2 ( struct V_4 * V_5 , T_1 V_6 )
{
if ( V_5 -> V_7 != V_6 ) {
if ( F_3 ( V_5 -> V_8 ,
V_9 ,
V_6 ) < 0 )
return - 1 ;
V_5 -> V_7 = V_6 ;
}
return 0 ;
}
static inline int F_4 ( struct V_4 * V_5 , T_1 V_10 )
{
if ( F_5 ( V_5 -> V_8 , V_10 ) < 0 )
return - 1 ;
V_5 -> V_7 = V_11 ;
return 0 ;
}
static inline int F_6 ( struct V_4 * V_5 ,
T_1 V_10 , T_1 V_12 )
{
if ( F_3 ( V_5 -> V_8 , V_10 , V_12 ) < 0 )
return - 1 ;
V_5 -> V_7 = ( V_10 != V_13 ) ?
V_11 : V_14 ;
return 0 ;
}
static int F_7 ( struct V_4 * V_5 )
{
int V_15 = - 1 ;
int V_16 = 0 ;
if ( ! F_2 ( V_5 , V_11 ) ) {
do {
V_15 = F_8 ( V_5 -> V_8 ) ;
} while ( ( V_15 >= 0 ) && ( V_15 & V_17 ) &&
( ++ V_16 < V_18 ) );
}
if ( V_16 >= V_18 )
F_9 ( L_1 ,
V_19 , V_5 -> V_20 ) ;
return V_15 ;
}
static int F_10 ( struct V_4 * V_5 , T_1 V_20 )
{
if ( F_3 ( V_5 -> V_8 , V_21 ,
V_22 [ V_20 ] ) < 0 )
return - 1 ;
V_5 -> V_7 = V_23 ;
V_5 -> V_20 = - 1 ;
if ( F_8 ( V_5 -> V_8 ) == V_24 [ V_20 ] ) {
V_5 -> V_20 = V_20 ;
return 0 ;
}
return - 1 ;
}
static T_1 F_11 ( void * V_25 , T_1 V_26 )
{
struct V_27 * V_28 = V_25 ;
struct V_4 * V_5 = V_28 -> V_5 ;
int V_29 = - 1 ;
F_12 ( & V_5 -> V_30 ) ;
F_7 ( V_5 ) ;
if ( V_5 -> V_31 > 1 )
F_10 ( V_5 , V_28 -> V_20 ) ;
if ( ! F_6 ( V_5 , V_32 ,
V_26 ? 0xFF : 0 ) )
V_29 = F_7 ( V_5 ) ;
F_13 ( & V_5 -> V_30 ) ;
return ( V_29 & V_33 ) ? 1 : 0 ;
}
static T_1 F_14 ( void * V_25 , T_1 V_34 )
{
struct V_27 * V_28 = V_25 ;
struct V_4 * V_5 = V_28 -> V_5 ;
int V_29 = ( 3 << 5 ) ;
F_12 ( & V_5 -> V_30 ) ;
F_7 ( V_5 ) ;
if ( V_5 -> V_31 > 1 )
F_10 ( V_5 , V_28 -> V_20 ) ;
if ( ! F_6 ( V_5 , V_35 ,
V_34 ? 0xFF : 0 ) )
V_29 = F_7 ( V_5 ) ;
F_13 ( & V_5 -> V_30 ) ;
return ( V_29 >> 5 ) ;
}
static void F_15 ( void * V_25 , T_1 V_12 )
{
struct V_27 * V_28 = V_25 ;
struct V_4 * V_5 = V_28 -> V_5 ;
F_12 ( & V_5 -> V_30 ) ;
F_7 ( V_5 ) ;
if ( V_5 -> V_31 > 1 )
F_10 ( V_5 , V_28 -> V_20 ) ;
F_6 ( V_5 , V_36 , V_12 ) ;
F_13 ( & V_5 -> V_30 ) ;
}
static T_1 F_16 ( void * V_25 )
{
struct V_27 * V_28 = V_25 ;
struct V_4 * V_5 = V_28 -> V_5 ;
int V_37 ;
F_12 ( & V_5 -> V_30 ) ;
F_7 ( V_5 ) ;
if ( V_5 -> V_31 > 1 )
F_10 ( V_5 , V_28 -> V_20 ) ;
F_4 ( V_5 , V_38 ) ;
F_7 ( V_5 ) ;
F_2 ( V_5 , V_39 ) ;
V_37 = F_8 ( V_5 -> V_8 ) ;
F_13 ( & V_5 -> V_30 ) ;
return V_37 ;
}
static T_1 F_17 ( void * V_25 )
{
struct V_27 * V_28 = V_25 ;
struct V_4 * V_5 = V_28 -> V_5 ;
int V_40 ;
T_1 V_41 = 1 ;
F_12 ( & V_5 -> V_30 ) ;
F_7 ( V_5 ) ;
if ( V_5 -> V_31 > 1 )
F_10 ( V_5 , V_28 -> V_20 ) ;
V_40 = F_4 ( V_5 , V_42 ) ;
if ( V_40 >= 0 ) {
V_40 = F_7 ( V_5 ) ;
V_41 = ! ( V_40 & V_43 ) ;
if ( V_40 & V_44 )
F_6 ( V_5 , V_13 ,
F_1 ( V_45 ) ) ;
}
F_13 ( & V_5 -> V_30 ) ;
return V_41 ;
}
static T_1 F_18 ( void * V_25 , int V_46 )
{
struct V_27 * V_28 = V_25 ;
struct V_4 * V_5 = V_28 -> V_5 ;
T_1 V_41 = 1 ;
if ( V_46 ) {
F_7 ( V_5 ) ;
V_41 = F_6 ( V_5 , V_13 ,
F_1 ( V_45 | V_47 | V_3 ) ) ;
F_7 ( V_5 ) ;
}
return V_41 ;
}
static int F_19 ( struct V_48 * V_8 ,
const struct V_49 * V_50 )
{
struct V_4 * V_25 ;
int V_40 = - V_51 ;
int V_52 ;
int V_53 ;
if ( ! F_20 ( V_8 -> V_54 ,
V_55 |
V_56 ) )
return - V_51 ;
if ( ! ( V_25 = F_21 ( sizeof( struct V_4 ) , V_57 ) ) ) {
V_40 = - V_58 ;
goto exit;
}
V_25 -> V_8 = V_8 ;
F_22 ( V_8 , V_25 ) ;
if ( F_4 ( V_25 , V_59 ) < 0 ) {
F_23 ( & V_8 -> V_60 , L_2 ) ;
goto V_61;
}
F_24 ( 525 ) ;
V_52 = F_8 ( V_8 ) ;
if ( V_52 != ( V_62 | V_44 ) ) {
F_23 ( & V_8 -> V_60 , L_3
L_4 , V_52 ) ;
goto V_61;
}
V_25 -> V_31 = 1 ;
if ( F_10 ( V_25 , 7 ) == 0 )
V_25 -> V_31 = 8 ;
F_6 ( V_25 , V_13 ,
F_1 ( V_45 ) ) ;
F_25 ( & V_25 -> V_30 ) ;
for ( V_53 = 0 ; V_53 < V_25 -> V_31 ; V_53 ++ ) {
V_25 -> V_63 [ V_53 ] . V_5 = V_25 ;
V_25 -> V_63 [ V_53 ] . V_20 = V_53 ;
V_25 -> V_63 [ V_53 ] . V_64 . V_25 = & V_25 -> V_63 [ V_53 ] ;
V_25 -> V_63 [ V_53 ] . V_64 . V_65 = F_16 ;
V_25 -> V_63 [ V_53 ] . V_64 . V_66 = F_15 ;
V_25 -> V_63 [ V_53 ] . V_64 . V_67 = F_11 ;
V_25 -> V_63 [ V_53 ] . V_64 . V_68 = F_14 ;
V_25 -> V_63 [ V_53 ] . V_64 . V_69 = F_17 ;
V_25 -> V_63 [ V_53 ] . V_64 . V_70 = F_18 ;
V_40 = F_26 ( & V_25 -> V_63 [ V_53 ] . V_64 ) ;
if ( V_40 ) {
V_25 -> V_63 [ V_53 ] . V_5 = NULL ;
goto V_71;
}
}
return 0 ;
V_71:
for ( V_53 = 0 ; V_53 < V_25 -> V_31 ; V_53 ++ ) {
if ( V_25 -> V_63 [ V_53 ] . V_5 != NULL )
F_27 ( & V_25 -> V_63 [ V_53 ] . V_64 ) ;
}
V_61:
F_28 ( V_25 ) ;
exit:
return V_40 ;
}
static int F_29 ( struct V_48 * V_8 )
{
struct V_4 * V_25 = F_30 ( V_8 ) ;
int V_53 ;
for ( V_53 = 0 ; V_53 < V_25 -> V_31 ; V_53 ++ ) {
if ( V_25 -> V_63 [ V_53 ] . V_5 != NULL )
F_27 ( & V_25 -> V_63 [ V_53 ] . V_64 ) ;
}
F_28 ( V_25 ) ;
return 0 ;
}
