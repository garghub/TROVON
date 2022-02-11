static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 ,
const struct V_7 * V_8 ,
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
const struct V_18 * V_12 ,
const struct V_7 * V_8 )
{
int V_19 = - V_20 ;
struct V_1 * V_2 = NULL ;
struct V_3 * V_21 ;
struct V_22 * V_22 = F_7 ( V_17 -> V_2 ) ;
F_8 () ;
if ( V_8 -> V_23 == V_24 )
V_2 = F_9 ( V_22 ,
V_8 -> V_25 . V_26 [ 0 ] , V_8 -> V_25 . V_27 ,
V_8 -> V_25 . V_28 [ 0 ] , V_8 -> V_25 . V_29 ,
V_8 -> V_25 . V_30 , V_16 , NULL ) ;
#if F_10 ( V_31 )
else if ( V_8 -> V_23 == V_32 )
V_2 = F_11 ( V_22 ,
(struct V_33 * ) V_8 -> V_25 . V_26 ,
V_8 -> V_25 . V_27 ,
(struct V_33 * ) V_8 -> V_25 . V_28 ,
V_8 -> V_25 . V_29 ,
V_8 -> V_25 . V_30 , V_16 , NULL ) ;
#endif
if ( V_2 && ! F_12 ( & V_2 -> V_34 ) )
V_2 = NULL ;
F_13 () ;
V_19 = - V_35 ;
if ( ! V_2 )
goto V_36;
V_19 = F_14 ( V_2 , V_8 -> V_25 . V_37 ) ;
if ( V_19 )
goto V_38;
V_19 = - V_39 ;
V_21 = F_15 ( sizeof( struct V_40 ) +
sizeof( struct V_41 ) + 64 ,
V_42 ) ;
if ( ! V_21 )
goto V_38;
V_19 = F_3 ( V_2 , NULL , V_21 , V_8 ,
F_4 ( F_5 ( V_17 ) . V_2 ) ,
F_5 ( V_17 ) . V_11 ,
V_12 -> V_13 , 0 , V_12 ) ;
if ( V_19 < 0 ) {
F_16 ( V_19 == - V_43 ) ;
F_17 ( V_21 ) ;
goto V_38;
}
V_19 = F_18 ( V_22 -> V_44 , V_21 , F_5 ( V_17 ) . V_11 ,
V_45 ) ;
if ( V_19 > 0 )
V_19 = 0 ;
V_38:
if ( V_2 )
F_19 ( V_2 ) ;
V_36:
return V_19 ;
}
static void F_20 ( struct V_15 * V_46 , struct V_3 * V_4 ,
struct V_5 * V_6 ,
const struct V_7 * V_47 , struct V_9 * V_10 )
{
struct V_22 * V_22 = F_7 ( V_4 -> V_2 ) ;
int V_48 , V_49 , V_50 , V_51 ;
V_51 = V_6 -> args [ 0 ] ;
V_48 = V_49 = V_6 -> args [ 1 ] ;
for ( V_50 = V_51 ; V_50 <= V_46 -> V_52 ; V_49 = 0 , V_50 ++ ) {
struct V_53 * V_54 = & V_46 -> V_55 [ V_50 ] ;
struct V_1 * V_2 ;
V_48 = 0 ;
if ( F_21 ( & V_54 -> V_56 ) )
continue;
F_22 ( & V_54 -> V_57 ) ;
F_23 (sk, &hslot->head) {
struct V_58 * V_59 = F_24 ( V_2 ) ;
if ( ! F_25 ( F_7 ( V_2 ) , V_22 ) )
continue;
if ( V_48 < V_49 )
goto V_60;
if ( ! ( V_47 -> V_61 & ( 1 << V_2 -> V_62 ) ) )
goto V_60;
if ( V_47 -> V_23 != V_63 &&
V_2 -> V_64 != V_47 -> V_23 )
goto V_60;
if ( V_47 -> V_25 . V_27 != V_59 -> V_65 &&
V_47 -> V_25 . V_27 )
goto V_60;
if ( V_47 -> V_25 . V_29 != V_59 -> V_66 &&
V_47 -> V_25 . V_29 )
goto V_60;
if ( F_1 ( V_2 , V_4 , V_6 , V_47 , V_10 ) < 0 ) {
F_26 ( & V_54 -> V_57 ) ;
goto V_67;
}
V_60:
V_48 ++ ;
}
F_26 ( & V_54 -> V_57 ) ;
}
V_67:
V_6 -> args [ 0 ] = V_50 ;
V_6 -> args [ 1 ] = V_48 ;
}
static void F_27 ( struct V_3 * V_4 , struct V_5 * V_6 ,
const struct V_7 * V_47 , struct V_9 * V_10 )
{
F_20 ( & V_15 , V_4 , V_6 , V_47 , V_10 ) ;
}
static int F_28 ( struct V_3 * V_17 , const struct V_18 * V_12 ,
const struct V_7 * V_8 )
{
return F_6 ( & V_15 , V_17 , V_12 , V_8 ) ;
}
static void F_29 ( struct V_1 * V_2 , struct V_40 * V_47 ,
void * V_68 )
{
V_47 -> V_69 = F_30 ( V_2 ) ;
V_47 -> V_70 = F_31 ( V_2 ) ;
}
static void F_32 ( struct V_3 * V_4 , struct V_5 * V_6 ,
const struct V_7 * V_47 ,
struct V_9 * V_10 )
{
F_20 ( & V_71 , V_4 , V_6 , V_47 , V_10 ) ;
}
static int F_33 ( struct V_3 * V_17 , const struct V_18 * V_12 ,
const struct V_7 * V_8 )
{
return F_6 ( & V_71 , V_17 , V_12 , V_8 ) ;
}
static int T_1 F_34 ( void )
{
int V_19 ;
V_19 = F_35 ( & V_72 ) ;
if ( V_19 )
goto V_38;
V_19 = F_35 ( & V_73 ) ;
if ( V_19 )
goto V_74;
V_38:
return V_19 ;
V_74:
F_36 ( & V_72 ) ;
goto V_38;
}
static void T_2 F_37 ( void )
{
F_36 ( & V_73 ) ;
F_36 ( & V_72 ) ;
}
