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
static void F_9 ( struct V_3 * V_4 , unsigned long V_12 )
{
}
static int F_10 ( struct V_3 * V_4 )
{
struct V_8 * V_9 ;
V_9 = F_11 ( sizeof( * V_9 ) , V_17 ) ;
if ( V_9 == NULL )
return - V_18 ;
F_12 ( & V_9 -> V_19 ) ;
F_13 ( V_4 -> V_10 , V_9 ) ;
return 0 ;
}
static void F_14 ( struct V_20 * V_9 )
{
struct V_11 * V_12 = F_15 ( V_9 , struct V_11 , V_21 ) ;
F_16 ( & V_12 -> V_14 ) ;
F_17 ( & V_12 -> V_13 ) ;
F_18 ( V_12 ) ;
}
static void F_19 ( struct V_3 * V_4 )
{
struct V_8 * V_9 = F_7 ( V_4 -> V_10 ) ;
struct V_11 * V_12 , * V_22 ;
F_20 (f, n, &head->flist, link) {
F_21 ( & V_12 -> V_23 ) ;
F_22 ( V_4 , & V_12 -> V_6 ) ;
F_23 ( & V_12 -> V_21 , F_14 ) ;
}
F_24 ( V_4 -> V_10 , NULL ) ;
F_25 ( V_9 , V_21 ) ;
}
static int F_26 ( struct V_3 * V_4 , unsigned long V_24 )
{
struct V_8 * V_9 = F_7 ( V_4 -> V_10 ) ;
struct V_11 * V_25 , * V_12 = (struct V_11 * ) V_24 ;
F_8 (t, &head->flist, link)
if ( V_25 == V_12 ) {
F_21 ( & V_25 -> V_23 ) ;
F_22 ( V_4 , & V_25 -> V_6 ) ;
F_23 ( & V_25 -> V_21 , F_14 ) ;
return 0 ;
}
return - V_26 ;
}
static int F_27 ( struct V_27 * V_27 , struct V_3 * V_4 ,
struct V_11 * V_12 , unsigned long V_28 ,
struct V_29 * * V_30 ,
struct V_29 * V_31 , bool V_32 )
{
int V_33 ;
struct V_34 V_35 ;
struct V_36 V_25 ;
F_28 ( & V_35 , V_37 , V_38 ) ;
V_33 = F_29 ( V_27 , V_4 , V_30 , V_31 , & V_35 , V_32 ) ;
if ( V_33 < 0 )
return V_33 ;
V_33 = F_30 ( V_4 , V_30 [ V_39 ] , & V_25 ) ;
if ( V_33 < 0 )
goto V_40;
if ( V_30 [ V_41 ] ) {
V_12 -> V_6 . V_42 = F_31 ( V_30 [ V_41 ] ) ;
F_32 ( V_4 , & V_12 -> V_6 , V_28 ) ;
}
F_33 ( V_4 , & V_12 -> V_14 , & V_35 ) ;
F_34 ( V_4 , & V_12 -> V_13 , & V_25 ) ;
V_12 -> V_4 = V_4 ;
return 0 ;
V_40:
F_16 ( & V_35 ) ;
return V_33 ;
}
static int F_35 ( struct V_27 * V_27 , struct V_1 * V_43 ,
struct V_3 * V_4 , unsigned long V_28 , T_1 V_15 ,
struct V_29 * * V_44 , unsigned long * V_24 , bool V_32 )
{
int V_33 ;
struct V_8 * V_9 = F_7 ( V_4 -> V_10 ) ;
struct V_29 * V_30 [ V_45 + 1 ] ;
struct V_11 * V_46 = (struct V_11 * ) * V_24 ;
struct V_11 * V_47 ;
if ( V_44 [ V_48 ] == NULL )
return - V_49 ;
V_33 = F_36 ( V_30 , V_45 , V_44 [ V_48 ] ,
V_50 ) ;
if ( V_33 < 0 )
return V_33 ;
if ( V_46 != NULL ) {
if ( V_15 && V_46 -> V_15 != V_15 )
return - V_49 ;
}
V_33 = - V_18 ;
V_47 = F_11 ( sizeof( * V_47 ) , V_17 ) ;
if ( V_47 == NULL )
goto V_40;
F_28 ( & V_47 -> V_14 , V_37 , V_38 ) ;
V_33 = - V_49 ;
if ( V_15 ) {
V_47 -> V_15 = V_15 ;
} else if ( V_46 ) {
V_47 -> V_15 = V_46 -> V_15 ;
} else {
unsigned int V_51 = 0x80000000 ;
do {
if ( ++ V_9 -> V_52 == 0x7FFFFFFF )
V_9 -> V_52 = 1 ;
} while ( -- V_51 > 0 && F_6 ( V_4 , V_9 -> V_52 ) );
if ( V_51 <= 0 ) {
F_37 ( L_1 ) ;
goto V_40;
}
V_47 -> V_15 = V_9 -> V_52 ;
}
V_33 = F_27 ( V_27 , V_4 , V_47 , V_28 , V_30 , V_44 [ V_53 ] , V_32 ) ;
if ( V_33 < 0 )
goto V_40;
* V_24 = ( unsigned long ) V_47 ;
if ( V_46 ) {
F_38 ( & V_46 -> V_23 , & V_47 -> V_23 ) ;
F_22 ( V_4 , & V_46 -> V_6 ) ;
F_23 ( & V_46 -> V_21 , F_14 ) ;
} else {
F_39 ( & V_47 -> V_23 , & V_9 -> V_19 ) ;
}
return 0 ;
V_40:
F_18 ( V_47 ) ;
return V_33 ;
}
static void F_40 ( struct V_3 * V_4 , struct V_54 * V_24 )
{
struct V_8 * V_9 = F_7 ( V_4 -> V_10 ) ;
struct V_11 * V_12 ;
F_8 (f, &head->flist, link) {
if ( V_24 -> V_55 < V_24 -> V_56 )
goto V_56;
if ( V_24 -> V_57 ( V_4 , ( unsigned long ) V_12 , V_24 ) < 0 ) {
V_24 -> V_58 = 1 ;
break;
}
V_56:
V_24 -> V_55 ++ ;
}
}
static int F_41 ( struct V_27 * V_27 , struct V_3 * V_4 , unsigned long V_59 ,
struct V_1 * V_2 , struct V_60 * V_25 )
{
struct V_11 * V_12 = (struct V_11 * ) V_59 ;
struct V_29 * V_61 ;
if ( V_12 == NULL )
return V_2 -> V_62 ;
V_25 -> V_63 = V_12 -> V_15 ;
V_61 = F_42 ( V_2 , V_48 ) ;
if ( V_61 == NULL )
goto V_64;
if ( V_12 -> V_6 . V_42 &&
F_43 ( V_2 , V_41 , V_12 -> V_6 . V_42 ) )
goto V_64;
if ( F_44 ( V_2 , & V_12 -> V_14 ) < 0 ||
F_45 ( V_2 , & V_12 -> V_13 , V_39 ) < 0 )
goto V_64;
F_46 ( V_2 , V_61 ) ;
if ( F_47 ( V_2 , & V_12 -> V_14 ) < 0 )
goto V_64;
return V_2 -> V_62 ;
V_64:
F_48 ( V_2 , V_61 ) ;
return - 1 ;
}
static int T_2 F_49 ( void )
{
return F_50 ( & V_65 ) ;
}
static void T_3 F_51 ( void )
{
F_52 ( & V_65 ) ;
}
