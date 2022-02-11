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
V_16 = F_3 ( V_3 , V_17 , 0 ) ;
if ( V_16 < 0 ) {
F_4 ( L_2 ) ;
return - 1 ;
}
V_16 = F_5 ( V_3 , & V_8 ) ;
if ( V_16 < 0 ) {
F_4 ( L_3 ) ;
return - 1 ;
}
memset ( & V_7 , 0 , sizeof( V_7 ) ) ;
V_16 = F_6 ( V_3 , & V_7 , sizeof( V_7 ) ) ;
if ( V_16 < 0 ) {
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
V_16 = F_6 ( V_3 , & V_11 , sizeof( V_11 ) ) ;
if ( V_16 < 0 ) {
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
for ( V_15 = 0 ; V_15 < V_11 . V_26 ; V_15 ++ ) {
V_16 = F_6 ( V_3 , & V_13 , sizeof( V_13 ) ) ;
if ( V_16 < 0 ) {
F_4 ( L_13 ,
V_15 ) ;
return - 1 ;
}
F_12 ( 0 , & V_13 ) ;
F_11 ( V_5 , sizeof( V_5 ) ,
V_13 . V_27 ,
V_13 . V_28 ,
V_13 . V_29 ) ;
printf ( L_14 , L_12 , V_15 , V_5 ) ;
}
printf ( L_15 ) ;
}
return 0 ;
}
static int F_13 ( char * V_2 )
{
int V_16 ;
int V_3 ;
V_3 = F_14 ( V_2 , V_30 ) ;
if ( V_3 < 0 ) {
F_15 ( L_16 , V_2 ,
V_30 , F_16 ( V_3 ) ) ;
return - 1 ;
}
F_4 ( L_17 , V_2 , V_30 ) ;
V_16 = F_2 ( V_2 , V_3 ) ;
if ( V_16 < 0 ) {
F_15 ( L_18 , V_2 ) ;
return - 1 ;
}
F_17 ( V_3 ) ;
return 0 ;
}
static void F_18 ( char * V_24 , char * V_31 , char * V_32 ,
bool V_33 )
{
if ( V_33 )
printf ( L_19 , V_24 , V_31 , V_32 ) ;
else
printf ( L_20 , V_24 , V_31 , V_32 ) ;
}
static void F_19 ( char * V_24 , char * V_34 , bool V_33 )
{
if ( V_33 )
printf ( L_21 , V_24 , V_34 ) ;
else
printf ( L_22 , L_12 , V_24 , V_34 ) ;
}
static int F_20 ( void * V_35 )
{
struct V_36 * V_37 ;
struct V_38 * V_39 = V_35 ;
int V_40 = 0 ;
V_37 = F_21 ( V_39 , L_23 ) ;
if ( V_37 && * V_37 -> V_41 != '0' )
V_40 = 1 ;
return V_40 ;
}
static int F_22 ( void * V_42 , void * V_43 )
{
return strcmp ( V_42 , V_43 ) ;
}
static int F_23 ( bool V_33 )
{
char V_44 [] = L_24 ;
char V_24 [ V_45 ] ;
struct V_46 * V_47 ;
struct V_38 * V_39 ;
struct V_38 * V_48 ;
struct V_36 * V_19 ;
struct V_36 * V_20 ;
struct V_36 * V_49 ;
struct V_36 * V_50 ;
struct V_51 * V_52 ;
int V_14 ;
int V_40 = - 1 ;
V_47 = F_24 ( V_44 ) ;
if ( ! V_47 ) {
F_15 ( L_25 , V_44 , strerror ( V_53 ) ) ;
return - 1 ;
}
V_52 = F_25 ( V_47 ) ;
if ( ! V_52 ) {
F_15 ( L_26 , V_44 ,
strerror ( V_53 ) ) ;
goto V_54;
}
F_26 ( V_52 , F_20 , F_22 ) ;
if ( ! V_33 ) {
printf ( L_27 ) ;
printf ( L_28 ) ;
}
F_27 (devlist, dev, struct sysfs_device) {
V_19 = F_21 ( V_39 , L_29 ) ;
V_20 = F_21 ( V_39 , L_30 ) ;
V_49 = F_21 ( V_39 , L_31 ) ;
V_50 = F_21 ( V_39 , L_32 ) ;
if ( ! V_19 || ! V_20 || ! V_49 || ! V_50 ) {
F_15 ( L_33 ,
strerror ( V_53 ) ) ;
goto V_54;
}
F_18 ( V_39 -> V_55 , V_19 -> V_41 , V_20 -> V_41 ,
V_33 ) ;
for ( V_14 = 0 ; V_14 < atoi ( V_50 -> V_41 ) ; V_14 ++ ) {
snprintf ( V_24 , sizeof( V_24 ) , L_34 ,
V_39 -> V_55 , V_49 -> V_41 , V_14 ) ;
V_48 = F_28 ( V_44 , V_24 ) ;
if ( ! V_48 ) {
F_15 ( L_35 ,
strerror ( V_53 ) ) ;
goto V_54;
}
F_19 ( V_24 , V_48 -> V_56 , V_33 ) ;
F_29 ( V_48 ) ;
}
printf ( L_15 ) ;
}
V_40 = 0 ;
V_54:
F_30 ( V_47 ) ;
return V_40 ;
}
int F_31 ( int V_57 , char * V_58 [] )
{
static const struct V_59 V_60 [] = {
{ L_36 , V_61 , NULL , 'p' } ,
{ L_37 , V_62 , NULL , 'r' } ,
{ L_38 , V_61 , NULL , 'l' } ,
{ NULL , 0 , NULL , 0 }
} ;
bool V_33 = false ;
int V_63 ;
int V_40 = - 1 ;
if ( F_32 ( V_64 ) )
F_15 ( L_39 , V_64 ) ;
for (; ; ) {
V_63 = F_33 ( V_57 , V_58 , L_40 , V_60 , NULL ) ;
if ( V_63 == - 1 )
break;
switch ( V_63 ) {
case 'p' :
V_33 = true ;
break;
case 'r' :
V_40 = F_13 ( V_65 ) ;
goto V_66;
case 'l' :
V_40 = F_23 ( V_33 ) ;
goto V_66;
default:
goto V_54;
}
}
V_54:
F_1 () ;
V_66:
F_34 () ;
return V_40 ;
}
