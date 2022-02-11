int F_1 ( T_1 * V_1 )
{
V_2 = V_1 ;
return 1 ;
}
T_2 * F_2 ( T_1 * V_1 )
{
T_2 * V_3 ;
if ( V_1 == NULL )
V_1 = F_3 () ;
V_3 = V_1 -> V_4 ( V_1 ) ;
if ( V_3 == NULL ) {
F_4 ( V_5 , V_6 ) ;
return ( NULL ) ;
}
return V_3 ;
}
void F_5 ( T_2 * V_7 )
{
if ( V_7 == NULL )
return;
V_7 -> V_1 -> V_8 ( V_7 ) ;
}
void F_6 ( T_2 * V_7 )
{
if ( V_7 == NULL )
return;
V_7 -> V_1 -> V_9 ( V_7 ) ;
}
int F_7 ( T_2 * V_7 , const char * V_10 , long * V_11 )
{
if ( V_7 == NULL ) {
F_4 ( V_12 , V_13 ) ;
return 0 ;
}
return V_7 -> V_1 -> V_14 ( V_7 , V_10 , V_11 ) ;
}
int F_8 ( T_2 * V_7 , T_3 * V_15 , long * V_11 )
{
T_4 * V_16 ;
int V_3 ;
if ( ! ( V_16 = F_9 ( V_15 , V_17 ) ) ) {
F_4 ( V_18 , V_19 ) ;
return 0 ;
}
V_3 = F_10 ( V_7 , V_16 , V_11 ) ;
F_11 ( V_16 ) ;
return V_3 ;
}
int F_10 ( T_2 * V_7 , T_4 * V_20 , long * V_11 )
{
if ( V_7 == NULL ) {
F_4 ( V_21 , V_13 ) ;
return 0 ;
}
return V_7 -> V_1 -> V_22 ( V_7 , V_20 , V_11 ) ;
}
int F_12 ( const T_2 * V_7 , T_3 * V_23 )
{
T_4 * V_16 ;
int V_3 ;
if ( ! ( V_16 = F_9 ( V_23 , V_17 ) ) ) {
F_4 ( V_24 , V_19 ) ;
return 0 ;
}
V_3 = F_13 ( V_7 , V_16 ) ;
F_11 ( V_16 ) ;
return V_3 ;
}
int F_13 ( const T_2 * V_7 , T_4 * V_23 )
{
if ( V_7 == NULL ) {
F_4 ( V_25 , V_13 ) ;
return 0 ;
}
return V_7 -> V_1 -> V_26 ( V_7 , V_23 ) ;
}
