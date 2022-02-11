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
static void F_44 ( struct V_1 * V_2 , int V_74 )
{
struct V_34 * V_75 , * V_35 = F_9 ( V_2 ) ;
struct V_1 * V_36 ;
if ( V_74 < 0 )
V_74 = 0 ;
F_12 () ;
V_36 = F_13 ( V_35 -> V_36 ) ;
if ( F_14 ( ! V_36 ) )
goto V_76;
V_75 = F_9 ( V_36 ) ;
V_35 -> V_77 = V_74 ;
V_74 = F_45 ( V_35 -> V_77 , V_75 -> V_77 ) ;
V_2 -> V_78 = V_74 ;
V_36 -> V_78 = V_74 ;
V_76:
F_22 () ;
}
static void F_46 ( struct V_1 * V_2 )
{
F_47 ( V_2 ) ;
V_2 -> V_79 &= ~ V_80 ;
V_2 -> V_79 |= V_81 ;
V_2 -> V_79 |= V_82 ;
V_2 -> V_79 |= V_83 ;
V_2 -> V_84 = & V_85 ;
V_2 -> V_86 = & V_87 ;
V_2 -> V_88 |= V_89 ;
V_2 -> V_88 |= V_90 ;
V_2 -> V_91 = V_2 -> V_88 &
~ ( V_92 |
V_93 |
V_94 |
V_95 ) ;
V_2 -> V_96 = F_39 ;
V_2 -> V_97 = V_90 ;
V_2 -> V_98 = V_90 ;
}
static int F_48 ( struct V_99 * V_100 [] , struct V_99 * V_33 [] )
{
if ( V_100 [ V_101 ] ) {
if ( F_49 ( V_100 [ V_101 ] ) != V_102 )
return - V_70 ;
if ( ! F_50 ( F_51 ( V_100 [ V_101 ] ) ) )
return - V_103 ;
}
if ( V_100 [ V_104 ] ) {
if ( ! F_35 ( F_52 ( V_100 [ V_104 ] ) ) )
return - V_70 ;
}
return 0 ;
}
static int F_53 ( struct V_105 * V_106 , struct V_1 * V_2 ,
struct V_99 * V_100 [] , struct V_99 * V_33 [] )
{
int V_107 ;
struct V_1 * V_36 ;
struct V_34 * V_35 ;
char V_108 [ V_109 ] ;
struct V_99 * V_110 [ V_111 + 1 ] , * * V_112 ;
unsigned char V_113 ;
struct V_114 * V_115 ;
struct V_105 * V_105 ;
if ( V_33 != NULL && V_33 [ V_116 ] != NULL ) {
struct V_99 * V_117 ;
V_117 = V_33 [ V_116 ] ;
V_115 = F_51 ( V_117 ) ;
V_107 = F_54 ( V_110 ,
F_51 ( V_117 ) + sizeof( struct V_114 ) ,
F_49 ( V_117 ) - sizeof( struct V_114 ) ) ;
if ( V_107 < 0 )
return V_107 ;
V_107 = F_48 ( V_110 , NULL ) ;
if ( V_107 < 0 )
return V_107 ;
V_112 = V_110 ;
} else {
V_115 = NULL ;
V_112 = V_100 ;
}
if ( V_112 [ V_118 ] ) {
F_55 ( V_108 , V_112 [ V_118 ] , V_109 ) ;
V_113 = V_119 ;
} else {
snprintf ( V_108 , V_109 , V_22 L_1 ) ;
V_113 = V_120 ;
}
V_105 = F_56 ( V_106 , V_112 ) ;
if ( F_57 ( V_105 ) )
return F_58 ( V_105 ) ;
V_36 = F_59 ( V_105 , V_108 , V_113 ,
& V_121 , V_112 ) ;
if ( F_57 ( V_36 ) ) {
F_60 ( V_105 ) ;
return F_58 ( V_36 ) ;
}
if ( V_112 [ V_101 ] == NULL )
F_61 ( V_36 ) ;
if ( V_115 && ( V_2 -> V_37 != 0 ) )
V_36 -> V_37 = V_115 -> V_122 ;
V_107 = F_62 ( V_36 ) ;
F_60 ( V_105 ) ;
V_105 = NULL ;
if ( V_107 < 0 )
goto V_123;
F_34 ( V_36 ) ;
V_107 = F_63 ( V_36 , V_115 ) ;
if ( V_107 < 0 )
goto V_124;
if ( V_100 [ V_101 ] == NULL )
F_61 ( V_2 ) ;
if ( V_100 [ V_118 ] )
F_55 ( V_2 -> V_125 , V_100 [ V_118 ] , V_109 ) ;
else
snprintf ( V_2 -> V_125 , V_109 , V_22 L_1 ) ;
V_107 = F_62 ( V_2 ) ;
if ( V_107 < 0 )
goto V_126;
F_34 ( V_2 ) ;
V_35 = F_9 ( V_2 ) ;
F_64 ( V_35 -> V_36 , V_36 ) ;
V_35 = F_9 ( V_36 ) ;
F_64 ( V_35 -> V_36 , V_2 ) ;
return 0 ;
V_126:
V_124:
F_65 ( V_36 ) ;
return V_107 ;
V_123:
F_41 ( V_36 ) ;
return V_107 ;
}
static void F_66 ( struct V_1 * V_2 , struct V_127 * V_128 )
{
struct V_34 * V_35 ;
struct V_1 * V_36 ;
V_35 = F_9 ( V_2 ) ;
V_36 = F_10 ( V_35 -> V_36 ) ;
F_67 ( V_35 -> V_36 , NULL ) ;
F_68 ( V_2 , V_128 ) ;
if ( V_36 ) {
V_35 = F_9 ( V_36 ) ;
F_67 ( V_35 -> V_36 , NULL ) ;
F_68 ( V_36 , V_128 ) ;
}
}
static struct V_105 * F_69 ( const struct V_1 * V_2 )
{
struct V_34 * V_35 = F_9 ( V_2 ) ;
struct V_1 * V_36 = F_10 ( V_35 -> V_36 ) ;
return V_36 ? F_70 ( V_36 ) : F_70 ( V_2 ) ;
}
static T_5 int F_71 ( void )
{
return F_72 ( & V_121 ) ;
}
static T_6 void F_73 ( void )
{
F_74 ( & V_121 ) ;
}
