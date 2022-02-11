static void F_1 ( void )
{
int V_1 ;
int V_2 = F_2 () , V_3 = F_3 () ;
int V_4 ;
if ( F_4 ( V_5 , 0 ) < 0 ||
F_5 ( V_6 , 0 , 0 , 0 ) < 0 ) {
perror ( L_1 ) ;
F_6 ( V_2 , V_7 ) ;
}
F_6 ( V_2 , V_8 ) ;
V_4 = F_2 () ;
if ( V_4 == V_2 )
V_1 = 1 ;
else if ( V_4 == V_3 )
V_1 = 0 ;
else
V_1 = 2 ;
exit ( V_1 ) ;
}
static void F_7 ( const char * V_9 )
{
perror ( V_9 ) ;
exit ( 1 ) ;
}
static void F_8 ( char * V_10 , ... )
{
T_1 V_11 ;
va_start ( V_11 , V_10 ) ;
vfprintf ( V_12 , V_10 , V_11 ) ;
va_end ( V_11 ) ;
exit ( 1 ) ;
}
static void F_9 ( char * V_10 , ... )
{
T_1 V_11 ;
va_start ( V_11 , V_10 ) ;
vfprintf ( V_12 , V_10 , V_11 ) ;
va_end ( V_11 ) ;
}
static int F_10 ( void )
{
int V_2 , V_13 , V_14 ;
V_2 = F_11 () ;
if ( V_2 == 0 )
F_1 () ;
else if ( V_2 < 0 )
F_7 ( L_2 ) ;
F_12 ( V_13 = F_13 ( V_2 , & V_14 , V_15 ) ) ;
if ( V_13 < 0 )
F_7 ( L_3 ) ;
if ( ! F_14 ( V_14 ) || ( F_15 ( V_14 ) != V_8 ) )
F_8 ( L_4 ,
V_14 ) ;
return V_2 ;
}
static int F_16 ( int V_2 , int V_16 , int V_17 )
{
int V_14 , V_13 , V_1 = 0 ;
if ( F_5 ( V_18 , V_2 , 0 , 0 ) < 0 ) {
perror ( L_5 ) ;
return - 1 ;
}
F_12 ( V_13 = F_13 ( V_2 , & V_14 , 0 ) ) ;
if ( ! F_17 ( V_14 ) || ( F_18 ( V_14 ) != V_16 ) ) {
int V_19 = F_18 ( V_14 ) ;
if ( V_19 == 2 )
F_9 ( L_6
L_7 ) ;
F_9 ( L_8
L_9 , V_19 ,
V_16 , V_14 ) ;
if ( V_17 )
exit ( 1 ) ;
V_1 = - 1 ;
}
return V_1 ;
}
static int T_2 F_19 ( char * V_9 , int * V_20 )
{
V_21 = 1 ;
V_22 = 1 ;
V_23 = 1 ;
V_24 = 1 ;
return 0 ;
}
static int T_2 F_20 ( char * V_9 , int * V_20 )
{
V_25 = 1 ;
return 0 ;
}
static void T_2 F_21 ( void )
{
unsigned long V_26 [ V_27 ] ;
int V_2 , V_13 , V_14 , V_28 = 0 ;
F_9 ( L_10 ) ;
V_29 = 0 ;
V_2 = F_10 () ;
if ( F_5 ( V_30 , V_2 , 0 , 0 ) < 0 )
goto V_31;
F_12 ( V_13 = F_13 ( V_2 , & V_14 , V_15 ) ) ;
if ( V_13 < 0 )
F_7 ( L_11 ) ;
if ( ! F_14 ( V_14 ) || ( F_15 ( V_14 ) != V_32 ) )
F_8 ( L_12 ,
V_14 ) ;
if ( F_5 ( V_33 , V_2 , 0 , V_26 ) < 0 )
F_7 ( L_13 ) ;
if ( F_22 ( V_26 ) != V_34 ) {
F_9 ( L_14
L_15 , F_22 ( V_26 ) , V_34 ) ;
goto V_31;
}
V_13 = F_5 ( V_35 , V_2 , V_36 , F_2 () ) ;
if ( V_13 < 0 ) {
F_9 ( L_16
L_17 ) ;
goto V_31;
}
if ( F_16 ( V_2 , 0 , 0 ) < 0 )
goto V_37;
V_29 = 1 ;
F_9 ( L_18 ) ;
F_23 ( ! V_25 ) ;
F_9 ( L_19 ) ;
V_2 = F_10 () ;
if ( ( F_5 ( V_38 , V_2 , 0 ,
( void * ) V_39 ) < 0 ) )
F_7 ( L_20 ) ;
while ( 1 ) {
V_28 ++ ;
if ( F_5 ( V_40 , V_2 , 0 , 0 ) < 0 )
goto V_31;
F_12 ( V_13 = F_13 ( V_2 , & V_14 , V_15 ) ) ;
if ( V_13 < 0 )
F_7 ( L_21 ) ;
if ( F_14 ( V_14 ) &&
( F_15 ( V_14 ) == ( V_32 | 0x80 ) ) ) {
if ( ! V_28 ) {
F_9 ( L_22
L_23 ) ;
goto V_31;
}
V_13 = F_5 ( V_35 , V_2 , V_36 ,
F_2 () ) ;
if ( V_13 < 0 )
F_7 ( L_24
L_25 ) ;
break;
}
else if ( F_14 ( V_14 ) && ( F_15 ( V_14 ) == V_32 ) )
V_28 ++ ;
else {
F_9 ( L_26
L_27 ,
V_14 ) ;
goto V_31;
}
}
if ( F_16 ( V_2 , 0 , 0 ) < 0 )
goto V_37;
V_29 = 2 ;
F_9 ( L_18 ) ;
if ( ! V_25 )
F_23 ( V_29 ) ;
return;
V_31:
F_16 ( V_2 , 1 , 0 ) ;
V_37:
F_9 ( L_28 ) ;
}
static void T_2 F_24 ( void )
{
int V_2 , V_41 , V_13 , V_14 ;
F_9 ( L_29 ) ;
V_2 = F_10 () ;
if ( ( F_5 ( V_38 , V_2 , 0 ,
( void * ) V_39 ) < 0 ) )
F_7 ( L_30 ) ;
while ( 1 ) {
if ( F_5 ( V_42 , V_2 , 0 , 0 ) < 0 )
F_7 ( L_31 ) ;
F_12 ( V_13 = F_13 ( V_2 , & V_14 , V_15 ) ) ;
if ( V_13 < 0 )
F_7 ( L_32 ) ;
if ( ! F_14 ( V_14 ) ||
( F_15 ( V_14 ) != ( V_32 | 0x80 ) ) )
F_8 ( L_33
L_34 , V_14 ) ;
V_41 = F_5 ( V_43 , V_2 , V_44 ,
0 ) ;
if ( V_41 == V_34 ) {
V_13 = F_5 ( V_35 , V_2 , V_44 ,
V_45 ) ;
if ( V_13 < 0 )
F_7 ( L_35
L_36 ) ;
break;
}
}
F_16 ( V_2 , 0 , 1 ) ;
F_9 ( L_18 ) ;
F_21 () ;
}
static void T_2 F_25 ( void )
{
struct V_46 V_47 ;
int V_48 = F_26 ( V_49 , & V_47 ) ;
if ( V_48 ) {
perror ( L_37 ) ;
return;
}
printf ( L_38 ) ;
if ( V_47 . V_50 == V_51 )
printf ( L_39 ) ;
else printf ( L_40 , V_47 . V_50 ) ;
printf ( L_41 ) ;
if ( V_47 . V_52 == V_51 )
printf ( L_39 ) ;
else printf ( L_40 , V_47 . V_52 ) ;
}
void T_2 F_27 ( void )
{
int V_2 ;
F_25 () ;
F_24 () ;
F_28 () ;
V_2 = F_10 () ;
if ( F_29 ( V_2 ) )
F_8 ( L_42 ) ;
F_16 ( V_2 , 1 , 1 ) ;
}
static int T_2 F_30 ( char * V_9 , int * V_20 )
{
V_23 = 1 ;
return 0 ;
}
static int T_2 F_31 ( char * V_9 , int * V_20 )
{
V_21 = 1 ;
return 0 ;
}
static int T_2 F_32 ( char * V_9 , int * V_20 )
{
V_22 = 1 ;
return 0 ;
}
static inline void F_33 ( void )
{
struct V_53 V_54 ;
int V_2 , V_13 ;
F_9 ( L_43 ) ;
V_2 = F_10 () ;
V_13 = F_5 ( V_55 , V_2 , 0 , & V_54 ) ;
if ( V_13 < 0 ) {
if ( V_56 == V_57 )
F_9 ( L_44 ) ;
else
perror ( L_45 ) ;
} else if ( V_21 )
F_9 ( L_46 ) ;
else {
V_53 = 1 ;
F_9 ( L_47 ) ;
}
F_16 ( V_2 , 1 , 1 ) ;
}
static inline void F_34 ( void )
{
#ifdef F_35
int V_2 , V_13 ;
unsigned char V_58 [ 40 ] ;
struct V_59 V_60 = (struct V_59 ) {
. V_61 = 2 ,
. V_62 = V_58 ,
. V_63 = sizeof( V_58 ) } ;
F_9 ( L_48 ) ;
V_2 = F_10 () ;
V_13 = F_5 ( F_35 , V_2 , 0 , ( unsigned long ) & V_60 ) ;
if ( V_13 < 0 ) {
if ( V_56 == V_57 )
F_9 ( L_44 ) ;
else
perror ( L_45 ) ;
} else if ( V_22 )
F_9 ( L_49 ) ;
else {
V_59 = 1 ;
F_9 ( L_47 ) ;
}
F_16 ( V_2 , 1 , 1 ) ;
#endif
}
static inline void F_36 ( void )
{
F_9 ( L_50 ) ;
if ( F_37 ( L_51 , V_64 ) < 0 )
perror ( L_45 ) ;
else if ( V_23 )
F_9 ( L_46 ) ;
else {
V_65 = 1 ;
F_9 ( L_47 ) ;
}
}
void F_38 ( void )
{
F_9 ( L_52 ) ;
F_36 () ;
F_33 () ;
F_34 () ;
if ( ! V_65 || ! V_53 || ! V_59 )
V_66 = 1 ;
}
int T_2 F_39 ( char * V_9 , int * V_20 )
{
struct V_67 * V_68 ;
struct V_69 V_70 ;
char * V_71 , * V_72 ;
int V_73 , V_74 ;
V_72 = V_9 ;
V_71 = strchr ( V_9 , ',' ) ;
if ( V_71 == NULL ) {
fprintf ( V_12 , L_53 ) ;
goto V_75;
}
* V_71 = '\0' ;
V_71 ++ ;
V_73 = F_40 ( V_71 , V_76 , 0 ) ;
if ( V_73 < 0 ) {
perror ( L_54 ) ;
goto V_75;
}
if ( F_41 ( V_73 , & V_70 ) < 0 ) {
perror ( L_55 ) ;
goto V_77;
}
V_68 = malloc ( sizeof( * V_68 ) ) ;
if ( V_68 == NULL ) {
perror ( L_56 ) ;
goto V_77;
}
V_74 = ( V_70 . V_78 + V_79 ) & ~ ( V_79 - 1 ) ;
* V_68 = ( (struct V_67 ) { . V_80 = V_81 ,
. V_72 = V_72 ,
. V_73 = V_73 ,
. V_74 = V_74 ,
. V_82 = 0 ,
. V_83 = 0 } ) ;
V_81 = V_68 ;
V_84 += V_68 -> V_74 + V_79 ;
return 0 ;
V_77:
F_42 ( V_73 ) ;
V_75:
return 1 ;
}
