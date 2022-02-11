static int T_1 F_1 ( char * V_1 )
{
if ( strncmp ( V_1 , L_1 , 3 ) == 0 )
V_2 = 1 ;
return 0 ;
}
static void T_1 F_2 ( void )
{
#ifdef F_3
V_3 |= V_4 ;
#endif
F_4 ( L_2 , V_3 ) ;
}
static int F_5 ( struct V_5 * V_5 )
{
struct V_6 * V_6 = V_5 -> V_7 ;
char * * V_8 ;
int error ;
int V_9 = 0 ;
if ( ! V_6 -> V_10 -> V_11 )
return - V_12 ;
for ( V_8 = V_13 ; * V_8 != NULL ; V_8 ++ ) {
error = V_6 -> V_10 -> V_11 ( V_5 , * V_8 , NULL , 0 ) ;
if ( error < 0 ) {
if ( error == - V_14 )
continue;
return error ;
}
V_9 ++ ;
}
return V_9 ;
}
static enum V_15 F_6 ( struct V_5 * V_5 ,
const char * V_16 ,
char * V_17 ,
T_2 V_18 ,
struct V_19 * V_20 )
{
struct V_21 * V_22 = NULL ;
struct V_21 V_23 ;
enum V_15 V_24 = V_25 ;
int V_26 , V_27 ;
if ( V_20 && V_20 -> V_24 == V_25 )
return V_20 -> V_24 ;
V_26 = F_7 ( V_5 , V_28 , ( char * * ) & V_22 , 0 ,
V_29 ) ;
if ( V_26 <= 0 ) {
if ( V_26 == 0 )
V_24 = V_30 ;
else if ( V_26 == - V_14 ) {
V_26 = F_5 ( V_5 ) ;
if ( V_26 > 0 )
V_24 = V_31 ;
else if ( V_26 == 0 )
V_24 = V_32 ;
}
goto V_33;
}
V_27 = V_26 ;
switch ( V_22 -> type ) {
case V_34 :
V_26 = F_8 ( V_5 , V_16 , V_17 ,
V_18 , V_23 . V_35 ) ;
if ( V_26 )
break;
V_26 = memcmp ( V_22 -> V_35 , V_23 . V_35 ,
sizeof( V_23 . V_35 ) ) ;
if ( V_26 )
V_26 = - V_36 ;
break;
case V_37 :
V_26 = F_9 ( V_5 , V_16 , V_17 ,
V_18 , V_23 . V_35 ) ;
if ( V_26 )
break;
V_26 = F_10 ( V_38 ,
( const char * ) V_22 , V_27 ,
V_23 . V_35 , sizeof( V_23 . V_35 ) ) ;
if ( ! V_26 ) {
F_11 ( V_5 , V_16 , V_17 ,
V_18 ) ;
}
break;
default:
V_26 = - V_36 ;
break;
}
if ( V_26 )
V_24 = ( V_26 == - V_14 ) ?
V_32 : V_30 ;
V_33:
if ( V_20 )
V_20 -> V_24 = V_24 ;
F_12 ( V_22 ) ;
return V_24 ;
}
static int F_13 ( const char * V_39 )
{
char * * V_40 ;
int V_41 ;
int V_42 = 0 ;
V_41 = strlen ( V_39 ) ;
for ( V_40 = V_13 ; * V_40 != NULL ; V_40 ++ ) {
if ( ( strlen ( * V_40 ) == V_41 )
&& ( strncmp ( V_39 , * V_40 , V_41 ) == 0 ) ) {
V_42 = 1 ;
break;
}
if ( strncmp ( V_39 ,
* V_40 + V_43 ,
strlen ( V_39 ) ) == 0 ) {
V_42 = 1 ;
break;
}
}
return V_42 ;
}
enum V_15 F_14 ( struct V_5 * V_5 ,
const char * V_16 ,
void * V_17 , T_2 V_18 ,
struct V_19 * V_20 )
{
if ( ! V_44 || ! F_13 ( V_16 ) )
return V_45 ;
if ( ! V_20 ) {
V_20 = F_15 ( V_5 -> V_7 ) ;
if ( ! V_20 )
return V_45 ;
}
return F_6 ( V_5 , V_16 , V_17 ,
V_18 , V_20 ) ;
}
static enum V_15 F_16 ( struct V_5 * V_5 )
{
struct V_6 * V_6 = V_5 -> V_7 ;
if ( ! V_44 || ! F_17 ( V_6 -> V_46 ) || V_2 )
return 0 ;
return F_6 ( V_5 , NULL , NULL , 0 , NULL ) ;
}
static int F_18 ( struct V_5 * V_5 , const char * V_16 ,
const void * V_17 , T_2 V_18 )
{
enum V_15 V_24 ;
if ( strcmp ( V_16 , V_28 ) == 0 ) {
if ( ! F_19 ( V_47 ) )
return - V_48 ;
} else if ( ! F_13 ( V_16 ) ) {
if ( ! F_20 ( V_16 ) )
return 0 ;
V_24 = F_16 ( V_5 ) ;
if ( ( V_24 == V_25 ) ||
( V_24 == V_32 ) )
return 0 ;
goto V_33;
}
V_24 = F_16 ( V_5 ) ;
V_33:
if ( V_24 != V_25 )
F_21 ( V_49 , V_5 -> V_7 ,
V_5 -> V_50 . V_51 , L_3 ,
V_52 [ V_24 ] ,
- V_48 , 0 ) ;
return V_24 == V_25 ? 0 : - V_48 ;
}
int F_22 ( struct V_5 * V_5 , const char * V_16 ,
const void * V_17 , T_2 V_18 )
{
const struct V_21 * V_22 = V_17 ;
if ( ( strcmp ( V_16 , V_28 ) == 0 )
&& ( V_22 -> type == V_34 ) )
return - V_48 ;
return F_18 ( V_5 , V_16 , V_17 ,
V_18 ) ;
}
int F_23 ( struct V_5 * V_5 , const char * V_16 )
{
return F_18 ( V_5 , V_16 , NULL , 0 ) ;
}
void F_24 ( struct V_5 * V_5 , const char * V_16 ,
const void * V_17 , T_2 V_18 )
{
if ( ! V_44 || ( ! F_13 ( V_16 )
&& ! F_20 ( V_16 ) ) )
return;
F_11 ( V_5 , V_16 , V_17 , V_18 ) ;
return;
}
void F_25 ( struct V_5 * V_5 , const char * V_16 )
{
struct V_6 * V_6 = V_5 -> V_7 ;
if ( ! V_44 || ! F_13 ( V_16 ) )
return;
F_26 ( & V_6 -> V_53 ) ;
F_11 ( V_5 , V_16 , NULL , 0 ) ;
F_27 ( & V_6 -> V_53 ) ;
return;
}
int F_28 ( struct V_5 * V_5 , struct V_54 * V_55 )
{
unsigned int V_56 = V_55 -> V_56 ;
enum V_15 V_24 ;
if ( ! ( V_56 & ( V_57 | V_58 | V_59 ) ) )
return 0 ;
V_24 = F_16 ( V_5 ) ;
if ( ( V_24 == V_25 ) ||
( V_24 == V_32 ) )
return 0 ;
F_21 ( V_49 , V_5 -> V_7 ,
V_5 -> V_50 . V_51 , L_3 ,
V_52 [ V_24 ] , - V_48 , 0 ) ;
return - V_48 ;
}
void F_29 ( struct V_5 * V_5 , int V_56 )
{
if ( ! V_44 )
return;
if ( V_56 & ( V_57 | V_58 | V_59 ) )
F_11 ( V_5 , NULL , NULL , 0 ) ;
return;
}
int F_30 ( struct V_6 * V_6 ,
const struct V_8 * V_60 ,
struct V_8 * V_61 )
{
struct V_21 * V_22 ;
int V_26 ;
if ( ! V_44 || ! F_13 ( V_60 -> V_51 ) )
return 0 ;
V_22 = F_31 ( sizeof( * V_22 ) , V_29 ) ;
if ( ! V_22 )
return - V_62 ;
V_22 -> type = V_34 ;
V_26 = F_32 ( V_6 , V_60 , V_22 -> V_35 ) ;
if ( V_26 < 0 )
goto V_33;
V_61 -> V_63 = V_22 ;
V_61 -> V_64 = sizeof( * V_22 ) ;
V_61 -> V_51 = V_65 ;
return 0 ;
V_33:
F_12 ( V_22 ) ;
return V_26 ;
}
static int T_1 F_33 ( void )
{
int error ;
F_2 () ;
error = F_34 () ;
if ( error < 0 ) {
F_4 ( L_4 ) ;
goto V_66;
}
return 0 ;
V_66:
return error ;
}
static int T_1 F_35 ( void )
{
char * * V_40 ;
for ( V_40 = V_13 ; * V_40 != NULL ; V_40 ++ )
F_4 ( L_5 , * V_40 ) ;
return 0 ;
}
