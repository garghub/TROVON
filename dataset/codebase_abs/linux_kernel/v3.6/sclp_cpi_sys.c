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
V_8 -> V_9 . V_14 . type = 0x0b ;
V_10 = & V_8 -> V_9 ;
F_1 ( V_10 -> V_16 , V_16 ) ;
F_1 ( V_10 -> V_17 , V_17 ) ;
V_10 -> V_18 = V_18 ;
F_1 ( V_10 -> V_19 , V_19 ) ;
V_5 -> V_20 = V_21 ;
V_5 -> V_8 = V_8 ;
V_5 -> V_22 = V_23 ;
V_5 -> V_24 = F_3 ;
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
int V_25 ;
int V_26 ;
V_25 = F_13 ( & V_27 ) ;
if ( V_25 )
goto V_28;
if ( ! ( V_27 . V_29 & V_30 ) ) {
V_25 = - V_31 ;
goto V_32;
}
V_5 = F_5 () ;
if ( F_14 ( V_5 ) ) {
V_25 = F_15 ( V_5 ) ;
goto V_32;
}
F_16 ( & V_6 ) ;
V_5 -> V_33 = & V_6 ;
V_25 = F_17 ( V_5 ) ;
if ( V_25 )
goto V_34;
F_18 ( & V_6 ) ;
if ( V_5 -> V_22 != V_35 ) {
F_19 ( L_1 ,
V_5 -> V_22 ) ;
V_25 = - V_36 ;
goto V_34;
}
V_26 = ( (struct V_7 * ) V_5 -> V_8 ) -> V_14 . V_37 ;
if ( V_26 != 0x0020 ) {
F_19 ( L_2 ,
V_26 ) ;
V_25 = - V_36 ;
}
V_34:
F_10 ( V_5 ) ;
V_32:
F_20 ( & V_27 ) ;
V_28:
return V_25 ;
}
static int F_21 ( const char * V_38 , const char * V_39 )
{
T_1 V_40 ;
T_1 V_41 ;
V_40 = strlen ( V_39 ) ;
if ( ( V_40 > 0 ) && ( V_39 [ V_40 - 1 ] == '\n' ) )
V_40 -- ;
if ( V_40 > V_3 )
return - V_42 ;
for ( V_41 = 0 ; V_41 < V_40 ; V_41 ++ ) {
if ( isalpha ( V_39 [ V_41 ] ) || isdigit ( V_39 [ V_41 ] ) ||
strchr ( L_3 , V_39 [ V_41 ] ) )
continue;
return - V_42 ;
}
return 0 ;
}
static void F_22 ( char * V_38 , const char * V_43 )
{
T_1 V_40 ;
T_1 V_41 ;
V_40 = strlen ( V_43 ) ;
if ( ( V_40 > 0 ) && ( V_43 [ V_40 - 1 ] == '\n' ) )
V_40 -- ;
for ( V_41 = 0 ; V_41 < V_3 ; V_41 ++ ) {
if ( V_41 < V_40 )
V_38 [ V_41 ] = toupper ( V_43 [ V_41 ] ) ;
else
V_38 [ V_41 ] = ' ' ;
}
}
static T_2 F_23 ( struct V_44 * V_45 ,
struct V_46 * V_38 , char * V_47 )
{
int V_25 ;
F_24 ( & V_48 ) ;
V_25 = snprintf ( V_47 , V_49 , L_4 , V_17 ) ;
F_25 ( & V_48 ) ;
return V_25 ;
}
static T_2 F_26 ( struct V_44 * V_45 ,
struct V_46 * V_38 ,
const char * V_50 ,
T_1 V_40 )
{
int V_25 ;
V_25 = F_21 ( L_5 , V_50 ) ;
if ( V_25 )
return V_25 ;
F_24 ( & V_48 ) ;
F_22 ( V_17 , V_50 ) ;
F_25 ( & V_48 ) ;
return V_40 ;
}
static T_2 F_27 ( struct V_44 * V_45 ,
struct V_46 * V_38 , char * V_47 )
{
int V_25 ;
F_24 ( & V_48 ) ;
V_25 = snprintf ( V_47 , V_49 , L_4 , V_19 ) ;
F_25 ( & V_48 ) ;
return V_25 ;
}
static T_2 F_28 ( struct V_44 * V_45 ,
struct V_46 * V_38 ,
const char * V_50 ,
T_1 V_40 )
{
int V_25 ;
V_25 = F_21 ( L_6 , V_50 ) ;
if ( V_25 )
return V_25 ;
F_24 ( & V_48 ) ;
F_22 ( V_19 , V_50 ) ;
F_25 ( & V_48 ) ;
return V_40 ;
}
static T_2 F_29 ( struct V_44 * V_45 ,
struct V_46 * V_38 , char * V_47 )
{
int V_25 ;
F_24 ( & V_48 ) ;
V_25 = snprintf ( V_47 , V_49 , L_4 , V_16 ) ;
F_25 ( & V_48 ) ;
return V_25 ;
}
static T_2 F_30 ( struct V_44 * V_45 ,
struct V_46 * V_38 ,
const char * V_50 ,
T_1 V_40 )
{
int V_25 ;
V_25 = F_21 ( L_7 , V_50 ) ;
if ( V_25 )
return V_25 ;
F_24 ( & V_48 ) ;
F_22 ( V_16 , V_50 ) ;
F_25 ( & V_48 ) ;
return V_40 ;
}
static T_2 F_31 ( struct V_44 * V_45 ,
struct V_46 * V_38 , char * V_47 )
{
unsigned long long V_51 ;
F_24 ( & V_48 ) ;
V_51 = V_18 ;
F_25 ( & V_48 ) ;
return snprintf ( V_47 , V_49 , L_8 , V_51 ) ;
}
static T_2 F_32 ( struct V_44 * V_45 ,
struct V_46 * V_38 ,
const char * V_50 ,
T_1 V_40 )
{
unsigned long long V_51 ;
char * V_52 ;
V_51 = F_33 ( V_50 , & V_52 , 16 ) ;
if ( V_52 == V_50 )
return - V_42 ;
if ( * V_52 == '\n' )
V_52 ++ ;
if ( * V_52 )
return - V_42 ;
F_24 ( & V_48 ) ;
V_18 = V_51 ;
F_25 ( & V_48 ) ;
return V_40 ;
}
static T_2 F_34 ( struct V_44 * V_45 ,
struct V_46 * V_38 ,
const char * V_50 , T_1 V_40 )
{
int V_25 ;
F_24 ( & V_48 ) ;
V_25 = F_12 () ;
F_25 ( & V_48 ) ;
if ( V_25 )
return V_25 ;
return V_40 ;
}
int F_35 ( const char * system , const char * V_53 , const char * type ,
const T_3 V_51 )
{
int V_25 ;
V_25 = F_21 ( L_5 , system ) ;
if ( V_25 )
return V_25 ;
V_25 = F_21 ( L_6 , V_53 ) ;
if ( V_25 )
return V_25 ;
V_25 = F_21 ( L_7 , type ) ;
if ( V_25 )
return V_25 ;
F_24 ( & V_48 ) ;
F_22 ( V_17 , system ) ;
F_22 ( V_19 , V_53 ) ;
F_22 ( V_16 , type ) ;
V_18 = V_51 ;
V_25 = F_12 () ;
F_25 ( & V_48 ) ;
return V_25 ;
}
static int T_4 F_36 ( void )
{
int V_25 ;
V_54 = F_37 ( L_9 , NULL , V_55 ) ;
if ( ! V_54 )
return - V_12 ;
V_25 = F_38 ( & V_54 -> V_45 , & V_56 ) ;
if ( V_25 )
F_39 ( V_54 ) ;
return V_25 ;
}
