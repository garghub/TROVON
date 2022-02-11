static T_1 F_1 ( struct V_1 * V_1 , char T_2 * V_2 ,
T_3 V_3 , T_4 * V_4 )
{
struct V_5 * V_6 = F_2 ( F_3 ( V_1 ) ) ;
unsigned int * V_7 = ( unsigned int * ) V_6 -> V_7 ;
int V_8 ;
unsigned long V_9 , V_10 ;
unsigned int V_11 ;
if ( V_3 > V_12 )
V_3 = V_12 ;
if ( V_3 < 1024 ) {
F_4 ( V_13 L_1 , V_3 ) ;
return - V_14 ;
}
if ( ! F_5 ( V_15 , V_2 , V_3 ) )
return - V_16 ;
for (; ; ) {
V_11 = 500 ;
F_6 ( & V_17 ) ;
memcpy ( V_18 , V_7 , V_12 ) ;
V_8 = F_7 ( V_19 , 2 , 1 , NULL ,
( V_20 ) F_8 ( V_18 ) , ( V_20 ) V_3 ) ;
memcpy ( V_7 , V_18 , V_12 ) ;
F_9 ( & V_17 ) ;
F_10 ( L_2 \
L_3 , V_8 , V_7 [ 0 ] , V_7 [ 1 ] , V_7 [ 2 ] ) ;
switch ( V_8 ) {
case V_21 :
F_10 ( L_4 ) ;
return 0 ;
case V_22 :
F_10 ( L_5 ) ;
return - V_23 ;
case V_24 :
V_9 = V_7 [ 1 ] ;
V_10 = V_7 [ 2 ] ;
if ( V_9 > 0 ) {
if ( F_11 ( V_2 , ( ( char * ) V_7 ) + V_10 , V_9 ) )
return - V_16 ;
return V_9 ;
}
break;
default:
V_11 = F_12 ( V_8 ) ;
if ( ! V_11 ) {
F_4 ( V_13 L_6 \
L_7 , V_8 ) ;
return - V_23 ;
}
}
F_13 ( V_11 ) ;
}
}
static T_1 F_14 ( struct V_1 * V_1 , const char T_2 * V_2 ,
T_3 V_3 , T_4 * V_4 )
{
char V_25 [ 20 ] ;
int V_8 ;
if ( V_3 > 19 ) V_3 = 19 ;
if ( F_15 ( V_25 , V_2 , V_3 ) ) {
return - V_16 ;
}
V_25 [ V_3 ] = 0 ;
if ( V_2 ) {
if ( strncmp ( V_25 , L_8 , 5 ) == 0 ) {
F_10 ( L_9 ) ;
V_8 = F_7 ( V_19 , 2 , 1 , NULL , 0 , 0 ) ;
F_10 ( L_10 , V_8 ) ;
}
}
return V_3 ;
}
static int F_16 ( struct V_26 * V_26 , struct V_1 * V_1 )
{
struct V_5 * V_6 = F_2 ( V_26 ) ;
unsigned int * V_7 = ( unsigned int * ) V_6 -> V_7 ;
if ( V_7 [ 0 ] != 0 ) {
return - V_27 ;
}
V_7 [ 0 ] = 0 ;
return 0 ;
}
static int F_17 ( struct V_26 * V_26 , struct V_1 * V_1 )
{
struct V_5 * V_6 = F_2 ( V_26 ) ;
unsigned int * V_7 = ( unsigned int * ) V_6 -> V_7 ;
V_7 [ 0 ] = 0 ;
return 0 ;
}
static int T_5 F_18 ( void )
{
struct V_5 * V_28 ;
void * V_7 ;
int V_29 = - V_30 ;
V_19 = F_19 ( L_11 ) ;
if ( V_19 == V_31 )
return - V_32 ;
V_7 = F_20 ( V_12 , V_33 ) ;
if ( ! V_7 )
goto V_29;
V_28 = F_21 ( L_12 , V_34 , NULL ,
& V_35 , V_7 ) ;
if ( ! V_28 )
goto V_29;
V_36 = V_28 ;
return 0 ;
V_29:
F_22 ( V_7 ) ;
return V_29 ;
}
static void T_6 F_23 ( void )
{
if ( V_36 ) {
F_22 ( V_36 -> V_7 ) ;
F_24 ( L_13 , V_36 -> V_37 ) ;
}
}
