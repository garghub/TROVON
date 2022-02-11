static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
V_4 -> V_5 = 0 ;
V_4 -> V_6 = 0 ;
F_2 ( V_4 , V_7 ) ;
V_4 -> V_8 = V_9 ;
V_4 -> V_10 = V_11 ;
V_4 -> V_12 = 0 ;
V_4 -> V_13 = V_14 ;
V_4 -> V_15 = V_16 ;
V_4 -> V_17 = 0 ;
V_4 -> V_18 = 0 ;
return 0 ;
}
static void F_3 ( struct V_1 * V_2 , struct V_19 * V_20 )
{
F_4 ( V_20 -> V_21 , V_22 , sizeof( V_20 -> V_21 ) ) ;
F_4 ( V_20 -> V_23 , V_24 , sizeof( V_20 -> V_23 ) ) ;
}
static void F_5 ( struct V_1 * V_2 , T_1 V_25 , T_2 * V_26 )
{
switch( V_25 ) {
case V_27 :
memcpy ( V_26 , & V_28 , sizeof( V_28 ) ) ;
break;
}
}
static int F_6 ( struct V_1 * V_2 , int V_29 )
{
switch ( V_29 ) {
case V_27 :
return F_7 ( V_28 ) ;
default:
return - V_30 ;
}
}
static void F_8 ( struct V_1 * V_2 ,
struct V_31 * V_32 , T_3 * V_33 )
{
struct V_34 * V_35 = F_9 ( V_2 ) ;
struct V_1 * V_36 = F_10 ( V_35 -> V_36 ) ;
V_33 [ 0 ] = V_36 ? V_36 -> V_37 : 0 ;
}
static T_4 F_11 ( struct V_38 * V_39 , struct V_1 * V_2 )
{
struct V_34 * V_35 = F_9 ( V_2 ) ;
struct V_1 * V_40 ;
int V_41 = V_39 -> V_42 ;
F_12 () ;
V_40 = F_13 ( V_35 -> V_36 ) ;
if ( F_14 ( ! V_40 ) ) {
F_15 ( V_39 ) ;
goto V_43;
}
if ( V_39 -> V_44 == V_45 &&
V_40 -> V_46 & V_47 )
V_39 -> V_44 = V_48 ;
if ( F_16 ( F_17 ( V_40 , V_39 ) == V_49 ) ) {
struct V_50 * V_32 = F_18 ( V_2 -> V_51 ) ;
F_19 ( & V_32 -> V_52 ) ;
V_32 -> V_53 += V_41 ;
V_32 -> V_54 ++ ;
F_20 ( & V_32 -> V_52 ) ;
} else {
V_43:
F_21 ( & V_35 -> V_55 ) ;
}
F_22 () ;
return V_56 ;
}
static T_3 F_23 ( struct V_50 * V_57 , struct V_1 * V_2 )
{
struct V_34 * V_35 = F_9 ( V_2 ) ;
int V_58 ;
V_57 -> V_54 = 0 ;
V_57 -> V_53 = 0 ;
F_24 (cpu) {
struct V_50 * V_32 = F_25 ( V_2 -> V_51 , V_58 ) ;
T_3 V_54 , V_53 ;
unsigned int V_59 ;
do {
V_59 = F_26 ( & V_32 -> V_52 ) ;
V_54 = V_32 -> V_54 ;
V_53 = V_32 -> V_53 ;
} while ( F_27 ( & V_32 -> V_52 , V_59 ) );
V_57 -> V_54 += V_54 ;
V_57 -> V_53 += V_53 ;
}
return F_28 ( & V_35 -> V_55 ) ;
}
static struct V_60 * F_29 ( struct V_1 * V_2 ,
struct V_60 * V_61 )
{
struct V_34 * V_35 = F_9 ( V_2 ) ;
struct V_1 * V_36 ;
struct V_50 V_62 ;
V_61 -> V_63 = F_23 ( & V_62 , V_2 ) ;
V_61 -> V_64 = V_62 . V_53 ;
V_61 -> V_65 = V_62 . V_54 ;
F_12 () ;
V_36 = F_13 ( V_35 -> V_36 ) ;
if ( V_36 ) {
V_61 -> V_66 = F_23 ( & V_62 , V_36 ) ;
V_61 -> V_67 = V_62 . V_53 ;
V_61 -> V_68 = V_62 . V_54 ;
}
F_22 () ;
return V_61 ;
}
static void F_30 ( struct V_1 * V_2 )
{
}
static int F_31 ( struct V_1 * V_2 )
{
struct V_34 * V_35 = F_9 ( V_2 ) ;
struct V_1 * V_36 = F_10 ( V_35 -> V_36 ) ;
if ( ! V_36 )
return - V_69 ;
if ( V_36 -> V_70 & V_71 ) {
F_32 ( V_2 ) ;
F_32 ( V_36 ) ;
}
return 0 ;
}
static int F_33 ( struct V_1 * V_2 )
{
struct V_34 * V_35 = F_9 ( V_2 ) ;
struct V_1 * V_36 = F_10 ( V_35 -> V_36 ) ;
F_34 ( V_2 ) ;
if ( V_36 )
F_34 ( V_36 ) ;
return 0 ;
}
static int F_35 ( int V_72 )
{
return V_72 >= V_73 && V_72 <= V_74 ;
}
static int F_36 ( struct V_1 * V_2 , int V_72 )
{
if ( ! F_35 ( V_72 ) )
return - V_75 ;
V_2 -> V_76 = V_72 ;
return 0 ;
}
static int F_37 ( struct V_1 * V_2 )
{
int V_77 ;
V_2 -> V_51 = F_38 ( struct V_50 ) ;
if ( ! V_2 -> V_51 )
return - V_78 ;
F_24 (i) {
struct V_50 * V_79 ;
V_79 = F_25 ( V_2 -> V_51 , V_77 ) ;
F_39 ( & V_79 -> V_52 ) ;
}
return 0 ;
}
static void F_40 ( struct V_1 * V_2 )
{
F_41 ( V_2 -> V_51 ) ;
F_42 ( V_2 ) ;
}
static void F_43 ( struct V_1 * V_2 )
{
F_44 ( V_2 ) ;
V_2 -> V_80 &= ~ V_81 ;
V_2 -> V_80 |= V_82 ;
V_2 -> V_83 = & V_84 ;
V_2 -> V_85 = & V_86 ;
V_2 -> V_46 |= V_87 ;
V_2 -> V_46 |= V_88 ;
V_2 -> V_89 = V_2 -> V_46 ;
V_2 -> V_90 = F_40 ;
V_2 -> V_91 = V_88 ;
V_2 -> V_92 = V_88 ;
}
static int F_45 ( struct V_93 * V_94 [] , struct V_93 * V_33 [] )
{
if ( V_94 [ V_95 ] ) {
if ( F_46 ( V_94 [ V_95 ] ) != V_96 )
return - V_75 ;
if ( ! F_47 ( F_48 ( V_94 [ V_95 ] ) ) )
return - V_97 ;
}
if ( V_94 [ V_98 ] ) {
if ( ! F_35 ( F_49 ( V_94 [ V_98 ] ) ) )
return - V_75 ;
}
return 0 ;
}
static int F_50 ( struct V_99 * V_100 , struct V_1 * V_2 ,
struct V_93 * V_94 [] , struct V_93 * V_33 [] )
{
int V_101 ;
struct V_1 * V_36 ;
struct V_34 * V_35 ;
char V_102 [ V_103 ] ;
struct V_93 * V_104 [ V_105 + 1 ] , * * V_106 ;
struct V_107 * V_108 ;
struct V_99 * V_99 ;
if ( V_33 != NULL && V_33 [ V_109 ] != NULL ) {
struct V_93 * V_110 ;
V_110 = V_33 [ V_109 ] ;
V_108 = F_48 ( V_110 ) ;
V_101 = F_51 ( V_104 , V_105 ,
F_48 ( V_110 ) + sizeof( struct V_107 ) ,
F_46 ( V_110 ) - sizeof( struct V_107 ) ,
V_111 ) ;
if ( V_101 < 0 )
return V_101 ;
V_101 = F_45 ( V_104 , NULL ) ;
if ( V_101 < 0 )
return V_101 ;
V_106 = V_104 ;
} else {
V_108 = NULL ;
V_106 = V_94 ;
}
if ( V_106 [ V_112 ] )
F_52 ( V_102 , V_106 [ V_112 ] , V_103 ) ;
else
snprintf ( V_102 , V_103 , V_22 L_1 ) ;
V_99 = F_53 ( V_100 , V_106 ) ;
if ( F_54 ( V_99 ) )
return F_55 ( V_99 ) ;
V_36 = F_56 ( V_99 , V_102 , & V_113 , V_106 ) ;
if ( F_54 ( V_36 ) ) {
F_57 ( V_99 ) ;
return F_55 ( V_36 ) ;
}
if ( V_106 [ V_95 ] == NULL )
F_58 ( V_36 ) ;
if ( V_108 && ( V_2 -> V_37 != 0 ) )
V_36 -> V_37 = V_108 -> V_114 ;
V_101 = F_59 ( V_36 ) ;
F_57 ( V_99 ) ;
V_99 = NULL ;
if ( V_101 < 0 )
goto V_115;
F_34 ( V_36 ) ;
V_101 = F_60 ( V_36 , V_108 ) ;
if ( V_101 < 0 )
goto V_116;
if ( V_94 [ V_95 ] == NULL )
F_58 ( V_2 ) ;
if ( V_94 [ V_112 ] )
F_52 ( V_2 -> V_117 , V_94 [ V_112 ] , V_103 ) ;
else
snprintf ( V_2 -> V_117 , V_103 , V_22 L_1 ) ;
V_101 = F_59 ( V_2 ) ;
if ( V_101 < 0 )
goto V_118;
F_34 ( V_2 ) ;
V_35 = F_9 ( V_2 ) ;
F_61 ( V_35 -> V_36 , V_36 ) ;
V_35 = F_9 ( V_36 ) ;
F_61 ( V_35 -> V_36 , V_2 ) ;
return 0 ;
V_118:
V_116:
F_62 ( V_36 ) ;
return V_101 ;
V_115:
F_42 ( V_36 ) ;
return V_101 ;
}
static void F_63 ( struct V_1 * V_2 , struct V_119 * V_120 )
{
struct V_34 * V_35 ;
struct V_1 * V_36 ;
V_35 = F_9 ( V_2 ) ;
V_36 = F_10 ( V_35 -> V_36 ) ;
F_64 ( V_35 -> V_36 , NULL ) ;
F_65 ( V_2 , V_120 ) ;
if ( V_36 ) {
V_35 = F_9 ( V_36 ) ;
F_64 ( V_35 -> V_36 , NULL ) ;
F_65 ( V_36 , V_120 ) ;
}
}
static T_5 int F_66 ( void )
{
return F_67 ( & V_113 ) ;
}
static T_6 void F_68 ( void )
{
F_69 ( & V_113 ) ;
}
