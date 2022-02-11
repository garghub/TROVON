static int T_1 F_1 ( char * V_1 )
{
V_2 = 1 ;
return 0 ;
}
int F_2 ( const char * V_3 , int V_4 )
{
if ( F_3 ( V_2 ) ) {
int V_5 ;
for ( V_5 = 0 ; V_5 < V_4 ; ++ V_5 )
F_4 ( V_6 , V_7 |
( V_3 [ V_5 ] << V_8 ) ) ;
F_4 ( V_6 , V_7 |
( V_9 <<
V_8 ) ) ;
return 0 ;
} else {
return F_5 ( ( V_10 ) V_3 , V_4 ) ;
}
}
static int F_6 ( T_2 V_11 , const char * V_3 , int V_4 )
{
return F_2 ( V_3 , V_4 ) ;
}
static int F_7 ( T_2 V_11 , char * V_3 , int V_4 )
{
int V_5 , V_12 ;
for ( V_5 = 0 ; V_5 < V_4 ; ++ V_5 ) {
V_12 = F_8 () ;
if ( V_12 < 0 )
break;
V_3 [ V_5 ] = V_12 ;
}
return V_5 ;
}
static int F_9 ( struct V_13 * V_14 , int V_15 )
{
int V_16 ;
int V_17 = F_10 () ;
T_3 V_18 = { . V_19 = F_11 ( V_17 ) , . V_20 = F_12 (cpu) } ;
V_16 = F_13 ( V_14 , V_15 ) ;
if ( V_16 )
return V_16 ;
if ( F_14 ( V_21 , V_15 , V_18 ) < 0 )
F_15 ( V_14 , V_15 ) ;
return 0 ;
}
static void F_16 ( struct V_13 * V_14 , int V_15 )
{
T_3 V_18 = { 0 , 0 } ;
F_14 ( V_21 , - 1 , V_18 ) ;
F_15 ( V_14 , V_15 ) ;
}
static void F_17 ( struct V_13 * V_14 , int V_15 )
{
F_16 ( V_14 , V_15 ) ;
}
static int F_18 ( struct V_22 * V_23 )
{
struct V_13 * V_14 ;
int V_24 ;
V_24 = F_19 () ;
if ( V_24 < 0 )
return - V_25 ;
F_20 ( V_24 , V_26 ) ;
V_14 = F_21 ( 0 , V_24 , & V_27 , 128 ) ;
if ( F_22 ( V_14 ) ) {
F_23 ( V_24 ) ;
return F_24 ( V_14 ) ;
}
F_25 ( & V_23 -> V_28 , V_14 ) ;
return 0 ;
}
static int F_26 ( struct V_22 * V_23 )
{
int V_16 ;
struct V_13 * V_14 = F_27 ( & V_23 -> V_28 ) ;
V_16 = F_28 ( V_14 ) ;
if ( V_16 == 0 )
F_23 ( V_14 -> V_29 ) ;
return V_16 ;
}
static void F_29 ( struct V_22 * V_23 )
{
struct V_13 * V_14 = F_27 ( & V_23 -> V_28 ) ;
F_16 ( V_14 , V_14 -> V_29 ) ;
}
static int T_1 F_30 ( void )
{
F_31 ( 0 , 0 , & V_27 ) ;
F_32 ( L_1 , 0 , NULL ) ;
return 0 ;
}
static int T_1 F_33 ( void )
{
#ifndef F_34
struct V_13 * V_14 ;
V_14 = F_21 ( 0 , 0 , & V_27 , 128 ) ;
return F_22 ( V_14 ) ? F_24 ( V_14 ) : 0 ;
#else
F_35 ( & V_30 ) ;
return F_36 ( & V_31 ) ;
#endif
}
