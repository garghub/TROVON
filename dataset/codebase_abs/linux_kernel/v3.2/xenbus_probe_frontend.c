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
V_3 = F_5 ( V_10 , L_3 , V_7 -> V_11 , type , V_8 ) ;
if ( ! V_3 )
return - V_12 ;
F_6 ( L_4 , V_3 ) ;
V_9 = F_7 ( V_7 , type , V_3 ) ;
F_8 ( V_3 ) ;
return V_9 ;
}
static int F_9 ( struct V_13 * V_14 ,
struct V_15 * V_16 )
{
struct V_17 * V_18 = F_10 ( V_14 ) ;
if ( F_11 ( V_16 , L_5 , V_18 -> V_19 ) )
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
F_6 ( L_6 ) ;
F_15 ( V_22 [ V_24 ] , & V_25 ) ;
}
static int F_16 ( struct V_17 * V_26 )
{
return F_17 ( V_26 , L_7 , L_8 ) ;
}
static int F_18 ( struct V_13 * V_18 , void * V_27 )
{
struct V_17 * V_26 = F_10 ( V_18 ) ;
struct V_28 * V_29 = V_27 ;
struct V_30 * V_31 ;
if ( ! V_18 -> V_32 )
return 0 ;
if ( V_29 && ( V_18 -> V_32 != V_29 ) )
return 0 ;
V_31 = F_19 ( V_18 -> V_32 ) ;
return ( V_26 -> V_33 < V_34 ||
( V_26 -> V_33 == V_34 &&
V_31 -> V_35 && ! V_31 -> V_35 ( V_26 ) ) ) ;
}
static int F_20 ( struct V_28 * V_29 )
{
return F_21 ( & V_25 . V_7 , NULL , V_29 ,
F_18 ) ;
}
static int F_22 ( struct V_13 * V_18 , void * V_27 )
{
struct V_17 * V_26 = F_10 ( V_18 ) ;
struct V_28 * V_29 = V_27 ;
if ( V_29 && ( V_18 -> V_32 != V_29 ) )
return 0 ;
if ( ! V_18 -> V_32 ) {
F_2 ( V_36 L_9 ,
V_26 -> V_3 ) ;
} else if ( V_26 -> V_33 < V_34 ) {
enum V_37 V_38 = V_39 ;
if ( V_26 -> V_40 )
V_38 = F_23 ( V_26 -> V_40 ) ;
F_2 ( V_4 L_10
L_11 ,
V_26 -> V_3 , V_26 -> V_33 , V_38 ) ;
}
return 0 ;
}
static void F_24 ( struct V_30 * V_31 )
{
unsigned long V_41 = V_42 ;
struct V_28 * V_29 = V_31 ? & V_31 -> V_32 : NULL ;
unsigned int V_43 = 0 ;
if ( ! V_44 || ! F_25 () )
return;
while ( F_20 ( V_29 ) ) {
if ( F_26 ( V_42 , V_41 + ( V_43 + 5 ) * V_45 ) ) {
if ( ! V_43 )
F_2 ( V_4 L_12
L_13 ) ;
V_43 += 5 ;
F_2 ( L_14 , 300 - V_43 ) ;
if ( V_43 == 300 )
break;
}
F_27 ( V_45 / 10 ) ;
}
if ( V_43 )
F_2 ( L_15 ) ;
F_21 ( & V_25 . V_7 , NULL , V_29 ,
F_22 ) ;
}
int F_28 ( struct V_30 * V_29 ,
struct V_46 * V_47 , const char * V_48 )
{
int V_49 ;
V_29 -> V_50 = F_16 ;
V_49 = F_29 ( V_29 , & V_25 ,
V_47 , V_48 ) ;
if ( V_49 )
return V_49 ;
F_24 ( V_29 ) ;
return 0 ;
}
static void F_30 ( struct V_20 * V_51 ,
const char * * V_52 , unsigned int V_53 )
{
F_31 ( V_54 , V_52 [ V_24 ] , L_6 , L_16 , & V_55 ) ;
F_2 ( V_56 L_17 ,
V_52 [ V_24 ] , F_32 ( V_55 ) ) ;
F_33 ( & V_57 ) ;
}
static void F_34 ( char * V_58 , int V_59 )
{
long V_60 ;
V_60 = F_35 ( V_57 ,
V_55 == V_59 , 5 * V_45 ) ;
if ( V_60 <= 0 )
F_2 ( V_36 L_18 , V_58 ) ;
}
static void F_36 ( char * V_61 , char * V_58 , int V_62 )
{
struct V_20 V_63 ;
F_2 ( V_56 L_17 ,
V_58 , F_32 ( V_62 ) ) ;
memset ( & V_63 , 0 , sizeof( V_63 ) ) ;
V_63 . V_64 = F_5 ( V_65 | V_66 , L_19 , V_58 ) ;
if ( ! V_63 . V_64 )
return;
V_63 . V_67 = F_30 ;
V_55 = V_39 ;
F_2 ( V_36 L_20 , V_58 ) ;
F_37 ( & V_63 ) ;
switch ( V_62 ) {
case V_34 :
F_38 ( V_54 , V_61 , L_21 , L_22 , V_68 ) ;
F_34 ( V_58 , V_68 ) ;
case V_68 :
F_38 ( V_54 , V_61 , L_21 , L_22 , V_69 ) ;
F_34 ( V_58 , V_69 ) ;
case V_69 :
F_38 ( V_54 , V_61 , L_21 , L_22 , V_70 ) ;
F_34 ( V_58 , V_71 ) ;
}
F_39 ( & V_63 ) ;
F_2 ( V_36 L_23 , V_58 ) ;
F_8 ( V_63 . V_64 ) ;
}
static void F_40 ( char * V_72 , char * V_18 )
{
int V_62 , V_73 , V_9 ;
char * V_74 , * V_75 ;
V_75 = F_5 ( V_65 | V_66 , L_24 , V_72 , V_18 ) ;
if ( ! V_75 )
return;
V_9 = F_31 ( V_54 , V_75 , L_21 , L_16 , & V_73 ) ;
if ( V_9 != 1 )
goto V_76;
switch ( V_73 ) {
case V_34 :
case V_69 :
F_2 ( V_56 L_25 ,
V_75 , F_32 ( V_73 ) ) ;
V_74 = F_41 ( V_54 , V_75 , L_8 , NULL ) ;
if ( ! V_74 || F_42 ( V_74 ) )
goto V_76;
V_9 = F_31 ( V_54 , V_74 , L_21 , L_16 , & V_62 ) ;
if ( V_9 == 1 )
F_36 ( V_75 , V_74 , V_62 ) ;
F_8 ( V_74 ) ;
break;
default:
break;
}
V_76:
F_8 ( V_75 ) ;
}
static void F_43 ( void )
{
char * * V_77 , * * V_18 ;
int V_78 , V_79 ;
int V_80 , V_81 ;
V_77 = F_44 ( V_54 , L_26 , L_6 , & V_78 ) ;
if ( F_42 ( V_77 ) )
return;
for ( V_80 = 0 ; V_80 < V_78 ; V_80 ++ ) {
V_18 = F_44 ( V_54 , L_26 , V_77 [ V_80 ] , & V_79 ) ;
if ( F_42 ( V_18 ) )
continue;
for ( V_81 = 0 ; V_81 < V_79 ; V_81 ++ )
F_40 ( V_77 [ V_80 ] , V_18 [ V_81 ] ) ;
F_8 ( V_18 ) ;
}
F_8 ( V_77 ) ;
}
static int F_45 ( struct V_82 * V_83 ,
unsigned long V_84 ,
void * V_27 )
{
if ( F_46 () )
F_43 () ;
F_47 ( & V_25 ) ;
F_37 ( & V_85 ) ;
return V_86 ;
}
static int T_1 F_48 ( void )
{
static struct V_82 V_87 = {
. V_88 = F_45
} ;
int V_9 ;
F_6 ( L_6 ) ;
V_9 = F_49 ( & V_25 . V_7 ) ;
if ( V_9 )
return V_9 ;
F_50 ( & V_87 ) ;
return 0 ;
}
static int T_1 F_51 ( void )
{
if ( F_46 () && ! V_89 )
return - V_90 ;
V_44 = 1 ;
F_24 ( NULL ) ;
return 0 ;
}
