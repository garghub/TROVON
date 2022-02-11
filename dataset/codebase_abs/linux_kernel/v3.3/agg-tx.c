static void F_1 ( struct V_1 * V_2 ,
const T_1 * V_3 , T_2 V_4 ,
T_1 V_5 , T_2 V_6 ,
T_2 V_7 , T_2 V_8 )
{
struct V_9 * V_10 = V_2 -> V_10 ;
struct V_11 * V_12 ;
struct V_13 * V_14 ;
T_2 V_15 ;
V_12 = F_2 ( sizeof( * V_14 ) + V_10 -> V_16 . V_17 ) ;
if ( ! V_12 )
return;
F_3 ( V_12 , V_10 -> V_16 . V_17 ) ;
V_14 = (struct V_13 * ) F_4 ( V_12 , 24 ) ;
memset ( V_14 , 0 , 24 ) ;
memcpy ( V_14 -> V_3 , V_3 , V_18 ) ;
memcpy ( V_14 -> V_19 , V_2 -> V_20 . V_21 , V_18 ) ;
if ( V_2 -> V_20 . type == V_22 ||
V_2 -> V_20 . type == V_23 ||
V_2 -> V_20 . type == V_24 )
memcpy ( V_14 -> V_25 , V_2 -> V_20 . V_21 , V_18 ) ;
else if ( V_2 -> V_20 . type == V_26 )
memcpy ( V_14 -> V_25 , V_2 -> V_27 . V_28 . V_25 , V_18 ) ;
else if ( V_2 -> V_20 . type == V_29 )
memcpy ( V_14 -> V_25 , V_2 -> V_27 . V_30 . V_25 , V_18 ) ;
V_14 -> V_31 = F_5 ( V_32 |
V_33 ) ;
F_4 ( V_12 , 1 + sizeof( V_14 -> V_27 . V_34 . V_27 . V_35 ) ) ;
V_14 -> V_27 . V_34 . V_36 = V_37 ;
V_14 -> V_27 . V_34 . V_27 . V_35 . V_38 = V_39 ;
V_14 -> V_27 . V_34 . V_27 . V_35 . V_5 = V_5 ;
V_15 = ( T_2 ) ( 1 << 1 ) ;
V_15 |= ( T_2 ) ( V_4 << 2 ) ;
V_15 |= ( T_2 ) ( V_7 << 6 ) ;
V_14 -> V_27 . V_34 . V_27 . V_35 . V_15 = F_5 ( V_15 ) ;
V_14 -> V_27 . V_34 . V_27 . V_35 . V_8 = F_5 ( V_8 ) ;
V_14 -> V_27 . V_34 . V_27 . V_35 . V_6 =
F_5 ( V_6 << 4 ) ;
F_6 ( V_2 , V_12 , V_4 ) ;
}
void F_7 ( struct V_40 * V_20 , T_1 * V_41 , T_2 V_4 , T_2 V_42 )
{
struct V_1 * V_2 = F_8 ( V_20 ) ;
struct V_9 * V_10 = V_2 -> V_10 ;
struct V_11 * V_12 ;
struct V_43 * V_44 ;
T_2 V_45 = 0 ;
V_12 = F_2 ( sizeof( * V_44 ) + V_10 -> V_16 . V_17 ) ;
if ( ! V_12 )
return;
F_3 ( V_12 , V_10 -> V_16 . V_17 ) ;
V_44 = (struct V_43 * ) F_4 ( V_12 , sizeof( * V_44 ) ) ;
memset ( V_44 , 0 , sizeof( * V_44 ) ) ;
V_44 -> V_31 = F_5 ( V_46 |
V_47 ) ;
memcpy ( V_44 -> V_41 , V_41 , V_18 ) ;
memcpy ( V_44 -> V_48 , V_2 -> V_20 . V_21 , V_18 ) ;
V_45 |= ( T_2 ) V_49 ;
V_45 |= ( T_2 ) V_50 ;
V_45 |= ( T_2 ) ( V_4 << V_51 ) ;
V_44 -> V_52 = F_5 ( V_45 ) ;
V_44 -> V_6 = F_5 ( V_42 ) ;
F_9 ( V_12 ) -> V_53 |= V_54 ;
F_6 ( V_2 , V_12 , V_4 ) ;
}
void F_10 ( struct V_55 * V_56 , int V_4 ,
struct V_57 * V_58 )
{
F_11 ( & V_56 -> V_59 . V_60 ) ;
F_11 ( & V_56 -> V_61 ) ;
F_12 ( V_56 -> V_59 . V_58 [ V_4 ] , V_58 ) ;
}
int F_13 ( struct V_55 * V_56 , T_2 V_4 ,
enum V_62 V_63 ,
bool V_64 )
{
struct V_9 * V_10 = V_56 -> V_10 ;
struct V_57 * V_58 ;
int V_65 ;
F_11 ( & V_56 -> V_59 . V_60 ) ;
F_14 ( & V_56 -> V_61 ) ;
V_58 = F_15 ( V_56 , V_4 ) ;
if ( ! V_58 ) {
F_16 ( & V_56 -> V_61 ) ;
return - V_66 ;
}
if ( F_17 ( V_67 , & V_58 -> V_68 ) ) {
F_16 ( & V_56 -> V_61 ) ;
return - V_69 ;
}
if ( F_17 ( V_70 , & V_58 -> V_68 ) ) {
F_10 ( V_56 , V_4 , NULL ) ;
F_16 ( & V_56 -> V_61 ) ;
F_18 ( V_58 , V_71 ) ;
return 0 ;
}
F_19 ( V_67 , & V_58 -> V_68 ) ;
F_16 ( & V_56 -> V_61 ) ;
#ifdef F_20
F_21 ( V_72 L_1 ,
V_56 -> V_56 . V_21 , V_4 ) ;
#endif
F_22 ( & V_58 -> V_73 ) ;
F_22 ( & V_58 -> V_74 ) ;
F_23 ( V_75 , & V_58 -> V_68 ) ;
F_24 () ;
V_58 -> V_76 = V_63 ;
V_58 -> V_77 = V_64 ;
V_65 = F_25 ( V_10 , V_56 -> V_2 ,
V_78 ,
& V_56 -> V_56 , V_4 , NULL , 0 ) ;
if ( F_26 ( V_65 ) ) {
}
return V_65 ;
}
static void F_27 ( unsigned long V_79 )
{
T_2 V_4 = * ( T_1 * ) V_79 ;
struct V_55 * V_56 = F_28 ( ( void * ) V_79 ,
struct V_55 , V_80 [ V_4 ] ) ;
struct V_57 * V_58 ;
F_29 () ;
V_58 = F_30 ( V_56 -> V_59 . V_58 [ V_4 ] ) ;
if ( ! V_58 ||
F_17 ( V_81 , & V_58 -> V_68 ) ) {
F_31 () ;
#ifdef F_20
F_21 ( V_72 L_2
L_3 ,
V_4 ) ;
#endif
return;
}
#ifdef F_20
F_21 ( V_72 L_4 , V_4 ) ;
#endif
F_32 ( & V_56 -> V_56 , V_4 ) ;
F_31 () ;
}
static inline int F_33 ( int V_4 )
{
return V_82 [ V_4 & 7 ] ;
}
static void F_34 ( T_3 )
ieee80211_stop_queue_agg( struct V_9 * V_10 , int V_4 )
{
int V_83 = F_33 ( V_4 ) ;
if ( F_35 ( & V_10 -> V_84 [ V_83 ] ) == 1 )
F_36 (
& V_10 -> V_16 , V_83 ,
V_85 ) ;
F_37 ( T_3 ) ;
}
static void F_38 ( T_3 )
ieee80211_wake_queue_agg( struct V_9 * V_10 , int V_4 )
{
int V_83 = F_33 ( V_4 ) ;
if ( F_39 ( & V_10 -> V_84 [ V_83 ] ) == 0 )
F_40 (
& V_10 -> V_16 , V_83 ,
V_85 ) ;
F_41 ( T_3 ) ;
}
static void F_34 ( T_3 )
ieee80211_agg_splice_packets( struct V_9 * V_10 ,
struct V_57 * V_58 , T_2 V_4 )
{
int V_83 = F_33 ( V_4 ) ;
unsigned long V_53 ;
F_42 ( V_10 , V_4 ) ;
if ( F_43 ( ! V_58 , L_5
L_6 , V_4 ) )
return;
if ( ! F_44 ( & V_58 -> V_86 ) ) {
F_45 ( & V_10 -> V_87 , V_53 ) ;
F_46 ( & V_58 -> V_86 ,
& V_10 -> V_86 [ V_83 ] ) ;
F_47 ( & V_10 -> V_87 , V_53 ) ;
}
}
static void F_38 ( T_3 )
ieee80211_agg_splice_finish( struct V_9 * V_10 , T_2 V_4 )
{
F_48 ( V_10 , V_4 ) ;
}
void F_49 ( struct V_55 * V_56 , int V_4 )
{
struct V_57 * V_58 ;
struct V_9 * V_10 = V_56 -> V_10 ;
struct V_1 * V_2 = V_56 -> V_2 ;
T_2 V_6 ;
int V_65 ;
V_58 = F_15 ( V_56 , V_4 ) ;
F_23 ( V_70 , & V_58 -> V_68 ) ;
F_24 () ;
V_6 = V_56 -> V_88 [ V_4 ] >> 4 ;
V_65 = F_25 ( V_10 , V_2 , V_89 ,
& V_56 -> V_56 , V_4 , & V_6 , 0 ) ;
if ( V_65 ) {
#ifdef F_20
F_21 ( V_72 L_7
L_8 , V_4 ) ;
#endif
F_14 ( & V_56 -> V_61 ) ;
F_50 ( V_10 , V_58 , V_4 ) ;
F_10 ( V_56 , V_4 , NULL ) ;
F_51 ( V_10 , V_4 ) ;
F_16 ( & V_56 -> V_61 ) ;
F_18 ( V_58 , V_71 ) ;
return;
}
F_52 ( & V_58 -> V_73 , V_90 + V_91 ) ;
#ifdef F_20
F_21 ( V_72 L_9 , V_4 ) ;
#endif
F_14 ( & V_56 -> V_61 ) ;
V_56 -> V_59 . V_92 [ V_4 ] = V_90 ;
V_56 -> V_59 . V_93 [ V_4 ] ++ ;
F_16 ( & V_56 -> V_61 ) ;
F_1 ( V_2 , V_56 -> V_56 . V_21 , V_4 ,
V_58 -> V_5 , V_6 ,
V_10 -> V_16 . V_94 ,
V_58 -> V_8 ) ;
}
static void F_53 ( unsigned long V_79 )
{
T_1 * V_95 = ( T_1 * ) V_79 ;
T_1 * V_96 = V_95 - * V_95 ;
struct V_55 * V_56 = F_28 ( V_96 , struct V_55 ,
V_80 [ 0 ] ) ;
#ifdef F_20
F_21 ( V_72 L_10 , ( T_2 ) * V_95 ) ;
#endif
F_32 ( & V_56 -> V_56 , * V_95 ) ;
}
int F_54 ( struct V_97 * V_98 , T_2 V_4 ,
T_2 V_8 )
{
struct V_55 * V_56 = F_28 ( V_98 , struct V_55 , V_56 ) ;
struct V_1 * V_2 = V_56 -> V_2 ;
struct V_9 * V_10 = V_2 -> V_10 ;
struct V_57 * V_58 ;
int V_65 = 0 ;
F_55 ( V_98 , V_4 ) ;
if ( F_26 ( ! V_10 -> V_99 -> V_100 ) )
return - V_101 ;
if ( ( V_4 >= V_102 ) ||
! ( V_10 -> V_16 . V_53 & V_103 ) ||
( V_10 -> V_16 . V_53 & V_104 ) )
return - V_101 ;
#ifdef F_20
F_21 ( V_72 L_11 ,
V_98 -> V_21 , V_4 ) ;
#endif
if ( V_2 -> V_20 . type != V_26 &&
V_2 -> V_20 . type != V_24 &&
V_2 -> V_20 . type != V_23 &&
V_2 -> V_20 . type != V_22 &&
V_2 -> V_20 . type != V_29 )
return - V_101 ;
if ( F_56 ( V_56 , V_105 ) ) {
#ifdef F_20
F_21 ( V_72 L_12
L_13 ) ;
#endif
return - V_101 ;
}
if ( V_56 -> V_2 -> V_20 . type == V_29 &&
! V_56 -> V_56 . V_106 . V_107 ) {
#ifdef F_20
F_21 ( V_72 L_14
L_15 , V_98 -> V_21 ) ;
#endif
return - V_101 ;
}
F_14 ( & V_56 -> V_61 ) ;
if ( V_56 -> V_59 . V_93 [ V_4 ] > V_108 ) {
V_65 = - V_109 ;
goto V_110;
}
if ( V_56 -> V_59 . V_93 [ V_4 ] > V_111 &&
F_57 ( V_90 , V_56 -> V_59 . V_92 [ V_4 ] +
V_112 ) ) {
#ifdef F_20
F_21 ( V_72 L_16
L_17
L_18 ,
V_56 -> V_59 . V_93 [ V_4 ] , V_4 ) ;
#endif
V_65 = - V_109 ;
goto V_110;
}
V_58 = F_15 ( V_56 , V_4 ) ;
if ( V_58 || V_56 -> V_59 . V_113 [ V_4 ] ) {
#ifdef F_20
F_21 ( V_72 L_19
L_20 , V_4 ) ;
#endif
V_65 = - V_114 ;
goto V_110;
}
V_58 = F_58 ( sizeof( struct V_57 ) , V_115 ) ;
if ( ! V_58 ) {
V_65 = - V_116 ;
goto V_110;
}
F_59 ( & V_58 -> V_86 ) ;
F_60 ( V_70 , & V_58 -> V_68 ) ;
V_58 -> V_8 = V_8 ;
V_58 -> V_73 . V_117 = F_27 ;
V_58 -> V_73 . V_79 = ( unsigned long ) & V_56 -> V_80 [ V_4 ] ;
F_61 ( & V_58 -> V_73 ) ;
V_58 -> V_74 . V_117 = F_53 ;
V_58 -> V_74 . V_79 = ( unsigned long ) & V_56 -> V_80 [ V_4 ] ;
F_61 ( & V_58 -> V_74 ) ;
V_56 -> V_59 . V_118 ++ ;
V_58 -> V_5 = V_56 -> V_59 . V_118 ;
V_56 -> V_59 . V_113 [ V_4 ] = V_58 ;
F_62 ( & V_10 -> V_16 , & V_56 -> V_59 . V_119 ) ;
V_110:
F_16 ( & V_56 -> V_61 ) ;
return V_65 ;
}
static void F_63 ( struct V_9 * V_10 ,
struct V_55 * V_56 , T_2 V_4 )
{
struct V_57 * V_58 ;
F_11 ( & V_56 -> V_59 . V_60 ) ;
V_58 = F_15 ( V_56 , V_4 ) ;
#ifdef F_20
F_21 ( V_72 L_21 , V_4 ) ;
#endif
F_25 ( V_10 , V_56 -> V_2 ,
V_120 ,
& V_56 -> V_56 , V_4 , NULL , V_58 -> V_121 ) ;
F_14 ( & V_56 -> V_61 ) ;
F_50 ( V_10 , V_58 , V_4 ) ;
F_19 ( V_75 , & V_58 -> V_68 ) ;
F_51 ( V_10 , V_4 ) ;
F_16 ( & V_56 -> V_61 ) ;
}
void F_64 ( struct V_40 * V_20 , T_1 * V_41 , T_2 V_4 )
{
struct V_1 * V_2 = F_8 ( V_20 ) ;
struct V_9 * V_10 = V_2 -> V_10 ;
struct V_55 * V_56 ;
struct V_57 * V_58 ;
F_65 ( V_2 , V_41 , V_4 ) ;
if ( V_4 >= V_102 ) {
#ifdef F_20
F_21 ( V_72 L_22 ,
V_4 , V_102 ) ;
#endif
return;
}
F_66 ( & V_10 -> V_122 ) ;
V_56 = F_67 ( V_2 , V_41 ) ;
if ( ! V_56 ) {
F_68 ( & V_10 -> V_122 ) ;
#ifdef F_20
F_21 ( V_72 L_23 , V_41 ) ;
#endif
return;
}
F_66 ( & V_56 -> V_59 . V_60 ) ;
V_58 = F_15 ( V_56 , V_4 ) ;
if ( F_26 ( ! V_58 ) ) {
#ifdef F_20
F_21 ( V_72 L_24 ) ;
#endif
goto V_123;
}
if ( F_26 ( F_69 ( V_124 , & V_58 -> V_68 ) ) )
goto V_123;
if ( F_17 ( V_81 , & V_58 -> V_68 ) )
F_63 ( V_10 , V_56 , V_4 ) ;
V_123:
F_68 ( & V_56 -> V_59 . V_60 ) ;
F_68 ( & V_10 -> V_122 ) ;
}
void F_70 ( struct V_40 * V_20 ,
const T_1 * V_41 , T_2 V_4 )
{
struct V_1 * V_2 = F_8 ( V_20 ) ;
struct V_9 * V_10 = V_2 -> V_10 ;
struct V_125 * V_126 ;
struct V_11 * V_12 = F_2 ( 0 ) ;
if ( F_71 ( ! V_12 ) )
return;
V_126 = (struct V_125 * ) & V_12 -> V_127 ;
memcpy ( & V_126 -> V_41 , V_41 , V_18 ) ;
V_126 -> V_4 = V_4 ;
V_12 -> V_128 = V_129 ;
F_72 ( & V_2 -> V_130 , V_12 ) ;
F_62 ( & V_10 -> V_16 , & V_2 -> V_119 ) ;
}
int F_73 ( struct V_55 * V_56 , T_2 V_4 ,
enum V_62 V_63 ,
bool V_64 )
{
int V_65 ;
F_66 ( & V_56 -> V_59 . V_60 ) ;
V_65 = F_13 ( V_56 , V_4 , V_63 , V_64 ) ;
F_68 ( & V_56 -> V_59 . V_60 ) ;
return V_65 ;
}
int F_32 ( struct V_97 * V_98 , T_2 V_4 )
{
struct V_55 * V_56 = F_28 ( V_98 , struct V_55 , V_56 ) ;
struct V_1 * V_2 = V_56 -> V_2 ;
struct V_9 * V_10 = V_2 -> V_10 ;
struct V_57 * V_58 ;
int V_65 = 0 ;
F_74 ( V_98 , V_4 ) ;
if ( ! V_10 -> V_99 -> V_100 )
return - V_101 ;
if ( V_4 >= V_102 )
return - V_101 ;
F_14 ( & V_56 -> V_61 ) ;
V_58 = F_15 ( V_56 , V_4 ) ;
if ( ! V_58 ) {
V_65 = - V_66 ;
goto V_123;
}
if ( F_17 ( V_67 , & V_58 -> V_68 ) ) {
V_65 = 0 ;
goto V_123;
}
F_19 ( V_131 , & V_58 -> V_68 ) ;
F_62 ( & V_10 -> V_16 , & V_56 -> V_59 . V_119 ) ;
V_123:
F_16 ( & V_56 -> V_61 ) ;
return V_65 ;
}
void F_75 ( struct V_40 * V_20 , T_1 * V_41 , T_1 V_4 )
{
struct V_1 * V_2 = F_8 ( V_20 ) ;
struct V_9 * V_10 = V_2 -> V_10 ;
struct V_55 * V_56 ;
struct V_57 * V_58 ;
F_76 ( V_2 , V_41 , V_4 ) ;
if ( V_4 >= V_102 ) {
#ifdef F_20
F_21 ( V_72 L_22 ,
V_4 , V_102 ) ;
#endif
return;
}
#ifdef F_20
F_21 ( V_72 L_25 ,
V_41 , V_4 ) ;
#endif
F_66 ( & V_10 -> V_122 ) ;
V_56 = F_67 ( V_2 , V_41 ) ;
if ( ! V_56 ) {
#ifdef F_20
F_21 ( V_72 L_23 , V_41 ) ;
#endif
goto V_123;
}
F_66 ( & V_56 -> V_59 . V_60 ) ;
F_14 ( & V_56 -> V_61 ) ;
V_58 = F_15 ( V_56 , V_4 ) ;
if ( ! V_58 || ! F_17 ( V_67 , & V_58 -> V_68 ) ) {
#ifdef F_20
F_21 ( V_72 L_26 ) ;
#endif
goto V_132;
}
if ( V_58 -> V_76 == V_133 && V_58 -> V_77 )
F_77 ( V_56 -> V_2 , V_41 , V_4 ,
V_133 , V_134 ) ;
F_50 ( V_10 , V_58 , V_4 ) ;
F_10 ( V_56 , V_4 , NULL ) ;
F_51 ( V_10 , V_4 ) ;
F_18 ( V_58 , V_71 ) ;
V_132:
F_16 ( & V_56 -> V_61 ) ;
F_68 ( & V_56 -> V_59 . V_60 ) ;
V_123:
F_68 ( & V_10 -> V_122 ) ;
}
void F_78 ( struct V_40 * V_20 ,
const T_1 * V_41 , T_2 V_4 )
{
struct V_1 * V_2 = F_8 ( V_20 ) ;
struct V_9 * V_10 = V_2 -> V_10 ;
struct V_125 * V_126 ;
struct V_11 * V_12 = F_2 ( 0 ) ;
if ( F_71 ( ! V_12 ) )
return;
V_126 = (struct V_125 * ) & V_12 -> V_127 ;
memcpy ( & V_126 -> V_41 , V_41 , V_18 ) ;
V_126 -> V_4 = V_4 ;
V_12 -> V_128 = V_135 ;
F_72 ( & V_2 -> V_130 , V_12 ) ;
F_62 ( & V_10 -> V_16 , & V_2 -> V_119 ) ;
}
void F_79 ( struct V_9 * V_10 ,
struct V_55 * V_56 ,
struct V_13 * V_14 ,
T_4 V_136 )
{
struct V_57 * V_58 ;
T_2 V_15 , V_4 ;
T_1 V_121 ;
V_15 = F_80 ( V_14 -> V_27 . V_34 . V_27 . V_137 . V_15 ) ;
V_4 = ( V_15 & V_138 ) >> 2 ;
V_121 = ( V_15 & V_139 ) >> 6 ;
F_66 ( & V_56 -> V_59 . V_60 ) ;
V_58 = F_15 ( V_56 , V_4 ) ;
if ( ! V_58 )
goto V_140;
if ( V_14 -> V_27 . V_34 . V_27 . V_137 . V_5 != V_58 -> V_5 ) {
#ifdef F_20
F_21 ( V_72 L_27 , V_4 ) ;
#endif
goto V_140;
}
F_22 ( & V_58 -> V_73 ) ;
#ifdef F_20
F_21 ( V_72 L_28 , V_4 ) ;
#endif
if ( F_17 ( V_131 , & V_58 -> V_68 ) ||
F_17 ( V_67 , & V_58 -> V_68 ) ) {
#ifdef F_20
F_21 ( V_72
L_29 ,
V_4 ) ;
#endif
goto V_140;
}
if ( F_80 ( V_14 -> V_27 . V_34 . V_27 . V_137 . V_141 )
== V_142 && V_121 ) {
if ( F_69 ( V_81 ,
& V_58 -> V_68 ) ) {
goto V_140;
}
V_58 -> V_121 = V_121 ;
if ( F_17 ( V_124 , & V_58 -> V_68 ) )
F_63 ( V_10 , V_56 , V_4 ) ;
V_56 -> V_59 . V_93 [ V_4 ] = 0 ;
if ( V_58 -> V_8 )
F_52 ( & V_58 -> V_74 ,
F_81 ( V_58 -> V_8 ) ) ;
} else {
F_13 ( V_56 , V_4 , V_133 ,
true ) ;
}
V_140:
F_68 ( & V_56 -> V_59 . V_60 ) ;
}
