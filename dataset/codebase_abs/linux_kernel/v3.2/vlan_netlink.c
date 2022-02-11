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
V_9 = F_7 ( V_6 [ V_15 ] ) ;
if ( V_9 >= V_16 )
return - V_17 ;
}
if ( V_6 [ V_18 ] ) {
V_8 = F_6 ( V_6 [ V_18 ] ) ;
if ( ( V_8 -> V_8 & V_8 -> V_19 ) &
~ ( V_20 | V_21 |
V_22 ) )
return - V_13 ;
}
V_10 = F_1 ( V_6 [ V_23 ] ) ;
if ( V_10 < 0 )
return V_10 ;
V_10 = F_1 ( V_6 [ V_24 ] ) ;
if ( V_10 < 0 )
return V_10 ;
return 0 ;
}
static int F_8 ( struct V_25 * V_26 ,
struct V_1 * V_5 [] , struct V_1 * V_6 [] )
{
struct V_7 * V_8 ;
struct V_27 * V_28 ;
struct V_1 * V_2 ;
int V_29 ;
if ( V_6 [ V_18 ] ) {
V_8 = F_6 ( V_6 [ V_18 ] ) ;
F_9 ( V_26 , V_8 -> V_8 , V_8 -> V_19 ) ;
}
if ( V_6 [ V_23 ] ) {
F_10 (attr, data[IFLA_VLAN_INGRESS_QOS], rem) {
V_28 = F_6 ( V_2 ) ;
F_11 ( V_26 , V_28 -> V_30 , V_28 -> V_31 ) ;
}
}
if ( V_6 [ V_24 ] ) {
F_10 (attr, data[IFLA_VLAN_EGRESS_QOS], rem) {
V_28 = F_6 ( V_2 ) ;
F_12 ( V_26 , V_28 -> V_31 , V_28 -> V_30 ) ;
}
}
return 0 ;
}
static int F_13 ( struct V_32 * V_33 , struct V_25 * V_26 ,
struct V_1 * V_5 [] , struct V_1 * V_6 [] )
{
struct V_34 * V_35 = V_34 ( V_26 ) ;
struct V_25 * V_36 ;
int V_10 ;
if ( ! V_6 [ V_15 ] )
return - V_13 ;
if ( ! V_5 [ V_37 ] )
return - V_13 ;
V_36 = F_14 ( V_33 , F_15 ( V_5 [ V_37 ] ) ) ;
if ( ! V_36 )
return - V_38 ;
V_35 -> V_39 = F_7 ( V_6 [ V_15 ] ) ;
V_35 -> V_36 = V_36 ;
V_35 -> V_8 = V_20 ;
V_10 = F_16 ( V_36 , V_35 -> V_39 ) ;
if ( V_10 < 0 )
return V_10 ;
if ( ! V_5 [ V_40 ] )
V_26 -> V_41 = V_36 -> V_41 ;
else if ( V_26 -> V_41 > V_36 -> V_41 )
return - V_13 ;
V_10 = F_8 ( V_26 , V_5 , V_6 ) ;
if ( V_10 < 0 )
return V_10 ;
return F_17 ( V_26 ) ;
}
static inline T_2 F_18 ( unsigned int V_42 )
{
if ( V_42 == 0 )
return 0 ;
return F_19 ( sizeof( struct V_1 ) ) +
F_19 ( sizeof( struct V_27 ) ) * V_42 ;
}
static T_2 F_20 ( const struct V_25 * V_26 )
{
struct V_34 * V_35 = V_34 ( V_26 ) ;
return F_19 ( 2 ) +
sizeof( struct V_7 ) +
F_18 ( V_35 -> V_43 ) +
F_18 ( V_35 -> V_44 ) ;
}
static int F_21 ( struct V_45 * V_46 , const struct V_25 * V_26 )
{
struct V_34 * V_35 = V_34 ( V_26 ) ;
struct V_47 * V_48 ;
struct V_7 V_49 ;
struct V_27 V_28 ;
struct V_1 * V_50 ;
unsigned int V_51 ;
F_22 ( V_46 , V_15 , V_34 ( V_26 ) -> V_39 ) ;
if ( V_35 -> V_8 ) {
V_49 . V_8 = V_35 -> V_8 ;
V_49 . V_19 = ~ 0 ;
F_23 ( V_46 , V_18 , sizeof( V_49 ) , & V_49 ) ;
}
if ( V_35 -> V_43 ) {
V_50 = F_24 ( V_46 , V_23 ) ;
if ( V_50 == NULL )
goto V_52;
for ( V_51 = 0 ; V_51 < F_25 ( V_35 -> V_53 ) ; V_51 ++ ) {
if ( ! V_35 -> V_53 [ V_51 ] )
continue;
V_28 . V_31 = V_51 ;
V_28 . V_30 = V_35 -> V_53 [ V_51 ] ;
F_23 ( V_46 , V_54 ,
sizeof( V_28 ) , & V_28 ) ;
}
F_26 ( V_46 , V_50 ) ;
}
if ( V_35 -> V_44 ) {
V_50 = F_24 ( V_46 , V_24 ) ;
if ( V_50 == NULL )
goto V_52;
for ( V_51 = 0 ; V_51 < F_25 ( V_35 -> V_55 ) ; V_51 ++ ) {
for ( V_48 = V_35 -> V_55 [ V_51 ] ; V_48 ;
V_48 = V_48 -> V_56 ) {
if ( ! V_48 -> V_57 )
continue;
V_28 . V_31 = V_48 -> V_58 ;
V_28 . V_30 = ( V_48 -> V_57 >> 13 ) & 0x7 ;
F_23 ( V_46 , V_54 ,
sizeof( V_28 ) , & V_28 ) ;
}
}
F_26 ( V_46 , V_50 ) ;
}
return 0 ;
V_52:
return - V_59 ;
}
int T_3 F_27 ( void )
{
return F_28 ( & V_60 ) ;
}
void T_4 F_29 ( void )
{
F_30 ( & V_60 ) ;
}
