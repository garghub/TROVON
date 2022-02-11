int F_1 ( const T_1 * V_1 )
{
return ( F_2 ( V_1 -> V_2 ) ) ;
}
int F_3 ( int V_3 , const unsigned char * V_4 , unsigned char * V_5 ,
T_1 * V_6 , int V_7 )
{
#ifdef F_4
if ( F_5 () && ! ( V_6 -> V_8 -> V_9 & V_10 )
&& ! ( V_6 -> V_9 & V_11 ) ) {
F_6 ( V_12 , V_13 ) ;
return - 1 ;
}
#endif
return ( V_6 -> V_8 -> V_14 ( V_3 , V_4 , V_5 , V_6 , V_7 ) ) ;
}
int F_7 ( int V_3 , const unsigned char * V_4 ,
unsigned char * V_5 , T_1 * V_6 , int V_7 )
{
#ifdef F_4
if ( F_5 () && ! ( V_6 -> V_8 -> V_9 & V_10 )
&& ! ( V_6 -> V_9 & V_11 ) ) {
F_6 ( V_15 , V_13 ) ;
return - 1 ;
}
#endif
return ( V_6 -> V_8 -> V_16 ( V_3 , V_4 , V_5 , V_6 , V_7 ) ) ;
}
int F_8 ( int V_3 , const unsigned char * V_4 ,
unsigned char * V_5 , T_1 * V_6 , int V_7 )
{
#ifdef F_4
if ( F_5 () && ! ( V_6 -> V_8 -> V_9 & V_10 )
&& ! ( V_6 -> V_9 & V_11 ) ) {
F_6 ( V_17 , V_13 ) ;
return - 1 ;
}
#endif
return ( V_6 -> V_8 -> V_18 ( V_3 , V_4 , V_5 , V_6 , V_7 ) ) ;
}
int F_9 ( int V_3 , const unsigned char * V_4 , unsigned char * V_5 ,
T_1 * V_6 , int V_7 )
{
#ifdef F_4
if ( F_5 () && ! ( V_6 -> V_8 -> V_9 & V_10 )
&& ! ( V_6 -> V_9 & V_11 ) ) {
F_6 ( V_19 , V_13 ) ;
return - 1 ;
}
#endif
return ( V_6 -> V_8 -> V_20 ( V_3 , V_4 , V_5 , V_6 , V_7 ) ) ;
}
int F_10 ( const T_1 * V_1 )
{
return ( ( V_1 == NULL ) ? 0 : V_1 -> V_8 -> V_9 ) ;
}
void F_11 ( T_1 * V_6 )
{
if ( V_6 -> V_21 != NULL ) {
F_12 ( V_6 -> V_21 ) ;
V_6 -> V_21 = NULL ;
}
V_6 -> V_9 &= ~ V_22 ;
V_6 -> V_9 |= V_23 ;
}
int F_13 ( T_1 * V_6 , T_2 * V_24 )
{
int V_25 = 0 ;
if ( V_6 -> V_21 != NULL )
F_11 ( V_6 ) ;
V_6 -> V_21 = F_14 ( V_6 , V_24 ) ;
if ( V_6 -> V_21 == NULL )
goto V_26;
V_6 -> V_9 |= V_22 ;
V_6 -> V_9 &= ~ V_23 ;
V_25 = 1 ;
V_26:
return ( V_25 ) ;
}
static T_3 * F_15 ( const T_3 * V_27 , const T_3 * V_28 ,
const T_3 * V_29 , T_2 * V_24 )
{
T_3 * V_25 = NULL , * V_30 , * V_31 , * V_32 ;
if ( V_27 == NULL || V_28 == NULL || V_29 == NULL )
return NULL ;
F_16 ( V_24 ) ;
V_30 = F_17 ( V_24 ) ;
V_31 = F_17 ( V_24 ) ;
V_32 = F_17 ( V_24 ) ;
if ( V_32 == NULL )
goto V_26;
if ( ! F_18 ( V_31 , V_28 , F_19 () ) )
goto V_26;
if ( ! F_18 ( V_32 , V_29 , F_19 () ) )
goto V_26;
if ( ! F_20 ( V_30 , V_31 , V_32 , V_24 ) )
goto V_26;
V_25 = F_21 ( NULL , V_27 , V_30 , V_24 ) ;
V_26:
F_22 ( V_24 ) ;
return V_25 ;
}
T_4 * F_14 ( T_1 * V_6 , T_2 * V_33 )
{
T_3 V_34 ;
T_3 * V_35 , * V_2 ;
T_2 * V_24 ;
T_4 * V_25 = NULL ;
if ( V_33 == NULL ) {
if ( ( V_24 = F_23 () ) == NULL )
return 0 ;
} else
V_24 = V_33 ;
F_16 ( V_24 ) ;
V_35 = F_17 ( V_24 ) ;
if ( V_35 == NULL ) {
F_6 ( V_36 , V_37 ) ;
goto V_26;
}
if ( V_6 -> V_35 == NULL ) {
V_35 = F_15 ( V_6 -> V_27 , V_6 -> V_28 , V_6 -> V_29 , V_24 ) ;
if ( V_35 == NULL ) {
F_6 ( V_36 , V_38 ) ;
goto V_26;
}
} else
V_35 = V_6 -> V_35 ;
if ( ( F_24 () == 0 ) && V_6 -> V_27 != NULL && V_6 -> V_27 -> V_27 != NULL ) {
F_25 ( V_6 -> V_27 -> V_27 , V_6 -> V_27 -> V_39 * sizeof V_6 -> V_27 -> V_27 [ 0 ] , 0.0 ) ;
}
if ( ! ( V_6 -> V_9 & V_40 ) ) {
V_2 = & V_34 ;
F_26 ( V_2 , V_6 -> V_2 , V_41 ) ;
} else
V_2 = V_6 -> V_2 ;
V_25 = F_27 ( NULL , V_35 , V_2 , V_24 ,
V_6 -> V_8 -> V_42 , V_6 -> V_43 ) ;
if ( V_25 == NULL ) {
F_6 ( V_36 , V_44 ) ;
goto V_26;
}
F_28 ( F_29 ( V_25 ) ) ;
V_26:
F_22 ( V_24 ) ;
if ( V_33 == NULL )
F_30 ( V_24 ) ;
if ( V_6 -> V_35 == NULL )
F_31 ( V_35 ) ;
return V_25 ;
}
