int F_1 ( T_1 * V_1 , const T_1 * V_2 , const T_1 * V_3 , const T_1 * V_4 , const T_1 * V_5 , int V_6 )
{
int V_7 ( T_1 * V_1 , const T_1 * V_2 , const T_1 * V_3 , const T_1 * V_4 , const T_1 * V_5 , int V_6 ) ;
int V_8 ( T_1 * V_1 , const T_1 * V_2 , const T_1 * V_3 , const T_1 * V_4 , const T_1 * V_5 , int V_6 ) ;
if ( ( V_9 & ( V_10 | V_11 ) ) ==
( V_10 | V_11 ) )
return V_7 ( V_1 , V_2 , V_3 , V_4 , V_5 , V_6 ) ;
else
return V_8 ( V_1 , V_2 , V_3 , V_4 , V_5 , V_6 ) ;
}
unsigned long F_2 ( void )
{
unsigned long V_12 ( void ) ;
if ( V_9 & V_13 )
#if F_3 ( V_14 ) && F_3 ( V_15 )
return F_4 () ;
#else
return 0 ;
#endif
else
return V_12 () ;
}
static int F_5 ( T_2 V_16 , T_3 V_17 )
{
char * V_18 = (* V_17)( V_16 ) ;
if ( ! strcmp ( V_18 , L_1 ) ||
! strncmp ( V_18 , L_2 , 17 ) )
{
V_9 |= V_10 | V_11 ;
if ( V_18 [ 14 ] != '\0' && V_18 [ 17 ] != '\0' && V_18 [ 18 ] != '\0' )
V_9 &= ~ V_13 ;
return V_19 ;
}
else if ( ! strncmp ( V_18 , L_1 , 15 ) )
{
V_9 &= ~ V_13 ;
return V_19 ;
}
return V_20 ;
}
void F_6 ( void )
{
void * V_21 ;
char * V_22 , V_23 [ 256 ] ;
static int V_24 = 0 ;
if ( V_24 ) return;
V_24 = 1 ;
if ( ( V_22 = getenv ( L_3 ) ) )
{
V_9 = strtoul ( V_22 , NULL , 0 ) ;
return;
}
if ( F_7 ( V_25 , V_23 , sizeof( V_23 ) ) > 0 )
{
if ( strcmp ( V_23 , L_4 ) )
V_9 |= V_10 ;
}
if ( F_7 ( V_26 , V_23 , sizeof( V_23 ) ) > 0 )
{
if ( strstr ( V_23 , L_5 ) )
V_9 |= V_11 ;
if ( strstr ( V_23 , L_6 ) )
{
V_9 |= V_27 ;
V_9 &= ~ V_13 ;
return;
}
}
if ( ( V_21 = F_8 ( L_7 , V_28 ) ) ) do
{
T_4 V_29 ;
T_5 V_30 ;
T_6 V_31 ;
T_3 V_17 ;
T_2 V_32 ;
if ( ! F_9 ( V_21 , V_29 ) ) break;
if ( ! F_9 ( V_21 , V_30 ) ) break;
if ( ! F_9 ( V_21 , V_31 ) ) break;
if ( ! F_9 ( V_21 , V_17 ) ) break;
if ( ( V_32 = (* V_29)( L_8 , V_33 ) ) != V_34 )
{
(* V_31)( V_32 , V_35 ,
V_17 , F_5 ) ;
(* V_30)( V_32 ) ;
}
} while( 0 );
if ( V_21 ) F_10 ( V_21 ) ;
}
void F_6 ( void )
{
char * V_22 ;
if ( ( V_22 = getenv ( L_3 ) ) )
{
V_9 = strtoul ( V_22 , NULL , 0 ) ;
return;
}
V_9 |= V_10 | V_11 ;
}
