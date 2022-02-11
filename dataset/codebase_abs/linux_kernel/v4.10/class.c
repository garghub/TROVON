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
int F_9 ( struct V_13 * V_19 , const struct V_6 * V_4 ,
const void * V_20 )
{
int error ;
if ( V_19 )
error = F_10 ( & V_19 -> V_21 -> V_22 . V_2 ,
& V_4 -> V_4 , V_20 ) ;
else
error = - V_23 ;
return error ;
}
void F_11 ( struct V_13 * V_19 , const struct V_6 * V_4 ,
const void * V_20 )
{
if ( V_19 )
F_12 ( & V_19 -> V_21 -> V_22 . V_2 , & V_4 -> V_4 , V_20 ) ;
}
static struct V_13 * F_13 ( struct V_13 * V_19 )
{
if ( V_19 )
F_14 ( & V_19 -> V_21 -> V_22 ) ;
return V_19 ;
}
static void F_15 ( struct V_13 * V_19 )
{
if ( V_19 )
F_16 ( & V_19 -> V_21 -> V_22 ) ;
}
static int F_17 ( struct V_13 * V_19 )
{
int V_24 ;
int error = 0 ;
if ( V_19 -> V_25 ) {
for ( V_24 = 0 ; V_19 -> V_25 [ V_24 ] . V_4 . V_16 ; V_24 ++ ) {
error = F_18 ( V_19 , & V_19 -> V_25 [ V_24 ] ) ;
if ( error )
goto error;
}
}
V_26:
return error ;
error:
while ( -- V_24 >= 0 )
F_19 ( V_19 , & V_19 -> V_25 [ V_24 ] ) ;
goto V_26;
}
static void F_20 ( struct V_13 * V_19 )
{
int V_24 ;
if ( V_19 -> V_25 ) {
for ( V_24 = 0 ; V_19 -> V_25 [ V_24 ] . V_4 . V_16 ; V_24 ++ )
F_19 ( V_19 , & V_19 -> V_25 [ V_24 ] ) ;
}
}
static void F_21 ( struct V_27 * V_28 )
{
struct V_29 * V_30 = F_22 ( V_28 , struct V_29 , V_31 ) ;
F_23 ( V_30 ) ;
}
static void F_24 ( struct V_27 * V_28 )
{
struct V_29 * V_30 = F_22 ( V_28 , struct V_29 , V_31 ) ;
F_25 ( V_30 ) ;
}
static int F_26 ( struct V_13 * V_19 ,
const struct V_32 * * V_33 )
{
return F_27 ( & V_19 -> V_21 -> V_22 . V_2 , V_33 ) ;
}
static void F_28 ( struct V_13 * V_19 ,
const struct V_32 * * V_33 )
{
return F_29 ( & V_19 -> V_21 -> V_22 . V_2 , V_33 ) ;
}
int F_30 ( struct V_13 * V_19 , struct V_34 * V_35 )
{
struct V_8 * V_9 ;
int error ;
F_6 ( L_4 , V_19 -> V_16 ) ;
V_9 = F_31 ( sizeof( * V_9 ) , V_36 ) ;
if ( ! V_9 )
return - V_37 ;
F_32 ( & V_9 -> V_38 , F_21 , F_24 ) ;
F_33 ( & V_9 -> V_39 ) ;
F_34 ( & V_9 -> V_40 ) ;
F_35 ( & V_9 -> V_41 , L_5 , V_35 ) ;
error = F_36 ( & V_9 -> V_22 . V_2 , L_6 , V_19 -> V_16 ) ;
if ( error ) {
F_7 ( V_9 ) ;
return error ;
}
if ( ! V_19 -> V_42 )
V_19 -> V_42 = V_43 ;
#if F_37 ( V_44 )
if ( ! V_45 || V_19 != & V_46 )
V_9 -> V_22 . V_2 . V_47 = V_48 ;
#else
V_9 -> V_22 . V_2 . V_47 = V_48 ;
#endif
V_9 -> V_22 . V_2 . V_49 = & V_50 ;
V_9 -> V_13 = V_19 ;
V_19 -> V_21 = V_9 ;
error = F_38 ( & V_9 -> V_22 ) ;
if ( error ) {
F_7 ( V_9 ) ;
return error ;
}
error = F_26 ( F_13 ( V_19 ) , V_19 -> V_51 ) ;
F_15 ( V_19 ) ;
error = F_17 ( F_13 ( V_19 ) ) ;
F_15 ( V_19 ) ;
return error ;
}
void F_39 ( struct V_13 * V_19 )
{
F_6 ( L_7 , V_19 -> V_16 ) ;
F_20 ( V_19 ) ;
F_28 ( V_19 , V_19 -> V_51 ) ;
F_40 ( & V_19 -> V_21 -> V_22 ) ;
}
static void F_41 ( struct V_13 * V_19 )
{
F_6 ( L_8 , V_52 , V_19 -> V_16 ) ;
F_7 ( V_19 ) ;
}
struct V_13 * F_42 ( struct V_53 * V_54 , const char * V_16 ,
struct V_34 * V_35 )
{
struct V_13 * V_19 ;
int V_55 ;
V_19 = F_31 ( sizeof( * V_19 ) , V_36 ) ;
if ( ! V_19 ) {
V_55 = - V_37 ;
goto error;
}
V_19 -> V_16 = V_16 ;
V_19 -> V_54 = V_54 ;
V_19 -> F_5 = F_41 ;
V_55 = F_30 ( V_19 , V_35 ) ;
if ( V_55 )
goto error;
return V_19 ;
error:
F_7 ( V_19 ) ;
return F_43 ( V_55 ) ;
}
void F_44 ( struct V_13 * V_19 )
{
if ( ( V_19 == NULL ) || ( F_45 ( V_19 ) ) )
return;
F_39 ( V_19 ) ;
}
void F_46 ( struct V_56 * V_57 , struct V_13 * V_13 ,
struct V_29 * V_58 , const struct V_59 * type )
{
struct V_27 * V_60 = NULL ;
if ( V_58 )
V_60 = & V_58 -> V_31 ;
F_47 ( & V_13 -> V_21 -> V_38 , & V_57 -> V_61 , V_60 ) ;
V_57 -> type = type ;
}
struct V_29 * F_48 ( struct V_56 * V_57 )
{
struct V_27 * V_62 ;
struct V_29 * V_30 ;
while ( 1 ) {
V_62 = F_49 ( & V_57 -> V_61 ) ;
if ( ! V_62 )
return NULL ;
V_30 = F_22 ( V_62 , struct V_29 , V_31 ) ;
if ( ! V_57 -> type || V_57 -> type == V_30 -> type )
return V_30 ;
}
}
void F_50 ( struct V_56 * V_57 )
{
F_51 ( & V_57 -> V_61 ) ;
}
int F_52 ( struct V_13 * V_13 , struct V_29 * V_58 ,
void * V_63 , int (* F_53)( struct V_29 * , void * ) )
{
struct V_56 V_57 ;
struct V_29 * V_30 ;
int error = 0 ;
if ( ! V_13 )
return - V_23 ;
if ( ! V_13 -> V_21 ) {
F_54 ( 1 , L_9 ,
V_52 , V_13 -> V_16 ) ;
return - V_23 ;
}
F_46 ( & V_57 , V_13 , V_58 , NULL ) ;
while ( ( V_30 = F_48 ( & V_57 ) ) ) {
error = F_53 ( V_30 , V_63 ) ;
if ( error )
break;
}
F_50 ( & V_57 ) ;
return error ;
}
struct V_29 * F_55 ( struct V_13 * V_13 , struct V_29 * V_58 ,
const void * V_63 ,
int (* F_56)( struct V_29 * , const void * ) )
{
struct V_56 V_57 ;
struct V_29 * V_30 ;
if ( ! V_13 )
return NULL ;
if ( ! V_13 -> V_21 ) {
F_54 ( 1 , L_9 ,
V_52 , V_13 -> V_16 ) ;
return NULL ;
}
F_46 ( & V_57 , V_13 , V_58 , NULL ) ;
while ( ( V_30 = F_48 ( & V_57 ) ) ) {
if ( F_56 ( V_30 , V_63 ) ) {
F_23 ( V_30 ) ;
break;
}
}
F_50 ( & V_57 ) ;
return V_30 ;
}
int F_57 ( struct V_64 * V_65 )
{
struct V_13 * V_66 ;
struct V_56 V_57 ;
struct V_29 * V_30 ;
if ( ! V_65 || ! V_65 -> V_13 )
return - V_67 ;
V_66 = F_13 ( V_65 -> V_13 ) ;
if ( ! V_66 )
return - V_23 ;
F_58 ( & V_66 -> V_21 -> V_41 ) ;
F_59 ( & V_65 -> V_68 , & V_66 -> V_21 -> V_39 ) ;
if ( V_65 -> V_69 ) {
F_46 ( & V_57 , V_66 , NULL , NULL ) ;
while ( ( V_30 = F_48 ( & V_57 ) ) )
V_65 -> V_69 ( V_30 , V_65 ) ;
F_50 ( & V_57 ) ;
}
F_60 ( & V_66 -> V_21 -> V_41 ) ;
return 0 ;
}
void F_61 ( struct V_64 * V_65 )
{
struct V_13 * V_66 = V_65 -> V_13 ;
struct V_56 V_57 ;
struct V_29 * V_30 ;
if ( ! V_66 )
return;
F_58 ( & V_66 -> V_21 -> V_41 ) ;
F_62 ( & V_65 -> V_68 ) ;
if ( V_65 -> V_70 ) {
F_46 ( & V_57 , V_66 , NULL , NULL ) ;
while ( ( V_30 = F_48 ( & V_57 ) ) )
V_65 -> V_70 ( V_30 , V_65 ) ;
F_50 ( & V_57 ) ;
}
F_60 ( & V_66 -> V_21 -> V_41 ) ;
F_15 ( V_66 ) ;
}
T_1 F_63 ( struct V_13 * V_13 ,
struct V_6 * V_4 , char * V_5 )
{
struct V_71 * V_72 ;
V_72 = F_22 ( V_4 , struct V_71 , V_4 ) ;
return snprintf ( V_5 , V_73 , L_10 , V_72 -> V_74 ) ;
}
struct V_75 * F_64 ( const char * V_16 )
{
struct V_75 * V_19 ;
V_19 = F_65 ( sizeof( struct V_75 ) , V_36 ) ;
if ( ! V_19 )
return NULL ;
V_19 -> V_2 = F_66 ( V_16 , & V_48 -> V_2 ) ;
if ( ! V_19 -> V_2 ) {
F_7 ( V_19 ) ;
return NULL ;
}
return V_19 ;
}
void F_67 ( struct V_75 * V_19 )
{
F_68 ( V_19 -> V_2 ) ;
F_7 ( V_19 ) ;
}
int F_69 ( struct V_75 * V_19 , struct V_29 * V_30 ,
struct V_29 * V_76 )
{
int error ;
error = F_70 ( V_19 -> V_2 , & V_30 -> V_2 , F_71 ( V_30 ) ) ;
if ( error )
return error ;
if ( V_76 ) {
error = F_70 ( & V_30 -> V_2 , & V_76 -> V_2 ,
L_11 ) ;
if ( error )
F_72 ( V_19 -> V_2 , F_71 ( V_30 ) ) ;
}
return error ;
}
void F_73 ( struct V_75 * V_19 , struct V_29 * V_30 ,
struct V_29 * V_76 )
{
if ( V_76 )
F_72 ( & V_30 -> V_2 , L_11 ) ;
F_72 ( V_19 -> V_2 , F_71 ( V_30 ) ) ;
}
int T_3 F_74 ( void )
{
V_48 = F_75 ( L_12 , NULL , NULL ) ;
if ( ! V_48 )
return - V_37 ;
return 0 ;
}
