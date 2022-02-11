void * F_1 ( T_1 * V_1 , T_2 * V_2 )
{
const unsigned char * V_3 ;
char * V_4 ;
V_3 = V_1 -> V_5 ;
if ( ! ( V_4 = V_2 ( NULL , & V_3 , V_1 -> V_6 ) ) )
F_2 ( V_7 , V_8 ) ;
return V_4 ;
}
T_1 * F_3 ( void * V_9 , T_3 * V_10 , T_1 * * V_1 )
{
unsigned char * V_3 ;
T_1 * V_11 ;
if ( ! V_1 || ! * V_1 ) {
if ( ! ( V_11 = F_4 () ) ) {
F_2 ( V_12 , V_13 ) ;
return NULL ;
}
if ( V_1 )
* V_1 = V_11 ;
} else
V_11 = * V_1 ;
if ( ! ( V_11 -> V_6 = V_10 ( V_9 , NULL ) ) ) {
F_2 ( V_12 , V_14 ) ;
goto V_15;
}
if ( ! ( V_3 = F_5 ( V_11 -> V_6 ) ) ) {
F_2 ( V_12 , V_13 ) ;
goto V_15;
}
V_11 -> V_5 = V_3 ;
V_10 ( V_9 , & V_3 ) ;
return V_11 ;
V_15:
if ( ! V_1 || ! * V_1 ) {
F_6 ( V_11 ) ;
if ( V_1 )
* V_1 = NULL ;
}
return NULL ;
}
T_1 * F_7 ( void * V_9 , const T_4 * V_16 , T_1 * * V_1 )
{
T_1 * V_11 ;
if ( ! V_1 || ! * V_1 ) {
if ( ! ( V_11 = F_4 () ) ) {
F_2 ( V_17 , V_13 ) ;
return NULL ;
}
if ( V_1 )
* V_1 = V_11 ;
} else
V_11 = * V_1 ;
if ( V_11 -> V_5 ) {
F_8 ( V_11 -> V_5 ) ;
V_11 -> V_5 = NULL ;
}
if ( ! ( V_11 -> V_6 = F_9 ( V_9 , & V_11 -> V_5 , V_16 ) ) ) {
F_2 ( V_17 , V_14 ) ;
return NULL ;
}
if ( ! V_11 -> V_5 ) {
F_2 ( V_17 , V_13 ) ;
return NULL ;
}
return V_11 ;
}
void * F_10 ( T_1 * V_1 , const T_4 * V_16 )
{
const unsigned char * V_3 ;
void * V_4 ;
V_3 = V_1 -> V_5 ;
if ( ! ( V_4 = F_11 ( NULL , & V_3 , V_1 -> V_6 , V_16 ) ) )
F_2 ( V_18 , V_8 ) ;
return V_4 ;
}
