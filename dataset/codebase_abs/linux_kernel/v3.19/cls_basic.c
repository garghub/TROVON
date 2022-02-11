static int F_1 ( struct V_1 * V_2 , const struct V_3 * V_4 ,
struct V_5 * V_6 )
{
int V_7 ;
struct V_8 * V_9 = F_2 ( V_4 -> V_10 ) ;
struct V_11 * V_12 ;
F_3 (f, &head->flist, link) {
if ( ! F_4 ( V_2 , & V_12 -> V_13 , NULL ) )
continue;
* V_6 = V_12 -> V_6 ;
V_7 = F_5 ( V_2 , & V_12 -> V_14 , V_6 ) ;
if ( V_7 < 0 )
continue;
return V_7 ;
}
return - 1 ;
}
static unsigned long F_6 ( struct V_3 * V_4 , T_1 V_15 )
{
unsigned long V_16 = 0UL ;
struct V_8 * V_9 = F_7 ( V_4 -> V_10 ) ;
struct V_11 * V_12 ;
if ( V_9 == NULL )
return 0UL ;
F_8 (f, &head->flist, link)
if ( V_12 -> V_15 == V_15 )
V_16 = ( unsigned long ) V_12 ;
return V_16 ;
}
static int F_9 ( struct V_3 * V_4 )
{
struct V_8 * V_9 ;
V_9 = F_10 ( sizeof( * V_9 ) , V_17 ) ;
if ( V_9 == NULL )
return - V_18 ;
F_11 ( & V_9 -> V_19 ) ;
F_12 ( V_4 -> V_10 , V_9 ) ;
return 0 ;
}
static void F_13 ( struct V_20 * V_9 )
{
struct V_11 * V_12 = F_14 ( V_9 , struct V_11 , V_21 ) ;
F_15 ( & V_12 -> V_14 ) ;
F_16 ( & V_12 -> V_13 ) ;
F_17 ( V_12 ) ;
}
static void F_18 ( struct V_3 * V_4 )
{
struct V_8 * V_9 = F_7 ( V_4 -> V_10 ) ;
struct V_11 * V_12 , * V_22 ;
F_19 (f, n, &head->flist, link) {
F_20 ( & V_12 -> V_23 ) ;
F_21 ( V_4 , & V_12 -> V_6 ) ;
F_22 ( & V_12 -> V_21 , F_13 ) ;
}
F_23 ( V_4 -> V_10 , NULL ) ;
F_24 ( V_9 , V_21 ) ;
}
static int F_25 ( struct V_3 * V_4 , unsigned long V_24 )
{
struct V_11 * V_12 = (struct V_11 * ) V_24 ;
F_20 ( & V_12 -> V_23 ) ;
F_21 ( V_4 , & V_12 -> V_6 ) ;
F_22 ( & V_12 -> V_21 , F_13 ) ;
return 0 ;
}
static int F_26 ( struct V_25 * V_25 , struct V_3 * V_4 ,
struct V_11 * V_12 , unsigned long V_26 ,
struct V_27 * * V_28 ,
struct V_27 * V_29 , bool V_30 )
{
int V_31 ;
struct V_32 V_33 ;
struct V_34 V_35 ;
F_27 ( & V_33 , V_36 , V_37 ) ;
V_31 = F_28 ( V_25 , V_4 , V_28 , V_29 , & V_33 , V_30 ) ;
if ( V_31 < 0 )
return V_31 ;
V_31 = F_29 ( V_4 , V_28 [ V_38 ] , & V_35 ) ;
if ( V_31 < 0 )
goto V_39;
if ( V_28 [ V_40 ] ) {
V_12 -> V_6 . V_41 = F_30 ( V_28 [ V_40 ] ) ;
F_31 ( V_4 , & V_12 -> V_6 , V_26 ) ;
}
F_32 ( V_4 , & V_12 -> V_14 , & V_33 ) ;
F_33 ( V_4 , & V_12 -> V_13 , & V_35 ) ;
V_12 -> V_4 = V_4 ;
return 0 ;
V_39:
F_15 ( & V_33 ) ;
return V_31 ;
}
static int F_34 ( struct V_25 * V_25 , struct V_1 * V_42 ,
struct V_3 * V_4 , unsigned long V_26 , T_1 V_15 ,
struct V_27 * * V_43 , unsigned long * V_24 , bool V_30 )
{
int V_31 ;
struct V_8 * V_9 = F_7 ( V_4 -> V_10 ) ;
struct V_27 * V_28 [ V_44 + 1 ] ;
struct V_11 * V_45 = (struct V_11 * ) * V_24 ;
struct V_11 * V_46 ;
if ( V_43 [ V_47 ] == NULL )
return - V_48 ;
V_31 = F_35 ( V_28 , V_44 , V_43 [ V_47 ] ,
V_49 ) ;
if ( V_31 < 0 )
return V_31 ;
if ( V_45 != NULL ) {
if ( V_15 && V_45 -> V_15 != V_15 )
return - V_48 ;
}
V_46 = F_10 ( sizeof( * V_46 ) , V_17 ) ;
if ( ! V_46 )
return - V_18 ;
F_27 ( & V_46 -> V_14 , V_36 , V_37 ) ;
V_31 = - V_48 ;
if ( V_15 ) {
V_46 -> V_15 = V_15 ;
} else if ( V_45 ) {
V_46 -> V_15 = V_45 -> V_15 ;
} else {
unsigned int V_50 = 0x80000000 ;
do {
if ( ++ V_9 -> V_51 == 0x7FFFFFFF )
V_9 -> V_51 = 1 ;
} while ( -- V_50 > 0 && F_6 ( V_4 , V_9 -> V_51 ) );
if ( V_50 <= 0 ) {
F_36 ( L_1 ) ;
goto V_39;
}
V_46 -> V_15 = V_9 -> V_51 ;
}
V_31 = F_26 ( V_25 , V_4 , V_46 , V_26 , V_28 , V_43 [ V_52 ] , V_30 ) ;
if ( V_31 < 0 )
goto V_39;
* V_24 = ( unsigned long ) V_46 ;
if ( V_45 ) {
F_37 ( & V_45 -> V_23 , & V_46 -> V_23 ) ;
F_21 ( V_4 , & V_45 -> V_6 ) ;
F_22 ( & V_45 -> V_21 , F_13 ) ;
} else {
F_38 ( & V_46 -> V_23 , & V_9 -> V_19 ) ;
}
return 0 ;
V_39:
F_17 ( V_46 ) ;
return V_31 ;
}
static void F_39 ( struct V_3 * V_4 , struct V_53 * V_24 )
{
struct V_8 * V_9 = F_7 ( V_4 -> V_10 ) ;
struct V_11 * V_12 ;
F_8 (f, &head->flist, link) {
if ( V_24 -> V_54 < V_24 -> V_55 )
goto V_55;
if ( V_24 -> V_56 ( V_4 , ( unsigned long ) V_12 , V_24 ) < 0 ) {
V_24 -> V_57 = 1 ;
break;
}
V_55:
V_24 -> V_54 ++ ;
}
}
static int F_40 ( struct V_25 * V_25 , struct V_3 * V_4 , unsigned long V_58 ,
struct V_1 * V_2 , struct V_59 * V_35 )
{
struct V_11 * V_12 = (struct V_11 * ) V_58 ;
struct V_27 * V_60 ;
if ( V_12 == NULL )
return V_2 -> V_61 ;
V_35 -> V_62 = V_12 -> V_15 ;
V_60 = F_41 ( V_2 , V_47 ) ;
if ( V_60 == NULL )
goto V_63;
if ( V_12 -> V_6 . V_41 &&
F_42 ( V_2 , V_40 , V_12 -> V_6 . V_41 ) )
goto V_63;
if ( F_43 ( V_2 , & V_12 -> V_14 ) < 0 ||
F_44 ( V_2 , & V_12 -> V_13 , V_38 ) < 0 )
goto V_63;
F_45 ( V_2 , V_60 ) ;
if ( F_46 ( V_2 , & V_12 -> V_14 ) < 0 )
goto V_63;
return V_2 -> V_61 ;
V_63:
F_47 ( V_2 , V_60 ) ;
return - 1 ;
}
static int T_2 F_48 ( void )
{
return F_49 ( & V_64 ) ;
}
static void T_3 F_50 ( void )
{
F_51 ( & V_64 ) ;
}
