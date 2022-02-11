static int F_1 ( struct V_1 * V_2 , const struct V_3 * V_4 ,
struct V_5 * V_6 )
{
int V_7 ;
struct V_8 * V_9 = (struct V_8 * ) V_4 -> V_10 ;
struct V_11 * V_12 ;
F_2 (f, &head->flist, link) {
if ( ! F_3 ( V_2 , & V_12 -> V_13 , NULL ) )
continue;
* V_6 = V_12 -> V_6 ;
V_7 = F_4 ( V_2 , & V_12 -> V_14 , V_6 ) ;
if ( V_7 < 0 )
continue;
return V_7 ;
}
return - 1 ;
}
static unsigned long F_5 ( struct V_3 * V_4 , T_1 V_15 )
{
unsigned long V_16 = 0UL ;
struct V_8 * V_9 = (struct V_8 * ) V_4 -> V_10 ;
struct V_11 * V_12 ;
if ( V_9 == NULL )
return 0UL ;
F_2 (f, &head->flist, link)
if ( V_12 -> V_15 == V_15 )
V_16 = ( unsigned long ) V_12 ;
return V_16 ;
}
static void F_6 ( struct V_3 * V_4 , unsigned long V_12 )
{
}
static int F_7 ( struct V_3 * V_4 )
{
struct V_8 * V_9 ;
V_9 = F_8 ( sizeof( * V_9 ) , V_17 ) ;
if ( V_9 == NULL )
return - V_18 ;
F_9 ( & V_9 -> V_19 ) ;
V_4 -> V_10 = V_9 ;
return 0 ;
}
static void F_10 ( struct V_3 * V_4 , struct V_11 * V_12 )
{
F_11 ( V_4 , & V_12 -> V_6 ) ;
F_12 ( V_4 , & V_12 -> V_14 ) ;
F_13 ( V_4 , & V_12 -> V_13 ) ;
F_14 ( V_12 ) ;
}
static void F_15 ( struct V_3 * V_4 )
{
struct V_8 * V_9 = V_4 -> V_10 ;
struct V_11 * V_12 , * V_20 ;
F_16 (f, n, &head->flist, link) {
F_17 ( & V_12 -> V_21 ) ;
F_10 ( V_4 , V_12 ) ;
}
F_14 ( V_9 ) ;
}
static int F_18 ( struct V_3 * V_4 , unsigned long V_22 )
{
struct V_8 * V_9 = (struct V_8 * ) V_4 -> V_10 ;
struct V_11 * V_23 , * V_12 = (struct V_11 * ) V_22 ;
F_2 (t, &head->flist, link)
if ( V_23 == V_12 ) {
F_19 ( V_4 ) ;
F_17 ( & V_23 -> V_21 ) ;
F_20 ( V_4 ) ;
F_10 ( V_4 , V_23 ) ;
return 0 ;
}
return - V_24 ;
}
static int F_21 ( struct V_25 * V_25 , struct V_3 * V_4 ,
struct V_11 * V_12 , unsigned long V_26 ,
struct V_27 * * V_28 ,
struct V_27 * V_29 )
{
int V_30 ;
struct V_31 V_32 ;
struct V_33 V_23 ;
V_30 = F_22 ( V_25 , V_4 , V_28 , V_29 , & V_32 , & V_34 ) ;
if ( V_30 < 0 )
return V_30 ;
V_30 = F_23 ( V_4 , V_28 [ V_35 ] , & V_23 ) ;
if ( V_30 < 0 )
goto V_36;
if ( V_28 [ V_37 ] ) {
V_12 -> V_6 . V_38 = F_24 ( V_28 [ V_37 ] ) ;
F_25 ( V_4 , & V_12 -> V_6 , V_26 ) ;
}
F_26 ( V_4 , & V_12 -> V_14 , & V_32 ) ;
F_27 ( V_4 , & V_12 -> V_13 , & V_23 ) ;
return 0 ;
V_36:
F_12 ( V_4 , & V_32 ) ;
return V_30 ;
}
static int F_28 ( struct V_25 * V_25 , struct V_1 * V_39 ,
struct V_3 * V_4 , unsigned long V_26 , T_1 V_15 ,
struct V_27 * * V_40 , unsigned long * V_22 )
{
int V_30 ;
struct V_8 * V_9 = (struct V_8 * ) V_4 -> V_10 ;
struct V_27 * V_28 [ V_41 + 1 ] ;
struct V_11 * V_12 = (struct V_11 * ) * V_22 ;
if ( V_40 [ V_42 ] == NULL )
return - V_43 ;
V_30 = F_29 ( V_28 , V_41 , V_40 [ V_42 ] ,
V_44 ) ;
if ( V_30 < 0 )
return V_30 ;
if ( V_12 != NULL ) {
if ( V_15 && V_12 -> V_15 != V_15 )
return - V_43 ;
return F_21 ( V_25 , V_4 , V_12 , V_26 , V_28 , V_40 [ V_45 ] ) ;
}
V_30 = - V_18 ;
V_12 = F_8 ( sizeof( * V_12 ) , V_17 ) ;
if ( V_12 == NULL )
goto V_36;
V_30 = - V_43 ;
if ( V_15 )
V_12 -> V_15 = V_15 ;
else {
unsigned int V_46 = 0x80000000 ;
do {
if ( ++ V_9 -> V_47 == 0x7FFFFFFF )
V_9 -> V_47 = 1 ;
} while ( -- V_46 > 0 && F_5 ( V_4 , V_9 -> V_47 ) );
if ( V_46 <= 0 ) {
F_30 ( L_1 ) ;
goto V_36;
}
V_12 -> V_15 = V_9 -> V_47 ;
}
V_30 = F_21 ( V_25 , V_4 , V_12 , V_26 , V_28 , V_40 [ V_45 ] ) ;
if ( V_30 < 0 )
goto V_36;
F_19 ( V_4 ) ;
F_31 ( & V_12 -> V_21 , & V_9 -> V_19 ) ;
F_20 ( V_4 ) ;
* V_22 = ( unsigned long ) V_12 ;
return 0 ;
V_36:
if ( * V_22 == 0UL && V_12 )
F_14 ( V_12 ) ;
return V_30 ;
}
static void F_32 ( struct V_3 * V_4 , struct V_48 * V_22 )
{
struct V_8 * V_9 = (struct V_8 * ) V_4 -> V_10 ;
struct V_11 * V_12 ;
F_2 (f, &head->flist, link) {
if ( V_22 -> V_49 < V_22 -> V_50 )
goto V_50;
if ( V_22 -> V_51 ( V_4 , ( unsigned long ) V_12 , V_22 ) < 0 ) {
V_22 -> V_52 = 1 ;
break;
}
V_50:
V_22 -> V_49 ++ ;
}
}
static int F_33 ( struct V_3 * V_4 , unsigned long V_53 ,
struct V_1 * V_2 , struct V_54 * V_23 )
{
struct V_11 * V_12 = (struct V_11 * ) V_53 ;
struct V_27 * V_55 ;
if ( V_12 == NULL )
return V_2 -> V_56 ;
V_23 -> V_57 = V_12 -> V_15 ;
V_55 = F_34 ( V_2 , V_42 ) ;
if ( V_55 == NULL )
goto V_58;
if ( V_12 -> V_6 . V_38 &&
F_35 ( V_2 , V_37 , V_12 -> V_6 . V_38 ) )
goto V_58;
if ( F_36 ( V_2 , & V_12 -> V_14 , & V_34 ) < 0 ||
F_37 ( V_2 , & V_12 -> V_13 , V_35 ) < 0 )
goto V_58;
F_38 ( V_2 , V_55 ) ;
if ( F_39 ( V_2 , & V_12 -> V_14 , & V_34 ) < 0 )
goto V_58;
return V_2 -> V_56 ;
V_58:
F_40 ( V_2 , V_55 ) ;
return - 1 ;
}
static int T_2 F_41 ( void )
{
return F_42 ( & V_59 ) ;
}
static void T_3 F_43 ( void )
{
F_44 ( & V_59 ) ;
}
