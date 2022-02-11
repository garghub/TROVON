static int F_1 ( struct V_1 * V_2 , int V_3 ,
struct V_4 * * V_5 )
{
struct V_4 * V_6 ;
int V_7 ;
if ( ! V_8 [ V_3 ] )
F_2 ( V_9 L_1 ) ;
* V_5 = NULL ;
V_7 = F_3 ( V_2 , V_10 [ V_3 ] , V_11 [ V_3 ] , V_12 ,
0 , & V_6 ) ;
if ( V_7 < 0 )
return V_7 ;
strcpy ( V_6 -> V_13 , L_2 ) ;
strcpy ( V_6 -> V_14 , V_6 -> V_13 ) ;
sprintf ( V_6 -> V_15 , L_3 , V_6 -> V_14 , V_16 [ V_3 ] ) ;
if ( V_17 [ V_3 ] >= 0 ) {
sprintf ( V_6 -> V_15 + strlen ( V_6 -> V_15 ) , L_4 , V_17 [ V_3 ] ) ;
} else {
strcat ( V_6 -> V_15 , L_5 ) ;
}
V_7 = F_4 ( V_6 , 0 , V_18 , V_16 [ V_3 ] , 0 ,
V_17 [ V_3 ] , NULL ) ;
if ( V_7 < 0 ) {
F_5 ( V_9 L_6 , V_16 [ V_3 ] ) ;
goto V_19;
}
* V_5 = V_6 ;
return 0 ;
V_19:
F_6 ( V_6 ) ;
return V_7 ;
}
static int F_7 ( struct V_20 * V_2 )
{
int V_3 = V_2 -> V_11 ;
int V_7 ;
struct V_4 * V_6 ;
if ( V_16 [ V_3 ] == V_21 ) {
F_2 ( V_9 L_7 ) ;
return - V_22 ;
}
if ( V_17 [ V_3 ] == V_23 ) {
F_2 ( V_9 L_8 ) ;
return - V_22 ;
}
V_7 = F_1 ( & V_2 -> V_3 , V_3 , & V_6 ) ;
if ( V_7 < 0 )
return V_7 ;
if ( ( V_7 = F_8 ( V_6 ) ) < 0 ) {
F_6 ( V_6 ) ;
return V_7 ;
}
F_9 ( V_2 , V_6 ) ;
return 0 ;
}
static int F_10 ( struct V_20 * V_2 )
{
F_6 ( F_11 ( V_2 ) ) ;
return 0 ;
}
static int F_12 ( int V_3 , struct V_24 * V_1 ,
const struct V_25 * V_11 )
{
if ( ! F_13 ( V_1 , 0 ) ||
F_14 ( V_1 , 0 ) & V_26 ) {
F_2 ( V_9 L_9 ) ;
return - V_27 ;
}
if ( F_15 ( V_1 , 0 ) < V_28 ) {
F_2 ( V_9 L_10 ,
( unsigned long long ) F_15 ( V_1 , 0 ) ,
V_28 ) ;
return - V_27 ;
}
V_16 [ V_3 ] = F_16 ( V_1 , 0 ) ;
if ( ! F_17 ( V_1 , 0 ) ||
F_18 ( V_1 , 0 ) & V_26 ) {
F_2 ( V_29 L_11 ) ;
V_17 [ V_3 ] = - 1 ;
} else {
V_17 [ V_3 ] = F_19 ( V_1 , 0 ) ;
}
return 0 ;
}
static int F_20 ( struct V_24 * V_24 ,
const struct V_25 * V_11 )
{
static int V_3 ;
struct V_4 * V_6 ;
int V_7 ;
for ( ; V_3 < V_30 ; ++ V_3 ) {
if ( ! V_31 [ V_3 ] || ! V_32 [ V_3 ] )
continue;
V_7 = F_12 ( V_3 , V_24 , V_11 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_1 ( & V_24 -> V_3 , V_3 , & V_6 ) ;
if ( V_7 < 0 )
return V_7 ;
if ( ( V_7 = F_8 ( V_6 ) ) < 0 ) {
F_6 ( V_6 ) ;
return V_7 ;
}
F_21 ( V_24 , V_6 ) ;
V_33 ++ ;
++ V_3 ;
return 0 ;
}
return - V_27 ;
}
static void F_22 ( struct V_24 * V_3 )
{
struct V_4 * V_6 = (struct V_4 * ) F_23 ( V_3 ) ;
F_24 ( V_6 ) ;
F_25 ( V_6 ) ;
}
static void F_26 ( void )
{
int V_34 ;
if ( V_35 )
F_27 ( & V_36 ) ;
for ( V_34 = 0 ; V_34 < F_28 ( V_37 ) ; ++ V_34 )
F_29 ( V_37 [ V_34 ] ) ;
F_30 ( & V_38 ) ;
}
static int T_1 F_31 ( void )
{
int V_34 , V_7 ;
if ( ( V_7 = F_32 ( & V_38 ) ) < 0 )
return V_7 ;
for ( V_34 = 0 ; V_34 < V_30 ; V_34 ++ ) {
struct V_20 * V_1 ;
if ( ! V_31 [ V_34 ] )
continue;
#ifdef F_33
if ( V_32 [ V_34 ] )
continue;
#endif
V_1 = F_34 ( V_39 ,
V_34 , NULL , 0 ) ;
if ( F_35 ( V_1 ) )
continue;
if ( ! F_11 ( V_1 ) ) {
F_29 ( V_1 ) ;
continue;
}
V_37 [ V_34 ] = V_1 ;
V_33 ++ ;
}
V_7 = F_36 ( & V_36 ) ;
if ( ! V_7 )
V_35 = 1 ;
if ( ! V_33 ) {
#ifdef F_37
F_5 ( V_9 L_12 ) ;
#endif
F_26 () ;
return - V_27 ;
}
return 0 ;
}
static void T_2 F_38 ( void )
{
F_26 () ;
}
