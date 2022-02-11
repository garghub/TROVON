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
return F_7 ( V_2 ) ;
}
void F_8 ( T_1 * V_1 )
{
F_9 ( V_1 , L_1 , NULL ) ;
}
static const char * F_10 ( void )
{
static const char * V_3 = NULL ;
if ( ! V_3 ) {
#ifdef F_11
V_3 = F_12 ( L_2 , F_13 () ) ;
#else
V_3 = F_12 ( L_3 , F_13 () ) ;
#endif
}
return V_3 ;
}
void F_14 ( void )
{
T_2 * V_4 ;
T_1 * V_5 , * V_6 , * V_7 ;
T_1 * V_8 , * V_1 ;
T_1 * V_9 ;
T_3 V_10 ;
char * V_11 ;
V_12 = F_15 ( V_13 , V_14 ) ;
F_1 () ;
V_4 = fopen ( F_10 () , L_4 ) ;
if ( V_4 == NULL ) {
printf ( L_5 , F_10 () ) ;
return;
}
F_16 ( V_4 , F_10 () ) ;
V_6 = F_17 ( L_6 ) ;
V_5 = F_18 ( V_6 ) ;
V_7 = F_19 ( V_5 , L_7 ) ;
if ( V_7 == NULL ) {
printf ( L_8 , F_10 () ) ;
return;
}
V_9 = F_20 ( L_9 , F_13 () , F_21 () ) ;
V_8 = F_22 ( V_7 , V_9 ) ;
if ( ! V_8 || ! F_23 ( V_8 ) ) {
printf ( L_10 ) ;
return;
}
for ( V_10 = 0 ; ( V_1 = F_24 ( V_8 , V_10 ) ) ; V_10 ++ )
{
V_11 = F_5 ( V_1 ) ;
F_8 ( V_1 ) ;
F_25 ( V_12 , ( V_15 * ) V_11 , V_1 ) ;
}
}
void F_26 ( T_4 * * V_16 , T_5 * * V_17 , T_6 * * V_18 )
{
* V_16 = V_19 ;
* V_17 = V_20 ;
* V_18 = V_21 ;
}
void F_27 ( T_4 * V_16 , T_5 * V_17 ,
T_6 * V_18 )
{
T_1 * V_1 ;
V_21 = V_18 ;
V_20 = V_17 ;
V_19 = V_16 ;
V_1 = F_28 ( V_12 , V_17 -> V_22 ) ;
assert ( V_1 ) ;
F_9 ( V_1 , L_11 , NULL ) ;
}
T_7 F_29 ( const int V_23 )
{
return F_30 ( & F_27 , V_23 ) ;
}
static void F_31 ( V_15 T_8 V_24 , V_15 V_25 , V_15 T_9 V_24 )
{
T_1 * V_1 = ( T_1 * ) V_25 ;
F_9 ( V_1 , L_12 , NULL ) ;
}
void
F_32 ( void )
{
F_33 ( V_12 , F_31 , NULL ) ;
}
