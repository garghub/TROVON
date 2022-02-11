static int F_1 ( struct V_1 * V_2 , int V_3 , int type )
{
struct V_4 V_5 ;
struct V_6 * V_7 ;
int V_8 , V_9 ;
T_1 V_10 ;
if ( type == V_11 ) {
F_2 ( L_1 , V_12 ) ;
return - V_13 ;
}
F_3 (entry, dev) {
V_8 = F_4 ( & V_14 . V_15 , 1 ) ;
if ( V_8 < 0 ) {
F_2 ( L_2 ,
V_12 ) ;
return V_8 ;
}
V_9 = V_14 . V_16 [ V_8 ] ;
if ( ! V_9 ) {
F_5 ( L_3 , V_12 , V_8 ) ;
return - V_13 ;
}
V_10 = V_14 . V_17 + V_8 * 0x10 ;
V_5 . V_18 = F_6 ( V_10 ) ;
V_5 . V_19 = F_7 ( V_10 ) ;
V_5 . V_20 = 0 ;
F_2 ( L_4 , V_12 , V_9 ,
( ( ( T_1 ) V_5 . V_18 ) << 32 ) | V_5 . V_19 ) ;
if ( F_8 ( V_9 , V_7 ) ) {
F_5 (
L_5 ,
V_12 , V_9 ) ;
F_9 ( & V_14 . V_15 , V_8 , 1 ) ;
return - V_13 ;
}
F_10 ( V_9 , & V_5 ) ;
}
return 0 ;
}
static int F_11 ( int V_9 )
{
int V_8 ;
for ( V_8 = 0 ; V_8 < V_14 . V_21 ; V_8 ++ )
if ( V_14 . V_16 [ V_8 ] == V_9 )
return V_8 ;
return - V_13 ;
}
static void F_12 ( struct V_1 * V_2 )
{
struct V_6 * V_7 ;
int V_8 ;
F_3 (entry, dev) {
if ( ! V_7 -> V_8 )
continue;
V_8 = F_11 ( V_7 -> V_8 ) ;
F_13 ( V_8 < 0 ) ;
F_8 ( V_7 -> V_8 , NULL ) ;
F_9 ( & V_14 . V_15 , V_8 , 1 ) ;
F_2 ( L_6 , V_12 ,
V_7 -> V_8 , V_8 ) ;
}
}
static int F_14 ( struct V_22 * V_23 )
{
struct V_24 * V_2 = & V_23 -> V_2 ;
struct V_25 * V_26 ;
int V_8 , V_27 , V_21 ;
struct V_28 * V_29 ;
V_26 = F_15 ( V_23 , V_30 , 0 ) ;
if ( ! V_26 ) {
F_16 ( V_2 , L_7 ) ;
return - V_13 ;
}
V_21 = F_17 ( V_2 -> V_31 ) ;
if ( ! V_21 ) {
F_16 ( V_2 , L_8 ) ;
return - V_13 ;
}
V_14 . V_2 = V_2 ;
V_14 . V_17 = V_26 -> V_32 ;
V_14 . V_20 = F_18 ( V_26 -> V_32 , F_19 ( V_26 ) ) ;
V_14 . V_21 = V_21 ;
if ( ! V_14 . V_20 ) {
F_16 ( V_2 , L_9 ) ;
return - V_33 ;
}
V_27 = F_20 ( & V_14 . V_15 , V_21 , V_2 -> V_31 ) ;
if ( V_27 )
goto V_34;
V_14 . V_16 = F_21 ( sizeof( int ) * V_21 , V_35 ) ;
if ( ! V_14 . V_16 ) {
V_27 = - V_33 ;
goto V_36;
}
for ( V_8 = 0 ; V_8 < V_21 ; V_8 ++ ) {
V_14 . V_16 [ V_8 ] =
F_22 ( V_2 -> V_31 , V_8 ) ;
if ( ! V_14 . V_16 [ V_8 ] ) {
F_16 ( V_2 , L_10 ) ;
V_27 = - V_13 ;
goto V_37;
}
}
F_23 (phb, &hose_list, list_node) {
V_29 -> V_38 . V_39 = F_1 ;
V_29 -> V_38 . V_40 = F_12 ;
}
return 0 ;
V_37:
F_24 ( V_14 . V_16 ) ;
V_36:
F_25 ( & V_14 . V_15 ) ;
V_34:
F_26 ( V_14 . V_20 ) ;
return V_27 ;
}
static int F_27 ( void )
{
return F_28 ( & V_41 ) ;
}
