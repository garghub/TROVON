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
V_2 -> V_20 . type == V_23 )
memcpy ( V_14 -> V_24 , V_2 -> V_20 . V_21 , V_18 ) ;
else if ( V_2 -> V_20 . type == V_25 )
memcpy ( V_14 -> V_24 , V_2 -> V_26 . V_27 . V_24 , V_18 ) ;
V_14 -> V_28 = F_5 ( V_29 |
V_30 ) ;
F_4 ( V_12 , 1 + sizeof( V_14 -> V_26 . V_31 . V_26 . V_32 ) ) ;
V_14 -> V_26 . V_31 . V_33 = V_34 ;
V_14 -> V_26 . V_31 . V_26 . V_32 . V_35 = V_36 ;
V_14 -> V_26 . V_31 . V_26 . V_32 . V_5 = V_5 ;
V_15 = ( T_2 ) ( 1 << 1 ) ;
V_15 |= ( T_2 ) ( V_4 << 2 ) ;
V_15 |= ( T_2 ) ( V_7 << 6 ) ;
V_14 -> V_26 . V_31 . V_26 . V_32 . V_15 = F_5 ( V_15 ) ;
V_14 -> V_26 . V_31 . V_26 . V_32 . V_8 = F_5 ( V_8 ) ;
V_14 -> V_26 . V_31 . V_26 . V_32 . V_6 =
F_5 ( V_6 << 4 ) ;
F_6 ( V_2 , V_12 ) ;
}
void F_7 ( struct V_37 * V_20 , T_1 * V_38 , T_2 V_4 , T_2 V_39 )
{
struct V_1 * V_2 = F_8 ( V_20 ) ;
struct V_9 * V_10 = V_2 -> V_10 ;
struct V_11 * V_12 ;
struct V_40 * V_41 ;
T_2 V_42 = 0 ;
V_12 = F_2 ( sizeof( * V_41 ) + V_10 -> V_16 . V_17 ) ;
if ( ! V_12 )
return;
F_3 ( V_12 , V_10 -> V_16 . V_17 ) ;
V_41 = (struct V_40 * ) F_4 ( V_12 , sizeof( * V_41 ) ) ;
memset ( V_41 , 0 , sizeof( * V_41 ) ) ;
V_41 -> V_28 = F_5 ( V_43 |
V_44 ) ;
memcpy ( V_41 -> V_38 , V_38 , V_18 ) ;
memcpy ( V_41 -> V_45 , V_2 -> V_20 . V_21 , V_18 ) ;
V_42 |= ( T_2 ) V_46 ;
V_42 |= ( T_2 ) V_47 ;
V_42 |= ( T_2 ) ( V_4 << V_48 ) ;
V_41 -> V_49 = F_5 ( V_42 ) ;
V_41 -> V_6 = F_5 ( V_39 ) ;
F_9 ( V_12 ) -> V_50 |= V_51 ;
F_6 ( V_2 , V_12 ) ;
}
void F_10 ( struct V_52 * V_53 , int V_4 ,
struct V_54 * V_55 )
{
F_11 ( & V_53 -> V_56 . V_57 ) ;
F_11 ( & V_53 -> V_58 ) ;
F_12 ( V_53 -> V_56 . V_55 [ V_4 ] , V_55 ) ;
}
int F_13 ( struct V_52 * V_53 , T_2 V_4 ,
enum V_59 V_60 ,
bool V_61 )
{
struct V_9 * V_10 = V_53 -> V_10 ;
struct V_54 * V_55 ;
int V_62 ;
F_11 ( & V_53 -> V_56 . V_57 ) ;
F_14 ( & V_53 -> V_58 ) ;
V_55 = F_15 ( V_53 , V_4 ) ;
if ( ! V_55 ) {
F_16 ( & V_53 -> V_58 ) ;
return - V_63 ;
}
if ( F_17 ( V_64 , & V_55 -> V_65 ) ) {
F_16 ( & V_53 -> V_58 ) ;
return - V_66 ;
}
if ( F_17 ( V_67 , & V_55 -> V_65 ) ) {
F_10 ( V_53 , V_4 , NULL ) ;
F_16 ( & V_53 -> V_58 ) ;
F_18 ( V_55 , V_68 ) ;
return 0 ;
}
F_19 ( V_64 , & V_55 -> V_65 ) ;
F_16 ( & V_53 -> V_58 ) ;
#ifdef F_20
F_21 ( V_69 L_1 ,
V_53 -> V_53 . V_21 , V_4 ) ;
#endif
F_22 ( & V_55 -> V_70 ) ;
F_23 ( V_71 , & V_55 -> V_65 ) ;
F_24 () ;
V_55 -> V_72 = V_60 ;
V_55 -> V_73 = V_61 ;
V_62 = F_25 ( V_10 , V_53 -> V_2 ,
V_74 ,
& V_53 -> V_53 , V_4 , NULL , 0 ) ;
if ( F_26 ( V_62 ) ) {
}
return V_62 ;
}
static void F_27 ( unsigned long V_75 )
{
T_2 V_4 = * ( T_1 * ) V_75 ;
struct V_52 * V_53 = F_28 ( ( void * ) V_75 ,
struct V_52 , V_76 [ V_4 ] ) ;
struct V_54 * V_55 ;
F_29 () ;
V_55 = F_30 ( V_53 -> V_56 . V_55 [ V_4 ] ) ;
if ( ! V_55 ||
F_17 ( V_77 , & V_55 -> V_65 ) ) {
F_31 () ;
#ifdef F_20
F_21 ( V_69 L_2
L_3 ,
V_4 ) ;
#endif
return;
}
#ifdef F_20
F_21 ( V_69 L_4 , V_4 ) ;
#endif
F_32 ( & V_53 -> V_53 , V_4 ) ;
F_31 () ;
}
static inline int F_33 ( int V_4 )
{
return V_78 [ V_4 & 7 ] ;
}
static void F_34 ( T_3 )
ieee80211_stop_queue_agg( struct V_9 * V_10 , int V_4 )
{
int V_79 = F_33 ( V_4 ) ;
if ( F_35 ( & V_10 -> V_80 [ V_79 ] ) == 1 )
F_36 (
& V_10 -> V_16 , V_79 ,
V_81 ) ;
F_37 ( T_3 ) ;
}
static void F_38 ( T_3 )
ieee80211_wake_queue_agg( struct V_9 * V_10 , int V_4 )
{
int V_79 = F_33 ( V_4 ) ;
if ( F_39 ( & V_10 -> V_80 [ V_79 ] ) == 0 )
F_40 (
& V_10 -> V_16 , V_79 ,
V_81 ) ;
F_41 ( T_3 ) ;
}
static void F_34 ( T_3 )
ieee80211_agg_splice_packets( struct V_9 * V_10 ,
struct V_54 * V_55 , T_2 V_4 )
{
int V_79 = F_33 ( V_4 ) ;
unsigned long V_50 ;
F_42 ( V_10 , V_4 ) ;
if ( F_43 ( ! V_55 , L_5
L_6 , V_4 ) )
return;
if ( ! F_44 ( & V_55 -> V_82 ) ) {
F_45 ( & V_10 -> V_83 , V_50 ) ;
F_46 ( & V_55 -> V_82 ,
& V_10 -> V_82 [ V_79 ] ) ;
F_47 ( & V_10 -> V_83 , V_50 ) ;
}
}
static void F_38 ( T_3 )
ieee80211_agg_splice_finish( struct V_9 * V_10 , T_2 V_4 )
{
F_48 ( V_10 , V_4 ) ;
}
void F_49 ( struct V_52 * V_53 , int V_4 )
{
struct V_54 * V_55 ;
struct V_9 * V_10 = V_53 -> V_10 ;
struct V_1 * V_2 = V_53 -> V_2 ;
T_2 V_6 ;
int V_62 ;
V_55 = F_15 ( V_53 , V_4 ) ;
F_23 ( V_67 , & V_55 -> V_65 ) ;
F_24 () ;
V_6 = V_53 -> V_84 [ V_4 ] >> 4 ;
V_62 = F_25 ( V_10 , V_2 , V_85 ,
& V_53 -> V_53 , V_4 , & V_6 , 0 ) ;
if ( V_62 ) {
#ifdef F_20
F_21 ( V_69 L_7
L_8 , V_4 ) ;
#endif
F_14 ( & V_53 -> V_58 ) ;
F_50 ( V_10 , V_55 , V_4 ) ;
F_10 ( V_53 , V_4 , NULL ) ;
F_51 ( V_10 , V_4 ) ;
F_16 ( & V_53 -> V_58 ) ;
F_18 ( V_55 , V_68 ) ;
return;
}
F_52 ( & V_55 -> V_70 , V_86 + V_87 ) ;
#ifdef F_20
F_21 ( V_69 L_9 , V_4 ) ;
#endif
F_14 ( & V_53 -> V_58 ) ;
V_53 -> V_56 . V_88 [ V_4 ] ++ ;
F_16 ( & V_53 -> V_58 ) ;
F_1 ( V_2 , V_53 -> V_53 . V_21 , V_4 ,
V_55 -> V_5 , V_6 ,
V_10 -> V_16 . V_89 ,
V_55 -> V_8 ) ;
}
int F_53 ( struct V_90 * V_91 , T_2 V_4 ,
T_2 V_8 )
{
struct V_52 * V_53 = F_28 ( V_91 , struct V_52 , V_53 ) ;
struct V_1 * V_2 = V_53 -> V_2 ;
struct V_9 * V_10 = V_2 -> V_10 ;
struct V_54 * V_55 ;
int V_62 = 0 ;
F_54 ( V_91 , V_4 ) ;
if ( F_26 ( ! V_10 -> V_92 -> V_93 ) )
return - V_94 ;
if ( ( V_4 >= V_95 ) ||
! ( V_10 -> V_16 . V_50 & V_96 ) ||
( V_10 -> V_16 . V_50 & V_97 ) )
return - V_94 ;
#ifdef F_20
F_21 ( V_69 L_10 ,
V_91 -> V_21 , V_4 ) ;
#endif
if ( V_2 -> V_20 . type != V_25 &&
V_2 -> V_20 . type != V_23 &&
V_2 -> V_20 . type != V_22 )
return - V_94 ;
if ( F_55 ( V_53 , V_98 ) ) {
#ifdef F_20
F_21 ( V_69 L_11
L_12 ) ;
#endif
return - V_94 ;
}
F_14 ( & V_53 -> V_58 ) ;
if ( V_53 -> V_56 . V_88 [ V_4 ] > V_99 ) {
V_62 = - V_100 ;
goto V_101;
}
V_55 = F_15 ( V_53 , V_4 ) ;
if ( V_55 || V_53 -> V_56 . V_102 [ V_4 ] ) {
#ifdef F_20
F_21 ( V_69 L_13
L_14 , V_4 ) ;
#endif
V_62 = - V_103 ;
goto V_101;
}
V_55 = F_56 ( sizeof( struct V_54 ) , V_104 ) ;
if ( ! V_55 ) {
V_62 = - V_105 ;
goto V_101;
}
F_57 ( & V_55 -> V_82 ) ;
F_58 ( V_67 , & V_55 -> V_65 ) ;
V_55 -> V_8 = V_8 ;
V_55 -> V_70 . V_106 = F_27 ;
V_55 -> V_70 . V_75 = ( unsigned long ) & V_53 -> V_76 [ V_4 ] ;
F_59 ( & V_55 -> V_70 ) ;
V_53 -> V_56 . V_107 ++ ;
V_55 -> V_5 = V_53 -> V_56 . V_107 ;
V_53 -> V_56 . V_102 [ V_4 ] = V_55 ;
F_60 ( & V_10 -> V_16 , & V_53 -> V_56 . V_108 ) ;
V_101:
F_16 ( & V_53 -> V_58 ) ;
return V_62 ;
}
static void F_61 ( struct V_9 * V_10 ,
struct V_52 * V_53 , T_2 V_4 )
{
struct V_54 * V_55 ;
F_11 ( & V_53 -> V_56 . V_57 ) ;
V_55 = F_15 ( V_53 , V_4 ) ;
#ifdef F_20
F_21 ( V_69 L_15 , V_4 ) ;
#endif
F_25 ( V_10 , V_53 -> V_2 ,
V_109 ,
& V_53 -> V_53 , V_4 , NULL , V_55 -> V_110 ) ;
F_14 ( & V_53 -> V_58 ) ;
F_50 ( V_10 , V_55 , V_4 ) ;
F_19 ( V_71 , & V_55 -> V_65 ) ;
F_51 ( V_10 , V_4 ) ;
F_16 ( & V_53 -> V_58 ) ;
}
void F_62 ( struct V_37 * V_20 , T_1 * V_38 , T_2 V_4 )
{
struct V_1 * V_2 = F_8 ( V_20 ) ;
struct V_9 * V_10 = V_2 -> V_10 ;
struct V_52 * V_53 ;
struct V_54 * V_55 ;
F_63 ( V_2 , V_38 , V_4 ) ;
if ( V_4 >= V_95 ) {
#ifdef F_20
F_21 ( V_69 L_16 ,
V_4 , V_95 ) ;
#endif
return;
}
F_64 ( & V_10 -> V_111 ) ;
V_53 = F_65 ( V_2 , V_38 ) ;
if ( ! V_53 ) {
F_66 ( & V_10 -> V_111 ) ;
#ifdef F_20
F_21 ( V_69 L_17 , V_38 ) ;
#endif
return;
}
F_64 ( & V_53 -> V_56 . V_57 ) ;
V_55 = F_15 ( V_53 , V_4 ) ;
if ( F_26 ( ! V_55 ) ) {
#ifdef F_20
F_21 ( V_69 L_18 ) ;
#endif
goto V_112;
}
if ( F_26 ( F_67 ( V_113 , & V_55 -> V_65 ) ) )
goto V_112;
if ( F_17 ( V_77 , & V_55 -> V_65 ) )
F_61 ( V_10 , V_53 , V_4 ) ;
V_112:
F_66 ( & V_53 -> V_56 . V_57 ) ;
F_66 ( & V_10 -> V_111 ) ;
}
void F_68 ( struct V_37 * V_20 ,
const T_1 * V_38 , T_2 V_4 )
{
struct V_1 * V_2 = F_8 ( V_20 ) ;
struct V_9 * V_10 = V_2 -> V_10 ;
struct V_114 * V_115 ;
struct V_11 * V_12 = F_2 ( 0 ) ;
if ( F_69 ( ! V_12 ) )
return;
V_115 = (struct V_114 * ) & V_12 -> V_116 ;
memcpy ( & V_115 -> V_38 , V_38 , V_18 ) ;
V_115 -> V_4 = V_4 ;
V_12 -> V_117 = V_118 ;
F_70 ( & V_2 -> V_119 , V_12 ) ;
F_60 ( & V_10 -> V_16 , & V_2 -> V_108 ) ;
}
int F_71 ( struct V_52 * V_53 , T_2 V_4 ,
enum V_59 V_60 ,
bool V_61 )
{
int V_62 ;
F_64 ( & V_53 -> V_56 . V_57 ) ;
V_62 = F_13 ( V_53 , V_4 , V_60 , V_61 ) ;
F_66 ( & V_53 -> V_56 . V_57 ) ;
return V_62 ;
}
int F_32 ( struct V_90 * V_91 , T_2 V_4 )
{
struct V_52 * V_53 = F_28 ( V_91 , struct V_52 , V_53 ) ;
struct V_1 * V_2 = V_53 -> V_2 ;
struct V_9 * V_10 = V_2 -> V_10 ;
struct V_54 * V_55 ;
int V_62 = 0 ;
F_72 ( V_91 , V_4 ) ;
if ( ! V_10 -> V_92 -> V_93 )
return - V_94 ;
if ( V_4 >= V_95 )
return - V_94 ;
F_14 ( & V_53 -> V_58 ) ;
V_55 = F_15 ( V_53 , V_4 ) ;
if ( ! V_55 ) {
V_62 = - V_63 ;
goto V_112;
}
if ( F_17 ( V_64 , & V_55 -> V_65 ) ) {
V_62 = 0 ;
goto V_112;
}
F_19 ( V_120 , & V_55 -> V_65 ) ;
F_60 ( & V_10 -> V_16 , & V_53 -> V_56 . V_108 ) ;
V_112:
F_16 ( & V_53 -> V_58 ) ;
return V_62 ;
}
void F_73 ( struct V_37 * V_20 , T_1 * V_38 , T_1 V_4 )
{
struct V_1 * V_2 = F_8 ( V_20 ) ;
struct V_9 * V_10 = V_2 -> V_10 ;
struct V_52 * V_53 ;
struct V_54 * V_55 ;
F_74 ( V_2 , V_38 , V_4 ) ;
if ( V_4 >= V_95 ) {
#ifdef F_20
F_21 ( V_69 L_16 ,
V_4 , V_95 ) ;
#endif
return;
}
#ifdef F_20
F_21 ( V_69 L_19 ,
V_38 , V_4 ) ;
#endif
F_64 ( & V_10 -> V_111 ) ;
V_53 = F_65 ( V_2 , V_38 ) ;
if ( ! V_53 ) {
#ifdef F_20
F_21 ( V_69 L_17 , V_38 ) ;
#endif
goto V_112;
}
F_64 ( & V_53 -> V_56 . V_57 ) ;
F_14 ( & V_53 -> V_58 ) ;
V_55 = F_15 ( V_53 , V_4 ) ;
if ( ! V_55 || ! F_17 ( V_64 , & V_55 -> V_65 ) ) {
#ifdef F_20
F_21 ( V_69 L_20 ) ;
#endif
goto V_121;
}
if ( V_55 -> V_72 == V_122 && V_55 -> V_73 )
F_75 ( V_53 -> V_2 , V_38 , V_4 ,
V_122 , V_123 ) ;
F_50 ( V_10 , V_55 , V_4 ) ;
F_10 ( V_53 , V_4 , NULL ) ;
F_51 ( V_10 , V_4 ) ;
F_18 ( V_55 , V_68 ) ;
V_121:
F_16 ( & V_53 -> V_58 ) ;
F_66 ( & V_53 -> V_56 . V_57 ) ;
V_112:
F_66 ( & V_10 -> V_111 ) ;
}
void F_76 ( struct V_37 * V_20 ,
const T_1 * V_38 , T_2 V_4 )
{
struct V_1 * V_2 = F_8 ( V_20 ) ;
struct V_9 * V_10 = V_2 -> V_10 ;
struct V_114 * V_115 ;
struct V_11 * V_12 = F_2 ( 0 ) ;
if ( F_69 ( ! V_12 ) )
return;
V_115 = (struct V_114 * ) & V_12 -> V_116 ;
memcpy ( & V_115 -> V_38 , V_38 , V_18 ) ;
V_115 -> V_4 = V_4 ;
V_12 -> V_117 = V_124 ;
F_70 ( & V_2 -> V_119 , V_12 ) ;
F_60 ( & V_10 -> V_16 , & V_2 -> V_108 ) ;
}
void F_77 ( struct V_9 * V_10 ,
struct V_52 * V_53 ,
struct V_13 * V_14 ,
T_4 V_125 )
{
struct V_54 * V_55 ;
T_2 V_15 , V_4 ;
T_1 V_110 ;
V_15 = F_78 ( V_14 -> V_26 . V_31 . V_26 . V_126 . V_15 ) ;
V_4 = ( V_15 & V_127 ) >> 2 ;
V_110 = ( V_15 & V_128 ) >> 6 ;
F_64 ( & V_53 -> V_56 . V_57 ) ;
V_55 = F_15 ( V_53 , V_4 ) ;
if ( ! V_55 )
goto V_129;
if ( V_14 -> V_26 . V_31 . V_26 . V_126 . V_5 != V_55 -> V_5 ) {
#ifdef F_20
F_21 ( V_69 L_21 , V_4 ) ;
#endif
goto V_129;
}
F_22 ( & V_55 -> V_70 ) ;
#ifdef F_20
F_21 ( V_69 L_22 , V_4 ) ;
#endif
if ( F_17 ( V_120 , & V_55 -> V_65 ) ||
F_17 ( V_64 , & V_55 -> V_65 ) ) {
#ifdef F_20
F_21 ( V_69
L_23 ,
V_4 ) ;
#endif
goto V_129;
}
if ( F_78 ( V_14 -> V_26 . V_31 . V_26 . V_126 . V_130 )
== V_131 && V_110 ) {
if ( F_67 ( V_77 ,
& V_55 -> V_65 ) ) {
goto V_129;
}
V_55 -> V_110 = V_110 ;
if ( F_17 ( V_113 , & V_55 -> V_65 ) )
F_61 ( V_10 , V_53 , V_4 ) ;
V_53 -> V_56 . V_88 [ V_4 ] = 0 ;
} else {
F_13 ( V_53 , V_4 , V_122 ,
true ) ;
}
V_129:
F_66 ( & V_53 -> V_56 . V_57 ) ;
}
