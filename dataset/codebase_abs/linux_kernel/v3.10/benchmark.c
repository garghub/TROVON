unsigned int F_1 ( long V_1 , struct V_2 * V_2 )
{
int V_3 ;
long long V_4 , V_5 ;
unsigned int V_6 = V_7 ;
unsigned int V_8 = 0 ;
unsigned int V_9 = 0 ;
if ( V_2 -> V_10 )
printf ( L_1 , V_1 ) ;
V_4 = F_2 () ;
F_3 ( V_6 ) ;
V_5 = F_2 () ;
V_9 = ( unsigned int ) ( V_5 - V_4 ) ;
for ( V_3 = 0 ; V_3 < 4 ; V_3 ++ ) {
V_8 = ( unsigned int ) ( V_1 * V_6 / V_9 ) ;
F_4 ( L_2 , V_8 ) ;
V_4 = F_2 () ;
F_3 ( V_8 ) ;
V_5 = F_2 () ;
V_9 = ( unsigned int ) ( V_5 - V_4 ) ;
V_6 = V_8 ;
}
if ( V_2 -> V_10 )
printf ( L_3 ) ;
return V_6 ;
}
void F_5 ( struct V_2 * V_2 )
{
unsigned int V_11 , V_12 ;
long long V_4 , V_5 ;
long V_13 = 0 , V_14 = 0 ;
long V_15 = 0 , V_16 = 0 ;
unsigned int V_17 ;
unsigned long V_18 = 0 , V_19 = 0 ;
V_13 = V_2 -> V_20 ;
V_14 = V_2 -> V_1 ;
for ( V_11 = 1 ; V_11 <= V_2 -> V_8 ; V_11 ++ )
V_18 += V_11 * ( V_2 -> V_20 + V_2 -> V_1 ) ;
V_18 *= 2 ;
for ( V_11 = 0 ; V_11 < V_2 -> V_8 ; V_11 ++ ) {
V_15 = 0LL ;
V_16 = 0LL ;
F_6 ( V_18 , V_19 ) ;
if ( F_7 ( L_4 , V_2 -> V_21 ) != 0 )
return;
V_17 = F_1 ( V_14 , V_2 ) ;
if ( V_2 -> V_10 )
printf ( L_5
L_6 , V_11 + 1 , V_2 -> V_22 ,
V_17 , V_14 ) ;
fprintf ( V_2 -> V_23 , L_7 ,
V_11 , V_14 , V_13 ) ;
if ( V_2 -> V_10 )
printf ( L_8 ,
V_14 / V_17 ,
1000000 * V_17 / V_14 ) ;
for ( V_12 = 0 ; V_12 < V_2 -> V_22 ; V_12 ++ ) {
V_4 = F_2 () ;
F_8 ( V_13 ) ;
F_3 ( V_17 ) ;
V_5 = F_2 () ;
V_15 += V_5 - V_4 - V_13 ;
if ( V_2 -> V_10 )
printf ( L_9
L_10
L_11 ,
( long ) ( V_5 - V_4 ) , V_13 ,
V_14 , V_17 ) ;
}
fprintf ( V_2 -> V_23 , L_12 ,
V_15 / V_2 -> V_22 ) ;
V_19 += V_13 + V_14 ;
F_6 ( V_18 , V_19 ) ;
if ( F_7 ( V_2 -> V_24 , V_2 -> V_21 ) != 0 )
return;
for ( V_12 = 0 ; V_12 < V_2 -> V_22 ; V_12 ++ ) {
V_4 = F_2 () ;
F_8 ( V_13 ) ;
F_3 ( V_17 ) ;
V_5 = F_2 () ;
V_16 += V_5 - V_4 - V_13 ;
if ( V_2 -> V_10 )
printf ( L_13
L_10
L_11 ,
( long ) ( V_5 - V_4 ) , V_13 ,
V_14 , V_17 ) ;
}
V_19 += V_13 + V_14 ;
fprintf ( V_2 -> V_23 , L_12 ,
V_16 / V_2 -> V_22 ) ;
fprintf ( V_2 -> V_23 , L_14 ,
V_15 * 100.0 / V_16 ) ;
fflush ( V_2 -> V_23 ) ;
if ( V_2 -> V_10 )
printf ( L_15 ,
V_15 * 100.0 / V_16 ) ;
V_13 += V_2 -> V_25 ;
V_14 += V_2 -> V_26 ;
}
}
