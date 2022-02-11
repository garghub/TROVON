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
if ( V_4 -> V_10 )
F_5 ( V_4 -> V_11 ) ;
if ( V_4 -> V_9 != V_4 -> V_12 [ 0 ] )
F_6 ( V_4 -> V_9 ) ;
}
for ( V_7 = 0 ; V_7 < V_13 ; V_7 ++ ) {
if ( V_4 -> V_12 [ V_7 ] != NULL )
F_7 ( V_4 -> V_12 [ V_7 ] ) ;
}
if ( V_6 -> exit )
V_6 -> exit ( V_2 ) ;
return 0 ;
}
static void F_8 ( struct V_14 * V_15 , int V_16 )
{
struct V_1 * V_17 ;
struct V_5 * V_6 ;
V_17 = (struct V_1 * ) V_15 -> V_18 ;
V_6 = V_17 -> V_2 . V_8 ;
if ( V_6 -> V_19 )
V_6 -> V_19 ( V_17 , V_16 ) ;
}
static int F_9 ( struct V_1 * V_2 )
{
struct V_5 * V_6 ;
struct V_3 * V_4 ;
const char * * V_20 ;
int V_21 = 0 ;
int V_7 ;
int V_22 = 0 ;
V_6 = V_2 -> V_2 . V_8 ;
if ( V_6 == NULL )
return - V_23 ;
V_4 = F_10 ( & V_2 -> V_2 , sizeof( struct V_3 ) ,
V_24 ) ;
if ( V_4 == NULL ) {
V_21 = - V_25 ;
goto V_26;
}
if ( V_6 -> V_27 ) {
V_21 = V_6 -> V_27 ( V_2 ) ;
if ( V_21 )
goto V_26;
}
F_3 ( V_2 , V_4 ) ;
for ( V_7 = 0 ; V_7 < V_2 -> V_28 ; V_7 ++ ) {
F_11 ( V_29 L_1 ,
( unsigned long long ) F_12 ( & V_2 -> V_30 [ V_7 ] ) ,
( unsigned long long ) V_2 -> V_30 [ V_7 ] . V_31 ) ;
if ( ! F_13 ( & V_2 -> V_2 ,
V_2 -> V_30 [ V_7 ] . V_31 ,
F_12 ( & V_2 -> V_30 [ V_7 ] ) ,
F_14 ( & V_2 -> V_2 ) ) ) {
F_15 ( & V_2 -> V_2 , L_2 ) ;
V_21 = - V_25 ;
goto V_26;
}
V_4 -> V_15 [ V_7 ] . V_32 = F_14 ( & V_2 -> V_2 ) ;
V_4 -> V_15 [ V_7 ] . V_33 = V_2 -> V_30 [ V_7 ] . V_31 ;
V_4 -> V_15 [ V_7 ] . V_34 = F_12 ( & V_2 -> V_30 [ V_7 ] ) ;
V_4 -> V_15 [ V_7 ] . V_35 = V_6 -> V_36 ;
V_4 -> V_15 [ V_7 ] . V_19 = F_8 ;
V_4 -> V_15 [ V_7 ] . V_37 = V_6 -> V_37 ;
V_4 -> V_15 [ V_7 ] . V_18 = ( unsigned long ) V_2 ;
V_4 -> V_15 [ V_7 ] . V_38 = F_16 ( & V_2 -> V_2 , V_4 -> V_15 [ V_7 ] . V_33 ,
V_4 -> V_15 [ V_7 ] . V_34 ) ;
if ( V_4 -> V_15 [ V_7 ] . V_38 == NULL ) {
F_15 ( & V_2 -> V_2 , L_3 ) ;
V_21 = - V_39 ;
goto V_26;
}
F_17 ( & V_4 -> V_15 [ V_7 ] ) ;
V_20 = V_40 ;
if ( V_6 -> V_20 == NULL ) {
for (; V_4 -> V_12 [ V_7 ] == NULL && * V_20 != NULL ; V_20 ++ )
V_4 -> V_12 [ V_7 ] = F_18 ( * V_20 , & V_4 -> V_15 [ V_7 ] ) ;
} else
V_4 -> V_12 [ V_7 ] = F_18 ( V_6 -> V_20 , & V_4 -> V_15 [ V_7 ] ) ;
if ( V_4 -> V_12 [ V_7 ] == NULL ) {
F_15 ( & V_2 -> V_2 , L_4 ) ;
V_21 = - V_41 ;
goto V_26;
} else {
V_22 ++ ;
}
V_4 -> V_12 [ V_7 ] -> V_42 = V_43 ;
V_4 -> V_12 [ V_7 ] -> V_2 . V_44 = & V_2 -> V_2 ;
}
if ( V_22 == 1 ) {
V_4 -> V_9 = V_4 -> V_12 [ 0 ] ;
} else if ( V_22 > 1 ) {
V_4 -> V_9 = F_19 ( V_4 -> V_12 , V_22 , F_14 ( & V_2 -> V_2 ) ) ;
if ( V_4 -> V_9 == NULL )
V_21 = - V_41 ;
}
if ( V_21 )
goto V_26;
V_21 = F_20 ( V_4 -> V_9 , V_45 ,
& V_4 -> V_11 , 0 ) ;
if ( V_21 > 0 ) {
F_21 ( V_4 -> V_9 , V_4 -> V_11 , V_21 ) ;
V_4 -> V_10 = V_21 ;
return 0 ;
}
if ( V_6 -> V_10 ) {
F_11 ( V_29 L_5 ) ;
F_21 ( V_4 -> V_9 , V_6 -> V_11 ,
V_6 -> V_10 ) ;
return 0 ;
}
F_21 ( V_4 -> V_9 , NULL , 0 ) ;
return 0 ;
V_26:
F_1 ( V_2 ) ;
return V_21 ;
}
static void F_22 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_7 ;
for ( V_7 = 0 ; V_7 < V_13 && V_4 -> V_12 [ V_7 ] ; V_7 ++ )
if ( V_4 -> V_12 [ V_7 ] -> V_46 && V_4 -> V_12 [ V_7 ] -> V_47 )
if ( V_4 -> V_12 [ V_7 ] -> V_46 ( V_4 -> V_12 [ V_7 ] ) == 0 )
V_4 -> V_12 [ V_7 ] -> V_47 ( V_4 -> V_12 [ V_7 ] ) ;
}
void F_23 ( unsigned long V_48 , unsigned long V_34 ,
int V_35 , void (* V_19)( struct V_14 * , int ) )
{
V_49 . V_31 = V_48 ;
V_49 . V_50 = V_48 + V_34 - 1 ;
V_5 . V_36 = V_35 ;
V_5 . V_19 = V_19 ;
}
void F_24 ( struct V_51 * V_11 , int V_52 )
{
V_5 . V_10 = V_52 ;
V_5 . V_11 = V_11 ;
}
static int T_1 F_25 ( void )
{
int V_21 ;
V_21 = F_26 ( & V_53 ) ;
#ifdef F_27
if ( V_21 == 0 ) {
V_21 = F_28 ( & V_54 ) ;
if ( V_21 )
F_29 ( & V_53 ) ;
}
#endif
return V_21 ;
}
static void T_2 F_30 ( void )
{
#ifdef F_27
F_31 ( & V_54 ) ;
#endif
F_29 ( & V_53 ) ;
}
