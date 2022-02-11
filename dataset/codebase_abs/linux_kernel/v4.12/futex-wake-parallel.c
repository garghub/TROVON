static void * F_1 ( void * V_1 )
{
struct V_2 * V_3 = (struct V_2 * ) V_1 ;
struct V_4 V_5 , V_6 ;
F_2 ( & V_5 , NULL ) ;
V_3 -> V_7 = F_3 ( & V_8 , V_9 , V_10 ) ;
if ( V_3 -> V_7 != V_9 )
F_4 ( L_1 ,
V_3 -> V_7 , V_9 ) ;
F_2 ( & V_6 , NULL ) ;
F_5 ( & V_6 , & V_5 , & V_3 -> V_11 ) ;
F_6 ( NULL ) ;
return NULL ;
}
static void F_7 ( struct V_2 * V_12 , T_1 V_13 )
{
unsigned int V_14 ;
F_8 ( & V_13 , V_15 ) ;
for ( V_14 = 0 ; V_14 < V_16 ; V_14 ++ ) {
if ( F_9 ( & V_12 [ V_14 ] . V_17 , & V_13 ,
F_1 , ( void * ) & V_12 [ V_14 ] ) )
F_10 ( V_18 , L_2 ) ;
}
for ( V_14 = 0 ; V_14 < V_16 ; V_14 ++ )
if ( F_11 ( V_12 [ V_14 ] . V_17 , NULL ) )
F_10 ( V_18 , L_3 ) ;
}
static void * F_12 ( void * V_1 V_19 )
{
F_13 ( & V_20 ) ;
V_21 -- ;
if ( ! V_21 )
F_14 ( & V_22 ) ;
F_15 ( & V_23 , & V_20 ) ;
F_16 ( & V_20 ) ;
while ( 1 ) {
if ( F_17 ( & V_8 , 0 , NULL , V_10 ) != V_24 )
break;
}
F_6 ( NULL ) ;
return NULL ;
}
static void F_18 ( T_2 * V_25 , T_1 V_13 )
{
T_3 V_26 ;
unsigned int V_14 ;
V_21 = V_27 ;
for ( V_14 = 0 ; V_14 < V_27 ; V_14 ++ ) {
F_19 ( & V_26 ) ;
F_20 ( V_14 % V_28 , & V_26 ) ;
if ( F_21 ( & V_13 , sizeof( T_3 ) , & V_26 ) )
F_10 ( V_18 , L_4 ) ;
if ( F_9 ( & V_25 [ V_14 ] , & V_13 , F_12 , NULL ) )
F_10 ( V_18 , L_2 ) ;
}
}
static void F_22 ( struct V_2 * V_29 , unsigned int V_30 )
{
unsigned int V_14 , V_31 ;
double V_32 , V_33 ;
struct V_34 V_35 , V_36 ;
F_23 ( & V_36 ) ;
F_23 ( & V_35 ) ;
for ( V_14 = 0 ; V_14 < V_16 ; V_14 ++ ) {
F_24 ( & V_35 , V_29 [ V_14 ] . V_11 . V_37 ) ;
F_24 ( & V_36 , V_29 [ V_14 ] . V_7 ) ;
}
V_32 = F_25 ( & V_35 ) ;
V_33 = F_26 ( & V_35 ) ;
V_31 = F_25 ( & V_36 ) ;
printf ( L_5
L_6 , V_30 + 1 , V_31 ,
V_27 , V_32 / V_38 ,
F_27 ( V_33 , V_32 ) ) ;
}
static void F_28 ( void )
{
unsigned int V_31 ;
double V_32 , V_33 ;
V_32 = F_25 ( & V_39 ) ;
V_33 = F_26 ( & V_39 ) ;
V_31 = F_25 ( & V_40 ) ;
printf ( L_7 ,
V_31 ,
V_27 ,
V_32 / V_38 ,
F_27 ( V_33 , V_32 ) ) ;
}
static void F_29 ( struct V_2 * V_29 )
{
unsigned int V_14 ;
for ( V_14 = 0 ; V_14 < V_16 ; V_14 ++ ) {
F_24 ( & V_39 , V_29 [ V_14 ] . V_11 . V_37 ) ;
F_24 ( & V_40 , V_29 [ V_14 ] . V_7 ) ;
}
}
static void F_30 ( int T_4 V_19 ,
T_5 * T_6 V_19 ,
void * T_7 V_19 )
{
V_41 = true ;
}
int F_31 ( int V_42 , const char * * V_43 )
{
int V_44 = 0 ;
unsigned int V_14 , V_45 ;
struct V_46 V_47 ;
T_1 V_13 ;
struct V_2 * V_29 ;
V_42 = F_32 ( V_42 , V_43 , V_48 ,
V_49 , 0 ) ;
if ( V_42 ) {
F_33 ( V_49 , V_48 ) ;
exit ( V_18 ) ;
}
F_34 ( & V_47 . V_50 ) ;
V_47 . V_51 = F_30 ;
V_46 ( V_52 , & V_47 , NULL ) ;
V_28 = F_35 ( V_53 ) ;
if ( ! V_27 )
V_27 = V_28 ;
if ( V_16 > V_27 || ! V_16 )
V_16 = V_27 ;
if ( V_27 % V_16 )
F_36 ( V_18 , L_8 ) ;
V_9 = V_27 / V_16 ;
V_54 = calloc ( V_27 , sizeof( * V_54 ) ) ;
if ( ! V_54 )
F_10 ( V_18 , L_9 ) ;
if ( ! V_55 )
V_10 = V_56 ;
printf ( L_10
L_11 ,
F_37 () , V_27 , V_55 ? L_12 : L_13 ,
& V_8 , V_16 , V_9 ) ;
F_23 ( & V_40 ) ;
F_23 ( & V_39 ) ;
F_38 ( & V_13 ) ;
F_39 ( & V_20 , NULL ) ;
F_40 ( & V_22 , NULL ) ;
F_40 ( & V_23 , NULL ) ;
for ( V_45 = 0 ; V_45 < V_57 && ! V_41 ; V_45 ++ ) {
V_29 = calloc ( V_16 , sizeof( * V_29 ) ) ;
if ( ! V_29 )
F_10 ( V_18 , L_9 ) ;
F_18 ( V_54 , V_13 ) ;
F_13 ( & V_20 ) ;
while ( V_21 )
F_15 ( & V_22 , & V_20 ) ;
F_41 ( & V_23 ) ;
F_16 ( & V_20 ) ;
F_42 ( 100000 ) ;
F_7 ( V_29 , V_13 ) ;
for ( V_14 = 0 ; V_14 < V_27 ; V_14 ++ ) {
V_44 = F_11 ( V_54 [ V_14 ] , NULL ) ;
if ( V_44 )
F_10 ( V_18 , L_3 ) ;
}
F_29 ( V_29 ) ;
if ( ! V_58 )
F_22 ( V_29 , V_45 ) ;
free ( V_29 ) ;
}
F_43 ( & V_22 ) ;
F_43 ( & V_23 ) ;
F_44 ( & V_20 ) ;
F_45 ( & V_13 ) ;
F_28 () ;
free ( V_54 ) ;
return V_44 ;
}
