static T_1 * F_1 ( T_2 * V_1 )
{
T_3 * V_2 ;
T_1 * V_3 ;
#ifdef F_2
V_3 = ( T_1 * ) F_3 ( V_4 ) ;
if ( ! V_3 )
return NULL ;
F_4 ( V_1 , F_5 ( F_6 ( V_3 ) | V_5 ) ) ;
V_2 = F_7 ( V_1 , 0 ) ;
F_8 ( V_3 != F_9 ( V_2 , 0 ) ) ;
#else
V_2 = F_7 ( V_1 , 0 ) ;
V_3 = F_9 ( V_2 , 0 ) ;
#endif
return V_3 ;
}
static T_4 * F_10 ( T_1 * V_6 )
{
if ( F_11 ( * V_6 ) ) {
T_4 * V_7 = ( T_4 * ) F_3 ( V_4 ) ;
if ( ! V_7 )
return NULL ;
F_12 ( V_6 , F_13 ( F_6 ( V_7 ) | V_8 ) ) ;
F_8 ( V_7 != F_14 ( V_6 , 0 ) ) ;
return V_7 ;
}
return F_14 ( V_6 , 0 ) ;
}
static int F_15 ( T_2 * V_9 )
{
unsigned long V_10 ;
T_2 * V_1 ;
T_1 * V_6 ;
T_4 * V_11 ;
int V_12 , V_13 ;
V_12 = F_16 ( V_14 ) ;
V_1 = V_9 + V_12 ;
V_10 = 0 ;
for (; V_12 < V_15 ; V_1 ++ , V_12 ++ ) {
V_6 = F_1 ( V_1 ) ;
if ( ! V_6 )
return - V_16 ;
if ( V_10 >= V_17 )
continue;
for ( V_13 = 0 ; V_13 < V_18 ; V_6 ++ , V_13 ++ ) {
if ( V_10 >= V_17 )
break;
if ( V_19 ) {
F_12 ( V_6 , F_17 ( V_10 , V_20 ) ) ;
V_10 += V_21 ;
} else {
T_4 * V_22 ;
V_11 = F_10 ( V_6 ) ;
if ( ! V_11 )
return - V_16 ;
V_22 = V_11 + V_21 ;
for (; V_11 < V_22 ; V_11 ++ , V_10 ++ ) {
if ( V_10 >= V_17 )
break;
F_18 ( V_11 , F_19 ( V_10 , V_23 ) ) ;
}
}
}
}
F_20 ( V_9 ) ;
return 0 ;
}
static inline void F_21 ( T_2 * V_24 )
{
#ifdef F_2
int V_25 ;
for ( V_25 = 0 ; V_25 < V_15 ; V_25 ++ )
F_4 ( V_24 + V_25 ,
F_5 ( F_6 ( V_26 ) | V_5 ) ) ;
#endif
}
int F_22 ( void )
{
int error ;
V_27 = ( T_2 * ) F_3 ( V_4 ) ;
if ( ! V_27 )
return - V_16 ;
F_21 ( V_27 ) ;
error = F_15 ( V_27 ) ;
if ( error )
return error ;
F_23 () ;
return 0 ;
}
int F_24 ( unsigned long V_10 )
{
unsigned long V_28 = F_25 ( & V_29 ) >> V_30 ;
unsigned long V_31 = F_26 ( F_25 ( & V_32 ) ) >> V_30 ;
return ( V_10 >= V_28 ) && ( V_10 < V_31 ) ;
}
