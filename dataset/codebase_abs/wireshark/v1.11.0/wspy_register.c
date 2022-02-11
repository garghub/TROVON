static inline
void F_1 ( void )
{
F_2 () ;
}
static inline
void F_3 ( void )
{
F_4 () ;
}
char * F_5 ( T_1 * V_1 )
{
T_1 * V_2 ;
assert ( V_1 ) ;
V_2 = F_6 ( V_1 ) ;
#if V_3 == 2
return F_7 ( V_2 ) ;
#else
return F_8 ( V_2 ) ;
#endif
}
void F_9 ( T_1 * V_1 )
{
F_10 ( V_1 , L_1 , NULL ) ;
}
static const char * F_11 ( void )
{
static const char * V_4 = NULL ;
if ( ! V_4 ) {
#ifdef F_12
V_4 = F_13 ( L_2 , F_14 () ) ;
#else
V_4 = F_13 ( L_3 , F_14 () ) ;
#endif
}
return V_4 ;
}
void F_15 ( void )
{
T_2 * V_5 ;
T_1 * V_6 , * V_7 , * V_8 ;
T_1 * V_9 , * V_1 ;
T_1 * V_10 ;
T_3 V_11 ;
char * V_12 ;
V_13 = F_16 ( V_14 , V_15 ) ;
F_1 () ;
V_5 = fopen ( F_11 () , L_4 ) ;
if ( V_5 == NULL ) {
printf ( L_5 , F_11 () ) ;
return;
}
F_17 ( V_5 , F_11 () ) ;
V_7 = F_18 ( L_6 ) ;
V_6 = F_19 ( V_7 ) ;
V_8 = F_20 ( V_6 , L_7 ) ;
if ( V_8 == NULL ) {
printf ( L_8 , F_11 () ) ;
return;
}
V_10 = F_21 ( L_9 , F_14 () , F_22 () ) ;
V_9 = F_23 ( V_8 , V_10 ) ;
if ( ! V_9 || ! F_24 ( V_9 ) ) {
printf ( L_10 ) ;
return;
}
for ( V_11 = 0 ; ( V_1 = F_25 ( V_9 , V_11 ) ) ; V_11 ++ )
{
V_12 = F_5 ( V_1 ) ;
F_9 ( V_1 ) ;
F_26 ( V_13 , ( V_16 * ) V_12 , V_1 ) ;
}
}
void F_27 ( T_4 * * V_17 , T_5 * * V_18 , T_6 * * V_19 )
{
* V_17 = V_20 ;
* V_18 = V_21 ;
* V_19 = V_22 ;
}
void F_28 ( T_4 * V_17 , T_5 * V_18 ,
T_6 * V_19 )
{
T_1 * V_1 ;
V_22 = V_19 ;
V_21 = V_18 ;
V_20 = V_17 ;
V_1 = F_29 ( V_13 , V_18 -> V_23 ) ;
assert ( V_1 ) ;
F_10 ( V_1 , L_11 , NULL ) ;
}
T_7 F_30 ( const int V_24 )
{
return F_31 ( & F_28 , V_24 ) ;
}
static void F_32 ( V_16 T_8 V_25 , V_16 V_26 , V_16 T_9 V_25 )
{
T_1 * V_1 = ( T_1 * ) V_26 ;
F_10 ( V_1 , L_12 , NULL ) ;
}
void
F_33 ( void )
{
F_34 ( V_13 , F_32 , NULL ) ;
}
