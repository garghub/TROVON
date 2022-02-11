static void F_1 ( void )
{
T_1 V_1 ;
T_1 V_2 ;
static const char * const V_3 [] = { L_1 , L_2 , L_3 } ;
int V_4 ;
bool V_5 = false ;
union V_6 V_7 ;
struct V_8 * V_9 ;
int V_10 ;
if ( V_11 == NULL ) {
F_2 ( L_4 , V_12 ) ;
return;
}
for ( V_4 = 0 ; V_4 < F_3 ( V_3 ) ; V_4 ++ ) {
V_9 = F_4 ( V_3 [ V_4 ] ) ;
if ( ! V_9 )
continue;
V_10 = F_5 ( V_9 , V_13 ,
& V_7 ) ;
F_6 ( V_9 ) ;
if ( ! V_10 && V_7 . V_14 ) {
V_5 = true ;
break;
}
}
if ( ! V_5 )
goto V_15;
V_9 = F_4 ( L_5 ) ;
if ( V_9 ) {
V_10 = F_5 ( V_9 ,
V_16 , & V_7 ) ;
if ( ! V_10 && V_7 . V_14 != V_17 ) {
F_7 ( L_6 ,
V_3 [ V_4 ] ) ;
F_7 ( L_7 ) ;
F_8 ( L_8 ) ;
}
F_6 ( V_9 ) ;
}
V_15:
F_9 ( & V_2 ) ;
if ( ! F_10 ( V_18 , & V_2 , & V_1 ) ) {
( void ) F_11 ( V_19 ,
V_20 |
V_21 ) ;
( void ) F_10 ( V_22 , & V_1 , NULL ) ;
}
}
static inline bool F_12 ( T_2 V_23 )
{
return ( ( V_23 == V_24 ) ||
( V_23 == V_25 ) ) ;
}
int F_13 ( T_3 V_26 , T_2 * V_27 )
{
T_2 V_23 ;
if ( V_11 == NULL )
return - V_28 ;
V_23 = ( V_26 >> 8 ) ;
if ( ! F_12 ( V_23 ) )
return - V_28 ;
return F_14 ( V_11 , V_23 ,
( T_2 ) ( V_26 & 0xFF ) , V_27 ) ;
}
int F_15 ( T_3 V_26 , T_2 V_29 , T_2 V_27 )
{
T_2 V_23 ;
if ( V_11 == NULL )
return - V_28 ;
V_23 = ( V_26 >> 8 ) ;
if ( ! F_12 ( V_23 ) )
return - V_28 ;
return F_16 ( V_11 , V_23 ,
( T_2 ) ( V_26 & 0xFF ) , V_29 , V_27 ) ;
}
static int F_17 ( struct V_30 * V_31 )
{
V_11 = & V_31 -> V_32 ;
if ( ! V_33 )
V_33 = F_1 ;
return 0 ;
}
static int F_18 ( struct V_30 * V_31 )
{
V_11 = NULL ;
if ( V_33 == F_1 )
V_33 = NULL ;
return 0 ;
}
static int T_4 F_19 ( void )
{
return F_20 ( & V_34 ) ;
}
