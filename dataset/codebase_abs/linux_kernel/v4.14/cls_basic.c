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
static void * F_6 ( struct V_3 * V_4 , T_1 V_15 )
{
struct V_8 * V_9 = F_7 ( V_4 -> V_10 ) ;
struct V_11 * V_12 ;
F_8 (f, &head->flist, link) {
if ( V_12 -> V_15 == V_15 ) {
return V_12 ;
}
}
return NULL ;
}
static int F_9 ( struct V_3 * V_4 )
{
struct V_8 * V_9 ;
V_9 = F_10 ( sizeof( * V_9 ) , V_16 ) ;
if ( V_9 == NULL )
return - V_17 ;
F_11 ( & V_9 -> V_18 ) ;
F_12 ( V_4 -> V_10 , V_9 ) ;
return 0 ;
}
static void F_13 ( struct V_11 * V_12 )
{
F_14 ( & V_12 -> V_14 ) ;
F_15 ( & V_12 -> V_13 ) ;
F_16 ( & V_12 -> V_14 ) ;
F_17 ( V_12 ) ;
}
static void F_18 ( struct V_19 * V_20 )
{
struct V_11 * V_12 = F_19 ( V_20 , struct V_11 , V_20 ) ;
F_20 () ;
F_13 ( V_12 ) ;
F_21 () ;
}
static void F_22 ( struct V_21 * V_9 )
{
struct V_11 * V_12 = F_19 ( V_9 , struct V_11 , V_22 ) ;
F_23 ( & V_12 -> V_20 , F_18 ) ;
F_24 ( & V_12 -> V_20 ) ;
}
static void F_25 ( struct V_3 * V_4 )
{
struct V_8 * V_9 = F_7 ( V_4 -> V_10 ) ;
struct V_11 * V_12 , * V_23 ;
F_26 (f, n, &head->flist, link) {
F_27 ( & V_12 -> V_24 ) ;
F_28 ( V_4 , & V_12 -> V_6 ) ;
if ( F_29 ( & V_12 -> V_14 ) )
F_30 ( & V_12 -> V_22 , F_22 ) ;
else
F_13 ( V_12 ) ;
}
F_31 ( V_9 , V_22 ) ;
}
static int F_32 ( struct V_3 * V_4 , void * V_25 , bool * V_26 )
{
struct V_8 * V_9 = F_7 ( V_4 -> V_10 ) ;
struct V_11 * V_12 = V_25 ;
F_27 ( & V_12 -> V_24 ) ;
F_28 ( V_4 , & V_12 -> V_6 ) ;
F_29 ( & V_12 -> V_14 ) ;
F_30 ( & V_12 -> V_22 , F_22 ) ;
* V_26 = F_33 ( & V_9 -> V_18 ) ;
return 0 ;
}
static int F_34 ( struct V_27 * V_27 , struct V_3 * V_4 ,
struct V_11 * V_12 , unsigned long V_28 ,
struct V_29 * * V_30 ,
struct V_29 * V_31 , bool V_32 )
{
int V_33 ;
V_33 = F_35 ( V_27 , V_4 , V_30 , V_31 , & V_12 -> V_14 , V_32 ) ;
if ( V_33 < 0 )
return V_33 ;
V_33 = F_36 ( V_4 , V_30 [ V_34 ] , & V_12 -> V_13 ) ;
if ( V_33 < 0 )
return V_33 ;
if ( V_30 [ V_35 ] ) {
V_12 -> V_6 . V_36 = F_37 ( V_30 [ V_35 ] ) ;
F_38 ( V_4 , & V_12 -> V_6 , V_28 ) ;
}
V_12 -> V_4 = V_4 ;
return 0 ;
}
static int F_39 ( struct V_27 * V_27 , struct V_1 * V_37 ,
struct V_3 * V_4 , unsigned long V_28 , T_1 V_15 ,
struct V_29 * * V_38 , void * * V_25 , bool V_32 )
{
int V_33 ;
struct V_8 * V_9 = F_7 ( V_4 -> V_10 ) ;
struct V_29 * V_30 [ V_39 + 1 ] ;
struct V_11 * V_40 = (struct V_11 * ) * V_25 ;
struct V_11 * V_41 ;
if ( V_38 [ V_42 ] == NULL )
return - V_43 ;
V_33 = F_40 ( V_30 , V_39 , V_38 [ V_42 ] ,
V_44 , NULL ) ;
if ( V_33 < 0 )
return V_33 ;
if ( V_40 != NULL ) {
if ( V_15 && V_40 -> V_15 != V_15 )
return - V_43 ;
}
V_41 = F_10 ( sizeof( * V_41 ) , V_16 ) ;
if ( ! V_41 )
return - V_17 ;
V_33 = F_41 ( & V_41 -> V_14 , V_45 , V_46 ) ;
if ( V_33 < 0 )
goto V_47;
V_33 = - V_43 ;
if ( V_15 ) {
V_41 -> V_15 = V_15 ;
} else if ( V_40 ) {
V_41 -> V_15 = V_40 -> V_15 ;
} else {
unsigned int V_48 = 0x80000000 ;
do {
if ( ++ V_9 -> V_49 == 0x7FFFFFFF )
V_9 -> V_49 = 1 ;
} while ( -- V_48 > 0 && F_6 ( V_4 , V_9 -> V_49 ) );
if ( V_48 <= 0 ) {
F_42 ( L_1 ) ;
goto V_47;
}
V_41 -> V_15 = V_9 -> V_49 ;
}
V_33 = F_34 ( V_27 , V_4 , V_41 , V_28 , V_30 , V_38 [ V_50 ] , V_32 ) ;
if ( V_33 < 0 )
goto V_47;
* V_25 = V_41 ;
if ( V_40 ) {
F_43 ( & V_40 -> V_24 , & V_41 -> V_24 ) ;
F_28 ( V_4 , & V_40 -> V_6 ) ;
F_29 ( & V_40 -> V_14 ) ;
F_30 ( & V_40 -> V_22 , F_22 ) ;
} else {
F_44 ( & V_41 -> V_24 , & V_9 -> V_18 ) ;
}
return 0 ;
V_47:
F_14 ( & V_41 -> V_14 ) ;
F_17 ( V_41 ) ;
return V_33 ;
}
static void F_45 ( struct V_3 * V_4 , struct V_51 * V_25 )
{
struct V_8 * V_9 = F_7 ( V_4 -> V_10 ) ;
struct V_11 * V_12 ;
F_8 (f, &head->flist, link) {
if ( V_25 -> V_52 < V_25 -> V_53 )
goto V_53;
if ( V_25 -> V_54 ( V_4 , V_12 , V_25 ) < 0 ) {
V_25 -> V_55 = 1 ;
break;
}
V_53:
V_25 -> V_52 ++ ;
}
}
static void F_46 ( void * V_56 , T_1 V_36 , unsigned long V_57 )
{
struct V_11 * V_12 = V_56 ;
if ( V_12 && V_12 -> V_6 . V_36 == V_36 )
V_12 -> V_6 . V_58 = V_57 ;
}
static int F_47 ( struct V_27 * V_27 , struct V_3 * V_4 , void * V_56 ,
struct V_1 * V_2 , struct V_59 * V_60 )
{
struct V_11 * V_12 = V_56 ;
struct V_29 * V_61 ;
if ( V_12 == NULL )
return V_2 -> V_62 ;
V_60 -> V_63 = V_12 -> V_15 ;
V_61 = F_48 ( V_2 , V_42 ) ;
if ( V_61 == NULL )
goto V_64;
if ( V_12 -> V_6 . V_36 &&
F_49 ( V_2 , V_35 , V_12 -> V_6 . V_36 ) )
goto V_64;
if ( F_50 ( V_2 , & V_12 -> V_14 ) < 0 ||
F_51 ( V_2 , & V_12 -> V_13 , V_34 ) < 0 )
goto V_64;
F_52 ( V_2 , V_61 ) ;
if ( F_53 ( V_2 , & V_12 -> V_14 ) < 0 )
goto V_64;
return V_2 -> V_62 ;
V_64:
F_54 ( V_2 , V_61 ) ;
return - 1 ;
}
static int T_2 F_55 ( void )
{
return F_56 ( & V_65 ) ;
}
static void T_3 F_57 ( void )
{
F_58 ( & V_65 ) ;
}
