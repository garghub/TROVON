static int F_1 ( void * V_1 , void * V_2 )
{
struct V_3 * V_4 = V_1 ;
V_4 -> V_2 = V_2 ;
return 0 ;
}
static void F_2 ( int V_5 , unsigned char * V_6 , unsigned char * V_7 ,
int V_8 )
{
struct V_9 V_10 ;
char * V_11 ;
int V_12 ;
V_10 . V_13 = V_5 ;
memcpy ( V_10 . V_6 , V_6 , sizeof( V_10 . V_6 ) ) ;
memcpy ( V_10 . V_7 , V_7 , sizeof( V_10 . V_7 ) ) ;
F_3 ( V_12 = F_4 ( V_8 , & V_10 , sizeof( V_10 ) ) ) ;
if ( V_12 != sizeof( V_10 ) ) {
F_5 ( V_14 L_1 ,
V_15 ) ;
return;
}
V_11 = F_6 ( V_16 , V_17 ) ;
if ( V_11 == NULL )
F_5 ( V_14 L_2
L_3 ) ;
F_7 ( V_8 , V_11 , V_16 ) ;
if ( V_11 != NULL ) {
F_5 ( L_4 , V_11 ) ;
F_8 ( V_11 ) ;
}
}
static void F_9 ( unsigned char * V_6 , unsigned char * V_7 ,
void * V_18 )
{
F_2 ( V_19 , V_6 , V_7 , * ( ( int * ) V_18 ) ) ;
}
static void F_10 ( unsigned char * V_6 , unsigned char * V_7 ,
void * V_18 )
{
F_2 ( V_20 , V_6 , V_7 , * ( ( int * ) V_18 ) ) ;
}
static void F_11 ( void * V_18 )
{
struct V_21 * V_1 = V_18 ;
F_12 ( V_1 -> V_22 , 1 ) ;
F_13 ( V_1 -> V_23 ) ;
F_13 ( V_1 -> V_24 ) ;
}
static int F_14 ( char * V_2 , char * V_25 , int V_24 ,
int V_22 , int V_23 , int V_26 )
{
struct V_21 V_27 ;
int V_28 , V_29 , V_12 ;
char V_30 [ sizeof( L_5 ) ] ;
char V_31 [ sizeof( L_6 ) ] ;
char V_32 [ sizeof( L_7 ) ] ;
char * V_33 [] = { L_8 , V_30 , L_9 , V_2 ,
V_31 , V_32 , NULL } ;
char * V_34 [] = { L_8 , V_30 , L_9 ,
V_2 , V_31 , NULL } ;
char * * args , V_35 ;
sprintf ( V_31 , L_10 , V_26 ) ;
sprintf ( V_30 , L_10 , V_36 ) ;
if ( V_25 != NULL ) {
strncpy ( V_32 , V_25 , 15 ) ;
args = V_33 ;
}
else args = V_34 ;
V_29 = 0 ;
V_27 . V_22 = V_22 ;
V_27 . V_24 = V_24 ;
V_27 . V_23 = V_23 ;
V_28 = F_15 ( F_11 , & V_27 , args ) ;
if ( V_28 < 0 )
V_29 = V_28 ;
F_13 ( V_26 ) ;
F_13 ( V_22 ) ;
F_3 ( V_12 = F_16 ( V_24 , & V_35 , sizeof( V_35 ) ) ) ;
if ( V_12 != sizeof( V_35 ) ) {
V_29 = - V_15 ;
F_5 ( V_14 L_11
L_12 , - V_29 ) ;
return V_29 ;
}
if ( V_35 != 1 ) {
F_5 ( V_14 L_13 ) ;
V_29 = F_17 ( V_28 ) ;
}
return V_29 ;
}
static int F_18 ( void * V_1 )
{
struct V_3 * V_4 = V_1 ;
char * V_11 ;
int V_37 [ 2 ] , V_38 [ 2 ] , V_29 , V_39 ;
V_29 = F_19 ( V_4 -> V_2 , V_4 -> V_40 ) ;
if ( V_29 )
return V_29 ;
V_29 = F_20 ( V_41 , V_42 , 0 , V_37 ) ;
if ( V_29 ) {
V_29 = - V_15 ;
F_5 ( V_14 L_14
L_12 , V_15 ) ;
return V_29 ;
}
V_29 = F_20 ( V_41 , V_43 , 0 , V_38 ) ;
if ( V_29 ) {
V_29 = - V_15 ;
F_5 ( V_14 L_15
L_12 , V_15 ) ;
goto V_44;
}
V_29 = F_14 ( V_4 -> V_45 , V_4 -> V_40 , V_38 [ 0 ] ,
V_38 [ 1 ] , V_37 [ 0 ] , V_37 [ 1 ] ) ;
V_39 = V_16 ;
V_11 = F_6 ( V_39 , V_17 ) ;
F_7 ( V_38 [ 0 ] , V_11 , V_39 ) ;
if ( V_11 == NULL )
F_5 ( V_14 L_16
L_3 ) ;
else {
F_5 ( L_4 , V_11 ) ;
F_8 ( V_11 ) ;
}
if ( V_29 < 0 ) {
F_5 ( V_14 L_17 , - V_29 ) ;
goto V_46;
}
V_4 -> V_47 = V_37 [ 0 ] ;
V_4 -> V_48 = V_38 [ 0 ] ;
F_21 ( V_4 -> V_2 , F_9 , & V_4 -> V_48 ) ;
return V_37 [ 0 ] ;
V_46:
F_13 ( V_38 [ 0 ] ) ;
F_13 ( V_38 [ 1 ] ) ;
V_44:
F_13 ( V_37 [ 0 ] ) ;
F_13 ( V_37 [ 1 ] ) ;
return V_29 ;
}
static void F_22 ( int V_8 , void * V_1 )
{
struct V_3 * V_4 = V_1 ;
F_21 ( V_4 -> V_2 , F_10 , & V_4 -> V_48 ) ;
F_13 ( V_8 ) ;
if ( F_23 ( V_4 -> V_47 , V_49 ) < 0 )
F_5 ( V_14 L_18
L_19 , V_15 ) ;
if ( F_23 ( V_4 -> V_48 , V_49 ) < 0 )
F_5 ( V_14 L_20
L_21 , V_15 ) ;
F_13 ( V_4 -> V_47 ) ;
V_4 -> V_47 = - 1 ;
F_13 ( V_4 -> V_48 ) ;
V_4 -> V_48 = - 1 ;
}
static void F_24 ( unsigned char * V_6 , unsigned char * V_7 ,
void * V_1 )
{
struct V_3 * V_4 = V_1 ;
F_25 ( V_4 -> V_40 , V_6 ) ;
if ( V_4 -> V_48 == - 1 )
return;
F_9 ( V_6 , V_7 , & V_4 -> V_48 ) ;
}
static void F_26 ( unsigned char * V_6 , unsigned char * V_7 ,
void * V_1 )
{
struct V_3 * V_4 = V_1 ;
if ( V_4 -> V_48 == - 1 )
return;
F_10 ( V_6 , V_7 , & V_4 -> V_48 ) ;
}
