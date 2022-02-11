static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = F_3 ( V_4 ) ;
if ( V_6 -> V_9 == V_8 -> V_10 )
return 1 ;
return 0 ;
}
static void F_4 ( struct V_5 * V_6 )
{
int V_11 ;
char V_12 [ 8 ] ;
for ( V_11 = 0 ; V_11 < V_6 -> V_13 ; V_11 ++ ) {
sprintf ( V_12 , L_1 , V_11 ) ;
F_5 ( & V_6 -> V_2 . V_14 , V_12 ) ;
F_5 ( & V_6 -> V_15 [ V_11 ] -> V_2 . V_14 , L_2 ) ;
}
}
static void F_6 ( struct V_5 * V_6 )
{
struct V_16 * V_15 ;
int V_11 ;
for ( V_11 = 0 ; V_11 < V_6 -> V_13 ; V_11 ++ ) {
V_15 = V_6 -> V_15 [ V_11 ] ;
if ( ! V_15 )
continue;
F_7 ( V_15 -> V_17 ) ;
F_8 ( & V_15 -> V_2 , NULL ) ;
F_9 ( V_15 -> V_17 ) ;
V_6 -> V_15 [ V_11 ] = NULL ;
F_10 ( & V_15 -> V_2 ) ;
}
}
static int F_11 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = F_3 ( V_6 -> V_2 . V_18 ) ;
int V_19 = 0 ;
if ( F_12 ( & V_6 -> V_20 , 0 , 1 ) != 0 )
return - V_21 ;
if ( V_6 -> V_22 == V_23 )
goto V_24;
if ( V_8 -> V_25 )
V_19 = V_8 -> V_25 ( V_6 ) ;
if ( V_19 )
goto V_24;
V_6 -> V_22 = V_23 ;
V_24:
F_13 ( & V_6 -> V_20 , 0 ) ;
return V_19 ;
}
static int F_14 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = F_3 ( V_6 -> V_2 . V_18 ) ;
int V_19 = 0 ;
if ( F_12 ( & V_6 -> V_20 , 0 , 1 ) != 0 )
return - V_21 ;
if ( V_6 -> V_22 == V_26 )
goto V_24;
if ( V_8 -> V_27 )
V_19 = V_8 -> V_27 ( V_6 ) ;
if ( V_19 )
goto V_24;
V_6 -> V_22 = V_26 ;
V_24:
F_13 ( & V_6 -> V_20 , 0 ) ;
return V_19 ;
}
static T_1 F_15 ( struct V_1 * V_2 ,
struct V_28 * V_29 ,
const char * V_30 , T_2 V_13 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = F_3 ( V_2 -> V_18 ) ;
unsigned long V_31 ;
int V_19 ;
if ( ! V_2 -> V_18 )
return - V_32 ;
if ( ! F_16 ( V_8 -> V_18 . V_33 ) )
return - V_32 ;
V_19 = F_17 ( V_30 , 0 , & V_31 ) ;
if ( V_19 )
goto V_24;
if ( V_31 == 1 )
V_19 = F_11 ( V_6 ) ;
else if ( V_31 == 0 )
V_19 = F_14 ( V_6 ) ;
else
V_19 = - V_32 ;
V_24:
F_18 ( V_8 -> V_18 . V_33 ) ;
return ( V_19 == 0 ) ? V_13 : V_19 ;
}
static T_1 F_19 ( struct V_1 * V_2 ,
struct V_28 * V_29 ,
char * V_30 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_34 ;
V_34 = ( V_6 -> V_22 == V_23 ) ? 1 : 0 ;
return F_20 ( V_30 , V_35 , L_3 , V_34 ) ;
}
static void F_21 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_22 ( & V_6 -> V_36 ) ;
if ( F_23 ( & V_6 -> V_2 ) ) {
F_4 ( V_6 ) ;
F_24 ( V_2 ) ;
F_6 ( V_6 ) ;
}
F_25 ( & V_6 -> V_36 ) ;
}
static T_1 F_26 ( struct V_1 * V_2 ,
struct V_28 * V_29 ,
const char * V_30 , T_2 V_13 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_37 ;
if ( F_12 ( & V_6 -> V_20 , 0 , 1 ) != 0 )
return - V_21 ;
if ( V_6 -> V_22 != V_26 ) {
V_37 = - V_32 ;
goto V_24;
}
V_37 = F_27 ( V_2 , F_21 ) ;
V_24:
if ( V_37 ) {
if ( V_37 != - V_21 )
F_13 ( & V_6 -> V_20 , 0 ) ;
return V_37 ;
}
return V_13 ;
}
static void F_28 ( struct V_1 * V_2 )
{
F_29 ( F_2 ( V_2 ) ) ;
}
static int F_30 ( struct V_5 * V_6 )
{
char V_12 [ 8 ] ;
int V_11 , V_37 ;
for ( V_11 = 0 ; V_11 < V_6 -> V_13 ; V_11 ++ ) {
V_37 = F_31 ( & V_6 -> V_15 [ V_11 ] -> V_2 . V_14 ,
& V_6 -> V_2 . V_14 , L_2 ) ;
if ( V_37 ) {
for ( -- V_11 ; V_11 >= 0 ; V_11 -- )
F_5 ( & V_6 -> V_15 [ V_11 ] -> V_2 . V_14 ,
L_2 ) ;
return V_37 ;
}
}
for ( V_11 = 0 ; V_11 < V_6 -> V_13 ; V_11 ++ ) {
sprintf ( V_12 , L_1 , V_11 ) ;
V_37 = F_31 ( & V_6 -> V_2 . V_14 ,
& V_6 -> V_15 [ V_11 ] -> V_2 . V_14 , V_12 ) ;
if ( V_37 ) {
for ( -- V_11 ; V_11 >= 0 ; V_11 -- ) {
sprintf ( V_12 , L_1 , V_11 ) ;
F_5 ( & V_6 -> V_2 . V_14 , V_12 ) ;
}
for ( V_11 = 0 ; V_11 < V_6 -> V_13 ; V_11 ++ )
F_5 ( & V_6 -> V_15 [ V_11 ] -> V_2 . V_14 ,
L_2 ) ;
return V_37 ;
}
}
return 0 ;
}
static int F_32 ( const char * * V_30 , char * V_38 )
{
int V_37 , V_39 ;
char * V_40 , * V_41 ;
V_40 = ( char * ) * V_30 ;
V_41 = strchr ( V_40 , ',' ) ;
if ( ! V_41 ) {
V_41 = strchr ( V_40 , '\n' ) ;
if ( V_41 )
* V_41 = '\0' ;
V_39 = strlen ( V_40 ) + 1 ;
} else {
V_39 = V_41 - V_40 + 1 ;
V_41 ++ ;
}
if ( V_39 < V_42 ) {
F_33 ( V_38 , V_40 , V_39 ) ;
V_37 = 0 ;
} else
V_37 = - V_32 ;
* V_30 = V_41 ;
return V_37 ;
}
static int F_34 ( char V_38 [ V_42 ] )
{
int V_43 , V_44 , V_45 ;
if ( sscanf ( V_38 , L_4 , & V_43 , & V_44 , & V_45 ) != 3 )
return 0 ;
return 1 ;
}
int F_35 ( struct V_1 * V_46 , unsigned int V_9 ,
struct V_47 * V_48 , int V_49 ,
const char * V_30 )
{
struct V_5 * V_6 ;
int V_37 , V_11 ;
char V_50 [ V_42 ] ;
const char * V_51 ;
V_6 = F_36 ( sizeof( * V_6 ) + V_49 * sizeof( V_6 -> V_15 [ 0 ] ) ,
V_52 ) ;
if ( ! V_6 )
return - V_53 ;
F_13 ( & V_6 -> V_20 , 0 ) ;
F_37 ( & V_6 -> V_36 ) ;
F_22 ( & V_6 -> V_36 ) ;
V_6 -> V_9 = V_9 ;
V_6 -> V_13 = V_49 ;
V_6 -> V_2 . V_54 = & V_55 ;
V_6 -> V_2 . V_56 = V_46 ;
V_6 -> V_2 . V_57 = F_28 ;
F_38 ( & V_6 -> V_2 ) ;
V_51 = V_30 ;
for ( V_11 = 0 ; V_11 < V_49 && V_51 ; V_11 ++ ) {
V_37 = F_32 ( & V_51 , V_50 ) ;
if ( V_37 != 0 )
goto error;
if ( ! F_34 ( V_50 ) ) {
V_37 = - V_32 ;
goto error;
}
V_6 -> V_15 [ V_11 ] = F_39 ( V_48 , V_50 ) ;
if ( ! V_6 -> V_15 [ V_11 ]
|| V_6 -> V_15 [ V_11 ] -> V_58 . V_59 !=
V_6 -> V_15 [ 0 ] -> V_58 . V_59 ) {
V_37 = - V_32 ;
goto error;
}
F_7 ( V_6 -> V_15 [ V_11 ] -> V_17 ) ;
if ( F_40 ( & V_6 -> V_15 [ V_11 ] -> V_2 ) ) {
F_9 ( V_6 -> V_15 [ V_11 ] -> V_17 ) ;
V_37 = - V_32 ;
goto error;
}
F_8 ( & V_6 -> V_15 [ V_11 ] -> V_2 , V_6 ) ;
F_9 ( V_6 -> V_15 [ V_11 ] -> V_17 ) ;
}
if ( V_11 < V_49 && ! V_51 ) {
V_37 = - V_32 ;
goto error;
}
if ( V_11 == V_49 && strlen ( V_51 ) > 0 ) {
V_37 = - V_32 ;
goto error;
}
F_41 ( & V_6 -> V_2 , L_5 , F_42 ( & V_6 -> V_15 [ 0 ] -> V_2 ) ) ;
V_6 -> V_2 . V_60 = V_61 ;
V_37 = F_43 ( & V_6 -> V_2 ) ;
if ( V_37 )
goto error;
V_37 = F_30 ( V_6 ) ;
if ( V_37 ) {
F_44 ( & V_6 -> V_2 ) ;
goto error;
}
F_25 ( & V_6 -> V_36 ) ;
return 0 ;
error:
for ( V_11 = 0 ; V_11 < V_49 ; V_11 ++ )
if ( V_6 -> V_15 [ V_11 ] ) {
F_7 ( V_6 -> V_15 [ V_11 ] -> V_17 ) ;
if ( F_40 ( & V_6 -> V_15 [ V_11 ] -> V_2 ) == V_6 )
F_8 ( & V_6 -> V_15 [ V_11 ] -> V_2 , NULL ) ;
F_9 ( V_6 -> V_15 [ V_11 ] -> V_17 ) ;
F_10 ( & V_6 -> V_15 [ V_11 ] -> V_2 ) ;
V_6 -> V_15 [ V_11 ] = NULL ;
}
F_25 ( & V_6 -> V_36 ) ;
F_10 ( & V_6 -> V_2 ) ;
return V_37 ;
}
static int F_45 ( struct V_62 * V_63 , unsigned long V_64 ,
void * V_65 )
{
struct V_1 * V_2 = V_65 ;
if ( V_64 == V_66 )
F_27 ( V_2 , F_21 ) ;
return V_67 ;
}
static int T_3 F_46 ( void )
{
int V_19 ;
V_19 = F_47 ( & V_55 ) ;
if ( V_19 )
return V_19 ;
V_19 = F_48 ( & V_55 , & V_68 ) ;
if ( V_19 )
F_49 ( & V_55 ) ;
return V_19 ;
}
static void T_4 F_50 ( void )
{
F_51 ( & V_55 , & V_68 ) ;
F_49 ( & V_55 ) ;
}
static int F_52 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = F_3 ( V_2 -> V_18 ) ;
return V_8 -> V_69 ? V_8 -> V_69 ( V_6 ) : - V_70 ;
}
static int F_53 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = F_3 ( V_2 -> V_18 ) ;
if ( ! V_2 -> V_18 )
return 0 ;
if ( V_8 -> remove )
V_8 -> remove ( V_6 ) ;
return 0 ;
}
static void F_54 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = F_3 ( V_2 -> V_18 ) ;
if ( ! V_2 -> V_18 )
return;
if ( V_8 -> V_71 )
V_8 -> V_71 ( V_6 ) ;
}
static int F_55 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = F_3 ( V_6 -> V_2 . V_18 ) ;
if ( F_56 ( & V_6 -> V_20 ) )
return - V_21 ;
if ( ! V_6 -> V_2 . V_18 || V_6 -> V_22 != V_23 )
return 0 ;
return V_8 -> V_72 ? V_8 -> V_72 ( V_6 ) : 0 ;
}
static void F_57 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = F_3 ( V_2 -> V_18 ) ;
if ( ! V_6 -> V_2 . V_18 || V_6 -> V_22 != V_23 )
return;
if ( V_8 -> V_73 )
V_8 -> V_73 ( V_6 ) ;
}
static int F_58 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = F_3 ( V_6 -> V_2 . V_18 ) ;
if ( ! V_6 -> V_2 . V_18 || V_6 -> V_22 != V_23 )
return 0 ;
return V_8 -> V_74 ? V_8 -> V_74 ( V_6 ) : 0 ;
}
static int F_59 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = F_3 ( V_6 -> V_2 . V_18 ) ;
if ( ! V_6 -> V_2 . V_18 || V_6 -> V_22 != V_23 )
return 0 ;
return V_8 -> V_75 ? V_8 -> V_75 ( V_6 ) : 0 ;
}
static int F_60 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = F_3 ( V_6 -> V_2 . V_18 ) ;
if ( ! V_6 -> V_2 . V_18 || V_6 -> V_22 != V_23 )
return 0 ;
return V_8 -> V_76 ? V_8 -> V_76 ( V_6 ) : 0 ;
}
int F_61 ( struct V_7 * V_77 )
{
V_77 -> V_18 . V_54 = & V_55 ;
return F_62 ( & V_77 -> V_18 ) ;
}
static int F_63 ( struct V_1 * V_2 , void * V_65 )
{
return 1 ;
}
void F_64 ( struct V_7 * V_77 )
{
struct V_1 * V_2 ;
F_65 ( & V_77 -> V_18 ) ;
while ( ( V_2 = F_66 ( & V_77 -> V_18 , NULL , NULL ,
F_63 ) ) ) {
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_22 ( & V_6 -> V_36 ) ;
F_4 ( V_6 ) ;
F_24 ( V_2 ) ;
F_6 ( V_6 ) ;
F_25 ( & V_6 -> V_36 ) ;
F_10 ( V_2 ) ;
}
F_67 ( & V_77 -> V_18 ) ;
F_68 ( & V_77 -> V_18 ) ;
}
int F_69 ( struct V_16 * V_15 )
{
return 0 ;
}
void F_70 ( struct V_16 * V_15 )
{
struct V_5 * V_6 ;
F_71 ( V_15 ) ;
F_7 ( V_15 -> V_17 ) ;
V_6 = F_40 ( & V_15 -> V_2 ) ;
if ( ! V_6 ) {
F_9 ( V_15 -> V_17 ) ;
return;
}
F_72 ( & V_6 -> V_2 ) ;
F_9 ( V_15 -> V_17 ) ;
F_22 ( & V_6 -> V_36 ) ;
if ( F_23 ( & V_6 -> V_2 ) ) {
F_4 ( V_6 ) ;
F_24 ( & V_6 -> V_2 ) ;
F_6 ( V_6 ) ;
}
F_25 ( & V_6 -> V_36 ) ;
F_10 ( & V_6 -> V_2 ) ;
}
