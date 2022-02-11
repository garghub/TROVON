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
V_9 / 1e3 ,
F_11 ( V_11 , V_9 ) ) ;
}
static void F_12 ( T_2 * V_15 ,
T_3 V_16 )
{
T_4 V_17 ;
unsigned int V_18 ;
V_3 = V_14 ;
for ( V_18 = 0 ; V_18 < V_14 ; V_18 ++ ) {
F_13 ( & V_17 ) ;
F_14 ( V_18 % V_19 , & V_17 ) ;
if ( F_15 ( & V_16 , sizeof( T_4 ) , & V_17 ) )
F_16 ( V_20 , L_2 ) ;
if ( F_17 ( & V_15 [ V_18 ] , & V_16 , F_1 , NULL ) )
F_16 ( V_20 , L_3 ) ;
}
}
static void F_18 ( int T_5 V_1 ,
T_6 * T_7 V_1 ,
void * T_8 V_1 )
{
V_21 = true ;
}
int F_19 ( int V_22 , const char * * V_23 ,
const char * T_9 V_1 )
{
int V_24 = 0 ;
unsigned int V_18 , V_25 ;
struct V_26 V_27 ;
T_3 V_16 ;
V_22 = F_20 ( V_22 , V_23 , V_28 , V_29 , 0 ) ;
if ( V_22 ) {
F_21 ( V_29 , V_28 ) ;
exit ( V_20 ) ;
}
V_19 = F_22 ( V_30 ) ;
F_23 ( & V_27 . V_31 ) ;
V_27 . V_32 = F_18 ;
V_26 ( V_33 , & V_27 , NULL ) ;
if ( ! V_14 )
V_14 = V_19 ;
V_34 = calloc ( V_14 , sizeof( * V_34 ) ) ;
if ( ! V_34 )
F_16 ( V_20 , L_4 ) ;
if ( ! V_35 )
V_7 = V_36 ;
printf ( L_5
L_6 ,
F_24 () , V_14 , V_35 ? L_7 : L_8 , & V_6 , V_37 ) ;
F_25 ( & V_13 ) ;
F_25 ( & V_10 ) ;
F_26 ( & V_16 ) ;
F_27 ( & V_2 , NULL ) ;
F_28 ( & V_4 , NULL ) ;
F_28 ( & V_5 , NULL ) ;
for ( V_25 = 0 ; V_25 < V_38 && ! V_21 ; V_25 ++ ) {
unsigned int V_39 = 0 ;
struct V_40 V_41 , V_42 , V_43 ;
F_12 ( V_34 , V_16 ) ;
F_2 ( & V_2 ) ;
while ( V_3 )
F_4 ( & V_4 , & V_2 ) ;
F_29 ( & V_5 ) ;
F_5 ( & V_2 ) ;
F_30 ( 100000 ) ;
F_31 ( & V_41 , NULL ) ;
while ( V_39 != V_14 )
V_39 += F_32 ( & V_6 , V_37 , V_7 ) ;
F_31 ( & V_42 , NULL ) ;
F_33 ( & V_42 , & V_41 , & V_43 ) ;
F_34 ( & V_13 , V_39 ) ;
F_34 ( & V_10 , V_43 . V_44 ) ;
if ( ! V_45 ) {
printf ( L_9 ,
V_25 + 1 , V_39 , V_14 , V_43 . V_44 / 1e3 ) ;
}
for ( V_18 = 0 ; V_18 < V_14 ; V_18 ++ ) {
V_24 = F_35 ( V_34 [ V_18 ] , NULL ) ;
if ( V_24 )
F_16 ( V_20 , L_10 ) ;
}
}
F_36 ( & V_4 ) ;
F_36 ( & V_5 ) ;
F_37 ( & V_2 ) ;
F_38 ( & V_16 ) ;
F_8 () ;
free ( V_34 ) ;
return V_24 ;
}
