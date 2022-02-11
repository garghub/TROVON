static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
struct V_5 * V_6 ;
int V_7 , V_8 ;
int V_9 = V_2 -> V_10 ;
V_8 = F_2 ( V_11 [ V_9 ] , V_10 [ V_9 ] , V_12 ,
sizeof( struct V_5 ) , & V_4 ) ;
if ( V_8 < 0 )
return V_8 ;
V_6 = V_4 -> V_13 ;
V_6 -> V_4 = V_4 ;
if ( V_14 [ V_9 ] > V_15 ) {
F_3 ( V_16
L_1
L_2 , V_9 , V_15 ) ;
V_14 [ V_9 ] = V_15 ;
}
for ( V_7 = 0 ; V_7 < V_14 [ V_9 ] ; V_7 ++ ) {
struct V_17 * V_18 ;
struct V_19 * V_20 ;
if ( ( V_8 = F_4 ( V_4 , V_7 , & V_18 ) ) < 0 )
goto V_21;
V_20 = V_18 -> V_13 ;
V_6 -> V_22 [ V_7 ] = V_18 ;
strcpy ( V_18 -> V_23 , L_3 ) ;
V_20 -> V_24 = V_25 ;
}
strcpy ( V_4 -> V_26 , L_4 ) ;
strcpy ( V_4 -> V_27 , L_4 ) ;
sprintf ( V_4 -> V_28 , L_5 , V_9 + 1 ) ;
F_5 ( V_4 , & V_2 -> V_9 ) ;
if ( ( V_8 = F_6 ( V_4 ) ) == 0 ) {
F_7 ( V_2 , V_4 ) ;
return 0 ;
}
V_21:
F_8 ( V_4 ) ;
return V_8 ;
}
static int F_9 ( struct V_1 * V_2 )
{
F_8 ( F_10 ( V_2 ) ) ;
F_7 ( V_2 , NULL ) ;
return 0 ;
}
static void F_11 ( void )
{
int V_29 ;
for ( V_29 = 0 ; V_29 < F_12 ( V_30 ) ; ++ V_29 )
F_13 ( V_30 [ V_29 ] ) ;
F_14 ( & V_31 ) ;
}
static int T_1 F_15 ( void )
{
int V_29 , V_32 , V_8 ;
if ( ( V_8 = F_16 ( & V_31 ) ) < 0 )
return V_8 ;
V_32 = 0 ;
for ( V_29 = 0 ; V_29 < V_33 ; V_29 ++ ) {
struct V_1 * V_34 ;
if ( ! V_35 [ V_29 ] )
continue;
V_34 = F_17 ( V_36 ,
V_29 , NULL , 0 ) ;
if ( F_18 ( V_34 ) )
continue;
if ( ! F_10 ( V_34 ) ) {
F_13 ( V_34 ) ;
continue;
}
V_30 [ V_29 ] = V_34 ;
V_32 ++ ;
}
if ( ! V_32 ) {
#ifdef F_19
F_20 ( V_37 L_6 ) ;
#endif
F_11 () ;
return - V_38 ;
}
return 0 ;
}
static void T_2 F_21 ( void )
{
F_11 () ;
}
