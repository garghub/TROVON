int F_1 ( T_1 * V_1 )
{
#ifdef F_2
if ( F_3 () && ! ( V_1 -> V_2 -> V_3 & V_4 )
&& ! ( V_1 -> V_3 & V_5 ) ) {
F_4 ( V_6 , V_7 ) ;
return 0 ;
}
#endif
return V_1 -> V_2 -> V_8 ( V_1 ) ;
}
int F_5 ( unsigned char * V_9 , const T_2 * V_10 , T_1 * V_1 )
{
#ifdef F_2
if ( F_3 () && ! ( V_1 -> V_2 -> V_3 & V_4 )
&& ! ( V_1 -> V_3 & V_5 ) ) {
F_4 ( V_11 , V_7 ) ;
return 0 ;
}
#endif
return V_1 -> V_2 -> V_12 ( V_9 , V_10 , V_1 ) ;
}
int F_6 ( unsigned char * V_9 , const T_2 * V_10 , T_1 * V_1 )
{
int V_13 , V_14 ;
V_13 = V_1 -> V_2 -> V_12 ( V_9 , V_10 , V_1 ) ;
if ( V_13 <= 0 )
return V_13 ;
V_14 = F_7 ( V_1 -> V_15 ) - V_13 ;
if ( V_14 > 0 ) {
memmove ( V_9 + V_14 , V_9 , V_13 ) ;
memset ( V_9 , 0 , V_14 ) ;
}
return V_13 + V_14 ;
}
const T_3 * F_8 ( void )
{
return & V_16 ;
}
static int V_8 ( T_1 * V_1 )
{
int V_17 = 0 ;
int V_18 = 0 ;
unsigned V_19 ;
T_4 * V_20 ;
T_5 * V_21 = NULL ;
T_2 * V_10 = NULL , * V_22 = NULL ;
V_20 = F_9 () ;
if ( V_20 == NULL )
goto V_23;
if ( V_1 -> V_22 == NULL ) {
V_22 = F_10 () ;
if ( V_22 == NULL )
goto V_23;
V_18 = 1 ;
} else
V_22 = V_1 -> V_22 ;
if ( V_1 -> V_10 == NULL ) {
V_10 = F_10 () ;
if ( V_10 == NULL )
goto V_23;
} else
V_10 = V_1 -> V_10 ;
if ( V_1 -> V_3 & V_24 ) {
V_21 = F_11 ( & V_1 -> V_25 ,
V_26 , V_1 -> V_15 , V_20 ) ;
if ( ! V_21 )
goto V_23;
}
if ( V_18 ) {
if ( V_1 -> V_27 ) {
do {
if ( ! F_12 ( V_22 , V_1 -> V_27 ) )
goto V_23;
}
while ( F_13 ( V_22 ) || F_14 ( V_22 ) );
} else {
V_19 = V_1 -> V_28 ? V_1 -> V_28 : F_15 ( V_1 -> V_15 ) - 1 ;
if ( ! F_16 ( V_22 , V_19 , 0 , 0 ) )
goto V_23;
}
}
{
T_2 V_29 ;
T_2 * V_30 ;
if ( ( V_1 -> V_3 & V_31 ) == 0 ) {
F_17 ( & V_29 ) ;
V_30 = & V_29 ;
F_18 ( V_30 , V_22 , V_32 ) ;
} else
V_30 = V_22 ;
if ( ! V_1 -> V_2 -> V_33 ( V_1 , V_10 , V_1 -> V_34 , V_30 , V_1 -> V_15 , V_20 , V_21 ) )
goto V_23;
}
V_1 -> V_10 = V_10 ;
V_1 -> V_22 = V_22 ;
V_17 = 1 ;
V_23:
if ( V_17 != 1 )
F_4 ( V_35 , V_36 ) ;
if ( ( V_10 != NULL ) && ( V_1 -> V_10 == NULL ) )
F_19 ( V_10 ) ;
if ( ( V_22 != NULL ) && ( V_1 -> V_22 == NULL ) )
F_19 ( V_22 ) ;
F_20 ( V_20 ) ;
return ( V_17 ) ;
}
static int V_12 ( unsigned char * V_9 , const T_2 * V_10 , T_1 * V_1 )
{
T_4 * V_20 = NULL ;
T_5 * V_21 = NULL ;
T_2 * V_37 ;
int V_38 = - 1 ;
int V_39 ;
if ( F_15 ( V_1 -> V_15 ) > V_40 ) {
F_4 ( V_41 , V_42 ) ;
goto V_23;
}
V_20 = F_9 () ;
if ( V_20 == NULL )
goto V_23;
F_21 ( V_20 ) ;
V_37 = F_22 ( V_20 ) ;
if ( V_1 -> V_22 == NULL ) {
F_4 ( V_41 , V_43 ) ;
goto V_23;
}
if ( V_1 -> V_3 & V_24 ) {
V_21 = F_11 ( & V_1 -> V_25 ,
V_26 , V_1 -> V_15 , V_20 ) ;
if ( ( V_1 -> V_3 & V_31 ) == 0 ) {
F_23 ( V_1 -> V_22 , V_32 ) ;
}
if ( ! V_21 )
goto V_23;
}
if ( ! F_24 ( V_1 , V_10 , & V_39 ) || V_39 ) {
F_4 ( V_41 , V_44 ) ;
goto V_23;
}
if ( ! V_1 ->
V_2 -> V_33 ( V_1 , V_37 , V_10 , V_1 -> V_22 , V_1 -> V_15 , V_20 , V_21 ) ) {
F_4 ( V_41 , V_36 ) ;
goto V_23;
}
V_38 = F_25 ( V_37 , V_9 ) ;
V_23:
if ( V_20 != NULL ) {
F_26 ( V_20 ) ;
F_20 ( V_20 ) ;
}
return ( V_38 ) ;
}
static int F_27 ( const T_1 * V_1 , T_2 * V_45 ,
const T_2 * V_46 , const T_2 * V_15 ,
const T_2 * V_47 , T_4 * V_20 , T_5 * V_48 )
{
if ( V_46 -> V_49 == 1 && ( ( V_1 -> V_3 & V_31 ) != 0 ) ) {
T_6 V_50 = V_46 -> V_51 [ 0 ] ;
return F_28 ( V_45 , V_50 , V_15 , V_47 , V_20 , V_48 ) ;
} else
return F_29 ( V_45 , V_46 , V_15 , V_47 , V_20 , V_48 ) ;
}
static int F_30 ( T_1 * V_1 )
{
V_1 -> V_3 |= V_24 ;
return ( 1 ) ;
}
static int F_31 ( T_1 * V_1 )
{
if ( V_1 -> V_25 )
F_32 ( V_1 -> V_25 ) ;
return ( 1 ) ;
}
