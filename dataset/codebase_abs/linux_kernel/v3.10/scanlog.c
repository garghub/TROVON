static T_1 F_1 ( struct V_1 * V_1 , char T_2 * V_2 ,
T_3 V_3 , T_4 * V_4 )
{
unsigned int * V_5 = V_6 ;
int V_7 ;
unsigned long V_8 , V_9 ;
unsigned int V_10 ;
if ( V_3 > V_11 )
V_3 = V_11 ;
if ( V_3 < 1024 ) {
F_2 ( V_12 L_1 , V_3 ) ;
return - V_13 ;
}
if ( ! F_3 ( V_14 , V_2 , V_3 ) )
return - V_15 ;
for (; ; ) {
V_10 = 500 ;
F_4 ( & V_16 ) ;
memcpy ( V_17 , V_5 , V_11 ) ;
V_7 = F_5 ( V_18 , 2 , 1 , NULL ,
( V_19 ) F_6 ( V_17 ) , ( V_19 ) V_3 ) ;
memcpy ( V_5 , V_17 , V_11 ) ;
F_7 ( & V_16 ) ;
F_8 ( L_2 \
L_3 , V_7 , V_5 [ 0 ] , V_5 [ 1 ] , V_5 [ 2 ] ) ;
switch ( V_7 ) {
case V_20 :
F_8 ( L_4 ) ;
return 0 ;
case V_21 :
F_8 ( L_5 ) ;
return - V_22 ;
case V_23 :
V_8 = V_5 [ 1 ] ;
V_9 = V_5 [ 2 ] ;
if ( V_8 > 0 ) {
if ( F_9 ( V_2 , ( ( char * ) V_5 ) + V_9 , V_8 ) )
return - V_15 ;
return V_8 ;
}
break;
default:
V_10 = F_10 ( V_7 ) ;
if ( ! V_10 ) {
F_2 ( V_12 L_6 \
L_7 , V_7 ) ;
return - V_22 ;
}
}
F_11 ( V_10 ) ;
}
}
static T_1 F_12 ( struct V_1 * V_1 , const char T_2 * V_2 ,
T_3 V_3 , T_4 * V_4 )
{
char V_24 [ 20 ] ;
int V_7 ;
if ( V_3 > 19 ) V_3 = 19 ;
if ( F_13 ( V_24 , V_2 , V_3 ) ) {
return - V_15 ;
}
V_24 [ V_3 ] = 0 ;
if ( V_2 ) {
if ( strncmp ( V_24 , L_8 , 5 ) == 0 ) {
F_8 ( L_9 ) ;
V_7 = F_5 ( V_18 , 2 , 1 , NULL , 0 , 0 ) ;
F_8 ( L_10 , V_7 ) ;
}
}
return V_3 ;
}
static int F_14 ( struct V_25 * V_25 , struct V_1 * V_1 )
{
unsigned int * V_5 = V_6 ;
if ( V_5 [ 0 ] != 0 ) {
return - V_26 ;
}
V_5 [ 0 ] = 0 ;
return 0 ;
}
static int F_15 ( struct V_25 * V_25 , struct V_1 * V_1 )
{
unsigned int * V_5 = V_6 ;
V_5 [ 0 ] = 0 ;
return 0 ;
}
static int T_5 F_16 ( void )
{
struct V_27 * V_28 ;
int V_29 = - V_30 ;
V_18 = F_17 ( L_11 ) ;
if ( V_18 == V_31 )
return - V_32 ;
V_6 = F_18 ( V_11 , V_33 ) ;
if ( ! V_6 )
goto V_29;
V_28 = F_19 ( L_12 , V_34 , NULL ,
& V_35 ) ;
if ( ! V_28 )
goto V_29;
return 0 ;
V_29:
F_20 ( V_6 ) ;
return V_29 ;
}
static void T_6 F_21 ( void )
{
F_22 ( L_12 , NULL ) ;
F_20 ( V_6 ) ;
}
