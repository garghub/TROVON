T_1
F_1 ( const T_2 * V_1 , T_3 * V_2 , T_1 V_3 )
{
int V_4 ;
T_4 V_5 ;
int V_6 ;
T_5 V_7 ;
T_6 * V_8 ;
int V_9 ;
V_4 = F_2 ( V_1 , V_10 | V_11 | V_12 |
V_13 , 0644 ) ;
if( V_4 == - 1 ) {
if ( V_3 )
F_3 ( V_1 , V_14 , TRUE ) ;
return FALSE ;
}
V_8 = V_2 -> V_15 ;
V_5 = V_2 -> V_16 ;
while ( V_5 != 0 ) {
if ( V_5 > 0x40000000 )
V_6 = 0x40000000 ;
else
V_6 = ( int ) V_5 ;
V_7 = F_4 ( V_4 , V_8 , V_6 ) ;
if( V_7 <= 0 ) {
if ( V_7 < 0 )
V_9 = V_14 ;
else
V_9 = V_17 ;
if ( V_3 )
F_5 ( V_1 , V_9 ) ;
F_6 ( V_4 ) ;
return FALSE ;
}
V_5 -= V_7 ;
V_8 += V_7 ;
}
if ( F_6 ( V_4 ) < 0 ) {
if ( V_3 )
F_5 ( V_1 , V_14 ) ;
return FALSE ;
}
return TRUE ;
}
static T_7 * F_7 ( T_7 * V_18 , int V_19 )
{
T_7 * V_20 ;
T_2 * V_21 ;
T_7 * V_22 ;
V_20 = F_8 ( L_1 ) ;
F_9 ( V_20 , L_2 , V_19 ) ;
if ( ( V_21 = strrchr ( V_18 -> V_23 , '.' ) ) != NULL ) {
V_22 = F_8 ( V_21 ) ;
V_18 = F_10 ( V_18 , V_18 -> V_24 - V_22 -> V_24 ) ;
if ( V_18 -> V_24 >= ( V_25 - ( strlen ( V_20 -> V_23 ) + V_22 -> V_24 ) ) )
V_18 = F_10 ( V_18 , V_25 - ( strlen ( V_20 -> V_23 ) + V_22 -> V_24 ) ) ;
V_18 = F_11 ( V_18 , V_20 -> V_23 ) ;
V_18 = F_11 ( V_18 , V_22 -> V_23 ) ;
F_12 ( V_22 , TRUE ) ;
}
else {
if ( V_18 -> V_24 >= ( V_25 - strlen ( V_20 -> V_23 ) ) )
V_18 = F_10 ( V_18 , V_25 - strlen ( V_20 -> V_23 ) ) ;
V_18 = F_11 ( V_18 , V_20 -> V_23 ) ;
}
F_12 ( V_20 , TRUE ) ;
return V_18 ;
}
T_7 *
F_13 ( const T_2 * V_26 , T_8 V_27 , int V_19 )
{
T_2 * V_21 ;
const T_2 * V_28 = L_3
L_4
L_5
L_6 ;
T_7 * V_29 ;
T_7 * V_22 ;
V_29 = F_8 ( L_7 ) ;
while ( ( V_21 = strpbrk ( V_26 , V_28 ) ) != NULL ) {
V_29 = F_14 ( V_29 , V_26 , V_21 - V_26 ) ;
V_29 = F_15 ( V_29 , '%' ) ;
V_29 = F_15 ( V_29 , F_16 ( F_17 ( * V_21 ) ) ) ;
V_29 = F_15 ( V_29 , F_16 ( F_18 ( * V_21 ) ) ) ;
V_26 = V_21 + 1 ;
}
V_29 = F_11 ( V_29 , V_26 ) ;
if ( V_29 -> V_24 > V_27 ) {
if ( ( V_21 = strrchr ( V_29 -> V_23 , '.' ) ) != NULL ) {
V_22 = F_8 ( V_21 ) ;
V_29 = F_10 ( V_29 , V_27 - V_22 -> V_24 ) ;
V_29 = F_11 ( V_29 , V_22 -> V_23 ) ;
F_12 ( V_22 , TRUE ) ;
}
else
V_29 = F_10 ( V_29 , V_27 ) ;
}
if ( V_19 != 0 )
V_29 = F_7 ( V_29 , V_19 ) ;
return V_29 ;
}
const char *
F_19 ( const char * V_30 )
{
return V_30 ;
}
