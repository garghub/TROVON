static inline int F_1 ( struct V_1 * V_2 )
{
if ( ! V_2 )
return 0 ;
return F_2 ( V_2 , V_3 , V_4 ,
NULL ) ;
}
static int F_3 ( struct V_1 * V_5 [] , struct V_1 * V_6 [] ,
struct V_7 * V_8 )
{
struct V_9 * V_10 ;
T_1 V_11 ;
int V_12 ;
if ( V_5 [ V_13 ] ) {
if ( F_4 ( V_5 [ V_13 ] ) != V_14 )
return - V_15 ;
if ( ! F_5 ( F_6 ( V_5 [ V_13 ] ) ) )
return - V_16 ;
}
if ( ! V_6 )
return - V_15 ;
if ( V_6 [ V_17 ] ) {
switch ( F_7 ( V_6 [ V_17 ] ) ) {
case F_8 ( V_18 ) :
case F_8 ( V_19 ) :
break;
default:
return - V_20 ;
}
}
if ( V_6 [ V_21 ] ) {
V_11 = F_9 ( V_6 [ V_21 ] ) ;
if ( V_11 >= V_22 )
return - V_23 ;
}
if ( V_6 [ V_24 ] ) {
V_10 = F_6 ( V_6 [ V_24 ] ) ;
if ( ( V_10 -> V_10 & V_10 -> V_25 ) &
~ ( V_26 | V_27 |
V_28 | V_29 ) )
return - V_15 ;
}
V_12 = F_1 ( V_6 [ V_30 ] ) ;
if ( V_12 < 0 )
return V_12 ;
V_12 = F_1 ( V_6 [ V_31 ] ) ;
if ( V_12 < 0 )
return V_12 ;
return 0 ;
}
static int F_10 ( struct V_32 * V_33 , struct V_1 * V_5 [] ,
struct V_1 * V_6 [] ,
struct V_7 * V_8 )
{
struct V_9 * V_10 ;
struct V_34 * V_35 ;
struct V_1 * V_2 ;
int V_36 ;
if ( V_6 [ V_24 ] ) {
V_10 = F_6 ( V_6 [ V_24 ] ) ;
F_11 ( V_33 , V_10 -> V_10 , V_10 -> V_25 ) ;
}
if ( V_6 [ V_30 ] ) {
F_12 (attr, data[IFLA_VLAN_INGRESS_QOS], rem) {
V_35 = F_6 ( V_2 ) ;
F_13 ( V_33 , V_35 -> V_37 , V_35 -> V_38 ) ;
}
}
if ( V_6 [ V_31 ] ) {
F_12 (attr, data[IFLA_VLAN_EGRESS_QOS], rem) {
V_35 = F_6 ( V_2 ) ;
F_14 ( V_33 , V_35 -> V_38 , V_35 -> V_37 ) ;
}
}
return 0 ;
}
static int F_15 ( struct V_39 * V_40 , struct V_32 * V_33 ,
struct V_1 * V_5 [] , struct V_1 * V_6 [] ,
struct V_7 * V_8 )
{
struct V_41 * V_42 = V_41 ( V_33 ) ;
struct V_32 * V_43 ;
unsigned int V_44 ;
T_2 V_45 ;
int V_12 ;
if ( ! V_6 [ V_21 ] )
return - V_15 ;
if ( ! V_5 [ V_46 ] )
return - V_15 ;
V_43 = F_16 ( V_40 , F_17 ( V_5 [ V_46 ] ) ) ;
if ( ! V_43 )
return - V_47 ;
if ( V_6 [ V_17 ] )
V_45 = F_7 ( V_6 [ V_17 ] ) ;
else
V_45 = F_8 ( V_18 ) ;
V_42 -> V_48 = V_45 ;
V_42 -> V_49 = F_9 ( V_6 [ V_21 ] ) ;
V_42 -> V_43 = V_43 ;
V_42 -> V_10 = V_26 ;
V_12 = F_18 ( V_43 , V_42 -> V_48 , V_42 -> V_49 ) ;
if ( V_12 < 0 )
return V_12 ;
V_44 = F_19 ( V_43 ) ? V_43 -> V_50 - V_51 :
V_43 -> V_50 ;
if ( ! V_5 [ V_52 ] )
V_33 -> V_50 = V_44 ;
else if ( V_33 -> V_50 > V_44 )
return - V_15 ;
V_12 = F_10 ( V_33 , V_5 , V_6 , V_8 ) ;
if ( V_12 < 0 )
return V_12 ;
return F_20 ( V_33 ) ;
}
static inline T_3 F_21 ( unsigned int V_53 )
{
if ( V_53 == 0 )
return 0 ;
return F_22 ( sizeof( struct V_1 ) ) +
F_22 ( sizeof( struct V_34 ) ) * V_53 ;
}
static T_3 F_23 ( const struct V_32 * V_33 )
{
struct V_41 * V_42 = V_41 ( V_33 ) ;
return F_22 ( 2 ) +
F_22 ( 2 ) +
F_22 ( sizeof( struct V_9 ) ) +
F_21 ( V_42 -> V_54 ) +
F_21 ( V_42 -> V_55 ) ;
}
static int F_24 ( struct V_56 * V_57 , const struct V_32 * V_33 )
{
struct V_41 * V_42 = V_41 ( V_33 ) ;
struct V_58 * V_59 ;
struct V_9 V_60 ;
struct V_34 V_35 ;
struct V_1 * V_61 ;
unsigned int V_62 ;
if ( F_25 ( V_57 , V_17 , V_42 -> V_48 ) ||
F_26 ( V_57 , V_21 , V_42 -> V_49 ) )
goto V_63;
if ( V_42 -> V_10 ) {
V_60 . V_10 = V_42 -> V_10 ;
V_60 . V_25 = ~ 0 ;
if ( F_27 ( V_57 , V_24 , sizeof( V_60 ) , & V_60 ) )
goto V_63;
}
if ( V_42 -> V_54 ) {
V_61 = F_28 ( V_57 , V_30 ) ;
if ( V_61 == NULL )
goto V_63;
for ( V_62 = 0 ; V_62 < F_29 ( V_42 -> V_64 ) ; V_62 ++ ) {
if ( ! V_42 -> V_64 [ V_62 ] )
continue;
V_35 . V_38 = V_62 ;
V_35 . V_37 = V_42 -> V_64 [ V_62 ] ;
if ( F_27 ( V_57 , V_65 ,
sizeof( V_35 ) , & V_35 ) )
goto V_63;
}
F_30 ( V_57 , V_61 ) ;
}
if ( V_42 -> V_55 ) {
V_61 = F_28 ( V_57 , V_31 ) ;
if ( V_61 == NULL )
goto V_63;
for ( V_62 = 0 ; V_62 < F_29 ( V_42 -> V_66 ) ; V_62 ++ ) {
for ( V_59 = V_42 -> V_66 [ V_62 ] ; V_59 ;
V_59 = V_59 -> V_67 ) {
if ( ! V_59 -> V_68 )
continue;
V_35 . V_38 = V_59 -> V_69 ;
V_35 . V_37 = ( V_59 -> V_68 >> 13 ) & 0x7 ;
if ( F_27 ( V_57 , V_65 ,
sizeof( V_35 ) , & V_35 ) )
goto V_63;
}
}
F_30 ( V_57 , V_61 ) ;
}
return 0 ;
V_63:
return - V_70 ;
}
static struct V_39 * F_31 ( const struct V_32 * V_33 )
{
struct V_32 * V_43 = V_41 ( V_33 ) -> V_43 ;
return F_32 ( V_43 ) ;
}
int T_4 F_33 ( void )
{
return F_34 ( & V_71 ) ;
}
void T_5 F_35 ( void )
{
F_36 ( & V_71 ) ;
}
