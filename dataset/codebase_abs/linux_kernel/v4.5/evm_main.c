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
struct V_6 * V_6 = F_6 ( V_5 ) ;
char * * V_7 ;
int error ;
int V_8 = 0 ;
if ( ! V_6 -> V_9 -> V_10 )
return - V_11 ;
for ( V_7 = V_12 ; * V_7 != NULL ; V_7 ++ ) {
error = V_6 -> V_9 -> V_10 ( V_5 , * V_7 , NULL , 0 ) ;
if ( error < 0 ) {
if ( error == - V_13 )
continue;
return error ;
}
V_8 ++ ;
}
return V_8 ;
}
static enum V_14 F_7 ( struct V_5 * V_5 ,
const char * V_15 ,
char * V_16 ,
T_2 V_17 ,
struct V_18 * V_19 )
{
struct V_20 * V_21 = NULL ;
struct V_20 V_22 ;
enum V_14 V_23 = V_24 ;
int V_25 , V_26 ;
if ( V_19 && V_19 -> V_23 == V_24 )
return V_19 -> V_23 ;
V_25 = F_8 ( V_5 , V_27 , ( char * * ) & V_21 , 0 ,
V_28 ) ;
if ( V_25 <= 0 ) {
V_23 = V_29 ;
if ( V_25 == - V_13 ) {
V_25 = F_5 ( V_5 ) ;
if ( V_25 > 0 )
V_23 = V_30 ;
else if ( V_25 == 0 )
V_23 = V_31 ;
} else if ( V_25 == - V_11 ) {
V_23 = V_32 ;
}
goto V_33;
}
V_26 = V_25 ;
switch ( V_21 -> type ) {
case V_34 :
V_25 = F_9 ( V_5 , V_15 , V_16 ,
V_17 , V_22 . V_35 ) ;
if ( V_25 )
break;
V_25 = F_10 ( V_21 -> V_35 , V_22 . V_35 ,
sizeof( V_22 . V_35 ) ) ;
if ( V_25 )
V_25 = - V_36 ;
break;
case V_37 :
V_25 = F_11 ( V_5 , V_15 , V_16 ,
V_17 , V_22 . V_35 ) ;
if ( V_25 )
break;
V_25 = F_12 ( V_38 ,
( const char * ) V_21 , V_26 ,
V_22 . V_35 , sizeof( V_22 . V_35 ) ) ;
if ( ! V_25 ) {
if ( ! F_13 ( F_6 ( V_5 ) ) &&
! F_14 ( F_6 ( V_5 ) ) )
F_15 ( V_5 , V_15 ,
V_16 ,
V_17 ) ;
}
break;
default:
V_25 = - V_36 ;
break;
}
if ( V_25 )
V_23 = ( V_25 == - V_13 ) ?
V_31 : V_29 ;
V_33:
if ( V_19 )
V_19 -> V_23 = V_23 ;
F_16 ( V_21 ) ;
return V_23 ;
}
static int F_17 ( const char * V_39 )
{
char * * V_40 ;
int V_41 ;
int V_42 = 0 ;
V_41 = strlen ( V_39 ) ;
for ( V_40 = V_12 ; * V_40 != NULL ; V_40 ++ ) {
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
enum V_14 F_18 ( struct V_5 * V_5 ,
const char * V_15 ,
void * V_16 , T_2 V_17 ,
struct V_18 * V_19 )
{
if ( ! V_44 || ! F_17 ( V_15 ) )
return V_32 ;
if ( ! V_19 ) {
V_19 = F_19 ( F_6 ( V_5 ) ) ;
if ( ! V_19 )
return V_32 ;
}
return F_7 ( V_5 , V_15 , V_16 ,
V_17 , V_19 ) ;
}
static enum V_14 F_20 ( struct V_5 * V_5 )
{
struct V_6 * V_6 = F_6 ( V_5 ) ;
if ( ! V_44 || ! F_21 ( V_6 -> V_45 ) || V_2 )
return 0 ;
return F_7 ( V_5 , NULL , NULL , 0 , NULL ) ;
}
static int F_22 ( struct V_5 * V_5 , const char * V_15 ,
const void * V_16 , T_2 V_17 )
{
enum V_14 V_23 ;
if ( strcmp ( V_15 , V_27 ) == 0 ) {
if ( ! F_23 ( V_46 ) )
return - V_47 ;
} else if ( ! F_17 ( V_15 ) ) {
if ( ! F_24 ( V_15 ) )
return 0 ;
V_23 = F_20 ( V_5 ) ;
if ( ( V_23 == V_24 ) ||
( V_23 == V_31 ) )
return 0 ;
goto V_33;
}
V_23 = F_20 ( V_5 ) ;
if ( V_23 == V_31 ) {
struct V_18 * V_19 ;
V_19 = F_19 ( F_6 ( V_5 ) ) ;
if ( V_19 && ( V_19 -> V_48 & V_49 ) )
return 0 ;
if ( V_5 -> V_50 -> V_51 -> V_52 == V_53
|| V_5 -> V_50 -> V_51 -> V_52 == V_54 )
return 0 ;
F_25 ( V_55 ,
V_5 -> V_50 , V_5 -> V_56 . V_57 ,
L_3 ,
V_58 [ V_23 ] ,
- V_47 , 0 ) ;
}
V_33:
if ( V_23 != V_24 )
F_25 ( V_55 , F_6 ( V_5 ) ,
V_5 -> V_56 . V_57 , L_4 ,
V_58 [ V_23 ] ,
- V_47 , 0 ) ;
return V_23 == V_24 ? 0 : - V_47 ;
}
int F_26 ( struct V_5 * V_5 , const char * V_15 ,
const void * V_16 , T_2 V_17 )
{
const struct V_20 * V_21 = V_16 ;
if ( strcmp ( V_15 , V_27 ) == 0 ) {
if ( ! V_17 )
return - V_36 ;
if ( V_21 -> type != V_37 )
return - V_47 ;
}
return F_22 ( V_5 , V_15 , V_16 ,
V_17 ) ;
}
int F_27 ( struct V_5 * V_5 , const char * V_15 )
{
return F_22 ( V_5 , V_15 , NULL , 0 ) ;
}
static void F_28 ( struct V_6 * V_6 )
{
struct V_18 * V_19 ;
V_19 = F_19 ( V_6 ) ;
if ( V_19 )
V_19 -> V_23 = V_32 ;
}
void F_29 ( struct V_5 * V_5 , const char * V_15 ,
const void * V_16 , T_2 V_17 )
{
if ( ! V_44 || ( ! F_17 ( V_15 )
&& ! F_24 ( V_15 ) ) )
return;
F_28 ( V_5 -> V_50 ) ;
F_15 ( V_5 , V_15 , V_16 , V_17 ) ;
}
void F_30 ( struct V_5 * V_5 , const char * V_15 )
{
if ( ! V_44 || ! F_17 ( V_15 ) )
return;
F_28 ( V_5 -> V_50 ) ;
F_15 ( V_5 , V_15 , NULL , 0 ) ;
}
int F_31 ( struct V_5 * V_5 , struct V_59 * V_60 )
{
unsigned int V_61 = V_60 -> V_61 ;
enum V_14 V_23 ;
if ( ! ( V_61 & ( V_62 | V_63 | V_64 ) ) )
return 0 ;
V_23 = F_20 ( V_5 ) ;
if ( ( V_23 == V_24 ) ||
( V_23 == V_31 ) )
return 0 ;
F_25 ( V_55 , F_6 ( V_5 ) ,
V_5 -> V_56 . V_57 , L_4 ,
V_58 [ V_23 ] , - V_47 , 0 ) ;
return - V_47 ;
}
void F_32 ( struct V_5 * V_5 , int V_61 )
{
if ( ! V_44 )
return;
if ( V_61 & ( V_62 | V_63 | V_64 ) )
F_15 ( V_5 , NULL , NULL , 0 ) ;
}
int F_33 ( struct V_6 * V_6 ,
const struct V_7 * V_65 ,
struct V_7 * V_66 )
{
struct V_20 * V_21 ;
int V_25 ;
if ( ! V_44 || ! F_17 ( V_65 -> V_57 ) )
return 0 ;
V_21 = F_34 ( sizeof( * V_21 ) , V_28 ) ;
if ( ! V_21 )
return - V_67 ;
V_21 -> type = V_34 ;
V_25 = F_35 ( V_6 , V_65 , V_21 -> V_35 ) ;
if ( V_25 < 0 )
goto V_33;
V_66 -> V_68 = V_21 ;
V_66 -> V_69 = sizeof( * V_21 ) ;
V_66 -> V_57 = V_70 ;
return 0 ;
V_33:
F_16 ( V_21 ) ;
return V_25 ;
}
void T_1 F_36 ( void )
{
int V_25 ;
V_25 = F_37 ( V_38 , V_71 ) ;
if ( ! V_25 )
V_44 |= V_72 ;
}
static int T_1 F_38 ( void )
{
int error ;
F_2 () ;
error = F_39 ( V_38 ) ;
if ( error )
return error ;
error = F_40 () ;
if ( error < 0 ) {
F_4 ( L_5 ) ;
return error ;
}
return 0 ;
}
static int T_1 F_41 ( void )
{
char * * V_40 ;
for ( V_40 = V_12 ; * V_40 != NULL ; V_40 ++ )
F_4 ( L_6 , * V_40 ) ;
return 0 ;
}
