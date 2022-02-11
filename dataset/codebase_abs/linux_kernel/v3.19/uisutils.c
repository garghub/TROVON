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
int V_23 = 0 ;
F_5 ( L_7 ,
& V_12 , F_10 ) ;
if ( ! F_10 ) {
F_3 ( L_8 , & V_12 ) ;
goto V_24;
}
if ( ! F_11 ) {
F_3 ( L_9 ,
& V_12 ) ;
goto V_24;
}
if ( ! F_12 ) {
F_3 ( L_10 ,
& V_12 ) ;
goto V_24;
}
V_22 = F_13 ( V_12 ,
V_13 ,
F_10 ,
V_15 ,
F_11 , F_12 ) ;
if ( ! V_22 ) {
F_3 ( L_11 , & V_12 ) ;
goto V_24;
}
F_6 ( & V_10 ) ;
V_23 = 1 ;
V_24:
if ( V_23 ) {
if ( V_8 )
F_8 ( V_8 , L_5 ,
L_6 , V_11 , NULL ) ;
} else
F_3 ( L_12 , & V_12 ) ;
return V_23 ;
}
int
F_14 ( T_2 V_12 )
{
int V_23 = 0 ;
F_5 ( L_13 , & V_12 ) ;
if ( F_15 ( V_12 ) < 0 ) {
F_3 ( L_14 ,
& V_12 ) ;
goto V_24;
}
F_7 ( & V_10 ) ;
V_23 = 1 ;
V_24:
if ( ! V_23 )
F_3 ( L_15 , & V_12 ) ;
return V_23 ;
}
unsigned int
F_16 ( unsigned char * V_25 , void * V_26 ,
unsigned int V_27 ,
unsigned int V_28 ,
struct V_29 V_30 [] )
{
unsigned int V_31 = 0 , V_32 , V_33 , V_34 = 0 , V_35 ;
struct V_36 * V_37 = V_26 ;
V_35 = F_17 ( V_37 ) -> V_38 ;
while ( V_27 ) {
if ( V_31 == V_28 ) {
F_3 ( L_16 ,
V_25 , V_28 , V_31 ) ;
return - 1 ;
}
V_30 [ V_31 ] . V_39 =
F_18 ( F_19 ( V_37 -> V_40 + V_34 ) ) ;
V_30 [ V_31 ] . V_41 =
( unsigned long ) ( V_37 -> V_40 + V_34 ) & V_42 ;
V_33 =
F_20 ( V_27 ,
( unsigned int ) ( V_43 - V_30 [ V_31 ] . V_41 ) ) ;
V_30 [ V_31 ] . V_44 = V_33 ;
V_27 -= V_33 ;
V_34 += V_33 ;
V_31 ++ ;
}
if ( ! V_35 )
goto V_45;
if ( ( V_31 + V_35 ) > V_28 ) {
F_3 ( L_17 ,
V_25 , V_28 , V_31 + V_35 ) ;
return - 1 ;
}
for ( V_32 = 0 ; V_32 < V_35 ; V_32 ++ ) {
V_31 = F_21 ( F_18 (
F_22 ( & F_17 ( V_37 ) -> V_30 [ V_32 ] ) ) ,
F_17 ( V_37 ) -> V_30 [ V_32 ] .
V_46 ,
F_17 ( V_37 ) -> V_30 [ V_32 ] .
V_33 , V_31 , V_28 ,
V_30 ) ;
if ( V_31 == 0 ) {
F_3 ( L_18 ) ;
return - 1 ;
}
}
V_45: if ( F_17 ( V_37 ) -> V_47 ) {
struct V_36 * V_48 ;
int V_49 ;
for ( V_48 = F_17 ( V_37 ) -> V_47 ; V_48 ;
V_48 = V_48 -> V_50 ) {
V_49 = F_16 ( L_19 ,
V_48 ,
V_48 -> V_5 - V_48 -> V_51 ,
V_28 - V_31 ,
& V_30 [ V_31 ] ) ;
if ( V_49 == - 1 ) {
F_3 ( L_20 ) ;
return - 1 ;
}
V_31 += V_49 ;
}
}
return V_31 ;
}
struct V_21 *
F_13 ( T_2 V_12 ,
const char * V_13 ,
int (* F_10)( struct V_14 * ) ,
unsigned long V_15 ,
int (* F_23)( unsigned long V_52 ) ,
int (* F_24)
( void * V_17 , unsigned char * V_53 , T_3 V_54 , T_4 V_20 ) )
{
struct V_21 * V_23 = NULL ;
V_23 = F_25 ( sizeof( * V_23 ) , V_55 ) ;
if ( ! V_23 )
return NULL ;
V_23 -> V_12 = V_12 ;
V_23 -> F_10 = F_10 ;
V_23 -> V_15 = V_15 ;
V_23 -> F_11 = F_23 ;
V_23 -> F_12 = F_24 ;
if ( V_13 )
strncpy ( V_23 -> V_13 , V_13 ,
sizeof( V_23 -> V_13 ) - 1 ) ;
F_26 ( & V_56 ) ;
F_27 ( & ( V_23 -> V_57 ) , & V_58 ) ;
F_28 ( & V_56 ) ;
return V_23 ;
}
struct V_21 *
F_29 ( T_2 V_12 )
{
struct V_59 * V_60 , * V_61 ;
struct V_21 * V_62 = NULL ;
F_26 ( & V_56 ) ;
F_30 (lelt, tmp, &ReqHandlerInfo_list) {
V_62 = F_31 ( V_60 , struct V_21 , V_57 ) ;
if ( F_32 ( V_62 -> V_12 , V_12 ) == 0 ) {
F_28 ( & V_56 ) ;
return V_62 ;
}
}
F_28 ( & V_56 ) ;
return NULL ;
}
int
F_15 ( T_2 V_12 )
{
struct V_59 * V_60 , * V_61 ;
struct V_21 * V_62 = NULL ;
int V_23 = - 1 ;
F_26 ( & V_56 ) ;
F_30 (lelt, tmp, &ReqHandlerInfo_list) {
V_62 = F_31 ( V_60 , struct V_21 , V_57 ) ;
if ( F_32 ( V_62 -> V_12 , V_12 ) == 0 ) {
F_33 ( V_60 ) ;
F_34 ( V_62 ) ;
V_23 ++ ;
}
}
F_28 ( & V_56 ) ;
return V_23 ;
}
