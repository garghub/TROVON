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
F_3 (entry, &dev->msi_list, list) {
V_8 = F_4 ( & V_14 . V_15 , 1 ) ;
if ( V_8 < 0 ) {
F_2 ( L_2 ,
V_12 ) ;
return V_8 ;
}
V_9 = V_14 . V_16 [ V_8 ] ;
if ( V_9 == V_17 ) {
F_5 ( L_3 , V_12 , V_8 ) ;
return - V_13 ;
}
V_10 = V_14 . V_18 + V_8 * 0x10 ;
V_5 . V_19 = F_6 ( V_10 ) ;
V_5 . V_20 = F_7 ( V_10 ) ;
V_5 . V_21 = 0 ;
F_2 ( L_4 , V_12 , V_9 ,
( ( ( T_1 ) V_5 . V_19 ) << 32 ) | V_5 . V_20 ) ;
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
for ( V_8 = 0 ; V_8 < V_14 . V_22 ; V_8 ++ )
if ( V_14 . V_16 [ V_8 ] == V_9 )
return V_8 ;
return - V_13 ;
}
static void F_12 ( struct V_1 * V_2 )
{
struct V_6 * V_7 ;
int V_8 ;
F_3 (entry, &dev->msi_list, list) {
if ( V_7 -> V_8 == V_17 )
continue;
V_8 = F_11 ( V_7 -> V_8 ) ;
F_13 ( V_8 < 0 ) ;
F_8 ( V_7 -> V_8 , NULL ) ;
F_9 ( & V_14 . V_15 , V_8 , 1 ) ;
F_2 ( L_6 , V_12 ,
V_7 -> V_8 , V_8 ) ;
}
}
static int F_14 ( struct V_23 * V_24 )
{
struct V_25 * V_2 = & V_24 -> V_2 ;
struct V_26 * V_27 ;
int V_8 , V_28 , V_22 ;
V_27 = F_15 ( V_24 , V_29 , 0 ) ;
if ( F_16 ( V_27 ) ) {
F_17 ( V_2 , L_7 ) ;
return - V_13 ;
}
V_22 = F_18 ( V_2 -> V_30 ) ;
if ( ! V_22 ) {
F_17 ( V_2 , L_8 ) ;
return - V_13 ;
}
V_14 . V_2 = V_2 ;
V_14 . V_18 = V_27 -> V_31 ;
V_14 . V_21 = F_19 ( V_27 -> V_31 , F_20 ( V_27 ) ) ;
V_14 . V_22 = V_22 ;
if ( F_16 ( V_14 . V_21 ) ) {
F_17 ( V_2 , L_9 ) ;
return - V_32 ;
}
V_28 = F_21 ( & V_14 . V_15 , V_22 , V_2 -> V_30 ) ;
if ( V_28 )
goto V_33;
V_14 . V_16 = F_22 ( sizeof( int ) * V_22 , V_34 ) ;
if ( F_16 ( V_14 . V_16 ) ) {
V_28 = - V_32 ;
goto V_35;
}
for ( V_8 = 0 ; V_8 < V_22 ; V_8 ++ ) {
V_14 . V_16 [ V_8 ] =
F_23 ( V_2 -> V_30 , V_8 ) ;
if ( V_14 . V_16 [ V_8 ] == V_17 ) {
F_17 ( V_2 , L_10 ) ;
V_28 = - V_13 ;
goto V_36;
}
}
V_37 . V_38 = F_1 ;
V_37 . V_39 = F_12 ;
return 0 ;
V_36:
F_24 ( V_14 . V_16 ) ;
V_35:
F_25 ( & V_14 . V_15 ) ;
V_33:
F_26 ( V_14 . V_21 ) ;
return V_28 ;
}
static int F_27 ( void )
{
return F_28 ( & V_40 ) ;
}
