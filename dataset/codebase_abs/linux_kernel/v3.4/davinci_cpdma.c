static struct V_1 *
F_1 ( struct V_2 * V_3 , T_1 V_4 , T_1 V_5 ,
int V_6 , int V_7 )
{
int V_8 ;
struct V_1 * V_9 ;
V_9 = F_2 ( sizeof( * V_9 ) , V_10 ) ;
if ( ! V_9 )
return NULL ;
F_3 ( & V_9 -> V_11 ) ;
V_9 -> V_3 = V_3 ;
V_9 -> V_12 = V_6 ;
V_9 -> V_13 = F_4 ( sizeof( struct V_14 ) , V_7 ) ;
V_9 -> V_15 = V_6 / V_9 -> V_13 ;
V_8 = ( V_9 -> V_15 / V_16 ) * sizeof( long ) ;
V_9 -> V_17 = F_2 ( V_8 , V_10 ) ;
if ( ! V_9 -> V_17 )
goto V_18;
if ( V_4 ) {
V_9 -> V_4 = V_4 ;
V_9 -> V_19 = F_5 ( V_4 , V_6 ) ;
V_9 -> V_5 = V_5 ;
} else {
V_9 -> V_20 = F_6 ( V_3 , V_6 , & V_9 -> V_4 ,
V_10 ) ;
V_9 -> V_19 = V_9 -> V_20 ;
V_9 -> V_5 = V_9 -> V_4 ;
}
if ( V_9 -> V_19 )
return V_9 ;
V_18:
F_7 ( V_9 -> V_17 ) ;
F_7 ( V_9 ) ;
return NULL ;
}
static void F_8 ( struct V_1 * V_9 )
{
unsigned long V_21 ;
if ( ! V_9 )
return;
F_9 ( & V_9 -> V_11 , V_21 ) ;
F_10 ( V_9 -> V_22 ) ;
F_7 ( V_9 -> V_17 ) ;
if ( V_9 -> V_20 ) {
F_11 ( V_9 -> V_3 , V_9 -> V_12 , V_9 -> V_20 ,
V_9 -> V_4 ) ;
} else {
F_12 ( V_9 -> V_19 ) ;
}
F_13 ( & V_9 -> V_11 , V_21 ) ;
F_7 ( V_9 ) ;
}
static inline T_2 F_14 ( struct V_1 * V_9 ,
struct V_14 T_3 * V_23 )
{
if ( ! V_23 )
return 0 ;
return V_9 -> V_5 + ( V_24 T_2 ) V_23 -
( V_24 T_2 ) V_9 -> V_19 ;
}
static inline struct V_14 T_3 *
F_15 ( struct V_1 * V_9 , T_2 V_25 )
{
return V_25 ? V_9 -> V_19 + V_25 - V_9 -> V_5 : NULL ;
}
static struct V_14 T_3 *
F_16 ( struct V_1 * V_9 , int V_15 )
{
unsigned long V_21 ;
int V_26 ;
struct V_14 T_3 * V_23 = NULL ;
F_9 ( & V_9 -> V_11 , V_21 ) ;
V_26 = F_17 ( V_9 -> V_17 , V_9 -> V_15 , 0 ,
V_15 , 0 ) ;
if ( V_26 < V_9 -> V_15 ) {
F_18 ( V_9 -> V_17 , V_26 , V_15 ) ;
V_23 = V_9 -> V_19 + V_9 -> V_13 * V_26 ;
V_9 -> V_22 ++ ;
}
F_13 ( & V_9 -> V_11 , V_21 ) ;
return V_23 ;
}
static void F_19 ( struct V_1 * V_9 ,
struct V_14 T_3 * V_23 , int V_15 )
{
unsigned long V_21 , V_26 ;
V_26 = ( ( unsigned long ) V_23 - ( unsigned long ) V_9 -> V_19 ) /
V_9 -> V_13 ;
F_9 ( & V_9 -> V_11 , V_21 ) ;
F_20 ( V_9 -> V_17 , V_26 , V_15 ) ;
V_9 -> V_22 -- ;
F_13 ( & V_9 -> V_11 , V_21 ) ;
}
struct V_27 * F_21 ( struct V_28 * V_29 )
{
struct V_27 * V_30 ;
V_30 = F_2 ( sizeof( * V_30 ) , V_10 ) ;
if ( ! V_30 )
return NULL ;
V_30 -> V_31 = V_32 ;
V_30 -> V_29 = * V_29 ;
V_30 -> V_3 = V_29 -> V_3 ;
F_3 ( & V_30 -> V_11 ) ;
V_30 -> V_9 = F_1 ( V_30 -> V_3 ,
V_30 -> V_29 . V_33 ,
V_30 -> V_29 . V_34 ,
V_30 -> V_29 . V_35 ,
V_30 -> V_29 . V_36 ) ;
if ( ! V_30 -> V_9 ) {
F_7 ( V_30 ) ;
return NULL ;
}
if ( F_10 ( V_30 -> V_37 > V_38 ) )
V_30 -> V_37 = V_38 ;
return V_30 ;
}
int F_22 ( struct V_27 * V_30 )
{
unsigned long V_21 ;
int V_39 ;
F_9 ( & V_30 -> V_11 , V_21 ) ;
if ( V_30 -> V_31 != V_32 ) {
F_13 ( & V_30 -> V_11 , V_21 ) ;
return - V_40 ;
}
if ( V_30 -> V_29 . V_41 ) {
unsigned long V_42 = V_43 + V_44 / 10 ;
F_23 ( V_30 , V_45 , 1 ) ;
while ( F_24 ( V_43 , V_42 ) ) {
if ( F_25 ( V_30 , V_45 ) == 0 )
break;
}
F_10 ( ! F_24 ( V_43 , V_42 ) ) ;
}
for ( V_39 = 0 ; V_39 < V_30 -> V_37 ; V_39 ++ ) {
F_26 ( 0 , V_30 -> V_29 . V_46 + 4 * V_39 ) ;
F_26 ( 0 , V_30 -> V_29 . V_47 + 4 * V_39 ) ;
F_26 ( 0 , V_30 -> V_29 . V_48 + 4 * V_39 ) ;
F_26 ( 0 , V_30 -> V_29 . V_49 + 4 * V_39 ) ;
}
F_23 ( V_30 , V_50 , 0xffffffff ) ;
F_23 ( V_30 , V_51 , 0xffffffff ) ;
F_23 ( V_30 , V_52 , 1 ) ;
F_23 ( V_30 , V_53 , 1 ) ;
V_30 -> V_31 = V_54 ;
for ( V_39 = 0 ; V_39 < F_27 ( V_30 -> V_55 ) ; V_39 ++ ) {
if ( V_30 -> V_55 [ V_39 ] )
F_28 ( V_30 -> V_55 [ V_39 ] ) ;
}
F_13 ( & V_30 -> V_11 , V_21 ) ;
return 0 ;
}
int F_29 ( struct V_27 * V_30 )
{
unsigned long V_21 ;
int V_39 ;
F_9 ( & V_30 -> V_11 , V_21 ) ;
if ( V_30 -> V_31 != V_54 ) {
F_13 ( & V_30 -> V_11 , V_21 ) ;
return - V_56 ;
}
V_30 -> V_31 = V_57 ;
for ( V_39 = 0 ; V_39 < F_27 ( V_30 -> V_55 ) ; V_39 ++ ) {
if ( V_30 -> V_55 [ V_39 ] )
F_30 ( V_30 -> V_55 [ V_39 ] ) ;
}
F_23 ( V_30 , V_50 , 0xffffffff ) ;
F_23 ( V_30 , V_51 , 0xffffffff ) ;
F_23 ( V_30 , V_52 , 0 ) ;
F_23 ( V_30 , V_53 , 0 ) ;
V_30 -> V_31 = V_32 ;
F_13 ( & V_30 -> V_11 , V_21 ) ;
return 0 ;
}
int F_31 ( struct V_27 * V_30 )
{
struct V_2 * V_3 = V_30 -> V_3 ;
unsigned long V_21 ;
int V_39 ;
F_9 ( & V_30 -> V_11 , V_21 ) ;
F_32 ( V_3 , L_1 , V_58 [ V_30 -> V_31 ] ) ;
F_32 ( V_3 , L_2 ,
F_25 ( V_30 , V_59 ) ) ;
F_32 ( V_3 , L_3 ,
F_25 ( V_30 , V_52 ) ) ;
F_32 ( V_3 , L_4 ,
F_25 ( V_30 , V_60 ) ) ;
F_32 ( V_3 , L_5 ,
F_25 ( V_30 , V_61 ) ) ;
F_32 ( V_3 , L_6 ,
F_25 ( V_30 , V_53 ) ) ;
F_32 ( V_3 , L_7 ,
F_25 ( V_30 , V_45 ) ) ;
F_32 ( V_3 , L_8 ,
F_25 ( V_30 , V_62 ) ) ;
F_32 ( V_3 , L_9 ,
F_25 ( V_30 , V_63 ) ) ;
F_32 ( V_3 , L_10 ,
F_25 ( V_30 , V_64 ) ) ;
F_32 ( V_3 , L_11 ,
F_25 ( V_30 , V_65 ) ) ;
F_32 ( V_3 , L_12 ,
F_25 ( V_30 , V_51 ) ) ;
F_32 ( V_3 , L_13 ,
F_25 ( V_30 , V_66 ) ) ;
F_32 ( V_3 , L_14 ,
F_25 ( V_30 , V_67 ) ) ;
F_32 ( V_3 , L_15 ,
F_25 ( V_30 , V_68 ) ) ;
F_32 ( V_3 , L_16 ,
F_25 ( V_30 , V_69 ) ) ;
F_32 ( V_3 , L_17 ,
F_25 ( V_30 , V_70 ) ) ;
F_32 ( V_3 , L_18 ,
F_25 ( V_30 , V_50 ) ) ;
F_32 ( V_3 , L_19 ,
F_25 ( V_30 , V_71 ) ) ;
F_32 ( V_3 , L_20 ,
F_25 ( V_30 , V_72 ) ) ;
F_32 ( V_3 , L_21 ,
F_25 ( V_30 , V_73 ) ) ;
F_32 ( V_3 , L_22 ,
F_25 ( V_30 , V_74 ) ) ;
if ( ! V_30 -> V_29 . V_75 ) {
F_32 ( V_3 , L_23 ,
F_25 ( V_30 , V_76 ) ) ;
F_32 ( V_3 , L_24 ,
F_25 ( V_30 , V_77 ) ) ;
F_32 ( V_3 , L_25 ,
F_25 ( V_30 , V_78 ) ) ;
}
for ( V_39 = 0 ; V_39 < F_27 ( V_30 -> V_55 ) ; V_39 ++ )
if ( V_30 -> V_55 [ V_39 ] )
F_33 ( V_30 -> V_55 [ V_39 ] ) ;
F_13 ( & V_30 -> V_11 , V_21 ) ;
return 0 ;
}
int F_34 ( struct V_27 * V_30 )
{
unsigned long V_21 ;
int V_79 = 0 , V_39 ;
if ( ! V_30 )
return - V_56 ;
F_9 ( & V_30 -> V_11 , V_21 ) ;
if ( V_30 -> V_31 != V_32 )
F_29 ( V_30 ) ;
for ( V_39 = 0 ; V_39 < F_27 ( V_30 -> V_55 ) ; V_39 ++ ) {
if ( V_30 -> V_55 [ V_39 ] )
F_35 ( V_30 -> V_55 [ V_39 ] ) ;
}
F_8 ( V_30 -> V_9 ) ;
F_13 ( & V_30 -> V_11 , V_21 ) ;
F_7 ( V_30 ) ;
return V_79 ;
}
int F_36 ( struct V_27 * V_30 , bool V_80 )
{
unsigned long V_21 ;
int V_39 , V_81 ;
F_9 ( & V_30 -> V_11 , V_21 ) ;
if ( V_30 -> V_31 != V_54 ) {
F_13 ( & V_30 -> V_11 , V_21 ) ;
return - V_56 ;
}
V_81 = V_80 ? V_73 : V_74 ;
F_23 ( V_30 , V_81 , V_82 ) ;
for ( V_39 = 0 ; V_39 < F_27 ( V_30 -> V_55 ) ; V_39 ++ ) {
if ( V_30 -> V_55 [ V_39 ] )
F_37 ( V_30 -> V_55 [ V_39 ] , V_80 ) ;
}
F_13 ( & V_30 -> V_11 , V_21 ) ;
return 0 ;
}
void F_38 ( struct V_27 * V_30 )
{
F_23 ( V_30 , V_67 , 0 ) ;
}
struct V_83 * F_39 ( struct V_27 * V_30 , int V_84 ,
T_4 V_85 )
{
struct V_83 * V_86 ;
int V_79 , V_87 = ( V_84 % V_38 ) * 4 ;
unsigned long V_21 ;
if ( F_40 ( V_84 ) >= V_30 -> V_37 )
return NULL ;
V_79 = - V_88 ;
V_86 = F_2 ( sizeof( * V_86 ) , V_10 ) ;
if ( ! V_86 )
goto V_89;
F_9 ( & V_30 -> V_11 , V_21 ) ;
V_79 = - V_40 ;
if ( V_30 -> V_55 [ V_84 ] )
goto V_90;
V_86 -> V_30 = V_30 ;
V_86 -> V_31 = V_32 ;
V_86 -> V_84 = V_84 ;
V_86 -> V_85 = V_85 ;
if ( F_41 ( V_86 ) ) {
V_86 -> V_91 = V_30 -> V_29 . V_47 + V_87 ;
V_86 -> V_92 = V_30 -> V_29 . V_49 + V_87 ;
V_86 -> V_93 = V_30 -> V_29 . V_93 + V_87 ;
V_86 -> V_94 = V_70 ;
V_86 -> V_95 = V_50 ;
V_86 -> V_96 = V_62 ;
V_86 -> V_97 = V_98 ;
} else {
V_86 -> V_91 = V_30 -> V_29 . V_46 + V_87 ;
V_86 -> V_92 = V_30 -> V_29 . V_48 + V_87 ;
V_86 -> V_94 = V_65 ;
V_86 -> V_95 = V_51 ;
V_86 -> V_96 = V_60 ;
V_86 -> V_97 = V_99 ;
}
V_86 -> V_100 = F_42 ( F_43 ( V_86 ) ) ;
F_3 ( & V_86 -> V_11 ) ;
V_30 -> V_55 [ V_84 ] = V_86 ;
F_13 ( & V_30 -> V_11 , V_21 ) ;
return V_86 ;
V_90:
F_13 ( & V_30 -> V_11 , V_21 ) ;
F_7 ( V_86 ) ;
V_89:
return F_44 ( V_79 ) ;
}
int F_35 ( struct V_83 * V_86 )
{
struct V_27 * V_30 = V_86 -> V_30 ;
unsigned long V_21 ;
if ( ! V_86 )
return - V_56 ;
F_9 ( & V_30 -> V_11 , V_21 ) ;
if ( V_86 -> V_31 != V_32 )
F_30 ( V_86 ) ;
V_30 -> V_55 [ V_86 -> V_84 ] = NULL ;
F_13 ( & V_30 -> V_11 , V_21 ) ;
F_7 ( V_86 ) ;
return 0 ;
}
int F_45 ( struct V_83 * V_86 ,
struct V_101 * V_102 )
{
unsigned long V_21 ;
if ( ! V_86 )
return - V_56 ;
F_9 ( & V_86 -> V_11 , V_21 ) ;
memcpy ( V_102 , & V_86 -> V_102 , sizeof( * V_102 ) ) ;
F_13 ( & V_86 -> V_11 , V_21 ) ;
return 0 ;
}
int F_33 ( struct V_83 * V_86 )
{
unsigned long V_21 ;
struct V_2 * V_3 = V_86 -> V_30 -> V_3 ;
F_9 ( & V_86 -> V_11 , V_21 ) ;
F_32 ( V_3 , L_26 ,
V_86 -> V_84 , F_41 ( V_86 ) ? L_27 : L_28 ,
F_43 ( V_86 ) , V_58 [ V_86 -> V_31 ] ) ;
F_32 ( V_3 , L_29 , F_46 ( V_86 , V_91 ) ) ;
F_32 ( V_3 , L_30 , F_46 ( V_86 , V_92 ) ) ;
if ( V_86 -> V_93 ) {
F_32 ( V_3 , L_31 ,
F_46 ( V_86 , V_93 ) ) ;
}
F_32 ( V_3 , L_32 ,
V_86 -> V_102 . V_103 ) ;
F_32 ( V_3 , L_33 ,
V_86 -> V_102 . V_104 ) ;
F_32 ( V_3 , L_34 ,
V_86 -> V_102 . V_105 ) ;
F_32 ( V_3 , L_35 ,
V_86 -> V_102 . V_106 ) ;
F_32 ( V_3 , L_36 ,
V_86 -> V_102 . V_107 ) ;
F_32 ( V_3 , L_37 ,
V_86 -> V_102 . V_108 ) ;
F_32 ( V_3 , L_38 ,
V_86 -> V_102 . V_109 ) ;
F_32 ( V_3 , L_39 ,
V_86 -> V_102 . V_110 ) ;
F_32 ( V_3 , L_40 ,
V_86 -> V_102 . V_111 ) ;
F_32 ( V_3 , L_41 ,
V_86 -> V_102 . V_112 ) ;
F_32 ( V_3 , L_42 ,
V_86 -> V_102 . V_113 ) ;
F_32 ( V_3 , L_43 ,
V_86 -> V_102 . V_114 ) ;
F_32 ( V_3 , L_44 ,
V_86 -> V_102 . V_115 ) ;
F_13 ( & V_86 -> V_11 , V_21 ) ;
return 0 ;
}
static void F_47 ( struct V_83 * V_86 ,
struct V_14 T_3 * V_23 )
{
struct V_27 * V_30 = V_86 -> V_30 ;
struct V_14 T_3 * V_116 = V_86 -> V_117 ;
struct V_1 * V_9 = V_30 -> V_9 ;
T_2 V_118 ;
T_1 V_119 ;
V_118 = F_14 ( V_9 , V_23 ) ;
if ( ! V_86 -> V_120 ) {
V_86 -> V_102 . V_103 ++ ;
V_86 -> V_120 = V_23 ;
V_86 -> V_117 = V_23 ;
if ( V_86 -> V_31 == V_54 )
F_48 ( V_86 , V_91 , V_118 ) ;
return;
}
F_49 ( V_116 , V_121 , V_118 ) ;
V_86 -> V_117 = V_23 ;
V_86 -> V_102 . V_104 ++ ;
V_119 = F_50 ( V_116 , V_122 ) ;
if ( ( ( V_119 & ( V_123 | V_124 ) ) == V_123 ) &&
( V_86 -> V_31 == V_54 ) ) {
F_49 ( V_116 , V_122 , V_119 & ~ V_123 ) ;
F_48 ( V_86 , V_91 , V_118 ) ;
V_86 -> V_102 . V_106 ++ ;
}
}
int F_51 ( struct V_83 * V_86 , void * V_125 , void * V_126 ,
int V_127 , T_5 V_128 )
{
struct V_27 * V_30 = V_86 -> V_30 ;
struct V_14 T_3 * V_23 ;
T_2 V_129 ;
unsigned long V_21 ;
T_1 V_119 ;
int V_79 = 0 ;
F_9 ( & V_86 -> V_11 , V_21 ) ;
if ( V_86 -> V_31 == V_57 ) {
V_79 = - V_56 ;
goto V_130;
}
V_23 = F_16 ( V_30 -> V_9 , 1 ) ;
if ( ! V_23 ) {
V_86 -> V_102 . V_107 ++ ;
V_79 = - V_88 ;
goto V_130;
}
if ( V_127 < V_30 -> V_29 . V_131 ) {
V_127 = V_30 -> V_29 . V_131 ;
V_86 -> V_102 . V_110 ++ ;
}
V_129 = F_52 ( V_30 -> V_3 , V_126 , V_127 , V_86 -> V_97 ) ;
V_119 = V_124 | V_132 | V_133 ;
F_49 ( V_23 , V_121 , 0 ) ;
F_49 ( V_23 , V_134 , V_129 ) ;
F_49 ( V_23 , V_135 , V_127 ) ;
F_49 ( V_23 , V_122 , V_119 | V_127 ) ;
F_49 ( V_23 , V_136 , V_125 ) ;
F_49 ( V_23 , V_137 , V_129 ) ;
F_49 ( V_23 , V_138 , V_127 ) ;
F_47 ( V_86 , V_23 ) ;
if ( V_86 -> V_31 == V_54 && V_86 -> V_93 )
F_48 ( V_86 , V_93 , 1 ) ;
V_86 -> V_139 ++ ;
V_130:
F_13 ( & V_86 -> V_11 , V_21 ) ;
return V_79 ;
}
static void F_53 ( struct V_83 * V_86 ,
struct V_14 T_3 * V_23 ,
int V_140 , int V_141 )
{
struct V_27 * V_30 = V_86 -> V_30 ;
struct V_1 * V_9 = V_30 -> V_9 ;
T_2 V_142 ;
int V_143 ;
void * V_125 ;
V_125 = ( void * ) F_50 ( V_23 , V_136 ) ;
V_142 = F_50 ( V_23 , V_137 ) ;
V_143 = F_50 ( V_23 , V_138 ) ;
F_54 ( V_30 -> V_3 , V_142 , V_143 , V_86 -> V_97 ) ;
F_19 ( V_9 , V_23 , 1 ) ;
(* V_86 -> V_85 )( V_125 , V_140 , V_141 ) ;
}
static int F_55 ( struct V_83 * V_86 )
{
struct V_27 * V_30 = V_86 -> V_30 ;
struct V_14 T_3 * V_23 ;
int V_141 , V_140 ;
struct V_1 * V_9 = V_30 -> V_9 ;
T_2 V_118 ;
unsigned long V_21 ;
F_9 ( & V_86 -> V_11 , V_21 ) ;
V_23 = V_86 -> V_120 ;
if ( ! V_23 ) {
V_86 -> V_102 . V_111 ++ ;
V_141 = - V_144 ;
goto V_130;
}
V_118 = F_14 ( V_9 , V_23 ) ;
V_141 = F_56 ( & V_23 -> V_122 ) ;
V_140 = V_141 & 0x7ff ;
if ( V_141 & V_124 ) {
V_86 -> V_102 . V_112 ++ ;
V_141 = - V_40 ;
goto V_130;
}
V_141 = V_141 & ( V_123 | V_145 ) ;
V_86 -> V_120 = F_15 ( V_9 , F_50 ( V_23 , V_121 ) ) ;
F_48 ( V_86 , V_92 , V_118 ) ;
V_86 -> V_139 -- ;
V_86 -> V_102 . V_113 ++ ;
if ( V_141 & V_123 ) {
V_86 -> V_102 . V_114 ++ ;
F_48 ( V_86 , V_91 , F_14 ( V_9 , V_86 -> V_120 ) ) ;
}
F_13 ( & V_86 -> V_11 , V_21 ) ;
F_53 ( V_86 , V_23 , V_140 , V_141 ) ;
return V_141 ;
V_130:
F_13 ( & V_86 -> V_11 , V_21 ) ;
return V_141 ;
}
int F_57 ( struct V_83 * V_86 , int V_146 )
{
int V_147 = 0 , V_79 = 0 ;
if ( V_86 -> V_31 != V_54 )
return - V_56 ;
while ( V_147 < V_146 ) {
V_79 = F_55 ( V_86 ) ;
if ( V_79 < 0 )
break;
V_147 ++ ;
}
return V_147 ;
}
int F_28 ( struct V_83 * V_86 )
{
struct V_27 * V_30 = V_86 -> V_30 ;
struct V_1 * V_9 = V_30 -> V_9 ;
unsigned long V_21 ;
F_9 ( & V_86 -> V_11 , V_21 ) ;
if ( V_86 -> V_31 != V_32 ) {
F_13 ( & V_86 -> V_11 , V_21 ) ;
return - V_40 ;
}
if ( V_30 -> V_31 != V_54 ) {
F_13 ( & V_86 -> V_11 , V_21 ) ;
return - V_56 ;
}
F_23 ( V_30 , V_86 -> V_94 , V_86 -> V_100 ) ;
V_86 -> V_31 = V_54 ;
if ( V_86 -> V_120 ) {
F_48 ( V_86 , V_91 , F_14 ( V_9 , V_86 -> V_120 ) ) ;
if ( V_86 -> V_93 )
F_48 ( V_86 , V_93 , V_86 -> V_139 ) ;
}
F_13 ( & V_86 -> V_11 , V_21 ) ;
return 0 ;
}
int F_30 ( struct V_83 * V_86 )
{
struct V_27 * V_30 = V_86 -> V_30 ;
struct V_1 * V_9 = V_30 -> V_9 ;
unsigned long V_21 ;
int V_79 ;
unsigned long V_42 ;
F_9 ( & V_86 -> V_11 , V_21 ) ;
if ( V_86 -> V_31 != V_54 ) {
F_13 ( & V_86 -> V_11 , V_21 ) ;
return - V_56 ;
}
V_86 -> V_31 = V_57 ;
F_23 ( V_30 , V_86 -> V_95 , V_86 -> V_100 ) ;
F_23 ( V_30 , V_86 -> V_96 , F_43 ( V_86 ) ) ;
V_42 = V_43 + V_44 / 10 ;
while ( F_24 ( V_43 , V_42 ) ) {
T_1 V_92 = F_46 ( V_86 , V_92 ) ;
if ( ( V_92 & V_148 ) == V_148 )
break;
F_58 () ;
}
F_10 ( ! F_24 ( V_43 , V_42 ) ) ;
F_48 ( V_86 , V_92 , V_148 ) ;
F_13 ( & V_86 -> V_11 , V_21 ) ;
do {
V_79 = F_55 ( V_86 ) ;
if ( V_79 < 0 )
break;
} while ( ( V_79 & V_145 ) == 0 );
F_9 ( & V_86 -> V_11 , V_21 ) ;
while ( V_86 -> V_120 ) {
struct V_14 T_3 * V_23 = V_86 -> V_120 ;
T_2 V_149 ;
V_149 = F_50 ( V_23 , V_121 ) ;
V_86 -> V_120 = F_15 ( V_9 , V_149 ) ;
V_86 -> V_102 . V_115 ++ ;
F_13 ( & V_86 -> V_11 , V_21 ) ;
F_53 ( V_86 , V_23 , 0 , - V_150 ) ;
F_9 ( & V_86 -> V_11 , V_21 ) ;
}
V_86 -> V_31 = V_32 ;
F_13 ( & V_86 -> V_11 , V_21 ) ;
return 0 ;
}
int F_37 ( struct V_83 * V_86 , bool V_80 )
{
unsigned long V_21 ;
F_9 ( & V_86 -> V_11 , V_21 ) ;
if ( V_86 -> V_31 != V_54 ) {
F_13 ( & V_86 -> V_11 , V_21 ) ;
return - V_56 ;
}
F_23 ( V_86 -> V_30 , V_80 ? V_86 -> V_94 : V_86 -> V_95 ,
V_86 -> V_100 ) ;
F_13 ( & V_86 -> V_11 , V_21 ) ;
return 0 ;
}
int F_59 ( struct V_27 * V_30 , int V_151 )
{
unsigned long V_21 ;
struct V_152 * V_153 = & V_154 [ V_151 ] ;
int V_79 ;
F_9 ( & V_30 -> V_11 , V_21 ) ;
V_79 = - V_155 ;
if ( ! V_30 -> V_29 . V_75 )
goto V_130;
V_79 = - V_56 ;
if ( V_30 -> V_31 != V_54 )
goto V_130;
V_79 = - V_144 ;
if ( V_151 < 0 || V_151 >= F_27 ( V_154 ) )
goto V_130;
V_79 = - V_156 ;
if ( ( V_153 -> V_157 & V_158 ) != V_158 )
goto V_130;
V_79 = ( F_25 ( V_30 , V_153 -> V_81 ) >> V_153 -> V_159 ) & V_153 -> V_100 ;
V_130:
F_13 ( & V_30 -> V_11 , V_21 ) ;
return V_79 ;
}
int F_60 ( struct V_27 * V_30 , int V_151 , int V_160 )
{
unsigned long V_21 ;
struct V_152 * V_153 = & V_154 [ V_151 ] ;
int V_79 ;
T_1 V_161 ;
F_9 ( & V_30 -> V_11 , V_21 ) ;
V_79 = - V_155 ;
if ( ! V_30 -> V_29 . V_75 )
goto V_130;
V_79 = - V_56 ;
if ( V_30 -> V_31 != V_54 )
goto V_130;
V_79 = - V_144 ;
if ( V_151 < 0 || V_151 >= F_27 ( V_154 ) )
goto V_130;
V_79 = - V_156 ;
if ( ( V_153 -> V_157 & V_162 ) != V_162 )
goto V_130;
V_161 = F_25 ( V_30 , V_153 -> V_81 ) ;
V_161 &= ~ ( V_153 -> V_100 << V_153 -> V_159 ) ;
V_161 |= ( V_160 & V_153 -> V_100 ) << V_153 -> V_159 ;
F_23 ( V_30 , V_153 -> V_81 , V_161 ) ;
V_79 = 0 ;
V_130:
F_13 ( & V_30 -> V_11 , V_21 ) ;
return V_79 ;
}
