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
T_2 V_50 = F_20 ( V_46 ) ;
const struct V_51 * V_52 = F_21 ( V_46 ) ;
struct V_53 * V_54 ;
const unsigned char * V_55 = F_22 ( V_46 ) ;
T_3 V_56 = V_55 [ F_23 ( V_46 ) -> V_57 ] ;
memset ( V_7 , 0 , sizeof( struct V_6 ) ) ;
V_7 -> V_58 = V_46 -> V_59 ;
V_7 -> V_60 = F_24 ( V_46 ) -> V_11 -> V_61 ;
V_7 -> V_5 = V_47 ? V_52 -> V_4 : V_52 -> V_5 ;
V_7 -> V_4 = V_47 ? V_52 -> V_5 : V_52 -> V_4 ;
while ( V_55 + V_50 + 1 < V_46 -> V_62 ||
F_25 ( V_46 , V_55 + V_50 + 1 - V_46 -> V_62 ) ) {
V_55 = F_22 ( V_46 ) ;
V_54 = (struct V_53 * ) ( V_55 + V_50 ) ;
switch ( V_56 ) {
case V_63 :
V_49 = 1 ;
case V_64 :
case V_65 :
case V_66 :
V_50 += F_26 ( V_54 ) ;
V_56 = V_54 -> V_56 ;
V_54 = (struct V_53 * ) ( V_55 + V_50 ) ;
break;
case V_67 :
case V_68 :
case V_69 :
case V_70 :
case V_71 :
if ( ! V_49 && ( V_55 + V_50 + 4 < V_46 -> V_62 ||
F_25 ( V_46 , V_55 + V_50 + 4 - V_46 -> V_62 ) ) ) {
T_4 * V_72 = ( T_4 * ) V_54 ;
V_7 -> V_73 = V_72 [ ! ! V_47 ] ;
V_7 -> V_74 = V_72 [ ! V_47 ] ;
}
V_7 -> V_75 = V_56 ;
return;
case V_76 :
if ( ! V_49 && F_25 ( V_46 , V_55 + V_50 + 2 - V_46 -> V_62 ) ) {
T_3 * V_77 = ( T_3 * ) V_54 ;
V_7 -> V_78 = V_77 [ 0 ] ;
V_7 -> V_79 = V_77 [ 1 ] ;
}
V_7 -> V_75 = V_56 ;
return;
#if F_27 ( V_80 )
case V_81 :
if ( ! V_49 && F_25 ( V_46 , V_55 + V_50 + 3 - V_46 -> V_62 ) ) {
struct V_82 * V_83 ;
V_83 = (struct V_82 * ) V_54 ;
V_7 -> V_84 = V_83 -> V_85 ;
}
V_7 -> V_75 = V_56 ;
return;
#endif
case V_86 :
case V_87 :
case V_88 :
default:
V_7 -> V_89 = 0 ;
V_7 -> V_75 = V_56 ;
return;
}
}
}
static inline int F_28 ( struct V_90 * V_25 )
{
struct V_2 * V_2 = F_29 ( V_25 , struct V_2 , V_91 . V_92 ) ;
V_93 . V_94 ( V_2 ) ;
return F_30 ( V_25 ) > V_25 -> V_95 * 2 ;
}
static void F_31 ( struct V_1 * V_8 , struct V_96 * V_97 ,
struct V_45 * V_46 , T_5 V_98 )
{
struct V_17 * V_18 = (struct V_17 * ) V_8 ;
struct V_1 * V_23 = V_18 -> V_34 ;
V_23 -> V_25 -> V_99 ( V_23 , V_97 , V_46 , V_98 ) ;
}
static void F_32 ( struct V_1 * V_8 , struct V_96 * V_97 ,
struct V_45 * V_46 )
{
struct V_17 * V_18 = (struct V_17 * ) V_8 ;
struct V_1 * V_23 = V_18 -> V_34 ;
V_23 -> V_25 -> V_100 ( V_23 , V_97 , V_46 ) ;
}
static void F_33 ( struct V_1 * V_8 )
{
struct V_17 * V_18 = (struct V_17 * ) V_8 ;
if ( F_34 ( V_18 -> V_31 . V_32 . V_35 ) )
F_35 ( V_18 -> V_31 . V_32 . V_35 ) ;
F_36 ( V_8 ) ;
if ( F_37 ( & V_18 -> V_31 . V_32 ) ) {
struct V_101 * V_102 = F_38 ( & V_18 -> V_31 . V_32 ) ;
F_39 ( V_102 ) ;
}
F_40 ( V_18 ) ;
}
static void F_41 ( struct V_1 * V_8 , struct V_10 * V_11 ,
int V_103 )
{
struct V_17 * V_18 ;
if ( ! V_103 )
return;
V_18 = (struct V_17 * ) V_8 ;
if ( V_18 -> V_31 . V_32 . V_35 -> V_11 == V_11 ) {
struct V_104 * V_105 =
F_16 ( F_9 ( V_11 ) -> V_106 ) ;
F_42 ( ! V_105 ) ;
do {
F_35 ( V_18 -> V_31 . V_32 . V_35 ) ;
V_18 -> V_31 . V_32 . V_35 = V_105 ;
F_43 ( V_105 ) ;
V_18 = (struct V_17 * ) V_18 -> V_31 . V_8 . V_107 ;
} while ( V_18 -> V_31 . V_8 . V_91 );
F_44 ( V_105 ) ;
}
F_45 ( V_8 , V_11 ) ;
}
static int T_6 F_46 ( void )
{
return F_47 ( & V_93 ) ;
}
static void F_48 ( void )
{
F_49 ( & V_93 ) ;
}
static int T_7 F_50 ( struct V_2 * V_2 )
{
struct V_108 * V_109 ;
struct V_110 * V_52 ;
V_109 = V_111 ;
if ( ! F_51 ( V_2 , & V_112 ) ) {
V_109 = F_52 ( V_109 , sizeof( V_111 ) , V_113 ) ;
if ( ! V_109 )
goto V_114;
V_109 [ 0 ] . V_62 = & V_2 -> V_91 . V_92 . V_95 ;
}
V_52 = F_53 ( V_2 , L_1 , V_109 ) ;
if ( ! V_52 )
goto V_115;
V_2 -> V_21 . V_116 . V_117 = V_52 ;
return 0 ;
V_115:
if ( ! F_51 ( V_2 , & V_112 ) )
F_54 ( V_109 ) ;
V_114:
return - V_118 ;
}
static void T_8 F_55 ( struct V_2 * V_2 )
{
struct V_108 * V_109 ;
if ( V_2 -> V_21 . V_116 . V_117 == NULL )
return;
V_109 = V_2 -> V_21 . V_116 . V_117 -> V_119 ;
F_56 ( V_2 -> V_21 . V_116 . V_117 ) ;
if ( ! F_51 ( V_2 , & V_112 ) )
F_54 ( V_109 ) ;
}
int T_6 F_57 ( void )
{
int V_120 ;
F_58 ( & V_92 ) ;
V_120 = F_46 () ;
if ( V_120 ) {
F_59 ( & V_92 ) ;
goto V_121;
}
V_120 = F_60 () ;
if ( V_120 )
goto V_122;
#ifdef F_61
F_62 ( & V_123 ) ;
#endif
V_121:
return V_120 ;
V_122:
F_48 () ;
goto V_121;
}
void F_63 ( void )
{
#ifdef F_61
F_64 ( & V_123 ) ;
#endif
F_48 () ;
F_65 () ;
F_59 ( & V_92 ) ;
}
