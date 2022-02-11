static T_1 * F_1 ( T_2 * V_1 )
{
if ( V_1 == NULL )
return NULL ;
if ( V_1 -> V_2 == NULL && ( V_1 -> V_2 = F_2 () ) == NULL )
return NULL ;
return V_1 -> V_2 ;
}
int F_3 ( T_2 * V_1 , const unsigned char * V_3 , int V_4 )
{
T_1 * V_2 ;
if ( ! V_3 ) {
if ( ! V_1 || ! V_1 -> V_2 || ! V_1 -> V_2 -> V_5 )
return 1 ;
F_4 ( V_1 -> V_2 -> V_5 ) ;
V_1 -> V_2 -> V_5 = NULL ;
return 1 ;
}
if ( ( V_2 = F_1 ( V_1 ) ) == NULL )
return 0 ;
if ( V_2 -> V_5 == NULL && ( V_2 -> V_5 = F_5 () ) == NULL )
return 0 ;
return F_6 ( V_2 -> V_5 , V_3 , V_4 ) ;
}
int F_7 ( T_2 * V_1 , const unsigned char * V_6 , int V_4 )
{
T_1 * V_2 ;
if ( ! V_6 ) {
if ( ! V_1 || ! V_1 -> V_2 || ! V_1 -> V_2 -> V_7 )
return 1 ;
F_8 ( V_1 -> V_2 -> V_7 ) ;
V_1 -> V_2 -> V_7 = NULL ;
return 1 ;
}
if ( ( V_2 = F_1 ( V_1 ) ) == NULL )
return 0 ;
if ( V_2 -> V_7 == NULL
&& ( V_2 -> V_7 = F_9 () ) == NULL )
return 0 ;
return F_6 ( V_2 -> V_7 , V_6 , V_4 ) ;
}
unsigned char * F_10 ( T_2 * V_1 , int * V_4 )
{
if ( ! V_1 -> V_2 || ! V_1 -> V_2 -> V_5 )
return NULL ;
if ( V_4 )
* V_4 = V_1 -> V_2 -> V_5 -> V_8 ;
return V_1 -> V_2 -> V_5 -> V_9 ;
}
unsigned char * F_11 ( T_2 * V_1 , int * V_4 )
{
if ( ! V_1 -> V_2 || ! V_1 -> V_2 -> V_7 )
return NULL ;
if ( V_4 )
* V_4 = V_1 -> V_2 -> V_7 -> V_8 ;
return V_1 -> V_2 -> V_7 -> V_9 ;
}
int F_12 ( T_2 * V_1 , const T_3 * V_10 )
{
T_1 * V_2 ;
T_3 * V_11 = NULL ;
if ( V_10 ) {
V_11 = F_13 ( V_10 ) ;
if ( ! V_11 )
return 0 ;
}
if ( ( V_2 = F_1 ( V_1 ) ) == NULL )
goto V_12;
if ( V_2 -> V_13 == NULL
&& ( V_2 -> V_13 = F_14 () ) == NULL )
goto V_12;
if ( ! V_11 || F_15 ( V_2 -> V_13 , V_11 ) )
return 1 ;
V_12:
F_16 ( V_11 ) ;
return 0 ;
}
int F_17 ( T_2 * V_1 , const T_3 * V_10 )
{
T_1 * V_2 ;
T_3 * V_11 ;
if ( ( V_11 = F_13 ( V_10 ) ) == NULL )
return 0 ;
if ( ( V_2 = F_1 ( V_1 ) ) == NULL )
goto V_12;
if ( V_2 -> V_14 == NULL
&& ( V_2 -> V_14 = F_14 () ) == NULL )
goto V_12;
return F_15 ( V_2 -> V_14 , V_11 ) ;
V_12:
F_16 ( V_11 ) ;
return 0 ;
}
void F_18 ( T_2 * V_1 )
{
if ( V_1 -> V_2 ) {
F_19 ( V_1 -> V_2 -> V_13 , F_16 ) ;
V_1 -> V_2 -> V_13 = NULL ;
}
}
void F_20 ( T_2 * V_1 )
{
if ( V_1 -> V_2 ) {
F_19 ( V_1 -> V_2 -> V_14 , F_16 ) ;
V_1 -> V_2 -> V_14 = NULL ;
}
}
