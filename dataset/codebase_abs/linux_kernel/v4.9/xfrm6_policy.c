static struct V_1 * F_1 ( struct V_2 * V_2 , int V_3 , int V_4 ,
const T_1 * V_5 ,
const T_1 * V_6 )
{
struct V_7 V_8 ;
struct V_1 * V_9 ;
int V_10 ;
memset ( & V_8 , 0 , sizeof( V_8 ) ) ;
V_8 . V_11 = F_2 ( V_2 , V_4 ) ;
V_8 . V_12 = V_13 ;
memcpy ( & V_8 . V_6 , V_6 , sizeof( V_8 . V_6 ) ) ;
if ( V_5 )
memcpy ( & V_8 . V_5 , V_5 , sizeof( V_8 . V_5 ) ) ;
V_9 = F_3 ( V_2 , NULL , & V_8 ) ;
V_10 = V_9 -> error ;
if ( V_9 -> error ) {
F_4 ( V_9 ) ;
V_9 = F_5 ( V_10 ) ;
}
return V_9 ;
}
static int F_6 ( struct V_2 * V_2 , int V_4 ,
T_1 * V_5 , T_1 * V_6 )
{
struct V_1 * V_9 ;
struct V_14 * V_15 ;
V_9 = F_1 ( V_2 , 0 , V_4 , NULL , V_6 ) ;
if ( F_7 ( V_9 ) )
return - V_16 ;
V_15 = F_8 ( V_9 ) -> V_15 ;
F_9 ( F_10 ( V_15 ) , V_15 , & V_6 -> V_17 , 0 , & V_5 -> V_17 ) ;
F_4 ( V_9 ) ;
return 0 ;
}
static int F_11 ( const struct V_18 * V_19 )
{
return 0 ;
}
static int F_12 ( struct V_20 * V_21 , struct V_1 * V_9 ,
int V_22 )
{
if ( V_9 -> V_23 -> V_24 == V_25 ) {
struct V_26 * V_27 = (struct V_26 * ) V_9 ;
V_21 -> V_28 = F_13 ( V_27 ) ;
}
V_21 -> V_29 . V_30 . V_31 = V_22 ;
return 0 ;
}
static int F_14 ( struct V_20 * V_32 , struct V_14 * V_15 ,
const struct V_18 * V_19 )
{
struct V_26 * V_27 = (struct V_26 * ) V_32 -> V_33 ;
V_32 -> V_29 . V_9 . V_15 = V_15 ;
F_15 ( V_15 ) ;
V_32 -> V_29 . V_30 . V_34 = F_16 ( V_15 ) ;
if ( ! V_32 -> V_29 . V_30 . V_34 ) {
F_17 ( V_15 ) ;
return - V_35 ;
}
V_32 -> V_29 . V_30 . V_36 = V_27 -> V_36 & ( V_37 |
V_38 ) ;
V_32 -> V_29 . V_30 . V_39 = V_27 -> V_39 ;
V_32 -> V_29 . V_30 . V_40 = V_27 -> V_40 ;
V_32 -> V_41 = F_13 ( V_27 ) ;
V_32 -> V_29 . V_30 . V_42 = V_27 -> V_42 ;
V_32 -> V_29 . V_30 . V_43 = V_27 -> V_43 ;
V_32 -> V_29 . V_30 . V_44 = V_27 -> V_44 ;
return 0 ;
}
static inline void
F_18 ( struct V_45 * V_46 , struct V_18 * V_19 , int V_47 )
{
struct V_7 * V_8 = & V_19 -> V_29 . V_48 ;
int V_49 = 0 ;
const struct V_50 * V_51 = F_19 ( V_46 ) ;
T_2 V_52 = sizeof( * V_51 ) ;
struct V_53 * V_54 ;
const unsigned char * V_55 = F_20 ( V_46 ) ;
T_2 V_56 = F_21 ( V_46 ) -> V_56 ;
int V_4 = 0 ;
T_3 V_57 ;
if ( ! V_56 )
V_56 = F_22 ( struct V_50 , V_57 ) ;
V_57 = V_55 [ V_56 ] ;
if ( F_23 ( V_46 ) )
V_4 = F_23 ( V_46 ) -> V_15 -> V_58 ;
memset ( V_8 , 0 , sizeof( struct V_7 ) ) ;
V_8 -> V_59 = V_46 -> V_60 ;
V_8 -> V_11 = V_47 ? V_46 -> V_61 : V_4 ;
V_8 -> V_6 = V_47 ? V_51 -> V_5 : V_51 -> V_6 ;
V_8 -> V_5 = V_47 ? V_51 -> V_6 : V_51 -> V_5 ;
while ( V_55 + V_52 + 1 < V_46 -> V_62 ||
F_24 ( V_46 , V_55 + V_52 + 1 - V_46 -> V_62 ) ) {
V_55 = F_20 ( V_46 ) ;
V_54 = (struct V_53 * ) ( V_55 + V_52 ) ;
switch ( V_57 ) {
case V_63 :
V_49 = 1 ;
case V_64 :
case V_65 :
case V_66 :
V_52 += F_25 ( V_54 ) ;
V_57 = V_54 -> V_57 ;
V_54 = (struct V_53 * ) ( V_55 + V_52 ) ;
break;
case V_67 :
case V_68 :
case V_69 :
case V_70 :
case V_71 :
if ( ! V_49 && ( V_55 + V_52 + 4 < V_46 -> V_62 ||
F_24 ( V_46 , V_55 + V_52 + 4 - V_46 -> V_62 ) ) ) {
T_4 * V_72 ;
V_55 = F_20 ( V_46 ) ;
V_72 = ( T_4 * ) ( V_55 + V_52 ) ;
V_8 -> V_73 = V_72 [ ! ! V_47 ] ;
V_8 -> V_74 = V_72 [ ! V_47 ] ;
}
V_8 -> V_75 = V_57 ;
return;
case V_76 :
if ( ! V_49 && ( V_55 + V_52 + 2 < V_46 -> V_62 ||
F_24 ( V_46 , V_55 + V_52 + 2 - V_46 -> V_62 ) ) ) {
T_3 * V_77 ;
V_55 = F_20 ( V_46 ) ;
V_77 = ( T_3 * ) ( V_55 + V_52 ) ;
V_8 -> V_78 = V_77 [ 0 ] ;
V_8 -> V_79 = V_77 [ 1 ] ;
}
V_8 -> V_75 = V_57 ;
return;
#if F_26 ( V_80 )
case V_81 :
V_52 += F_25 ( V_54 ) ;
if ( ! V_49 && ( V_55 + V_52 + 3 < V_46 -> V_62 ||
F_24 ( V_46 , V_55 + V_52 + 3 - V_46 -> V_62 ) ) ) {
struct V_82 * V_83 ;
V_55 = F_20 ( V_46 ) ;
V_83 = (struct V_82 * ) ( V_55 + V_52 ) ;
V_8 -> V_84 = V_83 -> V_85 ;
}
V_8 -> V_75 = V_57 ;
return;
#endif
case V_86 :
case V_87 :
case V_88 :
default:
V_8 -> V_89 = 0 ;
V_8 -> V_75 = V_57 ;
return;
}
}
}
static inline int F_27 ( struct V_90 * V_23 )
{
struct V_2 * V_2 = F_28 ( V_23 , struct V_2 , V_91 . V_92 ) ;
V_93 . V_94 ( V_2 ) ;
return F_29 ( V_23 ) > V_23 -> V_95 * 2 ;
}
static void F_30 ( struct V_1 * V_9 , struct V_96 * V_97 ,
struct V_45 * V_46 , T_5 V_98 )
{
struct V_20 * V_32 = (struct V_20 * ) V_9 ;
struct V_1 * V_21 = V_32 -> V_33 ;
V_21 -> V_23 -> V_99 ( V_21 , V_97 , V_46 , V_98 ) ;
}
static void F_31 ( struct V_1 * V_9 , struct V_96 * V_97 ,
struct V_45 * V_46 )
{
struct V_20 * V_32 = (struct V_20 * ) V_9 ;
struct V_1 * V_21 = V_32 -> V_33 ;
V_21 -> V_23 -> V_100 ( V_21 , V_97 , V_46 ) ;
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
int V_101 )
{
struct V_20 * V_32 ;
if ( ! V_101 )
return;
V_32 = (struct V_20 * ) V_9 ;
if ( V_32 -> V_29 . V_30 . V_34 -> V_15 == V_15 ) {
struct V_102 * V_103 =
F_16 ( F_10 ( V_15 ) -> V_104 ) ;
F_38 ( ! V_103 ) ;
do {
F_34 ( V_32 -> V_29 . V_30 . V_34 ) ;
V_32 -> V_29 . V_30 . V_34 = V_103 ;
F_39 ( V_103 ) ;
V_32 = (struct V_20 * ) V_32 -> V_29 . V_9 . V_105 ;
} while ( V_32 -> V_29 . V_9 . V_91 );
F_40 ( V_103 ) ;
}
F_41 ( V_9 , V_15 ) ;
}
static int T_6 F_42 ( void )
{
return F_43 ( & V_93 ) ;
}
static void F_44 ( void )
{
F_45 ( & V_93 ) ;
}
static int T_7 F_46 ( struct V_2 * V_2 )
{
struct V_106 * V_107 ;
struct V_108 * V_51 ;
V_107 = V_109 ;
if ( ! F_47 ( V_2 , & V_110 ) ) {
V_107 = F_48 ( V_107 , sizeof( V_109 ) , V_111 ) ;
if ( ! V_107 )
goto V_112;
V_107 [ 0 ] . V_62 = & V_2 -> V_91 . V_92 . V_95 ;
}
V_51 = F_49 ( V_2 , L_1 , V_107 ) ;
if ( ! V_51 )
goto V_113;
V_2 -> V_114 . V_115 . V_116 = V_51 ;
return 0 ;
V_113:
if ( ! F_47 ( V_2 , & V_110 ) )
F_50 ( V_107 ) ;
V_112:
return - V_117 ;
}
static void T_8 F_51 ( struct V_2 * V_2 )
{
struct V_106 * V_107 ;
if ( ! V_2 -> V_114 . V_115 . V_116 )
return;
V_107 = V_2 -> V_114 . V_115 . V_116 -> V_118 ;
F_52 ( V_2 -> V_114 . V_115 . V_116 ) ;
if ( ! F_47 ( V_2 , & V_110 ) )
F_50 ( V_107 ) ;
}
static inline int F_46 ( struct V_2 * V_2 )
{
return 0 ;
}
static inline void F_51 ( struct V_2 * V_2 )
{
}
static int T_7 F_53 ( struct V_2 * V_2 )
{
int V_119 ;
memcpy ( & V_2 -> V_91 . V_92 , & V_120 ,
sizeof( V_120 ) ) ;
V_119 = F_54 ( & V_2 -> V_91 . V_92 ) ;
if ( V_119 )
return V_119 ;
V_119 = F_46 ( V_2 ) ;
if ( V_119 )
F_55 ( & V_2 -> V_91 . V_92 ) ;
return V_119 ;
}
static void T_8 F_56 ( struct V_2 * V_2 )
{
F_51 ( V_2 ) ;
F_55 ( & V_2 -> V_91 . V_92 ) ;
}
int T_6 F_57 ( void )
{
int V_119 ;
V_119 = F_42 () ;
if ( V_119 )
goto V_121;
V_119 = F_58 () ;
if ( V_119 )
goto V_122;
V_119 = F_59 () ;
if ( V_119 )
goto V_123;
F_60 ( & V_124 ) ;
V_121:
return V_119 ;
V_123:
F_61 () ;
V_122:
F_44 () ;
goto V_121;
}
void F_62 ( void )
{
F_63 ( & V_124 ) ;
F_64 () ;
F_44 () ;
F_61 () ;
}
