T_1 * F_1 ( const T_2 * V_1 )
{
T_1 * V_2 = F_2 ( sizeof( * V_2 ) ) ;
if ( V_2 == NULL ) {
F_3 ( V_3 , V_4 ) ;
return ( NULL ) ;
}
V_2 -> V_1 = V_1 ;
V_2 -> V_5 = 1 ;
V_2 -> V_6 = 1 ;
if ( ! F_4 ( V_7 , V_2 , & V_2 -> V_8 ) )
goto V_9;
V_2 -> V_10 = F_5 () ;
if ( V_2 -> V_10 == NULL ) {
F_3 ( V_3 , V_4 ) ;
F_6 ( V_7 , V_2 , & V_2 -> V_8 ) ;
goto V_9;
}
if ( V_1 -> V_11 != NULL && ! V_1 -> V_11 ( V_2 ) ) {
F_3 ( V_3 , V_12 ) ;
F_6 ( V_7 , V_2 , & V_2 -> V_8 ) ;
F_7 ( V_2 -> V_10 ) ;
goto V_9;
}
return V_2 ;
V_9:
F_8 ( V_2 ) ;
return NULL ;
}
int F_9 ( T_1 * V_13 )
{
int V_14 ;
if ( V_13 == NULL )
return 0 ;
if ( F_10 ( & V_13 -> V_6 , - 1 , & V_14 , V_13 -> V_10 ) <= 0 )
return 0 ;
F_11 ( L_1 , V_13 ) ;
if ( V_14 > 0 )
return 1 ;
F_12 ( V_14 < 0 ) ;
if ( ( V_13 -> V_15 != NULL ) &&
( ( V_14 = ( int ) V_13 -> V_15 ( V_13 , V_16 , NULL , 0 , 0L , 1L ) ) <= 0 ) )
return V_14 ;
if ( ( V_13 -> V_1 != NULL ) && ( V_13 -> V_1 -> V_17 != NULL ) )
V_13 -> V_1 -> V_17 ( V_13 ) ;
F_6 ( V_7 , V_13 , & V_13 -> V_8 ) ;
F_7 ( V_13 -> V_10 ) ;
F_8 ( V_13 ) ;
return 1 ;
}
void F_13 ( T_1 * V_13 , void * V_18 )
{
V_13 -> V_18 = V_18 ;
}
void * F_14 ( T_1 * V_13 )
{
return V_13 -> V_18 ;
}
void F_15 ( T_1 * V_13 , int V_19 )
{
V_13 -> V_19 = V_19 ;
}
int F_16 ( T_1 * V_13 )
{
return V_13 -> V_19 ;
}
void F_17 ( T_1 * V_13 , int V_20 )
{
V_13 -> V_5 = V_20 ;
}
int F_18 ( T_1 * V_13 )
{
return V_13 -> V_5 ;
}
void F_19 ( T_1 * V_13 )
{
F_9 ( V_13 ) ;
}
int F_20 ( T_1 * V_13 )
{
int V_14 ;
if ( F_10 ( & V_13 -> V_6 , 1 , & V_14 , V_13 -> V_10 ) <= 0 )
return 0 ;
F_11 ( L_1 , V_13 ) ;
F_12 ( V_14 < 2 ) ;
return ( ( V_14 > 1 ) ? 1 : 0 ) ;
}
void F_21 ( T_1 * V_21 , int V_22 )
{
V_21 -> V_22 &= ~ V_22 ;
}
int F_22 ( const T_1 * V_21 , int V_22 )
{
return ( V_21 -> V_22 & V_22 ) ;
}
void F_23 ( T_1 * V_21 , int V_22 )
{
V_21 -> V_22 |= V_22 ;
}
void F_24 ( T_1 * V_21 ,
long (* F_25) ( struct V_23 * , int , const char * , int ,
long , long ) )
{
V_21 -> V_15 = F_25 ;
}
void F_26 ( T_1 * V_21 , char * V_24 )
{
V_21 -> V_25 = V_24 ;
}
char * F_27 ( const T_1 * V_21 )
{
return V_21 -> V_25 ;
}
const char * F_28 ( const T_1 * V_21 )
{
return V_21 -> V_1 -> V_26 ;
}
int F_29 ( const T_1 * V_21 )
{
return V_21 -> V_1 -> type ;
}
int F_30 ( T_1 * V_21 , void * V_27 , int V_28 )
{
int V_14 ;
long (* F_25) ( T_1 * , int , const char * , int , long , long );
if ( ( V_21 == NULL ) || ( V_21 -> V_1 == NULL ) || ( V_21 -> V_1 -> V_29 == NULL ) ) {
F_3 ( V_30 , V_31 ) ;
return ( - 2 ) ;
}
F_25 = V_21 -> V_15 ;
if ( ( F_25 != NULL ) &&
( ( V_14 = ( int ) F_25 ( V_21 , V_32 , V_27 , V_28 , 0L , 1L ) ) <= 0 ) )
return ( V_14 ) ;
if ( ! V_21 -> V_19 ) {
F_3 ( V_30 , V_33 ) ;
return ( - 2 ) ;
}
V_14 = V_21 -> V_1 -> V_29 ( V_21 , V_27 , V_28 ) ;
if ( V_14 > 0 )
V_21 -> V_34 += ( V_35 ) V_14 ;
if ( F_25 != NULL )
V_14 = ( int ) F_25 ( V_21 , V_32 | V_36 , V_27 , V_28 , 0L , ( long ) V_14 ) ;
return ( V_14 ) ;
}
int F_31 ( T_1 * V_21 , const void * V_37 , int V_38 )
{
int V_14 ;
long (* F_25) ( T_1 * , int , const char * , int , long , long );
if ( V_21 == NULL )
return ( 0 ) ;
F_25 = V_21 -> V_15 ;
if ( ( V_21 -> V_1 == NULL ) || ( V_21 -> V_1 -> V_39 == NULL ) ) {
F_3 ( V_40 , V_31 ) ;
return ( - 2 ) ;
}
if ( ( F_25 != NULL ) &&
( ( V_14 = ( int ) F_25 ( V_21 , V_41 , V_37 , V_38 , 0L , 1L ) ) <= 0 ) )
return ( V_14 ) ;
if ( ! V_21 -> V_19 ) {
F_3 ( V_40 , V_33 ) ;
return ( - 2 ) ;
}
V_14 = V_21 -> V_1 -> V_39 ( V_21 , V_37 , V_38 ) ;
if ( V_14 > 0 )
V_21 -> V_42 += ( V_35 ) V_14 ;
if ( F_25 != NULL )
V_14 = ( int ) F_25 ( V_21 , V_41 | V_36 , V_37 , V_38 , 0L , ( long ) V_14 ) ;
return ( V_14 ) ;
}
int F_32 ( T_1 * V_21 , const char * V_37 )
{
int V_14 ;
long (* F_25) ( T_1 * , int , const char * , int , long , long );
if ( ( V_21 == NULL ) || ( V_21 -> V_1 == NULL ) || ( V_21 -> V_1 -> V_43 == NULL ) ) {
F_3 ( V_44 , V_31 ) ;
return ( - 2 ) ;
}
F_25 = V_21 -> V_15 ;
if ( ( F_25 != NULL ) && ( ( V_14 = ( int ) F_25 ( V_21 , V_45 , V_37 , 0 , 0L , 1L ) ) <= 0 ) )
return ( V_14 ) ;
if ( ! V_21 -> V_19 ) {
F_3 ( V_44 , V_33 ) ;
return ( - 2 ) ;
}
V_14 = V_21 -> V_1 -> V_43 ( V_21 , V_37 ) ;
if ( V_14 > 0 )
V_21 -> V_42 += ( V_35 ) V_14 ;
if ( F_25 != NULL )
V_14 = ( int ) F_25 ( V_21 , V_45 | V_36 , V_37 , 0 , 0L , ( long ) V_14 ) ;
return ( V_14 ) ;
}
int F_33 ( T_1 * V_21 , char * V_37 , int V_38 )
{
int V_14 ;
long (* F_25) ( T_1 * , int , const char * , int , long , long );
if ( ( V_21 == NULL ) || ( V_21 -> V_1 == NULL ) || ( V_21 -> V_1 -> V_46 == NULL ) ) {
F_3 ( V_47 , V_31 ) ;
return ( - 2 ) ;
}
F_25 = V_21 -> V_15 ;
if ( ( F_25 != NULL ) && ( ( V_14 = ( int ) F_25 ( V_21 , V_48 , V_37 , V_38 , 0L , 1L ) ) <= 0 ) )
return ( V_14 ) ;
if ( ! V_21 -> V_19 ) {
F_3 ( V_47 , V_33 ) ;
return ( - 2 ) ;
}
V_14 = V_21 -> V_1 -> V_46 ( V_21 , V_37 , V_38 ) ;
if ( F_25 != NULL )
V_14 = ( int ) F_25 ( V_21 , V_48 | V_36 , V_37 , V_38 , 0L , ( long ) V_14 ) ;
return ( V_14 ) ;
}
int F_34 ( T_1 * V_21 , int V_49 , int V_50 )
{
if ( V_49 < 0 )
V_49 = 0 ;
if ( V_49 > V_50 )
V_49 = V_50 ;
while ( V_49 -- )
if ( F_32 ( V_21 , L_2 ) != 1 )
return 0 ;
return 1 ;
}
long F_35 ( T_1 * V_21 , int V_51 , long V_52 , int V_53 )
{
int V_14 ;
V_14 = V_53 ;
return ( F_36 ( V_21 , V_51 , V_52 , ( char * ) & V_14 ) ) ;
}
void * F_37 ( T_1 * V_21 , int V_51 , long V_52 )
{
void * V_54 = NULL ;
if ( F_36 ( V_21 , V_51 , V_52 , ( char * ) & V_54 ) <= 0 )
return ( NULL ) ;
else
return ( V_54 ) ;
}
long F_36 ( T_1 * V_21 , int V_51 , long V_52 , void * V_55 )
{
long V_56 ;
long (* F_25) ( T_1 * , int , const char * , int , long , long );
if ( V_21 == NULL )
return ( 0 ) ;
if ( ( V_21 -> V_1 == NULL ) || ( V_21 -> V_1 -> V_57 == NULL ) ) {
F_3 ( V_58 , V_31 ) ;
return ( - 2 ) ;
}
F_25 = V_21 -> V_15 ;
if ( ( F_25 != NULL ) &&
( ( V_56 = F_25 ( V_21 , V_59 , V_55 , V_51 , V_52 , 1L ) ) <= 0 ) )
return ( V_56 ) ;
V_56 = V_21 -> V_1 -> V_57 ( V_21 , V_51 , V_52 , V_55 ) ;
if ( F_25 != NULL )
V_56 = F_25 ( V_21 , V_59 | V_36 , V_55 , V_51 , V_52 , V_56 ) ;
return ( V_56 ) ;
}
long F_38 ( T_1 * V_21 , int V_51 ,
void (* F_39) ( struct V_23 * , int , const char * , int ,
long , long ) )
{
long V_56 ;
long (* F_25) ( T_1 * , int , const char * , int , long , long );
if ( V_21 == NULL )
return ( 0 ) ;
if ( ( V_21 -> V_1 == NULL ) || ( V_21 -> V_1 -> V_60 == NULL ) ) {
F_3 ( V_61 , V_31 ) ;
return ( - 2 ) ;
}
F_25 = V_21 -> V_15 ;
if ( ( F_25 != NULL ) &&
( ( V_56 = F_25 ( V_21 , V_59 , ( void * ) & F_39 , V_51 , 0 , 1L ) ) <= 0 ) )
return ( V_56 ) ;
V_56 = V_21 -> V_1 -> V_60 ( V_21 , V_51 , F_39 ) ;
if ( F_25 != NULL )
V_56 = F_25 ( V_21 , V_59 | V_36 , ( void * ) & F_39 , V_51 , 0 , V_56 ) ;
return ( V_56 ) ;
}
T_3 F_40 ( T_1 * V_2 )
{
return F_36 ( V_2 , V_62 , 0 , NULL ) ;
}
T_3 F_41 ( T_1 * V_2 )
{
return F_36 ( V_2 , V_63 , 0 , NULL ) ;
}
T_1 * F_42 ( T_1 * V_21 , T_1 * V_2 )
{
T_1 * V_64 ;
if ( V_21 == NULL )
return ( V_2 ) ;
V_64 = V_21 ;
while ( V_64 -> V_65 != NULL )
V_64 = V_64 -> V_65 ;
V_64 -> V_65 = V_2 ;
if ( V_2 != NULL )
V_2 -> V_66 = V_64 ;
F_36 ( V_21 , V_67 , 0 , V_64 ) ;
return ( V_21 ) ;
}
T_1 * F_43 ( T_1 * V_21 )
{
T_1 * V_56 ;
if ( V_21 == NULL )
return ( NULL ) ;
V_56 = V_21 -> V_65 ;
F_36 ( V_21 , V_68 , 0 , V_21 ) ;
if ( V_21 -> V_66 != NULL )
V_21 -> V_66 -> V_65 = V_21 -> V_65 ;
if ( V_21 -> V_65 != NULL )
V_21 -> V_65 -> V_66 = V_21 -> V_66 ;
V_21 -> V_65 = NULL ;
V_21 -> V_66 = NULL ;
return ( V_56 ) ;
}
T_1 * F_44 ( T_1 * V_2 , int * V_69 )
{
T_1 * V_21 , * V_70 ;
V_21 = V_70 = V_2 ;
for (; ; ) {
if ( ! F_45 ( V_21 ) )
break;
V_70 = V_21 ;
V_21 = V_21 -> V_65 ;
if ( V_21 == NULL )
break;
}
if ( V_69 != NULL )
* V_69 = V_70 -> V_71 ;
return ( V_70 ) ;
}
int F_46 ( T_1 * V_2 )
{
return ( V_2 -> V_71 ) ;
}
void F_47 ( T_1 * V_2 , int V_69 )
{
V_2 -> V_71 = V_69 ;
}
T_1 * F_48 ( T_1 * V_2 , int type )
{
int V_72 , V_73 ;
if ( V_2 == NULL )
return NULL ;
V_73 = type & 0xff ;
do {
if ( V_2 -> V_1 != NULL ) {
V_72 = V_2 -> V_1 -> type ;
if ( ! V_73 ) {
if ( V_72 & type )
return ( V_2 ) ;
} else if ( V_72 == type )
return ( V_2 ) ;
}
V_2 = V_2 -> V_65 ;
} while ( V_2 != NULL );
return ( NULL ) ;
}
T_1 * F_49 ( T_1 * V_21 )
{
if ( V_21 == NULL )
return NULL ;
return V_21 -> V_65 ;
}
void F_50 ( T_1 * V_21 , T_1 * V_74 )
{
V_21 -> V_65 = V_74 ;
}
void F_51 ( T_1 * V_2 )
{
T_1 * V_21 ;
int V_75 ;
while ( V_2 != NULL ) {
V_21 = V_2 ;
V_75 = V_21 -> V_6 ;
V_2 = V_2 -> V_65 ;
F_9 ( V_21 ) ;
if ( V_75 > 1 )
break;
}
}
T_1 * F_52 ( T_1 * V_37 )
{
T_1 * V_56 = NULL , * V_76 = NULL , * V_2 , * V_77 ;
for ( V_2 = V_37 ; V_2 != NULL ; V_2 = V_2 -> V_65 ) {
if ( ( V_77 = F_1 ( V_2 -> V_1 ) ) == NULL )
goto V_9;
V_77 -> V_15 = V_2 -> V_15 ;
V_77 -> V_25 = V_2 -> V_25 ;
V_77 -> V_19 = V_2 -> V_19 ;
V_77 -> V_5 = V_2 -> V_5 ;
V_77 -> V_22 = V_2 -> V_22 ;
V_77 -> V_78 = V_2 -> V_78 ;
if ( ! F_53 ( V_2 , ( char * ) V_77 ) ) {
F_9 ( V_77 ) ;
goto V_9;
}
if ( ! F_54 ( V_7 , & V_77 -> V_8 ,
& V_2 -> V_8 ) ) {
F_9 ( V_77 ) ;
goto V_9;
}
if ( V_56 == NULL ) {
V_76 = V_77 ;
V_56 = V_76 ;
} else {
F_42 ( V_76 , V_77 ) ;
V_76 = V_77 ;
}
}
return ( V_56 ) ;
V_9:
F_51 ( V_56 ) ;
return ( NULL ) ;
}
void F_55 ( T_1 * V_21 )
{
F_23 ( V_21 , F_56 ( V_21 -> V_65 ) ) ;
V_21 -> V_71 = V_21 -> V_65 -> V_71 ;
}
int F_57 ( T_1 * V_2 , int V_79 , void * V_80 )
{
return ( F_58 ( & ( V_2 -> V_8 ) , V_79 , V_80 ) ) ;
}
void * F_59 ( T_1 * V_2 , int V_79 )
{
return ( F_60 ( & ( V_2 -> V_8 ) , V_79 ) ) ;
}
V_35 F_61 ( T_1 * V_2 )
{
if ( V_2 )
return V_2 -> V_34 ;
return 0 ;
}
V_35 F_62 ( T_1 * V_2 )
{
if ( V_2 )
return V_2 -> V_42 ;
return 0 ;
}
void F_63 ( T_1 * V_2 )
{
F_6 ( V_7 , V_2 , & V_2 -> V_8 ) ;
}
void F_64 ( void )
{
#ifndef F_65
F_66 () ;
F_7 ( V_81 ) ;
V_81 = NULL ;
#endif
F_7 ( V_82 ) ;
V_82 = NULL ;
}
