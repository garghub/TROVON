static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = NULL ;
int V_7 ;
int V_8 ;
F_2 ( L_1 , V_2 -> V_9 ) ;
if ( F_3 ( V_2 , sizeof( struct V_10 ) ) < 0 )
return - V_11 ;
F_4 (pcidev) {
if ( V_6 -> V_12 != V_13 )
continue;
for ( V_7 = 0 ; V_7 < F_5 ( V_14 ) ; V_7 ++ ) {
if ( V_14 [ V_7 ] . V_15 != V_6 -> V_16 )
continue;
if ( V_4 -> V_17 [ 0 ] || V_4 -> V_17 [ 1 ] ) {
if ( V_6 -> V_18 -> V_19 != V_4 -> V_17 [ 0 ] ||
F_6 ( V_6 -> V_20 ) != V_4 -> V_17 [ 1 ] ) {
continue;
}
}
V_2 -> V_21 = V_14 + V_7 ;
goto V_22;
}
}
F_2 ( L_2
L_3 ) ;
return - V_23 ;
V_22:
V_2 -> V_24 = V_25 -> V_26 ;
V_27 -> V_5 = V_6 ;
F_2 ( L_4 , V_25 -> V_26 ,
V_27 -> V_5 -> V_18 -> V_19 ,
F_6 ( V_27 -> V_5 -> V_20 ) ) ;
if ( F_7 ( V_6 , V_25 -> V_26 ) ) {
F_2
( L_5 ) ;
return - V_23 ;
}
V_27 -> V_28
=
F_8 ( V_27 -> V_5 ,
V_14 [ V_7 ] . V_29 ) ;
if ( F_9 ( V_2 , V_25 -> V_30 ) < 0 )
return - V_11 ;
for ( V_8 = 0 ; V_8 < V_25 -> V_30 ; V_8 ++ ) {
F_10 ( V_2 , V_2 -> V_31 + V_8 ,
NULL , V_27 -> V_28 + V_8 * 4 ) ;
F_2 ( L_6 , V_8 ,
V_27 -> V_28 + V_8 * 4 ) ;
}
F_2 ( L_7 ) ;
return 1 ;
}
static int F_11 ( struct V_1 * V_2 )
{
F_2 ( L_8 , V_2 -> V_9 ) ;
if ( V_27 ) {
if ( V_27 -> V_5 ) {
if ( V_27 -> V_28 )
F_12 ( V_27 -> V_5 ) ;
F_13 ( V_27 -> V_5 ) ;
}
}
if ( V_2 -> V_31 ) {
int V_8 ;
for ( V_8 = 0 ; V_8 < V_25 -> V_30 ; V_8 ++ )
F_14 ( V_2 , V_2 -> V_31 + V_8 ) ;
}
return 0 ;
}
static int T_1 F_15 ( struct V_5 * V_2 ,
const struct V_32 * V_33 )
{
return F_16 ( V_2 , V_34 . V_35 ) ;
}
static void T_2 F_17 ( struct V_5 * V_2 )
{
F_18 ( V_2 ) ;
}
static int T_3 F_19 ( void )
{
int V_36 ;
V_36 = F_20 ( & V_34 ) ;
if ( V_36 < 0 )
return V_36 ;
V_37 . V_26 = ( char * ) V_34 . V_35 ;
return F_21 ( & V_37 ) ;
}
static void T_4 F_22 ( void )
{
F_23 ( & V_37 ) ;
F_24 ( & V_34 ) ;
}
