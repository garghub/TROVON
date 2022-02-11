static void F_1 ( void )
{
double V_1 = F_2 ( & V_2 ) ;
double V_3 = F_3 ( & V_2 ) ;
unsigned int V_4 = F_2 ( & V_5 ) ;
printf ( L_1 ,
V_4 ,
V_6 ,
V_1 / V_7 ,
F_4 ( V_3 , V_1 ) ) ;
}
static void * F_5 ( void * T_1 V_8 )
{
F_6 ( & V_9 ) ;
V_10 -- ;
if ( ! V_10 )
F_7 ( & V_11 ) ;
F_8 ( & V_12 , & V_9 ) ;
F_9 ( & V_9 ) ;
F_10 ( & V_13 , 0 , NULL , V_14 ) ;
return NULL ;
}
static void F_11 ( T_2 * V_15 ,
T_3 V_16 )
{
T_4 V_17 ;
unsigned int V_18 ;
V_10 = V_6 ;
for ( V_18 = 0 ; V_18 < V_6 ; V_18 ++ ) {
F_12 ( & V_17 ) ;
F_13 ( V_18 % V_19 , & V_17 ) ;
if ( F_14 ( & V_16 , sizeof( T_4 ) , & V_17 ) )
F_15 ( V_20 , L_2 ) ;
if ( F_16 ( & V_15 [ V_18 ] , & V_16 , F_5 , NULL ) )
F_15 ( V_20 , L_3 ) ;
}
}
static void F_17 ( int T_5 V_8 ,
T_6 * T_7 V_8 ,
void * T_8 V_8 )
{
V_21 = true ;
}
int F_18 ( int V_22 , const char * * V_23 ,
const char * T_9 V_8 )
{
int V_24 = 0 ;
unsigned int V_18 , V_25 ;
struct V_26 V_27 ;
T_3 V_16 ;
V_22 = F_19 ( V_22 , V_23 , V_28 , V_29 , 0 ) ;
if ( V_22 )
goto F_15;
V_19 = F_20 ( V_30 ) ;
F_21 ( & V_27 . V_31 ) ;
V_27 . V_32 = F_17 ;
V_26 ( V_33 , & V_27 , NULL ) ;
if ( ! V_6 )
V_6 = V_19 ;
else
V_6 = F_22 ( V_6 ) ;
V_34 = calloc ( V_6 , sizeof( * V_34 ) ) ;
if ( ! V_34 )
F_15 ( V_20 , L_4 ) ;
if ( ! V_35 )
V_14 = V_36 ;
if ( V_37 > V_6 )
V_37 = V_6 ;
printf ( L_5
L_6 , F_23 () , V_6 ,
V_35 ? L_7 : L_8 , & V_13 , & V_38 , V_37 ) ;
F_24 ( & V_5 ) ;
F_24 ( & V_2 ) ;
F_25 ( & V_16 ) ;
F_26 ( & V_9 , NULL ) ;
F_27 ( & V_11 , NULL ) ;
F_27 ( & V_12 , NULL ) ;
for ( V_25 = 0 ; V_25 < V_39 && ! V_21 ; V_25 ++ ) {
unsigned int V_40 = 0 ;
struct V_41 V_42 , V_43 , V_44 ;
F_11 ( V_34 , V_16 ) ;
F_6 ( & V_9 ) ;
while ( V_10 )
F_8 ( & V_11 , & V_9 ) ;
F_28 ( & V_12 ) ;
F_9 ( & V_9 ) ;
F_29 ( 100000 ) ;
F_30 ( & V_42 , NULL ) ;
while ( V_40 < V_6 ) {
V_40 += F_31 ( & V_13 , 0 , & V_38 , 0 ,
V_37 , V_14 ) ;
}
F_30 ( & V_43 , NULL ) ;
F_32 ( & V_43 , & V_42 , & V_44 ) ;
F_33 ( & V_5 , V_40 ) ;
F_33 ( & V_2 , V_44 . V_45 ) ;
if ( ! V_46 ) {
printf ( L_9 ,
V_25 + 1 , V_40 , V_6 , V_44 . V_45 / ( double ) V_7 ) ;
}
V_40 = F_34 ( & V_38 , V_40 , V_14 ) ;
if ( V_6 != V_40 )
F_35 ( L_10 , V_40 , V_6 ) ;
for ( V_18 = 0 ; V_18 < V_6 ; V_18 ++ ) {
V_24 = F_36 ( V_34 [ V_18 ] , NULL ) ;
if ( V_24 )
F_15 ( V_20 , L_11 ) ;
}
}
F_37 ( & V_11 ) ;
F_37 ( & V_12 ) ;
F_38 ( & V_9 ) ;
F_39 ( & V_16 ) ;
F_1 () ;
free ( V_34 ) ;
return V_24 ;
F_15:
F_40 ( V_29 , V_28 ) ;
exit ( V_20 ) ;
}
