static struct V_1 * F_1 ( struct V_2 * V_2 , int V_3 ,
const T_1 * V_4 ,
const T_1 * V_5 )
{
struct V_6 V_7 ;
struct V_1 * V_8 ;
int V_9 ;
memset ( & V_7 , 0 , sizeof( V_7 ) ) ;
memcpy ( & V_7 . V_5 , V_5 , sizeof( V_7 . V_5 ) ) ;
if ( V_4 )
memcpy ( & V_7 . V_4 , V_4 , sizeof( V_7 . V_4 ) ) ;
V_8 = F_2 ( V_2 , NULL , & V_7 ) ;
V_9 = V_8 -> error ;
if ( V_8 -> error ) {
F_3 ( V_8 ) ;
V_8 = F_4 ( V_9 ) ;
}
return V_8 ;
}
static int F_5 ( struct V_2 * V_2 ,
T_1 * V_4 , T_1 * V_5 )
{
struct V_1 * V_8 ;
struct V_10 * V_11 ;
V_8 = F_1 ( V_2 , 0 , NULL , V_5 ) ;
if ( F_6 ( V_8 ) )
return - V_12 ;
V_11 = F_7 ( V_8 ) -> V_11 ;
F_8 ( F_9 ( V_11 ) , V_11 ,
(struct V_13 * ) & V_5 -> V_14 , 0 ,
(struct V_13 * ) & V_4 -> V_14 ) ;
F_3 ( V_8 ) ;
return 0 ;
}
static int F_10 ( const struct V_15 * V_16 )
{
return 0 ;
}
static void F_11 ( struct V_2 * V_2 , struct V_17 * V_18 )
{
struct V_19 * V_20 = (struct V_19 * ) V_18 ;
F_12 ( V_20 , V_2 -> V_21 . V_22 ) ;
}
static int F_13 ( struct V_17 * V_23 , struct V_1 * V_8 ,
int V_24 )
{
if ( V_8 -> V_25 -> V_26 == V_27 ) {
struct V_19 * V_20 = (struct V_19 * ) V_8 ;
if ( V_20 -> V_28 )
V_23 -> V_29 = V_20 -> V_28 -> V_30 ;
}
V_23 -> V_31 . V_32 . V_33 = V_24 ;
return 0 ;
}
static int F_14 ( struct V_17 * V_18 , struct V_10 * V_11 ,
const struct V_15 * V_16 )
{
struct V_19 * V_20 = (struct V_19 * ) V_18 -> V_34 ;
V_18 -> V_31 . V_8 . V_11 = V_11 ;
F_15 ( V_11 ) ;
V_18 -> V_31 . V_32 . V_35 = F_16 ( V_11 ) ;
if ( ! V_18 -> V_31 . V_32 . V_35 ) {
F_17 ( V_11 ) ;
return - V_36 ;
}
F_18 ( & V_18 -> V_31 . V_32 , V_20 ) ;
V_18 -> V_31 . V_32 . V_37 = V_20 -> V_37 & ( V_38 |
V_39 ) ;
V_18 -> V_31 . V_32 . V_40 = V_20 -> V_40 ;
V_18 -> V_31 . V_32 . V_28 = V_20 -> V_28 ;
if ( V_20 -> V_28 )
V_18 -> V_41 = V_20 -> V_28 -> V_30 ;
V_18 -> V_31 . V_32 . V_42 = V_20 -> V_42 ;
V_18 -> V_31 . V_32 . V_43 = V_20 -> V_43 ;
V_18 -> V_31 . V_32 . V_44 = V_20 -> V_44 ;
return 0 ;
}
static inline void
F_19 ( struct V_45 * V_46 , struct V_15 * V_16 , int V_47 )
{
struct V_6 * V_7 = & V_16 -> V_31 . V_48 ;
int V_49 = 0 ;
const struct V_50 * V_51 = F_20 ( V_46 ) ;
T_2 V_52 = sizeof( * V_51 ) ;
struct V_53 * V_54 ;
const unsigned char * V_55 = F_21 ( V_46 ) ;
T_2 V_56 = F_22 ( V_46 ) -> V_56 ;
int V_57 = 0 ;
T_3 V_58 ;
if ( ! V_56 )
V_56 = F_23 ( struct V_50 , V_58 ) ;
V_58 = V_55 [ V_56 ] ;
if ( F_24 ( V_46 ) )
V_57 = F_24 ( V_46 ) -> V_11 -> V_59 ;
memset ( V_7 , 0 , sizeof( struct V_6 ) ) ;
V_7 -> V_60 = V_46 -> V_61 ;
V_7 -> V_62 = V_47 ? V_46 -> V_63 : V_57 ;
V_7 -> V_5 = V_47 ? V_51 -> V_4 : V_51 -> V_5 ;
V_7 -> V_4 = V_47 ? V_51 -> V_5 : V_51 -> V_4 ;
while ( V_55 + V_52 + 1 < V_46 -> V_64 ||
F_25 ( V_46 , V_55 + V_52 + 1 - V_46 -> V_64 ) ) {
V_55 = F_21 ( V_46 ) ;
V_54 = (struct V_53 * ) ( V_55 + V_52 ) ;
switch ( V_58 ) {
case V_65 :
V_49 = 1 ;
case V_66 :
case V_67 :
case V_68 :
V_52 += F_26 ( V_54 ) ;
V_58 = V_54 -> V_58 ;
V_54 = (struct V_53 * ) ( V_55 + V_52 ) ;
break;
case V_69 :
case V_70 :
case V_71 :
case V_72 :
case V_73 :
if ( ! V_49 && ( V_55 + V_52 + 4 < V_46 -> V_64 ||
F_25 ( V_46 , V_55 + V_52 + 4 - V_46 -> V_64 ) ) ) {
T_4 * V_74 ;
V_55 = F_21 ( V_46 ) ;
V_74 = ( T_4 * ) ( V_55 + V_52 ) ;
V_7 -> V_75 = V_74 [ ! ! V_47 ] ;
V_7 -> V_76 = V_74 [ ! V_47 ] ;
}
V_7 -> V_77 = V_58 ;
return;
case V_78 :
if ( ! V_49 && F_25 ( V_46 , V_55 + V_52 + 2 - V_46 -> V_64 ) ) {
T_3 * V_79 ;
V_55 = F_21 ( V_46 ) ;
V_79 = ( T_3 * ) ( V_55 + V_52 ) ;
V_7 -> V_80 = V_79 [ 0 ] ;
V_7 -> V_81 = V_79 [ 1 ] ;
}
V_7 -> V_77 = V_58 ;
return;
#if F_27 ( V_82 )
case V_83 :
if ( ! V_49 && F_25 ( V_46 , V_55 + V_52 + 3 - V_46 -> V_64 ) ) {
struct V_84 * V_85 ;
V_55 = F_21 ( V_46 ) ;
V_85 = (struct V_84 * ) ( V_55 + V_52 ) ;
V_7 -> V_86 = V_85 -> V_87 ;
}
V_7 -> V_77 = V_58 ;
return;
#endif
case V_88 :
case V_89 :
case V_90 :
default:
V_7 -> V_91 = 0 ;
V_7 -> V_77 = V_58 ;
return;
}
}
}
static inline int F_28 ( struct V_92 * V_25 )
{
struct V_2 * V_2 = F_29 ( V_25 , struct V_2 , V_93 . V_94 ) ;
V_95 . V_96 ( V_2 ) ;
return F_30 ( V_25 ) > V_25 -> V_97 * 2 ;
}
static void F_31 ( struct V_1 * V_8 , struct V_98 * V_99 ,
struct V_45 * V_46 , T_5 V_100 )
{
struct V_17 * V_18 = (struct V_17 * ) V_8 ;
struct V_1 * V_23 = V_18 -> V_34 ;
V_23 -> V_25 -> V_101 ( V_23 , V_99 , V_46 , V_100 ) ;
}
static void F_32 ( struct V_1 * V_8 , struct V_98 * V_99 ,
struct V_45 * V_46 )
{
struct V_17 * V_18 = (struct V_17 * ) V_8 ;
struct V_1 * V_23 = V_18 -> V_34 ;
V_23 -> V_25 -> V_102 ( V_23 , V_99 , V_46 ) ;
}
static void F_33 ( struct V_1 * V_8 )
{
struct V_17 * V_18 = (struct V_17 * ) V_8 ;
if ( F_34 ( V_18 -> V_31 . V_32 . V_35 ) )
F_35 ( V_18 -> V_31 . V_32 . V_35 ) ;
F_36 ( V_8 ) ;
if ( F_37 ( & V_18 -> V_31 . V_32 ) ) {
struct V_103 * V_104 = F_38 ( & V_18 -> V_31 . V_32 ) ;
F_39 ( V_104 ) ;
}
F_40 ( V_18 ) ;
}
static void F_41 ( struct V_1 * V_8 , struct V_10 * V_11 ,
int V_105 )
{
struct V_17 * V_18 ;
if ( ! V_105 )
return;
V_18 = (struct V_17 * ) V_8 ;
if ( V_18 -> V_31 . V_32 . V_35 -> V_11 == V_11 ) {
struct V_106 * V_107 =
F_16 ( F_9 ( V_11 ) -> V_108 ) ;
F_42 ( ! V_107 ) ;
do {
F_35 ( V_18 -> V_31 . V_32 . V_35 ) ;
V_18 -> V_31 . V_32 . V_35 = V_107 ;
F_43 ( V_107 ) ;
V_18 = (struct V_17 * ) V_18 -> V_31 . V_8 . V_109 ;
} while ( V_18 -> V_31 . V_8 . V_93 );
F_44 ( V_107 ) ;
}
F_45 ( V_8 , V_11 ) ;
}
static int T_6 F_46 ( void )
{
return F_47 ( & V_95 ) ;
}
static void F_48 ( void )
{
F_49 ( & V_95 ) ;
}
static int T_7 F_50 ( struct V_2 * V_2 )
{
struct V_110 * V_111 ;
struct V_112 * V_51 ;
V_111 = V_113 ;
if ( ! F_51 ( V_2 , & V_114 ) ) {
V_111 = F_52 ( V_111 , sizeof( V_113 ) , V_115 ) ;
if ( ! V_111 )
goto V_116;
V_111 [ 0 ] . V_64 = & V_2 -> V_93 . V_94 . V_97 ;
}
V_51 = F_53 ( V_2 , L_1 , V_111 ) ;
if ( ! V_51 )
goto V_117;
V_2 -> V_21 . V_118 . V_119 = V_51 ;
return 0 ;
V_117:
if ( ! F_51 ( V_2 , & V_114 ) )
F_54 ( V_111 ) ;
V_116:
return - V_120 ;
}
static void T_8 F_55 ( struct V_2 * V_2 )
{
struct V_110 * V_111 ;
if ( V_2 -> V_21 . V_118 . V_119 == NULL )
return;
V_111 = V_2 -> V_21 . V_118 . V_119 -> V_121 ;
F_56 ( V_2 -> V_21 . V_118 . V_119 ) ;
if ( ! F_51 ( V_2 , & V_114 ) )
F_54 ( V_111 ) ;
}
int T_6 F_57 ( void )
{
int V_122 ;
F_58 ( & V_94 ) ;
V_122 = F_46 () ;
if ( V_122 ) {
F_59 ( & V_94 ) ;
goto V_123;
}
V_122 = F_60 () ;
if ( V_122 )
goto V_124;
V_122 = F_61 () ;
if ( V_122 )
goto V_125;
#ifdef F_62
F_63 ( & V_126 ) ;
#endif
V_123:
return V_122 ;
V_125:
F_64 () ;
V_124:
F_48 () ;
goto V_123;
}
void F_65 ( void )
{
#ifdef F_62
F_66 ( & V_126 ) ;
#endif
F_67 () ;
F_48 () ;
F_64 () ;
F_59 ( & V_94 ) ;
}
