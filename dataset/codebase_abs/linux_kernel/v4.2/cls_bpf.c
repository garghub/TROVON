static int F_1 ( struct V_1 * V_2 , const struct V_3 * V_4 ,
struct V_5 * V_6 )
{
struct V_7 * V_8 = F_2 ( V_4 -> V_9 ) ;
struct V_10 * V_11 ;
#ifdef F_3
bool V_12 = F_4 ( V_2 -> V_13 ) & V_14 ;
#else
bool V_12 = false ;
#endif
int V_15 = - 1 ;
if ( F_5 ( ! F_6 ( V_2 ) ) )
return - 1 ;
F_7 () ;
F_8 (prog, &head->plist, link) {
int V_16 ;
if ( V_12 ) {
F_9 ( V_2 , V_2 -> V_17 ) ;
V_16 = F_10 ( V_11 -> V_18 , V_2 ) ;
F_11 ( V_2 , V_2 -> V_17 ) ;
} else {
V_16 = F_10 ( V_11 -> V_18 , V_2 ) ;
}
if ( V_16 == 0 )
continue;
* V_6 = V_11 -> V_6 ;
if ( V_16 != - 1 )
V_6 -> V_19 = V_16 ;
V_15 = F_12 ( V_2 , & V_11 -> V_20 , V_6 ) ;
if ( V_15 < 0 )
continue;
break;
}
F_13 () ;
return V_15 ;
}
static bool F_14 ( const struct V_10 * V_11 )
{
return ! V_11 -> V_21 ;
}
static int F_15 ( struct V_3 * V_4 )
{
struct V_7 * V_8 ;
V_8 = F_16 ( sizeof( * V_8 ) , V_22 ) ;
if ( V_8 == NULL )
return - V_23 ;
F_17 ( & V_8 -> V_24 ) ;
F_18 ( V_4 -> V_9 , V_8 ) ;
return 0 ;
}
static void F_19 ( struct V_3 * V_4 , struct V_10 * V_11 )
{
F_20 ( & V_11 -> V_20 ) ;
if ( F_14 ( V_11 ) )
F_21 ( V_11 -> V_18 ) ;
else
F_22 ( V_11 -> V_18 ) ;
F_23 ( V_11 -> V_25 ) ;
F_23 ( V_11 -> V_21 ) ;
F_23 ( V_11 ) ;
}
static void F_24 ( struct V_26 * V_27 )
{
struct V_10 * V_11 = F_25 ( V_27 , struct V_10 , V_27 ) ;
F_19 ( V_11 -> V_4 , V_11 ) ;
}
static int F_26 ( struct V_3 * V_4 , unsigned long V_28 )
{
struct V_10 * V_11 = (struct V_10 * ) V_28 ;
F_27 ( & V_11 -> V_29 ) ;
F_28 ( V_4 , & V_11 -> V_6 ) ;
F_29 ( & V_11 -> V_27 , F_24 ) ;
return 0 ;
}
static bool F_30 ( struct V_3 * V_4 , bool V_30 )
{
struct V_7 * V_8 = F_31 ( V_4 -> V_9 ) ;
struct V_10 * V_11 , * V_31 ;
if ( ! V_30 && ! F_32 ( & V_8 -> V_24 ) )
return false ;
F_33 (prog, tmp, &head->plist, link) {
F_27 ( & V_11 -> V_29 ) ;
F_28 ( V_4 , & V_11 -> V_6 ) ;
F_29 ( & V_11 -> V_27 , F_24 ) ;
}
F_34 ( V_4 -> V_9 , NULL ) ;
F_35 ( V_8 , V_27 ) ;
return true ;
}
static unsigned long F_36 ( struct V_3 * V_4 , T_1 V_32 )
{
struct V_7 * V_8 = F_31 ( V_4 -> V_9 ) ;
struct V_10 * V_11 ;
unsigned long V_15 = 0UL ;
if ( V_8 == NULL )
return 0UL ;
F_37 (prog, &head->plist, link) {
if ( V_11 -> V_32 == V_32 ) {
V_15 = ( unsigned long ) V_11 ;
break;
}
}
return V_15 ;
}
static int F_38 ( struct V_33 * * V_34 ,
struct V_10 * V_11 , T_1 V_19 )
{
struct V_35 * V_21 ;
struct V_36 V_37 ;
struct V_38 * V_39 ;
T_2 V_40 , V_41 ;
int V_15 ;
V_41 = F_39 ( V_34 [ V_42 ] ) ;
if ( V_41 > V_43 || V_41 == 0 )
return - V_44 ;
V_40 = V_41 * sizeof( * V_21 ) ;
if ( V_40 != F_40 ( V_34 [ V_45 ] ) )
return - V_44 ;
V_21 = F_16 ( V_40 , V_22 ) ;
if ( V_21 == NULL )
return - V_46 ;
memcpy ( V_21 , F_41 ( V_34 [ V_45 ] ) , V_40 ) ;
V_37 . V_47 = V_41 ;
V_37 . V_18 = V_21 ;
V_15 = F_42 ( & V_39 , & V_37 ) ;
if ( V_15 < 0 ) {
F_23 ( V_21 ) ;
return V_15 ;
}
V_11 -> V_21 = V_21 ;
V_11 -> V_41 = V_41 ;
V_11 -> V_25 = NULL ;
V_11 -> V_18 = V_39 ;
V_11 -> V_6 . V_19 = V_19 ;
return 0 ;
}
static int F_43 ( struct V_33 * * V_34 ,
struct V_10 * V_11 , T_1 V_19 )
{
struct V_38 * V_39 ;
char * V_48 = NULL ;
T_1 V_49 ;
V_49 = F_44 ( V_34 [ V_50 ] ) ;
V_39 = F_45 ( V_49 ) ;
if ( F_46 ( V_39 ) )
return F_47 ( V_39 ) ;
if ( V_39 -> type != V_51 ) {
F_21 ( V_39 ) ;
return - V_44 ;
}
if ( V_34 [ V_52 ] ) {
V_48 = F_48 ( F_41 ( V_34 [ V_52 ] ) ,
F_40 ( V_34 [ V_52 ] ) ,
V_22 ) ;
if ( ! V_48 ) {
F_21 ( V_39 ) ;
return - V_46 ;
}
}
V_11 -> V_21 = NULL ;
V_11 -> V_49 = V_49 ;
V_11 -> V_25 = V_48 ;
V_11 -> V_18 = V_39 ;
V_11 -> V_6 . V_19 = V_19 ;
return 0 ;
}
static int F_49 ( struct V_53 * V_53 , struct V_3 * V_4 ,
struct V_10 * V_11 ,
unsigned long V_54 , struct V_33 * * V_34 ,
struct V_33 * V_55 , bool V_56 )
{
struct V_57 V_20 ;
bool V_58 , V_59 ;
T_1 V_19 ;
int V_15 ;
V_58 = V_34 [ V_42 ] && V_34 [ V_45 ] ;
V_59 = V_34 [ V_50 ] ;
if ( ( ! V_58 && ! V_59 ) || ( V_58 && V_59 ) ||
! V_34 [ V_60 ] )
return - V_44 ;
F_50 ( & V_20 , V_61 , V_62 ) ;
V_15 = F_51 ( V_53 , V_4 , V_34 , V_55 , & V_20 , V_56 ) ;
if ( V_15 < 0 )
return V_15 ;
V_19 = F_44 ( V_34 [ V_60 ] ) ;
V_15 = V_58 ? F_38 ( V_34 , V_11 , V_19 ) :
F_43 ( V_34 , V_11 , V_19 ) ;
if ( V_15 < 0 ) {
F_20 ( & V_20 ) ;
return V_15 ;
}
F_52 ( V_4 , & V_11 -> V_6 , V_54 ) ;
F_53 ( V_4 , & V_11 -> V_20 , & V_20 ) ;
return 0 ;
}
static T_1 F_54 ( struct V_3 * V_4 ,
struct V_7 * V_8 )
{
unsigned int V_63 = 0x80000000 ;
T_1 V_32 ;
do {
if ( ++ V_8 -> V_64 == 0x7FFFFFFF )
V_8 -> V_64 = 1 ;
} while ( -- V_63 > 0 && F_36 ( V_4 , V_8 -> V_64 ) );
if ( F_5 ( V_63 == 0 ) ) {
F_55 ( L_1 ) ;
V_32 = 0 ;
} else {
V_32 = V_8 -> V_64 ;
}
return V_32 ;
}
static int F_56 ( struct V_53 * V_53 , struct V_1 * V_65 ,
struct V_3 * V_4 , unsigned long V_54 ,
T_1 V_32 , struct V_33 * * V_66 ,
unsigned long * V_28 , bool V_56 )
{
struct V_7 * V_8 = F_31 ( V_4 -> V_9 ) ;
struct V_10 * V_67 = (struct V_10 * ) * V_28 ;
struct V_33 * V_34 [ V_68 + 1 ] ;
struct V_10 * V_11 ;
int V_15 ;
if ( V_66 [ V_69 ] == NULL )
return - V_44 ;
V_15 = F_57 ( V_34 , V_68 , V_66 [ V_69 ] , V_70 ) ;
if ( V_15 < 0 )
return V_15 ;
V_11 = F_16 ( sizeof( * V_11 ) , V_22 ) ;
if ( ! V_11 )
return - V_23 ;
F_50 ( & V_11 -> V_20 , V_61 , V_62 ) ;
if ( V_67 ) {
if ( V_32 && V_67 -> V_32 != V_32 ) {
V_15 = - V_44 ;
goto V_71;
}
}
if ( V_32 == 0 )
V_11 -> V_32 = F_54 ( V_4 , V_8 ) ;
else
V_11 -> V_32 = V_32 ;
if ( V_11 -> V_32 == 0 ) {
V_15 = - V_44 ;
goto V_71;
}
V_15 = F_49 ( V_53 , V_4 , V_11 , V_54 , V_34 , V_66 [ V_72 ] , V_56 ) ;
if ( V_15 < 0 )
goto V_71;
if ( V_67 ) {
F_58 ( & V_67 -> V_29 , & V_11 -> V_29 ) ;
F_28 ( V_4 , & V_67 -> V_6 ) ;
F_29 ( & V_67 -> V_27 , F_24 ) ;
} else {
F_59 ( & V_11 -> V_29 , & V_8 -> V_24 ) ;
}
* V_28 = ( unsigned long ) V_11 ;
return 0 ;
V_71:
F_23 ( V_11 ) ;
return V_15 ;
}
static int F_60 ( const struct V_10 * V_11 ,
struct V_1 * V_2 )
{
struct V_33 * V_73 ;
if ( F_61 ( V_2 , V_42 , V_11 -> V_41 ) )
return - V_74 ;
V_73 = F_62 ( V_2 , V_45 , V_11 -> V_41 *
sizeof( struct V_35 ) ) ;
if ( V_73 == NULL )
return - V_74 ;
memcpy ( F_41 ( V_73 ) , V_11 -> V_21 , F_40 ( V_73 ) ) ;
return 0 ;
}
static int F_63 ( const struct V_10 * V_11 ,
struct V_1 * V_2 )
{
if ( F_64 ( V_2 , V_50 , V_11 -> V_49 ) )
return - V_74 ;
if ( V_11 -> V_25 &&
F_65 ( V_2 , V_52 , V_11 -> V_25 ) )
return - V_74 ;
return 0 ;
}
static int F_66 ( struct V_53 * V_53 , struct V_3 * V_4 , unsigned long V_75 ,
struct V_1 * V_2 , struct V_76 * V_77 )
{
struct V_10 * V_11 = (struct V_10 * ) V_75 ;
struct V_33 * V_78 ;
int V_15 ;
if ( V_11 == NULL )
return V_2 -> V_47 ;
V_77 -> V_79 = V_11 -> V_32 ;
V_78 = F_67 ( V_2 , V_69 ) ;
if ( V_78 == NULL )
goto V_80;
if ( F_64 ( V_2 , V_60 , V_11 -> V_6 . V_19 ) )
goto V_80;
if ( F_14 ( V_11 ) )
V_15 = F_63 ( V_11 , V_2 ) ;
else
V_15 = F_60 ( V_11 , V_2 ) ;
if ( V_15 )
goto V_80;
if ( F_68 ( V_2 , & V_11 -> V_20 ) < 0 )
goto V_80;
F_69 ( V_2 , V_78 ) ;
if ( F_70 ( V_2 , & V_11 -> V_20 ) < 0 )
goto V_80;
return V_2 -> V_47 ;
V_80:
F_71 ( V_2 , V_78 ) ;
return - 1 ;
}
static void F_72 ( struct V_3 * V_4 , struct V_81 * V_28 )
{
struct V_7 * V_8 = F_31 ( V_4 -> V_9 ) ;
struct V_10 * V_11 ;
F_37 (prog, &head->plist, link) {
if ( V_28 -> V_82 < V_28 -> V_83 )
goto V_83;
if ( V_28 -> V_84 ( V_4 , ( unsigned long ) V_11 , V_28 ) < 0 ) {
V_28 -> V_85 = 1 ;
break;
}
V_83:
V_28 -> V_82 ++ ;
}
}
static int T_3 F_73 ( void )
{
return F_74 ( & V_86 ) ;
}
static void T_4 F_75 ( void )
{
F_76 ( & V_86 ) ;
}
