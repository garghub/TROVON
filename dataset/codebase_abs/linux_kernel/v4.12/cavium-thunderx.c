static void F_1 ( struct V_1 * V_2 )
{
F_2 ( & V_2 -> V_3 ) ;
}
static void F_3 ( struct V_1 * V_2 )
{
F_4 ( & V_2 -> V_3 ) ;
}
static void F_5 ( struct V_1 * V_2 , T_1 V_4 )
{
F_6 ( V_4 , V_2 -> V_5 + F_7 ( V_2 ) ) ;
F_6 ( V_4 , V_2 -> V_5 + F_8 ( V_2 ) ) ;
}
static int F_9 ( struct V_1 * V_2 ,
struct V_6 * V_7 )
{
int V_8 , V_9 , V_10 ;
V_8 = F_10 ( V_7 , 1 , 9 , V_11 ) ;
if ( V_8 < 0 )
return V_8 ;
for ( V_10 = 0 ; V_10 < V_8 ; V_10 ++ ) {
V_9 = F_11 ( & V_7 -> V_12 , F_12 ( V_7 , V_10 ) ,
V_13 ,
0 , V_14 [ V_10 ] , V_2 ) ;
if ( V_9 )
return V_9 ;
}
return 0 ;
}
static int F_13 ( struct V_6 * V_7 ,
const struct V_15 * V_16 )
{
struct V_17 * V_18 = V_7 -> V_12 . V_19 ;
struct V_20 * V_12 = & V_7 -> V_12 ;
struct V_17 * V_21 ;
struct V_1 * V_2 ;
int V_9 , V_10 = 0 ;
V_2 = F_14 ( V_12 , sizeof( * V_2 ) , V_22 ) ;
if ( ! V_2 )
return - V_23 ;
F_15 ( V_7 , V_2 ) ;
V_9 = F_16 ( V_7 ) ;
if ( V_9 )
return V_9 ;
V_9 = F_17 ( V_7 , V_24 ) ;
if ( V_9 )
return V_9 ;
V_2 -> V_5 = F_18 ( V_7 , 0 , F_19 ( V_7 , 0 ) ) ;
if ( ! V_2 -> V_5 )
return - V_25 ;
V_2 -> V_26 = V_2 -> V_5 ;
V_2 -> V_27 = 0x2000 ;
V_2 -> V_28 = 0x160 ;
V_2 -> V_29 = F_20 ( V_12 , NULL ) ;
if ( F_21 ( V_2 -> V_29 ) )
return F_22 ( V_2 -> V_29 ) ;
V_9 = F_23 ( V_2 -> V_29 ) ;
if ( V_9 )
return V_9 ;
V_2 -> V_30 = F_24 ( V_2 -> V_29 ) ;
F_25 ( & V_2 -> V_31 ) ;
F_26 ( & V_2 -> V_3 , 1 ) ;
V_2 -> V_12 = V_12 ;
V_2 -> V_32 = F_1 ;
V_2 -> V_33 = F_3 ;
V_2 -> V_34 = F_5 ;
V_2 -> V_35 = true ;
V_2 -> V_36 = true ;
V_2 -> V_37 = true ;
V_2 -> V_38 = - 1 ;
V_9 = F_27 ( V_12 , F_28 ( 48 ) ) ;
if ( V_9 )
goto error;
F_6 ( 127 , V_2 -> V_5 + F_29 ( V_2 ) ) ;
F_6 ( 3 , V_2 -> V_5 + F_30 ( V_2 ) ) ;
F_6 ( F_31 ( 16 ) , V_2 -> V_5 + F_32 ( V_2 ) ) ;
V_9 = F_9 ( V_2 , V_7 ) ;
if ( V_9 )
goto error;
F_33 (node, child_node) {
if ( F_34 ( V_21 , L_1 ) ) {
V_2 -> V_39 [ V_10 ] = F_35 ( V_21 , NULL ,
& V_7 -> V_12 ) ;
if ( ! V_2 -> V_39 [ V_10 ] )
continue;
V_9 = F_36 ( & V_2 -> V_39 [ V_10 ] -> V_12 , V_2 ) ;
if ( V_9 )
goto error;
}
V_10 ++ ;
}
F_37 ( V_12 , L_2 ) ;
return 0 ;
error:
for ( V_10 = 0 ; V_10 < V_40 ; V_10 ++ ) {
if ( V_2 -> V_41 [ V_10 ] )
F_38 ( V_2 -> V_41 [ V_10 ] ) ;
if ( V_2 -> V_39 [ V_10 ] )
F_39 ( & V_2 -> V_39 [ V_10 ] -> V_12 , NULL ) ;
}
F_40 ( V_2 -> V_29 ) ;
return V_9 ;
}
static void F_41 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_42 ( V_7 ) ;
T_1 V_42 ;
int V_10 ;
for ( V_10 = 0 ; V_10 < V_40 ; V_10 ++ )
if ( V_2 -> V_41 [ V_10 ] )
F_38 ( V_2 -> V_41 [ V_10 ] ) ;
V_42 = F_43 ( V_2 -> V_26 + F_44 ( V_2 ) ) ;
V_42 &= ~ V_43 ;
F_6 ( V_42 , V_2 -> V_26 + F_44 ( V_2 ) ) ;
F_40 ( V_2 -> V_29 ) ;
}
