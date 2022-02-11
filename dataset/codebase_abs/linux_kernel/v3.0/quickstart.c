static T_1 F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
char * V_5 )
{
int V_6 = 0 ;
struct V_7 * V_8 = V_9 . V_10 ;
if ( ! V_8 )
return snprintf ( V_5 , V_11 , L_1 ) ;
while ( V_8 && ( V_6 < V_11 ) ) {
if ( V_8 -> V_12 ) {
V_6 += snprintf ( V_5 + V_6 ,
V_11 - V_6 ,
L_2 , V_8 -> V_13 , V_8 -> V_12 ) ;
}
V_8 = V_8 -> V_14 ;
}
return V_6 ;
}
static T_1 F_2 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
char * V_5 )
{
return snprintf ( V_5 , V_11 , L_3 ,
( V_9 . V_15 ?
V_9 . V_15 -> V_12 : L_1 ) ) ;
}
static T_1 F_3 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_5 , T_2 V_6 )
{
if ( V_6 < 2 )
return - V_16 ;
if ( strncasecmp ( V_5 , L_1 , 4 ) != 0 )
return - V_16 ;
V_9 . V_15 = NULL ;
return V_6 ;
}
static int F_4 ( struct V_7 * * V_17 )
{
struct V_7 * * V_8 = & V_9 . V_10 ;
while ( * V_8 )
V_8 = & ( ( * V_8 ) -> V_14 ) ;
* V_8 = F_5 ( sizeof( struct V_7 ) , V_18 ) ;
if ( ! * V_8 ) {
* V_17 = NULL ;
return - V_19 ;
}
* V_17 = * V_8 ;
return 0 ;
}
static void F_6 ( struct V_7 * V_17 )
{
struct V_7 * * V_8 = & V_9 . V_10 ;
if ( ! V_17 )
return;
while ( * V_8 ) {
if ( * V_8 == V_17 ) {
* V_8 = ( * V_8 ) -> V_14 ;
F_7 ( V_17 ) ;
return;
}
V_8 = & ( ( * V_8 ) -> V_14 ) ;
}
return;
}
static void F_8 ( void )
{
struct V_7 * V_8 = V_9 . V_10 ;
struct V_7 * V_20 = NULL ;
while ( V_8 ) {
V_20 = V_8 ;
V_8 = V_8 -> V_14 ;
F_7 ( V_20 -> V_12 ) ;
F_7 ( V_20 ) ;
}
return;
}
static void F_9 ( T_3 V_21 , T_4 V_22 , void * V_17 )
{
struct V_23 * V_24 = V_17 ;
if ( ! V_24 )
return;
if ( V_22 == V_25 )
V_9 . V_15 = V_24 -> V_26 ;
else if ( V_22 == V_27 ) {
F_10 ( V_28 , V_24 -> V_26 -> V_13 , 1 ) ;
F_11 ( V_28 ) ;
F_10 ( V_28 , V_24 -> V_26 -> V_13 , 0 ) ;
F_11 ( V_28 ) ;
}
return;
}
static void F_12 ( struct V_23 * V_24 )
{
T_5 V_29 ;
struct V_30 V_31 = { V_32 , NULL } ;
T_6 V_33 = 0 ;
if ( ! V_24 )
return;
V_29 = F_13 ( V_24 -> V_1 -> V_21 ,
L_4 , NULL , & V_31 ) ;
if ( F_14 ( V_29 ) || ! V_31 . V_34 ) {
F_15 ( V_35 L_5 ,
V_24 -> V_26 -> V_12 ) ;
return;
}
if ( V_31 . V_36 < 8 )
return;
V_33 = * ( ( T_6 * ) ( V_31 . V_34 + ( V_31 . V_36 - 8 ) ) ) ;
V_24 -> V_26 -> V_13 = V_33 ;
F_7 ( V_31 . V_34 ) ;
}
static int F_16 ( struct V_23 * V_24 , char * V_37 )
{
int V_38 = strlen ( V_37 ) ;
int V_39 ;
V_39 = F_4 ( & V_24 -> V_26 ) ;
if ( V_39 )
return V_39 ;
V_24 -> V_26 -> V_12 = F_5 ( V_38 + 1 , V_18 ) ;
if ( ! V_24 -> V_26 -> V_12 ) {
F_8 () ;
return - V_19 ;
}
strcpy ( V_24 -> V_26 -> V_12 , V_37 ) ;
return 0 ;
}
static int F_17 ( struct V_40 * V_1 )
{
int V_39 = 0 ;
T_5 V_29 = V_41 ;
struct V_23 * V_24 = NULL ;
if ( ! V_1 )
return - V_16 ;
V_24 = F_5 ( sizeof( struct V_23 ) , V_18 ) ;
if ( ! V_24 )
return - V_19 ;
V_24 -> V_1 = V_1 ;
strcpy ( F_18 ( V_1 ) , V_42 ) ;
strcpy ( F_19 ( V_1 ) , V_43 ) ;
V_1 -> V_44 = V_24 ;
V_39 = F_16 ( V_24 , F_20 ( V_1 ) ) ;
if ( V_39 )
goto V_45;
V_29 = F_21 ( V_1 -> V_21 ,
V_46 ,
F_9 ,
V_24 ) ;
if ( F_14 ( V_29 ) ) {
F_15 ( V_35 L_6 ) ;
V_39 = - V_47 ;
goto V_48;
}
F_12 ( V_24 ) ;
return 0 ;
V_48:
F_6 ( V_24 -> V_26 ) ;
V_45:
F_7 ( V_24 ) ;
return V_39 ;
}
static int F_22 ( struct V_40 * V_1 , int type )
{
T_5 V_29 = 0 ;
struct V_23 * V_24 = NULL ;
if ( ! V_1 || ! F_23 ( V_1 ) )
return - V_16 ;
V_24 = F_23 ( V_1 ) ;
V_29 = F_24 ( V_1 -> V_21 ,
V_46 ,
F_9 ) ;
if ( F_14 ( V_29 ) )
F_15 ( V_35 L_7 ) ;
F_7 ( V_24 ) ;
return 0 ;
}
static void F_25 ( void )
{
F_26 ( V_28 ) ;
F_27 ( & V_49 -> V_2 , & V_50 ) ;
F_27 ( & V_49 -> V_2 , & V_51 ) ;
F_28 ( V_49 ) ;
F_29 ( & V_52 ) ;
F_30 ( & V_53 ) ;
F_8 () ;
return;
}
static int T_7 F_31 ( void )
{
struct V_7 * * V_8 = & V_9 . V_10 ;
int V_6 ;
int V_39 ;
V_28 = F_32 () ;
if ( ! V_28 )
return - V_19 ;
V_28 -> V_12 = L_8 ;
V_28 -> V_13 . V_54 = V_55 ;
while ( * V_8 ) {
V_6 ++ ;
F_33 ( V_56 , V_28 -> V_57 ) ;
F_33 ( ( * V_8 ) -> V_13 , V_28 -> V_58 ) ;
V_8 = & ( ( * V_8 ) -> V_14 ) ;
}
V_39 = F_34 ( V_28 ) ;
if ( V_39 ) {
F_35 ( V_28 ) ;
return V_39 ;
}
return 0 ;
}
static int T_7 F_36 ( void )
{
int V_39 ;
if ( V_59 )
return - V_47 ;
V_39 = F_37 ( & V_53 ) ;
if ( V_39 )
return V_39 ;
if ( ! V_9 . V_10 ) {
V_39 = - V_47 ;
goto V_60;
}
V_39 = F_38 ( & V_52 ) ;
if ( V_39 )
goto V_60;
V_49 = F_39 ( V_61 , - 1 ) ;
if ( ! V_49 ) {
V_39 = - V_19 ;
goto V_62;
}
V_39 = F_40 ( V_49 ) ;
if ( V_39 )
goto V_63;
V_39 = F_41 ( & V_49 -> V_2 , & V_50 ) ;
if ( V_39 )
goto V_64;
V_39 = F_41 ( & V_49 -> V_2 , & V_51 ) ;
if ( V_39 )
goto V_65;
V_39 = F_31 () ;
if ( V_39 )
goto V_66;
F_15 ( V_67 L_9 ,
V_68 ) ;
return 0 ;
V_66:
F_27 ( & V_49 -> V_2 , & V_51 ) ;
V_65:
F_27 ( & V_49 -> V_2 , & V_50 ) ;
V_64:
F_42 ( V_49 ) ;
V_63:
F_43 ( V_49 ) ;
V_62:
F_29 ( & V_52 ) ;
V_60:
F_30 ( & V_53 ) ;
return V_39 ;
}
