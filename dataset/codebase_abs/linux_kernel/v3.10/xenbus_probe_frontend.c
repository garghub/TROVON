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
static void F_14 ( struct V_24 * V_25 )
{
struct V_17 * V_26 = F_15 ( V_25 , struct V_17 , V_27 ) ;
F_16 ( & V_26 -> V_18 ) ;
}
static int F_17 ( struct V_13 * V_18 )
{
if ( V_28 == V_29 ) {
struct V_17 * V_26 = F_10 ( V_18 ) ;
if ( ! V_30 ) {
F_18 ( L_9 ,
V_26 -> V_3 ) ;
return - V_31 ;
}
F_19 ( & V_26 -> V_27 , F_14 ) ;
F_20 ( V_30 , & V_26 -> V_27 ) ;
return 0 ;
}
return F_16 ( V_18 ) ;
}
static void F_21 ( struct V_20 * V_21 ,
const char * * V_22 , unsigned int V_23 )
{
F_5 ( L_10 ) ;
F_22 ( V_22 [ V_32 ] , & V_33 ) ;
}
static int F_23 ( struct V_17 * V_34 )
{
return F_24 ( V_34 , L_11 , L_12 ) ;
}
static int F_25 ( struct V_13 * V_18 , void * V_35 , bool V_36 )
{
struct V_17 * V_34 = F_10 ( V_18 ) ;
struct V_37 * V_38 = V_35 ;
struct V_39 * V_40 ;
if ( ! V_18 -> V_41 )
return 0 ;
if ( V_38 && ( V_18 -> V_41 != V_38 ) )
return 0 ;
if ( V_36 ) {
if ( ( strncmp ( V_34 -> V_3 , L_13 , 11 ) == 0 ) )
return 0 ;
if ( ( strncmp ( V_34 -> V_3 , L_14 , 10 ) == 0 ) )
return 0 ;
}
V_40 = F_26 ( V_18 -> V_41 ) ;
return ( V_34 -> V_42 < V_43 ||
( V_34 -> V_42 == V_43 &&
V_40 -> V_44 && ! V_40 -> V_44 ( V_34 ) ) ) ;
}
static int F_27 ( struct V_13 * V_18 , void * V_35 )
{
return F_25 ( V_18 , V_35 , true ) ;
}
static int F_28 ( struct V_13 * V_18 , void * V_35 )
{
return F_25 ( V_18 , V_35 , false ) ;
}
static int F_29 ( struct V_37 * V_38 )
{
return F_30 ( & V_33 . V_7 , NULL , V_38 ,
F_27 ) ;
}
static int F_31 ( struct V_37 * V_38 )
{
return F_30 ( & V_33 . V_7 , NULL , V_38 ,
F_28 ) ;
}
static int F_32 ( struct V_13 * V_18 , void * V_35 )
{
struct V_17 * V_34 = F_10 ( V_18 ) ;
struct V_37 * V_38 = V_35 ;
if ( V_38 && ( V_18 -> V_41 != V_38 ) )
return 0 ;
if ( ! V_18 -> V_41 ) {
F_2 ( V_45 L_15 ,
V_34 -> V_3 ) ;
} else if ( V_34 -> V_42 < V_43 ) {
enum V_46 V_47 = V_48 ;
if ( V_34 -> V_49 )
V_47 = F_33 ( V_34 -> V_49 ) ;
F_2 ( V_4 L_16
L_17 ,
V_34 -> V_3 , V_34 -> V_42 , V_47 ) ;
}
return 0 ;
}
static bool F_34 ( unsigned long V_50 , unsigned int V_51 ,
unsigned int * V_52 )
{
if ( F_35 ( V_53 , V_50 + ( * V_52 + 5 ) * V_54 ) ) {
if ( ! * V_52 )
F_2 ( V_4 L_18
L_19 ) ;
* V_52 += 5 ;
F_2 ( L_20 , V_51 - * V_52 ) ;
if ( * V_52 == V_51 )
return true ;
}
F_36 ( V_54 / 10 ) ;
return false ;
}
static void F_37 ( struct V_39 * V_40 )
{
unsigned long V_50 = V_53 ;
struct V_37 * V_38 = V_40 ? & V_40 -> V_41 : NULL ;
unsigned int V_52 = 0 ;
if ( ! V_55 || ! F_38 () )
return;
while ( F_31 ( V_38 ) )
if ( F_34 ( V_50 , 30 , & V_52 ) )
break;
while ( F_29 ( V_38 ) )
if ( F_34 ( V_50 , 270 , & V_52 ) )
break;
if ( V_52 )
F_2 ( L_21 ) ;
F_30 ( & V_33 . V_7 , NULL , V_38 ,
F_32 ) ;
}
int F_39 ( struct V_39 * V_38 )
{
int V_56 ;
V_38 -> V_57 = F_23 ;
V_56 = F_40 ( V_38 , & V_33 ) ;
if ( V_56 )
return V_56 ;
F_37 ( V_38 ) ;
return 0 ;
}
static void F_41 ( struct V_20 * V_25 ,
const char * * V_58 , unsigned int V_59 )
{
F_42 ( V_60 , V_58 [ V_32 ] , L_10 , L_22 , & V_61 ) ;
F_2 ( V_62 L_23 ,
V_58 [ V_32 ] , F_43 ( V_61 ) ) ;
F_44 ( & V_63 ) ;
}
static void F_45 ( char * V_64 , int V_65 )
{
long V_66 ;
V_66 = F_46 ( V_63 ,
V_61 == V_65 , 5 * V_54 ) ;
if ( V_66 <= 0 )
F_2 ( V_45 L_24 , V_64 ) ;
}
static void F_47 ( char * V_67 , char * V_64 , int V_68 )
{
struct V_20 V_69 ;
F_2 ( V_62 L_23 ,
V_64 , F_43 ( V_68 ) ) ;
memset ( & V_69 , 0 , sizeof( V_69 ) ) ;
V_69 . V_70 = F_6 ( V_71 | V_72 , L_25 , V_64 ) ;
if ( ! V_69 . V_70 )
return;
V_69 . V_73 = F_41 ;
V_61 = V_48 ;
F_2 ( V_45 L_26 , V_64 ) ;
F_48 ( & V_69 ) ;
switch ( V_68 ) {
case V_43 :
F_49 ( V_60 , V_67 , L_27 , L_28 , V_74 ) ;
F_45 ( V_64 , V_74 ) ;
case V_74 :
F_49 ( V_60 , V_67 , L_27 , L_28 , V_75 ) ;
F_45 ( V_64 , V_75 ) ;
case V_75 :
F_49 ( V_60 , V_67 , L_27 , L_28 , V_76 ) ;
F_45 ( V_64 , V_77 ) ;
}
F_50 ( & V_69 ) ;
F_2 ( V_45 L_29 , V_64 ) ;
F_8 ( V_69 . V_70 ) ;
}
static void F_51 ( char * V_78 , char * V_18 )
{
int V_68 , V_79 , V_9 ;
char * V_80 , * V_81 ;
V_81 = F_6 ( V_71 | V_72 , L_30 , V_78 , V_18 ) ;
if ( ! V_81 )
return;
V_9 = F_42 ( V_60 , V_81 , L_27 , L_22 , & V_79 ) ;
if ( V_9 != 1 )
goto V_82;
switch ( V_79 ) {
case V_43 :
case V_75 :
F_2 ( V_62 L_31 ,
V_81 , F_43 ( V_79 ) ) ;
V_80 = F_52 ( V_60 , V_81 , L_12 , NULL ) ;
if ( ! V_80 || F_53 ( V_80 ) )
goto V_82;
V_9 = F_42 ( V_60 , V_80 , L_27 , L_22 , & V_68 ) ;
if ( V_9 == 1 )
F_47 ( V_81 , V_80 , V_68 ) ;
F_8 ( V_80 ) ;
break;
default:
break;
}
V_82:
F_8 ( V_81 ) ;
}
static void F_54 ( void )
{
char * * V_83 , * * V_18 ;
int V_84 , V_85 ;
int V_86 , V_87 ;
V_83 = F_55 ( V_60 , L_32 , L_10 , & V_84 ) ;
if ( F_53 ( V_83 ) )
return;
for ( V_86 = 0 ; V_86 < V_84 ; V_86 ++ ) {
V_18 = F_55 ( V_60 , L_32 , V_83 [ V_86 ] , & V_85 ) ;
if ( F_53 ( V_18 ) )
continue;
for ( V_87 = 0 ; V_87 < V_85 ; V_87 ++ )
F_51 ( V_83 [ V_86 ] , V_18 [ V_87 ] ) ;
F_8 ( V_18 ) ;
}
F_8 ( V_83 ) ;
}
static int F_56 ( struct V_88 * V_89 ,
unsigned long V_90 ,
void * V_35 )
{
if ( F_57 () )
F_54 () ;
F_58 ( & V_33 ) ;
F_48 ( & V_91 ) ;
return V_92 ;
}
static int T_1 F_59 ( void )
{
static struct V_88 V_93 = {
. V_94 = F_56
} ;
int V_9 ;
F_5 ( L_10 ) ;
V_9 = F_60 ( & V_33 . V_7 ) ;
if ( V_9 )
return V_9 ;
F_61 ( & V_93 ) ;
V_30 = F_62 ( L_33 ) ;
return 0 ;
}
static int T_1 F_63 ( void )
{
if ( F_57 () && ! V_95 )
return - V_96 ;
V_55 = 1 ;
F_37 ( NULL ) ;
return 0 ;
}
