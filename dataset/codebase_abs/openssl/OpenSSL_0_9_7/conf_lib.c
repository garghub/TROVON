void F_1 ( T_1 * V_1 , T_2 * V_2 )
{
if ( V_3 == NULL )
V_3 = F_2 () ;
V_3 -> V_4 ( V_1 ) ;
V_1 -> V_5 = V_2 ;
}
int F_3 ( T_3 * V_6 )
{
V_3 = V_6 ;
return 1 ;
}
T_2 * F_4 ( T_2 * V_1 , const char * V_7 , long * V_8 )
{
T_2 * V_9 ;
T_4 * V_10 = NULL ;
#ifdef F_5
V_10 = F_6 ( V_7 , L_1 ) ;
#else
V_10 = F_6 ( V_7 , L_2 ) ;
#endif
if ( V_10 == NULL )
{
F_7 ( V_11 , V_12 ) ;
return NULL ;
}
V_9 = F_8 ( V_1 , V_10 , V_8 ) ;
F_9 ( V_10 ) ;
return V_9 ;
}
T_2 * F_10 ( T_2 * V_1 , T_5 * V_13 , long * V_8 )
{
T_4 * V_14 ;
T_2 * V_9 ;
if( ! ( V_14 = F_11 ( V_13 , V_15 ) ) ) {
F_7 ( V_16 , V_17 ) ;
return NULL ;
}
V_9 = F_8 ( V_1 , V_14 , V_8 ) ;
F_9 ( V_14 ) ;
return V_9 ;
}
T_2 * F_8 ( T_2 * V_1 , T_4 * V_18 , long * V_8 )
{
T_1 V_19 ;
int V_20 ;
F_1 ( & V_19 , V_1 ) ;
V_20 = F_12 ( & V_19 , V_18 , V_8 ) ;
if ( V_20 )
return V_19 . V_5 ;
return NULL ;
}
void F_13 ( T_2 * V_1 )
{
T_1 V_19 ;
F_1 ( & V_19 , V_1 ) ;
F_14 ( & V_19 ) ;
}
int F_15 ( T_2 * V_1 , T_5 * V_21 )
{
T_4 * V_14 ;
int V_20 ;
if( ! ( V_14 = F_11 ( V_21 , V_15 ) ) ) {
F_7 ( V_22 , V_17 ) ;
return 0 ;
}
V_20 = F_16 ( V_1 , V_14 ) ;
F_9 ( V_14 ) ;
return V_20 ;
}
int F_16 ( T_2 * V_1 , T_4 * V_21 )
{
T_1 V_19 ;
F_1 ( & V_19 , V_1 ) ;
return F_17 ( & V_19 , V_21 ) ;
}
T_1 * F_18 ( T_3 * V_6 )
{
T_1 * V_20 ;
if ( V_6 == NULL )
V_6 = F_2 () ;
V_20 = V_6 -> V_23 ( V_6 ) ;
if ( V_20 == NULL )
{
F_7 ( V_24 , V_25 ) ;
return ( NULL ) ;
}
return V_20 ;
}
void F_19 ( T_1 * V_1 )
{
if ( V_1 == NULL )
return;
V_1 -> V_6 -> V_26 ( V_1 ) ;
}
void F_14 ( T_1 * V_1 )
{
if ( V_1 == NULL )
return;
V_1 -> V_6 -> V_27 ( V_1 ) ;
}
int F_20 ( T_1 * V_1 , const char * V_7 , long * V_8 )
{
if ( V_1 == NULL )
{
F_7 ( V_28 , V_29 ) ;
return 0 ;
}
return V_1 -> V_6 -> V_30 ( V_1 , V_7 , V_8 ) ;
}
int F_21 ( T_1 * V_1 , T_5 * V_13 , long * V_8 )
{
T_4 * V_14 ;
int V_20 ;
if( ! ( V_14 = F_11 ( V_13 , V_15 ) ) )
{
F_7 ( V_31 , V_17 ) ;
return 0 ;
}
V_20 = F_12 ( V_1 , V_14 , V_8 ) ;
F_9 ( V_14 ) ;
return V_20 ;
}
int F_12 ( T_1 * V_1 , T_4 * V_18 , long * V_8 )
{
if ( V_1 == NULL )
{
F_7 ( V_32 , V_29 ) ;
return 0 ;
}
return V_1 -> V_6 -> V_33 ( V_1 , V_18 , V_8 ) ;
}
int F_22 ( const T_1 * V_1 , T_5 * V_21 )
{
T_4 * V_14 ;
int V_20 ;
if( ! ( V_14 = F_11 ( V_21 , V_15 ) ) ) {
F_7 ( V_34 , V_17 ) ;
return 0 ;
}
V_20 = F_17 ( V_1 , V_14 ) ;
F_9 ( V_14 ) ;
return V_20 ;
}
int F_17 ( const T_1 * V_1 , T_4 * V_21 )
{
if ( V_1 == NULL )
{
F_7 ( V_35 , V_29 ) ;
return 0 ;
}
return V_1 -> V_6 -> V_36 ( V_1 , V_21 ) ;
}
