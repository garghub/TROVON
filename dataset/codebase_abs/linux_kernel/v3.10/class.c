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
static const void * F_5 ( struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
struct V_6 * V_7 = F_2 ( V_4 ) ;
struct V_8 * V_9 = F_3 ( V_2 ) ;
const void * V_16 = NULL ;
if ( V_7 -> V_17 )
V_16 = V_7 -> V_17 ( V_9 -> V_13 , V_7 ) ;
return V_16 ;
}
static void F_6 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = F_3 ( V_2 ) ;
struct V_13 * V_13 = V_9 -> V_13 ;
F_7 ( L_1 , V_13 -> V_18 ) ;
if ( V_13 -> F_6 )
V_13 -> F_6 ( V_13 ) ;
else
F_7 ( L_2
L_3 , V_13 -> V_18 ) ;
F_8 ( V_9 ) ;
}
static const struct V_19 * F_9 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = F_3 ( V_2 ) ;
struct V_13 * V_13 = V_9 -> V_13 ;
return V_13 -> V_20 ;
}
int F_10 ( struct V_13 * V_21 , const struct V_6 * V_4 )
{
int error ;
if ( V_21 )
error = F_11 ( & V_21 -> V_22 -> V_23 . V_2 ,
& V_4 -> V_4 ) ;
else
error = - V_24 ;
return error ;
}
void F_12 ( struct V_13 * V_21 , const struct V_6 * V_4 )
{
if ( V_21 )
F_13 ( & V_21 -> V_22 -> V_23 . V_2 , & V_4 -> V_4 ) ;
}
static struct V_13 * F_14 ( struct V_13 * V_21 )
{
if ( V_21 )
F_15 ( & V_21 -> V_22 -> V_23 ) ;
return V_21 ;
}
static void F_16 ( struct V_13 * V_21 )
{
if ( V_21 )
F_17 ( & V_21 -> V_22 -> V_23 ) ;
}
static int F_18 ( struct V_13 * V_21 )
{
int V_25 ;
int error = 0 ;
if ( V_21 -> V_26 ) {
for ( V_25 = 0 ; F_19 ( V_21 -> V_26 [ V_25 ] ) ; V_25 ++ ) {
error = F_10 ( V_21 , & V_21 -> V_26 [ V_25 ] ) ;
if ( error )
goto error;
}
}
V_27:
return error ;
error:
while ( -- V_25 >= 0 )
F_12 ( V_21 , & V_21 -> V_26 [ V_25 ] ) ;
goto V_27;
}
static void F_20 ( struct V_13 * V_21 )
{
int V_25 ;
if ( V_21 -> V_26 ) {
for ( V_25 = 0 ; F_19 ( V_21 -> V_26 [ V_25 ] ) ; V_25 ++ )
F_12 ( V_21 , & V_21 -> V_26 [ V_25 ] ) ;
}
}
static void F_21 ( struct V_28 * V_29 )
{
struct V_30 * V_31 = F_22 ( V_29 , struct V_30 , V_32 ) ;
F_23 ( V_31 ) ;
}
static void F_24 ( struct V_28 * V_29 )
{
struct V_30 * V_31 = F_22 ( V_29 , struct V_30 , V_32 ) ;
F_25 ( V_31 ) ;
}
int F_26 ( struct V_13 * V_21 , struct V_33 * V_34 )
{
struct V_8 * V_9 ;
int error ;
F_7 ( L_4 , V_21 -> V_18 ) ;
V_9 = F_27 ( sizeof( * V_9 ) , V_35 ) ;
if ( ! V_9 )
return - V_36 ;
F_28 ( & V_9 -> V_37 , F_21 , F_24 ) ;
F_29 ( & V_9 -> V_38 ) ;
F_30 ( & V_9 -> V_39 ) ;
F_31 ( & V_9 -> V_40 , L_5 , V_34 ) ;
error = F_32 ( & V_9 -> V_23 . V_2 , L_6 , V_21 -> V_18 ) ;
if ( error ) {
F_8 ( V_9 ) ;
return error ;
}
if ( ! V_21 -> V_41 )
V_21 -> V_41 = V_42 ;
#if F_33 ( V_43 )
if ( ! V_44 || V_21 != & V_45 )
V_9 -> V_23 . V_2 . V_46 = V_47 ;
#else
V_9 -> V_23 . V_2 . V_46 = V_47 ;
#endif
V_9 -> V_23 . V_2 . V_48 = & V_49 ;
V_9 -> V_13 = V_21 ;
V_21 -> V_22 = V_9 ;
error = F_34 ( & V_9 -> V_23 ) ;
if ( error ) {
F_8 ( V_9 ) ;
return error ;
}
error = F_18 ( F_14 ( V_21 ) ) ;
F_16 ( V_21 ) ;
return error ;
}
void F_35 ( struct V_13 * V_21 )
{
F_7 ( L_7 , V_21 -> V_18 ) ;
F_20 ( V_21 ) ;
F_36 ( & V_21 -> V_22 -> V_23 ) ;
}
static void F_37 ( struct V_13 * V_21 )
{
F_7 ( L_8 , V_50 , V_21 -> V_18 ) ;
F_8 ( V_21 ) ;
}
struct V_13 * F_38 ( struct V_51 * V_52 , const char * V_18 ,
struct V_33 * V_34 )
{
struct V_13 * V_21 ;
int V_53 ;
V_21 = F_27 ( sizeof( * V_21 ) , V_35 ) ;
if ( ! V_21 ) {
V_53 = - V_36 ;
goto error;
}
V_21 -> V_18 = V_18 ;
V_21 -> V_52 = V_52 ;
V_21 -> F_6 = F_37 ;
V_53 = F_26 ( V_21 , V_34 ) ;
if ( V_53 )
goto error;
return V_21 ;
error:
F_8 ( V_21 ) ;
return F_39 ( V_53 ) ;
}
void F_40 ( struct V_13 * V_21 )
{
if ( ( V_21 == NULL ) || ( F_41 ( V_21 ) ) )
return;
F_35 ( V_21 ) ;
}
void F_42 ( struct V_54 * V_55 , struct V_13 * V_13 ,
struct V_30 * V_56 , const struct V_57 * type )
{
struct V_28 * V_58 = NULL ;
if ( V_56 )
V_58 = & V_56 -> V_32 ;
F_43 ( & V_13 -> V_22 -> V_37 , & V_55 -> V_59 , V_58 ) ;
V_55 -> type = type ;
}
struct V_30 * F_44 ( struct V_54 * V_55 )
{
struct V_28 * V_60 ;
struct V_30 * V_31 ;
while ( 1 ) {
V_60 = F_45 ( & V_55 -> V_59 ) ;
if ( ! V_60 )
return NULL ;
V_31 = F_22 ( V_60 , struct V_30 , V_32 ) ;
if ( ! V_55 -> type || V_55 -> type == V_31 -> type )
return V_31 ;
}
}
void F_46 ( struct V_54 * V_55 )
{
F_47 ( & V_55 -> V_59 ) ;
}
int F_48 ( struct V_13 * V_13 , struct V_30 * V_56 ,
void * V_61 , int (* F_49)( struct V_30 * , void * ) )
{
struct V_54 V_55 ;
struct V_30 * V_31 ;
int error = 0 ;
if ( ! V_13 )
return - V_24 ;
if ( ! V_13 -> V_22 ) {
F_50 ( 1 , L_9 ,
V_50 , V_13 -> V_18 ) ;
return - V_24 ;
}
F_42 ( & V_55 , V_13 , V_56 , NULL ) ;
while ( ( V_31 = F_44 ( & V_55 ) ) ) {
error = F_49 ( V_31 , V_61 ) ;
if ( error )
break;
}
F_46 ( & V_55 ) ;
return error ;
}
struct V_30 * F_51 ( struct V_13 * V_13 , struct V_30 * V_56 ,
const void * V_61 ,
int (* F_52)( struct V_30 * , const void * ) )
{
struct V_54 V_55 ;
struct V_30 * V_31 ;
if ( ! V_13 )
return NULL ;
if ( ! V_13 -> V_22 ) {
F_50 ( 1 , L_9 ,
V_50 , V_13 -> V_18 ) ;
return NULL ;
}
F_42 ( & V_55 , V_13 , V_56 , NULL ) ;
while ( ( V_31 = F_44 ( & V_55 ) ) ) {
if ( F_52 ( V_31 , V_61 ) ) {
F_23 ( V_31 ) ;
break;
}
}
F_46 ( & V_55 ) ;
return V_31 ;
}
int F_53 ( struct V_62 * V_63 )
{
struct V_13 * V_64 ;
struct V_54 V_55 ;
struct V_30 * V_31 ;
if ( ! V_63 || ! V_63 -> V_13 )
return - V_65 ;
V_64 = F_14 ( V_63 -> V_13 ) ;
if ( ! V_64 )
return - V_24 ;
F_54 ( & V_64 -> V_22 -> V_40 ) ;
F_55 ( & V_63 -> V_66 , & V_64 -> V_22 -> V_38 ) ;
if ( V_63 -> V_67 ) {
F_42 ( & V_55 , V_64 , NULL , NULL ) ;
while ( ( V_31 = F_44 ( & V_55 ) ) )
V_63 -> V_67 ( V_31 , V_63 ) ;
F_46 ( & V_55 ) ;
}
F_56 ( & V_64 -> V_22 -> V_40 ) ;
return 0 ;
}
void F_57 ( struct V_62 * V_63 )
{
struct V_13 * V_64 = V_63 -> V_13 ;
struct V_54 V_55 ;
struct V_30 * V_31 ;
if ( ! V_64 )
return;
F_54 ( & V_64 -> V_22 -> V_40 ) ;
F_58 ( & V_63 -> V_66 ) ;
if ( V_63 -> V_68 ) {
F_42 ( & V_55 , V_64 , NULL , NULL ) ;
while ( ( V_31 = F_44 ( & V_55 ) ) )
V_63 -> V_68 ( V_31 , V_63 ) ;
F_46 ( & V_55 ) ;
}
F_56 ( & V_64 -> V_22 -> V_40 ) ;
F_16 ( V_64 ) ;
}
T_1 F_59 ( struct V_13 * V_13 ,
struct V_6 * V_4 , char * V_5 )
{
struct V_69 * V_70 ;
V_70 = F_22 ( V_4 , struct V_69 , V_4 ) ;
return snprintf ( V_5 , V_71 , L_10 , V_70 -> V_72 ) ;
}
struct V_73 * F_60 ( const char * V_18 )
{
struct V_73 * V_21 ;
V_21 = F_61 ( sizeof( struct V_73 ) , V_35 ) ;
if ( ! V_21 )
return NULL ;
V_21 -> V_2 = F_62 ( V_18 , & V_47 -> V_2 ) ;
if ( ! V_21 -> V_2 ) {
F_8 ( V_21 ) ;
return NULL ;
}
return V_21 ;
}
void F_63 ( struct V_73 * V_21 )
{
F_64 ( V_21 -> V_2 ) ;
F_8 ( V_21 ) ;
}
int F_65 ( struct V_73 * V_21 , struct V_30 * V_31 ,
struct V_30 * V_74 )
{
int error ;
error = F_66 ( V_21 -> V_2 , & V_31 -> V_2 , F_67 ( V_31 ) ) ;
if ( error )
return error ;
if ( V_74 ) {
error = F_66 ( & V_31 -> V_2 , & V_74 -> V_2 ,
L_11 ) ;
if ( error )
F_68 ( V_21 -> V_2 , F_67 ( V_31 ) ) ;
}
return error ;
}
void F_69 ( struct V_73 * V_21 , struct V_30 * V_31 ,
struct V_30 * V_74 )
{
if ( V_74 )
F_68 ( & V_31 -> V_2 , L_11 ) ;
F_68 ( V_21 -> V_2 , F_67 ( V_31 ) ) ;
}
int T_3 F_70 ( void )
{
V_47 = F_71 ( L_12 , NULL , NULL ) ;
if ( ! V_47 )
return - V_36 ;
return 0 ;
}
