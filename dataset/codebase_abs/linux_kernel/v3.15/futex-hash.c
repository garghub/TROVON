static void * F_1 ( void * V_1 )
{
int V_2 ;
unsigned int V_3 ;
struct V_4 * V_5 = (struct V_4 * ) V_1 ;
F_2 ( & V_6 ) ;
V_7 -- ;
if ( ! V_7 )
F_3 ( & V_8 ) ;
F_4 ( & V_9 , & V_6 ) ;
F_5 ( & V_6 ) ;
do {
for ( V_3 = 0 ; V_3 < V_10 ; V_3 ++ , V_5 -> V_11 ++ ) {
V_2 = F_6 ( & V_5 -> V_12 [ V_3 ] , 1234 , NULL ,
V_13 ? 0 : V_14 ) ;
if ( ! V_15 &&
( ! V_2 || V_16 != V_17 || V_16 != V_18 ) )
F_7 ( L_1 ) ;
}
} while ( ! V_19 );
return NULL ;
}
static void F_8 ( int T_1 V_20 ,
T_2 * T_3 V_20 ,
void * T_4 V_20 )
{
V_19 = true ;
F_9 ( & V_21 , NULL ) ;
F_10 ( & V_21 , & V_22 , & V_23 ) ;
}
static void F_11 ( void )
{
unsigned long V_24 = F_12 ( & V_25 ) ;
double V_26 = F_13 ( & V_25 ) ;
printf ( L_2 ,
! V_15 ? L_3 : L_4 , V_24 , F_14 ( V_26 , V_24 ) ,
( int ) V_23 . V_27 ) ;
}
int F_15 ( int V_28 , const char * * V_29 ,
const char * T_5 V_20 )
{
int V_2 = 0 ;
T_6 V_30 ;
struct V_31 V_32 ;
unsigned int V_3 , V_33 ;
T_7 V_34 ;
struct V_4 * V_4 = NULL ;
V_28 = F_16 ( V_28 , V_29 , V_35 , V_36 , 0 ) ;
if ( V_28 ) {
F_17 ( V_36 , V_35 ) ;
exit ( V_37 ) ;
}
V_33 = F_18 ( V_38 ) ;
F_19 ( & V_32 . V_39 ) ;
V_32 . V_40 = F_8 ;
V_31 ( V_41 , & V_32 , NULL ) ;
if ( ! V_42 )
V_42 = V_33 ;
V_4 = calloc ( V_42 , sizeof( * V_4 ) ) ;
if ( ! V_4 )
goto V_43;
printf ( L_5 ,
F_20 () , V_42 , V_10 , V_13 ? L_6 : L_7 , V_44 ) ;
F_21 ( & V_25 ) ;
F_22 ( & V_6 , NULL ) ;
F_23 ( & V_8 , NULL ) ;
F_23 ( & V_9 , NULL ) ;
V_7 = V_42 ;
F_24 ( & V_34 ) ;
F_9 ( & V_22 , NULL ) ;
for ( V_3 = 0 ; V_3 < V_42 ; V_3 ++ ) {
V_4 [ V_3 ] . V_45 = V_3 ;
V_4 [ V_3 ] . V_12 = calloc ( V_10 , sizeof( * V_4 [ V_3 ] . V_12 ) ) ;
if ( ! V_4 [ V_3 ] . V_12 )
goto V_43;
F_25 ( & V_30 ) ;
F_26 ( V_3 % V_33 , & V_30 ) ;
V_2 = F_27 ( & V_34 , sizeof( T_6 ) , & V_30 ) ;
if ( V_2 )
F_28 ( V_37 , L_8 ) ;
V_2 = F_29 ( & V_4 [ V_3 ] . V_46 , & V_34 , F_1 ,
( void * ) (struct V_4 * ) & V_4 [ V_3 ] ) ;
if ( V_2 )
F_28 ( V_37 , L_9 ) ;
}
F_30 ( & V_34 ) ;
F_2 ( & V_6 ) ;
while ( V_7 )
F_4 ( & V_8 , & V_6 ) ;
F_31 ( & V_9 ) ;
F_5 ( & V_6 ) ;
F_32 ( V_44 ) ;
F_8 ( 0 , NULL , NULL ) ;
for ( V_3 = 0 ; V_3 < V_42 ; V_3 ++ ) {
V_2 = F_33 ( V_4 [ V_3 ] . V_46 , NULL ) ;
if ( V_2 )
F_28 ( V_37 , L_10 ) ;
}
F_34 ( & V_8 ) ;
F_34 ( & V_9 ) ;
F_35 ( & V_6 ) ;
for ( V_3 = 0 ; V_3 < V_42 ; V_3 ++ ) {
unsigned long V_47 = V_4 [ V_3 ] . V_11 / V_23 . V_27 ;
F_36 ( & V_25 , V_47 ) ;
if ( ! V_15 ) {
if ( V_10 == 1 )
printf ( L_11 ,
V_4 [ V_3 ] . V_45 , & V_4 [ V_3 ] . V_12 [ 0 ] , V_47 ) ;
else
printf ( L_12 ,
V_4 [ V_3 ] . V_45 , & V_4 [ V_3 ] . V_12 [ 0 ] ,
& V_4 [ V_3 ] . V_12 [ V_10 - 1 ] , V_47 ) ;
}
free ( V_4 [ V_3 ] . V_12 ) ;
}
F_11 () ;
free ( V_4 ) ;
return V_2 ;
V_43:
F_28 ( V_37 , L_13 ) ;
}
