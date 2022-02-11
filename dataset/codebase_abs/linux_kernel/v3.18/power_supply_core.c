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
struct V_1 * V_13 = V_12 ;
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
if ( F_8 ( V_13 -> V_22 ) ) {
V_13 -> V_22 = false ;
F_9 ( & V_13 -> V_21 , V_18 ) ;
F_10 ( V_23 , NULL , V_13 ,
F_2 ) ;
F_11 ( V_13 ) ;
F_12 ( & V_24 ,
V_25 , V_13 ) ;
F_13 ( & V_13 -> V_11 -> V_26 , V_27 ) ;
F_7 ( & V_13 -> V_21 , V_18 ) ;
}
if ( F_8 ( ! V_13 -> V_22 ) )
F_14 ( V_13 -> V_11 ) ;
F_9 ( & V_13 -> V_21 , V_18 ) ;
}
void F_15 ( struct V_1 * V_13 )
{
unsigned long V_18 ;
F_6 ( V_13 -> V_11 , L_1 , V_20 ) ;
F_7 ( & V_13 -> V_21 , V_18 ) ;
V_13 -> V_22 = true ;
F_16 ( V_13 -> V_11 ) ;
F_9 ( & V_13 -> V_21 , V_18 ) ;
F_17 ( & V_13 -> V_19 ) ;
}
static int F_18 ( struct V_10 * V_11 ,
void * V_12 )
{
struct V_1 * V_13 = V_12 ;
struct V_1 * V_28 = F_3 ( V_11 ) ;
struct V_29 * V_30 ;
int V_4 = 0 ;
do {
V_30 = F_19 ( V_13 -> V_31 , L_2 , V_4 ++ ) ;
if ( ! V_30 )
break;
if ( V_30 == V_28 -> V_31 ) {
F_20 ( V_13 -> V_11 , L_3 ,
V_13 -> V_7 , V_28 -> V_7 ) ;
V_13 -> V_5 [ V_4 - 1 ] = ( char * ) V_28 -> V_7 ;
V_13 -> V_8 ++ ;
F_21 ( V_30 ) ;
break;
}
F_21 ( V_30 ) ;
} while ( V_30 );
return 0 ;
}
static int F_22 ( struct V_1 * V_13 )
{
int error ;
error = F_10 ( V_23 , NULL , V_13 ,
F_18 ) ;
F_6 ( V_13 -> V_11 , L_4 , V_20 , error ) ;
return error ;
}
static int F_23 ( struct V_10 * V_11 ,
void * V_12 )
{
struct V_29 * V_30 = V_12 ;
struct V_1 * V_28 = F_3 ( V_11 ) ;
if ( V_28 -> V_31 == V_30 )
return 1 ;
return 0 ;
}
static int F_24 ( struct V_29 * V_32 )
{
int error ;
error = F_10 ( V_23 , NULL , V_32 ,
F_23 ) ;
return error ? ( error == 1 ? 0 : error ) : - V_33 ;
}
static int F_25 ( struct V_1 * V_13 )
{
struct V_29 * V_30 ;
int V_34 = 0 ;
if ( V_13 -> V_5 && V_13 -> V_8 > 0 )
return 0 ;
if ( ! V_13 -> V_31 )
return 0 ;
do {
int V_35 ;
V_30 = F_19 ( V_13 -> V_31 , L_2 , V_34 ++ ) ;
if ( ! V_30 )
break;
V_35 = F_24 ( V_30 ) ;
F_21 ( V_30 ) ;
if ( V_35 ) {
F_6 ( V_13 -> V_11 , L_5 ) ;
return V_35 ;
}
} while ( V_30 );
if ( V_34 == 1 )
return 0 ;
V_13 -> V_5 = F_26 ( V_13 -> V_11 , sizeof( V_13 -> V_5 ) ,
V_36 ) ;
if ( ! V_13 -> V_5 ) {
F_27 ( V_13 -> V_11 , L_6 ) ;
return - V_37 ;
}
* V_13 -> V_5 = F_26 ( V_13 -> V_11 , sizeof( char * ) * ( V_34 - 1 ) ,
V_36 ) ;
if ( ! * V_13 -> V_5 ) {
F_27 ( V_13 -> V_11 , L_6 ) ;
return - V_37 ;
}
return F_22 ( V_13 ) ;
}
static inline int F_25 ( struct V_1 * V_13 )
{
return 0 ;
}
static int F_28 ( struct V_10 * V_11 , void * V_12 )
{
union V_38 V_35 = { 0 ,} ;
struct V_1 * V_13 = V_12 ;
struct V_1 * V_28 = F_3 ( V_11 ) ;
if ( F_1 ( V_28 , V_13 ) )
if ( ! V_28 -> V_39 ( V_28 , V_40 , & V_35 ) )
return V_35 . V_41 ;
return 0 ;
}
int F_29 ( struct V_1 * V_13 )
{
int error ;
error = F_10 ( V_23 , NULL , V_13 ,
F_28 ) ;
F_6 ( V_13 -> V_11 , L_4 , V_20 , error ) ;
return error ;
}
static int F_30 ( struct V_10 * V_11 , void * V_12 )
{
union V_38 V_35 = { 0 ,} ;
struct V_1 * V_13 = F_3 ( V_11 ) ;
unsigned int * V_42 = V_12 ;
( * V_42 ) ++ ;
if ( V_13 -> type != V_43 )
if ( ! V_13 -> V_39 ( V_13 , V_40 , & V_35 ) )
return V_35 . V_41 ;
return 0 ;
}
int F_31 ( void )
{
int error ;
unsigned int V_42 = 0 ;
error = F_10 ( V_23 , NULL , & V_42 ,
F_30 ) ;
if ( V_42 == 0 )
return 1 ;
return error ;
}
int F_32 ( struct V_1 * V_13 )
{
if ( V_13 -> type == V_43 && V_13 -> V_44 ) {
V_13 -> V_44 ( V_13 ) ;
return 0 ;
}
return - V_45 ;
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
static int F_36 ( struct V_10 * V_11 , const void * V_12 )
{
return V_11 -> V_46 && V_11 -> V_46 -> V_31 == V_12 ;
}
struct V_1 * F_37 ( struct V_29 * V_30 ,
const char * V_47 )
{
struct V_29 * V_48 ;
struct V_10 * V_11 ;
V_48 = F_19 ( V_30 , V_47 , 0 ) ;
if ( ! V_48 )
return F_38 ( - V_49 ) ;
V_11 = F_35 ( V_23 , NULL , V_48 ,
F_36 ) ;
F_21 ( V_48 ) ;
return V_11 ? F_3 ( V_11 ) : NULL ;
}
int F_39 ( struct V_1 * V_13 , struct V_10 * V_11 )
{
return F_40 ( & V_13 -> V_11 -> V_26 , & V_11 -> V_26 , L_7 ) ;
}
static void F_41 ( struct V_10 * V_11 )
{
F_42 ( L_8 , F_43 ( V_11 ) , V_20 ) ;
F_44 ( V_11 ) ;
}
int F_45 ( struct V_50 * V_51 )
{
return F_46 ( & V_24 , V_51 ) ;
}
void F_47 ( struct V_50 * V_51 )
{
F_48 ( & V_24 , V_51 ) ;
}
static int F_49 ( struct V_52 * V_53 ,
unsigned long * V_54 )
{
struct V_1 * V_13 ;
union V_38 V_55 ;
int V_35 ;
F_50 ( V_53 == NULL ) ;
V_13 = V_53 -> V_56 ;
V_35 = V_13 -> V_39 ( V_13 , V_57 , & V_55 ) ;
if ( ! V_35 )
* V_54 = V_55 . V_41 * 100 ;
return V_35 ;
}
static int F_51 ( struct V_1 * V_13 )
{
int V_4 ;
if ( V_13 -> V_58 )
return 0 ;
for ( V_4 = 0 ; V_4 < V_13 -> V_59 ; V_4 ++ ) {
if ( V_13 -> V_60 [ V_4 ] == V_57 ) {
V_13 -> V_53 = F_52 ( V_13 -> V_7 , 0 , 0 ,
V_13 , & V_61 , NULL , 0 , 0 ) ;
return F_53 ( V_13 -> V_53 ) ;
}
}
return 0 ;
}
static void F_54 ( struct V_1 * V_13 )
{
if ( F_55 ( V_13 -> V_53 ) )
return;
F_56 ( V_13 -> V_53 ) ;
}
static int F_57 ( struct V_62 * V_63 ,
unsigned long * V_64 )
{
struct V_1 * V_13 ;
union V_38 V_55 ;
int V_35 ;
V_13 = V_63 -> V_56 ;
V_35 = V_13 -> V_39 ( V_13 ,
V_65 , & V_55 ) ;
if ( ! V_35 )
* V_64 = V_55 . V_41 ;
return V_35 ;
}
static int F_58 ( struct V_62 * V_63 ,
unsigned long * V_64 )
{
struct V_1 * V_13 ;
union V_38 V_55 ;
int V_35 ;
V_13 = V_63 -> V_56 ;
V_35 = V_13 -> V_39 ( V_13 ,
V_66 , & V_55 ) ;
if ( ! V_35 )
* V_64 = V_55 . V_41 ;
return V_35 ;
}
static int F_59 ( struct V_62 * V_63 ,
unsigned long V_64 )
{
struct V_1 * V_13 ;
union V_38 V_55 ;
int V_35 ;
V_13 = V_63 -> V_56 ;
V_55 . V_41 = V_64 ;
V_35 = V_13 -> V_67 ( V_13 ,
V_66 , & V_55 ) ;
return V_35 ;
}
static int F_60 ( struct V_1 * V_13 )
{
int V_4 ;
for ( V_4 = 0 ; V_4 < V_13 -> V_59 ; V_4 ++ ) {
if ( V_13 -> V_60 [ V_4 ] ==
V_66 ) {
V_13 -> V_63 = F_61 (
( char * ) V_13 -> V_7 ,
V_13 , & V_68 ) ;
return F_53 ( V_13 -> V_63 ) ;
}
}
return 0 ;
}
static void F_62 ( struct V_1 * V_13 )
{
if ( F_55 ( V_13 -> V_63 ) )
return;
F_63 ( V_13 -> V_63 ) ;
}
static int F_51 ( struct V_1 * V_13 )
{
return 0 ;
}
static void F_54 ( struct V_1 * V_13 )
{
}
static int F_60 ( struct V_1 * V_13 )
{
return 0 ;
}
static void F_62 ( struct V_1 * V_13 )
{
}
static int F_64 ( struct V_10 * V_46 ,
struct V_1 * V_13 , bool V_69 )
{
struct V_10 * V_11 ;
int V_70 ;
V_11 = F_65 ( sizeof( * V_11 ) , V_36 ) ;
if ( ! V_11 )
return - V_37 ;
F_66 ( V_11 ) ;
V_11 -> V_71 = V_23 ;
V_11 -> type = & V_72 ;
V_11 -> V_46 = V_46 ;
V_11 -> V_73 = F_41 ;
F_67 ( V_11 , V_13 ) ;
V_13 -> V_11 = V_11 ;
V_70 = F_68 ( V_11 , L_9 , V_13 -> V_7 ) ;
if ( V_70 )
goto V_74;
F_69 ( & V_13 -> V_19 , F_4 ) ;
V_70 = F_25 ( V_13 ) ;
if ( V_70 ) {
F_20 ( V_11 , L_10 ) ;
goto V_75;
}
F_70 ( & V_13 -> V_21 ) ;
V_70 = F_71 ( V_11 , V_69 ) ;
if ( V_70 )
goto V_76;
V_70 = F_72 ( V_11 ) ;
if ( V_70 )
goto V_77;
V_70 = F_51 ( V_13 ) ;
if ( V_70 )
goto V_78;
V_70 = F_60 ( V_13 ) ;
if ( V_70 )
goto V_79;
V_70 = F_73 ( V_13 ) ;
if ( V_70 )
goto V_80;
F_15 ( V_13 ) ;
return 0 ;
V_80:
F_62 ( V_13 ) ;
V_79:
F_54 ( V_13 ) ;
V_78:
F_74 ( V_11 ) ;
V_77:
V_76:
V_75:
V_74:
F_75 ( V_11 ) ;
return V_70 ;
}
int F_76 ( struct V_10 * V_46 , struct V_1 * V_13 )
{
return F_64 ( V_46 , V_13 , true ) ;
}
int F_77 ( struct V_10 * V_46 , struct V_1 * V_13 )
{
return F_64 ( V_46 , V_13 , false ) ;
}
void F_78 ( struct V_1 * V_13 )
{
F_79 ( & V_13 -> V_19 ) ;
F_80 ( & V_13 -> V_11 -> V_26 , L_7 ) ;
F_81 ( V_13 ) ;
F_62 ( V_13 ) ;
F_54 ( V_13 ) ;
F_71 ( V_13 -> V_11 , false ) ;
F_82 ( V_13 -> V_11 ) ;
}
static int T_1 F_83 ( void )
{
V_23 = F_84 ( V_81 , L_11 ) ;
if ( F_85 ( V_23 ) )
return F_86 ( V_23 ) ;
V_23 -> V_82 = V_83 ;
F_87 ( & V_72 ) ;
return 0 ;
}
static void T_2 F_88 ( void )
{
F_89 ( V_23 ) ;
}
