int F_1 ( T_1 * V_1 )
{
V_2 = V_1 ;
return 1 ;
}
T_2 * F_2 ( T_2 * V_3 , const char * V_4 , long * V_5 )
{
T_2 * V_6 ;
T_3 * V_7 = NULL ;
#ifdef F_3
V_7 = F_4 ( V_4 , L_1 ) ;
#else
V_7 = F_4 ( V_4 , L_2 ) ;
#endif
if ( V_7 == NULL )
{
F_5 ( V_8 , V_9 ) ;
return NULL ;
}
V_6 = F_6 ( V_3 , V_7 , V_5 ) ;
F_7 ( V_7 ) ;
return V_6 ;
}
T_2 * F_8 ( T_2 * V_3 , T_4 * V_10 , long * V_5 )
{
T_3 * V_11 ;
T_2 * V_6 ;
if( ! ( V_11 = F_9 ( V_10 , V_12 ) ) ) {
F_5 ( V_13 , V_14 ) ;
return NULL ;
}
V_6 = F_6 ( V_3 , V_11 , V_5 ) ;
F_7 ( V_11 ) ;
return V_6 ;
}
T_2 * F_6 ( T_2 * V_3 , T_3 * V_15 , long * V_5 )
{
T_5 V_16 ;
int V_17 ;
if ( V_2 == NULL )
V_2 = F_10 () ;
V_2 -> V_18 ( & V_16 ) ;
V_16 . V_19 = V_3 ;
V_17 = F_11 ( & V_16 , V_15 , V_5 ) ;
if ( V_17 )
return V_16 . V_19 ;
return NULL ;
}
void F_12 ( T_2 * V_3 )
{
T_5 V_16 ;
if ( V_2 == NULL )
V_2 = F_10 () ;
V_2 -> V_18 ( & V_16 ) ;
V_16 . V_19 = V_3 ;
F_13 ( & V_16 ) ;
}
int F_14 ( T_2 * V_3 , T_4 * V_20 )
{
T_3 * V_11 ;
int V_17 ;
if( ! ( V_11 = F_9 ( V_20 , V_12 ) ) ) {
F_5 ( V_21 , V_14 ) ;
return 0 ;
}
V_17 = F_15 ( V_3 , V_11 ) ;
F_7 ( V_11 ) ;
return V_17 ;
}
int F_15 ( T_2 * V_3 , T_3 * V_20 )
{
T_5 V_16 ;
if ( V_2 == NULL )
V_2 = F_10 () ;
V_2 -> V_18 ( & V_16 ) ;
V_16 . V_19 = V_3 ;
return F_16 ( & V_16 , V_20 ) ;
}
T_5 * F_17 ( T_1 * V_1 )
{
T_5 * V_17 ;
if ( V_1 == NULL )
V_1 = F_10 () ;
V_17 = V_1 -> V_22 ( V_1 ) ;
if ( V_17 == NULL )
{
F_5 ( V_23 , V_24 ) ;
return ( NULL ) ;
}
return V_17 ;
}
void F_18 ( T_5 * V_3 )
{
if ( V_3 == NULL )
return;
V_3 -> V_1 -> V_25 ( V_3 ) ;
}
void F_13 ( T_5 * V_3 )
{
if ( V_3 == NULL )
return;
V_3 -> V_1 -> V_26 ( V_3 ) ;
}
int F_19 ( T_5 * V_3 , const char * V_4 , long * V_5 )
{
int V_17 ;
T_3 * V_7 = NULL ;
#ifdef F_3
V_7 = F_4 ( V_4 , L_1 ) ;
#else
V_7 = F_4 ( V_4 , L_2 ) ;
#endif
if ( V_7 == NULL )
{
F_5 ( V_8 , V_9 ) ;
return 0 ;
}
V_17 = F_11 ( V_3 , V_7 , V_5 ) ;
F_7 ( V_7 ) ;
return V_17 ;
}
int F_20 ( T_5 * V_3 , T_4 * V_10 , long * V_5 )
{
T_3 * V_11 ;
int V_17 ;
if( ! ( V_11 = F_9 ( V_10 , V_12 ) ) )
{
F_5 ( V_13 , V_14 ) ;
return 0 ;
}
V_17 = F_11 ( V_3 , V_11 , V_5 ) ;
F_7 ( V_11 ) ;
return V_17 ;
}
int F_11 ( T_5 * V_3 , T_3 * V_15 , long * V_5 )
{
if ( V_3 == NULL )
{
F_5 ( V_27 , V_28 ) ;
return 0 ;
}
return V_3 -> V_1 -> V_29 ( V_3 , V_15 , V_5 ) ;
}
int F_21 ( T_5 * V_3 , T_4 * V_20 )
{
T_3 * V_11 ;
int V_17 ;
if( ! ( V_11 = F_9 ( V_20 , V_12 ) ) ) {
F_5 ( V_30 , V_14 ) ;
return 0 ;
}
V_17 = F_16 ( V_3 , V_11 ) ;
F_7 ( V_11 ) ;
return V_17 ;
}
int F_16 ( T_5 * V_3 , T_3 * V_20 )
{
if ( V_3 == NULL )
{
F_5 ( V_31 , V_28 ) ;
return 0 ;
}
return V_3 -> V_1 -> V_32 ( V_3 , V_20 ) ;
}
