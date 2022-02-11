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
V_15 = ( T_2 ) ( 1 << 0 ) ;
V_15 |= ( T_2 ) ( 1 << 1 ) ;
V_15 |= ( T_2 ) ( V_4 << 2 ) ;
V_15 |= ( T_2 ) ( V_7 << 6 ) ;
V_14 -> V_27 . V_34 . V_27 . V_35 . V_15 = F_5 ( V_15 ) ;
V_14 -> V_27 . V_34 . V_27 . V_35 . V_8 = F_5 ( V_8 ) ;
V_14 -> V_27 . V_34 . V_27 . V_35 . V_6 =
F_5 ( V_6 << 4 ) ;
F_6 ( V_2 , V_12 ) ;
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
F_9 ( V_12 ) -> V_53 |= V_54 |
V_55 ;
F_10 ( V_2 , V_12 , V_4 ) ;
}
void F_11 ( struct V_56 * V_57 , int V_4 ,
struct V_58 * V_59 )
{
F_12 ( & V_57 -> V_60 . V_61 ) ;
F_12 ( & V_57 -> V_62 ) ;
F_13 ( V_57 -> V_60 . V_59 [ V_4 ] , V_59 ) ;
}
static void F_14 ( T_3 )
ieee80211_stop_queue_agg( struct V_1 * V_2 , int V_4 )
{
int V_63 = V_2 -> V_20 . V_64 [ F_15 ( V_4 ) ] ;
if ( F_16 ( & V_2 -> V_10 -> V_65 [ V_63 ] ) == 1 )
F_17 (
& V_2 -> V_10 -> V_16 , V_63 ,
V_66 ,
false ) ;
F_18 ( T_3 ) ;
}
static void F_19 ( T_3 )
ieee80211_wake_queue_agg( struct V_1 * V_2 , int V_4 )
{
int V_63 = V_2 -> V_20 . V_64 [ F_15 ( V_4 ) ] ;
if ( F_20 ( & V_2 -> V_10 -> V_65 [ V_63 ] ) == 0 )
F_21 (
& V_2 -> V_10 -> V_16 , V_63 ,
V_66 ,
false ) ;
F_22 ( T_3 ) ;
}
static void
F_23 ( struct V_56 * V_57 , int V_4 )
{
struct V_67 * V_68 = V_57 -> V_57 . V_68 [ V_4 ] ;
struct V_1 * V_2 ;
struct V_69 * V_69 ;
struct V_70 * V_71 ;
if ( ! V_68 )
return;
V_71 = F_24 ( V_68 ) ;
V_2 = F_8 ( V_68 -> V_20 ) ;
V_69 = & V_2 -> V_10 -> V_69 ;
F_25 ( & V_69 -> V_62 ) ;
F_26 ( V_72 , & V_71 -> V_53 ) ;
F_27 ( & V_69 -> V_62 ) ;
}
static void
F_28 ( struct V_56 * V_57 , int V_4 , bool V_73 )
{
struct V_67 * V_68 = V_57 -> V_57 . V_68 [ V_4 ] ;
struct V_70 * V_71 ;
if ( ! V_68 )
return;
V_71 = F_24 ( V_68 ) ;
if ( V_73 )
F_26 ( V_74 , & V_71 -> V_53 ) ;
else
F_29 ( V_74 , & V_71 -> V_53 ) ;
F_29 ( V_72 , & V_71 -> V_53 ) ;
F_30 ( V_57 -> V_2 -> V_10 , V_71 ) ;
}
static void F_14 ( T_3 )
ieee80211_agg_splice_packets( struct V_1 * V_2 ,
struct V_58 * V_59 , T_2 V_4 )
{
struct V_9 * V_10 = V_2 -> V_10 ;
int V_63 = V_2 -> V_20 . V_64 [ F_15 ( V_4 ) ] ;
unsigned long V_53 ;
F_31 ( V_2 , V_4 ) ;
if ( F_32 ( ! V_59 ,
L_1 ,
V_4 ) )
return;
if ( ! F_33 ( & V_59 -> V_75 ) ) {
F_34 ( & V_10 -> V_76 , V_53 ) ;
F_35 ( & V_59 -> V_75 ,
& V_10 -> V_75 [ V_63 ] ) ;
F_36 ( & V_10 -> V_76 , V_53 ) ;
}
}
static void F_19 ( T_3 )
ieee80211_agg_splice_finish( struct V_1 * V_2 , T_2 V_4 )
{
F_37 ( V_2 , V_4 ) ;
}
static void F_38 ( struct V_56 * V_57 , int V_4 )
{
struct V_58 * V_59 ;
F_12 ( & V_57 -> V_60 . V_61 ) ;
F_12 ( & V_57 -> V_62 ) ;
V_59 = F_39 ( V_57 , V_4 ) ;
F_40 ( V_57 -> V_2 , V_59 , V_4 ) ;
F_11 ( V_57 , V_4 , NULL ) ;
F_41 ( V_57 -> V_2 , V_4 ) ;
F_28 ( V_57 , V_4 , false ) ;
F_42 ( V_59 , V_77 ) ;
}
int F_43 ( struct V_56 * V_57 , T_2 V_4 ,
enum V_78 V_79 )
{
struct V_9 * V_10 = V_57 -> V_10 ;
struct V_58 * V_59 ;
struct V_80 V_81 = {
. V_57 = & V_57 -> V_57 ,
. V_4 = V_4 ,
. V_82 = 0 ,
. V_83 = false ,
. V_8 = 0 ,
. V_42 = 0 ,
} ;
int V_84 ;
F_12 ( & V_57 -> V_60 . V_61 ) ;
switch ( V_79 ) {
case V_85 :
case V_86 :
case V_87 :
V_81 . V_34 = V_88 ;
break;
case V_89 :
V_81 . V_34 = V_90 ;
break;
default:
F_44 ( 1 ) ;
return - V_91 ;
}
F_25 ( & V_57 -> V_62 ) ;
V_59 = F_39 ( V_57 , V_4 ) ;
if ( ! V_59 ) {
F_27 ( & V_57 -> V_62 ) ;
return - V_92 ;
}
if ( F_45 ( V_93 , & V_59 -> V_94 ) ) {
F_27 ( & V_57 -> V_62 ) ;
if ( V_79 != V_89 )
return - V_95 ;
V_81 . V_34 = V_96 ;
V_84 = F_46 ( V_10 , V_57 -> V_2 , & V_81 ) ;
F_44 ( V_84 ) ;
return 0 ;
}
if ( F_45 ( V_97 , & V_59 -> V_94 ) ) {
F_11 ( V_57 , V_4 , NULL ) ;
F_27 ( & V_57 -> V_62 ) ;
F_42 ( V_59 , V_77 ) ;
return 0 ;
}
F_26 ( V_93 , & V_59 -> V_94 ) ;
F_27 ( & V_57 -> V_62 ) ;
F_47 ( V_57 -> V_2 , L_2 ,
V_57 -> V_57 . V_21 , V_4 ) ;
F_48 ( & V_59 -> V_98 ) ;
F_48 ( & V_59 -> V_99 ) ;
F_29 ( V_100 , & V_59 -> V_94 ) ;
F_49 () ;
V_59 -> V_101 = V_79 == V_87 ?
V_102 :
V_103 ;
V_59 -> V_104 = V_79 == V_86 ;
V_84 = F_46 ( V_10 , V_57 -> V_2 , & V_81 ) ;
if ( F_50 ( V_84 ) ) {
}
return 0 ;
}
static void F_51 ( unsigned long V_105 )
{
T_2 V_4 = * ( T_1 * ) V_105 ;
struct V_56 * V_57 = F_52 ( ( void * ) V_105 ,
struct V_56 , V_106 [ V_4 ] ) ;
struct V_58 * V_59 ;
F_53 () ;
V_59 = F_54 ( V_57 -> V_60 . V_59 [ V_4 ] ) ;
if ( ! V_59 ||
F_45 ( V_107 , & V_59 -> V_94 ) ) {
F_55 () ;
F_47 ( V_57 -> V_2 ,
L_3 ,
V_57 -> V_57 . V_21 , V_4 ) ;
return;
}
F_47 ( V_57 -> V_2 , L_4 ,
V_57 -> V_57 . V_21 , V_4 ) ;
F_56 ( & V_57 -> V_57 , V_4 ) ;
F_55 () ;
}
void F_57 ( struct V_56 * V_57 , int V_4 )
{
struct V_58 * V_59 ;
struct V_9 * V_10 = V_57 -> V_10 ;
struct V_1 * V_2 = V_57 -> V_2 ;
struct V_80 V_81 = {
. V_57 = & V_57 -> V_57 ,
. V_34 = V_108 ,
. V_4 = V_4 ,
. V_82 = 0 ,
. V_83 = false ,
. V_8 = 0 ,
} ;
int V_84 ;
V_59 = F_39 ( V_57 , V_4 ) ;
F_29 ( V_97 , & V_59 -> V_94 ) ;
F_23 ( V_57 , V_4 ) ;
F_49 () ;
V_81 . V_42 = V_57 -> V_109 [ V_4 ] >> 4 ;
V_84 = F_46 ( V_10 , V_2 , & V_81 ) ;
if ( V_84 ) {
F_47 ( V_2 ,
L_5 ,
V_57 -> V_57 . V_21 , V_4 ) ;
F_25 ( & V_57 -> V_62 ) ;
F_40 ( V_2 , V_59 , V_4 ) ;
F_11 ( V_57 , V_4 , NULL ) ;
F_41 ( V_2 , V_4 ) ;
F_27 ( & V_57 -> V_62 ) ;
F_28 ( V_57 , V_4 , false ) ;
F_42 ( V_59 , V_77 ) ;
return;
}
F_58 ( & V_59 -> V_98 , V_110 + V_111 ) ;
F_47 ( V_2 , L_6 ,
V_57 -> V_57 . V_21 , V_4 ) ;
F_25 ( & V_57 -> V_62 ) ;
V_57 -> V_60 . V_112 [ V_4 ] = V_110 ;
V_57 -> V_60 . V_113 [ V_4 ] ++ ;
F_27 ( & V_57 -> V_62 ) ;
F_1 ( V_2 , V_57 -> V_57 . V_21 , V_4 ,
V_59 -> V_5 , V_81 . V_42 ,
V_114 ,
V_59 -> V_8 ) ;
}
static void F_59 ( unsigned long V_105 )
{
T_1 * V_115 = ( T_1 * ) V_105 ;
T_1 * V_116 = V_115 - * V_115 ;
struct V_56 * V_57 = F_52 ( V_116 , struct V_56 ,
V_106 [ 0 ] ) ;
struct V_58 * V_59 ;
unsigned long V_8 ;
F_53 () ;
V_59 = F_54 ( V_57 -> V_60 . V_59 [ * V_115 ] ) ;
if ( ! V_59 || F_45 ( V_93 , & V_59 -> V_94 ) ) {
F_55 () ;
return;
}
V_8 = V_59 -> V_117 + F_60 ( V_59 -> V_8 ) ;
if ( F_61 ( V_8 ) ) {
F_58 ( & V_59 -> V_99 , V_8 ) ;
F_55 () ;
return;
}
F_55 () ;
F_47 ( V_57 -> V_2 , L_7 ,
V_57 -> V_57 . V_21 , ( T_2 ) * V_115 ) ;
F_56 ( & V_57 -> V_57 , * V_115 ) ;
}
int F_62 ( struct V_118 * V_119 , T_2 V_4 ,
T_2 V_8 )
{
struct V_56 * V_57 = F_52 ( V_119 , struct V_56 , V_57 ) ;
struct V_1 * V_2 = V_57 -> V_2 ;
struct V_9 * V_10 = V_2 -> V_10 ;
struct V_58 * V_59 ;
int V_84 = 0 ;
F_63 ( V_119 , V_4 ) ;
if ( F_32 ( V_57 -> V_120 == V_4 ,
L_8 , V_4 ) )
return - V_91 ;
if ( ! V_119 -> V_121 . V_122 )
return - V_91 ;
if ( F_44 ( ! V_10 -> V_123 -> V_124 ) )
return - V_91 ;
if ( ( V_4 >= V_125 ) ||
! F_64 ( & V_10 -> V_16 , V_126 ) ||
F_64 ( & V_10 -> V_16 , V_127 ) )
return - V_91 ;
if ( F_50 ( V_4 >= V_128 ) )
return - V_91 ;
F_47 ( V_2 , L_9 ,
V_119 -> V_21 , V_4 ) ;
if ( V_2 -> V_20 . type != V_26 &&
V_2 -> V_20 . type != V_24 &&
V_2 -> V_20 . type != V_23 &&
V_2 -> V_20 . type != V_22 &&
V_2 -> V_20 . type != V_29 )
return - V_91 ;
if ( F_65 ( V_57 , V_129 ) ) {
F_47 ( V_2 ,
L_10 ,
V_57 -> V_57 . V_21 , V_4 ) ;
return - V_91 ;
}
if ( V_57 -> V_2 -> V_20 . type == V_29 &&
! V_57 -> V_57 . V_121 . V_122 ) {
F_47 ( V_2 ,
L_11 ,
V_119 -> V_21 ) ;
return - V_91 ;
}
F_25 ( & V_57 -> V_62 ) ;
if ( V_57 -> V_60 . V_113 [ V_4 ] > V_130 ) {
V_84 = - V_131 ;
goto V_132;
}
if ( V_57 -> V_60 . V_113 [ V_4 ] > V_133 &&
F_66 ( V_110 , V_57 -> V_60 . V_112 [ V_4 ] +
V_134 ) ) {
F_47 ( V_2 ,
L_12 ,
V_57 -> V_60 . V_113 [ V_4 ] , V_57 -> V_57 . V_21 , V_4 ) ;
V_84 = - V_131 ;
goto V_132;
}
V_59 = F_39 ( V_57 , V_4 ) ;
if ( V_59 || V_57 -> V_60 . V_135 [ V_4 ] ) {
F_47 ( V_2 ,
L_13 ,
V_57 -> V_57 . V_21 , V_4 ) ;
V_84 = - V_136 ;
goto V_132;
}
V_59 = F_67 ( sizeof( struct V_58 ) , V_137 ) ;
if ( ! V_59 ) {
V_84 = - V_138 ;
goto V_132;
}
F_68 ( & V_59 -> V_75 ) ;
F_69 ( V_97 , & V_59 -> V_94 ) ;
V_59 -> V_8 = V_8 ;
F_70 ( & V_59 -> V_98 ,
F_51 ,
( unsigned long ) & V_57 -> V_106 [ V_4 ] ) ;
F_71 ( & V_59 -> V_99 ,
F_59 ,
( unsigned long ) & V_57 -> V_106 [ V_4 ] ) ;
V_57 -> V_60 . V_139 ++ ;
V_59 -> V_5 = V_57 -> V_60 . V_139 ;
V_57 -> V_60 . V_135 [ V_4 ] = V_59 ;
F_72 ( & V_10 -> V_16 , & V_57 -> V_60 . V_140 ) ;
V_132:
F_27 ( & V_57 -> V_62 ) ;
return V_84 ;
}
static void F_73 ( struct V_9 * V_10 ,
struct V_56 * V_57 , T_2 V_4 )
{
struct V_58 * V_59 ;
struct V_80 V_81 = {
. V_57 = & V_57 -> V_57 ,
. V_34 = V_141 ,
. V_4 = V_4 ,
. V_8 = 0 ,
. V_42 = 0 ,
} ;
F_12 ( & V_57 -> V_60 . V_61 ) ;
V_59 = F_39 ( V_57 , V_4 ) ;
V_81 . V_82 = V_59 -> V_82 ;
V_81 . V_83 = V_59 -> V_83 ;
F_47 ( V_57 -> V_2 , L_14 ,
V_57 -> V_57 . V_21 , V_4 ) ;
F_46 ( V_10 , V_57 -> V_2 , & V_81 ) ;
F_25 ( & V_57 -> V_62 ) ;
F_40 ( V_57 -> V_2 , V_59 , V_4 ) ;
F_26 ( V_100 , & V_59 -> V_94 ) ;
F_41 ( V_57 -> V_2 , V_4 ) ;
F_27 ( & V_57 -> V_62 ) ;
F_28 ( V_57 , V_4 , true ) ;
}
void F_74 ( struct V_56 * V_57 , int V_4 ,
struct V_58 * V_59 )
{
struct V_1 * V_2 = V_57 -> V_2 ;
struct V_9 * V_10 = V_2 -> V_10 ;
if ( F_50 ( F_75 ( V_142 , & V_59 -> V_94 ) ) )
return;
if ( F_45 ( V_107 , & V_59 -> V_94 ) )
F_73 ( V_10 , V_57 , V_4 ) ;
}
static struct V_58 *
F_76 ( struct V_1 * V_2 ,
const T_1 * V_41 , T_2 V_4 , struct V_56 * * V_57 )
{
struct V_58 * V_59 ;
if ( V_4 >= V_125 ) {
F_47 ( V_2 , L_15 ,
V_4 , V_125 ) ;
return NULL ;
}
* V_57 = F_77 ( V_2 , V_41 ) ;
if ( ! * V_57 ) {
F_47 ( V_2 , L_16 , V_41 ) ;
return NULL ;
}
V_59 = F_54 ( ( * V_57 ) -> V_60 . V_59 [ V_4 ] ) ;
if ( F_50 ( ! V_59 ) )
F_47 ( V_2 , L_17 ) ;
return V_59 ;
}
void F_78 ( struct V_40 * V_20 ,
const T_1 * V_41 , T_2 V_4 )
{
struct V_1 * V_2 = F_8 ( V_20 ) ;
struct V_9 * V_10 = V_2 -> V_10 ;
struct V_56 * V_57 ;
struct V_58 * V_59 ;
F_79 ( V_2 , V_41 , V_4 ) ;
F_53 () ;
V_59 = F_76 ( V_2 , V_41 , V_4 , & V_57 ) ;
if ( ! V_59 )
goto V_143;
F_26 ( V_144 , & V_59 -> V_94 ) ;
F_72 ( & V_10 -> V_16 , & V_57 -> V_60 . V_140 ) ;
V_143:
F_55 () ;
}
int F_80 ( struct V_56 * V_57 , T_2 V_4 ,
enum V_78 V_79 )
{
int V_84 ;
F_81 ( & V_57 -> V_60 . V_61 ) ;
V_84 = F_43 ( V_57 , V_4 , V_79 ) ;
F_82 ( & V_57 -> V_60 . V_61 ) ;
return V_84 ;
}
int F_56 ( struct V_118 * V_119 , T_2 V_4 )
{
struct V_56 * V_57 = F_52 ( V_119 , struct V_56 , V_57 ) ;
struct V_1 * V_2 = V_57 -> V_2 ;
struct V_9 * V_10 = V_2 -> V_10 ;
struct V_58 * V_59 ;
int V_84 = 0 ;
F_83 ( V_119 , V_4 ) ;
if ( ! V_10 -> V_123 -> V_124 )
return - V_91 ;
if ( V_4 >= V_125 )
return - V_91 ;
F_25 ( & V_57 -> V_62 ) ;
V_59 = F_39 ( V_57 , V_4 ) ;
if ( ! V_59 ) {
V_84 = - V_92 ;
goto V_145;
}
F_32 ( V_57 -> V_120 == V_4 ,
L_18 , V_4 ) ;
if ( F_45 ( V_93 , & V_59 -> V_94 ) ) {
V_84 = 0 ;
goto V_145;
}
F_26 ( V_146 , & V_59 -> V_94 ) ;
F_72 ( & V_10 -> V_16 , & V_57 -> V_60 . V_140 ) ;
V_145:
F_27 ( & V_57 -> V_62 ) ;
return V_84 ;
}
void F_84 ( struct V_56 * V_57 , int V_4 ,
struct V_58 * V_59 )
{
struct V_1 * V_2 = V_57 -> V_2 ;
bool V_147 = false ;
F_47 ( V_2 , L_19 ,
V_57 -> V_57 . V_21 , V_4 ) ;
F_25 ( & V_57 -> V_62 ) ;
if ( ! F_45 ( V_93 , & V_59 -> V_94 ) ) {
F_47 ( V_2 ,
L_20 ,
V_57 -> V_57 . V_21 , V_4 ) ;
goto V_148;
}
if ( V_59 -> V_101 == V_103 && V_59 -> V_104 )
V_147 = true ;
F_38 ( V_57 , V_4 ) ;
V_148:
F_27 ( & V_57 -> V_62 ) ;
if ( V_147 )
F_85 ( V_2 , V_57 -> V_57 . V_21 , V_4 ,
V_103 , V_149 ) ;
}
void F_86 ( struct V_40 * V_20 ,
const T_1 * V_41 , T_2 V_4 )
{
struct V_1 * V_2 = F_8 ( V_20 ) ;
struct V_9 * V_10 = V_2 -> V_10 ;
struct V_56 * V_57 ;
struct V_58 * V_59 ;
F_87 ( V_2 , V_41 , V_4 ) ;
F_53 () ;
V_59 = F_76 ( V_2 , V_41 , V_4 , & V_57 ) ;
if ( ! V_59 )
goto V_143;
F_26 ( V_150 , & V_59 -> V_94 ) ;
F_72 ( & V_10 -> V_16 , & V_57 -> V_60 . V_140 ) ;
V_143:
F_55 () ;
}
void F_88 ( struct V_9 * V_10 ,
struct V_56 * V_57 ,
struct V_13 * V_14 ,
T_4 V_151 )
{
struct V_58 * V_59 ;
struct V_67 * V_68 ;
T_2 V_15 , V_4 ;
T_1 V_82 ;
bool V_83 ;
V_15 = F_89 ( V_14 -> V_27 . V_34 . V_27 . V_152 . V_15 ) ;
V_83 = V_15 & V_153 ;
V_4 = ( V_15 & V_154 ) >> 2 ;
V_82 = ( V_15 & V_155 ) >> 6 ;
V_82 = F_90 ( V_82 , V_10 -> V_16 . V_156 ) ;
V_68 = V_57 -> V_57 . V_68 [ V_4 ] ;
if ( ! V_83 && V_68 )
F_26 ( V_157 , & F_24 ( V_68 ) -> V_53 ) ;
F_81 ( & V_57 -> V_60 . V_61 ) ;
V_59 = F_39 ( V_57 , V_4 ) ;
if ( ! V_59 )
goto V_143;
if ( V_14 -> V_27 . V_34 . V_27 . V_152 . V_5 != V_59 -> V_5 ) {
F_47 ( V_57 -> V_2 , L_21 ,
V_57 -> V_57 . V_21 , V_4 ) ;
goto V_143;
}
F_48 ( & V_59 -> V_98 ) ;
F_47 ( V_57 -> V_2 , L_22 ,
V_57 -> V_57 . V_21 , V_4 ) ;
if ( F_45 ( V_146 , & V_59 -> V_94 ) ||
F_45 ( V_93 , & V_59 -> V_94 ) ) {
F_47 ( V_57 -> V_2 ,
L_23 ,
V_57 -> V_57 . V_21 , V_4 ) ;
goto V_143;
}
if ( F_89 ( V_14 -> V_27 . V_34 . V_27 . V_152 . V_158 )
== V_159 && V_82 ) {
if ( F_75 ( V_107 ,
& V_59 -> V_94 ) ) {
goto V_143;
}
V_59 -> V_82 = V_82 ;
V_59 -> V_83 = V_83 ;
if ( F_45 ( V_142 , & V_59 -> V_94 ) )
F_73 ( V_10 , V_57 , V_4 ) ;
V_57 -> V_60 . V_113 [ V_4 ] = 0 ;
if ( V_59 -> V_8 ) {
F_58 ( & V_59 -> V_99 ,
F_91 ( V_59 -> V_8 ) ) ;
V_59 -> V_117 = V_110 ;
}
} else {
F_43 ( V_57 , V_4 , V_85 ) ;
}
V_143:
F_82 ( & V_57 -> V_60 . V_61 ) ;
}
