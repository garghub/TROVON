int F_1 ( T_1 * V_1 , const T_1 * V_2 , const T_1 * V_3 , const T_1 * V_4 , const T_1 * V_5 , int V_6 )
{
int V_7 ( T_1 * V_1 , const T_1 * V_2 , const T_1 * V_3 , const T_1 * V_4 , const T_1 * V_5 , int V_6 ) ;
int V_8 ( T_1 * V_1 , const T_1 * V_2 , const T_1 * V_3 , const T_1 * V_4 , const T_1 * V_5 , int V_6 ) ;
if ( V_6 >= 8 && ! ( V_6 & 1 ) &&
( V_9 & ( V_10 | V_11 ) ) ==
( V_10 | V_11 ) )
return V_7 ( V_1 , V_2 , V_3 , V_4 , V_5 , V_6 ) ;
else
return V_8 ( V_1 , V_2 , V_3 , V_4 , V_5 , V_6 ) ;
}
unsigned long F_2 ( void )
{
if ( V_9 & V_12 )
#if F_3 ( V_13 ) && F_3 ( V_14 )
return F_4 () ;
#else
return 0 ;
#endif
else
return F_5 () ;
}
static void F_6 ( int V_15 ) { F_7 ( V_16 , V_15 ) ; }
void F_8 ( void )
{
char * V_17 ;
struct V_18 V_19 , V_20 , V_21 ;
T_2 V_22 , V_23 ;
static int V_24 = 0 ;
if ( V_24 ) return;
V_24 = 1 ;
if ( ( V_17 = getenv ( L_1 ) ) )
{
V_9 = strtoul ( V_17 , NULL , 0 ) ;
return;
}
V_9 = V_10 | V_12 ;
F_9 ( & V_22 ) ;
F_10 ( & V_22 , V_25 ) ;
F_10 ( & V_22 , V_26 ) ;
#ifdef F_11
F_10 ( & V_22 , F_11 ) ;
#endif
F_10 ( & V_22 , V_27 ) ;
F_10 ( & V_22 , V_28 ) ;
F_10 ( & V_22 , V_29 ) ;
F_12 ( V_30 , & V_22 , & V_23 ) ;
memset ( & V_19 , 0 , sizeof( V_19 ) ) ;
V_19 . V_31 = F_6 ;
V_19 . V_32 = V_22 ;
V_18 ( V_25 , & V_19 , & V_20 ) ;
V_18 ( V_28 , & V_19 , & V_21 ) ;
if ( F_13 ( V_16 , 1 ) == 0 )
{
F_5 () ;
V_9 &= ~ V_12 ;
}
if ( F_13 ( V_16 , 1 ) == 0 )
{
F_14 () ;
V_9 |= V_11 ;
if ( F_15 () >= 12 )
V_9 &= ~ ( V_11 | V_10 ) ;
else
{
F_16 () ;
V_9 |= V_33 ;
}
}
if ( F_13 ( V_16 , 1 ) == 0 )
{
F_17 () ;
V_9 |= V_34 ;
}
V_18 ( V_28 , & V_21 , NULL ) ;
V_18 ( V_25 , & V_20 , NULL ) ;
F_12 ( V_30 , & V_23 , NULL ) ;
}
