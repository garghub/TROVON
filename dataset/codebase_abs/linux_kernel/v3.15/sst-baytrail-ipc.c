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
static int F_28 ( struct V_13 * V_14 , struct V_30 * V_31 ,
void * V_46 )
{
unsigned long V_37 ;
int V_47 ;
V_47 = F_29 ( V_31 -> V_45 , V_31 -> V_43 ,
F_30 ( V_48 ) ) ;
F_20 ( & V_14 -> V_20 -> V_38 , V_37 ) ;
if ( V_47 == 0 ) {
F_17 ( & V_31 -> V_33 ) ;
F_11 ( V_14 , L_2 ) ;
V_47 = - V_49 ;
} else {
if ( V_31 -> V_50 )
memcpy ( V_46 , V_31 -> V_46 , V_31 -> V_50 ) ;
V_47 = V_31 -> V_51 ;
}
F_26 ( & V_31 -> V_33 , & V_14 -> V_32 ) ;
F_21 ( & V_14 -> V_20 -> V_38 , V_37 ) ;
return V_47 ;
}
static int F_31 ( struct V_13 * V_14 , T_1 V_5 ,
void * V_41 , T_4 V_52 ,
void * V_46 , T_4 V_53 , int V_44 )
{
unsigned long V_37 ;
struct V_30 * V_31 ;
F_20 ( & V_14 -> V_20 -> V_38 , V_37 ) ;
V_31 = F_14 ( V_14 ) ;
if ( V_31 == NULL ) {
F_21 ( & V_14 -> V_20 -> V_38 , V_37 ) ;
return - V_54 ;
}
V_31 -> V_5 = V_5 ;
V_31 -> V_42 = V_52 ;
V_31 -> V_50 = V_53 ;
V_31 -> V_44 = V_44 ;
V_31 -> V_51 = 0 ;
V_31 -> V_43 = false ;
if ( V_52 ) {
* ( V_55 * ) V_31 -> V_41 = ( V_55 ) ( V_5 & ( V_55 ) - 1 ) ;
memcpy ( V_31 -> V_41 + sizeof( V_55 ) , V_41 , V_52 ) ;
V_31 -> V_42 += sizeof( V_55 ) ;
}
F_26 ( & V_31 -> V_33 , & V_14 -> V_39 ) ;
F_21 ( & V_14 -> V_20 -> V_38 , V_37 ) ;
F_32 ( & V_14 -> V_56 , & V_14 -> V_36 ) ;
if ( V_44 )
return F_28 ( V_14 , V_31 , V_46 ) ;
else
return 0 ;
}
static inline int F_33 ( struct V_13 * V_14 , T_1 V_5 ,
void * V_41 , T_4 V_52 ,
void * V_46 , T_4 V_53 )
{
return F_31 ( V_14 , V_5 , V_41 , V_52 ,
V_46 , V_53 , 1 ) ;
}
static inline int F_34 ( struct V_13 * V_14 , T_1 V_5 ,
void * V_41 , T_4 V_52 )
{
return F_31 ( V_14 , V_5 , V_41 , V_52 ,
NULL , 0 , 0 ) ;
}
static struct V_30 * F_35 ( struct V_13 * V_14 ,
T_1 V_5 )
{
struct V_30 * V_31 = NULL , * V_57 ;
T_1 V_58 ;
V_58 = V_7 |
V_9 << V_8 ;
V_5 &= V_58 ;
if ( F_15 ( & V_14 -> V_40 ) ) {
F_13 ( V_14 -> V_29 ,
L_3 , V_5 ) ;
goto V_59;
}
F_10 (_msg, &byt->rx_list, list) {
if ( ( V_57 -> V_5 & V_58 ) == V_5 ) {
V_31 = V_57 ;
break;
}
}
V_59:
return V_31 ;
}
static void F_36 ( struct V_13 * V_14 , struct V_30 * V_31 )
{
struct V_12 * V_16 ;
T_1 V_5 = V_31 -> V_5 ;
T_3 V_15 = F_7 ( V_5 ) ;
T_3 V_60 = F_6 ( V_5 ) ;
V_16 = F_9 ( V_14 , V_15 ) ;
if ( V_16 == NULL )
return;
switch ( V_60 ) {
case V_61 :
case V_62 :
case V_63 :
V_16 -> V_64 = false ;
break;
case V_65 :
case V_66 :
V_16 -> V_64 = true ;
break;
}
}
static int F_37 ( struct V_13 * V_14 , T_1 V_5 )
{
struct V_30 * V_31 ;
V_31 = F_35 ( V_14 , V_5 ) ;
if ( V_31 == NULL )
return 1 ;
if ( V_5 & F_4 ( true ) ) {
V_31 -> V_50 = F_8 ( V_5 ) ;
F_38 ( V_14 -> V_20 , V_31 -> V_46 , V_31 -> V_50 ) ;
}
F_36 ( V_14 , V_31 ) ;
F_17 ( & V_31 -> V_33 ) ;
F_25 ( V_14 , V_31 ) ;
return 1 ;
}
static void F_39 ( struct V_13 * V_14 , T_1 V_5 )
{
F_40 ( V_14 -> V_29 , L_4 , V_5 ) ;
V_14 -> V_67 = true ;
F_27 ( & V_14 -> V_68 ) ;
}
static int F_41 ( struct V_13 * V_14 ,
unsigned long * V_37 )
{
struct V_18 * V_19 = V_14 -> V_20 ;
struct V_12 * V_16 ;
T_1 V_5 ;
T_3 V_1 , V_15 ;
int V_69 = 1 ;
V_5 = F_12 ( V_19 , V_27 ) ;
V_1 = F_6 ( V_5 ) ;
switch ( V_1 ) {
case V_70 :
V_15 = F_7 ( V_5 ) ;
V_16 = F_9 ( V_14 , V_15 ) ;
if ( V_16 && V_16 -> V_64 && V_16 -> V_71 ) {
F_21 ( & V_19 -> V_38 , * V_37 ) ;
V_16 -> V_71 ( V_16 , V_16 -> V_72 ) ;
F_20 ( & V_19 -> V_38 , * V_37 ) ;
}
break;
case V_73 :
F_39 ( V_14 , V_5 ) ;
break;
}
return V_69 ;
}
static T_5 F_42 ( int V_74 , void * V_75 )
{
struct V_18 * V_19 = (struct V_18 * ) V_75 ;
struct V_13 * V_14 = F_43 ( V_19 ) ;
T_1 V_5 ;
unsigned long V_37 ;
F_20 ( & V_19 -> V_38 , V_37 ) ;
V_5 = F_12 ( V_19 , V_27 ) ;
if ( V_5 & V_76 ) {
if ( V_5 & V_77 ) {
F_41 ( V_14 , & V_37 ) ;
} else {
F_37 ( V_14 , V_5 ) ;
}
F_44 ( V_19 , V_27 ,
V_78 | V_76 |
F_5 ( V_11 ) ,
V_78 ) ;
F_44 ( V_19 , V_28 ,
V_79 , 0 ) ;
}
F_21 ( & V_19 -> V_38 , V_37 ) ;
F_32 ( & V_14 -> V_56 , & V_14 -> V_36 ) ;
return V_80 ;
}
struct V_12 * F_45 ( struct V_13 * V_14 , int V_81 ,
V_55 (* V_71)( struct V_12 * V_16 , void * V_2 ) ,
void * V_2 )
{
struct V_12 * V_16 ;
struct V_18 * V_19 = V_14 -> V_20 ;
unsigned long V_37 ;
V_16 = F_46 ( sizeof( * V_16 ) , V_82 ) ;
if ( V_16 == NULL )
return NULL ;
F_20 ( & V_19 -> V_38 , V_37 ) ;
F_47 ( & V_16 -> V_83 , & V_14 -> V_84 ) ;
V_16 -> V_71 = V_71 ;
V_16 -> V_72 = V_2 ;
V_16 -> V_14 = V_14 ;
V_16 -> V_4 = V_81 ;
F_21 ( & V_19 -> V_38 , V_37 ) ;
return V_16 ;
}
int F_48 ( struct V_13 * V_14 , struct V_12 * V_16 ,
int V_85 )
{
V_16 -> V_86 . V_87 . V_88 = V_85 ;
return 0 ;
}
int F_49 ( struct V_13 * V_14 ,
struct V_12 * V_16 , T_3 V_89 )
{
V_16 -> V_86 . V_87 . V_90 = V_89 ;
return 0 ;
}
int F_50 ( struct V_13 * V_14 , struct V_12 * V_16 ,
unsigned int V_91 )
{
V_16 -> V_86 . V_87 . V_92 = V_91 ;
return 0 ;
}
int F_51 ( struct V_13 * V_14 , struct V_12 * V_16 ,
int V_93 , int V_94 , int V_95 )
{
V_16 -> V_86 . V_96 . V_93 = V_93 ;
V_16 -> V_86 . V_96 . V_96 = V_94 ;
V_16 -> V_86 . V_96 . V_95 = V_95 ;
V_16 -> V_86 . V_96 . V_97 = 0xc ;
return 0 ;
}
int F_52 ( struct V_13 * V_14 , struct V_12 * V_16 ,
T_6 V_98 , T_6 V_99 )
{
V_16 -> V_86 . V_100 . V_101 = 1 ;
V_16 -> V_86 . V_100 . V_102 [ 0 ] . V_103 = V_98 ;
V_16 -> V_86 . V_100 . V_102 [ 0 ] . V_104 = V_99 ;
V_16 -> V_86 . V_100 . V_105 =
V_16 -> V_86 . V_87 . V_92 *
V_16 -> V_86 . V_87 . V_90 *
V_16 -> V_86 . V_87 . V_88 / 8 *
4 / 1000 ;
return 0 ;
}
int F_53 ( struct V_13 * V_14 , struct V_12 * V_16 )
{
struct V_106 * V_107 = & V_16 -> V_86 ;
struct V_108 * V_109 = & V_16 -> V_109 ;
T_1 V_5 ;
int V_47 ;
V_5 = F_1 ( V_110 ,
sizeof( * V_107 ) + sizeof( V_55 ) ,
true , V_16 -> V_4 ) ;
V_47 = F_33 ( V_14 , V_5 , V_107 , sizeof( * V_107 ) ,
V_109 , sizeof( * V_109 ) ) ;
if ( V_47 < 0 ) {
F_13 ( V_14 -> V_29 , L_5 ) ;
return V_47 ;
}
V_16 -> V_111 = true ;
return 0 ;
}
int F_54 ( struct V_13 * V_14 , struct V_12 * V_16 )
{
T_1 V_5 ;
int V_47 = 0 ;
struct V_18 * V_19 = V_14 -> V_20 ;
unsigned long V_37 ;
if ( ! V_16 -> V_111 )
goto V_59;
V_5 = F_1 ( V_63 , 0 , false , V_16 -> V_4 ) ;
V_47 = F_33 ( V_14 , V_5 , NULL , 0 , NULL , 0 ) ;
if ( V_47 < 0 ) {
F_13 ( V_14 -> V_29 , L_6 ,
V_16 -> V_4 ) ;
return - V_112 ;
}
V_16 -> V_111 = false ;
V_59:
F_20 ( & V_19 -> V_38 , V_37 ) ;
F_17 ( & V_16 -> V_83 ) ;
F_55 ( V_16 ) ;
F_21 ( & V_19 -> V_38 , V_37 ) ;
return V_47 ;
}
static int F_56 ( struct V_13 * V_14 , int type ,
int V_15 , int V_44 )
{
struct V_113 V_114 ;
T_1 V_5 ;
void * V_115 = NULL ;
T_4 V_104 = 0 ;
if ( type != V_65 ) {
V_5 = F_1 ( type , 0 , false , V_15 ) ;
} else {
V_114 . V_116 = 0 ;
V_5 = F_1 ( V_65 ,
sizeof( V_114 ) + sizeof( V_55 ) ,
true , V_15 ) ;
V_115 = & V_114 ;
V_104 = sizeof( V_114 ) ;
}
if ( V_44 )
return F_33 ( V_14 , V_5 ,
V_115 , V_104 , NULL , 0 ) ;
else
return F_34 ( V_14 , V_5 , V_115 , V_104 ) ;
}
int F_57 ( struct V_13 * V_14 , struct V_12 * V_16 )
{
int V_47 ;
V_47 = F_56 ( V_14 , V_65 ,
V_16 -> V_4 , 0 ) ;
if ( V_47 < 0 )
F_13 ( V_14 -> V_29 , L_7 ,
V_16 -> V_4 ) ;
return V_47 ;
}
int F_58 ( struct V_13 * V_14 , struct V_12 * V_16 )
{
int V_47 ;
if ( ! V_16 -> V_111 )
return 0 ;
V_47 = F_56 ( V_14 , V_61 ,
V_16 -> V_4 , 0 ) ;
if ( V_47 < 0 )
F_13 ( V_14 -> V_29 , L_8 ,
V_16 -> V_4 ) ;
return V_47 ;
}
int F_59 ( struct V_13 * V_14 , struct V_12 * V_16 )
{
int V_47 ;
V_47 = F_56 ( V_14 , V_62 ,
V_16 -> V_4 , 0 ) ;
if ( V_47 < 0 )
F_13 ( V_14 -> V_29 , L_9 ,
V_16 -> V_4 ) ;
return V_47 ;
}
int F_60 ( struct V_13 * V_14 , struct V_12 * V_16 )
{
int V_47 ;
V_47 = F_56 ( V_14 , V_66 ,
V_16 -> V_4 , 0 ) ;
if ( V_47 < 0 )
F_13 ( V_14 -> V_29 , L_10 ,
V_16 -> V_4 ) ;
return V_47 ;
}
int F_61 ( struct V_13 * V_14 ,
struct V_12 * V_16 , int V_99 )
{
struct V_18 * V_19 = V_14 -> V_20 ;
struct V_117 V_118 ;
T_3 V_4 = V_16 -> V_4 ;
V_55 V_119 ;
V_119 = V_120 + V_4 * sizeof( V_118 ) ;
F_62 ( & V_118 ,
V_19 -> V_103 . V_121 + V_119 , sizeof( V_118 ) ) ;
return F_63 ( V_118 . V_122 , V_99 ) ;
}
static int F_64 ( struct V_13 * V_14 )
{
struct V_30 * V_31 ;
int V_123 ;
V_14 -> V_31 = F_46 ( sizeof( * V_31 ) * V_124 , V_82 ) ;
if ( V_14 -> V_31 == NULL )
return - V_125 ;
for ( V_123 = 0 ; V_123 < V_124 ; V_123 ++ ) {
F_65 ( & V_14 -> V_31 [ V_123 ] . V_45 ) ;
F_47 ( & V_14 -> V_31 [ V_123 ] . V_33 , & V_14 -> V_32 ) ;
}
return 0 ;
}
struct V_18 * F_66 ( struct V_13 * V_14 )
{
return V_14 -> V_20 ;
}
int F_67 ( struct V_126 * V_29 , struct V_127 * V_72 )
{
struct V_13 * V_14 ;
struct V_128 * V_129 ;
int V_130 ;
F_40 ( V_29 , L_11 ) ;
V_14 = F_68 ( V_29 , sizeof( * V_14 ) , V_82 ) ;
if ( V_14 == NULL )
return - V_125 ;
V_14 -> V_29 = V_29 ;
F_69 ( & V_14 -> V_84 ) ;
F_69 ( & V_14 -> V_39 ) ;
F_69 ( & V_14 -> V_40 ) ;
F_69 ( & V_14 -> V_32 ) ;
F_65 ( & V_14 -> V_68 ) ;
F_65 ( & V_14 -> V_131 ) ;
V_130 = F_64 ( V_14 ) ;
if ( V_130 < 0 )
return - V_125 ;
F_70 ( & V_14 -> V_56 ) ;
V_14 -> V_132 = F_71 ( V_133 ,
& V_14 -> V_56 ,
F_72 ( V_14 -> V_29 ) ) ;
if ( F_73 ( V_14 -> V_132 ) ) {
V_130 = F_74 ( V_14 -> V_132 ) ;
F_13 ( V_14 -> V_29 , L_12 ) ;
goto V_134;
}
F_75 ( & V_14 -> V_36 , F_18 ) ;
V_135 . V_136 = V_14 ;
V_14 -> V_20 = F_76 ( V_29 , & V_135 , V_72 ) ;
if ( V_14 -> V_20 == NULL ) {
V_130 = - V_137 ;
goto V_134;
}
F_77 ( V_14 -> V_20 ) ;
V_129 = F_78 ( V_14 -> V_20 , V_72 -> V_138 , V_14 ) ;
if ( V_129 == NULL ) {
V_130 = - V_137 ;
F_13 ( V_29 , L_13 ) ;
goto V_139;
}
F_79 ( V_14 -> V_20 ) ;
V_130 = F_29 ( V_14 -> V_68 , V_14 -> V_67 ,
F_30 ( V_140 ) ) ;
if ( V_130 == 0 ) {
V_130 = - V_141 ;
F_13 ( V_14 -> V_29 , L_14 ) ;
goto V_142;
}
V_72 -> V_20 = V_14 ;
return 0 ;
V_142:
F_77 ( V_14 -> V_20 ) ;
F_80 ( V_129 ) ;
V_139:
F_81 ( V_14 -> V_20 ) ;
V_134:
F_55 ( V_14 -> V_31 ) ;
return V_130 ;
}
void F_82 ( struct V_126 * V_29 , struct V_127 * V_72 )
{
struct V_13 * V_14 = V_72 -> V_20 ;
F_77 ( V_14 -> V_20 ) ;
F_83 ( V_14 -> V_20 ) ;
F_81 ( V_14 -> V_20 ) ;
F_55 ( V_14 -> V_31 ) ;
}
