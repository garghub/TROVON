void F_1 ( T_1 * V_1 , T_2 * V_2 )
{
fprintf ( V_2 , L_1 , V_1 -> V_3 ) ;
fprintf ( V_2 , L_2 , V_1 -> V_4 ) ;
fprintf ( V_2 , L_3 , V_1 -> V_5 ) ;
fprintf ( V_2 , L_4 , V_1 -> V_6 ) ;
fprintf ( V_2 , L_5 , V_1 -> V_7 ) ;
fprintf ( V_2 , L_6 , V_1 -> V_8 ) ;
fprintf ( V_2 , L_7 , V_1 -> V_9 ) ;
fprintf ( V_2 , L_8 , V_1 -> V_10 ) ;
fprintf ( V_2 , L_9 , V_1 -> V_11 ) ;
fprintf ( V_2 , L_10 , V_1 -> V_12 ) ;
fprintf ( V_2 , L_11 , V_1 -> V_13 ) ;
fprintf ( V_2 , L_12 , V_1 -> V_14 ) ;
fprintf ( V_2 , L_13 , V_1 -> V_15 ) ;
fprintf ( V_2 , L_14 , V_1 -> V_16 ) ;
fprintf ( V_2 , L_15 , V_1 -> V_17 ) ;
fprintf ( V_2 , L_16 , V_1 -> V_18 ) ;
#ifdef F_2
fprintf ( V_2 , L_17 , V_1 -> V_19 ) ;
fprintf ( V_2 , L_18 , V_1 -> V_20 ) ;
fprintf ( V_2 , L_19 , V_1 -> V_21 ) ;
fprintf ( V_2 , L_20 , V_1 -> V_22 ) ;
#endif
}
void F_3 ( T_1 * V_1 , T_2 * V_2 )
{
T_3 * V_23 ;
unsigned int V_24 , V_25 ;
for ( V_24 = 0 ; V_24 < V_1 -> V_4 ; V_24 ++ )
{
for ( V_23 = V_1 -> V_26 [ V_24 ] , V_25 = 0 ; V_23 != NULL ; V_23 = V_23 -> V_27 )
V_25 ++ ;
fprintf ( V_2 , L_21 , V_24 , V_25 ) ;
}
}
void F_4 ( T_1 * V_1 , T_2 * V_2 )
{
T_3 * V_23 ;
unsigned long V_25 ;
unsigned int V_24 ;
unsigned long V_28 = 0 , V_29 = 0 ;
for ( V_24 = 0 ; V_24 < V_1 -> V_4 ; V_24 ++ )
{
for ( V_23 = V_1 -> V_26 [ V_24 ] , V_25 = 0 ; V_23 != NULL ; V_23 = V_23 -> V_27 )
V_25 ++ ;
if ( V_25 != 0 )
{
V_29 ++ ;
V_28 += V_25 ;
}
}
fprintf ( V_2 , L_22 , V_29 , V_1 -> V_4 ) ;
fprintf ( V_2 , L_23 , V_28 ) ;
if ( V_29 == 0 ) return;
fprintf ( V_2 , L_24 ,
( int ) ( V_28 / V_1 -> V_4 ) ,
( int ) ( ( V_28 % V_1 -> V_4 ) * 100 / V_1 -> V_4 ) ,
( int ) ( V_28 / V_29 ) ,
( int ) ( ( V_28 % V_29 ) * 100 / V_29 ) ) ;
}
void F_1 ( T_1 * V_1 , T_2 * V_30 )
{
T_4 * V_31 ;
V_31 = F_5 ( F_6 () ) ;
if ( V_31 == NULL ) goto V_32;
F_7 ( V_31 , V_30 , V_33 ) ;
F_8 ( V_1 , V_31 ) ;
F_9 ( V_31 ) ;
V_32: ;
}
void F_3 ( T_1 * V_1 , T_2 * V_30 )
{
T_4 * V_31 ;
V_31 = F_5 ( F_6 () ) ;
if ( V_31 == NULL ) goto V_32;
F_7 ( V_31 , V_30 , V_33 ) ;
F_10 ( V_1 , V_31 ) ;
F_9 ( V_31 ) ;
V_32: ;
}
void F_4 ( T_1 * V_1 , T_2 * V_30 )
{
T_4 * V_31 ;
V_31 = F_5 ( F_6 () ) ;
if ( V_31 == NULL ) goto V_32;
F_7 ( V_31 , V_30 , V_33 ) ;
F_11 ( V_1 , V_31 ) ;
F_9 ( V_31 ) ;
V_32: ;
}
void F_8 ( T_1 * V_1 , T_4 * V_2 )
{
char V_34 [ 128 ] ;
sprintf ( V_34 , L_1 , V_1 -> V_3 ) ;
F_12 ( V_2 , V_34 ) ;
sprintf ( V_34 , L_2 , V_1 -> V_4 ) ;
F_12 ( V_2 , V_34 ) ;
sprintf ( V_34 , L_3 , V_1 -> V_5 ) ;
F_12 ( V_2 , V_34 ) ;
sprintf ( V_34 , L_4 , V_1 -> V_6 ) ;
F_12 ( V_2 , V_34 ) ;
sprintf ( V_34 , L_5 , V_1 -> V_7 ) ;
F_12 ( V_2 , V_34 ) ;
sprintf ( V_34 , L_6 , V_1 -> V_8 ) ;
F_12 ( V_2 , V_34 ) ;
sprintf ( V_34 , L_7 , V_1 -> V_9 ) ;
F_12 ( V_2 , V_34 ) ;
sprintf ( V_34 , L_8 , V_1 -> V_10 ) ;
F_12 ( V_2 , V_34 ) ;
sprintf ( V_34 , L_9 , V_1 -> V_11 ) ;
F_12 ( V_2 , V_34 ) ;
sprintf ( V_34 , L_10 , V_1 -> V_12 ) ;
F_12 ( V_2 , V_34 ) ;
sprintf ( V_34 , L_11 , V_1 -> V_13 ) ;
F_12 ( V_2 , V_34 ) ;
sprintf ( V_34 , L_12 , V_1 -> V_14 ) ;
F_12 ( V_2 , V_34 ) ;
sprintf ( V_34 , L_13 , V_1 -> V_15 ) ;
F_12 ( V_2 , V_34 ) ;
sprintf ( V_34 , L_14 , V_1 -> V_16 ) ;
F_12 ( V_2 , V_34 ) ;
sprintf ( V_34 , L_15 , V_1 -> V_17 ) ;
F_12 ( V_2 , V_34 ) ;
sprintf ( V_34 , L_16 , V_1 -> V_18 ) ;
F_12 ( V_2 , V_34 ) ;
#ifdef F_2
sprintf ( V_34 , L_17 , V_1 -> V_19 ) ;
F_12 ( V_2 , V_34 ) ;
sprintf ( V_34 , L_18 , V_1 -> V_20 ) ;
F_12 ( V_2 , V_34 ) ;
sprintf ( V_34 , L_19 , V_1 -> V_21 ) ;
F_12 ( V_2 , V_34 ) ;
sprintf ( V_34 , L_20 , V_1 -> V_22 ) ;
F_12 ( V_2 , V_34 ) ;
#endif
}
void F_10 ( T_1 * V_1 , T_4 * V_2 )
{
T_3 * V_23 ;
unsigned int V_24 , V_25 ;
char V_34 [ 128 ] ;
for ( V_24 = 0 ; V_24 < V_1 -> V_4 ; V_24 ++ )
{
for ( V_23 = V_1 -> V_26 [ V_24 ] , V_25 = 0 ; V_23 != NULL ; V_23 = V_23 -> V_27 )
V_25 ++ ;
sprintf ( V_34 , L_21 , V_24 , V_25 ) ;
F_12 ( V_2 , V_34 ) ;
}
}
void F_11 ( T_1 * V_1 , T_4 * V_2 )
{
T_3 * V_23 ;
unsigned long V_25 ;
unsigned int V_24 ;
unsigned long V_28 = 0 , V_29 = 0 ;
char V_34 [ 128 ] ;
for ( V_24 = 0 ; V_24 < V_1 -> V_4 ; V_24 ++ )
{
for ( V_23 = V_1 -> V_26 [ V_24 ] , V_25 = 0 ; V_23 != NULL ; V_23 = V_23 -> V_27 )
V_25 ++ ;
if ( V_25 != 0 )
{
V_29 ++ ;
V_28 += V_25 ;
}
}
sprintf ( V_34 , L_22 , V_29 , V_1 -> V_4 ) ;
F_12 ( V_2 , V_34 ) ;
sprintf ( V_34 , L_23 , V_28 ) ;
F_12 ( V_2 , V_34 ) ;
if ( V_29 == 0 ) return;
sprintf ( V_34 , L_24 ,
( int ) ( V_28 / V_1 -> V_4 ) ,
( int ) ( ( V_28 % V_1 -> V_4 ) * 100 / V_1 -> V_4 ) ,
( int ) ( V_28 / V_29 ) ,
( int ) ( ( V_28 % V_29 ) * 100 / V_29 ) ) ;
F_12 ( V_2 , V_34 ) ;
}
