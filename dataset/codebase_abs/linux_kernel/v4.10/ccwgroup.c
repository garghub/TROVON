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
static void F_20 ( struct V_1 * V_2 )
{
F_21 ( & V_2 -> V_31 ) ;
if ( F_22 ( & V_2 -> V_6 ) ) {
F_1 ( V_2 ) ;
F_23 ( & V_2 -> V_6 ) ;
F_3 ( V_2 ) ;
}
F_24 ( & V_2 -> V_31 ) ;
}
static T_1 F_25 ( struct V_24 * V_6 ,
struct V_25 * V_26 ,
const char * V_27 , T_2 V_5 )
{
struct V_1 * V_2 = F_14 ( V_6 ) ;
int V_32 = 0 ;
if ( F_10 ( & V_2 -> V_16 , 0 , 1 ) != 0 )
return - V_17 ;
if ( V_2 -> V_18 != V_22 ) {
V_32 = - V_15 ;
goto V_20;
}
if ( F_26 ( V_6 , V_26 ) )
F_20 ( V_2 ) ;
else
V_32 = - V_33 ;
V_20:
if ( V_32 ) {
F_11 ( & V_2 -> V_16 , 0 ) ;
return V_32 ;
}
return V_5 ;
}
static void F_27 ( struct V_34 * V_35 )
{
struct V_1 * V_2 =
F_28 ( V_35 , struct V_1 , V_36 ) ;
F_20 ( V_2 ) ;
F_7 ( & V_2 -> V_6 ) ;
}
static void F_29 ( struct V_24 * V_6 )
{
F_30 ( F_14 ( V_6 ) ) ;
}
static int F_31 ( struct V_1 * V_2 )
{
char V_4 [ 8 ] ;
int V_3 , V_32 ;
for ( V_3 = 0 ; V_3 < V_2 -> V_5 ; V_3 ++ ) {
V_32 = F_32 ( & V_2 -> V_8 [ V_3 ] -> V_6 . V_7 ,
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
V_32 = F_32 ( & V_2 -> V_6 . V_7 ,
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
static int F_33 ( const char * * V_27 , struct V_37 * V_38 )
{
unsigned int V_39 , V_40 , V_41 ;
int V_14 = 0 , V_42 ;
char * V_43 , * V_44 ;
V_43 = ( char * ) * V_27 ;
V_44 = strchr ( V_43 , ',' ) ;
if ( ! V_44 ) {
V_44 = strchr ( V_43 , '\n' ) ;
if ( V_44 )
* V_44 = '\0' ;
V_42 = strlen ( V_43 ) + 1 ;
} else {
V_42 = V_44 - V_43 + 1 ;
V_44 ++ ;
}
if ( V_42 <= V_45 ) {
if ( sscanf ( V_43 , L_4 , & V_39 , & V_40 , & V_41 ) != 3 )
V_14 = - V_15 ;
} else
V_14 = - V_15 ;
if ( ! V_14 ) {
V_38 -> V_40 = V_40 ;
V_38 -> V_41 = V_41 ;
}
* V_27 = V_44 ;
return V_14 ;
}
int F_34 ( struct V_24 * V_46 , struct V_11 * V_12 ,
int V_47 , const char * V_27 )
{
struct V_1 * V_2 ;
struct V_37 V_48 ;
int V_32 , V_3 ;
V_2 = F_35 ( sizeof( * V_2 ) + V_47 * sizeof( V_2 -> V_8 [ 0 ] ) ,
V_49 ) ;
if ( ! V_2 )
return - V_50 ;
F_11 ( & V_2 -> V_16 , 0 ) ;
F_36 ( & V_2 -> V_31 ) ;
F_21 ( & V_2 -> V_31 ) ;
F_37 ( & V_2 -> V_36 , F_27 ) ;
V_2 -> V_5 = V_47 ;
V_2 -> V_6 . V_51 = & V_52 ;
V_2 -> V_6 . V_46 = V_46 ;
V_2 -> V_6 . V_53 = F_29 ;
F_38 ( & V_2 -> V_6 ) ;
for ( V_3 = 0 ; V_3 < V_47 && V_27 ; V_3 ++ ) {
V_32 = F_33 ( & V_27 , & V_48 ) ;
if ( V_32 != 0 )
goto error;
V_2 -> V_8 [ V_3 ] = F_39 ( & V_48 ) ;
if ( ! V_2 -> V_8 [ V_3 ] || ! V_2 -> V_8 [ V_3 ] -> V_54 ||
V_2 -> V_8 [ V_3 ] -> V_54 != V_2 -> V_8 [ 0 ] -> V_54 ||
V_2 -> V_8 [ V_3 ] -> V_38 . V_55 !=
V_2 -> V_8 [ 0 ] -> V_38 . V_55 ) {
V_32 = - V_15 ;
goto error;
}
F_4 ( V_2 -> V_8 [ V_3 ] -> V_10 ) ;
if ( F_40 ( & V_2 -> V_8 [ V_3 ] -> V_6 ) ) {
F_6 ( V_2 -> V_8 [ V_3 ] -> V_10 ) ;
V_32 = - V_15 ;
goto error;
}
F_5 ( & V_2 -> V_8 [ V_3 ] -> V_6 , V_2 ) ;
F_6 ( V_2 -> V_8 [ V_3 ] -> V_10 ) ;
}
if ( V_3 < V_47 ) {
V_32 = - V_15 ;
goto error;
}
if ( V_3 == V_47 && strlen ( V_27 ) > 0 ) {
V_32 = - V_15 ;
goto error;
}
F_41 ( & V_2 -> V_6 , L_5 , F_42 ( & V_2 -> V_8 [ 0 ] -> V_6 ) ) ;
V_2 -> V_6 . V_56 = V_57 ;
if ( V_12 ) {
V_2 -> V_6 . V_13 = & V_12 -> V_13 ;
V_32 = V_12 -> V_58 ? V_12 -> V_58 ( V_2 ) : 0 ;
if ( V_32 )
goto error;
}
V_32 = F_43 ( & V_2 -> V_6 ) ;
if ( V_32 )
goto error;
V_32 = F_31 ( V_2 ) ;
if ( V_32 ) {
F_44 ( & V_2 -> V_6 ) ;
goto error;
}
F_24 ( & V_2 -> V_31 ) ;
return 0 ;
error:
for ( V_3 = 0 ; V_3 < V_47 ; V_3 ++ )
if ( V_2 -> V_8 [ V_3 ] ) {
F_4 ( V_2 -> V_8 [ V_3 ] -> V_10 ) ;
if ( F_40 ( & V_2 -> V_8 [ V_3 ] -> V_6 ) == V_2 )
F_5 ( & V_2 -> V_8 [ V_3 ] -> V_6 , NULL ) ;
F_6 ( V_2 -> V_8 [ V_3 ] -> V_10 ) ;
F_7 ( & V_2 -> V_8 [ V_3 ] -> V_6 ) ;
V_2 -> V_8 [ V_3 ] = NULL ;
}
F_24 ( & V_2 -> V_31 ) ;
F_7 ( & V_2 -> V_6 ) ;
return V_32 ;
}
static int F_45 ( struct V_59 * V_60 , unsigned long V_61 ,
void * V_62 )
{
struct V_1 * V_2 = F_14 ( V_62 ) ;
if ( V_61 == V_63 ) {
F_46 ( & V_2 -> V_6 ) ;
F_47 ( & V_2 -> V_36 ) ;
}
return V_64 ;
}
static int T_3 F_48 ( void )
{
int V_14 ;
V_14 = F_49 ( & V_52 ) ;
if ( V_14 )
return V_14 ;
V_14 = F_50 ( & V_52 , & V_65 ) ;
if ( V_14 )
F_51 ( & V_52 ) ;
return V_14 ;
}
static void T_4 F_52 ( void )
{
F_53 ( & V_52 , & V_65 ) ;
F_51 ( & V_52 ) ;
}
static int F_54 ( struct V_24 * V_6 )
{
struct V_1 * V_2 = F_14 ( V_6 ) ;
struct V_11 * V_12 = F_9 ( V_6 -> V_13 ) ;
if ( ! V_6 -> V_13 )
return 0 ;
if ( V_12 -> remove )
V_12 -> remove ( V_2 ) ;
return 0 ;
}
static void F_55 ( struct V_24 * V_6 )
{
struct V_1 * V_2 = F_14 ( V_6 ) ;
struct V_11 * V_12 = F_9 ( V_6 -> V_13 ) ;
if ( ! V_6 -> V_13 )
return;
if ( V_12 -> V_66 )
V_12 -> V_66 ( V_2 ) ;
}
static int F_56 ( struct V_24 * V_6 )
{
struct V_1 * V_2 = F_14 ( V_6 ) ;
struct V_11 * V_12 = F_9 ( V_2 -> V_6 . V_13 ) ;
if ( F_57 ( & V_2 -> V_16 ) )
return - V_17 ;
if ( ! V_2 -> V_6 . V_13 || V_2 -> V_18 != V_19 )
return 0 ;
return V_12 -> V_67 ? V_12 -> V_67 ( V_2 ) : 0 ;
}
static void F_58 ( struct V_24 * V_6 )
{
struct V_1 * V_2 = F_14 ( V_6 ) ;
struct V_11 * V_12 = F_9 ( V_6 -> V_13 ) ;
if ( ! V_2 -> V_6 . V_13 || V_2 -> V_18 != V_19 )
return;
if ( V_12 -> V_68 )
V_12 -> V_68 ( V_2 ) ;
}
static int F_59 ( struct V_24 * V_6 )
{
struct V_1 * V_2 = F_14 ( V_6 ) ;
struct V_11 * V_12 = F_9 ( V_2 -> V_6 . V_13 ) ;
if ( ! V_2 -> V_6 . V_13 || V_2 -> V_18 != V_19 )
return 0 ;
return V_12 -> V_69 ? V_12 -> V_69 ( V_2 ) : 0 ;
}
static int F_60 ( struct V_24 * V_6 )
{
struct V_1 * V_2 = F_14 ( V_6 ) ;
struct V_11 * V_12 = F_9 ( V_2 -> V_6 . V_13 ) ;
if ( ! V_2 -> V_6 . V_13 || V_2 -> V_18 != V_19 )
return 0 ;
return V_12 -> V_70 ? V_12 -> V_70 ( V_2 ) : 0 ;
}
static int F_61 ( struct V_24 * V_6 )
{
struct V_1 * V_2 = F_14 ( V_6 ) ;
struct V_11 * V_12 = F_9 ( V_2 -> V_6 . V_13 ) ;
if ( ! V_2 -> V_6 . V_13 || V_2 -> V_18 != V_19 )
return 0 ;
return V_12 -> V_71 ? V_12 -> V_71 ( V_2 ) : 0 ;
}
int F_62 ( struct V_11 * V_72 )
{
V_72 -> V_13 . V_51 = & V_52 ;
return F_63 ( & V_72 -> V_13 ) ;
}
static int F_64 ( struct V_24 * V_6 , void * V_62 )
{
return 1 ;
}
void F_65 ( struct V_11 * V_72 )
{
struct V_24 * V_6 ;
while ( ( V_6 = F_66 ( & V_72 -> V_13 , NULL , NULL ,
F_64 ) ) ) {
struct V_1 * V_2 = F_14 ( V_6 ) ;
F_20 ( V_2 ) ;
F_7 ( V_6 ) ;
}
F_67 ( & V_72 -> V_13 ) ;
}
int F_68 ( struct V_9 * V_8 )
{
return 0 ;
}
void F_69 ( struct V_9 * V_8 )
{
struct V_1 * V_2 ;
F_70 ( V_8 ) ;
F_4 ( V_8 -> V_10 ) ;
V_2 = F_40 ( & V_8 -> V_6 ) ;
if ( ! V_2 ) {
F_6 ( V_8 -> V_10 ) ;
return;
}
F_46 ( & V_2 -> V_6 ) ;
F_6 ( V_8 -> V_10 ) ;
F_20 ( V_2 ) ;
F_7 ( & V_2 -> V_6 ) ;
}
