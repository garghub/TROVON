static void F_1 ( char * V_1 , char * V_2 )
{
memset ( V_1 , ' ' , V_3 ) ;
memcpy ( V_1 , V_2 , strlen ( V_2 ) ) ;
F_2 ( V_1 , V_3 ) ;
}
static void F_3 ( struct V_4 * V_5 , void * V_2 )
{
struct V_6 * V_6 = V_2 ;
F_4 ( V_6 ) ;
}
static struct V_4 * F_5 ( void )
{
struct V_4 * V_5 ;
struct V_7 * V_8 ;
struct V_9 * V_10 ;
V_5 = F_6 ( sizeof( struct V_4 ) , V_11 ) ;
if ( ! V_5 )
return F_7 ( - V_12 ) ;
V_8 = (struct V_7 * ) F_8 ( V_11 | V_13 ) ;
if ( ! V_8 ) {
F_9 ( V_5 ) ;
return F_7 ( - V_12 ) ;
}
V_8 -> V_14 . V_15 = sizeof( struct V_7 ) ;
V_8 -> V_9 . V_14 . V_15 = sizeof( struct V_9 ) ;
V_8 -> V_9 . V_14 . type = V_16 ;
V_10 = & V_8 -> V_9 ;
F_1 ( V_10 -> V_17 , V_17 ) ;
F_1 ( V_10 -> V_18 , V_18 ) ;
V_10 -> V_19 = V_19 ;
F_1 ( V_10 -> V_20 , V_20 ) ;
V_5 -> V_21 = V_22 ;
V_5 -> V_8 = V_8 ;
V_5 -> V_23 = V_24 ;
V_5 -> V_25 = F_3 ;
return V_5 ;
}
static void F_10 ( struct V_4 * V_5 )
{
F_11 ( ( unsigned long ) V_5 -> V_8 ) ;
F_9 ( V_5 ) ;
}
static int F_12 ( void )
{
struct V_6 V_6 ;
struct V_4 * V_5 ;
int V_26 ;
int V_27 ;
V_26 = F_13 ( & V_28 ) ;
if ( V_26 )
goto V_29;
if ( ! ( V_28 . V_30 & V_31 ) ) {
V_26 = - V_32 ;
goto V_33;
}
V_5 = F_5 () ;
if ( F_14 ( V_5 ) ) {
V_26 = F_15 ( V_5 ) ;
goto V_33;
}
F_16 ( & V_6 ) ;
V_5 -> V_34 = & V_6 ;
V_26 = F_17 ( V_5 ) ;
if ( V_26 )
goto V_35;
F_18 ( & V_6 ) ;
if ( V_5 -> V_23 != V_36 ) {
F_19 ( L_1 , V_5 -> V_23 ) ;
V_26 = - V_37 ;
goto V_35;
}
V_27 = ( (struct V_7 * ) V_5 -> V_8 ) -> V_14 . V_38 ;
if ( V_27 != 0x0020 ) {
F_19 ( L_2 , V_27 ) ;
V_26 = - V_37 ;
}
V_35:
F_10 ( V_5 ) ;
V_33:
F_20 ( & V_28 ) ;
V_29:
return V_26 ;
}
static int F_21 ( const char * V_39 , const char * V_40 )
{
T_1 V_41 ;
T_1 V_42 ;
V_41 = strlen ( V_40 ) ;
if ( ( V_41 > 0 ) && ( V_40 [ V_41 - 1 ] == '\n' ) )
V_41 -- ;
if ( V_41 > V_3 )
return - V_43 ;
for ( V_42 = 0 ; V_42 < V_41 ; V_42 ++ ) {
if ( isalpha ( V_40 [ V_42 ] ) || isdigit ( V_40 [ V_42 ] ) ||
strchr ( L_3 , V_40 [ V_42 ] ) )
continue;
return - V_43 ;
}
return 0 ;
}
static void F_22 ( char * V_39 , const char * V_44 )
{
T_1 V_41 ;
T_1 V_42 ;
V_41 = strlen ( V_44 ) ;
if ( ( V_41 > 0 ) && ( V_44 [ V_41 - 1 ] == '\n' ) )
V_41 -- ;
for ( V_42 = 0 ; V_42 < V_3 ; V_42 ++ ) {
if ( V_42 < V_41 )
V_39 [ V_42 ] = toupper ( V_44 [ V_42 ] ) ;
else
V_39 [ V_42 ] = ' ' ;
}
}
static T_2 F_23 ( struct V_45 * V_46 ,
struct V_47 * V_39 , char * V_48 )
{
int V_26 ;
F_24 ( & V_49 ) ;
V_26 = snprintf ( V_48 , V_50 , L_4 , V_18 ) ;
F_25 ( & V_49 ) ;
return V_26 ;
}
static T_2 F_26 ( struct V_45 * V_46 ,
struct V_47 * V_39 ,
const char * V_51 ,
T_1 V_41 )
{
int V_26 ;
V_26 = F_21 ( L_5 , V_51 ) ;
if ( V_26 )
return V_26 ;
F_24 ( & V_49 ) ;
F_22 ( V_18 , V_51 ) ;
F_25 ( & V_49 ) ;
return V_41 ;
}
static T_2 F_27 ( struct V_45 * V_46 ,
struct V_47 * V_39 , char * V_48 )
{
int V_26 ;
F_24 ( & V_49 ) ;
V_26 = snprintf ( V_48 , V_50 , L_4 , V_20 ) ;
F_25 ( & V_49 ) ;
return V_26 ;
}
static T_2 F_28 ( struct V_45 * V_46 ,
struct V_47 * V_39 ,
const char * V_51 ,
T_1 V_41 )
{
int V_26 ;
V_26 = F_21 ( L_6 , V_51 ) ;
if ( V_26 )
return V_26 ;
F_24 ( & V_49 ) ;
F_22 ( V_20 , V_51 ) ;
F_25 ( & V_49 ) ;
return V_41 ;
}
static T_2 F_29 ( struct V_45 * V_46 ,
struct V_47 * V_39 , char * V_48 )
{
int V_26 ;
F_24 ( & V_49 ) ;
V_26 = snprintf ( V_48 , V_50 , L_4 , V_17 ) ;
F_25 ( & V_49 ) ;
return V_26 ;
}
static T_2 F_30 ( struct V_45 * V_46 ,
struct V_47 * V_39 ,
const char * V_51 ,
T_1 V_41 )
{
int V_26 ;
V_26 = F_21 ( L_7 , V_51 ) ;
if ( V_26 )
return V_26 ;
F_24 ( & V_49 ) ;
F_22 ( V_17 , V_51 ) ;
F_25 ( & V_49 ) ;
return V_41 ;
}
static T_2 F_31 ( struct V_45 * V_46 ,
struct V_47 * V_39 , char * V_48 )
{
unsigned long long V_52 ;
F_24 ( & V_49 ) ;
V_52 = V_19 ;
F_25 ( & V_49 ) ;
return snprintf ( V_48 , V_50 , L_8 , V_52 ) ;
}
static T_2 F_32 ( struct V_45 * V_46 ,
struct V_47 * V_39 ,
const char * V_51 ,
T_1 V_41 )
{
unsigned long long V_52 ;
char * V_53 ;
V_52 = F_33 ( V_51 , & V_53 , 16 ) ;
if ( V_53 == V_51 )
return - V_43 ;
if ( * V_53 == '\n' )
V_53 ++ ;
if ( * V_53 )
return - V_43 ;
F_24 ( & V_49 ) ;
V_19 = V_52 ;
F_25 ( & V_49 ) ;
return V_41 ;
}
static T_2 F_34 ( struct V_45 * V_46 ,
struct V_47 * V_39 ,
const char * V_51 , T_1 V_41 )
{
int V_26 ;
F_24 ( & V_49 ) ;
V_26 = F_12 () ;
F_25 ( & V_49 ) ;
if ( V_26 )
return V_26 ;
return V_41 ;
}
int F_35 ( const char * system , const char * V_54 , const char * type ,
const T_3 V_52 )
{
int V_26 ;
V_26 = F_21 ( L_5 , system ) ;
if ( V_26 )
return V_26 ;
V_26 = F_21 ( L_6 , V_54 ) ;
if ( V_26 )
return V_26 ;
V_26 = F_21 ( L_7 , type ) ;
if ( V_26 )
return V_26 ;
F_24 ( & V_49 ) ;
F_22 ( V_18 , system ) ;
F_22 ( V_20 , V_54 ) ;
F_22 ( V_17 , type ) ;
V_19 = V_52 ;
V_26 = F_12 () ;
F_25 ( & V_49 ) ;
return V_26 ;
}
static int T_4 F_36 ( void )
{
int V_26 ;
V_55 = F_37 ( L_9 , NULL , V_56 ) ;
if ( ! V_55 )
return - V_12 ;
V_26 = F_38 ( & V_55 -> V_46 , & V_57 ) ;
if ( V_26 )
F_39 ( V_55 ) ;
return V_26 ;
}
