static int T_1 F_1 ( char * V_1 )
{
if ( strncmp ( V_1 , L_1 , 3 ) == 0 )
V_2 = 1 ;
return 0 ;
}
static int F_2 ( struct V_3 * V_3 )
{
struct V_4 * V_4 = V_3 -> V_5 ;
char * * V_6 ;
int error ;
int V_7 = 0 ;
if ( ! V_4 -> V_8 || ! V_4 -> V_8 -> V_9 )
return - V_10 ;
for ( V_6 = V_11 ; * V_6 != NULL ; V_6 ++ ) {
error = V_4 -> V_8 -> V_9 ( V_3 , * V_6 , NULL , 0 ) ;
if ( error < 0 ) {
if ( error == - V_12 )
continue;
return error ;
}
V_7 ++ ;
}
return V_7 ;
}
static enum V_13 F_3 ( struct V_3 * V_3 ,
const char * V_14 ,
char * V_15 ,
T_2 V_16 ,
struct V_17 * V_18 )
{
struct V_19 * V_20 = NULL ;
struct V_19 V_21 ;
enum V_13 V_22 = V_23 ;
int V_24 , V_25 ;
if ( V_18 && V_18 -> V_22 == V_23 )
return V_18 -> V_22 ;
V_24 = F_4 ( V_3 , V_26 , ( char * * ) & V_20 , 0 ,
V_27 ) ;
if ( V_24 <= 0 ) {
if ( V_24 == 0 )
V_22 = V_28 ;
else if ( V_24 == - V_12 ) {
V_24 = F_2 ( V_3 ) ;
if ( V_24 > 0 )
V_22 = V_29 ;
else if ( V_24 == 0 )
V_22 = V_30 ;
}
goto V_31;
}
V_25 = V_24 - 1 ;
switch ( V_20 -> type ) {
case V_32 :
V_24 = F_5 ( V_3 , V_14 , V_15 ,
V_16 , V_21 . V_33 ) ;
if ( V_24 )
break;
V_24 = memcmp ( V_20 -> V_33 , V_21 . V_33 ,
sizeof( V_21 . V_33 ) ) ;
if ( V_24 )
V_24 = - V_34 ;
break;
case V_35 :
V_24 = F_6 ( V_3 , V_14 , V_15 ,
V_16 , V_21 . V_33 ) ;
if ( V_24 )
break;
V_24 = F_7 ( V_36 ,
V_20 -> V_33 , V_25 ,
V_21 . V_33 , sizeof( V_21 . V_33 ) ) ;
if ( ! V_24 ) {
F_8 ( V_3 , V_14 , V_15 ,
V_16 ) ;
}
break;
default:
V_24 = - V_34 ;
break;
}
if ( V_24 )
V_22 = ( V_24 == - V_12 ) ?
V_30 : V_28 ;
V_31:
if ( V_18 )
V_18 -> V_22 = V_22 ;
F_9 ( V_20 ) ;
return V_22 ;
}
static int F_10 ( const char * V_37 )
{
char * * V_38 ;
int V_39 ;
int V_40 = 0 ;
V_39 = strlen ( V_37 ) ;
for ( V_38 = V_11 ; * V_38 != NULL ; V_38 ++ ) {
if ( ( strlen ( * V_38 ) == V_39 )
&& ( strncmp ( V_37 , * V_38 , V_39 ) == 0 ) ) {
V_40 = 1 ;
break;
}
if ( strncmp ( V_37 ,
* V_38 + V_41 ,
strlen ( V_37 ) ) == 0 ) {
V_40 = 1 ;
break;
}
}
return V_40 ;
}
enum V_13 F_11 ( struct V_3 * V_3 ,
const char * V_14 ,
void * V_15 , T_2 V_16 ,
struct V_17 * V_18 )
{
if ( ! V_42 || ! F_10 ( V_14 ) )
return V_43 ;
if ( ! V_18 ) {
V_18 = F_12 ( V_3 -> V_5 ) ;
if ( ! V_18 )
return V_43 ;
}
return F_3 ( V_3 , V_14 , V_15 ,
V_16 , V_18 ) ;
}
static enum V_13 F_13 ( struct V_3 * V_3 )
{
struct V_4 * V_4 = V_3 -> V_5 ;
if ( ! V_42 || ! F_14 ( V_4 -> V_44 ) || V_2 )
return 0 ;
return F_3 ( V_3 , NULL , NULL , 0 , NULL ) ;
}
static int F_15 ( struct V_3 * V_3 , const char * V_14 ,
const void * V_15 , T_2 V_16 )
{
enum V_13 V_22 ;
if ( strcmp ( V_14 , V_26 ) == 0 ) {
if ( ! F_16 ( V_45 ) )
return - V_46 ;
} else if ( ! F_10 ( V_14 ) ) {
if ( ! F_17 ( V_14 ) )
return 0 ;
V_22 = F_13 ( V_3 ) ;
if ( ( V_22 == V_23 ) ||
( V_22 == V_30 ) )
return 0 ;
goto V_31;
}
V_22 = F_13 ( V_3 ) ;
V_31:
if ( V_22 != V_23 )
F_18 ( V_47 , V_3 -> V_5 ,
V_3 -> V_48 . V_49 , L_2 ,
V_50 [ V_22 ] ,
- V_46 , 0 ) ;
return V_22 == V_23 ? 0 : - V_46 ;
}
int F_19 ( struct V_3 * V_3 , const char * V_14 ,
const void * V_15 , T_2 V_16 )
{
return F_15 ( V_3 , V_14 , V_15 ,
V_16 ) ;
}
int F_20 ( struct V_3 * V_3 , const char * V_14 )
{
return F_15 ( V_3 , V_14 , NULL , 0 ) ;
}
void F_21 ( struct V_3 * V_3 , const char * V_14 ,
const void * V_15 , T_2 V_16 )
{
if ( ! V_42 || ( ! F_10 ( V_14 )
&& ! F_17 ( V_14 ) ) )
return;
F_8 ( V_3 , V_14 , V_15 , V_16 ) ;
return;
}
void F_22 ( struct V_3 * V_3 , const char * V_14 )
{
struct V_4 * V_4 = V_3 -> V_5 ;
if ( ! V_42 || ! F_10 ( V_14 ) )
return;
F_23 ( & V_4 -> V_51 ) ;
F_8 ( V_3 , V_14 , NULL , 0 ) ;
F_24 ( & V_4 -> V_51 ) ;
return;
}
int F_25 ( struct V_3 * V_3 , struct V_52 * V_53 )
{
unsigned int V_54 = V_53 -> V_54 ;
enum V_13 V_22 ;
if ( ! ( V_54 & ( V_55 | V_56 | V_57 ) ) )
return 0 ;
V_22 = F_13 ( V_3 ) ;
if ( ( V_22 == V_23 ) ||
( V_22 == V_30 ) )
return 0 ;
F_18 ( V_47 , V_3 -> V_5 ,
V_3 -> V_48 . V_49 , L_2 ,
V_50 [ V_22 ] , - V_46 , 0 ) ;
return - V_46 ;
}
void F_26 ( struct V_3 * V_3 , int V_54 )
{
if ( ! V_42 )
return;
if ( V_54 & ( V_55 | V_56 | V_57 ) )
F_8 ( V_3 , NULL , NULL , 0 ) ;
return;
}
int F_27 ( struct V_4 * V_4 ,
const struct V_6 * V_58 ,
struct V_6 * V_59 )
{
struct V_19 * V_20 ;
int V_24 ;
if ( ! V_42 || ! F_10 ( V_58 -> V_49 ) )
return 0 ;
V_20 = F_28 ( sizeof( * V_20 ) , V_27 ) ;
if ( ! V_20 )
return - V_60 ;
V_20 -> type = V_32 ;
V_24 = F_29 ( V_4 , V_58 , V_20 -> V_33 ) ;
if ( V_24 < 0 )
goto V_31;
V_59 -> V_61 = V_20 ;
V_59 -> V_62 = sizeof( * V_20 ) ;
V_59 -> V_49 = V_63 ;
return 0 ;
V_31:
F_9 ( V_20 ) ;
return V_24 ;
}
static int T_1 F_30 ( void )
{
int error ;
error = F_31 () ;
if ( error < 0 ) {
F_32 ( V_64 L_3 ) ;
goto V_65;
}
return 0 ;
V_65:
return error ;
}
static int T_1 F_33 ( void )
{
char * * V_38 ;
for ( V_38 = V_11 ; * V_38 != NULL ; V_38 ++ )
F_32 ( V_64 L_4 , * V_38 ) ;
return 0 ;
}
