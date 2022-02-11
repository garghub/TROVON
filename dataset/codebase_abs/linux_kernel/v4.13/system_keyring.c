int F_1 ( struct V_1 * V_2 ,
const struct V_3 * type ,
const union V_4 * V_5 ,
struct V_1 * V_6 )
{
return F_2 ( V_2 , type , V_5 ,
V_7 ) ;
}
int F_3 (
struct V_1 * V_2 ,
const struct V_3 * type ,
const union V_4 * V_5 ,
struct V_1 * V_8 )
{
if ( type == & V_9 &&
V_2 == V_10 &&
V_5 == & V_7 -> V_5 )
return 0 ;
return F_2 ( V_2 , type , V_5 ,
V_10 ) ;
}
T_1 int F_4 ( void )
{
F_5 ( L_1 ) ;
V_7 =
F_6 ( L_2 ,
F_7 ( 0 ) , F_8 ( 0 ) , F_9 () ,
( ( V_11 & ~ V_12 ) |
V_13 | V_14 | V_15 ) ,
V_16 ,
NULL , NULL ) ;
if ( F_10 ( V_7 ) )
F_11 ( L_3 ) ;
#ifdef F_12
V_10 =
F_6 ( L_4 ,
F_7 ( 0 ) , F_8 ( 0 ) , F_9 () ,
( ( V_11 & ~ V_12 ) |
V_13 | V_14 | V_15 |
V_17 ) ,
V_16 ,
F_13 () ,
NULL ) ;
if ( F_10 ( V_10 ) )
F_11 ( L_5 ) ;
if ( F_14 ( V_10 , V_7 ) < 0 )
F_11 ( L_6 ) ;
#endif
return 0 ;
}
static T_1 int F_15 ( void )
{
T_2 V_1 ;
const T_3 * V_18 , * V_19 ;
T_4 V_20 ;
F_5 ( L_7 ) ;
V_18 = V_21 ;
V_19 = V_18 + V_22 ;
while ( V_18 < V_19 ) {
if ( V_19 - V_18 < 4 )
goto V_23;
if ( V_18 [ 0 ] != 0x30 &&
V_18 [ 1 ] != 0x82 )
goto V_23;
V_20 = ( V_18 [ 2 ] << 8 ) | V_18 [ 3 ] ;
V_20 += 4 ;
if ( V_20 > V_19 - V_18 )
goto V_23;
V_1 = F_16 ( F_17 ( V_7 , 1 ) ,
L_8 ,
NULL ,
V_18 ,
V_20 ,
( ( V_11 & ~ V_12 ) |
V_13 | V_14 ) ,
V_16 |
V_24 |
V_25 ) ;
if ( F_10 ( V_1 ) ) {
F_18 ( L_9 ,
F_19 ( V_1 ) ) ;
} else {
F_5 ( L_10 ,
F_20 ( V_1 ) -> V_26 ) ;
F_21 ( V_1 ) ;
}
V_18 += V_20 ;
}
return 0 ;
V_23:
F_18 ( L_11 ) ;
return 0 ;
}
int F_22 ( const void * V_27 , T_4 V_28 ,
const void * V_29 , T_4 V_30 ,
struct V_1 * V_31 ,
enum V_32 V_33 ,
int (* F_23)( void * V_34 ,
const void * V_27 , T_4 V_28 ,
T_4 V_35 ) ,
void * V_34 )
{
struct V_36 * V_37 ;
int V_38 ;
V_37 = F_24 ( V_29 , V_30 ) ;
if ( F_10 ( V_37 ) )
return F_19 ( V_37 ) ;
if ( V_27 && F_25 ( V_37 , V_27 , V_28 ) < 0 ) {
F_18 ( L_12 ) ;
V_38 = - V_39 ;
goto error;
}
V_38 = F_26 ( V_37 , V_33 ) ;
if ( V_38 < 0 )
goto error;
if ( ! V_31 ) {
V_31 = V_7 ;
} else if ( V_31 == ( void * ) 1UL ) {
#ifdef F_12
V_31 = V_10 ;
#else
V_31 = V_7 ;
#endif
}
V_38 = F_27 ( V_37 , V_31 ) ;
if ( V_38 < 0 ) {
if ( V_38 == - V_40 )
F_18 ( L_13 ) ;
goto error;
}
if ( F_23 ) {
T_4 V_35 ;
V_38 = F_28 ( V_37 , & V_27 , & V_28 , & V_35 ) ;
if ( V_38 < 0 ) {
if ( V_38 == - V_41 )
F_29 ( L_14 ) ;
goto error;
}
V_38 = F_23 ( V_34 , V_27 , V_28 , V_35 ) ;
}
error:
F_30 ( V_37 ) ;
F_29 ( L_15 , V_42 , V_38 ) ;
return V_38 ;
}
