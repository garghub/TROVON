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
F_7 ( & V_10 -> V_27 ) ;
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
F_7 ( & V_10 -> V_27 ) ;
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
T_2 V_36 ,
struct V_37 * * V_38 )
{
struct V_5 * V_11 ;
struct V_1 * V_2 ;
T_3 V_39 ;
T_4 V_40 ;
struct V_5 * V_41 ;
int error = - V_12 ;
struct V_9 * V_10 = NULL ;
struct V_37 * V_42 = NULL ;
if ( V_6 -> V_43 & V_44 ) {
V_11 = V_6 ;
} else {
if ( F_2 ( V_6 -> V_21 . V_29 -> V_45 != & V_46 ) )
return error ;
V_11 = F_11 ( V_6 -> V_21 . V_29 ) ;
}
V_2 = F_12 ( V_11 ) ;
* V_38 = NULL ;
error = F_19 ( V_2 , V_47 , & V_10 ) ;
if ( error < 0 )
return error ;
error = - V_12 ;
V_41 = V_10 -> V_25 ;
if ( F_2 ( ! V_41 ) )
goto V_48;
if ( V_41 -> V_15 . V_49 < V_50 ||
( V_41 -> V_15 . V_49 == V_50 &&
V_41 -> V_15 . V_51 < V_52 ) ) {
F_6 ( & V_41 -> V_21 ,
L_4 ,
V_41 -> V_15 . V_49 ,
V_41 -> V_15 . V_51 ) ;
error = - V_53 ;
goto V_48;
}
if ( F_2 ( V_41 -> V_15 . V_54 == 0 ) )
goto V_48;
V_39 = V_41 -> V_55 [ 0 ] . V_56 ;
V_40 = V_41 -> V_55 [ 0 ] . V_57 -
V_41 -> V_55 [ 0 ] . V_56 + 1 ;
if ( F_2 ( V_40 != V_11 -> V_42 -> V_58 ) )
goto V_48;
error = F_24 ( & V_11 -> V_21 ,
V_39 ,
V_40 , V_41 ,
V_36 , & V_42 ) ;
if ( error < 0 )
goto V_48;
* V_38 = V_42 ;
return 0 ;
V_48:
F_22 ( V_10 ) ;
return error ;
}
void F_25 ( struct V_37 * V_42 )
{
struct V_5 * V_41 ;
struct V_9 * V_10 ;
V_41 = V_42 -> V_41 ;
if ( F_2 ( ! V_41 ) )
return;
V_10 = V_41 -> V_10 ;
if ( F_2 ( ! V_10 || V_10 -> type != V_47 ) )
return;
if ( F_2 ( V_10 -> V_25 != V_41 ) )
return;
F_26 ( V_42 ) ;
F_22 ( V_10 ) ;
}
int F_27 ( struct V_37 * V_42 )
{
int error ;
struct V_5 * V_41 = V_42 -> V_41 ;
if ( F_2 ( ! V_41 ) )
return - V_12 ;
error = F_28 ( V_42 , 0 , V_41 -> V_59 ) ;
if ( error < 0 ) {
F_6 ( & V_41 -> V_21 , L_5 , error ) ;
return error ;
}
return 0 ;
}
int T_1 F_29 ( struct V_5 * V_6 ,
enum V_3 V_4 ,
struct V_5 * * V_60 )
{
struct V_5 * V_11 ;
struct V_1 * V_2 ;
struct V_5 * V_61 ;
int error = - V_12 ;
struct V_9 * V_10 = NULL ;
* V_60 = NULL ;
if ( F_2 ( V_6 -> V_43 & V_44 ) )
goto error;
if ( F_2 ( V_6 -> V_21 . V_29 -> V_45 != & V_46 ) )
goto error;
if ( F_2 ( V_4 == V_47 ) )
goto error;
V_11 = F_11 ( V_6 -> V_21 . V_29 ) ;
V_2 = F_12 ( V_11 ) ;
error = F_19 ( V_2 , V_4 , & V_10 ) ;
if ( error < 0 )
goto error;
V_61 = V_10 -> V_25 ;
if ( F_2 ( ! V_61 ) )
goto error;
* V_60 = V_61 ;
return 0 ;
error:
if ( V_10 )
F_22 ( V_10 ) ;
return error ;
}
void F_30 ( struct V_5 * V_61 )
{
struct V_9 * V_10 ;
V_10 = V_61 -> V_10 ;
if ( F_2 ( V_10 -> type == V_47 ) )
return;
if ( F_2 ( V_10 -> V_25 != V_61 ) )
return;
F_22 ( V_10 ) ;
}
int F_31 ( struct V_1 * V_2 ,
unsigned int V_62 )
{
unsigned int V_32 ;
struct V_63 * V_63 ;
struct V_64 * V_65 ;
struct V_64 * V_66 ;
int error ;
struct V_5 * V_11 = & V_2 -> V_6 ;
struct V_7 * V_8 =
& V_2 -> V_16 [ V_67 ] ;
if ( F_2 ( V_62 == 0 ||
V_62 > V_68 ) )
return - V_12 ;
error = F_32 ( & V_11 -> V_21 , V_62 ) ;
if ( error < 0 )
return error ;
V_65 = F_5 ( & V_11 -> V_21 ,
sizeof( * V_65 ) * V_62 ,
V_22 ) ;
if ( ! V_65 ) {
error = - V_23 ;
goto V_69;
}
for ( V_32 = 0 ; V_32 < V_62 ; V_32 ++ ) {
V_66 = & V_65 [ V_32 ] ;
V_66 -> V_10 . type = V_8 -> type ;
V_66 -> V_10 . V_25 = V_66 ;
V_66 -> V_10 . V_26 = V_8 ;
F_7 ( & V_66 -> V_10 . V_27 ) ;
F_8 ( & V_66 -> V_10 . V_27 , & V_8 -> V_28 ) ;
}
F_33 (msi_desc, &mc_bus_dev->dev) {
V_66 = & V_65 [ V_63 -> V_70 . V_71 ] ;
V_66 -> V_63 = V_63 ;
V_66 -> V_10 . V_24 = V_63 -> V_72 ;
}
V_8 -> V_18 = V_62 ;
V_8 -> V_20 = V_62 ;
V_2 -> V_65 = V_65 ;
return 0 ;
V_69:
F_34 ( & V_11 -> V_21 ) ;
return error ;
}
void F_35 ( struct V_1 * V_2 )
{
struct V_5 * V_11 = & V_2 -> V_6 ;
struct V_7 * V_8 =
& V_2 -> V_16 [ V_67 ] ;
if ( F_2 ( ! V_2 -> V_65 ) )
return;
if ( F_2 ( V_8 -> V_18 == 0 ) )
return;
if ( F_2 ( V_8 -> V_20 != V_8 -> V_18 ) )
return;
F_7 ( & V_8 -> V_28 ) ;
V_8 -> V_18 = 0 ;
V_8 -> V_20 = 0 ;
V_2 -> V_65 = NULL ;
F_34 ( & V_11 -> V_21 ) ;
}
int T_1 F_36 ( struct V_5 * V_6 )
{
int V_32 ;
int V_62 ;
int V_73 = 0 ;
int error = - V_12 ;
struct V_64 * * V_74 = NULL ;
struct V_1 * V_2 ;
struct V_7 * V_8 ;
if ( F_2 ( V_6 -> V_74 ) )
return - V_12 ;
V_62 = V_6 -> V_15 . V_62 ;
if ( F_2 ( V_62 == 0 ) )
return - V_12 ;
if ( strcmp ( V_6 -> V_15 . type , L_6 ) == 0 )
V_2 = F_12 ( V_6 ) ;
else
V_2 = F_12 ( F_11 ( V_6 -> V_21 . V_29 ) ) ;
if ( F_2 ( ! V_2 -> V_65 ) )
return - V_12 ;
V_8 = & V_2 -> V_16 [ V_67 ] ;
if ( V_8 -> V_20 < V_62 ) {
F_6 ( & V_6 -> V_21 ,
L_7 , V_62 ) ;
return - V_75 ;
}
V_74 = F_5 ( & V_6 -> V_21 , V_62 * sizeof( V_74 [ 0 ] ) ,
V_22 ) ;
if ( ! V_74 )
return - V_23 ;
for ( V_32 = 0 ; V_32 < V_62 ; V_32 ++ ) {
struct V_9 * V_10 ;
error = F_19 ( V_2 , V_67 ,
& V_10 ) ;
if ( error < 0 )
goto V_76;
V_74 [ V_32 ] = F_37 ( V_10 ) ;
V_73 ++ ;
F_2 ( V_74 [ V_32 ] -> V_6 ) ;
V_74 [ V_32 ] -> V_6 = V_6 ;
V_74 [ V_32 ] -> V_77 = V_32 ;
}
V_6 -> V_74 = V_74 ;
return 0 ;
V_76:
for ( V_32 = 0 ; V_32 < V_73 ; V_32 ++ ) {
V_74 [ V_32 ] -> V_6 = NULL ;
F_22 ( & V_74 [ V_32 ] -> V_10 ) ;
}
return error ;
}
void F_38 ( struct V_5 * V_6 )
{
int V_32 ;
int V_62 ;
struct V_1 * V_2 ;
struct V_64 * * V_74 = V_6 -> V_74 ;
if ( F_2 ( ! V_74 ) )
return;
V_62 = V_6 -> V_15 . V_62 ;
if ( strcmp ( V_6 -> V_15 . type , L_6 ) == 0 )
V_2 = F_12 ( V_6 ) ;
else
V_2 = F_12 ( F_11 ( V_6 -> V_21 . V_29 ) ) ;
if ( F_2 ( ! V_2 -> V_65 ) )
return;
for ( V_32 = 0 ; V_32 < V_62 ; V_32 ++ ) {
F_2 ( ! V_74 [ V_32 ] -> V_6 ) ;
V_74 [ V_32 ] -> V_6 = NULL ;
F_22 ( & V_74 [ V_32 ] -> V_10 ) ;
}
V_6 -> V_74 = NULL ;
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
if ( F_2 ( V_11 -> V_21 . V_45 != & V_46 ) )
return - V_12 ;
V_2 = F_12 ( V_11 ) ;
error = F_17 ( V_6 -> V_15 . type , & V_4 ) ;
if ( error < 0 )
return error ;
error = F_1 ( V_2 , V_4 , V_6 ) ;
if ( error < 0 )
return error ;
F_40 ( & V_6 -> V_21 ,
L_8 ) ;
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
L_9 ) ;
return 0 ;
}
int T_5 F_42 ( void )
{
return F_43 ( & V_78 ) ;
}
void F_44 ( void )
{
F_45 ( & V_78 ) ;
}
