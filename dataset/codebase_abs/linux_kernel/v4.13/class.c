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
static void F_17 ( struct V_24 * V_25 )
{
struct V_26 * V_27 = F_18 ( V_25 , struct V_26 , V_28 ) ;
F_19 ( V_27 ) ;
}
static void F_20 ( struct V_24 * V_25 )
{
struct V_26 * V_27 = F_18 ( V_25 , struct V_26 , V_28 ) ;
F_21 ( V_27 ) ;
}
static int F_22 ( struct V_13 * V_19 ,
const struct V_29 * * V_30 )
{
return F_23 ( & V_19 -> V_21 -> V_22 . V_2 , V_30 ) ;
}
static void F_24 ( struct V_13 * V_19 ,
const struct V_29 * * V_30 )
{
return F_25 ( & V_19 -> V_21 -> V_22 . V_2 , V_30 ) ;
}
int F_26 ( struct V_13 * V_19 , struct V_31 * V_32 )
{
struct V_8 * V_9 ;
int error ;
F_6 ( L_4 , V_19 -> V_16 ) ;
V_9 = F_27 ( sizeof( * V_9 ) , V_33 ) ;
if ( ! V_9 )
return - V_34 ;
F_28 ( & V_9 -> V_35 , F_17 , F_20 ) ;
F_29 ( & V_9 -> V_36 ) ;
F_30 ( & V_9 -> V_37 ) ;
F_31 ( & V_9 -> V_38 , L_5 , V_32 ) ;
error = F_32 ( & V_9 -> V_22 . V_2 , L_6 , V_19 -> V_16 ) ;
if ( error ) {
F_7 ( V_9 ) ;
return error ;
}
if ( ! V_19 -> V_39 )
V_19 -> V_39 = V_40 ;
#if F_33 ( V_41 )
if ( ! V_42 || V_19 != & V_43 )
V_9 -> V_22 . V_2 . V_44 = V_45 ;
#else
V_9 -> V_22 . V_2 . V_44 = V_45 ;
#endif
V_9 -> V_22 . V_2 . V_46 = & V_47 ;
V_9 -> V_13 = V_19 ;
V_19 -> V_21 = V_9 ;
error = F_34 ( & V_9 -> V_22 ) ;
if ( error ) {
F_7 ( V_9 ) ;
return error ;
}
error = F_22 ( F_13 ( V_19 ) , V_19 -> V_48 ) ;
F_15 ( V_19 ) ;
return error ;
}
void F_35 ( struct V_13 * V_19 )
{
F_6 ( L_7 , V_19 -> V_16 ) ;
F_24 ( V_19 , V_19 -> V_48 ) ;
F_36 ( & V_19 -> V_21 -> V_22 ) ;
}
static void F_37 ( struct V_13 * V_19 )
{
F_6 ( L_8 , V_49 , V_19 -> V_16 ) ;
F_7 ( V_19 ) ;
}
struct V_13 * F_38 ( struct V_50 * V_51 , const char * V_16 ,
struct V_31 * V_32 )
{
struct V_13 * V_19 ;
int V_52 ;
V_19 = F_27 ( sizeof( * V_19 ) , V_33 ) ;
if ( ! V_19 ) {
V_52 = - V_34 ;
goto error;
}
V_19 -> V_16 = V_16 ;
V_19 -> V_51 = V_51 ;
V_19 -> F_5 = F_37 ;
V_52 = F_26 ( V_19 , V_32 ) ;
if ( V_52 )
goto error;
return V_19 ;
error:
F_7 ( V_19 ) ;
return F_39 ( V_52 ) ;
}
void F_40 ( struct V_13 * V_19 )
{
if ( ( V_19 == NULL ) || ( F_41 ( V_19 ) ) )
return;
F_35 ( V_19 ) ;
}
void F_42 ( struct V_53 * V_54 , struct V_13 * V_13 ,
struct V_26 * V_55 , const struct V_56 * type )
{
struct V_24 * V_57 = NULL ;
if ( V_55 )
V_57 = & V_55 -> V_28 ;
F_43 ( & V_13 -> V_21 -> V_35 , & V_54 -> V_58 , V_57 ) ;
V_54 -> type = type ;
}
struct V_26 * F_44 ( struct V_53 * V_54 )
{
struct V_24 * V_59 ;
struct V_26 * V_27 ;
while ( 1 ) {
V_59 = F_45 ( & V_54 -> V_58 ) ;
if ( ! V_59 )
return NULL ;
V_27 = F_18 ( V_59 , struct V_26 , V_28 ) ;
if ( ! V_54 -> type || V_54 -> type == V_27 -> type )
return V_27 ;
}
}
void F_46 ( struct V_53 * V_54 )
{
F_47 ( & V_54 -> V_58 ) ;
}
int F_48 ( struct V_13 * V_13 , struct V_26 * V_55 ,
void * V_60 , int (* F_49)( struct V_26 * , void * ) )
{
struct V_53 V_54 ;
struct V_26 * V_27 ;
int error = 0 ;
if ( ! V_13 )
return - V_23 ;
if ( ! V_13 -> V_21 ) {
F_50 ( 1 , L_9 ,
V_49 , V_13 -> V_16 ) ;
return - V_23 ;
}
F_42 ( & V_54 , V_13 , V_55 , NULL ) ;
while ( ( V_27 = F_44 ( & V_54 ) ) ) {
error = F_49 ( V_27 , V_60 ) ;
if ( error )
break;
}
F_46 ( & V_54 ) ;
return error ;
}
struct V_26 * F_51 ( struct V_13 * V_13 , struct V_26 * V_55 ,
const void * V_60 ,
int (* F_52)( struct V_26 * , const void * ) )
{
struct V_53 V_54 ;
struct V_26 * V_27 ;
if ( ! V_13 )
return NULL ;
if ( ! V_13 -> V_21 ) {
F_50 ( 1 , L_9 ,
V_49 , V_13 -> V_16 ) ;
return NULL ;
}
F_42 ( & V_54 , V_13 , V_55 , NULL ) ;
while ( ( V_27 = F_44 ( & V_54 ) ) ) {
if ( F_52 ( V_27 , V_60 ) ) {
F_19 ( V_27 ) ;
break;
}
}
F_46 ( & V_54 ) ;
return V_27 ;
}
int F_53 ( struct V_61 * V_62 )
{
struct V_13 * V_63 ;
struct V_53 V_54 ;
struct V_26 * V_27 ;
if ( ! V_62 || ! V_62 -> V_13 )
return - V_64 ;
V_63 = F_13 ( V_62 -> V_13 ) ;
if ( ! V_63 )
return - V_23 ;
F_54 ( & V_63 -> V_21 -> V_38 ) ;
F_55 ( & V_62 -> V_65 , & V_63 -> V_21 -> V_36 ) ;
if ( V_62 -> V_66 ) {
F_42 ( & V_54 , V_63 , NULL , NULL ) ;
while ( ( V_27 = F_44 ( & V_54 ) ) )
V_62 -> V_66 ( V_27 , V_62 ) ;
F_46 ( & V_54 ) ;
}
F_56 ( & V_63 -> V_21 -> V_38 ) ;
return 0 ;
}
void F_57 ( struct V_61 * V_62 )
{
struct V_13 * V_63 = V_62 -> V_13 ;
struct V_53 V_54 ;
struct V_26 * V_27 ;
if ( ! V_63 )
return;
F_54 ( & V_63 -> V_21 -> V_38 ) ;
F_58 ( & V_62 -> V_65 ) ;
if ( V_62 -> V_67 ) {
F_42 ( & V_54 , V_63 , NULL , NULL ) ;
while ( ( V_27 = F_44 ( & V_54 ) ) )
V_62 -> V_67 ( V_27 , V_62 ) ;
F_46 ( & V_54 ) ;
}
F_56 ( & V_63 -> V_21 -> V_38 ) ;
F_15 ( V_63 ) ;
}
T_1 F_59 ( struct V_13 * V_13 ,
struct V_6 * V_4 , char * V_5 )
{
struct V_68 * V_69 ;
V_69 = F_18 ( V_4 , struct V_68 , V_4 ) ;
return snprintf ( V_5 , V_70 , L_10 , V_69 -> V_71 ) ;
}
struct V_72 * F_60 ( const char * V_16 )
{
struct V_72 * V_19 ;
V_19 = F_61 ( sizeof( struct V_72 ) , V_33 ) ;
if ( ! V_19 )
return NULL ;
V_19 -> V_2 = F_62 ( V_16 , & V_45 -> V_2 ) ;
if ( ! V_19 -> V_2 ) {
F_7 ( V_19 ) ;
return NULL ;
}
return V_19 ;
}
void F_63 ( struct V_72 * V_19 )
{
F_64 ( V_19 -> V_2 ) ;
F_7 ( V_19 ) ;
}
int F_65 ( struct V_72 * V_19 , struct V_26 * V_27 ,
struct V_26 * V_73 )
{
int error ;
error = F_66 ( V_19 -> V_2 , & V_27 -> V_2 , F_67 ( V_27 ) ) ;
if ( error )
return error ;
if ( V_73 ) {
error = F_66 ( & V_27 -> V_2 , & V_73 -> V_2 ,
L_11 ) ;
if ( error )
F_68 ( V_19 -> V_2 , F_67 ( V_27 ) ) ;
}
return error ;
}
void F_69 ( struct V_72 * V_19 , struct V_26 * V_27 ,
struct V_26 * V_73 )
{
if ( V_73 )
F_68 ( & V_27 -> V_2 , L_11 ) ;
F_68 ( V_19 -> V_2 , F_67 ( V_27 ) ) ;
}
int T_3 F_70 ( void )
{
V_45 = F_71 ( L_12 , NULL , NULL ) ;
if ( ! V_45 )
return - V_34 ;
return 0 ;
}
