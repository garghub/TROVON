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
V_22 | V_23 ) )
return - V_13 ;
}
V_10 = F_1 ( V_6 [ V_24 ] ) ;
if ( V_10 < 0 )
return V_10 ;
V_10 = F_1 ( V_6 [ V_25 ] ) ;
if ( V_10 < 0 )
return V_10 ;
return 0 ;
}
static int F_8 ( struct V_26 * V_27 ,
struct V_1 * V_5 [] , struct V_1 * V_6 [] )
{
struct V_7 * V_8 ;
struct V_28 * V_29 ;
struct V_1 * V_2 ;
int V_30 ;
if ( V_6 [ V_18 ] ) {
V_8 = F_6 ( V_6 [ V_18 ] ) ;
F_9 ( V_27 , V_8 -> V_8 , V_8 -> V_19 ) ;
}
if ( V_6 [ V_24 ] ) {
F_10 (attr, data[IFLA_VLAN_INGRESS_QOS], rem) {
V_29 = F_6 ( V_2 ) ;
F_11 ( V_27 , V_29 -> V_31 , V_29 -> V_32 ) ;
}
}
if ( V_6 [ V_25 ] ) {
F_10 (attr, data[IFLA_VLAN_EGRESS_QOS], rem) {
V_29 = F_6 ( V_2 ) ;
F_12 ( V_27 , V_29 -> V_32 , V_29 -> V_31 ) ;
}
}
return 0 ;
}
static int F_13 ( struct V_33 * V_34 , struct V_26 * V_27 ,
struct V_1 * V_5 [] , struct V_1 * V_6 [] )
{
struct V_35 * V_36 = V_35 ( V_27 ) ;
struct V_26 * V_37 ;
int V_10 ;
if ( ! V_6 [ V_15 ] )
return - V_13 ;
if ( ! V_5 [ V_38 ] )
return - V_13 ;
V_37 = F_14 ( V_34 , F_15 ( V_5 [ V_38 ] ) ) ;
if ( ! V_37 )
return - V_39 ;
V_36 -> V_40 = F_7 ( V_6 [ V_15 ] ) ;
V_36 -> V_37 = V_37 ;
V_36 -> V_8 = V_20 ;
V_10 = F_16 ( V_37 , V_36 -> V_40 ) ;
if ( V_10 < 0 )
return V_10 ;
if ( ! V_5 [ V_41 ] )
V_27 -> V_42 = V_37 -> V_42 ;
else if ( V_27 -> V_42 > V_37 -> V_42 )
return - V_13 ;
V_10 = F_8 ( V_27 , V_5 , V_6 ) ;
if ( V_10 < 0 )
return V_10 ;
return F_17 ( V_27 ) ;
}
static inline T_2 F_18 ( unsigned int V_43 )
{
if ( V_43 == 0 )
return 0 ;
return F_19 ( sizeof( struct V_1 ) ) +
F_19 ( sizeof( struct V_28 ) ) * V_43 ;
}
static T_2 F_20 ( const struct V_26 * V_27 )
{
struct V_35 * V_36 = V_35 ( V_27 ) ;
return F_19 ( 2 ) +
sizeof( struct V_7 ) +
F_18 ( V_36 -> V_44 ) +
F_18 ( V_36 -> V_45 ) ;
}
static int F_21 ( struct V_46 * V_47 , const struct V_26 * V_27 )
{
struct V_35 * V_36 = V_35 ( V_27 ) ;
struct V_48 * V_49 ;
struct V_7 V_50 ;
struct V_28 V_29 ;
struct V_1 * V_51 ;
unsigned int V_52 ;
if ( F_22 ( V_47 , V_15 , V_35 ( V_27 ) -> V_40 ) )
goto V_53;
if ( V_36 -> V_8 ) {
V_50 . V_8 = V_36 -> V_8 ;
V_50 . V_19 = ~ 0 ;
if ( F_23 ( V_47 , V_18 , sizeof( V_50 ) , & V_50 ) )
goto V_53;
}
if ( V_36 -> V_44 ) {
V_51 = F_24 ( V_47 , V_24 ) ;
if ( V_51 == NULL )
goto V_53;
for ( V_52 = 0 ; V_52 < F_25 ( V_36 -> V_54 ) ; V_52 ++ ) {
if ( ! V_36 -> V_54 [ V_52 ] )
continue;
V_29 . V_32 = V_52 ;
V_29 . V_31 = V_36 -> V_54 [ V_52 ] ;
if ( F_23 ( V_47 , V_55 ,
sizeof( V_29 ) , & V_29 ) )
goto V_53;
}
F_26 ( V_47 , V_51 ) ;
}
if ( V_36 -> V_45 ) {
V_51 = F_24 ( V_47 , V_25 ) ;
if ( V_51 == NULL )
goto V_53;
for ( V_52 = 0 ; V_52 < F_25 ( V_36 -> V_56 ) ; V_52 ++ ) {
for ( V_49 = V_36 -> V_56 [ V_52 ] ; V_49 ;
V_49 = V_49 -> V_57 ) {
if ( ! V_49 -> V_58 )
continue;
V_29 . V_32 = V_49 -> V_59 ;
V_29 . V_31 = ( V_49 -> V_58 >> 13 ) & 0x7 ;
if ( F_23 ( V_47 , V_55 ,
sizeof( V_29 ) , & V_29 ) )
goto V_53;
}
}
F_26 ( V_47 , V_51 ) ;
}
return 0 ;
V_53:
return - V_60 ;
}
int T_3 F_27 ( void )
{
return F_28 ( & V_61 ) ;
}
void T_4 F_29 ( void )
{
F_30 ( & V_61 ) ;
}
