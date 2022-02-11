int F_1 ( struct V_1 * V_2 ,
const struct V_3 * type ,
const union V_4 * V_5 )
{
return F_2 ( V_6 , type , V_5 ) ;
}
int F_3 (
struct V_1 * V_2 ,
const struct V_3 * type ,
const union V_4 * V_5 )
{
if ( type == & V_7 &&
V_2 == V_8 &&
V_5 == & V_6 -> V_5 )
return 0 ;
return F_2 ( V_8 , type , V_5 ) ;
}
static T_1 int F_4 ( void )
{
F_5 ( L_1 ) ;
V_6 =
F_6 ( L_2 ,
F_7 ( 0 ) , F_8 ( 0 ) , F_9 () ,
( ( V_9 & ~ V_10 ) |
V_11 | V_12 | V_13 ) ,
V_14 ,
NULL , NULL ) ;
if ( F_10 ( V_6 ) )
F_11 ( L_3 ) ;
#ifdef F_12
V_8 =
F_6 ( L_4 ,
F_7 ( 0 ) , F_8 ( 0 ) , F_9 () ,
( ( V_9 & ~ V_10 ) |
V_11 | V_12 | V_13 |
V_15 ) ,
V_14 ,
F_3 ,
NULL ) ;
if ( F_10 ( V_8 ) )
F_11 ( L_5 ) ;
if ( F_13 ( V_8 , V_6 ) < 0 )
F_11 ( L_6 ) ;
#endif
return 0 ;
}
static T_1 int F_14 ( void )
{
T_2 V_1 ;
const T_3 * V_16 , * V_17 ;
T_4 V_18 ;
F_5 ( L_7 ) ;
V_16 = V_19 ;
V_17 = V_16 + V_20 ;
while ( V_16 < V_17 ) {
if ( V_17 - V_16 < 4 )
goto V_21;
if ( V_16 [ 0 ] != 0x30 &&
V_16 [ 1 ] != 0x82 )
goto V_21;
V_18 = ( V_16 [ 2 ] << 8 ) | V_16 [ 3 ] ;
V_18 += 4 ;
if ( V_18 > V_17 - V_16 )
goto V_21;
V_1 = F_15 ( F_16 ( V_6 , 1 ) ,
L_8 ,
NULL ,
V_16 ,
V_18 ,
( ( V_9 & ~ V_10 ) |
V_11 | V_12 ) ,
V_14 |
V_22 |
V_23 ) ;
if ( F_10 ( V_1 ) ) {
F_17 ( L_9 ,
F_18 ( V_1 ) ) ;
} else {
F_5 ( L_10 ,
F_19 ( V_1 ) -> V_24 ) ;
F_20 ( V_1 ) ;
}
V_16 += V_18 ;
}
return 0 ;
V_21:
F_17 ( L_11 ) ;
return 0 ;
}
int F_21 ( const void * V_25 , T_4 V_26 ,
const void * V_27 , T_4 V_28 ,
struct V_1 * V_29 ,
enum V_30 V_31 ,
int (* F_22)( void * V_32 ,
const void * V_25 , T_4 V_26 ,
T_4 V_33 ) ,
void * V_32 )
{
struct V_34 * V_35 ;
int V_36 ;
V_35 = F_23 ( V_27 , V_28 ) ;
if ( F_10 ( V_35 ) )
return F_18 ( V_35 ) ;
if ( V_25 && F_24 ( V_35 , V_25 , V_26 ) < 0 ) {
F_17 ( L_12 ) ;
V_36 = - V_37 ;
goto error;
}
V_36 = F_25 ( V_35 , V_31 ) ;
if ( V_36 < 0 )
goto error;
if ( ! V_29 ) {
V_29 = V_6 ;
} else if ( V_29 == ( void * ) 1UL ) {
#ifdef F_12
V_29 = V_8 ;
#else
V_29 = V_6 ;
#endif
}
V_36 = F_26 ( V_35 , V_29 ) ;
if ( V_36 < 0 ) {
if ( V_36 == - V_38 )
F_17 ( L_13 ) ;
goto error;
}
if ( F_22 ) {
T_4 V_33 ;
V_36 = F_27 ( V_35 , & V_25 , & V_26 , & V_33 ) ;
if ( V_36 < 0 ) {
if ( V_36 == - V_39 )
F_28 ( L_14 ) ;
goto error;
}
V_36 = F_22 ( V_32 , V_25 , V_26 , V_33 ) ;
}
error:
F_29 ( V_35 ) ;
F_28 ( L_15 , V_40 , V_36 ) ;
return V_36 ;
}
