int
F_1 ( int * V_1 , char * * V_2 , int * V_3 ,
char * V_4 , ... )
{
T_1 args ;
int V_5 ;
F_2 ( L_1 , V_2 , * V_2 ) ;
va_start ( args , V_4 ) ;
V_5 = vsnprintf ( * V_2 , * V_3 , V_4 , args ) ;
va_end ( args ) ;
if ( V_5 >= * V_3 ) {
* V_2 += * V_3 ;
* V_1 += * V_3 ;
* V_3 = 0 ;
F_3 ( L_2 ) ;
return - 1 ;
}
* V_3 -= V_5 ;
* V_2 += V_5 ;
* V_1 += V_5 ;
return V_5 ;
}
int
F_4 ( int type , void * V_6 ,
struct V_7 * V_8 )
{
F_5 ( L_3 , type , V_6 ) ;
switch ( type ) {
case 2 :
if ( V_6 ) {
if ( ! V_9 )
F_6 ( & V_10 ) ;
V_9 = V_6 ;
} else {
if ( V_9 )
F_7 ( & V_10 ) ;
V_9 = NULL ;
}
break;
default:
F_3 ( L_4 , type ) ;
return 0 ;
}
if ( V_8 )
F_8 ( V_8 , L_5 , L_6 ,
V_11 , NULL ) ;
return 1 ;
}
int
F_9 ( T_2 V_12 ,
const char * V_13 ,
int (* F_10)( struct V_14 * ) ,
unsigned long V_15 ,
int (* F_11)( unsigned long V_16 ) ,
int (* F_12)( void * V_17 ,
unsigned char * V_18 ,
T_3 V_19 , T_4 V_20 ) ,
struct V_7 * V_8 )
{
struct V_21 * V_22 ;
F_5 ( L_7 ,
& V_12 , F_10 ) ;
if ( ! F_10 ) {
F_3 ( L_8 , & V_12 ) ;
return 0 ;
}
if ( ! F_11 ) {
F_3 ( L_9 ,
& V_12 ) ;
return 0 ;
}
if ( ! F_12 ) {
F_3 ( L_10 ,
& V_12 ) ;
return 0 ;
}
V_22 = F_13 ( V_12 ,
V_13 ,
F_10 ,
V_15 ,
F_11 , F_12 ) ;
if ( ! V_22 ) {
F_3 ( L_11 , & V_12 ) ;
return 0 ;
}
F_6 ( & V_10 ) ;
if ( V_8 ) {
F_8 ( V_8 , L_5 ,
L_6 , V_11 , NULL ) ;
return 1 ;
}
F_3 ( L_12 , & V_12 ) ;
return 0 ;
}
int
F_14 ( T_2 V_12 )
{
F_5 ( L_13 , & V_12 ) ;
if ( F_15 ( V_12 ) < 0 ) {
F_3 ( L_14 ,
& V_12 ) ;
return 0 ;
}
F_7 ( & V_10 ) ;
return 1 ;
}
unsigned int
F_16 ( unsigned char * V_23 , void * V_24 ,
unsigned int V_25 ,
unsigned int V_26 ,
struct V_27 V_28 [] )
{
unsigned int V_29 = 0 , V_30 , V_31 , V_32 = 0 , V_33 ;
struct V_34 * V_35 = V_24 ;
V_33 = F_17 ( V_35 ) -> V_36 ;
while ( V_25 ) {
if ( V_29 == V_26 ) {
F_3 ( L_15 ,
V_23 , V_26 , V_29 ) ;
return - 1 ;
}
V_28 [ V_29 ] . V_37 =
F_18 ( F_19 ( V_35 -> V_38 + V_32 ) ) ;
V_28 [ V_29 ] . V_39 =
( unsigned long ) ( V_35 -> V_38 + V_32 ) & V_40 ;
V_31 =
F_20 ( V_25 ,
( unsigned int ) ( V_41 - V_28 [ V_29 ] . V_39 ) ) ;
V_28 [ V_29 ] . V_42 = V_31 ;
V_25 -= V_31 ;
V_32 += V_31 ;
V_29 ++ ;
}
if ( ! V_33 )
goto V_43;
if ( ( V_29 + V_33 ) > V_26 ) {
F_3 ( L_16 ,
V_23 , V_26 , V_29 + V_33 ) ;
return - 1 ;
}
for ( V_30 = 0 ; V_30 < V_33 ; V_30 ++ ) {
V_29 = F_21 ( F_18 (
F_22 ( & F_17 ( V_35 ) -> V_28 [ V_30 ] ) ) ,
F_17 ( V_35 ) -> V_28 [ V_30 ] .
V_44 ,
F_17 ( V_35 ) -> V_28 [ V_30 ] .
V_31 , V_29 , V_26 ,
V_28 ) ;
if ( V_29 == 0 ) {
F_3 ( L_17 ) ;
return - 1 ;
}
}
V_43: if ( F_17 ( V_35 ) -> V_45 ) {
struct V_34 * V_46 ;
int V_47 ;
for ( V_46 = F_17 ( V_35 ) -> V_45 ; V_46 ;
V_46 = V_46 -> V_48 ) {
V_47 = F_16 ( L_18 ,
V_46 ,
V_46 -> V_5 - V_46 -> V_49 ,
V_26 - V_29 ,
& V_28 [ V_29 ] ) ;
if ( V_47 == - 1 ) {
F_3 ( L_19 ) ;
return - 1 ;
}
V_29 += V_47 ;
}
}
return V_29 ;
}
struct V_21 *
F_13 ( T_2 V_12 ,
const char * V_13 ,
int (* F_10)( struct V_14 * ) ,
unsigned long V_15 ,
int (* F_11)( unsigned long V_16 ) ,
int (* F_12)
( void * V_17 , unsigned char * V_50 , T_3 V_51 ,
T_4 V_20 ) )
{
struct V_21 * V_52 = NULL ;
V_52 = F_23 ( sizeof( * V_52 ) , V_53 ) ;
if ( ! V_52 )
return NULL ;
V_52 -> V_12 = V_12 ;
V_52 -> F_10 = F_10 ;
V_52 -> V_15 = V_15 ;
V_52 -> F_11 = F_11 ;
V_52 -> F_12 = F_12 ;
if ( V_13 )
strncpy ( V_52 -> V_13 , V_13 ,
sizeof( V_52 -> V_13 ) - 1 ) ;
F_24 ( & V_54 ) ;
F_25 ( & V_52 -> V_55 , & V_56 ) ;
F_26 ( & V_54 ) ;
return V_52 ;
}
struct V_21 *
F_27 ( T_2 V_12 )
{
struct V_57 * V_58 , * V_59 ;
struct V_21 * V_60 = NULL ;
F_24 ( & V_54 ) ;
F_28 (lelt, tmp, &req_handler_info_list) {
V_60 = F_29 ( V_58 , struct V_21 , V_55 ) ;
if ( F_30 ( V_60 -> V_12 , V_12 ) == 0 ) {
F_26 ( & V_54 ) ;
return V_60 ;
}
}
F_26 ( & V_54 ) ;
return NULL ;
}
int
F_15 ( T_2 V_12 )
{
struct V_57 * V_58 , * V_59 ;
struct V_21 * V_60 = NULL ;
int V_52 = - 1 ;
F_24 ( & V_54 ) ;
F_28 (lelt, tmp, &req_handler_info_list) {
V_60 = F_29 ( V_58 , struct V_21 , V_55 ) ;
if ( F_30 ( V_60 -> V_12 , V_12 ) == 0 ) {
F_31 ( V_58 ) ;
F_32 ( V_60 ) ;
V_52 ++ ;
}
}
F_26 ( & V_54 ) ;
return V_52 ;
}
