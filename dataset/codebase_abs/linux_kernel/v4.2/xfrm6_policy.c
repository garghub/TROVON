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
static int F_11 ( struct V_16 * V_17 , struct V_1 * V_8 ,
int V_18 )
{
if ( V_8 -> V_19 -> V_20 == V_21 ) {
struct V_22 * V_23 = (struct V_22 * ) V_8 ;
V_17 -> V_24 = F_12 ( V_23 ) ;
}
V_17 -> V_25 . V_26 . V_27 = V_18 ;
return 0 ;
}
static int F_13 ( struct V_16 * V_28 , struct V_10 * V_11 ,
const struct V_14 * V_15 )
{
struct V_22 * V_23 = (struct V_22 * ) V_28 -> V_29 ;
V_28 -> V_25 . V_8 . V_11 = V_11 ;
F_14 ( V_11 ) ;
V_28 -> V_25 . V_26 . V_30 = F_15 ( V_11 ) ;
if ( ! V_28 -> V_25 . V_26 . V_30 ) {
F_16 ( V_11 ) ;
return - V_31 ;
}
V_28 -> V_25 . V_26 . V_32 = V_23 -> V_32 & ( V_33 |
V_34 ) ;
V_28 -> V_25 . V_26 . V_35 = V_23 -> V_35 ;
V_28 -> V_25 . V_26 . V_36 = V_23 -> V_36 ;
V_28 -> V_37 = F_12 ( V_23 ) ;
V_28 -> V_25 . V_26 . V_38 = V_23 -> V_38 ;
V_28 -> V_25 . V_26 . V_39 = V_23 -> V_39 ;
V_28 -> V_25 . V_26 . V_40 = V_23 -> V_40 ;
return 0 ;
}
static inline void
F_17 ( struct V_41 * V_42 , struct V_14 * V_15 , int V_43 )
{
struct V_6 * V_7 = & V_15 -> V_25 . V_44 ;
int V_45 = 0 ;
const struct V_46 * V_47 = F_18 ( V_42 ) ;
T_2 V_48 = sizeof( * V_47 ) ;
struct V_49 * V_50 ;
const unsigned char * V_51 = F_19 ( V_42 ) ;
T_2 V_52 = F_20 ( V_42 ) -> V_52 ;
int V_53 = 0 ;
T_3 V_54 ;
if ( ! V_52 )
V_52 = F_21 ( struct V_46 , V_54 ) ;
V_54 = V_51 [ V_52 ] ;
if ( F_22 ( V_42 ) )
V_53 = F_22 ( V_42 ) -> V_11 -> V_55 ;
memset ( V_7 , 0 , sizeof( struct V_6 ) ) ;
V_7 -> V_56 = V_42 -> V_57 ;
V_7 -> V_58 = V_43 ? V_42 -> V_59 : V_53 ;
V_7 -> V_5 = V_43 ? V_47 -> V_4 : V_47 -> V_5 ;
V_7 -> V_4 = V_43 ? V_47 -> V_5 : V_47 -> V_4 ;
while ( V_51 + V_48 + 1 < V_42 -> V_60 ||
F_23 ( V_42 , V_51 + V_48 + 1 - V_42 -> V_60 ) ) {
V_51 = F_19 ( V_42 ) ;
V_50 = (struct V_49 * ) ( V_51 + V_48 ) ;
switch ( V_54 ) {
case V_61 :
V_45 = 1 ;
case V_62 :
case V_63 :
case V_64 :
V_48 += F_24 ( V_50 ) ;
V_54 = V_50 -> V_54 ;
V_50 = (struct V_49 * ) ( V_51 + V_48 ) ;
break;
case V_65 :
case V_66 :
case V_67 :
case V_68 :
case V_69 :
if ( ! V_45 && ( V_51 + V_48 + 4 < V_42 -> V_60 ||
F_23 ( V_42 , V_51 + V_48 + 4 - V_42 -> V_60 ) ) ) {
T_4 * V_70 ;
V_51 = F_19 ( V_42 ) ;
V_70 = ( T_4 * ) ( V_51 + V_48 ) ;
V_7 -> V_71 = V_70 [ ! ! V_43 ] ;
V_7 -> V_72 = V_70 [ ! V_43 ] ;
}
V_7 -> V_73 = V_54 ;
return;
case V_74 :
if ( ! V_45 && F_23 ( V_42 , V_51 + V_48 + 2 - V_42 -> V_60 ) ) {
T_3 * V_75 ;
V_51 = F_19 ( V_42 ) ;
V_75 = ( T_3 * ) ( V_51 + V_48 ) ;
V_7 -> V_76 = V_75 [ 0 ] ;
V_7 -> V_77 = V_75 [ 1 ] ;
}
V_7 -> V_73 = V_54 ;
return;
#if F_25 ( V_78 )
case V_79 :
V_48 += F_24 ( V_50 ) ;
if ( ! V_45 && F_23 ( V_42 , V_51 + V_48 + 3 - V_42 -> V_60 ) ) {
struct V_80 * V_81 ;
V_51 = F_19 ( V_42 ) ;
V_81 = (struct V_80 * ) ( V_51 + V_48 ) ;
V_7 -> V_82 = V_81 -> V_83 ;
}
V_7 -> V_73 = V_54 ;
return;
#endif
case V_84 :
case V_85 :
case V_86 :
default:
V_7 -> V_87 = 0 ;
V_7 -> V_73 = V_54 ;
return;
}
}
}
static inline int F_26 ( struct V_88 * V_19 )
{
struct V_2 * V_2 = F_27 ( V_19 , struct V_2 , V_89 . V_90 ) ;
V_91 . V_92 ( V_2 ) ;
return F_28 ( V_19 ) > V_19 -> V_93 * 2 ;
}
static void F_29 ( struct V_1 * V_8 , struct V_94 * V_95 ,
struct V_41 * V_42 , T_5 V_96 )
{
struct V_16 * V_28 = (struct V_16 * ) V_8 ;
struct V_1 * V_17 = V_28 -> V_29 ;
V_17 -> V_19 -> V_97 ( V_17 , V_95 , V_42 , V_96 ) ;
}
static void F_30 ( struct V_1 * V_8 , struct V_94 * V_95 ,
struct V_41 * V_42 )
{
struct V_16 * V_28 = (struct V_16 * ) V_8 ;
struct V_1 * V_17 = V_28 -> V_29 ;
V_17 -> V_19 -> V_98 ( V_17 , V_95 , V_42 ) ;
}
static void F_31 ( struct V_1 * V_8 )
{
struct V_16 * V_28 = (struct V_16 * ) V_8 ;
if ( F_32 ( V_28 -> V_25 . V_26 . V_30 ) )
F_33 ( V_28 -> V_25 . V_26 . V_30 ) ;
F_34 ( V_8 ) ;
F_35 ( V_28 ) ;
}
static void F_36 ( struct V_1 * V_8 , struct V_10 * V_11 ,
int V_99 )
{
struct V_16 * V_28 ;
if ( ! V_99 )
return;
V_28 = (struct V_16 * ) V_8 ;
if ( V_28 -> V_25 . V_26 . V_30 -> V_11 == V_11 ) {
struct V_100 * V_101 =
F_15 ( F_9 ( V_11 ) -> V_102 ) ;
F_37 ( ! V_101 ) ;
do {
F_33 ( V_28 -> V_25 . V_26 . V_30 ) ;
V_28 -> V_25 . V_26 . V_30 = V_101 ;
F_38 ( V_101 ) ;
V_28 = (struct V_16 * ) V_28 -> V_25 . V_8 . V_103 ;
} while ( V_28 -> V_25 . V_8 . V_89 );
F_39 ( V_101 ) ;
}
F_40 ( V_8 , V_11 ) ;
}
static int T_6 F_41 ( void )
{
return F_42 ( & V_91 ) ;
}
static void F_43 ( void )
{
F_44 ( & V_91 ) ;
}
static int T_7 F_45 ( struct V_2 * V_2 )
{
struct V_104 * V_105 ;
struct V_106 * V_47 ;
V_105 = V_107 ;
if ( ! F_46 ( V_2 , & V_108 ) ) {
V_105 = F_47 ( V_105 , sizeof( V_107 ) , V_109 ) ;
if ( ! V_105 )
goto V_110;
V_105 [ 0 ] . V_60 = & V_2 -> V_89 . V_90 . V_93 ;
}
V_47 = F_48 ( V_2 , L_1 , V_105 ) ;
if ( ! V_47 )
goto V_111;
V_2 -> V_112 . V_113 . V_114 = V_47 ;
return 0 ;
V_111:
if ( ! F_46 ( V_2 , & V_108 ) )
F_49 ( V_105 ) ;
V_110:
return - V_115 ;
}
static void T_8 F_50 ( struct V_2 * V_2 )
{
struct V_104 * V_105 ;
if ( ! V_2 -> V_112 . V_113 . V_114 )
return;
V_105 = V_2 -> V_112 . V_113 . V_114 -> V_116 ;
F_51 ( V_2 -> V_112 . V_113 . V_114 ) ;
if ( ! F_46 ( V_2 , & V_108 ) )
F_49 ( V_105 ) ;
}
int T_6 F_52 ( void )
{
int V_117 ;
F_53 ( & V_90 ) ;
V_117 = F_41 () ;
if ( V_117 ) {
F_54 ( & V_90 ) ;
goto V_118;
}
V_117 = F_55 () ;
if ( V_117 )
goto V_119;
V_117 = F_56 () ;
if ( V_117 )
goto V_120;
#ifdef F_57
F_58 ( & V_121 ) ;
#endif
V_118:
return V_117 ;
V_120:
F_59 () ;
V_119:
F_43 () ;
goto V_118;
}
void F_60 ( void )
{
#ifdef F_57
F_61 ( & V_121 ) ;
#endif
F_62 () ;
F_43 () ;
F_59 () ;
F_54 ( & V_90 ) ;
}
