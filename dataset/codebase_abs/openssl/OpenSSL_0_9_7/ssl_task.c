static int F_1 ( T_1 V_1 , char * V_2 , int V_3 , int * V_4 )
{
int V_5 ;
struct V_6 V_7 ;
V_5 = F_2 ( 0 , V_1 , V_8 , & V_7 , 0 , 0 ,
V_2 , V_3 , 0 , 0 , 0 , 0 ) ;
if ( ( V_5 & 1 ) == 1 ) V_5 = V_7 . V_5 ;
if ( ( V_5 & 1 ) == 1 ) * V_4 = V_7 . V_9 ;
return V_5 ;
}
static int F_3 ( T_1 V_1 , char * V_2 , int V_4 )
{
int V_5 ;
struct V_6 V_7 ;
V_5 = F_2 ( 0 , V_1 , V_10 , & V_7 , 0 , 0 ,
V_2 , V_4 , 0 , 0 , 0 , 0 ) ;
if ( ( V_5 & 1 ) == 1 ) V_5 = V_7 . V_5 ;
return V_5 ;
}
static int F_4 ( T_1 V_1 , struct V_11 * V_12 , int V_4 )
{
return 48 ;
}
int main ( int V_13 , char * * V_14 )
{
int V_5 , V_4 ;
T_1 V_1 ;
struct V_11 V_12 ;
char * V_15 = NULL , * V_16 = NULL ;
int V_17 = 0 ;
int V_18 = 1 ;
int V_19 = 0 ;
int V_20 = 0 ;
T_2 * V_21 = NULL ;
F_5 () ;
V_5 = F_6 ( & V_22 , & V_1 , 0 , 0 , 0 ) ;
printf ( L_1 , V_5 ) ;
if ( V_23 == NULL )
if ( ( V_23 = F_7 ( F_8 () ) ) != NULL )
F_9 ( V_23 , V_24 , V_25 ) ;
if ( V_26 == NULL )
if ( ( V_26 = F_7 ( F_8 () ) ) != NULL )
F_9 ( V_26 , stdout , V_25 ) ;
if ( V_27 == NULL ) V_27 = getenv ( L_2 ) ;
printf ( L_3 , V_27 ? V_27 : L_4 ) ;
F_10 () ;
F_11 () ;
V_21 = F_12 ( F_13 () ) ;
if ( V_21 == NULL ) goto V_28;
F_14 ( V_21 , V_29 , V_30 ) ;
F_15 ( V_21 , V_29 , V_30 ) ;
printf ( L_5 , V_29 ) ;
F_16 () ;
V_5 = F_17 ( V_1 , V_21 ) ;
F_16 () ;
V_28:
if ( V_21 != NULL ) F_18 ( V_21 ) ;
F_16 () ;
return 1 ;
}
int F_17 ( T_1 V_1 , T_2 * V_21 )
{
int V_5 , V_4 , V_31 ;
struct V_11 V_12 ;
T_3 * V_32 = NULL ;
T_4 * V_33 = NULL ;
T_4 * V_34 = NULL ;
T_4 * V_35 = NULL ;
T_4 * V_36 = NULL ;
int V_37 ;
int V_38 = 0 ;
V_32 = F_19 ( V_21 ) ;
if ( V_32 == NULL ) goto V_39;
V_33 = F_7 ( F_20 () ) ;
V_34 = F_7 ( F_20 () ) ;
if ( ( V_34 == NULL ) || ( V_33 == NULL ) ) goto V_39;
F_21 ( V_33 , 0 , V_1 ) ;
F_21 ( V_34 , 0 , V_1 ) ;
V_35 = F_7 ( F_22 () ) ;
V_36 = F_7 ( F_22 () ) ;
if ( ( V_35 == NULL ) || ( V_36 == NULL ) ) goto V_39;
F_23 ( V_32 ) ;
F_24 ( V_32 , V_33 , V_34 ) ;
F_25 ( V_36 , V_32 , V_40 ) ;
printf ( L_6 ) ;
for ( V_31 = 0 ; V_31 < 3 ; ) {
while ( V_31 == 0 ) {
V_5 = F_1 ( V_1 , ( char * ) & V_12 , sizeof( V_12 ) , & V_4 ) ;
if ( ( V_5 & 1 ) == 0 ) {
printf ( L_7 , V_5 ) ;
V_31 = 3 ;
break;
}
if ( V_4 < V_41 ) {
printf ( L_8 , V_4 ) ;
break;
V_31 = 3 ;
}
if ( V_12 . V_42 != 'A' ) {
printf ( L_9 ,
V_12 . V_42 ) ;
break;
V_31 = 3 ;
}
if ( V_12 . V_43 == 'G' ) {
V_31 = 1 ;
} else if ( V_12 . V_43 == 'P' ) {
V_31 = 2 ;
} else if ( V_12 . V_43 == 'X' ) {
V_31 = 3 ;
} else {
V_31 = 3 ;
}
}
if ( V_31 == 1 ) {
V_37 = F_26 ( V_36 , V_12 . V_44 , V_12 . V_4 ) ;
if ( V_37 < 0 ) V_31 = 3 ;
else {
V_12 . V_42 = 'A' ;
V_12 . V_43 = 'C' ;
V_12 . V_4 = V_37 ;
V_5 = F_3 ( V_1 , ( char * ) & V_12 , V_37 + V_41 ) ;
if ( ( V_5 & 1 ) == 0 ) break;
V_31 = 0 ;
}
} else if ( V_31 == 2 ) {
V_37 = F_27 ( V_36 , V_12 . V_44 , V_12 . V_4 ) ;
if ( V_37 < 0 ) V_31 = 3 ;
else {
V_12 . V_42 = 'A' ;
V_12 . V_43 = 'C' ;
V_12 . V_4 = 0 ;
V_5 = F_3 ( V_1 , ( char * ) & V_12 , V_41 ) ;
if ( ( V_5 & 1 ) == 0 ) break;
V_31 = 0 ;
}
}
}
fprintf ( stdout , L_10 ) ;
V_39:
V_32 -> V_45 = NULL ;
V_32 -> V_46 = NULL ;
if ( V_33 != NULL ) F_28 ( V_33 ) ;
if ( V_34 != NULL ) F_28 ( V_34 ) ;
if ( V_35 != NULL ) F_28 ( V_35 ) ;
if ( V_36 != NULL ) F_28 ( V_36 ) ;
return ( 0 ) ;
}
