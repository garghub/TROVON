void T_1 * F_1 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 ;
void T_1 * V_6 ;
V_5 = F_2 ( V_2 , V_7 , V_3 ) ;
V_6 = F_3 ( & V_2 -> V_2 , V_5 ) ;
if ( F_4 ( V_6 ) ) {
F_5 ( L_1 , F_6 ( V_6 ) ) ;
return V_6 ;
}
return V_6 ;
}
static void F_7 ( struct V_8 * V_2 )
{
struct V_9 * V_10 = F_8 ( V_2 ) ;
if ( V_10 -> V_11 )
F_9 ( V_10 -> V_11 ) ;
}
static int F_10 ( struct V_12 * V_2 , void * V_13 )
{
return V_2 == V_13 ;
}
static void F_11 ( struct V_12 * V_2 ,
struct V_14 * * V_15 ,
struct V_16 * const * V_17 ,
int V_18 )
{
int V_19 ;
for ( V_19 = 0 ; V_19 < V_18 ; V_19 ++ ) {
struct V_20 * V_21 = & V_17 [ V_19 ] -> V_22 ;
struct V_12 * V_23 = NULL , * V_24 ;
while ( ( V_24 = F_12 ( & V_25 , V_23 , V_21 ,
( void * ) V_25 . V_15 ) ) ) {
F_13 ( V_23 ) ;
F_14 ( V_2 , V_15 , F_10 , V_24 ) ;
V_23 = V_24 ;
}
F_13 ( V_23 ) ;
}
}
static int F_15 ( struct V_12 * V_2 )
{
struct V_1 * V_26 = F_16 ( V_2 ) ;
struct V_8 * V_27 ;
struct V_28 * V_29 ;
struct V_9 * V_10 ;
int V_30 = 0 ;
V_2 -> V_31 = F_17 ( 32 ) ;
V_10 = F_18 ( V_2 , sizeof( * V_10 ) , V_32 ) ;
if ( ! V_10 )
return - V_33 ;
V_27 = F_19 ( & V_34 , V_2 ) ;
if ( ! V_27 )
return - V_33 ;
F_20 ( V_26 , V_27 ) ;
V_10 -> V_2 = V_27 ;
V_27 -> V_35 = V_10 ;
F_21 ( V_27 ) ;
F_22 ( V_27 ) ;
if ( V_30 )
goto V_36;
F_23 ( V_27 ) ;
V_30 = F_24 ( V_2 , V_27 ) ;
if ( V_30 )
goto V_37;
V_30 = F_25 ( V_27 , 0 ) ;
if ( V_30 < 0 )
goto V_38;
F_26 (connector, &drm->mode_config.connector_list, head) {
V_30 = F_27 ( V_29 ) ;
if ( V_30 )
goto V_39;
}
F_28 ( V_27 ) ;
return 0 ;
V_39:
F_29 ( V_27 ) ;
V_38:
F_30 ( V_2 , V_27 ) ;
V_37:
F_31 ( V_27 ) ;
V_36:
F_32 ( V_27 ) ;
F_33 ( V_27 ) ;
return V_30 ;
}
static void F_34 ( struct V_12 * V_2 )
{
struct V_1 * V_26 = F_16 ( V_2 ) ;
struct V_8 * V_27 = F_35 ( V_26 ) ;
struct V_9 * V_10 = F_8 ( V_27 ) ;
if ( V_10 -> V_11 )
F_36 ( V_10 -> V_11 ) ;
F_37 ( V_27 ) ;
F_38 ( V_27 ) ;
}
static int F_39 ( struct V_1 * V_26 )
{
struct V_14 * V_15 = NULL ;
struct V_12 * V_2 = & V_26 -> V_2 ;
F_11 ( V_2 , & V_15 ,
V_40 , F_40 ( V_40 ) ) ;
return F_41 ( V_2 , & V_41 , V_15 ) ;
}
static int F_42 ( struct V_1 * V_26 )
{
F_43 ( & V_26 -> V_2 , & V_41 ) ;
return 0 ;
}
static int T_2 F_44 ( void )
{
int V_19 , V_30 ;
for ( V_19 = 0 ; V_19 < F_40 ( V_40 ) ; V_19 ++ ) {
V_30 = F_45 ( V_40 [ V_19 ] ) ;
if ( V_30 ) {
while ( -- V_19 >= 0 )
F_46 ( V_40 [ V_19 ] ) ;
return V_30 ;
}
}
return F_45 ( & V_42 ) ;
}
static void T_3 F_47 ( void )
{
int V_19 ;
for ( V_19 = F_40 ( V_40 ) - 1 ; V_19 >= 0 ; V_19 -- )
F_46 ( V_40 [ V_19 ] ) ;
F_46 ( & V_42 ) ;
}
