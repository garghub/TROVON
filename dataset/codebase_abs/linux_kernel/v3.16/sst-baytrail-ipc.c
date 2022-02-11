static inline T_1 F_1 ( int V_1 , int V_2 , bool V_3 , int V_4 )
{
T_1 V_5 ;
V_5 = F_2 ( V_1 ) |
F_3 ( V_4 ) |
F_4 ( V_3 ) |
F_5 ( V_2 ) |
V_6 ;
return V_5 ;
}
static inline T_2 F_6 ( T_1 V_5 )
{
return V_5 & V_7 ;
}
static inline T_3 F_7 ( T_1 V_5 )
{
return ( V_5 >> V_8 ) & V_9 ;
}
static inline T_2 F_8 ( T_1 V_5 )
{
return ( V_5 >> V_10 ) & V_11 ;
}
static struct V_12 * F_9 ( struct V_13 * V_14 ,
int V_15 )
{
struct V_12 * V_16 ;
F_10 (stream, &byt->stream_list, node) {
if ( V_16 -> V_4 == V_15 )
return V_16 ;
}
return NULL ;
}
static void F_11 ( struct V_13 * V_14 , const char * V_17 )
{
struct V_18 * V_19 = V_14 -> V_20 ;
T_1 V_21 , V_22 , V_23 , V_24 ;
V_24 = F_12 ( V_19 , V_25 ) ;
V_21 = F_12 ( V_19 , V_26 ) ;
V_22 = F_12 ( V_19 , V_27 ) ;
V_23 = F_12 ( V_19 , V_28 ) ;
F_13 ( V_14 -> V_29 ,
L_1 ,
V_17 , V_24 , V_21 , V_22 , V_23 ) ;
}
static struct V_30 * F_14 ( struct V_13 * V_14 )
{
struct V_30 * V_31 = NULL ;
if ( ! F_15 ( & V_14 -> V_32 ) ) {
V_31 = F_16 ( & V_14 -> V_32 ,
struct V_30 , V_33 ) ;
F_17 ( & V_31 -> V_33 ) ;
}
return V_31 ;
}
static void F_18 ( struct V_34 * V_35 )
{
struct V_13 * V_14 =
F_19 ( V_35 , struct V_13 , V_36 ) ;
struct V_30 * V_31 ;
T_1 V_24 ;
unsigned long V_37 ;
F_20 ( & V_14 -> V_20 -> V_38 , V_37 ) ;
if ( F_15 ( & V_14 -> V_39 ) ) {
F_21 ( & V_14 -> V_20 -> V_38 , V_37 ) ;
return;
}
V_24 = F_12 ( V_14 -> V_20 , V_25 ) ;
if ( V_24 & V_6 ) {
F_21 ( & V_14 -> V_20 -> V_38 , V_37 ) ;
return;
}
V_31 = F_16 ( & V_14 -> V_39 , struct V_30 , V_33 ) ;
F_22 ( & V_31 -> V_33 , & V_14 -> V_40 ) ;
if ( V_31 -> V_5 & F_4 ( true ) )
F_23 ( V_14 -> V_20 , V_31 -> V_41 , V_31 -> V_42 ) ;
F_24 ( V_14 -> V_20 , V_25 , V_31 -> V_5 ) ;
F_21 ( & V_14 -> V_20 -> V_38 , V_37 ) ;
}
static inline void F_25 ( struct V_13 * V_14 ,
struct V_30 * V_31 )
{
V_31 -> V_43 = true ;
if ( ! V_31 -> V_44 )
F_26 ( & V_31 -> V_33 , & V_14 -> V_32 ) ;
else
F_27 ( & V_31 -> V_45 ) ;
}
static void F_28 ( struct V_13 * V_14 )
{
struct V_30 * V_31 , * V_46 ;
unsigned long V_37 ;
F_20 ( & V_14 -> V_20 -> V_38 , V_37 ) ;
F_29 (msg, tmp, &byt->tx_list, list) {
F_22 ( & V_31 -> V_33 , & V_14 -> V_32 ) ;
}
F_29 (msg, tmp, &byt->rx_list, list) {
F_22 ( & V_31 -> V_33 , & V_14 -> V_32 ) ;
}
F_21 ( & V_14 -> V_20 -> V_38 , V_37 ) ;
}
static int F_30 ( struct V_13 * V_14 , struct V_30 * V_31 ,
void * V_47 )
{
unsigned long V_37 ;
int V_48 ;
V_48 = F_31 ( V_31 -> V_45 , V_31 -> V_43 ,
F_32 ( V_49 ) ) ;
F_20 ( & V_14 -> V_20 -> V_38 , V_37 ) ;
if ( V_48 == 0 ) {
F_17 ( & V_31 -> V_33 ) ;
F_11 ( V_14 , L_2 ) ;
V_48 = - V_50 ;
} else {
if ( V_31 -> V_51 )
memcpy ( V_47 , V_31 -> V_47 , V_31 -> V_51 ) ;
V_48 = V_31 -> V_52 ;
}
F_26 ( & V_31 -> V_33 , & V_14 -> V_32 ) ;
F_21 ( & V_14 -> V_20 -> V_38 , V_37 ) ;
return V_48 ;
}
static int F_33 ( struct V_13 * V_14 , T_1 V_5 ,
void * V_41 , T_4 V_53 ,
void * V_47 , T_4 V_54 , int V_44 )
{
unsigned long V_37 ;
struct V_30 * V_31 ;
F_20 ( & V_14 -> V_20 -> V_38 , V_37 ) ;
V_31 = F_14 ( V_14 ) ;
if ( V_31 == NULL ) {
F_21 ( & V_14 -> V_20 -> V_38 , V_37 ) ;
return - V_55 ;
}
V_31 -> V_5 = V_5 ;
V_31 -> V_42 = V_53 ;
V_31 -> V_51 = V_54 ;
V_31 -> V_44 = V_44 ;
V_31 -> V_52 = 0 ;
V_31 -> V_43 = false ;
if ( V_53 ) {
* ( V_56 * ) V_31 -> V_41 = ( V_56 ) ( V_5 & ( V_56 ) - 1 ) ;
memcpy ( V_31 -> V_41 + sizeof( V_56 ) , V_41 , V_53 ) ;
V_31 -> V_42 += sizeof( V_56 ) ;
}
F_26 ( & V_31 -> V_33 , & V_14 -> V_39 ) ;
F_21 ( & V_14 -> V_20 -> V_38 , V_37 ) ;
F_34 ( & V_14 -> V_57 , & V_14 -> V_36 ) ;
if ( V_44 )
return F_30 ( V_14 , V_31 , V_47 ) ;
else
return 0 ;
}
static inline int F_35 ( struct V_13 * V_14 , T_1 V_5 ,
void * V_41 , T_4 V_53 ,
void * V_47 , T_4 V_54 )
{
return F_33 ( V_14 , V_5 , V_41 , V_53 ,
V_47 , V_54 , 1 ) ;
}
static inline int F_36 ( struct V_13 * V_14 , T_1 V_5 ,
void * V_41 , T_4 V_53 )
{
return F_33 ( V_14 , V_5 , V_41 , V_53 ,
NULL , 0 , 0 ) ;
}
static struct V_30 * F_37 ( struct V_13 * V_14 ,
T_1 V_5 )
{
struct V_30 * V_31 = NULL , * V_58 ;
T_1 V_59 ;
V_59 = V_7 |
V_9 << V_8 ;
V_5 &= V_59 ;
if ( F_15 ( & V_14 -> V_40 ) ) {
F_13 ( V_14 -> V_29 ,
L_3 , V_5 ) ;
goto V_60;
}
F_10 (_msg, &byt->rx_list, list) {
if ( ( V_58 -> V_5 & V_59 ) == V_5 ) {
V_31 = V_58 ;
break;
}
}
V_60:
return V_31 ;
}
static void F_38 ( struct V_13 * V_14 , struct V_30 * V_31 )
{
struct V_12 * V_16 ;
T_1 V_5 = V_31 -> V_5 ;
T_3 V_15 = F_7 ( V_5 ) ;
T_3 V_61 = F_6 ( V_5 ) ;
V_16 = F_9 ( V_14 , V_15 ) ;
if ( V_16 == NULL )
return;
switch ( V_61 ) {
case V_62 :
case V_63 :
case V_64 :
V_16 -> V_65 = false ;
break;
case V_66 :
case V_67 :
V_16 -> V_65 = true ;
break;
}
}
static int F_39 ( struct V_13 * V_14 , T_1 V_5 )
{
struct V_30 * V_31 ;
V_31 = F_37 ( V_14 , V_5 ) ;
if ( V_31 == NULL )
return 1 ;
if ( V_5 & F_4 ( true ) ) {
V_31 -> V_51 = F_8 ( V_5 ) ;
F_40 ( V_14 -> V_20 , V_31 -> V_47 , V_31 -> V_51 ) ;
}
F_38 ( V_14 , V_31 ) ;
F_17 ( & V_31 -> V_33 ) ;
F_25 ( V_14 , V_31 ) ;
return 1 ;
}
static void F_41 ( struct V_13 * V_14 , T_1 V_5 )
{
F_42 ( V_14 -> V_29 , L_4 , V_5 ) ;
V_14 -> V_68 = true ;
F_27 ( & V_14 -> V_69 ) ;
}
static int F_43 ( struct V_13 * V_14 ,
unsigned long * V_37 )
{
struct V_18 * V_19 = V_14 -> V_20 ;
struct V_12 * V_16 ;
T_1 V_5 ;
T_3 V_1 , V_15 ;
int V_70 = 1 ;
V_5 = F_12 ( V_19 , V_27 ) ;
V_1 = F_6 ( V_5 ) ;
switch ( V_1 ) {
case V_71 :
V_15 = F_7 ( V_5 ) ;
V_16 = F_9 ( V_14 , V_15 ) ;
if ( V_16 && V_16 -> V_65 && V_16 -> V_72 ) {
F_21 ( & V_19 -> V_38 , * V_37 ) ;
V_16 -> V_72 ( V_16 , V_16 -> V_73 ) ;
F_20 ( & V_19 -> V_38 , * V_37 ) ;
}
break;
case V_74 :
F_41 ( V_14 , V_5 ) ;
break;
}
return V_70 ;
}
static T_5 F_44 ( int V_75 , void * V_76 )
{
struct V_18 * V_19 = (struct V_18 * ) V_76 ;
struct V_13 * V_14 = F_45 ( V_19 ) ;
T_1 V_5 ;
unsigned long V_37 ;
F_20 ( & V_19 -> V_38 , V_37 ) ;
V_5 = F_12 ( V_19 , V_27 ) ;
if ( V_5 & V_77 ) {
if ( V_5 & V_78 ) {
F_43 ( V_14 , & V_37 ) ;
} else {
F_39 ( V_14 , V_5 ) ;
}
F_46 ( V_19 , V_27 ,
V_79 | V_77 |
F_5 ( V_11 ) ,
V_79 ) ;
F_46 ( V_19 , V_28 ,
V_80 , 0 ) ;
}
F_21 ( & V_19 -> V_38 , V_37 ) ;
F_34 ( & V_14 -> V_57 , & V_14 -> V_36 ) ;
return V_81 ;
}
struct V_12 * F_47 ( struct V_13 * V_14 , int V_82 ,
V_56 (* V_72)( struct V_12 * V_16 , void * V_2 ) ,
void * V_2 )
{
struct V_12 * V_16 ;
struct V_18 * V_19 = V_14 -> V_20 ;
unsigned long V_37 ;
V_16 = F_48 ( sizeof( * V_16 ) , V_83 ) ;
if ( V_16 == NULL )
return NULL ;
F_20 ( & V_19 -> V_38 , V_37 ) ;
F_49 ( & V_16 -> V_84 , & V_14 -> V_85 ) ;
V_16 -> V_72 = V_72 ;
V_16 -> V_73 = V_2 ;
V_16 -> V_14 = V_14 ;
V_16 -> V_4 = V_82 ;
F_21 ( & V_19 -> V_38 , V_37 ) ;
return V_16 ;
}
int F_50 ( struct V_13 * V_14 , struct V_12 * V_16 ,
int V_86 )
{
V_16 -> V_87 . V_88 . V_89 = V_86 ;
return 0 ;
}
int F_51 ( struct V_13 * V_14 ,
struct V_12 * V_16 , T_3 V_90 )
{
V_16 -> V_87 . V_88 . V_91 = V_90 ;
return 0 ;
}
int F_52 ( struct V_13 * V_14 , struct V_12 * V_16 ,
unsigned int V_92 )
{
V_16 -> V_87 . V_88 . V_93 = V_92 ;
return 0 ;
}
int F_53 ( struct V_13 * V_14 , struct V_12 * V_16 ,
int V_94 , int V_95 , int V_96 )
{
V_16 -> V_87 . V_97 . V_94 = V_94 ;
V_16 -> V_87 . V_97 . V_97 = V_95 ;
V_16 -> V_87 . V_97 . V_96 = V_96 ;
V_16 -> V_87 . V_97 . V_98 = 0xc ;
return 0 ;
}
int F_54 ( struct V_13 * V_14 , struct V_12 * V_16 ,
T_6 V_99 , T_6 V_100 )
{
V_16 -> V_87 . V_101 . V_102 = 1 ;
V_16 -> V_87 . V_101 . V_103 [ 0 ] . V_104 = V_99 ;
V_16 -> V_87 . V_101 . V_103 [ 0 ] . V_105 = V_100 ;
V_16 -> V_87 . V_101 . V_106 =
V_16 -> V_87 . V_88 . V_93 *
V_16 -> V_87 . V_88 . V_91 *
V_16 -> V_87 . V_88 . V_89 / 8 *
4 / 1000 ;
return 0 ;
}
int F_55 ( struct V_13 * V_14 , struct V_12 * V_16 )
{
struct V_107 * V_108 = & V_16 -> V_87 ;
struct V_109 * V_110 = & V_16 -> V_110 ;
T_1 V_5 ;
int V_48 ;
V_5 = F_1 ( V_111 ,
sizeof( * V_108 ) + sizeof( V_56 ) ,
true , V_16 -> V_4 ) ;
V_48 = F_35 ( V_14 , V_5 , V_108 , sizeof( * V_108 ) ,
V_110 , sizeof( * V_110 ) ) ;
if ( V_48 < 0 ) {
F_13 ( V_14 -> V_29 , L_5 ) ;
return V_48 ;
}
V_16 -> V_112 = true ;
return 0 ;
}
int F_56 ( struct V_13 * V_14 , struct V_12 * V_16 )
{
T_1 V_5 ;
int V_48 = 0 ;
struct V_18 * V_19 = V_14 -> V_20 ;
unsigned long V_37 ;
if ( ! V_16 -> V_112 )
goto V_60;
V_5 = F_1 ( V_64 , 0 , false , V_16 -> V_4 ) ;
V_48 = F_35 ( V_14 , V_5 , NULL , 0 , NULL , 0 ) ;
if ( V_48 < 0 ) {
F_13 ( V_14 -> V_29 , L_6 ,
V_16 -> V_4 ) ;
return - V_113 ;
}
V_16 -> V_112 = false ;
V_60:
F_20 ( & V_19 -> V_38 , V_37 ) ;
F_17 ( & V_16 -> V_84 ) ;
F_57 ( V_16 ) ;
F_21 ( & V_19 -> V_38 , V_37 ) ;
return V_48 ;
}
static int F_58 ( struct V_13 * V_14 , int type ,
int V_15 , int V_44 )
{
T_1 V_5 ;
V_5 = F_1 ( type , 0 , false , V_15 ) ;
if ( V_44 )
return F_35 ( V_14 , V_5 , NULL , 0 , NULL , 0 ) ;
else
return F_36 ( V_14 , V_5 , NULL , 0 ) ;
}
int F_59 ( struct V_13 * V_14 , struct V_12 * V_16 ,
V_56 V_114 )
{
struct V_115 V_116 ;
void * V_117 ;
T_4 V_105 ;
T_1 V_5 ;
int V_48 ;
V_116 . V_118 = V_114 ;
V_5 = F_1 ( V_66 ,
sizeof( V_116 ) + sizeof( V_56 ) ,
true , V_16 -> V_4 ) ;
V_117 = & V_116 ;
V_105 = sizeof( V_116 ) ;
V_48 = F_36 ( V_14 , V_5 , V_117 , V_105 ) ;
if ( V_48 < 0 )
F_13 ( V_14 -> V_29 , L_7 ,
V_16 -> V_4 ) ;
return V_48 ;
}
int F_60 ( struct V_13 * V_14 , struct V_12 * V_16 )
{
int V_48 ;
if ( ! V_16 -> V_112 )
return 0 ;
V_48 = F_58 ( V_14 , V_62 ,
V_16 -> V_4 , 0 ) ;
if ( V_48 < 0 )
F_13 ( V_14 -> V_29 , L_8 ,
V_16 -> V_4 ) ;
return V_48 ;
}
int F_61 ( struct V_13 * V_14 , struct V_12 * V_16 )
{
int V_48 ;
V_48 = F_58 ( V_14 , V_63 ,
V_16 -> V_4 , 0 ) ;
if ( V_48 < 0 )
F_13 ( V_14 -> V_29 , L_9 ,
V_16 -> V_4 ) ;
return V_48 ;
}
int F_62 ( struct V_13 * V_14 , struct V_12 * V_16 )
{
int V_48 ;
V_48 = F_58 ( V_14 , V_67 ,
V_16 -> V_4 , 0 ) ;
if ( V_48 < 0 )
F_13 ( V_14 -> V_29 , L_10 ,
V_16 -> V_4 ) ;
return V_48 ;
}
int F_63 ( struct V_13 * V_14 ,
struct V_12 * V_16 , int V_100 )
{
struct V_18 * V_19 = V_14 -> V_20 ;
struct V_119 V_120 ;
T_3 V_4 = V_16 -> V_4 ;
V_56 V_121 ;
V_121 = V_122 + V_4 * sizeof( V_120 ) ;
F_64 ( & V_120 ,
V_19 -> V_104 . V_123 + V_121 , sizeof( V_120 ) ) ;
return F_65 ( V_120 . V_124 , V_100 ) ;
}
static int F_66 ( struct V_13 * V_14 )
{
struct V_30 * V_31 ;
int V_125 ;
V_14 -> V_31 = F_48 ( sizeof( * V_31 ) * V_126 , V_83 ) ;
if ( V_14 -> V_31 == NULL )
return - V_127 ;
for ( V_125 = 0 ; V_125 < V_126 ; V_125 ++ ) {
F_67 ( & V_14 -> V_31 [ V_125 ] . V_45 ) ;
F_49 ( & V_14 -> V_31 [ V_125 ] . V_33 , & V_14 -> V_32 ) ;
}
return 0 ;
}
struct V_18 * F_68 ( struct V_13 * V_14 )
{
return V_14 -> V_20 ;
}
int F_69 ( struct V_128 * V_29 , struct V_129 * V_73 )
{
struct V_13 * V_14 = V_73 -> V_20 ;
F_42 ( V_14 -> V_29 , L_11 ) ;
F_70 ( V_14 -> V_20 ) ;
F_28 ( V_14 ) ;
F_42 ( V_14 -> V_29 , L_12 ) ;
return 0 ;
}
int F_71 ( struct V_128 * V_29 , struct V_129 * V_73 )
{
struct V_13 * V_14 = V_73 -> V_20 ;
F_42 ( V_14 -> V_29 , L_13 ) ;
F_72 ( V_14 -> V_130 ) ;
return 0 ;
}
int F_73 ( struct V_128 * V_29 , struct V_129 * V_73 )
{
struct V_13 * V_14 = V_73 -> V_20 ;
int V_48 ;
F_42 ( V_14 -> V_29 , L_14 ) ;
F_70 ( V_14 -> V_20 ) ;
V_48 = F_74 ( V_14 -> V_130 ) ;
if ( V_48 < 0 ) {
F_13 ( V_29 , L_15 ) ;
return V_48 ;
}
V_14 -> V_68 = false ;
F_75 ( V_14 -> V_20 ) ;
F_42 ( V_14 -> V_29 , L_16 ) ;
return 0 ;
}
int F_76 ( struct V_128 * V_29 , struct V_129 * V_73 )
{
struct V_13 * V_14 = V_73 -> V_20 ;
int V_131 ;
F_42 ( V_14 -> V_29 , L_17 ) ;
V_131 = F_31 ( V_14 -> V_69 , V_14 -> V_68 ,
F_32 ( V_132 ) ) ;
if ( V_131 == 0 ) {
F_13 ( V_14 -> V_29 , L_18 ) ;
return - V_133 ;
}
F_42 ( V_14 -> V_29 , L_19 ) ;
return 0 ;
}
int F_77 ( struct V_128 * V_29 , struct V_129 * V_73 )
{
struct V_13 * V_14 ;
struct V_134 * V_135 ;
int V_131 ;
F_42 ( V_29 , L_20 ) ;
V_14 = F_78 ( V_29 , sizeof( * V_14 ) , V_83 ) ;
if ( V_14 == NULL )
return - V_127 ;
V_14 -> V_29 = V_29 ;
F_79 ( & V_14 -> V_85 ) ;
F_79 ( & V_14 -> V_39 ) ;
F_79 ( & V_14 -> V_40 ) ;
F_79 ( & V_14 -> V_32 ) ;
F_67 ( & V_14 -> V_69 ) ;
F_67 ( & V_14 -> V_136 ) ;
V_131 = F_66 ( V_14 ) ;
if ( V_131 < 0 )
return - V_127 ;
F_80 ( & V_14 -> V_57 ) ;
V_14 -> V_137 = F_81 ( V_138 ,
& V_14 -> V_57 , L_21 ,
F_82 ( V_14 -> V_29 ) ) ;
if ( F_83 ( V_14 -> V_137 ) ) {
V_131 = F_84 ( V_14 -> V_137 ) ;
F_13 ( V_14 -> V_29 , L_22 ) ;
goto V_139;
}
F_85 ( & V_14 -> V_36 , F_18 ) ;
V_140 . V_141 = V_14 ;
V_14 -> V_20 = F_86 ( V_29 , & V_140 , V_73 ) ;
if ( V_14 -> V_20 == NULL ) {
V_131 = - V_142 ;
goto V_143;
}
F_70 ( V_14 -> V_20 ) ;
V_135 = F_87 ( V_14 -> V_20 , V_73 -> V_130 , V_14 ) ;
if ( V_135 == NULL ) {
V_131 = - V_142 ;
F_13 ( V_29 , L_23 ) ;
goto V_144;
}
F_75 ( V_14 -> V_20 ) ;
V_131 = F_31 ( V_14 -> V_69 , V_14 -> V_68 ,
F_32 ( V_132 ) ) ;
if ( V_131 == 0 ) {
V_131 = - V_133 ;
F_13 ( V_14 -> V_29 , L_18 ) ;
goto V_145;
}
V_73 -> V_20 = V_14 ;
V_14 -> V_130 = V_135 ;
return 0 ;
V_145:
F_70 ( V_14 -> V_20 ) ;
F_88 ( V_135 ) ;
V_144:
F_89 ( V_14 -> V_20 ) ;
V_143:
F_90 ( V_14 -> V_137 ) ;
V_139:
F_57 ( V_14 -> V_31 ) ;
return V_131 ;
}
void F_91 ( struct V_128 * V_29 , struct V_129 * V_73 )
{
struct V_13 * V_14 = V_73 -> V_20 ;
F_70 ( V_14 -> V_20 ) ;
F_92 ( V_14 -> V_20 ) ;
F_89 ( V_14 -> V_20 ) ;
F_90 ( V_14 -> V_137 ) ;
F_57 ( V_14 -> V_31 ) ;
}
