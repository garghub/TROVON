static void F_1 ( unsigned int V_1 )
{
if ( V_1 == 0 || V_1 == 2 ) {
if ( V_2 ++ == 0 ) {
V_3 = F_2 ( NULL , L_1 ) ;
V_4 = F_2 ( NULL , L_2 ) ;
if ( ! F_3 ( V_3 ) && ! F_3 ( V_4 ) ) {
F_4 ( V_3 ) ;
F_4 ( V_4 ) ;
F_5 ( F_6 ( V_5 ) | V_6 |
V_7 , V_5 ) ;
}
}
}
}
static void F_7 ( unsigned int V_1 )
{
if ( V_1 == 0 || V_1 == 2 ) {
if ( -- V_2 == 0 ) {
if ( ! F_3 ( V_3 ) ) {
F_8 ( V_3 ) ;
F_9 ( V_3 ) ;
}
if ( ! F_3 ( V_4 ) ) {
F_8 ( V_4 ) ;
F_9 ( V_4 ) ;
}
}
}
}
static void F_10 ( struct V_8 * V_9 , int V_10 ,
struct V_11 * V_12 , int V_13 )
{
int V_14 ;
V_15 = F_11 ( V_13 * sizeof( struct V_16 * ) ,
V_17 ) ;
if ( ! V_15 ) {
F_12 ( V_18 L_3 ) ;
return;
}
for ( V_14 = 0 ; V_14 < V_13 ; V_14 ++ ) {
struct V_16 * V_19 ;
int V_20 ;
V_19 = F_13 ( L_4 , V_14 + 1 ) ;
if ( ! V_19 )
continue;
F_14 ( V_19 , & V_9 [ V_14 * V_10 ] ,
V_10 ) ;
V_12 [ V_14 ] . V_21 = 2 ;
V_12 [ V_14 ] . V_22 = 2 ;
V_19 -> V_23 . V_24 = & V_12 [ V_14 ] ;
V_20 = F_15 ( V_19 ) ;
if ( V_20 ) {
F_16 ( V_19 ) ;
continue;
}
V_15 [ V_14 ] = V_19 ;
}
}
static int T_1 F_17 ( void )
{
if ( ! F_18 () )
return - V_25 ;
if ( F_19 () )
F_10 ( V_26 ,
V_27 ,
V_28 ,
V_29 ) ;
if ( F_20 () )
F_10 ( V_30 ,
V_31 ,
V_32 ,
V_33 ) ;
if ( F_21 () )
F_10 ( V_34 ,
V_35 ,
V_36 ,
V_37 ) ;
return 0 ;
}
