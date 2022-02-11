static void F_1 ( struct V_1 * V_2 )
{
int V_3 ;
char V_4 [ 8 ] ;
for ( V_3 = 0 ; V_3 < V_2 -> V_5 ; V_3 ++ ) {
sprintf ( V_4 , L_1 , V_3 ) ;
F_2 ( & V_2 -> V_6 . V_7 , V_4 ) ;
F_2 ( & V_2 -> V_8 [ V_3 ] -> V_6 . V_7 , L_2 ) ;
}
}
static void F_3 ( struct V_1 * V_2 )
{
struct V_9 * V_8 ;
int V_3 ;
for ( V_3 = 0 ; V_3 < V_2 -> V_5 ; V_3 ++ ) {
V_8 = V_2 -> V_8 [ V_3 ] ;
if ( ! V_8 )
continue;
F_4 ( V_8 -> V_10 ) ;
F_5 ( & V_8 -> V_6 , NULL ) ;
F_6 ( V_8 -> V_10 ) ;
V_2 -> V_8 [ V_3 ] = NULL ;
F_7 ( & V_8 -> V_6 ) ;
}
}
int F_8 ( struct V_1 * V_2 )
{
struct V_11 * V_12 = F_9 ( V_2 -> V_6 . V_13 ) ;
int V_14 = - V_15 ;
if ( F_10 ( & V_2 -> V_16 , 0 , 1 ) != 0 )
return - V_17 ;
if ( V_2 -> V_18 == V_19 )
goto V_20;
if ( V_12 -> V_21 )
V_14 = V_12 -> V_21 ( V_2 ) ;
if ( V_14 )
goto V_20;
V_2 -> V_18 = V_19 ;
V_20:
F_11 ( & V_2 -> V_16 , 0 ) ;
return V_14 ;
}
int F_12 ( struct V_1 * V_2 )
{
struct V_11 * V_12 = F_9 ( V_2 -> V_6 . V_13 ) ;
int V_14 = - V_15 ;
if ( F_10 ( & V_2 -> V_16 , 0 , 1 ) != 0 )
return - V_17 ;
if ( V_2 -> V_18 == V_22 )
goto V_20;
if ( V_12 -> V_23 )
V_14 = V_12 -> V_23 ( V_2 ) ;
if ( V_14 )
goto V_20;
V_2 -> V_18 = V_22 ;
V_20:
F_11 ( & V_2 -> V_16 , 0 ) ;
return V_14 ;
}
static T_1 F_13 ( struct V_24 * V_6 ,
struct V_25 * V_26 ,
const char * V_27 , T_2 V_5 )
{
struct V_1 * V_2 = F_14 ( V_6 ) ;
unsigned long V_28 ;
int V_14 ;
F_15 ( V_6 ) ;
if ( ! V_6 -> V_13 ) {
V_14 = - V_15 ;
goto V_20;
}
V_14 = F_16 ( V_27 , 0 , & V_28 ) ;
if ( V_14 )
goto V_20;
if ( V_28 == 1 )
V_14 = F_8 ( V_2 ) ;
else if ( V_28 == 0 )
V_14 = F_12 ( V_2 ) ;
else
V_14 = - V_15 ;
V_20:
F_17 ( V_6 ) ;
return ( V_14 == 0 ) ? V_5 : V_14 ;
}
static T_1 F_18 ( struct V_24 * V_6 ,
struct V_25 * V_26 ,
char * V_27 )
{
struct V_1 * V_2 = F_14 ( V_6 ) ;
int V_29 ;
V_29 = ( V_2 -> V_18 == V_19 ) ? 1 : 0 ;
return F_19 ( V_27 , V_30 , L_3 , V_29 ) ;
}
static void F_20 ( struct V_24 * V_6 )
{
struct V_1 * V_2 = F_14 ( V_6 ) ;
F_21 ( & V_2 -> V_31 ) ;
if ( F_22 ( & V_2 -> V_6 ) ) {
F_1 ( V_2 ) ;
F_23 ( V_6 ) ;
F_3 ( V_2 ) ;
}
F_24 ( & V_2 -> V_31 ) ;
}
static T_1 F_25 ( struct V_24 * V_6 ,
struct V_25 * V_26 ,
const char * V_27 , T_2 V_5 )
{
struct V_1 * V_2 = F_14 ( V_6 ) ;
int V_32 ;
if ( F_10 ( & V_2 -> V_16 , 0 , 1 ) != 0 )
return - V_17 ;
if ( V_2 -> V_18 != V_22 ) {
V_32 = - V_15 ;
goto V_20;
}
V_32 = F_26 ( V_6 , F_20 ) ;
V_20:
if ( V_32 ) {
if ( V_32 != - V_17 )
F_11 ( & V_2 -> V_16 , 0 ) ;
return V_32 ;
}
return V_5 ;
}
static void F_27 ( struct V_24 * V_6 )
{
F_28 ( F_14 ( V_6 ) ) ;
}
static int F_29 ( struct V_1 * V_2 )
{
char V_4 [ 8 ] ;
int V_3 , V_32 ;
for ( V_3 = 0 ; V_3 < V_2 -> V_5 ; V_3 ++ ) {
V_32 = F_30 ( & V_2 -> V_8 [ V_3 ] -> V_6 . V_7 ,
& V_2 -> V_6 . V_7 , L_2 ) ;
if ( V_32 ) {
for ( -- V_3 ; V_3 >= 0 ; V_3 -- )
F_2 ( & V_2 -> V_8 [ V_3 ] -> V_6 . V_7 ,
L_2 ) ;
return V_32 ;
}
}
for ( V_3 = 0 ; V_3 < V_2 -> V_5 ; V_3 ++ ) {
sprintf ( V_4 , L_1 , V_3 ) ;
V_32 = F_30 ( & V_2 -> V_6 . V_7 ,
& V_2 -> V_8 [ V_3 ] -> V_6 . V_7 , V_4 ) ;
if ( V_32 ) {
for ( -- V_3 ; V_3 >= 0 ; V_3 -- ) {
sprintf ( V_4 , L_1 , V_3 ) ;
F_2 ( & V_2 -> V_6 . V_7 , V_4 ) ;
}
for ( V_3 = 0 ; V_3 < V_2 -> V_5 ; V_3 ++ )
F_2 ( & V_2 -> V_8 [ V_3 ] -> V_6 . V_7 ,
L_2 ) ;
return V_32 ;
}
}
return 0 ;
}
static int F_31 ( const char * * V_27 , struct V_33 * V_34 )
{
unsigned int V_35 , V_36 , V_37 ;
int V_14 = 0 , V_38 ;
char * V_39 , * V_40 ;
V_39 = ( char * ) * V_27 ;
V_40 = strchr ( V_39 , ',' ) ;
if ( ! V_40 ) {
V_40 = strchr ( V_39 , '\n' ) ;
if ( V_40 )
* V_40 = '\0' ;
V_38 = strlen ( V_39 ) + 1 ;
} else {
V_38 = V_40 - V_39 + 1 ;
V_40 ++ ;
}
if ( V_38 <= V_41 ) {
if ( sscanf ( V_39 , L_4 , & V_35 , & V_36 , & V_37 ) != 3 )
V_14 = - V_15 ;
} else
V_14 = - V_15 ;
if ( ! V_14 ) {
V_34 -> V_36 = V_36 ;
V_34 -> V_37 = V_37 ;
}
* V_27 = V_40 ;
return V_14 ;
}
int F_32 ( struct V_24 * V_42 , struct V_11 * V_12 ,
int V_43 , const char * V_27 )
{
struct V_1 * V_2 ;
struct V_33 V_44 ;
int V_32 , V_3 ;
V_2 = F_33 ( sizeof( * V_2 ) + V_43 * sizeof( V_2 -> V_8 [ 0 ] ) ,
V_45 ) ;
if ( ! V_2 )
return - V_46 ;
F_11 ( & V_2 -> V_16 , 0 ) ;
F_34 ( & V_2 -> V_31 ) ;
F_21 ( & V_2 -> V_31 ) ;
V_2 -> V_5 = V_43 ;
V_2 -> V_6 . V_47 = & V_48 ;
V_2 -> V_6 . V_42 = V_42 ;
V_2 -> V_6 . V_49 = F_27 ;
F_35 ( & V_2 -> V_6 ) ;
for ( V_3 = 0 ; V_3 < V_43 && V_27 ; V_3 ++ ) {
V_32 = F_31 ( & V_27 , & V_44 ) ;
if ( V_32 != 0 )
goto error;
V_2 -> V_8 [ V_3 ] = F_36 ( & V_44 ) ;
if ( ! V_2 -> V_8 [ V_3 ] || ! V_2 -> V_8 [ V_3 ] -> V_50 ||
V_2 -> V_8 [ V_3 ] -> V_50 != V_2 -> V_8 [ 0 ] -> V_50 ||
V_2 -> V_8 [ V_3 ] -> V_34 . V_51 !=
V_2 -> V_8 [ 0 ] -> V_34 . V_51 ) {
V_32 = - V_15 ;
goto error;
}
F_4 ( V_2 -> V_8 [ V_3 ] -> V_10 ) ;
if ( F_37 ( & V_2 -> V_8 [ V_3 ] -> V_6 ) ) {
F_6 ( V_2 -> V_8 [ V_3 ] -> V_10 ) ;
V_32 = - V_15 ;
goto error;
}
F_5 ( & V_2 -> V_8 [ V_3 ] -> V_6 , V_2 ) ;
F_6 ( V_2 -> V_8 [ V_3 ] -> V_10 ) ;
}
if ( V_3 < V_43 ) {
V_32 = - V_15 ;
goto error;
}
if ( V_3 == V_43 && strlen ( V_27 ) > 0 ) {
V_32 = - V_15 ;
goto error;
}
F_38 ( & V_2 -> V_6 , L_5 , F_39 ( & V_2 -> V_8 [ 0 ] -> V_6 ) ) ;
V_2 -> V_6 . V_52 = V_53 ;
if ( V_12 ) {
V_2 -> V_6 . V_13 = & V_12 -> V_13 ;
V_32 = V_12 -> V_54 ? V_12 -> V_54 ( V_2 ) : 0 ;
if ( V_32 )
goto error;
}
V_32 = F_40 ( & V_2 -> V_6 ) ;
if ( V_32 )
goto error;
V_32 = F_29 ( V_2 ) ;
if ( V_32 ) {
F_41 ( & V_2 -> V_6 ) ;
goto error;
}
F_24 ( & V_2 -> V_31 ) ;
return 0 ;
error:
for ( V_3 = 0 ; V_3 < V_43 ; V_3 ++ )
if ( V_2 -> V_8 [ V_3 ] ) {
F_4 ( V_2 -> V_8 [ V_3 ] -> V_10 ) ;
if ( F_37 ( & V_2 -> V_8 [ V_3 ] -> V_6 ) == V_2 )
F_5 ( & V_2 -> V_8 [ V_3 ] -> V_6 , NULL ) ;
F_6 ( V_2 -> V_8 [ V_3 ] -> V_10 ) ;
F_7 ( & V_2 -> V_8 [ V_3 ] -> V_6 ) ;
V_2 -> V_8 [ V_3 ] = NULL ;
}
F_24 ( & V_2 -> V_31 ) ;
F_7 ( & V_2 -> V_6 ) ;
return V_32 ;
}
static int F_42 ( struct V_55 * V_56 , unsigned long V_57 ,
void * V_58 )
{
struct V_24 * V_6 = V_58 ;
if ( V_57 == V_59 )
F_26 ( V_6 , F_20 ) ;
return V_60 ;
}
static int T_3 F_43 ( void )
{
int V_14 ;
V_14 = F_44 ( & V_48 ) ;
if ( V_14 )
return V_14 ;
V_14 = F_45 ( & V_48 , & V_61 ) ;
if ( V_14 )
F_46 ( & V_48 ) ;
return V_14 ;
}
static void T_4 F_47 ( void )
{
F_48 ( & V_48 , & V_61 ) ;
F_46 ( & V_48 ) ;
}
static int F_49 ( struct V_24 * V_6 )
{
struct V_1 * V_2 = F_14 ( V_6 ) ;
struct V_11 * V_12 = F_9 ( V_6 -> V_13 ) ;
if ( ! V_6 -> V_13 )
return 0 ;
if ( V_12 -> remove )
V_12 -> remove ( V_2 ) ;
return 0 ;
}
static void F_50 ( struct V_24 * V_6 )
{
struct V_1 * V_2 = F_14 ( V_6 ) ;
struct V_11 * V_12 = F_9 ( V_6 -> V_13 ) ;
if ( ! V_6 -> V_13 )
return;
if ( V_12 -> V_62 )
V_12 -> V_62 ( V_2 ) ;
}
static int F_51 ( struct V_24 * V_6 )
{
struct V_1 * V_2 = F_14 ( V_6 ) ;
struct V_11 * V_12 = F_9 ( V_2 -> V_6 . V_13 ) ;
if ( F_52 ( & V_2 -> V_16 ) )
return - V_17 ;
if ( ! V_2 -> V_6 . V_13 || V_2 -> V_18 != V_19 )
return 0 ;
return V_12 -> V_63 ? V_12 -> V_63 ( V_2 ) : 0 ;
}
static void F_53 ( struct V_24 * V_6 )
{
struct V_1 * V_2 = F_14 ( V_6 ) ;
struct V_11 * V_12 = F_9 ( V_6 -> V_13 ) ;
if ( ! V_2 -> V_6 . V_13 || V_2 -> V_18 != V_19 )
return;
if ( V_12 -> V_64 )
V_12 -> V_64 ( V_2 ) ;
}
static int F_54 ( struct V_24 * V_6 )
{
struct V_1 * V_2 = F_14 ( V_6 ) ;
struct V_11 * V_12 = F_9 ( V_2 -> V_6 . V_13 ) ;
if ( ! V_2 -> V_6 . V_13 || V_2 -> V_18 != V_19 )
return 0 ;
return V_12 -> V_65 ? V_12 -> V_65 ( V_2 ) : 0 ;
}
static int F_55 ( struct V_24 * V_6 )
{
struct V_1 * V_2 = F_14 ( V_6 ) ;
struct V_11 * V_12 = F_9 ( V_2 -> V_6 . V_13 ) ;
if ( ! V_2 -> V_6 . V_13 || V_2 -> V_18 != V_19 )
return 0 ;
return V_12 -> V_66 ? V_12 -> V_66 ( V_2 ) : 0 ;
}
static int F_56 ( struct V_24 * V_6 )
{
struct V_1 * V_2 = F_14 ( V_6 ) ;
struct V_11 * V_12 = F_9 ( V_2 -> V_6 . V_13 ) ;
if ( ! V_2 -> V_6 . V_13 || V_2 -> V_18 != V_19 )
return 0 ;
return V_12 -> V_67 ? V_12 -> V_67 ( V_2 ) : 0 ;
}
int F_57 ( struct V_11 * V_68 )
{
V_68 -> V_13 . V_47 = & V_48 ;
return F_58 ( & V_68 -> V_13 ) ;
}
static int F_59 ( struct V_24 * V_6 , void * V_58 )
{
return 1 ;
}
void F_60 ( struct V_11 * V_68 )
{
struct V_24 * V_6 ;
while ( ( V_6 = F_61 ( & V_68 -> V_13 , NULL , NULL ,
F_59 ) ) ) {
struct V_1 * V_2 = F_14 ( V_6 ) ;
F_21 ( & V_2 -> V_31 ) ;
F_1 ( V_2 ) ;
F_23 ( V_6 ) ;
F_3 ( V_2 ) ;
F_24 ( & V_2 -> V_31 ) ;
F_7 ( V_6 ) ;
}
F_62 ( & V_68 -> V_13 ) ;
}
int F_63 ( struct V_9 * V_8 )
{
return 0 ;
}
void F_64 ( struct V_9 * V_8 )
{
struct V_1 * V_2 ;
F_65 ( V_8 ) ;
F_4 ( V_8 -> V_10 ) ;
V_2 = F_37 ( & V_8 -> V_6 ) ;
if ( ! V_2 ) {
F_6 ( V_8 -> V_10 ) ;
return;
}
F_66 ( & V_2 -> V_6 ) ;
F_6 ( V_8 -> V_10 ) ;
F_21 ( & V_2 -> V_31 ) ;
if ( F_22 ( & V_2 -> V_6 ) ) {
F_1 ( V_2 ) ;
F_23 ( & V_2 -> V_6 ) ;
F_3 ( V_2 ) ;
}
F_24 ( & V_2 -> V_31 ) ;
F_7 ( & V_2 -> V_6 ) ;
}
