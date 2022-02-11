static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 ,
const struct V_7 * V_8 ,
struct V_9 * V_10 , bool V_11 )
{
if ( ! F_2 ( V_10 , V_2 ) )
return 0 ;
return F_3 ( V_2 , NULL , V_4 , V_8 ,
F_4 ( F_5 ( V_6 -> V_4 ) . V_2 ) ,
F_5 ( V_6 -> V_4 ) . V_12 ,
V_6 -> V_13 -> V_14 , V_15 , V_6 -> V_13 , V_11 ) ;
}
static int F_6 ( struct V_16 * V_17 , struct V_3 * V_18 ,
const struct V_19 * V_13 ,
const struct V_7 * V_8 )
{
int V_20 = - V_21 ;
struct V_1 * V_2 = NULL ;
struct V_3 * V_22 ;
struct V_23 * V_23 = F_7 ( V_18 -> V_2 ) ;
F_8 () ;
if ( V_8 -> V_24 == V_25 )
V_2 = F_9 ( V_23 ,
V_8 -> V_26 . V_27 [ 0 ] , V_8 -> V_26 . V_28 ,
V_8 -> V_26 . V_29 [ 0 ] , V_8 -> V_26 . V_30 ,
V_8 -> V_26 . V_31 , 0 , V_17 , NULL ) ;
#if F_10 ( V_32 )
else if ( V_8 -> V_24 == V_33 )
V_2 = F_11 ( V_23 ,
(struct V_34 * ) V_8 -> V_26 . V_27 ,
V_8 -> V_26 . V_28 ,
(struct V_34 * ) V_8 -> V_26 . V_29 ,
V_8 -> V_26 . V_30 ,
V_8 -> V_26 . V_31 , 0 , V_17 , NULL ) ;
#endif
if ( V_2 && ! F_12 ( & V_2 -> V_35 ) )
V_2 = NULL ;
F_13 () ;
V_20 = - V_36 ;
if ( ! V_2 )
goto V_37;
V_20 = F_14 ( V_2 , V_8 -> V_26 . V_38 ) ;
if ( V_20 )
goto V_39;
V_20 = - V_40 ;
V_22 = F_15 ( sizeof( struct V_41 ) +
sizeof( struct V_42 ) + 64 ,
V_43 ) ;
if ( ! V_22 )
goto V_39;
V_20 = F_3 ( V_2 , NULL , V_22 , V_8 ,
F_4 ( F_5 ( V_18 ) . V_2 ) ,
F_5 ( V_18 ) . V_12 ,
V_13 -> V_14 , 0 , V_13 ,
F_16 ( V_18 , V_44 ) ) ;
if ( V_20 < 0 ) {
F_17 ( V_20 == - V_45 ) ;
F_18 ( V_22 ) ;
goto V_39;
}
V_20 = F_19 ( V_23 -> V_46 , V_22 , F_5 ( V_18 ) . V_12 ,
V_47 ) ;
if ( V_20 > 0 )
V_20 = 0 ;
V_39:
if ( V_2 )
F_20 ( V_2 ) ;
V_37:
return V_20 ;
}
static void F_21 ( struct V_16 * V_48 , struct V_3 * V_4 ,
struct V_5 * V_6 ,
const struct V_7 * V_49 , struct V_9 * V_10 )
{
bool V_11 = F_16 ( V_6 -> V_4 , V_44 ) ;
struct V_23 * V_23 = F_7 ( V_4 -> V_2 ) ;
int V_50 , V_51 , V_52 , V_53 ;
V_53 = V_6 -> args [ 0 ] ;
V_50 = V_51 = V_6 -> args [ 1 ] ;
for ( V_52 = V_53 ; V_52 <= V_48 -> V_54 ; V_51 = 0 , V_52 ++ ) {
struct V_55 * V_56 = & V_48 -> V_57 [ V_52 ] ;
struct V_1 * V_2 ;
V_50 = 0 ;
if ( F_22 ( & V_56 -> V_58 ) )
continue;
F_23 ( & V_56 -> V_59 ) ;
F_24 (sk, &hslot->head) {
struct V_60 * V_61 = F_25 ( V_2 ) ;
if ( ! F_26 ( F_7 ( V_2 ) , V_23 ) )
continue;
if ( V_50 < V_51 )
goto V_62;
if ( ! ( V_49 -> V_63 & ( 1 << V_2 -> V_64 ) ) )
goto V_62;
if ( V_49 -> V_24 != V_65 &&
V_2 -> V_66 != V_49 -> V_24 )
goto V_62;
if ( V_49 -> V_26 . V_28 != V_61 -> V_67 &&
V_49 -> V_26 . V_28 )
goto V_62;
if ( V_49 -> V_26 . V_30 != V_61 -> V_68 &&
V_49 -> V_26 . V_30 )
goto V_62;
if ( F_1 ( V_2 , V_4 , V_6 , V_49 , V_10 , V_11 ) < 0 ) {
F_27 ( & V_56 -> V_59 ) ;
goto V_69;
}
V_62:
V_50 ++ ;
}
F_27 ( & V_56 -> V_59 ) ;
}
V_69:
V_6 -> args [ 0 ] = V_52 ;
V_6 -> args [ 1 ] = V_50 ;
}
static void F_28 ( struct V_3 * V_4 , struct V_5 * V_6 ,
const struct V_7 * V_49 , struct V_9 * V_10 )
{
F_21 ( & V_16 , V_4 , V_6 , V_49 , V_10 ) ;
}
static int F_29 ( struct V_3 * V_18 , const struct V_19 * V_13 ,
const struct V_7 * V_8 )
{
return F_6 ( & V_16 , V_18 , V_13 , V_8 ) ;
}
static void F_30 ( struct V_1 * V_2 , struct V_41 * V_49 ,
void * V_70 )
{
V_49 -> V_71 = F_31 ( V_2 ) ;
V_49 -> V_72 = F_32 ( V_2 ) ;
}
static int F_33 ( struct V_3 * V_18 ,
const struct V_7 * V_8 ,
struct V_16 * V_17 )
{
struct V_23 * V_23 = F_7 ( V_18 -> V_2 ) ;
struct V_1 * V_2 ;
int V_20 ;
F_8 () ;
if ( V_8 -> V_24 == V_25 )
V_2 = F_9 ( V_23 ,
V_8 -> V_26 . V_29 [ 0 ] , V_8 -> V_26 . V_30 ,
V_8 -> V_26 . V_27 [ 0 ] , V_8 -> V_26 . V_28 ,
V_8 -> V_26 . V_31 , 0 , V_17 , NULL ) ;
#if F_10 ( V_32 )
else if ( V_8 -> V_24 == V_33 ) {
if ( F_34 ( (struct V_34 * ) V_8 -> V_26 . V_29 ) &&
F_34 ( (struct V_34 * ) V_8 -> V_26 . V_27 ) )
V_2 = F_9 ( V_23 ,
V_8 -> V_26 . V_29 [ 3 ] , V_8 -> V_26 . V_30 ,
V_8 -> V_26 . V_27 [ 3 ] , V_8 -> V_26 . V_28 ,
V_8 -> V_26 . V_31 , 0 , V_17 , NULL ) ;
else
V_2 = F_11 ( V_23 ,
(struct V_34 * ) V_8 -> V_26 . V_29 ,
V_8 -> V_26 . V_30 ,
(struct V_34 * ) V_8 -> V_26 . V_27 ,
V_8 -> V_26 . V_28 ,
V_8 -> V_26 . V_31 , 0 , V_17 , NULL ) ;
}
#endif
else {
F_13 () ;
return - V_21 ;
}
if ( V_2 && ! F_12 ( & V_2 -> V_35 ) )
V_2 = NULL ;
F_13 () ;
if ( ! V_2 )
return - V_36 ;
if ( F_14 ( V_2 , V_8 -> V_26 . V_38 ) ) {
F_20 ( V_2 ) ;
return - V_36 ;
}
V_20 = F_35 ( V_2 , V_73 ) ;
F_20 ( V_2 ) ;
return V_20 ;
}
static int F_36 ( struct V_3 * V_18 ,
const struct V_7 * V_8 )
{
return F_33 ( V_18 , V_8 , & V_16 ) ;
}
static int F_37 ( struct V_3 * V_18 ,
const struct V_7 * V_8 )
{
return F_33 ( V_18 , V_8 , & V_74 ) ;
}
static void F_38 ( struct V_3 * V_4 , struct V_5 * V_6 ,
const struct V_7 * V_49 ,
struct V_9 * V_10 )
{
F_21 ( & V_74 , V_4 , V_6 , V_49 , V_10 ) ;
}
static int F_39 ( struct V_3 * V_18 , const struct V_19 * V_13 ,
const struct V_7 * V_8 )
{
return F_6 ( & V_74 , V_18 , V_13 , V_8 ) ;
}
static int T_1 F_40 ( void )
{
int V_20 ;
V_20 = F_41 ( & V_75 ) ;
if ( V_20 )
goto V_39;
V_20 = F_41 ( & V_76 ) ;
if ( V_20 )
goto V_77;
V_39:
return V_20 ;
V_77:
F_42 ( & V_75 ) ;
goto V_39;
}
static void T_2 F_43 ( void )
{
F_42 ( & V_76 ) ;
F_42 ( & V_75 ) ;
}
