static int F_1 ( struct V_1 * V_2 , void * V_3 )
{
struct V_4 * V_5 = (struct V_4 * ) V_3 ;
struct V_4 * V_6 = F_2 ( V_2 ) ;
int V_7 ;
for ( V_7 = 0 ; V_7 < V_5 -> V_8 ; V_7 ++ )
if ( ! strcmp ( V_5 -> V_9 [ V_7 ] , V_6 -> V_10 ) ) {
if ( V_6 -> V_11 )
V_6 -> V_11 ( V_6 ) ;
}
return 0 ;
}
static void F_3 ( struct V_12 * V_13 )
{
struct V_4 * V_5 = F_4 ( V_13 , struct V_4 ,
V_14 ) ;
F_5 ( V_5 -> V_2 , L_1 , V_15 ) ;
F_6 ( V_16 , NULL , V_5 ,
F_1 ) ;
F_7 ( V_5 ) ;
F_8 ( & V_5 -> V_2 -> V_17 , V_18 ) ;
}
void F_9 ( struct V_4 * V_5 )
{
F_5 ( V_5 -> V_2 , L_1 , V_15 ) ;
F_10 ( & V_5 -> V_14 ) ;
}
static int F_11 ( struct V_1 * V_2 , void * V_3 )
{
union V_19 V_20 = { 0 ,} ;
struct V_4 * V_5 = (struct V_4 * ) V_3 ;
struct V_4 * V_21 = F_2 ( V_2 ) ;
int V_7 ;
for ( V_7 = 0 ; V_7 < V_21 -> V_8 ; V_7 ++ ) {
if ( ! strcmp ( V_21 -> V_9 [ V_7 ] , V_5 -> V_10 ) ) {
if ( V_21 -> V_22 ( V_21 ,
V_23 , & V_20 ) )
continue;
if ( V_20 . V_24 )
return V_20 . V_24 ;
}
}
return 0 ;
}
int F_12 ( struct V_4 * V_5 )
{
int error ;
error = F_6 ( V_16 , NULL , V_5 ,
F_11 ) ;
F_5 ( V_5 -> V_2 , L_2 , V_15 , error ) ;
return error ;
}
static int F_13 ( struct V_1 * V_2 , void * V_3 )
{
union V_19 V_20 = { 0 ,} ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
if ( V_5 -> type != V_25 ) {
if ( V_5 -> V_22 ( V_5 , V_23 , & V_20 ) )
return 0 ;
if ( V_20 . V_24 )
return V_20 . V_24 ;
}
return 0 ;
}
int F_14 ( void )
{
int error ;
error = F_6 ( V_16 , NULL , NULL ,
F_13 ) ;
return error ;
}
int F_15 ( struct V_4 * V_5 )
{
if ( V_5 -> type == V_25 && V_5 -> V_26 ) {
V_5 -> V_26 ( V_5 ) ;
return 0 ;
}
return - V_27 ;
}
static int F_16 ( struct V_1 * V_2 , void * V_3 )
{
const char * V_10 = V_3 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
return strcmp ( V_5 -> V_10 , V_10 ) == 0 ;
}
struct V_4 * F_17 ( char * V_10 )
{
struct V_1 * V_2 = F_18 ( V_16 , NULL , V_10 ,
F_16 ) ;
return V_2 ? F_2 ( V_2 ) : NULL ;
}
static void F_19 ( struct V_1 * V_2 )
{
F_20 ( L_3 , F_21 ( V_2 ) , V_15 ) ;
F_22 ( V_2 ) ;
}
int F_23 ( struct V_1 * V_28 , struct V_4 * V_5 )
{
struct V_1 * V_2 ;
int V_29 ;
V_2 = F_24 ( sizeof( * V_2 ) , V_30 ) ;
if ( ! V_2 )
return - V_31 ;
F_25 ( V_2 ) ;
V_2 -> V_32 = V_16 ;
V_2 -> type = & V_33 ;
V_2 -> V_28 = V_28 ;
V_2 -> V_34 = F_19 ;
F_26 ( V_2 , V_5 ) ;
V_5 -> V_2 = V_2 ;
F_27 ( & V_5 -> V_14 , F_3 ) ;
V_29 = F_28 ( & V_2 -> V_17 , L_4 , V_5 -> V_10 ) ;
if ( V_29 )
goto V_35;
V_29 = F_29 ( V_2 ) ;
if ( V_29 )
goto V_36;
V_29 = F_30 ( V_5 ) ;
if ( V_29 )
goto V_37;
F_9 ( V_5 ) ;
goto V_38;
V_37:
F_31 ( V_2 ) ;
V_35:
V_36:
F_32 ( V_2 ) ;
V_38:
return V_29 ;
}
void F_33 ( struct V_4 * V_5 )
{
F_34 ( & V_5 -> V_14 ) ;
F_35 ( V_5 ) ;
F_36 ( V_5 -> V_2 ) ;
}
static int T_1 F_37 ( void )
{
V_16 = F_38 ( V_39 , L_5 ) ;
if ( F_39 ( V_16 ) )
return F_40 ( V_16 ) ;
V_16 -> V_40 = V_41 ;
F_41 ( & V_33 ) ;
return 0 ;
}
static void T_2 F_42 ( void )
{
F_43 ( V_16 ) ;
}
