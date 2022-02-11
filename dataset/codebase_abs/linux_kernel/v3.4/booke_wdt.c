static unsigned long long F_1 ( unsigned int V_1 )
{
unsigned long long V_2 = 1ULL << ( 64 - V_1 ) ;
unsigned long V_3 = V_4 ;
V_3 = V_3 / 5 * 2 ;
F_2 ( V_2 , V_3 ) ;
return V_2 ;
}
static unsigned int F_3 ( unsigned int V_5 )
{
unsigned int V_1 ;
for ( V_1 = 63 ; V_1 > 0 ; V_1 -- ) {
if ( F_1 ( V_1 ) >= V_5 )
return V_1 ;
}
return 0 ;
}
static void F_4 ( void * V_6 )
{
T_1 V_7 ;
V_7 = F_5 ( V_8 ) ;
V_7 &= ~ V_9 ;
V_7 |= F_6 ( V_10 ) ;
F_7 ( V_8 , V_7 ) ;
}
static void F_8 ( void )
{
F_9 ( F_4 , NULL , 0 ) ;
}
static void F_10 ( void * V_6 )
{
F_7 ( V_11 , V_12 | V_13 ) ;
}
static void F_11 ( void )
{
F_9 ( F_10 , NULL , 0 ) ;
}
static void F_12 ( void * V_6 )
{
T_1 V_7 ;
F_10 ( NULL ) ;
V_7 = F_5 ( V_8 ) ;
V_7 &= ~ V_9 ;
V_7 |= ( V_14 | F_13 ( V_15 ) | F_6 ( V_10 ) ) ;
F_7 ( V_8 , V_7 ) ;
}
static void F_14 ( void * V_6 )
{
T_1 V_7 ;
V_7 = F_5 ( V_8 ) ;
V_7 &= ~ ( V_14 | V_9 ) ;
F_7 ( V_8 , V_7 ) ;
F_10 ( NULL ) ;
}
static T_2 F_15 ( struct V_16 * V_16 , const char T_3 * V_17 ,
T_4 V_18 , T_5 * V_19 )
{
F_11 () ;
return V_18 ;
}
static long F_16 ( struct V_16 * V_16 ,
unsigned int V_20 , unsigned long V_21 )
{
T_1 V_2 = 0 ;
T_1 T_3 * V_22 = ( T_1 T_3 * ) V_21 ;
switch ( V_20 ) {
case V_23 :
if ( F_17 ( ( void * ) V_21 , & V_24 , sizeof( V_24 ) ) )
return - V_25 ;
case V_26 :
return F_18 ( 0 , V_22 ) ;
case V_27 :
V_2 = F_5 ( V_11 ) & F_19 ( 3 ) ;
return ( V_2 ? V_28 : 0 ) ;
case V_29 :
if ( F_20 ( V_2 , V_22 ) )
return - V_30 ;
if ( V_2 == V_31 ) {
F_11 () ;
break;
} else
return - V_30 ;
return 0 ;
case V_32 :
F_11 () ;
return 0 ;
case V_33 :
if ( F_20 ( V_2 , V_22 ) )
return - V_25 ;
#ifdef F_21
if ( V_2 > F_1 ( 1 ) )
return - V_30 ;
V_10 = F_3 ( V_2 ) ;
#else
V_10 = V_2 ;
#endif
F_8 () ;
case V_34 :
#ifdef F_21
return F_18 ( F_1 ( V_10 ) , V_22 ) ;
#else
return F_18 ( V_10 , V_22 ) ;
#endif
default:
return - V_35 ;
}
return 0 ;
}
static int F_22 ( struct V_36 * V_36 , struct V_16 * V_16 )
{
if ( F_23 ( 0 , & V_37 ) )
return - V_38 ;
F_24 ( & V_39 ) ;
if ( V_40 == 0 ) {
V_40 = 1 ;
F_9 ( F_12 , NULL , 0 ) ;
F_25 ( L_1 ,
F_1 ( V_10 ) ) ;
}
F_26 ( & V_39 ) ;
return F_27 ( V_36 , V_16 ) ;
}
static int F_28 ( struct V_36 * V_36 , struct V_16 * V_16 )
{
#ifndef F_29
F_9 ( F_14 , NULL , 0 ) ;
V_40 = 0 ;
F_25 ( L_2 ) ;
#endif
F_30 ( 0 , & V_37 ) ;
return 0 ;
}
static void T_6 F_31 ( void )
{
F_32 ( & V_41 ) ;
}
static int T_7 F_33 ( void )
{
int V_42 = 0 ;
F_34 ( L_3 ) ;
V_24 . V_43 = V_44 -> V_45 ;
V_42 = F_35 ( & V_41 ) ;
if ( V_42 ) {
F_36 ( L_4 ,
V_46 , V_42 ) ;
return V_42 ;
}
F_24 ( & V_39 ) ;
if ( V_40 == 1 ) {
F_34 ( L_1 ,
F_1 ( V_10 ) ) ;
F_9 ( F_12 , NULL , 0 ) ;
}
F_26 ( & V_39 ) ;
return V_42 ;
}
