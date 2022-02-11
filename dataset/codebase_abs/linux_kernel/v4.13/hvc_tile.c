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
return F_5 ( ( V_10 ) V_3 , V_4 ) ? : - V_11 ;
}
}
static int F_6 ( T_2 V_12 , const char * V_3 , int V_4 )
{
return F_2 ( V_3 , V_4 ) ;
}
static int F_7 ( T_2 V_12 , char * V_3 , int V_4 )
{
int V_5 , V_13 ;
for ( V_5 = 0 ; V_5 < V_4 ; ++ V_5 ) {
V_13 = F_8 () ;
if ( V_13 < 0 )
break;
V_3 [ V_5 ] = V_13 ;
}
return V_5 ;
}
static int F_9 ( struct V_14 * V_15 , int V_16 )
{
int V_17 ;
int V_18 = F_10 () ;
T_3 V_19 = { . V_20 = F_11 ( V_18 ) , . V_21 = F_12 (cpu) } ;
V_17 = F_13 ( V_15 , V_16 ) ;
if ( V_17 )
return V_17 ;
if ( F_14 ( V_22 , V_16 , V_19 ) < 0 )
F_15 ( V_15 , V_16 ) ;
return 0 ;
}
static void F_16 ( struct V_14 * V_15 , int V_16 )
{
T_3 V_19 = { 0 , 0 } ;
F_14 ( V_22 , - 1 , V_19 ) ;
F_15 ( V_15 , V_16 ) ;
}
static void F_17 ( struct V_14 * V_15 , int V_16 )
{
F_16 ( V_15 , V_16 ) ;
}
static int F_18 ( struct V_23 * V_24 )
{
struct V_14 * V_15 ;
int V_25 ;
V_25 = F_19 ( - 1 ) ;
if ( ! V_25 )
return - V_26 ;
F_20 ( V_25 , V_27 ) ;
V_15 = F_21 ( 0 , V_25 , & V_28 , 128 ) ;
if ( F_22 ( V_15 ) ) {
F_23 ( V_25 ) ;
return F_24 ( V_15 ) ;
}
F_25 ( & V_24 -> V_29 , V_15 ) ;
return 0 ;
}
static int F_26 ( struct V_23 * V_24 )
{
int V_17 ;
struct V_14 * V_15 = F_27 ( & V_24 -> V_29 ) ;
V_17 = F_28 ( V_15 ) ;
if ( V_17 == 0 )
F_23 ( V_15 -> V_30 ) ;
return V_17 ;
}
static void F_29 ( struct V_23 * V_24 )
{
struct V_14 * V_15 = F_27 ( & V_24 -> V_29 ) ;
F_16 ( V_15 , V_15 -> V_30 ) ;
}
static int T_1 F_30 ( void )
{
F_31 ( 0 , 0 , & V_28 ) ;
F_32 ( L_1 , 0 , NULL ) ;
return 0 ;
}
static int T_1 F_33 ( void )
{
#ifndef F_34
struct V_14 * V_15 ;
V_15 = F_21 ( 0 , 0 , & V_28 , 128 ) ;
return F_35 ( V_15 ) ;
#else
F_36 ( & V_31 ) ;
return F_37 ( & V_32 ) ;
#endif
}
