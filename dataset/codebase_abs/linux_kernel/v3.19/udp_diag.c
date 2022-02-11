static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 , struct V_7 * V_8 ,
struct V_9 * V_10 )
{
if ( ! F_2 ( V_10 , V_2 ) )
return 0 ;
return F_3 ( V_2 , NULL , V_4 , V_8 ,
F_4 ( F_5 ( V_6 -> V_4 ) . V_2 ) ,
F_5 ( V_6 -> V_4 ) . V_11 ,
V_6 -> V_12 -> V_13 , V_14 , V_6 -> V_12 ) ;
}
static int F_6 ( struct V_15 * V_16 , struct V_3 * V_17 ,
const struct V_18 * V_12 , struct V_7 * V_8 )
{
int V_19 = - V_20 ;
struct V_1 * V_2 ;
struct V_3 * V_21 ;
struct V_22 * V_22 = F_7 ( V_17 -> V_2 ) ;
if ( V_8 -> V_23 == V_24 )
V_2 = F_8 ( V_22 ,
V_8 -> V_25 . V_26 [ 0 ] , V_8 -> V_25 . V_27 ,
V_8 -> V_25 . V_28 [ 0 ] , V_8 -> V_25 . V_29 ,
V_8 -> V_25 . V_30 , V_16 ) ;
#if F_9 ( V_31 )
else if ( V_8 -> V_23 == V_32 )
V_2 = F_10 ( V_22 ,
(struct V_33 * ) V_8 -> V_25 . V_26 ,
V_8 -> V_25 . V_27 ,
(struct V_33 * ) V_8 -> V_25 . V_28 ,
V_8 -> V_25 . V_29 ,
V_8 -> V_25 . V_30 , V_16 ) ;
#endif
else
goto V_34;
V_19 = - V_35 ;
if ( V_2 == NULL )
goto V_34;
V_19 = F_11 ( V_2 , V_8 -> V_25 . V_36 ) ;
if ( V_19 )
goto V_37;
V_19 = - V_38 ;
V_21 = F_12 ( sizeof( struct V_39 ) +
sizeof( struct V_40 ) + 64 ,
V_41 ) ;
if ( ! V_21 )
goto V_37;
V_19 = F_3 ( V_2 , NULL , V_21 , V_8 ,
F_4 ( F_5 ( V_17 ) . V_2 ) ,
F_5 ( V_17 ) . V_11 ,
V_12 -> V_13 , 0 , V_12 ) ;
if ( V_19 < 0 ) {
F_13 ( V_19 == - V_42 ) ;
F_14 ( V_21 ) ;
goto V_37;
}
V_19 = F_15 ( V_22 -> V_43 , V_21 , F_5 ( V_17 ) . V_11 ,
V_44 ) ;
if ( V_19 > 0 )
V_19 = 0 ;
V_37:
if ( V_2 )
F_16 ( V_2 ) ;
V_34:
return V_19 ;
}
static void F_17 ( struct V_15 * V_45 , struct V_3 * V_4 , struct V_5 * V_6 ,
struct V_7 * V_46 , struct V_9 * V_10 )
{
int V_47 , V_48 , V_49 , V_50 ;
struct V_22 * V_22 = F_7 ( V_4 -> V_2 ) ;
V_50 = V_6 -> args [ 0 ] ;
V_47 = V_48 = V_6 -> args [ 1 ] ;
for ( V_49 = V_50 ; V_49 <= V_45 -> V_51 ; V_48 = 0 , V_49 ++ ) {
struct V_1 * V_2 ;
struct V_52 * V_53 ;
struct V_54 * V_55 = & V_45 -> V_56 [ V_49 ] ;
V_47 = 0 ;
if ( F_18 ( & V_55 -> V_57 ) )
continue;
F_19 ( & V_55 -> V_58 ) ;
F_20 (sk, node, &hslot->head) {
struct V_59 * V_60 = F_21 ( V_2 ) ;
if ( ! F_22 ( F_7 ( V_2 ) , V_22 ) )
continue;
if ( V_47 < V_48 )
goto V_61;
if ( ! ( V_46 -> V_62 & ( 1 << V_2 -> V_63 ) ) )
goto V_61;
if ( V_46 -> V_23 != V_64 &&
V_2 -> V_65 != V_46 -> V_23 )
goto V_61;
if ( V_46 -> V_25 . V_27 != V_60 -> V_66 &&
V_46 -> V_25 . V_27 )
goto V_61;
if ( V_46 -> V_25 . V_29 != V_60 -> V_67 &&
V_46 -> V_25 . V_29 )
goto V_61;
if ( F_1 ( V_2 , V_4 , V_6 , V_46 , V_10 ) < 0 ) {
F_23 ( & V_55 -> V_58 ) ;
goto V_68;
}
V_61:
V_47 ++ ;
}
F_23 ( & V_55 -> V_58 ) ;
}
V_68:
V_6 -> args [ 0 ] = V_49 ;
V_6 -> args [ 1 ] = V_47 ;
}
static void F_24 ( struct V_3 * V_4 , struct V_5 * V_6 ,
struct V_7 * V_46 , struct V_9 * V_10 )
{
F_17 ( & V_15 , V_4 , V_6 , V_46 , V_10 ) ;
}
static int F_25 ( struct V_3 * V_17 , const struct V_18 * V_12 ,
struct V_7 * V_8 )
{
return F_6 ( & V_15 , V_17 , V_12 , V_8 ) ;
}
static void F_26 ( struct V_1 * V_2 , struct V_39 * V_46 ,
void * V_69 )
{
V_46 -> V_70 = F_27 ( V_2 ) ;
V_46 -> V_71 = F_28 ( V_2 ) ;
}
static void F_29 ( struct V_3 * V_4 , struct V_5 * V_6 ,
struct V_7 * V_46 , struct V_9 * V_10 )
{
F_17 ( & V_72 , V_4 , V_6 , V_46 , V_10 ) ;
}
static int F_30 ( struct V_3 * V_17 , const struct V_18 * V_12 ,
struct V_7 * V_8 )
{
return F_6 ( & V_72 , V_17 , V_12 , V_8 ) ;
}
static int T_1 F_31 ( void )
{
int V_19 ;
V_19 = F_32 ( & V_73 ) ;
if ( V_19 )
goto V_37;
V_19 = F_32 ( & V_74 ) ;
if ( V_19 )
goto V_75;
V_37:
return V_19 ;
V_75:
F_33 ( & V_73 ) ;
goto V_37;
}
static void T_2 F_34 ( void )
{
F_33 ( & V_74 ) ;
F_33 ( & V_73 ) ;
}
