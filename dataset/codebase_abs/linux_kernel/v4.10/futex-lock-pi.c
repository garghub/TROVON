static void F_1 ( void )
{
unsigned long V_1 = F_2 ( & V_2 ) ;
double V_3 = F_3 ( & V_2 ) ;
printf ( L_1 ,
! V_4 ? L_2 : L_3 , V_1 , F_4 ( V_3 , V_1 ) ,
( int ) V_5 . V_6 ) ;
}
static void F_5 ( int T_1 V_7 ,
T_2 * T_3 V_7 ,
void * T_4 V_7 )
{
V_8 = true ;
F_6 ( & V_9 , NULL ) ;
F_7 ( & V_9 , & V_10 , & V_5 ) ;
}
static void * F_8 ( void * V_11 )
{
struct V_12 * V_13 = (struct V_12 * ) V_11 ;
unsigned long V_14 = V_13 -> V_14 ;
F_9 ( & V_15 ) ;
V_16 -- ;
if ( ! V_16 )
F_10 ( & V_17 ) ;
F_11 ( & V_18 , & V_15 ) ;
F_12 ( & V_15 ) ;
do {
int V_19 ;
V_20:
V_19 = F_13 ( V_13 -> V_21 , NULL , V_22 ) ;
if ( V_19 ) {
if ( ! V_4 )
F_14 ( L_4 ,
V_13 -> V_23 , V_13 -> V_21 , V_19 ) ;
if ( V_8 )
break;
goto V_20;
}
F_15 ( 1 ) ;
V_19 = F_16 ( V_13 -> V_21 , V_22 ) ;
if ( V_19 && ! V_4 )
F_14 ( L_5 ,
V_13 -> V_23 , V_13 -> V_21 , V_19 ) ;
V_14 ++ ;
} while ( ! V_8 );
V_13 -> V_14 = V_14 ;
return NULL ;
}
static void F_17 ( struct V_12 * V_13 , T_5 V_24 )
{
T_6 V_25 ;
unsigned int V_26 ;
V_16 = V_27 ;
for ( V_26 = 0 ; V_26 < V_27 ; V_26 ++ ) {
V_12 [ V_26 ] . V_23 = V_26 ;
if ( V_28 ) {
V_12 [ V_26 ] . V_21 = calloc ( 1 , sizeof( V_29 ) ) ;
if ( ! V_12 [ V_26 ] . V_21 )
F_18 ( V_30 , L_6 ) ;
} else
V_12 [ V_26 ] . V_21 = & V_31 ;
F_19 ( & V_25 ) ;
F_20 ( V_26 % V_32 , & V_25 ) ;
if ( F_21 ( & V_24 , sizeof( T_6 ) , & V_25 ) )
F_18 ( V_30 , L_7 ) ;
if ( F_22 ( & V_13 [ V_26 ] . V_33 , & V_24 , F_8 , & V_12 [ V_26 ] ) )
F_18 ( V_30 , L_8 ) ;
}
}
int F_23 ( int V_34 , const char * * V_35 ,
const char * T_7 V_7 )
{
int V_19 = 0 ;
unsigned int V_26 ;
struct V_36 V_37 ;
T_5 V_24 ;
V_34 = F_24 ( V_34 , V_35 , V_38 , V_39 , 0 ) ;
if ( V_34 )
goto F_18;
V_32 = F_25 ( V_40 ) ;
V_41 = F_26 ( V_41 ) ;
F_27 ( & V_37 . V_42 ) ;
V_37 . V_43 = F_5 ;
V_36 ( V_44 , & V_37 , NULL ) ;
if ( ! V_27 )
V_27 = V_32 ;
else
V_27 = F_26 ( V_27 ) ;
V_12 = calloc ( V_27 , sizeof( * V_12 ) ) ;
if ( ! V_12 )
F_18 ( V_30 , L_6 ) ;
if ( ! V_45 )
V_22 = V_46 ;
printf ( L_9 ,
F_28 () , V_27 , V_41 ) ;
F_29 ( & V_2 ) ;
F_30 ( & V_15 , NULL ) ;
F_31 ( & V_17 , NULL ) ;
F_31 ( & V_18 , NULL ) ;
V_16 = V_27 ;
F_32 ( & V_24 ) ;
F_6 ( & V_10 , NULL ) ;
F_17 ( V_12 , V_24 ) ;
F_33 ( & V_24 ) ;
F_9 ( & V_15 ) ;
while ( V_16 )
F_11 ( & V_17 , & V_15 ) ;
F_34 ( & V_18 ) ;
F_12 ( & V_15 ) ;
F_35 ( V_41 ) ;
F_5 ( 0 , NULL , NULL ) ;
for ( V_26 = 0 ; V_26 < V_27 ; V_26 ++ ) {
V_19 = F_36 ( V_12 [ V_26 ] . V_33 , NULL ) ;
if ( V_19 )
F_18 ( V_30 , L_10 ) ;
}
F_37 ( & V_17 ) ;
F_37 ( & V_18 ) ;
F_38 ( & V_15 ) ;
for ( V_26 = 0 ; V_26 < V_27 ; V_26 ++ ) {
unsigned long V_47 = V_12 [ V_26 ] . V_14 / V_5 . V_6 ;
F_39 ( & V_2 , V_47 ) ;
if ( ! V_4 )
printf ( L_11 ,
V_12 [ V_26 ] . V_23 , V_12 [ V_26 ] . V_21 , V_47 ) ;
if ( V_28 )
free ( V_12 [ V_26 ] . V_21 ) ;
}
F_1 () ;
free ( V_12 ) ;
return V_19 ;
F_18:
F_40 ( V_39 , V_38 ) ;
exit ( V_30 ) ;
}
