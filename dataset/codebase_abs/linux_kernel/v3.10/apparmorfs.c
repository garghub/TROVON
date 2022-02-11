static char * F_1 ( int V_1 , const char T_1 * V_2 ,
T_2 V_3 , T_2 V_4 ,
T_3 * V_5 )
{
char * V_6 ;
F_2 ( V_4 > V_3 ) ;
if ( * V_5 != 0 )
return F_3 ( - V_7 ) ;
if ( ! F_4 ( V_1 ) )
return F_3 ( - V_8 ) ;
V_6 = F_5 ( V_3 ) ;
if ( V_6 == NULL )
return F_3 ( - V_9 ) ;
if ( F_6 ( V_6 , V_2 , V_4 ) ) {
F_7 ( V_6 ) ;
return F_3 ( - V_10 ) ;
}
return V_6 ;
}
static T_4 F_8 ( struct V_11 * V_12 , const char T_1 * V_13 , T_2 V_14 ,
T_3 * V_5 )
{
char * V_6 ;
T_4 error ;
V_6 = F_1 ( V_15 , V_13 , V_14 , V_14 , V_5 ) ;
error = F_9 ( V_6 ) ;
if ( ! F_10 ( V_6 ) ) {
error = F_11 ( V_6 , V_14 , V_16 ) ;
F_7 ( V_6 ) ;
}
return error ;
}
static T_4 F_12 ( struct V_11 * V_12 , const char T_1 * V_13 ,
T_2 V_14 , T_3 * V_5 )
{
char * V_6 ;
T_4 error ;
V_6 = F_1 ( V_17 , V_13 , V_14 , V_14 , V_5 ) ;
error = F_9 ( V_6 ) ;
if ( ! F_10 ( V_6 ) ) {
error = F_11 ( V_6 , V_14 , V_18 ) ;
F_7 ( V_6 ) ;
}
return error ;
}
static T_4 F_13 ( struct V_11 * V_12 , const char T_1 * V_13 ,
T_2 V_14 , T_3 * V_5 )
{
char * V_6 ;
T_4 error ;
V_6 = F_1 ( V_19 , V_13 , V_14 + 1 , V_14 , V_5 ) ;
error = F_9 ( V_6 ) ;
if ( ! F_10 ( V_6 ) ) {
V_6 [ V_14 ] = 0 ;
error = F_14 ( V_6 , V_14 ) ;
F_7 ( V_6 ) ;
}
return error ;
}
static int F_15 ( struct V_20 * V_21 , void * V_22 )
{
struct V_23 * V_24 = V_21 -> V_25 ;
if ( ! V_24 )
return 0 ;
switch ( V_24 -> V_26 ) {
case V_27 :
F_16 ( V_21 , L_1 , V_24 -> V_22 . boolean ? L_2 : L_3 ) ;
break;
case V_28 :
F_16 ( V_21 , L_1 , V_24 -> V_22 . string ) ;
break;
case V_29 :
F_16 ( V_21 , L_4 , V_24 -> V_22 . V_30 ) ;
break;
default:
break;
}
return 0 ;
}
static int F_17 ( struct V_31 * V_31 , struct V_11 * V_11 )
{
return F_18 ( V_11 , F_15 , V_31 -> V_32 ) ;
}
static int T_5 F_19 ( struct V_23 * V_24 ,
struct V_33 * V_34 )
{
int error = 0 ;
V_24 -> V_33 = F_20 ( V_24 -> V_35 ,
V_36 | V_24 -> V_37 ,
V_34 , V_24 ,
V_24 -> V_38 ) ;
if ( F_10 ( V_24 -> V_33 ) ) {
error = F_9 ( V_24 -> V_33 ) ;
V_24 -> V_33 = NULL ;
}
return error ;
}
static int T_5 F_21 ( struct V_23 * V_39 ,
struct V_33 * V_34 )
{
int error ;
struct V_23 * V_24 ;
V_39 -> V_33 = F_22 ( V_39 -> V_35 , V_34 ) ;
if ( F_10 ( V_39 -> V_33 ) ) {
error = F_9 ( V_39 -> V_33 ) ;
V_39 -> V_33 = NULL ;
goto V_40;
}
for ( V_24 = V_39 -> V_22 . V_41 ; V_24 -> V_35 ; ++ V_24 ) {
if ( V_24 -> V_26 == V_42 )
error = F_21 ( V_24 , V_39 -> V_33 ) ;
else
error = F_19 ( V_24 , V_39 -> V_33 ) ;
if ( error )
goto V_40;
}
return 0 ;
V_40:
return error ;
}
static void T_5 F_23 ( struct V_23 * V_24 )
{
if ( ! V_24 -> V_33 )
return;
F_24 ( V_24 -> V_33 ) ;
V_24 -> V_33 = NULL ;
}
static void T_5 F_25 ( struct V_23 * V_39 )
{
struct V_23 * V_24 ;
for ( V_24 = V_39 -> V_22 . V_41 ; V_24 -> V_35 ; ++ V_24 ) {
if ( V_24 -> V_26 == V_42 )
F_25 ( V_24 ) ;
else
F_23 ( V_24 ) ;
}
F_23 ( V_39 ) ;
}
void T_5 F_26 ( void )
{
F_25 ( & V_23 ) ;
}
static int T_5 F_27 ( void )
{
int error ;
if ( ! V_43 )
return 0 ;
if ( V_23 . V_33 ) {
F_28 ( L_5 , V_44 ) ;
return - V_45 ;
}
error = F_21 ( & V_23 , NULL ) ;
if ( error )
goto error;
F_29 ( L_6 ) ;
return 0 ;
error:
F_26 () ;
F_28 ( L_7 ) ;
return error ;
}
