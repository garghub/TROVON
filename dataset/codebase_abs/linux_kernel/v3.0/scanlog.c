static T_1 F_1 ( struct V_1 * V_1 , char T_2 * V_2 ,
T_3 V_3 , T_4 * V_4 )
{
struct V_5 * V_5 = V_1 -> V_6 . V_7 -> V_8 ;
struct V_9 * V_10 ;
unsigned int * V_11 ;
int V_12 ;
unsigned long V_13 , V_14 ;
unsigned int V_15 ;
V_10 = F_2 ( V_5 ) ;
V_11 = ( unsigned int * ) V_10 -> V_11 ;
if ( V_3 > V_16 )
V_3 = V_16 ;
if ( V_3 < 1024 ) {
F_3 ( V_17 L_1 , V_3 ) ;
return - V_18 ;
}
if ( ! F_4 ( V_19 , V_2 , V_3 ) )
return - V_20 ;
for (; ; ) {
V_15 = 500 ;
F_5 ( & V_21 ) ;
memcpy ( V_22 , V_11 , V_16 ) ;
V_12 = F_6 ( V_23 , 2 , 1 , NULL ,
( V_24 ) F_7 ( V_22 ) , ( V_24 ) V_3 ) ;
memcpy ( V_11 , V_22 , V_16 ) ;
F_8 ( & V_21 ) ;
F_9 ( L_2 \
L_3 , V_12 , V_11 [ 0 ] , V_11 [ 1 ] , V_11 [ 2 ] ) ;
switch ( V_12 ) {
case V_25 :
F_9 ( L_4 ) ;
return 0 ;
case V_26 :
F_9 ( L_5 ) ;
return - V_27 ;
case V_28 :
V_13 = V_11 [ 1 ] ;
V_14 = V_11 [ 2 ] ;
if ( V_13 > 0 ) {
if ( F_10 ( V_2 , ( ( char * ) V_11 ) + V_14 , V_13 ) )
return - V_20 ;
return V_13 ;
}
break;
default:
V_15 = F_11 ( V_12 ) ;
if ( ! V_15 ) {
F_3 ( V_17 L_6 \
L_7 , V_12 ) ;
return - V_27 ;
}
}
F_12 ( V_15 ) ;
}
}
static T_1 F_13 ( struct V_1 * V_1 , const char T_2 * V_2 ,
T_3 V_3 , T_4 * V_4 )
{
char V_29 [ 20 ] ;
int V_12 ;
if ( V_3 > 19 ) V_3 = 19 ;
if ( F_14 ( V_29 , V_2 , V_3 ) ) {
return - V_20 ;
}
V_29 [ V_3 ] = 0 ;
if ( V_2 ) {
if ( strncmp ( V_29 , L_8 , 5 ) == 0 ) {
F_9 ( L_9 ) ;
V_12 = F_6 ( V_23 , 2 , 1 , NULL , 0 , 0 ) ;
F_9 ( L_10 , V_12 ) ;
}
}
return V_3 ;
}
static int F_15 ( struct V_5 * V_5 , struct V_1 * V_1 )
{
struct V_9 * V_10 = F_2 ( V_5 ) ;
unsigned int * V_11 = ( unsigned int * ) V_10 -> V_11 ;
if ( V_11 [ 0 ] != 0 ) {
return - V_30 ;
}
V_11 [ 0 ] = 0 ;
return 0 ;
}
static int F_16 ( struct V_5 * V_5 , struct V_1 * V_1 )
{
struct V_9 * V_10 = F_2 ( V_5 ) ;
unsigned int * V_11 = ( unsigned int * ) V_10 -> V_11 ;
V_11 [ 0 ] = 0 ;
return 0 ;
}
static int T_5 F_17 ( void )
{
struct V_9 * V_31 ;
void * V_11 ;
int V_32 = - V_33 ;
V_23 = F_18 ( L_11 ) ;
if ( V_23 == V_34 )
return - V_35 ;
V_11 = F_19 ( V_16 , V_36 ) ;
if ( ! V_11 )
goto V_32;
V_31 = F_20 ( L_12 , V_37 , NULL ,
& V_38 , V_11 ) ;
if ( ! V_31 )
goto V_32;
V_39 = V_31 ;
return 0 ;
V_32:
F_21 ( V_11 ) ;
return V_32 ;
}
static void T_6 F_22 ( void )
{
if ( V_39 ) {
F_21 ( V_39 -> V_11 ) ;
F_23 ( L_13 , V_39 -> V_40 ) ;
}
}
