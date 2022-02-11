static bool F_1 ( struct V_1 * V_2 ,
struct V_1 * V_3 )
{
int V_4 ;
if ( ! V_3 -> V_5 && ! V_2 -> V_6 )
return false ;
if ( V_3 -> V_5 ) {
if ( ! V_2 -> V_7 )
return false ;
for ( V_4 = 0 ; V_4 < V_3 -> V_8 ; V_4 ++ )
if ( ! strcmp ( V_2 -> V_7 , V_3 -> V_5 [ V_4 ] ) )
return true ;
} else {
if ( ! V_3 -> V_7 )
return false ;
for ( V_4 = 0 ; V_4 < V_2 -> V_9 ; V_4 ++ )
if ( ! strcmp ( V_2 -> V_6 [ V_4 ] , V_3 -> V_7 ) )
return true ;
}
return false ;
}
static int F_2 ( struct V_10 * V_11 , void * V_12 )
{
struct V_1 * V_13 = (struct V_1 * ) V_12 ;
struct V_1 * V_14 = F_3 ( V_11 ) ;
if ( F_1 ( V_13 , V_14 ) ) {
if ( V_14 -> V_15 )
V_14 -> V_15 ( V_14 ) ;
}
return 0 ;
}
static void F_4 ( struct V_16 * V_17 )
{
struct V_1 * V_13 = F_5 ( V_17 , struct V_1 ,
V_18 ) ;
F_6 ( V_13 -> V_11 , L_1 , V_19 ) ;
F_7 ( V_20 , NULL , V_13 ,
F_2 ) ;
F_8 ( V_13 ) ;
F_9 ( & V_13 -> V_11 -> V_21 , V_22 ) ;
}
void F_10 ( struct V_1 * V_13 )
{
F_6 ( V_13 -> V_11 , L_1 , V_19 ) ;
F_11 ( & V_13 -> V_18 ) ;
}
static int F_12 ( struct V_10 * V_11 ,
void * V_12 )
{
struct V_1 * V_13 = (struct V_1 * ) V_12 ;
struct V_1 * V_23 = F_3 ( V_11 ) ;
struct V_24 * V_25 ;
int V_4 = 0 ;
do {
V_25 = F_13 ( V_13 -> V_26 , L_2 , V_4 ++ ) ;
if ( ! V_25 )
continue;
if ( V_25 == V_23 -> V_26 ) {
F_14 ( V_13 -> V_11 , L_3 ,
V_13 -> V_7 , V_23 -> V_7 ) ;
V_13 -> V_5 [ V_4 - 1 ] = ( char * ) V_23 -> V_7 ;
V_13 -> V_8 ++ ;
F_15 ( V_25 ) ;
break;
}
F_15 ( V_25 ) ;
} while ( V_25 );
return 0 ;
}
static int F_16 ( struct V_1 * V_13 )
{
int error ;
error = F_7 ( V_20 , NULL , V_13 ,
F_12 ) ;
F_6 ( V_13 -> V_11 , L_4 , V_19 , error ) ;
return error ;
}
static int F_17 ( struct V_10 * V_11 ,
void * V_12 )
{
struct V_24 * V_25 = (struct V_24 * ) V_12 ;
struct V_1 * V_23 = F_3 ( V_11 ) ;
if ( V_23 -> V_26 == V_25 )
return - V_27 ;
return 0 ;
}
static int F_18 ( struct V_24 * V_28 )
{
int error ;
struct V_10 * V_11 ;
struct V_29 V_30 ;
F_19 ( & V_30 , V_20 , NULL , NULL ) ;
V_11 = F_20 ( & V_30 ) ;
if ( ! V_11 )
return - V_31 ;
error = F_7 ( V_20 , NULL , V_28 ,
F_17 ) ;
return error ? 0 : - V_31 ;
}
static int F_21 ( struct V_1 * V_13 )
{
struct V_24 * V_25 ;
int V_32 = 0 ;
if ( V_13 -> V_5 && V_13 -> V_8 > 0 )
return 0 ;
if ( ! V_13 -> V_26 )
return 0 ;
do {
int V_33 ;
V_25 = F_13 ( V_13 -> V_26 , L_2 , V_32 ++ ) ;
if ( ! V_25 )
continue;
V_33 = F_18 ( V_25 ) ;
if ( V_33 ) {
F_6 ( V_13 -> V_11 , L_5 ) ;
F_15 ( V_25 ) ;
return - V_31 ;
}
F_15 ( V_25 ) ;
} while ( V_25 );
V_13 -> V_5 = F_22 ( V_13 -> V_11 , sizeof( V_13 -> V_5 ) ,
V_34 ) ;
if ( ! V_13 -> V_5 ) {
F_23 ( V_13 -> V_11 , L_6 ) ;
return - V_35 ;
}
* V_13 -> V_5 = F_22 ( V_13 -> V_11 , sizeof( char * ) * V_32 ,
V_34 ) ;
if ( ! * V_13 -> V_5 ) {
F_23 ( V_13 -> V_11 , L_6 ) ;
return - V_35 ;
}
return F_16 ( V_13 ) ;
}
static inline int F_21 ( struct V_1 * V_13 )
{
return 0 ;
}
static int F_24 ( struct V_10 * V_11 , void * V_12 )
{
union V_36 V_33 = { 0 ,} ;
struct V_1 * V_13 = (struct V_1 * ) V_12 ;
struct V_1 * V_23 = F_3 ( V_11 ) ;
if ( F_1 ( V_23 , V_13 ) )
if ( ! V_23 -> V_37 ( V_23 , V_38 , & V_33 ) ) {
if ( V_33 . V_39 )
return V_33 . V_39 ;
}
return 0 ;
}
int F_25 ( struct V_1 * V_13 )
{
int error ;
error = F_7 ( V_20 , NULL , V_13 ,
F_24 ) ;
F_6 ( V_13 -> V_11 , L_4 , V_19 , error ) ;
return error ;
}
static int F_26 ( struct V_10 * V_11 , void * V_12 )
{
union V_36 V_33 = { 0 ,} ;
struct V_1 * V_13 = F_3 ( V_11 ) ;
unsigned int * V_40 = V_12 ;
( * V_40 ) ++ ;
if ( V_13 -> type != V_41 ) {
if ( V_13 -> V_37 ( V_13 , V_38 , & V_33 ) )
return 0 ;
if ( V_33 . V_39 )
return V_33 . V_39 ;
}
return 0 ;
}
int F_27 ( void )
{
int error ;
unsigned int V_40 = 0 ;
error = F_7 ( V_20 , NULL , & V_40 ,
F_26 ) ;
if ( V_40 == 0 )
return 1 ;
return error ;
}
int F_28 ( struct V_1 * V_13 )
{
if ( V_13 -> type == V_41 && V_13 -> V_42 ) {
V_13 -> V_42 ( V_13 ) ;
return 0 ;
}
return - V_27 ;
}
static int F_29 ( struct V_10 * V_11 , const void * V_12 )
{
const char * V_7 = V_12 ;
struct V_1 * V_13 = F_3 ( V_11 ) ;
return strcmp ( V_13 -> V_7 , V_7 ) == 0 ;
}
struct V_1 * F_30 ( const char * V_7 )
{
struct V_10 * V_11 = F_31 ( V_20 , NULL , V_7 ,
F_29 ) ;
return V_11 ? F_3 ( V_11 ) : NULL ;
}
int F_32 ( struct V_1 * V_13 , struct V_10 * V_11 )
{
return F_33 ( & V_13 -> V_11 -> V_21 , & V_11 -> V_21 , L_7 ) ;
}
static void F_34 ( struct V_10 * V_11 )
{
F_35 ( L_8 , F_36 ( V_11 ) , V_19 ) ;
F_37 ( V_11 ) ;
}
static int F_38 ( struct V_43 * V_44 ,
unsigned long * V_45 )
{
struct V_1 * V_13 ;
union V_36 V_46 ;
int V_33 ;
F_39 ( V_44 == NULL ) ;
V_13 = V_44 -> V_47 ;
V_33 = V_13 -> V_37 ( V_13 , V_48 , & V_46 ) ;
if ( ! V_33 )
* V_45 = V_46 . V_39 * 100 ;
return V_33 ;
}
static int F_40 ( struct V_1 * V_13 )
{
int V_4 ;
for ( V_4 = 0 ; V_4 < V_13 -> V_49 ; V_4 ++ ) {
if ( V_13 -> V_50 [ V_4 ] == V_48 ) {
V_13 -> V_44 = F_41 ( V_13 -> V_7 , 0 , 0 ,
V_13 , & V_51 , NULL , 0 , 0 ) ;
if ( F_42 ( V_13 -> V_44 ) )
return F_43 ( V_13 -> V_44 ) ;
break;
}
}
return 0 ;
}
static void F_44 ( struct V_1 * V_13 )
{
if ( F_45 ( V_13 -> V_44 ) )
return;
F_46 ( V_13 -> V_44 ) ;
}
static int F_47 ( struct V_52 * V_53 ,
unsigned long * V_54 )
{
struct V_1 * V_13 ;
union V_36 V_46 ;
int V_33 ;
V_13 = V_53 -> V_47 ;
V_33 = V_13 -> V_37 ( V_13 ,
V_55 , & V_46 ) ;
if ( ! V_33 )
* V_54 = V_46 . V_39 ;
return V_33 ;
}
static int F_48 ( struct V_52 * V_53 ,
unsigned long * V_54 )
{
struct V_1 * V_13 ;
union V_36 V_46 ;
int V_33 ;
V_13 = V_53 -> V_47 ;
V_33 = V_13 -> V_37 ( V_13 ,
V_56 , & V_46 ) ;
if ( ! V_33 )
* V_54 = V_46 . V_39 ;
return V_33 ;
}
static int F_49 ( struct V_52 * V_53 ,
unsigned long V_54 )
{
struct V_1 * V_13 ;
union V_36 V_46 ;
int V_33 ;
V_13 = V_53 -> V_47 ;
V_46 . V_39 = V_54 ;
V_33 = V_13 -> V_57 ( V_13 ,
V_56 , & V_46 ) ;
return V_33 ;
}
static int F_50 ( struct V_1 * V_13 )
{
int V_4 ;
for ( V_4 = 0 ; V_4 < V_13 -> V_49 ; V_4 ++ ) {
if ( V_13 -> V_50 [ V_4 ] ==
V_56 ) {
V_13 -> V_53 = F_51 (
( char * ) V_13 -> V_7 ,
V_13 , & V_58 ) ;
if ( F_42 ( V_13 -> V_53 ) )
return F_43 ( V_13 -> V_53 ) ;
break;
}
}
return 0 ;
}
static void F_52 ( struct V_1 * V_13 )
{
if ( F_45 ( V_13 -> V_53 ) )
return;
F_53 ( V_13 -> V_53 ) ;
}
static int F_40 ( struct V_1 * V_13 )
{
return 0 ;
}
static void F_44 ( struct V_1 * V_13 )
{
}
static int F_50 ( struct V_1 * V_13 )
{
return 0 ;
}
static void F_52 ( struct V_1 * V_13 )
{
}
int F_54 ( struct V_10 * V_59 , struct V_1 * V_13 )
{
struct V_10 * V_11 ;
int V_60 ;
V_11 = F_55 ( sizeof( * V_11 ) , V_34 ) ;
if ( ! V_11 )
return - V_35 ;
F_56 ( V_11 ) ;
V_11 -> V_61 = V_20 ;
V_11 -> type = & V_62 ;
V_11 -> V_59 = V_59 ;
V_11 -> V_63 = F_34 ;
F_57 ( V_11 , V_13 ) ;
V_13 -> V_11 = V_11 ;
F_58 ( & V_13 -> V_18 , F_4 ) ;
V_60 = F_21 ( V_13 ) ;
if ( V_60 ) {
F_14 ( V_11 , L_9 ) ;
goto V_64;
}
V_60 = F_59 ( & V_11 -> V_21 , L_10 , V_13 -> V_7 ) ;
if ( V_60 )
goto V_65;
V_60 = F_60 ( V_11 ) ;
if ( V_60 )
goto V_66;
V_60 = F_40 ( V_13 ) ;
if ( V_60 )
goto V_67;
V_60 = F_50 ( V_13 ) ;
if ( V_60 )
goto V_68;
V_60 = F_61 ( V_13 ) ;
if ( V_60 )
goto V_69;
F_10 ( V_13 ) ;
goto V_70;
V_69:
F_52 ( V_13 ) ;
V_68:
F_44 ( V_13 ) ;
V_67:
F_62 ( V_11 ) ;
V_65:
V_66:
V_64:
F_63 ( V_11 ) ;
V_70:
return V_60 ;
}
void F_64 ( struct V_1 * V_13 )
{
F_65 ( & V_13 -> V_18 ) ;
F_66 ( & V_13 -> V_11 -> V_21 , L_7 ) ;
F_67 ( V_13 ) ;
F_52 ( V_13 ) ;
F_44 ( V_13 ) ;
F_68 ( V_13 -> V_11 ) ;
}
static int T_1 F_69 ( void )
{
V_20 = F_70 ( V_71 , L_11 ) ;
if ( F_42 ( V_20 ) )
return F_43 ( V_20 ) ;
V_20 -> V_72 = V_73 ;
F_71 ( & V_62 ) ;
return 0 ;
}
static void T_2 F_72 ( void )
{
F_73 ( V_20 ) ;
}
