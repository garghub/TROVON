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
#if 0
fprintf(out,"p = %u\n",lh->p);
fprintf(out,"pmax = %u\n",lh->pmax);
fprintf(out,"up_load = %lu\n",lh->up_load);
fprintf(out,"down_load = %lu\n",lh->down_load);
#endif
}
void F_2 ( T_1 * V_1 , T_2 * V_2 )
{
T_3 * V_19 ;
unsigned int V_20 , V_21 ;
for ( V_20 = 0 ; V_20 < V_1 -> V_4 ; V_20 ++ )
{
for ( V_19 = V_1 -> V_22 [ V_20 ] , V_21 = 0 ; V_19 != NULL ; V_19 = V_19 -> V_23 )
V_21 ++ ;
fprintf ( V_2 , L_17 , V_20 , V_21 ) ;
}
}
void F_3 ( T_1 * V_1 , T_2 * V_2 )
{
T_3 * V_19 ;
unsigned long V_21 ;
unsigned int V_20 ;
unsigned long V_24 = 0 , V_25 = 0 ;
for ( V_20 = 0 ; V_20 < V_1 -> V_4 ; V_20 ++ )
{
for ( V_19 = V_1 -> V_22 [ V_20 ] , V_21 = 0 ; V_19 != NULL ; V_19 = V_19 -> V_23 )
V_21 ++ ;
if ( V_21 != 0 )
{
V_25 ++ ;
V_24 += V_21 ;
}
}
fprintf ( V_2 , L_18 , V_25 , V_1 -> V_4 ) ;
fprintf ( V_2 , L_19 , V_24 ) ;
if ( V_25 == 0 ) return;
fprintf ( V_2 , L_20 ,
( int ) ( V_24 / V_1 -> V_4 ) ,
( int ) ( ( V_24 % V_1 -> V_4 ) * 100 / V_1 -> V_4 ) ,
( int ) ( V_24 / V_25 ) ,
( int ) ( ( V_24 % V_25 ) * 100 / V_25 ) ) ;
}
void F_1 ( const T_4 * V_1 , T_2 * V_26 )
{
T_5 * V_27 ;
V_27 = F_4 ( F_5 () ) ;
if ( V_27 == NULL ) goto V_28;
F_6 ( V_27 , V_26 , V_29 ) ;
F_7 ( V_1 , V_27 ) ;
F_8 ( V_27 ) ;
V_28: ;
}
void F_2 ( const T_4 * V_1 , T_2 * V_26 )
{
T_5 * V_27 ;
V_27 = F_4 ( F_5 () ) ;
if ( V_27 == NULL ) goto V_28;
F_6 ( V_27 , V_26 , V_29 ) ;
F_9 ( V_1 , V_27 ) ;
F_8 ( V_27 ) ;
V_28: ;
}
void F_3 ( const T_4 * V_1 , T_2 * V_26 )
{
T_5 * V_27 ;
V_27 = F_4 ( F_5 () ) ;
if ( V_27 == NULL ) goto V_28;
F_6 ( V_27 , V_26 , V_29 ) ;
F_10 ( V_1 , V_27 ) ;
F_8 ( V_27 ) ;
V_28: ;
}
void F_7 ( const T_4 * V_1 , T_5 * V_2 )
{
F_11 ( V_2 , L_1 , V_1 -> V_3 ) ;
F_11 ( V_2 , L_2 , V_1 -> V_4 ) ;
F_11 ( V_2 , L_3 , V_1 -> V_5 ) ;
F_11 ( V_2 , L_4 , V_1 -> V_6 ) ;
F_11 ( V_2 , L_5 ,
V_1 -> V_7 ) ;
F_11 ( V_2 , L_6 , V_1 -> V_8 ) ;
F_11 ( V_2 , L_7 ,
V_1 -> V_9 ) ;
F_11 ( V_2 , L_8 , V_1 -> V_10 ) ;
F_11 ( V_2 , L_9 , V_1 -> V_11 ) ;
F_11 ( V_2 , L_10 , V_1 -> V_12 ) ;
F_11 ( V_2 , L_11 , V_1 -> V_13 ) ;
F_11 ( V_2 , L_12 , V_1 -> V_14 ) ;
F_11 ( V_2 , L_13 , V_1 -> V_15 ) ;
F_11 ( V_2 , L_14 , V_1 -> V_16 ) ;
F_11 ( V_2 , L_15 , V_1 -> V_17 ) ;
F_11 ( V_2 , L_16 , V_1 -> V_18 ) ;
#if 0
BIO_printf(out,"p = %u\n",lh->p);
BIO_printf(out,"pmax = %u\n",lh->pmax);
BIO_printf(out,"up_load = %lu\n",lh->up_load);
BIO_printf(out,"down_load = %lu\n",lh->down_load);
#endif
}
void F_9 ( const T_4 * V_1 , T_5 * V_2 )
{
T_3 * V_19 ;
unsigned int V_20 , V_21 ;
for ( V_20 = 0 ; V_20 < V_1 -> V_4 ; V_20 ++ )
{
for ( V_19 = V_1 -> V_22 [ V_20 ] , V_21 = 0 ; V_19 != NULL ; V_19 = V_19 -> V_23 )
V_21 ++ ;
F_11 ( V_2 , L_17 , V_20 , V_21 ) ;
}
}
void F_10 ( const T_4 * V_1 , T_5 * V_2 )
{
T_3 * V_19 ;
unsigned long V_21 ;
unsigned int V_20 ;
unsigned long V_24 = 0 , V_25 = 0 ;
for ( V_20 = 0 ; V_20 < V_1 -> V_4 ; V_20 ++ )
{
for ( V_19 = V_1 -> V_22 [ V_20 ] , V_21 = 0 ; V_19 != NULL ; V_19 = V_19 -> V_23 )
V_21 ++ ;
if ( V_21 != 0 )
{
V_25 ++ ;
V_24 += V_21 ;
}
}
F_11 ( V_2 , L_18 , V_25 , V_1 -> V_4 ) ;
F_11 ( V_2 , L_19 , V_24 ) ;
if ( V_25 == 0 ) return;
F_11 ( V_2 , L_20 ,
( int ) ( V_24 / V_1 -> V_4 ) ,
( int ) ( ( V_24 % V_1 -> V_4 ) * 100 / V_1 -> V_4 ) ,
( int ) ( V_24 / V_25 ) ,
( int ) ( ( V_24 % V_25 ) * 100 / V_25 ) ) ;
}
