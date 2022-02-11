static long F_1 ( long V_1 , long * V_2 ,
struct V_3 * * V_4 )
{
struct V_3 * V_5 , * V_6 ;
unsigned long V_7 ;
while ( V_1 ) {
V_7 = F_2 ( V_8 ) ;
if ( ! V_7 )
break;
F_3 ( & V_9 ) ;
V_5 = * V_4 ;
if ( ! V_5 || V_5 -> V_10 >= V_11 ) {
F_4 ( & V_9 ) ;
V_6 = (struct V_3 * )
F_2 ( V_8 ) ;
if ( ! V_6 ) {
F_5 ( V_7 ) ;
break;
}
F_3 ( & V_9 ) ;
V_5 = * V_4 ;
if ( ! V_5 || V_5 -> V_10 >= V_11 ) {
V_6 -> V_12 = V_5 ;
V_6 -> V_10 = 0 ;
V_5 = V_6 ;
* V_4 = V_5 ;
} else
F_5 ( ( unsigned long ) V_6 ) ;
}
F_6 ( V_7 >> V_13 , 1 ) ;
V_5 -> V_14 [ V_5 -> V_10 ++ ] = V_7 ;
( * V_2 ) ++ ;
F_4 ( & V_9 ) ;
V_1 -- ;
}
return V_1 ;
}
static long F_7 ( long V_1 , long * V_2 , struct V_3 * * V_4 )
{
struct V_3 * V_5 ;
unsigned long V_7 ;
F_3 ( & V_9 ) ;
V_5 = * V_4 ;
while ( V_1 ) {
if ( ! V_5 || V_5 -> V_10 <= 0 )
break;
V_7 = V_5 -> V_14 [ -- V_5 -> V_10 ] ;
if ( V_5 -> V_10 == 0 ) {
V_5 = V_5 -> V_12 ;
F_5 ( ( unsigned long ) * V_4 ) ;
* V_4 = V_5 ;
}
F_5 ( V_7 ) ;
( * V_2 ) -- ;
V_1 -- ;
}
F_4 ( & V_9 ) ;
return V_1 ;
}
static int F_8 ( struct V_15 * V_16 ,
unsigned long V_17 , void * V_18 )
{
unsigned long * V_19 = V_18 ;
long V_1 = 256 ;
V_1 = F_7 ( V_1 , & V_20 , & V_21 ) ;
if ( V_1 > 0 )
V_1 = F_7 ( V_1 , & V_22 , & V_23 ) ;
V_24 = V_22 ;
V_25 = V_20 ;
* V_19 += 256 - V_1 ;
return V_26 ;
}
static int F_9 ( void * V_17 )
{
int V_27 ;
while ( 1 ) {
V_27 = F_10 ( V_28 ,
( ! V_29 && ( V_22 != V_24 ||
V_20 != V_25 ) ) ||
F_11 () ) ;
if ( F_11 () || V_27 == - V_30 ) {
V_24 = V_22 ;
V_25 = V_20 ;
break;
}
if ( V_24 > V_22 ) {
if ( F_1 ( 1 , & V_22 , & V_23 ) )
V_24 = V_22 ;
} else if ( V_24 < V_22 ) {
F_7 ( 1 , & V_22 , & V_23 ) ;
}
if ( V_25 > V_20 ) {
if ( F_1 ( 1 , & V_20 ,
& V_21 ) )
V_25 = V_20 ;
} else if ( V_25 < V_20 ) {
F_7 ( 1 , & V_20 ,
& V_21 ) ;
}
if ( V_20 > 0 && ! F_12 ( & V_31 ) )
F_13 () ;
}
return 0 ;
}
static void F_14 ( void )
{
F_15 ( & V_28 ) ;
}
static void F_13 ( void )
{
if ( V_25 <= 0 || V_32 <= 0 ) {
if ( F_12 ( & V_31 ) )
F_16 ( & V_31 ) ;
return;
}
if ( F_12 ( & V_31 ) ) {
if ( F_17 ( & V_31 , V_33 + V_32 * V_34 ) )
return;
}
V_31 . V_35 = V_36 ;
V_31 . V_37 = 0 ;
V_31 . V_38 = V_33 + V_32 * V_34 ;
F_18 ( & V_31 ) ;
}
static void V_36 ( unsigned long V_39 )
{
long V_1 ;
V_1 = V_25 - V_40 ;
if ( V_1 < 0 )
V_25 = 0 ;
else
V_25 = V_1 ;
F_14 () ;
F_13 () ;
}
static void F_19 ( long V_1 )
{
V_24 = V_1 ;
F_14 () ;
}
static long F_20 ( void )
{
return V_22 ;
}
static void F_21 ( long V_1 )
{
V_25 += V_1 ;
F_14 () ;
}
static long F_22 ( void )
{
return V_20 ;
}
static void F_23 ( long V_1 , long V_41 )
{
V_40 = V_1 ;
V_32 = V_41 ;
F_13 () ;
}
static int F_24 ( char * V_42 , char * * V_43 )
{
char * V_44 ;
for ( V_44 = V_42 ; * V_44 == ' ' || * V_44 == '\t' ; V_44 ++ )
;
* V_43 = V_44 ;
return V_44 != V_42 ;
}
static int F_25 ( struct V_45 * V_46 , int V_47 ,
void T_1 * V_48 , T_2 * V_49 , T_3 * V_50 )
{
char V_51 [ 16 ] , * V_52 ;
unsigned int V_53 ;
long V_1 ;
if ( ! * V_49 || ( * V_50 && ! V_47 ) ) {
* V_49 = 0 ;
return 0 ;
}
if ( V_47 ) {
V_53 = * V_49 ;
if ( F_26 ( V_51 , V_48 ,
V_53 > sizeof( V_51 ) ? sizeof( V_51 ) : V_53 ) )
return - V_54 ;
V_51 [ sizeof( V_51 ) - 1 ] = '\0' ;
F_24 ( V_51 , & V_52 ) ;
V_1 = F_27 ( V_52 , & V_52 , 0 ) ;
if ( V_46 == & V_55 [ 0 ] )
F_19 ( V_1 ) ;
else
F_21 ( V_1 ) ;
} else {
if ( V_46 == & V_55 [ 0 ] )
V_1 = F_20 () ;
else
V_1 = F_22 () ;
V_53 = sprintf ( V_51 , L_1 , V_1 ) ;
if ( V_53 > * V_49 )
V_53 = * V_49 ;
if ( F_28 ( V_48 , V_51 , V_53 ) )
return - V_54 ;
}
* V_49 = V_53 ;
* V_50 += V_53 ;
return 0 ;
}
static int F_29 ( struct V_45 * V_46 , int V_47 ,
void T_1 * V_48 , T_2 * V_49 , T_3 * V_50 )
{
char V_51 [ 64 ] , * V_52 ;
long V_1 , V_41 ;
unsigned int V_53 ;
if ( ! * V_49 || ( * V_50 && ! V_47 ) ) {
* V_49 = 0 ;
return 0 ;
}
if ( V_47 ) {
V_53 = * V_49 ;
if ( F_26 ( V_51 , V_48 ,
V_53 > sizeof( V_51 ) ? sizeof( V_51 ) : V_53 ) )
return - V_54 ;
V_51 [ sizeof( V_51 ) - 1 ] = '\0' ;
F_24 ( V_51 , & V_52 ) ;
V_1 = F_27 ( V_52 , & V_52 , 0 ) ;
F_24 ( V_52 , & V_52 ) ;
V_41 = F_27 ( V_52 , & V_52 , 0 ) ;
F_23 ( V_1 , V_41 ) ;
} else {
V_53 = sprintf ( V_51 , L_2 ,
V_40 , V_32 ) ;
if ( V_53 > * V_49 )
V_53 = * V_49 ;
if ( F_28 ( V_48 , V_51 , V_53 ) )
return - V_54 ;
}
* V_49 = V_53 ;
* V_50 += V_53 ;
return 0 ;
}
static void F_30 ( const char * V_56 , char * V_57 )
{
long V_1 , V_41 ;
if ( strlen ( V_58 ) > 0 && strcmp ( V_56 , V_58 ) != 0 )
return;
if ( ! F_24 ( V_57 + strlen ( V_59 ) , & V_57 ) )
return;
if ( strncmp ( V_57 , L_3 , 6 ) == 0 ) {
if ( ! F_24 ( V_57 + 6 , & V_57 ) )
return;
V_1 = F_27 ( V_57 , & V_57 , 0 ) ;
F_24 ( V_57 , & V_57 ) ;
if ( * V_57 == '\0' )
F_19 ( V_1 ) ;
} else if ( strncmp ( V_57 , L_4 , 7 ) == 0 ) {
if ( ! F_24 ( V_57 + 7 , & V_57 ) )
return;
V_1 = F_27 ( V_57 , & V_57 , 0 ) ;
F_24 ( V_57 , & V_57 ) ;
if ( * V_57 == '\0' )
F_21 ( V_1 ) ;
} else if ( strncmp ( V_57 , L_5 , 5 ) == 0 ) {
if ( ! F_24 ( V_57 + 5 , & V_57 ) )
return;
V_1 = F_27 ( V_57 , & V_57 , 0 ) ;
if ( ! F_24 ( V_57 , & V_57 ) )
return;
V_41 = F_27 ( V_57 , & V_57 , 0 ) ;
F_24 ( V_57 , & V_57 ) ;
if ( * V_57 == '\0' )
F_23 ( V_1 , V_41 ) ;
}
}
static int F_31 ( void )
{
V_29 = 1 ;
F_7 ( V_22 , & V_22 , & V_23 ) ;
F_7 ( V_20 , & V_20 , & V_21 ) ;
return 0 ;
}
static int F_32 ( void )
{
V_29 = 0 ;
F_14 () ;
return 0 ;
}
static int F_33 ( struct V_15 * V_60 ,
unsigned long V_61 , void * V_62 )
{
switch ( V_61 ) {
case V_63 :
return F_32 () ;
case V_64 :
return F_31 () ;
default:
return V_65 ;
}
}
static int T_4 F_34 ( void )
{
int V_27 = - V_66 ;
V_67 = F_35 ( V_68 ) ;
if ( ! V_67 )
goto V_69;
#ifdef F_36
if ( V_58 ) {
int V_53 = strlen ( V_58 ) ;
while ( V_53 -- )
V_58 [ V_53 ] = toupper ( V_58 [ V_53 ] ) ;
} else {
V_58 = V_70 ;
}
V_27 = F_37 ( V_59 , F_30 ) ;
if ( V_27 < 0 )
goto V_71;
#endif
V_27 = F_38 ( & V_72 ) ;
if ( V_27 < 0 )
goto V_73;
V_27 = F_39 ( & V_74 ) ;
if ( V_27 )
goto V_75;
V_76 = F_40 ( F_9 , NULL , L_6 ) ;
if ( ! F_41 ( V_76 ) )
return 0 ;
V_27 = F_42 ( V_76 ) ;
F_43 ( & V_74 ) ;
V_75:
F_44 ( & V_72 ) ;
V_73:
#ifdef F_36
F_45 ( V_59 , F_30 ) ;
V_71:
#endif
F_46 ( V_67 ) ;
V_69:
F_47 ( & V_31 ) ;
return V_27 ;
}
static void T_5 F_48 ( void )
{
F_46 ( V_67 ) ;
#ifdef F_36
F_45 ( V_59 , F_30 ) ;
#endif
F_43 ( & V_74 ) ;
F_44 ( & V_72 ) ;
F_49 ( V_76 ) ;
F_47 ( & V_31 ) ;
F_7 ( V_22 , & V_22 , & V_23 ) ;
F_7 ( V_20 , & V_20 , & V_21 ) ;
}
