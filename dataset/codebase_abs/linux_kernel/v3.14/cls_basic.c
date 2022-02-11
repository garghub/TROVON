static int F_1 ( struct V_1 * V_2 , const struct V_3 * V_4 ,
struct V_5 * V_6 )
{
int V_7 ;
struct V_8 * V_9 = V_4 -> V_10 ;
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
struct V_8 * V_9 = V_4 -> V_10 ;
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
struct V_8 * V_9 = V_4 -> V_10 ;
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
F_22 ( & V_32 , V_34 , V_35 ) ;
V_30 = F_23 ( V_25 , V_4 , V_28 , V_29 , & V_32 ) ;
if ( V_30 < 0 )
return V_30 ;
V_30 = F_24 ( V_4 , V_28 [ V_36 ] , & V_23 ) ;
if ( V_30 < 0 )
goto V_37;
if ( V_28 [ V_38 ] ) {
V_12 -> V_6 . V_39 = F_25 ( V_28 [ V_38 ] ) ;
F_26 ( V_4 , & V_12 -> V_6 , V_26 ) ;
}
F_27 ( V_4 , & V_12 -> V_14 , & V_32 ) ;
F_28 ( V_4 , & V_12 -> V_13 , & V_23 ) ;
return 0 ;
V_37:
F_12 ( V_4 , & V_32 ) ;
return V_30 ;
}
static int F_29 ( struct V_25 * V_25 , struct V_1 * V_40 ,
struct V_3 * V_4 , unsigned long V_26 , T_1 V_15 ,
struct V_27 * * V_41 , unsigned long * V_22 )
{
int V_30 ;
struct V_8 * V_9 = V_4 -> V_10 ;
struct V_27 * V_28 [ V_42 + 1 ] ;
struct V_11 * V_12 = (struct V_11 * ) * V_22 ;
if ( V_41 [ V_43 ] == NULL )
return - V_44 ;
V_30 = F_30 ( V_28 , V_42 , V_41 [ V_43 ] ,
V_45 ) ;
if ( V_30 < 0 )
return V_30 ;
if ( V_12 != NULL ) {
if ( V_15 && V_12 -> V_15 != V_15 )
return - V_44 ;
return F_21 ( V_25 , V_4 , V_12 , V_26 , V_28 , V_41 [ V_46 ] ) ;
}
V_30 = - V_18 ;
V_12 = F_8 ( sizeof( * V_12 ) , V_17 ) ;
if ( V_12 == NULL )
goto V_37;
F_22 ( & V_12 -> V_14 , V_34 , V_35 ) ;
V_30 = - V_44 ;
if ( V_15 )
V_12 -> V_15 = V_15 ;
else {
unsigned int V_47 = 0x80000000 ;
do {
if ( ++ V_9 -> V_48 == 0x7FFFFFFF )
V_9 -> V_48 = 1 ;
} while ( -- V_47 > 0 && F_5 ( V_4 , V_9 -> V_48 ) );
if ( V_47 <= 0 ) {
F_31 ( L_1 ) ;
goto V_37;
}
V_12 -> V_15 = V_9 -> V_48 ;
}
V_30 = F_21 ( V_25 , V_4 , V_12 , V_26 , V_28 , V_41 [ V_46 ] ) ;
if ( V_30 < 0 )
goto V_37;
F_19 ( V_4 ) ;
F_32 ( & V_12 -> V_21 , & V_9 -> V_19 ) ;
F_20 ( V_4 ) ;
* V_22 = ( unsigned long ) V_12 ;
return 0 ;
V_37:
if ( * V_22 == 0UL && V_12 )
F_14 ( V_12 ) ;
return V_30 ;
}
static void F_33 ( struct V_3 * V_4 , struct V_49 * V_22 )
{
struct V_8 * V_9 = V_4 -> V_10 ;
struct V_11 * V_12 ;
F_2 (f, &head->flist, link) {
if ( V_22 -> V_50 < V_22 -> V_51 )
goto V_51;
if ( V_22 -> V_52 ( V_4 , ( unsigned long ) V_12 , V_22 ) < 0 ) {
V_22 -> V_53 = 1 ;
break;
}
V_51:
V_22 -> V_50 ++ ;
}
}
static int F_34 ( struct V_25 * V_25 , struct V_3 * V_4 , unsigned long V_54 ,
struct V_1 * V_2 , struct V_55 * V_23 )
{
struct V_11 * V_12 = (struct V_11 * ) V_54 ;
struct V_27 * V_56 ;
if ( V_12 == NULL )
return V_2 -> V_57 ;
V_23 -> V_58 = V_12 -> V_15 ;
V_56 = F_35 ( V_2 , V_43 ) ;
if ( V_56 == NULL )
goto V_59;
if ( V_12 -> V_6 . V_39 &&
F_36 ( V_2 , V_38 , V_12 -> V_6 . V_39 ) )
goto V_59;
if ( F_37 ( V_2 , & V_12 -> V_14 ) < 0 ||
F_38 ( V_2 , & V_12 -> V_13 , V_36 ) < 0 )
goto V_59;
F_39 ( V_2 , V_56 ) ;
if ( F_40 ( V_2 , & V_12 -> V_14 ) < 0 )
goto V_59;
return V_2 -> V_57 ;
V_59:
F_41 ( V_2 , V_56 ) ;
return - 1 ;
}
static int T_2 F_42 ( void )
{
return F_43 ( & V_60 ) ;
}
static void T_3 F_44 ( void )
{
F_45 ( & V_60 ) ;
}
