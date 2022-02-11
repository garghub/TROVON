static int F_1 ( struct V_1 * V_2 , const struct V_3 * V_4 ,
struct V_5 * V_6 )
{
struct V_7 * V_8 = F_2 ( V_4 -> V_9 ) ;
struct V_10 * V_11 ;
int V_12 = - 1 ;
if ( F_3 ( ! F_4 ( V_2 ) ) )
return - 1 ;
F_5 () ;
F_6 (prog, &head->plist, link) {
int V_13 = F_7 ( V_11 -> V_14 , V_2 ) ;
if ( V_13 == 0 )
continue;
* V_6 = V_11 -> V_6 ;
if ( V_13 != - 1 )
V_6 -> V_15 = V_13 ;
V_12 = F_8 ( V_2 , & V_11 -> V_16 , V_6 ) ;
if ( V_12 < 0 )
continue;
break;
}
F_9 () ;
return V_12 ;
}
static bool F_10 ( const struct V_10 * V_11 )
{
return ! V_11 -> V_17 ;
}
static int F_11 ( struct V_3 * V_4 )
{
struct V_7 * V_8 ;
V_8 = F_12 ( sizeof( * V_8 ) , V_18 ) ;
if ( V_8 == NULL )
return - V_19 ;
F_13 ( & V_8 -> V_20 ) ;
F_14 ( V_4 -> V_9 , V_8 ) ;
return 0 ;
}
static void F_15 ( struct V_3 * V_4 , struct V_10 * V_11 )
{
F_16 ( & V_11 -> V_16 ) ;
if ( F_10 ( V_11 ) )
F_17 ( V_11 -> V_14 ) ;
else
F_18 ( V_11 -> V_14 ) ;
F_19 ( V_11 -> V_21 ) ;
F_19 ( V_11 -> V_17 ) ;
F_19 ( V_11 ) ;
}
static void F_20 ( struct V_22 * V_23 )
{
struct V_10 * V_11 = F_21 ( V_23 , struct V_10 , V_23 ) ;
F_15 ( V_11 -> V_4 , V_11 ) ;
}
static int F_22 ( struct V_3 * V_4 , unsigned long V_24 )
{
struct V_10 * V_11 = (struct V_10 * ) V_24 ;
F_23 ( & V_11 -> V_25 ) ;
F_24 ( V_4 , & V_11 -> V_6 ) ;
F_25 ( & V_11 -> V_23 , F_20 ) ;
return 0 ;
}
static bool F_26 ( struct V_3 * V_4 , bool V_26 )
{
struct V_7 * V_8 = F_27 ( V_4 -> V_9 ) ;
struct V_10 * V_11 , * V_27 ;
if ( ! V_26 && ! F_28 ( & V_8 -> V_20 ) )
return false ;
F_29 (prog, tmp, &head->plist, link) {
F_23 ( & V_11 -> V_25 ) ;
F_24 ( V_4 , & V_11 -> V_6 ) ;
F_25 ( & V_11 -> V_23 , F_20 ) ;
}
F_30 ( V_4 -> V_9 , NULL ) ;
F_31 ( V_8 , V_23 ) ;
return true ;
}
static unsigned long F_32 ( struct V_3 * V_4 , T_1 V_28 )
{
struct V_7 * V_8 = F_27 ( V_4 -> V_9 ) ;
struct V_10 * V_11 ;
unsigned long V_12 = 0UL ;
if ( V_8 == NULL )
return 0UL ;
F_33 (prog, &head->plist, link) {
if ( V_11 -> V_28 == V_28 ) {
V_12 = ( unsigned long ) V_11 ;
break;
}
}
return V_12 ;
}
static int F_34 ( struct V_29 * * V_30 ,
struct V_10 * V_11 , T_1 V_15 )
{
struct V_31 * V_17 ;
struct V_32 V_33 ;
struct V_34 * V_35 ;
T_2 V_36 , V_37 ;
int V_12 ;
V_37 = F_35 ( V_30 [ V_38 ] ) ;
if ( V_37 > V_39 || V_37 == 0 )
return - V_40 ;
V_36 = V_37 * sizeof( * V_17 ) ;
if ( V_36 != F_36 ( V_30 [ V_41 ] ) )
return - V_40 ;
V_17 = F_12 ( V_36 , V_18 ) ;
if ( V_17 == NULL )
return - V_42 ;
memcpy ( V_17 , F_37 ( V_30 [ V_41 ] ) , V_36 ) ;
V_33 . V_43 = V_37 ;
V_33 . V_14 = V_17 ;
V_12 = F_38 ( & V_35 , & V_33 ) ;
if ( V_12 < 0 ) {
F_19 ( V_17 ) ;
return V_12 ;
}
V_11 -> V_17 = V_17 ;
V_11 -> V_37 = V_37 ;
V_11 -> V_21 = NULL ;
V_11 -> V_14 = V_35 ;
V_11 -> V_6 . V_15 = V_15 ;
return 0 ;
}
static int F_39 ( struct V_29 * * V_30 ,
struct V_10 * V_11 , T_1 V_15 )
{
struct V_34 * V_35 ;
char * V_44 = NULL ;
T_1 V_45 ;
V_45 = F_40 ( V_30 [ V_46 ] ) ;
V_35 = F_41 ( V_45 ) ;
if ( F_42 ( V_35 ) )
return F_43 ( V_35 ) ;
if ( V_35 -> type != V_47 ) {
F_17 ( V_35 ) ;
return - V_40 ;
}
if ( V_30 [ V_48 ] ) {
V_44 = F_44 ( F_37 ( V_30 [ V_48 ] ) ,
F_36 ( V_30 [ V_48 ] ) ,
V_18 ) ;
if ( ! V_44 ) {
F_17 ( V_35 ) ;
return - V_42 ;
}
}
V_11 -> V_17 = NULL ;
V_11 -> V_45 = V_45 ;
V_11 -> V_21 = V_44 ;
V_11 -> V_14 = V_35 ;
V_11 -> V_6 . V_15 = V_15 ;
return 0 ;
}
static int F_45 ( struct V_49 * V_49 , struct V_3 * V_4 ,
struct V_10 * V_11 ,
unsigned long V_50 , struct V_29 * * V_30 ,
struct V_29 * V_51 , bool V_52 )
{
struct V_53 V_16 ;
bool V_54 , V_55 ;
T_1 V_15 ;
int V_12 ;
V_54 = V_30 [ V_38 ] && V_30 [ V_41 ] ;
V_55 = V_30 [ V_46 ] ;
if ( ( ! V_54 && ! V_55 ) || ( V_54 && V_55 ) ||
! V_30 [ V_56 ] )
return - V_40 ;
F_46 ( & V_16 , V_57 , V_58 ) ;
V_12 = F_47 ( V_49 , V_4 , V_30 , V_51 , & V_16 , V_52 ) ;
if ( V_12 < 0 )
return V_12 ;
V_15 = F_40 ( V_30 [ V_56 ] ) ;
V_12 = V_54 ? F_34 ( V_30 , V_11 , V_15 ) :
F_39 ( V_30 , V_11 , V_15 ) ;
if ( V_12 < 0 ) {
F_16 ( & V_16 ) ;
return V_12 ;
}
F_48 ( V_4 , & V_11 -> V_6 , V_50 ) ;
F_49 ( V_4 , & V_11 -> V_16 , & V_16 ) ;
return 0 ;
}
static T_1 F_50 ( struct V_3 * V_4 ,
struct V_7 * V_8 )
{
unsigned int V_59 = 0x80000000 ;
T_1 V_28 ;
do {
if ( ++ V_8 -> V_60 == 0x7FFFFFFF )
V_8 -> V_60 = 1 ;
} while ( -- V_59 > 0 && F_32 ( V_4 , V_8 -> V_60 ) );
if ( F_3 ( V_59 == 0 ) ) {
F_51 ( L_1 ) ;
V_28 = 0 ;
} else {
V_28 = V_8 -> V_60 ;
}
return V_28 ;
}
static int F_52 ( struct V_49 * V_49 , struct V_1 * V_61 ,
struct V_3 * V_4 , unsigned long V_50 ,
T_1 V_28 , struct V_29 * * V_62 ,
unsigned long * V_24 , bool V_52 )
{
struct V_7 * V_8 = F_27 ( V_4 -> V_9 ) ;
struct V_10 * V_63 = (struct V_10 * ) * V_24 ;
struct V_29 * V_30 [ V_64 + 1 ] ;
struct V_10 * V_11 ;
int V_12 ;
if ( V_62 [ V_65 ] == NULL )
return - V_40 ;
V_12 = F_53 ( V_30 , V_64 , V_62 [ V_65 ] , V_66 ) ;
if ( V_12 < 0 )
return V_12 ;
V_11 = F_12 ( sizeof( * V_11 ) , V_18 ) ;
if ( ! V_11 )
return - V_19 ;
F_46 ( & V_11 -> V_16 , V_57 , V_58 ) ;
if ( V_63 ) {
if ( V_28 && V_63 -> V_28 != V_28 ) {
V_12 = - V_40 ;
goto V_67;
}
}
if ( V_28 == 0 )
V_11 -> V_28 = F_50 ( V_4 , V_8 ) ;
else
V_11 -> V_28 = V_28 ;
if ( V_11 -> V_28 == 0 ) {
V_12 = - V_40 ;
goto V_67;
}
V_12 = F_45 ( V_49 , V_4 , V_11 , V_50 , V_30 , V_62 [ V_68 ] , V_52 ) ;
if ( V_12 < 0 )
goto V_67;
if ( V_63 ) {
F_54 ( & V_11 -> V_25 , & V_63 -> V_25 ) ;
F_24 ( V_4 , & V_63 -> V_6 ) ;
F_25 ( & V_63 -> V_23 , F_20 ) ;
} else {
F_55 ( & V_11 -> V_25 , & V_8 -> V_20 ) ;
}
* V_24 = ( unsigned long ) V_11 ;
return 0 ;
V_67:
F_19 ( V_11 ) ;
return V_12 ;
}
static int F_56 ( const struct V_10 * V_11 ,
struct V_1 * V_2 )
{
struct V_29 * V_69 ;
if ( F_57 ( V_2 , V_38 , V_11 -> V_37 ) )
return - V_70 ;
V_69 = F_58 ( V_2 , V_41 , V_11 -> V_37 *
sizeof( struct V_31 ) ) ;
if ( V_69 == NULL )
return - V_70 ;
memcpy ( F_37 ( V_69 ) , V_11 -> V_17 , F_36 ( V_69 ) ) ;
return 0 ;
}
static int F_59 ( const struct V_10 * V_11 ,
struct V_1 * V_2 )
{
if ( F_60 ( V_2 , V_46 , V_11 -> V_45 ) )
return - V_70 ;
if ( V_11 -> V_21 &&
F_61 ( V_2 , V_48 , V_11 -> V_21 ) )
return - V_70 ;
return 0 ;
}
static int F_62 ( struct V_49 * V_49 , struct V_3 * V_4 , unsigned long V_71 ,
struct V_1 * V_2 , struct V_72 * V_73 )
{
struct V_10 * V_11 = (struct V_10 * ) V_71 ;
struct V_29 * V_74 ;
int V_12 ;
if ( V_11 == NULL )
return V_2 -> V_43 ;
V_73 -> V_75 = V_11 -> V_28 ;
V_74 = F_63 ( V_2 , V_65 ) ;
if ( V_74 == NULL )
goto V_76;
if ( F_60 ( V_2 , V_56 , V_11 -> V_6 . V_15 ) )
goto V_76;
if ( F_10 ( V_11 ) )
V_12 = F_59 ( V_11 , V_2 ) ;
else
V_12 = F_56 ( V_11 , V_2 ) ;
if ( V_12 )
goto V_76;
if ( F_64 ( V_2 , & V_11 -> V_16 ) < 0 )
goto V_76;
F_65 ( V_2 , V_74 ) ;
if ( F_66 ( V_2 , & V_11 -> V_16 ) < 0 )
goto V_76;
return V_2 -> V_43 ;
V_76:
F_67 ( V_2 , V_74 ) ;
return - 1 ;
}
static void F_68 ( struct V_3 * V_4 , struct V_77 * V_24 )
{
struct V_7 * V_8 = F_27 ( V_4 -> V_9 ) ;
struct V_10 * V_11 ;
F_33 (prog, &head->plist, link) {
if ( V_24 -> V_78 < V_24 -> V_79 )
goto V_79;
if ( V_24 -> V_80 ( V_4 , ( unsigned long ) V_11 , V_24 ) < 0 ) {
V_24 -> V_81 = 1 ;
break;
}
V_79:
V_24 -> V_78 ++ ;
}
}
static int T_3 F_69 ( void )
{
return F_70 ( & V_82 ) ;
}
static void T_4 F_71 ( void )
{
F_72 ( & V_82 ) ;
}
