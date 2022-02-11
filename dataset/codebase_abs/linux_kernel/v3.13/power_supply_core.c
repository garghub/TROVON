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
unsigned long V_18 ;
struct V_1 * V_13 = F_5 ( V_17 , struct V_1 ,
V_19 ) ;
F_6 ( V_13 -> V_11 , L_1 , V_20 ) ;
F_7 ( & V_13 -> V_21 , V_18 ) ;
if ( V_13 -> V_22 ) {
V_13 -> V_22 = false ;
F_8 ( & V_13 -> V_21 , V_18 ) ;
F_9 ( V_23 , NULL , V_13 ,
F_2 ) ;
F_10 ( V_13 ) ;
F_11 ( & V_13 -> V_11 -> V_24 , V_25 ) ;
F_7 ( & V_13 -> V_21 , V_18 ) ;
}
if ( ! V_13 -> V_22 )
F_12 ( V_13 -> V_11 ) ;
F_8 ( & V_13 -> V_21 , V_18 ) ;
}
void F_13 ( struct V_1 * V_13 )
{
unsigned long V_18 ;
F_6 ( V_13 -> V_11 , L_1 , V_20 ) ;
F_7 ( & V_13 -> V_21 , V_18 ) ;
V_13 -> V_22 = true ;
F_14 ( V_13 -> V_11 ) ;
F_8 ( & V_13 -> V_21 , V_18 ) ;
F_15 ( & V_13 -> V_19 ) ;
}
static int F_16 ( struct V_10 * V_11 ,
void * V_12 )
{
struct V_1 * V_13 = (struct V_1 * ) V_12 ;
struct V_1 * V_26 = F_3 ( V_11 ) ;
struct V_27 * V_28 ;
int V_4 = 0 ;
do {
V_28 = F_17 ( V_13 -> V_29 , L_2 , V_4 ++ ) ;
if ( ! V_28 )
continue;
if ( V_28 == V_26 -> V_29 ) {
F_18 ( V_13 -> V_11 , L_3 ,
V_13 -> V_7 , V_26 -> V_7 ) ;
V_13 -> V_5 [ V_4 - 1 ] = ( char * ) V_26 -> V_7 ;
V_13 -> V_8 ++ ;
F_19 ( V_28 ) ;
break;
}
F_19 ( V_28 ) ;
} while ( V_28 );
return 0 ;
}
static int F_20 ( struct V_1 * V_13 )
{
int error ;
error = F_9 ( V_23 , NULL , V_13 ,
F_16 ) ;
F_6 ( V_13 -> V_11 , L_4 , V_20 , error ) ;
return error ;
}
static int F_21 ( struct V_10 * V_11 ,
void * V_12 )
{
struct V_27 * V_28 = (struct V_27 * ) V_12 ;
struct V_1 * V_26 = F_3 ( V_11 ) ;
if ( V_26 -> V_29 == V_28 )
return - V_30 ;
return 0 ;
}
static int F_22 ( struct V_27 * V_31 )
{
int error ;
struct V_10 * V_11 ;
struct V_32 V_33 ;
F_23 ( & V_33 , V_23 , NULL , NULL ) ;
V_11 = F_24 ( & V_33 ) ;
if ( ! V_11 )
return - V_34 ;
error = F_9 ( V_23 , NULL , V_31 ,
F_21 ) ;
return error ? 0 : - V_34 ;
}
static int F_25 ( struct V_1 * V_13 )
{
struct V_27 * V_28 ;
int V_35 = 0 ;
if ( V_13 -> V_5 && V_13 -> V_8 > 0 )
return 0 ;
if ( ! V_13 -> V_29 )
return 0 ;
do {
int V_36 ;
V_28 = F_17 ( V_13 -> V_29 , L_2 , V_35 ++ ) ;
if ( ! V_28 )
continue;
V_36 = F_22 ( V_28 ) ;
if ( V_36 ) {
F_6 ( V_13 -> V_11 , L_5 ) ;
F_19 ( V_28 ) ;
return - V_34 ;
}
F_19 ( V_28 ) ;
} while ( V_28 );
V_13 -> V_5 = F_26 ( V_13 -> V_11 , sizeof( V_13 -> V_5 ) ,
V_37 ) ;
if ( ! V_13 -> V_5 ) {
F_27 ( V_13 -> V_11 , L_6 ) ;
return - V_38 ;
}
* V_13 -> V_5 = F_26 ( V_13 -> V_11 , sizeof( char * ) * V_35 ,
V_37 ) ;
if ( ! * V_13 -> V_5 ) {
F_27 ( V_13 -> V_11 , L_6 ) ;
return - V_38 ;
}
return F_20 ( V_13 ) ;
}
static inline int F_25 ( struct V_1 * V_13 )
{
return 0 ;
}
static int F_28 ( struct V_10 * V_11 , void * V_12 )
{
union V_39 V_36 = { 0 ,} ;
struct V_1 * V_13 = (struct V_1 * ) V_12 ;
struct V_1 * V_26 = F_3 ( V_11 ) ;
if ( F_1 ( V_26 , V_13 ) )
if ( ! V_26 -> V_40 ( V_26 , V_41 , & V_36 ) ) {
if ( V_36 . V_42 )
return V_36 . V_42 ;
}
return 0 ;
}
int F_29 ( struct V_1 * V_13 )
{
int error ;
error = F_9 ( V_23 , NULL , V_13 ,
F_28 ) ;
F_6 ( V_13 -> V_11 , L_4 , V_20 , error ) ;
return error ;
}
static int F_30 ( struct V_10 * V_11 , void * V_12 )
{
union V_39 V_36 = { 0 ,} ;
struct V_1 * V_13 = F_3 ( V_11 ) ;
unsigned int * V_43 = V_12 ;
( * V_43 ) ++ ;
if ( V_13 -> type != V_44 ) {
if ( V_13 -> V_40 ( V_13 , V_41 , & V_36 ) )
return 0 ;
if ( V_36 . V_42 )
return V_36 . V_42 ;
}
return 0 ;
}
int F_31 ( void )
{
int error ;
unsigned int V_43 = 0 ;
error = F_9 ( V_23 , NULL , & V_43 ,
F_30 ) ;
if ( V_43 == 0 )
return 1 ;
return error ;
}
int F_32 ( struct V_1 * V_13 )
{
if ( V_13 -> type == V_44 && V_13 -> V_45 ) {
V_13 -> V_45 ( V_13 ) ;
return 0 ;
}
return - V_30 ;
}
static int F_33 ( struct V_10 * V_11 , const void * V_12 )
{
const char * V_7 = V_12 ;
struct V_1 * V_13 = F_3 ( V_11 ) ;
return strcmp ( V_13 -> V_7 , V_7 ) == 0 ;
}
struct V_1 * F_34 ( const char * V_7 )
{
struct V_10 * V_11 = F_35 ( V_23 , NULL , V_7 ,
F_33 ) ;
return V_11 ? F_3 ( V_11 ) : NULL ;
}
int F_36 ( struct V_1 * V_13 , struct V_10 * V_11 )
{
return F_37 ( & V_13 -> V_11 -> V_24 , & V_11 -> V_24 , L_7 ) ;
}
static void F_38 ( struct V_10 * V_11 )
{
F_39 ( L_8 , F_40 ( V_11 ) , V_20 ) ;
F_41 ( V_11 ) ;
}
static int F_42 ( struct V_46 * V_47 ,
unsigned long * V_48 )
{
struct V_1 * V_13 ;
union V_39 V_49 ;
int V_36 ;
F_43 ( V_47 == NULL ) ;
V_13 = V_47 -> V_50 ;
V_36 = V_13 -> V_40 ( V_13 , V_51 , & V_49 ) ;
if ( ! V_36 )
* V_48 = V_49 . V_42 * 100 ;
return V_36 ;
}
static int F_44 ( struct V_1 * V_13 )
{
int V_4 ;
for ( V_4 = 0 ; V_4 < V_13 -> V_52 ; V_4 ++ ) {
if ( V_13 -> V_53 [ V_4 ] == V_51 ) {
V_13 -> V_47 = F_45 ( V_13 -> V_7 , 0 , 0 ,
V_13 , & V_54 , NULL , 0 , 0 ) ;
if ( F_46 ( V_13 -> V_47 ) )
return F_47 ( V_13 -> V_47 ) ;
break;
}
}
return 0 ;
}
static void F_48 ( struct V_1 * V_13 )
{
if ( F_49 ( V_13 -> V_47 ) )
return;
F_50 ( V_13 -> V_47 ) ;
}
static int F_51 ( struct V_55 * V_56 ,
unsigned long * V_57 )
{
struct V_1 * V_13 ;
union V_39 V_49 ;
int V_36 ;
V_13 = V_56 -> V_50 ;
V_36 = V_13 -> V_40 ( V_13 ,
V_58 , & V_49 ) ;
if ( ! V_36 )
* V_57 = V_49 . V_42 ;
return V_36 ;
}
static int F_52 ( struct V_55 * V_56 ,
unsigned long * V_57 )
{
struct V_1 * V_13 ;
union V_39 V_49 ;
int V_36 ;
V_13 = V_56 -> V_50 ;
V_36 = V_13 -> V_40 ( V_13 ,
V_59 , & V_49 ) ;
if ( ! V_36 )
* V_57 = V_49 . V_42 ;
return V_36 ;
}
static int F_53 ( struct V_55 * V_56 ,
unsigned long V_57 )
{
struct V_1 * V_13 ;
union V_39 V_49 ;
int V_36 ;
V_13 = V_56 -> V_50 ;
V_49 . V_42 = V_57 ;
V_36 = V_13 -> V_60 ( V_13 ,
V_59 , & V_49 ) ;
return V_36 ;
}
static int F_54 ( struct V_1 * V_13 )
{
int V_4 ;
for ( V_4 = 0 ; V_4 < V_13 -> V_52 ; V_4 ++ ) {
if ( V_13 -> V_53 [ V_4 ] ==
V_59 ) {
V_13 -> V_56 = F_55 (
( char * ) V_13 -> V_7 ,
V_13 , & V_61 ) ;
if ( F_46 ( V_13 -> V_56 ) )
return F_47 ( V_13 -> V_56 ) ;
break;
}
}
return 0 ;
}
static void F_56 ( struct V_1 * V_13 )
{
if ( F_49 ( V_13 -> V_56 ) )
return;
F_57 ( V_13 -> V_56 ) ;
}
static int F_44 ( struct V_1 * V_13 )
{
return 0 ;
}
static void F_48 ( struct V_1 * V_13 )
{
}
static int F_54 ( struct V_1 * V_13 )
{
return 0 ;
}
static void F_56 ( struct V_1 * V_13 )
{
}
int F_58 ( struct V_10 * V_62 , struct V_1 * V_13 )
{
struct V_10 * V_11 ;
int V_63 ;
V_11 = F_59 ( sizeof( * V_11 ) , V_37 ) ;
if ( ! V_11 )
return - V_38 ;
F_60 ( V_11 ) ;
V_11 -> V_64 = V_23 ;
V_11 -> type = & V_65 ;
V_11 -> V_62 = V_62 ;
V_11 -> V_66 = F_38 ;
F_61 ( V_11 , V_13 ) ;
V_13 -> V_11 = V_11 ;
V_63 = F_62 ( V_11 , L_9 , V_13 -> V_7 ) ;
if ( V_63 )
goto V_67;
F_63 ( & V_13 -> V_19 , F_4 ) ;
V_63 = F_25 ( V_13 ) ;
if ( V_63 ) {
F_18 ( V_11 , L_10 ) ;
goto V_68;
}
F_64 ( & V_13 -> V_21 ) ;
V_63 = F_65 ( V_11 , true ) ;
if ( V_63 )
goto V_69;
V_63 = F_66 ( V_11 ) ;
if ( V_63 )
goto V_70;
V_63 = F_44 ( V_13 ) ;
if ( V_63 )
goto V_71;
V_63 = F_54 ( V_13 ) ;
if ( V_63 )
goto V_72;
V_63 = F_67 ( V_13 ) ;
if ( V_63 )
goto V_73;
F_13 ( V_13 ) ;
goto V_74;
V_73:
F_56 ( V_13 ) ;
V_72:
F_48 ( V_13 ) ;
V_71:
F_68 ( V_11 ) ;
V_70:
V_69:
V_68:
V_67:
F_69 ( V_11 ) ;
V_74:
return V_63 ;
}
void F_70 ( struct V_1 * V_13 )
{
F_71 ( & V_13 -> V_19 ) ;
F_72 ( & V_13 -> V_11 -> V_24 , L_7 ) ;
F_73 ( V_13 ) ;
F_56 ( V_13 ) ;
F_48 ( V_13 ) ;
F_65 ( V_13 -> V_11 , false ) ;
F_74 ( V_13 -> V_11 ) ;
}
static int T_1 F_75 ( void )
{
V_23 = F_76 ( V_75 , L_11 ) ;
if ( F_46 ( V_23 ) )
return F_47 ( V_23 ) ;
V_23 -> V_76 = V_77 ;
F_77 ( & V_65 ) ;
return 0 ;
}
static void T_2 F_78 ( void )
{
F_79 ( V_23 ) ;
}
