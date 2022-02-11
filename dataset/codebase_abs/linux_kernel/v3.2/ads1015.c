static int F_1 ( struct V_1 * V_2 , unsigned int V_3 ,
int * V_4 )
{
T_1 V_5 ;
T_2 V_6 ;
struct V_7 * V_8 = F_2 ( V_2 ) ;
unsigned int V_9 = V_8 -> V_10 [ V_3 ] . V_9 ;
int V_11 ;
unsigned int V_12 = V_8 -> V_10 [ V_3 ] . V_12 ;
unsigned int V_13 ;
int V_14 ;
F_3 ( & V_8 -> V_15 ) ;
V_14 = F_4 ( V_2 , V_16 ) ;
if ( V_14 < 0 )
goto V_17;
V_5 = V_14 ;
V_11 = V_18 [ V_9 ] ;
V_13 = F_5 ( 1000 , V_19 [ V_12 ] ) ;
V_5 &= 0x001f ;
V_5 |= ( 1 << 15 ) | ( 1 << 8 ) ;
V_5 |= ( V_3 & 0x0007 ) << 12 ;
V_5 |= ( V_9 & 0x0007 ) << 9 ;
V_5 |= ( V_12 & 0x0007 ) << 5 ;
V_14 = F_6 ( V_2 , V_16 , V_5 ) ;
if ( V_14 < 0 )
goto V_17;
F_7 ( V_13 ) ;
V_14 = F_4 ( V_2 , V_16 ) ;
if ( V_14 < 0 )
goto V_17;
V_5 = V_14 ;
if ( ! ( V_5 & ( 1 << 15 ) ) ) {
V_14 = - V_20 ;
goto V_17;
}
V_14 = F_4 ( V_2 , V_21 ) ;
if ( V_14 < 0 )
goto V_17;
V_6 = V_14 ;
F_8 ( & V_8 -> V_15 ) ;
* V_4 = F_9 ( V_6 * V_11 , 0x7ff0 ) ;
return 0 ;
V_17:
F_8 ( & V_8 -> V_15 ) ;
return V_14 ;
}
static T_3 F_10 ( struct V_22 * V_23 , struct V_24 * V_25 ,
char * V_26 )
{
struct V_27 * V_28 = F_11 ( V_25 ) ;
struct V_1 * V_2 = F_12 ( V_23 ) ;
int V_29 ;
int V_14 ;
V_14 = F_1 ( V_2 , V_28 -> V_30 , & V_29 ) ;
return ( V_14 < 0 ) ? V_14 : sprintf ( V_26 , L_1 , V_29 ) ;
}
static int F_13 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
int V_31 ;
F_14 ( V_8 -> V_32 ) ;
for ( V_31 = 0 ; V_31 < V_33 ; ++ V_31 )
F_15 ( & V_2 -> V_23 , & V_34 [ V_31 ] . V_35 ) ;
F_16 ( V_8 ) ;
return 0 ;
}
static int F_17 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
struct V_36 * V_37 ;
if ( ! V_2 -> V_23 . V_38
|| ! F_18 ( V_2 -> V_23 . V_38 , NULL ) )
return - V_39 ;
F_19 (client->dev.of_node, node) {
const T_4 * V_40 ;
int V_41 ;
unsigned int V_3 ;
unsigned int V_9 = V_42 ;
unsigned int V_12 = V_43 ;
V_40 = F_20 ( V_37 , L_2 , & V_41 ) ;
if ( ! V_40 || V_41 != sizeof( int ) ) {
F_21 ( & V_2 -> V_23 , L_3 ,
V_37 -> V_44 ) ;
continue;
}
V_3 = F_22 ( V_40 ) ;
if ( V_3 > V_33 ) {
F_21 ( & V_2 -> V_23 ,
L_4 ,
V_3 , V_37 -> V_44 ) ;
continue;
}
V_40 = F_20 ( V_37 , L_5 , & V_41 ) ;
if ( V_40 && V_41 == sizeof( int ) ) {
V_9 = F_22 ( V_40 ) ;
if ( V_9 > 6 ) {
F_21 ( & V_2 -> V_23 ,
L_6 ,
V_37 -> V_44 ) ;
}
}
V_40 = F_20 ( V_37 , L_7 , & V_41 ) ;
if ( V_40 && V_41 == sizeof( int ) ) {
V_12 = F_22 ( V_40 ) ;
if ( V_12 > 7 ) {
F_21 ( & V_2 -> V_23 ,
L_8 ,
V_37 -> V_44 ) ;
}
}
V_8 -> V_10 [ V_3 ] . V_45 = true ;
V_8 -> V_10 [ V_3 ] . V_9 = V_9 ;
V_8 -> V_10 [ V_3 ] . V_12 = V_12 ;
}
return 0 ;
}
static void F_23 ( struct V_1 * V_2 )
{
unsigned int V_31 ;
struct V_7 * V_8 = F_2 ( V_2 ) ;
struct V_46 * V_47 = F_24 ( & V_2 -> V_23 ) ;
if ( V_47 ) {
memcpy ( V_8 -> V_10 , V_47 -> V_10 ,
sizeof( V_8 -> V_10 ) ) ;
return;
}
#ifdef F_25
if ( ! F_17 ( V_2 ) )
return;
#endif
for ( V_31 = 0 ; V_31 < V_33 ; ++ V_31 ) {
V_8 -> V_10 [ V_31 ] . V_45 = true ;
V_8 -> V_10 [ V_31 ] . V_9 = V_42 ;
V_8 -> V_10 [ V_31 ] . V_12 = V_43 ;
}
}
static int F_26 ( struct V_1 * V_2 ,
const struct V_48 * V_49 )
{
struct V_7 * V_8 ;
int V_50 ;
unsigned int V_31 ;
V_8 = F_27 ( sizeof( struct V_7 ) , V_51 ) ;
if ( ! V_8 ) {
V_50 = - V_52 ;
goto exit;
}
F_28 ( V_2 , V_8 ) ;
F_29 ( & V_8 -> V_15 ) ;
F_23 ( V_2 ) ;
for ( V_31 = 0 ; V_31 < V_33 ; ++ V_31 ) {
if ( ! V_8 -> V_10 [ V_31 ] . V_45 )
continue;
V_50 = F_30 ( & V_2 -> V_23 , & V_34 [ V_31 ] . V_35 ) ;
if ( V_50 )
goto V_53;
}
V_8 -> V_32 = F_31 ( & V_2 -> V_23 ) ;
if ( F_32 ( V_8 -> V_32 ) ) {
V_50 = F_33 ( V_8 -> V_32 ) ;
goto V_54;
}
return 0 ;
V_54:
for ( V_31 = 0 ; V_31 < V_33 ; ++ V_31 )
F_15 ( & V_2 -> V_23 , & V_34 [ V_31 ] . V_35 ) ;
V_53:
F_16 ( V_8 ) ;
exit:
return V_50 ;
}
static int T_5 F_34 ( void )
{
return F_35 ( & V_55 ) ;
}
static void T_6 F_36 ( void )
{
F_37 ( & V_55 ) ;
}
