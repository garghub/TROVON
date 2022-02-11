static int F_1 ( struct V_1 * V_2 , int V_3 , int type )
{
struct V_4 V_5 ;
struct V_6 * V_7 ;
int V_8 , V_9 ;
T_1 V_10 ;
F_2 (entry, &dev->msi_list, list) {
V_8 = F_3 ( & V_11 . V_12 , 1 ) ;
if ( V_8 < 0 ) {
F_4 ( L_1 ,
V_13 ) ;
return V_8 ;
}
V_9 = V_11 . V_14 [ V_8 ] ;
if ( V_9 == V_15 ) {
F_5 ( L_2 , V_13 , V_8 ) ;
return - V_16 ;
}
V_10 = V_11 . V_17 + V_8 * 0x10 ;
V_5 . V_18 = F_6 ( V_10 ) ;
V_5 . V_19 = F_7 ( V_10 ) ;
V_5 . V_20 = 0 ;
F_4 ( L_3 , V_13 , V_9 ,
( ( ( T_1 ) V_5 . V_18 ) << 32 ) | V_5 . V_19 ) ;
if ( F_8 ( V_9 , V_7 ) ) {
F_5 (
L_4 ,
V_13 , V_9 ) ;
F_9 ( & V_11 . V_12 , V_8 , 1 ) ;
return - V_16 ;
}
F_10 ( V_9 , & V_5 ) ;
}
return 0 ;
}
static int F_11 ( int V_9 )
{
int V_8 ;
for ( V_8 = 0 ; V_8 < V_11 . V_21 ; V_8 ++ )
if ( V_11 . V_14 [ V_8 ] == V_9 )
return V_8 ;
return - V_16 ;
}
static void F_12 ( struct V_1 * V_2 )
{
struct V_6 * V_7 ;
int V_8 ;
F_2 (entry, &dev->msi_list, list) {
if ( V_7 -> V_8 == V_15 )
continue;
V_8 = F_11 ( V_7 -> V_8 ) ;
F_13 ( V_8 < 0 ) ;
F_8 ( V_7 -> V_8 , NULL ) ;
F_9 ( & V_11 . V_12 , V_8 , 1 ) ;
F_4 ( L_5 , V_13 ,
V_7 -> V_8 , V_8 ) ;
}
}
static int F_14 ( struct V_1 * V_22 , int V_3 , int type )
{
if ( type == V_23 ) {
F_4 ( L_6 , V_13 ) ;
return - V_16 ;
}
return 0 ;
}
static int F_15 ( struct V_24 * V_22 )
{
struct V_25 * V_2 = & V_22 -> V_2 ;
struct V_26 * V_27 ;
int V_8 , V_28 , V_21 ;
V_27 = F_16 ( V_22 , V_29 , 0 ) ;
if ( F_17 ( V_27 ) ) {
F_18 ( V_2 , L_7 ) ;
return - V_16 ;
}
V_21 = F_19 ( V_2 -> V_30 ) ;
if ( ! V_21 ) {
F_18 ( V_2 , L_8 ) ;
return - V_16 ;
}
V_11 . V_2 = V_2 ;
V_11 . V_17 = V_27 -> V_31 ;
V_11 . V_20 = F_20 ( V_27 -> V_31 , F_21 ( V_27 ) ) ;
V_11 . V_21 = V_21 ;
if ( F_17 ( V_11 . V_20 ) ) {
F_18 ( V_2 , L_9 ) ;
return - V_32 ;
}
V_28 = F_22 ( & V_11 . V_12 , V_21 , V_2 -> V_30 ) ;
if ( V_28 )
goto V_33;
V_11 . V_14 = F_23 ( sizeof( int ) * V_21 , V_34 ) ;
if ( F_17 ( V_11 . V_14 ) ) {
V_28 = - V_32 ;
goto V_35;
}
for ( V_8 = 0 ; V_8 < V_21 ; V_8 ++ ) {
V_11 . V_14 [ V_8 ] =
F_24 ( V_2 -> V_30 , V_8 ) ;
if ( V_11 . V_14 [ V_8 ] == V_15 ) {
F_18 ( V_2 , L_10 ) ;
V_28 = - V_16 ;
goto V_36;
}
}
V_37 . V_38 = F_1 ;
V_37 . V_39 = F_12 ;
V_37 . V_40 = F_14 ;
return 0 ;
V_36:
F_25 ( V_11 . V_14 ) ;
V_35:
F_26 ( & V_11 . V_12 ) ;
V_33:
F_27 ( V_11 . V_20 ) ;
return V_28 ;
}
static int F_28 ( void )
{
return F_29 ( & V_41 ) ;
}
