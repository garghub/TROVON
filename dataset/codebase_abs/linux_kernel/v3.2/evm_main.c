static int T_1 F_1 ( char * V_1 )
{
if ( strncmp ( V_1 , L_1 , 3 ) == 0 )
V_2 = 1 ;
return 0 ;
}
static enum V_3 F_2 ( struct V_4 * V_4 ,
const char * V_5 ,
char * V_6 ,
T_2 V_7 ,
struct V_8 * V_9 )
{
struct V_10 V_11 ;
enum V_3 V_12 = V_13 ;
int V_14 ;
if ( V_9 && V_9 -> V_12 == V_13 )
return V_9 -> V_12 ;
V_14 = F_3 ( V_4 , V_5 , V_6 ,
V_7 , V_11 . V_15 ) ;
if ( V_14 < 0 ) {
V_12 = ( V_14 == - V_16 )
? V_17 : V_18 ;
goto V_19;
}
V_11 . type = V_20 ;
V_14 = F_4 ( V_4 , V_21 , ( V_22 * ) & V_11 ,
sizeof V_11 , V_23 ) ;
if ( V_14 < 0 )
V_12 = ( V_14 == - V_16 )
? V_24 : V_18 ;
V_19:
if ( V_9 )
V_9 -> V_12 = V_12 ;
return V_12 ;
}
static int F_5 ( const char * V_25 )
{
char * * V_26 ;
int V_27 ;
int V_28 = 0 ;
V_27 = strlen ( V_25 ) ;
for ( V_26 = V_29 ; * V_26 != NULL ; V_26 ++ ) {
if ( ( strlen ( * V_26 ) == V_27 )
&& ( strncmp ( V_25 , * V_26 , V_27 ) == 0 ) ) {
V_28 = 1 ;
break;
}
if ( strncmp ( V_25 ,
* V_26 + V_30 ,
strlen ( V_25 ) ) == 0 ) {
V_28 = 1 ;
break;
}
}
return V_28 ;
}
enum V_3 F_6 ( struct V_4 * V_4 ,
const char * V_5 ,
void * V_6 , T_2 V_7 ,
struct V_8 * V_9 )
{
if ( ! V_31 || ! F_5 ( V_5 ) )
return V_32 ;
if ( ! V_9 ) {
V_9 = F_7 ( V_4 -> V_33 ) ;
if ( ! V_9 )
return V_32 ;
}
return F_2 ( V_4 , V_5 , V_6 ,
V_7 , V_9 ) ;
}
static enum V_3 F_8 ( struct V_4 * V_4 )
{
struct V_34 * V_34 = V_4 -> V_33 ;
if ( ! V_31 || ! F_9 ( V_34 -> V_35 ) || V_2 )
return 0 ;
return F_2 ( V_4 , NULL , NULL , 0 , NULL ) ;
}
static int F_10 ( struct V_4 * V_4 , const char * V_5 ,
const void * V_6 , T_2 V_7 )
{
enum V_3 V_12 ;
if ( strcmp ( V_5 , V_21 ) == 0 ) {
if ( ! F_11 ( V_36 ) )
return - V_37 ;
} else if ( ! F_5 ( V_5 ) ) {
if ( ! F_12 ( V_5 ) )
return 0 ;
V_12 = F_8 ( V_4 ) ;
if ( ( V_12 == V_13 ) ||
( V_12 == V_17 ) )
return 0 ;
return - V_37 ;
}
V_12 = F_8 ( V_4 ) ;
return V_12 == V_13 ? 0 : - V_37 ;
}
int F_13 ( struct V_4 * V_4 , const char * V_5 ,
const void * V_6 , T_2 V_7 )
{
return F_10 ( V_4 , V_5 , V_6 ,
V_7 ) ;
}
int F_14 ( struct V_4 * V_4 , const char * V_5 )
{
return F_10 ( V_4 , V_5 , NULL , 0 ) ;
}
void F_15 ( struct V_4 * V_4 , const char * V_5 ,
const void * V_6 , T_2 V_7 )
{
if ( ! V_31 || ( ! F_5 ( V_5 )
&& ! F_12 ( V_5 ) ) )
return;
F_16 ( V_4 , V_5 , V_6 , V_7 ) ;
return;
}
void F_17 ( struct V_4 * V_4 , const char * V_5 )
{
struct V_34 * V_34 = V_4 -> V_33 ;
if ( ! V_31 || ! F_5 ( V_5 ) )
return;
F_18 ( & V_34 -> V_38 ) ;
F_16 ( V_4 , V_5 , NULL , 0 ) ;
F_19 ( & V_34 -> V_38 ) ;
return;
}
int F_20 ( struct V_4 * V_4 , struct V_39 * V_40 )
{
unsigned int V_41 = V_40 -> V_41 ;
enum V_3 V_12 ;
if ( ! ( V_41 & ( V_42 | V_43 | V_44 ) ) )
return 0 ;
V_12 = F_8 ( V_4 ) ;
if ( ( V_12 == V_13 ) ||
( V_12 == V_17 ) )
return 0 ;
return - V_37 ;
}
void F_21 ( struct V_4 * V_4 , int V_41 )
{
if ( ! V_31 )
return;
if ( V_41 & ( V_42 | V_43 | V_44 ) )
F_16 ( V_4 , NULL , NULL , 0 ) ;
return;
}
int F_22 ( struct V_34 * V_34 ,
const struct V_45 * V_46 ,
struct V_45 * V_47 )
{
struct V_10 * V_11 ;
int V_14 ;
if ( ! V_31 || ! F_5 ( V_46 -> V_48 ) )
return 0 ;
V_11 = F_23 ( sizeof( * V_11 ) , V_23 ) ;
if ( ! V_11 )
return - V_49 ;
V_11 -> type = V_20 ;
V_14 = F_24 ( V_34 , V_46 , V_11 -> V_15 ) ;
if ( V_14 < 0 )
goto V_19;
V_47 -> V_50 = V_11 ;
V_47 -> V_51 = sizeof( * V_11 ) ;
V_47 -> V_48 = F_25 ( V_52 , V_23 ) ;
return 0 ;
V_19:
F_26 ( V_11 ) ;
return V_14 ;
}
static int T_1 F_27 ( void )
{
int error ;
error = F_28 () ;
if ( error < 0 ) {
F_29 ( V_53 L_2 ) ;
goto V_54;
}
V_54:
return error ;
}
static void T_3 F_30 ( void )
{
F_31 () ;
if ( V_55 )
F_32 ( V_55 ) ;
}
static int T_1 F_33 ( void )
{
char * * V_26 ;
for ( V_26 = V_29 ; * V_26 != NULL ; V_26 ++ )
F_29 ( V_53 L_3 , * V_26 ) ;
return 0 ;
}
