static bool T_1 F_1 ( const char * V_1 )
{
return strcmp ( V_1 , L_1 ) == 0 ||
strcmp ( V_1 , L_2 ) == 0 ||
strcmp ( V_1 , L_3 ) == 0 ;
}
static int T_1 F_2 ( struct V_2
* V_3 ,
enum V_4
V_5 ,
struct V_6
* V_7 )
{
struct V_8 * V_9 ;
struct V_10 * V_11 ;
struct V_6 * V_12 = & V_3 -> V_7 ;
int error = - V_13 ;
if ( F_3 ( V_5 < 0 || V_5 >= V_14 ) )
goto V_15;
if ( F_3 ( ! F_1 ( V_7 -> V_16 . type ) ) )
goto V_15;
if ( F_3 ( V_7 -> V_11 ) )
goto V_15;
V_9 = & V_3 -> V_17 [ V_5 ] ;
if ( F_3 ( V_9 -> type != V_5 ) )
goto V_15;
if ( F_3 ( V_9 -> V_3 != V_3 ) )
goto V_15;
F_4 ( & V_9 -> V_18 ) ;
if ( F_3 ( V_9 -> V_19 < 0 ) )
goto V_20;
if ( F_3 ( V_9 -> V_21 < 0 ||
V_9 -> V_21 > V_9 -> V_19 ) )
goto V_20;
V_11 = F_5 ( & V_12 -> V_22 , sizeof( * V_11 ) ,
V_23 ) ;
if ( ! V_11 ) {
error = - V_24 ;
F_6 ( & V_12 -> V_22 ,
L_4 ) ;
goto V_20;
}
V_11 -> type = V_5 ;
V_11 -> V_25 = V_7 -> V_16 . V_25 ;
V_11 -> V_26 = V_7 ;
V_11 -> V_27 = V_9 ;
F_7 ( & V_11 -> V_28 ) ;
F_8 ( & V_11 -> V_28 , & V_9 -> V_29 ) ;
V_7 -> V_11 = V_11 ;
V_9 -> V_21 ++ ;
V_9 -> V_19 ++ ;
error = 0 ;
V_20:
F_9 ( & V_9 -> V_18 ) ;
V_15:
return error ;
}
static int T_1 F_10 ( struct V_6
* V_7 )
{
struct V_6 * V_12 ;
struct V_2 * V_3 ;
struct V_8 * V_9 ;
struct V_10 * V_11 ;
int error = - V_13 ;
if ( F_3 ( ! F_1 ( V_7 -> V_16 . type ) ) )
goto V_15;
V_11 = V_7 -> V_11 ;
if ( F_3 ( ! V_11 || V_11 -> V_26 != V_7 ) )
goto V_15;
V_12 = F_11 ( V_7 -> V_22 . V_30 ) ;
V_3 = F_12 ( V_12 ) ;
V_9 = V_11 -> V_27 ;
if ( F_3 ( V_9 != & V_3 -> V_17 [ V_11 -> type ] ) )
goto V_15;
F_4 ( & V_9 -> V_18 ) ;
if ( F_3 ( V_9 -> V_19 <= 0 ) )
goto V_20;
if ( F_3 ( V_9 -> V_21 <= 0 ||
V_9 -> V_21 > V_9 -> V_19 ) )
goto V_20;
if ( F_13 ( & V_11 -> V_28 ) ) {
error = - V_31 ;
F_6 ( & V_12 -> V_22 ,
L_5 ,
F_14 ( & V_7 -> V_22 ) ) ;
goto V_20;
}
F_15 ( & V_11 -> V_28 ) ;
V_9 -> V_21 -- ;
V_9 -> V_19 -- ;
F_16 ( & V_12 -> V_22 , V_11 ) ;
V_7 -> V_11 = NULL ;
error = 0 ;
V_20:
F_9 ( & V_9 -> V_18 ) ;
V_15:
return error ;
}
static int T_1 F_17 ( const char * V_32 ,
enum V_4
* V_5 )
{
unsigned int V_33 ;
for ( V_33 = 0 ; V_33 < F_18 ( V_34 ) ; V_33 ++ ) {
if ( strcmp ( V_32 , V_34 [ V_33 ] ) == 0 ) {
* V_5 = V_33 ;
return 0 ;
}
}
return - V_13 ;
}
int T_1 F_19 ( struct V_2 * V_3 ,
enum V_4 V_5 ,
struct V_10 * * V_35 )
{
struct V_8 * V_9 ;
struct V_10 * V_11 ;
struct V_6 * V_12 = & V_3 -> V_7 ;
int error = - V_13 ;
F_20 ( F_18 ( V_34 ) !=
V_14 ) ;
* V_35 = NULL ;
if ( F_3 ( V_5 < 0 || V_5 >= V_14 ) )
goto V_15;
V_9 = & V_3 -> V_17 [ V_5 ] ;
if ( F_3 ( V_9 -> V_3 != V_3 ) )
goto V_15;
F_4 ( & V_9 -> V_18 ) ;
V_11 = F_21 ( & V_9 -> V_29 ,
struct V_10 , V_28 ) ;
if ( ! V_11 ) {
F_3 ( V_9 -> V_21 != 0 ) ;
error = - V_36 ;
F_6 ( & V_12 -> V_22 ,
L_6 ,
V_34 [ V_5 ] ) ;
goto V_20;
}
if ( F_3 ( V_11 -> type != V_5 ) )
goto V_20;
if ( F_3 ( V_11 -> V_27 != V_9 ) )
goto V_20;
if ( F_3 ( V_9 -> V_21 <= 0 ||
V_9 -> V_21 > V_9 -> V_19 ) )
goto V_20;
F_15 ( & V_11 -> V_28 ) ;
V_9 -> V_21 -- ;
error = 0 ;
V_20:
F_9 ( & V_9 -> V_18 ) ;
* V_35 = V_11 ;
V_15:
return error ;
}
void F_22 ( struct V_10 * V_11 )
{
struct V_8 * V_9 ;
V_9 = V_11 -> V_27 ;
if ( F_3 ( V_11 -> type != V_9 -> type ) )
return;
F_4 ( & V_9 -> V_18 ) ;
if ( F_3 ( V_9 -> V_21 < 0 ||
V_9 -> V_21 >= V_9 -> V_19 ) )
goto V_20;
if ( F_3 ( ! F_13 ( & V_11 -> V_28 ) ) )
goto V_20;
F_8 ( & V_11 -> V_28 , & V_9 -> V_29 ) ;
V_9 -> V_21 ++ ;
V_20:
F_9 ( & V_9 -> V_18 ) ;
}
int T_1 F_23 ( struct V_6 * V_7 ,
enum V_4 V_5 ,
struct V_6 * * V_37 )
{
struct V_6 * V_12 ;
struct V_2 * V_3 ;
struct V_6 * V_38 ;
int error = - V_13 ;
struct V_10 * V_11 = NULL ;
* V_37 = NULL ;
if ( F_3 ( V_7 -> V_39 & V_40 ) )
goto error;
if ( F_3 ( ! F_24 ( V_7 -> V_22 . V_30 ) ) )
goto error;
if ( F_3 ( V_5 == V_41 ) )
goto error;
V_12 = F_11 ( V_7 -> V_22 . V_30 ) ;
V_3 = F_12 ( V_12 ) ;
error = F_19 ( V_3 , V_5 , & V_11 ) ;
if ( error < 0 )
goto error;
V_38 = V_11 -> V_26 ;
if ( F_3 ( ! V_38 ) )
goto error;
* V_37 = V_38 ;
return 0 ;
error:
if ( V_11 )
F_22 ( V_11 ) ;
return error ;
}
void F_25 ( struct V_6 * V_38 )
{
struct V_10 * V_11 ;
V_11 = V_38 -> V_11 ;
if ( F_3 ( V_11 -> type == V_41 ) )
return;
if ( F_3 ( V_11 -> V_26 != V_38 ) )
return;
F_22 ( V_11 ) ;
}
int F_26 ( struct V_2 * V_3 ,
unsigned int V_42 )
{
unsigned int V_33 ;
struct V_43 * V_43 ;
struct V_44 * V_45 ;
struct V_44 * V_46 ;
int error ;
struct V_6 * V_12 = & V_3 -> V_7 ;
struct V_8 * V_9 =
& V_3 -> V_17 [ V_47 ] ;
if ( F_3 ( V_42 == 0 ||
V_42 > V_48 ) )
return - V_13 ;
error = F_27 ( & V_12 -> V_22 , V_42 ) ;
if ( error < 0 )
return error ;
V_45 = F_5 ( & V_12 -> V_22 ,
sizeof( * V_45 ) * V_42 ,
V_23 ) ;
if ( ! V_45 ) {
error = - V_24 ;
goto V_49;
}
for ( V_33 = 0 ; V_33 < V_42 ; V_33 ++ ) {
V_46 = & V_45 [ V_33 ] ;
V_46 -> V_11 . type = V_9 -> type ;
V_46 -> V_11 . V_26 = V_46 ;
V_46 -> V_11 . V_27 = V_9 ;
F_7 ( & V_46 -> V_11 . V_28 ) ;
F_8 ( & V_46 -> V_11 . V_28 , & V_9 -> V_29 ) ;
}
F_28 (msi_desc, &mc_bus_dev->dev) {
V_46 = & V_45 [ V_43 -> V_50 . V_51 ] ;
V_46 -> V_43 = V_43 ;
V_46 -> V_11 . V_25 = V_43 -> V_52 ;
}
V_9 -> V_19 = V_42 ;
V_9 -> V_21 = V_42 ;
V_3 -> V_45 = V_45 ;
return 0 ;
V_49:
F_29 ( & V_12 -> V_22 ) ;
return error ;
}
void F_30 ( struct V_2 * V_3 )
{
struct V_6 * V_12 = & V_3 -> V_7 ;
struct V_8 * V_9 =
& V_3 -> V_17 [ V_47 ] ;
if ( F_3 ( ! V_3 -> V_45 ) )
return;
if ( F_3 ( V_9 -> V_19 == 0 ) )
return;
if ( F_3 ( V_9 -> V_21 != V_9 -> V_19 ) )
return;
F_7 ( & V_9 -> V_29 ) ;
V_9 -> V_19 = 0 ;
V_9 -> V_21 = 0 ;
V_3 -> V_45 = NULL ;
F_29 ( & V_12 -> V_22 ) ;
}
int T_1 F_31 ( struct V_6 * V_7 )
{
int V_33 ;
int V_42 ;
int V_53 = 0 ;
int error = - V_13 ;
struct V_44 * * V_54 = NULL ;
struct V_2 * V_3 ;
struct V_8 * V_9 ;
if ( F_3 ( V_7 -> V_54 ) )
return - V_13 ;
V_42 = V_7 -> V_16 . V_42 ;
if ( F_3 ( V_42 == 0 ) )
return - V_13 ;
if ( strcmp ( V_7 -> V_16 . type , L_7 ) == 0 )
V_3 = F_12 ( V_7 ) ;
else
V_3 = F_12 ( F_11 ( V_7 -> V_22 . V_30 ) ) ;
if ( F_3 ( ! V_3 -> V_45 ) )
return - V_13 ;
V_9 = & V_3 -> V_17 [ V_47 ] ;
if ( V_9 -> V_21 < V_42 ) {
F_6 ( & V_7 -> V_22 ,
L_8 , V_42 ) ;
return - V_55 ;
}
V_54 = F_5 ( & V_7 -> V_22 , V_42 * sizeof( V_54 [ 0 ] ) ,
V_23 ) ;
if ( ! V_54 )
return - V_24 ;
for ( V_33 = 0 ; V_33 < V_42 ; V_33 ++ ) {
struct V_10 * V_11 ;
error = F_19 ( V_3 , V_47 ,
& V_11 ) ;
if ( error < 0 )
goto V_56;
V_54 [ V_33 ] = F_32 ( V_11 ) ;
V_53 ++ ;
F_3 ( V_54 [ V_33 ] -> V_7 ) ;
V_54 [ V_33 ] -> V_7 = V_7 ;
V_54 [ V_33 ] -> V_57 = V_33 ;
}
V_7 -> V_54 = V_54 ;
return 0 ;
V_56:
for ( V_33 = 0 ; V_33 < V_53 ; V_33 ++ ) {
V_54 [ V_33 ] -> V_7 = NULL ;
F_22 ( & V_54 [ V_33 ] -> V_11 ) ;
}
return error ;
}
void F_33 ( struct V_6 * V_7 )
{
int V_33 ;
int V_42 ;
struct V_2 * V_3 ;
struct V_44 * * V_54 = V_7 -> V_54 ;
if ( F_3 ( ! V_54 ) )
return;
V_42 = V_7 -> V_16 . V_42 ;
if ( strcmp ( V_7 -> V_16 . type , L_7 ) == 0 )
V_3 = F_12 ( V_7 ) ;
else
V_3 = F_12 ( F_11 ( V_7 -> V_22 . V_30 ) ) ;
if ( F_3 ( ! V_3 -> V_45 ) )
return;
for ( V_33 = 0 ; V_33 < V_42 ; V_33 ++ ) {
F_3 ( ! V_54 [ V_33 ] -> V_7 ) ;
V_54 [ V_33 ] -> V_7 = NULL ;
F_22 ( & V_54 [ V_33 ] -> V_11 ) ;
}
V_7 -> V_54 = NULL ;
}
void F_34 ( struct V_6 * V_12 )
{
int V_5 ;
struct V_2 * V_3 = F_12 ( V_12 ) ;
for ( V_5 = 0 ; V_5 < V_14 ; V_5 ++ ) {
struct V_8 * V_9 =
& V_3 -> V_17 [ V_5 ] ;
V_9 -> type = V_5 ;
V_9 -> V_19 = 0 ;
V_9 -> V_21 = 0 ;
V_9 -> V_3 = V_3 ;
F_7 ( & V_9 -> V_29 ) ;
F_35 ( & V_9 -> V_18 ) ;
}
}
static void F_36 ( struct V_6 * V_12 ,
enum V_4 V_5 )
{
struct V_10 * V_11 ;
struct V_10 * V_58 ;
struct V_2 * V_3 = F_12 ( V_12 ) ;
struct V_8 * V_9 =
& V_3 -> V_17 [ V_5 ] ;
int V_21 = 0 ;
F_3 ( V_9 -> type != V_5 ) ;
F_3 ( V_9 -> V_21 != V_9 -> V_19 ) ;
F_37 (resource, next, &res_pool->free_list, node) {
V_21 ++ ;
F_3 ( V_11 -> type != V_9 -> type ) ;
F_3 ( V_11 -> V_27 != V_9 ) ;
F_16 ( & V_12 -> V_22 , V_11 ) ;
}
F_3 ( V_21 != V_9 -> V_21 ) ;
}
void F_38 ( struct V_6 * V_12 )
{
int V_5 ;
for ( V_5 = 0 ; V_5 < V_14 ; V_5 ++ )
F_36 ( V_12 , V_5 ) ;
}
static int F_39 ( struct V_6 * V_7 )
{
enum V_4 V_5 ;
struct V_6 * V_12 ;
struct V_2 * V_3 ;
int error ;
if ( F_3 ( ! F_1 ( V_7 -> V_16 . type ) ) )
return - V_13 ;
V_12 = F_11 ( V_7 -> V_22 . V_30 ) ;
if ( F_3 ( ! F_24 ( & V_12 -> V_22 ) ) )
return - V_13 ;
V_3 = F_12 ( V_12 ) ;
error = F_17 ( V_7 -> V_16 . type , & V_5 ) ;
if ( error < 0 )
return error ;
error = F_2 ( V_3 , V_5 , V_7 ) ;
if ( error < 0 )
return error ;
F_40 ( & V_7 -> V_22 ,
L_9 ) ;
return 0 ;
}
static int F_41 ( struct V_6 * V_7 )
{
int error ;
if ( F_3 ( ! F_1 ( V_7 -> V_16 . type ) ) )
return - V_13 ;
if ( V_7 -> V_11 ) {
error = F_10 ( V_7 ) ;
if ( error < 0 )
return error ;
}
F_40 ( & V_7 -> V_22 ,
L_10 ) ;
return 0 ;
}
int T_2 F_42 ( void )
{
return F_43 ( & V_59 ) ;
}
void F_44 ( void )
{
F_45 ( & V_59 ) ;
}
