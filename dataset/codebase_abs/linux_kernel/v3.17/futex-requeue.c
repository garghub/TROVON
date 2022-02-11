static void F_1 ( void )
{
double V_1 = F_2 ( & V_2 ) ;
double V_3 = F_3 ( & V_2 ) ;
unsigned int V_4 = F_2 ( & V_5 ) ;
printf ( L_1 ,
V_4 ,
V_6 ,
V_1 / 1e3 ,
F_4 ( V_3 , V_1 ) ) ;
}
static void * F_5 ( void * T_1 V_7 )
{
F_6 ( & V_8 ) ;
V_9 -- ;
if ( ! V_9 )
F_7 ( & V_10 ) ;
F_8 ( & V_11 , & V_8 ) ;
F_9 ( & V_8 ) ;
F_10 ( & V_12 , 0 , NULL , V_13 ) ;
return NULL ;
}
static void F_11 ( T_2 * V_14 ,
T_3 V_15 )
{
T_4 V_16 ;
unsigned int V_17 ;
V_9 = V_6 ;
for ( V_17 = 0 ; V_17 < V_6 ; V_17 ++ ) {
F_12 ( & V_16 ) ;
F_13 ( V_17 % V_18 , & V_16 ) ;
if ( F_14 ( & V_15 , sizeof( T_4 ) , & V_16 ) )
F_15 ( V_19 , L_2 ) ;
if ( F_16 ( & V_14 [ V_17 ] , & V_15 , F_5 , NULL ) )
F_15 ( V_19 , L_3 ) ;
}
}
static void F_17 ( int T_5 V_7 ,
T_6 * T_7 V_7 ,
void * T_8 V_7 )
{
V_20 = true ;
}
int F_18 ( int V_21 , const char * * V_22 ,
const char * T_9 V_7 )
{
int V_23 = 0 ;
unsigned int V_17 , V_24 ;
struct V_25 V_26 ;
T_3 V_15 ;
V_21 = F_19 ( V_21 , V_22 , V_27 , V_28 , 0 ) ;
if ( V_21 )
goto F_15;
V_18 = F_20 ( V_29 ) ;
F_21 ( & V_26 . V_30 ) ;
V_26 . V_31 = F_17 ;
V_25 ( V_32 , & V_26 , NULL ) ;
if ( ! V_6 )
V_6 = V_18 ;
V_33 = calloc ( V_6 , sizeof( * V_33 ) ) ;
if ( ! V_33 )
F_15 ( V_19 , L_4 ) ;
printf ( L_5
L_6 ,
F_22 () , V_6 , & V_12 , & V_34 , V_35 ) ;
F_23 ( & V_5 ) ;
F_23 ( & V_2 ) ;
F_24 ( & V_15 ) ;
F_25 ( & V_8 , NULL ) ;
F_26 ( & V_10 , NULL ) ;
F_26 ( & V_11 , NULL ) ;
for ( V_24 = 0 ; V_24 < V_36 && ! V_20 ; V_24 ++ ) {
unsigned int V_37 = 0 ;
struct V_38 V_39 , V_40 , V_41 ;
F_11 ( V_33 , V_15 ) ;
F_6 ( & V_8 ) ;
while ( V_9 )
F_8 ( & V_10 , & V_8 ) ;
F_27 ( & V_11 ) ;
F_9 ( & V_8 ) ;
F_28 ( 100000 ) ;
F_29 ( & V_39 , NULL ) ;
for ( V_37 = 0 ; V_37 < V_6 ; V_37 += V_35 )
F_30 ( & V_12 , 0 , & V_34 , 0 , V_35 ,
V_13 ) ;
F_29 ( & V_40 , NULL ) ;
F_31 ( & V_40 , & V_39 , & V_41 ) ;
F_32 ( & V_5 , V_37 ) ;
F_32 ( & V_2 , V_41 . V_42 ) ;
if ( ! V_43 ) {
printf ( L_7 ,
V_24 + 1 , V_37 , V_6 , V_41 . V_42 / 1e3 ) ;
}
V_37 = F_33 ( & V_34 , V_6 , V_13 ) ;
if ( V_6 != V_37 )
F_34 ( L_8 , V_37 , V_6 ) ;
for ( V_17 = 0 ; V_17 < V_6 ; V_17 ++ ) {
V_23 = F_35 ( V_33 [ V_17 ] , NULL ) ;
if ( V_23 )
F_15 ( V_19 , L_9 ) ;
}
}
F_36 ( & V_10 ) ;
F_36 ( & V_11 ) ;
F_37 ( & V_8 ) ;
F_38 ( & V_15 ) ;
F_1 () ;
free ( V_33 ) ;
return V_23 ;
F_15:
F_39 ( V_28 , V_27 ) ;
exit ( V_19 ) ;
}
