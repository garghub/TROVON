static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
struct V_5 * V_6 ;
int V_7 ;
V_4 = F_2 ( V_2 ) ;
if ( V_4 == NULL )
return 0 ;
V_6 = F_3 ( & V_2 -> V_2 ) ;
if ( V_4 -> V_8 ) {
F_4 ( V_4 -> V_8 ) ;
if ( V_4 -> V_8 != V_4 -> V_9 [ 0 ] )
F_5 ( V_4 -> V_8 ) ;
}
for ( V_7 = 0 ; V_7 < V_10 ; V_7 ++ ) {
if ( V_4 -> V_9 [ V_7 ] != NULL )
F_6 ( V_4 -> V_9 [ V_7 ] ) ;
}
if ( V_6 -> exit )
V_6 -> exit ( V_2 ) ;
return 0 ;
}
static void F_7 ( struct V_11 * V_12 , int V_13 )
{
struct V_1 * V_14 ;
struct V_5 * V_6 ;
struct V_3 * V_4 ;
unsigned long V_15 ;
V_14 = (struct V_1 * ) V_12 -> V_16 ;
V_6 = F_3 ( & V_14 -> V_2 ) ;
if ( ! V_6 -> V_17 )
return;
V_4 = F_2 ( V_14 ) ;
F_8 ( & V_4 -> V_18 , V_15 ) ;
if ( V_13 ) {
if ( ++ V_4 -> V_19 == 1 )
V_6 -> V_17 ( V_14 , 1 ) ;
} else {
if ( -- V_4 -> V_19 == 0 )
V_6 -> V_17 ( V_14 , 0 ) ;
}
F_9 ( & V_4 -> V_18 , V_15 ) ;
}
static int F_10 ( struct V_1 * V_2 )
{
struct V_5 * V_6 ;
struct V_3 * V_4 ;
const char * const * V_20 ;
const char * const * V_21 ;
int V_22 = 0 ;
int V_7 ;
int V_23 = 0 ;
V_6 = F_3 ( & V_2 -> V_2 ) ;
if ( V_6 == NULL )
return - V_24 ;
V_4 = F_11 ( & V_2 -> V_2 , sizeof( struct V_3 ) ,
V_25 ) ;
if ( V_4 == NULL ) {
V_22 = - V_26 ;
goto V_27;
}
if ( V_6 -> V_28 ) {
V_22 = V_6 -> V_28 ( V_2 ) ;
if ( V_22 )
goto V_27;
}
F_12 ( V_2 , V_4 ) ;
for ( V_7 = 0 ; V_7 < V_2 -> V_29 ; V_7 ++ ) {
F_13 ( V_30 L_1 ,
( unsigned long long ) F_14 ( & V_2 -> V_31 [ V_7 ] ) ,
( unsigned long long ) V_2 -> V_31 [ V_7 ] . V_32 ) ;
if ( ! F_15 ( & V_2 -> V_2 ,
V_2 -> V_31 [ V_7 ] . V_32 ,
F_14 ( & V_2 -> V_31 [ V_7 ] ) ,
F_16 ( & V_2 -> V_2 ) ) ) {
F_17 ( & V_2 -> V_2 , L_2 ) ;
V_22 = - V_26 ;
goto V_27;
}
V_4 -> V_12 [ V_7 ] . V_33 = F_16 ( & V_2 -> V_2 ) ;
V_4 -> V_12 [ V_7 ] . V_34 = V_2 -> V_31 [ V_7 ] . V_32 ;
V_4 -> V_12 [ V_7 ] . V_35 = F_14 ( & V_2 -> V_31 [ V_7 ] ) ;
V_4 -> V_12 [ V_7 ] . V_36 = V_6 -> V_37 ;
V_4 -> V_12 [ V_7 ] . V_17 = F_7 ;
V_4 -> V_12 [ V_7 ] . V_38 = V_6 -> V_38 ;
V_4 -> V_12 [ V_7 ] . V_16 = ( unsigned long ) V_2 ;
V_4 -> V_12 [ V_7 ] . V_39 = F_18 ( & V_2 -> V_2 , V_4 -> V_12 [ V_7 ] . V_34 ,
V_4 -> V_12 [ V_7 ] . V_35 ) ;
if ( V_4 -> V_12 [ V_7 ] . V_39 == NULL ) {
F_17 ( & V_2 -> V_2 , L_3 ) ;
V_22 = - V_40 ;
goto V_27;
}
F_19 ( & V_4 -> V_12 [ V_7 ] ) ;
V_20 = V_41 ;
if ( V_6 -> V_20 == NULL ) {
for (; V_4 -> V_9 [ V_7 ] == NULL && * V_20 != NULL ; V_20 ++ )
V_4 -> V_9 [ V_7 ] = F_20 ( * V_20 , & V_4 -> V_12 [ V_7 ] ) ;
} else
V_4 -> V_9 [ V_7 ] = F_20 ( V_6 -> V_20 , & V_4 -> V_12 [ V_7 ] ) ;
if ( V_4 -> V_9 [ V_7 ] == NULL ) {
F_17 ( & V_2 -> V_2 , L_4 ) ;
V_22 = - V_42 ;
goto V_27;
} else {
V_23 ++ ;
}
V_4 -> V_9 [ V_7 ] -> V_43 = V_44 ;
V_4 -> V_9 [ V_7 ] -> V_2 . V_45 = & V_2 -> V_2 ;
}
if ( V_23 == 1 ) {
V_4 -> V_8 = V_4 -> V_9 [ 0 ] ;
} else if ( V_23 > 1 ) {
V_4 -> V_8 = F_21 ( V_4 -> V_9 , V_23 , F_16 ( & V_2 -> V_2 ) ) ;
if ( V_4 -> V_8 == NULL )
V_22 = - V_42 ;
}
if ( V_22 )
goto V_27;
F_22 ( & V_4 -> V_18 ) ;
V_21 = V_6 -> V_46 ? : V_46 ;
F_23 ( V_4 -> V_8 , V_21 , NULL ,
V_6 -> V_47 , V_6 -> V_48 ) ;
return 0 ;
V_27:
F_1 ( V_2 ) ;
return V_22 ;
}
static void F_24 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_7 ;
for ( V_7 = 0 ; V_7 < V_10 && V_4 -> V_9 [ V_7 ] ; V_7 ++ )
if ( F_25 ( V_4 -> V_9 [ V_7 ] ) == 0 )
F_26 ( V_4 -> V_9 [ V_7 ] ) ;
}
static int T_1 F_27 ( void )
{
int V_22 ;
V_22 = F_28 ( & V_49 ) ;
#ifdef F_29
if ( V_22 == 0 ) {
V_22 = F_30 ( & V_50 ) ;
if ( V_22 )
F_31 ( & V_49 ) ;
}
#endif
return V_22 ;
}
static void T_2 F_32 ( void )
{
#ifdef F_29
F_33 ( & V_50 ) ;
#endif
F_31 ( & V_49 ) ;
}
