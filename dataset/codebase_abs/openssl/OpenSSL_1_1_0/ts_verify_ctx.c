T_1 * F_1 ( void )
{
T_1 * V_1 = F_2 ( sizeof( * V_1 ) ) ;
if ( V_1 == NULL )
F_3 ( V_2 , V_3 ) ;
return V_1 ;
}
void F_4 ( T_1 * V_1 )
{
F_5 ( V_1 != NULL ) ;
memset ( V_1 , 0 , sizeof( * V_1 ) ) ;
}
void F_6 ( T_1 * V_1 )
{
if ( ! V_1 )
return;
F_7 ( V_1 ) ;
F_8 ( V_1 ) ;
}
int F_9 ( T_1 * V_1 , int V_4 )
{
V_1 -> V_5 |= V_4 ;
return V_1 -> V_5 ;
}
int F_10 ( T_1 * V_1 , int V_4 )
{
V_1 -> V_5 = V_4 ;
return V_1 -> V_5 ;
}
T_2 * F_11 ( T_1 * V_1 , T_2 * V_6 )
{
V_1 -> V_7 = V_6 ;
return V_1 -> V_7 ;
}
T_3 * F_12 ( T_1 * V_1 , T_3 * V_8 )
{
V_1 -> V_9 = V_8 ;
return V_1 -> V_9 ;
}
unsigned char * F_13 ( T_1 * V_1 ,
unsigned char * V_10 , long V_11 )
{
V_1 -> V_12 = V_10 ;
V_1 -> V_13 = V_11 ;
return V_1 -> V_12 ;
}
void F_7 ( T_1 * V_1 )
{
if ( ! V_1 )
return;
F_14 ( V_1 -> V_9 ) ;
F_15 ( V_1 -> V_14 , V_15 ) ;
F_16 ( V_1 -> V_16 ) ;
F_17 ( V_1 -> V_17 ) ;
F_8 ( V_1 -> V_12 ) ;
F_18 ( V_1 -> V_7 ) ;
F_19 ( V_1 -> V_18 ) ;
F_20 ( V_1 -> V_19 ) ;
F_4 ( V_1 ) ;
}
T_1 * F_21 ( T_4 * V_20 , T_1 * V_1 )
{
T_1 * V_21 = V_1 ;
T_5 * V_16 ;
T_6 * V_12 ;
T_7 * V_17 ;
T_8 * V_22 ;
const T_9 * V_18 ;
F_5 ( V_20 != NULL ) ;
if ( V_21 )
F_7 ( V_21 ) ;
else if ( ( V_21 = F_1 () ) == NULL )
return NULL ;
V_21 -> V_5 = V_23 & ~ ( V_24 | V_25 ) ;
if ( ( V_16 = V_20 -> V_26 ) != NULL ) {
if ( ( V_21 -> V_16 = F_22 ( V_16 ) ) == NULL )
goto V_27;
} else
V_21 -> V_5 &= ~ V_28 ;
V_12 = V_20 -> V_29 ;
V_17 = V_12 -> V_30 ;
if ( ( V_21 -> V_17 = F_23 ( V_17 ) ) == NULL )
goto V_27;
V_22 = V_12 -> V_31 ;
V_21 -> V_13 = F_24 ( V_22 ) ;
if ( ( V_21 -> V_12 = F_25 ( V_21 -> V_13 ) ) == NULL )
goto V_27;
memcpy ( V_21 -> V_12 , F_26 ( V_22 ) , V_21 -> V_13 ) ;
if ( ( V_18 = V_20 -> V_18 ) != NULL ) {
if ( ( V_21 -> V_18 = F_27 ( V_18 ) ) == NULL )
goto V_27;
} else
V_21 -> V_5 &= ~ V_32 ;
return V_21 ;
V_27:
if ( V_1 )
F_7 ( V_1 ) ;
else
F_6 ( V_21 ) ;
return NULL ;
}
