int F_1 ( T_1 * V_1 , const T_1 * V_2 , const T_1 * V_3 , const T_1 * V_4 , const T_1 * V_5 , int V_6 )
{
int V_7 ( T_1 * V_1 , const T_1 * V_2 , const T_1 * V_3 , const T_1 * V_4 , const T_1 * V_5 , int V_6 ) ;
int V_8 ( T_1 * V_1 , const T_1 * V_2 , const T_1 * V_3 , const T_1 * V_4 , const T_1 * V_5 , int V_6 ) ;
if ( sizeof( V_9 ) == 4 )
{
#if ( F_2 ( V_10 ) && F_2 ( V_11 ) )
if ( V_6 >= 8 && ( V_6 & 3 ) == 0 && ( V_12 & V_13 ) )
return V_7 ( V_1 , V_2 , V_3 , V_4 , V_5 , V_6 ) ;
#else
if ( V_6 >= 32 && ( V_6 & 3 ) == 0 && ( V_12 & V_13 ) )
{
T_2 V_14 ;
int V_15 ;
F_3 ( V_16 , & V_17 , & V_14 ) ;
V_15 = V_7 ( V_1 , V_2 , V_3 , V_4 , V_5 , V_6 ) ;
F_3 ( V_16 , & V_14 , NULL ) ;
return V_15 ;
}
#endif
}
else if ( ( V_12 & V_13 ) )
return V_7 ( V_1 , V_2 , V_3 , V_4 , V_5 , V_6 ) ;
return V_8 ( V_1 , V_2 , V_3 , V_4 , V_5 , V_6 ) ;
}
static void F_4 ( int V_18 ) { F_5 ( V_19 , V_18 ) ; }
void F_6 ( void )
{
char * V_20 ;
struct V_21 V_22 , V_23 ;
T_2 V_14 ;
static int V_24 = 0 ;
if ( V_24 ) return;
V_24 = 1 ;
F_7 ( & V_17 ) ;
F_8 ( & V_17 , V_25 ) ;
F_8 ( & V_17 , V_26 ) ;
#ifdef F_9
F_8 ( & V_17 , F_9 ) ;
#endif
F_8 ( & V_17 , V_27 ) ;
F_8 ( & V_17 , V_28 ) ;
F_8 ( & V_17 , V_29 ) ;
if ( ( V_20 = getenv ( L_1 ) ) )
{
V_12 = strtoul ( V_20 , NULL , 0 ) ;
return;
}
V_12 = 0 ;
memset ( & V_23 , 0 , sizeof( V_23 ) ) ;
V_23 . V_30 = F_4 ;
V_23 . V_31 = V_17 ;
F_3 ( V_16 , & V_23 . V_31 , & V_14 ) ;
V_21 ( V_25 , & V_23 , & V_22 ) ;
if ( sizeof( V_9 ) == 4 )
{
if ( F_10 ( V_19 , 1 ) == 0 )
{
F_11 () ;
V_12 |= V_13 ;
}
}
else
{
}
if ( F_10 ( V_19 , 1 ) == 0 )
{
F_12 () ;
V_12 |= V_32 ;
}
V_21 ( V_25 , & V_22 , NULL ) ;
F_3 ( V_16 , & V_14 , NULL ) ;
}
