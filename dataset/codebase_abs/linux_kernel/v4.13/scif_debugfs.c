static int F_1 ( struct V_1 * V_2 , void * V_3 )
{
int V_4 ;
F_2 ( V_2 , L_1 ,
V_5 . V_6 , V_5 . V_7 ,
V_5 . V_8 ) ;
if ( ! V_9 )
return 0 ;
F_2 ( V_2 , L_2 , L_3 , L_4 ) ;
for ( V_4 = 0 ; V_4 <= V_5 . V_8 ; V_4 ++ )
F_2 ( V_2 , L_5 , V_9 [ V_4 ] . V_4 ,
F_3 ( & V_9 [ V_4 ] ) ?
L_6 : L_7 ) ;
return 0 ;
}
static int F_4 ( struct V_10 * V_10 , struct V_11 * V_11 )
{
return F_5 ( V_11 , F_1 , V_10 -> V_12 ) ;
}
static int F_6 ( struct V_10 * V_10 , struct V_11 * V_11 )
{
return F_7 ( V_10 , V_11 ) ;
}
static void F_8 ( struct V_13 * V_14 , struct V_1 * V_2 )
{
int V_15 ;
struct V_16 * V_17 ;
T_1 V_18 = V_14 -> V_19 ;
F_2 ( V_2 , L_8 ,
V_14 , V_14 -> type , V_14 -> V_20 , V_14 -> V_21 ) ;
F_2 ( V_2 , L_9 ,
V_14 -> V_22 , V_14 -> V_23 , V_14 -> V_24 ) ;
F_2 ( V_2 , L_10 ,
V_14 -> V_25 , V_14 -> V_26 , V_14 -> V_27 ) ;
F_2 ( V_2 , L_11 ,
V_14 -> V_28 , V_14 -> V_29 ) ;
for ( V_15 = 0 ; V_15 < V_14 -> V_23 ; V_15 ++ )
F_2 ( V_2 , L_12 , V_15 ,
V_14 -> V_30 [ V_15 ] , V_14 -> V_31 [ V_15 ] ) ;
if ( V_14 -> type == V_32 && V_18 )
for ( V_15 = 0 ; V_15 < V_14 -> V_22 ; V_15 ++ )
F_2 ( V_2 , L_13 ,
V_15 , V_18 -> V_33 [ V_15 ] ,
F_9 ( V_18 -> V_33 [ V_15 ] ) ) ;
if ( V_14 -> V_34 )
F_10 (window->st->sgl, sg, window->st->nents, j)
F_2 ( V_2 , L_14 ,
V_15 , F_11 ( V_17 ) , F_12 ( V_17 ) ) ;
}
static void F_13 ( struct V_35 * V_36 , struct V_1 * V_2 )
{
struct V_35 * V_37 ;
struct V_13 * V_14 ;
F_14 (item, head) {
V_14 = F_15 ( V_37 , struct V_13 , V_38 ) ;
F_8 ( V_14 , V_2 ) ;
}
}
static int F_16 ( struct V_1 * V_2 , void * V_3 )
{
struct V_39 * V_40 ;
struct V_35 * V_41 ;
F_17 ( & V_5 . V_42 ) ;
F_14 (pos, &scif_info.connected) {
V_40 = F_15 ( V_41 , struct V_39 , V_38 ) ;
F_2 ( V_2 , L_15 , V_40 ) ;
F_17 ( & V_40 -> V_43 . V_44 ) ;
F_13 ( & V_40 -> V_43 . V_45 , V_2 ) ;
F_2 ( V_2 , L_16 , V_40 ) ;
F_13 ( & V_40 -> V_43 . V_46 , V_2 ) ;
F_18 ( & V_40 -> V_43 . V_44 ) ;
}
F_18 ( & V_5 . V_42 ) ;
return 0 ;
}
static int F_19 ( struct V_10 * V_10 , struct V_11 * V_11 )
{
return F_5 ( V_11 , F_16 , V_10 -> V_12 ) ;
}
static int F_20 ( struct V_10 * V_10 , struct V_11 * V_11 )
{
return F_7 ( V_10 , V_11 ) ;
}
void T_2 F_21 ( void )
{
V_47 = F_22 ( V_48 , NULL ) ;
if ( ! V_47 ) {
F_23 ( V_5 . V_49 . V_50 ,
L_17 ) ;
return;
}
F_24 ( L_18 , 0444 , V_47 , NULL , & V_51 ) ;
F_24 ( L_19 , 0444 , V_47 , NULL , & V_52 ) ;
F_25 ( L_20 , 0666 , V_47 , & V_5 . V_53 ) ;
F_25 ( L_21 , 0666 , V_47 , & V_5 . V_54 ) ;
}
void F_26 ( void )
{
F_27 ( V_47 ) ;
}
