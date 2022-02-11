void F_1 ( int V_1 , struct V_2 * V_3 , const char * V_4 , ... )
{
struct V_5 V_6 ;
T_1 args ;
if ( V_1 & V_7 ) {
va_start ( args , V_4 ) ;
V_6 . V_4 = V_4 ;
V_6 . V_8 = & args ;
F_2 ( V_9 , V_3 , L_1 , & V_6 ) ;
va_end ( args ) ;
}
}
static void F_3 ( struct V_2 * V_3 )
{
struct V_10 * V_11 = F_4 ( V_3 ) ;
F_5 ( V_11 ) ;
}
bool F_6 ( struct V_2 * V_3 )
{
return V_3 -> type == & V_12 ;
}
int F_7 ( struct V_13 * V_14 )
{
static T_2 V_15 = F_8 ( 0 ) ;
struct V_10 * V_11 ;
int error ;
V_11 = F_9 ( sizeof( struct V_10 ) , V_16 ) ;
if ( ! V_11 )
return - V_17 ;
F_10 ( & V_11 -> V_3 ) ;
V_11 -> V_14 = V_14 ;
V_11 -> V_18 = F_11 ( & V_15 ) - 1 ;
F_12 ( & V_11 -> V_3 , L_2 , V_11 -> V_18 ) ;
V_11 -> V_3 . V_19 = & V_20 ;
V_11 -> V_3 . type = & V_12 ;
V_14 -> V_11 = V_11 ;
error = F_13 ( & V_11 -> V_3 ) ;
if ( error )
goto V_21;
F_1 ( V_22 , V_14 -> V_3 ,
L_3 , V_23 ,
F_14 ( V_11 -> V_14 -> V_3 ) , F_14 ( & V_11 -> V_3 ) ) ;
return 0 ;
V_21:
F_15 ( & V_11 -> V_3 ) ;
return error ;
}
void F_16 ( struct V_13 * V_14 )
{
struct V_10 * V_11 = V_14 -> V_11 ;
F_17 ( & V_11 -> V_3 ) ;
F_15 ( & V_11 -> V_3 ) ;
}
static void F_18 ( struct V_2 * V_3 )
{
struct V_24 * V_25 = F_19 ( V_3 ) ;
F_5 ( V_25 ) ;
}
bool F_20 ( struct V_2 * V_3 )
{
return V_3 -> type == & V_26 ;
}
static int F_21 ( struct V_2 * V_3 , struct V_27 * V_28 )
{
struct V_29 * V_30 = F_22 ( V_28 ) ;
struct V_24 * V_25 = F_19 ( V_3 ) ;
return V_25 -> V_31 . V_32 == V_30 -> V_33 ;
}
static void F_23 ( struct V_24 * V_25 )
{
char V_34 [ 9 ] ;
struct V_35 * V_36 = V_25 -> V_11 -> V_14 -> V_3 -> V_37 ;
snprintf ( V_34 , sizeof( V_34 ) , L_4 ,
V_25 -> V_31 . V_32 ) ;
V_25 -> V_3 . V_37 = F_24 ( V_36 , V_34 ) ;
}
static inline void F_23 ( struct V_24 * V_25 )
{}
static int F_25 ( struct V_2 * V_3 )
{
struct V_24 * V_25 = F_19 ( V_3 ) ;
struct V_29 * V_30 =
F_22 ( V_3 -> V_38 ) ;
int error ;
F_23 ( V_25 ) ;
if ( V_30 -> V_39 ) {
error = V_30 -> V_39 ( V_25 ) ;
return error ;
}
return 0 ;
}
static int F_26 ( struct V_2 * V_3 )
{
struct V_24 * V_25 = F_19 ( V_3 ) ;
struct V_29 * V_30 =
F_22 ( V_3 -> V_38 ) ;
if ( V_30 -> remove )
V_30 -> remove ( V_25 ) ;
return 0 ;
}
int F_27 ( struct V_24 * V_25 )
{
struct V_10 * V_11 = V_25 -> V_11 ;
int error ;
F_10 ( & V_25 -> V_3 ) ;
F_12 ( & V_25 -> V_3 , L_5 ,
F_14 ( & V_11 -> V_3 ) , V_25 -> V_31 . V_32 ) ;
V_25 -> V_3 . V_40 = & V_11 -> V_3 ;
V_25 -> V_3 . type = & V_26 ;
V_25 -> V_3 . V_19 = & V_20 ;
error = F_13 ( & V_25 -> V_3 ) ;
if ( error ) {
F_28 ( & V_11 -> V_3 ,
L_6 ,
F_14 ( & V_25 -> V_3 ) ) ;
goto V_21;
}
F_1 ( V_22 , & V_11 -> V_3 , L_7 ,
V_25 -> V_31 . V_32 ) ;
return 0 ;
V_21:
F_15 ( & V_25 -> V_3 ) ;
return error ;
}
void F_29 ( struct V_24 * V_25 )
{
F_1 ( V_22 , & V_25 -> V_3 , L_8 ,
V_25 -> V_31 . V_32 ) ;
F_17 ( & V_25 -> V_3 ) ;
F_30 ( V_25 -> V_3 . V_37 ) ;
F_15 ( & V_25 -> V_3 ) ;
}
int F_31 ( struct V_29 * V_30 ,
struct V_41 * V_42 ,
const char * V_43 )
{
struct V_27 * V_38 = & V_30 -> V_38 ;
int error ;
V_38 -> V_19 = & V_20 ;
V_38 -> V_42 = V_42 ;
V_38 -> V_43 = V_43 ;
V_38 -> V_39 = F_25 ;
V_38 -> remove = F_26 ;
error = F_32 ( V_38 ) ;
if ( error ) {
F_33 ( L_9 ,
V_38 -> V_44 , error ) ;
return error ;
}
return 0 ;
}
void F_34 ( struct V_29 * V_30 )
{
F_35 ( & V_30 -> V_38 ) ;
}
static int F_36 ( struct V_2 * V_3 , struct V_27 * V_28 )
{
bool V_45 = F_6 ( V_3 ) ;
if ( V_45 != F_37 ( V_28 ) )
return 0 ;
return V_45 || F_21 ( V_3 , V_28 ) ;
}
static void F_38 ( int V_46 )
{
int V_47 ;
for ( V_47 = V_46 ; V_47 >= 0 ; V_47 -- )
F_34 ( V_48 [ V_47 ] ) ;
}
static void F_39 ( void )
{
F_38 ( F_40 ( V_48 ) - 1 ) ;
}
static int F_41 ( void )
{
int V_49 ;
int V_47 ;
for ( V_47 = 0 ; V_47 < F_40 ( V_48 ) ; V_47 ++ ) {
V_49 = F_42 ( V_48 [ V_47 ] ) ;
if ( V_49 ) {
F_33 ( L_10 ,
V_23 , V_48 [ V_47 ] -> V_33 , V_49 ) ;
goto V_50;
}
}
return 0 ;
V_50:
F_38 ( V_47 - 1 ) ;
return V_49 ;
}
int F_43 ( struct V_2 * V_3 , T_3 * V_51 ,
const char * V_52 , bool V_53 )
{
int V_54 ;
T_3 V_55 = 0 ;
V_54 = F_44 ( V_3 -> V_37 , V_52 , & V_55 ) ;
if ( V_54 && ( ! V_53 && V_54 == - V_56 ) ) {
F_28 ( V_3 , L_11 ,
V_52 , V_54 ) ;
return V_54 ;
}
* V_51 = V_55 ;
return 0 ;
}
static int T_4 F_45 ( void )
{
int error ;
error = F_46 ( & V_20 ) ;
if ( error ) {
F_33 ( L_12 ,
V_23 , error ) ;
return error ;
}
error = F_41 () ;
if ( error )
goto V_57;
error = F_47 () ;
if ( error ) {
F_33 ( L_13 ,
V_23 , error ) ;
goto V_57;
}
return 0 ;
V_57:
F_48 ( & V_20 ) ;
return error ;
}
static void T_5 F_49 ( void )
{
F_50 () ;
F_39 () ;
F_48 ( & V_20 ) ;
}
