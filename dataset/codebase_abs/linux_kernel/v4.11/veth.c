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
static void F_29 ( struct V_1 * V_2 ,
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
static int F_36 ( struct V_1 * V_2 )
{
V_2 -> V_46 = F_37 ( struct V_45 ) ;
if ( ! V_2 -> V_46 )
return - V_70 ;
return 0 ;
}
static void F_38 ( struct V_1 * V_2 )
{
F_39 ( V_2 -> V_46 ) ;
F_40 ( V_2 ) ;
}
static void F_41 ( struct V_1 * V_2 )
{
}
static int F_42 ( const struct V_1 * V_2 )
{
struct V_34 * V_35 = F_9 ( V_2 ) ;
struct V_1 * V_36 ;
int V_71 ;
F_12 () ;
V_36 = F_13 ( V_35 -> V_36 ) ;
V_71 = V_36 ? V_36 -> V_37 : 0 ;
F_22 () ;
return V_71 ;
}
static void F_43 ( struct V_1 * V_2 , int V_72 )
{
struct V_34 * V_73 , * V_35 = F_9 ( V_2 ) ;
struct V_1 * V_36 ;
if ( V_72 < 0 )
V_72 = 0 ;
F_12 () ;
V_36 = F_13 ( V_35 -> V_36 ) ;
if ( F_14 ( ! V_36 ) )
goto V_74;
V_73 = F_9 ( V_36 ) ;
V_35 -> V_75 = V_72 ;
V_72 = F_44 ( V_35 -> V_75 , V_73 -> V_75 ) ;
V_2 -> V_76 = V_72 ;
V_36 -> V_76 = V_72 ;
V_74:
F_22 () ;
}
static void F_45 ( struct V_1 * V_2 )
{
F_46 ( V_2 ) ;
V_2 -> V_77 &= ~ V_78 ;
V_2 -> V_77 |= V_79 ;
V_2 -> V_77 |= V_80 ;
V_2 -> V_77 |= V_81 ;
V_2 -> V_82 = & V_83 ;
V_2 -> V_84 = & V_85 ;
V_2 -> V_86 |= V_87 ;
V_2 -> V_86 |= V_88 ;
V_2 -> V_89 = V_2 -> V_86 &
~ ( V_90 |
V_91 |
V_92 |
V_93 ) ;
V_2 -> V_94 = F_38 ;
V_2 -> V_95 = V_69 ;
V_2 -> V_96 = V_88 ;
V_2 -> V_97 = V_88 ;
V_2 -> V_98 = V_99 | V_100 ;
}
static int F_47 ( struct V_101 * V_102 [] , struct V_101 * V_33 [] )
{
if ( V_102 [ V_103 ] ) {
if ( F_48 ( V_102 [ V_103 ] ) != V_104 )
return - V_105 ;
if ( ! F_49 ( F_50 ( V_102 [ V_103 ] ) ) )
return - V_106 ;
}
if ( V_102 [ V_107 ] ) {
if ( ! F_35 ( F_51 ( V_102 [ V_107 ] ) ) )
return - V_105 ;
}
return 0 ;
}
static int F_52 ( struct V_108 * V_109 , struct V_1 * V_2 ,
struct V_101 * V_102 [] , struct V_101 * V_33 [] )
{
int V_110 ;
struct V_1 * V_36 ;
struct V_34 * V_35 ;
char V_111 [ V_112 ] ;
struct V_101 * V_113 [ V_114 + 1 ] , * * V_115 ;
unsigned char V_116 ;
struct V_117 * V_118 ;
struct V_108 * V_108 ;
if ( V_33 != NULL && V_33 [ V_119 ] != NULL ) {
struct V_101 * V_120 ;
V_120 = V_33 [ V_119 ] ;
V_118 = F_50 ( V_120 ) ;
V_110 = F_53 ( V_113 ,
F_50 ( V_120 ) + sizeof( struct V_117 ) ,
F_48 ( V_120 ) - sizeof( struct V_117 ) ) ;
if ( V_110 < 0 )
return V_110 ;
V_110 = F_47 ( V_113 , NULL ) ;
if ( V_110 < 0 )
return V_110 ;
V_115 = V_113 ;
} else {
V_118 = NULL ;
V_115 = V_102 ;
}
if ( V_115 [ V_121 ] ) {
F_54 ( V_111 , V_115 [ V_121 ] , V_112 ) ;
V_116 = V_122 ;
} else {
snprintf ( V_111 , V_112 , V_22 L_1 ) ;
V_116 = V_123 ;
}
V_108 = F_55 ( V_109 , V_115 ) ;
if ( F_56 ( V_108 ) )
return F_57 ( V_108 ) ;
V_36 = F_58 ( V_108 , V_111 , V_116 ,
& V_124 , V_115 ) ;
if ( F_56 ( V_36 ) ) {
F_59 ( V_108 ) ;
return F_57 ( V_36 ) ;
}
if ( V_115 [ V_103 ] == NULL )
F_60 ( V_36 ) ;
if ( V_118 && ( V_2 -> V_37 != 0 ) )
V_36 -> V_37 = V_118 -> V_125 ;
V_110 = F_61 ( V_36 ) ;
F_59 ( V_108 ) ;
V_108 = NULL ;
if ( V_110 < 0 )
goto V_126;
F_34 ( V_36 ) ;
V_110 = F_62 ( V_36 , V_118 ) ;
if ( V_110 < 0 )
goto V_127;
if ( V_102 [ V_103 ] == NULL )
F_60 ( V_2 ) ;
if ( V_102 [ V_121 ] )
F_54 ( V_2 -> V_128 , V_102 [ V_121 ] , V_112 ) ;
else
snprintf ( V_2 -> V_128 , V_112 , V_22 L_1 ) ;
V_110 = F_61 ( V_2 ) ;
if ( V_110 < 0 )
goto V_129;
F_34 ( V_2 ) ;
V_35 = F_9 ( V_2 ) ;
F_63 ( V_35 -> V_36 , V_36 ) ;
V_35 = F_9 ( V_36 ) ;
F_63 ( V_35 -> V_36 , V_2 ) ;
return 0 ;
V_129:
V_127:
F_64 ( V_36 ) ;
return V_110 ;
V_126:
F_40 ( V_36 ) ;
return V_110 ;
}
static void F_65 ( struct V_1 * V_2 , struct V_130 * V_131 )
{
struct V_34 * V_35 ;
struct V_1 * V_36 ;
V_35 = F_9 ( V_2 ) ;
V_36 = F_10 ( V_35 -> V_36 ) ;
F_66 ( V_35 -> V_36 , NULL ) ;
F_67 ( V_2 , V_131 ) ;
if ( V_36 ) {
V_35 = F_9 ( V_36 ) ;
F_66 ( V_35 -> V_36 , NULL ) ;
F_67 ( V_36 , V_131 ) ;
}
}
static struct V_108 * F_68 ( const struct V_1 * V_2 )
{
struct V_34 * V_35 = F_9 ( V_2 ) ;
struct V_1 * V_36 = F_10 ( V_35 -> V_36 ) ;
return V_36 ? F_69 ( V_36 ) : F_69 ( V_2 ) ;
}
static T_5 int F_70 ( void )
{
return F_71 ( & V_124 ) ;
}
static T_6 void F_72 ( void )
{
F_73 ( & V_124 ) ;
}
