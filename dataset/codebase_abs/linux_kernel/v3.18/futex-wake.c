static void * F_1 ( void * T_1 V_1 )
{
F_2 ( & V_2 ) ;
V_3 -- ;
if ( ! V_3 )
F_3 ( & V_4 ) ;
F_4 ( & V_5 , & V_2 ) ;
F_5 ( & V_2 ) ;
F_6 ( & V_6 , 0 , NULL , V_7 ) ;
return NULL ;
}
static void F_7 ( void )
{
double V_8 = F_8 ( & V_9 ) ;
double V_10 = F_9 ( & V_9 ) ;
unsigned int V_11 = F_8 ( & V_12 ) ;
printf ( L_1 ,
V_11 ,
V_13 ,
V_8 / 1e3 ,
F_10 ( V_10 , V_8 ) ) ;
}
static void F_11 ( T_2 * V_14 ,
T_3 V_15 )
{
T_4 V_16 ;
unsigned int V_17 ;
V_3 = V_13 ;
for ( V_17 = 0 ; V_17 < V_13 ; V_17 ++ ) {
F_12 ( & V_16 ) ;
F_13 ( V_17 % V_18 , & V_16 ) ;
if ( F_14 ( & V_15 , sizeof( T_4 ) , & V_16 ) )
F_15 ( V_19 , L_2 ) ;
if ( F_16 ( & V_14 [ V_17 ] , & V_15 , F_1 , NULL ) )
F_15 ( V_19 , L_3 ) ;
}
}
static void F_17 ( int T_5 V_1 ,
T_6 * T_7 V_1 ,
void * T_8 V_1 )
{
V_20 = true ;
}
int F_18 ( int V_21 , const char * * V_22 ,
const char * T_9 V_1 )
{
int V_23 = 0 ;
unsigned int V_17 , V_24 ;
struct V_25 V_26 ;
T_3 V_15 ;
V_21 = F_19 ( V_21 , V_22 , V_27 , V_28 , 0 ) ;
if ( V_21 ) {
F_20 ( V_28 , V_27 ) ;
exit ( V_19 ) ;
}
V_18 = F_21 ( V_29 ) ;
F_22 ( & V_26 . V_30 ) ;
V_26 . V_31 = F_17 ;
V_25 ( V_32 , & V_26 , NULL ) ;
if ( ! V_13 )
V_13 = V_18 ;
V_33 = calloc ( V_13 , sizeof( * V_33 ) ) ;
if ( ! V_33 )
F_15 ( V_19 , L_4 ) ;
if ( ! V_34 )
V_7 = V_35 ;
printf ( L_5
L_6 ,
F_23 () , V_13 , V_34 ? L_7 : L_8 , & V_6 , V_36 ) ;
F_24 ( & V_12 ) ;
F_24 ( & V_9 ) ;
F_25 ( & V_15 ) ;
F_26 ( & V_2 , NULL ) ;
F_27 ( & V_4 , NULL ) ;
F_27 ( & V_5 , NULL ) ;
for ( V_24 = 0 ; V_24 < V_37 && ! V_20 ; V_24 ++ ) {
unsigned int V_38 = 0 ;
struct V_39 V_40 , V_41 , V_42 ;
F_11 ( V_33 , V_15 ) ;
F_2 ( & V_2 ) ;
while ( V_3 )
F_4 ( & V_4 , & V_2 ) ;
F_28 ( & V_5 ) ;
F_5 ( & V_2 ) ;
F_29 ( 100000 ) ;
F_30 ( & V_40 , NULL ) ;
while ( V_38 != V_13 )
V_38 += F_31 ( & V_6 , V_36 , V_7 ) ;
F_30 ( & V_41 , NULL ) ;
F_32 ( & V_41 , & V_40 , & V_42 ) ;
F_33 ( & V_12 , V_38 ) ;
F_33 ( & V_9 , V_42 . V_43 ) ;
if ( ! V_44 ) {
printf ( L_9 ,
V_24 + 1 , V_38 , V_13 , V_42 . V_43 / 1e3 ) ;
}
for ( V_17 = 0 ; V_17 < V_13 ; V_17 ++ ) {
V_23 = F_34 ( V_33 [ V_17 ] , NULL ) ;
if ( V_23 )
F_15 ( V_19 , L_10 ) ;
}
}
F_35 ( & V_4 ) ;
F_35 ( & V_5 ) ;
F_36 ( & V_2 ) ;
F_37 ( & V_15 ) ;
F_7 () ;
free ( V_33 ) ;
return V_23 ;
}
