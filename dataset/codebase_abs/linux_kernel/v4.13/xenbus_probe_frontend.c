static int F_1 ( char V_1 [ V_2 ] , const char * V_3 )
{
V_3 = strchr ( V_3 , '/' ) ;
if ( ! V_3 || strlen ( V_3 + 1 ) >= V_2 ) {
F_2 ( L_1 , V_3 ) ;
return - V_4 ;
}
F_3 ( V_1 , V_3 + 1 , V_2 ) ;
if ( ! strchr ( V_1 , '/' ) ) {
F_2 ( L_2 , V_1 ) ;
return - V_4 ;
}
* strchr ( V_1 , '/' ) = '-' ;
return 0 ;
}
static int F_4 ( struct V_5 * V_6 , const char * type ,
const char * V_7 )
{
char * V_3 ;
int V_8 ;
if ( ! strncmp ( type , L_3 , 7 ) && ! strncmp ( V_7 , L_4 , 1 ) ) {
F_5 ( L_5 ) ;
return 0 ;
}
V_3 = F_6 ( V_9 , L_6 , V_6 -> V_10 , type , V_7 ) ;
if ( ! V_3 )
return - V_11 ;
F_5 ( L_7 , V_3 ) ;
V_8 = F_7 ( V_6 , type , V_3 ) ;
F_8 ( V_3 ) ;
return V_8 ;
}
static int F_9 ( struct V_12 * V_13 ,
struct V_14 * V_15 )
{
struct V_16 * V_17 = F_10 ( V_13 ) ;
if ( F_11 ( V_15 , L_8 , V_17 -> V_18 ) )
return - V_11 ;
return 0 ;
}
static void F_12 ( struct V_19 * V_20 ,
const char * V_21 , const char * V_22 )
{
F_13 ( V_20 , V_21 , V_22 , 1 ) ;
}
static void F_14 ( struct V_23 * V_24 )
{
struct V_16 * V_25 = F_15 ( V_24 , struct V_16 , V_26 ) ;
F_16 ( & V_25 -> V_17 ) ;
}
static int F_17 ( struct V_12 * V_17 )
{
if ( V_27 == V_28 ) {
struct V_16 * V_25 = F_10 ( V_17 ) ;
F_18 ( & V_25 -> V_26 ) ;
return 0 ;
}
return F_16 ( V_17 ) ;
}
static int F_19 ( struct V_12 * V_17 )
{
if ( V_27 == V_28 ) {
struct V_16 * V_25 = F_10 ( V_17 ) ;
F_20 ( & V_25 -> V_26 , F_14 ) ;
}
return F_21 ( V_17 ) ;
}
static void F_22 ( struct V_19 * V_20 ,
const char * V_21 , const char * V_22 )
{
F_5 ( L_9 ) ;
F_23 ( V_21 , & V_29 ) ;
}
static int F_24 ( struct V_16 * V_30 )
{
return F_25 ( V_30 , L_10 , L_11 ) ;
}
static int F_26 ( struct V_12 * V_17 , void * V_31 , bool V_32 )
{
struct V_16 * V_30 = F_10 ( V_17 ) ;
struct V_33 * V_34 = V_31 ;
struct V_35 * V_36 ;
if ( ! V_17 -> V_37 )
return 0 ;
if ( V_34 && ( V_17 -> V_37 != V_34 ) )
return 0 ;
if ( V_32 ) {
if ( ( strncmp ( V_30 -> V_3 , L_12 , 11 ) == 0 ) )
return 0 ;
if ( ( strncmp ( V_30 -> V_3 , L_13 , 10 ) == 0 ) )
return 0 ;
}
V_36 = F_27 ( V_17 -> V_37 ) ;
return ( V_30 -> V_38 < V_39 ||
( V_30 -> V_38 == V_39 &&
V_36 -> V_40 && ! V_36 -> V_40 ( V_30 ) ) ) ;
}
static int F_28 ( struct V_12 * V_17 , void * V_31 )
{
return F_26 ( V_17 , V_31 , true ) ;
}
static int F_29 ( struct V_12 * V_17 , void * V_31 )
{
return F_26 ( V_17 , V_31 , false ) ;
}
static int F_30 ( struct V_33 * V_34 )
{
return F_31 ( & V_29 . V_6 , NULL , V_34 ,
F_28 ) ;
}
static int F_32 ( struct V_33 * V_34 )
{
return F_31 ( & V_29 . V_6 , NULL , V_34 ,
F_29 ) ;
}
static int F_33 ( struct V_12 * V_17 , void * V_31 )
{
struct V_16 * V_30 = F_10 ( V_17 ) ;
struct V_33 * V_34 = V_31 ;
if ( V_34 && ( V_17 -> V_37 != V_34 ) )
return 0 ;
if ( ! V_17 -> V_37 ) {
F_34 ( L_14 , V_30 -> V_3 ) ;
} else if ( V_30 -> V_38 < V_39 ) {
enum V_41 V_42 = V_43 ;
if ( V_30 -> V_44 )
V_42 = F_35 ( V_30 -> V_44 ) ;
F_2 ( L_15 ,
V_30 -> V_3 , V_30 -> V_38 , V_42 ) ;
}
return 0 ;
}
static bool F_36 ( unsigned long V_45 , unsigned int V_46 ,
unsigned int * V_47 )
{
if ( F_37 ( V_48 , V_45 + ( * V_47 + 5 ) * V_49 ) ) {
if ( ! * V_47 )
F_2 ( L_16 ) ;
* V_47 += 5 ;
F_38 ( L_17 , V_46 - * V_47 ) ;
if ( * V_47 == V_46 ) {
F_38 ( L_18 ) ;
return true ;
}
}
F_39 ( V_49 / 10 ) ;
return false ;
}
static void F_40 ( struct V_35 * V_36 )
{
unsigned long V_45 = V_48 ;
struct V_33 * V_34 = V_36 ? & V_36 -> V_37 : NULL ;
unsigned int V_47 = 0 ;
if ( ! V_50 || ! F_41 () )
return;
while ( F_32 ( V_34 ) )
if ( F_36 ( V_45 , 30 , & V_47 ) )
break;
while ( F_30 ( V_34 ) )
if ( F_36 ( V_45 , 270 , & V_47 ) )
break;
if ( V_47 )
F_42 ( L_18 ) ;
F_31 ( & V_29 . V_6 , NULL , V_34 ,
F_33 ) ;
}
int F_43 ( struct V_35 * V_34 , struct V_51 * V_52 ,
const char * V_53 )
{
int V_54 ;
V_34 -> V_55 = F_24 ;
V_54 = F_44 ( V_34 , & V_29 ,
V_52 , V_53 ) ;
if ( V_54 )
return V_54 ;
F_40 ( V_34 ) ;
return 0 ;
}
static void F_45 ( struct V_19 * V_24 ,
const char * V_21 , const char * V_22 )
{
if ( F_46 ( V_56 , V_21 , L_9 , L_19 ,
& V_57 ) != 1 )
V_57 = V_43 ;
F_42 ( V_58 L_20 ,
V_21 , F_47 ( V_57 ) ) ;
F_48 ( & V_59 ) ;
}
static void F_49 ( char * V_60 , int V_61 )
{
long V_62 ;
V_62 = F_50 ( V_59 ,
V_57 == V_61 , 5 * V_49 ) ;
if ( V_62 <= 0 )
F_34 ( L_21 , V_60 ) ;
}
static void F_51 ( char * V_63 , char * V_60 , int V_64 )
{
struct V_19 V_65 ;
F_42 ( V_58 L_20 ,
V_60 , F_47 ( V_64 ) ) ;
memset ( & V_65 , 0 , sizeof( V_65 ) ) ;
V_65 . V_66 = F_6 ( V_67 | V_68 , L_22 , V_60 ) ;
if ( ! V_65 . V_66 )
return;
V_65 . V_69 = F_45 ;
V_57 = V_43 ;
F_34 ( L_23 , V_60 ) ;
F_52 ( & V_65 ) ;
switch ( V_64 ) {
case V_39 :
F_53 ( V_56 , V_63 , L_24 , L_25 , V_70 ) ;
F_49 ( V_60 , V_70 ) ;
case V_70 :
F_53 ( V_56 , V_63 , L_24 , L_25 , V_71 ) ;
F_49 ( V_60 , V_71 ) ;
case V_71 :
F_53 ( V_56 , V_63 , L_24 , L_25 , V_72 ) ;
F_49 ( V_60 , V_73 ) ;
}
F_54 ( & V_65 ) ;
F_34 ( L_26 , V_60 ) ;
F_8 ( V_65 . V_66 ) ;
}
static void F_55 ( char * V_74 , char * V_17 )
{
int V_64 , V_75 , V_8 ;
char * V_76 , * V_77 ;
V_77 = F_6 ( V_67 | V_68 , L_27 , V_74 , V_17 ) ;
if ( ! V_77 )
return;
V_8 = F_46 ( V_56 , V_77 , L_24 , L_19 , & V_75 ) ;
if ( V_8 != 1 )
goto V_78;
switch ( V_75 ) {
case V_39 :
case V_71 :
F_42 ( V_58 L_28 ,
V_77 , F_47 ( V_75 ) ) ;
V_76 = F_56 ( V_56 , V_77 , L_11 , NULL ) ;
if ( ! V_76 || F_57 ( V_76 ) )
goto V_78;
V_8 = F_46 ( V_56 , V_76 , L_24 , L_19 , & V_64 ) ;
if ( V_8 == 1 )
F_51 ( V_77 , V_76 , V_64 ) ;
F_8 ( V_76 ) ;
break;
default:
break;
}
V_78:
F_8 ( V_77 ) ;
}
static void F_58 ( void )
{
char * * V_79 , * * V_17 ;
int V_80 , V_81 ;
int V_82 , V_83 ;
V_79 = F_59 ( V_56 , L_29 , L_9 , & V_80 ) ;
if ( F_57 ( V_79 ) )
return;
for ( V_82 = 0 ; V_82 < V_80 ; V_82 ++ ) {
V_17 = F_59 ( V_56 , L_29 , V_79 [ V_82 ] , & V_81 ) ;
if ( F_57 ( V_17 ) )
continue;
for ( V_83 = 0 ; V_83 < V_81 ; V_83 ++ )
F_55 ( V_79 [ V_82 ] , V_17 [ V_83 ] ) ;
F_8 ( V_17 ) ;
}
F_8 ( V_79 ) ;
}
static int F_60 ( struct V_84 * V_85 ,
unsigned long V_86 ,
void * V_31 )
{
if ( F_61 () )
F_58 () ;
F_62 ( & V_29 ) ;
F_52 ( & V_87 ) ;
return V_88 ;
}
static int T_1 F_63 ( void )
{
static struct V_84 V_89 = {
. V_90 = F_60
} ;
int V_8 ;
F_5 ( L_9 ) ;
V_8 = F_64 ( & V_29 . V_6 ) ;
if ( V_8 )
return V_8 ;
F_65 ( & V_89 ) ;
return 0 ;
}
static int T_1 F_66 ( void )
{
if ( ! F_67 () )
return - V_91 ;
V_50 = 1 ;
F_40 ( NULL ) ;
return 0 ;
}
