int F_1 ( T_1 V_1 , int V_2 )
{
#ifdef F_2
int V_3 = 0 ;
if ( ! V_4 ) {
V_5 = F_3 () ;
if ( V_5 == NULL )
return 0 ;
V_3 = F_4 ( V_1 , V_2 ) ;
V_4 = 1 ;
}
return V_3 ;
#else
return 0 ;
#endif
}
int F_5 ()
{
#ifdef F_2
if ( V_6 == 0 ) {
F_6 () ;
V_4 = 0 ;
F_7 ( V_5 ) ;
return 1 ;
}
#endif
return 0 ;
}
int F_8 ()
{
#ifdef F_2
return V_4 ;
#else
return 0 ;
#endif
}
void * F_9 ( T_1 V_7 , const char * V_8 , int line )
{
#ifdef F_2
void * V_3 ;
T_1 V_9 ;
if ( ! V_4 ) {
return F_10 ( V_7 , V_8 , line ) ;
}
F_11 ( V_5 ) ;
V_3 = F_12 ( V_7 ) ;
V_9 = V_3 ? F_13 ( V_3 ) : 0 ;
V_6 += V_9 ;
F_14 ( V_5 ) ;
return V_3 ;
#else
return F_10 ( V_7 , V_8 , line ) ;
#endif
}
void * F_15 ( T_1 V_7 , const char * V_8 , int line )
{
void * V_3 = F_9 ( V_7 , V_8 , line ) ;
if ( V_3 != NULL )
memset ( V_3 , 0 , V_7 ) ;
return V_3 ;
}
void F_16 ( void * V_10 , const char * V_8 , int line )
{
#ifdef F_2
T_1 V_9 ;
if ( V_10 == NULL )
return;
if ( ! F_17 ( V_10 ) ) {
F_18 ( V_10 , V_8 , line ) ;
return;
}
F_11 ( V_5 ) ;
V_9 = F_13 ( V_10 ) ;
F_19 ( V_10 , V_9 ) ;
V_6 -= V_9 ;
F_20 ( V_10 ) ;
F_14 ( V_5 ) ;
#else
F_18 ( V_10 , V_8 , line ) ;
#endif
}
int F_17 ( const void * V_10 )
{
#ifdef F_2
int V_3 ;
if ( ! V_4 )
return 0 ;
F_11 ( V_5 ) ;
V_3 = F_21 ( V_10 ) ;
F_14 ( V_5 ) ;
return V_3 ;
#else
return 0 ;
#endif
}
T_1 F_22 ()
{
#ifdef F_2
return V_6 ;
#else
return 0 ;
#endif
}
T_1 F_23 ( void * V_10 )
{
#ifdef F_2
T_1 V_9 ;
F_11 ( V_5 ) ;
V_9 = F_13 ( V_10 ) ;
F_14 ( V_5 ) ;
return V_9 ;
#else
return 0 ;
#endif
}
static T_1 F_24 ( char * V_10 )
{
T_2 V_11 = V_12 . V_13 - 1 ;
T_1 V_14 = ( V_12 . V_15 + V_10 - V_12 . V_16 ) / V_12 . V_2 ;
for (; V_14 ; V_14 >>= 1 , V_11 -- ) {
if ( F_25 ( V_12 . V_17 , V_14 ) )
break;
F_26 ( ( V_14 & 1 ) == 0 ) ;
}
return V_11 ;
}
static int F_27 ( char * V_10 , int V_11 , unsigned char * V_18 )
{
T_1 V_14 ;
F_26 ( V_11 >= 0 && V_11 < V_12 . V_13 ) ;
F_26 ( ( ( V_10 - V_12 . V_16 ) & ( ( V_12 . V_15 >> V_11 ) - 1 ) ) == 0 ) ;
V_14 = ( V_19 << V_11 ) + ( ( V_10 - V_12 . V_16 ) / ( V_12 . V_15 >> V_11 ) ) ;
F_26 ( V_14 > 0 && V_14 < V_12 . V_20 ) ;
return F_25 ( V_18 , V_14 ) ;
}
static void F_28 ( char * V_10 , int V_11 , unsigned char * V_18 )
{
T_1 V_14 ;
F_26 ( V_11 >= 0 && V_11 < V_12 . V_13 ) ;
F_26 ( ( ( V_10 - V_12 . V_16 ) & ( ( V_12 . V_15 >> V_11 ) - 1 ) ) == 0 ) ;
V_14 = ( V_19 << V_11 ) + ( ( V_10 - V_12 . V_16 ) / ( V_12 . V_15 >> V_11 ) ) ;
F_26 ( V_14 > 0 && V_14 < V_12 . V_20 ) ;
F_26 ( F_25 ( V_18 , V_14 ) ) ;
F_29 ( V_18 , V_14 ) ;
}
static void F_30 ( char * V_10 , int V_11 , unsigned char * V_18 )
{
T_1 V_14 ;
F_26 ( V_11 >= 0 && V_11 < V_12 . V_13 ) ;
F_26 ( ( ( V_10 - V_12 . V_16 ) & ( ( V_12 . V_15 >> V_11 ) - 1 ) ) == 0 ) ;
V_14 = ( V_19 << V_11 ) + ( ( V_10 - V_12 . V_16 ) / ( V_12 . V_15 >> V_11 ) ) ;
F_26 ( V_14 > 0 && V_14 < V_12 . V_20 ) ;
F_26 ( ! F_25 ( V_18 , V_14 ) ) ;
F_31 ( V_18 , V_14 ) ;
}
static void F_32 ( char * * V_11 , char * V_10 )
{
T_3 * V_21 ;
F_26 ( F_33 ( V_11 ) ) ;
F_26 ( F_34 ( V_10 ) ) ;
V_21 = ( T_3 * ) V_10 ;
V_21 -> V_22 = * ( T_3 * * ) V_11 ;
F_26 ( V_21 -> V_22 == NULL || F_34 ( V_21 -> V_22 ) ) ;
V_21 -> V_23 = ( T_3 * * ) V_11 ;
if ( V_21 -> V_22 != NULL ) {
F_26 ( ( char * * ) V_21 -> V_22 -> V_23 == V_11 ) ;
V_21 -> V_22 -> V_23 = & ( V_21 -> V_22 ) ;
}
* V_11 = V_10 ;
}
static void F_35 ( char * V_10 )
{
T_3 * V_21 , * V_24 ;
V_21 = ( T_3 * ) V_10 ;
if ( V_21 -> V_22 != NULL )
V_21 -> V_22 -> V_23 = V_21 -> V_23 ;
* V_21 -> V_23 = V_21 -> V_22 ;
if ( V_21 -> V_22 == NULL )
return;
V_24 = V_21 -> V_22 ;
F_26 ( F_33 ( V_24 -> V_23 ) || F_34 ( V_24 -> V_23 ) ) ;
}
static int F_4 ( T_1 V_1 , int V_2 )
{
int V_25 , V_3 ;
T_1 V_26 ;
T_1 V_27 ;
memset ( & V_12 , 0 , sizeof V_12 ) ;
F_26 ( V_1 > 0 ) ;
F_26 ( ( V_1 & ( V_1 - 1 ) ) == 0 ) ;
F_26 ( V_2 > 0 ) ;
F_26 ( ( V_2 & ( V_2 - 1 ) ) == 0 ) ;
if ( V_1 <= 0 || ( V_1 & ( V_1 - 1 ) ) != 0 )
goto V_28;
if ( V_2 <= 0 || ( V_2 & ( V_2 - 1 ) ) != 0 )
goto V_28;
V_12 . V_15 = V_1 ;
V_12 . V_2 = V_2 ;
V_12 . V_20 = ( V_12 . V_15 / V_12 . V_2 ) * 2 ;
V_12 . V_13 = - 1 ;
for ( V_25 = V_12 . V_20 ; V_25 ; V_25 >>= 1 )
V_12 . V_13 ++ ;
V_12 . V_29 = F_36 ( V_12 . V_13 * sizeof ( char * ) ) ;
F_26 ( V_12 . V_29 != NULL ) ;
if ( V_12 . V_29 == NULL )
goto V_28;
V_12 . V_17 = F_36 ( V_12 . V_20 >> 3 ) ;
F_26 ( V_12 . V_17 != NULL ) ;
if ( V_12 . V_17 == NULL )
goto V_28;
V_12 . V_30 = F_36 ( V_12 . V_20 >> 3 ) ;
F_26 ( V_12 . V_30 != NULL ) ;
if ( V_12 . V_30 == NULL )
goto V_28;
#if F_37 ( V_31 ) || F_37 ( V_32 )
{
# if F_37 ( V_31 )
long V_33 = F_38 ( V_31 ) ;
# else
long V_33 = F_38 ( V_32 ) ;
# endif
if ( V_33 < 1 )
V_26 = V_34 ;
else
V_26 = ( T_1 ) V_33 ;
}
#else
V_26 = V_34 ;
#endif
V_12 . V_35 = V_26 + V_12 . V_15 + V_26 ;
if ( 1 ) {
#ifdef F_39
V_12 . V_36 = F_40 ( NULL , V_12 . V_35 ,
V_37 | V_38 , F_39 | V_39 , - 1 , 0 ) ;
} else {
#endif
int V_40 ;
V_12 . V_36 = V_41 ;
if ( ( V_40 = F_41 ( L_1 , V_42 ) ) >= 0 ) {
V_12 . V_36 = F_40 ( NULL , V_12 . V_35 ,
V_37 | V_38 , V_39 , V_40 , 0 ) ;
F_42 ( V_40 ) ;
}
}
F_26 ( V_12 . V_36 != V_41 ) ;
if ( V_12 . V_36 == V_41 )
goto V_28;
V_12 . V_16 = ( char * ) ( V_12 . V_36 + V_26 ) ;
F_30 ( V_12 . V_16 , 0 , V_12 . V_17 ) ;
F_32 ( & V_12 . V_29 [ 0 ] , V_12 . V_16 ) ;
V_3 = 1 ;
if ( F_43 ( V_12 . V_36 , V_26 , V_43 ) < 0 )
V_3 = 2 ;
V_27 = ( V_26 + V_12 . V_15 + ( V_26 - 1 ) ) & ~ ( V_26 - 1 ) ;
if ( F_43 ( V_12 . V_36 + V_27 , V_26 , V_43 ) < 0 )
V_3 = 2 ;
if ( F_44 ( V_12 . V_16 , V_12 . V_15 ) < 0 )
V_3 = 2 ;
#ifdef F_45
if ( F_46 ( V_12 . V_16 , V_12 . V_15 , F_45 ) < 0 )
V_3 = 2 ;
#endif
return V_3 ;
V_28:
F_6 () ;
return 0 ;
}
static void F_6 ()
{
F_47 ( V_12 . V_29 ) ;
F_47 ( V_12 . V_17 ) ;
F_47 ( V_12 . V_30 ) ;
if ( V_12 . V_36 != NULL && V_12 . V_35 )
F_48 ( V_12 . V_36 , V_12 . V_35 ) ;
memset ( & V_12 , 0 , sizeof V_12 ) ;
}
static int F_21 ( const char * V_10 )
{
return F_34 ( V_10 ) ? 1 : 0 ;
}
static char * F_49 ( char * V_10 , int V_11 )
{
T_1 V_14 ;
char * V_44 = NULL ;
V_14 = ( V_19 << V_11 ) + ( V_10 - V_12 . V_16 ) / ( V_12 . V_15 >> V_11 ) ;
V_14 ^= 1 ;
if ( F_25 ( V_12 . V_17 , V_14 ) && ! F_25 ( V_12 . V_30 , V_14 ) )
V_44 = V_12 . V_16 + ( ( V_14 & ( ( V_19 << V_11 ) - 1 ) ) * ( V_12 . V_15 >> V_11 ) ) ;
return V_44 ;
}
static char * F_12 ( T_1 V_1 )
{
T_2 V_11 , V_45 ;
T_1 V_25 ;
char * V_44 ;
V_11 = V_12 . V_13 - 1 ;
for ( V_25 = V_12 . V_2 ; V_25 < V_1 ; V_25 <<= 1 )
V_11 -- ;
if ( V_11 < 0 )
return NULL ;
for ( V_45 = V_11 ; V_45 >= 0 ; V_45 -- )
if ( V_12 . V_29 [ V_45 ] != NULL )
break;
if ( V_45 < 0 )
return NULL ;
while ( V_45 != V_11 ) {
char * V_21 = V_12 . V_29 [ V_45 ] ;
F_26 ( ! F_27 ( V_21 , V_45 , V_12 . V_30 ) ) ;
F_28 ( V_21 , V_45 , V_12 . V_17 ) ;
F_35 ( V_21 ) ;
F_26 ( V_21 != V_12 . V_29 [ V_45 ] ) ;
V_45 ++ ;
F_26 ( ! F_27 ( V_21 , V_45 , V_12 . V_30 ) ) ;
F_30 ( V_21 , V_45 , V_12 . V_17 ) ;
F_32 ( & V_12 . V_29 [ V_45 ] , V_21 ) ;
F_26 ( V_12 . V_29 [ V_45 ] == V_21 ) ;
V_21 += V_12 . V_15 >> V_45 ;
F_26 ( ! F_27 ( V_21 , V_45 , V_12 . V_30 ) ) ;
F_30 ( V_21 , V_45 , V_12 . V_17 ) ;
F_32 ( & V_12 . V_29 [ V_45 ] , V_21 ) ;
F_26 ( V_12 . V_29 [ V_45 ] == V_21 ) ;
F_26 ( V_21 - ( V_12 . V_15 >> V_45 ) == F_49 ( V_21 , V_45 ) ) ;
}
V_44 = V_12 . V_29 [ V_11 ] ;
F_26 ( F_27 ( V_44 , V_11 , V_12 . V_17 ) ) ;
F_30 ( V_44 , V_11 , V_12 . V_30 ) ;
F_35 ( V_44 ) ;
F_26 ( F_34 ( V_44 ) ) ;
return V_44 ;
}
static void F_20 ( char * V_10 )
{
T_1 V_11 ;
char * V_46 ;
if ( V_10 == NULL )
return;
F_26 ( F_34 ( V_10 ) ) ;
if ( ! F_34 ( V_10 ) )
return;
V_11 = F_24 ( V_10 ) ;
F_26 ( F_27 ( V_10 , V_11 , V_12 . V_17 ) ) ;
F_28 ( V_10 , V_11 , V_12 . V_30 ) ;
F_32 ( & V_12 . V_29 [ V_11 ] , V_10 ) ;
while ( ( V_46 = F_49 ( V_10 , V_11 ) ) != NULL ) {
F_26 ( V_10 == F_49 ( V_46 , V_11 ) ) ;
F_26 ( V_10 != NULL ) ;
F_26 ( ! F_27 ( V_10 , V_11 , V_12 . V_30 ) ) ;
F_28 ( V_10 , V_11 , V_12 . V_17 ) ;
F_35 ( V_10 ) ;
F_26 ( ! F_27 ( V_10 , V_11 , V_12 . V_30 ) ) ;
F_28 ( V_46 , V_11 , V_12 . V_17 ) ;
F_35 ( V_46 ) ;
V_11 -- ;
if ( V_10 > V_46 )
V_10 = V_46 ;
F_26 ( ! F_27 ( V_10 , V_11 , V_12 . V_30 ) ) ;
F_30 ( V_10 , V_11 , V_12 . V_17 ) ;
F_32 ( & V_12 . V_29 [ V_11 ] , V_10 ) ;
F_26 ( V_12 . V_29 [ V_11 ] == V_10 ) ;
}
}
static T_1 F_13 ( char * V_10 )
{
int V_11 ;
F_26 ( F_34 ( V_10 ) ) ;
if ( ! F_34 ( V_10 ) )
return 0 ;
V_11 = F_24 ( V_10 ) ;
F_26 ( F_27 ( V_10 , V_11 , V_12 . V_17 ) ) ;
return V_12 . V_15 / ( V_19 << V_11 ) ;
}
