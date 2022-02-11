int F_1 ( T_1 * V_1 )
{
if ( V_1 && V_1 -> V_2 && V_1 -> V_2 -> V_3 )
return V_1 -> V_2 -> V_3 ( V_1 ) ;
return 0 ;
}
int F_2 ( T_1 * V_1 )
{
if ( V_1 && V_1 -> V_2 && V_1 -> V_2 -> V_4 )
return V_1 -> V_2 -> V_4 ( V_1 ) ;
return 0 ;
}
int F_3 ( T_1 * V_1 , int V_5 )
{
#ifndef F_4
if ( V_1 -> type == V_6 ) {
int V_7 = V_1 -> V_8 ;
if ( V_5 >= 0 )
V_1 -> V_8 = V_5 ;
return ( V_7 ) ;
}
#endif
#ifndef F_5
if ( V_1 -> type == V_9 ) {
int V_7 = V_1 -> V_8 ;
if ( V_5 >= 0 )
V_1 -> V_8 = V_5 ;
return ( V_7 ) ;
}
#endif
return ( 0 ) ;
}
int F_6 ( T_1 * V_10 , const T_1 * V_11 )
{
if ( V_10 -> type != V_11 -> type ) {
F_7 ( V_12 , V_13 ) ;
goto V_14;
}
if ( F_8 ( V_11 ) ) {
F_7 ( V_12 , V_15 ) ;
goto V_14;
}
if ( V_11 -> V_2 && V_11 -> V_2 -> V_16 )
return V_11 -> V_2 -> V_16 ( V_10 , V_11 ) ;
V_14:
return 0 ;
}
int F_8 ( const T_1 * V_1 )
{
if ( V_1 -> V_2 && V_1 -> V_2 -> V_17 )
return V_1 -> V_2 -> V_17 ( V_1 ) ;
return 0 ;
}
int F_9 ( const T_1 * V_18 , const T_1 * V_19 )
{
if ( V_18 -> type != V_19 -> type )
return - 1 ;
if ( V_18 -> V_2 && V_18 -> V_2 -> V_20 )
return V_18 -> V_2 -> V_20 ( V_18 , V_19 ) ;
return - 2 ;
}
int F_10 ( const T_1 * V_18 , const T_1 * V_19 )
{
if ( V_18 -> type != V_19 -> type )
return - 1 ;
if ( V_18 -> V_2 ) {
int V_7 ;
if ( V_18 -> V_2 -> V_20 ) {
V_7 = V_18 -> V_2 -> V_20 ( V_18 , V_19 ) ;
if ( V_7 <= 0 )
return V_7 ;
}
if ( V_18 -> V_2 -> V_21 )
return V_18 -> V_2 -> V_21 ( V_18 , V_19 ) ;
}
return - 2 ;
}
T_1 * F_11 ( void )
{
T_1 * V_7 ;
V_7 = ( T_1 * ) F_12 ( sizeof( T_1 ) ) ;
if ( V_7 == NULL ) {
F_7 ( V_22 , V_23 ) ;
return ( NULL ) ;
}
V_7 -> type = V_24 ;
V_7 -> V_25 = V_24 ;
V_7 -> V_26 = 1 ;
V_7 -> V_2 = NULL ;
V_7 -> V_27 = NULL ;
V_7 -> V_1 . V_28 = NULL ;
V_7 -> V_29 = NULL ;
V_7 -> V_8 = 1 ;
return ( V_7 ) ;
}
static int F_13 ( T_1 * V_1 , int type , const char * V_30 , int V_31 )
{
const T_2 * V_2 ;
T_3 * V_32 = NULL ;
if ( V_1 ) {
if ( V_1 -> V_1 . V_28 )
F_14 ( V_1 ) ;
if ( ( type == V_1 -> V_25 ) && V_1 -> V_2 )
return 1 ;
#ifndef F_15
if ( V_1 -> V_27 ) {
F_16 ( V_1 -> V_27 ) ;
V_1 -> V_27 = NULL ;
}
#endif
}
if ( V_30 )
V_2 = F_17 ( & V_32 , V_30 , V_31 ) ;
else
V_2 = F_18 ( & V_32 , type ) ;
#ifndef F_15
if ( ! V_1 && V_32 )
F_16 ( V_32 ) ;
#endif
if ( ! V_2 ) {
F_7 ( V_33 , V_34 ) ;
return 0 ;
}
if ( V_1 ) {
V_1 -> V_2 = V_2 ;
V_1 -> V_27 = V_32 ;
V_1 -> type = V_1 -> V_2 -> V_35 ;
V_1 -> V_25 = type ;
}
return 1 ;
}
int F_19 ( T_1 * V_1 , int type )
{
return F_13 ( V_1 , type , NULL , - 1 ) ;
}
int F_20 ( T_1 * V_1 , const char * V_30 , int V_31 )
{
return F_13 ( V_1 , V_24 , V_30 , V_31 ) ;
}
int F_21 ( T_1 * V_1 , int type , void * V_36 )
{
if ( ! F_19 ( V_1 , type ) )
return 0 ;
V_1 -> V_1 . V_28 = V_36 ;
return ( V_36 != NULL ) ;
}
void * F_22 ( T_1 * V_1 )
{
return V_1 -> V_1 . V_28 ;
}
int F_23 ( T_1 * V_1 , T_4 * V_36 )
{
int V_7 = F_24 ( V_1 , V_36 ) ;
if ( V_7 )
F_25 ( V_36 ) ;
return V_7 ;
}
T_4 * F_26 ( T_1 * V_1 )
{
if ( V_1 -> type != V_37 ) {
F_7 ( V_38 , V_39 ) ;
return NULL ;
}
F_25 ( V_1 -> V_1 . V_40 ) ;
return V_1 -> V_1 . V_40 ;
}
int F_27 ( T_1 * V_1 , T_5 * V_36 )
{
int V_7 = F_28 ( V_1 , V_36 ) ;
if ( V_7 )
F_29 ( V_36 ) ;
return V_7 ;
}
T_5 * F_30 ( T_1 * V_1 )
{
if ( V_1 -> type != V_6 ) {
F_7 ( V_41 , V_42 ) ;
return NULL ;
}
F_29 ( V_1 -> V_1 . V_43 ) ;
return V_1 -> V_1 . V_43 ;
}
int F_31 ( T_1 * V_1 , T_6 * V_36 )
{
int V_7 = F_32 ( V_1 , V_36 ) ;
if ( V_7 )
F_33 ( V_36 ) ;
return V_7 ;
}
T_6 * F_34 ( T_1 * V_1 )
{
if ( V_1 -> type != V_9 ) {
F_7 ( V_44 , V_45 ) ;
return NULL ;
}
F_33 ( V_1 -> V_1 . V_46 ) ;
return V_1 -> V_1 . V_46 ;
}
int F_35 ( T_1 * V_1 , T_7 * V_36 )
{
int V_7 = F_36 ( V_1 , V_36 ) ;
if ( V_7 )
F_37 ( V_36 ) ;
return V_7 ;
}
T_7 * F_38 ( T_1 * V_1 )
{
if ( V_1 -> type != V_47 && V_1 -> type != V_48 ) {
F_7 ( V_49 , V_50 ) ;
return NULL ;
}
F_37 ( V_1 -> V_1 . V_51 ) ;
return V_1 -> V_1 . V_51 ;
}
int F_39 ( int type )
{
int V_7 ;
const T_2 * V_2 ;
T_3 * V_32 ;
V_2 = F_18 ( & V_32 , type ) ;
if ( V_2 )
V_7 = V_2 -> V_35 ;
else
V_7 = V_52 ;
#ifndef F_15
if ( V_32 )
F_16 ( V_32 ) ;
#endif
return V_7 ;
}
int F_40 ( const T_1 * V_1 )
{
return V_1 -> type ;
}
int F_41 ( const T_1 * V_1 )
{
return F_39 ( V_1 -> type ) ;
}
void F_42 ( T_1 * V_53 )
{
int V_54 ;
if ( V_53 == NULL )
return;
V_54 = F_43 ( & V_53 -> V_26 , - 1 , V_55 ) ;
#ifdef F_44
F_44 ( L_1 , V_53 ) ;
#endif
if ( V_54 > 0 )
return;
#ifdef F_45
if ( V_54 < 0 ) {
fprintf ( V_56 , L_2 ) ;
abort () ;
}
#endif
F_14 ( V_53 ) ;
if ( V_53 -> V_29 )
F_46 ( V_53 -> V_29 , V_57 ) ;
F_47 ( V_53 ) ;
}
static void F_14 ( T_1 * V_53 )
{
if ( V_53 -> V_2 && V_53 -> V_2 -> V_58 ) {
V_53 -> V_2 -> V_58 ( V_53 ) ;
V_53 -> V_1 . V_28 = NULL ;
}
#ifndef F_15
if ( V_53 -> V_27 ) {
F_16 ( V_53 -> V_27 ) ;
V_53 -> V_27 = NULL ;
}
#endif
}
static int F_48 ( T_8 * V_59 , const T_1 * V_1 , int V_60 ,
const char * V_61 )
{
F_49 ( V_59 , V_60 , 128 ) ;
F_50 ( V_59 , L_3 ,
V_61 , F_51 ( V_1 -> type ) ) ;
return 1 ;
}
int F_52 ( T_8 * V_59 , const T_1 * V_1 ,
int V_60 , T_9 * V_62 )
{
if ( V_1 -> V_2 && V_1 -> V_2 -> V_63 )
return V_1 -> V_2 -> V_63 ( V_59 , V_1 , V_60 , V_62 ) ;
return F_48 ( V_59 , V_1 , V_60 , L_4 ) ;
}
int F_53 ( T_8 * V_59 , const T_1 * V_1 ,
int V_60 , T_9 * V_62 )
{
if ( V_1 -> V_2 && V_1 -> V_2 -> V_64 )
return V_1 -> V_2 -> V_64 ( V_59 , V_1 , V_60 , V_62 ) ;
return F_48 ( V_59 , V_1 , V_60 , L_5 ) ;
}
int F_54 ( T_8 * V_59 , const T_1 * V_1 ,
int V_60 , T_9 * V_62 )
{
if ( V_1 -> V_2 && V_1 -> V_2 -> V_65 )
return V_1 -> V_2 -> V_65 ( V_59 , V_1 , V_60 , V_62 ) ;
return F_48 ( V_59 , V_1 , V_60 , L_6 ) ;
}
int F_55 ( T_1 * V_1 , int * V_66 )
{
if ( ! V_1 -> V_2 || ! V_1 -> V_2 -> V_67 )
return - 2 ;
return V_1 -> V_2 -> V_67 ( V_1 , V_68 ,
0 , V_66 ) ;
}
