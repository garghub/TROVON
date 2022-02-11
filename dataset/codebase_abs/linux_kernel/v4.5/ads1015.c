static int F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
T_1 V_4 ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
unsigned int V_7 = V_6 -> V_8 [ V_3 ] . V_7 ;
unsigned int V_9 = V_6 -> V_8 [ V_3 ] . V_9 ;
unsigned int V_10 ;
const unsigned int * const V_11 = V_6 -> V_12 == V_13 ?
V_14 : V_15 ;
int V_16 ;
F_3 ( & V_6 -> V_17 ) ;
V_16 = F_4 ( V_2 , V_18 ) ;
if ( V_16 < 0 )
goto V_19;
V_4 = V_16 ;
V_10 = F_5 ( 1000 , V_11 [ V_9 ] ) ;
V_4 &= 0x001f ;
V_4 |= ( 1 << 15 ) | ( 1 << 8 ) ;
V_4 |= ( V_3 & 0x0007 ) << 12 ;
V_4 |= ( V_7 & 0x0007 ) << 9 ;
V_4 |= ( V_9 & 0x0007 ) << 5 ;
V_16 = F_6 ( V_2 , V_18 , V_4 ) ;
if ( V_16 < 0 )
goto V_19;
F_7 ( V_10 ) ;
V_16 = F_4 ( V_2 , V_18 ) ;
if ( V_16 < 0 )
goto V_19;
V_4 = V_16 ;
if ( ! ( V_4 & ( 1 << 15 ) ) ) {
V_16 = - V_20 ;
goto V_19;
}
V_16 = F_4 ( V_2 , V_21 ) ;
V_19:
F_8 ( & V_6 -> V_17 ) ;
return V_16 ;
}
static int F_9 ( struct V_1 * V_2 , unsigned int V_3 ,
T_2 V_22 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
unsigned int V_7 = V_6 -> V_8 [ V_3 ] . V_7 ;
int V_23 = V_24 [ V_7 ] ;
const int V_25 = V_6 -> V_12 == V_13 ? 0x7fff : 0x7ff0 ;
return F_10 ( V_22 * V_23 , V_25 ) ;
}
static T_3 F_11 ( struct V_26 * V_27 , struct V_28 * V_29 ,
char * V_30 )
{
struct V_31 * V_32 = F_12 ( V_29 ) ;
struct V_1 * V_2 = F_13 ( V_27 ) ;
int V_16 ;
int V_33 = V_32 -> V_33 ;
V_16 = F_1 ( V_2 , V_33 ) ;
if ( V_16 < 0 )
return V_16 ;
return sprintf ( V_30 , L_1 , F_9 ( V_2 , V_33 , V_16 ) ) ;
}
static int F_14 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_34 ;
F_15 ( V_6 -> V_35 ) ;
for ( V_34 = 0 ; V_34 < V_36 ; ++ V_34 )
F_16 ( & V_2 -> V_27 , & V_37 [ V_34 ] . V_38 ) ;
return 0 ;
}
static int F_17 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_39 * V_40 ;
if ( ! V_2 -> V_27 . V_41
|| ! F_18 ( V_2 -> V_27 . V_41 , NULL ) )
return - V_42 ;
F_19 (client->dev.of_node, node) {
T_4 V_43 ;
unsigned int V_3 ;
unsigned int V_7 = V_44 ;
unsigned int V_9 = V_45 ;
if ( F_20 ( V_40 , L_2 , & V_43 ) ) {
F_21 ( & V_2 -> V_27 , L_3 ,
V_40 -> V_46 ) ;
continue;
}
V_3 = V_43 ;
if ( V_3 >= V_36 ) {
F_21 ( & V_2 -> V_27 ,
L_4 ,
V_3 , V_40 -> V_46 ) ;
continue;
}
if ( ! F_20 ( V_40 , L_5 , & V_43 ) ) {
V_7 = V_43 ;
if ( V_7 > 6 ) {
F_21 ( & V_2 -> V_27 , L_6 ,
V_40 -> V_46 ) ;
return - V_42 ;
}
}
if ( ! F_20 ( V_40 , L_7 , & V_43 ) ) {
V_9 = V_43 ;
if ( V_9 > 7 ) {
F_21 ( & V_2 -> V_27 ,
L_8 ,
V_40 -> V_46 ) ;
return - V_42 ;
}
}
V_6 -> V_8 [ V_3 ] . V_47 = true ;
V_6 -> V_8 [ V_3 ] . V_7 = V_7 ;
V_6 -> V_8 [ V_3 ] . V_9 = V_9 ;
}
return 0 ;
}
static void F_22 ( struct V_1 * V_2 )
{
unsigned int V_34 ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_48 * V_49 = F_23 ( & V_2 -> V_27 ) ;
if ( V_49 ) {
memcpy ( V_6 -> V_8 , V_49 -> V_8 ,
sizeof( V_6 -> V_8 ) ) ;
return;
}
#ifdef F_24
if ( ! F_17 ( V_2 ) )
return;
#endif
for ( V_34 = 0 ; V_34 < V_36 ; ++ V_34 ) {
V_6 -> V_8 [ V_34 ] . V_47 = true ;
V_6 -> V_8 [ V_34 ] . V_7 = V_44 ;
V_6 -> V_8 [ V_34 ] . V_9 = V_45 ;
}
}
static int F_25 ( struct V_1 * V_2 ,
const struct V_50 * V_12 )
{
struct V_5 * V_6 ;
int V_51 ;
unsigned int V_34 ;
V_6 = F_26 ( & V_2 -> V_27 , sizeof( struct V_5 ) ,
V_52 ) ;
if ( ! V_6 )
return - V_53 ;
V_6 -> V_12 = V_12 -> V_54 ;
F_27 ( V_2 , V_6 ) ;
F_28 ( & V_6 -> V_17 ) ;
F_22 ( V_2 ) ;
for ( V_34 = 0 ; V_34 < V_36 ; ++ V_34 ) {
if ( ! V_6 -> V_8 [ V_34 ] . V_47 )
continue;
V_51 = F_29 ( & V_2 -> V_27 , & V_37 [ V_34 ] . V_38 ) ;
if ( V_51 )
goto V_55;
}
V_6 -> V_35 = F_30 ( & V_2 -> V_27 ) ;
if ( F_31 ( V_6 -> V_35 ) ) {
V_51 = F_32 ( V_6 -> V_35 ) ;
goto V_55;
}
return 0 ;
V_55:
for ( V_34 = 0 ; V_34 < V_36 ; ++ V_34 )
F_16 ( & V_2 -> V_27 , & V_37 [ V_34 ] . V_38 ) ;
return V_51 ;
}
