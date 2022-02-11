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
F_11 ( & V_24 ,
V_25 , V_13 ) ;
F_12 ( & V_13 -> V_11 -> V_26 , V_27 ) ;
F_7 ( & V_13 -> V_21 , V_18 ) ;
}
if ( ! V_13 -> V_22 )
F_13 ( V_13 -> V_11 ) ;
F_8 ( & V_13 -> V_21 , V_18 ) ;
}
void F_14 ( struct V_1 * V_13 )
{
unsigned long V_18 ;
F_6 ( V_13 -> V_11 , L_1 , V_20 ) ;
F_7 ( & V_13 -> V_21 , V_18 ) ;
V_13 -> V_22 = true ;
F_15 ( V_13 -> V_11 ) ;
F_8 ( & V_13 -> V_21 , V_18 ) ;
F_16 ( & V_13 -> V_19 ) ;
}
static int F_17 ( struct V_10 * V_11 ,
void * V_12 )
{
struct V_1 * V_13 = (struct V_1 * ) V_12 ;
struct V_1 * V_28 = F_3 ( V_11 ) ;
struct V_29 * V_30 ;
int V_4 = 0 ;
do {
V_30 = F_18 ( V_13 -> V_31 , L_2 , V_4 ++ ) ;
if ( ! V_30 )
continue;
if ( V_30 == V_28 -> V_31 ) {
F_19 ( V_13 -> V_11 , L_3 ,
V_13 -> V_7 , V_28 -> V_7 ) ;
V_13 -> V_5 [ V_4 - 1 ] = ( char * ) V_28 -> V_7 ;
V_13 -> V_8 ++ ;
F_20 ( V_30 ) ;
break;
}
F_20 ( V_30 ) ;
} while ( V_30 );
return 0 ;
}
static int F_21 ( struct V_1 * V_13 )
{
int error ;
error = F_9 ( V_23 , NULL , V_13 ,
F_17 ) ;
F_6 ( V_13 -> V_11 , L_4 , V_20 , error ) ;
return error ;
}
static int F_22 ( struct V_10 * V_11 ,
void * V_12 )
{
struct V_29 * V_30 = (struct V_29 * ) V_12 ;
struct V_1 * V_28 = F_3 ( V_11 ) ;
if ( V_28 -> V_31 == V_30 )
return - V_32 ;
return 0 ;
}
static int F_23 ( struct V_29 * V_33 )
{
int error ;
struct V_10 * V_11 ;
struct V_34 V_35 ;
F_24 ( & V_35 , V_23 , NULL , NULL ) ;
V_11 = F_25 ( & V_35 ) ;
if ( ! V_11 )
return - V_36 ;
error = F_9 ( V_23 , NULL , V_33 ,
F_22 ) ;
return error ? 0 : - V_36 ;
}
static int F_26 ( struct V_1 * V_13 )
{
struct V_29 * V_30 ;
int V_37 = 0 ;
if ( V_13 -> V_5 && V_13 -> V_8 > 0 )
return 0 ;
if ( ! V_13 -> V_31 )
return 0 ;
do {
int V_38 ;
V_30 = F_18 ( V_13 -> V_31 , L_2 , V_37 ++ ) ;
if ( ! V_30 )
continue;
V_38 = F_23 ( V_30 ) ;
if ( V_38 ) {
F_6 ( V_13 -> V_11 , L_5 ) ;
F_20 ( V_30 ) ;
return - V_36 ;
}
F_20 ( V_30 ) ;
} while ( V_30 );
V_13 -> V_5 = F_27 ( V_13 -> V_11 , sizeof( V_13 -> V_5 ) ,
V_39 ) ;
if ( ! V_13 -> V_5 ) {
F_28 ( V_13 -> V_11 , L_6 ) ;
return - V_40 ;
}
* V_13 -> V_5 = F_27 ( V_13 -> V_11 , sizeof( char * ) * V_37 ,
V_39 ) ;
if ( ! * V_13 -> V_5 ) {
F_28 ( V_13 -> V_11 , L_6 ) ;
return - V_40 ;
}
return F_21 ( V_13 ) ;
}
static inline int F_26 ( struct V_1 * V_13 )
{
return 0 ;
}
static int F_29 ( struct V_10 * V_11 , void * V_12 )
{
union V_41 V_38 = { 0 ,} ;
struct V_1 * V_13 = (struct V_1 * ) V_12 ;
struct V_1 * V_28 = F_3 ( V_11 ) ;
if ( F_1 ( V_28 , V_13 ) )
if ( ! V_28 -> V_42 ( V_28 , V_43 , & V_38 ) ) {
if ( V_38 . V_44 )
return V_38 . V_44 ;
}
return 0 ;
}
int F_30 ( struct V_1 * V_13 )
{
int error ;
error = F_9 ( V_23 , NULL , V_13 ,
F_29 ) ;
F_6 ( V_13 -> V_11 , L_4 , V_20 , error ) ;
return error ;
}
static int F_31 ( struct V_10 * V_11 , void * V_12 )
{
union V_41 V_38 = { 0 ,} ;
struct V_1 * V_13 = F_3 ( V_11 ) ;
unsigned int * V_45 = V_12 ;
( * V_45 ) ++ ;
if ( V_13 -> type != V_46 ) {
if ( V_13 -> V_42 ( V_13 , V_43 , & V_38 ) )
return 0 ;
if ( V_38 . V_44 )
return V_38 . V_44 ;
}
return 0 ;
}
int F_32 ( void )
{
int error ;
unsigned int V_45 = 0 ;
error = F_9 ( V_23 , NULL , & V_45 ,
F_31 ) ;
if ( V_45 == 0 )
return 1 ;
return error ;
}
int F_33 ( struct V_1 * V_13 )
{
if ( V_13 -> type == V_46 && V_13 -> V_47 ) {
V_13 -> V_47 ( V_13 ) ;
return 0 ;
}
return - V_32 ;
}
static int F_34 ( struct V_10 * V_11 , const void * V_12 )
{
const char * V_7 = V_12 ;
struct V_1 * V_13 = F_3 ( V_11 ) ;
return strcmp ( V_13 -> V_7 , V_7 ) == 0 ;
}
struct V_1 * F_35 ( const char * V_7 )
{
struct V_10 * V_11 = F_36 ( V_23 , NULL , V_7 ,
F_34 ) ;
return V_11 ? F_3 ( V_11 ) : NULL ;
}
static int F_37 ( struct V_10 * V_11 , const void * V_12 )
{
return V_11 -> V_48 && V_11 -> V_48 -> V_31 == V_12 ;
}
struct V_1 * F_38 ( struct V_29 * V_30 ,
const char * V_49 )
{
struct V_29 * V_50 ;
struct V_10 * V_11 ;
V_50 = F_18 ( V_30 , V_49 , 0 ) ;
if ( ! V_50 )
return F_39 ( - V_51 ) ;
V_11 = F_36 ( V_23 , NULL , V_50 ,
F_37 ) ;
F_20 ( V_50 ) ;
return V_11 ? F_3 ( V_11 ) : NULL ;
}
int F_40 ( struct V_1 * V_13 , struct V_10 * V_11 )
{
return F_41 ( & V_13 -> V_11 -> V_26 , & V_11 -> V_26 , L_7 ) ;
}
static void F_42 ( struct V_10 * V_11 )
{
F_43 ( L_8 , F_44 ( V_11 ) , V_20 ) ;
F_45 ( V_11 ) ;
}
int F_46 ( struct V_52 * V_53 )
{
return F_47 ( & V_24 , V_53 ) ;
}
void F_48 ( struct V_52 * V_53 )
{
F_49 ( & V_24 , V_53 ) ;
}
static int F_50 ( struct V_54 * V_55 ,
unsigned long * V_56 )
{
struct V_1 * V_13 ;
union V_41 V_57 ;
int V_38 ;
F_51 ( V_55 == NULL ) ;
V_13 = V_55 -> V_58 ;
V_38 = V_13 -> V_42 ( V_13 , V_59 , & V_57 ) ;
if ( ! V_38 )
* V_56 = V_57 . V_44 * 100 ;
return V_38 ;
}
static int F_52 ( struct V_1 * V_13 )
{
int V_4 ;
for ( V_4 = 0 ; V_4 < V_13 -> V_60 ; V_4 ++ ) {
if ( V_13 -> V_61 [ V_4 ] == V_59 ) {
V_13 -> V_55 = F_53 ( V_13 -> V_7 , 0 , 0 ,
V_13 , & V_62 , NULL , 0 , 0 ) ;
if ( F_54 ( V_13 -> V_55 ) )
return F_55 ( V_13 -> V_55 ) ;
break;
}
}
return 0 ;
}
static void F_56 ( struct V_1 * V_13 )
{
if ( F_57 ( V_13 -> V_55 ) )
return;
F_58 ( V_13 -> V_55 ) ;
}
static int F_59 ( struct V_63 * V_64 ,
unsigned long * V_65 )
{
struct V_1 * V_13 ;
union V_41 V_57 ;
int V_38 ;
V_13 = V_64 -> V_58 ;
V_38 = V_13 -> V_42 ( V_13 ,
V_66 , & V_57 ) ;
if ( ! V_38 )
* V_65 = V_57 . V_44 ;
return V_38 ;
}
static int F_60 ( struct V_63 * V_64 ,
unsigned long * V_65 )
{
struct V_1 * V_13 ;
union V_41 V_57 ;
int V_38 ;
V_13 = V_64 -> V_58 ;
V_38 = V_13 -> V_42 ( V_13 ,
V_67 , & V_57 ) ;
if ( ! V_38 )
* V_65 = V_57 . V_44 ;
return V_38 ;
}
static int F_61 ( struct V_63 * V_64 ,
unsigned long V_65 )
{
struct V_1 * V_13 ;
union V_41 V_57 ;
int V_38 ;
V_13 = V_64 -> V_58 ;
V_57 . V_44 = V_65 ;
V_38 = V_13 -> V_68 ( V_13 ,
V_67 , & V_57 ) ;
return V_38 ;
}
static int F_62 ( struct V_1 * V_13 )
{
int V_4 ;
for ( V_4 = 0 ; V_4 < V_13 -> V_60 ; V_4 ++ ) {
if ( V_13 -> V_61 [ V_4 ] ==
V_67 ) {
V_13 -> V_64 = F_63 (
( char * ) V_13 -> V_7 ,
V_13 , & V_69 ) ;
if ( F_54 ( V_13 -> V_64 ) )
return F_55 ( V_13 -> V_64 ) ;
break;
}
}
return 0 ;
}
static void F_64 ( struct V_1 * V_13 )
{
if ( F_57 ( V_13 -> V_64 ) )
return;
F_65 ( V_13 -> V_64 ) ;
}
static int F_52 ( struct V_1 * V_13 )
{
return 0 ;
}
static void F_56 ( struct V_1 * V_13 )
{
}
static int F_62 ( struct V_1 * V_13 )
{
return 0 ;
}
static void F_64 ( struct V_1 * V_13 )
{
}
static int F_66 ( struct V_10 * V_48 ,
struct V_1 * V_13 , bool V_70 )
{
struct V_10 * V_11 ;
int V_71 ;
V_11 = F_67 ( sizeof( * V_11 ) , V_39 ) ;
if ( ! V_11 )
return - V_40 ;
F_68 ( V_11 ) ;
V_11 -> V_72 = V_23 ;
V_11 -> type = & V_73 ;
V_11 -> V_48 = V_48 ;
V_11 -> V_74 = F_42 ;
F_69 ( V_11 , V_13 ) ;
V_13 -> V_11 = V_11 ;
V_71 = F_70 ( V_11 , L_9 , V_13 -> V_7 ) ;
if ( V_71 )
goto V_75;
F_71 ( & V_13 -> V_19 , F_4 ) ;
V_71 = F_26 ( V_13 ) ;
if ( V_71 ) {
F_19 ( V_11 , L_10 ) ;
goto V_76;
}
F_72 ( & V_13 -> V_21 ) ;
V_71 = F_73 ( V_11 , V_70 ) ;
if ( V_71 )
goto V_77;
V_71 = F_74 ( V_11 ) ;
if ( V_71 )
goto V_78;
V_71 = F_52 ( V_13 ) ;
if ( V_71 )
goto V_79;
V_71 = F_62 ( V_13 ) ;
if ( V_71 )
goto V_80;
V_71 = F_75 ( V_13 ) ;
if ( V_71 )
goto V_81;
F_14 ( V_13 ) ;
goto V_82;
V_81:
F_64 ( V_13 ) ;
V_80:
F_56 ( V_13 ) ;
V_79:
F_76 ( V_11 ) ;
V_78:
V_77:
V_76:
V_75:
F_77 ( V_11 ) ;
V_82:
return V_71 ;
}
int F_78 ( struct V_10 * V_48 , struct V_1 * V_13 )
{
return F_66 ( V_48 , V_13 , true ) ;
}
int F_79 ( struct V_10 * V_48 , struct V_1 * V_13 )
{
return F_66 ( V_48 , V_13 , false ) ;
}
void F_80 ( struct V_1 * V_13 )
{
F_81 ( & V_13 -> V_19 ) ;
F_82 ( & V_13 -> V_11 -> V_26 , L_7 ) ;
F_83 ( V_13 ) ;
F_64 ( V_13 ) ;
F_56 ( V_13 ) ;
F_73 ( V_13 -> V_11 , false ) ;
F_84 ( V_13 -> V_11 ) ;
}
static int T_1 F_85 ( void )
{
V_23 = F_86 ( V_83 , L_11 ) ;
if ( F_54 ( V_23 ) )
return F_55 ( V_23 ) ;
V_23 -> V_84 = V_85 ;
F_87 ( & V_73 ) ;
return 0 ;
}
static void T_2 F_88 ( void )
{
F_89 ( V_23 ) ;
}
