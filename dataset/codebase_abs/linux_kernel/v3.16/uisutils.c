int
F_1 ( int * V_1 , char * * V_2 , int * V_3 ,
char * V_4 , ... )
{
T_1 args ;
int V_5 ;
F_2 ( L_1 , V_2 , * V_2 ) ;
va_start ( args , V_4 ) ;
V_5 = vsnprintf ( * V_2 , * V_3 , V_4 , args ) ;
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
T_2 * V_7 )
{
F_5 ( L_3 , type , V_6 ) ;
switch ( type ) {
case 2 :
if ( V_6 ) {
if ( ! V_8 )
F_6 ( & V_9 ) ;
V_8 = V_6 ;
} else {
if ( V_8 )
F_7 ( & V_9 ) ;
V_8 = NULL ;
}
break;
default:
F_3 ( L_4 , type ) ;
return 0 ;
}
if ( V_7 )
F_8 ( V_7 ,
L_5 , L_6 ,
V_10 , NULL , __DATE__ , __TIME__ ) ;
return 1 ;
}
int
F_9 ( T_3 V_11 ,
const char * V_12 ,
int (* F_10)( struct V_13 * ) ,
unsigned long V_14 ,
int (* F_11)( unsigned long
V_15 ) ,
int (* F_12)
( void * V_16 , unsigned char * V_17 ,
T_4 V_18 , T_5 V_19 ) ,
T_2 * V_7 )
{
T_6 * V_20 ;
int V_21 = 0 ;
F_5 ( L_7 ,
& V_11 , F_10 ) ;
if ( ! F_10 ) {
F_3 ( L_8 , & V_11 ) ;
goto V_22;
}
if ( ! F_11 ) {
F_3 ( L_9 ,
& V_11 ) ;
goto V_22;
}
if ( ! F_12 ) {
F_3 ( L_10 ,
& V_11 ) ;
goto V_22;
}
V_20 = F_13 ( V_11 ,
V_12 ,
F_10 ,
V_14 ,
F_11 , F_12 ) ;
if ( ! V_20 ) {
F_3 ( L_11 , & V_11 ) ;
goto V_22;
}
F_6 ( & V_9 ) ;
V_21 = 1 ;
V_22:
if ( V_21 ) {
if ( V_7 )
F_8 ( V_7 ,
L_5 , L_6 ,
V_10 , NULL ,
__DATE__ , __TIME__ ) ;
} else
F_3 ( L_12 , & V_11 ) ;
return V_21 ;
}
int
F_14 ( T_3 V_11 )
{
int V_21 = 0 ;
F_5 ( L_13 , & V_11 ) ;
if ( F_15 ( V_11 ) < 0 ) {
F_3 ( L_14 ,
& V_11 ) ;
goto V_22;
}
F_7 ( & V_9 ) ;
V_21 = 1 ;
V_22:
if ( ! V_21 )
F_3 ( L_15 , & V_11 ) ;
return V_21 ;
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
F_3 ( L_16 ,
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
if ( V_33 ) {
if ( ( V_29 + V_33 ) > V_26 ) {
F_3 ( L_17 ,
V_23 , V_26 , V_29 + V_33 ) ;
return - 1 ;
}
for ( V_30 = 0 ; V_30 < V_33 ; V_30 ++ ) {
V_29 = F_21 ( F_18 ( F_22 ( & F_17 ( V_35 ) -> V_28 [ V_30 ] ) ) ,
F_17 ( V_35 ) -> V_28 [ V_30 ] .
V_43 ,
F_17 ( V_35 ) -> V_28 [ V_30 ] .
V_31 , V_29 , V_26 ,
V_28 ) ;
if ( V_29 == 0 ) {
F_3 ( L_18 ) ;
return - 1 ;
}
}
}
if ( F_17 ( V_35 ) -> V_44 ) {
struct V_34 * V_45 ;
int V_46 ;
for ( V_45 = F_17 ( V_35 ) -> V_44 ; V_45 ;
V_45 = V_45 -> V_47 ) {
V_46 = F_16 ( L_19 ,
V_45 ,
V_45 -> V_5 -
V_45 -> V_48 ,
V_26 - V_29 ,
& V_28 [ V_29 ] ) ;
if ( V_46 == - 1 ) {
F_3 ( L_20 ) ;
return - 1 ;
}
V_29 += V_46 ;
}
}
return V_29 ;
}
T_6 *
F_13 ( T_3 V_11 ,
const char * V_12 ,
int (* F_10)( struct V_13 * ) ,
unsigned long V_14 ,
int (* F_11)( unsigned long V_15 ) ,
int (* F_12)
( void * V_16 , unsigned char * V_17 , T_4 V_18 , T_5 V_19 ) )
{
T_6 * V_21 = NULL ;
V_21 = F_23 ( sizeof( * V_21 ) , V_49 ) ;
if ( ! V_21 )
return NULL ;
V_21 -> V_11 = V_11 ;
V_21 -> F_10 = F_10 ;
V_21 -> V_14 = V_14 ;
V_21 -> F_11 = F_11 ;
V_21 -> F_12 = F_12 ;
if ( V_12 )
strncpy ( V_21 -> V_12 , V_12 ,
sizeof( V_21 -> V_12 ) - 1 ) ;
F_24 ( & V_50 ) ;
F_25 ( & ( V_21 -> V_51 ) , & V_52 ) ;
F_26 ( & V_50 ) ;
return V_21 ;
}
T_6 *
F_27 ( T_3 V_11 )
{
struct V_53 * V_54 , * V_55 ;
T_6 * V_56 = NULL ;
F_24 ( & V_50 ) ;
F_28 (lelt, tmp, &ReqHandlerInfo_list) {
V_56 = F_29 ( V_54 , T_6 , V_51 ) ;
if ( F_30 ( V_56 -> V_11 , V_11 ) == 0 ) {
F_26 ( & V_50 ) ;
return V_56 ;
}
}
F_26 ( & V_50 ) ;
return NULL ;
}
int
F_15 ( T_3 V_11 )
{
struct V_53 * V_54 , * V_55 ;
T_6 * V_56 = NULL ;
int V_21 = - 1 ;
F_24 ( & V_50 ) ;
F_28 (lelt, tmp, &ReqHandlerInfo_list) {
V_56 = F_29 ( V_54 , T_6 , V_51 ) ;
if ( F_30 ( V_56 -> V_11 , V_11 ) == 0 ) {
F_31 ( V_54 ) ;
F_32 ( V_56 ) ;
V_21 ++ ;
}
}
F_26 ( & V_50 ) ;
return V_21 ;
}
