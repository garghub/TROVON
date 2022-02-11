void F_1 ( int V_1 , void * V_2 )
{
F_2 ( V_1 ) ;
}
int F_3 ( int V_1 , char * V_3 , void * V_2 )
{
int V_4 ;
V_4 = F_4 ( V_1 , V_3 , sizeof( * V_3 ) ) ;
if ( V_4 > 0 )
return V_4 ;
else if ( V_5 == V_6 )
return 0 ;
else if ( V_4 == 0 )
return - V_7 ;
return - V_5 ;
}
int F_5 ( int V_1 , const char * V_8 , int V_4 , void * V_2 )
{
int V_9 ;
V_9 = F_6 ( V_1 , V_8 , V_4 ) ;
if ( V_9 > 0 )
return V_9 ;
else if ( V_5 == V_6 )
return 0 ;
else if ( V_9 == 0 )
return - V_7 ;
return - V_5 ;
}
int F_7 ( int V_1 , void * V_2 , unsigned short * V_10 ,
unsigned short * V_11 )
{
struct V_12 V_13 ;
int V_14 ;
if ( F_8 ( V_1 , V_15 , & V_13 ) < 0 )
return - V_5 ;
V_14 = ( ( * V_10 != V_13 . V_16 ) || ( * V_11 != V_13 . V_17 ) ) ;
* V_10 = V_13 . V_16 ;
* V_11 = V_13 . V_17 ;
return V_14 ;
}
void F_9 ( void * V_18 )
{
F_10 ( V_18 ) ;
}
int F_11 ( int V_1 , const char * V_8 , int V_4 )
{
T_1 V_19 , V_20 ;
struct V_21 V_22 , V_23 ;
int V_9 ;
if ( F_12 ( V_1 ) ) {
F_13 ( & V_20 ) ;
F_14 ( & V_20 , V_24 ) ;
if ( F_15 ( V_25 , & V_20 , & V_19 ) )
goto error;
F_16 ( V_9 = F_17 ( V_1 , & V_22 ) ) ;
if ( V_9 )
goto error;
V_23 = V_22 ;
V_23 . V_26 |= V_27 ;
F_16 ( V_9 = F_18 ( V_1 , V_28 , & V_23 ) ) ;
if ( V_9 )
goto error;
}
V_9 = F_5 ( V_1 , V_8 , V_4 , NULL ) ;
if ( F_12 ( V_1 ) ) {
F_16 ( F_18 ( V_1 , V_28 , & V_22 ) ) ;
F_15 ( V_29 , & V_19 , NULL ) ;
}
return V_9 ;
error:
return - V_5 ;
}
static void F_19 ( int V_30 )
{
}
static int F_20 ( void * V_31 )
{
struct V_32 * V_18 = V_31 ;
T_1 V_33 ;
int V_34 , V_35 ;
int V_36 ;
char V_37 = 1 ;
V_34 = V_18 -> V_34 ;
V_35 = V_18 -> V_35 ;
V_36 = F_6 ( V_35 , & V_37 , sizeof( V_37 ) ) ;
if ( V_36 != sizeof( V_37 ) )
F_21 ( V_38 L_1
L_2 , - V_36 ) ;
signal ( V_39 , F_19 ) ;
F_22 ( & V_33 ) ;
if ( F_15 ( V_29 , & V_33 , NULL ) < 0 ) {
F_21 ( V_38 L_3
L_4 , V_5 ) ;
exit ( 1 ) ;
}
F_23 ( & V_33 , V_39 ) ;
if ( F_24 () < 0 ) {
F_21 ( V_38 L_5 ,
V_5 ) ;
exit ( 1 ) ;
}
if ( F_8 ( V_34 , V_40 , 0 ) < 0 ) {
F_21 ( V_38 L_6
L_7 , V_34 , V_5 ) ;
exit ( 1 ) ;
}
if ( F_25 ( V_34 , F_26 () ) < 0 ) {
F_21 ( V_38 L_8
L_7 , V_34 , V_5 ) ;
exit ( 1 ) ;
}
V_36 = F_4 ( V_35 , & V_37 , sizeof( V_37 ) ) ;
if ( V_36 != sizeof( V_37 ) )
F_21 ( V_38 L_9
L_2 , V_5 ) ;
while( 1 ) {
F_27 ( & V_33 ) ;
V_36 = F_6 ( V_35 , & V_37 , sizeof( V_37 ) ) ;
if ( V_36 != sizeof( V_37 ) )
F_21 ( V_38 L_10
L_11 , V_5 ) ;
}
}
static int F_28 ( int V_1 , struct V_41 * V_42 , int * V_43 ,
unsigned long * V_44 )
{
struct V_32 V_18 ;
int V_45 [ 2 ] , V_4 , V_9 ;
char V_37 ;
V_9 = F_29 ( V_45 , 1 , 1 ) ;
if ( V_9 < 0 ) {
F_21 ( V_38 L_12 ,
- V_9 ) ;
goto V_46;
}
V_18 = ( (struct V_32 ) { . V_34 = V_1 ,
. V_35 = V_45 [ 1 ] } ) ;
V_9 = F_30 ( F_20 , & V_18 , V_47 , V_44 ) ;
if ( V_9 < 0 ) {
F_21 ( V_38 L_13 ,
- V_9 ) ;
goto V_48;
}
* V_43 = V_45 [ 0 ] ;
V_4 = F_4 ( V_45 [ 0 ] , & V_37 , sizeof( V_37 ) ) ;
if ( V_4 != sizeof( V_37 ) ) {
F_21 ( V_38 L_14
L_15 ) ;
F_21 ( V_38 L_16 , V_5 ) ;
F_21 ( V_38 L_17 , V_1 ) ;
V_9 = - V_49 ;
goto V_48;
}
if ( F_31 ( * V_43 , 0 ) ) {
F_21 ( V_38 L_18
L_19 ) ;
goto V_48;
}
return V_9 ;
V_48:
F_2 ( V_45 [ 1 ] ) ;
F_2 ( V_45 [ 0 ] ) ;
V_46:
return V_9 ;
}
void F_32 ( int V_1 , struct V_41 * V_42 )
{
unsigned long V_50 ;
int V_51 , V_52 , V_36 , V_53 = - 1 ;
char V_37 = 1 ;
if ( ! F_12 ( V_1 ) )
return;
V_51 = F_33 ( V_1 ) ;
if ( F_34 ( V_51 , V_1 , V_42 ) ) {
F_35 ( - 1 , V_1 , - 1 , V_42 , 0 ) ;
return;
}
if ( V_51 == - 1 ) {
V_52 = F_28 ( V_1 , V_42 , & V_53 , & V_50 ) ;
if ( V_52 < 0 )
return;
F_35 ( V_53 , V_1 , V_52 , V_42 , V_50 ) ;
V_36 = F_6 ( V_53 , & V_37 , sizeof( V_37 ) ) ;
if ( V_36 != sizeof( V_37 ) )
F_21 ( V_38 L_20
L_2 , V_5 ) ;
}
}
