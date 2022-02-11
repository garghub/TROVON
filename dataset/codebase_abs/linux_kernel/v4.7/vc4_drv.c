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
static void F_15 ( void )
{
struct V_26 * V_27 ;
V_27 = F_16 ( 1 ) ;
if ( ! V_27 )
return;
V_27 -> V_28 [ 0 ] . V_29 = 0 ;
V_27 -> V_28 [ 0 ] . V_30 = ~ 0 ;
F_17 ( V_27 , L_2 , false ) ;
F_18 ( V_27 ) ;
}
static int F_19 ( struct V_12 * V_2 )
{
struct V_1 * V_31 = F_20 ( V_2 ) ;
struct V_8 * V_32 ;
struct V_33 * V_34 ;
struct V_9 * V_10 ;
int V_35 = 0 ;
V_2 -> V_36 = F_21 ( 32 ) ;
V_10 = F_22 ( V_2 , sizeof( * V_10 ) , V_37 ) ;
if ( ! V_10 )
return - V_38 ;
V_32 = F_23 ( & V_39 , V_2 ) ;
if ( ! V_32 )
return - V_38 ;
F_24 ( V_31 , V_32 ) ;
V_10 -> V_2 = V_32 ;
V_32 -> V_40 = V_10 ;
F_25 ( V_32 ) ;
F_26 ( V_32 ) ;
if ( V_35 )
goto V_41;
F_27 ( V_32 ) ;
V_35 = F_28 ( V_2 , V_32 ) ;
if ( V_35 )
goto V_42;
F_15 () ;
V_35 = F_29 ( V_32 , 0 ) ;
if ( V_35 < 0 )
goto V_43;
F_30 (connector, &drm->mode_config.connector_list, head) {
V_35 = F_31 ( V_34 ) ;
if ( V_35 )
goto V_44;
}
F_32 ( V_32 ) ;
return 0 ;
V_44:
F_33 ( V_32 ) ;
V_43:
F_34 ( V_2 , V_32 ) ;
V_42:
F_35 ( V_32 ) ;
V_41:
F_36 ( V_32 ) ;
F_37 ( V_32 ) ;
return V_35 ;
}
static void F_38 ( struct V_12 * V_2 )
{
struct V_1 * V_31 = F_20 ( V_2 ) ;
struct V_8 * V_32 = F_39 ( V_31 ) ;
struct V_9 * V_10 = F_8 ( V_32 ) ;
if ( V_10 -> V_11 )
F_40 ( V_10 -> V_11 ) ;
F_41 ( V_32 ) ;
F_42 ( V_32 ) ;
}
static int F_43 ( struct V_1 * V_31 )
{
struct V_14 * V_15 = NULL ;
struct V_12 * V_2 = & V_31 -> V_2 ;
F_11 ( V_2 , & V_15 ,
V_45 , F_44 ( V_45 ) ) ;
return F_45 ( V_2 , & V_46 , V_15 ) ;
}
static int F_46 ( struct V_1 * V_31 )
{
F_47 ( & V_31 -> V_2 , & V_46 ) ;
return 0 ;
}
static int T_2 F_48 ( void )
{
int V_19 , V_35 ;
for ( V_19 = 0 ; V_19 < F_44 ( V_45 ) ; V_19 ++ ) {
V_35 = F_49 ( V_45 [ V_19 ] ) ;
if ( V_35 ) {
while ( -- V_19 >= 0 )
F_50 ( V_45 [ V_19 ] ) ;
return V_35 ;
}
}
return F_49 ( & V_47 ) ;
}
static void T_3 F_51 ( void )
{
int V_19 ;
for ( V_19 = F_44 ( V_45 ) - 1 ; V_19 >= 0 ; V_19 -- )
F_50 ( V_45 [ V_19 ] ) ;
F_50 ( & V_47 ) ;
}
