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
if ( F_16 ( F_17 ( V_40 , V_39 ) == V_44 ) ) {
struct V_45 * V_32 = F_18 ( V_2 -> V_46 ) ;
F_19 ( & V_32 -> V_47 ) ;
V_32 -> V_48 += V_41 ;
V_32 -> V_49 ++ ;
F_20 ( & V_32 -> V_47 ) ;
} else {
V_43:
F_21 ( & V_35 -> V_50 ) ;
}
F_22 () ;
return V_51 ;
}
static T_3 F_23 ( struct V_45 * V_52 , struct V_1 * V_2 )
{
struct V_34 * V_35 = F_9 ( V_2 ) ;
int V_53 ;
V_52 -> V_49 = 0 ;
V_52 -> V_48 = 0 ;
F_24 (cpu) {
struct V_45 * V_32 = F_25 ( V_2 -> V_46 , V_53 ) ;
T_3 V_49 , V_48 ;
unsigned int V_54 ;
do {
V_54 = F_26 ( & V_32 -> V_47 ) ;
V_49 = V_32 -> V_49 ;
V_48 = V_32 -> V_48 ;
} while ( F_27 ( & V_32 -> V_47 , V_54 ) );
V_52 -> V_49 += V_49 ;
V_52 -> V_48 += V_48 ;
}
return F_28 ( & V_35 -> V_50 ) ;
}
static struct V_55 * F_29 ( struct V_1 * V_2 ,
struct V_55 * V_56 )
{
struct V_34 * V_35 = F_9 ( V_2 ) ;
struct V_1 * V_36 ;
struct V_45 V_57 ;
V_56 -> V_58 = F_23 ( & V_57 , V_2 ) ;
V_56 -> V_59 = V_57 . V_48 ;
V_56 -> V_60 = V_57 . V_49 ;
F_12 () ;
V_36 = F_13 ( V_35 -> V_36 ) ;
if ( V_36 ) {
V_56 -> V_61 = F_23 ( & V_57 , V_36 ) ;
V_56 -> V_62 = V_57 . V_48 ;
V_56 -> V_63 = V_57 . V_49 ;
}
F_22 () ;
return V_56 ;
}
static void F_30 ( struct V_1 * V_2 )
{
}
static int F_31 ( struct V_1 * V_2 )
{
struct V_34 * V_35 = F_9 ( V_2 ) ;
struct V_1 * V_36 = F_10 ( V_35 -> V_36 ) ;
if ( ! V_36 )
return - V_64 ;
if ( V_36 -> V_65 & V_66 ) {
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
static int F_35 ( int V_67 )
{
return V_67 >= V_68 && V_67 <= V_69 ;
}
static int F_36 ( struct V_1 * V_2 , int V_67 )
{
if ( ! F_35 ( V_67 ) )
return - V_70 ;
V_2 -> V_71 = V_67 ;
return 0 ;
}
static int F_37 ( struct V_1 * V_2 )
{
V_2 -> V_46 = F_38 ( struct V_45 ) ;
if ( ! V_2 -> V_46 )
return - V_72 ;
return 0 ;
}
static void F_39 ( struct V_1 * V_2 )
{
F_40 ( V_2 -> V_46 ) ;
F_41 ( V_2 ) ;
}
static void F_42 ( struct V_1 * V_2 )
{
}
static int F_43 ( const struct V_1 * V_2 )
{
struct V_34 * V_35 = F_9 ( V_2 ) ;
struct V_1 * V_36 ;
int V_73 ;
F_12 () ;
V_36 = F_13 ( V_35 -> V_36 ) ;
V_73 = V_36 ? V_36 -> V_37 : 0 ;
F_22 () ;
return V_73 ;
}
static void F_44 ( struct V_1 * V_2 )
{
F_45 ( V_2 ) ;
V_2 -> V_74 &= ~ V_75 ;
V_2 -> V_74 |= V_76 ;
V_2 -> V_74 |= V_77 ;
V_2 -> V_78 = & V_79 ;
V_2 -> V_80 = & V_81 ;
V_2 -> V_82 |= V_83 ;
V_2 -> V_82 |= V_84 ;
V_2 -> V_85 = V_2 -> V_82 &
~ ( V_86 |
V_87 |
V_88 |
V_89 ) ;
V_2 -> V_90 = F_39 ;
V_2 -> V_91 = V_84 ;
V_2 -> V_92 = V_84 ;
}
static int F_46 ( struct V_93 * V_94 [] , struct V_93 * V_33 [] )
{
if ( V_94 [ V_95 ] ) {
if ( F_47 ( V_94 [ V_95 ] ) != V_96 )
return - V_70 ;
if ( ! F_48 ( F_49 ( V_94 [ V_95 ] ) ) )
return - V_97 ;
}
if ( V_94 [ V_98 ] ) {
if ( ! F_35 ( F_50 ( V_94 [ V_98 ] ) ) )
return - V_70 ;
}
return 0 ;
}
static int F_51 ( struct V_99 * V_100 , struct V_1 * V_2 ,
struct V_93 * V_94 [] , struct V_93 * V_33 [] )
{
int V_101 ;
struct V_1 * V_36 ;
struct V_34 * V_35 ;
char V_102 [ V_103 ] ;
struct V_93 * V_104 [ V_105 + 1 ] , * * V_106 ;
unsigned char V_107 ;
struct V_108 * V_109 ;
struct V_99 * V_99 ;
if ( V_33 != NULL && V_33 [ V_110 ] != NULL ) {
struct V_93 * V_111 ;
V_111 = V_33 [ V_110 ] ;
V_109 = F_49 ( V_111 ) ;
V_101 = F_52 ( V_104 ,
F_49 ( V_111 ) + sizeof( struct V_108 ) ,
F_47 ( V_111 ) - sizeof( struct V_108 ) ) ;
if ( V_101 < 0 )
return V_101 ;
V_101 = F_46 ( V_104 , NULL ) ;
if ( V_101 < 0 )
return V_101 ;
V_106 = V_104 ;
} else {
V_109 = NULL ;
V_106 = V_94 ;
}
if ( V_106 [ V_112 ] ) {
F_53 ( V_102 , V_106 [ V_112 ] , V_103 ) ;
V_107 = V_113 ;
} else {
snprintf ( V_102 , V_103 , V_22 L_1 ) ;
V_107 = V_114 ;
}
V_99 = F_54 ( V_100 , V_106 ) ;
if ( F_55 ( V_99 ) )
return F_56 ( V_99 ) ;
V_36 = F_57 ( V_99 , V_102 , V_107 ,
& V_115 , V_106 ) ;
if ( F_55 ( V_36 ) ) {
F_58 ( V_99 ) ;
return F_56 ( V_36 ) ;
}
if ( V_106 [ V_95 ] == NULL )
F_59 ( V_36 ) ;
if ( V_109 && ( V_2 -> V_37 != 0 ) )
V_36 -> V_37 = V_109 -> V_116 ;
V_101 = F_60 ( V_36 ) ;
F_58 ( V_99 ) ;
V_99 = NULL ;
if ( V_101 < 0 )
goto V_117;
F_34 ( V_36 ) ;
V_101 = F_61 ( V_36 , V_109 ) ;
if ( V_101 < 0 )
goto V_118;
if ( V_94 [ V_95 ] == NULL )
F_59 ( V_2 ) ;
if ( V_94 [ V_112 ] )
F_53 ( V_2 -> V_119 , V_94 [ V_112 ] , V_103 ) ;
else
snprintf ( V_2 -> V_119 , V_103 , V_22 L_1 ) ;
V_101 = F_60 ( V_2 ) ;
if ( V_101 < 0 )
goto V_120;
F_34 ( V_2 ) ;
V_35 = F_9 ( V_2 ) ;
F_62 ( V_35 -> V_36 , V_36 ) ;
V_35 = F_9 ( V_36 ) ;
F_62 ( V_35 -> V_36 , V_2 ) ;
return 0 ;
V_120:
V_118:
F_63 ( V_36 ) ;
return V_101 ;
V_117:
F_41 ( V_36 ) ;
return V_101 ;
}
static void F_64 ( struct V_1 * V_2 , struct V_121 * V_122 )
{
struct V_34 * V_35 ;
struct V_1 * V_36 ;
V_35 = F_9 ( V_2 ) ;
V_36 = F_10 ( V_35 -> V_36 ) ;
F_65 ( V_35 -> V_36 , NULL ) ;
F_66 ( V_2 , V_122 ) ;
if ( V_36 ) {
V_35 = F_9 ( V_36 ) ;
F_65 ( V_35 -> V_36 , NULL ) ;
F_66 ( V_36 , V_122 ) ;
}
}
static struct V_99 * F_67 ( const struct V_1 * V_2 )
{
struct V_34 * V_35 = F_9 ( V_2 ) ;
struct V_1 * V_36 = F_10 ( V_35 -> V_36 ) ;
return V_36 ? F_68 ( V_36 ) : F_68 ( V_2 ) ;
}
static T_5 int F_69 ( void )
{
return F_70 ( & V_115 ) ;
}
static T_6 void F_71 ( void )
{
F_72 ( & V_115 ) ;
}
