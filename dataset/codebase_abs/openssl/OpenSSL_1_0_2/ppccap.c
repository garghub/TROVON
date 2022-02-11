int F_1 ( T_1 * V_1 , const T_1 * V_2 , const T_1 * V_3 ,
const T_1 * V_4 , const T_1 * V_5 , int V_6 )
{
int V_7 ( T_1 * V_1 , const T_1 * V_2 ,
const T_1 * V_3 , const T_1 * V_4 ,
const T_1 * V_5 , int V_6 ) ;
int V_8 ( T_1 * V_1 , const T_1 * V_2 , const T_1 * V_3 ,
const T_1 * V_4 , const T_1 * V_5 , int V_6 ) ;
if ( sizeof( V_9 ) == 4 ) {
# if 1 || ( F_2 ( V_10 ) && F_2 ( V_11 ) )
if ( V_6 >= 8 && ( V_6 & 3 ) == 0 && ( V_12 & V_13 ) )
return V_7 ( V_1 , V_2 , V_3 , V_4 , V_5 , V_6 ) ;
# else
if ( V_6 >= 32 && ( V_6 & 3 ) == 0 && ( V_12 & V_13 ) ) {
T_2 V_14 ;
int V_15 ;
F_3 ( V_16 , & V_17 , & V_14 ) ;
V_15 = V_7 ( V_1 , V_2 , V_3 , V_4 , V_5 , V_6 ) ;
F_3 ( V_16 , & V_14 , NULL ) ;
return V_15 ;
}
# endif
} else if ( ( V_12 & V_13 ) )
return V_7 ( V_1 , V_2 , V_3 , V_4 , V_5 , V_6 ) ;
return V_8 ( V_1 , V_2 , V_3 , V_4 , V_5 , V_6 ) ;
}
void F_4 ( void * V_18 , const void * V_19 , V_9 V_20 )
{
V_12 & V_21 ? F_5 ( V_18 , V_19 , V_20 ) :
F_6 ( V_18 , V_19 , V_20 ) ;
}
void F_7 ( void * V_18 , const void * V_19 , V_9 V_20 )
{
V_12 & V_21 ? F_8 ( V_18 , V_19 , V_20 ) :
F_9 ( V_18 , V_19 , V_20 ) ;
}
static void F_10 ( int V_22 )
{
F_11 ( V_23 , V_22 ) ;
}
void F_12 ( void )
{
char * V_24 ;
struct V_25 V_26 , V_27 ;
T_2 V_14 ;
static int V_28 = 0 ;
if ( V_28 )
return;
V_28 = 1 ;
F_13 ( & V_17 ) ;
F_14 ( & V_17 , V_29 ) ;
F_14 ( & V_17 , V_30 ) ;
#ifdef F_15
F_14 ( & V_17 , F_15 ) ;
#endif
F_14 ( & V_17 , V_31 ) ;
F_14 ( & V_17 , V_32 ) ;
F_14 ( & V_17 , V_33 ) ;
if ( ( V_24 = getenv ( L_1 ) ) ) {
V_12 = strtoul ( V_24 , NULL , 0 ) ;
return;
}
V_12 = 0 ;
#if F_2 ( V_34 )
if ( sizeof( V_9 ) == 4 ) {
struct V_35 V_36 ;
# if F_2 ( V_37 )
if ( F_16 ( V_37 ) != 64 )
return;
# endif
if ( F_17 ( & V_36 ) != 0 || atoi ( V_36 . V_38 ) < 6 )
return;
}
#endif
memset ( & V_27 , 0 , sizeof( V_27 ) ) ;
V_27 . V_39 = F_10 ;
V_27 . V_40 = V_17 ;
F_3 ( V_16 , & V_27 . V_40 , & V_14 ) ;
V_25 ( V_29 , & V_27 , & V_26 ) ;
if ( sizeof( V_9 ) == 4 ) {
#ifdef F_18
struct V_35 V_36 ;
if ( F_17 ( & V_36 ) == 0 && strcmp ( V_36 . V_41 , L_2 ) == 0 )
#endif
if ( F_19 ( V_23 , 1 ) == 0 ) {
F_20 () ;
V_12 |= V_13 ;
}
} else {
}
if ( F_19 ( V_23 , 1 ) == 0 ) {
F_21 () ;
V_12 |= V_42 ;
if ( F_19 ( V_23 , 1 ) == 0 ) {
F_22 () ;
V_12 |= V_21 ;
}
}
V_25 ( V_29 , & V_26 , NULL ) ;
F_3 ( V_16 , & V_14 , NULL ) ;
}
