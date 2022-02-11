static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 , struct V_7 * V_8 ,
struct V_9 * V_10 )
{
if ( ! F_2 ( V_10 , V_2 ) )
return 0 ;
return F_3 ( V_2 , NULL , V_4 , V_8 ,
F_4 ( F_5 ( V_6 -> V_4 ) . V_11 ) ,
F_5 ( V_6 -> V_4 ) . V_12 ,
V_6 -> V_13 -> V_14 , V_15 , V_6 -> V_13 ) ;
}
static int F_6 ( struct V_16 * V_17 , struct V_3 * V_18 ,
const struct V_19 * V_13 , struct V_7 * V_8 )
{
int V_20 = - V_21 ;
struct V_1 * V_2 ;
struct V_3 * V_22 ;
struct V_23 * V_23 = F_7 ( V_18 -> V_2 ) ;
if ( V_8 -> V_24 == V_25 )
V_2 = F_8 ( V_23 ,
V_8 -> V_26 . V_27 [ 0 ] , V_8 -> V_26 . V_28 ,
V_8 -> V_26 . V_29 [ 0 ] , V_8 -> V_26 . V_30 ,
V_8 -> V_26 . V_31 , V_17 ) ;
#if F_9 ( V_32 )
else if ( V_8 -> V_24 == V_33 )
V_2 = F_10 ( V_23 ,
(struct V_34 * ) V_8 -> V_26 . V_27 ,
V_8 -> V_26 . V_28 ,
(struct V_34 * ) V_8 -> V_26 . V_29 ,
V_8 -> V_26 . V_30 ,
V_8 -> V_26 . V_31 , V_17 ) ;
#endif
else
goto V_35;
V_20 = - V_36 ;
if ( V_2 == NULL )
goto V_35;
V_20 = F_11 ( V_2 , V_8 -> V_26 . V_37 ) ;
if ( V_20 )
goto V_38;
V_20 = - V_39 ;
V_22 = F_12 ( F_13 ( ( sizeof( struct V_40 ) +
sizeof( struct V_41 ) +
64 ) ) , V_42 ) ;
if ( ! V_22 )
goto V_38;
V_20 = F_3 ( V_2 , NULL , V_22 , V_8 ,
F_4 ( F_5 ( V_18 ) . V_11 ) ,
F_5 ( V_18 ) . V_12 ,
V_13 -> V_14 , 0 , V_13 ) ;
if ( V_20 < 0 ) {
F_14 ( V_20 == - V_43 ) ;
F_15 ( V_22 ) ;
goto V_38;
}
V_20 = F_16 ( V_23 -> V_44 , V_22 , F_5 ( V_18 ) . V_12 ,
V_45 ) ;
if ( V_20 > 0 )
V_20 = 0 ;
V_38:
if ( V_2 )
F_17 ( V_2 ) ;
V_35:
return V_20 ;
}
static void F_18 ( struct V_16 * V_46 , struct V_3 * V_4 , struct V_5 * V_6 ,
struct V_7 * V_47 , struct V_9 * V_10 )
{
int V_48 , V_49 , V_50 , V_51 ;
struct V_23 * V_23 = F_7 ( V_4 -> V_2 ) ;
V_51 = V_6 -> args [ 0 ] ;
V_48 = V_49 = V_6 -> args [ 1 ] ;
for ( V_50 = V_51 ; V_50 <= V_46 -> V_52 ; V_48 = V_49 = 0 , V_50 ++ ) {
struct V_1 * V_2 ;
struct V_53 * V_54 ;
struct V_55 * V_56 = & V_46 -> V_57 [ V_50 ] ;
if ( F_19 ( & V_56 -> V_58 ) )
continue;
F_20 ( & V_56 -> V_59 ) ;
F_21 (sk, node, &hslot->head) {
struct V_60 * V_61 = F_22 ( V_2 ) ;
if ( ! F_23 ( F_7 ( V_2 ) , V_23 ) )
continue;
if ( V_48 < V_49 )
goto V_62;
if ( ! ( V_47 -> V_63 & ( 1 << V_2 -> V_64 ) ) )
goto V_62;
if ( V_47 -> V_24 != V_65 &&
V_2 -> V_66 != V_47 -> V_24 )
goto V_62;
if ( V_47 -> V_26 . V_28 != V_61 -> V_67 &&
V_47 -> V_26 . V_28 )
goto V_62;
if ( V_47 -> V_26 . V_30 != V_61 -> V_68 &&
V_47 -> V_26 . V_30 )
goto V_62;
if ( F_1 ( V_2 , V_4 , V_6 , V_47 , V_10 ) < 0 ) {
F_24 ( & V_56 -> V_59 ) ;
goto V_69;
}
V_62:
V_48 ++ ;
}
F_24 ( & V_56 -> V_59 ) ;
}
V_69:
V_6 -> args [ 0 ] = V_50 ;
V_6 -> args [ 1 ] = V_48 ;
}
static void F_25 ( struct V_3 * V_4 , struct V_5 * V_6 ,
struct V_7 * V_47 , struct V_9 * V_10 )
{
F_18 ( & V_16 , V_4 , V_6 , V_47 , V_10 ) ;
}
static int F_26 ( struct V_3 * V_18 , const struct V_19 * V_13 ,
struct V_7 * V_8 )
{
return F_6 ( & V_16 , V_18 , V_13 , V_8 ) ;
}
static void F_27 ( struct V_1 * V_2 , struct V_40 * V_47 ,
void * V_70 )
{
V_47 -> V_71 = F_28 ( V_2 ) ;
V_47 -> V_72 = F_29 ( V_2 ) ;
}
static void F_30 ( struct V_3 * V_4 , struct V_5 * V_6 ,
struct V_7 * V_47 , struct V_9 * V_10 )
{
F_18 ( & V_73 , V_4 , V_6 , V_47 , V_10 ) ;
}
static int F_31 ( struct V_3 * V_18 , const struct V_19 * V_13 ,
struct V_7 * V_8 )
{
return F_6 ( & V_73 , V_18 , V_13 , V_8 ) ;
}
static int T_1 F_32 ( void )
{
int V_20 ;
V_20 = F_33 ( & V_74 ) ;
if ( V_20 )
goto V_38;
V_20 = F_33 ( & V_75 ) ;
if ( V_20 )
goto V_76;
V_38:
return V_20 ;
V_76:
F_34 ( & V_74 ) ;
goto V_38;
}
static void T_2 F_35 ( void )
{
F_34 ( & V_75 ) ;
F_34 ( & V_74 ) ;
}
