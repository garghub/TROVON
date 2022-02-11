static int F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
T_1 V_4 ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
unsigned int V_7 = V_6 -> V_8 [ V_3 ] . V_7 ;
unsigned int V_9 = V_6 -> V_8 [ V_3 ] . V_9 ;
unsigned int V_10 ;
int V_11 ;
F_3 ( & V_6 -> V_12 ) ;
V_11 = F_4 ( V_2 , V_13 ) ;
if ( V_11 < 0 )
goto V_14;
V_4 = V_11 ;
V_10 = F_5 ( 1000 , V_15 [ V_9 ] ) ;
V_4 &= 0x001f ;
V_4 |= ( 1 << 15 ) | ( 1 << 8 ) ;
V_4 |= ( V_3 & 0x0007 ) << 12 ;
V_4 |= ( V_7 & 0x0007 ) << 9 ;
V_4 |= ( V_9 & 0x0007 ) << 5 ;
V_11 = F_6 ( V_2 , V_13 , V_4 ) ;
if ( V_11 < 0 )
goto V_14;
F_7 ( V_10 ) ;
V_11 = F_4 ( V_2 , V_13 ) ;
if ( V_11 < 0 )
goto V_14;
V_4 = V_11 ;
if ( ! ( V_4 & ( 1 << 15 ) ) ) {
V_11 = - V_16 ;
goto V_14;
}
V_11 = F_4 ( V_2 , V_17 ) ;
V_14:
F_8 ( & V_6 -> V_12 ) ;
return V_11 ;
}
static int F_9 ( struct V_1 * V_2 , unsigned int V_3 ,
T_2 V_18 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
unsigned int V_7 = V_6 -> V_8 [ V_3 ] . V_7 ;
int V_19 = V_20 [ V_7 ] ;
return F_10 ( V_18 * V_19 , 0x7ff0 ) ;
}
static T_3 F_11 ( struct V_21 * V_22 , struct V_23 * V_24 ,
char * V_25 )
{
struct V_26 * V_27 = F_12 ( V_24 ) ;
struct V_1 * V_2 = F_13 ( V_22 ) ;
int V_11 ;
int V_28 = V_27 -> V_28 ;
V_11 = F_1 ( V_2 , V_28 ) ;
if ( V_11 < 0 )
return V_11 ;
return sprintf ( V_25 , L_1 , F_9 ( V_2 , V_28 , V_11 ) ) ;
}
static int F_14 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_29 ;
F_15 ( V_6 -> V_30 ) ;
for ( V_29 = 0 ; V_29 < V_31 ; ++ V_29 )
F_16 ( & V_2 -> V_22 , & V_32 [ V_29 ] . V_33 ) ;
return 0 ;
}
static int F_17 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_34 * V_35 ;
if ( ! V_2 -> V_22 . V_36
|| ! F_18 ( V_2 -> V_22 . V_36 , NULL ) )
return - V_37 ;
F_19 (client->dev.of_node, node) {
const T_4 * V_38 ;
int V_39 ;
unsigned int V_3 ;
unsigned int V_7 = V_40 ;
unsigned int V_9 = V_41 ;
V_38 = F_20 ( V_35 , L_2 , & V_39 ) ;
if ( ! V_38 || V_39 != sizeof( int ) ) {
F_21 ( & V_2 -> V_22 , L_3 ,
V_35 -> V_42 ) ;
continue;
}
V_3 = F_22 ( V_38 ) ;
if ( V_3 > V_31 ) {
F_21 ( & V_2 -> V_22 ,
L_4 ,
V_3 , V_35 -> V_42 ) ;
continue;
}
V_38 = F_20 ( V_35 , L_5 , & V_39 ) ;
if ( V_38 && V_39 == sizeof( int ) ) {
V_7 = F_22 ( V_38 ) ;
if ( V_7 > 6 ) {
F_21 ( & V_2 -> V_22 ,
L_6 ,
V_35 -> V_42 ) ;
}
}
V_38 = F_20 ( V_35 , L_7 , & V_39 ) ;
if ( V_38 && V_39 == sizeof( int ) ) {
V_9 = F_22 ( V_38 ) ;
if ( V_9 > 7 ) {
F_21 ( & V_2 -> V_22 ,
L_8 ,
V_35 -> V_42 ) ;
}
}
V_6 -> V_8 [ V_3 ] . V_43 = true ;
V_6 -> V_8 [ V_3 ] . V_7 = V_7 ;
V_6 -> V_8 [ V_3 ] . V_9 = V_9 ;
}
return 0 ;
}
static void F_23 ( struct V_1 * V_2 )
{
unsigned int V_29 ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_44 * V_45 = F_24 ( & V_2 -> V_22 ) ;
if ( V_45 ) {
memcpy ( V_6 -> V_8 , V_45 -> V_8 ,
sizeof( V_6 -> V_8 ) ) ;
return;
}
#ifdef F_25
if ( ! F_17 ( V_2 ) )
return;
#endif
for ( V_29 = 0 ; V_29 < V_31 ; ++ V_29 ) {
V_6 -> V_8 [ V_29 ] . V_43 = true ;
V_6 -> V_8 [ V_29 ] . V_7 = V_40 ;
V_6 -> V_8 [ V_29 ] . V_9 = V_41 ;
}
}
static int F_26 ( struct V_1 * V_2 ,
const struct V_46 * V_47 )
{
struct V_5 * V_6 ;
int V_48 ;
unsigned int V_29 ;
V_6 = F_27 ( & V_2 -> V_22 , sizeof( struct V_5 ) ,
V_49 ) ;
if ( ! V_6 )
return - V_50 ;
F_28 ( V_2 , V_6 ) ;
F_29 ( & V_6 -> V_12 ) ;
F_23 ( V_2 ) ;
for ( V_29 = 0 ; V_29 < V_31 ; ++ V_29 ) {
if ( ! V_6 -> V_8 [ V_29 ] . V_43 )
continue;
V_48 = F_30 ( & V_2 -> V_22 , & V_32 [ V_29 ] . V_33 ) ;
if ( V_48 )
goto V_51;
}
V_6 -> V_30 = F_31 ( & V_2 -> V_22 ) ;
if ( F_32 ( V_6 -> V_30 ) ) {
V_48 = F_33 ( V_6 -> V_30 ) ;
goto V_51;
}
return 0 ;
V_51:
for ( V_29 = 0 ; V_29 < V_31 ; ++ V_29 )
F_16 ( & V_2 -> V_22 , & V_32 [ V_29 ] . V_33 ) ;
return V_48 ;
}
