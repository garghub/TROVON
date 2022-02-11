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
static int F_30 ( struct V_1 * V_2 )
{
struct V_34 * V_35 = F_9 ( V_2 ) ;
struct V_1 * V_36 = F_10 ( V_35 -> V_36 ) ;
if ( ! V_36 )
return - V_69 ;
if ( V_36 -> V_70 & V_71 ) {
F_31 ( V_2 ) ;
F_31 ( V_36 ) ;
}
return 0 ;
}
static int F_32 ( struct V_1 * V_2 )
{
struct V_34 * V_35 = F_9 ( V_2 ) ;
struct V_1 * V_36 = F_10 ( V_35 -> V_36 ) ;
F_33 ( V_2 ) ;
if ( V_36 )
F_33 ( V_36 ) ;
return 0 ;
}
static int F_34 ( int V_72 )
{
return V_72 >= V_73 && V_72 <= V_74 ;
}
static int F_35 ( struct V_1 * V_2 , int V_72 )
{
if ( ! F_34 ( V_72 ) )
return - V_75 ;
V_2 -> V_76 = V_72 ;
return 0 ;
}
static int F_36 ( struct V_1 * V_2 )
{
V_2 -> V_51 = F_37 ( struct V_50 ) ;
if ( ! V_2 -> V_51 )
return - V_77 ;
return 0 ;
}
static void F_38 ( struct V_1 * V_2 )
{
F_39 ( V_2 -> V_51 ) ;
F_40 ( V_2 ) ;
}
static void F_41 ( struct V_1 * V_2 )
{
F_42 ( V_2 ) ;
V_2 -> V_78 &= ~ V_79 ;
V_2 -> V_78 |= V_80 ;
V_2 -> V_81 = & V_82 ;
V_2 -> V_83 = & V_84 ;
V_2 -> V_46 |= V_85 ;
V_2 -> V_46 |= V_86 ;
V_2 -> V_87 = F_38 ;
V_2 -> V_88 = V_86 ;
}
static int F_43 ( struct V_89 * V_90 [] , struct V_89 * V_33 [] )
{
if ( V_90 [ V_91 ] ) {
if ( F_44 ( V_90 [ V_91 ] ) != V_92 )
return - V_75 ;
if ( ! F_45 ( F_46 ( V_90 [ V_91 ] ) ) )
return - V_93 ;
}
if ( V_90 [ V_94 ] ) {
if ( ! F_34 ( F_47 ( V_90 [ V_94 ] ) ) )
return - V_75 ;
}
return 0 ;
}
static int F_48 ( struct V_95 * V_96 , struct V_1 * V_2 ,
struct V_89 * V_90 [] , struct V_89 * V_33 [] )
{
int V_97 ;
struct V_1 * V_36 ;
struct V_34 * V_35 ;
char V_98 [ V_99 ] ;
struct V_89 * V_100 [ V_101 + 1 ] , * * V_102 ;
struct V_103 * V_104 ;
struct V_95 * V_95 ;
if ( V_33 != NULL && V_33 [ V_105 ] != NULL ) {
struct V_89 * V_106 ;
V_106 = V_33 [ V_105 ] ;
V_104 = F_46 ( V_106 ) ;
V_97 = F_49 ( V_100 , V_101 ,
F_46 ( V_106 ) + sizeof( struct V_103 ) ,
F_44 ( V_106 ) - sizeof( struct V_103 ) ,
V_107 ) ;
if ( V_97 < 0 )
return V_97 ;
V_97 = F_43 ( V_100 , NULL ) ;
if ( V_97 < 0 )
return V_97 ;
V_102 = V_100 ;
} else {
V_104 = NULL ;
V_102 = V_90 ;
}
if ( V_102 [ V_108 ] )
F_50 ( V_98 , V_102 [ V_108 ] , V_99 ) ;
else
snprintf ( V_98 , V_99 , V_22 L_1 ) ;
V_95 = F_51 ( V_96 , V_102 ) ;
if ( F_52 ( V_95 ) )
return F_53 ( V_95 ) ;
V_36 = F_54 ( V_95 , V_98 , & V_109 , V_102 ) ;
if ( F_52 ( V_36 ) ) {
F_55 ( V_95 ) ;
return F_53 ( V_36 ) ;
}
if ( V_102 [ V_91 ] == NULL )
F_56 ( V_36 ) ;
if ( V_104 && ( V_2 -> V_37 != 0 ) )
V_36 -> V_37 = V_104 -> V_110 ;
V_97 = F_57 ( V_36 ) ;
F_55 ( V_95 ) ;
V_95 = NULL ;
if ( V_97 < 0 )
goto V_111;
F_33 ( V_36 ) ;
V_97 = F_58 ( V_36 , V_104 ) ;
if ( V_97 < 0 )
goto V_112;
if ( V_90 [ V_91 ] == NULL )
F_56 ( V_2 ) ;
if ( V_90 [ V_108 ] )
F_50 ( V_2 -> V_113 , V_90 [ V_108 ] , V_99 ) ;
else
snprintf ( V_2 -> V_113 , V_99 , V_22 L_1 ) ;
if ( strchr ( V_2 -> V_113 , '%' ) ) {
V_97 = F_59 ( V_2 , V_2 -> V_113 ) ;
if ( V_97 < 0 )
goto V_114;
}
V_97 = F_57 ( V_2 ) ;
if ( V_97 < 0 )
goto V_115;
F_33 ( V_2 ) ;
V_35 = F_9 ( V_2 ) ;
F_60 ( V_35 -> V_36 , V_36 ) ;
V_35 = F_9 ( V_36 ) ;
F_60 ( V_35 -> V_36 , V_2 ) ;
return 0 ;
V_115:
V_114:
V_112:
F_61 ( V_36 ) ;
return V_97 ;
V_111:
F_40 ( V_36 ) ;
return V_97 ;
}
static void F_62 ( struct V_1 * V_2 , struct V_116 * V_117 )
{
struct V_34 * V_35 ;
struct V_1 * V_36 ;
V_35 = F_9 ( V_2 ) ;
V_36 = F_10 ( V_35 -> V_36 ) ;
F_63 ( V_35 -> V_36 , NULL ) ;
F_64 ( V_2 , V_117 ) ;
if ( V_36 ) {
V_35 = F_9 ( V_36 ) ;
F_63 ( V_35 -> V_36 , NULL ) ;
F_64 ( V_36 , V_117 ) ;
}
}
static T_5 int F_65 ( void )
{
return F_66 ( & V_109 ) ;
}
static T_6 void F_67 ( void )
{
F_68 ( & V_109 ) ;
}
