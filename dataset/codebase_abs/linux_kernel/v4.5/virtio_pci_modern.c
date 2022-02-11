static inline T_1 F_1 ( T_1 T_2 * V_1 )
{
return F_2 ( V_1 ) ;
}
static inline T_3 F_3 ( T_3 T_2 * V_1 )
{
return F_4 ( V_1 ) ;
}
static inline T_4 F_5 ( T_4 T_2 * V_1 )
{
return F_6 ( V_1 ) ;
}
static inline void F_7 ( T_1 V_2 , T_1 T_2 * V_1 )
{
F_8 ( V_2 , V_1 ) ;
}
static inline void F_9 ( T_3 V_2 , T_3 T_2 * V_1 )
{
F_10 ( V_2 , V_1 ) ;
}
static inline void F_11 ( T_4 V_2 , T_4 T_2 * V_1 )
{
F_12 ( V_2 , V_1 ) ;
}
static void F_13 ( T_5 V_3 ,
T_6 T_2 * V_4 , T_6 T_2 * V_5 )
{
F_11 ( ( T_4 ) V_3 , V_4 ) ;
F_11 ( V_3 >> 32 , V_5 ) ;
}
static void T_2 * F_14 ( struct V_6 * V_7 , int V_8 ,
T_7 V_9 ,
T_4 V_10 ,
T_4 V_11 , T_4 V_12 ,
T_7 * V_13 )
{
T_1 V_14 ;
T_4 V_15 , V_16 ;
void T_2 * V_17 ;
F_15 ( V_7 , V_8 + F_16 ( struct V_18 ,
V_14 ) ,
& V_14 ) ;
F_17 ( V_7 , V_8 + F_16 ( struct V_18 , V_15 ) ,
& V_15 ) ;
F_17 ( V_7 , V_8 + F_16 ( struct V_18 , V_16 ) ,
& V_16 ) ;
if ( V_16 <= V_11 ) {
F_18 ( & V_7 -> V_7 ,
L_1 ,
V_16 , V_11 ) ;
return NULL ;
}
if ( V_16 - V_11 < V_9 ) {
F_18 ( & V_7 -> V_7 ,
L_2 ,
V_16 , V_9 ) ;
return NULL ;
}
V_16 -= V_11 ;
if ( V_11 + V_15 < V_15 ) {
F_18 ( & V_7 -> V_7 ,
L_3 ,
V_11 , V_15 ) ;
return NULL ;
}
V_15 += V_11 ;
if ( V_15 & ( V_10 - 1 ) ) {
F_18 ( & V_7 -> V_7 ,
L_4 ,
V_15 , V_10 ) ;
return NULL ;
}
if ( V_16 > V_12 )
V_16 = V_12 ;
if ( V_13 )
* V_13 = V_16 ;
if ( V_9 + V_15 < V_9 ||
V_9 + V_15 > F_19 ( V_7 , V_14 ) ) {
F_18 ( & V_7 -> V_7 ,
L_5
L_6 ,
V_9 , V_15 ,
V_14 , ( unsigned long ) F_19 ( V_7 , V_14 ) ) ;
return NULL ;
}
V_17 = F_20 ( V_7 , V_14 , V_15 , V_16 ) ;
if ( ! V_17 )
F_18 ( & V_7 -> V_7 ,
L_7 ,
V_16 , V_15 , V_14 ) ;
return V_17 ;
}
static T_5 F_21 ( struct V_19 * V_20 )
{
struct V_21 * V_22 = F_22 ( V_20 ) ;
T_5 V_23 ;
F_11 ( 0 , & V_22 -> V_24 -> V_25 ) ;
V_23 = F_5 ( & V_22 -> V_24 -> V_26 ) ;
F_11 ( 1 , & V_22 -> V_24 -> V_25 ) ;
V_23 |= ( ( T_5 ) F_5 ( & V_22 -> V_24 -> V_26 ) << 32 ) ;
return V_23 ;
}
static int F_23 ( struct V_19 * V_20 )
{
struct V_21 * V_22 = F_22 ( V_20 ) ;
F_24 ( V_20 ) ;
if ( ! F_25 ( V_20 , V_27 ) ) {
F_18 ( & V_20 -> V_7 , L_8
L_9 ) ;
return - V_28 ;
}
F_11 ( 0 , & V_22 -> V_24 -> V_29 ) ;
F_11 ( ( T_4 ) V_20 -> V_23 , & V_22 -> V_24 -> V_30 ) ;
F_11 ( 1 , & V_22 -> V_24 -> V_29 ) ;
F_11 ( V_20 -> V_23 >> 32 , & V_22 -> V_24 -> V_30 ) ;
return 0 ;
}
static void F_26 ( struct V_19 * V_20 , unsigned V_15 ,
void * V_31 , unsigned V_13 )
{
struct V_21 * V_22 = F_22 ( V_20 ) ;
T_1 V_32 ;
T_8 V_33 ;
T_6 V_34 ;
F_27 ( V_15 + V_13 > V_22 -> V_35 ) ;
switch ( V_13 ) {
case 1 :
V_32 = F_2 ( V_22 -> V_36 + V_15 ) ;
memcpy ( V_31 , & V_32 , sizeof V_32 ) ;
break;
case 2 :
V_33 = F_28 ( F_4 ( V_22 -> V_36 + V_15 ) ) ;
memcpy ( V_31 , & V_33 , sizeof V_33 ) ;
break;
case 4 :
V_34 = F_29 ( F_6 ( V_22 -> V_36 + V_15 ) ) ;
memcpy ( V_31 , & V_34 , sizeof V_34 ) ;
break;
case 8 :
V_34 = F_29 ( F_6 ( V_22 -> V_36 + V_15 ) ) ;
memcpy ( V_31 , & V_34 , sizeof V_34 ) ;
V_34 = F_29 ( F_6 ( V_22 -> V_36 + V_15 + sizeof V_34 ) ) ;
memcpy ( V_31 + sizeof V_34 , & V_34 , sizeof V_34 ) ;
break;
default:
F_30 () ;
}
}
static void F_31 ( struct V_19 * V_20 , unsigned V_15 ,
const void * V_31 , unsigned V_13 )
{
struct V_21 * V_22 = F_22 ( V_20 ) ;
T_1 V_32 ;
T_8 V_33 ;
T_6 V_34 ;
F_27 ( V_15 + V_13 > V_22 -> V_35 ) ;
switch ( V_13 ) {
case 1 :
memcpy ( & V_32 , V_31 , sizeof V_32 ) ;
F_8 ( V_32 , V_22 -> V_36 + V_15 ) ;
break;
case 2 :
memcpy ( & V_33 , V_31 , sizeof V_33 ) ;
F_10 ( F_32 ( V_33 ) , V_22 -> V_36 + V_15 ) ;
break;
case 4 :
memcpy ( & V_34 , V_31 , sizeof V_34 ) ;
F_12 ( F_33 ( V_34 ) , V_22 -> V_36 + V_15 ) ;
break;
case 8 :
memcpy ( & V_34 , V_31 , sizeof V_34 ) ;
F_12 ( F_33 ( V_34 ) , V_22 -> V_36 + V_15 ) ;
memcpy ( & V_34 , V_31 + sizeof V_34 , sizeof V_34 ) ;
F_12 ( F_33 ( V_34 ) , V_22 -> V_36 + V_15 + sizeof V_34 ) ;
break;
default:
F_30 () ;
}
}
static T_4 F_34 ( struct V_19 * V_20 )
{
struct V_21 * V_22 = F_22 ( V_20 ) ;
return F_1 ( & V_22 -> V_24 -> V_37 ) ;
}
static T_1 F_35 ( struct V_19 * V_20 )
{
struct V_21 * V_22 = F_22 ( V_20 ) ;
return F_1 ( & V_22 -> V_24 -> V_38 ) ;
}
static void F_36 ( struct V_19 * V_20 , T_1 V_39 )
{
struct V_21 * V_22 = F_22 ( V_20 ) ;
F_27 ( V_39 == 0 ) ;
F_7 ( V_39 , & V_22 -> V_24 -> V_38 ) ;
}
static void F_37 ( struct V_19 * V_20 )
{
struct V_21 * V_22 = F_22 ( V_20 ) ;
F_7 ( 0 , & V_22 -> V_24 -> V_38 ) ;
F_1 ( & V_22 -> V_24 -> V_38 ) ;
F_38 ( V_20 ) ;
}
static T_3 F_39 ( struct V_21 * V_22 , T_3 V_40 )
{
F_9 ( V_40 , & V_22 -> V_24 -> V_41 ) ;
return F_3 ( & V_22 -> V_24 -> V_41 ) ;
}
static T_7 F_40 ( T_3 V_42 )
{
return F_41 ( F_42 ( V_42 , V_43 ) ) ;
}
static void * F_43 ( int * V_42 )
{
void * V_44 ;
for (; * V_42 && F_40 ( * V_42 ) > V_45 ; * V_42 /= 2 ) {
V_44 = F_44 ( F_40 ( * V_42 ) ,
V_46 | V_47 | V_48 ) ;
if ( V_44 )
return V_44 ;
}
if ( ! * V_42 )
return NULL ;
return F_44 ( F_40 ( * V_42 ) , V_46 | V_47 ) ;
}
static struct V_49 * F_45 ( struct V_21 * V_22 ,
struct V_50 * V_51 ,
unsigned V_52 ,
void (* F_46)( struct V_49 * V_53 ) ,
const char * V_54 ,
T_3 V_55 )
{
struct V_56 T_2 * V_57 = V_22 -> V_24 ;
struct V_49 * V_53 ;
T_3 V_42 , V_8 ;
int V_58 ;
if ( V_52 >= F_3 ( & V_57 -> V_59 ) )
return F_47 ( - V_60 ) ;
F_9 ( V_52 , & V_57 -> V_61 ) ;
V_42 = F_3 ( & V_57 -> V_62 ) ;
if ( ! V_42 || F_3 ( & V_57 -> V_63 ) )
return F_47 ( - V_60 ) ;
if ( V_42 & ( V_42 - 1 ) ) {
F_48 ( & V_22 -> V_6 -> V_7 , L_10 , V_42 ) ;
return F_47 ( - V_28 ) ;
}
V_8 = F_3 ( & V_57 -> V_64 ) ;
V_51 -> V_42 = V_42 ;
V_51 -> V_65 = V_55 ;
V_51 -> V_66 = F_43 ( & V_51 -> V_42 ) ;
if ( V_51 -> V_66 == NULL )
return F_47 ( - V_67 ) ;
V_53 = F_49 ( V_52 , V_51 -> V_42 ,
V_43 , & V_22 -> V_20 ,
true , V_51 -> V_66 , V_68 , F_46 , V_54 ) ;
if ( ! V_53 ) {
V_58 = - V_67 ;
goto V_69;
}
F_9 ( V_42 , & V_57 -> V_62 ) ;
F_13 ( F_50 ( V_51 -> V_66 ) ,
& V_57 -> V_70 , & V_57 -> V_71 ) ;
F_13 ( F_50 ( F_51 ( V_53 ) ) ,
& V_57 -> V_72 , & V_57 -> V_73 ) ;
F_13 ( F_50 ( F_52 ( V_53 ) ) ,
& V_57 -> V_74 , & V_57 -> V_75 ) ;
if ( V_22 -> V_76 ) {
if ( ( T_5 ) V_8 * V_22 -> V_77 + 2
> V_22 -> V_78 ) {
F_48 ( & V_22 -> V_6 -> V_7 ,
L_11
L_12 ,
V_8 , V_22 -> V_77 ,
V_52 , V_22 -> V_78 ) ;
V_58 = - V_28 ;
goto V_79;
}
V_53 -> V_80 = ( void V_81 * ) V_22 -> V_76 +
V_8 * V_22 -> V_77 ;
} else {
V_53 -> V_80 = ( void V_81 * ) F_14 ( V_22 -> V_6 ,
V_22 -> V_82 , 2 , 2 ,
V_8 * V_22 -> V_77 , 2 ,
NULL ) ;
}
if ( ! V_53 -> V_80 ) {
V_58 = - V_67 ;
goto V_79;
}
if ( V_55 != V_83 ) {
F_9 ( V_55 , & V_57 -> V_84 ) ;
V_55 = F_3 ( & V_57 -> V_84 ) ;
if ( V_55 == V_83 ) {
V_58 = - V_85 ;
goto V_86;
}
}
return V_53 ;
V_86:
if ( ! V_22 -> V_76 )
F_53 ( V_22 -> V_6 , ( void T_2 V_81 * ) V_53 -> V_80 ) ;
V_79:
F_54 ( V_53 ) ;
V_69:
F_55 ( V_51 -> V_66 , F_40 ( V_51 -> V_42 ) ) ;
return F_47 ( V_58 ) ;
}
static int F_56 ( struct V_19 * V_20 , unsigned V_87 ,
struct V_49 * V_88 [] ,
T_9 * V_89 [] ,
const char * const V_90 [] )
{
struct V_21 * V_22 = F_22 ( V_20 ) ;
struct V_49 * V_53 ;
int V_91 = F_57 ( V_20 , V_87 , V_88 , V_89 , V_90 ) ;
if ( V_91 )
return V_91 ;
F_58 (vq, &vdev->vqs, list) {
F_9 ( V_53 -> V_52 , & V_22 -> V_24 -> V_61 ) ;
F_9 ( 1 , & V_22 -> V_24 -> V_63 ) ;
}
return 0 ;
}
static void F_59 ( struct V_50 * V_51 )
{
struct V_49 * V_53 = V_51 -> V_53 ;
struct V_21 * V_22 = F_22 ( V_53 -> V_20 ) ;
F_9 ( V_53 -> V_52 , & V_22 -> V_24 -> V_61 ) ;
if ( V_22 -> V_92 ) {
F_9 ( V_83 ,
& V_22 -> V_24 -> V_84 ) ;
F_3 ( & V_22 -> V_24 -> V_84 ) ;
}
if ( ! V_22 -> V_76 )
F_53 ( V_22 -> V_6 , ( void V_81 T_2 * ) V_53 -> V_80 ) ;
F_54 ( V_53 ) ;
F_55 ( V_51 -> V_66 , F_40 ( V_51 -> V_42 ) ) ;
}
static inline int F_60 ( struct V_6 * V_7 , T_1 V_93 ,
T_4 V_94 , int * V_95 )
{
int V_96 ;
for ( V_96 = F_61 ( V_7 , V_97 ) ;
V_96 > 0 ;
V_96 = F_62 ( V_7 , V_96 , V_97 ) ) {
T_1 type , V_14 ;
F_15 ( V_7 , V_96 + F_16 ( struct V_18 ,
V_93 ) ,
& type ) ;
F_15 ( V_7 , V_96 + F_16 ( struct V_18 ,
V_14 ) ,
& V_14 ) ;
if ( V_14 > 0x5 )
continue;
if ( type == V_93 ) {
if ( F_19 ( V_7 , V_14 ) &&
F_63 ( V_7 , V_14 ) & V_94 ) {
* V_95 |= ( 1 << V_14 ) ;
return V_96 ;
}
}
}
return 0 ;
}
static inline void F_64 ( void )
{
F_65 ( V_98 !=
F_16 ( struct V_18 , V_99 ) ) ;
F_65 ( V_100 !=
F_16 ( struct V_18 , V_101 ) ) ;
F_65 ( V_102 !=
F_16 ( struct V_18 , V_103 ) ) ;
F_65 ( V_104 !=
F_16 ( struct V_18 , V_93 ) ) ;
F_65 ( V_105 !=
F_16 ( struct V_18 , V_14 ) ) ;
F_65 ( V_106 !=
F_16 ( struct V_18 , V_15 ) ) ;
F_65 ( V_107 !=
F_16 ( struct V_18 , V_16 ) ) ;
F_65 ( V_108 !=
F_16 ( struct V_109 ,
V_110 ) ) ;
F_65 ( V_111 !=
F_16 ( struct V_56 ,
V_25 ) ) ;
F_65 ( V_112 !=
F_16 ( struct V_56 , V_26 ) ) ;
F_65 ( V_113 !=
F_16 ( struct V_56 ,
V_29 ) ) ;
F_65 ( V_114 !=
F_16 ( struct V_56 , V_30 ) ) ;
F_65 ( V_115 !=
F_16 ( struct V_56 , V_41 ) ) ;
F_65 ( V_116 !=
F_16 ( struct V_56 , V_59 ) ) ;
F_65 ( V_117 !=
F_16 ( struct V_56 , V_38 ) ) ;
F_65 ( V_118 !=
F_16 ( struct V_56 , V_37 ) ) ;
F_65 ( V_119 !=
F_16 ( struct V_56 , V_61 ) ) ;
F_65 ( V_120 !=
F_16 ( struct V_56 , V_62 ) ) ;
F_65 ( V_121 !=
F_16 ( struct V_56 , V_84 ) ) ;
F_65 ( V_122 !=
F_16 ( struct V_56 , V_63 ) ) ;
F_65 ( V_123 !=
F_16 ( struct V_56 , V_64 ) ) ;
F_65 ( V_124 !=
F_16 ( struct V_56 , V_70 ) ) ;
F_65 ( V_125 !=
F_16 ( struct V_56 , V_71 ) ) ;
F_65 ( V_126 !=
F_16 ( struct V_56 , V_72 ) ) ;
F_65 ( V_127 !=
F_16 ( struct V_56 , V_73 ) ) ;
F_65 ( V_128 !=
F_16 ( struct V_56 , V_74 ) ) ;
F_65 ( V_129 !=
F_16 ( struct V_56 , V_75 ) ) ;
}
int F_66 ( struct V_21 * V_22 )
{
struct V_6 * V_6 = V_22 -> V_6 ;
int V_58 , V_24 , V_130 , V_131 , V_36 ;
T_4 V_132 ;
T_4 V_133 ;
F_64 () ;
if ( V_6 -> V_36 < 0x1000 || V_6 -> V_36 > 0x107f )
return - V_134 ;
if ( V_6 -> V_36 < 0x1040 ) {
V_22 -> V_20 . V_135 . V_36 = V_6 -> V_136 ;
} else {
V_22 -> V_20 . V_135 . V_36 = V_6 -> V_36 - 0x1040 ;
}
V_22 -> V_20 . V_135 . V_137 = V_6 -> V_138 ;
V_24 = F_60 ( V_6 , V_139 ,
V_140 | V_141 ,
& V_22 -> V_142 ) ;
if ( ! V_24 ) {
F_67 ( & V_6 -> V_7 ,
L_13 ) ;
return - V_134 ;
}
V_130 = F_60 ( V_6 , V_143 ,
V_140 | V_141 ,
& V_22 -> V_142 ) ;
V_131 = F_60 ( V_6 , V_144 ,
V_140 | V_141 ,
& V_22 -> V_142 ) ;
if ( ! V_130 || ! V_131 ) {
F_18 ( & V_6 -> V_7 ,
L_14 ,
V_24 , V_130 , V_131 ) ;
return - V_28 ;
}
V_36 = F_60 ( V_6 , V_145 ,
V_140 | V_141 ,
& V_22 -> V_142 ) ;
V_58 = F_68 ( V_6 , V_22 -> V_142 ,
L_15 ) ;
if ( V_58 )
return V_58 ;
V_58 = - V_28 ;
V_22 -> V_24 = F_14 ( V_6 , V_24 ,
sizeof( struct V_56 ) , 4 ,
0 , sizeof( struct V_56 ) ,
NULL ) ;
if ( ! V_22 -> V_24 )
goto V_146;
V_22 -> V_130 = F_14 ( V_6 , V_130 , sizeof( T_1 ) , 1 ,
0 , 1 ,
NULL ) ;
if ( ! V_22 -> V_130 )
goto V_147;
F_17 ( V_6 ,
V_131 + F_16 ( struct V_109 ,
V_110 ) ,
& V_22 -> V_77 ) ;
F_17 ( V_6 ,
V_131 + F_16 ( struct V_109 ,
V_148 . V_16 ) ,
& V_132 ) ;
F_17 ( V_6 ,
V_131 + F_16 ( struct V_109 ,
V_148 . V_15 ) ,
& V_133 ) ;
if ( ( T_5 ) V_132 + ( V_133 % V_45 ) <= V_45 ) {
V_22 -> V_76 = F_14 ( V_6 , V_131 , 2 , 2 ,
0 , V_132 ,
& V_22 -> V_78 ) ;
if ( ! V_22 -> V_76 )
goto V_79;
} else {
V_22 -> V_82 = V_131 ;
}
if ( V_36 ) {
V_22 -> V_36 = F_14 ( V_6 , V_36 , 0 , 4 ,
0 , V_45 ,
& V_22 -> V_35 ) ;
if ( ! V_22 -> V_36 )
goto V_149;
V_22 -> V_20 . V_150 = & V_151 ;
} else {
V_22 -> V_20 . V_150 = & V_152 ;
}
V_22 -> V_153 = F_39 ;
V_22 -> F_45 = F_45 ;
V_22 -> F_59 = F_59 ;
return 0 ;
V_149:
if ( V_22 -> V_76 )
F_53 ( V_6 , V_22 -> V_76 ) ;
V_79:
F_53 ( V_6 , V_22 -> V_130 ) ;
V_147:
F_53 ( V_6 , V_22 -> V_24 ) ;
V_146:
return V_58 ;
}
void F_69 ( struct V_21 * V_22 )
{
struct V_6 * V_6 = V_22 -> V_6 ;
if ( V_22 -> V_36 )
F_53 ( V_6 , V_22 -> V_36 ) ;
if ( V_22 -> V_76 )
F_53 ( V_6 , V_22 -> V_76 ) ;
F_53 ( V_6 , V_22 -> V_130 ) ;
F_53 ( V_6 , V_22 -> V_24 ) ;
F_70 ( V_6 , V_22 -> V_142 ) ;
}
