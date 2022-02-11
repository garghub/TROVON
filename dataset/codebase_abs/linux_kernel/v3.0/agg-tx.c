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
if ( ! V_12 ) {
F_3 ( V_18 L_1
L_2 , V_2 -> V_19 ) ;
return;
}
F_4 ( V_12 , V_10 -> V_16 . V_17 ) ;
V_14 = (struct V_13 * ) F_5 ( V_12 , 24 ) ;
memset ( V_14 , 0 , 24 ) ;
memcpy ( V_14 -> V_3 , V_3 , V_20 ) ;
memcpy ( V_14 -> V_21 , V_2 -> V_22 . V_23 , V_20 ) ;
if ( V_2 -> V_22 . type == V_24 ||
V_2 -> V_22 . type == V_25 )
memcpy ( V_14 -> V_26 , V_2 -> V_22 . V_23 , V_20 ) ;
else if ( V_2 -> V_22 . type == V_27 )
memcpy ( V_14 -> V_26 , V_2 -> V_28 . V_29 . V_26 , V_20 ) ;
V_14 -> V_30 = F_6 ( V_31 |
V_32 ) ;
F_5 ( V_12 , 1 + sizeof( V_14 -> V_28 . V_33 . V_28 . V_34 ) ) ;
V_14 -> V_28 . V_33 . V_35 = V_36 ;
V_14 -> V_28 . V_33 . V_28 . V_34 . V_37 = V_38 ;
V_14 -> V_28 . V_33 . V_28 . V_34 . V_5 = V_5 ;
V_15 = ( T_2 ) ( 1 << 1 ) ;
V_15 |= ( T_2 ) ( V_4 << 2 ) ;
V_15 |= ( T_2 ) ( V_7 << 6 ) ;
V_14 -> V_28 . V_33 . V_28 . V_34 . V_15 = F_6 ( V_15 ) ;
V_14 -> V_28 . V_33 . V_28 . V_34 . V_8 = F_6 ( V_8 ) ;
V_14 -> V_28 . V_33 . V_28 . V_34 . V_6 =
F_6 ( V_6 << 4 ) ;
F_7 ( V_2 , V_12 ) ;
}
void F_8 ( struct V_1 * V_2 , T_1 * V_39 , T_2 V_4 , T_2 V_40 )
{
struct V_9 * V_10 = V_2 -> V_10 ;
struct V_11 * V_12 ;
struct V_41 * V_42 ;
T_2 V_43 = 0 ;
V_12 = F_2 ( sizeof( * V_42 ) + V_10 -> V_16 . V_17 ) ;
if ( ! V_12 ) {
F_3 ( V_18 L_3
L_4 , V_2 -> V_19 ) ;
return;
}
F_4 ( V_12 , V_10 -> V_16 . V_17 ) ;
V_42 = (struct V_41 * ) F_5 ( V_12 , sizeof( * V_42 ) ) ;
memset ( V_42 , 0 , sizeof( * V_42 ) ) ;
V_42 -> V_30 = F_6 ( V_44 |
V_45 ) ;
memcpy ( V_42 -> V_39 , V_39 , V_20 ) ;
memcpy ( V_42 -> V_46 , V_2 -> V_22 . V_23 , V_20 ) ;
V_43 |= ( T_2 ) V_47 ;
V_43 |= ( T_2 ) V_48 ;
V_43 |= ( T_2 ) ( V_4 << 12 ) ;
V_42 -> V_49 = F_6 ( V_43 ) ;
V_42 -> V_6 = F_6 ( V_40 ) ;
F_9 ( V_12 ) -> V_50 |= V_51 ;
F_7 ( V_2 , V_12 ) ;
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
F_10 ( V_53 , V_4 , NULL ) ;
F_16 ( & V_53 -> V_58 ) ;
F_18 ( V_55 , V_66 ) ;
return 0 ;
}
F_16 ( & V_53 -> V_58 ) ;
#ifdef F_19
F_3 ( V_67 L_5 ,
V_53 -> V_53 . V_23 , V_4 ) ;
#endif
F_20 ( V_68 , & V_55 -> V_65 ) ;
F_21 ( & V_55 -> V_69 ) ;
F_22 ( V_70 , & V_55 -> V_65 ) ;
V_55 -> V_71 = V_60 ;
V_55 -> V_72 = V_61 ;
V_62 = F_23 ( V_10 , V_53 -> V_2 ,
V_73 ,
& V_53 -> V_53 , V_4 , NULL , 0 ) ;
if ( F_24 ( V_62 ) ) {
}
return V_62 ;
}
static void F_25 ( unsigned long V_74 )
{
T_2 V_4 = * ( T_1 * ) V_74 ;
struct V_52 * V_53 = F_26 ( ( void * ) V_74 ,
struct V_52 , V_75 [ V_4 ] ) ;
struct V_54 * V_55 ;
F_27 () ;
V_55 = F_28 ( V_53 -> V_56 . V_55 [ V_4 ] ) ;
if ( ! V_55 ||
F_17 ( V_76 , & V_55 -> V_65 ) ) {
F_29 () ;
#ifdef F_19
F_3 ( V_67 L_6
L_7 ,
V_4 ) ;
#endif
return;
}
#ifdef F_19
F_3 ( V_67 L_8 , V_4 ) ;
#endif
F_30 ( & V_53 -> V_53 , V_4 ) ;
F_29 () ;
}
static inline int F_31 ( int V_4 )
{
return V_77 [ V_4 & 7 ] ;
}
static void F_32 ( T_3 )
ieee80211_stop_queue_agg( struct V_9 * V_10 , int V_4 )
{
int V_78 = F_31 ( V_4 ) ;
if ( F_33 ( & V_10 -> V_79 [ V_78 ] ) == 1 )
F_34 (
& V_10 -> V_16 , V_78 ,
V_80 ) ;
F_35 ( T_3 ) ;
}
static void F_36 ( T_3 )
ieee80211_wake_queue_agg( struct V_9 * V_10 , int V_4 )
{
int V_78 = F_31 ( V_4 ) ;
if ( F_37 ( & V_10 -> V_79 [ V_78 ] ) == 0 )
F_38 (
& V_10 -> V_16 , V_78 ,
V_80 ) ;
F_39 ( T_3 ) ;
}
void F_40 ( struct V_52 * V_53 , int V_4 )
{
struct V_54 * V_55 ;
struct V_9 * V_10 = V_53 -> V_10 ;
struct V_1 * V_2 = V_53 -> V_2 ;
T_2 V_6 ;
int V_62 ;
V_55 = F_15 ( V_53 , V_4 ) ;
F_41 ( V_10 , V_4 ) ;
F_22 ( V_64 , & V_55 -> V_65 ) ;
F_42 () ;
V_6 = V_53 -> V_81 [ V_4 ] >> 4 ;
V_62 = F_23 ( V_10 , V_2 , V_82 ,
& V_53 -> V_53 , V_4 , & V_6 , 0 ) ;
if ( V_62 ) {
#ifdef F_19
F_3 ( V_67 L_9
L_10 , V_4 ) ;
#endif
F_14 ( & V_53 -> V_58 ) ;
F_10 ( V_53 , V_4 , NULL ) ;
F_16 ( & V_53 -> V_58 ) ;
F_43 ( V_10 , V_4 ) ;
F_18 ( V_55 , V_66 ) ;
return;
}
F_43 ( V_10 , V_4 ) ;
F_44 ( & V_55 -> V_69 , V_83 + V_84 ) ;
#ifdef F_19
F_3 ( V_67 L_11 , V_4 ) ;
#endif
F_14 ( & V_53 -> V_58 ) ;
V_53 -> V_56 . V_85 [ V_4 ] ++ ;
F_16 ( & V_53 -> V_58 ) ;
F_1 ( V_2 , V_53 -> V_53 . V_23 , V_4 ,
V_55 -> V_5 , V_6 ,
V_10 -> V_16 . V_86 ,
V_55 -> V_8 ) ;
}
int F_45 ( struct V_87 * V_88 , T_2 V_4 ,
T_2 V_8 )
{
struct V_52 * V_53 = F_26 ( V_88 , struct V_52 , V_53 ) ;
struct V_1 * V_2 = V_53 -> V_2 ;
struct V_9 * V_10 = V_2 -> V_10 ;
struct V_54 * V_55 ;
int V_62 = 0 ;
F_46 ( V_88 , V_4 ) ;
if ( F_24 ( ! V_10 -> V_89 -> V_90 ) )
return - V_91 ;
if ( ( V_4 >= V_92 ) ||
! ( V_10 -> V_16 . V_50 & V_93 ) )
return - V_91 ;
#ifdef F_19
F_3 ( V_67 L_12 ,
V_88 -> V_23 , V_4 ) ;
#endif
if ( V_2 -> V_22 . type != V_27 &&
V_2 -> V_22 . type != V_25 &&
V_2 -> V_22 . type != V_24 )
return - V_91 ;
if ( F_47 ( V_53 , V_94 ) ) {
#ifdef F_19
F_3 ( V_67 L_13
L_14 ) ;
#endif
return - V_91 ;
}
F_14 ( & V_53 -> V_58 ) ;
if ( V_53 -> V_56 . V_85 [ V_4 ] > V_95 ) {
V_62 = - V_96 ;
goto V_97;
}
V_55 = F_15 ( V_53 , V_4 ) ;
if ( V_55 || V_53 -> V_56 . V_98 [ V_4 ] ) {
#ifdef F_19
F_3 ( V_67 L_15
L_16 , V_4 ) ;
#endif
V_62 = - V_99 ;
goto V_97;
}
V_55 = F_48 ( sizeof( struct V_54 ) , V_100 ) ;
if ( ! V_55 ) {
#ifdef F_19
if ( F_49 () )
F_3 ( V_18 L_17 ,
V_4 ) ;
#endif
V_62 = - V_101 ;
goto V_97;
}
F_50 ( & V_55 -> V_102 ) ;
F_51 ( V_64 , & V_55 -> V_65 ) ;
V_55 -> V_8 = V_8 ;
V_55 -> V_69 . V_103 = F_25 ;
V_55 -> V_69 . V_74 = ( unsigned long ) & V_53 -> V_75 [ V_4 ] ;
F_52 ( & V_55 -> V_69 ) ;
V_53 -> V_56 . V_104 ++ ;
V_55 -> V_5 = V_53 -> V_56 . V_104 ;
V_53 -> V_56 . V_98 [ V_4 ] = V_55 ;
F_53 ( & V_10 -> V_16 , & V_53 -> V_56 . V_105 ) ;
V_97:
F_16 ( & V_53 -> V_58 ) ;
return V_62 ;
}
static void F_32 ( T_3 )
ieee80211_agg_splice_packets( struct V_9 * V_10 ,
struct V_54 * V_55 , T_2 V_4 )
{
int V_78 = F_31 ( V_4 ) ;
unsigned long V_50 ;
F_41 ( V_10 , V_4 ) ;
if ( F_54 ( ! V_55 , L_18
L_19 , V_4 ) )
return;
if ( ! F_55 ( & V_55 -> V_102 ) ) {
F_56 ( & V_10 -> V_106 , V_50 ) ;
F_57 ( & V_55 -> V_102 ,
& V_10 -> V_102 [ V_78 ] ) ;
F_58 ( & V_10 -> V_106 , V_50 ) ;
}
}
static void F_36 ( T_3 )
ieee80211_agg_splice_finish( struct V_9 * V_10 , T_2 V_4 )
{
F_43 ( V_10 , V_4 ) ;
}
static void F_59 ( struct V_9 * V_10 ,
struct V_52 * V_53 , T_2 V_4 )
{
struct V_54 * V_55 ;
F_11 ( & V_53 -> V_56 . V_57 ) ;
V_55 = F_15 ( V_53 , V_4 ) ;
#ifdef F_19
F_3 ( V_67 L_20 , V_4 ) ;
#endif
F_23 ( V_10 , V_53 -> V_2 ,
V_107 ,
& V_53 -> V_53 , V_4 , NULL , V_55 -> V_108 ) ;
F_14 ( & V_53 -> V_58 ) ;
F_60 ( V_10 , V_55 , V_4 ) ;
F_20 ( V_70 , & V_55 -> V_65 ) ;
F_61 ( V_10 , V_4 ) ;
F_16 ( & V_53 -> V_58 ) ;
}
void F_62 ( struct V_109 * V_22 , T_1 * V_39 , T_2 V_4 )
{
struct V_1 * V_2 = F_63 ( V_22 ) ;
struct V_9 * V_10 = V_2 -> V_10 ;
struct V_52 * V_53 ;
struct V_54 * V_55 ;
F_64 ( V_2 , V_39 , V_4 ) ;
if ( V_4 >= V_92 ) {
#ifdef F_19
F_3 ( V_67 L_21 ,
V_4 , V_92 ) ;
#endif
return;
}
F_65 ( & V_10 -> V_110 ) ;
V_53 = F_66 ( V_2 , V_39 ) ;
if ( ! V_53 ) {
F_67 ( & V_10 -> V_110 ) ;
#ifdef F_19
F_3 ( V_67 L_22 , V_39 ) ;
#endif
return;
}
F_65 ( & V_53 -> V_56 . V_57 ) ;
V_55 = F_15 ( V_53 , V_4 ) ;
if ( F_24 ( ! V_55 ) ) {
#ifdef F_19
F_3 ( V_67 L_23 ) ;
#endif
goto V_111;
}
if ( F_24 ( F_68 ( V_112 , & V_55 -> V_65 ) ) )
goto V_111;
if ( F_17 ( V_76 , & V_55 -> V_65 ) )
F_59 ( V_10 , V_53 , V_4 ) ;
V_111:
F_67 ( & V_53 -> V_56 . V_57 ) ;
F_67 ( & V_10 -> V_110 ) ;
}
void F_69 ( struct V_109 * V_22 ,
const T_1 * V_39 , T_2 V_4 )
{
struct V_1 * V_2 = F_63 ( V_22 ) ;
struct V_9 * V_10 = V_2 -> V_10 ;
struct V_113 * V_114 ;
struct V_11 * V_12 = F_2 ( 0 ) ;
if ( F_70 ( ! V_12 ) ) {
#ifdef F_19
if ( F_49 () )
F_3 ( V_115 L_24
L_25 , V_2 -> V_19 ) ;
#endif
return;
}
V_114 = (struct V_113 * ) & V_12 -> V_116 ;
memcpy ( & V_114 -> V_39 , V_39 , V_20 ) ;
V_114 -> V_4 = V_4 ;
V_12 -> V_117 = V_118 ;
F_71 ( & V_2 -> V_119 , V_12 ) ;
F_53 ( & V_10 -> V_16 , & V_2 -> V_105 ) ;
}
int F_72 ( struct V_52 * V_53 , T_2 V_4 ,
enum V_59 V_60 ,
bool V_61 )
{
int V_62 ;
F_65 ( & V_53 -> V_56 . V_57 ) ;
V_62 = F_13 ( V_53 , V_4 , V_60 , V_61 ) ;
F_67 ( & V_53 -> V_56 . V_57 ) ;
return V_62 ;
}
int F_30 ( struct V_87 * V_88 , T_2 V_4 )
{
struct V_52 * V_53 = F_26 ( V_88 , struct V_52 , V_53 ) ;
struct V_1 * V_2 = V_53 -> V_2 ;
struct V_9 * V_10 = V_2 -> V_10 ;
struct V_54 * V_55 ;
int V_62 = 0 ;
F_73 ( V_88 , V_4 ) ;
if ( ! V_10 -> V_89 -> V_90 )
return - V_91 ;
if ( V_4 >= V_92 )
return - V_91 ;
F_14 ( & V_53 -> V_58 ) ;
V_55 = F_15 ( V_53 , V_4 ) ;
if ( ! V_55 ) {
V_62 = - V_63 ;
goto V_111;
}
if ( F_17 ( V_68 , & V_55 -> V_65 ) ) {
V_62 = 0 ;
goto V_111;
}
F_20 ( V_120 , & V_55 -> V_65 ) ;
F_53 ( & V_10 -> V_16 , & V_53 -> V_56 . V_105 ) ;
V_111:
F_16 ( & V_53 -> V_58 ) ;
return V_62 ;
}
void F_74 ( struct V_109 * V_22 , T_1 * V_39 , T_1 V_4 )
{
struct V_1 * V_2 = F_63 ( V_22 ) ;
struct V_9 * V_10 = V_2 -> V_10 ;
struct V_52 * V_53 ;
struct V_54 * V_55 ;
F_75 ( V_2 , V_39 , V_4 ) ;
if ( V_4 >= V_92 ) {
#ifdef F_19
F_3 ( V_67 L_21 ,
V_4 , V_92 ) ;
#endif
return;
}
#ifdef F_19
F_3 ( V_67 L_26 ,
V_39 , V_4 ) ;
#endif
F_65 ( & V_10 -> V_110 ) ;
V_53 = F_66 ( V_2 , V_39 ) ;
if ( ! V_53 ) {
#ifdef F_19
F_3 ( V_67 L_22 , V_39 ) ;
#endif
goto V_111;
}
F_65 ( & V_53 -> V_56 . V_57 ) ;
F_14 ( & V_53 -> V_58 ) ;
V_55 = F_15 ( V_53 , V_4 ) ;
if ( ! V_55 || ! F_17 ( V_68 , & V_55 -> V_65 ) ) {
#ifdef F_19
F_3 ( V_67 L_27 ) ;
#endif
goto V_121;
}
if ( V_55 -> V_71 == V_122 && V_55 -> V_72 )
F_76 ( V_53 -> V_2 , V_39 , V_4 ,
V_122 , V_123 ) ;
F_60 ( V_10 , V_55 , V_4 ) ;
F_10 ( V_53 , V_4 , NULL ) ;
F_61 ( V_10 , V_4 ) ;
F_18 ( V_55 , V_66 ) ;
V_121:
F_16 ( & V_53 -> V_58 ) ;
F_67 ( & V_53 -> V_56 . V_57 ) ;
V_111:
F_67 ( & V_10 -> V_110 ) ;
}
void F_77 ( struct V_109 * V_22 ,
const T_1 * V_39 , T_2 V_4 )
{
struct V_1 * V_2 = F_63 ( V_22 ) ;
struct V_9 * V_10 = V_2 -> V_10 ;
struct V_113 * V_114 ;
struct V_11 * V_12 = F_2 ( 0 ) ;
if ( F_70 ( ! V_12 ) ) {
#ifdef F_19
if ( F_49 () )
F_3 ( V_115 L_24
L_28 , V_2 -> V_19 ) ;
#endif
return;
}
V_114 = (struct V_113 * ) & V_12 -> V_116 ;
memcpy ( & V_114 -> V_39 , V_39 , V_20 ) ;
V_114 -> V_4 = V_4 ;
V_12 -> V_117 = V_124 ;
F_71 ( & V_2 -> V_119 , V_12 ) ;
F_53 ( & V_10 -> V_16 , & V_2 -> V_105 ) ;
}
void F_78 ( struct V_9 * V_10 ,
struct V_52 * V_53 ,
struct V_13 * V_14 ,
T_4 V_125 )
{
struct V_54 * V_55 ;
T_2 V_15 , V_4 ;
T_1 V_108 ;
V_15 = F_79 ( V_14 -> V_28 . V_33 . V_28 . V_126 . V_15 ) ;
V_4 = ( V_15 & V_127 ) >> 2 ;
V_108 = ( V_15 & V_128 ) >> 6 ;
F_65 ( & V_53 -> V_56 . V_57 ) ;
V_55 = F_15 ( V_53 , V_4 ) ;
if ( ! V_55 )
goto V_129;
if ( V_14 -> V_28 . V_33 . V_28 . V_126 . V_5 != V_55 -> V_5 ) {
#ifdef F_19
F_3 ( V_67 L_29 , V_4 ) ;
#endif
goto V_129;
}
F_80 ( & V_55 -> V_69 ) ;
#ifdef F_19
F_3 ( V_67 L_30 , V_4 ) ;
#endif
if ( F_79 ( V_14 -> V_28 . V_33 . V_28 . V_126 . V_130 )
== V_131 ) {
if ( ! V_108 )
goto V_129;
if ( F_68 ( V_76 ,
& V_55 -> V_65 ) ) {
goto V_129;
}
V_55 -> V_108 = V_108 ;
if ( F_17 ( V_112 , & V_55 -> V_65 ) )
F_59 ( V_10 , V_53 , V_4 ) ;
V_53 -> V_56 . V_85 [ V_4 ] = 0 ;
} else {
F_13 ( V_53 , V_4 , V_122 ,
true ) ;
}
V_129:
F_67 ( & V_53 -> V_56 . V_57 ) ;
}
