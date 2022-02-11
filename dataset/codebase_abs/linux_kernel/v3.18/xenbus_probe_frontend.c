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
if ( ! V_29 ) {
F_18 ( L_9 ,
V_25 -> V_3 ) ;
return - V_30 ;
}
F_19 ( V_29 , & V_25 -> V_26 ) ;
return 0 ;
}
return F_16 ( V_17 ) ;
}
static int F_20 ( struct V_12 * V_17 )
{
if ( V_27 == V_28 ) {
struct V_16 * V_25 = F_10 ( V_17 ) ;
F_21 ( & V_25 -> V_26 , F_14 ) ;
}
return F_22 ( V_17 ) ;
}
static void F_23 ( struct V_19 * V_20 ,
const char * * V_21 , unsigned int V_22 )
{
F_5 ( L_10 ) ;
F_24 ( V_21 [ V_31 ] , & V_32 ) ;
}
static int F_25 ( struct V_16 * V_33 )
{
return F_26 ( V_33 , L_11 , L_12 ) ;
}
static int F_27 ( struct V_12 * V_17 , void * V_34 , bool V_35 )
{
struct V_16 * V_33 = F_10 ( V_17 ) ;
struct V_36 * V_37 = V_34 ;
struct V_38 * V_39 ;
if ( ! V_17 -> V_40 )
return 0 ;
if ( V_37 && ( V_17 -> V_40 != V_37 ) )
return 0 ;
if ( V_35 ) {
if ( ( strncmp ( V_33 -> V_3 , L_13 , 11 ) == 0 ) )
return 0 ;
if ( ( strncmp ( V_33 -> V_3 , L_14 , 10 ) == 0 ) )
return 0 ;
}
V_39 = F_28 ( V_17 -> V_40 ) ;
return ( V_33 -> V_41 < V_42 ||
( V_33 -> V_41 == V_42 &&
V_39 -> V_43 && ! V_39 -> V_43 ( V_33 ) ) ) ;
}
static int F_29 ( struct V_12 * V_17 , void * V_34 )
{
return F_27 ( V_17 , V_34 , true ) ;
}
static int F_30 ( struct V_12 * V_17 , void * V_34 )
{
return F_27 ( V_17 , V_34 , false ) ;
}
static int F_31 ( struct V_36 * V_37 )
{
return F_32 ( & V_32 . V_6 , NULL , V_37 ,
F_29 ) ;
}
static int F_33 ( struct V_36 * V_37 )
{
return F_32 ( & V_32 . V_6 , NULL , V_37 ,
F_30 ) ;
}
static int F_34 ( struct V_12 * V_17 , void * V_34 )
{
struct V_16 * V_33 = F_10 ( V_17 ) ;
struct V_36 * V_37 = V_34 ;
if ( V_37 && ( V_17 -> V_40 != V_37 ) )
return 0 ;
if ( ! V_17 -> V_40 ) {
F_35 ( L_15 , V_33 -> V_3 ) ;
} else if ( V_33 -> V_41 < V_42 ) {
enum V_44 V_45 = V_46 ;
if ( V_33 -> V_47 )
V_45 = F_36 ( V_33 -> V_47 ) ;
F_2 ( L_16 ,
V_33 -> V_3 , V_33 -> V_41 , V_45 ) ;
}
return 0 ;
}
static bool F_37 ( unsigned long V_48 , unsigned int V_49 ,
unsigned int * V_50 )
{
if ( F_38 ( V_51 , V_48 + ( * V_50 + 5 ) * V_52 ) ) {
if ( ! * V_50 )
F_2 ( L_17 ) ;
* V_50 += 5 ;
F_39 ( L_18 , V_49 - * V_50 ) ;
if ( * V_50 == V_49 ) {
F_39 ( L_19 ) ;
return true ;
}
}
F_40 ( V_52 / 10 ) ;
return false ;
}
static void F_41 ( struct V_38 * V_39 )
{
unsigned long V_48 = V_51 ;
struct V_36 * V_37 = V_39 ? & V_39 -> V_40 : NULL ;
unsigned int V_50 = 0 ;
if ( ! V_53 || ! F_42 () )
return;
while ( F_33 ( V_37 ) )
if ( F_37 ( V_48 , 30 , & V_50 ) )
break;
while ( F_31 ( V_37 ) )
if ( F_37 ( V_48 , 270 , & V_50 ) )
break;
if ( V_50 )
F_43 ( L_19 ) ;
F_32 ( & V_32 . V_6 , NULL , V_37 ,
F_34 ) ;
}
int F_44 ( struct V_38 * V_37 , struct V_54 * V_55 ,
const char * V_56 )
{
int V_57 ;
V_37 -> V_58 = F_25 ;
V_57 = F_45 ( V_37 , & V_32 ,
V_55 , V_56 ) ;
if ( V_57 )
return V_57 ;
F_41 ( V_37 ) ;
return 0 ;
}
static void F_46 ( struct V_19 * V_24 ,
const char * * V_59 , unsigned int V_60 )
{
F_47 ( V_61 , V_59 [ V_31 ] , L_10 , L_20 , & V_62 ) ;
F_43 ( V_63 L_21 ,
V_59 [ V_31 ] , F_48 ( V_62 ) ) ;
F_49 ( & V_64 ) ;
}
static void F_50 ( char * V_65 , int V_66 )
{
long V_67 ;
V_67 = F_51 ( V_64 ,
V_62 == V_66 , 5 * V_52 ) ;
if ( V_67 <= 0 )
F_35 ( L_22 , V_65 ) ;
}
static void F_52 ( char * V_68 , char * V_65 , int V_69 )
{
struct V_19 V_70 ;
F_43 ( V_63 L_21 ,
V_65 , F_48 ( V_69 ) ) ;
memset ( & V_70 , 0 , sizeof( V_70 ) ) ;
V_70 . V_71 = F_6 ( V_72 | V_73 , L_23 , V_65 ) ;
if ( ! V_70 . V_71 )
return;
V_70 . V_74 = F_46 ;
V_62 = V_46 ;
F_35 ( L_24 , V_65 ) ;
F_53 ( & V_70 ) ;
switch ( V_69 ) {
case V_42 :
F_54 ( V_61 , V_68 , L_25 , L_26 , V_75 ) ;
F_50 ( V_65 , V_75 ) ;
case V_75 :
F_54 ( V_61 , V_68 , L_25 , L_26 , V_76 ) ;
F_50 ( V_65 , V_76 ) ;
case V_76 :
F_54 ( V_61 , V_68 , L_25 , L_26 , V_77 ) ;
F_50 ( V_65 , V_78 ) ;
}
F_55 ( & V_70 ) ;
F_35 ( L_27 , V_65 ) ;
F_8 ( V_70 . V_71 ) ;
}
static void F_56 ( char * V_79 , char * V_17 )
{
int V_69 , V_80 , V_8 ;
char * V_81 , * V_82 ;
V_82 = F_6 ( V_72 | V_73 , L_28 , V_79 , V_17 ) ;
if ( ! V_82 )
return;
V_8 = F_47 ( V_61 , V_82 , L_25 , L_20 , & V_80 ) ;
if ( V_8 != 1 )
goto V_83;
switch ( V_80 ) {
case V_42 :
case V_76 :
F_43 ( V_63 L_29 ,
V_82 , F_48 ( V_80 ) ) ;
V_81 = F_57 ( V_61 , V_82 , L_12 , NULL ) ;
if ( ! V_81 || F_58 ( V_81 ) )
goto V_83;
V_8 = F_47 ( V_61 , V_81 , L_25 , L_20 , & V_69 ) ;
if ( V_8 == 1 )
F_52 ( V_82 , V_81 , V_69 ) ;
F_8 ( V_81 ) ;
break;
default:
break;
}
V_83:
F_8 ( V_82 ) ;
}
static void F_59 ( void )
{
char * * V_84 , * * V_17 ;
int V_85 , V_86 ;
int V_87 , V_88 ;
V_84 = F_60 ( V_61 , L_30 , L_10 , & V_85 ) ;
if ( F_58 ( V_84 ) )
return;
for ( V_87 = 0 ; V_87 < V_85 ; V_87 ++ ) {
V_17 = F_60 ( V_61 , L_30 , V_84 [ V_87 ] , & V_86 ) ;
if ( F_58 ( V_17 ) )
continue;
for ( V_88 = 0 ; V_88 < V_86 ; V_88 ++ )
F_56 ( V_84 [ V_87 ] , V_17 [ V_88 ] ) ;
F_8 ( V_17 ) ;
}
F_8 ( V_84 ) ;
}
static int F_61 ( struct V_89 * V_90 ,
unsigned long V_91 ,
void * V_34 )
{
if ( F_62 () )
F_59 () ;
F_63 ( & V_32 ) ;
F_53 ( & V_92 ) ;
return V_93 ;
}
static int T_1 F_64 ( void )
{
static struct V_89 V_94 = {
. V_95 = F_61
} ;
int V_8 ;
F_5 ( L_10 ) ;
V_8 = F_65 ( & V_32 . V_6 ) ;
if ( V_8 )
return V_8 ;
F_66 ( & V_94 ) ;
if ( V_27 == V_28 ) {
V_29 = F_67 ( L_31 ) ;
if ( ! V_29 )
F_2 ( L_32 ) ;
}
return 0 ;
}
static int T_1 F_68 ( void )
{
if ( ! F_69 () )
return - V_96 ;
V_53 = 1 ;
F_41 ( NULL ) ;
return 0 ;
}
