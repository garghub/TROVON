static T_1 F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_4 ) ;
struct V_8 * V_9 = F_3 ( V_2 ) ;
T_1 V_10 = - V_11 ;
if ( V_7 -> V_12 )
V_10 = V_7 -> V_12 ( V_9 -> V_13 , V_7 , V_5 ) ;
return V_10 ;
}
static T_1 F_4 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const char * V_5 , T_2 V_14 )
{
struct V_6 * V_7 = F_2 ( V_4 ) ;
struct V_8 * V_9 = F_3 ( V_2 ) ;
T_1 V_10 = - V_11 ;
if ( V_7 -> V_15 )
V_10 = V_7 -> V_15 ( V_9 -> V_13 , V_7 , V_5 , V_14 ) ;
return V_10 ;
}
static void F_5 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = F_3 ( V_2 ) ;
struct V_13 * V_13 = V_9 -> V_13 ;
F_6 ( L_1 , V_13 -> V_16 ) ;
if ( V_13 -> F_5 )
V_13 -> F_5 ( V_13 ) ;
else
F_6 ( L_2
L_3 , V_13 -> V_16 ) ;
F_7 ( V_9 ) ;
}
static const struct V_17 * F_8 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = F_3 ( V_2 ) ;
struct V_13 * V_13 = V_9 -> V_13 ;
return V_13 -> V_18 ;
}
int F_9 ( struct V_13 * V_19 , const struct V_6 * V_4 )
{
int error ;
if ( V_19 )
error = F_10 ( & V_19 -> V_20 -> V_21 . V_2 ,
& V_4 -> V_4 ) ;
else
error = - V_22 ;
return error ;
}
void F_11 ( struct V_13 * V_19 , const struct V_6 * V_4 )
{
if ( V_19 )
F_12 ( & V_19 -> V_20 -> V_21 . V_2 , & V_4 -> V_4 ) ;
}
static struct V_13 * F_13 ( struct V_13 * V_19 )
{
if ( V_19 )
F_14 ( & V_19 -> V_20 -> V_21 ) ;
return V_19 ;
}
static void F_15 ( struct V_13 * V_19 )
{
if ( V_19 )
F_16 ( & V_19 -> V_20 -> V_21 ) ;
}
static int F_17 ( struct V_13 * V_19 )
{
int V_23 ;
int error = 0 ;
if ( V_19 -> V_24 ) {
for ( V_23 = 0 ; F_18 ( V_19 -> V_24 [ V_23 ] ) ; V_23 ++ ) {
error = F_9 ( V_19 , & V_19 -> V_24 [ V_23 ] ) ;
if ( error )
goto error;
}
}
V_25:
return error ;
error:
while ( -- V_23 >= 0 )
F_11 ( V_19 , & V_19 -> V_24 [ V_23 ] ) ;
goto V_25;
}
static void F_19 ( struct V_13 * V_19 )
{
int V_23 ;
if ( V_19 -> V_24 ) {
for ( V_23 = 0 ; F_18 ( V_19 -> V_24 [ V_23 ] ) ; V_23 ++ )
F_11 ( V_19 , & V_19 -> V_24 [ V_23 ] ) ;
}
}
static void F_20 ( struct V_26 * V_27 )
{
struct V_28 * V_29 = F_21 ( V_27 , struct V_28 , V_30 ) ;
F_22 ( V_29 ) ;
}
static void F_23 ( struct V_26 * V_27 )
{
struct V_28 * V_29 = F_21 ( V_27 , struct V_28 , V_30 ) ;
F_24 ( V_29 ) ;
}
int F_25 ( struct V_13 * V_19 , struct V_31 * V_32 )
{
struct V_8 * V_9 ;
int error ;
F_6 ( L_4 , V_19 -> V_16 ) ;
V_9 = F_26 ( sizeof( * V_9 ) , V_33 ) ;
if ( ! V_9 )
return - V_34 ;
F_27 ( & V_9 -> V_35 , F_20 , F_23 ) ;
F_28 ( & V_9 -> V_36 ) ;
F_29 ( & V_9 -> V_37 ) ;
F_30 ( & V_9 -> V_38 , L_5 , V_32 ) ;
error = F_31 ( & V_9 -> V_21 . V_2 , L_6 , V_19 -> V_16 ) ;
if ( error ) {
F_7 ( V_9 ) ;
return error ;
}
if ( ! V_19 -> V_39 )
V_19 -> V_39 = V_40 ;
#if F_32 ( V_41 )
if ( ! V_42 || V_19 != & V_43 )
V_9 -> V_21 . V_2 . V_44 = V_45 ;
#else
V_9 -> V_21 . V_2 . V_44 = V_45 ;
#endif
V_9 -> V_21 . V_2 . V_46 = & V_47 ;
V_9 -> V_13 = V_19 ;
V_19 -> V_20 = V_9 ;
error = F_33 ( & V_9 -> V_21 ) ;
if ( error ) {
F_7 ( V_9 ) ;
return error ;
}
error = F_17 ( F_13 ( V_19 ) ) ;
F_15 ( V_19 ) ;
return error ;
}
void F_34 ( struct V_13 * V_19 )
{
F_6 ( L_7 , V_19 -> V_16 ) ;
F_19 ( V_19 ) ;
F_35 ( & V_19 -> V_20 -> V_21 ) ;
}
static void F_36 ( struct V_13 * V_19 )
{
F_6 ( L_8 , V_48 , V_19 -> V_16 ) ;
F_7 ( V_19 ) ;
}
struct V_13 * F_37 ( struct V_49 * V_50 , const char * V_16 ,
struct V_31 * V_32 )
{
struct V_13 * V_19 ;
int V_51 ;
V_19 = F_26 ( sizeof( * V_19 ) , V_33 ) ;
if ( ! V_19 ) {
V_51 = - V_34 ;
goto error;
}
V_19 -> V_16 = V_16 ;
V_19 -> V_50 = V_50 ;
V_19 -> F_5 = F_36 ;
V_51 = F_25 ( V_19 , V_32 ) ;
if ( V_51 )
goto error;
return V_19 ;
error:
F_7 ( V_19 ) ;
return F_38 ( V_51 ) ;
}
void F_39 ( struct V_13 * V_19 )
{
if ( ( V_19 == NULL ) || ( F_40 ( V_19 ) ) )
return;
F_34 ( V_19 ) ;
}
void F_41 ( struct V_52 * V_53 , struct V_13 * V_13 ,
struct V_28 * V_54 , const struct V_55 * type )
{
struct V_26 * V_56 = NULL ;
if ( V_54 )
V_56 = & V_54 -> V_30 ;
F_42 ( & V_13 -> V_20 -> V_35 , & V_53 -> V_57 , V_56 ) ;
V_53 -> type = type ;
}
struct V_28 * F_43 ( struct V_52 * V_53 )
{
struct V_26 * V_58 ;
struct V_28 * V_29 ;
while ( 1 ) {
V_58 = F_44 ( & V_53 -> V_57 ) ;
if ( ! V_58 )
return NULL ;
V_29 = F_21 ( V_58 , struct V_28 , V_30 ) ;
if ( ! V_53 -> type || V_53 -> type == V_29 -> type )
return V_29 ;
}
}
void F_45 ( struct V_52 * V_53 )
{
F_46 ( & V_53 -> V_57 ) ;
}
int F_47 ( struct V_13 * V_13 , struct V_28 * V_54 ,
void * V_59 , int (* F_48)( struct V_28 * , void * ) )
{
struct V_52 V_53 ;
struct V_28 * V_29 ;
int error = 0 ;
if ( ! V_13 )
return - V_22 ;
if ( ! V_13 -> V_20 ) {
F_49 ( 1 , L_9 ,
V_48 , V_13 -> V_16 ) ;
return - V_22 ;
}
F_41 ( & V_53 , V_13 , V_54 , NULL ) ;
while ( ( V_29 = F_43 ( & V_53 ) ) ) {
error = F_48 ( V_29 , V_59 ) ;
if ( error )
break;
}
F_45 ( & V_53 ) ;
return error ;
}
struct V_28 * F_50 ( struct V_13 * V_13 , struct V_28 * V_54 ,
void * V_59 ,
int (* F_51)( struct V_28 * , void * ) )
{
struct V_52 V_53 ;
struct V_28 * V_29 ;
if ( ! V_13 )
return NULL ;
if ( ! V_13 -> V_20 ) {
F_49 ( 1 , L_9 ,
V_48 , V_13 -> V_16 ) ;
return NULL ;
}
F_41 ( & V_53 , V_13 , V_54 , NULL ) ;
while ( ( V_29 = F_43 ( & V_53 ) ) ) {
if ( F_51 ( V_29 , V_59 ) ) {
F_22 ( V_29 ) ;
break;
}
}
F_45 ( & V_53 ) ;
return V_29 ;
}
int F_52 ( struct V_60 * V_61 )
{
struct V_13 * V_62 ;
struct V_52 V_53 ;
struct V_28 * V_29 ;
if ( ! V_61 || ! V_61 -> V_13 )
return - V_63 ;
V_62 = F_13 ( V_61 -> V_13 ) ;
if ( ! V_62 )
return - V_22 ;
F_53 ( & V_62 -> V_20 -> V_38 ) ;
F_54 ( & V_61 -> V_64 , & V_62 -> V_20 -> V_36 ) ;
if ( V_61 -> V_65 ) {
F_41 ( & V_53 , V_62 , NULL , NULL ) ;
while ( ( V_29 = F_43 ( & V_53 ) ) )
V_61 -> V_65 ( V_29 , V_61 ) ;
F_45 ( & V_53 ) ;
}
F_55 ( & V_62 -> V_20 -> V_38 ) ;
return 0 ;
}
void F_56 ( struct V_60 * V_61 )
{
struct V_13 * V_62 = V_61 -> V_13 ;
struct V_52 V_53 ;
struct V_28 * V_29 ;
if ( ! V_62 )
return;
F_53 ( & V_62 -> V_20 -> V_38 ) ;
F_57 ( & V_61 -> V_64 ) ;
if ( V_61 -> V_66 ) {
F_41 ( & V_53 , V_62 , NULL , NULL ) ;
while ( ( V_29 = F_43 ( & V_53 ) ) )
V_61 -> V_66 ( V_29 , V_61 ) ;
F_45 ( & V_53 ) ;
}
F_55 ( & V_62 -> V_20 -> V_38 ) ;
F_15 ( V_62 ) ;
}
T_1 F_58 ( struct V_13 * V_13 ,
struct V_6 * V_4 , char * V_5 )
{
struct V_67 * V_68 ;
V_68 = F_21 ( V_4 , struct V_67 , V_4 ) ;
return snprintf ( V_5 , V_69 , L_10 , V_68 -> V_70 ) ;
}
struct V_71 * F_59 ( const char * V_16 )
{
struct V_71 * V_19 ;
V_19 = F_60 ( sizeof( struct V_71 ) , V_33 ) ;
if ( ! V_19 )
return NULL ;
V_19 -> V_2 = F_61 ( V_16 , & V_45 -> V_2 ) ;
if ( ! V_19 -> V_2 ) {
F_7 ( V_19 ) ;
return NULL ;
}
return V_19 ;
}
void F_62 ( struct V_71 * V_19 )
{
F_63 ( V_19 -> V_2 ) ;
F_7 ( V_19 ) ;
}
int F_64 ( struct V_71 * V_19 , struct V_28 * V_29 ,
struct V_28 * V_72 )
{
int error ;
error = F_65 ( V_19 -> V_2 , & V_29 -> V_2 , F_66 ( V_29 ) ) ;
if ( error )
return error ;
if ( V_72 ) {
error = F_65 ( & V_29 -> V_2 , & V_72 -> V_2 ,
L_11 ) ;
if ( error )
F_67 ( V_19 -> V_2 , F_66 ( V_29 ) ) ;
}
return error ;
}
void F_68 ( struct V_71 * V_19 , struct V_28 * V_29 ,
struct V_28 * V_72 )
{
if ( V_72 )
F_67 ( & V_29 -> V_2 , L_11 ) ;
F_67 ( V_19 -> V_2 , F_66 ( V_29 ) ) ;
}
int T_3 F_69 ( void )
{
V_45 = F_70 ( L_12 , NULL , NULL ) ;
if ( ! V_45 )
return - V_34 ;
return 0 ;
}
