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
static void F_11 ( struct V_13 * V_14 , struct V_17 * V_18 )
{
struct V_12 * V_16 ;
T_1 V_5 = V_18 -> V_5 ;
T_3 V_15 = F_7 ( V_5 ) ;
T_3 V_19 = F_6 ( V_5 ) ;
V_16 = F_9 ( V_14 , V_15 ) ;
if ( V_16 == NULL )
return;
switch ( V_19 ) {
case V_20 :
case V_21 :
case V_22 :
V_16 -> V_23 = false ;
break;
case V_24 :
case V_25 :
V_16 -> V_23 = true ;
break;
}
}
static int F_12 ( struct V_13 * V_14 , T_1 V_5 )
{
struct V_17 * V_18 ;
V_18 = F_13 ( & V_14 -> V_26 , V_5 ) ;
if ( V_18 == NULL )
return 1 ;
if ( V_5 & F_4 ( true ) ) {
V_18 -> V_27 = F_8 ( V_5 ) ;
F_14 ( V_14 -> V_28 , V_18 -> V_29 , V_18 -> V_27 ) ;
}
F_11 ( V_14 , V_18 ) ;
F_15 ( & V_18 -> V_30 ) ;
F_16 ( & V_14 -> V_26 , V_18 ) ;
return 1 ;
}
static void F_17 ( struct V_13 * V_14 , T_1 V_5 )
{
F_18 ( V_14 -> V_31 , L_1 , V_5 ) ;
V_14 -> V_32 = true ;
F_19 ( & V_14 -> V_33 ) ;
}
static int F_20 ( struct V_13 * V_14 ,
unsigned long * V_34 )
{
struct V_35 * V_36 = V_14 -> V_28 ;
struct V_12 * V_16 ;
T_1 V_5 ;
T_3 V_1 , V_15 ;
int V_37 = 1 ;
V_5 = F_21 ( V_36 , V_38 ) ;
V_1 = F_6 ( V_5 ) ;
switch ( V_1 ) {
case V_39 :
V_15 = F_7 ( V_5 ) ;
V_16 = F_9 ( V_14 , V_15 ) ;
if ( V_16 && V_16 -> V_23 && V_16 -> V_40 ) {
F_22 ( & V_36 -> V_41 , * V_34 ) ;
V_16 -> V_40 ( V_16 , V_16 -> V_42 ) ;
F_23 ( & V_36 -> V_41 , * V_34 ) ;
}
break;
case V_43 :
F_17 ( V_14 , V_5 ) ;
break;
}
return V_37 ;
}
static T_4 F_24 ( int V_44 , void * V_45 )
{
struct V_35 * V_36 = (struct V_35 * ) V_45 ;
struct V_13 * V_14 = F_25 ( V_36 ) ;
struct V_46 * V_26 = & V_14 -> V_26 ;
T_1 V_5 ;
unsigned long V_34 ;
F_23 ( & V_36 -> V_41 , V_34 ) ;
V_5 = F_21 ( V_36 , V_38 ) ;
if ( V_5 & V_47 ) {
if ( V_5 & V_48 ) {
F_20 ( V_14 , & V_34 ) ;
} else {
F_12 ( V_14 , V_5 ) ;
}
F_26 ( V_36 , V_38 ,
V_49 | V_47 |
F_5 ( V_11 ) ,
V_49 ) ;
F_26 ( V_36 , V_50 ,
V_51 , 0 ) ;
}
F_22 ( & V_36 -> V_41 , V_34 ) ;
F_27 ( & V_26 -> V_52 , & V_26 -> V_53 ) ;
return V_54 ;
}
struct V_12 * F_28 ( struct V_13 * V_14 , int V_55 ,
T_5 (* V_40)( struct V_12 * V_16 , void * V_2 ) ,
void * V_2 )
{
struct V_12 * V_16 ;
struct V_35 * V_36 = V_14 -> V_28 ;
unsigned long V_34 ;
V_16 = F_29 ( sizeof( * V_16 ) , V_56 ) ;
if ( V_16 == NULL )
return NULL ;
F_23 ( & V_36 -> V_41 , V_34 ) ;
F_30 ( & V_16 -> V_57 , & V_14 -> V_58 ) ;
V_16 -> V_40 = V_40 ;
V_16 -> V_42 = V_2 ;
V_16 -> V_14 = V_14 ;
V_16 -> V_4 = V_55 ;
F_22 ( & V_36 -> V_41 , V_34 ) ;
return V_16 ;
}
int F_31 ( struct V_13 * V_14 , struct V_12 * V_16 ,
int V_59 )
{
V_16 -> V_60 . V_61 . V_62 = V_59 ;
return 0 ;
}
int F_32 ( struct V_13 * V_14 ,
struct V_12 * V_16 , T_3 V_63 )
{
V_16 -> V_60 . V_61 . V_64 = V_63 ;
return 0 ;
}
int F_33 ( struct V_13 * V_14 , struct V_12 * V_16 ,
unsigned int V_65 )
{
V_16 -> V_60 . V_61 . V_66 = V_65 ;
return 0 ;
}
int F_34 ( struct V_13 * V_14 , struct V_12 * V_16 ,
int V_67 , int V_68 , int V_69 )
{
V_16 -> V_60 . V_70 . V_67 = V_67 ;
V_16 -> V_60 . V_70 . V_70 = V_68 ;
V_16 -> V_60 . V_70 . V_69 = V_69 ;
V_16 -> V_60 . V_70 . V_71 = 0xc ;
return 0 ;
}
int F_35 ( struct V_13 * V_14 , struct V_12 * V_16 ,
T_6 V_72 , T_6 V_73 )
{
V_16 -> V_60 . V_74 . V_75 = 1 ;
V_16 -> V_60 . V_74 . V_76 [ 0 ] . V_77 = V_72 ;
V_16 -> V_60 . V_74 . V_76 [ 0 ] . V_78 = V_73 ;
V_16 -> V_60 . V_74 . V_79 =
V_16 -> V_60 . V_61 . V_66 *
V_16 -> V_60 . V_61 . V_64 *
V_16 -> V_60 . V_61 . V_62 / 8 *
4 / 1000 ;
return 0 ;
}
int F_36 ( struct V_13 * V_14 , struct V_12 * V_16 )
{
struct V_80 * V_81 = & V_16 -> V_60 ;
struct V_82 * V_83 = & V_16 -> V_83 ;
T_1 V_5 ;
int V_84 ;
V_5 = F_1 ( V_85 ,
sizeof( * V_81 ) + sizeof( T_5 ) ,
true , V_16 -> V_4 ) ;
V_84 = F_37 ( & V_14 -> V_26 , V_5 , V_81 ,
sizeof( * V_81 ) ,
V_83 , sizeof( * V_83 ) ) ;
if ( V_84 < 0 ) {
F_38 ( V_14 -> V_31 , L_2 ) ;
return V_84 ;
}
V_16 -> V_86 = true ;
return 0 ;
}
int F_39 ( struct V_13 * V_14 , struct V_12 * V_16 )
{
T_1 V_5 ;
int V_84 = 0 ;
struct V_35 * V_36 = V_14 -> V_28 ;
unsigned long V_34 ;
if ( ! V_16 -> V_86 )
goto V_87;
V_5 = F_1 ( V_22 , 0 , false , V_16 -> V_4 ) ;
V_84 = F_37 ( & V_14 -> V_26 , V_5 , NULL , 0 , NULL , 0 ) ;
if ( V_84 < 0 ) {
F_38 ( V_14 -> V_31 , L_3 ,
V_16 -> V_4 ) ;
return - V_88 ;
}
V_16 -> V_86 = false ;
V_87:
F_23 ( & V_36 -> V_41 , V_34 ) ;
F_15 ( & V_16 -> V_57 ) ;
F_40 ( V_16 ) ;
F_22 ( & V_36 -> V_41 , V_34 ) ;
return V_84 ;
}
static int F_41 ( struct V_13 * V_14 , int type ,
int V_15 , int V_89 )
{
T_1 V_5 ;
V_5 = F_1 ( type , 0 , false , V_15 ) ;
if ( V_89 )
return F_37 ( & V_14 -> V_26 , V_5 , NULL ,
0 , NULL , 0 ) ;
else
return F_42 ( & V_14 -> V_26 , V_5 ,
NULL , 0 ) ;
}
int F_43 ( struct V_13 * V_14 , struct V_12 * V_16 ,
T_5 V_90 )
{
struct V_91 V_92 ;
void * V_93 ;
T_7 V_78 ;
T_1 V_5 ;
int V_84 ;
V_92 . V_94 = V_90 ;
V_5 = F_1 ( V_24 ,
sizeof( V_92 ) + sizeof( T_5 ) ,
true , V_16 -> V_4 ) ;
V_93 = & V_92 ;
V_78 = sizeof( V_92 ) ;
V_84 = F_42 ( & V_14 -> V_26 , V_5 , V_93 , V_78 ) ;
if ( V_84 < 0 )
F_38 ( V_14 -> V_31 , L_4 ,
V_16 -> V_4 ) ;
return V_84 ;
}
int F_44 ( struct V_13 * V_14 , struct V_12 * V_16 )
{
int V_84 ;
if ( ! V_16 -> V_86 )
return 0 ;
V_84 = F_41 ( V_14 , V_20 ,
V_16 -> V_4 , 0 ) ;
if ( V_84 < 0 )
F_38 ( V_14 -> V_31 , L_5 ,
V_16 -> V_4 ) ;
return V_84 ;
}
int F_45 ( struct V_13 * V_14 , struct V_12 * V_16 )
{
int V_84 ;
V_84 = F_41 ( V_14 , V_21 ,
V_16 -> V_4 , 0 ) ;
if ( V_84 < 0 )
F_38 ( V_14 -> V_31 , L_6 ,
V_16 -> V_4 ) ;
return V_84 ;
}
int F_46 ( struct V_13 * V_14 , struct V_12 * V_16 )
{
int V_84 ;
V_84 = F_41 ( V_14 , V_25 ,
V_16 -> V_4 , 0 ) ;
if ( V_84 < 0 )
F_38 ( V_14 -> V_31 , L_7 ,
V_16 -> V_4 ) ;
return V_84 ;
}
int F_47 ( struct V_13 * V_14 ,
struct V_12 * V_16 , int V_73 )
{
struct V_35 * V_36 = V_14 -> V_28 ;
struct V_95 V_96 ;
T_3 V_4 = V_16 -> V_4 ;
T_5 V_97 ;
V_97 = V_98 + V_4 * sizeof( V_96 ) ;
F_48 ( & V_96 ,
V_36 -> V_77 . V_99 + V_97 , sizeof( V_96 ) ) ;
return F_49 ( V_96 . V_100 , V_73 ) ;
}
struct V_35 * F_50 ( struct V_13 * V_14 )
{
return V_14 -> V_28 ;
}
int F_51 ( struct V_101 * V_31 , struct V_102 * V_42 )
{
struct V_13 * V_14 = V_42 -> V_28 ;
F_18 ( V_14 -> V_31 , L_8 ) ;
F_52 ( V_14 -> V_28 ) ;
F_53 ( & V_14 -> V_26 ) ;
F_18 ( V_14 -> V_31 , L_9 ) ;
F_18 ( V_14 -> V_31 , L_10 ) ;
F_54 ( V_14 -> V_103 ) ;
return 0 ;
}
int F_55 ( struct V_101 * V_31 , struct V_102 * V_42 )
{
struct V_13 * V_14 = V_42 -> V_28 ;
int V_84 ;
F_18 ( V_14 -> V_31 , L_11 ) ;
F_52 ( V_14 -> V_28 ) ;
V_84 = F_56 ( V_14 -> V_103 ) ;
if ( V_84 < 0 ) {
F_38 ( V_31 , L_12 ) ;
return V_84 ;
}
V_14 -> V_32 = false ;
F_57 ( V_14 -> V_28 ) ;
F_18 ( V_14 -> V_31 , L_13 ) ;
return 0 ;
}
int F_58 ( struct V_101 * V_31 , struct V_102 * V_42 )
{
struct V_13 * V_14 = V_42 -> V_28 ;
int V_104 ;
F_18 ( V_14 -> V_31 , L_14 ) ;
V_104 = F_59 ( V_14 -> V_33 , V_14 -> V_32 ,
F_60 ( V_105 ) ) ;
if ( V_104 == 0 ) {
F_38 ( V_14 -> V_31 , L_15 ) ;
return - V_106 ;
}
F_18 ( V_14 -> V_31 , L_16 ) ;
return 0 ;
}
static void F_61 ( struct V_46 * V_26 , struct V_17 * V_18 )
{
if ( V_18 -> V_5 & F_4 ( true ) )
F_62 ( V_26 -> V_28 , V_18 -> V_107 , V_18 -> V_108 ) ;
F_63 ( V_26 -> V_28 , V_109 , V_18 -> V_5 ) ;
}
static void F_64 ( struct V_46 * V_26 , const char * V_110 )
{
struct V_35 * V_36 = V_26 -> V_28 ;
T_1 V_111 , V_112 , V_113 , V_114 ;
V_114 = F_21 ( V_36 , V_109 ) ;
V_111 = F_21 ( V_36 , V_115 ) ;
V_112 = F_21 ( V_36 , V_38 ) ;
V_113 = F_21 ( V_36 , V_50 ) ;
F_38 ( V_26 -> V_31 ,
L_17 ,
V_110 , V_114 , V_111 , V_112 , V_113 ) ;
}
static void F_65 ( struct V_17 * V_18 , char * V_107 ,
T_7 V_108 )
{
* ( T_5 * ) V_18 -> V_107 = ( T_5 ) ( V_18 -> V_5 & ( T_5 ) - 1 ) ;
memcpy ( V_18 -> V_107 + sizeof( T_5 ) , V_107 , V_108 ) ;
V_18 -> V_108 += sizeof( T_5 ) ;
}
static T_1 F_66 ( T_1 V_5 , T_1 * V_116 )
{
* V_116 = V_7 |
V_9 << V_8 ;
V_5 &= * V_116 ;
return V_5 ;
}
static bool F_67 ( struct V_35 * V_28 )
{
T_1 V_114 ;
V_114 = F_68 ( V_28 , V_109 ) ;
return ( V_114 & ( V_117 | V_118 ) ) ;
}
int F_69 ( struct V_101 * V_31 , struct V_102 * V_42 )
{
struct V_13 * V_14 ;
struct V_46 * V_26 ;
struct V_119 * V_120 ;
struct V_121 V_122 ;
int V_104 ;
F_18 ( V_31 , L_18 ) ;
V_14 = F_70 ( V_31 , sizeof( * V_14 ) , V_56 ) ;
if ( V_14 == NULL )
return - V_123 ;
V_14 -> V_31 = V_31 ;
V_26 = & V_14 -> V_26 ;
V_26 -> V_31 = V_31 ;
V_26 -> V_124 . V_93 = F_61 ;
V_26 -> V_124 . V_125 = F_64 ;
V_26 -> V_124 . V_126 = F_65 ;
V_26 -> V_124 . V_127 = F_66 ;
V_26 -> V_124 . V_128 = F_67 ;
V_26 -> V_129 = V_130 ;
V_26 -> V_131 = V_130 ;
V_104 = F_71 ( V_26 ) ;
if ( V_104 != 0 )
goto V_132;
F_72 ( & V_14 -> V_58 ) ;
F_73 ( & V_14 -> V_33 ) ;
V_133 . V_134 = V_14 ;
V_14 -> V_28 = F_74 ( V_31 , & V_133 , V_42 ) ;
if ( V_14 -> V_28 == NULL ) {
V_104 = - V_135 ;
goto V_136;
}
V_26 -> V_28 = V_14 -> V_28 ;
F_52 ( V_14 -> V_28 ) ;
V_120 = F_75 ( V_14 -> V_28 , V_42 -> V_103 , V_14 ) ;
if ( V_120 == NULL ) {
V_104 = - V_135 ;
F_38 ( V_31 , L_19 ) ;
goto V_137;
}
F_57 ( V_14 -> V_28 ) ;
V_104 = F_59 ( V_14 -> V_33 , V_14 -> V_32 ,
F_60 ( V_105 ) ) ;
if ( V_104 == 0 ) {
V_104 = - V_106 ;
F_38 ( V_14 -> V_31 , L_15 ) ;
goto V_138;
}
F_14 ( V_14 -> V_28 , & V_122 , sizeof( V_122 ) ) ;
F_76 ( V_14 -> V_31 , L_20 ,
V_122 . V_139 . V_140 , V_122 . V_139 . V_141 ,
V_122 . V_139 . V_142 , V_122 . V_139 . type ) ;
F_76 ( V_14 -> V_31 , L_21 , V_122 . V_139 . type ) ;
F_76 ( V_14 -> V_31 , L_22 ,
V_122 . V_143 . V_144 , V_122 . V_143 . time ) ;
V_42 -> V_28 = V_14 ;
V_14 -> V_103 = V_120 ;
return 0 ;
V_138:
F_52 ( V_14 -> V_28 ) ;
F_77 ( V_120 ) ;
V_137:
F_78 ( V_14 -> V_28 ) ;
V_136:
F_79 ( V_26 ) ;
V_132:
return V_104 ;
}
void F_80 ( struct V_101 * V_31 , struct V_102 * V_42 )
{
struct V_13 * V_14 = V_42 -> V_28 ;
F_52 ( V_14 -> V_28 ) ;
F_81 ( V_14 -> V_28 ) ;
F_78 ( V_14 -> V_28 ) ;
F_79 ( & V_14 -> V_26 ) ;
}
