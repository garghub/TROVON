static void F_1 ( unsigned long V_1 )
{
struct V_2 * V_3 = (struct V_2 * ) V_1 ;
if ( ! V_3 )
return;
F_2 ( V_3 -> V_4 , L_1 ) ;
if ( V_3 -> V_5 )
F_3 ( V_3 -> V_5 ) ;
}
static T_1 F_4 ( int V_6 , void * V_1 )
{
struct V_2 * V_3 = (struct V_2 * ) V_1 ;
F_5 ( & V_3 -> V_7 ) ;
return V_8 ;
}
static void F_6 ( struct V_4 * V_9 )
{
struct V_2 * V_3 = F_7 ( V_9 ) ;
int V_10 ;
for ( V_10 = 0 ; V_10 < V_3 -> V_11 ; V_10 ++ ) {
F_8 ( & V_9 -> V_12 , V_3 -> V_13 [ V_10 ] . V_14 ) ;
F_9 ( V_3 -> V_13 [ V_10 ] . V_15 ) ;
}
}
static int F_10 ( struct V_4 * V_9 )
{
struct V_16 * V_17 = V_9 -> V_18 ;
struct V_2 * V_3 = F_7 ( V_9 ) ;
int V_19 , V_20 , V_10 , V_21 ;
V_19 = F_11 ( V_17 ) ;
if ( V_19 < 0 ) {
F_12 ( V_9 , L_2 , V_19 ) ;
return V_19 ;
}
V_20 = F_13 ( V_17 , L_3 ) ;
if ( V_19 != V_20 ) {
F_12 ( V_9 , L_4 ) ;
return - V_22 ;
}
V_3 -> V_13 = F_14 ( V_9 , V_19 *
sizeof( struct V_23 ) , V_24 ) ;
if ( ! V_3 -> V_13 ) {
F_12 ( V_9 , L_5 ) ;
return - V_25 ;
}
V_3 -> V_11 = V_19 ;
for ( V_10 = 0 ; V_10 < V_19 ; V_10 ++ ) {
V_3 -> V_13 [ V_10 ] . V_15 = F_15 ( V_9 , NULL , V_10 ,
V_26 ) ;
if ( F_16 ( V_3 -> V_13 [ V_10 ] . V_15 ) ) {
F_12 ( V_9 , L_6 , V_10 ) ;
return F_17 ( V_3 -> V_13 [ V_10 ] . V_15 ) ;
}
V_21 = F_18 ( V_17 , L_3 , V_10 ,
& ( V_3 -> V_13 [ V_10 ] . V_14 ) ) ;
if ( V_21 ) {
F_12 ( V_9 , L_7 , V_10 ) ;
return V_21 ;
}
V_21 = F_19 ( V_3 -> V_13 [ V_10 ] . V_15 , 0 ) ;
if ( V_21 )
return V_21 ;
V_21 = F_20 ( V_9 , V_3 -> V_13 [ V_10 ] . V_14 ,
V_3 -> V_13 [ V_10 ] . V_15 ) ;
if ( V_21 )
return V_21 ;
}
return 0 ;
}
static int F_21 ( struct V_4 * V_9 )
{
struct V_16 * V_17 ;
struct V_2 * V_3 ;
struct V_27 * V_28 = F_22 ( V_9 ) ;
struct V_29 * V_30 = F_23 ( V_28 ) ;
int V_6 , V_31 , V_21 ;
struct V_32 V_33 ;
struct V_32 V_34 ;
V_17 = V_9 -> V_18 ;
if ( ! V_17 ) {
F_12 ( V_9 , L_8 ) ;
return - V_35 ;
}
V_3 = F_14 ( V_9 , sizeof( * V_3 ) , V_24 ) ;
if ( ! V_3 ) {
F_12 ( V_9 , L_9 ) ;
return - V_25 ;
}
F_24 ( V_9 , V_3 ) ;
V_3 -> V_4 = V_9 ;
V_6 = F_25 ( V_17 , 0 ) ;
if ( ! V_6 ) {
F_12 ( V_9 , L_10 , V_6 ) ;
return - V_22 ;
}
V_3 -> V_36 = V_6 ;
V_31 = F_26 ( V_6 ) ;
F_27 ( & V_3 -> V_7 ,
F_1 , ( unsigned long ) V_3 ) ;
V_21 = F_28 ( V_9 , V_6 , F_4 ,
V_31 , L_11 , V_3 ) ;
if ( V_21 < 0 ) {
F_12 ( V_9 , L_12 ,
V_6 , V_31 ) ;
return V_21 ;
}
F_29 ( V_6 ) ;
if( V_37 ) {
V_21 = F_10 ( V_9 ) ;
if ( V_21 < 0 ) {
F_12 ( V_9 , L_13 ) ;
goto V_38;
}
}
V_33 . V_14 = L_14 ;
V_33 . V_39 = V_28 -> V_39 ;
V_33 . V_40 = V_28 -> V_40 ;
V_33 . V_41 = NULL ;
V_33 . V_42 = NULL ;
V_3 -> V_5 = F_30 ( V_30 , & V_33 ) ;
if ( ! V_3 -> V_5 ) {
F_12 ( V_9 , L_15 ) ;
V_21 = - V_25 ;
goto V_43;
}
V_21 = F_31 ( & V_3 -> V_5 -> V_4 ) ;
if ( V_21 == 0 ) {
F_32 ( V_9 , L_16 ) ;
V_21 = - V_44 ;
goto V_45;
} else if ( V_21 < 0 ) {
F_12 ( V_9 , L_17 , V_21 ) ;
goto V_45;
}
V_34 . V_14 = L_18 ;
V_34 . V_39 = V_28 -> V_39 ;
V_34 . V_40 = V_28 -> V_40 ;
V_34 . V_41 = NULL ;
V_34 . V_42 = NULL ;
V_3 -> V_46 = F_30 ( V_30 , & V_34 ) ;
if ( ! V_3 -> V_46 ) {
F_12 ( V_9 , L_19 ) ;
V_21 = - V_25 ;
goto V_45;
}
V_21 = F_31 ( & V_3 -> V_46 -> V_4 ) ;
if ( V_21 == 0 ) {
F_32 ( V_9 , L_20 ) ;
V_21 = - V_44 ;
goto V_47;
} else if ( V_21 < 0 ) {
F_12 ( V_9 , L_21 , V_21 ) ;
goto V_47;
}
F_2 ( V_9 , L_22 ) ;
return 0 ;
V_47:
F_33 ( & V_3 -> V_46 -> V_4 , NULL ) ;
V_45:
F_33 ( & V_3 -> V_5 -> V_4 , NULL ) ;
V_43:
F_6 ( V_9 ) ;
V_38:
F_34 ( V_3 -> V_36 ) ;
F_35 ( & V_3 -> V_7 ) ;
return V_21 ;
}
static int F_36 ( struct V_4 * V_9 )
{
struct V_2 * V_3 = F_7 ( V_9 ) ;
if ( ! V_3 )
return 0 ;
if ( V_3 -> V_46 ) {
F_33 ( & V_3 -> V_46 -> V_4 , NULL ) ;
V_3 -> V_46 = NULL ;
}
if ( V_3 -> V_5 ) {
F_33 ( & V_3 -> V_5 -> V_4 , NULL ) ;
V_3 -> V_5 = NULL ;
}
F_6 ( V_9 ) ;
F_24 ( V_9 , NULL ) ;
F_34 ( V_3 -> V_36 ) ;
F_35 ( & V_3 -> V_7 ) ;
return 0 ;
}
static int T_2 F_37 ( void )
{
return F_38 ( & V_48 ) ;
}
static void T_3 F_39 ( void )
{
F_40 ( & V_48 ) ;
}
