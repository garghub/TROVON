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
bool V_13 = false ;
if ( F_2 ( V_4 < 0 || V_4 >= V_14 ) )
goto V_15;
if ( F_2 ( ! F_3 ( V_6 -> V_16 . type ) ) )
goto V_15;
if ( F_2 ( V_6 -> V_10 ) )
goto V_15;
V_8 = & V_2 -> V_17 [ V_4 ] ;
if ( F_2 ( V_8 -> type != V_4 ) )
goto V_15;
if ( F_2 ( V_8 -> V_2 != V_2 ) )
goto V_15;
F_4 ( & V_8 -> V_18 ) ;
V_13 = true ;
if ( F_2 ( V_8 -> V_19 < 0 ) )
goto V_15;
if ( F_2 ( V_8 -> V_20 < 0 ||
V_8 -> V_20 > V_8 -> V_19 ) )
goto V_15;
V_10 = F_5 ( & V_11 -> V_21 , sizeof( * V_10 ) ,
V_22 ) ;
if ( ! V_10 ) {
error = - V_23 ;
F_6 ( & V_11 -> V_21 ,
L_1 ) ;
goto V_15;
}
V_10 -> type = V_4 ;
V_10 -> V_24 = V_6 -> V_16 . V_24 ;
V_10 -> V_25 = V_6 ;
V_10 -> V_26 = V_8 ;
F_7 ( & V_10 -> V_27 ) ;
F_8 ( & V_10 -> V_27 , & V_8 -> V_28 ) ;
V_6 -> V_10 = V_10 ;
V_8 -> V_20 ++ ;
V_8 -> V_19 ++ ;
error = 0 ;
V_15:
if ( V_13 )
F_9 ( & V_8 -> V_18 ) ;
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
bool V_13 = false ;
if ( F_2 ( ! F_3 ( V_6 -> V_16 . type ) ) )
goto V_15;
V_10 = V_6 -> V_10 ;
if ( F_2 ( ! V_10 || V_10 -> V_25 != V_6 ) )
goto V_15;
V_11 = F_11 ( V_6 -> V_21 . V_29 ) ;
V_2 = F_12 ( V_11 ) ;
V_8 = V_10 -> V_26 ;
if ( F_2 ( V_8 != & V_2 -> V_17 [ V_10 -> type ] ) )
goto V_15;
F_4 ( & V_8 -> V_18 ) ;
V_13 = true ;
if ( F_2 ( V_8 -> V_19 <= 0 ) )
goto V_15;
if ( F_2 ( V_8 -> V_20 <= 0 ||
V_8 -> V_20 > V_8 -> V_19 ) )
goto V_15;
if ( F_13 ( & V_10 -> V_27 ) ) {
error = - V_30 ;
F_6 ( & V_11 -> V_21 ,
L_2 ,
F_14 ( & V_6 -> V_21 ) ) ;
goto V_15;
}
F_15 ( & V_10 -> V_27 ) ;
F_7 ( & V_10 -> V_27 ) ;
V_8 -> V_20 -- ;
V_8 -> V_19 -- ;
F_16 ( & V_11 -> V_21 , V_10 ) ;
V_6 -> V_10 = NULL ;
error = 0 ;
V_15:
if ( V_13 )
F_9 ( & V_8 -> V_18 ) ;
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
bool V_13 = false ;
F_20 ( F_18 ( V_33 ) !=
V_14 ) ;
* V_34 = NULL ;
if ( F_2 ( V_4 < 0 || V_4 >= V_14 ) )
goto error;
V_8 = & V_2 -> V_17 [ V_4 ] ;
if ( F_2 ( V_8 -> V_2 != V_2 ) )
goto error;
F_4 ( & V_8 -> V_18 ) ;
V_13 = true ;
V_10 = F_21 ( & V_8 -> V_28 ,
struct V_9 , V_27 ) ;
if ( ! V_10 ) {
F_2 ( V_8 -> V_20 != 0 ) ;
error = - V_35 ;
F_6 ( & V_11 -> V_21 ,
L_3 ,
V_33 [ V_4 ] ) ;
goto error;
}
if ( F_2 ( V_10 -> type != V_4 ) )
goto error;
if ( F_2 ( V_10 -> V_26 != V_8 ) )
goto error;
if ( F_2 ( V_8 -> V_20 <= 0 ||
V_8 -> V_20 > V_8 -> V_19 ) )
goto error;
F_15 ( & V_10 -> V_27 ) ;
F_7 ( & V_10 -> V_27 ) ;
V_8 -> V_20 -- ;
F_9 ( & V_8 -> V_18 ) ;
* V_34 = V_10 ;
return 0 ;
error:
if ( V_13 )
F_9 ( & V_8 -> V_18 ) ;
return error ;
}
void F_22 ( struct V_9 * V_10 )
{
struct V_7 * V_8 ;
bool V_13 = false ;
V_8 = V_10 -> V_26 ;
if ( F_2 ( V_10 -> type != V_8 -> type ) )
goto V_15;
F_4 ( & V_8 -> V_18 ) ;
V_13 = true ;
if ( F_2 ( V_8 -> V_20 < 0 ||
V_8 -> V_20 >= V_8 -> V_19 ) )
goto V_15;
if ( F_2 ( ! F_13 ( & V_10 -> V_27 ) ) )
goto V_15;
F_8 ( & V_10 -> V_27 , & V_8 -> V_28 ) ;
V_8 -> V_20 ++ ;
V_15:
if ( V_13 )
F_9 ( & V_8 -> V_18 ) ;
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
V_41 = V_10 -> V_25 ;
if ( F_2 ( ! V_41 ) )
goto V_48;
if ( F_2 ( V_41 -> V_16 . V_49 == 0 ) )
goto V_48;
V_39 = V_41 -> V_50 [ 0 ] . V_51 ;
V_40 = V_41 -> V_50 [ 0 ] . V_52 -
V_41 -> V_50 [ 0 ] . V_51 + 1 ;
if ( F_2 ( V_40 != V_11 -> V_42 -> V_53 ) )
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
error = F_28 ( V_42 , 0 , V_41 -> V_54 ) ;
if ( error < 0 ) {
F_6 ( & V_41 -> V_21 , L_4 , error ) ;
return error ;
}
return 0 ;
}
int T_1 F_29 ( struct V_5 * V_6 ,
enum V_3 V_4 ,
struct V_5 * * V_55 )
{
struct V_5 * V_11 ;
struct V_1 * V_2 ;
struct V_5 * V_56 ;
int error = - V_12 ;
struct V_9 * V_10 = NULL ;
* V_55 = NULL ;
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
V_56 = V_10 -> V_25 ;
if ( F_2 ( ! V_56 ) )
goto error;
* V_55 = V_56 ;
return 0 ;
error:
if ( V_10 )
F_22 ( V_10 ) ;
return error ;
}
void F_30 ( struct V_5 * V_56 )
{
struct V_9 * V_10 ;
V_10 = V_56 -> V_10 ;
if ( F_2 ( V_10 -> type == V_47 ) )
return;
if ( F_2 ( V_10 -> V_25 != V_56 ) )
return;
F_22 ( V_10 ) ;
}
static int F_31 ( struct V_5 * V_6 )
{
enum V_3 V_4 ;
struct V_5 * V_11 ;
struct V_1 * V_2 ;
int error ;
if ( F_2 ( ! F_3 ( V_6 -> V_16 . type ) ) )
return - V_12 ;
V_11 = F_11 ( V_6 -> V_21 . V_29 ) ;
if ( F_2 ( V_11 -> V_21 . V_45 != & V_46 ) )
return - V_12 ;
V_2 = F_12 ( V_11 ) ;
error = F_17 ( V_6 -> V_16 . type , & V_4 ) ;
if ( error < 0 )
return error ;
error = F_1 ( V_2 , V_4 , V_6 ) ;
if ( error < 0 )
return error ;
F_32 ( & V_6 -> V_21 ,
L_5 ) ;
return 0 ;
}
static int F_33 ( struct V_5 * V_6 )
{
int error ;
if ( F_2 ( ! F_3 ( V_6 -> V_16 . type ) ) )
return - V_12 ;
if ( V_6 -> V_10 ) {
error = F_10 ( V_6 ) ;
if ( error < 0 )
return error ;
}
F_32 ( & V_6 -> V_21 ,
L_6 ) ;
return 0 ;
}
int T_5 F_34 ( void )
{
return F_35 ( & V_57 ) ;
}
void T_6 F_36 ( void )
{
F_37 ( & V_57 ) ;
}
