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
if ( ! V_18 -> V_31 . V_32 . V_35 )
return - V_36 ;
F_17 ( & V_18 -> V_31 . V_32 , V_20 ) ;
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
F_18 ( struct V_45 * V_46 , struct V_15 * V_16 , int V_47 )
{
struct V_6 * V_7 = & V_16 -> V_31 . V_48 ;
int V_49 = 0 ;
T_2 V_50 = F_19 ( V_46 ) ;
const struct V_51 * V_52 = F_20 ( V_46 ) ;
struct V_53 * V_54 ;
const unsigned char * V_55 = F_21 ( V_46 ) ;
T_3 V_56 = V_55 [ F_22 ( V_46 ) -> V_57 ] ;
memset ( V_7 , 0 , sizeof( struct V_6 ) ) ;
V_7 -> V_58 = V_46 -> V_59 ;
V_7 -> V_5 = V_47 ? V_52 -> V_4 : V_52 -> V_5 ;
V_7 -> V_4 = V_47 ? V_52 -> V_5 : V_52 -> V_4 ;
while ( V_55 + V_50 + 1 < V_46 -> V_60 ||
F_23 ( V_46 , V_55 + V_50 + 1 - V_46 -> V_60 ) ) {
V_55 = F_21 ( V_46 ) ;
V_54 = (struct V_53 * ) ( V_55 + V_50 ) ;
switch ( V_56 ) {
case V_61 :
V_49 = 1 ;
case V_62 :
case V_63 :
case V_64 :
V_50 += F_24 ( V_54 ) ;
V_56 = V_54 -> V_56 ;
V_54 = (struct V_53 * ) ( V_55 + V_50 ) ;
break;
case V_65 :
case V_66 :
case V_67 :
case V_68 :
case V_69 :
if ( ! V_49 && ( V_55 + V_50 + 4 < V_46 -> V_60 ||
F_23 ( V_46 , V_55 + V_50 + 4 - V_46 -> V_60 ) ) ) {
T_4 * V_70 = ( T_4 * ) V_54 ;
V_7 -> V_71 = V_70 [ ! ! V_47 ] ;
V_7 -> V_72 = V_70 [ ! V_47 ] ;
}
V_7 -> V_73 = V_56 ;
return;
case V_74 :
if ( ! V_49 && F_23 ( V_46 , V_55 + V_50 + 2 - V_46 -> V_60 ) ) {
T_3 * V_75 = ( T_3 * ) V_54 ;
V_7 -> V_76 = V_75 [ 0 ] ;
V_7 -> V_77 = V_75 [ 1 ] ;
}
V_7 -> V_73 = V_56 ;
return;
#if F_25 ( V_78 )
case V_79 :
if ( ! V_49 && F_23 ( V_46 , V_55 + V_50 + 3 - V_46 -> V_60 ) ) {
struct V_80 * V_81 ;
V_81 = (struct V_80 * ) V_54 ;
V_7 -> V_82 = V_81 -> V_83 ;
}
V_7 -> V_73 = V_56 ;
return;
#endif
case V_84 :
case V_85 :
case V_86 :
default:
V_7 -> V_87 = 0 ;
V_7 -> V_73 = V_56 ;
return;
}
}
}
static inline int F_26 ( struct V_88 * V_25 )
{
struct V_2 * V_2 = F_27 ( V_25 , struct V_2 , V_89 . V_90 ) ;
V_91 . V_92 ( V_2 ) ;
return F_28 ( V_25 ) > V_25 -> V_93 * 2 ;
}
static void F_29 ( struct V_1 * V_8 , struct V_94 * V_95 ,
struct V_45 * V_46 , T_5 V_96 )
{
struct V_17 * V_18 = (struct V_17 * ) V_8 ;
struct V_1 * V_23 = V_18 -> V_34 ;
V_23 -> V_25 -> V_97 ( V_23 , V_95 , V_46 , V_96 ) ;
}
static void F_30 ( struct V_1 * V_8 , struct V_94 * V_95 ,
struct V_45 * V_46 )
{
struct V_17 * V_18 = (struct V_17 * ) V_8 ;
struct V_1 * V_23 = V_18 -> V_34 ;
V_23 -> V_25 -> V_98 ( V_23 , V_95 , V_46 ) ;
}
static void F_31 ( struct V_1 * V_8 )
{
struct V_17 * V_18 = (struct V_17 * ) V_8 ;
if ( F_32 ( V_18 -> V_31 . V_32 . V_35 ) )
F_33 ( V_18 -> V_31 . V_32 . V_35 ) ;
F_34 ( V_8 ) ;
if ( F_35 ( & V_18 -> V_31 . V_32 ) ) {
struct V_99 * V_100 = F_36 ( & V_18 -> V_31 . V_32 ) ;
F_37 ( V_100 ) ;
}
F_38 ( V_18 ) ;
}
static void F_39 ( struct V_1 * V_8 , struct V_10 * V_11 ,
int V_101 )
{
struct V_17 * V_18 ;
if ( ! V_101 )
return;
V_18 = (struct V_17 * ) V_8 ;
if ( V_18 -> V_31 . V_32 . V_35 -> V_11 == V_11 ) {
struct V_102 * V_103 =
F_16 ( F_9 ( V_11 ) -> V_104 ) ;
F_40 ( ! V_103 ) ;
do {
F_33 ( V_18 -> V_31 . V_32 . V_35 ) ;
V_18 -> V_31 . V_32 . V_35 = V_103 ;
F_41 ( V_103 ) ;
V_18 = (struct V_17 * ) V_18 -> V_31 . V_8 . V_105 ;
} while ( V_18 -> V_31 . V_8 . V_89 );
F_42 ( V_103 ) ;
}
F_43 ( V_8 , V_11 ) ;
}
static int T_6 F_44 ( void )
{
return F_45 ( & V_91 ) ;
}
static void F_46 ( void )
{
F_47 ( & V_91 ) ;
}
static int T_7 F_48 ( struct V_2 * V_2 )
{
struct V_106 * V_107 ;
struct V_108 * V_52 ;
V_107 = V_109 ;
if ( ! F_49 ( V_2 , & V_110 ) ) {
V_107 = F_50 ( V_107 , sizeof( V_109 ) , V_111 ) ;
if ( ! V_107 )
goto V_112;
V_107 [ 0 ] . V_60 = & V_2 -> V_89 . V_90 . V_93 ;
}
V_52 = F_51 ( V_2 , L_1 , V_107 ) ;
if ( ! V_52 )
goto V_113;
V_2 -> V_21 . V_114 . V_115 = V_52 ;
return 0 ;
V_113:
if ( ! F_49 ( V_2 , & V_110 ) )
F_52 ( V_107 ) ;
V_112:
return - V_116 ;
}
static void T_8 F_53 ( struct V_2 * V_2 )
{
struct V_106 * V_107 ;
if ( V_2 -> V_21 . V_114 . V_115 == NULL )
return;
V_107 = V_2 -> V_21 . V_114 . V_115 -> V_117 ;
F_54 ( V_2 -> V_21 . V_114 . V_115 ) ;
if ( ! F_49 ( V_2 , & V_110 ) )
F_52 ( V_107 ) ;
}
int T_6 F_55 ( void )
{
int V_118 ;
F_56 ( & V_90 ) ;
V_118 = F_44 () ;
if ( V_118 ) {
F_57 ( & V_90 ) ;
goto V_119;
}
V_118 = F_58 () ;
if ( V_118 )
goto V_120;
#ifdef F_59
F_60 ( & V_121 ) ;
#endif
V_119:
return V_118 ;
V_120:
F_46 () ;
goto V_119;
}
void F_61 ( void )
{
#ifdef F_59
F_62 ( & V_121 ) ;
#endif
F_46 () ;
F_63 () ;
F_57 ( & V_90 ) ;
}
