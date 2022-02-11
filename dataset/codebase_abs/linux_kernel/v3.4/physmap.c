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
struct V_3 * V_4 ;
unsigned long V_16 ;
V_15 = (struct V_1 * ) V_13 -> V_17 ;
V_6 = V_15 -> V_2 . V_8 ;
if ( ! V_6 -> V_18 )
return;
V_4 = F_2 ( V_15 ) ;
F_8 ( & V_4 -> V_19 , V_16 ) ;
if ( V_14 ) {
if ( ++ V_4 -> V_20 == 1 )
V_6 -> V_18 ( V_15 , 1 ) ;
} else {
if ( -- V_4 -> V_20 == 0 )
V_6 -> V_18 ( V_15 , 0 ) ;
}
F_9 ( & V_4 -> V_19 , V_16 ) ;
}
static int F_10 ( struct V_1 * V_2 )
{
struct V_5 * V_6 ;
struct V_3 * V_4 ;
const char * * V_21 ;
const char * * V_22 ;
int V_23 = 0 ;
int V_7 ;
int V_24 = 0 ;
V_6 = V_2 -> V_2 . V_8 ;
if ( V_6 == NULL )
return - V_25 ;
V_4 = F_11 ( & V_2 -> V_2 , sizeof( struct V_3 ) ,
V_26 ) ;
if ( V_4 == NULL ) {
V_23 = - V_27 ;
goto V_28;
}
if ( V_6 -> V_29 ) {
V_23 = V_6 -> V_29 ( V_2 ) ;
if ( V_23 )
goto V_28;
}
F_3 ( V_2 , V_4 ) ;
for ( V_7 = 0 ; V_7 < V_2 -> V_30 ; V_7 ++ ) {
F_12 ( V_31 L_1 ,
( unsigned long long ) F_13 ( & V_2 -> V_32 [ V_7 ] ) ,
( unsigned long long ) V_2 -> V_32 [ V_7 ] . V_33 ) ;
if ( ! F_14 ( & V_2 -> V_2 ,
V_2 -> V_32 [ V_7 ] . V_33 ,
F_13 ( & V_2 -> V_32 [ V_7 ] ) ,
F_15 ( & V_2 -> V_2 ) ) ) {
F_16 ( & V_2 -> V_2 , L_2 ) ;
V_23 = - V_27 ;
goto V_28;
}
V_4 -> V_13 [ V_7 ] . V_34 = F_15 ( & V_2 -> V_2 ) ;
V_4 -> V_13 [ V_7 ] . V_35 = V_2 -> V_32 [ V_7 ] . V_33 ;
V_4 -> V_13 [ V_7 ] . V_36 = F_13 ( & V_2 -> V_32 [ V_7 ] ) ;
V_4 -> V_13 [ V_7 ] . V_37 = V_6 -> V_38 ;
V_4 -> V_13 [ V_7 ] . V_18 = F_7 ;
V_4 -> V_13 [ V_7 ] . V_39 = V_6 -> V_39 ;
V_4 -> V_13 [ V_7 ] . V_17 = ( unsigned long ) V_2 ;
V_4 -> V_13 [ V_7 ] . V_40 = F_17 ( & V_2 -> V_2 , V_4 -> V_13 [ V_7 ] . V_35 ,
V_4 -> V_13 [ V_7 ] . V_36 ) ;
if ( V_4 -> V_13 [ V_7 ] . V_40 == NULL ) {
F_16 ( & V_2 -> V_2 , L_3 ) ;
V_23 = - V_41 ;
goto V_28;
}
F_18 ( & V_4 -> V_13 [ V_7 ] ) ;
V_21 = V_42 ;
if ( V_6 -> V_21 == NULL ) {
for (; V_4 -> V_10 [ V_7 ] == NULL && * V_21 != NULL ; V_21 ++ )
V_4 -> V_10 [ V_7 ] = F_19 ( * V_21 , & V_4 -> V_13 [ V_7 ] ) ;
} else
V_4 -> V_10 [ V_7 ] = F_19 ( V_6 -> V_21 , & V_4 -> V_13 [ V_7 ] ) ;
if ( V_4 -> V_10 [ V_7 ] == NULL ) {
F_16 ( & V_2 -> V_2 , L_4 ) ;
V_23 = - V_43 ;
goto V_28;
} else {
V_24 ++ ;
}
V_4 -> V_10 [ V_7 ] -> V_44 = V_45 ;
V_4 -> V_10 [ V_7 ] -> V_2 . V_46 = & V_2 -> V_2 ;
}
if ( V_24 == 1 ) {
V_4 -> V_9 = V_4 -> V_10 [ 0 ] ;
} else if ( V_24 > 1 ) {
V_4 -> V_9 = F_20 ( V_4 -> V_10 , V_24 , F_15 ( & V_2 -> V_2 ) ) ;
if ( V_4 -> V_9 == NULL )
V_23 = - V_43 ;
}
if ( V_23 )
goto V_28;
F_21 ( & V_4 -> V_19 ) ;
V_22 = V_6 -> V_47 ? : V_47 ;
F_22 ( V_4 -> V_9 , V_22 , NULL ,
V_6 -> V_48 , V_6 -> V_49 ) ;
return 0 ;
V_28:
F_1 ( V_2 ) ;
return V_23 ;
}
static void F_23 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_7 ;
for ( V_7 = 0 ; V_7 < V_11 && V_4 -> V_10 [ V_7 ] ; V_7 ++ )
if ( F_24 ( V_4 -> V_10 [ V_7 ] ) == 0 )
F_25 ( V_4 -> V_10 [ V_7 ] ) ;
}
static int T_1 F_26 ( void )
{
int V_23 ;
V_23 = F_27 ( & V_50 ) ;
#ifdef F_28
if ( V_23 == 0 ) {
V_23 = F_29 ( & V_51 ) ;
if ( V_23 )
F_30 ( & V_50 ) ;
}
#endif
return V_23 ;
}
static void T_2 F_31 ( void )
{
#ifdef F_28
F_32 ( & V_51 ) ;
#endif
F_30 ( & V_50 ) ;
}
