static int F_1 ( void )
{
V_1 -> V_2 = F_2 ( V_1 -> V_3 + V_4 ) ;
return 0 ;
}
static void F_3 ( void )
{
F_4 ( V_1 -> V_2 , V_1 -> V_3 + V_4 ) ;
}
static void T_1 F_5 ( struct V_5 * V_6 , T_2 V_7 )
{
const char * V_8 [ V_9 ] ;
struct V_10 * V_11 [ V_9 ] ;
int V_12 ;
int V_13 ;
int V_14 ;
V_1 = F_6 ( sizeof( * V_1 ) +
sizeof( * V_1 -> V_15 . V_16 ) * V_17 ,
V_18 ) ;
if ( ! V_1 )
return;
F_7 ( & V_1 -> V_19 ) ;
V_12 = 0 ;
for ( V_14 = 0 ; V_14 < V_9 ; ++ V_14 ) {
char V_20 [] = L_1 ;
snprintf ( V_20 , sizeof( V_20 ) , L_2 , V_14 ) ;
V_11 [ V_14 ] = F_8 ( V_6 , V_20 ) ;
if ( F_9 ( V_11 [ V_14 ] ) ) {
V_8 [ V_14 ] = L_3 ;
continue;
}
V_8 [ V_14 ] = F_10 ( V_11 [ V_14 ] ) ;
V_12 = V_14 + 1 ;
}
if ( ! V_12 )
goto V_21;
V_1 -> V_3 = F_11 ( V_6 , 0 ) ;
if ( ! V_1 -> V_3 )
goto V_22;
V_1 -> V_23 . V_3 = V_1 -> V_3 + V_4 ;
V_1 -> V_23 . V_24 = V_25 ;
V_1 -> V_23 . V_26 = V_27 ;
V_1 -> V_23 . V_28 = & V_1 -> V_19 ;
V_1 -> V_29 . V_3 = V_1 -> V_3 + V_4 ;
V_1 -> V_29 . V_30 = V_7 ;
V_1 -> V_29 . V_31 = V_32 ;
V_1 -> V_29 . V_28 = & V_1 -> V_19 ;
V_1 -> V_15 . V_16 [ 0 ] = F_12 ( NULL , L_4 ,
V_8 , V_12 , & V_1 -> V_29 . V_33 ,
& V_34 , NULL , NULL , & V_1 -> V_23 . V_33 ,
& V_35 , V_36
| V_37 ) ;
if ( F_9 ( V_1 -> V_15 . V_16 [ 0 ] ) )
goto V_38;
V_1 -> V_15 . V_39 = V_17 ;
V_13 = F_13 ( V_6 , V_40 , & V_1 -> V_15 ) ;
if ( V_13 )
goto V_41;
F_14 ( & V_42 ) ;
return;
V_41:
F_15 ( V_1 -> V_15 . V_16 [ 0 ] ) ;
V_38:
F_16 ( V_1 -> V_3 ) ;
V_22:
for ( V_14 = 0 ; V_14 < V_9 ; ++ V_14 )
if ( ! F_9 ( V_11 [ V_14 ] ) )
F_17 ( V_11 [ V_14 ] ) ;
V_21:
F_18 ( V_1 ) ;
F_19 ( L_5 , V_43 ) ;
}
static void T_1 F_20 ( struct V_5 * V_6 )
{
F_5 ( V_6 , V_44 ) ;
}
static void T_1 F_21 ( struct V_5 * V_6 )
{
F_5 ( V_6 , V_45 ) ;
}
