static int F_1 ( char V_1 [ V_2 ] , const char * V_3 )
{
V_3 = strchr ( V_3 , '/' ) ;
if ( ! V_3 || strlen ( V_3 + 1 ) >= V_2 ) {
F_2 ( V_4 L_1 , V_3 ) ;
return - V_5 ;
}
F_3 ( V_1 , V_3 + 1 , V_2 ) ;
if ( ! strchr ( V_1 , '/' ) ) {
F_2 ( V_4 L_2 , V_1 ) ;
return - V_5 ;
}
* strchr ( V_1 , '/' ) = '-' ;
return 0 ;
}
static int F_4 ( struct V_6 * V_7 , const char * type ,
const char * V_8 )
{
char * V_3 ;
int V_9 ;
if ( ! strncmp ( type , L_3 , 7 ) && ! strncmp ( V_8 , L_4 , 1 ) ) {
F_5 ( L_5 ) ;
return 0 ;
}
V_3 = F_6 ( V_10 , L_6 , V_7 -> V_11 , type , V_8 ) ;
if ( ! V_3 )
return - V_12 ;
F_5 ( L_7 , V_3 ) ;
V_9 = F_7 ( V_7 , type , V_3 ) ;
F_8 ( V_3 ) ;
return V_9 ;
}
static int F_9 ( struct V_13 * V_14 ,
struct V_15 * V_16 )
{
struct V_17 * V_18 = F_10 ( V_14 ) ;
if ( F_11 ( V_16 , L_8 , V_18 -> V_19 ) )
return - V_12 ;
return 0 ;
}
static void F_12 ( struct V_20 * V_21 ,
const char * * V_22 , unsigned int V_23 )
{
F_13 ( V_21 , V_22 , V_23 , 1 ) ;
}
static void F_14 ( struct V_20 * V_21 ,
const char * * V_22 , unsigned int V_23 )
{
F_5 ( L_9 ) ;
F_15 ( V_22 [ V_24 ] , & V_25 ) ;
}
static int F_16 ( struct V_17 * V_26 )
{
return F_17 ( V_26 , L_10 , L_11 ) ;
}
static int F_18 ( struct V_13 * V_18 , void * V_27 , bool V_28 )
{
struct V_17 * V_26 = F_10 ( V_18 ) ;
struct V_29 * V_30 = V_27 ;
struct V_31 * V_32 ;
if ( ! V_18 -> V_33 )
return 0 ;
if ( V_30 && ( V_18 -> V_33 != V_30 ) )
return 0 ;
if ( V_28 ) {
if ( ( strncmp ( V_26 -> V_3 , L_12 , 11 ) == 0 ) )
return 0 ;
if ( ( strncmp ( V_26 -> V_3 , L_13 , 10 ) == 0 ) )
return 0 ;
}
V_32 = F_19 ( V_18 -> V_33 ) ;
return ( V_26 -> V_34 < V_35 ||
( V_26 -> V_34 == V_35 &&
V_32 -> V_36 && ! V_32 -> V_36 ( V_26 ) ) ) ;
}
static int F_20 ( struct V_13 * V_18 , void * V_27 )
{
return F_18 ( V_18 , V_27 , true ) ;
}
static int F_21 ( struct V_13 * V_18 , void * V_27 )
{
return F_18 ( V_18 , V_27 , false ) ;
}
static int F_22 ( struct V_29 * V_30 )
{
return F_23 ( & V_25 . V_7 , NULL , V_30 ,
F_20 ) ;
}
static int F_24 ( struct V_29 * V_30 )
{
return F_23 ( & V_25 . V_7 , NULL , V_30 ,
F_21 ) ;
}
static int F_25 ( struct V_13 * V_18 , void * V_27 )
{
struct V_17 * V_26 = F_10 ( V_18 ) ;
struct V_29 * V_30 = V_27 ;
if ( V_30 && ( V_18 -> V_33 != V_30 ) )
return 0 ;
if ( ! V_18 -> V_33 ) {
F_2 ( V_37 L_14 ,
V_26 -> V_3 ) ;
} else if ( V_26 -> V_34 < V_35 ) {
enum V_38 V_39 = V_40 ;
if ( V_26 -> V_41 )
V_39 = F_26 ( V_26 -> V_41 ) ;
F_2 ( V_4 L_15
L_16 ,
V_26 -> V_3 , V_26 -> V_34 , V_39 ) ;
}
return 0 ;
}
static bool F_27 ( unsigned long V_42 , unsigned int V_43 ,
unsigned int * V_44 )
{
if ( F_28 ( V_45 , V_42 + ( * V_44 + 5 ) * V_46 ) ) {
if ( ! * V_44 )
F_2 ( V_4 L_17
L_18 ) ;
* V_44 += 5 ;
F_2 ( L_19 , V_43 - * V_44 ) ;
if ( * V_44 == V_43 )
return true ;
}
F_29 ( V_46 / 10 ) ;
return false ;
}
static void F_30 ( struct V_31 * V_32 )
{
unsigned long V_42 = V_45 ;
struct V_29 * V_30 = V_32 ? & V_32 -> V_33 : NULL ;
unsigned int V_44 = 0 ;
if ( ! V_47 || ! F_31 () )
return;
while ( F_24 ( V_30 ) )
if ( F_27 ( V_42 , 30 , & V_44 ) )
break;
while ( F_22 ( V_30 ) )
if ( F_27 ( V_42 , 270 , & V_44 ) )
break;
if ( V_44 )
F_2 ( L_20 ) ;
F_23 ( & V_25 . V_7 , NULL , V_30 ,
F_25 ) ;
}
int F_32 ( struct V_31 * V_30 )
{
int V_48 ;
V_30 -> V_49 = F_16 ;
V_48 = F_33 ( V_30 , & V_25 ) ;
if ( V_48 )
return V_48 ;
F_30 ( V_30 ) ;
return 0 ;
}
static void F_34 ( struct V_20 * V_50 ,
const char * * V_51 , unsigned int V_52 )
{
F_35 ( V_53 , V_51 [ V_24 ] , L_9 , L_21 , & V_54 ) ;
F_2 ( V_55 L_22 ,
V_51 [ V_24 ] , F_36 ( V_54 ) ) ;
F_37 ( & V_56 ) ;
}
static void F_38 ( char * V_57 , int V_58 )
{
long V_59 ;
V_59 = F_39 ( V_56 ,
V_54 == V_58 , 5 * V_46 ) ;
if ( V_59 <= 0 )
F_2 ( V_37 L_23 , V_57 ) ;
}
static void F_40 ( char * V_60 , char * V_57 , int V_61 )
{
struct V_20 V_62 ;
F_2 ( V_55 L_22 ,
V_57 , F_36 ( V_61 ) ) ;
memset ( & V_62 , 0 , sizeof( V_62 ) ) ;
V_62 . V_63 = F_6 ( V_64 | V_65 , L_24 , V_57 ) ;
if ( ! V_62 . V_63 )
return;
V_62 . V_66 = F_34 ;
V_54 = V_40 ;
F_2 ( V_37 L_25 , V_57 ) ;
F_41 ( & V_62 ) ;
switch ( V_61 ) {
case V_35 :
F_42 ( V_53 , V_60 , L_26 , L_27 , V_67 ) ;
F_38 ( V_57 , V_67 ) ;
case V_67 :
F_42 ( V_53 , V_60 , L_26 , L_27 , V_68 ) ;
F_38 ( V_57 , V_68 ) ;
case V_68 :
F_42 ( V_53 , V_60 , L_26 , L_27 , V_69 ) ;
F_38 ( V_57 , V_70 ) ;
}
F_43 ( & V_62 ) ;
F_2 ( V_37 L_28 , V_57 ) ;
F_8 ( V_62 . V_63 ) ;
}
static void F_44 ( char * V_71 , char * V_18 )
{
int V_61 , V_72 , V_9 ;
char * V_73 , * V_74 ;
V_74 = F_6 ( V_64 | V_65 , L_29 , V_71 , V_18 ) ;
if ( ! V_74 )
return;
V_9 = F_35 ( V_53 , V_74 , L_26 , L_21 , & V_72 ) ;
if ( V_9 != 1 )
goto V_75;
switch ( V_72 ) {
case V_35 :
case V_68 :
F_2 ( V_55 L_30 ,
V_74 , F_36 ( V_72 ) ) ;
V_73 = F_45 ( V_53 , V_74 , L_11 , NULL ) ;
if ( ! V_73 || F_46 ( V_73 ) )
goto V_75;
V_9 = F_35 ( V_53 , V_73 , L_26 , L_21 , & V_61 ) ;
if ( V_9 == 1 )
F_40 ( V_74 , V_73 , V_61 ) ;
F_8 ( V_73 ) ;
break;
default:
break;
}
V_75:
F_8 ( V_74 ) ;
}
static void F_47 ( void )
{
char * * V_76 , * * V_18 ;
int V_77 , V_78 ;
int V_79 , V_80 ;
V_76 = F_48 ( V_53 , L_31 , L_9 , & V_77 ) ;
if ( F_46 ( V_76 ) )
return;
for ( V_79 = 0 ; V_79 < V_77 ; V_79 ++ ) {
V_18 = F_48 ( V_53 , L_31 , V_76 [ V_79 ] , & V_78 ) ;
if ( F_46 ( V_18 ) )
continue;
for ( V_80 = 0 ; V_80 < V_78 ; V_80 ++ )
F_44 ( V_76 [ V_79 ] , V_18 [ V_80 ] ) ;
F_8 ( V_18 ) ;
}
F_8 ( V_76 ) ;
}
static int F_49 ( struct V_81 * V_82 ,
unsigned long V_83 ,
void * V_27 )
{
if ( F_50 () )
F_47 () ;
F_51 ( & V_25 ) ;
F_41 ( & V_84 ) ;
return V_85 ;
}
static int T_1 F_52 ( void )
{
static struct V_81 V_86 = {
. V_87 = F_49
} ;
int V_9 ;
F_5 ( L_9 ) ;
V_9 = F_53 ( & V_25 . V_7 ) ;
if ( V_9 )
return V_9 ;
F_54 ( & V_86 ) ;
return 0 ;
}
static int T_1 F_55 ( void )
{
if ( F_50 () && ! V_88 )
return - V_89 ;
V_47 = 1 ;
F_30 ( NULL ) ;
return 0 ;
}
