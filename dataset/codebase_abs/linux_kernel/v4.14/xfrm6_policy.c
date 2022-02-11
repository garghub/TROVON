static struct V_1 * F_1 ( struct V_2 * V_2 , int V_3 , int V_4 ,
const T_1 * V_5 ,
const T_1 * V_6 ,
T_2 V_7 )
{
struct V_8 V_9 ;
struct V_1 * V_10 ;
int V_11 ;
memset ( & V_9 , 0 , sizeof( V_9 ) ) ;
V_9 . V_12 = F_2 ( V_2 , V_4 ) ;
V_9 . V_13 = V_14 ;
V_9 . V_15 = V_7 ;
memcpy ( & V_9 . V_6 , V_6 , sizeof( V_9 . V_6 ) ) ;
if ( V_5 )
memcpy ( & V_9 . V_5 , V_5 , sizeof( V_9 . V_5 ) ) ;
V_10 = F_3 ( V_2 , NULL , & V_9 ) ;
V_11 = V_10 -> error ;
if ( V_10 -> error ) {
F_4 ( V_10 ) ;
V_10 = F_5 ( V_11 ) ;
}
return V_10 ;
}
static int F_6 ( struct V_2 * V_2 , int V_4 ,
T_1 * V_5 , T_1 * V_6 ,
T_2 V_7 )
{
struct V_1 * V_10 ;
struct V_16 * V_17 ;
V_10 = F_1 ( V_2 , 0 , V_4 , NULL , V_6 , V_7 ) ;
if ( F_7 ( V_10 ) )
return - V_18 ;
V_17 = F_8 ( V_10 ) -> V_17 ;
F_9 ( F_10 ( V_17 ) , V_17 , & V_6 -> V_19 , 0 , & V_5 -> V_19 ) ;
F_4 ( V_10 ) ;
return 0 ;
}
static int F_11 ( const struct V_20 * V_21 )
{
return 0 ;
}
static int F_12 ( struct V_22 * V_23 , struct V_1 * V_10 ,
int V_24 )
{
if ( V_10 -> V_25 -> V_26 == V_27 ) {
struct V_28 * V_29 = (struct V_28 * ) V_10 ;
V_23 -> V_30 = F_13 ( V_29 ) ;
}
V_23 -> V_31 . V_32 . V_33 = V_24 ;
return 0 ;
}
static int F_14 ( struct V_22 * V_34 , struct V_16 * V_17 ,
const struct V_20 * V_21 )
{
struct V_28 * V_29 = (struct V_28 * ) V_34 -> V_35 ;
V_34 -> V_31 . V_10 . V_17 = V_17 ;
F_15 ( V_17 ) ;
V_34 -> V_31 . V_32 . V_36 = F_16 ( V_17 ) ;
if ( ! V_34 -> V_31 . V_32 . V_36 ) {
F_17 ( V_17 ) ;
return - V_37 ;
}
V_34 -> V_31 . V_32 . V_38 = V_29 -> V_38 & ( V_39 |
V_40 ) ;
V_34 -> V_31 . V_32 . V_41 = V_29 -> V_41 ;
V_34 -> V_31 . V_32 . V_42 = V_29 -> V_42 ;
V_34 -> V_43 = F_13 ( V_29 ) ;
V_34 -> V_31 . V_32 . V_44 = V_29 -> V_44 ;
V_34 -> V_31 . V_32 . V_45 = V_29 -> V_45 ;
V_34 -> V_31 . V_32 . V_46 = V_29 -> V_46 ;
return 0 ;
}
static inline void
F_18 ( struct V_47 * V_48 , struct V_20 * V_21 , int V_49 )
{
struct V_8 * V_9 = & V_21 -> V_31 . V_50 ;
int V_51 = 0 ;
const struct V_52 * V_53 = F_19 ( V_48 ) ;
T_3 V_54 = sizeof( * V_53 ) ;
struct V_55 * V_56 ;
const unsigned char * V_57 = F_20 ( V_48 ) ;
T_3 V_58 = F_21 ( V_48 ) -> V_58 ;
int V_4 = 0 ;
T_4 V_59 ;
if ( ! V_58 )
V_58 = F_22 ( struct V_52 , V_59 ) ;
V_59 = V_57 [ V_58 ] ;
if ( F_23 ( V_48 ) )
V_4 = F_23 ( V_48 ) -> V_17 -> V_60 ;
memset ( V_9 , 0 , sizeof( struct V_8 ) ) ;
V_9 -> V_15 = V_48 -> V_7 ;
V_9 -> V_12 = V_49 ? V_48 -> V_61 : V_4 ;
V_9 -> V_6 = V_49 ? V_53 -> V_5 : V_53 -> V_6 ;
V_9 -> V_5 = V_49 ? V_53 -> V_6 : V_53 -> V_5 ;
while ( V_57 + V_54 + 1 < V_48 -> V_62 ||
F_24 ( V_48 , V_57 + V_54 + 1 - V_48 -> V_62 ) ) {
V_57 = F_20 ( V_48 ) ;
V_56 = (struct V_55 * ) ( V_57 + V_54 ) ;
switch ( V_59 ) {
case V_63 :
V_51 = 1 ;
case V_64 :
case V_65 :
case V_66 :
V_54 += F_25 ( V_56 ) ;
V_59 = V_56 -> V_59 ;
V_56 = (struct V_55 * ) ( V_57 + V_54 ) ;
break;
case V_67 :
case V_68 :
case V_69 :
case V_70 :
case V_71 :
if ( ! V_51 && ( V_57 + V_54 + 4 < V_48 -> V_62 ||
F_24 ( V_48 , V_57 + V_54 + 4 - V_48 -> V_62 ) ) ) {
T_5 * V_72 ;
V_57 = F_20 ( V_48 ) ;
V_72 = ( T_5 * ) ( V_57 + V_54 ) ;
V_9 -> V_73 = V_72 [ ! ! V_49 ] ;
V_9 -> V_74 = V_72 [ ! V_49 ] ;
}
V_9 -> V_75 = V_59 ;
return;
case V_76 :
if ( ! V_51 && ( V_57 + V_54 + 2 < V_48 -> V_62 ||
F_24 ( V_48 , V_57 + V_54 + 2 - V_48 -> V_62 ) ) ) {
T_4 * V_77 ;
V_57 = F_20 ( V_48 ) ;
V_77 = ( T_4 * ) ( V_57 + V_54 ) ;
V_9 -> V_78 = V_77 [ 0 ] ;
V_9 -> V_79 = V_77 [ 1 ] ;
}
V_9 -> V_75 = V_59 ;
return;
#if F_26 ( V_80 )
case V_81 :
V_54 += F_25 ( V_56 ) ;
if ( ! V_51 && ( V_57 + V_54 + 3 < V_48 -> V_62 ||
F_24 ( V_48 , V_57 + V_54 + 3 - V_48 -> V_62 ) ) ) {
struct V_82 * V_83 ;
V_57 = F_20 ( V_48 ) ;
V_83 = (struct V_82 * ) ( V_57 + V_54 ) ;
V_9 -> V_84 = V_83 -> V_85 ;
}
V_9 -> V_75 = V_59 ;
return;
#endif
case V_86 :
case V_87 :
case V_88 :
default:
V_9 -> V_89 = 0 ;
V_9 -> V_75 = V_59 ;
return;
}
}
}
static void F_27 ( struct V_1 * V_10 , struct V_90 * V_91 ,
struct V_47 * V_48 , T_2 V_92 )
{
struct V_22 * V_34 = (struct V_22 * ) V_10 ;
struct V_1 * V_23 = V_34 -> V_35 ;
V_23 -> V_25 -> V_93 ( V_23 , V_91 , V_48 , V_92 ) ;
}
static void F_28 ( struct V_1 * V_10 , struct V_90 * V_91 ,
struct V_47 * V_48 )
{
struct V_22 * V_34 = (struct V_22 * ) V_10 ;
struct V_1 * V_23 = V_34 -> V_35 ;
V_23 -> V_25 -> V_94 ( V_23 , V_91 , V_48 ) ;
}
static void F_29 ( struct V_1 * V_10 )
{
struct V_22 * V_34 = (struct V_22 * ) V_10 ;
if ( F_30 ( V_34 -> V_31 . V_32 . V_36 ) )
F_31 ( V_34 -> V_31 . V_32 . V_36 ) ;
F_32 ( V_10 ) ;
F_33 ( V_34 ) ;
}
static void F_34 ( struct V_1 * V_10 , struct V_16 * V_17 ,
int V_95 )
{
struct V_22 * V_34 ;
if ( ! V_95 )
return;
V_34 = (struct V_22 * ) V_10 ;
if ( V_34 -> V_31 . V_32 . V_36 -> V_17 == V_17 ) {
struct V_96 * V_97 =
F_16 ( F_10 ( V_17 ) -> V_98 ) ;
F_35 ( ! V_97 ) ;
do {
F_31 ( V_34 -> V_31 . V_32 . V_36 ) ;
V_34 -> V_31 . V_32 . V_36 = V_97 ;
F_36 ( V_97 ) ;
V_34 = (struct V_22 * ) V_34 -> V_31 . V_10 . V_99 ;
} while ( V_34 -> V_31 . V_10 . V_100 );
F_37 ( V_97 ) ;
}
F_38 ( V_10 , V_17 ) ;
}
static int T_6 F_39 ( void )
{
return F_40 ( & V_101 , V_27 ) ;
}
static void F_41 ( void )
{
F_42 ( & V_101 ) ;
}
static int T_7 F_43 ( struct V_2 * V_2 )
{
struct V_102 * V_103 ;
struct V_104 * V_53 ;
V_103 = V_105 ;
if ( ! F_44 ( V_2 , & V_106 ) ) {
V_103 = F_45 ( V_103 , sizeof( V_105 ) , V_107 ) ;
if ( ! V_103 )
goto V_108;
V_103 [ 0 ] . V_62 = & V_2 -> V_100 . V_109 . V_110 ;
}
V_53 = F_46 ( V_2 , L_1 , V_103 ) ;
if ( ! V_53 )
goto V_111;
V_2 -> V_112 . V_113 . V_114 = V_53 ;
return 0 ;
V_111:
if ( ! F_44 ( V_2 , & V_106 ) )
F_47 ( V_103 ) ;
V_108:
return - V_115 ;
}
static void T_8 F_48 ( struct V_2 * V_2 )
{
struct V_102 * V_103 ;
if ( ! V_2 -> V_112 . V_113 . V_114 )
return;
V_103 = V_2 -> V_112 . V_113 . V_114 -> V_116 ;
F_49 ( V_2 -> V_112 . V_113 . V_114 ) ;
if ( ! F_44 ( V_2 , & V_106 ) )
F_47 ( V_103 ) ;
}
static inline int F_43 ( struct V_2 * V_2 )
{
return 0 ;
}
static inline void F_48 ( struct V_2 * V_2 )
{
}
static int T_7 F_50 ( struct V_2 * V_2 )
{
int V_117 ;
memcpy ( & V_2 -> V_100 . V_109 , & V_118 ,
sizeof( V_118 ) ) ;
V_117 = F_51 ( & V_2 -> V_100 . V_109 ) ;
if ( V_117 )
return V_117 ;
V_117 = F_43 ( V_2 ) ;
if ( V_117 )
F_52 ( & V_2 -> V_100 . V_109 ) ;
return V_117 ;
}
static void T_8 F_53 ( struct V_2 * V_2 )
{
F_48 ( V_2 ) ;
F_52 ( & V_2 -> V_100 . V_109 ) ;
}
int T_6 F_54 ( void )
{
int V_117 ;
V_117 = F_39 () ;
if ( V_117 )
goto V_119;
V_117 = F_55 () ;
if ( V_117 )
goto V_120;
V_117 = F_56 () ;
if ( V_117 )
goto V_121;
F_57 ( & V_122 ) ;
V_119:
return V_117 ;
V_121:
F_58 () ;
V_120:
F_41 () ;
goto V_119;
}
void F_59 ( void )
{
F_60 ( & V_122 ) ;
F_61 () ;
F_41 () ;
F_58 () ;
}
