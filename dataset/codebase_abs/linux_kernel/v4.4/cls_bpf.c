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
struct V_16 * V_17 ;
#ifdef F_4
bool V_18 = F_5 ( V_8 -> V_19 ) & V_20 ;
#else
bool V_18 = false ;
#endif
int V_21 = - 1 ;
if ( F_6 ( ! F_7 ( V_8 ) ) )
return - 1 ;
F_8 () ;
F_9 (prog, &head->plist, link) {
int V_22 ;
F_10 ( V_8 ) -> V_23 = V_17 -> V_12 . V_24 ;
if ( V_18 ) {
F_11 ( V_8 , V_8 -> V_25 ) ;
V_22 = F_12 ( V_17 -> V_26 , V_8 ) ;
F_13 ( V_8 , V_8 -> V_25 ) ;
} else {
V_22 = F_12 ( V_17 -> V_26 , V_8 ) ;
}
if ( V_17 -> V_27 ) {
V_12 -> V_28 = V_17 -> V_12 . V_28 ;
V_12 -> V_24 = F_10 ( V_8 ) -> V_23 ;
V_21 = F_1 ( V_22 ) ;
if ( V_21 == V_6 )
continue;
break;
}
if ( V_22 == 0 )
continue;
* V_12 = V_17 -> V_12 ;
if ( V_22 != - 1 )
V_12 -> V_24 = V_22 ;
V_21 = F_14 ( V_8 , & V_17 -> V_29 , V_12 ) ;
if ( V_21 < 0 )
continue;
break;
}
F_15 () ;
return V_21 ;
}
static bool F_16 ( const struct V_16 * V_17 )
{
return ! V_17 -> V_30 ;
}
static int F_17 ( struct V_9 * V_10 )
{
struct V_13 * V_14 ;
V_14 = F_18 ( sizeof( * V_14 ) , V_31 ) ;
if ( V_14 == NULL )
return - V_32 ;
F_19 ( & V_14 -> V_33 ) ;
F_20 ( V_10 -> V_15 , V_14 ) ;
return 0 ;
}
static void F_21 ( struct V_9 * V_10 , struct V_16 * V_17 )
{
F_22 ( & V_17 -> V_29 ) ;
if ( F_16 ( V_17 ) )
F_23 ( V_17 -> V_26 ) ;
else
F_24 ( V_17 -> V_26 ) ;
F_25 ( V_17 -> V_34 ) ;
F_25 ( V_17 -> V_30 ) ;
F_25 ( V_17 ) ;
}
static void F_26 ( struct V_35 * V_36 )
{
struct V_16 * V_17 = F_27 ( V_36 , struct V_16 , V_36 ) ;
F_21 ( V_17 -> V_10 , V_17 ) ;
}
static int F_28 ( struct V_9 * V_10 , unsigned long V_37 )
{
struct V_16 * V_17 = (struct V_16 * ) V_37 ;
F_29 ( & V_17 -> V_38 ) ;
F_30 ( V_10 , & V_17 -> V_12 ) ;
F_31 ( & V_17 -> V_36 , F_26 ) ;
return 0 ;
}
static bool F_32 ( struct V_9 * V_10 , bool V_39 )
{
struct V_13 * V_14 = F_33 ( V_10 -> V_15 ) ;
struct V_16 * V_17 , * V_40 ;
if ( ! V_39 && ! F_34 ( & V_14 -> V_33 ) )
return false ;
F_35 (prog, tmp, &head->plist, link) {
F_29 ( & V_17 -> V_38 ) ;
F_30 ( V_10 , & V_17 -> V_12 ) ;
F_31 ( & V_17 -> V_36 , F_26 ) ;
}
F_36 ( V_10 -> V_15 , NULL ) ;
F_37 ( V_14 , V_36 ) ;
return true ;
}
static unsigned long F_38 ( struct V_9 * V_10 , T_1 V_41 )
{
struct V_13 * V_14 = F_33 ( V_10 -> V_15 ) ;
struct V_16 * V_17 ;
unsigned long V_21 = 0UL ;
if ( V_14 == NULL )
return 0UL ;
F_39 (prog, &head->plist, link) {
if ( V_17 -> V_41 == V_41 ) {
V_21 = ( unsigned long ) V_17 ;
break;
}
}
return V_21 ;
}
static int F_40 ( struct V_42 * * V_43 , struct V_16 * V_17 )
{
struct V_44 * V_30 ;
struct V_45 V_46 ;
struct V_47 * V_48 ;
T_2 V_49 , V_50 ;
int V_21 ;
V_50 = F_41 ( V_43 [ V_51 ] ) ;
if ( V_50 > V_52 || V_50 == 0 )
return - V_53 ;
V_49 = V_50 * sizeof( * V_30 ) ;
if ( V_49 != F_42 ( V_43 [ V_54 ] ) )
return - V_53 ;
V_30 = F_18 ( V_49 , V_31 ) ;
if ( V_30 == NULL )
return - V_55 ;
memcpy ( V_30 , F_43 ( V_43 [ V_54 ] ) , V_49 ) ;
V_46 . V_56 = V_50 ;
V_46 . V_26 = V_30 ;
V_21 = F_44 ( & V_48 , & V_46 ) ;
if ( V_21 < 0 ) {
F_25 ( V_30 ) ;
return V_21 ;
}
V_17 -> V_30 = V_30 ;
V_17 -> V_50 = V_50 ;
V_17 -> V_34 = NULL ;
V_17 -> V_26 = V_48 ;
return 0 ;
}
static int F_45 ( struct V_42 * * V_43 , struct V_16 * V_17 ,
const struct V_9 * V_10 )
{
struct V_47 * V_48 ;
char * V_57 = NULL ;
T_1 V_58 ;
V_58 = F_46 ( V_43 [ V_59 ] ) ;
V_48 = F_47 ( V_58 ) ;
if ( F_48 ( V_48 ) )
return F_49 ( V_48 ) ;
if ( V_48 -> type != V_60 ) {
F_23 ( V_48 ) ;
return - V_53 ;
}
if ( V_43 [ V_61 ] ) {
V_57 = F_50 ( F_43 ( V_43 [ V_61 ] ) ,
F_42 ( V_43 [ V_61 ] ) ,
V_31 ) ;
if ( ! V_57 ) {
F_23 ( V_48 ) ;
return - V_55 ;
}
}
V_17 -> V_30 = NULL ;
V_17 -> V_58 = V_58 ;
V_17 -> V_34 = V_57 ;
V_17 -> V_26 = V_48 ;
if ( V_48 -> V_62 )
F_51 ( F_52 ( V_10 -> V_63 ) ) ;
return 0 ;
}
static int F_53 ( struct V_64 * V_64 , struct V_9 * V_10 ,
struct V_16 * V_17 ,
unsigned long V_65 , struct V_42 * * V_43 ,
struct V_42 * V_66 , bool V_67 )
{
bool V_68 , V_69 , V_70 = false ;
struct V_71 V_29 ;
int V_21 ;
V_68 = V_43 [ V_51 ] && V_43 [ V_54 ] ;
V_69 = V_43 [ V_59 ] ;
if ( ( ! V_68 && ! V_69 ) || ( V_68 && V_69 ) )
return - V_53 ;
F_54 ( & V_29 , V_72 , V_73 ) ;
V_21 = F_55 ( V_64 , V_10 , V_43 , V_66 , & V_29 , V_67 ) ;
if ( V_21 < 0 )
return V_21 ;
if ( V_43 [ V_74 ] ) {
T_1 V_75 = F_46 ( V_43 [ V_74 ] ) ;
if ( V_75 & ~ V_76 ) {
F_22 ( & V_29 ) ;
return - V_53 ;
}
V_70 = V_75 & V_76 ;
}
V_17 -> V_27 = V_70 ;
V_21 = V_68 ? F_40 ( V_43 , V_17 ) :
F_45 ( V_43 , V_17 , V_10 ) ;
if ( V_21 < 0 ) {
F_22 ( & V_29 ) ;
return V_21 ;
}
if ( V_43 [ V_77 ] ) {
V_17 -> V_12 . V_24 = F_46 ( V_43 [ V_77 ] ) ;
F_56 ( V_10 , & V_17 -> V_12 , V_65 ) ;
}
F_57 ( V_10 , & V_17 -> V_29 , & V_29 ) ;
return 0 ;
}
static T_1 F_58 ( struct V_9 * V_10 ,
struct V_13 * V_14 )
{
unsigned int V_78 = 0x80000000 ;
T_1 V_41 ;
do {
if ( ++ V_14 -> V_79 == 0x7FFFFFFF )
V_14 -> V_79 = 1 ;
} while ( -- V_78 > 0 && F_38 ( V_10 , V_14 -> V_79 ) );
if ( F_6 ( V_78 == 0 ) ) {
F_59 ( L_1 ) ;
V_41 = 0 ;
} else {
V_41 = V_14 -> V_79 ;
}
return V_41 ;
}
static int F_60 ( struct V_64 * V_64 , struct V_7 * V_80 ,
struct V_9 * V_10 , unsigned long V_65 ,
T_1 V_41 , struct V_42 * * V_81 ,
unsigned long * V_37 , bool V_67 )
{
struct V_13 * V_14 = F_33 ( V_10 -> V_15 ) ;
struct V_16 * V_82 = (struct V_16 * ) * V_37 ;
struct V_42 * V_43 [ V_83 + 1 ] ;
struct V_16 * V_17 ;
int V_21 ;
if ( V_81 [ V_84 ] == NULL )
return - V_53 ;
V_21 = F_61 ( V_43 , V_83 , V_81 [ V_84 ] , V_85 ) ;
if ( V_21 < 0 )
return V_21 ;
V_17 = F_18 ( sizeof( * V_17 ) , V_31 ) ;
if ( ! V_17 )
return - V_32 ;
F_54 ( & V_17 -> V_29 , V_72 , V_73 ) ;
if ( V_82 ) {
if ( V_41 && V_82 -> V_41 != V_41 ) {
V_21 = - V_53 ;
goto V_86;
}
}
if ( V_41 == 0 )
V_17 -> V_41 = F_58 ( V_10 , V_14 ) ;
else
V_17 -> V_41 = V_41 ;
if ( V_17 -> V_41 == 0 ) {
V_21 = - V_53 ;
goto V_86;
}
V_21 = F_53 ( V_64 , V_10 , V_17 , V_65 , V_43 , V_81 [ V_87 ] , V_67 ) ;
if ( V_21 < 0 )
goto V_86;
if ( V_82 ) {
F_62 ( & V_82 -> V_38 , & V_17 -> V_38 ) ;
F_30 ( V_10 , & V_82 -> V_12 ) ;
F_31 ( & V_82 -> V_36 , F_26 ) ;
} else {
F_63 ( & V_17 -> V_38 , & V_14 -> V_33 ) ;
}
* V_37 = ( unsigned long ) V_17 ;
return 0 ;
V_86:
F_25 ( V_17 ) ;
return V_21 ;
}
static int F_64 ( const struct V_16 * V_17 ,
struct V_7 * V_8 )
{
struct V_42 * V_88 ;
if ( F_65 ( V_8 , V_51 , V_17 -> V_50 ) )
return - V_89 ;
V_88 = F_66 ( V_8 , V_54 , V_17 -> V_50 *
sizeof( struct V_44 ) ) ;
if ( V_88 == NULL )
return - V_89 ;
memcpy ( F_43 ( V_88 ) , V_17 -> V_30 , F_42 ( V_88 ) ) ;
return 0 ;
}
static int F_67 ( const struct V_16 * V_17 ,
struct V_7 * V_8 )
{
if ( F_68 ( V_8 , V_59 , V_17 -> V_58 ) )
return - V_89 ;
if ( V_17 -> V_34 &&
F_69 ( V_8 , V_61 , V_17 -> V_34 ) )
return - V_89 ;
return 0 ;
}
static int F_70 ( struct V_64 * V_64 , struct V_9 * V_10 , unsigned long V_90 ,
struct V_7 * V_8 , struct V_91 * V_92 )
{
struct V_16 * V_17 = (struct V_16 * ) V_90 ;
struct V_42 * V_93 ;
T_1 V_75 = 0 ;
int V_21 ;
if ( V_17 == NULL )
return V_8 -> V_56 ;
V_92 -> V_94 = V_17 -> V_41 ;
V_93 = F_71 ( V_8 , V_84 ) ;
if ( V_93 == NULL )
goto V_95;
if ( V_17 -> V_12 . V_24 &&
F_68 ( V_8 , V_77 , V_17 -> V_12 . V_24 ) )
goto V_95;
if ( F_16 ( V_17 ) )
V_21 = F_67 ( V_17 , V_8 ) ;
else
V_21 = F_64 ( V_17 , V_8 ) ;
if ( V_21 )
goto V_95;
if ( F_72 ( V_8 , & V_17 -> V_29 ) < 0 )
goto V_95;
if ( V_17 -> V_27 )
V_75 |= V_76 ;
if ( V_75 && F_68 ( V_8 , V_74 , V_75 ) )
goto V_95;
F_73 ( V_8 , V_93 ) ;
if ( F_74 ( V_8 , & V_17 -> V_29 ) < 0 )
goto V_95;
return V_8 -> V_56 ;
V_95:
F_75 ( V_8 , V_93 ) ;
return - 1 ;
}
static void F_76 ( struct V_9 * V_10 , struct V_96 * V_37 )
{
struct V_13 * V_14 = F_33 ( V_10 -> V_15 ) ;
struct V_16 * V_17 ;
F_39 (prog, &head->plist, link) {
if ( V_37 -> V_97 < V_37 -> V_98 )
goto V_98;
if ( V_37 -> V_99 ( V_10 , ( unsigned long ) V_17 , V_37 ) < 0 ) {
V_37 -> V_100 = 1 ;
break;
}
V_98:
V_37 -> V_97 ++ ;
}
}
static int T_3 F_77 ( void )
{
return F_78 ( & V_101 ) ;
}
static void T_4 F_79 ( void )
{
F_80 ( & V_101 ) ;
}
