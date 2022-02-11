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
static void F_7 ( struct V_8 * V_2 , struct V_9 * V_10 )
{
struct V_11 * V_12 ;
F_8 (crtc, &dev->mode_config.crtc_list, head)
F_9 ( V_12 , V_10 ) ;
}
static void F_10 ( struct V_8 * V_2 )
{
struct V_13 * V_14 = F_11 ( V_2 ) ;
if ( V_14 -> V_15 )
F_12 ( V_14 -> V_15 ) ;
}
static int F_13 ( struct V_16 * V_2 , void * V_17 )
{
return V_2 == V_17 ;
}
static void F_14 ( struct V_16 * V_2 ,
struct V_18 * * V_19 ,
struct V_20 * const * V_21 ,
int V_22 )
{
int V_23 ;
for ( V_23 = 0 ; V_23 < V_22 ; V_23 ++ ) {
struct V_24 * V_25 = & V_21 [ V_23 ] -> V_26 ;
struct V_16 * V_27 = NULL , * V_28 ;
while ( ( V_28 = F_15 ( & V_29 , V_27 , V_25 ,
( void * ) V_29 . V_19 ) ) ) {
F_16 ( V_27 ) ;
F_17 ( V_2 , V_19 , F_13 , V_28 ) ;
V_27 = V_28 ;
}
F_16 ( V_27 ) ;
}
}
static int F_18 ( struct V_16 * V_2 )
{
struct V_1 * V_30 = F_19 ( V_2 ) ;
struct V_8 * V_31 ;
struct V_32 * V_33 ;
struct V_13 * V_14 ;
int V_34 = 0 ;
V_2 -> V_35 = F_20 ( 32 ) ;
V_14 = F_21 ( V_2 , sizeof( * V_14 ) , V_36 ) ;
if ( ! V_14 )
return - V_37 ;
V_31 = F_22 ( & V_38 , V_2 ) ;
if ( ! V_31 )
return - V_37 ;
F_23 ( V_30 , V_31 ) ;
V_14 -> V_2 = V_31 ;
V_31 -> V_39 = V_14 ;
F_24 ( V_31 , F_25 ( V_2 ) ) ;
F_26 ( V_31 ) ;
if ( V_34 )
goto V_40;
V_34 = F_27 ( V_2 , V_31 ) ;
if ( V_34 )
goto V_40;
V_34 = F_28 ( V_31 , 0 ) ;
if ( V_34 < 0 )
goto V_41;
F_8 (connector, &drm->mode_config.connector_list, head) {
V_34 = F_29 ( V_33 ) ;
if ( V_34 )
goto V_42;
}
F_30 ( V_31 ) ;
return 0 ;
V_42:
F_31 ( V_31 ) ;
V_41:
F_32 ( V_2 , V_31 ) ;
V_40:
F_33 ( V_31 ) ;
return V_34 ;
}
static void F_34 ( struct V_16 * V_2 )
{
struct V_1 * V_30 = F_19 ( V_2 ) ;
struct V_8 * V_31 = F_35 ( V_30 ) ;
struct V_13 * V_14 = F_11 ( V_31 ) ;
if ( V_14 -> V_15 )
F_36 ( V_14 -> V_15 ) ;
F_37 ( V_31 ) ;
F_38 ( V_31 ) ;
}
static int F_39 ( struct V_1 * V_30 )
{
struct V_18 * V_19 = NULL ;
struct V_16 * V_2 = & V_30 -> V_2 ;
F_14 ( V_2 , & V_19 ,
V_43 , F_40 ( V_43 ) ) ;
return F_41 ( V_2 , & V_44 , V_19 ) ;
}
static int F_42 ( struct V_1 * V_30 )
{
F_43 ( & V_30 -> V_2 , & V_44 ) ;
return 0 ;
}
static int T_2 F_44 ( void )
{
int V_23 , V_34 ;
for ( V_23 = 0 ; V_23 < F_40 ( V_43 ) ; V_23 ++ ) {
V_34 = F_45 ( V_43 [ V_23 ] ) ;
if ( V_34 ) {
while ( -- V_23 >= 0 )
F_46 ( V_43 [ V_23 ] ) ;
return V_34 ;
}
}
return F_45 ( & V_45 ) ;
}
static void T_3 F_47 ( void )
{
int V_23 ;
for ( V_23 = F_40 ( V_43 ) - 1 ; V_23 >= 0 ; V_23 -- )
F_46 ( V_43 [ V_23 ] ) ;
F_46 ( & V_45 ) ;
}
