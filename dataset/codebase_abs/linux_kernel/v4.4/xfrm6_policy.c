static struct V_1 * F_1 ( struct V_2 * V_2 , int V_3 , int V_4 ,
const T_1 * V_5 ,
const T_1 * V_6 )
{
struct V_7 V_8 ;
struct V_1 * V_9 ;
int V_10 ;
memset ( & V_8 , 0 , sizeof( V_8 ) ) ;
V_8 . V_11 = V_4 ;
V_8 . V_12 = V_13 ;
memcpy ( & V_8 . V_6 , V_6 , sizeof( V_8 . V_6 ) ) ;
if ( V_5 )
memcpy ( & V_8 . V_5 , V_5 , sizeof( V_8 . V_5 ) ) ;
V_9 = F_2 ( V_2 , NULL , & V_8 ) ;
V_10 = V_9 -> error ;
if ( V_9 -> error ) {
F_3 ( V_9 ) ;
V_9 = F_4 ( V_10 ) ;
}
return V_9 ;
}
static int F_5 ( struct V_2 * V_2 , int V_4 ,
T_1 * V_5 , T_1 * V_6 )
{
struct V_1 * V_9 ;
struct V_14 * V_15 ;
V_9 = F_1 ( V_2 , 0 , V_4 , NULL , V_6 ) ;
if ( F_6 ( V_9 ) )
return - V_16 ;
V_15 = F_7 ( V_9 ) -> V_15 ;
F_8 ( F_9 ( V_15 ) , V_15 , & V_6 -> V_17 , 0 , & V_5 -> V_17 ) ;
F_3 ( V_9 ) ;
return 0 ;
}
static int F_10 ( const struct V_18 * V_19 )
{
return 0 ;
}
static int F_11 ( struct V_20 * V_21 , struct V_1 * V_9 ,
int V_22 )
{
if ( V_9 -> V_23 -> V_24 == V_25 ) {
struct V_26 * V_27 = (struct V_26 * ) V_9 ;
V_21 -> V_28 = F_12 ( V_27 ) ;
}
V_21 -> V_29 . V_30 . V_31 = V_22 ;
return 0 ;
}
static int F_13 ( struct V_20 * V_32 , struct V_14 * V_15 ,
const struct V_18 * V_19 )
{
struct V_26 * V_27 = (struct V_26 * ) V_32 -> V_33 ;
V_32 -> V_29 . V_9 . V_15 = V_15 ;
F_14 ( V_15 ) ;
V_32 -> V_29 . V_30 . V_34 = F_15 ( V_15 ) ;
if ( ! V_32 -> V_29 . V_30 . V_34 ) {
F_16 ( V_15 ) ;
return - V_35 ;
}
V_32 -> V_29 . V_30 . V_36 = V_27 -> V_36 & ( V_37 |
V_38 ) ;
V_32 -> V_29 . V_30 . V_39 = V_27 -> V_39 ;
V_32 -> V_29 . V_30 . V_40 = V_27 -> V_40 ;
V_32 -> V_41 = F_12 ( V_27 ) ;
V_32 -> V_29 . V_30 . V_42 = V_27 -> V_42 ;
V_32 -> V_29 . V_30 . V_43 = V_27 -> V_43 ;
V_32 -> V_29 . V_30 . V_44 = V_27 -> V_44 ;
return 0 ;
}
static inline void
F_17 ( struct V_45 * V_46 , struct V_18 * V_19 , int V_47 )
{
struct V_7 * V_8 = & V_19 -> V_29 . V_48 ;
int V_49 = 0 ;
const struct V_50 * V_51 = F_18 ( V_46 ) ;
T_2 V_52 = sizeof( * V_51 ) ;
struct V_53 * V_54 ;
const unsigned char * V_55 = F_19 ( V_46 ) ;
T_2 V_56 = F_20 ( V_46 ) -> V_56 ;
int V_4 = 0 ;
T_3 V_57 ;
if ( ! V_56 )
V_56 = F_21 ( struct V_50 , V_57 ) ;
V_57 = V_55 [ V_56 ] ;
if ( F_22 ( V_46 ) )
V_4 = F_23 ( F_22 ( V_46 ) -> V_15 ) ;
memset ( V_8 , 0 , sizeof( struct V_7 ) ) ;
V_8 -> V_58 = V_46 -> V_59 ;
V_8 -> V_11 = V_47 ? V_46 -> V_60 : V_4 ;
V_8 -> V_6 = V_47 ? V_51 -> V_5 : V_51 -> V_6 ;
V_8 -> V_5 = V_47 ? V_51 -> V_6 : V_51 -> V_5 ;
while ( V_55 + V_52 + 1 < V_46 -> V_61 ||
F_24 ( V_46 , V_55 + V_52 + 1 - V_46 -> V_61 ) ) {
V_55 = F_19 ( V_46 ) ;
V_54 = (struct V_53 * ) ( V_55 + V_52 ) ;
switch ( V_57 ) {
case V_62 :
V_49 = 1 ;
case V_63 :
case V_64 :
case V_65 :
V_52 += F_25 ( V_54 ) ;
V_57 = V_54 -> V_57 ;
V_54 = (struct V_53 * ) ( V_55 + V_52 ) ;
break;
case V_66 :
case V_67 :
case V_68 :
case V_69 :
case V_70 :
if ( ! V_49 && ( V_55 + V_52 + 4 < V_46 -> V_61 ||
F_24 ( V_46 , V_55 + V_52 + 4 - V_46 -> V_61 ) ) ) {
T_4 * V_71 ;
V_55 = F_19 ( V_46 ) ;
V_71 = ( T_4 * ) ( V_55 + V_52 ) ;
V_8 -> V_72 = V_71 [ ! ! V_47 ] ;
V_8 -> V_73 = V_71 [ ! V_47 ] ;
}
V_8 -> V_74 = V_57 ;
return;
case V_75 :
if ( ! V_49 && ( V_55 + V_52 + 2 < V_46 -> V_61 ||
F_24 ( V_46 , V_55 + V_52 + 2 - V_46 -> V_61 ) ) ) {
T_3 * V_76 ;
V_55 = F_19 ( V_46 ) ;
V_76 = ( T_3 * ) ( V_55 + V_52 ) ;
V_8 -> V_77 = V_76 [ 0 ] ;
V_8 -> V_78 = V_76 [ 1 ] ;
}
V_8 -> V_74 = V_57 ;
return;
#if F_26 ( V_79 )
case V_80 :
V_52 += F_25 ( V_54 ) ;
if ( ! V_49 && ( V_55 + V_52 + 3 < V_46 -> V_61 ||
F_24 ( V_46 , V_55 + V_52 + 3 - V_46 -> V_61 ) ) ) {
struct V_81 * V_82 ;
V_55 = F_19 ( V_46 ) ;
V_82 = (struct V_81 * ) ( V_55 + V_52 ) ;
V_8 -> V_83 = V_82 -> V_84 ;
}
V_8 -> V_74 = V_57 ;
return;
#endif
case V_85 :
case V_86 :
case V_87 :
default:
V_8 -> V_88 = 0 ;
V_8 -> V_74 = V_57 ;
return;
}
}
}
static inline int F_27 ( struct V_89 * V_23 )
{
struct V_2 * V_2 = F_28 ( V_23 , struct V_2 , V_90 . V_91 ) ;
V_92 . V_93 ( V_2 ) ;
return F_29 ( V_23 ) > V_23 -> V_94 * 2 ;
}
static void F_30 ( struct V_1 * V_9 , struct V_95 * V_96 ,
struct V_45 * V_46 , T_5 V_97 )
{
struct V_20 * V_32 = (struct V_20 * ) V_9 ;
struct V_1 * V_21 = V_32 -> V_33 ;
V_21 -> V_23 -> V_98 ( V_21 , V_96 , V_46 , V_97 ) ;
}
static void F_31 ( struct V_1 * V_9 , struct V_95 * V_96 ,
struct V_45 * V_46 )
{
struct V_20 * V_32 = (struct V_20 * ) V_9 ;
struct V_1 * V_21 = V_32 -> V_33 ;
V_21 -> V_23 -> V_99 ( V_21 , V_96 , V_46 ) ;
}
static void F_32 ( struct V_1 * V_9 )
{
struct V_20 * V_32 = (struct V_20 * ) V_9 ;
if ( F_33 ( V_32 -> V_29 . V_30 . V_34 ) )
F_34 ( V_32 -> V_29 . V_30 . V_34 ) ;
F_35 ( V_9 ) ;
F_36 ( V_32 ) ;
}
static void F_37 ( struct V_1 * V_9 , struct V_14 * V_15 ,
int V_100 )
{
struct V_20 * V_32 ;
if ( ! V_100 )
return;
V_32 = (struct V_20 * ) V_9 ;
if ( V_32 -> V_29 . V_30 . V_34 -> V_15 == V_15 ) {
struct V_101 * V_102 =
F_15 ( F_9 ( V_15 ) -> V_103 ) ;
F_38 ( ! V_102 ) ;
do {
F_34 ( V_32 -> V_29 . V_30 . V_34 ) ;
V_32 -> V_29 . V_30 . V_34 = V_102 ;
F_39 ( V_102 ) ;
V_32 = (struct V_20 * ) V_32 -> V_29 . V_9 . V_104 ;
} while ( V_32 -> V_29 . V_9 . V_90 );
F_40 ( V_102 ) ;
}
F_41 ( V_9 , V_15 ) ;
}
static int T_6 F_42 ( void )
{
return F_43 ( & V_92 ) ;
}
static void F_44 ( void )
{
F_45 ( & V_92 ) ;
}
static int T_7 F_46 ( struct V_2 * V_2 )
{
struct V_105 * V_106 ;
struct V_107 * V_51 ;
V_106 = V_108 ;
if ( ! F_47 ( V_2 , & V_109 ) ) {
V_106 = F_48 ( V_106 , sizeof( V_108 ) , V_110 ) ;
if ( ! V_106 )
goto V_111;
V_106 [ 0 ] . V_61 = & V_2 -> V_90 . V_91 . V_94 ;
}
V_51 = F_49 ( V_2 , L_1 , V_106 ) ;
if ( ! V_51 )
goto V_112;
V_2 -> V_113 . V_114 . V_115 = V_51 ;
return 0 ;
V_112:
if ( ! F_47 ( V_2 , & V_109 ) )
F_50 ( V_106 ) ;
V_111:
return - V_116 ;
}
static void T_8 F_51 ( struct V_2 * V_2 )
{
struct V_105 * V_106 ;
if ( ! V_2 -> V_113 . V_114 . V_115 )
return;
V_106 = V_2 -> V_113 . V_114 . V_115 -> V_117 ;
F_52 ( V_2 -> V_113 . V_114 . V_115 ) ;
if ( ! F_47 ( V_2 , & V_109 ) )
F_50 ( V_106 ) ;
}
static int inline F_46 ( struct V_2 * V_2 )
{
return 0 ;
}
static void inline F_51 ( struct V_2 * V_2 )
{
}
static int T_7 F_53 ( struct V_2 * V_2 )
{
int V_118 ;
memcpy ( & V_2 -> V_90 . V_91 , & V_119 ,
sizeof( V_119 ) ) ;
V_118 = F_54 ( & V_2 -> V_90 . V_91 ) ;
if ( V_118 )
return V_118 ;
V_118 = F_46 ( V_2 ) ;
if ( V_118 )
F_55 ( & V_2 -> V_90 . V_91 ) ;
return V_118 ;
}
static void T_8 F_56 ( struct V_2 * V_2 )
{
F_51 ( V_2 ) ;
F_55 ( & V_2 -> V_90 . V_91 ) ;
}
int T_6 F_57 ( void )
{
int V_118 ;
V_118 = F_42 () ;
if ( V_118 )
goto V_120;
V_118 = F_58 () ;
if ( V_118 )
goto V_121;
V_118 = F_59 () ;
if ( V_118 )
goto V_122;
F_60 ( & V_123 ) ;
V_120:
return V_118 ;
V_122:
F_61 () ;
V_121:
F_44 () ;
goto V_120;
}
void F_62 ( void )
{
F_63 ( & V_123 ) ;
F_64 () ;
F_44 () ;
F_61 () ;
}
