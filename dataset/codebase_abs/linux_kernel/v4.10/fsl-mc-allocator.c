static int T_1 F_1 ( struct V_1
* V_2 ,
enum V_3
V_4 ,
struct V_5
* V_6 )
{
struct V_7 * V_8 ;
struct V_9 * V_10 ;
struct V_5 * V_11 = & V_2 -> V_6 ;
int error = - V_12 ;
if ( F_2 ( V_4 < 0 || V_4 >= V_13 ) )
goto V_14;
if ( F_2 ( ! F_3 ( V_6 -> V_15 . type ) ) )
goto V_14;
if ( F_2 ( V_6 -> V_10 ) )
goto V_14;
V_8 = & V_2 -> V_16 [ V_4 ] ;
if ( F_2 ( V_8 -> type != V_4 ) )
goto V_14;
if ( F_2 ( V_8 -> V_2 != V_2 ) )
goto V_14;
F_4 ( & V_8 -> V_17 ) ;
if ( F_2 ( V_8 -> V_18 < 0 ) )
goto V_19;
if ( F_2 ( V_8 -> V_20 < 0 ||
V_8 -> V_20 > V_8 -> V_18 ) )
goto V_19;
V_10 = F_5 ( & V_11 -> V_21 , sizeof( * V_10 ) ,
V_22 ) ;
if ( ! V_10 ) {
error = - V_23 ;
F_6 ( & V_11 -> V_21 ,
L_1 ) ;
goto V_19;
}
V_10 -> type = V_4 ;
V_10 -> V_24 = V_6 -> V_15 . V_24 ;
V_10 -> V_25 = V_6 ;
V_10 -> V_26 = V_8 ;
F_7 ( & V_10 -> V_27 ) ;
F_8 ( & V_10 -> V_27 , & V_8 -> V_28 ) ;
V_6 -> V_10 = V_10 ;
V_8 -> V_20 ++ ;
V_8 -> V_18 ++ ;
error = 0 ;
V_19:
F_9 ( & V_8 -> V_17 ) ;
V_14:
return error ;
}
static int T_1 F_10 ( struct V_5
* V_6 )
{
struct V_5 * V_11 ;
struct V_1 * V_2 ;
struct V_7 * V_8 ;
struct V_9 * V_10 ;
int error = - V_12 ;
if ( F_2 ( ! F_3 ( V_6 -> V_15 . type ) ) )
goto V_14;
V_10 = V_6 -> V_10 ;
if ( F_2 ( ! V_10 || V_10 -> V_25 != V_6 ) )
goto V_14;
V_11 = F_11 ( V_6 -> V_21 . V_29 ) ;
V_2 = F_12 ( V_11 ) ;
V_8 = V_10 -> V_26 ;
if ( F_2 ( V_8 != & V_2 -> V_16 [ V_10 -> type ] ) )
goto V_14;
F_4 ( & V_8 -> V_17 ) ;
if ( F_2 ( V_8 -> V_18 <= 0 ) )
goto V_19;
if ( F_2 ( V_8 -> V_20 <= 0 ||
V_8 -> V_20 > V_8 -> V_18 ) )
goto V_19;
if ( F_13 ( & V_10 -> V_27 ) ) {
error = - V_30 ;
F_6 ( & V_11 -> V_21 ,
L_2 ,
F_14 ( & V_6 -> V_21 ) ) ;
goto V_19;
}
F_15 ( & V_10 -> V_27 ) ;
V_8 -> V_20 -- ;
V_8 -> V_18 -- ;
F_16 ( & V_11 -> V_21 , V_10 ) ;
V_6 -> V_10 = NULL ;
error = 0 ;
V_19:
F_9 ( & V_8 -> V_17 ) ;
V_14:
return error ;
}
static int T_1 F_17 ( const char * V_31 ,
enum V_3
* V_4 )
{
unsigned int V_32 ;
for ( V_32 = 0 ; V_32 < F_18 ( V_33 ) ; V_32 ++ ) {
if ( strcmp ( V_31 , V_33 [ V_32 ] ) == 0 ) {
* V_4 = V_32 ;
return 0 ;
}
}
return - V_12 ;
}
int T_1 F_19 ( struct V_1 * V_2 ,
enum V_3 V_4 ,
struct V_9 * * V_34 )
{
struct V_7 * V_8 ;
struct V_9 * V_10 ;
struct V_5 * V_11 = & V_2 -> V_6 ;
int error = - V_12 ;
F_20 ( F_18 ( V_33 ) !=
V_13 ) ;
* V_34 = NULL ;
if ( F_2 ( V_4 < 0 || V_4 >= V_13 ) )
goto V_14;
V_8 = & V_2 -> V_16 [ V_4 ] ;
if ( F_2 ( V_8 -> V_2 != V_2 ) )
goto V_14;
F_4 ( & V_8 -> V_17 ) ;
V_10 = F_21 ( & V_8 -> V_28 ,
struct V_9 , V_27 ) ;
if ( ! V_10 ) {
F_2 ( V_8 -> V_20 != 0 ) ;
error = - V_35 ;
F_6 ( & V_11 -> V_21 ,
L_3 ,
V_33 [ V_4 ] ) ;
goto V_19;
}
if ( F_2 ( V_10 -> type != V_4 ) )
goto V_19;
if ( F_2 ( V_10 -> V_26 != V_8 ) )
goto V_19;
if ( F_2 ( V_8 -> V_20 <= 0 ||
V_8 -> V_20 > V_8 -> V_18 ) )
goto V_19;
F_15 ( & V_10 -> V_27 ) ;
V_8 -> V_20 -- ;
error = 0 ;
V_19:
F_9 ( & V_8 -> V_17 ) ;
* V_34 = V_10 ;
V_14:
return error ;
}
void F_22 ( struct V_9 * V_10 )
{
struct V_7 * V_8 ;
V_8 = V_10 -> V_26 ;
if ( F_2 ( V_10 -> type != V_8 -> type ) )
return;
F_4 ( & V_8 -> V_17 ) ;
if ( F_2 ( V_8 -> V_20 < 0 ||
V_8 -> V_20 >= V_8 -> V_18 ) )
goto V_19;
if ( F_2 ( ! F_13 ( & V_10 -> V_27 ) ) )
goto V_19;
F_8 ( & V_10 -> V_27 , & V_8 -> V_28 ) ;
V_8 -> V_20 ++ ;
V_19:
F_9 ( & V_8 -> V_17 ) ;
}
int T_1 F_23 ( struct V_5 * V_6 ,
enum V_3 V_4 ,
struct V_5 * * V_36 )
{
struct V_5 * V_11 ;
struct V_1 * V_2 ;
struct V_5 * V_37 ;
int error = - V_12 ;
struct V_9 * V_10 = NULL ;
* V_36 = NULL ;
if ( F_2 ( V_6 -> V_38 & V_39 ) )
goto error;
if ( F_2 ( ! F_24 ( V_6 -> V_21 . V_29 ) ) )
goto error;
if ( F_2 ( V_4 == V_40 ) )
goto error;
V_11 = F_11 ( V_6 -> V_21 . V_29 ) ;
V_2 = F_12 ( V_11 ) ;
error = F_19 ( V_2 , V_4 , & V_10 ) ;
if ( error < 0 )
goto error;
V_37 = V_10 -> V_25 ;
if ( F_2 ( ! V_37 ) )
goto error;
* V_36 = V_37 ;
return 0 ;
error:
if ( V_10 )
F_22 ( V_10 ) ;
return error ;
}
void F_25 ( struct V_5 * V_37 )
{
struct V_9 * V_10 ;
V_10 = V_37 -> V_10 ;
if ( F_2 ( V_10 -> type == V_40 ) )
return;
if ( F_2 ( V_10 -> V_25 != V_37 ) )
return;
F_22 ( V_10 ) ;
}
int F_26 ( struct V_1 * V_2 ,
unsigned int V_41 )
{
unsigned int V_32 ;
struct V_42 * V_42 ;
struct V_43 * V_44 ;
struct V_43 * V_45 ;
int error ;
struct V_5 * V_11 = & V_2 -> V_6 ;
struct V_7 * V_8 =
& V_2 -> V_16 [ V_46 ] ;
if ( F_2 ( V_41 == 0 ||
V_41 > V_47 ) )
return - V_12 ;
error = F_27 ( & V_11 -> V_21 , V_41 ) ;
if ( error < 0 )
return error ;
V_44 = F_5 ( & V_11 -> V_21 ,
sizeof( * V_44 ) * V_41 ,
V_22 ) ;
if ( ! V_44 ) {
error = - V_23 ;
goto V_48;
}
for ( V_32 = 0 ; V_32 < V_41 ; V_32 ++ ) {
V_45 = & V_44 [ V_32 ] ;
V_45 -> V_10 . type = V_8 -> type ;
V_45 -> V_10 . V_25 = V_45 ;
V_45 -> V_10 . V_26 = V_8 ;
F_7 ( & V_45 -> V_10 . V_27 ) ;
F_8 ( & V_45 -> V_10 . V_27 , & V_8 -> V_28 ) ;
}
F_28 (msi_desc, &mc_bus_dev->dev) {
V_45 = & V_44 [ V_42 -> V_49 . V_50 ] ;
V_45 -> V_42 = V_42 ;
V_45 -> V_10 . V_24 = V_42 -> V_51 ;
}
V_8 -> V_18 = V_41 ;
V_8 -> V_20 = V_41 ;
V_2 -> V_44 = V_44 ;
return 0 ;
V_48:
F_29 ( & V_11 -> V_21 ) ;
return error ;
}
void F_30 ( struct V_1 * V_2 )
{
struct V_5 * V_11 = & V_2 -> V_6 ;
struct V_7 * V_8 =
& V_2 -> V_16 [ V_46 ] ;
if ( F_2 ( ! V_2 -> V_44 ) )
return;
if ( F_2 ( V_8 -> V_18 == 0 ) )
return;
if ( F_2 ( V_8 -> V_20 != V_8 -> V_18 ) )
return;
F_7 ( & V_8 -> V_28 ) ;
V_8 -> V_18 = 0 ;
V_8 -> V_20 = 0 ;
V_2 -> V_44 = NULL ;
F_29 ( & V_11 -> V_21 ) ;
}
int T_1 F_31 ( struct V_5 * V_6 )
{
int V_32 ;
int V_41 ;
int V_52 = 0 ;
int error = - V_12 ;
struct V_43 * * V_53 = NULL ;
struct V_1 * V_2 ;
struct V_7 * V_8 ;
if ( F_2 ( V_6 -> V_53 ) )
return - V_12 ;
V_41 = V_6 -> V_15 . V_41 ;
if ( F_2 ( V_41 == 0 ) )
return - V_12 ;
if ( strcmp ( V_6 -> V_15 . type , L_4 ) == 0 )
V_2 = F_12 ( V_6 ) ;
else
V_2 = F_12 ( F_11 ( V_6 -> V_21 . V_29 ) ) ;
if ( F_2 ( ! V_2 -> V_44 ) )
return - V_12 ;
V_8 = & V_2 -> V_16 [ V_46 ] ;
if ( V_8 -> V_20 < V_41 ) {
F_6 ( & V_6 -> V_21 ,
L_5 , V_41 ) ;
return - V_54 ;
}
V_53 = F_5 ( & V_6 -> V_21 , V_41 * sizeof( V_53 [ 0 ] ) ,
V_22 ) ;
if ( ! V_53 )
return - V_23 ;
for ( V_32 = 0 ; V_32 < V_41 ; V_32 ++ ) {
struct V_9 * V_10 ;
error = F_19 ( V_2 , V_46 ,
& V_10 ) ;
if ( error < 0 )
goto V_55;
V_53 [ V_32 ] = F_32 ( V_10 ) ;
V_52 ++ ;
F_2 ( V_53 [ V_32 ] -> V_6 ) ;
V_53 [ V_32 ] -> V_6 = V_6 ;
V_53 [ V_32 ] -> V_56 = V_32 ;
}
V_6 -> V_53 = V_53 ;
return 0 ;
V_55:
for ( V_32 = 0 ; V_32 < V_52 ; V_32 ++ ) {
V_53 [ V_32 ] -> V_6 = NULL ;
F_22 ( & V_53 [ V_32 ] -> V_10 ) ;
}
return error ;
}
void F_33 ( struct V_5 * V_6 )
{
int V_32 ;
int V_41 ;
struct V_1 * V_2 ;
struct V_43 * * V_53 = V_6 -> V_53 ;
if ( F_2 ( ! V_53 ) )
return;
V_41 = V_6 -> V_15 . V_41 ;
if ( strcmp ( V_6 -> V_15 . type , L_4 ) == 0 )
V_2 = F_12 ( V_6 ) ;
else
V_2 = F_12 ( F_11 ( V_6 -> V_21 . V_29 ) ) ;
if ( F_2 ( ! V_2 -> V_44 ) )
return;
for ( V_32 = 0 ; V_32 < V_41 ; V_32 ++ ) {
F_2 ( ! V_53 [ V_32 ] -> V_6 ) ;
V_53 [ V_32 ] -> V_6 = NULL ;
F_22 ( & V_53 [ V_32 ] -> V_10 ) ;
}
V_6 -> V_53 = NULL ;
}
void F_34 ( struct V_5 * V_11 )
{
int V_4 ;
struct V_1 * V_2 = F_12 ( V_11 ) ;
for ( V_4 = 0 ; V_4 < V_13 ; V_4 ++ ) {
struct V_7 * V_8 =
& V_2 -> V_16 [ V_4 ] ;
V_8 -> type = V_4 ;
V_8 -> V_18 = 0 ;
V_8 -> V_20 = 0 ;
V_8 -> V_2 = V_2 ;
F_7 ( & V_8 -> V_28 ) ;
F_35 ( & V_8 -> V_17 ) ;
}
}
static void F_36 ( struct V_5 * V_11 ,
enum V_3 V_4 )
{
struct V_9 * V_10 ;
struct V_9 * V_57 ;
struct V_1 * V_2 = F_12 ( V_11 ) ;
struct V_7 * V_8 =
& V_2 -> V_16 [ V_4 ] ;
int V_20 = 0 ;
F_2 ( V_8 -> type != V_4 ) ;
F_2 ( V_8 -> V_20 != V_8 -> V_18 ) ;
F_37 (resource, next, &res_pool->free_list, node) {
V_20 ++ ;
F_2 ( V_10 -> type != V_8 -> type ) ;
F_2 ( V_10 -> V_26 != V_8 ) ;
F_16 ( & V_11 -> V_21 , V_10 ) ;
}
F_2 ( V_20 != V_8 -> V_20 ) ;
}
void F_38 ( struct V_5 * V_11 )
{
int V_4 ;
for ( V_4 = 0 ; V_4 < V_13 ; V_4 ++ )
F_36 ( V_11 , V_4 ) ;
}
static int F_39 ( struct V_5 * V_6 )
{
enum V_3 V_4 ;
struct V_5 * V_11 ;
struct V_1 * V_2 ;
int error ;
if ( F_2 ( ! F_3 ( V_6 -> V_15 . type ) ) )
return - V_12 ;
V_11 = F_11 ( V_6 -> V_21 . V_29 ) ;
if ( F_2 ( ! F_24 ( & V_11 -> V_21 ) ) )
return - V_12 ;
V_2 = F_12 ( V_11 ) ;
error = F_17 ( V_6 -> V_15 . type , & V_4 ) ;
if ( error < 0 )
return error ;
error = F_1 ( V_2 , V_4 , V_6 ) ;
if ( error < 0 )
return error ;
F_40 ( & V_6 -> V_21 ,
L_6 ) ;
return 0 ;
}
static int F_41 ( struct V_5 * V_6 )
{
int error ;
if ( F_2 ( ! F_3 ( V_6 -> V_15 . type ) ) )
return - V_12 ;
if ( V_6 -> V_10 ) {
error = F_10 ( V_6 ) ;
if ( error < 0 )
return error ;
}
F_40 ( & V_6 -> V_21 ,
L_7 ) ;
return 0 ;
}
int T_2 F_42 ( void )
{
return F_43 ( & V_58 ) ;
}
void F_44 ( void )
{
F_45 ( & V_58 ) ;
}
