static T_1 F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
T_1 V_4 = F_2 ( V_2 , V_3 ) ;
return ( V_4 < 0 ) ? V_4 : F_3 ( V_4 ) ;
}
static T_1 F_4 ( struct V_1 * V_2 , unsigned int V_3 ,
T_2 V_5 )
{
return F_5 ( V_2 , V_3 , F_3 ( V_5 ) ) ;
}
static int F_6 ( struct V_1 * V_2 , unsigned int V_6 ,
int * V_7 )
{
T_2 V_8 ;
T_3 V_9 ;
struct V_10 * V_4 = F_7 ( V_2 ) ;
unsigned int V_11 = V_4 -> V_12 [ V_6 ] . V_11 ;
int V_13 ;
unsigned int V_14 = V_4 -> V_12 [ V_6 ] . V_14 ;
unsigned int V_15 ;
int V_16 ;
F_8 ( & V_4 -> V_17 ) ;
V_16 = F_1 ( V_2 , V_18 ) ;
if ( V_16 < 0 )
goto V_19;
V_8 = V_16 ;
V_13 = V_20 [ V_11 ] ;
V_15 = F_9 ( 1000 , V_21 [ V_14 ] ) ;
V_8 &= 0x001f ;
V_8 |= ( 1 << 15 ) | ( 1 << 8 ) ;
V_8 |= ( V_6 & 0x0007 ) << 12 ;
V_8 |= ( V_11 & 0x0007 ) << 9 ;
V_8 |= ( V_14 & 0x0007 ) << 5 ;
V_16 = F_4 ( V_2 , V_18 , V_8 ) ;
if ( V_16 < 0 )
goto V_19;
F_10 ( V_15 ) ;
V_16 = F_1 ( V_2 , V_18 ) ;
if ( V_16 < 0 )
goto V_19;
V_8 = V_16 ;
if ( ! ( V_8 & ( 1 << 15 ) ) ) {
V_16 = - V_22 ;
goto V_19;
}
V_16 = F_1 ( V_2 , V_23 ) ;
if ( V_16 < 0 )
goto V_19;
V_9 = V_16 ;
F_11 ( & V_4 -> V_17 ) ;
* V_7 = F_12 ( V_9 * V_13 , 0x7ff0 ) ;
return 0 ;
V_19:
F_11 ( & V_4 -> V_17 ) ;
return V_16 ;
}
static T_4 F_13 ( struct V_24 * V_25 , struct V_26 * V_27 ,
char * V_28 )
{
struct V_29 * V_30 = F_14 ( V_27 ) ;
struct V_1 * V_2 = F_15 ( V_25 ) ;
int V_31 ;
int V_16 ;
V_16 = F_6 ( V_2 , V_30 -> V_32 , & V_31 ) ;
return ( V_16 < 0 ) ? V_16 : sprintf ( V_28 , L_1 , V_31 ) ;
}
static int F_16 ( struct V_1 * V_2 )
{
struct V_10 * V_4 = F_7 ( V_2 ) ;
int V_33 ;
F_17 ( V_4 -> V_34 ) ;
for ( V_33 = 0 ; V_33 < V_35 ; ++ V_33 )
F_18 ( & V_2 -> V_25 , & V_36 [ V_33 ] . V_37 ) ;
F_19 ( V_4 ) ;
return 0 ;
}
static int F_20 ( struct V_1 * V_2 )
{
struct V_10 * V_4 = F_7 ( V_2 ) ;
struct V_38 * V_39 ;
if ( ! V_2 -> V_25 . V_40
|| ! F_21 ( V_2 -> V_25 . V_40 , NULL ) )
return - V_41 ;
F_22 (client->dev.of_node, node) {
const T_5 * V_42 ;
int V_43 ;
unsigned int V_6 ;
unsigned int V_11 = V_44 ;
unsigned int V_14 = V_45 ;
V_42 = F_23 ( V_39 , L_2 , & V_43 ) ;
if ( ! V_42 || V_43 != sizeof( int ) ) {
F_24 ( & V_2 -> V_25 , L_3 ,
V_39 -> V_46 ) ;
continue;
}
V_6 = F_25 ( V_42 ) ;
if ( V_6 > V_35 ) {
F_24 ( & V_2 -> V_25 ,
L_4 ,
V_6 , V_39 -> V_46 ) ;
continue;
}
V_42 = F_23 ( V_39 , L_5 , & V_43 ) ;
if ( V_42 && V_43 == sizeof( int ) ) {
V_11 = F_25 ( V_42 ) ;
if ( V_11 > 6 ) {
F_24 ( & V_2 -> V_25 ,
L_6 ,
V_39 -> V_46 ) ;
}
}
V_42 = F_23 ( V_39 , L_7 , & V_43 ) ;
if ( V_42 && V_43 == sizeof( int ) ) {
V_14 = F_25 ( V_42 ) ;
if ( V_14 > 7 ) {
F_24 ( & V_2 -> V_25 ,
L_8 ,
V_39 -> V_46 ) ;
}
}
V_4 -> V_12 [ V_6 ] . V_47 = true ;
V_4 -> V_12 [ V_6 ] . V_11 = V_11 ;
V_4 -> V_12 [ V_6 ] . V_14 = V_14 ;
}
return 0 ;
}
static void F_26 ( struct V_1 * V_2 )
{
unsigned int V_33 ;
struct V_10 * V_4 = F_7 ( V_2 ) ;
struct V_48 * V_49 = F_27 ( & V_2 -> V_25 ) ;
if ( V_49 ) {
memcpy ( V_4 -> V_12 , V_49 -> V_12 ,
sizeof( V_4 -> V_12 ) ) ;
return;
}
#ifdef F_28
if ( ! F_20 ( V_2 ) )
return;
#endif
for ( V_33 = 0 ; V_33 < V_35 ; ++ V_33 ) {
V_4 -> V_12 [ V_33 ] . V_47 = true ;
V_4 -> V_12 [ V_33 ] . V_11 = V_44 ;
V_4 -> V_12 [ V_33 ] . V_14 = V_45 ;
}
}
static int F_29 ( struct V_1 * V_2 ,
const struct V_50 * V_51 )
{
struct V_10 * V_4 ;
int V_52 ;
unsigned int V_33 ;
V_4 = F_30 ( sizeof( struct V_10 ) , V_53 ) ;
if ( ! V_4 ) {
V_52 = - V_54 ;
goto exit;
}
F_31 ( V_2 , V_4 ) ;
F_32 ( & V_4 -> V_17 ) ;
F_26 ( V_2 ) ;
for ( V_33 = 0 ; V_33 < V_35 ; ++ V_33 ) {
if ( ! V_4 -> V_12 [ V_33 ] . V_47 )
continue;
V_52 = F_33 ( & V_2 -> V_25 , & V_36 [ V_33 ] . V_37 ) ;
if ( V_52 )
goto V_55;
}
V_4 -> V_34 = F_34 ( & V_2 -> V_25 ) ;
if ( F_35 ( V_4 -> V_34 ) ) {
V_52 = F_36 ( V_4 -> V_34 ) ;
goto V_56;
}
return 0 ;
V_56:
for ( V_33 = 0 ; V_33 < V_35 ; ++ V_33 )
F_18 ( & V_2 -> V_25 , & V_36 [ V_33 ] . V_37 ) ;
V_55:
F_19 ( V_4 ) ;
exit:
return V_52 ;
}
static int T_6 F_37 ( void )
{
return F_38 ( & V_57 ) ;
}
static void T_7 F_39 ( void )
{
F_40 ( & V_57 ) ;
}
