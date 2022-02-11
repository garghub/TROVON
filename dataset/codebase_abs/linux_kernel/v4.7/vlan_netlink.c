static inline int F_1 ( struct V_1 * V_2 )
{
if ( ! V_2 )
return 0 ;
return F_2 ( V_2 , V_3 , V_4 ) ;
}
static int F_3 ( struct V_1 * V_5 [] , struct V_1 * V_6 [] )
{
struct V_7 * V_8 ;
T_1 V_9 ;
int V_10 ;
if ( V_5 [ V_11 ] ) {
if ( F_4 ( V_5 [ V_11 ] ) != V_12 )
return - V_13 ;
if ( ! F_5 ( F_6 ( V_5 [ V_11 ] ) ) )
return - V_14 ;
}
if ( ! V_6 )
return - V_13 ;
if ( V_6 [ V_15 ] ) {
switch ( F_7 ( V_6 [ V_15 ] ) ) {
case F_8 ( V_16 ) :
case F_8 ( V_17 ) :
break;
default:
return - V_18 ;
}
}
if ( V_6 [ V_19 ] ) {
V_9 = F_9 ( V_6 [ V_19 ] ) ;
if ( V_9 >= V_20 )
return - V_21 ;
}
if ( V_6 [ V_22 ] ) {
V_8 = F_6 ( V_6 [ V_22 ] ) ;
if ( ( V_8 -> V_8 & V_8 -> V_23 ) &
~ ( V_24 | V_25 |
V_26 | V_27 ) )
return - V_13 ;
}
V_10 = F_1 ( V_6 [ V_28 ] ) ;
if ( V_10 < 0 )
return V_10 ;
V_10 = F_1 ( V_6 [ V_29 ] ) ;
if ( V_10 < 0 )
return V_10 ;
return 0 ;
}
static int F_10 ( struct V_30 * V_31 ,
struct V_1 * V_5 [] , struct V_1 * V_6 [] )
{
struct V_7 * V_8 ;
struct V_32 * V_33 ;
struct V_1 * V_2 ;
int V_34 ;
if ( V_6 [ V_22 ] ) {
V_8 = F_6 ( V_6 [ V_22 ] ) ;
F_11 ( V_31 , V_8 -> V_8 , V_8 -> V_23 ) ;
}
if ( V_6 [ V_28 ] ) {
F_12 (attr, data[IFLA_VLAN_INGRESS_QOS], rem) {
V_33 = F_6 ( V_2 ) ;
F_13 ( V_31 , V_33 -> V_35 , V_33 -> V_36 ) ;
}
}
if ( V_6 [ V_29 ] ) {
F_12 (attr, data[IFLA_VLAN_EGRESS_QOS], rem) {
V_33 = F_6 ( V_2 ) ;
F_14 ( V_31 , V_33 -> V_36 , V_33 -> V_35 ) ;
}
}
return 0 ;
}
static int F_15 ( struct V_37 * V_38 , struct V_30 * V_31 ,
struct V_1 * V_5 [] , struct V_1 * V_6 [] )
{
struct V_39 * V_40 = V_39 ( V_31 ) ;
struct V_30 * V_41 ;
unsigned int V_42 ;
T_2 V_43 ;
int V_10 ;
if ( ! V_6 [ V_19 ] )
return - V_13 ;
if ( ! V_5 [ V_44 ] )
return - V_13 ;
V_41 = F_16 ( V_38 , F_17 ( V_5 [ V_44 ] ) ) ;
if ( ! V_41 )
return - V_45 ;
if ( V_6 [ V_15 ] )
V_43 = F_7 ( V_6 [ V_15 ] ) ;
else
V_43 = F_8 ( V_16 ) ;
V_40 -> V_46 = V_43 ;
V_40 -> V_47 = F_9 ( V_6 [ V_19 ] ) ;
V_40 -> V_41 = V_41 ;
V_40 -> V_8 = V_24 ;
V_10 = F_18 ( V_41 , V_40 -> V_46 , V_40 -> V_47 ) ;
if ( V_10 < 0 )
return V_10 ;
V_42 = F_19 ( V_41 ) ? V_41 -> V_48 - V_49 :
V_41 -> V_48 ;
if ( ! V_5 [ V_50 ] )
V_31 -> V_48 = V_42 ;
else if ( V_31 -> V_48 > V_42 )
return - V_13 ;
V_10 = F_10 ( V_31 , V_5 , V_6 ) ;
if ( V_10 < 0 )
return V_10 ;
return F_20 ( V_31 ) ;
}
static inline T_3 F_21 ( unsigned int V_51 )
{
if ( V_51 == 0 )
return 0 ;
return F_22 ( sizeof( struct V_1 ) ) +
F_22 ( sizeof( struct V_32 ) ) * V_51 ;
}
static T_3 F_23 ( const struct V_30 * V_31 )
{
struct V_39 * V_40 = V_39 ( V_31 ) ;
return F_22 ( 2 ) +
F_22 ( 2 ) +
F_22 ( sizeof( struct V_7 ) ) +
F_21 ( V_40 -> V_52 ) +
F_21 ( V_40 -> V_53 ) ;
}
static int F_24 ( struct V_54 * V_55 , const struct V_30 * V_31 )
{
struct V_39 * V_40 = V_39 ( V_31 ) ;
struct V_56 * V_57 ;
struct V_7 V_58 ;
struct V_32 V_33 ;
struct V_1 * V_59 ;
unsigned int V_60 ;
if ( F_25 ( V_55 , V_15 , V_40 -> V_46 ) ||
F_26 ( V_55 , V_19 , V_40 -> V_47 ) )
goto V_61;
if ( V_40 -> V_8 ) {
V_58 . V_8 = V_40 -> V_8 ;
V_58 . V_23 = ~ 0 ;
if ( F_27 ( V_55 , V_22 , sizeof( V_58 ) , & V_58 ) )
goto V_61;
}
if ( V_40 -> V_52 ) {
V_59 = F_28 ( V_55 , V_28 ) ;
if ( V_59 == NULL )
goto V_61;
for ( V_60 = 0 ; V_60 < F_29 ( V_40 -> V_62 ) ; V_60 ++ ) {
if ( ! V_40 -> V_62 [ V_60 ] )
continue;
V_33 . V_36 = V_60 ;
V_33 . V_35 = V_40 -> V_62 [ V_60 ] ;
if ( F_27 ( V_55 , V_63 ,
sizeof( V_33 ) , & V_33 ) )
goto V_61;
}
F_30 ( V_55 , V_59 ) ;
}
if ( V_40 -> V_53 ) {
V_59 = F_28 ( V_55 , V_29 ) ;
if ( V_59 == NULL )
goto V_61;
for ( V_60 = 0 ; V_60 < F_29 ( V_40 -> V_64 ) ; V_60 ++ ) {
for ( V_57 = V_40 -> V_64 [ V_60 ] ; V_57 ;
V_57 = V_57 -> V_65 ) {
if ( ! V_57 -> V_66 )
continue;
V_33 . V_36 = V_57 -> V_67 ;
V_33 . V_35 = ( V_57 -> V_66 >> 13 ) & 0x7 ;
if ( F_27 ( V_55 , V_63 ,
sizeof( V_33 ) , & V_33 ) )
goto V_61;
}
}
F_30 ( V_55 , V_59 ) ;
}
return 0 ;
V_61:
return - V_68 ;
}
static struct V_37 * F_31 ( const struct V_30 * V_31 )
{
struct V_30 * V_41 = V_39 ( V_31 ) -> V_41 ;
return F_32 ( V_41 ) ;
}
int T_4 F_33 ( void )
{
return F_34 ( & V_69 ) ;
}
void T_5 F_35 ( void )
{
F_36 ( & V_69 ) ;
}
