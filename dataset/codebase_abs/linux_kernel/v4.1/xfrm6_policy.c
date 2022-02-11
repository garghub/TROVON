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
F_8 ( F_9 ( V_11 ) , V_11 , & V_5 -> V_13 , 0 , & V_4 -> V_13 ) ;
F_3 ( V_8 ) ;
return 0 ;
}
static int F_10 ( const struct V_14 * V_15 )
{
return 0 ;
}
static void F_11 ( struct V_2 * V_2 , struct V_16 * V_17 )
{
struct V_18 * V_19 = (struct V_18 * ) V_17 ;
F_12 ( V_19 , V_2 -> V_20 . V_21 ) ;
}
static int F_13 ( struct V_16 * V_22 , struct V_1 * V_8 ,
int V_23 )
{
if ( V_8 -> V_24 -> V_25 == V_26 ) {
struct V_18 * V_19 = (struct V_18 * ) V_8 ;
if ( V_19 -> V_27 )
V_22 -> V_28 = V_19 -> V_27 -> V_29 ;
}
V_22 -> V_30 . V_31 . V_32 = V_23 ;
return 0 ;
}
static int F_14 ( struct V_16 * V_17 , struct V_10 * V_11 ,
const struct V_14 * V_15 )
{
struct V_18 * V_19 = (struct V_18 * ) V_17 -> V_33 ;
V_17 -> V_30 . V_8 . V_11 = V_11 ;
F_15 ( V_11 ) ;
V_17 -> V_30 . V_31 . V_34 = F_16 ( V_11 ) ;
if ( ! V_17 -> V_30 . V_31 . V_34 ) {
F_17 ( V_11 ) ;
return - V_35 ;
}
F_18 ( & V_17 -> V_30 . V_31 , V_19 ) ;
V_17 -> V_30 . V_31 . V_36 = V_19 -> V_36 & ( V_37 |
V_38 ) ;
V_17 -> V_30 . V_31 . V_39 = V_19 -> V_39 ;
V_17 -> V_30 . V_31 . V_27 = V_19 -> V_27 ;
if ( V_19 -> V_27 )
V_17 -> V_40 = V_19 -> V_27 -> V_29 ;
V_17 -> V_30 . V_31 . V_41 = V_19 -> V_41 ;
V_17 -> V_30 . V_31 . V_42 = V_19 -> V_42 ;
V_17 -> V_30 . V_31 . V_43 = V_19 -> V_43 ;
return 0 ;
}
static inline void
F_19 ( struct V_44 * V_45 , struct V_14 * V_15 , int V_46 )
{
struct V_6 * V_7 = & V_15 -> V_30 . V_47 ;
int V_48 = 0 ;
const struct V_49 * V_50 = F_20 ( V_45 ) ;
T_2 V_51 = sizeof( * V_50 ) ;
struct V_52 * V_53 ;
const unsigned char * V_54 = F_21 ( V_45 ) ;
T_2 V_55 = F_22 ( V_45 ) -> V_55 ;
int V_56 = 0 ;
T_3 V_57 ;
if ( ! V_55 )
V_55 = F_23 ( struct V_49 , V_57 ) ;
V_57 = V_54 [ V_55 ] ;
if ( F_24 ( V_45 ) )
V_56 = F_24 ( V_45 ) -> V_11 -> V_58 ;
memset ( V_7 , 0 , sizeof( struct V_6 ) ) ;
V_7 -> V_59 = V_45 -> V_60 ;
V_7 -> V_61 = V_46 ? V_45 -> V_62 : V_56 ;
V_7 -> V_5 = V_46 ? V_50 -> V_4 : V_50 -> V_5 ;
V_7 -> V_4 = V_46 ? V_50 -> V_5 : V_50 -> V_4 ;
while ( V_54 + V_51 + 1 < V_45 -> V_63 ||
F_25 ( V_45 , V_54 + V_51 + 1 - V_45 -> V_63 ) ) {
V_54 = F_21 ( V_45 ) ;
V_53 = (struct V_52 * ) ( V_54 + V_51 ) ;
switch ( V_57 ) {
case V_64 :
V_48 = 1 ;
case V_65 :
case V_66 :
case V_67 :
V_51 += F_26 ( V_53 ) ;
V_57 = V_53 -> V_57 ;
V_53 = (struct V_52 * ) ( V_54 + V_51 ) ;
break;
case V_68 :
case V_69 :
case V_70 :
case V_71 :
case V_72 :
if ( ! V_48 && ( V_54 + V_51 + 4 < V_45 -> V_63 ||
F_25 ( V_45 , V_54 + V_51 + 4 - V_45 -> V_63 ) ) ) {
T_4 * V_73 ;
V_54 = F_21 ( V_45 ) ;
V_73 = ( T_4 * ) ( V_54 + V_51 ) ;
V_7 -> V_74 = V_73 [ ! ! V_46 ] ;
V_7 -> V_75 = V_73 [ ! V_46 ] ;
}
V_7 -> V_76 = V_57 ;
return;
case V_77 :
if ( ! V_48 && F_25 ( V_45 , V_54 + V_51 + 2 - V_45 -> V_63 ) ) {
T_3 * V_78 ;
V_54 = F_21 ( V_45 ) ;
V_78 = ( T_3 * ) ( V_54 + V_51 ) ;
V_7 -> V_79 = V_78 [ 0 ] ;
V_7 -> V_80 = V_78 [ 1 ] ;
}
V_7 -> V_76 = V_57 ;
return;
#if F_27 ( V_81 )
case V_82 :
V_51 += F_26 ( V_53 ) ;
if ( ! V_48 && F_25 ( V_45 , V_54 + V_51 + 3 - V_45 -> V_63 ) ) {
struct V_83 * V_84 ;
V_54 = F_21 ( V_45 ) ;
V_84 = (struct V_83 * ) ( V_54 + V_51 ) ;
V_7 -> V_85 = V_84 -> V_86 ;
}
V_7 -> V_76 = V_57 ;
return;
#endif
case V_87 :
case V_88 :
case V_89 :
default:
V_7 -> V_90 = 0 ;
V_7 -> V_76 = V_57 ;
return;
}
}
}
static inline int F_28 ( struct V_91 * V_24 )
{
struct V_2 * V_2 = F_29 ( V_24 , struct V_2 , V_92 . V_93 ) ;
V_94 . V_95 ( V_2 ) ;
return F_30 ( V_24 ) > V_24 -> V_96 * 2 ;
}
static void F_31 ( struct V_1 * V_8 , struct V_97 * V_98 ,
struct V_44 * V_45 , T_5 V_99 )
{
struct V_16 * V_17 = (struct V_16 * ) V_8 ;
struct V_1 * V_22 = V_17 -> V_33 ;
V_22 -> V_24 -> V_100 ( V_22 , V_98 , V_45 , V_99 ) ;
}
static void F_32 ( struct V_1 * V_8 , struct V_97 * V_98 ,
struct V_44 * V_45 )
{
struct V_16 * V_17 = (struct V_16 * ) V_8 ;
struct V_1 * V_22 = V_17 -> V_33 ;
V_22 -> V_24 -> V_101 ( V_22 , V_98 , V_45 ) ;
}
static void F_33 ( struct V_1 * V_8 )
{
struct V_16 * V_17 = (struct V_16 * ) V_8 ;
if ( F_34 ( V_17 -> V_30 . V_31 . V_34 ) )
F_35 ( V_17 -> V_30 . V_31 . V_34 ) ;
F_36 ( V_8 ) ;
if ( F_37 ( & V_17 -> V_30 . V_31 ) ) {
struct V_102 * V_103 = F_38 ( & V_17 -> V_30 . V_31 ) ;
F_39 ( V_103 ) ;
}
F_40 ( V_17 ) ;
}
static void F_41 ( struct V_1 * V_8 , struct V_10 * V_11 ,
int V_104 )
{
struct V_16 * V_17 ;
if ( ! V_104 )
return;
V_17 = (struct V_16 * ) V_8 ;
if ( V_17 -> V_30 . V_31 . V_34 -> V_11 == V_11 ) {
struct V_105 * V_106 =
F_16 ( F_9 ( V_11 ) -> V_107 ) ;
F_42 ( ! V_106 ) ;
do {
F_35 ( V_17 -> V_30 . V_31 . V_34 ) ;
V_17 -> V_30 . V_31 . V_34 = V_106 ;
F_43 ( V_106 ) ;
V_17 = (struct V_16 * ) V_17 -> V_30 . V_8 . V_108 ;
} while ( V_17 -> V_30 . V_8 . V_92 );
F_44 ( V_106 ) ;
}
F_45 ( V_8 , V_11 ) ;
}
static int T_6 F_46 ( void )
{
return F_47 ( & V_94 ) ;
}
static void F_48 ( void )
{
F_49 ( & V_94 ) ;
}
static int T_7 F_50 ( struct V_2 * V_2 )
{
struct V_109 * V_110 ;
struct V_111 * V_50 ;
V_110 = V_112 ;
if ( ! F_51 ( V_2 , & V_113 ) ) {
V_110 = F_52 ( V_110 , sizeof( V_112 ) , V_114 ) ;
if ( ! V_110 )
goto V_115;
V_110 [ 0 ] . V_63 = & V_2 -> V_92 . V_93 . V_96 ;
}
V_50 = F_53 ( V_2 , L_1 , V_110 ) ;
if ( ! V_50 )
goto V_116;
V_2 -> V_20 . V_117 . V_118 = V_50 ;
return 0 ;
V_116:
if ( ! F_51 ( V_2 , & V_113 ) )
F_54 ( V_110 ) ;
V_115:
return - V_119 ;
}
static void T_8 F_55 ( struct V_2 * V_2 )
{
struct V_109 * V_110 ;
if ( ! V_2 -> V_20 . V_117 . V_118 )
return;
V_110 = V_2 -> V_20 . V_117 . V_118 -> V_120 ;
F_56 ( V_2 -> V_20 . V_117 . V_118 ) ;
if ( ! F_51 ( V_2 , & V_113 ) )
F_54 ( V_110 ) ;
}
int T_6 F_57 ( void )
{
int V_121 ;
F_58 ( & V_93 ) ;
V_121 = F_46 () ;
if ( V_121 ) {
F_59 ( & V_93 ) ;
goto V_122;
}
V_121 = F_60 () ;
if ( V_121 )
goto V_123;
V_121 = F_61 () ;
if ( V_121 )
goto V_124;
#ifdef F_62
F_63 ( & V_125 ) ;
#endif
V_122:
return V_121 ;
V_124:
F_64 () ;
V_123:
F_48 () ;
goto V_122;
}
void F_65 ( void )
{
#ifdef F_62
F_66 ( & V_125 ) ;
#endif
F_67 () ;
F_48 () ;
F_64 () ;
F_59 ( & V_93 ) ;
}
