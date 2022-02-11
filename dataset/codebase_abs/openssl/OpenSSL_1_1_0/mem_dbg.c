static void F_1 ( T_1 * V_1 )
{
if ( ! V_1 )
return;
if ( -- ( V_1 -> V_2 ) <= 0 ) {
F_1 ( V_1 -> V_3 ) ;
F_2 ( V_1 ) ;
}
}
int F_3 ( int V_4 )
{
#ifdef F_4
return V_4 - V_4 ;
#else
int V_5 = V_6 ;
if ( ! F_5 ( & V_7 , V_8 ) )
return - 1 ;
F_6 ( V_9 ) ;
switch ( V_4 ) {
default:
break;
case V_10 :
V_6 = V_10 | V_11 ;
V_12 = 0 ;
break;
case V_13 :
V_6 = 0 ;
V_12 = 0 ;
break;
case V_14 :
if ( V_6 & V_10 ) {
T_2 V_15 = F_7 () ;
if ( ! V_12
|| ! F_8 ( V_16 , V_15 ) ) {
F_9 ( V_9 ) ;
F_6 ( V_17 ) ;
F_6 ( V_9 ) ;
V_6 &= ~ V_11 ;
V_16 = V_15 ;
}
V_12 ++ ;
}
break;
case V_11 :
if ( V_6 & V_10 ) {
if ( V_12 ) {
V_12 -- ;
if ( V_12 == 0 ) {
V_6 |= V_11 ;
F_9 ( V_17 ) ;
}
}
}
break;
}
F_9 ( V_9 ) ;
return ( V_5 ) ;
#endif
}
static int F_10 ( void )
{
int V_5 = 0 ;
T_2 V_15 ;
if ( V_6 & V_10 ) {
if ( ! F_5 ( & V_7 , V_8 ) )
return 0 ;
V_15 = F_7 () ;
F_11 ( V_9 ) ;
V_5 = ( V_6 & V_11 )
|| ! F_8 ( V_16 , V_15 ) ;
F_9 ( V_9 ) ;
}
return ( V_5 ) ;
}
static int F_12 ( const T_3 * V_18 , const T_3 * V_19 )
{
#ifdef F_13
const char * V_20 = ( const char * ) V_18 -> V_21 , * V_22 = ( const char * ) V_19 -> V_21 ;
if ( V_20 == V_22 )
return 0 ;
else if ( V_20 > V_22 )
return 1 ;
else
return - 1 ;
#else
return ( const char * ) V_18 -> V_21 - ( const char * ) V_19 -> V_21 ;
#endif
}
static unsigned long F_14 ( const T_3 * V_18 )
{
T_4 V_5 ;
V_5 = ( T_4 ) V_18 -> V_21 ;
V_5 = V_5 * 17851 + ( V_5 >> 14 ) * 7 + ( V_5 >> 4 ) * 251 ;
return ( V_5 ) ;
}
static int F_15 ( void )
{
T_1 * V_23 = NULL ;
if ( ! F_5 ( & V_7 , V_8 ) )
return 0 ;
V_23 = ( T_1 * ) F_16 ( & V_24 ) ;
if ( V_23 != NULL ) {
T_1 * V_3 = V_23 -> V_3 ;
if ( V_3 != NULL ) {
V_3 -> V_2 ++ ;
F_17 ( & V_24 , V_3 ) ;
} else {
F_17 ( & V_24 , NULL ) ;
}
if ( -- ( V_23 -> V_2 ) <= 0 ) {
V_23 -> V_3 = NULL ;
if ( V_3 != NULL )
V_3 -> V_2 -- ;
F_2 ( V_23 ) ;
}
return 1 ;
}
return 0 ;
}
int F_18 ( const char * V_25 , const char * V_26 , int line )
{
T_1 * V_27 , * V_28 ;
int V_5 = 0 ;
if ( F_10 () ) {
F_3 ( V_14 ) ;
if ( ! F_5 ( & V_7 , V_8 )
|| ( V_27 = F_19 ( sizeof( * V_27 ) ) ) == NULL )
goto V_29;
V_27 -> V_30 = F_7 () ;
V_27 -> V_26 = V_26 ;
V_27 -> line = line ;
V_27 -> V_25 = V_25 ;
V_27 -> V_2 = 1 ;
V_27 -> V_3 = NULL ;
V_28 = ( T_1 * ) F_16 ( & V_24 ) ;
F_17 ( & V_24 , V_27 ) ;
if ( V_28 != NULL )
V_27 -> V_3 = V_28 ;
V_5 = 1 ;
V_29:
F_3 ( V_11 ) ;
}
return ( V_5 ) ;
}
int F_20 ( void )
{
int V_5 = 0 ;
if ( F_10 () ) {
F_3 ( V_14 ) ;
V_5 = F_15 () ;
F_3 ( V_11 ) ;
}
return ( V_5 ) ;
}
void F_21 ( void * V_21 , T_4 V_31 , int V_32 ,
const char * V_26 , int line )
{
T_3 * V_33 , * V_34 ;
T_1 * V_28 ;
switch ( V_32 & 127 ) {
case 0 :
break;
case 1 :
if ( V_21 == NULL )
break;
if ( F_10 () ) {
F_3 ( V_14 ) ;
if ( ! F_5 ( & V_7 , V_8 )
|| ( V_33 = F_19 ( sizeof( * V_33 ) ) ) == NULL ) {
F_2 ( V_21 ) ;
F_3 ( V_11 ) ;
return;
}
if ( V_35 == NULL ) {
if ( ( V_35 = F_22 ( F_14 , F_12 ) ) == NULL ) {
F_2 ( V_21 ) ;
F_2 ( V_33 ) ;
V_21 = NULL ;
goto V_29;
}
}
V_33 -> V_21 = V_21 ;
V_33 -> V_26 = V_26 ;
V_33 -> line = line ;
V_33 -> V_31 = V_31 ;
V_33 -> V_30 = F_7 () ;
if ( V_36 == V_37 ) {
V_33 -> V_36 = V_36 ;
}
V_33 -> V_36 = V_36 ++ ;
# ifndef F_23
V_33 -> V_38 = F_24 ( V_33 -> V_39 , F_25 ( V_33 -> V_39 ) ) ;
# endif
V_33 -> time = time ( NULL ) ;
V_28 = ( T_1 * ) F_16 ( & V_24 ) ;
V_33 -> V_40 = V_28 ;
if ( V_28 != NULL )
V_28 -> V_2 ++ ;
if ( ( V_34 = F_26 ( V_35 , V_33 ) ) != NULL ) {
if ( V_34 -> V_40 != NULL ) {
V_34 -> V_40 -> V_2 -- ;
}
F_2 ( V_34 ) ;
}
V_29:
F_3 ( V_11 ) ;
}
break;
}
return;
}
void F_27 ( void * V_21 , int V_32 ,
const char * V_26 , int line )
{
T_3 V_33 , * V_41 ;
switch ( V_32 ) {
case 0 :
if ( V_21 == NULL )
break;
if ( F_10 () && ( V_35 != NULL ) ) {
F_3 ( V_14 ) ;
V_33 . V_21 = V_21 ;
V_41 = F_28 ( V_35 , & V_33 ) ;
if ( V_41 != NULL ) {
F_1 ( V_41 -> V_40 ) ;
F_2 ( V_41 ) ;
}
F_3 ( V_11 ) ;
}
break;
case 1 :
break;
}
}
void F_29 ( void * V_42 , void * V_43 , T_4 V_31 ,
int V_32 , const char * V_26 , int line )
{
T_3 V_33 , * V_41 ;
switch ( V_32 ) {
case 0 :
break;
case 1 :
if ( V_43 == NULL )
break;
if ( V_42 == NULL ) {
F_21 ( V_43 , V_31 , 128 | V_32 , V_26 , line ) ;
break;
}
if ( F_10 () ) {
F_3 ( V_14 ) ;
V_33 . V_21 = V_42 ;
V_41 = F_28 ( V_35 , & V_33 ) ;
if ( V_41 != NULL ) {
V_41 -> V_21 = V_43 ;
V_41 -> V_31 = V_31 ;
#ifndef F_23
V_41 -> V_38 = F_24 ( V_41 -> V_39 , F_25 ( V_41 -> V_39 ) ) ;
#endif
( void ) F_26 ( V_35 , V_41 ) ;
}
F_3 ( V_11 ) ;
}
break;
}
return;
}
static void F_30 ( const T_3 * V_33 , T_5 * V_44 )
{
char V_45 [ 1024 ] ;
char * V_46 = V_45 ;
T_1 * V_47 ;
int V_48 ;
struct V_49 * V_50 = NULL ;
union {
T_2 V_51 ;
unsigned long V_52 ;
} V_51 ;
T_2 V_53 ;
#define F_31 (sizeof buf - (size_t)(bufp - buf))
V_50 = localtime ( & V_33 -> time ) ;
F_32 ( V_46 , F_31 , L_1 ,
V_50 -> V_54 , V_50 -> V_55 , V_50 -> V_56 ) ;
V_46 += strlen ( V_46 ) ;
F_32 ( V_46 , F_31 , L_2 ,
V_33 -> V_36 , V_33 -> V_26 , V_33 -> line ) ;
V_46 += strlen ( V_46 ) ;
V_51 . V_52 = 0 ;
V_51 . V_51 = V_33 -> V_30 ;
F_32 ( V_46 , F_31 , L_3 , V_51 . V_52 ) ;
V_46 += strlen ( V_46 ) ;
F_32 ( V_46 , F_31 , L_4 ,
V_33 -> V_31 , V_33 -> V_21 ) ;
V_46 += strlen ( V_46 ) ;
F_33 ( V_44 -> V_57 , V_45 ) ;
V_44 -> V_58 ++ ;
V_44 -> V_59 += V_33 -> V_31 ;
V_47 = V_33 -> V_40 ;
V_48 = 0 ;
if ( V_47 ) {
V_53 = V_47 -> V_30 ;
do {
int V_60 ;
int V_61 ;
V_48 ++ ;
memset ( V_45 , '>' , V_48 ) ;
V_51 . V_52 = 0 ;
V_51 . V_51 = V_47 -> V_30 ;
F_32 ( V_45 + V_48 , sizeof V_45 - V_48 ,
L_5 ,
V_51 . V_52 , V_47 -> V_26 ,
V_47 -> line ) ;
V_60 = strlen ( V_45 ) ;
V_61 = strlen ( V_47 -> V_25 ) ;
if ( 128 - V_60 - 3 < V_61 ) {
memcpy ( V_45 + V_60 , V_47 -> V_25 , 128 - V_60 - 3 ) ;
V_60 = 128 - 3 ;
} else {
F_34 ( V_45 + V_60 , V_47 -> V_25 , sizeof V_45 - V_60 ) ;
V_60 = strlen ( V_45 ) ;
}
F_32 ( V_45 + V_60 , sizeof V_45 - V_60 , L_6 ) ;
F_33 ( V_44 -> V_57 , V_45 ) ;
V_47 = V_47 -> V_3 ;
}
while ( V_47 && F_8 ( V_47 -> V_30 , V_53 ) );
}
#ifndef F_23
{
T_4 V_62 ;
char * * V_63 = F_35 ( V_33 -> V_39 , V_33 -> V_38 ) ;
for ( V_62 = 0 ; V_62 < V_33 -> V_38 ; V_62 ++ )
fprintf ( V_64 , L_7 , V_63 [ V_62 ] ) ;
free ( V_63 ) ;
}
#endif
}
int F_36 ( T_6 * V_19 )
{
T_5 V_65 ;
F_37 ( V_19 ) ;
F_38 () ;
if ( ! F_5 ( & V_7 , V_8 ) )
return - 1 ;
F_3 ( V_14 ) ;
V_65 . V_57 = V_19 ;
V_65 . V_59 = 0 ;
V_65 . V_58 = 0 ;
if ( V_35 != NULL )
F_39 ( V_35 , F_30 , & V_65 ) ;
if ( V_65 . V_58 != 0 ) {
F_40 ( V_19 , L_8 , V_65 . V_59 , V_65 . V_58 ) ;
} else {
int V_66 ;
F_6 ( V_9 ) ;
V_66 = V_6 ;
V_6 = V_13 ;
F_41 ( V_35 ) ;
V_35 = NULL ;
V_6 = V_66 ;
F_9 ( V_9 ) ;
}
F_3 ( V_13 ) ;
F_42 ( & V_24 ) ;
F_43 ( V_9 ) ;
F_43 ( V_17 ) ;
V_9 = NULL ;
V_17 = NULL ;
return V_65 . V_58 == 0 ? 1 : 0 ;
}
int F_44 ( T_7 * V_67 )
{
T_6 * V_19 ;
int V_5 ;
F_3 ( V_14 ) ;
V_19 = F_45 ( F_46 () ) ;
F_3 ( V_11 ) ;
if ( V_19 == NULL )
return - 1 ;
F_47 ( V_19 , V_67 , V_68 ) ;
V_5 = F_36 ( V_19 ) ;
F_48 ( V_19 ) ;
return V_5 ;
}
