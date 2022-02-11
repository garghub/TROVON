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
unsigned int * V_25 = V_3 ;
( * V_25 ) ++ ;
if ( V_5 -> type != V_26 ) {
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
unsigned int V_25 = 0 ;
error = F_6 ( V_16 , NULL , & V_25 ,
F_13 ) ;
if ( V_25 == 0 )
return 1 ;
return error ;
}
int F_15 ( struct V_4 * V_5 )
{
if ( V_5 -> type == V_26 && V_5 -> V_27 ) {
V_5 -> V_27 ( V_5 ) ;
return 0 ;
}
return - V_28 ;
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
int F_19 ( struct V_4 * V_5 , struct V_1 * V_2 )
{
return F_20 ( & V_5 -> V_2 -> V_17 , & V_2 -> V_17 , L_3 ) ;
}
static void F_21 ( struct V_1 * V_2 )
{
F_22 ( L_4 , F_23 ( V_2 ) , V_15 ) ;
F_24 ( V_2 ) ;
}
int F_25 ( struct V_1 * V_29 , struct V_4 * V_5 )
{
struct V_1 * V_2 ;
int V_30 ;
V_2 = F_26 ( sizeof( * V_2 ) , V_31 ) ;
if ( ! V_2 )
return - V_32 ;
F_27 ( V_2 ) ;
V_2 -> V_33 = V_16 ;
V_2 -> type = & V_34 ;
V_2 -> V_29 = V_29 ;
V_2 -> V_35 = F_21 ;
F_28 ( V_2 , V_5 ) ;
V_5 -> V_2 = V_2 ;
F_29 ( & V_5 -> V_14 , F_3 ) ;
V_30 = F_30 ( & V_2 -> V_17 , L_5 , V_5 -> V_10 ) ;
if ( V_30 )
goto V_36;
V_30 = F_31 ( V_2 ) ;
if ( V_30 )
goto V_37;
V_30 = F_32 ( V_5 ) ;
if ( V_30 )
goto V_38;
F_9 ( V_5 ) ;
goto V_39;
V_38:
F_33 ( V_2 ) ;
V_36:
V_37:
F_34 ( V_2 ) ;
V_39:
return V_30 ;
}
void F_35 ( struct V_4 * V_5 )
{
F_36 ( & V_5 -> V_14 ) ;
F_37 ( & V_5 -> V_2 -> V_17 , L_3 ) ;
F_38 ( V_5 ) ;
F_39 ( V_5 -> V_2 ) ;
}
static int T_1 F_40 ( void )
{
V_16 = F_41 ( V_40 , L_6 ) ;
if ( F_42 ( V_16 ) )
return F_43 ( V_16 ) ;
V_16 -> V_41 = V_42 ;
F_44 ( & V_34 ) ;
return 0 ;
}
static void T_2 F_45 ( void )
{
F_46 ( V_16 ) ;
}
