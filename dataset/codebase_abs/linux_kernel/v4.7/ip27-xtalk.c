static int F_1 ( T_1 V_1 , int V_2 , int V_3 )
{
T_2 V_4 ;
T_3 V_5 ;
V_4 = * ( volatile T_2 * )
( F_2 ( V_1 , V_2 ) + V_6 ) ;
V_5 = F_3 ( V_4 ) ;
F_4 ( V_7 L_1 ,
F_5 () , V_1 , V_2 , V_5 ) ;
switch ( V_5 ) {
case V_8 :
case V_9 :
F_6 ( V_1 , V_2 , V_3 ) ;
break;
default:
break;
}
return 0 ;
}
static int F_7 ( T_1 V_1 )
{
T_4 * V_10 ;
T_5 * V_11 ;
unsigned V_3 , V_12 ;
F_4 ( L_2 ) ;
V_10 = F_8 ( ( T_4 * ) F_9 ( V_1 ) , V_13 ) ;
if ( ! V_10 )
return - V_14 ;
V_11 = ( T_5 * ) F_10 ( V_10 , NULL , V_15 ) ;
if ( ! V_11 )
return - V_14 ;
#ifdef F_11
V_12 = V_16 + 1 ;
do {
V_12 -- ;
} while ( ( ! F_12 ( V_11 , V_12 ) ) ||
( ! F_13 ( V_11 , V_12 ) ) );
#else
V_12 = V_17 - 1 ;
do {
V_12 ++ ;
} while ( ( ! F_12 ( V_11 , V_12 ) ) ||
( ! F_13 ( V_11 , V_12 ) ) );
#endif
V_3 = V_12 ;
if ( V_1 != F_14 ( V_11 , V_12 ) )
return 1 ;
for ( V_12 = V_17 ; V_12 <= V_16 ; V_12 ++ ) {
if ( F_13 ( V_11 , V_12 ) &&
F_15 ( V_11 , V_12 ) )
F_1 ( V_1 , V_12 , V_3 ) ;
}
return 0 ;
}
void F_16 ( T_6 V_18 )
{
volatile T_7 V_19 ;
T_1 V_1 ;
T_3 V_5 ;
T_2 V_4 ;
V_1 = F_17 ( V_18 ) ;
V_19 = F_18 ( V_1 , V_20 ) ;
if ( ! ( V_19 & V_21 ) )
return;
V_4 = * ( volatile T_2 * )
( F_2 ( V_1 , 0x0 ) + V_6 ) ;
V_5 = F_3 ( V_4 ) ;
F_4 ( V_7 L_3 ,
F_5 () , V_1 , V_5 ) ;
switch ( V_5 ) {
case V_8 :
F_6 ( V_1 , 0x8 , 0xa ) ;
break;
case V_22 :
case V_23 :
F_7 ( V_1 ) ;
break;
default:
F_4 ( L_4 ) ;
break;
}
}
