static T_1 * F_1 ( T_2 * V_1 )
{
T_3 * V_2 ;
T_4 * V_3 ;
T_1 * V_4 ;
#ifdef F_2
V_4 = ( T_1 * ) F_3 ( V_5 ) ;
if ( ! V_4 )
return NULL ;
F_4 ( V_1 , F_5 ( F_6 ( V_4 ) | V_6 ) ) ;
V_2 = F_7 ( V_1 , 0 ) ;
V_3 = F_8 ( V_2 , 0 ) ;
F_9 ( V_4 != F_10 ( V_3 , 0 ) ) ;
#else
V_2 = F_7 ( V_1 , 0 ) ;
V_3 = F_8 ( V_2 , 0 ) ;
V_4 = F_10 ( V_3 , 0 ) ;
#endif
return V_4 ;
}
static T_5 * F_11 ( T_1 * V_7 )
{
if ( F_12 ( * V_7 ) ) {
T_5 * V_8 = ( T_5 * ) F_3 ( V_5 ) ;
if ( ! V_8 )
return NULL ;
F_13 ( V_7 , F_14 ( F_6 ( V_8 ) | V_9 ) ) ;
F_9 ( V_8 != F_15 ( V_7 , 0 ) ) ;
return V_8 ;
}
return F_15 ( V_7 , 0 ) ;
}
static int F_16 ( T_2 * V_10 )
{
unsigned long V_11 ;
T_2 * V_1 ;
T_1 * V_7 ;
T_5 * V_12 ;
int V_13 , V_14 ;
V_13 = F_17 ( V_15 ) ;
V_1 = V_10 + V_13 ;
V_11 = 0 ;
for (; V_13 < V_16 ; V_1 ++ , V_13 ++ ) {
V_7 = F_1 ( V_1 ) ;
if ( ! V_7 )
return - V_17 ;
if ( V_11 >= V_18 )
continue;
for ( V_14 = 0 ; V_14 < V_19 ; V_7 ++ , V_14 ++ ) {
if ( V_11 >= V_18 )
break;
if ( F_18 ( V_20 ) ) {
F_13 ( V_7 , F_19 ( V_11 , V_21 ) ) ;
V_11 += V_22 ;
} else {
T_5 * V_23 ;
V_12 = F_11 ( V_7 ) ;
if ( ! V_12 )
return - V_17 ;
V_23 = V_12 + V_22 ;
for (; V_12 < V_23 ; V_12 ++ , V_11 ++ ) {
if ( V_11 >= V_18 )
break;
F_20 ( V_12 , F_21 ( V_11 , V_24 ) ) ;
}
}
}
}
return 0 ;
}
static inline void F_22 ( T_2 * V_25 )
{
#ifdef F_2
int V_26 ;
for ( V_26 = 0 ; V_26 < V_16 ; V_26 ++ )
F_4 ( V_25 + V_26 ,
F_5 ( F_6 ( V_27 ) | V_6 ) ) ;
#endif
}
int F_23 ( void )
{
int error ;
V_28 = ( T_2 * ) F_3 ( V_5 ) ;
if ( ! V_28 )
return - V_17 ;
F_22 ( V_28 ) ;
error = F_16 ( V_28 ) ;
if ( error )
return error ;
F_24 () ;
return 0 ;
}
int F_25 ( unsigned long V_11 )
{
unsigned long V_29 = F_26 ( & V_30 ) >> V_31 ;
unsigned long V_32 = F_27 ( F_26 ( & V_33 ) ) >> V_31 ;
return ( V_11 >= V_29 ) && ( V_11 < V_32 ) ;
}
