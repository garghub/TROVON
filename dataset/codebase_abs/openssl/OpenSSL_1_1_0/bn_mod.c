int F_1 ( T_1 * V_1 , const T_1 * V_2 , const T_1 * V_3 , T_2 * V_4 )
{
if ( ! ( F_2 ( V_1 , V_2 , V_3 , V_4 ) ) )
return 0 ;
if ( ! V_1 -> V_5 )
return 1 ;
return ( V_3 -> V_5 ? V_6 : V_7 ) ( V_1 , V_1 , V_3 ) ;
}
int F_3 ( T_1 * V_1 , const T_1 * V_8 , const T_1 * V_9 , const T_1 * V_2 ,
T_2 * V_4 )
{
if ( ! V_7 ( V_1 , V_8 , V_9 ) )
return 0 ;
return F_1 ( V_1 , V_1 , V_2 , V_4 ) ;
}
int F_4 ( T_1 * V_1 , const T_1 * V_8 , const T_1 * V_9 ,
const T_1 * V_2 )
{
if ( ! F_5 ( V_1 , V_8 , V_9 ) )
return 0 ;
if ( F_6 ( V_1 , V_2 ) >= 0 )
return F_7 ( V_1 , V_1 , V_2 ) ;
return 1 ;
}
int F_8 ( T_1 * V_1 , const T_1 * V_8 , const T_1 * V_9 , const T_1 * V_2 ,
T_2 * V_4 )
{
if ( ! V_6 ( V_1 , V_8 , V_9 ) )
return 0 ;
return F_1 ( V_1 , V_1 , V_2 , V_4 ) ;
}
int F_9 ( T_1 * V_1 , const T_1 * V_8 , const T_1 * V_9 ,
const T_1 * V_2 )
{
if ( ! V_6 ( V_1 , V_8 , V_9 ) )
return 0 ;
if ( V_1 -> V_5 )
return V_7 ( V_1 , V_1 , V_2 ) ;
return 1 ;
}
int F_10 ( T_1 * V_1 , const T_1 * V_8 , const T_1 * V_9 , const T_1 * V_2 ,
T_2 * V_4 )
{
T_1 * V_10 ;
int V_11 = 0 ;
F_11 ( V_8 ) ;
F_11 ( V_9 ) ;
F_11 ( V_2 ) ;
F_12 ( V_4 ) ;
if ( ( V_10 = F_13 ( V_4 ) ) == NULL )
goto V_12;
if ( V_8 == V_9 ) {
if ( ! F_14 ( V_10 , V_8 , V_4 ) )
goto V_12;
} else {
if ( ! F_15 ( V_10 , V_8 , V_9 , V_4 ) )
goto V_12;
}
if ( ! F_1 ( V_1 , V_10 , V_2 , V_4 ) )
goto V_12;
F_11 ( V_1 ) ;
V_11 = 1 ;
V_12:
F_16 ( V_4 ) ;
return ( V_11 ) ;
}
int F_17 ( T_1 * V_1 , const T_1 * V_8 , const T_1 * V_2 , T_2 * V_4 )
{
if ( ! F_14 ( V_1 , V_8 , V_4 ) )
return 0 ;
return F_2 ( V_1 , V_1 , V_2 , V_4 ) ;
}
int F_18 ( T_1 * V_1 , const T_1 * V_8 , const T_1 * V_2 , T_2 * V_4 )
{
if ( ! F_19 ( V_1 , V_8 ) )
return 0 ;
F_11 ( V_1 ) ;
return F_1 ( V_1 , V_1 , V_2 , V_4 ) ;
}
int F_20 ( T_1 * V_1 , const T_1 * V_8 , const T_1 * V_2 )
{
if ( ! F_19 ( V_1 , V_8 ) )
return 0 ;
F_11 ( V_1 ) ;
if ( F_21 ( V_1 , V_2 ) >= 0 )
return V_6 ( V_1 , V_1 , V_2 ) ;
return 1 ;
}
int F_22 ( T_1 * V_1 , const T_1 * V_8 , int V_13 , const T_1 * V_2 ,
T_2 * V_4 )
{
T_1 * V_14 = NULL ;
int V_11 ;
if ( ! F_1 ( V_1 , V_8 , V_2 , V_4 ) )
return 0 ;
if ( V_2 -> V_5 ) {
V_14 = F_23 ( V_2 ) ;
if ( V_14 == NULL )
return 0 ;
V_14 -> V_5 = 0 ;
}
V_11 = F_24 ( V_1 , V_1 , V_13 , ( V_14 ? V_14 : V_2 ) ) ;
F_11 ( V_1 ) ;
F_25 ( V_14 ) ;
return V_11 ;
}
int F_24 ( T_1 * V_1 , const T_1 * V_8 , int V_13 , const T_1 * V_2 )
{
if ( V_1 != V_8 ) {
if ( F_26 ( V_1 , V_8 ) == NULL )
return 0 ;
}
while ( V_13 > 0 ) {
int V_15 ;
V_15 = F_27 ( V_2 ) - F_27 ( V_1 ) ;
if ( V_15 < 0 ) {
F_28 ( V_16 , V_17 ) ;
return 0 ;
}
if ( V_15 > V_13 )
V_15 = V_13 ;
if ( V_15 ) {
if ( ! F_29 ( V_1 , V_1 , V_15 ) )
return 0 ;
V_13 -= V_15 ;
} else {
if ( ! F_19 ( V_1 , V_1 ) )
return 0 ;
-- V_13 ;
}
if ( F_21 ( V_1 , V_2 ) >= 0 ) {
if ( ! V_6 ( V_1 , V_1 , V_2 ) )
return 0 ;
}
}
F_11 ( V_1 ) ;
return 1 ;
}
