static void * F_1 ( void * T_1 V_1 )
{
F_2 ( & V_2 ) ;
V_3 -- ;
if ( ! V_3 )
F_3 ( & V_4 ) ;
F_4 ( & V_5 , & V_2 ) ;
F_5 ( & V_2 ) ;
while ( 1 ) {
if ( F_6 ( & V_6 , 0 , NULL , V_7 ) != V_8 )
break;
}
F_7 ( NULL ) ;
return NULL ;
}
static void F_8 ( void )
{
double V_9 = F_9 ( & V_10 ) ;
double V_11 = F_10 ( & V_10 ) ;
unsigned int V_12 = F_9 ( & V_13 ) ;
printf ( L_1 ,
V_12 ,
V_14 ,
V_9 / V_15 ,
F_11 ( V_11 , V_9 ) ) ;
}
static void F_12 ( T_2 * V_16 ,
T_3 V_17 )
{
T_4 V_18 ;
unsigned int V_19 ;
V_3 = V_14 ;
for ( V_19 = 0 ; V_19 < V_14 ; V_19 ++ ) {
F_13 ( & V_18 ) ;
F_14 ( V_19 % V_20 , & V_18 ) ;
if ( F_15 ( & V_17 , sizeof( T_4 ) , & V_18 ) )
F_16 ( V_21 , L_2 ) ;
if ( F_17 ( & V_16 [ V_19 ] , & V_17 , F_1 , NULL ) )
F_16 ( V_21 , L_3 ) ;
}
}
static void F_18 ( int T_5 V_1 ,
T_6 * T_7 V_1 ,
void * T_8 V_1 )
{
V_22 = true ;
}
int F_19 ( int V_23 , const char * * V_24 )
{
int V_25 = 0 ;
unsigned int V_19 , V_26 ;
struct V_27 V_28 ;
T_3 V_17 ;
V_23 = F_20 ( V_23 , V_24 , V_29 , V_30 , 0 ) ;
if ( V_23 ) {
F_21 ( V_30 , V_29 ) ;
exit ( V_21 ) ;
}
V_20 = F_22 ( V_31 ) ;
F_23 ( & V_28 . V_32 ) ;
V_28 . V_33 = F_18 ;
V_27 ( V_34 , & V_28 , NULL ) ;
if ( ! V_14 )
V_14 = V_20 ;
V_35 = calloc ( V_14 , sizeof( * V_35 ) ) ;
if ( ! V_35 )
F_16 ( V_21 , L_4 ) ;
if ( ! V_36 )
V_7 = V_37 ;
printf ( L_5
L_6 ,
F_24 () , V_14 , V_36 ? L_7 : L_8 , & V_6 , V_38 ) ;
F_25 ( & V_13 ) ;
F_25 ( & V_10 ) ;
F_26 ( & V_17 ) ;
F_27 ( & V_2 , NULL ) ;
F_28 ( & V_4 , NULL ) ;
F_28 ( & V_5 , NULL ) ;
for ( V_26 = 0 ; V_26 < V_39 && ! V_22 ; V_26 ++ ) {
unsigned int V_40 = 0 ;
struct V_41 V_42 , V_43 , V_44 ;
F_12 ( V_35 , V_17 ) ;
F_2 ( & V_2 ) ;
while ( V_3 )
F_4 ( & V_4 , & V_2 ) ;
F_29 ( & V_5 ) ;
F_5 ( & V_2 ) ;
F_30 ( 100000 ) ;
F_31 ( & V_42 , NULL ) ;
while ( V_40 != V_14 )
V_40 += F_32 ( & V_6 , V_38 , V_7 ) ;
F_31 ( & V_43 , NULL ) ;
F_33 ( & V_43 , & V_42 , & V_44 ) ;
F_34 ( & V_13 , V_40 ) ;
F_34 ( & V_10 , V_44 . V_45 ) ;
if ( ! V_46 ) {
printf ( L_9 ,
V_26 + 1 , V_40 , V_14 , V_44 . V_45 / ( double ) V_15 ) ;
}
for ( V_19 = 0 ; V_19 < V_14 ; V_19 ++ ) {
V_25 = F_35 ( V_35 [ V_19 ] , NULL ) ;
if ( V_25 )
F_16 ( V_21 , L_10 ) ;
}
}
F_36 ( & V_4 ) ;
F_36 ( & V_5 ) ;
F_37 ( & V_2 ) ;
F_38 ( & V_17 ) ;
F_8 () ;
free ( V_35 ) ;
return V_25 ;
}
