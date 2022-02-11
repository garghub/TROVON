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
const char * * V_21 , unsigned int V_22 )
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
const char * * V_21 , unsigned int V_22 )
{
F_5 ( L_9 ) ;
F_23 ( V_21 [ V_29 ] , & V_30 ) ;
}
static int F_24 ( struct V_16 * V_31 )
{
return F_25 ( V_31 , L_10 , L_11 ) ;
}
static int F_26 ( struct V_12 * V_17 , void * V_32 , bool V_33 )
{
struct V_16 * V_31 = F_10 ( V_17 ) ;
struct V_34 * V_35 = V_32 ;
struct V_36 * V_37 ;
if ( ! V_17 -> V_38 )
return 0 ;
if ( V_35 && ( V_17 -> V_38 != V_35 ) )
return 0 ;
if ( V_33 ) {
if ( ( strncmp ( V_31 -> V_3 , L_12 , 11 ) == 0 ) )
return 0 ;
if ( ( strncmp ( V_31 -> V_3 , L_13 , 10 ) == 0 ) )
return 0 ;
}
V_37 = F_27 ( V_17 -> V_38 ) ;
return ( V_31 -> V_39 < V_40 ||
( V_31 -> V_39 == V_40 &&
V_37 -> V_41 && ! V_37 -> V_41 ( V_31 ) ) ) ;
}
static int F_28 ( struct V_12 * V_17 , void * V_32 )
{
return F_26 ( V_17 , V_32 , true ) ;
}
static int F_29 ( struct V_12 * V_17 , void * V_32 )
{
return F_26 ( V_17 , V_32 , false ) ;
}
static int F_30 ( struct V_34 * V_35 )
{
return F_31 ( & V_30 . V_6 , NULL , V_35 ,
F_28 ) ;
}
static int F_32 ( struct V_34 * V_35 )
{
return F_31 ( & V_30 . V_6 , NULL , V_35 ,
F_29 ) ;
}
static int F_33 ( struct V_12 * V_17 , void * V_32 )
{
struct V_16 * V_31 = F_10 ( V_17 ) ;
struct V_34 * V_35 = V_32 ;
if ( V_35 && ( V_17 -> V_38 != V_35 ) )
return 0 ;
if ( ! V_17 -> V_38 ) {
F_34 ( L_14 , V_31 -> V_3 ) ;
} else if ( V_31 -> V_39 < V_40 ) {
enum V_42 V_43 = V_44 ;
if ( V_31 -> V_45 )
V_43 = F_35 ( V_31 -> V_45 ) ;
F_2 ( L_15 ,
V_31 -> V_3 , V_31 -> V_39 , V_43 ) ;
}
return 0 ;
}
static bool F_36 ( unsigned long V_46 , unsigned int V_47 ,
unsigned int * V_48 )
{
if ( F_37 ( V_49 , V_46 + ( * V_48 + 5 ) * V_50 ) ) {
if ( ! * V_48 )
F_2 ( L_16 ) ;
* V_48 += 5 ;
F_38 ( L_17 , V_47 - * V_48 ) ;
if ( * V_48 == V_47 ) {
F_38 ( L_18 ) ;
return true ;
}
}
F_39 ( V_50 / 10 ) ;
return false ;
}
static void F_40 ( struct V_36 * V_37 )
{
unsigned long V_46 = V_49 ;
struct V_34 * V_35 = V_37 ? & V_37 -> V_38 : NULL ;
unsigned int V_48 = 0 ;
if ( ! V_51 || ! F_41 () )
return;
while ( F_32 ( V_35 ) )
if ( F_36 ( V_46 , 30 , & V_48 ) )
break;
while ( F_30 ( V_35 ) )
if ( F_36 ( V_46 , 270 , & V_48 ) )
break;
if ( V_48 )
F_42 ( L_18 ) ;
F_31 ( & V_30 . V_6 , NULL , V_35 ,
F_33 ) ;
}
int F_43 ( struct V_36 * V_35 , struct V_52 * V_53 ,
const char * V_54 )
{
int V_55 ;
V_35 -> V_56 = F_24 ;
V_55 = F_44 ( V_35 , & V_30 ,
V_53 , V_54 ) ;
if ( V_55 )
return V_55 ;
F_40 ( V_35 ) ;
return 0 ;
}
static void F_45 ( struct V_19 * V_24 ,
const char * * V_57 , unsigned int V_58 )
{
if ( F_46 ( V_59 , V_57 [ V_29 ] , L_9 , L_19 ,
& V_60 ) != 1 )
V_60 = V_44 ;
F_42 ( V_61 L_20 ,
V_57 [ V_29 ] , F_47 ( V_60 ) ) ;
F_48 ( & V_62 ) ;
}
static void F_49 ( char * V_63 , int V_64 )
{
long V_65 ;
V_65 = F_50 ( V_62 ,
V_60 == V_64 , 5 * V_50 ) ;
if ( V_65 <= 0 )
F_34 ( L_21 , V_63 ) ;
}
static void F_51 ( char * V_66 , char * V_63 , int V_67 )
{
struct V_19 V_68 ;
F_42 ( V_61 L_20 ,
V_63 , F_47 ( V_67 ) ) ;
memset ( & V_68 , 0 , sizeof( V_68 ) ) ;
V_68 . V_69 = F_6 ( V_70 | V_71 , L_22 , V_63 ) ;
if ( ! V_68 . V_69 )
return;
V_68 . V_72 = F_45 ;
V_60 = V_44 ;
F_34 ( L_23 , V_63 ) ;
F_52 ( & V_68 ) ;
switch ( V_67 ) {
case V_40 :
F_53 ( V_59 , V_66 , L_24 , L_25 , V_73 ) ;
F_49 ( V_63 , V_73 ) ;
case V_73 :
F_53 ( V_59 , V_66 , L_24 , L_25 , V_74 ) ;
F_49 ( V_63 , V_74 ) ;
case V_74 :
F_53 ( V_59 , V_66 , L_24 , L_25 , V_75 ) ;
F_49 ( V_63 , V_76 ) ;
}
F_54 ( & V_68 ) ;
F_34 ( L_26 , V_63 ) ;
F_8 ( V_68 . V_69 ) ;
}
static void F_55 ( char * V_77 , char * V_17 )
{
int V_67 , V_78 , V_8 ;
char * V_79 , * V_80 ;
V_80 = F_6 ( V_70 | V_71 , L_27 , V_77 , V_17 ) ;
if ( ! V_80 )
return;
V_8 = F_46 ( V_59 , V_80 , L_24 , L_19 , & V_78 ) ;
if ( V_8 != 1 )
goto V_81;
switch ( V_78 ) {
case V_40 :
case V_74 :
F_42 ( V_61 L_28 ,
V_80 , F_47 ( V_78 ) ) ;
V_79 = F_56 ( V_59 , V_80 , L_11 , NULL ) ;
if ( ! V_79 || F_57 ( V_79 ) )
goto V_81;
V_8 = F_46 ( V_59 , V_79 , L_24 , L_19 , & V_67 ) ;
if ( V_8 == 1 )
F_51 ( V_80 , V_79 , V_67 ) ;
F_8 ( V_79 ) ;
break;
default:
break;
}
V_81:
F_8 ( V_80 ) ;
}
static void F_58 ( void )
{
char * * V_82 , * * V_17 ;
int V_83 , V_84 ;
int V_85 , V_86 ;
V_82 = F_59 ( V_59 , L_29 , L_9 , & V_83 ) ;
if ( F_57 ( V_82 ) )
return;
for ( V_85 = 0 ; V_85 < V_83 ; V_85 ++ ) {
V_17 = F_59 ( V_59 , L_29 , V_82 [ V_85 ] , & V_84 ) ;
if ( F_57 ( V_17 ) )
continue;
for ( V_86 = 0 ; V_86 < V_84 ; V_86 ++ )
F_55 ( V_82 [ V_85 ] , V_17 [ V_86 ] ) ;
F_8 ( V_17 ) ;
}
F_8 ( V_82 ) ;
}
static int F_60 ( struct V_87 * V_88 ,
unsigned long V_89 ,
void * V_32 )
{
if ( F_61 () )
F_58 () ;
F_62 ( & V_30 ) ;
F_52 ( & V_90 ) ;
return V_91 ;
}
static int T_1 F_63 ( void )
{
static struct V_87 V_92 = {
. V_93 = F_60
} ;
int V_8 ;
F_5 ( L_9 ) ;
V_8 = F_64 ( & V_30 . V_6 ) ;
if ( V_8 )
return V_8 ;
F_65 ( & V_92 ) ;
return 0 ;
}
static int T_1 F_66 ( void )
{
if ( ! F_67 () )
return - V_94 ;
V_51 = 1 ;
F_40 ( NULL ) ;
return 0 ;
}
