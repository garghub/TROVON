static int F_1 ( int V_1 , struct V_2 * * V_3 )
{
struct V_2 * V_4 ;
int V_5 ;
if ( ! V_6 [ V_1 ] )
F_2 ( V_7 L_1 ) ;
* V_3 = NULL ;
V_5 = F_3 ( V_8 [ V_1 ] , V_9 [ V_1 ] , V_10 , 0 , & V_4 ) ;
if ( V_5 < 0 )
return V_5 ;
strcpy ( V_4 -> V_11 , L_2 ) ;
strcpy ( V_4 -> V_12 , V_4 -> V_11 ) ;
sprintf ( V_4 -> V_13 , L_3 , V_4 -> V_12 , V_14 [ V_1 ] ) ;
if ( V_15 [ V_1 ] >= 0 ) {
sprintf ( V_4 -> V_13 + strlen ( V_4 -> V_13 ) , L_4 , V_15 [ V_1 ] ) ;
} else {
strcat ( V_4 -> V_13 , L_5 ) ;
}
V_5 = F_4 ( V_4 , 0 , V_16 , V_14 [ V_1 ] , 0 ,
V_15 [ V_1 ] , NULL ) ;
if ( V_5 < 0 ) {
F_5 ( V_7 L_6 , V_14 [ V_1 ] ) ;
goto V_17;
}
* V_3 = V_4 ;
return 0 ;
V_17:
F_6 ( V_4 ) ;
return V_5 ;
}
static int T_1 F_7 ( struct V_18 * V_19 )
{
int V_1 = V_19 -> V_9 ;
int V_5 ;
struct V_2 * V_4 ;
if ( V_14 [ V_1 ] == V_20 ) {
F_2 ( V_7 L_7 ) ;
return - V_21 ;
}
if ( V_15 [ V_1 ] == V_22 ) {
F_2 ( V_7 L_8 ) ;
return - V_21 ;
}
V_5 = F_1 ( V_1 , & V_4 ) ;
if ( V_5 < 0 )
return V_5 ;
F_8 ( V_4 , & V_19 -> V_1 ) ;
if ( ( V_5 = F_9 ( V_4 ) ) < 0 ) {
F_6 ( V_4 ) ;
return V_5 ;
}
F_10 ( V_19 , V_4 ) ;
return 0 ;
}
static int T_2 F_11 ( struct V_18 * V_19 )
{
F_6 ( F_12 ( V_19 ) ) ;
F_10 ( V_19 , NULL ) ;
return 0 ;
}
static int T_1 F_13 ( int V_1 , struct V_23 * V_24 ,
const struct V_25 * V_9 )
{
if ( ! F_14 ( V_24 , 0 ) ||
F_15 ( V_24 , 0 ) & V_26 ) {
F_2 ( V_7 L_9 ) ;
return - V_27 ;
}
if ( F_16 ( V_24 , 0 ) < V_28 ) {
F_2 ( V_7 L_10 ,
( unsigned long long ) F_16 ( V_24 , 0 ) ,
V_28 ) ;
return - V_27 ;
}
V_14 [ V_1 ] = F_17 ( V_24 , 0 ) ;
if ( ! F_18 ( V_24 , 0 ) ||
F_19 ( V_24 , 0 ) & V_26 ) {
F_2 ( V_29 L_11 ) ;
V_15 [ V_1 ] = - 1 ;
} else {
V_15 [ V_1 ] = F_20 ( V_24 , 0 ) ;
}
return 0 ;
}
static int T_1 F_21 ( struct V_23 * V_23 ,
const struct V_25 * V_9 )
{
static int V_1 ;
struct V_2 * V_4 ;
int V_5 ;
for ( ; V_1 < V_30 ; ++ V_1 ) {
if ( ! V_31 [ V_1 ] || ! V_32 [ V_1 ] )
continue;
V_5 = F_13 ( V_1 , V_23 , V_9 ) ;
if ( V_5 < 0 )
return V_5 ;
V_5 = F_1 ( V_1 , & V_4 ) ;
if ( V_5 < 0 )
return V_5 ;
if ( ( V_5 = F_9 ( V_4 ) ) < 0 ) {
F_6 ( V_4 ) ;
return V_5 ;
}
F_8 ( V_4 , & V_23 -> V_1 ) ;
F_22 ( V_23 , V_4 ) ;
V_33 ++ ;
++ V_1 ;
return 0 ;
}
return - V_27 ;
}
static void T_2 F_23 ( struct V_23 * V_1 )
{
struct V_2 * V_4 = (struct V_2 * ) F_24 ( V_1 ) ;
F_25 ( V_4 ) ;
F_26 ( V_4 ) ;
}
static void F_27 ( void )
{
int V_34 ;
if ( V_35 )
F_28 ( & V_36 ) ;
for ( V_34 = 0 ; V_34 < F_29 ( V_37 ) ; ++ V_34 )
F_30 ( V_37 [ V_34 ] ) ;
F_31 ( & V_38 ) ;
}
static int T_3 F_32 ( void )
{
int V_34 , V_5 ;
if ( ( V_5 = F_33 ( & V_38 ) ) < 0 )
return V_5 ;
for ( V_34 = 0 ; V_34 < V_30 ; V_34 ++ ) {
struct V_18 * V_24 ;
if ( ! V_31 [ V_34 ] )
continue;
#ifdef F_34
if ( V_32 [ V_34 ] )
continue;
#endif
V_24 = F_35 ( V_39 ,
V_34 , NULL , 0 ) ;
if ( F_36 ( V_24 ) )
continue;
if ( ! F_12 ( V_24 ) ) {
F_30 ( V_24 ) ;
continue;
}
V_37 [ V_34 ] = V_24 ;
V_33 ++ ;
}
V_5 = F_37 ( & V_36 ) ;
if ( ! V_5 )
V_35 = 1 ;
if ( ! V_33 ) {
#ifdef F_38
F_5 ( V_7 L_12 ) ;
#endif
F_27 () ;
return - V_27 ;
}
return 0 ;
}
static void T_4 F_39 ( void )
{
F_27 () ;
}
