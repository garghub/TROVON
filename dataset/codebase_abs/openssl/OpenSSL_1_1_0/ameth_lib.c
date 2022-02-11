void main ()
{
int V_1 ;
for ( V_1 = 0 ; V_1 < F_1 ( V_2 ) ; V_1 ++ )
fprintf ( V_3 , L_1 , V_1 ,
V_2 [ V_1 ] -> V_4 ,
F_2 ( V_2 [ V_1 ] -> V_4 ) ) ;
}
static int F_3 ( const T_1 * const * V_5 ,
const T_1 * const * V_6 )
{
return ( ( * V_5 ) -> V_4 - ( * V_6 ) -> V_4 ) ;
}
int F_4 ( void )
{
int V_7 = F_1 ( V_2 ) ;
if ( V_8 )
V_7 += F_5 ( V_8 ) ;
return V_7 ;
}
const T_1 * F_6 ( int V_9 )
{
int V_7 = F_1 ( V_2 ) ;
if ( V_9 < 0 )
return NULL ;
if ( V_9 < V_7 )
return V_2 [ V_9 ] ;
V_9 -= V_7 ;
return F_7 ( V_8 , V_9 ) ;
}
static const T_1 * F_8 ( int type )
{
T_1 V_10 ;
const T_1 * V_11 = & V_10 , * * V_12 ;
V_10 . V_4 = type ;
if ( V_8 ) {
int V_9 ;
V_9 = F_9 ( V_8 , & V_10 ) ;
if ( V_9 >= 0 )
return F_7 ( V_8 , V_9 ) ;
}
V_12 = F_10 ( & V_11 , V_2 , F_1 ( V_2 ) ) ;
if ( ! V_12 || ! * V_12 )
return NULL ;
return * V_12 ;
}
const T_1 * F_11 ( T_2 * * V_13 , int type )
{
const T_1 * V_11 ;
for (; ; ) {
V_11 = F_8 ( type ) ;
if ( ! V_11 || ! ( V_11 -> V_14 & V_15 ) )
break;
type = V_11 -> V_16 ;
}
if ( V_13 ) {
#ifndef F_12
T_2 * V_17 ;
V_17 = F_13 ( type ) ;
if ( V_17 ) {
* V_13 = V_17 ;
return F_14 ( V_17 , type ) ;
}
#endif
* V_13 = NULL ;
}
return V_11 ;
}
const T_1 * F_15 ( T_2 * * V_13 ,
const char * V_18 , int V_19 )
{
int V_1 ;
const T_1 * V_20 ;
if ( V_19 == - 1 )
V_19 = strlen ( V_18 ) ;
if ( V_13 ) {
#ifndef F_12
T_2 * V_17 ;
V_20 = F_16 ( & V_17 , V_18 , V_19 ) ;
if ( V_20 ) {
if ( ! F_17 ( V_17 ) )
V_20 = NULL ;
F_18 ( V_17 ) ;
* V_13 = V_17 ;
return V_20 ;
}
#endif
* V_13 = NULL ;
}
for ( V_1 = 0 ; V_1 < F_4 () ; V_1 ++ ) {
V_20 = F_6 ( V_1 ) ;
if ( V_20 -> V_14 & V_15 )
continue;
if ( ( ( int ) strlen ( V_20 -> V_21 ) == V_19 )
&& ( strncasecmp ( V_20 -> V_21 , V_18 , V_19 ) == 0 ) )
return V_20 ;
}
return NULL ;
}
int F_19 ( const T_1 * V_20 )
{
if ( V_8 == NULL ) {
V_8 = F_20 ( F_3 ) ;
if ( V_8 == NULL )
return 0 ;
}
if ( ! F_21 ( V_8 , V_20 ) )
return 0 ;
F_22 ( V_8 ) ;
return 1 ;
}
int F_23 ( int V_22 , int V_23 )
{
T_1 * V_20 ;
V_20 = F_24 ( V_23 , V_15 , NULL , NULL ) ;
if ( V_20 == NULL )
return 0 ;
V_20 -> V_16 = V_22 ;
if ( ! F_19 ( V_20 ) ) {
F_25 ( V_20 ) ;
return 0 ;
}
return 1 ;
}
int F_26 ( int * V_24 , int * V_25 ,
int * V_26 , const char * * V_27 ,
const char * * V_28 ,
const T_1 * V_20 )
{
if ( ! V_20 )
return 0 ;
if ( V_24 )
* V_24 = V_20 -> V_4 ;
if ( V_25 )
* V_25 = V_20 -> V_16 ;
if ( V_26 )
* V_26 = V_20 -> V_14 ;
if ( V_27 )
* V_27 = V_20 -> V_29 ;
if ( V_28 )
* V_28 = V_20 -> V_21 ;
return 1 ;
}
const T_1 * F_27 ( const T_3 * V_30 )
{
return V_30 -> V_20 ;
}
T_1 * F_24 ( int V_31 , int V_32 ,
const char * V_21 , const char * V_29 )
{
T_1 * V_20 = F_28 ( sizeof( * V_20 ) ) ;
if ( V_20 == NULL )
return NULL ;
V_20 -> V_4 = V_31 ;
V_20 -> V_16 = V_31 ;
V_20 -> V_14 = V_32 | V_33 ;
if ( V_29 ) {
V_20 -> V_29 = F_29 ( V_29 ) ;
if ( ! V_20 -> V_29 )
goto V_34;
}
if ( V_21 ) {
V_20 -> V_21 = F_29 ( V_21 ) ;
if ( ! V_20 -> V_21 )
goto V_34;
}
return V_20 ;
V_34:
F_25 ( V_20 ) ;
return NULL ;
}
void F_30 ( T_1 * V_35 ,
const T_1 * V_36 )
{
V_35 -> V_37 = V_36 -> V_37 ;
V_35 -> V_38 = V_36 -> V_38 ;
V_35 -> V_39 = V_36 -> V_39 ;
V_35 -> V_40 = V_36 -> V_40 ;
V_35 -> V_41 = V_36 -> V_41 ;
V_35 -> V_42 = V_36 -> V_42 ;
V_35 -> V_43 = V_36 -> V_43 ;
V_35 -> V_44 = V_36 -> V_44 ;
V_35 -> V_45 = V_36 -> V_45 ;
V_35 -> V_46 = V_36 -> V_46 ;
V_35 -> V_47 = V_36 -> V_47 ;
V_35 -> V_48 = V_36 -> V_48 ;
V_35 -> V_49 = V_36 -> V_49 ;
V_35 -> V_50 = V_36 -> V_50 ;
V_35 -> V_51 = V_36 -> V_51 ;
V_35 -> V_52 = V_36 -> V_52 ;
V_35 -> V_53 = V_36 -> V_53 ;
V_35 -> V_54 = V_36 -> V_54 ;
V_35 -> V_55 = V_36 -> V_55 ;
V_35 -> V_56 = V_36 -> V_56 ;
V_35 -> V_57 = V_36 -> V_57 ;
}
void F_25 ( T_1 * V_20 )
{
if ( V_20 && ( V_20 -> V_14 & V_33 ) ) {
F_31 ( V_20 -> V_21 ) ;
F_31 ( V_20 -> V_29 ) ;
F_31 ( V_20 ) ;
}
}
void F_32 ( T_1 * V_20 ,
int (* V_37) ( T_3 * V_58 ,
T_4 * V_59 ) ,
int (* V_38) ( T_4 * V_59 ,
const T_3 * V_58 ) ,
int (* V_39) ( const T_3 * V_5 ,
const T_3 * V_6 ) ,
int (* V_40) ( T_5 * V_60 ,
const T_3 * V_30 ,
int V_61 , T_6 * V_62 ) ,
int (* V_46) ( const T_3 * V_58 ) ,
int (* V_47) ( const T_3 * V_58 ) )
{
V_20 -> V_37 = V_37 ;
V_20 -> V_38 = V_38 ;
V_20 -> V_39 = V_39 ;
V_20 -> V_40 = V_40 ;
V_20 -> V_46 = V_46 ;
V_20 -> V_47 = V_47 ;
}
void F_33 ( T_1 * V_20 ,
int (* V_41) ( T_3 * V_58 ,
const T_7
* V_63 ) ,
int (* V_42) ( T_7 * V_64 ,
const T_3 * V_58 ) ,
int (* V_43) ( T_5 * V_60 ,
const T_3 * V_30 ,
int V_61 ,
T_6 * V_62 ) )
{
V_20 -> V_41 = V_41 ;
V_20 -> V_42 = V_42 ;
V_20 -> V_43 = V_43 ;
}
void F_34 ( T_1 * V_20 ,
int (* V_48) ( T_3 * V_30 ,
const unsigned char * * V_65 ,
int V_66 ) ,
int (* V_49) ( const T_3 * V_30 ,
unsigned char * * V_65 ) ,
int (* V_50) ( const T_3 * V_58 ) ,
int (* V_51) ( T_3 * V_22 ,
const T_3 * V_23 ) ,
int (* V_52) ( const T_3 * V_5 ,
const T_3 * V_6 ) ,
int (* V_53) ( T_5 * V_60 ,
const T_3 * V_30 ,
int V_61 , T_6 * V_62 ) )
{
V_20 -> V_48 = V_48 ;
V_20 -> V_49 = V_49 ;
V_20 -> V_50 = V_50 ;
V_20 -> V_51 = V_51 ;
V_20 -> V_52 = V_52 ;
V_20 -> V_53 = V_53 ;
}
void F_35 ( T_1 * V_20 ,
void (* V_54) ( T_3 * V_30 ) )
{
V_20 -> V_54 = V_54 ;
}
void F_36 ( T_1 * V_20 ,
int (* V_55) ( T_3 * V_30 , int V_67 ,
long V_68 , void * V_69 ) )
{
V_20 -> V_55 = V_55 ;
}
void F_37 ( T_1 * V_20 ,
int (* F_38) ( const T_3
* V_58 ) )
{
V_20 -> F_38 = F_38 ;
}
void F_39 ( T_1 * V_20 ,
int (* V_57) ( T_8 * V_70 ,
const T_9 * V_71 ,
void * V_72 ,
T_10 * V_5 ,
T_11 * V_73 ,
T_3 * V_30 ) ,
int (* V_56) ( T_8 * V_70 ,
const T_9 * V_71 ,
void * V_72 ,
T_10 * V_74 ,
T_10 * V_75 ,
T_11 * V_73 ) )
{
V_20 -> V_56 = V_56 ;
V_20 -> V_57 = V_57 ;
}
