static int F_1 ( int V_1 )
{
switch ( V_1 ) {
case V_2 :
case V_3 :
case V_4 :
case V_5 :
case V_6 :
return V_1 ;
default:
return V_6 ;
}
}
static int F_2 ( struct V_7 * V_8 , const struct V_9 * V_10 ,
struct V_11 * V_12 )
{
struct V_13 * V_14 = F_3 ( V_10 -> V_15 ) ;
bool V_16 = F_4 ( V_8 ) ;
struct V_17 * V_18 ;
int V_19 = - 1 ;
if ( F_5 ( ! F_6 ( V_8 ) ) )
return - 1 ;
F_7 () ;
F_8 (prog, &head->plist, link) {
int V_20 ;
F_9 ( V_8 ) -> V_21 = V_18 -> V_12 . V_22 ;
if ( V_16 ) {
F_10 ( V_8 , V_8 -> V_23 ) ;
F_11 ( V_8 ) ;
V_20 = F_12 ( V_18 -> V_24 , V_8 ) ;
F_13 ( V_8 , V_8 -> V_23 ) ;
} else {
F_11 ( V_8 ) ;
V_20 = F_12 ( V_18 -> V_24 , V_8 ) ;
}
if ( V_18 -> V_25 ) {
V_12 -> V_26 = 0 ;
V_12 -> V_22 = F_14 ( V_18 -> V_12 . V_22 ) |
F_9 ( V_8 ) -> V_21 ;
V_19 = F_1 ( V_20 ) ;
if ( V_19 == V_6 )
continue;
break;
}
if ( V_20 == 0 )
continue;
if ( V_20 != - 1 ) {
V_12 -> V_26 = 0 ;
V_12 -> V_22 = V_20 ;
} else {
* V_12 = V_18 -> V_12 ;
}
V_19 = F_15 ( V_8 , & V_18 -> V_27 , V_12 ) ;
if ( V_19 < 0 )
continue;
break;
}
F_16 () ;
return V_19 ;
}
static bool F_17 ( const struct V_17 * V_18 )
{
return ! V_18 -> V_28 ;
}
static int F_18 ( struct V_9 * V_10 )
{
struct V_13 * V_14 ;
V_14 = F_19 ( sizeof( * V_14 ) , V_29 ) ;
if ( V_14 == NULL )
return - V_30 ;
F_20 ( & V_14 -> V_31 ) ;
F_21 ( V_10 -> V_15 , V_14 ) ;
return 0 ;
}
static void F_22 ( struct V_9 * V_10 , struct V_17 * V_18 )
{
F_23 ( & V_18 -> V_27 ) ;
if ( F_17 ( V_18 ) )
F_24 ( V_18 -> V_24 ) ;
else
F_25 ( V_18 -> V_24 ) ;
F_26 ( V_18 -> V_32 ) ;
F_26 ( V_18 -> V_28 ) ;
F_26 ( V_18 ) ;
}
static void F_27 ( struct V_33 * V_34 )
{
struct V_17 * V_18 = F_28 ( V_34 , struct V_17 , V_34 ) ;
F_22 ( V_18 -> V_10 , V_18 ) ;
}
static int F_29 ( struct V_9 * V_10 , unsigned long V_35 )
{
struct V_17 * V_18 = (struct V_17 * ) V_35 ;
F_30 ( & V_18 -> V_36 ) ;
F_31 ( V_10 , & V_18 -> V_12 ) ;
F_32 ( & V_18 -> V_34 , F_27 ) ;
return 0 ;
}
static bool F_33 ( struct V_9 * V_10 , bool V_37 )
{
struct V_13 * V_14 = F_34 ( V_10 -> V_15 ) ;
struct V_17 * V_18 , * V_38 ;
if ( ! V_37 && ! F_35 ( & V_14 -> V_31 ) )
return false ;
F_36 (prog, tmp, &head->plist, link) {
F_30 ( & V_18 -> V_36 ) ;
F_31 ( V_10 , & V_18 -> V_12 ) ;
F_32 ( & V_18 -> V_34 , F_27 ) ;
}
F_37 ( V_10 -> V_15 , NULL ) ;
F_38 ( V_14 , V_34 ) ;
return true ;
}
static unsigned long F_39 ( struct V_9 * V_10 , T_1 V_39 )
{
struct V_13 * V_14 = F_34 ( V_10 -> V_15 ) ;
struct V_17 * V_18 ;
unsigned long V_19 = 0UL ;
if ( V_14 == NULL )
return 0UL ;
F_40 (prog, &head->plist, link) {
if ( V_18 -> V_39 == V_39 ) {
V_19 = ( unsigned long ) V_18 ;
break;
}
}
return V_19 ;
}
static int F_41 ( struct V_40 * * V_41 , struct V_17 * V_18 )
{
struct V_42 * V_28 ;
struct V_43 V_44 ;
struct V_45 * V_46 ;
T_2 V_47 , V_48 ;
int V_19 ;
V_48 = F_42 ( V_41 [ V_49 ] ) ;
if ( V_48 > V_50 || V_48 == 0 )
return - V_51 ;
V_47 = V_48 * sizeof( * V_28 ) ;
if ( V_47 != F_43 ( V_41 [ V_52 ] ) )
return - V_51 ;
V_28 = F_19 ( V_47 , V_29 ) ;
if ( V_28 == NULL )
return - V_53 ;
memcpy ( V_28 , F_44 ( V_41 [ V_52 ] ) , V_47 ) ;
V_44 . V_54 = V_48 ;
V_44 . V_24 = V_28 ;
V_19 = F_45 ( & V_46 , & V_44 ) ;
if ( V_19 < 0 ) {
F_26 ( V_28 ) ;
return V_19 ;
}
V_18 -> V_28 = V_28 ;
V_18 -> V_48 = V_48 ;
V_18 -> V_32 = NULL ;
V_18 -> V_24 = V_46 ;
return 0 ;
}
static int F_46 ( struct V_40 * * V_41 , struct V_17 * V_18 ,
const struct V_9 * V_10 )
{
struct V_45 * V_46 ;
char * V_55 = NULL ;
T_1 V_56 ;
V_56 = F_47 ( V_41 [ V_57 ] ) ;
V_46 = F_48 ( V_56 , V_58 ) ;
if ( F_49 ( V_46 ) )
return F_50 ( V_46 ) ;
if ( V_41 [ V_59 ] ) {
V_55 = F_51 ( F_44 ( V_41 [ V_59 ] ) ,
F_43 ( V_41 [ V_59 ] ) ,
V_29 ) ;
if ( ! V_55 ) {
F_24 ( V_46 ) ;
return - V_53 ;
}
}
V_18 -> V_28 = NULL ;
V_18 -> V_56 = V_56 ;
V_18 -> V_32 = V_55 ;
V_18 -> V_24 = V_46 ;
if ( V_46 -> V_60 && ! ( V_10 -> V_61 -> V_62 & V_63 ) )
F_52 ( F_53 ( V_10 -> V_61 ) ) ;
return 0 ;
}
static int F_54 ( struct V_64 * V_64 , struct V_9 * V_10 ,
struct V_17 * V_18 ,
unsigned long V_65 , struct V_40 * * V_41 ,
struct V_40 * V_66 , bool V_67 )
{
bool V_68 , V_69 , V_70 = false ;
struct V_71 V_27 ;
int V_19 ;
V_68 = V_41 [ V_49 ] && V_41 [ V_52 ] ;
V_69 = V_41 [ V_57 ] ;
if ( ( ! V_68 && ! V_69 ) || ( V_68 && V_69 ) )
return - V_51 ;
F_55 ( & V_27 , V_72 , V_73 ) ;
V_19 = F_56 ( V_64 , V_10 , V_41 , V_66 , & V_27 , V_67 ) ;
if ( V_19 < 0 )
return V_19 ;
if ( V_41 [ V_74 ] ) {
T_1 V_75 = F_47 ( V_41 [ V_74 ] ) ;
if ( V_75 & ~ V_76 ) {
F_23 ( & V_27 ) ;
return - V_51 ;
}
V_70 = V_75 & V_76 ;
}
V_18 -> V_25 = V_70 ;
V_19 = V_68 ? F_41 ( V_41 , V_18 ) :
F_46 ( V_41 , V_18 , V_10 ) ;
if ( V_19 < 0 ) {
F_23 ( & V_27 ) ;
return V_19 ;
}
if ( V_41 [ V_77 ] ) {
V_18 -> V_12 . V_22 = F_47 ( V_41 [ V_77 ] ) ;
F_57 ( V_10 , & V_18 -> V_12 , V_65 ) ;
}
F_58 ( V_10 , & V_18 -> V_27 , & V_27 ) ;
return 0 ;
}
static T_1 F_59 ( struct V_9 * V_10 ,
struct V_13 * V_14 )
{
unsigned int V_78 = 0x80000000 ;
T_1 V_39 ;
do {
if ( ++ V_14 -> V_79 == 0x7FFFFFFF )
V_14 -> V_79 = 1 ;
} while ( -- V_78 > 0 && F_39 ( V_10 , V_14 -> V_79 ) );
if ( F_5 ( V_78 == 0 ) ) {
F_60 ( L_1 ) ;
V_39 = 0 ;
} else {
V_39 = V_14 -> V_79 ;
}
return V_39 ;
}
static int F_61 ( struct V_64 * V_64 , struct V_7 * V_80 ,
struct V_9 * V_10 , unsigned long V_65 ,
T_1 V_39 , struct V_40 * * V_81 ,
unsigned long * V_35 , bool V_67 )
{
struct V_13 * V_14 = F_34 ( V_10 -> V_15 ) ;
struct V_17 * V_82 = (struct V_17 * ) * V_35 ;
struct V_40 * V_41 [ V_83 + 1 ] ;
struct V_17 * V_18 ;
int V_19 ;
if ( V_81 [ V_84 ] == NULL )
return - V_51 ;
V_19 = F_62 ( V_41 , V_83 , V_81 [ V_84 ] , V_85 ) ;
if ( V_19 < 0 )
return V_19 ;
V_18 = F_19 ( sizeof( * V_18 ) , V_29 ) ;
if ( ! V_18 )
return - V_30 ;
F_55 ( & V_18 -> V_27 , V_72 , V_73 ) ;
if ( V_82 ) {
if ( V_39 && V_82 -> V_39 != V_39 ) {
V_19 = - V_51 ;
goto V_86;
}
}
if ( V_39 == 0 )
V_18 -> V_39 = F_59 ( V_10 , V_14 ) ;
else
V_18 -> V_39 = V_39 ;
if ( V_18 -> V_39 == 0 ) {
V_19 = - V_51 ;
goto V_86;
}
V_19 = F_54 ( V_64 , V_10 , V_18 , V_65 , V_41 , V_81 [ V_87 ] , V_67 ) ;
if ( V_19 < 0 )
goto V_86;
if ( V_82 ) {
F_63 ( & V_82 -> V_36 , & V_18 -> V_36 ) ;
F_31 ( V_10 , & V_82 -> V_12 ) ;
F_32 ( & V_82 -> V_34 , F_27 ) ;
} else {
F_64 ( & V_18 -> V_36 , & V_14 -> V_31 ) ;
}
* V_35 = ( unsigned long ) V_18 ;
return 0 ;
V_86:
F_26 ( V_18 ) ;
return V_19 ;
}
static int F_65 ( const struct V_17 * V_18 ,
struct V_7 * V_8 )
{
struct V_40 * V_88 ;
if ( F_66 ( V_8 , V_49 , V_18 -> V_48 ) )
return - V_89 ;
V_88 = F_67 ( V_8 , V_52 , V_18 -> V_48 *
sizeof( struct V_42 ) ) ;
if ( V_88 == NULL )
return - V_89 ;
memcpy ( F_44 ( V_88 ) , V_18 -> V_28 , F_43 ( V_88 ) ) ;
return 0 ;
}
static int F_68 ( const struct V_17 * V_18 ,
struct V_7 * V_8 )
{
if ( F_69 ( V_8 , V_57 , V_18 -> V_56 ) )
return - V_89 ;
if ( V_18 -> V_32 &&
F_70 ( V_8 , V_59 , V_18 -> V_32 ) )
return - V_89 ;
return 0 ;
}
static int F_71 ( struct V_64 * V_64 , struct V_9 * V_10 , unsigned long V_90 ,
struct V_7 * V_8 , struct V_91 * V_92 )
{
struct V_17 * V_18 = (struct V_17 * ) V_90 ;
struct V_40 * V_93 ;
T_1 V_75 = 0 ;
int V_19 ;
if ( V_18 == NULL )
return V_8 -> V_54 ;
V_92 -> V_94 = V_18 -> V_39 ;
V_93 = F_72 ( V_8 , V_84 ) ;
if ( V_93 == NULL )
goto V_95;
if ( V_18 -> V_12 . V_22 &&
F_69 ( V_8 , V_77 , V_18 -> V_12 . V_22 ) )
goto V_95;
if ( F_17 ( V_18 ) )
V_19 = F_68 ( V_18 , V_8 ) ;
else
V_19 = F_65 ( V_18 , V_8 ) ;
if ( V_19 )
goto V_95;
if ( F_73 ( V_8 , & V_18 -> V_27 ) < 0 )
goto V_95;
if ( V_18 -> V_25 )
V_75 |= V_76 ;
if ( V_75 && F_69 ( V_8 , V_74 , V_75 ) )
goto V_95;
F_74 ( V_8 , V_93 ) ;
if ( F_75 ( V_8 , & V_18 -> V_27 ) < 0 )
goto V_95;
return V_8 -> V_54 ;
V_95:
F_76 ( V_8 , V_93 ) ;
return - 1 ;
}
static void F_77 ( struct V_9 * V_10 , struct V_96 * V_35 )
{
struct V_13 * V_14 = F_34 ( V_10 -> V_15 ) ;
struct V_17 * V_18 ;
F_40 (prog, &head->plist, link) {
if ( V_35 -> V_97 < V_35 -> V_98 )
goto V_98;
if ( V_35 -> V_99 ( V_10 , ( unsigned long ) V_18 , V_35 ) < 0 ) {
V_35 -> V_100 = 1 ;
break;
}
V_98:
V_35 -> V_97 ++ ;
}
}
static int T_3 F_78 ( void )
{
return F_79 ( & V_101 ) ;
}
static void T_4 F_80 ( void )
{
F_81 ( & V_101 ) ;
}
