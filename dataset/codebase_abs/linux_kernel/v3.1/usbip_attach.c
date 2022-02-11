void F_1 ( void )
{
printf ( L_1 , V_1 ) ;
}
static int F_2 ( char * V_2 , char * V_3 , char * V_4 , int V_5 )
{
int V_6 ;
char V_7 [ V_8 + 1 ] ;
char V_9 [ V_10 + 1 ] ;
int V_11 ;
F_3 ( V_12 , 0700 ) ;
snprintf ( V_7 , V_8 , V_12 L_2 , V_5 ) ;
V_6 = F_4 ( V_7 , V_13 | V_14 | V_15 , V_16 ) ;
if ( V_6 < 0 )
return - 1 ;
snprintf ( V_9 , V_10 , L_3 ,
V_2 , V_3 , V_4 ) ;
V_11 = F_5 ( V_6 , V_9 , strlen ( V_9 ) ) ;
if ( V_11 != ( V_17 ) strlen ( V_9 ) ) {
F_6 ( V_6 ) ;
return - 1 ;
}
F_6 ( V_6 ) ;
return 0 ;
}
static int F_7 ( int V_18 , struct V_19 * V_20 )
{
int V_21 ;
int V_3 ;
V_21 = F_8 () ;
if ( V_21 < 0 ) {
F_9 ( L_4 ) ;
return - 1 ;
}
V_3 = F_10 () ;
if ( V_3 < 0 ) {
F_9 ( L_5 ) ;
F_11 () ;
return - 1 ;
}
V_21 = F_12 ( V_3 , V_18 , V_20 -> V_22 ,
V_20 -> V_23 , V_20 -> V_24 ) ;
if ( V_21 < 0 ) {
F_9 ( L_6 ) ;
F_11 () ;
return - 1 ;
}
F_11 () ;
return V_3 ;
}
static int F_13 ( int V_18 , char * V_4 )
{
int V_21 ;
struct V_25 V_26 ;
struct V_27 V_28 ;
T_1 V_29 = V_30 ;
memset ( & V_26 , 0 , sizeof( V_26 ) ) ;
memset ( & V_28 , 0 , sizeof( V_28 ) ) ;
V_21 = F_14 ( V_18 , V_31 , 0 ) ;
if ( V_21 < 0 ) {
F_9 ( L_7 ) ;
return - 1 ;
}
strncpy ( V_26 . V_4 , V_4 , V_32 - 1 ) ;
F_15 ( 0 , & V_26 ) ;
V_21 = F_16 ( V_18 , ( void * ) & V_26 , sizeof( V_26 ) ) ;
if ( V_21 < 0 ) {
F_9 ( L_8 ) ;
return - 1 ;
}
V_21 = F_17 ( V_18 , & V_29 ) ;
if ( V_21 < 0 ) {
F_9 ( L_9 ) ;
return - 1 ;
}
V_21 = F_18 ( V_18 , ( void * ) & V_28 , sizeof( V_28 ) ) ;
if ( V_21 < 0 ) {
F_9 ( L_10 ) ;
return - 1 ;
}
F_19 ( 0 , & V_28 ) ;
if ( strncmp ( V_28 . V_20 . V_4 , V_4 , V_32 ) ) {
F_9 ( L_11 , V_28 . V_20 . V_4 ) ;
return - 1 ;
}
return F_7 ( V_18 , & V_28 . V_20 ) ;
}
static int F_20 ( char * V_2 , char * V_4 )
{
int V_18 ;
int V_21 ;
int V_5 ;
V_18 = F_21 ( V_2 , V_33 ) ;
if ( V_18 < 0 ) {
F_9 ( L_12 ) ;
return - 1 ;
}
V_5 = F_13 ( V_18 , V_4 ) ;
if ( V_5 < 0 ) {
F_9 ( L_13 ) ;
return - 1 ;
}
F_6 ( V_18 ) ;
V_21 = F_2 ( V_2 , V_33 , V_4 , V_5 ) ;
if ( V_21 < 0 ) {
F_9 ( L_14 ) ;
return - 1 ;
}
return 0 ;
}
int F_22 ( int V_34 , char * V_35 [] )
{
static const struct V_36 V_37 [] = {
{ L_15 , V_38 , NULL , 'h' } ,
{ L_16 , V_38 , NULL , 'b' } ,
{ NULL , 0 , NULL , 0 }
} ;
char * V_2 = NULL ;
char * V_4 = NULL ;
int V_39 ;
int V_11 = - 1 ;
for (; ; ) {
V_39 = F_23 ( V_34 , V_35 , L_17 , V_37 , NULL ) ;
if ( V_39 == - 1 )
break;
switch ( V_39 ) {
case 'h' :
V_2 = V_40 ;
break;
case 'b' :
V_4 = V_40 ;
break;
default:
goto V_41;
}
}
if ( ! V_2 || ! V_4 )
goto V_41;
V_11 = F_20 ( V_2 , V_4 ) ;
goto V_42;
V_41:
F_1 () ;
V_42:
return V_11 ;
}
