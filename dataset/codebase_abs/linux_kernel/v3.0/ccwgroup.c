static int
F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 ;
struct V_7 * V_8 ;
V_6 = F_2 ( V_2 ) ;
V_8 = F_3 ( V_4 ) ;
if ( V_6 -> V_9 == V_8 -> V_10 )
return 1 ;
return 0 ;
}
static int
F_4 ( struct V_1 * V_2 , struct V_11 * V_12 )
{
return 0 ;
}
static void
F_5 ( struct V_5 * V_6 )
{
int V_13 ;
char V_14 [ 8 ] ;
for ( V_13 = 0 ; V_13 < V_6 -> V_15 ; V_13 ++ ) {
sprintf ( V_14 , L_1 , V_13 ) ;
F_6 ( & V_6 -> V_2 . V_16 , V_14 ) ;
F_6 ( & V_6 -> V_17 [ V_13 ] -> V_2 . V_16 , L_2 ) ;
}
}
static void F_7 ( struct V_5 * V_6 )
{
struct V_18 * V_17 ;
int V_13 ;
for ( V_13 = 0 ; V_13 < V_6 -> V_15 ; V_13 ++ ) {
V_17 = V_6 -> V_17 [ V_13 ] ;
if ( ! V_17 )
continue;
F_8 ( V_17 -> V_19 ) ;
F_9 ( & V_17 -> V_2 , NULL ) ;
F_10 ( V_17 -> V_19 ) ;
V_6 -> V_17 [ V_13 ] = NULL ;
F_11 ( & V_17 -> V_2 ) ;
}
}
static void F_12 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_13 ( & V_6 -> V_20 ) ;
if ( F_14 ( & V_6 -> V_2 ) ) {
F_5 ( V_6 ) ;
F_15 ( V_2 ) ;
F_7 ( V_6 ) ;
}
F_16 ( & V_6 -> V_20 ) ;
}
static T_1
F_17 ( struct V_1 * V_2 , struct V_21 * V_22 , const char * V_23 , T_2 V_15 )
{
struct V_5 * V_6 ;
int V_24 ;
V_6 = F_2 ( V_2 ) ;
if ( F_18 ( & V_6 -> V_25 , 0 , 1 ) != 0 )
return - V_26 ;
if ( V_6 -> V_27 != V_28 ) {
V_24 = - V_29 ;
goto V_30;
}
V_24 = F_19 ( V_2 , F_12 ) ;
V_30:
if ( V_24 ) {
if ( V_24 != - V_26 )
F_20 ( & V_6 -> V_25 , 0 ) ;
return V_24 ;
}
return V_15 ;
}
static void
F_21 ( struct V_1 * V_2 )
{
F_22 ( F_2 ( V_2 ) ) ;
}
static int
F_23 ( struct V_5 * V_6 )
{
char V_14 [ 8 ] ;
int V_13 , V_24 ;
for ( V_13 = 0 ; V_13 < V_6 -> V_15 ; V_13 ++ ) {
V_24 = F_24 ( & V_6 -> V_17 [ V_13 ] -> V_2 . V_16 , & V_6 -> V_2 . V_16 ,
L_2 ) ;
if ( V_24 ) {
for ( -- V_13 ; V_13 >= 0 ; V_13 -- )
F_6 ( & V_6 -> V_17 [ V_13 ] -> V_2 . V_16 ,
L_2 ) ;
return V_24 ;
}
}
for ( V_13 = 0 ; V_13 < V_6 -> V_15 ; V_13 ++ ) {
sprintf ( V_14 , L_1 , V_13 ) ;
V_24 = F_24 ( & V_6 -> V_2 . V_16 , & V_6 -> V_17 [ V_13 ] -> V_2 . V_16 ,
V_14 ) ;
if ( V_24 ) {
for ( -- V_13 ; V_13 >= 0 ; V_13 -- ) {
sprintf ( V_14 , L_1 , V_13 ) ;
F_6 ( & V_6 -> V_2 . V_16 , V_14 ) ;
}
for ( V_13 = 0 ; V_13 < V_6 -> V_15 ; V_13 ++ )
F_6 ( & V_6 -> V_17 [ V_13 ] -> V_2 . V_16 ,
L_2 ) ;
return V_24 ;
}
}
return 0 ;
}
static int F_25 ( const char * * V_23 , char * V_31 )
{
int V_24 , V_32 ;
char * V_33 , * V_34 ;
V_33 = ( char * ) * V_23 ;
V_34 = strchr ( V_33 , ',' ) ;
if ( ! V_34 ) {
V_34 = strchr ( V_33 , '\n' ) ;
if ( V_34 )
* V_34 = '\0' ;
V_32 = strlen ( V_33 ) + 1 ;
} else {
V_32 = V_34 - V_33 + 1 ;
V_34 ++ ;
}
if ( V_32 < V_35 ) {
F_26 ( V_31 , V_33 , V_32 ) ;
V_24 = 0 ;
} else
V_24 = - V_29 ;
* V_23 = V_34 ;
return V_24 ;
}
static int F_27 ( char V_31 [ V_35 ] )
{
int V_36 , V_37 , V_38 ;
if ( sscanf ( V_31 , L_3 , & V_36 , & V_37 , & V_38 ) != 3 )
return 0 ;
return 1 ;
}
int F_28 ( struct V_1 * V_39 , unsigned int V_9 ,
struct V_40 * V_41 , int V_42 ,
const char * V_23 )
{
struct V_5 * V_6 ;
int V_24 , V_13 ;
char V_43 [ V_35 ] ;
const char * V_44 ;
V_6 = F_29 ( sizeof( * V_6 ) + V_42 * sizeof( V_6 -> V_17 [ 0 ] ) ,
V_45 ) ;
if ( ! V_6 )
return - V_46 ;
F_20 ( & V_6 -> V_25 , 0 ) ;
F_30 ( & V_6 -> V_20 ) ;
F_13 ( & V_6 -> V_20 ) ;
V_6 -> V_9 = V_9 ;
V_6 -> V_15 = V_42 ;
V_6 -> V_2 . V_47 = & V_48 ;
V_6 -> V_2 . V_49 = V_39 ;
V_6 -> V_2 . V_50 = F_21 ;
F_31 ( & V_6 -> V_2 ) ;
V_44 = V_23 ;
for ( V_13 = 0 ; V_13 < V_42 && V_44 ; V_13 ++ ) {
V_24 = F_25 ( & V_44 , V_43 ) ;
if ( V_24 != 0 )
goto error;
if ( ! F_27 ( V_43 ) ) {
V_24 = - V_29 ;
goto error;
}
V_6 -> V_17 [ V_13 ] = F_32 ( V_41 , V_43 ) ;
if ( ! V_6 -> V_17 [ V_13 ]
|| V_6 -> V_17 [ V_13 ] -> V_51 . V_52 !=
V_6 -> V_17 [ 0 ] -> V_51 . V_52 ) {
V_24 = - V_29 ;
goto error;
}
F_8 ( V_6 -> V_17 [ V_13 ] -> V_19 ) ;
if ( F_33 ( & V_6 -> V_17 [ V_13 ] -> V_2 ) ) {
F_10 ( V_6 -> V_17 [ V_13 ] -> V_19 ) ;
V_24 = - V_29 ;
goto error;
}
F_9 ( & V_6 -> V_17 [ V_13 ] -> V_2 , V_6 ) ;
F_10 ( V_6 -> V_17 [ V_13 ] -> V_19 ) ;
}
if ( V_13 < V_42 && ! V_44 ) {
V_24 = - V_29 ;
goto error;
}
if ( V_13 == V_42 && strlen ( V_44 ) > 0 ) {
V_24 = - V_29 ;
goto error;
}
F_34 ( & V_6 -> V_2 , L_4 , F_35 ( & V_6 -> V_17 [ 0 ] -> V_2 ) ) ;
V_24 = F_36 ( & V_6 -> V_2 ) ;
if ( V_24 )
goto error;
F_37 ( & V_6 -> V_2 ) ;
V_24 = F_38 ( & V_6 -> V_2 , & V_53 ) ;
if ( V_24 ) {
F_15 ( & V_6 -> V_2 ) ;
goto error;
}
V_24 = F_23 ( V_6 ) ;
if ( ! V_24 ) {
F_16 ( & V_6 -> V_20 ) ;
F_11 ( & V_6 -> V_2 ) ;
return 0 ;
}
F_39 ( & V_6 -> V_2 , & V_53 ) ;
F_15 ( & V_6 -> V_2 ) ;
error:
for ( V_13 = 0 ; V_13 < V_42 ; V_13 ++ )
if ( V_6 -> V_17 [ V_13 ] ) {
F_8 ( V_6 -> V_17 [ V_13 ] -> V_19 ) ;
if ( F_33 ( & V_6 -> V_17 [ V_13 ] -> V_2 ) == V_6 )
F_9 ( & V_6 -> V_17 [ V_13 ] -> V_2 , NULL ) ;
F_10 ( V_6 -> V_17 [ V_13 ] -> V_19 ) ;
F_11 ( & V_6 -> V_17 [ V_13 ] -> V_2 ) ;
V_6 -> V_17 [ V_13 ] = NULL ;
}
F_16 ( & V_6 -> V_20 ) ;
F_11 ( & V_6 -> V_2 ) ;
return V_24 ;
}
static int T_3 F_40 ( void )
{
int V_54 ;
V_54 = F_41 ( & V_48 ) ;
if ( V_54 )
return V_54 ;
V_54 = F_42 ( & V_48 , & V_55 ) ;
if ( V_54 )
F_43 ( & V_48 ) ;
return V_54 ;
}
static void T_4 F_44 ( void )
{
F_45 ( & V_48 , & V_55 ) ;
F_43 ( & V_48 ) ;
}
static int
F_46 ( struct V_5 * V_6 )
{
struct V_7 * V_8 ;
int V_54 ;
if ( F_18 ( & V_6 -> V_25 , 0 , 1 ) != 0 )
return - V_26 ;
if ( V_6 -> V_27 == V_56 ) {
V_54 = 0 ;
goto V_30;
}
if ( ! V_6 -> V_2 . V_57 ) {
V_54 = - V_29 ;
goto V_30;
}
V_8 = F_3 ( V_6 -> V_2 . V_57 ) ;
if ( ( V_54 = V_8 -> V_58 ? V_8 -> V_58 ( V_6 ) : 0 ) )
goto V_30;
V_6 -> V_27 = V_56 ;
V_30:
F_20 ( & V_6 -> V_25 , 0 ) ;
return V_54 ;
}
static int
F_47 ( struct V_5 * V_6 )
{
struct V_7 * V_8 ;
int V_54 ;
if ( F_18 ( & V_6 -> V_25 , 0 , 1 ) != 0 )
return - V_26 ;
if ( V_6 -> V_27 == V_28 ) {
V_54 = 0 ;
goto V_30;
}
if ( ! V_6 -> V_2 . V_57 ) {
V_54 = - V_29 ;
goto V_30;
}
V_8 = F_3 ( V_6 -> V_2 . V_57 ) ;
if ( ( V_54 = V_8 -> V_59 ? V_8 -> V_59 ( V_6 ) : 0 ) )
goto V_30;
V_6 -> V_27 = V_28 ;
V_30:
F_20 ( & V_6 -> V_25 , 0 ) ;
return V_54 ;
}
static T_1
F_48 ( struct V_1 * V_2 , struct V_21 * V_22 , const char * V_23 , T_2 V_15 )
{
struct V_5 * V_6 ;
struct V_7 * V_8 ;
unsigned long V_60 ;
int V_54 ;
if ( ! V_2 -> V_57 )
return - V_61 ;
V_6 = F_2 ( V_2 ) ;
V_8 = F_3 ( V_2 -> V_57 ) ;
if ( ! F_49 ( V_8 -> V_57 . V_62 ) )
return - V_29 ;
V_54 = F_50 ( V_23 , 0 , & V_60 ) ;
if ( V_54 )
goto V_30;
if ( V_60 == 1 )
V_54 = F_46 ( V_6 ) ;
else if ( V_60 == 0 )
V_54 = F_47 ( V_6 ) ;
else
V_54 = - V_29 ;
V_30:
F_51 ( V_8 -> V_57 . V_62 ) ;
return ( V_54 == 0 ) ? V_15 : V_54 ;
}
static T_1
F_52 ( struct V_1 * V_2 , struct V_21 * V_22 , char * V_23 )
{
int V_63 ;
V_63 = ( F_2 ( V_2 ) -> V_27 == V_56 ) ;
return sprintf ( V_23 , V_63 ? L_5 : L_6 ) ;
}
static int
F_53 ( struct V_1 * V_2 )
{
struct V_5 * V_6 ;
struct V_7 * V_8 ;
int V_54 ;
V_6 = F_2 ( V_2 ) ;
V_8 = F_3 ( V_2 -> V_57 ) ;
if ( ( V_54 = F_38 ( V_2 , & V_64 ) ) )
return V_54 ;
V_54 = V_8 -> V_65 ? V_8 -> V_65 ( V_6 ) : - V_61 ;
if ( V_54 )
F_39 ( V_2 , & V_64 ) ;
return V_54 ;
}
static int
F_54 ( struct V_1 * V_2 )
{
struct V_5 * V_6 ;
struct V_7 * V_8 ;
F_39 ( V_2 , & V_64 ) ;
F_39 ( V_2 , & V_53 ) ;
if ( ! V_2 -> V_57 )
return 0 ;
V_6 = F_2 ( V_2 ) ;
V_8 = F_3 ( V_2 -> V_57 ) ;
if ( V_8 -> remove )
V_8 -> remove ( V_6 ) ;
return 0 ;
}
static void F_55 ( struct V_1 * V_2 )
{
struct V_5 * V_6 ;
struct V_7 * V_8 ;
if ( ! V_2 -> V_57 )
return;
V_6 = F_2 ( V_2 ) ;
V_8 = F_3 ( V_2 -> V_57 ) ;
if ( V_8 -> V_66 )
V_8 -> V_66 ( V_6 ) ;
}
static int F_56 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = F_3 ( V_6 -> V_2 . V_57 ) ;
if ( F_57 ( & V_6 -> V_25 ) )
return - V_26 ;
if ( ! V_6 -> V_2 . V_57 || V_6 -> V_27 != V_56 )
return 0 ;
return V_8 -> V_67 ? V_8 -> V_67 ( V_6 ) : 0 ;
}
static void F_58 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = F_3 ( V_2 -> V_57 ) ;
if ( ! V_6 -> V_2 . V_57 || V_6 -> V_27 != V_56 )
return;
if ( V_8 -> V_68 )
V_8 -> V_68 ( V_6 ) ;
}
static int F_59 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = F_3 ( V_6 -> V_2 . V_57 ) ;
if ( ! V_6 -> V_2 . V_57 || V_6 -> V_27 != V_56 )
return 0 ;
return V_8 -> V_69 ? V_8 -> V_69 ( V_6 ) : 0 ;
}
static int F_60 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = F_3 ( V_6 -> V_2 . V_57 ) ;
if ( ! V_6 -> V_2 . V_57 || V_6 -> V_27 != V_56 )
return 0 ;
return V_8 -> V_70 ? V_8 -> V_70 ( V_6 ) : 0 ;
}
static int F_61 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = F_3 ( V_6 -> V_2 . V_57 ) ;
if ( ! V_6 -> V_2 . V_57 || V_6 -> V_27 != V_56 )
return 0 ;
return V_8 -> V_71 ? V_8 -> V_71 ( V_6 ) : 0 ;
}
static int F_62 ( struct V_72 * V_73 , unsigned long V_74 ,
void * V_75 )
{
struct V_1 * V_2 = V_75 ;
if ( V_74 == V_76 )
F_19 ( V_2 , F_12 ) ;
return V_77 ;
}
int F_63 ( struct V_7 * V_78 )
{
V_78 -> V_57 . V_47 = & V_48 ;
return F_64 ( & V_78 -> V_57 ) ;
}
static int
F_65 ( struct V_1 * V_2 , void * V_75 )
{
return 1 ;
}
void F_66 ( struct V_7 * V_78 )
{
struct V_1 * V_2 ;
F_67 ( & V_78 -> V_57 ) ;
while ( ( V_2 = F_68 ( & V_78 -> V_57 , NULL , NULL ,
F_65 ) ) ) {
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_13 ( & V_6 -> V_20 ) ;
F_5 ( V_6 ) ;
F_15 ( V_2 ) ;
F_7 ( V_6 ) ;
F_16 ( & V_6 -> V_20 ) ;
F_11 ( V_2 ) ;
}
F_69 ( & V_78 -> V_57 ) ;
F_70 ( & V_78 -> V_57 ) ;
}
int F_71 ( struct V_18 * V_17 )
{
return 0 ;
}
void F_72 ( struct V_18 * V_17 )
{
struct V_5 * V_6 ;
F_73 ( V_17 ) ;
F_8 ( V_17 -> V_19 ) ;
V_6 = F_33 ( & V_17 -> V_2 ) ;
if ( ! V_6 ) {
F_10 ( V_17 -> V_19 ) ;
return;
}
F_37 ( & V_6 -> V_2 ) ;
F_10 ( V_17 -> V_19 ) ;
F_13 ( & V_6 -> V_20 ) ;
if ( F_14 ( & V_6 -> V_2 ) ) {
F_5 ( V_6 ) ;
F_15 ( & V_6 -> V_2 ) ;
F_7 ( V_6 ) ;
}
F_16 ( & V_6 -> V_20 ) ;
F_11 ( & V_6 -> V_2 ) ;
}
