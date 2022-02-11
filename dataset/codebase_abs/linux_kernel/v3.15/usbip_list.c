void F_1 ( void )
{
printf ( L_1 , V_1 ) ;
}
static int F_2 ( char * V_2 , int V_3 )
{
char V_4 [ 100 ] ;
char V_5 [ 100 ] ;
struct V_6 V_7 ;
T_1 V_8 = V_9 ;
struct V_10 V_11 ;
struct V_12 V_13 ;
unsigned int V_14 ;
int V_15 , V_16 ;
V_15 = F_3 ( V_3 , V_17 , 0 ) ;
if ( V_15 < 0 ) {
F_4 ( L_2 ) ;
return - 1 ;
}
V_15 = F_5 ( V_3 , & V_8 ) ;
if ( V_15 < 0 ) {
F_4 ( L_3 ) ;
return - 1 ;
}
memset ( & V_7 , 0 , sizeof( V_7 ) ) ;
V_15 = F_6 ( V_3 , & V_7 , sizeof( V_7 ) ) ;
if ( V_15 < 0 ) {
F_4 ( L_4 ) ;
return - 1 ;
}
F_7 ( 0 , & V_7 ) ;
F_4 ( L_5 , V_7 . V_18 ) ;
if ( V_7 . V_18 == 0 ) {
F_8 ( L_6 , V_2 ) ;
return 0 ;
}
printf ( L_7 ) ;
printf ( L_8 ) ;
printf ( L_9 , V_2 ) ;
for ( V_14 = 0 ; V_14 < V_7 . V_18 ; V_14 ++ ) {
memset ( & V_11 , 0 , sizeof( V_11 ) ) ;
V_15 = F_6 ( V_3 , & V_11 , sizeof( V_11 ) ) ;
if ( V_15 < 0 ) {
F_4 ( L_10 , V_14 ) ;
return - 1 ;
}
F_9 ( 0 , & V_11 ) ;
F_10 ( V_4 , sizeof( V_4 ) ,
V_11 . V_19 , V_11 . V_20 ) ;
F_11 ( V_5 , sizeof( V_5 ) ,
V_11 . V_21 , V_11 . V_22 ,
V_11 . V_23 ) ;
printf ( L_11 , V_11 . V_24 , V_4 ) ;
printf ( L_11 , L_12 , V_11 . V_25 ) ;
printf ( L_11 , L_12 , V_5 ) ;
for ( V_16 = 0 ; V_16 < V_11 . V_26 ; V_16 ++ ) {
V_15 = F_6 ( V_3 , & V_13 , sizeof( V_13 ) ) ;
if ( V_15 < 0 ) {
F_12 ( L_13 ,
V_16 ) ;
return - 1 ;
}
F_13 ( 0 , & V_13 ) ;
F_11 ( V_5 , sizeof( V_5 ) ,
V_13 . V_27 ,
V_13 . V_28 ,
V_13 . V_29 ) ;
printf ( L_14 , L_12 , V_16 , V_5 ) ;
}
printf ( L_15 ) ;
}
return 0 ;
}
static int F_14 ( char * V_2 )
{
int V_15 ;
int V_3 ;
V_3 = F_15 ( V_2 , V_30 ) ;
if ( V_3 < 0 ) {
F_12 ( L_16 , V_2 ,
V_30 , F_16 ( V_3 ) ) ;
return - 1 ;
}
F_4 ( L_17 , V_2 , V_30 ) ;
V_15 = F_2 ( V_2 , V_3 ) ;
if ( V_15 < 0 ) {
F_12 ( L_18 , V_2 ) ;
return - 1 ;
}
F_17 ( V_3 ) ;
return 0 ;
}
static void F_18 ( const char * V_24 , const char * V_31 ,
const char * V_32 , bool V_33 )
{
if ( V_33 )
printf ( L_19 , V_24 , V_31 , V_32 ) ;
else
printf ( L_20 , V_24 , V_31 , V_32 ) ;
}
static void F_19 ( char * V_4 , bool V_33 )
{
if ( ! V_33 )
printf ( L_21 , V_4 ) ;
}
static int F_20 ( bool V_33 )
{
struct V_11 * V_11 ;
struct V_34 * V_35 ;
struct V_36 * V_37 , * V_38 ;
struct V_39 * V_40 ;
const char * V_25 ;
const char * V_19 ;
const char * V_20 ;
const char * V_41 ;
const char * V_42 ;
const char * V_24 ;
char V_4 [ 128 ] ;
int V_43 = - 1 ;
V_11 = F_21 () ;
V_35 = F_22 ( V_11 ) ;
F_23 ( V_35 , L_22 ) ;
F_24 ( V_35 , L_23 , L_24 ) ;
F_24 ( V_35 , L_25 , NULL ) ;
F_25 ( V_35 ) ;
V_37 = F_26 ( V_35 ) ;
F_27 (dev_list_entry, devices) {
V_25 = F_28 ( V_38 ) ;
V_40 = F_29 ( V_11 , V_25 ) ;
V_19 = F_30 ( V_40 , L_26 ) ;
V_20 = F_30 ( V_40 , L_27 ) ;
V_41 = F_30 ( V_40 , L_28 ) ;
V_42 = F_30 ( V_40 , L_29 ) ;
V_24 = F_31 ( V_40 ) ;
if ( ! V_19 || ! V_20 || ! V_41 || ! V_42 ) {
F_12 ( L_30 ,
strerror ( V_44 ) ) ;
goto V_45;
}
F_10 ( V_4 , sizeof( V_4 ) ,
strtol ( V_19 , NULL , 16 ) ,
strtol ( V_20 , NULL , 16 ) ) ;
F_18 ( V_24 , V_19 , V_20 , V_33 ) ;
F_19 ( V_4 , V_33 ) ;
printf ( L_15 ) ;
F_32 ( V_40 ) ;
}
V_43 = 0 ;
V_45:
F_33 ( V_35 ) ;
F_34 ( V_11 ) ;
return V_43 ;
}
int F_35 ( int V_46 , char * V_47 [] )
{
static const struct V_48 V_49 [] = {
{ L_31 , V_50 , NULL , 'p' } ,
{ L_32 , V_51 , NULL , 'r' } ,
{ L_33 , V_50 , NULL , 'l' } ,
{ NULL , 0 , NULL , 0 }
} ;
bool V_33 = false ;
int V_52 ;
int V_43 = - 1 ;
if ( F_36 ( V_53 ) )
F_12 ( L_34 , V_53 ) ;
for (; ; ) {
V_52 = F_37 ( V_46 , V_47 , L_35 , V_49 , NULL ) ;
if ( V_52 == - 1 )
break;
switch ( V_52 ) {
case 'p' :
V_33 = true ;
break;
case 'r' :
V_43 = F_14 ( V_54 ) ;
goto V_55;
case 'l' :
V_43 = F_20 ( V_33 ) ;
goto V_55;
default:
goto V_45;
}
}
V_45:
F_1 () ;
V_55:
F_38 () ;
return V_43 ;
}
