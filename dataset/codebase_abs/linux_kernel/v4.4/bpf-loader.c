struct V_1 *
F_1 ( void * V_2 , T_1 V_3 , const char * V_4 )
{
struct V_1 * V_5 ;
if ( ! V_6 ) {
F_2 ( V_7 ,
V_8 ,
V_9 ) ;
V_6 = true ;
}
V_5 = F_3 ( V_2 , V_3 , V_4 ) ;
if ( F_4 ( V_5 ) ) {
F_5 ( L_1 ) ;
return F_6 ( - V_10 ) ;
}
return V_5 ;
}
struct V_1 * F_7 ( const char * V_11 , bool V_12 )
{
struct V_1 * V_5 ;
if ( ! V_6 ) {
F_2 ( V_7 ,
V_8 ,
V_9 ) ;
V_6 = true ;
}
if ( V_12 ) {
int V_13 ;
void * V_2 ;
T_1 V_3 ;
V_13 = F_8 ( V_11 , & V_2 , & V_3 ) ;
if ( V_13 )
return F_6 ( - V_14 ) ;
V_5 = F_3 ( V_2 , V_3 , V_11 ) ;
free ( V_2 ) ;
} else
V_5 = F_9 ( V_11 ) ;
if ( F_4 ( V_5 ) ) {
F_5 ( L_2 , V_11 ) ;
return V_5 ;
}
return V_5 ;
}
void F_10 ( void )
{
struct V_1 * V_5 , * V_15 ;
F_11 (obj, tmp) {
F_12 ( V_5 ) ;
F_13 ( V_5 ) ;
}
}
static void
F_14 ( struct V_16 * T_2 V_17 ,
void * V_18 )
{
struct V_19 * V_20 = V_18 ;
F_15 ( & V_20 -> V_21 , 1 ) ;
free ( V_20 ) ;
}
static int
F_16 ( struct V_16 * T_2 )
{
struct V_22 * V_21 = NULL ;
struct V_19 * V_20 = NULL ;
const char * V_23 ;
int V_13 ;
V_23 = F_17 ( T_2 , false ) ;
if ( F_4 ( V_23 ) ) {
F_5 ( L_3 ) ;
return F_18 ( V_23 ) ;
}
V_20 = calloc ( sizeof( * V_20 ) , 1 ) ;
if ( ! V_20 ) {
F_5 ( L_4 ) ;
return - V_24 ;
}
V_21 = & V_20 -> V_21 ;
F_5 ( L_5 , V_23 ) ;
V_13 = F_19 ( V_23 , V_21 ) ;
if ( V_13 < 0 ) {
F_5 ( L_6 ,
V_23 ) ;
V_13 = - V_25 ;
goto V_26;
}
if ( V_21 -> V_27 && strcmp ( V_21 -> V_27 , V_28 ) ) {
F_5 ( L_7 ,
V_23 , V_28 ) ;
V_13 = - V_29 ;
goto V_26;
} else if ( ! V_21 -> V_27 )
V_21 -> V_27 = F_20 ( V_28 ) ;
if ( ! V_21 -> V_27 ) {
F_5 ( L_8 ) ;
V_13 = - V_24 ;
goto V_26;
}
if ( ! V_21 -> V_30 ) {
F_5 ( L_9 ,
V_23 ) ;
V_13 = - V_31 ;
goto V_26;
}
F_5 ( L_10 , V_23 ) ;
V_13 = F_21 ( T_2 , V_20 , F_14 ) ;
if ( V_13 ) {
F_5 ( L_11 , V_23 ) ;
goto V_26;
}
return 0 ;
V_26:
if ( V_21 )
F_22 ( V_21 ) ;
free ( V_20 ) ;
return V_13 ;
}
static int F_23 ( void )
{
static int V_13 = 0 ;
static bool V_32 = false ;
if ( V_32 )
return V_13 ;
V_32 = true ;
V_13 = F_24 ( false ) ;
if ( V_13 < 0 )
F_5 ( L_12 ) ;
V_33 . V_34 = V_35 ;
return V_13 ;
}
int F_25 ( struct V_1 * V_5 )
{
int V_13 = 0 ;
struct V_16 * T_2 ;
struct V_19 * V_20 ;
struct V_22 * V_21 ;
V_13 = F_23 () ;
if ( V_13 ) {
F_5 ( L_13 ) ;
return V_13 ;
}
F_26 (prog, obj) {
V_13 = F_16 ( T_2 ) ;
if ( V_13 )
goto V_36;
V_13 = F_27 ( T_2 , ( void * * ) & V_20 ) ;
if ( V_13 || ! V_20 )
goto V_36;
V_21 = & V_20 -> V_21 ;
V_13 = F_28 ( V_21 , 1 ) ;
if ( V_13 < 0 ) {
F_5 ( L_14 ) ;
goto V_36;
}
V_13 = F_29 ( V_21 , 1 ) ;
if ( V_13 < 0 ) {
F_5 ( L_15 ) ;
goto V_36;
}
}
V_36:
return V_13 < 0 ? V_13 : 0 ;
}
int F_12 ( struct V_1 * V_5 )
{
int V_13 , V_37 = 0 ;
struct V_16 * T_2 ;
struct V_19 * V_20 ;
F_26 (prog, obj) {
int V_38 ;
V_13 = F_27 ( T_2 , ( void * * ) & V_20 ) ;
if ( V_13 || ! V_20 )
continue;
for ( V_38 = 0 ; V_38 < V_20 -> V_21 . V_39 ; V_38 ++ ) {
struct V_40 * V_41 = & V_20 -> V_21 . V_42 [ V_38 ] ;
char V_43 [ V_44 ] ;
struct V_45 * V_46 ;
snprintf ( V_43 , V_44 ,
L_16 , V_41 -> V_27 , V_41 -> V_30 ) ;
V_43 [ V_44 - 1 ] = '\0' ;
V_46 = F_30 ( V_43 , NULL ) ;
if ( ! V_46 ) {
F_5 ( L_17 ) ;
V_37 = - V_24 ;
continue;
}
V_13 = F_31 ( V_46 ) ;
F_32 ( V_46 ) ;
if ( V_13 ) {
F_5 ( L_18 , V_43 ) ;
V_37 = V_13 ;
continue;
}
}
}
return V_37 ;
}
int F_33 ( struct V_1 * V_5 )
{
int V_13 ;
V_13 = F_34 ( V_5 ) ;
if ( V_13 ) {
F_5 ( L_19 ) ;
return V_13 ;
}
return 0 ;
}
int F_35 ( struct V_1 * V_5 ,
T_3 V_47 ,
void * V_48 )
{
struct V_16 * T_2 ;
int V_13 ;
F_26 (prog, obj) {
struct V_40 * V_41 ;
struct V_22 * V_21 ;
struct V_19 * V_20 ;
int V_38 , V_49 ;
V_13 = F_27 ( T_2 ,
( void * * ) & V_20 ) ;
if ( V_13 || ! V_20 ) {
F_5 ( L_20 ) ;
return - V_50 ;
}
V_21 = & V_20 -> V_21 ;
for ( V_38 = 0 ; V_38 < V_21 -> V_39 ; V_38 ++ ) {
V_41 = & V_21 -> V_42 [ V_38 ] ;
V_49 = F_36 ( T_2 ) ;
if ( V_49 < 0 ) {
F_5 ( L_21 ) ;
return V_49 ;
}
V_13 = (* V_47)( V_41 , V_49 , V_48 ) ;
if ( V_13 ) {
F_5 ( L_22 ) ;
return V_13 ;
}
}
}
return 0 ;
}
static int
F_37 ( int V_13 , char * V_51 , T_1 V_52 )
{
char V_53 [ V_54 ] ;
const char * V_55 ;
if ( ! V_51 || ! V_52 )
return - 1 ;
V_13 = V_13 > 0 ? V_13 : - V_13 ;
if ( V_13 >= V_56 )
return F_38 ( V_13 , V_51 , V_52 ) ;
if ( V_13 >= V_57 && V_13 < V_58 ) {
V_55 = V_59 [ F_39 ( V_13 ) ] ;
snprintf ( V_51 , V_52 , L_23 , V_55 ) ;
V_51 [ V_52 - 1 ] = '\0' ;
return 0 ;
}
if ( V_13 >= V_58 )
snprintf ( V_51 , V_52 , L_24 , V_13 ) ;
else
snprintf ( V_51 , V_52 , L_23 ,
F_40 ( V_13 , V_53 , sizeof( V_53 ) ) ) ;
V_51 [ V_52 - 1 ] = '\0' ;
return - 1 ;
}
int F_41 ( const char * V_11 , bool V_12 ,
int V_13 , char * V_51 , T_1 V_52 )
{
T_1 V_60 ;
int V_37 ;
V_60 = snprintf ( V_51 , V_52 , L_25 ,
V_11 , V_12 ? L_26 : L_27 ) ;
if ( V_60 >= V_52 ) {
V_51 [ V_52 - 1 ] = '\0' ;
return 0 ;
}
V_51 += V_60 ;
V_52 -= V_60 ;
V_37 = F_37 ( V_13 , V_51 , V_52 ) ;
V_51 [ V_52 - 1 ] = '\0' ;
return V_37 ;
}
int F_42 ( struct V_1 * V_5 V_17 ,
int V_13 , char * V_51 , T_1 V_52 )
{
F_43 ( V_13 , V_51 , V_52 ) ;
F_44 ( V_61 , L_28 ) ;
F_44 ( V_62 , L_29 ) ;
F_44 ( V_63 , L_30 ) ;
F_44 ( V_64 , L_31 ) ;
F_45 ( V_51 , V_52 ) ;
return 0 ;
}
int F_46 ( struct V_1 * V_5 ,
int V_13 , char * V_51 , T_1 V_52 )
{
F_43 ( V_13 , V_51 , V_52 ) ;
case V_65 : {
unsigned int V_66 = F_47 ( V_5 ) ;
unsigned int V_67 ;
if ( F_48 ( & V_67 , NULL , 0 ) ) {
F_49 ( V_51 , V_52 , L_32 ) ;
break;
}
if ( V_66 != V_67 ) {
F_49 ( V_51 , V_52 ,
L_33 V_68 L_34 V_68 L_35 ,
F_50 ( V_66 ) ,
F_50 ( V_67 ) ) ;
break;
}
F_49 ( V_51 , V_52 , L_36 ) ;
break;
}
F_45 ( V_51 , V_52 ) ;
return 0 ;
}
