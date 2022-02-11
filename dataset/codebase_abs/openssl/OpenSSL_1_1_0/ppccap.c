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
void F_10 ( unsigned char * V_22 , const unsigned char * V_19 ,
V_9 V_20 , const unsigned int V_23 [ 8 ] ,
const unsigned int V_24 [ 4 ] )
{
V_12 & V_25
? F_11 ( V_22 , V_19 , V_20 , V_23 , V_24 )
: F_12 ( V_22 , V_19 , V_20 , V_23 , V_24 ) ;
}
int F_13 ( void * V_18 , const unsigned char V_23 [ 16 ] , void * V_26 [ 2 ] )
{
if ( sizeof( V_9 ) == 4 && ( V_12 & V_27 ) ) {
F_14 ( V_18 , V_23 ) ;
V_26 [ 0 ] = V_28 ;
V_26 [ 1 ] = V_29 ;
} else {
F_15 ( V_18 , V_23 ) ;
V_26 [ 0 ] = V_30 ;
V_26 [ 1 ] = V_31 ;
}
return 1 ;
}
static void F_16 ( int V_32 )
{
F_17 ( V_33 , V_32 ) ;
}
void F_18 ( void )
{
char * V_34 ;
struct V_35 V_36 , V_37 ;
T_2 V_14 ;
static int V_38 = 0 ;
if ( V_38 )
return;
V_38 = 1 ;
if ( ( V_34 = getenv ( L_1 ) ) ) {
V_12 = strtoul ( V_34 , NULL , 0 ) ;
return;
}
V_12 = 0 ;
#if F_2 ( V_39 )
V_12 |= V_27 ;
if ( sizeof( V_9 ) == 4 ) {
struct V_40 V_41 ;
# if F_2 ( V_42 )
if ( F_19 ( V_42 ) != 64 )
return;
# endif
if ( F_20 ( & V_41 ) != 0 || atoi ( V_41 . V_43 ) < 6 )
return;
}
# if F_2 ( V_44 )
if ( sizeof( V_9 ) == 4 ) {
if ( V_44 ( 0xffffffffU << 13 ) )
V_12 |= V_13 ;
} else {
if ( V_44 ( 0x1U << 14 ) )
V_12 |= V_13 ;
}
if ( V_44 ( 0xffffffffU << 14 ) )
V_12 |= V_25 ;
if ( V_44 ( 0xffffffffU << 16 ) )
V_12 |= V_21 ;
if ( V_44 ( 0xffffffffU << 17 ) )
V_12 |= V_45 ;
return;
# endif
#endif
if ( V_46 != NULL ) {
unsigned long V_47 = V_46 ( V_48 ) ;
if ( V_47 & V_49 ) {
V_12 |= V_27 ;
if ( sizeof( V_9 ) == 4 ) {
if ( V_47 & V_50 )
V_12 |= V_13 ;
} else {
if ( V_47 & V_51 )
V_12 |= V_13 ;
}
}
if ( V_47 & V_52 ) {
V_12 |= V_25 ;
if ( ( V_47 & V_53 ) && ( V_46 ( V_54 ) & V_55 ) )
V_12 |= V_21 ;
}
if ( V_47 & V_56 ) {
V_12 |= V_45 ;
}
return;
}
F_21 ( & V_17 ) ;
F_22 ( & V_17 , V_57 ) ;
F_22 ( & V_17 , V_58 ) ;
#ifdef F_23
F_22 ( & V_17 , F_23 ) ;
#endif
F_22 ( & V_17 , V_59 ) ;
F_22 ( & V_17 , V_60 ) ;
F_22 ( & V_17 , V_61 ) ;
memset ( & V_37 , 0 , sizeof( V_37 ) ) ;
V_37 . V_62 = F_16 ;
V_37 . V_63 = V_17 ;
F_3 ( V_16 , & V_37 . V_63 , & V_14 ) ;
V_35 ( V_57 , & V_37 , & V_36 ) ;
if ( F_24 ( V_33 , 1 ) == 0 ) {
F_25 () ;
V_12 |= V_27 ;
if ( sizeof( V_9 ) == 4 ) {
#ifdef F_26
struct V_40 V_41 ;
if ( F_20 ( & V_41 ) == 0 && strcmp ( V_41 . V_64 , L_2 ) == 0 )
#endif
if ( F_24 ( V_33 , 1 ) == 0 ) {
F_27 () ;
V_12 |= V_13 ;
}
} else {
}
}
if ( F_24 ( V_33 , 1 ) == 0 ) {
F_28 () ;
V_12 |= V_25 ;
if ( F_24 ( V_33 , 1 ) == 0 ) {
F_29 () ;
V_12 |= V_21 ;
}
}
if ( F_24 ( V_33 , 1 ) == 0 ) {
F_30 () ;
V_12 |= V_45 ;
}
V_35 ( V_57 , & V_36 , NULL ) ;
F_3 ( V_16 , & V_14 , NULL ) ;
}
