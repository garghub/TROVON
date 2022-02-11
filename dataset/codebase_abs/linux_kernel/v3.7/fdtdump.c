static void F_1 ( const char * V_1 , int V_2 )
{
int V_3 ;
const char * V_4 = V_1 ;
if ( V_2 == 0 )
return;
if ( F_2 ( V_1 , V_2 ) ) {
printf ( L_1 , ( const char * ) V_1 ) ;
} else if ( ( V_2 % 4 ) == 0 ) {
printf ( L_2 ) ;
for ( V_3 = 0 ; V_3 < V_2 ; V_3 += 4 )
printf ( L_3 , F_3 ( F_4 ( V_4 ) ) ,
V_3 < ( V_2 - 4 ) ? L_4 : L_5 ) ;
printf ( L_6 ) ;
} else {
printf ( L_7 ) ;
for ( V_3 = 0 ; V_3 < V_2 ; V_3 ++ )
printf ( L_8 , * V_4 ++ , V_3 < V_2 - 1 ? L_4 : L_5 ) ;
printf ( L_9 ) ;
}
}
static void F_5 ( void * V_5 )
{
struct V_6 * V_7 = V_5 ;
T_1 V_8 = F_3 ( V_7 -> V_8 ) ;
T_1 V_9 = F_3 ( V_7 -> V_10 ) ;
T_1 V_11 = F_3 ( V_7 -> V_12 ) ;
struct V_13 * V_14 =
(struct V_13 * ) ( ( char * ) V_5 + V_8 ) ;
const char * V_15 = ( const char * ) V_5 + V_9 ;
const char * V_16 = ( const char * ) V_5 + V_11 ;
T_1 V_17 = F_3 ( V_7 -> V_17 ) ;
T_1 V_18 = F_3 ( V_7 -> V_18 ) ;
T_1 V_19 ;
const char * V_4 , * V_20 , * V_21 ;
int V_22 , V_23 , V_24 ;
int V_3 ;
T_2 V_25 , V_26 ;
V_22 = 0 ;
V_24 = 4 ;
printf ( L_10 ) ;
printf ( L_11 , F_3 ( V_7 -> V_27 ) ) ;
printf ( L_12 , V_18 , V_18 ) ;
printf ( L_13 , V_9 ) ;
printf ( L_14 , V_11 ) ;
printf ( L_15 , V_8 ) ;
printf ( L_16 , V_17 ) ;
printf ( L_17 ,
F_3 ( V_7 -> V_28 ) ) ;
if ( V_17 >= 2 )
printf ( L_18 ,
F_3 ( V_7 -> V_29 ) ) ;
if ( V_17 >= 3 )
printf ( L_19 ,
F_3 ( V_7 -> V_30 ) ) ;
if ( V_17 >= 17 )
printf ( L_20 ,
F_3 ( V_7 -> V_31 ) ) ;
printf ( L_21 ) ;
for ( V_3 = 0 ; ; V_3 ++ ) {
V_25 = F_6 ( V_14 [ V_3 ] . V_32 ) ;
V_26 = F_6 ( V_14 [ V_3 ] . V_26 ) ;
if ( V_25 == 0 && V_26 == 0 )
break;
printf ( L_22 ,
( unsigned long long ) V_25 , ( unsigned long long ) V_26 ) ;
}
V_4 = V_15 ;
while ( ( V_19 = F_3 ( F_4 ( V_4 ) ) ) != V_33 ) {
if ( V_19 == V_34 ) {
V_20 = V_4 ;
V_4 = F_7 ( V_4 + strlen ( V_20 ) + 1 , 4 ) ;
if ( * V_20 == '\0' )
V_20 = L_23 ;
printf ( L_24 , V_22 * V_24 , L_5 , V_20 ) ;
V_22 ++ ;
continue;
}
if ( V_19 == V_35 ) {
V_22 -- ;
printf ( L_25 , V_22 * V_24 , L_5 ) ;
continue;
}
if ( V_19 == V_36 ) {
printf ( L_26 , V_22 * V_24 , L_5 ) ;
continue;
}
if ( V_19 != V_37 ) {
fprintf ( V_38 , L_27 , V_22 * V_24 , L_5 , V_19 ) ;
break;
}
V_23 = F_3 ( F_4 ( V_4 ) ) ;
V_20 = V_16 + F_3 ( F_4 ( V_4 ) ) ;
if ( V_17 < 16 && V_23 >= 8 )
V_4 = F_7 ( V_4 , 8 ) ;
V_21 = V_4 ;
V_4 = F_7 ( V_4 + V_23 , 4 ) ;
printf ( L_28 , V_22 * V_24 , L_5 , V_20 ) ;
F_1 ( V_21 , V_23 ) ;
printf ( L_29 ) ;
}
}
int main ( int V_39 , char * V_40 [] )
{
char * V_41 ;
if ( V_39 < 2 ) {
fprintf ( V_38 , L_30 ) ;
return 5 ;
}
V_41 = F_8 ( V_40 [ 1 ] ) ;
if ( V_41 )
F_5 ( V_41 ) ;
else
return 10 ;
return 0 ;
}
