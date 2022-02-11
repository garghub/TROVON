void F_1 ( void )
{
printf ( L_1 , V_1 ) ;
}
static int F_2 ( char * V_2 )
{
char V_3 [] = L_2 ;
struct V_4 * V_5 ;
struct V_6 * V_7 ;
struct V_8 * V_9 ;
int V_10 = 0 ;
int V_11 , V_12 = - 1 ;
char V_13 [] = L_3 ;
char V_14 [ V_15 ] ;
char V_16 [ V_15 ] ;
struct V_17 * V_18 ;
char * V_19 = NULL ;
int V_20 ;
V_5 = F_3 ( V_3 , V_21 ) ;
if ( ! V_5 ) {
F_4 ( L_4 , V_21 ,
strerror ( V_22 ) ) ;
return - 1 ;
}
V_9 = F_5 ( V_5 ) ;
if ( ! V_9 ) {
F_4 ( L_5 , V_21 ) ;
goto V_23;
}
F_6 (devlist, dev, struct sysfs_device) {
if ( ! strncmp ( V_2 , V_7 -> V_24 , strlen ( V_2 ) ) &&
! strncmp ( V_7 -> V_25 , V_21 ,
strlen ( V_21 ) ) ) {
V_10 = 1 ;
break;
}
}
if ( ! V_10 ) {
F_4 ( L_6 , V_2 ,
V_21 ) ;
goto V_23;
}
V_11 = F_7 ( V_14 , V_15 ) ;
if ( V_11 < 0 ) {
F_4 ( L_7 , strerror ( V_22 ) ) ;
return - 1 ;
}
snprintf ( V_16 , sizeof( V_16 ) , L_8 ,
V_14 , V_26 , V_3 , V_27 ,
V_2 , V_13 ) ;
V_18 = F_8 ( V_16 ) ;
if ( ! V_18 ) {
F_4 ( L_9 , V_2 , V_13 ,
strerror ( V_22 ) ) ;
return - 1 ;
}
if ( F_9 ( V_18 ) < 0 ) {
F_4 ( L_10 , strerror ( V_22 ) ) ;
goto V_28;
}
V_20 = V_18 -> V_20 ;
V_19 = malloc ( V_20 ) ;
* V_19 = * V_18 -> V_29 ;
F_10 ( V_18 ) ;
V_11 = F_11 ( V_2 , 0 ) ;
if ( V_11 < 0 ) {
F_4 ( L_11 , V_2 ) ;
goto V_28;
}
V_18 = F_8 ( V_16 ) ;
if ( ! V_18 ) {
F_4 ( L_9 , V_2 , V_13 ,
strerror ( V_22 ) ) ;
return - 1 ;
}
V_11 = F_12 ( V_18 , V_19 , V_20 ) ;
if ( V_11 < 0 ) {
F_4 ( L_12 , strerror ( V_22 ) ) ;
goto V_28;
}
F_10 ( V_18 ) ;
V_12 = 0 ;
printf ( L_13 , V_2 ) ;
V_28:
free ( V_19 ) ;
V_23:
F_13 ( V_5 ) ;
return V_12 ;
}
int F_14 ( int V_30 , char * V_31 [] )
{
static const struct V_32 V_33 [] = {
{ L_14 , V_34 , NULL , 'b' } ,
{ NULL , 0 , NULL , 0 }
} ;
int V_35 ;
int V_12 = - 1 ;
for (; ; ) {
V_35 = F_15 ( V_30 , V_31 , L_15 , V_33 , NULL ) ;
if ( V_35 == - 1 )
break;
switch ( V_35 ) {
case 'b' :
V_12 = F_2 ( V_36 ) ;
goto V_37;
default:
goto V_28;
}
}
V_28:
F_1 () ;
V_37:
return V_12 ;
}
