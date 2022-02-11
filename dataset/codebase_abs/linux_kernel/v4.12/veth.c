static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
V_4 -> V_5 . V_6 = V_7 ;
V_4 -> V_5 . V_8 = V_9 ;
V_4 -> V_5 . V_10 = V_11 ;
V_4 -> V_5 . V_12 = V_13 ;
return 0 ;
}
static void F_2 ( struct V_1 * V_2 , struct V_14 * V_15 )
{
F_3 ( V_15 -> V_16 , V_17 , sizeof( V_15 -> V_16 ) ) ;
F_3 ( V_15 -> V_18 , V_19 , sizeof( V_15 -> V_18 ) ) ;
}
static void F_4 ( struct V_1 * V_2 , T_1 V_20 , T_2 * V_21 )
{
switch( V_20 ) {
case V_22 :
memcpy ( V_21 , & V_23 , sizeof( V_23 ) ) ;
break;
}
}
static int F_5 ( struct V_1 * V_2 , int V_24 )
{
switch ( V_24 ) {
case V_22 :
return F_6 ( V_23 ) ;
default:
return - V_25 ;
}
}
static void F_7 ( struct V_1 * V_2 ,
struct V_26 * V_27 , T_3 * V_28 )
{
struct V_29 * V_30 = F_8 ( V_2 ) ;
struct V_1 * V_31 = F_9 ( V_30 -> V_31 ) ;
V_28 [ 0 ] = V_31 ? V_31 -> V_32 : 0 ;
}
static T_4 F_10 ( struct V_33 * V_34 , struct V_1 * V_2 )
{
struct V_29 * V_30 = F_8 ( V_2 ) ;
struct V_1 * V_35 ;
int V_36 = V_34 -> V_37 ;
F_11 () ;
V_35 = F_12 ( V_30 -> V_31 ) ;
if ( F_13 ( ! V_35 ) ) {
F_14 ( V_34 ) ;
goto V_38;
}
if ( F_15 ( F_16 ( V_35 , V_34 ) == V_39 ) ) {
struct V_40 * V_27 = F_17 ( V_2 -> V_41 ) ;
F_18 ( & V_27 -> V_42 ) ;
V_27 -> V_43 += V_36 ;
V_27 -> V_44 ++ ;
F_19 ( & V_27 -> V_42 ) ;
} else {
V_38:
F_20 ( & V_30 -> V_45 ) ;
}
F_21 () ;
return V_46 ;
}
static T_3 F_22 ( struct V_40 * V_47 , struct V_1 * V_2 )
{
struct V_29 * V_30 = F_8 ( V_2 ) ;
int V_48 ;
V_47 -> V_44 = 0 ;
V_47 -> V_43 = 0 ;
F_23 (cpu) {
struct V_40 * V_27 = F_24 ( V_2 -> V_41 , V_48 ) ;
T_3 V_44 , V_43 ;
unsigned int V_49 ;
do {
V_49 = F_25 ( & V_27 -> V_42 ) ;
V_44 = V_27 -> V_44 ;
V_43 = V_27 -> V_43 ;
} while ( F_26 ( & V_27 -> V_42 , V_49 ) );
V_47 -> V_44 += V_44 ;
V_47 -> V_43 += V_43 ;
}
return F_27 ( & V_30 -> V_45 ) ;
}
static void F_28 ( struct V_1 * V_2 ,
struct V_50 * V_51 )
{
struct V_29 * V_30 = F_8 ( V_2 ) ;
struct V_1 * V_31 ;
struct V_40 V_52 ;
V_51 -> V_53 = F_22 ( & V_52 , V_2 ) ;
V_51 -> V_54 = V_52 . V_43 ;
V_51 -> V_55 = V_52 . V_44 ;
F_11 () ;
V_31 = F_12 ( V_30 -> V_31 ) ;
if ( V_31 ) {
V_51 -> V_56 = F_22 ( & V_52 , V_31 ) ;
V_51 -> V_57 = V_52 . V_43 ;
V_51 -> V_58 = V_52 . V_44 ;
}
F_21 () ;
}
static void F_29 ( struct V_1 * V_2 )
{
}
static int F_30 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_8 ( V_2 ) ;
struct V_1 * V_31 = F_9 ( V_30 -> V_31 ) ;
if ( ! V_31 )
return - V_59 ;
if ( V_31 -> V_60 & V_61 ) {
F_31 ( V_2 ) ;
F_31 ( V_31 ) ;
}
return 0 ;
}
static int F_32 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_8 ( V_2 ) ;
struct V_1 * V_31 = F_9 ( V_30 -> V_31 ) ;
F_33 ( V_2 ) ;
if ( V_31 )
F_33 ( V_31 ) ;
return 0 ;
}
static int F_34 ( int V_62 )
{
return V_62 >= V_63 && V_62 <= V_64 ;
}
static int F_35 ( struct V_1 * V_2 )
{
V_2 -> V_41 = F_36 ( struct V_40 ) ;
if ( ! V_2 -> V_41 )
return - V_65 ;
return 0 ;
}
static void F_37 ( struct V_1 * V_2 )
{
F_38 ( V_2 -> V_41 ) ;
}
static void F_39 ( struct V_1 * V_2 )
{
}
static int F_40 ( const struct V_1 * V_2 )
{
struct V_29 * V_30 = F_8 ( V_2 ) ;
struct V_1 * V_31 ;
int V_66 ;
F_11 () ;
V_31 = F_12 ( V_30 -> V_31 ) ;
V_66 = V_31 ? V_31 -> V_32 : 0 ;
F_21 () ;
return V_66 ;
}
static void F_41 ( struct V_1 * V_2 , int V_67 )
{
struct V_29 * V_68 , * V_30 = F_8 ( V_2 ) ;
struct V_1 * V_31 ;
if ( V_67 < 0 )
V_67 = 0 ;
F_11 () ;
V_31 = F_12 ( V_30 -> V_31 ) ;
if ( F_13 ( ! V_31 ) )
goto V_69;
V_68 = F_8 ( V_31 ) ;
V_30 -> V_70 = V_67 ;
V_67 = F_42 ( V_30 -> V_70 , V_68 -> V_70 ) ;
V_2 -> V_71 = V_67 ;
V_31 -> V_71 = V_67 ;
V_69:
F_21 () ;
}
static void F_43 ( struct V_1 * V_2 )
{
F_44 ( V_2 ) ;
V_2 -> V_72 &= ~ V_73 ;
V_2 -> V_72 |= V_74 ;
V_2 -> V_72 |= V_75 ;
V_2 -> V_72 |= V_76 ;
V_2 -> V_77 = & V_78 ;
V_2 -> V_79 = & V_80 ;
V_2 -> V_81 |= V_82 ;
V_2 -> V_81 |= V_83 ;
V_2 -> V_84 = V_2 -> V_81 &
~ ( V_85 |
V_86 |
V_87 |
V_88 ) ;
V_2 -> V_89 = true ;
V_2 -> V_90 = F_37 ;
V_2 -> V_91 = V_64 ;
V_2 -> V_92 = V_83 ;
V_2 -> V_93 = V_83 ;
V_2 -> V_94 = V_95 | V_96 ;
}
static int F_45 ( struct V_97 * V_98 [] , struct V_97 * V_28 [] )
{
if ( V_98 [ V_99 ] ) {
if ( F_46 ( V_98 [ V_99 ] ) != V_100 )
return - V_101 ;
if ( ! F_47 ( F_48 ( V_98 [ V_99 ] ) ) )
return - V_102 ;
}
if ( V_98 [ V_103 ] ) {
if ( ! F_34 ( F_49 ( V_98 [ V_103 ] ) ) )
return - V_101 ;
}
return 0 ;
}
static int F_50 ( struct V_104 * V_105 , struct V_1 * V_2 ,
struct V_97 * V_98 [] , struct V_97 * V_28 [] )
{
int V_106 ;
struct V_1 * V_31 ;
struct V_29 * V_30 ;
char V_107 [ V_108 ] ;
struct V_97 * V_109 [ V_110 + 1 ] , * * V_111 ;
unsigned char V_112 ;
struct V_113 * V_114 ;
struct V_104 * V_104 ;
if ( V_28 != NULL && V_28 [ V_115 ] != NULL ) {
struct V_97 * V_116 ;
V_116 = V_28 [ V_115 ] ;
V_114 = F_48 ( V_116 ) ;
V_106 = F_51 ( V_109 ,
F_48 ( V_116 ) + sizeof( struct V_113 ) ,
F_46 ( V_116 ) - sizeof( struct V_113 ) ,
NULL ) ;
if ( V_106 < 0 )
return V_106 ;
V_106 = F_45 ( V_109 , NULL ) ;
if ( V_106 < 0 )
return V_106 ;
V_111 = V_109 ;
} else {
V_114 = NULL ;
V_111 = V_98 ;
}
if ( V_114 && V_111 [ V_117 ] ) {
F_52 ( V_107 , V_111 [ V_117 ] , V_108 ) ;
V_112 = V_118 ;
} else {
snprintf ( V_107 , V_108 , V_17 L_1 ) ;
V_112 = V_119 ;
}
V_104 = F_53 ( V_105 , V_111 ) ;
if ( F_54 ( V_104 ) )
return F_55 ( V_104 ) ;
V_31 = F_56 ( V_104 , V_107 , V_112 ,
& V_120 , V_111 ) ;
if ( F_54 ( V_31 ) ) {
F_57 ( V_104 ) ;
return F_55 ( V_31 ) ;
}
if ( ! V_114 || ! V_111 [ V_99 ] )
F_58 ( V_31 ) ;
if ( V_114 && ( V_2 -> V_32 != 0 ) )
V_31 -> V_32 = V_114 -> V_121 ;
V_106 = F_59 ( V_31 ) ;
F_57 ( V_104 ) ;
V_104 = NULL ;
if ( V_106 < 0 )
goto V_122;
F_33 ( V_31 ) ;
V_106 = F_60 ( V_31 , V_114 ) ;
if ( V_106 < 0 )
goto V_123;
if ( V_98 [ V_99 ] == NULL )
F_58 ( V_2 ) ;
if ( V_98 [ V_117 ] )
F_52 ( V_2 -> V_124 , V_98 [ V_117 ] , V_108 ) ;
else
snprintf ( V_2 -> V_124 , V_108 , V_17 L_1 ) ;
V_106 = F_59 ( V_2 ) ;
if ( V_106 < 0 )
goto V_125;
F_33 ( V_2 ) ;
V_30 = F_8 ( V_2 ) ;
F_61 ( V_30 -> V_31 , V_31 ) ;
V_30 = F_8 ( V_31 ) ;
F_61 ( V_30 -> V_31 , V_2 ) ;
return 0 ;
V_125:
V_123:
F_62 ( V_31 ) ;
return V_106 ;
V_122:
F_63 ( V_31 ) ;
return V_106 ;
}
static void F_64 ( struct V_1 * V_2 , struct V_126 * V_127 )
{
struct V_29 * V_30 ;
struct V_1 * V_31 ;
V_30 = F_8 ( V_2 ) ;
V_31 = F_9 ( V_30 -> V_31 ) ;
F_65 ( V_30 -> V_31 , NULL ) ;
F_66 ( V_2 , V_127 ) ;
if ( V_31 ) {
V_30 = F_8 ( V_31 ) ;
F_65 ( V_30 -> V_31 , NULL ) ;
F_66 ( V_31 , V_127 ) ;
}
}
static struct V_104 * F_67 ( const struct V_1 * V_2 )
{
struct V_29 * V_30 = F_8 ( V_2 ) ;
struct V_1 * V_31 = F_9 ( V_30 -> V_31 ) ;
return V_31 ? F_68 ( V_31 ) : F_68 ( V_2 ) ;
}
static T_5 int F_69 ( void )
{
return F_70 ( & V_120 ) ;
}
static T_6 void F_71 ( void )
{
F_72 ( & V_120 ) ;
}
