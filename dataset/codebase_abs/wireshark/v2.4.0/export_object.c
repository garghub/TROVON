int
F_1 ( const int V_1 , T_1 V_2 , T_2 V_3 )
{
T_3 * V_4 ;
F_2 ( V_2 ) ;
V_4 = F_3 ( F_4 () , T_3 ) ;
V_4 -> V_1 = V_1 ;
V_4 -> V_5 = F_5 ( F_4 () , L_1 , F_6 ( V_1 ) ) ;
V_4 -> V_6 = V_2 ;
V_4 -> V_3 = V_3 ;
if ( V_7 == NULL )
V_7 = F_7 ( F_4 () ) ;
F_8 ( V_7 , F_6 ( V_1 ) , V_4 , 0 ) ;
return F_9 ( V_4 -> V_5 ) ;
}
int F_10 ( T_3 * V_8 )
{
if ( ! V_8 ) {
return - 1 ;
}
return V_8 -> V_1 ;
}
const char * F_11 ( T_3 * V_8 )
{
return V_8 -> V_5 ;
}
T_1 F_12 ( T_3 * V_8 )
{
return V_8 -> V_6 ;
}
T_2 F_13 ( T_3 * V_8 )
{
return V_8 -> V_3 ;
}
T_3 * F_14 ( const char * V_9 )
{
return ( T_3 * ) F_15 ( V_7 , V_9 , 0 ) ;
}
void F_16 ( T_4 V_10 , T_5 V_11 )
{
F_17 ( V_7 , V_10 , V_11 ) ;
}
static T_6 * F_18 ( T_6 * V_12 , int V_13 )
{
T_6 * V_14 ;
T_7 * V_15 ;
T_6 * V_16 ;
V_14 = F_19 ( L_2 ) ;
F_20 ( V_14 , L_3 , V_13 ) ;
if ( ( V_15 = strrchr ( V_12 -> V_17 , '.' ) ) != NULL ) {
V_16 = F_19 ( V_15 ) ;
V_12 = F_21 ( V_12 , V_12 -> V_18 - V_16 -> V_18 ) ;
if ( V_12 -> V_18 >= ( V_19 - ( strlen ( V_14 -> V_17 ) + V_16 -> V_18 ) ) )
V_12 = F_21 ( V_12 , V_19 - ( strlen ( V_14 -> V_17 ) + V_16 -> V_18 ) ) ;
V_12 = F_22 ( V_12 , V_14 -> V_17 ) ;
V_12 = F_22 ( V_12 , V_16 -> V_17 ) ;
F_23 ( V_16 , TRUE ) ;
}
else {
if ( V_12 -> V_18 >= ( V_19 - strlen ( V_14 -> V_17 ) ) )
V_12 = F_21 ( V_12 , V_19 - strlen ( V_14 -> V_17 ) ) ;
V_12 = F_22 ( V_12 , V_14 -> V_17 ) ;
}
F_23 ( V_14 , TRUE ) ;
return V_12 ;
}
T_6 *
F_24 ( const T_7 * V_20 , T_8 V_21 , int V_13 )
{
T_7 * V_15 ;
const T_7 * V_22 = L_4
L_5
L_6
L_7 ;
T_6 * V_23 ;
T_6 * V_16 ;
V_23 = F_19 ( L_8 ) ;
while ( ( V_15 = strpbrk ( V_20 , V_22 ) ) != NULL ) {
V_23 = F_25 ( V_23 , V_20 , V_15 - V_20 ) ;
F_20 ( V_23 , L_9 , * V_15 ) ;
V_20 = V_15 + 1 ;
}
V_23 = F_22 ( V_23 , V_20 ) ;
if ( V_23 -> V_18 > V_21 ) {
if ( ( V_15 = strrchr ( V_23 -> V_17 , '.' ) ) != NULL ) {
V_16 = F_19 ( V_15 ) ;
V_23 = F_21 ( V_23 , V_21 - V_16 -> V_18 ) ;
V_23 = F_22 ( V_23 , V_16 -> V_17 ) ;
F_23 ( V_16 , TRUE ) ;
}
else
V_23 = F_21 ( V_23 , V_21 ) ;
}
if ( V_13 != 0 )
V_23 = F_18 ( V_23 , V_13 ) ;
return V_23 ;
}
const char *
F_26 ( const char * V_24 )
{
return V_24 ;
}
void F_27 ( T_9 * V_25 )
{
F_28 ( V_25 -> V_26 ) ;
F_28 ( V_25 -> V_24 ) ;
F_28 ( V_25 -> V_27 ) ;
F_28 ( V_25 -> V_28 ) ;
F_28 ( V_25 ) ;
}
