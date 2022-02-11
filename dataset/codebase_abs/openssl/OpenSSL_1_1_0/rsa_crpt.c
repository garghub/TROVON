int F_1 ( const T_1 * V_1 )
{
return ( F_2 ( V_1 -> V_2 ) ) ;
}
int F_3 ( const T_1 * V_1 )
{
return ( F_4 ( V_1 -> V_2 ) ) ;
}
int F_5 ( int V_3 , const unsigned char * V_4 , unsigned char * V_5 ,
T_1 * V_6 , int V_7 )
{
return ( V_6 -> V_8 -> V_9 ( V_3 , V_4 , V_5 , V_6 , V_7 ) ) ;
}
int F_6 ( int V_3 , const unsigned char * V_4 ,
unsigned char * V_5 , T_1 * V_6 , int V_7 )
{
return ( V_6 -> V_8 -> V_10 ( V_3 , V_4 , V_5 , V_6 , V_7 ) ) ;
}
int F_7 ( int V_3 , const unsigned char * V_4 ,
unsigned char * V_5 , T_1 * V_6 , int V_7 )
{
return ( V_6 -> V_8 -> V_11 ( V_3 , V_4 , V_5 , V_6 , V_7 ) ) ;
}
int F_8 ( int V_3 , const unsigned char * V_4 , unsigned char * V_5 ,
T_1 * V_6 , int V_7 )
{
return ( V_6 -> V_8 -> V_12 ( V_3 , V_4 , V_5 , V_6 , V_7 ) ) ;
}
int F_9 ( const T_1 * V_1 )
{
return ( ( V_1 == NULL ) ? 0 : V_1 -> V_8 -> V_13 ) ;
}
void F_10 ( T_1 * V_6 )
{
F_11 ( V_6 -> V_14 ) ;
V_6 -> V_14 = NULL ;
V_6 -> V_13 &= ~ V_15 ;
V_6 -> V_13 |= V_16 ;
}
int F_12 ( T_1 * V_6 , T_2 * V_17 )
{
int V_18 = 0 ;
if ( V_6 -> V_14 != NULL )
F_10 ( V_6 ) ;
V_6 -> V_14 = F_13 ( V_6 , V_17 ) ;
if ( V_6 -> V_14 == NULL )
goto V_19;
V_6 -> V_13 |= V_15 ;
V_6 -> V_13 &= ~ V_16 ;
V_18 = 1 ;
V_19:
return ( V_18 ) ;
}
static T_3 * F_14 ( const T_3 * V_20 , const T_3 * V_21 ,
const T_3 * V_22 , T_2 * V_17 )
{
T_3 * V_18 = NULL , * V_23 , * V_24 , * V_25 ;
if ( V_20 == NULL || V_21 == NULL || V_22 == NULL )
return NULL ;
F_15 ( V_17 ) ;
V_23 = F_16 ( V_17 ) ;
V_24 = F_16 ( V_17 ) ;
V_25 = F_16 ( V_17 ) ;
if ( V_25 == NULL )
goto V_19;
if ( ! F_17 ( V_24 , V_21 , F_18 () ) )
goto V_19;
if ( ! F_17 ( V_25 , V_22 , F_18 () ) )
goto V_19;
if ( ! F_19 ( V_23 , V_24 , V_25 , V_17 ) )
goto V_19;
V_18 = F_20 ( NULL , V_20 , V_23 , V_17 ) ;
V_19:
F_21 ( V_17 ) ;
return V_18 ;
}
T_4 * F_13 ( T_1 * V_6 , T_2 * V_26 )
{
T_3 * V_27 ;
T_2 * V_17 ;
T_4 * V_18 = NULL ;
if ( V_26 == NULL ) {
if ( ( V_17 = F_22 () ) == NULL )
return 0 ;
} else
V_17 = V_26 ;
F_15 ( V_17 ) ;
V_27 = F_16 ( V_17 ) ;
if ( V_27 == NULL ) {
F_23 ( V_28 , V_29 ) ;
goto V_19;
}
if ( V_6 -> V_27 == NULL ) {
V_27 = F_14 ( V_6 -> V_20 , V_6 -> V_21 , V_6 -> V_22 , V_17 ) ;
if ( V_27 == NULL ) {
F_23 ( V_28 , V_30 ) ;
goto V_19;
}
} else
V_27 = V_6 -> V_27 ;
if ( ( F_24 () == 0 ) && V_6 -> V_20 != NULL
&& F_25 ( V_6 -> V_20 ) != NULL ) {
F_26 ( F_25 ( V_6 -> V_20 ) , F_27 ( V_6 -> V_20 ) * sizeof( V_31 ) ,
0.0 ) ;
}
{
T_3 * V_2 = F_28 () ;
if ( V_2 == NULL ) {
F_23 ( V_28 , V_29 ) ;
goto V_19;
}
F_29 ( V_2 , V_6 -> V_2 , V_32 ) ;
V_18 = F_30 ( NULL , V_27 , V_2 , V_17 , V_6 -> V_8 -> V_33 ,
V_6 -> V_34 ) ;
F_31 ( V_2 ) ;
}
if ( V_18 == NULL ) {
F_23 ( V_28 , V_35 ) ;
goto V_19;
}
F_32 ( V_18 ) ;
V_19:
F_21 ( V_17 ) ;
if ( V_17 != V_26 )
F_33 ( V_17 ) ;
if ( V_27 != V_6 -> V_27 )
F_31 ( V_27 ) ;
return V_18 ;
}
