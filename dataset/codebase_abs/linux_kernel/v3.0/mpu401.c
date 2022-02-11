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
V_15 [ V_1 ] , V_15 [ V_1 ] >= 0 ? V_17 : 0 ,
NULL ) ;
if ( V_5 < 0 ) {
F_5 ( V_7 L_6 , V_14 [ V_1 ] ) ;
goto V_18;
}
* V_3 = V_4 ;
return 0 ;
V_18:
F_6 ( V_4 ) ;
return V_5 ;
}
static int T_1 F_7 ( struct V_19 * V_20 )
{
int V_1 = V_20 -> V_9 ;
int V_5 ;
struct V_2 * V_4 ;
if ( V_14 [ V_1 ] == V_21 ) {
F_2 ( V_7 L_7 ) ;
return - V_22 ;
}
if ( V_15 [ V_1 ] == V_23 ) {
F_2 ( V_7 L_8 ) ;
return - V_22 ;
}
V_5 = F_1 ( V_1 , & V_4 ) ;
if ( V_5 < 0 )
return V_5 ;
F_8 ( V_4 , & V_20 -> V_1 ) ;
if ( ( V_5 = F_9 ( V_4 ) ) < 0 ) {
F_6 ( V_4 ) ;
return V_5 ;
}
F_10 ( V_20 , V_4 ) ;
return 0 ;
}
static int T_2 F_11 ( struct V_19 * V_20 )
{
F_6 ( F_12 ( V_20 ) ) ;
F_10 ( V_20 , NULL ) ;
return 0 ;
}
static int T_1 F_13 ( int V_1 , struct V_24 * V_25 ,
const struct V_26 * V_9 )
{
if ( ! F_14 ( V_25 , 0 ) ||
F_15 ( V_25 , 0 ) & V_27 ) {
F_2 ( V_7 L_9 ) ;
return - V_28 ;
}
if ( F_16 ( V_25 , 0 ) < V_29 ) {
F_2 ( V_7 L_10 ,
( unsigned long long ) F_16 ( V_25 , 0 ) ,
V_29 ) ;
return - V_28 ;
}
V_14 [ V_1 ] = F_17 ( V_25 , 0 ) ;
if ( ! F_18 ( V_25 , 0 ) ||
F_19 ( V_25 , 0 ) & V_27 ) {
F_2 ( V_30 L_11 ) ;
V_15 [ V_1 ] = - 1 ;
} else {
V_15 [ V_1 ] = F_20 ( V_25 , 0 ) ;
}
return 0 ;
}
static int T_1 F_21 ( struct V_24 * V_24 ,
const struct V_26 * V_9 )
{
static int V_1 ;
struct V_2 * V_4 ;
int V_5 ;
for ( ; V_1 < V_31 ; ++ V_1 ) {
if ( ! V_32 [ V_1 ] || ! V_33 [ V_1 ] )
continue;
V_5 = F_13 ( V_1 , V_24 , V_9 ) ;
if ( V_5 < 0 )
return V_5 ;
V_5 = F_1 ( V_1 , & V_4 ) ;
if ( V_5 < 0 )
return V_5 ;
if ( ( V_5 = F_9 ( V_4 ) ) < 0 ) {
F_6 ( V_4 ) ;
return V_5 ;
}
F_8 ( V_4 , & V_24 -> V_1 ) ;
F_22 ( V_24 , V_4 ) ;
V_34 ++ ;
++ V_1 ;
return 0 ;
}
return - V_28 ;
}
static void T_2 F_23 ( struct V_24 * V_1 )
{
struct V_2 * V_4 = (struct V_2 * ) F_24 ( V_1 ) ;
F_25 ( V_4 ) ;
F_26 ( V_4 ) ;
}
static void F_27 ( void )
{
int V_35 ;
if ( V_36 )
F_28 ( & V_37 ) ;
for ( V_35 = 0 ; V_35 < F_29 ( V_38 ) ; ++ V_35 )
F_30 ( V_38 [ V_35 ] ) ;
F_31 ( & V_39 ) ;
}
static int T_3 F_32 ( void )
{
int V_35 , V_5 ;
if ( ( V_5 = F_33 ( & V_39 ) ) < 0 )
return V_5 ;
for ( V_35 = 0 ; V_35 < V_31 ; V_35 ++ ) {
struct V_19 * V_25 ;
if ( ! V_32 [ V_35 ] )
continue;
#ifdef F_34
if ( V_33 [ V_35 ] )
continue;
#endif
V_25 = F_35 ( V_40 ,
V_35 , NULL , 0 ) ;
if ( F_36 ( V_25 ) )
continue;
if ( ! F_12 ( V_25 ) ) {
F_30 ( V_25 ) ;
continue;
}
V_38 [ V_35 ] = V_25 ;
V_34 ++ ;
}
V_5 = F_37 ( & V_37 ) ;
if ( ! V_5 )
V_36 = 1 ;
if ( ! V_34 ) {
#ifdef F_38
F_5 ( V_7 L_12 ) ;
#endif
F_27 () ;
return - V_28 ;
}
return 0 ;
}
static void T_4 F_39 ( void )
{
F_27 () ;
}
