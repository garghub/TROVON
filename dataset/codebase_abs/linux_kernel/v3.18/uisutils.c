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
F_8 ( V_7 , L_5 , L_6 ,
V_10 , NULL ) ;
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
T_2 * V_20 )
{
T_6 * V_21 ;
int V_22 = 0 ;
F_5 ( L_7 ,
& V_11 , F_10 ) ;
if ( ! F_10 ) {
F_3 ( L_8 , & V_11 ) ;
goto V_23;
}
if ( ! F_11 ) {
F_3 ( L_9 ,
& V_11 ) ;
goto V_23;
}
if ( ! F_12 ) {
F_3 ( L_10 ,
& V_11 ) ;
goto V_23;
}
V_21 = F_13 ( V_11 ,
V_12 ,
F_10 ,
V_14 ,
F_11 , F_12 ) ;
if ( ! V_21 ) {
F_3 ( L_11 , & V_11 ) ;
goto V_23;
}
F_6 ( & V_9 ) ;
V_22 = 1 ;
V_23:
if ( V_22 ) {
if ( V_20 )
F_8 ( V_20 , L_5 ,
L_6 , V_10 , NULL ) ;
} else
F_3 ( L_12 , & V_11 ) ;
return V_22 ;
}
int
F_14 ( T_3 V_11 )
{
int V_22 = 0 ;
F_5 ( L_13 , & V_11 ) ;
if ( F_15 ( V_11 ) < 0 ) {
F_3 ( L_14 ,
& V_11 ) ;
goto V_23;
}
F_7 ( & V_9 ) ;
V_22 = 1 ;
V_23:
if ( ! V_22 )
F_3 ( L_15 , & V_11 ) ;
return V_22 ;
}
unsigned int
F_16 ( unsigned char * V_24 , void * V_25 ,
unsigned int V_26 ,
unsigned int V_27 ,
struct V_28 V_29 [] )
{
unsigned int V_30 = 0 , V_31 , V_32 , V_33 = 0 , V_34 ;
struct V_35 * V_36 = V_25 ;
V_34 = F_17 ( V_36 ) -> V_37 ;
while ( V_26 ) {
if ( V_30 == V_27 ) {
F_3 ( L_16 ,
V_24 , V_27 , V_30 ) ;
return - 1 ;
}
V_29 [ V_30 ] . V_38 =
F_18 ( F_19 ( V_36 -> V_39 + V_33 ) ) ;
V_29 [ V_30 ] . V_40 =
( unsigned long ) ( V_36 -> V_39 + V_33 ) & V_41 ;
V_32 =
F_20 ( V_26 ,
( unsigned int ) ( V_42 - V_29 [ V_30 ] . V_40 ) ) ;
V_29 [ V_30 ] . V_43 = V_32 ;
V_26 -= V_32 ;
V_33 += V_32 ;
V_30 ++ ;
}
if ( ! V_34 )
goto V_44;
if ( ( V_30 + V_34 ) > V_27 ) {
F_3 ( L_17 ,
V_24 , V_27 , V_30 + V_34 ) ;
return - 1 ;
}
for ( V_31 = 0 ; V_31 < V_34 ; V_31 ++ ) {
V_30 = F_21 ( F_18 (
F_22 ( & F_17 ( V_36 ) -> V_29 [ V_31 ] ) ) ,
F_17 ( V_36 ) -> V_29 [ V_31 ] .
V_45 ,
F_17 ( V_36 ) -> V_29 [ V_31 ] .
V_32 , V_30 , V_27 ,
V_29 ) ;
if ( V_30 == 0 ) {
F_3 ( L_18 ) ;
return - 1 ;
}
}
V_44: if ( F_17 ( V_36 ) -> V_46 ) {
struct V_35 * V_47 ;
int V_48 ;
for ( V_47 = F_17 ( V_36 ) -> V_46 ; V_47 ;
V_47 = V_47 -> V_49 ) {
V_48 = F_16 ( L_19 ,
V_47 ,
V_47 -> V_5 - V_47 -> V_50 ,
V_27 - V_30 ,
& V_29 [ V_30 ] ) ;
if ( V_48 == - 1 ) {
F_3 ( L_20 ) ;
return - 1 ;
}
V_30 += V_48 ;
}
}
return V_30 ;
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
T_6 * V_22 = NULL ;
V_22 = F_23 ( sizeof( * V_22 ) , V_51 ) ;
if ( ! V_22 )
return NULL ;
V_22 -> V_11 = V_11 ;
V_22 -> F_10 = F_10 ;
V_22 -> V_14 = V_14 ;
V_22 -> F_11 = F_11 ;
V_22 -> F_12 = F_12 ;
if ( V_12 )
strncpy ( V_22 -> V_12 , V_12 ,
sizeof( V_22 -> V_12 ) - 1 ) ;
F_24 ( & V_52 ) ;
F_25 ( & ( V_22 -> V_53 ) , & V_54 ) ;
F_26 ( & V_52 ) ;
return V_22 ;
}
T_6 *
F_27 ( T_3 V_11 )
{
struct V_55 * V_56 , * V_57 ;
T_6 * V_58 = NULL ;
F_24 ( & V_52 ) ;
F_28 (lelt, tmp, &ReqHandlerInfo_list) {
V_58 = F_29 ( V_56 , T_6 , V_53 ) ;
if ( F_30 ( V_58 -> V_11 , V_11 ) == 0 ) {
F_26 ( & V_52 ) ;
return V_58 ;
}
}
F_26 ( & V_52 ) ;
return NULL ;
}
int
F_15 ( T_3 V_11 )
{
struct V_55 * V_56 , * V_57 ;
T_6 * V_58 = NULL ;
int V_22 = - 1 ;
F_24 ( & V_52 ) ;
F_28 (lelt, tmp, &ReqHandlerInfo_list) {
V_58 = F_29 ( V_56 , T_6 , V_53 ) ;
if ( F_30 ( V_58 -> V_11 , V_11 ) == 0 ) {
F_31 ( V_56 ) ;
F_32 ( V_58 ) ;
V_22 ++ ;
}
}
F_26 ( & V_52 ) ;
return V_22 ;
}
