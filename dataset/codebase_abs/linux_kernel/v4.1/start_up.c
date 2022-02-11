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
return 0 ;
}
static void T_2 F_20 ( void )
{
unsigned long V_22 [ V_23 ] ;
int V_2 , V_13 , V_14 , V_24 = 0 ;
F_9 ( L_10 ) ;
V_25 = 0 ;
V_2 = F_10 () ;
if ( F_5 ( V_26 , V_2 , 0 , 0 ) < 0 )
goto V_27;
F_12 ( V_13 = F_13 ( V_2 , & V_14 , V_15 ) ) ;
if ( V_13 < 0 )
F_7 ( L_11 ) ;
if ( ! F_14 ( V_14 ) || ( F_15 ( V_14 ) != V_28 ) )
F_8 ( L_12 ,
V_14 ) ;
if ( F_5 ( V_29 , V_2 , 0 , V_22 ) < 0 )
F_7 ( L_13 ) ;
if ( F_21 ( V_22 ) != V_30 ) {
F_9 ( L_14
L_15 , F_21 ( V_22 ) , V_30 ) ;
goto V_27;
}
V_13 = F_5 ( V_31 , V_2 , V_32 , F_2 () ) ;
if ( V_13 < 0 ) {
F_9 ( L_16
L_17 ) ;
goto V_27;
}
if ( F_16 ( V_2 , 0 , 0 ) < 0 )
goto V_33;
V_25 = 1 ;
F_9 ( L_18 ) ;
F_22 ( ! V_21 ) ;
F_9 ( L_19 ) ;
V_2 = F_10 () ;
if ( ( F_5 ( V_34 , V_2 , 0 ,
( void * ) V_35 ) < 0 ) )
F_7 ( L_20 ) ;
while ( 1 ) {
V_24 ++ ;
if ( F_5 ( V_36 , V_2 , 0 , 0 ) < 0 )
goto V_27;
F_12 ( V_13 = F_13 ( V_2 , & V_14 , V_15 ) ) ;
if ( V_13 < 0 )
F_7 ( L_21 ) ;
if ( F_14 ( V_14 ) &&
( F_15 ( V_14 ) == ( V_28 | 0x80 ) ) ) {
if ( ! V_24 ) {
F_9 ( L_22
L_23 ) ;
goto V_27;
}
V_13 = F_5 ( V_31 , V_2 , V_32 ,
F_2 () ) ;
if ( V_13 < 0 )
F_7 ( L_24
L_25 ) ;
break;
}
else if ( F_14 ( V_14 ) && ( F_15 ( V_14 ) == V_28 ) )
V_24 ++ ;
else {
F_9 ( L_26
L_27 ,
V_14 ) ;
goto V_27;
}
}
if ( F_16 ( V_2 , 0 , 0 ) < 0 )
goto V_33;
V_25 = 2 ;
F_9 ( L_18 ) ;
if ( ! V_21 )
F_22 ( V_25 ) ;
return;
V_27:
F_16 ( V_2 , 1 , 0 ) ;
V_33:
F_9 ( L_28 ) ;
}
static void T_2 F_23 ( void )
{
int V_2 , V_37 , V_13 , V_14 ;
F_9 ( L_29 ) ;
V_2 = F_10 () ;
if ( ( F_5 ( V_34 , V_2 , 0 ,
( void * ) V_35 ) < 0 ) )
F_7 ( L_30 ) ;
while ( 1 ) {
if ( F_5 ( V_38 , V_2 , 0 , 0 ) < 0 )
F_7 ( L_31 ) ;
F_12 ( V_13 = F_13 ( V_2 , & V_14 , V_15 ) ) ;
if ( V_13 < 0 )
F_7 ( L_32 ) ;
if ( ! F_14 ( V_14 ) ||
( F_15 ( V_14 ) != ( V_28 | 0x80 ) ) )
F_8 ( L_33
L_34 , V_14 ) ;
V_37 = F_5 ( V_39 , V_2 , V_40 ,
0 ) ;
if ( V_37 == V_30 ) {
V_13 = F_5 ( V_31 , V_2 , V_40 ,
V_41 ) ;
if ( V_13 < 0 )
F_7 ( L_35
L_36 ) ;
break;
}
}
F_16 ( V_2 , 0 , 1 ) ;
F_9 ( L_18 ) ;
F_20 () ;
}
static void T_2 F_24 ( void )
{
struct V_42 V_43 ;
int V_44 = F_25 ( V_45 , & V_43 ) ;
if ( V_44 ) {
perror ( L_37 ) ;
return;
}
printf ( L_38 ) ;
if ( V_43 . V_46 == V_47 )
printf ( L_39 ) ;
else printf ( L_40 , V_43 . V_46 ) ;
printf ( L_41 ) ;
if ( V_43 . V_48 == V_47 )
printf ( L_39 ) ;
else printf ( L_40 , V_43 . V_48 ) ;
}
void T_2 F_26 ( void )
{
int V_2 ;
F_24 () ;
F_23 () ;
F_27 () ;
V_2 = F_10 () ;
if ( F_28 ( V_2 ) )
F_8 ( L_42 ) ;
F_16 ( V_2 , 1 , 1 ) ;
}
int T_2 F_29 ( char * V_9 , int * V_20 )
{
struct V_49 * V_50 ;
struct V_51 V_52 ;
char * V_53 , * V_54 ;
int V_55 , V_56 ;
V_54 = V_9 ;
V_53 = strchr ( V_9 , ',' ) ;
if ( V_53 == NULL ) {
fprintf ( V_12 , L_43 ) ;
goto V_57;
}
* V_53 = '\0' ;
V_53 ++ ;
V_55 = F_30 ( V_53 , V_58 , 0 ) ;
if ( V_55 < 0 ) {
perror ( L_44 ) ;
goto V_57;
}
if ( F_31 ( V_55 , & V_52 ) < 0 ) {
perror ( L_45 ) ;
goto V_59;
}
V_50 = malloc ( sizeof( * V_50 ) ) ;
if ( V_50 == NULL ) {
perror ( L_46 ) ;
goto V_59;
}
V_56 = ( V_52 . V_60 + V_61 ) & ~ ( V_61 - 1 ) ;
* V_50 = ( (struct V_49 ) { . V_62 = V_63 ,
. V_54 = V_54 ,
. V_55 = V_55 ,
. V_56 = V_56 ,
. V_64 = 0 ,
. V_65 = 0 } ) ;
V_63 = V_50 ;
V_66 += V_50 -> V_56 + V_61 ;
return 0 ;
V_59:
F_32 ( V_55 ) ;
V_57:
return 1 ;
}
