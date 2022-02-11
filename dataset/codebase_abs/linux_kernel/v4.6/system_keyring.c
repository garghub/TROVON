static T_1 int F_1 ( void )
{
F_2 ( L_1 ) ;
V_1 =
F_3 ( L_2 ,
F_4 ( 0 ) , F_5 ( 0 ) , F_6 () ,
( ( V_2 & ~ V_3 ) |
V_4 | V_5 | V_6 ) ,
V_7 , NULL ) ;
if ( F_7 ( V_1 ) )
F_8 ( L_3 ) ;
F_9 ( V_8 , & V_1 -> V_9 ) ;
return 0 ;
}
static T_1 int F_10 ( void )
{
T_2 V_10 ;
const T_3 * V_11 , * V_12 ;
T_4 V_13 ;
F_2 ( L_4 ) ;
V_11 = V_14 ;
V_12 = V_11 + V_15 ;
while ( V_11 < V_12 ) {
if ( V_12 - V_11 < 4 )
goto V_16;
if ( V_11 [ 0 ] != 0x30 &&
V_11 [ 1 ] != 0x82 )
goto V_16;
V_13 = ( V_11 [ 2 ] << 8 ) | V_11 [ 3 ] ;
V_13 += 4 ;
if ( V_13 > V_12 - V_11 )
goto V_16;
V_10 = F_11 ( F_12 ( V_1 , 1 ) ,
L_5 ,
NULL ,
V_11 ,
V_13 ,
( ( V_2 & ~ V_3 ) |
V_4 | V_5 ) ,
V_7 |
V_17 |
V_18 ) ;
if ( F_7 ( V_10 ) ) {
F_13 ( L_6 ,
F_14 ( V_10 ) ) ;
} else {
F_2 ( L_7 ,
F_15 ( V_10 ) -> V_19 ) ;
F_16 ( V_10 ) ;
}
V_11 += V_13 ;
}
return 0 ;
V_16:
F_13 ( L_8 ) ;
return 0 ;
}
int F_17 ( const void * V_20 , unsigned long V_21 ,
const void * V_22 , T_4 V_23 ,
enum V_24 V_25 )
{
struct V_26 * V_27 ;
bool V_28 ;
int V_29 ;
V_27 = F_18 ( V_22 , V_23 ) ;
if ( F_7 ( V_27 ) )
return F_14 ( V_27 ) ;
if ( F_19 ( V_27 , V_20 , V_21 ) < 0 ) {
F_13 ( L_9 ) ;
V_29 = - V_30 ;
goto error;
}
V_29 = F_20 ( V_27 , V_25 ) ;
if ( V_29 < 0 )
goto error;
V_29 = F_21 ( V_27 , V_1 , & V_28 ) ;
if ( V_29 < 0 )
goto error;
if ( ! V_28 ) {
F_13 ( L_10 ) ;
V_29 = - V_31 ;
}
error:
F_22 ( V_27 ) ;
F_23 ( L_11 , V_32 , V_29 ) ;
return V_29 ;
}
