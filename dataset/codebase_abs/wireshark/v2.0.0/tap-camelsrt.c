static void F_1 ( void * V_1 )
{
struct V_2 * V_3 = (struct V_2 * ) V_1 ;
memset ( V_3 , 0 , sizeof( struct V_2 ) ) ;
}
static int F_2 ( void * V_1 ,
T_1 * T_2 V_4 ,
T_3 * T_4 V_4 ,
const void * V_5 )
{
struct V_2 * V_3 = (struct V_2 * ) V_1 ;
const struct V_6 * V_7 = ( const struct V_6 * ) V_5 ;
int V_8 ;
for ( V_8 = 0 ; V_8 < V_9 ; V_8 ++ ) {
if ( V_7 -> V_10 [ V_8 ] &&
V_7 -> V_11 [ V_8 ] . V_12
&& V_7 -> V_11 [ V_8 ] . V_13
&& ! V_7 -> V_11 [ V_8 ] . V_14 ) {
F_3 ( & ( V_3 -> V_15 [ V_8 ] ) ,
& ( V_7 -> V_11 [ V_8 ] . V_16 ) ,
T_2 ) ;
if ( V_3 -> V_17 [ V_8 ] < V_18 ) {
V_3 -> V_16 [ V_8 ] [ V_3 -> V_17 [ V_8 ] ++ ]
= V_7 -> V_11 [ V_8 ] . V_16 ;
}
}
}
return 1 ;
}
static void F_4 ( void * V_1 )
{
struct V_2 * V_3 = (struct V_2 * ) V_1 ;
T_5 V_19 , V_20 ;
T_6 V_21 ;
int V_22 , V_23 = 0 ;
T_7 * V_24 ;
double V_25 , V_26 , V_27 , V_28 , V_29 ;
double V_30 [ V_31 ] = { 5.0 , 10.0 , 75.0 , 90.0 , 95.0 , 99.0 , 99.90 } ;
double V_32 [ V_31 ] ;
T_8 * V_33 ;
printf ( L_1 ) ;
printf ( L_2 ) ;
printf ( L_3 ) ;
printf ( L_4 ) ;
printf ( L_5 ) ;
V_19 = 1 ;
V_33 = F_5 ( NULL , V_19 , V_34 , L_6 ) ;
printf ( L_7 ,
V_33 ,
V_3 -> V_15 [ V_19 ] . V_35 ,
F_6 ( & ( V_3 -> V_15 [ V_19 ] . V_36 ) ) ,
F_6 ( & ( V_3 -> V_15 [ V_19 ] . V_37 ) ) ,
F_7 ( & ( V_3 -> V_15 [ V_19 ] . V_38 ) , V_3 -> V_15 [ V_19 ] . V_35 ) / 1000.0 ,
V_3 -> V_15 [ V_19 ] . V_39 ,
V_3 -> V_15 [ V_19 ] . V_40
) ;
F_8 ( NULL , V_33 ) ;
for ( V_19 = 2 ; V_19 < V_9 ; V_19 ++ ) {
if ( V_3 -> V_15 [ V_19 ] . V_35 == 0 ) {
V_33 = F_5 ( NULL , V_19 , V_34 , L_6 ) ;
printf ( L_8 ,
V_33 , 0U , 0.0 , 0.0 , 0.0 , 0U , 0U ) ;
F_8 ( NULL , V_33 ) ;
continue;
}
V_33 = F_5 ( NULL , V_19 , V_34 , L_6 ) ;
printf ( L_8 ,
V_33 ,
V_3 -> V_15 [ V_19 ] . V_35 ,
F_9 ( 9999 , F_10 ( & ( V_3 -> V_15 [ V_19 ] . V_36 ) ) ) ,
F_9 ( 9999 , F_10 ( & ( V_3 -> V_15 [ V_19 ] . V_37 ) ) ) ,
F_9 ( 9999 , F_7 ( & ( V_3 -> V_15 [ V_19 ] . V_38 ) , V_3 -> V_15 [ V_19 ] . V_35 ) ) ,
V_3 -> V_15 [ V_19 ] . V_39 ,
V_3 -> V_15 [ V_19 ] . V_40
) ;
F_8 ( NULL , V_33 ) ;
}
printf ( L_3 ) ;
printf ( L_9 ) ;
for ( V_20 = 0 ; V_20 < V_31 ; V_20 ++ ) printf ( L_10 , V_30 [ V_20 ] ) ;
printf ( L_1 ) ;
printf ( L_11 ) ;
for ( V_20 = 0 ; V_20 < V_31 ; V_20 ++ ) printf ( L_12 ) ;
printf ( L_1 ) ;
for ( V_19 = 2 ; V_19 < V_9 ; V_19 ++ ) {
V_24 = & ( V_3 -> V_15 [ V_19 ] ) ;
if ( V_3 -> V_17 [ V_19 ] > 0 ) {
for ( V_20 = 0 ; V_20 < V_31 ; V_20 ++ ) {
V_23 = 0 ;
V_27 = ( double ) V_24 -> V_37 . V_41 * 1000 + ( double ) V_24 -> V_37 . V_42 / 1000000 ;
V_28 = ( double ) V_24 -> V_36 . V_41 * 1000 + ( double ) V_24 -> V_36 . V_42 / 1000000 ;
V_26 = V_28 ;
V_29 = V_27 - V_28 ;
while ( ( V_29 > 0.001 ) && ( V_23 < 10000 ) ) {
V_22 = 0 ;
V_23 ++ ;
for ( V_21 = 0 ; V_21 < V_3 -> V_17 [ V_19 ] ; V_21 ++ ) {
V_25 = V_3 -> V_16 [ V_19 ] [ V_21 ] . V_41 * 1000
+ ( double ) V_3 -> V_16 [ V_19 ] [ V_21 ] . V_42 / 1000000 ;
if ( V_25 <= V_26 ) V_22 ++ ;
}
if ( V_22 * 100 > V_3 -> V_17 [ V_19 ] * V_30 [ V_20 ] ) {
V_27 = V_26 ;
V_26 = ( V_27 + V_28 ) / 2 ;
V_29 = V_27 - V_28 ;
} else {
V_28 = V_26 ;
V_26 = ( V_27 + V_28 ) / 2 ;
V_29 = V_27 - V_28 ;
}
}
V_32 [ V_20 ] = V_26 ;
}
V_33 = F_5 ( NULL , V_19 , V_34 , L_6 ) ;
printf ( L_13 , V_33 ) ;
F_8 ( NULL , V_33 ) ;
for ( V_20 = 0 ; V_20 < V_31 ; V_20 ++ ) printf ( L_14 , F_9 ( 9999 , V_32 [ V_20 ] ) ) ;
printf ( L_1 ) ;
} else {
V_33 = F_5 ( NULL , V_19 , V_34 , L_6 ) ;
printf ( L_13 , V_33 ) ;
F_8 ( NULL , V_33 ) ;
for ( V_20 = 0 ; V_20 < V_31 ; V_20 ++ ) printf ( L_14 , 0.0 ) ;
printf ( L_1 ) ;
}
}
printf ( L_15 ) ;
for ( V_20 = 0 ; V_20 < V_31 ; V_20 ++ ) printf ( L_16 ) ;
printf ( L_1 ) ;
}
static void F_11 ( const char * V_43 , void * T_9 V_4 )
{
struct V_2 * V_44 ;
T_10 * V_45 ;
V_44 = F_12 ( struct V_2 , 1 ) ;
if ( ! strncmp ( V_43 , L_17 , 9 ) ) {
V_44 -> V_46 = F_13 ( V_43 + 9 ) ;
} else {
V_44 -> V_46 = NULL ;
}
F_1 ( V_44 ) ;
V_45 = F_14 ( L_18 ,
V_44 ,
V_44 -> V_46 ,
0 ,
NULL ,
F_2 ,
F_4 ) ;
if ( V_45 ) {
F_15 ( V_44 -> V_46 ) ;
F_15 ( V_44 ) ;
fprintf ( V_47 , L_19 ,
V_45 -> V_48 ) ;
F_16 ( V_45 , TRUE ) ;
exit ( 1 ) ;
}
V_49 = TRUE ;
V_50 = TRUE ;
}
void
F_17 ( void )
{
F_18 ( & V_51 , NULL ) ;
}
