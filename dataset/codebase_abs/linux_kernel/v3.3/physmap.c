static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
struct V_5 * V_6 ;
int V_7 ;
V_4 = F_2 ( V_2 ) ;
if ( V_4 == NULL )
return 0 ;
F_3 ( V_2 , NULL ) ;
V_6 = V_2 -> V_2 . V_8 ;
if ( V_4 -> V_9 ) {
F_4 ( V_4 -> V_9 ) ;
if ( V_4 -> V_9 != V_4 -> V_10 [ 0 ] )
F_5 ( V_4 -> V_9 ) ;
}
for ( V_7 = 0 ; V_7 < V_11 ; V_7 ++ ) {
if ( V_4 -> V_10 [ V_7 ] != NULL )
F_6 ( V_4 -> V_10 [ V_7 ] ) ;
}
if ( V_6 -> exit )
V_6 -> exit ( V_2 ) ;
return 0 ;
}
static void F_7 ( struct V_12 * V_13 , int V_14 )
{
struct V_1 * V_15 ;
struct V_5 * V_6 ;
V_15 = (struct V_1 * ) V_13 -> V_16 ;
V_6 = V_15 -> V_2 . V_8 ;
if ( V_6 -> V_17 )
V_6 -> V_17 ( V_15 , V_14 ) ;
}
static int F_8 ( struct V_1 * V_2 )
{
struct V_5 * V_6 ;
struct V_3 * V_4 ;
const char * * V_18 ;
const char * * V_19 ;
int V_20 = 0 ;
int V_7 ;
int V_21 = 0 ;
V_6 = V_2 -> V_2 . V_8 ;
if ( V_6 == NULL )
return - V_22 ;
V_4 = F_9 ( & V_2 -> V_2 , sizeof( struct V_3 ) ,
V_23 ) ;
if ( V_4 == NULL ) {
V_20 = - V_24 ;
goto V_25;
}
if ( V_6 -> V_26 ) {
V_20 = V_6 -> V_26 ( V_2 ) ;
if ( V_20 )
goto V_25;
}
F_3 ( V_2 , V_4 ) ;
for ( V_7 = 0 ; V_7 < V_2 -> V_27 ; V_7 ++ ) {
F_10 ( V_28 L_1 ,
( unsigned long long ) F_11 ( & V_2 -> V_29 [ V_7 ] ) ,
( unsigned long long ) V_2 -> V_29 [ V_7 ] . V_30 ) ;
if ( ! F_12 ( & V_2 -> V_2 ,
V_2 -> V_29 [ V_7 ] . V_30 ,
F_11 ( & V_2 -> V_29 [ V_7 ] ) ,
F_13 ( & V_2 -> V_2 ) ) ) {
F_14 ( & V_2 -> V_2 , L_2 ) ;
V_20 = - V_24 ;
goto V_25;
}
V_4 -> V_13 [ V_7 ] . V_31 = F_13 ( & V_2 -> V_2 ) ;
V_4 -> V_13 [ V_7 ] . V_32 = V_2 -> V_29 [ V_7 ] . V_30 ;
V_4 -> V_13 [ V_7 ] . V_33 = F_11 ( & V_2 -> V_29 [ V_7 ] ) ;
V_4 -> V_13 [ V_7 ] . V_34 = V_6 -> V_35 ;
V_4 -> V_13 [ V_7 ] . V_17 = F_7 ;
V_4 -> V_13 [ V_7 ] . V_36 = V_6 -> V_36 ;
V_4 -> V_13 [ V_7 ] . V_16 = ( unsigned long ) V_2 ;
V_4 -> V_13 [ V_7 ] . V_37 = F_15 ( & V_2 -> V_2 , V_4 -> V_13 [ V_7 ] . V_32 ,
V_4 -> V_13 [ V_7 ] . V_33 ) ;
if ( V_4 -> V_13 [ V_7 ] . V_37 == NULL ) {
F_14 ( & V_2 -> V_2 , L_3 ) ;
V_20 = - V_38 ;
goto V_25;
}
F_16 ( & V_4 -> V_13 [ V_7 ] ) ;
V_18 = V_39 ;
if ( V_6 -> V_18 == NULL ) {
for (; V_4 -> V_10 [ V_7 ] == NULL && * V_18 != NULL ; V_18 ++ )
V_4 -> V_10 [ V_7 ] = F_17 ( * V_18 , & V_4 -> V_13 [ V_7 ] ) ;
} else
V_4 -> V_10 [ V_7 ] = F_17 ( V_6 -> V_18 , & V_4 -> V_13 [ V_7 ] ) ;
if ( V_4 -> V_10 [ V_7 ] == NULL ) {
F_14 ( & V_2 -> V_2 , L_4 ) ;
V_20 = - V_40 ;
goto V_25;
} else {
V_21 ++ ;
}
V_4 -> V_10 [ V_7 ] -> V_41 = V_42 ;
V_4 -> V_10 [ V_7 ] -> V_2 . V_43 = & V_2 -> V_2 ;
}
if ( V_21 == 1 ) {
V_4 -> V_9 = V_4 -> V_10 [ 0 ] ;
} else if ( V_21 > 1 ) {
V_4 -> V_9 = F_18 ( V_4 -> V_10 , V_21 , F_13 ( & V_2 -> V_2 ) ) ;
if ( V_4 -> V_9 == NULL )
V_20 = - V_40 ;
}
if ( V_20 )
goto V_25;
V_19 = V_6 -> V_44 ? : V_44 ;
F_19 ( V_4 -> V_9 , V_19 , 0 ,
V_6 -> V_45 , V_6 -> V_46 ) ;
return 0 ;
V_25:
F_1 ( V_2 ) ;
return V_20 ;
}
static void F_20 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_7 ;
for ( V_7 = 0 ; V_7 < V_11 && V_4 -> V_10 [ V_7 ] ; V_7 ++ )
if ( F_21 ( V_4 -> V_10 [ V_7 ] ) == 0 )
F_22 ( V_4 -> V_10 [ V_7 ] ) ;
}
static int T_1 F_23 ( void )
{
int V_20 ;
V_20 = F_24 ( & V_47 ) ;
#ifdef F_25
if ( V_20 == 0 ) {
V_20 = F_26 ( & V_48 ) ;
if ( V_20 )
F_27 ( & V_47 ) ;
}
#endif
return V_20 ;
}
static void T_2 F_28 ( void )
{
#ifdef F_25
F_29 ( & V_48 ) ;
#endif
F_27 ( & V_47 ) ;
}
