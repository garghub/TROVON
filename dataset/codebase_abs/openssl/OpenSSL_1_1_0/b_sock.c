int F_1 ( const char * V_1 , unsigned char * V_2 )
{
T_1 * V_3 = NULL ;
int V_4 = 0 ;
if ( F_2 () != 1 )
return 0 ;
if ( F_3 ( V_1 , NULL , V_5 , V_6 , V_7 , & V_3 ) ) {
T_2 V_8 ;
if ( F_4 ( V_3 ) != V_6 ) {
F_5 ( V_9 ,
V_10 ) ;
} else {
F_6 ( F_7 ( V_3 ) , NULL , & V_8 ) ;
F_8 ( V_8 == 4 ) ;
F_6 ( F_7 ( V_3 ) , V_2 , & V_8 ) ;
V_4 = 1 ;
}
F_9 ( V_3 ) ;
} else {
F_10 ( 2 , L_1 , V_1 ) ;
}
return V_4 ;
}
int F_11 ( const char * V_1 , unsigned short * V_11 )
{
T_1 * V_3 = NULL ;
int V_4 = 0 ;
if ( V_1 == NULL ) {
F_5 ( V_12 , V_13 ) ;
return ( 0 ) ;
}
if ( F_2 () != 1 )
return 0 ;
if ( F_3 ( NULL , V_1 , V_5 , V_6 , V_7 , & V_3 ) ) {
if ( F_4 ( V_3 ) != V_6 ) {
F_5 ( V_12 ,
V_14 ) ;
} else {
* V_11 = F_12 ( F_13 ( F_7 ( V_3 ) ) ) ;
V_4 = 1 ;
}
F_9 ( V_3 ) ;
} else {
F_10 ( 2 , L_1 , V_1 ) ;
}
return V_4 ;
}
int F_14 ( int V_15 )
{
int V_16 = 0 , V_17 ;
T_3 V_18 = sizeof( V_16 ) ;
V_17 = F_15 ( V_15 , V_19 , V_20 , ( void * ) & V_16 , & V_18 ) ;
if ( V_17 < 0 )
return ( F_16 () ) ;
else
return ( V_16 ) ;
}
struct V_21 * F_17 ( const char * V_22 )
{
# if ( F_18 ( V_23 ) && ! F_18 ( V_24 ) )
return F_19 ( ( char * ) V_22 ) ;
# else
return F_19 ( V_22 ) ;
# endif
}
int F_2 ( void )
{
# ifdef F_20
static struct V_25 V_26 ;
if ( ! V_27 ) {
int V_28 ;
V_27 = 1 ;
memset ( & V_26 , 0 , sizeof( V_26 ) ) ;
if ( F_21 ( 0x0202 , & V_26 ) != 0 ) {
V_28 = F_22 () ;
F_23 ( V_29 , V_28 ) ;
F_5 ( V_30 , V_31 ) ;
return ( - 1 ) ;
}
}
# endif
# ifdef F_24
extern int V_32 ;
V_32 = 0 ;
if ( F_25 () )
return ( - 1 ) ;
# endif
return ( 1 ) ;
}
void F_26 ( void )
{
# ifdef F_20
if ( V_27 ) {
V_27 = 0 ;
F_27 () ;
}
# endif
}
int F_28 ( int V_33 , long type , void * V_34 )
{
int V_17 ;
# ifdef F_29
V_17 = F_30 ( V_33 , type , ( char * ) V_34 ) ;
# else
# if F_18 ( V_35 )
# if V_36 == 64
# define F_31 arg_32p
# pragma V_37 V_38
# pragma V_37 V_39
unsigned long V_40 ;
unsigned long * V_41 ;
# pragma V_37 V_42
V_41 = & V_40 ;
V_40 = * ( ( unsigned long * ) V_34 ) ;
# else
# define F_31 arg
# endif
# else
# define F_31 arg
# endif
V_17 = F_30 ( V_33 , type , F_31 ) ;
# endif
if ( V_17 < 0 )
F_23 ( V_43 , F_16 () ) ;
return ( V_17 ) ;
}
int F_32 ( char * V_44 , int V_45 )
{
int V_46 = V_47 ;
char * V_48 = NULL , * V_49 = NULL ;
T_1 * V_3 = NULL ;
if ( ! F_33 ( V_44 , & V_48 , & V_49 , V_50 ) )
return V_47 ;
if ( F_2 () != 1 )
return V_47 ;
if ( F_3 ( V_48 , V_49 , V_51 , V_52 , V_7 , & V_3 ) != 0 )
goto V_28;
if ( ( V_46 = F_34 ( F_4 ( V_3 ) , F_35 ( V_3 ) ,
F_36 ( V_3 ) , 0 ) ) == V_47 ) {
V_46 = V_47 ;
goto V_28;
}
if ( ! F_37 ( V_46 , F_7 ( V_3 ) ,
V_45 ? V_53 : 0 ) ) {
F_38 ( V_46 ) ;
V_46 = V_47 ;
}
V_28:
F_9 ( V_3 ) ;
F_39 ( V_48 ) ;
F_39 ( V_49 ) ;
return V_46 ;
}
int F_40 ( int V_15 , char * * V_54 )
{
T_4 V_3 ;
int V_4 = - 1 ;
V_4 = F_41 ( V_15 , & V_3 , 0 ) ;
if ( V_4 == ( int ) V_47 ) {
if ( F_42 ( V_4 ) ) {
V_4 = - 2 ;
goto V_55;
}
F_23 ( V_56 , F_16 () ) ;
F_5 ( V_57 , V_58 ) ;
goto V_55;
}
if ( V_54 != NULL ) {
char * V_44 = F_43 ( & V_3 , 1 ) ;
char * V_59 = F_44 ( & V_3 , 1 ) ;
if ( V_44 != NULL && V_59 != NULL )
* V_54 = F_45 ( strlen ( V_44 ) + strlen ( V_59 ) + 2 ) ;
else
* V_54 = NULL ;
if ( * V_54 == NULL ) {
F_5 ( V_57 , V_60 ) ;
F_38 ( V_4 ) ;
V_4 = ( int ) V_47 ;
} else {
strcpy ( * V_54 , V_44 ) ;
strcat ( * V_54 , L_2 ) ;
strcat ( * V_54 , V_59 ) ;
}
F_39 ( V_44 ) ;
F_39 ( V_59 ) ;
}
V_55:
return V_4 ;
}
int F_46 ( int V_46 , int V_61 )
{
int V_4 = 0 ;
# if F_18 ( V_62 ) && ( F_18 ( V_63 ) || F_18 ( V_64 ) )
int V_65 ;
# ifdef V_64
V_65 = V_64 ;
# else
# ifdef V_63
V_65 = V_63 ;
# endif
# endif
V_4 = F_47 ( V_46 , V_65 , V_62 , ( char * ) & V_61 , sizeof( V_61 ) ) ;
# endif
return ( V_4 == 0 ) ;
}
int F_48 ( int V_46 , int V_66 )
{
int V_4 = - 1 ;
int V_8 ;
V_8 = V_66 ;
# ifdef F_49
V_8 = V_66 ;
V_4 = F_28 ( V_46 , F_49 , & V_8 ) ;
# elif F_18 ( V_67 ) && F_18 ( V_68 ) && ( F_18 ( V_69 ) || F_18 ( V_70 ) )
V_8 = F_50 ( V_46 , V_67 , 0 ) ;
if ( V_8 == - 1 ) {
F_23 ( V_71 , F_51 () ) ;
V_4 = - 1 ;
} else {
# if F_18 ( V_69 )
V_8 &= ~ V_69 ;
# else
V_8 &= ~ V_70 ;
# endif
if ( V_66 ) {
# if F_18 ( V_69 )
V_8 |= V_69 ;
# else
V_8 |= V_70 ;
# endif
}
V_4 = F_50 ( V_46 , V_68 , V_8 ) ;
if ( V_4 < 0 ) {
F_23 ( V_71 , F_51 () ) ;
}
}
# else
F_5 ( V_72 , V_73 ) ;
# endif
return ( V_4 == 0 ) ;
}
int F_52 ( int V_15 ,
enum V_74 type , union V_75 * V_76 )
{
switch ( type ) {
case V_77 :
{
T_3 V_78 ;
int V_4 = 0 ;
V_78 = sizeof( * V_76 -> V_79 ) ;
V_4 = F_53 ( V_15 , F_54 ( V_76 -> V_79 ) ,
& V_78 ) ;
if ( V_4 == - 1 ) {
F_23 ( V_80 , F_16 () ) ;
F_5 ( V_81 , V_82 ) ;
return 0 ;
}
if ( ( T_2 ) V_78 > sizeof( * V_76 -> V_79 ) ) {
F_5 ( V_81 , V_83 ) ;
return 0 ;
}
}
break;
default:
F_5 ( V_81 , V_84 ) ;
return 0 ;
}
return 1 ;
}
