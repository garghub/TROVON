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
V_11 = F_3 ( V_12 , 0700 ) ;
if ( V_11 < 0 ) {
if ( V_13 == V_14 ) {
struct V_15 V_16 ;
V_11 = V_15 ( V_12 , & V_16 ) ;
if ( V_11 < 0 )
return - 1 ;
if ( ! ( V_16 . V_17 & V_18 ) )
return - 1 ;
} else
return - 1 ;
}
snprintf ( V_7 , V_8 , V_12 L_2 , V_5 ) ;
V_6 = F_4 ( V_7 , V_19 | V_20 | V_21 , V_22 ) ;
if ( V_6 < 0 )
return - 1 ;
snprintf ( V_9 , V_10 , L_3 ,
V_2 , V_3 , V_4 ) ;
V_11 = F_5 ( V_6 , V_9 , strlen ( V_9 ) ) ;
if ( V_11 != ( V_23 ) strlen ( V_9 ) ) {
F_6 ( V_6 ) ;
return - 1 ;
}
F_6 ( V_6 ) ;
return 0 ;
}
static int F_7 ( int V_24 , struct V_25 * V_26 )
{
int V_27 ;
int V_3 ;
T_1 V_28 = V_26 -> V_28 ;
V_27 = F_8 () ;
if ( V_27 < 0 ) {
F_9 ( L_4 ) ;
goto V_29;
}
do {
V_3 = F_10 ( V_28 ) ;
if ( V_3 < 0 ) {
F_9 ( L_5 ) ;
goto V_30;
}
F_11 ( L_6 , V_3 ) ;
V_27 = F_12 ( V_3 , V_24 , V_26 -> V_31 ,
V_26 -> V_32 , V_26 -> V_28 ) ;
if ( V_27 < 0 && V_13 != V_33 ) {
F_9 ( L_7 ) ;
goto V_30;
}
} while ( V_27 < 0 );
F_13 () ;
return V_3 ;
V_30:
F_13 () ;
V_29:
return - 1 ;
}
static int F_14 ( int V_24 , char * V_4 )
{
int V_27 ;
struct V_34 V_35 ;
struct V_36 V_37 ;
T_2 V_38 = V_39 ;
memset ( & V_35 , 0 , sizeof( V_35 ) ) ;
memset ( & V_37 , 0 , sizeof( V_37 ) ) ;
V_27 = F_15 ( V_24 , V_40 , 0 ) ;
if ( V_27 < 0 ) {
F_9 ( L_8 ) ;
return - 1 ;
}
strncpy ( V_35 . V_4 , V_4 , V_41 - 1 ) ;
F_16 ( 0 , & V_35 ) ;
V_27 = F_17 ( V_24 , ( void * ) & V_35 , sizeof( V_35 ) ) ;
if ( V_27 < 0 ) {
F_9 ( L_9 ) ;
return - 1 ;
}
V_27 = F_18 ( V_24 , & V_38 ) ;
if ( V_27 < 0 ) {
F_9 ( L_10 ) ;
return - 1 ;
}
V_27 = F_19 ( V_24 , ( void * ) & V_37 , sizeof( V_37 ) ) ;
if ( V_27 < 0 ) {
F_9 ( L_11 ) ;
return - 1 ;
}
F_20 ( 0 , & V_37 ) ;
if ( strncmp ( V_37 . V_26 . V_4 , V_4 , V_41 ) ) {
F_9 ( L_12 , V_37 . V_26 . V_4 ) ;
return - 1 ;
}
return F_7 ( V_24 , & V_37 . V_26 ) ;
}
static int F_21 ( char * V_2 , char * V_4 )
{
int V_24 ;
int V_27 ;
int V_5 ;
V_24 = F_22 ( V_2 , V_42 ) ;
if ( V_24 < 0 ) {
F_9 ( L_13 ) ;
return - 1 ;
}
V_5 = F_14 ( V_24 , V_4 ) ;
if ( V_5 < 0 ) {
F_9 ( L_14 ) ;
return - 1 ;
}
F_6 ( V_24 ) ;
V_27 = F_2 ( V_2 , V_42 , V_4 , V_5 ) ;
if ( V_27 < 0 ) {
F_9 ( L_15 ) ;
return - 1 ;
}
return 0 ;
}
int F_23 ( int V_43 , char * V_44 [] )
{
static const struct V_45 V_46 [] = {
{ L_16 , V_47 , NULL , 'r' } ,
{ L_17 , V_47 , NULL , 'b' } ,
{ L_18 , V_47 , NULL , 'd' } ,
{ NULL , 0 , NULL , 0 }
} ;
char * V_2 = NULL ;
char * V_4 = NULL ;
int V_48 ;
int V_11 = - 1 ;
for (; ; ) {
V_48 = F_24 ( V_43 , V_44 , L_19 , V_46 , NULL ) ;
if ( V_48 == - 1 )
break;
switch ( V_48 ) {
case 'r' :
V_2 = V_49 ;
break;
case 'd' :
case 'b' :
V_4 = V_49 ;
break;
default:
goto V_29;
}
}
if ( ! V_2 || ! V_4 )
goto V_29;
V_11 = F_21 ( V_2 , V_4 ) ;
goto V_50;
V_29:
F_1 () ;
V_50:
return V_11 ;
}
