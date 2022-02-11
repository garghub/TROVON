static int F_1 ( const T_1 * const * V_1 ,
const T_1 * const * V_2 )
{
return F_2 ( ( * V_1 ) -> V_3 -> V_4 , ( * V_2 ) -> V_3 -> V_4 ) ;
}
T_1 * F_3 ( const T_2 * V_5 ,
const T_1 * V_6 ,
const T_3 * V_7 )
{
T_1 * V_8 ;
int V_9 ;
for ( V_9 = 0 ; V_9 < F_4 ( V_5 -> V_10 ) ; V_9 ++ ) {
V_8 = F_5 ( V_5 -> V_10 , V_9 ) ;
if ( V_8 -> V_6 == V_6 ) {
if ( ! F_2 ( V_8 -> V_3 -> V_4 , V_7 ) )
return V_8 ;
}
}
return NULL ;
}
T_1 * F_6 ( T_2 * V_5 ,
T_4 * V_3 ,
T_1 * V_6 ,
T_5 * V_11 )
{
T_1 * V_8 ;
V_8 = F_7 ( sizeof( * V_8 ) ) ;
if ( V_8 == NULL )
return NULL ;
V_8 -> V_3 = V_3 ;
V_8 -> V_6 = V_6 ;
if ( V_5 ) {
if ( F_8 ( V_3 -> V_4 ) == V_12 ) {
if ( V_5 -> V_13 )
goto V_14;
V_5 -> V_13 = V_8 ;
} else {
if ( V_5 -> V_10 == NULL )
V_5 -> V_10 = F_9 () ;
if ( V_5 -> V_10 == NULL )
goto V_14;
if ( ! F_10 ( V_5 -> V_10 , V_8 ) )
goto V_14;
}
}
if ( V_11 ) {
if ( V_11 -> V_15 == NULL )
V_11 -> V_15 = F_11 () ;
if ( V_11 -> V_15 == NULL )
goto V_14;
if ( ! F_12 ( V_11 -> V_15 , V_3 ) )
goto V_14;
}
if ( V_6 )
V_6 -> V_16 ++ ;
return V_8 ;
V_14:
F_13 ( V_8 ) ;
return NULL ;
}
void F_13 ( T_1 * V_8 )
{
F_14 ( V_8 ) ;
}
int F_15 ( const T_2 * V_17 ,
const T_1 * V_8 , const T_3 * V_18 )
{
int V_9 ;
T_3 * V_19 ;
const T_4 * V_20 = V_8 -> V_3 ;
if ( ( V_17 -> V_21 & V_22 )
|| ! ( V_20 -> V_21 & V_23 ) ) {
if ( ! F_2 ( V_20 -> V_4 , V_18 ) )
return 1 ;
return 0 ;
}
for ( V_9 = 0 ; V_9 < F_16 ( V_20 -> V_24 ) ; V_9 ++ ) {
V_19 = F_17 ( V_20 -> V_24 , V_9 ) ;
if ( ! F_2 ( V_19 , V_18 ) )
return 1 ;
}
return 0 ;
}
