static int F_1 ( struct V_1 * V_2 , const struct V_3 * V_4 ,
struct V_5 * V_6 )
{
struct V_7 * V_8 = V_4 -> V_9 ;
struct V_10 * V_11 ;
int V_12 ;
F_2 (prog, &head->plist, link) {
int V_13 = F_3 ( V_11 -> V_14 , V_2 ) ;
if ( V_13 == 0 )
continue;
* V_6 = V_11 -> V_6 ;
if ( V_13 != - 1 )
V_6 -> V_15 = V_13 ;
V_12 = F_4 ( V_2 , & V_11 -> V_16 , V_6 ) ;
if ( V_12 < 0 )
continue;
return V_12 ;
}
return - 1 ;
}
static int F_5 ( struct V_3 * V_4 )
{
struct V_7 * V_8 ;
V_8 = F_6 ( sizeof( * V_8 ) , V_17 ) ;
if ( V_8 == NULL )
return - V_18 ;
F_7 ( & V_8 -> V_19 ) ;
V_4 -> V_9 = V_8 ;
return 0 ;
}
static void F_8 ( struct V_3 * V_4 , struct V_10 * V_11 )
{
F_9 ( V_4 , & V_11 -> V_6 ) ;
F_10 ( V_4 , & V_11 -> V_16 ) ;
F_11 ( V_11 -> V_14 ) ;
F_12 ( V_11 -> V_20 ) ;
F_12 ( V_11 ) ;
}
static int F_13 ( struct V_3 * V_4 , unsigned long V_21 )
{
struct V_7 * V_8 = V_4 -> V_9 ;
struct V_10 * V_11 , * V_22 = (struct V_10 * ) V_21 ;
F_2 (prog, &head->plist, link) {
if ( V_11 == V_22 ) {
F_14 ( V_4 ) ;
F_15 ( & V_11 -> V_23 ) ;
F_16 ( V_4 ) ;
F_8 ( V_4 , V_11 ) ;
return 0 ;
}
}
return - V_24 ;
}
static void F_17 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = V_4 -> V_9 ;
struct V_10 * V_11 , * V_25 ;
F_18 (prog, tmp, &head->plist, link) {
F_15 ( & V_11 -> V_23 ) ;
F_8 ( V_4 , V_11 ) ;
}
F_12 ( V_8 ) ;
}
static unsigned long F_19 ( struct V_3 * V_4 , T_1 V_26 )
{
struct V_7 * V_8 = V_4 -> V_9 ;
struct V_10 * V_11 ;
unsigned long V_12 = 0UL ;
if ( V_8 == NULL )
return 0UL ;
F_2 (prog, &head->plist, link) {
if ( V_11 -> V_26 == V_26 ) {
V_12 = ( unsigned long ) V_11 ;
break;
}
}
return V_12 ;
}
static void F_20 ( struct V_3 * V_4 , unsigned long V_27 )
{
}
static int F_21 ( struct V_28 * V_28 , struct V_3 * V_4 ,
struct V_10 * V_11 ,
unsigned long V_29 , struct V_30 * * V_31 ,
struct V_30 * V_32 )
{
struct V_33 * V_20 , * V_34 ;
struct V_35 V_16 ;
struct V_36 V_25 ;
struct V_37 * V_38 , * V_39 ;
T_2 V_40 , V_41 ;
T_1 V_15 ;
int V_12 ;
if ( ! V_31 [ V_42 ] || ! V_31 [ V_43 ] || ! V_31 [ V_44 ] )
return - V_45 ;
F_22 ( & V_16 , V_46 , V_47 ) ;
V_12 = F_23 ( V_28 , V_4 , V_31 , V_32 , & V_16 ) ;
if ( V_12 < 0 )
return V_12 ;
V_15 = F_24 ( V_31 [ V_44 ] ) ;
V_41 = F_25 ( V_31 [ V_42 ] ) ;
if ( V_41 > V_48 || V_41 == 0 ) {
V_12 = - V_45 ;
goto V_49;
}
V_40 = V_41 * sizeof( * V_20 ) ;
V_20 = F_6 ( V_40 , V_17 ) ;
if ( V_20 == NULL ) {
V_12 = - V_50 ;
goto V_49;
}
memcpy ( V_20 , F_26 ( V_31 [ V_43 ] ) , V_40 ) ;
V_25 . V_51 = V_41 ;
V_25 . V_14 = (struct V_33 V_52 * ) V_20 ;
V_12 = F_27 ( & V_38 , & V_25 ) ;
if ( V_12 )
goto V_53;
F_14 ( V_4 ) ;
V_39 = V_11 -> V_14 ;
V_34 = V_11 -> V_20 ;
V_11 -> V_41 = V_41 ;
V_11 -> V_20 = V_20 ;
V_11 -> V_14 = V_38 ;
V_11 -> V_6 . V_15 = V_15 ;
F_16 ( V_4 ) ;
F_28 ( V_4 , & V_11 -> V_6 , V_29 ) ;
F_29 ( V_4 , & V_11 -> V_16 , & V_16 ) ;
if ( V_39 )
F_11 ( V_39 ) ;
if ( V_34 )
F_12 ( V_34 ) ;
return 0 ;
V_53:
F_12 ( V_20 ) ;
V_49:
F_10 ( V_4 , & V_16 ) ;
return V_12 ;
}
static T_1 F_30 ( struct V_3 * V_4 ,
struct V_7 * V_8 )
{
unsigned int V_54 = 0x80000000 ;
do {
if ( ++ V_8 -> V_55 == 0x7FFFFFFF )
V_8 -> V_55 = 1 ;
} while ( -- V_54 > 0 && F_19 ( V_4 , V_8 -> V_55 ) );
if ( V_54 == 0 )
F_31 ( L_1 ) ;
return V_54 ;
}
static int F_32 ( struct V_28 * V_28 , struct V_1 * V_56 ,
struct V_3 * V_4 , unsigned long V_29 ,
T_1 V_26 , struct V_30 * * V_57 ,
unsigned long * V_21 )
{
struct V_7 * V_8 = V_4 -> V_9 ;
struct V_10 * V_11 = (struct V_10 * ) * V_21 ;
struct V_30 * V_31 [ V_58 + 1 ] ;
int V_12 ;
if ( V_57 [ V_59 ] == NULL )
return - V_45 ;
V_12 = F_33 ( V_31 , V_58 , V_57 [ V_59 ] , V_60 ) ;
if ( V_12 < 0 )
return V_12 ;
if ( V_11 != NULL ) {
if ( V_26 && V_11 -> V_26 != V_26 )
return - V_45 ;
return F_21 ( V_28 , V_4 , V_11 , V_29 , V_31 ,
V_57 [ V_61 ] ) ;
}
V_11 = F_6 ( sizeof( * V_11 ) , V_17 ) ;
if ( V_11 == NULL )
return - V_18 ;
F_22 ( & V_11 -> V_16 , V_46 , V_47 ) ;
if ( V_26 == 0 )
V_11 -> V_26 = F_30 ( V_4 , V_8 ) ;
else
V_11 -> V_26 = V_26 ;
if ( V_11 -> V_26 == 0 ) {
V_12 = - V_45 ;
goto V_49;
}
V_12 = F_21 ( V_28 , V_4 , V_11 , V_29 , V_31 , V_57 [ V_61 ] ) ;
if ( V_12 < 0 )
goto V_49;
F_14 ( V_4 ) ;
F_34 ( & V_11 -> V_23 , & V_8 -> V_19 ) ;
F_16 ( V_4 ) ;
* V_21 = ( unsigned long ) V_11 ;
return 0 ;
V_49:
if ( * V_21 == 0UL && V_11 )
F_12 ( V_11 ) ;
return V_12 ;
}
static int F_35 ( struct V_28 * V_28 , struct V_3 * V_4 , unsigned long V_62 ,
struct V_1 * V_2 , struct V_63 * V_64 )
{
struct V_10 * V_11 = (struct V_10 * ) V_62 ;
struct V_30 * V_65 , * V_66 ;
if ( V_11 == NULL )
return V_2 -> V_51 ;
V_64 -> V_67 = V_11 -> V_26 ;
V_65 = F_36 ( V_2 , V_59 ) ;
if ( V_65 == NULL )
goto V_68;
if ( F_37 ( V_2 , V_44 , V_11 -> V_6 . V_15 ) )
goto V_68;
if ( F_38 ( V_2 , V_42 , V_11 -> V_41 ) )
goto V_68;
V_66 = F_39 ( V_2 , V_43 , V_11 -> V_41 *
sizeof( struct V_33 ) ) ;
if ( V_66 == NULL )
goto V_68;
memcpy ( F_26 ( V_66 ) , V_11 -> V_20 , F_40 ( V_66 ) ) ;
if ( F_41 ( V_2 , & V_11 -> V_16 ) < 0 )
goto V_68;
F_42 ( V_2 , V_65 ) ;
if ( F_43 ( V_2 , & V_11 -> V_16 ) < 0 )
goto V_68;
return V_2 -> V_51 ;
V_68:
F_44 ( V_2 , V_65 ) ;
return - 1 ;
}
static void F_45 ( struct V_3 * V_4 , struct V_69 * V_21 )
{
struct V_7 * V_8 = V_4 -> V_9 ;
struct V_10 * V_11 ;
F_2 (prog, &head->plist, link) {
if ( V_21 -> V_70 < V_21 -> V_71 )
goto V_71;
if ( V_21 -> V_72 ( V_4 , ( unsigned long ) V_11 , V_21 ) < 0 ) {
V_21 -> V_73 = 1 ;
break;
}
V_71:
V_21 -> V_70 ++ ;
}
}
static int T_3 F_46 ( void )
{
return F_47 ( & V_74 ) ;
}
static void T_4 F_48 ( void )
{
F_49 ( & V_74 ) ;
}
