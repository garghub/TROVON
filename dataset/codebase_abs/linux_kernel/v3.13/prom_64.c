void * T_1 F_1 ( unsigned long V_1 )
{
unsigned long V_2 = F_2 ( V_1 , V_3 ) ;
void * V_4 ;
if ( ! V_2 ) {
F_3 ( L_1 , V_1 ) ;
F_4 () ;
}
V_4 = F_5 ( V_2 ) ;
memset ( V_4 , 0 , V_1 ) ;
V_5 += V_1 ;
return V_4 ;
}
static void T_1 F_6 ( struct V_6 * V_7 , char * V_8 )
{
struct V_9 * V_10 ;
struct V_11 * V_12 ;
T_2 V_13 , V_14 , type ;
V_12 = F_7 ( V_7 , L_2 , NULL ) ;
if ( ! V_12 )
return;
V_10 = V_12 -> V_15 ;
if ( ! F_8 ( V_7 -> V_16 ) ) {
sprintf ( V_8 , L_3 ,
V_7 -> V_17 ,
( unsigned int ) ( V_10 -> V_18 >> 32UL ) ,
( unsigned int ) ( V_10 -> V_18 & 0xffffffffUL ) ) ;
return;
}
type = V_10 -> V_18 >> 60UL ;
V_13 = ( V_10 -> V_18 >> 32UL ) & 0x0fffffffUL ;
V_14 = ( V_10 -> V_18 & 0xffffffffUL ) ;
if ( type == 0 || type == 8 ) {
const char * V_19 = ( type == 0 ) ? L_4 : L_5 ;
if ( V_14 )
sprintf ( V_8 , L_6 ,
V_7 -> V_17 , V_19 ,
V_13 , V_14 ) ;
else
sprintf ( V_8 , L_7 ,
V_7 -> V_17 ,
V_19 ,
V_13 ) ;
} else if ( type == 12 ) {
sprintf ( V_8 , L_8 ,
V_7 -> V_17 , V_13 ) ;
}
}
static void T_1 F_9 ( struct V_6 * V_7 , char * V_8 )
{
struct V_9 * V_10 ;
struct V_11 * V_20 ;
V_20 = F_7 ( V_7 , L_2 , NULL ) ;
if ( ! V_20 )
return;
V_10 = V_20 -> V_15 ;
if ( ! F_8 ( V_7 -> V_16 ) ) {
sprintf ( V_8 , L_3 ,
V_7 -> V_17 ,
( unsigned int ) ( V_10 -> V_18 >> 32UL ) ,
( unsigned int ) ( V_10 -> V_18 & 0xffffffffUL ) ) ;
return;
}
V_20 = F_7 ( V_7 , L_9 , NULL ) ;
if ( ! V_20 )
V_20 = F_7 ( V_7 , L_10 , NULL ) ;
if ( V_20 ) {
unsigned long V_21 = 0xffffffffUL ;
if ( V_22 >= V_23 )
V_21 = 0x7fffff ;
sprintf ( V_8 , L_3 ,
V_7 -> V_17 ,
* ( T_2 * ) V_20 -> V_15 ,
( unsigned int ) ( V_10 -> V_18 & V_21 ) ) ;
}
}
static void T_1 F_10 ( struct V_6 * V_7 , char * V_8 )
{
struct V_24 * V_10 ;
struct V_11 * V_20 ;
V_20 = F_7 ( V_7 , L_2 , NULL ) ;
if ( ! V_20 )
return;
V_10 = V_20 -> V_15 ;
sprintf ( V_8 , L_3 ,
V_7 -> V_17 ,
V_10 -> V_25 ,
V_10 -> V_18 ) ;
}
static void T_1 F_11 ( struct V_6 * V_7 , char * V_8 )
{
struct V_26 * V_10 ;
struct V_11 * V_20 ;
unsigned int V_27 ;
V_20 = F_7 ( V_7 , L_2 , NULL ) ;
if ( ! V_20 )
return;
V_10 = V_20 -> V_15 ;
V_27 = ( V_10 -> V_28 >> 8 ) & 0xff ;
if ( V_27 & 0x07 ) {
sprintf ( V_8 , L_3 ,
V_7 -> V_17 ,
V_27 >> 3 ,
V_27 & 0x07 ) ;
} else {
sprintf ( V_8 , L_8 ,
V_7 -> V_17 ,
V_27 >> 3 ) ;
}
}
static void T_1 F_12 ( struct V_6 * V_7 , char * V_8 )
{
struct V_9 * V_10 ;
struct V_11 * V_20 ;
V_20 = F_7 ( V_7 , L_2 , NULL ) ;
if ( ! V_20 )
return;
V_10 = V_20 -> V_15 ;
V_20 = F_7 ( V_7 , L_9 , NULL ) ;
if ( ! V_20 )
return;
sprintf ( V_8 , L_3 ,
V_7 -> V_17 ,
* ( T_2 * ) V_20 -> V_15 ,
( unsigned int ) ( V_10 -> V_18 & 0xffffffffUL ) ) ;
}
static void T_1 F_13 ( struct V_6 * V_7 , char * V_8 )
{
struct V_11 * V_20 ;
T_2 * V_10 ;
V_20 = F_7 ( V_7 , L_2 , NULL ) ;
if ( ! V_20 )
return;
V_10 = V_20 -> V_15 ;
sprintf ( V_8 , L_8 , V_7 -> V_17 , * V_10 ) ;
}
static void T_1 F_14 ( struct V_6 * V_7 , char * V_8 )
{
struct V_9 * V_10 ;
struct V_11 * V_20 ;
V_20 = F_7 ( V_7 , L_2 , NULL ) ;
if ( ! V_20 )
return;
V_10 = V_20 -> V_15 ;
sprintf ( V_8 , L_3 ,
V_7 -> V_17 ,
( unsigned int ) ( V_10 -> V_18 >> 32UL ) ,
( unsigned int ) ( V_10 -> V_18 & 0xffffffffUL ) ) ;
}
static void T_1 F_15 ( struct V_6 * V_7 , char * V_8 )
{
struct V_11 * V_20 ;
T_2 * V_10 ;
V_20 = F_7 ( V_7 , L_2 , NULL ) ;
if ( ! V_20 )
return;
V_10 = V_20 -> V_15 ;
sprintf ( V_8 , L_3 ,
V_7 -> V_17 , V_10 [ 0 ] , V_10 [ 1 ] ) ;
}
static void T_1 F_16 ( struct V_6 * V_7 , char * V_8 )
{
struct V_11 * V_20 ;
T_2 * V_10 ;
V_20 = F_7 ( V_7 , L_2 , NULL ) ;
if ( ! V_20 )
return;
V_10 = V_20 -> V_15 ;
if ( V_20 -> V_29 == sizeof( T_2 ) || V_10 [ 1 ] == 1 ) {
sprintf ( V_8 , L_8 ,
V_7 -> V_17 , V_10 [ 0 ] ) ;
} else {
sprintf ( V_8 , L_3 ,
V_7 -> V_17 , V_10 [ 0 ] , V_10 [ 1 ] ) ;
}
}
static void T_1 F_17 ( struct V_6 * V_7 , char * V_8 )
{
struct V_11 * V_20 ;
T_2 * V_10 ;
V_20 = F_7 ( V_7 , L_2 , NULL ) ;
if ( ! V_20 )
return;
V_10 = V_20 -> V_15 ;
if ( V_10 [ 2 ] || V_10 [ 3 ] ) {
sprintf ( V_8 , L_11 ,
V_7 -> V_17 , V_10 [ 0 ] , V_10 [ 1 ] , V_10 [ 2 ] , V_10 [ 3 ] ) ;
} else {
sprintf ( V_8 , L_12 ,
V_7 -> V_17 , V_10 [ 0 ] , V_10 [ 1 ] ) ;
}
}
static void T_1 F_18 ( struct V_6 * V_7 , char * V_8 )
{
struct V_6 * V_16 = V_7 -> V_16 ;
if ( V_16 != NULL ) {
if ( ! strcmp ( V_16 -> type , L_13 ) ||
! strcmp ( V_16 -> type , L_14 ) ) {
F_11 ( V_7 , V_8 ) ;
return;
}
if ( ! strcmp ( V_16 -> type , L_15 ) ) {
F_10 ( V_7 , V_8 ) ;
return;
}
if ( ! strcmp ( V_16 -> type , L_16 ) ) {
F_12 ( V_7 , V_8 ) ;
return;
}
if ( ! strcmp ( V_16 -> type , L_17 ) ) {
F_14 ( V_7 , V_8 ) ;
return;
}
if ( ! strcmp ( V_16 -> V_17 , L_18 ) ||
! strcmp ( V_16 -> V_17 , L_19 ) ) {
F_16 ( V_7 , V_8 ) ;
return;
}
if ( ! strcmp ( V_16 -> type , L_20 ) ) {
F_15 ( V_7 , V_8 ) ;
return;
}
if ( ! strcmp ( V_16 -> type , L_21 ) ) {
F_17 ( V_7 , V_8 ) ;
return;
}
if ( ! strcmp ( V_16 -> type , L_22 ) ) {
F_13 ( V_7 , V_8 ) ;
return;
}
}
if ( V_22 == V_30 ) {
F_6 ( V_7 , V_8 ) ;
return;
} else {
F_9 ( V_7 , V_8 ) ;
}
}
char * T_1 F_19 ( struct V_6 * V_7 )
{
char V_8 [ 64 ] , * V_31 ;
V_8 [ 0 ] = '\0' ;
F_18 ( V_7 , V_8 ) ;
if ( V_8 [ 0 ] == '\0' )
strcpy ( V_8 , V_7 -> V_17 ) ;
V_31 = F_1 ( strlen ( V_8 ) + 1 ) ;
strcpy ( V_31 , V_8 ) ;
return V_31 ;
}
static const char * F_20 ( void )
{
return ( V_22 == V_32 ? L_9 : L_10 ) ;
}
bool F_21 ( struct V_6 * V_33 ,
int V_34 , unsigned int * V_35 )
{
const char * V_36 = F_20 () ;
int V_37 ;
if ( V_22 == V_30 ) {
struct V_11 * V_20 = F_7 ( V_33 , L_2 , NULL ) ;
T_2 * V_10 ;
if ( ! V_20 ) {
F_22 ( L_23 ) ;
return false ;
}
V_10 = V_20 -> V_15 ;
V_37 = V_10 [ 0 ] & 0x0fffffff ;
} else {
V_37 = F_23 ( V_33 , V_36 , - 1 ) ;
if ( V_37 < 0 ) {
V_36 = L_24 ;
V_37 = F_23 ( V_33 , V_36 , - 1 ) ;
}
if ( V_37 < 0 ) {
F_22 ( L_25 ) ;
return false ;
}
}
if ( V_37 == V_34 ) {
if ( V_35 ) {
int V_38 = F_24 ( V_34 ) . V_38 ;
if ( V_38 < 0 )
V_38 = 0 ;
* V_35 = V_38 ;
}
return true ;
}
return false ;
}
static void * F_25 ( void * (* F_26)( struct V_6 * , int , int ) , int V_39 )
{
struct V_6 * V_7 ;
const char * V_36 ;
V_36 = F_20 () ;
F_27 (dp, L_26 ) {
int V_40 = F_23 ( V_7 , V_36 , - 1 ) ;
const char * V_41 = V_36 ;
void * V_4 ;
if ( V_40 < 0 ) {
V_41 = L_24 ;
V_40 = F_23 ( V_7 , V_41 , - 1 ) ;
}
if ( V_40 < 0 ) {
F_3 ( L_27
L_28 , V_41 ) ;
F_4 () ;
}
#ifdef F_28
if ( V_40 >= V_42 ) {
F_29 ( V_43 L_29
L_30 ,
V_40 , V_42 ) ;
continue;
}
#endif
V_4 = F_26 ( V_7 , V_40 , V_39 ) ;
if ( V_4 )
return V_4 ;
}
return NULL ;
}
static void * F_30 ( struct V_6 * V_7 , int V_40 , int V_44 )
{
if ( V_44 == V_40 )
return V_7 ;
return NULL ;
}
struct V_6 * F_31 ( int V_40 )
{
return F_25 ( F_30 , V_40 ) ;
}
static void * F_32 ( struct V_6 * V_7 , int V_40 , int V_39 )
{
V_45 ++ ;
#ifdef F_28
F_33 ( V_40 , true ) ;
F_34 ( V_40 , true ) ;
#endif
return NULL ;
}
void T_1 F_35 ( void )
{
if ( V_22 == V_30 )
return;
V_45 = 0 ;
F_25 ( F_32 , 0 ) ;
}
static void * F_36 ( struct V_6 * V_7 , int V_40 , int V_39 )
{
struct V_6 * V_46 = NULL ;
int V_47 = - 1 ;
if ( F_7 ( V_7 , L_24 , NULL ) ) {
int V_48 = 2 ;
V_46 = V_7 ;
while ( V_48 -- ) {
V_46 = V_46 -> V_16 ;
if ( ! V_46 )
break;
V_47 = F_23 ( V_46 ,
L_10 , - 1 ) ;
if ( V_47 >= 0 )
break;
}
}
#ifndef F_28
if ( V_40 != F_37 () )
return NULL ;
V_40 = 0 ;
#endif
F_24 ( V_40 ) . V_49 =
F_23 ( V_7 , L_31 , 0 ) ;
if ( V_46 ) {
F_24 ( V_40 ) . V_50 =
F_23 ( V_7 , L_32 ,
16 * 1024 ) ;
F_24 ( V_40 ) . V_51 =
F_23 ( V_7 , L_33 ,
32 ) ;
F_24 ( V_40 ) . V_52 =
F_23 ( V_7 , L_34 ,
8 * 1024 ) ;
F_24 ( V_40 ) . V_53 =
F_23 ( V_7 , L_35 ,
32 ) ;
F_24 ( V_40 ) . V_54 =
F_23 ( V_7 , L_36 , 0 ) ;
F_24 ( V_40 ) . V_55 =
F_23 ( V_7 , L_37 , 0 ) ;
if ( ! F_24 ( V_40 ) . V_54 ||
! F_24 ( V_40 ) . V_55 ) {
F_24 ( V_40 ) . V_54 =
F_23 ( V_46 ,
L_36 ,
( 4 * 1024 * 1024 ) ) ;
F_24 ( V_40 ) . V_55 =
F_23 ( V_46 ,
L_37 , 64 ) ;
}
F_24 ( V_40 ) . V_56 = V_47 + 1 ;
F_24 ( V_40 ) . V_38 = V_47 ;
#ifdef F_28
V_57 = 1 ;
#endif
} else {
F_24 ( V_40 ) . V_50 =
F_23 ( V_7 , L_38 , 16 * 1024 ) ;
F_24 ( V_40 ) . V_51 =
F_23 ( V_7 , L_39 , 32 ) ;
F_24 ( V_40 ) . V_52 =
F_23 ( V_7 , L_40 , 16 * 1024 ) ;
F_24 ( V_40 ) . V_53 =
F_23 ( V_7 , L_41 , 32 ) ;
F_24 ( V_40 ) . V_54 =
F_23 ( V_7 , L_42 ,
( 4 * 1024 * 1024 ) ) ;
F_24 ( V_40 ) . V_55 =
F_23 ( V_7 , L_43 , 64 ) ;
F_24 ( V_40 ) . V_56 = 0 ;
F_24 ( V_40 ) . V_38 = - 1 ;
}
return NULL ;
}
void T_1 F_38 ( void )
{
if ( V_22 == V_30 )
return;
F_25 ( F_36 , 0 ) ;
F_39 () ;
}
void T_1 F_40 ( void )
{
char * V_58 = L_44 ;
struct V_6 * V_7 ;
const char * type ;
T_3 V_59 ;
V_60 = F_1 ( 256 ) ;
if ( F_41 ( V_61 , V_60 , 256 ) < 0 ) {
F_3 ( L_45 ) ;
F_4 () ;
}
V_62 = strrchr ( V_60 , ':' ) ;
if ( V_62 ) {
V_62 ++ ;
if ( * V_62 == '\0' )
V_62 = NULL ;
}
V_59 = F_42 ( V_61 ) ;
if ( ! V_59 ) {
F_3 ( L_46
L_47 , V_61 ) ;
F_4 () ;
}
V_7 = F_43 ( V_59 ) ;
type = F_44 ( V_7 , L_48 , NULL ) ;
if ( ! type ) {
F_3 ( L_49 ) ;
F_4 () ;
}
if ( strcmp ( type , L_50 ) && strcmp ( type , L_51 ) ) {
F_3 ( L_52
L_53 ) ;
F_4 () ;
}
V_63 = V_7 ;
F_29 ( V_58 , V_60 ) ;
}
