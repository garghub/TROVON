void F_1 ( int V_1 , T_1 V_2 , int V_3 , int V_4 ,
int V_5 , unsigned long * V_6 ,
int * V_7 )
{
if ( V_1 < 3 ) {
* V_6 = ( V_2 + V_3 - 1 ) / ( 8 * V_3 ) ;
* V_7 = V_5 + * V_6 ;
* V_7 = ( * V_7 + V_3 - 1 ) /
V_3 ;
* V_7 *= V_3 ;
}
else {
* V_6 = F_2 ( V_2 , V_3 ) ;
* V_6 = F_2 ( * V_6 , 8 ) ;
* V_7 = V_5 + * V_6 ;
* V_7 = F_3 ( * V_7 , V_4 ) ;
}
}
static int F_4 ( char * V_8 , int V_2 , char * V_9 )
{
char V_10 [ 256 ] , * V_11 ;
int V_12 ;
if ( F_5 ( V_10 , sizeof( V_10 ) ) == NULL ) {
F_6 ( L_1 ,
V_13 ) ;
return - 1 ;
}
V_11 = strrchr ( V_9 , '/' ) ;
if ( V_11 != NULL ) {
* V_11 = '\0' ;
if ( F_7 ( V_9 ) ) {
* V_11 = '/' ;
F_6 ( L_2
L_3 , V_9 , V_13 ) ;
return - 1 ;
}
* V_11 = '/' ;
if ( F_5 ( V_8 , V_2 ) == NULL ) {
F_6 ( L_4
L_3 , V_9 , V_13 ) ;
return - 1 ;
}
V_12 = V_2 - strlen ( V_8 ) ;
if ( strlen ( V_11 ) + 1 > V_12 ) {
F_6 ( L_5
L_6 , V_9 , V_2 ) ;
return - 1 ;
}
strcat ( V_8 , V_11 ) ;
}
else {
if ( strlen ( V_10 ) + 1 + strlen ( V_9 ) + 1 > V_2 ) {
F_6 ( L_5
L_6 , V_9 , V_2 ) ;
return - 1 ;
}
strcpy ( V_8 , V_10 ) ;
strcat ( V_8 , L_7 ) ;
strcat ( V_8 , V_9 ) ;
}
F_7 ( V_10 ) ;
return 0 ;
}
int F_8 ( char * V_14 , int V_15 , char * V_16 ,
int V_3 , int V_17 , unsigned long long * V_2 )
{
struct V_18 * V_19 ;
unsigned long V_20 ;
int V_21 ;
V_21 = F_9 ( V_15 , 0 ) ;
if ( V_21 < 0 ) {
F_6 ( L_8 , - V_21 ) ;
goto V_22;
}
V_21 = - V_23 ;
V_19 = F_10 ( sizeof( * V_19 ) ) ;
if ( V_19 == NULL ) {
F_6 ( L_9
L_10 ) ;
goto V_22;
}
V_19 -> V_24 = F_11 ( V_25 ) ;
V_19 -> V_1 = F_11 ( V_26 ) ;
V_21 = - V_27 ;
if ( strlen ( V_16 ) > sizeof( V_19 -> V_16 ) - 1 ) {
F_6 ( L_11
L_12 , V_16 ,
sizeof( V_19 -> V_16 ) - 1 ) ;
goto V_28;
}
if ( F_4 ( V_19 -> V_16 , sizeof( V_19 -> V_16 ) ,
V_16 ) )
goto V_28;
V_21 = F_12 ( V_19 -> V_16 , & V_20 ) ;
if ( V_21 < 0 ) {
F_6 ( L_13
L_14 , V_19 -> V_16 ,
- V_21 ) ;
goto V_28;
}
V_21 = F_13 ( V_19 -> V_16 , V_2 ) ;
if ( V_21 < 0 ) {
F_6 ( L_15
L_16 ,
V_19 -> V_16 , - V_21 ) ;
goto V_28;
}
V_19 -> V_29 = F_11 ( V_20 ) ;
V_19 -> V_2 = F_14 ( * V_2 ) ;
V_19 -> V_3 = F_11 ( V_3 ) ;
V_19 -> V_17 = F_11 ( V_17 ) ;
V_19 -> V_30 = V_31 ;
V_21 = F_15 ( V_15 , V_19 , sizeof( * V_19 ) ) ;
if ( V_21 != sizeof( * V_19 ) ) {
F_6 ( L_17
L_18 , V_14 ,
- V_21 ) ;
goto V_28;
}
V_21 = 0 ;
V_28:
F_16 ( V_19 ) ;
V_22:
return V_21 ;
}
int F_17 ( T_1 V_32 , char * V_33 , int V_34 , void * V_35 )
{
int V_15 = * ( ( int * ) V_35 ) ;
return F_18 ( V_15 , V_33 , V_34 , V_32 ) ;
}
int F_19 ( int (* F_20)( T_1 , char * , int , void * ) , void * V_35 ,
T_2 * V_36 , char * * V_37 ,
T_3 * V_38 , unsigned long long * V_39 ,
int * V_40 , T_2 * V_41 ,
int * V_42 )
{
union V_43 * V_19 ;
char * V_44 ;
int V_21 , V_45 ;
unsigned long V_1 , V_24 ;
V_19 = F_10 ( sizeof( * V_19 ) ) ;
if ( V_19 == NULL ) {
F_6 ( L_19 ) ;
return - V_23 ;
}
V_21 = - V_27 ;
V_45 = (* F_20)( 0 , ( char * ) V_19 , sizeof( * V_19 ) , V_35 ) ;
if ( V_45 < F_21 ( F_22 ( V_19 -> V_46 ) , V_16 ) ) {
F_6 ( L_20 ) ;
goto V_22;
}
V_24 = V_19 -> V_46 . V_24 ;
if ( V_24 == V_25 )
V_1 = V_19 -> V_46 . V_1 ;
else if ( V_24 == F_23 ( V_25 ) )
V_1 = F_23 ( V_19 -> V_46 . V_1 ) ;
else goto V_22;
* V_36 = V_1 ;
if ( V_1 == 1 ) {
if ( V_45 < sizeof( V_19 -> V_46 ) ) {
F_6 ( L_21
L_10 ) ;
goto V_22;
}
* V_38 = V_19 -> V_46 . V_29 ;
* V_39 = V_19 -> V_46 . V_2 ;
* V_40 = V_19 -> V_46 . V_3 ;
* V_42 = sizeof( V_19 -> V_46 ) ;
* V_41 = * V_40 ;
V_44 = V_19 -> V_46 . V_16 ;
}
else if ( V_1 == 2 ) {
if ( V_45 < sizeof( V_19 -> V_47 ) ) {
F_6 ( L_22
L_10 ) ;
goto V_22;
}
* V_38 = F_23 ( V_19 -> V_47 . V_29 ) ;
* V_39 = F_24 ( V_19 -> V_47 . V_2 ) ;
* V_40 = F_23 ( V_19 -> V_47 . V_3 ) ;
* V_42 = sizeof( V_19 -> V_47 ) ;
* V_41 = * V_40 ;
V_44 = V_19 -> V_47 . V_16 ;
}
else if ( V_1 == 3 && ( * ( ( int * ) V_19 -> V_48 . V_16 ) != 0 ) ) {
if ( V_45 < sizeof( V_19 -> V_48 ) ) {
F_6 ( L_23
L_10 ) ;
goto V_22;
}
* V_38 = F_23 ( V_19 -> V_48 . V_29 ) ;
* V_39 = F_24 ( V_19 -> V_48 . V_2 ) ;
* V_40 = F_23 ( V_19 -> V_48 . V_3 ) ;
* V_41 = F_23 ( V_19 -> V_48 . V_17 ) ;
if ( * V_41 == 0 ) {
F_6 ( L_24
L_25 ) ;
}
* V_42 = F_3 ( sizeof( V_19 -> V_48 ) , * V_41 ) ;
V_44 = V_19 -> V_48 . V_16 ;
}
else if ( V_1 == 3 ) {
F_6 ( L_26
L_27 ) ;
if ( V_45 < sizeof( V_19 -> V_49 ) ) {
F_6 ( L_23
L_10 ) ;
goto V_22;
}
* V_38 = ( V_50 ) F_23 ( V_19 -> V_49 . V_29 ) ;
* V_39 = F_24 ( V_19 -> V_49 . V_2 ) ;
* V_40 = F_23 ( V_19 -> V_49 . V_3 ) ;
* V_41 = F_23 ( V_19 -> V_49 . V_17 ) ;
if ( * V_41 == 0 ) {
F_6 ( L_24
L_25 ) ;
}
* V_42 = F_3 ( sizeof( V_19 -> V_49 ) , * V_41 ) ;
V_44 = V_19 -> V_49 . V_16 ;
}
else {
F_6 ( L_28 ) ;
goto V_22;
}
V_21 = - V_23 ;
* V_37 = F_25 ( V_44 ) ;
if ( * V_37 == NULL ) {
F_6 ( L_29
L_30 ) ;
goto V_22;
}
V_21 = 0 ;
V_22:
F_16 ( V_19 ) ;
return V_21 ;
}
int F_26 ( int V_15 , char * V_14 , char * V_16 , int V_3 ,
int V_17 , int * V_42 ,
unsigned long * V_6 , int * V_7 )
{
unsigned long long V_2 , V_32 ;
char V_51 = 0 ;
int V_21 ;
V_21 = F_8 ( V_14 , V_15 , V_16 , V_3 ,
V_17 , & V_2 ) ;
if ( V_21 )
goto V_22;
* V_42 = F_3 ( sizeof( struct V_18 ) , V_17 ) ;
F_1 ( V_26 , V_2 , V_3 , V_17 , * V_42 ,
V_6 , V_7 ) ;
V_32 = * V_7 + V_2 - sizeof( V_51 ) ;
V_21 = F_9 ( V_15 , V_32 ) ;
if ( V_21 < 0 ) {
F_6 ( L_31 , - V_21 ) ;
goto V_22;
}
V_21 = F_15 ( V_15 , & V_51 , sizeof( V_51 ) ) ;
if ( V_21 != sizeof( V_51 ) ) {
F_6 ( L_32
L_33 , V_14 , - V_21 ) ;
if ( V_21 >= 0 )
V_21 = - V_27 ;
goto V_22;
}
return 0 ;
V_22:
return V_21 ;
}
